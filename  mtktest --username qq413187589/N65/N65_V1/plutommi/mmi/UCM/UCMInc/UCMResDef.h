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
 *  UCMResDef.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_RES_DEF_H
#define UCM_RES_DEF_H

#include "MMIDatatype.h"

#define UCM_STRING_BASE					(UCM_BASE + 1)
#define UCM_IMAGE_BASE					(UCM_BASE + 1)
#define UCM_SCREEN_BASE					(UCM_BASE + 1)

typedef enum
{
    STR_ID_UCM_CALLING = (UCM_BASE + 1),
    STR_ID_UCM_VOIP_CALLING,
    STR_ID_UCM_REJECT,
    STR_ID_UCM_ANSWER,
    STR_ID_UCM_DEFLECT,
    STR_ID_UCM_CALL_BACKGROUND_SOUND,
    STR_ID_UCM_HAND_HELD,
    STR_ID_UCM_HAND_FREE,
    STR_ID_UCM_VOIP_ACTIVE,
    STR_ID_UCM_VOIP_HOLD,
    STR_ID_UCM_VOICE_ACTIVE,
    STR_ID_UCM_VOICE_HOLD,
    STR_ID_UCM_PROCESSING,
    STR_ID_UCM_RELEASING,
    STR_ID_UCM_NO_NUMBER_TO_DIAL,
    STR_ID_UCM_NOT_SOS_NUMBER,
    STR_ID_UCM_NOT_ALLOW_TO_DIAL,
    STR_ID_UCM_NOT_ALLOW_TO_ACCEPT,
    STR_ID_UCM_NOT_ALLOW_TO_HOLD,
    STR_ID_UCM_NOT_ALLOW_TO_SWAP,
    STR_ID_UCM_CALL_ABORT,
    STR_ID_UCM_CALL_HOLD,
    STR_ID_UCM_CALL_RETRIEVE,
    STR_ID_UCM_CALL_SWAP,
    STR_ID_UCM_CALL_CONFERENCE,
    STR_ID_UCM_CALL_SPLIT,
    STR_ID_UCM_CALL_END,
    STR_ID_UCM_CALL_DEFLECT,
    STR_ID_UCM_CALL_TRANSFER,
    STR_ID_UCM_HOLD,
    STR_ID_UCM_RETRIEVE,
    STR_ID_UCM_SWAP,
    STR_ID_UCM_CONFERENCE,
    STR_ID_UCM_SPLIT,
    STR_ID_UCM_END_SINGLE,
    STR_ID_UCM_END_CONFERENCE,
    STR_ID_UCM_END_ALL,
    STR_ID_UCM_END_CALL,
    STR_ID_UCM_HOLD_SINGLE,
    STR_ID_UCM_HOLD_CONFERENCE,
    STR_ID_UCM_RETRIEVE_SINGLE,
    STR_ID_UCM_RETRIEVE_CONFERENCE,
    STR_ID_UCM_TRANSFER,
    STR_ID_UCM_NEW_CALL,
    STR_ID_UCM_PHONEBOOK,
    STR_ID_UCM_SMS,
    STR_ID_UCM_SOUND_RECORDER,
    STR_ID_UCM_BACKGROUND_SOUND,
    STR_ID_UCM_MUTE,
    STR_ID_UCM_DTMF,
    STR_ID_UCM_VOICE_CALL,
    STR_ID_UCM_VOIP_CALL,
    STR_ID_UCM_SAVE_TO_PHONEBOOK,
    STR_ID_UCM_SELECT_FROM_PHONEBOOK,
    STR_ID_UCM_CALL_CENTER,
    STR_ID_UCM_GENERAL_CALL_SETTING,
    STR_ID_UCM_MORE,
    STR_ID_UCM_LOUD_SPEAKER_OFF,
    STR_ID_UCM_LOUD_SPEAKER_ON,
    STR_ID_UCM_SWITCH_AUDIO_PATH,
    STR_ID_UCM_ACTIVE,
    STR_ID_UCM_VIDEO_CALL,
    STR_ID_UCM_DIALING_VIDEO_CALL,
    STR_ID_UCM_CTM_CONNECT,
    STR_ID_UCM_REPLACE,
    STR_ID_UCM_REDIAL_FROM_OTHER_SIM,
    STR_ID_UCM_END_ALL_ACTIVE,
    STR_ID_UCM_END_ALL_HELD,
    STR_ID_UCM_SIM1_VOICE_CALL,
    STR_ID_UCM_SIM2_VOICE_CALL,
    STR_ID_UCM_SIM1_VOICE_ACTIVE,
    STR_ID_UCM_SIM1_VOICE_HOLD,
    STR_ID_UCM_TOTAL
} ucm_string_enum;

typedef enum
{
    IMG_ID_UCM_OUTGOING_CALL = (UCM_BASE + 1),
    IMG_ID_UCM_CONNECTED,
    IMG_ID_UCM_CALL_STATE_ACTIVE,
    IMG_ID_UCM_CALL_STATE_HOLD,
    IMG_ID_UCM_SUBLCD_CALLING,
    IMG_ID_UCM_ACTIVE_CALL,
    IMG_ID_UCM_CALL_HISTORY,    
    IMG_ID_UCM_VIDEO,
    IMG_ID_UCM_SETTING,
    IMG_ID_UCM_TOTAL
} ucm_image_enum;

typedef enum
{
    SCR_ID_UCM_OUTGOING = (UCM_BASE + 1),
    SCR_ID_UCM_OUTGOING_SUBLCD,
    SCR_ID_UCM_INCOMING,
    SCR_ID_UCM_INCOMING_SUBLCD,
    SCR_ID_UCM_INCOMING_SUBLCD_STATIC,
    SCR_ID_UCM_INCOMING_OPTION,
    SCR_ID_UCM_IN_CALL,
    SCR_ID_UCM_IN_CALL_SUBLCD,
    SCR_ID_UCM_IN_CALL_OPTION,
    SCR_ID_UCM_DTMF_EDITOR,
    SCR_ID_UCM_MULTI_HELD_CALL,
    SCR_ID_UCM_CALL_END,
    SCR_ID_UCM_NEW_CALL_OPTION,
    SCR_ID_UCM_VOIP_DIALER,
    SCR_ID_UCM_VOICE_DIALER,
    SCR_ID_UCM_TRANSFER,
    SCR_ID_UCM_DEFLECT,
    SCR_ID_UCM_CONFIRM,
    SCR_ID_UCM_NEW_CALL_DIALER_OPTION,
    SCR_ID_UCM_PROCESSING,
    SCR_ID_UCM_CALL_CENTER,
    SCR_ID_UCM_GENERAL_CALL_SETTING,
    SCR_ID_UCM_GENERAL_CALL_SETTING_MORE,
    SCR_ID_UCM_AUTO_REDIAL,
    SCR_ID_UCM_DIAL_CALL_TYPE_MENU,
    SCR_ID_UCM_BGS_EFFECT_SELECT,
    SCR_ID_UCM_GENERAL_CALL_SETTING_SIM1,
    SCR_ID_UCM_MARKER,
    SCR_ID_UCM_TOTAL
} ucm_screen_enum;
#endif /* UCM_RES_DEF_H */ 

