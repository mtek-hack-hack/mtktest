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
 *  RightsMgrListRO.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  List RO screen of Rights Manager  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Include 
 */
#include "MMI_include.h"
#ifdef __MMI_RMGR__

#include "custom_mmi_default_value.h"
#include "RightsMgrProt.h"
#include "FileMgr.h"
#include "CommonScreens.h"
#include "SettingProfile.h"


#include "drm_gprot.h"
#include "drm_msg.h"

/*
 * Static Declaration
 */
typedef struct
{
    S8 alias[(FMGR_MAX_FILE_LEN + 1) *ENCODING_LENGTH];
    S32 currentIdx;
    S32 start;
    S32 end;
}rmgr_ro_cntx_struct;

/*
 * Global Variable
 */

/*
 * Local Function
 */
static void mmi_rmgr_list_ro_main_highlight_hdlr(S32 menu_idx);
static void mmi_rmgr_list_ro_set_execute_key_hdlr(FuncPtr key_hdlr);
static void mmi_rmgr_list_ro_entry_detail(void);
static void mmi_rmgr_list_ro_delete_entry(void);
static void mmi_rmgr_list_ro_entry_delete(void);
static void mmi_rmgr_list_ro_option_highlight_hdlr(S32 menu_idx);
static void mmi_rmgr_list_ro_entry_option(void);

/*
 * Local Variable
 */

pBOOL mmi_rmgr_get_alias_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_get_ro_list(item_index, (char *)&mmi_rmgr_p->alias[0], FMGR_MAX_FILE_LEN * ENCODING_LENGTH))
    {
        *img_buff_p = get_image(IMG_SI_KEYPAD_UNLOCK);
    }
    else
    {
        *img_buff_p = get_image(IMG_SI_KEYPAD_LOCK);
    }
    mmi_ucs2ncpy((S8 *)str_buff, (const S8 *)&mmi_rmgr_p->alias[0], sizeof(mmi_rmgr_p->alias));

    return MMI_TRUE;
}


S32 mmi_rmgr_get_alias_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_array = NULL;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_main_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the list ro main screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_main_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->ro_idx = menu_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_set_execute_key_hdlr
 * DESCRIPTION
 *  Set the execution key handler
 * PARAMETERS
 *  key_hdlr        [IN]        Key handler function pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_set_execute_key_hdlr(FuncPtr key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(key_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_entry_detail
 * DESCRIPTION
 *  Entry function of the list ro detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_entry_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_LIST_RO_DETAIL, NULL, mmi_rmgr_list_ro_entry_detail, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_LIST_RO_DETAIL);

    info = (PU8) subMenuData;

    /* Shared */
    mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_ID_RMGR_SHARED_RO));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    
    if (DRM_get_ro_shareability(mmi_rmgr_p->ro_idx))
    {
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_YES));
    }
    else
    {
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_NO));
    }
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
   
    /* Summary */
    mmi_rmgr_populate_drm_info_aux(NULL, DRM_PERMISSION_ALL, info, mmi_rmgr_p->ro_idx);
        
    ShowCategory74Screen(
        STR_ID_RMGR,
        mmi_rmgr_get_root_icon(),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_del_cnf_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_del_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_process_database_cnf_struct *local_data = (drmt_process_database_cnf_struct *) msg;
    S32 max_ro_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (local_data->result)
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            SUCCESS_TONE);
    else
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR), 
            IMG_GLOBAL_ERROR, 
            0, 
            UI_POPUP_NOTIFYDURATION_TIME_2000, 
            ERROR_TONE);

    DeleteScreenIfPresent(SCR_ID_RMGR_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_RMGR_LIST_RO_OPTION);

    
    /* display sweep done popup only when the active screen is sweep progress */
    if (GetActiveScreenId() == SCR_ID_RMGR_PROGRESS)
    {
        GoBackHistory();
    }

    max_ro_num = DRM_get_ro_num();

    if (max_ro_num == 0)
    {
        DeleteScreenIfPresent(SCR_ID_RMGR_LIST_RO_MAIN);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_delete_entry
 * DESCRIPTION
 *  Entry function of the list ro delete done screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_delete_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_entry_db_progressing();

    SetProtocolEventHandler(mmi_rmgr_list_ro_del_cnf_hdlr, MSG_ID_DRMT_PROCESS_DATABASE_CNF);

    /* send the sweep request message */
    mmi_rmgr_send_process_database_req(DRMT_PROCESS_DATABASE_DELETE, mmi_rmgr_p->ro_idx, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_entry_delete
 * DESCRIPTION
 *  Entry function of the list ro delete screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_entry_delete(void)
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
        (U16*) GetString(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_rmgr_list_ro_delete_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the list ro option screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_option_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_idx == 0)
    {
        mmi_rmgr_list_ro_set_execute_key_hdlr(mmi_rmgr_list_ro_entry_detail);
    }
    else
    {
        mmi_rmgr_list_ro_set_execute_key_hdlr(mmi_rmgr_list_ro_entry_delete);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_entry_option
 * DESCRIPTION
 *  Entry function of the list ro option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_list_ro_entry_option(void)
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
    EntryNewScreen(SCR_ID_RMGR_LIST_RO_OPTION, NULL, mmi_rmgr_list_ro_entry_option, NULL);

    nItems = GetNumOfChild(MENU_ID_RMGR_LIST_RO_ALIAS_OPTION);
    GetSequenceStringIds(MENU_ID_RMGR_LIST_RO_ALIAS_OPTION, ItemList);
    GetSequenceImageIds(MENU_ID_RMGR_LIST_RO_ALIAS_OPTION, ItemIcons);

    MMI_ASSERT(nItems <= MAX_SUB_MENUS);

    RegisterHighlightHandler(mmi_rmgr_list_ro_option_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_LIST_RO_OPTION);

    ShowCategory52Screen(
        STR_ID_RMGR,
        mmi_rmgr_get_root_icon(),
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

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_entry_main
 * DESCRIPTION
 *  Entry function of the list ro main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_list_ro_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_ro_num;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_LIST_RO_MAIN, NULL, mmi_rmgr_list_ro_entry_main, NULL);

    max_ro_num = DRM_get_ro_num();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_LIST_RO_MAIN);

    if (!max_ro_num)
    {   
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 2000, EMPTY_LIST_TONE);
        DeleteScreenIfPresent(SCR_ID_RMGR_LIST_RO_MAIN);
        return;
    }
    
    RegisterHighlightHandler(mmi_rmgr_list_ro_main_highlight_hdlr);

    ShowCategory284Screen(
        STR_ID_RMGR,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        max_ro_num,
        mmi_rmgr_get_alias_item,
        mmi_rmgr_get_alias_hint,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    mmi_rmgr_list_ro_set_execute_key_hdlr(mmi_rmgr_list_ro_entry_option);
}

#endif /* __MMI_RMGR__ */ 
