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
 *   gui_color_slider.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Picture Editor related categoreis.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

#include "CustThemesRes.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "gui.h"
#include "wgui_fixed_menus.h"

typedef struct _color_slider
{
    U16 flags;
    S32 x, y;
    S32 width, height;
    S32 range;
    S32 value;
    S32 swidth, sheight;
    S32 sx1, sy1, sx2, sy2;
    UI_filled_area *filler;
    U16 simage;

    void (*shide) (S32 x1, S32 y1, S32 x2, S32 y2);

#ifdef __MMI_TOUCH_SCREEN__
    gui_slide_control_pen_state_enum pen_state;
#endif 

} color_slider;

extern void gui_color_slider_create(color_slider *s, S32 x, S32 y, S32 width, S32 height);
extern void gui_color_slider_set_range(color_slider *s, S32 range);
extern void gui_color_slider_set_value(color_slider *s, S32 value);
extern void gui_color_slider_set_filler(color_slider *s, UI_filled_area *f);
void gui_color_slider_set_hide_function(color_slider *s, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_color_slider_show(color_slider *s);
extern void gui_color_slider_hide(color_slider *s);

#ifdef __MMI_TOUCH_SCREEN__
extern void wgui_color_slider_translate_pen_position(
                color_slider *s,
                S16 x,
                S32 *value,
                gui_slide_control_pen_state_enum *state);
extern BOOL wgui_color_slider_translate_pen_event(
                color_slider *s,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_slide_control_pen_event_enum *slide_event,
                gui_pen_event_param_struct *slide_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 

