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
 * BTMMIFtp.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI FTP service.
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
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/*  Include: MMI header file */
#ifndef __MTK_TARGET__
#include "Windows.h"
#endif 
#include "MMI_include.h"
#include "Conversions.h"
#include "FileManagerGProt.h"
#include "CallManagementGprot.h"

/* Trace Header Files */


/* File Type Categories (sync with file manager) */
#include "FileMgr.h"
#include "xml_def.h"
#include "CommonScreens.h"      /* DisplayPopup */
#include "SettingProfile.h"     /* for tone ID */
#include "BTMMIScrGprots.h"
#include "BTMMICm.h"
#include "Bluetooth_struct.h"
#include "BTMMIFtpGprots.h"
#include "BTMMIFtpScr.h"
#include "BTMMIFtp.h"
#include "BTMMIObex.h"
#include "Bluetooth_bm_struct.h"
#include "ExtDeviceDefs.h"
#include "BTMMICustDef.h"
#include "BTMMICmGprots.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#if defined(__DRM_SUPPORT__)
#include "Drm_gprot.h"
#endif

/***************************************************************************** 
* External Variable & Functions
*****************************************************************************/

/* for file name buffer */
extern S8 nPrintableStr[];
/*extern int mmi_bth_activate_cnf_hdler(U32 profile_id);
extern int mmi_bth_deactivate_cnf_hdler(U32 profile_id);
extern int mmi_bth_disconnect_cnf_hdler(MMI_BOOL result, U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id);
extern int mmi_bth_connect_ind_hdler(U32 lap, U8 uap, U16 nap, U8 *name_p, U32 profile_id, U32 connection_id);
extern int mmi_bth_multiple_connect_cnf_hdler(
            MMI_BOOL result,
            U32 lap,
            U8 uap,
            U16 nap,
            U8 *name_p,
            U32 profile_id,
            U32 connection_id,
            U8 connecting_index);
*/
extern void mmi_bth_disconnect_ind_hdler(U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id);
extern int mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern int mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern void mmi_chset_mixed_text_to_ucs2_str(
                kal_uint8 *dest,
                kal_int16 dest_size,
                kal_uint8 *src,
                mmi_chset_enum encoding);
extern U8 PhnsetGetDefEncodingType(void);
extern MMI_BOOL mmi_bt_test_ucs2(U16 *buf, U16 char_num);
extern void mmi_bt_truncate_ucs2_string(U16 *buf, U16 char_num, U16 truncate_char_num);
extern void playRequestedTone(ALL_TONE_ENUM playtone);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
const kal_uint8 OBEX_FTP_UUID[] = {0xF9, 0xEC, 0x7B, 0xC4,
    0x95, 0x3C, 0x11, 0xD2,
    0x98, 0x4E, 0x52, 0x54,
    0x00, 0xDC, 0x9E, 0x09
};

/***************************************************************************** 
* CONTEXT
*****************************************************************************/
#ifdef __MMI_FTS_SUPPORT__
mmi_ftps_cntx_struct g_mmi_ftps_cntx;
mmi_ftps_cntx_struct *const ftps_cntx_p = &g_mmi_ftps_cntx;
mmi_ftps_conn_cntx_struct *act_server_cntx_p;
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
mmi_ftpc_cntx_struct g_mmi_ftpc_cntx;
mmi_ftpc_cntx_struct *const ftpc_cntx_p = &g_mmi_ftpc_cntx;
mmi_ftpc_conn_cntx_struct *act_client_cntx_p;
#endif /* __MMI_FTC_SUPPORT__ */ 

/***************************************************************************** 
* MACROS
*****************************************************************************/
/* MMI usb context bit-wise flag operation */
#ifdef __MMI_FTC_SUPPORT__
#define MMI_FTPC_GET_FLAG(a)       ( ((ftpc_cntx_p->ftpc_flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMI_FTPC_SET_FLAG(a)       ( (ftpc_cntx_p->ftpc_flag) |=  a )
#define MMI_FTPC_RESET_FLAG(a)     ( (ftpc_cntx_p->ftpc_flag) &=  ~a )
#endif /* __MMI_FTC_SUPPORT__ */ 

#ifdef __MMI_FTS_SUPPORT__
#define MMI_FTPS_GET_FLAG(a)       ( ((ftps_cntx_p->ftps_flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMI_FTPS_SET_FLAG(a)       ( (ftps_cntx_p->ftps_flag) |=  a )
#define MMI_FTPS_RESET_FLAG(a)     ( (ftps_cntx_p->ftps_flag) &=  ~a )

#define MMI_FTPS_LOG_STATE_ERR(i)                                                                  \
   {                                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_STATE_ERROR, i, (act_server_cntx_p+i)->ftps_state);\
   }
#define MMI_FTPS_LOG_STATE(i, x)                                                                            \
   {                                                                                                        \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_STATE_TRANSITION, i, (act_server_cntx_p+i)->ftps_state, x );\
   }
#define MMI_FTPS_STATE_TRANS(i, x)                                                              \
{                                                                                               \
    FTP_DEBUG(kal_print("FTPS STATE_TRANS FROM STATE: %d",(act_server_cntx_p+i)->ftps_state);); \
    MMI_FTPS_LOG_STATE((i), (x));                                                               \
    (act_server_cntx_p+i)->ftps_state = (x);                                                    \
    FTP_DEBUG(kal_print("  TO STATE: %d\n",(act_server_cntx_p+i)->ftps_state););                \
}
#define FTPS_MAKE_RECV_PATH(x)   do {                      \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\", MMI_PUBLIC_DRV);         \
   mmi_ucs2cat((PS8)x, (PS8)FTPS_RECV_OBJ_FILEPATH);                 \
}while(0)
#endif /* __MMI_FTS_SUPPORT__ */ 

#define FTP_MEMSET(local_para_ptr)    do {                              \
    memset((kal_uint8*)(local_para_ptr) + sizeof(local_para_struct), 0, \
           (local_para_ptr)->msg_len - sizeof(local_para_struct));      \
} while(0)

/***************************************************************************** 
* MMI TRACE MACROS
*****************************************************************************/
#define MMI_FTP_LOG(x)                                                             \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x);                                           \
   }
#define MMI_FTP_LOG1(x, x1)                                                        \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1);                                       \
   }
#define MMI_FTP_LOG2(x, x1, x2)                                                    \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2);                                   \
   }
#define MMI_FTP_LOG3(x, x1, x2, x3)                                                \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3);                               \
   }
#define MMI_FTP_LOG4(x, x1, x2, x3, x4)                                            \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4);                           \
   }
#define MMI_FTP_LOG5(x, x1, x2, x3, x4, x5)                                            \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5);                           \
   }
#define MMI_FTP_LOG6(x, x1, x2, x3, x4, x5, x6)                                    \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6);                   \
   }
#define MMI_FTP_LOG7(x, x1, x2, x3, x4, x5, x6, x7)                                \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6, x7);               \
   }

/***************************************************************************** 
* INTERNAL STATIC FUNCTION
*****************************************************************************/
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
static void mmi_bt_ftp_cntx_init(void);
static MMI_BOOL mmi_bt_ftp_work_folder_init(void);
static void mmi_bt_ftp_connection_terminated(U32 index, MMI_BT_PROFILE_ROLE role);
static void mmi_bt_ftp_send_msg(U32 msg_id, void *p_local_para);
static void mmi_bt_ftp_send_msg_self(U32 msg_id, void *p_local_para);
static void mmi_bt_ftp_obj_name_swapcpy(PU8 h_order_name, PU8 n_order_name);
static int mmi_bt_ftp_write_buf2file(mmi_ftp_file_writer_struct *composer);
static U16 mmi_bt_ftp_htons(U16 a);
static void mmi_bt_ftp_ucs2_cut_name_with_ext(U8 *dest, U32  dest_size, const U8 *src);
static void mmi_bt_ftp_ucs2_cut_name_without_ext(U8 *dest, U32  dest_size, const U8 *src);
static MMI_BOOL mmi_bt_ftp_check_folder_existed(U8* absolute_path);
static void mmi_bt_ftp_delete_file(const U8* absolute_path, const U8* file_name);
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

#ifdef __MMI_FTS_SUPPORT__
static void mmi_bt_ftps_cntx_init(void);
static void mmi_bt_ftps_set_parent_folder(U32 i);
static void mmi_bt_ftps_set_folder(goep_set_folder_ind_struct *ind, U32 i);
static void mmi_bt_ftps_create_folder(goep_set_folder_ind_struct *ind, U32 i);
static void mmi_bt_ftps_push_obj(goep_push_ind_struct *ind, U32 i);
static void mmi_bt_ftps_push_delete(goep_push_ind_struct *ind, U32 i);
static void mmi_bt_ftps_write_obj_continue(goep_push_ind_struct *ind, U32 i);
static U32 mmi_bt_ftps_find_goep_id(U8 index);
static void mmi_bt_ftps_pull_continue(U32 i);
static void mmi_bt_ftps_send_folder_content(goep_pull_ind_struct *ind, U32 i);
static void mmi_bt_ftps_send_obj(goep_pull_ind_struct *ind, U32 i);
#if 0
/* under construction !*/
#endif
static int mmi_bt_ftps_write_obj(goep_push_ind_struct *ind, U32 i);
static int mmi_bt_ftps_gen_folder_content(U32 index, PU8 folder_name);
static int mmi_bt_ftps_compose_folder_element(
            mmi_ftp_file_writer_struct *composer,
            mmi_ftp_obj_info_struct *file_info);
static int mmi_bt_ftps_compose_file_element(mmi_ftp_file_writer_struct *composer, mmi_ftp_obj_info_struct *file_info);
static int mmi_bt_ftps_compose_end_element(mmi_ftp_file_writer_struct *composer, mmi_ftp_obj_info_struct *file_info);
static void mmi_bt_ftps_pull_stop_icon_timer_expire_hdler(void);
static void mmi_bt_ftps_read_fs_flag_and_popup(void);
static void mmi_bt_ftps_set_fs_flag(int ret);
static void mmi_bt_ftps_usb_plugin_hdle(void);
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
static void mmi_bt_ftpc_cntx_init(void);
static void mmi_bt_ftpc_received_folder_init(void);
#if 0
/* under construction !*/
#endif
static U32 mmi_bt_ftpc_find_goep_id(U8 index);
static void mmi_bt_ftpc_get_folder(goep_pull_rsp_struct *rsp, U32 i);
static int mmi_bt_ftpc_parse_folder_content(U32 i);
static int mmi_bt_ftpc_write_obj_entity(U8 idx, mmi_ftp_file_writer_struct *writer);
static void mmi_bt_ftpc_folder_listing_startElement(void *data, const char *el, const char **attr, int error);
static void mmi_bt_ftpc_folder_listing_endElement(void *data, const char *el, int error);
static void mmi_bt_ftpc_multi_file_continue(U32 i);
static int mmi_bt_ftpc_rename_recved_obj(U32 i);
static void mmi_bt_ftpc_browse_files_failed_timer_expire_hdler(void);
static void mmi_bt_ftpc_read_fs_flag_and_popup(void);
static void mmi_bt_ftpc_set_fs_flag(int ret);
static void mmi_bt_ftpc_disp_folder_content(U8 status);
static MMI_BOOL mmi_bt_ftpc_permit_show_pair_scr(mmi_bth_bt_addr bt_addr);
#endif /* __MMI_FTC_SUPPORT__ */ 

#define FTP_GLOBAL_API


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_init
 * DESCRIPTION
 *  This function is to initialize FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_INIT);

    /* ftp work folder init */
    mmi_bt_ftp_work_folder_init();
    /* ftp context init */
    mmi_bt_ftp_cntx_init();

#ifdef __MMI_FTS_SUPPORT__
    mmi_bt_ftps_menu_hdlr_init();
#endif 

#ifdef __MMI_FTC_SUPPORT__
    mmi_bt_ftpc_received_folder_init();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_deinit
 * DESCRIPTION
 *  This function is to clear screens for ftpc in de-init bt procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_DEINIT);

#ifdef __MMI_FTC_SUPPORT__
    mmi_bt_ftpc_reset_clear_scrs();

    /*reset fh*/
    mmi_bt_ftp_connection_terminated(0, MMI_BT_CLIENT_ROLE);

#endif 

#ifdef __MMI_FTS_SUPPORT__
    mmi_bt_ftps_reset_clear_scrs();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_event_hdlr
 * DESCRIPTION
 *  This function is to handle event from obex
 * PARAMETERS
 *  msg_id      [IN]        
 *  msg         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_event_hdlr(msg_type msg_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_EVENT_HDLR);

    switch (msg_id)
    {
#ifdef __MMI_FTS_SUPPORT__
        case MSG_ID_GOEP_REGISTER_SERVER_RSP:
            mmi_bt_ftps_register_server_rsp_hdlr(msg);
            return;
        case MSG_ID_GOEP_DEREGISTER_SERVER_RSP:
            mmi_bt_ftps_deregister_server_rsp_hdlr(msg);
            return;
        case MSG_ID_GOEP_CONNECT_IND:
            mmi_bt_ftps_connect_ind_hdlr(msg);
            return;
        case MSG_ID_GOEP_PUSH_IND:
            mmi_bt_ftps_push_ind_hdlr(msg);
            return;
        case MSG_ID_GOEP_PULL_IND:
            mmi_bt_ftps_pull_ind_hdlr(msg);
            return;
        case MSG_ID_GOEP_SET_FOLDER_IND:
            mmi_bt_ftps_set_folder_ind_hdlr(msg);
            return;
        case MSG_ID_GOEP_ABORT_IND:
            mmi_bt_ftps_abort_ind_hdlr(msg);
            return;
        case MSG_ID_GOEP_AUTHORIZE_IND:
            mmi_bt_ftps_authorize_ind_hdlr(msg);
            return;
#endif /* __MMI_FTS_SUPPORT__ */

#ifdef __MMI_FTC_SUPPORT__
        case MSG_ID_GOEP_CONNECT_RSP:
            mmi_bt_ftpc_connect_rsp_hdlr(msg);
            return;
        case MSG_ID_GOEP_PULL_RSP:
            mmi_bt_ftpc_pull_rsp_hdlr(msg);
            return;
        case MSG_ID_GOEP_SET_FOLDER_RSP:
            mmi_bt_ftpc_set_folder_rsp_hdlr(msg);
            return;
        case MSG_ID_GOEP_ABORT_RSP:
            mmi_bt_ftpc_abort_rsp_hdlr(msg);
            return;
#endif /* __MMI_FTC_SUPPORT__ */
        case MSG_ID_GOEP_DISCONNECT_IND:
            mmi_bt_ftp_disconnect_ind_hdlr(msg);
            return;
        default:
            MMI_FTP_ASSERT(0);
            return;
    }
}

#ifdef __MMI_FTS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_activate
 * DESCRIPTION
 *  This function is to activate the FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 Register_flag;
    goep_register_server_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_ACTIVATE);

    /* find all IDLE state connection and register them all */
    for (i = 0, Register_flag = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        switch ((act_server_cntx_p + i)->ftps_state)
        {
                /* unactivated connection */
            case MMI_FTPS_STATE_IDLE:
                /* Construct goep register req ilm */
                req = (goep_register_server_req_struct*) OslConstructDataPtr(sizeof(goep_register_server_req_struct));
                FTP_MEMSET(req);    /* memory init */
                memcpy(req->uuid, OBEX_FTP_UUID, 16);
                req->uuid_len = 16;
                req->req_id = (U8) i;
                FTP_DEBUG(kal_print("ILM REQ_ID: %d\n", req->req_id);)
                req->tp_type = GOEP_TP_BT;
                req->buf_ptr = (act_server_cntx_p + i)->ftps_obj_buff;
                req->buf_size = FTPS_MEM_BUFF_SIZE;

                /* switch state to registering */
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_REGISTERING);

                /* Send MSG_ID_GOEP_REGISTER_SERVER_REQ primitive */
                mmi_bt_ftp_send_msg(MSG_ID_GOEP_REGISTER_SERVER_REQ, req);

                /* set flag to notify the unactivaed connection is found */
                if (Register_flag == 0)
                {
                    Register_flag = 1;
                }
                break;
                /* other states */
            default:
                MMI_FTPS_LOG_STATE_ERR(i);
                break;
        }
    }
    /* without un-activated connections --> call activate cnf to CM */
    if (Register_flag == 0)
    {
        /* call activate cnf to CM */
        mmi_bth_activate_cnf_hdler((U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_deactivate
 * DESCRIPTION
 *  This function is to deactivate the FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 deregister_flag;
    bt_sdpdb_deregister_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_DEACTIVATE);

    /* check all connections state */
    for (i = 0, deregister_flag = 0; (i < FTP_MAX_CLIENT_SUPPORT) && (deregister_flag == 0); i++)
    {
        MMI_FTP_LOG2(MMI_BT_FTP_FTPS_STATE, i, (act_server_cntx_p + i)->ftps_state);
        switch ((act_server_cntx_p + i)->ftps_state)
        {
            case MMI_FTPS_STATE_REGISTERING:    /* activating -> deactivating */
            case MMI_FTPS_STATE_DEACTIVATING:   /* deactivating -> deactivating */
                MMI_FTPS_LOG_STATE_ERR(i);
                MMI_FTP_ASSERT(0);
                break;
            case MMI_FTPS_STATE_IDLE:           /* unactivated */
                break;
            default:                            /* other activated states */
                /* send SDP deregister primitive */
                req = (bt_sdpdb_deregister_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_deregister_req_struct));
                FTP_MEMSET(req);                /* memory init */
                req->uuid = MMI_BTH_OBEX_FILE_TRANSFER_UUID;

                /* send req to bt */
                mmi_bt_ftp_send_msg(MSG_ID_BT_SDPDB_DEREGISTER_REQ, req);

                /* only one sdp deregister req is enough */
                deregister_flag = 1;
                break;
        }
    }
    /* all connections are in IDLE state -> call deactivate cnf to CM */
    if (deregister_flag == 0)
    {
        mmi_bth_deactivate_cnf_hdler((U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_disconnect_client
 * DESCRIPTION
 *  This function is to deactivate the FTP application
 * PARAMETERS
 *  bd_addr         [IN]        
 *  g_conn_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_disconnect_client(mmi_bth_bt_addr bd_addr, U32 g_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_DISCONNECT_CLIENT);

    /* search the selected connection index */
    for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        MMI_FTP_LOG4(
            MMI_BT_FTP_FTPS_DISCONNECT_CLIENT_CHECK,
            i,
            (act_server_cntx_p + i)->ftps_state,
            ftps_cntx_p->g_conn_id[i],
            g_conn_id);
        if (ftps_cntx_p->g_conn_id[i] == g_conn_id)
        {
            switch ((act_server_cntx_p + i)->ftps_state)
            {
                case MMI_FTPS_STATE_DISCONNECTING:  /* disconnecting -> disconnecting */
                    MMI_FTPS_LOG_STATE_ERR(i);
                    MMI_FTP_ASSERT(0);
                    return;
                    /* connected states */
                case MMI_FTPS_STATE_ACTIVE:
                    //Connection sync to RFCOMM channel == Authorize
                    //both accept and reject will send disconnect req to goep
                case MMI_FTPS_STATE_ACCEPTED:
                case MMI_FTPS_STATE_RECEIVING:
                case MMI_FTPS_STATE_SENDING:
                    /* switch ftps state to disconnecting */
                    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_DISCONNECTING);
                    /* then do the same thing as state deactivating */
                    /* deactivate triggered disconnecting */
                case MMI_FTPS_STATE_DEACTIVATING:

                    /* Construct Disconnect REQ to goep */
                    req = (goep_disconnect_req_struct*) OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
                    FTP_MEMSET(req);    /* memory init */
                    req->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

                    /* Send Disconnect REQ to goep */
                    mmi_bt_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
                    return;
                    /* don't have to disconnect in states without connection */
                default:
                    /* there is no connection exists -> call disconnect cnf to CM */
                    mmi_bth_disconnect_cnf_hdler(
                        MMI_TRUE,
                        (act_server_cntx_p + i)->ftps_bt_device.lap,
                        (act_server_cntx_p + i)->ftps_bt_device.uap,
                        (act_server_cntx_p + i)->ftps_bt_device.nap,
                        (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                        (U32) ftps_cntx_p->g_conn_id[i]);
                    return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_set_shared_fodler
 * DESCRIPTION
 *  This function is to set the FTPS shared folder
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_set_shared_fodler(PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_SET_FOLDER_SCR_CALLBACK);

    mmi_ucs2cpy((PS8) ftps_cntx_p->root_folder, path);

    for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        mmi_ucs2cpy((PS8) (act_server_cntx_p + i)->current_folder, (PS8) ftps_cntx_p->root_folder);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_authorize_accept
 * DESCRIPTION
 *  This function is to accept rfcomm channel
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_authorize_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_authorize_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the current connection index */
    i = mmi_bt_ftps_find_goep_id(ftps_cntx_p->cur_goep_conn_id);
    MMI_FTP_LOG3(
        MMI_BT_FTP_FTPS_AUTHORIZE_ACCEPT,
        i,
        (act_server_cntx_p + i)->ftps_state,
        ftps_cntx_p->cur_goep_conn_id);

    if ((act_server_cntx_p + i)->ftps_state == MMI_FTPS_STATE_AUTHORIZING)
    {
        /* Send success connect response to OBEX task */
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACTIVE);

        /* for other apps query FTP connection in state active */
        /* accept == 0xFE, reject, delete, not authorize == 0xFF */
        /* connected states == 0, 1, 2,.... */
        ftps_cntx_p->g_conn_id[i] = 0xFE;

        /* Construct goep push res ilm */
        res = (goep_authorize_res_struct*) OslConstructDataPtr(sizeof(goep_authorize_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->rsp_code = GOEP_STATUS_SUCCESS;
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_AUTHORIZE_RES, res);
    }
    else
    {
        MMI_FTP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_authorize_reject
 * DESCRIPTION
 *  This function is to reject rfcomm channel
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_authorize_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_authorize_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the current connection index */
    i = mmi_bt_ftps_find_goep_id(ftps_cntx_p->cur_goep_conn_id);
    MMI_FTP_LOG3(
        MMI_BT_FTP_FTPS_AUTHORIZE_REJECT,
        i,
        (act_server_cntx_p + i)->ftps_state,
        ftps_cntx_p->cur_goep_conn_id);

    if ((act_server_cntx_p + i)->ftps_state == MMI_FTPS_STATE_AUTHORIZING)
    {
        /* Send success connect response to OBEX task */
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACTIVE);

        /* Construct goep push res ilm */
        res = (goep_authorize_res_struct*) OslConstructDataPtr(sizeof(goep_authorize_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->rsp_code = GOEP_STATUS_FAILED;
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_AUTHORIZE_RES, res);
    }
    else
    {
        MMI_FTP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_authorize_confirm_del_cb
 * DESCRIPTION
 *  This function is to reject the connect when confirm screen is deleted
 * PARAMETERS
 *  p       [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_ftps_authorize_confirm_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_authorize_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the current connection index */
    i = mmi_bt_ftps_find_goep_id(ftps_cntx_p->cur_goep_conn_id);
    MMI_FTP_LOG3(
        MMI_BT_FTP_FTPS_AUTHORIZE_DEL_CB,
        i,
        (act_server_cntx_p + i)->ftps_state,
        ftps_cntx_p->cur_goep_conn_id);

    if ((act_server_cntx_p + i)->ftps_state == MMI_FTPS_STATE_AUTHORIZING)
    {
        /* Send success connect response to OBEX task */
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACTIVE);

        /* Construct goep push res ilm */
        res = (goep_authorize_res_struct*) OslConstructDataPtr(sizeof(goep_authorize_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->rsp_code = GOEP_STATUS_FAILED;
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_AUTHORIZE_RES, res);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_get_dev_name
 * DESCRIPTION
 *  This function is to get the bt device name from context
 * PARAMETERS
 *  name_buf        [IN]        
 *  p           [?](?)
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_get_dev_name(PU8 name_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the current connection index */
    i = mmi_bt_ftps_find_goep_id(ftps_cntx_p->cur_goep_conn_id);

    MMI_FTP_LOG2(MMI_BT_FTP_FTPS_GET_DEV_NAME, i, ftps_cntx_p->cur_goep_conn_id);

    /* copy dev_name to MMI screen */
    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    utf8_char_cnt =
        (U8) ((mmi_chset_utf8_strlen((kal_uint8*) (act_server_cntx_p + i)->dev_name) + 1) * ENCODING_LENGTH);

    if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) name_buf,
                    MMI_BT_SCR_BD_NAME_LEN,
                    (kal_uint8*) (act_server_cntx_p + i)->dev_name);
    }
    else
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) name_buf,
                    utf8_char_cnt,
                    (kal_uint8*) (act_server_cntx_p + i)->dev_name);
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
 *  mmi_ftp_server_is_receiving
 * DESCRIPTION
 *  This function is to get current status of ftp server.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
BOOL mmi_ftp_server_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (act_server_cntx_p->ftps_state)
    {
        case MMI_FTPS_STATE_ACTIVE:
        {
            /* non-authorized */
            /* accept == 0xFE, reject, delete, not authorize == 0xFF */
            /* connected states == 0, 1, 2,.... */
            if (ftps_cntx_p->g_conn_id[0] == 0xFE)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    
        case MMI_FTPS_STATE_ACCEPTED:
        case MMI_FTPS_STATE_RECEIVING:
        case MMI_FTPS_STATE_SENDING:
        case MMI_FTPS_STATE_DISCONNECTING:
            return MMI_TRUE;
        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_get_state
 * DESCRIPTION
 *  This function is to get current status of ftp server.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
U32 mmi_bt_ftps_get_state(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return (act_server_cntx_p + i)->ftps_state;

}

#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_connect_server
 * DESCRIPTION
 *  This function is to connect server for ftp service
 * PARAMETERS
 *  bd_addr     [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_connect_server(mmi_bth_bt_addr bd_addr, U8 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_CONNECT_SERVER);

#ifdef __USB_IN_NORMAL_MODE__

    FTP_DEBUG(kal_print("FTPC CONNECT SERVER --> (__USB_IN_NORMAL_MODE__)\n");)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        FTPC_MAKE_RECV_PATH(nPrintableStr);
        /* in mass storage mode */
        if (mmi_usb_check_path_exported(nPrintableStr))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            mmi_bth_multiple_connect_cnf_hdler(
                MMI_FALSE,
                bd_addr.lap,
                bd_addr.uap,
                bd_addr.nap,
                NULL,
                (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                (U32) 0,
                req_id);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* Reset root folder content flag */
    for (i = 0; i < FTP_MAX_SERVER_SUPPORT; i++)
    {
        goep_connect_req_struct *req;

        MMI_FTP_LOG6(
            MMI_BT_FTP_FTPC_CONNECT_SERVER_CHECK,
            i,
            (act_client_cntx_p + i)->ftpc_state,
            req_id,
            bd_addr.lap,
            bd_addr.uap,
            bd_addr.nap);

        if ((act_client_cntx_p + i)->ftpc_state == MMI_FTPC_STATE_IDLE)
        {
            /* update context */
            ftpc_cntx_p->req_id[i] = req_id;
            (act_client_cntx_p + i)->got_root = 0;
            MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTING);
            (act_client_cntx_p + i)->ftpc_bt_device.lap = bd_addr.lap;
            (act_client_cntx_p + i)->ftpc_bt_device.uap = bd_addr.uap;
            (act_client_cntx_p + i)->ftpc_bt_device.nap = bd_addr.nap;

            /* connect server */
            /* film res pkt_type attibute */
            FTP_DEBUG(kal_print("FTPC CONNECT_SERVER TRY TO FILM ILM\n");)
            req = (goep_connect_req_struct*) OslConstructDataPtr(sizeof(goep_connect_req_struct));
            FTP_MEMSET(req);    /* memory init */
            req->bd_addr.lap = bd_addr.lap;
            req->bd_addr.uap = bd_addr.uap;
            req->bd_addr.nap = bd_addr.nap;
            req->buf_ptr = (act_client_cntx_p + i)->ftpc_obj_buff;
            req->buf_size = FTPC_MEM_BUFF_SIZE;
            req->req_id = req_id;
            req->tp_type = GOEP_TP_BT;
            memcpy(req->uuid, OBEX_FTP_UUID, 16);
            req->uuid_len = 16;

            /* send connect req to server */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_CONNECT_REQ, req);
            mmi_bt_ftpc_entry_connect_scr();
            return;
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_FTP_DEV_BUSY),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);

            mmi_bth_multiple_connect_cnf_hdler(
                MMI_FALSE,
                bd_addr.lap,
                bd_addr.uap,
                bd_addr.nap,
                NULL,
                (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                (U32) 0,
                req_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_is_recving
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
BOOL mmi_bt_ftpc_is_recving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_IS_RECEIVING, act_client_cntx_p->ftpc_state);

    switch (act_client_cntx_p->ftpc_state)
    {
        case MMI_FTPC_STATE_ABORTING:
        case MMI_FTPC_STATE_IDLE:
        case MMI_FTPC_STATE_CONNECTED:
            return MMI_FALSE;
        default:
            return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_is_canceling
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
BOOL mmi_bt_ftpc_is_canceling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_IS_CANCELING, act_client_cntx_p->ftpc_state);

    if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_DISCONNECTING)
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
 *  mmi_bt_ftpc_is_aborting
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
BOOL mmi_bt_ftpc_is_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_IS_ABORTING, act_client_cntx_p->ftpc_state);

    if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_ABORTING)
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
 *  mmi_bt_ftpc_connect_cancel
 * DESCRIPTION
 *  This is common function to abort connecting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_connect_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_req_struct *req;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_CONNECT_CANCEL, act_client_cntx_p->ftpc_state);

    mmi_bth_reg_pairing_permission(MMI_BTH_OBEX_FILE_TRANSFER_UUID,(void*)mmi_bt_ftpc_permit_show_pair_scr);
    
    /* wait rsp from server, the reply an abort req */
    if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_GETTING_FOLDER
        || act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_PARSING_FOLDER)
    {
        mmi_bt_ftpc_send_tpdisconnect(0);
        MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_TPDISCONNECTING);
        return;
    }

    /* construct disconnect req ilm */
    req = (goep_disconnect_req_struct*) OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
    FTP_MEMSET(req);    /* memory init */
    req->req_id = ftpc_cntx_p->req_id[0];

    /* already got the folder content and parsing, clear context */
    if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_CONNECTING)
    {
        /* diconnect cancel case */
        req->goep_conn_id = 0xFF;
    }

    /* send disconnect req and connect cnf fail to CM */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);

    mmi_bth_multiple_connect_cnf_hdler(
        MMI_FALSE,
        (act_client_cntx_p + i)->ftpc_bt_device.lap,
        (act_client_cntx_p + i)->ftpc_bt_device.uap,
        (act_client_cntx_p + i)->ftpc_bt_device.nap,
        NULL,
        (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
        (U32) 0,
        req->req_id);
    MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_DISCONNECTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_send_disconnect
 * DESCRIPTION
 *  This is common function to disconnect
 * PARAMETERS
 *  void
 *  cause(?)        [IN]        The cause to disconnect current session(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_send_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_SEND_DISCONNECT, act_client_cntx_p->ftpc_state);

    /* construct disconnect req ilm */
    req = (goep_disconnect_req_struct*) OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
    FTP_MEMSET(req);    /* memory init */
    req->goep_conn_id = ftpc_cntx_p->goep_conn_id[0];

    /* send disconnect req and connect cnf fail to CM */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_back_folder
 * DESCRIPTION
 *  This function is to go to the parent folder.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bt_ftpc_back_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG2(MMI_BT_FTP_FTPC_BACK_FOLDER, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id[0]);

    /* Change MMI FTPC state */
    switch (act_client_cntx_p->ftpc_state)
    {
        case MMI_FTPC_STATE_CONNECTED:
        {
            goep_set_folder_req_struct *req;

            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_SETTING_BACK_FOLDER);

            /* construct set folder req ilm */
            req = (goep_set_folder_req_struct*) OslConstructDataPtr(sizeof(goep_set_folder_req_struct));
            FTP_MEMSET(req);    /* memory init */
            req->goep_conn_id = ftpc_cntx_p->goep_conn_id[0];
            req->setpath_flag = GOEP_BACK_FOLDER;

            /* send set folder req */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_REQ, req);
            break;
        }
        default:    /* Incorrect state */
            /* Incorrect state, callback and return error */
            mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED);    /* Pop up error messages */
            MMI_FTPC_LOG_STATE_ERR(0);
            if (act_client_cntx_p->fh_ftpc_recv)
            {
                FS_Close(act_client_cntx_p->fh_ftpc_recv);
                act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE) NULL;
            }
            return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_root_folder
 * DESCRIPTION
 *  This function is to go to the root folder.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bt_ftpc_root_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG2(MMI_BT_FTP_FTPC_ROOT_FOLDER, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id[0]);

    /* Change MMI FTC state */
    switch (act_client_cntx_p->ftpc_state)
    {
        case MMI_FTPC_STATE_CONNECTED:
        {
            goep_set_folder_req_struct *req;

            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_SETTING_ROOT_FOLDER);

            /* construct set folder req ilm */
            req = (goep_set_folder_req_struct*) OslConstructDataPtr(sizeof(goep_set_folder_req_struct));
            FTP_MEMSET(req);    /* memory init */
            req->goep_conn_id = ftpc_cntx_p->goep_conn_id[0];
            req->setpath_flag = GOEP_ROOT_FOLDER;

            /* send set folder req */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_REQ, req);
            break;
        }
        default:    /* Incorrect state */
            /* Incorrect state, callback and return error */
            mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED);    /* Pop up error messages */
            MMI_FTPC_LOG_STATE_ERR(0);
            if (act_client_cntx_p->fh_ftpc_recv)
            {
                FS_Close(act_client_cntx_p->fh_ftpc_recv);
                act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE) NULL;
            }
            return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_change_folder
 * DESCRIPTION
 *  This function is to browse a new folder or refresh the current folder
 * PARAMETERS
 *  name        [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bt_ftpc_change_folder(PU16 name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    PU16 tmp_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG2(MMI_BT_FTP_FTPC_CHANGE_FOLDER, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id[0]);

    /* file path is null, not change to another folder (refresh) */
    if (!name)
    {
        /* refresh current folder */
        MMI_FTP_LOG(MMI_BT_FTP_FTPC_CHANGE_FOLDER_REFRESH);
        mmi_bt_ftpc_get_folder_content();
        return MMI_TRUE;
    }

    if ((mmi_ucs2cmp((PS8) name, (PS8) L".") != 0) && (mmi_ucs2cmp((PS8) name, (PS8) L"..") != 0))
    {
        goep_set_folder_req_struct *req;

        MMI_FTP_LOG(MMI_BT_FTP_FTPC_CHANGE_FOLDER_FORWARD);

        /* Change MMI FTPC state */
        switch (act_client_cntx_p->ftpc_state)
        {
            case MMI_FTPC_STATE_CONNECTED:
                MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_SETTING_FOLDER);
                break;

            default:    /* Incorrect state */
                /* Incorrect state, callback and return error */
                MMI_FTPC_LOG_STATE_ERR(0);
                if (act_client_cntx_p->fh_ftpc_recv)
                {
                    FS_Close(act_client_cntx_p->fh_ftpc_recv);
                    act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE) NULL;
                }
                mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
                return MMI_FALSE;
        }

        MMI_FTP_ASSERT((FTP_MAX_OBJ_NAME_LEN / 2) >= (mmi_ucs2strlen((PS8) name) + 1));

        tmp_name = get_ctrl_buffer(mmi_ucs2strlen((PS8) name) * 2 + 2);
        memset(tmp_name, 0, mmi_ucs2strlen((PS8) name) * 2 + 2);
        mmi_ucs2cpy((PS8) tmp_name, (PS8) name);

        for (i = 0; i <= mmi_ucs2strlen((PS8) name); i++) /* includes null temination */
        {
            *(tmp_name + i) = mmi_bt_ftp_htons(*(tmp_name + i));
        }
        mmi_ucs2cpy((PS8) act_client_cntx_p->ftpc_obj_name, (PS8) tmp_name);
        free_ctrl_buffer(tmp_name);

        /* construct set folder req ilm */
        req = (goep_set_folder_req_struct*) OslConstructDataPtr(sizeof(goep_set_folder_req_struct));
        FTP_MEMSET(req);    /* memory init */
        req->goep_conn_id = ftpc_cntx_p->goep_conn_id[0];
        req->setpath_flag = GOEP_FORWARD_FOLDER;
        mmi_ucs2cpy((PS8) req->folder_name, (PS8) act_client_cntx_p->ftpc_obj_name);

        /* send set folder req */
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_REQ, req);

        memset(act_client_cntx_p->ftpc_obj_name, 0, FTP_MAX_OBJ_NAME_LEN);
        return MMI_TRUE;
    }
    else if (mmi_ucs2cmp((PS8) name, (PS8) L"..") == 0)
    {
        MMI_FTP_LOG(MMI_BT_FTP_FTPC_CHANGE_FOLDER_BACK);
        mmi_bt_ftpc_entry_back_to_parent_folder();
        return MMI_FALSE;   /* Disable to show connecting scr again */
    }
    else
    {
        MMI_FTP_LOG(MMI_BT_FTP_FTPC_CHANGE_FOLDER_REFRESH);
        /* refresh current folder */
        mmi_bt_ftpc_get_folder_content();
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_file_obj
 * DESCRIPTION
 *  This function is to get file object.
 * PARAMETERS
 *  name        [IN]        
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bt_ftpc_get_file_obj(PU16 name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_pull_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_GET_FILE_OBJ, act_client_cntx_p->ftpc_state);
    FTP_DEBUG(kal_print("FTPC GET FILE OGJ\n");)
    /* Init the statistics for received object length */
    act_client_cntx_p->total_recv_obj_len = 0;
    act_client_cntx_p->remain_recv_obj_len = 0;
    act_client_cntx_p->recved_obj_len = 0;
    act_client_cntx_p->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;

    /* file path is null */
    if (!name)
    {
        mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
        MMI_FTP_ASSERT(0);
        return MMI_FALSE;
    }

    /* Change MMI FTPC state */
    switch (act_client_cntx_p->ftpc_state)
    {
        case MMI_FTPC_STATE_CONNECTED:
            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_GETTING_OBJ);
            break;

        default:    /* Incorrect state */
            /* Incorrect state, callback and return error */
            MMI_FTPC_LOG_STATE_ERR(0);
            if (act_client_cntx_p->fh_ftpc_recv)
            {
                FS_Close(act_client_cntx_p->fh_ftpc_recv);
                act_client_cntx_p->fh_ftpc_recv = (FS_HANDLE) NULL;
            }
            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_CONNECTED);
            mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED);    /* Pop up error messages */
            return MMI_FALSE;
    }

    mmi_ucs2cpy((PS8) act_client_cntx_p->ftpc_obj_name, (PS8) name);
    for (i = 0; i <= mmi_ucs2strlen((PS8) name); i++) /* includes null temination */
    {
        *(name + i) = mmi_bt_ftp_htons(*(name + i));
    }

    /* send get obj req */
    req = (goep_pull_req_struct*) OslConstructDataPtr(sizeof(goep_pull_req_struct));
    FTP_MEMSET(req);    /* memory init */
    req->goep_conn_id = ftpc_cntx_p->goep_conn_id[0];
    req->pkt_type = GOEP_FIRST_PKT;
    mmi_ucs2cpy((PS8) req->obj_name, (PS8) name);

    /* send pull req */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
//    mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_START);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_retrieve_get_prog_percentage
 * DESCRIPTION
 *  This function is to retrieve the file put progress.
 * PARAMETERS
 *  recv_per_str_buf        [?]     
 * RETURNS
 *  1 ~ 100  The percentage of put process.(?)
 *****************************************************************************/
void mmi_bt_ftpc_retrieve_get_prog_percentage(U16 *recv_per_str_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = ftpc_cntx_p->curr_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC RETRIVE GET PROG PERCENT\n");)
    /* Total length type of a object */
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    switch (g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type)
#else
    switch ((act_client_cntx_p + idx)->total_len_type)
#endif
    {
        case MMI_FTPC_TOTAL_LEN_NO_ZERO:
        {
            U8 prog;
         /*when get next file, total len may be No_First_Pkt
           * avoid case: total_recv_obj_len is the previous file len, it may be Zero.
           */
        #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
            if ((act_client_cntx_p + idx)->total_len_type == MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT)
            {
                prog = 0;
            }
            else
        #endif
            {
                prog =
                    (U8) (((double)
                           ((act_client_cntx_p + idx)->total_recv_obj_len -
                            (act_client_cntx_p + idx)->remain_recv_obj_len) / (double)((act_client_cntx_p +
                                                                                        idx)->total_recv_obj_len)) * 100.0);
            }
            kal_wsprintf((U16*) recv_per_str_buf, "%d%c", prog, '%');
        }
            break;

        case MMI_FTPC_TOTAL_LEN_ZERO:
        {

            /*when get next file, total len may be No_First_Pkt
           * this case: receved_obj_len has been set Zero.
           */
            U32 recved_size = (act_client_cntx_p + idx)->recved_obj_len;

            if (recved_size > 1024 * 1024 * 1024)
            {
                recved_size = recved_size / 1024;
                kal_wsprintf(
                    (U16*) recv_per_str_buf,
                    "%d.%dMB",
                    (U16) (recved_size / 1024),
                    (U16) ((recved_size % 1024) / 103));
            }
            else if (recved_size > 1024 * 1024)
            {
                recved_size = recved_size / 1024;
                kal_wsprintf(
                    (U16*) recv_per_str_buf,
                    "%d.%dMB",
                    (U16) (recved_size / 1024),
                    (U16) ((recved_size % 1024) / 103));
            }
            else if (recved_size > 1024)
            {
                kal_wsprintf(
                    (U16*) recv_per_str_buf,
                    "%d.%dKB",
                    (U16) (recved_size / 1024),
                    (U16) ((recved_size % 1024) / 103));
            }
            else if (recved_size > 0)   /* less than 1024 */
            {
                kal_wsprintf((U16*) recv_per_str_buf, "%dB", (U16) (recved_size));
            }
            else
            {
                kal_wsprintf((U16*) recv_per_str_buf, "%dB", 0);
            }
        }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_set_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_set_state(U32 i, mmi_ftpc_state_enum ftpc_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTPC_STATE_TRANS(i, ftpc_state);
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_bt_ftpc_get_state(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (act_client_cntx_p + i)->ftpc_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_send_tpdisconnect
 * DESCRIPTION
 *  This is common function to disconnect
 * PARAMETERS
 *  void
 *  cause(?)        [IN]        The cause to disconnect current session(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_send_tpdisconnect(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_SEND_DISCONNECT, act_client_cntx_p->ftpc_state);

    /* construct disconnect req ilm */
    req = (goep_disconnect_req_struct*) OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
    FTP_MEMSET(req);    /* memory init */
    req->req_id = ftpc_cntx_p->req_id[i];
    req->goep_conn_id = ftpc_cntx_p->goep_conn_id[i];

    mmi_bt_ftp_send_msg(MSG_ID_GOEP_TPDISCONNECT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_is_get_root
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_ftpc_is_get_root(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((act_client_cntx_p + i)->got_root == 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
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

#endif /* __MMI_FTC_SUPPORT__ */ 
#define END_FTP_GLOBAL_API

#define FTP_CORE_FUNCTION


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_cntx_init
 * DESCRIPTION
 *  This function is to initialize FTP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_CNTX_INIT);
#ifdef __MMI_FTS_SUPPORT__    
    /* ftps active connection base pointer init */
    act_server_cntx_p = &(ftps_cntx_p->conn_cntx[0]);
#endif

#ifdef __MMI_FTC_SUPPORT__
    /* ftpc active connection base pointer init */
    act_client_cntx_p = &(ftpc_cntx_p->conn_cntx[0]);
#endif

#ifdef __MMI_FTS_SUPPORT__
    /* ftps context init */
    mmi_bt_ftps_cntx_init();
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
    /* ftpc context init */
    mmi_bt_ftpc_cntx_init();
#endif /* __MMI_FTC_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_work_folder_init
 * DESCRIPTION
 *  This function is to initialize FTP work folder Z:\@ftp\
 *  When the folder is not existed, it will try to create, if create failed, it will set flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_ftp_work_folder_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_WORK_FOLDER_INIT);

#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        return MMI_TRUE;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    h = FS_Open((kal_uint16*) FTP_FOLDER_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
        MMI_FTP_LOG(MMI_BT_FTP_WORK_FOLDER_INIT_OPEN_NO_ERROR);
        return MMI_TRUE;
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((kal_uint16*) FTP_FOLDER_PATH);
        if (ret < 0)
        {
            MMI_FTP_LOG(MMI_BT_FTP_WORK_FOLDER_INIT_OPEN_ERROR);
            return MMI_FALSE;            
        }
        return MMI_TRUE;
    }
}

#ifdef __MMI_FTS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_cntx_init
 * DESCRIPTION
 *  This function is to initialize FTPS context
 *  This funciton is only to init the cntxt in ftps, if read shared path info from a hidden file, if read failed, 
 *  then default path will be set to variables.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    FS_HANDLE h;
    U32 read_length;
    int res;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_CNTX_INIT);

    /* Access Right Init */
    /* Read the ftp server access right from nvram */
    ReadValue(NVRAM_FTP_ACCESS_RIGHT, &(ftps_cntx_p->access_right), DS_BYTE, &error);
    if (ftps_cntx_p->access_right == 0xFF)
    {
        /* default setting == READ_ONLY */
        ftps_cntx_p->access_right = MMI_FTP_ACCESS_RIGHT_READ_ONLY;
        FTP_DEBUG(kal_print("ACCESS RIGHT %d\n", ftps_cntx_p->access_right);)
    }

    /* FTPS error flag Init */
    ftps_cntx_p->ftps_flag = 0;
    /* for get cur goep_conn_id in authorize process */
    ftps_cntx_p->cur_goep_conn_id = 0;

    /* Folder Path Init */
    h = FS_Open(FTP_SHARED_FOLDER_PATH_FILE, FS_READ_ONLY);
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_CNTX_INIT_FS_OPEN, h);

    if (h >= FS_NO_ERROR)
    {
        FTP_DEBUG(kal_print("FS_OPEN NO ERROR\n");)
            /* Read the shared folder path to the first connection context */
            res = FS_Read(h, ftps_cntx_p->root_folder, FMGR_MAX_PATH_LEN * ENCODING_LENGTH, &read_length);
        FS_Close(h);

        if (res == FS_NO_ERROR)
        {
            MMI_FTP_LOG1(MMI_BT_FTP_FTPS_CNTX_INIT_FS_READ, res);
            /* copy the same shared folder path between connections */
            for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
            {
                FTP_DEBUG(kal_print("FS_READ NO ERROR\n");)
                mmi_ucs2cpy((PS8) (act_server_cntx_p + i)->current_folder, (PS8) ftps_cntx_p->root_folder);
            }
            /* mmi_bt_ftp_check_folder_existed(ftps_cntx_p->root_folder); */
        }
        else    /* res != FS_NO_ERROR */
        {
            FTP_DEBUG(kal_print("FS_READ ERROR\n");)
            FTPS_MAKE_RECV_PATH(ftps_cntx_p->root_folder);
            for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
            {
                FTPS_MAKE_RECV_PATH((act_server_cntx_p + i)->current_folder);
            }
        }
    }
    else    /* h<FS_NO_ERROR */
    {
        /* first time "empty shared folder file" */
        FTP_DEBUG(kal_print("FS_OPEN ERROR\n");)
        FTPS_MAKE_RECV_PATH(ftps_cntx_p->root_folder);
        /* mmi_bt_ftp_check_folder_existed(ftps_cntx_p->root_folder); */
        for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
        {
            FTPS_MAKE_RECV_PATH((act_server_cntx_p + i)->current_folder);
        }
    }

    for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        /* ID Init */
        ftps_cntx_p->goep_conn_id[i] = 0xFE; /* avoid case: When Client Connecting, BT Reset. disconnect_ind_hdlr*/
        ftps_cntx_p->g_conn_id[i] = 0xFF;

        /* Send/Recv File Handle Init */
        if ((act_server_cntx_p + i)->fh_ftps_send)
        {
            FS_Close((act_server_cntx_p + i)->fh_ftps_send);
            (act_server_cntx_p + i)->fh_ftps_send = (FS_HANDLE) NULL;
        }

        if ((act_server_cntx_p + i)->fh_ftps_recv)
        {
            FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
            (act_server_cntx_p + i)->fh_ftps_recv = (FS_HANDLE) NULL;
        }

        /* FTPS STATE Init */
        (act_server_cntx_p + i)->ftps_state = MMI_FTPS_STATE_IDLE;

        /* Xml_composer Init */
        memset(&((act_server_cntx_p + i)->xml_composer), 0, sizeof(mmi_ftp_file_writer_struct));

        /* bt_device_addr init */
        memset(&((act_server_cntx_p + i)->ftps_bt_device), 0, sizeof(goep_bd_addr_struct));

        /* FTPS obj buffer init */
        memset((act_server_cntx_p + i)->ftps_obj_buff, 0, FTPS_MEM_BUFF_SIZE);

        /* FTPS Obj Name Init */
        memset((act_server_cntx_p + i)->ftps_obj_name, 0, FTP_MAX_OBJ_NAME_LEN);

        /* FTPS Dev Name Init */
        memset((act_server_cntx_p + i)->dev_name, 0, GOEP_MAX_DEV_NAME);

        /* FTPS FOLDER CONTENT FILE Init */
        FTPS_MAKE_FOLDER_CONTENT(((act_server_cntx_p + i)->folder_content), i);

        /* Others Init */
        (act_server_cntx_p + i)->send_obj_type = MMI_FTP_OBJ_TYPE_NONE;
        (act_server_cntx_p + i)->total_send_obj_len = 0;
        (act_server_cntx_p + i)->send_obex_pkt_size = 0;
        (act_server_cntx_p + i)->remain_send_obj_len = 0;

        (act_server_cntx_p + i)->ftps_blink_state = FTPS_BLINK_STATE_IDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_write_obj
 * DESCRIPTION
 *  This function is to write obj to file
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 *  goep_push_ind_struct*, U32(?)
 * RETURNS
 *  int
 *****************************************************************************/
int mmi_bt_ftps_write_obj(goep_push_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *all_path_name_ptr;
    FS_HANDLE h;
    goep_push_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_WRITE_OBJ, ind->pkt_type);

    /* create file to write */
    all_path_name_ptr = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_ASSERT(all_path_name_ptr != NULL);
    memset(all_path_name_ptr, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);

    /* form obj name from context */
    mmi_ucs2cpy((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->current_folder);
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
#endif    
    mmi_ucs2cat((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->ftps_obj_name);

    h = FS_Open((kal_uint16*) all_path_name_ptr, (FS_READ_WRITE | FS_CREATE_ALWAYS));
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_WRITE_OBJ_OPEN, h);
    if (h <= 0)
    {
        /* File open error. Error handling */
        mmi_bt_ftps_set_fs_flag((int) h);
        
        if (all_path_name_ptr)
        {
            OslMfree(all_path_name_ptr);
            all_path_name_ptr = NULL;
        }
        return -1;
    }
    else
    {
        /* set file handle to context */
        (act_server_cntx_p + i)->fh_ftps_recv = h;
    }
    /* Write object context to file */
    if (ind->frag_len > 0)
    {
        U32 len_written;
        int ret;

        ret = FS_Write(h, ind->frag_ptr, ind->frag_len, (kal_uint32*) & len_written);
        MMI_FTP_LOG1(MMI_BT_FTP_FTPS_WRITE_OBJ_WRITE, ret);

        /* Write error */
        if (ret < 0)
        {
            FTP_DEBUG(kal_print("FTPS WRITE OBJ( FS_WRITE ERROR )\n"););
            FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
            FS_Delete((const WCHAR*)all_path_name_ptr);
            (act_server_cntx_p + i)->fh_ftps_recv = 0;

            mmi_bt_ftps_set_fs_flag((int) ret);
                        
            if (all_path_name_ptr)
            {
                OslMfree(all_path_name_ptr);
                all_path_name_ptr = NULL;
            }
            return -1;
        }
    }
    else
    {
        FTP_DEBUG(kal_print("FTPS WRITE OBJ (LEN <= 0)\n"););
    }

    if (all_path_name_ptr)
    {
        OslMfree(all_path_name_ptr);
        all_path_name_ptr = NULL;
    }

    /* check final packet -- if final -> notify MMI Scr */
    if ((ind->pkt_type == GOEP_FINAL_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
    {
        FTP_DEBUG(kal_print("FTPS WRITE OBJ (FINAL_PKT)\n"););
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

        /* Blink Test */
        mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

        /* close file */
        if ((act_server_cntx_p + i)->fh_ftps_recv)
        {
            FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
            (act_server_cntx_p + i)->fh_ftps_recv = 0;
        }
        /* nofify register appications */
        /* call MMI SCR api to notify receive a file */
#if 0
/* under construction !*/
#endif
    }

    /* send push res to client */
    /* send res to goep with success no matter the last packet or not */
    res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->rsp_code = GOEP_STATUS_SUCCESS;
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
    return 1;
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

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_push_obj
 * DESCRIPTION
 *  This function is to push a obj to server
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 *  goep_push_ind_struct*, U32(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_push_obj(goep_push_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *path_buf;
    FS_HANDLE h;
    int ret;
    goep_push_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_PUSH_OBJ);

    /* Check default folder first */
    h = FS_Open((kal_uint16*) ((act_server_cntx_p + i)->current_folder), FS_READ_ONLY | FS_OPEN_DIR);
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PUSH_OBJ_CHECK_FOLDER, h);

    if (h >= FS_NO_ERROR)
    {
        MMI_FTPS_RESET_FLAG(MMIFTP_MASK_FOLDER_ERR);
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else 
    {
        mmi_bt_ftps_set_fs_flag((int) h);
        goto FTPS_PUSH_OBJ_ERR;
    }

    /* check and set file name */
    /* reset and save object name to context */
    memset((act_server_cntx_p + i)->ftps_obj_name, 0, FTP_MAX_OBJ_NAME_LEN);

    if (mmi_ucs2strlen((S8*) ind->obj_name) > 0)
    {
        U8 host_name[GOEP_MAX_OBJ_NAME];
        U8 cut_host_name[FTP_MAX_OBJ_NAME_LEN];

        memset(cut_host_name, 0, FTP_MAX_OBJ_NAME_LEN);

        mmi_bt_ftp_obj_name_swapcpy((PU8)host_name, (PU8)ind->obj_name);
        
        mmi_bt_ftp_ucs2_cut_name_with_ext((U8 *)cut_host_name, FTP_MAX_OBJ_NAME_LEN, (const U8 *)host_name);
        

        if (mmi_ucs2strlen((S8*)cut_host_name) == 0)
        {
            FTP_DEBUG(kal_print("FTPS PUSH OBJ( OBJ_NAME IS ALL SPACE )\n"););            
            kal_wsprintf((kal_uint16*) (act_server_cntx_p + i)->ftps_obj_name, "new.tmp");
        }

        else
        {
            mmi_ucs2cpy((PS8) (act_server_cntx_p + i)->ftps_obj_name, (PS8) cut_host_name);
        }
    }
    /* put obj without carring name */
    else
    {
        FTP_DEBUG(kal_print("FTPS PUSH OBJ( OBJ_NAME == 0 )\n"););            
        kal_wsprintf((kal_uint16*) (act_server_cntx_p + i)->ftps_obj_name, "new.tmp");
    }

    /* Set path and file name, check file exist */
    path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_ASSERT(path_buf != NULL);
    memset(path_buf, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);

    /* check path length */
    mmi_ucs2cpy((PS8) path_buf, (PS8) (act_server_cntx_p + i)->current_folder);
    if (mmi_ucs2strlen((PS8) path_buf) + mmi_ucs2strlen((PS8) (act_server_cntx_p + i)->ftps_obj_name) >
        (FMGR_MAX_PATH_LEN - 1))
    {
        FTP_DEBUG(kal_print("FTPS PUSH OBJ( PATH > FMGR_MAX_PATH_LEN )\n"););            
        if (path_buf)
        {
            OslMfree(path_buf);
        }
        MMI_FTPS_SET_FLAG(MMIFTP_MASK_WRITE_FILE_FAIL);
        goto FTPS_PUSH_OBJ_ERR;
    }

    /* form complete path */
    mmi_ucs2cat((PS8) path_buf, (PS8) (act_server_cntx_p + i)->ftps_obj_name);
    ret = FS_GetAttributes((const WCHAR*)path_buf);
    if (path_buf)
    {
        OslMfree(path_buf);
    }
	/* ret>=0: attr value, file already exists*/
	if ((ret == FS_FILE_NOT_FOUND) || (ret == FS_PATH_NOT_FOUND))
	{
		FTP_DEBUG(kal_print("FTPS PUSH OBJ( file doesn't exist )\n"););  
		/* write file */
	}
	else if(ret < FS_NO_ERROR)
	{
		if (ret == FS_INVALID_FILENAME)
		{
			FTP_DEBUG(kal_print("FTPS PUSH OBJ( Invalid file name )\n"););
			goto FTPS_PUSH_OBJ_ERR;
		}
		else 
		{
			mmi_bt_ftps_set_fs_flag((int) ret);
			goto FTPS_PUSH_OBJ_ERR;
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
#endif

    /* write file */
    ret = mmi_bt_ftps_write_obj(ind, i);

    if (ret < 0)
    {
        goto FTPS_PUSH_OBJ_ERR;
    }
    return;
 
  FTPS_PUSH_OBJ_ERR:
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_PUSH_OBJ_ERR_GOTO);

    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

    /* Blink Test */
    mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

    /* Send response to client */
    /* Construct goep push res ilm */
    res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;

    /* Send MSG_ID_GOEP_PUSH_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);

    mmi_bt_ftps_read_fs_flag_and_popup();

    /* reset FS flag */
    ftps_cntx_p->ftps_flag = 0;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_push_delete
 * DESCRIPTION
 *  This function is to delete a obj from server
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 *  goep_push_ind_struct*, U32(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_push_delete(goep_push_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U8 path_buf[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    goep_push_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Construct goep push res ilm */
    res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

    MMI_FTP_LOG(MMI_BT_FTP_FTPS_PUSH_DELETE);

    if (mmi_ucs2strlen((S8*) ind->obj_name) > 0)
    {
        U8 tmp_name[FTP_MAX_OBJ_NAME_LEN];

        memset(tmp_name, 0, FTP_MAX_OBJ_NAME_LEN);

        /* fail-safe for enough memory to store the obj_name */
        if (mmi_ucs2strlen((const S8*)ind->obj_name) * 2 > (FTP_MAX_OBJ_NAME_LEN - 2))
        {
            MMI_FTP_LOG(MMI_BT_FTP_FTPS_PUSH_DELETE_INVALID_NAME);
            /* send res with error rsp_code internal server error */
            res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
            goto FTPS_PUSH_DELETE_SEND;
        }
        mmi_bt_ftp_obj_name_swapcpy(tmp_name, ind->obj_name);
        mmi_ucs2cpy((PS8) path_buf, (PS8) (act_server_cntx_p + i)->current_folder);

        /* fail-safe for enough memory to store the obj_name + obj_path (2 = '\0','\') */
        if (mmi_ucs2strlen((PS8) path_buf) + mmi_ucs2strlen((PS8) tmp_name) > (FMGR_MAX_PATH_LEN - 1))
        {
            MMI_FTP_LOG(MMI_BT_FTP_FTPS_PUSH_DELETE_INVALID_NAME);
            /* send res with error rsp_code internal server error */
            res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
            goto FTPS_PUSH_DELETE_SEND;
        }
        mmi_ucs2cat((PS8) path_buf, (PS8) tmp_name);
    }
    /* delete obj but without carring name */
    else
    {
        MMI_FTP_LOG(MMI_BT_FTP_FTPS_PUSH_DELETE_WITHOUT_NAME);
        /* send res with rsp_code GOEP_NOT_FOUND */
        res->rsp_code = GOEP_NOT_FOUND;
        goto FTPS_PUSH_DELETE_SEND;
    }

    /* FS_Delete is used to delete file */
    ret = FS_XDelete(
                (WCHAR*) path_buf, 
                FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, 
                NULL, 
                0);
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PUSH_DELETE_FILE, ret);
    if (ret < FS_NO_ERROR)
    {
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;  
        goto FTPS_PUSH_DELETE_SEND;
    }
    res->rsp_code = GOEP_STATUS_SUCCESS;

  FTPS_PUSH_DELETE_SEND:
    /* Send MSG_ID_GOEP_PUSH_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);

    /* change state to accepted */
    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

    /* Blink Test */
    mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_write_obj_continue
 * DESCRIPTION
 *  This function is to create a new folder and set as the current folder
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 *  goep_push_ind_struct* U32(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_write_obj_continue(goep_push_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PUSH_CONTINUE, ind->pkt_type);

    if((act_server_cntx_p + i)->fh_ftps_recv == NULL) /* Cover usb plug in*/
    {
        return;
    }

    /* Write object context to file */
    if (ind->frag_len > 0)
    {
        U32 len_written;
        int ret;

        ret = FS_Write((act_server_cntx_p + i)->fh_ftps_recv, ind->frag_ptr, ind->frag_len, (kal_uint32*) & len_written);
        MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PUSH_CONTINUE_WRITE, ret);
        /* Write error */
        if (ret < 0)
        {
            U8 *all_path_name_ptr;

            /*close file handle, and delete temp file*/
            FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
            (act_server_cntx_p + i)->fh_ftps_recv = 0;

             /*-------------This code will delete the downloading obj when error happens-----BEGIN--------*/
            all_path_name_ptr = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
            MMI_FTP_ASSERT(all_path_name_ptr != NULL);
            memset(all_path_name_ptr, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
            mmi_ucs2cpy((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->current_folder);
            mmi_ucs2cat((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->ftps_obj_name);
            FS_Delete((const WCHAR*)all_path_name_ptr);
            

            if (all_path_name_ptr)
            {
                OslMfree(all_path_name_ptr);
                all_path_name_ptr = NULL;
            }
            /*-------------This code will delete the downloading obj when error happens------END--------*/

            mmi_bt_ftps_set_fs_flag(ret);

            goto FTPS_PUSH_CONTINUE_ERR;
        }
    }

    /* check final packet -- if final -> notify MMI Scr */
    if ((ind->pkt_type == GOEP_FINAL_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
    {
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

        /* Blink Test */
        mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

        /* close file */
        if ((act_server_cntx_p + i)->fh_ftps_recv)
        {
            FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
            (act_server_cntx_p + i)->fh_ftps_recv = 0;
        }

        /* nofify register appications */
        /* call MMI SCR api to notify receive a file */
#if 0
/* under construction !*/
#endif
    }

    /* send res to goep with success no matter the last packet or not */
    res->rsp_code = GOEP_STATUS_SUCCESS;
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
    return;

  FTPS_PUSH_CONTINUE_ERR:

    FTP_DEBUG(kal_print("FTPS PUSH CONTINUE ERR (GOTO)\n"););    
    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

    /* Blink Test */
    mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

    /* send push res to client */
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);

   mmi_bt_ftps_read_fs_flag_and_popup();

    /* reset FS flag */
    ftps_cntx_p->ftps_flag = 0;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_create_folder
 * DESCRIPTION
 *  This function is to create a new folder and set as the current folder
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 *  goep_set_folder_ind_struct*, U32(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_create_folder(goep_set_folder_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U8 all_path_name[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    U8 cut_host_name[FTP_MAX_OBJ_NAME_LEN];
    goep_set_folder_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_CREATE_FOLDER, ftps_cntx_p->goep_conn_id[i]);
    res = (goep_set_folder_res_struct*) OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

    /* Check the access right first. If the access right is read only, return failed directly */
    if (ftps_cntx_p->access_right == MMI_FTP_ACCESS_RIGHT_READ_ONLY)
    {
        /* Wrong Access Right */
        res->rsp_code = GOEP_UNAUTHORIZED;
        goto FTPS_CREATE_FOLDER_SEND;
    }

    /* check the folder name */
    if (mmi_ucs2strlen((S8*) ind->folder_name) > 0)
    {
        U8 host_name[GOEP_MAX_FOLDER_NAME];
        FTP_DEBUG(kal_print("FTPS CREATE FOLDER ( NAME > 0 )\n"););

        memset(cut_host_name, 0, FTP_MAX_OBJ_NAME_LEN);

        mmi_bt_ftp_obj_name_swapcpy((PU8)host_name, (PU8)ind->folder_name);
        mmi_bt_ftp_ucs2_cut_name_without_ext((U8 *) cut_host_name, FTP_MAX_OBJ_NAME_LEN, (const U8 *) host_name);

        if (mmi_ucs2strlen((S8*)cut_host_name) == 0)
        {
            kal_wsprintf((kal_uint16*) cut_host_name, "new_folder");
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
#endif

    }
    else    /* form a new_folder in current path */
    {
        FTP_DEBUG(kal_print("FTPS CREATE FOLDER ( NAME == 0 )\n"););
        memset(cut_host_name, 0, FTP_MAX_OBJ_NAME_LEN);
        kal_wsprintf((kal_uint16*) cut_host_name, "new_folder");
    }

    /* form folder path */
    mmi_ucs2cpy((PS8) all_path_name, (PS8) ((act_server_cntx_p + i)->current_folder));
    if (mmi_ucs2strlen((PS8) all_path_name) + mmi_ucs2strlen((PS8) cut_host_name) > (FMGR_MAX_PATH_LEN - 2))
    {
        /* send res to client with rsp_code server internal error */
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        goto FTPS_CREATE_FOLDER_SEND;
    }
    mmi_ucs2cat((PS8) all_path_name, (PS8) cut_host_name);
    mmi_ucs2cat((PS8) all_path_name, (const S8*)L"\\");

    ret = FS_CreateDir((WCHAR*) all_path_name);
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_CREATE_FOLDER_CREATE_DIR, ret);

    if ((ret < 0) && (ret != FS_FILE_EXISTS))
    {
        FTP_DEBUG(kal_print("FTPS CREATE FOLDER ( FS_CREATEDIR ERROR )\n"););        
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        goto FTPS_CREATE_FOLDER_SEND;
    }
    else
    {
        mmi_ucs2cpy((PS8) ((act_server_cntx_p + i)->current_folder), (PS8) all_path_name);
        res->rsp_code = GOEP_STATUS_SUCCESS;
        goto FTPS_CREATE_FOLDER_SEND;
    }

  FTPS_CREATE_FOLDER_SEND:
    /* Send MSG_ID_GOEP_SET_FOLDER_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_set_folder
 * DESCRIPTION
 *  This function is to set current folder to selected folder
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 *  goep_set_folder_ind_struct*,U32(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_set_folder(goep_set_folder_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 folder_name[FTP_MAX_OBJ_NAME_LEN];
    U8 new_folder[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    goep_set_folder_res_struct *res;
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_SET_FOLDER, ftps_cntx_p->goep_conn_id[i]);
    res = (goep_set_folder_res_struct*) OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

    memset(folder_name, 0, FTP_MAX_OBJ_NAME_LEN);
    memset(new_folder, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    /* if folder name == NULL --> assert */
    if (ind->folder_name == NULL)
    {
        /* can't forward a NULL folder goep should avoid it */
        MMI_FTP_ASSERT(0);
    }

    /* fail-safe for enough memory to store the folder_name */
    if (mmi_ucs2strlen((PS8) (ind->folder_name)) * 2 > FTP_MAX_OBJ_NAME_LEN - 2)
    {
        FTP_DEBUG(kal_print("FTPS SET FOLDER CARRING INVALID FOLDER NAME\n"););
        /* send res with error rsp_code not found */
        res->rsp_code = GOEP_NOT_FOUND;
        goto FTPS_SET_FOLDER_SEND;
    }

    mmi_bt_ftp_obj_name_swapcpy(folder_name, ind->folder_name);
    /* not parent or current folder */
    if ((mmi_ucs2cmp((PS8) folder_name, (PS8) L".") != 0) &&
        (mmi_ucs2cmp((PS8) folder_name, (PS8) L"..") != 0))
    {
        mmi_ucs2cpy((PS8) new_folder, (PS8) ((act_server_cntx_p + i)->current_folder));
        /* fail-safe for enough memory to store the folder_name + folder_path (2 = '\0','\') */
        if (mmi_ucs2strlen((PS8) new_folder) + mmi_ucs2strlen((PS8) folder_name) > (FMGR_MAX_PATH_LEN - 2))
        {
            FTP_DEBUG(kal_print("FTPS SET FOLDER CARRING INVALID FOLDER NAME\n"););
            /* send res with error rsp_code not found */
            res->rsp_code = GOEP_NOT_FOUND;
            goto FTPS_SET_FOLDER_SEND;
        }

        /* form folder path */
        mmi_ucs2cat((PS8) new_folder, (PS8) folder_name);
        mmi_ucs2cat((PS8) new_folder, (const PS8)L"\\");

        h = FS_Open((kal_uint16*) new_folder, FS_READ_ONLY | FS_OPEN_DIR);
        /* if folder exist, set folder send res */
        if (h >= FS_NO_ERROR)
        {
            FS_Close(h);
            mmi_ucs2cpy((PS8) ((act_server_cntx_p + i)->current_folder), (PS8) new_folder);

            /* Send success response to client */
            res->rsp_code = GOEP_STATUS_SUCCESS;
            goto FTPS_SET_FOLDER_SEND;
        }
        else    /* FS_PATH_NOT_FOUND */
        {
            FTP_DEBUG(kal_print("FTPS SET FOLDER ( FS_OPEN ERROR )\n"););
            /* send res with error rsp_code not found */
            res->rsp_code = GOEP_NOT_FOUND;
            goto FTPS_SET_FOLDER_SEND;
        }
    }
    /* go to parent folder */
    else if (mmi_ucs2cmp((PS8) folder_name, (PS8) L"..") == 0)
    {
        /* call set parent folder routine */
        MMI_FTP_ASSERT(res);
        OslFreeDataPtr(res);
        mmi_bt_ftps_set_parent_folder(i);
        return;
    }
    /* current folder */
    else
    {
        /* Send success response to client */
        res->rsp_code = GOEP_STATUS_SUCCESS;
        goto FTPS_SET_FOLDER_SEND;
    }
  FTPS_SET_FOLDER_SEND:
    /* Send MSG_ID_GOEP_SET_FOLDER_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_set_parent_folder
 * DESCRIPTION
 *  This function is to set current folder to parent folder
 * PARAMETERS
 *  i       [IN]        
 *  U32(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_set_parent_folder(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_set_folder_res_struct *res;
    S32 NameLength;
    U16 *UniPathName = 0; 
    U16 deter = '\\';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_SET_PARENT_FOLDER, ftps_cntx_p->goep_conn_id[i]);

    res = (goep_set_folder_res_struct*) OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

    NameLength = mmi_ucs2strlen((PS8) ((act_server_cntx_p + i)->current_folder));
    UniPathName = get_ctrl_buffer((NameLength + 1) * ENCODING_LENGTH);
    if(!UniPathName)
    {
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
        return;
    }
    mmi_ucs2cpy((S8 * )UniPathName, (S8 *) ((act_server_cntx_p + i)->current_folder));
    

    /* UniPathName+i points to the (i+1)th ascii code in path --> minus one first */
    NameLength--;
    while (NameLength > 0)
    {
        /* search from tail by cutting the last ascii code step by step */
        NameLength--;
        if (memcmp((UniPathName + NameLength), &deter, 2) == 0)
        {
            /* Cut the current folder path to become parent folder path */
            memset((UniPathName + NameLength + 1), 0, 2);
            break;
        }
    }


    /* path is not valid */
    if ((mmi_ucs2ncmp(
                (const S8*)UniPathName,
                (const S8*)(ftps_cntx_p->root_folder),
                mmi_ucs2strlen((PS8) ftps_cntx_p->root_folder)) != 0)
                || (NameLength == 0))
    {
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
    }
    else
    {
        FS_HANDLE temp_current_path_fh = FS_Open((WCHAR *)UniPathName, FS_READ_ONLY | FS_OPEN_DIR);
        
        if(temp_current_path_fh >= FS_NO_ERROR)
        {
            FS_Close(temp_current_path_fh);
            mmi_ucs2cpy((S8 *)((act_server_cntx_p + i)->current_folder), (S8 *)UniPathName);
            res->rsp_code = GOEP_STATUS_SUCCESS;
        }
        else 
        {
            res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
        }
    }
    
    if(UniPathName)
    {
        free_ctrl_buffer(UniPathName);
    }
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_pull_continue
 * DESCRIPTION
 *  This function is to keeping sending the pending object requested from client
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_pull_continue(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U32 len_read;
    goep_pull_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PULL_CONTINUE, ftps_cntx_p->goep_conn_id[i]);

    ret = FS_Read(
            (act_server_cntx_p + i)->fh_ftps_send,
            (act_server_cntx_p + i)->ftps_obj_buff,
            (act_server_cntx_p + i)->send_obex_pkt_size,
            (kal_uint32*) & len_read);
    /* FS error */
    if (ret < 0)
    {
        FTP_DEBUG(kal_print("FTPS SEND CONTINUE FS_Read error\n");)
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
        mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
        
        FS_Close((act_server_cntx_p + i)->fh_ftps_send);
        (act_server_cntx_p + i)->total_send_obj_len = 0;
        (act_server_cntx_p + i)->remain_send_obj_len = 0;
        (act_server_cntx_p + i)->fh_ftps_send = 0;

        if ((act_server_cntx_p + i)->send_obj_type == MMI_FTP_OBJ_TYPE_FOLDER)
        {
            FTP_DEBUG(kal_print("FTPS SEND CONTINUE ERR (FOLDER)\n");)
                /* delete the folder content file */
                FS_Delete((const WCHAR*)((act_server_cntx_p + i)->folder_content));
        }
        (act_server_cntx_p + i)->send_obj_type = MMI_FTP_OBJ_TYPE_NONE;

        /* Construct goep pull res ilm */
        res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;

        /* Send MSG_ID_GOEP_PULL_RES primitive */
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
        return;
    }

    /* Finished reading */
    if (len_read == (act_server_cntx_p + i)->remain_send_obj_len)
    {
        FTP_DEBUG(kal_print("FTPS SEND CONTINUE (LAST PACKET)\n");)
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

        /* Blink Test */
        mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
        
        FS_Close((act_server_cntx_p + i)->fh_ftps_send);
        (act_server_cntx_p + i)->total_send_obj_len = 0;
        (act_server_cntx_p + i)->remain_send_obj_len = 0;
        (act_server_cntx_p + i)->fh_ftps_send = 0;

        if ((act_server_cntx_p + i)->send_obj_type == MMI_FTP_OBJ_TYPE_FOLDER)
        {
            FTP_DEBUG(kal_print("FTPS SEND CONTINUE FINAL FOLDER PKT\n");)
                /* delete the folder content file */
                FS_Delete((const WCHAR*)((act_server_cntx_p + i)->folder_content));
        }
        (act_server_cntx_p + i)->send_obj_type = MMI_FTP_OBJ_TYPE_NONE;

        /* film res pkt_type attibute */
        res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->pkt_type = GOEP_FINAL_PKT;
    }

    /* continue transferring */
    else if (len_read < (act_server_cntx_p + i)->remain_send_obj_len)
    {

        FTP_DEBUG(kal_print("FTPS SEND CONTINUE (NORMAL PACKET)\n");)
        (act_server_cntx_p+i)->remain_send_obj_len  -= len_read;      
        /* film res pkt_type attibute */
        res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->pkt_type = GOEP_NORMAL_PKT;
    }

    /* abnormal case */
    else
    {
        FTP_DEBUG(kal_print("FTPS SEND CONTINUE (ABNORMAL CASE)\n");)
        MMI_FTP_ASSERT(0);
        return;
    }

    /* film remaining res attibutes */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->frag_len = len_read;
    res->frag_ptr = (act_server_cntx_p + i)->ftps_obj_buff;
    res->total_obj_len = 0;
    res->rsp_code = GOEP_STATUS_SUCCESS;

    /* send res to client */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_send_obj
 * DESCRIPTION
 *  This function is to send the obj requested from client
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_send_obj(goep_pull_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_res_struct *res;
    int ret;
    kal_uint32 fileSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_SEND_OBJ, ftps_cntx_p->goep_conn_id[i]);

    /* Reset the context first */
    (act_server_cntx_p + i)->total_send_obj_len = 0;
    (act_server_cntx_p + i)->remain_send_obj_len = 0;

    ret = FS_GetFileSize((act_server_cntx_p + i)->fh_ftps_send, &fileSize);

    if(ret != FS_NO_ERROR)
    {
        /* Construct goep pull res ilm */
        res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->rsp_code = GOEP_INTERNAL_SERVER_ERR;

        /* Send MSG_ID_GOEP_PULL_RES primitive */
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
        mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
        return;
    }
    
    /* not empty obj */
    if (fileSize > 0)
    {
        /* goep can't handle first res pkt with data */
        FTP_DEBUG(kal_print("FTPS SEND OBJ (RES FIRST PKT)\n");)
        (act_server_cntx_p+i)->total_send_obj_len   = fileSize;
        (act_server_cntx_p + i)->remain_send_obj_len = fileSize;
        (act_server_cntx_p + i)->send_obj_type = MMI_FTP_OBJ_TYPE_FILE;

        /* film res pkt_type attibute */
        res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->pkt_type = GOEP_FIRST_PKT;
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->frag_len = 0;
        res->frag_ptr = (act_server_cntx_p + i)->ftps_obj_buff;
        res->total_obj_len = fileSize;
        res->rsp_code = GOEP_STATUS_SUCCESS;
    }
    /* Empty body */
    else
    {
        FTP_DEBUG(kal_print("FTPS SEND OBJ (EMPTY FOLDER CONTENT FILE)\n");)
            /* film res pkt_type attibute */
            res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->pkt_type = GOEP_SINGLE_PKT;
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->frag_len = 0;
        res->frag_ptr = (act_server_cntx_p + i)->ftps_obj_buff;
        res->total_obj_len = 0;
        res->rsp_code = GOEP_STATUS_SUCCESS;

        FS_Close((act_server_cntx_p + i)->fh_ftps_send);
        (act_server_cntx_p + i)->fh_ftps_send = 0;

        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
        mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
    }
    /* send res to client */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_send_folder_content
 * DESCRIPTION
 *  This function is to send the folder content requested from client
 * PARAMETERS
 *  ind     [?]         
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_send_folder_content(goep_pull_ind_struct *ind, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    goep_pull_res_struct *res;
    int ret;
    kal_uint32 fileSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_SEND_FOLDER_CONTENT, ftps_cntx_p->goep_conn_id[i]);

    /* Reset the context first */
    (act_server_cntx_p + i)->total_send_obj_len = 0;
    (act_server_cntx_p + i)->remain_send_obj_len = 0;

    /* open the default folder content file */
    h = FS_Open((kal_uint16*) ((act_server_cntx_p + i)->folder_content), FS_READ_ONLY);
    if (h < 0)
    {
        MMI_FTP_LOG(MMI_BT_FTP_FTPS_SEND_FOLDER_CONTENT_OPEN_ERROR);
        /* File open error. Error handling */
        goto FTPS_SEND_FOLDER_CONTENT_ERR;
    }
    else
    {
        (act_server_cntx_p + i)->fh_ftps_send = h;
    }

    ret = FS_GetFileSize(h, &fileSize);
    /* not empty folder content */
    if (fileSize > 0)
    {
        /* goep can't handle first res pkt with data */
        FTP_DEBUG(kal_print("FTPS SEND FOLDER CONTENT (RES FIRST PKT)\n");)
        (act_server_cntx_p+i)->total_send_obj_len   = fileSize;
        (act_server_cntx_p + i)->remain_send_obj_len = fileSize;
        (act_server_cntx_p + i)->send_obj_type = MMI_FTP_OBJ_TYPE_FOLDER;

        /* film res pkt_type attibute */
        res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->pkt_type = GOEP_FIRST_PKT;
        res->total_obj_len = fileSize;
    }
    /* Empty body */
    else
    {
        FTP_DEBUG(kal_print("FTPS SEND FOLDER CONTENT (EMPTY FOLDER CONTENT FILE)\n");)
            /* film res pkt_type attibute */
            res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->pkt_type = GOEP_FINAL_PKT;
        res->total_obj_len = 0;
        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
        /* Blink Test */
        FS_Delete((const WCHAR*)((act_server_cntx_p + i)->folder_content));
    }

    strcpy((PS8) res->obj_mime_type, "x-obex/folder-listing");
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->frag_ptr = (act_server_cntx_p + i)->ftps_obj_buff;
    res->frag_len = 0;
    res->rsp_code = GOEP_STATUS_SUCCESS;

    /* send res to client */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
    return;
  FTPS_SEND_FOLDER_CONTENT_ERR:

    FS_Delete((const WCHAR*)((act_server_cntx_p + i)->folder_content));

    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

    /* Construct goep pull res ilm */
    res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
    strcpy((PS8) res->obj_mime_type, "x-obex/folder-listing");

    /* Send MSG_ID_GOEP_PULL_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_gen_folder_content
 * DESCRIPTION
 *  This function is to generate the folder content requested from client
 * PARAMETERS
 *  index           [IN]        
 *  folder_name     [IN]        
 * RETURNS
 *  int
 *****************************************************************************/
static int mmi_bt_ftps_gen_folder_content(U32 index, PU8 folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftp_file_writer_struct *composer = &((act_server_cntx_p + index)->xml_composer);
    FS_DOSDirEntry fs_file_info;
    mmi_ftp_obj_info_struct ftp_file_info;
    UI_character_type file_name[FMGR_MAX_FILE_LEN + 1];
    int result = 0;
    int i;
    U8 tmp_path_buf[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS GEN FOLDER CONTENT\n");)
        /* continue generating folder content */
        if (*folder_name == 0)
    {
        FTP_DEBUG(kal_print("FTPS GEN FOLDER (CONTINUE WRITE))\n");)
        i = 0;
        fs_file_info.Attributes = FS_ATTR_SYSTEM;
        goto CONTINUE_WRITE_FOLDER_CONTENT;
    }

    /* Composer initialization */
    memset(composer, 0, sizeof(mmi_ftp_file_writer_struct));

    composer->buflen += sprintf(composer->buf + composer->buflen, "<?xml version=\"1.0\"?>\n");
    composer->buflen += sprintf(composer->buf + composer->buflen, "<!DOCTYPE folder-listing SYSTEM \"obex-folder-listing.dtd\">\n");
    composer->buflen += sprintf(composer->buf + composer->buflen, "<folder-listing version=\"1.0\">\n");

    /* If the selecting folder is not root folder, represent the parent folder */
    if (mmi_ucs2cmp((PS8) folder_name, (PS8) ftps_cntx_p->root_folder))
    {
        composer->buflen += sprintf(composer->buf + composer->buflen, "<parent-folder />\n");
    }

    /* which means the files in folder "folder_path" */
    mmi_ucs2cat((S8*) folder_name, (const S8*)L"*.*");

    composer->fd = FS_Open((const WCHAR*)((act_server_cntx_p + index)->folder_content), FS_READ_WRITE | FS_CREATE_ALWAYS);
    /* FS error */
    if (composer->fd < 0)
    {
        return composer->fd;
    }

    /* starting to get content */
    /* if there is the file info -> write content */
    if (((act_server_cntx_p + index)->fh_ftps_generating = FS_FindFirst(
                                                            (WCHAR*) folder_name,
                                                            0,
                                                            0,
                                                            &fs_file_info,
                                                            file_name,
                                                            (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH)) >=
        0)
    {
        i = 0;
        do
        {
          CONTINUE_WRITE_FOLDER_CONTENT:
            /* if this file should be included in folder content */
            if ((fs_file_info.Attributes & (FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
            {
                i++;
                /* save obj name and info */
                /* FS file attribut for different encodeed file */
                if (fs_file_info.NTReserved == FS_SFN_MATCH)
                {
                    mmi_chset_mixed_text_to_ucs2_str(
                        (U8*) tmp_path_buf,
                        (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH,
                        (U8*) file_name,
                        PhnsetGetDefEncodingType());
                    mmi_chset_ucs2_to_utf8_string(
                        (U8*) ftp_file_info.file_name,
                        FMGR_MAX_PATH_LEN * ENCODING_LENGTH,
                        (U8*) tmp_path_buf);
                }
                else
                {
                    mmi_chset_ucs2_to_utf8_string(
                        (U8*) ftp_file_info.file_name,
                        FMGR_MAX_PATH_LEN * ENCODING_LENGTH,
                        (U8*) file_name);
                }

                ftp_file_info.year = fs_file_info.DateTime.Year1980 + 1980;
                ftp_file_info.month = fs_file_info.DateTime.Month;
                ftp_file_info.day = fs_file_info.DateTime.Day;
                ftp_file_info.hour = fs_file_info.DateTime.Hour;
                ftp_file_info.min = fs_file_info.DateTime.Minute;
                ftp_file_info.sec = fs_file_info.DateTime.Second2;
                ftp_file_info.file_size = fs_file_info.FileSize;

                /* If the file_info is a folder */
                if (fs_file_info.Attributes & FS_ATTR_DIR)
                {
                    result = mmi_bt_ftps_compose_folder_element(composer, &ftp_file_info);
                    /* FS_Write error */
                    if (result < 0)
                    {
                        FS_FindClose((act_server_cntx_p + index)->fh_ftps_generating);
                        FS_Close(composer->fd);
                        return result;
                    }
                    /* result >= 0 */
                    if (i > FTP_MAX_PARSE_FILE_INFO_NUMBER)
                    {
                        if (composer->buflen > 0)
                        {
                            result = FS_Write(composer->fd, composer->buf, composer->buflen, &(composer->written));

                            if (result < 0)
                            {
                                FS_FindClose((act_server_cntx_p + index)->fh_ftps_generating);
                                FS_Close(composer->fd);
                                return result;
                            }
                        }
                        kal_mem_set(composer->buf, 0, FTP_MAX_FILE_WRITER_BUF_SIZE);
                        composer->buflen = 0;
                        composer->written = 0;
                        return i;
                    }
                }
                /* the file info is a file */
                else
                {
                    result = mmi_bt_ftps_compose_file_element(composer, &ftp_file_info);
                    /* FS_Writer error */
                    if (result < 0)
                    {
                        FS_FindClose((act_server_cntx_p + index)->fh_ftps_generating);
                        FS_Close(composer->fd);
                        return result;
                    }
                    if (i > FTP_MAX_PARSE_FILE_INFO_NUMBER)
                    {
                        if (composer->buflen > 0)
                        {
                            result = FS_Write(composer->fd, composer->buf, composer->buflen, &(composer->written));
                            if (result < 0)
                            {
                                FS_FindClose((act_server_cntx_p + index)->fh_ftps_generating);
                                FS_Close(composer->fd);
                                return result;
                            }
                        }
                        kal_mem_set(composer->buf, 0, FTP_MAX_FILE_WRITER_BUF_SIZE);
                        composer->buflen = 0;
                        composer->written = 0;
                        return i;
                    }
                }
            }
        } while (FS_FindNext
                 ((act_server_cntx_p + index)->fh_ftps_generating, &fs_file_info, file_name,
                  (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH) == FS_NO_ERROR);
        FS_FindClose((act_server_cntx_p + index)->fh_ftps_generating);
    }
    result = mmi_bt_ftps_compose_end_element(composer, &ftp_file_info);

    /* result == 0 means FS_Write >= threshold success */
    if (!result)
    {
        /* write the remaining content */
        result = FS_Write(composer->fd, composer->buf, composer->buflen, &(composer->written));
    }
    FS_Close(composer->fd);
    /* result !=0 means FS error */
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_compose_folder_element
 * DESCRIPTION
 *  This function is to compose the folder attributes
 * PARAMETERS
 *  composer        [?]     [?]
 *  file_info       [?]     [?]
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  The result of composing the folder attributes
 *****************************************************************************/
static int mmi_bt_ftps_compose_folder_element(
            mmi_ftp_file_writer_struct *composer,
            mmi_ftp_obj_info_struct *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = 0;

    FTP_DEBUG(kal_print("FTPS COMPOSE FOLDER ELEMENT\n");)
        /* not root folder and not parent folder */
        if ((strcmp((PS8) file_info->file_name, ".") != 0) && (strcmp((PS8) file_info->file_name, "..") != 0))
    {
        FTP_DEBUG(kal_print("FTPS COMPOSE FOLDER ELEMENT (WRITE TO BUFFER)\n");)
        composer->buflen += sprintf(
                                    composer->buf + composer->buflen,
                                    "\t<folder name=\"%s\" created=\"%04d%02d%02dT%02d%02d%02dZ\"/>\n",
                                    file_info->file_name,
                                    file_info->year,
                                    file_info->month,
                                    file_info->day,
                                    file_info->hour,
                                    file_info->min,
                                    file_info->sec);
        result = mmi_bt_ftp_write_buf2file(composer);
    }
    /* root, parent folder won't write to file and return 0 */
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_compose_file_element
 * DESCRIPTION
 *  This function is to compose the file attributes
 * PARAMETERS
 *  composer        [?]     [?]
 *  file_info       [?]     [?]
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  The result of composing the file attributes
 *****************************************************************************/
static int mmi_bt_ftps_compose_file_element(mmi_ftp_file_writer_struct *composer, mmi_ftp_obj_info_struct *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS COMPOSE FILE ELEMENT\n");)
    composer->buflen += sprintf(
                                composer->buf + composer->buflen,
                                "\t<file name=\"%s\" modified=\"%04d%02d%02dT%02d%02d%02dZ\" size=\"%d\" user-perm=\"%s\"/>\n",
                                file_info->file_name,
                                file_info->year,
                                file_info->month,
                                file_info->day,
                                file_info->hour,
                                file_info->min,
                                file_info->sec,
                                file_info->file_size,
                                ftps_cntx_p->access_right ? "R" : "RWD");
    result = mmi_bt_ftp_write_buf2file(composer);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_compose_end_element
 * DESCRIPTION
 *  This function is to compose the end tag
 * PARAMETERS
 *  composer        [?]     [?]
 *  file_info       [?]     [?]
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  The result of composing the end tag
 *****************************************************************************/
static int mmi_bt_ftps_compose_end_element(mmi_ftp_file_writer_struct *composer, mmi_ftp_obj_info_struct *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS COMPOSE END ELEMENT\n");)
    composer->buflen += sprintf(composer->buf + composer->buflen, "</folder-listing>");
    result = mmi_bt_ftp_write_buf2file(composer);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_find_goep_id
 * DESCRIPTION
 *  This function is to find the goep_id from ftps context
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
U32 mmi_bt_ftps_find_goep_id(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS FIND INDEX\n");)
        /* fine the index */
        for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        if (ftps_cntx_p->goep_conn_id[i] == index)
        {
            return i;
        }
    }

    /* index is not correct */
    MMI_FTP_LOG2(MMI_BT_FTP_FTPS_FIND_GOEP_ID_FAILED, ftps_cntx_p->goep_conn_id[0], index);
    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_pull_stop_icon_timer_expire_hdler
 * DESCRIPTION
 *  This function is to find the goep_id from ftps context
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static void mmi_bt_ftps_pull_stop_icon_timer_expire_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_ICON_STOP_TIMER);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (act_server_cntx_p->ftps_blink_state)
    {
    case FTPS_BLINK_STATE_PROTECTED:
        act_server_cntx_p->ftps_blink_state = FTPS_BLINK_STATE_SAFE;
        break;
    case FTPS_BLINK_STATE_STOP_NEEDED:
        mmi_bt_status_icon_stop_blinking(MMI_BTH_OBEX_FILE_TRANSFER_UUID, MMI_BT_SERVER_ROLE);
        act_server_cntx_p->ftps_blink_state = FTPS_BLINK_STATE_IDLE;
        break;
    default:
        MMI_FTP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_read_fs_flag_and_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static void mmi_bt_ftps_read_fs_flag_and_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_READ_FS_FLAG);
    if (MMI_FTPS_GET_FLAG(MMIFTP_MASK_ROOT_DIR_FULL) == MMI_TRUE)
    {
        /* Notify Root Directory full Screen */
        mmi_bt_ftps_popup(MMIFTP_MASK_ROOT_DIR_FULL);
    }
    else if (MMI_FTPS_GET_FLAG(MMIFTP_MASK_DISK_FULL) == MMI_TRUE)
    {
        /* Notify Disk full Screen */
        mmi_bt_ftps_popup(MMIFTP_MASK_DISK_FULL);
    }
#ifdef __USB_IN_NORMAL_MODE__
    else if (MMI_FTPS_GET_FLAG(MMIFTP_MASK_DEVICE_EXPORTED) == MMI_TRUE)
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    else if ((MMI_FTPS_GET_FLAG(MMIFTP_MASK_FS_DEVICE_BUSY) == MMI_TRUE)
                 || (MMI_FTPS_GET_FLAG(MMIFTP_MASK_FS_LOCK_MUTEX_FAIL) == MMI_TRUE))
    {
        /* Notify Write File Fail Screen */
        mmi_bt_ftps_popup(MMIFTP_MASK_FS_DEVICE_BUSY);
    }
    else if(ftps_cntx_p->ftps_flag != 0)
    {
        /* Notify Write File Fail Screen */
        mmi_bt_ftps_popup(MMIFTP_MASK_WRITE_FILE_FAIL);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_set_fs_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static void mmi_bt_ftps_set_fs_flag(int ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_SET_FS_FLAG);
    
    if (ret == FS_ROOT_DIR_FULL)
    {
        MMI_FTPS_SET_FLAG(MMIFTP_MASK_ROOT_DIR_FULL);
    }
    else if (ret == FS_DISK_FULL)
    {
        MMI_FTPS_SET_FLAG(MMIFTP_MASK_DISK_FULL);
    }
#ifdef __USB_IN_NORMAL_MODE__
    else if (ret == FS_DEVICE_EXPORTED_ERROR)
    {
        MMI_FTPS_SET_FLAG(MMIFTP_MASK_DEVICE_EXPORTED);
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    else if(ret == FS_DEVICE_BUSY)
    {
        MMI_FTPS_SET_FLAG(MMIFTP_MASK_FS_DEVICE_BUSY);
    }
    else if(ret == FS_LOCK_MUTEX_FAIL)
    {
        MMI_FTPS_SET_FLAG(MMIFTP_MASK_FS_LOCK_MUTEX_FAIL);
    }
    else
    {
        MMI_FTPS_SET_FLAG(MMIFTP_MASK_WRITE_FILE_FAIL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_usb_plugin_hdle
 * DESCRIPTION
 *  when usb mass plug in, this func will be called
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftps_usb_plugin_hdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*mmi_bth_bt_addr bd_addr;*/
    U8 *all_path_name_ptr = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPS_USB_PLUG_IN);
    switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_RECEIVING:
            /*close pushed file handle*/
            if ((act_server_cntx_p + i)->fh_ftps_recv)
            {
                FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
                (act_server_cntx_p + i)->fh_ftps_recv = 0;
            }

            /* delete pushed file*/
            all_path_name_ptr = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
            if(all_path_name_ptr == NULL)
            {
                return;
            }
            mmi_ucs2cpy((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->current_folder);
            mmi_ucs2cat((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->ftps_obj_name);
            FS_Delete((const WCHAR*)all_path_name_ptr);
            if(all_path_name_ptr)
            {
                OslMfree(all_path_name_ptr);
                all_path_name_ptr = NULL;
            }
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);            

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            return;

    }    
}

#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_cntx_init
 * DESCRIPTION
 *  This function is to initialize FTPC context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_CNTX_INIT);

    /* ftpc context init */
    ftpc_cntx_p->ftpc_flag = 0;
    ftpc_cntx_p->curr_idx = 0xFF;

    for (i = 0; i < FTP_MAX_SERVER_SUPPORT; i++)
    {
        ftpc_cntx_p->goep_conn_id[i] = 0xFF;
        ftpc_cntx_p->req_id[i] = 0xFF;
        ftpc_cntx_p->g_conn_id[i] = 0xFF;

        (act_client_cntx_p + i)->got_root = 0;
        (act_client_cntx_p + i)->browse_depth = 0;
        (act_client_cntx_p + i)->total_recv_obj_len = 0;
        (act_client_cntx_p + i)->remain_recv_obj_len = 0;
        (act_client_cntx_p + i)->entity_cnt_cur_folder = 0;
        (act_client_cntx_p + i)->xml_parser_p = NULL;
        (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
        (act_client_cntx_p + i)->ftpc_state = MMI_FTPC_STATE_IDLE;
        (act_client_cntx_p + i)->recved_obj_len = 0;
        (act_client_cntx_p + i)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;

        FTPC_MAKE_FOLDER_OBJECT((act_client_cntx_p + i)->folder_obj, i);
        FTPC_MAKE_FOLDER_PARSED((act_client_cntx_p + i)->parsed_folder, i);

        memset((act_client_cntx_p + i)->ftpc_obj_name, 0, FTP_MAX_OBJ_NAME_LEN);
        memset(&((act_client_cntx_p + i)->ftpc_bt_device), 0, sizeof(goep_bd_addr_struct));
        memset(&((act_client_cntx_p + i)->obj_entity), 0, sizeof(mmi_ftp_obj_entity_struct));
        memset(&(act_client_cntx_p + i)->folder_content, 0, sizeof(mmi_ftp_file_writer_struct));

        mmi_bt_ftpc_reset_abort_req_sent_flag();

        /* get the shared buffer for ftpc*/
        (act_client_cntx_p + i)->ftpc_obj_buff = (U8*)mmi_bt_obex_get_profile_shared_buffer();
        MMI_FTP_ASSERT((act_client_cntx_p + i)->ftpc_obj_buff);
        memset((act_client_cntx_p + i)->ftpc_obj_buff, 0, MMI_OBEX_PROFILE_SHARE_BUF_SIZE);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_received_folder_init
 * DESCRIPTION
 *  This function is to create FTC received folder if not exist.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS :(?)
 *****************************************************************************/
void mmi_bt_ftpc_received_folder_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_RECEIVED_FOLDER_INIT);

#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        FTP_DEBUG(kal_print("FTPC RECEIVED FOLDER INIT (NVRAM_IN_USB_MS)\n");)
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    ftpc_cntx_p->ftpc_flag = 0;

    /* build default path */
    FTPC_MAKE_RECV_PATH(nPrintableStr);

    h = FS_Open((kal_uint16*) nPrintableStr, FS_READ_ONLY | FS_OPEN_DIR);
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_RECEIVED_FOLDER_INIT_OPEN, h);
    if ((h >= FS_NO_ERROR) || (h == FS_FILE_EXISTS))
    {
        FTP_DEBUG(kal_print("FTPC RECEIVED FOLDER INIT -- FS_OPEN NO ERROR\n");)
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((kal_uint16*) nPrintableStr);
        MMI_FTP_LOG1(MMI_BT_FTP_FTPC_RECEIVED_FOLDER_INIT_CREATE, ret);
        if (ret == FS_NO_ERROR)
        {
            FTP_DEBUG(kal_print("FTPC RECEIVED FOLDER INIT -- FS_OPEN NO ERROR\n");)
            MMI_FTPC_RESET_FLAG(MMIFTP_MASK_FOLDER_ERR);
            MMI_FTPC_RESET_FLAG(MMIFTP_MASK_FS_SANITY);
        }
        else if (ret == FS_DISK_FULL)
        {
            FTP_DEBUG(kal_print("FTPC RECEIVED FOLDER INIT -- ERROR DISK FULL\n");)
            MMI_FTPC_SET_FLAG(MMIFTP_MASK_DISK_FULL);
            MMI_FTPC_SET_FLAG(MMIFTP_MASK_FS_SANITY);
        }
        else if (ret == FS_ROOT_DIR_FULL)
        {
            FTP_DEBUG(kal_print("FTPC RECEIVED FOLDER INIT -- ERROR ROOT DIR FULL\n");)
            MMI_FTPC_SET_FLAG(MMIFTP_MASK_ROOT_DIR_FULL);
            MMI_FTPC_SET_FLAG(MMIFTP_MASK_FS_SANITY);
        }
        else if (ret == FS_DEVICE_BUSY)
        {
            MMI_FTPC_SET_FLAG(MMIFTP_MASK_FS_DEVICE_BUSY);
        }
        else if (ret == FS_LOCK_MUTEX_FAIL)
        {
            MMI_FTPC_SET_FLAG(MMIFTP_MASK_FS_LOCK_MUTEX_FAIL);
        }
        else
        {

	        MMI_FTPC_SET_FLAG(MMIFTP_MASK_WRITE_FILE_FAIL);
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
#endif
        }
    }   /* End of error handling */
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
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_find_goep_id
 * DESCRIPTION
 *  This function is to find the goep_id from ftpc context
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
U32 mmi_bt_ftpc_find_goep_id(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC FIND INDEX\n");)
        /* fine the index */
        for (i = 0; i < FTP_MAX_SERVER_SUPPORT; i++)
    {
        if (ftpc_cntx_p->goep_conn_id[i] == index)
        {
            return i;
        }
    }
    /* index is not correct */
    MMI_FTP_LOG2(MMI_BT_FTP_FTPC_FIND_GOEP_ID_FAILED, ftpc_cntx_p->goep_conn_id[0], index);
    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_gen_dup_name
 * DESCRIPTION
 *  This function is to generate a unique duplicated obj name
 * PARAMETERS
 *  i       [IN]        
 *  U32(?)
 * RETURNS
 *  int
 *****************************************************************************/
int mmi_bt_ftpc_gen_dup_name(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    U8 fcnt = 1;
    U8 pre_str_size = 0;
    U8 *path_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_GEN_DUP_OBJ_NAME);

    path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);

    /* create duplicated name */
    while (fcnt < 1024)
    {
        U8 tmp_name2[FTP_MAX_OBJ_NAME_LEN];

        memset(tmp_name2, 0, FTP_MAX_OBJ_NAME_LEN);

        /* prepare path */
        memset(path_buf, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        FTPC_MAKE_RECV_PATH(path_buf);

        /* prepare duplicated name */
        kal_wsprintf((kal_uint16*) nPrintableStr, "Dup(%d)", fcnt);
        pre_str_size = mmi_ucs2strlen((S8*) nPrintableStr);

        /* Dup(%d)+ name */
        if (mmi_ucs2strlen((S8*) ((act_client_cntx_p + i)->ftpc_obj_name)) + pre_str_size >
            (FTP_MAX_OBJ_NAME_LEN / 2 - 1))
        {
            U16 offset = 0;

            /* skip front name (len: exceed part) */
            /* Dup(%d) -> tmp */
            memcpy(tmp_name2, nPrintableStr, (pre_str_size * 2));

            /* filename -> tmp */
            offset += (U16) pre_str_size *2 + mmi_ucs2strlen((S8*) ((act_client_cntx_p + i)->ftpc_obj_name)) * 2 + 2;

            offset -= FTP_MAX_OBJ_NAME_LEN;

            memcpy(
                tmp_name2 + (pre_str_size * 2), /* strcat after Dup(%d) */
                ((act_client_cntx_p + i)->ftpc_obj_name) + offset,   /* skip front */
                (FTP_MAX_OBJ_NAME_LEN - 2 - (pre_str_size * 2)));

            tmp_name2[FTP_MAX_OBJ_NAME_LEN - 2] = 0;
            tmp_name2[FTP_MAX_OBJ_NAME_LEN - 1] = 0;

        }
        /* FTP_MAX_OBJ_NAME_LEN /2 >= len(filname) + pre_str_size + 1 */
        else
        {
            /* Dup(%d) -> tmp */
            memcpy(tmp_name2, nPrintableStr, (pre_str_size * 2));
            /* obj_name -> tmp */
            memcpy(
                tmp_name2 + (pre_str_size * 2),
                (act_client_cntx_p + i)->ftpc_obj_name,
                (FTP_MAX_OBJ_NAME_LEN - (pre_str_size * 2)));
            /* tmp -> context */
        }

        /* check new path length */
        if ((mmi_ucs2strlen((PS8) path_buf) + mmi_ucs2strlen((PS8) tmp_name2)) > (FMGR_MAX_PATH_LEN - 1))
        {
            FTP_DEBUG(kal_print("FTPC PUSH OBJ( NEW PATH > FMGR_MAX_PATH_LEN )\n"););            
            if (path_buf);
            {
                OslMfree(path_buf);
            }
            MMI_FTPC_SET_FLAG(MMIFTP_MASK_WRITE_FILE_FAIL);
            return -1;
        }

        /* check if new filename exists */
        /* form complete path */
        mmi_ucs2cat((PS8) path_buf, (PS8) tmp_name2);
        ret = FS_GetAttributes((const WCHAR*)path_buf);
        /* file doesn't exist */
        if ((ret == FS_FILE_NOT_FOUND) || (ret == FS_PATH_NOT_FOUND))
        {
            /* unique name */
            memcpy(((act_client_cntx_p + i)->ftpc_obj_name), tmp_name2, FTP_MAX_OBJ_NAME_LEN);
            if (path_buf);
            {
                OslMfree(path_buf);
            }
            return 1;
        }
        /* file already exist */
        else
        {
            /* increase temp count */
            fcnt++;
        }
    }

    /* can't generate a uniaue dup file */
    FTP_DEBUG(kal_print("FTPC GEN DUP OBJ NAME -- FAILED (fcnt == 0xFF)\n"););
    MMI_FTPC_SET_FLAG(MMIFTP_MASK_WRITE_FILE_FAIL);
    if (path_buf);
    {
        OslMfree(path_buf);
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_rename_recved_obj
 * DESCRIPTION
 *  This function is to rename the temp obj name to actual
 * PARAMETERS
 *  i       [IN]        
 *  U32(?)
 * RETURNS
 *  int
 *****************************************************************************/
static int mmi_bt_ftpc_rename_recved_obj(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U8 *path_buf_actual;
    U8 *path_buf_tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FTP_LOG(MMI_BT_FTP_FTPC_RENAME_OBJ);
    
    /* Temp file name */
    path_buf_tmp = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_ASSERT(path_buf_tmp != NULL);
    memset(path_buf_tmp, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_MAKE_RECV_TMP_OBJNAME(path_buf_tmp, (act_client_cntx_p + i)->tmpname_fcnt);

    /* Actual file name */
    path_buf_actual = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_ASSERT(path_buf_actual != NULL);
    memset(path_buf_actual, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    FTPC_MAKE_RECV_PATH(path_buf_actual);
    mmi_ucs2cat((PS8) path_buf_actual, (PS8) (act_client_cntx_p + i)->ftpc_obj_name);
    
    ret = FS_GetAttributes((const WCHAR*)path_buf_actual);
    /* actual file already exist */
    if ((ret != FS_FILE_NOT_FOUND) && (ret != FS_PATH_NOT_FOUND))
    {
        ret = mmi_bt_ftpc_gen_dup_name(i);

        /* duplicate new file name failed*/
        if (ret < 0)
        {
            if(path_buf_actual)
            {
                OslMfree(path_buf_actual);
            }
            
            if(path_buf_tmp)
            {
                OslMfree(path_buf_tmp);
            }
            return -1;
        }
        else
        {
            memset(path_buf_actual, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
            FTPC_MAKE_RECV_PATH(path_buf_actual);
            mmi_ucs2cat((PS8) path_buf_actual, (PS8) (act_client_cntx_p + i)->ftpc_obj_name);
        }
    }


#if defined(NOKE_DEBUG)
    noke_dbg_printf( "temp name =%s, actual name =%s \n\r ", path_buf_tmp  , path_buf_actual );
#endif

    ret = FS_Rename((kal_uint16*) path_buf_tmp, (kal_uint16*) path_buf_actual);


#if defined(NOKE_DEBUG)
    noke_dbg_printf( "fs_rename =%d \n\r ", ret );
#endif

    if(path_buf_actual)
    {
        OslMfree(path_buf_actual);
    }
    
    if(path_buf_tmp)
    {
        OslMfree(path_buf_tmp);
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_write_obj
 * DESCRIPTION
 *  This function is to write obj to file
 * PARAMETERS
 *  rsp     [?]         
 *  i       [IN]        
 *  goep_push_ind_struct*, U32(?)
 * RETURNS
 *  int
 *****************************************************************************/
int mmi_bt_ftpc_write_obj(goep_pull_rsp_struct *rsp, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *path_buf;
    FS_HANDLE h;
    goep_pull_req_struct *req;
    U8 fcnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_WRITE_OBJ, rsp->pkt_type);

    /* Use name FtpRecv00.tmp when getting */
    path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_ASSERT(path_buf != NULL);
    memset(path_buf, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    fcnt = 0;
    MMI_FTP_MAKE_RECV_TMP_OBJNAME(path_buf, fcnt);

    /*----------------------------------------------------
    //by eric mbj06054,  saved for FtpRecvxx.tmp support
    while (fcnt < 0xFF)
    {   
        MMI_FTP_MAKE_RECV_TMP_OBJNAME(path_buf, fcnt);
        h = FS_Open((kal_uint16*) path_buf, FS_READ_ONLY);
        if (h >= 0)
        {
            FS_Close(h);
            fcnt++;
        }
        else
        {
            (act_client_cntx_p + i)->tmpname_fcnt = fcnt;
            break;
        }
    }
    ----------------------------------------------------*/

    h = FS_Open((kal_uint16*) path_buf, (FS_READ_WRITE | FS_CREATE_ALWAYS));
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_WRITE_OBJ_OPEN, h);
    if (path_buf);
    {
        OslMfree(path_buf);
    }

    if (h <= 0)
    {
        /* File open error. Error handling */
        mmi_bt_ftpc_set_fs_flag((int) h);
        return -1;
    }
    else
    {
        /* set file handle to context */
        (act_client_cntx_p + i)->fh_ftpc_recv = h;
        (act_client_cntx_p + i)->tmpname_fcnt = fcnt;
    }

    /* Write object context to file */
    if (rsp->frag_len > 0)
    {
        U32 len_written;
        int ret;

        ret = FS_Write(h, rsp->frag_ptr, rsp->frag_len, (kal_uint32*) & len_written);
        MMI_FTP_LOG1(MMI_BT_FTP_FTPC_WRITE_OBJ_WRITE, ret);

        /* Write error */
        if (ret < 0)
        {
            FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
            (act_client_cntx_p + i)->fh_ftpc_recv = 0;
            FS_Delete((kal_uint16*) path_buf);

            mmi_bt_ftpc_set_fs_flag((int) ret);
            return -1;
        }
    }
    else
    {
        FTP_DEBUG(kal_print("FTPC WRITE OBJ (LEN <= 0)\n"););       
    }

    (act_client_cntx_p + i)->recved_obj_len += rsp->frag_len;

    /*knows the total len*/
    if((act_client_cntx_p + i)->total_len_type == MMI_FTPC_TOTAL_LEN_NO_ZERO)
    {
        if ((act_client_cntx_p + i)->total_recv_obj_len > rsp->frag_len)
        {
            (act_client_cntx_p + i)->remain_recv_obj_len = (act_client_cntx_p + i)->total_recv_obj_len - rsp->frag_len;
        }
        else
        {
            (act_client_cntx_p + i)->remain_recv_obj_len = 0;
        }
    }

    /* check final packet -- if final -> notify MMI Scr */
    if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
    {

#if defined(NOKE_DEBUG)
        noke_dbg_printf( " mmi_bt_ftpc_write_obj : final packet \n\r "   );
#endif

        FTP_DEBUG(kal_print("FTPC WRITE OBJ (FINAL PKT)\n"););       
        (act_client_cntx_p + i)->remain_recv_obj_len = 0;

        /* close file */
        if ((act_client_cntx_p + i)->fh_ftpc_recv)
        {
            FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
            (act_client_cntx_p + i)->fh_ftpc_recv = 0;
        }
        mmi_bt_ftpc_rename_recved_obj(i);
        mmi_bt_ftpc_multi_file_continue(i);
    }
    else
    {
        /* Get next object body */
        req = (goep_pull_req_struct*) OslConstructDataPtr(sizeof(goep_pull_req_struct));
        FTP_MEMSET(req);    /* memory init */
        req->goep_conn_id = ftpc_cntx_p->goep_conn_id[i];
        req->pkt_type = GOEP_NORMAL_PKT;
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_write_obj_continue
 * DESCRIPTION
 *  This function is to write obj to file
 * PARAMETERS
 *  rsp     [?]         
 *  i       [IN]        
 *  goep_push_ind_struct*, U32(?)
 * RETURNS
 *  int
 *****************************************************************************/
int mmi_bt_ftpc_write_obj_continue(goep_pull_rsp_struct *rsp, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_WRITE_OBJ_CONTINUE, rsp->pkt_type);

    /* Write object context to file */
    if (rsp->frag_len > 0)
    {
        U32 len_written;
        int ret;

        MMI_FTP_ASSERT((act_client_cntx_p + i)->fh_ftpc_recv);
        ret = FS_Write((act_client_cntx_p + i)->fh_ftpc_recv, rsp->frag_ptr, rsp->frag_len, (kal_uint32*) & len_written);
        MMI_FTP_LOG1(MMI_BT_FTP_FTPC_WRITE_OBJ_CONTINUE_WRITE, ret);

        /* Write error */
        if (ret < 0)
        {
            FTP_DEBUG(kal_print("FTPC WRITE OBJ ERROR -- FS_WRITE ERROR\n");)

            mmi_bt_ftpc_set_fs_flag((int) ret);
            return -1;
        }
    }
    else
    {
        FTP_DEBUG(kal_print("FTPC WRITE OBJ (LEN <= 0)\n"););       
    }

    (act_client_cntx_p + i)->recved_obj_len += rsp->frag_len;

    /*knows the total len*/
    if((act_client_cntx_p + i)->total_len_type == MMI_FTPC_TOTAL_LEN_NO_ZERO)
    {
        if ((act_client_cntx_p + i)->remain_recv_obj_len >= rsp->frag_len)
        {
            (act_client_cntx_p + i)->remain_recv_obj_len = (act_client_cntx_p + i)->remain_recv_obj_len - rsp->frag_len;
        }
        /* get uploading file */
        else
        {
            /* keep bar at position 99% */
            (act_client_cntx_p + i)->remain_recv_obj_len = 1;
        }
    }

    /* check final packet -- if final -> notify MMI Scr */
    if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
    {
#if defined(NOKE_DEBUG)
        noke_dbg_printf( " mmi_bt_ftpc_write_obj_continue : final packet \n\r "   );
#endif
        FTP_DEBUG(kal_print("FTPC WRITE OBJ CONTINUE (FINAL PKT)\n"););       
        (act_client_cntx_p + i)->remain_recv_obj_len = 0;

        /* close file */
        if ((act_client_cntx_p + i)->fh_ftpc_recv)
        {
            FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
            (act_client_cntx_p + i)->fh_ftpc_recv = 0;
        }
        mmi_bt_ftpc_rename_recved_obj(i);
        mmi_bt_ftpc_multi_file_continue(i);
    }
    else
    {
        /* Get next object body */
        req = (goep_pull_req_struct*) OslConstructDataPtr(sizeof(goep_pull_req_struct));
        FTP_MEMSET(req);    /* memory init */
        req->goep_conn_id = ftpc_cntx_p->goep_conn_id[i];
        req->pkt_type = GOEP_NORMAL_PKT;
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_del_tmp_obj
 * DESCRIPTION
 *  This function is to delete the temp object file when error occurs  
 *  The file is temp file for getting obj, not or getting folder.
 * PARAMETERS
 *  
 *  i       [IN]        
 *  
 * RETURNS
 *  int
 *****************************************************************************/
void mmi_bt_ftpc_del_tmp_obj(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *path_buf_tmp;
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC DELETE TEMP OBJECT-- DOWNLOAD ERROR\n");)

    MMI_FTP_LOG(MMI_BT_FTP_FTPC_DEL_TMP_FILE);

    /*current only support only one connection!*/
    if(i != 0)
    {
        i = 0;
    }

    /* Temp file name */
    path_buf_tmp = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_ASSERT(path_buf_tmp != NULL);
    memset(path_buf_tmp, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_MAKE_RECV_TMP_OBJNAME(path_buf_tmp, (act_client_cntx_p + i)->tmpname_fcnt);

    h = FS_Open((kal_uint16*) path_buf_tmp, FS_READ_ONLY);
    if (h >= 0)
    {
        FS_Close(h);
        FS_Delete((kal_uint16*) path_buf_tmp);
    }

    if(path_buf_tmp)
    {
        OslMfree(path_buf_tmp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_folder
 * DESCRIPTION
 *  This function is to handel the getting folder operation
 * PARAMETERS
 *  rsp     [?]         
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_get_folder(goep_pull_rsp_struct *rsp, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG3(MMI_BT_FTP_FTPC_GET_FOLDER, rsp->rsp_code, rsp->pkt_type, rsp->to_self);

    /* continue parsing */
    if (rsp->to_self == MMI_TRUE)
    {
        MMI_FTP_LOG2(
            MMI_BT_FTP_FTPC_GET_FOLDER_PARSE_RESUME,
            (act_client_cntx_p + i)->entity_cnt_cur_folder,
            (act_client_cntx_p + i)->parsed_folder_item_cnt);
        ret = xml_resume_parse((act_client_cntx_p + i)->xml_parser_p);

        /* threshold for release MMI control to other tasks */
        if ((act_client_cntx_p + i)->parsed_folder_item_cnt == FTP_MAX_PARSE_THRESHOLD)
        {
            (act_client_cntx_p + i)->parsed_folder_item_cnt = 0;

            /* send pull rsp to self */
            goto FTPC_GET_FOLER_CONTINUE_PARSE;
        }
        /* parse finished */
        else
        {
            /* no error -> write to file (last records still in temp buff ) */
            if (!ret)
            {
                ret = FS_Write(
                        (act_client_cntx_p + i)->folder_content.fd,
                        (act_client_cntx_p + i)->folder_content.buf,
                        (act_client_cntx_p + i)->folder_content.buflen,
                        &((act_client_cntx_p + i)->folder_content.written));
            }
            /* reset context */
            FS_Close((act_client_cntx_p + i)->folder_content.fd);
            (act_client_cntx_p + i)->folder_content.fd = 0;
            xml_close_parser((act_client_cntx_p + i)->xml_parser_p);
            free_ctrl_buffer((act_client_cntx_p + i)->xml_parser_p);
            (act_client_cntx_p + i)->xml_parser_p = NULL;
            ftpc_cntx_p->curr_idx = 0;
            (act_client_cntx_p + i)->parsed_folder_item_cnt = 0;
            goto PARSE_DONE;
        }
    }

    switch (rsp->rsp_code)
    {
        case GOEP_STATUS_SUCCESS:
        {
            FS_HANDLE h;

            if ((rsp->pkt_type == GOEP_FIRST_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                FTP_DEBUG(kal_print("FTPC GET FOLDER -- FIRST PKT\n");)

                    /* Check default folder again */
                    mmi_bt_ftp_work_folder_init();

                /* if after reinit, folder still get problem, return fail */
                if (MMI_FTPC_GET_FLAG(MMIFTP_MASK_FOLDER_ERR) == MMI_TRUE)
                {
                    FTP_DEBUG(kal_print("FTPC GET FOLDER -- WORK FOLDER CHECK FAIL\n"););
                    mmi_bt_ftpc_disp_folder_content(MMI_FTPC_FOLDER_EMPTY);
                    goto FTPC_GET_FOLDER_ERROR;
                }

                /* close file first if necessary */
                if ((act_client_cntx_p + i)->fh_ftpc_recv)
                {
                    FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
                    (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
                }

                /* Create folder listing object file */
                h = FS_Open((kal_uint16*) ((act_client_cntx_p + i)->folder_obj), (FS_READ_WRITE | FS_CREATE_ALWAYS));
                MMI_FTP_LOG1(MMI_BT_FTP_FTPC_GET_FOLDER_OPEN, h);

                if (h < 0)
                {
                    FTP_DEBUG(kal_print("FTPC GET FOLDER -- FS_OPEN ERROR\n");)
                    mmi_bt_ftpc_disp_folder_content(MMI_FTPC_FOLDER_EMPTY);
                    goto FTPC_GET_FOLDER_ERROR;
                }
                else
                {
                    (act_client_cntx_p + i)->fh_ftpc_recv = h;
                }
            }
            /* Write object context to file */
            if (rsp->frag_len > 0)
            {
                U32 len_written;

                if ((act_client_cntx_p + i)->fh_ftpc_recv)
                {
                    ret = FS_Write(
                            (act_client_cntx_p + i)->fh_ftpc_recv,
                            rsp->frag_ptr,
                            rsp->frag_len,
                            (kal_uint32*) & len_written);
                    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_GET_FOLDER_WRITE, ret);

                    if (ret < 0)
                    {
                        FTP_DEBUG(kal_print("FTPC GET FOLDER -- FS_WRITE ERROR\n");)
                        mmi_bt_ftpc_disp_folder_content(MMI_FTPC_FOLDER_EMPTY);
                        goto FTPC_GET_FOLDER_ERROR;
                    }
                }
                else
                {
                    FTP_DEBUG(kal_print("FTPC GET FOLDER ERROR -- WRITE OBJ BUT FH IN CNTX IS NULL\n"););
                    MMI_FTP_ASSERT(0);
                }
            }

            /* Final packet, Receive Finished !! */
            if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                FTP_DEBUG(kal_print("FTPC GET FOLDER FINAL PKT\n"););
                ftpc_cntx_p->ftpc_flag = 0;

                /* close file */
                if ((act_client_cntx_p + i)->fh_ftpc_recv)
                {
                    FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
                    (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
                }

                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_PARSING_FOLDER);
                /* parse folder content */
                ret = mmi_bt_ftpc_parse_folder_content(i);

                /* check continue parsing or not */
                if (ret == 1)
                {
                    /* send pull rsp to self */
                    goto FTPC_GET_FOLER_CONTINUE_PARSE;
                }
              PARSE_DONE:
                MMI_FTP_LOG3(
                    MMI_BT_FTP_FTPC_GET_FOLDER_PARSE_DONE,
                    ret,
                    (act_client_cntx_p + i)->entity_cnt_cur_folder,
                    (act_client_cntx_p + i)->parsed_folder_item_cnt);

                /* clear the transferred folder content */
                FS_Delete((const WCHAR*)(act_client_cntx_p + i)->folder_obj);
                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);

                if (ret < 0)
                {
                    FTP_DEBUG(kal_print("FTPC GET FOLDER FINAL PKT PARSE ERROR\n"););
                    mmi_bt_ftpc_disp_folder_content(MMI_FTPC_FOLDER_PARTIAL);
                }
                else
                {
                    mmi_bt_ftpc_disp_folder_content(MMI_FTPC_FOLDER_FULL);

                    if ((act_client_cntx_p + i)->got_root == 0)
                    {
                        (act_client_cntx_p + i)->got_root = 1;
                    }
                }
            }
            else
            {
                goep_pull_req_struct *req;
                FTP_DEBUG(kal_print("FTPC GET FOLDER NOT FINAL PKT -- SEND REQ\n"););
                /* Get next list folder object body */
                /* construct disconnect req ilm */
                req = (goep_pull_req_struct*) OslConstructDataPtr(sizeof(goep_pull_req_struct));
                FTP_MEMSET(req);    /* memory init */
                req->goep_conn_id = rsp->goep_conn_id;
                strcpy((PS8) req->obj_mime_type, "x-obex/folder-listing");
                req->pkt_type = GOEP_NORMAL_PKT;
                mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
            }
            return;
        }
        default:
                {
            FTP_DEBUG(kal_print("FTPC GET FOLDER RSP ERROR\n"););
                if ((act_client_cntx_p + i)->fh_ftpc_recv)
                {
                    FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
                    (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
                FS_Delete((const WCHAR*)(act_client_cntx_p + i)->folder_obj);
                }

                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
            mmi_bt_ftpc_disp_folder_content(MMI_FTPC_FOLDER_EMPTY);
            return;
    }
    }
  FTPC_GET_FOLER_CONTINUE_PARSE:
    {
        goep_pull_rsp_struct *continue_rsp;

        MMI_FTP_LOG(MMI_BT_FTP_FTPC_GET_FOLDER_CONTINUE_PARSE);

        /* construct continue_rsp ilm */
        continue_rsp = (goep_pull_rsp_struct*) OslConstructDataPtr(sizeof(goep_pull_rsp_struct));
        FTP_MEMSET(continue_rsp);   /* memory init */
        continue_rsp->goep_conn_id = rsp->goep_conn_id;
        memcpy(continue_rsp->uuid, OBEX_FTP_UUID, 16);
        continue_rsp->uuid_len = 16;
        continue_rsp->to_self = MMI_TRUE;

        /* send continue_rsp and connect cnf fail to CM */
        mmi_bt_ftp_send_msg_self(MSG_ID_GOEP_PULL_RSP, continue_rsp);
        return;
    }
  FTPC_GET_FOLDER_ERROR:
    {
        /* close file */
        if ((act_client_cntx_p + i)->fh_ftpc_recv)
        {
            FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
            (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
        }
        FS_Delete((const WCHAR*)(act_client_cntx_p + i)->folder_obj);

        /* Not last packet of folder content, we have to send abort out */
        if ((rsp->pkt_type == GOEP_SINGLE_PKT) || (rsp->pkt_type == GOEP_FINAL_PKT))
        {
            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_CONNECTED);
        }
        else
        {
            /* send abort packet */
            mmi_bt_ftpc_send_abort(rsp->goep_conn_id);
            /* add disconnecting screen to history */
            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_ABORTING);
            mmi_bt_ftpc_AddHistory(SCR_FTP_ABORTING);
        }
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_obj
 * DESCRIPTION
 *  This function is to handel the getting obj operation
 * PARAMETERS
 *  rsp     [?]         
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_get_obj(goep_pull_rsp_struct *rsp, U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG2(MMI_BT_FTP_FTPC_GET_OBJ, rsp->rsp_code, rsp->pkt_type);

    switch (rsp->rsp_code)
    {
        case GOEP_STATUS_SUCCESS:
        {
#ifdef __USB_IN_NORMAL_MODE__
                if(mmi_usb_is_in_mass_storage_mode())
                {
                    return;
                }
#endif /* __USB_IN_NORMAL_MODE__ */ 

            if ((rsp->pkt_type == GOEP_FIRST_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                if (MMI_TRUE == mmi_bt_ftpc_is_first_file() )
                {
                    mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_START);
                }
                /* Check default folder again */
                mmi_bt_ftpc_received_folder_init();

                /* if after reinit, folder still get problem, return fail */
                if (MMI_FTPC_GET_FLAG(MMIFTP_MASK_WRITE_FILE_FAIL) == MMI_TRUE
                    ||MMI_FTPC_GET_FLAG(MMIFTP_MASK_DISK_FULL) == MMI_TRUE
                    ||MMI_FTPC_GET_FLAG(MMIFTP_MASK_ROOT_DIR_FULL) == MMI_TRUE
                    ||MMI_FTPC_GET_FLAG(MMIFTP_MASK_FS_DEVICE_BUSY) == MMI_TRUE
                    ||MMI_FTPC_GET_FLAG(MMIFTP_MASK_ROOT_DIR_FULL) == MMI_TRUE)
                {
                    FTP_DEBUG(kal_print("FTPC GET OBJ -- WORK FOLDER CHECK FAIL\n"););
                    goto FTPC_GET_OBJ_ERR;
                }

                if (rsp->total_obj_len > 0)
                {
                    (act_client_cntx_p + i)->total_recv_obj_len = rsp->total_obj_len;
                    (act_client_cntx_p + i)->remain_recv_obj_len = rsp->total_obj_len;
                    (act_client_cntx_p + i)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_ZERO;
                #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
                    if (g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type == MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT)
                    {
                        g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type = MMI_FTPC_TOTAL_LEN_NO_ZERO;
                    }
                #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
                }
                else
                {
                    (act_client_cntx_p + i)->total_len_type = MMI_FTPC_TOTAL_LEN_ZERO;
                #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
                    if (g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type == MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT)
                    {
                        g_mmi_bt_ftp_scr_cntx_p->multi_total_len_type = MMI_FTPC_TOTAL_LEN_ZERO;
                    }
                #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
                }

                /* write file */
                ret = mmi_bt_ftpc_write_obj(rsp, i);
                if (ret < 0)
                {
                   FTP_DEBUG(kal_print("FTPC GET OBJ( write obj fail )\n"););
                    goto FTPC_GET_OBJ_ERR;
                }
                return;
            }   /* end of first packet */

            /* write file */
            ret = mmi_bt_ftpc_write_obj_continue(rsp, i);
            if (ret < 0)
            {
               FTP_DEBUG(kal_print("FTPC GET OBJ( write obj continue fail )\n"););
                goto FTPC_GET_OBJ_ERR;
            }
            return;
        }
        default:
            FTP_DEBUG(kal_print("FTPC GET OBJ RSP ERROR\n");)
            if ((act_client_cntx_p+i)->ftpc_state != MMI_FTPC_STATE_IDLE)
            {
                mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_REJECT_FROM_SERVER);
            }
            if ((act_client_cntx_p + i)->fh_ftpc_recv)
            {
                FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
                (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
            }
            MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
            mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);
    }
    return;
  FTPC_GET_OBJ_ERR:
    /*reset variables after send abort_req*/
    mmi_bt_ftpc_receiving_aborted_hdlr(i);

    if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
    {
        MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
        mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);
    }
    else
    {
        mmi_bt_ftpc_set_abort_req_sent_flag();
        mmi_bt_ftpc_send_abort(rsp->goep_conn_id);
        MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_ABORTING);
        mmi_bt_ftpc_AddHistory(SCR_FTP_ABORTING);
    }

    /*notify the user the fs error*/
    mmi_bt_ftpc_read_fs_flag_and_popup();
    ftpc_cntx_p->ftpc_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_send_abort
 * DESCRIPTION
 *  This function is to abort the getting obj operation
 * PARAMETERS
 *  rsp     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_send_abort(U8 goep_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_req_struct *req;

    FTP_DEBUG(kal_print("FTPC GET ABORT\n");)
        /* construct abort req ilm */
        req = (goep_abort_req_struct*) OslConstructDataPtr(sizeof(goep_abort_req_struct));
    FTP_MEMSET(req);    /* memory init */
    req->goep_conn_id = goep_conn_id;

    /* send abort req */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_ABORT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_parse_folder_content
 * DESCRIPTION
 *  This function is to parse the folder content
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static int mmi_bt_ftpc_parse_folder_content(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_PARSE_FOLDER_CONTENT);

    if ((act_client_cntx_p + i)->xml_parser_p == NULL)
    {
        (act_client_cntx_p + i)->xml_parser_p = get_ctrl_buffer(sizeof(XML_PARSER_STRUCT));
    }

    memset((act_client_cntx_p + i)->xml_parser_p, 0, sizeof(XML_PARSER_STRUCT));
    memset(&((act_client_cntx_p + i)->folder_content), 0, sizeof(mmi_ftp_file_writer_struct));

    (act_client_cntx_p + i)->folder_content.fd = FS_Open((const WCHAR*)(act_client_cntx_p + i)->parsed_folder, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if ((act_client_cntx_p + i)->folder_content.fd < 0)
    {
        FTP_DEBUG(kal_print("FTPC PARSE FOLDER CONTENT -- FS_OPEN ERROR\n");)
        FS_Close((act_client_cntx_p+i)->folder_content.fd);
        (act_client_cntx_p + i)->folder_content.fd = 0;
        free_ctrl_buffer((act_client_cntx_p + i)->xml_parser_p);
        (act_client_cntx_p + i)->xml_parser_p = NULL;
        MMI_FTP_LOG1(MMI_BT_FTP_FTPC_PARSE_FOLDER_CONTENT_FS_OPEN, (act_client_cntx_p + i)->folder_content.fd);
        return -1;
    }

    result = xml_new_parser((act_client_cntx_p + i)->xml_parser_p);
    /* init parser fail */
    if (result)
    {
        FTP_DEBUG(kal_print("FTPC PARSE FOLDER CONTENT -- INIT_PARSER ERROR\n");)
        FS_Close((act_client_cntx_p+i)->folder_content.fd);
        (act_client_cntx_p + i)->folder_content.fd = 0;
        xml_close_parser((act_client_cntx_p + i)->xml_parser_p);
        free_ctrl_buffer((act_client_cntx_p + i)->xml_parser_p);
        (act_client_cntx_p + i)->xml_parser_p = NULL;
        return result;
    }
    /* set the index for parser to know the active connection */
    ftpc_cntx_p->curr_idx = (U8) i;
    (act_client_cntx_p + i)->entity_cnt_cur_folder = 0;
    (act_client_cntx_p + i)->parsed_folder_item_cnt = 0;
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    (act_client_cntx_p + i)->file_cnt_cur_folder = 0;
#endif 

    /* register element parser to write records to file when parsing */
    xml_register_element_handler((act_client_cntx_p+i)->xml_parser_p,
        mmi_bt_ftpc_folder_listing_startElement,
        mmi_bt_ftpc_folder_listing_endElement);

    /* parse received folder content */
    result = xml_parse((act_client_cntx_p + i)->xml_parser_p, (kal_wchar*) (act_client_cntx_p + i)->folder_obj);

    /* threshold for release MMI control to other tasks */
    if ((act_client_cntx_p + i)->parsed_folder_item_cnt == FTP_MAX_PARSE_THRESHOLD)
    {
        MMI_FTP_LOG1(MMI_BT_FTP_FTPC_PARSE_FOLDER_CONTENT_PAUSE, (act_client_cntx_p + i)->entity_cnt_cur_folder);
        (act_client_cntx_p + i)->parsed_folder_item_cnt = 0;
        /* FS api and XML api won't return postive value, so return 1 means continue parsing case */
        return 1;
    }
    /* no error -> write to file (last records still in temp buff ) */
    if (!result)
    {
        result = FS_Write(
                    (act_client_cntx_p + i)->folder_content.fd,
                    (act_client_cntx_p + i)->folder_content.buf,
                    (act_client_cntx_p + i)->folder_content.buflen,
                    &((act_client_cntx_p + i)->folder_content.written));
    }
    /* reset context */
    FS_Close((act_client_cntx_p + i)->folder_content.fd);
    (act_client_cntx_p + i)->folder_content.fd = 0;
    xml_close_parser((act_client_cntx_p + i)->xml_parser_p);
    free_ctrl_buffer((act_client_cntx_p + i)->xml_parser_p);
    (act_client_cntx_p + i)->xml_parser_p = NULL;
    ftpc_cntx_p->curr_idx = 0;
    (act_client_cntx_p + i)->parsed_folder_item_cnt = 0;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_folder_listing_startElement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         [?]
 *  el          [IN]        
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_folder_listing_startElement(void *data, const char *el, const char **attr, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int write_result = 0;
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = ftpc_cntx_p->curr_idx;

    /*if have error in parse*/
    if(error != XML_NO_ERROR)
    {
        MMI_FTP_LOG(MMI_BT_FTP_FTPC_PARSE_EL_START_ERR);
        xml_stop_parse((act_client_cntx_p + idx)->xml_parser_p);
        return;
    }

    if ((!strcmp("folder", el)) || (!strcmp("file", el)))
    {
        memset(&((act_client_cntx_p + idx)->obj_entity), 0, sizeof(mmi_ftp_obj_entity_struct));
        (act_client_cntx_p + idx)->entity_cnt_cur_folder++;
        (act_client_cntx_p + idx)->parsed_folder_item_cnt++;

    #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        if (!strcmp("file", el))
        {
            (act_client_cntx_p + idx)->file_cnt_cur_folder++;
        }
    #endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

        if (!strcmp("folder", el))
        {
            (act_client_cntx_p + idx)->obj_entity.type = MMI_FTP_OBJ_TYPE_FOLDER;
        }
        else
        {
            (act_client_cntx_p + idx)->obj_entity.type = MMI_FTP_OBJ_TYPE_FILE;
        }

        if (attr != NULL)
        {
            while ((attr[i]) != 0)
            {
                if (!strcmp("name", attr[i]))
                {

                    if (mmi_chset_utf8_strlen((U8*) attr[i + 1]) <= FTP_MAX_OBJ_NAME_LEN/2 -1)
                    {
                        mmi_chset_utf8_to_ucs2_string(
                            (U8*) (act_client_cntx_p + idx)->obj_entity.name,
                            FTP_MAX_OBJ_NAME_LEN,
                            (U8*) attr[i + 1]);
                    }
                    /* need to cut the name but with the ext name
                      * 1. calculate the ext name length
                      * 2. cut and cat
                      */
                    else
                    {
                        char *p_ext_name;
                        U32  ext_name_len;
                        S8 *ext_name_new;      /*ucs2*/

                        p_ext_name = strrchr(attr[i + 1], '.');
                        if(p_ext_name)
                        {
                            ext_name_len = mmi_chset_utf8_strlen((kal_uint8*)p_ext_name);
                        }
                        else
                        {
                            ext_name_len = 0;
                        }

                        if((FTP_MAX_OBJ_NAME_LEN - 2) > ext_name_len * 2)
                        {
                            mmi_chset_utf8_to_ucs2_string(
                                (U8*) (act_client_cntx_p + idx)->obj_entity.name,
                                FTP_MAX_OBJ_NAME_LEN - ext_name_len * 2,
                                (U8*) attr[i + 1]);

                            if (ext_name_len > 0)
                            {
                                ext_name_new = get_ctrl_buffer(ext_name_len * 2 + 2);
                                mmi_chset_utf8_to_ucs2_string((kal_uint8*)ext_name_new, ext_name_len * 2 + 2, (kal_uint8*) p_ext_name);
                                UCS2Strncat(
                                    (S8 *)(act_client_cntx_p + idx)->obj_entity.name, 
                                    ext_name_new, 
                                    ext_name_len);
                                free_ctrl_buffer(ext_name_new);
                            }
                        }
                        else
                        {
                            mmi_chset_utf8_to_ucs2_string(
                                (U8*) (act_client_cntx_p + idx)->obj_entity.name,
                                FTP_MAX_OBJ_NAME_LEN,
                                (U8*) attr[i + 1] +(FTP_MAX_OBJ_NAME_LEN - 2 - ext_name_len * 2) );
                        }
                    }
                }
                else if ((!strcmp("created", attr[i])) || (!strcmp("modified", attr[i])))
                {
                    MYTIME create_date;
                    U8 tmp_string[5];

                    tmp_string[0] = attr[i + 1][0];
                    tmp_string[1] = attr[i + 1][1];
                    tmp_string[2] = attr[i + 1][2];
                    tmp_string[3] = attr[i + 1][3];
                    tmp_string[4] = 0;
                    create_date.nYear = atoi((const char*)tmp_string);

                    tmp_string[0] = attr[i + 1][4];
                    tmp_string[1] = attr[i + 1][5];
                    tmp_string[2] = 0;
                    tmp_string[3] = 0;
                    tmp_string[4] = 0;
                    create_date.nMonth = atoi((const char*)tmp_string);

                    tmp_string[0] = attr[i + 1][6];
                    tmp_string[1] = attr[i + 1][7];
                    create_date.nDay = atoi((const char*)tmp_string);

                    tmp_string[0] = attr[i + 1][9];
                    tmp_string[1] = attr[i + 1][10];
                    create_date.nHour = atoi((const char*)tmp_string);

                    tmp_string[0] = attr[i + 1][11];
                    tmp_string[1] = attr[i + 1][12];
                    create_date.nMin = atoi((const char*)tmp_string);

                    tmp_string[0] = attr[i + 1][13];
                    tmp_string[1] = attr[i + 1][14];
                    create_date.nSec = atoi((const char*)tmp_string);

                    date_string(
                        &create_date,
                        (PU16) (act_client_cntx_p + idx)->obj_entity.created_date,
                        DT_IDLE_SCREEN);
                }
                else if (!strcmp("size", attr[i]))
                {
                    int file_size;

                    file_size = atoi(attr[i + 1]);

                    if (file_size > 1024 * 1024)
                    {
                        file_size = file_size / 1024;
                        kal_wsprintf(
                            (WCHAR*) (act_client_cntx_p + idx)->obj_entity.size,
                            "%d.%dM",
                            (U16) (file_size / 1024),
                            (U16) ((file_size % 1024) / 103));
                    }
                    else if (file_size > 1024)
                    {
                        kal_wsprintf(
                            (WCHAR*) (act_client_cntx_p + idx)->obj_entity.size,
                            "%d.%dK",
                            (U16) (file_size / 1024),
                            (U16) ((file_size % 1024) / 103));
                    }
                    else    /* less than 1024 */
                    {
                        kal_wsprintf((WCHAR*) (act_client_cntx_p + idx)->obj_entity.size, "%dB", (U16) (file_size));
                    }
                }
                i += 2;
            }
            if (mmi_ucs2strlen((PS8) ((act_client_cntx_p + idx)->obj_entity.size)) == 0)
            {
                kal_wstrcpy((U16*) (act_client_cntx_p + idx)->obj_entity.size, (U16*) GetString(STR_GLOBAL_EMPTY));
            }
            if (mmi_ucs2strlen((PS8) ((act_client_cntx_p + idx)->obj_entity.created_date)) == 0)
            {
                kal_wstrcpy(
                    (U16*) (act_client_cntx_p + idx)->obj_entity.created_date,
                    (U16*) GetString(STR_GLOBAL_EMPTY));
            }
        }
        write_result = mmi_bt_ftpc_write_obj_entity(idx, &((act_client_cntx_p + idx)->folder_content));
        if (write_result < 0)
        {
            xml_stop_parse((act_client_cntx_p + idx)->xml_parser_p);
        }

        /* threshold for release MMI control to other tasks */
        if ((act_client_cntx_p + idx)->parsed_folder_item_cnt == FTP_MAX_PARSE_THRESHOLD)
        {
            MMI_FTP_LOG1(MMI_BT_FTP_FTPC_FOLDER_LISTING_START_EL, (act_client_cntx_p + idx)->entity_cnt_cur_folder);
            xml_pause_parse((act_client_cntx_p + idx)->xml_parser_p);
        }
    }
    else if ((!strcmp("parent-folder", el)) || (!strcmp("folder-listing", el)))
    {
        return;
    }
    else
    {
        xml_stop_parse((act_client_cntx_p + idx)->xml_parser_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_folder_listing_endElement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         [?]
 *  el          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_folder_listing_endElement(void *data, const char *el, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = ftpc_cntx_p->curr_idx;

    if(error != XML_NO_ERROR)
    {
        MMI_FTP_LOG(MMI_BT_FTP_FTPC_PARSE_EL_END_ERR);
        xml_stop_parse((act_client_cntx_p + idx)->xml_parser_p);
        return;
    }

    if ((!strcmp("folder", el)) ||
        (!strcmp("folder-listing", el)) || (!strcmp("file", el)) || (!strcmp("parent-folder", el)))
    {
        return;
    }
    else
    {
        xml_stop_parse((act_client_cntx_p + idx)->xml_parser_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_write_obj_entity
 * DESCRIPTION
 *  This function is to write the object entities in the listing folder
 * PARAMETERS
 *  idx         [IN]        
 *  writer      [?]         [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  The result od write object entity
 *****************************************************************************/
static int mmi_bt_ftpc_write_obj_entity(U8 idx, mmi_ftp_file_writer_struct *writer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC WRITE OBJ ENTITY\n");)
        /* obj -> buffer */
        memcpy(
            &(writer->buf[writer->buflen]),
            &((act_client_cntx_p + idx)->obj_entity),
            sizeof(mmi_ftp_obj_entity_struct));
    writer->buflen += sizeof(mmi_ftp_obj_entity_struct);

    /* buffer -> file */
    result = mmi_bt_ftp_write_buf2file(writer);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_get_folder_content
 * DESCRIPTION
 *  This function is to get the folder content
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bt_ftpc_get_folder_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG2(MMI_BT_FTP_FTPC_GET_FOLDER_CONTENT, act_client_cntx_p->ftpc_state, ftpc_cntx_p->goep_conn_id[0]);

    /* Change MMI FTPC state */
    switch (act_client_cntx_p->ftpc_state)
    {
        case MMI_FTPC_STATE_CONNECTED:
            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_GETTING_FOLDER);
            /* send get current folder req */
            /* construct get folder req ilm */
            req = (goep_pull_req_struct*) OslConstructDataPtr(sizeof(goep_pull_req_struct));
            FTP_MEMSET(req);    /* memory init */
            req->goep_conn_id = ftpc_cntx_p->goep_conn_id[0];
            req->pkt_type = GOEP_FIRST_PKT;
            strcpy((PS8) req->obj_mime_type, "x-obex/folder-listing");

            /* send get folder req */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
            break;
        default:    /* Incorrect state */
            /* Incorrect state, callback and return error */
            MMI_FTPC_LOG_STATE_ERR(0);
            mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED);    /* Pop up error messages */
            MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_CONNECTED);
            return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_multi_file_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_multi_file_continue(U32 i)
{
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* When download the last packet of a file, user have aborted.*/
    if ((act_client_cntx_p + i)->ftpc_state == MMI_FTPC_STATE_ABORTING)
    {
        if (g_mmi_bt_ftp_scr_cntx_p->pull_type == MMI_FTP_PULL_TYPE_SINGLE)
        {
            MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
            mmi_bt_ftpc_obj_receive_ind();
        }
        else 
        {
            MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
            mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);

            /* reset the downloaded file  info*/
            act_client_cntx_p->total_recv_obj_len = 0;
            act_client_cntx_p->remain_recv_obj_len = 0;
            (act_client_cntx_p + ftpc_cntx_p->curr_idx)->recved_obj_len = 0;
            (act_client_cntx_p + ftpc_cntx_p->curr_idx)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;
            
            mmi_bt_ftpc_clear_abort_scr();
        }
    }
    /* continue down next file */
    else if ((act_client_cntx_p + i)->ftpc_state == MMI_FTPC_STATE_GETTING_OBJ)
    {
        MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
        mmi_bt_ftpc_get_next_file();
    }
    /* user pressed end-key */
    else if ((act_client_cntx_p + i)->ftpc_state == MMI_FTPC_STATE_DISCONNECTING)
    {
        mmi_bt_ftpc_send_disconnect();
    }
    else
    {
        ASSERT(0);
    }
#else /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
    if ((act_client_cntx_p + i)->ftpc_state == MMI_FTPC_STATE_DISCONNECTING)
    {
        mmi_bt_ftpc_send_disconnect();
    }
    else
    {
        MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
        /* nofify register appications */
        /* call MMI SCR api to notify receive a file */
        mmi_bt_ftpc_obj_receive_ind();
    }
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_multi_file_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_receiving_aborted_hdlr(U32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_ABORTED_HDL);

#if defined(NOKE_DEBUG)
    noke_dbg_printf( "mmi_bt_ftpc_receiving_aborted_hdlr \n\r" );
#endif
    
     /* release fh before abort_req send*/
    if((act_client_cntx_p+i)->fh_ftpc_recv)
    {
        FS_Close((act_client_cntx_p+i)->fh_ftpc_recv);
        (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
    }

    act_client_cntx_p->total_recv_obj_len = 0;
    act_client_cntx_p->remain_recv_obj_len = 0;
    (act_client_cntx_p + ftpc_cntx_p->curr_idx)->recved_obj_len = 0;
    (act_client_cntx_p + ftpc_cntx_p->curr_idx)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_set_abort_req_sent_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_set_abort_req_sent_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_SET_FLAG_ABORT_REQ_SENT);

    act_client_cntx_p->flag_abort_req_sent = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_reset_abort_req_sent_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_reset_abort_req_sent_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_RESET_FLAG_ABORT_REQ_SENT);

    act_client_cntx_p->flag_abort_req_sent = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_pull_stop_icon_timer_expire_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static void mmi_bt_ftpc_browse_files_failed_timer_expire_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_BROWSE_FILES_FAILED_TIMER);
    if ((act_client_cntx_p + i)->fh_ftpc_recv)
    {
        FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
        (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
    }
    (act_client_cntx_p + i)->browse_depth = 0;

    if (act_client_cntx_p->ftpc_state != MMI_FTPC_STATE_IDLE)
    {
        mmi_bt_ftpc_send_disconnect();
        MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_DISCONNECTING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_read_fs_flag_and_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static void mmi_bt_ftpc_read_fs_flag_and_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_READ_FS_FLAG);
    if (MMI_FTPC_GET_FLAG(MMIFTP_MASK_ROOT_DIR_FULL) == MMI_TRUE)
    {
        /* Notify Root Directory full Screen */
        mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ROOT_DIR_FULL);
    }
    else if (MMI_FTPC_GET_FLAG(MMIFTP_MASK_DISK_FULL) == MMI_TRUE)
    {
        /* Notify Disk full Screen */
        mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_DISK_FULL);
    }
    else if (MMI_FTPC_GET_FLAG(MMIFTP_MASK_FOLDER_ERR) == MMI_TRUE)
    {
        /* Notify Write File Fail Screen */
        mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST);
    }
    else if ((MMI_FTPC_GET_FLAG(MMIFTP_MASK_FS_DEVICE_BUSY) == MMI_TRUE)
                 || (MMI_FTPC_GET_FLAG(MMIFTP_MASK_FS_LOCK_MUTEX_FAIL) == MMI_TRUE))
    {
        /* Notify Write File Fail Screen */
        mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_FS_DEVICE_BUSY);
    }
    else
    {
        /* default error string, it is temp */
        mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_WRITE_FILE_FAIL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_set_fs_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static void mmi_bt_ftpc_set_fs_flag(int ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_FTPC_SET_FS_FLAG);

    if (ret == FS_DISK_FULL)
    {
        MMI_FTPC_SET_FLAG(MMIFTP_MASK_DISK_FULL);
    }
    else if (ret == FS_ROOT_DIR_FULL)
    {
        MMI_FTPC_SET_FLAG(MMIFTP_MASK_ROOT_DIR_FULL);
    }
    else if(ret == FS_DEVICE_BUSY)
    {
        MMI_FTPC_SET_FLAG(MMIFTP_MASK_FS_DEVICE_BUSY);
    }
    else if(ret == FS_LOCK_MUTEX_FAIL)
    {
        MMI_FTPC_SET_FLAG(MMIFTP_MASK_FS_LOCK_MUTEX_FAIL);
    }
    else
    {
        MMI_FTPC_SET_FLAG(MMIFTP_MASK_WRITE_FILE_FAIL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_permit_show_pair_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  U32 index
 *****************************************************************************/
static MMI_BOOL mmi_bt_ftpc_permit_show_pair_scr(mmi_bth_bt_addr bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_client_cntx_p->ftpc_bt_device.lap == bt_addr.lap
         && act_client_cntx_p->ftpc_bt_device.uap == bt_addr.uap
         && act_client_cntx_p->ftpc_bt_device.nap == bt_addr.nap
         && act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_DISCONNECTING)
    {
        ret = MMI_FALSE;
    }

    return ret;
}



#endif /* __MMI_FTC_SUPPORT__ */ 
#define END_FTP_CORE_FUNCTION

#define FTP_EVENT_HDLR


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_disconnect_ind_hdlr
 * DESCRIPTION
 *  This function is to to handle FTP_DISCONNECT_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_disconnect_ind_struct *ind = (goep_disconnect_ind_struct*) msg;
    goep_deregister_server_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTS_SUPPORT__  
    MMI_FTP_LOG4(
        MMI_BT_FTP_FTPS_DISCONNECT_IND_HDLR,
        ind->goep_conn_id,
        ind->req_id,
        ftps_cntx_p->goep_conn_id[0],
        ftps_cntx_p->conn_cntx[0].ftps_state);
#endif

#ifdef __MMI_FTC_SUPPORT__  
    MMI_FTP_LOG5(
        MMI_BT_FTP_FTPC_DISCONNECT_IND_HDLR,
        ind->goep_conn_id,
        ind->req_id,
        ftpc_cntx_p->goep_conn_id[0],
        ftpc_cntx_p->req_id[0],
        ftpc_cntx_p->conn_cntx[0].ftpc_state);
#endif

#ifdef __MMI_FTC_SUPPORT__
    /*two case:  1. connecting, cancel
      *               2. connecting, remove remote battery 
      */
    if (ind->goep_conn_id == 0xFF)
    {
        for (i = 0; i < FTP_MAX_SERVER_SUPPORT; i++)
        {
            if (ftpc_cntx_p->req_id[i] == ind->req_id)
            {
                /* reset context for later connect request */
                ftpc_cntx_p->req_id[i] = 0xFF;

                /* remove battery to popup, string same as conn_rsp failed*/
                if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_CONNECTING)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_UNFINISHED),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);

                    /* once the state is changed to disconecting, the connect failed call back must be called*/
                    mmi_bth_multiple_connect_cnf_hdler(
                        MMI_FALSE,
                        (act_client_cntx_p + i)->ftpc_bt_device.lap,
                        (act_client_cntx_p + i)->ftpc_bt_device.uap,
                        (act_client_cntx_p + i)->ftpc_bt_device.nap,
                        NULL,
                        (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                        (U32) 0,
                        ind->req_id);
                }

                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_IDLE);
                
                mmi_bt_ftpc_disconnect_clear_scrs();
                mmi_bt_ftp_connection_terminated(i, MMI_BT_CLIENT_ROLE);
                return;
            }
        }
        FTP_DEBUG(kal_print("CONNECT CACEL CASE: FTPC FIND INDEX THROUGH REQ_ID FAILED\n");)
        MMI_FTP_LOG(MMI_BT_FTPC_DISCONN_IND_HDLR_FIND_INDEX_FAILED_CONN_CACEL);
        return;        
    }
#endif

#ifdef __MMI_FTS_SUPPORT__   
    /* identify ftps conection or ftpc connection */
    i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);
    if (i == 0xFF)
    {
    #ifdef __MMI_FTC_SUPPORT__
         /* Open FTS and FTC*/
        i = mmi_bt_ftpc_find_goep_id(ind->goep_conn_id);
        if (i == 0xFF)
        {
            /* reset state */
            if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_IDLE)
            {
                return;
            }
            else
            {
                /* client and server all can not find goep_conn_id*/
                FTP_DEBUG(kal_print("FTS AND FTC ALL OPEN: FTP FIND INDEX FAILED\n");)
                MMI_FTP_LOG(MMI_BT_FTP_DISCONNECT_IND_HDLR_FIND_INDEX_FAILED);
                return;
            }
        }
        else
        {
            /* FTC find goep_conn_id */
            goto CLIENT_CONN;
        }
    #else  /* __MMI_FTC_SUPPORT__ */
        /* only open FTS, can not found the goep_conn_id*/
        FTP_DEBUG(kal_print("ONLY OPEN FTS: FTPS FIND INDEX FAILED\n");)
        MMI_FTP_LOG(MMI_BT_FTPS_DISCONN_IND_HDLR_FIND_INDEX_FAILED_ONLY_FTPS);
        return;
    #endif /* __MMI_FTC_SUPPORT__ */
    }
#else  /* __MMI_FTS_SUPPORT__  */
    #ifdef __MMI_FTC_SUPPORT__
    {
        /* only open FTC */
        i = mmi_bt_ftpc_find_goep_id(ind->goep_conn_id);
        if (i == 0xFF)
        {
            /* reset state */
            if (act_client_cntx_p->ftpc_state == MMI_FTPC_STATE_IDLE)
            {
                return;
            }
            else
            {
                FTP_DEBUG(kal_print("ONLY OPEN FTC: FTPS FIND INDEX FAILED\n");)
                MMI_FTP_LOG(MMI_BT_FTPS_DISCONN_IND_HDLR_FIND_INDEX_FAILED_ONLY_FTPC);
                return;
            }
        }
        goto CLIENT_CONN;
    }
    #endif
#endif /* __MMI_FTS_SUPPORT__  */

#ifdef __MMI_FTS_SUPPORT__   
    FTP_DEBUG(kal_print("DISCONNECT IND HDLR CHECK SERVER CONNECTION\n");)
        /* update the context and call ind function to CM */
        switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_AUTHORIZING:
            mmi_bt_ftps_notify_disconnected();
            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACTIVE);        /* state -> active */
            FTP_DEBUG(kal_print("DISCONNECT IND STATE DISCONNECTING\n");)
            mmi_bth_disconnect_ind_hdler((act_server_cntx_p + i)->ftps_bt_device.lap, (act_server_cntx_p + i)->ftps_bt_device.uap, (act_server_cntx_p + i)->ftps_bt_device.nap, (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID, (U32) ftps_cntx_p->g_conn_id[i]);      /* call CM */

            /* reset context */
            mmi_bt_ftp_connection_terminated(i, MMI_BT_SERVER_ROLE);
            return;

            case MMI_FTPS_STATE_DISCONNECTING:
            FTP_DEBUG(kal_print("DISCONNECT IND STATE DISCONNECTING\n");)
            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACTIVE);        /* state -> active */
            /*call CM*/
            if(act_server_cntx_p->discon_not_from_cm == MMI_TRUE)
            {
                mmi_bth_disconnect_ind_hdler(
                    (act_server_cntx_p + i)->ftps_bt_device.lap, 
                    (act_server_cntx_p + i)->ftps_bt_device.uap, 
                    (act_server_cntx_p + i)->ftps_bt_device.nap, 
                    (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID, 
                    (U32) ftps_cntx_p->g_conn_id[i]); 
            }
            else
            {
                mmi_bth_disconnect_cnf_hdler(
                    MMI_TRUE,
                    (act_server_cntx_p + i)->ftps_bt_device.lap,
                    (act_server_cntx_p + i)->ftps_bt_device.uap,
                    (act_server_cntx_p + i)->ftps_bt_device.nap,
                    (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                    (U32) ftps_cntx_p->g_conn_id[i]);
            }
                
            /* reset context */
            mmi_bt_ftp_connection_terminated(i, MMI_BT_SERVER_ROLE);
            return;
        case MMI_FTPS_STATE_DEACTIVATING:
                FTP_DEBUG(kal_print("DISCONNECT IND STATE DEACTIVATING\n");)
                /* Construct goep deregister req ilm */
                req =
                (goep_deregister_server_req_struct*) OslConstructDataPtr(sizeof(goep_deregister_server_req_struct));
            FTP_MEMSET(req);    /* memory init */
            req->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

            /* Send MSG_ID_GOEP_DEREGISTER_SERVER_REQ primitive */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_DEREGISTER_SERVER_REQ, req);

            /* call disconnect ind to notify CM */
            mmi_bth_disconnect_ind_hdler(
                (act_server_cntx_p + i)->ftps_bt_device.lap,
                (act_server_cntx_p + i)->ftps_bt_device.uap,
                (act_server_cntx_p + i)->ftps_bt_device.nap,
                (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                (U32) ftps_cntx_p->g_conn_id[i]);
            /* reset context */
            mmi_bt_ftp_connection_terminated(i, MMI_BT_SERVER_ROLE);
            return;
            /* connected states */
        case MMI_FTPS_STATE_ACTIVE:
        case MMI_FTPS_STATE_ACCEPTED:
        case MMI_FTPS_STATE_SENDING:
        case MMI_FTPS_STATE_RECEIVING:
                FTP_DEBUG(kal_print("DISCONNECT IND CONNECTED STATE \n");)

            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACTIVE);
            /* call disconnect ind to notify CM */
            if (ftps_cntx_p->g_conn_id[i] != 0xFF)
            {
                mmi_bth_disconnect_ind_hdler(
                    (act_server_cntx_p + i)->ftps_bt_device.lap,
                    (act_server_cntx_p + i)->ftps_bt_device.uap,
                    (act_server_cntx_p + i)->ftps_bt_device.nap,
                    (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                    (U32) ftps_cntx_p->g_conn_id[i]);
            }

            /* reset context */
            mmi_bt_ftp_connection_terminated(i, MMI_BT_SERVER_ROLE);
            return;
            /* not connected yet */
        default:
                FTP_DEBUG(kal_print("DISCONNECT IND STATE ERROR (state: %d)\n",(act_server_cntx_p+i)->ftps_state);)
                MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTP_ASSERT(0);
            return;
    }
#endif        /* __MMI_FTS_SUPPORT__  */

#ifdef __MMI_FTC_SUPPORT__
  CLIENT_CONN:
    FTP_DEBUG(kal_print("DISCONNECT IND HDLR CHECK CLIENT CONNECTION\n");)
    switch ((act_client_cntx_p + i)->ftpc_state)
    {
        case MMI_FTPC_STATE_IDLE:
            MMI_FTP_ASSERT(0);
            return;
            /* should happen in cancel case not here */
        case MMI_FTPC_STATE_CONNECTING:
            FTP_DEBUG(kal_print("DISCONNECT RSP STATE ERROR (state: %d)\n",(act_client_cntx_p+i)->ftpc_state);)
            /* MMI_FTPS_LOG_STATE_ERR(i); */
            MMI_FTP_ASSERT(0);
            break;
        case MMI_FTPC_STATE_DISCONNECTING:
        case MMI_FTPC_STATE_ABORTING:
        case MMI_FTPC_STATE_TPDISCONNECTING:
            MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_IDLE);   /* state -> active */
            mmi_bth_disconnect_ind_hdler((act_client_cntx_p + i)->ftpc_bt_device.lap, (act_client_cntx_p + i)->ftpc_bt_device.uap, (act_client_cntx_p + i)->ftpc_bt_device.nap, (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID, (U32) ftpc_cntx_p->g_conn_id[i]);        /* call CM */
            /* reset context */
            mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);
            mmi_bt_ftp_connection_terminated(i, MMI_BT_CLIENT_ROLE);
            mmi_bt_ftpc_disconnect_clear_scrs();
            return;

            /* other connected states */
        default:
            MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_IDLE);   /* state -> active */
            mmi_bth_disconnect_ind_hdler((act_client_cntx_p + i)->ftpc_bt_device.lap, (act_client_cntx_p + i)->ftpc_bt_device.uap, (act_client_cntx_p + i)->ftpc_bt_device.nap, (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID, (U32) ftpc_cntx_p->g_conn_id[i]);        /* call CM */
            /* reset context */
            mmi_bt_ftp_connection_terminated(i, MMI_BT_CLIENT_ROLE);
            mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);
            /* Notify MMI Screen */
            mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_CONNECTION_DISCONNECTED);       /* Pop up error messages */
            DeleteScreenIfPresent(SCR_FTP_FILE_BROWSER);
            return;
    }
#endif /* __MMI_FTC_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_usb_plugin_hdle
 * DESCRIPTION
 *  the call back func when usb plug in 
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_usb_plugin_hdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ftpc: 
        connecting: 
        connected:  no handle
        getting obj: delete the temp file
        aborting:  sent abort_req,  
                       not sent abort_req,  delete the temp file,   handle disconnect in del callback.
        ftps: 
        sending, reset cntx, disconnect; 
        receiving, delete temp file, reset cntx, disconnect; 
        accepted, del callback
        authorizing: del callback*/
#ifdef __MMI_FTS_SUPPORT__  
    mmi_bt_ftps_usb_plugin_hdle();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_usb_plugin_check
 * DESCRIPTION
 *  the check func for callback when usb mass plug in
 *  True: execute; False: not execute
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bt_ftp_usb_plugin_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTS_SUPPORT__  
    if((act_server_cntx_p + i)->ftps_state == MMI_FTPS_STATE_RECEIVING)
    {
        return MMI_TRUE;
    }
#endif
        return MMI_FALSE;

}

#ifdef __MMI_FTS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_sdp_register_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_sdp_register_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_cnf_struct *cnf = (bt_sdpdb_register_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SDP register success */
    if (cnf->result == 0x00)
    {
        /* call activate cnf to CM */
        mmi_bth_activate_cnf_hdler((U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID);
    }
    /* SDP register failed */
    else
    {
        FTP_DEBUG(kal_print("FTPS SDP REGISTER CNF ERROR RESULT: %d\n",cnf->result);)
        MMI_FTP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_sdp_deregister_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_sdp_deregister_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    bt_sdpdb_deregister_cnf_struct *cnf = (bt_sdpdb_deregister_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SDP register Failed */
    if (cnf->result != 0x00)
    {
        FTP_DEBUG(kal_print("FTPS SDP DEREGISTER CNF ERROR RESULT: %d\n",cnf->result);)
        MMI_FTP_ASSERT(0);
    }

    /* deregister the goep connections */
    for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        goep_deregister_server_req_struct *req;
        mmi_bth_bt_addr bd_addr;

        MMI_FTP_LOG1(MMI_BT_FTP_FTPS_SDP_DEREGISTER_CNF_HDLR, (act_server_cntx_p + i)->ftps_state);
        switch ((act_server_cntx_p + i)->ftps_state)
        {
                /* can't deactivate twice */
            case MMI_FTPS_STATE_DEACTIVATING:
                MMI_FTPS_LOG_STATE_ERR(i);
                MMI_FTP_ASSERT(0);
                break;
                /* do nothing (handle this case in disconnecting rsp) */
            case MMI_FTPS_STATE_DISCONNECTING:
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_DEACTIVATING);
                break;
                /* states with active connection */
            case MMI_FTPS_STATE_ACTIVE:
                //Connection sync to RFCOMM channel == Authorize
                //both accept and reject will send disconnect req to goep
                if (ftps_cntx_p->g_conn_id[i] == 0xFF)
                {
                    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_DEACTIVATING);
                    /* Construct goep deregister server req ilm */
                    req =
                        (goep_deregister_server_req_struct*)
                        OslConstructDataPtr(sizeof(goep_deregister_server_req_struct));
                    FTP_MEMSET(req);    /* memory init */
                    req->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
                    mmi_bt_ftp_send_msg(MSG_ID_GOEP_DEREGISTER_SERVER_REQ, req);
                    break;
                }
            case MMI_FTPS_STATE_ACCEPTED:
            case MMI_FTPS_STATE_RECEIVING:
            case MMI_FTPS_STATE_SENDING:
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_DEACTIVATING);
                /* send disconnect req to goep */
                memset(&bd_addr, 0, sizeof(mmi_bth_bt_addr));
                mmi_bt_ftps_disconnect_client(bd_addr, ftps_cntx_p->g_conn_id[i]);
                break;

            case MMI_FTPS_STATE_IDLE:
                return;

                /* other states without connection */
            default:
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_DEACTIVATING);
                /* Construct goep deregister server req ilm */
                req =
                    (goep_deregister_server_req_struct*)
                    OslConstructDataPtr(sizeof(goep_deregister_server_req_struct));
                FTP_MEMSET(req);    /* memory init */
                req->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
                mmi_bt_ftp_send_msg(MSG_ID_GOEP_DEREGISTER_SERVER_REQ, req);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_register_server_rsp_hdlr
 * DESCRIPTION
 *  This function is to handle server REGISTER_RSP msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_register_server_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_register_server_rsp_struct *rsp = (goep_register_server_rsp_struct*) msg;
    bt_sdpdb_register_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* index exceeds the num of client supported */
    if (rsp->req_id >= FTP_MAX_CLIENT_SUPPORT)
    {
        FTP_DEBUG(kal_print("FTPS REGISTER RSP ERROR (req_id >= client support)\n");)
        MMI_FTP_ASSERT(0);
    }
    /* rsp->req_id == the connection index */
    switch ((act_server_cntx_p + rsp->req_id)->ftps_state)
    {
            MMI_FTP_LOG1(MMI_BT_FTP_FTPS_REGISTER_SERVER_RSP_HDLR, (act_server_cntx_p + rsp->req_id)->ftps_state);
        case MMI_FTPS_STATE_REGISTERING:
            if (rsp->rsp_code == GOEP_STATUS_SUCCESS)   /* success */
            {
                /* save goep connection id */
                ftps_cntx_p->goep_conn_id[rsp->req_id] = rsp->goep_conn_id;
                MMI_FTPS_STATE_TRANS(rsp->req_id, MMI_FTPS_STATE_ACTIVE);
            }
            else    /* error handling */
            {
                MMI_FTPS_STATE_TRANS(rsp->req_id, MMI_FTPS_STATE_IDLE);
                MMI_FTP_ASSERT(0);
            }
            break;

        case MMI_FTPS_STATE_IDLE:
            return;

        default:
            MMI_FTPS_LOG_STATE_ERR(rsp->req_id);
            MMI_FTP_ASSERT(0);
            break;
    }

    /* if there is connection wating for register response don't register SDP */
    for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        if ((act_server_cntx_p + i)->ftps_state == MMI_FTPS_STATE_REGISTERING)
        {
            return;
        }
    }
    /* Send SDP Register primitive */
    req = (bt_sdpdb_register_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_register_req_struct));
    FTP_MEMSET(req);    /* memory init */
    req->uuid = (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID;
    /* send req to bt */
    mmi_bt_ftp_send_msg(MSG_ID_BT_SDPDB_REGISTER_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_deregister_server_rsp_hdlr
 * DESCRIPTION
 *  This function is to handle server DEREGISTER_RSP msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_deregister_server_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_deregister_server_rsp_struct *rsp = (goep_deregister_server_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* chcek rsp code first */
    switch (rsp->rsp_code)
    {
            /* deregister success */
        case GOEP_STATUS_SUCCESS:
            break;
            /* deregister failed */
        default:
            MMI_FTP_ASSERT(0);
            break;
    }

    /* find the connection then reset the context */
    i = mmi_bt_ftps_find_goep_id(rsp->goep_conn_id);

    /* reset */
    if (i == 0xff)
    {
        return;
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_DEREGISTER_SERVER_RSP_HDLR, (act_server_cntx_p + i)->ftps_state);

    switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_DEACTIVATING:
            /* switch state to IDLE */
            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_IDLE);   /* don't have to reset context */
            break;
        default:                                            /* Exception!! only the state deactivatig is allowed */
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTP_ASSERT(0);
            return;
    }
    /* if there is any connection wating for deregister response? */
    for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
    {
        if ((act_server_cntx_p + i)->ftps_state == MMI_FTPS_STATE_DEACTIVATING)
        {
            return;
        }
    }
    /* no connection is wating for deregister rsp -> deactivate cnf to CM */
    mmi_bth_deactivate_cnf_hdler((U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_connect_ind_hdlr
 * DESCRIPTION
 *  This function is to handle server CONNECT_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_connect_ind_struct *ind = (goep_connect_ind_struct*) msg;
    goep_connect_res_struct *res;
    goep_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the goep_conn_id */
    i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);

    /* reset */
    if (i == 0xff)
    {
        return;
    }

    /* check the bd_addr correctness (authorize one == connecting one) */
    if (memcmp(&(((act_server_cntx_p + i)->ftps_bt_device).lap), &(ind->bd_addr.lap), 4) ||
        memcmp(&(((act_server_cntx_p + i)->ftps_bt_device).uap), &(ind->bd_addr.uap), 1) ||
        memcmp(&(((act_server_cntx_p + i)->ftps_bt_device).nap), &(ind->bd_addr.nap), 2))
    {
        FTP_DEBUG(kal_print("FTPS CONNECT IND BUT DIFFERENT BD_ADDR BETWEEN AUTHORIZE\n");)
        MMI_FTP_ASSERT(0);
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_CONNECT_IND_HDLR, (act_server_cntx_p + i)->ftps_state);
    /* check the connection state */
    switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_ACTIVE: /* correct state to accept the authorize ind */
            if(mmi_bt_ftp_check_folder_existed(ftps_cntx_p->root_folder) == MMI_FALSE)
            {
                res = (goep_connect_res_struct*) OslConstructDataPtr(sizeof(goep_connect_res_struct));
                FTP_MEMSET(res);    
                res->rsp_code = GOEP_NOT_FOUND ; 
                res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

                mmi_bt_ftp_send_msg(MSG_ID_GOEP_CONNECT_RES, res);
                return;
            }
                
            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
            /* check the max transfer unit size */
            if (ind->peer_mru < FTPS_MEM_BUFF_SIZE)
            {
                (act_server_cntx_p + i)->send_obex_pkt_size = ind->peer_mru;
            }
            else
            {
                (act_server_cntx_p + i)->send_obex_pkt_size = FTPS_MEM_BUFF_SIZE;
            }

            /* Construct goep connect res ilm */
            res = (goep_connect_res_struct*) OslConstructDataPtr(sizeof(goep_connect_res_struct));
            FTP_MEMSET(res);    /* memory init */
            res->rsp_code = GOEP_STATUS_SUCCESS;
            res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

            /* Send MSG_ID_GOEP_CONNECT_RES primitive */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_CONNECT_RES, res);

            /* update ftps context */
            ftps_cntx_p->g_conn_id[i] = ind->cm_conn_id;

            /* call connect ind hdlr to notify CM */
            mmi_bth_connect_ind_hdler(
                (act_server_cntx_p + i)->ftps_bt_device.lap,
                (act_server_cntx_p + i)->ftps_bt_device.uap,
                (act_server_cntx_p + i)->ftps_bt_device.nap,
                (act_server_cntx_p + i)->dev_name,
                (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                (U32) ftps_cntx_p->g_conn_id[i]);

            return;
        case MMI_FTPS_STATE_ACCEPTED:   /* IVT IOT Cover */
            /* send connect res failed to client */
            /* Construct goep connect res ilm */
            res = (goep_connect_res_struct*) OslConstructDataPtr(sizeof(goep_connect_res_struct));
            FTP_MEMSET(res);            /* memory init */
            res->rsp_code = GOEP_CONFLICT;
            res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

            /* Send MSG_ID_GOEP_CONNECT_RES primitive */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_CONNECT_RES, res);

            /* send disconnect req to client */
            /* switch ftps state to disconnecting */
            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_DISCONNECTING);
            /* Construct Disconnect REQ to goep */
            req = (goep_disconnect_req_struct*) OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
            FTP_MEMSET(req);    /* memory init */
            req->goep_conn_id = ftps_cntx_p->goep_conn_id[i];

            /* Send Disconnect REQ to goep */
            mmi_bt_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);

            act_server_cntx_p->discon_not_from_cm = MMI_TRUE;
            return;
        default:    /* wrong state */
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTP_ASSERT(0);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_push_ind_hdlr
 * DESCRIPTION
 *  This function is to handle server PUSH_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_push_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_push_ind_struct *ind = (goep_push_ind_struct*) msg;
    goep_push_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the connection */
    i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);

    /* reset */
    if (i == 0xff)
    {
        return;
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PUSH_IND_HDLR, (act_server_cntx_p + i)->ftps_state);

    /* Check the access right first. If the access right is read only, return failed directly */
    if (ftps_cntx_p->access_right == MMI_FTP_ACCESS_RIGHT_READ_ONLY)
    {
        /* Wrong Access Right */
        /* send res with rsp_code GOEP_UNAUTHORIZED */
        FTP_DEBUG(kal_print("FTPS PUSH IND HDLR -- ACCESS RIGHT ERROR\n");)

        if ((act_server_cntx_p + i)->ftps_state == MMI_FTPS_STATE_RECEIVING)
        {
            FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
            (act_server_cntx_p + i)->fh_ftps_recv = 0;

            mmi_bt_ftp_delete_file(
                (act_server_cntx_p + i)->current_folder, 
                (act_server_cntx_p + i)->ftps_obj_name);            
        }
            /* Construct goep set folder res ilm */
            res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
        FTP_MEMSET(res);    /* memory init */
        res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        res->rsp_code = GOEP_UNAUTHORIZED;
        goto FTPS_PUSH_IND_SEND;
    }

    /* check state to enter different handle case */
    switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_ACCEPTED:
            /* put obj */
            if (ind->put_type == GOEP_PUT_NORMAL || ind->put_type == GOEP_CREATEEMPTY)
            {
                /*forbbiden 0 size normal file push for IVT IOT*/
                if(ind->frag_len == 0 && ind->total_obj_len == 0 
                    && ind->put_type == GOEP_PUT_NORMAL)
                {
                    /* Construct goep set folder res ilm */
                    res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
                    FTP_MEMSET(res);    /* memory init */
                    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
                    /* send push res to goep with error rsp_code server internal error */
                    res->rsp_code = GOEP_FORBIDDEN;
                    goto FTPS_PUSH_IND_SEND;
                }
                
                /* Blink Test */
                mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_START);
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_RECEIVING);

                /* call ftps push obj routine and send res to client */
                mmi_bt_ftps_push_obj(ind, i);
                return;
            }
            /* delete obj */
            else if (ind->put_type == GOEP_PUT_DELETE)
            {
                /* Blink Test */
                mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_START);
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_RECEIVING);

                /* call ftps push delete routine and send res to client */
                mmi_bt_ftps_push_delete(ind, i);
            }
            return;
        case MMI_FTPS_STATE_RECEIVING:  /* continue */
            /* can't support simultaneously receiving */
            if ((ind->pkt_type == GOEP_FIRST_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
            {
                FTP_DEBUG(kal_print("PUSH IND WITH WRONG PKT_TYPE(FIRST->FIRST)\n");)              
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

                /* Blink Test */
                mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

                /* Construct goep set folder res ilm */
                res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
                FTP_MEMSET(res);    /* memory init */
                res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
                /* send push res to goep with error rsp_code server internal error */
                res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
                goto FTPS_PUSH_IND_SEND;
            }
            else    /* not another first req */
            {
                /* call ftps push continue routine and send res to client */
                mmi_bt_ftps_write_obj_continue(ind, i);
                return;
            }
        case MMI_FTPS_STATE_SENDING:    /* wrong sequence msg incoming (error handling) */
            FTP_DEBUG(kal_print("PUSH IND IN WRONG STATE(SENDING)\n");)
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

            /* Blink Test */
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

            /* Construct goep set folder res ilm */
            res = (goep_push_res_struct*) OslConstructDataPtr(sizeof(goep_push_res_struct));
            FTP_MEMSET(res);    /* memory init */
            res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
            /* send push res to goep with error rsp_code */
            res->rsp_code = GOEP_INTERNAL_SERVER_ERR;
            goto FTPS_PUSH_IND_SEND;
            /* discard this message */
        case MMI_FTPS_STATE_DEACTIVATING:
        case MMI_FTPS_STATE_DISCONNECTING:
            /* Blink Test */
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
            return;
        default:                /* abnormal state */
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTP_ASSERT(0);
            return;
    }
  FTPS_PUSH_IND_SEND:
    /* Send MSG_ID_GOEP_PUSH_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PUSH_RES, res);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_pull_ind_hdlr
 * DESCRIPTION
 *  This function is to handle server PULL_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_pull_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    int ret;
    FS_HANDLE h;
    U8 folder_listing_obj[GOEP_MAX_MIME_TYPE];
    U8 path_buf[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    U8 tmp_name[FTP_MAX_OBJ_NAME_LEN];
    goep_pull_ind_struct *ind = (goep_pull_ind_struct*) msg;
    goep_pull_ind_struct *continue_ind;
    goep_pull_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* continue writing folder content by send self primitive */
    if (strcmp((PS8) ind->obj_mime_type, "continue_writing") == 0)
    {
        FTP_DEBUG(kal_print("FTPS PULL IND HDLR (EMPTY MSG FOR CONTINUE WRITING)\n");)
        path_buf[0] = 0;
        i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);
        /* to write folder content */
        goto FTPS_PULL_IND_CONTINUE_WRITE_FOLDER;
    }
    strcpy((PS8) folder_listing_obj, "x-obex/folder-listing");

    /* find the connection */
    i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);

    /* reset */
    if (i == 0xff)
    {
        return;
    }

    MMI_FTP_LOG2(MMI_BT_FTP_FTPS_PULL_IND_HDLR, (act_server_cntx_p + i)->ftps_state, ind->pkt_type);

    /* check state to enter different handle case */
    switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_ACCEPTED:
            /* common procedures for both folder pulling or file pulling */
            mmi_ucs2cpy((PS8) path_buf, (PS8) (act_server_cntx_p + i)->current_folder);
            memset(tmp_name, 0, FTP_MAX_OBJ_NAME_LEN);

            /* check if there is obj name carried by pull ind */
            if (mmi_ucs2strlen((PS8) ind->obj_name) > 0)
            {
                /* fail-safe for enough memory to store the obj_name */
                if (mmi_ucs2strlen((PS8) ind->obj_name) * 2 > FTP_MAX_OBJ_NAME_LEN - 2)
                {
                    FTP_DEBUG(kal_print("FTPS PULL IND HDLR INVALID NAME\n");)
                        /* send pull res to goep with error rsp_code */
                        goto FTPS_PULL_IND_ERR;
                }
                mmi_bt_ftp_obj_name_swapcpy(tmp_name, ind->obj_name);
            }

            /* check pull folder listing or file */
            /* pull a file */
            if (strcmp((PS8) ind->obj_mime_type, (PS8) folder_listing_obj))
            {
                int j;

                /* fail-safe for enough memory to store the obj_name + obj_path (1 = '\0') */
                if (mmi_ucs2strlen((PS8) path_buf) + mmi_ucs2strlen((PS8) tmp_name) > (FMGR_MAX_PATH_LEN - 1))
                {
                    FTP_DEBUG(kal_print("FTPS PULL IND HDLR INVALID NAME\n");)
                    goto FTPS_PULL_IND_ERR;
                }

                /* switch '/' to '\' if necessary */
                for (j = 0; j < FTP_MAX_OBJ_NAME_LEN;)
                {
                    /* '/' */
                    if (tmp_name[j] == 0x2F && tmp_name[j+1] == 0)
                    {
                        /* switch */
                        tmp_name[j] = 0x5C;
                    }
                    /* '\' */
                    else if (tmp_name[j] == 0x5C && tmp_name[j+1] == 0)
                    {
                        /* don't have to change */
                        break;
                    }
					j += 2;
                }
                mmi_ucs2cat((PS8) path_buf, (PS8) tmp_name);

#if defined(__DRM_SUPPORT__)
                /* drm check: if not allow to forward out */
                if(!DRM_interdev_movable(0, (kal_wchar*)path_buf))
                {
                    FTP_DEBUG(kal_print("FTPS PULL FILE DRM FORBIDDEN\n");)

                    res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
                    FTP_MEMSET(res);    
                    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
                    res->rsp_code = GOEP_FORBIDDEN;

                    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
                    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
                    return;
                }
#endif

                /* check does the obj exist? */
                h = FS_Open((kal_uint16*) path_buf, FS_READ_ONLY);
                if (h < 0)
                {
                    FTP_DEBUG(kal_print("FTPS PULL IND HDLR FS_OPEN ERROR\n");)
                    goto FTPS_PULL_IND_ERR;                    
                }
                else
                {
                    (act_server_cntx_p + i)->fh_ftps_send = h;
                }
                /* Blink Test */
                {
                    mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_START);
                }

                /* send obj */
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_SENDING);
                mmi_bt_ftps_send_obj(ind, i);

            }
            /* pull a folder content */
            else
            {
                /* fail-safe for enough memory to store the obj_name + obj_path (2 = '\','\0') */
                if (mmi_ucs2strlen((PS8) path_buf) + mmi_ucs2strlen((PS8) tmp_name) > (FMGR_MAX_PATH_LEN - 2))
                {
                    FTP_DEBUG(kal_print("FTPS PULL IND HDLR FS_OPEN ERROR\n");)
                    goto FTPS_PULL_IND_ERR;
                }

                /* check if there is obj name carried by pull ind */
                if (mmi_ucs2strlen((PS8) ind->obj_name) > 0)
                {
                    mmi_ucs2cat((PS8) path_buf, (PS8) tmp_name);
                    mmi_ucs2cat((PS8) path_buf, (const PS8)L"\\");
                }

                /* without carring folder name -> get current folder */
                /* check does the folder exist? If not, create the folder */
                h = FS_Open((kal_uint16*) path_buf, FS_OPEN_DIR | FS_READ_ONLY);
                if (h < 0)
                {
                    FTP_DEBUG(kal_print("FTPS PULL IND HDLR FS_OPEN ERROR\n");)
                    FS_Delete((const WCHAR*)((act_server_cntx_p+i)->folder_content));   
                    goto FTPS_PULL_IND_ERR;
                }
                else
                {
                    FS_Close(h);
                }

                /* to write folder content */
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_SENDING);
                goto FTPS_PULL_IND_CONTINUE_WRITE_FOLDER;
            }
            return;
        case MMI_FTPS_STATE_SENDING:    /* continue */
            /* can't support simultaneously sending */
            if ((ind->pkt_type == GOEP_FIRST_PKT) || (ind->pkt_type == GOEP_SINGLE_PKT))
            {
                FTP_DEBUG(kal_print("FTPS PULL IND WITH WRONG PKT_TYPE(FIRST->FIRST)\n");)              
                MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

                /* Blink Test */
                mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

                /* send pull res to goep with error rsp_code */
                goto FTPS_PULL_IND_ERR;
            }
            else    /* not another first req */
            {
                mmi_bt_ftps_pull_continue(i);
                return;
            }
        case MMI_FTPS_STATE_RECEIVING:  /* wrong sequence msg incoming (error handling) */
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

            /* Blink Test */
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

            /* send pull res to goep with error rsp_code */
            goto FTPS_PULL_IND_ERR;
            /* discard this message */
        case MMI_FTPS_STATE_DEACTIVATING:
        case MMI_FTPS_STATE_DISCONNECTING:
            /* Blink Test */
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
            return;
        default:    /* abnormal state */
            MMI_FTPS_LOG_STATE_ERR(i);
            /* MMI_FTP_ASSERT(0);*/
            return;
    }

  FTPS_PULL_IND_CONTINUE_WRITE_FOLDER:

    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PULL_IND_HDLR_CONTINUE_WRITE_FOLDER, (act_server_cntx_p + i)->ftps_state);

    /* if state is changed -> error */
    if ((act_server_cntx_p + i)->ftps_state != MMI_FTPS_STATE_SENDING)
    {
        FS_FindClose((act_server_cntx_p + i)->fh_ftps_generating);
        FS_Close(((act_server_cntx_p + i)->xml_composer).fd);
        FS_Delete((const WCHAR*)((act_server_cntx_p + i)->folder_content));
        /* don't assert! because of the reason is disconnecting or deactivating */
        return;
    }

    /* generating folder listing object (folder path store in path_buff) */
    ret = mmi_bt_ftps_gen_folder_content(i, path_buf);

    /* if the folder content is done -> send folder content, else send primitive to self */
    /* continue generating folder content */
    if (ret > 0)
    {
        FTP_DEBUG(kal_print("FTPS PULL IND CONTINUE WRITE FOLDER (SEND CONTINUE MSG TO SELF)\n"););

        /* Construct goep pull ind ilm */
        continue_ind = (goep_pull_ind_struct*) OslConstructDataPtr(sizeof(goep_pull_ind_struct));
        FTP_MEMSET(continue_ind);   /* memory init */
        continue_ind->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
        memcpy(continue_ind->uuid, OBEX_FTP_UUID, 16);
        continue_ind->uuid_len = 16;
        sprintf((PS8) continue_ind->obj_mime_type, "continue_writing");

        mmi_bt_ftp_send_msg_self(MSG_ID_GOEP_PULL_IND, continue_ind);
    }
    /* FS error */
    else if (ret != FS_NO_ERROR)
    {
        MMI_FTP_LOG1(MMI_BT_FTP_FTPS_PULL_IND_HDLR_CONTINUE_WRITE_FOLDER_FS_ERROR, ret);

        FTP_DEBUG(kal_print("FTPS PULL IND HDLR CONTINUE WRITE -- GEN FOLDER CONTENT ERROR\n");)

        MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);

        goto FTPS_PULL_IND_ERR;
    }
    /* folder content is done */
    else    /* ret == 0 */
    {
        mmi_bt_ftps_send_folder_content(ind, i);
    }
    return;
  FTPS_PULL_IND_ERR:

    FTP_DEBUG(kal_print("FTPS PULL IND ERR (GOTO)\n");)
    
        /* Construct goep pull res ilm */
        res = (goep_pull_res_struct*) OslConstructDataPtr(sizeof(goep_pull_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;

    /* Send MSG_ID_GOEP_PULL_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_RES, res);
    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
    mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_set_folder_ind_hdlr
 * DESCRIPTION
 *  This function is to handle server SET_FOLDER_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_set_folder_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_set_folder_ind_struct *ind = (goep_set_folder_ind_struct*) msg;
    goep_set_folder_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find out the selected index */
    i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);

    /* reset */
    if (i == 0xff)
    {
        return;
    }

    MMI_FTP_LOG2(MMI_BT_FTP_FTPS_SET_FOLDER_IND_HDLR, (act_server_cntx_p + i)->ftps_state, ind->setpath_flag);

    /* check state for different resetting */
    switch ((act_server_cntx_p + i)->ftps_state)
    {
            /* normal case */
        case MMI_FTPS_STATE_ACCEPTED:
            /* name, back, root, create */
            if (ind->setpath_flag == GOEP_ROOT_FOLDER)
            {
                FS_HANDLE temp_current_path_fh;
                memset((act_server_cntx_p + i)->current_folder, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
                mmi_ucs2cpy((PS8) (act_server_cntx_p + i)->current_folder, (PS8) ftps_cntx_p->root_folder);
                temp_current_path_fh = FS_Open((WCHAR *)((act_server_cntx_p + i)->current_folder), FS_READ_ONLY | FS_OPEN_DIR);
                if(temp_current_path_fh >= FS_NO_ERROR)
                {
                    FS_Close(temp_current_path_fh);
                    goto FTPS_SET_FOLDER_SUCCESS;
                }
                else 
                {
                    goto FTPS_SET_FOLDER_ERR;
                }
            }
            else if (ind->setpath_flag == GOEP_BACK_FOLDER)
            {
                /* call set parent folder routine */
                mmi_bt_ftps_set_parent_folder(i);
                return;
            }
            else if (ind->setpath_flag == GOEP_FORWARD_FOLDER)
            {
                /* call set folder routine */
                mmi_bt_ftps_set_folder(ind, i);
                return;
            }
            else    /* GOEP_CREATE_FOLDER */
            {
                /* call create folder routine */
                /* create folder and set current to new folder (should send res) */
                mmi_bt_ftps_create_folder(ind, i);
                return;
            }
            /* ignore conditions */
        case MMI_FTPS_STATE_DEACTIVATING:
        case MMI_FTPS_STATE_DISCONNECTING:
            /* do nothing */
            return;
            /* error recovery */
        case MMI_FTPS_STATE_SENDING:
            if ((act_server_cntx_p + i)->fh_ftps_send)
            {
                FS_Close((act_server_cntx_p + i)->fh_ftps_send);
                (act_server_cntx_p + i)->total_send_obj_len = 0;
                (act_server_cntx_p + i)->remain_send_obj_len = 0;
                (act_server_cntx_p + i)->fh_ftps_send = 0;
            }
            if ((act_server_cntx_p + i)->send_obj_type == MMI_FTP_OBJ_TYPE_FOLDER)
            {
                FTP_DEBUG(kal_print("FTPS SET FOLDER IND HDLR DEL FOLDER CONTENT FILE\n");)
                    /* delete the folder content file */
                    FS_Delete((const WCHAR*)((act_server_cntx_p + i)->folder_content));
            }
            (act_server_cntx_p + i)->send_obj_type = MMI_FTP_OBJ_TYPE_NONE;
            /* send res with error rsp_code and go back to accepted state */
            goto FTPS_SET_FOLDER_ERR;
            break;
        case MMI_FTPS_STATE_RECEIVING:
            if ((act_server_cntx_p + i)->fh_ftps_recv)
            {
                FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
                (act_server_cntx_p + i)->fh_ftps_recv = 0;
            }
            /* send res with error rsp_code and go back to accepted state */
            goto FTPS_SET_FOLDER_ERR;
            break;
            /* abnormal case (no connection yet -- wrong state) */
        default:
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTP_ASSERT(0);
            return;
    }

  FTPS_SET_FOLDER_SUCCESS:
   FTP_DEBUG(kal_print("FTPS SET FOLDER SUCCESS (GOTO)\n");)
   
        /* Construct goep set folder res ilm */
        res = (goep_set_folder_res_struct*) OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->rsp_code = GOEP_STATUS_SUCCESS;

    /* Send MSG_ID_GOEP_SET_FOLDER_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    return;

  FTPS_SET_FOLDER_ERR:
    FTP_DEBUG(kal_print("FTPS SET FOLDER ERR (GOTO)\n");)
    
        /* Construct goep set folder res ilm */
        res = (goep_set_folder_res_struct*) OslConstructDataPtr(sizeof(goep_set_folder_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
    res->rsp_code = GOEP_INTERNAL_SERVER_ERR;

    /* Send MSG_ID_GOEP_SET_FOLDER_RES primitive */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_SET_FOLDER_RES, res);
    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_abort_ind_hdlr
 * DESCRIPTION
 *  This function is to handle server ABORT_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_abort_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_abort_ind_struct *ind = (goep_abort_ind_struct*) msg;
    goep_abort_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the index of aborting goep connection */
    i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);

    /* reset */
    if (i == 0xff)
    {
        return;
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_ABORT_IND_HDLR, (act_server_cntx_p + i)->ftps_state);

    /* check state for different resetting */
    switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_SENDING:
            if ((act_server_cntx_p + i)->fh_ftps_send)
            {
                FS_Close((act_server_cntx_p + i)->fh_ftps_send);
                (act_server_cntx_p + i)->total_send_obj_len = 0;
                (act_server_cntx_p + i)->remain_send_obj_len = 0;
                (act_server_cntx_p + i)->fh_ftps_send = 0;
            }
            if ((act_server_cntx_p + i)->send_obj_type == MMI_FTP_OBJ_TYPE_FOLDER)
            {
                FTP_DEBUG(kal_print("FTPS ABORT IND HDLR DEL FOLDER CONTENT FILE\n");)
                    /* delete the folder content file */
                    FS_Delete((const WCHAR*)((act_server_cntx_p + i)->folder_content));
            }
            (act_server_cntx_p + i)->send_obj_type = MMI_FTP_OBJ_TYPE_NONE;
            break;
        case MMI_FTPS_STATE_RECEIVING:
            if ((act_server_cntx_p + i)->fh_ftps_recv)
            {
                U8 *all_path_name_ptr;

                /*close file handle, and delete temp file*/
                FS_Close((act_server_cntx_p + i)->fh_ftps_recv);
                (act_server_cntx_p + i)->fh_ftps_recv = 0;

                 /*-------------This code will delete the downloading obj when abort-----BEGIN--------*/
                all_path_name_ptr = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
                MMI_FTP_ASSERT(all_path_name_ptr != NULL);
                memset(all_path_name_ptr, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
                mmi_ucs2cpy((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->current_folder);
                mmi_ucs2cat((PS8) all_path_name_ptr, (PS8) (act_server_cntx_p + i)->ftps_obj_name);
                FS_Delete((const WCHAR*)all_path_name_ptr);
                

                if (all_path_name_ptr)
                {
                    OslMfree(all_path_name_ptr);
                    all_path_name_ptr = NULL;
                }
                /*-------------This code will delete the downloading obj when abort------END--------*/
            }
            break;
            /* ignore conditions (for race condition) */
        case MMI_FTPS_STATE_ACCEPTED:
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
            break;
        case MMI_FTPS_STATE_DEACTIVATING:
        case MMI_FTPS_STATE_DISCONNECTING:
            /* Blink Test */
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
            return;
            /* error recovery */
        default:
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTP_ASSERT(0);
            break;
    }

    MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_ACCEPTED);
    /* Blink Test */
    mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);

    /* film res pkt_type attibute */
    res = (goep_abort_res_struct*) OslConstructDataPtr(sizeof(goep_abort_res_struct));
    FTP_MEMSET(res);    /* memory init */
    res->goep_conn_id = ind->goep_conn_id;
    res->rsp_code = GOEP_STATUS_SUCCESS;

    /* send abort res to goep */
    mmi_bt_ftp_send_msg(MSG_ID_GOEP_ABORT_RES, res);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_authorize_ind_hdlr
 * DESCRIPTION
 *  This function is to handle server AUTHORIZE_IND msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftps_authorize_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_authorize_ind_struct *ind = (goep_authorize_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_bt_ftps_find_goep_id(ind->goep_conn_id);

    /* reset */
    if (i == 0xff)
    {
        return;
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPS_AUTHORIZE_IND_HDLR, (act_server_cntx_p + i)->ftps_state);

    /* for MMI knows the authorizing one */
    ftps_cntx_p->cur_goep_conn_id = ind->goep_conn_id;

    switch ((act_server_cntx_p + i)->ftps_state)
    {
        case MMI_FTPS_STATE_ACTIVE: /* correct state to accept the authorize ind */
    #ifdef __USB_IN_NORMAL_MODE__
            FTP_DEBUG(kal_print("FTPS AUTHORIZE IND IN ACTIVE STATE (USB_NORMAL_MODE)\n");)
            if (mmi_usb_is_in_mass_storage_mode())
            {
                /* in mass storage mode */
                if (mmi_usb_check_path_exported((PS8) ftps_cntx_p->root_folder))
                {
                    goep_authorize_res_struct *res;

                    /* phone drive is exported, cant use this app */
                    mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */

                    /* Construct goep push res ilm */
                    res = (goep_authorize_res_struct*) OslConstructDataPtr(sizeof(goep_authorize_res_struct));
                    FTP_MEMSET(res);    /* memory init */
                    res->goep_conn_id = ftps_cntx_p->goep_conn_id[i];
                    res->rsp_code = GOEP_STATUS_FAILED;
                    mmi_bt_ftp_send_msg(MSG_ID_GOEP_AUTHORIZE_RES, res);
                    return;
                }
            }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

            MMI_FTPS_STATE_TRANS(i, MMI_FTPS_STATE_AUTHORIZING);
            memset((act_server_cntx_p + i)->dev_name, 0, GOEP_MAX_DEV_NAME);
            memset(&((act_server_cntx_p + i)->ftps_bt_device), 0, sizeof(goep_bd_addr_struct));
            strcpy((PS8) (act_server_cntx_p + i)->dev_name, (PS8) (ind->dev_name));
            memcpy(&((act_server_cntx_p + i)->ftps_bt_device), &(ind->bd_addr), sizeof(goep_bd_addr_struct));

            /* show confirm screen */
            if (!isIncomingCall() )
            {
                mmi_bt_ftps_entry_recv_confirm_scr();
                playRequestedTone(WARNING_TONE);
            }
            else
            {
                SetDelScrnIDCallbackHandler(SCR_FTP_NOTY_CONN_REQ, mmi_bt_ftps_authorize_confirm_del_cb);		
                mmi_bt_ftp_add_history_before_cm_marker(SCR_FTP_NOTY_CONN_REQ, mmi_bt_ftps_entry_recv_confirm_scr);
            }

            return;
        default:    /* wrong state */
            MMI_FTPS_LOG_STATE_ERR(i);
            MMI_FTP_ASSERT(0);
            return;
    }
}
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_connect_rsp_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_CONNECT_RSP msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_connect_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_connect_rsp_struct *rsp = (goep_connect_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the corresponding connection */
    for (i = 0; i < FTP_MAX_SERVER_SUPPORT; i++)
    {
        if (ftpc_cntx_p->req_id[i] == rsp->req_id)
        {
            break;
        }
    }

    if (i == FTP_MAX_SERVER_SUPPORT)
    {
        /* without corresponding connect req for this connect rsp */
        /* reset */
        return;
        /* MMI_FTP_ASSERT(0); */
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_CONNECT_RSP_HDLR, (act_client_cntx_p + i)->ftpc_state);

    /* Connection is established successfully  */
    if (rsp->rsp_code == GOEP_STATUS_SUCCESS)
    {
        FTP_DEBUG(kal_print("FTPC CONNECT RSP SUCCESS\n");)
        switch ((act_client_cntx_p + i)->ftpc_state)
        {
                /* discard this msg: connect failed cm call back has been called when connect cancel*/
            case MMI_FTPC_STATE_DISCONNECTING:
                return;
                /* reset */
            case MMI_FTPC_STATE_IDLE:
                return;
            case MMI_FTPC_STATE_CONNECTING:
            {
                goep_pull_req_struct *req;

                /* The connection is established */
                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_GETTING_FOLDER);

                /* set ftpc context */
                (act_client_cntx_p + i)->browse_depth = 0;
                ftpc_cntx_p->goep_conn_id[i] = rsp->goep_conn_id;
                ftpc_cntx_p->g_conn_id[i] = rsp->cm_conn_id;

                /* call connection cnf to CM and send first get list folder packet */
                mmi_bth_multiple_connect_cnf_hdler(
                    MMI_TRUE,
                    (act_client_cntx_p + i)->ftpc_bt_device.lap,
                    (act_client_cntx_p + i)->ftpc_bt_device.uap,
                    (act_client_cntx_p + i)->ftpc_bt_device.nap,
                    NULL,
                    (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                    (U32) rsp->cm_conn_id,
                    rsp->req_id);

                /* construct pull req ilm */
                req = (goep_pull_req_struct*) OslConstructDataPtr(sizeof(goep_pull_req_struct));
                FTP_MEMSET(req);    /* memory init */
                req->goep_conn_id = rsp->goep_conn_id;
                strcpy((PS8) req->obj_mime_type, "x-obex/folder-listing");
                req->pkt_type = GOEP_FIRST_PKT;

                mmi_bt_ftp_send_msg(MSG_ID_GOEP_PULL_REQ, req);
                return;
            }
                /* Connection establish fail */
            default:
                MMI_FTPC_LOG_STATE_ERR(i);

                /* free memory if using dynamic memory mechanism */
                /* (act_client_cntx_p+i)->obj_buff_p = NULL; */
                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_IDLE);

                /* Notify MMI Screen */
                mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_REJECT_FROM_SERVER);
                return;
        }
    }
    else
    {
        FTP_DEBUG(kal_print("FTPC CONNECT RSP ERROR\n");)
        switch ( (act_client_cntx_p+i)->ftpc_state )
        {
            /* discard this msg: connect failed cm call back has been called when connect cancel*/
            case MMI_FTPC_STATE_DISCONNECTING:
                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_IDLE);
                mmi_bt_ftpc_goback2history();
                return;
            case MMI_FTPC_STATE_CONNECTING:
                mmi_bth_multiple_connect_cnf_hdler(
                    MMI_FALSE,
                    (act_client_cntx_p + i)->ftpc_bt_device.lap,
                    (act_client_cntx_p + i)->ftpc_bt_device.uap,
                    (act_client_cntx_p + i)->ftpc_bt_device.nap,
                    NULL,
                    (U32) MMI_BTH_OBEX_FILE_TRANSFER_UUID,
                    (U32) 0,
                    rsp->req_id);
                /* passkey screen del callback */
                mmi_bt_reject_passkey_ind();

                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_IDLE);

                /* Notify MMI Screen */
                if (rsp->rsp_code == GOEP_STATUS_SCO_REJECT)                    
                {
                    /* sco link support for MT6601 */
                    mmi_bt_popup_operation_not_allowed();
                    mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_LAST);
                }
                else if (rsp->rsp_code == GOEP_STATUS_BUSY)
                {
                    mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_GOEP_STATUS_BUSY);
                }
                else
                {
                    mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_REJECT_FROM_SERVER);
                }
                return;

                /* reset */
            case MMI_FTPC_STATE_IDLE:
                return;
            default:
                MMI_FTPC_LOG_STATE_ERR(i);
                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_IDLE);
                /* Notify MMI Screen */
                mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_REJECT_FROM_SERVER);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_pull_rsp_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_PULL_RSP msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_pull_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_pull_rsp_struct *rsp = (goep_pull_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_bt_ftpc_find_goep_id(rsp->goep_conn_id);

    if (i == 0xff)
    {
        /* reset */
        return;
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_PULL_RSP_HDLR, (act_client_cntx_p + i)->ftpc_state);

    switch ((act_client_cntx_p + i)->ftpc_state)
    {
        case MMI_FTPC_STATE_ABORTING:
        /* omit all the pull_rsp after send abort_req, and wait pull_rsp only*/
            if(act_client_cntx_p->flag_abort_req_sent == MMI_TRUE)
                return;
            else
            {
                /* omit this pkt, and send abort req, and set the flag, and reset the vars */
                mmi_bt_ftpc_set_abort_req_sent_flag();
                mmi_bt_ftpc_receiving_aborted_hdlr(0);
                mmi_bt_ftpc_send_abort(rsp->goep_conn_id);
                return;
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
#endif

        case MMI_FTPC_STATE_GETTING_FOLDER:
            /* continue parsing */
        case MMI_FTPC_STATE_PARSING_FOLDER:
            mmi_bt_ftpc_get_folder(rsp, i);
            return;
        case MMI_FTPC_STATE_GETTING_OBJ:
            mmi_bt_ftpc_get_obj(rsp, i);
            return;
        case MMI_FTPC_STATE_DISCONNECTING:
        {
            if (rsp->to_self == MMI_TRUE)
            {
                return;
            }
            /* the last packet of folder content */
            if ((rsp->pkt_type == GOEP_FINAL_PKT) || (rsp->pkt_type == GOEP_SINGLE_PKT))
            {
                /* send disconnect packet */
                goep_disconnect_req_struct *req;

                /* construct disconnect req ilm */
                req = (goep_disconnect_req_struct*) OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
                FTP_MEMSET(req);    /* memory init */
                req->goep_conn_id = ftpc_cntx_p->goep_conn_id[i];

                /* send disconnect req and connect cnf fail to CM */
                mmi_bt_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
            }
            else
            {
                /* send abort packet */
                goep_abort_req_struct *req;

                req = (goep_abort_req_struct*) OslConstructDataPtr(sizeof(goep_abort_req_struct));
                FTP_MEMSET(req);    /* memory init */
                req->goep_conn_id = ftpc_cntx_p->goep_conn_id[i];
                mmi_bt_ftp_send_msg(MSG_ID_GOEP_ABORT_REQ, req);
            }
            return;
        }
        case MMI_FTPC_STATE_IDLE:
        {
            /* 
              *at this time, xml parser has been closed
              * E.G.  When parsing, disconn_ind comes
              */
            if (rsp->to_self == MMI_TRUE)
            {
                return;
            }
        }

        case MMI_FTPC_STATE_TPDISCONNECTING:
            /*Omit it, when setting_folder, tpdiscon may be sent*/
            return;

            /* wrong states */
        default:
            /* error handling */
            MMI_FTPC_LOG_STATE_ERR(i);

            if ((act_client_cntx_p + i)->fh_ftpc_recv)
            {
                FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
                (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
            }

            MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
            mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);
            /* Notify MMI Screen */
            mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_set_folder_rsp_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_SET_FOLDER_RSP msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_set_folder_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_set_folder_rsp_struct *rsp = (goep_set_folder_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPC SET FOLDER RSP HDLR\n");)
    i = mmi_bt_ftpc_find_goep_id(rsp->goep_conn_id);

    if (i == 0xff)
    {
        /* reset */
        return;
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_SET_FOLDER_RSP_HDLR, (act_client_cntx_p + i)->ftpc_state);

    if (rsp->rsp_code == GOEP_STATUS_SUCCESS)
    {
        /* Set the folder successfully, then start to get folder content */
        switch ((act_client_cntx_p + i)->ftpc_state)
        {
            case MMI_FTPC_STATE_SETTING_FOLDER:
                (act_client_cntx_p + i)->browse_depth++;
                break;

            case MMI_FTPC_STATE_SETTING_BACK_FOLDER:
                (act_client_cntx_p + i)->browse_depth--;
                break;

            case MMI_FTPC_STATE_SETTING_ROOT_FOLDER:
                (act_client_cntx_p + i)->browse_depth = 0;
                break;

            case MMI_FTPC_STATE_TPDISCONNECTING:
                /*omit it, tpdisconn_req have sent*/
//                mmi_bt_ftpc_send_disconnect();
                return;

             default:
                /*error state*/
                MMI_FTPC_LOG_STATE_ERR(i);
                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
                /* Notify MMI Screen */
                return;
        }
        MMI_FTPC_STATE_TRANS(0, MMI_FTPC_STATE_CONNECTED);
        mmi_bt_ftpc_get_folder_content();
    }
    else
    {
        switch ((act_client_cntx_p + i)->ftpc_state)
        {
            case MMI_FTPC_STATE_SETTING_FOLDER:
            {
                /* forward folder failed, not disconnect*/
                FTP_DEBUG(kal_print("FTPC SET FORWARD FOLDER RSP HDLR ERROR\n");)
                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
                mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_REJECT_FROM_SERVER);        /* Pop up error messages */

                if ((act_client_cntx_p + i)->fh_ftpc_recv)
                {
                    FS_Close((act_client_cntx_p + i)->fh_ftpc_recv);
                    (act_client_cntx_p + i)->fh_ftpc_recv = (FS_HANDLE) NULL;
                }
            }
            break;
            
            case MMI_FTPC_STATE_SETTING_BACK_FOLDER:
            case MMI_FTPC_STATE_SETTING_ROOT_FOLDER:
            {
                 /*when setting back/root  folder failed, popup and disconnect it*/
                FTP_DEBUG(kal_print("FTPC SET FOLDER RSP HDLR ERROR\n");)

                MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
                mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_BROWSE_FILES_FAILED);
                mmi_bt_ftpc_AddHistory(SCR_FTP_DISCONNECTING);

                StartTimer(BT_FTPC_BROWSE_FILES_FAILED_TIMER, FTPC_BROWSE_FILES_FAILED_DELAY_DUR, mmi_bt_ftpc_browse_files_failed_timer_expire_hdler);
            }
            break;

            case MMI_FTPC_STATE_DISCONNECTING:
                mmi_bt_ftpc_send_disconnect();
                return;

            case MMI_FTPC_STATE_TPDISCONNECTING:
            /*Omit it, when setting_folder, tpdiscon may be sent*/
            return;

             default:
                /*error state*/
                return;
                
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_abort_rsp_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_GOEP_ABORT_RSP msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftpc_abort_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    goep_abort_rsp_struct *rsp = (goep_abort_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_bt_ftpc_find_goep_id(rsp->goep_conn_id);

    if (i == 0xff)
    {
        /* reset */
        return;
    }

    MMI_FTP_LOG1(MMI_BT_FTP_FTPC_ABORT_RSP_HDLR, (act_client_cntx_p + i)->ftpc_state);

    if ((act_client_cntx_p + i)->ftpc_state == MMI_FTPC_STATE_ABORTING)
    {
        FTP_DEBUG(kal_print("FTPC ABORT RSP HDLR IN STATE ABORTING\n");)

        (act_client_cntx_p + i)->total_recv_obj_len = 0;
        (act_client_cntx_p + i)->remain_recv_obj_len = 0;
        (act_client_cntx_p + i)->recved_obj_len = 0;
        (act_client_cntx_p + i)->total_len_type = MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT;

        MMI_FTPC_STATE_TRANS(i, MMI_FTPC_STATE_CONNECTED);
        mmi_bt_ftp_blinking(MMI_BT_CLIENT_ROLE, MMI_FTP_BLINK_STOP);
        mmi_bt_ftpc_clear_abort_scr();
    }
    if ((act_client_cntx_p + i)->ftpc_state == MMI_FTPC_STATE_DISCONNECTING)
    {
        goep_disconnect_req_struct *req;

        /* construct disconnect req ilm */
        req = (goep_disconnect_req_struct*) OslConstructDataPtr(sizeof(goep_disconnect_req_struct));
        FTP_MEMSET(req);    /* memory init */
        req->goep_conn_id = ftpc_cntx_p->goep_conn_id[i];

        /* send disconnect req and connect cnf fail to CM */
        mmi_bt_ftp_send_msg(MSG_ID_GOEP_DISCONNECT_REQ, req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftpc_disp_folder_content
 * DESCRIPTION
 *  This function is to display the folder content
 * PARAMETERS
 *  status     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftpc_disp_folder_content(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status == MMI_FTPC_FOLDER_EMPTY)
    {
        act_client_cntx_p->entity_cnt_cur_folder = 0;
    }

    if (isInCall() && !IsWapCallPresent())
    {
        mmi_bt_ftpc_browser_history_replace();
    }
    else
    {
        mmi_bt_ftpc_entry_file_browser();
    }

    switch (status)
    {
    case MMI_FTPC_FOLDER_EMPTY:
        mmi_bt_ftpc_notify_recv_err(MMI_FTPC_NOTIFY_BROWSE_FILES_FAILED);        
        break;
    case MMI_FTPC_FOLDER_PARTIAL:
        mmi_bt_ftpc_parse_folder_fail();
        break;
    case MMI_FTPC_FOLDER_FULL:
        break;
    default:
        MMI_FTP_ASSERT(0);        
    }
}

#endif /* __MMI_FTC_SUPPORT__ */ 
#define END_FTP_EVENT_HDLR

#define FTP_UTIL_FUNCTION


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_send_msg
 * DESCRIPTION
 *  This function is to send msg to BT task
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_send_msg(U32 msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS SEND MSG TO BT -- FILL ILM BEFORE SENDING\n");)
    ilm_send = allocate_ilm(MOD_MMI);
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = MOD_BT;
    ilm_send->sap_id = BT_APP_SAP;
    ilm_send->msg_id = (kal_uint16) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_send);
    FTP_DEBUG(kal_print("FTPS SEND MSG TO BT -- SNED\n");
)}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_send_msg_self
 * DESCRIPTION
 *  This function is to send msg to self
 * PARAMETERS
 *  msg_id      [IN]        
 *  ind         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_send_msg_self(U32 msg_id, void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTPS SEND MSG TO SELF -- FILL ILM BEFORE SENDING\n");)
    msg.oslSrcId = MOD_MMI;
    msg.oslDestId = MOD_MMI;
    msg.oslMsgId = msg_id;
    msg.oslSapId = INVALID_SAP;
    msg.oslDataPtr = (oslParaType*) ind;
    msg.oslPeerBuffPtr = NULL;

    FTP_DEBUG(kal_print("FTPS SEND MSG TO SELF -- SNED\n");)
    OslMsgSendExtQueue(&msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_connection_terminated
 * DESCRIPTION
 *  This function is to reset cntx when the connection terminated
 * PARAMETERS
 *  index       [IN]        
 *  role        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_ftp_connection_terminated(U32 index, MMI_BT_PROFILE_ROLE role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG1(MMI_BT_FTP_CONNECTION_TERMINATED, role);

    switch (role)
    {
        case MMI_BT_SERVER_ROLE:    /* FTPS */
#ifdef __MMI_FTS_SUPPORT__
            FTP_DEBUG(kal_print("FTPS CONNECTION TERMINATED\n");)
            if ((act_server_cntx_p + index)->fh_ftps_send)
            {
                FS_Close((act_server_cntx_p + index)->fh_ftps_send);
                (act_server_cntx_p + index)->fh_ftps_send = (FS_HANDLE) NULL;
            }
            if ((act_server_cntx_p + index)->send_obj_type == MMI_FTP_OBJ_TYPE_FOLDER)
            {
                FTP_DEBUG(kal_print("FTPS CONNECTION TERMINATED DEL FOLDER CONTENT FILE\n");)
                    /* delete the folder content file */
                    FS_Delete((const WCHAR*)((act_server_cntx_p + index)->folder_content));
            }
            (act_server_cntx_p + index)->send_obj_type = MMI_FTP_OBJ_TYPE_NONE;

            if ((act_server_cntx_p + index)->fh_ftps_recv)
            {
                FS_Close((act_server_cntx_p + index)->fh_ftps_recv);
                (act_server_cntx_p + index)->fh_ftps_recv = (FS_HANDLE) NULL;
            }

            mmi_ucs2cpy((PS8) (act_server_cntx_p + index)->current_folder, (PS8) ftps_cntx_p->root_folder);
            /* clear the released g_conn_id */
            ftps_cntx_p->g_conn_id[index] = 0xFF;
            act_server_cntx_p->discon_not_from_cm = MMI_FALSE;
            mmi_bt_ftp_blinking(MMI_BT_SERVER_ROLE, MMI_FTP_BLINK_STOP);
#endif
            return;

        default:    /* FTPC */
#ifdef __MMI_FTC_SUPPORT__
            {

                /* 
                  * Getting folder:  open temp xhtml file;
                  * Parsing: open parsed file, (temp xhtml file is opened by xml parser;  (parsing state)
                  * Parsed achieved: temp xhtml file is deleted;
                  * 
                  * Getting file: open a temp file;
                  */
                    
                /* FTPC reset */
                FTP_DEBUG(kal_print("FTPC CONNECTION TERMINATED\n"););

                /* Parsing */
                if((act_client_cntx_p + index)->xml_parser_p)
                {
                    xml_close_parser((act_client_cntx_p + index)->xml_parser_p);
                    free_ctrl_buffer((act_client_cntx_p + index)->xml_parser_p);
                    (act_client_cntx_p + index)->xml_parser_p = NULL;

                    /* delete the temp xhtml file */
                    FS_Delete((const WCHAR*)(act_client_cntx_p + index)->folder_obj);

                    /* delete the parsed file*/
                    if((act_client_cntx_p + index)->folder_content.fd)
                    {
                        FS_Close((act_client_cntx_p + index)->folder_content.fd);
                        FS_Delete((const WCHAR*)((act_client_cntx_p + index)->parsed_folder));
                        (act_client_cntx_p + index)->folder_content.fd = 0; 
                    }
                }
                else
                {
                    /* Receiving */
                    if((act_client_cntx_p+index)->fh_ftpc_recv)
                    {
                        FS_Close((act_client_cntx_p+index)->fh_ftpc_recv);
                        (act_client_cntx_p + index)->fh_ftpc_recv = (FS_HANDLE) NULL;
                    }

                    /* temp file for getting obj*/
                    mmi_bt_ftpc_del_tmp_obj(0);

                    /* delete the temp xhtml file */
                    FS_Delete((const WCHAR*)(act_client_cntx_p + index)->folder_obj);

                    /* delete the parsed file*/ 
                    FS_Delete((const WCHAR*)(act_client_cntx_p + index)->parsed_folder);
                }

                /* reset the flag, False: abort_req not sent*/
                mmi_bt_ftpc_reset_abort_req_sent_flag();
                
                ftpc_cntx_p->g_conn_id[index] = 0xFF;
                (act_client_cntx_p + index)->got_root = 0;

                /* Clear shared buffer */
                memset((act_client_cntx_p + index)->ftpc_obj_buff, 0, MMI_OBEX_PROFILE_SHARE_BUF_SIZE);

            }
#endif
                return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_obj_name_swapcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_order_name        [IN]        
 *  n_order_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftp_obj_name_swapcpy(PU8 h_order_name, PU8 n_order_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 bytes_len = mmi_ucs2strlen((PS8) n_order_name) * 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTP OBJ NAME SWAPCPY\n");)
    for (i = 0; i < mmi_ucs2strlen((PS8) n_order_name) * 2; i += 2)    /* includes null temination */
    {
        h_order_name[i] = n_order_name[i + 1];
        h_order_name[i + 1] = n_order_name[i];
    }

    h_order_name[bytes_len] = 0;
    h_order_name[bytes_len + 1] = 0;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_write_buf2file
 * DESCRIPTION
 *  This function is to write buffer to file if the content of the buffer exceeds the
 *  writing threshold.
 * PARAMETERS
 *  composer        [?]     [?]
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  The result of write buffer to file
 *****************************************************************************/
static int mmi_bt_ftp_write_buf2file(mmi_ftp_file_writer_struct *composer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FTP_DEBUG(kal_print("FTP WRITE BUFF TO FILE\n");)
    if (composer->buflen >= FTP_WRITER_BUF_THRESHOLD)
    {
        FTP_DEBUG(kal_print("FTP WRITE BUFF TO FILE ( >= threshold)\n");)
        ret = FS_Write(composer->fd, composer->buf, composer->buflen, &(composer->written));
        MMI_FTP_LOG1(MMI_BT_FTP_WRITE_BUF2FILE_FS_WRITE, ret);

        kal_mem_set(composer->buf, 0, FTP_MAX_FILE_WRITER_BUF_SIZE);
        composer->buflen = 0;
        composer->written = 0;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_blinking
 * DESCRIPTION
 *  This function is to decide if the cm's blinking api should be called.
 *  connection establish    -> call blinking then update the state
 *  disconnect connection   -> update state then call blinking
 * PARAMETERS
 *  profile_role        [IN]        
 *  action              [IN]        
 * RETURNS
 *  The result of blinking(?)
 *****************************************************************************/
void mmi_bt_ftp_blinking(MMI_BT_PROFILE_ROLE profile_role, mmi_ftp_blink_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG2(MMI_BT_FTP_BLINKING, profile_role, action);

    switch (profile_role)
    {
        case MMI_BT_SERVER_ROLE:
#ifdef __MMI_FTS_SUPPORT__
            FTP_DEBUG(kal_print("FTP BLINKING ROLE: SERVER\n");)
            for (i = 0; i < FTP_MAX_CLIENT_SUPPORT; i++)
            {
                /* have other active connections */
                switch ((act_server_cntx_p + i)->ftps_state)
                {
                        /* do nothing */
                    default:
                        break;
                }
            }
#endif /* __MMI_FTS_SUPPORT__ */
            break;

        /* Client*/
        default:
#ifdef __MMI_FTC_SUPPORT__
            FTP_DEBUG(kal_print("FTP BLINKING ROLE: CLIENT\n");)
            for (i = 0; i < FTP_MAX_SERVER_SUPPORT; i++)
            {
                /* have other active connections */
                switch ((act_client_cntx_p + i)->ftpc_state)
                {
                    case MMI_FTPC_STATE_ABORTING:
                    case MMI_FTPC_STATE_GETTING_FOLDER:
                    case MMI_FTPC_STATE_SETTING_BACK_FOLDER:
                    case MMI_FTPC_STATE_SETTING_ROOT_FOLDER:
                    case MMI_FTPC_STATE_SETTING_FOLDER:
                        /* do nothing */
                        return;
                    default:
                        break;
                }
            }
#endif /* __MMI_FTC_SUPPORT__ */
            break;
    }

#ifdef __MMI_FTS_SUPPORT__
    if (profile_role == MMI_BT_SERVER_ROLE)
    {
        /* Guard timer for server side blinking */
        switch (act_server_cntx_p->ftps_blink_state)
        {
        case FTPS_BLINK_STATE_IDLE:
            if (action == MMI_FTP_BLINK_STOP)
                return;
            StartTimer(BT_FTPS_PULL_IND_TIMER, FTPS_ICON_PULL_DELAY_DUR, mmi_bt_ftps_pull_stop_icon_timer_expire_hdler);
            act_server_cntx_p->ftps_blink_state = FTPS_BLINK_STATE_PROTECTED;
            break;
        case FTPS_BLINK_STATE_PROTECTED:
            if (action == MMI_FTP_BLINK_STOP)
            {
                act_server_cntx_p->ftps_blink_state = FTPS_BLINK_STATE_STOP_NEEDED;
            }
            return;
        case FTPS_BLINK_STATE_SAFE:
            if (action == MMI_FTP_BLINK_START)
                return;
            act_server_cntx_p->ftps_blink_state = FTPS_BLINK_STATE_IDLE;
            break;
        case FTPS_BLINK_STATE_STOP_NEEDED:
            if (action == MMI_FTP_BLINK_START)
            {
                act_server_cntx_p->ftps_blink_state = FTPS_BLINK_STATE_PROTECTED;
            }
            return;
        }
    
    }
#endif /* __MMI_FTS_SUPPORT__ */

    /* the last active connection */
    switch (action)
    {
        case MMI_FTP_BLINK_START:
            FTP_DEBUG(kal_print("FTP BLINKING ACTION: START\n");)
                /* first connection -> blinking */
                mmi_bt_status_icon_start_blinking(MMI_BTH_OBEX_FILE_TRANSFER_UUID, profile_role);
            return;
            /* MMI_FTP_BLINK_STOP */
        default:
            FTP_DEBUG(kal_print("FTP BLINKING ACTION: STOP\n");)
                /* last connection -> stop blinking */
                mmi_bt_status_icon_stop_blinking(MMI_BTH_OBEX_FILE_TRANSFER_UUID, profile_role);
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_htons
 * DESCRIPTION
 *  Convert short integer (16 bits) from host byte order to network byte order
 * PARAMETERS
 *  a       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_bt_ftp_htons(U16 a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((a & 0xFF) << 8) | (((a >> 8) & 0xFF)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_htons
 * DESCRIPTION
 *  This function  remove the space in the font, and cut the remain name to requsted size.
 * 
 *  All strings in this funcion must be Unicode encoded.
 *  dest_size: is the buffer size including the  end Zero 
 *  src/dest: host sequence
 * PARAMETERS
 *  a       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_bt_ftp_ucs2_cut_name_with_ext(U8 *dest, U32  dest_size, const U8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *src_no_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_no_space = (U8*)mmi_fmgr_skip_space((S8*)src);


    /* need not to cut*/
    if(mmi_ucs2strlen((S8 *)src_no_space) <= (dest_size/2 -1))
    {
        mmi_ucs2ncpy((PS8)dest, (const PS8)src_no_space, (U32)(dest_size/2 -1));
    }
    else
    {
        char *p_ext_name;
        U32  ext_name_len = 0;

        /* 1. calculate the extend name length
          * 2. cut
          * 3. cat
           */

        p_ext_name = mmi_ucs2rchr((const PS8)src_no_space, (U16)(L'.'));
        if(p_ext_name)
        {
            ext_name_len = mmi_ucs2strlen((const PS8)p_ext_name);
        }
        else
        {
            ext_name_len = 0;
        }

        mmi_ucs2ncpy((PS8)dest, (const PS8)src_no_space, (U32)((dest_size/2 -1) - ext_name_len));
        mmi_ucs2cat((PS8)dest, (const PS8)p_ext_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_htons
 * DESCRIPTION
 *  This function  remove the space in the font, and cut the remain name to requsted size.
 * 
 *  All strings in this funcion must be Unicode encoded.
 *  dest_size: is the buffer size including the  end Zero 
 * PARAMETERS
 *  a       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_bt_ftp_ucs2_cut_name_without_ext(U8 *dest, U32  dest_size, const U8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *src_no_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_no_space = (U8*)mmi_fmgr_skip_space((S8*)src);

    /*copy max dest_size/2 - 1 chars*/
    mmi_ucs2ncpy((PS8)dest, (const PS8)src_no_space, (U32)(dest_size/2 -1));
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftps_check_folder_existed
 * DESCRIPTION
 *   
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bt_ftp_check_folder_existed(U8* absolute_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 deter = '\\';
    U8 parent_folder[FMGR_MAX_PATH_LEN *ENCODING_LENGTH]; 
    U16 start_pos;
    U16 path_len;
    FS_HANDLE fh_parent, fh_checked_folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_CHECK_FOLDER_EXISTED);
    path_len = mmi_ucs2strlen((PS8) absolute_path);
    if (path_len * 2 > (FMGR_MAX_PATH_LEN - 2))
    {
        return MMI_FALSE;
    }
        
    if ((fh_checked_folder = FS_Open((WCHAR *)absolute_path, FS_READ_ONLY | FS_OPEN_DIR )) < FS_NO_ERROR)
    {
        /* start after "X:\" to search*/
        for (start_pos = 0; start_pos < path_len * 2; start_pos += 2)
        {
            if(memcmp((absolute_path + start_pos), &deter, 2) == 0)
            {
                memcpy(parent_folder, absolute_path, start_pos + 2);
                memset(parent_folder + start_pos + 2, 0, 2);
                if((fh_parent = FS_Open((WCHAR *)parent_folder, FS_READ_ONLY | FS_OPEN_DIR)) < FS_NO_ERROR)
                {
                    if(FS_CreateDir((WCHAR *)parent_folder) < FS_NO_ERROR)
                    {
                        return MMI_FALSE;
                    }
                }
                else
                {
                    FS_Close(fh_parent);                    
                }
            }
        }
        return MMI_TRUE;
    }
    else
    {
        FS_Close(fh_checked_folder);
        return MMI_TRUE;
    }
    
}


MMI_BOOL mmi_bt_ftp_check_folder_existed_external(U8* absolute_path)
{
	return mmi_bt_ftp_check_folder_existed( absolute_path );
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ftp_delete_file
 * DESCRIPTION
 *   
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ftp_delete_file(const U8* absolute_path, const U8* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *all_path_name_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTP_LOG(MMI_BT_FTP_DELETE_FILE);
    all_path_name_ptr = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_FTP_ASSERT(all_path_name_ptr != NULL);
    memset(all_path_name_ptr, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);

    /* form obj name */
    mmi_ucs2cpy((PS8) all_path_name_ptr, (PS8) absolute_path);
    mmi_ucs2cat((PS8) all_path_name_ptr, (PS8) file_name);

    FS_Delete((WCHAR *) all_path_name_ptr);

    if (all_path_name_ptr)
    {
        OslMfree(all_path_name_ptr);
    }
}

#define END_FTP_UTIL_FUNCTION

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 

