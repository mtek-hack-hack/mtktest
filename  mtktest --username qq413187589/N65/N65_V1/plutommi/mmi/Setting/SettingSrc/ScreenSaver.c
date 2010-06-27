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
 * ScreenSaver.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Screen Saver application
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
#include "MMI_include.h"
#ifndef _SCREENSAVER_C
#define _SCREENSAVER_C

/***************************************************************************** 
* Include
*****************************************************************************/
#include "DownloadDefs.h"
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "MainMenuDef.h"
#include "SettingProfile.h"
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__)
#if defined(__MMI_POWER_ON_OFF_DISPLAY__)
   /* MUST be allocated before WallpaperDefs.h */
#include "PowerOnOffDisplayDefs.h"
#endif /* defined(__MMI_POWER_ON_OFF_DISPLAY__) */ 
#include "VdoPlyResDef.h"
#endif /* defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) */ 
#include "ScreenSaverDefs.h"
#include "WallpaperDefs.h"
#include "WPSSProtos.h"
#include "wgui_inline_edit.h"
#include "DownloadProtos.h"
#include "SettingDefs.h"
#include "SettingProt.h"
#include "PhoneSetup.h"
#include "IdleAppDef.h"
#ifdef __MMI_FILE_MANAGER__
#include "FileMgr.h"
#endif 
#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "Conversions.h"
#ifdef __MMI_THEMES_V2_SUPPORT__
#include "MMIThemes.h"  /* ritesh */
#endif 

#ifdef __MMI_AVATAR__
#include "AvatarGprot.h"
#endif

#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
#endif /* defined(__MMI_RESOURCE_ENFB_SUPPORT__) */


/***************************************************************************** 
* Local Variable
*****************************************************************************/
static PS8 error_str_ptr;
static U8 ss_item_amount;

/***************************************************************************** 
* External Variable
*****************************************************************************/
#ifdef __MMI_FILE_MANAGER__
extern PHNSET_WPSS_FILENAME_STRUCT phnset_wpss_filename;
#endif

/***************************************************************************** 
* External Function
*****************************************************************************/
extern void PhnsetWpUsrDefPreView(void);
extern U8 PhnsetGetDefEncodingType(void);


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetScreenSaver
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver
 *  Following Functions:   EntryPhnsetScrSvr
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetScreenSaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_SS;

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetKeyHandler(EntryPhnsetScrSvr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryPhnsetScrSvr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetScrSvrSetting
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 *  Following Functions:   EntryPhnsetScrSvrSettings
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetScrSvrSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryPhnsetScrSvrSettings, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetScrSvrSettings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetScrSvrSelect
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select
 *  Following Functions:   EntryPhnsetScrSvrSystem ( EntryScrSaverSystem //Wap Disable )
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetScrSvrSelect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__))
    /* Display 2 menuitems: System, User Defined */
    SetLeftSoftkeyFunction(EntryPhnsetScrSvrSelect, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetScrSvrSelect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#else /* (defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)) */ 

    /* Download and File Manager not exist, go to system screen saver list directly */
    SetLeftSoftkeyFunction(EntryPhnsetScrSvrSystem, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetScrSvrSystem, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#endif /* (defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetScrSvrSystem
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> (Select) -> System
 *  Following Functions:   EntryPhnsetScrSvrSystem
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_FILE_MANAGER__)
void HighlightPhnsetScrSvrSystem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryPhnsetScrSvrSystem, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetScrSvrSystem, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_FILE_MANAGER__) */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetScrSvrFmgr
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_FILE_MANAGER__)
void HighlightPhnsetScrSvrFmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_SS;

    SetLeftSoftkeyFunction(EntryPhnsetWallpaperFmgr /* EntryPhnsetScrSvrFmgr */ , KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetWallpaperFmgr /* EntryPhnsetScrSvrFmgr */ , KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#endif /* defined(__MMI_FILE_MANAGER__) */ 


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetScrSvrSetting
 * DESCRIPTION
 *  This function is hint handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 *  Following Functions:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetScrSvrSetting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (PhnsetGetCurScrSvrStatus())
    {
        case SET_SS_STATUS_ON:
            mmi_ucs2cpy((PS8) hintData[index], GetString(STR_GLOBAL_ON));
            break;

        case SET_SS_STATUS_OFF:
            mmi_ucs2cpy((PS8) hintData[index], GetString(STR_GLOBAL_OFF));
            break;

    #ifdef __MMI_LCD_PARTIAL_ON__
        case SET_SS_STATUS_POWERSAVING:
            mmi_ucs2cpy((PS8) hintData[index], GetString(STR_SCREENSAVER_DISPLAY_TIME));
            break;
    #endif /* __MMI_LCD_PARTIAL_ON__ */ 

        default:
            mmi_ucs2cpy((PS8) hintData[index], GetString(STR_GLOBAL_OFF));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetScrSvrSelect
 * DESCRIPTION
 *  This function is hint handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select
 *  Following Functions:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetScrSvrSelect(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PS8 p = PhnsetGetCurScrSvrName();

    if (p)
    {
        mmi_ucs2cpy((PS8) hintData[index], p);
    }
}


#ifdef __MMI_AVATAR__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_ss_avatar_highlight_hdlr
 * DESCRIPTION
 *  This function is Inline selection highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver
 																-> Select -> 3d avatar
 *  Following Functions:   mmi_phnset_avatar_entry
 * PARAMETERS            
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_ss_avatar_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phnset_avatar_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_phnset_avatar_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetScrSvr
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver
 *  Following Functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetScrSvr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ScreenSaverScrText[MAX_SUB_MENUS];
    U8 *ScreenSaverHintsList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MAIN_SCREENSAVER, NULL, EntryPhnsetScrSvr, NULL);
    g_phnset_cntx_p->ScrAnchor = SCR_MAIN_SCREENSAVER;

   /***** Set Hint/Hightlight Handler *****/
    SetHintHandler(MENU_SETTING_SS_SETTING, HintPhnsetScrSvrSetting);
    SetHintHandler(MENU_SETTING_SS_SELECT, HintPhnsetScrSvrSelect);
    SetHiliteHandler(MENU_SETTING_SS_SETTING, HighlightPhnsetScrSvrSetting);
    SetHiliteHandler(MENU_SETTING_SS_SELECT, HighlightPhnsetScrSvrSelect);

#if defined(__MMI_FILE_MANAGER__)
    SetHiliteHandler(MENU_SELECT_SS_SELECT_SYSTEM, HighlightPhnsetScrSvrSystem);
    SetHiliteHandler(MEUN_SELECT_SS_SELECT_DOWNLOAD, HighlightPhnsetScrSvrFmgr);
#ifdef __MMI_AVATAR__
    SetHiliteHandler(MENU_ID_PHNSET_SS_SELECT_AVATAR, mmi_phnset_ss_avatar_highlight_hdlr);
#endif
#endif /* defined(__MMI_FILE_MANAGER__) */ 
      /***** End of Hint/Hightlight Handler *****/

    guiBuffer = GetCurrGuiBuffer(SCR_MAIN_SCREENSAVER);
    nNumofItem = GetNumOfChild(MENU_SETTING_SCR_SVR);
    GetSequenceStringIds(MENU_SETTING_SCR_SVR, ScreenSaverScrText);

    SetParentHandler(MENU_SETTING_SCR_SVR);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Set Hint Handler of Select to NULL if Screen Saver is Off */
    if (PhnsetGetCurScrSvrStatus() == SET_SS_STATUS_ON)
    {
        SetHintHandler(MENU_SETTING_SS_SELECT, HintPhnsetScrSvrSelect);
    }
    else
    {
        SetHintHandler(MENU_SETTING_SS_SELECT, NULL);
    }

    ConstructHintsList(MENU_SETTING_SCR_SVR, ScreenSaverHintsList);

    ShowCategory52Screen(
        STR_SCR_SCREENSAVER_CAPTION,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_OK,
        nNumofItem,
        ScreenSaverScrText,
        (PU16) gIndexIconsImageList,
        ScreenSaverHintsList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/* 
 * Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 */


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrInlineHiliteHdlr
 * DESCRIPTION
 *  This function is Inline selection highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 *  Following Functions:   PhnsetScrSvrSettingLskHdlr
 * PARAMETERS
 *  nIndex      [IN]            
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrInlineHiliteHdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(PhnsetScrSvrSettingLskHdlr);
}

#ifdef __MMI_LCD_PARTIAL_ON__


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrInlineStatusSelectHiliteHdlr
 * DESCRIPTION
 *  Highlight handler of the inline select for screen saver status
 * PARAMETERS
 *  item_index      [IN]            
 *  a(?)            [IN/OUT]        Void
 *  b(?)            [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrInlineStatusSelectHiliteHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 2 || item_index == 0)
    {
        DisableInlineItem(&(wgui_inline_items[3]), 3);
        Category57ChangeItemText(3, (U8*) GetString(STR_GLOBAL_INVALID));
    }
    else
    {
        EnableInlineItem(&(wgui_inline_items[3]), 3);
        Category57ChangeItemText(
            3,
            (U8*) subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_5SEC + g_phnset_cntx_p->SSWaitStatusInlineHilite]);
    }
    RedrawCategory57Screen();
}

#endif /* __MMI_LCD_PARTIAL_ON__ */ 


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrFillInline
 * DESCRIPTION
 *  This function is to fill inline selection items for Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 * PARAMETERS
 *  SSaverInline        [?]             
 *  a(?)                [IN/OUT]        InlineItem *SSaverInline
 *  b(?)                [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrFillInline(InlineItem *SSaverInline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->SSStatusInlineHilite = g_phnset_cntx_p->curSSStatus;
    SetInlineItemActivation(&SSaverInline[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&SSaverInline[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    switch (g_phnset_cntx_p->curSSWaitTime)
    {
        case 5:
            g_phnset_cntx_p->SSWaitStatusInlineHilite = 0;
            break;
        case 15:
            g_phnset_cntx_p->SSWaitStatusInlineHilite = 1;
            break;
        case 30:
            g_phnset_cntx_p->SSWaitStatusInlineHilite = 2;
            break;
        case 60:
            g_phnset_cntx_p->SSWaitStatusInlineHilite = 3;
            break;
        default:
            g_phnset_cntx_p->SSWaitStatusInlineHilite = 2;
            break;  /* Deafult Value */
    }

    subMenuDataPtrs[SET_SS_SETTING_INLINE_CAPTION_STATUS] = (PU8) GetString(STR_SCREENSAVER_STATUS);
    subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_OFF] = (PU8) GetString(STR_GLOBAL_OFF);
    subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_ON] = (PU8) GetString(STR_GLOBAL_ON);
#ifdef __MMI_LCD_PARTIAL_ON__
    subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_POWER_SAVING] = (PU8) GetString(STR_SCREENSAVER_DISPLAY_TIME);
#endif 
    subMenuDataPtrs[SET_SS_SETTING_INLINE_CAPTION_WAITING] = (PU8) GetString(STR_SCREENSAVER_WAITING);
    subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_5SEC] = (PU8) GetString(STR_SCREENSAVER_5SEC);
    subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_15SEC] = (PU8) GetString(STR_SCREENSAVER_15SEC);
    subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_30SEC] = (PU8) GetString(STR_SCREENSAVER_30SEC);
    subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_1MIN] = (PU8) GetString(STR_SCREENSAVER_1MINUTE);

    SetInlineItemCaption(&SSaverInline[0], subMenuDataPtrs[SET_SS_SETTING_INLINE_CAPTION_STATUS]);
#ifdef __MMI_LCD_PARTIAL_ON__
	#if 0
		//Huyanwei Modify It 
	    SetInlineItemSelect(
	        &SSaverInline[1],
	        3,
	        &subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_OFF],
	        &(g_phnset_cntx_p->SSStatusInlineHilite));
	#else
	    SetInlineItemSelect(
	        &SSaverInline[1],
	        2,
	        &subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_OFF],
	        &(g_phnset_cntx_p->SSStatusInlineHilite));

	#endif
    RegisterInlineSelectHighlightHandler(&SSaverInline[1], PhnsetScrSvrInlineStatusSelectHiliteHdlr);
#else /* __MMI_LCD_PARTIAL_ON__ */ 
    SetInlineItemSelect(
        &SSaverInline[1],
        2,
        &subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_OFF],
        &(g_phnset_cntx_p->SSStatusInlineHilite));
#endif /* __MMI_LCD_PARTIAL_ON__ */ 
    SetInlineItemCaption(&SSaverInline[2], subMenuDataPtrs[SET_SS_SETTING_INLINE_CAPTION_WAITING]);
    SetInlineItemSelect(
        &SSaverInline[3],
        MAX_SS_INLINE_EDIT,
        &subMenuDataPtrs[SET_SS_SETTING_INLINE_SELECT_5SEC],
        &(g_phnset_cntx_p->SSWaitStatusInlineHilite));
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetScrSvrSettings
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 *  Following Functions:   PhnsetScrSvrSettingLskHdlr
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetScrSvrSettings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ScreenSaverListIcon[MAX_SS_INLINE_EDIT] = {IMG_SETTING_GREET_STATUS, 0, IMAGE_SETTING_TIME, 0};
    InlineItem SSSettingInLine[MAX_SS_INLINE_EDIT];
    S16 error;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SCREENSAVER_SETTING, ExitPhnsetScrSvrSettings, NULL, NULL);

    g_phnset_cntx_p->isCorrectSet = 0;
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_SCREENSAVER_SETTING);
    memset((void*)SSSettingInLine, 0, sizeof(InlineItem) * MAX_SS_INLINE_EDIT);
    ReadValue(NVRAM_SCREENSAVER_STATUS, &(g_phnset_cntx_p->curSSStatus), DS_BYTE, &error);
    ReadValue(NVRAM_SCREENSAVER_WAITING, &(g_phnset_cntx_p->curSSWaitTime), DS_BYTE, &error);

#ifndef __MMI_LCD_PARTIAL_ON__
    /* If __MMI_LCD_PARTIAL_ON__ is turned off without reseting NVRAM */
    if (g_phnset_cntx_p->curSSStatus == (S32) SET_SS_STATUS_POWERSAVING)
    {
        g_phnset_cntx_p->curSSStatus = 0xFF;
    }
#endif /* __MMI_LCD_PARTIAL_ON__ */ 

    if (g_phnset_cntx_p->curSSStatus == 0xFF)
    {
        g_phnset_cntx_p->curSSStatus = RstGetScrSaverStatusDefault();
        WriteValue(NVRAM_SCREENSAVER_STATUS, &(g_phnset_cntx_p->curSSStatus), DS_BYTE, &error);
    }

    if (g_phnset_cntx_p->curSSWaitTime == 0xFF)
    {
        g_phnset_cntx_p->curSSWaitTime = RstGetScrSaverWaitingDefault();
        WriteValue(NVRAM_SCREENSAVER_WAITING, &(g_phnset_cntx_p->curSSWaitTime), DS_BYTE, &error);
    }

    PhnsetScrSvrFillInline(SSSettingInLine);
    SetLeftSoftkeyFunction(PhnsetScrSvrSettingLskHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterHighlightHandler(PhnsetScrSvrInlineHiliteHdlr);

    inputBuffer = GetCurrNInputBuffer(SCR_SCREENSAVER_SETTING, &inputBufferSize);       /* added for inline edit history */

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(SSSettingInLine, MAX_SS_INLINE_EDIT, inputBuffer);    /* sets the data */
    }

    ShowCategory57Screen(
        STR_GLOBAL_SETTINGS,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_SS_INLINE_EDIT,
        ScreenSaverListIcon,
        SSSettingInLine,
        0,
        guiBuffer);
    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(PhnsetScrSvrSettingLskHdlr, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitPhnsetScrSvrSettings
 * DESCRIPTION
 *  This function is Exit function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 *  Following Functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhnsetScrSvrSettings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_SCREENSAVER_SETTING;
    h.entryFuncPtr = EntryPhnsetScrSvrSettings;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) h.inputBuffer);             /* added for inline edit history */
    AddNHistory(h, inputBufferSize);                    /* added for inline edit history */

    if (g_phnset_cntx_p->isCorrectSet)
    {
        DeleteUptoScrID(SCR_MAIN_SCREENSAVER);
    }

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrSettingLskHdlr
 * DESCRIPTION
 *  This function is left softkey handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Setting
 *  Ancestor Functions:   EntryPhnsetScrSvrSettings
 *  PhnsetScrSvrInlineHiliteHdlr
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrSettingLskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curSSStatus = (U8) g_phnset_cntx_p->SSStatusInlineHilite;

    switch (g_phnset_cntx_p->SSWaitStatusInlineHilite)
    {
        case 0:
            g_phnset_cntx_p->curSSWaitTime = 5;
            break;
        case 1:
            g_phnset_cntx_p->curSSWaitTime = 15;
            break;
        case 2:
            g_phnset_cntx_p->curSSWaitTime = 30;
            break;
        case 3:
            g_phnset_cntx_p->curSSWaitTime = 60;
            break;
    }

    WriteValue(NVRAM_SCREENSAVER_STATUS, &(g_phnset_cntx_p->curSSStatus), DS_BYTE, &error);
    WriteValue(NVRAM_SCREENSAVER_WAITING, &(g_phnset_cntx_p->curSSWaitTime), DS_BYTE, &error);

    g_phnset_cntx_p->isCorrectSet = 1;
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
}

/* 
 * Phonesetup->IdleScreenDisplay->ScreenSaver -> Select
 */


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetScrSvrSelect
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select
 *  Ancestor Functions:   EntryPhnsetScrSvrSettings
 *  PhnsetScrSvrInlineHiliteHdlr
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_FILE_MANAGER__)
void EntryPhnsetScrSvrSelect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ScreenSaverSelectList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SCREENSAVER_SELECT, NULL, EntryPhnsetScrSvrSelect, NULL);

    g_phnset_cntx_p->ScrAnchor = SCR_SCREENSAVER_SELECT;

    guiBuffer = GetCurrGuiBuffer(SCR_SCREENSAVER_SELECT);

    nNumofItem = GetNumOfChild(MENU_SETTING_SS_SELECT);
    GetSequenceStringIds(MENU_SETTING_SS_SELECT, ScreenSaverSelectList);

    SetParentHandler(MENU_SETTING_SS_SELECT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler); /* HighlightPhnsetScrSvrSystem, HighlightPhnsetScrSvrDwnl */

    ShowCategory15Screen(
        STR_SCR_SCREENSAVER_CAPTION,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        ScreenSaverSelectList,
        (PU16) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

#endif /* defined(__MMI_FILE_MANAGER__) */ 


/*****************************************************************************
 * FUNCTION
 *  PhnsetConstSysScrSvrList
 * DESCRIPTION
 *  This function is to construct system screen saver list
 *  for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System
 * PARAMETERS
 *  pSysSSStrList       [IN]            
 *  pSysSSImgIDList     [?]             
 *  HighliteItem        [?]             
 *  a(?)                [IN/OUT]        U8 **pSysSSStrList, U16 *pSysSSImgIDList, S16 *HighliteItem
 *  b(?)                [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetConstSysScrSvrList(U8 **pSysSSStrList, U16 *pSysSSImgIDList, S16 *HighliteItem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    DYNIMAGEINFO *Info;

    U8 index_other = 0;
    U8 index_swflash = 0;
    U8 index_img = 0; /* count of image */
    U8 index_vdo = 0; /* count of video */
    U8 ss_max;
    U8 max_ss_img = MAX_SCREENSAVER_IMG - MAX_OTHER_SCREENSAVER - MAX_DISPCHAR_SWFLASH;
    U8 max_ss_other = MAX_OTHER_SCREENSAVER;
    U8 max_ss_swflash = MAX_DISPCHAR_SWFLASH;

    max_ss_other --;    /* remove theme wallpaper image id */

#ifdef __MMI_THEMES_V2_SUPPORT__
        if(!mmi_tm_get_current_theme_screensaver())
        {
            max_ss_other --;            
        }
#endif /* __MMI_THEMES_V2_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Layout
     *
     * -- Video         --
     *
     * -- Normal Images --
     * -- Normal Images -- SVG
     * -- Normal Images -- M3D
     * -- Analog clock  --
     * -- Digital clock --
     * -- Theme         --
     * -- SWFLASH        --
     *
     * -- Factory images--
     * 
     */


    for (i = 0; i < (MAX_SCREENSAVER_VDO + max_ss_img + max_ss_other + max_ss_swflash); i++)
    {
        U16 strID = 0, imgID = 0;
        
        if (i < MAX_SCREENSAVER_VDO)
        {
           imgID = IMG_ID_PHNSET_SS_VDO_START + i;
        }
        else if (i >= MAX_SCREENSAVER_VDO && 
                 i < (MAX_SCREENSAVER_VDO + max_ss_img))
        {
           imgID = IMG_ID_PHNSET_SS_START + (i - MAX_SCREENSAVER_VDO);
        }
        else if (max_ss_other &&
                 i >= (MAX_SCREENSAVER_VDO + max_ss_img) &&
                 i < (MAX_SCREENSAVER_VDO + (max_ss_img + max_ss_other)))
        {
            imgID = IMG_ID_DISPCHAR_OTHER_START + (i - (MAX_SCREENSAVER_VDO + max_ss_img)) + 1;
        }
        else if (max_ss_swflash)
        {
            imgID = IMG_ID_DISPCHAR_SWFLASH_START + (i - (MAX_SCREENSAVER_VDO + (max_ss_img + max_ss_other)));
        }

        if (imgID >= IMG_ID_PHNSET_SS_VDO_START && imgID <= IMG_ID_PHNSET_SS_VDO_MAX)
        {
            strID = STR_ID_PHNSET_DISPCHAR_VDOID_START + index_vdo;
            ++index_vdo;
        }
        /* normal/SVG/M3D  images*/
        else if (imgID >= IMG_ID_PHNSET_SS_START && imgID <= IMG_ID_PHNSET_SS_MAX)
        {
            strID = STR_ID_PHNSET_DISPCHAR_IMGID_START + index_img;
            index_img++;
        }
        else if ( imgID > IMG_ID_DISPCHAR_OTHER_START && imgID < IMG_ID_DISPCHAR_OTHER_MAX)
        {

    #if !defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        
    #ifdef __MMI_ANALOG_CLOCK__
            /* Analog clock */
            if (imgID == IMG_ID_DISPCHAR_ANALOG_CLK)
            {
                strID = STR_ID_PHNSET_DISPCHAR_ANALOG;
            }
    #endif /* __MMI_ANALOG_CLOCK__ */ 
        
    #ifdef __MMI_DIGITAL_CLOCK__
            /* Digital clock */
            if (imgID == IMG_ID_DISPCHAR_DIGITAL_CLK)
            {
                strID = STR_ID_PHNSET_DISPCHAR_DIGITAL;
            }
    #endif /* __MMI_DIGITAL_CLOCK__ */ 
        
    #endif /* !__MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
        
    #ifdef __MMI_THEMES_V2_SUPPORT__
            /* Theme */
            if (mmi_tm_get_current_theme_screensaver() && imgID == IMG_ID_DISPCHAR_THEME_WALLPAPER)
            {
                imgID = IMG_ID_DISPCHAR_THEME_SCREENSAVER;
                strID = STR_ID_DISPCHAR_THEME_SCREENSAVER;
            }
    #endif /* __MMI_THEMES_V2_SUPPORT__ */

            ++index_other;
        }
#ifdef __MMI_SWFLASH__
        else if (imgID >= IMG_ID_DISPCHAR_SWFLASH_START && imgID <= IMG_ID_DISPCHAR_SWFLASH_MAX)
        {
                strID = STR_ID_DISPCHAR_SWFLASH_START + index_swflash;
                ++index_swflash;
        }
#endif /* __MMI_SWFLASH__*/
        if(strID && imgID)
        {
            if (pSysSSImgIDList)
            {
                pSysSSImgIDList[i] = imgID;
            }
            
            if (pSysSSStrList)
            {
                pSysSSStrList[i] = (PU8) GetString(strID);
            }
            
            if (HighliteItem && g_phnset_cntx_p->curSsID == pSysSSImgIDList[i])
            {
                *HighliteItem = i;
            }
        }
    }
    ss_max = i;
    MMI_ASSERT(index_other == max_ss_other);
    MMI_ASSERT(index_swflash == max_ss_swflash);

    
   /*
    * FACTORY SCREEN SAVER
    */
    g_phnset_cntx_p->SSFctyImgNum = GetFullScreenFactoryImagesInfo(&Info);

    for (i = 0; i < g_phnset_cntx_p->SSFctyImgNum; i++)
    {
        U16 strID = STR_ID_PHNSET_DISPCHAR_IMGID_START + index_img + i;

        if (pSysSSImgIDList)
        {
            pSysSSImgIDList[ss_max + i] = Info[i].ImagesId;
        }

        if (pSysSSStrList)
        {
            pSysSSStrList[ss_max + i] = (PU8) GetString(strID);
        }

        if (HighliteItem)
            if (g_phnset_cntx_p->curSsID == Info[i].ImagesId)
            {
                *HighliteItem = ss_max + i;
            }
    }

    ss_max += i;

    return ss_max;   /* amount, will be used to construct list */

}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetScrSvrSystem
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System
 *  Following Functions:   EntryPhnsetScrSvrSysView
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetScrSvrSystem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "EntryPhnsetScrSvrSystem\n");

    EntryNewScreen(SCR_SCREENSAVER_SYSTEM_LIST, NULL, EntryPhnsetScrSvrSystem, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_SCREENSAVER_SYSTEM_LIST);

    RegisterHighlightHandler(PhnsetScrSvrSysHiliteHdlr);

    g_phnset_cntx_p->curHightlightItem = 0;
    ss_item_amount = PhnsetConstSysScrSvrList(
                        subMenuDataPtrs,
                        g_phnset_cntx_p->SysWPSSList,
                        (S16*) & g_phnset_cntx_p->curHightlightItem);

    /* Variable To Keep Is Dont Added On Scrolling */
    g_phnset_cntx_p->WPSSPreviewScrFlag = 1;

    if (g_phnset_cntx_p->curSsID == 0)
        g_phnset_cntx_p->curHightlightItem = 0;        
    
    ShowCategory36Screen(
        STR_GLOBAL_SELECT,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_VIEW,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ss_item_amount,
        subMenuDataPtrs,
        (U16) (g_phnset_cntx_p->curHightlightItem),
        guiBuffer);

    SetLeftSoftkeyFunction(EntryPhnsetScrSvrSysView, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetScrSvrSysView, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrSysHiliteHdlr
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System
 * PARAMETERS
 *  nIndex      [IN]            
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrSysHiliteHdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__)
    if (nIndex < MAX_SCREENSAVER_VDO)
    {
        ChangeLeftSoftkey(STR_ID_VDOPLY_PLAY, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_VIEW, 0);
    }
#endif /* defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__) */ 
    g_phnset_cntx_p->curHightlightItem = (U16) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetScrSvrSysView
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System ->View
 *  Following Functions:   EntryScrSetScreenSaver
 *  PhnsetScrSvrSysViewPre
 *  PhnsetScrSvrSysViewNext
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetScrSvrSysView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /* Notice: g_phnset_cntx_p->SysWPSSList Has been constructed at  EntryPhnsetScrSvrSystem() */
    U16 screenSaverId = g_phnset_cntx_p->SysWPSSList[g_phnset_cntx_p->curHightlightItem];
    U8 *ssName = (U8 *)PhnsetGetScrSvrNameById(screenSaverId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_SCREENSAVER_VIEW);

    g_phnset_cntx_p->isCorrectSet = 0;

    if (g_phnset_cntx_p->WPSSPreviewScrFlag)
    {
        EntryNewScreen(SCR_SCREENSAVER_VIEW, ExitPhnsetScrSvrSysView, EntryPhnsetScrSvrSysView, NULL);
    }
#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
    else
    {
        mmi_frm_resmem_reset(MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND);
    }    
#endif /* defined(__MMI_RESOURCE_ENFB_SUPPORT__) */


    wgui_set_touch_title_bar_buttons(); /* enable the display of title bar buttons */

#if defined(__MMI_TOUCH_SCREEN__)
    register_touch_button_handlers(NULL, PhnsetScrSvrSysViewPre, NULL, PhnsetScrSvrSysViewNext);
#endif 


    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "EntryPhnsetScrSvrSysView: screenSaverId=%d\n", screenSaverId);

#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__)
    if (PhnsetGetDisplayType(screenSaverId) == PHNSET_TYPE_DISP_VIDEO)
    {
        ShowCategory225Screen(
            STR_ID_PHNSET_DISPCHAR_VDOID_START + (screenSaverId - IMG_ID_PHNSET_SS_VDO_START),        /* title_str */
            0,                  /* title_icon */
            STR_GLOBAL_OK,      /* lsk_str */
            IMG_GLOBAL_OK,      /* lsk_icon */
            STR_GLOBAL_BACK,    /* rsk_str */
            IMG_GLOBAL_BACK,    /* rsk_icon */
            screenSaverId,      /* video_id */
            NULL,               /* video_filename */
            1,                  /* repeat_count */
            TRUE,               /* is_visual_update */
            FALSE,              /* is_play_audio */
            TRUE,               /* is_lcd_no_sleep */
            GDI_COLOR_BLACK,    /* bg_color */
            PhnsetWpSsPlayCallBack,
            guiBuffer);
    }
    else
#endif /* defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__) */ 

#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__    
#ifdef __MMI_ANALOG_CLOCK__
        /* Category 86 to View Analog Clock Screen Saver */
    if ((screenSaverId == IMG_ID_DISPCHAR_ANALOG_CLK))
    {
        ShowCategory86Screen(STR_ID_PHNSET_DISPCHAR_ANALOG, 0, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, IMG_ID_DISPCHAR_ANALOG_CLK, NULL, guiBuffer, 0);        /* 051305 Calvin modified */
    }
    else
#endif /* __MMI_ANALOG_CLOCK__ */ 

#ifdef __MMI_DIGITAL_CLOCK__
        /* Category 128 to View Digital Clock Screen Saver */
    if (screenSaverId == IMG_ID_DISPCHAR_DIGITAL_CLK)
    {
        ShowCategory128Screen(
            STR_ID_PHNSET_DISPCHAR_DIGITAL,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMG_ID_DISPCHAR_DIGITAL_CLK,
            1,
            1,
            1,
            guiBuffer,
            0);

    }
    else
#endif /* __MMI_DIGITAL_CLOCK__ */ 
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__  */

#ifdef __MMI_SWFLASH__
    if (PhnsetGetDisplayType(screenSaverId) == PHNSET_TYPE_DISP_SWFLASH)
    {
        ShowCategory229Screen(
            ssName,                            /* title_str */
            IMG_SCR_SETTING_CAPTION,            /* title_icon */
            STR_GLOBAL_OK,                      /* lsk_str */
            IMG_GLOBAL_OK,                      /* lsk_icon */
            STR_GLOBAL_BACK,                    /* rsk_str */
            IMG_GLOBAL_BACK,                    /* rsk_icon */
            screenSaverId,                      /* resource_id */
            NULL,                               /* resource_filename */
            1,                                  /* repeat_count */
            MMI_FALSE,                          /* is_play_audio */
            MMI_FALSE,                          /* is_vibrate_on */
            MMI_FALSE,                          /* is_interaction_on */
            MMI_TRUE,                           /* is_lcd_no_sleep */
            MMI_TRUE,                          /* is_full_screen */
            GDI_COLOR_WHITE,                    /* bg_color */
            PhnsetWpSsPlayCallBack,
            guiBuffer);


    }
    else
#endif /* __MMI_SWFLASH__ */

    /* Category 129 to view other Screensavers */
    {
        ShowCategory129Screen(
            ssName,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            screenSaverId,
            guiBuffer);
    }

    SetLeftSoftkeyFunction(PhnsetScrSvrSysViewLskHdlr, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* changed the up-down arrow key handlers to left-right arrow key handlers
       for having the similar behaviour of keypad and touchscreen. */
    SetKeyHandler(PhnsetScrSvrSysViewPre, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(PhnsetScrSvrSysViewNext, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitPhnsetScrSvrSysView
 * DESCRIPTION
 *  This function is Exit function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System ->View
 *  Ancestor Functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhnsetScrSvrSysView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "ExitPhnsetScrSvrSysView\n");
    if (g_phnset_cntx_p->isCorrectSet)
    {
        DeleteUptoScrID(g_phnset_cntx_p->ScrAnchor);
    }

    g_phnset_cntx_p->WPSSPreviewScrFlag = 1;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrSysViewPre
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System ->View
 *  Ancestor Functions:   EntryPhnsetScrSvrSysView
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrSysViewPre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryFunction();
    if (g_phnset_cntx_p->curHightlightItem <= 0)
    {
        g_phnset_cntx_p->curHightlightItem = ss_item_amount;
    }

    g_phnset_cntx_p->curHightlightItem--;
    g_phnset_cntx_p->WPSSPreviewScrFlag = 0;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetScrSvrSysViewPre: highlight=%d\n",
                         g_phnset_cntx_p->curHightlightItem);

    EntryPhnsetScrSvrSysView();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrSysViewNext
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System ->View
 *  Ancestor Functions:   EntryPhnsetScrSvrSysView
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrSysViewNext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryFunction();

    if (g_phnset_cntx_p->curHightlightItem >= ss_item_amount - 1)
    {
        g_phnset_cntx_p->curHightlightItem = -1;
    }

    g_phnset_cntx_p->curHightlightItem++;
    g_phnset_cntx_p->WPSSPreviewScrFlag = 0;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetScrSvrSysViewNext: highlight=%d\n",
                         g_phnset_cntx_p->curHightlightItem);

    EntryPhnsetScrSvrSysView();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrSysViewLskHdlr
 * DESCRIPTION
 *  This function is Left softkey for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> System ->View
 *  Ancestor Functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrSysViewLskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curSsID = g_phnset_cntx_p->SysWPSSList[g_phnset_cntx_p->curHightlightItem];
    mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetScrSvrSysViewLskHdlr: ID=%d\n", g_phnset_cntx_p->curSsID);

    g_phnset_cntx_p->isCorrectSet = 1;
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
}

#ifdef __MMI_THEMES_V2_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  ThemeManagerSetScreensaver
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  nId         [IN]            
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerSetScreensaver(U16 nId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curSsID = nId;
    mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  DispIdleScrSvrBadFilePopup
 * DESCRIPTION
 *  To show a popup of selecting an invalid file
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void DispIdleScrSvrBadFilePopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_str_ptr)
    {
        DisplayPopup((PU8) error_str_ptr, IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_IDLE_SS_DECODE_ERR),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    error_str_ptr = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScreenSaverBadFileCallBack
 * DESCRIPTION
 *  This function is call back function for showcategories33screen,
 *  If display user defined image got problem in idle screen, this function will be executed
 *  Follow functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
S32 PhnsetScreenSaverBadFileCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetScreenSaverBadFileCallBack\n");

    PhnsetRstScrSvrDefault();

    error_str_ptr = NULL;
    DispIdleScrSvrBadFilePopup();

    return g_phnset_cntx_p->curSsID;
}

#ifdef __MMI_FILE_MANAGER__


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrForwardFromFmgr
 * DESCRIPTION
 *  Call back for File manager forwarding
 * PARAMETERS
 *  path            [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrForwardFromFmgr(void *path, FMGR_FILTER *filter, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetScrSvrForwardFromFmgr: short=%d\n", is_short);

    if (!FMGR_FILTER_IS_SET(filter, FMGR_TYPE_GIF) &&
#ifdef JPG_DECODE
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_JPG) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_JPEG) &&
#endif /* JPG_DECODE */ 
#if defined(GDI_USING_PNG)
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_PNG) &&
#endif 
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__)
#ifdef MP4_CODEC
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_3GP) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_MP4) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_MPG) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_3G2) &&
#endif /* MP4_CODEC */ 
#ifdef MJPG_SUPPORT
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_AVI) &&
#endif 
#endif /* defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__) */ 
#ifdef M3D_MMI_SUPPORT
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_M3D) &&
#endif
#ifdef SVG_SUPPORT
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_SVG) &&
#endif
#ifdef __MMI_SWFLASH__
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_CMP) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_VIS) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_IVIS) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_KVIS) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_MVIS) &&
#endif
#if defined(__DRM_V02__)
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_ODF) &&
#endif
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_BMP) &&
        !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_WBMP))
    {
        DisplayPopup((PU8) GetString(STR_FMGR_INVALID_FORMAT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;
    }

    if (path)
    {
        /* Prevent memory leck, after buffer is free, set pointer to NULL */
        ASSERT(phnset_dispchar_strp == NULL);

        g_phnset_cntx_p->isShort = is_short;

        phnset_dispchar_strp = OslMalloc(FMGR_PATH_BUFFER_SIZE);
        if (phnset_dispchar_strp)
        {
            mmi_ucs2cpy((S8*) phnset_dispchar_strp, (S8*) path);
        }
        else
        {
            GoBackToHistory(SCR_IDLE_SCR_DISP);
            return;
        }
        if (mmi_fmgr_forwardable_path((PS8) phnset_dispchar_strp))
        {
            error_str_ptr = (PS8) GetString(STR_ID_PHNSET_DISPCHAR_INVALID_PATH);
            DispIdleScrSvrBadFilePopup();
            PhnsetWpUsrDefFreeBuf();
            return;
        }

        /* file limitation check - limitation is define in file manager util */
        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_SCREEN_SAVER, (PS8) phnset_dispchar_strp, &error_str_ptr))
        {
            DispIdleScrSvrBadFilePopup();
            PhnsetWpUsrDefFreeBuf();
            return;
        }

        g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_SS;
        g_phnset_cntx_p->ScrAnchor = GetCurrScrnId();

        PhnsetWpUsrDefPreView();
    }
    else
        /* run to here means some kinds of image error occur */
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetScrSvrByFileName
 * DESCRIPTION
 *  Set Current screensaver by given path
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetScrSvrByFileName(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetSetScrSvrByFileName: short=%d\n", g_phnset_cntx_p->isShort);

    if (g_phnset_cntx_p->isShort)
    {
        phnset_wpss_filename.isSSShort = 1;
    }
    else
    {
        phnset_wpss_filename.isSSShort = 0;
    }

    g_phnset_cntx_p->curSsID = 0;
    mmi_ucs2cpy((S8*) phnset_wpss_filename.screensave, (S8*) path);
    mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));
    WriteRecord(NVRAM_EF_WPSS_FILENAME_LID, 1, &phnset_wpss_filename, sizeof(phnset_wpss_filename), &error);

    g_phnset_cntx_p->isCorrectSet = 1;

    if (g_idle_context.IsOnIdleScreen)
    {
        EntryIdleScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetCurScrSvrFileName
 * DESCRIPTION
 *  get Current screensaver path
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
PS8 PhnsetGetCurScrSvrFileName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetGetCurScrSvrFileName\n");

    return (PS8) phnset_wpss_filename.screensave;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetDwnlScrSvrHiliteHdlr
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> Download
 *  Follow functions:
 * PARAMETERS
 *  nIndex      [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetDwnlScrSvrHiliteHdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curHightlightItem = (U32) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetScrSvrDwnlView
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> Download -> View
 *  Following functions:   PhnsetScrSvrDwnlViewLskHdlr
 *  PhnsetScrSvrDwnlViewPre
 *  PhnsetScrSvrDwnlViewNext
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetScrSvrDwnlView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 ssName;
    U8 *guiBuffer;
    U16 screenSaverId = g_phnset_cntx_p->DwnlWPSSList[g_phnset_cntx_p->curHightlightItem];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_SCREENSAVER_DOWNLOAD_VIEW);

    if (g_phnset_cntx_p->WPSSPreviewScrFlag)
    {
        EntryNewScreen(SCR_SCREENSAVER_DOWNLOAD_VIEW, ExitPhnsetScrSvrDwnlView, EntryPhnsetScrSvrDwnlView, NULL);
    }

    ssName = (PU8) PhnsetGetScrSvrNameById(screenSaverId);

#if defined(__MMI_TOUCH_SCREEN__)
    /* register the handlers for pen down event. */
    register_touch_button_handlers(NULL, PhnsetScrSvrDwnlViewPre, NULL, PhnsetScrSvrDwnlViewNext);

#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    wgui_set_touch_title_bar_buttons(); /* enable the display of title bar buttons */

    ShowCategory129Screen(
        ssName,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        screenSaverId,
        guiBuffer);

    SetLeftSoftkeyFunction(PhnsetScrSvrDwnlViewLskHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* changed the up-down arrow key handlers to left-right arrow key handlers
       for having the similar behaviour of keypad and touchscreen. */
    /* change the key handler for KEY UP event to KEY DOWN event. */
    SetKeyHandler(PhnsetScrSvrDwnlViewPre, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(PhnsetScrSvrDwnlViewPre, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(PhnsetScrSvrDwnlViewPre, KEY_VOL_UP, KEY_LONG_PRESS);

    SetKeyHandler(PhnsetScrSvrDwnlViewNext, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(PhnsetScrSvrDwnlViewNext, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(PhnsetScrSvrDwnlViewNext, KEY_VOL_DOWN, KEY_LONG_PRESS);

}


/*****************************************************************************
 * FUNCTION
 *  ExitPhnsetScrSvrDwnlView
 * DESCRIPTION
 *  This function is Exit function for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> Download -> View
 *  Following functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhnsetScrSvrDwnlView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->WPSSPreviewScrFlag = 1;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrDwnlViewPre
 * DESCRIPTION
 *  This function is to view preview screen saver
 *  for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> Download -> View
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrDwnlViewPre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryFunction();
    if (g_phnset_cntx_p->curHightlightItem == 0)
    {
        g_phnset_cntx_p->curHightlightItem = g_phnset_cntx_p->SSDwnlImgNum;
    }

    g_phnset_cntx_p->curHightlightItem--;
    g_phnset_cntx_p->WPSSPreviewScrFlag = 0;
    EntryPhnsetScrSvrDwnlView();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrDwnlViewNext
 * DESCRIPTION
 *  This function is to view next screen saver
 *  for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> Download -> View
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrDwnlViewNext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->curHightlightItem >= g_phnset_cntx_p->SSDwnlImgNum - 1)
    {
        g_phnset_cntx_p->curHightlightItem = -1;
    }

    g_phnset_cntx_p->curHightlightItem++;
    g_phnset_cntx_p->WPSSPreviewScrFlag = 0;
    EntryPhnsetScrSvrDwnlView();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrDwnlViewLskHdlrDone
 * DESCRIPTION
 *  This function is Left softkey handler
 *  for Phonesetup->IdleScreenDisplay->ScreenSaver -> Select -> Download -> View
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrDwnlViewLskHdlrDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_MAIN_SCREENSAVER);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetScrSvrDwnlViewLskHdlr
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetScrSvrDwnlViewLskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopupCallBack(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        ST_NOTIFYDURATION,
        SUCCESS_TONE,
        PhnsetScrSvrDwnlViewLskHdlrDone);
    g_phnset_cntx_p->curSsID = g_phnset_cntx_p->DwnlWPSSList[g_phnset_cntx_p->curHightlightItem];
    mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));
}
#endif /* defined(__MMI_FILE_MANAGER__) */ /* __MMI_WAP__ */

/*
 * Externel Interfaces
 */


/*****************************************************************************
 * FUNCTION
 *  PhnsetRstScrSvrDefault
 * DESCRIPTION
 *  This function is to set screen saver status/waiting time/image to default value
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetRstScrSvrDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curSsID = RstGetScrSaverImgIdDefault();
    mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetRstScrSvrDefault: ID=%d\n", g_phnset_cntx_p->curSsID);

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetCurScrSvr
 * DESCRIPTION
 *  This function is to get screen saver image ID to default value
 * PARAMETERS
 *  screenSaver     [?]             
 *  a(?)            [IN/OUT]        
 *  b(?)            [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGetCurScrSvr(U16 *screenSaver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *screenSaver = g_phnset_cntx_p->curSsID;
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetGetCurScrSvr: ID=%d\n", g_phnset_cntx_p->curSsID);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetScrSvrSetings
 * DESCRIPTION
 *  This function is to get screen saver setting status
 * PARAMETERS
 *  ScreenSaverStatus       [?]             
 *  ScreenSaverWait         [?]             
 *  a(?)                    [IN/OUT]        
 *  b(?)                    [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGetScrSvrSetings(U8 *ScreenSaverStatus, U8 *ScreenSaverWait)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ScreenSaverStatus = (U8) g_phnset_cntx_p->curSSStatus;
    *ScreenSaverWait = (U8) g_phnset_cntx_p->curSSWaitTime;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetGetScrSvrSetings: status=%d, time=%d\n",
                         g_phnset_cntx_p->curSSStatus, g_phnset_cntx_p->curSSWaitTime);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetReadNvramScrSvrSettings
 * DESCRIPTION
 *  This function is to read screen saver setting status/waiting time/image from nvram
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReadNvramScrSvrSettings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    PHNSET_TYPE_DISP type;
    phnset_wpss_type_enum temp_type = g_phnset_cntx_p->wpss_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SCREENSAVER_STATUS, &(g_phnset_cntx_p->curSSStatus), DS_BYTE, &error);
    ReadValue(NVRAM_SCREENSAVER_WAITING, &(g_phnset_cntx_p->curSSWaitTime), DS_BYTE, &error);
    mmi_dispchar_get_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetReadNvramScrSvrSettings: ID=%d, status=%d, time=%d\n",
                         g_phnset_cntx_p->curSsID, g_phnset_cntx_p->curSSStatus, g_phnset_cntx_p->curSSWaitTime);
#ifndef __MMI_LCD_PARTIAL_ON__
    /* If __MMI_LCD_PARTIAL_ON__ is turned off without reseting NVRAM */
    if (g_phnset_cntx_p->curSSStatus == (S32) SET_SS_STATUS_POWERSAVING)
    {
        g_phnset_cntx_p->curSSStatus = 0xFF;
    }
#endif /* __MMI_LCD_PARTIAL_ON__ */ 

    if (g_phnset_cntx_p->curSSStatus == 0xFF)
    {
        g_phnset_cntx_p->curSSStatus = RstGetScrSaverStatusDefault();
        WriteValue(NVRAM_SCREENSAVER_STATUS, &(g_phnset_cntx_p->curSSStatus), DS_BYTE, &error);
    }

    if (g_phnset_cntx_p->curSSWaitTime == 0xFF)
    {
        g_phnset_cntx_p->curSSWaitTime = RstGetScrSaverWaitingDefault();
        WriteValue(NVRAM_SCREENSAVER_WAITING, &g_phnset_cntx_p->curSSWaitTime, DS_BYTE, &error);
    }

    if ((type = PhnsetGetDisplayType(g_phnset_cntx_p->curSsID)) == PHNSET_TYPE_DISP_INVALID)
    {
        g_phnset_cntx_p->curSsID = RstGetScrSaverImgIdDefault();
        mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));
    }
#ifdef __MMI_FILE_MANAGER__    
    else if (type == PHNSET_TYPE_DISP_USER)
    {
        ReadRecord(NVRAM_EF_WPSS_FILENAME_LID, 1, &phnset_wpss_filename, sizeof(phnset_wpss_filename), &error);
        if (error != NVRAM_READ_SUCCESS)
        {
            memset(&phnset_wpss_filename, 0, sizeof(phnset_wpss_filename));
            g_phnset_cntx_p->curSsID = RstGetScrSaverImgIdDefault();
            mmi_dispchar_set_img_id(NVRAM_CURRENT_SCREENSVER_ID, &(g_phnset_cntx_p->curSsID));
        }
    }
#endif /* __MMI_FILE_MANAGER__ */
    g_phnset_cntx_p->wpss_type = temp_type;

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetCurScrSvrName
 * DESCRIPTION
 *  This function is to get screen saver name string ptr
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
PS8 PhnsetGetCurScrSvrName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetGetCurScrSvrName: ID=%d\n", g_phnset_cntx_p->curSsID);

#ifdef __MMI_FILE_MANAGER__
    if (g_phnset_cntx_p->curSsID == 0)
    {
        if (phnset_wpss_filename.isSSShort == 1)
        {
            U8 *temp = phnset_dispchar_temp;
            PS8 p;

            /* rename short name file should pass converted short name to editor,
               so that the display will be the same as in File Manager */
            p = PhnsetGetFileNamePointer((S8*) phnset_wpss_filename.screensave);

            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) temp,
                (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH,
                (U8*) p,
                (mmi_chset_enum) PhnsetGetDefEncodingType());
            p = (PS8) & temp[0];
            return p;

        }
        else
        {
            return PhnsetGetFileNamePointer((S8*) phnset_wpss_filename.screensave);
        }
    }
    else
#endif /* __MMI_FILE_MANAGER__ */ 
        return PhnsetGetScrSvrNameById(g_phnset_cntx_p->curSsID);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetScrSvrNameById
 * DESCRIPTION
 *  This function is to get screen saver name string ptr by image ID
 * PARAMETERS
 *  Id          [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
PS8 PhnsetGetScrSvrNameById(U16 Id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 ssName = NULL;
    U32 strID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetGetScrSvrNameById: ID=%d\n", Id);

#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__)
    if (Id >= IMG_ID_PHNSET_SS_VDO_START && Id <= IMG_ID_PHNSET_SS_VDO_MAX)
    {
        ssName = GetString((U16) STR_ID_PHNSET_DISPCHAR_VDOID_START + (Id - IMG_ID_PHNSET_SS_VDO_START));
    }
    else
#endif /* defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__) */ /* defined( __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ ) && defined(__MTK_TARGET__) */
#ifdef __MMI_AVATAR__
    if (Id == IMG_ID_DISPCHAR_AVATAR_SCREENSAVER)
    {
        U32 avatar_id;
        U32 serial_num;
        dispchar_get_current_avatar_id(Id, &avatar_id, &serial_num);
        mmi_avater_get_name_by_avatarid((U32)avatar_id, (PS8)phnset_dispchar_temp);
        ssName = (PS8)phnset_dispchar_temp;
    }
    else
#endif /* __MMI_AVATAR__ */
    if (Id >= IMG_ID_PHNSET_SS_START && Id <= IMG_ID_PHNSET_SS_MAX)
    {
        strID = STR_ID_PHNSET_DISPCHAR_IMGID_START + (Id - IMG_ID_PHNSET_SS_START);
        ssName = GetString((U16) strID);
    }
    else if ((strID = getFactoryImageRelativeIndex(Id)) != 0)
    {
        DYNIMAGEINFO *Info;
        U8 i;
        U8 noFactImages = GetFullScreenFactoryImagesInfo(&Info);

        for (i = 0; i < noFactImages; i++)
        {
            if (Id == Info[i].ImagesId)
            {
                strID = STR_ID_PHNSET_DISPCHAR_IMGID_START + MAX_SCREENSAVER_IMG + i;
                break;
            }
        }
        ssName = GetString((U16) strID);
    }
#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__    
#ifdef __MMI_ANALOG_CLOCK__
    else if (Id == IMG_ID_DISPCHAR_ANALOG_CLK)
    {
        strID = STR_ID_PHNSET_DISPCHAR_ANALOG;
        ssName = GetString((U16) strID);
    }
#endif /* __MMI_ANALOG_CLOCK__ */ 

#ifdef __MMI_DIGITAL_CLOCK__
    else if (Id == IMG_ID_DISPCHAR_DIGITAL_CLK)
    {
        strID = STR_ID_PHNSET_DISPCHAR_DIGITAL;
        ssName = GetString((U16) strID);
    }
#endif /* __MMI_DIGITAL_CLOCK__ */ 
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

#ifdef __MMI_THEMES_V2_SUPPORT__
    else if (Id == IMG_ID_DISPCHAR_THEME_SCREENSAVER)
    {
        strID = STR_ID_DISPCHAR_THEME_SCREENSAVER;
        ssName = GetString((U16) strID);
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
#ifdef __MMI_SWFLASH__
else if (Id >= IMG_ID_DISPCHAR_SWFLASH_START && Id <= IMG_ID_DISPCHAR_SWFLASH_MAX)
{
    strID = STR_ID_DISPCHAR_SWFLASH_START + (Id - IMG_ID_DISPCHAR_SWFLASH_START);
    ssName = GetString((U16) strID);
}
#endif /* __MMI_SWFLASH__ */
    return ssName;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetCurScrSvrStatus
 * DESCRIPTION
 *  This function is to get screen saver status on/off
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  0 OFF, 1 ON
 *****************************************************************************/
SET_SS_SETTING_STATUS PhnsetGetCurScrSvrStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_phnset_cntx_p->curSSStatus)
    {
        case 1:
            return SET_SS_STATUS_ON;
    #ifdef __MMI_LCD_PARTIAL_ON__
        case 2:
            return SET_SS_STATUS_POWERSAVING;
    #endif /* __MMI_LCD_PARTIAL_ON__ */ 
        default:
            return SET_SS_STATUS_OFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetIsScrSvrAnalogClock
 * DESCRIPTION
 *  This function is to query if screen set Analog Clock
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  0 OFF, 1 ON
 *****************************************************************************/
BOOL PhnsetIsScrSvrAnalogClock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__    
#ifdef __MMI_ANALOG_CLOCK__
    if (g_phnset_cntx_p->curSsID == IMG_ID_DISPCHAR_ANALOG_CLK)
    {
        return TRUE;
    }
    else
#endif /* __MMI_ANALOG_CLOCK__ */ 
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

        return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetIsScrSvrDigitalClock
 * DESCRIPTION
 *  This function is to query if screen set Digital Clock
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  0 OFF, 1 ON
 *****************************************************************************/
BOOL PhnsetIsScrSvrDigitalClock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__    
#ifdef __MMI_DIGITAL_CLOCK__
    if (g_phnset_cntx_p->curSsID == IMG_ID_DISPCHAR_DIGITAL_CLK)
    {
        return TRUE;
    }
    else
#endif /* __MMI_DIGITAL_CLOCK__ */ 
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
        return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetIsScrSvrPartialOn
 * DESCRIPTION
 *  To check if the current screensaver is the partial one.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  0 OFF, 1 ON
 *****************************************************************************/
BOOL PhnsetIsScrSvrPartialOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LCD_PARTIAL_ON__
    if (g_phnset_cntx_p->curSSStatus == (S32) SET_SS_STATUS_POWERSAVING)
    {
        return TRUE;
    }
    else
#endif /* __MMI_LCD_PARTIAL_ON__ */ 
        return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disable_partial_ss
 * DESCRIPTION
 *  To disable partial screensaver.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_disable_partial_ss(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LCD_PARTIAL_ON__
    g_phnset_cntx_p->curSSStatus = (S32) SET_SS_STATUS_OFF;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_enable_partial_ss
 * DESCRIPTION
 *  To enable partial screensaver.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_enable_partial_ss(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LCD_PARTIAL_ON__
    S16 error;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LCD_PARTIAL_ON__
    ReadValue(NVRAM_SCREENSAVER_STATUS, &(g_phnset_cntx_p->curSSStatus), DS_BYTE, &error);
#endif 
}

#ifdef __MMI_THEMES_V2_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  PhnsetIsScrSvrCurrentTheme
 * DESCRIPTION
 *  To check if the current screensaver is the current theme.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  0 OFF, 1 ON
 *****************************************************************************/
BOOL PhnsetIsScrSvrCurrentTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->curSsID == IMG_ID_DISPCHAR_THEME_SCREENSAVER)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  PhnsetSSUseDefault
 * DESCRIPTION
 *  Use default build-in screensaver
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSSUseDefault(void)
{
#ifdef __MMI_FILE_MANAGER__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PHNSET_TYPE_DISP type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((type = PhnsetGetDisplayType(g_phnset_cntx_p->curSsID)) == PHNSET_TYPE_DISP_USER
        && (mmi_usb_check_path_exported((S8*) phnset_wpss_filename.screensave)))
    {
        g_phnset_cntx_p->curSsID = RstGetScrSaverImgIdDefault();
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "PhnsetSSUseDefault: ID=%d\n", g_phnset_cntx_p->curSsID);
#endif /* __MMI_FILE_MANAGER__ */
}
#endif /* __USB_IN_NORMAL_MODE__ */ 

#endif /* _SCREENSAVER_C */ 

