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
 /*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wap_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   l4 related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
    MSG_ID_WAP_STATUS_UPDATE_IND = MSG_ID_WAP_CODE_BEGIN,
    
    MSG_ID_WAP_PROF_ACCESS_REQ,
    MSG_ID_WAP_BROWSER_POWEROFF_REQ,
    MSG_ID_WAP_BROWSER_POWEROFF_RSP,	
    MSG_ID_WAP_BROWSER_STARTUP_REQ,
    MSG_ID_WAP_MMI_READY_IND,
    MSG_ID_WAP_INTERNAL_ERROR_IND,
    MSG_ID_WAP_BROWSER_SHUTDOWN_REQ,
    MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ,
    MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF,	
    MSG_ID_MEA_STARTUP_REQ,
    MSG_ID_MEA_STARTUP_NEW_MMS_REQ,
    MSG_ID_MEA_UM_ENTRY_REQ,
    MSG_ID_MEA_PHB_ADDR_INPUT_IND,
    MSG_ID_WAP_PHB_ADDR_INPUT_IND = MSG_ID_MEA_PHB_ADDR_INPUT_IND,
    MSG_ID_MEA_SHUTDOWN_REQ,
    MSG_ID_MMS_ENTER_USB_MODE_REQ,
    MSG_ID_MMS_ENTER_USB_MODE_RSP,
    MSG_ID_MMS_EXIT_USB_MODE_REQ,
    MSG_ID_MMS_EXIT_USB_MODE_RSP,
    MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ,
    MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP,
    MSG_ID_WAP_MMI_KEY_INDICATION,
    MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ,
    MSG_ID_WAP_MMI_LAUNCH_BROWSER_RSP,
    MSG_ID_WAP_MMI_BROWSER_TERMINATION_IND,
    MSG_ID_WAP_MMI_JAVA_INTALL_REQ,
    MSG_ID_WAP_GET_PROF_LIST_REQ,
    MSG_ID_WAP_GET_PROF_LIST_RSP,
    MSG_ID_WAP_GET_PROF_CONTENT_REQ,
    MSG_ID_WAP_GET_PROF_CONTENT_RSP,	
    MSG_ID_WAP_GET_BRA_PROF_ID_REQ,	
    MSG_ID_WAP_GET_BRA_PROF_ID_RSP,	
    MSG_ID_WAP_GET_USER_AGENT_REQ,
    MSG_ID_WAP_GET_USER_AGENT_RSP,
    MSG_ID_WAP_READY_IND,
    MSG_ID_WAP_BEARER_STATUS_IND,
    MSG_ID_WAP_SELECT_BOOKMARK_REQ,
    MSG_ID_WAP_SELECT_BOOKMARK_RSP,
    MSG_ID_WAP_SIM_INFO_NOTIFY_IND,
    
    MSG_ID_WAP_MMC_SEND_APPMMS_REQ,
    MSG_ID_WAP_MMC_SEND_APPMMS_RSP,
    MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND,
    MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES,
    MSG_ID_WAP_MMC_RECV_APPMMS_REQ,
    MSG_ID_WAP_MMC_RECV_APPMMS_RSP,
    MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ,
    MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP,
    MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ,
    MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP,
    MSG_ID_WAP_MMC_ABORT_APPMMS_REQ,
    MSG_ID_WAP_MMC_ABORT_APPMMS_RSP,
    MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ,
    MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP,	
    MSG_ID_WAP_MMC_GET_MMS_PROF_REQ,
    MSG_ID_WAP_MMC_GET_MMS_PROF_RSP,
    MSG_ID_WAP_MMC_APPMMS_NEW_MMS_IND,
    MSG_ID_WAP_MMA_TERMINATE_IND,
    MSG_ID_WAP_MMA_UM_ENTRY_REQ,
    MSG_ID_WAP_MMA_UC_START_REQ,
    MSG_ID_WAP_MMA_UC_START_RSP,
    MSG_ID_WAP_MMA_GET_SETTING_REQ,
    MSG_ID_WAP_MMA_GET_SETTING_RSP,
    MSG_ID_WAP_MMA_SET_SETTING_REQ,
    MSG_ID_WAP_MMA_SET_SETTING_RSP,
    MSG_ID_WAP_MMA_GET_PROFILE_REQ,
    MSG_ID_WAP_MMA_GET_PROFILE_RSP,    
    MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ,
    MSG_ID_WAP_MMA_GET_MEM_STATUS_RSP,
    MSG_ID_WAP_MMA_SET_PROFILE_REQ,
    MSG_ID_WAP_MMA_SET_PROFILE_RSP,
    MSG_ID_WAP_MMA_GET_CONTENT_REQ,
    MSG_ID_WAP_MMA_GET_CONTENT_RSP,
    MSG_ID_WAP_MMA_CREATE_REQ,
    MSG_ID_WAP_MMA_CREATE_RSP,
    MSG_ID_WAP_MMA_DELETE_REQ,
    MSG_ID_WAP_MMA_DELETE_RSP,
    MSG_ID_WAP_MMA_SAVE_REQ,
    MSG_ID_WAP_MMA_SAVE_RSP,
    MSG_ID_WAP_MMA_PREVIEW_REQ,
    MSG_ID_WAP_MMA_PREVIEW_RSP,
    MSG_ID_WAP_MMA_SEND_REQ,
    MSG_ID_WAP_MMA_SEND_IND,
    MSG_ID_WAP_MMA_SEND_RSP,
    MSG_ID_WAP_MMA_CANCEL_SEND_REQ,
    MSG_ID_WAP_MMA_CANCEL_SEND_RSP,
    MSG_ID_WAP_MMA_DOWNLOAD_REQ,
    MSG_ID_WAP_MMA_DOWNLOAD_RSP,
    MSG_ID_WAP_MMA_DOWNLOAD_IND,
    MSG_ID_WAP_MMA_DOWNLOAD_RES,
    MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ,
    MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP,
    MSG_ID_WAP_MMA_GET_MSG_INFO_REQ,
    MSG_ID_WAP_MMA_GET_MSG_INFO_RSP,
    MSG_ID_WAP_MMA_SET_READMARK_REQ,
    MSG_ID_WAP_MMA_SET_READMARK_RSP,
    MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND,
    MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND,
    MSG_ID_WAP_MMA_SET_APP_DATA_REQ,
    MSG_ID_WAP_MMA_SET_APP_DATA_RSP,
    MSG_ID_WAP_MMA_GET_MSG_LIST_REQ,
    MSG_ID_WAP_MMA_GET_MSG_LIST_RSP,    
    MSG_ID_WAP_MMA_STORAGE_FULL_IND,
    MSG_ID_WAP_MMA_VIEW_MSG_IND,    
    MSG_ID_WAP_MMA_MSG_IS_VALID_REQ,
    MSG_ID_WAP_MMA_MSG_IS_VALID_RSP,
    
    #include "bam_sap.h"
    #include "pmg_sap.h"
    
    MSG_ID_WPS_SET_CHANNEL_REQ,	
    MSG_ID_WPS_SET_CHANNEL_RSP,
    MSG_ID_WPS_UNSET_CHANNEL_REQ,
    MSG_ID_WPS_UNSET_CHANNEL_RSP,
    MSG_ID_WPS_RECONFIG_CHANNEL_REQ,	
    MSG_ID_WPS_RECONFIG_CHANNEL_RSP,
    MSG_ID_WPS_HTTP_REQ,
    MSG_ID_WPS_HTTP_RSP,
    MSG_ID_WPS_READ_CONTENT_REQ,
    MSG_ID_WPS_READ_CONTENT_RSP,
    MSG_ID_WPS_POST_CONTENT_IND,
    MSG_ID_WPS_POST_CONTENT_RES,
    MSG_ID_WPS_DL_PROGRESS_IND,
    MSG_ID_WPS_DL_PROGRESS_RES,
    MSG_ID_WPS_CANCEL_REQ,
    MSG_ID_WPS_CANCEL_RSP,
    MSG_ID_WPS_PUSH_IND,
    MSG_ID_WPS_CLEAR_REQ,
    MSG_ID_WPS_CLEAR_RSP,
    MSG_ID_WPS_CREATE_STREAM_CONNECTION_REQ,
    MSG_ID_WPS_CREATE_STREAM_CONNECTION_RSP,
    MSG_ID_WPS_STREAM_CONNECTION_CLOSED_IND,
    MSG_ID_WPS_CLOSE_STREAM_CONNECTION_REQ,
    MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP,
    MSG_ID_WPS_STREAM_DATA_SEND_REQ,
    MSG_ID_WPS_STREAM_DATA_SEND_RSP,
    MSG_ID_WPS_STREAM_DATA_READ_REQ,
    MSG_ID_WPS_STREAM_DATA_READ_RSP,
    MSG_ID_WPS_EXT_MSG_IND,
    MSG_ID_WPS_READY_IND,
    MSG_ID_WPS_SEC_GET_SESSION_INFO_REQ,
    MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP,
    MSG_ID_WPS_SEC_GET_CURRENT_CERT_REQ,
    MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP,  
    MSG_ID_WPS_HTTP_AUTH_IND,
    MSG_ID_WPS_HTTP_AUTH_RES,
    MSG_ID_WPS_STATUS_QUERY_REQ,
    MSG_ID_WPS_STATUS_QUERY_RSP,          
    MSG_ID_WAP_MMI_FILE_DL_IND,
    MSG_ID_WAP_MMI_FILE_DL_RES,
    MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND,
    MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES,
    MSG_ID_WAP_MMI_FILE_DL_STOP_REQ,
    MSG_ID_WAP_MMI_FILE_DL_STOP_RSP,
    MSG_ID_WPS_JATAAYU_TRANSPORT_START_IND, 
    MSG_ID_WPS_JATAAYU_QUEUE_RECV_IND,    
    MSG_ID_MMS_BGSR_SEND_RSP,
    MSG_ID_MMS_BGSR_DOWNLOAD_RSP,
    MSG_ID_MMS_BGSR_CANCEL_SEND_RSP,
    MSG_ID_MMS_BGSR_CANCEL_DOWNLOAD_RSP,    
    MSG_ID_MMS_BGSR_NAV_ACTIVATE_BGSR_RSP,
    MSG_ID_MMS_BGSR_DELETE_MSG_RSP,
    MSG_ID_MMS_BGSR_DELETE_ALL_INBOX_RSP,
    MSG_ID_MMS_BGSR_CANCEL_ALL_INBOX_RSP,
    MSG_ID_MMS_BGSR_DELETE_ALL_OUTBOX_RSP,    
    MSG_ID_MMS_BGSR_MOVE_TO_FOLDER_RSP,
    MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_REQ,
    MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP,   
    MSG_ID_WPS_SEC_DELETE_CA_CERT_REQ,
    MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP,  
    MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_IND,
    MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_RES,  
    MSG_ID_WPS_SEC_GET_X509_CA_CERT_REQ,
    MSG_ID_WPS_SEC_GET_X509_CA_CERT_IND,
    MSG_ID_WPS_SEC_GET_X509_CA_CERT_RSP,   
    MSG_ID_WPS_SEC_GET_CERT_IDS_REQ,
    MSG_ID_WPS_SEC_GET_CERT_IDS_RSP,   
    MSG_ID_WPS_SEC_GET_CERT_REQ,   
    MSG_ID_WPS_SEC_GET_CERT_RSP,   
    MSG_ID_WAP_CODE_END = MSG_ID_WPS_SEC_GET_CERT_RSP,
    
    
