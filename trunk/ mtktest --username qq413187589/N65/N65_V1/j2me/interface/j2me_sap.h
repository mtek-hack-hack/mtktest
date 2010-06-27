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
 * Filename:
 * ---------
 *  j2me_sap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifdef __SUN_RI__
MSG_ID_MMI_J2ME_ACTIVATE_REQ = MSG_ID_J2ME_CODE_BEGIN,
    MSG_ID_MMI_J2ME_PAUSE_REQ, 
    MSG_ID_MMI_J2ME_RESUME_REQ, 
    MSG_ID_MMI_J2ME_DEACTIVATE_REQ,
#else /* __SUN_RI__ */ 
   /*************************************************************************** 
    * For message table implementation simplicity, 
    * request/indication input messages are put together. 
    **************************************************************************/

   /**************************************************************************
    * Request or Indication Messages (Input
    **************************************************************************/

   /* Get MIDlet Suite/MIDlet List */
MSG_ID_MMI_JAVA_MIDS_GETLIST_REQ = MSG_ID_J2ME_CODE_BEGIN, 
MSG_ID_MMI_JAVA_MID_GETLIST_REQ,
    /* MIDlet Start/Stop notification */
    MSG_ID_MMI_JAVA_MID_START_REQ, 
    MSG_ID_MMI_JAVA_MID_STOP_RES,
    /* Get MIDlet Suite information */
    MSG_ID_MMI_JAVA_MIDS_GETINFO_REQ,
    /* Get/Set MIDlet Suite settings */
    MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ, 
    MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ,
    /* Update MIDlet Suite */
    MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ,
    /* Remove MIDlet Suite */
    MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ, 
    MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES,
    /* Install MIDlet Suite */
    MSG_ID_JAVA_WAP_INSTALL_MIDS_IND,
    MSG_ID_MMI_JAVA_INSTALL_MIDS_REQ,
    MSG_ID_MMI_JAVA_INSTALL_MIDS_RES,
    MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES,
    MSG_ID_JAVA_WAP_GET_FILE_AND_SAVE_CNF,
    MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_RES,
    MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_RES,
    MSG_ID_JAVA_WAP_POST_DATA_CNF,
    MSG_ID_JAVA_WAP_DATA_ACCOUNT_IND,
    MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_PROGRESS_RES, 
    MSG_ID_MMI_JAVA_GET_INSTALL_DRV_RES,
    /* Local installation */
    MSG_ID_MMI_JAVA_LOCAL_INSTALL_REQ,
    /* ABORT */
    MSG_ID_MMI_JAVA_ABORT_REQ, 
    MSG_ID_JAVA_WAP_ABORT_CNF, 
    MSG_ID_MMI_WAP_ABORT_REQ,
    /* PUSH */
    MSG_ID_JAVA_MMI_TIMEALARM_PUSH_RES,
    /* Push timeout message is system timeout message */
    /* get user confirm */
    MSG_ID_MMI_JAVA_GET_CONFIRM_RES,
    /* get authentication */
    MSG_ID_MMI_JAVA_GET_AUTH_RES,
    /* security doamin setting for OGDR 5.0 */
    MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_REQ,
    MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_REQ, 
    MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_REQ,
    MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_REQ,
    /* INFUSIO IMSI */
    MSG_ID_MMI_JAVA_GET_IMSI_RES,   /* MMI-> JAVA */
   /**************************************************************************
    * Confirm or Response Messages (Output)
    **************************************************************************/
    /* Get MIDlet Suite List */
    MSG_ID_MMI_JAVA_MIDS_GETLIST_CNF, 
    MSG_ID_MMI_JAVA_MID_GETLIST_CNF,
    /* MIDlet Start/Stop notification */
    MSG_ID_MMI_JAVA_MID_START_CNF, 
    MSG_ID_MMI_JAVA_MID_STOP_IND,
    /* Get MIDlet Suite information */
    MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF,
    /* Get/Set MIDlet Suite settings */
    MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF, 
    MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF,
    /* Update MIDlet Suite */
    MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF,
    /* Remove MIDlet Suite */
    MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND, 
    MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF,
    /* Install MIDlet Suite */
    MSG_ID_JAVA_WAP_INSTALL_MIDS_RES,
    MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF,
    MSG_ID_MMI_JAVA_INSTALL_MIDS_IND,
    MSG_ID_MMI_JAVA_INSTALL_CONFIRM_IND,
    MSG_ID_JAVA_WAP_GET_FILE_AND_SAVE_REQ,
    MSG_ID_MMI_WAP_GET_FILE_AND_SAVE_RES,
    MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_IND,
    MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_IND,
    MSG_ID_JAVA_WAP_POST_DATA_REQ, 
    MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_PROGRESS_IND, 
    MSG_ID_MMI_JAVA_GET_INSTALL_DRV_IND,
    MSG_ID_MMI_JAVA_SHOW_PERCENTAGE_IND,
    /* Local installation */
    MSG_ID_MMI_JAVA_LOCAL_INSTALL_CNF,
    /* ABORT */
    MSG_ID_MMI_JAVA_ABORT_CNF, 
    MSG_ID_JAVA_WAP_ABORT_REQ, 
    MSG_ID_MMI_WAP_ABORT_CNF,
    /* PUSH & TimeAlarm */
    MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND, 
    MSG_ID_JAVA_JAVA_MID_START_REQ,
    /* get user permission */
    MSG_ID_MMI_JAVA_GET_PERMISSION_IND, /* add by eric */
    /* get user confirm */
    MSG_ID_MMI_JAVA_GET_CONFIRM_IND,
    /* get authentication */
    MSG_ID_MMI_JAVA_GET_AUTH_IND,
#endif /* __SUN_RI__ */ 
    MSG_ID_MMI_J2ME_EXIT_SCREEN_REQ,
    /* Set Java mode to execute */
    MSG_ID_MMI_JAVA_SET_MODE_REQ, 
    MSG_ID_MMI_JAVA_SET_MODE_CNF,
    /* Unit test */
    MSG_ID_MMI_JAM_UT_GETLIST_REQ,
    /* Interwork */
    MSG_ID_JAM_JASYN_PUSHUT_REQ,
    MSG_ID_MMI_JAVA_SHOW_ALERT_USER_DIALOG_REQ,
    MSG_ID_JAVA_MMA_EVENT_CALLBACK, 
    MSG_ID_JAVA_KEYPAD_NOTIFY_IND,
    /* CMCC PHB */
    MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ,
    MSG_ID_MMI_PHB_JAVA_SET_ENTRY_RSP,
    MSG_ID_MMI_PHB_JAVA_GET_ENTRY_REQ,
    MSG_ID_MMI_PHB_JAVA_GET_ENTRY_RSP, 
    MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_REQ, 
    MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_RSP,
    MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_REQ,
    MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_RSP,
    MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ,
    MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_RSP,
    MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ,
    MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_RSP,
    MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_REQ,
    MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_RSP,
    /* security doamin setting for OGDR 5.0 */
    MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_CNF,
    MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_CNF,
    MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_CNF,
    MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_CNF,
    /* INFUSIO IMSI */
    MSG_ID_MMI_JAVA_GET_IMSI_IND,   /* JAVA -> MMI */
    MSG_ID_WAP_MMI_EUREKA_START_REQ,    
    MSG_ID_MMI_WAP_EUREKA_START_RES,
    MSG_ID_JAVA_JAVA_ENQUEUE_SMS_REQ,

    /* Pause by VM itself */
    MSG_ID_MMI_JAVA_PAUSE_IND,  /* JAVA -> MMI */

    /**************************************************************************
     * JBlendia
     **************************************************************************/		
    MSG_ID_MMI_JAVA_JBLENDIA_ACTION_CMD,
    MSG_ID_J2ME_JASYN_PAUSE_VM_REQ, /* add by ting */
    MSG_ID_J2ME_JASYN_RESUME_VM_REQ,
    MSG_ID_J2ME_JASYN_STOP_VM_REQ,
