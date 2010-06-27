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
 *  wgui_categories_stopwatch.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Stop Watch related categories.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __WGUI_CATEGORIES_STOPWATCH_H__
#define __WGUI_CATEGORIES_STOPWATCH_H__

typedef struct _stop_watch_history
{
    U16 history_ID;
    S32 highlight_item;
    U8 cur_stop_play_flag;
} UI_stop_watch_history;

typedef struct _stop_watch
{
    S32 mili_sec;
    S32 sec;
    S32 min;
    S32 hour;
    PS8 normalimagedata;
    PS8 highlightimagedata;
    U8 watch_string[40];    /* Printable Stopwatch timer string */
} UI_stop_watch;

#define  CONTINUE_TIMER                0
#define STOP_START_AGAIN               1
#define TIMER_STOP                     0
#define  TIMER_START                   1
#define MAX_TIMER_RECORDS              20
#define DISPLAY_MILISEC_TRUE           1
#define DISPLAY_MILISEC_FALSE          0
#define MAX_MULTIPURPOSE_TIMER            4

/* nWay Timer Refresh rate */
#define STPWACH_UI_UPDATE_PERIOD                   100  /* ms */

/* Use to draw the typical stopwatch background image */
#define STOP_WATCH_ANIMATION_DELAY        1000

extern void ShowCategory306Screen(
                UI_stop_watch *title_values,
                U16 title_img,
                U16 title_side_msg,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                UI_stop_watch *stop_watch_list,
                U16 bkgrd_image,
                U16 title_text,
                U8 *history_buffer,
                S32 highlight_item);
extern void ExitCategory306Screen(void);
extern U8 *GetCategory306History(U8 *history_buffer);
extern S32 GetCategory306HistorySize(void);
extern void RedrawCategory306Screen(void);
extern void GetMultipurposeTimeValues(S32 *high_light);
extern void stop_multipurpose_timers(void);
extern void start_multipurpose_list_watch(U8 index);
extern void reset_all_multipurpose_time(void);

extern void ShowCategory307Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                UI_stop_watch *list_watch,
                S32 highlighted_item,
                U8 *history_buffer,
                U16 bkg_image,
                S32 start_stop_flag);
extern void ExitCategory307Screen(void);

extern void UpdateHistoryValue(S32 *mili, S32 *hr, S32 *min, S32 *sec);
extern void reset_timer(void);
extern void start_stop_watch_timer(U8 start_stop_flag);
extern void change_stopwatchtime_to_string(S32, S32, S32, S32, U8 *, U8);
extern void initialize_stop_watch_timer(void);
extern void show_typical_stop_watch(void);
extern void show_nway_stop_watch(void);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL wgui_stopwatch_pen_down_hdlr(mmi_pen_point_struct point, S32 *index);
extern MMI_BOOL gui_stopwatch_translate_penevent(S32 x, S32 y, S32 *index);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __WGUI_CATEGORIES_STOPWATCH_H__ */ 

