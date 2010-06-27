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

	FILENAME	: Res_Calls.c

  	PURPOSE		: Populate Resource for Calls

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-15-2003

**************************************************************/
#include "MMI_features.h" //__MMI_UI_CALL_LOG_IN_TAB_PANE__
#include "CustomCfg.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "SettingResDef.h"
#include "PhoneBookResDef.h"
#include "CallsResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

/*************************************************************************

	FUNCTION NAME		: AddCallLogApplicationRes

  	PURPOSE				: 

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void AddCallLogApplicationRes( void )
{
    ADD_APPLICATION_MENUITEM( ( MENU8101_RECEIVED_CALLS,
                                MAIN_MENU_CALL_HISTORY, 0, SHOW,
                                MOVEABLEWITHINPARENT|SHORTCUTABLE , DISP_LIST,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                STRING_MTPNP_MENU8101_SIM1_RECEIVED_CALLS,
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                STR_MENU8101_RECEIVED_CALLS,
                            #endif /*__MMI_DUAL_SIM_MASTER__*/
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_MENU_RECEIVED_CALLS
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_MENU8101_RECEIVED_CALLS
                            #endif /*__MMI_DUAL_SIM_MASTER__*/
                                ));
    ADD_APPLICATION_MENUITEM( ( MENU8102_DIALED_CALLS, MAIN_MENU_CALL_HISTORY,0, SHOW, 
                                MOVEABLEWITHINPARENT|SHORTCUTABLE, DISP_LIST,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                STRING_MTPNP_MENU8102_SIM1_DIALED_CALLS,
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                STR_MENU8102_DIALED_CALLS,
                            #endif  /*__MMI_DUAL_SIM_MASTER__*/
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_MENU_DIALED_CALLS
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_MENU8102_DIALED_CALLS
                            #endif  /*__MMI_DUAL_SIM_MASTER__*/
                                ));
    ADD_APPLICATION_MENUITEM( ( MENU8103_MISSED_CALLS, MAIN_MENU_CALL_HISTORY, 0, SHOW, 
                                MOVEABLEWITHINPARENT|SHORTCUTABLE, DISP_LIST,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                STRING_MTPNP_MENU8103_SIM1_MISSED_CALLS,
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                STR_MENU8103_MISSED_CALLS,
                            #endif  /*__MMI_DUAL_SIM_MASTER__*/
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_MENU_MISSED_CALLS
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_MENU8103_MISSED_CALLS
                            #endif  /*__MMI_DUAL_SIM_MASTER__*/
                                ));
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
	ADD_APPLICATION_MENUITEM((IDLE_SCREEN_CALL_HISTORY_SEND,0,
						#ifdef __MMI_CH_MIXED_CALL_LOG__
								4,
                                MENU8100_MIXED_CALLS,
						#else
								3,
						#endif
								MENU8103_MISSED_CALLS,MENU8101_RECEIVED_CALLS,MENU8102_DIALED_CALLS,
								SHOW,NONMOVEABLE|SHORTCUTABLE,1,MAIN_MENU_CALL_HISTORY_TEXT, STR_MENU8101_RECEIVED_CALLS));
	ADD_APPLICATION_MENUITEM( ( MENU8100_MIXED_CALLS,
	                            IDLE_SCREEN_CALL_HISTORY_SEND, 0, SHOW,
	                            MOVEABLEWITHINPARENT|SHORTCUTABLE , DISP_LIST,
	                            MAIN_MENU_CALL_HISTORY_TEXT,
	                            IMG_MENU8101_RECEIVED_CALLS ));
#ifdef __MMI_CH_MIXED_CALL_LOG__
	ADD_APPLICATION_IMAGE2( TAB_MIXED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\TB_CMIX.GIF","Recieved Calls Tab Pane");
#endif
	ADD_APPLICATION_IMAGE2( TAB_MISSED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\TB_CMIS.GIF","Recieved Calls Tab Pane");
	ADD_APPLICATION_IMAGE2( TAB_RECIEVED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\TB_CREC.GIF","Recieved Calls Tab Pane");
	ADD_APPLICATION_IMAGE2( TAB_DIALED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\TB_CDIL.GIF","Recieved Calls Tab Pane");


#endif
	
	ADD_APPLICATION_STRING2(STR_UNKNOWN_NUMBER, "Unknown Number", "Unknown number");
	ADD_APPLICATION_STRING2(STR_NO_NUMBER, "No Number", "No number");
	ADD_APPLICATION_STRING2(STR_ID_CHIST_ANONYMOUS_URI, "anonymous", "anonymous");	
	ADD_APPLICATION_STRING2(STR_NO_ENTRY, "No entry", "No Entry");
	ADD_APPLICATION_STRING2(STR_ENTRY, "entry", "entry");
	ADD_APPLICATION_STRING2(STR_ENTRIES, "entries", "entries");
	ADD_APPLICATION_STRING2(STR_TIME, "time", "time");
	ADD_APPLICATION_STRING2(STR_TIMES, "times", "times");
	
	ADD_APPLICATION_STRING2(STR_NONUMBER_TO_DIAL, "No Number to Dial!", "No Number To Dial");
	ADD_APPLICATION_STRING2( STR_MENU8101_RECEIVED_CALLS, "Received Calls",
	                         "String for call Received" );
	ADD_APPLICATION_STRING2( STR_MENU8102_DIALED_CALLS, "Dialed Calls",
	                         "String for Call Dialled" );
	ADD_APPLICATION_STRING2( STR_MENU8103_MISSED_CALLS, "Missed Calls",
	                         "String for Missed Calls option" );
	ADD_APPLICATION_STRING2( STR_CALLS_IN_PROGRESS_TEXT ," In Progress.... ",
		"CALLS IN PROGRESS TEXT ");
	/*	Recd Call list */
	ADD_APPLICATION_STRING2( STR_SCR8054_CAPTION, "Received Calls",
	                         "Recd. call list caption string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8054_CAPTION, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Recd. call list caption image" );
	/*	Missed Call list */
	ADD_APPLICATION_STRING2( STR_SCR8055_CAPTION, "Missed Calls",
	                         "Missed call list caption string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8055_CAPTION, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Missed call list caption  image" );
	/*	Dialed Call list */
	ADD_APPLICATION_STRING2( STR_SCR8056_CAPTION, "Dialed Calls",
	                         "Dialed call list caption string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8056_CAPTION, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Dialed call list caption image" );

   // MTK amanda add 1215
	ADD_APPLICATION_STRING2( STR_SCR8057_CAPTION, "Call Logs",
	                         "Mixed call list caption string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8057_CAPTION, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Mixed call list caption image" );

    // send SMS and MMS from Call Log 
	ADD_APPLICATION_STRING2( STR_ID_CHIST_OPTION_SENDSMS, "Send SMS",
	                         "Send SMS message to caller" );
	ADD_APPLICATION_STRING2( STR_ID_CHIST_OPTION_SENDMMS, "Send MMS",
	                         "Send MMS message to caller" );

	/********************** Recd Call list options *******************/
	ADD_APPLICATION_STRING2( STR_SCR8069_CAPTION, "Received Call Info Option",
	                         "Recd. call list options title string" );
	ADD_APPLICATION_STRING2( STR_SCR8069_CAPTION1, "Call Info",
	                         "Recd. call list options title string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8069_CAPTION, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Recd. call list options title icon" );

	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_LIST_OPTIONS, 0, 7,
                                RECEIVED_CALL_MENU_INFO,
                                RECEIVED_CALL_MENU_DELETE,
                                RECEIVED_CALL_MENU_SAVE,
                                RECEIVED_CALL_MENU_CALL,
                                RECEIVED_CALL_MENU_EDIT,
                                RECEIVED_CALL_MENU_SENDSMS,
                                RECEIVED_CALL_MENU_SENDMMS,
                                SHOW, INSERTABLE, DISP_LIST,
                                STR_SCR8069_CAPTION, IMG_SCR8069_CAPTION ));

	ADD_APPLICATION_STRING2( STR_RECD_SAVE_MENUENTRY, "Save to Phone book",
	                         "Recd call list options Save to phone book entry string" );

	ADD_APPLICATION_IMAGE2( IMG_MENU8101_RECEIVED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CREC.PBM",
	                        "Recd. call list options DELETE ALL entry image" );
	ADD_APPLICATION_IMAGE2( IMG_MENU8102_DIALED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CDIA.PBM",
	                        "Recd. call list options DELETE ALL entry image" );
	ADD_APPLICATION_IMAGE2( IMG_MENU8103_MISSED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CMIS.PBM",
	                        "Recd. call list options DELETE ALL entry image" );

//MTK Leo end
	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_MENU_INFO,
	                            RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_VIEW,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_MENU_CALL,
	                            RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_DIAL,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_MENU_SAVE,
	                            RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_RECD_SAVE_MENUENTRY,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_MENU_DELETE,
	                            RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_DELETE,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_MENU_EDIT,
	                            RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_EDIT,
	                            NULL ));
	//send SMS from call log
	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_MENU_SENDSMS,
	                            RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_ID_CHIST_OPTION_SENDSMS,
	                            NULL ));
	//send MMS from call log                            
	ADD_APPLICATION_MENUITEM( ( RECEIVED_CALL_MENU_SENDMMS,
	                            RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_ID_CHIST_OPTION_SENDMMS,
	                            NULL ));

	/******************** Dialed call list ****************/
	ADD_APPLICATION_STRING2( STR_SCR8070_CAPTION, "Dialed Call Info Option",
	                         "Dialed call list options title string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8070_CAPTION, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Dialed call list options title icon" );

        ADD_APPLICATION_MENUITEM( ( DIALED_CALL_LIST_OPTIONS, 0, 7,
                                    DIALED_CALL_MENU_INFO,
                                    DIALED_CALL_MENU_DELETE,
	                            DIALED_CALL_MENU_SAVE, 
	                            DIALED_CALL_MENU_CALL,
	                            DIALED_CALL_MENU_EDIT,
	                            DIALED_CALL_MENU_SENDSMS,
	                            DIALED_CALL_MENU_SENDMMS,
	                            SHOW, INSERTABLE, DISP_LIST,
	                            STR_SCR8070_CAPTION, IMG_SCR8070_CAPTION ));

	ADD_APPLICATION_STRING2( STR_DIALED_SAVE_MENUENTRY, "Save to Phone book",
	                         "Dialed call list options Save entry string" );
        ADD_APPLICATION_MENUITEM( ( DIALED_CALL_MENU_INFO,
	                            DIALED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_VIEW,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( DIALED_CALL_MENU_CALL,
	                            DIALED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_DIAL,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( DIALED_CALL_MENU_SAVE,
	                            DIALED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_DIALED_SAVE_MENUENTRY,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( DIALED_CALL_MENU_DELETE,
	                            DIALED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_DELETE,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( DIALED_CALL_MENU_EDIT,
	                            DIALED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_EDIT,
	                            NULL ));
	
	ADD_APPLICATION_MENUITEM( ( DIALED_CALL_MENU_SENDSMS,
	                            DIALED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_ID_CHIST_OPTION_SENDSMS,
	                            NULL ));

	ADD_APPLICATION_MENUITEM( ( DIALED_CALL_MENU_SENDMMS,
	                            DIALED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_ID_CHIST_OPTION_SENDMMS,
	                            NULL ));

	/******************** Missed call list ****************/
	ADD_APPLICATION_STRING2( STR_SCR8071_CAPTION, "Missed Call Info Option",
	                         "Missed call list options title string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8071_CAPTION, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Missed call list options title icon" );

	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_LIST_OPTIONS, 0, 7,
	                            MISSED_CALL_MENU_INFO,
	                            MISSED_CALL_MENU_DELETE,
	                            MISSED_CALL_MENU_SAVE, 
	                            MISSED_CALL_MENU_CALL,
	                            MISSED_CALL_MENU_EDIT,
	                            MISSED_CALL_MENU_SENDSMS,
	                            MISSED_CALL_MENU_SENDMMS,
	                            SHOW, INSERTABLE, DISP_LIST,
	                            STR_SCR8071_CAPTION, IMG_SCR8071_CAPTION ));

	ADD_APPLICATION_STRING2( STR_MISSED_SAVE_MENUENTRY, "Save to Phone book",
	                         "Missed call list options Save entry string" );
	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_MENU_INFO,
	                            MISSED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_VIEW,
	                            NULL ));	                      
	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_MENU_CALL,
	                            MISSED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_DIAL,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_MENU_SAVE,
	                            MISSED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MISSED_SAVE_MENUENTRY,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_MENU_DELETE,
	                            MISSED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_DELETE,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_MENU_EDIT,
	                            MISSED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_EDIT,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_MENU_SENDSMS,
	                            MISSED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_ID_CHIST_OPTION_SENDSMS,
	                            NULL ));
	ADD_APPLICATION_MENUITEM( ( MISSED_CALL_MENU_SENDMMS,
	                            MISSED_CALL_LIST_OPTIONS, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_ID_CHIST_OPTION_SENDMMS,
	                            NULL ));

	ADD_APPLICATION_STRING2( STR_EMPTY_LIST_NOTIFICATION, "Empty!",
	                         "Empty list notification string" );
	ADD_APPLICATION_IMAGE2( IMG_SCR8072_CAPTION,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "Call Times menu caption image" );
	ADD_APPLICATION_STRING2( STR_ENTRY_DELETED_CONFIRM, "Delete",
	                         "STR_ENTRY_DELETED" );

   ADD_APPLICATION_STRING2(STR_MISSED_CALL,"Missed Call!",
                            "Title String for Screen for one Missed Call");
	ADD_APPLICATION_STRING2(STR_MISSED_CALLS,"Missed Calls!",
	                         "Title String for Screen for multiple Missed Calls");
	ADD_APPLICATION_STRING2(MISSED_LSK_STR,"Read","LSK String");
	
//MTK Leo remove , for name info. in call info
	ADD_APPLICATION_IMAGE2( IMG_NAME_ENTRY,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\CallInfo\\\\CI_NAME.PBM",
	                        "Call Info Name Image" );
	ADD_APPLICATION_IMAGE2( IMG_NUMBER_ENTRY,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\CallInfo\\\\CI_PHONE.PBM",
	                        "Call Info Number Image" );
	ADD_APPLICATION_IMAGE2( IMG_TIME_ENTRY,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\CallInfo\\\\CI_TIME.PBM",
	                        "Call Info Time Image" );
	ADD_APPLICATION_IMAGE2( IMG_DATE_ENTRY,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\CallInfo\\\\CI_DATE.PBM",
	                        "Call Info Date Image" );
	ADD_APPLICATION_IMAGE2( IMG_COUNT_ENTRY,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\CallInfo\\\\CI_IRP.PBM",
	                        "Call Info number of times Image" );

   ADD_APPLICATION_IMAGE2(IMG_ID_CHIST_DURATION	,	
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\CallInfo\\\\CI_DURATION.PBM",
	                        "Call Info duration Image" );

   ADD_APPLICATION_IMAGE2(MISSED_LSK_ICN,	
                           CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Missed\\\\CL_MIS.gif",
                           "Missed call Icon");
   ADD_APPLICATION_IMAGE2(IMG_CM_STATE_MISSED	,	
                           CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\Call\\\\SB_MISCL.BMP",
                           "Image of Missed Call");
    ADD_APPLICATION_STRING2( STR_GPRS_RESET_COUNTER_QUERY, "Reset Counter?",  "GPRS COUNTER RESET COUNTER?" );


#ifdef __MMI_VOIP__
   ADD_APPLICATION_IMAGE2(IMG_ID_CHIST_VOIP_RECEIVED_CALLS	,	
	                        CUST_IMG_PATH"\\\\MainLCD\\\\VOIP\\\\Call\\\\CallLog\\\\VoIP_CREC.pbm",
	                        "Received Call icon" );
   ADD_APPLICATION_IMAGE2(IMG_ID_CHIST_VOIP_DIALED_CALLS	,	
	                        CUST_IMG_PATH"\\\\MainLCD\\\\VOIP\\\\Call\\\\CallLog\\\\VoIP_CDIA.pbm",
	                        "Dialed Call icon" );
   ADD_APPLICATION_IMAGE2(IMG_ID_CHIST_VOIP_MISSED_CALLS	,	
	                        CUST_IMG_PATH"\\\\MainLCD\\\\VOIP\\\\Call\\\\CallLog\\\\VoIP_CMIS.pbm",
	                        "Missed Call icon" );
#endif /* __MMI_VOIP__ */

#ifdef __MMI_VIDEO_TELEPHONY__
   ADD_APPLICATION_IMAGE2(IMG_ID_CHIST_VIDEO_RECEIVED_CALLS	,	
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\CallLog\\\\SB_CREC.pbm",
	                        "Received Call icon" );
   ADD_APPLICATION_IMAGE2(IMG_ID_CHIST_VIDEO_DIALED_CALLS	,	
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\CallLog\\\\SB_CDIA.pbm",
	                        "Dialed Call icon" );
   ADD_APPLICATION_IMAGE2(IMG_ID_CHIST_VIDEO_MISSED_CALLS	,	
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\CallLog\\\\SB_CMIS.pbm",
	                        "Missed Call icon" );
#endif /* __MMI_VIDEO_TELEPHONY__ */
}

/**************************************************************
FUNCTION NAME		: PopulateCallTimes(void)

 	PURPOSE				: 

INPUT PARAMETERS	: nil
	
OUTPUT PARAMETERS	: nil
	
RETURNS				: void

REMARKS				: 

**************************************************************/
void PopulateCallTimes()
{
    ADD_APPLICATION_MENUITEM( ( MENU_CALL_TIME_SETUP, MAIN_MENU_CALL_HISTORY, 4,
                                MENU_LAST_CALL_TIME, MENU_CALL_OUT_TIME,
                                MENU_CALL_IN_TIME, MENU_ALL_CALL_TIME, SHOW,
                                MOVEABLEACROSSPARENT|INSERTABLE|SHORTCUTABLE, DISP_LIST,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                STRING_MTPNP_MENU_SIM1_CALL_TIME_SETUP,
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                STR_MENU_CALL_TIME_SETUP,
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_CALL_TIMES_MAIN_MENU
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_CALL_TIMES_MAIN_MENU
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                                ));	

	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_QUICK_END, 
                           #ifdef __MMI_UCM__
                                MENU_ID_UCM_CALL_SETTING_MORE,
                           #else
                                MAIN_MENU_CALL_HISTORY, 
                           #endif
                                0,
	                            SHOW, MOVEABLEACROSSPARENT|SHORTCUTABLE, DISP_LIST,
	                            STR_MENU_QUICK_END,
	                            IMG_QUICK_END_MAIN_MENU ));	

	ADD_APPLICATION_MENUITEM( ( MENU_LAST_CALL_TIME, MENU_CALL_TIME_SETUP, 0,
	                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_LAST_CALL_TIME, NULL ));	
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_OUT_TIME, MENU_CALL_TIME_SETUP, 0,
	                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_CALL_OUT_TIME, NULL ));	
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_IN_TIME, MENU_CALL_TIME_SETUP, 0,
	                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_CALL_IN_TIME, NULL ));	
	ADD_APPLICATION_MENUITEM( ( MENU_ALL_CALL_TIME, MENU_CALL_TIME_SETUP, 0,
	                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_ALL_CALL_TIME, NULL ));	
	ADD_APPLICATION_STRING2( STR_MENU_CALL_TIME_SETUP, "Call Time",
	                         "CALL TIME SET MAIN " );

	ADD_APPLICATION_STRING2( STR_MENU_QUICK_END, "Auto quick end",
	                         "QUICK END SET MAIN " );
	ADD_APPLICATION_STRING2( STR_MENU_QUICK_END_SET, "Set",
	                         "QUICK END SET ON OFF" );
	ADD_APPLICATION_STRING2( STR_MENU_QUICK_END_DURATION, "Duration (1~9999 sec.)",
	                         "QUICK END SET DURATION " );

	ADD_APPLICATION_STRING2( STR_MENU_LAST_CALL_TIME, "Last Call Time",
	                         "LAST CALL TIME STRING" );
	ADD_APPLICATION_STRING2( STR_MENU_CALL_OUT_TIME, "Total Sent",
	                         "CALL OUT TIME  STRING" );
	ADD_APPLICATION_STRING2( STR_MENU_CALL_IN_TIME, "Total Received",
	                         "CALL IN TIME STRING" );
	ADD_APPLICATION_STRING2( STR_MENU_ALL_CALL_TIME, "Reset All Time",
	                         "ALL CALL TIMES STRING " );

	ADD_APPLICATION_STRING2( STR_RESET_ALL_CALL_TIME_CONFIRM, "Delete",
	                         "ALL CALL TIMES RESET STRING? " );
	
	ADD_APPLICATION_IMAGE2( IMG_MENU_CALL_TIMES,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "CALL TIMES IMG  " );
//MTK Leo add

		ADD_APPLICATION_IMAGE2( IMG_CALL_TIMES_MAIN_MENU,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CTIME.PBM",
	                        "RESET CALLS CONFIRM SCR  RSK IMG " );

	ADD_APPLICATION_IMAGE2( IMG_QUICK_END_MAIN_MENU,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CEND.PBM",
	                        "AUTO QUICK END IMG " );

//MTK Leo end
	return;
}


/**************************************************************

	FUNCTION NAME		: PopulateCallCost(void)

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void PopulateCallCost(void )
{
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_CALLCOST, MAIN_MENU_CALL_HISTORY, 5,
	                            MENU_CALL_COST_LASTCALL,
	                            MENU_CALL_COST_ALLCOST,
	                            MENU_CALL_COST_RESETCOUNTER,
	                            MENU_CALL_COST_MAXCOUNT,
	                            MENU_CALL_COST_PRICEUNIT, 0, 
				    					 MOVEABLEACROSSPARENT|INSERTABLE|SHORTCUTABLE, 1,
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   STRING_MTPNP_MENU_SIM1_CALL_COST_MAIN,
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            STR_MENU_CALL_COST_MAIN,
                               #endif /* __MMI_DUAL_SIM_MASTER__ */	
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   IMG_MTPNP_CARD1_CALL_COST_MAIN_MENU
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            IMG_CALL_COST_MAIN_MENU
                               #endif /* __MMI_DUAL_SIM_MASTER__ */		                            
	                             ));	

	ADD_APPLICATION_MENUITEM( ( MENU_CALL_COST_LASTCALL,
	                            MENU_CALL_HISTORY_CALLCOST, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_CALL_COST_LASTCALL, NULL ));	

	ADD_APPLICATION_MENUITEM( ( MENU_CALL_COST_ALLCOST,
	                            MENU_CALL_HISTORY_CALLCOST, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_CALL_COST_ALLCOST, NULL ));	

	ADD_APPLICATION_MENUITEM( ( MENU_CALL_COST_PRICEUNIT,
	                            MENU_CALL_HISTORY_CALLCOST, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_CALL_COST_PRICEUNIT, NULL ));	

	ADD_APPLICATION_MENUITEM( ( MENU_CALL_COST_RESETCOUNTER,
	                            MENU_CALL_HISTORY_CALLCOST, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_CALL_COST_RESETCOUNTER, NULL ));	

	ADD_APPLICATION_MENUITEM( ( MENU_CALL_COST_MAXCOUNT,
	                            MENU_CALL_HISTORY_CALLCOST, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_MENU_CALL_COST_MAXCOUNT, NULL ));	

	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_MAIN, "Call Cost",
	                         "CALL COST MAIN CAPTION " );

	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_LASTCALL, "Last Call Cost",
	                         "LAST CALL COST " );

	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_ALLCOST, "Total Cost",
	                         "ALL CALL COST " );

	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_PRICEUNIT, "Price Per Unit",
	                         "PRICE AND UNIT" );

	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_RESETCOUNTER, "Reset Cost",
	                         "RESET COUNTER " );

	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_MAXCOUNT, "Max Cost",
	                         "MAX COST" );

	ADD_APPLICATION_STRING2( STR_ALL_CALL_COSTS_ERROR_MSG,
	                         "Invalid Input", "ERROR MSG ALL COST " );

	ADD_APPLICATION_IMAGE2( IMG_SCR_CALL_COST_MAIN_CAP,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "CALL COST MAIN CAPTION IMG  " );

//MTK Leo add

		ADD_APPLICATION_IMAGE2( IMG_CALL_COST_MAIN_MENU,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_COAST.PBM",
	                        "RESET CALLS CONFIRM SCR  RSK IMG " );

//MTK Leo end
	/** Price and Unit **/
	ADD_APPLICATION_STRING2( STR_CALL_COST_PRICEANDUNIT_VIEW_LSK, "Set",
	                         "STR_CALL_COST_PRICEANDUNIT_VIEW_LSK" );

	ADD_APPLICATION_STRING2( STR_MENU_SCR_CALL_COST_PRICEANDUNIT_SET, "Set",
	                         "STR_MENU_SCR_CALL_COST_PRICEANDUNIT_SET" );

	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_PRICEANDUNIT_SET_PRICE, "Price", "STR_MENU_CALL_COST_PRICEANDUNIT_SET_PRICE");
	ADD_APPLICATION_STRING2( STR_MENU_CALL_COST_PRICEANDUNIT_SET_UNIT, "Unit", "STR_MENU_CALL_COST_PRICEANDUNIT_SET_UNIT");
	
	ADD_APPLICATION_STRING2( STR_MAX_COST_SET_CAPTION, "Set Max Cost ",
	                         "STR_MAX_COST_SET_CAPTION" );

	ADD_APPLICATION_IMAGE2( IMG_SCR_CALL_COST_PRICEANDUNIT_SET_CAPTION,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "IMG_SCR_CALL_COST_PRICEANDUNIT_SET_CAPTION  " );

	ADD_APPLICATION_IMAGE2( IMG_SCR_MAX_COST_GET_CAPTION,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "IMG_SCR_MAX_COST_GET_CAPTION  " );

}

/**************************************************************

	FUNCTION NAME		: PopulateCallHistoryRes(void)

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void PopulateCallHistoryRes(void)
{
	ADD_APPLICATION_STRING2( STR_SCR_CALL_HISTORY_MAIN_MENU_CAPTION,
	                         "Call History", "CALL HISTORY  CAPTION  " );

//MTK Leo add

	ADD_APPLICATION_IMAGE2( IMG_SCR_CALL_HISTORY_MAIN_MENU_CAPTION,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CA.PNG",
	                        "CALL HISTORY  CAPTION IMG" );

//MTK Leo end

	//PRINT_INFORMATION( ( "AddCallLogApplicationRes Start \n" ));
	AddCallLogApplicationRes();
	//PRINT_INFORMATION( ( "AddCallLogApplicationRes End \n" ));
	//PRINT_INFORMATION( ( "PopulateResetCallRes Start \n" ));
	PopulateResetCallRes();
	//PRINT_INFORMATION( ( "PopulateResetCallRes End \n" ));
	//PRINT_INFORMATION( ( "AddSMSCounterApplicationRes Start  \n" ));
	AddSMSCounterApplicationRes();
	//PRINT_INFORMATION( ( "AddSMSCounterApplicationRes End \n" ));
	//PRINT_INFORMATION( ( "PopulateCallTimes Start  \n" ));
	PopulateCallTimes();
	//PRINT_INFORMATION( ( "PopulateCallTimes End \n" ));
	//PRINT_INFORMATION( ( "PopulateCallCost Start  \n" ));
	PopulateCallCost();
	//PRINT_INFORMATION( ( "PopulateCallCost End \n" ));

#ifdef __MMI_GPRS_FEATURES__
	//PRINT_INFORMATION( ( "AddGPRSCounterApplicationRes Start  \n" ));
	AddGPRSCounterApplicationRes();
	//PRINT_INFORMATION( ( "AddGPRSCounterApplicationRes End \n" ));
#endif
	
}
/**************************************************************

	FUNCTION NAME		: AddSMSCounterApplicationRes(void)

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void AddSMSCounterApplicationRes( void )
{
	ADD_APPLICATION_STRING2( STR_SMS_CAPTION, "SMS Counter",
	                         "SMS COUNTER SCR CAPTION" );
	ADD_APPLICATION_STRING2( STR_SENT_SMS_COUNT, "Sent",
	                         "SMS COUNTER SCR SENT " );
	ADD_APPLICATION_STRING2( STR_RECV_SMS_COUNT, "Received",
	                         "SMS COUNTER RECV " );

	ADD_APPLICATION_STRING2( STR_SCR_RESET_RCVD_SMS_CONFIRM_TEXT, "Delete",
	                         "Reset sent/recvd sms counters" );

	ADD_APPLICATION_STRING2( STR_SMS_NO_NUMBER, "No msg",
	                         "No Messages" );
	ADD_APPLICATION_STRING2( STR_SMS_STRING, "msgs",
	                         "Messages counter string" );

	ADD_APPLICATION_STRING2( STR_SMS_COUNTER_LSK, "Reset",
	                         "SMS COUNTER RESET " );
    ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_SMSCOUNTER,
                                MAIN_MENU_CALL_HISTORY, 2,
                                MENU_CALL_HISTORY_SENT,
                                MENU_CALL_HISTORY_RECEIVED, SHOW, 
                                MOVEABLEACROSSPARENT|SHORTCUTABLE,
                                DISP_LIST,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                STRING_MTPNP_MENU_SIM1_SMS_CAPTION,
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                STR_SMS_CAPTION,
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_SMS_COUNTER_MENU
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_SMS_COUNTER_MENU 
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                                ));
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_SENT,
	                            MENU_CALL_HISTORY_SMSCOUNTER, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST, STR_SENT_SMS_COUNT, NULL ));
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_RECEIVED,
	                            MENU_CALL_HISTORY_SMSCOUNTER, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST, STR_RECV_SMS_COUNT, NULL ));
//MTK Leo add

	ADD_APPLICATION_IMAGE2( IMG_SMS_COUNTER_MENU,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CSMS.PBM",
	                        "DELETE ALL entry image" );

//MTK Leo end
}

/**************************************************************

	FUNCTION NAME		: PopulateResetCallRes(void)

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void PopulateResetCallRes()
{
	ADD_APPLICATION_STRING2( STR_MENU8113_CALLHISTORY_RESETCALL,
	                         "Delete Call Log", "RESET ALL CALLS MENU STR" );
#ifdef __MMI_CH_DELETE_ALL_LOGS__
	ADD_APPLICATION_MENUITEM( ( MENU8113_CALLHISTORY_RESETCALL,
	                            MAIN_MENU_CALL_HISTORY, 4, 
	                            MENU_MISSED_CALLS,
	                            MENU_DIALED_CALLS, 
	                            MENU_RECEIVED_CALLS, 
	                            MENU_ALL_CALLS, SHOW,
	                            MOVEABLEWITHINPARENT|SHORTCUTABLE, DISP_LIST,
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   STRING_MTPNP_MENU_SIM1_CALLHISTORY_RESETCALL,
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            STR_MENU8113_CALLHISTORY_RESETCALL,
	                        #endif /* __MMI_DUAL_SIM_MASTER__ */
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   IMG_MTPNP_CARD1_MENU_DELETE_CALLS
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            IMG_SCR_RESETCALLS
	                        #endif /* __MMI_DUAL_SIM_MASTER__ */
	                            ));
#else
	ADD_APPLICATION_MENUITEM( ( MENU8113_CALLHISTORY_RESETCALL,
	                            MAIN_MENU_CALL_HISTORY, 3, 
	                            MENU_MISSED_CALLS,
	                            MENU_DIALED_CALLS, 
	                            MENU_RECEIVED_CALLS, SHOW,
	                            MOVEABLEWITHINPARENT|SHORTCUTABLE, DISP_LIST,
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   STRING_MTPNP_MENU_SIM1_CALLHISTORY_RESETCALL,
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            STR_MENU8113_CALLHISTORY_RESETCALL,
	                        #endif /* __MMI_DUAL_SIM_MASTER__ */
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   IMG_MTPNP_CARD1_MENU_DELETE_CALLS
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            IMG_SCR_RESETCALLS
	                        #endif /* __MMI_DUAL_SIM_MASTER__ */
	                            ));
#endif
    ADD_APPLICATION_MENUITEM( ( MENU_RECEIVED_CALLS,
                                MENU8113_CALLHISTORY_RESETCALL, 0, SHOW,
                                MOVEABLEWITHINPARENT, DISP_LIST,
                                STR_MENU_RECEIVED_CALLS,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_MENU_RECEIVED_CALLS
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_MENU_RECEIVED_CALLS 
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                                ));
    ADD_APPLICATION_MENUITEM( ( MENU_DIALED_CALLS,
                                MENU8113_CALLHISTORY_RESETCALL, 0, SHOW,
                                MOVEABLEWITHINPARENT, DISP_LIST, STR_MENU_DIALED_CALLS,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_MENU_DIALED_CALLS
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_MENU_DIALED_CALLS
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                                ));
    ADD_APPLICATION_MENUITEM( ( MENU_MISSED_CALLS,
                                MENU8113_CALLHISTORY_RESETCALL, 0, SHOW,
                                MOVEABLEWITHINPARENT, DISP_LIST,
                                STR_MENU_MISSED_CALLS, 
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                IMG_MTPNP_CARD1_MENU_MISSED_CALLS
                            #else /* __MMI_DUAL_SIM_MASTER__ */
                                IMG_MENU_MISSED_CALLS 
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                                ));

   // MTK amanda add 1110
	ADD_APPLICATION_MENUITEM( ( MENU_ALL_CALLS, MENU8113_CALLHISTORY_RESETCALL, 0,
	                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
	                            STR_GLOBAL_DELETE_ALL,
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   IMG_MTPNP_CARD1_MENU_DELETE_CALLS
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            IMG_SCR_RESETCALLS
	                        #endif /* __MMI_DUAL_SIM_MASTER__ */
	                            ));

	ADD_APPLICATION_STRING2( STR_MENU_RECEIVED_CALLS, "Received Calls",
	                         "String for call Received" );
	ADD_APPLICATION_STRING2( STR_MENU_DIALED_CALLS, "Dialed Calls",
	                         "String for Call Dialled" );
	ADD_APPLICATION_STRING2( STR_MENU_MISSED_CALLS, "Missed Calls",
	                         "String for Missed Calls option" );
	ADD_APPLICATION_STRING2( STR_ID_CHIST_DELETE_QUERY, "Delete all?",
	                         "String for delete all query" );
	ADD_APPLICATION_STRING2( STR_ID_CHIST_DELETE_ALL_QUERY, "Delete all?",
	                         "String for delete all query" );

   // MTK amanda add 1110
	ADD_APPLICATION_IMAGE2( IMG_MENU_RECEIVED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CREC.PBM",
	                        "Image for recd Calls option" );
	ADD_APPLICATION_IMAGE2( IMG_MENU_DIALED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CDIA.PBM",
	                        "Image for Dialed Calls option" );
	ADD_APPLICATION_IMAGE2( IMG_MENU_MISSED_CALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CMIS.PBM",
	                        "Image for Missed Calls option" );
	ADD_APPLICATION_IMAGE2( IMG_SCR_RESETCALLS,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CRSET.PBM",
	                        "RESET CALLS CONFIRM SCR  RSK IMG " );
	ADD_APPLICATION_IMAGE2( IMG_SCR_RESETCALLS_CONFIRM,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DEL."__MMI_RES_TYPE_POPUP_SCREEN__,
	                        "RESET CALLS CONFIRM SCR  RSK IMG " );
//MTK Leo end



	ADD_APPLICATION_STRING2( STR_SCR_RESETCALLS_CONFIRM_CAPTION,
	                         "Delete",
	                         "RESET CALLS CONFIRM text " );

	ADD_APPLICATION_IMAGE2( IMG_SCR_RESETCALLS_CONFIRM,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DEL"__MMI_RES_TYPE_POPUP_SCREEN__,
	                        "RESET CALLS CONFIRM SCR  RSK IMG " );

}


#ifdef __MMI_GPRS_FEATURES__
/**************************************************************

	FUNCTION NAME		: AddSMSCounterApplicationRes(void)

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void AddGPRSCounterApplicationRes( void )
{
	ADD_APPLICATION_STRING2( STR_GPRS_CAPTION, "GPRS Counter",  "GPRS COUNTER SCR CAPTION" );
	ADD_APPLICATION_STRING2( STR_GPRS_LAST_SENT, "Last Sent",  "GPRS COUNTER LAST SENT" );
	ADD_APPLICATION_STRING2( STR_GPRS_LAST_RECEIVED, "Last Received",  "GPRS COUNTER LAST RECEIVED" );
	ADD_APPLICATION_STRING2( STR_GPRS_ALL_SENT, "All Sent",  "GPRS COUNTER ALL SENT" );
	ADD_APPLICATION_STRING2( STR_GPRS_ALL_RECEIVED, "All Received",  "GPRS COUNTER ALL RECEIVED" );
	ADD_APPLICATION_STRING2( STR_GPRS_RESET_COUNTER, "Reset Counter",  "GPRS COUNTER RESET COUNTER" );

	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_GPRSCOUNTER,
	                            MAIN_MENU_CALL_HISTORY, 5,
										 MENU_CALL_HISTORY_GPRS_LASTSENT,
										 MENU_CALL_HISTORY_GPRS_LASTRECEIVED,
										 MENU_CALL_HISTORY_GPRS_ALLSENT,
										 MENU_CALL_HISTORY_GPRS_ALLRECEIVED,
										 MENU_CALL_HISTORY_GPRS_RESETCOUNTER,
										 SHOW, MOVEABLEACROSSPARENT|INSERTABLE|SHORTCUTABLE,
	                            DISP_LIST,
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   STRING_MTPNP_MENU_SIM1_GPRS_CAPTION,
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            STR_GPRS_CAPTION,
                               #endif /* __MMI_DUAL_SIM_MASTER__ */	                            
	                        #ifdef __MMI_DUAL_SIM_MASTER__
                                   IMG_MTPNP_CARD1_GPRS_COUNTER_MENU
                               #else /* __MMI_DUAL_SIM_MASTER__ */
	                            IMG_GPRS_COUNTER_MENU
                               #endif /* __MMI_DUAL_SIM_MASTER__ */	                            
	                            ));
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_GPRS_LASTSENT,
	                            MENU_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST, STR_GPRS_LAST_SENT, NULL ));
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_GPRS_LASTRECEIVED,
	                            MENU_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST, STR_GPRS_LAST_RECEIVED, NULL ));
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_GPRS_ALLSENT,
	                            MENU_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST, STR_GPRS_ALL_SENT, NULL ));
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_GPRS_ALLRECEIVED,
	                            MENU_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST, STR_GPRS_ALL_RECEIVED, NULL ));
	ADD_APPLICATION_MENUITEM( ( MENU_CALL_HISTORY_GPRS_RESETCOUNTER,
	                            MENU_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
	                            MOVEABLEWITHINPARENT, DISP_LIST, STR_GPRS_RESET_COUNTER, NULL ));

	ADD_APPLICATION_IMAGE2( IMG_GPRS_COUNTER_MENU,
	                        CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CGPRS.PBM",
	                        "DELETE ALL entry image" );

}

#endif

#endif


