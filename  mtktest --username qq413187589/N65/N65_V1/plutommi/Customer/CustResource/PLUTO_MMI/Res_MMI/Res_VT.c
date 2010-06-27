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
 *  Res_VT.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file populates resource for VT appliction.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#ifndef RES_VT_C
#define RES_VT_C
#include "MMI_features.h"

#ifdef __MMI_VIDEO_TELEPHONY__

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "VTResDef.h"
#include "UCMResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/**************************************************************
 * FUNCTION
 *  VTResourceData
 * DESCRIPTION
 *  Register all the resources required by VT application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 **************************************************************/
void VTResourceData(void)
{
    /* image resource */
    ADD_APPLICATION_IMAGE2(IMG_ID_VT_OUTGOING_CALL, CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\Outgoing\\\\CL_VOutgoing.gif", "Outgoing call image");
    
    /* string resource */
    ADD_APPLICATION_STRING2(STR_ID_VT_VIDEO_CALL, "Video Call", "Video Call string");
    ADD_APPLICATION_STRING2(STR_ID_VT_MAKE_VIDEO_CALL, "Make Video Call", "Video Call string");
    ADD_APPLICATION_STRING2(STR_ID_VT_START_CAMERA, "Start Camera", "Start Camera string");
    ADD_APPLICATION_STRING2(STR_ID_VT_STOP_CAMERA, "Stop Camera", "Stop Camera string");    
    ADD_APPLICATION_STRING2(STR_ID_VT_MUTE_MIC, "Mute Microphone", "Mute Microphone string");    
    ADD_APPLICATION_STRING2(STR_ID_VT_UNMUTE_MIC, "Unmute Microphone", "Unmute Microphone string");    
    ADD_APPLICATION_STRING2(STR_ID_VT_MUTE_SPEAKER, "Mute Speaker", "Mute Speaker string");    
    ADD_APPLICATION_STRING2(STR_ID_VT_UNMUTE_SPEAKER, "Unmute Speaker", "Unmute Speaker string");    
    ADD_APPLICATION_STRING2(STR_ID_VT_SWITCH_PIC, "Switch Picture", "Switch Picture string");    
    ADD_APPLICATION_STRING2(STR_ID_VT_HIDE_SMALL_PIC, "Hide Small Picture", "Hide Small Picture string");    
    ADD_APPLICATION_STRING2(STR_ID_VT_UNHIDE_SMALL_PIC, "Unhide Small Picture", "Unhide Small Picture string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_ALTERNATIVE_PIC, "Alternative Picture", "Alternative Picture string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_VIDEO_CALL_SETTING, "Video Call Setting", "Video Call Setting string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_ADVANCED, "Advanced", "Advanced string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_ANSWER_MODE, "Answer Mode", "Answer Mode string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_DIAL_MODE, "Dial Mode", "Dial Mode string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_IMAGE_IN_VIDEO_CALL, "Image in Video Call", "Image in Video Call Mode string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_AUDIO_OPTION, "Audio Option", "Audio Option string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_PROMPT, "Prompt", "Prompt string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_MIC_OFF, "Microphone off", "Microphone off string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_SPEAKER_OFF, "Speaker off", "Microphone off string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_START_CALL_WITH, "Start Call With", "Start Call With string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_DEFAULT, "Default", "Default string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_USER_DEFINE, "User Define", "User Define string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_FAIL_TO_MAKE_VIDEO_CALL, "Failed to Make Video Call", "Failed to Make Video Call string");
    ADD_APPLICATION_STRING2(STR_ID_VT_MAKE_VOICE_CALL, "Make Voice Call", "Make Voice Call string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_REDIAL_VIDEO_CALL, "Redial Video Call", "Redial Video Call string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_SEND_MMS, "Send Multimedia Msg", "Redial Video Call string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_SEND_SMS, "Send Text Msg", "Redial Video Call string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_BRIGHTNESS, "Brightness", "Brightness string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_VIDEO_QUALITY, "Video Quality", "Video Quality string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_RECORD_AUDIO, "Record Audio", "Record Audio string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_SAVE_PICTURE, "Save Picture", "Save Picture string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_MIRROR_IMAGE, "Mirror Image", "Mirror Image string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_SMOOTH, "Smooth", "Smooth string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_NORMAL, "Normal", "Normal string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_SHARP, "Sharp", "Sharp string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_START_CAMERA_QUERY, "Start Camera to Send Local Image", "Start Camera Query string");        
    ADD_APPLICATION_STRING2(STR_ID_VT_SWITCH_AUDIO_PATH, "Switch Audio Path", "Switch Audio Path string");
    
    /* menu resource */

    /* MMI VT main */
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_MAIN,
                            MAIN_MENU_CALL_CENTER, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_VIDEO_CALL, IMG_ID_UCM_VIDEO));

    /* VT option */
    ADD_APPLICATION_MENUITEM2((MENU_ID_VT_INCALL_OPT, 0,
                            MENU_ID_VT_INCALL_OPT_MAKE_VIDEO_CALL,
                            MENU_ID_VT_INCALL_OPT_START_CAMERA,
                            MENU_ID_VT_INCALL_OPT_STOP_CAMERA,
                            MENU_ID_VT_INCALL_OPT_MUTE_MIC,
                            MENU_ID_VT_INCALL_OPT_UNMUTE_MIC,
                            MENU_ID_VT_INCALL_OPT_MUTE_SPEAKER,
                            MENU_ID_VT_INCALL_OPT_UNMUTE_SPEAKER,
                            MENU_ID_VT_INCALL_OPT_SWITCH_PIC,
                            MENU_ID_VT_INCALL_OPT_HIDE_SMALL_PIC,
                            MENU_ID_VT_INCALL_OPT_UNHIDE_SMALL_PIC,
                            MENU_ID_VT_INCALL_OPT_ALT_PIC,
                            MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH,
                            MENU_ID_VT_INCALL_OPT_SETTING,
                            MENU_ID_VT_INCALL_OPT_ADVANCE,
                            MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_MAKE_VIDEO_CALL,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_MAKE_VIDEO_CALL, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_START_CAMERA,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_START_CAMERA, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_STOP_CAMERA,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_STOP_CAMERA, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_MUTE_MIC,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_MUTE_MIC, 0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_UNMUTE_MIC,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_UNMUTE_MIC, 0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_MUTE_SPEAKER,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_MUTE_SPEAKER, 0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_UNMUTE_SPEAKER,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_UNMUTE_SPEAKER, 0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_SWITCH_PIC,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_SWITCH_PIC, 0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_HIDE_SMALL_PIC,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_HIDE_SMALL_PIC, 0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_UNHIDE_SMALL_PIC,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_UNHIDE_SMALL_PIC, 0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_ALT_PIC,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_ALTERNATIVE_PIC, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH,
                            MENU_ID_VT_INCALL_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_SWITCH_AUDIO_PATH, 0));
        
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_VT_INCALL_OPT_SETTING, MENU_ID_VT_INCALL_OPT,
                            MENU_ID_VT_SETTING_ANSWER_MODE,
                            MENU_ID_VT_SETTING_DIAL_MODE,
                            MENU_ID_VT_SETTING_INCALL_IMAGE,
                            MENU_ID_VT_SETTING_AUDIO_OPT,
                            MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_ID_VT_VIDEO_CALL_SETTING,0));    

    ADD_APPLICATION_MENUITEM2((MENU_ID_VT_INCALL_OPT_ADVANCE, MENU_ID_VT_INCALL_OPT,
                            //MENU_ID_VT_INCALL_OPT_ADVANCE_BRIGHTNESS,
                            MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY,
                            //MENU_ID_VT_INCALL_OPT_ADVANCE_RECORD_AUDIO,
                            //MENU_ID_VT_INCALL_OPT_ADVANCE_SAVE_PIC,
                            MENU_ID_VT_INCALL_OPT_ADVANCE_MIRROR_IMAGE,
                            MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_ID_VT_ADVANCED,0));    

    /* video call setting */
    ADD_APPLICATION_MENUITEM2((MENU_ID_VT_SETTING_ANSWER_MODE, MENU_ID_VT_INCALL_OPT_SETTING,
                            MENU_ID_VT_SETTING_ANSWER_MODE_PROMPT,
                            MENU_ID_VT_SETTING_ANSWER_MODE_START_CAMERA,
                            MENU_ID_VT_SETTING_ANSWER_MODE_STOP_CAMERA,
                            MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_ID_VT_ANSWER_MODE,0));     

    ADD_APPLICATION_MENUITEM2((MENU_ID_VT_SETTING_DIAL_MODE, MENU_ID_VT_INCALL_OPT_SETTING,
                            MENU_ID_VT_SETTING_DIAL_MODE_START_CAMERA,
                            MENU_ID_VT_SETTING_DIAL_MODE_STOP_CAMERA,
                            MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_ID_VT_DIAL_MODE,0));     

    ADD_APPLICATION_MENUITEM2((MENU_ID_VT_SETTING_INCALL_IMAGE, MENU_ID_VT_INCALL_OPT_SETTING,
                            MENU_ID_VT_SETTING_INCALL_IMAGE_DEFAULT,
                            MENU_ID_VT_SETTING_INCALL_IMAGE_USER_DEFINE,
                            MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_ID_VT_IMAGE_IN_VIDEO_CALL,0));   

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_AUDIO_OPT,
                            MENU_ID_VT_INCALL_OPT_SETTING, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_AUDIO_OPTION, 0));   


    /* answer mode */
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_ANSWER_MODE_PROMPT,
                            MENU_ID_VT_SETTING_ANSWER_MODE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_PROMPT, 0));       
    
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_ANSWER_MODE_START_CAMERA,
                            MENU_ID_VT_SETTING_ANSWER_MODE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_START_CAMERA, 0));       

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_ANSWER_MODE_STOP_CAMERA,
                            MENU_ID_VT_SETTING_ANSWER_MODE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_STOP_CAMERA, 0));       

    /* dial mode */    
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_DIAL_MODE_START_CAMERA,
                            MENU_ID_VT_SETTING_DIAL_MODE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_START_CAMERA, 0));       

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_DIAL_MODE_STOP_CAMERA,
                            MENU_ID_VT_SETTING_DIAL_MODE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_STOP_CAMERA, 0));      
    
    /* incall image setting */    
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_INCALL_IMAGE_DEFAULT,
                            MENU_ID_VT_SETTING_INCALL_IMAGE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_DEFAULT, 0));       

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_SETTING_INCALL_IMAGE_USER_DEFINE,
                            MENU_ID_VT_SETTING_INCALL_IMAGE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_USER_DEFINE, 0));       

    /* advance */
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_ADVANCE_BRIGHTNESS,
                            MENU_ID_VT_INCALL_OPT_ADVANCE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_BRIGHTNESS, 0));       

    ADD_APPLICATION_MENUITEM2((MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, MENU_ID_VT_INCALL_OPT_ADVANCE,
                            MENU_ID_VT_VIDEO_QUALITY_SMOOTH,
                            MENU_ID_VT_VIDEO_QUALITY_NORMAL,
                            MENU_ID_VT_VIDEO_QUALITY_SHARP,
                            MENU_ITEM_END,
                    		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                    		STR_ID_VT_VIDEO_QUALITY,0));     

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_ADVANCE_RECORD_AUDIO,
                            MENU_ID_VT_INCALL_OPT_ADVANCE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_RECORD_AUDIO, 0));       

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_ADVANCE_SAVE_PIC,
                            MENU_ID_VT_INCALL_OPT_ADVANCE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_SAVE_PICTURE, 0));       
    
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_INCALL_OPT_ADVANCE_MIRROR_IMAGE,
                            MENU_ID_VT_INCALL_OPT_ADVANCE, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_MIRROR_IMAGE, 0));       


    /* video quality */
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_VIDEO_QUALITY_SMOOTH,
                            MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_SMOOTH, 0));       
    
    ADD_APPLICATION_MENUITEM((MENU_ID_VT_VIDEO_QUALITY_NORMAL,
                            MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_NORMAL, 0));       

    ADD_APPLICATION_MENUITEM((MENU_ID_VT_VIDEO_QUALITY_SHARP,
                            MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_ID_VT_SHARP, 0));
}
#endif /* DEVELOPER_BUILD_FIRST_PASS */
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* RES_UCM_C */

