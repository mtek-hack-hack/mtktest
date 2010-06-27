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
 * JavaAgencyTaskSwitch.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*************************************************************************
 * Include header files
 *************************************************************************/
#include "MMI_include.h"
#include <math.h>

/*************************************************************************
 * Include header files
 *************************************************************************/
#ifdef __J2ME__

/*************************************************************************
 * Plutommi include header files
 *************************************************************************/
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "ProfileGprots.h"

/*  Include: J2ME header file */
#include "jam_msg_handler.h"    /* just need to incude J2ME_SUPPORT_PAUSE option */
#include "j2me_trace.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "jvm_adaptor.h"
#include "j2me_custom_option.h"
#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */
#include "SimDetectionDef.h"

#ifdef J2ME_SUPPORT_PAUSE
/*************************************************************************
 * extern function and variable
 *************************************************************************/
extern kal_wchar *get_running_mid_name(void);
extern void j2me_get_wap_rsp(void *MsgStruct);
extern kal_bool g_mmi_java_get_wap_prof_ok;
static kal_wchar *asking_string_buffer = NULL;
static BOOL mmi_java_go_to_idle_after_terminated = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  format_asking_string
 * DESCRIPTION
 *  Add mid_name and "?" into string.
 * PARAMETERS
 *  string_id       [IN]        String ID
 * RETURNS
 *
 *****************************************************************************/
static PU8 format_asking_string(U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 string_len = mmi_ucs2strlen(GetString(string_id));
    kal_wchar *mid_name = get_running_mid_name();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mid_name == NULL)
    {
        mid_name = (kal_wchar*) GetString(STR_SCR_JAVA_CAPTION);
    }
    if (asking_string_buffer != NULL)
    {
        free_ctrl_buffer(asking_string_buffer);
    }
    asking_string_buffer = (kal_wchar*) get_ctrl_buffer((string_len + mmi_ucs2strlen((S8*) mid_name) + 2) << 1);
    mmi_ucs2cpy((S8*) asking_string_buffer, GetString(string_id));
    mmi_ucs2cpy((S8*) (asking_string_buffer + string_len), (S8*) mid_name);
    string_len += mmi_ucs2strlen((S8*) mid_name);
    asking_string_buffer[string_len] = '?';
    asking_string_buffer[string_len + 1] = 0;
    return (PU8) asking_string_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  free_asking_string
 * DESCRIPTION
 *  Free the memory of asking string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void free_asking_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (asking_string_buffer != NULL)
    {
        free_ctrl_buffer(asking_string_buffer);
    }
    asking_string_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_handler
 * DESCRIPTION
 *  Handle Function: revoked when selected item changed
 * PARAMETERS
 *  index       [IN]        Index of selected item
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_java_highlight_index;

static void mmi_java_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_highlight_index = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_terminate_dialog_exit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_entry_terminate_dialog_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_asking_string();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_terminate_dialog_yes_hdlr
 * DESCRIPTION
 *  Handler Function:   revoked when select "YES" in "TERMINATE" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_terminate_dialog_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_java_highlight_index == 0)  /* pause */
    {
        jvm_enter_pause_mode();
        DeleteScreenIfPresent(SCR_JAVA_APP_MIDS_OPTION);
        DeleteScreenIfPresent(SCR_JAVA_APP_OPTION_SELECT);
        DeleteScreenIfPresent(SCR_JAVA);
    }
    else    /* terminate */
    {

        jvm_pause_state_exit();
        mmi_java_entry_terminating(MMI_FALSE);
    }

    if(GetActiveScreenId() == SCR_JAVA_TERMINATE_DIALOG)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_JAVA_TERMINATE_DIALOG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_terminate_dialog_no_hdlr
 * DESCRIPTION
 *  Handler Function:   revoked when select "NO" in "TERMINATE" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_terminate_dialog_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_terminate_dialog
 * DESCRIPTION
 *  The entry function to ask user if they want to terminate/Pause Java
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_terminate_dialog(void)  /* called by JAVA adaptor, also in mmi task */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *icon_items[2];
    U8 *text_items[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_JAVA_TERMINATE_DIALOG,
        mmi_java_entry_terminate_dialog_exit,
        mmi_java_entry_terminate_dialog,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_TERMINATE_DIALOG);

    RegisterHighlightHandler(mmi_java_highlight_handler);

    memset(icon_items, 0, sizeof(icon_items));

    text_items[0] = (PU8) GetString(STR_JAVA_PAUSE);
    text_items[1] = (PU8) GetString(STR_JAVA_TERMINATE);

    ShowCategory32Screen(
        format_asking_string(STR_JAVA_TERMINATE_DIALOG_TITLE),
        NULL,
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        2,
        text_items,
        icon_items,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_java_terminate_dialog_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_terminate_dialog_no_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_resume_dialog_exit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_resume_dialog_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_asking_string();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_resume_dialog_yes_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "YES" in "RESUME" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_resume_dialog_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: hope we can update wap profile in java task , not in MMI task
    if (mmi_java_highlight_index == 0)  /* resume */
    {
        if (g_mmi_java_get_wap_prof_ok && !mmi_java_is_no_sim())
        {
            /* this is used to update the wap profile data for java */
            /* default */
            if(g_mmi_java_wap_prof_id == 0xFF)
            {
                MYQUEUE Message;

                SetProtocolEventHandler(j2me_get_wap_rsp, MSG_ID_WAP_GET_BRA_PROF_ID_RSP);
                Message.oslSrcId = MOD_MMI;
                Message.oslDestId = wap_get_service_module(MSG_ID_WAP_GET_BRA_PROF_ID_REQ);;
                Message.oslMsgId = MSG_ID_WAP_GET_BRA_PROF_ID_REQ;
                Message.oslDataPtr = NULL;
                Message.oslPeerBuffPtr = NULL;
                OslMsgSendExtQueue(&Message);
            }
            else
            {
                MYQUEUE Message;
                wap_get_prof_content_req_struct *get_prof;

                SetProtocolEventHandler(j2me_get_wap_rsp, MSG_ID_WAP_GET_PROF_CONTENT_RSP);
                get_prof = construct_local_para(sizeof(wap_get_prof_content_req_struct), TD_CTRL);
                get_prof->id = g_mmi_java_wap_prof_id;

                Message.oslSrcId = MOD_MMI;
                Message.oslDestId = wap_get_service_module(MSG_ID_WAP_GET_PROF_CONTENT_REQ);
                Message.oslMsgId = MSG_ID_WAP_GET_PROF_CONTENT_REQ;
                Message.oslDataPtr = (local_para_struct*) get_prof;
                Message.oslPeerBuffPtr = NULL;
                OslMsgSendExtQueue(&Message);
            }
            g_mmi_java_get_wap_prof_ok = KAL_FALSE;
        }
      /*********************************************************/
        jvm_resume_screen();
    }
    else    /* terminate */
    {
        jvm_pause_state_exit();
        mmi_java_entry_terminating(MMI_FALSE);
    }

    DeleteScreenIfPresent(SCR_JAVA_RESUME_DIALOG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_resume_dialog_no_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "NO" in "RESUME" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_resume_dialog_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_resume_dialog
 * DESCRIPTION
 *  The entry function to ask if user want to resume Java or terminate java.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_resume_dialog(void) /* called by MMI */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *icon_items[2];
    U8 *text_items[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_RESUME_DIALOG, mmi_java_entry_resume_dialog_exit, mmi_java_entry_resume_dialog, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_RESUME_DIALOG);
    RegisterHighlightHandler(mmi_java_highlight_handler);

    memset(icon_items, 0, sizeof(icon_items));
    text_items[0] = (PU8) GetString(STR_JAVA_RESUME);
    text_items[1] = (PU8) GetString(STR_JAVA_TERMINATE);

    ShowCategory32Screen(
        format_asking_string(STR_JAVA_RESUME_DIALOG_TITLE),
        NULL,
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        2,
        text_items,
        icon_items,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_java_resume_dialog_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_resume_dialog_no_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_force_terminate_dialog_yes_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "YES" in "FORCE TERMINATE" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_force_terminate_dialog_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_pause_state_exit();

    mmi_java_entry_terminating(MMI_FALSE);

    if(GetActiveScreenId() == SCR_JAVA_FORCE_TERMINATE_DIALOG)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_JAVA_FORCE_TERMINATE_DIALOG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_force_terminate_dialog_no_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "NO" in "FORCE TERMINATE" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_force_terminate_dialog_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_force_terminate_dialog
 * DESCRIPTION
 *  The entry function to ask if user real want to terminate java? (can not pause)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_force_terminate_dialog(void)    /* called by JAVA adaptor, also in mmi task */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_FORCE_TERMINATE_DIALOG, NULL, mmi_java_entry_force_terminate_dialog, NULL);

    ShowCategory74Screen(
        STR_JAVA_TERMINATE,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) GetString(STR_JAVA_FORCE_TERMINATE),
        mmi_ucs2strlen(GetString(STR_JAVA_FORCE_TERMINATE)),
        NULL);

    SetLeftSoftkeyFunction(mmi_java_force_terminate_dialog_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_force_terminate_dialog_no_hdlr, KEY_EVENT_UP);
}
#endif /* J2ME_SUPPORT_PAUSE */ /* #ifdef J2ME_SUPPORT_PAUSE */




/*****************************************************************************
 * FUNCTION
 *  jvm_terminating_time_out_hdlr
 * DESCRIPTION
 *  Check if VM is real terminated
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_terminating_time_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(TRACE_GROUP_1, MMI_JAVA_TERMINATEING_TIMEOUT, jvm_is_busy());
    ClearDelScrnIDCallbackHandler(SCR_JAVA_VM_TERMINATING, NULL);

    if(mmi_java_go_to_idle_after_terminated)
    {
        mmi_java_go_to_idle_after_terminated = MMI_FALSE;

        if (IsScreenPresent(SCR_SIM_INSERTION))
        {
            DeleteUptoScrID(SCR_SIM_INSERTION);
        }
        else if (IsScreenPresent(SCR_SIM_BLOCK))
        {
            DeleteUptoScrID(SCR_SIM_BLOCK);
        }
        else
        {
            DeleteUptoScrID(IDLE_SCREEN_ID);
        }
    }

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_processing_generic
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

U8 mmi_java_screen_delete_hdlr(void *in_param)
{
    if (!jvm_is_own_screen())
    {
        jvm_delete_screen_notify();

        if( jvm_is_pause_mode() || !jvm_is_busy())
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
    {
        ASSERT(0);
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_entry_terminating(void)
 * DESCRIPTION
 *  Entry terminating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_terminating_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    EntryNewScreen(SCR_JAVA_VM_TERMINATING, NULL, mmi_java_entry_terminating_internal, NULL);

    SetDelScrnIDCallbackHandler(SCR_JAVA_VM_TERMINATING,mmi_java_screen_delete_hdlr);

    ShowCategory8Screen(
        STR_JAVA_VM_TERMINATING,
        mmi_java_get_title_icon(),
        0,
        0,
        0,
        0,
        STR_JAVA_WAIT,
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

}

/*****************************************************************************
 * FUNCTION
 *  jvm_entry_terminating(void)
 * DESCRIPTION
 *  Entry terminating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_terminating(BOOL idle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

        mmi_java_go_to_idle_after_terminated = idle;
        mmi_java_entry_terminating_internal();
}


static U16* cb_terminate_string = NULL;
static mmi_java_terminate_hdlr cb_terminate_hdlr = NULL;
/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_java_terminate_cb(BOOL is_terminate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cb_terminate_hdlr)
    {

        (*cb_terminate_hdlr)(is_terminate);
        cb_terminate_hdlr = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_force_terminate_dialog_yes_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "YES" in "FORCE TERMINATE" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_cb_terminate_dialog_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_terminate_cb(MMI_TRUE);

    if(GetActiveScreenId() == SCR_JAVA_TERMINATE_DIALOG2)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_JAVA_TERMINATE_DIALOG2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_force_terminate_dialog_no_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "NO" in "FORCE TERMINATE" dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_cb_terminate_dialog_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_terminate_cb(MMI_FALSE);
    if( GetActiveScreenId() == SCR_JAVA_TERMINATE_DIALOG2)
    {
        GoBackHistory();
    }
    else
    {
       DeleteScreenIfPresent(SCR_JAVA_TERMINATE_DIALOG2);
    }
}



/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_entry_cb_terminate_dialog_internal(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_TERMINATE_DIALOG2, NULL, mmi_java_entry_cb_terminate_dialog_internal, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_TERMINATE_DIALOG2);

    ShowCategory74Screen(
        STR_SCR_JAVA_CAPTION,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) cb_terminate_string,
        mmi_ucs2strlen((PS8) cb_terminate_string),
        NULL);

    SetLeftSoftkeyFunction(mmi_java_cb_terminate_dialog_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_cb_terminate_dialog_no_hdlr, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

void mmi_java_entry_cb_terminate_dialog(mmi_java_terminate_hdlr fp, U16* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cb_terminate_hdlr = fp;

    cb_terminate_string = str;

    mmi_java_entry_cb_terminate_dialog_internal();
}

#endif /* __J2ME__ */ /* #ifdef __J2ME__ */

