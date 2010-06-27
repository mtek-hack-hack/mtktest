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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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
 *****************************************************************************/

/*! \file mtr_ctrl.c
 *  This file contains the control logic for rendering/viewing a text.
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_mem.h"

/* SMA */
#include "samem.h"

/* SMTR */
#include "smtr.h"
#include "smtrcmn.h"
#include "smtrpar.h"
#include "smtrrend.h"
#include "smtrctrl.h"

/******************************************************************************
 * Constants
 *****************************************************************************/
/*!< Defines the maximum number of concurrent text boxes */
#define SMTR_MAX_INSTANCES 5

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Static variables
 *****************************************************************************/
static SmtrInstance *mtrTextBoxes[SMTR_MAX_INSTANCES];

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static SmtrInstance *createInstance(MsfStringHandle stringHandle,
    const SmtrCreateTextBoxProperties *prop);
                                   
static void deleteInstance(SmtrInstance **inst);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Initializes the SMTR component
 *****************************************************************************/
void smtrCtrlInit(void)
{
    memset(mtrTextBoxes, 0, sizeof(SmtrInstance*) * SMTR_MAX_INSTANCES);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMTR, 
        SMTRCTRL_33E096A4D9B33834667D9061EA49FEA1, "SMTR CTRL: initialized\n"));
}

/*!
 * \brief Terminates the SMTR component
 *****************************************************************************/
void smtrCtrlTerminate(void)
{
    /* Delete all instances */
    deleteInstance(NULL);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMTR, SMTRCTRL_6B94163C9F0D6A7B8C4849A0B7FBF142, "SMTR CTRL: terminated\n"));

}

/*!
 * \brief Creates a new text box instance.
 *
 * \param stringHandle The string handle of the string to show.
 * \param prop The user defined properties of the text box.
 * \return The new instance or NULL if no new instance could be created.
 *****************************************************************************/
static SmtrInstance *createInstance(MsfStringHandle stringHandle,
	const SmtrCreateTextBoxProperties *prop)
{
    int i;
    /* Find an empty slot. */
    for(i = 0; i < SMTR_MAX_INSTANCES; i++)
    {
        if (NULL == mtrTextBoxes[i])
        {
            mtrTextBoxes[i] = MSF_MEM_ALLOCTYPE(MSF_MODID_SMTR, SmtrInstance);
            memset(mtrTextBoxes[i], 0, sizeof(SmtrInstance));
            mtrTextBoxes[i]->instance = i;
            memcpy(&mtrTextBoxes[i]->boxSize, &prop->size, sizeof(MsfSize));
            mtrTextBoxes[i]->stringHandle = stringHandle;
            memcpy(&(mtrTextBoxes[i]->prop), prop, 
                sizeof(SmtrCreateTextBoxProperties));
            return mtrTextBoxes[i];
        }
    }
    return NULL;
}

/*!
 * \brief Deallocates a #SmtrInstance struct.
 * 
 * \param inst The instance to free. If inst is NULL then all instances will
 * be removed.
 *****************************************************************************/
static void deleteInstance(SmtrInstance **inst)
{
    int i;
    if (inst) 
    {
        if (*inst)
        {
            if ((*inst)->gadgetHandle > 0) 
            {
                (void)MSF_WIDGET_RELEASE((*inst)->gadgetHandle);
            }
            
            if ((*inst)->stringHandle > 0)
            {
                (void)MSF_WIDGET_RELEASE((*inst)->stringHandle);
            }
            
            smtrFreeParseResult(&((*inst)->parse));
            if ((*inst)->charBuffer) 
            {
                SMTR_FREE((*inst)->charBuffer);
            }
            SMTR_FREE(*inst);
            *inst = NULL;
        }
    }
    else
    {
        /* Remove all instances */
        for(i = 0; i < SMTR_MAX_INSTANCES; i++)
        {
            deleteInstance(&mtrTextBoxes[i]);
        }        
    }
}

/*!
 * \brief Create a text box
 * 
 * \param stringHandle Handle of the text string to display in the text box. 
 * \param prop Properties of the text box. See #MtrCreateTextBoxProperties.
 * \return SMTR_RESULT_OK on success, otherwise the proper error code.
 *****************************************************************************/
SmtrResult smtrCreateTextBox(MsfStringHandle stringHandle, 
    const SmtrCreateTextBoxProperties *prop, SmtrCreateRspData **rsp)
{
    SmtrInstance *inst;
    MSF_UINT32 flags;
    *rsp = NULL;

    /* We don't accept empty strings */
    if (MSF_WIDGET_STRING_GET_LENGTH(stringHandle, 0, MsfUtf8) <= 0) 
    {
        *rsp = NULL;
        return SMTR_RESULT_ERROR;
    }
    /* Create a new text box instance */
    if (NULL == (inst = createInstance(stringHandle, prop)))
    {
        return SMTR_RESULT_BUSY;
    }
    /* Save flags */
    flags = prop->flags;
    /* Only parse if user wants to */
    if (IS_SET(flags, SMTR_PROP_RENDER_LINKS) ||
        IS_SET(flags, SMTR_PROP_RETURN_LINKS)) 
    {
        if (smtrParse(inst) < 0) 
        {
            deleteInstance(&inst);
            return SMTR_RESULT_ERROR;
        }
    }
    /* Render screen */
    if (smtrRender(inst) < 0) 
    {
        deleteInstance(&inst);
        return SMTR_RESULT_ERROR;        
    }
    /* Create response data */
    *rsp = MSF_MEM_ALLOCTYPE(MSF_MODID_SMTR, SmtrCreateRspData);
    memset(*rsp, 0, sizeof(SmtrCreateRspData));
    (*rsp)->instance = inst->instance;
    (*rsp)->gadgetHandle = inst->gadgetHandle;
    memcpy(&(*rsp)->gadgetSize, &inst->actualSize, sizeof(MsfSize));
    if (IS_SET(flags, SMTR_PROP_RETURN_LINKS))
    {
        if (!smtrCopyLinkList(inst->parse, &(*rsp)->links))
        {
            return SMTR_RESULT_ERROR;
        }
    }
    return SMTR_RESULT_OK;
}

/*!
 * \brief Deletes a text box.
 * 
 * \param callerFsm Caller FSM
 * \param returnSignal The signal to return when done.
 * \param instance The text box instance.
 *****************************************************************************/
SmtrResult smtrDeleteTextBox(int instance)
{
    if (instance < 0 || instance >= SMTR_MAX_INSTANCES) 
    {
        return SMTR_RESULT_ERROR;
    }
    deleteInstance(&mtrTextBoxes[instance]);
    return SMTR_RESULT_OK;
}

/*!
 * \brief Checks if any link is active (is selected) in current text box.
 *        The function will allocate data for the MtrLinkEntry link if
 *        the functions returns TRUE, otherwise no memory will be allocated
 *        and link will be set to NULL.
 * \param instance The text box instance.
 * \param link The returned link if active, otherwise NULL.
 * \return TRUE if a link is active, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smtrHasActiveLink(int instance, SmtrLinkEntry **link)
{
    SmtrInstance *inst = NULL;

    if (NULL == link) 
    {
        return FALSE;
    }
    *link = NULL;
    if (instance < 0 || instance >= SMTR_MAX_INSTANCES) 
    {
        return FALSE;
    }
    inst = mtrTextBoxes[instance];
    if (NULL != inst->selectedLink) 
    {
        *link = (SmtrLinkEntry*)SMTR_ALLOC(sizeof(SmtrLinkEntry));
        (*link)->link = smtrStrDup(inst->selectedLink->link);
        (*link)->scheme = inst->selectedLink->scheme;
        (*link)->next = NULL;
        return TRUE;
    }
    return FALSE;
}

/*!
 * \brief Deallocates a MtrCreateRspData struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void smtrFreeSmtrCreateRspData(SmtrCreateRspData **data)
{
    smtrFreeLinks(&((*data)->links));
    MSF_MEM_FREE(MSF_MODID_SMTR, *data);
    *data = NULL;
}

/*!
 * \brief Deallocates a #MtrLinkEntry struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void smtrFreeSmtrLinkEntry(SmtrLinkEntry **data)
{
    smtrFreeLinks(data);
}


/*!
 * \brief Redraws the text box according to current event.
 * 
 * \param instance The text box instance.
 * \param event The event that causes the text box to redraw.
 * \param lostFocus (out) This parameter will be set to TRUE if the text box
 *                  will loose focus due to the event.
*****************************************************************************/
SmtrResult smtrRedraw(int instance, MsfEventType event, MSF_BOOL *lostFocus)
{
    SmtrInstance *inst;
    if (instance < 0 || instance >= SMTR_MAX_INSTANCES) 
    {
        return SMTR_RESULT_ERROR;
    }
    if (NULL == (inst = mtrTextBoxes[instance]))
    {
        return SMTR_RESULT_ERROR;
    }
    inst->currentEvent = event;
    inst->redraw = TRUE;
    if (FALSE == smtrRender(inst))
    {
        return SMTR_RESULT_ERROR;
    }
    *lostFocus = inst->lostFocus;
    return SMTR_RESULT_OK;
}

