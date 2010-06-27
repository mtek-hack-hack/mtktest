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
*  FMRadioSrc.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main program
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * modify issue MAUI_00426151
 *
 * removed!
 * removed!
 * remove pfnxxx string
 *
 * removed!
 * removed!
 * modify issue : MAUI_00423303
 *
 * removed!
 * removed!
 * Remove MMI_ON_WIN32 and MMI_ON_HARDWARE_P
 *
 * removed!
 * removed!
 * modify to add volume press effect
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
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_FM_RADIO__

#include "MainMenuDef.h"
#include "CommonScreens.h"
#include "ProfilesDefs.h"
#include "ProfileGprots.h"

#ifdef __MMI_AUDIO_PLAYER__
extern void mmi_audply_stop_playing(void);
extern BOOL mmi_audply_is_play_activated(void);
#endif 

#include "aud_defs.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Device.h"
#include "SettingProfile.h"
#include "Ucs2prot.h"

#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"

#if defined(__MMI_FM_RADIO_RECORD__)
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "Rtc_sw.h"

#include "USBDeviceGprot.h"
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 


#ifdef __MMI_SUBLCD_MASTER_MODE__
#include "wgui_status_icons.h"
#endif

mmi_fmrdo_struct g_fmrdo;   /* all memeber variables are zero initial */
static BOOL channel_name_edit_done;
static U16 main_option_highlighted_item_text;
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
static U16 g_subLCD_option_highlighted_item;  /*for highlight the item of option menu of FMRadio on SubLCD*/
#endif
static U16 channel_list_highlighted_item_index;
static U16 channel_option_highlighted_item_text;
static U16 channel_name_edit_option_highlighted_item_text;
static UI_character_type channel_name_str[MAX_NAME_INPUT_LEN + 10];     /* used for showing channel_name or freq in idle screen or subLCD */

static BOOL setfmmute=FALSE;//UNI@bw_20070420  单步搜索无声问题//ghw111
static S32 selected_background_play;
static S32 selected_skin_index;
static UI_character_type manual_input_buffer[MAX_MANUAL_INPUT_LEN];
static UI_character_type name_inline_editor_buffer[MAX_NAME_INPUT_LEN];
static UI_character_type freq_inline_editor_buffer[MAX_MANUAL_INPUT_LEN];
static UI_character_type name_text_editor_buffer[MAX_NAME_INPUT_LEN];
static UI_string_type background_play_texts[2];
static UI_string_type skin_texts[3];

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
static S32 selected_speaker_status;
static UI_string_type speaker_status_texts[2];
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 

#if defined(__MMI_FM_RADIO_RECORD__)
static S32 selected_record_format;
static S32 selected_record_quality;
static S32 selected_record_storage;
static UI_string_type record_format_texts[FM_REC_FORMAT_NUM];
static UI_string_type record_quality_texts[NO_OF_QUALITY];
static UI_character_type fmrdo_editor_buff[MAX_FM_INPUT_FILE_LEN + 2];
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

extern wgui_inline_item wgui_inline_items[];        /* defined in wgui_inline_edit.c */
extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
extern const mmi_fmrdo_sub_skin_struct g_fmrdo_subLCD_skins[];
extern void (*SUBLCD_ExitCategoryFunction) (void) ;
#endif 

extern U8 isEarphonePlugged;                        /* definedin gpio.c */

extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);
extern void kal_get_time(kal_uint32 *ticks_ptr);

#ifdef __MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__
extern BOOL FMR_IsChipValid(void);  /* this function is definedin in l1audio */
S32 g_fmrdo_menu_item_index;


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_skip_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_skip_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo_menu_item_index >= 0 && index >= g_fmrdo_menu_item_index)
    {
        index++;
    }
    ExecuteCurrHiliteHandler(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_check_chip_or_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  n_items         [IN]        U16* string_ids, U16* icon_ids
 *  string_ids      [?]         
 *  icon_ids        [?]         
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!FMR_IsChipValid())
    {
        /* hide FM Radio application menu item */
        S16 i, j;

        for (i = n_items - 1; i >= 0; i--)
        {
            if (string_ids[i] == STR_ID_FMRDO_TITLE)    /* look for FM Radio application string id */
            {
                break;
            }
        }
        g_fmrdo_menu_item_index = i;
        if (i >= 0) /* found FM Radio application string id */
        {
            n_items--;
            for (j = i; j < n_items; j++)   /* move rest application string & image ids up */
            {
                string_ids[j] = string_ids[j + 1];
                icon_ids[j] = icon_ids[j + 1];
            }
        }
    }
    else
    {
        g_fmrdo_menu_item_index = -1;
    }

    return n_items;
}
#endif /* __MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_subLCD_shown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_subLCD_shown(BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.is_subLCD_shown = is_shown;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_power_on_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_power_on_main_screen(BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.in_main_screen || IsScreenPresent(SCR_ID_FMRDO_MAIN))
    {
        mmi_fmrdo_power_on(turn_on);
    }
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(g_fmrdo.in_subLCD_main_screen)
    {
        mmi_fmrdo_power_on(turn_on);
    }
#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_is_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_fmrdo_is_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_fmrdo.is_ready && g_fmrdo.is_power_on);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_channel_name_or_freq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_fmrdo_get_channel_name_or_freq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str = channel_name_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        mmi_ucs2cpy((S8*) str, (const S8*)GetString(STR_ID_FMRDO_SEARCHING));
    }
    else
    {
        if (g_fmrdo.channel_index >= 0)
        {
            if (mmi_ucs2strlen((S8*) g_fmrdo.channel_list.name[g_fmrdo.channel_index]) > 0)
            {
                kal_wsprintf(
                    str,
                    "%d. %w",
                    g_fmrdo.channel_index + 1,
                    g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
            }
            else
            {
                kal_wsprintf(
                    str,
                    "%d. FM %d.%d",
                    g_fmrdo.channel_index + 1,
                    g_fmrdo.frequency / 10,
                    g_fmrdo.frequency % 10);
            }
        }
        else
        {
            kal_wsprintf(str, "FM %d.%d", g_fmrdo.frequency / 10, g_fmrdo.frequency % 10);
        }
    }
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_preset_list_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal_band     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern int fm_channel_selected[FM_RADIO_CHANNEL_NUM][2]; //hongzhe.liu add
#if defined(FM_RADIO_WITH_TV)
void mmi_fmrdo_preset_list_done( U16* signal_band )
#else
void mmi_fmrdo_preset_list_done(U8 *signal_band)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.state = FMRDO_STATE_READY;

    /* clear channel list */
    memset(g_fmrdo.channel_list.freq, 0, FM_RADIO_CHANNEL_NUM * sizeof(U16));
    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    {
        mmi_ucs2cpy((S8*) g_fmrdo.channel_list.name[i], (S8*) L"");
    }

#ifndef FM_RADIO_WITH_TV
//del by hongzhe.liu 
    /* set channel list */
    for (i = j = 0; i < FM_BANDWIDTH; i++)
    {
        if (FM_SIG_MARK(signal_band[i]))
        {
            mmi_fmrdo_set_channel(
                j++,
                (U16) (i + MIN_FM_FREQUENCY),
                (UI_string_type) GetString(STR_ID_FMRDO_NEW_CHANNEL));
            if (j > FM_RADIO_CHANNEL_NUM)
            {
                break;  /* this line should never be reached if the searching algorithm is correct!! */
            }
        }
    }
#else
    /* set channel list */
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\nHuyanwei Debug:\r\n\
    g_fmrdo.is_button_down=%d\r\n\
    g_fmrdo.selected_button=%d(1?)\r\n\
    g_fmrdo.is_ready=%d\r\n\
    g_fmrdo.state=%d\r\n\
    g_fmrdo.is_search_on=%d\r\n",\
    g_fmrdo.is_button_down,g_fmrdo.selected_button,g_fmrdo.is_ready,g_fmrdo.state,g_fmrdo.is_search_on);
#endif
    for (i = j =0; i < FM_RADIO_CHANNEL_NUM; i++)
    {
        if (fm_channel_selected[i][0] != 0)
        {
#if defined(NOKE_DEBUG)
        	noke_dbg_printf("\r**** Hongzhe.liu Write channel to nvram : %d\n", fm_channel_selected[i][0]);
#endif
            mmi_fmrdo_set_channel(
                j++,
                fm_channel_selected[i][0],
                (UI_string_type) GetString(STR_ID_FMRDO_NEW_CHANNEL));
        }
    }
#endif

    /* write channel list from nvram */
    WriteRecord(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE, &error);

    /* rematch channel index */
    g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(IsSubLCDInMasterMode())
    {
            ClearAllKeyHandler();
            GoBackSubLCDHistory();
    }   
    else 
#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/
    { 
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_FMRDO_SEARCHING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_start_twinkle_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_start_twinkle_frequency(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.twinkle_frequency_count = 0;
    StartTimer(FMRDO_TWINKLE_FREQUENCY_TIMER, TWINKLE_FREQUENCY_ON_TIME, mmi_fmrdo_twinkle_frequency_timer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_stop_twinkle_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_stop_twinkle_frequency(BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMRDO_TWINKLE_FREQUENCY_TIMER);
    if (is_shown && g_fmrdo.twinkle_frequency_count % 2 == 0)
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_long_press_number_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_long_press_number_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;
    U16 channel_index;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
    {
        /* get key number */
        GetkeyInfo((U16*) & key_code, (U16*) & key_type);
        channel_index = key_code - KEY_1;

        /* set channel */
        mmi_fmrdo_set_channel(channel_index, g_fmrdo.frequency, (UI_string_type) GetString(STR_ID_FMRDO_NEW_CHANNEL));

        /* write channel list from nvram */
        WriteRecord(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE, &error);

        g_fmrdo.channel_index = channel_index;

        /* update channel name */
        mmi_fmrdo_redraw_main_channel_name(0);

        /* start twinkle frequency */
        mmi_fmrdo_start_twinkle_frequency();
    }
    g_fmrdo.is_long_press_number_key = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_number_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_number_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;
    U16 freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        mmi_fmrdo_search_frequency_stop();
    }

    if (!g_fmrdo.is_long_press_number_key)
    {
        /* stop previous twinkle frequency if necessary */
        mmi_fmrdo_stop_twinkle_frequency(FALSE);

        GetkeyInfo((U16*) & key_code, (U16*) & key_type);
        freq = g_fmrdo.channel_list.freq[key_code - KEY_1];
        if (freq != 0)
        {
            mmi_fmrdo_goto_channel((U16) (key_code - KEY_1));
        }
    }
    g_fmrdo.is_long_press_number_key = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_twinkle_frequency_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_twinkle_frequency_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.twinkle_frequency_count % 2 == 0)   /* twinkle off */
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, FALSE);
        if (g_fmrdo.twinkle_frequency_count < TWINKLE_FREQUENCY_COUNT)
        {
            g_fmrdo.twinkle_frequency_count++;
            StartTimer(FMRDO_TWINKLE_FREQUENCY_TIMER, TWINKLE_FREQUENCY_OFF_TIME, mmi_fmrdo_twinkle_frequency_timer);
        }
    }
    else    /* twinkle on */
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
        if (g_fmrdo.twinkle_frequency_count < TWINKLE_FREQUENCY_COUNT)
        {
            g_fmrdo.twinkle_frequency_count++;
            StartTimer(FMRDO_TWINKLE_FREQUENCY_TIMER, TWINKLE_FREQUENCY_ON_TIME, mmi_fmrdo_twinkle_frequency_timer);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_step_down_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_step_down_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.step_freq > MIN_FM_FREQUENCY)
    {
        g_fmrdo.step_freq--;
    }
    else
    {
        g_fmrdo.step_freq = MAX_FM_FREQUENCY;
    }

    /* update display */
    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.step_freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.step_freq);
    }
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(g_fmrdo.in_subLCD_main_screen)
    {
        UI_set_sub_LCD_graphics_context();
        mmi_fmrdo_sub_redraw_frequency(g_fmrdo.step_freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.step_freq);
        UI_set_main_LCD_graphics_context();
    }
#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/

    if (g_fmrdo.normal_repeat_step_count == 0 && g_fmrdo.is_power_on)
    {
        mdi_fmr_mute(1);    /* mute in the begining of step down */
   setfmmute=TRUE;//UNI@bw_20070420  单步搜索无声问题	//ghw111
    }

    if (g_fmrdo.normal_repeat_step_count < NORMAL_REAPEAT_STEP_COUNT)
    {
        g_fmrdo.normal_repeat_step_count++;
        StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_down_timer);
    }
    else
    {
        StartTimer(FMRDO_REPEAT_STEP_TIMER, FAST_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_down_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_step_up_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_step_up_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.step_freq < MAX_FM_FREQUENCY)
    {
        g_fmrdo.step_freq++;
    }
    else
    {
        g_fmrdo.step_freq = MIN_FM_FREQUENCY;
    }

    /* update display */
    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.step_freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.step_freq);
    }
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(g_fmrdo.in_subLCD_main_screen)
    {
        UI_set_sub_LCD_graphics_context();
        mmi_fmrdo_sub_redraw_frequency(g_fmrdo.step_freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.step_freq);
        UI_set_main_LCD_graphics_context();
    }
#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/

    if (g_fmrdo.normal_repeat_step_count == 0 && g_fmrdo.is_power_on)
    {
        mdi_fmr_mute(1);    /* mute in the begining of step up */
		setfmmute=TRUE;//UNI@bw_20070420  单步搜索无声问题	//ghw111
    }

    if (g_fmrdo.normal_repeat_step_count < NORMAL_REAPEAT_STEP_COUNT)
    {
        g_fmrdo.normal_repeat_step_count++;
        StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_up_timer);
    }
    else
    {
        StartTimer(FMRDO_REPEAT_STEP_TIMER, FAST_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_up_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_is_stepping_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_fmrdo_is_stepping_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_fmrdo.is_ready && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP && g_fmrdo.is_button_down);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_is_stepping_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_fmrdo_is_stepping_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_fmrdo.is_ready && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN && g_fmrdo.is_button_down);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_freq_from_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_str       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_fmrdo_get_freq_from_str(UI_string_type input_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = 0;
    BOOL fraction = FALSE;
    BOOL skip = FALSE;
    BOOL one_digit_dicimal = TRUE;
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; input_str[i] != 0; i++)
    {
        if (input_str[i] == L'.')
        {
            if ((input_str[i + 1] != 0) && (input_str[i + 2] != 0))
            {
                one_digit_dicimal = FALSE;
            }
            fraction = TRUE;
        }
        else if (!skip)
        {
            freq = freq * 10 + input_str[i] - L'0';
            if (fraction)
            {
                skip = TRUE;
            }
        }
    }

    if (freq != 0 && !skip)
    {
        freq *= 10;
    }

    if (!one_digit_dicimal)
    {
        freq = 0xffff;  /* Only allow one digit after the '.' */
    }

    return freq;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_index       [IN]        
 *  freq                [IN]        
 *  name                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_channel(S16 channel_index, U16 freq, UI_string_type name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_fmrdo.channel_index == channel_index) && (g_fmrdo.channel_list.freq[g_fmrdo.channel_index] != freq))
    {
        g_fmrdo.channel_index = -1;
    }

    if ((g_fmrdo.channel_index == -1) && (freq == g_fmrdo.frequency))
    {
        g_fmrdo.channel_index = channel_index;
    }

    mmi_ucs2cpy((S8*) g_fmrdo.channel_list.name[channel_index], (S8*) name);

    g_fmrdo.channel_list.freq[channel_index] = freq;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_fmrdo_get_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_ready)
    {
        ReadValue(NVRAM_FMRDO_VOLUME, &g_fmrdo.volume, DS_BYTE, &error);
    }

    return g_fmrdo.volume;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.volume = volume;
    WriteValue(NVRAM_FMRDO_VOLUME, &g_fmrdo.volume, DS_BYTE, &error);

    if (g_fmrdo.is_ready && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE && g_fmrdo.state != FMRDO_STATE_SEARCH_ALL)
    {
        mdi_audio_set_volume(AUD_VOLUME_FMR, volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_write_settings_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_write_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_FMRDO_BACKGROUND_PLAY, &g_fmrdo.is_background_play, DS_BYTE, &error);
    WriteValue(NVRAM_FMRDO_SKIN, &g_fmrdo.skin_index, DS_BYTE, &error);

#if defined(__MMI_FM_RADIO_RECORD__)
    WriteValue(NVRAM_FMRDO_RECORD_FORMAT, &g_fmrdo.rec.format, DS_BYTE, &error);
    WriteValue(NVRAM_FMRDO_RECORD_QUALITY, &g_fmrdo.rec.quality, DS_BYTE, &error);
    WriteValue(NVRAM_FMRDO_RECORD_STORAGE, &g_fmrdo.rec.drive, DS_BYTE, &error);
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    WriteValue(NVRAM_FMRDO_SPEAKER_STATUS, &g_fmrdo.loud_speaker_on, DS_BYTE, &error);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.volume < MAX_VOL_LEVEL - 1)
    {
        mmi_fmrdo_set_volume(++g_fmrdo.volume);
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_volume();
        }
    #ifdef __MMI_FM_RADIO_ON_SUBLCD__
        if(g_fmrdo.in_subLCD_main_screen) 
        {
             UI_set_sub_LCD_graphics_context();
             mmi_fmrdo_redraw_main_volume(); 
             UI_set_main_LCD_graphics_context();
        }
    #endif /*__MMI_FM_RADIO_ON_SUBLCD__*/
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.volume > 0)
    {
        mmi_fmrdo_set_volume(--g_fmrdo.volume);
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_volume();
        }
    #ifdef __MMI_FM_RADIO_ON_SUBLCD__
        if(g_fmrdo.in_subLCD_main_screen)
        {
             UI_set_sub_LCD_graphics_context();
             mmi_fmrdo_redraw_main_volume();
             UI_set_main_LCD_graphics_context();
        }
    #endif /*__MMI_FM_RADIO_ON_SUBLCD__*/
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(1, FALSE);
    mmi_fmrdo_inc_volume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(0, FALSE);
    mmi_fmrdo_dec_volume();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(1, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(0, TRUE);
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__
    if (FMR_IsChipValid())
#endif 
        SetHiliteHandler(MENU_ID_FMRDO_MAIN, mmi_fmrdo_highlight_menu);
    g_fmrdo.is_subLCD_shown = FALSE;

#if defined(__MMI_FM_RADIO_RECORD__)
    SetHiliteHandler(MENU_ID_FMRDO_EDIT_FILENAME_SAVE, mmi_fmrdo_highlight_record_save_file);
    SetHiliteHandler(MENU_ID_FMRDO_EDIT_FILENAME_INPUT_METHOD, mmi_fmrdo_highlight_record_input_method);
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
#ifdef __MMI_FM_RADIO_ON_SUBLCD__   
    SetHiliteHandler(MENU_ID_SUB_FMRADIO, mmi_fmrdo_sub_highlight_menu);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_stop_audply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_stop_audply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_play_activated())
    {
        DisplayConfirm(
               STR_GLOBAL_YES,
               IMG_GLOBAL_YES,
               STR_GLOBAL_NO,
               IMG_GLOBAL_NO,
               get_string(STR_ID_FMRDO_STOP_AUDIO_PLAYER),
               IMG_GLOBAL_QUESTION,
               WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_fmrdo_run_app, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
#endif
    {
        mmi_fmrdo_run_app();
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_run_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_run_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_FM_RADIO_BIND_EARPHONE_SUBLCD__
    if (!isEarphonePlugged && IsSubLCDInMasterMode())                          
    {   
        ExecSubLCDCurrExitHandler();        
        ClearAllKeyHandler();
        ShowCategory311Screen(            
            (PU8) GetString(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE),
            IMG_GLOBAL_L1,
            NULL);
        StartTimer(POPUP_SUBLCD, NORMAL_TIMER_FOR_GOBACKSUBLCD,GoBackSubLCDHistory);
        return ;
        
    } 
    #endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
#ifdef __MMI_AUDIO_PLAYER__
    mmi_audply_stop_playing();
#endif 

    if (!g_fmrdo.is_ready)
    {
        S16 error;

        /* read channel list from nvram */
        ReadRecord(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE, &error);

        if(g_fmrdo.channel_list.name[0][0] == 0xFFFF)
        {
            memset(&g_fmrdo.channel_list, 0, sizeof(mmi_fmrdo_channel_list_struct));
        }

        /* read settings from nvram */
        ReadValue(NVRAM_FMRDO_BACKGROUND_PLAY, &g_fmrdo.is_background_play, DS_BYTE, &error);
#ifdef __MMI_FM_SLIM_SKIN__
        g_fmrdo.skin_index = 0; /* only 1 skin in silm skin version */
#else
        ReadValue(NVRAM_FMRDO_SKIN, &g_fmrdo.skin_index, DS_BYTE, &error);
#endif /* #ifdef __MMI_FM_SLIM_SKIN__ */
        ReadValue(NVRAM_FMRDO_VOLUME, &g_fmrdo.volume, DS_BYTE, &error);
    #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
        ReadValue(NVRAM_FMRDO_SPEAKER_STATUS, &g_fmrdo.loud_speaker_on, DS_BYTE, &error);
        if(g_fmrdo.loud_speaker_on != 0 && g_fmrdo.loud_speaker_on != 1)
        {
            g_fmrdo.loud_speaker_on = 1;
            WriteValue(NVRAM_FMRDO_SPEAKER_STATUS, &g_fmrdo.loud_speaker_on, DS_BYTE, &error);
        }
    #endif
    #if defined(__MMI_FM_RADIO_RECORD__)
        ReadValue(NVRAM_FMRDO_RECORD_FORMAT, &g_fmrdo.rec.format, DS_BYTE, &error);
        ReadValue(NVRAM_FMRDO_RECORD_QUALITY, &g_fmrdo.rec.quality, DS_BYTE, &error);
        ReadValue(NVRAM_FMRDO_RECORD_STORAGE, &g_fmrdo.rec.drive, DS_BYTE, &error);
        if (g_fmrdo.rec.format >= FM_REC_FORMAT_NUM)
        {
            g_fmrdo.rec.format = 0;
        }
        if (g_fmrdo.rec.quality >= NO_OF_QUALITY)
        {
            g_fmrdo.rec.quality = FM_QUALITY_LOW;
        }
        /* Restore to default drive if hardware not exists */
    #if defined(__MMI_FMGR_APP_STORAGE__)
        if ( FS_GetDevStatus(g_fmrdo.rec.drive, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    #endif
        {
             g_fmrdo.rec.drive = (U8)MMI_PUBLIC_DRV;
        }
        
    #endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

        ReadValue(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT, &error);
        /* default frequency value */
        if(g_fmrdo.frequency > MAX_FM_FREQUENCY || g_fmrdo.frequency < MIN_FM_FREQUENCY)
        {
            g_fmrdo.frequency = DEFAULT_FREQUENCY;
        }


        /* reset channel index */
        g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);

        /* search & power states */
        g_fmrdo.is_search_on = FALSE;
        g_fmrdo.is_power_on = FALSE;

        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued);

        g_fmrdo.is_ready = TRUE;
    }
/* 2009.08.13 moved by hongzhe.liu + */
#if 0 
    /* power on */
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (isEarphonePlugged)
#endif 
        mmi_fmrdo_power_on(TRUE);
#endif
/* 2009.08.13 moved by hongzhe.liu - */
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
   if( IsSubLCDInMasterMode())
   {
  	  return;
   }
#endif

    mmi_fmrdo_entry_main();

/* 2009.08.13 move to here by hongzhe.liu + */
    /* power on */
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (isEarphonePlugged)
#endif 
        mmi_fmrdo_power_on(TRUE);
/* 2009.08.13 move to here by hongzhe.liu - */

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (!isEarphonePlugged)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE),
            IMG_GLOBAL_WARNING,
            1,
            2000,
            (U8) WARNING_TONE);
    }
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_highlight_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_highlight_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_fmrdo_stop_audply, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_fmrdo_stop_audply, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_match_channel_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  frequency       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_fmrdo_match_channel_list(U16 frequency)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* try matching current frequency first */
    if (g_fmrdo.channel_index >= 0 && g_fmrdo.channel_list.freq[g_fmrdo.channel_index] == frequency)
    {
        return g_fmrdo.channel_index;
    }

    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
        if (g_fmrdo.channel_list.freq[i] == frequency)
        {
            return i;
        }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_step_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_step_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_STEP_DOWN;
    g_fmrdo.is_button_down = TRUE;
    g_fmrdo.normal_repeat_step_count = 0;

    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

    mmi_fmrdo_search_frequency_stop();

    g_fmrdo.step_freq = g_fmrdo.frequency;
    StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_down_timer);

    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_step_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_step_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;

#if 0 /*alex.xie*/
    BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);
#else
    BOOL is_freq_changed =0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)
    {
        StopTimer(FMRDO_REPEAT_STEP_TIMER);

        g_fmrdo.is_button_down = FALSE;

        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

        if (is_freq_changed)
        {
            freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
        }
        else
        {
            /* frequency is not changed during button press down so we need to decrease it */
           #if 1 /*alex.xie*/
				if(!g_fmrdo.is_search_on)
				{
		             if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
		            {
		                freq = g_fmrdo.frequency - 1;
		            }
		            else
		            {
		                freq = MAX_FM_FREQUENCY;
		            }
				}
			else
			{
					S16 channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);

#if defined(NOKE_DEBUG)
			noke_dbg_printf("xiexiegang channel_index:%d,g_fmrdo.frequency:%d\n",channel_index,g_fmrdo.frequency);
#endif				
					if(channel_index >= 0)
					{
						if(channel_index == 0)
							freq = g_fmrdo.channel_list.freq[FM_RADIO_CHANNEL_NUM-1];
						else
							freq = g_fmrdo.channel_list.freq[channel_index-1];
					}
					else
					{
						  if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
			            {
			                freq = g_fmrdo.frequency - 1;
			            }
			            else
			            {
			                freq = MAX_FM_FREQUENCY;
			            }
					}
				}
			#endif		
        }
if(setfmmute)//UNI@bw_20070420  单步搜索无声问题//ghw111
	{
		mdi_fmr_mute(0);	
		setfmmute=FALSE;
	}	
        if (g_fmrdo.is_power_on && g_fmrdo.is_search_on)
        {
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_ID_FMRDO_SEARCHING));     /* show searching text */
            mmi_fmrdo_search_frequency_start(freq, FALSE);  /* do search in non-blocking mode */
        }
        else
        {
            mmi_fmrdo_set_frequency(freq);
        }

        g_fmrdo.normal_repeat_step_count = 0;
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_step_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_step_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_STEP_UP;
    g_fmrdo.is_button_down = TRUE;
    g_fmrdo.normal_repeat_step_count = 0;

    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

    mmi_fmrdo_search_frequency_stop();

    g_fmrdo.step_freq = g_fmrdo.frequency;
    StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_up_timer);

    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_step_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_step_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
#if 0 /*alex.xie*/
    BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);
#else
    BOOL is_freq_changed =0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)
    {
        StopTimer(FMRDO_REPEAT_STEP_TIMER);

        g_fmrdo.is_button_down = FALSE;

        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

        if (is_freq_changed)
        {
            freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to increase it again */
        }
        else
        {
            /* frequency is not changed during button press down so we need to increase it */
           #if 1 /*alex.xie*/
				 if(!g_fmrdo.is_search_on)
				 {
		            if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
		            {
		                freq = g_fmrdo.frequency + 1;
		            }
		            else
		            {
		                freq = MIN_FM_FREQUENCY;
		            }
				 }
			else
				{
					S16 channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);
#if defined(NOKE_DEBUG)
			noke_dbg_printf("xiexiegang channel_index:%d,g_fmrdo.frequency:%d\n",channel_index,g_fmrdo.frequency);
#endif			
					if(channel_index >= 0)
					{
						if(channel_index == FM_RADIO_CHANNEL_NUM - 1)
							freq = g_fmrdo.channel_list.freq[0];
						else
							freq = g_fmrdo.channel_list.freq[channel_index+1];
					}
					else
					{
						 if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
			            {
			                freq = g_fmrdo.frequency + 1;
			            }
			            else
			            {
			                freq = MIN_FM_FREQUENCY;
			            }
					}
				}
			#endif

        }

		
	if(setfmmute)//UNI@bw_20070420  单步搜索无声问题//ghw111
	{
		mdi_fmr_mute(0);	
		setfmmute=FALSE;
	}	

        if (g_fmrdo.is_power_on && g_fmrdo.is_search_on)
        {
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_ID_FMRDO_SEARCHING));     /* show searching text */
            mmi_fmrdo_search_frequency_start(freq, TRUE);   /* do search in non-blocking mode */
        }
        else
        {
            mmi_fmrdo_set_frequency(freq);
        }

        g_fmrdo.normal_repeat_step_count = 0;
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_search_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_search_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_SEARCH;
    g_fmrdo.is_button_down = TRUE;

    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_search_on, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_search_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_search_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH)
    {
        g_fmrdo.is_button_down = FALSE;
        g_fmrdo.is_search_on = !g_fmrdo.is_search_on;

        mmi_fmrdo_redraw_main_toggle_button(
            g_fmrdo.selected_button,
            g_fmrdo.is_button_down,
            g_fmrdo.is_search_on,
            TRUE);

        /* stop if it's searching */
        mmi_fmrdo_search_frequency_stop();

        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_power_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_power_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\nHuyanwei Debug : mmi_fmrdo_press_power_button() Failed !!!\r\n");
#endif
        return;
    }

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (!isEarphonePlugged)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE),
            IMG_GLOBAL_WARNING,
            1,
            2000,
            (U8) WARNING_TONE);
        return;
    }
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
    g_fmrdo.selected_button = FMRDO_BUTTON_POWER;
    g_fmrdo.is_button_down = TRUE;

    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_power_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_power_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
    {
        g_fmrdo.is_button_down = FALSE;

        /* stop if it's searching */
        mmi_fmrdo_search_frequency_stop();

        /* power off if it's on */
        mmi_fmrdo_power_on((BOOL) ! g_fmrdo.is_power_on);

        mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);

        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_root
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param_p     [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_fmrdo_exit_root(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_background_play)
    {
        mmi_fmrdo_power_on(FALSE);
    }

    /* Keep frequency after exit FM radio */
    WriteValue(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT, &error);
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_register_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_fmrdo_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 
void mmi_fmrdo_main_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number_keys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9};
    const mmi_fmrdo_skin_struct *skin_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*button_press_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
            mmi_fmrdo_press_power_button,       /* FMRDO_BUTTON_POWER */
            mmi_fmrdo_press_search_button,      /* FMRDO_BUTTON_SEARCH */
            mmi_fmrdo_press_step_up_button,     /* FMRDO_BUTTON_STEP_UP */
            mmi_fmrdo_press_step_down_button    /* FMRDO_BUTTON_STEP_DOWN */
    };
    void (*button_release_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
            mmi_fmrdo_release_power_button,     /* FMRDO_BUTTON_POWER */
            mmi_fmrdo_release_search_button,    /* FMRDO_BUTTON_SEARCH */
            mmi_fmrdo_release_step_up_button,   /* FMRDO_BUTTON_STEP_UP */
            mmi_fmrdo_release_step_down_button  /* FMRDO_BUTTON_STEP_DOWN */
    };

    /* associate button press, release handlers with skin settings and register arrow key handlers */
    skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];
    SetKeyHandler(button_release_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_press_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_dummy_function, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);

    /* register number key handlers */
    SetGroupKeyHandler(mmi_fmrdo_release_number_key, number_keys, 9, KEY_EVENT_UP);
    SetGroupKeyHandler(mmi_fmrdo_long_press_number_key, number_keys, 9, KEY_LONG_PRESS);

    /* register LSK, RSK hanlders */
    SetKeyHandler(mmi_fmrdo_entry_main_option, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmrdo_entry_main_option, KEY_ENTER, KEY_EVENT_UP);//shaokai add it.
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_press_volume_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_press_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_release_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmrdo_release_volume_down, KEY_VOL_DOWN, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __MMI_TOUCH_SCREEN__ */
    /* MTK Leo add 20050301, add touch screen support for FM Radio */
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_fmrdo_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_fmrdo_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_fmrdo_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* MTK Leo end */

    /* register FM record key handler */
#if defined(__MMI_FM_RADIO_RECORD__)
    //SetKeyHandler(mmi_fmrdo_release_record_button, KEY_ENTER, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmrdo_release_record_button, KEY_STAR, KEY_EVENT_UP);
#endif 

}


int InFMScreen = 0;
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InFMScreen = 1 ;
	
    EntryNewScreen(SCR_ID_FMRDO_MAIN, mmi_fmrdo_exit_main, mmi_fmrdo_entry_main, MMI_FULL_SCREEN);

    entry_full_screen();

    g_fmrdo.in_main_screen = TRUE;

    /* button state */
    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    g_fmrdo.is_button_down = FALSE;
    g_fmrdo.normal_repeat_step_count = 0;
    g_fmrdo.is_long_press_number_key = FALSE;
    g_fmrdo.twinkle_frequency_count = 0;

    /* draw main screen */
    mmi_fmrdo_show_main(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, g_fmrdo.skin_index);

    /* Register all key handler */
    mmi_fmrdo_main_register_keys();

    SetDelScrnIDCallbackHandler(SCR_ID_FMRDO_MAIN, (HistoryDelCBPtr) mmi_fmrdo_exit_root);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.in_main_screen = FALSE;

    /* stop timer and update frequency if we don't release step up/down button yet */
    StopTimer(FMRDO_REPEAT_STEP_TIMER);
    StopTimer(FMRDO_TWINKLE_FREQUENCY_TIMER);
    if (g_fmrdo.normal_repeat_step_count != 0)
    {
        mmi_fmrdo_set_frequency(g_fmrdo.step_freq);
    }

    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(FALSE);

    /* stop if it's searching */
    mmi_fmrdo_search_frequency_stop();

#if defined(__MMI_FM_RADIO_RECORD__)
    /* Abort due to exit screen */
    g_fmrdo.rec.user_abort = FALSE;
    mmi_fmrdo_stop_record_on_exit();
    mmi_fmrdo_util_stop_duration();
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    InFMScreen = 0 ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_main_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[10];
    U16 item_icons[10];
    U16 item_count, i;
    U8 *gui_buffer;
    U8 *item_popups[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_MAIN_OPTION, mmi_fmrdo_exit_main_option, mmi_fmrdo_entry_main_option, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_MAIN_OPTION);
    item_count = GetNumOfChild(MENU_ID_FMRDO_MAIN_OPTION);
    GetSequenceStringIds(MENU_ID_FMRDO_MAIN_OPTION, item_texts);
    GetSequenceImageIds(MENU_ID_FMRDO_MAIN_OPTION, item_icons);
    SetParentHandler(MENU_ID_FMRDO_MAIN_OPTION);
    RegisterHighlightHandler(mmi_fmrdo_main_option_highlight_hdlr);

    for (i = 0; i < item_count; i++)
    {
        item_popups[i] = NULL;
    }

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        item_count,
        item_texts,
        item_icons,
        (U8 **) item_popups,
        0,
        0,
        gui_buffer);

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_main_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_fmrdo_main_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_main_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_main_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_option_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_main_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_option_highlighted_item_text = (U16) GetSeqItemStringId((U16) MENU_ID_FMRDO_MAIN_OPTION, (U16) index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_main_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (main_option_highlighted_item_text)
    {
        case STR_ID_FMRDO_CHANNEL_LIST:
            mmi_fmrdo_entry_channel_list();
            break;
        case STR_ID_FMRDO_MANUAL_INPUT:
            mmi_fmrdo_entry_manual_input();
            break;
        case STR_ID_FMRDO_PRESET_AUTO_SEARCH:
            mmi_fmrdo_entry_preset_list_confirm();
            break;
        case STR_ID_FMRDO_SETTINGS:
            mmi_fmrdo_entry_settings();
            break;
    #if defined(__MMI_FM_RADIO_RECORD__)
        case STR_ID_FMRDO_RECORD:
            mmi_fmrdo_release_record_button();
            break;
        case STR_ID_FMRDO_APPEND:
            mmi_fmrdo_release_append_button();
            break;
        case STR_ID_FMRDO_FILE_LIST:
            mmi_fmrdo_entry_record_list();
            break;
    #endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_fmrdo_channel_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* show frequency text */
    U16 freq = g_fmrdo.channel_list.freq[item_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (freq == 0)
    {
        mmi_ucs2cpy((S8*) str_buff, GetString(STR_ID_FMRDO_EMPTY));
    }
    else
    {
        kal_wsprintf(str_buff, "FM %d.%d", freq / 10, freq % 10);
    }

    /* show order icon */
    *img_buff_p = (PU8) GetImage((U16) (IMG_GLOBAL_L1 + item_index));

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_item_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_fmrdo_channel_list_item_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = g_fmrdo.channel_list.freq[item_index];
    UI_string_type name = g_fmrdo.channel_list.name[item_index];
    U16 name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (freq == 0 || (name_len = (U16) mmi_ucs2strlen((const S8*)name)) == 0)
    {
        return 0;
    }
    mmi_ucs2cpy((S8*) hint_array[0], (S8*) name);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_CHANNEL_LIST, mmi_fmrdo_exit_channel_list, mmi_fmrdo_entry_channel_list, NULL);

    /* register highligh handler */
    RegisterHighlightHandler(mmi_fmrdo_channel_list_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_CHANNEL_LIST);
    if (g_fmrdo.channel_index >= 0)
    {
        highlighted_item = g_fmrdo.channel_index;
    }
    else
    {
        highlighted_item = 0;
    }

    ShowCategory184Screen(
        STR_ID_FMRDO_CHANNEL_LIST,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),    /* title text and icon */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,                 /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        FM_RADIO_CHANNEL_NUM,
        mmi_fmrdo_channel_list_item,
        mmi_fmrdo_channel_list_item_hint,
        highlighted_item,
        gui_buffer);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_fmrdo_entry_channel_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left right arrow key handler */
    SetKeyHandler(mmi_fmrdo_entry_channel_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_channel_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_list_highlighted_item_index = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_manual_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_FMRDO_MANUAL_INPUT, mmi_fmrdo_exit_manual_input, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FMRDO_MANUAL_INPUT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_FMRDO_MANUAL_INPUT, &inputBufferSize);

    RegisterHighlightHandler(mmi_fmrdo_manual_input_highlight_hdlr);

    if (guiBuffer == NULL)
    {
        kal_wsprintf(manual_input_buffer, "%d.%d", g_fmrdo.frequency / 10, g_fmrdo.frequency % 10);
    }

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[0],
        (U8*) manual_input_buffer,
        MAX_MANUAL_INPUT_LEN,
        INPUT_TYPE_DECIMAL_NUMERIC);
    LeftJustifyInlineItem(&wgui_inline_items[0]);
    SetInlineItemFullWidth(&wgui_inline_items[0]);
    EnableInlineItemBoundary(&wgui_inline_items[0]);

    DisableCategory57ScreenDone();

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_FMRDO_MANUAL_INPUT,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        1,
        0,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_fmrdo_manual_input_LSK);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_manual_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_FMRDO_MANUAL_INPUT;
    h.entryFuncPtr = mmi_fmrdo_entry_manual_input;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_manual_input_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_manual_input_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_manual_input_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_manual_input_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* calculate frequency number */
    U16 freq = mmi_fmrdo_get_freq_from_str(manual_input_buffer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check frequency input */
    if (freq == 0xffff) /* invalid decimal digit */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMRDO_VALID_FM_DECIMAL),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) WARNING_TONE);
    }
    else if (freq < MIN_FM_FREQUENCY || freq > MAX_FM_FREQUENCY)        /* warning invalid frequency */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMRDO_VALID_FM_BANDWIDTH),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) WARNING_TONE);
    }
    else
    {
        mmi_fmrdo_set_frequency(freq);
        GoBackToHistory(SCR_ID_FMRDO_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_preset_list_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_preset_list_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_FMRDO_PRESET_LIST_CONFIRM, mmi_fmrdo_exit_preset_list_confirm, NULL, NULL);

    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_FMRDO_PRESET_LIST,
        IMG_GLOBAL_QUESTION,
        NULL);

    playRequestedTone(WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_fmrdo_preset_list_confirm_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_preset_list_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_preset_list_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_preset_list_confirm_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_preset_list_confirm_LSK(void)
{
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isEarphonePlugged && !g_fmrdo.is_power_on)
#else /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
    if (!g_fmrdo.is_power_on)
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
        mmi_fmrdo_power_on_before_preset_auto_search();

    if (g_fmrdo.is_power_on)    /* if audio is block, power won't be turned on */
    {
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
        if(IsSubLCDInMasterMode())
        {
            mmi_fmrdo_sub_entry_search_key_handler();
        }
        else
        #endif
        mmi_fmrdo_entry_searching();

        /* start search all channels */
        mmi_fmrdo_search_all_channels_start(mmi_fmrdo_preset_list_done);
    }
    else
    {
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
        if(IsSubLCDInMasterMode())  
        {   
            ClearAllKeyHandler();
        #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
            ShowCategory311Screen(            
            (PU8) GetString(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE),
            IMG_GLOBAL_L1,
            NULL);
        #else
            ShowCategory311Screen(            
            (PU8) GetString(STR_ID_FMRDO_POWER_ON_FIRST),
            IMG_GLOBAL_L1,
            NULL);
        #endif /*__MMI_FM_RADIO_BIND_EARPHONE__*/
        
            StartTimer(POPUP_SUBLCD, NORMAL_TIMER_FOR_GOBACKSUBLCD,GoBackSubLCDHistory);
        }
        else 
        #endif /*__MMI_FM_RADIO_ON_SUBLCD__*/ 
        {
        #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
            DisplayPopup((U8*) GetString(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE), IMG_GLOBAL_WARNING, 1, 1000, (U8) WARNING_TONE);
        #else
            DisplayPopup((U8*) GetString(STR_ID_FMRDO_POWER_ON_FIRST), IMG_GLOBAL_WARNING, 1, 1000, (U8) WARNING_TONE);
        #endif /*__MMI_FM_RADIO_BIND_EARPHONE__*/
            DeleteUptoScrID(SCR_ID_FMRDO_MAIN_OPTION);
        }
       
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 inline_count = 0;
#if defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FMGR_APP_STORAGE__)
    U32 *drive_name_p;
    U8 no_of_storage;    
#endif    
    MMI_ID_TYPE item_icons[] = 
    {
        IMG_ID_FMRDO_BACKGROUND_PLAY,
        0
    #ifndef __MMI_FM_SLIM_SKIN__
        ,
        IMG_ID_FMRDO_SKIN,
        0
    #endif        
    #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
        ,
        IMG_ID_FMRDO_LOUDSPEAK,
        0
    #endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */
    #if defined(__MMI_FM_RADIO_RECORD__)
        ,
        IMG_ID_FMRDO_RECORD_FORMAT,
        0,
        IMG_ID_FMRDO_RECORD_QUALITY,
        0
    #if defined(__MMI_FMGR_APP_STORAGE__)
        ,
        IMG_ID_FMRDO_RECORD_STORAGE,
        0
    #endif        
    #endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_FMRDO_SETTINGS, mmi_fmrdo_exit_settings, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FMRDO_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_FMRDO_SETTINGS, &inputBufferSize);

    RegisterHighlightHandler(mmi_fmrdo_settings_highlight_hdlr);

    if (guiBuffer == NULL)
    {
        selected_background_play = g_fmrdo.is_background_play;
        selected_skin_index = g_fmrdo.skin_index;
    #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
        selected_speaker_status = g_fmrdo.loud_speaker_on;
    #endif
    #if defined(__MMI_FM_RADIO_RECORD__)
        selected_record_format = g_fmrdo.rec.format;
        selected_record_quality = g_fmrdo.rec.quality;
    #endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
    }

    /* background play label */
    SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[inline_count++], (U8*) GetString(STR_ID_FMRDO_BACKGROUND_PLAY));

    /* background play select */
    background_play_texts[0] = (UI_string_type) GetString(STR_GLOBAL_OFF);
    background_play_texts[1] = (UI_string_type) GetString(STR_GLOBAL_ON);
    SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[inline_count++],
        2,
        (U8 **) background_play_texts,
        &selected_background_play);

#ifndef __MMI_FM_SLIM_SKIN__
    /* skin label */
    SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[inline_count++], (U8*) GetString(STR_ID_FMRDO_SKIN));

    /* skin select */
    skin_texts[0] = (UI_string_type) GetString(STR_ID_FMRDO_SKIN_1);
    skin_texts[1] = (UI_string_type) GetString(STR_ID_FMRDO_SKIN_2);
    skin_texts[2] = (UI_string_type) GetString(STR_ID_FMRDO_SKIN_3);
    SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[inline_count++], 3, (U8 **) skin_texts, &selected_skin_index);
#endif /*#ifndef __MMI_FM_SLIM_SKIN__*/

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    /* loud speaker caption */
    SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[inline_count++], (U8*) GetString(STR_ID_FMRDO_LOUD_SPEAKER));

    /* loud speaker select */
    speaker_status_texts[0] = (UI_string_type) GetString(STR_GLOBAL_OFF);
    speaker_status_texts[1] = (UI_string_type) GetString(STR_GLOBAL_ON);
    SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[inline_count++], 2, (U8 **) speaker_status_texts, &selected_speaker_status);
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */

#if defined(__MMI_FM_RADIO_RECORD__)
#if defined(__USB_IN_NORMAL_MODE__)
    /* Do not show record setting when in USB mode */
    if (!mmi_usb_is_in_mass_storage_mode())
#endif /* defined(__USB_IN_NORMAL_MODE__) */     
    {
        /* record format label */
        SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(&wgui_inline_items[inline_count++], (U8*) GetString(STR_ID_FMRDO_RECORD_FORMAT));

        /* record format select */
        record_format_texts[FM_FORMAT_AMR] = (UI_string_type) GetString(STR_ID_FMRDO_FORMAT_AMR);
        record_format_texts[FM_FORMAT_WAV] = (UI_string_type) GetString(STR_ID_FMRDO_FORMAT_WAV);
    #if defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
    	record_format_texts[FM_FORMAT_AWB] = (UI_string_type) GetString( STR_ID_FMRDO_FORMAT_AWB );
    #endif
        SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[inline_count++], FM_REC_FORMAT_NUM, (U8 **) record_format_texts, &selected_record_format);

        /*record quality label*/
        SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(&wgui_inline_items[inline_count++], (U8*) GetString(STR_ID_FMRDO_RECORD_QUALITY));
        record_quality_texts[FM_QUALITY_LOW] = (UI_string_type) GetString(STR_ID_FMRDO_RECORD_QUALITY_LOW);
        record_quality_texts[FM_QUALITY_HIGH] = (UI_string_type) GetString(STR_ID_FMRDO_RECORD_QUALITY_HIGH);
        SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[inline_count++], NO_OF_QUALITY, (U8 **) record_quality_texts, &selected_record_quality);
        
    #if defined(__MMI_FMGR_APP_STORAGE__)

        /* Find storage highlight item in inline editor */
        if(guiBuffer == NULL)
        {
            mmi_fmgr_get_full_storage_inline_list(g_fmrdo.rec.drive, &no_of_storage, (U32*)&drive_name_p, (U8*)&selected_record_storage);
        }
        else
        {
            mmi_fmgr_get_full_storage_inline_list(0, &no_of_storage, (U32*)&drive_name_p, NULL);
        }

        /* record storage label */
        SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(&wgui_inline_items[inline_count++], (U8*) GetString(STR_ID_FMRDO_RECORD_STORAGE));

        /* record storage select */
        SetInlineItemActivation(&wgui_inline_items[inline_count], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[inline_count++],
            no_of_storage,
            (U8 **) drive_name_p,
            &selected_record_storage);
    #endif /*__MMI_FMGR_APP_STORAGE__*/

    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    DisableCategory57ScreenDone();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, inline_count, inputBuffer);
    }

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_FMRDO_SETTINGS,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        inline_count,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_fmrdo_settings_LSK);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    /* register volume inc, dec handlers */
//    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
//    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_FMRDO_SETTINGS;
    h.entryFuncPtr = mmi_fmrdo_entry_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_settings_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_fmrdo_settings_LSK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_settings_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_settings_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL skin_changed = (g_fmrdo.skin_index != selected_skin_index);
    S8 drv_letter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_RECORD__)
#if defined(__MMI_FMGR_APP_STORAGE__)
#if defined(__USB_IN_NORMAL_MODE__)
    /* Use original setting in USB mode because we hide the setting */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        drv_letter = g_fmrdo.rec.drive;
    }
    else
#endif /* defined(__USB_IN_NORMAL_MODE__) */
    {
        mmi_fmgr_get_drive_letter_by_inline_index((U8)selected_record_storage, &drv_letter);
    }
#else
    drv_letter = (U8)MMI_PUBLIC_DRV;
#endif
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    g_fmrdo.is_background_play = selected_background_play;
    g_fmrdo.skin_index = (unsigned char)selected_skin_index;

#if defined(__MMI_FM_RADIO_RECORD__)
    g_fmrdo.rec.format = selected_record_format;
    g_fmrdo.rec.quality = selected_record_quality;
    g_fmrdo.rec.drive = drv_letter;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    if(g_fmrdo.loud_speaker_on != selected_speaker_status)
    {
        g_fmrdo.loud_speaker_on = selected_speaker_status;

        /* Turn off then turn on to switch output path */
        if(g_fmrdo.is_power_on)
        {
            mmi_fmrdo_power_on(FALSE);
            mmi_fmrdo_power_on(TRUE);            
        }
    }
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */

    mmi_fmrdo_write_settings_to_nvram();

    if (skin_changed)
    {
        GoBackToHistory(SCR_ID_FMRDO_MAIN);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_empty_channel = (g_fmrdo.channel_list.freq[channel_list_highlighted_item_index] == 0);
    U16 item_texts[] = {STR_ID_FMRDO_PLAY, STR_GLOBAL_DELETE, STR_ID_FMRDO_EDIT};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2, IMG_GLOBAL_L3};
    U8 *gui_buffer;
    U8 *item_popups[] = {NULL, NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_FMRDO_CHANNEL_OPTION, mmi_fmrdo_exit_channel_option, NULL, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_CHANNEL_OPTION);
    RegisterHighlightHandler(mmi_fmrdo_channel_option_highlight_hdlr);

    if (is_empty_channel)
    {
        ShowCategory52Screen(
            STR_GLOBAL_OPTIONS,
            GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            1,
            item_texts + 2,
            item_icons,
            (U8 **) item_popups,
            0,
            0,
            gui_buffer);
    }
    else
    {
        ShowCategory52Screen(
            STR_GLOBAL_OPTIONS,
            GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            3,
            item_texts,
            item_icons,
            (U8 **) item_popups,
            0,
            0,
            gui_buffer);
    }

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_channel_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_fmrdo_channel_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_channel_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_channel_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_option_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_empty_channel = (g_fmrdo.channel_list.freq[channel_list_highlighted_item_index] == 0);
    U16 item_texts[] = {STR_ID_FMRDO_PLAY, STR_GLOBAL_DELETE, STR_ID_FMRDO_EDIT};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_option_highlighted_item_text = (is_empty_channel ? item_texts[index + 2] : item_texts[index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (channel_option_highlighted_item_text)
    {
        case STR_ID_FMRDO_PLAY:
            if (!g_fmrdo.is_power_on)
            {
            #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
                if (!isEarphonePlugged)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE),
                        IMG_GLOBAL_WARNING,
                        1,
                        2000,
                        (U8) WARNING_TONE);
                    return;
                }
            #endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
                mmi_fmrdo_power_on(TRUE);
            }

            mmi_fmrdo_goto_channel(channel_list_highlighted_item_index);
            GoBackToHistory(SCR_ID_FMRDO_MAIN);
            break;
        case STR_GLOBAL_DELETE:
            mmi_fmrdo_entry_clear_channel_confirm();
            break;
        case STR_ID_FMRDO_EDIT:
            mmi_fmrdo_entry_channel_edit();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_FMRDO_SEARCHING, mmi_fmrdo_exit_searching, NULL, NULL);

    /* clear End key */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* Show searching screen */
    ShowCategory66Screen(
        STR_ID_FMRDO_PRESET_AUTO_SEARCH,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_ID_FMRDO_SEARCHING),
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_fmrdo_searching_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL)
    {
        history currHistory;

        currHistory.scrnID = SCR_ID_FMRDO_SEARCHING;
        currHistory.entryFuncPtr = mmi_fmrdo_entry_searching;
        GetCategoryHistory(currHistory.guiBuffer);
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
        AddHistory(currHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_searching_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_searching_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_search_all_channels_stop();
    #ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(IsSubLCDInMasterMode())
		GoBackSubLCDHistory();
    else
    #endif
        GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    MMI_ID_TYPE item_icons[] = 
    {
        IMG_ID_FMRDO_CHANNEL_NAME,
        0,
        IMG_ID_FMRDO_FREQUENCY,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_FMRDO_CHANNEL_EDIT, mmi_fmrdo_exit_channel_edit, NULL, NULL);

    InitializeCategory57Screen();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_FMRDO_CHANNEL_EDIT, &inputBufferSize);

    RegisterHighlightHandler(mmi_fmrdo_channel_edit_highlight_hdlr);

    if ((guiBuffer = GetCurrGuiBuffer(SCR_ID_FMRDO_CHANNEL_EDIT)) == NULL)
    {
        U16 freq = g_fmrdo.channel_list.freq[channel_list_highlighted_item_index];

        mmi_ucs2cpy(
            (S8*) name_inline_editor_buffer,
            (S8*) g_fmrdo.channel_list.name[channel_list_highlighted_item_index]);
        if (freq == 0)
        {
            freq_inline_editor_buffer[0] = 0;
        }
        else
        {
            kal_wsprintf(freq_inline_editor_buffer, "%d.%d", freq / 10, freq % 10);
        }

        channel_name_edit_done = FALSE;
    }

    /* channel name label */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_FMRDO_CHANNEL_NAME));

    /* channel name */
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[1], (U8*) name_inline_editor_buffer);

    /* frequency label */
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_FMRDO_FREQUENCY));

    /* frequency input */
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[3],
        (U8*) freq_inline_editor_buffer,
        MAX_MANUAL_INPUT_LEN,
        INPUT_TYPE_DECIMAL_NUMERIC);

    DisableInlineItemHighlight(&wgui_inline_items[3]);
//    LeftJustifyInlineItem(&wgui_inline_items[3]);
//    SetInlineItemFullWidth(&wgui_inline_items[3]);
//    EnableInlineItemBoundary(&wgui_inline_items[3]);

    DisableCategory57ScreenDone();

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_FMRDO_EDIT,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        4,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    // register volume inc, dec handlers - inline screen will register vol up and vol down key
    //SetKeyHandler( mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN );
    //SetKeyHandler( mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_channel_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_channel_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_FMRDO_CHANNEL_EDIT;
    h.entryFuncPtr = mmi_fmrdo_entry_channel_edit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_edit_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_edit_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 1) /* edit channel name */
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetCategory57LeftSoftkeyFunction(mmi_fmrdo_entry_channel_name_edit);
        if (channel_name_edit_done)
        {
            ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
            SetCategory57RightSoftkeyFunctions(mmi_fmrdo_channel_edit_LSK, mmi_fmrdo_channel_edit_LSK);
        }
        else
        {
            SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
        }
    }
    else
    {
        SetCategory57LeftSoftkeyFunction(mmi_fmrdo_channel_edit_LSK);
        SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_edit_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_edit_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* calculate frequency number */
    U16 freq = mmi_fmrdo_get_freq_from_str(freq_inline_editor_buffer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check frequency input */
    if (freq_inline_editor_buffer[0] == 0)
    {
        if (g_fmrdo.channel_list.freq[channel_list_highlighted_item_index] == 0)        /* it's empty, no need to clear it */
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_FMRDO_VALID_FM_BANDWIDTH),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME_2000,
                (U8) WARNING_TONE);
        }
        else
        {
            mmi_fmrdo_entry_clear_channel_confirm();    /* clear channel */
        }
    }
    else if (freq == 0xffff)    /* invalid decimal digit */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMRDO_VALID_FM_DECIMAL),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) WARNING_TONE);
    }
    else if (freq < MIN_FM_FREQUENCY || freq > MAX_FM_FREQUENCY)        /* warning invalid frequency */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMRDO_VALID_FM_BANDWIDTH),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) WARNING_TONE);
    }
    else
    {
        mmi_fmrdo_entry_save_channel_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_name_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_name_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_CHANNEL_NAME_EDIT, NULL, mmi_fmrdo_entry_channel_name_edit, NULL);

    if ((gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_CHANNEL_NAME_EDIT)) == NULL)
    {
        mmi_ucs2cpy((S8*) name_text_editor_buffer, (S8*) name_inline_editor_buffer);
    }

    ShowCategory5Screen(
        STR_ID_FMRDO_CHANNEL_NAME,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) name_text_editor_buffer,
        MAX_NAME_INPUT_LEN,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_fmrdo_entry_channel_name_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_name_edit_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_name_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_FMRDO_CHANNEL_NAME_EDIT_OPTION, NULL, NULL, NULL);

    RegisterHighlightHandler(mmi_fmrdo_channel_name_edit_option_highlight_hdlr);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        item_texts,
        item_icons,
        NULL,
        0,
        0,
        NULL);

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_channel_name_edit_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK handlers */
    SetLeftSoftkeyFunction(mmi_fmrdo_channel_name_edit_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_name_edit_option_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_name_edit_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_name_edit_option_highlighted_item_text = item_texts[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_name_edit_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_name_edit_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (channel_name_edit_option_highlighted_item_text)
    {
        case STR_GLOBAL_DONE:
            mmi_ucs2cpy((S8*) name_inline_editor_buffer, (S8*) name_text_editor_buffer);
            channel_name_edit_done = TRUE;
            GoBackToHistory(SCR_ID_FMRDO_CHANNEL_EDIT);
            break;
        case STR_GLOBAL_INPUT_METHOD:
            EntryInputMethodScreen();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_clear_channel_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_clear_channel_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_FMRDO_CLEAR_CHANNEL_CONFIRM,
        mmi_fmrdo_exit_clear_channel_confirm,
        mmi_fmrdo_entry_clear_channel_confirm,
        NULL);

    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_FMRDO_DELETE_ASK,
        IMG_GLOBAL_QUESTION,
        NULL);

    playRequestedTone(WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_fmrdo_clear_channel_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_clear_channel_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_clear_channel_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_clear_channel_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_clear_channel_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_set_channel(channel_list_highlighted_item_index, 0, L"");

    /* write channel list from nvram */
    WriteRecord(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE, &error);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8) SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_FMRDO_CHANNEL_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_save_channel_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_save_channel_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_FMRDO_SAVE_CHANNEL_CONFIRM,
        mmi_fmrdo_exit_save_channel_confirm,
        mmi_fmrdo_entry_save_channel_confirm,
        NULL);

    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_FMRDO_SAVE_ASK,
        IMG_GLOBAL_QUESTION,
        NULL);

    playRequestedTone(WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_fmrdo_save_channel_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_fmrdo_save_channel_RSK, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_save_channel_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_save_channel_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_save_channel_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_save_channel_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 freq = mmi_fmrdo_get_freq_from_str(freq_inline_editor_buffer);
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set channel */
    len = mmi_ucs2strlen((const S8*)name_inline_editor_buffer);
    if (len != 0)
    {
        mmi_fmrdo_set_channel(channel_list_highlighted_item_index, freq, name_inline_editor_buffer);
    }
    else
    {
        mmi_fmrdo_set_channel(channel_list_highlighted_item_index, freq, (UI_string_type) GetString(STR_ID_FMRDO_NEW_CHANNEL));
    }

    /* write channel list from nvram */
    WriteRecord(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE, &error);
    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8) SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_FMRDO_CHANNEL_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_save_channel_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_save_channel_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_FMRDO_CHANNEL_LIST);
}

#if defined(__MMI_FM_RADIO_RECORD__)
#define MMI_FMRADIO_REC


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_record_button
 * DESCRIPTION
 *  Send out the FM radio record request when release record button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_record_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /* Enter from option menu, go back to main screen and record */
    if (!g_fmrdo.in_main_screen)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        GoBackHistory();
    }
    mmi_fmrdo_search_frequency_stop();
    mmi_fmrdo_send_record_req(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_append_button
 * DESCRIPTION
 *  Select a file to append after release append button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_append_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MAX_FM_PATH_LEN];
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR);
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AWB);
#endif

    mmi_fmgr_select_path_and_enter(APP_FMRDO, FMGR_SELECT_FILE, filter, (PS8) path, mmi_fmrdo_select_file_callback);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_stop_button
 * DESCRIPTION
 *  Stop FM radio record when release stop button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_stop_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort by user */
    g_fmrdo.rec.user_abort = TRUE;
    mmi_fmrdo_stop_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_pause_button
 * DESCRIPTION
 *  Pause FM radio record when release pause button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_pause_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_pause_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_resume_button
 * DESCRIPTION
 *  Resume FM radio record when release resuem button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_resume_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_resume_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_select_file_callback
 * DESCRIPTION
 *  The callback function for file manager after select a file to append
 * PARAMETERS
 *  fullname        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_select_file_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fullname == NULL)
    {
        GoBackHistory();
    }
    else
    {
        mmi_ucs2cpy((S8*) g_fmrdo.rec.fullName, (S8*) fullname);

        GoBackToHistory(SCR_ID_FMRDO_MAIN);
        mmi_fmrdo_send_record_req(TRUE);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_send_record_req
 * DESCRIPTION
 *  Turn on the FM radio in advace and send out the record request.
 * PARAMETERS
 *  is_append       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_send_record_req(BOOL is_append)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.in_main_screen)
    {
        return;
    }

    if (g_fmrdo.is_power_on == FALSE)
    {
    #if defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        if (!isEarphonePlugged)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE),
                IMG_GLOBAL_WARNING,
                1,
                2000,
                (U8) WARNING_TONE);
            return;
        }
    #endif /* defined(__MMI_FM_RADIO_BIND_EARPHONE__) */ 

    #ifdef __MMI_BT_FM_VIA_SCO__
        /* Can not record while FM via SCO connected*/
        if(mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
        {
            DisplayPopup((PU8) GetString(STR_ID_FMRDO_RECORD_IN_BT_SCO), IMG_GLOBAL_UNFINISHED, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            return;
        }
    #endif /* __MMI_BT_FM_VIA_SCO__ */

        /* stop if it's searching */
        mmi_fmrdo_search_frequency_stop();
        mmi_fmrdo_power_on(TRUE);
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);
    }

    if (!is_append)
    {
        if (!mmi_fmrdo_util_get_new_file(g_fmrdo.rec.fullName))
        {    
            return;
        }
    }

    g_fmrdo.rec.is_append = is_append;
    g_fmrdo.rec.user_abort = FALSE;
    mmi_fmrdo_start_record(g_fmrdo.rec.fullName, g_fmrdo.rec.format, g_fmrdo.rec.quality);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_main_record_screen
 * DESCRIPTION
 *  Entry record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main_record_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, FALSE, TRUE, TRUE);
    mmi_fmrdo_change_main_SK_record();

    /* ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP); */
    ClearInputEventHandler(MMI_DEVICE_KEY);
	
    SetKeyHandler(mmi_fmrdo_release_pause_button, KEY_STAR, KEY_EVENT_UP);//shaokai add it.
    SetKeyHandler(mmi_fmrdo_release_pause_button, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmrdo_release_stop_button, KEY_RSK, KEY_EVENT_UP);


    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_main_pause_screen
 * DESCRIPTION
 *  Entry pause screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main_pause_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC_PAUSE, FALSE, TRUE, TRUE);
    mmi_fmrdo_change_main_SK_pause();

    /* ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP); */
    ClearInputEventHandler(MMI_DEVICE_KEY);
	
    SetKeyHandler(mmi_fmrdo_release_resume_button, KEY_STAR, KEY_EVENT_UP);//shaokai add it.
    SetKeyHandler(mmi_fmrdo_release_resume_button, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmrdo_release_stop_button, KEY_RSK, KEY_EVENT_UP);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_restore_main_screen
 * DESCRIPTION
 *  Restore to FM playing screen from record or pause screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_restore_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_util_stop_duration();

    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, FALSE, TRUE, FALSE);
    mmi_fmrdo_redraw_main_time_duration(FALSE);
    mmi_fmrdo_restore_main_SK();

    /* SetKeyHandler( mmi_fmrdo_release_record_button, KEY_ENTER, KEY_EVENT_UP ); */

    //SetKeyHandler( mmi_fmrdo_entry_main_option, KEY_LSK, KEY_EVENT_UP );
    //SetKeyHandler( GoBackHistory, KEY_RSK, KEY_EVENT_UP );
    mmi_fmrdo_main_register_keys();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_record_stopped_hdlr
 * DESCRIPTION
 *  Handler when stop FM record. Need to enter file name if it is not an append file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_record_stopped_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_util_stop_duration();

    /* not abort by user, exit directly */
    if (!g_fmrdo.rec.user_abort)
    {
        return;
    }

    /* No need to enter file name */
    if (g_fmrdo.rec.is_append)
    {
        mmi_fmrdo_entry_restore_main_screen();
    }
    else
    {
        filename = mmi_fmrdo_util_get_file_name(g_fmrdo.rec.fullName);
        memcpy(fmrdo_editor_buff, filename, (MAX_FM_INPUT_FILE_LEN + 2) * ENCODING_LENGTH);
        mmi_fmrdo_util_remove_file_ext(fmrdo_editor_buff);

        mmi_fmrdo_entry_edit_filename();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_edit_filename
 * DESCRIPTION
 *  Entry edit file name screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_edit_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_EDIT_FILENAME, NULL, mmi_fmrdo_entry_edit_filename, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FMRDO_EDIT_FILENAME);
    ShowCategory5Screen(
        STR_GLOBAL_FILENAME,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) fmrdo_editor_buff,
        (MAX_FM_INPUT_FILE_LEN + 1),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_fmrdo_entry_edit_filename_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_fmrdo_entry_edit_abort_query, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_edit_abort_query
 * DESCRIPTION
 *  Abort reocrd confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_edit_abort_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_FMRDO_CANCEL_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_fmrdo_abort_edit_file, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_abort_edit_file
 * DESCRIPTION
 *  Abort the record file if not enter file name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_abort_edit_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = FS_Delete(g_fmrdo.rec.fullName);
    DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME);
    if (result < 0)
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(result)),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_edit_filename_option
 * DESCRIPTION
 *  Entry edit file name option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_edit_filename_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[2];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS, NULL, mmi_fmrdo_entry_edit_filename_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS);
    nNumofItem = GetNumOfChild(MENU_ID_FMRDO_EDIT_FILENAME_OPTIONS);
    GetSequenceStringIds(MENU_ID_FMRDO_EDIT_FILENAME_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_FMRDO_EDIT_FILENAME_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(mmi_fmrdo_go_back_2_history);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_highlight_record_save_file
 * DESCRIPTION
 *  Highlight function for save file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_highlight_record_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_fmrdo_record_save_file, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_fmrdo_record_save_file, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_highlight_record_input_method
 * DESCRIPTION
 *  Highlight function for change input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_highlight_record_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_record_save_file
 * DESCRIPTION
 *  Save the recorded FM radio file according to the newly entered name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_record_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    UI_character_type fullname[MAX_FM_FULL_NAME_LEN];
    UI_character_type path[MAX_FM_PATH_LEN];
    S8 *ptr;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmrdo_editor_buff[0] == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_FMGR_EMPTY_FILENAME),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS);
        return;
    }

    ptr = mmi_fmgr_skip_space((PS8) fmrdo_editor_buff);
    len = mmi_ucs2strlen(ptr);
    if (len == 0)
    {
        DisplayPopup((PU8) GetString(STR_FMGR_EMPTY_FILENAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS);
        return;
    }
    if ((len == 1) && (ptr[0] == '.') && (ptr[1] == 0))
    {
        DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS);
        return;
    }
    while (len > 0)
    {
        len--;
        if ((ptr[len << 1] == '/' && ptr[(len << 1) + 1] == 0) || (ptr[len << 1] == '\\' && ptr[(len << 1) + 1] == 0))
        {
            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS);
            return;
        }
    }
    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);
    kal_wsprintf(fullname, "%w%w", path, ptr);
    mmi_fmrdo_util_append_file_ext(fullname, g_fmrdo.rec.format);

    result = FS_Rename(g_fmrdo.rec.fullName, fullname);

    if (result < 0)
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(result)),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_FMRDO_EDIT_FILENAME);
//        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_record_list
 * DESCRIPTION
 *  Entry file list in the folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_record_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MAX_FM_PATH_LEN];
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR);
#if defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
	FMGR_FILTER_SET(&filter, FMGR_TYPE_AWB);
#endif

    mmi_fmgr_select_path_and_enter(APP_FMRDO, FMGR_SELECT_BROWSE, filter, (PS8) path, mmi_fmrdo_browse_file_callback);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_browse_file_callback
 * DESCRIPTION
 *  Callback function for file manager after select a file from file list.
 * PARAMETERS
 *  fullname        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_browse_file_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_record_error_hdlr
 * DESCRIPTION
 *  Handle the error case for FM radio record
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_record_error_hdlr(S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cause)
    {
        case MDI_AUDIO_SUCCESS:
            GoBackHistory();
            break;
    #if defined(__DRM_SUPPORT__)
        case DRM_NOT_PERMIT_TO_APPEND:
            str_id = STR_GLOBAL_DRM_PROHIBITED;
            break;
    #endif /* defined(__DRM_SUPPORT__) */ 
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
            str_id = STR_GLOBAL_ERROR;
            break;
        case MDI_AUDIO_BAD_FORMAT:
            str_id = STR_ID_FMRDO_BAD_FORMAT;
            break;
        case MDI_AUDIO_INVALID_FORMAT:
            str_id = STR_ID_FMRDO_INVALID_FORMAT;
            break;
        case MDI_AUDIO_BUSY:
            str_id = STR_ID_FMRDO_DEVICE_BUSY;
            break;
        case MDI_AUDIO_DISC_FULL:
        case MDI_AUDIO_NO_SPACE:
            str_id = FMGR_FS_DISK_FULL_TEXT;
            break;
        case MDI_AUDIO_OPEN_FILE_FAIL:
            str_id = STR_ID_FMRDO_OPEN_FILE_ERROR;
            break;
        case MDI_AUDIO_NO_DISC:
            str_id = STR_ID_FMRDO_NO_CARD;
            break;
        case MDI_AUDIO_WRITE_PROTECTION:
            str_id = STR_ID_FMRDO_WRITE_PROTECTION_ERROR;
            break;
        case MDI_AUDIO_END_OF_FILE:
        case MDI_AUDIO_TERMINATED:
            GoBackHistory();
            break;
        case MDI_AUDIO_HFP_SCO_CONNECTED:
            str_id = STR_ID_FMRDO_RECORD_IN_BT_SCO;
            break;
        default:
            GoBackHistory();
            break;
    }

    if (str_id != 0)
    {
        DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
    }
}

#define MMI_FMRADIO_REC_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_get_storage_path
 * DESCRIPTION
 *  Get the storage drive and path according to the record setting
 * PARAMETERS
 *  path        [IN]        
 *  storage     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_get_storage_path(UI_string_type path, U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((kal_wchar*) path, "%c:\\%w", drv_letter, FMGR_DEFAULT_FOLDER_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_check_storage_folder
 * DESCRIPTION
 *  Check if the storage folder exists. if not, create it.
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmrdo_util_check_storage_folder(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        result = FS_CreateDir(path);
		if (result < 0)
        {
            if (result == FS_MEDIA_CHANGED)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_FMRDO_NO_CARD),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
            }
            else 
            {
            DisplayPopup(
                        (PU8) GetString(GetFileSystemErrorString(result)),
                        IMG_GLOBAL_ERROR,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
            }
            return FALSE;
        }
    }
    else
    {
        FS_Close(file_handle);
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_append_file_ext
 * DESCRIPTION
 *  Append the file extension according to the setting.
 * PARAMETERS
 *  filename        [IN]        
 *  format          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_append_file_ext(UI_string_type filename, U8 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (format)
    {
        case FM_FORMAT_AMR:
            mmi_ucs2ncat((S8*) filename, (S8*) FM_FILE_EXT_AMR, MAX_FM_FILE_NAME_LEN);
            break;
        case FM_FORMAT_WAV:
            mmi_ucs2ncat((S8*) filename, (S8*) FM_FILE_EXT_WAV, MAX_FM_FILE_NAME_LEN);
            break;
#if defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
         case FM_FORMAT_AWB:
            mmi_ucs2ncat((S8*)filename, (S8*)FM_FILE_EXT_AWB, MAX_FM_FILE_NAME_LEN);
break;
            #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_remove_file_ext
 * DESCRIPTION
 *  Remove file extenstion for editing file name
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_remove_file_ext(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = filename + mmi_ucs2strlen((const S8*)filename);

    while (p > filename)
    {
        if (*p == L'.')
        {
            *p = 0;
            break;
        }
        p--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_check_file_exist
 * DESCRIPTION
 *  Check if file already exists.
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmrdo_util_check_file_exist(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(filename, FS_READ_ONLY);
    if (fd >= 0)
    {
        FS_Close(fd);
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_increase_file_name
 * DESCRIPTION
 *  Change the file name by increase the number.
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_increase_file_name(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;
    U16 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = filename + mmi_ucs2strlen((const S8*)filename);
    while (p > filename)
    {
        if (*p == L'.')
        {
            file_count = (*(p - 2) - '0') * 10 + (*(p - 1) - '0');
            file_count++;
            *(p - 1) = file_count % 10 + '0';
            *(p - 2) = file_count / 10 + '0';
            break;
        }
        p--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_get_new_file
 * DESCRIPTION
 *  Get a new file name to record.
 * PARAMETERS
 *  fullname        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmrdo_util_get_new_file(UI_string_type fullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type filename[MAX_FM_FILE_NAME_LEN];
    UI_character_type path[MAX_FM_PATH_LEN];

    t_rtc rtc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);
    if (!mmi_fmrdo_util_check_storage_folder(path))
    {
        return FALSE;
    }

    RTC_GetTime(&rtc_time);
    kal_wsprintf(
        (kal_wchar*) filename,
        "%02d%02d%02d%02d00",
        rtc_time.rtc_mon,
        rtc_time.rtc_day,
        rtc_time.rtc_hour,
        rtc_time.rtc_min);
    kal_wsprintf((kal_wchar*) fullname, "%w%w", path, (const kal_wchar*)filename);

    mmi_fmrdo_util_append_file_ext(fullname, g_fmrdo.rec.format);

    while (mmi_fmrdo_util_check_file_exist(fullname))
    {
        mmi_fmrdo_util_increase_file_name(fullname);
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_get_file_name
 * DESCRIPTION
 *  Get file name for editing.
 * PARAMETERS
 *  fullname        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
UI_string_type mmi_fmrdo_util_get_file_name(UI_string_type fullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = fullname + mmi_ucs2strlen((const S8*)fullname);

    while (p > fullname)
    {
        if (*p == L'\\')
        {
            return (p + 1);
        }
        p--;
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_init_duration
 * DESCRIPTION
 *  Init duration time for display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_init_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.rec.duration = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_start_duration
 * DESCRIPTION
 *  Start to count the fduration time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_start_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_fmrdo.rec.last_duration_ticks);

    mmi_fmrdo_redraw_main_time_duration(TRUE);
    gui_start_timer(300, mmi_fmrdo_util_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_update_duration
 * DESCRIPTION
 *  Update duration time in the record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);

    g_fmrdo.rec.duration += current_time - g_fmrdo.rec.last_duration_ticks;
    g_fmrdo.rec.last_duration_ticks = current_time;

    mmi_fmrdo_redraw_main_time_duration(TRUE);
    gui_start_timer(300, mmi_fmrdo_util_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_stop_duration
 * DESCRIPTION
 *  Stop duration time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_stop_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);
    
    g_fmrdo.rec.duration += current_time - g_fmrdo.rec.last_duration_ticks;
    
    gui_cancel_timer(mmi_fmrdo_util_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_go_back_2_history
 * DESCRIPTION
 *  Go back two level screen after save.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_go_back_2_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}

#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 


#ifdef __MMI_FM_RADIO_ON_SUBLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_highlight_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_highlight_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Register the KEY_SUB_LSK and KEY_SUB_MENU*/
    SetKeyHandler((FuncPtr)mmi_fmrdo_sub_entry_run_app_key_handler, KEY_BACK, KEY_EVENT_DOWN);
    SetKeyHandler((FuncPtr)mmi_fmrdo_sub_entry_run_app_key_handler, KEY_PLAY_STOP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_main_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmrdo_sub_entry_run_app_key_handler(void)
{
	mmi_fmrdo_run_app(); 
 	if (!isEarphonePlugged)   
      {
          return FALSE;
       }
	 if (SetSubLCDInMasterMode())
	{
	    DisplaySubLCDScreen(SCR_ID_FMRDO_SUBLCD_MAIN, mmi_fmrdo_sub_entry_main, 1);
		return TRUE;		
	}
    return FALSE;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_main_from_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_fmrdo_sub_entry_main_from_idle(void)
{
	 if (SetSubLCDInMasterMode())
	{
	    DisplaySubLCDScreen(SCR_ID_FMRDO_SUBLCD_MAIN, mmi_fmrdo_sub_entry_main, 1);
		return TRUE;		
	}
    return FALSE;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_option_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmrdo_sub_entry_option_key_handler(void)
{
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_FMRDO_SUBLCD_MAIN, mmi_fmrdo_sub_entry_option, 1);
    	return TRUE;		
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_search_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmrdo_sub_entry_search_key_handler(void)
{
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_FMRDO_SUBLCD_MAIN, mmi_fmrdo_sub_entry_searching, 1);
    	return TRUE;		
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_search_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmrdo_sub_entry_power_on_key_handler(void)
{
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_FMRDO_SUBLCD_MAIN, mmi_fmrdo_sub_show_power_on_popup, 1);
    	return TRUE;		
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_show_power_on_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_show_power_on_popup(void)
{
    ExecSubLCDCurrExitHandler();
    ClearAllKeyHandler();
    ShowCategory311Screen(
    (PU8)GetString(STR_ID_FMRDO_POWER_ON_FIRST),
               IMG_GLOBAL_L1,
                NULL);
    StartTimer(POPUP_SUBLCD, NORMAL_TIMER_FOR_GOBACKSUBLCD,GoBackSubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_entry_main(void)
{       
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    UI_set_sub_LCD_graphics_context();
    ClearAllKeyHandler();  
    hide_status_icon_bar(2);
    g_fmrdo.in_subLCD_main_screen = TRUE;
    g_fmrdo.in_main_screen = FALSE;
    /*set the skin index on sub lcd*/
    g_fmrdo.skin_index = 0;
    /* button state */
    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    g_fmrdo.is_button_down = FALSE;
    g_fmrdo.normal_repeat_step_count = 0;
        
        
    /* draw main screen */
    mmi_fmrdo_sub_show_main(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK,g_fmrdo.skin_index);    
    /* Register all key handler */
    mmi_fmrdo_sub_main_register_keys();
    SetSubLCDExitHandler(mmi_fmrdo_sub_exit_main);
    UI_set_main_LCD_graphics_context();
    SetDelScrnIDCallbackHandler(SCR_ID_FMRDO_SUBLCD_MAIN, (HistoryDelCBPtr) mmi_fmrdo_sub_exit_root);
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_exit_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_exit_main()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_set_sub_LCD_graphics_context();
    g_fmrdo.in_subLCD_main_screen = FALSE;
    g_fmrdo.is_search_on = FALSE;
    mmi_fmrdo_sub_hide_main();
    /* stop timer and update frequency if we don't release step up/down button yet */
    StopTimer(FMRDO_REPEAT_STEP_TIMER);
    if (g_fmrdo.normal_repeat_step_count != 0)
    {
        mmi_fmrdo_set_frequency(g_fmrdo.step_freq);
    }

    /* stop if it's searching */
    mmi_fmrdo_search_frequency_stop();
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
    SubLCDHistory.entryFuncPtr = (FuncPtr)mmi_fmrdo_sub_entry_main;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_FMRDO_SUBLCD_MAIN);
    UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_main_register_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_main_register_keys(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const mmi_fmrdo_sub_skin_struct *skin_p;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*button_press_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
        mmi_fmrdo_sub_press_power_button,       /* FMRDO_BUTTON_POWER */   
        MMI_dummy_function,      /* without search key on sublcd*/
        mmi_fmrdo_sub_press_step_up_button,     /* FMRDO_BUTTON_STEP_UP */  
        mmi_fmrdo_sub_press_step_down_button    /* FMRDO_BUTTON_STEP_DOWN */  
    };
    void (*button_release_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
        mmi_fmrdo_sub_release_power_button,     /* FMRDO_BUTTON_POWER */
        MMI_dummy_function,    /* without search key on sublcd*/
        mmi_fmrdo_sub_release_step_up_button,   /* FMRDO_BUTTON_STEP_UP */   
        mmi_fmrdo_sub_release_step_down_button  /* FMRDO_BUTTON_STEP_DOWN */ 
        };
    skin_p = &g_fmrdo_subLCD_skins[g_fmrdo.skin_index]; 
    /* associate button press, release handlers with skin settings and register SUBLCD key handlers */
    SetKeyHandler(button_release_hdlr[skin_p->left_key_mapping], KEY_BACK, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->right_key_mapping], KEY_FWD, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->down_key_mapping], KEY_PLAY_STOP, KEY_EVENT_UP);
    SetKeyHandler(button_press_hdlr[skin_p->left_key_mapping], KEY_BACK, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->right_key_mapping], KEY_FWD, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->down_key_mapping], KEY_PLAY_STOP, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_dummy_function, KEY_FWD, KEY_EVENT_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_BACK, KEY_EVENT_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_PLAY_STOP, KEY_EVENT_REPEAT);
        
    /* register handlers to entry FM Radio option menu on subLCD */

     SetKeyHandler((FuncPtr)mmi_fmrdo_sub_entry_option_key_handler,KEY_PLAY_STOP, KEY_LONG_PRESS);
  
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_press_step_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_press_step_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_STEP_DOWN;
    g_fmrdo.is_button_down = TRUE;
    g_fmrdo.normal_repeat_step_count = 0;
    UI_set_sub_LCD_graphics_context();
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
    UI_set_main_LCD_graphics_context();
    mmi_fmrdo_search_frequency_stop();  
    if(g_fmrdo.subLCD_operation_mode == FMRDO_SUB_LCD_STEP_MODE)
    {           
        g_fmrdo.step_freq = g_fmrdo.frequency;
        StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_down_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_release_step_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_release_step_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)
    {
        g_fmrdo.is_button_down = FALSE;
        UI_set_sub_LCD_graphics_context();            
        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
        UI_set_main_LCD_graphics_context();
        switch(g_fmrdo.subLCD_operation_mode) 
        {
           case FMRDO_SUB_LCD_STEP_MODE: /*when it's step mode,behavior as before*/
           StopTimer(FMRDO_REPEAT_STEP_TIMER);
           if (is_freq_changed)
            {
                freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
            }
            else
            {
              /* frequency is not changed during button press down so we need to decrease it */
              if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
              {
                 freq = g_fmrdo.frequency - 1;
              }
              else
              {
                freq = MAX_FM_FREQUENCY;
              }
             }
          mmi_fmrdo_set_frequency(freq);
          break;
  
          case FMRDO_SUB_LCD_CHANNEL_MODE:/*when it's channel mode*/
         
          freq = g_fmrdo.frequency;
       	  mmi_fmrdo_sub_goto_previous_channel(freq);
          break;
       	  
          case FMRDO_SUB_LCD_SEARCH_MODE:

          if(g_fmrdo.is_power_on) /*power on FM Radio successful*/
           { 
             
             UI_set_sub_LCD_graphics_context(); 
             freq = g_fmrdo.frequency;
             mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_ID_FMRDO_SEARCHING));
             UI_set_main_LCD_graphics_context();
             mmi_fmrdo_search_frequency_start(freq, FALSE);
           }
          else 
           {
                mmi_fmrdo_sub_entry_power_on_key_handler();
            }
          break;
            }
    
    g_fmrdo.normal_repeat_step_count = 0;
    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_press_step_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_press_step_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_STEP_UP;
    g_fmrdo.is_button_down = TRUE;
    g_fmrdo.normal_repeat_step_count = 0;
    UI_set_sub_LCD_graphics_context();
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
    UI_set_main_LCD_graphics_context();
    mmi_fmrdo_search_frequency_stop();  
    if(g_fmrdo.subLCD_operation_mode == FMRDO_SUB_LCD_STEP_MODE)
    {           
        g_fmrdo.step_freq = g_fmrdo.frequency;
        StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_up_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_release_step_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_release_step_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)
    {
        g_fmrdo.is_button_down = FALSE; 
        UI_set_sub_LCD_graphics_context();            
        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
        UI_set_main_LCD_graphics_context();
        switch(g_fmrdo.subLCD_operation_mode) 
        {
            case FMRDO_SUB_LCD_STEP_MODE: /*when it's step mode,behavior as before*/
            StopTimer(FMRDO_REPEAT_STEP_TIMER);
            if (is_freq_changed)
            {
                freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
            }
            else
            {
              /* frequency is not changed during button press down so we need to decrease it */
              if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
              {
                 freq = g_fmrdo.frequency + 1;
              }
              else
              {
                freq = MIN_FM_FREQUENCY;
              }
             }
            mmi_fmrdo_set_frequency(freq);
            break;
  
            case FMRDO_SUB_LCD_CHANNEL_MODE:/*when it's channel mode*/
         
            freq = g_fmrdo.frequency;
       	    mmi_fmrdo_sub_goto_next_channel(freq);
            break;
       	  
            case FMRDO_SUB_LCD_SEARCH_MODE:	
           if(g_fmrdo.is_power_on) /*power on FM Radio successful*/
           { 
                
                UI_set_sub_LCD_graphics_context();
                freq = g_fmrdo.frequency;
                mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_ID_FMRDO_SEARCHING));
                UI_set_main_LCD_graphics_context();
                mmi_fmrdo_search_frequency_start(freq, TRUE);
            }
            else 
            {
                mmi_fmrdo_sub_entry_power_on_key_handler();
            }
                break;
        } 
    g_fmrdo.normal_repeat_step_count = 0;
    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_press_power_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_press_power_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_POWER;
    g_fmrdo.is_button_down = TRUE;
    UI_set_sub_LCD_graphics_context();
    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);
    UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_release_power_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_release_power_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
    {
        g_fmrdo.is_button_down = FALSE;

        /* stop if it's searching */
        mmi_fmrdo_search_frequency_stop();

        /* power off if it's on */
        mmi_fmrdo_power_on((BOOL) ! g_fmrdo.is_power_on);
        UI_set_sub_LCD_graphics_context();
        mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);
        UI_set_main_LCD_graphics_context();
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_goto_previous_channel
 * DESCRIPTION
 * From current frequency switch to the previous user defined channel 
 * PARAMETERS
 *  freq
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_goto_previous_channel(U16 freq)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 first_channel = -1;
    S16 last_channel = -1;
    S16 previous_channel;      
    S16 channel_index = mmi_fmrdo_match_channel_list(freq);   /* current channel index*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    if (g_fmrdo.channel_list.freq[i] != 0 )  /*find the first user defined channel*/
    {
        first_channel = i;
        break;	
    }
    for (i = FM_RADIO_CHANNEL_NUM -1; i >= 0; i--)
    if (g_fmrdo.channel_list.freq[i] != 0 )  /*find the last user defined channel*/
    {
        last_channel = i;
        break;	
    }
    if((first_channel == last_channel) && last_channel < 0)/*the channel list is empty!*/
    {
        return;
        }
    if(channel_index == -1) /*current channle is not an user defined channel*/
    {
        if(first_channel >= 0)
        mmi_fmrdo_goto_channel(first_channel);
        return;
    }
    else   /* the current channel is an user define channel */
    {
        if(first_channel == last_channel)   /*and just only one channel */
        {
            return;                                                
            }
        else 
        {
            for(i = channel_index - 1;i >= 0;i--)
            if(g_fmrdo.channel_list.freq[i] != 0)
            {
                previous_channel = i;
                mmi_fmrdo_goto_channel(previous_channel);/*goto previous channel*/
                return;
            }
            for(i = FM_RADIO_CHANNEL_NUM - 1; i > channel_index ;i--)
            if(g_fmrdo.channel_list.freq[i] != 0)
            {
                previous_channel = i;
                mmi_fmrdo_goto_channel(previous_channel);
                return;
             }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_goto_next_channel
 * DESCRIPTION
 * From current frequency switch to the next user defined channel 
 * PARAMETERS
 *  freq
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_goto_next_channel(U16 freq)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 first_channel = -1;
    S16 last_channel = -1;
    S16 next_channel;      
    S16 channel_index = mmi_fmrdo_match_channel_list(freq);   /* current channel index*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    if (g_fmrdo.channel_list.freq[i] != 0 )  /*find the first user defined channel*/
    {
        first_channel = i;
        break;	
    }
    for (i = FM_RADIO_CHANNEL_NUM -1; i >= 0; i--)
    if (g_fmrdo.channel_list.freq[i] != 0 )  /*find the last user defined channel*/
    {
        last_channel = i;
        break;	
    }
    if((first_channel == last_channel) && last_channel < 0)/*the channel list is empty!*/
    {
        return;
        }
    if(channel_index == -1) /*current channle is not an user defined channel*/
    {
        if(last_channel >= 0)
        mmi_fmrdo_goto_channel(last_channel);
        return;
    }
    else   /* the current channel is an user define channel */
    {
        if(first_channel == last_channel)   /*and just only one channel */
        {
            return;                                                
            }
        else 
        {
            for(i = channel_index +1;i < FM_RADIO_CHANNEL_NUM;i++)
            if(g_fmrdo.channel_list.freq[i] != 0)
            {
                next_channel = i;
                mmi_fmrdo_goto_channel(next_channel);/*goto next channel*/
                return;
             }
             for(i = 0; i < channel_index ;i++)
             if(g_fmrdo.channel_list.freq[i] != 0)
             {
                 next_channel = i;
                 mmi_fmrdo_goto_channel(next_channel);
                 return;
              }
         }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_option
 * DESCRIPTION
 * entry the option menu of FM Radio on subLCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	    U16 item_texts[4];
        U16 item_icons[4];
        U8 *item_popups[4],i;
        S32 n_items;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();
    ClearAllKeyHandler();
    StopTimer(POPUP_SUBLCD);
    item_texts[0] = STR_ID_FM_RADIO_ON_SUBLCD_STEP_MODE;
    item_icons[0] = IMG_GLOBAL_L1;	
    item_texts[1] = STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_MODE;
    item_icons[1] = IMG_GLOBAL_L2;
    item_texts[2] = STR_ID_FM_RADIO_ON_SUBLCD_SEARCH_MODE;
    item_icons[2] = IMG_GLOBAL_L3;
    item_texts[3] = STR_ID_FM_RADIO_ON_SUBLCD_BACK_TO_MAINMENU;  
    item_icons[3] = IMG_GLOBAL_L4;
    n_items = 4;
    RegisterHighlightHandler(mmi_fmrdo_sub_option_highlight_hdlr);
    for (i = 0; i < n_items; i++)
    {
        item_popups[i] = NULL;
    }
    ShowCategory314Screen(
                (U8*)get_string(STR_ID_FM_RADIO_ON_SUBLCD_MODE_SELECT),
                (U16)GetRootTitleIcon(MENU_ID_FMRDO_MAIN), 
                (S32)n_items,
                (U16 *)item_texts,
                (U16 *)item_icons,
                (U8 **)item_popups,
                (S32)g_subLCD_option_highlighted_item,
                NULL);
    UI_set_main_LCD_graphics_context();
    /* register left, right key handlers on Option subLCD*/
    SetKeyHandler(mmi_fmrdo_sub_option_LSK, KEY_BACK, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackSubLCDHistory,KEY_FWD,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_sub_option_LSK,KEY_PLAY_STOP,KEY_EVENT_DOWN);
        
    SetKeyHandler(MMI_dummy_function, KEY_PLAY_STOP, KEY_EVENT_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_BACK, KEY_EVENT_REPEAT);
    /* register volume inc, dec handlers */
    SetKeyHandler(fixed_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    
    SetSubLCDExitHandler(mmi_fmrdo_sub_exit_option);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_exit_option
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_exit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_go_to_previous_channel
 * DESCRIPTION
 * switch to the previous user defined channel 
 * PARAMETERS
 *  freq
 * RETURNS
 *  void
 *****************************************************************************/	
void mmi_fmrdo_sub_option_highlight_hdlr(S32 index)	
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_subLCD_option_highlighted_item =  index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	switch(g_subLCD_option_highlighted_item)
        {
        	case 0:
        	mmi_fmrdo_sub_entry_step_mode();
        	break;
            case 1:
        	mmi_fmrdo_sub_entry_channel_mode();
        	break;
        	case 2:
        	mmi_fmrdo_sub_entry_search_mode();
        	break;
        	case 3: 
            if(g_fmrdo.is_power_on)
                { 
                    mmi_fmrdo_power_on(FALSE);
                }
            UI_set_sub_LCD_graphics_context();
        	EntrySubLCDMainMenu();
            UI_set_main_LCD_graphics_context();
        	break;       	
        }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_step_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_entry_step_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*power on FM Radio if it's off*/
    #ifdef __MMI_FM_RADIO_BIND_EARPHONE_SUBLCD__
    if (isEarphonePlugged)
    #endif 
    if(!g_fmrdo.is_power_on)  
    mmi_fmrdo_power_on(TRUE);
    g_fmrdo.subLCD_operation_mode = FMRDO_SUB_LCD_STEP_MODE;
    /*return to FM Radio main screen on sublcd*/
    GoBackSubLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_channel_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_entry_channel_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    BOOL is_empty_channel_list = TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.subLCD_operation_mode = FMRDO_SUB_LCD_CHANNEL_MODE;
    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    if (g_fmrdo.channel_list.freq[i] != 0 ) 
    {
	    is_empty_channel_list = FALSE;
		break;
	 }
    if(is_empty_channel_list)/*the channel list is empty*/
	{
	     mmi_fmrdo_preset_list_confirm_LSK();
	 }
    else
    {
        /*return to FM Radio main screen on sublcd*/
        GoBackSubLCDHistory();
     }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_search_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_entry_search_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_FM_RADIO_BIND_EARPHONE_SUBLCD__
    if (isEarphonePlugged)
     #endif 
    if(!g_fmrdo.is_power_on)/*power on FM Radio when it's off on search mode*/
     {
        mmi_fmrdo_power_on(TRUE);
        }
    g_fmrdo.subLCD_operation_mode = FMRDO_SUB_LCD_SEARCH_MODE;
    g_fmrdo.is_search_on = TRUE;
    /*return to FM Radio main screen on sublcd*/
    GoBackSubLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_entry_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_entry_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();    
    ClearAllKeyHandler();
    ShowCategory311Screen(
                    (PU8)GetString(STR_ID_FMRDO_SEARCHING),
                     IMG_GLOBAL_L1,
                     NULL); 
    SetKeyHandler(mmi_fmrdo_searching_abort,KEY_FWD,KEY_EVENT_DOWN);
        /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetSubLCDExitHandler(mmi_fmrdo_sub_exit_searching);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_exit_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_exit_searching(void)
{      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL)
    {
        SubLCDHistoryNode currHistory;
        currHistory.scrnID = SCR_ID_FMRDO_SUBLCD_SEARCHING;
        currHistory.entryFuncPtr = mmi_fmrdo_sub_entry_searching;
        AddSubLCDHistoryWithScrID(&currHistory, SCR_ID_FMRDO_SUBLCD_SEARCHING);
     }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_exit_root
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fmrdo_sub_exit_root(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(!g_fmrdo.is_background_play)
    {
        mmi_fmrdo_power_on(FALSE);
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrao_sub_exit_by_earphone_plug_out
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_fmrao_sub_exit_by_earphone_plug_out(void)
{
    if(GetSubLCActiveScreenId() == SCR_ID_FMRDO_SUBLCD_MAIN ||
       IsSubLCDScreenPresent(SCR_ID_FMRDO_SUBLCD_MAIN))
    {
        /* If plug out the earphone, we will return to subLCD main menu screen */
        ExecSubLCDCurrExitHandler();                  
        ClearAllKeyHandler();
        UI_set_sub_LCD_graphics_context();  
        DinitSubLCDHistory();
        EntrySubLCDMainMenu();
        UI_set_sub_LCD_graphics_context();  
        return TRUE;
    }
    return FALSE;
}

#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/

#endif /* __MMI_FM_RADIO__ */ 

