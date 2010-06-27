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
 * BTMMIAVRCP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for Bluetooth AVRCP MMI application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#if defined(__MMI_BT_MTK_SUPPORT__) && (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__))
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "ProtocolEvents.h"
#if defined(__MMI_TOUCH_SCREEN__)
#endif
/* Trace Header Files */

/* avrcp header files */
#include "bt_avrcp_struct.h"
#include "bt_avrcp.h"

#include "BTMMICM.h"
#include "BTMMICMGProts.h"
#include "BTMMIAVRCP.h"
#include "BTMMIAVRCPGProt.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
/*
* Target global context, use channel 0
* Controller global context, use channel 1
*/
mmi_avrcp_cntx_struct g_mmi_avrcp_cntx[BT_AVRCP_MAX_CHANNEL];

#define BT_AVRCP_MAX_CALLBACK_NUM 2
//static AVRCPCmdFuncPtr g_mmi_avrcp_cmd_func_ptr;
static AVRCPCmdFuncPtr g_mmi_avrcp_cmd_func_ptr_list[BT_AVRCP_MAX_CALLBACK_NUM]; /* at most 2 func ptr */
static S32 g_mmi_avrcp_cmd_func_ptr_count = 0 ; /* at most 2 func ptr */

static U8 g_mmi_avrcp_last_pressed_cmd = 0xff; /* last pressed command, 0xff is a non spec command value to identify there is no command */
static U8 g_mmi_avrcp_pressed_cmd_count = 0 ;  /* to accumulate total pressed cmd numer with the same av/c command */
static BOOL g_mmi_avrcp_frm_blocked = FALSE ;  /* framework keypad / touch blocked */
#ifdef __MMI_AVRCP_CT_SUPPORT__
static AVRCPCmdCnfPtr g_mmi_avrcp_cmd_cnf_ptr;
#endif

/***************************************************************************** 
* External Functions
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_get_cmd_hdlr
 * DESCRIPTION
 *  This function is to get the latest register cmd hdlr ptr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static AVRCPCmdFuncPtr mmi_bt_avrcp_get_cmd_hdlr_func_ptr(void)
{
    S32 i = g_mmi_avrcp_cmd_func_ptr_count;

    PRINT_INFORMATION("mmi_bt_avrcp_get_cmd_hdlr_func_ptr: func number %d", i);

    if (i == 0)
        return NULL;

    ASSERT( i <= BT_AVRCP_MAX_CALLBACK_NUM );

    return g_mmi_avrcp_cmd_func_ptr_list[i-1];
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_init");
    mmi_bt_avrcp_init_event_handler();

    for(i = 0 ; i < BT_AVRCP_MAX_CHANNEL ; i++)
    {
        MMI_AVRCP_STATE_TRANS(i, MMI_AVRCP_IDLE);
    }

//    g_mmi_avrcp_cmd_func_ptr_count = 0;
//    g_mmi_avrcp_cmd_func_ptr_list[0] = g_mmi_avrcp_cmd_func_ptr_list[1] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_init_event_handler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_init_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_AVRCP_INIT_EVENT_HDLR);
    PRINT_INFORMATION("mmi_bt_avrcp_init_event_handler");

    SetProtocolEventHandler(mmi_bt_avrcp_activate_cnf_hdlr, MSG_ID_BT_AVRCP_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bt_avrcp_deactivate_cnf_hdlr, MSG_ID_BT_AVRCP_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bt_avrcp_connect_cnf_hdlr, MSG_ID_BT_AVRCP_CONNECT_CNF);
    SetProtocolEventHandler(mmi_bt_avrcp_connect_ind_hdlr, MSG_ID_BT_AVRCP_CONNECT_IND);
    SetProtocolEventHandler(mmi_bt_avrcp_disconnect_cnf_hdlr, MSG_ID_BT_AVRCP_DISCONNECT_CNF);
    SetProtocolEventHandler(mmi_bt_avrcp_disconnect_ind_hdlr, MSG_ID_BT_AVRCP_DISCONNECT_IND);

    SetProtocolEventHandler(mmi_bt_avrcp_cmd_frame_cnf_hdlr, MSG_ID_BT_AVRCP_CMD_FRAME_CNF);
    SetProtocolEventHandler(mmi_bt_avrcp_cmd_frame_ind_hdlr, MSG_ID_BT_AVRCP_CMD_FRAME_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_activate_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_activate_tg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_activate_tg_req");
    mmi_bt_avrcp_activate_req(BT_AVRCP_TG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_activate_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_activate_ct_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_activate_ct_req");    
    mmi_bt_avrcp_activate_req(BT_AVRCP_CT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_activate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  avrcp_role      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_activate_req(U8 avrcp_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_activate_req");    
    MMI_AVRCP_LOG_STATE(avrcp_role);

    MMI_AVRCP_ASSERT(avrcp_role == BT_AVRCP_TG || avrcp_role == BT_AVRCP_CT);

    if (MMI_AVRCP_CTX(avrcp_role, avrcp_state) != MMI_AVRCP_IDLE)
    {
        return;
    }

    g_mmi_avrcp_cntx[avrcp_role].avrcp_role = avrcp_role;

    /* Currently two channels, use role value as channel number */
    bt_avrcp_send_activate_req(MOD_MMI, avrcp_role, avrcp_role);

    MMI_AVRCP_STATE_TRANS(avrcp_role, MMI_AVRCP_ACTIVATING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_activate_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_activate_cnf_struct *msg_p = (bt_avrcp_activate_cnf_struct*) msg;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_activate_cnf_hdlr");

    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
    {
        if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == MMI_AVRCP_ACTIVATING)
        {
            MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_ACTIVATED);
            if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
            {
                mmi_bth_activate_cnf_hdler(MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID);
            }
            else if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_CT)
            {
                mmi_bth_activate_cnf_hdler(MMI_BTH_AV_REMOTE_CONTROL_UUID);
            }
        }
    }
    else /* Should not activate fail*/
    {
        MMI_AVRCP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_deactivate_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_deactivate_tg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_deactivate_tg_req");
    mmi_bt_avrcp_deactivate_req(BT_AVRCP_TG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_deactivate_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_deactivate_ct_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_deactivate_ct_req");
    mmi_bt_avrcp_deactivate_req(BT_AVRCP_CT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_deactivate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_deactivate_req(U8 avrcp_chnl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_deactivate_req");
    MMI_AVRCP_ASSERT(avrcp_chnl < BT_AVRCP_MAX_CHANNEL);

    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == MMI_AVRCP_ACTIVATED ||
        MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == MMI_AVRCP_ACTIVATING)
    {
        bt_avrcp_send_deactivate_req(MOD_MMI, avrcp_chnl);
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_DEACTIVATING);
    }
    /* If in connected state, need to disconnect in advance */
    else if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == MMI_AVRCP_CONNECTED)
    {
        bt_avrcp_send_disconnect_req(MOD_MMI, avrcp_chnl);
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_DEACTIVATING);
    }
    /* Wait connect / disconnect response to deactivate AVRCP */
    else if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == MMI_AVRCP_DISCONNECTING ||
             MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == MMI_AVRCP_CONNECTING)
    {
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_DEACTIVATING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_deactivate_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_deactivate_cnf_struct *msg_p = (bt_avrcp_deactivate_cnf_struct*) msg;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_deactivate_cnf_hdlr");
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
    {
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_IDLE);

        if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
        {
            mmi_bth_deactivate_cnf_hdler(MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID);
        }
        else
        {
            mmi_bth_deactivate_cnf_hdler(MMI_BTH_AV_REMOTE_CONTROL_UUID);
        }
    }
    else
    {
        /* Should not deactivate fail */
        MMI_AVRCP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_connect_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_connect_tg_req(mmi_bth_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_connect_tg_req");
    mmi_bt_avrcp_connect_req(BT_AVRCP_TG, dev_addr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_connect_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_connect_ct_req(mmi_bth_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_connect_ct_req");
    mmi_bt_avrcp_connect_req(BT_AVRCP_CT, dev_addr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_connect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_connect_req(U8 avrcp_chnl, mmi_bth_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_dev_addr_struct bt_addr;
    U32 profile_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_connect_req");
    MMI_AVRCP_ASSERT(avrcp_chnl < BT_AVRCP_MAX_CHANNEL);
    
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) != MMI_AVRCP_ACTIVATED)
    {
        /* Inform CM connect result here */
        if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
        {
            profile_id = MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID;
        }
        else
        {
            profile_id = MMI_BTH_AV_REMOTE_CONTROL_UUID;
        }

        mmi_bth_connect_cnf_hdler(MMI_FALSE, dev_addr.lap, dev_addr.uap, dev_addr.nap, NULL, profile_id, 0);
        return;
    }

    bt_addr.lap = dev_addr.lap;
    bt_addr.uap = dev_addr.uap;
    bt_addr.nap = dev_addr.nap;

    bt_avrcp_send_connect_req(MOD_MMI, avrcp_chnl, &bt_addr, g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role);

    MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_CONNECTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_connect_cnf_struct *msg_p = (bt_avrcp_connect_cnf_struct*) msg;
    U32 profile_id = 0;
    MMI_BOOL connect_result = MMI_FALSE;
    U8 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_connect_cnf_hdlr");
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;
    
    g_mmi_avrcp_cntx[avrcp_chnl].device_addr = msg_p->device_addr;

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case MMI_AVRCP_CONNECTING:

            if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
            {
                profile_id = MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID;
            }
            else
            {
                profile_id = MMI_BTH_AV_REMOTE_CONTROL_UUID;
            }

            /* Change state when connect success */
            if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
            {
                MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_CONNECTED);
                connect_result = MMI_TRUE;
                g_mmi_avrcp_last_pressed_cmd = 0xff;
                g_mmi_avrcp_pressed_cmd_count = 0;
            #if defined(__MMI_TOUCH_SCREEN__)
                mmi_pen_set_event_handler_callback(mmi_bt_avrcp_frm_sync_touch_calllback,NULL);
            #endif
            }
            /* Connect fail */
            else
            {
                MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_ACTIVATED);
            }

            /* Inform CM connect result */
            mmi_bth_connect_cnf_hdler(
                connect_result,
                msg_p->device_addr.lap,
                msg_p->device_addr.uap,
                msg_p->device_addr.nap,
                NULL,
                profile_id,
                (U32)msg_p->connect_id);
            break;

        case MMI_AVRCP_DISCONNECTING:
            break;

        case MMI_AVRCP_DEACTIVATING:
            bt_avrcp_send_deactivate_req(MOD_MMI, avrcp_chnl);
            break;

        default:
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_connect_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_connect_ind_struct *msg_p = (bt_avrcp_connect_ind_struct*) msg;
    U32 profile_id;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_connect_ind_hdlr");
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;
    
    g_mmi_avrcp_cntx[avrcp_chnl].device_addr = msg_p->device_addr;

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case MMI_AVRCP_ACTIVATED:
        case MMI_AVRCP_CONNECTING:

            MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_CONNECTED);
            g_mmi_avrcp_last_pressed_cmd = 0xff;
            g_mmi_avrcp_pressed_cmd_count = 0;
        #if defined(__MMI_TOUCH_SCREEN__)
            mmi_pen_set_event_handler_callback(mmi_bt_avrcp_frm_sync_touch_calllback,NULL);
        #endif

            if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
            {
                profile_id = MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID;
            }
            else
            {
                profile_id = MMI_BTH_AV_REMOTE_CONTROL_UUID;
            }

            mmi_bth_connect_ind_hdler(
                msg_p->device_addr.lap,
                msg_p->device_addr.uap,
                msg_p->device_addr.nap,
                NULL,
                profile_id,
                (U32)msg_p->connect_id);

            break;

        default:
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_disconnect_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_disconnect_tg_req(mmi_bth_bt_addr dev_addr, U32 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_disconnect_tg_req");
    mmi_bt_avrcp_disconnect_req(BT_AVRCP_TG, dev_addr, connect_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_disconnect_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_disconnect_ct_req(mmi_bth_bt_addr dev_addr, U32 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_disconnect_ct_req");
    mmi_bt_avrcp_disconnect_req(BT_AVRCP_CT, dev_addr, connect_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_disconnect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [IN]        
 *  connect_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_disconnect_req(U8 avrcp_chnl, mmi_bth_bt_addr dev_addr, U32 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_disconnect_req");
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl,avrcp_state) == MMI_AVRCP_CONNECTED ||
        MMI_AVRCP_CTX(avrcp_chnl,avrcp_state) == MMI_AVRCP_CONNECTING)
    {
        bt_avrcp_send_disconnect_req(MOD_MMI, avrcp_chnl);

        MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_DISCONNECTING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_disconnect_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_disconnect_cnf_struct *msg_p = (bt_avrcp_disconnect_cnf_struct*) msg;
    U32 lap;
    U8 uap;
    U16 nap;
    U32 profile_id;
    MMI_BOOL disconnect_result = MMI_FALSE;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_disconnect_cnf_hdlr");
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case MMI_AVRCP_DISCONNECTING:

            MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_ACTIVATED);
        #if defined(__MMI_TOUCH_SCREEN__)
            mmi_pen_reset_event_handler_callback(mmi_bt_avrcp_frm_sync_touch_calllback,NULL);
        #endif

            lap = g_mmi_avrcp_cntx[avrcp_chnl].device_addr.lap;
            uap = g_mmi_avrcp_cntx[avrcp_chnl].device_addr.uap;
            nap = g_mmi_avrcp_cntx[avrcp_chnl].device_addr.nap;

            if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
            {
                profile_id = MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID;
            }
            else
            {
                profile_id = MMI_BTH_AV_REMOTE_CONTROL_UUID;
            }

            if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
            {
                disconnect_result = MMI_TRUE;
            }

            mmi_bth_disconnect_cnf_hdler(disconnect_result, lap, uap, nap, profile_id, (U32)msg_p->connect_id);

            break;

        case MMI_AVRCP_DEACTIVATING:
            bt_avrcp_send_deactivate_req(MOD_MMI, avrcp_chnl);
            break;
        default:
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_disconnect_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_disconnect_ind_struct *msg_p = (bt_avrcp_disconnect_ind_struct*)msg;
    U32 lap;
    U8 uap;
    U16 nap;
    U32 profile_id;
    U8 avrcp_chnl;
    
    AVRCPCmdFuncPtr func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_disconnect_ind_hdlr");

    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    /* Change to activated state if not in idle state */
    if(MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) > MMI_AVRCP_IDLE)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_pen_reset_event_handler_callback(mmi_bt_avrcp_frm_sync_touch_calllback,NULL);
    #endif
        lap = g_mmi_avrcp_cntx[avrcp_chnl].device_addr.lap;
        uap = g_mmi_avrcp_cntx[avrcp_chnl].device_addr.uap;
        nap = g_mmi_avrcp_cntx[avrcp_chnl].device_addr.nap;

        if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
        {
            profile_id = MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID;
        }
        else
        {
            profile_id = MMI_BTH_AV_REMOTE_CONTROL_UUID;
        }

        mmi_bth_disconnect_ind_hdler(lap, uap, nap, profile_id, msg_p->connect_id);

        /*if it is in disconnecting state, it means cm is waiting for disconnect cnf.*/
        if(MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == MMI_AVRCP_DISCONNECTING)
        {
            mmi_bth_disconnect_cnf_hdler(MMI_TRUE, lap, uap, nap, profile_id, (U32)msg_p->connect_id);
        }

        MMI_AVRCP_STATE_TRANS(avrcp_chnl, MMI_AVRCP_ACTIVATED);

        /*to handle the button down cancel action*/
        if ( (func_ptr = mmi_bt_avrcp_get_cmd_hdlr_func_ptr()) != NULL && g_mmi_avrcp_last_pressed_cmd != 0xff)
        {
            func_ptr(g_mmi_avrcp_last_pressed_cmd, MMI_AVRCP_KEY_CANCELED);
            g_mmi_avrcp_last_pressed_cmd = 0xff;
            g_mmi_avrcp_pressed_cmd_count = 0;
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_cmd_frame_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_cmd_frame_req(U8 avrcp_chnl, U8 op_code, U8 op_id, U8 key_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ctype = 0;
    U8 subunit_type = 0;
    U8 subunit_id = 0;
    U8 send_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_cmd_frame_req");
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) != MMI_AVRCP_CONNECTED)
    {
        return;
    }

    switch (op_code)
    {
        case BT_AVRCP_OP_UNIT_INFO:
            ctype = BT_AVRCP_CR_STATUS;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO;
            subunit_id = BT_AVRCP_SUBUNIT_ID_UNIT_INFO;
            send_data[0] = BT_AVRCP_OP_UNIT_INFO;
            send_data[1] = 0xFF;
            send_data[2] = 0xFF;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF; 
            length = 6;
            
        break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
            ctype = BT_AVRCP_CR_STATUS;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO; 
            subunit_id = BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO;
            send_data[0] = BT_AVRCP_OP_SUBUNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0xFF;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF; 
            length = 6; 
            
        break;

        case BT_AVRCP_OP_PASS_THROUGH:
            ctype = BT_AVRCP_CR_CONTROL;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;            
            subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
            send_data[0] = BT_AVRCP_OP_PASS_THROUGH;

            if(key_down) /* down */
            {
                send_data[1] = op_id;
            }
            else /* up */
            {
                send_data[1] = op_id | 0x80;          
            }

            send_data[2] = 0;
            length = 3 ;
        break;

        case BT_AVRCP_OP_VENDOR:
        default:
            /*not support now*/
        return;
    }
        

    bt_avrcp_send_cmd_frame_req(MOD_MMI,
                                avrcp_chnl,
                                0, /* Not used */
                                ctype,
                                subunit_type,
                                subunit_id,
                                length,
                                &send_data[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_cmd_frame_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_cmd_frame_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_cmd_frame_cnf_struct *msg_p = (bt_avrcp_cmd_frame_cnf_struct*) msg;
    U16 cmd_type = 0;
    U8 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_cmd_frame_cnf_hdlr");
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    cmd_type = mmi_bt_avrcp_util_check_cmd_type(
                msg_p->c_type,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
                
#ifdef __MMI_AVRCP_CT_SUPPORT__
    switch (cmd_type)
    {
        case BT_AVRCP_OP_UNIT_INFO:
            if (g_mmi_avrcp_cmd_cnf_ptr != NULL)
            {
                g_mmi_avrcp_cmd_cnf_ptr(BT_AVRCP_OP_UNIT_INFO, 0, 0);
            }
            break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
            if (g_mmi_avrcp_cmd_cnf_ptr != NULL)
            {
                g_mmi_avrcp_cmd_cnf_ptr(BT_AVRCP_OP_SUBUNIT_INFO, 0, 0);
            }
            break;

        case BT_AVRCP_OP_PASS_THROUGH:
            if (g_mmi_avrcp_cmd_cnf_ptr != NULL)
            {
                g_mmi_avrcp_cmd_cnf_ptr(BT_AVRCP_OP_PASS_THROUGH,(U16) (msg_p->frame_data[1] & 0x7f), (BOOL) (msg_p->frame_data[1] & 0x80));
            }
            break;

        default:
            break;
    }
#endif /* __MMI_AVRCP_CT_SUPPORT__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_cmd_frame_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_cmd_frame_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_cmd_frame_ind_struct *msg_p = (bt_avrcp_cmd_frame_ind_struct*) msg;
    AVRCPCmdFuncPtr func_ptr;
    U16 cmd_type = 0;
    U8 send_len;
    U8 send_data[6];
    U8 type_result = BT_AVRCP_CR_NOT_IMPLEMENT;
    U8 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_bt_avrcp_cmd_frame_ind_hdlr, blocked=%d",g_mmi_avrcp_frm_blocked);
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);    
    avrcp_chnl = msg_p->chnl_num;
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    cmd_type = mmi_bt_avrcp_util_check_cmd_type(
                msg_p->c_type,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
                
    switch (cmd_type)
    {
        case BT_AVRCP_OP_UNIT_INFO:
        {
            send_data[0] = BT_AVRCP_OP_UNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0x48;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF;
            send_len = 6;

            bt_avrcp_send_cmd_frame_ind_res(
                MOD_MMI,
                avrcp_chnl,                
                msg_p->seq_id,
                msg_p->profile_id,
                BT_AVRCP_CR_STABLE,
                BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO,
                BT_AVRCP_SUBUNIT_ID_UNIT_INFO,
                send_len,
                send_data);
        }
        break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
        {
            send_data[0] = BT_AVRCP_OP_SUBUNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0x48;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF;
            send_len = 6;

            bt_avrcp_send_cmd_frame_ind_res(
                MOD_MMI,
                avrcp_chnl,                
                msg_p->seq_id,
                msg_p->profile_id,
                BT_AVRCP_CR_STABLE,
                BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO,
                BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO,
                send_len,
                send_data);
        }
        break;

        case BT_AVRCP_OP_PASS_THROUGH:
            
            type_result = MMI_AVRCP_CR_REJECT;
            
            if ((func_ptr = mmi_bt_avrcp_get_cmd_hdlr_func_ptr()) != NULL && !g_mmi_avrcp_frm_blocked)
            {
                U8 command = msg_p->frame_data[1] & 0x7f ;
                if( (msg_p->frame_data[1] & 0x80) == 0 )
                {
                    /*key pressed*/

                    /* receive another pressed cmd while previous */
                    /* pressed command has not released yet,      */
                    /* 1. auto relase previous command first      */
                    /* 2. pass current pressed cmd                */
                    if( (g_mmi_avrcp_last_pressed_cmd != 0xff) && (g_mmi_avrcp_last_pressed_cmd != command))
                    {
                        mmi_bt_avrcp_auto_release_cmd();
                        g_mmi_avrcp_last_pressed_cmd = command ;
                        g_mmi_avrcp_pressed_cmd_count = 1 ;
                        type_result = func_ptr( command, MMI_AVRCP_KEY_DOWN);
                        StartTimer(BT_AVRCP_AUTO_RELEASE_TIMER, 2000, (FuncPtr)mmi_bt_avrcp_auto_release_cmd);
                    }
                    /* receive the same pressed cmd, */
                    /* 1. restart timer              */
                    /* 2. pass longpress or repeat   */
                    else if(g_mmi_avrcp_last_pressed_cmd == command)
                    {
                        StartTimer(BT_AVRCP_AUTO_RELEASE_TIMER, 2000, (FuncPtr)mmi_bt_avrcp_auto_release_cmd);
                        g_mmi_avrcp_pressed_cmd_count ++ ;
                        if( g_mmi_avrcp_pressed_cmd_count > 2 )
                        {
                            type_result = func_ptr( command, MMI_AVRCP_KEY_REPEAT);
                        }
                        else
                        {
                            type_result = func_ptr( command, MMI_AVRCP_KEY_LONGPRESS);
                        }
                    }
                    /* first time receive pressed cmd */
                    else
                    {
                        g_mmi_avrcp_last_pressed_cmd = command ;
                        g_mmi_avrcp_pressed_cmd_count = 1 ;
                        type_result = func_ptr( command, MMI_AVRCP_KEY_DOWN);
                        StartTimer(BT_AVRCP_AUTO_RELEASE_TIMER, 2000, (FuncPtr)mmi_bt_avrcp_auto_release_cmd);
                    }
                }
                else if( g_mmi_avrcp_last_pressed_cmd == command )
                {
                    /*key released and matched key pressed command*/
                    /*reset previous pressed command to oxff*/
                    StopTimer(BT_AVRCP_AUTO_RELEASE_TIMER);
                    g_mmi_avrcp_last_pressed_cmd = 0xff ;
                    g_mmi_avrcp_pressed_cmd_count = 0 ;
                    type_result = func_ptr( command, MMI_AVRCP_KEY_UP);
                }
                else
                {
                    /*key released but key pressed command not matched*/
                    type_result = MMI_AVRCP_CR_REJECT ;
                }
            }

#ifndef __MMI_AVRCP_TEST__
            bt_avrcp_send_cmd_frame_ind_res(
                MOD_MMI,
                avrcp_chnl,                
                msg_p->seq_id,
                msg_p->profile_id,
                type_result,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
#endif
            break;

        default:
            // TODO: Error Trace Here.
            break;
    }
}

#define MMI_AVRCP_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_util_check_cmd_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c_type              [IN]        
 *  subunit_type        [IN]        
 *  subunit_id          [IN]        
 *  data_len            [IN]        
 *  frame_data          [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_bt_avrcp_util_check_cmd_type(U8 c_type, U8 subunit_type, U8 subunit_id, U16 data_len, U8 *frame_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_len > 0)
    {
        /* check if pass through command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_PASS_THROUGH) && (frame_data[0] == BT_AVRCP_OP_PASS_THROUGH))
        {
            return BT_AVRCP_OP_PASS_THROUGH;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_UNIT_INFO) && (frame_data[0] == BT_AVRCP_OP_UNIT_INFO))
        {
            return BT_AVRCP_OP_UNIT_INFO;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO) && (frame_data[0] == BT_AVRCP_OP_SUBUNIT_INFO))
        {
            return BT_AVRCP_OP_SUBUNIT_INFO;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_set_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_set_cmd_hdlr(AVRCPCmdFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Already registered */
    PRINT_INFORMATION("mmi_bt_avrcp_set_cmd_hdlr");
    for (i = 0 ; i < BT_AVRCP_MAX_CALLBACK_NUM ; i++)
    {
        if (g_mmi_avrcp_cmd_func_ptr_list[i] == callback_func)
        {
            return;
        }
    }
    
    ASSERT(g_mmi_avrcp_cmd_func_ptr_count < BT_AVRCP_MAX_CALLBACK_NUM);

    g_mmi_avrcp_cmd_func_ptr_list[g_mmi_avrcp_cmd_func_ptr_count++] = callback_func;
    PRINT_INFORMATION("mmi_bt_avrcp_set_cmd_hdlr: total %d",g_mmi_avrcp_cmd_func_ptr_count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_clear_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_clear_cmd_hdlr(AVRCPCmdFuncPtr callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("mmi_bt_avrcp_clear_cmd_hdlr: %d",g_mmi_avrcp_cmd_func_ptr_count);
    
    for (i = 0 ; i < BT_AVRCP_MAX_CALLBACK_NUM ; i++)
    {
        if (g_mmi_avrcp_cmd_func_ptr_list[i] == callback_func)
        {
            g_mmi_avrcp_cmd_func_ptr_list[i] = NULL;
            g_mmi_avrcp_cmd_func_ptr_count--;
            PRINT_INFORMATION("mmi_bt_avrcp_clear_cmd_hdlr 2: %d",g_mmi_avrcp_cmd_func_ptr_count);            
        }
    }
    
    ASSERT(g_mmi_avrcp_cmd_func_ptr_count >= 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_auto_release_cmd
 * DESCRIPTION
 *  automatically pass a released command to application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_auto_release_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AVRCPCmdFuncPtr func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("AVRCP: auto release1\n");

    if ((func_ptr = mmi_bt_avrcp_get_cmd_hdlr_func_ptr()) != NULL && g_mmi_avrcp_last_pressed_cmd != 0xff)
    {
        PRINT_INFORMATION("AVRCP: auto release2\n");
        func_ptr( g_mmi_avrcp_last_pressed_cmd, MMI_AVRCP_KEY_UP);
        g_mmi_avrcp_last_pressed_cmd = 0xff ;
        g_mmi_avrcp_pressed_cmd_count = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_frm_sync_calllback
 * DESCRIPTION
 *  for framework to callback if keypad / touch is triggered.
 * PARAMETERS
 *  BOOL    [IN] is keypad / touch blocked by target
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_frm_sync_calllback(BOOL is_blocked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    AVRCPCmdFuncPtr func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("AVRCP: framwork sync, is_blocked=%d",is_blocked);
    g_mmi_avrcp_frm_blocked = is_blocked;
    /* if blocked                                            */
    /* 1. cancel previous key down cmd                       */
    /* 2. pass key up cmd for previous longpress, repeat cmd */
    if(is_blocked && (func_ptr = mmi_bt_avrcp_get_cmd_hdlr_func_ptr()) != NULL && g_mmi_avrcp_last_pressed_cmd != 0xff)
    {
        if(g_mmi_avrcp_pressed_cmd_count == 1)
        {
            PRINT_INFORMATION("AVRCP: framwork sync, cmd canceled\n");
            func_ptr(g_mmi_avrcp_last_pressed_cmd, MMI_AVRCP_KEY_CANCELED);
        }
        else
        {
            PRINT_INFORMATION("AVRCP: framework sync, key up\n");
            func_ptr(g_mmi_avrcp_last_pressed_cmd, MMI_AVRCP_KEY_UP);
        }
        StopTimer(BT_AVRCP_AUTO_RELEASE_TIMER);
        g_mmi_avrcp_last_pressed_cmd = 0xff;
        g_mmi_avrcp_pressed_cmd_count = 0;
    }
    
}
#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_frm_sync_touch_calllback
 * DESCRIPTION
 *  for touch framework to callback to handle pen DOWN/UP/ABORT cases
 * PARAMETERS
 *  U16     [IN]    touch pen events
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_frm_sync_touch_calllback(U16 Touch_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("AVRCP: mmi_bt_avrcp_frm_sync_touch_calllback, Event : %d\n", Touch_event);

    switch(Touch_event)
    {
        case MMI_PEN_EVENT_DOWN:
            mmi_bt_avrcp_frm_sync_calllback(TRUE);
            break;
        case MMI_PEN_EVENT_UP:
        case MMI_PEN_EVENT_ABORT:
            mmi_bt_avrcp_frm_sync_calllback(FALSE);            
            break;
        default :
            break;
    }
    
}
#endif


#ifdef __MMI_AVRCP_DEBUG__

#include "ExtDeviceDefs.h"
#include "CommonScreens.h"
#include "SettingProfile.h"

#define MMI_BT_AVRCP_CMD_NUM    58

typedef struct
{
    U8 cmd_value;
    U16 str_id;
}mmi_bt_avrcp_cmd_struct;

static mmi_bt_avrcp_cmd_struct g_mmi_bt_avrcp_cmd[] =
{
BT_AVRCP_OP_UNIT_INFO           ,STR_BT_AVRCP_CMD_UNIT_COMMAND,
BT_AVRCP_OP_SUBUNIT_INFO        ,STR_BT_AVRCP_CMD_SUBUNIT_COMMAND,
MMI_AVRCP_POP_SELECT            ,STR_BT_AVRCP_CMD_SELECT,
MMI_AVRCP_POP_UP                ,STR_BT_AVRCP_CMD_UP,
MMI_AVRCP_POP_DOWN              ,STR_BT_AVRCP_CMD_DOWN,
MMI_AVRCP_POP_LEFT              ,STR_BT_AVRCP_CMD_LEFT,
MMI_AVRCP_POP_RIGHT             ,STR_BT_AVRCP_CMD_RIGHT,
MMI_AVRCP_POP_RIGHT_UP          ,STR_BT_AVRCP_CMD_RIGHT_UP,
MMI_AVRCP_POP_RIGHT_DOWN        ,STR_BT_AVRCP_CMD_RIGHT_DOWN,
MMI_AVRCP_POP_LEFT_UP           ,STR_BT_AVRCP_CMD_LEFT_UP,
MMI_AVRCP_POP_LEFT_DOWN         ,STR_BT_AVRCP_CMD_LEFT_DOWN,
MMI_AVRCP_POP_ROOT_MENU         ,STR_BT_AVRCP_CMD_ROOT_MENU,
MMI_AVRCP_POP_SETUP_MENU        ,STR_BT_AVRCP_CMD_SETUP,
MMI_AVRCP_POP_CONTENTS_MENU     ,STR_BT_AVRCP_CMD_CONTENTS,
MMI_AVRCP_POP_FAVORITE_MENU     ,STR_BT_AVRCP_CMD_FAVORITE,
MMI_AVRCP_POP_EXIT              ,STR_BT_AVRCP_CMD_EXIT,
MMI_AVRCP_POP_0                 ,STR_BT_AVRCP_CMD_0,
MMI_AVRCP_POP_1                 ,STR_BT_AVRCP_CMD_1,
MMI_AVRCP_POP_2                 ,STR_BT_AVRCP_CMD_2,
MMI_AVRCP_POP_3                 ,STR_BT_AVRCP_CMD_3,
MMI_AVRCP_POP_4                 ,STR_BT_AVRCP_CMD_4,
MMI_AVRCP_POP_5                 ,STR_BT_AVRCP_CMD_5,
MMI_AVRCP_POP_6                 ,STR_BT_AVRCP_CMD_6,
MMI_AVRCP_POP_7                 ,STR_BT_AVRCP_CMD_7,
MMI_AVRCP_POP_8                 ,STR_BT_AVRCP_CMD_8,
MMI_AVRCP_POP_9                 ,STR_BT_AVRCP_CMD_9,
MMI_AVRCP_POP_DOT               ,STR_BT_AVRCP_CMD_DOT,
MMI_AVRCP_POP_ENTER             ,STR_BT_AVRCP_CMD_ENTER,
MMI_AVRCP_POP_CLEAR             ,STR_BT_AVRCP_CMD_CLEAR,
MMI_AVRCP_POP_CHANNEL_UP        ,STR_BT_AVRCP_CMD_CHANNEL_UP,
MMI_AVRCP_POP_CHANNEL_DOWN      ,STR_BT_AVRCP_CMD_CHANNEL_DOWN,
MMI_AVRCP_POP_PREVIOUS_CHANNEL  ,STR_BT_AVRCP_CMD_PREVIOUS_CHANNEL,
MMI_AVRCP_POP_SOUND_SELECT      ,STR_BT_AVRCP_CMD_SOUND_SELECT,
MMI_AVRCP_POP_INPUT_SELECT      ,STR_BT_AVRCP_CMD_INPUT_SELECT,
MMI_AVRCP_POP_DISPLAY_INFO      ,STR_BT_AVRCP_CMD_DISPLAY_INFO,
MMI_AVRCP_POP_HELP              ,STR_BT_AVRCP_CMD_HELP,
MMI_AVRCP_POP_PAGE_UP           ,STR_BT_AVRCP_CMD_PAGE_UP,
MMI_AVRCP_POP_PAGE_DOWN         ,STR_BT_AVRCP_CMD_PAGE_DOWN,
MMI_AVRCP_POP_POWER             ,STR_BT_AVRCP_CMD_POWER,
MMI_AVRCP_POP_VOLUME_UP         ,STR_BT_AVRCP_CMD_VOLUME_UP,
MMI_AVRCP_POP_VOLUME_DOWN       ,STR_BT_AVRCP_CMD_VOLUME_DOWN,
MMI_AVRCP_POP_MUTE              ,STR_BT_AVRCP_CMD_MUTE,
MMI_AVRCP_POP_PLAY              ,STR_BT_AVRCP_CMD_PLAY,
MMI_AVRCP_POP_STOP              ,STR_BT_AVRCP_CMD_STOP,
MMI_AVRCP_POP_PAUSE             ,STR_BT_AVRCP_CMD_PAUSE,
MMI_AVRCP_POP_RECORD            ,STR_BT_AVRCP_CMD_RECORD,
MMI_AVRCP_POP_REWIND            ,STR_BT_AVRCP_CMD_REWIND,
MMI_AVRCP_POP_FAST_FORWARD      ,STR_BT_AVRCP_CMD_FAST_FORWARD,
MMI_AVRCP_POP_EJECT             ,STR_BT_AVRCP_CMD_EJECT,
MMI_AVRCP_POP_FORWARD           ,STR_BT_AVRCP_CMD_FORWARD,
MMI_AVRCP_POP_BACKWARD          ,STR_BT_AVRCP_CMD_BACKWARD,
MMI_AVRCP_POP_ANGLE             ,STR_BT_AVRCP_CMD_ANGLE,
MMI_AVRCP_POP_SUBPICTURE        ,STR_BT_AVRCP_CMD_SUBPICTURE,
MMI_AVRCP_POP_F1                ,STR_BT_AVRCP_CMD_F1,
MMI_AVRCP_POP_F2                ,STR_BT_AVRCP_CMD_F2,
MMI_AVRCP_POP_F3                ,STR_BT_AVRCP_CMD_F3,
MMI_AVRCP_POP_F4                ,STR_BT_AVRCP_CMD_F4,
MMI_AVRCP_POP_F5                ,STR_BT_AVRCP_CMD_F5
};

#ifdef __MMI_AVRCP_CT_SUPPORT__

static U16 g_mmi_bt_avrcp_ct_curr_cmd;

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_cmd_confirm
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_cmd_confirm(U16 op_code, U8 command_type, BOOL key_press)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 display_buffer[80];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op_code)
    {
        case BT_AVRCP_OP_UNIT_INFO:
            mmi_ucs2cpy((S8*)display_buffer, (S8*) GetString(STR_BT_AVRCP_CMD_UNIT_COMMAND));
            break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
            mmi_ucs2cpy((S8*)display_buffer, (S8*) GetString(STR_BT_AVRCP_CMD_SUBUNIT_COMMAND));
            break;

        case BT_AVRCP_OP_PASS_THROUGH:
            mmi_ucs2cpy((S8*)display_buffer, (S8*) GetString(mmi_bt_avrcp_util_get_cmd_string(command_type)));
            break;

        default:
            mmi_ucs2cpy((S8*)display_buffer, (S8*) GetString(STR_GLOBAL_ERROR));        
            break;
    }

    mmi_ucs2cat((S8*)display_buffer, (S8*)L"\n Response\0");
    DisplayPopup(display_buffer, IMG_GLOBAL_OK, 0, 1000, (U8) SUCCESS_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_send_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_send_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_bt_avrcp_ct_curr_cmd == 0)
    {
        mmi_bt_avrcp_cmd_frame_req(BT_AVRCP_CT, BT_AVRCP_OP_UNIT_INFO, 0, 0);
    }
    else if(g_mmi_bt_avrcp_ct_curr_cmd == 1)
    {
        mmi_bt_avrcp_cmd_frame_req(BT_AVRCP_CT, BT_AVRCP_OP_SUBUNIT_INFO, 0, 0);    
    }
    else
    {
        mmi_bt_avrcp_cmd_frame_req(BT_AVRCP_CT, BT_AVRCP_OP_PASS_THROUGH, g_mmi_bt_avrcp_cmd[g_mmi_bt_avrcp_ct_curr_cmd].cmd_value, 1); /*just send key down*/
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_main_list_highlight_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_main_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_avrcp_ct_curr_cmd = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_main_list_item
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_bt_avrcp_ct_main_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(g_mmi_bt_avrcp_cmd[item_index].str_id
));
    img_buff_p = NULL;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_ct_main
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_ct_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BT_AVCRP_CT_MAIN, NULL, mmi_bt_avrcp_ct_main, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BT_AVCRP_CT_MAIN);

    if (gui_buffer == NULL)
    {
        g_mmi_bt_avrcp_ct_curr_cmd = 0;
        g_mmi_avrcp_cmd_cnf_ptr = mmi_bt_avrcp_ct_cmd_confirm;
    }

    RegisterHighlightHandler(mmi_bt_avrcp_ct_main_list_highlight_hdlr);

    ShowCategory184Screen(
        STR_GLOBAL_OK, /* Title ID*/
        IMG_GLOBAL_OK, /* Title ICON */
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_BT_AVRCP_CMD_NUM,
        mmi_bt_avrcp_ct_main_list_item,
        NULL,
        g_mmi_bt_avrcp_ct_curr_cmd,
        gui_buffer);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bt_avrcp_ct_send_cmd, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left right arrow key handler */
    SetKeyHandler(mmi_bt_avrcp_ct_send_cmd, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /*#ifdef __MMI_AVRCP_CT_SUPPORT__ */
#endif /* #ifdef __MMI_AVRCP_DEBUG__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_util_get_cmd_string
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_bt_avrcp_util_get_cmd_string(U8 command)
{
#ifdef __MMI_AVRCP_DEBUG__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 2 ; i < MMI_BT_AVRCP_CMD_NUM ; i++)
    {
        if(command == g_mmi_bt_avrcp_cmd[i].cmd_value)
        {
            return g_mmi_bt_avrcp_cmd[i].str_id;
        }
    }
#endif

    return 0;
}

#ifdef __MMI_AVRCP_TEST__

U8  avrcp_test_counter = 0;
U8  avrcp_forward = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_different_down_cmd
 * DESCRIPTION
 *  Test when different down cmd comes before previous down cmd times up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_different_down_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;

    switch(avrcp_test_counter)
    {
        case 0 :
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_PLAY ;        /*play button down*/
            avrcp_test_counter ++ ;
        }
        break;
        case 1 :
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_STOP ;        /*stop button down*/
            avrcp_test_counter ++ ;
        }
        break;
        case 2 :
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_STOP | 0x80 ; /*stop button up*/
            avrcp_test_counter = 0 ;
        }
        break;
        default:
            avrcp_test_counter = 0 ;            
        break;     
    }

    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }

    if( avrcp_test_counter != 0 )
    {
        StartTimer(BT_AVRCP_TEST_TIMER, 1000, (FuncPtr)mmi_bt_avrcp_tst_different_down_cmd);
    }    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_same_down_cmd
 * DESCRIPTION
 *  Test when same down cmd comes before previous down cmd times up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_same_down_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;

    if(avrcp_test_counter <4)
    {
        if(avrcp_forward%2)
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_FORWARD;         /*stop button down*/
        }
        else
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_BACKWARD;         /*stop button down*/
        }
    }
    else
    {
        if(avrcp_forward%2)
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_FORWARD| 0x80;  /*stop button up*/
        }
        else
        {
            msg_p->frame_data[1] = MMI_AVRCP_POP_BACKWARD| 0x80;  /*stop button up*/
        }
        avrcp_forward ++ ;
    }
    
    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }

    if( avrcp_test_counter < 4 )
    {
        avrcp_test_counter ++ ;
        StartTimer(BT_AVRCP_TEST_TIMER, 1000, (FuncPtr)mmi_bt_avrcp_tst_same_down_cmd);
    }
    else
    {
        avrcp_test_counter = 0;
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_only_down_cmd
 * DESCRIPTION
 *  Test when only down cmd comes witout up cmd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_only_down_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;
    msg_p->frame_data[1] = MMI_AVRCP_POP_STOP; //MMI_AVRCP_POP_PLAY ;        /*play button down*/

    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_avrcp_tst_only_up_cmd
 * DESCRIPTION
 *  Test when only up cmd comes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_avrcp_tst_only_up_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	bt_avrcp_cmd_frame_ind_res_struct* msg_p = (bt_avrcp_cmd_frame_ind_res_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_res_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->chnl_num = BT_AVRCP_TG ;
    msg_p->profile_id = 0;
    msg_p->seq_id = 0;
    msg_p->c_type = 0;
    msg_p->data_len = 1; /*assign a value that's larger than 0*/
    msg_p->subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
    msg_p->subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;
    msg_p->frame_data[0] = BT_AVRCP_OP_PASS_THROUGH;
    msg_p->frame_data[1] = MMI_AVRCP_POP_PLAY | 0x80 ;        /*play button up*/

    /*send msg*/
    {
       ilm_struct *ilm_ptr = allocate_ilm(MOD_MMI);
       ilm_ptr->src_mod_id = MOD_MMI;
       ilm_ptr->dest_mod_id = MOD_MMI;
       ilm_ptr->sap_id = BT_AVRCP_SAP;
       ilm_ptr->msg_id = (msg_type)MSG_ID_BT_AVRCP_CMD_FRAME_IND;
       ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
       ilm_ptr->peer_buff_ptr = NULL;
    
       msg_send_ext_queue(ilm_ptr);
    }

}

#endif /*__MMI_AVRCP_TEST__*/
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)) */

