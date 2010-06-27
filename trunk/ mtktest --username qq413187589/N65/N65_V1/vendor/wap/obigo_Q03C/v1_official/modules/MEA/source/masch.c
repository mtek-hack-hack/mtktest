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
 * Description:     Converts schemes to a #MeaPropItem data structure.
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
#include "mea_cfg.h"
#include "mea_def.h"
#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "maaddr.h"

/*! \file masch.c
 */

/******************************************************************************
 * Constants
 *****************************************************************************/

/* ! Scheme parsing constants */
#define MEA_SCHEME_MMS_TO           "mmsto:"    /*!< */
#define MEA_SCHEME_MAIL_TO          "mailto:"   /*!< The mailto: scheme 
                                                     identifier */
#define MEA_SCHEME_MMS              "mms:"      /*!< The mms: scheme identifier
                                                 */
#define MEA_SCHEME_TO_DELIMITER     '?'         /*!< "To" delimiter */
#define MEA_SCHEME_FIELD_DELIMITER  '&'         /*!< Field delimiter */
#define MEA_SCHEME_HEX              '%'         /*!< Hex identifier */
#define MEA_SCHEME_CC               "cc="       /*!< Cc identifier */
#define MEA_SCHEME_SUBJECT          "subject="  /*!< Subject identifier */

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Variables
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Extracts the subject and formats the string according to the scheme.
 *
 * \param dest This is where the NULL terminated subject string is written.
 * \param subject The string containing the subject
 * \param length The length of the subject
 *****************************************************************************/
static void setSubject(char **dest, const char *subject, unsigned int length)
{
    char *sub;
    char *tmpPtr;
    char *delim;
    char value;
    int i;

    /* Free previous subject */
    MEA_FREE(*dest);
    /* Copy the new subject */
    sub = MEA_ALLOC(length + sizeof(""));
    strncpy(sub, subject, length);
    sub[length] = '\0';
    /* Post processing: exchange '+' to a white space ' ' */
    i = 0;
    while('\0' != sub[i])
    {
        if (sub[i] == '+')
        {
            sub[i] = ' ';
        }
        i++;
    }
    /* Post process the subject and fix the %*/
    delim = sub;
    while(NULL != (delim = strchr(delim, MEA_SCHEME_HEX)))
    {
        /* Check that he format is %xx, where xx is a hex value */
        if (strlen(delim) >= 2 && msf_cmmn_hex2byte(&(delim[1]), 
            (unsigned char *)&value))
        {
            /* Set the value at the delimiters place */
            delim[0] = value;
            /* Copy the rest of the string 2 characters to the "left" */
            tmpPtr = &(delim[3]);
            while('\0' != *tmpPtr)
            {
                tmpPtr[-2] = tmpPtr[0];
                tmpPtr += sizeof(char);
            }
            tmpPtr[-2] = '\0';
        }
        /* Skip the delimiter */
        delim += sizeof(char);
    }
    *dest = sub;
}

/*! Sets the addres
 * 
 *****************************************************************************/
static MSF_BOOL setAddr(MeaAddrItem **item, const char *str)
{
    char *newValue;
    char *freeData;
    char *delim;
    char *tmpPtr;
    unsigned char value;
    int i;
    MSF_BOOL status = FALSE;

    freeData = newValue = MEA_ALLOC(strlen(str) + 1);
    strcpy(newValue, str);
    /* Post process the string */
    /* Post processing: exchange '+' to a white space ' ' */
    i = 0;
    while('\0' != newValue[i])
    {
        if (newValue[i] == '+')
        {
            newValue[i] = ' ';
        }
        i++;
    }
    /* Post process the subject and fix the %*/
    delim = newValue;
    while(NULL != (delim = strchr(delim, MEA_SCHEME_HEX)))
    {
        /* Check that he format is %xx, where xx is a hex value */
        if (strlen(delim) >= 2 && msf_cmmn_hex2byte(&(delim[1]), 
            (unsigned char *)&value))
        {
            /* Set the value at the delimiters place */
            delim[0] = (char)value;
            /* Copy the rest of the string 2 characters to the "left" */
            tmpPtr = &(delim[3]);
            while('\0' != *tmpPtr)
            {
                tmpPtr[-2] = tmpPtr[0];
                tmpPtr += sizeof(char);
            }
            tmpPtr[-2] = '\0';
        }
        /* Skip the delimiter */
        delim += sizeof(char);
    }
    /* Trim */
    /* Trim left */
    while(' ' == *newValue)
    {
        newValue = &newValue[1];
    }
    /* Trim right */
    i = 0;
    while((' ' != newValue[i]) && (MSF_EOS != newValue[i]))
    {
        i++;
    }
    newValue[i] = MSF_EOS;

    /* Verify the address */
    /*lint -e{788} */
    switch(meaGetAddrType(newValue))
    {
    case MEA_ADDR_TYPE_EMAIL:
        status = meaAddrItemInsert(item, NULL, MEA_ADDR_TYPE_EMAIL, newValue);
        break;
    case MEA_ADDR_TYPE_PLMN:
        status = meaAddrItemInsert(item, NULL, MEA_ADDR_TYPE_PLMN, newValue);
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MASCH_9997EA28761553E91E86470D4820172F, "(%s) (%d) Address rejected: %s\n", __FILE__, __LINE__, newValue));
        status = FALSE;
        break;
    }
    MEA_FREE(freeData); 
    return status;
}


/*!
 * \brief Parse the scheme and present a C-structure with the scheme filled in.
 *
 * \param scheme The scheme, e.g., "mmsto:homer@simpson.com"
 * \return The scheme as a C-structure.
 *****************************************************************************/
MeaPropItem *meaSchemeToPropItem(const char *scheme)
{
    char *schemeStart;
    char *schemeStop;
    char *delimiter;
    char *nextDelimiter;
    char *name;
    char *value;
    char tmpChar;
    unsigned int length;
    MeaPropItem *propItem = NULL;
    int i;
    const char *schemes[4] = {MEA_SCHEME_MMS_TO, MEA_SCHEME_MAIL_TO, 
        MEA_SCHEME_MMS, NULL};

    /* Find scheme type */
    i = 0;
    schemeStart = NULL;
    while(schemes[i] != NULL)
    {
        /*lint -e{605} */
        if (NULL != (schemeStart = strstr(scheme, schemes[i])))
        {
            break;
        }
        ++i;
    }
    if (NULL == schemeStart)
    {
        return propItem;
    }
    schemeStop = schemeStart + strlen(schemes[i])*sizeof(char);
    /* Create the property item */
    propItem = MEA_ALLOC(sizeof(MeaPropItem));
    memset(propItem, 0, sizeof(MeaPropItem));
    /* Find the to field */
    delimiter = strchr(schemeStop, MEA_SCHEME_TO_DELIMITER);
    if (NULL == delimiter)
    {
        /* Fill in to field */
        (void)setAddr(&(propItem->to), schemeStop);
        return propItem;
    }
    else
    {
        tmpChar = schemeStop[delimiter - schemeStop];
        schemeStop[delimiter - schemeStop] = '\0';
        (void)setAddr(&(propItem->to), schemeStop);
        schemeStop[delimiter - schemeStop] = tmpChar;
    }

    /* Find Cc and Subject */
    while(NULL != delimiter)
    {
        /* Find the next delimiter */
        nextDelimiter = strchr(delimiter + sizeof(char), 
            MEA_SCHEME_FIELD_DELIMITER);
        if (NULL != nextDelimiter)
        {
            length = (unsigned)(nextDelimiter - delimiter);
        }
        else
        {
            length = strlen(delimiter);
        }
        /* Check for CC */
        value = NULL;
        if (NULL != (name = strstr(delimiter, MEA_SCHEME_CC)))
        {
            value = &(name[sizeof(MEA_SCHEME_CC) - 1]);
            tmpChar = value[length - sizeof(MEA_SCHEME_CC)];
            value[length - sizeof(MEA_SCHEME_CC)] = '\0';
            (void)setAddr(&(propItem->cc), value);
            value[length - sizeof(MEA_SCHEME_CC)] = tmpChar;
        }
        else if (NULL != (name = strstr(delimiter, MEA_SCHEME_SUBJECT)))
        {
            value = &(name[sizeof(MEA_SCHEME_SUBJECT) - 1]);
            setSubject(&(propItem->subject), value, length - 
                sizeof(MEA_SCHEME_SUBJECT));
        }
        /* Check next delimiter */
        delimiter = nextDelimiter;
    }
    return propItem;
}


