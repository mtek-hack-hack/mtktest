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

/* !\file mtr_cmn.h
 *  \brief Common data-types and constants used internally by the MTR.
 */

#ifndef _MTRCMN_H_
#define _MTRCMN_H_

#include "mtr.h"

/******************************************************************************
 * Constants
 *****************************************************************************/

#define MSF_MODID_MTR MSF_MODID_MEA

#define MTR_ALLOC MEA_ALLOC

#define MTR_FREE MEA_FREE

/*!
 *  NOTE! Since regular expressions are not supported there is special
 *  handling of dynamic schemes.
 */
#ifdef WAP_SUPPORT
#define MTR_SUPPORTED_SCHEMES  {{MTR_SCHEME_NONE, NULL, 0}}
#else
#define MTR_SUPPORTED_SCHEMES  \
    {{MTR_SCHEME_HTTP, "http://", sizeof("http://") - 1},\
     {MTR_SCHEME_HTTPS, "https://", sizeof("https://") - 1},\
     {MTR_SCHEME_WWW, "www", sizeof("www") - 1},\
     {MTR_SCHEME_MAIL, NULL, 0},\
     {MTR_SCHEME_PHONE, NULL, 0},\
     {MTR_SCHEME_NONE, NULL, 0}\
    }
#endif /*WAP_SUPPORT*/

#define IS_SET(flags, flag)   (((flags) & (flag)) == (flag))

/******************************************************************************
 * Data-types
 *****************************************************************************/


/*! \struct MtrParseResult
 */
typedef struct _MtrParseList  
{
    int index;
    MtrScheme scheme;
    char *link;
    int utf8Len;
    MsfPosition pos;
    MSF_BOOL isSelected;
    struct _MtrParseList *next;
    struct _MtrParseList *prev;
}MtrParseResult;


/*! \struct MtrInstance
 *  \brief  A data structure for keeping instance data.
 */
typedef struct 
{
    int instance;
    MsfGadgetHandle gadgetHandle;
    MsfStringHandle stringHandle;
    MtrCreateTextBoxProperties prop;

    MsfSize boxSize;
    /* Result data */
    MtrParseResult *parse;
    MsfSize actualSize;
    /* State data */
    MtrParseResult *selectedLink;
    MsfEventType currentEvent;
    int prevIndex;
    int prevEndIndex;
    int currentIndex;
    int currentEndIndex;
    int nextIndex;
    int nextEndIndex;
    MSF_BOOL fullScreen;
    MSF_BOOL lostFocus;
    MSF_BOOL redraw;
    int totalLength;
    char *charBuffer;
} MtrInstance;

void mtrFreeLinks(MtrLinkEntry **data);
void mtrInsertParseEntry(int charPos, const char *str, int utf8Len, 
    MtrScheme scheme, MtrParseResult **parse);
char *mtrGetStringBufferFromHandle(MsfStringHandle strHandle);
char *mtrStrDup(const char *str);
void mtrFreeParseResult(MtrParseResult **data);
MSF_BOOL mtrCopyLinkList(const MtrParseResult *parse, MtrLinkEntry **links);
#endif

