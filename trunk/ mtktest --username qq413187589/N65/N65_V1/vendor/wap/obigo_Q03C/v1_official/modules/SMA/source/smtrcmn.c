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

/*! \file mtr_cmn.c
 *  This file contains the control logic for rendering/viewing a text.
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_mem.h"
#include "msf_cmmn.h"

/* SMA */
#include "samem.h"
/* MTR */
#include "smtr.h"
#include "smtrcmn.h"

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Static variables
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Duplicate a string
 *
 * \param str The string to duplicate
 * \return The newly allocated string if successful, otherwise NULL.
 *****************************************************************************/
char *smtrStrDup(const char *str)
{
    return msf_cmmn_strdup(MSF_MODID_SMTR, str);
}

/*!
 * \brief Gets a character buffer from a string handle
 *
 * \param strHandle The string handle to get buffer from
 * \return The newly allocated string if successful, otherwise NULL.
 *****************************************************************************/
char *smtrGetStringBufferFromHandle(MsfStringHandle strHandle)
{
    char *tmpStr;
    int length;
    
    if (0 >= (length = MSF_WIDGET_STRING_GET_LENGTH(strHandle, TRUE, 
        MsfUtf8)))
    {
        return NULL;
    }
    /* Add space for NULL termination*/
    tmpStr = (char *)SMTR_ALLOC(sizeof(char) * 
        (unsigned)length);
    memset(tmpStr, 0, (unsigned int)length);
    /* Get string data */
    if (0 > MSF_WIDGET_STRING_GET_DATA(strHandle, tmpStr, MsfUtf8))
    {
        /*lint -e{774} */
        SMTR_FREE(tmpStr);
        tmpStr = NULL;
        return NULL;    
    }
    return tmpStr;
    
}

/*!
 * \brief Insert entry in double linked parse list
 *
 * \param charPos Current position in string
 *****************************************************************************/
void smtrInsertParseEntry(int charPos, const char *str, int utf8Len, 
	SmtrScheme scheme, SmtrParseResult **parse)
{
    SmtrParseResult *entry;
    entry = MSF_MEM_ALLOCTYPE(MSF_MODID_SMTR, SmtrParseResult);
    memset(entry, 0, sizeof(SmtrParseResult));
    entry->scheme = scheme;
    entry->link = smtrStrDup(str);
    entry->utf8Len = utf8Len;
    entry->index = charPos;
    entry->pos.x = entry->pos.y = 0;
    entry->next = *parse;
    entry->prev = NULL;
    if (NULL != *parse) 
    {
        (*parse)->prev = entry;        
    }
    *parse = entry;
}

/*!
 * \brief 
 *
 * \param data Data to free
 *****************************************************************************/
void smtrFreeLinks(SmtrLinkEntry **data)
{
    SmtrLinkEntry *p1;
    while (*data) 
    {
        if ((*data)->link) 
        {
            MSF_MEM_FREE(MSF_MODID_SMTR, (*data)->link);
            (*data)->link = NULL;
        }
        p1 = (*data);
        (*data) = (*data)->next;
        p1->next = NULL;
        MSF_MEM_FREE(MSF_MODID_SMTR, p1);
    }
    
}

/*!
 * \brief 
 *
 * \param inst Current instance
 * \return TRUE if succesful, otherwise FALSE.
 *****************************************************************************/
void smtrFreeParseResult(SmtrParseResult **data)
{
    SmtrParseResult *p1;
    while (*data) 
    {
        if ((*data)->link) 
        {
            SMTR_FREE((*data)->link);
            (*data)->link = NULL;
        }
        p1 = (*data);
        (*data) = (*data)->next;
        p1->next = NULL;
        SMTR_FREE(p1);
    }
    
}

/*!
 * \brief Allocates a new link.
 *
 * \param p The parse result
 * \param l (out) The new list
 * \return TRUE if succesful, otherwise FALSE.
 *****************************************************************************/
static void insertLink(const SmtrParseResult *p, SmtrLinkEntry **l)
{
    SmtrLinkEntry *link;
    link = MSF_MEM_ALLOCTYPE(MSF_MODID_SMTR, SmtrLinkEntry);
    memset(link, 0, sizeof(SmtrLinkEntry));
    link->link = smtrStrDup(p->link);
    link->scheme = p->scheme;
    link->next = *l;
    *l = link;
}

/*!
 * \brief Copies links from the parse result to a new list.
 *
 * \param parse The parse result
 * \param links (out) The new list
 * \return TRUE if succesful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smtrCopyLinkList(SmtrParseResult *parse, SmtrLinkEntry **links)
{
    SmtrParseResult *p;
    if (!parse || !links) 
    {
        return FALSE;
    }
    /* Since the list is backwards and we build a stack the new list
     * will be the right order */
    p = parse;
    /* Start copy */
    while (p) 
    {
        insertLink(p, links);
        p = p->next;
    }
    return TRUE;
}


