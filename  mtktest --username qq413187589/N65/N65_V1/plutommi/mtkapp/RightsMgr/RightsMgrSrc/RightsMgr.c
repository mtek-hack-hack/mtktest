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
 *  RightsMgr.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*
 * Include
 */
#include "MMI_include.h"
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#include "custom_mmi_default_value.h"
#include "RightsMgrProt.h"

#include "CommonScreens.h"
#include "SettingProfile.h"

#include "drm_msg.h"
#include "ProtocolEvents.h"
#include "FileManagerDef.h"
#include "FileManagerGprot.h"

/*
 * Local
 */
kal_bool mmi_drm_init_ready = KAL_FALSE;
static const FsErrorEntryStruct DRMErrorTable[] = 
{
    {DRM_RESULT_NOT_SUPPORT,         STR_ID_FMGR_DRM_NOT_SUPPORT},
    {DRM_RESULT_NON_DRM,             STR_GLOBAL_DRM_NON_DRM},
    {DRM_RESULT_NOT_ARCHIVE,         STR_ID_FMGR_DRM_NOT_ARCHIVE},
    {DRM_RESULT_FS_ERROR,            STR_GLOBAL_DRM_FS_ERROR},
    {DRM_RESULT_BAD_CONTENT_TYPE,    STR_ID_FMGR_DRM_BAD_CONTENT_TYPE},
    {DRM_RESULT_INVALID_FORMAT,      STR_GLOBAL_DRM_INVALID_FORMAT},
    {DRM_RESULT_INVALID_PATH,        STR_ID_FMGR_DRM_INVALID_PATH},
    {DRM_RESULT_SIZE_TOO_BIG,        STR_GLOBAL_DRM_SIZE_TOO_BIG},
    {DRM_RESULT_NO_PERMISSION,       STR_ID_FMGR_DRM_NO_PERMISSION},
    {DRM_RESULT_FILE_EXISTS,         STR_GLOBAL_DRM_FILE_EXISTS},
    {DRM_RESULT_INVALID_KEY,         STR_ID_FMGR_DRM_INVALID_KEY},
    {DRM_RESULT_INVALID_RIGHT,       STR_ID_DRM_INVALID_RO},
    {DRM_RESULT_INVALID_PARA,        STR_ID_FMGR_DRM_INVALID_PARA},
    {DRM_RESULT_INVALID_CERT,        STR_ID_DRM_INVALID_CERT},
    {DRM_RESULT_CERT_EXPIRED,        STR_ID_DRM_CERT_EXPIRED},
    {DRM_RESULT_EOF,                 STR_ID_FMGR_DRM_EOF},
    {DRM_RESULT_TRUNCATED,           STR_ID_FMGR_DRM_TRUNCATED},
    {DRM_RESULT_BUSY,                STR_ID_FMGR_DRM_BUSY},
    {DRM_RESULT_CANCELED,            STR_ID_FMGR_DRM_CANCELED},

    {DRM_RESULT_NO_MEMORY,           STR_ID_DRM_NO_MEMORY},
    {DRM_RESULT_DATA_NOT_FOUND,      STR_ID_DRM_NOT_FOUND},
    {DRM_RESULT_KEY_NOT_FOUND,       STR_ID_DRM_KEY_NOT_FOUND},
    {DRM_RESULT_CERT_NOT_FOUND,      STR_ID_DRM_CERT_NOT_FOUND},
    {DRM_RESULT_NOT_IN_DOMAIN,       STR_ID_DRM_NOT_IN_DOMAIN},
    {DRM_RESULT_NOT_REGISTERED,      STR_ID_DRM_NOT_REGISTERED},
    {DRM_RESULT_NO_RIGHTS,           STR_ID_DRM_NO_RIGHTS},
    {DRM_RESULT_REGISTRATION_FAILED, STR_ID_DRM_REG_FAILED},
    {DRM_RESULT_JOIN_DOMAIN_FAILED,  STR_ID_DRM_DOMAIN_JOIN_FAILED},
    {DRM_RESULT_LEAVE_DOMAIN_FAILED, STR_ID_DRM_DOMAIN_LEAVE_FAILED},
    {DRM_RESULT_DOMAIN_EXPIRED,      STR_ID_DRM_DOMAIN_EXPIRED},
    {DRM_RESULT_NEED_DOMAIN_UPGD,    STR_ID_DRM_NEED_DOMAIN_UPGD},
    {DRM_RESULT_INVALID_DRMTIME,     STR_ID_DRM_INVALID_DRMTIME},
    {DRM_RESULT_NETWORK_ERROR,       STR_ID_DRM_NETWORK_ERROR},
    {DRM_RESULT_DATABASE_ERROR,      STR_ID_DRM_DATABASE_ERROR},
    {DRM_RESULT_TIME_UNTRUSTED,      STR_ID_DRM_TIME_UNTRUSTED},

    {DRM_RESULT_UNKNOWN_ERROR,       STR_ID_FMGR_DRM_PROCESS_ERROR},

    {DRM_RESULT_NO_PERMISSION,       STR_GLOBAL_DRM_PROHIBITED},
    {0, 0}        
};


#ifdef __MMI_RMGR__
static mmi_rmgr_cntx_struct g_mmi_rmgr_cntx;    /* rights manager context */

static void mmi_rmgr_toggle_trans(void);
static void mmi_rmgr_show_trans_LSK_and_hint(void);

static void mmi_rmgr_set_execute_key_hdlr(FuncPtr key_hdlr);

static void mmi_rmgr_highlight_main(void);
static void mmi_rmgr_highlight_list_ro(void);
static void mmi_rmgr_highlight_trans(void);
static void mmi_rmgr_highlight_whitelist(void);
static void mmi_rmgr_highlight_info(void);
static void mmi_rmgr_highlight_db_proc(void);
static void mmi_rmgr_highlight_hdlr(S32 menu_idx);

static void mmi_rmgr_entry_main(void);


/*
 * Global Variable
 */
mmi_rmgr_cntx_struct *const mmi_rmgr_p = &g_mmi_rmgr_cntx;  /* rights manager pointer */
const U16 g_mmi_rmgr_number_icons[] =
{
    IMG_GLOBAL_L1, IMG_GLOBAL_L2, IMG_GLOBAL_L3, IMG_GLOBAL_L4,
    IMG_GLOBAL_L5, IMG_GLOBAL_L6, IMG_GLOBAL_L7, IMG_GLOBAL_L8,
    IMG_GLOBAL_L9, IMG_GLOBAL_L10
};

/* 
 * External Variable
 */
extern kal_bool g_mmi_rmgr_switch_cermgr;


/* 
 * External function
 */
extern void mmi_drm_ui_init(void);

/*****************************************************************************
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_get_root_icon
 * DESCRIPTION
 *  To get menu root icon
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_rmgr_get_root_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetRootTitleIcon(MAIN_MENU_SERVICES_MENUID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_show_trans_LSK_and_hint
 * DESCRIPTION
 *  Update and show trans LSK and hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_show_trans_LSK_and_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 highlight_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_idx = GetCurrHiliteID();

    if (mmi_rmgr_p->trans_state)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
        mmi_ucs2cpy((S8*) hintData[highlight_idx], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
        mmi_ucs2cpy((S8*) hintData[highlight_idx], (S8*) GetString(STR_GLOBAL_OFF));
    }

    Category52ChangeItemDescription(highlight_idx, hintData[highlight_idx]);
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_toggle_trans
 * DESCRIPTION
 *  Toggle trans state on the fly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_toggle_trans(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->trans_state = DRM_toggle_tracking(MMI_FALSE);

    /* show the LSK and hint of the trans state */
    mmi_rmgr_show_trans_LSK_and_hint();

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_set_execute_key_hdlr
 * DESCRIPTION
 *  Set the execution key handler
 * PARAMETERS
 *  key_hdlr        [IN]        Key handler function pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_set_execute_key_hdlr(FuncPtr key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(key_hdlr, KEY_EVENT_UP);
    SetKeyHandler(key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_main
 * DESCRIPTION
 *  Highlight handler of the rights manager screen in the services menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set default white list url index as 0 */
    mmi_rmgr_p->url_sel_idx = 0;
    mmi_rmgr_p->rmgr_sel_idx = 0;

    SetLeftSoftkeyFunction(mmi_rmgr_entry_main, KEY_EVENT_UP);
    SetKeyHandler(mmi_rmgr_entry_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_list_ro
 * DESCRIPTION
 *  Hightlight handler of the list RO
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_list_ro(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_list_ro_entry_main);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_trans
 * DESCRIPTION
 *  Hightlight handler of the trans tracking
 *  including hints
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_trans(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_rmgr_toggle_trans, KEY_EVENT_UP);

    mmi_rmgr_show_trans_LSK_and_hint();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_whitelist
 * DESCRIPTION
 *  Hightlight handler of the white list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_whitelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_whitelist_entry_main);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_info
 * DESCRIPTION
 *  Hightlight handler of the general info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_gen_info_entry_main);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_db_proc
 * DESCRIPTION
 *  Hightlight handler of db proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_db_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_rmgr_entry_db, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_cermgr
 * DESCRIPTION
 *  Hightlight handler of the HTTP profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_cermgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_entry_fmgr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_hint_trans
 * DESCRIPTION
 *  Hint handler for trans. tracking ON/OFF
 * PARAMETERS
 *  hint_idx        [IN]        Hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_hint_trans(U16 hint_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_rmgr_p->trans_state)
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the rights manager main screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->rmgr_sel_idx = menu_idx;

    if (GetSeqItemId(MENU_ID_RMGR, (U16) menu_idx) != MENU_ID_RMGR_TRANS)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }

    ExecuteCurrHiliteHandler(menu_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_main
 * DESCRIPTION
 *  Entry function of the rights manager main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U8 *hints[MAX_SUB_MENUS];
    U16 nItems;

    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_MAIN, NULL, mmi_rmgr_entry_main, NULL);
    if (g_mmi_rmgr_switch_cermgr)
    {
        mmi_frm_unhide_menu_item(MENU_ID_RMGR_CERMGR);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_RMGR_CERMGR);
    }

    nItems = GetNumOfChild_Ext(MENU_ID_RMGR);
    GetSequenceStringIds_Ext(MENU_ID_RMGR, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_RMGR, ItemIcons);
    SetParentHandler(MENU_ID_RMGR);

    ConstructHintsList(MENU_ID_RMGR, (U8 **) hints);

    RegisterHighlightHandler(mmi_rmgr_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_MAIN);
    
    
    ShowCategory52Screen(
        STR_ID_RMGR,
        GetRootTitleIcon(MAIN_MENU_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        mmi_rmgr_p->rmgr_sel_idx,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_ID_RMGR_LIST_RO_MAIN, (HistoryDelCBPtr)DRM_free_ro_list);
}


/*****************************************************************************
 * Global Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_init
 * DESCRIPTION
 *  Init function of rights manager application, called in InitService()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* test urls */

    mmi_rmgr_p->trans_state = DRM_toggle_tracking(MMI_TRUE);

    /* highlight handler of services menu */
    SetHiliteHandler(MENU_ID_RMGR, mmi_rmgr_highlight_main);

    /* highlight handlers of RMGR menu */
    SetHiliteHandler(MENU_ID_RMGR_LIST_RO, mmi_rmgr_highlight_list_ro);
    SetHiliteHandler(MENU_ID_RMGR_TRANS, mmi_rmgr_highlight_trans);
    SetHiliteHandler(MENU_ID_RMGR_WHITE_LIST, mmi_rmgr_highlight_whitelist);
    SetHiliteHandler(MENU_ID_RMGR_INFO, mmi_rmgr_highlight_info);
    SetHiliteHandler(MENU_ID_RMGR_DB_PROC, mmi_rmgr_highlight_db_proc);

    SetHiliteHandler(MENU_ID_RMGR_CERMGR, mmi_rmgr_highlight_cermgr);

    /* hint handler of trans. tracking state */
    SetHintHandler(MENU_ID_RMGR_TRANS, mmi_rmgr_hint_trans);

}
#endif /* __MMI_RMGR__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_info_aux
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rights          [?]         
 *  permission      [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_rmgr_populate_drm_info_aux(kal_wchar *path, kal_uint8 app_perm, kal_uint8 *data, kal_int32 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input = FS_ERROR_RESERVED;
    kal_int32 start = 0, end = 0, cons_ret = DRM_RESULT_NON_DRM;
    kal_bool ret = KAL_FALSE, flag = KAL_TRUE;
    kal_uint8 permission;
    drm_method_enum method;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* permission's incorrect, but ok here*/
    if (app_perm == DRM_PERMISSION_ALL)
         permission = DRM_PERMISSION_PLAY;
    else
        permission = app_perm;
    
    if(ref < 0)
    {
        input = DRM_open_file(path, FS_READ_ONLY, permission);

        if (input < FS_NO_ERROR)
            return ret;
        
        method = DRM_get_object_method(input, NULL);    
    }
    else
    {
        method = DRM_get_object_method_by_ref(ref);
    }
    
    if (method != DRM_METHOD_NONE)
    {
        if (ref < 0)
        {
            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_RIGHT));
            mmi_ucs2cat((PS8) data, (PS8) L"\n");
            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_PROTECTED));
            mmi_ucs2cat((PS8) data, (PS8) L"\n");
        }
    }
    else
    {
        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_RIGHT));
        mmi_ucs2cat((PS8) data, (PS8) L"\n");
        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNPROTECTED));
        mmi_ucs2cat((PS8) data, (PS8) L"\n");

        if (ref < 0)
        {
            DRM_close_file(input);
        }
        else
        {
            DRM_free_ro_detail();
        }
        return ret;
    }

#ifdef __DRM_V02__
    if (ref < 0)
    {
        kal_wchar *sepa = kal_wstrrchr(path, (kal_int32) '\\');
    
        if (DRM_is_archive(input, NULL) && sepa && kal_wstrncmp(sepa - 4, L".odf\\", 5) != 0)
        {
            /* Multi Part ODF */
            mmi_ucs2cat((PS8) data, (PS8) L" ");
            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_MULTI_PART));
            mmi_ucs2cat((PS8) data, (PS8) L"\n");
            return ret;
        }
    }
#endif    
    
    if (method == DRM_METHOD_FORWARD_LOCK)
    {
        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY));
        mmi_ucs2cat((PS8) data, (PS8) L"\n");
        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED));
        mmi_ucs2cat((PS8) data, (PS8) L"\n");
        
        if (ref < 0)
        {
            DRM_close_file(input);
        }
        else
        {
            DRM_free_ro_detail();
        }
        return ret;
    }

   
    do
    {
        if (permission & (DRM_PERMISSION_PLAY | DRM_PERMISSION_DISPLAY | DRM_PERMISSION_EXECUTE | DRM_PERMISSION_PRINT | DRM_PERMISSION_EXPORT))
        {
            drm_constraint_struct cons;
            if (ref < 0)
            {
                if (app_perm == DRM_PERMISSION_ALL && permission != DRM_PERMISSION_PLAY)
                {
                    input = DRM_open_file(path, FS_READ_ONLY, permission);

                    if (input < FS_NO_ERROR)
                        return KAL_FALSE;
                }
                
                cons_ret = DRM_get_constraint(input, NULL, permission, &cons);
            }
            else
            {
                cons_ret = DRM_get_constraint_by_ref(ref, permission, &cons);
            }
            
            if (cons_ret >= DRM_RESULT_OK && cons.status == DRM_STATUS_RIGHTS_PRESENT)
            {
                
                if (flag)
                {
                    mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY));
                    mmi_ucs2cat((PS8) data, (PS8) L"\n");
                    flag = KAL_FALSE;
                }

                switch(permission)
                {
                    case DRM_PERMISSION_PLAY:
                        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_DRM_PLAY));
                        mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        break;
                    case DRM_PERMISSION_DISPLAY:
                        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_DRM_DISPLAY));
                        mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        break;
                    case DRM_PERMISSION_EXECUTE:
                        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_DRM_EXECUTE));
                        mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        break;
                    case DRM_PERMISSION_PRINT:
                        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_DRM_PRINT));
                        mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        break;
                    case DRM_PERMISSION_EXPORT:
                        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_DRM_EXPORT));
                        mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        break;
                    default:
                        break;
                }

                if (((method & DRM_METHOD_COMBINED_DELIVERY) ||
                     (method & DRM_METHOD_SEPARATE_DELIVERY) || 
                     (method & DRM_METHOD_V2)) &&
                    (cons.status != DRM_STATUS_NO_RIGHTS))
                {
                
                    MYTIME t;
                    S8 buffer[20];
                    drm_constraint_struct *constraint;
                
                    constraint = &cons;
                    
                    if (constraint->type != DRM_CONSTRAINT_NONE)
                    {
                        if (constraint->type & DRM_CONSTRAINT_COUNT)
                        {
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_COUNT));
                            sprintf((char*)buffer, "\n%d/%d", constraint->used_count, constraint->total_count);
                            mmi_asc_to_ucs2((PS8) & data[mmi_ucs2strlen((PS8) data) << 1], (PS8) buffer);
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        }

                #ifdef __DRM_V02__
                        if (constraint->type & DRM_CONSTRAINT_ACCUMULATED)
                        {
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_ACCUMULATED));
                            sprintf((char*)buffer, "\n%d ", constraint->accum_dur);
                            mmi_asc_to_ucs2((PS8) & data[mmi_ucs2strlen((PS8) data) << 1], (PS8) buffer);
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_SEC));
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        }
                    
                        if (constraint->type & DRM_CONSTRAINT_TIMEDCOUNT)
                        {
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_TIMEDCOUNT));
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");
                            sprintf((char*)buffer, "%d ", constraint->timed_count);
                            mmi_asc_to_ucs2((PS8) & data[mmi_ucs2strlen((PS8) data) << 1], (PS8) buffer);
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_TIMEDCOUNT_TIME));
                            sprintf((char*)buffer, "%d ", constraint->period);
                            mmi_asc_to_ucs2((PS8) & data[mmi_ucs2strlen((PS8) data) << 1], (PS8) buffer);
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_SEC));
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        }
                #endif /* __DRM_V02__ */

                        if (constraint->type & DRM_CONSTRAINT_DATETIME)
                        {
                            if ((constraint->type & DRM_CONSTRAINT_INTERVAL) && constraint->start_intv != 0)
                            {
                                 /* date time contains interval -> show interval*/
                                 if (constraint->start_time <= constraint->start_intv &&
                                      constraint->end_time >= constraint->end_intv)
                                 {
                                          start = constraint->start_intv;
                                          end = constraint->end_intv;
                                 }
                                 /* interval contains date time -> show date time*/
                                 else if (constraint->start_intv <= constraint->start_time &&
                                      constraint->end_intv >= constraint->end_time)
                                 {
                                          start = constraint->start_time;
                                          end = constraint->end_time;
                                 }
                                 /* date time overlaps interval -> show overlap*/
                                 else if (constraint->start_intv <= constraint->start_time &&
                                      constraint->end_intv <= constraint->end_time && 
                                      constraint->start_time <= constraint->end_intv)
                                 {
                                          start = constraint->start_time;
                                          end = constraint->end_intv;
                                 }
                                 /* interval overlaps date time -> show overlap*/
                                 else if (constraint->start_time <= constraint->start_intv &&
                                      constraint->end_time <= constraint->end_intv &&
                                      constraint->start_intv <= constraint->end_time)
                                 {
                                      start = constraint->start_intv;
                                    end = constraint->end_time;
                                 }
                                 else
                                 {
                                          start = constraint->start_intv;
                                          end = constraint->end_intv;
                                 }
                            }
                            else
                            {
                                start = constraint->start_time;
                                end = constraint->end_time;
                            }
                        }
                        else if (constraint->type & DRM_CONSTRAINT_INTERVAL)
                        {
                            if (constraint->interval <= 0)
                            {
                                start = -1;
                                end = -1;
                            }
                            else
                            {
                                start = constraint->start_intv;
                                end = constraint->end_intv;
                            }
                        }
                        
                        if (start > 0)
                        {
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_START));
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");
                            mmi_dt_utc_sec_2_mytime(start, &t, FALSE);
                            date_string(&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                            mmi_ucs2cat((PS8) data, (PS8) L" ");
                            time_string(&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");
                        }
                    
                        if (end > 0)
                        {
                            mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_END));
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");
                            mmi_dt_utc_sec_2_mytime(end, &t, FALSE);
                            date_string(&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                            mmi_ucs2cat((PS8) data, (PS8) L" ");
                            time_string(&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                            mmi_ucs2cat((PS8) data, (PS8) L"\n");                    
                        }
                    }
                    else
                    {
                        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED));
                        mmi_ucs2cat((PS8) data, (PS8) L"\n");
                    }

                }
                
            }

            if (ref < 0)
            {
                DRM_close_file(input);
            }

        }

        permission = permission<<1;
    }
    while(permission < DRM_PERMISSION_ALL && app_perm == DRM_PERMISSION_ALL);
    
    if (flag)
    {
        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY));
        mmi_ucs2cat((PS8) data, (PS8) L"\n");
        mmi_ucs2cat((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID));
        mmi_ucs2cat((PS8) data, (PS8) L"\n");
    }

    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rights          [?]         
 *  permission      [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_rmgr_populate_drm_info(kal_wchar *path, kal_uint8 app_perm, kal_uint8 *data)
{
    return mmi_rmgr_populate_drm_info_aux(path, app_perm, data, -1);
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_ID_TYPE mmi_rmgr_get_err_string(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = 0; DRMErrorTable[i].errorNo != 0; i++)
        if (DRMErrorTable[i].errorNo == error)
        {
            return DRMErrorTable[i].stringId;
        }

        return STR_ID_FMGR_DRM_PROCESS_ERROR;
   
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_drm_send_get_imsi_cnf(U8* imsi, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MYQUEUE Message;
    drmt_get_imsi_cnf_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (drmt_get_imsi_cnf_struct*) OslConstructDataPtr(sizeof(drmt_get_imsi_cnf_struct));

    msg->result = result;
    memset(msg->imsi, 0, sizeof(msg->imsi));

    if( result == MMI_TRUE )
    {
        for( i = 0 ;i < 17; i++)
        {
            msg->imsi[i] = imsi[i];
        }
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_DRMT;
    Message.oslSapId = DRMT_MMI_SAP;
    Message.oslMsgId = MSG_ID_DRMT_GET_IMSI_CNF;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_recv_get_imsi_rsp
 * DESCRIPTION
 *  get the sim card IMSI
 * PARAMETERS
 *  MsgStruct   [In]    Message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_recv_l4_get_imsi_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_imsi_rsp_struct* msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_smu_get_imsi_rsp_struct*)MsgStruct;

    mmi_drm_send_get_imsi_cnf(msg->imsi, msg->result);
 }

/*****************************************************************************
 * FUNCTION
 *  mmi_drm_send_get_imsi_req
 * DESCRIPTION
 *  Send the message PRT_GET_IMSI_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_drm_send_l4_get_imsi_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_drm_recv_l4_get_imsi_rsp, PRT_GET_IMSI_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslSapId = MMI_L4C_SAP;
    Message.oslMsgId = PRT_GET_IMSI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
 }

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_drm_recv_get_imsi_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_drm_send_l4_get_imsi_req();
}


void mmi_drm_init(void)
{
    SetProtocolEventHandler(DRM_app_process_obj_hdlr, MSG_ID_DRMT_PROCESS_OBJECT_CNF);
    SetProtocolEventHandler(DRM_app_install_obj_hdlr, MSG_ID_DRMT_INSTALL_OBJECT_CNF);
    #ifdef __DRM_V02__
    SetProtocolEventHandler(DRM_app_ro_expiry_hdlr, MSG_ID_DRMT_RO_EXPIRY_IND);
    SetProtocolEventHandler(DRM_app_activate_hdlr, MSG_ID_DRMT_ACTIVATE_CNF);
    #endif
    mmi_drm_ui_init();
}
#endif
