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

/*! \file mtr_par.c
 *  This file contains the control logic for rendering/viewing a text.
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_cmmn.h"
#include "msf_chrt.h"

#ifdef WIDGET_SLIDING_SMIL_VBAR
#include "msf_mem.h"
#endif

/* MTR */
#include "mtr.h"
#include "mtr_cmn.h"
#include "mtr_par.h"
#ifdef WIDGET_SLIDING_SMIL_VBAR
#include "App_usedetails.h"
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/
/*! Valid characters in phone nr */
#define IS_PHONE_NO_CHARACTER(c)   ((c == '+') || (c == '-') || (c == '0') || \
    (c == '1') || (c == '2') || (c == '3') || \
    (c == '4') || (c == '5') || (c == '6') || \
    (c == '7') || (c == '8') || (c == '9'))

/*! Valid characters in a host name */
#define IS_HOST_LETTER(x) ( \
    (x) >= '0' && (x) <= '9' || \
    (x) >= 'a' && (x) <= 'z' || \
    (x) >= 'A' && (x) <= 'Z' || \
    (x) == '.' || (x) == '-' || (x) == '_')

/*! Valid characters in a email address */
#define IS_EMAIL_LETTER(x) (IS_HOST_LETTER(x) || (x) == '@' || (x) == '+')

#define MMS_PARSING_BUFFER_SIZE (16 * 1024)
/******************************************************************************
 * Data-structures
 *****************************************************************************/
typedef struct  
{
    MtrScheme scheme;
    const char *str;
    unsigned int size;
}MtrSchemesTable;

/******************************************************************************
 * Static variables
 *****************************************************************************/
static const MtrSchemesTable schemes[] = MTR_SUPPORTED_SCHEMES;
static int mtrBufferSize = 0;
/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementations
 *****************************************************************************/

#ifdef WIDGET_SLIDING_SMIL_VBAR

/* for applib*/
static void* mtrMemAllocFunc(kal_uint32 size)
{
    return (void*)MSF_MEM_ALLOC(MSF_MODID_MTR, size);
}

/* for applib*/
static void mtrMemFreeFunc(void *p)
{
    MSF_MEM_FREE(MSF_MODID_MTR, p);
    return;
}

static kal_bool mtrCheckStopFunc(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 no)
{
    if (addr)
    {
        mtrBufferSize += sizeof(applib_address_node_struct);
    }
    if (addr->data)
    {
        mtrBufferSize += strlen(addr->data);
    }
    if (addr->data2)
    {
        mtrBufferSize += strlen(addr->data2);
    }
    
    if (mtrBufferSize > MMS_PARSING_BUFFER_SIZE)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

/* Use applib to get link*/
static MSF_BOOL doParse(char *str, MtrParseResult **result)
{
    MtrScheme scheme = MTR_SCHEME_NONE;
    applib_address_node_struct *linkList = NULL;
    applib_address_node_struct *ptr = NULL;
    kal_bool stopped = KAL_FALSE;

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MTR_PAR_71AFBA75E3D99D677C3373B0ECF7FEDF, "MEA MMV Scroll: doParse\n"));
    
    if (NULL == str)
    {
        return FALSE;
    }

    mtrBufferSize = 0;
    linkList = applib_get_address_list_from_text_ext(
                   APPLIB_ADDR_TYPE_URL | APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER, 
                   mtrMemAllocFunc, 
                   mtrMemFreeFunc,
                   mtrCheckStopFunc,
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
            linkStr = msf_cmmn_strdup(MSF_MODID_MTR, ptr->data2);
        }
        else
        {
            linkStr = msf_cmmn_strdup(MSF_MODID_MTR, ptr->data);
        }
        
        switch (ptr->dataType)
        {
        case APPLIB_ADDR_TYPE_URL:
            scheme = MTR_SCHEME_HTTP;
            break;
        case APPLIB_ADDR_TYPE_EMAIL:
            scheme = MTR_SCHEME_MAIL;
            break;
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            scheme = MTR_SCHEME_PHONE;
            break;
        default:
            ASSERT(0);
        }
        ptr->pos = msf_cmmn_utf8_strnlen(str, ptr->pos);
        mtrInsertParseEntry(ptr->pos, linkStr, ptr->length, scheme, result);
        MSF_MEM_FREE(MSF_MODID_MTR, linkStr);
		ptr = ptr->next;
    }

    applib_free_address_list(&linkList, mtrMemFreeFunc);

    return TRUE;
}

#else /* WIDGET_SLIDING_SMIL_VBAR*/

/*!
 * \brief Checks if the str is a valid link.
 *
 * \param sch The table of available schemes.
 * \param str The string to match against the table
 * \param scheme (out) The type of scheme if the string was a link, otherwise
 *  FALSE.
 * \return TRUE if the string was a link, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL isLink(const MtrSchemesTable *sch, char *str, MtrScheme *scheme)
{
    int i;
    MSF_BOOL valid = TRUE;
    char *s = str;

    if (NULL == str) 
    {
        return FALSE;
    }
    for (i = 0; MTR_SCHEME_NONE != sch[i].scheme; i++)
    {
        *scheme = sch[i].scheme;
        /* Special handling for mail and phone number */
        if (MTR_SCHEME_MAIL == sch[i].scheme) 
        {
            /* Simple check for mail address */
            if (NULL != msf_cmmn_strnchr(str, '@', (int)strlen(str)))
            {
                valid = TRUE;
                /* Validate each character to be address safe */
                for (s = str; s && *s != '\0'; s++)
                {
                    if (!IS_EMAIL_LETTER(*s))
                    {
                        valid = FALSE;
                        break;
                    }
                }          
                if (valid) 
                {
                    return TRUE;
                }
            }
        }
        else if (MTR_SCHEME_PHONE == sch[i].scheme) 
        {
            if (strlen(str) > 2)
            {
                valid = TRUE;
                /* Validate each character to be phone number safe */
                for (s = str; s && *s != '\0'; s++)
                {
                    if (!IS_PHONE_NO_CHARACTER(*s))
                    {
                        valid = FALSE;
                        break;
                    }
                }                
                if (valid) 
                {
                    return TRUE;
                }
            }
        }
        /* Not special scheme, just string compare */
        else if (0 == msf_cmmn_strncmp_nc(sch[i].str, str, 
            (int)sch[i].size))
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*!
 * \brief The actual parser.
 *
 * \param str The string to find links in.
 * \param result (out) The parse result.
 * \return TRUE on successful parse, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL doParse(char *str, MtrParseResult **result)
{
    char *oldPos;
    char *endPos;
    char tmpChar;
    int utf8Len, utf8Pos;
    MtrScheme scheme;

    if (NULL == str)
    {
        return FALSE;
    }
    utf8Pos = 0;
    /* Explode */
    while(str[0] != '\0')
    {
        oldPos = str;
        /* Skip white-space */
        while (('\0' != *str) && (ct_iswhitespace (*str) || ct_isblank(*str)))
        {
            str++;
            utf8Pos++;
        }
        endPos = str;
        /* Find the end of the block */
        while (('\0' != *endPos) && (!ct_iswhitespace(*endPos) && 
            !ct_isblank(*endPos)))
        {
            endPos++;
        }
        tmpChar = *endPos;
        *endPos = '\0';
        utf8Len = msf_cmmn_utf8_strlen(str);
        /* Check for a valid link */
        if (isLink(schemes, str, &scheme)) 
        {
            /* One link found, insert the new item */
            mtrInsertParseEntry(utf8Pos, str, utf8Len, scheme, result);
        }
        utf8Pos += utf8Len;
        /* Restore the white-space */
        *endPos = tmpChar;
        /* Increase pointer in order to check the next word */
        str = endPos;
        /* Check if the pointer has been increased in order to prevent an 
           infinite loop*/
        str = (oldPos == str) ? endPos + 1: endPos;
    }
    return TRUE;
}

#endif /* WIDGET_SLIDING_SMIL_VBAR*/

/*!
 * \brief Main function for parsing text data
 *
 * \param inst Current instance.
 * \return TRUE on success, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL mtrParse(MtrInstance *inst)
{
    char *str;
    /* Get character buffer from string handle */
    str = mtrGetStringBufferFromHandle(inst->stringHandle);
    inst->charBuffer = str;
    /* Parse the text */
    return doParse(str, &(inst->parse));
}






















