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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include "MMI_include.h"
#if defined (__MMI_DOWNLOAD_AGENT__)

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"
#include "FileMgr.h"

#include "drm_def.h"                    /* DRM_PROC_RESULT_OK */
#include "drm_gprot.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "DLAgentprot.h"
#include "DLAgentResDef.h"

#include "SettingProfile.h"     /* ERROR_TONE */
#include "FileManagerGProt.h"           /* GetFileSystemErrorString */
#include "FileManagerDef.h"

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Define - Macro
*****************************************************************************/

#define MMI_DA_AUTH_LEN_USERNAME 31
#define MMI_DA_AUTH_LEN_PASSWORD 31

/****************************************************************************
* Typedef
*****************************************************************************/

/****************************************************************************
* Typedef - Enum
*****************************************************************************/

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct
{
    /* confirm */
    mmi_da_confirm_funcptr_type         confirm_yes_hdlr;
    mmi_da_scr_abort_funcptr_type       confirm_no_hdlr;
    mmi_da_confirm_format_msg_funcptr_type confirm_message_hdlr;
    U32                                 confirm_criteria;
    MMI_BOOL                            confirm_autodel;
    U16                                 confirm_icon_id;
        
    /* choose storage */
    mmi_da_scr_storage_parameter_struct storage_para;
    mmi_da_scr_storage_callback_type    storage_callback;
    U32                                 storage_criteria;
    U16                                 filepath[FMGR_MAX_PATH_LEN + 1];
    U16                                 fileext[FMGR_MAX_EXT_LEN + 1];
    U16                                 storage_icon_id;
    BOOL                                storage_reset_filename;

    /* auth */
    U16                                 auth_username[MMI_DA_AUTH_LEN_USERNAME];
    U16                                 auth_password[MMI_DA_AUTH_LEN_PASSWORD];
    U32                                 auth_criteria;
    mmi_da_scr_auth_callback_type       auth_callback;
    U16                                 auth_icon_id;

    /* please wait */
    U32                                 plzwait_criteria;
    mmi_da_scr_abort_funcptr_type       plzwait_callback;
    U16                                 plzwait_icon_id;
    
} mmi_da_scr_context_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Declaration
*****************************************************************************/

static mmi_da_scr_context_struct da_scr_context;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
static void mmi_da_scr_entry_confirm_screen(void);

static void mmi_da_scr_entry_marker_screen(void);
static void mmi_da_scr_entry_sel_drv(void);
static void mmi_da_scr_get_drive_callback(S8 drv);
static void mmi_da_scr_entry_filename_editor(void);
static void mmi_da_scr_entry_filename_editor_option(void);
static void mmi_da_scr_filename_editor_gobackhistory(void);
static void mmi_da_scr_hightlight_save(void);
static void mmi_da_scr_hightlight_input_method(void);

static void mmi_da_scr_storage_callback(U16* filepath, BOOL in_delete_cb);

static void mmi_da_scr_abort_lsk_hdlr(void);
static void mmi_da_scr_abort_rsk_hdlr(void);
static void mmi_da_scr_overwrite_query_lsk_hdlr(void);
static void mmi_da_scr_fake_overwrite_query_lsk_hdlr(void);

static void mmi_da_scr_entry_auth(void);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function 
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*   mmi_da_scr_init
* DESCRIPTION
*   Initial the screen context
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_da_scr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetHiliteHandler(MENU_ID_DA_OPTION_SAVE, mmi_da_scr_hightlight_save);
    SetHiliteHandler(MENU_ID_DA_OPTION_INPUT_METHOD, mmi_da_scr_hightlight_input_method);

    memset(&da_scr_context, 0, sizeof(mmi_da_scr_context_struct));
}

#define CONFIRM

void mmi_da_scr_confirm_download(U32 criteria,
    mmi_da_confirm_format_msg_funcptr_type msg_hdlr,
    mmi_da_confirm_funcptr_type yes_hdlr, 
    mmi_da_scr_abort_funcptr_type no_hdlr,
    MMI_BOOL auto_delete, U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    da_scr_context.confirm_yes_hdlr = yes_hdlr;
    da_scr_context.confirm_no_hdlr = no_hdlr;
    da_scr_context.confirm_message_hdlr = msg_hdlr;
    da_scr_context.confirm_criteria = criteria;
    da_scr_context.confirm_autodel = auto_delete;
    da_scr_context.confirm_icon_id = mmi_da_util_get_icon_from_appid(app_id);

    mmi_da_scr_entry_confirm_screen();
}

void mmi_da_scr_confirm_download_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    da_scr_context.confirm_no_hdlr = NULL;  
    da_scr_context.confirm_yes_hdlr = NULL;
    da_scr_context.confirm_message_hdlr = NULL;
    da_scr_context.confirm_criteria = 0;
        
    ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM, NULL);
    if(GetActiveScreenId() == SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM)
        EntryNewScreen(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM);
}

static void mmi_da_scr_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_confirm_funcptr_type yes_hdlr;
	S32                         criteria;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    yes_hdlr = da_scr_context.confirm_yes_hdlr;
	criteria = da_scr_context.confirm_criteria;

    if(da_scr_context.confirm_autodel)
    {
        mmi_da_scr_confirm_download_delete();
    }
    
    if(yes_hdlr)
        yes_hdlr(criteria);
}

static U8 mmi_da_scr_confirm_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(da_scr_context.confirm_no_hdlr)
        da_scr_context.confirm_no_hdlr(da_scr_context.confirm_criteria, TRUE);

    da_scr_context.confirm_no_hdlr = NULL;
    da_scr_context.confirm_yes_hdlr = NULL;
    da_scr_context.confirm_message_hdlr = NULL;
    da_scr_context.confirm_criteria = 0;

    ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM, NULL);
    return MMI_FALSE;
}

static void mmi_da_scr_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_scr_context.confirm_no_hdlr)
        da_scr_context.confirm_no_hdlr(da_scr_context.confirm_criteria, FALSE);

    da_scr_context.confirm_no_hdlr = NULL;
    da_scr_context.confirm_yes_hdlr = NULL;
    da_scr_context.confirm_message_hdlr = NULL;
    da_scr_context.confirm_criteria = 0;

    ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM, NULL);
    if(GetActiveScreenId() == SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM)
        GoBackHistory();
    else
        DeleteScreenIfPresent(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM);
}

static void mmi_da_scr_entry_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM, NULL, mmi_da_scr_entry_confirm_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM);

    if(da_scr_context.confirm_message_hdlr)
        da_scr_context.confirm_message_hdlr(da_scr_context.confirm_criteria, (U16*)subMenuData);

    ShowCategory74Screen(STR_GLOBAL_DOWNLOAD_ASK,
                         da_scr_context.confirm_icon_id,
                         STR_GLOBAL_YES, IMG_GLOBAL_YES,
                         STR_GLOBAL_NO, IMG_GLOBAL_NO,
                         (PU8) subMenuData,
                         mmi_ucs2strlen((PS8) subMenuData),
                         guiBuffer);

    SetDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM, (HistoryDelCBPtr) mmi_da_scr_confirm_delete_callback);
    SetLeftSoftkeyFunction(mmi_da_scr_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_da_scr_confirm_no_hdlr, KEY_EVENT_UP);
}

#define STORAGE_SELECTION
/*****************************************************************************
* FUNCTION
*   
* DESCRIPTION
*   
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_da_scr_select_storage(mmi_da_scr_storage_callback_type callback,
                               const mmi_da_scr_storage_parameter_struct* parameter,
                               U32 criteria, U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    BOOL select_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* initialize */
    if(parameter != &da_scr_context.storage_para)
    {
        DA_TRACE_FUNC(mmi_da_scr_select_storage);
        
        /* prevent multi-usage */
        if(da_scr_context.storage_callback)
        {
            ASSERT(0);
            return;
        }        

        /* first time enter */
        memcpy(&da_scr_context.storage_para, parameter, sizeof(mmi_da_scr_storage_parameter_struct));
        da_scr_context.storage_callback = callback;
        da_scr_context.storage_reset_filename = FALSE;

        da_scr_context.storage_icon_id = mmi_da_util_get_icon_from_appid(app_id);

        if(da_scr_context.storage_para.select_storage || da_scr_context.storage_para.select_filename)
            mmi_da_scr_entry_marker_screen();

        da_scr_context.storage_criteria = criteria;

        /* backup extension */
        mmi_ucs2ncpy((S8*) da_scr_context.fileext, (S8*)da_scr_context.storage_para.fileext, FMGR_MAX_EXT_LEN - 1);
        /* use extension from mimetype if provide */
        if(da_scr_context.storage_para.ext)
        {
            memset(da_scr_context.fileext, 0, sizeof(da_scr_context.fileext));
            mmi_asc_n_to_ucs2((S8*)da_scr_context.fileext, (S8*)da_scr_context.storage_para.ext, FMGR_MAX_EXT_LEN - 1);
        }
        
	    mmi_ucs2cpy((S8*)da_scr_context.filepath, (S8*)da_scr_context.storage_para.filename);
    }

    /* select storage */
    if(da_scr_context.storage_para.select_storage)
    {
        mmi_da_scr_entry_sel_drv();
        return;
    }
    else if(da_scr_context.storage_para.storage == MMI_DA_STORAGE_AUTO)
    {
        /* auto assign */
        if(MMI_PUBLIC_DRV == MMI_CARD_DRV)
        {
            /* only memory card */
            da_scr_context.storage_para.storage = MMI_DA_STORAGE_MEMORY_CARD;
            da_scr_context.storage_para.drv = MMI_PUBLIC_DRV;
        }
        else
        {
            /* default to phone, change to card if phone too small */
            da_scr_context.storage_para.storage = MMI_DA_STORAGE_PHONE;
            da_scr_context.storage_para.drv = MMI_PUBLIC_DRV;
        
            if(da_scr_context.storage_para.filesize && 
                MMI_CARD_DRV > 0 && 
                fmgr_is_msdc_present() == MMI_TRUE &&
                mmi_da_util_check_free_space(MMI_PUBLIC_DRV, da_scr_context.storage_para.filesize) == MMI_FALSE)
            {
                da_scr_context.storage_para.storage = MMI_DA_STORAGE_MEMORY_CARD;
                da_scr_context.storage_para.drv = MMI_CARD_DRV;
            }
        }
    }

    ASSERT(da_scr_context.storage_para.storage == MMI_DA_STORAGE_PHONE ||
            da_scr_context.storage_para.storage == MMI_DA_STORAGE_MEMORY_CARD);
    /* if ASSERT, means there is no public drv */
    ASSERT(da_scr_context.storage_para.drv != 0);
    
    /* check if selected storage is big enough */
    {
        /* if provided original_filepath, and the chosen storage are the same
            Skip the check */
        if(!da_scr_context.storage_para.original_filepath ||
            da_scr_context.storage_para.original_filepath[0] != da_scr_context.storage_para.drv)
        {
            if (!mmi_da_util_check_free_space(da_scr_context.storage_para.drv, 
                                              da_scr_context.storage_para.filesize))
            {
                DisplayPopup((PU8) GetString(STR_ID_DA_ERROR_INSUFFICIENT_STORAGE), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME,
                             WARNING_TONE);
                if( !IsScreenPresent(SCR_ID_DA_SCREEN_STORAGE_SEL_DRV))
                {
                    mmi_da_scr_storage_callback(NULL, FALSE);
                }
                return;
            }
        }
    }

    /* select filename */   
    if(da_scr_context.storage_para.select_filename)
    {
        da_scr_context.storage_reset_filename = TRUE;
        mmi_da_scr_entry_filename_editor();
        return;
    }

    select_filename = (BOOL)IsScreenPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME);

    if ( mmi_ucs2strlen(mmi_ucs2trim_left((S8*)da_scr_context.filepath,(S8*)L" \t\r\n")) == 0 )
    {
        if(select_filename)
        {
            /* if empty filename, display abort? */
            DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                           get_string(STR_ID_DA_POPUP_CANCEL_ASK), IMG_GLOBAL_QUESTION, WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_da_scr_abort_lsk_hdlr, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_da_scr_abort_rsk_hdlr, KEY_EVENT_UP);
            return;
        }
        else
        {
            /* no valid default name, assign a temp name */
            kal_wsprintf(da_scr_context.filepath, "%c:\\%w", 
                         da_scr_context.storage_para.drv, 
                         da_scr_context.storage_para.folder);
            mmi_da_util_get_temp_filename(da_scr_context.filepath, da_scr_context.storage_para.filename, FMGR_MAX_FILE_LEN);
            mmi_ucs2cpy((S8*)da_scr_context.filepath, (S8*)mmi_da_util_get_filename(da_scr_context.storage_para.filename));
        }
    }

    mmi_ucs2ncpy((S8*)da_scr_context.storage_para.filename, (S8*)da_scr_context.filepath, FMGR_MAX_FILE_LEN);
    da_scr_context.storage_para.filename[FMGR_MAX_FILE_LEN] = 0;

    /* To check filename is valid or not, we should use name + extension, or "XXX." will fail to pass the check */
    if(da_scr_context.fileext[0])
    {
        kal_wsprintf(da_scr_context.filepath, "%w.%w", 
                     da_scr_context.storage_para.filename,
                     da_scr_context.fileext);
    }
    else
    {
        mmi_ucs2cpy((S8*)da_scr_context.filepath, (S8*)da_scr_context.storage_para.filename);
    }

    /* check if filename is valid */    
    if ( !mmi_da_util_is_valid_filename( da_scr_context.filepath ))
    {
        if(select_filename)
        {
            /* Invalid filename */
            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                         (U8) ERROR_TONE);

            DeleteScreenIfPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION);
            
            da_scr_context.storage_reset_filename = TRUE;
            return;
        }
        else
        {
            kal_wsprintf(da_scr_context.filepath, "%c:\\%w", 
                         da_scr_context.storage_para.drv, 
                         da_scr_context.storage_para.folder);
            mmi_da_util_get_temp_filename(da_scr_context.filepath, da_scr_context.storage_para.filename, FMGR_MAX_FILE_LEN);
            mmi_ucs2cpy((S8*)da_scr_context.filepath, (S8*)mmi_da_util_get_filename(da_scr_context.storage_para.filename));
            mmi_ucs2cpy((S8*)da_scr_context.storage_para.filename, (S8*)da_scr_context.filepath);
        }
    }

    /* remove space */
    mmi_ucs2cpy((S8*)da_scr_context.filepath, (S8*)mmi_fmgr_skip_space((S8*)da_scr_context.storage_para.filename));
    mmi_ucs2cpy((S8*)da_scr_context.storage_para.filename, (S8*)da_scr_context.filepath);
    
    /* complete full path */
    if(da_scr_context.fileext[0])
    {
        kal_wsprintf(da_scr_context.filepath, "%c:\\%w%w.%w", 
                     da_scr_context.storage_para.drv, 
                     da_scr_context.storage_para.folder, 
                     da_scr_context.storage_para.filename,
                     da_scr_context.fileext);
    }
    else
    {
        /* no ext */
        kal_wsprintf(da_scr_context.filepath, "%c:\\%w%w",
                     da_scr_context.storage_para.drv, 
                     da_scr_context.storage_para.folder, 
                     da_scr_context.storage_para.filename);
    }
    
    /* create folder */
    result = mmi_da_util_create_file_dir(da_scr_context.filepath, TRUE);
    if (result < 0)
    {
        DisplayPopup((PU8) GetString((U16) GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                     (U8) ERROR_TONE);

        mmi_da_scr_storage_callback(NULL, FALSE);
        return;
    }

    /* perform outside check if necessary */
    if(da_scr_context.storage_para.filecheck_func && 
        (!da_scr_context.storage_para.original_filepath ||
            !((mmi_da_scr_storage_filecheck_funcptr_type)da_scr_context.storage_para.filecheck_func)(da_scr_context.storage_para.original_filepath, FALSE)) &&
        ((mmi_da_scr_storage_filecheck_funcptr_type)da_scr_context.storage_para.filecheck_func)(da_scr_context.filepath, select_filename))
    {
        if(select_filename)
        {
            da_scr_context.storage_reset_filename = TRUE;
            if(GetActiveScreenId() == SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION)
                GoBackHistory();
            else
                DeleteScreenIfPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION);
            return;
        }
        else
        {
            /* append (n) to filename */
            mmi_da_util_get_ok_filepath(da_scr_context.filepath, NULL);
        }
    }

    /* if file exist */
    if(mmi_da_util_does_file_exist(da_scr_context.filepath))
    {
        if(da_scr_context.storage_para.original_filepath &&
                mmi_ucs2icmp((S8*)da_scr_context.filepath, (S8*)da_scr_context.storage_para.original_filepath) == 0)
        {
            /* if app specify original filepath, and user choose to save at same place
                do nothing */
            /* We ask user , but do nothing */
            if(select_filename)
            {
                DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                               get_string(STR_ID_DA_REPLACE_FILE), IMG_GLOBAL_QUESTION, WARNING_TONE);

                da_scr_context.storage_reset_filename = TRUE;
                SetLeftSoftkeyFunction(mmi_da_scr_fake_overwrite_query_lsk_hdlr, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_da_scr_abort_rsk_hdlr, KEY_EVENT_UP);
                return;
            }
        }
        else if(!select_filename)
        {
            /* no checking, make a new name (append (n)) */
            mmi_da_util_get_ok_filepath(da_scr_context.filepath, NULL);
        }
        else
        {
            /* not support resume, ask overwrite or not */
            DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                           get_string(STR_ID_DA_REPLACE_FILE), IMG_GLOBAL_QUESTION, WARNING_TONE);

            da_scr_context.storage_reset_filename = TRUE;
            SetLeftSoftkeyFunction(mmi_da_scr_overwrite_query_lsk_hdlr, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_da_scr_abort_rsk_hdlr, KEY_EVENT_UP);
            return;
        }
    }

    /* if all ok, call back to User */
    mmi_da_scr_storage_callback(da_scr_context.filepath, FALSE);

}

/*****************************************************************************
* FUNCTION
*   mmi_da_entry_save_to
* DESCRIPTION
*   Entry function: Let user choose which device they want save to.
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
static void mmi_da_scr_entry_sel_drv(void)
{
    mmi_fmgr_sel_drv_and_enter(
        (U8)mmi_da_util_get_appid_from_icon(da_scr_context.storage_icon_id), 
        mmi_da_scr_get_drive_callback, 
        (S8)da_scr_context.storage_para.drv);
}

/*****************************************************************************
* FUNCTION
*   mmi_da_scr_enter_marker_screen
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_scr_get_drive_callback( S8 drv )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buf_UCS2[4];
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC1(mmi_da_scr_get_drive_callback, drv);
    
    if(drv > 0)
    {
        da_scr_context.storage_para.drv = drv;
        if(drv == MMI_PUBLIC_DRV && (MMI_PUBLIC_DRV != MMI_CARD_DRV))
        {
            da_scr_context.storage_para.storage = MMI_DA_STORAGE_PHONE;
        }
        else
        {
            da_scr_context.storage_para.storage = MMI_DA_STORAGE_MEMORY_CARD;
        }

        if( GetActiveScreenId() == SCR_FMGR_SEL_DRV )
        {
            EntryNewScreen(SCR_ID_DA_SCREEN_STORAGE_SEL_DRV, NULL, mmi_da_scr_entry_sel_drv, NULL);
        }

        /* make sure the storage is available */
        kal_wsprintf(buf_UCS2, "%c:\\", (U8) da_scr_context.storage_para.drv);
        file_handle = FS_Open((U16 *) buf_UCS2, FS_OPEN_DIR | FS_READ_ONLY);
        FS_Close(file_handle);

        if (file_handle < 0)
        {
            ASSERT(da_scr_context.storage_para.storage != MMI_DA_STORAGE_PHONE);
            DisplayPopup((PU8) GetString(STR_GLOBAL_NO_MEMORY_CARD), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME,
                         WARNING_TONE);
            return;
        }

        da_scr_context.storage_para.select_storage = FALSE;
        mmi_da_scr_select_storage(NULL, &da_scr_context.storage_para, 0, 0);
    }
    else
    {
        ASSERT(!drv);
        mmi_da_scr_storage_callback(NULL, FALSE);
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_da_entry_filename_editor
* DESCRIPTION
*   Entry function: Let user edit the filename.
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
static void mmi_da_scr_entry_filename_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S16 input_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    da_scr_context.storage_para.select_filename = TRUE;
    if(da_scr_context.storage_reset_filename)
        mmi_ucs2cpy((S8*)da_scr_context.filepath, (S8*)da_scr_context.storage_para.filename);

    EntryNewScreen(SCR_ID_DA_SCREEN_STORAGE_FILENAME, NULL, mmi_da_scr_entry_filename_editor, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DA_SCREEN_STORAGE_FILENAME);

    if(guiBuffer)   // retrieve last input type;
    {
        input_type = ((multiline_inputbox_category_history*)guiBuffer)->input_type;
//        wgui_set_previous_input_type(input_type);
    }
    else
        input_type = INPUT_TYPE_ALPHANUMERIC_SENTENCECASE;


    ShowCategory5Screen(STR_ID_DA_FILENAME_EDITOR, da_scr_context.storage_icon_id,
                        STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,
                        STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                        input_type,
                        (U8 *) da_scr_context.filepath,
                        FMGR_MAX_INPUT_FILE_LEN,
                        da_scr_context.storage_reset_filename ? NULL : guiBuffer);
    
    da_scr_context.storage_reset_filename = FALSE;
    
    SetLeftSoftkeyFunction(mmi_da_scr_entry_filename_editor_option, KEY_EVENT_UP);
    
    SetCategory5RightSoftkeyFunction(mmi_da_scr_filename_editor_gobackhistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_da_scr_filename_editor_gobackhistory);

}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_scr_filename_editor_gobackhistory(void)
{
    if (IsScreenPresent(SCR_ID_DA_SCREEN_STORAGE_SEL_DRV))
    {
        GoBackHistory();
    }
    else
    {
        mmi_da_scr_storage_callback(NULL, FALSE);
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_da_entry_filename_editor_option
* DESCRIPTION
*   Entry function: Let user enter option in editor.
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
static void mmi_da_scr_entry_filename_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;
    U16 nStrItemList[3];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 entry new screen */
    EntryNewScreen(SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION, NULL, mmi_da_scr_entry_filename_editor_option, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_ID_DA_OPTION);
    ASSERT(nNumofItem == 2);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_ID_DA_OPTION, (PU16) nStrItemList);

    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_ID_DA_OPTION);

    /* 7. Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 7 Register function for end  key */
//    SetKeyHandler(mmi_da_finally_go_to_idle_screen, KEY_END, KEY_EVENT_DOWN);

    /* 8. Display menu category screen */
    ShowCategory52Screen(STR_GLOBAL_OPTIONS, da_scr_context.storage_icon_id,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem,
                         nStrItemList,
                         (PU16) gIndexIconsImageList,
                         NULL, 0, 0, guiBuffer);

    if(da_scr_context.storage_reset_filename)
    {
        mmi_ucs2cpy((S8*)da_scr_context.filepath, (S8*)da_scr_context.storage_para.filename);
        da_scr_context.storage_reset_filename = FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_da_hightlight_save
* DESCRIPTION
*   Handler of "SAVE" item to be highlisghted
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_scr_filename_ok(void)
{
    da_scr_context.storage_para.select_filename = FALSE;
    mmi_da_scr_select_storage(NULL, &da_scr_context.storage_para, 0, 0);
}

/*****************************************************************************
* FUNCTION
*   mmi_da_hightlight_save
* DESCRIPTION
*   Handler of "SAVE" item to be highlisghted
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_scr_hightlight_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_da_scr_filename_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_da_scr_filename_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_go_back_filename_editor
 * DESCRIPTION
 *  Go back to  dictionary editor screen(exact/wildcard).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_go_back_filename_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_DA_SCREEN_STORAGE_FILENAME);
}

/*****************************************************************************
* FUNCTION
*   mmi_da_hightlight_input_method
* DESCRIPTION
*   Handler of "Input Method" item to be highlisghted
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
static void mmi_da_scr_hightlight_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    RegisterInputMethodScreenCloseFunction(mmi_da_scr_go_back_filename_editor);
}

/*****************************************************************************
* FUNCTION
*   mmi_da_scr_delete_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static U8 mmi_da_scr_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC(mmi_da_scr_delete_callback);

    mmi_da_scr_storage_callback(NULL, TRUE);
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_scr_enter_marker_screen
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_scr_entry_marker_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!CheckIsBackHistory())
    {
        SetDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_STORAGE_MARKER, (HistoryDelCBPtr) mmi_da_scr_delete_callback);
        EntryNewScreen(SCR_ID_DA_SCREEN_STORAGE_MARKER, NULL, mmi_da_scr_entry_marker_screen, NULL);
    }
    else
    {
        ASSERT(0);
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_da_entry_abort_query
* DESCRIPTION
*   Ask user "Do you want to give up this file ?"
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
static void mmi_da_scr_abort_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_da_scr_storage_callback(NULL, FALSE);
    GoBackHistory();
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_scr_fake_overwrite_query_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IsScreenPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME));

    EntryNewScreen(SCR_ID_DA_CONFIRM_DUMMY, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_CONFIRM_SCREEN);
    mmi_da_scr_storage_callback(da_scr_context.filepath, FALSE);
    if(SCR_ID_DA_CONFIRM_DUMMY == GetActiveScreenId())
        GoBackHistory();
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_scr_overwrite_query_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fsret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IsScreenPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME));
    
    fsret = FS_Delete(da_scr_context.filepath);
    if(fsret < 0)
    {
        DisplayPopup((PU8) GetString((U16) GetFileSystemErrorString(fsret)), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                     (U8) ERROR_TONE);
    }
    else
    {
        EntryNewScreen(SCR_ID_DA_CONFIRM_DUMMY, NULL, NULL, NULL);
        DeleteScreenIfPresent(SCR_CONFIRM_SCREEN);
        mmi_da_scr_storage_callback(da_scr_context.filepath, FALSE);
        if(SCR_ID_DA_CONFIRM_DUMMY == GetActiveScreenId())
            GoBackHistory();
    }
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_scr_abort_rsk_hdlr(void)
{
    ASSERT(IsScreenPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME));
    da_scr_context.storage_reset_filename = TRUE;
    DeleteScreenIfPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION);
    GoBackHistory();
}

/*****************************************************************************
* FUNCTION
*   mmi_da_scr_storage_callback
* DESCRIPTION
*   pop the original context
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_scr_storage_callback(U16* filepath, BOOL in_delect_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     i;
    BOOL    canback = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DA_TRACE_FUNC1(mmi_da_scr_storage_callback, (U32)filepath);

    if( IsScreenPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME) && filepath != NULL)
        canback = TRUE;

    if( !da_scr_context.storage_callback(da_scr_context.storage_criteria, filepath, canback, (BOOL)(!in_delect_cb)) && canback)
    {
        da_scr_context.storage_reset_filename = TRUE;
        DeleteScreenIfPresent(SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION);
    }
    else
    {
        ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_STORAGE_MARKER, NULL);

        if(!in_delect_cb)
        {
            for ( i = SCR_ID_DA_SCREEN_STORAGE_BEGIN + 1; i < SCR_ID_DA_SCREEN_STORAGE_END; i++)
                DeleteScreenIfPresent(i);

            i = GetActiveScreenId();
            if( i > SCR_ID_DA_SCREEN_STORAGE_BEGIN && i < SCR_ID_DA_SCREEN_STORAGE_END )
                GoBackHistory();
        }        
        da_scr_context.storage_callback = NULL;
    }
}
#define AUTH_SCR

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_da_scr_user_auth(mmi_da_scr_auth_callback_type callback, U32 criteria, U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check re-entry */
    if(da_scr_context.auth_callback)
    {
        ASSERT(0);
        return;
    }

    da_scr_context.auth_callback = callback;
    da_scr_context.auth_criteria = criteria;
    memset(da_scr_context.auth_username, 0, sizeof(MMI_DA_AUTH_LEN_USERNAME));
    memset(da_scr_context.auth_password, 0, sizeof(MMI_DA_AUTH_LEN_PASSWORD));
    da_scr_context.auth_icon_id = mmi_da_util_get_icon_from_appid(app_id);

    mmi_da_scr_entry_auth();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_confirm_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_auth_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_AUTH, NULL);

    EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_DA_SCREEN_AUTH);
    da_scr_context.auth_callback(da_scr_context.auth_criteria,
                                 da_scr_context.auth_username,
                                 da_scr_context.auth_password,
                                 FALSE);
    da_scr_context.auth_callback = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_no_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_auth_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_AUTH, NULL);
    
    EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_DA_SCREEN_AUTH);
    GoBackHistory();
    da_scr_context.auth_callback(da_scr_context.auth_criteria, NULL, NULL, FALSE);
    da_scr_context.auth_callback = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_delete_callback
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_da_scr_auth_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_AUTH, NULL);

    da_scr_context.auth_callback(da_scr_context.auth_criteria, NULL, NULL, TRUE);
    da_scr_context.auth_callback = NULL;
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_confirm_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_auth_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_ucs2strlen((S8*)da_scr_context.auth_username) == 0)
    {
        DisplayPopup((PU8) GetString(STR_DA_EMPTY_USERNAME), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        return;
    }
    else
    {
        DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                       STR_GLOBAL_NO,  IMG_GLOBAL_NO,
                       get_string(STR_ID_DA_POPUP_SEND_ASK),
                       IMG_GLOBAL_QUESTION,
                       WARNING_TONE);
        
        SetLeftSoftkeyFunction(mmi_da_scr_auth_yes_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_da_scr_auth_no_hdlr, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_open_full_screen_editor
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_auth_open_full_screen_editor(void)
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
 *  mmi_da_scr_auth_full_screen_editor_options
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_auth_full_screen_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(da_scr_context.auth_icon_id);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_auth_softkey_highlight_hdlr
 * DESCRIPTION
 *  Custom Highlight handler to change the label of LSK in case of inline edit screen.
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_auth_softkey_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NumericKeys[11] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(mmi_da_scr_auth_open_full_screen_editor,
                       NumericKeys, 11, KEY_EVENT_UP);

    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
    
    SetLeftSoftkeyFunction(mmi_da_scr_auth_open_full_screen_editor, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_scr_exit_auth_handler
 * DESCRIPTION
 *  Exit function for authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_da_scr_exit_auth_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16     inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_DA_SCREEN_AUTH;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_da_scr_entry_auth;
    GetCategory57History(h.guiBuffer);
    
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) h.inputBuffer);             /* added for inline edit history */
    
    AddNHistory(h, (U16) inputBufferSize);
}

/*************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*************************************************************************/
static void mmi_da_scr_entry_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8          *guiBuffer;
    U8          *inputBuffer;
    U16         inputBufferSize;
    InlineItem  authenticate_list[4];
    U16         IconsImageList[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DA_SCREEN_AUTH, mmi_da_scr_exit_auth_handler, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DA_SCREEN_AUTH);

    InitializeCategory57Screen();

    memset(authenticate_list, 0, sizeof(authenticate_list));

    /* Username caption */
    SetInlineItemActivation(&authenticate_list[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&authenticate_list[0], (U8*)GetString(STR_GLOBAL_USERNAME));

    /* Username */
    SetInlineItemActivation(&authenticate_list[1], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(&authenticate_list[1],
                                STR_GLOBAL_USERNAME,
                                da_scr_context.auth_icon_id,
                                (U8*) da_scr_context.auth_username,
                                MMI_DA_AUTH_LEN_USERNAME,
                                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&authenticate_list[1],
                                          mmi_da_scr_auth_full_screen_editor_options);

    /* Password caption */
    SetInlineItemActivation(&authenticate_list[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&authenticate_list[2], (U8*) GetString(STR_GLOBAL_PASSWORD));

    /* Password */
    SetInlineItemActivation(&authenticate_list[3], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(&authenticate_list[3],
                                STR_GLOBAL_PASSWORD,
                                da_scr_context.auth_icon_id,
                                (U8*) da_scr_context.auth_password,
                                MMI_DA_AUTH_LEN_PASSWORD,
                                INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&authenticate_list[3],
                                          mmi_da_scr_auth_full_screen_editor_options);


    /* Other setting */
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DA_SCREEN_AUTH, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(authenticate_list, 4, inputBuffer);
    }

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_da_scr_auth_softkey_highlight_hdlr);

    IconsImageList[0] = gIndexIconsImageList[0];
    IconsImageList[1] = 0;
    IconsImageList[2] = gIndexIconsImageList[1];
    IconsImageList[3] = 0;

    SetDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_AUTH, (HistoryDelCBPtr) mmi_da_scr_auth_delete_callback);
    
    ShowCategory57Screen(
        STR_GLOBAL_AUTHENTICATION,
        da_scr_context.auth_icon_id,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_CANCEL,
        0,
        4,
        (U16*) IconsImageList,
        authenticate_list,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions( mmi_da_scr_auth_confirm_hdlr, mmi_da_scr_auth_no_hdlr);
}

#define PLEASE_WAIT

static void _mmi_da_scr_please_wait_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    da_scr_context.plzwait_callback(da_scr_context.plzwait_criteria, FALSE);
    mmi_da_scr_close_please_wait();
}

static U8 _mmi_da_scr_please_wait_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_scr_context.plzwait_callback)
        da_scr_context.plzwait_callback(da_scr_context.plzwait_criteria, TRUE);
    return MMI_FALSE;
}

static void _mmi_da_scr_entry_please_wait_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rsk_str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_scr_context.plzwait_callback)
        rsk_str_id = STR_GLOBAL_CANCEL;

    EntryNewScreen(SCR_ID_DA_SCREEN_PLEASE_WAIT, NULL, _mmi_da_scr_entry_please_wait_screen, NULL);
    ShowCategory66Screen(STR_GLOBAL_DOWNLOADING, da_scr_context.plzwait_icon_id,
                         0, 0, 
                         rsk_str_id, 0, 
                         (U8 *) GetString(STR_GLOBAL_PLEASE_WAIT), IMG_GLOBAL_PROGRESS, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_PLEASE_WAIT, (HistoryDelCBPtr) _mmi_da_scr_please_wait_delete_callback);

    if(da_scr_context.plzwait_callback)
        SetRightSoftkeyFunction(_mmi_da_scr_please_wait_rsk_hdlr, KEY_EVENT_UP);
}

void mmi_da_scr_close_please_wait(void)
{
    da_scr_context.plzwait_callback = NULL;
    da_scr_context.plzwait_criteria = 0;
    ClearDelScrnIDCallbackHandler(SCR_ID_DA_SCREEN_PLEASE_WAIT, NULL);
    if(GetActiveScreenId() == SCR_ID_DA_SCREEN_PLEASE_WAIT)
        GoBackHistory();
    else
        DeleteScreenIfPresent(SCR_ID_DA_SCREEN_PLEASE_WAIT);
}

void mmi_da_scr_entry_please_wait(U32 criteria, mmi_da_scr_abort_funcptr_type callback, U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    da_scr_context.plzwait_callback = callback;
    da_scr_context.plzwait_criteria = criteria;
    da_scr_context.plzwait_icon_id = mmi_da_util_get_icon_from_appid(app_id);

    _mmi_da_scr_entry_please_wait_screen();
}

#endif /* __MMI_DOWNLOAD_AGENT__ */
