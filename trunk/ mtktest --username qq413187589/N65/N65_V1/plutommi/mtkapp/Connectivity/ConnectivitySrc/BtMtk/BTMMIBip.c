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
 * BTMMIBip.c
 *
 * Project:
 * --------
 *   BT BIP MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BIP service.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BIP_SUPPORT__)
 /*  Include: MMI header file */
#ifndef __MTK_TARGET__
#include "Windows.h"
#endif 
#include "MMI_include.h"
#include "Conversions.h"
#include "CommonScreens.h"      /* DisplayPopup */
#include "SettingProfile.h"     /* ERROR_TONE */
#include "FileManagerGProt.h"

 /* Trace Header Files */

 /* File Type Categories (sync with file manager) */
#include "FileMgr.h"
#include "xml_def.h"
#include "BTMMICm.h"
#include "BTMMICmGprots.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"

#include "Bluetooth_struct.h"

#include "BTMMIBipGprot.h"
#include "BTMMIBip.h"
#include "BTMMIBipScr.h"

#include "Bluetooth_bm_struct.h"
#include "ExtDeviceDefs.h"
#include "BTMMICustDef.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#if defined(__DRM_SUPPORT__)
#include "Drm_gprot.h"
#endif 

/* Applib MIME Header Files */
#include "app_mine.h"

#include "med_api.h"


#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIOppGprots.h"
#endif 

/* Trace Header Files */

extern pBOOL isInCall(void);

/* global variable */
bip_context_struct g_bip_context;

S8 mmi_bip_print_str[32];

#define MMI_BIP_MAX_FILTER_PATTERN_NUM  10

#define MMI_BIP_IMG_HANDLE_PREFIX  "8800000"

#define BIP_MEMSET(local_para_ptr)    do {                              \
    memset((kal_uint8*)(local_para_ptr) + sizeof(local_para_struct), 0, \
           (local_para_ptr)->msg_len - sizeof(local_para_struct));      \
} while(0)

#define MMI_BT_BIP_EXTERN_API


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_init
 * DESCRIPTION
 *  This function is to initialize BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_INIT);

    /* bip context init */
    mmi_bt_bip_cntx_init();

    /* bip work folder init */
    mmi_bt_bip_work_folder_init();

    /* bip responder setting menu handler */
    mmi_bt_bipr_menu_hdlr_init();

    /* set msg handler */

    /* initiator msg */
    SetProtocolEventHandler(mmi_bt_bipi_connect_cnf_hdlr, MSG_ID_BT_BIP_CONNECT_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_get_capabilities_cnf_hdlr, MSG_ID_BT_BIP_GET_CAPABILITIES_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_put_img_cnf_hdlr, MSG_ID_BT_BIP_PUT_IMG_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_put_thm_cnf_hdlr, MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_get_imglist_cnf_hdlr, MSG_ID_BT_BIP_GET_IMG_LIST_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_get_imgprop_cnf_hdlr, MSG_ID_BT_BIP_GET_IMG_PROP_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_get_img_cnf_hdlr, MSG_ID_BT_BIP_GET_IMG_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_get_thm_cnf_hdlr, MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_CNF);
    SetProtocolEventHandler(mmi_bt_bipi_abort_cnf_hdlr, MSG_ID_BT_BIP_ABORT_CNF);
    /* responder msg */
    SetProtocolEventHandler(mmi_bt_bipr_activate_cnf_hdlr, MSG_ID_BT_BIP_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bt_bipr_deactivate_cnf_hdlr, MSG_ID_BT_BIP_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bt_bipr_connect_ind_hdlr, MSG_ID_BT_BIP_CONNECT_IND);
    SetProtocolEventHandler(mmi_bt_bipr_get_capabilities_ind_hdlr, MSG_ID_BT_BIP_GET_CAPABILITIES_IND);
    SetProtocolEventHandler(mmi_bt_bipr_put_img_ind_hdlr, MSG_ID_BT_BIP_PUT_IMG_IND);
    SetProtocolEventHandler(mmi_bt_bipr_put_thm_ind_hdlr, MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_IND);
    SetProtocolEventHandler(mmi_bt_bipr_get_imglist_ind_hdlr, MSG_ID_BT_BIP_GET_IMG_LIST_IND);
    SetProtocolEventHandler(mmi_bt_bipr_get_imgprop_ind_hdlr, MSG_ID_BT_BIP_GET_IMG_PROP_IND);
    SetProtocolEventHandler(mmi_bt_bipr_get_img_ind_hdlr, MSG_ID_BT_BIP_GET_IMG_IND);
    SetProtocolEventHandler(mmi_bt_bipr_get_thm_ind_hdlr, MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_IND);
    SetProtocolEventHandler(mmi_bt_bipr_aborted_ind_hdlr, MSG_ID_BT_BIP_ABORT_IND);
    SetProtocolEventHandler(mmi_bt_bipr_complete_ind_hdlr, MSG_ID_BT_BIP_COMPLETE_IND);
    /* general msg */
    SetProtocolEventHandler(mmi_bt_bip_continue_ind_hdlr, MSG_ID_BT_BIP_CONTINUE_IND);
    SetProtocolEventHandler(mmi_bt_bip_disconnect_ind_hdlr, MSG_ID_BT_BIP_DISCONNECT_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_deinit
 * DESCRIPTION
 *  This function is to clear screens for bip in de-init bt procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_DEINIT);

    mmi_bt_bipi_push_deinit();

    mmi_bt_bipr_connection_terminated();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_activate
 * DESCRIPTION
 *  This function is to activate the BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 req_id;
    U8 Register_flag = 0;
    bt_bip_activate_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_BIPS_ACTIVATE);

    /* find all IDLE state connection and register them all */
    switch (g_bip_context.bip_responder_cntx.state)
    {
            /* unactivated connection */
        case MMI_BIPR_STATE_IDLE:

            req_id = BIP_CURR_REQ_ID;
            g_bip_context.bip_responder_cntx.req_id = req_id;
            /* switch state to registering */
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_REGISTERING);

            req = (bt_bip_activate_req_struct*) OslConstructDataPtr(sizeof(bt_bip_activate_req_struct));
            BIP_MEMSET(req);    /* memory init */
            req->req_id = req_id;
            req->bip_service_set = BT_BIP_IMAGE_PUSH | BT_BIP_IMAGE_PULL;

            /* Send activate_REQ primitive */
            mmi_bt_bip_send_msg(MSG_ID_BT_BIP_ACTIVATE_REQ, req);

            /* set flag to notify the unactivaed connection is found */
            if (Register_flag == 0)
            {
                Register_flag = 1;
            }
            break;
            /* other states */
        default:
            /* MMI_BIPS_LOG_STATE_ERR(i); */
            break;
    }

    /* without un-activated connections --> call activate cnf to CM */
    if (Register_flag == 0)
    {
        /* call activate cnf to CM */
        mmi_bth_activate_cnf_hdler((U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_deactivate
 * DESCRIPTION
 *  This function is to deactivate the BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 deregister_flag = 0;
    bt_sdpdb_deregister_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_BIPS_DEACTIVATE, g_bip_context.bip_responder_cntx.state);

    /* check all connections state */
    switch (g_bip_context.bip_responder_cntx.state)
    {
        case MMI_BIPR_STATE_REGISTERING:    /* activating -> deactivating */
        case MMI_BIPR_STATE_DEACTIVATING:   /* deactivating -> deactivating */
            ASSERT(0);
            break;
        case MMI_BIPR_STATE_IDLE:           /* unactivated */
            break;
        default:                            /* other activated states */
            /* send SDP deregister primitive */

            req = (bt_sdpdb_deregister_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_deregister_req_struct));
            BIP_MEMSET(req);    /* memory init */
            req->uuid = MMI_BTH_OBEX_IMAGING_RESPONDER_UUID;

            /* send req to bt */
            {
                ilm_struct *ilm_send;

                ilm_send = allocate_ilm(MOD_MMI);
                ilm_send->src_mod_id = MOD_MMI;
                ilm_send->dest_mod_id = MOD_BT;
                ilm_send->sap_id = BT_APP_SAP;
                ilm_send->msg_id = (U16) MSG_ID_BT_SDPDB_DEREGISTER_REQ;
                ilm_send->local_para_ptr = (local_para_struct*) req;
                ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

                msg_send_ext_queue(ilm_send);
            }

            /* only one sdp deregister req is enough */
            deregister_flag = 1;
            break;
    }
    /* all connections are in IDLE state -> call deactivate cnf to CM */

    if (deregister_flag == 0)
    {
        mmi_bth_deactivate_cnf_hdler((U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_disconnect_client
 * DESCRIPTION
 *  This function is to deactivate the BIP application
 * PARAMETERS
 *  bd_addr         [IN]        
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_disconnect_client(mmi_bth_bt_addr bd_addr, U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_BIPS_DISCONNECT_CLIENT,g_bip_context.bip_responder_cntx.state);

    /* search the selected connection index */
    if (g_bip_context.bip_responder_cntx.cm_conn_id == cm_conn_id)
    {
        switch (g_bip_context.bip_responder_cntx.state)
        {
            case MMI_BIPR_STATE_DISCONNECTING:  /* disconnecting -> disconnecting */
                ASSERT(0);
                return;
                /* connected states */
            case MMI_BIPR_STATE_ACTIVE:
            case MMI_BIPR_STATE_ACCEPTED:
            case MMI_BIPR_STATE_RECEIVING:
            case MMI_BIPR_STATE_SENDING:
                /* switch bipr state to disconnecting */
                MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_DISCONNECTING);
                /* then do the same thing as state deactivating */
                /* deactivate triggered disconnecting */
            case MMI_BIPR_STATE_DEACTIVATING:

                /* Construct Disconnect REQ to BIP adp */
                req = (bt_bip_disconnect_req_struct*) OslConstructDataPtr(sizeof(bt_bip_disconnect_req_struct));
                BIP_MEMSET(req);    /* memory init */
                req->req_id = BIP_CURR_REQ_ID;
                req->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;
                req->disconnect_tp_directly = MMI_TRUE;

                g_bip_context.bip_responder_cntx.req_id = req->req_id;
                g_bip_context.bip_responder_cntx.disconnect_from_cm = MMI_TRUE;

                /* Send Disconnect REQ to goep */
                mmi_bt_bip_send_msg(MSG_ID_BT_BIP_DISCONNECT_REQ, req);
                return;
                /* don't have to disconnect in states without connection */
            default:
                /* there is no connection exists -> call disconnect cnf to CM */
                mmi_bth_disconnect_cnf_hdler(
                    MMI_TRUE,
                    (g_bip_context.bip_responder_cntx.bipi_bt_device).lap,
                    (g_bip_context.bip_responder_cntx.bipi_bt_device).uap,
                    (g_bip_context.bip_responder_cntx.bipi_bt_device).nap,
                    (U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID,
                    (U32) cm_conn_id);
                return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_send_image_to_dev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name_with_path     [?]         [?]
 *  callback_f              [IN]        
 *  dst_bt_dev              [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
mmi_bt_bip_error_enum mmi_bt_bip_send_image_to_dev(
                        S8 *file_name_with_path,
                        mmi_bt_bip_send_img_callback callback_f,
                        mmi_bt_dev_addr *dst_bt_dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bth_bt_addr bd_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if the BIP initiator is sending or getting */
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_IMAGE_TO_DEV, g_bip_context.bip_initiator_cntx.state);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return MMI_BIP_ERR_INVALID_STATUS;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (g_bip_context.bip_initiator_cntx.state > MMI_BIPI_STATE_IDLE)
    {
        /* busy: sending or getting */
        DisplayPopup(
            (U8*) GetString(STR_BIP_DEV_BUSY),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);

        return MMI_BIP_ERR_BUSY;
    }

    g_bip_context.bip_initiator_cntx.cur_service = BT_BIP_IMAGE_PUSH;
    g_bip_context.bip_initiator_cntx.sent_size = 0;
    g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_IDLE;

    mmi_ucs2cpy(g_bip_context.bip_initiator_cntx.img_path_file, file_name_with_path);

    /* First, store the callback functionif any */
    /* In case send fail, clean up function will be able to callback */
    g_bip_context.bip_initiator_cntx.app_callback = callback_f;

    /* send connect req */
    bd_addr.lap = dst_bt_dev->lap;
    bd_addr.uap = dst_bt_dev->uap;
    bd_addr.nap = dst_bt_dev->nap;

    mmi_bt_bipi_connect_responder(bd_addr, BT_BIP_IMAGE_PUSH);

    return MMI_BIP_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_server_is_receiving
 * DESCRIPTION
 *  This function is to get current status of bip server.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS:(?)
 *  MMI_TRUE: is receiving(?)
 *  MMI_FALSE: not receiving(?)
 *****************************************************************************/
BOOL mmi_bip_server_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SERVER_IS_RECEIVING, g_bip_context.bip_responder_cntx.state);

    if (g_bip_context.bip_responder_cntx.state >= MMI_BIPR_STATE_ACCEPTED)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_connect_pull_responder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bd_addr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_connect_pull_responder(mmi_bth_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_CONNECT_PULL_RESPONDER, g_bip_context.bip_responder_cntx.state);
    
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        /* phone drive is exported, cann't use this app */
        mmi_usb_app_unavailable_popup(0);
        goto Connect_Error;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (g_bip_context.bip_initiator_cntx.state > MMI_BIPI_STATE_IDLE)
    {
        /* busy: sending or getting */
        DisplayPopup(
            (U8*) GetString(STR_BIP_DEV_BUSY),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);

        goto Connect_Error;
    }

    g_bip_context.bip_initiator_cntx.cur_service = BT_BIP_IMAGE_PULL;
    g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called = MMI_FALSE;

    mmi_bt_bipi_connect_responder(bd_addr, BT_BIP_IMAGE_PULL);

Connect_Error:
    /* notify CM */
    mmi_bth_connect_cnf_hdler(
        MMI_FALSE,
        bd_addr.lap,
        bd_addr.uap,
        bd_addr.nap,
        NULL,
        (U32) MMI_BTH_OBEX_IMAGING_UUID,
        (U32) 0);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_connect_responder
 * DESCRIPTION
 *  This function is to connect server for bip service
 * PARAMETERS
 *  bd_addr         [IN]        
 *  bip_service     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_connect_responder(mmi_bth_bt_addr bd_addr, U8 bip_service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 req_id;
    bt_bip_connect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIPI_CONNECT_SERVER);

    req_id = BIP_CURR_REQ_ID;

    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTING);
    g_bip_context.bip_initiator_cntx.bipr_bt_device.lap = bd_addr.lap;
    g_bip_context.bip_initiator_cntx.bipr_bt_device.uap = bd_addr.uap;
    g_bip_context.bip_initiator_cntx.bipr_bt_device.nap = bd_addr.nap;
    g_bip_context.bip_initiator_cntx.req_id = req_id;

    g_bip_context.bip_initiator_cntx.cur_service = bip_service;

    /* connect server */
    req = (bt_bip_connect_req_struct*) OslConstructDataPtr(sizeof(bt_bip_connect_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->bd_addr.lap = bd_addr.lap;
    req->bd_addr.uap = bd_addr.uap;
    req->bd_addr.nap = bd_addr.nap;

    req->req_id = req_id;
    req->bip_service = bip_service;

    /* send connect req to server */
    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_CONNECT_REQ, req);

    /* start timer */
	g_bip_context.bip_initiator_cntx.b_timeout = MMI_FALSE;
    StartTimer(BT_BIP_REQ_TIMER, MMI_BIP_CONNECT_TIMER_DUR, mmi_bt_bip_request_timeout_hdlr);

    if (bip_service == BT_BIP_IMAGE_PUSH)
    {
        mmi_bipi_entry_sending_scr();
    }
    else
    {
        mmi_bt_bipi_pull_entry_connect_scr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_set_shared_fodler
 * DESCRIPTION
 *  This function is to set the BIPS shared folder
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_set_shared_fodler(PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIPR_SET_FOLDER_SCR_CALLBACK);
    MMI_BIP_LOG_PATH(path);

    mmi_ucs2cpy((PS8) g_bip_context.bip_responder_cntx.shared_folder, path);

    WriteRecord(
        NVRAM_EF_BT_BIP_SETTING_LID,
        1,
        (void*)g_bip_context.bip_responder_cntx.shared_folder,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        &err);

}

#define MMI_BT_BIP_INIT_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_cntx_init
 * DESCRIPTION
 *  This function is to initialize BIP application context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_bip_context, 0, sizeof(g_bip_context));

    g_bip_context.bip_initiator_cntx.req_id = MMI_BIP_INVALID_REQ_ID;
    g_bip_context.bip_responder_cntx.req_id = MMI_BIP_INVALID_REQ_ID;

    g_bip_context.bip_initiator_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;
    g_bip_context.bip_responder_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;

	g_bip_context.bip_responder_cntx.cur_recv_img_num = 0;
	g_bip_context.bip_responder_cntx.total_recv_img_num = 0;

    memset(g_mmi_bt_bip_scr_cntx_p, 0, sizeof(mmi_bip_scr_cntx_struct));

    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_BT_BIP,
        STR_ID_BT_BIP,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        mmi_bt_bip_app_mem_stop_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_work_folder_init
 * DESCRIPTION
 *  This function is to initialize BIP work folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_work_folder_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;
    S16 err;
    S8 tmp_file[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    ReadRecord(
        NVRAM_EF_BT_BIP_SETTING_LID,
        1,
        (void*)g_bip_context.bip_responder_cntx.shared_folder,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        &err);

    MMI_BIP_LOG(MMI_BT_BIP_INIT_SHARED_FOLDER);
    MMI_BIP_LOG_PATH(g_bip_context.bip_responder_cntx.shared_folder);

	/* check if the shared folder exists */
    h = FS_Open((U16*) g_bip_context.bip_responder_cntx.shared_folder, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
    }
    else    /* Error handling */
    {
    	/* set the default shared folder */
	    kal_wsprintf((U16*) mmi_bip_print_str, (char*)"%c:\\", MMI_PUBLIC_DRV);
	    mmi_ucs2cat((S8*) mmi_bip_print_str, (S8*) BIP_RECV_FILEPATH);
			
	    mmi_ucs2cpy((S8*) g_bip_context.bip_responder_cntx.shared_folder, (S8*) mmi_bip_print_str);

	    h = FS_Open((U16*) mmi_bip_print_str, FS_READ_ONLY | FS_OPEN_DIR);
	    if ((h >= FS_NO_ERROR) || (h == FS_FILE_EXISTS))
	    {
	        /* Normal case ,Folder exist! */
	        FS_Close(h);
	    }
	    else    /* create it */
	    {
	        int ret = FS_CreateDir((U16*) mmi_bip_print_str);
	    }
    }

    h = FS_Open((U16*) BIP_FOLDER_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
        /* MMI_BIPI_RESET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((U16*) BIP_FOLDER_PATH);
        if (ret < 0)
        {
            /* MMI_BIPI_SET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
        }
    }

    h = FS_Open((U16*) BIP_RECV_THM_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
        /* MMI_BIPI_RESET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((U16*) BIP_RECV_THM_PATH);
        if (ret < 0)
        {
            kal_prompt_trace(MOD_MMI, "[BIP MMI] Create BIP_RECV_THM_PATH Failed!\n");
            /* MMI_BIPI_SET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
        }
    }

    h = FS_Open((U16*) BIP_GEN_THM_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
        /* MMI_BIPI_RESET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((U16*) BIP_GEN_THM_PATH);
        if (ret < 0)
        {
            kal_prompt_trace(MOD_MMI, "[BIP MMI] Create BIP_GEN_THM_PATH Failed!\n");
            /* MMI_BIPI_SET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
        }
    }

    h = FS_Open((U16*) BIP_TEMP_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
        /* MMI_BIPI_RESET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((U16*) BIP_TEMP_PATH);
        if (ret < 0)
        {
            kal_prompt_trace(MOD_MMI, "[BIP MMI] Create BIP_TEMP_PATH Failed!\n");
            /* MMI_BIPI_SET_FLAG(MMIBIP_MASK_FOLDER_ERR); */
        }
    }

    /* build default path */

    /* responder's img_list path */
    mmi_ucs2cpy((S8*) g_bip_context.bip_responder_cntx.img_list_path, (S8*) BIP_IMG_LIST_PATH_FILE);

    /* responder's current img_list path */
    mmi_ucs2cpy((S8*) g_bip_context.bip_responder_cntx.cur_img_list_path, (S8*) BIP_CUR_IMG_LIST_PATH_FILE);

    /* responder's img handle-name list file */
    mmi_ucs2cpy((S8*) g_bip_context.bip_responder_cntx.img_handle_name_path, (S8*) BIP_TMP_IMG_HDLE_NAME_FILE);

    /* pull initiator's recieved thumbnail path */
    mmi_ucs2cpy((S8*) g_bip_context.bip_initiator_cntx.thm_path, (S8*) BIP_RECV_THM_PATH);

    /* pull initiator's thm list file name */
    mmi_ucs2cpy((S8*) g_mmi_bt_bip_scr_cntx_p->img_browser_content_path, (S8*) BIP_TMP_IMG_THM_NAME_FILE);

    /* recieved image path */
    kal_wsprintf((U16*) mmi_bip_print_str, (char*)"%c:\\", MMI_PUBLIC_DRV);
    mmi_ucs2cat((S8*) mmi_bip_print_str, (S8*) BIP_RECV_FILEPATH);

    mmi_ucs2cpy((S8*) g_bip_context.bip_responder_cntx.recv_path, (S8*) mmi_bip_print_str);

    mmi_ucs2cpy((S8*) g_bip_context.bip_initiator_cntx.img_path, (S8*) mmi_bip_print_str);

    h = FS_Open((U16*) mmi_bip_print_str, FS_READ_ONLY | FS_OPEN_DIR);
    if ((h >= FS_NO_ERROR) || (h == FS_FILE_EXISTS))
    {
        /* BIP_DEBUG(kal_print("BIPC RECEIVED FOLDER INIT -- FS_OPEN NO ERROR\n");) */
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        int ret = FS_CreateDir((U16*) mmi_bip_print_str);

        /* MMI_BIP_LOG1(MMI_BT_BIP_BIPC_RECEIVED_FOLDER_INIT_CREATE, ret); */
        if (ret == FS_NO_ERROR)
        {
            /* BIP_DEBUG(kal_print("BIPC RECEIVED FOLDER INIT -- FS_OPEN NO ERROR\n");) */
        }
        else if (ret == FS_DISK_FULL)
        {
            /* BIP_DEBUG(kal_print("BIPC RECEIVED FOLDER INIT -- ERROR DISK FULL\n");) */
        }
        else if (ret == FS_ROOT_DIR_FULL)
        {
            /* BIP_DEBUG(kal_print("BIPC RECEIVED FOLDER INIT -- ERROR ROOT DIR FULL\n");) */
        }
        else
        {
        }
    }   /* End of error handling */

    /* delete tmp files that hasn't been deleted by accidence */

    /* 1. PUSH_responder */
    mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_responder_cntx.recv_path);
    mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PUSH_R_TMP_FILENAME);
    FS_Delete((U16*) tmp_file);

    /* 2. PULL_initiator */
    mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_initiator_cntx.img_path);
    mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);
    FS_Delete((U16*) tmp_file);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_send_msg
 * DESCRIPTION
 *  This function is to send msg to BT task
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_send_msg(U32 msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_MSG, msg_id);

    ilm_send = allocate_ilm(MOD_MMI);
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = MOD_BT;
    ilm_send->sap_id = BT_BIP_SAP;
    ilm_send->msg_id = (U16) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_send);
}

#define MMI_BT_BIPI_CNF_MSG_HDLR


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_BT_BIP_CONNECT_CNF msg
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_connect_cnf_struct *rsp = (bt_bip_connect_cnf_struct*) msg;
    U8 cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_CONNECT_CNF, rsp->cnf_code, g_bip_context.bip_initiator_cntx.state);
    ASSERT(g_bip_context.bip_initiator_cntx.req_id == rsp->req_id);

    StopTimer(BT_BIP_REQ_TIMER);

    g_bip_context.bip_initiator_cntx.req_id = MMI_BIP_INVALID_CONN_ID;
    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;

    /* Connection is established successfully  */
    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        switch (g_bip_context.bip_initiator_cntx.state)
        {
                /* connect cancel before connect rsp (race condition -> discard this msg) */
            case MMI_BIPI_STATE_DISCONNECTING:
                /* reset */
            case MMI_BIPI_STATE_IDLE:
                return;
            case MMI_BIPI_STATE_CONNECTING:
            {
                /* The connection is established */

                /* set bip context */
                g_bip_context.bip_initiator_cntx.cm_conn_id = rsp->cm_conn_id;
                
                MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);

                if (IS_BIPI_PUSHING)
                {
                    mmi_bth_connect_ind_hdler(
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                        NULL,
                        (U32) MMI_BTH_OBEX_IMAGING_UUID,
                        (U32) rsp->cm_conn_id);

                    /* get capability */
                    mmi_bt_bipi_send_get_capabilities_req(g_bip_context.bip_initiator_cntx.cm_conn_id);

                    mmi_bt_bip_start_blinking(MMI_BT_CLIENT_ROLE);
                }
                else if (IS_BIPI_PULLING)
                {
                    /* call connection cnf to CM and send first get image list packet */
                    mmi_bth_connect_cnf_hdler(
                        MMI_TRUE,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                        NULL,
                        (U32) MMI_BTH_OBEX_IMAGING_UUID,
                        (U32) rsp->cm_conn_id);

                    g_bip_context.bip_initiator_cntx.start_index = 0;
                    g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called = MMI_TRUE;
                    /* construct get image list req ilm */
                    mmi_bt_bipi_send_get_imglist_req();
                }

                return;
            }
                /* Connection establish fail */
            default:

                MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_IDLE);

                /* Notify MMI Screen */
                mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_REJECT_BY_SERVER);
                return;
        }
    }
    else
    {
        switch (g_bip_context.bip_initiator_cntx.state)
        {
            case MMI_BIPI_STATE_DISCONNECTING:
                if (IS_BIPI_PULLING)
                {
                    mmi_bth_connect_cnf_hdler(
                        MMI_FALSE,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                        NULL,
                        (U32) MMI_BTH_OBEX_IMAGING_UUID,
                        (U32) 0);
                    
                    g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called = MMI_TRUE;
                }

                MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_IDLE);

                if (IS_BIPI_PUSHING)
                {
                    if ((IS_BIPI_PUSH_SUCCESS) || (g_bip_context.bip_initiator_cntx.b_user_cancel))
                        cause = MMI_BIP_SUCCESS;
                    else
                        cause = MMI_BIP_ERR_CANCELED_BY_USER;
                    
                    g_bip_context.bip_initiator_cntx.b_user_cancel = MMI_FALSE;
                }
                else
                {
                    cause = MMI_BIP_SUCCESS;
                }
				if (g_bip_context.bip_initiator_cntx.b_timeout)
				{
                    cause = MMI_BIP_ERR_TIMEOUT;
		            if (IS_BIPI_PULLING)
		            {
		            	/* notify error */
						mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_TIMEOUT);
		            }			
				}
				
                mmi_bt_bipi_connection_terminated(cause);
                return;

            case MMI_BIPI_STATE_CONNECTING:
                if (IS_BIPI_PULLING)
                {
                    mmi_bth_connect_cnf_hdler(
                        MMI_FALSE,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                        g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                        NULL,
                        (U32) MMI_BTH_OBEX_IMAGING_UUID,
                        (U32) 0);

                    g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called = MMI_TRUE;
                }
                /* passkey screen del callback */
                mmi_bt_reject_passkey_ind();

                MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_IDLE);

                /* Notify MMI Screen */
                if (rsp->cnf_code == BT_BIP_SCO_REJECT)
                {
                    /* sco link support for MT6601 */
                    mmi_bt_popup_operation_not_allowed();
                }
                else if (IS_BIPI_PULLING)
                {
                    mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_REJECT_BY_SERVER);
                }
                break;

                /* reset */
            case MMI_BIPI_STATE_IDLE:
                return;
            default:
                MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_IDLE);
                mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_REJECT_BY_SERVER);
                break;
        }
        /* reset context */
        mmi_bt_bipi_connection_terminated(MMI_BIP_ERR_REJECT_BY_SERVER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_capabilities_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_capabilities_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_capabilities_cnf_struct *cnf = (bt_bip_get_capabilities_cnf_struct*) msg;
	bt_bip_img_format_enum cur_img_fmt;
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_CAPABILITIES_CNF, cnf->cnf_code,g_bip_context.bip_initiator_cntx.state);
    ASSERT(cnf->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_GETTING_CAPABILITIES)
    {
        /* if not in proper state, discard the cnf msg */
        return;
    }
    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;
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
#endif
    /* send PUSH image request */
    mmi_bt_bipi_send_push_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_put_img_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_put_img_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_cnf_struct *rsp = (bt_bip_put_img_cnf_struct*) msg;
    MMI_BOOL b_thm_success;
    S8 thm_path_file[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_PUT_IMG_CNF, rsp->cnf_code,g_bip_context.bip_initiator_cntx.state);

    ASSERT(rsp->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_SENDING)
    {
        /* send abort request because user already abort */
        g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_IDLE;
        return;
    }
    else if ((rsp->cnf_code != BT_BIP_CNF_SUCCESS) && rsp->cnf_code != BT_BIP_PARTIAL_CONTENT)
    {
        g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_IMG_FAILED;

        mmi_bt_bip_notify_user_error((U8)rsp->cnf_code);

        if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_DISCONNECTING)
        {
            mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
            mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
        }
        return;
    }

    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_IMG_SUCCESS;
        mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
	    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
    }
    else if (rsp->cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        /* the responder request to put thumbnail */

        /* generate thumbnail */
        b_thm_success = mmi_bt_bipi_generate_thumbnail(
                            (U16*) g_bip_context.bip_initiator_cntx.img_path_file,
                            (U16*) thm_path_file,
                            FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        if (b_thm_success)
        {
            bt_bip_put_linked_thumbnail_req_struct *req;

            req =
                (bt_bip_put_linked_thumbnail_req_struct*)
                OslConstructDataPtr(sizeof(bt_bip_put_linked_thumbnail_req_struct));
            BIP_MEMSET(req);

            req->cm_conn_id = rsp->cm_conn_id;
            strcpy((char*)req->img_handle, (char*)rsp->img_handle);
            mmi_ucs2cpy((S8*) req->img_path, thm_path_file);

            g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSHING_THM;
            g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_PUSH_THM;

            mmi_bt_bip_send_msg(MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_REQ, req);
        }
        else
        {
            g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_IMG_FAILED;
            mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
            mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_put_thm_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_put_thm_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_linked_thumbnail_cnf_struct *rsp = (bt_bip_put_linked_thumbnail_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_PUT_THM_CNF, rsp->cnf_code, g_bip_context.bip_initiator_cntx.state);

    ASSERT(rsp->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_SENDING)
    {
        /* send abort request because user already abort */
        return;
    }

    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_THM_SUCCESS;
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
    }
    else    /* failed */
    {
        g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_THM_FAILED;
        mmi_bt_bip_notify_user_error((U8)rsp->cnf_code);
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_imglist_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_imglist_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_list_cnf_struct *cnf = (bt_bip_get_img_list_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_IMGLIST_CNF, cnf->cnf_code, g_bip_context.bip_initiator_cntx.state);

    ASSERT(cnf->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_GETTING_IMGLIST)
    {
        /* send abort request because user already abort */
        return;
    }

    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);

    if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        memcpy(g_bip_context.bip_initiator_cntx.img_list_path, cnf->img_list_path, sizeof(cnf->img_list_path));
        MMI_BIP_LOG_PATH(cnf->img_list_path);

        MMI_BIP_LOG1(MMI_BT_BIP_GET_IMGLIST_NUM, cnf->img_count);

        /* img handle number in img list */
        g_bip_context.bip_initiator_cntx.img_handle_num_in_imglist = cnf->img_count;
        g_bip_context.bip_initiator_cntx.start_index += cnf->img_count - 1;

        mmi_bt_bipi_pull_scr_imglist_gotten();

        if (mmi_bt_bip_isForegroundScreen(SCR_BIP_CONNECTING))
        {
            g_bip_context.bip_initiator_cntx.b_user_disconnect = MMI_FALSE;
            /* display image list */
            mmi_bt_bipi_pull_entry_imglist_browser();
        }
        else
        {
            /* place the imglist browser into history */
            mmi_bt_bip_history_replace(SCR_BIP_CONNECTING, SCR_BIP_IMGLIST_BROWSER);
        }
    }
    else    /* failed */
    {
        mmi_bt_bip_notify_user_error((U8)cnf->cnf_code);
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_imgprop_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_imgprop_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_prop_cnf_struct *cnf = (bt_bip_get_img_prop_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_IMGPROP_CNF, cnf->cnf_code, g_bip_context.bip_initiator_cntx.state);
    ASSERT(cnf->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_GETTING_IMGPROP)
    {
        /* send abort request because user already abort */
        return;
    }

    if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        /* print info into string? */
        g_mmi_bt_bip_scr_cntx_p->img_encoding = cnf->native_img.encoding;
        g_mmi_bt_bip_scr_cntx_p->img_width = cnf->native_img.specified_pixel_width;
        g_mmi_bt_bip_scr_cntx_p->img_height = cnf->native_img.specified_pixel_height;
        g_mmi_bt_bip_scr_cntx_p->img_size = cnf->native_img.size;
        mmi_ucs2cpy((S8*) g_mmi_bt_bip_scr_cntx_p->img_name, (S8*) cnf->native_img.friendly_name);
    }

    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

	mmi_bt_bipi_get_imgprop_end((U8)cnf->cnf_code);

    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;

    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_get_imgfile_postfix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  postfix         [?]     
 *  tmp_file        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_get_imgfile_postfix(S8 *postfix, S8 *tmp_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_type = gdi_image_get_type_from_file(tmp_file);

    switch (img_type)
    {
        case GDI_IMAGE_TYPE_JPG_FILE:
            mmi_ucs2cpy(postfix, (S8*) L".jpg");
            break;
        case GDI_IMAGE_TYPE_PNG_FILE:
            mmi_ucs2cpy(postfix, (S8*) L".png");
            break;
        case GDI_IMAGE_TYPE_BMP_FILE:
            mmi_ucs2cpy(postfix, (S8*) L".bmp");
            break;
        case GDI_IMAGE_TYPE_WBMP_FILE:
            mmi_ucs2cpy(postfix, (S8*) L".wbmp");
            break;
        case GDI_IMAGE_TYPE_GIF_FILE:
            mmi_ucs2cpy(postfix, (S8*) L".gif");
            break;
        default:
            mmi_ucs2cpy(postfix, (S8*) L".jpg"); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_img_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_img_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_cnf_struct *cnf = (bt_bip_get_img_cnf_struct*) msg;
    S8 tmp_file[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_IMG_CNF, cnf->cnf_code, g_bip_context.bip_initiator_cntx.state);

    ASSERT(cnf->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_GETTING_IMG 
        && g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_GETTING_THM)
    {
        /* send abort request because user already abort */
        return;
    }

    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMG)
    {
        /* recieved file name */
        mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_initiator_cntx.img_path);
        mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);

        if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
        {
            /* rename received image name */
            S8 dst_img_name[BIP_MAX_FILE_NAME_LEN];
            S8 *p_postfix;

            /* construct received image name */
            mmi_asc_to_ucs2((S8*) dst_img_name, (S8*) g_bip_context.bip_initiator_cntx.img_handle);
            p_postfix = dst_img_name + (BT_BIP_IMG_HANDLE_LEN - 1) * 2;
            /* append postfix */
            mmi_bt_bip_get_imgfile_postfix(p_postfix, tmp_file);

            /* rename the tmp file name */
            mmi_bt_bip_rename_recved_file(
                (U16*) g_bip_context.bip_initiator_cntx.img_path,
                (U16*) dst_img_name,
                (U16*) BIP_PULL_I_TMP_FILENAME);
        }
        else
        {
            /* failed */

            /* delete tmp file */
            FS_Delete((U16*) tmp_file);
        }
        
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);        
        g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;

        /* notify screen: gotten a image  */
        mmi_bt_bipi_scr_get_img_cnf((U8)cnf->cnf_code);
    }
    else /* get thumbnail */
    {
        S8 dst_thm_name[BIP_MAX_FILE_NAME_LEN];

        if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
        {
            /* rename received thm name */
            mmi_bt_bip_rename_pulled_thm(dst_thm_name);
        }
        else
        {
            /* failed */
        
            /* recieved file name */
            mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_initiator_cntx.thm_path);
            mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);
        
            /* delete tmp file */
            FS_Delete((U16*) tmp_file);
        }
        
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);
        g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;
        
        /* notify screen */
        mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
        mmi_bt_bipi_scr_get_thm_cnf((U8) cnf->cnf_code, (U8*) g_bip_context.bip_initiator_cntx.thm_path, (U8*)dst_thm_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_thm_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_thm_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_linked_thumbnail_cnf_struct *cnf = (bt_bip_get_linked_thumbnail_cnf_struct*) msg;
    S8 dst_thm_name[BIP_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_THM_CNF, cnf->cnf_code, g_bip_context.bip_initiator_cntx.state);

    ASSERT(cnf->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_GETTING_THM)
    {
        /* send abort request because user already abort */
        return;
    }

    if (cnf->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        /* rename received thm name */
        mmi_bt_bip_rename_pulled_thm(dst_thm_name);
    }
    else
    {
        /* failed */
        S8 tmp_file[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];

        /* recieved file name */
        mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_initiator_cntx.thm_path);
        mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);

        /* delete tmp file */
        FS_Delete((U16*) tmp_file);
    }

    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;
    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);

    /* notify screen */
    mmi_bt_bipi_scr_get_thm_cnf((U8) cnf->cnf_code, (U8*) g_bip_context.bip_initiator_cntx.thm_path, (U8*)dst_thm_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_abort_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_abort_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_abort_cnf_struct *rsp = (bt_bip_abort_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_ABORT_CNF, rsp->cnf_code, g_bip_context.bip_initiator_cntx.state);

    StopTimer(BT_BIP_REQ_TIMER);

    if (IS_BIPI_PUSHING)
    {
        mmi_bt_bipi_push_abort_cnf_hdlr(rsp);
    }
    else if (IS_BIPI_PULLING)
    {
        mmi_bt_bipi_pull_abort_cnf_hdlr(rsp);
    }
    else
    {
        ASSERT(0);
    }
}

#define MMI_BT_BIPR_CNF_MSG_HDLR

/* BIP responder msg handler */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_activate_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_activate_cnf_struct *cnf = (bt_bip_activate_cnf_struct*) msg;
    bt_sdpdb_register_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_ACTIVATE_CNF,g_bip_context.bip_responder_cntx.state);

    if (g_bip_context.bip_responder_cntx.req_id == cnf->req_id)
    {
        g_bip_context.bip_responder_cntx.req_id = MMI_BIP_INVALID_CONN_ID;
        if (cnf->cnf_code != BT_BIP_CNF_SUCCESS)
        {
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_IDLE);
            return;
        }
        /* success */
        if (g_bip_context.bip_responder_cntx.state != MMI_BIPR_STATE_REGISTERING)
        {
            return;
        }

        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_ACTIVE);

        /* Send SDP Register primitive */
        req = (bt_sdpdb_register_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_register_req_struct));
        BIP_MEMSET(req);    /* memory init */
        req->uuid = (U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID;
        {
            ilm_struct *ilm_send;

            ilm_send = allocate_ilm(MOD_MMI);
            ilm_send->src_mod_id = MOD_MMI;
            ilm_send->dest_mod_id = MOD_BT;
            ilm_send->sap_id = BT_APP_SAP;
            ilm_send->msg_id = (U16) MSG_ID_BT_SDPDB_REGISTER_REQ;
            ilm_send->local_para_ptr = (local_para_struct*) req;
            ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

            msg_send_ext_queue(ilm_send);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_sdp_register_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_sdp_register_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_cnf_struct *cnf = (bt_sdpdb_register_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_SDP_REGISTER_CNF,cnf->result);

    /* SDP register success */
    if (cnf->result == 0x00)
    {
        /* call activate cnf to CM */
        mmi_bth_activate_cnf_hdler((U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID);
    }
    /* SDP register failed */
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_deactivate_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_deactivate_cnf_struct *rsp = (bt_bip_deactivate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_DEACTIVATE_CNF,g_bip_context.bip_responder_cntx.state);

    if (rsp->req_id == g_bip_context.bip_responder_cntx.req_id)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_IDLE);  /* don't have to reset context */
        g_bip_context.bip_responder_cntx.req_id = MMI_BIP_INVALID_CONN_ID;
        /* no connection is wating for deregister rsp -> deactivate cnf to CM */
        mmi_bth_deactivate_cnf_hdler((U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_sdp_deregister_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_sdp_deregister_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_cnf_struct *cnf = (bt_sdpdb_deregister_cnf_struct*) msg;
    bt_bip_deactivate_req_struct *req;
    mmi_bth_bt_addr bd_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_SDP_DEREGISTER_CNF,g_bip_context.bip_responder_cntx.state);
    if (cnf->result != 0x00)
    {
        /* SDP register Failed */
        ASSERT(0);
    }

    switch (g_bip_context.bip_responder_cntx.state)
    {
            /* can't deactivate twice */
        case MMI_BIPR_STATE_DEACTIVATING:
            ASSERT(0);
            break;
            /* do nothing (handle this case in disconnecting rsp) */
        case MMI_BIPR_STATE_DISCONNECTING:
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_DEACTIVATING);
            break;
            /* states with active connection */
        case MMI_BIPR_STATE_ACCEPTED:
        case MMI_BIPR_STATE_RECEIVING:
        case MMI_BIPR_STATE_SENDING:
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_DEACTIVATING);
            memset(&bd_addr, 0, sizeof(mmi_bth_bt_addr));
            mmi_bt_bipr_disconnect_client(bd_addr, g_bip_context.bip_responder_cntx.cm_conn_id);
            break;

        case MMI_BIPR_STATE_IDLE:
            return;

        case MMI_BIPR_STATE_ACTIVE:
            /* ok ? */
        default:
            MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_DEACTIVATING);
            req = (bt_bip_deactivate_req_struct*) OslConstructDataPtr(sizeof(bt_bip_deactivate_req_struct));
            BIP_MEMSET(req);    /* memory init */

            req->req_id = BIP_CURR_REQ_ID;
            g_bip_context.bip_responder_cntx.req_id = req->req_id;
            req->bip_service_set = BT_BIP_IMAGE_PUSH | BT_BIP_IMAGE_PULL;

            /* send req to bt */
            mmi_bt_bip_send_msg(MSG_ID_BT_BIP_DEACTIVATE_REQ, req);
            break;
    }
}

#define MMI_BT_BIPR_IND_MSG_HDLR


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_connect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_connect_ind_struct *ind = (bt_bip_connect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_CONNECT_IND, g_bip_context.bip_responder_cntx.state);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        /* phone drive is exported, cann't use this app */
        mmi_usb_app_unavailable_popup(0);

        /* send failed response */
        mmi_bt_bipr_send_connect_rsp(BT_BIP_CNF_FAILED);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (g_bip_context.bip_responder_cntx.state != MMI_BIPR_STATE_ACTIVE)
    {
        MMI_BIP_LOG(MMI_BT_BIP_CONNECT_IND_STATE_ERROR);
        mmi_bt_bipr_send_connect_rsp(BT_BIP_CNF_FAILED);
        return;
    }

    /* update BIPR context */
    memset((U8*) g_bip_context.bip_responder_cntx.bipi_dev_name, 0, BT_BIP_MAX_DEV_NAME_LEN);
    strcpy((S8*) g_bip_context.bip_responder_cntx.bipi_dev_name, (S8*) ind->dev_name);
    memset(&(g_bip_context.bip_responder_cntx.bipi_bt_device), 0, sizeof(bt_bip_bd_addr_struct));
    memcpy(&(g_bip_context.bip_responder_cntx.bipi_bt_device), &(ind->bd_addr), sizeof(bt_bip_bd_addr_struct));
    g_bip_context.bip_responder_cntx.cm_conn_id = ind->cm_conn_id;
    g_bip_context.bip_responder_cntx.disconnect_from_cm = MMI_FALSE;
    g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started = MMI_FALSE;

    MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_AUTHORIZING);
    if (!isInCall())
    {
        /* show confirm screen */
        mmi_bt_bipr_entry_recv_confirm_scr();
    }
    else
    {
        mmi_bt_bip_add_history_before_cm_marker(SCR_BIP_NOTY_CONN_REQ, mmi_bt_bipr_entry_recv_confirm_scr);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_get_capabilities_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_get_capabilities_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_CAPABILITIES_IND,g_bip_context.bip_responder_cntx.state);

    switch (g_bip_context.bip_responder_cntx.state)
    {
        case MMI_BIPR_STATE_ACCEPTED:
            break;

        default:
            /* do nothing */
            return;
    }

    mmi_bt_bipr_send_get_capabilities_rsp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_put_img_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_put_img_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_ind_struct *ind = (bt_bip_put_img_ind_struct*) msg;
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_PUT_IMG_IND,g_bip_context.bip_responder_cntx.state);

    ASSERT(g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id);

    if ((g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_DISCONNECTING) ||
        (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_DEACTIVATING))
    {
        /* Do Nothing */
        return;
    }

    if (g_bip_context.bip_responder_cntx.state != MMI_BIPR_STATE_ACCEPTED)
    {
        /* Wrong state */
        mmi_bt_bipr_send_put_img_rsp(BT_BIP_CNF_FAILED);
        return;
    }
    MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_RECEIVING);
    g_bip_context.bip_responder_cntx.recv_media = MMI_BIP_IMAGE;

    mmi_bt_bip_name_swapcpy((PU8) g_bip_context.bip_responder_cntx.recv_img_name, (PU8) ind->img_name);

    /* if the receive-folder not exist, create it now. */
    h = FS_Open((U16*) g_bip_context.bip_responder_cntx.recv_path, FS_READ_ONLY | FS_OPEN_DIR);
    if ((h >= FS_NO_ERROR) || (h == FS_FILE_EXISTS))
    {
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        int ret = FS_CreateDir((U16*) g_bip_context.bip_initiator_cntx.img_path);
    }

    mmi_bt_bipr_send_put_img_rsp(BT_BIP_CNF_SUCCESS);

    if (g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started)
    {
        MMI_BIP_LOG(MMI_BT_BIP_STOP_BLINKING_TIMER);
        /* if delay timer is set on, stop timer */
        StopTimer(BT_BIP_BLINKING_TIMER);
    }
    else
    {
        /* start blinking */
        mmi_bt_bip_start_blinking(MMI_BT_SERVER_ROLE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_put_thm_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_put_thm_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_linked_thumbnail_ind_struct *ind = (bt_bip_put_linked_thumbnail_ind_struct*) msg;
    bt_bip_put_linked_thumbnail_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_PUT_THM_IND,g_bip_context.bip_responder_cntx.state);

    ASSERT(g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id);

    if ((g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_DISCONNECTING) ||
        (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_DEACTIVATING))
    {
        /* Do Nothing */
        return;
    }

    if (g_bip_context.bip_responder_cntx.state != MMI_BIPR_STATE_ACCEPTED)
    {
        /* Wrong state */
        return;
    }
    MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_RECEIVING);
    g_bip_context.bip_responder_cntx.recv_media = MMI_BIP_THM;
    memcpy(g_bip_context.bip_responder_cntx.cur_img_handle, ind->img_handle, BT_BIP_IMG_HANDLE_LEN);

    rsp = (bt_bip_put_linked_thumbnail_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_put_img_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;
    rsp->cnf_code = BT_BIP_CNF_SUCCESS;

    /* img_path */
    mmi_ucs2cpy((S8*) rsp->img_path, g_bip_context.bip_responder_cntx.recv_path);
    mmi_ucs2cat((S8*) rsp->img_path, (S8*) BIP_PUSH_R_TMP_FILENAME);

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_RSP, rsp);


    if (g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started)
    {
        MMI_BIP_LOG(MMI_BT_BIP_STOP_BLINKING_TIMER);
        /* if delay timer is set on, stop timer */
        StopTimer(BT_BIP_BLINKING_TIMER);
    }
    else
    {
        /* start blinking */
        mmi_bt_bip_start_blinking(MMI_BT_SERVER_ROLE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_get_imglist_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_get_imglist_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_list_ind_struct *ind = (bt_bip_get_img_list_ind_struct*) msg;
    bt_bip_get_img_list_rsp_struct *rsp;
    U8 cnf_code = BT_BIP_CNF_FAILED;
    U32 total_img_count = 0;
    S32 img_count = 0;
    MMI_BOOL ret;
    int hFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_IMGLIST_IND,g_bip_context.bip_responder_cntx.state);

    ASSERT(g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id);

    switch (g_bip_context.bip_responder_cntx.state)
    {
        case MMI_BIPR_STATE_ACCEPTED:
            cnf_code = BT_BIP_CNF_SUCCESS;
            break;
        case MMI_BIPR_STATE_RECEIVING:
            cnf_code = BT_BIP_CNF_FAILED;
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            ASSERT(0);
    }

    /*
     * search shared_folder for image files, 
     * *  and write img_handle & img_name into a file.
     * *  build img_list, and write img_list into file
     */

    rsp = (bt_bip_get_img_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_list_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = ind->cm_conn_id;
    rsp->cnf_code = BT_BIP_CNF_FAILED;

    /* check if the shared folder exist */
    hFile = FS_Open((U16*)g_bip_context.bip_responder_cntx.shared_folder, FS_READ_ONLY);
    if (hFile < 0)
    {
        MMI_BIP_LOG1(MMI_BT_BIP_OPEN_SHARED_FOLDER_ERROR, hFile);
        cnf_code = BT_BIP_CNF_FAILED;
    }
    else
    {
        FS_Close(hFile);
    }
    
    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        if (ind->max_img_handle_number == 0 || ind->start_index == 0)
        {
            /* the first get: construct img list */
            ret = mmi_bt_bipr_construct_img_list(&total_img_count);
            if (ret == MMI_FALSE)
            {
                /* construction failed */
                total_img_count = 0;
            }
            g_bip_context.bip_responder_cntx.img_count = total_img_count;
        }

        if (ind->max_img_handle_number == 0)
        {
            /* Initiator want the total image number */
            img_count = g_bip_context.bip_responder_cntx.img_count;
        }
        else
        {
            /* Initiator want the image list, maybe partial */
            img_count = mmi_bt_bip_get_partial_imglist(ind->start_index, ind->max_img_handle_number);
        }

        if (img_count >= 0)
        {
            rsp->img_count = img_count;
            rsp->cnf_code = BT_BIP_CNF_SUCCESS;
            mmi_ucs2cpy((S8*) rsp->img_list_path, (S8*) g_bip_context.bip_responder_cntx.cur_img_list_path);

            MMI_BIP_LOG_PATH(rsp->img_list_path);
        }
    }

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_LIST_RSP, rsp);

    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING);
        mmi_bt_bip_start_blinking(MMI_BT_SERVER_ROLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_get_imgprop_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_get_imgprop_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_prop_ind_struct *ind = (bt_bip_get_img_prop_ind_struct*) msg;
    bt_bip_get_img_prop_rsp_struct *rsp;
    S8 img_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    U32 width, height;
    int ret, rt;
    U8 cnf_code = BT_BIP_CNF_FAILED;
    FS_HANDLE hFile;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_IMGPROP_IND,g_bip_context.bip_responder_cntx.state);

    ASSERT(g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id);

    switch (g_bip_context.bip_responder_cntx.state)
    {
        case MMI_BIPR_STATE_ACCEPTED:
            cnf_code = BT_BIP_CNF_SUCCESS;
            break;
        case MMI_BIPR_STATE_RECEIVING:
            cnf_code = BT_BIP_CNF_FAILED;
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            ASSERT(0);
    }

    rsp = (bt_bip_get_img_prop_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_prop_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;
    strcpy((char*)rsp->img_handle, (char*)ind->img_handle);
    rsp->cnf_code = BT_BIP_CNF_FAILED;

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        ret = mmi_bt_bipr_pull_get_filename_with_imghandle((S8*) ind->img_handle, (S8*) img_path);

        if (ret > 0)    /* find filename */
        {
            rsp->native_img.encoding = mmi_bt_bip_get_image_type((U16*) img_path);

            hFile = FS_Open((U16*) img_path, FS_READ_ONLY);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hFile);

            rt = FS_GetFileSize(hFile, &rsp->native_img.size);
            MMI_BIP_LOG2(MMI_BT_BIP_FS_GETFILESIZE_RETRUN, rt, rsp->native_img.size);

            rt = FS_Close(hFile);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_CLOSE_RETURN, rt);

            result = gdi_image_get_dimension_file(img_path, (S32*) & width, (S32*) & height);

            MMI_BIP_LOG_PATH(img_path);
            MMI_BIP_LOG3(MMI_BT_BIP_GDI_GET_DIMENSION, result,width,height);

            if (result == GDI_SUCCEED)
            {
                rsp->native_img.specified_pixel_width = (U16) width;
                rsp->native_img.specified_pixel_height = (U16) height;

                mmi_bt_bip_get_path_name((S8*) img_path, NULL, (S8*) rsp->native_img.friendly_name, BT_BIP_MAX_IMG_NAME_LEN);
                MMI_BIP_LOG(MMI_BT_BIP_FRIENDLY_NAME);
                MMI_BIP_LOG_PATH(rsp->native_img.friendly_name);

                rsp->cnf_code = BT_BIP_CNF_SUCCESS;
            }
            else
            {
                kal_prompt_trace(MOD_MMI, "[BIP MMI]gdi_image_get_dimension_file failed!");
                rsp->cnf_code = BT_BIP_CNF_FAILED;
            }
        }
    }

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_PROP_RSP, rsp);

    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING);
        if (g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started)
        {
            MMI_BIP_LOG(MMI_BT_BIP_STOP_BLINKING_TIMER);
            /* if delay timer is set on, stop timer */
            StopTimer(BT_BIP_BLINKING_TIMER);
        }
        else
        {
            /* start blinking */
            mmi_bt_bip_start_blinking(MMI_BT_SERVER_ROLE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_get_img_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_get_img_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_ind_struct *ind = (bt_bip_get_img_ind_struct*) msg;
    bt_bip_get_img_rsp_struct *rsp;
    U8 cnf_code = BT_BIP_CNF_FAILED;
    int ret, rt;
    int hFile;
    U8 img_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    MMI_BOOL b_thm_gotten = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_IMG_IND,g_bip_context.bip_responder_cntx.state);

    ASSERT(g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id);
    cnf_code = BT_BIP_CNF_FAILED;

    switch (g_bip_context.bip_responder_cntx.state)
    {
        case MMI_BIPR_STATE_ACCEPTED:
            rsp = (bt_bip_get_img_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_rsp_struct));
            BIP_MEMSET(rsp);    /* memory init */

            strcpy((char*)g_bip_context.bip_responder_cntx.cur_img_handle, (char*)ind->img_handle);

            ret = mmi_bt_bipr_pull_get_filename_with_imghandle((S8*) ind->img_handle, (S8*) rsp->img_path);

            if (ret > 0)    /* find filename */
            {
                /* check if this file exists */
                hFile = FS_Open((U16 *)rsp->img_path, FS_READ_ONLY);
                MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hFile);
                if (hFile < 0)
                {
                    /* not find */
					kal_prompt_trace(MOD_MMI, "[BT BIP] FS_Open return 0x%x", hFile);
                    break;
                }
                else
                {
                    rt = FS_Close(hFile);
                    MMI_BIP_LOG1(MMI_BT_BIP_FS_CLOSE_RETURN, rt);
                }
            
                MMI_BIP_LOG_PATH(rsp->img_path);

            #if defined(__DRM_SUPPORT__)
                /* drm check: if allow to forward out */
                if (!DRM_interdev_movable(0, (kal_wchar*) rsp->img_path))
                {
                    MMI_BIP_LOG(MMI_BT_BIP_DRM_FORBIDDEN);
                    cnf_code = BT_BIP_CNF_FAILED;
                }
                else
            #endif /* defined(__DRM_SUPPORT__) */ 
                    /* check if thm is requested */
                if (ind->img_descriptor.encoding == BT_BIP_IMG_TYPE_JPEG
                        && ind->img_descriptor.specified_pixel_width == BT_BIP_THM_WIDTH
                        && ind->img_descriptor.specified_pixel_height == BT_BIP_THM_HEIGHT)
                {
                    MMI_BIP_LOG(MMI_BT_BIP_THM_IS_REQUESTED);
                    /* thm is requested */
                    mmi_ucs2cpy((S8*) img_path, (S8*) rsp->img_path);

                    /* call api to get thumbnail of this image */
                    b_thm_gotten = mmi_bt_bipi_generate_thumbnail((U16*) img_path, (U16*) rsp->img_path, BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH);

                    if (b_thm_gotten)
                    {
                        cnf_code = BT_BIP_CNF_SUCCESS;
                    }
                }
                else
                {                    
                    /* native image is requested */
                    cnf_code = BT_BIP_CNF_SUCCESS;
                }
            }
            break;

        case MMI_BIPR_STATE_RECEIVING:
            rsp = (bt_bip_get_img_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_rsp_struct));
            BIP_MEMSET(rsp);    /* memory init */
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            ASSERT(0);
    }
    strcpy((char*)rsp->img_handle, (char*)ind->img_handle);
    rsp->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;
    rsp->cnf_code = cnf_code;

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_RSP, rsp);

    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING);
        if (g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started)
        {
            MMI_BIP_LOG(MMI_BT_BIP_STOP_BLINKING_TIMER);
            /* if delay timer is set on, stop timer */
            StopTimer(BT_BIP_BLINKING_TIMER);
        }
        else
        {
            /* start blinking */
            mmi_bt_bip_start_blinking(MMI_BT_SERVER_ROLE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_get_thm_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_get_thm_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_linked_thumbnail_ind_struct *ind = (bt_bip_get_linked_thumbnail_ind_struct*) msg;
    bt_bip_get_linked_thumbnail_rsp_struct *rsp;
    int ret;
    U8 cnf_code = BT_BIP_CNF_FAILED;
    U8 img_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    MMI_BOOL b_thm_gotten = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIPR_GET_THM_IND,g_bip_context.bip_responder_cntx.state);

    ASSERT(g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id);

    switch (g_bip_context.bip_responder_cntx.state)
    {
        case MMI_BIPR_STATE_ACCEPTED:
            cnf_code = BT_BIP_CNF_SUCCESS;
            break;
        case MMI_BIPR_STATE_RECEIVING:
            cnf_code = BT_BIP_CNF_FAILED;
            break;

        case MMI_BIPR_STATE_DEACTIVATING:
        case MMI_BIPR_STATE_DISCONNECTING:
            /* do nothing */
            return;

        default:
            ASSERT(0);
    }

    rsp =
        (bt_bip_get_linked_thumbnail_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_linked_thumbnail_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;
    strcpy((char*)rsp->img_handle, (char*)ind->img_handle);
    rsp->cnf_code = BT_BIP_CNF_FAILED;

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        ret = mmi_bt_bipr_pull_get_filename_with_imghandle((S8*) ind->img_handle, (S8*) img_path);

        if (ret > 0)    /* find filename */
        {
            /* call api to get thumbnail of this image */
            b_thm_gotten = mmi_bt_bipi_generate_thumbnail((U16*) img_path, (U16*) rsp->img_path, BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH);

            if (b_thm_gotten)
            {
                rsp->cnf_code = BT_BIP_CNF_SUCCESS;
            }
        }
    }
    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_RSP, rsp);

    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_SENDING);
        if (g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started)
        {
            MMI_BIP_LOG(MMI_BT_BIP_STOP_BLINKING_TIMER);
            /* if delay timer is set on, stop timer */
            StopTimer(BT_BIP_BLINKING_TIMER);
        }
        else
        {
            /* start blinking */
            mmi_bt_bip_start_blinking(MMI_BT_SERVER_ROLE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_aborted_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_aborted_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_abort_ind_struct *ind = (bt_bip_abort_ind_struct*) msg;
    S8 tmp_file[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_ABORT_IND,g_bip_context.bip_responder_cntx.state);

    if (ind->cm_conn_id == g_bip_context.bip_responder_cntx.cm_conn_id)
    {
        if (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_RECEIVING)
        {
            /* delete tmp file */
            mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_responder_cntx.recv_path);
            mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PUSH_R_TMP_FILENAME);
            FS_Delete((U16*) tmp_file);
        }

		if (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_RECEIVING 
			|| g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_SENDING)
		{
		    mmi_bt_bip_stop_blinking(MMI_BT_SERVER_ROLE);
		}

        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_ACCEPTED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_stop_blinking_timer_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_stop_blinking_timer_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_STOP_BLINKING_TIMER_HDLR);

    mmi_bt_bip_stop_blinking(MMI_BT_SERVER_ROLE);
    g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_rename_pushed_thm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_thm_name        [?]     
 *  img_name            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_rename_pushed_thm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* img_name = (S8*)g_bip_context.bip_responder_cntx.recv_img_name; 
    S8 dst_thm_name[BIP_MAX_FILE_NAME_LEN];
    S8 *tail;
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_RENAME_PUSHED_THM);
    MMI_BIP_LOG_PATH(img_name);

    /* construct pushed-in thm filename */

    if (mmi_ucs2strlen(img_name) > 0)
    {
        tail = img_name;
        while (*tail != '.' && tail > img_name)
            tail--;

        if (*tail == '.')
        {
            len = (tail - img_name) / 2;
            mmi_ucs2ncpy((S8*) dst_thm_name, (S8*) img_name, len);
            dst_thm_name[len] = 0;
            dst_thm_name[len + 1] = 0;
        }
        else
        {
            mmi_ucs2cpy((S8*) dst_thm_name, (S8*) img_name);
        }
    }
    else
    {
        mmi_asc_to_ucs2((S8*) dst_thm_name, (S8*) g_bip_context.bip_responder_cntx.cur_img_handle);
    }

    mmi_ucs2cat((S8*) dst_thm_name, (S8*) L"_thm.jpg");
    MMI_BIP_LOG(MMI_BT_BIP_RENAME_PUSHED_THM_DST_NAME);
    MMI_BIP_LOG_PATH(dst_thm_name);

    /* rename the filename */
    mmi_bt_bip_rename_recved_file(
        (U16*) g_bip_context.bip_responder_cntx.recv_path,
        (U16*) dst_thm_name,
        (U16*) BIP_PUSH_R_TMP_FILENAME);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_complete_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_complete_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_complete_ind_struct *ind = (bt_bip_complete_ind_struct*) msg;
    MMI_BOOL b_start_BTIcon_timer = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_COMPLETE_IND,g_bip_context.bip_responder_cntx.state);

    if (ind->cm_conn_id == g_bip_context.bip_responder_cntx.cm_conn_id)
    {
        if (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_RECEIVING
            || g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_SENDING)
        {
            b_start_BTIcon_timer = MMI_TRUE;
        }

        if (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_RECEIVING)
        {
            g_bip_context.bip_responder_cntx.cur_recv_img_num++;

            /* check name */
            if (g_bip_context.bip_responder_cntx.recv_media == MMI_BIP_IMAGE)
            {
                /* rename recieved image file */
                mmi_bt_bip_rename_recved_file(
                    (U16*) g_bip_context.bip_responder_cntx.recv_path,
                    (U16*) g_bip_context.bip_responder_cntx.recv_img_name,
                    (U16*) BIP_PUSH_R_TMP_FILENAME);
            }
            else
            {
                /* rename recieved thumbnail file */
                mmi_bt_bip_rename_pushed_thm();
            }
        }

        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_ACCEPTED);
    }

    if (b_start_BTIcon_timer)
    {
        MMI_BIP_LOG(MMI_BT_BIP_START_BLINKING_TIMER);
        StartTimer(BT_BIP_BLINKING_TIMER, MMI_BIP_ICON_DELAY_DUR, mmi_bt_bipr_stop_blinking_timer_hdler);
        g_bip_context.bip_responder_cntx.BTIcon_blinking_timer_started = MMI_TRUE;
    }
}

/* general msg handler */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_continue_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_continue_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_continue_ind_struct *ind = (bt_bip_continue_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bip_context.bip_initiator_cntx.cm_conn_id == ind->cm_conn_id)
    {
        if (IS_BIPI_PUSHING)
        {
            mmi_bt_bipi_push_continue_ind_hdlr(ind);
        }
        else if (IS_BIPI_PULLING)
        {
            mmi_bt_bipi_pull_continue_ind_hdlr(ind);
        }
    }
    else
    {
        if (g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id)
        {
            MMI_BIP_LOG(MMI_BT_BIP_RESPONDER_CONTINUE_IND);
            mmi_bt_bip_send_continue_rsp(ind->cm_conn_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_disconnect_ind_struct *ind = (bt_bip_disconnect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_DISCONNECT_IND);
    StopTimer(BT_BIP_REQ_TIMER);

    if (g_bip_context.bip_responder_cntx.cm_conn_id != MMI_BIP_INVALID_CONN_ID
        && g_bip_context.bip_responder_cntx.cm_conn_id == ind->cm_conn_id)
    {
        mmi_bt_bipr_disconnect_ind_hdlr();
    }
    else    /* if (g_bip_context.bip_initiator_cntx.cm_conn_id == ind->cm_conn_id) */
    {
        mmi_bt_bipi_disconnect_ind_hdlr();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_push_continue_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ind     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_push_continue_ind_hdlr(bt_bip_continue_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_BIP_LOG1(MMI_BT_BIP_PUSH_CONTINUE_IND, g_bip_context.bip_initiator_cntx.state);
    ASSERT(ind->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_ABORTING)
    {
        return;
    }
    else if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_SENDING &&
             g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_GETTING_CAPABILITIES)
    {
        /* send disconnect req */
        if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_DISCONNECTING)
            mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
        return;
    }

    /* update sent_size */
    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_SENDING 
        && g_bip_context.bip_initiator_cntx.push_flag == MMI_BIPI_PUSHING_IMG)
    {
        g_bip_context.bip_initiator_cntx.sent_size += ind->data_len;
    }

    /* send continue rsp */
    mmi_bt_bip_send_continue_rsp(ind->cm_conn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_continue_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ind     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_continue_ind_hdlr(bt_bip_continue_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_CONTINUE_IND, g_bip_context.bip_initiator_cntx.state);
    ASSERT(ind->cm_conn_id == g_bip_context.bip_initiator_cntx.cm_conn_id);

    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_GETTING_IMGLIST:
            break;

        case MMI_BIPI_STATE_GETTING_IMGPROP:
            break;
            
        case MMI_BIPI_STATE_GETTING_THM:
            break;

        case MMI_BIPI_STATE_GETTING_IMG:

            /* update gotten_size */
            g_bip_context.bip_initiator_cntx.cur_img_gotten_size += ind->data_len;
            if (g_bip_context.bip_initiator_cntx.cur_img_total_size == 0)
                g_bip_context.bip_initiator_cntx.cur_img_total_size = ind->obj_len;

            break;

        case MMI_BIPI_STATE_ABORTING:
            return;

        default:
            mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
            return;
    }

    /* send continue rsp */
    mmi_bt_bip_send_continue_rsp(ind->cm_conn_id);
}

#define MMI_BT_BIP_PUSH_INITIATOR_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_push_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_push_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_req_struct *req;
    bt_bip_img_info_struct desc;
    FS_HANDLE hFile;
    int ret;
    S32 result;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SEND_PUSH_REQ);

    hFile = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_path_file, FS_READ_ONLY);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hFile);

    memset(&desc, 0, sizeof(bt_bip_img_info_struct));
    desc.encoding = mmi_bt_bip_get_image_type((U16*) g_bip_context.bip_initiator_cntx.img_path_file);

    ret = FS_GetFileSize(hFile, &desc.size);
    MMI_BIP_LOG2(MMI_BT_BIP_FS_GETFILESIZE_RETRUN, ret, desc.size);
    
    ret = FS_Close(hFile);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_CLOSE_RETURN, ret);

    result = gdi_image_get_dimension_file(
                g_bip_context.bip_initiator_cntx.img_path_file,
                (S32*) & width,
                (S32*) & height);

	if (result != GDI_SUCCEED)
	    kal_prompt_trace(MOD_MMI, "[BIP MMI]gdi_image_get_dimension_file failed!");

    MMI_BIP_LOG3(MMI_BT_BIP_GDI_GET_DIMENSION, result,width,height);

    desc.specified_pixel_width = (U16) width;
    desc.specified_pixel_height = (U16) height;

    g_bip_context.bip_initiator_cntx.img_file_size = desc.size;
    g_bip_context.bip_initiator_cntx.sent_size = 0;
    g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_IDLE;

    /* construct push image req ilm */
    req = (bt_bip_put_img_req_struct*) OslConstructDataPtr(sizeof(bt_bip_put_img_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = g_bip_context.bip_initiator_cntx.cm_conn_id;

    req->img_descriptor = desc;
    req->img_size = desc.size;

    mmi_bt_bip_get_path_name(g_bip_context.bip_initiator_cntx.img_path_file, NULL, (S8*) req->img_name, BT_BIP_MAX_IMG_NAME_LEN);
    MMI_BIP_LOG_PATH(req->img_name);

    mmi_ucs2cpy((S8*) req->img_path, (S8*) g_bip_context.bip_initiator_cntx.img_path_file);

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_PUT_IMG_REQ, req);

    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_SENDING);
    g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSHING_IMG;
    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_PUSH_IMG;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_push_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_push_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PUSH_ABORT, g_bip_context.bip_initiator_cntx.state);

    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_SENDING ||
        g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_CAPABILITIES)
    {
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_ABORTING);
        mmi_bt_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);
    }
    else if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_CONNECTING)
    {
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
    }
    else
    {
        ASSERT(0);
    }

	mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
	
    SetDelScrnIDCallbackHandler(SCR_BIP_SENDING, NULL);
    DeleteScreenIfPresent(SCR_BIP_SENDING);

    mmi_bipi_entry_abort_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_fmgr_forward_to_bip_callback
 * DESCRIPTION
 *  This function is the call back used when the transfer gets completed
 * PARAMETERS
 *  p           [?]         [?]
 *  result      [IN]        
 *  buf_p       [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_fmgr_forward_to_bip_callback(void *p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_FMGR_PUSH_IMG_CALLBACK, result);
    if (p != NULL)
    {
        OslMfree(p);
        p = NULL;
    }

    if (result == MMI_BIP_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    SetDelScrnIDCallbackHandler(SCR_BIP_SENDING, NULL);
    DeleteScreenIfPresent(SCR_BIP_SENDING);

    StopTimer(FMGR_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_push_prog_percentage
 * DESCRIPTION
 *  This function is to retrieve the file put progress.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 ~ 100  The percentage of put process.
 *****************************************************************************/
U8 mmi_bipi_push_prog_percentage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Total length of a object */

    if (g_bip_context.bip_initiator_cntx.img_file_size == 0)
    {
        return 0;
    }
    return (U8) (((double)(g_bip_context.bip_initiator_cntx.sent_size) /
                  (double)g_bip_context.bip_initiator_cntx.img_file_size) * 100.0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_push_is_sending
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)
 *****************************************************************************/
BOOL mmi_bt_bipi_push_is_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PUSH_IS_SENDING,g_bip_context.bip_initiator_cntx.state);
    
    if ((MMI_BIPI_STATE_CONNECTING == g_bip_context.bip_initiator_cntx.state)
        || (MMI_BIPI_STATE_CONNECTED == g_bip_context.bip_initiator_cntx.state)
        || (MMI_BIPI_STATE_ABORTING== g_bip_context.bip_initiator_cntx.state)
        || (MMI_BIPI_STATE_DISCONNECTING== g_bip_context.bip_initiator_cntx.state))
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
 *  mmi_bt_bipi_push_is_aborting
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)
 *****************************************************************************/
BOOL mmi_bt_bipi_push_is_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PUSH_IS_ABORTING,g_bip_context.bip_initiator_cntx.state);
    
    if ((MMI_BIPI_STATE_ABORTING == g_bip_context.bip_initiator_cntx.state) ||
        (MMI_BIPI_STATE_DISCONNECTING == g_bip_context.bip_initiator_cntx.state))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_push_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_push_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PUSH_DEINIT, g_bip_context.bip_initiator_cntx.state);
    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_CONNECTING:
        case MMI_BIPI_STATE_CONNECTED:
        case MMI_BIPI_STATE_SENDING:
        case MMI_BIPI_STATE_ABORTING:
        case MMI_BIPI_STATE_DISCONNECTING:
            mmi_bt_bipi_connection_terminated(MMI_BIP_ERR_DISCONNECTED);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_get_recv_images_cnt
 * DESCRIPTION
 *  This function is to get received files count.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)
 *****************************************************************************/
U8 mmi_bt_bip_get_recv_images_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_GET_RECV_IMG_CNT,g_bip_context.bip_responder_cntx.total_recv_img_num);
    return g_bip_context.bip_responder_cntx.total_recv_img_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_set_recv_images_cnt
 * DESCRIPTION
 *  This function is to set received files count.
 *  
 *  PARAMETERS: void
 *  cnt     [IN]        
 *  RETURNS: received file counter.(?)(?)(?)
 *****************************************************************************/
void mmi_bt_bip_set_recv_images_cnt(U8 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SET_RECV_IMG_CNT,cnt);
    g_bip_context.bip_responder_cntx.total_recv_img_num = cnt;
}

#define MMI_BT_BIPI_SEND_REQUEST_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_disconnect_req(mmi_bip_disconnect_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_DISCONNECTING);
    mmi_bt_bip_send_disconnect_req(g_bip_context.bip_initiator_cntx.cm_conn_id, type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_send_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_send_disconnect_req(mmi_bip_disconnect_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIPR_STATE_TRANS(MMI_BIPI_STATE_DISCONNECTING);
    mmi_bt_bip_send_disconnect_req(g_bip_context.bip_responder_cntx.cm_conn_id, type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_send_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 *  type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_send_disconnect_req(U32 cm_conn_id, mmi_bip_disconnect_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_DISCONNECT_REQ, type);
    
    req = (bt_bip_disconnect_req_struct*) OslConstructDataPtr(sizeof(bt_bip_disconnect_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = cm_conn_id;

    if (type == MMI_BIP_TP_DISCONNECT)
    {
        req->disconnect_tp_directly = KAL_TRUE;
        /* TP-Disconnect need no timer */
    }
    else
    {
        req->disconnect_tp_directly = KAL_FALSE;

        StartTimer(BT_BIP_REQ_TIMER, MMI_BIP_DISCONNECT_TIMER_DUR, mmi_bt_bip_request_timeout_hdlr);
    }

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_DISCONNECT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_abort_req(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_abort_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_ABORT_REQ, g_bip_context.bip_initiator_cntx.state);

    req = (bt_bip_abort_req_struct*) OslConstructDataPtr(sizeof(bt_bip_abort_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = cm_conn_id;

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_ABORT_REQ, req);

    StartTimer(BT_BIP_REQ_TIMER, MMI_BIP_ABORT_TIMER_DUR, mmi_bt_bip_request_timeout_hdlr);

    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_get_capabilities_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_get_capabilities_req(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_capabilities_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_GETTING_CAPABILITIES);

    req = (bt_bip_get_capabilities_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_capabilities_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = cm_conn_id;

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_CAPABILITIES_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_push_abort_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_push_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PUSH_ABORT_CNF);

    mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_get_imglist_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_get_imglist_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_list_req_struct *req;
    bt_bip_img_info_struct desc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMGLIST_REQ,g_bip_context.bip_initiator_cntx.state);
    
    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        ASSERT(0);
    }

    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_GETTING_IMGLIST);

    req = (bt_bip_get_img_list_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_list_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = g_bip_context.bip_initiator_cntx.cm_conn_id;
#if 0
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
    req->start_index = 0;
    req->max_img_handle_number = BT_BIP_MAX_RETURNED_IMG_HANDLES;       // 0xFFFF; /* uint16 */
#endif /* 0 */ 

    memset(&desc, 0, sizeof(bt_bip_img_info_struct));
    desc.define_pixel_with_range = KAL_FALSE;

    req->img_list_descriptor = desc;

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_LIST_REQ, req);

    mmi_bt_bip_start_blinking(MMI_BT_CLIENT_ROLE);

    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_GET_IMGLIST;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_get_imgprop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_get_imgprop_req(S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_prop_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMGPROP_REQ,g_bip_context.bip_initiator_cntx.state);
    
    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        ASSERT(0);
    }

    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_GETTING_IMGPROP);

    req = (bt_bip_get_img_prop_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_prop_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = g_bip_context.bip_initiator_cntx.cm_conn_id;
    memcpy(req->img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_PROP_REQ, req);

    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_GET_IMGPROP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_get_img_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_get_img_req(S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMG_REQ,g_bip_context.bip_initiator_cntx.state);

    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        ASSERT(0);
    }
    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_GETTING_IMG);

    g_bip_context.bip_initiator_cntx.cur_img_gotten_size = 0;
    g_bip_context.bip_initiator_cntx.cur_img_total_size = 0;
    memcpy(g_bip_context.bip_initiator_cntx.img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_GET_IMG;

    req = (bt_bip_get_img_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = g_bip_context.bip_initiator_cntx.cm_conn_id;
    memcpy(req->img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
    mmi_ucs2cpy((S8*) req->img_path, g_bip_context.bip_initiator_cntx.img_path);
    mmi_ucs2cat((S8*) req->img_path, (S8*) BIP_PULL_I_TMP_FILENAME);
    
    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_send_get_imgthm_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_send_get_imgthm_req(S8 *img_handle)
{
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
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_img_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SEND_GET_IMGTHM_REQ,g_bip_context.bip_initiator_cntx.state);
    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_CONNECTED)
    {
        MMI_BIPI_LOG_STATE();
        ASSERT(0);
    }

    g_bip_context.bip_initiator_cntx.cur_img_gotten_size = 0;
    g_bip_context.bip_initiator_cntx.cur_img_total_size = 0;

    req = (bt_bip_get_img_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_img_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = g_bip_context.bip_initiator_cntx.cm_conn_id;
    memcpy(req->img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
    mmi_ucs2cpy((S8*) req->img_path, g_bip_context.bip_initiator_cntx.thm_path);
    mmi_ucs2cat((S8*) req->img_path, (S8*) BIP_PULL_I_TMP_FILENAME);
    
    /* image descriptor */
    req->img_descriptor.encoding = BT_BIP_IMG_TYPE_JPEG;
    req->img_descriptor.specified_pixel_width = BT_BIP_THM_WIDTH;
    req->img_descriptor.specified_pixel_height= BT_BIP_THM_HEIGHT;

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_IMG_REQ, req);

#endif

    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_GETTING_THM);
    memcpy(g_bip_context.bip_initiator_cntx.img_handle, img_handle, BT_BIP_IMG_HANDLE_LEN);
}

#define MMI_BT_BIPR_SEND_RESPONSE_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_send_connect_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_send_connect_rsp(U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_connect_rsp_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send response */
    res = (bt_bip_connect_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_connect_rsp_struct));
    BIP_MEMSET(res);    /* memory init */
    res->cnf_code = rsp_code;
    res->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;

    /* Send  primitive */
    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_CONNECT_RSP, res);

    if (rsp_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_ACCEPTED);
        /* call connect ind hdlr to notify CM */
        mmi_bth_connect_ind_hdler(
            g_bip_context.bip_responder_cntx.bipi_bt_device.lap,
            g_bip_context.bip_responder_cntx.bipi_bt_device.uap,
            g_bip_context.bip_responder_cntx.bipi_bt_device.nap,
            (U8*) g_bip_context.bip_responder_cntx.bipi_dev_name,
            (U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID,
            (U32) res->cm_conn_id);
    }
    else
    {
        MMI_BIPR_STATE_TRANS(MMI_BIPR_STATE_ACTIVE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_send_put_img_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cnf_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_send_put_img_rsp(U8 cnf_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_rsp_struct *rsp;
    U8 tmp_str[12];
    U8 *dst;
    int len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_bip_put_img_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_put_img_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;
    rsp->cnf_code = cnf_code;

    if (cnf_code == BT_BIP_CNF_SUCCESS || cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        /* img_path */
        mmi_ucs2cpy((S8*) rsp->img_path, g_bip_context.bip_responder_cntx.recv_path);

        /* append tmp filename */
        mmi_ucs2cat((S8*) rsp->img_path, (S8*) BIP_PUSH_R_TMP_FILENAME);

        /* img_handle */
        strcpy((S8*) g_bip_context.bip_responder_cntx.cur_img_handle, MMI_BIP_IMG_HANDLE_PREFIX);
        kal_sprintf((S8*) tmp_str, "%d", g_bip_context.bip_responder_cntx.cur_recv_img_num);
        len = strlen((S8*) tmp_str);
        dst =
            (U8*) (g_bip_context.bip_responder_cntx.cur_img_handle +
                    strlen(g_bip_context.bip_responder_cntx.cur_img_handle) - len);
        for (i = 0; i < len; i++)
        {
            *dst = tmp_str[i];
            dst++;
        }

        strcpy((S8*) rsp->img_handle, (S8*) g_bip_context.bip_responder_cntx.cur_img_handle);

    }

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_PUT_IMG_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_send_get_capabilities_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_send_get_capabilities_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_capabilities_rsp_struct *rsp;
    int i = 0;
    bt_bip_img_format_enum spt_img_formats[] = 
	{	BT_BIP_IMG_TYPE_JPEG,
        BT_BIP_IMG_TYPE_BMP,
        BT_BIP_IMG_TYPE_GIF,
        BT_BIP_IMG_TYPE_WBMP,
#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
        BT_BIP_IMG_TYPE_PNG,
#endif
		BT_BIP_IMG_TYPE_UNSUPPORT
    };
	U8 cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_bip_get_capabilities_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_capabilities_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = g_bip_context.bip_responder_cntx.cm_conn_id;

	cnt = sizeof(spt_img_formats) / sizeof(bt_bip_img_format_enum);
    for (i = 0; i < cnt; i++)
        rsp->supported_img_formats[i] = spt_img_formats[i];

		rsp->cnf_code = BT_BIP_CNF_SUCCESS;
    rsp->preferred_format = BT_BIP_IMG_TYPE_JPEG;
    rsp->created_time_filter = KAL_FALSE;
    rsp->modified_time_filter = KAL_FALSE;
    rsp->encoding_filter = KAL_FALSE;
    rsp->pixel_filter = KAL_FALSE;

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_GET_CAPABILITIES_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_send_continue_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_send_continue_rsp(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_continue_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_bip_continue_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_continue_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cnf_code = BT_BIP_CNF_SUCCESS;

    rsp->cm_conn_id = cm_conn_id;

    mmi_bt_bip_send_msg(MSG_ID_BT_BIP_CONTINUE_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_authorize_confirm_del_cb
 * DESCRIPTION
 *  This function is to reject the connect when confirm screen is deleted
 * PARAMETERS
 *  p       [?]     [?]     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_bipr_authorize_confirm_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_AUTH_CONFIRM_DEL_CB,g_bip_context.bip_responder_cntx.state);

    if (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_AUTHORIZING)
    {
        mmi_bt_bipr_send_connect_rsp(BT_BIP_CNF_FAILED);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_get_dev_name
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
void mmi_bt_bipr_get_dev_name(U8 *name_buf)
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
        (U8) ((mmi_chset_utf8_strlen((kal_uint8*) g_bip_context.bip_responder_cntx.bipi_dev_name) +
               1) * ENCODING_LENGTH);

    if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) name_buf,
                    MMI_BT_SCR_BD_NAME_LEN,
                    (kal_uint8*) g_bip_context.bip_responder_cntx.bipi_dev_name);
    }
    else
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) name_buf,
                    utf8_char_cnt,
                    (kal_uint8*) g_bip_context.bip_responder_cntx.bipi_dev_name);
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

#define MMI_BT_BIP_PULL_INITIATOR_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_disconnect_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cause = MMI_BIP_ERR_DISCONNECTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_INITIATOR_DISCONNECT_IND,g_bip_context.bip_initiator_cntx.state);
    
    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_IDLE:
            return;
        case MMI_BIPI_STATE_DISCONNECTING:
        case MMI_BIPI_STATE_ABORTING:
            MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_IDLE);  /* state -> idle */
            
            /* call CM */
            if (IS_BIPI_PULLING && !g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called)
            {
                mmi_bth_connect_cnf_hdler(
                    MMI_FALSE,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                    NULL,
                    (U32) MMI_BTH_OBEX_IMAGING_UUID,
                    (U32) 0);
                
                g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called = MMI_TRUE;            
            }
            else
            {
                mmi_bth_disconnect_ind_hdler(
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                    (U32) MMI_BTH_OBEX_IMAGING_UUID,
                    (U32) g_bip_context.bip_initiator_cntx.cm_conn_id);
            }

            if (IS_BIPI_PUSHING)
            {
                if ((IS_BIPI_PUSH_SUCCESS) || (g_bip_context.bip_initiator_cntx.b_user_cancel))
                    cause = MMI_BIP_SUCCESS;
				
				g_bip_context.bip_initiator_cntx.b_user_cancel = MMI_FALSE;

            }
            else
            {
                if (g_bip_context.bip_initiator_cntx.b_user_disconnect)
                    cause = MMI_BIP_SUCCESS;
            }
            /* reset context */
            mmi_bt_bipi_connection_terminated(cause);
            return;

            /* other connected states */

        case MMI_BIPI_STATE_CONNECTING:
        default:
            MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_IDLE);  /* state -> active */
            /* call CM */
            if (IS_BIPI_PULLING && !g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called)
            {
                mmi_bth_connect_cnf_hdler(
                    MMI_FALSE,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                    NULL,
                    (U32) MMI_BTH_OBEX_IMAGING_UUID,
                    (U32) 0);
                
                g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called = MMI_TRUE;            
            }
            else
            {
                mmi_bth_disconnect_ind_hdler(
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.lap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.uap,
                    g_bip_context.bip_initiator_cntx.bipr_bt_device.nap,
                    (U32) MMI_BTH_OBEX_IMAGING_UUID,
                    (U32) g_bip_context.bip_initiator_cntx.cm_conn_id);
            }

            /* notify mmi */
            if (IS_BIPI_PULLING)
            {
                mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_DISCONNECTED);
            }
            /* reset context */
            mmi_bt_bipi_connection_terminated(MMI_BIP_ERR_DISCONNECTED);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_simple_abort
 * DESCRIPTION
 *  This is common function to abort getting object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_simple_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_SIMPLE_ABORT,g_bip_context.bip_initiator_cntx.state);

    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMGLIST
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMG
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMGPROP
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_THM)
    {
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_ABORTING);
        mmi_bt_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);
	
		mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
    }
    else if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_CONNECTING)
    {
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
    }
    else
    {
        ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_abort_getting_images
 * DESCRIPTION
 *  This is common function to abort getting object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_abort_getting_images(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_ABORT_GETIMG,g_bip_context.bip_initiator_cntx.state);

    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMGLIST
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMG
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMGPROP
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_THM)
    {
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_ABORTING);
        mmi_bt_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);

		mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
    }
    else if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_CONNECTING)
    {
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
    }
    else if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_CONNECTED)
    {
	    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

        /* delete Aborting screen if present*/
        mmi_bt_bipi_pull_clear_abort_scr();

        /* notify screen */
        mmi_bt_bipi_pull_img_end(MMI_BIP_ERR_CANCELED_BY_USER);
    }
    else
    {
        ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_abort_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_ABORT_RSP msg
 * PARAMETERS
 *  rsp     [?]     [?]
 *  msg     [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_disconnect_req_struct *req;
    S8 tmp_file[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    MMI_BOOL b_continue_pull;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_PULL_ABORT_CNF, g_bip_context.bip_initiator_cntx.state,g_bip_context.bip_initiator_cntx.cur_oper);

    if (rsp->cm_conn_id != g_bip_context.bip_initiator_cntx.cm_conn_id)
        return;

    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_ABORTING:
            MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);
            
            /* notify screen */
            b_continue_pull = mmi_bt_bipi_pull_scr_aborted();
/*
            if (!b_continue_pull)
            {
            }
*/
            break;

        case MMI_BIPI_STATE_DISCONNECTING:
            /* construct disconnect req ilm */
            req = (bt_bip_disconnect_req_struct*) OslConstructDataPtr(sizeof(bt_bip_disconnect_req_struct));
            BIP_MEMSET(req);    /* memory init */
            req->cm_conn_id = g_bip_context.bip_initiator_cntx.cm_conn_id;

            /* send disconnect req and connect cnf fail to CM */
            mmi_bt_bip_send_msg(MSG_ID_BT_BIP_DISCONNECT_REQ, req);
            break;

        default:
            MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED);

            break;
    }

    /* delete tmp file */
    mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_initiator_cntx.img_path);
    mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PULL_I_TMP_FILENAME);
    FS_Delete((U16*) tmp_file);
        
    if (g_bip_context.bip_initiator_cntx.cur_oper == MMI_BIPI_OPER_GET_IMG)
    {
        /* notify screen */
        mmi_bt_bipi_pull_img_end(MMI_BIP_ERR_CANCELED_BY_USER);
    }
	else
	{
        mmi_bt_bipi_pull_clear_abort_scr();
	}
    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_is_recving
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)(?)
 *****************************************************************************/
BOOL mmi_bt_bipi_pull_is_recving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_RECVING,g_bip_context.bip_initiator_cntx.state);
    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_ABORTING:
        case MMI_BIPI_STATE_IDLE:
        case MMI_BIPI_STATE_CONNECTED:
        case MMI_BIPI_STATE_CONNECTING:
        case MMI_BIPI_STATE_DISCONNECTING:
            return MMI_FALSE;
        default:
            return MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_is_connecting
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)(?)
 *****************************************************************************/
BOOL mmi_bt_bipi_pull_is_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_CONNECTING,g_bip_context.bip_initiator_cntx.state);
    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_GETTING_IMGLIST:
        case MMI_BIPI_STATE_CONNECTING:
            return MMI_TRUE;
        default:
            return MMI_FALSE;
    }
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_is_canceling
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)(?)
 *****************************************************************************/
BOOL mmi_bt_bipi_pull_is_canceling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_CANCELING,g_bip_context.bip_initiator_cntx.state);
    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_DISCONNECTING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_is_aborting
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)(?)
 *****************************************************************************/
BOOL mmi_bt_bipi_pull_is_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_ABORTING,g_bip_context.bip_initiator_cntx.state);
    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_ABORTING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_is_getting_thm
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)(?)
 *****************************************************************************/
BOOL mmi_bt_bipi_pull_is_getting_thm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IS_GETTING_THM,g_bip_context.bip_initiator_cntx.state);
    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_THM)
    {
        kal_prompt_trace(MOD_MMI, "[BIP MMI]mmi_bt_bipi_pull_is_getting_thm. return TRUE!\n");
        return MMI_TRUE;
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "[BIP MMI]mmi_bt_bipi_pull_is_getting_thm. return FALSE!\n");
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_connect_cancel
 * DESCRIPTION
 *  This is common function to abort connecting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_connect_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_CONNECT_CANCEL,g_bip_context.bip_initiator_cntx.state);

#if 1
    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMGLIST
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMG
        || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMGPROP ||
        g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_THM)
    {
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_DISCONNECTING);
        mmi_bt_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);
    }
    else if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_CONNECTING
             || g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_CONNECTED)
    {
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
    }
    else
    {
    }
#else /* 1 */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 1 */ 

    mmi_bt_bipi_pull_entry_canceling();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_exit_image_browser
 * DESCRIPTION
 *  This function is to exit image browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_exit_image_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_EXIT_IMAGE_BROWSER, g_bip_context.bip_initiator_cntx.state);
    
    g_bip_context.bip_initiator_cntx.b_user_disconnect = MMI_TRUE;

    /* Disconnect the BIP connection */
    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_GETTING_IMGLIST:
        case MMI_BIPI_STATE_GETTING_IMG:
        case MMI_BIPI_STATE_GETTING_IMGPROP:
        case MMI_BIPI_STATE_GETTING_THM:
            mmi_bt_bipi_pull_entry_disconnecting();
            mmi_bt_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);
            MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_DISCONNECTING);
            break;

        case MMI_BIPI_STATE_CONNECTED:
            mmi_bt_bipi_pull_entry_disconnecting();
            mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
            break;

        default:
            break;
    }
}

 


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_exit_recving
 * DESCRIPTION
 *  This function is to exit receiving
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_exit_recving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_EXIT_RECVING, g_bip_context.bip_initiator_cntx.state);

    mmi_bt_bipi_pull_entry_disconnecting();

    if (g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_GETTING_IMG)
    {
        mmi_bt_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_DISCONNECTING);
    }
    else
    {
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_get_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bipi_pull_get_image(S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_IMAGE, g_bip_context.bip_initiator_cntx.state);

    g_bip_context.bip_initiator_cntx.cur_img_gotten_size = 0;

    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_CONNECTED:
            mmi_bt_bipi_send_get_img_req(img_handle);
            return MMI_TRUE;

        default:
            mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_INVALID_STATUS);
            return MMI_FALSE;
    }

}

#define MMI_BT_BIP_PULL_RESPONDER_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_disconnect_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_deactivate_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_RESPONDER_DISCONNECT_IND,g_bip_context.bip_responder_cntx.state);

    switch (g_bip_context.bip_responder_cntx.state)
    {
        case MMI_BIPR_STATE_DEACTIVATING:
            /* send DEACTIVATE_REQ to BT */
            req = (bt_bip_deactivate_req_struct*) OslConstructDataPtr(sizeof(bt_bip_deactivate_req_struct));
            BIP_MEMSET(req);
            req->req_id = BIP_CURR_REQ_ID;
            mmi_bt_bip_send_msg(MSG_ID_BT_BIP_DEACTIVATE_REQ, req);

            /* call disconnect ind to notify CM */
            if (g_bip_context.bip_responder_cntx.disconnect_from_cm)
            {
                /* call disconnect cnf to notify CM */
                mmi_bth_disconnect_cnf_hdler(
                    MMI_TRUE,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.lap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.uap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.nap,
                    (U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID,
                    (U32) g_bip_context.bip_responder_cntx.cm_conn_id);
            }
            else
            {
                /* call disconnect ind to notify CM */
                mmi_bth_disconnect_ind_hdler(
                    g_bip_context.bip_responder_cntx.bipi_bt_device.lap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.uap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.nap,
                    (U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID,
                    (U32) g_bip_context.bip_responder_cntx.cm_conn_id);
            }

            /* reset context */
            mmi_bt_bipr_connection_terminated();
            return;
            /* connected states */
        case MMI_BIPR_STATE_ACTIVE:
        case MMI_BIPR_STATE_ACCEPTED:
        case MMI_BIPR_STATE_SENDING:
        case MMI_BIPR_STATE_RECEIVING:
        case MMI_BIPR_STATE_DISCONNECTING:
        case MMI_BIPR_STATE_AUTHORIZING:

            if (g_bip_context.bip_responder_cntx.disconnect_from_cm)
            {
                /* call disconnect cnf to notify CM */
                mmi_bth_disconnect_cnf_hdler(
                    MMI_TRUE,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.lap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.uap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.nap,
                    (U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID,
                    (U32) g_bip_context.bip_responder_cntx.cm_conn_id);
            }
            else
            {
                /* call disconnect ind to notify CM */
                mmi_bth_disconnect_ind_hdler(
                    g_bip_context.bip_responder_cntx.bipi_bt_device.lap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.uap,
                    g_bip_context.bip_responder_cntx.bipi_bt_device.nap,
                    (U32) MMI_BTH_OBEX_IMAGING_RESPONDER_UUID,
                    (U32) g_bip_context.bip_responder_cntx.cm_conn_id);
            }

			if (g_bip_context.bip_responder_cntx.cur_recv_img_num > 0)
			{
	            mmi_bt_bip_scr_recv_img_ind();
				g_bip_context.bip_responder_cntx.total_recv_img_num += g_bip_context.bip_responder_cntx.cur_recv_img_num;
				g_bip_context.bip_responder_cntx.cur_recv_img_num = 0;
			}

            /* reset context */
            mmi_bt_bipr_connection_terminated();
            mmi_bt_bip_stop_blinking(MMI_BT_SERVER_ROLE);
            return;
            /* not connected yet */
        default:
            ASSERT(0);
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_pull_get_filename_with_imghandle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_handle      [?]     [?]
 *  file_name       [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_bt_bipr_pull_get_filename_with_imghandle(S8 *img_handle, S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    bip_img_handle_name_struct info;
    U32 read_len;
    int ret;
    kal_bool found_name = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_FILENAME_WITH_HANDLE, img_handle);
    
    hFile = FS_Open((U16*) g_bip_context.bip_responder_cntx.img_handle_name_path, FS_READ_ONLY);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hFile);
    
    if (hFile > 0)
    {
        ret = FS_Read(hFile, &info, sizeof(info), &read_len);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_READ_RETURN, ret);
        while (ret == FS_NO_ERROR && read_len > 0)
        {
            if (strcmp(info.img_handle, img_handle) == 0)
            {
                /* find it */
                mmi_ucs2cpy((S8*) file_name, g_bip_context.bip_responder_cntx.shared_folder);
                mmi_ucs2cat((S8*) file_name, (S8*) info.img_name);
                found_name = KAL_TRUE;
                MMI_BIP_LOG(MMI_BT_BIP_FIND_FILENAME);
                MMI_BIP_LOG_PATH(file_name);
                break;
            }
            ret = FS_Read(hFile, &info, sizeof(info), &read_len);
        }
        ret = FS_Close(hFile);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_CLOSE_RETURN, ret);
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "[BIP MMI]get_filename_with_imghandle: FS_Open img_handle_name_path error!\n");
    }

    if (!found_name)
    {
        kal_prompt_trace(MOD_MMI, "[BIP MMI] get_filename_with_imghandle FAILED: NOT FOUND!\n");
    }
    return found_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_construct_filter_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bip_filter_pattern      [?]         [?]
 *  max_cnt                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_bt_bip_construct_filter_pattern(FS_Pattern_Struct *bip_filter_pattern, U8 max_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_Pattern_Struct *p_pattern = bip_filter_pattern;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.jpg");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.jpeg");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.gif");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.bmp");
    p_pattern++;
    i++;
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.wbmp");
    p_pattern++;
    i++;
#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)	
    mmi_ucs2cpy((S8*) p_pattern->Pattern, (S8*) L"*.png");
    p_pattern++;
    i++;
#endif
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_construct_img_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_count       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_bt_bipr_construct_img_list(U32 *img_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_Pattern_Struct bip_filter_pattern[MMI_BIP_MAX_FILTER_PATTERN_NUM];
    U8 filter_count;
    FS_HANDLE hFile;
    U32 start_index = 0;
    S8 path[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    S8 file_name[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    FS_DOSDirEntry file_info;
    S32 file_count = 0;
    bt_bip_img_min_info_struct img_info;
    FS_HANDLE fs_imglist;
    bip_img_handle_name_struct handle_name_info;
    FS_HANDLE fs_handle_name;
    S8 tmp_str[BT_BIP_IMG_HANDLE_LEN];
    U32 write_len;
    S8 *dst, *src;
    int ret, wr_ret;
    int len, i;
    MMI_BOOL rst = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_CONSTRUCT_IMGLIST);
    
    filter_count = mmi_bt_bip_construct_filter_pattern(bip_filter_pattern, MMI_BIP_MAX_FILTER_PATTERN_NUM);

    mmi_ucs2cpy(path, g_bip_context.bip_responder_cntx.shared_folder);
    mmi_ucs2cat(path, (S8*) L"*.*");

    hFile = FS_FindFirstN(
                (U16*) path,
                bip_filter_pattern,
                filter_count,
                0,
                0,
                0,
                &file_info,
                (U16*) file_name,
                FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                start_index,
                FS_FIND_DEFAULT);

    MMI_BIP_LOG1(MMI_BT_BIP_FINDFIRST_RETURN,hFile);

    if (hFile >= 0)
    {
        fs_imglist = FS_Open((U16*) g_bip_context.bip_responder_cntx.img_list_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, fs_imglist);
        if (fs_imglist < 0)
        {
            kal_prompt_trace(MOD_MMI, "[BIP MMI]construct_img_list: FS_Open img_list_path error!\n");
            FS_FindClose(hFile);
            return MMI_FALSE;
        }

        fs_handle_name = FS_Open((U16*) g_bip_context.bip_responder_cntx.img_handle_name_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, fs_handle_name);
        if (fs_handle_name < 0)
        {
            kal_prompt_trace(MOD_MMI, "[BIP MMI]construct_img_list: FS_Open img_handle_name_path error!\n");
            FS_Close(fs_imglist);
            FS_FindClose(hFile);
            return MMI_FALSE;
        }

        do
        {
            file_count++;

            /* construct img-list info, and write it into file */
            memset(&img_info, 0, sizeof(img_info));
            strcpy((char*)img_info.img_handle, MMI_BIP_IMG_HANDLE_PREFIX);
            kal_sprintf(tmp_str, "%d", file_count);
            len = strlen(tmp_str);
            if (len > 0)
            {
                dst = (S8*) (img_info.img_handle + BT_BIP_IMG_HANDLE_LEN - len - 1);
                src = tmp_str;

                for (i = 0; i < len; i++)
                    *dst++ = *src++;
            }
            /*
             * img_info.created;
             * img_info.modified;
             */
            sprintf((char*)img_info.created,
                    "%04d%02d%02dT%02d%02d%02dZ",
                    file_info.CreateDateTime.Year1980 + 1980,
                    file_info.CreateDateTime.Month,
                    file_info.CreateDateTime.Day,
                    file_info.CreateDateTime.Hour,
                    file_info.CreateDateTime.Minute,
                    file_info.CreateDateTime.Second2);

            sprintf((char*)img_info.modified,
                    "%04d%02d%02dT%02d%02d%02dZ",
                    file_info.DateTime.Year1980 + 1980,
                    file_info.DateTime.Month,
                    file_info.DateTime.Day,
                    file_info.DateTime.Hour,
                    file_info.DateTime.Minute,
                    file_info.DateTime.Second2);


            wr_ret = FS_Write(fs_imglist, &img_info, sizeof(img_info), &write_len);
			if (wr_ret != FS_NO_ERROR)
			{
			    MMI_BIP_LOG1(MMI_BT_BIP_FS_WRITE_RETURN, ret);
				goto Error;
			}

			MMI_BIP_LOG_PATH(file_name);
            /* construct img handle-name info, and write it into file */
            strcpy((char*)handle_name_info.img_handle, (char*)img_info.img_handle);
            mmi_ucs2cpy((S8*) handle_name_info.img_name, (S8*) file_name);
            wr_ret = FS_Write(fs_handle_name, &handle_name_info, sizeof(handle_name_info), &write_len);
			if (wr_ret != FS_NO_ERROR)
			{
			    MMI_BIP_LOG1(MMI_BT_BIP_FS_WRITE_RETURN, ret);
				goto Error;
			}

            /* find the next image file */
            ret = FS_FindNextN(
                    hFile,
                    bip_filter_pattern,
                    filter_count,
                    0,
                    &file_info,
                    (U16*) file_name,
                    FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                    FS_FIND_DEFAULT);
        } while (ret == FS_NO_ERROR);

        FS_Close(fs_handle_name);
        FS_Close(fs_imglist);
        FS_FindClose(hFile);
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "[BIP MMI]construct_img_list: FS_FindFirstN FAILED!\n");
		/* delete the previous img list: maybe it contains old value. */
		ret = FS_Delete((U16*) g_bip_context.bip_responder_cntx.img_list_path);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_DELETE_RETURN, ret);		
    }

    MMI_BIP_LOG1(MMI_BT_BIP_CONSTRUCT_IMGLIST_COUNT, file_count);

    *img_count = file_count;
    if (file_count >= 0)
        rst = MMI_TRUE;
    return rst;

Error:
    FS_Close(fs_handle_name);
    FS_Close(fs_imglist);
    FS_FindClose(hFile);

	FS_Delete((U16*) g_bip_context.bip_responder_cntx.img_list_path);
	FS_Delete((U16*) g_bip_context.bip_responder_cntx.img_handle_name_path);

    *img_count = 0;
	return MMI_FALSE;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_get_partial_imglist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [in] start index
 *  max_num           [in] max img handle number to return
 * RETURNS
 *  the real img handle number gotten 
 *****************************************************************************/
S16 mmi_bt_bip_get_partial_imglist(U16 start_index, U16 max_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hDstFile;
    FS_HANDLE hImglist;
    bt_bip_img_min_info_struct img_info;
    U32 offset;    
    U32 len;
    int ret, rt;
    S16 read_cnt = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG2(MMI_BT_BIP_GET_PARTIAL_IMGLIST, start_index, max_num);

    /* open the total img_list file */
    hImglist = FS_Open((U16*) g_bip_context.bip_responder_cntx.img_list_path, FS_READ_ONLY);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hImglist);
    
    if (hImglist < 0)
    {
        kal_prompt_trace(MOD_MMI, "[BIP MMI]FS_Open(img_list_path): FS_Open img_list_path error!\n");
        return 0;
    }
    /* open the cur_img_list file */
    hDstFile = FS_Open((U16*) g_bip_context.bip_responder_cntx.cur_img_list_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hDstFile);
    if (hDstFile < 0)
    {
        kal_prompt_trace(MOD_MMI, "[BIP MMI]FS_Open(cur_img_list_path): FS_Open img_list_path error!\n");
        FS_Close(hImglist);
        return 0;
    }

    /* seek the img list file to proper offset */
    offset = start_index * sizeof(bt_bip_img_min_info_struct);
    ret = FS_Seek(hImglist, offset, FS_FILE_BEGIN);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);

    /* read out the source */
    ret = FS_Read(hImglist, &img_info, sizeof(bt_bip_img_min_info_struct), &len);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_READ_RETURN, ret);
    while (ret == FS_NO_ERROR && read_cnt < max_num && len > 0)
    {
        /* write into the dst file */
        rt = FS_Write(hDstFile, &img_info, sizeof(bt_bip_img_min_info_struct), &len);

		if (rt != FS_NO_ERROR)
		{
		    MMI_BIP_LOG1(MMI_BT_BIP_FS_WRITE_RETURN, ret);
			goto Ret_err;
		}
        //kal_prompt_trace(MOD_MMI,"[BIP MMI]FS_Write(cur_img_list_path) return 0x%x, len=%d\n", rt, len);    
        read_cnt++;

        /* read out the next source */
        ret = FS_Read(hImglist, &img_info, sizeof(bt_bip_img_min_info_struct), &len);
    }
    
    FS_Close(hDstFile);
    FS_Close(hImglist);

    return read_cnt;
	
Ret_err:

    FS_Close(hDstFile);
    FS_Close(hImglist);
    FS_Delete((U16*) g_bip_context.bip_responder_cntx.cur_img_list_path);

    return -1;
	
}

#define MMI_BT_BIP_CONNECTION_TERMINATED_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_connection_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_connection_terminated(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_I_CONNECTION_TERMINATED, g_bip_context.bip_initiator_cntx.state);

    /* stop blinking */
    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

    mmi_bt_bipi_clear_scrs(MMI_BIP_CLEAR_SCR_ON_DISCONNECT);

    if (IS_BIPI_PUSHING)
    {
        if (g_bip_context.bip_initiator_cntx.app_callback)
        {
            g_bip_context.bip_initiator_cntx.app_callback(NULL, cause);
            g_bip_context.bip_initiator_cntx.app_callback = NULL;
        }
    }
    else if (IS_BIPI_PULLING)
    {
        /* mmi_bt_bipi_notify_recv_err(cause); */

        /* delete tmp file */
        FS_Delete((U16*) g_bip_context.bip_initiator_cntx.img_list_path);
        
        /* delete received all thumbnail in recv_thm folder */
        FS_XDelete((U16*)g_bip_context.bip_initiator_cntx.thm_path, FS_FILE_TYPE, NULL, 0);

        mmi_bt_bipi_pull_scr_connect_terminated();
    }

    /* reset members */
    g_bip_context.bip_initiator_cntx.state = MMI_BIPI_STATE_IDLE;
    g_bip_context.bip_initiator_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;
    g_bip_context.bip_initiator_cntx.req_id = MMI_BIP_INVALID_REQ_ID;

    g_bip_context.bip_initiator_cntx.b_CmConnectCnf_called = MMI_FALSE;
    g_bip_context.bip_initiator_cntx.b_user_disconnect = MMI_FALSE;
    g_bip_context.bip_initiator_cntx.cur_oper = MMI_BIPI_OPER_IDLE;
    g_bip_context.bip_initiator_cntx.push_flag = MMI_BIPI_PUSH_IDLE;
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_connection_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_file[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_R_CONNECTION_TERMINATED, g_bip_context.bip_responder_cntx.state);

    //if (g_bip_context.bip_responder_cntx.state != MMI_BIPR_STATE_ACCEPTED)
    {
        if (g_bip_context.bip_responder_cntx.state == MMI_BIPR_STATE_AUTHORIZING)
        {
            mmi_bt_bipr_notify_recv_err(MMI_BIP_ERR_DISCONNECTED);
            
            SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_CONN_REQ, NULL);
            DeleteScreenIfPresent(SCR_BIP_NOTY_CONN_REQ);
        }
    }
    /* reset members */
    g_bip_context.bip_responder_cntx.state = MMI_BIPR_STATE_ACTIVE;
    g_bip_context.bip_responder_cntx.req_id = MMI_BIP_INVALID_REQ_ID;
    g_bip_context.bip_responder_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;

    /* clear tmp file */
    FS_Delete((U16*) g_bip_context.bip_responder_cntx.img_list_path);
    FS_Delete((U16*) g_bip_context.bip_responder_cntx.img_handle_name_path);
    FS_Delete((U16*) g_bip_context.bip_responder_cntx.thm_path);

    /* delete tmp file that may exist by accidence */
    mmi_ucs2cpy((S8*) tmp_file, (S8*) g_bip_context.bip_responder_cntx.recv_path);
    mmi_ucs2cat((S8*) tmp_file, (S8*) BIP_PUSH_R_TMP_FILENAME);
    FS_Delete((U16*) tmp_file);

    mmi_bt_bip_stop_blinking(MMI_BT_SERVER_ROLE);
}

#define MMI_BT_BIP_COMMON_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_get_image_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
bt_bip_img_format_enum mmi_bt_bip_get_image_type(U16 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime_type;
    bt_bip_img_format_enum img_format = BT_BIP_IMG_TYPE_UNSUPPORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mime_type = mime_get_file_type((kal_wchar*) pathfileName);

    if (mime_type == NULL)
    {
        goto RET;
    }

    switch (mime_type->mime_subtype)
    {
        case MIME_SUBTYPE_GIF:
            img_format = BT_BIP_IMG_TYPE_GIF;
            break;
        case MIME_SUBTYPE_JPEG:
        case MIME_SUBTYPE_JPG:
            img_format = BT_BIP_IMG_TYPE_JPEG;
            break;
        case MIME_SUBTYPE_WBMP:
            img_format = BT_BIP_IMG_TYPE_WBMP;
            break;
        case MIME_SUBTYPE_PNG:
            img_format = BT_BIP_IMG_TYPE_PNG;
            break;
        case MIME_SUBTYPE_BMP:
        case MIME_SUBTYPE_BMP_1:
            img_format = BT_BIP_IMG_TYPE_BMP;
            break;
        default:
            break;
    }

RET:
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
#endif
    return img_format;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_get_path_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathFileName        [?]     [?]
 *  path                [?]     [?]
 *  name                [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_get_path_name(S8 *pathFileName, S8 *path, S8 *name, U16 name_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 PathLength = (U16) mmi_ucs2strlen(pathFileName);
    S16 *UniPathName = (S16*) pathFileName;
    U16 NameLength = 0;
    U16 deter = '\\';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (PathLength > 0)
    {
        PathLength--;
        NameLength++;
        if (memcmp(UniPathName + PathLength, &deter, 2) == 0)
        {
            break;
        }
    }
    if (name != NULL)
    {
        /* check name len */
		if (NameLength * 2 <= name_size )
		{
                     memcpy(name, (S8*) (UniPathName + PathLength + 1), NameLength * 2);
                }
		else
		{
			U8 max_pfx_len = 5; /* ".wbmp" */ 
			U8 left_space = max_pfx_len * 2 + 2; /*  + 0x00 */
			/* name header*/
		    memcpy(name, (S8*) (UniPathName + PathLength + 1), 
					name_size - left_space);
			/* postfix */
			memcpy(name + (name_size - left_space), 
					(S8*) (UniPathName + mmi_ucs2strlen(pathFileName) - max_pfx_len),
					left_space);
		}
    }
    if (path != NULL)
    {
        memcpy(path, pathFileName, (PathLength + 1) * 2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_request_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_request_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_REQUEST_TIMEOUT, g_bip_context.bip_initiator_cntx.state);

    switch (g_bip_context.bip_initiator_cntx.state)
    {
        case MMI_BIPI_STATE_CONNECTING:
			g_bip_context.bip_initiator_cntx.b_timeout = MMI_TRUE;
        case MMI_BIPI_STATE_ABORTING:
            /* notify mmi timeout */
            //mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_TIMEOUT);
            
        case MMI_BIPI_STATE_DISCONNECTING:
            kal_prompt_trace(MOD_MMI, "[BIP MMI]request_timeout: send TpDisconnect Request\n");
            mmi_bt_bipi_send_disconnect_req(MMI_BIP_TP_DISCONNECT);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_generate_thumbnail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_path        [?]     [?]
 *  thm_path        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_bt_bipi_generate_thumbnail(U16 *img_path, U16 *thm_path, U16 thm_path_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w = 0, h = 0, buf_size = 0;
    U8 *buf_ptr = NULL;
    GDI_RESULT gdi_ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_GENERATE_THM);
    MMI_BIP_LOG_PATH(img_path);

    /* construct thm filename */
    mmi_bt_bip_construct_send_thm_path((S8*)img_path, (S8*)thm_path, thm_path_len);                        

    MMI_BIP_LOG(MMI_BT_BIP_THM_PATH);
    MMI_BIP_LOG_PATH(thm_path);

    w = BT_BIP_THM_WIDTH;
    h = BT_BIP_THM_HEIGHT;
    buf_size = (w * h * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
    buf_size = ((buf_size + 3) / 4) * 4;

    buf_ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BT_BIP, buf_size);
    if (buf_ptr != NULL)
    {
        gdi_image_set_encoding_flag(GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_442);
        gdi_ret = gdi_image_encode_file_to_jpeg((S8*) img_path, (S8*) thm_path, w, h, buf_ptr, buf_size);
        applib_mem_ap_free(buf_ptr);
    }
	else
	{
	    kal_prompt_trace(MOD_MMI, "[BT BIP] applib_mem_ap_alloc FAILED!!!");
    }
    MMI_BIP_LOG1(MMI_BT_BIP_GDI_ENCODING_RETURN, gdi_ret);
    if (gdi_ret == GDI_SUCCEED)
    {
        MMI_BIP_LOG(MMI_BT_BIP_GDI_ENCODING_SUCCESS);
        return MMI_TRUE;
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIP_GDI_ENCODING_FAILED);
        return MMI_FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_construct_recved_thm_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_path_file      
 *  dst_path            
 *  path_size               
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_rename_pulled_thm(S8 * dst_thm_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_RENAME_PULLED_THM);

    mmi_asc_to_ucs2((S8*) dst_thm_name, (S8*) g_bip_context.bip_initiator_cntx.img_handle);
    mmi_ucs2cat((S8*) dst_thm_name, (S8*) L"_thm");
    /* append postfix: thm always is jpg */
    mmi_ucs2cat((S8*) dst_thm_name, (S8*) L".jpg");

    /* rename the tmp file name */
    mmi_bt_bip_rename_recved_file(
        (U16*) g_bip_context.bip_initiator_cntx.thm_path,
        (U16*) dst_thm_name,
        (U16*) BIP_PULL_I_TMP_FILENAME);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_construct_send_thm_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_path_file      
 *  dst_path           
 *  path_size            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_construct_send_thm_path(S8 *img_path_file, S8 *thm_path, U16 path_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 img_name[BT_BIP_MAX_IMG_NAME_LEN];
    U16 name_len, left_len;
    U16 deter = '.';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_CONSTRUCT_SEND_THM_PATH);
        
    mmi_ucs2cpy((S8*)thm_path, (S8*)BIP_GEN_THM_PATH);

    memset(img_name, 0, sizeof(img_name));

    mmi_bt_bip_get_path_name((S8*) img_path_file, (S8*) NULL, (S8*) img_name, BT_BIP_MAX_IMG_NAME_LEN);
    left_len = path_size / ENCODING_LENGTH - mmi_ucs2strlen((S8*) thm_path);

    name_len = mmi_ucs2strlen((S8*) img_name);
    while (name_len > 0)
    {
        name_len--;
        if (memcmp(img_name + name_len, &deter, 2) == 0)
        {
            break;
        }
    }
    
    /* to be improved */
    ASSERT(left_len > 4 + 3 + 4);
    mmi_ucs2cat((S8*) thm_path, (S8*) L"thm_");
    mmi_ucs2ncat((S8*) thm_path, (S8*) img_name, name_len > 3 ? 3 : name_len);
    mmi_ucs2cat((S8*) thm_path, (S8*) L".jpg");

    MMI_BIP_LOG_PATH(thm_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_gen_dup_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [?]     
 *  old_name        [?]     
 *  new_name        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S8 mmi_bt_bip_gen_dup_name(U16 *path, U16 *old_name, U16 *new_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    U8 fcnt = 1;
    U8 pre_str_len = 0, old_name_len;
    U8 *path_buf;
    U8 *p_name, *pfx, *p_rear;
    U16 path_len = FMGR_MAX_PATH_LEN * ENCODING_LENGTH;
    U8 tmp_name[BIP_MAX_FILE_NAME_LEN];
    U16 len = 0, pfx_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_GEN_DUP_NAME);
    MMI_BIP_LOG_PATH(old_name);

    path_buf = OslMalloc(path_len);
    memset(path_buf, 0, path_len);

    mmi_ucs2cpy((S8*) path_buf, (S8*) path);
    p_name = path_buf + mmi_ucs2strlen((S8*) path) * ENCODING_LENGTH;

    old_name_len = mmi_ucs2strlen((S8*) old_name);

    /* create duplicated name */
    while (fcnt < 0xFF)
    {
        /* Dup(%d) -> tmp */
        kal_wsprintf((kal_uint16*) tmp_name, "Dup(%d)", fcnt);

        pre_str_len = mmi_ucs2strlen((S8*) tmp_name);

        /* Dup(%d)+ name */
        if (old_name_len + pre_str_len > (BIP_MAX_FILE_NAME_LEN / 2 - 1))
        {
            len = BIP_MAX_FILE_NAME_LEN / 2 - 1 - pre_str_len;

			pfx = (U8*)(old_name + old_name_len - 1);
			while ((U16*)pfx > old_name)
			{
			    if (pfx[0] == '.' && pfx[1] == 0x00)
					break;
				pfx = pfx - 2;
             }
			if ((U16*)pfx > old_name)
				pfx_len = old_name_len - ((U16*)pfx - old_name) / 2;

			if (len <= pfx_len) 
	            goto DUP_FAILED;

            /* filename -> tmp */
			
			/* header part of oldname */
	        mmi_ucs2ncat((S8*) tmp_name, (S8*) old_name, len - pfx_len);
			/* postfix part of oldname */
			p_rear = (U8*)((U16*)tmp_name + pre_str_len + (len - pfx_len));
			mmi_ucs2cpy((S8*)p_rear, (S8*)pfx);
        }
		else
		{
	        /* filename -> tmp */
			mmi_ucs2cat((S8*) tmp_name, (S8*) old_name);
		}

        /* check new path length */
        if ((mmi_ucs2strlen((PS8) path_buf) + mmi_ucs2strlen((PS8) tmp_name)) > (FMGR_MAX_PATH_LEN - 1))
        {
            goto DUP_FAILED;
        }

        /* check if new filename exists */
        /* form complete path */
        mmi_ucs2cpy((S8*) p_name, (S8*) tmp_name);
        ret = FS_GetAttributes((const WCHAR*)path_buf);
        /* file doesn't exist */
        if ((ret == FS_FILE_NOT_FOUND) || (ret == FS_PATH_NOT_FOUND))
        {
            /* unique name */
            memcpy(new_name, tmp_name, BIP_MAX_FILE_NAME_LEN);
            if (path_buf);
            {
                OslMfree(path_buf);
            }
            MMI_BIP_LOG(MMI_BT_BIP_GEN_NEW_NAME);
            MMI_BIP_LOG_PATH(new_name);
            
            return 1;
        }
        /* file already exist */
        else
        {
            /* increase temp count */
            fcnt++;
        }
    }

  DUP_FAILED:
    /* can't generate a unique dup file */
    if (path_buf);
    {
        OslMfree(path_buf);
    }
    return -1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_rename_recved_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [?]     
 *  dst_name        [?]     
 *  src_name        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_bt_bip_rename_recved_file(U16 *path, U16 *dst_name, U16 *src_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    S8 *dst_file;
    S8 *tmp_file;
    U32 path_len = FMGR_MAX_PATH_LEN * ENCODING_LENGTH;
    S8 new_name[BIP_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_RENAME_RECVED_FILE);
    MMI_BIP_LOG_PATH(dst_name);
    MMI_BIP_LOG_PATH(src_name);

    dst_file = OslMalloc(path_len);
    tmp_file = OslMalloc(path_len);

    memset(dst_file, 0, path_len);
    memset(tmp_file, 0, path_len);

    mmi_ucs2cpy((S8*) dst_file, (S8*) path);
    mmi_ucs2cat((S8*) dst_file, (S8*) dst_name);

    mmi_ucs2cpy((S8*) new_name, (S8*) dst_name);

    ret = FS_GetAttributes((const WCHAR*)dst_file);

    /* actual file already exist */
    if ((ret != FS_FILE_NOT_FOUND) && (ret != FS_PATH_NOT_FOUND))
    {
        ret = mmi_bt_bip_gen_dup_name(path, dst_name, (U16*) new_name);
        if (ret <= 0)
        {
            /* failed */
            OslMfree(dst_file);
            OslMfree(tmp_file);
            return MMI_FALSE;
        }
        mmi_ucs2cpy((S8*) dst_file, (S8*) path);
        mmi_ucs2cat((S8*) dst_file, (S8*) new_name);
    }

    mmi_ucs2cpy((S8*) tmp_file, (S8*) path);
    mmi_ucs2cat((S8*) tmp_file, (S8*) src_name);

    FS_Rename((U16*) tmp_file, (U16*) dst_file);

    mmi_ucs2cpy((S8*)dst_name, (S8*)new_name);
    
    MMI_BIP_LOG(MMI_BT_BIP_RENAME_RECVED_FILE_DST_FILE);
    MMI_BIP_LOG_PATH(dst_file);

    OslMfree(dst_file);
    OslMfree(tmp_file);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_name_swapcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_name            [IN]        
 *  src_name            [IN]        
 *  h_order_name(?)     [IN]        
 *  n_order_name(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_name_swapcpy(PU8 dst_name, PU8 src_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	U32 src_len = mmi_ucs2strlen((PS8) src_name) * 2;
	MMI_BOOL b_truncate = MMI_FALSE;
	PU8 pfx = NULL;
	U32 j, pfx_len = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (src_len >= BIP_MAX_FILE_NAME_LEN)
	{
		pfx = src_name + src_len - 2;
		while (pfx > src_name)
		{
		    if (pfx[0] == 0x00 && pfx[1] == '.')
				break;
			pfx = pfx - 2;
		}
		if (pfx > src_name)
			pfx_len = src_len - (pfx - src_name);
			
	    src_len = BIP_MAX_FILE_NAME_LEN - pfx_len - 2;
	    b_truncate = MMI_TRUE;
	}
	
    for (i = 0; i < src_len; i += 2)       
    {
        dst_name[i] = src_name[i + 1];
        dst_name[i + 1] = src_name[i];
    }

	if (b_truncate)
	{
	    for (j = 0; j < pfx_len; j += 2, i += 2)
	    {
	    	dst_name[i] = pfx[j + 1];
			dst_name[i + 1] = pfx[j];
		}
	}
	
	dst_name[i] = 0;
	dst_name[i + 1] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_notify_user_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_notify_user_error(U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 errcode = MMI_BIP_ERR_LAST;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rsp_code)
    {
        case BT_BIP_XML_GEN_FAIL:
            errcode = MMI_BIP_ERR_XML_GEN_FAIL;
            break;
        case BT_BIP_FILE_OPEN_FAIL:
            errcode = MMI_BIP_ERR_FILE_OPEN_FAIL;
            break;
        case BT_BIP_FILE_READ_FAIL:
            errcode = MMI_BIP_ERR_FILE_READ_FAIL;
            break;
        case BT_BIP_FILE_WRITE_FAIL:
            errcode = MMI_BIP_ERR_FILE_WRITE_FAIL;
            break;
        case BT_BIP_DISK_FULL:
            errcode = MMI_BIP_ERR_DISK_FULL;
            break;
        case BT_BIP_ROOT_DIR_FULL:
            errcode = MMI_BIP_ERR_ROOT_DIR_FULL;
            break;
        default:
            break;
    }

    mmi_bt_bipi_notify_recv_err(errcode);
}

/*****************************************************************************
 *  functions about adapter of BIP PUSH and OPP
 *****************************************************************************/

#define MMI_BT_BIP_OPP_ADP_FUNC

typedef struct
{
    S8 file_path_to_send[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    mmi_bt_send_file_callback callback_func;
    MMI_BOOL b_img_file;
} mmi_bt_send_file_info_struct;

mmi_bt_send_file_info_struct g_mmi_bt_send_file_info;


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_send_file_through_BT
 * DESCRIPTION
 *  This function is to request to forward the specified file
 *  through Bluetooth.
 *  When the forwarding finish, the callback func is called.
 * PARAMETERS
 *  file_path       [IN]        The specified file with path info
 *  callback_f      [IN]        Callback func
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_send_file_through_BT(S8 *file_path, mmi_bt_send_file_callback callback_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_img_format_enum img_type;
    U32 COD_bit_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* file path is null, return to application */
    if (!file_path)
    {
        ASSERT(0);  /* assert! for easy debuging */
        if (callback_f)
        {
            callback_f(NULL, MMI_BIP_ERR_FILE_OPEN_FAIL);
        }
        return;
    }
    
#if defined(__DRM_SUPPORT__)
    /* drm check: if allow to forward out */
    if (!DRM_interdev_movable(0, (kal_wchar*) file_path))
    {
        MMI_BIP_LOG(MMI_BT_BIP_DRM_FORBIDDEN);

        DisplayPopup(
            (U8*) GetString(STR_BIP_DRM_FORBIDDEN),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);

        return;
    }
#endif /* defined(__DRM_SUPPORT__) */ 

    MMI_BIP_LOG(MMI_BT_BIP_FILE_PATH_TO_FORWARD);
    MMI_BIP_LOG_PATH(file_path);

    /* record file_path and callback func */
    mmi_ucs2cpy(g_mmi_bt_send_file_info.file_path_to_send, file_path);
    g_mmi_bt_send_file_info.callback_func = callback_f;
    g_mmi_bt_send_file_info.b_img_file = MMI_FALSE;

    /* check if this file is image file */
    img_type = mmi_bt_bip_get_image_type((U16*) file_path);
    if (img_type == BT_BIP_IMG_TYPE_UNSUPPORT)
    {
        MMI_BIP_LOG(MMI_BT_BIP_SENDFILE_ISNOT_IMAGE);
        g_mmi_bt_send_file_info.b_img_file = MMI_FALSE;
    }
    else
    {
        MMI_BIP_LOG(MMI_BT_BIP_SENDFILE_IS_IMAGE);
        g_mmi_bt_send_file_info.b_img_file = MMI_TRUE;
    }

    /* discovery device */
    COD_bit_mask = MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK;
    /*
     * | MMI_BT_PHONE_MAJOR_DEVICE_MASK
     * | MMI_BT_IMAGING_MAJOR_DEVICE_MASK;
     */

    mmi_bt_entry_cod_device_with_service_select_screen(
        COD_bit_mask,
        0,
        (void*)mmi_bt_push_cm_device_discovery_callback);

}

#ifdef __MMI_OPP_SUPPORT__

extern U8 mmi_bt_opp_send_file_to_dev(S8 *file_name_with_path, void* callback_f, void *dst_dev);
extern void mmi_opp_fmgr_forward_to_opp_callback(void *buf_p, U32 result);

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_push_cm_device_discovery_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  lap         [IN]        
 *  uap         [IN]        
 *  nap         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_push_cm_device_discovery_callback(MMI_BOOL result, U32 lap, U8 uap, U16 nap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL b_support_BIP = MMI_FALSE;
    MMI_BOOL b_support_OPP = MMI_FALSE;
    mmi_bt_dev_addr dst_bt_dev;
    mmi_bt_dev_struct bt_dev_info;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        /* inquiry service supported by this dev */
        mmi_bt_get_selected_specfic_device_info((void*)&bt_dev_info);

        dst_bt_dev.lap = bt_dev_info.bd_addr.lap;
        dst_bt_dev.uap = bt_dev_info.bd_addr.uap;
        dst_bt_dev.nap = bt_dev_info.bd_addr.nap;

        for (i = 0; i < bt_dev_info.service_list_num; i++)
        {
            if (bt_dev_info.service_list[i] == MMI_BTH_OBEX_IMAGING_RESPONDER_UUID)
            {
                MMI_BIP_LOG(MMI_BT_BIP_DSTDEV_SUPPORT_BIP);
                b_support_BIP = KAL_TRUE;
            }
            else if (bt_dev_info.service_list[i] == MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID)
            {
                MMI_BIP_LOG(MMI_BT_BIP_DSTDEV_SUPPORT_OPP);
                b_support_OPP = KAL_TRUE;
            }
        }

        if (b_support_BIP && g_mmi_bt_send_file_info.b_img_file 
			&& g_bip_context.bip_initiator_cntx.state == MMI_BIPI_STATE_IDLE)/*may pushed from BIP pull initiator*/
        {
            MMI_BIP_LOG(MMI_BT_BIP_PUSH_THROUGH_BIP);
            mmi_bt_bip_send_image_to_dev(
                g_mmi_bt_send_file_info.file_path_to_send,
                (mmi_bt_bip_send_img_callback) mmi_bt_bipi_fmgr_forward_to_bip_callback,
                /* g_mmi_bt_send_file_info.callback_func, */ &dst_bt_dev);
        }
    #ifdef __MMI_OPP_SUPPORT__

        else 
        {
            /* through OPP */
            MMI_BIP_LOG(MMI_BT_BIP_PUSH_THROUGH_OPP);

            mmi_bt_opp_send_file_to_dev(
                g_mmi_bt_send_file_info.file_path_to_send,
                (void*)mmi_opp_fmgr_forward_to_opp_callback,
                &dst_bt_dev);

        }
    #else
        else
        {
            /* pop up 'not support BT push' */
            kal_prompt_trace(MOD_MMI, "[BIP MMI]== no BT service availible ==\n");

            DisplayPopup(
                (U8*) GetString(STR_BIP_NOTSUPPORT_BT_PUSH),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);

        }

    #endif /* __MMI_OPP_SUPPORT__ */ 
    }
    else
    {
    }
}

#endif /* defined(__MMI_BIP_SUPPORT__) */ 

#endif /* __MMI_BT_MTK_SUPPORT__ */ 

