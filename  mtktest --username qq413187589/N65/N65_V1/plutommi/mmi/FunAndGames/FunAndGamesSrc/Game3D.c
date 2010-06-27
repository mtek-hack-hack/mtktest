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
 *  Game3D.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  3D Game Menu
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_3D_GAME__

#include "gui.h"
#include "CustResDef.h"
#include "MiscFunctions.h"
#include "GameDefs.h"
#include "GameProts.h"
#include "FunAndGamesDefs.h"
#include "MainMenuDef.h"
#include "GameFramework.h"
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "Commonscreens.h"
#include "DateTimeGprot.h"

#ifdef GE_BROGENT
#include "BrogentGameGprot.h"
#endif

#ifdef GE_INTERGRAFX
#include "IntergraphxGameGprot.h"
#endif 

/* TODO: shall remove, test only */
//#undef __MMI_3D_GAME_BROGENT_HB2_176x220__
//#undef __MMI_3D_GAME_BROGENT_GGR2_176x220__

//#undef __MMI_3D_GAME_BROGENT_HB2_240x320__
//#undef __MMI_3D_GAME_BROGENT_GGR2_240x320__

//#undef __MMI_3D_GAME_INTERGRAFX_DEMOGAME_240x320__
//#undef __MMI_3D_GAME_INTERGRAFX_DEMOGAME_176x220__

/****************************************************************************
* Macro                                                                
*****************************************************************************/
#define MMI_3D_GAME_SWITCH(_index, func_ptr)                     \
{                                                                \
   case _index:                                                  \
      {                                                          \
         SetLeftSoftkeyFunction(func_ptr,KEY_EVENT_UP);          \
         SetKeyHandler(func_ptr, KEY_RIGHT_ARROW,KEY_EVENT_DOWN);\
      }                                                          \
      break;                                                     \
}

typedef enum
{

#if defined(__MMI_3D_GAME_BROGENT_GGR2_240x320__) || defined(__MMI_3D_GAME_BROGENT_GGR2_176x220__)
    MMI_3D_GAME_BROGENT_GOGOROBOT,
#endif 

#if defined(__MMI_3D_GAME_BROGENT_HB2_240x320__) || defined(__MMI_3D_GAME_BROGENT_HB2_176x220__)
    MMI_3D_GAME_BROGENT_HEATBREAKER2,
#endif 

#if defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_176x220__)
    MMI_3D_GAME_INTERGRAFX_DEMOGAME,
#endif 

#if defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_176x220__)
    MMI_3D_GAME_INTERGRAFX_PETFISH,
#endif 

#if defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_176x220__)
    MMI_3D_GAME_INTERGRAFX_ROLLINGBALL,
#endif
    MMI_3D_GAME_MAX_COUNT
} MMI_3D_GAME_LIST_ENUM;

/****************************************************************************
* Local Functions                                                        
*****************************************************************************/
static void mmi_game3d_highlight_hdlr(S32 index);
static void mmi_game3d_entry_game_list(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_game3d_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr for games
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game3d_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    #if defined(__MMI_3D_GAME_BROGENT_GGR2_240x320__) || defined(__MMI_3D_GAME_BROGENT_GGR2_176x220__)
        MMI_3D_GAME_SWITCH(MMI_3D_GAME_BROGENT_GOGOROBOT, mmi_game3d_entry_gogorobot);
    #endif 

    #if defined(__MMI_3D_GAME_BROGENT_HB2_240x320__) || defined(__MMI_3D_GAME_BROGENT_HB2_176x220__)
        MMI_3D_GAME_SWITCH(MMI_3D_GAME_BROGENT_HEATBREAKER2, mmi_game3d_entry_heatbreaker2);
    #endif 

    #if defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_176x220__)
        MMI_3D_GAME_SWITCH(MMI_3D_GAME_INTERGRAFX_DEMOGAME, mmi_game3d_entry_demogame);
    #endif 

    #if defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_176x220__)
        MMI_3D_GAME_SWITCH(MMI_3D_GAME_INTERGRAFX_PETFISH, mmi_game3d_entry_petfish);
    #endif 

    #if defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_176x220__)
        MMI_3D_GAME_SWITCH(MMI_3D_GAME_INTERGRAFX_ROLLINGBALL, mmi_game3d_entry_rollingball);
    #endif
    
        default:
            /* shall not enter here */
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game3d_highlight_app
 * DESCRIPTION
 *  highlight game app menitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_game3d_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_game3d_entry_game_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_game3d_entry_game_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game3d_entry_game_lsit
 * DESCRIPTION
 *  entry game app screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game3d_entry_game_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    UI_time t;
    U16 menu_str[MMI_3D_GAME_MAX_COUNT + 1];
    U16 menu_img[MMI_3D_GAME_MAX_COUNT + 1];
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_3D_GAME_BROGENT_GGR2_240x320__) || defined(__MMI_3D_GAME_BROGENT_GGR2_176x220__)
    menu_str[index] = STR_ID_3D_GAME_BROGENT_GOGOROBOT;
    menu_img[index++] = IMG_ID_3D_GAME_BROGENT_GOGOROBOT;
#endif 

#if defined(__MMI_3D_GAME_BROGENT_HB2_240x320__) || defined(__MMI_3D_GAME_BROGENT_HB2_176x220__)
    menu_str[index] = STR_ID_3D_GAME_BROGENT_HEATBREAKER2;
    menu_img[index++] = IMG_ID_3D_GAME_BROGENT_HEATBREAKER2;
#endif 

#if defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_176x220__)
    menu_str[index] = STR_ID_3D_GAME_INTERGRAFX_DEMOGAME;
    menu_img[index++] = IMG_ID_3D_GAME_INTERGRAFX_DEMOGAME;
#endif 

#if defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_176x220__)
    menu_str[index] = STR_ID_3D_GAME_INTERGRAFX_PETFISH;
    menu_img[index++] = IMG_ID_3D_GAME_INTERGRAFX_PETFISH;
#endif 

#if defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_176x220__)
    menu_str[index] = STR_ID_3D_GAME_INTERGRAFX_ROLLINGBALL;
    menu_img[index++] = IMG_ID_3D_GAME_INTERGRAFX_ROLLINGBALL;
#endif

    /* Set random seed */
    GetDateTime(&t);
    srand(t.nMin);

    EntryNewScreen(SCR_ID_3D_GAME_LIST, NULL, mmi_game3d_entry_game_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_3D_GAME_LIST);

    RegisterHighlightHandler(mmi_game3d_highlight_hdlr);

    ShowCategory15Screen(
        STR_ID_3D_GAME,
        GetRootTitleIcon(MENU_ID_FNG_3D_GAME),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_3D_GAME_MAX_COUNT,
        menu_str,
        menu_img,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

#endif /* __MMI_3D_GAME__ */ 

