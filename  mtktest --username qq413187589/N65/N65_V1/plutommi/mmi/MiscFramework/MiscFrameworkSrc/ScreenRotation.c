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
 *  ScreenRotation.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI screen rotation 
 *  Available after MT6217 & MT6219, but not MT6218B
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
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_SCREEN_ROTATE__

#include "lcd_if.h"

#include "IdleAppDef.h" /* SCREEN_ROTATION_DUMMY_ID */

#include "wgui_status_icons.h"

#include "ScreenRotationGprot.h"

#ifndef GDI_USING_LAYER_ROTATE
#error "Hardware does not support rotation"
#endif 

extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;
extern void UpdateUITheme(void);

#ifndef __MTK_TARGET__
/* MTE */
extern S32 mmi_mte_is_active(void);
#endif /* __MTK_TARGET__ */

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef struct
{
    U8 wh_swapped;  /* width-height swapped */
    U8 lcd_layer_rotate;
} frm_screen_rotation_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

static const frm_screen_rotation_struct g_screen_rotation_data[MMI_FRM_SCREEN_ROTATE_MAX_TYPE] = 
{
    {0, GDI_LCD_LAYER_ROTATE_0},
    {1, GDI_LCD_LAYER_ROTATE_90},
    {0, GDI_LCD_LAYER_ROTATE_180},
    {1, GDI_LCD_LAYER_ROTATE_270},
    {0, GDI_LCD_LAYER_ROTATE_0_MIRROR},
    {1, GDI_LCD_LAYER_ROTATE_90_MIRROR},
    {0, GDI_LCD_LAYER_ROTATE_180_MIRROR},
    {1, GDI_LCD_LAYER_ROTATE_270_MIRROR}
};

/* Rotation value of the current screen with mmi_frm_screen_rotate() */
static mmi_frm_screen_rotate_enum g_mmi_frm_screen_rotate = MMI_FRM_SCREEN_ROTATE_0;

/* Rotation value of the current screen with mmi_frm_set_self_rotation_flag()  (-1 if not set) */
static S32 g_mmi_frm_self_screen_rotate = -1;

/* Rotation value of the previous screen */
static mmi_frm_screen_rotate_enum g_mmi_frm_previous_screen_rotate = MMI_FRM_SCREEN_ROTATE_0;

/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_rotate_screen_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_rotate_screen_setup_environment(const frm_screen_rotation_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_theme *old_current_MMI_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->wh_swapped)
    {
        MAIN_LCD_device_height = GDI_LCD_WIDTH;
        MAIN_LCD_device_width = GDI_LCD_HEIGHT;
    }
    else
    {
        MAIN_LCD_device_height = GDI_LCD_HEIGHT;
        MAIN_LCD_device_width = GDI_LCD_WIDTH;
    }

    gdi_layer_resize(MAIN_LCD_device_width, MAIN_LCD_device_height);

    old_current_MMI_theme = current_MMI_theme;

    /* Setup basic UI global varaibles */
    setup_UI_wrappers();
    /* Re-intialize UI components . */
    wgui_init();
    arrange_status_icons();

    /* force UI theme update */
    // TODO: UpdateUITheme() needs a parameter to force the update.
    current_MMI_theme = NULL;

    /* Update to current theme setting. */
    UpdateUITheme();

    /* UpdateUITheme() does not update current_MMI_theme, simply use old theme. */
    if (current_MMI_theme == NULL)
    {
        current_MMI_theme = old_current_MMI_theme;
    }

#ifndef __MTK_TARGET__
    /* activate the theme for MTE since UpdateUITheme() does nothing when MTE is active. */
    if (mmi_mte_is_active())
    {
        set_MMI_theme(current_MMI_theme);
        MMI_apply_current_theme();
    }
#endif /* __MTK_TARGET__ */
}

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotation        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_screen_rotate(mmi_frm_screen_rotate_enum rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_frm_screen_rotate == rotation || rotation < 0 || rotation >= MMI_FRM_SCREEN_ROTATE_MAX_TYPE)
    {
        return;
    }

    if (GDI_LCD_WIDTH != GDI_LCD_HEIGHT &&
        (g_screen_rotation_data[rotation].wh_swapped != g_screen_rotation_data[g_mmi_frm_screen_rotate].wh_swapped))
    {
        g_mmi_frm_screen_rotate = rotation;

        gdi_lcd_set_rotate(g_screen_rotation_data[rotation].lcd_layer_rotate);
        mmi_frm_rotate_screen_setup_environment(&g_screen_rotation_data[g_mmi_frm_screen_rotate]);
    }
    else
    {
        g_mmi_frm_screen_rotate = rotation;

        gdi_lcd_set_rotate(g_screen_rotation_data[rotation].lcd_layer_rotate);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_self_rotation_flag
 * DESCRIPTION
 *  Sometimes applications changes the rotation of GDI layer by itself without using mmi_frm_screen_rotate() for
 *  some reasons. (For example, when image sensor is rotated, GDI layer for camera preview needs to be rotated, too)
 *  
 *  After screen is switched, mmi_frm_get_previous_screen_rotate() returns the value set in this function.
 * PARAMETERS
 *  rotation        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_self_rotation_flag(mmi_frm_screen_rotate_enum rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_frm_self_screen_rotate = (S32) rotation;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_screen_rotation
 * DESCRIPTION
 *  Reset screen rotation and context and reset the rotation of base layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_reset_screen_rotation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL clear_screen = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_frm_self_screen_rotate >= 0)
    {
        g_mmi_frm_previous_screen_rotate = (mmi_frm_screen_rotate_enum) g_mmi_frm_self_screen_rotate;
        g_mmi_frm_self_screen_rotate = -1;
        /* Unnecessary to set 'clear_screen' because the application will do it in its screen exit handler */
    }
    else
    {
        g_mmi_frm_previous_screen_rotate = g_mmi_frm_screen_rotate;
        if (g_mmi_frm_screen_rotate != MMI_FRM_SCREEN_ROTATE_0)
        {
            clear_screen = MMI_TRUE;
        }
    }
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_0);

    /* 
     * Note: after screen is rotated, the content of LCD double buffer is wrong.
     *
     * If backlight was off and the next screen turn on backlight, it will BLT the 
     * content of LCD double buffer to the screen, and the screen is messed.
     *
     * Framework should be responsible to clear the screen to black to avoid blinking 
     * when backlight is turned on.
     */
    if (clear_screen)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_previous_screen_width_height_swapped
 * DESCRIPTION
 *  Check whether the previous screen has swapped width and height
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_frm_is_previous_screen_width_height_swapped(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LCD_WIDTH != GDI_LCD_HEIGHT && g_screen_rotation_data[g_mmi_frm_previous_screen_rotate].wh_swapped)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_previous_screen_rotate
 * DESCRIPTION
 *  Get the previous screen rotation value
 *  
 *  It is typically used screens like popup dialog because they need to preserve the display of the previous screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_frm_screen_rotate_enum
 *****************************************************************************/
mmi_frm_screen_rotate_enum mmi_frm_get_previous_screen_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_frm_previous_screen_rotate;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_screen_width_height_swapped
 * DESCRIPTION
 *  Check whether the current screen has swapped width and height
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_frm_is_screen_width_height_swapped(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LCD_WIDTH != GDI_LCD_HEIGHT && g_screen_rotation_data[g_mmi_frm_screen_rotate].wh_swapped)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_screen_rotate
 * DESCRIPTION
 *  Get the current screen rotation value
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_frm_screen_rotate_enum
 *****************************************************************************/
mmi_frm_screen_rotate_enum mmi_frm_get_screen_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_frm_screen_rotate;
}

#else /* __MMI_SCREEN_ROTATE__ */ 

int screen_rotation_dummy;  /* Get rid of compile warning */

#endif /* __MMI_SCREEN_ROTATE__ */ 

