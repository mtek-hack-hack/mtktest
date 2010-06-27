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

/*******************************************************************************
 * Filename:
 * ---------
 *  DeviceManagement.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Device Management.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/************************************************************************
* Includes
************************************************************************/
#include "MMI_include.h"

#if defined(__FOTA_ENABLE__)

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "MainMenuDef.h"
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif /*__MMI_FOTA_OTAP_DMP__*/
#include "DeviceManagementInc.h"
#include "DeviceManagementResDef.h"

#include "DataAccountGprot.h"
#include "DataAccountResDef.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"


#include "Fota_error.h"

#if defined(__MMI_FWU_VIA_TFTP__)
#include "tftp_enum.h"
#include "tftp_const.h"
#include "Tftp2app_struct.h"
#endif /* defined(__MMI_FWU_VIA_TFTP__) */

#if defined(__MMI_FWU_VIA_HTTP__)
#include "Wap_ps_struct.h"
#include "Wapadp.h"
#endif /* defined(__MMI_FWU_VIA_HTTP__) */

#if defined(__MMI_FWU_VIA_FILE__)
#include "fmt_struct.h"
#include "fmt_def.h"
#include "FileManagerGProt.h"
#include "filemgr.h"
#endif /* __MMI_FWU_VIA_FILE__*/

#include "CallManagementGprot.h"
#include "USBDeviceGprot.h"
#include "gpioInc.h"

/************************************************************************
* Internal Variables
************************************************************************/
/* DM FWU context */
dm_fwu_context_struct g_dm_fwu_context;

#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif

#if defined(__MMI_FWU_VIA_TFTP__)
app_tftp_recv_rsp_struct  g_tftp_recv_ind_info={0};            /* to keep rece_ind info */
#endif /* defined(__MMI_FWU_VIA_TFTP__) */

#if defined(__MMI_FWU_VIA_HTTP__)
wap_get_prof_content_rsp_struct wap_profile_info;   /* to keep profile info */
#endif /* defined(__MMI_FWU_VIA_HTTP__) */

/************************************************************************
* Extern Functions
************************************************************************/
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_FOTA_OTAP_DMP__*/


/************************************************************************
* Code Body
************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_init
 * DESCRIPTION
 *  init DM highlight handlers & protocol event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*********************************/
    /****** Set HiLite Handler *******/
    /*********************************/        
    SetHiliteHandler(SERVICES_FWU_MENU_ID, mmi_dm_fwu_highlight_hdlr);
    
#if defined(__MMI_FWU_VIA_TFTP__)    
    SetHiliteHandler(FWU_TFTP_MENU_ID, mmi_dm_fwu_tftp_highlight_hdlr);
    SetHiliteHandler(FWU_TFTP_UPGRADE_MENU_ID, mmi_dm_fwu_tftp_upgrade_highlight_hdlr);
    SetHiliteHandler(FWU_TFTP_SETTING_MENU_ID, mmi_dm_fwu_tftp_settings_highlight_hdlr);
#endif /* defined(__MMI_FWU_VIA_TFTP__) */

#if defined(__MMI_FWU_VIA_HTTP__)
    SetHiliteHandler(FWU_HTTP_MENU_ID, mmi_dm_fwu_http_highlight_hdlr);
    SetHiliteHandler(FWU_HTTP_UPGRADE_MENU_ID, mmi_dm_fwu_http_upgrade_highlight_hdlr);
    SetHiliteHandler(FWU_HTTP_SETTING_MENU_ID, mmi_dm_fwu_http_settings_highlight_hdlr);
#endif /* defined(__MMI_FWU_VIA_HTTP__) */

#if defined(__MMI_FWU_VIA_FILE__)
    SetHiliteHandler(FWU_FILE_MENU_ID, mmi_dm_fwu_file_highlight_hdlr);
#endif /* __MMI_FWU_VIA_FILE__*/

    /******************************/
    /* Set Protocol Event Handler */
    /******************************/    
    SetProtocolEventHandler(mmi_dm_fwu_fmt_fota_init_rsp, MSG_ID_MMI_FMT_FOTA_INIT_RSP);
    SetProtocolEventHandler(mmi_dm_fwu_fmt_fota_write_data_rsp, MSG_ID_MMI_FMT_FOTA_WRITE_DATA_RSP);
    SetProtocolEventHandler(mmi_dm_fwu_fmt_fota_finalize_rsp, MSG_ID_MMI_FMT_FOTA_FINALIZE_RSP);    

    mmi_dm_fwu_init_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_init_context
 * DESCRIPTION
 *  init DM FWU context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_dm_fwu_context.buffer)
    {
        free_ctrl_buffer(g_dm_fwu_context.buffer);
    }
    
    /* init global context/variable */
    memset(&g_dm_fwu_context, 0, sizeof(dm_fwu_context_struct));
    g_dm_fwu_context.buffer = NULL;
    
#if defined(__MMI_FWU_VIA_TFTP__)   
    memset(&g_tftp_recv_ind_info, 0, sizeof(g_tftp_recv_ind_info));    
    g_dm_fwu_context.history_buffer = NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_highlight_hdlr
 * DESCRIPTION
 *  Firmware Upgrade Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_entry_firmware_update, KEY_EVENT_UP);
    SetKeyHandler(mmi_dm_entry_firmware_update, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_entry_firmware_update
 * DESCRIPTION
 *  Firmware Update screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_entry_firmware_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10]; 
    U8 *gui_buffer;       
    U16 item_num;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if firmware upgrading */
    if ((g_dm_fwu_context.state != DM_STATE_INIT) && (g_dm_fwu_context.state != DM_STATE_DOWNLOAD_FINISH_PENDING))
    {
        DisplayPopup((PU8)GetString(STR_ID_DM_DOWNLOADING_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);        
        return;
    }

    EntryNewScreen(SCR_ID_DM_FWU, NULL, mmi_dm_entry_firmware_update, NULL);

    /* Get current screen to gui buffer  for history purposes */
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DM_FWU);

    /* Retrieve no of child of menu item to be displayed */
    item_num = GetNumOfChild(SERVICES_FWU_MENU_ID);

    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(SERVICES_FWU_MENU_ID, nStrItemList);

    /* Set current parent id */
    SetParentHandler(SERVICES_FWU_MENU_ID);

    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetDelScrnIDCallbackHandler(SCR_ID_DM_FWU, (HistoryDelCBPtr) mmi_dm_fwu_main_del_callback);

    /* Display Category52 Screen */
    ShowCategory52Screen(
        STR_ID_DM_FWU,
        GetRootTitleIcon(SERVICES_FWU_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_num,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_main_del_callback
 * DESCRIPTION
 *  Callback function when main menu is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dm_fwu_main_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FWU_VIA_HTTP__)
    if (g_dm_fwu_context.state == DM_STATE_HTTP_AUTH)
    {
        g_dm_fwu_context.state = DM_STATE_ABORT;
        
        memset(g_dm_fwu_context.auth_username, 0, sizeof(g_dm_fwu_context.auth_username));
        memset(g_dm_fwu_context.auth_password, 0, sizeof(g_dm_fwu_context.auth_password));

        mmi_dm_fwu_http_send_http_auth_res();
        SetProtocolEventHandler(NULL, MSG_ID_WPS_HTTP_RSP);
        mmi_dm_fwu_http_unset_channel_req();   
        SetProtocolEventHandler(NULL, MSG_ID_WPS_UNSET_CHANNEL_RSP);
    }
#endif

    mmi_dm_fwu_init_context();
    
    return FALSE;
}


#if defined(__MMI_FWU_VIA_TFTP__)    
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_highlight_hdlr
 * DESCRIPTION
 *  [From TFTP] TFTP Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set upgrade media: TFTP */
    g_dm_fwu_context.upgrade_media = DM_UPGRADE_TFTP;
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_tftp, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_dm_fwu_entry_tftp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_upgrade_highlight_hdlr
 * DESCRIPTION
 *  [From TFTP] TFTP Upgrade Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_upgrade_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set upgrade media: TFTP */    
    g_dm_fwu_context.upgrade_media = DM_UPGRADE_TFTP;
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_download_confirm, KEY_EVENT_UP);  

    SetKeyHandler(mmi_dm_fwu_entry_download_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_settings_highlight_hdlr
 * DESCRIPTION
 *  [From TFTP] TFTP Settings Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set upgrade media: TFTP */    
    g_dm_fwu_context.upgrade_media = DM_UPGRADE_TFTP;
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_pre_tftp_settings, KEY_EVENT_UP);

    SetKeyHandler(mmi_dm_fwu_entry_pre_tftp_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_tftp
 * DESCRIPTION
 *  [From TFTP] From TFTP screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_tftp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10]; 
    U8 *gui_buffer;       
    U16 item_num;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DM_TFTP, NULL, mmi_dm_fwu_entry_tftp, NULL);

    /* Get current screen to gui buffer  for history purposes */
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DM_TFTP);
    
    /* Retrieve no of child of menu item to be displayed */
    item_num = GetNumOfChild(FWU_TFTP_MENU_ID);
    
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(FWU_TFTP_MENU_ID, nStrItemList);
    
    /* Set current parent id */
    SetParentHandler(FWU_TFTP_MENU_ID);
    
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Display Category52 Screen */
    ShowCategory52Screen(
        STR_ID_DM_FWU_TFTP,
        GetRootTitleIcon(FWU_TFTP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_num,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_pre_tftp_settings
 * DESCRIPTION
 *  [From TFTP] Check for Data Account ready before entering TFTP settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_pre_tftp_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for data account ready first so that we can get data account name */
    DataAccountReadyCheck(mmi_dm_fwu_entry_tftp_settings);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_tftp_settings
 * DESCRIPTION
 *  [From TFTP] Settings screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_tftp_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;  /* Buffer holding history data */
    U8 *input_buffer;
    U16 input_buffer_size;
    U16 icon_list[DM_TFTP_IDX_END];
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* CheckIsBackHistory should be called before EntryNewScreen */
    if (!CheckIsBackHistory())
    {
        /* get settings for the 1st entry */
        mmi_dm_fwu_get_settings(DM_UPGRADE_TFTP);
    }

    EntryNewScreen(SCR_ID_DM_TFTP_SETTINGS, mmi_dm_fwu_exit_tftp_settings, NULL, NULL);
   
    InitializeCategory57Screen();

    /* Get current screen to gui buffer for history purposes */
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DM_TFTP_SETTINGS);

    /* Get input buffer for inline edit history */
    input_buffer = GetCurrNInputBuffer(SCR_ID_DM_TFTP_SETTINGS, &input_buffer_size);

    /* get icon list */
    for (i=0; i<DM_TFTP_IDX_END; i+=2)
    {
        icon_list[i] = gIndexIconsImageList[i>>1];
        icon_list[i+1] = 0;
    }
    
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(mmi_dm_fwu_tftp_settings_submenu_highlight_hdlr);
    
    /* Set current parent id */
    SetParentHandler(FWU_TFTP_MENU_ID);

    /* construct all inline items */
    mmi_dm_fwu_construct_inline_item(DM_UPGRADE_TFTP);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, DM_TFTP_IDX_END, input_buffer);
    }

    /* set done-flag to change RSK to Done if necessary */
    if (g_dm_fwu_context.is_da_changed == MMI_TRUE && 
        (GetInlineDoneFlag(gui_buffer) == 0))
    {
        SetInlineDoneFlag(gui_buffer);
    }

    /* Display Category57 Screen */
    ShowCategory57Screen(
        STR_ID_DM_SETTINGS,
        GetRootTitleIcon(SERVICES_FWU_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        DM_TFTP_IDX_END,
        icon_list,
        wgui_inline_items,
        0,
        gui_buffer);

    SetCategory57RightSoftkeyFunctions(mmi_dm_fwu_entry_confirm_setting, GoBackHistory);    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_settings_submenu_highlight_hdlr
 * DESCRIPTION
 *  [From TFTP] Highlight handler for TFTP Settings submenu 
 * PARAMETERS
 *  index       [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_settings_submenu_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == DM_TFTP_IDX_DA)
    {
        /* when highlight Data Account, LSK will be changed for selecting a DA */
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_dm_fwu_entry_tftp_DA, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_allocate_history_data_dummy
 * DESCRIPTION
 *  [From TFTP] function for allocate history data
 * PARAMETERS
 *  param1    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void* mmi_dm_fwu_allocate_history_data_dummy(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Since the size of TFTP settings is too large, 
       Current history size is at most: 1K. So allocate a buffer for self-usage.
       1500 is a rough size. it is evaluated on MoDIS environment */
    g_dm_fwu_context.history_buffer = (U8*)get_ctrl_buffer(1500);
    
    return (void*)g_dm_fwu_context.history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_free_history_data_dummy
 * DESCRIPTION
 *  [From TFTP] function for free history data
 * PARAMETERS
 *  param1    [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_fwu_free_history_data_dummy(void* param1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_dm_fwu_context.history_buffer)
    {
        free_ctrl_buffer(g_dm_fwu_context.history_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_exit_tftp_settings
 * DESCRIPTION
 *  [From TFTP] Settings screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_exit_tftp_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* application should provide allocate & free function of self-usage buffer */
    AddHistoryEx(
        SCR_ID_DM_TFTP_SETTINGS,
        mmi_dm_fwu_entry_tftp_settings,
        GetCategoryHistory,
        GetCategory57DataSize,
        GetCategory57Data,
        mmi_dm_fwu_allocate_history_data_dummy,
        mmi_dm_fwu_free_history_data_dummy);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_save_tftp_settings
 * DESCRIPTION
 *  [From TFTP] Save the settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_save_tftp_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset da changed flag to FALSE */
    g_dm_fwu_context.is_da_changed = MMI_FALSE;
    
    stopRequestedTone(WARNING_TONE);

    /* Save setttings to NVRAM */
    mmi_dm_fwu_set_settings(DM_UPGRADE_TFTP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_DA_cb
 * DESCRIPTION
 *  [From TFTP] Callback function for TFTP Data Account
 * PARAMETERS
 *  index       [IN]        selected data account
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_DA_cb(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Keep the data account index */
    g_dm_fwu_context.tftp_da_index = (U8)index;

    /* reset da changed flag to TRUE */
    g_dm_fwu_context.is_da_changed = MMI_TRUE;
    
    /* get data account name by the index. */
    mmi_dtcnt_get_account_name((U8)index, (S8*)g_dm_fwu_context.tftp_da_name, (U8)sizeof(g_dm_fwu_context.tftp_da_name)/ENCODING_LENGTH); 

    DeleteUptoScrID(SCR_ID_DM_TFTP_SETTINGS);
    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_tftp_DA
 * DESCRIPTION
 *  [From TFTP] Enter Data Account
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_tftp_DA(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(mmi_dm_fwu_tftp_DA_cb, FWU_TFTP_SETTING_MENU_ID, DATA_ACCOUNT_BEARER_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_start_tftp_req
 * DESCRIPTION
 *  [From TFTP] start tftp request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_start_tftp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_tftp_run_req_struct *msgReq;
    U8 textbuf[(DM_TFTP_MAX_FILENAME_LEN + 1)];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set protocol event handler of tftp start confirm , receive ind, result ind */
    SetProtocolEventHandler(mmi_dm_fwu_tftp_start_tftp_cnf, MSG_ID_APP_TFTP_RUN_CNF);    
    SetProtocolEventHandler(mmi_dm_fwu_tftp_receive_ind, MSG_ID_APP_TFTP_RECV_IND);
    SetProtocolEventHandler(mmi_dm_fwu_tftp_result_ind, MSG_ID_APP_TFTP_RESULT_IND);
    
    /* to allocate a control buffer */
    g_dm_fwu_context.buffer = (U8*)get_ctrl_buffer(DM_TFTP_BUFFER_SIZE);
    
    msgReq = (app_tftp_run_req_struct*) OslConstructDataPtr(sizeof(app_tftp_run_req_struct));
   
    msgReq->account_id      =  (U8)(g_dm_fwu_context.tftp_da_index);    /* data account index */
    msgReq->host_mode       =  (tftp_host_enum)TFTP_CLIENT;             /* as TFTP client */
    msgReq->opcode          =  (tftp_op_enum)TFTP_READ;                 /* read/get file */
    msgReq->mode            =  (tftp_mode_enum)TFTP_OCTET;
    msgReq->media_type      =  (tftp_media_enum)TFTP_BUFF;              /* media : buffer base */
    msgReq->buffer          =  g_dm_fwu_context.buffer;                 /* buffer pointer */
    msgReq->buf_size        =  DM_TFTP_BUFFER_SIZE;                     /* buffer size */

    memset(msgReq->local_filename, 0, sizeof(msgReq->local_filename));  /* unused */ 
    memset(textbuf, 0, sizeof(textbuf));        
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_dm_fwu_context.tftp_port);    
    msgReq->fport           =  (U16)(atoi((S8*)textbuf));               /* tftp port */
    
    memset(textbuf, 0, sizeof(textbuf));    
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_dm_fwu_context.tftp_server_name);     /* server name */
    memcpy(msgReq->remote_addr, textbuf, strlen((PS8)textbuf) + 1);

    memset(textbuf, 0, sizeof(textbuf));    
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_dm_fwu_context.full_filename_buffer); /* remote file name */
    memcpy(msgReq->remote_filename, textbuf, strlen((PS8)textbuf)+1);
    
    msgReq->opt_blksize     =  0;  /* 0 means default (512bytes), otherwise 1024 bytes) */
    msgReq->opt_timeout     =  0;
    msgReq->opt_tsize       =  1;  /* 1: query total size */

    mmi_dm_fwu_send_msg(MOD_TFTP, MSG_ID_APP_TFTP_RUN_REQ, (void*)msgReq, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_start_tftp_cnf
 * DESCRIPTION
 *  [From TFTP] start tftp confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_start_tftp_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_tftp_run_cnf_struct *rsp_p = inMsg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == TFTP_SUCCESS)
    {
        /* set state: downloading */
        g_dm_fwu_context.state = DM_STATE_DOWNLOADING;

        /* keep the job id */
        g_dm_fwu_context.job_id = rsp_p->job_id;
    }
    else
    {
        /* fails */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] tftp start: %d", rsp_p->result);
        
        g_dm_fwu_context.general_result_code = (U8)mmi_dm_fwu_convert_result_code((U8)rsp_p->result);
        mmi_dm_fwu_entry_download_result();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_stop_tftp_req
 * DESCRIPTION
 *  [From TFTP] stop tftp request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_stop_tftp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_tftp_close_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.state != DM_STATE_DOWNLOAD_FINISH)
    {
        /* set protocol event handler of tftp stop confirm */
        SetProtocolEventHandler(mmi_dm_fwu_tftp_stop_tftp_cnf, MSG_ID_APP_TFTP_CLOSE_CNF);    
    
        msgReq = (app_tftp_close_req_struct*) OslConstructDataPtr(sizeof(app_tftp_close_req_struct));

        msgReq->job_id = (U8)(g_dm_fwu_context.job_id);

        mmi_dm_fwu_send_msg(MOD_TFTP, MSG_ID_APP_TFTP_CLOSE_REQ, (void*)msgReq, (void*)NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_stop_tftp_cnf
 * DESCRIPTION
 *  [From TFTP] stop tftp confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_stop_tftp_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_dm_fwu_context.state)
    {
        case DM_STATE_DOWNLOAD_FINISH:
        {
            /* EOF , finish reading */
            mmi_dm_fwu_fmt_fota_finalize_req(); 
            break;
        }
        case DM_STATE_ERROR:
        {
            g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_SOC_ERROR;
            mmi_dm_fwu_entry_download_result();
            break;
        }
        case DM_STATE_FOTA_AUTH_ERROR:
        {
            g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_AUTHENTICATION_FAIL;
            mmi_dm_fwu_entry_download_result();
            break;
        }
        case DM_STATE_FOTA_CHECKSUM_FAIL:
        {
            g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_FINAL_CHECK_FAIL;
            mmi_dm_fwu_entry_download_result();
            break;
        }
        default:
        {
            g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_ABORT;
            mmi_dm_fwu_entry_download_result();
            break;
        }
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_receive_ind
 * DESCRIPTION
 *  [From TFTP] received tftp indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_receive_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_tftp_recv_ind_struct *rsp_p = inMsg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* keep the cumulate size */
    g_dm_fwu_context.cumul_size = rsp_p->cumul_size;

    if (rsp_p->cumul_size == 0 && rsp_p->blk_num == 0)
    {
        /* it means servr support total size query. then keep the total size */
        g_dm_fwu_context.total_size = rsp_p->tsize;

        /* set percentage to 0: default value */
        g_dm_fwu_context.percentage = 0;
        
        /* change the category to percentage bar */
        mmi_dm_fwu_entry_download_animation();
        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);        
    }
    else
    {
        g_tftp_recv_ind_info.job_id          =  rsp_p->job_id;
        g_tftp_recv_ind_info.media_type      =  rsp_p->media_type;
        g_tftp_recv_ind_info.blk_num         =  rsp_p->blk_num;
        g_tftp_recv_ind_info.rcvd_buf_size   =  rsp_p->rcvd_buf_size;
        g_tftp_recv_ind_info.cumul_size      =  rsp_p->cumul_size;
        g_tftp_recv_ind_info.buffer          =  rsp_p->buffer;
    
        /* send msg to FMT (FOTA) to write buffer */
        mmi_dm_fwu_fmt_fota_write_data_req(rsp_p->rcvd_buf_size);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_send_receive_rsp
 * DESCRIPTION
 *  [From TFTP] received tftp response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_send_receive_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_tftp_recv_rsp_struct  *g_msgReq;                 /* to keep rece_ind info */

    g_msgReq = (app_tftp_recv_rsp_struct*) OslConstructDataPtr(sizeof(app_tftp_recv_rsp_struct));
        
    g_msgReq->job_id          =  g_tftp_recv_ind_info.job_id;
    g_msgReq->media_type      =  g_tftp_recv_ind_info.media_type;
    g_msgReq->blk_num         =  g_tftp_recv_ind_info.blk_num;
    g_msgReq->rcvd_buf_size   =  g_tftp_recv_ind_info.rcvd_buf_size;
    g_msgReq->cumul_size      =  g_tftp_recv_ind_info.cumul_size;
    g_msgReq->buffer          =  g_tftp_recv_ind_info.buffer;

    mmi_dm_fwu_send_msg(MOD_TFTP, MSG_ID_APP_TFTP_RECV_RSP, (void*)g_msgReq, (void*)NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_result_ind
 * DESCRIPTION
 *  [From TFTP] result tftp confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_tftp_result_ind_struct *rsp_p = inMsg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set state: finish */
    if (rsp_p->result == TFTP_SUCCESS)
    {
        mmi_dm_fwu_tftp_stop_tftp_req();

        g_dm_fwu_context.state = DM_STATE_DOWNLOAD_FINISH;
    }
    else
    {
        /* fails */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] tftp result: %d", rsp_p->result);
        g_dm_fwu_context.state = DM_STATE_ERROR;
        g_dm_fwu_context.general_result_code = (U8)mmi_dm_fwu_convert_result_code((U8)rsp_p->result);
        mmi_dm_fwu_entry_download_result();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_tftp_abort_tftp_req
 * DESCRIPTION
 *  [From TFTP] abort tftp request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_tftp_abort_tftp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_dm_fwu_context.state != DM_STATE_DOWNLOAD_FINISH)
    {
        g_dm_fwu_context.state = DM_STATE_ABORT;
        mmi_dm_fwu_tftp_stop_tftp_req();
    }
}

#ifdef __MMI_FOTA_OTAP_DMP__
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
#endif /*__MMI_FOTA_OTAP_DMP__*/

#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */


#if defined(__MMI_FWU_VIA_HTTP__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_highlight_hdlr
 * DESCRIPTION
 *  [From HTTP] HTTP Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set upgrade media: HTTP */    
    g_dm_fwu_context.upgrade_media = DM_UPGRADE_HTTP;
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_http, KEY_EVENT_UP);    

    SetKeyHandler(mmi_dm_fwu_entry_http, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_upgrade_highlight_hdlr
 * DESCRIPTION
 *  [From HTTP] HTTP Upgrade Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_upgrade_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set upgrade media: HTTP */        
    g_dm_fwu_context.upgrade_media = DM_UPGRADE_HTTP;
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_download_confirm, KEY_EVENT_UP);

    SetKeyHandler(mmi_dm_fwu_entry_download_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_settings_highlight_hdlr
 * DESCRIPTION
 *  [From HTTP] HTTP Settings Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set upgrade media: HTTP */        
    g_dm_fwu_context.upgrade_media = DM_UPGRADE_HTTP;
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_pre_http_settings, KEY_EVENT_UP);        

    SetKeyHandler(mmi_dm_fwu_entry_pre_http_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_http
 * DESCRIPTION
 *  [From HTTP] HTTP screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_http(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id_list[MAX_SUB_MENUS]; /* Stores the strings id of submenus returned */
    U8 *gui_buffer;                 /* Buffer holding history data */
    U16 item_num;                   /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_is_ready())
    {
        EntryNewScreen(SCR_ID_DM_HTTP, NULL, mmi_dm_fwu_entry_http, NULL);
    
        /* Get current screen to gui buffer  for history purposes */
        gui_buffer = GetCurrGuiBuffer(SCR_ID_DM_HTTP);
        
        /* Retrieve no of child of menu item to be displayed */
        item_num = GetNumOfChild(FWU_HTTP_MENU_ID);
        
        /* Retrieve string ids in sequence of given menu item to be displayed */
        GetSequenceStringIds(FWU_HTTP_MENU_ID, str_id_list);
        
        /* Set current parent id */
        SetParentHandler(FWU_HTTP_MENU_ID);
        
        /* Register highlight handler to be called in menu screen */
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
        /* Display Category52 Screen */
        ShowCategory52Screen(
            STR_ID_DM_FWU_HTTP,
            GetRootTitleIcon(FWU_HTTP_MENU_ID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            item_num,
            str_id_list,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            gui_buffer);
    
        /* Register left arrow key */
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        
        /* Register function with left/right softkey */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_pre_http_settings
 * DESCRIPTION
 *  [From HTTP] Check for Data Account ready before entering HTTP settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_pre_http_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set protocol event handler of recv wap profile list response */
    SetProtocolEventHandler(mmi_dm_fwu_recv_wap_prof_list_cnf, MSG_ID_WAP_GET_PROF_LIST_RSP);
    
    /* send msg to get WAP profile list */
    mmi_dm_fwu_send_msg(wap_get_service_module(MSG_ID_WAP_GET_PROF_LIST_REQ), MSG_ID_WAP_GET_PROF_LIST_REQ, (void*)NULL, (void*)NULL);     
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_recv_wap_prof_list_cnf
 * DESCRIPTION
 *  response handler of recv_wap_prof_list_req
 * PARAMETERS
 *  MSG     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_recv_wap_prof_list_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_prof_list_rsp_struct *msg = (wap_get_prof_list_rsp_struct*)inMsg;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_fwu_context.http_profile_sum = msg->number+1;

    /* the first item is "Default" */
    mmi_ucs2cpy((S8*)g_dm_fwu_context.http_profile_string[0], GetString(STR_ID_DM_HTTP_DEFAULT));
    g_dm_fwu_context.http_profile_str_p[0]= g_dm_fwu_context.http_profile_string[0];

    /* real profiles start from second item */
    for (i = 0; i < g_dm_fwu_context.http_profile_sum && i < DM_HTTP_MAX_WAP_PROF_SUM; i++)
    {
        memcpy(g_dm_fwu_context.http_profile_string[i+1], msg->prof_list[i].name.value, msg->prof_list[i].name.len);
        g_dm_fwu_context.http_profile_string[i+1][msg->prof_list[i].name.len / 2] = L'\0';
        
        g_dm_fwu_context.http_profile_str_p[i+1] = g_dm_fwu_context.http_profile_string[i+1];
    }

    if (msg->prof_list)
    {
        OslMfree(msg->prof_list);
    }

    /* entry http setting screen */
    mmi_dm_fwu_entry_http_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_http_settings
 * DESCRIPTION
 *  [From HTTP] Settings screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_http_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;  /* Buffer holding history data */
    U8 *input_buffer;
    U16 input_buffer_size;
    U16 icon_list[DM_HTTP_IDX_END];
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* CheckIsBackHistory should be called before EntryNewScreen */
    if (!CheckIsBackHistory())
    {
        /* get settings for the first entry */
        mmi_dm_fwu_get_settings(DM_UPGRADE_HTTP);
    }
    
    EntryNewScreen(SCR_ID_DM_HTTP_SETTINGS, mmi_dm_fwu_exit_http_settings, NULL, NULL);
   
    InitializeCategory57Screen();

    /* get icon list */
    for (i=0; i<DM_HTTP_IDX_END; i+=2)
    {
        icon_list[i] = gIndexIconsImageList[i>>1];
        icon_list[i+1] = 0;
    }

    /* Get current screen to gui buffer  for history purposes */
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DM_HTTP_SETTINGS);

    /* Get input buffer for inline edit history */
    input_buffer = GetCurrNInputBuffer(SCR_ID_DM_HTTP_SETTINGS, &input_buffer_size);
    
    /* Set current parent id */
    SetParentHandler(FWU_HTTP_MENU_ID);
    
    /* Register highlight handler to be called in menu screen */
//    RegisterHighlightHandler(mmi_dm_fwu_http_settings_submenu_highlight_hdlr);

    /* construct all inline items */
    mmi_dm_fwu_construct_inline_item(DM_UPGRADE_HTTP);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, DM_HTTP_IDX_END, input_buffer);
    }

    /* set done-flag to change RSK to Done if necessary */
    if (g_dm_fwu_context.is_da_changed == MMI_TRUE && 
        (GetInlineDoneFlag(gui_buffer) == 0))
    {
        SetInlineDoneFlag(gui_buffer);
    }
    
    /* Display Category57 Screen */
    ShowCategory57Screen(
        STR_ID_DM_SETTINGS,
        GetRootTitleIcon(SERVICES_FWU_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        DM_HTTP_IDX_END,
        icon_list,
        wgui_inline_items,
        0,
        gui_buffer);

    SetCategory57RightSoftkeyFunctions(mmi_dm_fwu_entry_confirm_setting, GoBackHistory);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_exit_http_settings
 * DESCRIPTION
 *  [From HTTP]Settings screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_exit_http_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DM_HTTP_SETTINGS;
    h.entryFuncPtr = mmi_dm_fwu_entry_http_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_save_http_settings
 * DESCRIPTION
 *  [From HTTP] Save the settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_save_http_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset da changed flag to FALSE */    
    g_dm_fwu_context.is_da_changed = MMI_FALSE;
    
    stopRequestedTone(WARNING_TONE);

    /* Save setttings to NVRAM */
    mmi_dm_fwu_set_settings(DM_UPGRADE_HTTP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_settings_submenu_highlight_hdlr
 * DESCRIPTION
 *  [From HTTP] Highlight handler for HTTP Settings submenu 
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_settings_submenu_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == DM_HTTP_IDX_PROFILE)
    {
        g_dm_fwu_context.is_da_changed = MMI_TRUE;
        
        /* when highlight Data Account, LSK will be changed for selecting a DA */    
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_get_profile_content_req
 * DESCRIPTION
 *  [From HTTP] start http -- get profile content request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_get_profile_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_prof_content_req_struct *get_prof_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set protocol event handler of http set channel */
    SetProtocolEventHandler(mmi_dm_fwu_http_get_profile_content_cnf, MSG_ID_WAP_GET_PROF_CONTENT_RSP);

    get_prof_req = construct_local_para(sizeof(wap_get_prof_content_req_struct), TD_CTRL);

//    get_prof_req->id = g_dm_fwu_context.http_profile_id[g_dm_fwu_context.http_profile_index];
    get_prof_req->id = g_dm_fwu_context.http_profile_index-1;
    
    mmi_dm_fwu_send_msg(wap_get_service_module(MSG_ID_WAP_GET_PROF_CONTENT_REQ), MSG_ID_WAP_GET_PROF_CONTENT_REQ, (void*)get_prof_req, (void*)NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_get_profile_content_cnf
 * DESCRIPTION
 *  [From HTTP] get profile content confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_get_profile_content_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_prof_content_rsp_struct *rsp_p = inMsg; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == 0)  /* success */
    {
        /* keep the profile info */
        memcpy((void*)&wap_profile_info, (void*)rsp_p, sizeof(wap_get_prof_content_rsp_struct));

        /* send http set channel request */
        mmi_dm_fwu_http_set_channel_req();        
    }
    else
    {
        /* fails */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] http get prof: %d", rsp_p->result);
        g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_GEN_ERROR;
        mmi_dm_fwu_entry_download_result();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_set_channel_req
 * DESCRIPTION
 *  [From HTTP] start http -- set channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_set_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req;
    U16 msg_len, ref_count;
    U8 i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set protocol event handler of http set channel */
    SetProtocolEventHandler(mmi_dm_fwu_http_set_channel_cnf, MSG_ID_WPS_SET_CHANNEL_RSP);
    
    set_channel_req = (wps_set_channel_req_struct *) construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL);
    msg_len = set_channel_req->msg_len;
    ref_count = set_channel_req->ref_count;
    memset(set_channel_req, 0 , sizeof(wps_set_channel_req_struct));
    set_channel_req->msg_len = msg_len;
    set_channel_req->ref_count = ref_count;

//    if (g_dm_fwu_context.http_profile_id[g_dm_fwu_context.http_profile_index] == 0xFF)  /* use default */
    if (g_dm_fwu_context.http_profile_index == 0 )     /* use default profile */
    {
        set_channel_req->use_default = KAL_TRUE;
    }
    else
    {
        set_channel_req->use_default = KAL_FALSE;    
        set_channel_req->conn_type = WPS_CONN_TYPE_HTTP;
        set_channel_req->timeout = DM_HTTP_WPS_TIMEOUT;
        
        set_channel_req->net_id = wap_profile_info.net_id;

        if (wap_profile_info.prx_ip[0] == 0 && wap_profile_info.prx_ip[1] == 0 && wap_profile_info.prx_ip[2] == 0 && wap_profile_info.prx_ip[3] == 0 )
        {
            set_channel_req->use_proxy = KAL_FALSE;
        }
        else
        {
            set_channel_req->use_proxy = KAL_TRUE;
        }

        for (i = 0; i < 4;i++)
        {
            set_channel_req->prx_ip[i] = wap_profile_info.prx_ip[i];
        }

        set_channel_req->prx_port = wap_profile_info.prx_port;
    
        memset(set_channel_req->username,0,sizeof(set_channel_req->username));
        strcpy((char*)set_channel_req->username,(char*)wap_profile_info.username);
    
        memset(set_channel_req->password,0,sizeof(set_channel_req->password));    
        strcpy((char*)set_channel_req->password,(char*)wap_profile_info.password);    
        
    }

    mmi_dm_fwu_send_msg(MOD_WPS, MSG_ID_WPS_SET_CHANNEL_REQ, (void*)set_channel_req, (void*)NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_set_channel_cnf
 * DESCRIPTION
 *  [From HTTP] start http confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_set_channel_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *rsp_p = inMsg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == WPS_OK)
    {
        /* keep the channel id */
        g_dm_fwu_context.job_id = rsp_p->channel_id;

        /* then send http request */
        mmi_dm_fwu_http_send_http_req();        
    }
    else
    {
        /* fails */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] http set chan: %d", rsp_p->result);
        g_dm_fwu_context.general_result_code = (U8)mmi_dm_fwu_convert_result_code((U8)rsp_p->result);
        mmi_dm_fwu_entry_download_result();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_send_http_req
 * DESCRIPTION
 *  [From HTTP] start http -- send http request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_send_http_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_req_struct *http_req;
    wps_http_req_var_struct http_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 pdu_length;
    U16 len;
    U8 url[(DM_HTTP_MAX_URL_LEN + 1)];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set protocol event handler of http send http confirm */
    SetProtocolEventHandler((PsFuncPtr)mmi_dm_fwu_http_send_http_cnf, MSG_ID_WPS_HTTP_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_dm_fwu_recv_http_auth_ind, MSG_ID_WPS_HTTP_AUTH_IND);
    
    /* get control buffer */
    g_dm_fwu_context.buffer = (U8*)get_ctrl_buffer(DM_HTTP_BUFFER_SIZE);
    
    http_req = (wps_http_req_struct *) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);
    http_req->channel_id = g_dm_fwu_context.job_id;       /* channel id */
    http_req->request_id = 0;                             /* unused */
    http_req->method = WPS_HTTP_METHOD_GET;               /* to get an object */
    http_req->option = WPS_HTTP_OPTION_NO_CACHE;          /* use no cache */

    memset(url, 0, sizeof(url));    
    mmi_ucs2_to_asc((PS8)url,  (PS8)g_dm_fwu_context.http_url);     
    http_req_var.request_url_len = (kal_uint32) strlen((S8*)url);      /* url length*/
    
    http_req_var.request_url = (kal_uint8 *) url;        /* url */
    http_req_var.request_header_len = 0;                 /* unused */
    http_req_var.request_header = NULL;                  /* unused */

    http_req->reply_type = WPS_DATA_TYPE_BUFFER;         /* reply type: buffer */
    
    memset(http_req->reply_path, 0 , sizeof(http_req->reply_path));   /* unused */
    http_req->reply_segment_len = DM_HTTP_BUFFER_SIZE;                /* buffer size */
    http_req->post_type = 0;                                          /* unused */
    memset(http_req->post_path, 0 , sizeof(http_req->post_path));     /* unused */
	http_req->post_total_len = 0;                                     /* unused */
    http_req->more_post = MMI_FALSE;                                  /* unused */
    http_req_var.post_segment_len = 0;                                /* unused */
    http_req_var.post_segment = NULL;                                 /* unused */

    /* pack peer buffer */
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &len)) !=
            pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    mmi_dm_fwu_send_msg(MOD_WPS, MSG_ID_WPS_HTTP_REQ, (void*)http_req, (void*)peer_buff_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_send_http_cnf
 * DESCRIPTION
 *  [From HTTP] stop http confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_send_http_cnf(void *msgStruct, int mod_id , void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *rsp_p = (wps_http_rsp_struct *) msgStruct;
    wps_http_rsp_var_struct http_rsp_var;
    U16 pdu_length = 0;
    ilm_struct *ilm_info = (ilm_struct*)peer_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == WPS_OK && rsp_p->status == 200)
    {
        /* set state: upgrading */
        g_dm_fwu_context.state = DM_STATE_DOWNLOADING;

        /* keep the total size */
        g_dm_fwu_context.total_size = rsp_p->content_length;

        /* entry download animation, and it might change animation */
        mmi_dm_fwu_entry_download_animation();
        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);        

        /* unpack peer buffer */
        if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_HTTP_RSP, &http_rsp_var, get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length)) > 0)
        {
            /* calcuate cumulate size */
            g_dm_fwu_context.cumul_size += http_rsp_var.reply_segment_len;

            /* keep the more flag */
            g_dm_fwu_context.more = rsp_p->more;

            /* segment number ++ */
            g_dm_fwu_context.seqnum++;            

            memset(g_dm_fwu_context.buffer, 0, sizeof(g_dm_fwu_context.buffer));
            memcpy(g_dm_fwu_context.buffer, http_rsp_var.reply_segment, http_rsp_var.reply_segment_len);

            /* send msg to fmt to write fota data */
            mmi_dm_fwu_fmt_fota_write_data_req(http_rsp_var.reply_segment_len);
        }
    }
    else
    {
        if (rsp_p->status == 404)
        {
            g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_FILE_NOT_FOUND;
        }
    
        /* fails! error occurs */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] http send http: %d status: %d", rsp_p->result, rsp_p->status);
        
        if (g_dm_fwu_context.state != DM_STATE_ABORT)
        {
            g_dm_fwu_context.state = DM_STATE_ERROR;
        }

        /* unset channel */
        mmi_dm_fwu_http_unset_channel_req();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_recv_http_auth_ind
 * DESCRIPTION
 *  [From HTTP] receive http authentication indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_recv_http_auth_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_ind_struct *p = (wps_http_auth_ind_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_fwu_context.http_auth_request_id = p->request_id;
    g_dm_fwu_context.state = DM_STATE_HTTP_AUTH;
        
    mmi_dm_fwu_entry_auth_screen();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_auth_screen
 * DESCRIPTION
 *  [From HTTP] entry authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_auth_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    InlineItem authenticate_list[4];
    U16 IconsImageList[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DM_HTTP_AUTH, mmi_dm_fwu_exit_auth_screen, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DM_HTTP_AUTH);
    InitializeCategory57Screen();

    memset(authenticate_list, 0, sizeof(authenticate_list));

    if(!guiBuffer)
    {
        memset(g_dm_fwu_context.auth_username, 0, sizeof(g_dm_fwu_context.auth_username));
        memset(g_dm_fwu_context.auth_password, 0, sizeof(g_dm_fwu_context.auth_password));
    }

    /* For username caption */
    SetInlineItemActivation(&authenticate_list[MMI_DM_FWU_INLINE_USERNAME_CAPTION],
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&authenticate_list[MMI_DM_FWU_INLINE_USERNAME_CAPTION], (U8*)GetString(STR_GLOBAL_USERNAME));

    /* For username string */
    SetInlineItemActivation(&authenticate_list[MMI_DM_FWU_INLINE_USERNAME], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(&authenticate_list[MMI_DM_FWU_INLINE_USERNAME],
                                STR_GLOBAL_USERNAME,
                                GetRootTitleIcon(FWU_HTTP_MENU_ID),
                                (U8*) g_dm_fwu_context.auth_username,
                                MMI_DM_AUTH_LEN_USERNAME,
                                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&authenticate_list[MMI_DM_FWU_INLINE_USERNAME],
                                mmi_dm_fwu_auth_full_screen_editor_options);

    /* For password caption */
    SetInlineItemActivation(&authenticate_list[MMI_DM_FWU_INLINE_PASSWORD_CAPTION],
                             INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
                             0);
    SetInlineItemCaption(&authenticate_list[MMI_DM_FWU_INLINE_PASSWORD_CAPTION], (U8*) GetString(STR_GLOBAL_PASSWORD));

    /* For password string */
    SetInlineItemActivation(&authenticate_list[MMI_DM_FWU_INLINE_PASSWORD], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(&authenticate_list[MMI_DM_FWU_INLINE_PASSWORD],
                                STR_GLOBAL_PASSWORD,
                                GetRootTitleIcon(FWU_HTTP_MENU_ID),
                                (U8*) g_dm_fwu_context.auth_password,
                                MMI_DM_AUTH_LEN_PASSWORD,
                                INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&authenticate_list[MMI_DM_FWU_INLINE_PASSWORD],
                                mmi_dm_fwu_auth_full_screen_editor_options);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_DM_HTTP_AUTH, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(authenticate_list, 4, inputBuffer);
    }

    SetParentHandler(0);

    /* Set the softkey label to be displayed in  Category57 screen */
    RegisterHighlightHandler(mmi_dm_fwu_softkey_label_highlight_hdlr);

    IconsImageList[0] = gIndexIconsImageList[0];
    IconsImageList[1] = 0;
    IconsImageList[2] = gIndexIconsImageList[1];
    IconsImageList[3] = 0;

    ShowCategory57Screen(
        STR_GLOBAL_AUTHENTICATION,
        GetRootTitleIcon(FWU_HTTP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_CANCEL,
        0,
        4,
        (U16*) IconsImageList,
        authenticate_list,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_dm_fwu_auth_confirm_hdlr, mmi_dm_fwu_auth_no_hdlr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_exit_auth_screen
 * DESCRIPTION
 *  [From HTTP]authentication screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_exit_auth_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DM_HTTP_AUTH;
    h.entryFuncPtr = mmi_dm_fwu_entry_auth_screen;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_auth_confirm_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_auth_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucs2strlen((S8*)g_dm_fwu_context.auth_username) == 0)
    {
        DisplayPopup((PU8) GetString(STR_ID_DM_EMPTY_USERNAME), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        return;
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SUBMIT),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
        
        SetKeyHandler(mmi_dm_fwu_auth_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_dm_fwu_auth_yes_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_dm_fwu_auth_no_hdlr, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_auth_yes_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_auth_yes_hdlr(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_dm_fwu_http_send_http_auth_res();
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_auth_no_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_auth_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    g_dm_fwu_context.state = DM_STATE_ABORT;

    memset(g_dm_fwu_context.auth_username, 0, sizeof(g_dm_fwu_context.auth_username));
    memset(g_dm_fwu_context.auth_password, 0, sizeof(g_dm_fwu_context.auth_password));

    mmi_dm_fwu_http_send_http_auth_res();

    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_auth_full_screen_editor_options
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_auth_full_screen_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(FWU_HTTP_MENU_ID));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_softkey_label_highlight_hdlr
 * DESCRIPTION
 *  Custom Highlight handler to change the label of LSK in case of inline edit screen.
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_softkey_label_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NumericKeys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(mmi_dm_fwu_auth_open_full_screen_editor, NumericKeys, 11, KEY_EVENT_UP);

    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
    SetKeyHandler(mmi_dm_fwu_auth_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_dm_fwu_auth_open_full_screen_editor, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_auth_open_full_screen_editor
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_auth_open_full_screen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_DOWN);
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_UP);
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_auth_endkey_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_auth_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    if (g_dm_fwu_context.state == DM_STATE_HTTP_AUTH)
    {
        g_dm_fwu_context.state = DM_STATE_ABORT;
        
        memset(g_dm_fwu_context.auth_username, 0, sizeof(g_dm_fwu_context.auth_username));
        memset(g_dm_fwu_context.auth_password, 0, sizeof(g_dm_fwu_context.auth_password));

        mmi_dm_fwu_http_send_http_auth_res();
        SetProtocolEventHandler(NULL, MSG_ID_WPS_HTTP_RSP);
        mmi_dm_fwu_http_unset_channel_req();   
        SetProtocolEventHandler(NULL, MSG_ID_WPS_UNSET_CHANNEL_RSP);
        
        /* user abort */
        g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_ABORT;
        mmi_dm_fwu_entry_download_result();

        DeleteUptoScrID(IDLE_SCREEN_ID);
    }
    else
    {
        DisplayIdleScreen();
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_dm_fwu_http_send_http_auth_res
* DESCRIPTION
*   get User Agent
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
void mmi_dm_fwu_http_send_http_auth_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct * p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wps_http_auth_res_struct *) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);

    p->channel_id = g_dm_fwu_context.job_id;
    p->request_id = g_dm_fwu_context.http_auth_request_id;
    mmi_ucs2_to_asc((S8*)p->password, (S8*)g_dm_fwu_context.auth_password);
    mmi_ucs2_to_asc((S8*)p->username, (S8*)g_dm_fwu_context.auth_username);

    mmi_dm_fwu_send_msg(MOD_WPS, MSG_ID_WPS_HTTP_AUTH_RES, (void*)p, (void*)NULL);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_read_content_req
 * DESCRIPTION
 *  [From HTTP] start http -- send read content request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_read_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_req_struct *read_content_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set http read content confirm */
    SetProtocolEventHandler((PsFuncPtr)mmi_dm_fwu_http_read_content_cnf, MSG_ID_WPS_READ_CONTENT_RSP);
    
    if (g_dm_fwu_context.more == MMI_TRUE)
    {
        /* it means there is still data need to receive */
        read_content_req = (wps_read_content_req_struct *) construct_local_para(sizeof(wps_read_content_req_struct), TD_CTRL);
        read_content_req->channel_id = g_dm_fwu_context.job_id;
        read_content_req->request_id = 0;
        read_content_req->seq_num = g_dm_fwu_context.seqnum;    
        read_content_req->read_segnemtn_len = 0;    
    
        mmi_dm_fwu_send_msg(MOD_WPS, MSG_ID_WPS_READ_CONTENT_REQ, (void*)read_content_req, (void*)NULL);
    }
    else
    {
        /* send unset channel request to WPS */
        mmi_dm_fwu_http_unset_channel_req();   

        /* set state: finish. it means there is no data need to receive */
        g_dm_fwu_context.state = DM_STATE_DOWNLOAD_FINISH;  
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_read_content_cnf
 * DESCRIPTION
 *  [From HTTP] read content confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_read_content_cnf(void *msgStruct, int mod_id , void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_rsp_struct *rsp_p = (wps_read_content_rsp_struct *) msgStruct;
    wps_read_content_rsp_var_struct read_content_rsp_var;
    U16 pdu_length = 0;
    ilm_struct *ilm_info = (ilm_struct*)peer_buf;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == WPS_OK)
    {
        /* unpack peer buffer */
        if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_READ_CONTENT_RSP, &read_content_rsp_var, get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length)) > 0)
        {
            /* calculate cumulate size */
            g_dm_fwu_context.cumul_size += read_content_rsp_var.reply_segment_len;

            /* keep the more flag */
            g_dm_fwu_context.more = rsp_p->more;

            /* segment number ++ */
            g_dm_fwu_context.seqnum++;
            
            memset(g_dm_fwu_context.buffer, 0, sizeof(g_dm_fwu_context.buffer));
            memcpy(g_dm_fwu_context.buffer, read_content_rsp_var.reply_segment, read_content_rsp_var.reply_segment_len);

            /* send write fota data msg to fmt */
            mmi_dm_fwu_fmt_fota_write_data_req(read_content_rsp_var.reply_segment_len);
        }
    }
    else
    {
        /* fails! error occurs */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] http read cont: %d", rsp_p->result);
        
        g_dm_fwu_context.state = DM_STATE_ERROR;
        
        /* fails, unset channel */
        mmi_dm_fwu_http_unset_channel_req();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_unset_channel_req
 * DESCRIPTION
 *  [From HTTP] stop http request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_unset_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.state != DM_STATE_DOWNLOAD_FINISH)
    {
        /* set protocol event handler of http unset channel confirm */
        SetProtocolEventHandler(mmi_dm_fwu_http_unset_channel_cnf, MSG_ID_WPS_UNSET_CHANNEL_RSP);
    
        msgReq = (wps_unset_channel_req_struct*) OslConstructDataPtr(sizeof(wps_unset_channel_req_struct));

        msgReq->channel_id = (U8)(g_dm_fwu_context.job_id);

        mmi_dm_fwu_send_msg(MOD_WPS, MSG_ID_WPS_UNSET_CHANNEL_REQ, (void*)msgReq, (void*)NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_unset_channel_cnf
 * DESCRIPTION
 *  [From HTTP] stop http confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_unset_channel_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_dm_fwu_context.state)
    {
        case DM_STATE_DOWNLOAD_FINISH:
        {
            /* EOF , finish reading */
            mmi_dm_fwu_fmt_fota_finalize_req(); 
            break;
        }
        case DM_STATE_ERROR:
        {
            /* Error occurs */
            if (g_dm_fwu_context.general_result_code != (U8)DM_RESULT_CODE_FILE_NOT_FOUND)
            {
                g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_SOC_ERROR;
            }
            mmi_dm_fwu_entry_download_result();
            break;
        }
        case DM_STATE_FOTA_AUTH_ERROR:
        {
            g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_AUTHENTICATION_FAIL;
            mmi_dm_fwu_entry_download_result();
            break;
        }
        default:
        {
            /* user abort */
            g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_ABORT;
            mmi_dm_fwu_entry_download_result();
            DeleteScreenIfPresent(SCR_ID_DM_HTTP_AUTH);   
            break;
        }
    }
    
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_http_abort_req
 * DESCRIPTION
 *  [From HTTP] abort http request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_http_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.state != DM_STATE_DOWNLOAD_FINISH)
    {
        g_dm_fwu_context.state = DM_STATE_ABORT;
        
        mmi_dm_fwu_http_unset_channel_req();
    }
}

#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */


#if defined(__MMI_FWU_VIA_FILE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_file_highlight_hdlr
 * DESCRIPTION
 *  [From File] File Menu highlight handler
 * PARAMETERS
 *  index       [IN]        Highlight position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_file_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                            */
    /*----------------------------------------------------------------*/
    /* set upgrade media: FILE */       
    g_dm_fwu_context.upgrade_media = DM_UPGRADE_FILE;
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_file_select, KEY_EVENT_UP);

    SetKeyHandler(mmi_dm_fwu_entry_file_select, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_file_select
 * DESCRIPTION
 *  [From File] File screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_file_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /* ToDo: discuss a extension file name for firmware */
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOTA_FULL);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

#if defined(__MMI_FWU_VIA_FILE__)
    mmi_fmgr_select_path_and_enter(APP_DEVICE_MANAGEMENT, 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT, 
                                   filter, 
                                   (PS8) L"root",
                                   mmi_dm_fwu_file_select_callback);
#endif /* #ifdef __MMI_FWU_VIA_FILE__*/

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_file_select_callback
 * DESCRIPTION
 *  [From File] The call back function called when the user selects some file from FMGR
 * PARAMETERS
 *  path            [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_file_select_callback(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *filepath = (S8*) path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath)
    {
        /* keep the file path */
        memset(g_dm_fwu_context.full_filename_buffer, 0, sizeof(g_dm_fwu_context.full_filename_buffer));    
        mmi_ucs2cpy((S8*)g_dm_fwu_context.full_filename_buffer, (S8*)filepath);

        fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */

        /* get file size */
        g_dm_fwu_context.fs_handle = FS_Open((U16*) g_dm_fwu_context.full_filename_buffer, FS_READ_ONLY);
        if (g_dm_fwu_context.fs_handle >= FS_NO_ERROR)
        {
            /* get file size --> total size */
            FS_GetFileSize(g_dm_fwu_context.fs_handle, (kal_uint32*) & g_dm_fwu_context.total_size);
            FS_Close(g_dm_fwu_context.fs_handle);
        }
        else
        {
            /* Open file error. maybe file is gone.*/        
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(g_dm_fwu_context.fs_handle)), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE); 

            /* init dm context */
            mmi_dm_fwu_init_context();    

            return;
        }    

        g_dm_fwu_context.percentage = 0;
        g_dm_fwu_context.cumul_size = 0;

        /* get control buffer */
        g_dm_fwu_context.buffer = (U8*)get_ctrl_buffer(DM_FILE_BUFFER_SIZE);

        /* entry download confirm screen */
        mmi_dm_fwu_entry_download_confirm();
    }
    else
    {
        GoBackHistory();
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_file_download_to_phone
 * DESCRIPTION
 *  [From File] start read data from file to fota
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_file_download_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   ret;
    U32   len_read;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.cumul_size==0)
    {
        /* first time to read data from file. 
           1. set state: upgrading 
           2. open file to get file handle */
        g_dm_fwu_context.state = DM_STATE_DOWNLOADING;
        g_dm_fwu_context.fs_handle = FS_Open((U16*) g_dm_fwu_context.full_filename_buffer, FS_READ_ONLY);
    }
    
    if (g_dm_fwu_context.fs_handle >= FS_NO_ERROR)
    {
        /* read data from file */
        memset(g_dm_fwu_context.buffer, 0, sizeof(g_dm_fwu_context.buffer));
        ret = FS_Read(g_dm_fwu_context.fs_handle, 
                      g_dm_fwu_context.buffer,
                      DM_FILE_BUFFER_SIZE, 
                      &len_read);

        /* FS error */
        if (ret < 0)
        {
            FS_Close(g_dm_fwu_context.fs_handle);  

            /* init dm context */
            mmi_dm_fwu_init_context();    

            /* Open file error. maybe file is gone.*/
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(ret)), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);
           
            return;
        }
           
        if (len_read == 0)
        {
            /* set state: finish */
            g_dm_fwu_context.state = DM_STATE_DOWNLOAD_FINISH;
        
            /* EOF , finish reading */
            mmi_dm_fwu_fmt_fota_finalize_req(); 
        }
        else
        {
            /* calculate cumulate size */
            g_dm_fwu_context.cumul_size += len_read;
           
            if (g_dm_fwu_context.cumul_size <= g_dm_fwu_context.total_size)
            {
                mmi_dm_fwu_fmt_fota_write_data_req(len_read);        
            }
            else
            {
                /* error */
                FS_Close(g_dm_fwu_context.fs_handle);

                /* init dm context */
                mmi_dm_fwu_init_context();   
                g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_GEN_ERROR;
                mmi_dm_fwu_entry_download_result();
                return;
            }
        }
    }
    else
    {
        /* Open file error. maybe file is gone.*/
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(g_dm_fwu_context.fs_handle)), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);        
        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);      

        /* init dm context */
        mmi_dm_fwu_init_context();   

        /* open file fails */
        FS_Close(g_dm_fwu_context.fs_handle); 
        return;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_file_abort_download
 * DESCRIPTION
 *  [From File] stop download from file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_file_abort_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.state != DM_STATE_DOWNLOAD_FINISH)
    {
        g_dm_fwu_context.state = DM_STATE_ABORT;
        
        mmi_dm_fwu_file_abort_result();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_file_abort_result
 * DESCRIPTION
 *  [From File] abort result from file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_file_abort_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_dm_fwu_context.state != DM_STATE_DOWNLOAD_FINISH)
    {
        switch (g_dm_fwu_context.state)
        {
            case DM_STATE_ERROR:
            {
                g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_GEN_ERROR;
                mmi_dm_fwu_entry_download_result();
                break;
            }
            case DM_STATE_FOTA_AUTH_ERROR:
            {
                g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_AUTHENTICATION_FAIL;
                mmi_dm_fwu_entry_download_result();
                break;
            }
            default:
            {
                g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_ABORT;
                mmi_dm_fwu_entry_download_result();
                break;
            }
        }
    }
    return;
}
#endif /* #ifdef __MMI_FWU_VIA_FILE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_confirm_setting
 * DESCRIPTION
 *  Confirm Upgrade Settings Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_confirm_setting(void)
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
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    switch(g_dm_fwu_context.upgrade_media)
    {
    #if defined(__MMI_FWU_VIA_TFTP__)    
        case DM_UPGRADE_TFTP:
        {
            SetLeftSoftkeyFunction(mmi_dm_fwu_save_tftp_settings, KEY_EVENT_UP);
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
    #if defined(__MMI_FWU_VIA_HTTP__)
        case DM_UPGRADE_HTTP:    
        {
            SetLeftSoftkeyFunction(mmi_dm_fwu_save_http_settings, KEY_EVENT_UP);            
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
        case DM_UPGRADE_FILE:
        {
            break;
        }
        default:
        {
            break;
        }
    }
    
    SetRightSoftkeyFunction(mmi_dm_fwu_ignore_settings, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_download_confirm
 * DESCRIPTION
 *  Confirm Download Now Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_download_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(STR_GLOBAL_YES,
                   IMG_GLOBAL_YES,
                   STR_GLOBAL_NO,
                   IMG_GLOBAL_NO,
                   get_string(STR_ID_DM_DOWNLOAD_NOW),
                   IMG_GLOBAL_QUESTION,
                   WARNING_TONE);
    
    SetLeftSoftkeyFunction(mmi_dm_fwu_entry_download_animation, KEY_EVENT_UP);    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_download_animation
 * DESCRIPTION
 *  entry download animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_download_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif /*__MMI_FOTA_OTAP_DMP__*/

    if (isInCall())
    {
        if (!IsScreenPresent(SCR_ID_DM_UPGRADE_ANIMATION))
        {
            history currHistory;
            S16 nHistory = 0;
    
            currHistory.scrnID = SCR_ID_DM_UPGRADE_ANIMATION;
            currHistory.entryFuncPtr = mmi_dm_fwu_entry_download_animation;
            mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
            GetCategoryHistory(currHistory.guiBuffer);
            AddHistory(currHistory);
        }
    }
    else
    {
        if (g_dm_fwu_context.total_size == 0)
        {
            /* if total size is 0, the screen will show some info, such as: received size */
            EntryNewScreen(SCR_ID_DM_UPGRADE_ANIMATION, NULL, mmi_dm_fwu_entry_download_animation, NULL);
        
            ShowCategory66Screen(STR_ID_DM_FWU,
                                 GetRootTitleIcon(SERVICES_FWU_MENU_ID),
                                 0,
                                 0,
                                 STR_GLOBAL_ABORT,
                                 0,
                                 (PU8) GetString(STR_ID_DM_DOWNLOADING),
                                 IMG_GLOBAL_PROGRESS,
                                 NULL);
        }
        else
        {
            /* if total size is not 0, the screen will be a progress screen */
            EntryNewScreen(SCR_ID_DM_UPGRADE_ANIMATION, NULL, mmi_dm_fwu_entry_download_animation, NULL);
        
            ShowCategory402Screen((U8*)GetString(STR_ID_DM_FWU), 
                                   0,
                                   0, 
                                   0, 
                                   STR_GLOBAL_ABORT, 
                                   0, 
                                   (PU8) GetString(STR_ID_DM_DOWNLOADING), 
                                   g_dm_fwu_context.percentage,
                                   NULL);    
        }
        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_RESULT);

        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

        switch(g_dm_fwu_context.upgrade_media)
        {
        #if defined(__MMI_FWU_VIA_TFTP__)    
            case DM_UPGRADE_TFTP:
            {
                SetRightSoftkeyFunction(mmi_dm_fwu_tftp_abort_tftp_req, KEY_EVENT_UP);
                break;
            }
        #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
        #if defined(__MMI_FWU_VIA_HTTP__)
            case DM_UPGRADE_HTTP:
            {
                SetRightSoftkeyFunction(mmi_dm_fwu_http_abort_req, KEY_EVENT_UP);
                break;
            }
        #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
        #if defined(__MMI_FWU_VIA_FILE__)
            case DM_UPGRADE_FILE:
            {
                SetRightSoftkeyFunction(mmi_dm_fwu_file_abort_download, KEY_EVENT_UP);
                break;
            }
        #endif /* #ifdef __MMI_FWU_VIA_FILE__ */
            default:
            {
                break;
            }
        }
    }

    /* the first time should send fota init request */
    if ((g_dm_fwu_context.state == DM_STATE_INIT) || (g_dm_fwu_context.state == DM_STATE_DOWNLOAD_FINISH_PENDING))
    {
        g_dm_fwu_context.state = DM_STATE_WAIT_AUTH;    

        /* Send FOTA init to FMT task : authentication*/
        mmi_dm_fwu_fmt_fota_init_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_show_upgrade_percentage
 * DESCRIPTION
 *  Update percentage 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_show_upgrade_percentage(S32 percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!isInCall())
    {
        if (GetActiveScreenId() == SCR_ID_DM_UPGRADE_ANIMATION)
        {
            if (g_dm_fwu_context.total_size != 0 )
            {
                /* update the progress bar */
                if(percentage != g_dm_fwu_context.percentage)
                {
                    g_dm_fwu_context.percentage = percentage;
                    UpdateCategory402Value((U16)percentage, NULL);
                }
            }
        }
        else if (!IsScreenPresent(SCR_ID_DM_UPGRADE_ANIMATION))
        {
            /* it means upgrading screen is overlaped or deleted, re-entry again.
               To keep the download animation is always on the top */
            g_dm_fwu_context.percentage = percentage;
            mmi_dm_fwu_entry_download_animation();
        }
        else
        {
            g_dm_fwu_context.percentage = percentage;
        }
    }
    else
    {
        g_dm_fwu_context.percentage = percentage;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_upgrade_now_confirm
 * DESCRIPTION
 *  Upgrade Now Confirm Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_upgrade_now_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FWU_VIA_FILE__)
    if (g_dm_fwu_context.upgrade_media == DM_UPGRADE_FILE)
    {
        FS_Close(g_dm_fwu_context.fs_handle); 
    }
#endif

    if (!isInCall())
    {
        TurnOnBacklight(1);
        
        DisplayConfirm(STR_GLOBAL_YES,
                       IMG_GLOBAL_YES,
                       STR_GLOBAL_NO,
                       IMG_GLOBAL_NO,
                       get_string(STR_ID_DM_UPGRADE_NOW),
                       IMG_GLOBAL_QUESTION,
                       WARNING_TONE);
    
        SetLeftSoftkeyFunction(mmi_dm_fwu_entry_shutdown_for_upgrade, KEY_EVENT_UP);    
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
         
        /* init dm context */
        mmi_dm_fwu_init_context();    
    }
    else
    {
        /* init dm context */
        mmi_dm_fwu_init_context();    
        g_dm_fwu_context.state = DM_STATE_DOWNLOAD_FINISH_PENDING;

            HistoryReplace(SCR_ID_DM_UPGRADE_ANIMATION, 
                       GLOBAL_SCR_DUMMY, 
                       mmi_dm_fwu_entry_upgrade_now_confirm);
    }   

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_shutdown_for_upgrade
 * DESCRIPTION
 *  shutdown for upgrade notification screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_shutdown_for_upgrade(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern void ShutdownSystemOperation(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(0,
                   0,
                   0,
                   0,
                   get_string(STR_ID_DM_SHUTDOWN_NOTIFY),
                   IMG_GLOBAL_INFO,
                   WARNING_TONE);

    /* start a timer to shoudown system operation */
    StartTimer(FMGR_DM_FWU_SHUTDOWN_TIMER, 3000, ShutdownSystemOperation);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_entry_download_result
 * DESCRIPTION
 *  entry dm result 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_download_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    U16 image_id = IMG_GLOBAL_ERROR;
    U8 tone_id = ERROR_TONE;
    U8 str[100];
    U8 prev_media;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FWU_VIA_FILE__)
    if (g_dm_fwu_context.upgrade_media == DM_UPGRADE_FILE)
    {
        FS_Close(g_dm_fwu_context.fs_handle); 
    }
#endif
    
    switch (g_dm_fwu_context.general_result_code)
    {
        case DM_RESULT_CODE_SUCCESS:
        {
            string_id = STR_GLOBAL_DONE;
            tone_id = SUCCESS_TONE;
            image_id = IMG_GLOBAL_ACTIVATED;
            break;
        }
        case DM_RESULT_CODE_ABORT:
        {
            string_id = STR_GLOBAL_ABORT;
            break;
        }        
        case DM_RESULT_CODE_FILE_NOT_FOUND:
        {
            string_id = STR_ID_DM_RESULT_FILE_NOT_FOUND;
            break;
        }
        case DM_RESULT_CODE_ACCESS_DENIED:
        {
            string_id = STR_ID_DM_RESULT_ACCESS_DENIED;
            break;
        }    
        case DM_RESULT_CODE_SOC_ERROR:
        {
            string_id = STR_ID_DM_RESULT_SOC_ERROR;            
            break;
        }    
        case DM_RESULT_CODE_TIMEOUT:
        {
            string_id = STR_ID_DM_RESULT_TIMEOUT;            
            break;
        }    
        case DM_RESULT_CODE_AUTHENTICATION_FAIL:
        {
            string_id = STR_ID_DM_RESULT_AUTH_FAIL;            
            break;
        }
        case DM_RESULT_CODE_FINAL_CHECK_FAIL:
        {
            string_id = STR_ID_DM_RESULT_FINAL_CHECK_FAIL;            
            break;
        }
        default:
        {
            string_id = STR_GLOBAL_ERROR;            
            break;
        }    
    }        

    if (g_dm_fwu_context.general_result_code==DM_RESULT_CODE_ABORT)
    {
        DisplayPopup((PU8)GetString(string_id), image_id, 0, 1000, tone_id);
        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);

        /* keep the previous media */
        prev_media = g_dm_fwu_context.upgrade_media;
    
        /* init dm context */
        mmi_dm_fwu_init_context();   

        /* restore the previous media */
        g_dm_fwu_context.upgrade_media = prev_media;

    }
    else if (g_dm_fwu_context.upgrade_media == DM_UPGRADE_FILE)
    {
        /* if upgrade via file, doesn't need to retry. */
        DisplayConfirm(0, 
                       0, 
                       STR_GLOBAL_BACK, 
                       IMG_GLOBAL_BACK,
                       (PU16)GetString(string_id), 
                       IMG_GLOBAL_WARNING, 
                       WARNING_TONE);
    
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);   
        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);

        /* keep the previous media */
        prev_media = g_dm_fwu_context.upgrade_media;
    
        /* init dm context */
        mmi_dm_fwu_init_context();   

        /* restore the previous media */
        g_dm_fwu_context.upgrade_media = prev_media;

    }
    else
    {
        /* incall / call end / call abort condition */
        if (IsScreenPresent(SCR_ID_DM_UPGRADE_ANIMATION) &&
            (IsScreenPresent(GetCmMarkerScrnID()) || isInCall()))
        {
            HistoryReplace(SCR_ID_DM_UPGRADE_ANIMATION, 
                           SCR_ID_DM_UPGRADE_RESULT, 
                           mmi_dm_fwu_entry_download_result);
        }
        else
        {
            U8 *guiBuffer;
            U8 prev_result;
        	
            mmi_ucs2cpy((PS8) str, (PS8) get_string(string_id));
            mmi_ucs2cat((PS8) str, (PS8) L"\n");
            mmi_ucs2cat((PS8) str, (PS8) get_string(STR_ID_DM_DOWNLOAD_RETRY));
        
            EntryNewScreen(SCR_ID_DM_UPGRADE_RESULT, NULL, mmi_dm_fwu_entry_download_result, NULL);
            guiBuffer = GetCurrGuiBuffer(SCR_ID_DM_UPGRADE_RESULT);

            ShowCategory121Screen(STR_GLOBAL_YES,
                                  0,
                           STR_GLOBAL_NO, 
                                  0,
                                  (PU8)str,
                           IMG_GLOBAL_QUESTION, 
                                  guiBuffer,
                                  1);
    
            DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);
        
            if (g_dm_fwu_context.state != DM_STATE_INIT)
            {
                playRequestedTone(tone_id);
            }
        
            SetLeftSoftkeyFunction(mmi_dm_fwu_entry_download_animation, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);   

            /* keep the previous media */
            prev_media = g_dm_fwu_context.upgrade_media;
            prev_result = g_dm_fwu_context.general_result_code;

            /* init dm context */
            mmi_dm_fwu_init_context();   

            /* restore the previous media */
            g_dm_fwu_context.upgrade_media = prev_media;
            g_dm_fwu_context.general_result_code = prev_result;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_set_full_scr_edit_lsk
 * DESCRIPTION
 *  Set LSK of full screen inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_set_full_scr_edit_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_FWU_MENU_ID));
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_construct_inline_item
 * DESCRIPTION
 *  Construct inline item data for category57
 * PARAMETERS
 *  scr_id       [IN]            screen id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_construct_inline_item(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    #if defined(__MMI_FWU_VIA_TFTP__)
        case DM_UPGRADE_TFTP:
        {
            /* [0] Server Name title */
            SetInlineItemCaption(&wgui_inline_items[DM_TFTP_IDX_SN_TITLE], (U8 *)GetString(STR_ID_DM_SERVER_NAME));
            /* [0] Server Name item */
            SetInlineItemActivation(&wgui_inline_items[DM_TFTP_IDX_SN], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(&wgui_inline_items[DM_TFTP_IDX_SN], 
                                         STR_ID_DM_SERVER_NAME, 
                                         GetRootTitleIcon(SERVICES_FWU_MENU_ID), 
                                         (U8 *)g_dm_fwu_context.tftp_server_name, 
                                         sizeof(g_dm_fwu_context.tftp_server_name)/ENCODING_LENGTH, 
                                         INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[DM_TFTP_IDX_SN], mmi_dm_fwu_set_full_scr_edit_lsk);
            
            /* [1] Port title */
            SetInlineItemCaption(&wgui_inline_items[DM_TFTP_IDX_PORT_TITLE], (U8 *)GetString(STR_ID_DM_PORT));
            /* [1] Port item */
            SetInlineItemActivation(&wgui_inline_items[DM_TFTP_IDX_PORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(&wgui_inline_items[DM_TFTP_IDX_PORT], 
                                   (U8 *)g_dm_fwu_context.tftp_port, 
                                   sizeof(g_dm_fwu_context.tftp_port)/ENCODING_LENGTH, 
                                   INPUT_TYPE_NUMERIC);
            DisableInlineItemHighlight(&wgui_inline_items[DM_TFTP_IDX_PORT]);

            /* [2] File Name title */
            SetInlineItemCaption(&wgui_inline_items[DM_TFTP_IDX_FN_TITLE], (U8 *)GetString(STR_ID_DM_FILENAME));
            /* [2] File Name item */
            SetInlineItemActivation(&wgui_inline_items[DM_TFTP_IDX_FN], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(&wgui_inline_items[DM_TFTP_IDX_FN], 
                                         STR_ID_DM_FILENAME, 
                                         GetRootTitleIcon(SERVICES_FWU_MENU_ID), 
                                         (U8 *)g_dm_fwu_context.full_filename_buffer, 
                                         sizeof(g_dm_fwu_context.full_filename_buffer)/ENCODING_LENGTH, 
                                         INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[DM_TFTP_IDX_FN], mmi_dm_fwu_set_full_scr_edit_lsk);

            /* [3] Data Account title */
            SetInlineItemCaption(&wgui_inline_items[DM_TFTP_IDX_DA_TITLE], (U8 *)GetString(STR_ID_DTCNT_CAPTION));
            /* [3] Data Account item */
            SetInlineItemActivation(&wgui_inline_items[DM_TFTP_IDX_DA], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemDisplayOnly(&wgui_inline_items[DM_TFTP_IDX_DA], (U8 *)g_dm_fwu_context.tftp_da_name);
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
    #if defined(__MMI_FWU_VIA_HTTP__)
        case DM_UPGRADE_HTTP:
        {
            /* [0] title */
            SetInlineItemCaption(&wgui_inline_items[DM_HTTP_IDX_URL_TITLE], (U8 *)GetString(STR_ID_DM_URL));
            /* [0] item */
            SetInlineItemActivation(&wgui_inline_items[DM_HTTP_IDX_URL], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(&wgui_inline_items[DM_HTTP_IDX_URL], 
                                         STR_ID_DM_URL, 
                                         GetRootTitleIcon(SERVICES_FWU_MENU_ID), 
                                         (U8 *)g_dm_fwu_context.http_url, 
                                         sizeof(g_dm_fwu_context.http_url)/ENCODING_LENGTH, 
                                         INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[DM_HTTP_IDX_URL], mmi_dm_fwu_set_full_scr_edit_lsk);

            /* [1] title */
            SetInlineItemCaption(&wgui_inline_items[DM_HTTP_IDX_PROFILE_TITLE], (U8 *)GetString(STR_ID_DM_HTTP_NETWORK));
            /* [1] item */
            SetInlineItemActivation(&wgui_inline_items[DM_HTTP_IDX_PROFILE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(&wgui_inline_items[DM_HTTP_IDX_PROFILE], g_dm_fwu_context.http_profile_sum, 
                                (U8 **) g_dm_fwu_context.http_profile_str_p, &g_dm_fwu_context.http_profile_index);
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
        default:
        {
            ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_ignore_settings
 * DESCRIPTION
 *  Ignore the modified settings and go-back-history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_ignore_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteScreenIfPresent(SCR_ID_DM_TFTP_SETTINGS);    
    DeleteScreenIfPresent(SCR_ID_DM_HTTP_SETTINGS);    
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_get_settings
 * DESCRIPTION
 *  Get settings
 * PARAMETERS
 *  scr_id      [IN]         screen id
 *  p           [OUT]        pointer to setting structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_get_settings(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S8 buffer[DM_TFTP_MAX_FILENAME_LEN+1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Read settings from NVRAM */
    switch (scr_id)
    {
    #if defined(__MMI_FWU_VIA_TFTP__)
        case DM_UPGRADE_TFTP:
        {
            nvram_ef_dm_fwu_tftp_setting_struct nvram_buf;    
            nvram_ef_dm_fwu_tftp_setting_struct *temp_setting = &nvram_buf;    

            memset(g_dm_fwu_context.tftp_server_name, 0, sizeof(g_dm_fwu_context.tftp_server_name));    
            memset(g_dm_fwu_context.tftp_port, 0, sizeof(g_dm_fwu_context.tftp_port));    
            memset(g_dm_fwu_context.tftp_da_name, 0, sizeof(g_dm_fwu_context.tftp_da_name));    
            memset(g_dm_fwu_context.full_filename_buffer, 0, sizeof(g_dm_fwu_context.full_filename_buffer));    
            
            ReadRecord(NVRAM_EF_DM_FWU_TFTP_SETTING_LID, 1, (void*)&nvram_buf, NVRAM_EF_DM_FWU_TFTP_SETTING_SIZE, &error);

            /* get server name */
            mmi_asc_to_ucs2((PS8) g_dm_fwu_context.tftp_server_name, (PS8)temp_setting->server_name);

            /* get port number */
            sprintf(buffer, "%d", temp_setting->port);
            mmi_asc_to_ucs2((PS8) g_dm_fwu_context.tftp_port, (PS8)buffer);

            /* get file name */
            mmi_ucs2cpy((PS8) g_dm_fwu_context.full_filename_buffer, (PS8) temp_setting->filename);

            /* get data account */
            g_dm_fwu_context.tftp_da_index = temp_setting->da_index;
            mmi_dtcnt_get_account_name((U8)temp_setting->da_index, (S8*)g_dm_fwu_context.tftp_da_name, (U8)sizeof(g_dm_fwu_context.tftp_da_name)/ENCODING_LENGTH); 
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
    #if defined(__MMI_FWU_VIA_HTTP__)
        case DM_UPGRADE_HTTP:
        {
            nvram_ef_dm_fwu_http_setting_struct nvram_buf;    
            nvram_ef_dm_fwu_http_setting_struct *temp_setting = &nvram_buf;    

            memset(g_dm_fwu_context.http_url, 0, sizeof(g_dm_fwu_context.http_url));    
            ReadRecord(NVRAM_EF_DM_FWU_HTTP_SETTING_LID, 1, (void*)&nvram_buf, NVRAM_EF_DM_FWU_HTTP_SETTING_SIZE, &error);

            /* get url */
            mmi_asc_to_ucs2((PS8) g_dm_fwu_context.http_url, (PS8)temp_setting->url);

            /* get profile index */
            g_dm_fwu_context.http_profile_index = (S32)temp_setting->profile_index;
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_set_settings
 * DESCRIPTION
 *  Set settings
 * PARAMETERS
 *  scr_id      [IN]            screen id
 *  P           [IN]            pointer to setting structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_set_settings(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S8 buffer[20];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    #if defined(__MMI_FWU_VIA_TFTP__)
        case DM_UPGRADE_TFTP:
        {
            U32 value;
            nvram_ef_dm_fwu_tftp_setting_struct nvram_buf;    
            nvram_ef_dm_fwu_tftp_setting_struct *temp_setting = &nvram_buf;    

            value = strlen((S8*) g_dm_fwu_context.tftp_server_name);
            if (value == 0)
            {
                DisplayPopup((PU8) GetString(STR_ID_DM_EMPTY_SERVERNAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                return;
            }

            value = mmi_ucs2strlen((S8*) g_dm_fwu_context.full_filename_buffer);
            if (value == 0)
            {
                DisplayPopup((PU8) GetString(STR_ID_DM_EMPTY_FILERNAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                return;
            }

            /* port number */
            mmi_ucs2_to_asc((S8*) buffer, (S8*) g_dm_fwu_context.tftp_port);
            value = (U32) atoi((S8*) buffer);
            if (value > 65535)
            {
                DisplayPopup((PU8) GetString(STR_ID_DM_INVALID_PORT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                return;
            }

            temp_setting->port = (U16) value;

            /* server name */    
            mmi_ucs2_to_asc((S8*) temp_setting->server_name, (S8*) g_dm_fwu_context.tftp_server_name);

            /* file name */
            mmi_ucs2cpy((PS8) temp_setting->filename, (PS8) g_dm_fwu_context.full_filename_buffer);

            /* data account index */
            temp_setting->da_index = g_dm_fwu_context.tftp_da_index;

            WriteRecord(NVRAM_EF_DM_FWU_TFTP_SETTING_LID, 1, (void*)&nvram_buf, NVRAM_EF_DM_FWU_TFTP_SETTING_SIZE, &error);
                    
            DeleteScreenIfPresent(SCR_ID_DM_TFTP_SETTINGS);
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
    #if defined(__MMI_FWU_VIA_HTTP__)
        case DM_UPGRADE_HTTP:
        {
            U8 len;
            nvram_ef_dm_fwu_http_setting_struct nvram_buf;    
            nvram_ef_dm_fwu_http_setting_struct *temp_setting = &nvram_buf;    

            len = strlen((S8*) g_dm_fwu_context.http_url);
            if (len == 0)
            {
                DisplayPopup((PU8) GetString(STR_ID_DM_EMPTY_SERVERNAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                return;
            }

            mmi_ucs2_to_asc((S8*) temp_setting->url, (S8*) g_dm_fwu_context.http_url);
            temp_setting->profile_index = (U8)g_dm_fwu_context.http_profile_index;

            WriteRecord(NVRAM_EF_DM_FWU_HTTP_SETTING_LID, 1, (void*)&nvram_buf, NVRAM_EF_DM_FWU_HTTP_SETTING_SIZE, &error);

            /* Pop-up Done */
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 
                UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
            
            DeleteScreenIfPresent(SCR_ID_DM_HTTP_SETTINGS);
            break;
        }
    #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_convert_result_code
 * DESCRIPTION
 *  Convert result code
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dm_fwu_convert_result_code(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result_code = DM_RESULT_CODE_GEN_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FWU_VIA_TFTP__)    
    if (g_dm_fwu_context.upgrade_media == DM_UPGRADE_TFTP)
    {
        switch (result)
        {
            case TFTP_SUCCESS:
                result_code = DM_RESULT_CODE_SUCCESS;
                break;
            case RMOT_ERROR_FILE_NOT_FOUND:
                result_code = DM_RESULT_CODE_FILE_NOT_FOUND;
                break;
            case RMOT_ERROR_ACCESS_VIOLATION:
                result_code = DM_RESULT_CODE_ACCESS_DENIED;
                break;
            case LOCAL_ERROR_SOC_ERROR:
                result_code = DM_RESULT_CODE_SOC_ERROR;
                break;
            case LOCAL_ERROR_TIMEOUT:
                result_code = DM_RESULT_CODE_TIMEOUT;
                break;
            default:
                result_code = DM_RESULT_CODE_SOC_ERROR;
                break;
        }
    }
    else 
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */   
#if defined(__MMI_FWU_VIA_HTTP__)
    if (g_dm_fwu_context.upgrade_media == DM_UPGRADE_HTTP)
    {
        switch (result)
        {
            case WPS_OK:
                result_code = DM_RESULT_CODE_SUCCESS;
                break;
            case WPS_ERROR_NOT_FOUND:
                result_code = DM_RESULT_CODE_FILE_NOT_FOUND;
                break;
            case WPS_ERROR_ACCESS_DENY:
                result_code = DM_RESULT_CODE_ACCESS_DENIED;
                break;
            default:
                result_code = DM_RESULT_CODE_SOC_ERROR;
                break;
        }    
    }
    else 
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
    if (g_dm_fwu_context.upgrade_media == DM_UPGRADE_FILE)
    {
    }
    else
    {
        ASSERT(0);
    }

    return result_code;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_send_msg
 * DESCRIPTION
 *  Send message to other modules
 *  
 *  PARAMETERS: mmiapi_device_play_req_struct *
 *  src_mod_id          [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 *****************************************************************************/
void mmi_dm_fwu_send_msg(U16 src_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = (oslMsgType) msg_id;         /* Type casting, to make compiler happer */
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = (oslModuleType) src_mod_id; /* Type casting, to make compiler happer */
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_fmt_fota_init_req
 * DESCRIPTION
 *  dm fmt fota init request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_fmt_fota_init_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_fwu_send_msg(MOD_FMT, MSG_ID_MMI_FMT_FOTA_INIT_REQ, (void*)NULL, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_fmt_fota_init_rsp
 * DESCRIPTION
 *  dm fmt fota init response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_fmt_fota_init_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_fota_init_rsp_struct *rsp_p = inMsg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == 0)
    {
        /* set state: auth */
        g_dm_fwu_context.state = DM_STATE_FOTA_AUTH;      

        switch(g_dm_fwu_context.upgrade_media)
        {
        #if defined(__MMI_FWU_VIA_TFTP__)    
            case DM_UPGRADE_TFTP:
            {
                /* get settings */
                mmi_dm_fwu_get_settings(DM_UPGRADE_TFTP);
        
                /* tftp start */
                mmi_dm_fwu_tftp_start_tftp_req();
                
                break;
            }
        #endif /* defined(__MMI_FWU_VIA_TFTP__)  */
        #if defined(__MMI_FWU_VIA_HTTP__)
            case DM_UPGRADE_HTTP:
            {
                /* get settings */
                mmi_dm_fwu_get_settings(DM_UPGRADE_HTTP);

                if (g_dm_fwu_context.http_profile_index == 0)  /* default */
                {
                   /* http start -- set channel */
                   mmi_dm_fwu_http_set_channel_req();
                }
                else
                {
                   /* http start -- get profile content */
                   mmi_dm_fwu_http_get_profile_content_req();
                }                
                break;
            }
        #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
            case DM_UPGRADE_FILE:
            {
                mmi_dm_fwu_file_download_to_phone();
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else
    {
        /* fails */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] fota init: %d", rsp_p->result);

        g_dm_fwu_context.general_result_code = (U8)DM_RESULT_CODE_AUTHENTICATION_FAIL;
        mmi_dm_fwu_entry_download_result();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_fmt_fota_write_data_req
 * DESCRIPTION
 *  dm fmt fota write data request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_fmt_fota_write_data_req(U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_fota_write_data_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (fmt_fota_write_data_req_struct*) OslConstructDataPtr(sizeof(fmt_fota_write_data_req_struct));

    msgReq->length = buffer_size; 
    msgReq->pkg_buffer = (void*)g_dm_fwu_context.buffer;
    
    mmi_dm_fwu_send_msg(MOD_FMT, MSG_ID_MMI_FMT_FOTA_WRITE_DATA_REQ, (void*)msgReq, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_fmt_fota_write_data_rsp
 * DESCRIPTION
 *  dm fmt fota write data response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_fmt_fota_write_data_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_fota_write_data_rsp_struct *rsp_p = inMsg;    
    S32 percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.state == DM_STATE_DOWNLOADING)
    {
        if (rsp_p->result == 0)
        {
            if (g_dm_fwu_context.total_size != 0 )
            {
                percentage = g_dm_fwu_context.cumul_size * 100 / g_dm_fwu_context.total_size;    
                mmi_dm_fwu_show_upgrade_percentage(percentage);
            }
            else
            {
                mmi_dm_fwu_show_upgrade_percentage(0);
            }
    
            switch(g_dm_fwu_context.upgrade_media)
            {
            #if defined(__MMI_FWU_VIA_TFTP__)    
                case DM_UPGRADE_TFTP:
                {
                    /* Send Received response to TFTP task */
                    mmi_dm_fwu_tftp_send_receive_rsp((void*)inMsg);    
                    break;
                }
            #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
            #if defined(__MMI_FWU_VIA_HTTP__)
                case DM_UPGRADE_HTTP:
                {
                    mmi_dm_fwu_http_read_content_req();
                    break;
                }
            #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
                case DM_UPGRADE_FILE:
                {
                    mmi_dm_fwu_file_download_to_phone();
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        else
        {
            /* error occurs */
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] fota write: %d", rsp_p->result);
            
            g_dm_fwu_context.state = DM_STATE_FOTA_AUTH_ERROR;
            
            switch(g_dm_fwu_context.upgrade_media)
            {
            #if defined(__MMI_FWU_VIA_TFTP__)    
                case DM_UPGRADE_TFTP:
                {
                    mmi_dm_fwu_tftp_stop_tftp_req();
                    break;
                }
            #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
            #if defined(__MMI_FWU_VIA_HTTP__)
                case DM_UPGRADE_HTTP:
                {
                    mmi_dm_fwu_http_unset_channel_req();
                    break;
                }
            #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
                case DM_UPGRADE_FILE:
                {
                    mmi_dm_fwu_file_abort_result();
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_fmt_fota_finalize_req
 * DESCRIPTION
 *  dm fmt fota finalize request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_fmt_fota_finalize_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_fwu_send_msg(MOD_FMT, MSG_ID_MMI_FMT_FOTA_FINALIZE_REQ, (void*)NULL, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_fmt_fota_finalize_rsp
 * DESCRIPTION
 *  dm fmt fota finalize response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_fmt_fota_finalize_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_fota_finalize_rsp_struct *rsp_p = inMsg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == 0)
    {
        mmi_dm_fwu_entry_upgrade_now_confirm();
        DeleteScreenIfPresent(SCR_ID_DM_UPGRADE_ANIMATION);
    }
    else
    {
        if (rsp_p->result != ERROR_FOTA_IMAGE_CHECKSUM)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] fota final: %d", rsp_p->result);
        
        g_dm_fwu_context.state = DM_STATE_FOTA_AUTH_ERROR;
    }
    else
    {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FOTA] fota final check sum: %d", rsp_p->result);

        g_dm_fwu_context.state = DM_STATE_FOTA_CHECKSUM_FAIL;
        }

        switch(g_dm_fwu_context.upgrade_media)
        {
        #if defined(__MMI_FWU_VIA_TFTP__)    
            case DM_UPGRADE_TFTP:
            {
        mmi_dm_fwu_tftp_stop_tftp_req();
                break;
            }
        #endif /* #if defined(__MMI_FWU_VIA_TFTP__) */
        #if defined(__MMI_FWU_VIA_HTTP__)
            case DM_UPGRADE_HTTP:
            {
                mmi_dm_fwu_http_unset_channel_req();
                break;
            }
        #endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
            case DM_UPGRADE_FILE:
            {
                mmi_dm_fwu_file_abort_result();
                break;
            }
            default:
            {
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_check_download_finish
 * DESCRIPTION
 *  dm fwu check download finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dm_fwu_check_download_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.state == DM_STATE_DOWNLOAD_FINISH_PENDING)
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
 *  mmi_dm_fwu_entry_download_finish_ind
 * DESCRIPTION
 *  entry download finish indication 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_fwu_entry_download_finish_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_fwu_entry_upgrade_now_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_fwu_is_busy
 * DESCRIPTION
 *  check if is in download procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dm_fwu_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_fwu_context.state != DM_STATE_INIT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* defined(__FOTA_ENABLE__) */

