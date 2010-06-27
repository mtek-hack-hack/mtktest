/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wgui_softkeys.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  softkey related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
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
 * rebase maintrunk.MAUI_MBJ on 2007-3-17 23:21:53.
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
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_softkeys.c
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines for Softkeys
**********************************************************************************/
#include "MMI_features.h"
#include "wgui_softkeys.h"
#include "gui_themes.h"
#include "FrameworkStruct.h"
#include "DebugInitDef.h"
#include "gdi_include.h"
#include "wgui_status_icons.h"//061506 double buffer
#include "ShortcutsDefs.h"
#include "Wgui_categories_inputs.h"
#include "gui_setting.h"
#ifdef __LSK_KEYSEND2_IN_ONE__
#include "MTPNP_PFAL_CC.h"   
#endif/*__LSK_KEYSEND2_IN_ONE__*/

/* Globals                 */
/* softkey width */
S32 MMI_softkey_width = MMI_SOFTKEY_WIDTH;

MMI_BOOL MMI_softkey_filler_disabled = MMI_FALSE;

#ifdef __MMI_WGUI_CSK_ENABLE__
S32 MMI_center_softkey_width = MMI_CENTER_SOFTKEY_WIDTH;
#endif

/* softkey height */
S32 MMI_softkey_height = MMI_SOFTKEY_HEIGHT;

void (*wgui_softkey_show) (WGUI_SOFTKEY_ENUM key) = NULL;
void (*wgui_softkey_hide) (WGUI_SOFTKEY_ENUM key) = NULL;

/* Softkey wrappers        */
icontext_button MMI_softkeys[WGUI_MAX_SOFTKEYS];

#define  MMI_left_softkey  MMI_softkeys[MMI_LEFT_SOFTKEY]
#define  MMI_right_softkey MMI_softkeys[MMI_RIGHT_SOFTKEY]

#ifdef __MMI_WGUI_CSK_ENABLE__
#define  MMI_center_softkey   MMI_softkeys[MMI_CENTER_SOFTKEY]
#endif 

/* LSK key handler */
U8 left_softkey_keyboard_handler_active = 0;

/* RSKk key handler */
U8 right_softkey_keyboard_handler_active = 0;

#ifdef __MMI_WGUI_CSK_ENABLE__
/* CSK key handler */
U8 center_softkey_keyboard_handler_active = 0;
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 

#define  WGUI_MAX_SOFTKEY_FUNCTIONS 3

#define  WGUI_SOFTKEY_TOUCH_GAP      3

void (*softkey_functions[WGUI_MAX_SOFTKEYS][WGUI_MAX_SOFTKEY_FUNCTIONS]) (void);

#define           left_softkey_functions  softkey_functions[MMI_LEFT_SOFTKEY]
#define           right_softkey_functions    softkey_functions[MMI_RIGHT_SOFTKEY]
#define           center_softkey_functions      softkey_functions[MMI_CENTER_SOFTKEY]

/* Functions to hide softkeys */
void (*hide_softkey[WGUI_MAX_SOFTKEYS]) (void);

#ifdef __MMI_T9__
extern void (*t9_inputbox_LSK_function) (void);
#endif 

void softkey_keyboard_handler(S32 vkey_code, S32 key_state);

extern UI_string_type get_string(MMI_ID_TYPE i);
extern PU8 get_image(MMI_ID_TYPE i);


/*****************************************************************************
 * FUNCTION
 *  clear_softkey_button_background_callback
 * DESCRIPTION
 *  Clear the background of softkey. Used of callback function in icontext_button.clear_background_fp
 * PARAMETERS
 *  button_object       [IN]        The target button
 * RETURNS
 *  void
 *****************************************************************************/
void clear_softkey_button_background_callback(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
        if (button_object == (void*)&MMI_softkeys[i])
        {
            (hide_softkey[i]) ();
            return;
        }
    }
    MMI_DBG_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  create_softkeys
 * DESCRIPTION
 *  Creates and set default value of softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, key = 0;
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set theme of LSK */
    set_MMI_LSK_theme();
    /* careate button */
    gui_create_icontext_button(
        &MMI_softkeys[MMI_LEFT_SOFTKEY],
        0,
        UI_device_height - MMI_softkey_height,
        MMI_softkey_width,
        MMI_softkey_height,
        NULL,
        NULL);
    gui_icontext_set_horizontal_gap(&MMI_softkeys[MMI_LEFT_SOFTKEY], MMI_UI_SOFTKEY_GAP);

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
    MMI_softkeys[MMI_LEFT_SOFTKEY].flags |=
        (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_LEFT_ALIGN | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
         UI_BUTTON_ALIGN_ICON_TEXT | UI_BUTTON_DISABLE_BACKGND_DISPLAY);
#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 
    MMI_softkeys[MMI_LEFT_SOFTKEY].flags |=
        (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_TEXT_X | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
         UI_BUTTON_ALIGN_ICON_TEXT);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[MMI_LEFT_SOFTKEY], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[MMI_LEFT_SOFTKEY].x)
        x1 = MMI_softkeys[MMI_LEFT_SOFTKEY].x;
    if (x2 > MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width - 1)
        x2 = MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[MMI_LEFT_SOFTKEY], x1, y1, x2, y2);
#endif

    /* set theme of RSK */
    set_MMI_RSK_theme();
    /* create RK button */

    gui_create_icontext_button(
        &MMI_softkeys[MMI_RIGHT_SOFTKEY],
        UI_device_width - MMI_softkey_width - MMI_UI_SOFTKEY_GAP,
        UI_device_height - MMI_softkey_height,
        MMI_softkey_width,
        MMI_softkey_height,
        NULL,
        NULL);
    gui_icontext_set_horizontal_gap(&MMI_softkeys[MMI_RIGHT_SOFTKEY], MMI_UI_SOFTKEY_GAP);

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
    MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |=
        (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_RIGHT_ALIGN | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
         UI_BUTTON_ALIGN_ICON_TEXT | UI_BUTTON_DISABLE_BACKGND_DISPLAY);
#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 
    MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |=
        (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_TEXT_X | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
         UI_BUTTON_ALIGN_ICON_TEXT);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[MMI_RIGHT_SOFTKEY], &x1, &y1, &x2, &y2);    
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[MMI_RIGHT_SOFTKEY].x)
        x1 = MMI_softkeys[MMI_RIGHT_SOFTKEY].x;
    if (x2 > MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width - 1)
        x2 = MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[MMI_RIGHT_SOFTKEY], x1, y1, x2, y2);
#endif

#ifdef __MMI_WGUI_CSK_ENABLE__
    /* create CSK button */
    gui_create_icontext_button(
        &MMI_softkeys[MMI_CENTER_SOFTKEY],
        MMI_softkey_width + ((UI_device_width - (MMI_softkey_width) * 2 - MMI_center_softkey_width) >> 1),
        UI_device_height - MMI_softkey_height,
        MMI_center_softkey_width,
        MMI_softkey_height,
        NULL,
        NULL);
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
    MMI_center_softkey.flags |=
        (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_TEXT_X | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
         UI_BUTTON_ALIGN_ICON_TEXT | UI_BUTTON_DISABLE_BACKGND_DISPLAY);
#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 
    MMI_center_softkey.flags |=
        (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y | UI_BUTTON_ALIGN_ICON_TEXT);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[MMI_CENTER_SOFTKEY], &x1, &y1, &x2, &y2);  
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[MMI_CENTER_SOFTKEY].x)
        x1 = MMI_softkeys[MMI_CENTER_SOFTKEY].x;
    if (x2 > MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width - 1)
        x2 = MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[MMI_CENTER_SOFTKEY], x1, y1, x2, y2);
#endif
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 

    /* initilaize softkey functions to dummy func */
    for (key = 0; key < WGUI_MAX_SOFTKEYS; key++)
    {
        MMI_softkeys[key].clear_background_fp = clear_softkey_button_background_callback;
        hide_softkey[key] = UI_dummy_function;
        for (i = 0; i < WGUI_MAX_SOFTKEY_FUNCTIONS; i++)
        {
            softkey_functions[key][i] = UI_dummy_function;
        }
    }
    register_keyboard_global_key_handler(softkey_keyboard_handler);
    wgui_softkey_show = wgui_softkey_oem_show;
    wgui_softkey_hide = wgui_softkey_oem_hide;
}


/*****************************************************************************
 * FUNCTION
 *  restore_softkeys
 * DESCRIPTION
 *  set the softkeys to the MMI's default positions and sizes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (key = 0; key < WGUI_MAX_SOFTKEYS; key++)
    {
#ifdef __MMI_WGUI_CSK_ENABLE__
	if (key == MMI_CENTER_SOFTKEY)
	{
			gui_resize_icontext_button(&MMI_softkeys[key], MMI_center_softkey_width, MMI_softkey_height);
	}
	else			
#endif
	{
			gui_resize_icontext_button(&MMI_softkeys[key], MMI_softkey_width, MMI_softkey_height);
	}	
        gui_move_icontext_button(&MMI_softkeys[key], 0, UI_device_height - MMI_softkey_height);
        gui_set_icontext_button_current_theme(&MMI_softkeys[key]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_softkey_by_string_length
 * DESCRIPTION
 *  resize the left softkey width according the the string
 * PARAMETERS
 *  s       [IN]        String
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void resize_softkey_by_string_length(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(MMI_softkeys[key].text_font);
    gui_measure_string(s, &sw, &sh);
    gui_resize_icontext_button(&MMI_softkeys[key], sw + WGUI_SOFTKEY_STRING_GAP, MMI_softkeys[key].height);
    gui_move_icontext_button(&MMI_softkeys[key], 0, UI_device_height - MMI_softkeys[key].height);
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_label_for_IME
 * DESCRIPTION
 *  Changes the label of softkeys
 * PARAMETERS
 *  s       [IN]        String
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_label_for_IME(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkeys[key].text = s;
    if (MMI_softkeys[key].normal_down_icon == NULL)
    {
        MMI_softkeys[key].flags &= ~UI_BUTTON_CENTER_ICON_X;
    #ifdef __MMI_WGUI_CSK_ENABLE__
        if (key == MMI_CENTER_SOFTKEY)
        {
            MMI_softkeys[key].flags |= UI_BUTTON_CENTER_TEXT_X;
        }
    #endif /* __MMI_WGUI_CSK_ENABLE__ */ 

    #if !(defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__)) || defined (__MMI_MAINLCD_128X160__)
        MMI_softkeys[key].flags |= UI_BUTTON_CENTER_TEXT_X;
    #endif 
    }
    gui_resize_icontext_button(&MMI_softkeys[key], MMI_softkeys[key].width, MMI_softkeys[key].height);
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, y1, x2, y2);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  set_softkey_label
 * DESCRIPTION
 *  Changes the label of softkeys
 * PARAMETERS
 *  s       [IN]        String
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_label(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	set_softkey_label_for_IME(s, key);
    if (key == MMI_LEFT_SOFTKEY)
        SetInputboxLSKText();
}

/*****************************************************************************
 * FUNCTION
 *  get_softkey_label
 * DESCRIPTION
 *  get softkey text label
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  Softkey text label
 *****************************************************************************/
UI_string_type get_softkey_label(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key >= WGUI_MAX_SOFTKEYS)
    {
        return NULL;
    }
    return MMI_softkeys[key].text;
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_icon
 * DESCRIPTION
 *  Changes the icon of softkeys
 * PARAMETERS
 *  icon        [IN]        Icon
 *  key         [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_icon(PU8 icon, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 new_icon = icon;
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon != NULL) && (icon[0] == 0))
    {
        new_icon = NULL;
    }

    if (icon != NULL && icon == MMI_softkeys[key].normal_up_icon)
    {
        return;
    }

    /* set icon of LSK button */
    gui_icontext_button_set_icon(&MMI_softkeys[key], new_icon, gui_transparent_color(0, 0, 0));
    if (MMI_softkeys[key].text == NULL)
    {
        MMI_softkeys[key].flags &= ~UI_BUTTON_CENTER_TEXT_X;
        MMI_softkeys[key].flags |= UI_BUTTON_CENTER_ICON_X;
    }
    gui_resize_icontext_button(&MMI_softkeys[key], MMI_softkeys[key].width, MMI_softkeys[key].height);
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, y1, x2, y2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  change_softkey
 * DESCRIPTION
 *  Changes the string and icon of softkeys
 * PARAMETERS
 *  s       [IN]        String
 *  i       [IN]        Icon
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void change_softkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_softkey_label(str, key);
    }
    else
    {
        set_softkey_label(NULL, key);
    }

    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

        set_softkey_icon(img, key);
    }
    else
    {
        set_softkey_icon(NULL, key);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_function
 * DESCRIPTION
 *  Changes the handler of softkeys
 * PARAMETERS
 *  f       [IN]        Handler function
 *  k       [IN]        Key event type
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }

    switch (key)
    {
        case MMI_LEFT_SOFTKEY:
            if (k == KEY_LONG_PRESS)
            {
                SetKeyHandler(f, KEY_LSK, KEY_LONG_PRESS);
            }
            softkey_functions[key][k] = f;
            break;

        case MMI_RIGHT_SOFTKEY:
            if (k == KEY_LONG_PRESS)
            {
                SetKeyHandler(f, KEY_RSK, KEY_LONG_PRESS);
            }
            softkey_functions[key][k] = f;
            break;

        #ifdef __MMI_WGUI_CSK_ENABLE__
        case MMI_CENTER_SOFTKEY:
            if (k == KEY_LONG_PRESS)
            {
                SetKeyHandler(f, KEY_CSK, KEY_LONG_PRESS);
            }
            softkey_functions[key][k] = f;
            break;
        #endif /* __MMI_WGUI_CSK_ENABLE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_softkey_function
 * DESCRIPTION
 *  get softkey handlers
 * PARAMETERS
 *  k       [IN]        Key event
 *  key     [IN]        Softkey enum
 * RETURNS
 *  Softkey callback functions
 *****************************************************************************/
FuncPtr get_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return NULL;
    }

    return softkey_functions[key][k];
}


/*****************************************************************************
 * FUNCTION
 *  execute_softkey_function
 * DESCRIPTION
 *  execute softkey handlers
 * PARAMETERS
 *  k       [IN]        Key event
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void execute_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }

    if (softkey_functions[key][k] != NULL)
    {
        softkey_functions[key][k] ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey
 * DESCRIPTION
 *  Sets the label and the function to be called for the softkey
 * PARAMETERS
 *  s       [IN]        New string to be used as the softkey label
 *  f       [IN]        Function that is called when a particular softkey event occurs
 *  k       [IN]        Key event
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey(UI_string_type s, void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }

    set_softkey_label(s, key);
    set_softkey_function(f, k, key);
}


/*****************************************************************************
 * FUNCTION
 *  clear_softkey_display_functions
 * DESCRIPTION
 *  Clear the functions of the softkey
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void clear_softkey_display_functions(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hide_softkey[key] = UI_dummy_function;
    for (i = 0; i < WGUI_MAX_SOFTKEY_FUNCTIONS; i++)
    {
        softkey_functions[key][i] = UI_dummy_function;
    }
}


/*****************************************************************************
 * FUNCTION
 *  show_softkey
 * DESCRIPTION
 *  Displays softkey
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void show_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_softkeys[key].text == NULL) && (MMI_softkeys[key].normal_up_icon == NULL))
    {
        clear_softkey_handler(key);
        return;
    }

    wgui_softkey_show(key);
}


/*****************************************************************************
 * FUNCTION
 *  move_softkey
 * DESCRIPTION
 *  change the position of softkey
 * PARAMETERS
 *  x       [IN]        New x-coordinate of softkey
 *  y       [IN]        New y-coordinate of softkey
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void move_softkey(S32 x, S32 y, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_icontext_button(&MMI_softkeys[key], x, y);
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, y1, x2, y2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  resize_softkey
 * DESCRIPTION
 *  change the width and height of softkey
 * PARAMETERS
 *  width       [IN]        New width of softkey
 *  height      [IN]        New height of softkey
 *  key         [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void resize_softkey(S32 width, S32 height, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_icontext_button(&MMI_softkeys[key], width, height);
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, y1, x2, y2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  redraw_softkey
 * DESCRIPTION
 *  Redraw softkey
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;//061506 double buffer

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
#ifdef __LSK_KEYSEND2_IN_ONE__
        kal_prompt_trace(MOD_MMI,"redraw_softkey LSK :[%x]for call",MTPNP_PFAL_CC_GetIsKeyForCall());
        if(MTPNP_PFAL_CC_GetIsKeyForCall() && (key == MMI_LEFT_SOFTKEY))
        {
		return;
        }
#endif/*__LSK_KEYSEND2_IN_ONE__*/
    hide_softkey[key] ();
    show_softkey(key);
    gui_unlock_double_buffer();

    switch (key)
    {
        case MMI_LEFT_SOFTKEY:
            gdi_layer_blt_previous(
                MMI_softkeys[MMI_LEFT_SOFTKEY].x,
                MMI_softkeys[MMI_LEFT_SOFTKEY].y,
                (MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width + 2),
                (MMI_softkeys[MMI_LEFT_SOFTKEY].y + MMI_softkeys[MMI_LEFT_SOFTKEY].height + 2));
            break;

        case MMI_RIGHT_SOFTKEY:
            gdi_layer_blt_previous(
                MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
                MMI_softkeys[MMI_RIGHT_SOFTKEY].y,
                (MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width + 2),
                (MMI_softkeys[MMI_RIGHT_SOFTKEY].y + MMI_softkeys[MMI_RIGHT_SOFTKEY].height + 2));
            break;
        #ifdef __MMI_WGUI_CSK_ENABLE__
        case MMI_CENTER_SOFTKEY:
            gdi_layer_blt_previous(
                MMI_softkeys[MMI_CENTER_SOFTKEY].x,
                MMI_softkeys[MMI_CENTER_SOFTKEY].y,
                (MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width + 2),
                (MMI_softkeys[MMI_CENTER_SOFTKEY].y + MMI_softkeys[MMI_CENTER_SOFTKEY].height + 2));
            break;
        #endif /* __MMI_WGUI_CSK_ENABLE__ */ 
    }

    /* 061506 double buffer Start */
    for (idx=0; idx<MAX_STATUS_ICON_BARS; idx++)
    {
        if(get_status_icon_bar_type((U8)idx)&STATUS_ICON_BAR_ENABLE_DOUBLE_BUFFER)
        {
            gdi_layer_push_and_set_active(get_status_icon_bar_layer((U8)idx));
            gdi_layer_toggle_double();
            gdi_layer_copy_double();//070306 copy double
            gdi_layer_pop_and_restore_active();
        }
    }
    /* 061506 double buffer End */
}


/*****************************************************************************
 * FUNCTION
 *  left_softkey_down
 * DESCRIPTION
 *  Handles left softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void left_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_softkeys[MMI_LEFT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED))
    {                                       /* change the state of LSK button */
        MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_STATE_DOWN;
        redraw_softkey(MMI_LEFT_SOFTKEY);   /* redraw LSK */
        /* call function handlers of LSK down */
        execute_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  left_softkey_up
 * DESCRIPTION
 *  Handles left softkey up event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void left_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_softkeys[MMI_LEFT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED)
    {   /* change the state of LSK button */
        MMI_softkeys[MMI_LEFT_SOFTKEY].flags &= ~UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[MMI_LEFT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DOWN;
        redraw_softkey(MMI_LEFT_SOFTKEY);

        /* call function handlers of LSK Up */
        execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
    }
}

/*****************************************************************************
 * FUNCTION
 *  left_softkey_up
 * DESCRIPTION
 *  Handles left softkey up event but no redraw
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_softkey_state_no_redraw( U16 KeyCode, U16 KeyType)
{
	if ( KeyCode == KEY_LSK )
	{
		if ( KeyType == KEY_EVENT_UP )
		{
			if (MMI_softkeys[MMI_LEFT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED)
			{   /* change the state of LSK button */
				MMI_softkeys[MMI_LEFT_SOFTKEY].flags &= ~UI_BUTTON_STATE_CLICKED;
				MMI_softkeys[MMI_LEFT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DOWN;
			}
		}
		else if ( KeyType == KEY_EVENT_DOWN )
		{
			if (!(MMI_softkeys[MMI_LEFT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED))
			{
				/* change the state of LSK button */
				MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_STATE_CLICKED;
				MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_STATE_DOWN;
			}
		}
	}
	else if ( KeyCode == KEY_RSK )
	{
		if ( KeyType == KEY_EVENT_UP )
		{
			if (MMI_softkeys[MMI_RIGHT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED)
			{   /* change the state of RSK button */
				MMI_softkeys[MMI_RIGHT_SOFTKEY].flags &= ~UI_BUTTON_STATE_CLICKED;
				MMI_softkeys[MMI_RIGHT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DOWN;
			}
		}
		else if ( KeyType == KEY_EVENT_DOWN )
		{
			if (!(MMI_softkeys[MMI_RIGHT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED))
			{
				/* change the state of RSK button */
				MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_STATE_CLICKED;
				MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_STATE_DOWN;
			}
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  right_softkey_down
 * DESCRIPTION
 *  Handles right softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void right_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_softkeys[MMI_RIGHT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED))
    {
        /* change the state of RSK button */
        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_STATE_DOWN;
        redraw_softkey(MMI_RIGHT_SOFTKEY);
        execute_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  right_softkey_up
 * DESCRIPTION
 *  Handles right softkey up event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_softkeys[MMI_RIGHT_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED)
    {
        /* change the state of LSK button */
        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags &= ~UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DOWN;
        redraw_softkey(MMI_RIGHT_SOFTKEY);
        execute_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
    }
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  center_softkey_down
 * DESCRIPTION
 *  Handles center softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void center_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_softkeys[MMI_CENTER_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED))
    {   /* change the state of LSK button */
        MMI_softkeys[MMI_CENTER_SOFTKEY].flags |= UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[MMI_CENTER_SOFTKEY].flags |= UI_BUTTON_STATE_DOWN;
        redraw_softkey(MMI_CENTER_SOFTKEY);
        /* call function handlers of LSK down  */
        execute_softkey_function(KEY_EVENT_DOWN, MMI_CENTER_SOFTKEY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  center_softkey_up
 * DESCRIPTION
 *  Handles left softkey up event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void center_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_softkeys[MMI_CENTER_SOFTKEY].flags & UI_BUTTON_STATE_CLICKED)
    {   /* change the state of LSK button */
        MMI_softkeys[MMI_CENTER_SOFTKEY].flags &= ~UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[MMI_CENTER_SOFTKEY].flags &= ~UI_BUTTON_STATE_DOWN;
        redraw_softkey(MMI_CENTER_SOFTKEY);
        /* call function handlers of LSK Up */
        execute_softkey_function(KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
    }
}
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  register_softkey_handler
 * DESCRIPTION
 *  Register handlers of softkeys
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void register_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_softkeys[key].text == NULL) && (MMI_softkeys[key].normal_up_icon == NULL))
    {
        return;
    }

    switch (key)
    {
        case MMI_LEFT_SOFTKEY:
            SetKeyHandler(left_softkey_down, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(left_softkey_up, KEY_LSK, KEY_EVENT_UP);
            left_softkey_keyboard_handler_active = 1;
            break;

        case MMI_RIGHT_SOFTKEY:
            SetKeyHandler(right_softkey_down, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(right_softkey_up, KEY_RSK, KEY_EVENT_UP);
            right_softkey_keyboard_handler_active = 1;
            break;

    #ifdef __MMI_WGUI_CSK_ENABLE__
        case MMI_CENTER_SOFTKEY:
            SetKeyHandler(center_softkey_down, KEY_CSK, KEY_EVENT_DOWN);
            SetKeyHandler(center_softkey_up, KEY_CSK, KEY_EVENT_UP);
            center_softkey_keyboard_handler_active = 1;
            break;
    #endif /* __MMI_WGUI_CSK_ENABLE__ */ 
    }
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  register_center_softkey_to_enter_key
 * DESCRIPTION
 *  Register center softkey handlers to enter key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_center_softkey_to_enter_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(center_softkey_up, KEY_ENTER, KEY_EVENT_UP);
    SetKeyHandler(center_softkey_down, KEY_ENTER, KEY_EVENT_DOWN);
}
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  clear_softkey_handler
 * DESCRIPTION
 *  Register handlers of softkeys
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void clear_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key)
    {
        case MMI_LEFT_SOFTKEY:
            ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
            left_softkey_keyboard_handler_active = 0;
            break;

        case MMI_RIGHT_SOFTKEY:
            ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
            right_softkey_keyboard_handler_active = 0;
            break;

    #ifdef __MMI_WGUI_CSK_ENABLE__
        case MMI_CENTER_SOFTKEY:
            ClearKeyHandler(KEY_CSK, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_CSK, KEY_EVENT_UP);
            center_softkey_keyboard_handler_active = 0;
            break;
    #endif /* __MMI_WGUI_CSK_ENABLE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  softkey_keyboard_handler
 * DESCRIPTION
 *  Keyboard handler (Simulator) for softkeys
 * PARAMETERS
 *  vkey_code       [IN]        Key type
 *  key_state       [IN]        Key event type
 * RETURNS
 *  void
 *****************************************************************************/
void softkey_keyboard_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 112:
                if (left_softkey_keyboard_handler_active)
                {
                    left_softkey_down();
                }
                break;
            case 113:
                if (right_softkey_keyboard_handler_active)
                {
                    right_softkey_down();
                }
                break;
        }
    }
    else
    {
        switch (vkey_code)
        {
            case 112:
                if (left_softkey_keyboard_handler_active)
                {
                    left_softkey_up();
                }
                break;
            case 113:
                if (right_softkey_keyboard_handler_active)
                {
                    right_softkey_up();
                }
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  register_hide_softkey
 * DESCRIPTION
 *  Register handlers of hide softkeys
 * PARAMETERS
 *  f       [IN]        Callback function to hide softkey
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void register_hide_softkey(void (*f) (void), WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hide_softkey[key] = f;
}


/*****************************************************************************
 * FUNCTION
 *  reset_softkeys
 * DESCRIPTION
 *  Sets the softkey states to normal and clears the hide functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
        MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_DOWN;
        MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_DISABLED;
        MMI_softkeys[i].flags &= ~UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE;
        MMI_softkeys[i].flags &= ~UI_BUTTON_NO_SHIFT_BUTTON;
        hide_softkey[i] = UI_dummy_function;
    }
    MMI_softkey_filler_disabled = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  reset_softkey
 * DESCRIPTION
 *  Sets the softkey states to normal and clears the hide functions
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void reset_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_CLICKED;
    MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_DOWN;
    MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_DISABLED;
    MMI_softkeys[key].flags &= ~UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE;
    /* Do not reset UI_BUTTON_NO_SHIFT_BUTTON and hide_softkey[] */
}


/*****************************************************************************
 * FUNCTION
 *  disable_softkey_background
 * DESCRIPTION
 *  Set some flags to disable background display of softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_softkey_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
        MMI_softkeys[i].flags |= UI_BUTTON_NO_UNDER_BAR;
    #else 
        MMI_softkeys[i].flags |= UI_BUTTON_DISABLE_BACKGND_DISPLAY;
    #endif 
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_filler_disabled
 * DESCRIPTION
 *  Set the filler in theme disabled or enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_filler_disabled(MMI_BOOL filler_disabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkey_filler_disabled = filler_disabled;
}


/*****************************************************************************
 * FUNCTION
 *  enable_softkey_background
 * DESCRIPTION
 *  Set some flags to disable background display of softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enable_softkey_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
        MMI_softkeys[i].flags &= ~UI_BUTTON_NO_UNDER_BAR;
    #else 
        MMI_softkeys[i].flags &= ~UI_BUTTON_DISABLE_BACKGND_DISPLAY;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_flags_on
 * DESCRIPTION
 *  turn on flag of softkeys
 * PARAMETERS
 *  flag        [IN]        
 *  key         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_flags_on(S32 flag, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkeys[key].flags |= flag;
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_flags_off
 * DESCRIPTION
 *  turn off  flag of softkeys
 * PARAMETERS
 *  flag        [IN]        
 *  key         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_flags_off(S32 flag, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkeys[key].flags &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_offset_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_get_offset_ex(UI_string_type sk_str_p, S32 *offset_x, S32 *offset_y, WGUI_SOFTKEY_ENUM key, mmi_frm_screen_rotate_enum rotate_degree)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_string(sk_str_p, &sw, &sh);

#ifdef __MMI_SCREEN_ROTATE__
    if (rotate_degree != MMI_FRM_SCREEN_ROTATE_0)
    {
        *offset_x =  MMI_ROTATED_BUTTON_BAR_X + MMI_ROTATED_SOFTKEY_WIDTH - sw - MMI_UI_SOFTKEY_GAP;

        if (key == MMI_LEFT_SOFTKEY)
        {
            *offset_y =  MMI_ROTATED_BUTTON_BAR_HEIGHT - GUI_BUTTON_VERTICAL_GAP - sh - 
                (MMI_ROTATED_SOFTKEY_HEIGHT - GUI_BUTTON_VERTICAL_GAP - sh) / 2;
        }
        else
        {        
            *offset_y =  MMI_ROTATED_BUTTON_BAR_Y + GUI_BUTTON_VERTICAL_GAP +
                (MMI_ROTATED_SOFTKEY_HEIGHT - GUI_BUTTON_VERTICAL_GAP) / 2 - sh / 2;
        }
    }
    else
    {
#endif /* __MMI_SCREEN_ROTATE__ */        
        *offset_y = MMI_softkeys[key].y + GUI_BUTTON_VERTICAL_GAP +
                (MMI_softkey_height - GUI_BUTTON_VERTICAL_GAP) / 2 - sh / 2;
        if (key == MMI_LEFT_SOFTKEY)
        {
        #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
            *offset_x =  MMI_softkeys[key].x + MMI_UI_SOFTKEY_GAP;
        #else
            *offset_x = (MMI_softkeys[key].width - sw) / 2;
        #endif
        }
        else
        {        
        #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)|| defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__)
            *offset_x =  MMI_softkeys[key].x + MMI_softkeys[key].width - MMI_UI_SOFTKEY_GAP - sw;
        #else
            *offset_x = MMI_softkeys[key].x  + 
                (MMI_softkeys[MMI_RIGHT_SOFTKEY].width - sw) / 2;
        #endif
        }
        
#ifdef __MMI_SCREEN_ROTATE__
    }
#endif /* __MMI_SCREEN_ROTATE__ */        

    if (r2lMMIFlag)
    {
        *offset_x += sw;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_offset
 * DESCRIPTION
 *  turn off  flag of softkeys
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_get_offset(UI_string_type sk_str_p, S32 *offset_x, S32 *offset_y, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    wgui_softkey_get_offset_ex(sk_str_p, offset_x, offset_y, key, mmi_frm_get_screen_rotate());
#else
    wgui_softkey_get_offset_ex(sk_str_p, offset_x, offset_y, key, MMI_FRM_SCREEN_ROTATE_0);
#endif
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  translate_softkey_pen_event
 * DESCRIPTION
 *  translate low level key events to softkey related events
 * PARAMETERS
 *  key                 [IN]            One of value of WGUI_SOFTKEY_ENUM
 *  pen_event           [IN]            Low level pen event type
 *  x                   [IN]            X-coordinate of pen event
 *  y                   [IN]            Y-coordinate of pen event
 *  button_event        [IN/OUT]        Softkey related event type
 * RETURNS
 *  void
 *****************************************************************************/
BOOL translate_softkey_pen_event(
        WGUI_SOFTKEY_ENUM key,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_button_pen_enum *button_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_icontext_button_translate_pen_event(&MMI_softkeys[key], pen_event, x, y, button_event);
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_dimension
 * DESCRIPTION
 *  get softkey dimenstion
 * PARAMETERS
 *  key         [IN]            One of value of WGUI_SOFTKEY_ENUM
 *  width       [IN/OUT]        Width of softkey
 *  height      [IN/OUT]        Height of softkey
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_get_dimension(WGUI_SOFTKEY_ENUM key, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MMI_softkeys[key].width;
    *height = MMI_softkeys[key].height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_position
 * DESCRIPTION
 *  get softkey position
 * PARAMETERS
 *  key         [IN]            One of value of WGUI_SOFTKEY_ENUM
 *  x           [IN/OUT]        X-position of softkey
 *  y           [?]             
 *  yx(?)       [IN/OUT]        Y-positino of softkey
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_get_position(WGUI_SOFTKEY_ENUM key, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = MMI_softkeys[key].x;
    *y = MMI_softkeys[key].y;
}


/*****************************************************************************
 * FUNCTION
 *  show_softkey_background
 * DESCRIPTION
 *  Draws a background behind the softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_softkey_background(void)
{
    wgui_softkey_hide(WGUI_MAX_SOFTKEYS);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_softkey
 * DESCRIPTION
 *  Hides the softkeys using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key)
    {
        case MMI_LEFT_SOFTKEY:
    #ifdef __MMI_SCREEN_ROTATE__
            if (mmi_frm_is_screen_width_height_swapped())
            {
                gdi_draw_solid_rect(
                    MMI_softkeys[MMI_LEFT_SOFTKEY].x,
                    MMI_softkeys[MMI_LEFT_SOFTKEY].y,
                    MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width + 2,
                    MMI_softkeys[MMI_LEFT_SOFTKEY].y + MMI_softkeys[MMI_LEFT_SOFTKEY].height + 2,
                    GDI_COLOR_TRANSPARENT);
            }
            else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
                gdi_draw_solid_rect(
                    MMI_softkeys[MMI_LEFT_SOFTKEY].x,
                    UI_device_height - MMI_button_bar_height,
                    MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width + 2,
                    UI_device_height - 1,
                    GDI_COLOR_TRANSPARENT);
            break;

        case MMI_RIGHT_SOFTKEY:
        #ifdef __MMI_SCREEN_ROTATE__
            if (mmi_frm_is_screen_width_height_swapped())
            {
                gdi_draw_solid_rect(
                    MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
                    MMI_softkeys[MMI_RIGHT_SOFTKEY].y,
                    MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width + 2,
                    MMI_softkeys[MMI_RIGHT_SOFTKEY].y + MMI_softkeys[MMI_RIGHT_SOFTKEY].height + 2,
                    GDI_COLOR_TRANSPARENT);
            }
            else
        #endif /* __MMI_SCREEN_ROTATE__ */ 
                gdi_draw_solid_rect(
                    MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
                    UI_device_height - MMI_button_bar_height,
                    MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width + 2,
                    UI_device_height - 1,
                    GDI_COLOR_TRANSPARENT);
            break;
        #ifdef __MMI_WGUI_CSK_ENABLE__
        case MMI_CENTER_SOFTKEY:
        #ifdef __MMI_SCREEN_ROTATE__
            if (mmi_frm_is_screen_width_height_swapped())
            {
                gdi_draw_solid_rect(
                    MMI_softkeys[MMI_CENTER_SOFTKEY].x,
                    MMI_softkeys[MMI_CENTER_SOFTKEY].y,
                    MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width + 2,
                    MMI_softkeys[MMI_CENTER_SOFTKEY].y + MMI_softkeys[MMI_CENTER_SOFTKEY].height + 2,
                    GDI_COLOR_TRANSPARENT);
            }
            else
        #endif /* __MMI_SCREEN_ROTATE__ */ 
                gdi_draw_solid_rect(
                    MMI_softkeys[MMI_CENTER_SOFTKEY].x,
                    UI_device_height - MMI_button_bar_height,
                    MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width + 2,
                    UI_device_height - 1,
                    GDI_COLOR_TRANSPARENT);
            break;
        #endif /* __MMI_WGUI_CSK_ENABLE__ */ 
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_left_softkey
 * DESCRIPTION
 *  Hides the left softkey using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_left_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clear_softkey(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_right_softkey
 * DESCRIPTION
 *  Hides the left softkey using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_right_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clear_softkey(MMI_RIGHT_SOFTKEY);
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_center_softkey
 * DESCRIPTION
 *  Hides the left softkey using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_center_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clear_softkey(MMI_CENTER_SOFTKEY);
}
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_hide_left_softkey
 * DESCRIPTION
 *  Hides the left softkey
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_hide_left_softkey(void)
{
    wgui_softkey_hide(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_hide_right_softkey
 * DESCRIPTION
 *  Hides the right softkey
 *  
 *  Default hide right softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_hide_right_softkey(void)
{
    wgui_softkey_hide(MMI_RIGHT_SOFTKEY);
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  wgui_hide_center_softkey
 * DESCRIPTION
 *  Hides the center softkey
 *  
 *  Default hide center softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_hide_center_softkey(void)
{
    wgui_softkey_hide(MMI_CENTER_SOFTKEY);
}

#endif /* __MMI_WGUI_CSK_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  register_default_hide_softkeys
 * DESCRIPTION
 *  Registers the default functions to hide the softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_default_hide_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_hide_left_softkey(wgui_hide_left_softkey);
    register_hide_right_softkey(wgui_hide_right_softkey);
#ifdef __MMI_WGUI_CSK_ENABLE__
    register_hide_softkey(wgui_hide_center_softkey, MMI_CENTER_SOFTKEY);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  register_default_hide_softkeys_to_transparent
 * DESCRIPTION
 *  Registers the default functions to hide the softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_default_hide_softkeys_to_transparent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_hide_softkey(wgui_clear_left_softkey, MMI_LEFT_SOFTKEY);
    register_hide_softkey(wgui_clear_right_softkey, MMI_RIGHT_SOFTKEY);
#ifdef __MMI_WGUI_CSK_ENABLE__
    register_hide_softkey(wgui_clear_center_softkey, MMI_CENTER_SOFTKEY);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkey
 * DESCRIPTION
 *  Changes the left softkey label and icon
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__)
    if (g_shct_cntx.IsKeyRetrieving)
    {
        return;
    }
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__) */ 
    /* Redraw the left softkey only if the string changed to enhance efficiency */
    if ((s != STRING_ID_NULL && MMI_softkeys[MMI_LEFT_SOFTKEY].text!= NULL &&
        !mmi_ucs2cmp((const S8 *)get_string(s), (const S8 *)MMI_softkeys[MMI_LEFT_SOFTKEY].text)) ||
        (s == STRING_ID_NULL && MMI_softkeys[MMI_LEFT_SOFTKEY].text == NULL))
    {
        if ((i != IMAGE_ID_NULL && get_image(i) == MMI_softkeys[MMI_LEFT_SOFTKEY].normal_up_icon)||
            (i == IMAGE_ID_NULL && MMI_softkeys[MMI_LEFT_SOFTKEY].normal_up_icon == NULL))
        {
            return;
        }
    }

    hide_softkey[MMI_LEFT_SOFTKEY] ();
    change_left_softkey(s, i);
    redraw_softkey(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  ChangeRightSoftkey
 * DESCRIPTION
 *  Changes the right softkey label and icon
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__)
    if (g_shct_cntx.IsKeyRetrieving)
    {
        return;
    }
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__) */ 
    /* Redraw the right softkey only if the string changed to enhance efficiency */
    if ((s != STRING_ID_NULL && MMI_softkeys[MMI_RIGHT_SOFTKEY].text!= NULL &&
        !mmi_ucs2cmp((const S8 *)get_string(s), (const S8 *)MMI_softkeys[MMI_RIGHT_SOFTKEY].text)) ||
        (s == STRING_ID_NULL && MMI_softkeys[MMI_RIGHT_SOFTKEY].text == NULL))
    {
        if ((i != IMAGE_ID_NULL && get_image(i) == MMI_softkeys[MMI_RIGHT_SOFTKEY].normal_up_icon)||
            (i == IMAGE_ID_NULL && MMI_softkeys[MMI_RIGHT_SOFTKEY].normal_up_icon == NULL))
        {
            return;
        }
    }

    hide_softkey[MMI_RIGHT_SOFTKEY] ();
    change_right_softkey(s, i);
    redraw_right_softkey();
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  ChangeCenterSoftkey
 * DESCRIPTION
 *  Changes the left softkey label and icon
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeCenterSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__)
    if (g_shct_cntx.IsKeyRetrieving)
    {
        return;
    }
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__) */ 
    /* Redraw the center softkey only if the string changed to enhance efficiency */
    if ((s != STRING_ID_NULL && MMI_softkeys[MMI_CENTER_SOFTKEY].text!= NULL &&
        !mmi_ucs2cmp((const S8 *)get_string(s), (const S8 *)MMI_softkeys[MMI_CENTER_SOFTKEY].text)) ||
        (s == STRING_ID_NULL && MMI_softkeys[MMI_CENTER_SOFTKEY].text == NULL))
    {
        if ((i != IMAGE_ID_NULL && get_image(i) == MMI_softkeys[MMI_CENTER_SOFTKEY].normal_up_icon)||
            (i == IMAGE_ID_NULL && MMI_softkeys[MMI_CENTER_SOFTKEY].normal_up_icon == NULL))
        {
            return;
        }
    }
    hide_softkey[MMI_CENTER_SOFTKEY] ();
    change_softkey(s, i, MMI_CENTER_SOFTKEY);
    redraw_softkey(MMI_CENTER_SOFTKEY);
}
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 
/* 030705 Calvin added */


/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkeyByStringLength
 * DESCRIPTION
 *  Changes the left softkey label and icon and also adjust the width according to the string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkeyByStringLength(UI_string_type s, PU8 i)
{
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.IsKeyRetrieving)
    {
        return;
    }
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__) */ 

    gui_lock_double_buffer();
    hide_softkey[MMI_LEFT_SOFTKEY] ();
    resize_left_softkey_by_string_length(s);
    set_left_softkey_label(s);
    set_left_softkey_icon(i);
    redraw_left_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, UI_device_height - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  ChangeRightSoftkeyByStringLength
 * DESCRIPTION
 *  Changes the right softkey label and icon and also adjust the width according to the string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkeyByStringLength(UI_string_type s, PU8 i)
{
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.IsKeyRetrieving)
    {
        return;
    }
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__) */ 

    gui_lock_double_buffer();
    hide_softkey[MMI_RIGHT_SOFTKEY] ();
    resize_right_softkey_by_string_length(s);
    set_right_softkey_label(s);
    set_right_softkey_icon(i);
    redraw_right_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, UI_device_height - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);
}

/* Calvin end */

/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkeyByString
 * DESCRIPTION
 *  Changes the left softkey label using a dynamic string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkeyByString(UI_string_type s, PU8 i)
{
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.IsKeyRetrieving)
    {
        return;
    }
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__) */ 

    gui_lock_double_buffer();
    hide_softkey[MMI_LEFT_SOFTKEY] ();
    set_left_softkey_label(s);
    set_left_softkey_icon(i);
    redraw_left_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, UI_device_height - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  ChangeRightSoftkeyByString
 * DESCRIPTION
 *  Changes the right softkey label using a dynamic string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkeyByString(UI_string_type s, PU8 i)
{
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.IsKeyRetrieving)
    {
        return;
    }
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_IMPL__) */ 

    gui_lock_double_buffer();
    hide_softkey[MMI_RIGHT_SOFTKEY] ();
    set_right_softkey_label(s);
    set_right_softkey_icon(i);
    redraw_right_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, UI_device_height - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  EnableLeftSoftkey
 * DESCRIPTION
 *  Enable the left soft key , set string and icon of LSK and display LSK
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableLeftSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_left_softkey_label(str);
    }
    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

        set_left_softkey_icon(img);
    }
    MMI_softkeys[MMI_LEFT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DISABLED;
    redraw_left_softkey();
    register_left_softkey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  DisableLeftSoftkey
 * DESCRIPTION
 *  Disable the left soft key , set string and icon of LSK and display LSK
 *  with disable color
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void DisableLeftSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_left_softkey_label(str);
    }
    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

        set_left_softkey_icon(img);
    }
    MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_STATE_DISABLED;
    MMI_softkeys[MMI_LEFT_SOFTKEY].disabled_up_filler = NULL;
    MMI_softkeys[MMI_LEFT_SOFTKEY].disabled_down_filler = NULL;
    redraw_left_softkey();
    clear_left_softkey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  EnableRightSoftkey
 * DESCRIPTION
 *  Enable the right soft key , set string and icon of RSK and display RSK
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableRightSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_right_softkey_label(str);
    }
    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

        set_right_softkey_icon(img);
    }
    MMI_softkeys[MMI_RIGHT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DISABLED;
    redraw_right_softkey();
    register_right_softkey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  DisableRightSoftkey
 * DESCRIPTION
 *  Disable the right soft key , set string and icon of RSK and display RSK
 *  with disable color
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void DisableRightSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_right_softkey_label(str);
    }
    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

        set_right_softkey_icon(img);
    }
    MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_STATE_DISABLED;
    MMI_softkeys[MMI_RIGHT_SOFTKEY].disabled_up_filler = NULL;
    MMI_softkeys[MMI_RIGHT_SOFTKEY].disabled_down_filler = NULL;
    redraw_right_softkey();
    clear_right_softkey_handler();
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  EnableCenterSoftkey
 * DESCRIPTION
 *  Enable the left soft key , set string and icon of LSK and display LSK
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableCenterSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_softkey_label(str, MMI_CENTER_SOFTKEY);
    }
    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

        set_softkey_icon(img, MMI_CENTER_SOFTKEY);
    }
    MMI_softkeys[MMI_CENTER_SOFTKEY].flags &= ~UI_BUTTON_STATE_DISABLED;
    /* redraw_softkey(MMI_CENTER_SOFTKEY); */
    register_softkey_handler(MMI_CENTER_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  ResetCenterSoftkey
 * DESCRIPTION
 *  Disable center softkey display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCenterSoftkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_softkey(0, 0, MMI_CENTER_SOFTKEY);
}
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 

/*****************************************************************************
 * FUNCTION
 *  SetLeftSoftkeyAlwaysKeyUpByPen
 * DESCRIPTION
 *  Emulate Key Up event even when pen is up outside the LSK button
 *  (By default, Key Up is only generated when pen is up inside a button)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetLeftSoftkeyAlwaysKeyUpByPen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_softkey_flags_on(UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE, MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  SetRightSoftkeyAlwaysKeyUpByPen
 * DESCRIPTION
 *  Emulate Key Up event even when pen is up outside the RSK button
 *  (By default, Key Up is only generated when pen is up inside a button)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetRightSoftkeyAlwaysKeyUpByPen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_softkey_flags_on(UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE, MMI_RIGHT_SOFTKEY);
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  SetCenterSoftkeyAlwaysKeyUpByPen
 * DESCRIPTION
 *  Emulate Key Up event even when pen is up outside the center softkey
 *  (By default, Key Up is only generated when pen is up inside a button)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCenterSoftkeyAlwaysKeyUpByPen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_softkey_flags_on(UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE, MMI_CENTER_SOFTKEY);
}
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetLeftSoftkeyFunction
 * DESCRIPTION
 *  Sets the function that is called when a particular softkey event occurs
 * PARAMETERS
 *  f       [IN]        Is the function that is called
 *  k       [IN]        Is the key event (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_left_softkey_handler();
    set_left_softkey_function(f, k);
    SetInputboxLSKFunction(f);
}


/*****************************************************************************
 * FUNCTION
 *  SetRightSoftkeyFunction
 * DESCRIPTION
 *  Sets the function that is called when a particular softkey event occurs
 * PARAMETERS
 *  f       [IN]        Is the function that is called
 *  k       [IN]        Is the key event (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void SetRightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_right_softkey_handler();
    set_right_softkey_function(f, k);
}

#ifdef __MMI_WGUI_CSK_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  SetCenterSoftkeyFunction
 * DESCRIPTION
 *  Sets the function that is called when a particular softkey event occurs
 * PARAMETERS
 *  f       [IN]        Is the function that is called
 *  k       [IN]        Is the key event (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void SetCenterSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_softkey_handler(MMI_CENTER_SOFTKEY);
    set_softkey_function(f, k, MMI_CENTER_SOFTKEY);
}
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 