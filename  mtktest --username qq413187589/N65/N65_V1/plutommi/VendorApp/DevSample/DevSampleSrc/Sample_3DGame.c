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
 *   Sample_3DGame.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Sample code for 3D Game 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
/*************************
* Feature Define
*************************/
#include "MMI_features.h"       /* MMI features */

/*************************
* OS, Datatype  
*************************/
#include "stdC.h"       /* OS */
#include "L4Dr1.h"      /* l4 */
#include "MMIDatatype.h"        /* Datatype */
#include "GlobalDefs.h" /* Golbal image and string ID */
#include "GlobalConstants.h"    /* KEY ID */

/*************************
* MMI Framework    
*************************/
#include "FrameworkStruct.h"    /* Framework structure - depedency function for following functions  */
#include "GUI.h"        /* pixtel_UI font drawing functions */
#include "HistoryGprot.h"       /* Screen history */
#include "Unicodexdcl.h"        /* Unicode transform functions */
#include "EventsGprot.h"        /* Event (key) handler */
#include "keybrd.h"     /* keypad tone */
#include "SubLCDHistoryGprot.h" /* sublcd */

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"  /* touch screen */
#endif 

#include "wgui_categories.h"
#include "wgui_categories_multimedia.h"

/*************************
* Audio, Vibration 
*************************/
#include "AudioInc.h"   /* Audio play functions */
#include "SettingProfile.h"     /* Audio setting */
#include "ProfileGprots.h"      /* Profiles fuction. Check ring type. */
#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_audio.h"  /* mdi audio interface */
#include "gpioInc.h"    /* Vibration */

/*************************
* Graphic
*************************/
#include "gdi_include.h"        /* gdi interface */

/*************************
* Game Res
*************************/
#include "GameDefs.h"   /* game icon on sublcd */

/***************************************************************************** 
* Local Function
*****************************************************************************/
void mmi_sample_3dgame_exit_app_screen(void);
#ifdef __MMI_SUBLCD__
void mmi_sample_3dgame_entry_sublcd(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_3dgame_entry_app_screen
 * DESCRIPTION
 *  enter dev3dgame screen - init an MMI  environment for 3D game
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_3dgame_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_3D_GAME, mmi_sample_3dgame_exit_app_screen, mmi_sample_3dgame_entry_app_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_3D_GAME);

    /* reset clip */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* enable multilayer */
    gdi_layer_multi_layer_enable();

    /* entry full screen app - will force status bar update */
    entry_full_screen();

    /* force all playing keypad tone off */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* set audio volumn */
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, 4);  /* vol level : 0 - 6 */

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* clear keys */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    clear_category_screen_key_handlers();

    /* set RSK-up to exit */
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    /* clear background as black */
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

#ifndef WIN32
    /* enable faster key handling */
    mmi_frm_set_key_handle_in_high_frequency(MMI_TRUE);
#endif /* WIN32 */ 

#ifdef __MMI_SUBLCD__
    /* draw game icon on sublcd */
    ForceSubLCDScreen(mmi_sample_3dgame_entry_sublcd);
#endif /* __MMI_SUBLCD__ */ 

    /* disalbe align timer, this will let timer more accurate */
    UI_disable_alignment_timers();

    /* start game */
    if (gui_buffer == NULL)
    {
        /* TODO: start new game here .. */

    }
    else
    {
        /* back from interrupt */
        /* TODO: resume a existing game here .. */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_3dgame_exit_app_screen
 * DESCRIPTION
 *  exit dev3dgame screen, restore to normal mmi environment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_3dgame_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore timer to default accuracy */
    UI_enable_alignment_timers();

#ifndef WIN32
    /* disable faster key handling */
    mmi_frm_set_key_handle_in_high_frequency(MMI_FALSE);
#endif /* WIN32 */ 

    /* re-enable the keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* stop all playing audio and vibration */
    mdi_audio_stop_string();
    VibratorOff();

    /* resume background play */
    mdi_audio_resume_background_play();

#ifdef __MMI_SUBLCD__
    /* resume sublcd */
    GoBackSubLCDHistory();
#endif /* __MMI_SUBLCD__ */ 

    /* let MMI can sleep */
    TurnOffBacklight();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_3dgame_entry_sublcd
 * DESCRIPTION
 *  entry sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_sample_3dgame_entry_sublcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory332Screen(IMG_ID_GAME_SUBLCD_ICON);
}
#endif /* __MMI_SUBLCD__ */ 

