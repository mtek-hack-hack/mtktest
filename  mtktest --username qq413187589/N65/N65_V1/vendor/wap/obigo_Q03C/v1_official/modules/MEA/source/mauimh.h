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

/*!\file mauimh.h
 * \brief Definitions for the MH user interface.
 */

#ifndef _MAUIMH_H_
#define _MAUIMH_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

#ifndef WAP_SUPPORT
#define MEA_STARTUP_MENU_ITEMS {{MEA_STR_ID_NEW_SMIL,   MEA_MH_NEW_SMIL}, \
                                {MEA_STR_ID_INBOX,      MEA_MH_INBOX}, \
                                {MEA_STR_ID_DRAFTS,     MEA_MH_DRAFTS}, \
                                {MEA_STR_ID_SENT,       MEA_MH_SENT}, \
                                {MEA_STR_ID_TEMPLATES,  MEA_MH_TEMPLATE}, \
                                {MEA_STR_ID_OUTBOX,     MEA_MH_OUTBOX}, \
                                {MEA_STR_ID_CONFIG,     MEA_MH_SETTINGS}, \
                                {MEA_STR_ID_EXIT,       MEA_MH_BACK}, \
                                {MEA_STR_ID_EMPTY_STRING, -1}}

#else /* ~WAP_SUPPORT */

  #if defined MEA_MERGE_SENT
#define MEA_STARTUP_MENU_ITEMS {{MEA_STR_ID_WRITE_MESSAGE,   MEA_MH_NEW_SMIL, MEA_IMG_WRITE_MESSAGE}, \
                                {MEA_STR_ID_INBOX, MEA_MH_INBOX, MEA_IMG_INBOX}, \
                                {MEA_STR_ID_OUTBOX,     MEA_MH_OUTBOX, MEA_IMG_OUTBOX}, \
                                {MEA_STR_ID_DRAFTS,     MEA_MH_DRAFTS, MEA_IMG_DRAFTS}, \
                                {MEA_STR_ID_TEMPLATES,  MEA_MH_TEMPLATE, MEA_IMG_TEMPLATES}, \
                                {MEA_STR_ID_CONFIG,     MEA_MH_SETTINGS, MEA_IMG_SETTINGS}, \
                                {MEA_STR_ID_EMPTY_STRING, -1}}
  #elif defined(MEA_MERGE_OUTBOX)
#define MEA_STARTUP_MENU_ITEMS {{MEA_STR_ID_INBOX, MEA_MH_INBOX, MEA_IMG_INBOX}, \
                                {MEA_STR_ID_OUTBOX,     MEA_MH_OUTBOX, MEA_IMG_OUTBOX}, \
                                {MEA_STR_ID_WRITE_MESSAGE,   MEA_MH_NEW_SMIL, MEA_IMG_WRITE_MESSAGE}, \
                                {MEA_STR_ID_SENT,       MEA_MH_SENT, MEA_IMG_SENT}, \
                                {MEA_STR_ID_TEMPLATES,  MEA_MH_TEMPLATE, MEA_IMG_TEMPLATES}, \
                                {MEA_STR_ID_CONFIG,     MEA_MH_SETTINGS, MEA_IMG_SETTINGS}, \
                                {MEA_STR_ID_EMPTY_STRING, -1}}
  #else
#define MEA_STARTUP_MENU_ITEMS {{MEA_STR_ID_INBOX, MEA_MH_INBOX, MEA_IMG_INBOX}, \
                                {MEA_STR_ID_WRITE_MESSAGE,   MEA_MH_NEW_SMIL, MEA_IMG_WRITE_MESSAGE}, \
                                {MEA_STR_ID_DRAFTS,     MEA_MH_DRAFTS, MEA_IMG_DRAFTS}, \
                                {MEA_STR_ID_SENT,       MEA_MH_SENT, MEA_IMG_SENT}, \
                                {MEA_STR_ID_TEMPLATES,  MEA_MH_TEMPLATE, MEA_IMG_TEMPLATES}, \
                                {MEA_STR_ID_OUTBOX,     MEA_MH_OUTBOX, MEA_IMG_OUTBOX}, \
                                {MEA_STR_ID_CONFIG,     MEA_MH_SETTINGS, MEA_IMG_SETTINGS}, \
                                {MEA_STR_ID_EMPTY_STRING, -1}}
  #endif /* MEA_MERGE_OUTBOX */

typedef struct 
{
    /* Startup data */
    MmsMsgId            msgId;      /*!< The current message id */
    MmsFileType         fileType;   /*!< The type of message to open */

    /* Derived data */
    char            *fileName;      /*!< The filename of the message */
    //MeaMessageType  msgType;        /*!< The message type */

    /* The message properties */
    MeaPropItem     *msgProperties; /*!< Message properties */    

    /* The new SMIL presentation */
    MeaSmilInfo     *smilInfo;      /*!< The new SMIL presentation */
}MeaMhMessage;

typedef struct 
{
    /* Used internally */
    MeaStateMachine     fsm;             /*!< The callback FSM */
    unsigned int        signal;          /*!< The callback signal */
    MSF_UINT32          slideCount;      /*!< The total number of slides */
    unsigned int        sizeWarning;     /*!< Number of size warnings */

    MeaMhMessage          *msg;            /*!< The message being created */

    /* Retrieval data */
    MmsGetHeader            *msgHeader;     /*!< The retrieved header */
    MmsTransactionHandle    transaction;    /*!< Transaction handle */
    MmsMsgHandle            msgHandle;      /*!< Message handle */

#ifdef __UNIFIED_MSG_SUPPORT__
    MmsNotification  *notif;
#endif
}MeaMhInstance;

typedef enum
{
    MEA_MH_NUM_LIST_DIAL,
    MEA_MH_NUM_LIST_SAVE_PHB,
	MEA_MH_NUM_LIST_WRITE_MMS,
	MEA_MH_NUM_LIST_WRITE_SMS
}MeaMhUseNumberMenuItem;

typedef enum
{
    MEA_MH_USE_EMAIL_WRITE_MMS,
    MEA_MH_USE_EMAIL_SAVE_PHB
}MeaMhUseEmailMenuItem;

typedef enum
{
    MEA_MH_USE_URL_BROWSE,
    MEA_MH_USE_URL_ADD_BOOKMARK
}MeaMhUseUrlMenuItem;

#endif /*~WAP_SUPPORT*/
/******************************************************************************
 * Prototypes
 *****************************************************************************/
#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
MSF_BOOL meaCreateMhView(const MmsListOfProperties *list, MeaFolder folder);
int meaGetSelectedMhItem(void);
MSF_BOOL meaMhUpdateList(const MmsListOfProperties *list, MeaFolder folder);
MSF_BOOL meaMhIsActive(void);
void meaDeleteMhView(void);
void meaMhUiInit(void);

MSF_BOOL meaCreateMhNavMenu(MeaFolder folder, MmsMsgId activeMsgId, 
                       MmsFileType msgType, MSF_BOOL forwardLock
#ifdef __MMI_MMS_BGSR_SUPPORT__
                       , mmi_mms_bgsr_msg_info_struct * msg_info
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
                       );
void meaDeleteMhNavMenu(void);

MSF_BOOL meaCreateMhStartupMenu(void);
void meaDeleteMhStartupMenu(void);

#ifdef WAP_SUPPORT
void meaMhUpdateDynamicList(int noOfElements, MeaFolder folder);
void meaDeleteNumberListView(void);
MSF_BOOL meaMhCreateUseNumberNavMenu(void);
MSF_BOOL meaCreateDetailListView(MmsMsgId msgId, SlsUnrefItemList *unrefItems);
void updateHintList(void);
void meaMhCreateUseDetailNavMenu(void);
void meaMhWriteMessageByMail(const char *mail);
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
MSF_BOOL meaCreateTemplatesFolderListView(void);
void meaDeleteTemplatesFolderListView(void);
void updateTemplatesFolderListHint(void);
#endif
#endif /* WAP_SUPPORT */
#endif


