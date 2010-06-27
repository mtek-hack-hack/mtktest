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
 * PhoneBookCallerGroups.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implemantation of "Caller Group" feature in the Phonebook Application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _PHONEBOOKCALLERGROUP_C
#define _PHONEBOOKCALLERGROUP_C

#include "ProtocolEvents.h"
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhonebookProt.h"
#include "PhonebookGprot.h"
#include "mainmenudef.h"
#include "ProfileGprots.h"
#include "gpioinc.h"
#include "DownloadDefs.h"
#include "DownloadProtos.h"
#include "CommonScreens.h"
#include "UserProfilesResDef.h"       /* For Alert Type String ID */
#include "CallManagementGprot.h"
#include "custom_equipment.h"
#include "wgui_inputs.h"
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
#include "FileMgr.h"
#include "ProfileMgrGProt.h"
#include "Conversions.h"
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
#include "MessagesExDcl.h"
#include "SMSGuiInterfaceProt.h"
#endif /* defined(__MMI_MESSAGES_SEND_BY_GROUP__) */ 

#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
#include "PhonebookJavaHandler.h"
#endif
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_Master_ADN.h"
#include "MTPNP_AD_resdef.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#define MAX_CALLER_GRP_USIM_ITEMS 2

/*
 * Local Variable
 */
static U16 g_phb_last_ring_tone_id = 0;
static U16 g_phb_curr_ring_tone_id = 0;
static U8 g_phb_last_pattern_id = 0;
static U8 g_phb_curr_pattern_id = 0;

#ifdef __MMI_PHB_USIM_FIELD__
static U8 phb_delete_grp_flag;
#endif 

#if defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__)        /* Caller Group Member List */
static U16 g_phb_callergroup_member_count;
static U16 *g_phb_callergroup_ptr = NULL;
static U8 g_phb_callergroup_member_index = 10;
#endif /* defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__) */ 

/*
 * Global Variable
 */
extern InlineItem wgui_inline_items[];
extern pBOOL viewOnce;
extern MMI_PHB_LIST_VIEW phbListView;
extern U8 gPictureItemIndex;
#ifdef __MMI_AVATAR__
extern BOOL g_phb_avatar_image_view;
#endif
extern U16 g_phb_image_type_id;

#if defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__)        /* Caller Group Member List */
extern U16 PhoneBookEntryCount;
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
#endif /* defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__) */ 
extern U16 g_phb_name_index[];
extern S8 pbName[];

#ifdef __MMI_PHB_USIM_FIELD__
extern S8 pbNumber[];   /* dummy number for save gas */
#endif 
extern U8 *myCallerGrpnames[];
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
extern U8 g_phb_enter_from;
#endif

#if defined(__MMI_INCOMING_CALL_VIDEO__)
extern U8 g_phb_video_item_index;
extern BOOL g_phb_video_view;
#ifdef __MMI_SWFLASH__
extern BOOL g_phb_swflash_view;
#endif
#ifdef __MMI_AVATAR__
extern BOOL g_phb_avatar_video_view;
#endif
#if defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__)
extern U8 g_phb_swflash_video_minus;
extern U8 g_phb_avatar_video_minus;
#elif defined(__MMI_SWFLASH__) /* defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__) */
extern U8 g_phb_swflash_video_minus;
#elif defined(__MMI_AVATAR__)
extern U8 g_phb_avatar_video_minus;
#endif /* defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__) */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */

extern U16 TitleStrings[];
/*
 * Local Function
 */
static void mmi_phb_entry_callergroup_phone_detail(void);

#ifdef __MMI_PHB_USIM_FIELD__
static void mmi_phb_entry_callergroup_usim_detail(void);
static void mmi_phb_gas_pre_save(void);
static void mmi_phb_callergroup_member_usim_set_req(void);
#endif /* __MMI_PHB_USIM_FIELD__ */ 


/*
 * Global Function
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_group_init
 * DESCRIPTION
 *  Initialization of "Caller Group" feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_group_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_caller_group_init.>\n", __FILE__,
                         __LINE__);
    SetHiliteHandler(MITEM109_PBOOK_CALLER_GROUPS, mmi_phb_highlight_callergroup);

#if defined (__MMI_PHB_CALLERGROUP_MEMBER_LIST__)
    SetHiliteHandler(MENU_ID_PHB_CALLERGROUP_MEMBER_ADD_MEMBER, mmi_phb_highlight_callergroup_member_add);
    SetHiliteHandler(MENU_ID_PHB_CALLERGROUP_MEMBER_DELETE_MEMBER, mmi_phb_highlight_callergroup_member_delete);
#endif /* defined (__MMI_PHB_CALLERGROUP_MEMBER_LIST__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_restore_default
 * DESCRIPTION
 *  Sets Caller Groups default values. This is an external API called by restore defaults application
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL: TRUE if restore successfully, else FALSE
 *****************************************************************************/
BOOL mmi_phb_callergroup_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 i, midiToneStartId, midiToneTotalId;
    PHB_CALLER_GROUP_STRUCT *callerGroups;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;

    GetMidiRange(&midiToneStartId, &midiToneTotalId);

    for (i = 0; i < MAX_PB_CALLER_GROUPS; ++i)
    {

    #if defined(__MMI_CALLERGROUP_NO_ALERT__)
        callerGroups[i].alertType = MMI_ALERT_NONE;
    #else 
        callerGroups[i].alertType = MMI_RING;
    #endif 

        callerGroups[i].ringToneID = midiToneStartId;
        callerGroups[i].pictureTagID = IMG_PHB_DEFAULT;

    #if !defined(HARDWARE_LED_NOT_SUPPORT)
        callerGroups[i].LEDPatternId = 1;   /* pattern 1 */
    #else 
        callerGroups[i].LEDPatternId = 0;   /* no pattern */
    #endif 
        callerGroups[i].is_modified = 0;    /* Restore to default name */

        /* Restore Name according to language */
        mmi_ucs2ncpy(
            (PS8) callerGroups[i].groupName,
            GetString((U16) (STR_CALLER_GROUP_1 + i)),
            MAX_GRP_NAME_LENGTH);
    }

    WriteRecord(NVRAM_EF_PHB_CALLER_GROUPS_LID, 1, callerGroups, CALLER_GROUPS_RECORD_SIZE, &pError);

    if (pError == NVRAM_WRITE_SUCCESS)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_set_name_by_language
 * DESCRIPTION
 *  Sets Caller Groups name values according to current language.
 *  This is an external API called by restore defaults application
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL: TRUE if restore successfully, else FALSE(?)
 *****************************************************************************/
void mmi_phb_callergroup_set_name_by_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 i;
    PHB_CALLER_GROUP_STRUCT callerGroups[MAX_PB_CALLER_GROUPS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_PHB_CALLER_GROUPS_LID, 1, callerGroups, CALLER_GROUPS_RECORD_SIZE, &pError);

    if (pError == NVRAM_READ_SUCCESS)
    {

        for (i = 0; i < MAX_PB_CALLER_GROUPS; ++i)
        {
            if (callerGroups[i].is_modified == 0)   /* User not modify yet */
            {
                mmi_ucs2ncpy(
                    (PS8) callerGroups[i].groupName,
                    GetString((U16) (STR_CALLER_GROUP_1 + i)),
                    MAX_GRP_NAME_LENGTH);
            }
        }
        WriteRecord(NVRAM_EF_PHB_CALLER_GROUPS_LID, 1, callerGroups, CALLER_GROUPS_RECORD_SIZE, &pError);

        if ((pError == NVRAM_WRITE_SUCCESS) && (g_phb_cntx.caller_group != NULL) && g_phb_cntx.nvram_data_init)
        {
            memcpy(g_phb_cntx.caller_group, callerGroups, CALLER_GROUPS_RECORD_SIZE);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_callergroup
 * DESCRIPTION
 *  Highlight handler for Caller Group in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_callergroup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    phbListView = MMI_PHB_LIST_FOR_PHB;
    SetLeftSoftkeyFunction(mmi_phb_entry_callergroup, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_callergroup, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup
 * DESCRIPTION
 *  Displays the list of available Caller Groups
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_FIELD__
    MMI_PHB_NAME_STRUCT *usim_caller_groups = (MMI_PHB_NAME_STRUCT*) g_phb_cntx.usim_group;
#endif
    U8 *grpNames[MAX_PB_CALLER_GROUPS + MAX_PB_USIM_GROUPS];
    U16 i;
    U8 *guiBuffer;
    PHB_CALLER_GROUP_STRUCT *callerGroups;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_callergroup.>\n", __FILE__,
                         __LINE__);

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
        return;
    }
#endif /* __SYNCML_SUPPORT__ */

    if (!g_phb_cntx.nvram_data_init)
    {
        mmi_phb_init_get_data_from_nvram();
        g_phb_cntx.nvram_data_init = TRUE;
    }

    EntryNewScreen(SCR_CALLER_GROUPS, mmi_phb_exit_callergroup, mmi_phb_entry_callergroup, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_CALLER_GROUPS);    /* Getting the Index from history */

    callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;
    for (i = 0; i < MAX_PB_CALLER_GROUPS; i++)
    {
        grpNames[i] = callerGroups[i].groupName;
    }
#ifdef __MMI_PHB_USIM_FIELD__
    for (i = MAX_PB_CALLER_GROUPS; i < MAX_PB_CALLER_GROUPS + g_phb_cntx.gas_total; i++)
    {
        if (mmi_ucs2strlen((PS8) usim_caller_groups[i - MAX_PB_CALLER_GROUPS].name) > 0)
        {
            grpNames[i] = usim_caller_groups[i - MAX_PB_CALLER_GROUPS].name;
        }
        else
        {
            grpNames[i] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }
#endif /* __MMI_PHB_USIM_FIELD__ */ 

#if defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__)
    if (phbListView == MMI_PHB_LIST_FOR_GET_ADDRESS_FROM_GROUP)
    {
        RegisterHighlightHandler(mmi_phb_get_index_second_level);
        SetMessagesCurrScrnID(SCR_CALLER_GROUPS);
        ShowCategory53Screen(STR_SCR_CALLER_GROUP_CAPTION, IMG_SCR_PBOOK_CAPTION,
                             STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
            #ifdef __MMI_PHB_USIM_FIELD__
                             g_phb_cntx.gas_total +
            #endif 
                             MAX_PB_CALLER_GROUPS,
                             grpNames, (U16*) gIndexIconsImageList, NULL, 0, 0, guiBuffer);
        SetLeftSoftkeyFunction(mmi_phb_sms_send_data_for_group, KEY_EVENT_UP);
    }
    else
#endif /* defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__)*/ 
    {
        RegisterHighlightHandler(mmi_phb_get_index);
        ShowCategory53Screen(STR_SCR_CALLER_GROUP_CAPTION, IMG_SCR_PBOOK_CAPTION,
                             STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
            #ifdef __MMI_PHB_USIM_FIELD__
                             g_phb_cntx.gas_total +
            #endif 
                             MAX_PB_CALLER_GROUPS,
                             grpNames, (U16*) gIndexIconsImageList, NULL, 0, 0, guiBuffer);
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        if (phbListView == MMI_PHB_LIST_FOR_SAVE_FROM_FILE_MGR)
        {
            SetLeftSoftkeyFunction(mmi_phb_fmgr_pre_edit_callergrp, KEY_EVENT_UP);
        }
        else
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
        {
            SetLeftSoftkeyFunction(mmi_phb_entry_callergroup_detail, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_entry_callergroup_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }

    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_callergroup
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_callergroup()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_callergroup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_CALLER_GROUPS;
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
    mmi_msg_exit_generic();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_detail
 * DESCRIPTION
 *  Displayes the attributes of the selected Caller Group and also allows to edit it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_detail(void)
{
#ifdef __MMI_PHB_USIM_FIELD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
    {
        mmi_phb_entry_callergroup_usim_detail();
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
    {
        mmi_phb_entry_callergroup_phone_detail();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_phone_detail
 * DESCRIPTION
 *  Displayes the attributes of the selected Caller Group and also allows to edit it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_phone_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U8 j = 0;
    U16 CGDetailsImageList[MAX_CALLER_GRP_ITEMS];
    PHB_CALLER_GROUP_STRUCT *callerGroups = NULL;
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    U16 video_id = 0;
#endif    
#if defined __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    BOOL found_theme_tone = TRUE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_callergroup_phone_detail.>\n",
                         __FILE__, __LINE__);

    mmi_phb_build_led_and_alert_list();
    mmi_phb_build_ring_tone_list();
    mmi_phb_build_image_list();

#if defined(__MMI_INCOMING_CALL_VIDEO__)
    mmi_phb_build_video_list();
#endif 

    EntryNewScreen(SCR_CALLER_GRP_DETAILS, mmi_phb_exit_callergroup_detail, NULL, NULL);
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_CALLER_GRP_DETAILS);
    inputBuffer = GetCurrNInputBuffer(SCR_CALLER_GRP_DETAILS, &inputBufferSize);

    callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;
    mmi_ucs2cpy(pbName, (PS8) callerGroups[g_phb_cntx.active_index].groupName);
    g_phb_cntx.selected_alert_index = callerGroups[g_phb_cntx.active_index].alertType;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (callerGroups[g_phb_cntx.active_index].ringToneID == CURRENT_THEME_INCOMING_CALL_TONE && mmi_tm_get_current_theme_ringtone() == FALSE)
    {
        g_phb_cntx.selected_ring_index = 0;
        found_theme_tone = FALSE;
    }
    else
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
    {
        g_phb_cntx.selected_ring_index = mmi_phb_get_ring_tone_index(callerGroups[g_phb_cntx.active_index].ringToneID);
    }
    g_phb_cntx.selected_pattern_index = callerGroups[g_phb_cntx.active_index].LEDPatternId;
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    if (guiBuffer == NULL)  /* First Time Enter and Not Enter From File Manager */
    {
        g_phb_cntx.selected_video_index = mmi_phb_get_video_index(callerGroups[g_phb_cntx.active_index].VideoID);
        video_id = callerGroups[g_phb_cntx.active_index].VideoID;
        g_phb_cntx.video_audio = ((video_id == 0) || (video_id & 0x4000)) ? 1 : 0;

        /*Change Inline select prompt message.*/
        if( g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1)
        {
            g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - 1] = (U8*)GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            g_phb_cntx.video_location = MMI_PHB_IMAGE_SELECT_PATH;
        }
#ifdef __MMI_AVATAR__
        else if( g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus)
        {
            g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_avatar_video_minus] = (U8*)GetString(STR_ID_PHB_AVATAR_SELECTED);
            g_phb_cntx.video_location = MMI_PHB_AVATAR_SELECT_PATH;
        }
#endif /* __MMI_AVATAR__ */
#ifdef __MMI_SWFLASH__
        else if( g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus)
        {
            g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_swflash_video_minus] = (U8*)GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            g_phb_cntx.video_location = MMI_PHB_SWFLASH_SELECT_PATH;
        }
#endif /* __MMI_SWFLASH__ */

        /* Check if can load video path */
        if (!mmi_phb_video_get_path_by_index(video_id))
        {
            g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
        }
    }
    else /* not first enter */
    {
        if (g_phb_cntx.video_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
        {
        #if defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__)
        #ifdef __MMI_AVATAR__
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_avatar_video_minus) &&
                g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH)
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_avatar_video_minus] =
                    (U8*) GetString(STR_ID_PHB_AVATAR_SELECTED);
                g_phb_cntx.video_location = MMI_PHB_AVATAR_SELECT_PATH;
            }
            else
        #endif /* __MMI_AVATAR__ */
        #ifdef __MMI_SWFLASH__
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_swflash_video_minus) &&
                g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH)
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_swflash_video_minus] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                g_phb_cntx.video_location = MMI_PHB_SWFLASH_SELECT_PATH;
            }
            else
        #endif /* __MMI_SWFLASH__ */
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - 1)
        #ifdef __MMI_AVATAR__ 
               && g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH
        #endif /* __MMI_AVATAR__ */
        #ifdef __MMI_SWFLASH__
               && g_phb_cntx.video_location != MMI_PHB_SWFLASH_SELECT_PATH
        #endif /* __MMI_SWFLASH__ */
               )
        #endif /* defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__) */
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - 1] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            }
        }
    }	
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    if (guiBuffer == NULL)
    {
        g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(callerGroups[g_phb_cntx.active_index].pictureTagID);
        g_phb_image_type_id = callerGroups[g_phb_cntx.active_index].pictureTagID;
        /* Check if image folder was hidden by USB mode */
        if ((callerGroups[g_phb_cntx.active_index].pictureTagID == 1 || callerGroups[g_phb_cntx.active_index].pictureTagID == 2) /*&& mmi_phb_image_check_image_file()*/)
        {
            g_phb_cntx.image_location = MMI_PHB_IMAGE_CALLER_GROUP;
        }
        else
        {
            g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
        }
        if (g_phb_cntx.image_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
        {
        #ifdef __MMI_AVATAR__
            if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 2))
            {
                g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 2] =
                    (U8*) GetString(STR_ID_PHB_AVATAR_SELECTED);
            }
            else
        #endif /* __MMI_AVATAR__ */
            if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1))
            {
                g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 1] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            }
        }
    }
    else
    {
        g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(g_phb_image_type_id);
        if (g_phb_cntx.image_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
        {
        #ifdef __MMI_AVATAR__
            if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 2))
            {
                g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 2] =
                    (U8*) GetString(STR_ID_PHB_AVATAR_SELECTED);
            }
            else
        #endif /* __MMI_AVATAR__ */
            if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1))
            {
                g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 1] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            }
        }
	}        
#else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
    if (guiBuffer == NULL)
    {
        g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(callerGroups[g_phb_cntx.active_index].pictureTagID);
        g_phb_image_type_id = callerGroups[g_phb_cntx.active_index].pictureTagID;
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
    }
    else
    {
        callerGroups[g_phb_cntx.active_index].pictureTagID = g_phb_image_type_id;
        g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(g_phb_image_type_id);
    }
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    /* Caller Group Name */
    SetInlineItemActivation(&wgui_inline_items[j], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[j],
        STR_GRP_NAME_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        (PU8) pbName,
        MAX_GRP_NAME_LENGTH + 1,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[j], mmi_phb_set_full_scr_lsk);
    TitleStrings[j] = STR_GRP_NAME_CAPTION;
    CGDetailsImageList[j++] = IMG_CG_NAME;

    /* Alert Setting */
#if !defined(__MMI_CALLERGROUP_NO_ALERT__)
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[j],
        MAX_PB_ALERT_TYPES + 1,
        g_phb_cntx.alert_name_list,
        &g_phb_cntx.selected_alert_index);
    TitleStrings[j] = STR_ASSOCIATE_ALERT;
    CGDetailsImageList[j++] = IMG_CG_ALERT_TYPE;
#endif /* !defined(__MMI_CALLERGROUP_NO_ALERT__) */ 

    /* Ring Tone Setting */
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[j],
        g_phb_cntx.total_ring_tone,
        g_phb_cntx.ring_tone_name_list,
        &g_phb_cntx.selected_ring_index);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[j], mmi_phb_ring_tone_highlight_hdlr);
    TitleStrings[j] = STR_ASSOCIATE_SOUND;
    CGDetailsImageList[j++] = IMG_CG_RING_TONE;

    /* Associate Picture */
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[j],
        g_phb_cntx.total_image_id,
        g_phb_cntx.image_name_list,
        &g_phb_cntx.selected_pic_index);
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[j], mmi_phb_image_highlight_hdlr);
#endif 
    gPictureItemIndex = j;
    TitleStrings[j] = STR_ASSOCIATE_PICTURE;
    CGDetailsImageList[j++] = IMG_CG_PICTURE;

    /* LED Setting */
#if !defined(HARDWARE_LED_NOT_SUPPORT)
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[j],
        MAX_PB_LED_PATTERNS + 1,
        g_phb_cntx.led_name_list,
        &g_phb_cntx.selected_pattern_index);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[j], mmi_phb_led_pattern_highlight_hdlr);
    TitleStrings[j] = STR_ASSOCIATE_LED;
    CGDetailsImageList[j++] = IMG_CG_INDICATOR_LITE;
#endif /* defined(HARDWARE_LED_NOT_SUPPORT) */ 

    /* Incoming call video */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[j],
        g_phb_cntx.total_video_id,
        g_phb_cntx.video_name_list,
        &g_phb_cntx.selected_video_index);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[j], mmi_phb_video_highlight_hdlr);
    g_phb_video_item_index = j;
    TitleStrings[j] = STR_ID_PHB_ASSOCIATE_VIDEO;
    CGDetailsImageList[j++] = IMG_ID_PHB_ASSOCIATE_VIDEO;
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

    /* Caller Group Member List */
#if defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__)
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[j], (U8*) GetString(STR_ID_PHB_CALLERGROUP_MEMBER_LIST));
    g_phb_callergroup_member_index = j;
    TitleStrings[j] = STR_ID_PHB_CALLERGROUP_MEMBER_LIST;
    CGDetailsImageList[j++] = IMG_ID_PHB_CALLERGRP_MEMBER;
#endif /* defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__) */ 

    RegisterHighlightHandler(mmi_phb_callergroup_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, j, inputBuffer);

        if (viewOnce)   /* Reconfig only if view fields has turned on */
        {
            viewOnce = FALSE;

            /* If select from file but no image selected, clear it to default */
            if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 1) &&
                (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT 
            #ifdef __MMI_AVATAR__
                || g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH
            #endif
                ))
            {
                g_phb_cntx.selected_pic_index = 0;
                g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
            }
            else if (g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 1
            #ifdef __MMI_AVATAR__
                    && g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 2
            #endif
                )
            {
                g_phb_cntx.selected_pic_index = g_phb_cntx.selected_pic_in_view;
            }
                ReConfigureInlineItemSelect(
                    &wgui_inline_items[gPictureItemIndex],
                    g_phb_cntx.total_image_id,
                    g_phb_cntx.image_name_list,
                    &g_phb_cntx.selected_pic_index);
            #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
                RegisterInlineSelectHighlightHandler(&wgui_inline_items[gPictureItemIndex], mmi_phb_image_highlight_hdlr);
            #endif 
                SetInlineDoneFlag(guiBuffer);
        }
    #ifdef __MMI_AVATAR__
        else if (g_phb_avatar_image_view)
        {
            g_phb_avatar_image_view = FALSE;

            /* If select from file but no image selected, clear it to default */
            if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 2) &&
                (g_phb_cntx.image_location != MMI_PHB_AVATAR_SELECT_PATH) &&
                (g_phb_cntx.image_location != MMI_PHB_IMAGE_CALLER_GROUP))
            {
                g_phb_cntx.selected_pic_index = 0;
                g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
            }

            ReConfigureInlineItemSelect(
                &wgui_inline_items[gPictureItemIndex],
                g_phb_cntx.total_image_id,
                g_phb_cntx.image_name_list,
                &g_phb_cntx.selected_pic_index);
        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)      
            RegisterInlineSelectHighlightHandler(&wgui_inline_items[gPictureItemIndex], mmi_phb_image_highlight_hdlr);
        #endif 
            SetInlineDoneFlag(guiBuffer);
        }
    #endif /* def __MMI_AVATAR__ */
    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        if (g_phb_video_view)
        {
            g_phb_video_view = FALSE;
            if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1) &&
                (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT 
            #ifdef __MMI_SWFLASH__
                || g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH
            #endif
            #ifdef __MMI_AVATAR__
                || g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH
            #endif
                ))
            {
                g_phb_cntx.selected_video_index = 0;
                g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
            }

            ReConfigureInlineItemSelect(
                &wgui_inline_items[g_phb_video_item_index],
                g_phb_cntx.total_video_id,
                g_phb_cntx.video_name_list,
                &g_phb_cntx.selected_video_index);
            RegisterInlineSelectHighlightHandler(
                &wgui_inline_items[g_phb_video_item_index],
                mmi_phb_video_highlight_hdlr);
            SetInlineDoneFlag(guiBuffer);
        }
    #ifdef __MMI_AVATAR__
        else if (g_phb_avatar_video_view)
        {
            g_phb_avatar_video_view = FALSE;
            if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus) &&
                (g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH))
            {
                g_phb_cntx.selected_video_index = 0;
                g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
            }

            ReConfigureInlineItemSelect(
                &wgui_inline_items[g_phb_video_item_index],
                g_phb_cntx.total_video_id,
                g_phb_cntx.video_name_list,
                &g_phb_cntx.selected_video_index);
            RegisterInlineSelectHighlightHandler(&wgui_inline_items[g_phb_video_item_index], mmi_phb_video_highlight_hdlr);
            SetInlineDoneFlag(guiBuffer);
        }
    #endif /*  __MMI_AVATAR__ */
    #ifdef __MMI_SWFLASH__
        else if (g_phb_swflash_view)
        {
            g_phb_swflash_view = FALSE;
            if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus) &&
                (g_phb_cntx.video_location != MMI_PHB_SWFLASH_SELECT_PATH))
            {
                g_phb_cntx.selected_video_index = 0;
                g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
            }

            ReConfigureInlineItemSelect(
                &wgui_inline_items[g_phb_video_item_index],
                g_phb_cntx.total_video_id,
                g_phb_cntx.video_name_list,
                &g_phb_cntx.selected_video_index);
            RegisterInlineSelectHighlightHandler(&wgui_inline_items[g_phb_video_item_index], mmi_phb_video_highlight_hdlr);
            SetInlineDoneFlag(guiBuffer);
        }
    #endif /*  __MMI_SWFLASH__ */
    #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
    }
    ShowCategory57Screen(
        STR_SCR_CG_DETAILS_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_EDIT_LSK,
        STR_GLOBAL_DONE,
        IMG_DONE_RSK,
        j,
        CGDetailsImageList,
        wgui_inline_items,
        0,
        guiBuffer);

#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
    {
        SetCategory57RightSoftkeyFunctions(mmi_phb_gas_pre_save, GoBackHistory);
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
        SetCategory57RightSoftkeyFunctions(mmi_phb_callergroup_detail_pre_save, GoBackHistory);

    if (g_phb_cntx.set_done_flag)
    {
        g_phb_cntx.set_done_flag = 0;
        set_wgui_inline_list_menu_changed();
    }

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    /* Check if associate audio in file system exists. */
    if ((guiBuffer == NULL) &&
        (callerGroups[g_phb_cntx.active_index].ringToneID >= PMG_EXT_MELODY_BEGIN) &&
        (callerGroups[g_phb_cntx.active_index].ringToneID <= PMG_EXT_MELODY_END) &&
        !PmgQueryFileExistById(callerGroups[g_phb_cntx.active_index].ringToneID))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_AUDIO_ID_NOT_EXIST),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

#if defined __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (guiBuffer == NULL && found_theme_tone == FALSE)
    {
        DisplayPopup(
          (PU8) GetString(STR_ID_PHB_THEME_TONE_NOT_FOUND),
          IMG_GLOBAL_ERROR,
          FALSE,
          PHB_NOTIFY_TIMEOUT,
          ERROR_TONE);
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_callergroup_detail
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_callergroup_detail()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_callergroup_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_CALLER_GRP_DETAILS;
    gPictureItemIndex = 10;
    mmi_phb_stop_ring_tone_id();
    mmi_phb_stop_led_pattern_id();
    CloseCategory57Screen();
    h.scrnID = SCR_CALLER_GRP_DETAILS;
    h.entryFuncPtr = mmi_phb_entry_callergroup_detail;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Caller Groups details screen
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_stop_ring_tone_id();
    mmi_phb_stop_led_pattern_id();
    ChangeTitleString((PU8) GetString(TitleStrings[index]));

    draw_title();

    /* Highlight on image item */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    if ((index == gPictureItemIndex) && (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1)))     /* View Image File */
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_image_pre_entry_option, KEY_EVENT_UP);
    }
    else if ((index == gPictureItemIndex) && (g_phb_cntx.selected_pic_index < (g_phb_cntx.total_image_id - 1))) /* View Image ID through Category screen */
    {
        ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_view_picture, KEY_EVENT_UP);
    }
#else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
    if (index == gPictureItemIndex)
    {
        ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_view_picture, KEY_EVENT_UP);
    }
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    /* Highlight on incoming call video item */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    if (index == g_phb_video_item_index)
    {
        if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - 1))
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_pre_entry_file_option, KEY_EVENT_UP);
        }
        else if (g_phb_cntx.selected_video_index != 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_entry_video_default_option, KEY_EVENT_UP);
        }
        else
        {
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        }
    }
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

    /* Highlight on member list item */
#if defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__)
    if (index == g_phb_callergroup_member_index)
    {
       // ChangeLeftSoftkey(STR_GLOBAL_OK, STR_GLOBAL_OK);   //huyi-20080428-MTKCR00001467
		 ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        SetLeftSoftkeyFunction(mmi_phb_callergroup_member_pre_enter_list, KEY_EVENT_UP);
    }
#endif /* defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_name_is_duplicated
 * DESCRIPTION
 *  Checks if name is duplicated before saving the Caller Group details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_phb_callergroup_name_is_duplicated(U16 group_index, S8* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    PHB_CALLER_GROUP_STRUCT *callerGroups;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;

    /* Each group name can not be the same. */
    for (i = 0; i < MAX_PB_CALLER_GROUPS; ++i)
    {
        if (i != group_index)
        {
            if (!mmi_ucs2cmp((PS8) callerGroups[i].groupName, group_name))
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_detail_pre_save
 * DESCRIPTION
 *  Checks before saving the Caller Group details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_detail_pre_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_callergroup_name_is_duplicated(g_phb_cntx.active_index, pbName))
    {
        DisplayPopup((PU8) GetString(STR_CG_RENAME_FAIL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        mmi_phb_entry_callergroup_detail_save_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_detail_save_confirm
 * DESCRIPTION
 *  Confirms for saving Caller groups details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_detail_save_confirm(void)
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

#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
    {
        SetLeftSoftkeyFunction(mmi_phb_gas_save_req, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
        SetLeftSoftkeyFunction(mmi_phb_callergroup_detail_save, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_detail_save
 * DESCRIPTION
 *  Saves the Caller Group details on the NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_detail_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    BOOL copy_image = TRUE, copy_video = TRUE;
    PHB_CALLER_GROUP_STRUCT *callerGroups;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);

    callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;

    mmi_ucs2cpy((S8*) callerGroups[g_phb_cntx.active_index].groupName, pbName);

    /* Ring Tone Setting */
    callerGroups[g_phb_cntx.active_index].ringToneID = g_phb_cntx.ring_tone_list[g_phb_cntx.selected_ring_index];

    /* Image Setting */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    if ((g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 1) /* De-select the file if selection is not from file. */
    #ifdef __MMI_AVATAR__
        && (g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 2)
    #endif
        )
    {
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
    }
    else if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 1) &&
        (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT 
    #ifdef __MMI_AVATAR__
        || g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH
        || g_phb_image_type_id == 2
    #endif
        ))
    {
        g_phb_cntx.selected_pic_index = 0;
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#ifdef __MMI_AVATAR__
    else if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 2) &&
        (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT
        || g_phb_image_type_id == 1))
    {
        g_phb_cntx.selected_pic_index = 0;
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#endif /* def __MMI_AVATAR__ */
    else if (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT)      /* Set selection to none if not select picture from file */
    {
        g_phb_cntx.selected_pic_index = 0;
    }

    copy_image = mmi_phb_image_update_by_index((U16) (g_phb_cntx.active_index + 5001)); /* Copy image to folder in file system, 5001 for group 1 and so on. */
    if (!copy_image)    /* Edit image fail. */
    {
        g_phb_cntx.selected_pic_index = 0;
    }

    if (g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 1)
    {
        callerGroups[g_phb_cntx.active_index].pictureTagID = 1;
    }
#ifdef __MMI_AVATAR__
    else if (g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 2)
    {
        callerGroups[g_phb_cntx.active_index].pictureTagID = 2;
    }		
#endif /* def __MMI_AVATAR__ */
    else
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
        callerGroups[g_phb_cntx.active_index].pictureTagID = g_phb_cntx.image_id_list[g_phb_cntx.selected_pic_index];

    /* Alert Setting */
#if defined(__MMI_CALLERGROUP_NO_ALERT__)
    callerGroups[g_phb_cntx.active_index].alertType = MMI_ALERT_NONE;
#else 
    callerGroups[g_phb_cntx.active_index].alertType = (MMI_ALERT_TYPE) g_phb_cntx.selected_alert_index;
#endif 

    /* LED setting */
#if !defined(HARDWARE_LED_NOT_SUPPORT)
    callerGroups[g_phb_cntx.active_index].LEDPatternId = (U8) g_phb_cntx.selected_pattern_index;
#else 
    callerGroups[g_phb_cntx.active_index].LEDPatternId = 0; /* no pattern */
#endif 

    /* Incoming call video setting */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    if ((g_phb_cntx.selected_video_index != g_phb_cntx.total_video_id - 1) /* De-select the file if selection is not from file. */
    #ifdef __MMI_AVATAR__
        && (g_phb_cntx.selected_video_index != g_phb_cntx.total_video_id - g_phb_avatar_video_minus)
    #endif
    #ifdef __MMI_SWFLASH__
        && (g_phb_cntx.selected_video_index != g_phb_cntx.total_video_id - g_phb_swflash_video_minus)
    #endif
        )
    {
        g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
    }
    else if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1) &&
        (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT 
    #ifdef __MMI_AVATAR__
        || g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH
    #endif
    #ifdef __MMI_SWFLASH__
        || g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH
    #endif
        ))
    {
        g_phb_cntx.selected_video_index = 0;
        g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#ifdef __MMI_AVATAR__
    else if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus) &&
        (g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH))
    {
        g_phb_cntx.selected_video_index = 0;
        g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#endif /* def __MMI_AVATAR__ */
#ifdef __MMI_SWFLASH__
    else if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus) &&
        (g_phb_cntx.video_location != MMI_PHB_SWFLASH_SELECT_PATH))
    {
        g_phb_cntx.selected_video_index = 0;
        g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#endif /* def __MMI_AVATAR__ */
    else if (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT)      /* Set selection to none if not select picture from file */
    {
        g_phb_cntx.selected_video_index = 0;
    }
    callerGroups[g_phb_cntx.active_index].VideoID = mmi_phb_video_update_by_index_for_path(callerGroups[g_phb_cntx.active_index].VideoID, &copy_video);
    if (!copy_video)    /* Update video fail. */
    {
        g_phb_cntx.selected_video_index = 0;
    }
#endif 

    /* Check if name is modified. */
    if ((callerGroups[g_phb_cntx.active_index].is_modified == 0) &&
        (mmi_ucs2cmp
         ((S8*) callerGroups[g_phb_cntx.active_index].groupName,
          GetString((U16) (STR_CALLER_GROUP_1 + g_phb_cntx.active_index))) != 0))
    {
        callerGroups[g_phb_cntx.active_index].is_modified = 1;
    }

    WriteRecord(NVRAM_EF_PHB_CALLER_GROUPS_LID, 1, callerGroups, CALLER_GROUPS_RECORD_SIZE, &pError);

    /* Data update success, but image or video add fail */
    if (!copy_image || !copy_video)
    {
        S8 str_buff[64 * 2];

        memset(str_buff, 0, 2);

        if (!copy_image)
        {
            mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_IMAGE_FAIL));
        }

        if (!copy_video)
        {
            if (!copy_image)
            {
                mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_COMMA));
            }
            mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_VIDEO_FAIL));
        }
        mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_EDIT_FAIL));
        DisplayPopup((U8*) str_buff, IMG_GLOBAL_ERROR, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }

    if (!DeleteNScrId(SCR_ID_PHB_FMGR_SAVE_OPTION)) /* Enter From Save image from file manager */
    {
        DeleteNScrId(SCR_CALLER_GRP_DETAILS);   /* Enter from caller group */
    }
}


#define MMI_PHB_CALLER_GROUP_MEMBER
/*-------------------------------------------------Caller Group Member List -----------------------------------------------------------*/
#if defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_callergroup_member_add
 * DESCRIPTION
 *  Highlight function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_callergroup_member_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_callergroup_member_pre_enter_add, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_callergroup_member_pre_enter_add, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_callergroup_member_delete
 * DESCRIPTION
 *  Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_callergroup_member_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_callergroup_member_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_member_list
 * DESCRIPTION
 *  Entry function of phonebook caller group member list.
 *  Will show list if any entry exists, or will display "add" screen at begin.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_member_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_CALLERGROUP_MEMBER_LIST, mmi_phb_exit_callergroup_member_list, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_CALLERGROUP_MEMBER_LIST);
    state = (S8) - 1;
    if (guiBuffer != NULL)
    {
        state = get_list_menu_category_history_state(SCR_ID_PHB_CALLERGROUP_MEMBER_LIST, guiBuffer);
        if (state != -1)
        {
            phbListView = (U8) state;
            g_phb_callergroup_member_count = mmi_phb_callergroup_member_count_number((U8) phbListView);
        }
    }

#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.active_index < MAX_PB_CALLER_GROUPS)
#endif 
    {
        /* Allocate a buffer to store caller group of each entry to enhance speed. */
        if (g_phb_callergroup_ptr == NULL)
    #if (MAX_PB_ENTRIES >= 1000)
            g_phb_callergroup_ptr = (U16*) g_phb_list_filter;
    #else /* (MAX_PB_ENTRIES >= 1000) */ 
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
            g_phb_callergroup_ptr = OslMalloc(MAX_PB_ENTRIES * sizeof(U16));
    #else 
            g_phb_callergroup_ptr = OslMalloc(MAX_PB_PHONE_ENTRIES * sizeof(U16));
    #endif 
    #endif /* (MAX_PB_ENTRIES >= 1000) */ /* MAX_PB_ENTRIES >= 1000 */

        /* After allocate buffer, make cache for caller group of each entry. */
        mmi_phb_callergroup_member_make_group_id_cache();
    }

    if (phbListView == MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST)
    {
        /* Build alpha index list */
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_list_build_alpha_index(
            g_phb_callergroup_ptr,
            (U16) (g_phb_cntx.active_index + 1),
            TRUE,
            MMI_STORAGE_NONE);
    #else /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 
    #ifdef __MMI_PHB_USIM_FIELD__
        if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
        {
            mmi_phb_list_build_alpha_index(
                (U16*) g_phb_cntx.group_type,
                (U16) (g_phb_cntx.active_index + 1 - MAX_PB_CALLER_GROUPS),
                TRUE,
                MMI_SIM);
        }
        else
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
            mmi_phb_list_build_alpha_index(g_phb_callergroup_ptr, (U16) (g_phb_cntx.active_index + 1), TRUE, MMI_NVRAM);
    #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 
        g_phb_cntx.refresh_list = 1;

        RegisterHighlightHandler(mmi_phb_get_index_second_level);

        ShowCategory184Screen(
            STR_ID_PHB_CALLERGROUP_MEMBER_LIST,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_phb_callergroup_member_count,
            mmi_phb_callergroup_member_list_get_item,
            mmi_phb_callergroup_member_list_get_hint,
            g_phb_cntx.highlight_entry,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_phb_entry_callergroup_member_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_entry_callergroup_member_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (phbListView == MMI_PHB_LIST_FOR_ADD_MEMBER_LIST)
    {
        /* Build alpha index list */
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_list_build_alpha_index(
            (U16*) g_phb_callergroup_ptr,
            (U16) (g_phb_cntx.active_index + 1),
            FALSE,
            MMI_STORAGE_NONE);
    #else /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 
        mmi_phb_list_build_alpha_index(
            (U16*) g_phb_callergroup_ptr,
            (U16) (g_phb_cntx.active_index + 1),
            FALSE,
            MMI_NVRAM);
    #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 
        g_phb_cntx.refresh_list = 1;

        RegisterHighlightHandler(mmi_phb_get_index_third_level);

        ShowCategory184Screen(
            STR_SCR_PBOOK_VIEW_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_ADD,
            0,
            STR_GLOBAL_BACK,
            0,
            g_phb_callergroup_member_count,
            mmi_phb_callergroup_member_list_get_item,
            mmi_phb_callergroup_member_list_get_hint,
            g_phb_cntx.highlight_entry,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_phb_entry_callergroup_member_add, KEY_EVENT_UP);
    }

    /* register multitap key for fast jump by alpha index */
    register_multitap_no_draw_key_handlers();
    set_multitap_functions(mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback);
    change_multitap_mode(0);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_callergroup_member_list
 * DESCRIPTION
 *  Exit function of caller group member list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_callergroup_member_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    S8 state = (S8) phbListView;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_CALLERGROUP_MEMBER_LIST;

    h.scrnID = SCR_ID_PHB_CALLERGROUP_MEMBER_LIST;
    h.entryFuncPtr = mmi_phb_entry_callergroup_member_list;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);

    set_list_menu_category_history_state(SCR_ID_PHB_CALLERGROUP_MEMBER_LIST, h.guiBuffer, state);
    AddHistory(h);
    reset_multitaps(); /* pair with set_multitap_functions */

    /* Free memory */
#if (MAX_PB_ENTRIES < 1000)
    if (g_phb_callergroup_ptr)
    {
        OslMfree(g_phb_callergroup_ptr);
        g_phb_callergroup_ptr = NULL;
    }
#endif /* (MAX_PB_ENTRIES < 1000) */ /* MAX_PB_ENTRIES < 1000 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_member_option
 * DESCRIPTION
 *  Entry function of caller group member list options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_member_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[2];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION,
        mmi_phb_exit_callergroup_member_option,
        mmi_phb_entry_callergroup_member_option,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION);
    nNumofItem = GetNumOfChild(MENU_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Show Add New Only. */
    if (((guiBuffer == NULL) && (g_phb_callergroup_member_count == 0)) ||
        (mmi_phb_callergroup_member_count_number(MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST) == 0))
    {
        nNumofItem = 1;
    }

    ShowCategory15Screen(
        STR_ID_PHB_CALLERGROUP_MEMBER_LIST,
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
 *  mmi_phb_exit_callergroup_member_option
 * DESCRIPTION
 *  Exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_callergroup_member_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_member_add
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_member_add(void)
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
        get_string(STR_ID_PHB_ADD_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
    {
        phb_delete_grp_flag = FALSE;
        SetLeftSoftkeyFunction(mmi_phb_callergroup_member_usim_set_req, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
    SetLeftSoftkeyFunction(mmi_phb_callergroup_member_add_member, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_member_delete
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_member_delete(void)
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
        get_string(STR_DELETE_QUERY_MSG),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
    {
        phb_delete_grp_flag = TRUE;
        SetLeftSoftkeyFunction(mmi_phb_callergroup_member_usim_set_req, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
        SetLeftSoftkeyFunction(mmi_phb_callergroup_member_delete_member, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_phb_callergroup_member_list_get_item(
        S32 item_index,
        UI_string_type str_buff,
        PU8 *img_buff_p,
        U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > PhoneBookEntryCount))
    {
        return FALSE;
    }

    i = mmi_phb_callergroup_member_get_index((U8) phbListView, (U16) item_index);

    if (mmi_ucs2strlen((S8*) PhoneBook[i].alpha_id.name))
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) PhoneBook[i].alpha_id.name);
    }
    else
    {
        mmi_phb_convert_get_ucs2_number((S8*) str_buff, i);
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if(i >= (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES))
    {
        *img_buff_p = get_image(IMG_ID_CARD2_PHB_STORAGE_SIM);
    }
    else if (i >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_ID_CARD1_PHB_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#else	/* __MMI_DUAL_SIM_MASTER__ */
    if (i < MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_SIM);
    }
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_list_get_hint
 * DESCRIPTION
 *  hint call back function for dynamic list
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_phb_callergroup_member_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S8 temp_number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > PhoneBookEntryCount))
    {
        return FALSE;
    }

    i = mmi_phb_callergroup_member_get_index((U8) phbListView, (U16) item_index);

    mmi_phb_convert_get_ucs2_number((S8*) temp_number, i);
    if (mmi_ucs2strlen((S8*) PhoneBook[i].alpha_id.name) && mmi_ucs2strlen((S8*) temp_number))
    {
        mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_number);
    }
    else
    {
        return 0;
    }

    return 1;   /* One hint data only, can be more hints. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_pre_enter_list
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_member_pre_enter_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#endif /*__MMI_DUAL_SIM_MASTER__*/
    {
        if (PhoneBookEntryCount)
        {
            g_phb_cntx.highlight_entry = 0;
            phbListView = MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST;
            g_phb_callergroup_member_count = mmi_phb_callergroup_member_count_number((U8) phbListView);
            if (g_phb_callergroup_member_count > 0)
            {
                mmi_phb_entry_callergroup_member_list();
            }
            else
            {
                mmi_phb_entry_callergroup_member_option();
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
                IMG_GLOBAL_EMPTY,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                EMPTY_LIST_TONE);
        }
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_pre_enter_add
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_member_pre_enter_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phbListView = MMI_PHB_LIST_FOR_ADD_MEMBER_LIST;

    g_phb_callergroup_member_count = mmi_phb_callergroup_member_count_number((U8) phbListView);
    if (g_phb_callergroup_member_count > 0)
    {
        mmi_phb_entry_callergroup_member_list();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NO_ENTRY_TO_SELECT),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_add_member
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_member_add_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count, i;
    S16 pError;
    U16 store_index;
    U8 optid_record, optid_index, current_record = 0;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        store_index = g_phb_name_index[i];

    #if !defined(__MMI_PHB_CALLERGROUP_IN_SIM__)    /* Associate caller group in SIM card entry */
        if (store_index < MAX_PB_PHONE_ENTRIES) /* In NVRAM */
    #endif 
        {
            /* Get optional IDs record. */
            optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
            optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

            if (optid_record != current_record)
            {
                ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
                current_record = optid_record;
            }

            /* Get index */
            if (PhbOptIDs[optid_index].callerGroupID != (g_phb_cntx.active_index + 1))
            {
                if (count == g_phb_cntx.active_index_third)
                {
                    break;
                }

                count++;
            }
        }
    }

    store_index = g_phb_name_index[i];

    /* Read optional ID field and write it back. */
    optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

    ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    PhbOptIDs[optid_index].callerGroupID = g_phb_cntx.active_index + 1;
    WriteRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    DisplayPopup((PU8) GetString(STR_ID_PHB_ADDED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    g_phb_callergroup_member_count++;
    g_phb_cntx.highlight_entry = 0;
    DeleteNScrId(SCR_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION);
    phbListView = MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST;
    g_phb_callergroup_member_count = mmi_phb_callergroup_member_count_number((U8) phbListView);
    if (g_phb_callergroup_member_count == 1)
    {
        mmi_phb_entry_callergroup_member_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_delete_member
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_member_delete_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count, i;
    S16 pError;
    U16 store_index;
    U8 optid_record, optid_index, current_record = 0;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB_CALLER_GROUP_STRUCT* callerGroups; */

    /* callerGroups = (PHB_CALLER_GROUP_STRUCT*)g_phb_cntx.caller_group; */
    count = 0;
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        store_index = g_phb_name_index[i];

    #if !defined(__MMI_PHB_CALLERGROUP_IN_SIM__)    /* Associate caller group in SIM card entry */
        if (store_index < MAX_PB_PHONE_ENTRIES)
    #endif 
        {
            /* Get optional IDs record. */
            optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
            optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

            if (optid_record != current_record)
            {
                ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
                current_record = optid_record;
            }

            if ((g_phb_cntx.active_index + 1) == PhbOptIDs[optid_index].callerGroupID)
            {
                if (count == g_phb_cntx.active_index_second)
                {
                    break;
                }

                count++;
            }
        }
    }

    store_index = g_phb_name_index[i];
    /* Read optional ID field and write it back. */
    optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

    ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    PhbOptIDs[optid_index].callerGroupID = 0;
    WriteRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);

    if (mmi_phb_callergroup_member_count_number(MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST) == 0)
    {
        DeleteNScrId(SCR_ID_PHB_CALLERGROUP_MEMBER_LIST);
    }
    else
    {
        g_phb_cntx.highlight_entry = 0;
        DeleteUptoScrID(SCR_ID_PHB_CALLERGROUP_MEMBER_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_count_number
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  list_enum       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_callergroup_member_count_number(U8 list_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j, count = 0;
    S16 pError;
    U8 optid_record, optid_index, current_record = 0;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
    {
        for (i = 0; i < MAX_PB_SIM_ENTRIES; i++)
        {
            if (((list_enum == MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST) &&
                 g_phb_cntx.group_type[i] == (g_phb_cntx.active_index - MAX_PB_CALLER_GROUPS + 1))
                ||
                ((list_enum == MMI_PHB_LIST_FOR_ADD_MEMBER_LIST) &&
                 g_phb_cntx.group_type[i] != (g_phb_cntx.active_index - MAX_PB_CALLER_GROUPS + 1)))
            {
                for (j = 0; j < PhoneBookEntryCount; j++)
                {
                    if ((i + MAX_PB_PHONE_ENTRIES) == g_phb_name_index[j])
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
#endif /* __MMI_PHB_USIM_FIELD__ */ 

#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
    for (i = 0; i < MAX_PB_ENTRIES; i++)
#else 
    for (i = 0; i < MAX_PB_PHONE_ENTRIES; i++)
#endif 
    {
        /* Get optional IDs record. */
        optid_record = (i / OPTIONAL_IDS_RECORD_TOTAL) + 1;
        optid_index = i - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

        if (optid_record != current_record)
        {
            ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
            current_record = optid_record;
        }

        /* Count Entry Number */
        if (((list_enum == MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST) &&
             (PhbOptIDs[optid_index].callerGroupID) == (g_phb_cntx.active_index + 1))
            ||
            ((list_enum == MMI_PHB_LIST_FOR_ADD_MEMBER_LIST) &&
             (PhbOptIDs[optid_index].callerGroupID != (g_phb_cntx.active_index + 1))))
        {

            for (j = 0; j < PhoneBookEntryCount; j++)
                if (i == g_phb_name_index[j])
                {
                    count++;
                    break;
                }
        }

    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_make_group_id_cache
 * DESCRIPTION
 *  Allocate a buffer and make cache for callergroup of each phonebook entry.
 *  This is to reduce the NVRAM when showing in list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_member_make_group_id_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S16 pError;
    U8 optid_record, optid_index, current_record = 0;
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
    for (store_index = 0; store_index < MAX_PB_ENTRIES; store_index++)
#else 
    for (store_index = 0; store_index < MAX_PB_PHONE_ENTRIES; store_index++)
#endif 
    {
        /* Get optional IDs record. */
        optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
        optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;

        if (optid_record != current_record)
        {
            ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
            current_record = optid_record;
        }

        g_phb_callergroup_ptr[store_index] = (U16) PhbOptIDs[optid_index].callerGroupID;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_get_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  list_enum       [IN]        
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_callergroup_member_get_index(U8 list_enum, U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, count = 0;
    U16 store_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.active_index >= MAX_PB_CALLER_GROUPS)
    {
        for (i = 0; i < PhoneBookEntryCount; i++)
        {
            store_index = g_phb_name_index[i];

            /* Associate caller group in USIM card entry */
            if (store_index >= MAX_PB_PHONE_ENTRIES)
            {
                U16 filter_index = store_index - MAX_PB_PHONE_ENTRIES;

                if (((list_enum == MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST) &&
                     (g_phb_cntx.group_type[filter_index] == (g_phb_cntx.active_index + 1 - MAX_PB_CALLER_GROUPS)))
                    ||
                    ((list_enum == MMI_PHB_LIST_FOR_ADD_MEMBER_LIST) &&
                     (g_phb_cntx.group_type[filter_index] != (g_phb_cntx.active_index + 1 - MAX_PB_CALLER_GROUPS))))
                {
                    if (count == item_index)
                    {
                        break;
                    }
                    count++;
                }
            }
        }
        return store_index;
    }
#endif /* __MMI_PHB_USIM_FIELD__ */ 

    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        store_index = g_phb_name_index[i];

    #if !defined(__MMI_PHB_CALLERGROUP_IN_SIM__)    /* Associate caller group in SIM card entry */
        if (store_index < MAX_PB_PHONE_ENTRIES)
    #endif 
        {
            if (((list_enum == MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST) &&
                 (g_phb_callergroup_ptr[store_index] == (g_phb_cntx.active_index + 1)))
                ||
                ((list_enum == MMI_PHB_LIST_FOR_ADD_MEMBER_LIST) &&
                 (g_phb_callergroup_ptr[store_index] != (g_phb_cntx.active_index + 1))))
            {
                if (count == item_index)
                {
                    break;
                }
                count++;
            }
        }
    }

    return store_index;
}

#endif /* defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__) */ /* END of #if defined( __MMI_PHB_CALLERGROUP_MEMBER_LIST__   ) */
/*--------------------------------------------END Caller Group Member List -----------------------------------------------------------*/

#define MMI_PHB_INLINE_ITEM


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ring_tone_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for ringtones inline selection list
 * PARAMETERS
 *  ringToneIndex       [IN]        Ring tone id for play
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ring_tone_highlight_hdlr(S32 ringToneIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_stop_ring_tone_id();
    if (ringToneIndex)
    {
        g_phb_curr_ring_tone_id = g_phb_cntx.ring_tone_list[ringToneIndex];
        g_phb_last_ring_tone_id = g_phb_curr_ring_tone_id;
        if (!IsSilentModeActivated() && !isInCall())    /* need to check if it's in call because phonebook use this function, too */
        {
        #ifdef __MMI_SILENT_MEETING_PROFILE__
            if (IsMeetingModeActivated())
            {
                g_phb_last_ring_tone_id = 0;
            }
            else
        #endif
            {
                StartTimer(PHB_NOTIFYDURATION_TIMER, 1000, mmi_phb_play_ring_tone_id);
            }
        }
        else    
        {
            g_phb_last_ring_tone_id = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_play_ring_tone_id
 * DESCRIPTION
 *  Plays the selected ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_play_ring_tone_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_phb_last_ring_tone_id = g_phb_curr_ring_tone_id; */
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    /* Play ring tone repeatedly */
    AudioPlayReq(g_phb_curr_ring_tone_id, (U8) DEVICE_AUDIO_PLAY_INFINITE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_stop_ring_tone_id
 * DESCRIPTION
 *  Stops the currently played ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_stop_ring_tone_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_last_ring_tone_id)
    {
        StopTimer(PHB_NOTIFYDURATION_TIMER);
        AudioStopReq(g_phb_last_ring_tone_id);
    }
    g_phb_last_ring_tone_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_led_pattern_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for LED patterns inline selection list
 * PARAMETERS
 *  index       [IN]        Index for play
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_led_pattern_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_stop_led_pattern_id();
    if (index)
    {
        g_phb_curr_pattern_id = (U8) index;
        g_phb_last_pattern_id = g_phb_curr_pattern_id;
        StartTimer(PHB_NOTIFYDURATION_TIMER, 1000, mmi_phb_play_led_pattern_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_play_led_pattern_id
 * DESCRIPTION
 *  Plays the selected LED pattern
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_play_led_pattern_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_phb_last_pattern_id = g_phb_curr_pattern_id; */
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    PlayPatternCallerGroup(g_phb_curr_pattern_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_stop_led_pattern_id
 * DESCRIPTION
 *  Stops the currently played LED pattern
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_stop_led_pattern_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_last_pattern_id)
    {
        StopTimer(PHB_NOTIFYDURATION_TIMER);
        StopPatternCallerGroup(g_phb_last_pattern_id);
    }
    g_phb_last_pattern_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_led_and_alert_list
 * DESCRIPTION
 *  Builds the Ringtone, Pictures, Alerts & Patterns list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_led_and_alert_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use the same string ID with UserProfilesResDef.h */
#if !defined(HARDWARE_LED_NOT_SUPPORT)
    g_phb_cntx.led_name_list[0] = (PU8) GetString(STR_GLOBAL_NONE);
    g_phb_cntx.led_name_list[1] = (PU8) GetString(STR_LIGHT_STATUS_COLOR1);
    g_phb_cntx.led_name_list[2] = (PU8) GetString(STR_LIGHT_STATUS_COLOR2);
    g_phb_cntx.led_name_list[3] = (PU8) GetString(STR_LIGHT_STATUS_COLOR3);
    g_phb_cntx.led_name_list[4] = (PU8) GetString(STR_LIGHT_STATUS_COLOR4);
    g_phb_cntx.led_name_list[5] = (PU8) GetString(STR_LIGHT_STATUS_COLOR5);
    g_phb_cntx.led_name_list[6] = (PU8) GetString(STR_LIGHT_STATUS_COLOR6);
#endif /* defined(HARDWARE_LED_NOT_SUPPORT) */ 

    /* Use Same String ID with UserProfilesResDef.h  */
    g_phb_cntx.alert_name_list[0] = (PU8) GetString(STR_GLOBAL_NONE);
    g_phb_cntx.alert_name_list[1] = (PU8) GetString(STR_RING);
    g_phb_cntx.alert_name_list[2] = (PU8) GetString(STR_VIBRATION_ONLY);
    g_phb_cntx.alert_name_list[3] = (PU8) GetString(STR_VIBRATION_AND_RING);
    g_phb_cntx.alert_name_list[4] = (PU8) GetString(STR_VIBRATION_THEN_RING);
#if !defined(HARDWARE_LED_NOT_SUPPORT)
    g_phb_cntx.alert_name_list[5] = (PU8) GetString(STR_SILENT);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_ring_tone_list
 * DESCRIPTION
 *  Builds the ringtone list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_ring_tone_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j;
    U8 ringToneStartId, ringToneTotalId, midiToneStartId, midiToneTotalId;
    U8 factoryTonesCnt;     /* Factory Default */
    U8 factoryMelodiesCnt, composedMelodiesCnt, downloadMelodiesCnt, downloadEmsMelodiesCnt;    /* iMelody */
    U8 downloadTonesCnt;    /* WAP download */
    U8 extMelodyCnt;        /* File Manager Associate. */

    S8 dummyStr[8];

    /* Default Factory Tones. */
    DYNAUDIOINFO *factoryTones;

    /* iMelody support */
#if defined(__MMI_IMELODY_SUPPORT__)
    DYNAUDIOINFO *factoryMelodies;

#if defined(__MMI_RING_COMPOSER__)
    DYNAUDIOINFO *composedMelodies;
#endif 
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 

    /* External Melody, select from file manager. */
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    DYNEXTMELODYINFO *ExtMelodyInfo;
#endif 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    DYNAUDIOINFO *DownloadThemeTones;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Default Factory Tones. */
    GetRingToneRange(&ringToneStartId, &ringToneTotalId);
    GetMidiRange(&midiToneStartId, &midiToneTotalId);
    factoryTonesCnt = GetFactoryTonesInfo(&factoryTones);

    /* iMelody support */
#if defined(__MMI_IMELODY_SUPPORT__)
    factoryMelodiesCnt = GetFactoryIMelodyInfo(&factoryMelodies);
    downloadMelodiesCnt = 0;

    downloadEmsMelodiesCnt = 0;

#if defined(__MMI_RING_COMPOSER__)
    composedMelodiesCnt = GetComposedIMelodyInfo(&composedMelodies);
#else 
    composedMelodiesCnt = 0;
#endif 
#else /* defined(__MMI_IMELODY_SUPPORT__) */ 
    factoryMelodiesCnt = 0;
    downloadMelodiesCnt = 0;
    downloadEmsMelodiesCnt = 0;
    composedMelodiesCnt = 0;
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 

    downloadTonesCnt = 0;

    /* External Melody, select from file manager. */
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    extMelodyCnt = PmgGetExtMelodyInfo(&ExtMelodyInfo);
#else 
    extMelodyCnt = 0;
#endif 

    /*
     *  The following section will Begin to associate label for inline selection.
     */

    g_phb_cntx.total_ring_tone = 1 + ringToneTotalId
        + midiToneTotalId
        + factoryTonesCnt
        + factoryMelodiesCnt
        + downloadTonesCnt + downloadMelodiesCnt + composedMelodiesCnt + downloadEmsMelodiesCnt + extMelodyCnt;

    g_phb_cntx.ring_tone_name_list[0] = (PU8) GetString(STR_GLOBAL_NONE);
    g_phb_cntx.ring_tone_list[0] = 0;
    mmi_ucs2cpy((PS8) subMenuData[0], GetString(STR_GLOBAL_NONE));

    /* Default Factory Tones. */
    for (j = 0; j < ringToneTotalId; ++j)
    {
        mmi_ucs2cpy((PS8) subMenuData[++i], GetString(STR_PROFILES_RING));
        gui_itoa((j + 1), (UI_string_type) dummyStr, 10);
        mmi_ucs2cat((PS8) subMenuData[i], dummyStr);
        g_phb_cntx.ring_tone_list[i] = j + ringToneStartId;
        g_phb_cntx.ring_tone_name_list[i] = subMenuData[i];
    }

    for (j = 0; j < midiToneTotalId; ++j)
    {
        mmi_ucs2cpy((PS8) subMenuData[++i], GetString(STR_PROFILES_MIDI));
        gui_itoa((j + 1), (UI_string_type) dummyStr, 10);
        mmi_ucs2cat((PS8) subMenuData[i], dummyStr);
        g_phb_cntx.ring_tone_list[i] = j + midiToneStartId;
        g_phb_cntx.ring_tone_name_list[i] = subMenuData[i];
    }

    for (j = 0; j < factoryTonesCnt; ++j)
    {
        g_phb_cntx.ring_tone_list[++i] = factoryTones[j].AudioId;
        g_phb_cntx.ring_tone_name_list[i] = factoryTones[j].AudioName;
    }

    /* iMelody support */
#if defined(__MMI_IMELODY_SUPPORT__)
    for (j = 0; j < factoryMelodiesCnt; ++j)
    {
        g_phb_cntx.ring_tone_list[++i] = factoryMelodies[j].AudioId;
        g_phb_cntx.ring_tone_name_list[i] = factoryMelodies[j].AudioName;
    }

#if defined(__MMI_RING_COMPOSER__)
    for (j = 0; j < composedMelodiesCnt; ++j)
    {
        g_phb_cntx.ring_tone_list[++i] = composedMelodies[j].AudioId;
        g_phb_cntx.ring_tone_name_list[i] = composedMelodies[j].AudioName;
    }
#endif /* defined(__MMI_RING_COMPOSER__) */ 

#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (GetThemeV2TonesInfo(&DownloadThemeTones) != 0 && mmi_tm_get_current_theme_ringtone())
    {
        ++g_phb_cntx.total_ring_tone;
        mmi_ucs2cpy((PS8) subMenuData[++i], GetString(STR_PROFILES_CURR_THEME));
        g_phb_cntx.ring_tone_list[i] = DownloadThemeTones->AudioId;
        g_phb_cntx.ring_tone_name_list[i] = subMenuData[i];
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    /* External Melody, select from file manager. */
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    for (j = 0; j < MAXIMUM_EXT_MELODY_NUM; ++j)
    {
        if (PmgIsEmptySlot(j) == MMI_TRUE)
        {
            continue;
        }

        g_phb_cntx.ring_tone_list[++i] = ExtMelodyInfo->info[j].id;

        if (IS_EXTMELODY_SHORTNAME(ExtMelodyInfo->info[j].filepath))
        {
            mmi_chset_mixed_text_to_ucs2_str(
                subMenuData[i],
                (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH,
                (U8*) ExtMelodyInfo->info[j].filename,
                g_chset_text_encoding);
        }
        else
        {
            mmi_ucs2cpy((PS8) subMenuData[i], (PS8) ExtMelodyInfo->info[j].filename);
        }

    #if (!defined(__MMI_SHOW_FILE_EXT__))
        PmgRemoveFileExt((S8*) subMenuData[i]);
    #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
        PmgRemoveFileDAFExt((S8*) subMenuData[i]);
    #endif 
        g_phb_cntx.ring_tone_name_list[i] = subMenuData[i];
    }
#endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_image_list
 * DESCRIPTION
 *  Builds Images list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_image_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j;
    U8 maxSystemImages = 4;
    DYNIMAGEINFO *fullScrFactoryImages, *associatedFactoryImages;
    U8 fullScrFactoryImagesCnt, associatedFactoryImagesCnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System Default Image */
    fullScrFactoryImagesCnt = GetFullScreenFactoryImagesInfo(&fullScrFactoryImages);
    associatedFactoryImagesCnt = GetAssociatedFactoryImagesInfo(&associatedFactoryImages);

    g_phb_cntx.total_image_id = 1 + maxSystemImages + fullScrFactoryImagesCnt + associatedFactoryImagesCnt;

    /* System Default Image */
    g_phb_cntx.image_name_list[0] = (PU8) GetString(STR_GLOBAL_NONE);
    g_phb_cntx.image_id_list[0] = IMG_PHB_DEFAULT;

    for (j = 0; j < maxSystemImages; ++j)
    {
        g_phb_cntx.image_name_list[++i] = (PU8) GetString((U16) (STR_PICTURE_1 + j));
        g_phb_cntx.image_id_list[i] = IMG_PHB_PICTURE1 + j;
    }

    for (j = 0; j < fullScrFactoryImagesCnt; ++j)
    {
        g_phb_cntx.image_name_list[++i] = fullScrFactoryImages[j].ImageName;
        g_phb_cntx.image_id_list[i] = fullScrFactoryImages[j].ImagesId;
    }

    for (j = 0; j < associatedFactoryImagesCnt; ++j)
    {
        g_phb_cntx.image_name_list[++i] = associatedFactoryImages[j].ImageName;
        g_phb_cntx.image_id_list[i] = associatedFactoryImages[j].ImagesId;
    }

    /* Select Image From File Manager */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    /* Select Image From 3D Avatar */
#ifdef __MMI_AVATAR__
    g_phb_cntx.total_image_id++;
    g_phb_cntx.image_name_list[++i] = (U8*) GetString(STR_ID_PHB_AVATAR_SELECT_FILE);
    g_phb_cntx.image_id_list[i] = 2;
#endif
    g_phb_cntx.total_image_id++;
    g_phb_cntx.image_name_list[++i] = (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
    g_phb_cntx.image_id_list[i] = 1;
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_caller_group_list
 * DESCRIPTION
 *  Builds caller group list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_caller_group_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    PHB_CALLER_GROUP_STRUCT *callerGroups;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;

    myCallerGrpnames[0] = (PU8) GetString(STR_GLOBAL_NONE);
    for (i = 1; i <= MAX_PB_CALLER_GROUPS; i++)
    {
        myCallerGrpnames[i] = callerGroups[i - 1].groupName;
    }
}

#ifdef __MMI_PHB_USIM_FIELD__


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_usim_group_list
 * DESCRIPTION
 *  Builds caller group list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_usim_group_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    MMI_PHB_NAME_STRUCT *callerGroups;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callerGroups = (MMI_PHB_NAME_STRUCT*) g_phb_cntx.usim_group;

    myCallerGrpnames[0] = (PU8) GetString(STR_GLOBAL_NONE);
    for (i = 1; i <= g_phb_cntx.gas_total; i++)
    {
        myCallerGrpnames[i] = callerGroups[i - 1].name;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_callergroup_usim_detail
 * DESCRIPTION
 *  Builds caller group list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_callergroup_usim_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U8 j = 0;
    U16 CGDetailsImageList[MAX_CALLER_GRP_USIM_ITEMS];
    MMI_PHB_NAME_STRUCT *usim_caller_groups = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_callergroup_usim_detail.>\n",
                         __FILE__, __LINE__);

    EntryNewScreen(SCR_CALLER_GRP_DETAILS, mmi_phb_exit_callergroup_detail, NULL, NULL);
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_CALLER_GRP_DETAILS);
    inputBuffer = GetCurrNInputBuffer(SCR_CALLER_GRP_DETAILS, &inputBufferSize);

    usim_caller_groups = (MMI_PHB_NAME_STRUCT*) g_phb_cntx.usim_group;
    mmi_ucs2cpy(pbName, (PS8) usim_caller_groups[g_phb_cntx.active_index - MAX_PB_CALLER_GROUPS].name);

    /* Caller Group Name */
    SetInlineItemActivation(&wgui_inline_items[j], KEY_LSK, KEY_EVENT_UP);
#if defined(__PHB_0x81_SUPPORT__)
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[j],
        STR_ID_PHB_NAME,
        IMG_SCR_PBOOK_CAPTION,
        (PU8) pbName,
        g_phb_cntx.group_name_len + 1,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
        INPUT_TYPE_EXT_USE_0x81_ENCODING);
#else /* defined(__PHB_0x81_SUPPORT__) */ 
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[j],
        STR_ID_PHB_NAME,
        IMG_SCR_PBOOK_CAPTION,
        (PU8) pbName,
        g_phb_cntx.group_name_len + 1,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING));
#endif /* defined(__PHB_0x81_SUPPORT__) */ 
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[j],
        STR_GRP_NAME_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        (PU8) pbName,
        g_phb_cntx.group_name_len + 1,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[j], mmi_phb_set_full_scr_lsk);
    CGDetailsImageList[j++] = IMG_CG_NAME;

    /* Caller Group Member List */
#if defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__)
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[j], (U8*) GetString(STR_ID_PHB_CALLERGROUP_MEMBER_LIST));
    g_phb_callergroup_member_index = j;
    CGDetailsImageList[j++] = IMG_ID_PHB_CALLERGRP_MEMBER;
#endif /* defined(__MMI_PHB_CALLERGROUP_MEMBER_LIST__) */ 

    RegisterHighlightHandler(mmi_phb_callergroup_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, j, inputBuffer);

    }
    ShowCategory57Screen(
        STR_SCR_CG_DETAILS_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_EDIT_LSK,
        STR_GLOBAL_DONE,
        IMG_DONE_RSK,
        j,
        CGDetailsImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_phb_gas_pre_save, GoBackHistory);

    if (g_phb_cntx.set_done_flag)
    {
        g_phb_cntx.set_done_flag = 0;
        set_wgui_inline_list_menu_changed();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_gas_save_rsp
 * DESCRIPTION
 *  Response of saving the Caller Group Name to SIM GAS
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_gas_save_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_PHB_NAME_STRUCT *caller_groups = NULL;
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_gas_save_rsp.>\n", __FILE__, __LINE__);

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
    {
        if (localPtr->result.flag == 0) /* Set Entry Success */
        {
            mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_SUCCESS);
        }
        else
        {
            mmi_phb_java_set_group_info_rsp(MMI_PHB_JAVA_ERROR);
        }
        g_phb_enter_from = MMI_PHB_ENTER_NONE;
        return;
    }
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
    if (localPtr->result.flag == 0) /* Set Entry Success */
    {
        caller_groups = (MMI_PHB_NAME_STRUCT*) g_phb_cntx.usim_group;
        mmi_ucs2cpy((S8*) caller_groups[g_phb_cntx.active_index - MAX_PB_CALLER_GROUPS].name, pbName);
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }

    DeleteNScrId(SCR_CALLER_GRP_DETAILS);   /* Enter from caller group */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_gas_save_req
 * DESCRIPTION
 *  Sends the request to the stack to save the information of a phonebook entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_gas_save_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_gas_save_req.>\n", __FILE__, __LINE__);

    myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
    {
        myMsgPtr->list.index = g_phb_cntx.java_store_index;
        myMsgPtr->list.record_index = g_phb_cntx.java_store_index;
    }
    else
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
    {
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
        myMsgPtr->list.index = g_phb_cntx.active_index - MAX_PB_CALLER_GROUPS + 1;
        myMsgPtr->list.record_index = g_phb_cntx.active_index - MAX_PB_CALLER_GROUPS + 1;
    }

    myMsgPtr->type = MMI_PHB_GAS;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.storage = MMI_SIM;

    mmi_phb_op_set_entry_prepare_name_number(&myMsgPtr->list, pbName, pbNumber);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_gas_save_rsp, PRT_PHB_SET_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_gas_is_duplicated
 * DESCRIPTION
 *  Checks if name is duplicated before saving the Caller Group details
 * PARAMETERS
 *  group_index        [IN]     
 *  group_name         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_phb_gas_is_duplicated(U16 group_index, S8* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_PHB_NAME_STRUCT *caller_groups;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    caller_groups = (MMI_PHB_NAME_STRUCT*) g_phb_cntx.usim_group;

    /* Each group name can not be the same. */
    for (i = 0; i < MAX_PB_USIM_GROUPS; ++i)
    {
        if (i != group_index)
        {
            if (!mmi_ucs2cmp((PS8) caller_groups[i].name, group_name))
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_gas_pre_save
 * DESCRIPTION
 *  Checks before saving the Caller Group Name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_gas_pre_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_phb_cntx.active_index    >= MAX_PB_CALLER_GROUPS);
    if (mmi_phb_gas_is_duplicated((U16)(g_phb_cntx.active_index - MAX_PB_CALLER_GROUPS), pbName))
    {
        DisplayPopup((PU8) GetString(STR_CG_RENAME_FAIL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        mmi_phb_entry_callergroup_detail_save_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_usim_set_rsp
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_callergroup_member_usim_set_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_GRP_RSP_STRUCT *localPtr;
    U16 record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_GRP_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_callergroup_member_usim_set_rsp.>\n",
                         __FILE__, __LINE__);

    if (localPtr->result.flag == 0) /* Set GRP OK */
    {
        record_index = localPtr->record_index;
        if (phb_delete_grp_flag)
        {
            g_phb_cntx.group_type[record_index - 1] = 0;
        }
        else
        {
            g_phb_cntx.group_type[record_index - 1] = g_phb_cntx.active_index + 1 - MAX_PB_CALLER_GROUPS;
        }

        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
        g_phb_callergroup_member_count++;
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }

    g_phb_cntx.highlight_entry = 0;
    DeleteNScrId(SCR_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION);
    phbListView = MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST;
    g_phb_callergroup_member_count = mmi_phb_callergroup_member_count_number((U8) phbListView);
    if (g_phb_callergroup_member_count == 1)
    {
        mmi_phb_entry_callergroup_member_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_member_usim_set_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_callergroup_member_usim_set_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_GRP_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_callergroup_member_usim_set_req.>\n",
                         __FILE__, __LINE__);

    mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
    myMsgPtr = (MSG_PHB_SET_GRP_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_GRP_REQ_STRUCT));

    if (phb_delete_grp_flag)
    {
        myMsgPtr->group_type = 0;
        store_index = mmi_phb_callergroup_member_get_index(
                        MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST,
                        g_phb_cntx.active_index_second);
    }
    else
    {
        myMsgPtr->group_type = g_phb_cntx.active_index + 1 - MAX_PB_CALLER_GROUPS;
        store_index = mmi_phb_callergroup_member_get_index(
                        MMI_PHB_LIST_FOR_ADD_MEMBER_LIST,
                        g_phb_cntx.active_index_third);
    }

    myMsgPtr->record_index = store_index + 1 - MAX_PB_PHONE_ENTRIES;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_GRP_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_callergroup_member_usim_set_rsp, PRT_PHB_SET_GRP_RSP);
    OslMsgSendExtQueue(&Message);

}

#endif /* __MMI_PHB_USIM_FIELD__ */ 

#if defined(__MMI_INCOMING_CALL_VIDEO__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_video_list
 * DESCRIPTION
 *  Builds Video list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_video_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System Default video */
    g_phb_cntx.video_name_list[count] = (U8*) GetString(STR_GLOBAL_NONE);
    g_phb_cntx.video_id_list[count] = 0;
    g_phb_cntx.total_video_id = 1;

#ifdef __MMI_SWFLASH__
    for (i = 0 ; i < MMI_PHB_SWFLASH_TOTAL; i++)
    {
        g_phb_cntx.video_name_list[++count] = (U8*)GetString((U16)(STR_ID_PHB_SWFLASH_1+i));
        g_phb_cntx.video_id_list[count] = MFH_ID_PHB_MTCALL_1 + i;
        g_phb_cntx.total_video_id++;
    }
#endif /* __MMI_SWFLASH__ */


    for (i = 0; i < 1; i++)
    {
        g_phb_cntx.video_name_list[++count] = (U8*) GetString((U16) (STR_ID_PHB_VIDEO_1 + i));
        g_phb_cntx.video_id_list[count] = VDO_ID_PHB_MTCALL_1 + i;
        g_phb_cntx.total_video_id++;
    }

#ifdef __MMI_SWFLASH__
    /* Select From SWFlash */
    g_phb_cntx.video_name_list[++count] = (U8*)GetString(STR_ID_PHB_CALLER_VIDEO_FROM_SWFLASH);
    g_phb_cntx.video_id_list[count] = 0xA000;
    g_phb_cntx.total_video_id++;
#endif /* __MMI_SWFLASH__ */

#ifdef __MMI_AVATAR__
    /* Select From 3D Avatar */
    g_phb_cntx.video_name_list[++count] = (U8*) GetString(STR_ID_PHB_AVATAR_SELECT_FILE);
    g_phb_cntx.video_id_list[count] = 0x9000;
    g_phb_cntx.total_video_id++;
#endif /* __MMI_AVATAR__ */

    /* Select From File */
    g_phb_cntx.video_name_list[++count] = (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
    g_phb_cntx.video_id_list[count] = 0x8000;
    g_phb_cntx.total_video_id++;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_video_index
 * DESCRIPTION
 *  Retrieve video list index by video id.
 * PARAMETERS
 *  video_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_get_video_index(U16 video_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* An external video resource */
    if (video_id & 0x8000)
    {
#ifdef __MMI_AVATAR__
        if (video_id & 0x1000)
        {
            return (U8)(g_phb_cntx.total_video_id - g_phb_avatar_video_minus);
        }
#endif /* __MMI_SWFLASH__ */
#ifdef __MMI_SWFLASH__
        if (video_id & 0x2000)
        {
            return (U8)(g_phb_cntx.total_video_id - g_phb_swflash_video_minus);
        }
#endif /* __MMI_SWFLASH__ */
        return (U8) (g_phb_cntx.total_video_id - 1);
    }

    /* An internal video resource, mask it to get resource id */
    video_id &= 0x3FFF;

    if (video_id)
    {
        for (i = 0; i < (g_phb_cntx.total_video_id - 1); i++)
        {
            if (video_id == g_phb_cntx.video_id_list[i])
            {
                return i;
            }
        }
    }

    return 0;
}
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_ring_tone_index
 * DESCRIPTION
 *  Gets the index of the current ringtone in ringtone list
 * PARAMETERS
 *  ringToneId          [IN]        
 *  ringToneID(?)       [IN]        Ring tone id  for lookup
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_get_ring_tone_index(U16 ringToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ringToneId)
    {
        for (i = 0; i < g_phb_cntx.total_ring_tone; ++i)
        {
            if (g_phb_cntx.ring_tone_list[i] == ringToneId)
            {
                break;
            }
        }
        return i;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_image_index
 * DESCRIPTION
 *  Gets the index of the current image tag in  images list
 * PARAMETERS
 *  imageId         [IN]        Image for lookup
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_get_image_index(U16 imageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imageId)
    {
        for (i = 0; i < g_phb_cntx.total_image_id; ++i)
        {
            if (g_phb_cntx.image_id_list[i] == imageId)
            {
                return i;
            }
        }
        return 0;
    }
    else
    {
        return 0;
    }
}


#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_callergroup_copy_group_info
 * DESCRIPTION
 *  Displays the list of available Caller Groups
 * PARAMETERS
 *  group_index         [IN]
 *  group_name          [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_callergroup_copy_group_info(U8 group_index, U8* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_FIELD__
    MMI_PHB_NAME_STRUCT *usim_caller_groups = (MMI_PHB_NAME_STRUCT*) g_phb_cntx.usim_group;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_callergroup_copy_group_info.>\n", __FILE__,
                         __LINE__);

    if (!g_phb_cntx.nvram_data_init)
    {
        mmi_phb_init_get_data_from_nvram();
        g_phb_cntx.nvram_data_init = TRUE;
    }
    if (group_index < MAX_PB_CALLER_GROUPS)
    {
        PHB_CALLER_GROUP_STRUCT *callerGroups = (PHB_CALLER_GROUP_STRUCT*) g_phb_cntx.caller_group;
        mmi_ucs2cpy((S8*)group_name, (S8*)callerGroups[group_index].groupName);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else
    {
        if (mmi_ucs2strlen((PS8) usim_caller_groups[group_index- MAX_PB_CALLER_GROUPS].name) > 0)
        {
            mmi_ucs2cpy((S8*)group_name, (S8*)usim_caller_groups[group_index - MAX_PB_CALLER_GROUPS].name);
        }
        else
        {
            mmi_ucs2cpy((S8*)group_name, (S8*)GetString(STR_GLOBAL_EMPTY_LIST));
        }
    }
#endif /* __MMI_PHB_USIM_FIELD__ */ 
}
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
#endif /* _PHONEBOOKCALLERGROUP_C */ 

