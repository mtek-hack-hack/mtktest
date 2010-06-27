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
 *  Res_VoIP.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file populates resource for VoIP appliction.
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
 *******************************************************************************/

#ifndef RES_VOIP_C
#define RES_VOIP_C
#include "MMI_features.h"

#ifdef __MMI_VOIP__

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "VoIPResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/**************************************************************
 * FUNCTION
 *  VoIPResourceData
 * DESCRIPTION
 *  Register all the resources required by VoIP application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 **************************************************************/
void VoIPResourceData(void)
{
    /* image resource */
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_MAIN, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\SB_VoIP.pbm", "Main menu image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_EDIT_COMMON, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\CommonSet\\\\VOIP_CSet.pbm", "Profile edit image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_COMMON_PROF_NAME, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\CommonSet\\\\VOIP_PName.pbm", "Profile name image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_COMMON_DATA_ACCT, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\CommonSet\\\\VOIP_DataAccount.pbm", "Data account image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_COMMON_AUTO_LOGIN, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\CommonSet\\\\VOIP_Login.pbm", "Auto login image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_COMMON_VMSERVER, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\CommonSet\\\\VOIP_VMail.pbm", "Voice mail server image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_EDIT_ACCOUNT, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\AccountSet\\\\VOIP_ASet.pbm", "Profile edit image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_ACCOUNT_SIP_SERVER, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\AccountSet\\\\VOIP_Server.pbm", "SIP server image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_ACCOUNT_SIP_PORT, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\AccountSet\\\\VOIP_Port.pbm", "SIP port image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_ACCOUNT_DISPNAME, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\AccountSet\\\\VOIP_DName.pbm", "Display name image");  
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_ACCOUNT_USERNAME, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\AccountSet\\\\VOIP_UName.pbm", "SIP server username image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_ACCOUNT_PASSWORD, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\AccountSet\\\\VOIP_PW.pbm", "SIP server password image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_ACCOUNT_AUTHNAME, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\AccountSet\\\\VOIP_UName.pbm", "Authorization name image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_EDIT_OUTBOUND, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Outbound\\\\VOIP_Outbound.pbm", "Profile edit image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_OUTBOUND_STATUS, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Outbound\\\\VOIP_Enable.pbm", "Outbound server status image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_OUTBOUND_SERVER, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Outbound\\\\VOIP_Server.pbm", "Outbound server image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_OUTBOUND_PORT, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Outbound\\\\VOIP_Port.pbm", "Outbound server port image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_OUTBOUND_USERNAME, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Outbound\\\\VOIP_UName.pbm", "Outbound server username image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_OUTBOUND_PASSWORD, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Outbound\\\\VOIP_PW.pbm", "Outbound server password image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_EDIT_REGISTER, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Register\\\\VOIP_Register.pbm", "Profile edit image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_REGISTER_STATUS, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Register\\\\VOIP_Enable.pbm", "Register server status image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_REGISTER_SERVER, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Register\\\\VOIP_Server.pbm", "Register server image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_REGISTER_PORT, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Register\\\\VOIP_Port.pbm", "Register server port image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_REGISTER_USERNAME, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Register\\\\VOIP_UName.pbm", "Register server username image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_REGISTER_PASSWORD, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\Register\\\\VOIP_PW.pbm", "Register server password image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_EDIT_NAT, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\STUN\\\\VOIP_STUN.pbm", "Profile edit image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_NAT_STATUS, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\STUN\\\\VOIP_Enable.pbm", "NAT server status image");   
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_NAT_FIREWALL, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\STUN\\\\VOIP_Firewall.pbm", "Firewall server image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_NAT_STUNSERVER, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\STUN\\\\VOIP_Server.pbm", "STUN server image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_NAT_STUNPORT, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\STUN\\\\VOIP_Port.pbm", "STUN server port image");    
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_PROF_NAT_INTERVAL, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Submenu\\\\STUN\\\\VOIP_Refresh.pbm", "STUN server refresh interval image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_CALL_EDITOR, CUST_IMG_PATH"\\\\MainLCD\\\\VoIP\\\\Call\\\\VoIP_BG.gif", "Call editor background image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_OUTGOING_CALL, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\CL_incom.gif", "Outgoing call image");    
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_INCOMING_CALL, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\CL_incom.gif", "Incoming call image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_CALL_STATE_ACTIVE, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_ACT.bmp", "Active call image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_CALL_STATE_HOLD, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_HOLD.bmp", "Held call image");    
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_CALL_ENDED, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\ended\\\\CL_END.GIF","Call ended popup image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VOIP_MSG_WAITING, CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_VOMAL"__MMI_RES_TYPE_POPUP_SCREEN__, "Message waiting image");
    
    /* string resource */
    ADD_APPLICATION_STRING2(STR_ID_VOIP_MAIN, "VoIP", "Main menu string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROCESSING, "Processing", "Processing string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_LOGIN, "Login", "Login string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_LOGOUT, "Logout", "Logout string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_LOGIN_OK, "Login Success", "Login success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_LOGOUT_OK, "Logout Success", "Logout success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_LOGOUT_IND, "VoIP Logout by Network", "VoIP logout by network string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CONNECT_TO_SERVER, "Connecting to SIP Server", "Connecting string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_DISCONNECT_FROM_SERVER, "Disconnecting from SIP Server", "Disconnecting string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SUMMARY, "Current Status", "Current status string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_SETTING, "Profile Setting", "Profile setting string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_EDIT_COMMON, "Common Setting", "Common setting string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_EDIT_ACCOUNT, "Account Setting", "Account setting string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_EDIT_OUTBOUND, "Outbound Server", "Outbound server setting");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_EDIT_REGISTER, "Register Server", "Register server string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_EDIT_NAT, "NAT Setting", "NAT setting string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROFNAME, "Profile Name", "Profile name string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_DATAACCOUNT, "Data Account", "Data account string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_AUTOLOGIN, "Auto Login", "Auto login string");    
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_VMSERVER, "Voice Mail Server", "Voice mail server string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF1, "Profile 1", "Profile 1 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF2, "Profile 2", "Profile 2 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF3, "Profile 3", "Profile 3 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF4, "Profile 4", "Profile 4 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF5, "Profile 5", "Profile 5 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF6, "Profile 6", "Profile 6 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF7, "Profile 7", "Profile 7 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF8, "Profile 8", "Profile 8 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF9, "Profile 9", "Profile 9 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_COMMON_PROF10, "Profile 10", "Profile 10 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_ACCOUNT_SIPSERVER, "SIP Server", "SIP server string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_ACCOUNT_SIPPORT, "SIP Port", "SIP port string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_ACCOUNT_DISPNAME, "Display Name", "Display name string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_USERNAME, "Username", "Username string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_PASSWORD, "Password", "Password string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_ACCOUNT_AUTHNAME, "Auth Name", "Authorization name string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_DEFAULT, "Default", "Default string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_STATUS, "Status", "Status string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_OUTBOUND_SERVER, "Outbound Server", "Outbound server string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_OUTBOUND_PORT, "Outbound Port", "Outbound port string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_OUTBOUND_NEVER, "Never", "Never string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_AUTO, "Auto", "Auto string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_OUTBOUND_ALWAYS, "Always", "Always string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_REGISTER_SERVER, "Register Server", "Register server string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_REGISTER_PORT, "Register Port", "Register port string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_FIREWALL, "NAT Firewall IP", "NAT firewall ip string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_STUNSERVER, "STUN Server", "STUN server string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_STUNPORT, "STUN Port", "STUN port string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_INTERVAL, "NAT Refresh Interval", "NAT refresh interval");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_STATICNAT, "Static NAT", "Static nat string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_9SEC, "9 Secs", "9 secs string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_15SEC, "15 Secs", "15 secs string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_30SEC, "30 Secs", "30 secs string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PROF_NAT_60SEC, "60 Secs", "6 secs sting");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALL_SETTING, "Call Setting", "Call setting string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_AUTO_ANSWER, "Auto Answer", "Auto answer string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_AUTO_REJECT, "Auto Reject", "Auto reject string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_AUTO_REDIAL, "Auto Redial", "Auto redial string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_HIDE_CALLER_ID, "Hide Caller ID", "Hide caller id string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_DTMF, "DTMF", "DTMF string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_SECURE_RTP, "Secure RTP", "Secure rtp string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_COMFORT_NOISE, "Comfort Noise", "Comfort noise string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_SET_CODEC_ORDER, "Set Codec Order", "Set codec order string");    
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_ANYKEY, "Any Key", "Anykey string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_AUTO, "Auto", "Auto string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_REJECT_UNKNOWN, "Reject Anonymous", "Reject anonymous string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_REJECT_ALL, "Do Not Disturb", "Do not disturb string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_INBAND, "Inband", "Inband string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_OUTBAND, "Outband", "Outband string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC1, "AMR", "Codec 1 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC2, "G.729", "Codec 2 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC3, "G.7231", "Codec 3 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC4, "G.726/16", "Codec 4 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC5, "G.726/24", "Codec 5 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC6, "G.726/32", "Codec 6 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC7, "G.726/40", "Codec 7 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC8, "PCMA", "Codec 8 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC9, "PCMU", "Codec 9 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_CODEC10, "CN", "Codec 10 string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SETTING_PRIORITY, "Priority", "Priority string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NEW_CALL, "New Call", "New call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_DIAL, "Dial", "Dial string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SAVE_PHONEBOOK, "Save to Phonebook", "Save to phonebook string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INPUT_METHOD, "Input Method", "Input method string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SOS, "SOS", "SOS string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_EMERGENCY_NUM, "Emergency Number", "Emergency number string");
#ifdef SIP_CONFORMANCE_TEST
    ADD_APPLICATION_STRING2(STR_ID_VOIP_OPTION_QUERY, "Option Query", "Option query string");
#endif /* SIP_CONFORMANCE_TEST */
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALLING, "Calling", "Calling string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALL_FORWARDED, "Call Forwarded", "Call forwarded string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_REDIALING, "Redialing", "Redialing string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_TIME_UNIT, " time(s)", "Time unit string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_RINGING, "Ringing", "Ringing string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_ANSWER, "Answer", "Answer string");    
    ADD_APPLICATION_STRING2(STR_ID_VOIP_REJECT, "Reject", "Reject string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_HAND_FREE, "H-Free", "Hand free string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_HAND_HELD, "H-Held", "Hand held string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_LOUD_SPEAKER_OFF, "Loud Speaker Off", "Loud speaker off string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_LOUD_SPEAKER_ON, "Loud Speaker On", "Loud speaker on string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALL_OPTION, "Call Option", "Call option string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_HOLD_SINGLE, "Hold Single Call", "Hold single call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_HOLD_CONFERENCE, "Hold Conf. Call", "Hold conference call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_RETRIEVE_SINGLE, "Retrieve Single Call", "Retrieve single call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_RETRIEVE_CONFERENCE, "Retrieve Conf. Call", "Retrieve conference call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SWAP, "Swap", "Swap string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CONFERENCE, "Conference", "Conference string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SPLIT, "Split", "Split string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_END_SINGLE, "End Single Call", "End single call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_END_CONFERENCE, "End Conf. Call", "End conference call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_END_ALL, "End All Calls", "End all call string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_TRANSFER, "Transfer", "Transfer string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_REPLACE, "Replace", "Replace string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PHONEBOOK, "Phonebook", "Phonebook string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SOUND_RECORDER, "Sound Recorder", "Sound recorder string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_MUTE, "Mute", "Mute string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_DTMF, "DTMF", "DTMF string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_HOLD_OK, "Hold Success", "Hold success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_RETRIEVE_OK, "Retrieve Success", "Retrieve success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SWAP_OK, "Swap Success", "Swap success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CONFERENCE_OK, "Conference Success", "Conference success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SPLIT_OK, "Split Success", "Split success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_TRANSFER_OK, "Transfer Success", "Transfer success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_REPLACE_OK, "Replace Success", "Replace success string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALL_END, "Call End", "Call end string");    
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALL_ABORT, "Call Abort", "Call abort error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALL_REJECT, "Call Reject", "Call reject error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_USER_BUSY, "User Busy", "User busy error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_USER_NOT_FOUND, "User Not Found", "User not found error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NO_ACTIVATED_PROFILE, "No Activated Profile", "No activated profile error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_EMPTY_PROFILE_NAME, "Empty Profile Name", "Empty profile name error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_EMPTY_SIP_SERVER, "Empty SIP Server", "Empty sip server error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_EMPTY_OUTBOUND_SERVER, "Empty Outbound Server", "Empty outbound server error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_EMPTY_REGISTER_SERVER, "Empty Register Server", "Empty register server error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_EMPTY_STUN_SERVER, "Empty Stun Server", "Empty stun server error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_EMPTY_USERNAME, "Empty Username", "Empty username error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INVALID_PORT_NUMBER, "Invalid Port Number", "Invalid prot number error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INVALID_USERNAME, "Invalid Username", "Invalid username error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INVALID_AUTHNAME, "Invalid Auth Name", "Invalid authorization name error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INVALID_VM_SERVER, "Invalid Voice Mail Server", "Invalid voice mail server error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INVALID_IP_ADDRESS, "Invalid IP Address", "Invalid ip address error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INVALID_URI, "Invalid URI", "Invalid uri error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CANNOT_DIAL_OWNER, "Cannot Dial to Owner Number", "Cannot dial to owner number error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NOT_ALLOW_TO_DIAL, "Not Allow to Dial", "Not allow to dial error string");;
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NOT_ALLOW_TO_HOLD, "Capacity Full Cannot Hold", "Capacity full cannot hold error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_REGISTER, "Registered", "Registered string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NOT_REGISTER, "Not Registered", "Not registered error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_ALREADY_REGISTER, "Already Registered", "Already registered error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_REGISTER_FAIL, "Register Failed", "Register failed error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_AUTHENTICATION_FAIL, "Authentication Failed", "Authentication failed error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_REQUEST_TIMEOUT, "Request Timeout", "Request timeout error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_INVALID_PARAMETER, "Invalid Parameter", "Invalid parameter error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NETWORK_DOWN, "Network Down", "Network down error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NETWORK_ERROR, "Network Error", "Network error error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NUMBER_MOVE, "Number Moved", "Number moved error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_ACTION_CONFLICT, "Conflict Request", "Conflict request error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_ACTION_INVALID, "Invalid Request", "Invalid request error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_ACTION_FORBIDDEN, "Forbidden Request", "Forbidden request error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CALL_NOT_EXIST, "Call Not Existed", "Call not existed error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SWAP_FAIL, "Swap Failed", "Swap failed error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_CONFERENCE_FAIL, "Conference Failed", "Conference failed error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SPLIT_FAIL, "Split Failed", "Split failed error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_TRANSFER_FAIL, "Transfer Failed", "Transfer failed error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SDP_ERROR, "Incompatible Media", "Incompatible media error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_SIP_ERROR, "SIP Error", "SIP error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_DNS_ERROR, "DNS Error", "DNS error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NAT_ERROR, "NAT Error", "NAT error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_UNKNOWN_ERROR, "Unknown Error", "Unknown error string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_VOICE_MESSAGE, "Voice Message", "Voice message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_FAX_MESSAGE, "Fax Message", "Fax message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_PAGER_MESSAGE, "Pager Message", "Pager message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_MULTIMEDIA_MESSAGE, "Multimedia Message", "Multimedia message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_TEXT_MESSAGE, "Text Message", "Text message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_UNKNOWN_MESSAGE, "Unknown Message", "Unknown message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NEW_MESSAGE, "New / Total Messages:", "New message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_URGENT_MESSAGE, "Urgent / Total Messages:", "Urgent message string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_MSG_UNIT, " msg(s)", "Message unit string");
    ADD_APPLICATION_STRING2(STR_ID_VOIP_NOT_SUPPORT, "Not Support", "Not support error string");
#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */
    /* menu resource */
#ifndef SIP_CONFORMANCE_TEST
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_MAIN,
        MAIN_MENU_SERVICES_MENUID,
        5,
        MENU_ID_VOIP_STATUS,
        MENU_ID_VOIP_SUMMARY,
        MENU_ID_VOIP_PROF_SETTING,
        MENU_ID_VOIP_CALL_SETTING,
        MENU_ID_VOIP_CALL_EDITOR,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_MAIN,
        IMG_ID_VOIP_MAIN));
#else /* SIP_CONFORMANCE_TEST */
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_MAIN,
        MAIN_MENU_SERVICES_MENUID,
        6,
        MENU_ID_VOIP_STATUS,
        MENU_ID_VOIP_SUMMARY,
        MENU_ID_VOIP_PROF_SETTING,
        MENU_ID_VOIP_CALL_SETTING,
        MENU_ID_VOIP_CALL_EDITOR,
        MENU_ID_VOIP_OPTION_QUERY,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_MAIN,
        IMG_ID_VOIP_MAIN));
#endif /* SIP_CONFORMANCE_TEST */
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_STATUS,
    	MENU_ID_VOIP_MAIN,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_LOGIN, /* default string is Login */
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_SUMMARY,
        MENU_ID_VOIP_MAIN,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SUMMARY,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_PROF_SETTING,
    	MENU_ID_VOIP_MAIN,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_PROF_SETTING,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_SETTING_OPTION,
        0,
        2,
        MENU_ID_VOIP_PROF_SETTING_OPTION_ACTIVATE,
        MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_GLOBAL_OPTIONS,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_SETTING_OPTION_ACTIVATE,
        MENU_ID_VOIP_PROF_SETTING_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_GLOBAL_ACTIVATE,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT,
        MENU_ID_VOIP_PROF_SETTING_OPTION,
        5,
        MENU_ID_VOIP_PROF_EDIT_COMMON,
        MENU_ID_VOIP_PROF_EDIT_ACCOUNT,
        MENU_ID_VOIP_PROF_EDIT_OUTBOUND,
        MENU_ID_VOIP_PROF_EDIT_REGISTER,
        MENU_ID_VOIP_PROF_EDIT_NAT,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_GLOBAL_EDIT,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_EDIT_COMMON,
        MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_PROF_EDIT_COMMON,
        IMG_ID_VOIP_PROF_EDIT_COMMON));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_EDIT_ACCOUNT,
        MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_PROF_EDIT_ACCOUNT,
        IMG_ID_VOIP_PROF_EDIT_ACCOUNT));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_EDIT_OUTBOUND,
        MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_PROF_EDIT_OUTBOUND,
        IMG_ID_VOIP_PROF_EDIT_OUTBOUND));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_EDIT_REGISTER,
        MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_PROF_EDIT_REGISTER,
        IMG_ID_VOIP_PROF_EDIT_REGISTER));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_PROF_EDIT_NAT,
        MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_PROF_EDIT_NAT,
        IMG_ID_VOIP_PROF_EDIT_NAT));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_FULL_EDITOR_OPTION, 
        0,
        2,
        MENU_ID_VOIP_FULL_EDITOR_DONE,
        MENU_ID_VOIP_FULL_EDITOR_INPUT_METHOD,
        SHOW, 
        NONMOVEABLE, 
        DISP_LIST, 
        STR_GLOBAL_OPTIONS, 
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_FULL_EDITOR_DONE, 
        MENU_ID_VOIP_FULL_EDITOR_OPTION,
        0,
        SHOW, 
        NONMOVEABLE, 
        DISP_LIST,
        STR_GLOBAL_DONE, 
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_FULL_EDITOR_INPUT_METHOD, 
        MENU_ID_VOIP_FULL_EDITOR_OPTION, 
        0,
        SHOW, 
        NONMOVEABLE, 
        DISP_LIST,
        STR_GLOBAL_INPUT_METHOD, 
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_CALL_SETTING,
    	MENU_ID_VOIP_MAIN,
    	8,
    	MENU_ID_VOIP_SETTING_AUTO_ANSWER,
    	MENU_ID_VOIP_SETTING_AUTO_REJECT,
    	MENU_ID_VOIP_SETTING_AUTO_REDIAL,
    	MENU_ID_VOIP_SETTING_HIDE_CALLER_ID,
    	MENU_ID_VOIP_SETTING_DTMF,
    	MENU_ID_VOIP_SETTING_SECURE_RTP,
    	MENU_ID_VOIP_SETTING_COMFORT_NOISE,
    	MENU_ID_VOIP_SETTING_SET_CODEC_ORDER,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_CALL_SETTING,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SETTING_AUTO_ANSWER,
    	MENU_ID_VOIP_CALL_SETTING,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_AUTO_ANSWER,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SETTING_AUTO_REJECT,
    	MENU_ID_VOIP_CALL_SETTING,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_AUTO_REJECT,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SETTING_AUTO_REDIAL,
    	MENU_ID_VOIP_CALL_SETTING,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_AUTO_REDIAL,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SETTING_HIDE_CALLER_ID,
    	MENU_ID_VOIP_CALL_SETTING,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_HIDE_CALLER_ID,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SETTING_DTMF,
    	MENU_ID_VOIP_CALL_SETTING,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_DTMF,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SETTING_SECURE_RTP,
    	MENU_ID_VOIP_CALL_SETTING,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_SECURE_RTP,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_SETTING_COMFORT_NOISE,
        MENU_ID_VOIP_CALL_SETTING,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_COMFORT_NOISE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SETTING_SET_CODEC_ORDER,
    	MENU_ID_VOIP_CALL_SETTING,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SETTING_SET_CODEC_ORDER,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_CALL_EDITOR,
    	MENU_ID_VOIP_MAIN,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_NEW_CALL,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_CALL_EDITOR_OPTION,
        0,
        4,
        MENU_ID_VOIP_CALL_EDITOR_DIAL,
        MENU_ID_VOIP_CALL_EDITOR_SAVE_PHONEBOOK,
        MENU_ID_VOIP_CALL_EDITOR_INPUT_METHOD,
        MENU_ID_VOIP_CALL_EDITOR_SOS,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_GLOBAL_OPTIONS,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_CALL_EDITOR_DIAL,
        MENU_ID_VOIP_CALL_EDITOR_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_DIAL,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_CALL_EDITOR_SAVE_PHONEBOOK,
        MENU_ID_VOIP_CALL_EDITOR_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SAVE_PHONEBOOK,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_CALL_EDITOR_INPUT_METHOD,
        MENU_ID_VOIP_CALL_EDITOR_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_INPUT_METHOD,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_CALL_EDITOR_SOS,
        MENU_ID_VOIP_CALL_EDITOR_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SOS,
        0));
#ifdef SIP_CONFORMANCE_TEST
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_OPTION_QUERY,
    	MENU_ID_VOIP_MAIN,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_OPTION_QUERY,
        0));
#endif /* SIP_CONFORMANCE_TEST */
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_CALL_OPTION,
        0,
        16,
        MENU_ID_VOIP_HOLD_SINGLE,
        MENU_ID_VOIP_HOLD_CONFERENCE,
        MENU_ID_VOIP_RETRIEVE_SINGLE,
        MENU_ID_VOIP_RETRIEVE_CONFERENCE,
        MENU_ID_VOIP_SWAP,
        MENU_ID_VOIP_CONFERENCE,
        MENU_ID_VOIP_SPLIT,
        MENU_ID_VOIP_END_SINGLE,
        MENU_ID_VOIP_END_CONFERENCE,
        MENU_ID_VOIP_END_ALL,
        MENU_ID_VOIP_TRANSFER,
        MENU_ID_VOIP_CALL_EDITOR,
        MENU_ID_VOIP_PHONEBOOK,
        MENU_ID_VOIP_SOUND_RECORDER,
        MENU_ID_VOIP_MUTE,
        MENU_ID_VOIP_DTMF,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_CALL_OPTION,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_HOLD_SINGLE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_HOLD_SINGLE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_HOLD_CONFERENCE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_HOLD_CONFERENCE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_RETRIEVE_SINGLE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_RETRIEVE_SINGLE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_RETRIEVE_CONFERENCE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_RETRIEVE_CONFERENCE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SWAP,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SWAP,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_CONFERENCE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_CONFERENCE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_SPLIT,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SPLIT,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_END_SINGLE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_END_SINGLE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_END_CONFERENCE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_END_CONFERENCE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_END_ALL,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_END_ALL,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_TRANSFER,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_TRANSFER,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_PHONEBOOK,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_PHONEBOOK,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_SOUND_RECORDER,
        MENU_ID_VOIP_CALL_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_SOUND_RECORDER,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_MUTE,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_MUTE,
        0));
    ADD_APPLICATION_MENUITEM((
    	MENU_ID_VOIP_DTMF,
    	MENU_ID_VOIP_CALL_OPTION,
    	0,
    	SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_DTMF,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_TRANSFER_OPTION,
        0,
        2,
        MENU_ID_VOIP_TRANSFER_OPTION_DONE,
        MENU_ID_VOIP_TRANSFER_OPTION_INPUT_METHOD,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_GLOBAL_OPTIONS,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_TRANSFER_OPTION_DONE,
        MENU_ID_VOIP_TRANSFER_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_TRANSFER,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VOIP_TRANSFER_OPTION_INPUT_METHOD,
        MENU_ID_VOIP_TRANSFER_OPTION,
        0,
        SHOW,
        NONMOVEABLE,
        DISP_LIST,
        STR_ID_VOIP_INPUT_METHOD,
        0));
}
#endif /* DEVELOPER_BUILD_FIRST_PASS */
#endif /* __MMI_VOIP__ */
#endif /* RES_VOIP_C */

