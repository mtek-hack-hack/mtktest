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
 * BTMMIHIDD.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for HIDD application.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_BT_MTK_SUPPORT__
#ifdef __MMI_HIDD_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "IdleAppProt.h"
#include "gpioInc.h"
#include "Conversions.h"
#include "ProfileGprots.h"      /* PlayRequestTone */
/* MMI Nvram access */

/* Trace Header Files */
 
/* External Device Header Files */
#include "ExtDeviceDefs.h"
#include "BTMMICm.h"

/* HIDD */
#include "bt_dm_struct.h"
#include "bt_hidd_struct.h"
#include "BTMMIHidd.h"
#include "BTMMIHiddGprots.h"
#include "BTMMIHIDScrGprots.h"
#include "BTMMIHidScr.h"

/* BT CM callback */
#include "BTMMICMGprots.h"
#include "BTMMICustDef.h"
#include "BTMMIScrGprots.h"  /*mmi_bt_get_device_name*/
#include "BTMMIScr.h"

/* Trace Header Files */
extern pBOOL isIncomingCall(void);
/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_bth_hidd_cntx_struct g_mmi_bth_hidd_cntx;

/***************************************************************************** 
* Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_bth_hidd_cntx, 0, sizeof(mmi_bth_hidd_cntx_struct));
    mmi_bth_get_last_hid_dev(&(g_mmi_bth_hidd_cntx.last_connected_bd_addr));
    mmi_bth_init_hidd_event_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_init_hidd_event_handler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_init_hidd_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_INIT_EVENT_HDLR);

    /* Init protocol event handler */
    SetProtocolEventHandler(mmi_bth_hidd_activate_cnf_hdler, MSG_ID_BT_HIDD_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_hidd_deactivate_cnf_hdler, MSG_ID_BT_HIDD_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_hidd_connect_cnf_hdler, MSG_ID_BT_HIDD_CONNECT_CNF);
    SetProtocolEventHandler(mmi_bth_hidd_connect_ind_hdler, MSG_ID_BT_HIDD_CONNECT_IND);
    SetProtocolEventHandler(mmi_bth_hidd_disconnect_cnf_hdler, MSG_ID_BT_HIDD_DISCONNECT_CNF);
    SetProtocolEventHandler(mmi_bth_hidd_disconnect_ind_hdler, MSG_ID_BT_HIDD_DISCONNECT_IND);

    SetProtocolEventHandler(mmi_bth_hidd_connection_authorize_ind_hdler, MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_IND);
    SetProtocolEventHandler(mmi_bth_hidd_interrupt_data_cnf_hdler, MSG_ID_BT_HIDD_INTERRUPT_DATA_CNF);



}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_activate_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_activate_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_IDLE:
        {
            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_ACTIVATE_REQ, NULL, NULL);
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATING);
        }
            break;
        case MMI_BTH_HIDD_STAT_ACTIVATED:
        {
            mmi_bth_activate_cnf_hdler((U32) MMI_BTH_HID_PROFILE_UUID);
        }
            break;
        default:
            MMI_BT_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_activate_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_activate_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_activate_cnf_struct *msg_p = (bt_hidd_activate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == hidd_result_ok)
    {
        MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
        mmi_bth_activate_cnf_hdler((U32) MMI_BTH_HID_PROFILE_UUID);
    }
    else
    {
        switch (g_mmi_bth_hidd_cntx.state)
        {
            case MMI_BTH_HIDD_STAT_ACTIVATING:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_IDLE);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_deactivate_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_deactivate_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_ACTIVATED:
        {
            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DEACTIVATING);
        }
            break;
        case MMI_BTH_HIDD_STAT_CONNECTED:
        {
            mmi_bth_hidd_disconnect_all();
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DEACTIVATING);
        }
            break;
        default:
            MMI_BT_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_deactivate_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_deactivate_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_deactivate_cnf_struct *msg_p = (bt_hidd_deactivate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == hidd_result_ok)
    {
        MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_IDLE);
        mmi_bth_deactivate_cnf_hdler((U32) MMI_BTH_HID_PROFILE_UUID);
    }
    else
    {
        switch (g_mmi_bth_hidd_cntx.state)
        {
            case MMI_BTH_HIDD_STAT_DEACTIVATING:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_connect_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  device_addr     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_connect_req_hdler(mmi_bth_bt_addr device_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_ACTIVATED:
        {
            bt_hidd_connect_req_struct *msg_p;

            msg_p = (bt_hidd_connect_req_struct*) construct_local_para(sizeof(bt_hidd_connect_req_struct), TD_CTRL);
            msg_p->bt_addr.lap = device_addr.lap;
            msg_p->bt_addr.uap = device_addr.uap;
            msg_p->bt_addr.nap = device_addr.nap;

            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_CONNECT_REQ, (void*)msg_p, NULL);
            /* SetProtocolEventHandler(mmi_bth_hidd_connect_cnf_hdler, MSG_ID_BT_HIDD_CONNECT_CNF); */
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNECTING);
        }
            break;
        case MMI_BTH_HIDD_STAT_CONNECTED:
        {
            mmi_bth_connect_cnf_hdler(
                MMI_FALSE,
                device_addr.lap,
                device_addr.uap,
                device_addr.nap,
                NULL,
                MMI_BTH_HID_PROFILE_UUID,
                0xFFFFFFFF);

        }
            break;
        default:
            MMI_BT_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_connect_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *str_prof, *str_conn_res;
    U8 str_output[80];
    U32 conn_index;
    bt_hidd_connect_cnf_struct *msg_p = (bt_hidd_connect_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_CONNECTING:
            break;
        case MMI_BTH_HIDD_STAT_IDLE:
            /* ignore this case, receiving connect cnf at idle state */
            /* for BT abnormal reset case, hidd module may receive the connect cnf at idle state */
            return;
        default:
            return;

    }

    mmi_bth_connect_cnf_hdler(
        !(msg_p->result),
        msg_p->bt_addr.lap,
        msg_p->bt_addr.uap,
        msg_p->bt_addr.nap,
        NULL,
        MMI_BTH_HID_PROFILE_UUID,
        msg_p->connection_id);


    if (msg_p->result == hidd_result_ok)
    {

        MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNECTED);
        /* get index of activate conn list */
        for (conn_index = 0; conn_index < g_mmi_bth_hidd_cntx.active_conn_num; conn_index++)
        {
            if (g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
                && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
                && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
                && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
            {
                break;
            }
        }
        g_mmi_bth_hidd_cntx.active_conn_list[conn_index].active = MMI_TRUE;
        g_mmi_bth_hidd_cntx.active_conn_list[conn_index].conn_id = msg_p->connection_id;
        /* update BT address */
        g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.lap = msg_p->bt_addr.lap;
        g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.uap = msg_p->bt_addr.uap;
        g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.nap = msg_p->bt_addr.nap;
		 /* update to last device */
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap = msg_p->bt_addr.lap;
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap = msg_p->bt_addr.uap;
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap = msg_p->bt_addr.nap;

        if (conn_index == g_mmi_bth_hidd_cntx.active_conn_num)
        {
            g_mmi_bth_hidd_cntx.active_conn_num++;
            MMI_BT_ASSERT(g_mmi_bth_hidd_cntx.active_conn_num <= MMI_BTH_HIDD_MAX_CONNECTION);
        }

        mmi_bt_entry_hid_app_select();
	DeleteScreenIfPresent(SCR_BT_CONNECTING);
    }
    else
    {
        if (msg_p->result == hidd_result_sco_reject)
        {
            /* sco link support for MT6601 */
            mmi_bt_popup_operation_not_allowed();
            DeleteScreenIfPresent(SCR_BT_CONNECTING);
    }
    else
    {
            str_prof = (U8*) GetString(STR_BT_CONNECT);
            str_conn_res = (U8*) GetString(STR_BT_FAILED);
            memset(str_output, 0, sizeof(U8) * 80);
            mmi_ucs2cpy((S8*) str_output, (const S8*)str_prof);
            mmi_ucs2cat((S8*) str_output, (const S8*)str_conn_res);
            
            DisplayPopup(str_output, IMG_GLOBAL_WARNING, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            DeleteScreenIfPresent(SCR_BT_CONNECTING);
     }

        MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
    }

    if(g_mmi_bt_hid_scr_cntx.flag==(U8)MMI_TRUE)
    {
        TurnOffBacklight();
        g_mmi_bt_hid_scr_cntx.flag=(U8)MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_connect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_connect_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conn_index;
    bt_hidd_connect_ind_struct *msg_p = (bt_hidd_connect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get index of activate conn list */
    for (conn_index = 0; conn_index < g_mmi_bth_hidd_cntx.active_conn_num; conn_index++)
    {
        if (g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
            && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
            && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
            && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
        {
            break;
        }
    }
    g_mmi_bth_hidd_cntx.active_conn_list[conn_index].active = MMI_TRUE;
    g_mmi_bth_hidd_cntx.active_conn_list[conn_index].conn_id = msg_p->connection_id;
    /* update BT address */
    g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.lap = msg_p->bt_addr.lap;
    g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.uap = msg_p->bt_addr.uap;
    g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.nap = msg_p->bt_addr.nap;
	 /* update to last device */
    g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap = msg_p->bt_addr.lap;
    g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap = msg_p->bt_addr.uap;
    g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap = msg_p->bt_addr.nap;
    
    if (conn_index == g_mmi_bth_hidd_cntx.active_conn_num)
    {
        g_mmi_bth_hidd_cntx.active_conn_num++;
        MMI_BT_ASSERT(g_mmi_bth_hidd_cntx.active_conn_num <= MMI_BTH_HIDD_MAX_CONNECTION);
    }

    if (!isIncomingCall() )
    {
        mmi_bt_entry_hid_app_select();
    }
    else
    {
        mmi_bt_hid_add_history_before_cm_marker(SCR_BT_REMOTE_CONTROL_DEV_SELECT,mmi_bt_entry_hid_app_select);
    }
    
    DeleteScreenIfPresent(SCR_BT_CONNECT_ACCEPT_CNF);
    DeleteScreenIfPresent(SCR_BT_CONNECTING);
    DeleteScreenIfPresent(SCR_BT_DISC_PROC);
    DeleteScreenIfPresent(SCR_BT_REMOTE_CONTROL_CONN_REQ);
    
    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_ACTIVATED:
        {
            /* send connect ind  */
            mmi_bth_connect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);

        }
            break;
        case MMI_BTH_HIDD_STAT_CONNECTING:
        {
            /* send connect cnf */
            mmi_bth_connect_cnf_hdler(
                MMI_TRUE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);

        }
            break;
        case MMI_BTH_HIDD_STAT_DISCONNECTING:
        {
            /* return disconnect cnf with failed result */
            mmi_bth_disconnect_cnf_hdler(
                MMI_FALSE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                (U32) MMI_BTH_HID_PROFILE_UUID,
                0xFFFFFFFF);
            /* send connect ind  */
            mmi_bth_connect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);

        }
            break;
        default:
            MMI_BT_ASSERT(0);
    }

    MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNECTED);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_disconnect_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  device_addr     [IN]            
 *  connect_id      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_disconnect_req_hdler(mmi_bth_bt_addr device_addr, U32 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_ACTIVATED:
        {
            mmi_bth_disconnect_cnf_hdler(
                MMI_FALSE,
                device_addr.lap,
                device_addr.uap,
                device_addr.nap,
                (U32) MMI_BTH_HID_PROFILE_UUID,
                0xFFFFFFFF);
        }
            break;
        case MMI_BTH_HIDD_STAT_CONNECTED:
        {
            bt_hidd_disconnect_req_struct *msg_p;

            msg_p =
                (bt_hidd_disconnect_req_struct*) construct_local_para(sizeof(bt_hidd_disconnect_req_struct), TD_CTRL);
            msg_p->bt_addr.lap = device_addr.lap;
            msg_p->bt_addr.uap = device_addr.uap;
            msg_p->bt_addr.nap = device_addr.nap;
            msg_p->connection_id = connect_id;

            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DISCONNECT_REQ, (void*)msg_p, NULL);
            /* SetProtocolEventHandler(mmi_bth_hidd_disconnect_cnf_hdler, MSG_ID_BT_HIDD_DISCONNECT_CNF); */
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DISCONNECTING);
        }
            break;
        default:
            MMI_BT_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_disconnect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_disconnect_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *str_prof, *str_conn_res;
    U8 str_output[80];
    U32 conn_index, reset_conn_index;
    bt_hidd_disconnect_cnf_struct *msg_p = (bt_hidd_disconnect_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == hidd_result_ok)
    {
        /* get index of activate conn list */
        for (conn_index = 0; conn_index < g_mmi_bth_hidd_cntx.active_conn_num; conn_index++)
        {
            if (g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
                && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
                && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
                && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
            {
                break;
            }
        }

        if (conn_index == g_mmi_bth_hidd_cntx.active_conn_num)
        {
            MMI_BT_ASSERT(0);
        }

        /* remove this existed_conn */
        if (conn_index == (g_mmi_bth_hidd_cntx.active_conn_num - 1))
        {
            memset(&(g_mmi_bth_hidd_cntx.active_conn_list[conn_index]), 0, sizeof(mmi_bth_hidd_connect_struct));
        }
        else
        {
            for (reset_conn_index = conn_index; reset_conn_index < g_mmi_bth_hidd_cntx.active_conn_num - 1;
                 reset_conn_index++)
            {
                memcpy(
                    &(g_mmi_bth_hidd_cntx.active_conn_list[reset_conn_index]),
                    &(g_mmi_bth_hidd_cntx.active_conn_list[reset_conn_index + 1]),
                    sizeof(mmi_bth_hidd_connect_struct));
            }
            memset(&(g_mmi_bth_hidd_cntx.active_conn_list[reset_conn_index]), 0, sizeof(mmi_bth_hidd_connect_struct));

        }
        MMI_BT_ASSERT(g_mmi_bth_hidd_cntx.active_conn_num);
        g_mmi_bth_hidd_cntx.active_conn_num--;

        str_prof = (U8*) GetString(STR_BT_PROF_HID);
        str_conn_res = (U8*) GetString(STR_BT_DISCON_ED);
        memset(str_output, 0, sizeof(U8) * 80);
        mmi_ucs2cpy((S8*) str_output, (const S8*)str_prof);
        mmi_ucs2cat((S8*) str_output, (const S8*)str_conn_res);
      
        DisplayPopup(str_output, IMG_GLOBAL_ACTIVATED, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) SUCCESS_TONE);
        SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_DEV_SELECT, (HistoryDelCBPtr) NULL);
	DeleteScreenIfPresent(SCR_BT_DISC_PROC);
        DeleteScreenIfPresent(SCR_BT_REMOTE_CONTROL_CONN_REQ);
        mmi_bt_del_scr(SCR_BT_REMOTE_CONTROL, SCR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM);
      }
    else
    {
        str_prof = (U8*) GetString(STR_BT_DISCONNECT);
        str_conn_res = (U8*) GetString(STR_BT_FAILED);
        memset(str_output, 0, sizeof(U8) * 80);
        mmi_ucs2cpy((S8*) str_output, (const S8*)str_prof);
        mmi_ucs2cat((S8*) str_output, (const S8*)str_conn_res);
        
        DisplayPopup(str_output, IMG_GLOBAL_WARNING, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
    }

    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_DEACTIVATING:
            if (msg_p->result == hidd_result_ok)
            {
                /* send disconnect ind */
                mmi_bth_disconnect_ind_hdler(
                    msg_p->bt_addr.lap,
                    msg_p->bt_addr.uap,
                    msg_p->bt_addr.nap,
                    MMI_BTH_HID_PROFILE_UUID,
                    msg_p->connection_id);
            
            }
            else
            {
            }

            if (!mmi_bth_hidd_disconnect_all())
            {
                mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            }
            break;
        case MMI_BTH_HIDD_STAT_DISCONNECTING:
            mmi_bth_disconnect_cnf_hdler(
                !(msg_p->result),
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                (U32) MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);
            if (g_mmi_bt_hid_scr_cntx.flag==(U8)MMI_TRUE)
            {
                TurnOffBacklight();
                g_mmi_bt_hid_scr_cntx.flag=(U8)MMI_FALSE;
            }


            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;

        default:
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_disconnect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_disconnect_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conn_index, reset_conn_index;
    U8 *str_prof, *str_conn_res;
    U8 str_output[80];
    bt_hidd_disconnect_ind_struct *msg_p = (bt_hidd_disconnect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get index of activate conn list */
    for (conn_index = 0; conn_index < g_mmi_bth_hidd_cntx.active_conn_num; conn_index++)
    {
        if (g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
            && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
            && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
            && g_mmi_bth_hidd_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
        {
            break;
        }
    }

    if (conn_index == g_mmi_bth_hidd_cntx.active_conn_num)
    {
    	if (g_mmi_bth_hidd_cntx.state == MMI_BTH_HIDD_STAT_AUTHORIZING)
	    {
            /* send link disconnected ind to hid scr module */
            mmi_bt_hid_authorized_failed_ind();
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
	    }
        return;
    }

    /* remove this existed_conn */
    if (conn_index == (g_mmi_bth_hidd_cntx.active_conn_num - 1))
    {
        memset(&(g_mmi_bth_hidd_cntx.active_conn_list[conn_index]), 0, sizeof(mmi_bth_hidd_connect_struct));
    }
    else
    {
        for (reset_conn_index = conn_index; reset_conn_index < g_mmi_bth_hidd_cntx.active_conn_num - 1;
             reset_conn_index++)
        {
            memcpy(
                &(g_mmi_bth_hidd_cntx.active_conn_list[reset_conn_index]),
                &(g_mmi_bth_hidd_cntx.active_conn_list[reset_conn_index + 1]),
                sizeof(mmi_bth_hidd_connect_struct));
        }
        memset(&(g_mmi_bth_hidd_cntx.active_conn_list[reset_conn_index]), 0, sizeof(mmi_bth_hidd_connect_struct));

    }
    MMI_BT_ASSERT(g_mmi_bth_hidd_cntx.active_conn_num);
    g_mmi_bth_hidd_cntx.active_conn_num--;


    str_prof = (U8*) GetString(STR_BT_PROF_HID);
    str_conn_res = (U8*) GetString(STR_BT_DISCON_ED);
    memset(str_output, 0, sizeof(U8) * 80);
    mmi_ucs2cpy((S8*) str_output, (const S8*)str_prof);
    mmi_ucs2cat((S8*) str_output, (const S8*)str_conn_res);
    
    DisplayPopup(str_output, IMG_GLOBAL_ACTIVATED, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) SUCCESS_TONE);
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_DEV_SELECT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_BT_DISC_PROC);
    DeleteScreenIfPresent(SCR_BT_REMOTE_CONTROL_CONN_REQ);
    mmi_bt_del_scr(SCR_BT_REMOTE_CONTROL, SCR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM);

    switch (g_mmi_bth_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_DEACTIVATING:
        {
            /* send disconnect ind */
            mmi_bth_disconnect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);
            /* doing deactivation */
            if (!mmi_bth_hidd_disconnect_all())
            {
                mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            }
            break;
        }
        case MMI_BTH_HIDD_STAT_CONNECTING:
        {

            /* send connect cnf */
            mmi_bth_connect_cnf_hdler(
                MMI_FALSE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HID_PROFILE_UUID,
                0xFFFFFFFF);
            /* send disconnect ind */
            mmi_bth_disconnect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;
        }
        case MMI_BTH_HIDD_STAT_DISCONNECTING:
        {
            /* send disconnect cnf */
            mmi_bth_disconnect_cnf_hdler(
                MMI_TRUE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                (U32) MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;
        }

        case MMI_BTH_HIDD_STAT_CONNECTED:
        {
            /* send disconnect ind */
            mmi_bth_disconnect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                MMI_BTH_HID_PROFILE_UUID,
                msg_p->connection_id);
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;
        }
        case MMI_BTH_HIDD_STAT_AUTHORIZING:
        {
            /* send link disconnected ind to hid scr module */
            mmi_bt_hid_authorized_failed_ind();
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;
        }
        default:
            break;
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_disconnect_all
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_hidd_disconnect_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_hidd_cntx.active_conn_num; i++)
    {
        if (g_mmi_bth_hidd_cntx.active_conn_list[i].active == MMI_TRUE)
        {
            {
                mmi_bth_hidd_disconnect_req_hdler(
                    g_mmi_bth_hidd_cntx.active_conn_list[i].bd_addr,
                    g_mmi_bth_hidd_cntx.active_conn_list[i].conn_id);
                result = MMI_TRUE;
                break;
            }
        }
    }

    if (i == g_mmi_bth_hidd_cntx.active_conn_num)
    {
        result = MMI_FALSE;
    }

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_connection_authorize_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_connection_authorize_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_connection_authorize_ind_struct *msg_p = (bt_hidd_connection_authorize_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mmi_bth_hidd_cntx.state == MMI_BTH_HIDD_STAT_ACTIVATED)
    {
	    MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_AUTHORIZING);
    }

  /* get device name from CM */
    memset((U8*) g_mmi_bth_hidd_cntx.hidd_dev_name, 0, BT_HIDD_MAX_DEV_NAME_LEN);
    mmi_bt_get_device_name( msg_p->bt_addr.lap,
                            msg_p->bt_addr.uap,
			    msg_p->bt_addr.nap,
			    (U8)BT_HIDD_MAX_DEV_NAME_LEN,
			    (U8*)g_mmi_bth_hidd_cntx.hidd_dev_name);
    
    memset(&(g_mmi_bth_hidd_cntx.last_connected_bd_addr), 0, sizeof(mmi_bth_bt_addr));
    memcpy(&(g_mmi_bth_hidd_cntx.last_connected_bd_addr), &(msg_p->bt_addr), sizeof(mmi_bth_bt_addr));

    if (!isIncomingCall())
    {
        /* show confirm screen */
        mmi_bt_hid_conn_confirm();
    }
    else
    {	
        mmi_bt_hid_add_history_before_cm_marker(SCR_BT_REMOTE_CONTROL_CONN_REQ, mmi_bt_hid_entry_conn_confirm_scr);
    }
	

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_connection_authorize_rsp_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_connection_authorize_rsp_hdler(mmi_bth_bt_addr bt_addr, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_connection_authorize_rsp_struct *msg_p;
    bt_hidd_result_enum rsp_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_hidd_connection_authorize_rsp_struct*) construct_local_para(sizeof(bt_hidd_connection_authorize_rsp_struct), TD_CTRL);
    msg_p->bt_addr.lap = bt_addr.lap;
    msg_p->bt_addr.uap = bt_addr.uap;
    msg_p->bt_addr.nap = bt_addr.nap;
    if	(result == MMI_TRUE)
    {
		rsp_result = hidd_connect_authorization_result_accepted;
    }
    else
    {
		rsp_result = hidd_connect_authorization_result_rejected;
    }
    msg_p->result = rsp_result;

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_RSP, (void*)msg_p, NULL);


	if (g_mmi_bth_hidd_cntx.state == MMI_BTH_HIDD_STAT_AUTHORIZING)
    {
	    MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
    }

    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_interrupt_data_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_interrupt_data_req_hdler(U8 data_len, U8* data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_interrupt_data_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    msg_p = (bt_hidd_interrupt_data_req_struct*) construct_local_para(sizeof(bt_hidd_interrupt_data_req_struct), TD_CTRL);
    msg_p->bt_addr.lap = g_mmi_bth_hidd_cntx.active_conn_list[0].bd_addr.lap;
    msg_p->bt_addr.uap = g_mmi_bth_hidd_cntx.active_conn_list[0].bd_addr.uap;
    msg_p->bt_addr.nap = g_mmi_bth_hidd_cntx.active_conn_list[0].bd_addr.nap;
    msg_p->connection_id = g_mmi_bth_hidd_cntx.active_conn_list[0].conn_id;
    msg_p->report_type = hidd_report_input;
    msg_p->data_len = data_len;
    msg_p->data_ptr = data_ptr;

    
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_INTERRUPT_DATA_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_hidd_interrupt_data_cnf_hdler, MSG_ID_BT_HIDD_CONNECT_CNF); */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_interrupt_data_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_interrupt_data_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_interrupt_data_cnf_struct *msg_p = (bt_hidd_interrupt_data_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result )
        {
        }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_connect_last_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_connect_last_dev(void)
{
	mmi_bth_hidd_connect_req_hdler(g_mmi_bth_hidd_cntx.last_connected_bd_addr);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_clear_last_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_clear_last_dev_info(void)
{
	g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap = 0;
	g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap = 0;
	g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_get_dev_name
 * DESCRIPTION
 *  This function is to get the bt device name from context
 * PARAMETERS
 *  name_buf        [IN]        
 *  p           [?](?)(?)(?)
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_get_dev_name(U8 *name_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy dev_name to MMI screen */
    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    utf8_char_cnt =
        (U8) ((mmi_chset_utf8_strlen((kal_uint8*) g_mmi_bth_hidd_cntx.hidd_dev_name) +
               1) * ENCODING_LENGTH);

    if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) name_buf,
                    MMI_BT_SCR_BD_NAME_LEN,
                    (kal_uint8*) g_mmi_bth_hidd_cntx.hidd_dev_name);
    }
    else
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) name_buf,
                    utf8_char_cnt,
                    (kal_uint8*) g_mmi_bth_hidd_cntx.hidd_dev_name);
    }

    /* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
    /* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

    /* shall check if there is any two_byte character mixed in one_bye UCS2 string */
    /* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters) */
    if (mmi_bt_test_ucs2((U16*) name_buf, (U16) (ucs2_str_len / ENCODING_LENGTH)))
    {
        mmi_bt_truncate_ucs2_string(
            (U16*) name_buf,
            (U16) (ucs2_str_len / ENCODING_LENGTH),
            (U16) ((MMI_BT_BD_NAME_LEN - 2) / 3));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_accept_conn
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_accept_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_HID_LOG(MMI_BT_HID_ACCEPT_FILE_RECV);
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_CONN_REQ, (HistoryDelCBPtr) NULL);
    GoBackHistory();
    
    mmi_bth_hidd_connection_authorize_rsp_hdler(g_mmi_bth_hidd_cntx.last_connected_bd_addr, MMI_TRUE);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_reject_conn
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_reject_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_HID_LOG(MMI_BT_HID_REJECT_FILE_RECV);
    
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_CONN_REQ, (HistoryDelCBPtr) NULL);
    GoBackHistory();
    
    mmi_bth_hidd_connection_authorize_rsp_hdler(g_mmi_bth_hidd_cntx.last_connected_bd_addr, MMI_FALSE);
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_authorize_confirm_del_cb
 * DESCRIPTION
 *  This function is to reject the connect when confirm screen is deleted
 * PARAMETERS
 *  p       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bth_hidd_authorize_confirm_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_HID_LOG1(MMI_BT_HID_AUTH_CONFIRM_DEL_CB,g_mmi_bth_hidd_cntx.state);

    if (g_mmi_bth_hidd_cntx.state == MMI_BTH_HIDD_STAT_AUTHORIZING)
    {
        mmi_bth_hidd_connection_authorize_rsp_hdler(g_mmi_bth_hidd_cntx.last_connected_bd_addr, MMI_FALSE);
    }

    return MMI_FALSE;
}


#endif /* __MMI_HIDD_SUPPORT__ */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 

