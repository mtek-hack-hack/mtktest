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

#include "SimDetectionGprot.h"
#include "simdetectiongexdcl.h"
#include "CallmanagementGprot.h"
#include "ProfileGprots.h"      /* need MYQUEUE */
#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */
#include "WrapperGprot.h"
#include "phonebookdef.h"
#include "Wgui_touch_screen.h"

#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "jam_msg_handler.h"

#include "jal.h"
#include "jvm_adaptor.h"

#include "AlarmFrameworkProt.h" /* AlmIsTonePlaying()*/

#include "drm_def.h"
#include "drm_gprot.h"

#ifdef __MMI_MY_FAVORITE__
#include "MyFavoriteResDef.h"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_in_voice_call
 * DESCRIPTION
 *  this function use to detect taht current have voice call or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
BOOL mmi_java_is_in_voice_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( AlmIsTonePlaying())
    {
        return MMI_TRUE;
    }

    if ( isInCall() == MMI_TRUE )
    {
        /*
            wap call connecting  => true
            wap call connected => false
            other call connecting/connected => true
        */
        if( GetWapCallPresent() )
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
        if (GetActiveScreenId()==GetCmMarkerScrnID() ||
            IsScreenPresent(GetCmMarkerScrnID()))
        {
            /* special case here, sometimes CM change state too early
                but still have call marker in the history */
            return MMI_TRUE;
        }

        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_in_idle_screen
 * DESCRIPTION
 *  This function is used to detect "current screen" is idle screen or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
BOOL mmi_java_is_in_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_shutdown_is_in_power_off_period() == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    if (IsScreenPresent(SCR_SIM_INSERTION)  /* is sim insertion IN history ? */
        || IsScreenPresent(IDLE_SCREEN_ID)  /* is idle screen IN history ? */
        || IsScreenPresent(SCR_SIM_BLOCK))  /* is sim block IN history ? */
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_no_network_service
 * DESCRIPTION
 *  This function is to detect if network is available or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_java_is_no_network_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_network_service_available() == MMI_TRUE)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_no_sim
 * DESCRIPTION
 *  This function is to detect if there is a sim in phone or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_java_is_no_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_sim_valid() == MMI_TRUE)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_widget_not_ready
 * DESCRIPTION
 *  The exit function of some popup window. We should stop timer here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_widget_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(J2ME_NOT_READY_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_is_busy
 * DESCRIPTION
 *  To show java is busy now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_J2ME_SCREEN_NOT_READY, mmi_java_widget_not_ready, NULL, NULL);
    StartTimer(J2ME_NOT_READY_TIMER, 2000, GoBackHistory);
    ShowCategory66Screen(
        STR_JAVA_VM_BUSY,
        mmi_java_get_title_icon(),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) GetString(STR_JAVA_WAIT),
        IMG_PROCESSING_PHONEBOOK,
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_push_busy_ok_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when press "OK" in "PUSH BUSY" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_push_busy_ok_hdlr(void)
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
 *  mmi_java_display_push_busy
 * DESCRIPTION
 *  Display VM is busy for timealarm push
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_push_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_PUSH_BUSY, NULL, mmi_java_display_push_busy, NULL);

    ShowCategory74Screen(
        STR_JAVA_VM_BUSY,
        mmi_java_get_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        (U16) 0,
        (U16) 0,
        (PU8) GetString(STR_JAVA_PUSH_BUSY),
        mmi_ucs2strlen(GetString(STR_JAVA_PUSH_BUSY)),
        NULL);

    SetLeftSoftkeyFunction(mmi_java_display_push_busy_ok_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_is_busy_for_pause_mode
 * DESCRIPTION
 *  Display Java is busy for pause state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_is_busy_for_pause_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_JAVA_BUSY_FOR_PAUSE_MODE), 0, 1, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_check_and_display_is_busy
 * DESCRIPTION
 *  Check if jvm is busy , and display popup to announce user
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
BOOL mmi_java_check_and_display_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jvm_is_busy())
    {
        mmi_java_display_is_busy();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_show_alert_user_req
 * DESCRIPTION
 *  Handler Function: revoked when receive the request to alert user some warning
 * PARAMETERS
 *  MsgStruct       [IN]        Send from Java task
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_show_alert_user_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_show_alert_user_dialog_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_show_alert_user_dialog_req_struct*) MsgStruct;

    DisplayPopup((PU8) msg->message, IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
}

/*****************************
 *  User permission dialog
 ************************************/
static mmi_java_get_permission_ind_struct mmi_java_get_permission_msg;
static S32 *mmi_java_get_permission_index;


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_permission_lsk_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when press "YES" in "PERMISSION" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_get_permission_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*mmi_java_get_permission_index) = MMI_TRUE;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_permission_rsk_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when press "NO" in "PERMISSION" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_get_permission_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    (*mmi_java_get_permission_index) = MMI_FALSE;
    GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_get_permission
 * DESCRIPTION
 *  The entry function to get user's permission to use Network or some
 *  resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_java_permission_strid(kal_uint8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(index)
    {
        case JAVA_PERMISSION_SOCKET:             return STR_JAVA_PERMISSION_SOCKET;
        case JAVA_PERMISSION_HTTP:               return STR_JAVA_PERMISSION_HTTP;
        case JAVA_PERMISSION_HTTPS:              return STR_JAVA_PERMISSION_HTTPS;
        case JAVA_PERMISSION_SSL:                return STR_JAVA_PERMISSION_SSL;
        case JAVA_PERMISSION_DATAGRAM:           return STR_JAVA_PERMISSION_DATAGRAM;
        case JAVA_PERMISSION_SVR_SOCKET:         return STR_JAVA_PERMISSION_SVR_SOCKET;
        case JAVA_PERMISSION_SVR_DATAGRAM:       return STR_JAVA_PERMISSION_SVR_DATAGRAM;
        case JAVA_PERMISSION_COMM:               return STR_JAVA_PERMISSION_COMM;
        case JAVA_PERMISSION_PUSH:               return STR_JAVA_PERMISSION_PUSH;
        case JAVA_PERMISSION_SMS:                return STR_JAVA_PERMISSION_SMS;
        case JAVA_PERMISSION_CBS:                return STR_JAVA_PERMISSION_CBS;
        case JAVA_PERMISSION_MMS:                return STR_JAVA_PERMISSION_MMS;
        case JAVA_PERMISSION_RECORD_CTRL:        return STR_JAVA_PERMISSION_RECORD_CTRL;
        case JAVA_PERMISSION_SNAPSHOT:           return STR_JAVA_PERMISSION_SNAPSHOT;
        case JAVA_PERMISSION_FILE_READ:          return STR_JAVA_PERMISSION_FILE_READ;
        case JAVA_PERMISSION_FILE_WRITE:         return STR_JAVA_PERMISSION_FILE_WRITE;
        case JAVA_PERMISSION_CONTACT_LIST_READ:  return STR_JAVA_PERMISSION_CONTACT_LIST_READ;
        case JAVA_PERMISSION_CONTACT_LIST_WRITE: return STR_JAVA_PERMISSION_CONTACT_LIST_WRITE;
        case JAVA_PERMISSION_EVENT_LIST_READ:    return STR_JAVA_PERMISSION_EVENT_LIST_READ;
        case JAVA_PERMISSION_EVENT_LIST_WRITE:   return STR_JAVA_PERMISSION_EVENT_LIST_WRITE;
        case JAVA_PERMISSION_TODO_LIST_READ:     return STR_JAVA_PERMISSION_TODO_LIST_READ;
        case JAVA_PERMISSION_TODO_LIST_WRITE:    return STR_JAVA_PERMISSION_TODO_LIST_WRITE;
        case JAVA_PERMISSION_OBEX_CLIENT:        return STR_JAVA_PERMISSION_OBEX_CLIENT;
        case JAVA_PERMISSION_OBEX_SERVER:        return STR_JAVA_PERMISSION_OBEX_SERVER;
        case JAVA_PERMISSION_OBEX_CLIENT_TCP:    return STR_JAVA_PERMISSION_OBEX_CLIENT_TCP;
        case JAVA_PERMISSION_OBEX_SERVER_TCP:    return STR_JAVA_PERMISSION_OBEX_SERVER_TCP;
        case JAVA_PERMISSION_BT_CLIENT:          return STR_JAVA_PERMISSION_BT_CLIENT;
        case JAVA_PERMISSION_BT_SERVER:          return STR_JAVA_PERMISSION_BT_SERVER;
        case JAVA_PERMISSION_TELEPHONE:          return STR_JAVA_PERMISSION_TELEPHONE;
        case JAVA_PERMISSION_EXCLUSIVE_PUSH:     return STR_JAVA_PERMISSION_EXCLUSIVE_PUSH;
        case JAVA_PERMISSION_EXCLUSIVE_NET:      return STR_JAVA_PERMISSION_EXCLUSIVE_NET;
        case JAVA_PERMISSION_UNKNOWN:            return STR_JAVA_PERMISSION_UNKNOWN;
        default:
            return STR_JAVA_PERMISSION_UNKNOWN;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_get_permission
 * DESCRIPTION
 *  The entry function to get user's permission to use Network or some
 *  resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_get_permission(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U16 strid = mmi_java_permission_strid(mmi_java_get_permission_msg.title_id);
    S8 *buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_GET_PERMISSION, NULL, mmi_java_entry_get_permission, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_GET_PERMISSION);

    mmi_java_get_permission_index = mmi_java_get_permission_msg.chosen_id;

    buffer = (S8*)subMenuData;
    kal_mem_set(buffer, 0, MAX_SUB_MENUS * MAX_SUB_MENU_SIZE);

    mmi_ucs2cpy((S8*)buffer, (S8*)GetString(strid));

    if(mmi_java_get_permission_msg.appendix)
    {
        mmi_ucs2cat((S8*)buffer, (S8*)mmi_java_get_permission_msg.appendix);
    }

    ShowCategory74Screen(
        STR_JAVA_PERMISSION_TITLE,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) buffer,
        mmi_ucs2strlen((PS8) buffer),
        NULL);

    SetLeftSoftkeyFunction(mmi_java_get_permission_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_get_permission_rsk_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_permission_ind
 * DESCRIPTION
 *  Handler Function: revoked when receive the message "MSG_ID_MMI_JAVA_GET_PERMISSION_IND"
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_get_permission_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&mmi_java_get_permission_msg, MsgStruct, sizeof(mmi_java_get_permission_ind_struct));

    ASSERT(mmi_java_get_permission_msg.chosen_id != NULL);

    mmi_java_entry_get_permission();
}

////////////////////////////////
//  GET GENERAL CONFIRM
/////////////////////////////////

static mmi_java_get_confirm_ind_struct mmi_java_mids_get_confirm_ind_msg;


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_get_confirm_res
 * DESCRIPTION
 *  Send the message MMI_JAVA_SEND_GET_CONFIRM_RES to java
 * PARAMETERS
 *  confirm     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_get_confirm_res(BOOL confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_install_confirm_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_GET_CONFIRM_RES, confirm);

    msg = (mmi_java_install_confirm_res_struct*) OslConstructDataPtr(sizeof(mmi_java_install_confirm_res_struct));
    msg->session_id = mmi_java_mids_get_confirm_ind_msg.session_id;
    msg->confirm = confirm;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_GET_CONFIRM_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_get_confirm_yes_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when select "Yes" in "CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_get_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    GoBackHistory();
    mmi_java_send_mids_install_confirm_res(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_get_confirm_no_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when select "No" in "CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_get_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    GoBackHistory();
    mmi_java_send_mids_get_confirm_res(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_get_confirm_cancel_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when select "End key" in "CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_get_confirm_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_java_send_mids_get_confirm_res(MMI_FALSE);
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_get_confirm
 * DESCRIPTION
 *  The entry function to get any confirm from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_mids_get_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *str;
    U16 title;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str = mmi_java_mids_get_confirm_ind_msg.confirm_msg;
    title = mmi_java_mids_get_confirm_ind_msg.confirm_title;

    EntryNewScreen(SCR_JAVA_GET_CONFIRM, NULL, mmi_java_entry_mids_get_confirm, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_GET_CONFIRM);

    if (mmi_java_mids_get_confirm_ind_msg.window_category == JAVA_CONFIRM_NOTIFICATION_CATEGORY)
    {
        U16 image = mmi_java_mids_get_confirm_ind_msg.confirm_image;

        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type) str,
            image,
            guiBuffer);
    }
    else if (mmi_java_mids_get_confirm_ind_msg.window_category == JAVA_CONFIRM_TEXT_VIEW_CATEGORY)
    {

        ShowCategory74Screen(
            (U16) title,
            mmi_java_get_title_icon(),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8*) str,
            mmi_ucs2strlen((PS8) str),
            NULL);
    }
    else
    {
        ASSERT(0);
    }

    SetKeyHandler(mmi_java_mids_get_confirm_cancel_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_java_mids_get_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_mids_get_confirm_no_hdlr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_confirm_ind
 * DESCRIPTION
 *  Handler Function: revoked when receive the message "MMI_JAVA_RECV_GET_CONFIRM_IND"
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_get_confirm_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_GET_CONFIRM_IND);

    memcpy(
        &mmi_java_mids_get_confirm_ind_msg,
        (mmi_java_get_confirm_ind_struct*) MsgStruct,
        sizeof(mmi_java_get_confirm_ind_struct));

    mmi_java_entry_mids_get_confirm();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_ilm
 * DESCRIPTION
 *  send message
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/

void mmi_java_send_message(S32 src_id, S32 dst_id, S32 sap_id, S32 msg_id, void *local_para_ptr, void *peer_buff_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = src_id;
    Message.oslDestId = dst_id;
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (local_para_struct *) local_para_ptr;
    Message.oslPeerBuffPtr = (peer_buff_struct *) peer_buff_ptr;
    Message.oslSapId = sap_id;

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
void mmi_java_send_get_imsi_res(U8* imsi, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_java_get_imsi_res_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_imsi_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_imsi_res_struct));
    msg->error = error;

    memset(msg->imsi, 0, sizeof(msg->imsi));

    if( imsi)
    {
        for( i = 0 ;i < 17; i++)
        {
            msg->imsi[i] = imsi[i];
        }
    }

    mmi_java_send_message(MOD_MMI, MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_GET_IMSI_RES, msg, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_imsi_rsp
 * DESCRIPTION
 *  get the sim card IMSI
 * PARAMETERS
 *  MsgStruct   [In]    Message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_l4_get_imsi_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_imsi_rsp_struct* msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_smu_get_imsi_rsp_struct*)MsgStruct;

    if (msg->result == ST_SUCCESS)
    {
        mmi_java_send_get_imsi_res(msg->imsi, J2ME_NO_ERROR);
    }
    else
    {
        mmi_java_send_get_imsi_res(NULL, J2ME_UNDEFINED_ERROR);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_get_imsi_req
 * DESCRIPTION
 *  Send the message PRT_GET_IMSI_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_l4_get_imsi_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_java_recv_l4_get_imsi_rsp, PRT_GET_IMSI_RSP);
    mmi_java_send_message(MOD_MMI, MOD_L4C, MMI_L4C_SAP, PRT_GET_IMSI_REQ, NULL, NULL);
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
void mmi_java_recv_get_imsi_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_java_send_l4_get_imsi_req();
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

kal_bool mmi_java_is_drm_file(kal_wchar* filename)
{

#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( filename == NULL ) return KAL_FALSE;

    if (DRM_get_object_method(0, filename) != DRM_METHOD_NONE)
    {
        return KAL_TRUE;
    }
#endif
    return KAL_FALSE;
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
U16 mmi_java_get_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MY_FAVORITE__
    return IMG_ID_MY_FAVORITE_TITLE_JAVABOX;
#else
    return GetRootTitleIcon(MAIN_MENU_FUNANDGAMES_MENUID);
#endif
}

#endif /* __J2ME__ */ /* ifdef J2ME */

