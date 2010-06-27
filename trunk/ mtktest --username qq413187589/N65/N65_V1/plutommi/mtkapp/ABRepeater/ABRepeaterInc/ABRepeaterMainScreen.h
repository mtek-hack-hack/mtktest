/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  ABRepeaterMainScreen.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repeater main screen
*
* Author:
* -------
*  Tarun Bakshi
*
*********************************************************************************************/

#ifndef __AB_Repeater_MAIN_SCREEN_H__
#define __AB_Repeater_MAIN_SCREEN_H__

/*
 * Need to include:
 * (1) gui_data_types.h
 */
#ifdef __MMI_AB_REPEATER__
extern void mmi_abrepeat_show_mainscreen(U16 title, U16 left_softkey, U16 right_softkey, S8 skin);
extern void mmi_abrepeat_mainscr_LSK_down_hldr(void);
extern void mmi_abrepeat_mainscr_RSK_down_hldr(void);
extern void mmi_abrepeat_redraw_main_screen(void);
extern void mmi_abrepeat_redraw_main_title(void);
extern void mmi_abrepeat_scroll_main_title_handler(void);
extern void mmi_abrepeat_redraw_main_title_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_abrepeat_redraw_main_volumebar(void);
extern void mmi_abrepeat_redraw_main_button(U8 btn_idx, BOOL bPressed);
extern void mmi_abrepeat_redraw_main_buttons(void);
extern void mmi_abrepeat_exit_mainscreen(void);
extern void mmi_abrepeat_redraw_absection_buttons(S32 absection);
extern void mmi_abrepeat_redraw_once_always_button(BOOL bPressed);
extern void mmi_abrepeat_redraw_mode_switch_button(BOOL bPressed);
extern void mmi_abrepeat_redraw_progress_bar(void);
extern void mmi_abrepeat_init_main_screen_images(S8 skin);
extern void mmi_abrepeat_redraw_RSK(BOOL bPressed);
extern void mmi_abrepeat_redraw_LSK(BOOL bPressed);
extern void mmi_abrepeat_redraw_volumectrl(BOOL bInc, BOOL bPressed);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_abrepeat_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_abrepeat_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_abrepeat_pen_move_hdlr(mmi_pen_point_struct pos);
extern void mmi_abrepeat_pen_long_tap_hdlr(mmi_pen_point_struct pos);
extern BOOL mmi_abrepeat_pen_check_inside_area(const mmi_pen_point_struct *pos_p, 
                                               const abrepeat_area_struct *area_p);
extern BOOL mmi_abrepeat_pen_check_inside_area_sk(const mmi_pen_point_struct *pos_p, 
                                               const abrepeat_area_struct *area_p);

#endif /*__MMI_TOUCH_SCREEN__*/

#endif /* __MMI_AB_REPEATER__ */ 

#endif /* __AB_Repeater_MAIN_SCREEN_H__ */ 

