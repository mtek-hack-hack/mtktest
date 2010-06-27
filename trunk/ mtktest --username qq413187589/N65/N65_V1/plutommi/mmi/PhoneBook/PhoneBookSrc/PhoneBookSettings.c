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
 * PhoneBookSettings.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of feature "Settings" in the Phobebook Application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _PHONEBOOKSETTINGS_C
#define _PHONEBOOKSETTINGS_C

#include "PhoneBookTypes.h"
#include "PhoneBookDef.h"
#include "PhoneBookProt.h"
#include "PhoneBookGprot.h"
#include "ProtocolEvents.h"
#include "SpeedDial.h"
#include "CommonScreens.h"
#if defined(__MMI_VCARD__)
#include "vCard.h"
#endif 

#if defined(__MMI_PHB_CALLER_RES_SETTING__)
#include "FileMgr.h"    /* Should include FileMgr.h before ProfileMgrGprot.h */
#include "FileManagerGProt.h"
#include "UserProfilesResDef.h"
#include "ProfilesDefs.h"
#include "Profiles_Prot.h"
#include "ProfileGprots.h"      /* for GetRingToneID */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
#include "VdoPlyGProt.h"
#include "CallManagementGProt.h"
#endif 
#if defined(__MMI_IMAGE_VIEWER__)
#include "ImageViewer.h"
#endif 
#if defined(__MMI_AVATAR__)
#include "AvatarGProt.h"
#endif
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 

#include "SimDetectionGprot.h"
#include "USBDeviceGprot.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif/* __MMI_DUAL_SIM_MASTER__ */

/*
 * Define
 */

/*
 * Local Variable
 */
static U8 g_phb_temp_field_state[MAX_PB_VIEW_FIELDS];
static U8 g_phb_temp_storage;
#if defined(__MMI_PHB_NAME_LIST_FILTER__)
static U8 g_phb_temp_nlf;
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */
#if defined(__MMI_VCARD__) && defined(__MMI_VCARD_V30__)
static U8 g_phb_temp_vcard_version;
#endif /* defined(__MMI_VCARD__) && defined(__MMI_VCARD_V30__) */

/*
 * Global Variable
 */
/* For Edit vCard */
extern wgui_inline_item wgui_inline_items[];
extern U16 TitleStrings[];
extern S8 pbName[];
extern S8 pbNumber[];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
extern S8 pbHomeNumber[];
extern S8 pbCompanyName[];
extern S8 pbEmailAddress[];
extern S8 pbOfficeNumber[];
extern S8 pbFaxNumber[];
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */
extern U8 gPictureItemIndex;
extern U8 gRingtoneItemIndex;

extern pBOOL viewOnce;
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];

#if defined(__MMI_INCOMING_CALL_VIDEO__)
extern U8 g_phb_video_item_index; /* for entry_edit_mycard */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */

#if defined(__MMI_PHB_CALLER_RES_SETTING__)
#if defined(__MMI_FILE_MANAGER__)
extern S8 g_phb_file_path[];
#endif 

#if defined(__MMI_INCOMING_CALL_VIDEO__)
extern S8 g_phb_video_file_path[];
#if defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__)
extern U8 g_phb_swflash_video_minus;
extern U8 g_phb_avatar_video_minus;
#elif defined(__MMI_SWFLASH__) /* defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__) */
extern U8 g_phb_swflash_video_minus;
#elif defined(__MMI_AVATAR__)
extern U8 g_phb_avatar_video_minus;
#endif /* defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__) */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */

extern void mmi_profiles_Ext_melody_set_tone_type(PRFSET_MELODY_CONF_TYPE type);
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 

#if defined(__MMI_PHB_IMPS_FIELD__)
extern U8 phb_imps_item_index;
#endif 

/*
 * Local Function
 */
#if defined(__MMI_PHB_CALLER_RES_SETTING__) 

#if defined(__MMI_AVATAR__)
static void mmi_phb_highlight_caller_pic_file(void);
static void mmi_phb_highlight_caller_pic_avatar(void);
static void mmi_phb_caller_avatar_pic_select_from_file_manager(void);
static void mmi_phb_caller_avatar_pic_select_from_file_manager_done(U32 path_address, U32 serial_num);
#endif /* defined(__MMI_AVATAR__) */

#if defined(__MMI_INCOMING_CALL_VIDEO__)
static void mmi_phb_caller_video_preview(void);
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
static void mmi_phb_highlight_caller_video_file(void);
#if defined(__MMI_AVATAR__)
static void mmi_phb_highlight_caller_video_avatar(void);
static void mmi_phb_caller_avatar_video_select_from_file_manager(void);
static void mmi_phb_caller_avatar_video_select_from_file_manager_done(U32 id, U32 serial_num);
#endif /* defined(__MMI_AVATAR__) */
#if defined(__MMI_SWFLASH__)
static void mmi_phb_highlight_caller_video_swflash(void);
static void mmi_phb_caller_swflash_select_from_file_manager(void);
static void mmi_phb_caller_swflash_select_from_file_manager_done(void *path, int is_short);
#endif /* defined(__MMI_SWFLASH__) */
#endif /* defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__) */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */

#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */

/*
 * Global Function
 */
#if defined(__MMI_PHB_CALLER_RES_SETTING__)  
#if defined(__MMI_INCOMING_CALL_VIDEO__)
#ifdef __MMI_SWFLASH__
extern MMI_BOOL mmi_swflash_get_storage_file_path(PS8 filepath);
#endif
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_setting_init
 * DESCRIPTION
 *  Initialization of "Settings" feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_setting_init.>\n", __FILE__, __LINE__);

    /* Settings */
    SetHiliteHandler(MITEM110_PBOOK_SETTINGS, mmi_phb_highlight_setting);
    SetHiliteHandler(MITEM110_PBOOK_SETTINGS_NO_SIM, mmi_phb_highlight_setting);
    SetHiliteHandler(MITEM1101_PBOOK_MEMORY_STATUS, mmi_phb_highlight_memory_status);
    SetHiliteHandler(MITEM1102_PBOOK_STORAGE_LOCATION, mmi_phb_highlight_storage_location);
    SetHiliteHandler(MITEM_STORAGE_LOCATION_SIM, mmi_phb_highlight_storage_location_in_sim);
    SetHiliteHandler(MITEM_STORAGE_LOCATION_PHONE, mmi_phb_highlight_storage_location_in_phone);
    SetHiliteHandler(MITEM1103_PBOOK_VIEW_FIELDS, mmi_phb_highlight_view_field);

    /* Preferred Storage */
    SetHintHandler(MITEM1102_PBOOK_STORAGE_LOCATION, mmi_phb_hint_storage_location);
    SetHintHandler(MITEM_STORAGE_LOCATION_SIM, mmi_phb_hint_storage_location_in_sim);
    SetHintHandler(MITEM_STORAGE_LOCATION_PHONE, mmi_phb_hint_storage_location_in_phone);

    /* Name List Filter */
#if defined(__MMI_PHB_NAME_LIST_FILTER__)
    SetHiliteHandler(MENU_ID_PHB_NAME_LIST_FILTER, mmi_phb_highlight_name_list_filter);
    SetHiliteHandler(MENU_ID_PHB_NLF_SIM, mmi_phb_highlight_nlf_sim);
    SetHiliteHandler(MENU_ID_PHB_NLF_PHONE, mmi_phb_highlight_nlf_phone);
    SetHiliteHandler(MENU_ID_PHB_NLF_BOTH, mmi_phb_highlight_nlf_both);
#ifdef __MMI_DUAL_SIM_MASTER__
    SetHiliteHandler(MENU_MTPNP_PHB_NLF_SIM2, highlight_Card2_nlf_sim);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetHintHandler(MENU_ID_PHB_NAME_LIST_FILTER, mmi_phb_hint_name_list_filter);
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */

#if defined(__MMI_VCARD__)
    /* My vCard */
    SetHiliteHandler(MENU_ID_PHB_VCARD_MYCARD, mmi_phb_highlight_vcard_mycard);
    SetHiliteHandler(MENU_ID_PHB_VCARD_EDIT_MYCARD, mmi_phb_highlight_vcard_edit_mycard);
    SetHiliteHandler(MENU_ID_PHB_VCARD_SEND_MYCARD, mmi_phb_highlight_vcard_send_mycard);

#if defined(__MMI_VCARD_V30__)
    /* vCard version */
    SetHiliteHandler(MENU_ID_PHB_VCARD_VERSION, mmi_phb_highlight_vcard_version);
    SetHintHandler(MENU_ID_PHB_VCARD_VERSION, mmi_phb_hint_vcard_version);
    SetHiliteHandler(MENU_ID_PHB_VCARD_VERSION_21, mmi_phb_highlight_vcard_version_21);
    SetHiliteHandler(MENU_ID_PHB_VCARD_VERSION_30, mmi_phb_highlight_vcard_version_30);
#endif /* defined(__MMI_VCARD_V30__) */
#endif /* defined(__MMI_VCARD__) */

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_init_speak_name();
    SetHiliteHandler(MENU_ID_PHB_SPEAK_NAME, mmi_phb_highlight_speak_name);
    SetHintHandler(MENU_ID_PHB_SPEAK_NAME, mmi_phb_hint_speak_name);
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

    /* Forward resource to phonebook entry */
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
    /* For submenu in phonebook */
    SetHiliteHandler(MENU_ID_PHB_CALLER_PIC, mmi_phb_highlight_caller_pic);
#if defined(__MMI_AVATAR__)
    SetHiliteHandler(MENU_ID_PHB_CALLER_PIC_FILE, mmi_phb_highlight_caller_pic_file);
    SetHiliteHandler(MENU_ID_PHB_CALLER_PIC_AVATAR, mmi_phb_highlight_caller_pic_avatar);
#endif /* __MMI_AVATAR__ */
    SetHiliteHandler(MENU_ID_PHB_CALLER_RING, mmi_phb_highlight_caller_ring);
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    SetHiliteHandler(MENU_ID_PHB_CALLER_VIDEO, mmi_phb_highlight_caller_video);
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
    SetHiliteHandler(MENU_ID_PHB_CALLER_VIDEO_FILE, mmi_phb_highlight_caller_video_file);
#if defined(__MMI_AVATAR__)
    SetHiliteHandler(MENU_ID_PHB_CALLER_VIDEO_AVATAR, mmi_phb_highlight_caller_video_avatar);
#endif /* __MMI_AVATAR__ */
#if defined(__MMI_SWFLASH__)
    SetHiliteHandler(MENU_ID_PHB_CALLER_VIDEO_SWFLASH, mmi_phb_highlight_caller_video_swflash);
#endif /* __MMI_SWFLASH__ */
#endif /* defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__) */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */

    /* For submenu in other application, link to same menu */
    SetHiliteHandler(MENU_ID_PHB_CALLER_PIC_1, mmi_phb_highlight_caller_pic);
    SetHiliteHandler(MENU_ID_PHB_CALLER_RING_1, mmi_phb_highlight_caller_ring);
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_setting
 * DESCRIPTION
 *  Highlight handler for Settings in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_setting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_setting
 * DESCRIPTION
 *  Draws the Phonebook settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_setting.>\n", __FILE__, __LINE__);
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready)
#endif /* __MMI_DUAL_SIM_MASTER__ */	
    {
        EntryNewScreen(SCR_PBSETTINGS_LIST, mmi_phb_exit_setting, mmi_phb_entry_setting, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_PBSETTINGS_LIST);  /* Getting the Index from history  */
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (mmi_bootup_is_sim_valid() || mmi_bootup_is_sim2_valid())
    #else /* __MMI_DUAL_SIM_MASTER__ */
        if (mmi_bootup_is_sim_valid())
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        {
            nNumofItem = GetNumOfChild(MITEM110_PBOOK_SETTINGS);
            GetSequenceStringIds(MITEM110_PBOOK_SETTINGS, nStrItemList);
            SetParentHandler(MITEM110_PBOOK_SETTINGS);
            ConstructHintsList(MITEM110_PBOOK_SETTINGS, nHintList);
        }
        else
        {
            nNumofItem = GetNumOfChild(MITEM110_PBOOK_SETTINGS_NO_SIM);
            GetSequenceStringIds(MITEM110_PBOOK_SETTINGS_NO_SIM, nStrItemList);
            SetParentHandler(MITEM110_PBOOK_SETTINGS_NO_SIM);
            ConstructHintsList(MITEM110_PBOOK_SETTINGS_NO_SIM, nHintList);
        }

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        ShowCategory52Screen(
            STR_SCR_PBSETTINGS_LIST_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            nHintList,
            0,
            0,
            guiBuffer);
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_setting
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_setting()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_PBSETTINGS_LIST;
}

#define MMI_PHB_SETTING_MEMORY


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_memory_status
 * DESCRIPTION
 *  Highlight handler for Memory Status in Settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_memory_status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_memory_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_memory_status
 * DESCRIPTION
 *  Draws the memory status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 memoryStatus[100];
    S8 tmpStr[10];
    S8 tmpStr_UCS2[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_memory_status.>\n", __FILE__,
                         __LINE__);

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
    else
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        memset(memoryStatus, 0, 100);
        if (mmi_bootup_is_sim_valid())
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            mmi_ucs2ncat(memoryStatus, GetString(STRING_MTPNP_SIM1_MEMORY_STATUS), 16);
        #else /* __MMI_DUAL_SIM_MASTER__ */
            mmi_ucs2ncat(memoryStatus, GetString(STR_MEMORY_STATUS_SIM), 16);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            memset(tmpStr, 0, 10);
            sprintf(tmpStr, ": %d/%d\n", g_phb_cntx.sim_used, g_phb_cntx.sim_total);
            mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
            mmi_ucs2cat(memoryStatus, tmpStr_UCS2);
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (mmi_bootup_is_sim2_valid())
        {
            mmi_ucs2ncat(memoryStatus, GetString(STRING_MTPNP_SLAVE_MEMORY_STATUS), 24);
            memset(tmpStr, 0, 10);
            sprintf(tmpStr, ": %d/%d\n", (U16)MTPNP_AD_ADN_SIM2GetUsedNumber(),(U16)MTPNP_AD_ADN_SIM2GetCapacity());
            mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
            mmi_ucs2cat(memoryStatus, tmpStr_UCS2);
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        mmi_ucs2ncat(memoryStatus, GetString(STR_MEMORY_STATUS_PHONE), 16);
        memset(tmpStr, 0, 10);
        sprintf(tmpStr, ": %d/%d", g_phb_cntx.phone_used, g_phb_cntx.phone_total);
        mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
        mmi_ucs2cat(memoryStatus, tmpStr_UCS2);

        EntryNewScreen(SCR_MEMORY_STATUS, mmi_phb_exit_memory_status, mmi_phb_entry_memory_status, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_MEMORY_STATUS);
        ShowCategory7Screen(
            STR_GLOBAL_MEMORY_STATUS,
            IMG_SCR_PBOOK_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) memoryStatus,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_memory_status
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_memory_status()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_MEMORY_STATUS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_memory_status_get_sim
 * DESCRIPTION
 *  Gets the memory usage for SIM
 * PARAMETERS
 *  ucs2_status     [IN/OUT]        Buffer for result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_memory_status_get_sim(S8 *ucs2_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_status[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_sim_valid())
    {
        sprintf(ascii_status, "%d/%d", g_phb_cntx.sim_used, g_phb_cntx.sim_total);
    }
    else
    {
        sprintf(ascii_status, "%d/%d", 0, 0);
    }
    mmi_asc_to_ucs2(ucs2_status, ascii_status);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_memory_status_get_phone
 * DESCRIPTION
 *  Gets the memory usage for Phone
 * PARAMETERS
 *  ucs2_status     [IN/OUT]        Buffer for result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_memory_status_get_phone(S8 *ucs2_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_status[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(ascii_status, "%d/%d", g_phb_cntx.phone_used, g_phb_cntx.phone_total);
    mmi_asc_to_ucs2(ucs2_status, ascii_status);
}

#define MMI_PHB_SETTING_STORAGE


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_storage_location
 * DESCRIPTION
 *  Highlight handler for Preferred Storage in Setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_storage_location(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_storage_location, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_storage_location, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_storage_location
 * DESCRIPTION
 *  Hint handler for Preferred Storage in Setting menu
 * PARAMETERS
 *  index       [IN]        Hint item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_storage_location(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_phb_cntx.prefer_storage == MMI_SIM)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STRING_MTPNP_SIM1_MEMORY_STATUS));
    }
    else if(g_phb_cntx.prefer_storage == MMI_NVRAM)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_STORAGE_PHONE));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STRING_MTPNP_PHB_STORAGE_SIM2));
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.prefer_storage == MMI_SIM)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_STORAGE_SIM));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_STORAGE_PHONE));
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_storage_location_in_sim
 * DESCRIPTION
 *  Highlight handler for SIM in Preferred Storage menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_storage_location_in_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_storage_location_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_storage = MMI_SIM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_storage_location_in_phone
 * DESCRIPTION
 *  Highlight handler for Phone in Preferred Storage menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_storage_location_in_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_storage_location_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_storage = MMI_NVRAM;
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  highlightPreferStoragLocationinSIM2
 * DESCRIPTION
 *  Highlight handler for SIM2 in Preferred Storage menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlightPreferStoragLocationinSIM2(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

	SetLeftSoftkeyFunction(mmi_phb_storage_location_set_req,KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	g_phb_temp_storage = MMI_SIM2;

}
#endif  /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_storage_location_in_sim
 * DESCRIPTION
 *  Hint handler for SIM in Preferred Storage menu
 * PARAMETERS
 *  index       [IN]        Hint item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_storage_location_in_sim(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 simStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_sim(simStatus);
    mmi_ucs2cpy((S8*) hintData[index], simStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_storage_location_in_phone
 * DESCRIPTION
 *  Hint handler for Phone in Preferred Storage menu
 * PARAMETERS
 *  index       [IN]        Hint item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_storage_location_in_phone(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 phoneStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_phone(phoneStatus);
    mmi_ucs2cpy((S8*) hintData[index], phoneStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_storage_location
 * DESCRIPTION
 *  Draws the preferred storage menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_storage_location(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 nStrItemList[3];
    U8 *nStrList[3];
    U8 *nHintList[3];
#else/* __MMI_DUAL_SIM_MASTER__ */
    U16 nStrItemList[2];
    U8 *nStrList[2];
    U8 *nHintList[2];
#endif/* __MMI_DUAL_SIM_MASTER__ */
    U16 nNumofItem;
    U8 hiliteStorage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_storage_location.>\n", __FILE__,
                         __LINE__);
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
    else
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif
    {
        EntryNewScreen(
            SCR_STORAGE_LOCATION_OPTIONS,
            mmi_phb_exit_storage_location,
            mmi_phb_entry_storage_location,
            NULL);

        switch(g_phb_cntx.prefer_storage)
        {
            case MMI_SIM:
                hiliteStorage = GetIndexOfStringId(MITEM1102_PBOOK_STORAGE_LOCATION, MITEM_STORAGE_LOCATION_SIM);
                break;
        #ifdef __MMI_DUAL_SIM_MASTER__
            case MMI_SIM2:
                hiliteStorage = GetIndexOfStringId(MITEM1102_PBOOK_STORAGE_LOCATION, MENU_MTPNP_PB_PRE_STORAGE_SIM2);
                break;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            case MMI_NVRAM:
                hiliteStorage = GetIndexOfStringId(MITEM1102_PBOOK_STORAGE_LOCATION, MITEM_STORAGE_LOCATION_PHONE);
                break;
            default:
                hiliteStorage = GetIndexOfStringId(MITEM1102_PBOOK_STORAGE_LOCATION, MITEM_STORAGE_LOCATION_SIM);
                break;
        }
        guiBuffer = GetCurrGuiBuffer(SCR_STORAGE_LOCATION_OPTIONS);
        nNumofItem = GetNumOfChild(MITEM1102_PBOOK_STORAGE_LOCATION);
        GetSequenceStringIds(MITEM1102_PBOOK_STORAGE_LOCATION, nStrItemList);
        SetParentHandler(MITEM1102_PBOOK_STORAGE_LOCATION);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ConstructHintsList(MITEM1102_PBOOK_STORAGE_LOCATION, nHintList);
        nStrList[0] = (PU8) GetString(nStrItemList[0]);
        nStrList[1] = (PU8) GetString(nStrItemList[1]);  
#ifdef __MMI_DUAL_SIM_MASTER__
        nStrList[2] = (PU8)GetString(nStrItemList[2]);
#endif/* __MMI_DUAL_SIM_MASTER__ */
        ShowCategory109Screen(
            STR_GLOBAL_PREFERRED_STORAGE,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrList,
            nHintList,
            hiliteStorage,
            guiBuffer);
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_storage_location
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_storage_location()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_storage_location(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_STORAGE_LOCATION_OPTIONS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_storage_location_set_req
 * DESCRIPTION
 *  Sends the request to L4 to save the preferred storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_storage_location_set_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    MSG_PHB_SET_PREFERRED_STORAGE_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 tempStorageLocation;    /* Temp Solution For Write 2 bytes NVRAM_PHB_STORAGE_LOCATION */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_storage_location_set_req.>\n", __FILE__,
                         __LINE__);

    if (g_phb_cntx.prefer_storage != g_phb_temp_storage)
    {
        myMsgPtr =
            (MSG_PHB_SET_PREFERRED_STORAGE_REQ_STRUCT*)
            OslConstructDataPtr(sizeof(MSG_PHB_SET_PREFERRED_STORAGE_REQ_STRUCT));

        g_phb_cntx.prefer_storage = g_phb_temp_storage;

        myMsgPtr->storage = g_phb_cntx.prefer_storage;
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_SET_PREFERRED_STORAGE_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);

        tempStorageLocation = g_phb_cntx.prefer_storage;
        WriteValue(NVRAM_PHB_STORAGE_LOCATION, &tempStorageLocation, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteNScrId(SCR_STORAGE_LOCATION_OPTIONS);
}

#define MMI_PHB_SETTING_FIELDS


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_view_field
 * DESCRIPTION
 *  Highlight handler for "Fields" in Settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_view_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_view_field, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_view_field, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_field_get_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U8 *mmi_phb_view_field_get_string(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = STR_GLOBAL_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        case MMI_PHB_FIELD_HOME:
            str_id = STR_HOME_NUMBER;
            break;
        case MMI_PHB_FIELD_COMPANY_NAME:
            str_id = STR_COMPNAY_NAME;
            break;
        case MMI_PHB_FIELD_EMAIL:
            str_id = STR_EMAIL_ADRESS;
            break;
        case MMI_PHB_FIELD_OFFICE:
            str_id = STR_OFFICE_NUMBER;
            break;
        case MMI_PHB_FIELD_FAX:
            str_id = STR_FAX_NUMBER;
            break;
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
        case MMI_PHB_FIELD_PIC:
            str_id = STR_ASSOCIATE_PICTURE;
            break;
        case MMI_PHB_FIELD_RING:
            str_id = STR_ASSOCIATE_SOUND;
            break;
        case MMI_PHB_FIELD_GROUP:
            str_id = STR_CALLER_GROUP;
            break;
    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            str_id = STR_ID_PHB_ASSOCIATE_VIDEO;
            break;
    #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            str_id = STR_ID_PHB_BIRTHDAY;
            break;
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
        default:
            break;
    }

    return (U8*) GetString(str_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_view_field
 * DESCRIPTION
 *  Draws the Phonebook view fields screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_view_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *viewFields[MAX_PB_VIEW_FIELDS];
    U8 i, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Assign string for each view field */
    for (i = (MMI_PHB_FIELD_NUMBER + 1); i < MMI_PHB_FIELD_TOTAL; i++)
    {
        viewFields[count++] = mmi_phb_view_field_get_string(i);
    }

    /* Read out setting from NVRAM */
    if (!g_phb_cntx.nvram_data_init)
    {
        mmi_phb_init_get_data_from_nvram();
        g_phb_cntx.nvram_data_init = TRUE;
    }

    memcpy(g_phb_temp_field_state, g_phb_cntx.view_field, MAX_PB_VIEW_FIELDS);

    EntryNewScreen(SCR_VIEW_FIELDS, mmi_phb_exit_view_field, mmi_phb_entry_view_field, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_VIEW_FIELDS);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_phb_entry_view_field_save_confirm, GoBackHistory);

    ShowCategory140Screen(
        STR_ID_PHB_SETTING_VIEW_FIELDS,
        IMG_SCR_PBOOK_CAPTION,
        count,
        viewFields,
        g_phb_temp_field_state,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_view_field
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_view_field()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_view_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_VIEW_FIELDS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_view_field_save_confirm
 * DESCRIPTION
 *  Confirms before saving the chnages in view  fields settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_view_field_save_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_phb_view_field_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_field_save
 * DESCRIPTION
 *  Saves the change in view fields setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_view_field_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 viewField[NVRAM_PHB_SETTINGS_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_phb_cntx.view_field, g_phb_temp_field_state, MAX_PB_VIEW_FIELDS);
    memset(viewField, 1, NVRAM_PHB_SETTINGS_SIZE);
    memcpy(viewField, g_phb_cntx.view_field, MAX_PB_VIEW_FIELDS);
    WriteRecord(NVRAM_EF_PHB_SETTINGS_LID, 1, viewField, NVRAM_PHB_SETTINGS_SIZE, &pError);

    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteNScrId(SCR_VIEW_FIELDS);
}


/*-----------------------------------------------------Begin of Name List Filter---------------------------------------------*/
#if defined(__MMI_PHB_NAME_LIST_FILTER__)
#define MMI_PHB_SETTING_NAME_LIST_FILTER

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_name_list_filter
 * DESCRIPTION
 *  Highlight handler for Name List Filter in Setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_name_list_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_name_list_filter, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_name_list_filter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_name_list_filter
 * DESCRIPTION
 *  Hint handler for Name List Filter in Setting menu
 * PARAMETERS
 *  index       [IN]        Hint item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_name_list_filter(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_phb_cntx.name_list_filter == MMI_STORAGE_BOTH)
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STRING_MTPNP_NLF_ALL));
    }
    else if (g_phb_cntx.name_list_filter == MMI_SIM2)
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STRING_MTPNP_SIM2PHB_PRESTORAGE));
    }
    else if (g_phb_cntx.name_list_filter == MMI_SIM)
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STRING_MTPNP_NLF_SIM1));
    }
    else
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_PHB_NLF_PHONE));
    }
#else/* __MMI_DUAL_SIM_MASTER__ */
   	if (g_phb_cntx.name_list_filter == MMI_STORAGE_BOTH)
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_PHB_NLF_BOTH));
    }
    else if (g_phb_cntx.name_list_filter == MMI_SIM)
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_PHB_NLF_SIM));
    }
    else
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_PHB_NLF_PHONE));
    }
#endif/* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_nlf_sim
 * DESCRIPTION
 *  Highlight handler for SIM in Name List Filter menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_nlf_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_nlf_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_nlf = MMI_SIM;
}


#ifdef __MMI_DUAL_SIM_MASTER__
void highlight_Card2_nlf_sim(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_nlf_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_nlf = MMI_SIM2;
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_nlf_phone
 * DESCRIPTION
 *  Highlight handler for Phone in Name List Filter menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_nlf_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_nlf_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_nlf = MMI_NVRAM;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_nlf_both
 * DESCRIPTION
 *  Highlight handler for Both in Name List Filter menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_nlf_both(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_nlf_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_nlf = MMI_STORAGE_BOTH;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_name_list_filter
 * DESCRIPTION
 *  Draws the name list filter menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_name_list_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 nStrItemList[4];
    U8 *nStrList[4];
    U8 *nHintList[4];
#else /* __MMI_DUAL_SIM_MASTER__ */
    U16 nStrItemList[3];
    U8 *nStrList[3];
    U8 *nHintList[3];
#endif /* __MMI_DUAL_SIM_MASTER__ */
    U16 nNumofItem;
    U8 hiliteStorage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.name_list_filter == MMI_SIM)
    {
        hiliteStorage = GetIndexOfStringId(MENU_ID_PHB_NAME_LIST_FILTER, MENU_ID_PHB_NLF_SIM);;
    }
    else if (g_phb_cntx.name_list_filter == MMI_NVRAM)
    {
        hiliteStorage = GetIndexOfStringId(MENU_ID_PHB_NAME_LIST_FILTER, MENU_ID_PHB_NLF_PHONE);;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (g_phb_cntx.name_list_filter == MMI_SIM2)
    {
        hiliteStorage = GetIndexOfStringId(MENU_ID_PHB_NAME_LIST_FILTER, MENU_MTPNP_PHB_NLF_SIM2);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    else
    {
        hiliteStorage = GetIndexOfStringId(MENU_ID_PHB_NAME_LIST_FILTER, MENU_ID_PHB_NLF_BOTH);
    }

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_name_list_filter.>\n", __FILE__,
                         __LINE__);
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else/* __MERCURY_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif
    {
        EntryNewScreen(
            SCR_ID_PHB_NAME_LIST_FILTER_OPTIONS,
            mmi_phb_exit_name_list_filter,
            mmi_phb_entry_name_list_filter,
            NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_NAME_LIST_FILTER_OPTIONS);
#ifdef __MMI_DUAL_SIM_MASTER__
        nNumofItem = GetNumOfChild(MENU_ID_PHB_NAME_LIST_FILTER);
        GetSequenceStringIds(MENU_ID_PHB_NAME_LIST_FILTER, nStrItemList);
#else
        nNumofItem = GetNumOfChild_Ext(MENU_ID_PHB_NAME_LIST_FILTER);
        GetSequenceStringIds_Ext(MENU_ID_PHB_NAME_LIST_FILTER, nStrItemList);
#endif
        SetParentHandler(MENU_ID_PHB_NAME_LIST_FILTER);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ConstructHintsList(MENU_ID_PHB_NAME_LIST_FILTER, nHintList);
#ifdef __MMI_DUAL_SIM_MASTER__
        nStrList[0] = (PU8) GetString(nStrItemList[0]);
        nStrList[1] = (PU8) GetString(nStrItemList[1]);
        nStrList[2] = (PU8) GetString(nStrItemList[2]);
        nStrList[3] = (PU8) GetString(nStrItemList[3]);
#else/* __MMI_DUAL_SIM_MASTER__ */
        nStrList[0] = (PU8) GetString(nStrItemList[0]);
        nStrList[1] = (PU8) GetString(nStrItemList[1]);
        nStrList[2] = (PU8) GetString(nStrItemList[2]);
#endif/* __MMI_DUAL_SIM_MASTER__ */
        ShowCategory109Screen(
            STR_ID_PHB_NLF,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrList,
            nHintList,
            hiliteStorage,
            guiBuffer);

    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_name_list_filter
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_name_list_filter()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_name_list_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_NAME_LIST_FILTER_OPTIONS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_nlf_set_req
 * DESCRIPTION
 *  Sends the request to L4 to save the preferred storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_nlf_set_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 tempNameListFilter;    /* Temp Solution For Write 2 bytes NVRAM_PHB_NAME_LIST_FILTER */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_nlf_set_req.>\n", __FILE__,
                         __LINE__);

    if (g_phb_cntx.name_list_filter != g_phb_temp_nlf)
    {
        g_phb_cntx.name_list_filter = g_phb_temp_nlf;
        tempNameListFilter = g_phb_cntx.name_list_filter;
        WriteValue(NVRAM_PHB_NAME_LIST_FILTER, &tempNameListFilter, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteNScrId(SCR_ID_PHB_NAME_LIST_FILTER_OPTIONS);
}
#endif /* defined(__MMI_PHB_NAME_LIST_FILTER__) */
/*-----------------------------------------------------End of Name List Filter-----------------------------------------------*/



/*-----------------------------------------------------Begin of vCard -------------------------------------------------------*/
#define MMI_PHB_SETTING_VCARD
#if defined(__MMI_VCARD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_vcard_send_select_card
 * DESCRIPTION
 *  Highlight function of vcard option -> Send through SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_vcard_send_select_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vcard_forward_option_select_card, KEY_EVENT_UP);
    SetKeyHandler(mmi_vcard_forward_option_select_card, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_VCARD__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_vcard_mycard
 * DESCRIPTION
 *  Highlight function of vcard option -> Send through SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_vcard_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_mycard, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_entry_mycard, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_vcard_edit_mycard
 * DESCRIPTION
 *  Highlight function of vcard option -> Send through SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_vcard_edit_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VCARD__)
    SetLeftSoftkeyFunction(mmi_phb_entry_edit_mycard, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_edit_mycard, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* defined(__MMI_VCARD__) */ 
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_VCARD__) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_vcard_send_mycard
 * DESCRIPTION
 *  Highlight function of vcard option -> Send through SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_vcard_send_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VCARD__)
    SetLeftSoftkeyFunction(mmi_vcard_forward_option_my_card, KEY_EVENT_UP);
    SetKeyHandler(mmi_vcard_forward_option_my_card, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* defined(__MMI_VCARD__) */ 
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_VCARD__) */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mycard
 * DESCRIPTION
 *  Inline Editor Screen of My vCard for editing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mycard(void)
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
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_mycard.>\n", __FILE__, __LINE__);

    EntryNewScreen(SCR_ID_PHB_VCARD_MYCARD, mmi_phb_exit_mycard, mmi_phb_entry_mycard, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_VCARD_MYCARD);
    nNumofItem = GetNumOfChild(MENU_ID_PHB_VCARD_MYCARD);
    GetSequenceStringIds(MENU_ID_PHB_VCARD_MYCARD, nStrItemList);
    SetParentHandler(MENU_ID_PHB_VCARD_MYCARD);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_PHB_VCARD,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_mycard
 * DESCRIPTION
 *  Inline Editor Screen of My vCard for editing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_VCARD_MYCARD;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_edit_mycard
 * DESCRIPTION
 *  Inline Editor Screen of My vCard for editing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_edit_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S16 pError;
    U8 item_index = 0;
    U16 DetailPbNameImageList[MAX_PB_FIELDS];
    MMI_PHB_VCARD_STRUCT myCard;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_edit_mycard.>\n", __FILE__,
                         __LINE__);
    EntryNewScreen(SCR_ID_PHB_VCARD_EDIT_MYCARD, mmi_phb_exit_edit_mycard, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_VCARD_EDIT_MYCARD);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_PHB_VCARD_EDIT_MYCARD, &inputBufferSize);

    gPictureItemIndex = 0xff;   /* Set to default before use. */
    gRingtoneItemIndex = 0xff;
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    g_phb_video_item_index = 0xff;
#endif 
#if defined(__MMI_PHB_IMPS_FIELD__)
    phb_imps_item_index = 0xff;
#endif 

    RegisterHighlightHandler(mmi_phb_op_edit_highlight_hdlr);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    EnableInlineItemDefaultText();
#endif
    if (guiBuffer == NULL)
    {
        ReadRecord(NVRAM_EF_PHB_VCARD_LID, 1, (void*)&myCard, MMI_PHB_VCARD_RECORD_SIZE, &pError);

        mmi_ucs2cpy(pbName, myCard.name);
        mmi_asc_to_ucs2(pbNumber, myCard.number);
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)        
        mmi_asc_to_ucs2(pbHomeNumber, myCard.homeNumber);
        mmi_ucs2cpy(pbCompanyName, myCard.companyName);
        mmi_asc_to_ucs2(pbEmailAddress, myCard.emailAddress);
        mmi_asc_to_ucs2(pbOfficeNumber, myCard.officeNumber);
        mmi_asc_to_ucs2(pbFaxNumber, myCard.faxNumber);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */        
    }

    mmi_phb_op_fill_inline_item(
        MMI_PHB_FIELD_NAME,
        item_index++,
        MAX_PB_PHONE_ENTRIES - 1,
        TitleStrings,
        DetailPbNameImageList);
    mmi_phb_op_fill_inline_item(
        MMI_PHB_FIELD_NUMBER,
        item_index++,
        MAX_PB_PHONE_ENTRIES - 1,
        TitleStrings,
        DetailPbNameImageList);

#ifndef __MMI_PHB_NO_OPTIONAL_FIELD__
    /* Fill inline item for each option field */
    for (item_index = (MMI_PHB_FIELD_HOME); item_index <= MMI_PHB_FIELD_FAX; item_index++)
    {
        mmi_phb_op_fill_inline_item(
            item_index,
            item_index,
            MAX_PB_PHONE_ENTRIES - 1,
            TitleStrings,
            DetailPbNameImageList);
    }
#endif /* __MMI_PHB_NO_OPTIONAL_FIELD__ */ 

#if 1   /* Disable image and sound in my card first, will enable when can send image and sound through IrDa */
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
    }
#else /* 1 */ 
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
#endif /* 1 */ 

#ifdef GUI_SUBMENU_USE_THICK_TITLE
    image_id = GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID);
#else
    image_id = IMG_STORAGE_HANDSET;
#endif

    ShowCategory57Screen(
        STR_SCR_INLINE_EDIT_CAPTION,
        image_id,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_edit_mycard_confirm_save, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_edit_mycard
 * DESCRIPTION
 *  Exit Screen for edit my vcard.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_edit_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_VCARD_EDIT_MYCARD;
    gPictureItemIndex = 10;
    mmi_phb_stop_ring_tone_id();
    CloseCategory57Screen();

    h.scrnID = SCR_ID_PHB_VCARD_EDIT_MYCARD;
    h.entryFuncPtr = mmi_phb_entry_edit_mycard;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_pre_save_mycard
 * DESCRIPTION
 *  check vcard fields
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_vcard_pre_save_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_op_check_pre_save(TRUE))
    {
        return;
    }
    mmi_phb_vcard_save_mycard();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_edit_mycard_confirm_save
 * DESCRIPTION
 *  save confirmation for edit my vcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_edit_mycard_confirm_save(void)
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

    SetLeftSoftkeyFunction(mmi_phb_vcard_pre_save_mycard, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_save_mycard
 * DESCRIPTION
 *  save my vcard to flash
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_vcard_save_mycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_PHB_VCARD_STRUCT myCard;
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(myCard.name, pbName);
    mmi_ucs2_to_asc(myCard.number, pbNumber);
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)    
    mmi_ucs2_to_asc(myCard.homeNumber, pbHomeNumber);
    mmi_ucs2cpy(myCard.companyName, pbCompanyName);
    mmi_ucs2_to_asc(myCard.emailAddress, pbEmailAddress);
    mmi_ucs2_to_asc(myCard.officeNumber, pbOfficeNumber);
    mmi_ucs2_to_asc(myCard.faxNumber, pbFaxNumber);
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */    
    myCard.pictureTagID = g_phb_cntx.image_id_list[g_phb_cntx.selected_pic_index];
    myCard.ringToneID = g_phb_cntx.ring_tone_list[g_phb_cntx.selected_ring_index];

    WriteRecord(NVRAM_EF_PHB_VCARD_LID, 1, (void*)&myCard, MMI_PHB_VCARD_RECORD_SIZE, &pError);

    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteNScrId(SCR_ID_PHB_VCARD_EDIT_MYCARD);
}

/*-----------------------------------------------------END of vCard-------------------------------------------------------*/

/*------------------------------------------------Start of vCard Version--------------------------------------------------*/
#if defined(__MMI_VCARD__) && defined(__MMI_VCARD_V30__)

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_vcard_version
 * DESCRIPTION
 *  Highlight handler for vCard Version in Setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_vcard_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_vcard_version, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_vcard_version, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_vcard_version
 * DESCRIPTION
 *  Hint handler for vcard_version in Setting menu
 * PARAMETERS
 *  index       [IN]        Hint item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_vcard_version(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));

    if (g_phb_cntx.vcard_version == MMI_PHB_VCARD_VERSION_21)
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_PHB_VCARD_VERSION_21));
    }
    else
    {
    	mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_PHB_VCARD_VERSION_30));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_vcard_version_21
 * DESCRIPTION
 *  Highlight handler for vcard_version_21 menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_vcard_version_21(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_vcard_version_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_vcard_version = MMI_PHB_VCARD_VERSION_21;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_vcard_version_30
 * DESCRIPTION
 *  Highlight handler for vcard_version_30 menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_vcard_version_30(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_vcard_version_set_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_temp_vcard_version = MMI_PHB_VCARD_VERSION_30;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_vcard_version
 * DESCRIPTION
 *  Draws the vcard_version menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_vcard_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[2];
    U8 *nStrList[2];
    U8 *nHintList[2];
    U16 nNumofItem;
    U8 hiliteStorage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.vcard_version == MMI_PHB_VCARD_VERSION_21)
    {
        hiliteStorage = 0;
    }
    else
    {
        hiliteStorage = 1;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_vcard_version.>\n", __FILE__,
                         __LINE__);
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif
    {
        EntryNewScreen(
            SCR_ID_PHB_VCARD_VERSION_OPTIONS,
            mmi_phb_exit_vcard_version,
            mmi_phb_entry_vcard_version,
            NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_VCARD_VERSION_OPTIONS);
        nNumofItem = GetNumOfChild(MENU_ID_PHB_VCARD_VERSION);
        GetSequenceStringIds(MENU_ID_PHB_VCARD_VERSION, nStrItemList);
        SetParentHandler(MENU_ID_PHB_VCARD_VERSION);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ConstructHintsList(MENU_ID_PHB_VCARD_VERSION, nHintList);
        nStrList[0] = (PU8) GetString(nStrItemList[0]);
        nStrList[1] = (PU8) GetString(nStrItemList[1]);
				
        ShowCategory109Screen(
            STR_ID_PHB_VCARD_VERSION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrList,
            nHintList,
            hiliteStorage,
            guiBuffer);

    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_vcard_version
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_vcard_version()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_vcard_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_VCARD_VERSION_OPTIONS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_vcard_version_set_req
 * DESCRIPTION
 *  Sends the request to L4 to save the preferred storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_vcard_version_set_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 tempVcardVersion;    /* Temp Solution For Write 2 bytes NVRAM_PHB_NAME_LIST_FILTER */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_vcard_version_set_req.>\n", __FILE__,
                         __LINE__);

    if (g_phb_cntx.vcard_version != g_phb_temp_vcard_version)
    {
        g_phb_cntx.vcard_version = g_phb_temp_vcard_version;
        tempVcardVersion = g_phb_cntx.vcard_version;
        WriteValue(NVRAM_PHB_VCARD_VERSION, &tempVcardVersion, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteNScrId(SCR_ID_PHB_VCARD_VERSION_OPTIONS);
}
#endif /* defined(__MMI_VCARD__) && defined(__MMI_VCARD_V30__) */
/*-------------------------------------------------End of vCard Version---------------------------------------------------*/
#define MMI_PHB_SETTING_SPEAK_NAME
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_speak_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_speak_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_PHB_SPEAK_NAME_ON_OFF, &g_phb_cntx.speak_name, DS_BYTE, &pError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_speak_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_speak_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.speak_name)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_BACK);
    }

    SetLeftSoftkeyFunction(mmi_phb_speak_name_toggle, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_speak_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_speak_name(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    if (g_phb_cntx.speak_name)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speak_name_toggle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speak_name_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.speak_name)
    {
        g_phb_cntx.speak_name = 0;
    }
    else
    {
        g_phb_cntx.speak_name = 1;
    }

    WriteValue(NVRAM_PHB_SPEAK_NAME_ON_OFF, &g_phb_cntx.speak_name, DS_BYTE, &pError);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
}

#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

#define MMI_PHB_CALLER_RES_SETTING
#if defined(__MMI_PHB_CALLER_RES_SETTING__)

#if defined(__MMI_AVATAR__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_caller_pic
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_caller_pic()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_caller_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_CALLER_PIC;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_caller_pic
 * DESCRIPTION
 *  Draws the Phonebook settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_caller_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_caller_pic.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_ID_PHB_CALLER_PIC, mmi_phb_exit_caller_pic, mmi_phb_entry_caller_pic, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_CALLER_PIC);  /* Getting the Index from history  */
    nNumofItem = GetNumOfChild(MENU_ID_PHB_CALLER_PIC);
    GetSequenceStringIds(MENU_ID_PHB_CALLER_PIC, nStrItemList);
    SetParentHandler(MENU_ID_PHB_CALLER_PIC);
    ConstructHintsList(MENU_ID_PHB_CALLER_PIC, nHintList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_PHB_CALLER_PIC,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_pic_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_highlight_caller_pic_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_caller_pic_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_caller_pic_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_avatar_pic_select_from_file_manager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_avatar_pic_select_from_file_manager_done(U32 path_address, U32 serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((PS8)path_address == NULL)   /* User does not select file and go back directly. */
    {
        GoBackHistory();
        return;
    }

    /* Check image content. */
    if (mmi_phb_image_check_valid_image((S8*) path_address)) /* avatar is a kind of *.jpg file */
    {
        length = mmi_ucs2strlen((S8*)path_address);
        mmi_ucs2ncpy((S8*) g_phb_file_path, (S8*) path_address, length);
        g_phb_cntx.recv_res_from = MMI_PHB_RECV_RES_AVATAR_IMAGE;
        mmi_phb_entry_fmgr_save_option();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_avatar_pic_select_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_avatar_pic_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    mmi_avatar_select_path_and_enter(
        MMI_AVATAR_APP_CALLER_PICTURE,
        mmi_phb_caller_avatar_pic_select_from_file_manager_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_pic_avatar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_highlight_caller_pic_avatar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_caller_avatar_pic_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_caller_avatar_pic_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_AVATAR__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_pic
 * DESCRIPTION
 *  highlight function for caller picture setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_caller_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AVATAR__)
    SetLeftSoftkeyFunction(mmi_phb_entry_caller_pic, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_caller_pic, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* defined(__MMI_AVATAR__) */ 
    SetLeftSoftkeyFunction(mmi_phb_caller_pic_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_caller_pic_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_AVATAR__) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_pic_select_from_file_manager
 * DESCRIPTION
 *  select file from file manager function. The initial path is the same as camera folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_pic_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    U16 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use camera folder as default folder to select image */
#if defined(__MMI_IMAGE_VIEWER__)
    mmi_imgview_get_storage_file_path(buf_filepath);
#else 
    mmi_ucs2cpy(buf_filepath, (S8*) L"root");
#endif 
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*) buf_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    FMGR_FILTER_INIT(&filter);
#if defined(__GDI_MEMORY_PROFILE_2__)   /* Able to select jpeg file if supported */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
#if defined(GDI_USING_PNG)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
#if defined(GDI_USING_M3D)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_M3D);
#endif
/* .SVG file is now not supported due to stack overflow */
//#ifdef __MMI_SVG__
//    FMGR_FILTER_SET(&filter, FMGR_TYPE_SVG);
//#endif
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    mmi_fmgr_kernel_init(buf_filepath, filter, &file_count);
    if (file_count < 1)
    {
        S32			ret_drv;
        S8			buf[64];
        S8			UCS2_buf[128];
        FS_HANDLE	file_handle;

        /* path is memory card */
        ret_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if (ret_drv >= 0)
        {
            /* drive available */
            sprintf(buf, "%c:\\", (U8)ret_drv);
            mmi_asc_to_ucs2(UCS2_buf, buf);

            file_handle = FS_Open((kal_uint16*)UCS2_buf, FS_OPEN_DIR | FS_READ_ONLY);
            /* Memory card is available */
            if (file_handle >= 0)
            {
                FS_Close(file_handle);
                mmi_fmgr_select_path_and_enter(APP_PHONEBOOK,
                                                    FMGR_SELECT_FILE|FMGR_SELECT_REPEAT,
                                                    filter,
                                                    (S8*)L"root", 
                                                    (PsExtFuncPtr)mmi_phb_caller_pic_select_path_from_file_manager);
                return;
            }
        }
    }

    mmi_fmgr_select_path_and_enter(
        APP_PHONEBOOK,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) buf_filepath,
        (PsExtFuncPtr) mmi_phb_caller_pic_select_path_from_file_manager);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_pic_preview
 * DESCRIPTION
 *  phb image preview function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_pic_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_PHB_IMAGE_VIEW_IMAGE, NULL, mmi_phb_caller_pic_preview, NULL);

    /* entry cat222 to decode and display a image from file */

    ShowCategory222Screen(
        STR_ASSOCIATE_PICTURE,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_BLACK,
        (PS8) NULL,
        (PS8) g_phb_file_path,
        FALSE,
        mmi_phb_image_preview_callback,
        GDI_IMAGE_SRC_FROM_FILE);
    SetLeftSoftkeyFunction(mmi_phb_caller_pic_select_from_file_manager_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_pic_select_path_from_file_manager
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  path            [IN]        selected file path
 *  is_short        [IN]        is selected file name short name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_pic_select_path_from_file_manager(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
        GoBackHistory();
        return;
    }

    /* Check image content. */
    if (mmi_phb_image_check_valid_image((S8*) path))
    {
        mmi_ucs2cpy((S8*) g_phb_file_path, (S8*) path);
        mmi_phb_caller_pic_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_pic_select_from_file_manager_done
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  path            [IN]        selected file path
 *  is_short        [IN]        is selected file name short name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_pic_select_from_file_manager_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.recv_res_from = MMI_PHB_RECV_RES_IMAGE;
    fmgr_reset_app_select();
    mmi_phb_entry_fmgr_save_option();
    DeleteScreenIfPresent(SCR_ID_PHB_IMAGE_VIEW_IMAGE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_ring
 * DESCRIPTION
 *  Highlight function for caller ring tone settngs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_caller_ring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_caller_ring_select_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_caller_ring_select_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_ring_select_profile
 * DESCRIPTION
 *  Select ring tone from profile list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_ring_select_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_profiles_entry_ring_tone_list(mmi_phb_caller_ring_select_profile,
    //                                                                                     mmi_phb_caller_ring_select_profile_done);
    U8 *guiBuffer;  /* Buffer holding history data */

    // U16 nDispAttribute;  /* Stores display attribue */
    U16 selecteditem = 0;
    U8 totalItems = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    mmi_profiles_Ext_melody_set_tone_type(PRFSET_MELODY_TYPE_PHB_RING);
#endif

    /* 1 Call Exit Handler */
    EntryNewScreen(
        SCR_PROFILES_RING_TONE_SETUP,
        mmi_profiles_exit_ring_tone_list,
        mmi_phb_caller_ring_select_profile,
        NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_PROFILES_RING_TONE_SETUP);

    /* 4. Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU_TONE_SETUP_RING_TONE); */

    /* 3. Retrieve no of child of menu item to be displayed */
    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    totalItems = mmi_profiles_get_melody_list(GetRingToneID(), &selecteditem);

    /* 6 Set current parent id */
    SetParentHandler(SCR_PBOOK_MAIN_MENU);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(mmi_profiles_melody_list_highlight_hdlr);

    /* 8 Display Category Screen */
    ShowCategory89Screen(
        STR_ID_PHB_CALLER_RING,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        totalItems,
        subMenuDataPtrs,
        hintDataPtrs,
        0,
        selecteditem,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(mmi_profiles_stop_tone_and_go_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phb_caller_ring_select_profile_done, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_ring_select_profile_done
 * DESCRIPTION
 *  select a ring tone id from profile done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_ring_select_profile_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_profiles_set_ring_tone_id_count_id(mmi_phb_caller_ring_get_id_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_ring_get_id_callback
 * DESCRIPTION
 *  Get the ring tone id from profile
 * PARAMETERS
 *  ExtMelodyFlag       [IN]        Is it a external resource
 *  ringToneId          [IN]        Selected ring tone id.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_ring_get_id_callback(U8 ExtMelodyFlag, U16 ringToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    if (ExtMelodyFlag == MMI_TRUE)
    {
        mmi_profiles_Ext_melody_set_tone_type(PRFSET_MELODY_TYPE_PHB_RING);
        mmi_profiles_Ext_melody_entry_menu();
        return;
    }
#endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 

    mmi_phb_caller_ring_forward_to_entry(ringToneId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_ring_forward_to_entry
 * DESCRIPTION
 *  Forward a ring tone resource to phonebook entry.
 * PARAMETERS
 *  ringToneId      [IN]        ring tone ID associate to phonebook entry
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_ring_forward_to_entry(U16 ringToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.recv_res_from = MMI_PHB_RECV_RES_AUDIO;
    g_phb_cntx.recv_res_id = ringToneId;
    mmi_phb_entry_fmgr_save_option();

    DeleteScreenIfPresent(SCR_PROFILES_RING_TONE_SETUP);
    DeleteScreenIfPresent(MENU_TONE_SETUP_RING_TONE_EXT_MELODY);
}


#if defined(__MMI_INCOMING_CALL_VIDEO__)
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_caller_video
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_caller_video()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_caller_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_CALLER_VIDEO;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_caller_video
 * DESCRIPTION
 *  Draws the Phonebook settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_caller_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_caller_video.>\n", __FILE__,
                         __LINE__);
    if (isInCall())
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_CANT_SELECT_CALLER_VIDEO_IN_CALL),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
        return;
    }
#if !defined(__MMI_AVATAR__)
    mmi_frm_hide_menu_item(MENU_ID_PHB_CALLER_VIDEO_AVATAR);
#endif
#if !defined(__MMI_SWFLASH__)
    mmi_frm_hide_menu_item(MENU_ID_PHB_CALLER_VIDEO_SWFLASH);
#endif
    EntryNewScreen(SCR_ID_PHB_CALLER_VIDEO, mmi_phb_exit_caller_video, mmi_phb_entry_caller_video, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_CALLER_VIDEO);  /* Getting the Index from history  */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_PHB_CALLER_VIDEO);
    GetSequenceStringIds_Ext(MENU_ID_PHB_CALLER_VIDEO, nStrItemList);
    SetParentHandler(MENU_ID_PHB_CALLER_VIDEO);
    ConstructHintsList(MENU_ID_PHB_CALLER_VIDEO, nHintList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_PHB_CALLER_VIDEO,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_video_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_highlight_caller_video_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_caller_video_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_caller_video_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__) */


#if defined(__MMI_AVATAR__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_avatar_video_select_from_file_manager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_avatar_video_select_from_file_manager_done(U32 id, U32 serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_buff[FMGR_MAX_PATH_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_video_check_data_space(NULL))
    {
        return;
    }
    memset(g_phb_video_file_path, 0, (FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH));
    sprintf(temp_buff, "%d-%d", id, serial_num);
    mmi_asc_to_ucs2((S8*) g_phb_video_file_path, temp_buff);
    g_phb_cntx.recv_res_from = MMI_PHB_RECV_RES_AVATAR_VIDEO;
    mmi_phb_entry_fmgr_save_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_avatar_video_select_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_avatar_video_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    mmi_avatar_select_path_and_enter (MMI_AVATAR_APP_CALLER_VIDEO, 
        mmi_phb_caller_avatar_video_select_from_file_manager_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_video_avatar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_highlight_caller_video_avatar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_caller_avatar_video_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_caller_avatar_video_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_AVATAR__) */


#if defined(__MMI_SWFLASH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_swflash_select_from_file_manager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_swflash_select_from_file_manager_done(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        GoBackHistory();
        return;
    }
    if (!mmi_phb_video_check_data_space((S8*) path))
    {
        return;
    }
    mmi_ucs2cpy(g_phb_video_file_path, path);
    g_phb_cntx.recv_res_from = MMI_PHB_RECV_RES_SWFLASH;
    mmi_phb_caller_video_preview();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_swflash_select_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_swflash_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    U16 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use swflash player folder as default folder to select image */
    mmi_swflash_get_storage_file_path(buf_filepath);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*) buf_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_SWFLASH(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ZDD);
    mmi_fmgr_kernel_init(buf_filepath, filter, &file_count);
    if (file_count < 1)
    {
        S32			ret_drv;
        S8				buf[64];
        S8				UCS2_buf[128];
        FS_HANDLE	file_handle;

        /* path is memory card */
        ret_drv 	= FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if(ret_drv >= 0)
        {
            /* drive available */
            sprintf(buf, "%c:\\", (U8)ret_drv);
            mmi_asc_to_ucs2(UCS2_buf, buf);

            file_handle = FS_Open((kal_uint16*)UCS2_buf, FS_OPEN_DIR | FS_READ_ONLY);

            /* Memory card is available */
            if(file_handle >= 0)
            {
                FS_Close(file_handle);
                mmi_fmgr_select_path_and_enter(APP_PHONEBOOK,
                                                    FMGR_SELECT_FILE|FMGR_SELECT_REPEAT,
                                                    filter,
                                                    (S8*)L"root", 
                                                    (PsExtFuncPtr)mmi_phb_caller_swflash_select_from_file_manager_done);
                return;
            }
        }
    }
    mmi_fmgr_select_path_and_enter(
        APP_PHONEBOOK,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) buf_filepath,
        (PsExtFuncPtr) mmi_phb_caller_swflash_select_from_file_manager_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_video_swflash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_highlight_caller_video_swflash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_caller_swflash_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_caller_swflash_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_SWFLASH__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_caller_video
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_caller_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
    SetLeftSoftkeyFunction(mmi_phb_entry_caller_video, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_caller_video, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__) */ 
    SetLeftSoftkeyFunction(mmi_phb_caller_video_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_caller_video_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_video_preview_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_video_preview_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_reset_app_select();
    mmi_phb_entry_fmgr_save_option();
    DeleteScreenIfPresent(SCR_ID_PHB_VIDEO_PREVIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_video_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_video_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall()) /* Can not preview video during call. */
    {
#ifdef __MMI_SWFLASH__
        if (g_phb_cntx.recv_res_from == MMI_PHB_RECV_RES_SWFLASH)
        {
            DisplayPopup((U8*)GetString(STR_ID_PHB_CANT_VIEW_SWFLASH_IN_CALL), IMG_GLOBAL_WARNING, FALSE, PHB_NOTIFY_TIMEOUT, WARNING_TONE);
        }
        else
#endif /* __MMI_SWFLASH__ */
        {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_CANT_VIEW_VIDEO_IN_CALL),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
        }
        return;
    }
    EntryNewScreen(SCR_ID_PHB_VIDEO_PREVIEW, NULL, mmi_phb_caller_video_preview, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_PHB_VIDEO_PREVIEW);
#ifdef __MMI_SWFLASH__
    if (g_phb_cntx.recv_res_from == MMI_PHB_RECV_RES_SWFLASH)
    {
      	ShowCategory229Screen(
            (U8*)GetString(STR_ID_PHB_ASSOCIATE_VIDEO),		/* title_str */
            IMG_SCR_PBOOK_CAPTION,	    /* title_icon */
            STR_GLOBAL_OK,				/* lsk_str */
            IMG_GLOBAL_OK,				/* lsk_icon */
            STR_GLOBAL_BACK,			/* rsk_str */
            IMG_GLOBAL_BACK,			/* rsk_icon */
            0,								/* video_id */
            (S8*)g_phb_video_file_path,	/* video_filename */
            1,								/* repeat_count */
            (BOOL)!IsSilentModeActivated(),		/* is_play_audio */
            TRUE,                           /* is_vibrate_on */
            TRUE,                           /* is_interaction_on */
            TRUE,							/* is_lcd_no_sleep */
            0,							    /* is_full_screen */
            GDI_COLOR_WHITE,			/* bg_color */
            mmi_phb_swflash_play_callback,
            gui_buffer);  
    }
    else
#endif /* __MMI_SWFLASH__ */
    {
        ShowCategory225Screen(
            STR_ID_PHB_ASSOCIATE_VIDEO,                    /* title_str */
            IMG_SCR_PBOOK_CAPTION,              /* title_icon */
            STR_GLOBAL_OK,                      /* lsk_str */
            IMG_GLOBAL_OK,                      /* lsk_icon */
            STR_GLOBAL_BACK,                    /* rsk_str */
            IMG_GLOBAL_BACK,                    /* rsk_icon */
            0,                                  /* video_id */
            (S8*) g_phb_video_file_path,      /* video_filename */
            1,                                  /* repeat_count */
            TRUE,                               /* is_visual_update */
            (BOOL) ! IsSilentModeActivated(),   /* is_play_audio */
            TRUE,                               /* is_lcd_no_sleep */
            GDI_COLOR_WHITE,                    /* bg_color */
            mmi_phb_video_view_callback,
            gui_buffer);
    }
    SetLeftSoftkeyFunction(mmi_phb_caller_video_preview_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_video_select_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_video_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    U16 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use video player folder as default folder to select image */
    mmi_vdoply_get_storage_file_path(buf_filepath);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*) buf_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (isInCall()) /* Can not enter caller video during call. */
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_CANT_SELECT_CALLER_VIDEO_IN_CALL),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
        return;
    }

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_VIDEO(&filter);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    mmi_fmgr_kernel_init(buf_filepath, filter, &file_count);
    if (file_count < 1)
    {
        S32			ret_drv;
        S8				buf[64];
        S8				UCS2_buf[128];
        FS_HANDLE	file_handle;

        /* path is memory card */
        ret_drv 	= FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if(ret_drv >= 0)
        {
            /* drive available */
            sprintf(buf, "%c:\\", (U8)ret_drv);
            mmi_asc_to_ucs2(UCS2_buf, buf);

            file_handle = FS_Open((kal_uint16*)UCS2_buf, FS_OPEN_DIR | FS_READ_ONLY);

            /* Memory card is available */
            if(file_handle >= 0)
            {
                FS_Close(file_handle);
                mmi_fmgr_select_path_and_enter(APP_PHONEBOOK,
                                                    FMGR_SELECT_FILE|FMGR_SELECT_REPEAT,
                                                    filter,
                                                    (S8*)L"root", 
                                                    (PsExtFuncPtr)mmi_phb_caller_video_select_from_file_manager_done);
                return;
            }
        }

    }
    mmi_fmgr_select_path_and_enter(
        APP_PHONEBOOK,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) buf_filepath,
        (PsExtFuncPtr) mmi_phb_caller_video_select_from_file_manager_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_video_select_from_file_manager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_video_select_from_file_manager_done(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        GoBackHistory();
        return;
    }
    if (!mmi_phb_video_check_data_space((S8*) path))
    {
        return;
    }
    mmi_ucs2cpy(g_phb_video_file_path, path);
    g_phb_cntx.recv_res_from = MMI_PHB_RECV_RES_VIDEO;
    mmi_phb_caller_video_preview();
}
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */
#endif /* _PHONEBOOKSETTINGS_C */ 

