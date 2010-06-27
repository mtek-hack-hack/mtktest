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

	FILENAME	: Res_.c

  	PURPOSE		: Populate Resource for 

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-11-2003

**************************************************************/
#include "MMI_features.h"
#include "CustomCfg.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "SATResDef.h"
#include "InfoNumResDef.h"

//micha0601, NOTE, checkin all main trunk branches
#include "ServiceDefs.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/**************************************************************

	FUNCTION NAME		: PopulateSATRes

  	PURPOSE				: Populates the respurces for SAT

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: nil

	REMARKS				: nil

**************************************************************/

void PopulateSATRes(void)
{
	/* Services Resources  to be put in separate file*/

	ADD_APPLICATION_STRING2(SERVICES_TITLE_STRING_ID,"Services","Title for Services Menu");

#ifdef WAP_SUPPORT
	ADD_APPLICATION_STRING2(SERVICES_WAP_STRING_ID,"WAP","WAP Menu Item String");

#if defined (JATAAYU_SUPPORT)
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
	ADD_APPLICATION_MENUITEM((SERVICES_WAP_MENU_ID, MAIN_MENU_SERVICES_MENUID,
#endif
#ifndef __MMI_UNIFIED_MESSAGE__			
		#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
        7,
		#else
		6,
		#endif
#else
		#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
			6,
        #else
			5,
        #endif
#endif
			MENU_ID_BRW_HOMEPAGE,
			MENU_ID_BRW_BOOKMARKS,
			MENU_ID_BRW_RECENT_PAGES,
			MENU_ID_BRW_ENTER_ADDRESS,
#ifndef __MMI_UNIFIED_MESSAGE__	
			MENU_ID_BRW_SERVICE_INBOX,
#endif
#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
		    MENU_ID_BRW_SAVED_PAGES,
#endif
			MENU_ID_BRW_SETTINGS_1,
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
			SHOW,NONMOVEABLE|SHORTCUTABLE,DISP_LIST,SERVICES_WAP_STRING_ID,SERVICES_WAP_IMAGE_ID));
#endif
#elif defined (__MMI_BROWSER_2__)
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
	ADD_APPLICATION_MENUITEM2((SERVICES_WAP_MENU_ID, MAIN_MENU_SERVICES_MENUID,
#endif
/*Multiple Download patch 220807*//*START*/
			MENU_ID_BRW_REN_PAGE_DOWNLOADS,
/*Multiple Download patch 220807*//*END*/
			MENU_ID_BRW_HOMEPAGE,
#ifdef __MMI_VBOOKMARK__
			MENU_ID_BRW_BOOKMARKS,
#endif /*__MMI_VBOOKMARK__*/
			MENU_ID_BRW_ENTER_ADDRESS,
			MENU_ID_BRW_OPEN_FILE,
			MENU_ID_BRW_LAST_WEB_ADDR,
			MENU_ID_BRW_RECENT_PAGES,
			MENU_ID_BRW_STORED_PAGES,
			MENU_ID_BRW_PUSH_INBOX,
			MENU_ID_BRW_SETTINGS,
			MENU_ITEM_END,
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
			SHOW,NONMOVEABLE|SHORTCUTABLE,DISP_LIST,SERVICES_WAP_STRING_ID,SERVICES_WAP_IMAGE_ID));
#endif
#else
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
	ADD_APPLICATION_MENUITEM((SERVICES_WAP_MENU_ID,MAIN_MENU_SERVICES_MENUID,0,SHOW,NONMOVEABLE|SHORTCUTABLE,DISP_LIST,
								SERVICES_WAP_STRING_ID,SERVICES_WAP_IMAGE_ID));
#endif /* __MMI_OP01_MENU_9MATRIX__ */
#endif
#endif

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
	ADD_APPLICATION_MENUITEM2((SERVICES_DATA_CONNECT_MAIN_MENU_ID,MAIN_MENU_SERVICES_MENUID,
#endif
                               SERVICES_DATA_CONNECT_MENU_ID,
#ifdef __MMI_GPRS_FEATURES__
                               SERVICES_DATA_CONNECT_GPRS_MENU_ID,
#endif
#ifdef __MMI_WLAN_FEATURES__
                               MENU_ID_WLAN_MAIN,
#endif  
                              
                               MENU_ITEM_END,
                               SHOW,NONMOVEABLE,DISP_LIST,
                               STR_GLOBAL_DATA_ACCOUNT,SERVICES_DATA_CONNECT_IMAGE_ID));

	ADD_APPLICATION_STRING2(SERVICES_DATA_CONNECT_MAIN_STRING_ID,"Data Account","Data Connect Menu Item String");	
	ADD_APPLICATION_MENUITEM((SERVICES_INFO_NUM_MENU_ID,MAIN_MENU_SERVICES_MENUID,0,SHOW,NONMOVEABLE,DISP_LIST,
								SERVICES_INFO_NUM_STRING_ID,SERVICES_INFO_NUM_IMAGE_ID));
	
	ADD_APPLICATION_STRING2(SERVICES_INFO_NUM_STRING_ID,"Information Num","Title for Information Number Menu");
	ADD_APPLICATION_STRING2(SERVICES_INFO_DIAL_STRING_ID,"Dial","Title for Information Number Menu");
	ADD_APPLICATION_STRING2(SERVICES_INFO_PREMIUM_STRING_ID,"Do you want to dial out with a premium rate?","Premim Number Message");
	ADD_APPLICATION_STRING2(SERVICES_INFO_ROAMING_STRING_ID,"Sorry!!\nThis number is not accessible when roaming!!","Roaming Message");

	

	ADD_APPLICATION_IMAGE2(SERVICES_TITLE_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PNG","Title Icon for Services Menu");
	ADD_APPLICATION_IMAGE2(SERVICES_WAP_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SB_WAP.PBM","WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(SERVICES_DATA_CONNECT_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\submenu\\\\services\\\\DataAccount\\\\SB_DATA.PBM","Data Connect Menu Item Icon");
	ADD_APPLICATION_IMAGE2(SAT_WAIT_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\progress\\\\progress"__MMI_RES_TYPE_POPUP_SCREEN__, "Image Diaplayed in Please Wait Screen");
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
	ADD_APPLICATION_IMAGE2(SAT_TITLE_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\SAT\\\\SB_SIM_1.bmp","SAT1 Menu Item Icon");
	ADD_APPLICATION_IMAGE2(SAT_TITLE_IMAGE_ID_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\SAT\\\\SB_SIM_2.bmp","SAT2 Menu Item Icon");
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
	ADD_APPLICATION_IMAGE2(SAT_TITLE_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Services\\\\SIMToolKit\\\\SB_SIM.PBM","SAT Menu Item Icon");
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
//MTK Leo add 0929, for information number menu icon
	ADD_APPLICATION_IMAGE2(SERVICES_INFO_NUM_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Services\\\\SB_IF.PBM","Information Number Menu Item Icon");
//MTK Leo end

//MTK Leo end

	//ADD_APPLICATION_IMAGE2(SAT_SEND_SS_IMAGE_ID,"..\\\\Images\\\\SMS\\\\MO\\\\MOMessage.gif","Default Image displayed when Sending SS.");
	//ADD_APPLICATION_IMAGE2(SAT_SS_SUCCESS_IMAGE_ID,"..\\\\Images\\\\SAT\\\\progress.gif", "Image Displayed when SS Success");
	//ADD_APPLICATION_IMAGE2(SAT_SS_ERROR_IMAGE_ID,"..\\\\Images\\\\SAT\\\\progress.gif", "Image Displayed when SS Error");

	//ADD_APPLICATION_IMAGE2(SAT_SEND_USSD_IMAGE_ID,"..\\\\Images\\\\SMS\\\\MO\\\\MOMessage.gif","Default Image displayed when Sending SS.");
	//ADD_APPLICATION_IMAGE2(SAT_USSD_SUCCESS_IMAGE_ID,"..\\\\Images\\\\SAT\\\\progress.gif", "Image Displayed when USSD Success");
	//ADD_APPLICATION_IMAGE2(SAT_USSD_ERROR_IMAGE_ID,"..\\\\Images\\\\SAT\\\\progress.gif", "Image Displayed when USSD Error");

	//ADD_APPLICATION_IMAGE2(SAT_PLAY_TONE_IMAGE_ID,"..\\\\Images\\\\SAT\\\\progress.gif", "Image Displayed when Playing Tone");

	//ADD_APPLICATION_IMAGE2(SAT_OPERATION_CHANGED_BY_SIM_IMAGE_ID,"..\\\\Images\\\\EmptyImage.bmp", "Image Displayed when Operation changed by SIM");
	//ADD_APPLICATION_IMAGE2(SAT_NUM_CHANGED_BY_SIM_IMAGE_ID,"..\\\\Images\\\\EmptyImage.bmp", "Image Displayed when Number changed by SIM");
	//ADD_APPLICATION_IMAGE2(SIM_MEM_PROBLEM_IMAGE_ID,"..\\\\Images\\\\EmptyImage.bmp", "Image Displayed when Memory Problem");
	//ADD_APPLICATION_IMAGE2(SIM_SECRET_CODE_REJ_IMAGE_ID,"..\\\\Images\\\\EmptyImage.bmp", "Image Displayed when Secret Code Rejected");
	//ADD_APPLICATION_IMAGE2(SIM_TECH_PROBLEM_IMAGE_ID,"..\\\\Images\\\\EmptyImage.bmp", "Image Displayed when Technical Problem");

	ADD_APPLICATION_STRING2(SAT_WAIT_STRING_ID,"Please Wait!","String displayed when waiting for response from SIM.");

	ADD_APPLICATION_STRING2(SAT_SETUP_CALL_CONF_STRING_ID,"Proceed With Call?","String in Setup Call Confirmation Screen");

	ADD_APPLICATION_STRING2(SAT_SEND_SMS_CONF_STRING_ID,"Send SMS","String in Sending SMS Confirmation Screen");
	ADD_APPLICATION_STRING2(SAT_SEND_SMS_STRING_ID,"Sending Short Message ....","Default String displayed when Sending SMS.");
	ADD_APPLICATION_STRING2(SAT_SMS_ERROR_STRING_ID,"Error Sending Short Message!!!","String displayed when SMS Error.");
	ADD_APPLICATION_STRING2(SAT_SMS_SUCCESS_STRING_ID,"Short Message Sent!","String displayed when SMS Sent.");

	ADD_APPLICATION_STRING2(SAT_SEND_SS_STRING_ID,"Sending SS ....","Default String displayed when Sending SS.");
	ADD_APPLICATION_STRING2(SAT_SS_ERROR_STRING_ID,"Error Sending SS!!!","String displayed when SS Error.");
	ADD_APPLICATION_STRING2(SAT_SS_SUCCESS_STRING_ID,"SS Sent!","String displayed when SS Sent.");

	ADD_APPLICATION_STRING2(SAT_SEND_USSD_STRING_ID,"Sending USSD ....","Default String displayed when Sending USSD.");
	ADD_APPLICATION_STRING2(SAT_USSD_ERROR_STRING_ID,"Error Sending USSD!!!","String displayed when USSD Error.");
	ADD_APPLICATION_STRING2(SAT_USSD_SUCCESS_STRING_ID,"USSD Sent!","String displayed when USSD Sent.");
	ADD_APPLICATION_STRING2(SAT_USSD_ABORT_STRING_ID,"USSD Abort!","String displayed when USSD Abort.");

//micha1111, michaSATc3, #212
	ADD_APPLICATION_STRING2(SAT_SEND_DTMF_CONF_STRING_ID,"Send DTMF","String in Sending DTMF Confirmation Screen");
	ADD_APPLICATION_STRING2(SAT_SEND_DTMF_STRING_ID,"Sending DTMF....","Default String displayed when Sending DTMF.");
	ADD_APPLICATION_STRING2(SAT_DTMF_ERROR_STRING_ID,"Error Sending DTMF!!!","String displayed when DTMF Error.");
	ADD_APPLICATION_STRING2(SAT_DTMF_SUCCESS_STRING_ID,"DTMF Sent!","String displayed when DTMF Sent.");

	/* diamond, 2005/01/11 LAUNCH BROWSER confirmation string*/
	ADD_APPLICATION_STRING2(SAT_LAUNCH_BROWSER_CONF_STRING_ID,"Make GPRS connection for browser?","String in Launch Browser Confirmation Screen");

//micha1119
//For next action indicator
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_REFRESH_STRING_ID,"Refresh","Refresh");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_MORE_TIME_STRING_ID,"More Time","More Time");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_POLL_INTERVAL_STRING_ID,"Poll Interval","Poll Interval");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_POLLING_OFF_STRING_ID,"Poll Off","Poll Off");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SETUP_EVENT_LIST_STRING_ID,"Setup Event List","Setup Event List");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SETUP_CALL_STRING_ID,"Setup Call","Setup Call");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SEND_SS_STRING_ID,"Send SS","Send SS");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SEND_USSD_STRING_ID,"Send USSD","Send USSD");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SEND_SMS_STRING_ID,"Send SMS","Send SMS");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SEND_DTMF_STRING_ID,"Send DTMF","Send DTMF");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_LAUNCH_BROWSER_STRING_ID,"Launch Browser","Launch Browser");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_PLAY_TONE_STRING_ID,"Play Tone","Play Tone");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_DISPLAY_TEXT_STRING_ID,"Display Text","Display Text");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_GET_INKEY_STRING_ID,"Get Inkey","Get Inkey");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_GET_INPUT_STRING_ID,"Get Input","Get Input");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SELECT_ITEM_STRING_ID,"Select Item","Select Item");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SETUP_MENU_STRING_ID,"Setup Menu","Setup Menu");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_PROVIDE_LOCAL_INFO_STRING_ID,"Provide Local Info","Provide Local Info");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_TIMER_MANAGEMENT_STRING_ID,"Timer Management","Timer Management");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SETUP_IDLE_TEXT_STRING_ID,"Setup Idle Mode Text","Setup Idle Mode Text");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_PERFORM_CARD_APDU_STRING_ID,"Peform Card APDU","Peform Card APDU");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_POWER_ON_CARD_STRING_ID,"Power On Card","Power On Card");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_POWER_OFF_CARD_STRING_ID,"Power Off Card","Power Off Card");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_GET_READER_STATUS_STRING_ID,"Get Reader Status","Get Reader Status");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_RUN_AT_COMMAND_STRING_ID,"Run AT Command","Run AT Command");
//	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_LANGUAGE_NOTIFICATION_STRING_ID,"Language Notification","Language Notification");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_OPEN_CHANNEL_STRING_ID,"Open Channel","Open Channel");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_CLOSE_CHANNEL_STRING_ID,"Close Channel","Close Channel");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_RECEIVE_DATA_STRING_ID,"Receive Data","Receive Data");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_SEND_DATA_STRING_ID,"Send Data","Send Data");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_GET_CHANNEL_STATUS_STRING_ID,"Get Channel Status","Get Channel Status");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_RESERVED_FOR_TIA_STRING_ID,"Reserved for TIA/EIA-136","Reserved for TIA/EIA-136");
	ADD_APPLICATION_STRING2(SAT_NEXT_ACTION_END_SESSION_STRING_ID,"End of Proactive Session","End of Proactive Session");

//michaSATc3 end

#ifdef __SATCE__
//NOTE*************************
//           Remember to checkin ref_list.txt
//NOTE*************************
	ADD_APPLICATION_STRING2(SAT_OPEN_CHANNEL_STRING_ID,"Open Channel","Default Open Channel String");
	ADD_APPLICATION_STRING2(SAT_OPEN_CHANNEL_CONF_STRING_ID,"Open Channel","Open Channel Query Strinig");
	ADD_APPLICATION_STRING2(SAT_OPEN_CHANNEL_SUCCESS_STRING_ID,"Channel Opened!","Channel Opened");
	ADD_APPLICATION_STRING2(SAT_OPEN_CHANNEL_FAIL_STRING_ID,"Open Channel Failed!","Open Channel Failed");	

	ADD_APPLICATION_STRING2(SAT_SEND_DATA_STRING_ID,"Send Data","Default Send Data String");
	ADD_APPLICATION_STRING2(SAT_SEND_DATA_CONF_STRING_ID,"Send Data","Send Data Query Strinig");
	ADD_APPLICATION_STRING2(SAT_SEND_DATA_SUCCESS_STRING_ID,"Data Sent!","Send Data Success");
	ADD_APPLICATION_STRING2(SAT_SEND_DATA_FAIL_STRING_ID,"Send Datal Failed!","Send Data Failed");	

	ADD_APPLICATION_STRING2(SAT_RECV_DATA_STRING_ID,"Receive Data","Default Receive Data String");
	ADD_APPLICATION_STRING2(SAT_RECV_DATA_CONF_STRING_ID,"Receive Data","Receive Data Query Strinig");
	ADD_APPLICATION_STRING2(SAT_RECV_DATA_SUCCESS_STRING_ID,"Receive Sent!","Receive Data Success");
	ADD_APPLICATION_STRING2(SAT_RECV_DATA_FAIL_STRING_ID,"","Receive Data Failed");	
#endif

	ADD_APPLICATION_STRING2(SAT_PLAY_TONE_STRING_ID,"Playing SIM Tone....","String displayed when Playing Tone.");

	//ADD_APPLICATION_STRING2(SAT_OPERATION_CHANGED_BY_SIM_STRING_ID,"Operation changed by SIM", "String Displayed when Operation changed by SIM");
	ADD_APPLICATION_STRING2(SAT_NUM_CHANGED_BY_SIM_STRING_ID,"Number changed to ", "String Displayed when Number changed by SIM");
	//ADD_APPLICATION_STRING2(SIM_MEM_PROBLEM_STRING_ID,"Memory Problem", "String Displayed when Memory Problem");
	//ADD_APPLICATION_STRING2(SIM_SECRET_CODE_REJ_STRING_ID,"Secret Code Rejected", "String Displayed when Secret Code Rejected");
	//ADD_APPLICATION_STRING2(SIM_TECH_PROBLEM_STRING_ID,"Technical Problem", "String Displayed when Technical Problem");

	ADD_APPLICATION_STRING2(SAT_MENU_STRING_ID,"SIM Toolkit","Setup Menu");
//micha1217
	ADD_APPLICATION_STRING2(SERVICES_NOT_PROVIDED_STRING_ID,"SIM Not Support!","String displayed when no service avaliable.");
//micha0702, remember to change ref_list.txt
	ADD_APPLICATION_STRING2(SAT_GET_INPUT_LENGTH_NOT_ENOUGH,"Please input at least","Text of Help Button");
}

#endif


