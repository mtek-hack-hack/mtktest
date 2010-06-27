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
 * BTMMIBip.h
 *
 * Project:
 * --------
 *   BT BIP MMI
 *
 * Description:
 * ------------
 *   
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

#ifndef __BT_MMI_BIP_H__
#define __BT_MMI_BIP_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

/* file path */

#define BIP_RECV_FILEPATH   FMGR_DEFAULT_FOLDER_RECEIVED

/* L for wide char, @ for hidden working folder */
#define BIP_FOLDER_PATH       (L"Z:\\@bip\\")   /* working folder */
#define BIP_RECV_THM_PATH     (L"Z:\\@bip\\recv_thm\\") /* for recving thm  */
#define BIP_GEN_THM_PATH     (L"Z:\\@bip\\gen_thm\\")   /* for generating thm */
#define BIP_TEMP_PATH         (L"Z:\\@bip\\tmp\\")      /* for tmp file */

#define BIP_IMG_LIST_PATH_FILE         (L"Z:\\@bip\\tmp\\mmi_imglist.tmp")      /* for tmp imglist file */
#define BIP_TMP_IMG_HDLE_NAME_FILE     (L"Z:\\@bip\\tmp\\hdle_name.tmp")        /* for tmp image handle-name file */
#define BIP_TMP_IMG_THM_NAME_FILE     (L"Z:\\@bip\\tmp\\thm_name.tmp")  /* for tmp thm name file */
#define BIP_CUR_IMG_LIST_PATH_FILE         (L"Z:\\@bip\\tmp\\mmi_curimglist.tmp")      /* for tmp imglist file */

/* tmp file name for reciever */
#define BIP_PUSH_R_TMP_FILENAME  (L"bip_r.tmp") /* pushed img and thm */
#define BIP_PULL_I_TMP_FILENAME  (L"bip_i.tmp") /* pulled img and thm */

#define BIP_THM_POSTFIX  (l"_thm.jpg")

/* max filename length */
#define BIP_MAX_FILE_NAME_LEN            (80)

#define BIP_MAKE_RECV_PATH(x)               do{            \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\", MMI_PUBLIC_DRV);\
   mmi_ucs2cat((U8*)x, (U8*)BIP_RECV_FILEPATH);             \
   }while(0)

#ifdef WIN32
#define BIP_DEBUG(x) x
#else 
#define BIP_DEBUG(x)
#endif 

/* image thumbnail pixels: */
#define BT_BIP_THM_WIDTH   160
#define BT_BIP_THM_HEIGHT  120

/* max number of images returned in the image list */
#define BT_BIP_MAX_RETURNED_IMG_HANDLES  0X7FFF //0x20

/* disconnect type for sending disconnect request */
typedef enum
{
    MMI_BIP_OBEX_DISCONNECT,
    MMI_BIP_TP_DISCONNECT
} mmi_bip_disconnect_type_enum;

typedef enum
{
	MMI_BIP_RESPONDER_ROLE,
	MMI_BIP_INITIATOR_ROLE
}mmi_bip_role_type_enum;

/* timer duration */
#define MMI_BIP_PROG_UPD_DUR            (100)
#define MMI_BIP_CONNECT_TIMER_DUR       (20000)
#define MMI_BIP_ABORT_TIMER_DUR         (8000)
#define MMI_BIP_DISCONNECT_TIMER_DUR    (10000)
#define MMI_BIP_GENERAL_TIMER_DUR       (1000)
#define MMI_BIP_ICON_DELAY_DUR          (1000)

/* operation result */
#define MMI_BIP_RESULT_SUCCESS   1
#define MMI_BIP_RESULT_FAILED    0

#define MMI_BIP_INVALID_REQ_ID   0xFF
#define MMI_BIP_INVALID_CONN_ID  0xFF

/* mmi_bip_initiator_state_enum */
typedef enum
{
    MMI_BIPI_STATE_IDLE,
    MMI_BIPI_STATE_CONNECTING,
    MMI_BIPI_STATE_CONNECTED,

    MMI_BIPI_STATE_GETTING_CAPABILITIES,
    MMI_BIPI_STATE_SENDING,

    MMI_BIPI_STATE_GETTING_IMGLIST,
    MMI_BIPI_STATE_GETTING_IMG,
    MMI_BIPI_STATE_GETTING_THM,
    MMI_BIPI_STATE_GETTING_IMGPROP,

    MMI_BIPI_STATE_ABORTING,
    MMI_BIPI_STATE_DISCONNECTING
} mmi_bip_initiator_state_enum;

/* mmi_bip_responder_state_enum */
typedef enum
{
    MMI_BIPR_STATE_IDLE,    /* Initial state */
    MMI_BIPR_STATE_REGISTERING,
    MMI_BIPR_STATE_ACTIVE,
    MMI_BIPR_STATE_AUTHORIZING,
    MMI_BIPR_STATE_ACCEPTED,

    MMI_BIPR_STATE_RECEIVING,

    MMI_BIPR_STATE_SENDING,

    MMI_BIPR_STATE_DISCONNECTING,
    MMI_BIPR_STATE_DEACTIVATING
} mmi_bip_responder_state_enum;

/* push flag */
typedef enum
{
    MMI_BIPI_PUSH_IDLE,
    MMI_BIPI_PUSHING_IMG,
    MMI_BIPI_PUSHING_THM,
    MMI_BIPI_PUSH_IMG_SUCCESS,
    MMI_BIPI_PUSH_IMG_FAILED,
    MMI_BIPI_PUSH_THM_SUCCESS,
    MMI_BIPI_PUSH_THM_FAILED,
    
    MMI_BIPI_PUSH_LAST
}mmi_bipi_push_flag_enum;

typedef enum
{
    MMI_BIPI_OPER_IDLE,
    MMI_BIPI_OPER_PUSH_IMG,
    MMI_BIPI_OPER_PUSH_THM,
    MMI_BIPI_OPER_GET_CAPABILITIES,
    MMI_BIPI_OPER_GET_IMGLIST,
    MMI_BIPI_OPER_GET_IMG,
    MMI_BIPI_OPER_GET_THM,
    MMI_BIPI_OPER_GET_IMGPROP,
    
    MMI_BIPI_OPER_LAST
}mmi_bipi_operation_type;


/* BIP initiator context struct */
typedef struct
{
    mmi_bip_initiator_state_enum state;
    U8 cur_service;
    U8 req_id;
    bt_bip_bd_addr_struct bipr_bt_device;
    U32 cm_conn_id;

    mmi_bipi_operation_type cur_oper;
        
    /* current sending/receving img handle */
    S8 img_handle[BT_BIP_IMG_HANDLE_LEN];
	MMI_BOOL b_timeout;

    /* PUSH info */

    U32 img_file_size;
    S8 img_path_file[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    U32 sent_size;

    mmi_bipi_push_flag_enum push_flag;
    MMI_BOOL b_user_cancel;

    mmi_bt_bip_send_img_callback app_callback;  /* notify the sending result */

    /* PULL info */

    S8 img_list_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];

    S8 img_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    S8 thm_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];

    U32 cur_img_gotten_size;
    U32 cur_img_total_size;

    U16 img_handle_num_in_imglist;

    MMI_BOOL b_user_disconnect;
    MMI_BOOL b_CmConnectCnf_called;

    /* for getting image list */
    U32 start_index;

} bip_initiator_cntx_struct;

typedef struct
{
    S8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    S8 img_name[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
} bip_img_handle_name_struct;

typedef enum
{
    MMI_BIP_IMAGE,
    MMI_BIP_THM
} mmi_bip_media_type_enum;

/* bip_pull_responder_cntx_struct */
typedef struct
{
    mmi_bip_responder_state_enum state;
    U8 req_id;
    bt_bip_bd_addr_struct bipi_bt_device;
    S8 bipi_dev_name[BT_BIP_MAX_DEV_NAME_LEN];
    MMI_BOOL disconnect_from_cm;
    U32 cm_conn_id;

    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /* data for push */
    mmi_bip_media_type_enum recv_media;
    U32 total_recv_img_num;
    U32 cur_recv_img_num;
    S8 recv_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    /* push: current filename */
    S8 recv_img_name[BIP_MAX_FILE_NAME_LEN];

    /* the following is for pull */

    /* shared folder for images */
    S8 shared_folder[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];

    /* info in get_img_list_rsp */
    S8 cur_img_list_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    U16 cur_img_count;
    
    /* total info */
    S8 img_list_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    U16 img_count;

    /* save every image's handle and name list */
    S8 img_handle_name_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];

    /* thumbnail path for generating thm */
    S8 thm_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];

    MMI_BOOL BTIcon_blinking_timer_started;
} bip_responder_cntx_struct;

typedef struct
{
    bip_initiator_cntx_struct bip_initiator_cntx;

    bip_responder_cntx_struct bip_responder_cntx;

    U8 cur_req_id;

} bip_context_struct;

/* global variable */
extern bip_context_struct g_bip_context;

/* func prototype */
void mmi_bt_bip_cntx_init(void);
void mmi_bt_bip_work_folder_init(void);

/* msg handler */

/* BIP initiator msg handler */
void mmi_bt_bipi_connect_cnf_hdlr(void *msg);
void mmi_bt_bipi_send_disconnect_req(mmi_bip_disconnect_type_enum type);

void mmi_bt_bipi_get_capabilities_cnf_hdlr(void *msg);
void mmi_bt_bipi_put_img_cnf_hdlr(void *msg);
void mmi_bt_bipi_put_thm_cnf_hdlr(void *msg);

void mmi_bt_bipi_get_imglist_cnf_hdlr(void *msg);
void mmi_bt_bipi_get_imgprop_cnf_hdlr(void *msg);
void mmi_bt_bipi_get_img_cnf_hdlr(void *msg);
void mmi_bt_bipi_get_thm_cnf_hdlr(void *msg);

void mmi_bt_bipi_abort_cnf_hdlr(void *msg);

void mmi_bt_bipi_disconnect_ind_hdlr(void);

void mmi_bt_bipi_pull_exit_recving(void);

/* BIP responder msg handler */
void mmi_bt_bipr_activate_cnf_hdlr(void *msg);
void mmi_bt_bipr_deactivate_cnf_hdlr(void *msg);

void mmi_bt_bipr_connect_ind_hdlr(void *msg);
void mmi_bt_bipr_disconnect_ind_hdlr(void);

void mmi_bt_bipr_get_capabilities_ind_hdlr(void *msg);
void mmi_bt_bipr_put_img_ind_hdlr(void *msg);
void mmi_bt_bipr_put_thm_ind_hdlr(void *msg);

void mmi_bt_bipr_get_imglist_ind_hdlr(void *msg);
void mmi_bt_bipr_get_imgprop_ind_hdlr(void *msg);
void mmi_bt_bipr_get_img_ind_hdlr(void *msg);
void mmi_bt_bipr_get_thm_ind_hdlr(void *msg);

void mmi_bt_bipr_aborted_ind_hdlr(void *msg);
void mmi_bt_bipr_complete_ind_hdlr(void *msg);

/* general msg handler */
void mmi_bt_bip_continue_ind_hdlr(void *msg);

void mmi_bt_bip_disconnect_ind_hdlr(void *msg);

void mmi_bt_bip_send_msg(U32 msg_id, void *p_local_para);

void mmi_bt_bipi_push_connect_cnf_hdlr(bt_bip_connect_cnf_struct *rsp);
void mmi_bt_bipi_pull_connect_cnf_hdlr(bt_bip_connect_cnf_struct *rsp);
void mmi_bt_bipi_push_continue_ind_hdlr(bt_bip_continue_ind_struct *ind);
void mmi_bt_bipi_pull_continue_ind_hdlr(bt_bip_continue_ind_struct *ind);
void mmi_bt_bipi_push_disconnect_ind_hdlr(void);

void mmi_bt_bipi_connection_terminated(U8 cause);

void mmi_bt_bip_get_path_name(S8 *pathFileName, S8 *path, S8 *name, U16 name_len);

void mmi_bt_bip_send_disconnect_req(U32 cm_conn_id, mmi_bip_disconnect_type_enum type);
void mmi_bt_bipi_send_abort_req(U32 cm_conn_id);
void mmi_bt_bipi_push_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp);
void mmi_bt_bipi_send_get_imglist_req(void);
void mmi_bt_bipi_send_get_capabilities_req(U32 cm_conn_id);

void mmi_bt_bipr_send_put_img_rsp(U8 cnf_code);
void mmi_bt_bipr_send_get_capabilities_rsp(void);
void mmi_bt_bip_send_continue_rsp(U32 cm_conn_id);
void mmi_bt_bipr_connection_terminated(void);

BOOL mmi_bt_bipi_pull_is_recving(void);

void mmi_bt_bip_request_timeout_hdlr(void);

MMI_BOOL mmi_bt_bipr_construct_img_list(U32 *img_count);

void mmi_bt_bipi_push_abort(void);
void mmi_bt_bipi_pull_disconnect_ind_hdlr(void);
void mmi_bt_bipr_disconnect_ind_hdlr(void);

void mmi_bt_bipi_notify_recv_err(U8 cause);

void mmi_bt_bipi_send_push_req(void);
void mmi_bt_bipi_fmgr_forward_to_bip_callback(void *p, U32 result);

void mmi_bt_bipi_push_deinit(void);

void mmi_bt_bipi_pull_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp);

MMI_BOOL mmi_bt_bipr_pull_get_filename_with_imghandle(S8 *img_handle, S8 *file_name);
bt_bip_img_format_enum mmi_bt_bip_get_image_type(U16 *pathfileName);

void mmi_bt_bipr_set_shared_fodler(PS8 path);
BOOL mmi_bt_bipi_pull_is_canceling(void);
BOOL mmi_bt_bipi_push_is_aborting(void);
BOOL mmi_bt_bipi_push_is_sending(void);
BOOL mmi_bt_bipi_pull_is_aborting(void);
BOOL mmi_bt_bipi_pull_is_connecting(void);
BOOL mmi_bt_bipi_pull_is_getting_thm(void);

void mmi_bt_bipi_pull_simple_abort(void);
void mmi_bt_bipi_pull_abort_getting_images(void);

U8 mmi_bipi_push_prog_percentage(void);

void mmi_bt_bipi_send_get_img_req(S8 *img_handle);
void mmi_bt_bipi_send_get_imgprop_req(S8 *img_handle);
void mmi_bt_bipi_send_get_imgthm_req(S8 *img_handle);

void mmi_bt_bipi_connect_responder(mmi_bth_bt_addr bd_addr, U8 bip_service);

void mmi_bt_bipr_get_dev_name(U8 *name_buf);

U8 mmi_bt_bipr_authorize_confirm_del_cb(void *p);

void mmi_bt_bipr_send_connect_rsp(U8 rsp_code);

void mmi_bt_bip_construct_send_thm_path(S8 *img_path_file, S8 *dst_path, U16 path_size);

U8 mmi_bt_bipi_generate_thumbnail(U16 *img_path, U16 *thm_path, U16 thm_path_len);

void mmi_bt_bip_rename_pushed_thm(void);

void mmi_bt_bip_rename_pulled_thm(S8* dst_thm_name);


MMI_BOOL mmi_bt_bipi_pull_get_image(S8 *img_handle);

U8 mmi_bt_bip_rename_recved_file(U16 *path, U16 *dst_name, U16 *src_name);

void mmi_bt_bip_name_swapcpy(PU8 dst_name, PU8 src_name);

void mmi_bt_bip_notify_user_error(U8 rsp_code);

S16 mmi_bt_bip_get_partial_imglist(U16 start_index, U16 max_num);


/* push adpt */
void mmi_bt_push_cm_device_discovery_callback(MMI_BOOL result, U32 lap, U8 uap, U16 nap);

mmi_bt_bip_error_enum mmi_bt_bip_send_image_to_dev(
                        S8 *file_name_with_path,
                        mmi_bt_bip_send_img_callback callback_f,
                        mmi_bt_dev_addr *dst_bt_dev);

/* trace macro */

#define BIP_CURR_REQ_ID  (g_bip_context.cur_req_id++)

#define IS_BIPI_PUSHING  (g_bip_context.bip_initiator_cntx.cur_service == BT_BIP_IMAGE_PUSH)

#define IS_BIPI_PULLING  (g_bip_context.bip_initiator_cntx.cur_service == BT_BIP_IMAGE_PULL)

#define IS_BIPI_PUSH_SUCCESS ((g_bip_context.bip_initiator_cntx.push_flag == MMI_BIPI_PUSH_IMG_SUCCESS) \
                    || (g_bip_context.bip_initiator_cntx.push_flag == MMI_BIPI_PUSH_THM_SUCCESS))

#define MMI_BIPI_STATE_TRANS(x)                                                                                                   \
{                                                                                                                                 \
    kal_prompt_trace(MOD_MMI, "[BIP MMI]initiator trans state from (%d) to (%d)\n",g_bip_context.bip_initiator_cntx.state, x);    \
    g_bip_context.bip_initiator_cntx.state = (x);                                                                                 \
}

#define MMI_BIPR_STATE_TRANS( x)                                                                                                  \
{                                                                                                                                 \
    kal_prompt_trace(MOD_MMI, "[BIP MMI]responder trans state from (%d) to (%d)\n",g_bip_context.bip_responder_cntx.state, x);    \
    g_bip_context.bip_responder_cntx.state = (x);                                                                                 \
}

#define MMI_BIPI_LOG_STATE()                                                                                \
{                                                                                                            \
    kal_prompt_trace(MOD_MMI, "[BIP MMI]initiator state: (%d)\n",g_bip_context.bip_initiator_cntx.state);    \
}

#define MMI_BIPR_LOG_STATE()                                                                                \
{                                                                                                            \
    kal_prompt_trace(MOD_MMI, "[BIP MMI]responder state: (%d)\n",g_bip_context.bip_responder_cntx.state);    \
}

#define MMI_BIP_LOG(x)                                                             \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x);                                           \
   }
#define MMI_BIP_LOG1(x, x1)                                                        \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1);                                       \
   }
#define MMI_BIP_LOG2(x, x1, x2)                                                    \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2);                                   \
   }
#define MMI_BIP_LOG3(x, x1, x2, x3)                                                \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3);                               \
   }
#define MMI_BIP_LOG4(x, x1, x2, x3, x4)                                            \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4);                           \
   }
#define MMI_BIP_LOG6(x, x1, x2, x3, x4, x5, x6)                                    \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6);                   \
   }
#define MMI_BIP_LOG7(x, x1, x2, x3, x4, x5, x6, x7)                                \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6, x7);               \
   }
#define MMI_BIP_LOG_PATH(unicode_path)                   \
{                                                        \
U8 path[FMGR_MAX_PATH_LEN];                              \
mmi_ucs2_to_asc((S8 *)path, (S8 *)unicode_path);          \
kal_prompt_trace(MOD_MMI, "[BIP MMI] path: %s\n", path); \
}

#endif /* __BT_MMI_BIP_H__ */ 

