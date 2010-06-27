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
 * mainmenu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main menu
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
   Filename:      mainmenu.c
   Author:        manju, Vijay Vaidya
   Date Created:  September-07-2002
   Contains:      Main menu application
**********************************************************************************/
#include "MMI_include.h"

#include "mmiappfnptrs.h"
#include "PhoneBookDef.h"
#include "MainMenuDef.h"
#include "MainMenuProt.h"
#include "MiscFunctions.h"
#include "UserProfilesResDef.h"
#include "SettingGprots.h"
#include "FunAndGamesDefs.h"
#include "FunAndGamesProts.h"
#include "ExtraDef.h"
#include "CallHistoryMain.h"
#include "SettingDefs.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "MessagesExDcl.h"
#include "CommonScreens.h"

#include "Service.h"
#ifdef __SAT__
#include "SATGProts.h"
#endif 
#ifdef __MMI_FILE_MANAGER__
#include "FileMgr.h"
#endif 
#ifndef __DISABLE_SHORTCUTS_MENU__
#include "ShortcutsProts.h"
#endif 

#include "FunandGamesProts.h"
#include "wgui_status_icons.h"
#include "MainMenudef.h"
#include "ManageCallMain.h"
#include "IdleAppDef.h"

#include "CallSetUpEnum.h"

#include "OrganizerGProt.h"
#include "OrganizerDef.h"
#include "SettingProt.h"

#ifdef __MMI_MOBILE_SERVICE__
#include "MobileServiceGProt.h"
#endif

#ifdef __MMI_CUSTOMER_SERVICE__
#include "CustSerGProt.h"
#endif

#ifdef __MMI_MY_FAVORITE__
#include "MyFavoriteGProt.h"
#endif

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
#include "gui_custom_menus.h"
#ifdef __MMI_WGUI_MINI_TAB_BAR__
#include "wgui_tab_bars.h"
#endif 

extern U8 PhnsetGetMainMenuStyle(void);
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#if (defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_USB_SUPPORT__) || defined(__MMI_BT_SUPPORT__))
#include "ExtDeviceDefs.h"
#endif 

#ifdef  __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#endif  /*  __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif


extern void EntryIdleScreen(void);

extern void mmi_profiles_entry_main_screen(void);
extern void mmi_phb_reset_scr_id(void);

#ifdef __SAT__
extern void GoToSATMainMenu(void);
#endif

#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
extern void IdleHandleKeypadLockProcess(void);
extern void IdleHandlePoundKeyForKeypadLock(void);
#endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 

extern U16 gMainMenuTitleIcon[];
extern main_menu_index;
extern S32 MMI_main_menu_type;
extern UI_3D_circular_menu wgui_CM3D_menu;

#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
extern void shuffle_draw_white(void);
#endif 

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
extern void mmi_fmrdo_skip_highlight_hdlr(S32 index);   /* defined in FMRadioSrc.c */
extern U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids); /* defined in FMRadioSrc.c */
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 

#ifdef WAP_SUPPORT
extern void goto_mobile_suite_screen(void);
#endif

#ifdef __MMI_UCM__
extern void mmi_ucm_entry_call_center(void);
#endif /* __MMI_UCM__ */

/*****************************************************************************
 * FUNCTION
 *  handle_mainmenu_right_softkey_up
 * DESCRIPTION
 *  Go to previous screen when rt soft key
 *  is released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_mainmenu_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_profiles
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 *  
 *  AUTHOR            :Ashima
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_profiles_entry_main_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    /* if(gPrevScreenIndicator == ENTER_SIM_INSERTION) */

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_profiles_entry_main_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#endif /* __MMI_OP01_MENU_9MATRIX__ */

}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_phonebook
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_phb_entry_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_messages
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

#ifdef __MOD_SMSAL__
    SetLeftSoftkeyFunction(EntryScrMessagesMenuList, KEY_EVENT_UP);     /* sms-code */
#endif 
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_funandgames
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_funandgames(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_fng_entry_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
	
    /* if(gPrevScreenIndicator == ENTER_SIM_INSERTION) */
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_fng_entry_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_organizer
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_organizer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryOrganizer, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    /* if(gPrevScreenIndicator == ENTER_SIM_INSERTION) */
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryOrganizer, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_settings
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha0420 */
    SetLeftSoftkeyFunction(EntryScrSettingMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryScrSettingMenu, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}

#ifdef __MMI_MESSAGES_CLUB__


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_msgclub
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_msgclub(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

#ifdef __MOD_SMSAL__
    SetLeftSoftkeyFunction(mmi_msg_club_entry_level_1, KEY_EVENT_UP);   /* sms-code */
#endif 
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}
#endif /* __MMI_MESSAGES_CLUB__ */ 


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_shortcuts
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __DISABLE_SHORTCUTS_MENU__
void highlight_mainmenu_shortcuts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryShctInMainMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

#if defined(__MMI_VERSION_2__)
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryShctInMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#else
    SetKeyHandler(EntryShctInMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#endif /* defined(__MMI_VERSION_2__) */
}
#endif /* __DISABLE_SHORTCUTS_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_services
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha1223 */
#ifdef __MMI_MERGE_SAT_TO_MAINMENU__
    /* micha1217 */
#ifndef WAP_SUPPORT
    /* micha0601 */
    if (IsSATPresent())
    {
        SetLeftSoftkeyFunction(GoToSATMainMenu, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);
    }
#else /* WAP_SUPPORT */ 
    SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);
#endif /* WAP_SUPPORT */ 

#else /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

    SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);

#endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}

#ifdef __MMI_OP01_MENU_9MATRIX__
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
#ifdef WAP_SUPPORT
/* under construction !*/
#else
/* under construction !*/
#endif /* WAP_SUPPORT */ 
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

#ifdef __MMI_CUSTOMER_SERVICE__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_cust_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_cust_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_custser_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}
#endif /* __MMI_CUSTOMER_SERVICE__ */

#ifdef __MMI_MOBILE_SERVICE__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_op_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_op_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_optrser_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}

#endif /* __MMI_MOBILE_SERVICE__ */

#ifdef __MMI_MY_FAVORITE__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_my_favorite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_my_favorite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_my_favorite_entry_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}
#endif /* __MMI_MY_FAVORITE__ */

#ifdef __MMI_OP01_MENU_NOSIM_LIST__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_multimedia_no_sim
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_multimedia_no_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryMainMultimediaNoSim, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryMainMultimediaNoSim, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_organizer_no_sim
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_organizer_no_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryOrganizerNoSim, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
   
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryOrganizerNoSim, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}

#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */



#if defined(GSENSOR_SUPPORT) || defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
#include "nvram_common_defs.h"
#include "NVRAMProt.h"
#endif


#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 

#if !defined(byte)
#define byte char 
#endif

extern byte CalibrantionData[6];
extern unsigned short NVRAM_GSENSOR_DATA ;

void Read_GSensor_Data(void)
{
	S16 ErrCode = 0 ;	
	ReadRecord(NVRAM_G_SENSOR_LID, 1, (void *)&NVRAM_GSENSOR_DATA, NVRAM_G_SENSOR_SIZE, &ErrCode);
	if( NVRAM_GSENSOR_DATA > 1)
		NVRAM_GSENSOR_DATA = 1;	
}

extern void SetClibrantionData(byte * CalibrantionData );


void ReadClibrantionData(void)
{
	S16 ErrCode = 0 ;
	ReadRecord(NVRAM_G_SENSOR_CALIBRANTION_LID, 1, (void *)CalibrantionData, NVRAM_G_SENSOR_CALIBRANTION_SIZE, &ErrCode);	
	
   	SetClibrantionData( CalibrantionData );
}

void StoreCibrantionData(char * DataArr,unsigned char len )	
{
       S16 ErrCode = 0 ;
	if ( len != 6)
		len = 6 ;

	WriteRecord(NVRAM_G_SENSOR_CALIBRANTION_LID, 1, (void *)CalibrantionData, NVRAM_G_SENSOR_CALIBRANTION_SIZE, &ErrCode);	
	
}

int GSensorInitedFlag = 0 ;
void Init_GSensorData(void)
{
	Read_GSensor_Data();
	ReadClibrantionData();
	GSensorInitedFlag = 1 ;
}


void mmi_entry_g_sersor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nImgIltemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *hintList[MAX_SUB_MENUS];    /* Array for hint */

	S16 ErrCode = 0 ;
	unsigned 	short nvram_data = 0 ;	
	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_G_SENSOR_LID, 1, (void *)&nvram_data, NVRAM_G_SENSOR_SIZE, &ErrCode);	

#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n 1 Huyanwei debug nvram_data =%d ,ErrCode =%d\n",nvram_data,ErrCode);
#endif
    if (nvram_data > 1)	
		nvram_data = 1 ;

    if(nvram_data == 0)
		nvram_data = 1;	
   else
		nvram_data = 2;
	
#if defined(NOKE_DEBUG)	
   noke_dbg_printf("\r\n2 Huyanwei debug %d\n",nvram_data);
#endif
    EntryNewScreen(SCR_G_SENSOR, NULL, mmi_entry_g_sersor, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_G_SENSOR);  /* Getting the Index from history */

    {
        nNumofItem = GetNumOfChild(MENU_ID_GSENSOR_0);
        GetSequenceStringIds(MENU_ID_GSENSOR_0, nStrItemList);
        GetSequenceImageIds(MENU_ID_GSENSOR_0, nImgIltemList);
        SetParentHandler(MENU_ID_GSENSOR_0);
        /* Construct List To Show Hint */
        ConstructHintsList(MENU_ID_GSENSOR_0, hintList);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Screen with hint, if no hint needed, can change to Screen 15 */
#if 0	
    ShowCategory52Screen(
        G_SENSOR_STRING,
        G_SENSOR_IMAGE,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        nImgIltemList,
        hintList,
        0,
        0,
        guiBuffer);
#else
	 ShowCategory15Screen(
        G_SENSOR_STRING,
        G_SENSOR_IMAGE,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        nImgIltemList,
        LIST_MENU,
        nvram_data,
        guiBuffer);
  
#endif
 /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

void highlight_g_sensor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 030705 Calvin modified */
	
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_g_sersor, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_g_sersor, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
	
}


typedef enum _G_SENSOR_DATA_TYPE_
{
	G_SENSOR_ON= 0 ,
	G_SENSOR_OFF	
}G_SENSOR_DATA_TYPE;


void mmi_write_g_sensor_data(unsigned char data)
{
	S16 ErrCode = 0 ;
	unsigned short g_sensor_data = 0 ;
	unsigned 	short nvram_data = 0 ;	

	
	g_sensor_data = data ;	
	ReadRecord(NVRAM_G_SENSOR_LID, 1, (void *)&nvram_data, NVRAM_G_SENSOR_SIZE, &ErrCode);	

	if( g_sensor_data == nvram_data )
	{
		return ;
	}
	
	switch(data)
	{
		case G_SENSOR_ON:
			g_sensor_data = 0 ;
			NVRAM_GSENSOR_DATA = 0 ;
			WriteRecord(NVRAM_G_SENSOR_LID, 1, (void *)&g_sensor_data, NVRAM_G_SENSOR_SIZE, &ErrCode);
			break;
		case G_SENSOR_OFF:
			g_sensor_data = 1;
			NVRAM_GSENSOR_DATA = 1 ;
			WriteRecord(NVRAM_G_SENSOR_LID, 1, (void *)&g_sensor_data, NVRAM_G_SENSOR_SIZE, &ErrCode);
			break;
		default:
			g_sensor_data = 0 ;
			NVRAM_GSENSOR_DATA = 0 ;
			WriteRecord(NVRAM_G_SENSOR_LID, 1, (void *)&g_sensor_data, NVRAM_G_SENSOR_SIZE, &ErrCode);
			break;
	}
}



void mmi_entry_g_sersor_on(void)
{
	mmi_write_g_sensor_data(G_SENSOR_ON);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Huyanwei Debug G Sensor On ......\r\n");	
#endif
	GoBackHistory();
}

void highlight_g_sensor_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 030705 Calvin modified */
	
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_g_sersor_on, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_g_sersor_on, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }	
}


void mmi_entry_g_sersor_off(void)
{
	mmi_write_g_sensor_data(G_SENSOR_OFF);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Huyanwei Debug G Sensor Off  ......\r\n");	
#endif
	GoBackHistory();	
}

void highlight_g_sensor_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 030705 Calvin modified */
	
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_g_sersor_off, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_g_sersor_off, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }	
}


extern void Calibrantion_GSensor(void);

void entry_g_sersor_calibrantion(void)
{
	Calibrantion_GSensor();
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Huyanwei Debug G Sensor Calibrantion  ......\r\n");

#endif
	GoBackHistory();
}

extern S8 EMFMUnicodeDisplayBuf[];  /* display buffer */
extern U8 EMFMAsciiDisplayBuf[];

void mmi_entry_g_sersor_calibrantion(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_reset_clip();

    clear_screen();
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();//yuyang
    EntryNewScreen(MENU_ID_GSENSOR_1, NULL, mmi_entry_g_sersor_calibrantion, NULL);    
		
#if 0	
	 sprintf((S8*) EMFMAsciiDisplayBuf, "\r\nPlease keep this Phone flat ,then press OK Key to Calibrante G sensor ,press back key to exit this menu.\r\n");
        AnsiiToUnicodeString(EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);
			
        ShowCategory7Screen(
        G_SENSOR_CALIBRATION_STRING,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) EMFMUnicodeDisplayBuf,
        NULL);
#else
        ShowCategory7Screen(
        G_SENSOR_CALIBRATION_STRING,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(G_SENSOR_CALIBRATION_DES_STRNG),
        NULL);
#endif
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);//yuyang

 /* 9.Register function with right softkey */	
    SetLeftSoftkeyFunction(entry_g_sersor_calibrantion, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);	
}

void highlight_g_sensor_calibrantion(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 030705 Calvin modified */
	
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_g_sersor_calibrantion, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_g_sersor_calibrantion, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }	
}


#endif



#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
extern unsigned short  NVRAM_HORSERACE_DATA;

void mmi_entry_horserace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nImgIltemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *hintList[MAX_SUB_MENUS];    /* Array for hint */


	S16 ErrCode = 0 ;
	unsigned short nvram_data = 0 ;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ReadRecord(NVRAM_HORSERACE_LID, 1, (void *)&nvram_data, NVRAM_HORSERACE_SIZE, &ErrCode);
	if(nvram_data > 4  )
		nvram_data = 4;

    EntryNewScreen(SCR_HORSERACE, NULL, mmi_entry_horserace, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_HORSERACE);  /* Getting the Index from history */

    {
        nNumofItem = GetNumOfChild(MENU_ID_HORSERACE_0);
        GetSequenceStringIds(MENU_ID_HORSERACE_0, nStrItemList);
        GetSequenceImageIds(MENU_ID_HORSERACE_0, nImgIltemList);
        SetParentHandler(MENU_ID_HORSERACE_0);
		
        /* Construct List To Show Hint */
        ConstructHintsList(MENU_ID_HORSERACE_0, hintList);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Screen with hint, if no hint needed, can change to Screen 15 */
#if 0	
    ShowCategory52Screen(
        G_SENSOR_STRING,
        G_SENSOR_IMAGE,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        nImgIltemList,
        hintList,
        0,
        0,
        guiBuffer);
#else
	 ShowCategory15Screen(
        HORSERACE_STRING,
        HORSERACE_IMAGE,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        nImgIltemList,
        LIST_MENU,
        nvram_data,
        guiBuffer);
  
#endif
 /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


void highlight_horserace(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_horserace, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_horserace, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
	
}


typedef enum _HORSERACE_DATA_TYPE_
{
	HORSERACE_DAFAULT = 0,
	HORSERACE_ONE,
	HORSERACE_TWO,
	HORSERACE_THREE,
	HORSERACE_OFF  ,
}HORSERACE_DATA_TYPE;


void mmi_write_horserace_data(unsigned char data)
{
	S16 ErrCode = 0 ;
	unsigned short horserace_data = 0 ;
	unsigned short nvram_data = 0 ;

	
	horserace_data = data ;
	ReadRecord(NVRAM_HORSERACE_LID, 1, (void *)&nvram_data, NVRAM_HORSERACE_SIZE, &ErrCode);

	if( horserace_data == nvram_data )
	{
		return ;
	}
	
	switch(data)
	{
		case HORSERACE_DAFAULT:
			horserace_data = 0 ;
			NVRAM_HORSERACE_DATA = 0;
			WriteRecord(NVRAM_HORSERACE_LID, 1, (void *)&horserace_data, NVRAM_HORSERACE_SIZE, &ErrCode);
			break;
		case HORSERACE_ONE:
			horserace_data = 1;
			NVRAM_HORSERACE_DATA = 1 ;
			WriteRecord(NVRAM_HORSERACE_LID, 1, (void *)&horserace_data, NVRAM_HORSERACE_SIZE, &ErrCode);
			break;
		case HORSERACE_TWO:
			horserace_data = 2;
			NVRAM_HORSERACE_DATA = 2 ;			
			WriteRecord(NVRAM_HORSERACE_LID, 1, (void *)&horserace_data, NVRAM_HORSERACE_SIZE, &ErrCode);
			break;
		case HORSERACE_THREE:
			horserace_data = 3;
			NVRAM_HORSERACE_DATA	=3 ;		
			WriteRecord(NVRAM_HORSERACE_LID, 1, (void *)&horserace_data, NVRAM_HORSERACE_SIZE, &ErrCode);
			break;		
		case HORSERACE_OFF:
			horserace_data = 4;
			NVRAM_HORSERACE_DATA = 4;			
			WriteRecord(NVRAM_HORSERACE_LID, 1, (void *)&horserace_data, NVRAM_HORSERACE_SIZE, &ErrCode);
			break;				
		default:
			horserace_data = 0 ;
			NVRAM_HORSERACE_DATA= 0 ;
			WriteRecord(NVRAM_HORSERACE_LID, 1, (void *)&horserace_data, NVRAM_HORSERACE_SIZE, &ErrCode);
			break;
	}
	
}


void mmi_entry_horserace_default(void)
{	
       mmi_write_horserace_data(HORSERACE_DAFAULT);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug Horse Race Default ......\r\n");
#endif
	GoBackHistory();
}

void highlight_horserace_default(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_horserace_default, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_horserace_default, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
	
}



void mmi_entry_horserace_one(void)
{
       mmi_write_horserace_data(HORSERACE_ONE);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug Horse Race One ......\r\n");
#endif
	GoBackHistory();
}

void highlight_horserace_one(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_horserace_one, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_horserace_one, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}




void mmi_entry_horserace_two(void)
{
       mmi_write_horserace_data(HORSERACE_TWO);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug Horse Race Two ......\r\n");
#endif
	GoBackHistory();	
}

void highlight_horserace_two(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_horserace_two, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_horserace_two, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}



void mmi_entry_horserace_three(void)
{
       mmi_write_horserace_data(HORSERACE_THREE);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug Horse Race Three ......\r\n");
#endif
	GoBackHistory();	
}

void highlight_horserace_three(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_horserace_three, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_horserace_three, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


void mmi_entry_horserace_off(void)
{
       mmi_write_horserace_data(HORSERACE_OFF);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug Horse Race Off  ......\r\n");
#endif
	GoBackHistory();
}

void highlight_horserace_off(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_entry_horserace_off, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(mmi_entry_horserace_off, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


#endif

/*****************************************************************************
 * FUNCTION
 *  initalize_main_menu_application
 * DESCRIPTION
 *  Set all highlte handler for main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initalize_main_menu_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MAIN_MENU_PROFILES_MENUID, highlight_mainmenu_profiles);
    SetHiliteHandler(MAIN_MENU_PHONEBOOK_MENUID, highlight_mainmenu_phonebook);
    SetHiliteHandler(MAIN_MENU_PHONEBOOK_NO_SIM_MENUID, highlight_mainmenu_phonebook);
    SetHiliteHandler(MAIN_MENU_MESSAGES_MENUID, highlight_mainmenu_messages);
    SetHiliteHandler(MAIN_MENU_FUNANDGAMES_MENUID, highlight_mainmenu_funandgames);
    SetHiliteHandler(MAIN_MENU_ORGANIZER_MENUID, highlight_mainmenu_organizer);
    SetHiliteHandler(MAIN_MENU_SETTINGS_MENUID, highlight_mainmenu_settings);
    SetHiliteHandler(MAIN_MENU_SETTINGS_NO_SIM_MENUID, highlight_mainmenu_settings);    /* diamond, 2005/12/23 Phone setup in option menu */
#ifdef __MMI_MESSAGES_CLUB__
    SetHiliteHandler(MAIN_MENU_MSGCLUB_MENUID, highlight_mainmenu_msgclub);
#endif 
#ifndef __DISABLE_SHORTCUTS_MENU__
    SetHiliteHandler(EXTRA_SHORTCUTS_MENUID, highlight_mainmenu_shortcuts);
#endif 
    SetHiliteHandler(MAIN_MENU_SERVICES_MENUID, highlight_mainmenu_services);

#ifdef __MMI_UCM__
    SetHiliteHandler(MAIN_MENU_CALL_CENTER, highlight_mainmenu_callcenter);
#else /* __MMI_UCM__ */
    SetHiliteHandler(MAIN_MENU_CALL_HISTORY, highlight_mainmenu_callhistory);
#endif /* __MMI_UCM__ */
    
    SetHiliteHandler(MAIN_MENU_MULTIMEDIA_MENUID, highlight_mainmenu_multimedia);
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    SetHiliteHandler(MAIN_MENU_OPTION_AVZONE_MENUID, highlight_mainmenu_avzone);
#endif 

#if defined(__MMI_FILE_MANAGER__)
    SetHiliteHandler(MAIN_MENU_FILE_MNGR_MENUID, highlight_mainmenu_filemngr);
#endif 

#if defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__)
    SetHiliteHandler(MAIN_MENU_EXTRA_MENUID, highlight_mainmenu_extra);
#endif /* defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__) */

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */
#ifdef __MMI_CUSTOMER_SERVICE__
    SetHiliteHandler(MAIN_MENU_CUST_SERVICES_MENUID, highlight_mainmenu_cust_services);
#endif /* __MMI_CUSTOMER_SERVICE__ */
#ifdef __MMI_MOBILE_SERVICE__
    SetHiliteHandler(MAIN_MENU_OP_SERVICES_MENUID, highlight_mainmenu_op_services);
#endif /* __MMI_MOBILE_SERVICE__ */
#ifdef __MMI_MY_FAVORITE__
    SetHiliteHandler(MAIN_MENU_MY_FAVORITE_MENUID, highlight_mainmenu_my_favorite);
#endif /* __MMI_MY_FAVORITE__ */
#ifdef __MMI_OP01_MENU_NOSIM_LIST__
    SetHiliteHandler(MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID, highlight_mainmenu_multimedia_no_sim);
    SetHiliteHandler(MAIN_MENU_ORGANIZER_NO_SIM_MENUID, highlight_mainmenu_organizer_no_sim);
#endif /* __MMI_OP01_MENU_NOSIM_LIST_ */




#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
    SetHiliteHandler(MENU_ID_GSENSOR_0, highlight_g_sensor);
    SetHiliteHandler(MENU_ID_GSENSOR_1, highlight_g_sensor_on);
    SetHiliteHandler(MENU_ID_GSENSOR_2, highlight_g_sensor_off);
    SetHiliteHandler(MENU_ID_GSENSOR_3, highlight_g_sensor_calibrantion);
#endif

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
    SetHiliteHandler(MENU_ID_HORSERACE_0, highlight_horserace);
    SetHiliteHandler(MENU_ID_HORSERACE_1, highlight_horserace_default);
    SetHiliteHandler(MENU_ID_HORSERACE_2, highlight_horserace_one);
    SetHiliteHandler(MENU_ID_HORSERACE_3, highlight_horserace_two);
    SetHiliteHandler(MENU_ID_HORSERACE_4, highlight_horserace_three);
    SetHiliteHandler(MENU_ID_HORSERACE_5, highlight_horserace_off);
#endif

    mmi_frm_set_highlight_handler();
    initialize_mainmenu_title_icons();
}


/*****************************************************************************
 * FUNCTION
 *  main_menu_shortcut_executer
 * DESCRIPTION
 *  Shortcut handler to main menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void main_menu_shortcut_executer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items = GetNumOfChild(IDLE_SCREEN_MENU_ID);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * When matrix item number > 9, the menu shortcut will fail when going
     * to an invalid index. See fixed_matrix_goto_item().
     */
    if ((MMI_current_menu_type == MATRIX_MENU) &&
        (MMI_fixed_matrix_menu.last_highlighted_item == -2))
    {
        return;
    }
    
    if (index >= 0 && index < n_items)
    {
        execute_left_softkey_function(KEY_EVENT_UP);
    }
}

/* /PMT NEERAJ START 20050616 */
#if defined(__MMI_MAINMENU_TAB_SUPPORT__) && defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)  /* 071705 Calvin modified */


/*****************************************************************************
 * FUNCTION
 *  set_main_menu_tab_pane
 * DESCRIPTION
 *  Set tab pane function for main menu in tab pane
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_menu_tab_pane(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE mm_stringIDs[MAX_MAIN_MENU_ITEMS];
    MMI_ID_TYPE mm_iconIDs[MAX_MAIN_MENU_ITEMS];
    MMI_ID_TYPE mm_iconIDs_display[MAX_MAIN_MENU_ITEMS];
    MMI_ID_TYPE *iconList;
    S32 n_items;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_items = GetNumOfChild(IDLE_SCREEN_MENU_ID);
    GetSequenceStringIds(IDLE_SCREEN_MENU_ID, mm_stringIDs);
    GetSequenceImageIds(IDLE_SCREEN_MENU_ID, mm_iconIDs);
    for (i = 0; i < (MAIN_MENU_TAB_ICON_IMGBASE_MAX - MAIN_MENU_TAB_ICON_IMGBASE); i++)
    {
        mm_iconIDs_display[i] = MAIN_MENU_TAB_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
    }
    iconList = mm_iconIDs_display;
    SetParentHandler(IDLE_SCREEN_MENU_ID);
    register_tab_pane_hilite_handler(ExecuteCurrHiliteHandler);
    set_tab_pane(n_items, mm_stringIDs, iconList, 0);
}
#endif /* defined(__MMI_MAINMENU_TAB_SUPPORT__) && defined(__MMI_MAINMENU_STYLE_CHANGE_EN__) */ 
/* PMT NEERAJ END 20050616 */


/*****************************************************************************
 * FUNCTION
 *  main_menu_custom_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void main_menu_custom_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
    gdi_layer_lock_frame_buffer();
#endif 

    ExecuteCurrHiliteHandler_Ext(index);

#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
    gdi_layer_unlock_frame_buffer();
    gui_BLT_double_buffer(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT, UI_device_width - 1, UI_device_height - 1);
#endif /* __MMI_UI_DALMATIAN_SOFTKEYS__ */ 

#ifndef __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__    /* 030705 Calvin added */
    if (MMI_main_menu_type != ROTATE_MENU && MMI_main_menu_type != CIRCULAR_3D_MENU)    /* 113004 Calvin added if check */
    {
    #ifndef __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR_ICON__
        ChangeTitleIcon((U16) gMainMenuTitleIcon[index]);
    #endif /* __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR_ICON__ */

        draw_title();
    }
#endif /* __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__ */ 

    main_menu_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  EntryMainMenuFromIdleScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainMenuFromIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    g_idle_context.ToMainMenuScrFromIdleApp = 1;
#endif 
    goto_main_menu();
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
extern void ShowCategory414Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                U16 *list_of_icons2,
                U16 *list_of_menuitem_id,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  list_matrix_main_menu_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void list_matrix_main_menu_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items;
    U16 nMenuItemList[MAX_SUB_MENUS];

    MMI_ID_TYPE mm_stringIDs[MAX_SUB_MENUS];
    MMI_ID_TYPE mm_iconIDs[MAX_SUB_MENUS];
    U8 *history_buffer;
    list_matrix_menu_category_history *h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds(IDLE_SCREEN_MENU_ID, nMenuItemList);
    if (nMenuItemList[index] == MAIN_MENU_FILE_MNGR_MENUID)
    {
        return;
    }
    history_buffer = GetCurrGuiBuffer(MAIN_MENU_SCREENID);
    GetSequenceStringIds(nMenuItemList[index], mm_stringIDs);
    GetSequenceImageIds(nMenuItemList[index], mm_iconIDs);
    SetParentHandler(nMenuItemList[index]);
    n_items = GetNumOfChild(nMenuItemList[index]);
    MMI_matrix_highlight_handler = ExecuteCurrHiliteHandler;
    ChangeTitleString((U8*) GetString(GetStringIdOfItem(nMenuItemList[index])));
    MMI_title_icon = NULL;
    draw_title();
    if (history_buffer != NULL)
    {
        h = (list_matrix_menu_category_history*) history_buffer;
        ShowCat414Matrix(n_items, mm_stringIDs, mm_iconIDs, MATRIX_MENU, 0, &(h->matrix_menu_history));
    }
    else
    {
        ShowCat414Matrix(n_items, mm_stringIDs, mm_iconIDs, MATRIX_MENU, 0, NULL);
    }
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#ifdef __MMI_WGUI_MINI_TAB_BAR__
extern U16 *GetSeqItems(U16 ParentItemId);
#endif 


/*****************************************************************************
 * FUNCTION
 *  goto_main_menu
 * DESCRIPTION
 *  Display the main menu.
 *  
 *  This a entry function for the main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL If_Main_menu=FALSE;
void goto_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ID_TYPE mm_stringIDs[MAX_MAIN_MENU_ITEMS];
    MMI_ID_TYPE mm_iconIDs[MAX_MAIN_MENU_ITEMS];

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MMI_ID_TYPE mm_iconID2[MAX_MAIN_MENU_ITEMS];
    U16 nMenuItemList[MAX_SUB_MENUS];
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    U8 *history_buffer;
    S32 n_items;
    S32 attributes;
    U8 HighlightMenu = 0;
    MMI_ID_TYPE *iconList;

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    U8 menu_style = 0;
    MMI_ID_TYPE mm_iconIDs_display[MAX_MAIN_MENU_ITEMS];
    U8 i = 0;
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    U8 j = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
If_Main_menu=TRUE;
    mmi_phb_reset_scr_id();

    EntryNewScreen(MAIN_MENU_SCREENID, exit_main_menu, NULL, MMI_FULL_SCREEN);

    history_buffer = GetCurrGuiBuffer(MAIN_MENU_SCREENID);
    n_items = GetNumOfChild(IDLE_SCREEN_MENU_ID);
    GetSequenceStringIds(IDLE_SCREEN_MENU_ID, mm_stringIDs);
    GetSequenceImageIds(IDLE_SCREEN_MENU_ID, mm_iconIDs);
    SetParentHandler(IDLE_SCREEN_MENU_ID);
    attributes = GetDispAttributeOfItem(IDLE_SCREEN_MENU_ID);

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    GetSequenceItemIds(IDLE_SCREEN_MENU_ID, nMenuItemList);
#endif 
    /* MTK Leo add, for mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_setup_mini_tab_bar(
        MMI_content_x,
        MMI_content_y,
        MMI_content_width,
        20,
        UI_COLOR_BLACK,
        UI_COLOR_RED,
        UI_COLOR_GREY,
        9 /* n_items */ ,
        GetSeqItems(IDLE_SCREEN_MENU_ID),
        NULL);
    wgui_mini_tab_bar_set_flag_on(0x00000002 /* WGUI_MINI_TAB_BAR_IN_PARENT */ );
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
    /* MTK Leo end */

    /* RegisterHighlightHandler(main_menu_custom_highlight_handler); */

#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_CENTER__
    HighlightMenu = (n_items - 1) >> 1;
#endif /* __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_CENTER__ */ 

#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
    /* Specify the highlight item to the message */
    HighlightMenu = (U8)GetChildMenuIDIndexByParentMenuID(IDLE_SCREEN_MENU_ID, MAIN_MENU_MESSAGES_MENUID);
#endif /* __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__ */ 

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    menu_style = PhnsetGetMainMenuStyle();
    switch (menu_style)
    {
    #ifdef __MMI_MAINMENU_MATRIX_SUPPORT__  /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_MATRIX:
            attributes = MATRIX_MENU;
            for (i = 0; i < (MAIN_MENU_MATRIX_ICON_IMGBASE_MAX - MAIN_MENU_MATRIX_ICON_IMGBASE); i++)
            {
                /* U16 a = mm_iconIDs[i];
                   U16 b = MAIN_MENU_ICON_IMGBASE;
                   U16 c = MAIN_MENU_MATRIX_ICON_IMGBASE;
                   U16 d = ( mm_iconIDs[i] -MAIN_MENU_ICON_IMGBASE  );
                   U16 e = MAIN_MENU_MATRIX_ICON_IMGBASE+( mm_iconIDs[i] -MAIN_MENU_ICON_IMGBASE  );
                   printf( "%d %d %d %d %d ", a, b, c, d, e ); */
                mm_iconIDs_display[i] = MAIN_MENU_MATRIX_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
    #endif /* __MMI_MAINMENU_MATRIX_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_PAGE_SUPPORT__    /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_PAGE:
            attributes = PAGE_MENU;
            for (i = 0; i < (MAIN_MENU_PAGE_ICON_IMGBASE_MAX - MAIN_MENU_PAGE_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_PAGE_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_PAGE_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_LIST_SUPPORT__    /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_LIST:
            attributes = LIST_MENU;
            for (i = 0; i < (MAIN_MENU_LIST_ICON_IMGBASE_MAX - MAIN_MENU_LIST_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_LIST_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_LIST_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_CIRCULAR_SUPPORT__        /* 071705 Calvin modified */
        case PHNSET_MAINMENU_STYLE_CIRCULE:
            attributes = CIRCULAR_3D_MENU;
            for (i = 0; i < (MAIN_MENU_CIRCULAR_ICON_IMGBASE_MAX - MAIN_MENU_CIRCULAR_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_CIRCULAR_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_CIRCULAR_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_ROTATE_SUPPORT__
        case PHNSET_MAINMENU_STYLE_ROTATE:
            attributes = ROTATE_MENU;
            for (i = 0; i < (MAIN_MENU_ROTATE_ICON_IMGBASE_MAX - MAIN_MENU_ROTATE_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_ROTATE_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_ROTATE_SUPPORT__ */ 

            /* PMT NEERAJ START 20050616 */
        #ifdef __MMI_MAINMENU_TAB_SUPPORT__     /* 071705 Calvin modified */
        case PHNSET_MAINMENU_STYLE_TAB:
        {
            register_set_tab_pane_callback(set_main_menu_tab_pane, NULL, NULL);
            show_category_one_icon_tab_pane();
            return;
        }
        #endif /* __MMI_MAINMENU_TAB_SUPPORT__ */ 
            /* PMT NEERAJ END 20050616 */
        default:
            iconList = mm_iconIDs;
            break;
    }
#else /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
    iconList = mm_iconIDs;
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
    /* 113004 Calvin removed if-else check */
    /*
     * if((attributes==CIRCULAR_3D_MENU)||(attributes==ROTATE_MENU))
     * RegisterHighlightHandler(ExecuteCurrHiliteHandler_Ext); //MTK JL add no key clear hilite
     * else
     * RegisterHighlightHandler(main_menu_custom_highlight_handler);
     */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    RegisterHighlightHandler(list_matrix_main_menu_highlight_handler);
#else 
    RegisterHighlightHandler(main_menu_custom_highlight_handler);
#endif 
    /* Calvin end */
    /* PMT VIKAS START 20050707 */
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
    gui_register_button_shuffle(shuffle_draw_white);
#endif 
    /* PMT VIKAS END 20050707 */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    for (j = 0; j < 4; j++)
    {
        mm_iconID2[j] = mm_iconIDs[j] + 1;
    }
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    ShowCategory414Screen(
        MAIN_MENU_TITLE_TEXT,
        MAIN_MENU_TITLE_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_items,
        mm_stringIDs,
        iconList,
        mm_iconID2,
        nMenuItemList,
        attributes,
        HighlightMenu,
        (U8*) history_buffer);
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    ShowCategory14Screen(
        MAIN_MENU_TITLE_TEXT,
        MAIN_MENU_TITLE_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_items,
        mm_stringIDs,
        iconList,
        attributes,
        HighlightMenu,
        (U8*) history_buffer);
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#if (defined(__MMI_KEYPAD_LOCK_PATTERN_2__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__))
    if (g_idle_context.ToMainMenuScrFromIdleApp == 1)
    {
        StartTimer(KEYPAD_LOCK_TIMER, KEYPAD_LOCK_TIMEOUT, IdleHandleKeypadLockProcess);
        SetKeyHandler(IdleHandlePoundKeyForKeypadLock, KEY_STAR, KEY_EVENT_UP);
    }
#endif /* (defined(__MMI_KEYPAD_LOCK_PATTERN_2__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__)) */ 

    register_menu_shortcut_selected(main_menu_shortcut_executer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  exit_main_menu
 * DESCRIPTION
 *  Store the  snap shot
 *  before displaying next screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history main_menu_history;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) main_menu_history.inputBuffer, (S8*) & nHistory);
    main_menu_history.scrnID = MAIN_MENU_SCREENID;
    main_menu_history.entryFuncPtr = goto_main_menu;
    GetCategoryHistory(main_menu_history.guiBuffer);
    AddHistory(main_menu_history);
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_mini_tab_bar_set_flag_off(WGUI_MINI_TAB_BAR_IN_PARENT);
#endif 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
    g_idle_context.ToMainMenuScrFromIdleApp = 0;
#endif 
   If_Main_menu=FALSE;
}


#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_callcenter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_callcenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_ucm_entry_call_center, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

}

#else /* __MMI_UCM__ */

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_callhistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_callhistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryCHISTMainMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}

#endif /* __MMI_UCM__ */

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_multimedia
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_multimedia(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryMainMultimedia, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryMainMultimedia, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#endif /* __MMI_OP01_MENU_9MATRIX__ */
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_avzone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_avzone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryMainAVZone, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryMainAVZone, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_filemngr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_filemngr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_FILE_MANAGER__
    SetLeftSoftkeyFunction(fmgr_launch, KEY_EVENT_UP);

#if defined(__MMI_VERSION_2__)
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(fmgr_launch, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#else /* defined(__MMI_VERSION_2__) */ 
    SetKeyHandler(fmgr_launch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_VERSION_2__) */ 

#else /* __MMI_FILE_MANAGER__ */ 

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_FILE_MANAGER__ */ 
}


#if defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__)

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_extra
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_extra(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryMainExtra, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
    if (g_pwr_context.PrevScreenIndicator != ENTER_IDLE_SCR || mmi_bootup_get_active_flight_mode() != 0)
    {
        SetKeyHandler(EntryMainExtra, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#endif /* __MMI_OP01_MENU_9MATRIX__ */	
}
#endif /* defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__) */ 

/* Max: temporary define here, shall be moved to each application file */
#define SCR_FILE_MANAGER   FILE_MANAGER_BASE
#define SCR_MMEDIA         MMEDIA_BASE
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#define  SCR_AVZONE        MMEDIA_BASE+1
#endif 

#ifdef __MMI_OP01_MENU_NOSIM_LIST__
/*****************************************************************************
 * FUNCTION
 *  EntryMainMultimediaNoSim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainMultimediaNoSim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MMEDIA, NULL, EntryMainMultimediaNoSim, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MMEDIA);
    nItems = GetNumOfChild_Ext(MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_PHB_CALLER_RES_SETTING__)
    /* No SIM, remove caller picture menu items */
#if !defined( __MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() == MMI_FALSE)
#else   /*  __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid() == MMI_FALSE && MTPNP_PFAL_Is_Card2Absent())
#endif  /*  __MMI_DUAL_SIM_MASTER__ */
    {
        S32 MenuItemId;

        MenuItemId = GetChildMenuIDIndexByParentMenuID(MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID, MENU_ID_PHB_CALLER_PIC_1);
        if (MenuItemId != -1)   /* Menu Exists. */
        {
            nItems -= 1;
        }
    }
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
    RegisterHighlightHandler(mmi_fmrdo_skip_highlight_hdlr);
    nItems = mmi_fmrdo_check_chip_or_hide(nItems, ItemList, ItemIcons);
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    /* add mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID);
#endif 
    ShowCategory52Screen(
        MAIN_MENU_MMEDIA_TEXT,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  EntryMainMultimedia
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainMultimedia(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MMEDIA, NULL, EntryMainMultimedia, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MMEDIA);
    nItems = GetNumOfChild_Ext(MAIN_MENU_MULTIMEDIA_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_MULTIMEDIA_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_MULTIMEDIA_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_MULTIMEDIA_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_PHB_CALLER_RES_SETTING__)
    /* No SIM, remove caller picture menu items */
#if !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() == MMI_FALSE)
#else   /*  __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid() == MMI_FALSE && MTPNP_PFAL_Is_Card2Absent())
#endif  /*  __MMI_DUAL_SIM_MASTER__ */
    {
        S32 MenuItemId;

        MenuItemId = GetChildMenuIDIndexByParentMenuID(MAIN_MENU_MULTIMEDIA_MENUID, MENU_ID_PHB_CALLER_PIC_1);
        if (MenuItemId != -1)   /* Menu Exists. */
        {
            nItems -= 1;
        }
    }
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
    RegisterHighlightHandler(mmi_fmrdo_skip_highlight_hdlr);
    nItems = mmi_fmrdo_check_chip_or_hide(nItems, ItemList, ItemIcons);
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_MULTIMEDIA_MENUID);
#endif 
    /* MTK Leo end */

    ShowCategory52Screen(
        MAIN_MENU_MMEDIA_TEXT,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  EntryMainFileMngr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainFileMngr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall be implemented later */
}


/*****************************************************************************
 * FUNCTION
 *  ExitMainFileMngr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitMainFileMngr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall be implemented later */
}


#if defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__)
/*****************************************************************************
 * FUNCTION
 *  EntryMainExtra
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainExtra(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_EXTRA, NULL, EntryMainExtra, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_EXTRA);
    nItems = GetNumOfChild_Ext(MAIN_MENU_EXTRA_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_EXTRA_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_EXTRA_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_EXTRA_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        MAIN_MENU_EXTRA_TEXT,
        GetRootTitleIcon(MAIN_MENU_EXTRA_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /* defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__) */

#if defined(__MMI_VERSION_2__)

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__

/*****************************************************************************
 * FUNCTION
 *  EntryMainAVZone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainAVZone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_AVZONE, NULL, EntryMainAVZone, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_AVZONE);
    nItems = GetNumOfChild(MAIN_MENU_OPTION_AVZONE_MENUID);
    GetSequenceStringIds(MAIN_MENU_OPTION_AVZONE_MENUID, ItemList);
    GetSequenceImageIds(MAIN_MENU_OPTION_AVZONE_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_OPTION_AVZONE_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
    RegisterHighlightHandler(mmi_fmrdo_skip_highlight_hdlr);
    nItems = mmi_fmrdo_check_chip_or_hide(nItems, ItemList, ItemIcons);
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    /*
     * //MTK Leo add, mini_tab_bar
     * #ifdef __MMI_WGUI_MINI_TAB_BAR__
     * wgui_enable_mini_tab_bar(MAIN_MENU_AVZONE_MENU_ID);
     * #endif
     * //MTK Leo end
     */
    ShowCategory52Screen(
        MAIN_MENU_AVZONE_TEXT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#endif /* defined(__MMI_VERSION_2__) */ 


#ifdef __MMI_SUBLCD_MASTER_MODE__
static U16	main_menu_hilited_index = 0;

/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDMainMenuScreen
 * DESCRIPTION
 *  Exit SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDMainMenuScreen()
{
    main_menu_hilited_index = 0;
    ForceEntrySubLCDSlave();
    GoBackHistory();
    /*
     * At the function EntrySubLCDMasterFromIdle(), we may freeze subLCD to avoid update subLCD when interrupt occurs.
     * When exit subLCD main menu screen, we will unfreeze the subLCD.
     */
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(FALSE);
    UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenuScreen
 * DESCRIPTION
 *  Entry SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMainMenuScreenHiliteHandler(S32 index)
{
    main_menu_hilited_index = index;
    ExecuteCurrHiliteHandler(index);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenuScreen
 * DESCRIPTION
 *  Entry SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySubLCDMainMenuScreen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 numOfItems = 0;
    U16 itemList[MAX_SUB_MENUS];
    U16 itemIcon[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();
	ClearAllKeyHandler();
	
    SetParentHandler(MENU_ID_SUB_MAIN_MENU);

    numOfItems = GetNumOfChild(MENU_ID_SUB_MAIN_MENU);

    GetSequenceStringIds(MENU_ID_SUB_MAIN_MENU, itemList);
    GetSequenceImageIds(MENU_ID_SUB_MAIN_MENU, itemIcon);

    RegisterHighlightHandler(SubLCDMainMenuScreenHiliteHandler);

	
    ShowCategory314Screen(
        (U8*)GetString(MAIN_MENU_MENU_TEXT),
        0, 
        numOfItems,
        itemList,
        itemIcon,
        NULL, 
        main_menu_hilited_index,
        NULL);

    SetKeyHandler( ExitSubLCDMainMenuScreen, KEY_FWD, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenu
 * DESCRIPTION
 *  Entry SubLCD MainMenu
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 EntrySubLCDMainMenu()
{
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SUB_MAIN_MENU_SCREENID, EntrySubLCDMainMenuScreen, TRUE);
    	return TRUE;		
    }
    return FALSE;	
}

#endif /* __MMI_SUBLCD_MASTER_MODE__ */

