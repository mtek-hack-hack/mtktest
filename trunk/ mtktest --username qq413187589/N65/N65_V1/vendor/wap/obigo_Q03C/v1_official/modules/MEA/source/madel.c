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

/* \file madel.c
 * \brief  Handling of message deletion.
 */

/* MSF */
#include "msf_int.h"
#include "msf_core.h"
#include "msf_cfg.h"
#include "msf_log.h"

/* MMS Service */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "msig.h"  /* for fldmgr.h */
#include "fldmgr.h"  /* for fldrMgrDeleteMessage */

/* MEA */
#include "mea_cfg.h"
#include "mea_def.h"
#include "mea_rc.h"
#include "maintsig.h"
#include "mauidia.h"
#include "mamh.h"

#ifdef MMS_SUPPORT
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
extern MSF_BOOL mmcRemoveMsgIdFromJSRIndex(MSF_UINT32 msgId);
#endif
/******************************************************************************
 * Function implementation
 *****************************************************************************/
#ifdef WAP_SUPPORT
void meaDeleteAllMsg(MeaFolder folder)
{
    MSF_UINT32 strId;
    switch (folder)
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__  
        case MEA_FOLDER_ARCHIVE:
            strId = MEA_STR_ID_DELETE_ALL_ARCHIVE;
			break;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/           
        case MEA_FOLDER_INBOX:
            strId = MEA_STR_ID_DELETE_ALL_INBOX;
			break;
        case MEA_FOLDER_DRAFTS:
            strId = MEA_STR_ID_DELETE_ALL_DRAFTS;
			break;
        case MEA_FOLDER_OUTBOX:
            strId = MEA_STR_ID_DELETE_ALL_OUTBOX;
			break;
        case MEA_FOLDER_SENT:
            strId = MEA_STR_ID_DELETE_ALL_SENT;
			break;
        case MEA_FOLDER_TEMPLATE:
            strId = MEA_STR_ID_DELETE_ALL_TEMPLATE;
			break;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        case MEA_FOLDER_USER_TEMPLATE:
            strId = MEA_STR_ID_DELETE_ALL_TEMPLATE;
            break;
#endif
        default:
			return;
    }
#ifdef __MMI_MMS_BGSR_SUPPORT__
    if( folder == MEA_FOLDER_INBOX || folder == MEA_FOLDER_OUTBOX)
    {
        (void)meaShowConfirmDialog(strId, NULL, MEA_MH_FSM, MEA_SIG_MH_BGSR_DELETE_ALL_MSG_REQ, (unsigned int)folder);
    }
    else
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
    {
#ifdef __UNIFIED_MSG_SUPPORT__
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    if (folder != MEA_FOLDER_USER_TEMPLATE)
    {
#endif
    (void)meaShowConfirmDialog(strId, NULL, MEA_MH_FSM, MEA_SIG_MH_UM_DELETE_ALL_MSG_REQ, (unsigned int)folder);
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    }
    else
    {
        (void)meaShowConfirmDialog(strId, NULL, MEA_MH_FSM, MEA_SIG_MH_DELETE_ALL_MSG, (unsigned int)folder);
    }
#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/
#else
    (void)meaShowConfirmDialog(strId, NULL, MEA_MH_FSM, MEA_SIG_MH_DELETE_ALL_MSG, (unsigned int)folder);
#endif    
    }
}
#endif /* WAP_SUPPORT */

/*!
 * \brief Deletes a message completely: 1. update folder(Show Done popup) 2. delete checksum 3. delete JSR entry
 *
 * \param msgId The ID of the message to delete
 *****************************************************************************/
extern void delChkSumFile(MmsMsgId msgId);
void meaDeleteMsg(MmsMsgId msgId)
{
    if (msgId == 0)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MADEL_FB9BD416D8EF1E1CC6496BE6EEF032FD, "%s(%d): Removal of non-existent message!\n", __FILE__, __LINE__));
    }
    else
    {
        /* Delete message without asking */
        MMSif_deleteMessage(MSF_MODID_MEA, msgId);
#ifdef MMS_FILE_PROTECT_SUPPORT
	delChkSumFile(msgId);
#endif        
#ifdef MMS_SUPPORT
        if(mmcIsJSRMsg(msgId))
		{
            mmcRemoveMsgIdFromJSRIndex(msgId);
		}
#endif
    }
}

/*!
 * \brief Deletes a message silently: 1. update folder 2. delete checksum 3. delete JSR entry
 *
 * \param msgId The ID of the message to delete
 *****************************************************************************/
MSF_BOOL meaDeleteMsgSilent(MmsMsgId msgId)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, MADEL_5F2AD780F0A72C3176E00903FC875B46, "%s(%d): meaDeleteMsgSilent\n", __FILE__, __LINE__));

    if (msgId == 0)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MADEL_FB9BD416D8EF1E1CC6496BE6EEF032FD, "%s(%d): Removal of non-existent message!\n", __FILE__, __LINE__));
	return FALSE;
    }
    else
    {
        if(fldrMgrDeleteMessage(msgId) != MMS_RESULT_OK)
        {
            return FALSE;
        }

#ifdef MMS_FILE_PROTECT_SUPPORT
        delChkSumFile(msgId);
#endif        
#ifdef MMS_SUPPORT
        if(mmcIsJSRMsg(msgId))
        {
            mmcRemoveMsgIdFromJSRIndex(msgId);
        }
#endif
        (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, MEA_FOLDER_NONE);
    }
    return TRUE;
}

/*!
 * \brief Deletes a message emergenty(no message passing), ex. when press end key: 1. delete message 2. delete checksum 3. delete JSR entry
 *
 * \param msgId The ID of the message to delete
 *****************************************************************************/
MSF_BOOL meaDeleteMsgEmergency(MmsMsgId msgId)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, MADEL_DF820EA1858BB3966950435B6E4E90B9, "%s(%d): meaDeleteMsgEmergency\n", __FILE__, __LINE__));

    if (msgId == 0)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MADEL_FB9BD416D8EF1E1CC6496BE6EEF032FD, "%s(%d): Removal of non-existent message!\n", __FILE__, __LINE__));
	return FALSE;
    }
    else
    {
        if(fldrMgrDeleteMessage(msgId) != MMS_RESULT_OK)
        {
            return FALSE;
        }

#ifdef MMS_FILE_PROTECT_SUPPORT
        delChkSumFile(msgId);
#endif        
#ifdef MMS_SUPPORT
        if(mmcIsJSRMsg(msgId))
        {
            mmcRemoveMsgIdFromJSRIndex(msgId);
        }
#endif
    }
    return TRUE;
}
