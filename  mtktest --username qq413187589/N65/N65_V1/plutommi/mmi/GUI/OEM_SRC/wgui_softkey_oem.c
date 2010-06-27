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
 *  wgui_softkey_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Extract the codes related drawing into this file for oem
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
#include "MMI_features.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_themes.h"
#include "wgui_softkeys_pre_oem.h"
#include "wgui_softkeys.h"
#include "wgui_softkeys_post_oem.h"

//static void show_softkey_background_with_clipping(S32 x1, S32 y1, S32 x2, S32 y2);
void show_softkey_background_with_clipping(S32 x1, S32 y1, S32 x2, S32 y2); // WMD取消此处的static属性



/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_oem_show
 * DESCRIPTION
 *  show sofutkey
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_oem_show(WGUI_SOFTKEY_ENUM key)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_icontext_button(&MMI_softkeys[(WGUI_SOFTKEY_ENUM)key]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_oem_hide
 * DESCRIPTION
 *  show sofutkey
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_oem_hide(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button b;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b = MMI_softkeys[key];

    if ((WGUI_SOFTKEY_ENUM)key == WGUI_MAX_SOFTKEYS)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            show_softkey_background_with_clipping(
                MMI_ROTATED_BUTTON_BAR_X + 1 /* TEMP FIX */ ,
                MMI_ROTATED_BUTTON_BAR_Y,
                MMI_ROTATED_BUTTON_BAR_X + MMI_ROTATED_BUTTON_BAR_WIDTH - 1,
                MMI_ROTATED_BUTTON_BAR_Y + MMI_ROTATED_BUTTON_BAR_HEIGHT - 1);
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
            show_softkey_background_with_clipping(
            0,
            UI_device_height - MMI_button_bar_height,
            UI_device_width - 1,
            UI_device_height - 1);
    }
    else if ((WGUI_SOFTKEY_ENUM)key == MMI_LEFT_SOFTKEY)
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)       /* 041205 Calvin modieid */
        if (!(b.flags & UI_BUTTON_NO_UNDER_BAR))
    #else
        if (!(b.flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY))
    #endif
            {
    #ifdef __MMI_SCREEN_ROTATE__
                if (mmi_frm_is_screen_width_height_swapped())
                {
                    show_softkey_background_with_clipping(
                        b.x,
                        b.y,
                        b.x + b.width,
                        b.y + b.height);
                }
                else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
                    show_softkey_background_with_clipping(
                    b.x,
                    UI_device_height - MMI_button_bar_height,
                    b.x + b.width,
                    UI_device_height - 1);
            }
    }
    else if ((WGUI_SOFTKEY_ENUM)key == MMI_RIGHT_SOFTKEY)
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)       /* 041205 Calvin modieid */
        if (!(b.flags & UI_BUTTON_NO_UNDER_BAR))
    #else 
        if (!(b.flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY))
    #endif 
            {
    #ifdef __MMI_SCREEN_ROTATE__
                if (mmi_frm_is_screen_width_height_swapped())
                {
                    show_softkey_background_with_clipping(
                        b.x,
                        b.y,
                        b.x + b.width,
                        b.y + b.height);
                }
                else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
                    show_softkey_background_with_clipping(
                    b.x,
                    UI_device_height - MMI_button_bar_height,
                    b.x + b.width,
                    UI_device_height - 1);
            }
    }
#ifdef __MMI_WGUI_CSK_ENABLE__
    else if ((WGUI_SOFTKEY_ENUM)key == MMI_CENTER_SOFTKEY)
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)       /* 041205 Calvin modieid */
        if (!(b.flags & UI_BUTTON_NO_UNDER_BAR))
    #else
        if (!(b.flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY))
    #endif
            {
    #ifdef __MMI_SCREEN_ROTATE__
                if (mmi_frm_is_screen_width_height_swapped())
                {
                    show_softkey_background_with_clipping(
                        b.x,
                        b.y,
                        b.x + b.width,
                        b.y + b.height);
                }
                else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
                    show_softkey_background_with_clipping(
                    b.x,
                    UI_device_height - MMI_button_bar_height,
                    b.x + b.width,
                    UI_device_height - 1);
            }
    }
#endif /* __MMI_WGUI_CSK_ENABLE__ */
    
}

/*****************************************************************************
 * FUNCTION
 *  show_softkey_background_with_clipping
 * DESCRIPTION
 *  Draws a background behind the softkeys with clipping
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_softkey_background_with_clipping(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern S32 MMI_button_bar_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        gui_push_clip();
        gui_reset_clip();
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        gui_pop_clip();
        return;
    }
#endif /* __MMI_SCREEN_ROTATE__ */ 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
#if defined( __MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        if (MMI_softkey_filler_disabled)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
	else if (current_MMI_theme->softkey_bar_bkg_filler)
	{
	/*gui_draw_filled_area(x1, y1, x2, y2, current_MMI_theme->softkey_bar_bkg_filler);*/
            gui_draw_filled_area(
                0, 
                UI_device_height - MMI_button_bar_height,
                UI_device_width - 1,
                UI_device_height - 1,
                current_MMI_theme->softkey_bar_bkg_filler);
	}
	else
	{
		gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
	}
    }
    else
    {
	gui_show_image(0, UI_device_height - MMI_button_bar_height, (PU8) GetImage(IMG_SOFTKEY_BAR));
    }
#else 
//    gui_fill_rectangle(x1, y1, x2, y2, c);
    /*gui_draw_filled_area(x1, y1, x2, y2, current_MMI_theme->softkey_bar_bkg_filler);*/
    gui_draw_filled_area(
        0, 
        UI_device_height - MMI_button_bar_height,
        UI_device_width - 1,
        UI_device_height - 1,
        current_MMI_theme->softkey_bar_bkg_filler);
#endif 

    gui_pop_clip();
}