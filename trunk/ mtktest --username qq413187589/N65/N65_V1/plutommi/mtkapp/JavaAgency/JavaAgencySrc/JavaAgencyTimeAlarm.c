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
 * JavaSrc.c
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
 * -------
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
#ifdef __J2ME__

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "ProfileGprots.h"      /* need MYQUEUE */
#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */
#include "WrapperGprot.h"
#include "gpioInc.h"            /* GPIO_BACKLIGHT_SHORT_TIME */

#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "jam_msg_handler.h"
#include "jal.h"
#include "jvm_adaptor.h"
#include "jpush_interface.h"


extern java_context_struct g_java;

/*****************************************************************************
** 5. JAVA_TIMEALARM_PUSH
**    mmi_java_recv_timealarm_push_ind
**    mmi_java_recv_timealarm_push_get_setting_cnf
**    mmi_java_send_timealarm_push_res
**    mmi_java_entry_timealarm_push_res
**    mmi_java_exit_timealarm_push_res
**    mmi_java_send_timealarm_push_res_yes
**    mmi_java_send_timealarm_push_res_no
**    mmi_java_entry_timealarm_push_launch
**    mmi_java_exit_timealarm_push_launch
*****************************************************************************/
mmi_java_timealarm_push_ind_struct timealarm_push_ind_msg[MAX_PUSH_REGISTRY];
kal_bool timealarm_push_ind_msg_used[MAX_PUSH_REGISTRY] = 
{
    KAL_FALSE, KAL_FALSE, KAL_FALSE,
    KAL_FALSE, KAL_FALSE, KAL_FALSE
};
static kal_bool timealarm_push_processing = KAL_FALSE;
static kal_uint32 timealarm_push_processing_index;


/*****************************************************************************
 * FUNCTION
 *  fetch_time_alarm_event_id
 * DESCRIPTION
 *  Look for a timealarm
 * PARAMETERS
 *  void
 * RETURNS
 *  0~ MAX_PUSH_REGISTRY-1 : have one more timealarm
 *  -1 : means no timealarm
 *****************************************************************************/
static int fetch_time_alarm_event_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PUSH_REGISTRY; i++)
        if (timealarm_push_ind_msg_used[i])
        {
            return i;
        }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  new_time_alarm_event_id
 * DESCRIPTION
 *  Get a position to save a new timealarm
 * PARAMETERS
 *  void
 * RETURNS
 *  0~ MAX_PUSH_REGISTRY-1 : have position
 *  -1 : means no position
 *****************************************************************************/
static int new_time_alarm_event_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PUSH_REGISTRY; i++)
        if (!timealarm_push_ind_msg_used[i])
        {
            timealarm_push_ind_msg_used[i] = KAL_TRUE;
            return i;
        }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  delete_time_alarm_event_id
 * DESCRIPTION
 *  Delete the timealarm
 * PARAMETERS
 *  id      [IN]        The id of timealarm which should be deleted.
 * RETURNS
 *  void
 *****************************************************************************/
static void delete_time_alarm_event_id(int id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(timealarm_push_ind_msg_used[id]);

    timealarm_push_ind_msg_used[id] = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_cant_timealarm_for_pause_mode
 * DESCRIPTION
 *  Display that we can not launch MIDlet because java is in pause mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_cant_timealarm_for_pause_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_JAVA_STOP_TIMEALARM_FOR_PAUSE_MODE),
        0,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_timealarm_push_ind
 * DESCRIPTION
 *  Handler Function: revoked when receive MMI_JAVA_RECV_TIMEALARM_PUSH_IND
 *  The message means java want to launch a MIDlet for timealarm
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool timer_set = KAL_FALSE;
void mmi_java_recv_timealarm_push_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int session_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    session_id = new_time_alarm_event_id();

    /* ASSERT(0<= session_id);// too many time alarm, maybe memory leak ? or java task allow more timealarm ? */
    if (session_id < 0)
    {
        return; /* drop this timealarm event, because there are too many event need to process */
    }

    /* timealarm_push_ind_msg=(mmi_java_timealarm_push_ind_struct*)MsgStruct; */
    kal_mem_cpy(
        &timealarm_push_ind_msg[session_id],
        (mmi_java_timealarm_push_ind_struct*) MsgStruct,
        sizeof(mmi_java_timealarm_push_ind_struct));

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_IND);
    if (!timer_set)
    {
        mmi_java_launch_time_alarm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_time_alarm
 * DESCRIPTION
 *  Start to launch the MIDlet for time alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_time_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int session_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((session_id = fetch_time_alarm_event_id()) < 0)
    {
        timer_set = KAL_FALSE;
        return; /* no time alarm event should launch.. */
    }

    if (mmi_java_is_in_idle_screen() && !timealarm_push_processing)
    {
        ASSERT(0 <= session_id);
        if (jvm_is_pause_mode())
        {
            mmi_java_display_cant_timealarm_for_pause_mode();
            /* delete_time_alarm_event_id(session_id); */
            StartTimer(J2ME_TIMEALARM_TIMER, 10 * 1000, (FuncPtr) mmi_java_launch_time_alarm);        /* waiting 10 seconds, and try again... */
            return; /* drop the timealarm request */
        }
        timealarm_push_processing = KAL_TRUE;
        timealarm_push_processing_index = session_id;
        SetProtocolEventHandler(
            (PsFuncPtr) mmi_java_recv_timealarm_push_get_setting_cnf,
            MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF);
        mmi_java_send_mids_get_setting_req(
            0,
            jam_call_back_functions. jam_get_mids_id_from_push_name(timealarm_push_ind_msg[session_id]. mids_storage_name));
    }
    else
    {
        StartTimer(J2ME_TIMEALARM_TIMER, 10 * 1000, (FuncPtr) mmi_java_launch_time_alarm);    /* waiting 10 seconds, and try again... */
        timer_set = KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_timealarm_push_get_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_J2ME to decide
 *  the response data for PushAlarmPermissionCnf
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_timealarm_push_get_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_TIMEALARM_PUSH_GET_SETTING_CNF);

    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;

    if (msg->error_code == J2ME_NO_ERROR)
    {
        g_java.mids_trusted = (U8) msg->mids_trusted;

        kal_mem_cpy(&(g_java.mids_setting), &(msg->mids_setting), sizeof(mmi_setting_struct));
    }
    else
    {
        ASSERT(0);  /* add by hjf , to detect the get setting fail case . */
    }

    if (g_java.mids_setting.permission_push == PERMISSION_NEVER ||
        g_java.mids_setting.permission_push == PERMISSION_DENY ||
        g_java.mids_setting.permission_push == PERMISSION_USER_DENIED)
    {
        mmi_java_send_timealarm_push_res(
            timealarm_push_processing_index,
            g_java.mids_setting.permission_push,
            KAL_FALSE);
    }
    else if (g_java.mids_setting.permission_push == PERMISSION_SESSION ||
             g_java.mids_setting.permission_push == PERMISSION_ONE_SHOT ||
             g_java.mids_setting.permission_push == PERMISSION_BLANKET ||
             g_java.mids_setting.permission_push == PERMISSION_DENY_SESSION)
    {
        mmi_java_entry_timealarm_push_confirm();
    }
    else if (g_java.mids_setting.permission_push == PERMISSION_ALLOW ||
             g_java.mids_setting.permission_push == PERMISSION_BLANKET_GRANTED)
    {
        mmi_java_send_timealarm_push_res(
            timealarm_push_processing_index,
            g_java.mids_setting.permission_push,
            KAL_TRUE);
    }
    else
    {
        /* ASSERT(0); */
        mmi_java_send_timealarm_push_res(
            timealarm_push_processing_index,
            g_java.mids_setting.permission_push,
            KAL_FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_timealarm_push_res
 * DESCRIPTION
 *  This routines send MSG_ID_JAVA_MMI_TIMEALARM_PUSH_RES to MOD_J2ME
 *  to send confirm mids permission and execution status
 * PARAMETERS
 *  session_id      [IN]        
 *  permission      [IN]        
 *  execute         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_timealarm_push_res(kal_uint32 session_id, S8 permission, U8 execute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_timealarm_push_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_TIMEALARM_PUSH_RES);

    /* if(!j2me_is_in_idle_screen())
       {
       timealarm_push_processing = KAL_FALSE;
       mmi_java_launch_time_alarm();
       return;
       } */

    mmi_java_load_setting();

    if (execute)
    {
        jvm_enter_screen();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_JAVA_ERROR_CODE_VERIFY_FAILED),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
    }

    msg = (mmi_java_timealarm_push_res_struct*) OslConstructDataPtr(sizeof(mmi_java_timealarm_push_res_struct));

    msg->callback_entry = timealarm_push_ind_msg[session_id].callback_entry;
    msg->execute = execute;
    msg->mid_class_name = timealarm_push_ind_msg[session_id].mid_class_name;
    msg->mids_storage_name = timealarm_push_ind_msg[session_id].mids_storage_name;
    msg->mids_permission = permission;
    msg->pushalarm_type = timealarm_push_ind_msg[session_id].pushalarm_type;
    msg->game_type = timealarm_push_ind_msg[session_id].game_type;
    msg->session_id = timealarm_push_ind_msg[session_id].session_id;
    msg->wap_prof_id = g_mmi_java_wap_prof_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_JAVA_MMI_TIMEALARM_PUSH_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    delete_time_alarm_event_id(session_id);
    timealarm_push_processing = KAL_FALSE;
    StartTimer(J2ME_TIMEALARM_TIMER, 2 * 1000, (FuncPtr) mmi_java_launch_time_alarm);
    /* mmi_java_launch_time_alarm(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_timealarm_push_confirm
 * DESCRIPTION
 *  TimeAlarm Push Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_timealarm_push_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_java_is_in_idle_screen() && !IsScreenPresent(SCR_JAVA_TIMEALARM_PUSH_CONFIRM))
    {
        timealarm_push_processing = KAL_FALSE;
        mmi_java_launch_time_alarm();
        return;
    }


    EntryNewScreen(SCR_JAVA_TIMEALARM_PUSH_CONFIRM, NULL, mmi_java_entry_timealarm_push_confirm, NULL);

    /* playRequestedTone(WARNING_TONE); */

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_TIMEALARM_PUSH_CONFIRM);

    //      mmi_asc_to_ucs2 ((PS8)gJavaPrintableStr,
    //      "Do you want to launch pushed MIDlet?");

    str = (U8*) get_string(STR_JAVA_PUSH_LAUNCH_ASK);
    ShowCategory74Screen(
        STR_JAVA_LAUNCH_ASK,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) str,
        mmi_ucs2strlen((PS8) str),
        NULL);

    SetKeyHandler(mmi_java_timealarm_push_confirm_no_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_java_timealarm_push_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_timealarm_push_confirm_no_hdlr, KEY_EVENT_UP);
    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_push_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "YES"  in "TIMEALARM PUSH" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_timealarm_push_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    GoBackHistory();    /* KEY PRESSED */
    mmi_java_send_timealarm_push_res(timealarm_push_processing_index, g_java.mids_setting.permission_push, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_timealarm_push_confirm_no_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "NO"  in "TIMEALARM PUSH" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_timealarm_push_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    GoBackHistory();    /* KEY PRESSED */
    mmi_java_send_timealarm_push_res(timealarm_push_processing_index, g_java.mids_setting.permission_push, KAL_FALSE);
}

#endif /* __J2ME__ */ 

