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
 * BTMMIHFP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for HFP application.
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
#ifdef __MMI_HFP_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "IdleAppProt.h"
#include "gpioInc.h"

/* MMI Nvram access */

/* Trace Header Files */

/* Call Management related API */
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "UCMGProt.h"

/* MMI BT profile related files */
#include "ProfilesDefs.h"
#include "ProfileGprots.h"

/* External Device Header Files */
#include "ExtDeviceDefs.h"
#include "BTMMICm.h"

/* HFP */
#include "bt_dm_struct.h"
#include "bt_hfg_struct.h"
#include "BTMMIHfp.h"
#include "BTMMIHfpGprots.h"

/* CM callback */
#include "BTMMICMGprots.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_bth_hfg_cntx_struct g_mmi_bth_hfg_cntx;

/***************************************************************************** 
* Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_bth_hfg_cntx, 0, sizeof(mmi_bth_hfg_cntx_struct));
    mmi_bth_init_hfp_event_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_init_hfp_event_handler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_init_hfp_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_INIT_EVENT_HDLR);

    /* Init protocol event handler */
    SetProtocolEventHandler(mmi_bth_hfg_activate_cnf_hdler, MSG_ID_BT_HFG_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_hfg_deactivate_cnf_hdler, MSG_ID_BT_HFG_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_hfg_connect_cnf_hdler, MSG_ID_BT_HFG_CONNECT_CNF);
    SetProtocolEventHandler(mmi_bth_hfg_connect_ind_hdler, MSG_ID_BT_HFG_CONNECT_IND);
    SetProtocolEventHandler(mmi_bth_hfg_disconnect_cnf_hdler, MSG_ID_BT_HFG_DISCONNECT_CNF);
    SetProtocolEventHandler(mmi_bth_hfg_disconnect_ind_hdler, MSG_ID_BT_HFG_DISCONNECT_IND);

    SetProtocolEventHandler(mmi_bth_hfg_speaker_gain_cnf_hdler, MSG_ID_BT_HFG_SPEAKER_GAIN_CNF);
    SetProtocolEventHandler(mmi_bth_hfg_speaker_gain_ind_hdler, MSG_ID_BT_HFG_SPEAKER_GAIN_IND);
    SetProtocolEventHandler(mmi_bth_hfg_mic_gain_ind_hdler, MSG_ID_BT_HFG_MIC_GAIN_IND);
    SetProtocolEventHandler(mmi_bth_hfg_mic_gain_cnf_hdler, MSG_ID_BT_HFG_MIC_GAIN_CNF);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_activate_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_activate_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_IDLE:
        {
            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_ACTIVATE_REQ, NULL, NULL);
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATING);
        }
            break;
        case MMI_BTH_HFG_STAT_ACTIVATED:
        {
            mmi_bth_activate_cnf_hdler((U32) MMI_BTH_HFG_PROFILE_UUID);
        }
            break;
        default:
            MMI_BT_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_activate_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_activate_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_activate_cnf_struct *msg_p = (bt_hfg_activate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == BT_HFG_RESULT_OK)
    {
        MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATED);
        mmi_bth_activate_cnf_hdler((U32) MMI_BTH_HFG_PROFILE_UUID);
    }
    else
    {
        switch (g_mmi_bth_hfg_cntx.state)
        {
            case MMI_BTH_HFG_STAT_ACTIVATING:
                MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_IDLE);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_deactivate_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_deactivate_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_ACTIVATED:
        {
            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_DEACTIVATE_REQ, NULL, NULL);
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_DEACTIVATING);
        }
            break;
        case MMI_BTH_HFG_STAT_CONNECTED:
        {
            mmi_bth_hfg_disconnect_all();
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_DEACTIVATING);
        }
            break;
        default:
            MMI_BT_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_deactivate_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_deactivate_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_deactivate_cnf_struct *msg_p = (bt_hfg_deactivate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == BT_HFG_RESULT_OK)
    {
        MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_IDLE);
        mmi_bth_deactivate_cnf_hdler((U32) MMI_BTH_HFG_PROFILE_UUID);
    }
    else
    {
        switch (g_mmi_bth_hfg_cntx.state)
        {
            case MMI_BTH_HFG_STAT_DEACTIVATING:
                MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATED);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_connect_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  device_addr     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_connect_req_hdler(mmi_bth_bt_addr device_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_ACTIVATED:
        {
            bt_hfg_connect_req_struct *msg_p;

            msg_p = (bt_hfg_connect_req_struct*) construct_local_para(sizeof(bt_hfg_connect_req_struct), TD_CTRL);
            msg_p->bt_addr.lap = device_addr.lap;
            msg_p->bt_addr.uap = device_addr.uap;
            msg_p->bt_addr.nap = device_addr.nap;

            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_CONNECT_REQ, (void*)msg_p, NULL);
            /* SetProtocolEventHandler(mmi_bth_hfg_connect_cnf_hdler, MSG_ID_BT_HFG_CONNECT_CNF); */
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_REQ, MMI_PROFILES_BT_OK);
        #endif 
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_CONNECTING);
        }
            break;
        case MMI_BTH_HFG_STAT_CONNECTED:
        {
            mmi_bth_connect_cnf_hdler(
                MMI_FALSE,
                device_addr.lap,
                device_addr.uap,
                device_addr.nap,
                NULL,
                MMI_BTH_HFG_PROFILE_UUID,
                0xFFFFFFFF);

        }
            break;
        default:
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_connect_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conn_index;
    bt_hfg_connect_cnf_struct *msg_p = (bt_hfg_connect_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_CONNECTING:
            break;
        case MMI_BTH_HFG_STAT_IDLE:
            /* ignore this case, receiving connect cnf at idle state */
            /* for BT abnormal reset case, hfg module may receive the connect cnf at idle state */
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
        MMI_BTH_HFG_PROFILE_UUID,
        msg_p->connection_id);


    if (msg_p->result == BT_HFG_RESULT_OK)
    {

        MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_CONNECTED);
    #if defined(__MMI_BT_PROFILE__)
        mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_OK);
    #endif 
        /* get index of activate conn list */
        for (conn_index = 0; conn_index < g_mmi_bth_hfg_cntx.active_conn_num; conn_index++)
        {
            if (g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
                && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
                && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
                && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
            {
                break;
            }
        }
        g_mmi_bth_hfg_cntx.active_conn_list[conn_index].active = MMI_TRUE;
        g_mmi_bth_hfg_cntx.active_conn_list[conn_index].conn_id = msg_p->connection_id;
        /* update BT address */
        g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.lap = msg_p->bt_addr.lap;
        g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.uap = msg_p->bt_addr.uap;
        g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.nap = msg_p->bt_addr.nap;
        if (conn_index == g_mmi_bth_hfg_cntx.active_conn_num)
        {
            g_mmi_bth_hfg_cntx.active_conn_num++;
            MMI_BT_ASSERT(g_mmi_bth_hfg_cntx.active_conn_num <= MMI_BTH_HFG_MAX_CONNECTION);
        }
    }
    else
    {

        MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATED);
    #if defined(__MMI_BT_PROFILE__)
        mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_FAIL);
    #endif 
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_connect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_connect_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conn_index;
    bt_hfg_connect_ind_struct *msg_p = (bt_hfg_connect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get index of activate conn list */
    for (conn_index = 0; conn_index < g_mmi_bth_hfg_cntx.active_conn_num; conn_index++)
    {
        if (g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
            && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
            && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
            && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
        {
            break;
        }
    }
    g_mmi_bth_hfg_cntx.active_conn_list[conn_index].active = MMI_TRUE;
    g_mmi_bth_hfg_cntx.active_conn_list[conn_index].conn_id = msg_p->connection_id;
    /* update BT address */
    g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.lap = msg_p->bt_addr.lap;
    g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.uap = msg_p->bt_addr.uap;
    g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.nap = msg_p->bt_addr.nap;
    if (conn_index == g_mmi_bth_hfg_cntx.active_conn_num)
    {
        g_mmi_bth_hfg_cntx.active_conn_num++;
        MMI_BT_ASSERT(g_mmi_bth_hfg_cntx.active_conn_num <= MMI_BTH_HFG_MAX_CONNECTION);
    }

    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_ACTIVATED:
        {
            /* send connect ind  */
            mmi_bth_connect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HFG_PROFILE_UUID,
                msg_p->connection_id);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 

        }
            break;
        case MMI_BTH_HFG_STAT_CONNECTING:
        {
            /* send connect cnf */
            mmi_bth_connect_cnf_hdler(
                MMI_TRUE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HFG_PROFILE_UUID,
                msg_p->connection_id);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_OK);
        #endif 

        }
            break;
        case MMI_BTH_HFG_STAT_DISCONNECTING:
        {
            /* return disconnect cnf with failed result */
            mmi_bth_disconnect_cnf_hdler(
                MMI_FALSE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                (U32) MMI_BTH_HFG_PROFILE_UUID,
                0xFFFFFFFF);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_FAIL);
        #endif 
            /* send connect ind  */
            mmi_bth_connect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HFG_PROFILE_UUID,
                msg_p->connection_id);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 

        }
            break;
        default:
            MMI_BT_ASSERT(0);
    }

    MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_CONNECTED);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_disconnect_req_hdler
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
void mmi_bth_hfg_disconnect_req_hdler(mmi_bth_bt_addr device_addr, U32 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_ACTIVATED:
        {
            mmi_bth_disconnect_cnf_hdler(
                MMI_FALSE,
                device_addr.lap,
                device_addr.uap,
                device_addr.nap,
                (U32) MMI_BTH_HFG_PROFILE_UUID,
                0xFFFFFFFF);
        }
            break;
        case MMI_BTH_HFG_STAT_CONNECTED:
        {
            bt_hfg_disconnect_req_struct *msg_p;

            msg_p =
                (bt_hfg_disconnect_req_struct*) construct_local_para(sizeof(bt_hfg_disconnect_req_struct), TD_CTRL);
            msg_p->bt_addr.lap = device_addr.lap;
            msg_p->bt_addr.uap = device_addr.uap;
            msg_p->bt_addr.nap = device_addr.nap;
            msg_p->connection_id = connect_id;

        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_REQ, MMI_PROFILES_BT_OK);
        #endif 

            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_DISCONNECT_REQ, (void*)msg_p, NULL);
            /* SetProtocolEventHandler(mmi_bth_hfg_disconnect_cnf_hdler, MSG_ID_BT_HFG_DISCONNECT_CNF); */
        #if 0    
        #if defined(__MMI_BT_PROFILE__)
/* under construction !*/
        #endif 
        #endif
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_DISCONNECTING);
        }
            break;
        default:
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_disconnect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_disconnect_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conn_index, reset_conn_index;
    bt_hfg_disconnect_cnf_struct *msg_p = (bt_hfg_disconnect_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == BT_HFG_RESULT_OK)
    {
        /* get index of activate conn list */
        for (conn_index = 0; conn_index < g_mmi_bth_hfg_cntx.active_conn_num; conn_index++)
        {
            if (g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
                && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
                && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
                && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
            {
                break;
            }
        }

        if (conn_index == g_mmi_bth_hfg_cntx.active_conn_num)
        {
            MMI_BT_ASSERT(0);
        }

        /* remove this existed_conn */
        if (conn_index == (g_mmi_bth_hfg_cntx.active_conn_num - 1))
        {
            memset(&(g_mmi_bth_hfg_cntx.active_conn_list[conn_index]), 0, sizeof(mmi_bth_hfg_connect_struct));
        }
        else
        {
            for (reset_conn_index = conn_index; reset_conn_index < g_mmi_bth_hfg_cntx.active_conn_num - 1;
                 reset_conn_index++)
            {
                memcpy(
                    &(g_mmi_bth_hfg_cntx.active_conn_list[reset_conn_index]),
                    &(g_mmi_bth_hfg_cntx.active_conn_list[reset_conn_index + 1]),
                    sizeof(mmi_bth_hfg_connect_struct));
            }
            memset(&(g_mmi_bth_hfg_cntx.active_conn_list[reset_conn_index]), 0, sizeof(mmi_bth_hfg_connect_struct));

        }
        MMI_BT_ASSERT(g_mmi_bth_hfg_cntx.active_conn_num);
        g_mmi_bth_hfg_cntx.active_conn_num--;

    }

    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_DEACTIVATING:
            if (msg_p->result == BT_HFG_RESULT_OK)
            {
                /* send disconnect ind */
                mmi_bth_disconnect_ind_hdler(
                    msg_p->bt_addr.lap,
                    msg_p->bt_addr.uap,
                    msg_p->bt_addr.nap,
                    MMI_BTH_HFG_PROFILE_UUID,
                    msg_p->connection_id);
            
            #if defined(__MMI_BT_PROFILE__)
                mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_OK);
            #endif 
            }
            else
            {
            #if defined(__MMI_BT_PROFILE__)
                mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_FAIL);
            #endif 
            }

            if (!mmi_bth_hfg_disconnect_all())
            {
                mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_DEACTIVATE_REQ, NULL, NULL);
            }
            break;
        case MMI_BTH_HFG_STAT_DISCONNECTING:

            if (msg_p->result == BT_HFG_RESULT_OK)
            {
                mmi_bth_disconnect_cnf_hdler(
                    !(msg_p->result),
                    msg_p->bt_addr.lap,
                    msg_p->bt_addr.uap,
                    msg_p->bt_addr.nap,
                    (U32) MMI_BTH_HFG_PROFILE_UUID,
                    msg_p->connection_id);

            #if defined(__MMI_BT_PROFILE__)
                mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_OK);
            #endif 
            }
            else
            {
                mmi_bth_disconnect_cnf_hdler(
                    !(msg_p->result),
                    msg_p->bt_addr.lap,
                    msg_p->bt_addr.uap,
                    msg_p->bt_addr.nap,
                    (U32) MMI_BTH_HFG_PROFILE_UUID,
                    msg_p->connection_id);
                MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_CONNECTED);
                return;
                
            }

            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATED);
            break;

        default:
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_disconnect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_disconnect_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conn_index, reset_conn_index;
    bt_hfg_disconnect_ind_struct *msg_p = (bt_hfg_disconnect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get index of activate conn list */
    for (conn_index = 0; conn_index < g_mmi_bth_hfg_cntx.active_conn_num; conn_index++)
    {
        if (g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.lap == msg_p->bt_addr.lap
            && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.uap == msg_p->bt_addr.uap
            && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].bd_addr.nap == msg_p->bt_addr.nap
            && g_mmi_bth_hfg_cntx.active_conn_list[conn_index].conn_id == msg_p->connection_id)
        {
            break;
        }
    }

    if (conn_index == g_mmi_bth_hfg_cntx.active_conn_num)
    {
        return;
    }

    /* remove this existed_conn */
    if (conn_index == (g_mmi_bth_hfg_cntx.active_conn_num - 1))
    {
        memset(&(g_mmi_bth_hfg_cntx.active_conn_list[conn_index]), 0, sizeof(mmi_bth_hfg_connect_struct));
    }
    else
    {
        for (reset_conn_index = conn_index; reset_conn_index < g_mmi_bth_hfg_cntx.active_conn_num - 1;
             reset_conn_index++)
        {
            memcpy(
                &(g_mmi_bth_hfg_cntx.active_conn_list[reset_conn_index]),
                &(g_mmi_bth_hfg_cntx.active_conn_list[reset_conn_index + 1]),
                sizeof(mmi_bth_hfg_connect_struct));
        }
        memset(&(g_mmi_bth_hfg_cntx.active_conn_list[reset_conn_index]), 0, sizeof(mmi_bth_hfg_connect_struct));

    }
    MMI_BT_ASSERT(g_mmi_bth_hfg_cntx.active_conn_num);
    g_mmi_bth_hfg_cntx.active_conn_num--;

    switch (g_mmi_bth_hfg_cntx.state)
    {
        case MMI_BTH_HFG_STAT_DEACTIVATING:
        {
            /* send disconnect ind */
            mmi_bth_disconnect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                MMI_BTH_HFG_PROFILE_UUID,
                msg_p->connection_id);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 
            /* doing deactivation */
            if (!mmi_bth_hfg_disconnect_all())
            {
                mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_DEACTIVATE_REQ, NULL, NULL);
            }
            break;
        }
            break;
        case MMI_BTH_HFG_STAT_CONNECTING:
        {

            /* send connect cnf */
            mmi_bth_connect_cnf_hdler(
                MMI_FALSE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                NULL,
                MMI_BTH_HFG_PROFILE_UUID,
                0xFFFFFFFF);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_FAIL);
        #endif 
            /* send disconnect ind */
            mmi_bth_disconnect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                MMI_BTH_HFG_PROFILE_UUID,
                msg_p->connection_id);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATED);

        }
            break;
        case MMI_BTH_HFG_STAT_DISCONNECTING:
        {
            /* send disconnect cnf */
            mmi_bth_disconnect_cnf_hdler(
                MMI_TRUE,
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                (U32) MMI_BTH_HFG_PROFILE_UUID,
                msg_p->connection_id);
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_OK);
        #endif 
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATED);
        }
            break;

        case MMI_BTH_HFG_STAT_CONNECTED:
        {
            /* send disconnect ind */
            mmi_bth_disconnect_ind_hdler(
                msg_p->bt_addr.lap,
                msg_p->bt_addr.uap,
                msg_p->bt_addr.nap,
                MMI_BTH_HFG_PROFILE_UUID,
                msg_p->connection_id);
            /* send disconnect ind */
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 
            MMI_BTH_HFG_STATE_TRANS(MMI_BTH_HFG_STAT_ACTIVATED);
        }
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_speaker_gain_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  speaker_gain        [IN]            
 *  conn_id             [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_speaker_gain_req_hdler(U8 speaker_gain, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_speaker_gain_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_hfg_speaker_gain_req_struct*) construct_local_para(sizeof(bt_hfg_speaker_gain_req_struct), TD_CTRL);
    msg_p->gain = speaker_gain;
    msg_p->connection_id = conn_id;

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_SPEAKER_GAIN_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_hfg_speaker_gain_cnf_hdler, MSG_ID_BT_HFG_SPEAKER_GAIN_CNF); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_speaker_gain_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_speaker_gain_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_speaker_gain_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_speaker_gain_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_speaker_gain_ind_struct *msg_p = (bt_hfg_speaker_gain_ind_struct*) msg;
    S32 ui_volume_level = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_is_hs_connected())
    {
        /* check if already in existed conn list */
        for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
        {
            if (g_mmi_bth_cntx.existed_conn[i].conn_id == msg_p->connection_id)
            {
                break;
            }
        }

        if (i < g_mmi_bth_cntx.existed_conn_num)
        {
            if ( /* msg_p->gain >=0 && */ msg_p->gain < 3)
            {
                ui_volume_level = LEVEL1;
            }
            else if (msg_p->gain >= 3 && msg_p->gain < 7)
            {
                ui_volume_level = LEVEL2;
            }
            else if (msg_p->gain >= 7 && msg_p->gain < 9)
            {
                ui_volume_level = LEVEL3;
            }
            else if (msg_p->gain >= 9 && msg_p->gain < 11)
            {
                ui_volume_level = LEVEL4;
            }
            else if (msg_p->gain >= 11 && msg_p->gain < 13)
            {
                ui_volume_level = LEVEL5;
            }
            else if (msg_p->gain >= 13 && msg_p->gain < 15)
            {
                ui_volume_level = LEVEL6;
            }
            else if (msg_p->gain == 15)
            {
                ui_volume_level = LEVEL7;
            }
            else
            {
                MMI_BT_ASSERT(0);
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
			#endif
			#ifdef __MMI_UCM__
		    if ((mmi_ucm_app_incoming_call(MMI_UCM_VOICE_CALL_TYPE_ALL) == 0 && 
		         mmi_ucm_app_outgoing_call(MMI_UCM_VOICE_CALL_TYPE_ALL) == 0  &&
		         mmi_ucm_app_active_call(MMI_UCM_VOICE_CALL_TYPE_ALL) > 0) ||
		        (mmi_ucm_app_incoming_call(MMI_UCM_VOICE_CALL_TYPE_ALL) > 0) )
			#else /* __MMI_UCM__ */
		    if ((!isIncomingCall() && !isOutgoingCall() && GetTotalActiveCallCount() > 0) ||
				(isIncomingCall()))
			#endif /* __MMI_UCM__ */
			{
                    SetSpeechVolume(ui_volume_level);
			}

			
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_mic_gain_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  speaker_gain        [IN]            
 *  conn_id             [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_mic_gain_req_hdler(U8 speaker_gain, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_mic_gain_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_hfg_mic_gain_req_struct*) construct_local_para(sizeof(bt_hfg_mic_gain_req_struct), TD_CTRL);
    msg_p->gain = speaker_gain;
    msg_p->connection_id = conn_id;

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HFG_MIC_GAIN_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_hfg_mic_gain_cnf_hdler, MSG_ID_BT_HFG_MIC_GAIN_CNF); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_mic_gain_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_mic_gain_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_mic_gain_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hfg_mic_gain_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfg_disconnect_all
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_hfg_disconnect_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_hfg_cntx.active_conn_num; i++)
    {
        if (g_mmi_bth_hfg_cntx.active_conn_list[i].active == MMI_TRUE)
        {
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif    
            {
                mmi_bth_hfg_disconnect_req_hdler(
                    g_mmi_bth_hfg_cntx.active_conn_list[i].bd_addr,
                    g_mmi_bth_hfg_cntx.active_conn_list[i].conn_id);
                result = MMI_TRUE;
                break;
            }
        }
    }

    if (i == g_mmi_bth_hfg_cntx.active_conn_num)
    {
        result = MMI_FALSE;
    }

    return result;

}

#endif /* __MMI_HFP_SUPPORT__ */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 

