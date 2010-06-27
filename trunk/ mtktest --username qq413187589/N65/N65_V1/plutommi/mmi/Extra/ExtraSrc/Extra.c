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
 * Extra.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements main menu screen of Extra applications.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_EXTRA_C
#define _MMI_EXTRA_C

/*  Include: MMI header file */

#include "MainMenuDef.h"
#include "ExtraDef.h"
#include "Calculator.h" /* for calculator */
#include "unitconvertor.h"      /* for converters */
#include "Calorie.h"    /* for health */
#include "Bmi.h"
#include "Healthmenstural.h"
#include "SettingGprots.h"      /* for aphorism */
#include "SettingProt.h"
#include "SimDetectionGexdcl.h"
#include "MessagesExDcl.h"
#include "PopulateRes.h"
#if defined (__MMI_CURRENCY_CONVERTER__)
#include "currencyconvertor.h"
#elif defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
#include "CurrencyConvertorE.h"
#endif 
#if defined (__MMI_EBOOK_READER__)
#include "FileManagerGprot.h"
#include "EbookGprot.h"
#include "EbookProt.h"
#endif 
#ifdef __MMI_MESSAGES_CLUB__
#include "SATGProts.h"
#endif 
#ifdef __MMI_DICTIONARY__
#include "DictionaryMain.h"
#endif 
/* 
 * Define
 */
// #define APR_TEXT_CHARCTERS           3

/* 
 * Typedef 
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
#if defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__)
void EntryExtraHealthApp(void);
void HighlightExtraHealthMenu(void);
#endif /* defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__) */ 

/* 
 * Global Variable
 */
extern U16 gIndexIconsImageList[];

#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif 

/* 
 * Global Function
 */

#if defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__)


/*****************************************************************************
 * FUNCTION
 *  EntryExtraHealthApp
 * DESCRIPTION
 *  Display list of health applications.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryExtraHealthApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[3];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_HEALTH_MENU, NULL, EntryExtraHealthApp, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_HEALTH_MENU);
    nNumofItem = GetNumOfChild(EXTRA_HEALTH_MENU);
    GetSequenceStringIds(EXTRA_HEALTH_MENU, nStrItemList);
    SetParentHandler(EXTRA_HEALTH_MENU);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_SCR_HEALTH_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightExtraHealthMenu
 * DESCRIPTION
 *  Highlight handler of Health menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightExtraHealthMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryExtraHealthApp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryExtraHealthApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__) */ 


/*****************************************************************************
 * FUNCTION
 *  ExtraInit
 * DESCRIPTION
 *  Initialize each applications in Extra.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExtraInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calucartor */
#if defined (__MMI_CALCULATOR__)
    CalcInit();
#endif 

    /* unit converter */
#if defined (__MMI_UNIT_CONVERTER__) || defined (__MMI_EXTENDED_UNIT_CONVERTER__)
    UconvInit();
#endif 

    /* currency converter (extended version) */
#if defined (__MMI_CURRENCY_CONVERTER__)
    CconvInit();
#elif defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
    mmi_cconv_init();
#endif 

    /* health */
#if defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__)
    SetHiliteHandler(EXTRA_HEALTH_MENU, HighlightExtraHealthMenu);
#endif 

    /* bmi */
#if defined(__MMI_BMI__)
    SetHiliteHandler(EXTRA_HEALTH_MENU_BMI, HighlightBMIMenu);
#endif 

    /* menstrual */
#if defined(__MMI_MENSTRUAL__)
    MensInit();
#endif 

    /* calorie */
#if defined(__MMI_CALORIE__)
/* under construction !*/
#endif 

#ifdef __MMI_STOPWATCH__
        InitStopwatchApp();
#endif 

    /* aphorism */
#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif 
#if defined (__MMI_EBOOK_READER__)
    InitEbookApp();
    SetHiliteHandler(MAIN_MENU_EBOOK_MENUID, highlight_mainmenu_ebook);
#endif /* defined (__MMI_EBOOK_READER__) */ 
#if defined(__MMI_DICTIONARY__)
    mmi_dictionary_init();
#endif 
}

/*****************************************************************************
* FUNCTION
*  ExtraDeInit
* DESCRIPTION
*   Deinitialize each application of Extra
* PARAMETERS
*  None.
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
/*
 * void ExtraDeInit(void)
 * {  
 * #if defined(__MMI_CALENDAR__)
 * ClndrDeInit();
 * #endif
 * 
 * #if defined (__MMI_CALCULATOR__)
 * //CalcDeInit();
 * #endif
 * 
 * // currency converter (extended version) 
 * #if defined (__MMI_CURRENCY_CONVERTER__)
 * CconvDeInit();
 * #elif defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
 * //mmi_cconv_deinit();
 * #endif
 * 
 * #if defined (__MMI_UNIT_CONVERTER__) || defined(__MMI_EXTENDED_UNIT_CONVERTER__)
 * //UconvDeInit();
 * #endif
 * 
 * #if defined(__MMI_BMI__)
 * BmiDeInit();
 * #endif
 * 
 * #if defined(__MMI_MENSTRUAL__)
 * MensDeInit();
 * #endif
 * 
 * #if defined(__MMI_CALORIE__)
 * CaleDeInit();
 * #endif   
 * }
 */

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 
#if defined(__MMI_EBOOK_READER__)


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_ebook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_ebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(ebr_entry_book_shel_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ebr_entry_book_shel_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_EBOOK_READER__) */ 

#endif /* _MMI_EXTRA_C */ // #ifndef _MMI_EXTRA_C
