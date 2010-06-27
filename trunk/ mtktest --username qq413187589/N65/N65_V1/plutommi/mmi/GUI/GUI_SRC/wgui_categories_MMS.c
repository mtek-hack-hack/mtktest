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
 *  wgui_categories_MMS.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS related categories. 
 *
 *  [Category275]       MMS SMIL editor
 *
 *  Note: Most MMS screens are located in mcu\wapadp\msf_ui\ instead of here.
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
 ****************************************************************************/

#include "MMI_features.h"
#include "StdC.h"
#include "L4Dr1.h"

/* framework related include */
#include "EventsGprot.h"
#include "GlobalDefs.h"
#include "FrameworkStruct.h"
#include "EventsDef.h"
#include "Unicodexdcl.h"
#include "DebugInitDef.h"


/* gui related include */
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_softkeys.h"
#include "wgui_categories.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_MMS.h"
#include "wgui_draw_manager.h"
#include "wgui_status_icons.h"
#if defined(__MMI_TOUCH_SCREEN__)
#include "EditorPenGprot.h"
#endif 

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
#include "SmsGuiInterfaceType.h"
#endif 

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
#include "MessagesExDcl.h"
extern S32 wgui_inputbox_buffer_size;
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#ifdef __MMI_T9__
#include "T9Main.h"     /* T9SynT9WithInputBox() */
extern void InuptMethodEnterCategory5(void);
#elif defined __MMI_ZI__
extern void ZiInuptMethodEnterCategory5(void);
#elif defined __MMI_CSTAR__
extern void CstarInputMethodEnterCategory5(void);
#elif defined __MMI_KA__
extern void KonkaInuptMethodEnterCategory5(void);
#elif defined __MMI_ITAP__
/* under construction !*/
#endif 

extern void dm_set_scr_bg_image_no_draw(U16 image_id, S8 *file_name, S32 x, S32 y, U8 opacity);        /* 092005 grayscale Calvin */

/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__)
#define CAT275_MIN_LINE_HEIGHT         (26)
#elif defined(__MMI_MAINLCD_176X220__)
#define CAT275_MIN_LINE_HEIGHT         (20)
#elif defined(__MMI_MAINLCD_128X160__)
#define CAT275_MIN_LINE_HEIGHT         (19)
#else 
/* However, category 275 should not be used on 128x128 display */
#define CAT275_MIN_LINE_HEIGHT         (19)
#endif 

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef struct
{
    U32 identifier;
    wgui_cat275_draw_title_hdlr draw_title_fp;
    wgui_cat275_draw_area_hdlr draw_area_1_fp;
    wgui_cat275_draw_area_hdlr draw_area_2_fp;
    S16 draw_area_1_height;
    S16 draw_area_2_height;
    UI_filled_area *backup_normal_filler;   /* normal filler of editor */
    UI_filled_area *backup_multitap_filler;
} gui_cat275_context_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

static gui_cat275_context_struct *g_mmi_gui_cat275_context_p;

static BOOL g_mmi_gui_cat275_modified;

#define CAT275_CTX         (g_mmi_gui_cat275_context_p)

static UI_filled_area g_mmi_gui_cat275_editor_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_BORDER,
    NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

static UI_filled_area g_mmi_gui_cat275_multitap_filler = {UI_FILLED_AREA_TYPE_COLOR,
    NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
static U8 editor_scr_bg_opacity;
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */ 

/* Global variables for storing the Title bar buttons index of Category276 Screen */
#if defined(__MMI_TOUCH_SCREEN__)
U16 g_cat276_prev_btn_item_id = 0;  
U16 g_cat276_next_btn_item_id = 0;
static void DrawCat276TitleButton(U16 index);
#endif /* __MMI_TOUCH_SCREEN__ */

/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  category275_hide_multitap
 * DESCRIPTION
 *  hide multitap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category275_hide_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We fill the multitap bar across the screen instead of using MMI_multitap_x & MMI_multitap_width */
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

#ifdef __MMI_DEFAULT_THEME_3__
    c.r = 206;
    c.g = 206;
    c.b = 206;
#else /* __MMI_DEFAULT_THEME_3__ */ 
    c.r = 255;
    c.g = 255;
    c.b = 255;
#endif /* __MMI_DEFAULT_THEME_3__ */ 
    c.alpha = 100;
    /* 101805 multitap Calvin End */

    gui_reset_clip();
    /* W05.45 Adjust the height of multitap to avoid the overlap with soft key */
    gui_fill_rectangle(0, MMI_multitap_y, UI_device_width - 1, MMI_multitap_y + MMI_multitap_height - 1, c);

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, MMI_multitap_y, UI_device_width - 1, MMI_multitap_y + MMI_multitap_height + 1);
}


/*****************************************************************************
 * FUNCTION
 *  category275_header_callback
 * DESCRIPTION
 *  redraw header 
 * PARAMETERS
 *  yoffset     [IN]        offset Y
 *  clip_x1     [IN]        start x
 *  clip_y1     [IN]        start y
 *  clip_x2     [IN]        end x
 *  clip_y2     [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void category275_header_callback(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }

    if (CAT275_CTX)
    {
        ((wgui_cat275_draw_area_hdlr_ex)(CAT275_CTX->draw_area_1_fp))(CAT275_CTX->identifier, yoffset, clip_x1, clip_y1, clip_x2, clip_y2, is_draw);
    }
}


/*****************************************************************************
 * FUNCTION
 *  category275_footer_callback
 * DESCRIPTION
 *  redraw footer
 * PARAMETERS
 *  yoffset     [IN]        offset Y
 *  clip_x1     [IN]        start x
 *  clip_y1     [IN]        start y
 *  clip_x2     [IN]        end x
 *  clip_y2     [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void category275_footer_callback(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }

    if (CAT275_CTX)
    {
        ((wgui_cat275_draw_area_hdlr_ex)(CAT275_CTX->draw_area_2_fp))(CAT275_CTX->identifier, yoffset, clip_x1, clip_y1, clip_x2, clip_y2, is_draw);
    }
}


/*****************************************************************************
 * FUNCTION
 *  category275_change_callback
 * DESCRIPTION
 *  change callbakc, set modified
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category275_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_gui_cat275_modified = TRUE;
}

/* We need to sync with T9 internal state */


/*****************************************************************************
 * FUNCTION
 *  category275_sync_with_T9
 * DESCRIPTION
 *  sync with T9 internal state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category275_sync_with_T9(void)
{
#ifdef __MMI_T9__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_input_type & INPUT_TYPE_MASK)
    {
        case INPUT_TYPE_TR_BOPOMO:
        case INPUT_TYPE_SM_PINYIN:
        case INPUT_TYPE_TR_STROKE:
        case INPUT_TYPE_SM_STROKE:
        case INPUT_TYPE_SMART_UPPERCASE_ABC:
        case INPUT_TYPE_SMART_LOWERCASE_ABC:
        case INPUT_TYPE_TR_MULTITAP_BOPOMO:
        case INPUT_TYPE_SM_MULTITAP_PINYIN:

    #if defined(__MMI_T9_SPANISH__)
        case INPUT_TYPE_SMART_UPPERCASE_SPANISH:
        case INPUT_TYPE_SMART_LOWERCASE_SPANISH:
    #endif /* defined(__MMI_T9_SPANISH__) */ 

    #if defined(__MMI_T9_DANISH__)
        case INPUT_TYPE_SMART_UPPERCASE_DANISH:
        case INPUT_TYPE_SMART_LOWERCASE_DANISH:
    #endif /* defined(__MMI_T9_DANISH__) */ 

    #if defined(__MMI_T9_POLISH__)
        case INPUT_TYPE_SMART_UPPERCASE_POLISH:
        case INPUT_TYPE_SMART_LOWERCASE_POLISH:
    #endif /* defined(__MMI_T9_POLISH__) */ 

    #if defined(__MMI_T9_FRENCH__)
        case INPUT_TYPE_SMART_UPPERCASE_FRENCH:
        case INPUT_TYPE_SMART_LOWERCASE_FRENCH:
    #endif /* defined(__MMI_T9_FRENCH__) */ 
    
    #if defined(__MMI_T9_GERMAN__)
        case INPUT_TYPE_SMART_UPPERCASE_GERMAN:
        case INPUT_TYPE_SMART_LOWERCASE_GERMAN:
    #endif /* defined(__MMI_T9_GERMAN__) */ 
    
    #if defined(__MMI_T9_ITALIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_ITALIAN:
        case INPUT_TYPE_SMART_LOWERCASE_ITALIAN:
    #endif /* defined(__MMI_T9_ITALIAN__) */ 

    #if defined(__MMI_T9_VIETNAMESE__)
        case INPUT_TYPE_SMART_UPPERCASE_VIETNAMESE:
        case INPUT_TYPE_SMART_LOWERCASE_VIETNAMESE:
    #endif /* defined(__MMI_T9_VIETNAMESE__) */ 

    #if defined(__MMI_T9_INDONESIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_INDONESIAN:
        case INPUT_TYPE_SMART_LOWERCASE_INDONESIAN:
    #endif /* defined(__MMI_T9_INDONESIAN__) */ 

    #if defined(__MMI_T9_CZECH__)
        case INPUT_TYPE_SMART_UPPERCASE_CZECH:
        case INPUT_TYPE_SMART_LOWERCASE_CZECH:
    #endif /* defined(__MMI_T9_CZECH__) */ 

    #if defined(__MMI_T9_TURKISH__)
        case INPUT_TYPE_SMART_UPPERCASE_TURKISH:
        case INPUT_TYPE_SMART_LOWERCASE_TURKISH:
    #endif /* defined(__MMI_T9_TURKISH__) */ 

    #if defined(__MMI_T9_PORTUGUESE__)
        case INPUT_TYPE_SMART_UPPERCASE_PORTUGUESE:
        case INPUT_TYPE_SMART_LOWERCASE_PORTUGUESE:
    #endif /* defined(__MMI_T9_PORTUGUESE__) */ 

    #if defined(__MMI_T9_FINNISH__)
        case INPUT_TYPE_SMART_UPPERCASE_FINNISH:
        case INPUT_TYPE_SMART_LOWERCASE_FINNISH:
    #endif /* defined(__MMI_T9_FINNISH__) */ 

    #if defined(__MMI_T9_HUNGARIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_HUNGARIAN:
        case INPUT_TYPE_SMART_LOWERCASE_HUNGARIAN:
    #endif /* defined(__MMI_T9_HUNGARIAN__) */ 

    #if defined(__MMI_T9_ARABIC__)
        case INPUT_TYPE_SMART_ARABIC:
    #endif 

    #if defined(__MMI_T9_HINDI__)
        case INPUT_TYPE_SMART_HINDI:
    #endif 

    #if defined(__MMI_T9_NORWEGIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_NORWEGIAN:
        case INPUT_TYPE_SMART_LOWERCASE_NORWEGIAN:
    #endif /* defined(__MMI_T9_NORWEGIAN__) */ 

    #if defined(__MMI_T9_DUTCH__)
        case INPUT_TYPE_SMART_UPPERCASE_DUTCH:
        case INPUT_TYPE_SMART_LOWERCASE_DUTCH:
    #endif /* defined(__MMI_T9_DUTCH__) */ 

    #if defined(__MMI_T9_MALAY__)
        case INPUT_TYPE_SMART_UPPERCASE_MALAY:
        case INPUT_TYPE_SMART_LOWERCASE_MALAY:
    #endif /* defined(__MMI_T9_MALAY__) */ 
    
    #if defined(__MMI_T9_CROATIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_CROATIAN:
        case INPUT_TYPE_SMART_LOWERCASE_CROATIAN:
    #endif /* defined(__MMI_T9_CROATIAN__) */ 
    
    #if defined(__MMI_T9_SLOVAK__)
        case INPUT_TYPE_SMART_UPPERCASE_SLOVAK:
        case INPUT_TYPE_SMART_LOWERCASE_SLOVAK:
    #endif /* defined(__MMI_T9_SLOVAK__) */ 
    
    #if defined(__MMI_T9_ROMANIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_ROMANIAN:
        case INPUT_TYPE_SMART_LOWERCASE_ROMANIAN:
    #endif /* defined(__MMI_T9_ROMANIAN__) */ 
            T9SynT9WithInputBox();
            break;
    }
#endif /* __MMI_T9__ */ 
}

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  DrawCate275CategoryControlArea
 * DESCRIPTION
 *  draw category 275 control area
 * PARAMETERS
 *  coordinate      [IN]     area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate275CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(GUI_COMMON_USE_SPECIFIC_STYLE) || (defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON))
    show_title_status_icon();
#endif
    CAT275_CTX->draw_title_fp(CAT275_CTX->identifier);

    wgui_show_inputbox();
    /* W05.46 Fix Category275 Display Issue */
#if !defined(__MMI_FULL_SCREEN_EDITOR__)
    category275_hide_multitap();    /* For the first time display */
#endif 

    if (RedrawSpellingOrCandidateBoxesFunction)
    {
        RedrawSpellingOrCandidateBoxesFunction();
    }

}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory275Screen
 * DESCRIPTION
 *  Redraws the category275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory275Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    clear_screen();

    CAT275_CTX->draw_title_fp(CAT275_CTX->identifier);

#if defined(__MMI_FULL_SCREEN_EDITOR__)
    category275_hide_multitap();    /* For the first time display */
#endif 
    wgui_show_inputbox();
#if !defined(__MMI_FULL_SCREEN_EDITOR__)
    category275_hide_multitap();    /* For the first time display */
#endif 

    show_softkey_background();
    show_left_softkey();
    show_right_softkey();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (RedrawSpellingOrCandidateBoxesFunction)
    {
        RedrawSpellingOrCandidateBoxesFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetCategory275RightSoftkeyFunction
 * DESCRIPTION
 *  right softkey function
 * PARAMETERS
 *  f       [IN]        Function
 *  k       [IN]        Event type
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory275RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(k);
    wgui_inputbox_RSK_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  Category275GotoTop
 * DESCRIPTION
 *  Invoked after ShowCategory275Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Category275GotoTop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.text;

    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    category275_sync_with_T9();

    MMI_multiline_inputbox.text_offset_y = 0;
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  Category275GotoBottom
 * DESCRIPTION
 *  Invoked after ShowCategory275Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Category275GotoBottom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.text_length >= 2)
    {
        MMI_multiline_inputbox.cursor_p =
            (UI_buffer_type) ((U8*) (MMI_multiline_inputbox.text) + (MMI_multiline_inputbox.text_length - 2));
    }
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    category275_sync_with_T9();

    if (MMI_multiline_inputbox.text_height > MMI_multiline_inputbox.edit_height)
    {
        MMI_multiline_inputbox.text_offset_y = MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height;
    }
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  Category275SetUnmodified
 * DESCRIPTION
 *  Set that category 275 is unmodified.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Category275SetUnmodified(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_gui_cat275_modified = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Category275CheckIfModified
 * DESCRIPTION
 *  Get is modified
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether category 275 is modified.
 *****************************************************************************/
BOOL Category275CheckIfModified(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_gui_cat275_modified;
}


/*****************************************************************************
 * FUNCTION
 *  cat275_virtual_keypad_callback
 * DESCRIPTION
 *  virtual keypad callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat275_virtual_keypad_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_editor_resize_multiline_input_box_for_vk();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory275Screen
 * DESCRIPTION
 *  Displays the category275 screen
 * PARAMETERS
 *  identifier              [IN]        Used as parameter for the callback functions described before
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  input_type              [IN]        Type of input to use
 *  buffer                  [IN]        Buffer the input box should use.
 *  buffer_size             [IN]        Size of the buffer.
 *  vbar_width              [IN]        Width of vertical bar
 *  draw_title_fp           [IN]        Function pointer to draw the title bar
 *  draw_area_1_height      [IN]        Height of the area where picture is to be shown
 *  draw_area_1_fp          [IN]        Function to draw the picture in area1
 *  draw_area_2_height      [IN]        Text area height
 *  draw_area_2_fp          [IN]        Function to insert the text
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory275Screen(
        U32 identifier,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S16 input_type,
        U8 *buffer,
        S32 buffer_size,
        U16 vbar_width,
        wgui_cat275_draw_title_hdlr draw_title_fp,
        U16 draw_area_1_height,
        wgui_cat275_draw_area_hdlr draw_area_1_fp,
        U16 draw_area_2_height,
        wgui_cat275_draw_area_hdlr draw_area_2_fp,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory277Screen(
        identifier, 
        left_softkey, 
        left_softkey_icon, 
        right_softkey, 
        right_softkey_icon, 
        input_type, 
        buffer, 
        buffer_size, 
        vbar_width, 
        draw_title_fp, 
        draw_area_1_height,
        draw_area_1_fp,
        draw_area_2_height,
        draw_area_2_fp,
        NULL,
        NULL,
        NULL,
        NULL,
        history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory277Screen
 * DESCRIPTION
 *  Displays the category277 screen
 * PARAMETERS
 *  identifier              [IN]        Used as parameter for the callback functions described before
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  input_type              [IN]        Type of input to use
 *  buffer                  [IN]        Buffer the input box should use.
 *  buffer_size             [IN]        Size of the buffer.
 *  vbar_width              [IN]        Width of vertical bar
 *  draw_title_fp           [IN]        Function pointer to draw the title bar
 *  draw_area_1_height      [IN]        Height of the area where picture is to be shown
 *  draw_area_1_fp          [IN]        Function to draw the picture in area1
 *  draw_area_2_height      [IN]        Text area height
 *  draw_area_2_fp          [IN]        Function to insert the text
 *  text_font               [IN]        Text font
 *  text_color              [IN]        Text color
 *  selected_text_color     [IN]        Selected text color
 *  bg_color                [IN]        Background color
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory277Screen(
        U32 identifier,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S16 input_type,
        U8 *buffer,
        S32 buffer_size,
        U16 vbar_width,
        wgui_cat275_draw_title_hdlr draw_title_fp,
        U16 draw_area_1_height,
        wgui_cat275_draw_area_hdlr draw_area_1_fp,
        U16 draw_area_2_height,
        wgui_cat275_draw_area_hdlr draw_area_2_fp,
        UI_font_type *text_font,
        color *text_color,
        color *selected_text_color,
        color *bg_color,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 inputbox_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setup context */
    g_mmi_gui_cat275_context_p = OslMalloc(sizeof(gui_cat275_context_struct));
    CAT275_CTX->identifier = identifier;
    CAT275_CTX->draw_title_fp = draw_title_fp;
    CAT275_CTX->draw_area_1_fp = draw_area_1_fp;
    CAT275_CTX->draw_area_2_fp = draw_area_2_fp;
    CAT275_CTX->draw_area_1_height = draw_area_1_height;
    CAT275_CTX->draw_area_2_height = draw_area_2_height;

    /* Setup layout */
    gui_lock_double_buffer();

    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    /* Input box */
#ifdef __MMI_T9__
    InuptMethodEnterCategory5();
#elif defined __MMI_ZI__
    ZiInuptMethodEnterCategory5();
#elif defined __MMI_CSTAR__
    CstarInputMethodEnterCategory5();
#elif defined __MMI_KA__
    KonkaInuptMethodEnterCategory5();
#elif defined __MMI_ITAP__
/* under construction !*/
#endif 

    register_hide_multitap(category275_hide_multitap);

    wgui_setup_inputbox_ext(0, MMI_content_y, MMI_content_width,
#if defined(__MMI_FULL_SCREEN_EDITOR__)
                            MMI_content_height,
#else 
                            MMI_content_height - MMI_multitap_height,
#endif 
                            buffer, buffer_size,
                            MMI_CATEGORY275_ID, get_string(right_softkey), get_image(right_softkey_icon),
                            input_type, history_buffer, 1, UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE,
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        // TODO: tune style 4
                            (S16) (draw_area_1_height + draw_area_2_height + CAT275_MIN_LINE_HEIGHT * 2),
#else 
                            (S16) (draw_area_1_height + draw_area_2_height + CAT275_MIN_LINE_HEIGHT),
#endif 
                            CAT275_MIN_LINE_HEIGHT, (S16) draw_area_1_height, (S16) draw_area_2_height, NULL);

#if defined(__MMI_FULL_SCREEN_EDITOR__)
    inputbox_height = MMI_content_height - wgui_inputbox_information_bar_height;
#else 
    inputbox_height = MMI_content_height - MMI_multitap_height - wgui_inputbox_information_bar_height;
#endif 
    if (MMI_multiline_inputbox.height > inputbox_height)
    {
        gui_resize_multi_line_input_box(&MMI_multiline_inputbox, MMI_multiline_inputbox.width, inputbox_height);
    }

    /* Input box attributes */
    MMI_multiline_inputbox.header_callback = category275_header_callback;
    MMI_multiline_inputbox.footer_callback = category275_footer_callback;
    MMI_multiline_inputbox.change_callback = category275_change_callback;

    /* Disable editor border and set background color of multitap */
    CAT275_CTX->backup_normal_filler = MMI_multiline_inputbox.normal_filler;

    if (MMI_multiline_inputbox.normal_filler)
    {
        if ((MMI_multiline_inputbox.normal_filler->flags & UI_FILLED_AREA_MASK_TYPE) == UI_FILLED_AREA_TYPE_COLOR)
        {
            g_mmi_gui_cat275_editor_filler.flags = UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_BORDER;
            if (bg_color != NULL)
            {
                g_mmi_gui_cat275_editor_filler.c = *bg_color;
            }
            else
            {
                g_mmi_gui_cat275_editor_filler.c = MMI_multiline_inputbox.normal_filler->c;
            }
            
            /* Tricky. Use multitap text color as editor border color */
            g_mmi_gui_cat275_editor_filler.border_color = *current_MMI_theme->multitap_normal_text_color;

            MMI_multiline_inputbox.normal_filler = (UI_filled_area*)&g_mmi_gui_cat275_editor_filler;       
        }
   }

    if (text_color != NULL)
    {
        MMI_multiline_inputbox.normal_text_color = *text_color;
    }
    
    if (selected_text_color != NULL)
    {
        MMI_multiline_inputbox.selected_text_color = *selected_text_color;
    }

    if (text_font != NULL)
    {
        MMI_multiline_inputbox.text_font = *text_font;
    }

    CAT275_CTX->backup_multitap_filler = current_multitap_input_theme->f;
    g_mmi_gui_cat275_multitap_filler = *(current_multitap_input_theme->f);
    current_multitap_input_theme->f = (UI_filled_area*)&g_mmi_gui_cat275_multitap_filler;
    set_MMI_multitap_theme();

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    dm_get_scr_bg_opacity(&editor_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    gui_unlock_double_buffer();

    /* Setup standard category handler */
    ExitCategoryFunction = ExitCategory275Screen;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory275History, GetCategory275HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY275_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32flags |= DM_SHOW_VKPAD;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate275CategoryControlArea);
    dm_register_vkpad_callback(cat275_virtual_keypad_callback);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory275Screen
 * DESCRIPTION
 *  Exits the category275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory275Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset UI */
    set_MMI_current_input_type();
    /* wgui_close_inputbox may call the header and footer, but we don't want to blt to LCD */
    gui_lock_double_buffer();
//    reset_softkeys();
    reset_multitaps();
    wgui_close_inputbox();
    gui_unlock_double_buffer();

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_set_scr_bg_opacity(editor_scr_bg_opacity);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    /*
     * Release context after other deinitialization routine
     * * because they might refer to CAT275_CTX
     */

    MMI_multiline_inputbox.normal_filler = CAT275_CTX->backup_normal_filler;
    current_multitap_input_theme->f = CAT275_CTX->backup_multitap_filler;
    set_MMI_multitap_theme();

    OslMfree(g_mmi_gui_cat275_context_p);
    g_mmi_gui_cat275_context_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory275HistorySize
 * DESCRIPTION
 *  Gets the size of the history buffer for category275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory275HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(multiline_inputbox_category_history);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory275History
 * DESCRIPTION
 *  Gets the history buffer for category275 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  Pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory275History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_multiline_inputbox_category_history(MMI_CATEGORY275_ID, history_buffer, MMI_current_input_type);
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  AppendCategory275String
 * DESCRIPTION
 *  append the string in category 275 (editor) text
 * PARAMETERS
 *  input_type          [IN]        Input ype
 *  buffer              [IN]        Buffer
 *  buffer_size         [IN]        Buffer isze
 *  s                   [IN]        String
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void AppendCategory275String(S16 input_type, U8 *buffer, S32 buffer_size, U8 *s, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_multiline_inputbox_append_string(input_type, buffer, buffer_size, s, history_buffer, MMI_CATEGORY275_ID, NULL);
}


#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) || defined(__MMI_SMART_MESSAGE_MT__)
/*****************************************************************************
 * FUNCTION
 *  cat275NSM_virtual_keypad_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat275NSM_virtual_keypad_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_editor_resize_multiline_input_box_for_vk();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategoryNSM275Screen
 * DESCRIPTION
 *  Displays the categoryNSM275 screen
 * PARAMETERS
 *  identifier              [IN]        Used as parameter for the callback functions described before
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  input_type              [IN]        Type of input to use
 *  buffer                  [IN]        Buffer the input box should use.
 *  buffer_size             [IN]        Size of the buffer.
 *  vbar_width              [IN]        Width of vertical bar
 *  draw_title_fp           [IN]        Function pointer to draw the title bar
 *  draw_area_1_height      [IN]        Height of the area where picture is to be shown
 *  draw_area_1_fp          [IN]        Function to draw the picture in area1
 *  draw_area_2_height      [IN]        Text area height
 *  draw_area_2_fp          [IN]        Function to insert the text
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
extern nsm_msg_struct g_nsm_msg_context;
extern S32 mmi_nsm_get_infobar_maxlen(void);
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

void ShowCategoryNSM275Screen(
        U32 identifier,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S16 input_type,
        U8 *buffer,
        S32 buffer_size,
        U16 vbar_width,
        wgui_cat275_draw_title_hdlr draw_title_fp,
        U16 draw_area_1_height,
        wgui_cat275_draw_area_hdlr draw_area_1_fp,
        U16 draw_area_2_height,
        wgui_cat275_draw_area_hdlr draw_area_2_fp,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 inputbox_height;
    U32 flagID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setup context */
    g_mmi_gui_cat275_context_p = OslMalloc(sizeof(gui_cat275_context_struct));
    CAT275_CTX->identifier = identifier;
    CAT275_CTX->draw_title_fp = draw_title_fp;
    CAT275_CTX->draw_area_1_fp = draw_area_1_fp;
    CAT275_CTX->draw_area_2_fp = draw_area_2_fp;
    CAT275_CTX->draw_area_1_height = draw_area_1_height;
    CAT275_CTX->draw_area_2_height = draw_area_2_height;

    /* Setup layout */
    gui_lock_double_buffer();

    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    /* Input box */
#ifdef __MMI_T9__
    InuptMethodEnterCategory5();
#elif defined __MMI_ZI__
    ZiInuptMethodEnterCategory5();
#elif defined __MMI_CSTAR__
    CstarInputMethodEnterCategory5();
#elif defined __MMI_KA__
    KonkaInuptMethodEnterCategory5();
#elif defined __MMI_ITAP__
/* under construction !*/
#endif 

    register_hide_multitap(category5_hide_multitap);    /* JP : To fix Issue 642 */

    flagID = UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED | UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;

    wgui_setup_inputbox_ext(0, MMI_content_y, MMI_content_width,
#if defined(__MMI_FULL_SCREEN_EDITOR__)
                            MMI_content_height,
#else 
                            MMI_content_height - MMI_multitap_height,
#endif 
                            buffer, buffer_size, MMI_CATEGORY275_ID, get_string(right_softkey), get_image(right_softkey_icon), input_type, history_buffer, 1, flagID,   /* PMT JAI : 05012005 FOR NSM PHASE-II */
                            14, 14,
                            draw_area_1_height, draw_area_2_height, NULL);

#if defined(__MMI_FULL_SCREEN_EDITOR__)
    inputbox_height = MMI_content_height - wgui_inputbox_information_bar_height;
#else 
    inputbox_height = MMI_content_height - MMI_multitap_height - wgui_inputbox_information_bar_height;
#endif 
    if (MMI_multiline_inputbox.height > inputbox_height)
    {
        gui_resize_multi_line_input_box(&MMI_multiline_inputbox, MMI_multiline_inputbox.width, inputbox_height);
    }

    /* Input box attributes */
    MMI_multiline_inputbox.header_callback = category275_header_callback;
    MMI_multiline_inputbox.footer_callback = category275_footer_callback;
    MMI_multiline_inputbox.change_callback = category275_change_callback;

    current_multitap_input_theme->f = (UI_filled_area*)&g_mmi_gui_cat275_multitap_filler;
    set_MMI_multitap_theme();

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    dm_get_scr_bg_opacity(&editor_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));  
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    gui_unlock_double_buffer();

    /* Setup standard category handler */
    ExitCategoryFunction = ExitCategoryNSM275Screen;    /* JP : after Justin suggestion */

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
    wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);

    if (g_nsm_msg_context.is_template_insert == TRUE)
    {
        MMI_multiline_inputbox.cursor_p = (MMI_multiline_inputbox.text + g_nsm_msg_context.cursor_pos_after_template);
        g_nsm_msg_context.is_template_insert = FALSE;
        g_nsm_msg_context.cursor_pos_after_template = 0;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
    wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    dm_setup_category_functions(dm_redraw_category_screen, GetCategory275History, GetCategory275HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY_NSM275;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32flags |= DM_SHOW_VKPAD;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate275CategoryControlArea);
    dm_register_vkpad_callback(cat275NSM_virtual_keypad_callback);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategoryNSM275Screen
 * DESCRIPTION
 *  Exits the categoryNSM275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategoryNSM275Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset UI */
    set_MMI_current_input_type();
    reset_softkeys();
    reset_multitaps();
    wgui_close_inputbox();

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_set_scr_bg_opacity(editor_scr_bg_opacity);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    /*
     * Release context after other deinitialization routine
     * * because they might refer to CAT275_CTX
     */

    set_MMI_multitap_theme();

    OslMfree(g_mmi_gui_cat275_context_p);
    g_mmi_gui_cat275_context_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategoryNSM275Screen
 * DESCRIPTION
 *  Redraws the categoryNSM275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategoryNSM275Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    clear_screen();

    show_title_status_icon();
    CAT275_CTX->draw_title_fp(CAT275_CTX->identifier);

#if 0
#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_SMART_MESSAGE_MT__)
/* under construction !*/
/* under construction !*/
#endif
#endif /* 0 */ 

#if defined(__MMI_FULL_SCREEN_EDITOR__)
    category5_hide_multitap();
#endif 
    wgui_show_inputbox();
#if !defined(__MMI_FULL_SCREEN_EDITOR__)
    category5_hide_multitap();
#endif 
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (RedrawSpellingOrCandidateBoxesFunction)
    {
        RedrawSpellingOrCandidateBoxesFunction();
    }
}

#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) || defined(__MMI_SMART_MESSAGE_MT__) */ 

/* deepali view screen */
#define CAT276_SLIDING_BAR_H_SPACE     8
#define CAT276_SLIDING_BAR_V_SPACE     4

#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__

#define CAT276_JMMS_LEFT_ARROW_FLAG    0x00000008       /* 8 */
#define CAT276_JMMS_RIGHT_ARROW_FLAG   0x00000010       /* 16 */
#ifdef __MMI_MAINLCD_128X160__
/* This macro is required for timer text gap from boundary of timerbar */
#define CAT276_TIMER_BAR_GAP_128X160    2
/* This macro is required for right side gap of timer bar for 128X160 phone model. */
#define CAT276_TIMER_BAR_RIGHT_MARGIN_128X160   3
/* This filler is used to fill the timerbar */
static const UI_filled_area mms_title_bar_counter_filler =
    {UI_FILLED_AREA_TYPE_CROSS_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    NULL,
    NULL,
    {120, 120, 120, 100},
    {0, 0, 0, 0},
    {100, 100, 100, 100},
    {0, 0, 0, 0},
    0
};
#elif __MMI_MAINLCD_240X320__
/* These macro is required for progerss bar gap from left and right side, and from top and bottom */
#define CAT276_IMG_PROGRESS_GAP_X 8
#define CAT276_IMG_PROGRESS_GAP_Y 4
/* This macro is used for default color for progress bar */
#define CAT276_MMS_NEW_PROGRESS_BAR_COLOR   148, 227, 255
#else 
#define CAT276_IMG_PROGRESS_GAP_X 4
#define CAT276_IMG_PROGRESS_GAP_Y 4
#define CAT276_MMS_NEW_PROGRESS_BAR_COLOR   148, 227, 255
#endif 
#endif /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 
/*
 * This Blend Effect is required for mixing the Current MMI Theme Title Color with BLACK color
 * in a ratio defined by the CAT276_BLEND_EFFECT macro
 */
#define CAT276_BLEND_EFFECT            20


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory276Screen
 * DESCRIPTION
 *  redraw category screen 276
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory276Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)
    S32 left_arrow_width = 0, left_arrow_height = 0, right_arrow_width = 0, right_arrow_height = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    clear_screen();
    draw_title();
#if defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)
    /* Here we are showing the left and right button incase of non touch screen phone model. This button is not apply on 128x160 phone model */
    gui_measure_image(get_image(LEFT_RED_ARROW), &left_arrow_width, &left_arrow_height);
    gui_measure_image(get_image(RIGHT_RED_ARROW), &right_arrow_width, &right_arrow_height);
    gui_show_image(
        MMI_TITLEBAR_BUTTON_GAP,
        MMI_title_y + ((MMI_title_height - left_arrow_height) >> 1),
        (PU8) GetImage(LEFT_RED_ARROW));
    gui_show_image(
        (UI_device_width - MMI_TITLEBAR_BUTTON_GAP - MMI_TITLEBAR_BUTTON_WIDTH),
        MMI_title_y + ((MMI_title_height - right_arrow_height) >> 1),
        (PU8) GetImage(RIGHT_RED_ARROW));
#endif /* defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__) */ 
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}


extern U16 title_bg_id;
extern void cat129_clear_icon_bg(void *button);


/*****************************************************************************
 * FUNCTION
 *  cat276_clear_icon_bg_title
 * DESCRIPTION
 *  clear icon background title
 * PARAMETERS
 *  button      [IN]     icontext_button
 * RETURNS
 *  void
 *****************************************************************************/
void cat276_clear_icon_bg_title(void *button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = (icontext_button*) button;
    S32 x1 = b->x;
    S32 y1 = b->y;
    S32 x2 = b->x + b->width - 1;
    S32 y2 = b->y + b->height - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2 + 1, y2 + 1);
    gdi_draw_solid_rect(MMI_title_x, MMI_title_y, MMI_title_x + MMI_title_width - 1, MMI_title_y + MMI_title_height - 1, GDI_COLOR_WHITE);
    if (title_bg_id != 0)
    {
        gdi_image_draw_id(MMI_title_x, MMI_title_y, title_bg_id);
    }
    else
    {
        gui_draw_filled_area(
            MMI_title_x,
            MMI_title_y,
            MMI_title_x + MMI_title_width - 1,
            MMI_title_y + MMI_title_height - 1,
            current_UI_theme->window_title_theme->active_filler);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory276Screen
 * DESCRIPTION
 *  Show category 276
 * PARAMETERS
 *  title                   [IN]        Title string
 *  title_icon              [IN]        Title icon
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory276Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    MMI_disable_title_shortcut_display = 1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    if (gOnFullScreen & MMI_LEAVE_FULL_SCREEN)
    {
        gOnFullScreen = MMI_IN_NORMAL_SCREEN;
    }

    hide_status_icon_bar(0);
    hide_status_icon_bar(1);

    MMI_title_icon = (PU8) get_image(title_icon);
    MMI_title_string = (UI_string_type) title;

#if defined(__MMI_TOUCH_SCREEN__)
    if (wgui_is_touch_title_bar_buttons())
    {
        g_cat276_prev_btn_item_id = dm_add_button(
                                        NULL,
                                        get_image(LEFT_RED_ARROW),
                                        get_image(LEFT_RED_ARROW),
                                        cat276_clear_icon_bg_title);
        g_cat276_next_btn_item_id = dm_add_button(
                                        NULL,
                                        get_image(RIGHT_RED_ARROW),
                                        get_image(RIGHT_RED_ARROW),
                                        cat276_clear_icon_bg_title);
        title_bg_id = IMAGE_VIEW_TITLEBAR_BG;   /* for showing different title bar. */
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
#if defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)
    /* Incase of non touch screen phone model we are showing the same title bar as it is comes in touch screen phone model */
    title_bg_id = IMAGE_VIEW_TITLEBAR_BG;
#endif /* defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__) */ 
    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory276Screen;

    #if defined(__MMI_TOUCH_SCREEN__)
    if (wgui_is_touch_title_bar_buttons())
    {
        /* register the handler for pen event down istead of pen event up */
        dm_register_button_functions(g_cat276_prev_btn_item_id, KEY_EVENT_UP, gMMI_touch_title_button1_down_handler);
        dm_register_button_functions(g_cat276_next_btn_item_id, KEY_EVENT_UP, gMMI_touch_title_button2_down_handler);
    }
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY276_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    #if !defined(__MMI_TOUCH_SCREEN__)
    dm_register_category_controlled_callback(dm_category_276_controlled_area);
    #endif /* __MMI_TOUCH_SCREEN__ */
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  dm_category_276_controlled_area
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void dm_category_276_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RedrawCategory276Screen();
}


#if defined(__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  DrawCat276TitleButton
 * DESCRIPTION
 *  This function is used to draw the buttons
 * PARAMETERS
 *  index       [IN]        Index of the buttons to be drawn
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCat276TitleButton(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    icontext_button *b;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    b = dm_get_button(index);
    gdi_layer_push_clip();
    gdi_layer_set_clip(b->x, b->y, b->x + b->width - 1, b->y + b->height - 1);
    gui_show_icontext_button(b);
    gdi_layer_pop_clip();
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  DrawCat276Title
 * DESCRIPTION
 *  Draw category 276 title
 * PARAMETERS
 *  title       [IN]        Title to be Displayed
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCat276Title(U8 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)
    S32 left_arrow_width = 0, left_arrow_height = 0, right_arrow_width = 0, right_arrow_height = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    MMI_title_string = (UI_string_type) title;
    draw_title();
#if defined(__MMI_TOUCH_SCREEN__)
    if (wgui_is_touch_title_bar_buttons())
    {
        DrawCat276TitleButton(g_cat276_prev_btn_item_id);
        DrawCat276TitleButton(g_cat276_next_btn_item_id);
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    /*  we are showing the title bar of non touch screen phone same as touch screen phone 
       The following lines for showing left and right arrow for non touch screen phone and this title bar
       is not applicable for S880(128x160) phone */
#if defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)
    /* Here we are showing the left and right button incase of non touch screen phone model. This button is not apply on 128x160 phone model */
    gui_measure_image(get_image(LEFT_RED_ARROW), &left_arrow_width, &left_arrow_height);
    gui_measure_image(get_image(RIGHT_RED_ARROW), &right_arrow_width, &right_arrow_height);
    gui_show_image(
        MMI_TITLEBAR_BUTTON_GAP,
        MMI_title_y + ((MMI_title_height - left_arrow_height) >> 1),
        (PU8) GetImage(LEFT_RED_ARROW));
    gui_show_image(
        (UI_device_width - MMI_TITLEBAR_BUTTON_GAP - MMI_TITLEBAR_BUTTON_WIDTH),
        MMI_title_y + ((MMI_title_height - right_arrow_height) >> 1),
        (PU8) GetImage(RIGHT_RED_ARROW));
#endif /* defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__) */ 
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_title_x,
        MMI_title_y,
        MMI_title_x + MMI_title_width - 1,
        MMI_title_y + MMI_title_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  DrawCat276ButtonBarArrow
 * DESCRIPTION
 *  Draw category 276 button bar arrows.
 * PARAMETERS
 *  curr_page       [IN]        Curr page number
 *  page_count      [IN]        Total page count
 * RETURNS
 *  void
 *****************************************************************************/
/* this function is used to draw left and right arrow as per the no of slide information on Buttonbar */
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
void DrawCat276ButtonBarArrow(U32 curr_page, U32 page_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If page count is more then one, only that condition we show left or right button on button bar */
    if (page_count > 1)
    {
        show_softkey_background();

        if (curr_page == 1)
        {
            /* if we are on first page then we show only right arrow on button bar */
            draw_arrow_indication(0, CAT276_JMMS_RIGHT_ARROW_FLAG, 0, 0);
        }
        else if (curr_page == page_count)
        {
            /* If we are on last page then we show only left arrow */
            draw_arrow_indication(CAT276_JMMS_LEFT_ARROW_FLAG, 0, 0, 0);
        }
        else
        {
            /* If we are in between first and middle then we show both left and right arrow */
            draw_arrow_indication(CAT276_JMMS_LEFT_ARROW_FLAG, 0, 0, 0);
            draw_arrow_indication(0, CAT276_JMMS_RIGHT_ARROW_FLAG, 0, 0);
        }

        redraw_left_softkey();
        redraw_right_softkey();
    }
}
#endif /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 
/*****************************************************************************
 * FUNCTION
 *  DrawCat276SlidingBar
 * DESCRIPTION
 *  Draw category 276 sliding bar.
 * PARAMETERS
 *  percentage      [IN]        percentage of silding bar
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
void DrawCat276SlidingBar(U8 percentage, U32 time)
#else 
void DrawCat276SlidingBar(U8 percentage)
#endif 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, x3;
#ifndef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    color bg_color, *bar_border_color, bar_filler_color, *bar_unfill_color;
#endif

#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    U32 min = 0, sec = 0;
    S8 buf[20] = {0, };
    U16 unicode_str[20] = {0, };
    S32 timer_text_width = 0, timer_text_height = 0;
#if !defined(__MMI_MAINLCD_128X160__)	
    color text_color = {0, 0, 0, 100};
    S32 progress_bar_height = 0, progress_bar_width = 0;
#endif
#endif /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    /* Here we are calculating the time in min and sec which we show on timer bar */
    time = time / 1000;
    min = time / 60;
    sec = time % 60;
    sprintf(buf, "%01d:%02d", min, sec);
    mmi_asc_to_ucs2((S8 *) unicode_str, buf);
    gui_set_font(&MMI_medium_font);
    gui_measure_string((UI_string_type) unicode_str, &timer_text_width, &timer_text_height);
#endif /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 

#if defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__)
#ifdef __MMI_MAINLCD_128X160__
    /* we are showing the timer bar at the left side of title bar and in screen size 128x160 phone model doesn't show status bar
       so we are setting the value of timer bar according to that specification */
    x1 = UI_device_width - timer_text_width - (2 * CAT276_TIMER_BAR_GAP_128X160) -
        CAT276_TIMER_BAR_RIGHT_MARGIN_128X160;
    y1 = 0;
    x2 = UI_device_width - CAT276_TIMER_BAR_RIGHT_MARGIN_128X160;
    y2 = y1 + MMI_TITLE_HEIGHT - 1;
#else /* __MMI_MAINLCD_128X160__ */ 
    /*  except screen size 128x160 phone model, we are showing the timer bar above the buttonbar and the height and width
       of the timer bar is same as it is in title bar */
    x1 = 0;
    y1 = UI_device_height - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT - 1;
#endif /* __MMI_MAINLCD_128X160__ */ 
#else /* defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) */ 
    x1 = 0;
    y1 = 0;
    x2 = UI_device_width - 1;
    y2 = MMI_title_y - 1;
#endif /* defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) */ 

    gui_lock_double_buffer();

#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
#ifdef __MMI_MAINLCD_128X160__

    gui_push_text_clip();
    gui_set_text_clip(x1, y1, x2, y2);

    draw_title();
    gui_draw_filled_area(x1, y1, x2, y2, (UI_filled_area *)&mms_title_bar_counter_filler);

    gui_set_font((UI_font_type) (current_MMI_theme->window_title_font));
    gui_set_text_color(*current_MMI_theme->title_shortcut_text_color);

    /* Move cursor at the place where we show time in timer bar */
    if(r2lMMIFlag)
    {
        gui_move_text_cursor(x2 - CAT276_TIMER_BAR_GAP_128X160, (MMI_TITLE_HEIGHT - timer_text_height) >> 1);
    }
    else
    {
        gui_move_text_cursor(x1 + CAT276_TIMER_BAR_GAP_128X160, (MMI_TITLE_HEIGHT - timer_text_height) >> 1);
    }
    gui_print_text(unicode_str);

    gui_pop_text_clip();

#else /* __MMI_MAINLCD_128X160__ */ /* except 128x160 screen. */

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    gui_fill_rectangle(x1, y1, x2, y2, *(current_MMI_theme->UI_white_color));

    gui_measure_image(get_image(IMG_ID_JMMS_NEW_VIEW_SCREEN_PROGRESS_BAR), &progress_bar_width, &progress_bar_height);

    gui_show_image((UI_device_width - progress_bar_width) >> 1, y1 + ((MMI_TITLE_HEIGHT - progress_bar_height) / 2),
                   (PU8) GetImage(IMG_ID_JMMS_NEW_VIEW_SCREEN_PROGRESS_BAR));

    /*  This x1,y1,x2,y2 calculation are for progress bar parameters */
    x1 = (UI_device_width - progress_bar_width) / 2 + CAT276_IMG_PROGRESS_GAP_X;
    x2 = UI_device_width - (UI_device_width - progress_bar_width) / 2 - CAT276_IMG_PROGRESS_GAP_X;
    y1 = (UI_device_height - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT) + (MMI_TITLE_HEIGHT - progress_bar_height) / 2 +
        CAT276_IMG_PROGRESS_GAP_Y;
    y2 = (UI_device_height - MMI_BUTTON_BAR_HEIGHT) - (MMI_TITLE_HEIGHT - progress_bar_height) / 2 -
        CAT276_IMG_PROGRESS_GAP_Y;

    if (percentage > 100)
    {
        percentage = 100;
    }

    x3 = x1 + (((x2 - x1) * percentage) / 100);

    gui_fill_rectangle(x1, y1, x3, y2, gui_color(CAT276_MMS_NEW_PROGRESS_BAR_COLOR));

    gui_push_text_clip();
    gui_set_text_clip(x1, y1, x2, y2);

    gui_set_font(&MMI_medium_font);
    gui_set_text_color(text_color);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor((UI_device_width + timer_text_width) >> 1,
                             (UI_device_height - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT) +
                             ((MMI_TITLE_HEIGHT - timer_text_height) >> 1));
    }
    else
    {
        gui_move_text_cursor((UI_device_width - timer_text_width) >> 1,
                             (UI_device_height - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT) +
                             ((MMI_TITLE_HEIGHT - timer_text_height) >> 1));
    }
    gui_print_text(unicode_str);

    gui_pop_text_clip();
    gui_pop_clip();
#endif /* __MMI_MAINLCD_128X160__ */ 
#else /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    bg_color = current_MMI_theme->title_filler->c;

    gui_fill_rectangle(x1, y1, x2, y2, gui_color(bg_color.r, bg_color.g, bg_color.b));

    x1 += CAT276_SLIDING_BAR_H_SPACE;
    y1 += CAT276_SLIDING_BAR_V_SPACE;
    x2 -= CAT276_SLIDING_BAR_H_SPACE;
    y2 -= CAT276_SLIDING_BAR_V_SPACE;

    bar_border_color = current_MMI_theme->UI_black_color;

    gui_line(x1, y1 + 1, x1, y2 - 1, *bar_border_color);
    gui_line(x2, y1 + 1, x2, y2 - 1, *bar_border_color);
    gui_line(x1 + 1, y1, x2 - 1, y1, *bar_border_color);
    gui_line(x1 + 1, y2, x2 - 1, y2, *bar_border_color);

    x1++;
    y1++;
    x2--;
    y2--;

    if (percentage > 100)
    {
        percentage = 100;
    }

    x3 = x1 + (((x2 - x1) * percentage) / 100);

    /* Get the Current Theme Title Color */
    bar_filler_color = *(current_MMI_theme->title_text_color);

    /* Get the Unfilll Color */
    bar_unfill_color = current_MMI_theme->UI_white_color;

    /* 
     * Mix Current Theme Title Text Color with Black Color in a ratio defined by  CAT276_BLEND_EFFECT 
     * This mixing is required to differentiate between slider background color with slider color in 
     * case the bar_unfill_color matches with current_MMI_theme->title_text_color
     */
    bar_filler_color =
        gui_blend_two_color(bar_filler_color, *(current_MMI_theme->UI_black_color), 100 - CAT276_BLEND_EFFECT,
                            CAT276_BLEND_EFFECT);

    /* Now fill the New color for drawing the slider */
    gui_fill_rectangle(x1, y1, x3, y2, bar_filler_color);

    /* And draw the Unfill Color for rest of the slider */
    gui_fill_rectangle(x3 + 1, y1, x2, y2, *bar_unfill_color);

    gui_pop_clip();
#endif /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 

    gui_unlock_double_buffer();

#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
#ifdef __MMI_MAINLCD_128X160__
    gui_BLT_double_buffer(x1, y1, x2, y2);
#else /* __MMI_MAINLCD_128X160__ */ 
    gui_BLT_double_buffer(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT, UI_device_width - 1,
                          UI_device_height - MMI_BUTTON_BAR_HEIGHT - 1);
#endif /* __MMI_MAINLCD_128X160__ */ 
#else /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, MMI_title_y - 1);
#endif /* __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory276Screen
 * DESCRIPTION
 *  Exit category276 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory276Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();
    
#if defined(__MMI_TOUCH_SCREEN__)
    if (wgui_is_touch_title_bar_buttons())
    {
        title_bg_id = 0;
        wgui_reset_touch_title_bar_buttons();
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    /* when we come out from the MMS view screen then reset the value of title_bg_id to zero which we set in showcategory276screen */
#if defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)
    /* At the exit of MMS view screen we have to reset the value of title_bg_id to zero so that another screen can show the title
       background according to their requirement */
    title_bg_id = 0;
#endif /* defined(__MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__) */ 
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    leave_full_screen();
}

