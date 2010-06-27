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

/*******************************************************************************
 * Filename:
 * ---------
 *  MotionDJ.c
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
#include "MMI_include.h"
#ifndef _MMI_MOTION_DJ_C
#define _MMI_MOTION_DJ_C



#include "GameInc.h"    /* Game Include */

#ifdef IS_DJ_BASE_MOTIONGAME    /* this must after GameInc.h" */

#include "MotionDJResDef.h"
#include "filemgr.h"    /* file related */
#include "FileManagerGProt.h"   /* file related */
#include "MainMenuDef.h"        /* fun&game icon id */
#include "CommonScreens.h"      /* DisplayPopup() */
#include "gui.h"        /* Gui functions */
#include "gpioInc.h"    /* LED related */
#include "mmiapi_enum.h"        /* Stop LED */
#include "GameFramework.h"      /* for game settings */
#include "filemgr.h"    /* file manager */

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_audio.h"  /* audio */
#include "mdi_motion.h" /* motion sensor */

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
#define DJ_MENU_ICON_IMG_ID         GetRootTitleIcon(MENU_ID_MOTION_APP)
#define DJ_AUDIO_COUNT              (10)
#define DJ_VOLUME_LEVEL             (7)

#define DJ_NUM_OF_INSTRUMENT_ENTRY  (3)
#define DJ_NUM_OF_VOCAL_ENTRY       (3)
#define DJ_NUM_OF_ALL_ENTRY         (DJ_NUM_OF_INSTRUMENT_ENTRY+DJ_NUM_OF_VOCAL_ENTRY)

#define DJ_ICON_FADE_TIME           (300)

#define DJ_FONT_COLOR               (gui_color(255, 255, 255))
#define DJ_FONT_BORDER_COLOR        (gui_color(0, 0, 0))

#define DJ_SEL_FONT_COLOR           (gui_color(255, 255, 255))
#define DJ_SEL_FONT_BORDER_COLOR    (gui_color(255, 0, 0))

/* turn on this flag will enable indivisual audio's volume config - mdi/med not implement yet */
// #define DJ_ENABLE_INDIVISUAL_VOLUME

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    DJ_TRIGGER_NONE,
    DJ_TRIGGER_AUTO,
    DJ_TRIGGER_SHAKE,
    DJ_TRIGGER_PRESS,

    NUM_OF_DJ_TRIGGER_TYPE
} dj_trigger_type_enum;

typedef enum
{
    DJ_AUD_INSTRUMENT,
    DJ_AUD_VOCAL,

    NUM_OF_DJ_AUDIO_TYPE
} dj_audio_type_enum;

typedef enum
{
    DJ_KEY_NONE,
    DJ_KEY_0,
    DJ_KEY_1,
    DJ_KEY_2,
    DJ_KEY_3,
    DJ_KEY_4,
    DJ_KEY_5,
    DJ_KEY_6,
    DJ_KEY_7,
    DJ_KEY_8,
    DJ_KEY_9,
    DJ_KEY_STAR,
    DJ_KEY_POUND,

    NUM_OF_DJ_KEY
} dj_key_enum;

/* 16 byte - NVRAM_EF_MOTION_DJ_SIZE */
typedef struct
{
    U16 audio_type; /* 2 byte */
    U16 audio_id;   /* 2 byte */
    U16 vol;        /* 2 byte */
    U16 trigger;    /* 2 byte */
    U16 key;        /* 2 byte */
    U16 reserve_1;  /* 2 byte */
    U16 reserve_2;  /* 2 byte */
    U16 reserve_3;  /* 2 byte */
} dj_event_struct;

typedef struct
{

    UI_string_type audio_str[DJ_AUDIO_COUNT];
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    UI_string_type volume_str[DJ_VOLUME_LEVEL];
#endif 
    UI_string_type trigger_str[NUM_OF_DJ_TRIGGER_TYPE];
    UI_string_type key_str[NUM_OF_DJ_KEY];

    /* selected */
    S32 audio_selected;
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    S32 volume_selected;
#endif 
    S32 trigger_selected;
    S32 key_selected;

} setting_data_struct;

typedef struct
{
    BOOL is_trigger_sel;
    BOOL is_key_sel;
    BOOL is_text_sel;
} dj_draw_state_struct;

typedef struct
{
    S32 icon_trigger_x;
    S32 icon_trigger_y;
    S32 icon_key_x;
    S32 icon_key_y;
    S32 text_x;
    S32 text_y;
} dj_draw_pos_struct;

/* context */
typedef struct
{
    S32 selected_idx;
    U16 selected_audio_type;
    U16 prev_trigger;
    GDI_HANDLE item_layer;
    GDI_HANDLE bg_layer;
    GDI_HANDLE bg_anim;
    MDI_HANDLE aud_bg_handle;
    MDI_HANDLE aud_handle[DJ_NUM_OF_ALL_ENTRY];
    BOOL is_key_pressed[NUM_OF_DJ_KEY];
    setting_data_struct inline_data;
    dj_event_struct event_list[DJ_NUM_OF_ALL_ENTRY];

    dj_draw_state_struct draw_state[DJ_NUM_OF_ALL_ENTRY];

} dj_cntx_struct;

const dj_draw_pos_struct g_dj_draw_pos[DJ_NUM_OF_ALL_ENTRY] = 
{
    3, 11, 52, 11, 92, 28,      /* inst 0 */
    3, 42, 52, 42, 92, 59,      /* inst 1 */
    3, 73, 52, 73, 92, 90,      /* inst 2 */
    3, 103, 52, 103, 92, 121,   /* vox 0 */
    3, 135, 52, 135, 92, 152,   /* vox 1 */
    3, 166, 52, 166, 92, 183    /* vox 2 */
};

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern __align(2)
     const U8 motion_dj_aud_dummy_bg[DJ_AUD_DUMMY_BG_LEN];

     extern __align(2)
     const U8 motion_dj_instrument_midi_0[DJ_AUD_INS_MIDI_0_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_1[DJ_AUD_INS_MIDI_1_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_2[DJ_AUD_INS_MIDI_2_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_3[DJ_AUD_INS_MIDI_3_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_4[DJ_AUD_INS_MIDI_4_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_5[DJ_AUD_INS_MIDI_5_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_6[DJ_AUD_INS_MIDI_6_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_7[DJ_AUD_INS_MIDI_7_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_8[DJ_AUD_INS_MIDI_8_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_9[DJ_AUD_INS_MIDI_9_LEN];

     extern __align(2)
     const U8 motion_dj_vocal_wav_0[DJ_AUD_VOX_WAVE_0_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_1[DJ_AUD_VOX_WAVE_1_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_2[DJ_AUD_VOX_WAVE_2_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_3[DJ_AUD_VOX_WAVE_3_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_4[DJ_AUD_VOX_WAVE_4_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_5[DJ_AUD_VOX_WAVE_5_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_6[DJ_AUD_VOX_WAVE_6_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_7[DJ_AUD_VOX_WAVE_7_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_8[DJ_AUD_VOX_WAVE_8_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_9[DJ_AUD_VOX_WAVE_9_LEN];

/***************************************************************************** 
* Global Function
*****************************************************************************/
     extern void inline_select_menu_goto_item(S32 index);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
     dj_cntx_struct g_dj_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* app */
     static void mmi_motion_dj_highlight_start(void);
     static void mmi_motion_dj_highlight_setting(void);

/* setting screen */
     static void mmi_motion_dj_entry_setting_scr(void);
     static void mmi_motion_dj_setting_highlight_hdlr(S32 index);

/* edit screen */
     static void mmi_motion_dj_entry_edit_scr(void);
     static void mmi_motion_dj_exit_edit_scr(void);
     static void mmi_motion_dj_edit_highlight_hdlr(S32 index);
     static void mmi_motion_dj_edit_delay_play_audio(void);
     static void mmi_motion_dj_edit_trigger_highlight_handler(S32 index);
     static void mmi_motion_dj_edit_audio_highlight_handler(S32 index);
     static void mmi_motion_dj_edit_key_highlight_handler(S32 index);
     static void mmi_motion_dj_edit_done(void);

/* play screen */
     static void mmi_motion_dj_entry_play_scr(void);
     static void mmi_motion_dj_exit_play_scr(void);
     static void mmi_motion_dj_play_shake_trigger(void);
     static void mmi_motion_dj_draw_items(void);
#if 0
/* under construction !*/
#endif
     static void mmi_motion_dj_auto_icon_timeout(void);
     static void mmi_motion_dj_shake_0_icon_timeout(void);
     static void mmi_motion_dj_shake_1_icon_timeout(void);
     static void mmi_motion_dj_shake_2_icon_timeout(void);
     static void mmi_motion_dj_shake_3_icon_timeout(void);
     static void mmi_motion_dj_shake_4_icon_timeout(void);
     static void mmi_motion_dj_shake_5_icon_timeout(void);

     static void mmi_motion_dj_play_key_0_press(void);
     static void mmi_motion_dj_play_key_0_release(void);
     static void mmi_motion_dj_play_key_1_press(void);
     static void mmi_motion_dj_play_key_1_release(void);
     static void mmi_motion_dj_play_key_2_press(void);
     static void mmi_motion_dj_play_key_2_release(void);
     static void mmi_motion_dj_play_key_3_press(void);
     static void mmi_motion_dj_play_key_3_release(void);
     static void mmi_motion_dj_play_key_4_press(void);
     static void mmi_motion_dj_play_key_4_release(void);
     static void mmi_motion_dj_play_key_5_press(void);
     static void mmi_motion_dj_play_key_5_release(void);
     static void mmi_motion_dj_play_key_6_press(void);
     static void mmi_motion_dj_play_key_6_release(void);
     static void mmi_motion_dj_play_key_7_press(void);
     static void mmi_motion_dj_play_key_7_release(void);
     static void mmi_motion_dj_play_key_8_press(void);
     static void mmi_motion_dj_play_key_8_release(void);
     static void mmi_motion_dj_play_key_9_press(void);
     static void mmi_motion_dj_play_key_9_release(void);
     static void mmi_motion_dj_play_key_star_press(void);
     static void mmi_motion_dj_play_key_star_release(void);
     static void mmi_motion_dj_play_key_pound_press(void);
     static void mmi_motion_dj_play_key_pound_release(void);

/*****************************************************************************
*
*  App                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_init_app
 * DESCRIPTION
 *  init dj app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
     void mmi_motion_dj_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_MOTION_DJ_START, mmi_motion_dj_highlight_start);
    SetHiliteHandler(MENU_ID_MOTION_DJ_SETTING, mmi_motion_dj_highlight_setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_app
 * DESCRIPTION
 *  enter point of dj app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL dj_first_load;

void mmi_motion_dj_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[32];
    S32 i;
    S32 idx;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MOTION_DJ_APP, NULL, mmi_motion_dj_entry_app, NULL);

    for (i = 0 ; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        /* load value from NVRAM */
        ReadRecord(
            NVRAM_EF_MOTION_DJ_LID,
            i+1,
            (void*)&g_dj_cntx.event_list[i],
            NVRAM_EF_MOTION_DJ_SIZE,
            &error);
    }


    /* init if needed */ 
    if (g_dj_cntx.event_list[0].audio_type == 0xffff) 
    {
        dj_first_load = FALSE;

        idx = 0;
        for (i = 0; i < DJ_NUM_OF_INSTRUMENT_ENTRY; i++)
        {
            g_dj_cntx.event_list[idx].audio_type = DJ_AUD_INSTRUMENT;
            g_dj_cntx.event_list[idx].audio_id = 0;
            g_dj_cntx.event_list[idx].vol = LEVEL4;
            g_dj_cntx.event_list[idx].trigger = DJ_TRIGGER_NONE;
            g_dj_cntx.event_list[idx].key = DJ_KEY_NONE;
            idx++;
        }

        for (i = 0; i < DJ_NUM_OF_VOCAL_ENTRY; i++)
        {
            g_dj_cntx.event_list[idx].audio_type = DJ_AUD_VOCAL;
            g_dj_cntx.event_list[idx].audio_id = 0;
            g_dj_cntx.event_list[idx].vol = LEVEL4;
            g_dj_cntx.event_list[idx].trigger = DJ_TRIGGER_NONE;
            g_dj_cntx.event_list[idx].key = DJ_KEY_NONE;
            idx++;
        }

        for (i = 0 ; i < DJ_NUM_OF_ALL_ENTRY; i++)
        {
            /* write inited value to NVRAM */
            WriteRecord(
                NVRAM_EF_MOTION_DJ_LID,
                i+1,
                (void*)&g_dj_cntx.event_list[i],
                NVRAM_EF_MOTION_DJ_SIZE,
                &error);
        }
        
    }

    gui_buffer = GetCurrGuiBuffer(SCR_ID_MOTION_DJ_APP);
    num_item = GetNumOfChild(MENU_ID_MOTION_DJ_APP);

    GetSequenceStringIds(MENU_ID_MOTION_DJ_APP, item_list);
    GetSequenceImageIds(MENU_ID_MOTION_DJ_APP, item_icons);
    SetParentHandler(MENU_ID_MOTION_DJ_APP);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_MOTION_DJ_APP, popup_list);

    ShowCategory52Screen(
        STR_ID_MOTION_DJ_APP,
        DJ_MENU_ICON_IMG_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_highlight_start
 * DESCRIPTION
 *  highlight handler of start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_highlight_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_dj_entry_play_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_entry_play_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_highlight_setting
 * DESCRIPTION
 *  highlight handler of start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_highlight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_dj_entry_setting_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_entry_setting_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
*
*  Setting Screen                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_setting_scr
 * DESCRIPTION
 *  enter setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 icon_list_1[MAX_SUB_MENUS];
    U16 icon_list_2[MAX_SUB_MENUS];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MOTION_DJ_SETTING, NULL, mmi_motion_dj_entry_setting_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_MOTION_DJ_SETTING);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
        {
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
                mmi_ucs2cpy(
                    (PS8) subMenuDataPtrs[i],
                    (PS8) GetString((U16) (STR_ID_MOTION_DJ_INSTRUMENT_0 + g_dj_cntx.event_list[i].audio_id)));
            }
            else
            {
                mmi_ucs2cpy((PS8) subMenuDataPtrs[i], (PS8) GetString(STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1 + i));
            }
        }
        else
        {
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
                mmi_ucs2cpy(
                    (PS8) subMenuDataPtrs[i],
                    (PS8) GetString((U16) (STR_ID_MOTION_DJ_VOCAL_0 + g_dj_cntx.event_list[i].audio_id)));
            }
            else
            {
                mmi_ucs2cpy(
                    (PS8) subMenuDataPtrs[i],
                    (PS8) GetString(STR_ID_MOTION_DJ_VOCAL_TITLE_1 + i - DJ_NUM_OF_INSTRUMENT_ENTRY));
            }
        }

        icon_list_1[i] = (U16) (IMG_ID_MOTION_DJ_ICON_TRIGGER_NONE + g_dj_cntx.event_list[i].trigger);
        icon_list_2[i] = (U16) (IMG_ID_MOTION_DJ_ICON_KEY_DUMMY + g_dj_cntx.event_list[i].key);
    }

    /* get item count */
    RegisterHighlightHandler(mmi_motion_dj_setting_highlight_hdlr);

    ShowCategory73Screen(
        STR_ID_MOTION_DJ_SETTING,
        DJ_MENU_ICON_IMG_ID,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        DJ_NUM_OF_ALL_ENTRY,
        (U8 **) subMenuDataPtrs,    /* list of items */
        (U16*) icon_list_1,         /* list of icon1 */
        (U16*) icon_list_2,         /* list of icon2 */
        (U16) 0,                    /* highlighted item */
        gui_buffer,
        1);                         /* display flag */

    SetLeftSoftkeyFunction(mmi_motion_dj_entry_edit_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for settng
 * PARAMETERS
 *  index       [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.selected_idx = index;

    if (index < DJ_NUM_OF_INSTRUMENT_ENTRY)
    {
        g_dj_cntx.selected_audio_type = DJ_AUD_INSTRUMENT;
    }
    else
    {
        g_dj_cntx.selected_audio_type = DJ_AUD_VOCAL;
    }
}

/*****************************************************************************
*
*  Edit Screen                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_edit_scr
 * DESCRIPTION
 *  enter audio edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_edit_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 input_buffer_size;
    S32 item_idx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    /* TODO: can add dedicate icons */
    MMI_ID_TYPE item_icons[8] = 
    {
        IMG_GLOBAL_L1,  /* audio */
        0,
        IMG_GLOBAL_L2,  /* vol */
        0,
        IMG_GLOBAL_L3,  /* trigger */
        0,
        IMG_GLOBAL_L4,  /* key */
        0,
    };
#else /* DJ_ENABLE_INDIVISUAL_VOLUME */ 
    /* TODO: can add dedicate icons */
    MMI_ID_TYPE item_icons[8] = 
    {
        IMG_GLOBAL_L1,  /* audio */
        0,
        IMG_GLOBAL_L2,  /* trigger */
        0,
        IMG_GLOBAL_L3,  /* key */
        0,
    };

#endif /* DJ_ENABLE_INDIVISUAL_VOLUME */ 

    EntryNewScreen(SCR_ID_MOTION_DJ_EDIT, mmi_motion_dj_exit_edit_scr, NULL, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_MOTION_DJ_EDIT);

    mdi_audio_suspend_background_play();

    /* load setting to inline data */
    g_dj_cntx.inline_data.audio_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].audio_id;
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    g_dj_cntx.inline_data.volume_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].vol;
#endif 
    g_dj_cntx.inline_data.trigger_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].trigger;
    g_dj_cntx.inline_data.key_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].key;

    g_dj_cntx.prev_trigger = g_dj_cntx.inline_data.trigger_selected;

    InitializeCategory57Screen();

    item_idx = 0;

   /************************************/
    /* audio - inline selection         */
   /************************************/

    /* caption */
    SetInlineItemCaption(&wgui_inline_items[item_idx], (PU8) GetString((U16) (STR_ID_MOTION_DJ_EDIT_AUDIO)));
    item_idx++;

    if (g_dj_cntx.selected_audio_type == DJ_AUD_INSTRUMENT)
    {
        for (i = 0; i < DJ_AUDIO_COUNT; i++)
        {
            g_dj_cntx.inline_data.audio_str[i] = (UI_string_type) GetString((U16) (STR_ID_MOTION_DJ_INSTRUMENT_0 + i));
        }
    }
    else
    {
        for (i = 0; i < DJ_AUDIO_COUNT; i++)
        {
            g_dj_cntx.inline_data.audio_str[i] = (UI_string_type) GetString((U16) (STR_ID_MOTION_DJ_VOCAL_0 + i));
        }
    }

    SetInlineItemActivation(&wgui_inline_items[item_idx], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_idx],
        DJ_AUDIO_COUNT,
        (U8 **) g_dj_cntx.inline_data.audio_str,
        &g_dj_cntx.inline_data.audio_selected);

    RegisterInlineSelectHighlightHandler(&wgui_inline_items[item_idx], mmi_motion_dj_edit_audio_highlight_handler);

    item_idx++;

#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
   /************************************/
    /* volume - inline selection        */
   /************************************/

    /* caption */
    SetInlineItemCaption(&wgui_inline_items[item_idx], (PU8) GetString((U16) (STR_ID_MOTION_DJ_EDIT_VOLUME)));
    item_idx++;

    /* inline selection */
    for (i = 0; i < DJ_VOLUME_LEVEL; i++)
    {
        g_dj_cntx.inline_data.volume_str[i] = (UI_string_type) GetString((U16) (STR_GLOBAL_0 + i + 1));
    }

    SetInlineItemActivation(&wgui_inline_items[item_idx], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_idx],
        DJ_VOLUME_LEVEL,
        (U8 **) g_dj_cntx.inline_data.volume_str,
        &g_dj_cntx.inline_data.volume_selected);

    item_idx++;
#endif /* DJ_ENABLE_INDIVISUAL_VOLUME */ 

   /************************************/
    /* trigger - inline selection       */
   /************************************/

    /* caption */
    SetInlineItemCaption(&wgui_inline_items[item_idx], (PU8) GetString((U16) (STR_ID_MOTION_DJ_EDIT_TRIGGER)));
    item_idx++;

    /* inline selection */

    g_dj_cntx.inline_data.trigger_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_NONE));

    for (i = 0; i < NUM_OF_DJ_TRIGGER_TYPE - 1; i++)
    {
        g_dj_cntx.inline_data.trigger_str[i + 1] =
            (UI_string_type) GetString((U16) (STR_ID_MOTION_DJ_EDIT_TRIGGER_AUTO + i));
    }

    SetInlineItemActivation(&wgui_inline_items[item_idx], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_idx],
        NUM_OF_DJ_TRIGGER_TYPE,
        (U8 **) g_dj_cntx.inline_data.trigger_str,
        &g_dj_cntx.inline_data.trigger_selected);

    RegisterInlineSelectHighlightHandler(&wgui_inline_items[item_idx], mmi_motion_dj_edit_trigger_highlight_handler);

    item_idx++;

   /************************************/
    /* key - inline selection           */
   /************************************/

    /* caption */
    SetInlineItemCaption(&wgui_inline_items[item_idx], (PU8) GetString((U16) (STR_ID_MOTION_DJ_EDIT_KEY)));
    item_idx++;

    /* inline selection */
    g_dj_cntx.inline_data.key_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_NONE));

    for (i = 0; i < NUM_OF_DJ_KEY - 1; i++)
    {
        g_dj_cntx.inline_data.key_str[i + 1] = (UI_string_type) GetString((U16) (STR_ID_MOTION_DJ_KEY_0 + i));
    }

    SetInlineItemActivation(&wgui_inline_items[item_idx], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_idx],
        NUM_OF_DJ_KEY,
        (U8 **) g_dj_cntx.inline_data.key_str,
        &g_dj_cntx.inline_data.key_selected);

    RegisterInlineSelectHighlightHandler(&wgui_inline_items[item_idx], mmi_motion_dj_edit_key_highlight_handler);

    item_idx++;

    /* show screen */
    input_buffer = GetCurrNInputBuffer(SCR_ID_MOTION_DJ_EDIT, &input_buffer_size);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, item_idx, input_buffer);
    }

    RegisterHighlightHandler(mmi_motion_dj_edit_highlight_hdlr);

    ShowCategory57Screen(
        SCR_ID_MOTION_DJ_EDIT,
        DJ_MENU_ICON_IMG_ID,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_idx,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);

    /* set key hdlr */
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    DisableCategory57ScreenDone();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_exit_edit_scr
 * DESCRIPTION
 *  exit event edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_exit_edit_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    S16 num_history = 0;
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_string();
    mdi_audio_resume_background_play();

    CloseCategory57Screen();
    h.scrnID = SCR_ID_MOTION_DJ_EDIT;
    h.entryFuncPtr = mmi_motion_dj_entry_edit_scr;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & num_history);
    input_buffer_size = (U16) GetCategory57DataSize();

    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_edit_highlight_hdlr
 * DESCRIPTION
 *  setting edit done
 * PARAMETERS
 *  index       [IN]        Selected index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_edit_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_string();

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_motion_dj_edit_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_edit_trigger_highlight_handler
 * DESCRIPTION
 *  inline select trigger hilight handler
 * PARAMETERS
 *  index       [IN]        Selected index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_edit_trigger_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* trigger changed */
    if (g_dj_cntx.prev_trigger != g_dj_cntx.inline_data.trigger_selected)
    {
        g_dj_cntx.prev_trigger = g_dj_cntx.inline_data.trigger_selected;

        if (g_dj_cntx.inline_data.key_selected != DJ_KEY_NONE)
        {
            g_dj_cntx.inline_data.key_selected = DJ_KEY_NONE;

            EntryNewScreen(SCR_ID_MOTION_DJ_DUMMY, NULL, NULL, NULL);
            GoBackHistory();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_edit_audio_highlight_handler
 * DESCRIPTION
 *  inline select audio hilight handler
 * PARAMETERS
 *  index       [IN]        Selected index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_edit_audio_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_string();
    gui_start_timer(400, mmi_motion_dj_edit_delay_play_audio);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_edit_delay_play_audio
 * DESCRIPTION
 *  delay play audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_edit_delay_play_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 select_aud_idx;
    PU8 raw_data = NULL;
    U32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    select_aud_idx = g_dj_cntx.inline_data.audio_selected;

    if (g_dj_cntx.selected_audio_type == DJ_AUD_INSTRUMENT)
    {
#define INST_SWITCH_CASE(__id__)                      \
         case __id__:                                       \
         raw_data = (PU8)motion_dj_instrument_midi_##__id__;\
         size     =  DJ_AUD_INS_MIDI_##__id__##_LEN;        \
         break;                                             \

        switch (select_aud_idx)
        {
        INST_SWITCH_CASE(0)
                    INST_SWITCH_CASE(1)
                    INST_SWITCH_CASE(2)
                    INST_SWITCH_CASE(3)
                    INST_SWITCH_CASE(4)
                    INST_SWITCH_CASE(5) INST_SWITCH_CASE(6) INST_SWITCH_CASE(7) INST_SWITCH_CASE(8) INST_SWITCH_CASE(9)}

        mdi_audio_play_string_with_vol_path_non_block(
            (void*)raw_data,
            (U32) size,
            MDI_FORMAT_SMF,
            DEVICE_AUDIO_PLAY_ONCE,
            NULL,
            NULL,
            mmi_gfx_get_audio_vol(),
            MDI_DEVICE_SPEAKER2);
    }
    else
    {

#define VOX_SWITCH_CASE(__id__)                 \
         case __id__:                                 \
         raw_data = (PU8)motion_dj_vocal_wav_##__id__;\
         size     =  DJ_AUD_VOX_WAVE_##__id__##_LEN;  \
         break;                                       \

        switch (select_aud_idx)
        {
        VOX_SWITCH_CASE(0)
                    VOX_SWITCH_CASE(1)
                    VOX_SWITCH_CASE(2)
                    VOX_SWITCH_CASE(3)
                    VOX_SWITCH_CASE(4)
                    VOX_SWITCH_CASE(5) VOX_SWITCH_CASE(6) VOX_SWITCH_CASE(7) VOX_SWITCH_CASE(8) VOX_SWITCH_CASE(9)}

        mdi_audio_play_string_with_vol_path_non_block(
            (void*)raw_data,
            (U32) size,
            MDI_FORMAT_WAV,
            DEVICE_AUDIO_PLAY_ONCE,
            NULL,
            NULL,
            mmi_gfx_get_audio_vol(),
            MDI_DEVICE_SPEAKER2);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_edit_key_highlight_handler
 * DESCRIPTION
 *  setting edit done
 * PARAMETERS
 *  index       [IN]        Selected index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_edit_key_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_edit_done
 * DESCRIPTION
 *  setting edit done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 i;

    U16 trigger;
    U16 key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    trigger = g_dj_cntx.inline_data.trigger_selected;
    key = g_dj_cntx.inline_data.key_selected;

    if (trigger != DJ_TRIGGER_NONE)
    {

        /* trigger is press but key is not set */
        if (trigger == DJ_TRIGGER_PRESS)
        {
            if (key == DJ_KEY_NONE)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_MOTION_DJ_NOTIFY_EMPTY_KEY),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                return;
            }
        }

        for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
        {
            if (g_dj_cntx.selected_idx != i)
            {
                if (trigger == DJ_TRIGGER_AUTO)
                {
                    if (g_dj_cntx.event_list[i].trigger == trigger)
                    {
                        /* already has auto trigger event */
                        DisplayPopup(
                            (PU8) GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_AUTO),
                            IMG_GLOBAL_WARNING,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            WARNING_TONE);
                        return;
                    }
                    else
                    {
                        g_dj_cntx.inline_data.key_selected = DJ_KEY_NONE;
                    }
                }
                else if ((trigger == DJ_TRIGGER_SHAKE) || (trigger == DJ_TRIGGER_PRESS))
                {
                    /* has same event - shake and press with same key */
                    if ((g_dj_cntx.event_list[i].key != DJ_KEY_NONE) && (g_dj_cntx.event_list[i].key == key))
                    {
                        if (trigger == DJ_TRIGGER_SHAKE)
                        {
                            DisplayPopup(
                                (PU8) GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE_SAME_KEY),
                                IMG_GLOBAL_WARNING,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                WARNING_TONE);
                            return;
                        }
                        else if (trigger == DJ_TRIGGER_PRESS)
                        {
                            DisplayPopup(
                                (PU8) GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_PRESS_SAME_KEY),
                                IMG_GLOBAL_WARNING,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                WARNING_TONE);
                            return;
                        }
                    }
                    else if ((trigger == DJ_TRIGGER_SHAKE) &&
                             (key == DJ_KEY_NONE) &&
                             (g_dj_cntx.event_list[i].trigger == trigger) && (g_dj_cntx.event_list[i].key == key))
                    {
                        /* has shake only */
                        DisplayPopup(
                            (PU8) GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE),
                            IMG_GLOBAL_WARNING,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            WARNING_TONE);
                        return;
                    }
                }
            }
        }

    }

    /* checking: can only have 1 auto */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    DeleteNHistory(1);

    /* pass , write to NVRAM */
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].audio_id = g_dj_cntx.inline_data.audio_selected;
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].vol = g_dj_cntx.inline_data.volume_selected;
#endif 
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].trigger = g_dj_cntx.inline_data.trigger_selected;
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].key = g_dj_cntx.inline_data.key_selected;

    /* write value from NVRAM */
    WriteRecord(
        NVRAM_EF_MOTION_DJ_LID,
        g_dj_cntx.selected_idx+1,
        (void*)&g_dj_cntx.event_list[g_dj_cntx.selected_idx],
        NVRAM_EF_MOTION_DJ_SIZE,
        &error);

}

/*****************************************************************************
*
*  Play Screen                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_play_scr
 * DESCRIPTION
 *  enter play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 i;
    BOOL has_trigger;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has any trigger */

    has_trigger = FALSE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
        {
            has_trigger = TRUE;
        }
    }

    if (!has_trigger)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_MOTION_DJ_NOTIFY_EMPTY_TRIGGER),
            IMG_GLOBAL_INFO,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }

    /* entry new screen */
    EntryNewScreen(SCR_ID_MOTION_DJ_PLAY, mmi_motion_dj_exit_play_scr, mmi_motion_dj_entry_play_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_MOTION_DJ_PLAY);

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    /* enable motion sensor */
    mdi_motion_power_on();

    mdi_motion_start_listen_shake(MDI_MOTION_SENSITIVE_LOW, mmi_motion_dj_play_shake_trigger);

    /* RSK up leave screen */
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_motion_dj_play_key_0_press, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_0_release, KEY_0, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_1_press, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_1_release, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_2_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_2_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_3_press, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_3_release, KEY_3, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_4_press, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_4_release, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_5_press, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_5_release, KEY_5, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_6_press, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_6_release, KEY_6, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_7_press, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_7_release, KEY_7, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_8_press, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_8_release, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_9_press, KEY_9, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_9_release, KEY_9, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_star_press, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_star_release, KEY_STAR, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_pound_press, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_pound_release, KEY_POUND, KEY_EVENT_UP);

#ifndef DJ_ENABLE_INDIVISUAL_VOLUME
    SetKeyHandler(mmi_gfx_volume_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gfx_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* DJ_ENABLE_INDIVISUAL_VOLUME */ 

    mdi_audio_set_volume(MDI_VOLUME_MEDIA, mmi_gfx_get_audio_vol());

    for (i = 0; i < NUM_OF_DJ_KEY; i++)
    {
        g_dj_cntx.is_key_pressed[i] = FALSE;

        g_dj_cntx.draw_state[i].is_trigger_sel = FALSE;
        g_dj_cntx.draw_state[i].is_key_sel = FALSE;
        g_dj_cntx.draw_state[i].is_text_sel = FALSE;
    }

    /* start a bg midi which will always active DPS */
    g_dj_cntx.aud_bg_handle = mdi_audio_mma_open_midi((void*)motion_dj_aud_dummy_bg, DJ_AUD_DUMMY_BG_LEN, 0, NULL);

    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
    mdi_audio_mma_play_midi(g_dj_cntx.aud_bg_handle);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        g_dj_cntx.aud_handle[i] = 0;

        if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
        {
            /* clear handle first */
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
#define DJ_OPEN_MIDI_CASE(__idx__)                                             \
            {                                                                              \
               case(__idx__):                                                              \
               {                                                                           \
                  if(g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)                   \
                  {                                                                        \
                     g_dj_cntx.aud_handle[i] =                                             \
                        mdi_audio_mma_open_midi((void*)motion_dj_instrument_midi_##__idx__,\
                                                (U32)DJ_AUD_INS_MIDI_##__idx__##_LEN,      \
                                                0,                                         \
                                                NULL);                                     \
                  }                                                                        \
                  else                                                                     \
                  {                                                                        \
                     g_dj_cntx.aud_handle[i] =                                             \
                        mdi_audio_mma_open_midi((void*)motion_dj_instrument_midi_##__idx__,\
                                                (U32)DJ_AUD_INS_MIDI_##__idx__##_LEN,      \
                                                1,                                         \
                                                NULL);                                     \
                  }                                                                        \
               }                                                                           \
               break;                                                                      \
            }

                switch (g_dj_cntx.event_list[i].audio_id)
                {
                        DJ_OPEN_MIDI_CASE(0);
                        DJ_OPEN_MIDI_CASE(1);
                        DJ_OPEN_MIDI_CASE(2);
                        DJ_OPEN_MIDI_CASE(3);
                        DJ_OPEN_MIDI_CASE(4);
                        DJ_OPEN_MIDI_CASE(5);
                        DJ_OPEN_MIDI_CASE(6);
                        DJ_OPEN_MIDI_CASE(7);
                        DJ_OPEN_MIDI_CASE(8);
                        DJ_OPEN_MIDI_CASE(9);
                }
            }

            /* start auto play */
            if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
                mdi_audio_mma_play_midi(g_dj_cntx.aud_handle[i]);
            }

        }
        else
        {
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
#define DJ_OPEN_WAVE_CASE(__idx__)                                       \
            {                                                                        \
               case(__idx__):                                                        \
               {                                                                     \
                  if(g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)             \
                  {                                                                  \
                     g_dj_cntx.aud_handle[i] =                                       \
                        mdi_audio_mma_open_wav((void*)motion_dj_vocal_wav_##__idx__, \
                                                (U32)DJ_AUD_VOX_WAVE_##__idx__##_LEN,\
                                                0,                                   \
                                                NULL);                               \
                  }                                                                  \
                  else                                                               \
                  {                                                                  \
                     g_dj_cntx.aud_handle[i] =                                       \
                        mdi_audio_mma_open_wav((void*)motion_dj_vocal_wav_##__idx__, \
                                                (U32)DJ_AUD_VOX_WAVE_##__idx__##_LEN,\
                                                1,                                   \
                                                NULL);                               \
                  }                                                                  \
               }                                                                     \
               break;                                                                \
            }

                switch (g_dj_cntx.event_list[i].audio_id)
                {
                        DJ_OPEN_WAVE_CASE(0);
                        DJ_OPEN_WAVE_CASE(1);
                        DJ_OPEN_WAVE_CASE(2);
                        DJ_OPEN_WAVE_CASE(3);
                        DJ_OPEN_WAVE_CASE(4);
                        DJ_OPEN_WAVE_CASE(5);
                        DJ_OPEN_WAVE_CASE(6);
                        DJ_OPEN_WAVE_CASE(7);
                        DJ_OPEN_WAVE_CASE(8);
                        DJ_OPEN_WAVE_CASE(9);
                }

                /* start auto play */
                if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)
                {
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
                    mdi_audio_mma_play_wav(g_dj_cntx.aud_handle[i]);
                }
            }
        }
    }

    /* create layer */
    gdi_layer_get_base_handle(&g_dj_cntx.bg_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &g_dj_cntx.item_layer);
    gdi_layer_push_and_set_active(g_dj_cntx.item_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_dj_cntx.bg_layer, g_dj_cntx.item_layer, 0, 0);

    /* draw backgroud */
    gdi_layer_push_and_set_active(g_dj_cntx.bg_layer);
    gdi_image_draw_animation_id(0, 0, IMG_ID_MOTION_DJ_PLAY_BG, &g_dj_cntx.bg_anim);
    gdi_layer_pop_and_restore_active();

    /* draw items */
    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_exit_play_scr
 * DESCRIPTION
 *  enter play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_exit_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_motion_dj_auto_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_0_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_1_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_2_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_3_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_4_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_5_icon_timeout);

    gdi_image_stop_animation(g_dj_cntx.bg_anim);

    /* disable motion sensor */
    mdi_motion_power_off();

    /* stop dummy background audio */
    mdi_audio_mma_stop_midi(g_dj_cntx.aud_bg_handle);
    mdi_audio_mma_close_midi(g_dj_cntx.aud_bg_handle);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.aud_handle[i] != 0)
        {
            if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
            {
                mdi_audio_mma_stop_midi(g_dj_cntx.aud_handle[i]);
                mdi_audio_mma_close_midi(g_dj_cntx.aud_handle[i]);
            }
            else
            {
                mdi_audio_mma_stop_wav(g_dj_cntx.aud_handle[i]);
                mdi_audio_mma_close_wav(g_dj_cntx.aud_handle[i]);
            }
        }
    }

    /* free layer */
    gdi_layer_free(g_dj_cntx.item_layer);
    gdi_layer_set_blt_layer(g_dj_cntx.bg_layer, 0, 0, 0);

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* this will force title status to redraw */
    entry_full_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_draw_items
 * DESCRIPTION
 *  draw items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_draw_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 text_id;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_dj_cntx.item_layer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
        {

            if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
            {
                text_id = STR_ID_MOTION_DJ_INSTRUMENT_0;
            }
            else
            {
                text_id = STR_ID_MOTION_DJ_VOCAL_0;
            }

            if (g_dj_cntx.draw_state[i].is_trigger_sel)
            {
                gdi_image_draw_id(
                    g_dj_draw_pos[i].icon_trigger_x,
                    g_dj_draw_pos[i].icon_trigger_y,
                    (U16) (IMG_ID_MOTION_DJ_PLAY_NONE_SEL + g_dj_cntx.event_list[i].trigger));
            }
            else
            {
                gdi_image_draw_id(
                    g_dj_draw_pos[i].icon_trigger_x,
                    g_dj_draw_pos[i].icon_trigger_y,
                    (U16) (IMG_ID_MOTION_DJ_PLAY_NONE + g_dj_cntx.event_list[i].trigger));

            }

            if (g_dj_cntx.event_list[i].key != DJ_KEY_NONE)
            {
                if (g_dj_cntx.draw_state[i].is_key_sel)
                {
                    gdi_image_draw_id(
                        g_dj_draw_pos[i].icon_key_x,
                        g_dj_draw_pos[i].icon_key_y,
                        (U16) (IMG_ID_MOTION_DJ_PLAY_KEY_0_SEL + g_dj_cntx.event_list[i].key - 1));
                }
                else
                {
                    gdi_image_draw_id(
                        g_dj_draw_pos[i].icon_key_x,
                        g_dj_draw_pos[i].icon_key_y,
                        (U16) (IMG_ID_MOTION_DJ_PLAY_KEY_0 + g_dj_cntx.event_list[i].key - 1));
                }
            }

            gui_set_font(&MMI_medium_font);

            gui_move_text_cursor(g_dj_draw_pos[i].text_x, g_dj_draw_pos[i].text_y);
            gui_set_text_color(DJ_FONT_COLOR);
            gui_set_text_border_color(DJ_FONT_BORDER_COLOR);
            gui_print_bordered_text((UI_string_type) GetString((U16) (text_id + g_dj_cntx.event_list[i].audio_id)));

        }
    }

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_play_shake_trigger
 * DESCRIPTION
 *  shake trigger
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_play_shake_trigger(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    BOOL has_shake_key;
    BOOL has_shake_only;
    S32 shake_key_idx = 0;
    S32 shake_only_idx = 0;
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has shake event with key press */

    has_shake_key = FALSE;
    has_shake_only = FALSE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        /* has shake with key event */
        if ((g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE) &&
            (g_dj_cntx.event_list[i].key != DJ_KEY_NONE) &&
            (g_dj_cntx.is_key_pressed[g_dj_cntx.event_list[i].key] == TRUE))
        {
            has_shake_key = TRUE;
            shake_key_idx = i;
            break;
        }
        else if ((g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE) && (g_dj_cntx.event_list[i].key == DJ_KEY_NONE))
        {
            has_shake_only = TRUE;
            shake_only_idx = i;
        }
    }

    if (has_shake_key || has_shake_only)
    {
        if (has_shake_key)
        {
            idx = shake_key_idx;
        }
        else if (has_shake_only)
        {
            idx = shake_only_idx;
        }

        g_dj_cntx.draw_state[idx].is_trigger_sel = TRUE;

        switch (idx)
        {
            case 0:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_0_icon_timeout);
                break;

            case 1:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_1_icon_timeout);
                break;

            case 2:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_2_icon_timeout);
                break;

            case 3:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_3_icon_timeout);
                break;

            case 4:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_4_icon_timeout);
                break;

            case 5:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_5_icon_timeout);
                break;
        }

        if (idx < DJ_NUM_OF_INSTRUMENT_ENTRY)
        {
            mdi_audio_mma_stop_midi(g_dj_cntx.aud_handle[idx]);
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
            mdi_audio_mma_play_midi(g_dj_cntx.aud_handle[idx]);
        }
        else
        {
            mdi_audio_mma_stop_wav(g_dj_cntx.aud_handle[idx]);
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
            mdi_audio_mma_play_wav(g_dj_cntx.aud_handle[idx]);
        }

        mmi_motion_dj_draw_items();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        return;
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_motion_dj_auto_play_finish_hdlr()
* DESCRIPTION
*   key  press handler
* PARAMETERS
*   mdi_result IN    audio handle
*   result     IN    play result 
* RETURNS
*   void
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_auto_icon_timeout
 * DESCRIPTION
 *  time out to darw small auto icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_auto_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the auto icon, draw unselect icon */

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)
        {
            g_dj_cntx.draw_state[i].is_trigger_sel = FALSE;

            mmi_motion_dj_draw_items();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_0_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_0_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[0].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_1_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_1_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[1].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_2_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_2_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[2].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_3_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_3_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[3].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_4_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_4_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[4].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_5_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_5_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[5].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_play_key_press_handler
 * DESCRIPTION
 *  key  press handler
 * PARAMETERS
 *  key_id      [IN]        Key_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_play_key_press_handler(U16 key_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.is_key_pressed[key_id] = TRUE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].key == key_id)
        {
            if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_PRESS)
            {
                g_dj_cntx.draw_state[i].is_trigger_sel = TRUE;
                g_dj_cntx.draw_state[i].is_key_sel = TRUE;

                if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
                {
                    mdi_audio_mma_stop_midi(g_dj_cntx.aud_handle[i]);
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
                    mdi_audio_mma_play_midi(g_dj_cntx.aud_handle[i]);
                }
                else
                {
                    mdi_audio_mma_stop_wav(g_dj_cntx.aud_handle[i]);
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
                    mdi_audio_mma_play_wav(g_dj_cntx.aud_handle[i]);
                }
            }
            else if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE)
            {
                g_dj_cntx.draw_state[i].is_key_sel = TRUE;
            }

            mmi_motion_dj_draw_items();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_play_key_release_handler
 * DESCRIPTION
 *  key  release handler
 * PARAMETERS
 *  key_id      [IN]        Key_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_play_key_release_handler(U16 key_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.is_key_pressed[key_id] = FALSE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].key == key_id)
        {
            if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_PRESS)
            {
                g_dj_cntx.draw_state[i].is_trigger_sel = FALSE;
                g_dj_cntx.draw_state[i].is_key_sel = FALSE;
            }
            else if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE)
            {
                g_dj_cntx.draw_state[i].is_key_sel = FALSE;
            }

            mmi_motion_dj_draw_items();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            return;
        }
    }
}

#define DJ_KEY_HANDLER(__key__,__KEY__)                        \
   static void mmi_motion_dj_play_key_##__key__##_press(void)  \
   {                                                           \
      mmi_motion_dj_play_key_press_handler(DJ_KEY_##__KEY__);  \
   }                                                           \
   static void mmi_motion_dj_play_key_##__key__##_release(void)\
   {                                                           \
      mmi_motion_dj_play_key_release_handler(DJ_KEY_##__KEY__);\
   }

DJ_KEY_HANDLER(0, 0)
DJ_KEY_HANDLER(1, 1)
DJ_KEY_HANDLER(2, 2)
DJ_KEY_HANDLER(3, 3)
DJ_KEY_HANDLER(4, 4)
DJ_KEY_HANDLER(5, 5)
DJ_KEY_HANDLER(6, 6)
DJ_KEY_HANDLER(7, 7) DJ_KEY_HANDLER(8, 8) DJ_KEY_HANDLER(9, 9) DJ_KEY_HANDLER(star, STAR) DJ_KEY_HANDLER(pound, POUND)
#endif /* IS_DJ_BASE_MOTIONGAME */ 
#endif /* _MMI_MOTION_DJ_C */ 

