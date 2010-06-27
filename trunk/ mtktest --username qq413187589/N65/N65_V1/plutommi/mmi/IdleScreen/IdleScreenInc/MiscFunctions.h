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
 * MiscFunctions.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      MiscFunctions.h
   Author:        manju
   Date Created:  August-14-2002
   Contains:      Contains miscellaneous functions
**********************************************************************************/

#ifndef __MISCFUNCTIONS_H__
#define __MISCFUNCTIONS_H__

#include "gui.h"
#include "gui_buttons.h"
#include "gui_scrollbars.h"
#include "gui_inputs.h"
#include "gui_generic_menuitems.h"
#include "gui_fixed_menuitems.h"
#include "gui_generic_menus.h"
#include "gui_fixed_menus.h"
#include "gui_windows.h"
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_softkeys.h"
#include "wgui_menu_shortcuts.h"
#include "wgui_fixed_menus.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_inputs.h"
#include "wgui_categories.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
    extern S32 ANALOG_CLOCK_DIAL_X;
    extern S32 ANALOG_CLOCK_DIAL_Y;
#ifdef __MMI_MAINLCD_128X128__
#define ANALOG_CLOCK_DIAL_WIDTH              55
#define ANALOG_CLOCK_DIAL_HEIGHT          55
#else
#define ANALOG_CLOCK_DIAL_WIDTH              77
#define ANALOG_CLOCK_DIAL_HEIGHT          77
#endif
#define THEME_MENU_SCREENID               903
#define DEMO_ABOUT_SCREENID               904
#define DEMO_UNDERCONSTRUCTION_SCREENID      905
#define SCR_OPEN_SCREEN_ID             906
    /* 0: Images are enabled. 1: Images are disabled   */
#define DEMO_DISABLE_IMAGES               0

    /* Demo timeout values                       */
#define DEMO_OPENING_ANIMATION_TIMEOUT    100
#define DEMO_OPENING_WAIT_TIMEOUT         1000
#define DEMO_OPENING_COPYRIGHT_TIMEOUT    5000
#define DEMO_OPENING_CUSTOM_LOGO_TIMEOUT  2000

#define PWRON_DISPLAY_SUCCESS    0xff
#define PWRON_DISPLAY_FAILED     0x00
#define PWRON_DISPLAY_PLAYING    0x01

#define PWROFF_DISPLAY_SUCCESS   0xff
#define PWROFF_DISPLAY_FAILED    0x00
#define PWROFF_DISPLAY_PLAYING   0x01

    /* Global functions  */

    extern void (*redraw_current_demo) (void);
    extern void goto_custom_startup_screen(void);
    extern void goto_demo_about(void);
    extern void exit_custom_startup_screen(void);
    extern void EntryIdleScreen(void);
    extern void EntryMainMenuFromIdleScreen(void);  /* Robin 1223 */
    extern void goto_main_menu(void);
    extern void goto_theme_menu(void);
    extern void EntryGFXDemo(void);
    extern void ExitFastOpenScreen(void);

    /* Idle Screen related functions: 
       These will be moved to a seperate header later  */

    extern void idle_screen_charger_connected(void);
    extern void idle_screen_charger_disconnected(void);
    extern void ExitIdleScreen(void);
    extern void ShowWelcomeScr(void);

    /* power on interface */
    extern void mmi_pwron_stop_animation(void);
    extern void mmi_pwron_exception_check_display(void);

#if defined(__MMI_VIDEO_PLAYER__)
    extern void mmi_pwron_pause_video(void);
    extern void mmi_pwron_resume_video(void);
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 

    /* shutdown interface */
    extern void mmi_shutdown_stop_animation(void);

#ifdef __cplusplus
}
#endif 

#endif /* __MISCFUNCTIONS_H__ */ 

