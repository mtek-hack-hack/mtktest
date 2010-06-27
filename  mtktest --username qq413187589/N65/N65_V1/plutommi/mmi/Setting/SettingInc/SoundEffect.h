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
* SoundEffect.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is the header file of sound effect setup.
*
* Author:
* -------
* Tim Chen
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _SOUND_EFFECT_H_
#define _SOUND_EFFECT_H_

#define MAX_EQUALIZER_NUM  8    /* double check if NVRAM_EF_AUDIO_EQUALIZER_COUNT == MAX_EQUALIZER_NUM */
#define NUM_OF_BARS_IN_A_SETTING  8
#define UPPER_LIMIT_SOUND_LEVEL   1270
#define LOWER_LIMIT_SOUND_LEVEL   -1280
#define SETTING_NAME_MAX_LEN      23

typedef enum
{
    SETTINGS_SOUND_EFFECTS_NONE,
#ifdef __MMI_AUDIO_EQUALIZER__
    SETTINGS_SOUND_EFFECTS_EQ,
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    SETTINGS_SOUND_EFFECTS_REVERB,
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    SETTINGS_SOUND_EFFECTS_SURROUND,
#endif
    NO_OF_SETTINGS_SOUND_EFFECTS
}AUDIO_SOUND_EFFECTS_ENUM;


typedef enum
{
    AUDIO_MIC_IN_CALL,
    AUDIO_MIC_APP,
    AUDIO_MIC_SET_NUM
} AUDIO_MIC_SET_ENUM;

typedef struct
{
    S16 count;
    S16 index;
    signed char magnitude[MAX_EQUALIZER_NUM][NUM_OF_BARS_IN_A_SETTING];
    unsigned char setting_name[MAX_EQUALIZER_NUM][(SETTING_NAME_MAX_LEN + 1) *ENCODING_LENGTH];
} audio_equalizer_struct;

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
typedef struct
{
    S16 sound_level[NUM_OF_BARS_IN_A_SETTING];
    U8 active_bar;
} equalizer_setting_info;
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 

typedef struct
{
    unsigned char levels[AUDIO_MIC_SET_NUM];
} audio_mic_volume_struct;

extern audio_equalizer_struct g_settings_audio_equalizer;

extern void InitSoundEffect(void);
extern void mmi_settings_sound_effect_highlight_hdlr(void);
extern void mmi_settings_entry_sound_effect_list(void);

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
extern void mmi_settings_audio_effect_highlight_hdlr(void);
extern void mmi_settings_audio_effect_screen_highlight_hdlr(S32 index);
extern void mmi_settnigs_audio_effect_inlineitem_highlight_hdlr_1(S32 index);
extern void mmi_settings_audio_effect_inlineitem_highlight_hdlr_2(S32 index);
extern void mmi_settings_audio_effect_init(void);
extern void mmi_settings_turn_off_audio_effect(void);
extern void mmi_settings_audio_effect_write_nvram(void);
extern void mmi_settings_audio_effect_settings_done(void);
extern void mmi_settings_audio_effect_settings_back(void);
extern void mmi_settings_exit_audio_effect(void);
extern void mmi_settings_entry_audio_effect(void);
#endif

#ifdef __MMI_AUDIO_EQUALIZER__
extern void mmi_settings_audio_eq_read_from_nvram(void);
extern void mmi_settings_audio_eq_write_to_nvram(void);
extern void mmi_settings_audio_eq_init(void);
extern BOOL mmi_settings_audio_eq_apply(S16 index);

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
extern void mmi_settings_audio_equalizer_restore_factory_default(void);
extern void mmi_settings_entry_audio_equalizer_setting_options(void);
extern void mmi_settings_audio_equalizer_opt_select_highlight_hdlr(void);
extern void mmi_settings_audio_equalizer_opt_edit_highlight_hdlr(void);
extern void mmi_settings_audio_equalizer_opt_rename_highlight_hdlr(void);
extern void mmi_settings_audio_equalizer_opt_reset_highlight_hdlr(void);

/* select functions */
extern void mmi_settings_audio_equalizer_setting_select(void);

/* editing functions */
extern void mmi_settings_entry_audio_equalizer_setting_edit(void);
extern U8 mmi_settings_audio_equalizer_delete_history_hdlr(void *in_param);
extern void mmi_settings_audio_equalizer_setting_edit_RSK_hdlr(void);
extern void mmi_settings_audio_equalizer_activate_previous_bar(void);
extern void mmi_settings_audio_equalizer_activate_next_bar(void);
extern void mmi_settings_audio_equalizer_increment_sound_level(void);
extern void mmi_settings_audio_equalizer_decrement_sound_level(void);
extern void mmi_settings_audio_equalizer_save_values(void);

/* renaming functions */
extern void mmi_settings_entry_audio_equalizer_setting_rename(void);
extern void mmi_settings_entry_audio_equalizer_setting_name_edit_option(void);
extern void mmi_settings_audio_equalizer_setting_name_edit_option_highlight_hdlr(S32 index);
extern void mmi_settings_audio_equalizer_setting_name_edit_option_LSK(void);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_settings_audio_equalizer_change_sound_level(S16 change);
#endif 

#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 
#endif /* __MMI_AUDIO_EQUALIZER__ */

#if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

typedef struct
{
    U16 reverb_index;
    U16 surround_index;    
} audio_3d_effect_struct;

extern audio_3d_effect_struct g_mmi_aud_3d_cntx;

#ifdef __MMI_AUDIO_REVERB_EFFECT__

#define MAX_AUDIO_REVERB_EFFECT_NUM  6

extern void mmi_settings_audio_reverb_init(void);
extern BOOL mmi_settings_audio_reverb_apply(U16 index);
extern void mmi_settings_audio_reverb_effect_init(U16 index);
extern void mmi_settings_audio_reverb_read_nvram(void);
extern void mmi_settings_audio_reverb_write_nvram(void);
extern MMI_BOOL mmi_settings_audio_reverb_get_status(void);
#endif /*__MMI_AUDIO_REVERB_EFFECT__*/


#ifdef __MMI_AUDIO_SURROUND_EFFECT__

typedef enum
{
    AUD_SURROUND_MODE1,
    AUD_SURROUND_MODE2,
    AUD_SURROUND_TOTAL
} audio_surround_mode_enum;

extern void mmi_settings_audio_surround_init(void);
extern void mmi_settings_audio_surround_effect_init(U16 index);
extern void mmi_settings_audio_surround_bind_earphone_confirm(void);
extern void mmi_settings_audio_surround_apply_check(U16 index);
extern void mmi_settings_audio_surround_apply(U16 mode);
extern void mmi_settings_audio_surround_read_nvram(void);
extern void mmi_settings_audio_surround_write_nvram(void);
#endif /*__MMI_AUDIO_SURROUND_EFFECT__*/

#endif /*__MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

#endif /* _SOUND_EFFECT_H_ */ 

extern void mmi_settings_read_audio_mic_volume_from_nvram(audio_mic_volume_struct *audio_mic_volume_p);
extern void mmi_settings_write_audio_mic_volume_to_nvram(audio_mic_volume_struct *audio_mic_volume_p);

