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
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: Res_Messages.c

  	PURPOSE		: Populate Resource for Messages

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-15-2003

**************************************************************/
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MMI_features.h"


#include "MessagesResDef.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

void PopulateCBResData();
void AddCBLanguagesString (void);
void PopulateVoiceMailResData (void);
static void PopulateEMSResourceData (void);
#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__)&&!defined(__MMI_MESSAGES_EMS__))|| defined(__MMI_MYPICTURE__)
void PopulateNSMRes(void);
#endif

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
void PopulateSIMMessageResData (void);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

/**************************************************************

	FUNCTION NAME		: PopulateMessagesResData

  	PURPOSE				: Register all the resources required
	                      by SMS application of Messages

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void PopulateMessagesResData (void)
{
/* Image Resources */

//MENU ICONs
	ADD_APPLICATION_IMAGE2 (IMG_SMS_COMMON_NOIMAGE,
								CUST_IMG_BASE_PATH"\\\\NoImage.bmp",
								"SMS Menu item LSK no Image");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_ENTRY_SCRN_CAPTION,
								CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PNG",
								"SMS Menu item LSK common Image");
	ADD_APPLICATION_IMAGE2 (IMG_CB_RECEIVE_MODE_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_WRITE.PBM",
								"Write RECEIVE MODE menu item Image");
	ADD_APPLICATION_IMAGE2 (IMG_CB_READ_MESSAGE_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_WRITE.PBM",
								"Write READ MESSAGE menu item Image");
	ADD_APPLICATION_IMAGE2 (IMG_CB_LANGUAGES_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_WRITE.PBM",
								"Write LANGUAGES menu item Image");
	ADD_APPLICATION_IMAGE2 (IMG_CB_CHNL_SETTING_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_WRITE.PBM",
								"Write CHNL SETTING menu item Image");
	ADD_APPLICATION_IMAGE2 (IMG_CB_CHNL_TITLE,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\Channel\\\\CH_TITLE.PBM",
								"CB channel title Image");
	ADD_APPLICATION_IMAGE2 (IMG_CB_CHNL_NUMBER,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\Channel\\\\CH_NB.PBM",
								"CB channel number Image");

//MAIN MENU ICONs
	ADD_APPLICATION_IMAGE2 (IMG_SMS_WMESSAGE_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_WRITE.PBM",
								"Write Message SMS menu item Image");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_INBOX_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_INBOX.PBM",
								"Inbox SMS menu item String");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_OUTBOX_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_UTBOX.PBM",
								"Outbox SMS menu item Image");
	#ifdef __MMI_MESSAGES_DRAFT_BOX__
	ADD_APPLICATION_IMAGE2 (IMG_SMS_DRAFTBOX_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_DraftsBox.PBM",
								"Draftbox SMS menu item Image");
	#endif

	#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
	ADD_APPLICATION_IMAGE2 (IMG_SMS_DELETE_MENUENTRY, 	CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_DELETE.PBM",
								"Delete SMS menu item Image");
	#endif

	#if defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_IMAGE2 (IMG_SMS_TEMPLATES_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_TEMP.PBM",
								"Templates Message SMS menu item Image");
	#endif // defined(__MMI_MESSAGES_TEMPLATE__)

	#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
	ADD_APPLICATION_IMAGE2 (IMG_SMS_MEMSTATUS_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_MMORY.PBM",
							 	"Memory Status SMS menu item Image");
	#endif // defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)

	ADD_APPLICATION_IMAGE2 (IMG_SMS_MSG_SETTINGS_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_SET.PBM",
							 	"SMS settings menu item Image");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_VMAIL_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_VOICE.PBM",
							 	"SMS voicemail menu item Image");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_CB_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_BROAD.PBM",
							 	"CB menu item Image");
#ifdef __MMI_MESSAGES_MULTI_APP__
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_SMS_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_sms.pbm",
							 	"SMS menu item Image");

#endif
#ifdef MMS_SUPPORT
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_MMS_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_mms.pbm",
							 	"MMS menu item Image");
#endif
#if defined(__MMI_MESSAGES_CHAT__)
	ADD_APPLICATION_IMAGE2 (IMG_CHAT_MESSAGE_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\Chat\\\\SB_CHAT.PBM",
							 	"CHAT menu item Image");
#endif //MMS_SUPPORT
#if defined(__MMI_MESSAGES_CLUB__)
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_CLUB_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_MC.pbm",
							 	"Message club menu item Image");
#endif

//IDLE SCREEN ICONS
#ifdef __MMI_SLIM_PROGRESS_ANIMATION__
	ADD_APPLICATION_IMAGE2 (IMG_NEW_MESSAGE_NOTIFICATION_MSG,
							CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__,
								"Progress Image");
	ADD_APPLICATION_IMAGE2 (IMG_NEW_VOICEMAIL_NOTIFICATION_MSG,
								CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__,
								"Progress Image");
	ADD_APPLICATION_IMAGE2 (IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE,
							CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__,
								"Progress Image");
#else
	ADD_APPLICATION_IMAGE2 (IMG_NEW_MESSAGE_NOTIFICATION_MSG,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_MAG"__MMI_RES_TYPE_POPUP_SCREEN__,
								"You have New Message SMS Notification Caption Image");
	ADD_APPLICATION_IMAGE2 (IMG_NEW_VOICEMAIL_NOTIFICATION_MSG,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_VOMAL"__MMI_RES_TYPE_POPUP_SCREEN__,
								"You have New Voicemail SMS Notification Caption Image");
	ADD_APPLICATION_IMAGE2 (IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_IdleMSG.GIF",
								"You have New Message SMS Notification Caption Image in idle");
#endif
	ADD_APPLICATION_IMAGE2 (IMG_NEW_SMS_PIC_SUBLCD_MSG,
								CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_SMS.GIF",
								"You have New Voicemail SMS Notification Caption Image");
	ADD_APPLICATION_IMAGE2 (IMG_NEW_VOICEMAIL_PIC_SUBLCD_MSG,
								CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_VOCM.gif",
								"You have New Voicemail SMS Notification Caption Image");

//SEND ICONS
#ifdef __MMI_SLIM_PROGRESS_ANIMATION__
	ADD_APPLICATION_IMAGE2 (IMG_NEW_SMS_SEND,
								CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__,
								"Progress Image");
#else
	ADD_APPLICATION_IMAGE2 (IMG_NEW_SMS_SEND,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Sending\\\\SS_SEND"__MMI_RES_TYPE_POPUP_SCREEN__,
								"SMS Message Send Message String");
#endif
	ADD_APPLICATION_IMAGE2 (IMG_SEND_FAIL_PIC_MSG,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\SentFail\\\\SS_WARN"__MMI_RES_TYPE_POPUP_SCREEN__,
								"You have New Voicemail SMS Notification Caption Image");
	ADD_APPLICATION_IMAGE2 (IMG_SEND_SUCCESS_PIC_MSG,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\SentSuccess\\\\SS_SUCES"__MMI_RES_TYPE_POPUP_SCREEN__,
								"You have New Voicemail SMS Notification Caption Image");

//STATUS ICONS
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_READ,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_READ.PBM",
								"Message Read SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_UNREAD,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_UREAD.PBM",
								"Message UnRead SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_SENT,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_SENT.PBM",
								"Message Sent SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_UNSENT,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_UNSENT.PBM",
								"Message Unsent SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_SS_NSUP,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_NSUP.PBM",
								"Message SS_NSUP SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_SS_NCOMP,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_NCOMP.PBM",
								"Message SS_NCOMP SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_SI_MGE,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_READ.PBM",
								"Message SI_MGE SMS Image");


	ADD_APPLICATION_IMAGE2 (IMG_SMS_PROFILE_NAME,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_PRO.PBM",
								"Profiles name Image");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_PROFILE_SC,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_PHONE.PBM",
								"Profiles service center Image");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_PROFILE_VP,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_TIME.PBM",
								"Profiles validity period Image");
	ADD_APPLICATION_IMAGE2 (IMG_SMS_PROFILE_MSG_TYPE,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_MODE.PBM",
								"Profiles message type Image");
#ifndef __EMS_REL5__
	ADD_APPLICATION_IMAGE2 (IMG_EMS01_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS01.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS02_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS02.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS03_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS03.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS04_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS04.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS05_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS05.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS06_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS06.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS07_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS07.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS08_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS08.BMP",
								"EMS predefined pictures");
#else
	ADD_APPLICATION_IMAGE2 (IMG_EMS01_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS09.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS02_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS10.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS03_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS11.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS04_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS12.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS05_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS13.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS06_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS14.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS07_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS15.BMP",
								"EMS predefined pictures");

	ADD_APPLICATION_IMAGE2 (IMG_EMS08_PIC,
								CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS16.BMP",
								"EMS predefined pictures");
#endif
//	ADD_APPLICATION_STRING2 (STR_SMS_COMMON_VIEW, "View", "Common SMS LSK label for \"View\"");
	ADD_APPLICATION_STRING2 (STR_SMS_COMMON_SEARCH, "Search", "Common SMS LSK label for \"Search\"");
#if defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_1, "Call me now", "Messages template 1");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_2, "How about lunch?", "Messages template 2");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_3, "Be right back", "Messages template 3");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_4, "I am busy now...", "Messages template 4");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_5, "Sorry", "Messages template 5");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_6, "Thank you", "Messages template 6");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_7, "How was the day?", "Messages template 7");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_8, "Long time no see", "Messages template 8");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_9, "Lots of luv", "Messages template 9");
	ADD_APPLICATION_STRING2 (STR_SMS_TEMPLATE_10, "How are you?", "Messages template 10");
#endif //defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_STRING2 (STR_SMS_MESSAGE_HEADER_TO, "To: ", "Prefix of Outbox Message Header \"To\"");
	ADD_APPLICATION_STRING2 (STR_SMS_MESSAGE_HEADER_FROM, "From: ", "Prefix of Inbox Message Header \"From\"");
	ADD_APPLICATION_STRING2 (STR_SMS_COUNT_POPUP_SUFFIX, "msg(s)", "Message count show pop up suffix");

//MAIN MENU
	ADD_APPLICATION_STRING2 (STR_MESSAGE_MAIN_MENU_CAPTION, "Messages", "SMS Main Menu Caption String");
	ADD_APPLICATION_STRING2 (STR_VMAIL_MENUENTRY, "Voice Mail Server", "Voice Mail menu item string");
	ADD_APPLICATION_STRING2 (STR_CB_MENUENTRY,	"Broadcast Message", "Cell Broadcast menu item string");
	ADD_APPLICATION_STRING2 (STR_MESSAGESETUP_MENUENTRY, "Message Settings", "Message setup menu item string");
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
	ADD_APPLICATION_STRING2 (STR_SMS_MEMSTATUS_PREFIX_SIM, "SIM: ", "Memory Status display prefix for SIM");
	ADD_APPLICATION_STRING2 (STR_SMS_MEMSTATUS_PREFIX_PHONE, "PHONE: ", "Memory Status display prefix for PHONE");
#endif  // __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
#if defined(MMS_SUPPORT) || defined(__MMI_MESSAGES_CHAT__) || defined(__MMI_EMAIL__)
	ADD_APPLICATION_STRING2 (STR_SMS_MENUENTRY, "SMS", "SMS menu item String");
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2 (STR_MMS_MENUENTRY, "MMS", "MMS menu item String");
#endif	//__MMI_MMS__
#endif

//MTK Add By Jo for MMS 20030822

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_SEND_MENU_ITEM, "Send", "Message Background send: send");
    ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_CANCELSEND_SMS_ID, "Cancel Send", "Message Background send: Cancel Send");
    ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_MOVETO_DRAFT_ID, "Move to Draft", "Message Background send: Move to Draft");
	ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_NOT_EXIST_ID, "Message does not exist", "Message Background send: Message does not exist");
	ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_STATUS_CHANGED_ID, "Message status changed", "Message Background send: Message status changed");
    ADD_APPLICATION_STRING2 (STR_SMS_SENDING_ID, "Sending", "SMS Sending string");
    ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_DEL_ALL_WITHOUT_SENDING_ID, "Delete All Without Sending Messages?", "Backgroud Send: Delete All Query String");
    ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_SAVE_SENT_MSG_ID, "Save Sent Message", "Save Sent Message Setting");

    ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_SENDING,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_SENDING.PBM",
								"Message Sending SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_WAITING,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_WAITING.PBM",
								"Message waiting SMS Image");
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_FAILTOSENT,
								CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_FAILTOSENT.PBM",
								"Message fail to send SMS Image");
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#ifdef __MMI_MESSAGES_MULTI_APP__
	/* Message main menu */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_MESSAGES_MENUID,
	#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
								MAIN_MENU_PIM_MENU_ID, MMI_MSG_MENU_TOTAL,
	#else
								IDLE_SCREEN_MENU_ID, MMI_MSG_MENU_TOTAL,
	#endif
								#if defined(__MMI_UNIFIED_MESSAGE__)
									MENU_ID_UM_MAIN,
								#else
									MESSAGES_MENU_SMS_MENUID,

									#if defined(MMS_SUPPORT)
										MESSAGES_MENU_MMS_MENUID,
									#endif
								#endif /* __MMI_UNIFIED_MESSAGE__ */

								#if defined(__MMI_MESSAGES_CHAT__)
									MENU_CHATAPP_ID,
								#endif

								#if defined(__MMI_EMAIL__)
									MENU_ID_EMAIL_MAIN,
								#endif

								#if defined(__MMI_IMPS__)
								   MENU_ID_IMPS_MAIN,
								#endif

								#ifndef __MMI_DUAL_SIM_MASTER__
									MESSAGES_MENU_VMAIL_MENUID,
									MESSAGES_MENU_CB_MENUID,
								#else /* __MMI_DUAL_SIM_MASTER__ */
									MENU_MTPNP_DM_VMAIL,
									MENU_MTPNP_DM_CB_MESSAGES,
								#endif /* __MMI_DUAL_SIM_MASTER__ */

									SHOW,	MOVEABLEWITHINPARENT|INSERTABLE,	DISP_LIST,
								#ifdef __MMI_UNIFIED_MESSAGE__
									STR_UM_MAIN_MENU_TITLE_ID,
								#else
									MAIN_MENU_MESSAGES_TEXT,	
								#endif
									MAIN_MENU_MESSAGES_ICON));
	#ifndef __MMI_UNIFIED_MESSAGE__
	/* Message -> SMS menu */
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_SMS_MENUID,
									MAIN_MENU_MESSAGES_MENUID,	NUM_MESSAGES_MAIN_MENU,
									MESSAGES_MENU_INBOX_MENUID,
									MESSAGES_MENU_OUTBOX_MENUID,
								#ifdef __MMI_MESSAGES_DRAFT_BOX__
									MESSAGES_MENU_DRAFTBOX_MENUID,
								#endif
									MESSAGES_MENU_WMESSAGE_MENU_ID,
								#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
									MESSAGES_MENU_DELETE_MENUID,
								#endif
								#if defined(__MMI_MESSAGES_TEMPLATE__)
									MESSAGES_MENU_TEMPLATES_MENUID,
								#endif
					#if defined(__MMI_MYPICTURE__) 
									//MENU_ID_NSM_MY_TONE,	// My Tone reomve : 25-11-2004
									MENU_ID_MY_PICTURE,	/*FOR NSM: New option in Message Menu*/
								#endif
								#ifndef __MMI_DUAL_SIM_MASTER__
									MESSAGES_MENU_MSG_SETTINGS_MENUID,
								#else /*__MMI_DUAL_SIM_MASTER__*/
									MENU_MTPNP_DM_MSG_SETTINGS,
								#endif /*__MMI_DUAL_SIM_MASTER__*/
									SHOW,	MOVEABLEWITHINPARENT|INSERTABLE,	DISP_LIST,
									STR_SMS_MENUENTRY,	IMG_MESSAGE_SMS_MENUENTRY));
	#endif /* __MMI_UNIFIED_MESSAGE__ */
	
#else
	/* Message main menu */
	ADD_APPLICATION_MENUITEM((MAIN_MENU_MESSAGES_MENUID,
	#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
								MAIN_MENU_PIM_MENU_ID, NUM_MESSAGES_MAIN_MENU,
	#else
									IDLE_SCREEN_MENU_ID,	NUM_MESSAGES_MAIN_MENU,
	#endif
									MESSAGES_MENU_WMESSAGE_MENU_ID,
									MESSAGES_MENU_INBOX_MENUID,
									MESSAGES_MENU_OUTBOX_MENUID,
								#ifdef __MMI_MESSAGES_DRAFT_BOX__
									MESSAGES_MENU_DRAFTBOX_MENUID,
								#endif

								#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
									MESSAGES_MENU_DELETE_MENUID,
								#endif
								#if defined(__MMI_MESSAGES_TEMPLATE__)
									MESSAGES_MENU_TEMPLATES_MENUID,
								#endif
								#if defined(__MMI_MYPICTURE__) && defined(__MMI_SMART_MESSAGE_MT__)
									//MENU_ID_NSM_MY_TONE,	// My Tone remove : 25-11-2004
									MENU_ID_MY_PICTURE,	/*FOR NSM: New option in Message Menu*/
								#endif
								#ifndef __MMI_DUAL_SIM_MASTER__
									MESSAGES_MENU_MSG_SETTINGS_MENUID,
								#else /* __MMI_DUAL_SIM_MASTER__ */
									MENU_MTPNP_DM_MSG_SETTINGS,
								#endif /* __MMI_DUAL_SIM_MASTER__ */
									MESSAGES_MENU_VMAIL_MENUID,
									MESSAGES_MENU_CB_MENUID,
									SHOW,	MOVEABLEWITHINPARENT|INSERTABLE,	DISP_LIST,
									MAIN_MENU_MESSAGES_TEXT,	MAIN_MENU_MESSAGES_ICON));
#endif

#if (defined (OBIGO_Q03C) && defined (MMS_SUPPORT))
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_MMS_MENUID,
									MAIN_MENU_MESSAGES_MENUID,	0, //sub menu
									SHOW,	MOVEABLEWITHINPARENT|SHORTCUTABLE,	DISP_LIST,
									STR_MMS_MENUENTRY,	IMG_MESSAGE_MMS_MENUENTRY));
#endif

#ifndef __MMI_UNIFIED_MESSAGE__	

	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_WMESSAGE_MENU_ID,
								#ifdef __MMI_MESSAGES_MULTI_APP__
									MESSAGES_MENU_SMS_MENUID,
								#else
									MAIN_MENU_MESSAGES_MENUID,
								#endif
									0,
									SHOW, 	MOVEABLEWITHINPARENT|SHORTCUTABLE, 	DISP_LIST,
									STR_WMESSAGE_MENUENTRY, 	IMG_SMS_WMESSAGE_MENUENTRY));
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_INBOX_MENUID,
								#ifdef __MMI_MESSAGES_MULTI_APP__
									MESSAGES_MENU_SMS_MENUID,
								#else
									MAIN_MENU_MESSAGES_MENUID,
								#endif
								#ifndef __MMI_DUAL_SIM_MASTER__
									0,
								#else /* __MMI_DUAL_SIM_MASTER__ */
									2,
									MENU_MTPNP_SMS_MASTER_INBOX,
									MENU_MTPNP_SMS_SLAVE_INBOX,
								#endif /* __MMI_DUAL_SIM_MASTER__ */
									SHOW, 	MOVEABLEWITHINPARENT|SHORTCUTABLE, 	DISP_LIST,
									STR_INBOX_MENUENTRY, 	IMG_SMS_INBOX_MENUENTRY));
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_OUTBOX_MENUID,
								#ifdef __MMI_MESSAGES_MULTI_APP__
									MESSAGES_MENU_SMS_MENUID,
								#else
									MAIN_MENU_MESSAGES_MENUID,
								#endif
								#ifndef __MMI_DUAL_SIM_MASTER__
									0,
								#else /* __MMI_DUAL_SIM_MASTER__ */
									2,
									MENU_MTPNP_SMS_MASTER_OUTBOX,
									MENU_MTPNP_SMS_SLAVE_OUTBOX,
								#endif /* __MMI_DUAL_SIM_MASTER__ */
									SHOW, 	MOVEABLEWITHINPARENT|SHORTCUTABLE, 	DISP_LIST ,
									STR_OUTBOX_MENUENTRY, 	IMG_SMS_OUTBOX_MENUENTRY));
#ifdef __MMI_MESSAGES_DRAFT_BOX__
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_DRAFTBOX_MENUID,
								#ifdef __MMI_MESSAGES_MULTI_APP__
									MESSAGES_MENU_SMS_MENUID,
								#else
									MAIN_MENU_MESSAGES_MENUID,
								#endif
									0,
									SHOW, 	MOVEABLEWITHINPARENT|SHORTCUTABLE, 	DISP_LIST ,
									STR_DRAFTBOX_MENUENTRY, 	IMG_SMS_DRAFTBOX_MENUENTRY));
#endif
#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_DELETE_MENUID,
								#ifdef __MMI_MESSAGES_MULTI_APP__
									MESSAGES_MENU_SMS_MENUID,
								#else
									MAIN_MENU_MESSAGES_MENUID,
								#endif
								#ifdef 	__MMI_MESSAGES_DRAFT_BOX__
									4,
								#else
									3,
								#endif
									MESSAGES_MENU_DELETE_INBOX_MENUID,
									MESSAGES_MENU_DELETE_OUTBOX_MENUID,
								#ifdef 	__MMI_MESSAGES_DRAFT_BOX__
									MESSAGES_MENU_DELETE_DRAFTBOX_MENUID,
								#endif
									MESSAGES_MENU_DELETE_ALL_MENUID,
									SHOW, 	MOVEABLEWITHINPARENT, 	DISP_LIST,
									STR_GLOBAL_DELETE,	IMG_SMS_DELETE_MENUENTRY));
#endif //defined(__MMI_MESSAGES_DELETE_ALL_MENU__)

#if defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_TEMPLATES_MENUID,
								#ifdef __MMI_MESSAGES_MULTI_APP__
									MESSAGES_MENU_SMS_MENUID,
								#else
									MAIN_MENU_MESSAGES_MENUID,
								#endif
									0,
									SHOW, 	MOVEABLEWITHINPARENT, 	DISP_LIST,
									STR_TEMPLATES_MENUENTRY, 	IMG_SMS_TEMPLATES_MENUENTRY));
#endif // defined(__MMI_MESSAGES_TEMPLATE__)

	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_MSG_SETTINGS_MENUID,
							#ifndef __MMI_DUAL_SIM_MASTER__
								#ifdef __MMI_MESSAGES_MULTI_APP__
									MESSAGES_MENU_SMS_MENUID,
								#else
									MAIN_MENU_MESSAGES_MENUID,
								#endif
							#else /*__MMI_DUAL_SIM_MASTER__*/
									MENU_MTPNP_DM_MSG_SETTINGS,
							#endif /*__MMI_DUAL_SIM_MASTER__*/
									NUM_MESSAGES_SETUP_MENU,
									SETUP_MENU_PROFILE_SETTING_MENUID,
									SETUP_MENU_COMMONSETTING_MENUID,
								#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
									MESSAGES_MENU_MEMSTATUS_MENUID,
									SETUP_MENU_PREFEREDSTORAGE_MENUID,
								#endif
								#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
									SETUP_MENU_PREFEREDBEARER_MENUID,
								#endif
									SHOW, 	MOVEABLEACROSSPARENT,	DISP_LIST,
								#ifndef __MMI_DUAL_SIM_MASTER__
									STR_MESSAGESETUP_MENUENTRY,
								#else /*__MMI_DUAL_SIM_MASTER__*/
									STRING_MTPNP_SIM1_MESSAGESETUP_MENUENTRY,
								#endif /*__MMI_DUAL_SIM_MASTER__*/
									IMG_SMS_MSG_SETTINGS_MENUENTRY));
#else /* __MMI_UNIFIED_MESSAGE__ */

	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_MSG_SETTINGS_MENUID,
								#ifndef __MMI_DUAL_SIM_MASTER__
									MENU_ID_UM_SETTING,
								#else /*__MMI_DUAL_SIM_MASTER__*/
									MENU_MTPNP_DM_MSG_SETTINGS,
								#endif /*__MMI_DUAL_SIM_MASTER__*/
									NUM_MESSAGES_SETUP_MENU,
									SETUP_MENU_PROFILE_SETTING_MENUID,
									SETUP_MENU_COMMONSETTING_MENUID,
								#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
									MESSAGES_MENU_MEMSTATUS_MENUID,
								#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
									SETUP_MENU_PREFEREDSTORAGE_MENUID,
								#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
								#endif
								#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
									SETUP_MENU_PREFEREDBEARER_MENUID,
								#endif
									SHOW, 	MOVEABLEACROSSPARENT,	DISP_LIST,
								#ifndef __MMI_DUAL_SIM_MASTER__
									STR_UM_SMS_ID, IMG_MESSAGE_SMS_MENUENTRY));
								#else /*__MMI_DUAL_SIM_MASTER__*/
									STRING_MTPNP_SIM1_MESSAGESETUP_MENUENTRY, IMG_SMS_MSG_SETTINGS_MENUENTRY));
								#endif /*__MMI_DUAL_SIM_MASTER__*/

#endif /*__MMI_UNIFIED_MESSAGE__ */

	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_VMAIL_MENUID,
								#ifndef __MMI_DUAL_SIM_MASTER__
									MAIN_MENU_MESSAGES_MENUID, 0,
								#else /* __MMI_DUAL_SIM_MASTER__ */
									MENU_MTPNP_DM_VMAIL, 0,
								#endif /* __MMI_DUAL_SIM_MASTER__ */
									SHOW, MOVEABLEWITHINPARENT|SHORTCUTABLE, DISP_LIST,
								#ifndef __MMI_DUAL_SIM_MASTER__
									STR_VMAIL_MENUENTRY,
								#else /*__MMI_DUAL_SIM_MASTER__*/
									STRING_MTPNP_SIM1_VMAIL_MENUENTRY,
								#endif /*__MMI_DUAL_SIM_MASTER__*/
									IMG_SMS_VMAIL_MENUENTRY));

	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_CB_MENUID,
								#ifndef __MMI_DUAL_SIM_MASTER__
									MAIN_MENU_MESSAGES_MENUID, 4,
								#else /*__MMI_DUAL_SIM_MASTER__*/
									MENU_MTPNP_DM_CB_MESSAGES, 4,
								#endif /*__MMI_DUAL_SIM_MASTER__*/
									MITEM102_CB_SERVICE,
									MITEM102_CB_READ_MESSAGE,
									MITEM102_CB_LANGUAGE,
									MITEM102_CB_CHANNELS,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST ,
								#ifndef __MMI_DUAL_SIM_MASTER__
									STR_CB_MENUENTRY, 
								#else /*__MMI_DUAL_SIM_MASTER__*/
									STRING_MTPNP_SIM1_CB_MENUENTRY,
								#endif /*__MMI_DUAL_SIM_MASTER__*/
									IMG_SMS_CB_MENUENTRY));

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_DONE,
									EMS_ED_OPTIONS_MENU_ID, NUM_MESSAGES_INBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
								#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
									SEND_OPT_SAVE_AND_SEND_MENUID,
								#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
									SEND_OPT_SAVE_MENUID,
								#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
								#endif
								#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
								#endif
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DONE, IMG_SMS_COMMON_NOIMAGE));
#else /* __MMI_DUAL_SIM_MASTER__ */
	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_DONE,
									EMS_ED_OPTIONS_MENU_ID, NUM_MESSAGES_INBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									SEND_OPT_SAVE_AND_SEND_MENUID,
									SEND_OPT_SAVE_MENUID,
								#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
								#endif
								#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
								#endif
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STRING_MTPNP_SMS_MASTER_DONE, IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_DUAL_SIM_MASTER__ */

//MTK Joy added for send by name, 0212
#ifdef __MMI_SEND_BY_SEARCH_NAME__
	ADD_APPLICATION_MENUITEM( (SEND_OPT_SEND_ONLY_MENUID, EMS_ED_OPT_DONE,
							2,
							SEND_OPT_SEND_BY_NUMBER,
							SEND_OPT_SEND_BY_NAME,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_SEND_ONLY_MENU_ITEM, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM( (SEND_OPT_SEND_BY_NUMBER, SEND_OPT_SEND_ONLY_MENUID,
							0,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_ENTER_NUMBER_TO_MANY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM( (SEND_OPT_SEND_BY_NAME, SEND_OPT_SEND_ONLY_MENUID,
							0,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_SEARCH_PHB_TO_MANY, IMG_SMS_COMMON_NOIMAGE));
#else
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_ONLY_MENUID, EMS_ED_OPT_DONE,
								0,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            #ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
								STR_SEND_ONLY_MENU_ITEM, 
							#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
                                STR_SMS_BACKGROUND_SEND_MENU_ITEM,
                            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
								IMG_SMS_COMMON_NOIMAGE));
#endif
//MTK end
#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	ADD_APPLICATION_MENUITEM((SEND_OPT_SAVE_AND_SEND_MENUID,
									EMS_ED_OPT_DONE,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SAVE_AND_SEND_MENU_ITEM, IMG_SMS_COMMON_NOIMAGE));
#endif  /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

	ADD_APPLICATION_MENUITEM((SEND_OPT_SAVE_MENUID,
									EMS_ED_OPT_DONE,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_SAVE, IMG_SMS_COMMON_NOIMAGE));
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_MENUID,
									EMS_ED_OPT_DONE,	2,
									SEND_OPT_SEND_TO_MANY_BY_LIST,
									SEND_OPT_SEND_TO_MANY_NOW,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SENDTOMANY_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST,
									SEND_OPT_SEND_TO_MANY_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SENDTOMANY_LIST, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_NOW,
									SEND_OPT_SEND_TO_MANY_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SENDTOMANY_NOW, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION,
									0,	2,
									SEND_OPT_SEND_TO_MANY_BY_LIST_EDIT,
									SEND_OPT_SEND_TO_MANY_BY_LIST_ERASE,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST_EDIT,
									SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_EDIT, IMG_GLOBAL_OK));
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST_ERASE,
									SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_VM_2_ERASE_ID, IMG_GLOBAL_OK));
#endif // defined(__MMI_MESSAGES_SEND_TO_MANY__)
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
	ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_BY_GROUP_MENUID,
									EMS_ED_OPT_DONE,	0,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_SENDBYGROUP_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif // defined(__MMI_MESSAGES_SEND_BY_GROUP__)

#ifdef __MMI_UNIFIED_MESSAGE__
	ADD_APPLICATION_MENUITEM2((SMS_INBOX_OPTIONS_MENUID,
									0,
								#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
									SMS_INBOX_OPT_VIEW_MENUID,
								#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
						 			SMS_INBOX_OPT_REPLY_MENUID,
						 			SMS_INBOX_OPT_FORWARD_MENUID,
						 			SMS_INBOX_OPT_EDIT_MENUID,
									SMS_INBOX_OPT_DELETE_MENUID,
								#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
									SMS_INBOX_OPT_DELETE_ALL_MENUID,
								#endif
								#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
									SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID,  
								#endif						
								#if defined(__MMI_MESSAGES_EMS__) && !defined(__SLIM_EMS__)
									SMS_INBOX_OPT_SAVE_OBJECT_MENUID,
								#endif /* defined(__MMI_MESSAGES_EMS__) && !defined(__SLIM_EMS__) */
									SMS_INBOX_OPT_USE_NUMBER_MENUID,
								#if defined(__MMI_MESSAGES_USE_URL__)
									MENU_ID_SMS_INBOX_OPT_USE_URL,
								#endif /* __MMI_MESSAGES_USE_URL__ */							
								#ifdef __MMI_EMAIL__
									MENU_ID_SMS_INBOX_OPT_USE_EMAIL_ADDRESS,
								#endif /* __MMI_EMAIL__ */						
								#ifdef __MMI_MESSAGES_CHAT__
									SMS_INBOX_OPT_CHAT_MENUID,
								#endif

								#ifdef __MMI_MESSAGES_COPY__
                                #ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
									SMS_INBOX_OPT_ADVANCED_MENUID,
								#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
							    #endif
								    MENU_ITEM_END,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) && defined (__MMI_MESSAGES_COPY__)								
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_ADVANCED_MENUID,
									0, NUM_MESSAGES_ADVANCED_OPTION_MENU,
						 			SMS_INBOX_OPT_COPY_MENUID,
									SMS_INBOX_OPT_MOVE_MENUID,
									SMS_INBOX_OPT_COPY_ALL_MENUID,
									SMS_INBOX_OPT_MOVE_ALL_MENUID,
								
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_MESSAGES_ADVANCED, IMG_SMS_COMMON_NOIMAGE));
#endif /* !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) && defined (__MMI_MESSAGES_COPY__) */
    
    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__

    	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_VIEW_MENUID,
    									SMS_INBOX_OPTIONS_MENUID,	0,
    									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    									STR_GLOBAL_VIEW, IMG_SMS_COMMON_NOIMAGE));                                
    #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#else /* __MMI_UNIFIED_MESSAGE__ */
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPTIONS_MENUID,
									0, NUM_MESSAGES_INBOXOP_MENU,
						 			SMS_INBOX_OPT_REPLY_MENUID,
									SMS_INBOX_OPT_DELETE_MENUID,
						 			SMS_INBOX_OPT_EDIT_MENUID,
									SMS_INBOX_OPT_FORWARD_MENUID,
								#ifdef __MMI_MESSAGES_COPY__
									SMS_INBOX_OPT_COPY_MENUID,
									SMS_INBOX_OPT_MOVE_MENUID,
								#endif
								#ifdef __MMI_MESSAGES_CHAT__
									SMS_INBOX_OPT_CHAT_MENUID,
								#endif
								#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
									SMS_INBOX_OPT_DELETE_ALL_MENUID,
								#endif
								#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
									SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID,  
								#endif
								#ifdef __MMI_MESSAGES_COPY__
									SMS_INBOX_OPT_COPY_ALL_MENUID,
									SMS_INBOX_OPT_MOVE_ALL_MENUID,
								#endif
									SMS_INBOX_OPT_USE_NUMBER_MENUID,
                                                                #if defined(__MMI_MESSAGES_USE_URL__)
									MENU_ID_SMS_INBOX_OPT_USE_URL,
								#endif /* __MMI_MESSAGES_USE_URL__ */							
								#ifdef __MMI_EMAIL__
									MENU_ID_SMS_INBOX_OPT_USE_EMAIL_ADDRESS,
								#endif /* __MMI_EMAIL__ */						
								#if defined(__MMI_MESSAGES_EMS__) && !defined(__SLIM_EMS__)
									SMS_INBOX_OPT_SAVE_OBJECT_MENUID,
								#endif /* defined(__MMI_MESSAGES_EMS__) && !defined(__SLIM_EMS__) */
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_UNIFIED_MESSAGE__ */
	
	// status report - options
#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
	ADD_APPLICATION_MENUITEM2((SMS_INBOX_SR_OPTIONS_MENUID,
									0,
								#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                                    SMS_SR_OPT_VIEW_MENUID,
                                #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
						 			SMS_INBOX_OPT_DELETE_MENUID,
						 			MENU_ITEM_END,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM2((SMS_OUTBOX_DEFAULT_OPTIONS_MENUID,
									0,
								#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                                    SMS_DEFAULT_OPT_VIEW_MENUID,
                                #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
						 			SMS_OUTBOX_OPT_DELETE_MENUID,
						 			MENU_ITEM_END,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
#else
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_DELETE_ALL_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DELETE_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM2((SMS_INBOX_SR_OPTIONS_MENUID,
									0,
								#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                                    SMS_SR_OPT_VIEW_MENUID,
                                #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
						 			SMS_INBOX_OPT_DELETE_MENUID,
						 			SMS_INBOX_OPT_DELETE_ALL_MENUID,
						 			SMS_INBOX_OPT_USE_NUMBER_MENUID,
						 			MENU_ITEM_END,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_DELETE_ALL_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DELETE_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM2((SMS_OUTBOX_DEFAULT_OPTIONS_MENUID,
									0,
								#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                                    SMS_DEFAULT_OPT_VIEW_MENUID,
                                #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
						 			SMS_OUTBOX_OPT_DELETE_MENUID,
						 			SMS_OUTBOX_OPT_DELETE_ALL_MENUID,
						 			SMS_OUTBOX_OPT_USE_NUMBERS_MENUID,
						 			MENU_ITEM_END,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
#endif
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_MOVE_TO_ARCHIVE_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID,
    									SMS_OUTBOX_OPTIONS_MENUID,	0,
    									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    									STR_MOVE_TO_ARCHIVE_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));   
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__

    ADD_APPLICATION_MENUITEM((SMS_SR_OPT_VIEW_MENUID,
								SMS_INBOX_SR_OPTIONS_MENUID,	0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_GLOBAL_VIEW, IMG_SMS_COMMON_NOIMAGE)); 

    ADD_APPLICATION_MENUITEM((SMS_DEFAULT_OPT_VIEW_MENUID,
                            SMS_OUTBOX_DEFAULT_OPTIONS_MENUID,    0,
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                            STR_GLOBAL_VIEW, IMG_SMS_COMMON_NOIMAGE));

#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __MMI_MESSAGES_CHAT__
#if defined(__MMI_MESSAGES_USE_URL__)
	ADD_APPLICATION_MENUITEM((SMS_CHAT_INVITATION_MENUID, 0, 7,
								SMS_INBOX_OPT_CHAT_MENUID,
								SMS_INBOX_OPT_REPLY_MENUID,
								SMS_INBOX_OPT_EDIT_MENUID,
								SMS_INBOX_OPT_FORWARD_MENUID,
								SMS_INBOX_OPT_DELETE_MENUID,
								SMS_INBOX_OPT_USE_NUMBER_MENUID,
								MENU_ID_SMS_INBOX_OPT_USE_URL,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
#else
	ADD_APPLICATION_MENUITEM((SMS_CHAT_INVITATION_MENUID, 0, 6,
								SMS_INBOX_OPT_CHAT_MENUID,
								SMS_INBOX_OPT_REPLY_MENUID,
								SMS_INBOX_OPT_EDIT_MENUID,
								SMS_INBOX_OPT_FORWARD_MENUID,
								SMS_INBOX_OPT_DELETE_MENUID,
								SMS_INBOX_OPT_USE_NUMBER_MENUID,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
#endif
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_CHAT_MENUID,
									SMS_INBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_CHAT_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_REPLY_MENUID,
									SMS_INBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_REPLY, IMG_SMS_COMMON_NOIMAGE));

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_FORWARD_MENUID,
									SMS_INBOX_OPTIONS_MENUID,	NUM_MESSAGES_INBOX_FORWARD_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
									#endif
									#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
									#endif
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_FORWARD_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_DUAL_SIM_MASTER__ */
									
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_EDIT_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_EDIT, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_DELETE_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DELETE, IMG_SMS_COMMON_NOIMAGE));
#ifdef __MMI_MESSAGES_COPY__

	#ifdef __MMI_UNIFIED_MESSAGE__
    #ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
		ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_COPY_MENUID,
										SMS_INBOX_OPT_ADVANCED_MENUID, 0,
										SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
										STR_SMS_COPY_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));

		ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_COPY_ALL_MENUID,
										SMS_INBOX_OPT_ADVANCED_MENUID, 2,
							 			SMS_INBOX_OPT_COPY_ALL_FROM_SIM_MENUID,
							 			SMS_INBOX_OPT_COPY_ALL_FROM_PHONE_MENUID,
							 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							 			STR_SMS_COPY_ALL_SMS, IMG_SMS_COMMON_NOIMAGE));		
		ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_MOVE_MENUID,
										SMS_INBOX_OPT_ADVANCED_MENUID, 0,
										SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
										STR_SMS_MOVE_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
		ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_MOVE_ALL_MENUID,
										SMS_INBOX_OPT_ADVANCED_MENUID, 2,
							 			SMS_INBOX_OPT_MOVE_ALL_FROM_SIM_MENUID,
							 			SMS_INBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID,
							 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							 			STR_SMS_MOVE_ALL_SMS, IMG_SMS_COMMON_NOIMAGE));
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
	#else
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_COPY_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_COPY_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_COPY_ALL_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 2,
						 			SMS_INBOX_OPT_COPY_ALL_FROM_SIM_MENUID,
						 			SMS_INBOX_OPT_COPY_ALL_FROM_PHONE_MENUID,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_COPY_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_MOVE_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_MOVE_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_MOVE_ALL_MENUID,
									SMS_INBOX_OPTIONS_MENUID, 2,
						 			SMS_INBOX_OPT_MOVE_ALL_FROM_SIM_MENUID,
						 			SMS_INBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_MOVE_ALL, IMG_SMS_COMMON_NOIMAGE));
	#endif
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_COPY_ALL_FROM_SIM_MENUID,
									SMS_INBOX_OPT_COPY_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_COPY_ALL_FROM_PHONE_MENUID,
									SMS_INBOX_OPT_COPY_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_MOVE_ALL_FROM_SIM_MENUID,
									SMS_INBOX_OPT_MOVE_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID,
									SMS_INBOX_OPT_MOVE_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));	
#endif
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_USE_NUMBER_MENUID,
									SMS_INBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_NUMBER_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_USE_NUMBER_OPTIONS_MENUID,
									0,	3,
									SMS_USE_NUM_OPT_DIAL,
									SMS_USE_NUM_OPT_SAVE,
									SMS_USE_NUM_OPT_SEND_SMS,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_NUMBER_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_USE_NUM_OPT_DIAL,
									SMS_USE_NUMBER_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DIAL,	IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_USE_NUM_OPT_SAVE,
									SMS_USE_NUMBER_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_NUMBER_OPT_SAVE,	IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_USE_NUM_OPT_SEND_SMS,
									SMS_USE_NUMBER_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_NUMBER_OPT_SEND_SMS,	IMG_SMS_COMMON_NOIMAGE));
#if defined(__MMI_MESSAGES_USE_URL__)
	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_INBOX_OPT_USE_URL,
									SMS_INBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_URL_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_USE_URL_OPTIONS, 0, NUM_USE_URL_OPTIONS,
								MENU_ID_SMS_USE_URL_CONNECT,
								MENU_ID_SMS_USE_URL_ADD_TO_BOOKMARK,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_URL_OPT_CAPTION,IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_USE_URL_CONNECT,
								MENU_ID_SMS_USE_URL_OPTIONS, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_CONNECT_MENUENTRY,IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_USE_URL_ADD_TO_BOOKMARK,
								MENU_ID_SMS_USE_URL_OPTIONS, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_URL_ADD_TO_BOOKMARK,IMG_SMS_COMMON_NOIMAGE));

#endif /* __MMI_MESSAGES_USE_URL__ */

#ifdef __MMI_EMAIL__
	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_INBOX_OPT_USE_EMAIL_ADDRESS,
									SMS_INBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_EMAIL_ADDRESS_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_USE_EMAIL_ADDRESS_OPTIONS, 0, NUM_USE_EMAIL_ADDR_OPTIONS,
								MENU_ID_SMS_USE_EMAIL_ADDR_OPT_SEND,
								MENU_ID_SMS_USE_EMAIL_ADDR_OPT_SAVE,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_GLOBAL_OPTIONS,IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_USE_EMAIL_ADDR_OPT_SEND,
								MENU_ID_SMS_USE_EMAIL_ADDRESS_OPTIONS, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_GLOBAL_SEND,IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_USE_EMAIL_ADDR_OPT_SAVE,
								MENU_ID_SMS_USE_EMAIL_ADDRESS_OPTIONS, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_USE_NUMBER_OPT_SAVE,IMG_SMS_COMMON_NOIMAGE));
#endif /* __EMAIL__ */

#if defined(__MMI_MESSAGES_EMS__)
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_SAVE_OBJECT_MENUID,
									SMS_INBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SAVE_OBJECT_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif // defined(__MMI_MESSAGES_EMS__)


#ifdef __MMI_UNIFIED_MESSAGE__
	ADD_APPLICATION_MENUITEM2((SMS_OUTBOX_OPTIONS_MENUID,
									0,
    							#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
									SMS_OUTBOX_OPT_VIEW_MENUID,
								#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
									SMS_OUTBOX_OPT_SEND_MENUID,
							    #if defined(__MMI_DUAL_SIM_MASTER__)
                                   	MENU_MTPNP_OUTBOX_OPT_SEND_SMS,
                                #endif /* __MMI_DUAL_SIM_MASTER__ */
									SMS_OUTBOX_OPT_FORWARD_MENUID,
									SMS_OUTBOX_OPT_EDIT_MENUID,
									SMS_OUTBOX_OPT_DELETE_MENUID,
								#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
									SMS_OUTBOX_OPT_DELETE_ALL_MENUID,
								#endif
								#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
									SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID, 
								#endif
									SMS_OUTBOX_OPT_USE_NUMBERS_MENUID,
                                                         #if defined(__MMI_MESSAGES_USE_URL__)
									MENU_ID_SMS_OUTBOX_OPT_USE_URL,
								#endif /* __MMI_MESSAGES_USE_URL__ */							
								#ifdef __MMI_EMAIL__
									MENU_ID_SMS_OUTBOX_OPT_USE_EMAIL_ADDRESS,
								#endif /* __MMI_EMAIL__ */							
								
								#ifdef __MMI_MESSAGES_COPY__
                                #ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
									SMS_OUTBOX_OPT_ADVANCED_MENUID,
								#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
							#endif
                                    MENU_ITEM_END,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
                                
    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    
        ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_VIEW_MENUID,
        									SMS_OUTBOX_OPTIONS_MENUID,	0,
        									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
        									STR_GLOBAL_VIEW, IMG_SMS_COMMON_NOIMAGE)); 
    #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */                                
								
#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) && defined (__MMI_MESSAGES_COPY__)								
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_ADVANCED_MENUID,
									0, NUM_MESSAGES_ADVANCED_OPTION_MENU,
						 			SMS_OUTBOX_OPT_COPY_MENUID,
									SMS_OUTBOX_OPT_MOVE_MENUID,
									SMS_OUTBOX_OPT_COPY_ALL_MENUID,
									SMS_OUTBOX_OPT_MOVE_ALL_MENUID,
								
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_MESSAGES_ADVANCED, IMG_SMS_COMMON_NOIMAGE));
#endif /* !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) && defined (__MMI_MESSAGES_COPY__) */

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_SEND_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	NUM_MESSAGES_OUTBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
									#endif
									#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
									#endif
									SHOW, MOVEABLEWITHINPARENT,	 DISP_LIST,
									STR_GLOBAL_SEND,	IMG_SMS_COMMON_NOIMAGE));	
#else /* __MMI_DUAL_SIM_MASTER__ */
    ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_SEND_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	NUM_MESSAGES_OUTBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
									#endif
									#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
									#endif
									SHOW, MOVEABLEWITHINPARENT,	 DISP_LIST,
									STRING_MTPNP_OUTBOX_MASTER_SEND_SMS,	
									IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_FORWARD_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	NUM_MESSAGES_OUTBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
									#endif
									#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
									#endif
									SHOW, MOVEABLEWITHINPARENT,	 DISP_LIST,
									STR_FORWARD_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	ADD_APPLICATION_MENUITEM2((MENU_ID_SMS_UNSENTBOX_OPTIONS,
									0,
									MENU_ID_SMS_UNSENTBOX_OPT_SEND,
									MENU_ID_SMS_UNSENTBOX_OPT_CANCEL_SEND,
									MENU_ID_SMS_UNSENTBOX_OPT_DELETE,
								#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
									MENU_ID_SMS_UNSENTBOX_OPT_DELETE_ALL,
								#endif /* __MMI_MESSAGES_DELETE_ALL_MENU__ */
                                    MENU_ID_SMS_UNSENTBOX_OPT_MOVE_TO_DRAFT,
                                    MENU_ITEM_END,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
                                                               
    ADD_APPLICATION_MENUITEM((MENU_ID_SMS_UNSENTBOX_OPT_SEND,
    									MENU_ID_SMS_UNSENTBOX_OPTIONS,	0,
    									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    									STR_GLOBAL_SEND, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((MENU_ID_SMS_UNSENTBOX_OPT_CANCEL_SEND,
    									MENU_ID_SMS_UNSENTBOX_OPTIONS,	0,
    									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    									STR_SMS_BACKGROUND_CANCELSEND_SMS_ID,
    									IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((MENU_ID_SMS_UNSENTBOX_OPT_DELETE,
    									MENU_ID_SMS_UNSENTBOX_OPTIONS,	0,
    									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    									STR_GLOBAL_DELETE, IMG_SMS_COMMON_NOIMAGE));
#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
    ADD_APPLICATION_MENUITEM((MENU_ID_SMS_UNSENTBOX_OPT_DELETE_ALL,
    									MENU_ID_SMS_UNSENTBOX_OPTIONS,	0,
    									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    									STR_GLOBAL_DELETE_ALL, IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_MESSAGES_DELETE_ALL_MENU__ */	
   ADD_APPLICATION_MENUITEM((MENU_ID_SMS_UNSENTBOX_OPT_MOVE_TO_DRAFT,
    									MENU_ID_SMS_UNSENTBOX_OPTIONS,	0,
    									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    									STR_SMS_BACKGROUND_MOVETO_DRAFT_ID, IMG_SMS_COMMON_NOIMAGE));
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#else /* __MMI_UNIFIED_MESSAGE__ */

	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPTIONS_MENUID,
									0, NUM_MESSAGES_OUTBOXOP_MENU,
									SMS_OUTBOX_OPT_SEND_MENUID,
								#if defined(__MMI_DUAL_SIM_MASTER__)
                                    MENU_MTPNP_OUTBOX_OPT_SEND_SMS,
                                #endif /* __MMI_DUAL_SIM_MASTER__ */
									SMS_OUTBOX_OPT_EDIT_MENUID,
									SMS_OUTBOX_OPT_DELETE_MENUID,
								#ifdef __MMI_MESSAGES_COPY__
									SMS_OUTBOX_OPT_COPY_MENUID,
									SMS_OUTBOX_OPT_MOVE_MENUID,
								#endif
								#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
									SMS_OUTBOX_OPT_DELETE_ALL_MENUID,
								#endif
								#ifdef __MMI_MESSAGES_COPY__
									SMS_OUTBOX_OPT_COPY_ALL_MENUID,
									SMS_OUTBOX_OPT_MOVE_ALL_MENUID,
								#endif
									SMS_OUTBOX_OPT_USE_NUMBERS_MENUID,
                                                                #if defined(__MMI_MESSAGES_USE_URL__)
									MENU_ID_SMS_OUTBOX_OPT_USE_URL,
								#endif /* __MMI_MESSAGES_USE_URL__ */
								#ifdef __MMI_EMAIL__
									MENU_ID_SMS_OUTBOX_OPT_USE_EMAIL_ADDRESS,
								#endif /* __MMI_EMAIL__ */						
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_SEND_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	NUM_MESSAGES_OUTBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
									#endif
									#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
									#endif
									SHOW, MOVEABLEWITHINPARENT,	 DISP_LIST,
									STR_GLOBAL_SEND,	IMG_SMS_COMMON_NOIMAGE));
#else /* __MMI_DUAL_SIM_MASTER__ */
    ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_SEND_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	NUM_MESSAGES_OUTBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
									SEND_OPT_SEND_TO_MANY_MENUID,
									#endif
									#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
									#endif
									SHOW, MOVEABLEWITHINPARENT,	 DISP_LIST,
									STRING_MTPNP_OUTBOX_MASTER_SEND_SMS,	
									IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_UNIFIED_MESSAGE__ */



	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_EDIT_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_EDIT, IMG_SMS_COMMON_NOIMAGE));
#ifdef __MMI_MESSAGES_COPY__
	#ifdef __MMI_UNIFIED_MESSAGE__
    #ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
		ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_COPY_MENUID,
										SMS_OUTBOX_OPT_ADVANCED_MENUID,	0,
										SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
										STR_SMS_COPY_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
		ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_COPY_ALL_MENUID,
										SMS_OUTBOX_OPT_ADVANCED_MENUID, 2,
							 			SMS_OUTBOX_OPT_COPY_ALL_FROM_SIM_MENUID,
							 			SMS_OUTBOX_OPT_COPY_ALL_FROM_PHONE_MENUID,
							 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							 			STR_SMS_COPY_ALL_SMS, IMG_SMS_COMMON_NOIMAGE));
			
		ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_MOVE_MENUID,
										SMS_OUTBOX_OPT_ADVANCED_MENUID,	0,
										SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
										STR_SMS_MOVE_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
		ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_MOVE_ALL_MENUID,
										SMS_OUTBOX_OPT_ADVANCED_MENUID, 2,
							 			SMS_OUTBOX_OPT_MOVE_ALL_FROM_SIM_MENUID,
							 			SMS_OUTBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID,
							 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							 			STR_SMS_MOVE_ALL_SMS, IMG_SMS_COMMON_NOIMAGE));
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
	#else
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_COPY_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_COPY_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_COPY_ALL_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID, 2,
						 			SMS_OUTBOX_OPT_COPY_ALL_FROM_SIM_MENUID,
						 			SMS_OUTBOX_OPT_COPY_ALL_FROM_PHONE_MENUID,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_COPY_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_MOVE_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_MOVE_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_MOVE_ALL_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID, 2,
						 			SMS_OUTBOX_OPT_MOVE_ALL_FROM_SIM_MENUID,
						 			SMS_OUTBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_MOVE_ALL, IMG_SMS_COMMON_NOIMAGE));
	#endif
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_COPY_ALL_FROM_SIM_MENUID,
									SMS_OUTBOX_OPT_COPY_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_COPY_ALL_FROM_PHONE_MENUID,
									SMS_OUTBOX_OPT_COPY_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_MOVE_ALL_FROM_SIM_MENUID,
									SMS_OUTBOX_OPT_MOVE_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID,
									SMS_OUTBOX_OPT_MOVE_ALL_MENUID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));
#endif
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_DELETE_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DELETE,
									IMG_SMS_COMMON_NOIMAGE));
#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_DELETE_ALL_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DELETE_ALL,	IMG_SMS_COMMON_NOIMAGE));
#endif
	ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_USE_NUMBERS_MENUID,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_OUTBOX_USE_NUMBERS_MENUENTRY,
									IMG_SMS_COMMON_NOIMAGE));
#if defined(__MMI_MESSAGES_USE_URL__)
	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_OUTBOX_OPT_USE_URL,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_URL_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_MESSAGES_USE_URL__ */

#ifdef __MMI_EMAIL__
	ADD_APPLICATION_MENUITEM((MENU_ID_SMS_OUTBOX_OPT_USE_EMAIL_ADDRESS,
									SMS_OUTBOX_OPTIONS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_EMAIL_ADDRESS_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#endif /* __EMAIL__ */

#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_DELETE_INBOX_MENUID,
									MESSAGES_MENU_DELETE_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_DELETE_INBOX_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_DELETE_OUTBOX_MENUID,
									MESSAGES_MENU_DELETE_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_DELETE_OUTBOX_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#ifdef __MMI_MESSAGES_DRAFT_BOX__
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_DELETE_DRAFTBOX_MENUID,
									MESSAGES_MENU_DELETE_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_DELETE_DRAFTBOX_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#endif
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_DELETE_ALL_MENUID,
									MESSAGES_MENU_DELETE_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_DELETE_ALL_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#endif

	ADD_APPLICATION_MENUITEM((SETUP_MENU_PROFILE_SETTING_MENUID,
									MESSAGES_MENU_MSG_SETTINGS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_PROFILE_SETTING_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((SETUP_MENU_COMMONSETTING_MENUID,
									MESSAGES_MENU_MSG_SETTINGS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_COMMONSETTING_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_MEMSTATUS_MENUID,
									MESSAGES_MENU_MSG_SETTINGS_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMSSTATUS_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((SETUP_MENU_PREFEREDSTORAGE_MENUID,
									MESSAGES_MENU_MSG_SETTINGS_MENUID,	2,
									PREFEREDSTORAGE_SIM_MENUID,
									PREFEREDSTORAGE_ME_MENUID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_PREFEREDSTORAGE_MENUENTRY,
									IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((PREFEREDSTORAGE_ME_MENUID,
									SETUP_MENU_PREFEREDSTORAGE_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_ME_STORAGE_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((PREFEREDSTORAGE_SIM_MENUID,
									SETUP_MENU_PREFEREDSTORAGE_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SIM_STORAGE_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
	ADD_APPLICATION_MENUITEM((SETUP_MENU_PREFEREDBEARER_MENUID,
									MESSAGES_MENU_MSG_SETTINGS_MENUID,	3,
									PREFEREDBEARER_PREFER_GPRS_MENUID,
									PREFEREDBEARER_PREFER_GSM_MENUID,
									PREFEREDBEARER_GSM_MENUID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_PREFEREDBEARER_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((PREFEREDBEARER_PREFER_GSM_MENUID,
									SETUP_MENU_PREFEREDBEARER_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_PREFER_GSM_BEARER_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((PREFEREDBEARER_PREFER_GPRS_MENUID,
									SETUP_MENU_PREFEREDBEARER_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_PREFER_GPRS_BEARER_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((PREFEREDBEARER_GSM_MENUID,
									SETUP_MENU_PREFEREDBEARER_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GSM_BEARER_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif

	ADD_APPLICATION_MENUITEM2((SMS_CLSASS0_OPT_MENUID,
									 0,
									SMS_CLSASS0_OPT_USE_NUMBER_MENUID,
								#ifdef __MMI_MESSAGES_USE_URL__
									SMS_CLSASS0_OPT_USE_URL_MENUID,
								#endif
									MENU_ITEM_END,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
									STR_GLOBAL_OPTIONS,IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((SMS_CLSASS0_OPT_USE_NUMBER_MENUID,
									SMS_CLSASS0_OPT_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_NUMBER_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#ifdef __MMI_MESSAGES_USE_URL__
	ADD_APPLICATION_MENUITEM((SMS_CLSASS0_OPT_USE_URL_MENUID,
									SMS_CLSASS0_OPT_MENUID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_URL_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_MESSAGES_USE_URL__ */

#ifdef __MMI_MESSAGES_CLUB__

	ADD_APPLICATION_MENUITEM((MENU_MSG_CLUB_OPTION, 0, 3,
									MENU_MSG_CLUB_SUBSCRIBE,
									MENU_MSG_CLUB_ORDER,
									MENU_MSG_CLUB_EXPLAIN,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_MSG_CLUB_SUBSCRIBE,
									MENU_MSG_CLUB_OPTION,	0,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_MSG_CLUB_SUBSCRIBE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENU_MSG_CLUB_ORDER,
									MENU_MSG_CLUB_OPTION,	0,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_MSG_CLUB_ORDER, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENU_MSG_CLUB_EXPLAIN,
									MENU_MSG_CLUB_OPTION,	0,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_MSG_CLUB_INQUIRE, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB, "Konka Club", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE, "Voice Interaction", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_QUIT, "Cancel", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_MORE, "More SMS", "message club menu 1");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_05, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_06, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_07, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_08, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_09, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_10, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_11, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_12, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_01_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_01_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_01_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_01_04, "Comics", "message club menu 1");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_02_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_02_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_02_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_02_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_02_05, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_03_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_03_02, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_04_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_04_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_04_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_04_04, "Comics", "message club menu 1");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_05_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_05_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_05_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_05_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_05_05, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_05_06, "Friends", "message club menu 3");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_06_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_06_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_06_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_06_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_06_05, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_07_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_07_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_07_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_07_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_07_05, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_08_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_08_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_08_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_08_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_08_05, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_09_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_09_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_09_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_09_04, "Comics", "message club menu 1");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_10_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_10_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_10_03, "Friends", "message club menu 3");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_11_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_11_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_11_03, "Friends", "message club menu 3");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_12_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_12_02, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13_05, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13_06, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_13_07, "Comics", "message club menu 1");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_05, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_06, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_07, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_08, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_14_09, "Friends", "message club menu 3");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_05, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_06, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_07, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_08, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_09, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_10, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_15_11, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_05, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_06, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_07, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_08, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_09, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_10, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_16_11, "Loves", "message club menu 2");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_01, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_02, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_03, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_04, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_05, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_06, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_07, "Comics", "message club menu 1");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_08, "Loves", "message club menu 2");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_09, "Friends", "message club menu 3");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_17_10, "Comics", "message club menu 1");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_01, "V1", "message club menu 4");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_02, "V2", "message club menu 5");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_03, "V3", "message club menu 5");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_01_01, "V1-1", "message club menu 4");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_01_02, "V1-2", "message club menu 5");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_01_03, "V1-3", "message club menu 5");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_01_04, "V1-4", "message club menu 5");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_01_05, "V1-5", "message club menu 5");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_02_01, "V2-1", "message club menu 6");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_02_02, "V2-2", "message club menu 6");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_02_03, "V2-3", "message club menu 6");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_03_01, "V3-1", "message club menu 6");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_03_02, "V3-2", "message club menu 6");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_03_03, "V3-3", "message club menu 6");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_03_04, "V3-4", "message club menu 6");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_VOICE_03_05, "V3-5", "message club menu 6");

	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_SUBSCRIBE, "Subscribe", "message club menu 7");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_ORDER, "Order", "message club menu 8");
	ADD_APPLICATION_STRING2 (STR_MSG_CLUB_INQUIRE, "Inquire", "message club menu 9");

#endif
#if defined(__MMI_MESSAGES_EMS__)
	ADD_APPLICATION_STRING2 (STR_SAVE_OBJECT_MENUENTRY, "Save Objects", "Save Objects SMS menu item String");
#endif //defined(__MMI_MESSAGES_EMS__)
//	ADD_APPLICATION_STRING2 (STR_MESSAGES_DELETE_Q_ID,"Delete", "SMS Report String");
	ADD_APPLICATION_STRING2 (STR_MESSAGES_DELETED_ID,  "Deleted!", "SMS Deleted String");
//	ADD_APPLICATION_STRING2 (STR_MESSAGES_EMPTY_ID,  "Empty", "SMS Empty String");
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
	ADD_APPLICATION_STRING2 (STR_MESSAGES_EMPTY_GROUP_ID,  "Group Empty", "SMS Group Empty String");
#endif // defined(__MMI_MESSAGES_SEND_BY_GROUP__)
//	ADD_APPLICATION_STRING2 (STR_MESSAGES_SPL_EMPTY_ID,  "<Empty>", "SMS Empty String");
	ADD_APPLICATION_STRING2 (STR_MESSAGES_ERACE_Q_ID,"Erase", "SMS Report String");
	ADD_APPLICATION_STRING2 (STR_MESSAGES_ERACED_ID,  "Erased!", "SMS Deleted String");
	ADD_APPLICATION_STRING2 (STR_SR_DELIVERD_ID, "Delivered", "SMS Deliverd String");
	ADD_APPLICATION_STRING2 (STR_SR_PENDING_ID,  "Pending", "SMS Pending String");
	ADD_APPLICATION_STRING2 (STR_INBOX_REPORT_ID,"Report", "SMS Report String");
#if defined(__MMI_MESSAGES_EMS__)
//	ADD_APPLICATION_STRING2 (STR_MESSAGES_VIEW_ID,  "View", "SMS View String");
	ADD_APPLICATION_STRING2 (STR_MESSAGES_SEND_BY_EMS_ID,  "Send By EMS", "SMS View String");
//	ADD_APPLICATION_STRING2 (STR_MESSAGES_DELETE_ID,  "Delete", "SMS Delete String");
#endif // defined(__MMI_MESSAGES_EMS__)
	ADD_APPLICATION_STRING2 (STR_OUTBOX_LIST_MESSAGE,"No Number", "Display str when there is no number in the outbox String");
	ADD_APPLICATION_STRING2 (STR_WMESSAGE_MENUENTRY, "Write Message", "Write Message SMS menu item String");
	ADD_APPLICATION_STRING2 (STR_INBOX_MENUENTRY, "Inbox", "Inbox SMS menu item String");
#if defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_STRING2 (STR_TEMPLATES_MENUENTRY, "Template", "Templates Message SMS menu item String");
#endif // defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_STRING2 (STR_OUTBOX_MENUENTRY, "Outbox", "Outbox SMS menu item String");
#ifdef __MMI_MESSAGES_DRAFT_BOX__
	ADD_APPLICATION_STRING2 (STR_DRAFTBOX_MENUENTRY, "Draftbox", "Outbox SMS menu item String");
#endif
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
	ADD_APPLICATION_STRING2 (STR_SMSSTATUS_MENUENTRY, "Memory Status", "SMS Status SMS menu item String");
	ADD_APPLICATION_STRING2 (STR_SMSSTATUS_TITLE, "SMS Status", "SMS Status SMS menu item String");
#endif // defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
	ADD_APPLICATION_STRING2 (STR_SEND_OPTIONS_CAPTION, "Send Option", "Send Options list Caption");
	//
	ADD_APPLICATION_STRING2 (STR_ENTER_PHONE_NUMBER_CAPTION, "Phone Number", "Prompt for phone number caption");

	// Done (Send option) menu
	ADD_APPLICATION_STRING2 (STR_SEND_ONLY_MENU_ITEM, "Send Only", "Send SMS menu String");
//	ADD_APPLICATION_STRING2 (STR_SAVE_MENU_ITEM, "Save", "Save String");
	ADD_APPLICATION_STRING2 (STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM, "Save to Drafts", "Save To Drafts SMS menu String");

	ADD_APPLICATION_STRING2 (STR_SAVE_AND_SEND_MENU_ITEM, "Save and Send", "Send SMS menu String");
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
	ADD_APPLICATION_STRING2 (STR_SENDTOMANY_MENUENTRY, "Send To Many", "Send To Many SMS menu String");
#endif // defined(__MMI_MESSAGES_SEND_TO_MANY__)

#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
	ADD_APPLICATION_STRING2 (STR_SENDBYGROUP_MENUENTRY, "Send By Group", "Send To Many SMS menu String");
#endif // defined(__MMI_MESSAGES_SEND_BY_GROUP__)

#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
//MTK Joy added for KLM send to many, 1209
#if defined (__MMI_SEND_BY_SEARCH_NAME__)
	ADD_APPLICATION_STRING2 (STR_ENTER_NUMBER_TO_MANY, "Enter Number", "Send To Many by Enter Number");
	ADD_APPLICATION_STRING2 (STR_SEARCH_PHB_TO_MANY, "Search PHB", "Send To Many by Search PHB");
#endif
	ADD_APPLICATION_STRING2 (STR_SENDTOMANY_LIST, "Edit List", "Send To Many by Enter Number");
	ADD_APPLICATION_STRING2 (STR_SENDTOMANY_NOW, "Send Now", "Send To Many by Search PHB");
#endif // defined(__MMI_MESSAGES_SEND_TO_MANY__)

	// Write message options menu entries
//	ADD_APPLICATION_STRING2 (STR_OPT_DONE_MENUENTRY, "Done", "Send To Many SMS menu String");
#if defined(__MMI_MESSAGES_TEMPLATE__)
//	ADD_APPLICATION_STRING2 (STR_OPT_GET_TEMPL_MENUENTRY, "Use Template", "Send To Many SMS menu String");
#endif // defined(__MMI_MESSAGES_TEMPLATE__)

#if defined(__MMI_MESSAGES_EMS__)
	ADD_APPLICATION_STRING2 (STR_OPT_INS_OBJECT_MENUENTRY, "Insert Object",  "Insert Object menu String");
#endif // defined(__MMI_MESSAGES_EMS__)

#if !defined(__MMI_MESSAGES_EMS__)&& defined (__MMI_SMART_MESSAGE_MO__)
	ADD_APPLICATION_STRING2 (STR_OPT_INS_OBJECT_MENUENTRY, "Insert Object",  "Insert Object menu String");
#endif

//	ADD_APPLICATION_STRING2 (STR_OPT_INPUT_METHOD_MENUENTRY, "Input Method",  "Input Method menu String");

//	ADD_APPLICATION_STRING2 (STR_OUTBOX_SEND_MENUENTRY, "Send", "Send menu String");
//	ADD_APPLICATION_STRING2 (STR_OUTBOX_EDIT_MENUENTRY, "Edit", "Edit menu String");
//	ADD_APPLICATION_STRING2 (STR_OUTBOX_DELETE_MENUENTRY, "Delete", "Delete menu String");
//	ADD_APPLICATION_STRING2 (STR_OUTBOX_DELETEALL_MENUENTRY, "Delete All", "Delete All menu String");
	ADD_APPLICATION_STRING2 (STR_OUTBOX_USE_NUMBERS_MENUENTRY, "Use Number", "Use Numbers menu String");
	ADD_APPLICATION_STRING2 (STR_SCR6010_CAPTION,		"Inbox",	"Inbox View SMS Caption String");
	ADD_APPLICATION_STRING2 (STR_SCR6024_CAPTION, "Message Body",		"Message Text View SMS Caption String");
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
	ADD_APPLICATION_STRING2 (STR_MOVE_TO_ARCHIVE_MENUENTRY, "Move To Archive",	"move message to archive");  
	ADD_APPLICATION_STRING2 (STR_MOVE, "Move",	"move confirm"); 
#endif
#ifdef __MMI_MESSAGES_CHAT__
	ADD_APPLICATION_STRING2 (STR_CHAT_MENUENTRY,			  "Chat",		"Inbox Options Menu Chat  SMS String");
#endif
//	ADD_APPLICATION_STRING2 (STR_REPLY_MENUENTRY,			  "Reply",		"Inbox Options Menu Reply  SMS String");
//	ADD_APPLICATION_STRING2 (STR_EDIT_MENUENTRY,			   "Edit",		"Inbox Options Menu Edit SMS String");
	ADD_APPLICATION_STRING2 (STR_FORWARD_MENUENTRY,			"Forward",		"Inbox Options Menu Forward SMS String");
//	ADD_APPLICATION_STRING2 (STR_DELETE_MENUENTRY,		     "Delete",		"Inbox Options Menu Delete SMS String");
//	ADD_APPLICATION_STRING2 (STR_DELETEALL_MENUENTRY,	 "Delete All",		"Inbox Options Menu Delete All SMS String");
#if defined(__MMI_MESSAGES_USE_URL__)
	ADD_APPLICATION_STRING2 (STR_USE_URL_MENUENTRY,			"Use URL",		"SMS option Use URL menu string");
	ADD_APPLICATION_STRING2 (STR_USE_URL_LIST_CAPTION,		"URL List",		"Caption of Use URL menu item");
	ADD_APPLICATION_STRING2 (STR_NOURL_NOTIFICATION,		"No URL",		"Caption of Use URL menu item");
	ADD_APPLICATION_STRING2 (STR_URL_OPT_CAPTION,			"URL Option",	"Caption of Use URL options");
	ADD_APPLICATION_STRING2 (STR_CONNECT_MENUENTRY,			"Connect",		"Use URL option - Connect string");
	ADD_APPLICATION_STRING2 (STR_URL_ADD_TO_BOOKMARK,		"Add to Bookmark",	"Add URL to WAP bookmark string");
	ADD_APPLICATION_STRING2 (STR_CONNECT_FAILED,				"Connection Failed",	"Wap connection failed when in call");
#endif /* __MMI_MESSAGES_USE_URL__ */

#ifdef __MMI_EMAIL__
	ADD_APPLICATION_STRING2 (STR_USE_EMAIL_ADDRESS_MENUENTRY,		"Use Email Address",	"SMS option Use Email Address menu string");
	ADD_APPLICATION_STRING2 (STR_USE_EMAIL_ADDRESS_LIST_CAPTION,	"Email Address List",	"Caption of Use Email Address List");
	ADD_APPLICATION_STRING2 (STR_NO_EMAIL_ADDRESS_NOTIFICATION,		"No Email Address",		"No Email Address Notification");
	ADD_APPLICATION_STRING2 (STR_USE_EMAIL_ADDRESS_OPTION_CAPTION,	"Email Address Option",	"Caption of Use Email Address Option");
#endif /* __EMAIL__ */

	ADD_APPLICATION_STRING2 (STR_USE_NUMBER_MENUENTRY,	 "Use Number",		"Inbox Options Menu Delete All SMS String");
	ADD_APPLICATION_STRING2 (STR_USE_NUMBER_CAPTION,	 "Number List",		"Caption of Use numbers menu");
	ADD_APPLICATION_STRING2 (STR_USE_NUMBER_OPT_CAPTION,	 "Number Option",		"Caption of Use numbers options menu");
//	ADD_APPLICATION_STRING2 (STR_USE_NUMBER_OPT_DIAL,	 "Dial",		"Use numbers options : dial");
	ADD_APPLICATION_STRING2 (STR_USE_NUMBER_OPT_SAVE,	 "Save To Phone Book",		"Use numbers options : Save");
	ADD_APPLICATION_STRING2 (STR_USE_NUMBER_OPT_SEND_SMS,	 "Send SMS",		"Use numbers options : Send SMS");

	ADD_APPLICATION_STRING2 (STR_SCR6026_CAPTION, "Outbox",		"Outbox Message List View SMS Caption String");
	ADD_APPLICATION_STRING2 (STR_SCR6028_CAPTION, "Message Option",		"Outbox Options View SMS Caption String");
	ADD_APPLICATION_STRING2 (STR_INBOX_DELETEALL_QUERY, "Delete All Inbox?" ,"Delete all inbox Message Confirmation");
	ADD_APPLICATION_STRING2 (STR_OUTBOX_DELETEALL_QUERY, "Delete All Outbox?" ,"Delete Message Confirmation SMS Screen String");
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
       ADD_APPLICATION_STRING2 (STR_ARCHIVE_DELETEALL_QUERY, "Delete All Archive?" ,"Delete ALL Archive Msg Confirmation");  
#endif
#ifdef __MMI_MESSAGES_DRAFT_BOX__
	ADD_APPLICATION_STRING2 (STR_DRAFTBOX_DELETEALL_QUERY, "Delete All Draftbox?" ,"Delete Message Confirmation SMS Screen String");
#endif

	ADD_APPLICATION_STRING2 (STR_NONUMBER_NOTIFICATION, "No Number!", "No Number in Message Text Notification String");
	ADD_APPLICATION_STRING2(STR_VM_NO_NUMBER_TO_DIAL,"No Number to Dial!","No Number to Dial");

	ADD_APPLICATION_STRING2 (STR_VOICEMAIL_IND,			"New Voice Mail!",	"New voice Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STR_FAX_IND,			"New Fax!",	"New Fax SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STR_EMAIL_IND,			"New E-Mail!",	"New E-Mail SMS Notification Caption String");

	ADD_APPLICATION_STRING2 (STR_VOICEMAIL_NUM_IND,			"New Voice Mail(s)!",	"Number of new voice Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STR_FAX_NUM_IND,			"New Fax(es)!",	"Number of new Fax SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STR_EMAIL_NUM_IND,			"New E-Mail(s)!",	"Number of new E-Mail SMS Notification Caption String");
		
	ADD_APPLICATION_STRING2 (STR_SCR6035_LSK,			"Read",	"View New Message SMS LSK String");

	ADD_APPLICATION_STRING2 (STR_SUCCESS_CAPTION,		"Success!","Success Message Screen SMS Caption String");
	ADD_APPLICATION_STRING2 (STR_FAILURE_CAPTION,		"Failure!",	"Failure Message Button SMS Caption String");

#ifdef __MMI_MESSAGES_DELETE_ALL_MENU__
	ADD_APPLICATION_STRING2 (STR_DELETE_INBOX_MENUENTRY,	 "Delete Inbox",		"Delete Options Menu Delete Inbox SMS String");
	ADD_APPLICATION_STRING2 (STR_DELETE_OUTBOX_MENUENTRY,	 "Delete Outbox",		"Delete Options Menu Delete Outbox SMS String");
#ifdef __MMI_MESSAGES_DRAFT_BOX__
	ADD_APPLICATION_STRING2 (STR_DELETE_DRAFTBOX_MENUENTRY,	 "Delete Drafts",		"Delete Options Menu Delete Outbox SMS String");
#endif
	ADD_APPLICATION_STRING2 (STR_DELETE_ALL_MENUENTRY,	 "Delete All",		"Delete Options Menu Delete All SMS String");
	ADD_APPLICATION_STRING2 (STR_DELETE_ALL_QUERY,	 "Delete All Messages",		"Delete Query Delete All SMS String");
#endif

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
	ADD_APPLICATION_STRING2 (STR_ME_STORAGE_MENUENTRY,		"Phone", "Message ME Memory Setting SMS String");
	ADD_APPLICATION_STRING2 (STR_SIM_STORAGE_MENUENTRY,		"SIM", "Message SIM Memory Setting SMS String");
	ADD_APPLICATION_STRING2 (STR_PREFEREDSTORAGE_MENUENTRY,	"Preferred Storage",	"Message Setup Preferred Storage SMS  String");
#endif // defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)


//	ADD_APPLICATION_STRING2 (STR_PROFILE_EDIT_MENUENTRY,	    "Edit",	"Message Profile Edit  SMS  String");
	ADD_APPLICATION_STRING2 (STR_PROFILE_SETTING_MENUENTRY,	    "Profile Setting",	"Message Profile Setting  SMS  String");

	ADD_APPLICATION_STRING2 (STR_SET0_MENUENTRY,			           "Profile 1",	"Message Setup Set1 SMS  String");
	ADD_APPLICATION_STRING2 (STR_SET1_MENUENTRY,			           "Profile 2",	"Message Setup Set2 SMS  String");
	ADD_APPLICATION_STRING2 (STR_SET2_MENUENTRY,			           "Profile 3",	"Message Setup Set3 SMS  String");
	ADD_APPLICATION_STRING2 (STR_SET3_MENUENTRY,			           "Profile 4",	"Message Setup Set4 SMS  String");
	ADD_APPLICATION_STRING2 (STR_COMMONSETTING_MENUENTRY,	 "Common Setting",	"Message Setup Common Settings SMS  String");
//MTK Joy added for GPRS support, 1216
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
	ADD_APPLICATION_STRING2 (STR_PREFEREDBEARER_MENUENTRY,	"Bearer Settings",	"Message Setup Preferred Bearer SMS  String");
	ADD_APPLICATION_STRING2 (STR_PREFER_GSM_BEARER_MENUENTRY,	"Prefer GSM",	"Message Setup Preferred Bearer SMS  String");
	ADD_APPLICATION_STRING2 (STR_PREFER_GPRS_BEARER_MENUENTRY,	"Prefer GPRS",	"Message Setup Preferred Bearer SMS  String");
	ADD_APPLICATION_STRING2 (STR_GSM_BEARER_MENUENTRY,	"GSM Only",	"Message Setup Preferred Bearer SMS  String");
#endif
//MTK end
	//ADD_APPLICATION_STRING2 (STR_SCR6037_CAPTION,		"Settings",	"Message Settings SMS Caption String");

	ADD_APPLICATION_STRING2 (STR_1HOUR_MENUENTRY,	     "1 hour",	"Validity Period I hour SMS  String");
	ADD_APPLICATION_STRING2 (STR_6HOUR_MENUENTRY,        "6 hours",  "Validity Period 6 hours SMS  String");
	ADD_APPLICATION_STRING2 (STR_12HOUR_MENUENTRY,		  "12 hours",	"Validity Period 12 hours SMS  String");
	ADD_APPLICATION_STRING2 (STR_24HOUR_MENUENTRY,		  "1 day",	"Validity Period 24 hours SMS  String");
	ADD_APPLICATION_STRING2 (STR_3DAY_MENUENTRY,		  "3 days",	"Validity Period 3 days SMS  String");
	ADD_APPLICATION_STRING2 (STR_1WEEK_MENUENTRY,		   "1 week",	"Validity Period 1 week SMS  String");
	ADD_APPLICATION_STRING2 (STR_63WEEKS_MENUENTRY,		  "Maximum",	"Validity Period 63 weeks SMS  String");

	ADD_APPLICATION_STRING2 (STR_TEXT_MENUENTRY,		  "Text",	"Message Type Text SMS String");
	ADD_APPLICATION_STRING2 (STR_FAX_MENUENTRY,			   "Fax",	"Message Type Fax SMS String");
	ADD_APPLICATION_STRING2 (STR_PAGE_MENUENTRY,	      "Page",	"Message Type Page SMS String");
	ADD_APPLICATION_STRING2 (STR_MT_EMAIL_MENUENTRY,	"E-mail",	"Message Type Email SMS String");
#if defined(__MMI_MESSAGES_EMS__)
	//formatting text
	ADD_APPLICATION_STRING2 (STR_EMS_FORMATING_TEXT_ID, "Format Text", "STR_EMS_FORMATING_TEXT_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_SIZE_ID     , "Text Size", "STR_EMS_TEXT_SIZE_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_STYLE_ID    , "Text Style", "STR_EMS_TEXT_STYLE_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_ALIGNMENT_ID     , "Alignment", "STR_EMS_ALIGNMENT_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_NEW_PARAGRAPH_ID , "New Paragraph", "STR_EMS_NEW_PARAGRAPH_ID");

	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_SIZE_SMALL_ID	, "Small", "STR_EMS_TEXT_STYLE_SMALL_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_SIZE_MEDIUM_ID, "Medium", "STR_EMS_TEXT_SIZE_MEDIUM_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_SIZE_LARGE_ID	, "Large", "STR_EMS_TEXT_SIZE_LARGE_ID");

	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_STYLE_BOLD_ID			, "Bold", "STR_EMS_TEXT_STYLE_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_STYLE_ITALICS_ID		, "Italics", "STR_EMS_TEXT_STYLE_ITALICS_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_STYLE_UNDERLINE_ID	, "Underline", "STR_EMS_TEXT_STYLE_UNDERLINE_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_TEXT_STYLE_STRIKETHROUGH_ID, "Strikethrough", "STR_EMS_TEXT_STYLE_STRIKETHROUGH_ID");

	ADD_APPLICATION_STRING2 (STR_EMS_ALIGNMENT_AUTOMATIC_ID	, "Automatic", "STR_EMS_ALIGNMENT_AUTOMATIC_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_ALIGNMENT_LEFT_ID		, "Left", "STR_EMS_ALIGNMENT_LEFT_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_ALIGNMENT_CENTER_ID	, "Center", "STR_EMS_ALIGNMENT_CENTER_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_ALIGNMENT_RIGHT_ID		, "Right", "STR_EMS_ALIGNMENT_RIGHT_ID");

	ADD_APPLICATION_STRING2 (STR_EMS_NEW_PARAGRAPH_AUTOMATIC_ID	, "Automatic", "STR_EMS_NEW_PARAGRAPH_AUTOMATIC_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_NEW_PARAGRAPH_LEFT_ID		, "Left", "STR_EMS_NEW_PARAGRAPH_LEFT_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_NEW_PARAGRAPH_CENTER_ID	, "Center", "STR_EMS_NEW_PARAGRAPH_CENTER_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_NEW_PARAGRAPH_RIGHT_ID		, "Right", "STR_EMS_NEW_PARAGRAPH_RIGHT_ID");
#endif // defined(__MMI_MESSAGES_EMS__)

/// memory exceeded
	ADD_APPLICATION_STRING2 (STR_SCR6042_CAPTION,		"Notification!",	"Memory Exceeded Note Screen SMS Caption String");
	ADD_APPLICATION_STRING2 (STR_SMS_MEMORY_EXCEEDED,		"Storage Full for New Incoming Message!",	"Memory Exceeded Message SMS String");
	ADD_APPLICATION_STRING2 (STR_SMS_SIM_MEMORY_EXCEEDED,		"SIM Storage Full for New Incoming Message!",	"SIM Memory Exceeded Message SMS String");
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
	ADD_APPLICATION_STRING2 (STR_SMS_ARCHIVE_MEMORY_EXCEEDED,		"Storage Full for SMS Archive Message!",	"Memory Exceeded Message SMS String");
#endif
	ADD_APPLICATION_STRING2 (STR_SMS_CB_CHNL_FULL,		"Channel Full!",	"Channel Full Message SMS String");

	ADD_APPLICATION_STRING2 (STR_DELETING_SMS_CAPTION,		"Deleting ",	"Deleting Process Indicator SMS Screen Caption String");
//	ADD_APPLICATION_STRING2 (STR_SCR6046_RSK,			"Abort",	"Loading Process Indicator SMS Screen RSK String");
	ADD_APPLICATION_STRING2 (STR_SMS_SEND_SUCCESS,	"Sent",	"SMS Delivered Successfully Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_SEND_SUCESS_SAVE_FILED,	"Message Sent but Save Failed",	"SMS Delivered Successfully Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_SEND_FAILED_SAVE_SUCCESS,		"Not Sent, Stored in Outbox",	"SMS Saved Successfully Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_SEND_FAILED,		"Message Send Failed",	"SMS Send failed Message String");

	ADD_APPLICATION_STRING2 (STR_SMS_SEND_SAVE_SUCESS,	"Sent and Stored ",	"SMS Delivered Successfully Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_SEND_SAVE_FAILED,		"Send and Save Failed",	"SMS Saved Successfully Message String");
	ADD_APPLICATION_STRING2 (STR_SC_EMPTY_CAPTION_ID,	"SC Address",	"SMS SC Empty String");

	ADD_APPLICATION_STRING2 (STR_VOICE_MAIL_NAME,			"Name",		"SMS Voice Mail Name String");
	ADD_APPLICATION_STRING2 (STR_VOICE_MAIL_NUM,			"Number",		"SMS Voice Mail Number String");
	ADD_APPLICATION_STRING2 (STR_PROFILE_NAME,			"Profile Name",		"SMS Profile Name String");
	ADD_APPLICATION_STRING2 (STR_PROFILE_SC,			"SC Address",		"SMS Profile Name String");
	ADD_APPLICATION_STRING2 (STR_PROFILE_VP,			"Valid Period",		"SMS Profile Name String");
	ADD_APPLICATION_STRING2 (STR_PROFILE_MSG_TYPE,			"Message Type",		"SMS Profile Name String");

	ADD_APPLICATION_STRING2 (STR_ABORT_SENDING_SMS,	"Stop Sending SMS",	"SMS Sending Abort Message String");

	ADD_APPLICATION_STRING2 (STR_LOADING_SMS,	"Loading",	"SMS while loading sms Message String");
	ADD_APPLICATION_STRING2 (STR_READING_SMS,	"Reading SMS",	"SMS while sending sms Message String");
	ADD_APPLICATION_STRING2 (STR_SENDING_SMS,	"Sending SMS",	"SMS while sending sms Message String");
	ADD_APPLICATION_STRING2 (STR_SAVING_SMS,		"Saving SMS",		"SMS while saving sms Message String");	
	ADD_APPLICATION_STRING2 (STR_SMS_PLEASE_WAIT_ID,		"Please Wait",		"SMS Please Wait String");
    ADD_APPLICATION_STRING2 (STR_SMS_SAVE_SUCESS,		"Saved",		"SMS while saved sms Message String");
    
	ADD_APPLICATION_STRING2 (STR_RECEIVED_SMS,	"New Message!",	"SMS while receiving sms Message String");
	ADD_APPLICATION_STRING2 (STR_NEW_MESSAGE_FROM_ID,	"Message From ", "SMS New Message From String");

	ADD_APPLICATION_STRING2 (STR_LOADING_INBOX_BACK,	"Back",	"SMS back while loading sms Message String");
	ADD_APPLICATION_STRING2 (STR_LOADING_OUTBOX_BACK,	"Back",	"SMS back while loading sms Message String");
	#ifdef __MMI_MESSAGES_DRAFT_BOX__
	ADD_APPLICATION_STRING2 (STR_LOADING_DRAFTBOX_BACK,	"Back",	"SMS back while loading sms Message String");
	#endif
	
	ADD_APPLICATION_STRING2 (STR_SMS_DOES_NOT_SUPPORT,	"Not Support",	"SMS when we receive not supported sms Message String");
	ADD_APPLICATION_STRING2 (STR_READ_SMS_DATA_FAILED,	"Read Failed!",	"SMS when read sms data failed Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_OBJECT_EXISTENCE_ERROR,	"Object Exist!",	"SMS when insert alignment failed due to EMS object exists");


	ADD_APPLICATION_STRING2 (STR_SMS_FAILURE_MEM_CAP_EXCEEDED,		"Memory Capacity Exceeded!",	"SMS Memory Capacity Exceeded Error Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_FAILURE_MEM_FULL,				"Memory Full!",	"SMS Memory Full Error Message String");
	ADD_APPLICATION_STRING2 (STR_MESSAGES_UNKNOWN_ERROR, "Unknown Error!",	"SMS Unknown Error Message String");
//#if defined(__MMI_MESSAGES_EMS__)
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_NUM_EXCEED, "Object Number Exceed",	"SMS Object Number Exceed Message String");
	ADD_APPLICATION_STRING2 (STR_NO_SPACE_TO_INSERT_OBJECT, "Not Enough Space",	"SMS No Space Message String");
//#endif // defined(__MMI_MESSAGES_EMS__)
    ADD_APPLICATION_STRING2 (STR_EMS_EMPTY_FILENAME, "Empty Filename!",	"Empty Filename Message String");

	/* message length exceeds maximum length */
	ADD_APPLICATION_STRING2 (STR_SMS_FAILURE_MSG_LEN_EXCEEDED,		"Message Length Exceeded!",	"SMS Message Limit Exceeded Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_NUM_CANNOT_BE_EMPTY,		"Number Cannot be Empty",	"SMS Number Empty Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_NUM_LEN_EXCEEDED,		"Number Length Exceeded",	"SMS Number Limit Exceeded Message String");
	ADD_APPLICATION_STRING2 (STR_SMS_NAME_CANNOT_BE_EMPTY,		"Name Cannot be Empty",	"SMS Name Empty Message String");

#ifdef __MMI_MESSAGES_COPY__
	/* copy function*/
	ADD_APPLICATION_STRING2 (STR_SMS_COPY_TO_PHONE,		"Copy to Phone",	"SMS copy function Copy to Phone String");
	ADD_APPLICATION_STRING2 (STR_SMS_COPY_TO_SIM,		"Copy to SIM",	"SMS copy function Copy to SIM String");
	ADD_APPLICATION_STRING2 (STR_SMS_COPY_ALL,		"Copy All",	"SMS copy function Copy All String");
	ADD_APPLICATION_STRING2 (STR_SMS_FROM_SIM,		"From SIM",	"SMS copy function From SIM String");
	ADD_APPLICATION_STRING2 (STR_SMS_FROM_PHONE,		"From Phone",	"SMS copy function From Phone String");
	ADD_APPLICATION_STRING2 (STR_SMS_COPYING,		"Copying",	"SMS copy function Copying String");
	ADD_APPLICATION_STRING2 (STR_SMS_MOVE_TO_PHONE,		"Move to Phone",	"SMS move function Move to Phone String");
	ADD_APPLICATION_STRING2 (STR_SMS_MOVE_TO_SIM,		"Move to SIM",	"SMS move function Move to SIM String");
	ADD_APPLICATION_STRING2 (STR_SMS_MOVE_ALL,		"Move All",	"SMS move function Move All String");
	ADD_APPLICATION_STRING2 (STR_SMS_MOVING,		"Moving",	"SMS move function Moving String");
	ADD_APPLICATION_STRING2 (STR_SMS_MESSAGE_COPIED,	"Message Copied",	"SMS move function Message Copied String");
	ADD_APPLICATION_STRING2 (STR_SMS_MESSAGES_COPIED,	"Messages Copied",	"SMS move function Messages Copied String");
	ADD_APPLICATION_STRING2 (STR_SMS_MESSAGE_MOVED,		"Message Moved",	"SMS move function Message Moved String");
	ADD_APPLICATION_STRING2 (STR_SMS_MESSAGES_MOVED,	"Messages Moved",	"SMS move function Messages Moved String");	
#endif
	
	ADD_APPLICATION_STRING2 (STR_SMS_COPY_ALL_SMS,		"Copy All Text Messages",	"SMS copy function Copy All SMS String");
	ADD_APPLICATION_STRING2 (STR_SMS_MOVE_ALL_SMS,		"Move All Text Messages",	"SMS move function Move All SMS String");
	ADD_APPLICATION_STRING2 (STR_SMS_MESSAGES_ADVANCED,	"Advanced",	"SMS Advanced option String");
	ADD_APPLICATION_STRING2 (STR_UNSENTBOX_DELETEALL_QUERY, "Delete All Outbox?" ,"Delete Message Confirmation SMS Screen String");
	ADD_APPLICATION_STRING2 (STR_SENTBOX_DELETEALL_QUERY, "Delete All Sent?" ,"Delete Message Confirmation SMS Screen String");
	ADD_APPLICATION_STRING2 (STR_UNSENTBOX_MENUENTRY, "Outbox", "Outbox SMS menu item String");

	ADD_APPLICATION_STRING2 (STR_SMS_REMOVE_EMS_OBJECT, "Remove EMS Object", "Remove EMS Object String");    
	
#if defined(__MMI_MESSAGES_TEMPLATE__)
		// main template
	ADD_APPLICATION_STRING2 (STR_SCRN_T0_CAPTION, "Template",	"SMS Message Template Caption String");
	// template option
	ADD_APPLICATION_STRING2 (STR_SCRN_T1_OPTIONS_CAPTION, "Template Option",	"SMS Message Template T1 Options Caption String");

	ADD_APPLICATION_STRING2 (STR_TEMPL_OPTIONS_ERASE,			"Erase",	"SMS Message Template Options Erase String");
	ADD_APPLICATION_STRING2 (STR_TEMPL_OPTIONS_WRITE_MESSAGE,			"Write Message",	"SMS Message Template Options Write Message String");
	
//	ADD_APPLICATION_STRING2 (STR_TEMPL_OPTIONS_EDIT,	   "Edit",	"SMS Message Template Options Edit String");

	ADD_APPLICATION_STRING2 (STR_SMS_FAILURE_DATA_EMPTY,	"No Content",	"SMS Empty Content String");
	ADD_APPLICATION_STRING2 (STR_SMS_FAILURE_DATA_INVALID,	"Invalid Content",	"SMS Invalid Content String");
	ADD_APPLICATION_STRING2 (STR_SMS_FAILURE_DATA_EXCEED,	"Content Size Exceeded",	"SMS Exceeded Content String");
	ADD_APPLICATION_STRING2 (STR_SMS_FAILURE_SC_NUM_EMPTY,	"Empty Service Center Number",	"SMS Empty SC number String");

	ADD_APPLICATION_STRING2 (STR_SMS_SIM_REFRESH,	"SIM Refresh",	"SMS SIM Refresh String");

    ADD_APPLICATION_STRING2 (STR_SMS_MOVE_TO_SIM_QUERY_ID,	"Move to SIM?",	"SMS Move to SIM Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_MOVE_TO_PHONE_QUERY_ID,	"Move to phone?",	"SMS Move to phone Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_COPY_TO_SIM_QUERY_ID,	"Copy to SIM?",	"SMS Copy to SIM Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_COPY_TO_PHONE_QUERY_ID,	"Copy to phone?",	"SMS Copy to phone Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_FROM_SIM_QUERY_ID,	"From SIM?",	"SMS SIM Refresh Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_FROM_PHONE_QUERY_ID,	"From phone?",	"SMS SIM Refresh Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID,	"Remove EMS Object?",	"SMS Remove EMS Object Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_BACKGROUND_MOVETO_DRAFT_QUERY_ID,	"Move to Draft?",	"SMS Move to Draft Query String");
	ADD_APPLICATION_STRING2 (STR_MOVE_TO_ARCHIVE_MENUENTRY_QUERY_ID,	"Move To Archive?",	"SMS Move To Archive Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_COPY_ALL_QUERY_ID,	"Copy All to Phone?",	"SMS Copy All to Phone Query String");
	ADD_APPLICATION_STRING2 (STR_SMS_MOVE_ALL_QUERY_ID,	"Move All to Phone?",	"SMS Move All to Phone Query String");
	ADD_APPLICATION_STRING2 (STR_DELETE_SMS_QUERY_ID,	"Delete SMS?",	"SMS Delete SMS Query String");

	ADD_APPLICATION_MENUITEM((TEMPLATES_OPTIONS_MENUENTRY,
									0,	3,
									TEMPLATES_OPTIONS_EDIT_MENUENTRY,
									TEMPLATES_OPTIONS_ERASE_MENUENTRY,
									TEMPLATES_OPTIONS_WRITE_MESSAGE_MENUENTRY,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, 0));

	ADD_APPLICATION_MENUITEM((TEMPLATES_OPTIONS_EDIT_MENUENTRY,
									TEMPLATES_OPTIONS_MENUENTRY,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_EDIT,	0));

	ADD_APPLICATION_MENUITEM((TEMPLATES_OPTIONS_ERASE_MENUENTRY,
									TEMPLATES_OPTIONS_MENUENTRY,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_TEMPL_OPTIONS_ERASE,	0));
	
	ADD_APPLICATION_MENUITEM((TEMPLATES_OPTIONS_WRITE_MESSAGE_MENUENTRY,
									TEMPLATES_OPTIONS_MENUENTRY,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_TEMPL_OPTIONS_WRITE_MESSAGE,	0));
	
	ADD_APPLICATION_MENUITEM((SMS_ED_TEMPL_OPTIONS_MENU_ID,
									0,  2,
									SMS_ED_TEMPL_OPT_DONE_MENU,
									SMS_ED_TEMPL_OPT_INPUT_METHODS_MENU,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS,		0));
	ADD_APPLICATION_MENUITEM((SMS_ED_TEMPL_OPT_DONE_MENU,
									SMS_ED_TEMPL_OPTIONS_MENU_ID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_SAVE, 0));
	ADD_APPLICATION_MENUITEM((SMS_ED_TEMPL_OPT_INPUT_METHODS_MENU,
									SMS_ED_TEMPL_OPTIONS_MENU_ID, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_INPUT_METHOD, 0));
#endif // defined(__MMI_MESSAGES_TEMPLATE__)

	// FOR INLINE EDIT SCREEN OPTIONS
	/*
	ADD_APPLICATION_MENUITEM((MENU_INPUT_METHOD_AND_DONE_OPTION_ID,
									0,  2,
									MENU_SMS_DONE_OPTION_ID,
									MENU_SMS_INPUT_METHOD_OPTION_ID,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_GLOBAL_OPTIONS, 0));
	ADD_APPLICATION_MENUITEM((MENU_SMS_DONE_OPTION_ID,
									MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_OPT_DONE_MENUENTRY, 0));
	ADD_APPLICATION_MENUITEM((MENU_SMS_INPUT_METHOD_OPTION_ID,
									MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0,
									SHOW, NONMOVEABLE, DISP_LIST,
									STR_OPT_INPUT_METHOD_MENUENTRY, 0));
	*/
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_SAVE_OBJECT_OPTION,
									0,  2,
									SMS_INBOX_OPT_SAVE_OPTION_DONE,
									SMS_INBOX_OPT_SAVE_OPTION_INPUT_METHOD,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, 0));
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_SAVE_OPTION_DONE,
									SMS_INBOX_OPT_SAVE_OBJECT_OPTION, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DONE, 0));
	ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_SAVE_OPTION_INPUT_METHOD,
									SMS_INBOX_OPT_SAVE_OBJECT_OPTION, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_INPUT_METHOD, 0));
#if defined(__MMI_MESSAGES_EMS__)
	// FOR NON-INLINE EDIT SCREEN OPTIONS

	// view/delete ems object option from "Fun and Games" app
	ADD_APPLICATION_MENUITEM((EMS_OBJECT_OPTION_MENUENTRY,
									0,	3,
									EMS_OBJECT_OPTION_VIEW_MENUENTRY,
									EMS_OBJECT_OPTION_SEND_BY_EMS_MENUENTRY,
									EMS_OBJECT_OPTION_DELETE_MENUENTRY,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, 0));
	ADD_APPLICATION_MENUITEM((EMS_OBJECT_OPTION_VIEW_MENUENTRY,
									EMS_OBJECT_OPTION_MENUENTRY, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_VIEW, 0));
	ADD_APPLICATION_MENUITEM((EMS_OBJECT_OPTION_SEND_BY_EMS_MENUENTRY,
									EMS_OBJECT_OPTION_MENUENTRY, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_MESSAGES_SEND_BY_EMS_ID, 0));

	ADD_APPLICATION_MENUITEM((EMS_OBJECT_OPTION_DELETE_MENUENTRY,
									EMS_OBJECT_OPTION_MENUENTRY,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DELETE, 0));
#endif // defined(__MMI_MESSAGES_EMS__)

#if defined(__MMI_MESSAGES_TEMPLATE__)
	// Edit Template
	ADD_APPLICATION_STRING2 (STR_SCRN_T4_EDIT_TEMPLATE_CAPTION, "Edit Template",	"SMS Edit Message Option Caption String");
#endif // defined(__MMI_MESSAGES_TEMPLATE__)

	ADD_APPLICATION_STRING2 (STR_SENDIING_SMS_BODY,"Please Wait", "SMS PhoneNumber Blank Error Message Caption String");

	ADD_APPLICATION_STRING2 (STR_DELIVERY_REPORT_MENUENTRY,			"Delivery Report",	"Message Delivery report SMS String");
	ADD_APPLICATION_STRING2 (STR_REPLY_PATH_MENUENTRY,				"Reply Path",		"Message Reply path SMS String");
//	ADD_APPLICATION_STRING2 (STR_DELIVERY_REPLY_ON_MENUENTRY,		"ON",				"Message ON SMS String");
//	ADD_APPLICATION_STRING2 (STR_DELIVERY_REPLY_OFF_MENUENTRY,		"OFF",				"Message OFF SMS String");
	ADD_APPLICATION_STRING2 (STR_STATUS_REPORT_MESSAGE_DELIVERD_MSG,		"Delivered",				"Message Deliverd String");
	ADD_APPLICATION_STRING2 (STR_SMS_MSG_NOT_READY_YET,						"SMS Not Ready Yet!",			"Message SMS not ready yet String");
	//	C l a s s   0	M e s a s a g e
	ADD_APPLICATION_STRING2 (STR_CLASS0_MESSAGE_CAPTION,	"Incoming SMS",	"Message class 0 message SMS caption String");


	//PRINT_INFORMATION (("*-------[Res_Messages.c] PopulateCBResData -------*");
	PopulateCBResData();
	//PRINT_INFORMATION (("*-------[Res_Messages.c] AddCBLanguagesString -------*");
	AddCBLanguagesString ();
	//PRINT_INFORMATION (("*-------[Res_Messages.c] PopulateVoiceMailResData -------*");
	PopulateVoiceMailResData ();
	//PRINT_INFORMATION (("*-------[Res_Messages.c] PopulateEMSResourceData -------*");
	PopulateEMSResourceData ();
	//PRINT_INFORMATION (("*-------[Res_Messages.c] END  -------*");
#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__)&&!defined(__MMI_MESSAGES_EMS__))|| defined(__MMI_MYPICTURE__)
	PopulateNSMRes();
#endif

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    PopulateSIMMessageResData();
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
}

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
static void PopulateSIMMessageResData (void)
{
    ADD_APPLICATION_STRING2 (STR_NEW_SIM_MESSAGE_FROM_ID, "SIM Message From", "SMS SIM New Message From String");
    ADD_APPLICATION_STRING2 (STR_SMS_MOVE_ALL_ID, "Move All to Phone", "SIM Message Move all option");
    ADD_APPLICATION_STRING2 (STR_SMS_COPY_ALL_ID, "Copy All to Phone", "SIM Message Copy all option");
    ADD_APPLICATION_STRING2 (STR_SIMBOX_DELETEALL_QUERY, "Delete All SIM Message?" ,"Delete all SIM Message Confirmation");
    ADD_APPLICATION_STRING2 (STR_SIMBOX_MENUENTRY, "SIM Message", "SIM Message Menu option");

    ADD_APPLICATION_MENUITEM2((SMS_SIM_OPTIONS_MENUID,
									0,
								#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
									SMS_SIM_OPT_VIEW_MENUID,
								#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
						 			SMS_SIM_OPT_DELETE_MENUID,
						 		#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
									SMS_SIM_OPT_DELETE_ALL_MENUID,
								#endif
                                #ifdef __MMI_MESSAGES_COPY__
									SMS_SIM_OPT_COPY_MENUID,
                                    SMS_SIM_OPT_COPY_ALL_MENUID,
                                    SMS_SIM_OPT_MOVE_MENUID,
                                    SMS_SIM_OPT_MOVE_ALL_MENUID,
								#endif
								    MENU_ITEM_END,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((SMS_SIM_OPT_VIEW_MENUID,
								SMS_SIM_OPTIONS_MENUID, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_GLOBAL_VIEW, IMG_SMS_COMMON_NOIMAGE));
    

    ADD_APPLICATION_MENUITEM((SMS_SIM_OPT_DELETE_MENUID,
								SMS_SIM_OPTIONS_MENUID, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_GLOBAL_DELETE, IMG_SMS_COMMON_NOIMAGE));


#ifndef __MMI_MESSAGES_DELETE_ALL_MENU__
    ADD_APPLICATION_MENUITEM((SMS_SIM_OPT_DELETE_ALL_MENUID,
								SMS_SIM_OPTIONS_MENUID, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_GLOBAL_DELETE_ALL, IMG_SMS_COMMON_NOIMAGE));
#endif

#ifdef __MMI_MESSAGES_COPY__
    ADD_APPLICATION_MENUITEM((SMS_SIM_OPT_COPY_MENUID,
								SMS_SIM_OPTIONS_MENUID, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_SMS_COPY_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SMS_SIM_OPT_COPY_ALL_MENUID,
								SMS_SIM_OPTIONS_MENUID, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_SMS_COPY_ALL_ID, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SMS_SIM_OPT_MOVE_MENUID,
								SMS_SIM_OPTIONS_MENUID, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_SMS_MOVE_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SMS_SIM_OPT_MOVE_ALL_MENUID,
								SMS_SIM_OPTIONS_MENUID, 0,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_SMS_MOVE_ALL_ID, IMG_SMS_COMMON_NOIMAGE));
#endif
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


static void PopulateEMSResourceData (void)
{
	// EMS Options Menu
	ADD_APPLICATION_MENUITEM((EMS_ED_OPTIONS_MENU_ID,
									0,	NUM_MESSAGES_EDIT_MENU,
									EMS_ED_OPT_DONE,
								#ifdef __MMI_DUAL_SIM_MASTER__
									MENU_MTPNP_EMS_ED_OPT_DONE,
								#endif /* __MMI_DUAL_SIM_MASTER__ */
								#if defined(__MMI_MESSAGES_TEMPLATE__)
									EMS_ED_OPT_USE_TEMPLATES,
								#endif
								#if defined(__MMI_MESSAGES_EMS__) && !defined(__SLIM_EMS__)
									EMS_ED_OPT_INS_OBJ,
									MENU_EMS_FORMATING_TEXT_ID,
								#endif /* defined(__MMI_MESSAGES_EMS__) && !defined(__SLIM_EMS__) */
								#if !defined(__MMI_MESSAGES_EMS__)&& defined (__MMI_SMART_MESSAGE_MO__)
								EMS_ED_OPT_INS_OBJ,
								#endif
									EMS_ED_OPT_INS_PHB_NUMBER,
									EMS_ED_OPT_INS_PHB_NAME,
									EMS_ED_OPT_INS_BOOKMARK,
									EMS_ED_OPT_INPUT_METHOD,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INPUT_METHOD, EMS_ED_OPTIONS_MENU_ID,
							0,  // No child : rest of the menu is part of SMS
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_GLOBAL_INPUT_METHOD, IMG_SMS_COMMON_NOIMAGE));

#if defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_USE_TEMPLATES,
									EMS_ED_OPTIONS_MENU_ID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_USE_TEMPLATE, IMG_SMS_COMMON_NOIMAGE));
#endif // defined(__MMI_MESSAGES_TEMPLATE__)

#if defined(__MMI_MESSAGES_EMS__)
	#if defined(__MMI_IMELODY_SUPPORT__)
	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INS_OBJ,
									EMS_ED_OPTIONS_MENU_ID,	7,
									EMS_INS_OBJ_PICTURE,
									EMS_INS_OBJ_MY_PICTURE,
									EMS_INS_OBJ_PRED_ANIMATION,
									EMS_INS_OBJ_MY_ANIMATION,
									EMS_INS_OBJ_MELODY,
									EMS_INS_OBJ_MY_MELODY,
									EMS_INS_OBJ_PRED_SOUND,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_OPT_INS_OBJECT_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	#else
	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INS_OBJ,
									EMS_ED_OPTIONS_MENU_ID,	5,
									EMS_INS_OBJ_PICTURE,
									EMS_INS_OBJ_MY_PICTURE,
									EMS_INS_OBJ_PRED_ANIMATION,
									EMS_INS_OBJ_MY_ANIMATION,
									EMS_INS_OBJ_PRED_SOUND,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_OPT_INS_OBJECT_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
	#endif
	#if defined(__MMI_TEXT_FORMAT_WITHOUT_SIZE__)
	ADD_APPLICATION_MENUITEM((MENU_EMS_FORMATING_TEXT_ID,
									EMS_ED_OPTIONS_MENU_ID,	3,
									MENU_EMS_TEXT_STYLE_ID,
									MENU_EMS_ALIGNMENT_ID,
									MENU_EMS_NEW_PARAGRAPH_ID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_EMS_FORMATING_TEXT_ID, IMG_SMS_COMMON_NOIMAGE));

	#else
	ADD_APPLICATION_MENUITEM((MENU_EMS_FORMATING_TEXT_ID,
									EMS_ED_OPTIONS_MENU_ID,	4,
									MENU_EMS_TEXT_SIZE_ID,
									MENU_EMS_TEXT_STYLE_ID,
									MENU_EMS_ALIGNMENT_ID,
									MENU_EMS_NEW_PARAGRAPH_ID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_EMS_FORMATING_TEXT_ID, IMG_SMS_COMMON_NOIMAGE));
	#endif

	// Insert Objects menu
	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_PICTURE,
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_PICTURE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_MY_PICTURE,
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_MY_PICTURE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_PRED_ANIMATION,
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_PRED_ANIMATION, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_MY_ANIMATION,
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_MY_ANIMATION, IMG_SMS_COMMON_NOIMAGE));
	#if defined(__MMI_IMELODY_SUPPORT__)
	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_MELODY,
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_MELODY, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_MY_MELODY,
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_MY_MELODY, IMG_SMS_COMMON_NOIMAGE));
	#endif
	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_PRED_SOUND,
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_MY_SOUND, IMG_SMS_COMMON_NOIMAGE));
	#ifdef __MMI_DIALLING_FONT__
	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_SIZE_ID,
									MENU_EMS_FORMATING_TEXT_ID,	2,
									MENU_EMS_TEXT_SIZE_SMALL_ID,
									MENU_EMS_TEXT_SIZE_MEDIUM_ID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_EMS_TEXT_SIZE_ID, IMG_SMS_COMMON_NOIMAGE));
	#else
	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_SIZE_ID,
									MENU_EMS_FORMATING_TEXT_ID,	3,
									MENU_EMS_TEXT_SIZE_SMALL_ID,
									MENU_EMS_TEXT_SIZE_MEDIUM_ID,
									MENU_EMS_TEXT_SIZE_LARGE_ID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_EMS_TEXT_SIZE_ID, IMG_SMS_COMMON_NOIMAGE));
	#endif // __MMI_DIALLING_FONT__

#ifndef __MMI_TEXT_FORMAT_WITHOUT_BOLD__
	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_STYLE_ID, MENU_EMS_FORMATING_TEXT_ID,
							4,
							MENU_EMS_TEXT_STYLE_BOLD_ID,
							MENU_EMS_TEXT_STYLE_ITALICS_ID,
							MENU_EMS_TEXT_STYLE_UNDERLINE_ID,
							MENU_EMS_TEXT_STYLE_STRIKETHROUGH_ID,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_STYLE_ID, IMG_SMS_COMMON_NOIMAGE));
#else
	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_STYLE_ID, MENU_EMS_FORMATING_TEXT_ID,
							3,
							MENU_EMS_TEXT_STYLE_ITALICS_ID,
							MENU_EMS_TEXT_STYLE_UNDERLINE_ID,
							MENU_EMS_TEXT_STYLE_STRIKETHROUGH_ID,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_STYLE_ID, IMG_SMS_COMMON_NOIMAGE));
#endif


	ADD_APPLICATION_MENUITEM((MENU_EMS_ALIGNMENT_ID, MENU_EMS_FORMATING_TEXT_ID,
							4,
							MENU_EMS_ALIGNMENT_AUTOMATIC_ID,
							MENU_EMS_ALIGNMENT_LEFT_ID,
							MENU_EMS_ALIGNMENT_CENTER_ID,
							MENU_EMS_ALIGNMENT_RIGHT_ID,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_ALIGNMENT_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_NEW_PARAGRAPH_ID, MENU_EMS_FORMATING_TEXT_ID,
							4,
							MENU_EMS_NEW_PARAGRAPH_AUTOMATIC_ID,
							MENU_EMS_NEW_PARAGRAPH_LEFT_ID,
							MENU_EMS_NEW_PARAGRAPH_CENTER_ID,
							MENU_EMS_NEW_PARAGRAPH_RIGHT_ID,
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_NEW_PARAGRAPH_ID, IMG_SMS_COMMON_NOIMAGE));
	// fmt text  - text size
	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_SIZE_SMALL_ID, MENU_EMS_TEXT_SIZE_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_SIZE_SMALL_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_SIZE_MEDIUM_ID, MENU_EMS_TEXT_SIZE_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_SIZE_MEDIUM_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_SIZE_LARGE_ID, MENU_EMS_TEXT_SIZE_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_SIZE_LARGE_ID, IMG_SMS_COMMON_NOIMAGE));
	// fmt text  - text style
	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_STYLE_BOLD_ID, MENU_EMS_TEXT_STYLE_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_STYLE_BOLD_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_STYLE_ITALICS_ID, MENU_EMS_TEXT_STYLE_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_STYLE_ITALICS_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_STYLE_UNDERLINE_ID, MENU_EMS_TEXT_STYLE_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_STYLE_UNDERLINE_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_TEXT_STYLE_STRIKETHROUGH_ID, MENU_EMS_TEXT_STYLE_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_TEXT_STYLE_STRIKETHROUGH_ID, IMG_SMS_COMMON_NOIMAGE));
	// fmt text  - alignment
	ADD_APPLICATION_MENUITEM((MENU_EMS_ALIGNMENT_AUTOMATIC_ID, MENU_EMS_ALIGNMENT_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_ALIGNMENT_AUTOMATIC_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_ALIGNMENT_LEFT_ID, MENU_EMS_ALIGNMENT_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_ALIGNMENT_LEFT_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_ALIGNMENT_CENTER_ID, MENU_EMS_ALIGNMENT_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_ALIGNMENT_CENTER_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_ALIGNMENT_RIGHT_ID, MENU_EMS_ALIGNMENT_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_ALIGNMENT_RIGHT_ID, IMG_SMS_COMMON_NOIMAGE));
	// fmt text  - new paragraph
	ADD_APPLICATION_MENUITEM((MENU_EMS_NEW_PARAGRAPH_AUTOMATIC_ID, MENU_EMS_NEW_PARAGRAPH_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_NEW_PARAGRAPH_AUTOMATIC_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_NEW_PARAGRAPH_LEFT_ID, MENU_EMS_NEW_PARAGRAPH_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_NEW_PARAGRAPH_LEFT_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_NEW_PARAGRAPH_CENTER_ID, MENU_EMS_NEW_PARAGRAPH_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_NEW_PARAGRAPH_CENTER_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_EMS_NEW_PARAGRAPH_RIGHT_ID, MENU_EMS_NEW_PARAGRAPH_ID,
							0,  // No child
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_EMS_NEW_PARAGRAPH_RIGHT_ID, IMG_SMS_COMMON_NOIMAGE));



	// String resources
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_PICTURE,	"Picture",	"Insert Object Option STR_INS_OBJ_PICTURE");
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_MY_PICTURE,	"My Picture",	"Insert Object Option STR_INS_OBJ_MY_PICTURE");
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_PRED_ANIMATION,	"Predefined Animation",	"Insert Object Option STR_INS_OBJ_PRED_ANIMATION");
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_MY_ANIMATION,	"My Animation",	"Insert Object Option STR_INS_OBJ_MY_ANIMATION");
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_MELODY,	"Melody",	"Insert Object Option STR_INS_OBJ_MELODY");
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_MY_MELODY,	"My Melody",	"Insert Object Option STR_INS_OBJ_MY_MELODY");
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_MY_SOUND,	"Predefined Sound",	"Insert Object Option STR_INS_OBJ_MY_SOUND");

	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_LIST,	"Object List",	"Insert Object List Picture List");
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_NAME,	"Object Name",	"Insert Object Name Picture List");
	ADD_APPLICATION_STRING2 (STR_PREVIEW_EMS_OBJECT,	"Preview",	"Insert Preview Picture List");
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_FILE_NAME_CANT_BE_EMPTY,	"File name cannot be empty",	"Insert Object List Picture List");
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_DUPLICATED_NAME_INPUT_AGAIN,	"Duplicated Name! Input Again",	"Insert Object Name Picture List");
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_STAORAGE_FULL,	"Storage Full!",	"Insert Preview Picture List");
	// Manufactures Pictures		/// names not decided yet..
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_0, "ems1", "EMS STR_MANUFACTURER_PICTURE_0 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_1, "ems2", "EMS STR_MANUFACTURER_PICTURE_1 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_2, "ems3", "EMS STR_MANUFACTURER_PICTURE_2 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_3, "ems4", "EMS STR_MANUFACTURER_PICTURE_3 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_4, "ems5", "EMS STR_MANUFACTURER_PICTURE_4 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_5, "ems6", "EMS STR_MANUFACTURER_PICTURE_5 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_6, "ems7", "EMS STR_MANUFACTURER_PICTURE_6 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_7, "ems8", "EMS STR_MANUFACTURER_PICTURE_7 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_8, "ems9", "EMS STR_MANUFACTURER_PICTURE_8 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_PICTURE_9, "ems10", "EMS STR_MANUFACTURER_PICTURE_9 name") ;
	// Manufactures Melodies		/// names not decided yet..
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_0, "imy1", "EMS STR_MANUFACTURER_MELODIES_0 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_1, "imy2", "EMS STR_MANUFACTURER_MELODIES_1 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_2, "imy3", "EMS STR_MANUFACTURER_MELODIES_2 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_3, "imy4", "EMS STR_MANUFACTURER_MELODIES_3 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_4, "imy5", "EMS STR_MANUFACTURER_MELODIES_4 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_5, "imy6", "EMS STR_MANUFACTURER_MELODIES_5 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_6, "imy7", "EMS STR_MANUFACTURER_MELODIES_6 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_7, "imy8", "EMS STR_MANUFACTURER_MELODIES_7 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_8, "imy9", "EMS STR_MANUFACTURER_MELODIES_8 name") ;
	ADD_APPLICATION_STRING2 (STR_MANUFACTURER_MELODIES_9, "imy10", "EMS STR_MANUFACTURER_MELODIES_9 name") ;
	// Predefined Animations
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_0,  "I am ironic, flirty", "EMS STR_PREDEFINED_ANIMATION_0 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_1,  "I am glad", "EMS STR_PREDEFINED_ANIMATION_1 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_2,  "I am sceptic", "EMS STR_PREDEFINED_ANIMATION_2 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_3,  "I am sad", "EMS STR_PREDEFINED_ANIMATION_3 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_4,  "WOW!", "EMS STR_PREDEFINED_ANIMATION_4 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_5,  "I am crying", "EMS STR_PREDEFINED_ANIMATION_5 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_6,  "I am winking", "EMS STR_PREDEFINED_ANIMATION_6 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_7,  "I am laughing", "EMS STR_PREDEFINED_ANIMATION_7 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_8,  "I am indifferent", "EMS STR_PREDEFINED_ANIMATION_8 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_9,  "In Love/Kissing", "EMS STR_PREDEFINED_ANIMATION_9 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_10, "I am confused", "EMS STR_PREDEFINED_ANIMATION_10 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_11, "Tongue hanging out", "EMS STR_PREDEFINED_ANIMATION_11 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_12, "I am angry", "EMS STR_PREDEFINED_ANIMATION_12 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_13, "Wearing glasses", "EMS STR_PREDEFINED_ANIMATION_13 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_ANIMATION_14, "Devil", "EMS STR_PREDEFINED_ANIMATION_14 name") ;
	// Predefined Sounds,
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_0,  "Chimes high", "EMS STR_PREDEFINED_SOUND_0 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_1,  "Chimes low", "EMS STR_PREDEFINED_SOUND_1 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_2,  "Ding", "EMS STR_PREDEFINED_SOUND_2 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_3,  "TaDa", "EMS STR_PREDEFINED_SOUND_3 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_4,  "Notify", "EMS STR_PREDEFINED_SOUND_4 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_5,  "Drum", "EMS STR_PREDEFINED_SOUND_5 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_6,  "Claps", "EMS STR_PREDEFINED_SOUND_6 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_7,  "FanFar", "EMS STR_PREDEFINED_SOUND_7 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_8,  "Chord high", "EMS STR_PREDEFINED_SOUND_8 name") ;
	ADD_APPLICATION_STRING2 (STR_PREDEFINED_SOUND_9,  "Chord low", "EMS STR_PREDEFINED_SOUND_9 name") ;

	// Access features "view/delete" ems objects from "FUN and GAMGES" application
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_EMS_ID,	"EMS",	"STR_EMS_OBJECT_EMS_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_ANIMATION_ID,	"EMS Animation",	"STR_EMS_PICTURE_OBJECT_FILE_NAME_INIT_PATH_ID");
	ADD_APPLICATION_STRING2 (STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID,	"Object Size Not Allowed",	"STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID");
#endif // defined(__MMI_MESSAGES_EMS__)

	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INS_PHB_NUMBER, EMS_ED_OPTIONS_MENU_ID,
						0,  // No child
						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						STR_SMS_INSERT_PHB_NUMBER_ID, IMG_SMS_COMMON_NOIMAGE));


	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INS_PHB_NAME, EMS_ED_OPTIONS_MENU_ID,
						0,  // No child
						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						STR_SMS_INSERT_PHB_NAME_ID, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INS_BOOKMARK, EMS_ED_OPTIONS_MENU_ID,
						0,  // No child
						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						STR_SMS_INSERT_BOOKMARK_ID, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_STRING2 (STR_SMS_INSERT_PHB_NUMBER_ID,	"Insert PHB Number",	"STR_SMS_INSERT_PHB_NUMBER_ID");    
    ADD_APPLICATION_STRING2 (STR_SMS_INSERT_PHB_NAME_ID,	"Insert PHB Name",	"STR_SMS_INSERT_PHB_NAME_ID");
    ADD_APPLICATION_STRING2 (STR_SMS_INSERT_BOOKMARK_ID,	"Insert Bookmark",	"STR_SMS_INSERT_BOOKMARK_ID");

}

void PopulateVoiceMailResData (void)
{

	ADD_APPLICATION_MENUITEM((MENU_ITEM_VOICE_MAIL_OPTION,
									0, 2,		
									MENU_ITEM_VM_1_EDIT,
									MENU_ITEM_VM_3_CONNECT_TO_VOICE,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK));
	ADD_APPLICATION_MENUITEM((MENU_ITEM_VM_1_EDIT,
									MENU_ITEM_VOICE_MAIL_OPTION,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_EDIT, IMG_GLOBAL_OK));
	ADD_APPLICATION_MENUITEM((MENU_ITEM_VM_3_CONNECT_TO_VOICE,
									MENU_ITEM_VOICE_MAIL_OPTION,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_VM_3_CONNECT_TO_VOICE_ID, IMG_GLOBAL_OK));
	ADD_APPLICATION_STRING2 (STR_VOICE_MAIL_NOT_READY_YET, 					"VM Not Ready Yet!", "Message Voice Mail Not Ready String");
	ADD_APPLICATION_STRING2 (STR_VOICE_MAIL_OPTION_ID,			"Voice Mail Option",	"Message Voice Mail Option String");
//	ADD_APPLICATION_STRING2 (STR_VM_1_EDIT_ID,					"Edit",					"Message Edit String");
	ADD_APPLICATION_STRING2 (STR_VM_2_ERASE_ID,					"Erase",				"Message Erase String");
	ADD_APPLICATION_STRING2 (STR_VM_3_CONNECT_TO_VOICE_ID,		"Connect to Voice",		"Message Connect to Voice String");
	ADD_APPLICATION_STRING2 (STR_SMS_SET_VOICEMAIL_QUERY_ID,	"Set voice mail number first",	"Set Voice Mail Number Query String");
}
void PopulateCBResData()
{
	ADD_APPLICATION_MENUITEM((MITEM102_CB_SERVICE,
									MESSAGES_MENU_CB_MENUID,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR101_MITEM102_CB_SERVICE, IMG_CB_RECEIVE_MODE_MENUENTRY));
	ADD_APPLICATION_MENUITEM((MITEM102_CB_READ_MESSAGE,
									MESSAGES_MENU_CB_MENUID,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR101_MITEM102_CB_READ_MESSAGE, IMG_CB_READ_MESSAGE_MENUENTRY));
	ADD_APPLICATION_MENUITEM((MITEM102_CB_CHANNELS,
									MESSAGES_MENU_CB_MENUID,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR101_MITEM102_CB_CHANNELS,IMG_CB_LANGUAGES_MENUENTRY));
	ADD_APPLICATION_MENUITEM((MITEM102_CB_LANGUAGE,
									MESSAGES_MENU_CB_MENUID,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR101_MITEM102_CB_LANGUAGE,IMG_CB_CHNL_SETTING_MENUENTRY));
	//channel options - enable
	ADD_APPLICATION_MENUITEM((MITEM103_CB_CHANNEL_ENBL_OPTIONS,
									0,	4,
									MITEM104_CB_CHANNEL_SELECT,
									MITEM104_CB_CHANNEL_ADD,
									MITEM104_CB_CHANNEL_EDIT,
									MITEM104_CB_CHANNEL_DELETE,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR102_MITEM103_CB_CHANNEL_ENBL_OPTIONS,IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MITEM104_CB_CHANNEL_ADD,
									MITEM103_CB_CHANNEL_ENBL_OPTIONS,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR_GLOBAL_ADD,IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MITEM104_CB_CHANNEL_EDIT,
									MITEM103_CB_CHANNEL_ENBL_OPTIONS,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR_GLOBAL_EDIT,IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MITEM104_CB_CHANNEL_DELETE,
									MITEM103_CB_CHANNEL_ENBL_OPTIONS,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR_GLOBAL_DELETE,IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MITEM104_CB_CHANNEL_SELECT,
									MITEM103_CB_CHANNEL_ENBL_OPTIONS,0,
									SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
									STR_GLOBAL_SELECT,IMG_SMS_COMMON_NOIMAGE));
// Strings
	ADD_APPLICATION_STRING2 (STR101_MITEM102_CB_SERVICE	,  			"Receive Mode",	"CB Menu Item Service Cell Broadcast String");
	ADD_APPLICATION_STRING2 (STR101_MITEM102_CB_READ_MESSAGE	, "Read Message",	"CB Menu Read Message Cell Broadcast String");
	ADD_APPLICATION_STRING2 (STR101_MITEM102_CB_CHANNELS	, 		"Channel Setting",	"CB Menu Channels Cell Broadcast String");
	ADD_APPLICATION_STRING2 (STR101_MITEM102_CB_LANGUAGE	,		"Languages",	"CB Menu Language Cell Broadcast String");
	ADD_APPLICATION_STRING2 (STR_CB_MESSAGE_BODY,   				"Message Body",		"CB Menu Message Body String");
	ADD_APPLICATION_STRING2 (STR_CB_SELECT_CHNL,    				"Select Channel",	"CB Menu Select Channel String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_EDITOR	,  					"Channel Editor",	"CB Menu Channel Editor String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_TITLE	,  					"Channel Title",	"CB Menu Channel Title: String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_TITLE_FULL_EDIT	,  		"Channel Title",	"CB Menu Channel Title String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NUMBER	,  					"Channel Number",	"CB Menu Channel Number String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_LIST	,  					"Channel List",		"CB Menu Channel List String");
	ADD_APPLICATION_STRING2 (STR_CB_ERROR_MESSAGE, 					"Failed!", "CB error String");
	ADD_APPLICATION_STRING2 (STR_CB_NOT_READY_YET, 					"CB Not Ready Yet!", "CB CB Not Ready Yet! String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_DUPLICATE_NUMBER_NOT_ALLOWED, "Duplicate number not allowed!", "CB Duplicate number not allowed String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NUMBER_LEN_EXCEEDED, "Number Exceeded!", "Number Exceeded! String");
	ADD_APPLICATION_STRING2 (STR_CB_ALL_CHANNELS_FOR_SELECT, 		"All Channels", "CB All Channels String");
	ADD_APPLICATION_STRING2 (STR_CB_ALL_LANGUAGES_FOR_SELECT, "All Languages", "CB All Languages String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_1, "Channel 1", "CB channel 1 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_2, "Channel 2", "CB channel 2 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_3, "Channel 3", "CB channel 3 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_4, "Channel 4", "CB channel 4 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_5, "Channel 5", "CB channel 5 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_6, "Channel 6", "CB channel 6 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_7, "Channel 7", "CB channel 7 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_8, "Channel 8", "CB channel 8 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_9, "Channel 9", "CB channel 9 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_10, "Channel 10", "CB channel 10 String");
        ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_11, "Channel 1", "CB channel 1 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_12, "Channel 2", "CB channel 2 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_13, "Channel 3", "CB channel 3 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_14, "Channel 4", "CB channel 4 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_15, "Channel 5", "CB channel 5 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_16, "Channel 6", "CB channel 6 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_17, "Channel 7", "CB channel 7 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_18, "Channel 8", "CB channel 8 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_19, "Channel 9", "CB channel 9 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_20, "Channel 10", "CB channel 10 String");
        ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_21, "Channel 1", "CB channel 1 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_22, "Channel 2", "CB channel 2 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_23, "Channel 3", "CB channel 3 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_24, "Channel 4", "CB channel 4 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_25, "Channel 5", "CB channel 5 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_26, "Channel 6", "CB channel 6 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_27, "Channel 7", "CB channel 7 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_28, "Channel 8", "CB channel 8 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_29, "Channel 9", "CB channel 9 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_30, "Channel 10", "CB channel 10 String");
        ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_31, "Channel 1", "CB channel 1 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_32, "Channel 2", "CB channel 2 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_33, "Channel 3", "CB channel 3 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_34, "Channel 4", "CB channel 4 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_35, "Channel 5", "CB channel 5 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_36, "Channel 6", "CB channel 6 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_37, "Channel 7", "CB channel 7 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_38, "Channel 8", "CB channel 8 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_39, "Channel 9", "CB channel 9 String");
	ADD_APPLICATION_STRING2 (STR_CB_CHNL_NAME_40, "Channel 10", "CB channel 10 String");
//	ADD_APPLICATION_STRING2 (STR101_MITEM103_CB_SERVICE_ON,			"ON",   "CB Menu Item Service ON Caption String");
//	ADD_APPLICATION_STRING2 (STR101_MITEM103_CB_SERVICE_OFF,		"OFF", "CB Menu Item Service OFF Caption String");
	ADD_APPLICATION_STRING2 (STR103_SCR101_CAPTION		,			"Languages", "CB Menu Item Cell Broadcast Language Caption String");
	ADD_APPLICATION_STRING2 (STR102_MITEM103_CB_CHANNEL_ENBL_OPTIONS,	"Channel Options",	     "CB Menu Item Cell Broadcast Channels Options Enable String");
//	ADD_APPLICATION_STRING2 (STR102_MITEM104_CB_CHANNEL_ADD,		"Add",	"CB Menu Item Cell Broadcast Channels Options Add New String");
//	ADD_APPLICATION_STRING2 (STR102_MITEM104_CB_CHANNEL_EDIT,		"Edit",	"CB Menu Item Cell Broadcast Channels Options Edit String");
//	ADD_APPLICATION_STRING2 (STR102_MITEM104_CB_CHANNEL_DELETE,"Delete",	"CB Menu Item Cell Broadcast Channels Options Delete String");
//	ADD_APPLICATION_STRING2 (STR102_MITEM104_CB_CHANNEL_ENABLE,"Select",	"CB Menu Item Cell Broadcast Channels Options Enable String");
	ADD_APPLICATION_STRING2 (STR102_SCR103_CAPTION,					"Channels",  "CB Menu Item Cell Broadcast Channels Options Caption String");
	ADD_APPLICATION_STRING2 (STR103_MITEM103_CB_LANGUAGE_UNSPECIFIED,"unspecified", "CB Menu Item Cell Broadcast Language Option Unspecified Language String");
//	ADD_APPLICATION_STRING2(STR_CB_MSG_DELETE,						"Delete",	"CB  delete String");
	ADD_APPLICATION_STRING2(STR_CB_MSG_IND_INFORMATION_CAPTION,	"Information",	"CB  Information String");

	ADD_APPLICATION_STRING2(STR_ID_MSG_CB_DELETE_CHANNEL_QUERY,	"Delete channel?","CB delete channel query string");
	ADD_APPLICATION_STRING2(STR_ID_MSG_CB_ADD_CHANNEL_QUERY,	"Add channel?",	"CB add channel query string");

	ADD_APPLICATION_STRING2(STR_ID_MSG_SMS_ADD_SUCCESS,	"Added",	"SMS add success string");
	ADD_APPLICATION_STRING2(STR_ID_MSG_SMS_SAVE_CHANGES_QUERY,	"Save changes?",	"SMS save changes query string");
	ADD_APPLICATION_STRING2(STR_ID_MSG_SMS_DELETE_MESSAGE_QUERY,	"Delete message?",	"SMS delete message query string");
}

void AddCBLanguagesString (void)
{
	ADD_APPLICATION_STRING2(	STR_LANG_AFAR,				"AFAR",      "CB AFAR String");
	ADD_APPLICATION_STRING2(	STR_LANG_ABKHAZIAN,			"ABKHAZIAN", "CB ABKHAZIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_AFRIKAANS,			"AFRIKAANS", "CB AFRIKAANS String");
	ADD_APPLICATION_STRING2(	STR_LANG_AMHARIC,			"AMHARIC",   "CB AMHARIC String");
	ADD_APPLICATION_STRING2(	STR_LANG_ARABIC,			"ARABIC",    "CB ARABIC String");
	ADD_APPLICATION_STRING2(	STR_LANG_ASSAMESE,			"ASSAMESE",  "CB ASSAMESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_AYMARA,			"AYMAR",     "CB AYMAR String");
	ADD_APPLICATION_STRING2(	STR_LANG_AZERBAIJANI,	    "AZERBAIJANI","CB AZERBAIJANI String");
	ADD_APPLICATION_STRING2(	STR_LANG_BASHKIR,			"BASHKIR",      "CB BASHKIR String");
	ADD_APPLICATION_STRING2(	STR_LANG_BYELORUSSIAN,      "BYELORUSSIAN",      "CB BYELORUSSIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_BULGARIAN,			"BULGARIAN", "CB BULGARIAN String");

	ADD_APPLICATION_STRING2(	STR_LANG_BIHARI,			"BIHARI", "CB BIHARI String");
	ADD_APPLICATION_STRING2(	STR_LANG_BISLAMA,			"BISLAMA",   "CB BISLAMA String");
	ADD_APPLICATION_STRING2(	STR_LANG_BENGALI ,			"BENGAL",      "CB BENGAL String");
	ADD_APPLICATION_STRING2(	STR_LANG_TIBETAN,			"TIBETAN", "CB TIBETAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_BRETON,			"BRETON", "CB BRETON String");
	ADD_APPLICATION_STRING2(	STR_LANG_CATALAN,			"CATALAN",   "CB CATALAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_CORSICAN,				"CORSICAN",      "CB CORSICAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_CZECH,				"CZECH",      "CB CZECH String");
	ADD_APPLICATION_STRING2(	STR_LANG_WELSH,				"WELSH", "CB WELSH String");
	ADD_APPLICATION_STRING2(	STR_LANG_DANISH ,			"DANISH", "CB DANISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_GERMAN,			"GERMAN",   "CB GERMAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_BHUTANI,			"BHUTANI",      "CB BHUTANI String");
	ADD_APPLICATION_STRING2(	STR_LANG_GREEK,				"GREEK", "CB GREEK String");
	ADD_APPLICATION_STRING2(	STR_LANG_ENGLISH,			"ENGLISH", "CB ENGLISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_ESPERANTO,			"ESPERANTO",   "CB ESPERANTO String");
	ADD_APPLICATION_STRING2(	STR_LANG_SPANISH,		"SPANISH",      "CB SPANISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_ESTONIAN,		"ESTONIAN",      "CB ESTONIAN String");

	ADD_APPLICATION_STRING2(	STR_LANG_BASQUE,		"BASQUE", "CB BASQUE String");
	ADD_APPLICATION_STRING2(	STR_LANG_PERSIAN,		"PERSIAN", "CB AFRIKAANS String");
	ADD_APPLICATION_STRING2(	STR_LANG_FINNISH ,		"FINNISH",   "CB FINNISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_FIJI,			"FIJI",      "CB FIJI String");
	ADD_APPLICATION_STRING2(	STR_LANG_FAROESE,		"FAROESE", "CB FAROESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_FRENCH,		"FRENCH", "CB FRENCH String");
	ADD_APPLICATION_STRING2(	STR_LANG_FRISIAN,		"FRISIAN",   "CB FRISIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_IRISH,			"IRISH",      "CB IRISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_SCOTS_GAELIC,	"SCOTS GAELIC",      "CB SCOTS GAELIC String");
	ADD_APPLICATION_STRING2(	STR_LANG_GALICIAN,		"GALICIAN", "CB GALICIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_GUARANI,		"GUARANI", "CB GUARANI String");
	ADD_APPLICATION_STRING2(	STR_LANG_GUJARATI,		"GUJARATI",   "CB GUJARATI String");
	ADD_APPLICATION_STRING2(	STR_LANG_HAUSA   ,  	"HAUSA",      "CB HAUSA String");

	ADD_APPLICATION_STRING2(	STR_LANG_HEBREW, 		"HEBREW",		 "CB HEBREW String");
	ADD_APPLICATION_STRING2(	STR_LANG_HINDI,			"HINDI",	     "CB HINDI String");
	ADD_APPLICATION_STRING2(	STR_LANG_CROATIAN,		"CROATIAN",		 "CB CROATIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_HUNGARIAN, 	"HUNGARIAN",	 "CB HUNGARIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_ARMENIAN,		"ARMENIAN",	 "CB ARMENIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_INTERLINGUA,	"INTERLINGUA",	 "CB INTERLINGUA String");
	ADD_APPLICATION_STRING2(	STR_LANG_INDONESIAN,	"AMHARIC",		"CB AMHARIC String");
	ADD_APPLICATION_STRING2(	STR_LANG_INTERLINGUE,	"INTERLINGUE",      "CB INTERLINGUE String");
	ADD_APPLICATION_STRING2(	STR_LANG_INUPIAK,		"INUPIAK", "CB INUPIAK String");
	ADD_APPLICATION_STRING2(	STR_LANG_ICELANDIC ,	"ICELANDIC", "CB ICELANDIC String");
	ADD_APPLICATION_STRING2(	STR_LANG_ITALIAN,		"ITALIAN",   "CB ITALIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_INUKTITUT,		"INUKTITUT",      "CB INUKTITUT String");
	ADD_APPLICATION_STRING2(	STR_LANG_JAPANESE, 		"JAPANESE", "CB JAPANESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_JAVANESE,		"JAVANESE", "CB JAVANESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_GEORGIAN,		"GEORGIAN",   "CB GEORGIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_KAZAKH,		"KAZAKH",      "CB KAZAKH String");
	ADD_APPLICATION_STRING2(	STR_LANG_GREENLANDIC,	"GREENLANDI", "CB GREENLANDI String");
	ADD_APPLICATION_STRING2(	STR_LANG_CAMBODIAN,		"CAMBODIAN", "CB CAMBODIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_KANNADA,		"KANNADA",   "CB KANNADA String");
	ADD_APPLICATION_STRING2(	STR_LANG_KOREAN   ,		"KOREAN",      "CB KOREAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_KASHMIRI,		"KASHMIRI", "CB KASHMIRI String");
	ADD_APPLICATION_STRING2(	STR_LANG_KURDISH,		"KURDISH", "CB KURDISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_KIRGHIZ,		"KIRGHIZ",   "CB KIRGHIZ String");
	ADD_APPLICATION_STRING2(	STR_LANG_LATIN,			"LATIN",      "CB LATIN String");
	ADD_APPLICATION_STRING2(	STR_LANG_LINGALA,		"LINGALA", "CB LINGALA String");
	ADD_APPLICATION_STRING2(	STR_LANG_LAOTHIAN,		"LAOTHIAN", "CB LAOTHIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_LITHUANIAN,	"LITHUANIAN",   "CB LITHUANIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_LATVIAN, 		"LATVIAN",      "CB LATVIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_MALAGASY,		"MALAGASY",      "CB MALAGASY String");
	ADD_APPLICATION_STRING2(	STR_LANG_MAORI  , 		"MAORI", "CB MAORI String");
	ADD_APPLICATION_STRING2(	STR_LANG_MACEDONIAN,		"MACEDONIA", "CB MACEDONIA String");
	ADD_APPLICATION_STRING2(	STR_LANG_MALAYALAM,		"MALAYALAM",   "CB MALAYALAM String");
	ADD_APPLICATION_STRING2(	STR_LANG_MONGOLIAN,		"MONGOLIAN",      "CB MONGOLIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_MOLDAVIAN,		"MOLDAVIAN", "CB MOLDAVIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_MARATHI,		"MARATHI", "CB MARATHI String");
	ADD_APPLICATION_STRING2(	STR_LANG_MALAY,			"MALAY",   "CB MALAY String");
	ADD_APPLICATION_STRING2(	STR_LANG_MALTESE,		"MALTESE",      "CB MALTESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_BURMESE,		"BURMESE", "CB BURMESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_NAURU,			"NAURU", "CB NAURU String");
	ADD_APPLICATION_STRING2(	STR_LANG_NEPALI, 		"NEPALI",   "CB NEPALI String");
	ADD_APPLICATION_STRING2(	STR_LANG_DUTCH,			"DUTCH",      "CB DUTCH String");
	ADD_APPLICATION_STRING2(	STR_LANG_NORWEGIAN,		"NORWEGIA", "CB NORWEGIA String");
	ADD_APPLICATION_STRING2(	STR_LANG_OCCITAN,		"OCCITAN", "CB OCCITAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_OROMO, 		"OROMO",   "CB OROMO String");
	ADD_APPLICATION_STRING2(	STR_LANG_ORIYA,			"ORIYA",			"CB ORIYA String");
	ADD_APPLICATION_STRING2(	STR_LANG_PUNJABI,		"PUNJABI",			"CB PUNJABI String");
	ADD_APPLICATION_STRING2(	STR_LANG_POLISH,		"POLISH",	"CB POLISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_PASHTO, 		"PASHTO",	"CB PASHTO String");

	ADD_APPLICATION_STRING2(	STR_LANG_PORTUGUESE,		"PORTUGUE",		"CB PORTUGUE String");
	ADD_APPLICATION_STRING2(	STR_LANG_QUECHUA,		"QUECHUA",       "CB QUECHUA String");
	ADD_APPLICATION_STRING2(	STR_LANG_RHAETO_ROMANCE,	"RHAETO ROMANCE",		"CB ASSAMESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_KIRUNDI,		"KIRUNDI",		"CB KIRUNDI String");
	ADD_APPLICATION_STRING2(	STR_LANG_ROMANIAN,		"ROMANIAN",  "CB ROMANIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_RUSSIAN,		"RUSSIAN",			"CB RUSSIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_KINYARWANDA,	"KINYARWANDA",			"CB KINYARWANDA String");
	ADD_APPLICATION_STRING2(	STR_LANG_SANSKRIT,		"SANSKRIT",	"CB SANSKRIT String");
	ADD_APPLICATION_STRING2(	STR_LANG_SINDHI,		"SINDHI",	"CB SINDHI String");
	ADD_APPLICATION_STRING2(	STR_LANG_SANGHO,		"SANGHO",		"CB SANGHO String");
	ADD_APPLICATION_STRING2(	STR_LANG_SERBO_CROATIAN,	"SERBO CROATI",       "CB SERBO_CROATI String");
	ADD_APPLICATION_STRING2(	STR_LANG_SINHALESE , 	"SINHALESE",		"CB SINHALESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_SLOVAK,		"SLOVAK",		"CB SLOVAK String");
	ADD_APPLICATION_STRING2(	STR_LANG_SLOVENIAN,		"SLOVENIAN",  "CB SLOVENIAN String");

	ADD_APPLICATION_STRING2(	STR_LANG_SAMOAN, 		"SAMOAN",			"CB SAMOAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_SHONA,			"SHONA",	"CB SHONA String");
	ADD_APPLICATION_STRING2(	STR_LANG_SOMALI,		"SOMALI",	"CB SOMALI String");
	ADD_APPLICATION_STRING2(	STR_LANG_ALBANIAN,		"ALBANIAN",		"CB ALBANIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_SERBIAN,		"SERBIAN",       "CB SERBIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_SISWATI,		"SISWATI",		"CB SISWATI String");
	ADD_APPLICATION_STRING2(	STR_LANG_SESOTHO,		"SESOTHO",		"CB SESOTHO String");
	ADD_APPLICATION_STRING2(	STR_LANG_SUNDANESE,		"SUNDANES",  "CB SUNDANES String");
	ADD_APPLICATION_STRING2(	STR_LANG_SWEDISH,		"SWEDISH",			"CB SWEDISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_SWAHILI,		"SWAHILI",			"CB SWAHILI String");
	ADD_APPLICATION_STRING2(	STR_LANG_TAMIL,			"TAMIL*",	"CB TAMIL String");
	ADD_APPLICATION_STRING2(	STR_LANG_TELUGU,		"TELUGU",	"CB TELUGU String");
	ADD_APPLICATION_STRING2(	STR_LANG_TAJIK,			"TAJIK",		"CB TAJIK String");
	ADD_APPLICATION_STRING2(	STR_LANG_THAI,			"THAI",       "CB THAI String");

	ADD_APPLICATION_STRING2(	STR_LANG_TIGRINYA,		"TIGRINYA",		"CB TIGRINYA String");
	ADD_APPLICATION_STRING2(	STR_LANG_TURKMEN,		"TURKMEN",		"CB TURKMEN String");
	ADD_APPLICATION_STRING2(	STR_LANG_TAGALOG,		"TAGALOG",  "CB TAGALOG String");
	ADD_APPLICATION_STRING2(	STR_LANG_SETSWANA , 	"SETSWANA",			"CB SETSWANA String");
	ADD_APPLICATION_STRING2(	STR_LANG_TONGA,			"TONGA",	"CB TONGA String");
	ADD_APPLICATION_STRING2(	STR_LANG_TURKISH,		"TURKISH",	"CB TURKISH String");
	ADD_APPLICATION_STRING2(	STR_LANG_TSONGA,		"TSONGA",		"CB TSONGA String");
	ADD_APPLICATION_STRING2(	STR_LANG_TATAR,			"TATAR",       "CB TATAR String");
	ADD_APPLICATION_STRING2(	STR_LANG_TWI,			"TWI",		"CB TWI String");
	ADD_APPLICATION_STRING2(	STR_LANG_UIGHUR,		"UIGHUR",		"CB UIGHUR String");
	ADD_APPLICATION_STRING2(	STR_LANG_UKRAINIAN,		"UKRAINIAN",  "CB UKRAINIAN String");
	ADD_APPLICATION_STRING2(	STR_LANG_URDU, 			"URDU",			"CB URDU String");
	ADD_APPLICATION_STRING2(	STR_LANG_UZBEK,			"UZBEK",	"CB UZBEK String");
	ADD_APPLICATION_STRING2(	STR_LANG_VIETNAMESE	,		"VIETNA",	"CB VIETNA String");
	ADD_APPLICATION_STRING2(	STR_LANG_VOLAPUK	,		"VOLAPU",		"CB VOLAPU String");
	ADD_APPLICATION_STRING2(	STR_LANG_WOLOF,			"WOLOF",       "CB WOLOF String");
	ADD_APPLICATION_STRING2(	STR_LANG_XHOSA,			"XHOSA",		"CB XHOSA String");
	ADD_APPLICATION_STRING2(	STR_LANG_YIDDISH	,		"YIDDIS",		"CB YIDDIS String");
	ADD_APPLICATION_STRING2(	STR_LANG_YORUBA	,		"YORUBA",  "CB YORUBA String");
	ADD_APPLICATION_STRING2(	STR_LANG_ZHUANG,		"ZHUANG",			"CB ZHUANG String");
	ADD_APPLICATION_STRING2(	STR_LANG_CHINESE,		"CHINESE",			"CB CHINESE String");
	ADD_APPLICATION_STRING2(	STR_LANG_ZULU ,			"ZULU",	"CB ZULU String");
}

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))|| defined(__MMI_MYPICTURE__)

typedef enum
{
	INBOX_NSM_PICMSG_OPT_REPLY = 0,
	INBOX_NSM_PICMSG_OPT_DELETE,
	INBOX_NSM_PICMSG_OPT_EDIT,
	INBOX_NSM_PICMSG_OPT_FORWARD,

#ifdef __MMI_MESSAGES_COPY__
	INBOX_NSM_OPT_PICMSG_COPY_TO_PHONE,
	INBOX_NSM_OPT_PICMSG_MOVE_TO_PHONE,
#endif	/* __MMI_MESSAGES_COPY__ */

#ifdef __MMI_MESSAGES_CHAT__
	INBOX_NSM_PICMSG_OPT_CHAT,
#endif	/* __MMI_MESSAGES_CHAT__ */

	INBOX_NSM_PICMSG_OPT_DELETE_ALL,


#ifdef __MMI_MESSAGES_COPY__
	INBOX_NSM_PICMSG_OPT_COPY_ALL,
	INBOX_NSM_PICMSG_OPT_MOVE_ALL,
#endif	/* __MMI_MESSAGES_COPY__ */

	INBOX_NSM_PICMSG_OPT_USE_NUMBER,

#if defined(__MMI_MESSAGES_USE_URL__)
	INBOX_NSM_PICMSG_OPT_USE_URL,
#endif /* __MMI_MESSAGES_USE_URL__ */
	
	INBOX_NSM_PICMSG_OPT_SAVE_PIC,

	NUM_NSM_PICMSG_INBOX_OPTIONS
} MMI_NSM_PICMSG_INBOX_OPTIONS;


typedef enum
{
	INBOX_NSM_RTONE_OPT_PLAY = 0,
	INBOX_NSM_RTONE_OPT_REPLY,
	INBOX_NSM_RTONE_OPT_DELETE,

#ifdef __MMI_MESSAGES_COPY__
	INBOX_NSM_RTONE_OPT_COPY_TO_PHONE,
	INBOX_NSM_RTONE_OPT_MOVE_TO_PHONE,
#endif	/* __MMI_MESSAGES_COPY__ */

	INBOX_NSM_RTONE_OPT_DELETE_ALL,


#ifdef __MMI_MESSAGES_COPY__
	INBOX_NSM_RTONE_OPT_COPY_ALL,
	INBOX_NSM_RTONE_OPT_MOVE_ALL,
#endif	/* __MMI_MESSAGES_COPY__ */

	INBOX_NSM_RTONE_OPT_USE_NUMBER,

#if defined(__MMI_MESSAGES_USE_URL__)
	INBOX_NSM_RTONE_OPT_USE_URL,
#endif /* __MMI_MESSAGES_USE_URL__ */
	INBOX_NSM_RTONE_OPT_SAVE_RINGTONE,

	NUM_NSM_RTONE_INBOX_OPTIONS
} MMI_NSM_RTONE_INBOX_OPTIONS;

void PopulateNSMRes(void)
{
	PopulateNsmStrRes();
	PopulateNsmImgRes();
	PopulateNsmMenuItemRes();
}

void PopulateNsmStrRes(void)
{

#if !defined (__MMI_MESSAGES_EMS__)&& defined(__MMI_SMART_MESSAGE_MO__)
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_PICTURE,	"Picture",	"Insert Object Option STR_INS_OBJ_PICTURE");
	ADD_APPLICATION_STRING2 (STR_INS_OBJ_MY_PICTURE,	"My Picture",	"Insert Object Option STR_INS_OBJ_MY_PICTURE");
#endif

	ADD_APPLICATION_STRING2 (	STR_ID_NSM_PICTURE,		"Picture",	"Test picture menu item for NSM"	);
	ADD_APPLICATION_STRING2 (	STR_ID_NSM_RINGTONE,	"Ringtone",	"Test Ringtone menu item for NSM" );
	ADD_APPLICATION_STRING2 (	STR_ID_NSM_RINGTONE_PLAY,	"Play",		"Ringtone Option - Play" );
	ADD_APPLICATION_STRING2 (	STR_ID_NSM_RINGTONE_SAVE,	"Save Ringtone",		"Ringtone Option - Save" );
	ADD_APPLICATION_STRING2 (	STR_ID_NSM_RINGTONE_PLAY_MSG,	"Playing...",	" Message for ringtone play screen" );
	ADD_APPLICATION_STRING2 (	STR_ID_NSM_RINGTONE_STOP,	"Stop",	"Stop ringtone" );
	ADD_APPLICATION_STRING2 (	STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG,	"Format not supported",	"Message string for pop-up " );
	ADD_APPLICATION_STRING2 (	STR_ID_NSM_PICTURE_MESSAGES,	"My Picture",		"For Nokia smart messaging" );

	ADD_APPLICATION_STRING2 ( STR_ID_NSM_NEW_PICTURE_MESSAGE,	"New Pic Msg",	" String for new picture message ");
	ADD_APPLICATION_STRING2 ( STR_ID_NSM_NEW_RINGTONE_MESSAGE,	"New Ringtone Msg",	"String for new ringtone message");
	ADD_APPLICATION_STRING2 ( STR_ID_NSM_NEW_NORMAL_MESSAGE,	" New Msg received",		"String for new normal message ");

	ADD_APPLICATION_STRING2 ( STR_ID_NSM_PICMSG_SAVE_PICTURE,	"Save Picture",		" Save picture menu item for picture message ");
	ADD_APPLICATION_STRING2 ( STR_ID_MYPIC_ADDTEXT,	"Insert Text"	,"My Picture - insert text menu item in My picture");

	ADD_APPLICATION_STRING2 ( STR_ID_PICMSG_FORWARD,	"Forward",		"Picture message option - Forward ");
	ADD_APPLICATION_STRING2 ( STR_ID_PICMSG_EDIT_TEXT,		"Edit text",			"Picture message option - Edit ");

	ADD_APPLICATION_STRING2 ( STR_ID_NSM_SPACE_FULL,	"Space full!!",	" Space full error message");

	ADD_APPLICATION_STRING2 ( STR_ID_GLOBAL_RENAME,	"Rename",	"Rename option");
	//START  PMT JAI : 06012005 FOR NSM PHASE-II
	ADD_APPLICATION_STRING2( STR_ID_NSM2_INSERT_PICTURE, "Insert Picture", "Insert Nokia Smart Picture string");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_REMOVE_PICTURE, "Remove Picture", "Remove Nokia Smart Picture string");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_INSERT,"Insert","Insert picture");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_REPLACE,"Replace","Replace picture");

	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC1, "PIC1", "Nokia smart picture -PIC1");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC2, "PIC2", "Nokia smart picture -PIC2");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC3, "PIC3", "Nokia smart picture -PIC3");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC4, "PIC4", "Nokia smart picture -PIC4");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC5, "PIC5", "Nokia smart picture -PIC5");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC6, "PIC6", "Nokia smart picture -PIC6");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC7, "PIC7", "Nokia smart picture -PIC7");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC8, "PIC8", "Nokia smart picture -PIC8");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC9, "PIC9", "Nokia smart picture -PIC9");
	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC10, "PIC10", "Nokia smart picture -PIC10");

	ADD_APPLICATION_STRING2( STR_ID_NSM2_PIC_LIST,"Picture List","Nokia Smart message : picture list");
	ADD_APPLICATION_STRING2( STR_ID_NSM_INVALID_PIC,"Invalid picture","NSM:Invalid picture");

}	/* End populateNsmStrRes */



void PopulateNsmImgRes(void)
{

#if defined(__MMI_MYPICTURE__)
	ADD_APPLICATION_IMAGE2 ( IMG_NSM_MYPIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Message\\\\MyPicture.PBM",
							 " Image for My Picture"
						   );
#endif /*__MMI_MYPICTURE__ */

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

	ADD_APPLICATION_IMAGE2 ( IMG_NSM01_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic1.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM02_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic2.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM03_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic3.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM04_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic4.bmp",
							 " Image for My Picture"
						   );
	ADD_APPLICATION_IMAGE2 ( IMG_NSM05_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic5.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM06_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic6.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM07_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic7.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM08_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic8.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM09_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic9.bmp",
							 " Image for My Picture"
						   );

	ADD_APPLICATION_IMAGE2 ( IMG_NSM010_PIC,
							 CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\NSM2\\\\Pic10.bmp",
							 " Image for My Picture"
						   );

#endif /* __MMI_SMART_MESSAGE_MO__*/

}	/*End populateNsmImgRes*/


void PopulateNsmMenuItemRes(void)
{

#if defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

	/* Menu Resources for MO/MT Smart message */

ADD_APPLICATION_MENUITEM (( MENU_ID_NSM_RINGTONE, 0, NUM_NSM_RTONE_INBOX_OPTIONS,
									MENU_ID_NSM_RINGTONE_PLAY,
									MENU_ID_NSM_RINGTONE_REPLY,
									MENU_ID_NSM_RINGTONE_DELETE,
							
							#ifdef __MMI_MESSAGES_COPY__
								MENUID_NSM_RTONE_COPY_TO_PHONE,
								MENUID_NSM_RTONE_MOVE_TO_PHONE,
							#endif	/* __MMI_MESSAGES_COPY__ */
							
								MENU_ID_NSM_RTONE_DELETE_ALL,
							
							
							#ifdef __MMI_MESSAGES_COPY__
								MENUID_NSM_RTONE_COPY_ALL,
								MENUID_NSM_RTONE_MOVE_ALL,
							#endif	/* __MMI_MESSAGES_COPY__ */

								MENU_ID_NSM_RTONE_USE_NUMBER,
							#if defined(__MMI_MESSAGES_USE_URL__)
									MENU_ID_RINGTONE_OPT_USE_URL,
							#endif	/* __MMI_MESSAGES_USE_URL__ */
								
									MENU_ID_NSM_RINGTONE_SAVE,
							
							SHOW,NONMOVEABLE|INSERTABLE,DISP_LIST,STR_ID_NSM_RINGTONE,NULL));


	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_RINGTONE_PLAY,MENU_ID_NSM_RINGTONE,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_ID_NSM_RINGTONE_PLAY,NULL));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_RINGTONE_REPLY,MENU_ID_NSM_RINGTONE,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_REPLY,IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_RINGTONE_SAVE,MENU_ID_NSM_RINGTONE,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_ID_NSM_RINGTONE_SAVE,NULL));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_RINGTONE_DELETE,MENU_ID_NSM_RINGTONE,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_DELETE,NULL));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_RTONE_DELETE_ALL,MENU_ID_NSM_RINGTONE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_DELETE_ALL,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_RTONE_USE_NUMBER,MENU_ID_NSM_RINGTONE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_USE_NUMBER_MENUENTRY,
								IMG_SMS_COMMON_NOIMAGE));

#if defined(__MMI_MESSAGES_USE_URL__)
	ADD_APPLICATION_MENUITEM((MENU_ID_RINGTONE_OPT_USE_URL,
									MENU_ID_NSM_RINGTONE,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_URL_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_MESSAGES_USE_URL__ */

#ifdef __MMI_MESSAGES_COPY__

	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_COPY_TO_PHONE,
									MENU_ID_NSM_RINGTONE, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_COPY_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_COPY_ALL,
									MENU_ID_NSM_RINGTONE, 2,
						 			MENUID_NSM_RTONE_COPY_ALL_FROM_SIM,
						 			MENUID_NSM_RTONE_COPY_ALL_FROM_PHONE,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_COPY_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_COPY_ALL_FROM_SIM,
									MENUID_NSM_RTONE_COPY_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_COPY_ALL_FROM_PHONE,
									MENUID_NSM_RTONE_COPY_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_MOVE_TO_PHONE,
									MENU_ID_NSM_RINGTONE, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_MOVE_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_MOVE_ALL,
									MENU_ID_NSM_RINGTONE, 2,
						 			MENUID_NSM_RTONE_MOVE_ALL_FROM_SIM,
						 			MENUID_NSM_RTONE_MOVE_ALL_FROM_PHONE,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_MOVE_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_MOVE_ALL_FROM_SIM,
									MENUID_NSM_RTONE_MOVE_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((MENUID_NSM_RTONE_MOVE_ALL_FROM_PHONE,
									MENUID_NSM_RTONE_MOVE_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));	
#endif	/* __MMI_MESSAGES_COPY__ */

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICTURE_MESSAGE,0,NUM_NSM_PICMSG_INBOX_OPTIONS,
								MENU_ID_NSM_PICMSG_REPLY,
								MENU_ID_NSM_PICMSG_DELETE,
								MENU_ID_NSM_PICMSG_EDIT,
								MENU_ID_NSM_PICMSG_FORWARD,
							#ifdef __MMI_MESSAGES_COPY__
								MENUID_INBOX_PICMSG_OPT_COPY_TO_PHONE,
								MENUID_INBOX_PICMSG_OPT_MOVE_TO_PHONE,
							#endif	/* __MMI_MESSAGES_COPY__ */

							#ifdef __MMI_MESSAGES_CHAT__
								MENUID_INBOX_PICMSG_OPT_CHAT,
							#endif	/* __MMI_MESSAGES_CHAT__ */

								MENU_ID_NSM_PICMSG_DELETE_ALL,

							#ifdef __MMI_MESSAGES_COPY__
								MENUID_INBOX_PICMSG_OPT_COPY_ALL,
								MENUID_INBOX_PICMSG_OPT_MOVE_ALL,
							#endif	/* __MMI_MESSAGES_COPY__ */

								MENU_ID_NSM_PICMSG_USE_NUMBER,
							#if defined(__MMI_MESSAGES_USE_URL__)
								MENU_ID_PICMSG_OPT_USE_URL,
							#endif	/* __MMI_MESSAGES_USE_URL__ */
                                MENU_ID_NSM_PICMSG_SAVE_PICTURE,

								SHOW,NONMOVEABLE|INSERTABLE, DISP_LIST,
						 		STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICMSG_REPLY,MENU_ID_NSM_PICTURE_MESSAGE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_REPLY, 
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICMSG_FORWARD,MENU_ID_NSM_PICTURE_MESSAGE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_ID_PICMSG_FORWARD,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICMSG_EDIT,MENU_ID_NSM_PICTURE_MESSAGE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_EDIT,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICMSG_DELETE,MENU_ID_NSM_PICTURE_MESSAGE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_DELETE,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICMSG_DELETE_ALL,MENU_ID_NSM_PICTURE_MESSAGE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_DELETE_ALL,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICMSG_USE_NUMBER,MENU_ID_NSM_PICTURE_MESSAGE,0,
								SHOW, MOVEABLEWITHINPARENT,DISP_LIST,STR_USE_NUMBER_MENUENTRY,
								IMG_SMS_COMMON_NOIMAGE));

#if defined(__MMI_MESSAGES_USE_URL__)
	ADD_APPLICATION_MENUITEM((MENU_ID_PICMSG_OPT_USE_URL,
									MENU_ID_NSM_PICTURE_MESSAGE,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_USE_URL_MENUENTRY,	IMG_SMS_COMMON_NOIMAGE));
#endif /* __MMI_MESSAGES_USE_URL__ */


	ADD_APPLICATION_MENUITEM((MENU_ID_NSM_PICMSG_SAVE_PICTURE,MENU_ID_NSM_PICTURE_MESSAGE,0,SHOW,
								MOVEABLEWITHINPARENT,DISP_LIST,STR_ID_NSM_PICMSG_SAVE_PICTURE,
								IMG_SMS_COMMON_NOIMAGE));

#if defined(__MMI_MESSAGES_CHAT__)
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_OPT_CHAT,
									MENU_ID_NSM_PICTURE_MESSAGE,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_CHAT_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif	/* __MMI_MESSAGES_CHAT__ */

#ifdef __MMI_MESSAGES_COPY__

	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_OPT_COPY_TO_PHONE,
									MENU_ID_NSM_PICTURE_MESSAGE, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_COPY_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_OPT_COPY_ALL,
									MENU_ID_NSM_PICTURE_MESSAGE, 2,
						 			MENUID_INBOX_PICMSG_COPY_ALL_FROM_SIM,
						 			MENUID_INBOX_PICMSG_COPY_ALL_FROM_PHONE,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_COPY_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_COPY_ALL_FROM_SIM,
									MENUID_INBOX_PICMSG_OPT_COPY_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_COPY_ALL_FROM_PHONE,
									MENUID_INBOX_PICMSG_OPT_COPY_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_OPT_MOVE_TO_PHONE,
									MENU_ID_NSM_PICTURE_MESSAGE, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_MOVE_TO_PHONE, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_OPT_MOVE_ALL,
									MENU_ID_NSM_PICTURE_MESSAGE, 2,
						 			MENUID_INBOX_PICMSG_MOVE_ALL_FROM_SIM,
						 			MENUID_INBOX_PICMSG_MOVE_ALL_FROM_PHONE,
						 			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SMS_MOVE_ALL, IMG_SMS_COMMON_NOIMAGE));
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_MOVE_ALL_FROM_SIM,
									MENUID_INBOX_PICMSG_OPT_MOVE_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_SIM, IMG_SMS_COMMON_NOIMAGE));	
	ADD_APPLICATION_MENUITEM((MENUID_INBOX_PICMSG_MOVE_ALL_FROM_PHONE,
									MENUID_INBOX_PICMSG_OPT_MOVE_ALL, 0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_SMS_FROM_PHONE, IMG_SMS_COMMON_NOIMAGE));	
#endif	/* __MMI_MESSAGES_COPY__ */

	ADD_APPLICATION_MENUITEM((MENU_ID_PIC_MSG_EDIT_TEXT_OPTION,NULL,2,
								MENU_ID_PIC_MSG_EDIT_TEXT_DONE,
								MENU_ID_PIC_MSG_EDIT_TEXT_INPUT_METHOD,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 		STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_PIC_MSG_EDIT_TEXT_DONE,MENU_ID_PIC_MSG_EDIT_TEXT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_DONE,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_PIC_MSG_EDIT_TEXT_INPUT_METHOD,MENU_ID_PIC_MSG_EDIT_TEXT_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_INPUT_METHOD,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SAVE_PIC_OPTION,NULL,2,
								MENU_ID_SAVE_PIC_DONE,
								MENU_ID_SAVE_PIC_INPUT_METHOD,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_OPTIONS, 
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SAVE_PIC_DONE,MENU_ID_SAVE_PIC_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_DONE,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SAVE_PIC_INPUT_METHOD,MENU_ID_SAVE_PIC_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_INPUT_METHOD,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SAVE_RINGTONE_OPTION,NULL,2,
								MENU_ID_SAVE_RINGTONE_DONE,
								MENU_ID_SAVE_RINGTONE_INPUT_METHOD,
								SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 		STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SAVE_RINGTONE_DONE,MENU_ID_SAVE_RINGTONE_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_DONE,
								IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((MENU_ID_SAVE_RINGTONE_INPUT_METHOD,MENU_ID_SAVE_RINGTONE_OPTION,0,
								SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_GLOBAL_INPUT_METHOD,
								IMG_SMS_COMMON_NOIMAGE));

#endif /* __MMI_SMART_MESSAGE_MT__ || __MMI_SMART_MESSAGE_MO__ */

#if defined(__MMI_MYPICTURE__) || defined(__MMI_SMART_MESSAGE_MT__)

	/* Menu Resources for My Picture Menu item only */
	ADD_APPLICATION_MENUITEM( (		MENU_ID_MY_PICTURE,
									MAIN_MENU_MESSAGES_MENUID,
									2,
									MENU_ID_MYPIC_DONE,
									MENU_ID_MYPIC_ADDTEXT,
									SHOW,
									NONMOVEABLE,
									DISP_LIST,
									STR_ID_NSM_PICTURE_MESSAGES,
									IMG_NSM_MYPIC
								)
							 );


	ADD_APPLICATION_MENUITEM((		MENU_ID_MYPIC_DONE,
									MENU_ID_MY_PICTURE,
									3,
									MENU_ID_MYPIC_SEND_ONLY,
									MENU_ID_MYPIC_SEND_TO_MANY,
									MENU_ID_MYPIC_SEND_BY_GROUP,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_DONE, IMG_SMS_COMMON_NOIMAGE));
			/* My Picture - Add text */
	ADD_APPLICATION_MENUITEM( (		MENU_ID_MYPIC_ADDTEXT,
									MENU_ID_MY_PICTURE,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_ID_MYPIC_ADDTEXT, IMG_SMS_COMMON_NOIMAGE
								)
							);



    ADD_APPLICATION_MENUITEM( (		MENU_ID_MYPIC_SEND_ONLY,
									MENU_ID_MYPIC_DONE,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SEND_ONLY_MENU_ITEM, IMG_SMS_COMMON_NOIMAGE
								)
							);

	ADD_APPLICATION_MENUITEM( (		MENU_ID_MYPIC_SEND_TO_MANY,
									MENU_ID_MYPIC_DONE,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SENDTOMANY_MENUENTRY, IMG_SMS_COMMON_NOIMAGE
								)
							);

	ADD_APPLICATION_MENUITEM( (		MENU_ID_MYPIC_SEND_BY_GROUP,
									MENU_ID_MYPIC_DONE,
									0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_SENDBYGROUP_MENUENTRY, IMG_SMS_COMMON_NOIMAGE
								)
							);

	ADD_APPLICATION_MENUITEM( (		MENU_ID_MYPIC_INSERT_TEXT_OPTION,
									NULL,2,
									MENU_ID_MYPIC_INSERT_TEXT_DONE,
									MENU_ID_MYPIC_INSERT_TEXT_INPUT_METHOD,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
						 			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE
								)
							);

	ADD_APPLICATION_MENUITEM( (		MENU_ID_MYPIC_INSERT_TEXT_DONE,
									MENU_ID_MYPIC_INSERT_TEXT_OPTION,
									0,SHOW,MOVEABLEWITHINPARENT,
									DISP_LIST,STR_GLOBAL_DONE,
									IMG_SMS_COMMON_NOIMAGE
								)
							);

	ADD_APPLICATION_MENUITEM( (		MENU_ID_MYPIC_INSERT_TEXT_INPUT_METHOD,
									MENU_ID_MYPIC_INSERT_TEXT_OPTION,
									0,SHOW,MOVEABLEWITHINPARENT,
									DISP_LIST,STR_GLOBAL_INPUT_METHOD,
									IMG_SMS_COMMON_NOIMAGE
								)
							);

#endif /* __MMI_MYPICTURE__ */

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

	/* Menu Resources for MO Smart message only */

	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INS_OBJ, 
									EMS_ED_OPTIONS_MENU_ID,	2,
									EMS_INS_OBJ_PICTURE,
									EMS_INS_OBJ_MY_PICTURE,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_OPT_INS_OBJECT_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));


	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_PICTURE, 
									EMS_ED_OPT_INS_OBJ,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_PICTURE, IMG_SMS_COMMON_NOIMAGE));

	ADD_APPLICATION_MENUITEM((EMS_INS_OBJ_MY_PICTURE, 
									EMS_ED_OPT_INS_OBJ,	0, 
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_INS_OBJ_MY_PICTURE, IMG_SMS_COMMON_NOIMAGE));


	ADD_APPLICATION_MENUITEM((MENU_ID_NSM2_INSERT_PIC, EMS_ED_OPTIONS_MENU_ID,
							0,  // No child : rest of the menu is part of SMS
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_ID_NSM2_INSERT_PICTURE, IMG_SMS_COMMON_NOIMAGE));



	ADD_APPLICATION_MENUITEM((NSM2_ED_OPTIONS_MENU_ID, /* Set as parent when picture is inserted*/
									0,	NUM_MESSAGES_EDIT_MENU, 
									EMS_ED_OPT_DONE,
								#ifdef __MMI_DUAL_SIM_MASTER__
									MENU_MTPNP_EMS_ED_OPT_DONE,
								#endif /* __MMI_DUAL_SIM_MASTER__ */
								#if defined(__MMI_MESSAGES_TEMPLATE__)
									EMS_ED_OPT_USE_TEMPLATES,
								#endif
								#if !defined(__MMI_MESSAGES_EMS__) && defined(__MMI_SMART_MESSAGE_MO__) 
									MENU_ID_NSM2_REMOVE_PIC,
								#endif										
									EMS_ED_OPT_INPUT_METHOD,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));



	ADD_APPLICATION_MENUITEM((MENU_ID_NSM2_REMOVE_PIC, NSM2_ED_OPTIONS_MENU_ID,
							0,  // No child : rest of the menu is part of SMS
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_ID_NSM2_REMOVE_PICTURE, IMG_SMS_COMMON_NOIMAGE));


	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_INPUT_METHOD, NSM2_ED_OPTIONS_MENU_ID,
							0,  // No child : rest of the menu is part of SMS
							SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							STR_GLOBAL_INPUT_METHOD, IMG_SMS_COMMON_NOIMAGE));
								
#if defined(__MMI_MESSAGES_TEMPLATE__)
	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_USE_TEMPLATES, 
									NSM2_ED_OPTIONS_MENU_ID,	0,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_GLOBAL_USE_TEMPLATE, IMG_SMS_COMMON_NOIMAGE));
#endif // defined(__MMI_MESSAGES_TEMPLATE__)	


	#if defined(__MMI_TEXT_FORMAT_WITHOUT_SIZE__)
	ADD_APPLICATION_MENUITEM((MENU_EMS_FORMATING_TEXT_ID, 
									NSM2_ED_OPTIONS_MENU_ID,3,  
									MENU_EMS_TEXT_STYLE_ID,
									MENU_EMS_ALIGNMENT_ID,
									MENU_EMS_NEW_PARAGRAPH_ID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_EMS_FORMATING_TEXT_ID, IMG_SMS_COMMON_NOIMAGE));
	
	#else	
	ADD_APPLICATION_MENUITEM((MENU_EMS_FORMATING_TEXT_ID, 
									NSM2_ED_OPTIONS_MENU_ID,4,  
									MENU_EMS_TEXT_SIZE_ID,
									MENU_EMS_TEXT_STYLE_ID,
									MENU_EMS_ALIGNMENT_ID,
									MENU_EMS_NEW_PARAGRAPH_ID,
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
									STR_EMS_FORMATING_TEXT_ID, IMG_SMS_COMMON_NOIMAGE));
#endif


	ADD_APPLICATION_MENUITEM((EMS_ED_OPT_DONE, 
									NSM2_ED_OPTIONS_MENU_ID, NUM_MESSAGES_INBOXSEND_MENU,
									SEND_OPT_SEND_ONLY_MENUID,
									SEND_OPT_SAVE_AND_SEND_MENUID,
									SEND_OPT_SAVE_MENUID,
								#if defined(__MMI_MESSAGES_SEND_TO_MANY__)	
									SEND_OPT_SEND_TO_MANY_MENUID,
#endif
								#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
									SEND_OPT_SEND_BY_GROUP_MENUID,
#endif
									SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
								STR_GLOBAL_DONE, IMG_SMS_COMMON_NOIMAGE));

#endif /* __MMI_SMART_MESSAGE_MO__*/

}

#endif	/* __MMI_SMART_MESSAGE_MT__ || __MMI_SMART_MESSAGE_MO__ || __MMI_MYPICTURE__ */

#endif	/* DEVELOPER_BUILD_FIRST_PASS : !! Don't remove */

