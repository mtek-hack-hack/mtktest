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
 *  MyFavorite.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  My Favorite
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_MY_FAVORITE__


#include "ProtocolEvents.h"
#include "CommonScreens.h"

#include "wgui_datetime.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

#include "FileMgr.h"
#include "DateTimeType.h"
#include "DateTimeGProt.h"
#include "MainMenuDef.h"
#include "GpioInc.h"
#include "IdleAppProt.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "ProfileGprots.h"
#include "PhoneSetupGprots.h"
#include "PhoneBookGprot.h"
#include "ToDoListEnum.h"
#include "AlarmDef.h"
#include "SettingProfile.h"     /* error tone */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "fmt_struct.h"
#include "Fmt_main.h"
#include "CallManagementGProt.h"
#include "Conversions.h"
#include "MMIThemes.h"
#include "FactoryModeProt.h"
#include "mmiapi.h"
#include "wapadp.h"

#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#include "DRM_main.h"
#include "wap_ps_struct.h"
#include "app_mine.h"
#endif /* __DRM_SUPPORT__ */ 

#ifdef __OTG_ENABLE__
#include "otg_if.h"
#endif 

#ifdef __USB_IN_NORMAL_MODE__
#include "ExtDeviceDefs.h"
#include "USBDeviceGprot.h"
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __MMI_SWFLASH__
#include "SWFlashDef.h"
#include "SWFlashProt.h"
#endif /* __MMI_SWFLASH__ */ 

#ifdef __MMI_DOWNLOAD_AGENT__
#include "DLAgentDef.h"
#endif 

#include "FileManagerGProt.h"
#include "FileMgrStruct.h"
#include "FileManagerDef.h"
#include  "FunAndGamesDefs.h"

#if defined(__MMI_FWU_VIA_FILE__)
#ifdef __MTK_TARGET__
#include "DrvFlash.h"
#endif 
#include "custom_fota.h"
#endif /* defined(__MMI_FWU_VIA_FILE__) */ 

#ifdef __J2ME__
#include "JavaAgencyProt.h"
#endif 
#include "FunAndGamesProts.h"
#include "MyFavorite.h"
#include "MyFavoriteResDef.h"
#include "MyFavoriteGProt.h"

/******************************************************************/
/* Internal Variable */
/******************************************************************/
static S8 g_myfavorite_filepath[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];
static U16 g_myfavorite_fname[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void mmi_my_favorite_highlight_folder_open(void);
static void mmi_my_favorite_highlight_memorycard_format(void);

#ifdef __J2ME__
static void mmi_my_favorite_highlight_javabox_open(void);
static void mmi_my_favorite_highlight_javabox_setting(void);
static void mmi_my_favorite_highlight_javabox_security(void);
#endif /* __J2ME__ */ 
static void mmi_my_favorite_entry_memorycard_option(void);
static void mmi_my_favorite_entry_customized_folder_option(void);
static void mmi_my_favorite_entry_javabox_option(void);
static void mmi_my_favorite_entry_format_confirm(void);
static void mmi_my_favorite_entry_editor(void);
static void mmi_my_favorite_entry_editor_option(void);

static void mmi_my_favorite_open_folder_hdlr(void);
static void mmi_my_favorite_creat_folder_hdlr(void);

#ifdef WAP_SUPPORT
static void mmi_my_favorite_open_swflash_wap_hdlr(void);
static void mmi_my_favorite_open_java_wap_hdlr(void);
#endif /* WAP_SUPPORT */ 
static void mmi_my_favorite_format_memorycard_hdlr(void);
static void mmi_my_favorite_main_menu_highlight_hdlr(S32 index);

static pBOOL mmi_my_favorite_main_get_item_callback(
                S32 item_idx,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
static S32 mmi_my_favorite_main_get_hint_callback(S32 item_idx, UI_string_type *hint_array);
static void mmi_my_favorite_init_folder(const UI_string_type FolderName);

static void mmi_my_favorite_highlight_creat_folder(void);
static void mmi_my_favorite_highlight_input_method(void);
static void mmi_my_favorite_highlight_creat_done(void);
static void mmi_my_favorite_creat_folder(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_OPEN, mmi_my_favorite_highlight_folder_open);
    SetHiliteHandler(MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_CREAT_FOLDER, mmi_my_favorite_highlight_creat_folder);
    SetHiliteHandler(MENU_ID_MY_FAVORITE_MEMORY_CARD_FORMAT, mmi_my_favorite_highlight_memorycard_format);
#ifdef __J2ME__
    SetHiliteHandler(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_OPEN, mmi_my_favorite_highlight_javabox_open);
    SetHiliteHandler(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING, mmi_my_favorite_highlight_javabox_setting);
    SetHiliteHandler(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY, mmi_my_favorite_highlight_javabox_security);
#endif /* __J2ME__ */ 
    SetHiliteHandler(MENU_ID_MY_FAVORITE_EDITOR_DONE, mmi_my_favorite_highlight_creat_done);
    SetHiliteHandler(MENU_ID_MY_FAVORITE_INPUT_METHOD, mmi_my_favorite_highlight_input_method);

}

#ifdef __J2ME__


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_javabox_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_javabox_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryScrJavaMenu, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(EntryScrJavaMenu);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_javabox_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_javabox_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_fng_entry_setting_java_screen, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_fng_entry_setting_java_screen);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_javabox_security
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_javabox_security(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_fng_entry_secuiry_java, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_fng_entry_secuiry_java);
#endif 

}
#endif /* __J2ME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_folder_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_folder_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_my_favorite_open_folder_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_my_favorite_open_folder_hdlr);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_creat_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_creat_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_my_favorite_creat_folder_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_my_favorite_creat_folder_hdlr);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(EntryInputMethodScreen);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_creat_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_creat_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_my_favorite_creat_folder, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_my_favorite_creat_folder);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_return_to_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_return_to_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_highlight_memorycard_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_highlight_memorycard_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_my_favorite_entry_format_confirm, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(mmi_my_favorite_entry_format_confirm);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_open_folder_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_open_folder_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EntryNewScreen(SCR_MY_FAVORITE_MARKER, NULL, mmi_my_favorite_open_folder_hdlr, NULL); */
    FMGR_FILTER_SET_ALL(&filter);

    mmi_fmgr_select_path_and_enter(APP_MYFAVORITE, FMGR_SELECT_FILE_OR_FOLDER, filter, g_myfavorite_filepath, NULL);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_MEMORY_CARD_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_creat_folder_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_creat_folder_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus(g_myfavorite_filepath[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_DEVICE_BUSY_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;
    }
    
    fs_ret = FS_SetCurrentDir((PU16) g_myfavorite_filepath);

    if (fs_ret == FS_NO_ERROR)
    {
        memset(g_myfavorite_fname, 0, sizeof(g_myfavorite_fname));
        mmi_my_favorite_entry_editor();
    }
    else
    {
        DisplayPopup((PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
    }
    return;
}

#ifdef WAP_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_open_swflash_wap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_open_swflash_wap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)MY_FAVORITE_SWFLASH_URL);

    return;

}

#ifdef __J2ME__


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_open_java_wap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_open_java_wap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)MY_FAVORITE_JAVA_URL);

    return;

}
#endif /* __J2ME__ */ 

#endif /* WAP_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_format_memorycard_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_format_memorycard_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_send_format_req((U8) MMI_CARD_DRV, FS_FORMAT_HIGH, (PsFuncPtr) fmgr_drive_rsp_hdlr);

    entry_fmgr_drive_animation();

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_swflash_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_swflash_highlight_hdlr(S32 index)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_network_service_available() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
    {

        if (index == 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPEN, 0);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_my_favorite_back_to_main, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_open_swflash_wap_hdlr, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_my_favorite_back_to_main, KEY_EVENT_UP);

            return;
        }

        index--;
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
    }
#endif /* WAP_SUPPORT */ 

    highlight_fmgr_node(index);
    return;
}

#ifdef __J2ME__


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_javabox_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_javabox_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT
    if (mmi_bootup_is_network_service_available() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
    {

        if (index == 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPEN, 0);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_open_java_wap_hdlr, KEY_EVENT_UP);
            return;
        }
        else
        {
            index--;
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        }
    }
#endif /* WAP_SUPPORT */ 
    mmi_java_highlight_get_mids_index(index);
    return;
}

#endif /* __J2ME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_main_menu_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_main_menu_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
        case MY_FAVORITE_IMAGES:
            mmi_my_favorite_get_images_folder_path((S8*) g_myfavorite_filepath);
            SetKeyHandler(mmi_my_favorite_open_folder_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_entry_customized_folder_option, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            break;

        case MY_FAVORITE_AUDIO:
            mmi_my_favorite_get_audio_folder_path((S8*) g_myfavorite_filepath);
            SetKeyHandler(mmi_my_favorite_open_folder_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_entry_customized_folder_option, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            break;

        case MY_FAVORITE_VIDEO:
            mmi_my_favorite_get_video_folder_path((S8*) g_myfavorite_filepath);
            SetKeyHandler(mmi_my_favorite_open_folder_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_entry_customized_folder_option, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            break;

    #ifdef __J2ME__
        case MY_FAVORITE_JAVABOX:
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetKeyHandler(EntryScrJavaMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_entry_javabox_option, KEY_EVENT_UP);

            break;
    #endif /* __J2ME__ */ 

    #ifdef __MMI_SWFLASH__
        case MY_FAVORITE_SWFLASH:
            mmi_my_favorite_get_swflash_folder_path((S8*) g_myfavorite_filepath);
            SetKeyHandler(mmi_my_favorite_open_folder_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_entry_customized_folder_option, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            break;
    #endif /* __MMI_SWFLASH__ */ 

        case MY_FAVORITE_OTHERS:
            mmi_my_favorite_get_others_folder_path((S8*) g_myfavorite_filepath);
            SetKeyHandler(mmi_my_favorite_open_folder_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_entry_customized_folder_option, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            break;

        case MY_FAVORITE_MEMORYCARD:
            mmi_my_favorite_get_memory_card_path((S8*) g_myfavorite_filepath);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetKeyHandler(mmi_my_favorite_open_folder_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_my_favorite_entry_memorycard_option, KEY_EVENT_UP);

            break;
        default:
            break;

    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_entry_customized_folder_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_entry_customized_folder_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[2];
    U16 iconId;
    U16 ItemNum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTION,
        NULL,
        mmi_my_favorite_entry_customized_folder_option,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetParentHandler(MENU_ID_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTIONS);
    ItemNum = GetNumOfChild(MENU_ID_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTIONS);
    GetSequenceStringIds(MENU_ID_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTIONS, ItemList);
    mmi_my_favorite_get_folder_resource((const S8*)g_myfavorite_filepath, NULL, &iconId);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ItemNum,
        ItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_entry_javabox_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_entry_javabox_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[3];
    U16 ItemNum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MY_FAVORITE_JAVABOX_OPTION, NULL, mmi_my_favorite_entry_javabox_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MY_FAVORITE_JAVABOX_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetParentHandler(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS);
    ItemNum = GetNumOfChild(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS);
    GetSequenceStringIds(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS, ItemList);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_ID_MY_FAVORITE_TITLE_JAVABOX,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ItemNum,
        ItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_entry_memorycard_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_entry_memorycard_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[3];
    U16 iconId;
    U16 ItemNum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Entry Screen */

    EntryNewScreen(SCR_MY_FAVORITE_MEMORY_CARD_OPTION, NULL, mmi_my_favorite_entry_memorycard_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MY_FAVORITE_MEMORY_CARD_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetParentHandler(MENU_ID_MY_FAVORITE_MEMORY_CARD_OPTIONS);
    ItemNum = GetNumOfChild(MENU_ID_MY_FAVORITE_MEMORY_CARD_OPTIONS);
    GetSequenceStringIds(MENU_ID_MY_FAVORITE_MEMORY_CARD_OPTIONS, ItemList);
    mmi_my_favorite_get_folder_resource((const S8*)g_myfavorite_filepath, NULL, &iconId);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ItemNum,
        ItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_entry_format_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_entry_format_confirm()
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
        get_string(STR_FMGR_FORMAT),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_my_favorite_format_memorycard_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_entry_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 length = FMGR_MAX_FILE_LEN;
    U16 iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MY_FAVORITE_EDITOR, NULL, mmi_my_favorite_entry_editor, NULL);

    if (mmi_ucs2strlen((PS8) g_myfavorite_fname) >= length)
    {
        memset(&g_myfavorite_fname[(length - 1) << 1], 0, sizeof(g_myfavorite_fname) - ((length - 1) << 1));
    }

    guiBuffer = GetCurrGuiBuffer(SCR_MY_FAVORITE_EDITOR);
    mmi_my_favorite_get_folder_resource((const S8*)g_myfavorite_filepath, NULL, &iconId);

    ShowCategory5Screen(
        STR_GLOBAL_EDIT,
        iconId,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE),
        (PU8) g_myfavorite_fname,
        length,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_my_favorite_entry_editor_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_entry_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_entry_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem;
    U16 iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MY_FAVORITE_EDITOR_OPTION, NULL, mmi_my_favorite_entry_editor_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MY_FAVORITE_EDITOR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_ID_MY_FAVORITE_EDITOR_OPTION);
    GetSequenceStringIds(MENU_ID_MY_FAVORITE_EDITOR_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_MY_FAVORITE_EDITOR_OPTION);

    mmi_my_favorite_get_folder_resource((const S8*)g_myfavorite_filepath, NULL, &iconId);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(mmi_my_favorite_return_to_editor);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 count = MY_FAVORITE_MEMORYCARD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())       
    {
        DisplayPopup((PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    mmi_my_favorite_init_folder(MY_FAVORITE_IMAGES_FOLDER);
    mmi_my_favorite_init_folder(MY_FAVORITE_AUDIO_FOLDER);
    mmi_my_favorite_init_folder(MY_FAVORITE_VIDEO_FOLDER);
    mmi_my_favorite_init_folder(MY_FAVORITE_OTHERS_FOLDER);
#ifdef __MMI_SWFLASH__
    mmi_my_favorite_init_folder(MY_FAVORITE_SWFLASH_FOLDER);
#endif 

    EntryNewScreen(SCR_MY_FAVORITE_MAIN, NULL, mmi_my_favorite_entry_main, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MY_FAVORITE_MAIN);

    DeleteScreenIfPresent(SCR_MY_FAVORITE_MEMORY_CARD_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_JAVABOX_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);

    RegisterHighlightHandler(mmi_my_favorite_main_menu_highlight_hdlr);

    if (fmgr_is_msdc_present() != FALSE)
    {
        count++;
    }

    ShowCategory185Screen(
        STR_ID_MY_FAVORITE_MAIN,
        IMG_ID_MY_FAVORITE_MAIN,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        mmi_my_favorite_main_get_item_callback,
        mmi_my_favorite_main_get_hint_callback,
        0,
        KAL_TRUE,
        NULL,
        (U8*) guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_back_to_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_back_to_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_JAVABOX_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_MEMORY_CARD_OPTION);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);

    if (IsScreenPresent(SCR_MY_FAVORITE_MAIN))
    {
        GoBackToHistory(SCR_MY_FAVORITE_MAIN);
    }
    else
    {
        GoBackHistory();
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_init_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  FolderName      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_init_folder(const UI_string_type FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;
    UI_character_type FolderPath[30];
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) FolderPath, drv);
    mmi_ucs2cat((S8*) FolderPath, (const S8*)FolderName);

    file_handle = FS_Open(FolderPath, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle < 0)
    {
        result = FS_CreateDir(FolderPath);
    }
    else
    {
        FS_Close(file_handle);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_get_images_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_get_images_folder_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) path, drv);
    mmi_ucs2cat((S8*) path, (const S8*)MY_FAVORITE_IMAGES_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_get_audio_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_get_audio_folder_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) path, drv);
    mmi_ucs2cat((S8*) path, (const S8*)MY_FAVORITE_AUDIO_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_get_video_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_get_video_folder_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) path, drv);
    mmi_ucs2cat((S8*) path, (const S8*)MY_FAVORITE_VIDEO_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_get_others_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_get_others_folder_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) path, drv);
    mmi_ucs2cat((S8*) path, (const S8*)MY_FAVORITE_OTHERS_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_get_swflash_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_get_swflash_folder_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) path, drv);
    mmi_ucs2cat((S8*) path, (const S8*)MY_FAVORITE_SWFLASH_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_get_memory_card_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_get_memory_card_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) MMI_CARD_DRV);
    mmi_asc_to_ucs2((S8*) path, drv);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_main_get_item_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_idx            [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_my_favorite_main_get_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item_idx)
    {
        case MY_FAVORITE_IMAGES:
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_FOLDER_IMAGES)));
            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_FOLDER_IMAGES);
            break;

        case MY_FAVORITE_AUDIO:
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_FOLDER_AUDIO)));
            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_FOLDER_AUDIO);
            break;

        case MY_FAVORITE_VIDEO:
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_FOLDER_VIDEO)));
            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_FOLDER_VIDEO);
            break;

    #ifdef __J2ME__
        case MY_FAVORITE_JAVABOX:
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_FOLDER_JAVABOX)));
            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_FOLDER_JAVABOX);
            break;
    #endif /* __J2ME__ */ 
    #ifdef __MMI_SWFLASH__
        case MY_FAVORITE_SWFLASH:
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_FOLDER_SWFLASH)));
            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_FOLDER_SWFLASH);
            break;
    #endif /* __MMI_SWFLASH__ */ 

        case MY_FAVORITE_OTHERS:
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_FOLDER_OTHERS)));
            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_FOLDER_OTHERS);
            break;

        case MY_FAVORITE_MEMORYCARD:
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_FOLDER_MEMORY_CARD)));
            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_FOLDER_MEMORY_CARD);
            break;

        default:
            kal_prompt_trace(MOD_MMI, "item_idx = %d", item_idx);
            MMI_ASSERT(0);
            break;

    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_main_get_hint_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_idx        [IN]        
 *  hint_array      [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_my_favorite_main_get_hint_callback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_swflash_get_item_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_my_favorite_swflash_get_item_callback(
        S32 item_index,
        UI_string_type str_buff,
        PU8 *img_buff_p,
        U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }

    if (mmi_bootup_is_network_service_available() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
    {

    #ifdef WAP_SUPPORT
        if (item_index == 0)
        {
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_WAP_SWFLASH)));

            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_WAP_SWFLASH);

            return TRUE;
        }
        else
        {
            item_index--;

        }
    #endif /* WAP_SUPPORT */ 

    }

    mmi_fmgr_get_file_item_callback(item_index, str_buff, img_buff_p, str_img_mask);

    return TRUE;

}

#ifdef __J2ME__


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_javabox_get_item_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_my_favorite_javabox_get_item_callback(
        S32 item_index,
        UI_string_type str_buff,
        PU8 *img_buff_p,
        U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }

    if (mmi_bootup_is_network_service_available() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
    {

    #ifdef WAP_SUPPORT
        if (item_index == 0)
        {
            mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(STR_ID_MY_FAVORITE_WAP_JAVA)));

            *img_buff_p = (PU8) GetImage(IMG_ID_MY_FAVORITE_WAP_JAVABOX);

            return TRUE;
        }
        else
        {
            item_index--;
        }
    #endif /* WAP_SUPPORT */ 

    }
    mmi_java_fetch_mids_list(item_index, str_buff, img_buff_p, str_img_mask);

    return TRUE;

}

#endif /* __J2ME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_get_folder_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_path        [IN]        
 *  title           [?]         [?]
 *  icon            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_my_favorite_get_folder_resource(const S8 *src_path, U16 *title, U16 *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 judge_path[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_my_favorite_get_images_folder_path(judge_path);

    if (mmi_ucs2str((const PS8)src_path, (const PS8)judge_path) != NULL)
    {
        if (title != NULL)
        {
            *title = STR_ID_MY_FAVORITE_FOLDER_IMAGES;
        }
        if (icon != NULL)
        {
            *icon = IMG_ID_MY_FAVORITE_TITLE_IMAGES;
        }
        return TRUE;
    }

    mmi_my_favorite_get_audio_folder_path(judge_path);
    if (mmi_ucs2str((const PS8)src_path, (const PS8)judge_path) != NULL)
    {
        if (title != NULL)
        {
            *title = STR_ID_MY_FAVORITE_FOLDER_AUDIO;
        }
        if (icon != NULL)
        {
            *icon = IMG_ID_MY_FAVORITE_TITLE_AUDIO;
        }
        return TRUE;
    }

    mmi_my_favorite_get_video_folder_path(judge_path);
    if (mmi_ucs2str((const PS8)src_path, (const PS8)judge_path) != NULL)
    {
        if (title != NULL)
        {
            *title = STR_ID_MY_FAVORITE_FOLDER_VIDEO;
        }
        if (icon != NULL)
        {
            *icon = IMG_ID_MY_FAVORITE_TITLE_VIDEO;
        }
        return TRUE;
    }

    mmi_my_favorite_get_others_folder_path(judge_path);
    if (mmi_ucs2str((const PS8)src_path, (const PS8)judge_path) != NULL)
    {
        if (title != NULL)
        {
            *title = STR_ID_MY_FAVORITE_FOLDER_OTHERS;
        }
        if (icon != NULL)
        {
            *icon = IMG_ID_MY_FAVORITE_TITLE_OTHERS;
        }
        return TRUE;
    }
#ifdef __MMI_SWFLASH__
    mmi_my_favorite_get_swflash_folder_path(judge_path);
    if (mmi_ucs2str((const PS8)src_path, (const PS8)judge_path) != NULL)
    {
        if (title != NULL)
        {
            *title = STR_ID_MY_FAVORITE_FOLDER_SWFLASH;
        }
        if (icon != NULL)
        {
            *icon = IMG_ID_MY_FAVORITE_TITLE_SWFLASH;
        }
        return TRUE;
    }
#endif /* __MMI_SWFLASH__ */ 
    mmi_my_favorite_get_memory_card_path(judge_path);
    if (mmi_ucs2str((const PS8)src_path, (const PS8)judge_path) != NULL)
    {
        if (title != NULL)
        {
            *title = STR_ID_MY_FAVORITE_FOLDER_MEMORY_CARD;
        }
        if (icon != NULL)
        {
            *icon = IMG_ID_MY_FAVORITE_TITLE_MEMORY_CARD;
        }
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_javabox_waplink_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_my_favorite_javabox_waplink_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT
    if (mmi_bootup_is_network_service_available() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#else /* WAP_SUPPORT */ 
    return 0;
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_swflash_waplink_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_my_favorite_swflash_waplink_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT
    if (mmi_bootup_is_network_service_available() == TRUE && mmi_bootup_get_active_flight_mode() == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#else /* WAP_SUPPORT */ 
    return 0;
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_creat_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_my_favorite_creat_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr;
    S32 fs_ret, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = mmi_fmgr_skip_space((PS8) g_myfavorite_fname);
    len = mmi_ucs2strlen(ptr);

    if (len == 0 || ptr[0] == '.')
    {
        if (ptr[0] == '.')
        {

            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        }
        else
        {

            DisplayPopup((PU8) GetString(STR_FMGR_EMPTY_FILENAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR);
        DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);
        return;
    }

    /* new file name can't contain '/' or '\' */
    while (len > 0)
    {
        len--;
        if ((ptr[len << 1] == '/' && ptr[(len << 1) + 1] == 0) || (ptr[len << 1] == '\\' && ptr[(len << 1) + 1] == 0))
        {
            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR);
            DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);
            return;
        }
    }

    if (mmi_ucs2strlen((PS8) g_myfavorite_filepath) + mmi_ucs2strlen(ptr) + 1 >= FMGR_MAX_PATH_LEN - 11)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);
        return;
    }

    fs_ret = FS_SetCurrentDir((PU16) g_myfavorite_filepath);

    if (fs_ret == FS_NO_ERROR)
    {
        fs_ret = FS_CreateDir((PU16) ptr);

        if (fs_ret == FS_NO_ERROR)
        {
            /* success */
            DeleteScreenIfPresent(SCR_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTION);
            DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR);
            DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);
            mmi_my_favorite_open_folder_hdlr();
            return;
        }
    }
    /* fail */
    DisplayPopup((PU8) GetString(GetFileSystemErrorString(fs_ret)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR);
    DeleteScreenIfPresent(SCR_MY_FAVORITE_EDITOR_OPTION);

}

#endif /* __MMI_MY_FAVORITE__ */ 

