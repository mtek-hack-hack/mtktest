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
 * BTMMIFtpScr.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI FTP service.
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
#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)

/*  Include: MMI header file */
#include "CommonScreens.h"      /* DisplayPopup */
#include "SettingProfile.h"     /* for tone ID */
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */
#include "wgui_status_icons.h"  /* for STATUS_ICON_IR */
#include "IdleAppDef.h" /* g_idle_context */
#include "IdleAppProt.h"        /* EntryIdleScreen() */
#include "ProfileGprots.h"      /* PlayRequestTone */
#include "gpioInc.h"    /* TurnOnBacklight */
#include "FileManagerGProt.h"   /* MMI_PUBLIC_DRV */
#include "Conversions.h"        /* char set conversion */
#include "CallManagementGprot.h"

/* Trace Header Files */

/* External Device Header Files */
/* File Type Categories (sync with file manager) */
#include "xml_def.h"
#include "FileMgr.h"
#include "BTMMIScrGprots.h"
#include "BTMMICm.h"
#include "Bluetooth_struct.h"
#include "BTMMIFtpGprots.h"
#include "BTMMIFtpScr.h"
#include "BTMMIFtp.h"
/* BT mmiresource def */
#include "ExtDeviceDefs.h"
#include "FileManagerDef.h"
#include "BTMMICustDef.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

/***************************************************************************** 
* CONTEXT
*****************************************************************************/
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
mmi_ftp_scr_cntx_struct g_mmi_bt_ftp_scr_cntx;
mmi_ftp_scr_cntx_struct *g_mmi_bt_ftp_scr_cntx_p = &g_mmi_bt_ftp_scr_cntx;
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __MMI_FTS_SUPPORT__
const U16 AccessRightStrList[] = 
{
    STR_FTP_OPTION_FULLY_CONTROL,
    STR_FTP_OPTION_READ_ONLY
};
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
U16 mmi_ftpc_notify_str[FTP_NOTY_STR_SIZE];
static U16 ftpc_fmgr_recv_str_buf[64];
#endif /* __MMI_FTC_SUPPORT__ */ 

/***************************************************************************** 
 * MACROS
 *****************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
#define MMI_FTPC_BUILD_EXIT_NOTY_STR()                                              \
{                                                                                   \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_FTP_CON_EXIT) );   \
}
#define MMI_FTPC_BUILD_ABORTING_NOTY_STR()                                          \
{                                                                                   \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_BT_CANCELLING) );\
}

#define MMI_FTPC_BUILD_CONNECTING_NOTY_STR()                                              \
{                                                                                         \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_GLOBAL_CONNECTING) );\
}
#define MMI_FTPC_BUILD_DISCONNECTING_NOTY_STR()                                              \
{                                                                                            \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_GLOBAL_DISCONNECTING) );\
}

#ifndef __MMI_FTC_MULTIPULL_SUPPORT__
#define MMI_FTPC_BUILD_NOTY_STR()                                                          \
{                                                                                          \
   U16 cnt[8];                                                                             \
                                                                                           \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_GLOBAL_RECEIVED) );\
   kal_wsprintf( (U16 *)cnt, " %d ", 1);                                                   \
   kal_wstrcat( (U16 *)mmi_ftpc_notify_str, (U16*) cnt);                                   \
   kal_wstrcat( (U16 *)mmi_ftpc_notify_str, (U16*) GetString(STR_FTP_NOTY_RECV_FILE_TIL)); \
}
#else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
#define MMI_FTPC_BUILD_NOTY_STR()                                                                                            \
{                                                                                                                            \
   U16 cnt[8];                                                                                                               \
   static U16 file_cnt;                                                                                                      \
                                                                                                                             \
   if(MMI_FTP_PULL_TYPE_SINGLE == g_mmi_bt_ftp_scr_cntx_p->pull_type)                                                        \
       file_cnt = 1;                                                                                                         \
                                                                                                                             \
   else if(MMI_FTP_PULL_TYPE_MULTI == g_mmi_bt_ftp_scr_cntx_p->pull_type)                                                    \
       file_cnt = g_mmi_bt_ftp_scr_cntx_p->download_list.list_obj_cnt;                                                       \
                                                                                                                             \
   else  if(MMI_FTP_PULL_TYPE_ALL== g_mmi_bt_ftp_scr_cntx_p->pull_type)                                                      \
       file_cnt = (act_client_cntx_p + ftpc_cntx_p->curr_idx )->file_cnt_cur_folder;                                         \
                                                                                                                             \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_GLOBAL_RECEIVED) );                                  \
   kal_wsprintf( (U16 *)cnt, " %d ", file_cnt);                                                                              \
   kal_wstrcat( (U16 *)mmi_ftpc_notify_str, (U16*) cnt);                                                                     \
   if(file_cnt == 1)                                                                                                                         \
       kal_wstrcat( (U16 *)mmi_ftpc_notify_str, (U16*) GetString(STR_FTP_NOTY_RECV_FILE_TIL_SINGLE));   \
   else if(file_cnt > 1)                                                                                                                   \
       kal_wstrcat( (U16 *)mmi_ftpc_notify_str, (U16*) GetString(STR_FTP_NOTY_RECV_FILE_TIL));    \
}
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#define FTPC_UDPADE_STR() {                                                                                                                                           \
            U16 fbrwr_ftpc_recv_per_str_buf[32];                                                                                                                      \
            if( (mmi_ucs2strlen( (S8*)  GetString(STR_GLOBAL_RECEIVED) )+1) > ((sizeof(ftpc_fmgr_recv_str_buf)/2) -(sizeof(fbrwr_ftpc_recv_per_str_buf)/2)) )\
                ASSERT(MMI_FALSE);                                                                                                                                    \
                                                                                                                                                                      \
            if((act_client_cntx_p + ftpc_cntx_p->curr_idx)->total_len_type == MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT)                                                        \
            {                                                                                                                                                         \
                mmi_ucs2cpy((S8*)ftpc_fmgr_recv_str_buf, GetString(STR_GLOBAL_RECEIVING) );                                                                  \
            }                                                                                                                                                         \
            else                                                                                                                                                      \
            {                                                                                                                                                         \
                mmi_ucs2cpy((S8*)ftpc_fmgr_recv_str_buf, GetString(STR_GLOBAL_RECEIVED) );                                                                \
                mmi_bt_ftpc_retrieve_get_prog_percentage(fbrwr_ftpc_recv_per_str_buf);                                                                                \
                mmi_ucs2cat((S8*)ftpc_fmgr_recv_str_buf, (S8*)fbrwr_ftpc_recv_per_str_buf);                                                                      \
            }                                                                                                                                                         \
}

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
static void mmi_bt_ftpc_retrieve_get_multi_percentage(U16 *recv_per_str_buf);

#define FTPC_MULTI_UDPADE_STR() {                                                                                                                                      \
            U16 fbrwr_ftpc_recv_per_str_buf[32];                                                                                                                       \
            if( (mmi_ucs2strlen( (S8*)  GetString(STR_GLOBAL_RECEIVED) )+1) > ((sizeof(ftpc_fmgr_recv_str_buf)/2) -(sizeof(fbrwr_ftpc_recv_per_str_buf)/2)) ) \
                ASSERT(MMI_FALSE);                                                                                                                                     \
            if (g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type == MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT)                        \
            {                                                                                                                                                          \
                mmi_ucs2cpy((S8*)ftpc_fmgr_recv_str_buf, GetString(STR_GLOBAL_RECEIVING) );                               \
                mmi_ucs2cat((PS8)ftpc_fmgr_recv_str_buf, (PS8) L"\n");                                                                                            \
            }                                                                                                                                                          \
            else                                                                                                                                                       \
            {                                                                                                                                                          \
                mmi_bt_ftpc_retrieve_get_prog_percentage(fbrwr_ftpc_recv_per_str_buf);                                 \
                mmi_bt_ftpc_retrieve_get_multi_percentage(fbrwr_ftpc_recv_per_str_buf);                                \
                mmi_ucs2cpy((S8*)ftpc_fmgr_recv_str_buf, (S8*)fbrwr_ftpc_recv_per_str_buf);                               \
            }                                                                                                                                                          \
}

#define MMI_FTPC_LIST_FILE_DEL_NOTY_STR()                                                        \
{                                                                                                     \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_FTP_LIST_FILE_DEL_CONFIRM) );   \
}

#define MMI_FTPC_LIST_ALL_FILE_DEL_NOTY_STR()                                                        \
{                                                                                                    \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_FTP_LIST_ALL_FILE_DEL_CONFIRM) );   \
}

#define MMI_FTPC_GET_ALL_CONFIRM_STR()                                                                                          \
{                                                                                                                               \
   U16 cnt[8];                                                                                                                  \
   kal_wstrcpy( (U16 *)mmi_ftpc_notify_str, (U16 *)GetString(STR_FTP_GET_ALL_CONFIRM_HEAD) );                                   \
   kal_wsprintf( (U16 *)cnt, "%d", (act_client_cntx_p + ftpc_cntx_p->curr_idx)->file_cnt_cur_folder);                         \
   kal_wstrcat( (U16 *)mmi_ftpc_notify_str, (U16*) cnt);                                                                        \
   kal_wstrcat( (U16 *)mmi_ftpc_notify_str, (U16*) GetString(STR_FTP_GET_ALL_CONFIRM_TAIL));                                    \
}

#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#endif /* __MMI_FTC_SUPPORT__ */ 

/***************************************************************************** 
 * External Functions
 *****************************************************************************/
extern PU8 mmi_fmgr_get_small_file_type_icon_image_ptr(FMGR_FILE_INFO_STRUCT *file_info);

/***************************************************************************** 
 * Internal Static Functions
 *****************************************************************************/
#ifdef __MMI_FTS_SUPPORT__
static void mmi_bt_ftps_accept_conn(void);
static void mmi_bt_ftps_reject_conn(void);
static void mmi_bt_ftps_access_right_LSK(void);
#endif /* __MMI_FTS_SUPPORT__ */
#ifdef __MMI_FTC_SUPPORT__
static U8 mmi_bt_ftpc_recving_screen_del_cb(void *p);
static U8 mmi_bt_ftpc_idle_notify_screen_del_cb(void *p);
static void mmi_bt_ftpc_file_browser_highlight_hdlr(S32 index);
static void mmi_bt_ftpc_file_browser_option_highlight_hdlr(S32 index);
static pBOOL mmi_bt_ftpc_browsing_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static int mmi_bt_ftpc_look_up_object_entity(S32 item_index);
static void mmi_bt_ftpc_entry_object_option(void);
static void mmi_bt_ftpc_entry_exit_confirm_scr(void);
static void mmi_bt_ftpc_notify_scr_browse(void);
static void mmi_bt_ftpc_update_prog_tohdlr(void);
static void mmi_bt_ftpc_abort(void);
static void mmi_bt_ftpc_notify_scr_browse_cb(void *filename, int isShort);
static void mmi_bt_ftpc_object_option_LSK(void);
static U8 mmi_bt_ftpc_file_browser_del_cb(void *p);
static void mmi_bt_ftpc_exit_file_browser(void);
static void mmi_bt_ftpc_exit_recv_obj(void);
static void mmi_bt_ftpc_store_endkey_hdlr(void);
static void mmi_bt_ftpc_clear_endkey_hdlr(void);
static void mmi_bt_ftpc_exe_endkey_hdlr(void);
static void mmi_bt_ftpc_end_key_press_handler(void);
static void mmi_bt_ftpc_entry_exit_confirm_scr_RSK(void);
static U8 mmi_bt_ftpc_connecting_screen_del_cb(void *p);
static U8 mmi_bt_ftpc_opening_folder_screen_del_cb(void *p);
static void mmi_bt_ftpc_connect_scr_RSK(void);

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
static void mmi_bt_ftpc_entry_download_list(void);
static void mmi_bt_ftpc_entry_list_option(void);
static void mmi_bt_ftpc_add_to_list(void);
static void mmi_bt_ftpc_get_list_files(void);
static void mmi_bt_ftpc_get_all_files(void);
static void mmi_bt_ftpc_list_option_up(void);
static void mmi_bt_ftpc_list_option_down(void);
static void mmi_bt_ftpc_list_option_delete(void);
static void mmi_bt_ftpc_list_option_del_all(void);
static MMI_BOOL mmi_bt_ftpc_check_list(void);
static void mmi_bt_ftpc_free_list(void);
static void mmi_bt_ftpc_download_list_highlight_hdlr(S32 index);
static void mmi_bt_ftpc_list_option_highlight_hdlr(S32 index);
static void mmi_bt_ftpc_list_option_LSK(void);
static MMI_BOOL mmi_bt_ftpc_find_next_file(void);
static void mmi_bt_ftpc_change_path_cfm(void);
static void mmi_bt_ftpc_change_path_cfm_LSK(void);
static U8 mmi_bt_ftpc_download_list_del_cb(void *p);

#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#endif /* __MMI_FTC_SUPPORT__ */ 

/*****************************************************************************
    MMI FTP SCR FUNCTIONS
*****************************************************************************/
#ifdef __MMI_FTS_SUPPORT__
#define FTPS_SETTING


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_menu_hdlr_init
 * DESCRIPTION
 *  This function is to initialize the mmi menu hilite hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_menu_hdlr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS MENU HDLR INIT\n");)
    SetHiliteHandler(MENU_CONN_FTP_SETTING, mmi_bt_ftps_setting_highlight_hdlr);
    SetHiliteHandler(MENU_CONN_FTP_ACCESS_RIGHT, mmi_bt_ftps_access_right_highlight_hdlr);
    SetHiliteHandler(MENU_CONN_FTP_SHARED_FOLDER, mmi_bt_ftps_shared_folder_highlight_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_setting_highlight_hdlr
 * DESCRIPTION
 *  This function is to entry FTP settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS SETTING HILITE HDLR\n");)
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_bt_ftps_entry_ftp_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftps_entry_ftp_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_entry_ftp_setting
 * DESCRIPTION
 *  This function is to display the FTP server setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_entry_ftp_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *HintList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ENTRY FTP SETTING MENU\n");)
    EntryNewScreen(SCR_FTP_SETTING, NULL, mmi_bt_ftps_entry_ftp_setting, NULL);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    guiBuffer = GetCurrGuiBuffer(SCR_FTP_SETTING);
    nNumofItem = GetNumOfChild(MENU_CONN_FTP_SETTING);
    GetSequenceStringIds(MENU_CONN_FTP_SETTING, nStrItemList);
    SetParentHandler(MENU_CONN_FTP_SETTING);
    SetHintHandler(MENU_CONN_FTP_SHARED_FOLDER, mmi_bt_ftps_shared_folder_hint);
    SetHintHandler(MENU_CONN_FTP_ACCESS_RIGHT, mmi_bt_ftps_access_right_hint);

    ConstructHintsList(MENU_CONN_FTP_SETTING, HintList);

    ShowCategory52Screen(
        STR_FTP_SETTING,
        GetRootTitleIcon(MENU_CONN_FTP_SETTING),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) HintList,
        0,
        0,
        guiBuffer);

    /* LSK/right arrow key is defined in highlight index */
    /* register RSK hanlders */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* register left arrow key handler */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define FTPS_SHARED_FOLDER


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_shared_folder_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index for
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_shared_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS SHARED FOLDER HILITE HDLR\n");)
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_bt_ftps_entry_shared_folder_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftps_entry_shared_folder_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_shared_folder_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_shared_folder_hint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS SHARED FOLDER HINT\n");)

    if (mmi_ucs2strlen((PS8) ftps_cntx_p->root_folder) <= 41)
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) ftps_cntx_p->root_folder);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) ftps_cntx_p->root_folder, 3);
        mmi_ucs2ncpy(
            (PS8) (hintData[index] + 6),
            (PS8) ftps_cntx_p->root_folder + (mmi_ucs2strlen((const S8*)ftps_cntx_p->root_folder) * 2) - (MAX_SUB_MENU_HINT_SIZE - 6 - ENCODING_LENGTH),
            (MAX_SUBMENU_CHARACTERS - 3 - 1));
        hintData[index][6] = 0x7E;
        hintData[index][7] = 0;
        hintData[index][MAX_SUB_MENU_HINT_SIZE - 2] = 0;
        hintData[index][MAX_SUB_MENU_HINT_SIZE - 1] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_entry_shared_folder_menu
 * DESCRIPTION
 *  This function is to enter selecting shared folder screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_entry_shared_folder_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ENTRY SHARED FOLDER MENU\n");)

    if(act_server_cntx_p->ftps_state >= MMI_FTPS_STATE_ACCEPTED)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_DISCONN_CLIENT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    else 
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

        mmi_fmgr_select_path_and_enter(
            APP_FTP,
            FMGR_SELECT_FOLDER,
            filter,
            (S8*) L"root",
            mmi_bt_ftps_fmgr_select_path_done);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_fmgr_select_path_done
 * DESCRIPTION
 *  Callback function for file manager when shared folder selection is finished.
 * PARAMETERS
 *  path            [IN]        User selected path
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_fmgr_select_path_done(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    int res;
    U32 written = 0;
    S8 tmp_path_buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS FMGR SELECT PATH DONE\n");)

    if (path == NULL)
    {
        DeleteUptoScrID(SCR_FTP_SETTING);
        GoBackHistory();
        return;
    }

    if(act_server_cntx_p->ftps_state >= MMI_FTPS_STATE_ACCEPTED)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_DISCONN_CLIENT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        DeleteUptoScrID(SCR_FTP_SETTING);
        return;
    }

    h = FS_Open((kal_uint16*) FTP_SHARED_FOLDER_PATH_FILE, (FS_READ_WRITE | FS_CREATE_ALWAYS));
    if (h < FS_NO_ERROR)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    else
    {
        mmi_ucs2cpy(tmp_path_buf, path);

        res = FS_Write(h, tmp_path_buf, (mmi_ucs2strlen(tmp_path_buf) * 2 + 2), &written);
        FS_Close(h);
        if ((res != FS_NO_ERROR) || ((mmi_ucs2strlen(tmp_path_buf) * 2 + 2) != written))
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
        else
        {
            /* set root folder and all connection's current folder */
            mmi_bt_ftps_set_shared_fodler(tmp_path_buf);
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
        }
    }
    DeleteUptoScrID(SCR_FTP_SETTING);
}

#define FTPS_ACCESS_RIGHT


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_access_right_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index for
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_access_right_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ACCESS RIGHT HILITE HDLR\n");)
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_bt_ftps_entry_access_right_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftps_entry_access_right_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_access_right_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_access_right_hint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ACCESS RIGHT HINT\n");)
    mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(AccessRightStrList[ftps_cntx_p->access_right]));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_entry_access_right_menu
 * DESCRIPTION
 *  This function is to display the FTP access right setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_entry_access_right_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ENTRY ACCESS RIGHT MENU\n");)

    EntryNewScreen(SCR_FTP_ACCESS_RIGHT_OPTION, NULL, mmi_bt_ftps_entry_access_right_menu, NULL);

    RegisterHighlightHandler(mmi_bt_ftps_accessright_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_FTP_ACCESS_RIGHT_OPTION);
    nNumofItem = GetNumOfChild(MENU_CONN_FTP_ACCESS_RIGHT);
    GetSequenceStringIds(MENU_CONN_FTP_ACCESS_RIGHT, nStrItemList);
    SetParentHandler(MENU_CONN_FTP_SETTING);

    ShowCategory11Screen(
        STR_FTP_ACCESS_RIGHT,
        GetRootTitleIcon(MENU_CONN_FTP_SETTING),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) ftps_cntx_p->access_right,
        guiBuffer);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bt_ftps_access_right_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left right arrow key handler */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_accessright_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index for access right
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_accessright_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ACCESSRIGHT HIGHLIGHT HDLR(get index)\n");)
    g_mmi_bt_ftp_scr_cntx_p->access_right_id = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_access_right_LSK
 * DESCRIPTION
 *  This function is to set the access right of the shared folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_access_right_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ACCESS RIGHT LSK\n");)
    switch (g_mmi_bt_ftp_scr_cntx_p->access_right_id)
    {
        case MMI_FTP_ACCESS_RIGHT_FULLY_CONTROL:
            FTP_DEBUG(kal_print("FTPS ACCESS RIGHT LSK -- FULLY CONTROL\n");)
            ftps_cntx_p->access_right = MMI_FTP_ACCESS_RIGHT_FULLY_CONTROL;
            break;
        case MMI_FTP_ACCESS_RIGHT_READ_ONLY:
            FTP_DEBUG(kal_print("FTPS ACCESS RIGHT LSK -- READ ONLY\n");
                );
            ftps_cntx_p->access_right = MMI_FTP_ACCESS_RIGHT_READ_ONLY;
            break;
        default:
            MMI_FTP_ASSERT(0);
    }
    WriteValue(NVRAM_FTP_ACCESS_RIGHT, &(ftps_cntx_p->access_right), DS_BYTE, &error);
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        MMI_FALSE,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteUptoScrID(SCR_FTP_SETTING);
}

#define FTPS_NOTIFY

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_entry_recv_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  U32(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_entry_recv_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dev_name_tmp[MMI_BT_SCR_BD_NAME_LEN];
    U8 cnf_str[130];    /* STR_FTP_CON_AUTH(48) + " "(2) + GOEP_MAX_DEV_NAME(80) = 130 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS BUILD NOTIFY STRING\n");)

    memset(dev_name_tmp, 0, MMI_BT_SCR_BD_NAME_LEN);

    /* common notify string */
    kal_wstrcpy((U16*) cnf_str, (U16*) GetString(STR_FTP_CON_AUTH));

    /* build dev_name string */
    mmi_bt_ftps_get_dev_name(dev_name_tmp);
    kal_wstrcat((U16*) cnf_str, (U16*) dev_name_tmp);

    kal_wstrcat((U16*) cnf_str, (U16*) GetString(STR_FTP_QUESTION_MARK));

    FTP_DEBUG(kal_print("FTPS ENTRY RECV CONFIRM SCREEN\n");)
    EntryNewScreen(SCR_FTP_NOTY_CONN_REQ, NULL, mmi_bt_ftps_entry_recv_confirm_scr, NULL);

    SetDelScrnIDCallbackHandler(SCR_FTP_NOTY_CONN_REQ, NULL);
    DeleteScreenIfPresent(SCR_FTP_NOTY_CONN_REQ);

    ShowCategory7Screen(
        STR_BT_MENU_TITLE,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (U8*) cnf_str,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_ftps_accept_conn, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_ftps_reject_conn, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_FTP_NOTY_CONN_REQ, mmi_bt_ftps_authorize_confirm_del_cb);
    TurnOnBacklight(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_accept_conn
 * DESCRIPTION
 *  This function is to accept rfcomm channel.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_accept_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS ACCEPT CONN\n");)

    SetDelScrnIDCallbackHandler(SCR_FTP_NOTY_CONN_REQ, (HistoryDelCBPtr) NULL);

    /* Send success connect response to OBEX task */
    mmi_bt_ftps_authorize_accept();
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_reject_conn
 * DESCRIPTION
 *  This function is to reject rfcomm channel.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_reject_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS REJECT CONN\n");)

    SetDelScrnIDCallbackHandler(SCR_FTP_NOTY_CONN_REQ, (HistoryDelCBPtr) NULL);
    GoBackHistory();

    /* Send success connect response to OBEX task */
    mmi_bt_ftps_authorize_reject();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_notify_disconnected
 * DESCRIPTION
 *  This function is to display disconected sceren when authorizing then
 *  delete ftp confirm screen
 * PARAMETERS
 *  void
 *  cause(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_notify_disconnected()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS NOTIFY RECV ERR\n");)

    if (mmi_bt_ftps_get_state(0) == MMI_FTPS_STATE_AUTHORIZING)
    {
        if (GetActiveScreenId() == SCR_FTP_NOTY_CONN_REQ)
            {
                GoBackHistory();
            }
            else
            {
                SetDelScrnIDCallbackHandler(SCR_FTP_NOTY_CONN_REQ, NULL);
                DeleteScreenIfPresent(SCR_FTP_NOTY_CONN_REQ);
            }
    }

}

#define FTPS_UTILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_popup
 * DESCRIPTION
 *  This function is to notify user that ftp client put one object to the server
 * PARAMETERS
 *  flag        [IN]        
 *  U8(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_popup(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS POPUP \n");)
    switch (flag)
    {
        case MMIFTP_MASK_WRITE_FILE_FAIL:
            string = (PU8) GetString(STR_FTP_WRITE_FILE_FAIL);
            break;
        case MMIFTP_MASK_DISK_FULL:
            string = (PU8) GetString(STR_FTP_RECV_DISK_FULL);
            break;
        case MMIFTP_MASK_ROOT_DIR_FULL:
            string = (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT);
            break;

        case MMIFTP_MASK_FS_DEVICE_BUSY:
            string = (PU8) GetString(GetFileSystemErrorString(MMIFTP_MASK_FS_DEVICE_BUSY));
            break;

        default:
            FTP_DEBUG(kal_print("FTPS POPUP ( flag error )\n");)
            MMI_FTP_ASSERT(0);
            return;
    }

    DisplayPopup(string, IMG_GLOBAL_ERROR, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_reset_clear_scrs
 * DESCRIPTION
 *  This function is to clear ftp screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_reset_clear_scrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DeleteScreenIfPresent(SCR_FTP_NOTY_CONN_REQ);

    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_FTP_NOTY_CONN_REQ:
            GoBackHistory();
        default:
            return;
    }

}
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
#define FTPC_ENTRY_FUNCTION


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_connect_scr
 * DESCRIPTION
 *  This function is to entry the connecting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_connect_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FTP_CONNECTING, NULL, mmi_bt_ftpc_entry_connect_scr, NULL);

    MMI_FTPC_BUILD_CONNECTING_NOTY_STR();
    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_GLOBAL_CONNECTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) mmi_ftpc_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_bt_ftpc_connect_scr_RSK, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECTING, mmi_bt_ftpc_connecting_screen_del_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_canceling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_canceling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY CANCEL SCREEN\n");)

    EntryNewScreen(SCR_FTP_CONNECT_CANCELING, NULL, mmi_bt_ftpc_entry_canceling, NULL);

    MMI_FTPC_BUILD_ABORTING_NOTY_STR();
    ShowCategory66Screen(STR_BT_CANCELLING, GetRootTitleIcon(MENU_CONN_BT_MAIN), 0, 0, 0, 0, (U8*) mmi_ftpc_notify_str, IMG_GLOBAL_PROGRESS, NULL);

    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECTING, NULL);
    DeleteScreenIfPresent(SCR_FTP_CONNECTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_file_browser
 * DESCRIPTION
 *  This function is to display the folder content of the remote phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_file_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY FILE BROWSER SCREEN\n");)

    EntryNewScreen(SCR_FTP_FILE_BROWSER, NULL, mmi_bt_ftpc_entry_file_browser, NULL);

    /* register highligh handler */
    RegisterHighlightHandler(mmi_bt_ftpc_file_browser_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_FTP_FILE_BROWSER);

    if (g_mmi_bt_ftp_scr_cntx_p->sel_opt_id == MMI_FTP_SCR_SELECT_OPT_DETAIL)
    {
        /* hilight the last item selected when re-enter file browser screen */
        highlighted_item = g_mmi_bt_ftp_scr_cntx_p->sel_obj_id;
    }
    else
    {
        highlighted_item = 0;
    }

    g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = 0;    /* Reset the option_id */
    ShowCategory184Screen(
        STR_FTP_FILE_BROWSER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),    /* title text and icon */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,                     /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                        /* RSK text and icon */
        act_client_cntx_p->entity_cnt_cur_folder,
        mmi_bt_ftpc_browsing_item,
        NULL,                                   /* No Hint inside first */
        highlighted_item,
        gui_buffer);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bt_ftpc_entry_object_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_entry_object_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* end key handler */
    mmi_bt_ftpc_store_endkey_hdlr();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    if (act_client_cntx_p->browse_depth > 0 && g_mmi_bt_ftp_scr_cntx_p->download_list.list_obj_cnt > 0)
    {
        SetRightSoftkeyFunction(mmi_bt_ftpc_change_path_cfm, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_ftpc_change_path_cfm, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetRightSoftkeyFunction(mmi_bt_ftpc_entry_back_to_parent_folder, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_ftpc_entry_back_to_parent_folder, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
#else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
    SetRightSoftkeyFunction(mmi_bt_ftpc_entry_back_to_parent_folder, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_entry_back_to_parent_folder, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
    
    SetDelScrnIDCallbackHandler(SCR_FTP_OPENING_FOLDER, NULL);
    DeleteScreenIfPresent(SCR_FTP_OPENING_FOLDER);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_BROWSER, NULL);
    DeleteScreenIfPresent(SCR_FTP_FILE_BROWSER);
    DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_BROWSER, mmi_bt_ftpc_file_browser_del_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_object_option
 * DESCRIPTION
 *  This function is to display the option menu of the selected file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_object_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY OBJECT OPTION SCREEN\n");)

    mmi_bt_ftpc_look_up_object_entity(g_mmi_bt_ftp_scr_cntx_p->sel_obj_id);

    if (act_client_cntx_p->entity_cnt_cur_folder != 0)
    {
        /* folder option screen */
        if (g_mmi_bt_ftp_scr_cntx_p->obj_entity.type == MMI_FTP_OBJ_TYPE_FOLDER)
        {
            FTP_DEBUG(kal_print("FTPC ENTRY OBJECT OPTION SCREEN (FOLDER)\n");)
            EntryNewScreen(SCR_FTP_FOLDER_OPTION, NULL, mmi_bt_ftpc_entry_object_option, NULL);
            guiBuffer = GetCurrGuiBuffer(SCR_FTP_FOLDER_OPTION);
            RegisterHighlightHandler(mmi_bt_ftpc_file_browser_option_highlight_hdlr);

            nNumofItem = GetNumOfChild(MENU_CONN_FTP_FOLDER_OPTION);
            GetSequenceStringIds(MENU_CONN_FTP_FOLDER_OPTION, nStrItemList);
        }
        /* file option screen */
        else
        {
            FTP_DEBUG(kal_print("FTPC ENTRY OBJECT OPTION SCREEN (FILE)\n");)
            EntryNewScreen(SCR_FTP_FILE_OPTION, NULL, mmi_bt_ftpc_entry_object_option, NULL);
            guiBuffer = GetCurrGuiBuffer(SCR_FTP_FILE_OPTION);
            RegisterHighlightHandler(mmi_bt_ftpc_file_browser_option_highlight_hdlr);

            nNumofItem = GetNumOfChild(MENU_CONN_FTP_FILE_OPTION);
            GetSequenceStringIds(MENU_CONN_FTP_FILE_OPTION, nStrItemList);
        }
    }
    /* empty folder option screen */
    else
    {
        FTP_DEBUG(kal_print("FTPC ENTRY OBJECT OPTION SCREEN (EMPTY FOLDER)\n");)
        EntryNewScreen(SCR_FTP_FOLDER_OPTION, NULL, mmi_bt_ftpc_entry_object_option, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_FTP_FOLDER_OPTION);
        RegisterHighlightHandler(mmi_bt_ftpc_file_browser_option_highlight_hdlr);

        nNumofItem = GetNumOfChild(MENU_CONN_FTP_EMPTY_FOLDER_OPTION);
        GetSequenceStringIds(MENU_CONN_FTP_EMPTY_FOLDER_OPTION, nStrItemList);
    }

    SetParentHandler(MENU_CONN_FTP_FILE_BROWSER);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_bt_ftpc_object_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bt_ftpc_object_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_disconnecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_disconnecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY DISCONNECTING SCREEN\n");)

    /* Call Exit Handler */
    EntryNewScreen(SCR_FTP_DISCONNECTING, NULL, mmi_bt_ftpc_entry_disconnecting, NULL);

    MMI_FTPC_BUILD_DISCONNECTING_NOTY_STR();

    ShowCategory66Screen(
        STR_GLOBAL_DISCONNECTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        (U8*) mmi_ftpc_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_opening_folder
 * DESCRIPTION
 *  this function is used to get file browser content
 *  No RSK: because previous scr's data is lost
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_opening_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_FTP_OPENING_FOLDER, NULL, mmi_bt_ftpc_entry_opening_folder, NULL);

    MMI_FTPC_BUILD_CONNECTING_NOTY_STR();

    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_GLOBAL_CONNECTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        (U8*) mmi_ftpc_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);
    SetDelScrnIDCallbackHandler(SCR_FTP_OPENING_FOLDER, mmi_bt_ftpc_opening_folder_screen_del_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_obj_detail
 * DESCRIPTION
 *  This function is to display the detailed info about the selected object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_obj_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY OBJECT DETAIL SCREEN\n");)

#ifndef __MMI_FTC_MULTIPULL_SUPPORT__
    mmi_bt_ftpc_look_up_object_entity(g_mmi_bt_ftp_scr_cntx_p->sel_obj_id);
#else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
    if (SCR_FTP_FOLDER_OPTION == GetActiveScreenId() || SCR_FTP_FILE_OPTION == GetActiveScreenId())
    {
        mmi_bt_ftpc_look_up_object_entity(g_mmi_bt_ftp_scr_cntx_p->sel_obj_id);
    }
    else if (SCR_FTP_LIST_OPTION == GetActiveScreenId())
    {
        mmi_bt_ftpc_look_up_object_entity(g_mmi_bt_ftp_scr_cntx_p->download_list.
                                          p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id]);
    }
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

    EntryNewScreen(SCR_FTP_DETAIL_INFO, NULL, mmi_bt_ftpc_entry_obj_detail, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FTP_DETAIL_INFO);

    info = (PU8) subMenuData;

    mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_FTP_DETAIL_DATE));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    mmi_ucs2cat((PS8) info, (PS8) g_mmi_bt_ftp_scr_cntx_p->obj_entity.created_date);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    if(g_mmi_bt_ftp_scr_cntx_p->obj_entity.type == MMI_FTP_OBJ_TYPE_FILE)
    {
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_FTP_DETAIL_SIZE));
        mmi_ucs2cat((PS8) info, (PS8) L"\n");
        mmi_ucs2cat((PS8) info, (PS8) g_mmi_bt_ftp_scr_cntx_p->obj_entity.size);
        mmi_ucs2cat((PS8) info, (PS8) L"\n");
    }
    

    ShowCategory74Screen(
        STR_GLOBAL_DETAILS,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_recv_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_recv_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY RECV OBJECT SCREEN\n");)

    /* Call Exit Handler */
    EntryNewScreen(SCR_FTP_RECEIVING, mmi_bt_ftpc_exit_recv_obj, mmi_bt_ftpc_entry_recv_obj, NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);    

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    FTPC_MULTI_UDPADE_STR();
#else 
    FTPC_UDPADE_STR();
#endif 

    /* Show Receiving screen */
    ShowCategory66Screen(
        STR_GLOBAL_RECEIVING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) ftpc_fmgr_recv_str_buf,
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_bt_ftpc_abort, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);
    SetDelScrnIDCallbackHandler(SCR_FTP_RECEIVING, mmi_bt_ftpc_recving_screen_del_cb);

    StartTimer(FMGR_PROG_UPDATE_TIMER, FTPC_PROG_UPD_DUR, mmi_bt_ftpc_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_aborting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY ABORTING SCREEN\n");)

    /* Call Exit Handler */
    EntryNewScreen(SCR_FTP_ABORTING, NULL, mmi_bt_ftpc_entry_aborting, NULL);

    MMI_FTPC_BUILD_ABORTING_NOTY_STR();

    ShowCategory66Screen(STR_BT_CANCELLING, GetRootTitleIcon(MENU_CONN_BT_MAIN), 0, 0, 0, 0, (U8*) mmi_ftpc_notify_str, IMG_GLOBAL_PROGRESS, NULL);
    DeleteScreenIfPresent(SCR_FTP_RECEIVING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_idle_notify_scr
 * DESCRIPTION
 *  This function is to display notify screen in idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY IDLE NOTIFY SCREEN\n");)

    MMI_FTPC_BUILD_NOTY_STR();

    EntryNewScreen(SCR_FTP_NOTY_FILE_RECV, NULL, mmi_bt_ftpc_entry_idle_notify_scr, NULL);

    ShowCategory154Screen(
        STR_FTP_FILE_BROWSER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_FTP_NOTY_RECV_FILE_BROWSE,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) mmi_ftpc_notify_str,
        NULL,
        IMG_GLOBAL_INFO,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_ftpc_notify_scr_browse, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_FTP_NOTY_FILE_RECV, mmi_bt_ftpc_idle_notify_screen_del_cb);

    DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
    DeleteScreenIfPresent(SCR_FTP_RECEIVING);
    DeleteScreenIfPresent(SCR_FTP_ABORTING);
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__    
    DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
    DeleteScreenIfPresent(SCR_FTP_DOWNLOAD_LIST);
    if (g_mmi_bt_ftp_scr_cntx_p->pull_type == MMI_FTP_PULL_TYPE_MULTI)
    {
        mmi_bt_ftpc_free_list();
    }
    mmi_bt_ftpc_reset_pull_variable();
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

}

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_download_list
 * DESCRIPTION
 *  This function is to display the files in download list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_entry_download_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 highlighted_item;
    U16 lsk_str = 0;
    U16 lsk_icon = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY DOWNLOAD LIST SCREEN\n");)

    if (g_mmi_bt_ftp_scr_cntx_p->download_list.list_obj_cnt == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            EMPTY_LIST_TONE);

        return;
    }

    EntryNewScreen(SCR_FTP_DOWNLOAD_LIST, NULL, mmi_bt_ftpc_entry_download_list, NULL);

    /* register highligh handler */
    RegisterHighlightHandler(mmi_bt_ftpc_download_list_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_FTP_DOWNLOAD_LIST);

    if (g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_DETAIL
        || g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_UP
        || g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_DOWN
        || g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_DELETE)
    {
        /* hilight the last item selected when re-enter file browser screen */
        highlighted_item = g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id;
        gui_buffer = NULL;
    }
    else
    {
        highlighted_item = 0;
    }

    g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id = 0;   /* Reset the option_id */
    if (g_mmi_bt_ftp_scr_cntx_p->sel_opt_id == MMI_FTP_SCR_SELECT_OPT_SHOW_LIST)
    {
        lsk_str = STR_GLOBAL_OPTIONS;
        lsk_icon = IMG_GLOBAL_OPTIONS;
    }
    else if (g_mmi_bt_ftp_scr_cntx_p->sel_opt_id == MMI_FTP_SCR_SELECT_OPT_GET_LIST_FILES)
    {
        lsk_str = STR_GLOBAL_OK;
        lsk_icon = IMG_GLOBAL_OK;
    }

    ShowCategory184Screen(
        STR_FTP_DOWNLOAD_LIST,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),    /* title text and icon */
        lsk_str,
        lsk_icon,                               /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                        /* RSK text and icon */
        g_mmi_bt_ftp_scr_cntx_p->download_list.list_obj_cnt,
        mmi_bt_ftpc_browsing_item,
        NULL,                                   /* No Hint inside first */
        highlighted_item,
        gui_buffer);

    if (g_mmi_bt_ftp_scr_cntx_p->sel_opt_id == MMI_FTP_SCR_SELECT_OPT_SHOW_LIST)
    {
        SetLeftSoftkeyFunction(mmi_bt_ftpc_entry_list_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_ftpc_entry_list_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (g_mmi_bt_ftp_scr_cntx_p->sel_opt_id == MMI_FTP_SCR_SELECT_OPT_GET_LIST_FILES)
    {
        SetLeftSoftkeyFunction(mmi_bt_ftpc_get_list_files, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_ftpc_get_list_files, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    /* register LSK, RSK hanlders */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left right arrow key handler */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);
    SetDelScrnIDCallbackHandler(SCR_FTP_DOWNLOAD_LIST, mmi_bt_ftpc_download_list_del_cb);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_list_option
 * DESCRIPTION
 *  This function is to display download list option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_entry_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY DOWNLOAD LIST OPTION SCREEN\n");)

    EntryNewScreen(SCR_FTP_LIST_OPTION, NULL, mmi_bt_ftpc_entry_list_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_FTP_LIST_OPTION);
    RegisterHighlightHandler(mmi_bt_ftpc_list_option_highlight_hdlr);

    nNumofItem = GetNumOfChild(MENU_CONN_FTP_LIST_OPTION);
    GetSequenceStringIds(MENU_CONN_FTP_LIST_OPTION, nStrItemList);

    /* SetParentHandler(MENU_CONN_FTP_LIST_OPTION); */
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_bt_ftpc_list_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bt_ftpc_list_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_end_key_press_handler, KEY_END, KEY_EVENT_DOWN);
    SetDelScrnIDCallbackHandler(SCR_FTP_LIST_OPTION, mmi_bt_ftpc_download_list_del_cb);
}

#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#define FTPC_POPUP


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_exit_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_exit_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ftpc_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY EXIT FTP CONFIRM SCREEN\n");)

    if (act_client_cntx_p->ftpc_state != MMI_FTPC_STATE_IDLE)
    {
        MMI_FTPC_BUILD_EXIT_NOTY_STR();

        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            mmi_ftpc_notify_str,
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        ftpc_state = mmi_bt_ftpc_get_state(0);

        if (g_mmi_bt_ftp_scr_cntx_p->is_endkey_pressed)
        {
            SetLeftSoftkeyFunction(mmi_bt_ftpc_exe_endkey_hdlr, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_bt_ftpc_exit_file_browser, KEY_EVENT_UP);
        }
        
        SetRightSoftkeyFunction(mmi_bt_ftpc_entry_exit_confirm_scr_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_ftpc_exe_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_parse_folder_fail
 * DESCRIPTION
 *  This function is to notify user that ftp client parse folder content failed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_parse_folder_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC PARSE FOLDER FAIL\n");)

    /* Play warning tone to notify file saved */
    DisplayPopup(
        (PU8) GetString(STR_FTP_NOTY_SHOW_PARTIAL_CONTENT_ONLY),
        IMG_GLOBAL_ERROR,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) WARNING_TONE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_notify_recv_err
 * DESCRIPTION
 *  This function is to display popup sceren when receiving error then
 *  delete all ftp screen except the file browser screen
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_notify_recv_err(mmi_ftpc_notify_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC NOTIFY RECV ERR\n");)

    if (cause == MMI_FTPC_NOTIFY_DISK_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_RECV_DISK_FULL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_ROOT_DIR_FULL)
    {
        DisplayPopup(
            (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_WRITE_FILE_FAIL)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_WRITE_FILE_FAIL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_CONNECTION_DISCONNECTED)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_CON_DISCONNECTED),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_BROWSE_FILES_FAILED)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTPC_NOTIFY_BROWSE_FILES_FAILED),
            IMG_GLOBAL_ERROR,
            0,
            FTPC_BROWSE_FILES_FAILED_DELAY_DUR,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_GOEP_STATUS_BUSY)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTPC_NOTIFY_GOEP_STATUS_BUSY),
            IMG_GLOBAL_ERROR,
            0,
            FTPC_BROWSE_FILES_FAILED_DELAY_DUR,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST)
    {
        /* Z:\@ftp\ not exist   and   E:\received not exist */
        DisplayPopup(
            (PU8) GetString(STR_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST),
            IMG_GLOBAL_ERROR,
            0,
            FTPC_BROWSE_FILES_FAILED_DELAY_DUR,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_FTPC_NOTIFY_FS_DEVICE_BUSY)
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(FS_DEVICE_BUSY)),
            IMG_GLOBAL_ERROR,
            0,
            FTPC_BROWSE_FILES_FAILED_DELAY_DUR,
            (U8) ERROR_TONE);
    }
    /* support device busy case for MT6601 */
    else if (cause == MMI_FTPC_NOTIFY_LAST)
    {
        goto CLEAR_SCRS;
    }
    else
    {
        U8 error_string[80];
        U8 file_prefix[10];

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        if (g_mmi_bt_ftp_scr_cntx_p->pull_type == MMI_FTP_PULL_TYPE_MULTI 
            || g_mmi_bt_ftp_scr_cntx_p->pull_type == MMI_FTP_PULL_TYPE_ALL)
         {
            kal_wsprintf(
                    (PU16)file_prefix,
                    "%d",
                    g_mmi_bt_ftp_scr_cntx.received_obj_cnt + 1);

            mmi_ucs2cpy((PS8) error_string, (PS8) GetString(STR_FTP_FILE_PREFIX));
            mmi_ucs2cat((PS8) error_string, (PS8) file_prefix);
            
            if (g_mmi_bt_ftp_scr_cntx.received_obj_cnt + 1 == 1)
            {
                mmi_ucs2cat((PS8) error_string, (PS8) GetString(STR_FTP_FILE_1ST));
            }
            else if (g_mmi_bt_ftp_scr_cntx.received_obj_cnt + 1 == 2)
            {
                mmi_ucs2cat((PS8) error_string, (PS8) GetString(STR_FTP_FILE_2ND));
            }
            else if (g_mmi_bt_ftp_scr_cntx.received_obj_cnt + 1 == 3)
            {
                mmi_ucs2cat((PS8) error_string, (PS8) GetString(STR_FTP_FILE_3RD));
            }
            else
            {
                mmi_ucs2cat((PS8) error_string, (PS8) GetString(STR_FTP_FILE_TH));
            }
            
            mmi_ucs2cat((PS8) error_string, (PS8) GetString(STR_FTP_FILE_UNFINISHED));
        }
        else
        {
            mmi_ucs2cpy((PS8) error_string, (PS8) GetString(STR_GLOBAL_UNFINISHED));
        }
#else /* __MMI_FTC_MULTIPULL_SUPPORT__ */
        mmi_ucs2cpy((PS8) error_string, (PS8) GetString(STR_GLOBAL_UNFINISHED));
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */

        DisplayPopup(
            (PU8) error_string,
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }

  CLEAR_SCRS:
    /* DeleteScreenIfPresent won't stop by registered delete callback function */
    SetDelScrnIDCallbackHandler(SCR_FTP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_ABORTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_DISCONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FOLDER_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_DETAIL_INFO, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECT_CANCELING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECTING, NULL);
    
    DeleteScreenIfPresent(SCR_FTP_RECEIVING);
    DeleteScreenIfPresent(SCR_FTP_ABORTING);
    DeleteScreenIfPresent(SCR_FTP_DISCONNECTING);
    DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
    DeleteScreenIfPresent(SCR_FTP_DETAIL_INFO);
    SetDelScrnIDCallbackHandler(SCR_FTP_OPENING_FOLDER, NULL);
    DeleteScreenIfPresent(SCR_FTP_OPENING_FOLDER);
    DeleteScreenIfPresent(SCR_FTP_CONNECT_CANCELING);
    DeleteScreenIfPresent(SCR_FTP_CONNECTING);
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
    DeleteScreenIfPresent(SCR_FTP_DOWNLOAD_LIST);
    mmi_bt_ftpc_reset_pull_variable();
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

}

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_list_opt_del_confirm_scr
 * DESCRIPTION
 *  This function is used to display a confrim when user delete all files or delete the last file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_list_opt_del_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY DELETE LAST LIST FILES CONFIRM SCREEN\n");)

    if (g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_DELETE)
    {
        MMI_FTPC_LIST_FILE_DEL_NOTY_STR();
    }
    else if (g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_DEL_ALL)
    {
        MMI_FTPC_LIST_ALL_FILE_DEL_NOTY_STR();
    }

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        mmi_ftpc_notify_str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    if (g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_DELETE)
    {
        SetLeftSoftkeyFunction(mmi_bt_ftpc_list_option_delete, KEY_EVENT_UP);
    }
    else if (g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id == MMI_FTP_MULTI_PULL_LIST_OPT_DEL_ALL)
    {
        SetLeftSoftkeyFunction(mmi_bt_ftpc_list_option_del_all, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_all_confirm_scr
 * DESCRIPTION
 *  Display a confirm when user select to get all files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_get_all_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY GET ALL FILES CONFIRM SCREEN\n");)

    MMI_FTPC_GET_ALL_CONFIRM_STR();

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        mmi_ftpc_notify_str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_bt_ftpc_get_all_files, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_exe_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_change_path_cfm
 * DESCRIPTION
 *  Display a confirm when user change the current path when the list have files.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_change_path_cfm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC CHANGE PATH CONFIRM SCREEN\n");)

    kal_wstrcpy((U16*) mmi_ftpc_notify_str, (U16*) GetString(STR_FTP_CLEAR_LIST));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        mmi_ftpc_notify_str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_bt_ftpc_change_path_cfm_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_ftpc_exe_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
}

#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#define FTPC_HILITE_HDLR


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_file_browser_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_file_browser_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC FILE BROWSER HILIGHT HDLR\n");)

    g_mmi_bt_ftp_scr_cntx_p->sel_obj_id = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_file_browser_option_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index for option menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_file_browser_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC FILE BROWSER OPTION HILIGHT HDLR\n");)

    if (act_client_cntx_p->entity_cnt_cur_folder != 0)
    {
    #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        /* mmi_bt_ftpc_look_up_object_entity(g_mmi_bt_ftp_scr_cntx_p->sel_obj_id); */
        if (MMI_FTP_OBJ_TYPE_FOLDER == g_mmi_bt_ftp_scr_cntx_p->obj_entity.type)
        {
            switch (index)
            {
                case 5:
                    g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = MMI_FTP_SCR_SELECT_OPT_SHOW_LIST;
                    break;

                case 6:
                    g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = MMI_FTP_SCR_SELECT_OPT_GET_LIST_FILES;
                    break;

                default:
                    g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = (U16) index;
            }
        }
        else
        {
            g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = (U16) index;
        }
    #else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
        g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = (U16) index;

    #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

    }
    /* empty folder */
    else
    {
        switch (index)
        {
            case 0:
                g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = MMI_FTP_SCR_SELECT_OPT_REFRESH;
                break;
            case 1:
                g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = MMI_FTP_SCR_SELECT_OPT_BACK_ROOT;
                break;
            case 2:
                g_mmi_bt_ftp_scr_cntx_p->sel_opt_id = MMI_FTP_SCR_SELECT_OPT_DISCONNECT;
                break;
            default:
                MMI_FTP_ASSERT(0);
        }
        return;
    }
}

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_download_list_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_download_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC DOWNLOAD LSIT SCREEN HILIGHT HDLR\n");)

    g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_list_option_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_list_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC DOWNLOAD LSIT OPTION SCREEN HILIGHT HDLR\n");)

    g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id = (U16) index;
}

#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#define FTPC_SCR_DEL_CB


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_recving_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_ftpc_recving_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC RECVING SCR DEL CB\n");)

    switch (mmi_bt_ftpc_get_state(0))
    {
        /*set folder*/
        case MMI_FTPC_STATE_GETTING_OBJ:
            /*getting folder, or parsing*/
            mmi_bt_ftpc_send_tpdisconnect(0);
            mmi_bt_ftpc_set_state(0, MMI_FTPC_STATE_TPDISCONNECTING);
            break;

        default:
            break;
    }

     return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_file_browser_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting file_browser screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_ftpc_file_browser_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ftpc_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC FILE BROWSER DEL CB\n");)

    ftpc_state = mmi_bt_ftpc_get_state(0);
    switch (ftpc_state)
    {
        case MMI_FTPC_STATE_CONNECTED:
            mmi_bt_ftpc_send_tpdisconnect(0);
            mmi_bt_ftpc_set_state(0, MMI_FTPC_STATE_TPDISCONNECTING);
            break;

        /*have sent tpdisconnect_req*/
        case MMI_FTPC_STATE_TPDISCONNECTING:
            break;
            

        default:
            break;

    }

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    mmi_bt_ftpc_free_list();
#endif
    

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_idle_notify_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_ftpc_idle_notify_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    stopRequestedTone(WARNING_TONE);
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_opening_folder_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting opening a folder screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_ftpc_opening_folder_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_bt_ftpc_get_state(0))
    {
        /*set folder*/
        case MMI_FTPC_STATE_SETTING_FOLDER:
        case MMI_FTPC_STATE_SETTING_BACK_FOLDER:
        case MMI_FTPC_STATE_SETTING_ROOT_FOLDER:

        case MMI_FTPC_STATE_PARSING_FOLDER:
        case MMI_FTPC_STATE_GETTING_FOLDER:            
            /*getting folder, or parsing*/
            mmi_bt_ftpc_send_tpdisconnect(0);
            mmi_bt_ftpc_set_state(0, MMI_FTPC_STATE_TPDISCONNECTING);
            break;

        default:
            break;
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_connecting_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_ftpc_connecting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ftpc_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC CONNECTING SCR DEL CB\n");)

    ftpc_state = mmi_bt_ftpc_get_state(0);

    if(ftpc_state == MMI_FTPC_STATE_CONNECTING
        ||ftpc_state == MMI_FTPC_STATE_GETTING_FOLDER
        ||ftpc_state == MMI_FTPC_STATE_PARSING_FOLDER)
    {
        mmi_bt_ftpc_connect_cancel();
    }

     return MMI_FALSE;

}

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_file_browser_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting download_list screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_bt_ftpc_download_list_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC  DOWNLOAD LIST DEL CB\n");)

    return MMI_FALSE;
}
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_connect_scr_RSK
 * DESCRIPTION
 *  RSK function of connecting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_connect_scr_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_ftpc_entry_canceling();
    mmi_bt_ftpc_connect_cancel();
}

#define FTPC_FRMWK_API


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_browser_history_replace
 * DESCRIPTION
 *  This function is to replace history for file browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_browser_history_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC HISTORY REPLACE TO FILE BROWSER\n");)

    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_BROWSER, NULL);
    DeleteScreenIfPresent(SCR_FTP_FILE_BROWSER);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_BROWSER, mmi_bt_ftpc_file_browser_del_cb);

    if (mmi_bt_ftpc_is_get_root(0))
    {
        
        HistoryReplace(SCR_FTP_OPENING_FOLDER, SCR_FTP_FILE_BROWSER, mmi_bt_ftpc_entry_file_browser);
    }
    else
    {
        HistoryReplace(SCR_FTP_CONNECTING, SCR_FTP_FILE_BROWSER, mmi_bt_ftpc_entry_file_browser);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_AddHistory
 * DESCRIPTION
 *  This function is to add aborting screen to History
 * PARAMETERS
 *  scr_id      [IN]        
 *  path_src        [?](?)
 *  filename        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_AddHistory(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_id == SCR_FTP_ABORTING)
    {
        h.scrnID = SCR_FTP_ABORTING;
        if (MMI_TRUE == mmi_bt_ftpc_is_aborting())
        {
            h.entryFuncPtr = mmi_bt_ftpc_entry_aborting;
        }
        else
        {
            /*the func is not used, if use need to confirm*/
            h.entryFuncPtr = mmi_bt_ftpc_entry_canceling;
        }
    }
    /* SCR_FTP_DISCONNECTING */
    else
    {
        h.scrnID = SCR_FTP_DISCONNECTING;
        h.entryFuncPtr = mmi_bt_ftpc_entry_disconnecting;
    }
    mmi_ucs2cpy((PS8) h.inputBuffer, (PS8) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}

#define FTPC_NOTIFY


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_notify_scr_browse
 * DESCRIPTION
 *  This function is to browse the received folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_notify_scr_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path_tmpbuf;
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY NOTIFY SCREEN BROWSE \n");)

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);

    path_tmpbuf = (S8*) OslMalloc(FMGR_PATH_BUFFER_SIZE);
    ASSERT(path_tmpbuf != NULL);

    FTPC_MAKE_RECV_PATH(path_tmpbuf);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported(path_tmpbuf))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            OslMfree(path_tmpbuf);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    mmi_fmgr_select_path_and_enter(
        APP_FTP,
        FMGR_SELECT_BROWSE,
        filter,
        path_tmpbuf,    /* (PS8)L"D:\\Received", */
        mmi_bt_ftpc_notify_scr_browse_cb);
    OslMfree(path_tmpbuf);
    DeleteScreenIfPresent(SCR_FTP_NOTY_FILE_RECV);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_notify_scr_browse_cb
 * DESCRIPTION
 *  This function is to browse received folder callback func
 * PARAMETERS
 *  filename        [?]         [?]
 *  isShort         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_notify_scr_browse_cb(void *filename, int isShort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY NOTIFY SCREEN BROWSE CALLBACK\n");)

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_obj_receive_ind
 * DESCRIPTION
 *  This function is to notify user that ftp received a unrecognized object
 * PARAMETERS
 *  void
 *  path_src        [?](?)
 *  filename        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_obj_receive_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC OBJECT RECEIVE IND\n");)

    mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);

    if (isInCall() && !IsWapCallPresent())
    {
        HistoryReplace(SCR_FTP_RECEIVING, SCR_FTP_NOTY_FILE_RECV, mmi_bt_ftpc_entry_idle_notify_scr);
    }
    else
    {
        mmi_bt_ftpc_entry_idle_notify_scr();
        playRequestedTone(WARNING_TONE);
        TurnOnBacklight(1);
    }

    act_client_cntx_p->total_recv_obj_len = 0;
    act_client_cntx_p->remain_recv_obj_len = 0;
    (act_client_cntx_p + ftpc_cntx_p->curr_idx)->recved_obj_len = 0;
    (act_client_cntx_p + ftpc_cntx_p->curr_idx)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;
}

#define FTPC_OPERATION_UTL


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_look_up_object_entity
 * DESCRIPTION
 *  This function is to read the object entity with the specified id
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_bt_ftpc_look_up_object_entity(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftp_obj_entity_struct *selecting_entity_p;
    FS_HANDLE fileHandle;
    int offset;
    unsigned int len;
    int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC LOOK UP OBJECT ENTITY\n");)

    selecting_entity_p = (mmi_ftp_obj_entity_struct*) & (g_mmi_bt_ftp_scr_cntx_p->obj_entity);

    fileHandle = FS_Open((U16*) act_client_cntx_p->parsed_folder, FS_READ_ONLY);

    if (fileHandle >= 0)
    {
        offset = item_index * (sizeof(mmi_ftp_obj_entity_struct));
        result = FS_Seek(fileHandle, offset, FS_FILE_BEGIN);
        if(result < FS_NO_ERROR)
        {
            FS_Close(fileHandle);
            return result;
        }

        result = FS_Read(fileHandle, (void*)selecting_entity_p, sizeof(mmi_ftp_obj_entity_struct), &len);
        if (result == FS_NO_ERROR)
        {
            FTP_DEBUG(kal_print("FTPC LOOK UP OBJECT ENTITY NO ERROR\n");)
            mmi_ucs2cpy((PS8) (g_mmi_bt_ftp_scr_cntx_p->obj_entity.name), (PS8) (selecting_entity_p->name));
        }
        else
        {
            FTP_DEBUG(kal_print("FTPC LOOK UP OBJECT ENTITY -- FS_READ ERROR\n");)
            FS_Close(fileHandle);
            return result;
        }
    }
    else
    {
        FTP_DEBUG(kal_print("FTPC LOOK UP OBJECT ENTITY -- FS_OPEN ERROR\n");)
        return fileHandle;
    }

    FS_Close(fileHandle);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_browsing_item
 * DESCRIPTION
 *  This function is to display the folder content of the remote phone
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_bt_ftpc_browsing_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* show frequency text */
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    if (GetActiveScreenId() == SCR_FTP_DOWNLOAD_LIST)
    {
        result = mmi_bt_ftpc_look_up_object_entity(g_mmi_bt_ftp_scr_cntx_p->download_list.
                                              p_obj_indexs_in_folder[item_index]);
    }
    else
    {
        result = mmi_bt_ftpc_look_up_object_entity(item_index);
    }
#else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
    result = mmi_bt_ftpc_look_up_object_entity(item_index);
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

    FTP_DEBUG(kal_print("FTPC BROWSING ITEM\n");
        );

    if (result == FS_NO_ERROR)
    {
        memset(&(file_info), 0, sizeof(FMGR_FILE_INFO_STRUCT));
        FTP_DEBUG(kal_print("FTPC BROWSING ITEM -- LOOK UP SUCCESS\n");)

        mmi_ucs2cpy((PS8) str_buff, (PS8) g_mmi_bt_ftp_scr_cntx_p->obj_entity.name);

        /* show folder icon */
        if (g_mmi_bt_ftp_scr_cntx_p->obj_entity.type == MMI_FTP_OBJ_TYPE_FOLDER)
        {
            file_info.attribute = FS_ATTR_DIR;
            *img_buff_p = (PU8) mmi_fmgr_get_small_file_type_icon_image_ptr(&file_info);
        }
        /* show obj icon */
        else
        {
            U32 type;
            FMGR_FILTER file_type;

            FMGR_FILTER_INIT(&file_type);
            type = mmi_fmgr_get_file_type_by_filename((PS8) g_mmi_bt_ftp_scr_cntx_p->obj_entity.name);
            FMGR_FILTER_SET(&file_type, type);

            file_info.attribute = file_info.attribute & (~FS_ATTR_DIR);
            file_info.file_type = file_type;
            *img_buff_p = (PU8) mmi_fmgr_get_small_file_type_icon_image_ptr(&file_info);
        }
        return MMI_TRUE;
    }
    else
    {
        FTP_DEBUG(kal_print("FTPC BROWSING ITEM -- LOOK UP FAILED\n");)
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_object_option_LSK
 * DESCRIPTION
 *  This function is to execute the selected action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_object_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK\n");)

    mmi_bt_ftpc_look_up_object_entity(g_mmi_bt_ftp_scr_cntx_p->sel_obj_id);

    switch (g_mmi_bt_ftp_scr_cntx_p->sel_opt_id)
    {
        case MMI_FTP_SCR_SELECT_OPT_OPEN_GET:
            if (g_mmi_bt_ftp_scr_cntx_p->obj_entity.type == MMI_FTP_OBJ_TYPE_FOLDER)
            {
            #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
                FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- FOLDER OPEN\n");)

                if (g_mmi_bt_ftp_scr_cntx_p->download_list.list_obj_cnt > 0)
                {
                    mmi_bt_ftpc_change_path_cfm();
                }
                else if (mmi_bt_ftpc_change_folder(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name) == MMI_TRUE)
                {
                    mmi_bt_ftpc_entry_opening_folder();
                }
            #else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
                if (mmi_bt_ftpc_change_folder(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name) == MMI_TRUE)
                {
                    FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- FOLDER OPEN\n");)
                    /* show connecting screen, waiting for set folder rsp then send get cur folder */
                    /* finally, the get folder rsp will trigger screen exchange to file browser screen */
                    mmi_bt_ftpc_entry_opening_folder();
                }
            #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
            }
            else
            {
                if (mmi_bt_ftpc_get_file_obj(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name) == MMI_TRUE)
                {
                    FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- FILE GET\n");)

                #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
                    g_mmi_bt_ftp_scr_cntx_p->pull_type = MMI_FTP_PULL_TYPE_SINGLE;
                #endif 
                    mmi_bt_ftpc_entry_recv_obj();
                }
            }
            break;
        case MMI_FTP_SCR_SELECT_OPT_REFRESH:
        #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
            if (g_mmi_bt_ftp_scr_cntx_p->download_list.list_obj_cnt > 0)
            {
                mmi_bt_ftpc_change_path_cfm();
            }
            else if (mmi_bt_ftpc_change_folder(NULL) == MMI_TRUE)
            {
                    mmi_bt_ftpc_entry_opening_folder();
            }
        #else
            if (mmi_bt_ftpc_change_folder(NULL) == MMI_TRUE)
            {
                FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- FOLDER REFRESH\n");)
                mmi_bt_ftpc_entry_opening_folder();
            }
        #endif
        
            break;
        case MMI_FTP_SCR_SELECT_OPT_DETAIL:
            FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- DETAIL\n");)
            mmi_bt_ftpc_entry_obj_detail();
            break;
        case MMI_FTP_SCR_SELECT_OPT_BACK_ROOT:
        #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
            FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- ROOT FOLDER\n");)

            if (g_mmi_bt_ftp_scr_cntx_p->download_list.list_obj_cnt > 0)
            {
                mmi_bt_ftpc_change_path_cfm();
            }
            else if (mmi_bt_ftpc_root_folder() == MMI_TRUE)
            {
                mmi_bt_ftpc_entry_opening_folder();
            }
        #else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
            if (mmi_bt_ftpc_root_folder() == MMI_TRUE)
            {
                FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- ROOT FOLDER\n");)
                mmi_bt_ftpc_entry_opening_folder();
            }
        #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
            break;
        case MMI_FTP_SCR_SELECT_OPT_DISCONNECT:
            FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- DISCONNECT\n");)
            mmi_bt_ftpc_entry_exit_confirm_scr();
            break;

        #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        case MMI_FTP_SCR_SELECT_OPT_ADD_TO_LIST:
            FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- ADD TO LIST\n");)
            mmi_bt_ftpc_add_to_list();
            break;

        case MMI_FTP_SCR_SELECT_OPT_SHOW_LIST:
            FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- SHOW DOWNLOAD LIST\n");)
            mmi_bt_ftpc_entry_download_list();
            break;

        case MMI_FTP_SCR_SELECT_OPT_GET_LIST_FILES:
            FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- GET LIST FILES\n");)
            mmi_bt_ftpc_entry_download_list();
            break;

        case MMI_FTP_SCR_SELECT_OPT_GET_ALL_FILES:
            FTP_DEBUG(kal_print("FTPC FILE OBJECT OPTION LSK -- GET ALL FILES\n");)
            mmi_bt_ftpc_get_all_confirm_scr();
            break;
        #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_back_to_parent_folder
 * DESCRIPTION
 *  This function is to display the folder content of the parent folder or disconnect when
 *  in the root folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_entry_back_to_parent_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY BACK TO PARENT FOLDER SCREEN\n");)

    /* Check if reached the root folder */
    if (act_client_cntx_p->browse_depth == 0)
    {
        mmi_bt_ftpc_entry_exit_confirm_scr();
    }
    else
    {
        if (mmi_bt_ftpc_back_folder() == MMI_TRUE)
        {
            mmi_bt_ftpc_entry_opening_folder();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_exit_file_browser
 * DESCRIPTION
 *  This function is to exit file browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_exit_file_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC EXIT FILE BROWSER CONFIRM SCREEN\n");)

    /* Disconnect the FTP connection */
    if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_CONNECTED)
    {
        /* send disconnect req */
        mmi_bt_ftpc_send_disconnect();
        MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_DISCONNECTING);
        mmi_bt_ftpc_entry_disconnecting();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_exit_recv_obj
 * DESCRIPTION
 *  This function is to exit recving obj screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_exit_recv_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC EXIT RECV OBJ SCREEN\n");)

    StopTimer(FMGR_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_update_prog_tohdlr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_update_prog_tohdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC UPDATE PROGRESS BAR TIMER HDLR\n");)

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    FTPC_MULTI_UDPADE_STR();
#else 
    FTPC_UDPADE_STR();
#endif 

    cat66_update_progress_string();
    StartTimer(FMGR_PROG_UPDATE_TIMER, FTPC_PROG_UPD_DUR, mmi_bt_ftpc_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_abort
 * DESCRIPTION
 *  This is common function to abort getting object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ABORT\n");)

    /*reset variables after send abort_req*/
    if(act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_GETTING_OBJ)
    {
        /* reset abort_req flag */
        mmi_bt_ftpc_reset_abort_req_sent_flag();
    
        MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_ABORTING);
        mmi_bt_ftpc_entry_aborting();
        
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_end_key_press_handler
 * DESCRIPTION
 *  File Browser end-key hdler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_end_key_press_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//add trace
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("End key is pressed.\n");)

    g_mmi_bt_ftp_scr_cntx_p->is_endkey_pressed = MMI_TRUE;

    mmi_bt_ftpc_entry_exit_confirm_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_entry_exit_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_entry_exit_confirm_scr_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//add trace
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("End key confirm screen select no.\n");)

    g_mmi_bt_ftp_scr_cntx_p->is_endkey_pressed = MMI_FALSE;

    GoBackHistory();
}


#ifdef __MMI_FTC_MULTIPULL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_add_to_list
 * DESCRIPTION
 *  Add a file to download list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_add_to_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC ENTRY TO ADD TO LIST \n");)

    if (mmi_bt_ftpc_check_list() == MMI_TRUE)
    {
        p_down_list->p_obj_indexs_in_folder[p_down_list->list_obj_cnt] = g_mmi_bt_ftp_scr_cntx.sel_obj_id;
        p_down_list->list_obj_cnt++;
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_list_files
 * DESCRIPTION
 *  Used to get the first file in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_get_list_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx_p->download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC GET LIST \n");)
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_GET_LIST);

    if (0 == p_down_list->list_obj_cnt)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_NO_FILE_IN_LIST),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }

    g_mmi_bt_ftp_scr_cntx_p->received_obj_cnt = 0;
    mmi_bt_ftpc_look_up_object_entity(p_down_list->p_obj_indexs_in_folder[0]);

    if (mmi_bt_ftpc_get_file_obj(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name) == MMI_TRUE)
    {
        g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;
        g_mmi_bt_ftp_scr_cntx_p->pull_type = MMI_FTP_PULL_TYPE_MULTI;
        mmi_bt_ftpc_entry_recv_obj();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_all_files
 * DESCRIPTION
 *  Used to get the first file when user select get all files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_get_all_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = ftpc_cntx_p->curr_idx;
    if ((act_client_cntx_p + idx)->file_cnt_cur_folder == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_NO_FILE_CURR_FOLDER),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }

    FTP_DEBUG(kal_print("FTPC GET ALL \n");)
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_GET_ALL);

    g_mmi_bt_ftp_scr_cntx_p->curent_file_id = 0;
    g_mmi_bt_ftp_scr_cntx_p->received_obj_cnt = 0;

    if (MMI_TRUE == mmi_bt_ftpc_find_next_file())
    {
        if (mmi_bt_ftpc_get_file_obj(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name) == MMI_TRUE)
        {
            g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;
            g_mmi_bt_ftp_scr_cntx_p->pull_type = MMI_FTP_PULL_TYPE_ALL;
            mmi_bt_ftpc_entry_recv_obj();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_find_next_file
 * DESCRIPTION
 *  used to find the next file if it exists when user select get all files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bt_ftpc_find_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_FIND_NEXT_FILE);

    idx = ftpc_cntx_p->curr_idx;

    for (i = g_mmi_bt_ftp_scr_cntx_p->curent_file_id; i < (act_client_cntx_p + idx)->entity_cnt_cur_folder; i++)
    {
        mmi_bt_ftpc_look_up_object_entity(i);

        if (MMI_FTP_OBJ_TYPE_FILE == g_mmi_bt_ftp_scr_cntx_p->obj_entity.type)
        {
            g_mmi_bt_ftp_scr_cntx_p->curent_file_id = i;
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_list_option_up
 * DESCRIPTION
 *  used to swap the sequence of hilited file with the previous file in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_list_option_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 old_id;
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx_p->download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_LIST_FIRST_FILE),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
        return;
    }

    old_id = p_down_list->p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id];
    p_down_list->p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id] =
        p_down_list->p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id - 1];
    p_down_list->p_obj_indexs_in_folder[--g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id] = old_id;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_list_option_down
 * DESCRIPTION
 *  used to swap the sequence of hilited file with the next file in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_list_option_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 old_id;
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx_p->download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id == p_down_list->list_obj_cnt - 1)
    {
        DisplayPopup(
            (PU8) GetString(STR_FTP_LIST_LAST_FILE),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
        return;
    }

    old_id = p_down_list->p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id];
    p_down_list->p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id] =
        p_down_list->p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id + 1];
    p_down_list->p_obj_indexs_in_folder[++g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id] = old_id;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_list_option_delete
 * DESCRIPTION
 *  used to delete the hilited file in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_list_option_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id + 1; i < p_down_list->list_obj_cnt; i++)
    {
        p_down_list->p_obj_indexs_in_folder[i - 1] = p_down_list->p_obj_indexs_in_folder[i];
    }

    DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    if (--p_down_list->list_obj_cnt == 0)
    {
        DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
        DeleteScreenIfPresent(SCR_FTP_DOWNLOAD_LIST);
        DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
        DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
        mmi_bt_ftpc_free_list();
    }
    else
    {
        if (g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id == p_down_list->list_obj_cnt)
            g_mmi_bt_ftp_scr_cntx_p->sel_list_obj_id--;

        DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_list_option_del_all
 * DESCRIPTION
 *  used to delete all the files in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_list_option_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_ftpc_free_list();

    DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
    DeleteScreenIfPresent(SCR_FTP_DOWNLOAD_LIST);
    DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
    DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_check_list
 * DESCRIPTION
 *  This is function to check the list when user add a file to list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bt_ftpc_check_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx.download_list;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_CHECK_LIST);

    /* now, if a list have no obj, the buffer will be freed, we have no empty list */
    /* if list not exist */
    if (p_down_list->p_obj_indexs_in_folder == NULL)
    {
        p_down_list->p_obj_indexs_in_folder = get_ctrl_buffer(MMI_BT_FTPC_MULPULL_LIST_INIT * sizeof(U16));
        ASSERT(p_down_list->p_obj_indexs_in_folder);

        memset(p_down_list->p_obj_indexs_in_folder, 0, MMI_BT_FTPC_MULPULL_LIST_INIT * sizeof(U16));
        p_down_list->list_capability = MMI_BT_FTPC_MULPULL_LIST_INIT;
        p_down_list->list_obj_cnt = 0;
        return MMI_TRUE;
    }

    /* search for duplicate */
    for (i = 0; i < p_down_list->list_obj_cnt; i++)
    {
        if (p_down_list->p_obj_indexs_in_folder[i] == g_mmi_bt_ftp_scr_cntx_p->sel_obj_id)
        {
            DisplayPopup(
                (PU8) GetString(STR_FTP_FILE_ALREADY_IN_LIST),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            return MMI_FALSE;
        }
    }

    /* if full list */
    if (p_down_list->list_capability == p_down_list->list_obj_cnt)
    {
        if ((p_down_list->list_capability + MMI_BT_FTPC_MULPULL_LIST_INC) <= MMI_BT_FTPC_MULPULL_LIST_MAX)
        {
            /* allocate new buffer and copy the data */
            U16 *p_new_list = get_ctrl_buffer((p_down_list->list_capability + MMI_BT_FTPC_MULPULL_LIST_INC) * sizeof(U16));
            ASSERT(p_new_list);

            /* memset(p_new_list, 0, (p_down_list->list_capability + MMI_BT_FTPC_MULPULL_LIST_INC) * sizeof(U16)); */
            memcpy(p_new_list, p_down_list->p_obj_indexs_in_folder, p_down_list->list_capability * sizeof(U16));

            /* free old buffer */
            free_ctrl_buffer(p_down_list->p_obj_indexs_in_folder);
            p_down_list->p_obj_indexs_in_folder = p_new_list;
            p_down_list->list_capability += MMI_BT_FTPC_MULPULL_LIST_INC;
            return MMI_TRUE;
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_FTP_LIST_ARRIVE_MAX),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_free_list
 * DESCRIPTION
 *  This is function to delete the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_free_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_FREE_LIST);

    if (p_down_list->p_obj_indexs_in_folder)
    {
        memset(p_down_list->p_obj_indexs_in_folder, 0xFFFF, p_down_list->list_capability * sizeof(U16));
        free_ctrl_buffer(p_down_list->p_obj_indexs_in_folder);
        p_down_list->p_obj_indexs_in_folder = NULL;
    }

    p_down_list->list_capability = 0;
    p_down_list->list_obj_cnt = 0;

    g_mmi_bt_ftp_scr_cntx.sel_list_obj_id = 0;
    g_mmi_bt_ftp_scr_cntx.sel_list_opt_id = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_list_option_LSK
 * DESCRIPTION
 *  LSK function of download list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_list_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC DOWNLOAD LIST OPTION LSK\n");)

    switch (g_mmi_bt_ftp_scr_cntx_p->sel_list_opt_id)
    {
        case MMI_FTP_MULTI_PULL_LIST_OPT_GET:
            FTP_DEBUG(kal_print("FTPC DOWNLOAD LIST OPTION LSK -- GET LIST FILES\n");)
            mmi_bt_ftpc_get_list_files();
            break;

        case MMI_FTP_MULTI_PULL_LIST_OPT_DETAIL:
            FTP_DEBUG(kal_print("FTPC DOWNLOAD LIST OPTION LSK -- DETAIL\n");)
            mmi_bt_ftpc_entry_obj_detail();
            break;

        case MMI_FTP_MULTI_PULL_LIST_OPT_UP:
            FTP_DEBUG(kal_print("FTPC DOWNLOAD LIST OPTION LSK -- UP\n");)
            mmi_bt_ftpc_list_option_up();
            break;

        case MMI_FTP_MULTI_PULL_LIST_OPT_DOWN:
            FTP_DEBUG(kal_print("FTPC DOWNLOAD LIST OPTION LSK -- DOWN\n");)
            mmi_bt_ftpc_list_option_down();
            break;

        case MMI_FTP_MULTI_PULL_LIST_OPT_DELETE:
        case MMI_FTP_MULTI_PULL_LIST_OPT_DEL_ALL:
            mmi_bt_ftpc_list_opt_del_confirm_scr();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_change_path_cfm_LSK
 * DESCRIPTION
 *  LSK function of change path confirm when user change current path when list have files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_change_path_cfm_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 history_top_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC CHANGE PATH CONFIRM SCREEN LSK\n");)

    history_top_scr = GetCurrScrnId();

    mmi_bt_ftpc_free_list();
    switch (history_top_scr)
    {
        /*back to parent, confirm, LSK*/
        case SCR_FTP_FILE_BROWSER:
            mmi_bt_ftpc_entry_back_to_parent_folder();
            break;

        case SCR_FTP_FILE_OPTION:
        case SCR_FTP_FOLDER_OPTION:
            if (MMI_FTP_SCR_SELECT_OPT_OPEN_GET == g_mmi_bt_ftp_scr_cntx_p->sel_opt_id)
            {
                if (mmi_bt_ftpc_change_folder(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name) == MMI_TRUE)
                {
                    mmi_bt_ftpc_entry_opening_folder();
                }
            }
            else if (MMI_FTP_SCR_SELECT_OPT_BACK_ROOT == g_mmi_bt_ftp_scr_cntx_p->sel_opt_id)
            {
                if (mmi_bt_ftpc_root_folder() == MMI_TRUE)
                {
                    mmi_bt_ftpc_entry_opening_folder();
                }

            }
            else if (MMI_FTP_SCR_SELECT_OPT_REFRESH == g_mmi_bt_ftp_scr_cntx_p->sel_opt_id)
            {
                if (mmi_bt_ftpc_change_folder(NULL) == MMI_TRUE)
                {
                    mmi_bt_ftpc_entry_opening_folder();
                }
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_next_file
 * DESCRIPTION
 *  when a file downloaded success, will call it to handle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_get_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_GET_NEXT_FILE);
    switch (g_mmi_bt_ftp_scr_cntx_p->pull_type)
    {
        case MMI_FTP_PULL_TYPE_ALL:
        {
            g_mmi_bt_ftp_scr_cntx.received_obj_cnt++;
            g_mmi_bt_ftp_scr_cntx.curent_file_id++;

            /* down next file */
            if (g_mmi_bt_ftp_scr_cntx.received_obj_cnt <
                (act_client_cntx_p + ftpc_cntx_p->curr_idx)->file_cnt_cur_folder)
            {
                if (MMI_TRUE == mmi_bt_ftpc_find_next_file())
                {
                    if (MMI_TRUE == mmi_bt_ftpc_get_file_obj(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name))
                        (act_client_cntx_p + ftpc_cntx_p->curr_idx)->recved_obj_len = 0;
                    (act_client_cntx_p + ftpc_cntx_p->curr_idx)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;
                    FTP_DEBUG(kal_print("FTPC OBJ RECEIVED, START THE NEXT--ALL NEW FILE GET\n");)
                    return;
                }
                else
                {
                    ASSERT(0);
                }
            }
            /* all files down completed */
            else
            {
                mmi_bt_ftpc_obj_receive_ind();
            }
        }
            break;

        case MMI_FTP_PULL_TYPE_MULTI:
        {
            mmi_ftpc_download_list *p_down_list = &g_mmi_bt_ftp_scr_cntx.download_list;

            g_mmi_bt_ftp_scr_cntx.received_obj_cnt++;
            /* down next list file */
            if (g_mmi_bt_ftp_scr_cntx.received_obj_cnt < p_down_list->list_obj_cnt)
            {
                mmi_bt_ftpc_look_up_object_entity(p_down_list->
                                                  p_obj_indexs_in_folder[g_mmi_bt_ftp_scr_cntx.received_obj_cnt]);
                if (mmi_bt_ftpc_get_file_obj(g_mmi_bt_ftp_scr_cntx_p->obj_entity.name) == MMI_TRUE)
                {
                    (act_client_cntx_p + ftpc_cntx_p->curr_idx)->recved_obj_len = 0;
                    (act_client_cntx_p + ftpc_cntx_p->curr_idx)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;
                    FTP_DEBUG(kal_print("FTPC OBJ RECEIVED, START THE NEXT--MULTI NEW FILE GET\n");)
                }
            }
            /* all list files have downloaded */
            else
            {
                mmi_bt_ftpc_obj_receive_ind();
            }
        }
            break;

        case MMI_FTP_PULL_TYPE_SINGLE:
            mmi_bt_ftpc_obj_receive_ind();
            break;
    }
}

#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#define FTPC_SCREEN_UTL


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_disconnect_clear_scrs
 * DESCRIPTION
 *  This function is to clear ftp screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_disconnect_clear_scrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC CLEAR SCREENS WHEN DISCONNECTED\n");)

    SetDelScrnIDCallbackHandler(SCR_FTP_DISCONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_BROWSER, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_ABORTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FOLDER_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_DETAIL_INFO, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_OPENING_FOLDER, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECT_CANCELING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECTING, NULL);

    DeleteScreenIfPresent(SCR_FTP_DISCONNECTING);
    DeleteScreenIfPresent(SCR_FTP_FILE_BROWSER);
    DeleteScreenIfPresent(SCR_FTP_RECEIVING);
    DeleteScreenIfPresent(SCR_FTP_ABORTING);
    DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
    DeleteScreenIfPresent(SCR_FTP_DETAIL_INFO);
    DeleteScreenIfPresent(SCR_FTP_OPENING_FOLDER);
    DeleteScreenIfPresent(SCR_FTP_CONNECT_CANCELING);
    DeleteScreenIfPresent(SCR_FTP_CONNECTING);

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
    DeleteScreenIfPresent(SCR_FTP_DOWNLOAD_LIST);
    mmi_bt_ftpc_free_list();
    mmi_bt_ftpc_reset_pull_variable();
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_FTP_DISCONNECTING:
        case SCR_FTP_FILE_BROWSER:
        case SCR_FTP_RECEIVING:
        case SCR_FTP_ABORTING:
        case SCR_FTP_FOLDER_OPTION:
        case SCR_FTP_FILE_OPTION:
        case SCR_FTP_DETAIL_INFO:
        case SCR_FTP_OPENING_FOLDER:
        case SCR_FTP_CONNECT_CANCELING:
        case SCR_FTP_CONNECTING:
    #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        case SCR_FTP_LIST_OPTION:
        case SCR_FTP_DOWNLOAD_LIST:
    #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
            GoBackHistory();
        default:
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_reset_clear_scrs
 * DESCRIPTION
 *  This function is to clear ftp screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_reset_clear_scrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC CLEAR SCREENS WHEN RESET\n");)

    MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_IDLE);

    DeleteScreenIfPresent(SCR_FTP_DISCONNECTING);
    DeleteScreenIfPresent(SCR_FTP_FILE_BROWSER);
    DeleteScreenIfPresent(SCR_FTP_RECEIVING);
    DeleteScreenIfPresent(SCR_FTP_ABORTING);
    DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
    DeleteScreenIfPresent(SCR_FTP_DETAIL_INFO);
    DeleteScreenIfPresent(SCR_FTP_OPENING_FOLDER);
    DeleteScreenIfPresent(SCR_FTP_CONNECT_CANCELING);    
    DeleteScreenIfPresent(SCR_FTP_CONNECTING);    

    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_FTP_NOTY_FILE_RECV:
        case SCR_FTP_DISCONNECTING:
        case SCR_FTP_FILE_BROWSER:
        case SCR_FTP_RECEIVING:
        case SCR_FTP_ABORTING:
        case SCR_FTP_FOLDER_OPTION:
        case SCR_FTP_FILE_OPTION:
        case SCR_FTP_DETAIL_INFO:
        case SCR_FTP_OPENING_FOLDER:
        case SCR_FTP_CONNECT_CANCELING:
        case SCR_FTP_CONNECTING:
            GoBackHistory();
        default:
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_goback2history
 * DESCRIPTION
 *  This function is to goback2history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_goback2history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC GOBACK2HISTORY\n");)

    SetDelScrnIDCallbackHandler(SCR_FTP_DISCONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_BROWSER, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_ABORTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FOLDER_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_FILE_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_DETAIL_INFO, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_OPENING_FOLDER, NULL);
    SetDelScrnIDCallbackHandler(SCR_FTP_CONNECT_CANCELING, NULL);

    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_FTP_DISCONNECTING:
        case SCR_FTP_FILE_BROWSER:
        case SCR_FTP_RECEIVING:
        case SCR_FTP_ABORTING:
        case SCR_FTP_FOLDER_OPTION:
        case SCR_FTP_FILE_OPTION:
        case SCR_FTP_DETAIL_INFO:
        case SCR_FTP_CONNECTING:
        case SCR_FTP_OPENING_FOLDER:
        case SCR_FTP_CONNECT_CANCELING:
            GoBacknHistory(1);
            break;
        default:
            DeleteScreenIfPresent(SCR_FTP_RECEIVING);
            DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
            DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
            DeleteScreenIfPresent(SCR_FTP_DETAIL_INFO);
            DeleteScreenIfPresent(SCR_FTP_CONNECTING);
            DeleteScreenIfPresent(SCR_FTP_OPENING_FOLDER);
            DeleteScreenIfPresent(SCR_FTP_CONNECT_CANCELING);
            
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_clear_abort_scr
 * DESCRIPTION
 *  This function is to clear aborting screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_clear_abort_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_FTP_ABORTING:
    #ifndef __MMI_FTC_MULTIPULL_SUPPORT__
            DeleteScreenIfPresent(SCR_FTP_RECEIVING);
            DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
            DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
    #else
            if (g_mmi_bt_ftp_scr_cntx_p->pull_type == MMI_FTP_PULL_TYPE_SINGLE)
            {
                DeleteScreenIfPresent(SCR_FTP_RECEIVING);
                DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
                DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
            }
            else if (g_mmi_bt_ftp_scr_cntx_p->pull_type == MMI_FTP_PULL_TYPE_MULTI)
            {
                DeleteScreenIfPresent(SCR_FTP_RECEIVING);
                DeleteScreenIfPresent(SCR_FTP_ABORTING);
                DeleteScreenIfPresent(SCR_FTP_DISCONNECTING);
                DeleteScreenIfPresent(SCR_FTP_LIST_OPTION);
                mmi_bt_ftpc_reset_pull_variable();
            }
            else if (g_mmi_bt_ftp_scr_cntx_p->pull_type == MMI_FTP_PULL_TYPE_ALL)
            {
                DeleteScreenIfPresent(SCR_FTP_RECEIVING);
                DeleteScreenIfPresent(SCR_FTP_ABORTING);
                DeleteScreenIfPresent(SCR_FTP_DISCONNECTING);
                DeleteScreenIfPresent(SCR_FTP_DOWNLOAD_LIST);
                DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
                DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
                mmi_bt_ftpc_reset_pull_variable();
            }
    #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
            GoBackHistory();
            return;

            /* pop up screen */
        default:
            DeleteScreenIfPresent(SCR_FTP_ABORTING);
            DeleteScreenIfPresent(SCR_FTP_RECEIVING);
            DeleteScreenIfPresent(SCR_FTP_FOLDER_OPTION);
            DeleteScreenIfPresent(SCR_FTP_FILE_OPTION);
            DeleteScreenIfPresent(SCR_FTP_DETAIL_INFO);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_store_endkey_hdlr
 * DESCRIPTION
 *  This function is to store the default end key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_store_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* first enter file browser*/
    if ((g_mmi_bt_ftp_scr_cntx_p->keyup_fp == NULL) && (g_mmi_bt_ftp_scr_cntx_p->keydown_fp == NULL))
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_STORE_ENDKEY);
        g_mmi_bt_ftp_scr_cntx_p->keyup_fp = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
        g_mmi_bt_ftp_scr_cntx_p->keydown_fp = GetKeyHandler(KEY_END, KEY_EVENT_UP);

        g_mmi_bt_ftp_scr_cntx_p->is_endkey_pressed = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_clear_endkey_hdlr
 * DESCRIPTION
 *  This function is to store the default end key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_clear_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_CLEAR_ENDKEY);

    g_mmi_bt_ftp_scr_cntx_p->keyup_fp = NULL;
    g_mmi_bt_ftp_scr_cntx_p->keydown_fp = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_exe_endkey_hdlr
 * DESCRIPTION
 *  This function is to execute the default end key handler and reset it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_exe_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_EXE_ENDKEY);

    if (g_mmi_bt_ftp_scr_cntx_p->keyup_fp)
    {
       (g_mmi_bt_ftp_scr_cntx_p->keyup_fp) ();
    }

    if (g_mmi_bt_ftp_scr_cntx_p->keydown_fp)
    {
       (g_mmi_bt_ftp_scr_cntx_p->keydown_fp) ();
    }

    mmi_bt_ftpc_clear_endkey_hdlr();
}

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_retrieve_get_multi_percentage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  recv_per_str_buf        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_retrieve_get_multi_percentage(U16 *recv_per_str_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_str_buf[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bt_ftp_scr_cntx_p->pull_type)
    {
        case MMI_FTP_PULL_TYPE_MULTI:
            if (1 >= g_mmi_bt_ftp_scr_cntx.download_list.list_obj_cnt)
                return;
            kal_wsprintf(
                temp_str_buf,
                " %d%c%d",
                g_mmi_bt_ftp_scr_cntx.received_obj_cnt + 1,
                '/',
                g_mmi_bt_ftp_scr_cntx.download_list.list_obj_cnt);
            mmi_ucs2cat((S8*) recv_per_str_buf, (S8*) temp_str_buf);
            break;

        case MMI_FTP_PULL_TYPE_ALL:
            if (1 >= (act_client_cntx_p + ftpc_cntx_p->curr_idx)->file_cnt_cur_folder)
                return;
            kal_wsprintf(
                temp_str_buf,
                " %d%c%d",
                g_mmi_bt_ftp_scr_cntx.received_obj_cnt + 1,
                '/',
                (act_client_cntx_p + ftpc_cntx_p->curr_idx)->file_cnt_cur_folder);
            mmi_ucs2cat((S8*) recv_per_str_buf, (S8*) temp_str_buf);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_reset_pull_variable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_reset_pull_variable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_FTPC_RESET_PULL_VAR);

    switch (g_mmi_bt_ftp_scr_cntx_p->pull_type)
    {
        case MMI_FTP_PULL_TYPE_MULTI:
            /*mmi_bt_ftpc_free_list();*/
            g_mmi_bt_ftp_scr_cntx.received_obj_cnt = 0;
            break;

        case MMI_FTP_PULL_TYPE_ALL:
            g_mmi_bt_ftp_scr_cntx.received_obj_cnt = 0;
            g_mmi_bt_ftp_scr_cntx.curent_file_id = 0;
            break;

        case MMI_FTP_PULL_TYPE_NONE:
        case MMI_FTP_PULL_TYPE_SINGLE:
            break;

        default:
            ASSERT(0);
            break;
    }
    g_mmi_bt_ftp_scr_cntx.pull_type = MMI_FTP_PULL_TYPE_NONE;
    g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;
}
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#define FTPC_OPEN_TO_LOGIC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_is_first_file
 * DESCRIPTION
 *  MMI_TRUE: the first file in multi get
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_ftpc_is_first_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTC_MULTIPULL_SUPPORT__
    return MMI_TRUE;
#else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

    switch (g_mmi_bt_ftp_scr_cntx_p->pull_type)
    {
        case MMI_FTP_PULL_TYPE_SINGLE:
        return MMI_TRUE;

        case MMI_FTP_PULL_TYPE_MULTI:
        case MMI_FTP_PULL_TYPE_ALL:
        if (0 == g_mmi_bt_ftp_scr_cntx_p->received_obj_cnt)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }

        default:
            /*Error state*/
            return MMI_FALSE;
    }
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
}
#endif /* __MMI_FTC_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_add_history_before_cm_marker
 * DESCRIPTION
 *  Add a screen to the history before CM_SCR_MARKER
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT , MMI_BT_FTP_FTPC_ADD_HISTORY_BEFORE_CM);
    Scr.scrnID = scrn_id;
    Scr.entryFuncPtr = func_ptr;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) L"");

    InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
}

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 

