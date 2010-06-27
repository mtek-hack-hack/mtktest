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
 *  RightsMgrSweep.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Sweep screen of Rights Manager
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_RMGR__

#include "custom_mmi_default_value.h"
#include "RightsMgrProt.h"

#include "CommonScreens.h"
#include "SettingProfile.h"

#include "drm_gprot.h"
#include "drm_msg.h"

#include "Conversions.h"
/*
 * Define
 */
typedef enum
{
    MMI_RMGR_DB_SWEEP,
    MMI_RMGR_DB_BACKUP,
    MMI_RMGR_DB_RESTORE,
    MMI_RMGR_DB_MAX
}mmi_rmgr_db_enum;

/*
 * Global Variable
 */
kal_bool g_mmi_rmgr_switch_cermgr = KAL_FALSE;

/*
 * External Variable
 */
extern const U16 g_mmi_rmgr_number_icons[];

/*
 * Local Function
 */
static void mmi_rmgr_sweep_entry_progress(void);
 
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_switch_cermgr
 * DESCRIPTION
 *  show/hide Import Certificate menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_switch_cermgr(void)
{
    if (g_mmi_rmgr_switch_cermgr)
        g_mmi_rmgr_switch_cermgr = KAL_FALSE;
    else
        g_mmi_rmgr_switch_cermgr = KAL_TRUE;

    GoBackHistory();
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_db_progressing
 * DESCRIPTION
 *  process screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_entry_db_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_PROGRESS, NULL, mmi_rmgr_entry_db_progressing, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_PROGRESS);

    ShowCategory65Screen((U8*) GetString(STR_GLOBAL_DRM_PROCESSING), IMG_GLOBAL_PROGRESS, guiBuffer);

    /* disable pen */
    ClearInputEventHandler(MMI_DEVICE_PEN);

    /* 
     * disable key
     *
     * ClearInputEventHandler(MMI_DEVICE_KEY) leaves KEY_END and volume keys 
     * avaiable, so call SetGroupKeyHandler() to disable all key handlers.
     */
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_sweep_entry_progress
 * DESCRIPTION
 *  Entry function of the sweep progress screen, should hold for the response.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_sweep_entry_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_entry_db_progressing();

    SetProtocolEventHandler(mmi_rmgr_send_process_database_cnf, MSG_ID_DRMT_PROCESS_DATABASE_CNF);
    
    /* send the sweep request message */
    mmi_rmgr_send_process_database_req(DRMT_PROCESS_DATABASE_SWEEP, -1,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_process_database_req
 * DESCRIPTION
 *  Send the process database request message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_send_process_database_req(kal_uint8 type, kal_int32 index, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    drmt_process_database_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (drmt_process_database_req_struct*) OslConstructDataPtr(sizeof(drmt_process_database_req_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_DRMT;
    Message.oslMsgId = MSG_ID_DRMT_PROCESS_DATABASE_REQ;
    req->type = type;
    req->index = index;
    if (path)
    {
        mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)path, (char*)req->path, kal_wstrlen(path) * 3);
    }
    else
    {
        req->path[0] = '\0';
    }
    Message.oslDataPtr = (oslParaType*)req;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_process_database_cnf
 * DESCRIPTION
 *  The protocol event handler for the sweep response msg, If there is another
 *  screen jumping in, simply remove the history node of the sweep progress screen.
 *  When the interrupter screen goes back history, it will display the rights
 *  manager screen. Otherwise, enter the sweep done screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_send_process_database_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_process_database_cnf_struct *local_data = (drmt_process_database_cnf_struct *) msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_RMGR_PROGRESS);

    /* display sweep done popup only when the active screen is sweep progress */
    if (GetActiveScreenId() == SCR_ID_RMGR_PROGRESS)
    {
        GoBackHistory();
    }

    if (local_data->result)
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    else
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR), 
            IMG_GLOBAL_ERROR, 
            0, 
            UI_POPUP_NOTIFYDURATION_TIME, 
            ERROR_TONE);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_sweep_entry_main
 * DESCRIPTION
 *  Entry function of sweep main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_sweep_entry_main(void)
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
        (U16*) GetString(STR_ID_RMGR_SWEEP_REMOVE_RIGHTS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_rmgr_sweep_entry_progress, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_db_highlight
 * DESCRIPTION
 *  Highlight handler of db proc option
 * PARAMETERS
 *  menu_idx        [IN]        Highlight menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_db_highlight(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->current_idx = menu_idx;
    switch (menu_idx)
    {
        case MMI_RMGR_DB_SWEEP:
        {
            SetLeftSoftkeyFunction(mmi_rmgr_sweep_entry_main, KEY_EVENT_UP);
            break;
        }
        case MMI_RMGR_DB_BACKUP:
        case MMI_RMGR_DB_RESTORE:
        {
            SetLeftSoftkeyFunction(mmi_rmgr_entry_fmgr, KEY_EVENT_UP);
            SetKeyHandler(mmi_rmgr_entry_fmgr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_db
 * DESCRIPTION
 *  Entry function of db proc main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_entry_db(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    const U16 item_text[] = {STR_ID_RMGR_SWEEP, STR_ID_RMGR_BACKUP, STR_ID_RMGR_RESTORE};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_DB_PROC, NULL, mmi_rmgr_entry_db, NULL);
        
    RegisterHighlightHandler(mmi_rmgr_db_highlight);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_DB_PROC);

    ShowCategory52Screen(
        STR_ID_RMGR,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        3,
        (U16*) item_text,
        (U16*) g_mmi_rmgr_number_icons,
        NULL,
        0,
        0,
        guiBuffer);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_select_file
 * DESCRIPTION
 *  Callback function for file manager when shared folder selection is finished.
 * PARAMETERS
 *  path            [IN]        User selected path
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_select_file_result(kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    
    if (error < 0)
    {
        S8 str_buf[20], unicode_buf[40];
        
        sprintf(str_buf, "Error: -0x%8x", -error);
        mmi_asc_to_ucs2(unicode_buf, str_buf);
        DisplayPopup(
            (U8 *)unicode_buf,
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_select_file
 * DESCRIPTION
 *  Callback function for file manager when shared folder selection is finished.
 * PARAMETERS
 *  path            [IN]        User selected path
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_select_file(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path)
    {
        kal_uint16 menu_seq = GetSeqItemId(MENU_ID_RMGR, (U16) mmi_rmgr_p->rmgr_sel_idx);
        
        switch(menu_seq)
        {
            case MENU_ID_RMGR_DB_PROC:
            {
                mmi_rmgr_entry_db_progressing();
                SetProtocolEventHandler(mmi_rmgr_send_process_database_cnf, MSG_ID_DRMT_PROCESS_DATABASE_CNF);
                if (mmi_rmgr_p->current_idx == MMI_RMGR_DB_BACKUP)
                {
                    mmi_rmgr_send_process_database_req(DRMT_PROCESS_DATABASE_BACKUP, 0, path);
                }
                else if (mmi_rmgr_p->current_idx == MMI_RMGR_DB_RESTORE)
                {
                    mmi_rmgr_send_process_database_req(DRMT_PROCESS_DATABASE_RESTORE, 0, path);
                }
                break;
            }
            case MENU_ID_RMGR_CERMGR:
                mmi_rmgr_select_file_result(DRM_import_certificate(path));
                break;
            default:
                ASSERT(0);
                break;
        }
        
    }
    else
    {
        GoBackHistory();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_fmgr
 * DESCRIPTION
 *  Entry function of certificate manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_entry_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_RMGR,
        (FMGR_SELECT_FOLDER),
        filter,
        (S8*) L"root",
        mmi_rmgr_select_file);
}

#endif /* __MMI_RMGR__ */ 

