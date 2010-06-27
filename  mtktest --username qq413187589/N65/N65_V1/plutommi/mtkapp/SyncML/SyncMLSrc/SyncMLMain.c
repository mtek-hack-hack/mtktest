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
 *    SyncMLMain.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "wapadp.h"
#include "NetworkSetupGProt.h" /* IMG_ID_NETSET_NW_SEARCH and IMG_ID_NETSET_ABORT_LSK */
#include "SATDefs.h"           /* SAT_WAIT_IMAGE_ID */
#include "PhoneBookTypes.h"
#include "AlarmFrameWorkProt.h"

#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "ToDoListDef.h"
#include "ToDoListEnum.h"

#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountDef.h"
#include "NetworkSetupDefs.h"
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "syncml_common_customize.h"

#ifdef __MMI_SYNCML_CCA_SUPPORT__
#include "CentralConfigAgentGProt.h"
#include "CentralConfigAgentDefs.h"
#include "CentralConfigAgentConst.h"
#endif

#ifdef SYNCML_DM_SUPPORT
#include "Cbfunc.h"
#endif


#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_resource.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*
 * Local Variable
 */
syncml_context_struct g_syncml_context;
static S8 syncml_progress_info[64];
static U16 temp_luid[MAX_SYNC_ITEMS];


static void mmi_syncml_cat_progress_count_string(U8 info_number);

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init
 * DESCRIPTION
 *  Initialize highlight, hint, and protocol event handlers for SyncML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_GPRS_FEATURES__) || !defined(__MMI_VCALENDAR__) || !defined(__MMI_VCARD__)
    MMI_ASSERT(0); /* SyncML needs the GPRS support and vCard/vCalendar support */
#endif

#ifndef __MMI_OP01_SYNCML_SETTING__
    SetHiliteHandler(MENU_ID_SYNCML_MAIN, mmi_syncml_highlight_sync_menu);
    SetHiliteHandler(MENU_ID_SYNCML_SYNC, mmi_syncml_highlight_sync_now);
	SetHiliteHandler(MENU_ID_SYNCML_SETTINGS, mmi_syncml_highlight_sync_settings);
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    SetHiliteHandler(MENU_ID_SYNCML_PROFILE, mmi_syncml_highlight_sync_profile);
    SetHiliteHandler(MENU_ID_SYNCML_APPLICATIONS, mmi_syncml_highlight_applications_to_sync);

#ifndef __MMI_OP01_SYNCML_SETTING__
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    SetHiliteHandler(MENU_ID_SYNCML_TYPE, mmi_syncml_highlight_sync_type);
#endif
    SetHiliteHandler(MENU_ID_SYNCML_REGULARITY, mmi_syncml_highlight_regular_sync);
    SetHiliteHandler(MENU_ID_SYNCML_REPORT, mmi_syncml_highlight_sync_report);
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    SetHintHandler(MENU_ID_SYNCML_PROFILE, mmi_syncml_hint_sync_profile);
    SetHintHandler(MENU_ID_SYNCML_APPLICATIONS, mmi_syncml_hint_applications_to_sync);

#ifndef __MMI_OP01_SYNCML_SETTING__
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    SetHintHandler(MENU_ID_SYNCML_TYPE, mmi_syncml_hint_sync_type);
#endif
    SetHintHandler(MENU_ID_SYNCML_REGULARITY, mmi_syncml_hint_regular_sync);
    SetHintHandler(MENU_ID_SYNCML_REPORT, mmi_syncml_hint_sync_report);
#endif /* __MMI_OP01_SYNCML_SETTING__ */ 

    /* only read from nvram once, then always use the global context */
    memset(&g_syncml_context, 0, sizeof(syncml_context_struct));
    mmi_syncml_read_settings_from_nvram();

#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif

    mmi_syncml_init_profile();
    mmi_syncml_init_message_handlers();
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
    mmi_syncml_init_sas();
#endif
#ifdef SYNCML_DM_SUPPORT
    mmi_dm_set_check_function(DM_SETTING_TYPE_PIM,mmi_syncml_checking_for_dm);/*init checking function for DM*/
#endif    

    /* set the category context */
    g_syncml_context.sync_progress = 0xFF;
    if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
    {
        g_syncml_context.selected_applications[0] = 1;
    }
    if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
    {
        g_syncml_context.selected_applications[1] = 1;
    }
    if (g_syncml_context.regular_sync == SYNCML_REGULAR_SYNC_POWER_ON)
    {
        g_syncml_context.power_on_sync = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_menu
 * DESCRIPTION
 *  Synchronization main menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_sync_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_now
 * DESCRIPTION
 *  "Sync Now" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_pre_check, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_syncml_entry_sync_pre_check, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_settings
 * DESCRIPTION
 *  "Sync Settings" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_sync_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    mmi_syncml_read_profile_name_display_strings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_applications_to_sync
 * DESCRIPTION
 *  "Applications to Sync" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_applications_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_syncml_entry_applications_to_sync, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_applications_to_sync, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_type
 * DESCRIPTION
 *  "Sync Type" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_type, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_sync_type, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_regular_sync
 * DESCRIPTION
 *  "Regular Sync" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_regular_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_syncml_entry_regular_sync, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_regular_sync, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_hint_sync_profile
 * DESCRIPTION
 *  "Profile" menu hint handler
 * PARAMETERS
 *  index       [IN]            hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_hint_sync_profile(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.active_profile == 0)
    {
        /* no profile activated */
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_NO_PROFILE));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) g_syncml_context.profile_name_display[g_syncml_context.active_profile - 1]);
    }

    g_syncml_context.selected_profile = (g_syncml_context.active_profile != 0) ? (g_syncml_context.active_profile - 1) : 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_hint_applications_to_sync
 * DESCRIPTION
 *  "Applications to Sync" menu hint handler
 * PARAMETERS
 *  index       [IN]            hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_hint_applications_to_sync(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_syncml_context.applications_to_sync)
    {
        case 1:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_HINT_PHB_ONLY));
            break;

        case 2:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_HINT_TDL_ONLY));
            break;

        case 3:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_HINT_PHB_TDL));
            break;

        case 0:
        default:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_REGULARITY_NONE));
            break;
    }
}


#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_hint_sync_type
 * DESCRIPTION
 *  "Sync Type" menu hint handler
 * PARAMETERS
 *  index       [IN]            hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_hint_sync_type(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_syncml_context.sync_type)
    {
        case SYNCML_TYPE_BACKUP:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_BACKUP));
            break;

        case SYNCML_TYPE_RESTORE:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_RESTORE));
            break;

        case SYNCML_TYPE_EXPORT:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_EXPORT));
            break;

        case SYNCML_TYPE_IMPORT:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_IMPORT));
            break;

        case SYNCML_TYPE_DEFAULT:
        default:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_TWOWAY));
            break;
    }

    g_syncml_context.selected_type = g_syncml_context.sync_type;
}
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_hint_regular_sync
 * DESCRIPTION
 *  "Regular Sync" menu hint handler
 * PARAMETERS
 *  index       [IN]            hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_hint_regular_sync(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_syncml_context.regular_sync)
    {
        case 1:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_REGULARITY_DATA));
            break;

        case 2:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_REGULARITY_POWERON));
            break;

        case 3:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_REGULARITY_DAY));
            break;

        case 4:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_REGULARITY_WEEK));
            break;

        case 5:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_REGULARITY_MONTH));
            break;

        case 0:
        default:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_SYNC_REGULARITY_NONE));
            break;
    }

    g_syncml_context.selected_regularity = g_syncml_context.regular_sync;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_menu
 * DESCRIPTION
 *  Synchronization main menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 SyncMLItem[MAX_SUB_MENUS];
    U16 SyncMLIcon[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_MAIN, NULL, mmi_syncml_entry_sync_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_MAIN);
    nNumofItem = GetNumOfChild(MENU_ID_SYNCML_MAIN);
    GetSequenceStringIds(MENU_ID_SYNCML_MAIN, SyncMLItem);
    GetSequenceImageIds(MENU_ID_SYNCML_MAIN, SyncMLIcon);
    SetParentHandler(MENU_ID_SYNCML_MAIN);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_SYNC_MENU,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        SyncMLItem,
        SyncMLIcon,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_now
 * DESCRIPTION
 *  "Sync Now" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_NOW, NULL, mmi_syncml_entry_sync_now, NULL);

    if (g_syncml_context.sync_progress == 0xFF)
    {
        mmi_ucs2cpy(syncml_progress_info, GetString(STR_ID_SYNC_PROGRESS));
        mmi_ucs2cat(syncml_progress_info, (PS8)L"\n\n");
    }
    else
    {
        mmi_ucs2cpy(syncml_progress_info, GetString((U16) (STR_ID_PROGRESS_LINK_ESTABLISHED + g_syncml_context.sync_progress)));
		mmi_syncml_cat_progress_count_string(g_syncml_context.sync_progress);
		mmi_ucs2cat(syncml_progress_info, (PS8)L"\n");
    }

    ShowCategory66Screen(
        STR_ID_SYNC_NOW,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        0,
        0,
        STR_GLOBAL_CANCEL, /* STR_GLOBAL_ABORT, */
        0, /* IMG_ID_NETSET_ABORT_LSK, */
        (U8 *) syncml_progress_info,
        IMG_ID_SYNC_NOW,
        NULL);
/*
 *  SetRightSoftkeyFunction(mmi_syncml_abort_confirm, KEY_EVENT_UP);
 *  SetKeyHandler(mmi_syncml_abort_confirm, KEY_END, KEY_EVENT_DOWN);
 */
    SetRightSoftkeyFunction(mmi_syncml_background_sync_query, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_background_sync_query, KEY_END, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(
        SCR_ID_SYNC_NOW,
        (HistoryDelCBPtr) mmi_syncml_delete_sync_screen_callback);

    if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
    {
        //g_syncml_context.next_anchor = mmi_syncml_get_current_time();
        if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
        {
            g_syncml_context.next_phb_anchor = g_syncml_context.last_phb_anchor[g_syncml_context.active_profile - 1] + 1;
        }
        if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
        {
            g_syncml_context.next_tdl_anchor = g_syncml_context.last_tdl_anchor[g_syncml_context.active_profile - 1] + 1;
        }
        g_syncml_context.power_on_sync = 0;
        mmi_syncml_init_sync_report();
        mmi_syncml_get_imei_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_settings
 * DESCRIPTION
 *  "Sync Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *SyncMLHint[MAX_SUB_MENUS];
    U16 SyncMLItem[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_syncml_is_phb_sync_now() || mmi_syncml_is_tdl_sync_now())
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_PLEASE_WAIT),
            IMG_GLOBAL_PROGRESS,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_SYNC_SETTINGS, NULL, mmi_syncml_entry_sync_settings, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_SETTINGS);
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    nNumofItem = GetNumOfChild(MENU_ID_SYNCML_SETTINGS);
    GetSequenceStringIds(MENU_ID_SYNCML_SETTINGS, SyncMLItem);
    SetParentHandler(MENU_ID_SYNCML_SETTINGS);
#endif
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#ifdef __MMI_OP01_SYNCML_SETTING__ 
/* under construction !*/
#else
    ConstructHintsList(MENU_ID_SYNCML_SETTINGS, SyncMLHint);
#endif

    ShowCategory52Screen(
        STR_ID_SYNC_SETTINGS,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else 
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        SyncMLItem,
        (U16*) gIndexIconsImageList,
        SyncMLHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (g_syncml_context.profile_deactivated)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_PROFILE_DEACTIVATED),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        g_syncml_context.profile_deactivated = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_abort_confirm
 * DESCRIPTION
 *  Confirmation to abort the sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_abort_sync
 * DESCRIPTION
 *  Waiting screen to abort the sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_abort_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* press abort from synchronizing screen */
    EntryNewScreen(SCR_ID_SYNC_ABORT, NULL, mmi_syncml_abort_sync, NULL);

    ShowCategory66Screen(
        STR_ID_SYNC_NOW,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_ABORTING),
        SAT_WAIT_IMAGE_ID,
        NULL);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_NOW, NULL);
    DeleteScreenIfPresent(SCR_ID_SYNC_NOW);

    if (!g_syncml_context.abort_state)
    {
        mmi_syncml_abort_sync_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_delete_sync_screen_callback
 * DESCRIPTION
 *  Delete callback if sync waiting screen is deleted by another application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_delete_sync_screen_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_regular_sync_selection
 * DESCRIPTION
 *  Highlight handler of "Regular Sync" selctions
 * PARAMETERS
 *  index       [IN]            highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_regular_sync_selection(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.selected_regularity = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_save_regular_sync
 * DESCRIPTION
 *  Save of the regular sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_save_regular_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.regular_sync = g_syncml_context.selected_regularity;
    mmi_syncml_update_settings_to_nvram();

    if (g_syncml_context.regular_sync > SYNCML_REGULAR_SYNC_POWER_ON)
    {
        AlmSetAlarm(ALM_SYNCML);
    }
    else
    {
        AlmCancelAlarm(ALM_SYNCML);
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_SYNC_REGULARITY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cancel_regular_sync
 * DESCRIPTION
 *  Cancellation of the regular sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_cancel_regular_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.selected_regularity = g_syncml_context.regular_sync;

    DeleteScreenIfPresent(SCR_ID_SYNC_REGULARITY);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_confirm_regular_sync
 * DESCRIPTION
 *  Confirmation of the regular sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_confirm_regular_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_save_regular_sync, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_cancel_regular_sync, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_regular_sync
 * DESCRIPTION
 *  "Regular Sync" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_regular_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = SYNCML_REGULAR_SYNC_END;
    U8 *guiBuffer;
    U16 SyncMLItem[SYNCML_REGULAR_SYNC_END];

    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_REGULARITY, NULL, mmi_syncml_entry_regular_sync, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_REGULARITY);
    RegisterHighlightHandler(mmi_syncml_highlight_regular_sync_selection);

    for (i = 0; i < SYNCML_REGULAR_SYNC_END; i++)
    {
        /* fill the selection items for category */
        SyncMLItem[i] = STR_ID_SYNC_REGULARITY_NONE + i;
    }

    ShowCategory11Screen(
        STR_ID_SYNC_REGULARITY,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        SyncMLItem,
        g_syncml_context.selected_regularity,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_syncml_confirm_regular_sync, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_save_applications_to_sync
 * DESCRIPTION
 *  Save of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_save_applications_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_profile_struct temp_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.applications_to_sync = 0;
    if (g_syncml_context.selected_applications[0])
    {
        g_syncml_context.applications_to_sync |= SYNCML_DB_PHONEBOOK;
    }
    if (g_syncml_context.selected_applications[1])
    {
        g_syncml_context.applications_to_sync |= SYNCML_DB_TODOLIST;
    }

    /* add profile validation check after change applications to sync */
    if (g_syncml_context.active_profile != 0)
    {
        mmi_syncml_read_profile_from_nvram(g_syncml_context.active_profile, (void *)(&temp_profile));
        if ((g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK) && !(temp_profile.profile_validation & 0x04))
        {
            g_syncml_context.active_profile = 0;
            g_syncml_context.profile_deactivated = 1;
        }
        if ((g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST) && !(temp_profile.profile_validation & 0x08))
        {
            g_syncml_context.active_profile = 0;
            g_syncml_context.profile_deactivated = 1;
        }
    }

    mmi_syncml_update_settings_to_nvram();

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_SYNC_APPLICATIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cancel_applications_to_sync
 * DESCRIPTION
 *  Cancellation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_cancel_applications_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
    {
        g_syncml_context.selected_applications[0] = 1;
    }
    else
    {
        g_syncml_context.selected_applications[0] = 0;
    }

    if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
    {
        g_syncml_context.selected_applications[1] = 1;
    }
    else
    {
        g_syncml_context.selected_applications[1] = 0;
    }

    DeleteScreenIfPresent(SCR_ID_SYNC_APPLICATIONS);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_confirm_applications_to_sync
 * DESCRIPTION
 *  Confirmation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_confirm_applications_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_save_applications_to_sync, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_cancel_applications_to_sync, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_applications_to_sync
 * DESCRIPTION
 *  "Applications to Sync" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_applications_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 numItems = 2; // should apply SYNCML_DB_END

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_APPLICATIONS, NULL, mmi_syncml_entry_applications_to_sync, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_APPLICATIONS);
    subMenuDataPtrs[0] = (PU8) GetString((U16) STR_ID_SYNC_APP_PHB);
    subMenuDataPtrs[1] = (PU8) GetString((U16) STR_ID_SYNC_APP_TDL);

    if (guiBuffer == NULL)
    {
        if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
        {
            g_syncml_context.selected_applications[0] = 1;
        }
        else
        {
            g_syncml_context.selected_applications[0] = 0;
        }

        if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
        {
            g_syncml_context.selected_applications[1] = 1;
        }
        else
        {
            g_syncml_context.selected_applications[1] = 0;
        }
    }

    SetCheckboxToggleRightSoftkeyFunctions(mmi_syncml_confirm_applications_to_sync, GoBackHistory);
    ShowCategory140Screen(
        STR_ID_SYNC_APPLICATIONS,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        numItems,
        (U8 **) subMenuDataPtrs,
        (U8*) g_syncml_context.selected_applications,
        0,
        guiBuffer);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_update_settings_to_nvram
 * DESCRIPTION
 *  Updating settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_update_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_buf[NVRAM_EF_SYNCML_SETTING_SIZE];
    S16 error;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_buf[0] = g_syncml_context.active_profile;
    nvram_buf[1] = g_syncml_context.applications_to_sync;
    nvram_buf[2] = g_syncml_context.regular_sync;
    nvram_buf[3] = g_syncml_context.power_on_sync;
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    nvram_buf[4] = g_syncml_context.sync_type;
#else
    nvram_buf[4] = 0;
#endif
    nvram_buf[5] = g_syncml_context.sync_report_status;

    for (i = 0; i < MAX_SYNCML_PROFILES; i++)
    {
        memcpy(nvram_buf + 6 + (i * sizeof(U32)), (const void *)(&g_syncml_context.last_phb_anchor[i]), sizeof(U32));
        memcpy(nvram_buf + 6 + ((i + MAX_SYNCML_PROFILES) * sizeof(U32)), (const void *)(&g_syncml_context.last_tdl_anchor[i]), sizeof(U32));
    }

    WriteRecord(NVRAM_EF_SYNCML_SETTING_LID, 1, (void*)nvram_buf, NVRAM_EF_SYNCML_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_settings_from_nvram
 * DESCRIPTION
 *  Reading settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_read_settings_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_buf[NVRAM_EF_SYNCML_SETTING_SIZE];
    S16 error;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SYNCML_SETTING_LID, 1, (void*)nvram_buf, NVRAM_EF_SYNCML_SETTING_SIZE, &error);

    g_syncml_context.active_profile = nvram_buf[0];
    g_syncml_context.applications_to_sync = nvram_buf[1];
    g_syncml_context.regular_sync = nvram_buf[2];
    g_syncml_context.power_on_sync = nvram_buf[3];
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    g_syncml_context.sync_type = nvram_buf[4];
#endif
    g_syncml_context.sync_report_status = nvram_buf[5];

    for (i = 0; i < MAX_SYNCML_PROFILES; i++)
    {
        memcpy((void *)(&g_syncml_context.last_phb_anchor[i]), nvram_buf + 6 + (i * sizeof(U32)), sizeof(U32));
        memcpy((void *)(&g_syncml_context.last_tdl_anchor[i]), nvram_buf + 6 + ((i + MAX_SYNCML_PROFILES) * sizeof(U32)), sizeof(U32));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_query
 * DESCRIPTION
 *  Qurey screen to edit profile if no active profile is selected for sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SYNC_EDIT_QUREY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    mmi_syncml_read_profile_name_display_strings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_phb_sync_now
 * DESCRIPTION
 *  Notification to phonebook application about sync state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_syncml_is_phb_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_syncml_context.contact_sync_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_tdl_sync_now
 * DESCRIPTION
 *  Notification to to-do-list application about sync state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_syncml_is_tdl_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_syncml_context.calendar_sync_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cat_progress_count_string
 * DESCRIPTION
 *  make progress count string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_cat_progress_count_string(U8 info_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[32];
    U16 current = 0, noc = 0;
    U8 progress_f = 0; /* flag for whether to show NOC info */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (info_number)
    {
        case PROGRESS_TASK_DATASTORE_SENDING:
            current = g_syncml_context.calendar_send_current;
            noc = g_syncml_context.calendar_send_noc;
            progress_f = 1;
            break;
		
        case PROGRESS_CONTACT_DATASTORE_SENDING:
            current = g_syncml_context.contact_send_current;
            noc = g_syncml_context.contact_send_noc;
            progress_f = 1;
            break;
		
        case PROGRESS_TASK_DATASTORE_RECEIVED:
            current = g_syncml_context.calendar_recv_current;
            noc = g_syncml_context.calendar_recv_noc;
            progress_f = 1;
            break;
		
        case PROGRESS_CONTACT_DATASTORE_RECEIVED:
            current = g_syncml_context.contact_recv_current;
            noc = g_syncml_context.contact_recv_noc;
            progress_f = 1;
            break;
		
        default:
            break;
    }
    
	
    //if (noc > 0) /* excluding condition not get noc */
    if (progress_f == 1)
    {
        if (current <= noc)
        {
            kal_wsprintf((PU16)temp, " %d/%d", current, noc);
            mmi_ucs2cat((PS8)syncml_progress_info, (PS8)temp);
        }
        else
        {
            kal_wsprintf((PU16)temp, " %d", current);
            mmi_ucs2cat((PS8)syncml_progress_info, (PS8)temp);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_update_progress_string
 * DESCRIPTION
 *  Update progress info of synchronization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_update_progress_string(U8 info_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_syncml_is_phb_sync_now() || mmi_syncml_is_tdl_sync_now())
    {
        g_syncml_context.sync_progress = info_number;
        mmi_ucs2cpy(syncml_progress_info, GetString((U16) (STR_ID_PROGRESS_LINK_ESTABLISHED + info_number)));

	mmi_syncml_cat_progress_count_string(info_number);

        /* no need to update screen if active screen is not "sync now" screen */
        if (GetActiveScreenId() == SCR_ID_SYNC_NOW)
        {
            cat66_update_progress_string();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_back_idle_background_sync
 * DESCRIPTION
 *  Go back idle screen and keep background sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_back_idle_background_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_NOW, NULL);
    EntryIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_go_back_background_sync
 * DESCRIPTION
 *  Go back history and keep background sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_go_back_background_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_NOW, NULL);
    DeleteScreenIfPresent(SCR_ID_SYNC_NOW);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_background_sync_query
 * DESCRIPTION
 *  Query screen of background sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_background_sync_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_BACKGROUND_QUERY, NULL, mmi_syncml_background_sync_query, NULL);

    ShowCategory2Screen(
        STR_ID_SYNC_MENU,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        STR_GLOBAL_YES, /* LSK: yes to abort */
        IMG_GLOBAL_YES, /* RSK: no to go back and keep background sync */
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_SYNC_BACKGROUND_QUERY,
        NULL);

    SetRightSoftkeyFunction(mmi_syncml_go_back_background_sync, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_syncml_abort_sync, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_back_idle_background_sync, KEY_END, KEY_EVENT_DOWN);
}


#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_type_selection
 * DESCRIPTION
 *  Highlight handler of "Sync Type" selctions
 * PARAMETERS
 *  index       [IN]            highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_type_selection(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.selected_type = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_save_sync_type
 * DESCRIPTION
 *  Save of the sync type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_save_sync_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.sync_type = g_syncml_context.selected_type;
    mmi_syncml_update_settings_to_nvram();

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_SYNC_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cancel_sync_type
 * DESCRIPTION
 *  Cancellation of the sync type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_cancel_sync_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.selected_type = g_syncml_context.sync_type;

    DeleteScreenIfPresent(SCR_ID_SYNC_TYPE);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_confirm_sync_type
 * DESCRIPTION
 *  Confirmation of the sync type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_confirm_sync_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_save_sync_type, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_cancel_sync_type, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_type
 * DESCRIPTION
 *  "Sync Type" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = SYNCML_TYPE_END;
    U8 *guiBuffer;
    U16 SyncMLItem[SYNCML_TYPE_END];

    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_TYPE, NULL, mmi_syncml_entry_sync_type, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_TYPE);
    RegisterHighlightHandler(mmi_syncml_highlight_sync_type_selection);

    for (i = 0; i < SYNCML_TYPE_END; i++)
    {
        /* fill the selection items for category */
        SyncMLItem[i] = STR_ID_SYNC_TWOWAY + i;
    }

    ShowCategory11Screen(
        STR_ID_SYNC_TYPE,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        SyncMLItem,
        g_syncml_context.selected_type,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_syncml_confirm_sync_type, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_delete_all_records
 * DESCRIPTION
 *  Entry screen to delete all records
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_delete_all_records(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_DELETE_ALL, NULL, mmi_syncml_entry_delete_all_records, NULL);

    ShowCategory66Screen(
        STR_ID_SYNC_NOW,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        0,
        0,
        0,
        0,
        (U8 *) GetString(STR_GLOBAL_DELETE_ALL),
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_perform_delete_phb_one_by_one
 * DESCRIPTION
 *  Delete phonebook records one by one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_perform_delete_phb_one_by_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_count = mmi_phb_get_phone_index_arrary(temp_luid);

    if (temp_count == 0)
    {
        mmi_syncml_entry_sync_now();
        DeleteScreenIfPresent(SCR_ID_SYNC_DELETE_ALL);
    }
    else
    {
        mmi_phb_sync_vcard(SYNCML_RECORD_DELETE, (S8*) SYNCML_VOBJ_PATH, temp_luid[0], 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_perform_delete_all_records
 * DESCRIPTION
 *  Delete phonebook and to-do-list records
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_perform_delete_all_records(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *fs_path;
    U16 temp_count, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_entry_delete_all_records();

    /* delete all calendars */
    if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
    {
        fs_path = OslMalloc(sizeof(SYNCML_TDL_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((S8*) fs_path, (S8*) SYNCML_TDL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_TDL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_syncml_context.selected_profile + 1;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);

        temp_count = mmi_tdl_get_total_index(temp_luid);
        for (i = 0; i < temp_count; i++)
        {
            mmi_tdl_sync_task(SYNCML_RECORD_DELETE, (S8*) SYNCML_VOBJ_PATH, &temp_luid[i], 0);
        }
    }

    /* delete all contacts, performed one by one */
    if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
    {
        fs_path = OslMalloc(sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((S8*) fs_path, (S8*) SYNCML_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_syncml_context.selected_profile + 1;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);

        mmi_syncml_perform_delete_phb_one_by_one();
    }
    else
    {
        mmi_syncml_entry_sync_now();
        DeleteScreenIfPresent(SCR_ID_SYNC_DELETE_ALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_popup_sync_backup_warning
 * DESCRIPTION
 *  Query screen to start backup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_popup_sync_backup_warning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SYNC_BACKUP_WARNING),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_now, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_popup_sync_restore_warning
 * DESCRIPTION
 *  Query screen to start restore
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_popup_sync_restore_warning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SYNC_RESTORE_WARNING),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_syncml_perform_delete_all_records, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_popup_sync_restore_warning
 * DESCRIPTION
 *  Pre-check function before start sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_pre_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.active_profile == 0)
    {
        /* no available profile */
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_NO_PROFILE),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);

        GenericExitScreen(SCR_CONFIRM_SCREEN, mmi_syncml_edit_profile_query);
        return;
    }

    if (g_syncml_context.applications_to_sync == 0)
    {
        /* no selected application */
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_NO_APPLICATION),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);

        return;
    }

    if (!mmi_syncml_is_phb_ready())
    {
        /* phonebook busy */
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_PHB_BUSY),
            IMG_GLOBAL_PROGRESS,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);

        return;
    }

    if (!wap_is_ready())
    {
        /* wap not ready */
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_WAP_NOT_READY),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);

        return;
    }

#ifdef __MMI_WLAN_FEATURES__
    if ((mmi_netset_get_active_preferred_mode() == P_GSM_ONLY  && mmi_syncml_get_active_profile_bearer() > MAX_DATA_ACCOUNT_GSM_LIMIT + MAX_DATA_ACCOUNT_GPRS_LIMIT - 1) ||
        (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY && mmi_syncml_get_active_profile_bearer() < MAX_DATA_ACCOUNT_GSM_LIMIT + MAX_DATA_ACCOUNT_GPRS_LIMIT))
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_INVALID_DATA_ACCOUNT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);

        return;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    if (g_syncml_context.abort_state)
    {
        mmi_syncml_abort_sync();
    }
    else if (mmi_syncml_is_phb_sync_now() || mmi_syncml_is_tdl_sync_now())
    {
        mmi_syncml_entry_sync_now();
    }
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    else if (g_syncml_context.sync_type == SYNCML_TYPE_BACKUP)
    {
        mmi_syncml_popup_sync_backup_warning();
    }
    else if (g_syncml_context.sync_type == SYNCML_TYPE_RESTORE)
    {
        mmi_syncml_popup_sync_restore_warning();
    }
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */
    else
    {
        mmi_syncml_entry_sync_now();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_phb_ready
 * DESCRIPTION
 *  Check function if phonebook is ready to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_syncml_is_phb_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL rtn = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
    #else
        if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
    #endif
        {
            rtn = MMI_FALSE;
        }
    }
    return rtn;
}


#endif /* __SYNCML_SUPPORT__ */

