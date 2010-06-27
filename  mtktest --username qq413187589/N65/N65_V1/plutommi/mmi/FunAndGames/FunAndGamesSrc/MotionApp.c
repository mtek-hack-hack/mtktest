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
 * Filename:
 * ---------
 *  MotionApp.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Motion Game 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_MOTION_APP__

#include "GameInc.h"    /* Game Include */
#include "GameFramework.h"      /* for load game settings */
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_FUNANDGAMES_ICON */

#ifdef IS_DICE_BASE_MOTIONGAME
#include "MotionDiceGprots.h"
#include "MotionDiceResDef.h"
#endif /* IS_DICE_BASE_MOTIONGAME */ 

#ifdef IS_DJ_BASE_MOTIONGAME
#include "MotionDJGprots.h"
#include "MotionDJResDef.h"
#endif /* IS_DJ_BASE_MOTIONGAME */ 

/****************************************************************************
* Macro                                                                
*****************************************************************************/
#define GAME_SWITCH(index, func_ptr)                             \
{                                                                \
   case index:                                                   \
      {                                                          \
         SetLeftSoftkeyFunction(func_ptr,KEY_EVENT_UP);          \
         SetKeyHandler(func_ptr, KEY_RIGHT_ARROW,KEY_EVENT_DOWN);\
		 SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW,KEY_EVENT_DOWN); \
      }                                                          \
      break;                                                     \
}

/****************************************************************************
* Local Functions                                                        
*****************************************************************************/
void mmi_motion_highlight_hdlr(S32 index);
void mmi_motion_entry_app_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_init
 * DESCRIPTION
 *  init moiton apps
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef IS_DICE_BASE_MOTIONGAME
    mmi_motion_dice_inti_app();
#endif 

#ifdef IS_DJ_BASE_MOTIONGAME
    mmi_motion_dj_init_app();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr for motion
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    #ifdef IS_DICE_BASE_MOTIONGAME
            GAME_SWITCH(motion_dice, mmi_motion_dice_entry_app);
    #endif 

    #ifdef IS_DJ_BASE_MOTIONGAME
            GAME_SWITCH(motion_dj, mmi_motion_dj_entry_app);
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_highlight_app
 * DESCRIPTION
 *  highlight motion app menitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_entry_app_screen
 * DESCRIPTION
 *  entry game app screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 menu_str[motion_list_count + 1];
    U16 menu_img[motion_list_count + 1];
#if defined(IS_DICE_BASE_MOTIONGAME) || defined(IS_DJ_BASE_MOTIONGAME)
    U16 index = 0;
#endif
    UI_time t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef IS_DICE_BASE_MOTIONGAME
    menu_str[index] = STR_ID_MOTION_DICE_APP;
    menu_img[index++] = IMG_ID_MOTION_DICE_APP;
#endif /* IS_DICE_BASE_MOTIONGAME */ 

#ifdef IS_DJ_BASE_MOTIONGAME
    menu_str[index] = STR_ID_MOTION_DJ_APP;
    menu_img[index++] = IMG_ID_MOTION_DJ_APP;
#endif /* IS_DJ_BASE_MOTIONGAME */ 

    /* Set random seed */
    GetDateTime(&t);
    srand(t.nMin);

    /* enter screen */
    EntryNewScreen(SCR_ID_MOTION_APP, NULL, mmi_motion_entry_app_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_MOTION_APP);

    RegisterHighlightHandler(mmi_motion_highlight_hdlr);

    ShowCategory15Screen(
        STR_GAME_CAPTION,
        GetRootTitleIcon(MENU_ID_MOTION_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        motion_list_count,
        menu_str,
        menu_img,
        1,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* load game settings */
    mmi_gfx_load_setting();
}

#endif /* __MMI_MOTION_APP__ */ 

