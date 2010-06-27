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
 *  MotionDJDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Motion Game - DJ
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
#ifndef _MOTION_DJ_DEFS_H_
#define _MOTION_DJ_DEFS_H_

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
#define DJ_AUD_DUMMY_BG_LEN         (94)
#define DJ_AUD_INS_MIDI_0_LEN       (310)
#define DJ_AUD_INS_MIDI_1_LEN       (310)
#define DJ_AUD_INS_MIDI_2_LEN       (310)
#define DJ_AUD_INS_MIDI_3_LEN       (310)
#define DJ_AUD_INS_MIDI_4_LEN       (310)
#define DJ_AUD_INS_MIDI_5_LEN       (310)
#define DJ_AUD_INS_MIDI_6_LEN       (310)
#define DJ_AUD_INS_MIDI_7_LEN       (310)
#define DJ_AUD_INS_MIDI_8_LEN       (310)
#define DJ_AUD_INS_MIDI_9_LEN       (310)

#define DJ_AUD_VOX_WAVE_0_LEN       (4798)
#define DJ_AUD_VOX_WAVE_1_LEN       (4798)
#define DJ_AUD_VOX_WAVE_2_LEN       (4798)
#define DJ_AUD_VOX_WAVE_3_LEN       (4798)
#define DJ_AUD_VOX_WAVE_4_LEN       (4798)
#define DJ_AUD_VOX_WAVE_5_LEN       (4798)
#define DJ_AUD_VOX_WAVE_6_LEN       (4798)
#define DJ_AUD_VOX_WAVE_7_LEN       (4798)
#define DJ_AUD_VOX_WAVE_8_LEN       (4798)
#define DJ_AUD_VOX_WAVE_9_LEN       (4798)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef enum
{
    STR_ID_MOTION_DJ_APP = MOTION_DJ_BASE,
    STR_ID_MOTION_DJ_START,
    STR_ID_MOTION_DJ_SETTING,
    STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1,
    STR_ID_MOTION_DJ_INSTRUMENT_TITLE_2,
    STR_ID_MOTION_DJ_INSTRUMENT_TITLE_3,
    STR_ID_MOTION_DJ_VOCAL_TITLE_1,
    STR_ID_MOTION_DJ_VOCAL_TITLE_2,
    STR_ID_MOTION_DJ_VOCAL_TITLE_3,

    STR_ID_MOTION_DJ_INSTRUMENT_0,
    STR_ID_MOTION_DJ_INSTRUMENT_1,
    STR_ID_MOTION_DJ_INSTRUMENT_2,
    STR_ID_MOTION_DJ_INSTRUMENT_3,
    STR_ID_MOTION_DJ_INSTRUMENT_4,
    STR_ID_MOTION_DJ_INSTRUMENT_5,
    STR_ID_MOTION_DJ_INSTRUMENT_6,
    STR_ID_MOTION_DJ_INSTRUMENT_7,
    STR_ID_MOTION_DJ_INSTRUMENT_8,
    STR_ID_MOTION_DJ_INSTRUMENT_9,

    STR_ID_MOTION_DJ_VOCAL_0,
    STR_ID_MOTION_DJ_VOCAL_1,
    STR_ID_MOTION_DJ_VOCAL_2,
    STR_ID_MOTION_DJ_VOCAL_3,
    STR_ID_MOTION_DJ_VOCAL_4,
    STR_ID_MOTION_DJ_VOCAL_5,
    STR_ID_MOTION_DJ_VOCAL_6,
    STR_ID_MOTION_DJ_VOCAL_7,
    STR_ID_MOTION_DJ_VOCAL_8,
    STR_ID_MOTION_DJ_VOCAL_9,

    STR_ID_MOTION_DJ_KEY_0,
    STR_ID_MOTION_DJ_KEY_1,
    STR_ID_MOTION_DJ_KEY_2,
    STR_ID_MOTION_DJ_KEY_3,
    STR_ID_MOTION_DJ_KEY_4,
    STR_ID_MOTION_DJ_KEY_5,
    STR_ID_MOTION_DJ_KEY_6,
    STR_ID_MOTION_DJ_KEY_7,
    STR_ID_MOTION_DJ_KEY_8,
    STR_ID_MOTION_DJ_KEY_9,
    STR_ID_MOTION_DJ_KEY_STAR,
    STR_ID_MOTION_DJ_KEY_POUND,

    STR_ID_MOTION_DJ_EDIT_AUDIO,
    STR_ID_MOTION_DJ_EDIT_VOLUME,
    STR_ID_MOTION_DJ_EDIT_TRIGGER,
    STR_ID_MOTION_DJ_EDIT_KEY,

    STR_ID_MOTION_DJ_EDIT_TRIGGER_AUTO,
    STR_ID_MOTION_DJ_EDIT_TRIGGER_SHAKE,
    STR_ID_MOTION_DJ_EDIT_TRIGGER_KEY_PRESS,

    STR_ID_MOTION_DJ_NOTIFY_HAS_AUTO,
    STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE,
    STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE_SAME_KEY,
    STR_ID_MOTION_DJ_NOTIFY_HAS_PRESS_SAME_KEY,
    STR_ID_MOTION_DJ_NOTIFY_EMPTY_TRIGGER,
    STR_ID_MOTION_DJ_NOTIFY_EMPTY_KEY,

    NUM_OF_MOTION_DJ_STR_ID
} motion_dj_str_enum;

typedef enum
{
    IMG_ID_MOTION_DJ_APP = MOTION_DJ_BASE,
    IMG_ID_MOTION_DJ_ICON_TRIGGER_NONE,
    IMG_ID_MOTION_DJ_ICON_TRIGGER_AUTO,
    IMG_ID_MOTION_DJ_ICON_TRIGGER_SHAKE,
    IMG_ID_MOTION_DJ_ICON_TRIGGER_PRESS,

    IMG_ID_MOTION_DJ_ICON_KEY_DUMMY,
    IMG_ID_MOTION_DJ_ICON_KEY_0,
    IMG_ID_MOTION_DJ_ICON_KEY_1,
    IMG_ID_MOTION_DJ_ICON_KEY_2,
    IMG_ID_MOTION_DJ_ICON_KEY_3,
    IMG_ID_MOTION_DJ_ICON_KEY_4,
    IMG_ID_MOTION_DJ_ICON_KEY_5,
    IMG_ID_MOTION_DJ_ICON_KEY_6,
    IMG_ID_MOTION_DJ_ICON_KEY_7,
    IMG_ID_MOTION_DJ_ICON_KEY_8,
    IMG_ID_MOTION_DJ_ICON_KEY_9,
    IMG_ID_MOTION_DJ_ICON_KEY_STAR,
    IMG_ID_MOTION_DJ_ICON_KEY_POUND,

    IMG_ID_MOTION_DJ_PLAY_BG,
    IMG_ID_MOTION_DJ_PLAY_NONE,
    IMG_ID_MOTION_DJ_PLAY_AUTO,
    IMG_ID_MOTION_DJ_PLAY_SHAKE,
    IMG_ID_MOTION_DJ_PLAY_PRESS,

    IMG_ID_MOTION_DJ_PLAY_KEY_0,
    IMG_ID_MOTION_DJ_PLAY_KEY_1,
    IMG_ID_MOTION_DJ_PLAY_KEY_2,
    IMG_ID_MOTION_DJ_PLAY_KEY_3,
    IMG_ID_MOTION_DJ_PLAY_KEY_4,
    IMG_ID_MOTION_DJ_PLAY_KEY_5,
    IMG_ID_MOTION_DJ_PLAY_KEY_6,
    IMG_ID_MOTION_DJ_PLAY_KEY_7,
    IMG_ID_MOTION_DJ_PLAY_KEY_8,
    IMG_ID_MOTION_DJ_PLAY_KEY_9,
    IMG_ID_MOTION_DJ_PLAY_KEY_STAR,
    IMG_ID_MOTION_DJ_PLAY_KEY_POUND,

    IMG_ID_MOTION_DJ_PLAY_NONE_SEL,
    IMG_ID_MOTION_DJ_PLAY_AUTO_SEL,
    IMG_ID_MOTION_DJ_PLAY_SHAKE_SEL,
    IMG_ID_MOTION_DJ_PLAY_PRESS_SEL,

    IMG_ID_MOTION_DJ_PLAY_KEY_0_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_1_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_2_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_3_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_4_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_5_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_6_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_7_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_8_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_9_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_STAR_SEL,
    IMG_ID_MOTION_DJ_PLAY_KEY_POUND_SEL,

    NUM_OF_MOTION_DJ_IMG_ID
} motion_dj_img_enum;

typedef enum
{
    SCR_ID_MOTION_DJ_APP = MOTION_DJ_BASE,
    SCR_ID_MOTION_DJ_SETTING,
    SCR_ID_MOTION_DJ_EDIT,
    SCR_ID_MOTION_DJ_PLAY,
    SCR_ID_MOTION_DJ_DUMMY,

    NUM_OF_MOTION_DJ_SCR_ID
} motion_dj_scr_enum;

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/

#endif /* _MOTION_DJ_DEFS_H_ */ 

