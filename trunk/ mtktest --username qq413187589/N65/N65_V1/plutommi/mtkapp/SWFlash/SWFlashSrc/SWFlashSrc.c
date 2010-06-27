/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * SWFlashSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_SWFLASH__
#ifdef SWFLASH_CHAOTEX

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "MainMenuDef.h"
#include "SettingProfile.h"

/* Mime type */
#include "app_mine.h"

/* File and Memory */
#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "rtfiles.h"
#include "med_smalloc.h"

/* Data Account */
#include "DataAccountGProt.h"
#include "DataAccountDef.h"
#include "wapadp.h"
#include "wap_ps_struct.h"

/* MDI */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_swflash.h"
#include "mdi_include.h"

/* NVRAM */

/* mmi_chset */
#include "Conversions.h"

/* Setting */
#include "SettingDefs.h"

/* Download Agent */
#include "DLAgentResDef.h"
#include "SettingProfile.h"

/* Silent or Meeting Mode */
#include "ProfileGprots.h"

/* LED */
#include "gpioInc.h"            

/*sim card*/
#include "simDetectionGprot.h"


#ifdef __MMI_TOUCH_SCREEN__
/* under construction ! */
#endif 

/* SWFlash */
#include "SWFlashGProt.h"
#include "SWFlashProt.h"
#include "SWFlashDef.h"

static S32 mmi_swflash_create_phone_folder(void);
static void mmi_swflash_wivg_render(dm_coordinates *coordinate);
static void mmi_swflash_percentage_endkey_abort_hdlr(void);
static void mmi_swflash_play_callback(MDI_RESULT result);
static S32 mmi_swflash_create_card_folder(void);
void mmi_swflash_setting_enter(void);
void mmi_swflash_setting_enter_callback(void);
void mmi_swflash_dl_result_callback(MDI_RESULT ret);
void mmi_swflash_dl_progress_callback(S32 dl_size, S32 total_size);
void mmi_swflash_receive_cmp_file(void);

#define MAX_FILE_NAME_LEN (261)
#define MAX_FULL_NAME_LEN (MAX_PATH_LEN+MAX_FILE_NAME_LEN)
#define SWFLASH_KEY_NUMBER (17)


/***************************************************************************** 
* Local Variable
*****************************************************************************/
typedef struct
{
    U8 percentage;
    U8 storage;
    U8 nwk_account_id;
    U8 volume;
    U8 is_load_setting;

    S16 layer_offset_x;
    S16 layer_offset_y;
    S16 layer_width;
    S16 layer_height;

    gdi_handle swflash_play_layer;
    gdi_handle swflash_base_layer;

    S32 da_mime_subtype;
    U16 da_file_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];

    /* drives and paths */
    UI_character_type swflash_phone_root_dir[4];
    UI_character_type swflash_card_root_dir[4];
    UI_character_type swflash_phone_list_dir[6][FMGR_MAX_FILE_LEN + 4]; /* swflash /animation/game/karaok/
                                                                           extent function/other */
    UI_character_type swflash_card_list_dir[6][FMGR_MAX_FILE_LEN + 4];
    UI_character_type swflash_cmp_full_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];

    MMI_BOOL dl_resume;

} swflash_context_struct;

static swflash_context_struct g_swflash_cntx;
static S8 *g_swflash_printable_str = NULL;

/***************************************************************************** 
* Extern Variable
*****************************************************************************/
extern mdi_swflash_info_struct wgui_swflash_info;

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_init_app
 * DESCRIPTION
 *  init video player applcation, register highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init video player application highlight handler */
#ifdef __MMI_SWFLASH_SERERATE_ENTRY__
    SetHiliteHandler(SERVICES_SWFLASH_MENU_ID, mmi_swflash_highlight_main);
#endif 
    /* init phone drive, card drive, phone dir and card dir */
    mmi_swflash_get_fs_info();
    g_swflash_cntx.is_load_setting = FALSE;
    mdi_swflash_set_is_from_player(MMI_FALSE);
    cim_set_text_layer(GDI_LAYER_EMPTY_HANDLE, NULL);
    mmi_swflash_load_setting();
}

#ifdef __MMI_SWFLASH_SEPERATE_ENTRY__


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_main
 * DESCRIPTION
 *  Highlight handler of SWFlash menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_entry_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_swflash_entry_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_entry_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;
    U16 nDispAttribute;
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SWFLASH_APP, mmi_swflash_exit_screen, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SWFLASH_APP);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_ID_SWFLASH_APP);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_SWFLASH_APP);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_ID_SWFLASH_APP, (PU16) nStrItemList);

    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_ID_SWFLASH_APP);

    /* 7. Register highlight handler to be called in menu screen */
    SetHiliteHandler(MENU_ID_SWFLASH_MONTERNET, mmi_swflash_highlight_monternet);
    SetHiliteHandler(MENU_ID_SWFLASH_LIST, mmi_swflash_highlight_list);
    SetHiliteHandler(MENU_ID_SWFLASH_SETTING, mmi_swflash_highlight_setting);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8. Display Category15 Screen */
    ShowCategory15Screen(
        STR_ID_SWFLASH_APP,
        IMG_ID_SWFLASH_APP2,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        (PU16) nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* load setting to get the current storage */
    mmi_swflash_load_setting();

    /* 9. Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_SWFLASH_APP;
    h.entryFuncPtr = mmi_swflash_entry_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_monternet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_monternet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_monternet_visit, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_list_content, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_setting_enter, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_list_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_list_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if card drive, check if card inserted */
    if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
    {
        if (!mmi_swflash_is_card_ready())
        {
            g_swflash_cntx.storage = MMI_SWFLASH_STORAGE_PHONE;
            mmi_swflash_store_setting();
        }
    }

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_CMP);

    mmi_fmgr_select_path_and_enter(
        APP_SWFLASH,
        FMGR_SELECT_BROWSE,
        filter,
        (PS8) (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE ? g_swflash_cntx.swflash_phone_list_dir[0] : g_swflash_cntx.swflash_card_list_dir),
        mmi_swflash_filename_callback);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_filename_callback
 * DESCRIPTION
 *  Callback function from file manaegr
 * PARAMETERS
 *  fullname        [?]         [?]         (Full path name of the file )
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_filename_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type filefullname[FMGR_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fullname == NULL)
    {
        GoBackHistory();
    }
    else if (is_short)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (PU8) filefullname,
            (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
            (PU8) fullname,
            g_chset_text_encoding);
    }
    else
    {
        mmi_ucs2cpy((PS8) filefullname, (PS8) fullname);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_option_play
 * DESCRIPTION
 *  Highlight handler of SWFlash menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_option_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_option_play_entry_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_swflash_option_play_entry_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_option_info
 * DESCRIPTION
 *  Highlight handler of SWFlash menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_option_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_option_info_entry_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_swflash_option_info_entry_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_option_download
 * DESCRIPTION
 *  Highlight handler of SWFlash menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_option_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_option_download, KEY_EVENT_UP);
    SetKeyHandler(mmi_swflash_option_download, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_SWFLASH_SEPERATE_ENTRY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_monternet_visit
 * DESCRIPTION
 *  visist the fixed url to access waps containing swflash works 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_monternet_visit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)L"http://masstraining.chaotex.com/test/plist.asp");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_menuId
 * DESCRIPTION
 *  Callback function from file manaegr
 * PARAMETERS
 *  filename        [?]         
 *  forward         [IN]        
 *  fullname        [?]         (Full path name of the file )(?)
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_swflash_get_menuId(void *filename, MMI_BOOL forward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type filefullname[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];
    MDI_RESULT ret;
    U32 total_len = 0;
    U32 current_len = 0;
    U32 category = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* filefullname passed from FileMgr is full file name, path included */
        
    mmi_ucs2cpy((PS8) filefullname, (PS8) filename);

    ret = mdi_swflash_check_download_file((U16*) filefullname, &total_len, &current_len, &category);

    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        return MITEM_FMGR_GEN_TYPE_NO_SIM_OPTIONS;
    }

    if (total_len > 0)
    {
        if (current_len < total_len)
        {
            mmi_ucs2cpy((S8*) g_swflash_cntx.swflash_cmp_full_path, (S8*) filefullname);

            if ((mmi_bootup_get_active_flight_mode()==MMI_TRUE)||(mmi_bootup_is_sim_valid()==MMI_FALSE))
            {   
                return MENU_ID_SWFLASH_OPTION2_FLIGHT;
            }
            else
            {
            return MENU_ID_SWFLASH_OPTION2;
        }
        }
        else if (current_len == total_len)
        {
            /* can be used for playback */
            mmi_ucs2cpy((S8*) g_swflash_cntx.swflash_cmp_full_path, (S8*) filefullname);
            if (forward == MMI_TRUE)
            {
                return MENU_ID_SWFLASH_OPTION1;
            }
            else
            {
                return MENU_ID_SWFLASH_OPTION1_NO_FORWARD;
            }
        }
        else
        {
            return MITEM_FMGR_GEN_TYPE_NO_SIM_OPTIONS;
        }
    }
    else
    {
        return MITEM_FMGR_GEN_TYPE_NO_SIM_OPTIONS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_category
 * DESCRIPTION
 *  Callback function from file manaegr
 * PARAMETERS
 *  filename        [?]     
 *  downloaded      [?]     
 *  fullname        [?]         (Full path name of the file )(?)
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_swflash_get_category(void *filename, S32 *downloaded)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    U32 total_len = 0;
    U32 current_len = 0;
    U32 category = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* filefullname passed from FileMgr is full file name */
    ret = mdi_swflash_check_download_file((U16*) filename, &total_len, &current_len, &category);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        *downloaded = 0;
        return 0;
    }

    if (total_len > 0)
    {
        if (current_len < total_len)
        {
            *downloaded = 0;
            return category;
        }
        else if (current_len == total_len)
        {
            *downloaded = 1;
            return category;
        }
        else
        {
            *downloaded = 0;
            return category;
        }
    }
    else
    {
        *downloaded = 0;
        return category;
    }

    *downloaded = 0;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_key_down
 * DESCRIPTION
 *  set_key down handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mdi_swflash_key_down_event(Keycode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_key_up
 * DESCRIPTION
 *  set_key up handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mdi_swflash_key_up_event(Keycode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_set_key_handle
 * DESCRIPTION
 *  set_key_handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_set_key_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 swFlashScreenDigits[SWFLASH_KEY_NUMBER] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
        KEY_6,KEY_7, KEY_8, KEY_9, KEY_UP_ARROW,KEY_DOWN_ARROW,KEY_RIGHT_ARROW,KEY_LEFT_ARROW,
        KEY_BACK,KEY_ENTER,KEY_SEND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    SetGroupKeyHandler(mmi_swflash_key_down, swFlashScreenDigits, SWFLASH_KEY_NUMBER, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_swflash_key_up, swFlashScreenDigits, SWFLASH_KEY_NUMBER, KEY_EVENT_UP);
}

#ifdef __MMI_TOUCH_SCREEN__
static void mmi_swflash_pen_down_hdlr(mmi_pen_point_struct pos){mdi_swflash_pen_down_event(pos.x,pos.y);}
static void mmi_swflash_pen_up_hdlr(mmi_pen_point_struct pos){mdi_swflash_pen_up_event(pos.x,pos.y);}
static void mmi_swflash_pen_move_hdlr(mmi_pen_point_struct pos){mdi_swflash_pen_move_event(pos.x,pos.y);}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_set_file_full_path
 * DESCRIPTION
 *  set the file full path 
 * PARAMETERS
 *  path:the folder path 
 *  filename: the file name(not the full name)
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_swflash_set_file_full_path(const S8 *path,const S8 * filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

      mmi_ucs2cpy((PS8)g_swflash_cntx.swflash_cmp_full_path,path); 
      mmi_ucs2cat((PS8) g_swflash_cntx.swflash_cmp_full_path, (PS8) filename);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_sms_interrupt_hdlr
 * DESCRIPTION
 *  the preprocess function of sms interrupt
 * PARAMETERS
 *  inMsg: the message come from framework
 * RETURNS
 *  void
 *****************************************************************************/

static U8 mmi_swflash_sms_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_OFF);
    return FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_post_interrupt_hdlr
 * DESCRIPTION
 *  the post function of sms interrupt
 * PARAMETERS
 *  inMsg:the message come from framework
 * RETURNS
 *  void
 *****************************************************************************/

static U8 mmi_swflash_post_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_ON);
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_entry_screen
 * DESCRIPTION
 *  the entry function of swflash play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_set_is_from_player(MMI_TRUE);

    /* stop lcd sleep */
    TurnOnBacklight(0);
    /* stop LED patten */
    StopLEDPatternBackGround();
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
    ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, CIM_PLAYERMODE, &wgui_swflash_info);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_SWFLASH_OPTION_PLAY, mmi_swflash_option_play_exit_screen, NULL, NULL);

    ShowCategory227Screen(
        (PU8) GetString(STR_ID_SWFLASH_PLAYBACK),
        IMG_ID_SWFLASH_APP2,
        STR_ID_SWFLASH_PAUSE,
        0,
        STR_ID_SWFLASH_STOP,
        0,
        mmi_swflash_wivg_render);

    /* pause sound */
    mdi_audio_suspend_background_play();
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    if (g_swflash_cntx.volume == 0)
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
    }

    /* create swflash layer on layer 1 */
    gdi_layer_multi_layer_enable();
    ASSERT(g_swflash_cntx.swflash_play_layer == NULL);
    g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    gdi_layer_create(
        g_swflash_cntx.layer_offset_x,
        g_swflash_cntx.layer_offset_y,
        g_swflash_cntx.layer_width,
        g_swflash_cntx.layer_height,
        &g_swflash_cntx.swflash_play_layer);
    ASSERT(g_swflash_cntx.swflash_play_layer != NULL);

    gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    gdi_layer_get_base_handle(&g_swflash_cntx.swflash_base_layer);
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, g_swflash_cntx.swflash_play_layer, 0, 0);

    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, 0, mmi_swflash_play_callback);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, 2000, (U8) ERROR_TONE);
        return;
    }
  
    /*for interaction*/
    mmi_swflash_set_key_handle();

#ifdef __MMI_TOUCH_SCREEN__
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* 9. Register function with right softkey */
    SetKeyHandler(mmi_swflash_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_swflash_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_swflash_option_play_pause, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);

    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS, 
        mmi_swflash_sms_interrupt_hdlr,
        mmi_swflash_post_interrupt_hdlr);	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play2_entry_screen
 * DESCRIPTION
 *  the reenry function of swflash play,mainly for the re-entry of interrupted 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play2_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_set_is_from_player(MMI_TRUE);
    /* stop lcd sleep */
    TurnOnBacklight(0);
    /* stop LED patten */
    StopLEDPatternBackGround();
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    EntryNewScreen(SCR_ID_SWFLASH_OPTION_PLAY, mmi_swflash_option_play_exit_screen, NULL, NULL);

    ShowCategory227Screen(
        (PU8) GetString(STR_ID_SWFLASH_PLAYBACK),
        IMG_ID_SWFLASH_APP2,
        STR_ID_SWFLASH_PLAY,
        0,
        STR_GLOBAL_BACK,
        0,
        mmi_swflash_wivg_render);

    /* pause sound */
    mdi_audio_suspend_background_play();
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    if (g_swflash_cntx.volume == 0)
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
    }

    /* create swflash layer on layer 1 */
    gdi_layer_multi_layer_enable();
    ASSERT(g_swflash_cntx.swflash_play_layer == NULL);
    g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    gdi_layer_create(
        g_swflash_cntx.layer_offset_x,
        g_swflash_cntx.layer_offset_y,
        g_swflash_cntx.layer_width,
        g_swflash_cntx.layer_height,
        &g_swflash_cntx.swflash_play_layer);
    gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_layer_get_base_handle(&g_swflash_cntx.swflash_base_layer);
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, g_swflash_cntx.swflash_play_layer, 0, 0);

    ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, CIM_PLAYERMODE, &wgui_swflash_info);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }

    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, 0xFF, mmi_swflash_play_callback);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, 2000, (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }
    /*for interaction*/
    mmi_swflash_set_key_handle();
 
#ifdef __MMI_TOUCH_SCREEN__
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* 9. Register function with right softkey */
    SetKeyHandler(mmi_swflash_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_swflash_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_swflash_option_play_play, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS, 
        mmi_swflash_sms_interrupt_hdlr,
        mmi_swflash_post_interrupt_hdlr);   

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_exit_screen
 * DESCRIPTION
 *  the exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop playback */
    mdi_swflash_set_is_from_player(MMI_FALSE);
    mdi_swflash_stop();

    /* free swflash layer */
    if (g_swflash_cntx.swflash_play_layer != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    }

    /*free text layer*/
    mdi_swflash_free_text_layer();
   
    /*free resource*/
    mdi_swflash_close_file();
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, 0, 0, 0);
    gdi_layer_multi_layer_disable();

    /* resume audio */
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    mdi_audio_start_background_timer();
    mdi_audio_resume_background_play();

    TurnOffBacklight();
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* stop LED patten */
    StartLEDPatternBackGround();
    
    h.scrnID = SCR_ID_SWFLASH_OPTION_PLAY;
    h.entryFuncPtr = mmi_swflash_option_play2_entry_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);

    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_played
 * DESCRIPTION
 *  the state of played
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_played(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_ID_SWFLASH_PAUSE, 0);
    ChangeRightSoftkey(STR_ID_SWFLASH_STOP, 0);

    /* 9. Register function with right softkey */
    SetLeftSoftkeyFunction(mmi_swflash_option_play_pause, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_play
 * DESCRIPTION
 *  the function of play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, MDI_DEVICE_SPEAKER_BOTH, mmi_swflash_play_callback);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, 2000, (U8) ERROR_TONE);
    }
#ifdef __MMI_TOUCH_SCREEN__
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_paused
 * DESCRIPTION
 *  the state of pause
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_paused(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_ID_SWFLASH_RESUME, 0);
    ChangeRightSoftkey(STR_ID_SWFLASH_STOP, 0);

    /* 9. Register function with right softkey */
    SetLeftSoftkeyFunction(mmi_swflash_option_play_resume, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_pause
 * DESCRIPTION
 *  the function of pause
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_pause();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, 2000, (U8) ERROR_TONE);
    }
#ifdef __MMI_TOUCH_SCREEN__

    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_stopped
 * DESCRIPTION
 *  the state of stopped
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_stopped(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_ID_SWFLASH_PLAY, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
  
	DeleteUptoScrID(SCR_FMGR_EXPLORER);
    /* 9. Register function with right softkey */
    SetLeftSoftkeyFunction(mmi_swflash_option_play_play, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_stop
 * DESCRIPTION
 *  the function of stop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_stop();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, 2000, (U8) ERROR_TONE);
    }

#ifdef __MMI_TOUCH_SCREEN__
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_resumed
 * DESCRIPTION
 *  the state of resumed (played)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_resumed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_ID_SWFLASH_PAUSE, 0);
    ChangeRightSoftkey(STR_ID_SWFLASH_STOP, 0);

    /* 9. Register function with right softkey */
    SetLeftSoftkeyFunction(mmi_swflash_option_play_pause, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_resume
 * DESCRIPTION
 *  the function of resume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_resume();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, 2000, (U8) ERROR_TONE);
    }

#ifdef __MMI_TOUCH_SCREEN__
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
    /* under construction ! */
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_press_inc_volume
 * DESCRIPTION
 *  increase volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_press_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int silent = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* XXX magic number 7 */
#ifdef __MMI_SILENT_MEETING_PROFILE__
    silent = IsSilentModeActivated() || IsMeetingModeActivated();
#else 
    silent = IsSilentModeActivated();
#endif 

    if (!silent && g_swflash_cntx.volume < 6)
    {
        S16 error;

        if (g_swflash_cntx.volume == 0)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, FALSE);
            g_swflash_cntx.volume++;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }
        else
        {
            g_swflash_cntx.volume++;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }
        WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_press_dec_volume
 * DESCRIPTION
 *  depress the volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_press_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int silent = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SILENT_MEETING_PROFILE__
    silent = IsSilentModeActivated() || IsMeetingModeActivated();
#else 
    silent = IsSilentModeActivated();
#endif 

    if (!silent && g_swflash_cntx.volume > 0)
    {
        S16 error;

        if (g_swflash_cntx.volume == 1)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
            g_swflash_cntx.volume--;
        }
        else
        {
            g_swflash_cntx.volume--;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }

        WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_transform_cmp_info
 * DESCRIPTION
 *  store the attribute of works to screen string buffer 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_transform_cmp_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(g_swflash_printable_str, 0, sizeof(g_swflash_printable_str));

    if (wgui_swflash_info.title != NULL)
    {
        mmi_ucs2cat(g_swflash_printable_str, (PS8) wgui_swflash_info.title);
    }

    mmi_ucs2cat(g_swflash_printable_str, (PS8) L"\n");
    mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY));

    switch (wgui_swflash_info.category)
    {
            /* */
        case 1:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_SCRSAVER));
            break;
        case 2:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_ANIMATION));
            break;
        case 3:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_CRAZYGAME));
            break;
        case 4:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_CARDSHOW));
            break;
        case 5:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_KARAOK));
            break;
        case 6:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_HOTMV));
            break;
        case 7:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_MOVIECLIP));
            break;
        case 8:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_MOBILEINFO));
            break;
        case 9:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_RECREATION));
            break;
        default:
            mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
            mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_UNKNOWN));
            break;
    }

    mmi_ucs2cat(g_swflash_printable_str, (PS8) L"\n");
    mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_SIZE));

    {
        S8 swflash_size[10];

        mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
        sprintf(swflash_size, "%u", wgui_swflash_info.size);
        mmi_asc_to_ucs2(
            (PS8) & g_swflash_printable_str[mmi_ucs2strlen((PS8) g_swflash_printable_str) << 1],
            (PS8) swflash_size);
        mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
        mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_BYTE));
    }

    mmi_ucs2cat(g_swflash_printable_str, (PS8) L"\n");
    mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_DATE));

    if (wgui_swflash_info.date != NULL)
    {
        mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
        mmi_ucs2cat(g_swflash_printable_str, (PS8) wgui_swflash_info.date);
    }

    mmi_ucs2cat(g_swflash_printable_str, (PS8) L"\n");
    mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_TIME));

    if (wgui_swflash_info.time != NULL)
    {
        mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
        mmi_ucs2cat(g_swflash_printable_str, (PS8) wgui_swflash_info.time);
    }

    mmi_ucs2cat(g_swflash_printable_str, (PS8) L"\n");
    mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_AUTHOR));

    if (wgui_swflash_info.author != NULL)
    {
        mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
        mmi_ucs2cat(g_swflash_printable_str, (PS8) wgui_swflash_info.author);
    }

    mmi_ucs2cat(g_swflash_printable_str, (PS8) L"\n");
    mmi_ucs2cat(g_swflash_printable_str, (PS8) GetString(STR_ID_SWFLASH_INFO_COMPANY));

    if (wgui_swflash_info.company != NULL)
    {
        mmi_ucs2cat(g_swflash_printable_str, (PS8) L" ");
        mmi_ucs2cat(g_swflash_printable_str, (PS8) wgui_swflash_info.company);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_continue_confirm
 * DESCRIPTION
 *  confirm whether to continue downloading 
 * PARAMETERS
 *  void
 *  ret(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_dl_continue_confirm(void)
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
        get_string(STR_ID_SWFLASH_ASK_DOWNLOAD2),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_swflash_option_download, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_info_entry_screen
 * DESCRIPTION
 *  entry function of swflash info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_info_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* QB-E-001-2005, section 6.4.1                                   */
    /* title: Name of content                                         */
    /* category: Animation, KaraOk, Game and so                       */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, CIM_SCREENMODE, &wgui_swflash_info);
    if (ret == MDI_RES_SWFLASH_SUCCEED)
    {
        media_get_ext_buffer(MOD_MMI, (void **)&g_swflash_printable_str, 1000);
        mmi_swflash_transform_cmp_info();
        mdi_swflash_close_file();
        EntryNewScreen(SCR_ID_SWFLASH_OPTION_INFO, mmi_swflash_option_info_exit_screen, NULL, NULL);

        /* 8. Display Category74 Screen */
        ShowCategory74Screen(
            STR_ID_SWFLASH_OPTION_INFO,
            IMG_ID_SWFLASH_APP2,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) g_swflash_printable_str,
            mmi_ucs2strlen((PS8) g_swflash_printable_str),
            NULL);

        /* 9. Register function with right softkey */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        mdi_swflash_close_file();
		if(wgui_swflash_info.curlen<wgui_swflash_info.size)
        {      
        mmi_swflash_dl_continue_confirm();
    }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_info_exit_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_info_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_SWFLASH_OPTION_INFO;
    h.entryFuncPtr = mmi_swflash_option_info_entry_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
    if (g_swflash_printable_str != NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_swflash_printable_str);
        g_swflash_printable_str = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_download
 * DESCRIPTION
 *  the entry function of download menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_len;
    U32 current_len;
    U32 category;
    MDI_RESULT ret = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* download process is required */
  
    /*check the downloaded length*/
    ret=mdi_swflash_check_download_file((U16*) g_swflash_cntx.swflash_cmp_full_path, &total_len, &current_len, &category);

    if(ret == MDI_RES_SWFLASH_SUCCEED)
    {
    g_swflash_cntx.percentage = current_len * 100 / total_len;

    /*get the current network acount id*/
        g_swflash_cntx.nwk_account_id=14;

    /*begin to download*/
        ret=mdi_swflash_start_download_file(
        (PS8) g_swflash_cntx.swflash_cmp_full_path, /* partial cmp file */
        (PS8) g_swflash_cntx.swflash_cmp_full_path, /* result cmp file */
        g_swflash_cntx.nwk_account_id,
        mmi_swflash_dl_result_callback,
        mmi_swflash_dl_progress_callback);

    /*enry the procees bar depend on g_swflash_cntx.percentage*/
        if(ret==MDI_RES_SWFLASH_SUCCEED)
        {
            g_swflash_cntx.dl_resume = MMI_TRUE;
    mmi_swflash_percentage_bar_entry_screen();
}
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_SWFLASH_NOTIFY_FILE_ERROR),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);

        DeleteUptoScrID(SCR_FMGR_EXPLORER);

    }
}
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_SWFLASH_NOTIFY_FILE_ERROR),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);

        DeleteUptoScrID(SCR_FMGR_EXPLORER);

    }
}

#ifdef __MMI_SWFLASH_SEPERATE_ENTRY__


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_setting_enter
 * DESCRIPTION
 *  the entry of data acount setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_setting_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataAccountReadyCheck(mmi_swflash_setting_enter_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_setting_enter_callback
 * DESCRIPTION
 *  callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_setting_enter_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_swflash_setting_entry_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_setting_entry_screen
 * DESCRIPTION
 *  the entry function of setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_setting_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;
    U16 nDispAttribute;
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SWFLASH_SETTING, mmi_swflash_setting_exit_screen, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SWFLASH_SETTING);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_ID_SWFLASH_SETTING);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_SWFLASH_SETTING);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_ID_SWFLASH_SETTING, (PU16) nStrItemList);

    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_ID_SWFLASH_SETTING);

    /* 7. Register highlight handler to be called in menu screen */
    SetHintHandler(MENU_ID_SWFLASH_SETTING_STORAGE, mmi_swflash_hint_storage);
    SetHintHandler(MENU_ID_SWFLASH_SETTING_DATACNT, mmi_swflash_hint_datacnt);
    SetHiliteHandler(MENU_ID_SWFLASH_SETTING_STORAGE, mmi_swflash_highlight_storage);
    SetHiliteHandler(MENU_ID_SWFLASH_SETTING_DATACNT, mmi_swflash_highlight_datacnt);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8. Display Category15 Screen */
    for (i = 0; i < nNumofItem; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_SWFLASH_SETTING, PopUpList);

    ShowCategory52Screen(
        STR_ID_SWFLASH_SETTING,
        IMG_ID_SWFLASH_APP2,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        (PU16) nStrItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        LIST_MENU,
        0,
        guiBuffer);

    /* 9. Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_setting_exit_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_setting_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_SWFLASH_SETTING;
    h.entryFuncPtr = mmi_swflash_setting_entry_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_hint_storage
 * DESCRIPTION
 *  hint storage
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_swflash_hint_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (S8*) hintData[index],
        (S8*) GetString((U16) (STR_ID_SWFLASH_STORAGE_PHONE + g_swflash_cntx.storage)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_hint_datacnt
 * DESCRIPTION
 *  datacnt hint
 * PARAMETERS
 *  index       [IN]        Storage id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_hint_datacnt(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type acnt_name[MAX_DATA_ACCOUNT_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_get_account_name(g_swflash_cntx.nwk_account_id, (S8*) acnt_name, MAX_DATA_ACCOUNT_NAME_LEN);

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((S8*) hintData[index], (S8*) acnt_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_storage
 * DESCRIPTION
 *  highlight storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_setting_storage_entry_screen, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_highlight_datacnt
 * DESCRIPTION
 *  highlight datacnt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_highlight_datacnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_swflash_datacnt_select, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_datacnt_select
 * DESCRIPTION
 *  select datacnt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_datacnt_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account_ext(
        (FuncPtrU32)mmi_swflash_datacnt_select_callback,
        0,
        DATA_ACCOUNT_BEARER_GPRS,
        g_swflash_cntx.nwk_account_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_datacnt_select_callback
 * DESCRIPTION
 *  call back function
 * PARAMETERS
 *  nwk_account_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_datacnt_select_callback(U16 nwk_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_swflash_cntx.nwk_account_id = nwk_account_id;

    /* write nwk_account_id */
    mmi_swflash_store_setting();

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);

    DeleteUptoScrID(SCR_ID_SWFLASH_SETTING);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_store_setting
 * DESCRIPTION
 *  store storage to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_SWFLASH_STORAGE, &g_swflash_cntx.storage, DS_BYTE, &error);
    WriteValue(NVRAM_SWFLASH_DATA_ACCOUNT, &g_swflash_cntx.nwk_account_id, DS_BYTE, &error);
    WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
}

#endif /* __MMI_SWFLASH_SEPERATE_ENTRY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_fs_info
 * DESCRIPTION
 *  fill in the folder path of phone and card 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_get_fs_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[4];
    S16 swflash_phone_drv_letter;
    S16 swflash_card_drv_letter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get phone drive */
    if ((swflash_phone_drv_letter = MMI_PUBLIC_DRV) > 0)
    {
        sprintf(temp, "%c:\\", (S8) swflash_phone_drv_letter);
        mmi_asc_to_ucs2((S8*) g_swflash_cntx.swflash_phone_root_dir, temp);
        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_phone_list_dir[0],
            (const S8*)g_swflash_cntx.swflash_phone_root_dir);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_phone_list_dir[0], (const S8*)FMGR_DEFAULT_FOLDER_SWFLASH);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_phone_list_dir[1],
            (const S8*)g_swflash_cntx.swflash_phone_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_phone_list_dir[1], (const S8*)SWFLASH_SUB_FOLDER_ANIMATION);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_phone_list_dir[2],
            (const S8*)g_swflash_cntx.swflash_phone_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_phone_list_dir[2], (const S8*)SWFLASH_SUB_FOLDER_GAME);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_phone_list_dir[3],
            (const S8*)g_swflash_cntx.swflash_phone_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_phone_list_dir[3], (const S8*)SWFLASH_SUB_FOLDER_KARAOK);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_phone_list_dir[4],
            (const S8*)g_swflash_cntx.swflash_phone_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_phone_list_dir[4], (const S8*)SWFLASH_SUB_FOLDER_EXTENT);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_phone_list_dir[5],
            (const S8*)g_swflash_cntx.swflash_phone_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_phone_list_dir[5], (const S8*)SWFLASH_SUB_FOLDER_OTHER);

    }

    /* get card drive */
    if ((swflash_card_drv_letter = MMI_CARD_DRV) > 0)
    {
        sprintf(temp, "%c:\\", (S8) swflash_card_drv_letter);
        mmi_asc_to_ucs2((S8*) g_swflash_cntx.swflash_card_root_dir, temp);
        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_card_list_dir[0],
            (const S8*)g_swflash_cntx.swflash_card_root_dir);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_card_list_dir[0], (const S8*)FMGR_DEFAULT_FOLDER_SWFLASH);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_card_list_dir[1],
            (const S8*)g_swflash_cntx.swflash_card_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_card_list_dir[1], (const S8*)SWFLASH_SUB_FOLDER_ANIMATION);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_card_list_dir[2],
            (const S8*)g_swflash_cntx.swflash_card_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_card_list_dir[2], (const S8*)SWFLASH_SUB_FOLDER_GAME);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_card_list_dir[3],
            (const S8*)g_swflash_cntx.swflash_card_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_card_list_dir[3], (const S8*)SWFLASH_SUB_FOLDER_KARAOK);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_card_list_dir[4],
            (const S8*)g_swflash_cntx.swflash_card_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_card_list_dir[4], (const S8*)SWFLASH_SUB_FOLDER_EXTENT);

        mmi_ucs2cpy(
            (S8*) g_swflash_cntx.swflash_card_list_dir[5],
            (const S8*)g_swflash_cntx.swflash_card_list_dir[0]);
        mmi_ucs2cat((S8*) g_swflash_cntx.swflash_card_list_dir[5], (const S8*)SWFLASH_SUB_FOLDER_OTHER);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_is_card_ready
 * DESCRIPTION
 *  check id card is inserted
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_swflash_is_card_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;
    S16 swflash_card_drv_letter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((swflash_card_drv_letter = MMI_CARD_DRV) <= 0)
    {
        return FALSE;
    }

    if ((hd = FS_Open((PU16) g_swflash_cntx.swflash_card_root_dir, FS_OPEN_DIR | FS_READ_ONLY)) >= 0)
    {
        FS_Close(hd);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_setting_storage_entry_screen
 * DESCRIPTION
 *  choose the storage path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_setting_storage_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SWFLASH_SETTING_STORAGE, NULL, mmi_swflash_setting_storage_entry_screen, NULL);

    nItems = GetNumOfChild(MENU_ID_SWFLASH_SETTING_STORAGE);
    GetSequenceStringIds(MENU_ID_SWFLASH_SETTING_STORAGE, ItemList);
    GetSequenceImageIds(MENU_ID_SWFLASH_SETTING_STORAGE, ItemIcons);
    SetParentHandler(MENU_ID_SWFLASH_SETTING_STORAGE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory11Screen(STR_ID_SWFLASH_SETTING_STORAGE,
                         IMG_ID_SWFLASH_APP2,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nItems, ItemList,
                         0, /* current index */
                         NULL);

    SetLeftSoftkeyFunction(mmi_swflash_set_storage_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_set_storage_value
 * DESCRIPTION
 *  set storage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_set_storage_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_UCS2[FMGR_PATH_BUFFER_SIZE];
    S32 ret_drv;
    S8 buf[64];
    FS_HANDLE file_handle;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_swflash_cntx.storage = GetCurrHiliteID();

    if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
    {
        ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    }
    else if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
    {
        ret_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    }
    else
    {
        ret_drv = 0;
        ASSERT(0);
    }

    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
        mmi_asc_to_ucs2(buf_UCS2, buf);

        file_handle = FS_Open((kal_uint16*) buf_UCS2, FS_OPEN_DIR | FS_READ_ONLY);

        if (file_handle >= 0)
        {
            FS_Close(file_handle);
            /* drive is avaiable */

            /* check if swflash path exist or not */
            if(g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
            {
                create_result = mmi_swflash_create_phone_folder();
            }
            else
            {
                create_result = mmi_swflash_create_card_folder();
            }


            if (create_result == FS_WRITE_PROTECTION)
            {
                g_swflash_cntx.storage = MMI_SWFLASH_STORAGE_PHONE;

                DisplayPopup(
                    (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);

                DeleteUptoScrID(SCR_ID_SWFLASH_SETTING_STORAGE);
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                g_swflash_cntx.storage = MMI_SWFLASH_STORAGE_PHONE;

                DisplayPopup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);

                DeleteUptoScrID(SCR_ID_SWFLASH_SETTING_STORAGE);
            }
            else if (create_result == FS_DISK_FULL)
            {
                g_swflash_cntx.storage = MMI_SWFLASH_STORAGE_PHONE;

                DisplayPopup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);

                DeleteUptoScrID(SCR_ID_SWFLASH_SETTING_STORAGE);
            }
            else
            {
                DeleteScreenIfPresent(SCR_ID_SWFLASH_SETTING_STORAGE);
                /* begin to download */
                mmi_swflash_receive_cmp_file();

            }
        }
        else
        {
            /* set phone internal space as default */
            g_swflash_cntx.storage = MMI_SWFLASH_STORAGE_PHONE;

            DisplayPopup(
                (PU8) GetString(STR_ID_SWFLASH_NOTIFY_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);

            DeleteUptoScrID(SCR_ID_SWFLASH_SETTING_STORAGE);
        }
    }
    else
    {
        /* set phone internal space as default */
        g_swflash_cntx.storage = MMI_SWFLASH_STORAGE_PHONE;

        DisplayPopup(
            (PU8) GetString(STR_ID_SWFLASH_NOTIFY_NO_MEMORY_CARD),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);

        DeleteUptoScrID(SCR_ID_SWFLASH_SETTING_STORAGE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_storage_file_path
 * DESCRIPTION
 *  get current active storage disk path
 * PARAMETERS
 *  filepath        [OUT]       Storage file path
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL mmi_swflash_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_buf[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
    {
        if (mmi_swflash_get_storage_disk_path(drv_buf))
        {
            mmi_ucs2cpy((PS8) filepath, (PS8) drv_buf);
            mmi_ucs2cat((PS8) filepath, (PS8) SWFLASH_STORAGE_FILEPATH_PHONE);
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
    {
        if (mmi_swflash_get_storage_disk_path(drv_buf))
        {
            mmi_ucs2cpy((PS8) filepath, (PS8) drv_buf);
            mmi_ucs2cat((PS8) filepath, (PS8) SWFLASH_STORAGE_FILEPATH_MEMORY_CARD);
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        ASSERT(0);

    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_storage_disk_path
 * DESCRIPTION
 *  get current active storage disk path
 * PARAMETERS
 *  drv_buf     [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_swflash_get_storage_disk_path(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_drv;
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
    {
        ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);

        if (ret_drv >= 0)
        {
            sprintf(buf, "%c:\\", (U8) ret_drv);
            mmi_asc_to_ucs2(drv_buf, buf);
            return TRUE;
        }
        else
        {
            /* phone drive should not fail */
            ASSERT(0);
            return FALSE;
        }
    }
    else if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
    {
        ret_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

        if (ret_drv >= 0)
        {
            sprintf(buf, "%c:\\", (U8) ret_drv);
            mmi_asc_to_ucs2(drv_buf, buf);
            return TRUE;
        }
        else
        {
            return FALSE;
        }

    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_create_file_dir
 * DESCRIPTION
 *  create file directory-resursivly
 * PARAMETERS
 *  filepath        [IN]        Filepath to be created
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_swflash_create_file_dir(S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_createpath[128];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 fs_ret;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return 0;   /* already exist, 0 means successful in file system */
    }

    /* create directory if it is not there */
    mmi_ucs2cpy((PS8) buf_filepath, (PS8) filepath);

    str_len = mmi_ucs2strlen((PS8) buf_filepath);
    str_len *= ENCODING_LENGTH;

    /* skip drive. "C:\" */
    for (i = 3 * ENCODING_LENGTH; i < str_len; i += 2)
    {
        cmp_ret = mmi_ucs2ncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */

            mmi_ucs2ncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);
            buf_createpath[i] = '\0';
            buf_createpath[i + 1] = '\0';

            fs_ret = FS_CreateDir((PU16) buf_createpath);

            if (fs_ret < 0)
            {
                return fs_ret;
            }
        }
    }

    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_load_setting
 * DESCRIPTION
 *  load setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S8 IMEIbuf[(15 + 1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_swflash_cntx.is_load_setting)
    {
        return;
    }

    g_swflash_cntx.is_load_setting = TRUE;

    /* volume setting */
    ReadValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_IMEI_IMEISV_LID, 1, IMEIbuf, (15 + 1) * ENCODING_LENGTH, &error);
    cim_set_imei(IMEIbuf);
    /* init if needed */
    if (g_swflash_cntx.storage == 0xff)
    {
        g_swflash_cntx.storage = MMI_SWFLASH_STORAGE_PHONE;
    }

    if (g_swflash_cntx.nwk_account_id == 0xff)
    {
        g_swflash_cntx.nwk_account_id = 14; /* CMCC */
    }

    if (g_swflash_cntx.volume == 0xff)
    {
        g_swflash_cntx.volume = 4;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_create_phone_folder
 * DESCRIPTION
 *  create SWFlash folder in phone drive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_swflash_create_phone_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    S32 k;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    for (k = 0; k < 6; k++)
    {
        file_handle = FS_Open((kal_uint16*) g_swflash_cntx.swflash_phone_list_dir[k], FS_OPEN_DIR | FS_READ_ONLY);
      
        if (file_handle >= 0)
        {
            /* already exist , 0 measn success in FS */
            FS_Close(file_handle);
        }
        else
        {
            fs_ret = FS_CreateDir((PU16) g_swflash_cntx.swflash_phone_list_dir[k]);

            if(fs_ret<0)
            return fs_ret;
        }

    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_create_card_folder
 * DESCRIPTION
 *  create SWFlash folder in card drive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_swflash_create_card_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    S32 k;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    for (k = 0; k < 6; k++)
    {
        file_handle = FS_Open((kal_uint16*) g_swflash_cntx.swflash_card_list_dir[k], FS_OPEN_DIR | FS_READ_ONLY);

        if (file_handle >= 0)
        {
            /* already exist , 0 measn success in FS */
            FS_Close(file_handle);
        }
        else
        {
            fs_ret = FS_CreateDir((PU16) g_swflash_cntx.swflash_card_list_dir[k]);

            if(fs_ret<0)
            return fs_ret;
        }

    }

    return FS_NO_ERROR;
}





/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_show_percentage
 * DESCRIPTION
 * show percentage of dow.load
 * PARAMETERS
 *  percentage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_show_percentage(U8 percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_SWFLASH_PERCENTAGE_BAR)
    {
        if (percentage != g_swflash_cntx.percentage)
        {
            g_swflash_cntx.percentage = percentage;
            UpdateCategory402Value((U16) percentage, NULL);
        }
    }
    else
    {
        g_swflash_cntx.percentage = percentage;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_percentage_bar_delete_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_percentage_bar_delete_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_stop_download_file();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_percentage_bar_entry_screen
 * DESCRIPTION
 *  entry function to show process bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_percentage_bar_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_swflash_cntx.percentage != 99)
    {
        EntryNewScreen(SCR_ID_SWFLASH_PERCENTAGE_BAR, NULL, mmi_swflash_percentage_bar_entry_screen, NULL);

        /* hook delete screen hdlr */
        SetDelScrnIDCallbackHandler(SCR_ID_SWFLASH_PERCENTAGE_BAR, (HistoryDelCBPtr)mmi_swflash_percentage_bar_delete_screen);

        ShowCategory402Screen(
            (U8*) GetString(STR_GLOBAL_DOWNLOADING),
            0,
            0,
            0,
            0,
            0,
            NULL,
            (U16) g_swflash_cntx.percentage,
            NULL);

        SetKeyHandler(mmi_swflash_percentage_endkey_abort_hdlr, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_enter_idle_screen_notify
 * DESCRIPTION
 *  the notify function to enter idle screen,be called by idlescreen app,
 *  when enter idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_enter_idle_screen_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_stop_download_file();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_percentage_endkey_abort_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_percentage_endkey_abort_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_stop_download_file();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    DisplayIdleScreen();
    DisplayPopup(
        (PU8) GetString(STR_DA_OMA_USER_CANCELLED_MSG),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_complete_play_confirm
 * DESCRIPTION
 *  confirm window to play or not
 * PARAMETERS
 *  void
 *  ret(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_dl_complete_play_confirm(void)
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
        get_string(STR_ID_SWFLASH_ASK_PLAYBACK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    TurnOnBacklight(1);

    DeleteUptoScrID(SCR_ID_SWFLASH_SETTING_STORAGE);
    DeleteScreenIfPresent(SCR_ID_SWFLASH_SETTING_STORAGE);
    
    SetLeftSoftkeyFunction(mmi_swflash_option_play_entry_screen, KEY_EVENT_UP);
    
    if(g_swflash_cntx.dl_resume == MMI_TRUE)
    {
        SetRightSoftkeyFunction(mmi_swflash_monternet_visit, KEY_EVENT_UP);
        g_swflash_cntx.dl_resume = MMI_FALSE;
    }
    else
    {
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_result_callback
 * DESCRIPTION
 *  call back function for download result
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_dl_result_callback(MDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ret)
    {
        case MDI_SWFLASH_SOC_NOTIFY_DL_COMPLETE:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            mmi_swflash_dl_complete_play_confirm();
            break;

        case MDI_SWFLASH_SOC_NOTIFY_DL_STATUS:
            /* XXX */
            break;

        case MDI_SWFLASH_SOC_NOTIFY_FILE_ERROR:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_FILE_ERROR), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;

        case MDI_SWFLASH_SOC_NOTIFY_NETWORK_ERROR:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_NETWORK_ERROR), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;

        case MDI_SWFLASH_SOC_NOTIFY_DISK_FULL:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_DISK_FULL), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;

        case MDI_SWFLASH_SOC_NOTIFY_DISK_WRITE_PROTECT:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup(
                (PU8) GetString(STR_ID_SWFLASH_NOTIFY_DISK_WRITE_PROTECT),
                IMG_GLOBAL_ERROR,
                1,
                1000,
                (U8) ERROR_TONE);
            break;

        case MDI_SWFLASH_SOC_NOTIFY_SOCKET_ERROR:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_SOCKET_ERROR), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;

        case MDI_SWFLASH_SOC_NOTIFY_SERVER_ERROR:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_SERVER_ERROR), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;

        case MDI_SWFLASH_SOC_NOTIFY_HTTP_FAILED:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_HTTP_FAILED), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;

        case MDI_SWFLASH_SOC_NOTIFY_UNKNOWN:
            mdi_swflash_stop_download_file();
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
            GoBackHistory();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_UNKNOWN), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;

        default:
            ASSERT(0);
            break;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_progress_callback
 * DESCRIPTION
 *  callback function for download process
 * PARAMETERS
 *  dl_size         [IN]        
 *  total_size      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_dl_progress_callback(S32 dl_size, S32 total_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 percentage = dl_size * 100 / total_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (percentage >= 100)
    {
        percentage = 99;
    }

    mmi_swflash_show_percentage((U8) percentage);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_play_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_wivg_render
 * DESCRIPTION
 *  callback function for category227
 * PARAMETERS
 *  coordinate      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_wivg_render(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* width and height need to assign before open_file for create cim_buffer */
    g_swflash_cntx.layer_offset_x = coordinate->s16X;
    g_swflash_cntx.layer_offset_y = coordinate->s16Y;
    g_swflash_cntx.layer_width = coordinate->s16Width;
    g_swflash_cntx.layer_height = coordinate->s16Height;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_disk_space
 * DESCRIPTION
 *  get the free disk space
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long mmi_swflash_get_disk_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int free_space = 0;
    UI_character_type storagePath[MAX_PATH_LEN];
    FS_DiskInfo info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FS_QM_SUPPORT__
    if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
    {
        kal_wsprintf((kal_wchar*) storagePath, "%c:\\%w", MMI_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_SWFLASH);
    }
    else if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
    {
        kal_wsprintf((kal_wchar*) storagePath, "%c:\\%w", MMI_CARD_DRV, FMGR_DEFAULT_FOLDER_SWFLASH);
    }
    else
    {
        ASSERT(0);
    }

    free_space = FS_QmGetFree((BYTE*) storagePath);
    /* negative means fs return error code */
    if (free_space < 0)
    {
        if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
        {
            kal_wsprintf((kal_wchar*) storagePath, "%c:\\", MMI_PUBLIC_DRV);
        }
        else if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
        {
            kal_wsprintf((kal_wchar*) storagePath, "%c:\\", MMI_CARD_DRV);
        }
        else
        {
            ASSERT(0);
        }

        FS_GetDiskInfo(storagePath, &info, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
        free_space = info.FreeClusters * info.SectorsPerCluster * info.BytesPerSector;
    }
#else /* __FS_QM_SUPPORT__ */ 
    if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
    {
        kal_wsprintf((kal_wchar*) storagePath, "%c:\\", MMI_PUBLIC_DRV);
    }
    else if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
    {
        kal_wsprintf((kal_wchar*) storagePath, "%c:\\", MMI_CARD_DRV);
    }
    else
    {
        ASSERT(0);
    }

    FS_GetDiskInfo(storagePath, &info, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
    free_space = info.FreeClusters * info.SectorsPerCluster * info.BytesPerSector;
#endif /* __FS_QM_SUPPORT__ */ 

    return (unsigned long)free_space;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_receive_da_file_callback
 * DESCRIPTION
 *  wfd download handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_receive_da_file_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_swflash_cntx.percentage = 0;

    ret=mdi_swflash_start_download_file(
        (PS8) g_swflash_cntx.swflash_cmp_full_path, /* partial cmp file */
        (PS8) g_swflash_cntx.swflash_cmp_full_path, /* result cmp file */
        g_swflash_cntx.nwk_account_id,
        mmi_swflash_dl_result_callback,
        mmi_swflash_dl_progress_callback);

    if(ret==MDI_RES_SWFLASH_SUCCEED)
    {
    mmi_swflash_percentage_bar_entry_screen();
    }
    else
    {
        DisplayPopup(
               (PU8) GetString(STR_ID_SWFLASH_NOTIFY_FILE_ERROR),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
     }
    return;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_browser_profile_rsq
 * DESCRIPTION
 *  get the current active browser profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_get_browser_profile_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_bra_prof_id_rsp_struct *profile;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile=(wap_get_bra_prof_id_rsp_struct *)info;
      
    g_swflash_cntx.nwk_account_id=profile->net_id;
    mmi_swflash_receive_da_file_callback();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_browser_profile_req
 * DESCRIPTION
 *  get the current active browser profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
  void mmi_swflash_get_browser_profile_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    SetProtocolEventHandler(mmi_swflash_get_browser_profile_rsp, MSG_ID_WAP_GET_BRA_PROF_ID_RSP);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_GET_BRA_PROF_ID_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_receive_cmp_file
 * DESCRIPTION
 *  download the left data of cmp file(swflash works)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_receive_cmp_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type storagePath[MAX_PATH_LEN];
    UI_character_type *cmp_name = NULL;
    long disk_space = 0;
    int ret = 0;
    int category = 0;
    char *pWfdData = NULL;
    char *pCmpData = NULL;

    int nWfdSize = -1;
    int nCimSize = -1;
    int nWfdRead = -1;
    int nCmpSize = -1;

    HCIMFILE hFile = NULL;

    FS_HANDLE fd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_swflash_cntx.da_mime_subtype == MIME_SUBTYPE_WFD) || (g_swflash_cntx.da_mime_subtype == MIME_SUBTYPE_CIM))
    {
        if ((fd = FS_Open((const WCHAR*)g_swflash_cntx.da_file_path, FS_READ_ONLY)) < 0)
        {
            /* WAP problem */
            //kal_prompt_trace(MOD_MMI, "da_mime_subtype=%s", g_swflash_cntx.da_file_path);
            PRINT_INFORMATION("[SWFLASH] WFD temp file is lost!");
            return;
        }

        if ((ret = FS_GetFileSize(fd, (U32*) & nWfdSize)) != RTF_NO_ERROR)
        {
            /* FS problem */
            PRINT_INFORMATION("[SWFLASH] WFD file size is unknown!");
            FS_Close(fd);
            return;
        }

        if (nWfdSize <= 0 || nWfdSize > MAX_SWFLASH_FILE_DATA_BUFFER_SIZE)
        {
            PRINT_INFORMATION("[SWFLASH] WFD file size %d is improper", nWfdSize);
            FS_Close(fd);
            return;
        }

        //kal_prompt_trace(MOD_MMI, "begin to alloc mem");
        /* alloc buffer */
        media_get_ext_buffer(MOD_MMI, (void **)&pWfdData, nWfdSize);

        /* Read Wfd file: pData is allocated from MED by SWFlash APP */
        ret = FS_Read(fd, pWfdData, nWfdSize, (U32*) & nWfdRead);
        FS_Close(fd);

        /* fs read error 1 */
        if (ret < 0)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&pWfdData);
            PRINT_INFORMATION("[SWFLASH] Read WFD data read failed");
            return;
        }

        /* fs read error 2 */
        if (nWfdSize != nWfdRead)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&pWfdData);
            PRINT_INFORMATION("[SWFLASH] Read WFD data read %d not %d", nWfdRead, nWfdSize);
            return;
        }

        /* Create HCIMFILE handle from empty */
        cim_adm_malloc();
        hFile = CimCreateHandle(NULL, 0);
        if (hFile == NULL)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&pWfdData);
            cim_adm_free();
            //kal_prompt_trace(MOD_MMI, "[SWFLASH] Create HCIMFILE failed");
            return;
        }

        /* feed to WIVG engine */
        ret = CimAddWfdData(hFile, pWfdData, nWfdSize);
        if (ret != 1)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&pWfdData);
            CimFreeHandle(hFile);
            cim_adm_free();
            //kal_prompt_trace(MOD_MMI, "[SWFLASH] Add Wfd data fail, ret=%d", ret);
            return;
        }

        /* free buffer */
        media_free_ext_buffer(MOD_MMI, (void **)&pWfdData);

        /* Get file size */
        ret = CimGetRecInt(hFile, (unsigned short*)_sizenode, &nCimSize);
        if (ret != 1)
        {
            CimFreeHandle(hFile);
            //kal_prompt_trace(MOD_MMI, "[SWFLASH] Get partial Cmp file size fail, ret=%d", ret);
            cim_adm_free();
            return;
        }

        if (nCimSize > MAX_SWFLASH_FILE_DATA_BUFFER_SIZE)
        {
            CimFreeHandle(hFile);
            //kal_prompt_trace(MOD_MMI, "[SWFLASH] Size %d Too Big!!", nCimSize);
            cim_adm_free();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_TOO_BIG), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            return;
        }

        disk_space = mmi_swflash_get_disk_space();
        if (nCimSize > disk_space)
        {
            CimFreeHandle(hFile);
            PRINT_INFORMATION("[SWFLASH] Insufficient space %d for cim size %d!!", disk_space, nCimSize);
            cim_adm_free();
            DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_DISK_FULL), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            return;
        }

        /* Get file name */
        ret = CimGetRecString(hFile, (unsigned short*)_titlenode, (unsigned short **)&cmp_name);
        if (ret != 1)
        {
            CimFreeHandle(hFile);
            //kal_prompt_trace(MOD_MMI, "[SWFLASH] Get SWFlash file name fail, ret=%d", ret);
            cim_adm_free();
            return;
        }
        PRINT_INFORMATION("[SWFLASH] SWFlash file name: 0x%x 0x%x 0x%x 0x%x", cmp_name[0], cmp_name[1], cmp_name[2],
                           cmp_name[3]);

        ret = CimGetRecInt(hFile, (unsigned short*)_categorynode, (int*)&category);

        /* Get partial Cmp file: pData is allocated from MED by WIVG engine */
        ret = CimGetFileData(hFile, (void **)&pCmpData, &nCmpSize);
        if (ret <= 0)
        {
            CimFreeHandle(hFile);
            cim_adm_free();
            //kal_prompt_trace(MOD_MMI, "[SWFLASH] Get partial Cmp file fail, ret=%d", ret);
            return;
        }
        //kal_prompt_trace(MOD_MMI, "partly cmp is ready");
        /******************************************************************************/
        /* ok, at this moment, pCmpData contains wfd-only information for further use */
        /******************************************************************************/

        /* settle storagePath */
        if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_PHONE)
        {
            kal_wsprintf((kal_wchar*) storagePath, "%c:\\%w", MMI_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_SWFLASH);
        }
        else if (g_swflash_cntx.storage == MMI_SWFLASH_STORAGE_CARD)
        {
            kal_wsprintf((kal_wchar*) storagePath, "%c:\\%w", MMI_CARD_DRV, FMGR_DEFAULT_FOLDER_SWFLASH);
        }
        else
        {
            ASSERT(0);
        }

        switch (category)
        {

            case 2:
                mmi_ucs2cat((S8*) storagePath, (S8*) SWFLASH_SUB_FOLDER_ANIMATION);
                break;
            case 3:
                mmi_ucs2cat((S8*) storagePath, (S8*) SWFLASH_SUB_FOLDER_GAME);
                break;
            case 4:
                mmi_ucs2cat((S8*) storagePath, (S8*) SWFLASH_SUB_FOLDER_EXTENT);
                break;
            case 5:
                mmi_ucs2cat((S8*) storagePath, (S8*) SWFLASH_SUB_FOLDER_KARAOK);
                break;
            default:
                mmi_ucs2cat((S8*) storagePath, (S8*) SWFLASH_SUB_FOLDER_OTHER);
                break;

        }
        /* Prepare Cmp file full path */
        kal_wsprintf((kal_wchar*) g_swflash_cntx.swflash_cmp_full_path, "%w%w%w", storagePath, cmp_name, L".cmp");

        {
            int i = 0;
            FS_HANDLE file_handle = 0;
            UI_character_type ser_num[MAX_FILE_NAME_LEN];

            while ((file_handle = FS_Open((U16*) g_swflash_cntx.swflash_cmp_full_path, FS_READ_ONLY)) >= 0)
            {
                FS_Close(file_handle);
                kal_wsprintf(ser_num, "%02d", i++ % 100);
                kal_wsprintf(
                    (kal_wchar*) g_swflash_cntx.swflash_cmp_full_path,
                    "%w%w%w%w",
                    storagePath,
                    cmp_name,
                    ser_num,
                    L".cmp");
            }
        }

        /* Write partial Cmp file */
        ret = mdi_swflash_write_file(g_swflash_cntx.swflash_cmp_full_path, pCmpData, nCmpSize);

        CimFreeHandle(hFile);
        cim_adm_free();
        //kal_prompt_trace(MOD_MMI, "DataAccountReadyCheck. write=%d", ret);
        mmi_swflash_get_browser_profile_req();
    }
    else
    {
        ASSERT(0);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_receive_da_file
 * DESCRIPTION
 *  call back function for download agent
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        
 *  mime_subtype            sub type(wfd or cim)        
 *  action                  [IN]        
 *  file_path               full name of works        
 *  url                     [IN]        
 *  mime_type_string        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 file_path,
        PS8 url,
        PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) g_swflash_cntx.da_file_path, (const S8*)file_path);
    g_swflash_cntx.da_mime_subtype = mime_subtype;
    mmi_swflash_load_setting();
    mmi_swflash_setting_storage_entry_screen();
}

#endif /* SWFLASH_CHAOTEX */ 
#endif /* __MMI_SWFLASH__ */ 

