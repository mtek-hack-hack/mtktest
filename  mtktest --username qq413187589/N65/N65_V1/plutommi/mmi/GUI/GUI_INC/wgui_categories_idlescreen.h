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
 *  wgui_categories_idlescreen.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Idle Screen related categories.
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
 *==============================================================================
 *******************************************************************************/
#ifndef __WGUI_CATEGORIES_IDLESCREEN_H__
#define __WGUI_CATEGORIES_IDLESCREEN_H__

extern void SetIdleScreenWallpaper(U16 image_ID);
extern void SetIdleScreenNetworkName(U8 *s);
extern void SetIdleScreenNetworkStatus(U8 *s);

extern void idle_screen_show_network_details(void);

extern MMI_BOOL mmi_cat33_get_cache_wallpaper_info (MMI_ID_TYPE id, PS8 filename, GDI_HANDLE *wallpaper_layer, U16 *output_image_type);

extern void RedrawCategory33Screen(void);
extern void ShowCategory33Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *history_buffer);
extern void ExitCategory33Screen(void);

extern void RedrawCategory86Screen(void);

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
extern void ShowCategory86Screen(U16 title, U16 title_icon, U16 left_softkey, U16 left_softkey_icon, U16 right_softkey, U16 right_softkey_icon, U16 img_id, U8 *network_string, U8 *history_buffer, U8 show_network_name);    /* 051305 Calvin modified */

/* __CUSTPACK_MULTIBIN Calvin END */

extern void ExitCategory86Screen(void);

extern void ShowCategory106Screen(U16 icon_screensaver, U8 *filename, U8 *history_buffer);
extern void RedrawCategory106Screen(void);
extern void ExitCategory106Screen(void);

extern void ShowCategory128Screen(
                U16,
                U16,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 screen_img,
                U8 date_flag,
                U8 time_flag,
                U8 service_provider,
                U8 *history_buffer,
                U8);
extern void RedrawCategory128Screen(void);
extern void ExitCategory128Screen(void);

extern void DrawCate130CategoryControlArea(dm_coordinates *coordinate);
extern void ExitCategory130Screen(void);
extern void ShowCategory130Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer);

extern void ShowCategory131Screen(U16 icon_screensaver, U8 *history_buffer);
extern void ExitCategory131Screen(void);

#ifdef __MMI_LCD_PARTIAL_ON__
extern void ShowCategory161Screen(UI_time *t);
extern void RedrawCategory161Screen(void);
extern void ExitCategory161Screen(void);
extern void Category161ChangeTime(UI_time *t);
#endif /* __MMI_LCD_PARTIAL_ON__ */ 

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
extern void wgui_set_wallpaper_change(void);
extern U8 wgui_is_wallpaper_change(void);
extern void wgui_reset_wallpaper_change(void);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

extern void cat86_hide_analog_clock_display(S32 x1, S32 y1, S32 x2, S32 y2);
extern void category128_hide_dt_display(S32 x1, S32 y1, S32 x2, S32 y2);
extern void draw_wallpaper(void);

#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
extern S32 max_touch_idle_screen_shortcut_height(void);
#endif 

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
extern void show_boundries_to_status_bar_at_bottom_idlescreen(void);
#endif 
extern S32 is_on_idlescreen(void);
extern void set_on_idlescreen(S32);

extern void SetIdleScreenWallpaperID(U16 image_ID, MMI_BOOL is_default);
extern void SetIdleScreenWallpaperName(UI_string_type name);
extern void wgui_save_wallpaper_to_speedup(MMI_BOOL is_default);
extern void wgui_stop_wallpaper(void);
extern MMI_BOOL wgui_check_wallpaper_frame_count(S8 *name, S8 **error_str);
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
extern void SetListWallpaperID(U16 image_ID);
#endif

#endif /* __WGUI_CATEGORIES_IDLESCREEN_H__ */ 

