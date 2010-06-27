/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*!\file mapbh.c
 * \brief Phone book handler.
 */

/* MSF */
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_def.h"
#include "msf_cmmn.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_log.h"

/* MMS */
#include "mms_def.h"

/* MEA */
#include "mea_rc.h"
#include "mea_def.h"
#include "mea_env.h"
#include "mea_cfg.h"
#include "mea_int.h"
#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "mamr.h"
#include "mame.h"
#include "mapbh.h"

/*! \file mapbh.c
 *  \brief Phone book handling
 */

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Variables
 *****************************************************************************/
static MSF_BOOL isPbStarted;
static MeaPbhLookupItem *lookupItems;
static MSF_UINT16 nextFreeId;

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void pbhSignalHandler(MeaSignal *sig);
static void freeLookupList(MeaPbhLookupItem **items);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates the PBH FSM.
 *
 *****************************************************************************/
void meaPbhInit(void)
{
    isPbStarted = FALSE;
    lookupItems = NULL;
    nextFreeId  = 0;
    meaSignalRegisterDst(MEA_PBH_FSM, pbhSignalHandler);
}

/*!
 * \brief Terminates the CRR FSM.
 *
 *****************************************************************************/
void meaPbhTerminate(void)
{
    if ((isPbStarted) || (NULL != lookupItems))
    {
        /* Cancel ongoing phone-book operations */
        MEAa_pbCancel();
    }
    freeLookupList(&lookupItems);
    isPbStarted = FALSE;
    lookupItems = NULL;
    nextFreeId  = 0;
    meaSignalDeregister(MEA_PBH_FSM);
}

/*! \brief Launches the phone book.
 *
 * \param id An identity that is provided in the response.
 *****************************************************************************/
void meaPbhLaunchPb(MSF_UINT16 id)
{
    isPbStarted = TRUE;
    MEAa_pbLaunch(id);
}

/*! \brief De-allocates a list of "lookup" entries.
 *
 *****************************************************************************/
static void freeLookupList(MeaPbhLookupItem **items)
{
    MeaPbhLookupItem *current;

    while(NULL != *items)
    {
        current = *items;
        *items = (*items)->next;
        MEA_FREE(current);
    }
    *items = NULL;
}

/*! \brief Gets a phone book lookup entry. The returned entry is removed from 
 *         the list.
 *
 *****************************************************************************/
MeaPbhLookupItem *meaPbhGetLookupEntry(unsigned int id)
{
    MeaPbhLookupItem *prev;
    MeaPbhLookupItem *current;
    MeaPbhLookupItem *items = lookupItems;
    /* Id it the first item? */
    if (NULL == items)
    {
        return NULL;
    }
    /* Handle the first item */
    if (items->id == id)
    {
        current = items;
        lookupItems = items->next;
        return current;
    }
    /* Other items */
    prev = NULL;
    current = items;
    while(NULL != current)
    {
        if (current->id == id)
        {
            /*lint -e{613}*/
            prev->next = current->next;
            return current;
        }
        prev = current;
        current = current->next;
    }
    return NULL;
}

/*!
 * \brief The signal handler for the PBH FSM.
 *
 * \param sig The current signal.
 *****************************************************************************/
static void pbhSignalHandler(MeaSignal *sig)
{
    MeaPbhLookupItem *lItem;
    /* Check which signal that was received */
    switch(sig->type)
    {
    case MEA_SIG_PBH_LAUNCH_RSP:
        if (MEA_PB_LAUNCH_RESULT_OK == sig->u_param1)
        {
            (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ADD_RECEPIENTS, 
                sig->u_param2, sig->p_param);
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAPBH_C1A0C7C171E1833433A632DEAF68BB6E, "(%s) (%d) The result of the phone book launch operation was "
                "not successful!\n", __FILE__, __LINE__));
        }
        break;

    case MEA_SIG_PBH_LOOKUP_RSP:
        if (MEA_PB_LOOKUP_RESULT_OK == sig->u_param1)
        {
            if (NULL != (lItem = meaPbhGetLookupEntry(sig->u_param2)))
            {
                (void)MEA_SIGNAL_SENDTO_P(lItem->fsm, (int)lItem->signal, 
                    sig->p_param);
                /*lint -e{774} */
                MEA_FREE(lItem);
            }
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAPBH_C1A0C7C171E1833433A632DEAF68BB6E, "(%s) (%d) The result of the phone book launch operation was "
                "not successful!\n", __FILE__, __LINE__));
        }        
        break;

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAPBH_ED7C4586CF0ED55D6EA21F276942BF8C, "(%s) (%d) Unhandled signal in crrSignalHandler!\n", __FILE__, 
            __LINE__));
        break;
    }
    meaSignalDelete(sig);
}

/*! \brief De-allocates a list of phone book items
 *
 * \param items the list to de-allocate
 *****************************************************************************/
void meaPbhFreeList(MeaPbItem *items)
{
    MeaPbItem *current;
    while(NULL != items)
    {
        current = items;
        /* De-allocate data */
        MEA_FREE(current->name);
        MEA_FREE(current->addr);
        MEA_FREE(current);
        /* Next item */
        items = items->next;
    }
}

/*! \brief Copies a #MeaPbItem to a new #MeaAddrItem.
 *
 * \param orig The item to copy.
 * \return The new item if successful, otherwise NULL.
 *****************************************************************************/
MeaAddrItem *meaPbhCopyItem(const MeaPbItem *orig)
{
    MeaAddrItem *newItem;
    if ((NULL == orig) || (NULL == orig->addr))
    {
        return NULL;
    }
    /* Create new item */
    if (NULL == (newItem = (MEA_ALLOC_NE(sizeof(MeaPbItem)))))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAPBH_453A7E07224056FBF5DDD3C06438F690, "(%s) (%d) Failed to allocate pb item.\n", __FILE__, 
            __LINE__));
        return FALSE;
    }
    memset(newItem, 0, sizeof(MeaPbItem));

    /* Copy the data */
    if (NULL != orig->name)
    {
        /* Name */
        if (NULL == (newItem->name = MEA_ALLOC_NE(strlen(orig->name) + 1)))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAPBH_453A7E07224056FBF5DDD3C06438F690, "(%s) (%d) Failed to allocate pb item.\n", __FILE__, 
                __LINE__));
            return NULL;
        }
        strcpy(newItem->name, orig->name);
    }
    if (NULL != orig->addr)
    {
        /* Value */
        if (NULL == (newItem->address = MEA_ALLOC_NE(strlen(orig->addr) + 1)))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAPBH_D020A140076E3242BF5BBBD3CC1E706E, "(%s) (%d) Failed to allocate PB item.\n", __FILE__, 
                __LINE__));

            return NULL;
        }
        strcpy(newItem->address, orig->addr);
    }
    /* Type */
    switch(orig->type)
    {
    case MEA_PB_TYPE_EMAIL:
        newItem->addrType = MEA_ADDR_TYPE_EMAIL;
        break;
    case MEA_PB_TYPE_PLMN:
        newItem->addrType = MEA_ADDR_TYPE_PLMN;
        break;
    }
    return newItem;
}

/*!\brief Find the name of a contact.  (Obsolete: It's replaced by meaNameLookup() autumn)
 *
 * \param fsm The callback FSM.
 * \param signal The callback signal.
 * \param addr The address to lookup the name for
 * \param addrType The address type, see #MeaAddrType.
 *****************************************************************************/
void meaPbhLookupName(MeaStateMachine fsm, unsigned int signal, char *addr, 
    MeaAddrType addrType)
{
    MeaPbhLookupItem *item;
    MeaPbAddrType    pbType;

    if (NULL == (item = MEA_ALLOC_NE(sizeof(MeaPbhLookupItem))))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAPBH_592C04B0DFA82D1A6148D0033B55D36F, "(%s) (%d) Failed to perform a lookup operation, out of memory.\n",
            __FILE__, __LINE__));
        return;
    }
    memset(item, 0, sizeof(MeaPbhLookupItem));
    item->fsm       = fsm;
    item->signal    = signal;
    item->id        = nextFreeId;
    if (NULL != lookupItems)
    {
        item->next = lookupItems;
    }
    lookupItems = item;
    pbType = (MeaPbAddrType)0;
    switch (addrType)
    {
    case MEA_ADDR_TYPE_EMAIL:
        pbType = MEA_PB_TYPE_EMAIL;
        break;
    case MEA_ADDR_TYPE_PLMN:
        pbType = MEA_PB_TYPE_PLMN;
        break;
    case MEA_ADDR_TYPE_NONE:
        return ;
    }
    MEAa_pbLookupName(nextFreeId, (MSF_UINT8)pbType, addr);
    nextFreeId++;
}


