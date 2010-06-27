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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Res_Email.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file populates resource for Email appliction.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/
/**
 *  Copyright Notice
 *  ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *  Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

    FILENAME    : Res_Email.c

    PURPOSE     : Populate Resource for Eamil 

    REMARKS     : nil

    AUTHOR      : Magesh k

    DATE        : 30-01-2004

**************************************************************/
#ifndef _MMI_RES_EMAIL_C
#define _MMI_RES_EMAIL_C
#include "MMI_features.h"

#ifdef __MMI_EMAIL__        // Changes for email

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "EmailAppResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/**************************************************************

    FUNCTION NAME       : EmailResourceData

    PURPOSE             : Register all the resources required
                          by Email application 

    INPUT PARAMETERS    : void

    OUTPUT PARAMETERS   : nil

    RETURNS             : void

    REMARKS             : nil

**************************************************************/
void EmailResourceData (void)
{
    /************************************************************************/
    /*                         Strings in Email                             */
    /************************************************************************/
    // Images 
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_MAIN_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\SB_Email.pbm", "Email main menu Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SEND_AND_RECEIVE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_SNR.pbm", "Email send and receive Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_WRITE_EMAIL_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_WRITE.pbm", "Email write email Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_INBOX_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_INBOX.pbm", "Email inbox Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SENT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_SENT.pbm", "Email sent Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_UNSENT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_UNSENT.pbm", "Email unsent Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DRAFT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_DRAFTS.pbm", "Email draft Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DELETE_ALL_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_DELE.pbm", "Email delete all Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DELETE_ALL_MARK_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_DELE.pbm", "Email delete all mark Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_PROFILE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_PRO.pbm", "Email profile Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_TEMPLATE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_TEMP.pbm", "Email Template Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_REFRESH_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_REPFLASH.pbm", "Email Refresh Image");    
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SWITCH_MODE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\EM_Switch.pbm", "Email Switch mode Image");    
    /* report */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SENT_CAPTION_REPORT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Report\\\\EM_SENT.pbm", "Email sent caption in report Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_RECEIVED_CAPTION_REPORT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Report\\\\EM_RECEIVED.pbm", "Email received caption in report Image");
    /* compose screen */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_TO_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\creat\\\\EM_TO.pbm", "Email to Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_CC_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_CC.pbm", "Email cc Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_BCC_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_BCC.pbm", "Email bcc Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACHMENT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_AT.pbm", "Email attachment Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_PRIORITY_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_PY.pbm", "Email priority Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ENCODING_TYPE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_ENCODING.PBM", "Email encoding Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SUBJECT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_SB.pbm", "Email subject Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_LEFT_BRACKET_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_LEFT.pbm", "Email left bracket Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_RIGHT_BRACKET_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_RIGHT.pbm", "Email right bracket Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_BALNK_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_XX.pbm", "Email blank Image");
    /* read screen */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_FROM_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_From.pbm", "Email from read Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_TO_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_TO.pbm", "Email to read Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_CC_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_CC.pbm", "Email cc read Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_BCC_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Creat\\\\EM_BCC.pbm", "Email bcc read Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_ATTACHMENT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_AT.pbm", "Email attachment read Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_SUBJECT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_SB.pbm", "Email subject read Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_RETRIEVE_TEXT, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Signature\\\\EM_Text.pbm", "Email download option Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_RETRIEVE_ATT, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Signature\\\\\EM_Image.pbm", "Email download option Image");
    /* attachment */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_PIC.pbm", "Email attachment image Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_AUDIO_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Audio.pbm", "Email attachment audio Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_VIDEO_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Video.pbm", "Email attachment video Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_TEXT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Text.pbm", "Email attachment text Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_UNKNOWN_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Unknown.pbm", "Email attachment unknown Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_IMAGE_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_PIC_15x15.pbm", "Email attachment image 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_AUDIO_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Audio_15x15.pbm", "Email attachment audio 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_VIDEO_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Video_15x15.pbm", "Email attachment video 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_TEXT_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Text_15x15.pbm", "Email attachment text 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_UNKNOWN_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Unknown_15x15.pbm", "Email attachment unknown 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_NC_IMAGE_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Unknown_15x15.pbm", "Email attachment image 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_NC_AUDIO_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Unknown_15x15.pbm", "Email attachment audio 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_NC_VIDEO_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Unknown_15x15.pbm", "Email attachment video 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_NC_TEXT_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Unknown_15x15.pbm", "Email attachment text 15x15 Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_ATTACH_NC_UNKNOWN_15x15_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Emailbody\\\\EM_Unknown_15x15.pbm", "Email attachment unknown 15x15 Image");
    /* miscellanea */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_CONNECTING_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Sending\\\\EM_CON"__MMI_RES_TYPE_POPUP_SCREEN__, "Email connecting Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SENDING_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Sending\\\\EM_Send"__MMI_RES_TYPE_POPUP_SCREEN__, "Email sending Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_RECEIVING_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Receiving\\\\EM_Reveive"__MMI_RES_TYPE_POPUP_SCREEN__, "Email receiving Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SEND_FAIL_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\SentFail\\\\EM_FAIL"__MMI_RES_TYPE_POPUP_SCREEN__, "Email send fail Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SEND_SUCCESS_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\SentSuccess\\\\EM_Success"__MMI_RES_TYPE_POPUP_SCREEN__, "Email send success Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_REPORT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Report\\\\EM_Mail.gif", "Email report Image");
    /* folder */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_LOW_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Read\\\\EM_LReadL.pbm", "Email read low Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_NORMAL_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Read\\\\EM_LRead.pbm", "Email read normal Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_READ_HIGH_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Read\\\\EM_LReadH.pbm", "Email read high Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_UNREAD_LOW_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\UnRead\\\\EM_LUnreadL.PBM", "Email unread low Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_UNREAD_NORMAL_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\UnRead\\\\EM_LUnread.PBM", "Email unread normal Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_UNREAD_HIGH_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\UnRead\\\\EM_LUnreadH.PBM", "Email unread high Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_MARK_DELETED_BIG_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\UnRead\\\\EM_Mdelete.pbm", "Email mark deleted Image for double line");
    /* profile */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_PROFILE_SETTING_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_PROST.pbm", "Email profile Setting Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SMTP_SETTING_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_SMTPST.pbm", "Email SMTP Seting Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_IMAP_POP3_SETTING_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_POP3ST.pbm", "Email POP3/IMAP4 Setting Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SIGNATURE_SETTING_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Sig.pbm", "Email Signature Setting Image");
    /* profile setting */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_PROFILE_NAME_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_PName.pbm", "Email profile name Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DATA_ACCOUNT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_DATA.pbm", "Email data account Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_PROTOCOL_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Pocol.pbm", "Email protocol Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_CHECK_INTERVAL_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Cintrval.pbm", "Email check interval Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DOWNLOAD_SIZE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_DLoad.pbm", "Email dowload type Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_REPLY_TO_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_ReplyTo.pbm", "Email Reply-To Image");  
    /* outgoing server */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_OUTGOING_SERVER_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Server.pbm", "Email outgoing server Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_OUTGOING_PORT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Port.pbm", "Email outgoing port Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DISPLAY_NAME_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_DName.pbm", "Email display name Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_EMAIL_ADDRESS_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Edress.pbm", "Email email address Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_AUTH_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Auth.pbm", "Email Authentication Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_AUTH_SAME_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_AuthSame.pbm", "Email Authentication same to incoming server Image");
    /* incoming server */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_INCOMING_SERVER_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Inserver.pbm", "Email incoming server Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_INCOMING_PORT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Inport.pbm", "Email incoming port Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_USER_NAME_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_UName.pbm", "Email user name Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_PASSWORD_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Pad.pbm", "Email password Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DOWNLOAD_OPTION_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Download.pbm", "Email download option Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SERVER_COPY_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_SC.pbm", "Email server copy Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DEL_AFTER_N_DAYS_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_Ddelete.pbm", "Email delete after n days Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DEL_SERVER_MAILS_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_DELE.pbm", "Email delete server mails Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_DRAFT_FOLDER_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_DraftF.pbm", "Email Draft Folder Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SENT_FOLDER_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\ProfileSetting\\\\EM_SentF.pbm", "Email Sent Folder Image");
    /* signature */
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SIGNATURE_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Signature\\\\EM_Image.pbm", "Email signature image Image");
    ADD_APPLICATION_IMAGE2 ( IMG_EMAIL_SIGNATURE_TEXT_ID, CUST_IMG_PATH"\\\\MainLCD\\\\Email\\\\Signature\\\\EM_Text.pbm", "Email signature text Image");
    /************************************************************************/
    /*                         Strings in Email                             */
    /************************************************************************/
    /* common */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_MOVING_ID, "Moving", "Email common moving String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_SAVE_AND_SEND_ID, "Save and Send", "Email common save and send String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_SAVE_TO_DRAFT_ID, "Save To Draft", "Email common save to draft String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_MOVE_TO_DRAFT_ID, "Move To Draft", "Email common Move to draft String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_QUIT_WITHOUT_SAVING_ID, "Quit without Saving", "Email common quit without saving String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_LOADING_ID, "Loading", "Email common Loading String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_SWITCHING_ID, "Switching", "Switching string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_SENT_ID, "Sent", "Email common Sent String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_DOWNLOAD_ID, "Download", "Email download prompt String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_NO_SUBJECT_ID, "<No Subject>", "Email common no subject String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_DETAILS_ID, "Detail", "Email common Detail String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_QUITING_ID, "Quiting", "Email Quiting String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_DELETING_ID, "Deleting", "Email Deleting String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_DELETED_ID, "Deleted", "Email deleted String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMMON_SAVE_CHANGES_ID, "Save changes?", "Email confirm to save changes String");
    /* error code */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID, "Account not configured", "Email Account not configured String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_FOLDER_NOT_EXISTING_ID, "Folder not exist", "Email Folder not exist String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_MSG_NOT_EXISTING_ID, "Message not exist", "Email Message not exist String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_CONN_FAIL_ID, "Server connection failed", "Email common save to draft String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_AUTH_FAIL_ID, "Authentication failed", "Email Authentication failed String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_INVALID_PORT_NUM_ID, "Invalid port", "Email Invalid port String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_INVALID_IP_ADDR_ID, "Invalid IP address", "Email Invalid IP address String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_NETWORK_ID, "Network Error", "Email Network Error String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID, "Invalid Email Address", "Email Invalid email addr String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_BAD_PAGE_NUMBER_ID, "Invalid page number", "Email Invalid page number String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_INVALID_ACCT_INDEX_ID, "Invalid acct index", "Email Invalid acct index String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_APP_SOC_TIMEOUT_ERR_ID, "APP SOC Timeout", "Email APP SOC Timeout String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_UNKNOWN_ID, "Unknown Error", "Email Unknown Error String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_IN_USE_ID, "Email in use", "Email in use String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_READ_ONLY_ACCESS, "Read only access", "Email Read only access String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DNS_ERR, "DNS Error", "Email DNS Error String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SMTP_RCPT_TO_FAIL, "Sender email addr wrong", "Email SMTP_RCPT_TO_FAIL String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_MSG_REQ, "ERROR_MSG_REQ", "Email ERROR_MSG_REQ String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FILE_QUOTA_EXCEEDED, "FILE_QUOTA_EXCEEDED", "Email FILE_QUOTA_EXCEEDED String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_INVALID_MAIL_MESSAGE, "INVALID_MAIL_MESSAGE", "Email INVALID_MAIL_MESSAGE String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FOLDER_SELECT_NOT_PERMITTED, "FOLDER_SELECT_NOT_PERMITTED", "Email FOLDER_SELECT_NOT_PERMITTED String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_NOT_SUPPORT_ID, "Not supported", "Email Not supported String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CONTENT_MESSAGE_TOO_ID, "Message too long!", "Email Messgae too long String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MEMORY_FULL_ID, "Memory Full", "Email Memory Full String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_UIDL_FULL_ID, "System Memory Full", "Email System Memory Full String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_AUTO_CHECK_BUSY_ID, "Busy in auto check", "String for Busy in auto check ");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_OFFLINE_NOTIFIER_ID, "Please Switch to on-line mode", "Please Switch to on-line mode string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_INVALID_FILE_NAME_ID, "Invalid Filename", "String for Invalid Filename");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DUPLICATE_FILENAME, "Duplicated Filename", "Duplicated filename warning string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EMPTY_FILENAME, "Empty Filename", "Empty Filename string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FILENAME_TOO_LONG, "Filename Too Long", "Filename Too Long string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIZE_TOO_LARGE, "Size Too Large", "Size Too Large string");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_WRONG_USERNAME, "Wrong Username", "String for Wrong User name");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_OVERWRITE_WARNING, "Overwrite Unsaved Mail", "Overwrite Unsaved Mail Confirm String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIG_EMPTY_WARNING, "Empty Signature", "Empty Signature String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_AUTH_NOT_SUPPORT, "Authentication Not Support", "Authentication Not Support String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MSG_MARKED_FULL, "Mark max number reached", "Mark max number reached string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DRM_FILE_IGNORE_ID, "Delete DRM files", "Delete DRM files");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIG_ADD_FAIL_ID, "Fail to insert signature", "Fail to insert signature");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_IN_CALL_ID, "Can not edit Email now", "Can not edit Email now");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EMPTY_FILE_ID, "Empty file", "Empty file");
    /* send result */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SEND_SUCCESS_SAVE_SUCCESS_ID, "Send success, Save success", "Email Send success - Save success String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SEND_SUCCESS_SAVE_FAILED_ID, "Send success, Save failed", "Email Send success - Save failed String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SEND_FAILED_SAVE_SUCCESS_ID, "Send failed, Save success", "Email Send failed - Save success String");
    /* folder */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FOLDER_READ_ID, "Read", "Email Read String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FOLDER_NEXT_PAGE_ID, "Next Page", "Email Next Page String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FOLDER_PREVIOUS_PAGE_ID, "Previous Page", "Email Previous Page String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FOLDER_JUMP_TO_PAGE_ID, "Page", "Email Jump To Page String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FOLDER_PAGE_NUMBER_ID, "No", "Email Page Number String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FOLDER_INVALID_PAGE_NUMBER_ID, "Invalid Page Number!", "Email Page Number String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_SEL_MAIL_ID, "Delete selected Email?", "Delete single Email in folder");
    /* main menu */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MAIN_ID, "Email", "Email Email String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SEND_AND_RECEIVE_ID, "Send and Receive", "Email Send and Receive String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_WRITE_EMAIL_ID, "Write Email", "Email Write Email String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_INBOX_ID, "Inbox", "Email Inbox String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SENT_ID, "Sent", "Email Sent String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_UNSENT_ID, "Unsent", "Email Unsent String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DRAFT_ID, "Draft", "Email Draft String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DELETE_ALL_FOLDER_ID, "Delete All mailboxes", "Delete All Folder String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DELETE_ALL_MARK_ID, "Delete All Mark", "Delete All Mark String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_ID, "Template", "Template string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EMAIL_ACCTS_ID, "Email Accounts", "Email Email Accounts String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SWITCH_MODE_ID, "Switch Mode", "Switch Mode String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_REFRESH_ID, "Refresh", "Email Refresh String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MODE_HINT_ONLINE_ID, "OnLine", "OnLine String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MODE_HINT_OFFLINE_ID, "OffLine", "OffLine String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_FOLDER_MAILS_ID, "Delete all of selected mailbox?", "Delete all of selected box string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_ALL_FOLDER_MAILS_ID, "Delete all of all mailboxes?", "Delete all of selected box string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_FOLDER_MARK_MAILS_ID, "Delete all marked of selected mailbox?", "Delete all marked of selected box string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_ALL_FOLDER_MARK_MAILS_ID, "Delete all marked of all mailboxes?", "Delete all of selected box string");
    /* batch download and report*/
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CONNECTING_ID, "Connecting", "Email Connecting String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CONNECTING_TO_OUTGOING_SERVER_ID, "SMTP", "Email Connecting To Outgoing Server String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CANCELED_ID, "Canceled", "Email Canceled String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SENDING_ID, "Sending", "Email Sending String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CONNECTING_TO_INCOMING_SERVER_POP3_ID, "POP3", "Email Connecting To Incoming Server String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CONNECTING_TO_INCOMING_SERVER_IMAP4_ID, "IMAP4", "Email Connecting To Incoming Server String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_AUTHORIZING_ID, "Authorizing", "Email Authorizing String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_VERIFYING_USERNAME_ID, "Username/", "Email Verifying Username String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_VERIFYING_PASSOWRD_ID, "Password", "Email Verifying Password String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_RECEIVING_ID, "Receiving", "Email Received String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_RECEIVED_ID, "Received", "Email Received String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MAILS_ID, "mails", "Email Mails String");
    /* compose mail */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TO_ID, "To", "Email to String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CC_ID, "CC", "Email cc String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_BCC_ID, "BCC", "Email bcc String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ATTACHMENT_ID, "Attachment", "Email Attachment String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PRIORITY_ID, "Priority", "Email Priority String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SUBJECT_ID, "Subject", "Email Subject String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CONTENT_ID, "Content", "Email Content String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PRIORITY_LOW_ID, "Low", "Email Low String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PRIORITY_MEDIUM_ID, "Normal", "Email Menidum String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PRIORITY_HIGH_ID, "High", "Email High String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EMAIL_OPTION_ID, "E-Mail Option", "Email E-Mail Option String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_INPUT_ADDRESS_ID, "Input Address", "Email Input Address String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ATTACHMENT_LIST_ID, "Attachment List", "Email Attachment List String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_VIEW_PLAY_ID, "View/Play", "Email View-play String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ADD_ATTACHMENT_ID, "Add Attachment", "Email Add Attachment String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_COMPOSE_SIZE_SEND_ID, "Mail size is", "Mail size is");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_REPLY_IND_ID, "Re:", "Re:");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FWD_IND_ID, "Fw:", "Fw:");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_COMP_ADDR_ID, "Delete selected address?", "Delete single address for compose mail");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_ALL_COMP_ADDR_ID, "Delete all addresses?", "Delete all addresses for compose mail");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_COMP_ATT_ID, "Delete selected attachment?", "Delete single attachment for compose mail");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_QUIT_COMP_ID, "Clear this edited Email?", "Quit compose mail without saving");
    /* read mail */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FROM_ID, "From", "Email From String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ADDRESS_LIST_ID, "Address List", "Email Address List String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SAVE_TO_PHONEBOOK_ID, "Save to Phonebook", "Email Search to Phonebook String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SEND_MAIL_ID, "Send Email", "Email Send Email String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SAVE_AS_ID, "Save As", "Email Save As String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FILENAME_ID, "Filename", "Email Filename String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_REPLY_ID, "Reply", "Email Reply String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_REPLY_WITHOUT_CONTENT_ID, "Reply Without Content", "Email Reply Without Content String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_REPLY_ALL_ID, "Reply All", "Email Reply All String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_REPLY_ALL_WITHOUT_CONTENT_ID, "Reply All Without Content", "Email Reply All Without Content String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_FORWARD_ID, "Forward", "Email Forward String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EXTRACT_ID, "Extract Address", "Email Extract Address String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EXTRACT_PHONENUMBER_ID, "Phone Number", "Email Extract phone number String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EXTRACT_EMAILADDR_ID, "Email Address", "Email Extract email address String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EXTRACT_WEBADDR_ID, "URL Address", "Email Extract URL address String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PHONENUMBER_ADDRESS_LIST_ID, "Number List", "Phone number List String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PHONENUMBER_CALL_ID, "Dial", "Call String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_URL_ADDRESS_LIST_ID, "URL List", "URL Address List String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_URL_WAP_ID, "Connect", "Wap browse String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_URL_ADD_BOOKMARK_ID, "Add To Bookmark", "Add to bookmark String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_RETRIEVE_OPTION_ID, "Retrieve Option", "Retrieve Option");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_ID, "Download All", "Download All");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_SINGLE_ID, "Download", "Download");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_TEXT1_ID, "Text 1", "Text 1");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_TEXT2_ID, "Text 2", "Text 2");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_ATT1_ID, "Attachment 1", "Attachment 1");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_ATT2_ID, "Attachment 2", "Attachment 2");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_ATT3_ID, "Attachment 3", "Attachment 3");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MARK_UNREAD_ID, "Mark as Unread", "Mark as Unread");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MARK_DELETED_ID, "Mark as Deleted", "Mark as Deleted");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_UNMARK_DELETED_ID, "Unmark as Deleted", "Unmark as Deleted");
    /* profile */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ACCT_ID, "Account", "Email Account String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ACCT_OPTIONS_ID, "Account Options", "Email Account Options String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ACCT_SETTING_ID, "Account Setting", "Email Account Setting String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PROFILE_ACTIVATED, "Activated", "String for Selected Profile Activated");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PROFILE_NAME_1, "Account 1", "String for Default Profile Name");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PROFILE_NAME_2, "Account 2", "String for Default Profile Name");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PROFILE_NAME_3, "Account 3", "String for Default Profile Name");
    /* profile error */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PORT_NUMBER_OUTOF_RANGE, "Port Number out of range", "String for Port Number Out of Range Warning");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PORT_NUMBER_EMPTY, "Empty Port Number", "String for Port Number is empty");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EMAIL_ADDRESS_EMPTY, "Email Address Empty", "String for Empty Email Address Warning.");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_SIZE_EMPTY_ID, "Empty Download Size", "String for Warning of Empty Download Size Number.");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_WRONG_SETTINGS, "Wrong Setting", "String for Wrong Setting");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIG_IMG_ERR_ID, "Image error", "Image error");
    /* profile setting */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ACCT_NAME_ID, "Account Name", "Email Account Name String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DATA_ACCOUNT_ID, "Data Account", "Email Data Account String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PROTOCOL_ID, "Protocol", "Email Protocol String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_POP3_ID, "POP3", "Email POP3 String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_IMAP4_ID, "IMAP4", "Email IMAP4 String");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_CHECK_INTERVAL_ID, "Check Interval", "Email Check Interval String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_5_MIN_ID, "5 min", "Email 5 min String");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_30_MIN_ID, "30 min", "Email 30 min String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_1_HOUR_ID, "1 hour", "Email 1 hour String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_2_HOURS_ID, "2 hours", "Email 2 hours String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_MAX_SIZE, "Max size", "String for Max Size Field.");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_REPLY_TO_ID, "Reply To Address", "Email Reply-To address String");
    /* outgoing server */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SMTP_SETTING_ID, "SMTP Setting", "Email SMTP Setting String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_OUTGOING_SERVER_ID, "Outgoing Server", "Email Outgoing Server String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_OUTGOING_PORT_ID, "Outgoing Port", "Email Outgoing Port String");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DISPLAY_NAME_ID, "Display Name", "Email Display Name String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EMAIL_ADDRESS_ID, "E-Mail Address", "Email E-Mail Address String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_AUTH_ID, "Authentication", "Email Authentication String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_AUTH_SAME_ID, "Use POP3/IMAP", "Email Same with Incoming Server String");
    /* incoming server */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_POP3_IMAP4_SETTING_ID, "POP3/IMAP4 Setting", "Email POP3/IMAP4 Setting String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_INCOMING_SERVER_ID, "Incoming Server", "Email Incoming Server String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_INCOMING_PORT_ID, "Incoming Port", "Email Incoming Port String");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_USER_NAME_ID, "User Name", "Email User Name String");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_PASSWORD_ID, "Password", "Email Password String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SERVER_COPY_ID, "Copy on Server", "Email Server Copy String");   
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_AFTER_N_DAYS_ID, "Delete After N Days", "Email delete server mails after n days String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_N_OF_DAYS, "N of Days", "Email N of days String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DEL_SERVER_MAILS_ID, "Del Server Mail", "Email delete server mails String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SENT_FOLDER_NAME, "Sent Folder", "Sent Folder Name Caption");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DRAFT_FOLDER_NAME, "Draft Folder", "Draft Folder Name Caption");    
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_OPTION_ID, "Download Option", "Download Option");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DOWNLOAD_ALL, "Download All", "Download All");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_HEADER_ONLY, "Header Only", "Header Only");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_HEADER_TEXT, "Header & Text", "Header & Text");
    /* signature */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIGNATURE_ID, "Signature", "Email Signature String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIGNATURE_ON_OFF_ID, "Auto Signature", "Email On/Off Signature String");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIGNATURE_IMAGE_ID, "Signature Image", "Email Signature Image String");  
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIGNATURE_TEXT_ID, "Signature Text", "Email Signature Text String"); 
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SIG_ATTACH_OPTION_IMAGES_ID, "Associate Images", "String for Associate Images");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_SELECT_FROM_FILE_ID, "Select from file", "String for Select from file");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_DELETE_REFERENCE_ID, "Delete reference", "String for Delete reference");
    /* miscellanea */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_POP_CMD, "Display Error", "String for Display Error");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_SMTP_CMD, "Invalid Filename", "String for Invalid Filename");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERROR_CODE_IMAP_CMD, "Busy in auto check", "String for Busy in auto check ");
    /* template */
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_OPTION_ID, "Template Option", "Template Option string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_EDIT_TEMPLATE_ID, "Edit Template", "Edit Template string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERASE_ID, "Erase", "Erase Template string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERASE_CONFIRM_ID, "Erase selected template?", "Erase Template string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_NO_SPACE_ID, "No Space", "No space to insert template string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_ERASED_ID, "Erased", "Template erased string");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_1, "Dear friend,", "Email template 1");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_2, "How are you", "Email template 2");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_3, "I am glad to receive your email.", "Email template 3");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_4, "We would be delighted if you could", "Email template 4");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_5, "I would be very pleased to", "Email template 5");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_6, "Thank you!", "Email template 6");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_7, "Best Regards!", "Email template 7");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_8, "I look forward to hearing from you.", "Email template 8");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_9, "Yours sincerely,", "Email template 9");
    ADD_APPLICATION_STRING2 ( STR_EMAIL_TEMPLATE_10, "Yours faithfully,", "Email template 10");

    ADD_APPLICATION_STRING2 (STR_EMAIL_SERVER_EMPTY_ID, "Server empty", "server empty warning string");
    ADD_APPLICATION_STRING2 (STR_EMAIL_USER_NAME_EMPTY_ID, "User name empty", "user name empty warning string");
    ADD_APPLICATION_STRING2 (STR_EMAIL_ACCT_NAME_EMPTY_ID, "Account name empty", "account name empty warning string");

    /* POP3 MENUS */
    // email main menu items (send and receive, write email, inbox, sent, unsent, draft, delete all, profile)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_MAIN, MAIN_MENU_MESSAGES_MENUID,
                            0,
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_MAIN_ID, IMG_EMAIL_MAIN_ID));

#define RES_EMAIL_COMP

    //  email main option menu items (send, save, draft, quit)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_OPT, 0/*have to correct this*/,
                            4,
                            MENU_ID_EMAIL_COMP_SEND,
                            MENU_ID_EMAIL_COMP_SAVE_N_SEND,
                            MENU_ID_EMAIL_COMP_SAVE_TO_DRAFT,
                            MENU_ID_EMAIL_COMP_QUIT_NO_SAVE,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_EMAIL_OPTION_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_SEND, MENU_ID_EMAIL_COMP_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_SEND, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_SAVE_N_SEND, MENU_ID_EMAIL_COMP_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_COMMON_SAVE_AND_SEND_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_SAVE_TO_DRAFT, MENU_ID_EMAIL_COMP_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_COMMON_SAVE_TO_DRAFT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_QUIT_NO_SAVE, MENU_ID_EMAIL_COMP_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_COMMON_QUIT_WITHOUT_SAVING_ID, 0));

    // add addr to "TO" and "CC" list (Add, Edit, Delete, Delete all)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_OPT, 0,
                            4,
                            MENU_ID_EMAIL_COMP_ADDR_ADD,
                            MENU_ID_EMAIL_COMP_ADDR_EDIT,
                            MENU_ID_EMAIL_COMP_ADDR_DEL,
                            MENU_ID_EMAIL_COMP_ADDR_DEL_ALL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_ADD, MENU_ID_EMAIL_COMP_ADDR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_ADD, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_EDIT, MENU_ID_EMAIL_COMP_ADDR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_EDIT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_DEL, MENU_ID_EMAIL_COMP_ADDR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DELETE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_DEL_ALL, MENU_ID_EMAIL_COMP_ADDR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DELETE_ALL, 0));

    // option - subject (done, input method)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_SUBJ_OPT, 0/*e28t? have to correct this*/,
                            2,
                            MENU_ID_EMAIL_COMP_SUBJ_DONE,
                            MENU_ID_EMAIL_COMP_SUBJ_INPUT_METH,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_SUBJ_DONE, MENU_ID_EMAIL_COMP_SUBJ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_SUBJ_INPUT_METH, MENU_ID_EMAIL_COMP_SUBJ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_INPUT_METHOD, 0));

    // option - input address (done, input method)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT_DONE,
                            MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT_INPUT_METH,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT_DONE, MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT_INPUT_METH, MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_INPUT_METHOD, 0));

    // attach option list (EDIT, View/Play, Delete)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ATTCH_OPT, 0,
                            3,
                            MENU_ID_EMAIL_COMP_ATTCH_EDIT,
                            MENU_ID_EMAIL_COMP_ATTCH_VIEW,
                            MENU_ID_EMAIL_COMP_ATTCH_DEL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ATTCH_EDIT, MENU_ID_EMAIL_COMP_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_EDIT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ATTCH_VIEW, MENU_ID_EMAIL_COMP_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_VIEW_PLAY_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_ATTCH_DEL, MENU_ID_EMAIL_COMP_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DELETE, 0));

#define RES_EMAIL_READ

    // address list option (save to phb, send email)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ADDR_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_READ_ADDR_OPT_SEND,
                            MENU_ID_EMAIL_READ_ADDR_OPT_SAVE,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_ADDRESS_LIST_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ADDR_OPT_SAVE, MENU_ID_EMAIL_READ_ADDR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SAVE_TO_PHONEBOOK_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ADDR_OPT_SEND, MENU_ID_EMAIL_READ_ADDR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SEND_MAIL_ID, 0));

    // attach play/save as list (play, save as)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ATTCH_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_READ_ATTCH_OPT_VIEW,
                            MENU_ID_EMAIL_READ_ATTCH_OPT_SAVE,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ATTCH_OPT_VIEW, MENU_ID_EMAIL_READ_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_VIEW_PLAY_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ATTCH_OPT_SAVE, MENU_ID_EMAIL_READ_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SAVE_AS_ID, 0));

    // option - input address (done, input method)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ATTCH_SAVE_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_READ_ATTCH_SAVE_DONE,
                            MENU_ID_EMAIL_READ_ATTCH_SAVE_INPUT_METH,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ATTCH_SAVE_DONE, MENU_ID_EMAIL_READ_ATTCH_SAVE_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_READ_ATTCH_SAVE_INPUT_METH, MENU_ID_EMAIL_READ_ATTCH_SAVE_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_INPUT_METHOD, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_EXTRACT_PHONENUMBER, MENU_ID_EMAIL_INBOX_OPT_EXTRACT,
                            0,  // 0 child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_EXTRACT_PHONENUMBER_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_EXTRACT_EMAILADDR, MENU_ID_EMAIL_INBOX_OPT_EXTRACT,
                            0,  // 0 child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_EXTRACT_EMAILADDR_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_EXTRACT_WEBADDR, MENU_ID_EMAIL_INBOX_OPT_EXTRACT,
                            0,  // 0 child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_EXTRACT_WEBADDR_ID, 0));
    
    /* phonenumber address list option (save to phb, call, send sms, send mms)*/
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT_CALL,
                            MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT_SAVE,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_PHONENUMBER_ADDRESS_LIST_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT_CALL, MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_PHONENUMBER_CALL_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT_SAVE, MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SAVE_TO_PHONEBOOK_ID, 0));
    
    /* EMAIL address list option (save to phb, call, send email)*/
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SEND_EMAIL,
                            MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SAVE,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_ADDRESS_LIST_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SEND_EMAIL, MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SEND_MAIL_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SAVE, MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SAVE_TO_PHONEBOOK_ID, 0));
    
    /* URL address list option (wap, add to bookmark)*/
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_URL_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_CONT_ADDR_URL_OPT_WAP,
                            MENU_ID_EMAIL_CONT_ADDR_URL_OPT_ADD_BOOKMARK,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_URL_ADDRESS_LIST_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_URL_OPT_WAP, MENU_ID_EMAIL_CONT_ADDR_URL_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_URL_WAP_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_CONT_ADDR_URL_OPT_ADD_BOOKMARK, MENU_ID_EMAIL_CONT_ADDR_URL_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_URL_ADD_BOOKMARK_ID, 0));
        
    // folder option for IMAP4 read/next page/previous page/jump to pages 
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_FOLDER_OPT, 0/*have to correct this*/,
                            4,
                            MENU_ID_EMAIL_FOLDER_OPT_READ,
                            MENU_ID_EMAIL_FOLDER_OPT_NEXT_PAGE,
                            MENU_ID_EMAIL_FOLDER_OPT_PREV_PAGE,
                            MENU_ID_EMAIL_FOLDER_OPT_JUMP_PAGE,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_FOLDER_OPT_READ, MENU_ID_EMAIL_FOLDER_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_VIEW, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_FOLDER_OPT_NEXT_PAGE, MENU_ID_EMAIL_FOLDER_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_FOLDER_NEXT_PAGE_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_FOLDER_OPT_PREV_PAGE, MENU_ID_EMAIL_FOLDER_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_FOLDER_PREVIOUS_PAGE_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_FOLDER_OPT_JUMP_PAGE, MENU_ID_EMAIL_FOLDER_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_FOLDER_JUMP_TO_PAGE_ID, 0));

#define RES_EMAIL_INBOX

    // inbox option reply/forward/delete (reply, reply without content, reply all, reply all without content, forward, delete)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_READ_OPT, 0/*have to correct this*/,
                            11,
                            MENU_ID_EMAIL_INBOX_OPT_REPLY,
                            MENU_ID_EMAIL_INBOX_OPT_REPLY_WITHOUT,
                            MENU_ID_EMAIL_INBOX_OPT_REPLY_ALL,
                            MENU_ID_EMAIL_INBOX_OPT_REPLY_ALL_WITHOUT,
                            MENU_ID_EMAIL_INBOX_OPT_FW,
                            MENU_ID_EMAIL_INBOX_OPT_RETRIEVE_OPTION,
                            MENU_ID_EMAIL_INBOX_OPT_MARK_UNREAD,
                            MENU_ID_EMAIL_INBOX_OPT_MARK_DELETED,
                            MENU_ID_EMAIL_INBOX_OPT_UNMARK_DELETED,
                            MENU_ID_EMAIL_INBOX_OPT_EXTRACT,
                            MENU_ID_EMAIL_INBOX_OPT_DEL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_REPLY, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_REPLY_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_REPLY_WITHOUT, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_REPLY_WITHOUT_CONTENT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_REPLY_ALL, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_REPLY_ALL_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_REPLY_ALL_WITHOUT, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_REPLY_ALL_WITHOUT_CONTENT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_FW, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_FORWARD_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_RETRIEVE_OPTION, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_RETRIEVE_OPTION_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_MARK_UNREAD, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_MARK_UNREAD_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_MARK_DELETED, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_MARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_UNMARK_DELETED, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_UNMARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_EXTRACT, MENU_ID_EMAIL_INBOX_READ_OPT,
                            3, // 3 children
                            MENU_ID_EMAIL_EXTRACT_PHONENUMBER,
                            MENU_ID_EMAIL_EXTRACT_EMAILADDR,
                            MENU_ID_EMAIL_EXTRACT_WEBADDR,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_EXTRACT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_INBOX_OPT_DEL, MENU_ID_EMAIL_INBOX_READ_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DELETE, 0));

#define RES_EMAIL_SENT

    // option - sent (forwarded, delete)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SENT_OPT, 0/*have to correct this*/,
                            6,
                            MENU_ID_EMAIL_SENT_OPT_FW,
                            MENU_ID_EMAIL_SENT_OPT_RETRIEVE,
                            MENU_ID_EMAIL_SENT_OPT_MARK_DELETED,
                            MENU_ID_EMAIL_SENT_OPT_UNMARK_DELETED,
                            MENU_ID_EMAIL_SENT_OPT_EXTRACT,
                            MENU_ID_EMAIL_SENT_OPT_DEL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SENT_OPT_FW, MENU_ID_EMAIL_SENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_FORWARD_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SENT_OPT_RETRIEVE, MENU_ID_EMAIL_SENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_RETRIEVE_OPTION_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SENT_OPT_MARK_DELETED, MENU_ID_EMAIL_SENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_MARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SENT_OPT_UNMARK_DELETED, MENU_ID_EMAIL_SENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_UNMARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SENT_OPT_EXTRACT, MENU_ID_EMAIL_SENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_EXTRACT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SENT_OPT_DEL, MENU_ID_EMAIL_SENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DELETE, 0));

#define RES_EMAIL_UNSENT

    // unsent option (send, save and send, edit, save to draft, delete)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT, 0/*have to correct this*/,
                            8,                          
                            MENU_ID_EMAIL_UNSENT_OPT_SEND,
                            MENU_ID_EMAIL_UNSENT_OPT_SAVE_N_SEND,
                            MENU_ID_EMAIL_UNSENT_OPT_EDIT,
                            MENU_ID_EMAIL_UNSENT_OPT_MOVE,
                            MENU_ID_EMAIL_UNSENT_OPT_MARK_DELETED,
                            MENU_ID_EMAIL_UNSENT_OPT_UNMARK_DELETED,
                            MENU_ID_EMAIL_UNSENT_OPT_EXTRACT,
                            MENU_ID_EMAIL_UNSENT_OPT_DEL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_SEND, MENU_ID_EMAIL_UNSENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_SEND, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_SAVE_N_SEND, MENU_ID_EMAIL_UNSENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_COMMON_SAVE_AND_SEND_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_EDIT, MENU_ID_EMAIL_UNSENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_EDIT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_MOVE, MENU_ID_EMAIL_UNSENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_COMMON_MOVE_TO_DRAFT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_MARK_DELETED, MENU_ID_EMAIL_UNSENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_MARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_UNMARK_DELETED, MENU_ID_EMAIL_UNSENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_UNMARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_EXTRACT, MENU_ID_EMAIL_UNSENT_OPT,
                            3, // 3 children
                            MENU_ID_EMAIL_EXTRACT_PHONENUMBER,
                            MENU_ID_EMAIL_EXTRACT_EMAILADDR,
                            MENU_ID_EMAIL_EXTRACT_WEBADDR,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_EXTRACT_ID, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_UNSENT_OPT_DEL, MENU_ID_EMAIL_UNSENT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DELETE, 0));

#define RES_EMAIL_DRAFT

    // draft option (edit, delete)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_DRAFT_OPT, 0/*have to correct this*/,
                            6,
                            MENU_ID_EMAIL_DRAFT_OPT_EDIT,
                            MENU_ID_EMAIL_DRAFT_OPT_RETRIEVE,
                            MENU_ID_EMAIL_DRAFT_OPT_MARK_DELETED,
                            MENU_ID_EMAIL_DRAFT_OPT_UNMARK_DELETED,
                            MENU_ID_EMAIL_DRAFT_OPT_EXTRACT,
                            MENU_ID_EMAIL_DRAFT_OPT_DEL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_DRAFT_OPT_EDIT, MENU_ID_EMAIL_DRAFT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_EDIT, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_DRAFT_OPT_RETRIEVE, MENU_ID_EMAIL_DRAFT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_RETRIEVE_OPTION_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_DRAFT_OPT_MARK_DELETED, MENU_ID_EMAIL_DRAFT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_MARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_DRAFT_OPT_UNMARK_DELETED, MENU_ID_EMAIL_DRAFT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_UNMARK_DELETED_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_DRAFT_OPT_EXTRACT, MENU_ID_EMAIL_DRAFT_OPT,
                            3, // 3 children
                            MENU_ID_EMAIL_EXTRACT_PHONENUMBER,
                            MENU_ID_EMAIL_EXTRACT_EMAILADDR,
                            MENU_ID_EMAIL_EXTRACT_WEBADDR,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_EXTRACT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_DRAFT_OPT_DEL, MENU_ID_EMAIL_DRAFT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DELETE, 0));

#define RES_EMAIL_PROFILE

    // profile option (activate, edit)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_PROF_ACTIVATE,
                            MENU_ID_EMAIL_PROF_EDIT,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_ACCT_OPTIONS_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_ACTIVATE, MENU_ID_EMAIL_PROF_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_ACTIVATE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDIT, MENU_ID_EMAIL_PROF_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_EDIT, 0));

    // profile edit option (profile setting, smtp setting, po3/imap4 setting, signature)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDIT_OPT, 0/*have to correct this*/,
                            4,
                            MENU_ID_EMAIL_PROF_EDIT_OPT_SETTING,
                            MENU_ID_EMAIL_PROF_EDIT_OPT_SMTP,
                            MENU_ID_EMAIL_PROF_EDIT_OPT_POP3_IMAP4,
                            MENU_ID_EMAIL_PROF_EDIT_OPT_SIG,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_ACCT_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDIT_OPT_SETTING, MENU_ID_EMAIL_PROF_EDIT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_ACCT_SETTING_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDIT_OPT_SMTP, MENU_ID_EMAIL_PROF_EDIT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SMTP_SETTING_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDIT_OPT_POP3_IMAP4, MENU_ID_EMAIL_PROF_EDIT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_POP3_IMAP4_SETTING_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDIT_OPT_SIG, MENU_ID_EMAIL_PROF_EDIT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SIGNATURE_ID, 0));

    // option - profiles (done, input method)
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDITOR_OPT, 0/*have to correct this*/,
                            2,
                            MENU_ID_EMAIL_PROF_EDITOR_OPT_DONE,
                            MENU_ID_EMAIL_PROF_EDITOR_OPT_INPUT_METH,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDITOR_OPT_DONE, MENU_ID_EMAIL_PROF_EDITOR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_EDITOR_OPT_INPUT_METH, MENU_ID_EMAIL_PROF_EDITOR_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_INPUT_METHOD, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SIG_ATTCH_OPT, 0,
                            3,
                            MENU_ID_EMAIL_SIG_ATTCH_OPT_VIEW,
                            MENU_ID_EMAIL_SIG_ATTCH_OPT_SEL,
                            MENU_ID_EMAIL_SIG_ATTCH_OPT_DEL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_EMAIL_SIG_ATTACH_OPTION_IMAGES_ID, IMG_EMAIL_MAIN_ID));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SIG_ATTCH_OPT_VIEW, MENU_ID_EMAIL_SIG_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_VIEW, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SIG_ATTCH_OPT_SEL, MENU_ID_EMAIL_SIG_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_SELECT_FROM_FILE_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_SIG_ATTCH_OPT_DEL, MENU_ID_EMAIL_SIG_ATTCH_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_DELETE_REFERENCE_ID, 0));

#ifdef __MMI_EMAIL_TEMPLATE__
    /*Template option menu*/
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_TEMPLATE_OPT, 0,
                            3,
                            MENU_ID_EMAIL_TEMPL_EDIT,
                            MENU_ID_EMAIL_TEMPL_ERASE,
                            MENU_ID_EMAIL_TEMPL_WRITE_EMAIL,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_TEMPL_EDIT, MENU_ID_EMAIL_TEMPLATE_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_EDIT, 0));
    
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_TEMPL_ERASE, MENU_ID_EMAIL_TEMPLATE_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_ERASE_ID, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_TEMPL_WRITE_EMAIL, MENU_ID_EMAIL_TEMPLATE_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_EMAIL_WRITE_EMAIL_ID, 0));
    
    /*Edit Template option menu*/
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_EDIT_TEMPL_OPT, 0,
                            2,
                            MENU_ID_EMAIL_EDIT_TEMPL_SAVE,
                            MENU_ID_EMAIL_EDIT_TEMPL_INPUT_METH,                            
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_EDIT_TEMPL_SAVE, MENU_ID_EMAIL_EDIT_TEMPL_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_SAVE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_EDIT_TEMPL_INPUT_METH, MENU_ID_EMAIL_EDIT_TEMPL_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_INPUT_METHOD, 0));
    
    /*option menu when edit email content*/
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_CONT_OPT, 0,
                            3,
                            MENU_ID_EMAIL_COMP_CONT_DONE,
                            MENU_ID_EMAIL_COMP_CONT_INPUT_METH,
                            MENU_ID_EMAIL_COMP_CONT_USE_TEMPLATE,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_CONT_DONE, MENU_ID_EMAIL_COMP_CONT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_CONT_INPUT_METH, MENU_ID_EMAIL_COMP_CONT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_INPUT_METHOD, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_COMP_CONT_USE_TEMPLATE, MENU_ID_EMAIL_COMP_CONT_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_USE_TEMPLATE, 0));
#endif /*__MMI_EMAIL_TEMPLATE__*/

/*Account Settings Reply-to */
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT, 0,
                            3,
                            MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_ADD,
                            MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_DONE,
                            MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_INPUT_METHOD,
                            SHOW, NONMOVEABLE, DISP_LIST,
                            STR_GLOBAL_OPTIONS, 0));
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_ADD, MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_ADD, 0));
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_DONE, MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_DONE, 0));
    ADD_APPLICATION_MENUITEM ((MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_INPUT_METHOD, MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT,
                            0,  // No child
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_INPUT_METHOD, 0));

}
#endif
#endif  //#ifndef _MMI_RES_EMAIL_C
#endif  //#ifndef _MMI_RES_EMAIL_C


