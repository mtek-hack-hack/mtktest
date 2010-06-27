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

/*! \file smtrpar.c
 *  This file contains the control logic for rendering/viewing a text.
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_cmmn.h"
#include "msf_chrt.h"
#include "msf_mem.h"  /* MSF_MEM_FREE */

/* SMTR */
#include "smtr.h"
#include "smtrcmn.h"
#include "smtrpar.h"
#ifdef WAP_SUPPORT
#include "kal_release.h"
#include "app_usedetails.h"
extern MSF_BOOL meaSmilEditorIsActive(void);
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/
#define MMS_PARSING_BUFFER_SIZE (16 * 1024)

/******************************************************************************
 * Data-structures
 *****************************************************************************/
typedef struct  
{
    SmtrScheme scheme;
    const char *str;
    unsigned int size;
}SmtrSchemesTable;

/******************************************************************************
 * Static variables
 *****************************************************************************/
static const SmtrSchemesTable schemes[] = SMTR_SUPPORTED_SCHEMES;
static int smtrBufferSize = 0;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementations
 *****************************************************************************/

#ifdef WAP_SUPPORT
static void *smtrMemAllocFunc(kal_uint32 size)
{
    return MSF_MEM_ALLOC(MSF_MODID_SMTR, size);
}

static void smtrMemFreeFunc(void *p)
{
    MSF_MEM_FREE(MSF_MODID_SMTR, p);
    return;
}

static kal_bool smtrCheckStopFunc(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 no)
{
    if (addr)
    {
        smtrBufferSize += sizeof(applib_address_node_struct);
    }
    if (addr->data)
    {
        smtrBufferSize += strlen(addr->data);
    }
    if (addr->data2)
    {
        smtrBufferSize += strlen(addr->data2);
    }
    
    if (smtrBufferSize > MMS_PARSING_BUFFER_SIZE)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
#endif

/*!
 * \brief The actual parser.
 *
 * \param str The string to find links in.
 * \param result (out) The parse result.
 * \return TRUE on successful parse, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL doParse(char *str, SmtrParseResult **result)
{
    SmtrScheme scheme = SMTR_SCHEME_NONE;
    applib_address_node_struct *linkList = NULL;
    applib_address_node_struct *ptr = NULL;
    kal_bool stopped = KAL_FALSE;

    if (NULL == str)
    {
        return FALSE;
    }

    smtrBufferSize = 0;
    linkList = applib_get_address_list_from_text_ext(
                   APPLIB_ADDR_TYPE_URL | APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER, 
                   smtrMemAllocFunc, 
                   smtrMemFreeFunc,
                   smtrCheckStopFunc,
                   APPLIB_INPUT_DATA_TYPE_UTF8,
                   str, 
                   strlen(str),
                   &stopped);

    ptr = linkList;
    while (ptr != NULL)
    {
        char *linkStr = NULL;
        if (ptr->data2 != NULL)
        {
            linkStr = msf_cmmn_strdup(MSF_MODID_SMTR, ptr->data2);
        }
        else
        {
            linkStr = msf_cmmn_strdup(MSF_MODID_SMTR, ptr->data);
        }
        
        switch (ptr->dataType)
        {
        case APPLIB_ADDR_TYPE_URL:
            scheme = SMTR_SCHEME_HTTP;
            break;
        case APPLIB_ADDR_TYPE_EMAIL:
            scheme = SMTR_SCHEME_MAIL;
            break;
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            scheme = SMTR_SCHEME_PHONE;
            break;
        default:
            ASSERT(0);
        }
        ptr->pos = msf_cmmn_utf8_strnlen(str, ptr->pos);
        smtrInsertParseEntry(ptr->pos, linkStr, ptr->length, scheme, result);
        MSF_MEM_FREE(MSF_MODID_SMTR, linkStr);
		ptr = ptr->next;
    }

    applib_free_address_list(&linkList, smtrMemFreeFunc);

    return TRUE;
}

/*!
 * \brief Main function for parsing text data
 *
 * \param inst Current instance.
 * \return TRUE on success, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smtrParse(SmtrInstance *inst)
{
    char *str;
    /* Get character buffer from string handle */
    str = smtrGetStringBufferFromHandle(inst->stringHandle);
    inst->charBuffer = str;
    /* Parse the text */
    return doParse(str, &(inst->parse));
}






















