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
 ******************************************************************************
 *
 * File:            $Workfile:   salnk.c  $
 *  
 * Date:            $Date:   May 17 2005 03:06:16  $
 *
 * Revision:        $Revision:   1.6  $
 *
 * Description:     Handling of links. 
 *
 *****************************************************************************/

/*! \file salnk.c
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_mem.h"
#include "msf_core.h"
#include "msf_cmmn.h"
#include "msf_chrt.h"
#include "msf_url.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#include "bra_if.h"  /* for BRAif_createUI */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
#include "sls_def.h"

/* SMA */
#include "sma_cfg.h"
#include "samem.h"
#include "satypes.h"
#include "salnk.h"

/******************************************************************************
 * Types
 *****************************************************************************/
/*!\struct SmaCrossTriggItem
 */
typedef struct
{
    const char      *scheme;    /*!< The type of scheme to check for, e.g. 
                                     "http://" */
    unsigned int    size;       /*!< The length of the string not counting the 
                                     string termination */
}SmaCrossTriggItem;

/******************************************************************************
 * Constants
 *****************************************************************************/
#ifdef SMA_CONFIG_CROSS_TRIGGERING_SCHEMES
static const SmaCrossTriggItem crossTriggSchemes[] = 
    SMA_CONFIG_CROSS_TRIGGERING_SCHEMES;
#endif 

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MSF_BOOL smaInsertUrl(const char *url, SmaLinkItem **root);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Insert a URL into the list of URL's
 *
 * \param url The URL to insert. The URL can be de-allocated after this call.
 * \param root The a reference to the root of the list
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL smaInsertUrl(const char *url, SmaLinkItem **root)
{
    SmaLinkItem *item;
    /* Allocate data-structures */
    if (NULL == (item = SMA_ALLOC(sizeof(SmaLinkItem))))
    {
        return FALSE;
    }
    memset(item, 0, sizeof(SmaLinkItem));
    if (NULL == (item->url = SMA_ALLOC(strlen(url) + 1)))
    {
        SMA_FREE(item);
        return FALSE;
    }
    if (NULL != *root)
    {
        item->next = *root;
    }
    /* Copy the content */
    strcpy(item->url, url);
    *root = item;
    return TRUE;
}

/*!
 * \brief Creates a list of links from a string containing any text.
 *
 * \param str The string to find links in.
 * \return A list of links or NULL.
 *****************************************************************************/
SmaLinkItem *smaCreateUrlList(const char *str, MSF_UINT32 size)
{
    char *oldPos;
    char *endPos;
    char tmpChar;
    char *newStr;
    char *toFree;
    int i;
    SmaLinkItem *links = NULL;

    if (NULL == str)
    {
        return FALSE;
    }
    /* Allocate a buffer*/
    if (NULL == (newStr = SMA_ALLOC(size + sizeof(char))))
    {
        return NULL;
    }
    /* Clear buffer */
    memset(newStr, 0, size + sizeof(char));
    /* Copy the content of the str, note that the buffer is one byte larger 
       than the original, i.e., a termination is added at the end */
    memcpy(newStr, str, size);
    toFree = newStr;
    /* Explode */
    while(newStr[0] != '\0')
    {
        oldPos = newStr;
        /* Skip white-space */
        while (('\0' != *newStr) && (ct_iswhitespace (*newStr) || ct_isblank(*newStr)))
        {
            newStr++;
        }
        endPos = newStr;
        /* Find the end of the block */
        while(('\0' != *endPos) && (!ct_iswhitespace(*endPos) && 
            !ct_isblank(*endPos)))
        {
            endPos++;
        }
        tmpChar = *endPos;
        *endPos = '\0';
        /* Check for a valid link */
        for(i = 0; NULL != crossTriggSchemes[i].scheme; i++)
        {
            if (0 == msf_cmmn_strncmp_nc(crossTriggSchemes[i].scheme, newStr, 
                (int)crossTriggSchemes[i].size))
            {
                /* Check that the identified URL is a valid one */
                if (msf_url_is_valid(newStr))
                {
                    /* One URL found, insert the new item */
                    if (!smaInsertUrl(newStr, &links))
                    {
                        /* Failed to create the new entry, clean-up and 
                           return */
                        smaDeleteUrlList(&links);
                        SMA_FREE(toFree);
                        return FALSE;
                    }
                }
            }
        }
        /* Restore the white-space */
        *endPos = tmpChar;
        /* Increase pointer in order to check the next word */
        newStr = endPos;
        /* Check if the pointer has been increased in order to prevent an 
           infinite loop*/
        newStr = (oldPos == newStr) ? endPos + 1: endPos;
    }
    SMA_FREE(toFree);
    return links;
}

/*!
 * \brief Deletes a list of URL's.
 *
 * \param root A reference to the list of URL's.
 *****************************************************************************/
void smaDeleteUrlList(SmaLinkItem **root)
{
    SmaLinkItem *current;
    SmaLinkItem *tmp;
    /* Check that there are any items to delete */
    if ((NULL == root) || (NULL == *root))
    {
        return;
    }
    /* Delete all items */
    current = *root;
    while(NULL != current)
    {
        if (current->url)
        {
            SMA_FREE(current->url);
        }
        tmp = current;
        current = current->next;
        SMA_FREE(tmp);
    }
    *root = NULL;
}

/*!
 * \brief Starts the BRA with a specific URL.
 *
 * \param url The URL to open in the BRA.
 *****************************************************************************/
void smaStartBra(char *url)
{
#ifdef MSF_MODID_BRA
  #ifdef WAP_SUPPORT
    char *link = NULL;
    extern void meaPanic(int showDialog);
    
    link = strstr(url, ":\\\\");
    if (link == NULL)
    {
        link = url;
    }
    else
    {
        link += strlen(":\\\\");
    }
    BRAif_createUI(BRA_UI_GOTO_URL, link);
    meaPanic(FALSE);  /* MEA_TERMINATE: Tell MEA to terminate all its affiliated modules */
  #else
    msf_content_data_t  contentData;

    memset(&contentData, 0, sizeof(msf_content_data_t));
    contentData.contentUrl = url;
    contentData.contentDataType = MSF_CONTENT_DATA_NONE;
    MSF_MODULE_START(MSF_MODID_SMA, MSF_MODID_BRA, NULL, &contentData, NULL);
  #endif
#else
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
        SALNK_BC4F74D83BDE9AC286AF7667079A7191, "(%s) (%d) Failed to start the BRA with the URL: %s, because the BRA"
        "is not defined!\n", __FILE__, __LINE__, url));
#endif
}


