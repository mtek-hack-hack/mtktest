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
*  AudioPlayerMainScreen.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main screen
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

#ifndef __AUDIO_PLAYER_MAIN_SCREEN_H__
#define __AUDIO_PLAYER_MAIN_SCREEN_H__

/*
 * Need to include:
 * (1) gui_data_types.h
 */
#ifdef __MMI_AUDIO_PLAYER__

extern signed char g_audply_main_selected_button;

extern void mmi_audply_redraw_subLCD(BOOL is_show);
extern void mmi_audply_exit_subLCD(void);

extern void mmi_audply_show_mainscreen(U16 title, U16 left_softkey, U16 right_softkey, S8 skin);

extern void mmi_audply_exit_mainscreen(void);

extern void mmi_audply_redraw_main_screen(void);
extern void mmi_audply_redraw_main_title_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_audply_redraw_main_title(void);
extern void mmi_audply_redraw_LSK_down(void);
extern void mmi_audply_redraw_LSK_up(void);
extern void mmi_audply_redraw_RSK_down(void);
extern void mmi_audply_redraw_RSK_up(void);
extern void mmi_audply_redraw_main_playlisticon(void);
extern void mmi_audply_redraw_main_time(void);
extern void mmi_audply_redraw_main_file_index(void);
extern void mmi_audply_redraw_main_volumebar(void);
extern void mmi_audply_redraw_main_volumectrl(U8 sel, BOOL down);       /* sel = 0 -> dec, sel = 1 -> inc */
extern void mmi_audply_redraw_main_progressbar(void);

#ifdef __MMI_TOUCH_SCREEN__
extern S32 mmi_audply_get_current_x_coordinate(void);
extern U32 mmi_audply_get_proportional_time_from_x(S16 cor_x);
extern void mmi_audply_redraw_main_setting(BOOL on);

extern void mmi_audply_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_audply_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_audply_pen_move_hdlr(mmi_pen_point_struct pos);

#endif /* __MMI_TOUCH_SCREEN__ */ 
extern void mmi_audply_redraw_main_buttons(void);

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
extern void mmi_audply_spectrum_display_start(void);
extern void mmi_audply_spectrum_display_stop(void);
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 


#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
extern void mmi_sub_audply_redraw_main_buttons(void);
extern void mmi_sub_audply_redraw_main_push_buttons(U8 button, BOOL is_down);
extern void mmi_sub_audply_redraw_main_toggle_buttons(U8 button, BOOL is_down);
extern void mmi_sub_audply_init_main_screen_images(S8 skin);
#endif

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__

extern void mmi_audply_stop_scroll_lyric_and_clean_screen(void);
extern void mmi_audply_redraw_lyric_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_audply_scroll_lyric_handler(void);
extern void mmi_audply_redraw_lyric(void);
extern void mmi_audply_lyric_on_time(void);

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#endif /* __MMI_AUDIO_PLAYER__ */ 

extern void mmi_audply_display_popup(S32 result);

#endif /* __AUDIO_PLAYER_MAIN_SCREEN_H__ */ 

