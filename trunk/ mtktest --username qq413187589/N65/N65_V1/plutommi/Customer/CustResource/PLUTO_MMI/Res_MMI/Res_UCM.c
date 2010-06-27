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
 *  Res_UCM.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file populates resource for UCM appliction.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#ifndef RES_UCM_C
#define RES_UCM_C
#include "MMI_features.h"

#ifdef __MMI_UCM__

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "UCMResDef.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_UNIFIED_MESSAGE__)
#include "UnifiedMessageResDef.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */

#include "ConnectivityResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/**************************************************************
 * FUNCTION
 *  UCMResourceData
 * DESCRIPTION
 *  Register all the resources required by UCM application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 **************************************************************/
void UCMResourceData(void)
{
    /* image resource */
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_OUTGOING_CALL, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\CL_incom.gif", "Outgoing call image");
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_CONNECTED,	CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\Call\\\\SB_CALL.bmp","Image of Call Connected -In Call");
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_CALL_STATE_ACTIVE, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_ACT.bmp", "Active call image");
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_CALL_STATE_HOLD, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_HOLD.bmp", "Held call image");    
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_SUBLCD_CALLING, CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\Call\\\\SB_MOMT.GIF","Sub-LCD image of calling");
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_CALL_HISTORY, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CallCenter\\\\CC_callhistory.pbm", "call history menu item icon");
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_VIDEO, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CallCenter\\\\CC_videocall.pbm", "video call menu item icon");
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_SETTING, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CallCenter\\\\CC_setting.pbm", "general call setting menu item icon");    
    ADD_APPLICATION_IMAGE2(IMG_ID_UCM_ACTIVE_CALL, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CallCenter\\\\CC_activecall.pbm", "default active call icon");
    
    /* string resource */
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALLING, "Calling", "Calling string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VOIP_CALLING, "VoIP Calling", "VoIP Calling string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_REJECT, "Reject", "Reject string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_ANSWER, "Answer", "Answer string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_DEFLECT, "Deflect", "Deflect string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_BACKGROUND_SOUND, "Call Background Sound", "Call Background Sound string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_HAND_HELD, "H-Held", "Hand Held string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_HAND_FREE, "H-Free", "Hand Free string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VOIP_ACTIVE, "VoIP Active", "VoIP Active string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VOIP_HOLD, "VoIP Hold", "VoIP Hold string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VOICE_ACTIVE, "Voice Active", "Voice Active string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VOICE_HOLD, "Voice Hold", "Voice Hold string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_PROCESSING, "Processing", "Processing string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_RELEASING, "Releasing", "Releasing string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_NO_NUMBER_TO_DIAL, "No Number to Dial", "No Number to Dial string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_NOT_SOS_NUMBER, "Emergency Call Only", "Emergency Call Only string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_NOT_ALLOW_TO_DIAL, "Not Allow to Dial", "Not Allow to Dial string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_NOT_ALLOW_TO_ACCEPT, "Not Allow to Accept", "Not Allow to Accept string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_NOT_ALLOW_TO_HOLD, "Not Allow to Hold", "Not Allow to Hold string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_NOT_ALLOW_TO_SWAP, "Not Allow to Swap", "Not Allow to Swap string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_ABORT, "Call Abort", "Call Abort string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_HOLD, "Call Hold", "Call Hold string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_RETRIEVE, "Call Retrieve", "Call Retrieve string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_SWAP, "Call Swap", "Call Swap string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_CONFERENCE, "Call Conference", "Call Conference string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_SPLIT, "Call Split", "Call Split string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_END, "Call End", "Call End string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_TRANSFER, "Call Transfer", "Call Transfer string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_HOLD, "Hold", "Hold string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_RETRIEVE, "Retrieve", "Hold string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SWAP, "Swap", "Swap string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CONFERENCE, "Conference", "Conference string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SPLIT, "Split", "Split string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_END_SINGLE, "End Single Call", "End Single Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_END_CONFERENCE, "End Conf. Call", "End Conference Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_END_ALL, "End All Calls", "End All Calls string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_END_CALL, "End Call", "End Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_HOLD_SINGLE, "Hold Single Call", "Hold Single Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_HOLD_CONFERENCE, "Hold Conf. Call", "Hold Conference Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_RETRIEVE_SINGLE, "Retrieve Single Call", "Retrieve Single Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_RETRIEVE_CONFERENCE, "Retrieve Conf. Call", "Retrieve Conference Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_TRANSFER, "Transfer", "Transfer string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_NEW_CALL, "New Call", "New Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_PHONEBOOK, "Phonebook", "Phonebook string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SMS, "SMS", "SMS string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SOUND_RECORDER, "Sound Recorder", "Sound Recorder string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_BACKGROUND_SOUND, "Background Sound", "Background Sound string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_MUTE, "Mute", "Mute string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_DTMF, "DTMF", "DTMF string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SAVE_TO_PHONEBOOK, "Save to Phonebook", "Save to Phonebook string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SELECT_FROM_PHONEBOOK, "Select from Phonebook", "Select from Phonebook string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CALL_CENTER, "Call Center", "Call Center string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_GENERAL_CALL_SETTING, "General Call Setting", "General Call Setting string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_MORE, "More...", "More... string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_LOUD_SPEAKER_OFF, "Loud Speaker Off", "Loud speaker off string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_LOUD_SPEAKER_ON, "Loud Speaker On", "Loud speaker on string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VOICE_CALL, "Voice Call", "Voice Call on string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VOIP_CALL, "VoIP Call", "VoIP Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SWITCH_AUDIO_PATH, "Switch Audio Path", "Switch Audio Path string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_ACTIVE, "Active", "Active string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_VIDEO_CALL, "Video Call", "Video Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_DIALING_VIDEO_CALL, "Dialing Video Call", "Dialing Video Call string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_CTM_CONNECT, "CTM Connect", "CTM Connect");
    ADD_APPLICATION_STRING2(STR_ID_UCM_REPLACE, "Replace", "UCM Replace string");    
    ADD_APPLICATION_STRING2(STR_ID_UCM_REDIAL_FROM_OTHER_SIM, "Redial from the other SIM", "UCM redial from the other SIM string");    
    ADD_APPLICATION_STRING2(STR_ID_UCM_SIM1_VOICE_CALL, "SIM1 Voice Call", "SIM1 Voice Call on string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SIM2_VOICE_CALL, "SIM2 Voice Call", "SIM2 Voice Call on string");    
    ADD_APPLICATION_STRING2(STR_ID_UCM_SIM1_VOICE_ACTIVE, "SIM1 Voice Active", "Voice Active string");
    ADD_APPLICATION_STRING2(STR_ID_UCM_SIM1_VOICE_HOLD, "SIM1 Voice Hold", "Voice Hold string");
    
    /* menu resource */

    /* call center */
    ADD_APPLICATION_MENUITEM2((
        MAIN_MENU_CALL_CENTER,
        
    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
        MAIN_MENU_PIM_MENU_ID,
    #else
        IDLE_SCREEN_MENU_ID,
    #endif
    #ifndef __MMI_DUAL_SIM_MASTER__
        MAIN_MENU_CALL_HISTORY,
    #else /* __MMI_DUAL_SIM_MASTER__ */
        MENU_MTPNP_DM_CALL_HISTORY,
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __MMI_VOIP__
        MENU_ID_VOIP_MAIN,
    #endif /* __MMI_VOIP__ */
    #ifdef __MMI_VIDEO_TELEPHONY__
        MENU_ID_VT_MAIN,
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        MENU_ID_UCM_CALL_SETTING,
        MENU_ITEM_END,
        SHOW,MOVEABLEWITHINPARENT|INSERTABLE,1,STR_ID_UCM_CALL_CENTER, MAIN_MENU_CALL_HISTORY_ICON));

    /* Call setting */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_CALL_SETTING,
                                MAIN_MENU_CALL_CENTER,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                MENU_ID_UCM_CALL_SETTING_SIM1,
                                MENU_MTPNP_CALL_SETTING,
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                            #ifndef __MMI_DUAL_SIM_MASTER__
                            #ifndef __MMI_REMOVE_CALLER_ID__
                                MENU_CALLER_ID,
                            #endif /* __MMI_REMOVE_CALLER_ID__ */
                                MENU8237_SCR8093_MNGCALL_MENU_WAIT,
                                MENU8237_SCR8093_MNGCALL_MENU_FWD,
                                MENU8237_SCR8093_MNGCALL_MENU_BARRING,
                            #ifdef __MMI_CM_BLACK_LIST__
                                MENU_SETTING_BLACK_LIST,
                            #endif /* __MMI_CM_BLACK_LIST__ */
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                                MENU9140_AUTO_REDIAL,
                                MENU_SETTING_SPEED_DIAL,
                            #ifdef __IP_NUMBER__
                                MENU_SETTING_IP_NUMBER,
                            #endif
                            #ifdef __MMI_BG_SOUND_EFFECT__
                                MENU_ID_UCM_CALL_SETTING_BGS,
                            #endif                            
                                MENU_ID_UCM_CALL_SETTING_MORE,
                                MENU_ITEM_END,
                                SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                                STR_ID_UCM_GENERAL_CALL_SETTING,
                                IMG_ID_UCM_SETTING));

    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_CALL_SETTING_MORE,
                                MENU_ID_UCM_CALL_SETTING,
                            #ifndef __MMI_DISABLE_CALL_TIME_DISPLAY__
                                MENU_SETTING_CALL_TIME_DISPLAY,
                            #endif 
                                MENU_SETTING_CALL_REMINDER,
                            #ifdef __MMI_CH_QUICK_END__
                                MENU_CALL_HISTORY_QUICK_END,
                            #endif
                            #ifndef __MMI_DUAL_SIM_MASTER__
                                MENU_LINE_SWCH,
                            #ifndef __MMI_REMOVE_CUG__
                                MENU_SETTING_CALL_CLOSED_GP,
                            #endif
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                            #ifdef __CTM_SUPPORT__
                                MITEM_CTM_MENU,
                            #endif 
  
                                MENU_ITEM_END,
                        		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                        		STR_ID_UCM_MORE,0));
                            
#ifdef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_CALL_SETTING_SIM1,
                                MENU_ID_UCM_CALL_SETTING,
                            #ifndef __MMI_REMOVE_CALLER_ID__
                                MENU_CALLER_ID,
                            #endif /* __MMI_REMOVE_CALLER_ID__ */
                                MENU8237_SCR8093_MNGCALL_MENU_WAIT,
                                MENU8237_SCR8093_MNGCALL_MENU_FWD,
                                MENU8237_SCR8093_MNGCALL_MENU_BARRING,
                                MENU_LINE_SWCH,
                            #ifdef __MMI_CM_BLACK_LIST__
                                MENU_SETTING_BLACK_LIST,
                            #endif /* __MMI_CM_BLACK_LIST__ */
                            #ifndef __MMI_REMOVE_CUG__
                                MENU_SETTING_CALL_CLOSED_GP,
                            #endif
                                MENU_ITEM_END,
                                SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                                STRING_MTPNP_CARD1_CALL_SETTING,0));
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_BG_SOUND_EFFECT__                            
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_CALL_SETTING_BGS,
                            MENU_ID_UCM_CALL_SETTING, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_UCM_BACKGROUND_SOUND, 0));
#endif /* __MMI_BG_SOUND_EFFECT__ */
    
    /* Incoming call option */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_INCOMING_OPTION,0,
                        		MENU_ID_UCM_INCOMING_OPTION_ANSWER, 
                        		MENU_ID_UCM_INCOMING_OPTION_DEFLECT,
                        		MENU_ID_UCM_INCOMING_OPTION_REPLACE,
                            #ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
                        		MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM,
                            #endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */
                        		MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND,
                        		MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH,
                                MENU_ITEM_END,
                        		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                        		STR_GLOBAL_OPTIONS,0));
    /* In-call option */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_INCALL_OPTION,0,
                                MENU_ID_UCM_INCALL_OPTION_HOLD_SINGLE,
                                MENU_ID_UCM_INCALL_OPTION_HOLD_CONF,
                                MENU_ID_UCM_INCALL_OPTION_RETRIEVE_SINGLE,
                                MENU_ID_UCM_INCALL_OPTION_RETRIEVE_CONF,
                                MENU_ID_UCM_INCALL_OPTION_SWAP,
                                MENU_ID_UCM_INCALL_OPTION_CONF,
                                MENU_ID_UCM_INCALL_OPTION_SPLIT,
                                MENU_ID_UCM_INCALL_OPTION_END_SINGLE,
                                MENU_ID_UCM_INCALL_OPTION_END_CONF,
                                MENU_ID_UCM_INCALL_OPTION_END_ALL,
                                MENU_ID_UCM_INCALL_OPTION_TRANSFER,
                                MENU_ID_UCM_INCALL_OPTION_NEW_CALL,
                                MENU_ID_UCM_INCALL_OPTION_PHONEBOOK,
                                MENU_ID_UCM_INCALL_OPTION_SMS,
                                MENU_ID_UCM_INCALL_OPTION_SOUND_RECORDER,
                                MENU_ID_UCM_INCALL_OPTION_BACKGROUND_SOUND,
                                MENU_ID_UCM_INCALL_OPTION_MUTE,
                                MENU_ID_UCM_INCALL_OPTION_DTMF,
                                MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH,
                                MENU_ID_UCM_INCALL_OPTION_CONNECT_LAST_BT_DEVICE,
                                MENU_ID_UCM_INCALL_OPTION_CTM_CONNECT,
                                MENU_ITEM_END,
                        		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                        		STR_GLOBAL_OPTIONS,0));
        
    /* Incoming call option menu item */
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCOMING_OPTION_ANSWER,
                                MENU_ID_UCM_INCOMING_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_ANSWER, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCOMING_OPTION_DEFLECT,
                                MENU_ID_UCM_INCOMING_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_DEFLECT, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCOMING_OPTION_REPLACE,
                                MENU_ID_UCM_INCOMING_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_REPLACE, 0));
    
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM,
                                MENU_ID_UCM_INCOMING_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_REDIAL_FROM_OTHER_SIM, 0));
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND,
                                MENU_ID_UCM_INCOMING_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_CALL_BACKGROUND_SOUND, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH,
                                MENU_ID_UCM_INCOMING_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_SWITCH_AUDIO_PATH, 0));

    /* In-call option menu item */
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_HOLD_SINGLE,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_HOLD_SINGLE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_HOLD_CONF,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_HOLD_CONFERENCE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_RETRIEVE_SINGLE,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_RETRIEVE_SINGLE, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_RETRIEVE_CONF,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_RETRIEVE_CONFERENCE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_SWAP,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_SWAP, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_CONF,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_CONFERENCE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_SPLIT,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_SPLIT, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_END_SINGLE,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_END_SINGLE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_END_CONF,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_END_CONFERENCE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_END_ALL,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_END_ALL, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_TRANSFER,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_TRANSFER, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_INCALL_OPTION_NEW_CALL, MENU_ID_UCM_INCALL_OPTION,
                        		MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOICE,
                            #ifdef __MMI_VOIP__
                        		MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOIP, 
                            #endif /* __MMI_VOIP__ */
                                MENU_ITEM_END,
                        		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                        		STR_ID_UCM_NEW_CALL,0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_PHONEBOOK,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_PHONEBOOK, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_SMS,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            #ifdef __MMI_UNIFIED_MESSAGE__
                                STR_UM_MAIN_MENU_TITLE_ID,
                            #else /*__MMI_UNIFIED_MESSAGE__ */
                                STR_ID_UCM_SMS, 
                            #endif /* __MMI_UNIFIED_MESSAGE__ */
                                0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_SOUND_RECORDER,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_SOUND_RECORDER, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_BACKGROUND_SOUND,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_BACKGROUND_SOUND, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_MUTE,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_MUTE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_DTMF,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_DTMF, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_SWITCH_AUDIO_PATH, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_CONNECT_LAST_BT_DEVICE,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_BT_CONNECT_LAST_HEADSET, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_CTM_CONNECT,
                                MENU_ID_UCM_INCALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_CTM_CONNECT, 0));

    /* New call */
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOICE,
                                MENU_ID_UCM_INCALL_OPTION_NEW_CALL, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_VOICE_CALL, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOIP,
                                MENU_ID_UCM_INCALL_OPTION_NEW_CALL, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_VOIP_CALL, 0));

    /* New call option */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_NEW_CALL_OPTION, 0,
                            MENU_ID_UCM_NEW_CALL_OPTION_DIAL,
                        #ifdef __MMI_DUAL_SIM_MASTER__
                            MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2,
                        #endif  /* __MMI_DUAL_SIM_MASTER__ */
                            MENU_ID_UCM_NEW_CALL_OPTION_SAVE,
                            MENU_ITEM_END,
                            SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                            STR_GLOBAL_OPTIONS,0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_NEW_CALL_OPTION_DIAL,
                                MENU_ID_UCM_NEW_CALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                STR_ID_UCM_SIM1_VOICE_CALL,
                            #else 
                                STR_GLOBAL_DIAL,
                            #endif
                                0));

#ifdef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2,
                              MENU_ID_UCM_NEW_CALL_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_UCM_SIM2_VOICE_CALL, 0));
#endif /* __MMI_DUAL_SIM_MASTER__ */
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_NEW_CALL_OPTION_SAVE,
                                MENU_ID_UCM_NEW_CALL_OPTION, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_SAVE_TO_PHONEBOOK, 0));

    /* MO call type selection */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UCM_CALL_TYPE, 0,
                                MENU_ID_UCM_CALL_TYPE_VOICE,
                                
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                MENU_ID_UCM_CALL_TYPE_VOICE_SIM2,
                            #endif /* __MMI_DUAL_SIM_MASTER__ */
                		    
                            #ifdef __MMI_VOIP__
                                MENU_ID_UCM_CALL_TYPE_VOIP,
                            #endif /* __MMI_VOIP__ */

                            #ifdef __MMI_VIDEO_TELEPHONY__
                                MENU_ID_UCM_CALL_TYPE_VIDEO,
                            #endif /* __MMI_VIDEO_TELEPHONY__ */
                            
                                MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_GLOBAL_DIAL,0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_CALL_TYPE_VOICE,
                                MENU_ID_UCM_CALL_TYPE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            #ifdef __MMI_DUAL_SIM_MASTER__
                                STR_ID_UCM_SIM1_VOICE_CALL,                                
                            #else
                                STR_ID_UCM_VOICE_CALL,
                            #endif
                                0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_CALL_TYPE_VOIP,
                                MENU_ID_UCM_CALL_TYPE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_VOIP_CALL, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_CALL_TYPE_VIDEO,
                                MENU_ID_UCM_CALL_TYPE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_VIDEO_CALL, 0));    

#ifdef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_CALL_TYPE_VOICE_SIM2,
                                MENU_ID_UCM_CALL_TYPE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_ID_UCM_SIM2_VOICE_CALL, 0));
#endif /* __MMI_DUAL_SIM_MASTER__ */

}
#endif /* DEVELOPER_BUILD_FIRST_PASS */
#endif /* __MMI_UCM__ */
#endif /* RES_UCM_C */

