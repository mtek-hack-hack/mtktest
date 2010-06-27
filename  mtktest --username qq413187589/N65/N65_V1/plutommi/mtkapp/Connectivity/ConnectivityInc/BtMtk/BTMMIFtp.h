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
 * BTMMIFtp.h
 *
 * Project:
 * --------
 *   MMI
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

#ifndef __BT_MMI_FTP_H__
#define __BT_MMI_FTP_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 

#ifndef __BT_MMI_FTP_GPROTS_H__
#error "BTMMIFtpGprots.h should be included"
#endif 

#ifndef __BLUETOOTH_STRUCT_H_
#error "Bluetooth_struct.h should be included"
#endif 

#ifndef __BT_MMI_FTP_SCR_H__
#error "BTMMIFtpScr.h should be included"
#endif 

#include "L4Dr.h"
#include "FileManagerGProt.h"
#include "wgui_categories_popup.h"      /* timer */

/******************************************************************************
    Enum Value
******************************************************************************/
#ifdef __MMI_FTS_SUPPORT__
/* FTP Server State for maintaining status and context */
typedef enum
{
    MMI_FTPS_STATE_IDLE,            /* FTPS Initial State */
    MMI_FTPS_STATE_REGISTERING,     /* Register goep and sdp */
    MMI_FTPS_STATE_ACTIVE,          /* goep and sdp is ready to service */
    MMI_FTPS_STATE_AUTHORIZING,     /* RFCOMM connection confirm state */
    MMI_FTPS_STATE_ACCEPTED,        /* Connection established state */
    MMI_FTPS_STATE_RECEIVING,       /* FTPS is receiving obj from FTPC */
    MMI_FTPS_STATE_SENDING,         /* FTPS is sending folder content or obj to FTPC */
    MMI_FTPS_STATE_DISCONNECTING,   /* FTPS is disconnecting the connection */
    MMI_FTPS_STATE_DEACTIVATING     /* FTPS service is going to stop */
} mmi_ftps_state_enum;

typedef enum
{
    FTPS_BLINK_STATE_IDLE = 0,
    FTPS_BLINK_STATE_PROTECTED,
    FTPS_BLINK_STATE_SAFE,
    FTPS_BLINK_STATE_STOP_NEEDED
} mmi_ftps_blink_state_enum;

#endif /* __MMI_FTS_SUPPORT__ */


#ifdef __MMI_FTC_SUPPORT__
/* FTP Client State for maintaining status and context */
typedef enum
{
    MMI_FTPC_STATE_IDLE,                /* 0 FTPC Initial State */
    MMI_FTPC_STATE_CONNECTING,          /* 1 FTPC is connecting to FTPS */
    MMI_FTPC_STATE_CONNECTED,           /* 2 FTPC has established the connection to FTPS */
    MMI_FTPC_STATE_GETTING_FOLDER,      /* 3 FTPC is getting the folder content for browsing */
    MMI_FTPC_STATE_PARSING_FOLDER,          /* 4  FTPC is parsing the folder content */
    MMI_FTPC_STATE_GETTING_OBJ,         /* 5 FTPC is getting obj from FTPS */
    MMI_FTPC_STATE_ABORTING,            /* 6 FTPC is aborting the getting obj behavior */
    MMI_FTPC_STATE_SETTING_FOLDER,      /* 7 FTPC is setting the current folder of connected FTPS */
    MMI_FTPC_STATE_SETTING_BACK_FOLDER, /* 8 FTPC is setting the current folder of connected FTPS */
    MMI_FTPC_STATE_SETTING_ROOT_FOLDER, /* 9 FTPC is setting the current folder of connected FTPS */
    MMI_FTPC_STATE_DISCONNECTING,        /* 10 FTPC is disconnecting the connection */
    MMI_FTPC_STATE_TPDISCONNECTING            /* 11 */
    
} mmi_ftpc_state_enum;

/* FTPC  get obj total length num */
typedef enum
{
    MMI_FTPC_TOTAL_LEN_NO_FIRST_PKT,
    MMI_FTPC_TOTAL_LEN_NO_ZERO,
    MMI_FTPC_TOTAL_LEN_ZERO
} mmi_ftpc_total_len_type;

typedef enum
{
    MMI_FTPC_FOLDER_FULL,
    MMI_FTPC_FOLDER_PARTIAL,
    MMI_FTPC_FOLDER_EMPTY
} mmi_ftpc_disp_folder_enum;

#endif /* __MMI_FTC_SUPPORT__ */ 

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/* FTP Blink action enum */
typedef enum
{
    MMI_FTP_BLINK_START,
    MMI_FTP_BLINK_STOP
} mmi_ftp_blink_enum;
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 


/******************************************************************************
    Structure
******************************************************************************/

#ifdef __MMI_FTS_SUPPORT__
/* object info struct is used to save the object detail information */
typedef struct
{
    U8 file_name[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    U32 file_size;
    U16 year;
    U8 month;
    U8 day;
    U8 hour;
    U8 min;
    U8 sec;
} mmi_ftp_obj_info_struct;
#endif /* __MMI_FTS_SUPPORT__ */ 

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/* temp buffer for file writing */
typedef struct
{
    kal_int32 fd;                               /* file handle */
    kal_char buf[FTP_MAX_FILE_WRITER_BUF_SIZE]; /* buffer */
    kal_uint32 buflen;                          /* buffer len used */
    kal_uint32 written;                         /* written len */
} mmi_ftp_file_writer_struct;
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

/******************************************************************************
    MMI FTP CONTEXT
******************************************************************************/

#ifdef __MMI_FTS_SUPPORT__
typedef struct
{
    mmi_ftp_file_writer_struct xml_composer;                /* for generating folder listing object composer */
    U8 dev_name[GOEP_MAX_DEV_NAME];                         /* saving bt device name (utf-8) */
    U8 current_folder[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];  /* saving current folder */
    U8 ftps_obj_name[FTP_MAX_OBJ_NAME_LEN];                 /* saving the obj name */
    U8 folder_content[FTPS_FOLDER_CONTENT_PATH_SIZE];       /* should > 2 * "Z:\\@ftp\\folder_content_%d" */
    U32 send_obex_pkt_size;                                 /* peer Max packet size */
    U32 total_send_obj_len;                                 /* total length of a object */
    U32 remain_send_obj_len;                                /* remains length of a object */
    mmi_ftp_obj_type_enum send_obj_type;                    /* save the obj_type in sending */
    mmi_ftps_state_enum ftps_state;                         /* ftps state */
    goep_bd_addr_struct ftps_bt_device;                     /* saving bt device address */
    FS_HANDLE fh_ftps_send;                                 /* fh for sending file */
    FS_HANDLE fh_ftps_recv;                                 /* fh for receiving file */
    FS_HANDLE fh_ftps_generating;                           /* fh for generating composing obj */
    kal_uint8 ftps_obj_buff[FTPS_MEM_BUFF_SIZE];            /* ftps obj memory buffer */
    MMI_BOOL discon_not_from_cm;                        /* true, not from cm, call disconnect_ind*/
    U8 ftps_blink_state;
} mmi_ftps_conn_cntx_struct;

typedef struct
{
    U8 goep_conn_id[FTP_MAX_CLIENT_SUPPORT];            /* goep connection id */
    U32 g_conn_id[FTP_MAX_CLIENT_SUPPORT];              /* global connection id */
    mmi_ftp_access_right_enum access_right;             /* FTPS access right setting */
    mmi_ftps_conn_cntx_struct conn_cntx[FTP_MAX_CLIENT_SUPPORT];        /* connection cntx */
    U8 root_folder[FMGR_MAX_PATH_LEN *ENCODING_LENGTH]; /* saving root folder */
    U8 cur_goep_conn_id;                                /* save active goep_conn_id for authorizing */
    U32 ftps_flag;                                       /* bit-wise flag for FS error summary */
} mmi_ftps_cntx_struct;
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
typedef struct
{
    mmi_ftp_file_writer_struct folder_content;      /* temp buffer for parsed folder content */
    XML_PARSER_STRUCT *xml_parser_p;                /* xml parser for parsing folder content */
    mmi_ftp_obj_entity_struct obj_entity;           /* temp buffer for receiving object */
    mmi_ftpc_state_enum ftpc_state;                 /* ftpc state */
    FS_HANDLE fh_ftpc_recv;                         /* fh for receiving file */
    U32 total_recv_obj_len;                         /* total length of a object */
    U8* ftpc_obj_buff;           /* ftpc obj memory buffer */
    U32 remain_recv_obj_len;                        /* remains length of a object */
    U8 ftpc_obj_name[FTP_MAX_OBJ_NAME_LEN];         /* saving the obj name */
    U16 entity_cnt_cur_folder;                      /* entity count in current folder */
    U16 browse_depth;                               /* depth from root folder */
    U8 got_root;                                    /* flag for root folder content */
    goep_bd_addr_struct ftpc_bt_device;             /* saving bt device address */
    U8 folder_obj[FTPC_FOLDER_OBJ_PATH_SIZE];       /* should > 2 * "Z:\\@ftp\\folder_object_%d" */
    U8 parsed_folder[FTPC_FOLDER_OBJ_PATH_SIZE];    /* should > 2 * "Z:\\@ftp\\fc.tmp_%d" */
    U8 parsed_folder_item_cnt;                      /* saving the temp count of parsed folder item */
    U8 total_len_type;                              /* flag for display receiving: no zero total len, zero total len, first pkt not arrived */
    U32 recved_obj_len;                             /* only save received length of a file, not folder-content file */
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    U16 file_cnt_cur_folder;                        /* files count in current folder */
#endif 
    U8 tmpname_fcnt;                                /* the fcnt of  FtpRecv00.tmp (e.g. 00)*/
    U8 flag_abort_req_sent;                                /* have send abort_req*/

} mmi_ftpc_conn_cntx_struct;

typedef struct
{
    U8 goep_conn_id[FTP_MAX_SERVER_SUPPORT];    /* goep connection id */
    U32 g_conn_id[FTP_MAX_SERVER_SUPPORT];      /* global connection id */
    U8 req_id[FTP_MAX_SERVER_SUPPORT];          /* req from CM id */
    mmi_ftpc_conn_cntx_struct conn_cntx[FTP_MAX_SERVER_SUPPORT];        /* connection cntx */
    U32 ftpc_flag;                               /* bit-wise flag for FS error summary */
    U8 curr_idx;                                /* save the current active connection */
} mmi_ftpc_cntx_struct;
#endif /* __MMI_FTC_SUPPORT__ */ 


/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/
/* OBEX FTP UUID */
extern const kal_uint8 OBEX_FTP_UUID[];

#ifdef __MMI_FTS_SUPPORT__
extern mmi_ftps_cntx_struct *const ftps_cntx_p;
extern mmi_ftps_conn_cntx_struct *act_server_cntx_p;
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
extern mmi_ftpc_cntx_struct *const ftpc_cntx_p;
extern mmi_ftpc_conn_cntx_struct *act_client_cntx_p;
#endif /* __MMI_FTC_SUPPORT__ */ 

/* MMI usb context bit-wise flag defination */
#define MMIFTP_MASK_FOLDER_ERR          (0x01)
#define MMIFTP_MASK_FS_SANITY           (0x02)
#define MMIFTP_MASK_WRITE_FILE_FAIL     (0x04)
#define MMIFTP_MASK_DISK_FULL           (0x08)
#define MMIFTP_MASK_ROOT_DIR_FULL       (0x10)
#define MMIFTP_MASK_DEVICE_EXPORTED     (0x20)
#define MMIFTP_MASK_RESERVED_5          (0x40)
#define MMIFTP_MASK_RESERVED_6          (0x80)
/* When long fs operation on card, fs api will become Non-blockong */
#define MMIFTP_MASK_FS_DEVICE_BUSY              (0x100)
#define MMIFTP_MASK_FS_LOCK_MUTEX_FAIL      (0x200)

/* cover the shared folder path read failed */
#define FTPS_RECV_OBJ_FILEPATH          FMGR_DEFAULT_FOLDER_RECEIVED
#define FTPC_RECV_OBJ_FILEPATH          FMGR_DEFAULT_FOLDER_RECEIVED

#ifdef __MMI_FTS_SUPPORT__
#define FTPS_ICON_PULL_DELAY_DUR    (1000)
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
#define FTPC_BROWSE_FILES_FAILED_DELAY_DUR    (UI_POPUP_NOTIFYDURATION_TIME)
#endif /* __MMI_FTS_SUPPORT__ */ 

/******************************************************************************
    MMI FTP FUNCTIONS
******************************************************************************/
#if defined (__MMI_FTS_SUPPORT__) || defined (__MMI_FTC_SUPPORT__)
void mmi_bt_ftp_disconnect_ind_hdlr(void *msg);
void mmi_bt_ftp_blinking(MMI_BT_PROFILE_ROLE profile_role, mmi_ftp_blink_enum action);
#endif 

#ifdef __MMI_FTS_SUPPORT__
void mmi_bt_ftps_set_shared_fodler(PS8 path);
void mmi_bt_ftps_get_dev_name(PU8 name_buf);
U8 mmi_bt_ftps_authorize_confirm_del_cb(void *p);
void mmi_bt_ftps_authorize_reject(void);
void mmi_bt_ftps_authorize_accept(void);
void mmi_bt_ftps_register_server_rsp_hdlr(void *msg);
void mmi_bt_ftps_deregister_server_rsp_hdlr(void *msg);
void mmi_bt_ftps_connect_ind_hdlr(void *msg);
void mmi_bt_ftps_push_ind_hdlr(void *msg);
void mmi_bt_ftps_pull_ind_hdlr(void *msg);
void mmi_bt_ftps_set_folder_ind_hdlr(void *msg);
void mmi_bt_ftps_abort_ind_hdlr(void *msg);
void mmi_bt_ftps_authorize_ind_hdlr(void *msg);
U32 mmi_bt_ftps_get_state(U32 i);
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
void mmi_bt_ftpc_abort_rsp_hdlr(void *msg);
void mmi_bt_ftpc_set_folder_rsp_hdlr(void *msg);
void mmi_bt_ftpc_pull_rsp_hdlr(void *msg);
void mmi_bt_ftpc_connect_rsp_hdlr(void *msg);
BOOL mmi_bt_ftpc_is_recving(void);
void mmi_bt_ftpc_connect_cancel(void);
BOOL mmi_bt_ftpc_is_canceling(void);
void mmi_bt_ftpc_send_disconnect(void);
BOOL mmi_bt_ftpc_get_folder_content(void);
BOOL mmi_bt_ftpc_change_folder(PU16 name);
BOOL mmi_bt_ftpc_get_file_obj(PU16 name);
BOOL mmi_bt_ftpc_root_folder(void);
BOOL mmi_bt_ftpc_is_aborting(void);
BOOL mmi_bt_ftpc_back_folder(void);
#if 0
/* under construction !*/
#endif
void mmi_bt_ftpc_retrieve_get_prog_percentage(U16 *recv_per_str_buf);
void mmi_bt_ftpc_del_tmp_obj(U32 i);
void mmi_bt_ftpc_receiving_aborted_hdlr(U32 i);
void mmi_bt_ftpc_send_abort(U8 goep_conn_id);
void mmi_bt_ftpc_set_abort_req_sent_flag(void);
void mmi_bt_ftpc_reset_abort_req_sent_flag(void);
void mmi_bt_ftpc_set_state(U32 i, mmi_ftpc_state_enum ftpc_state);
U32 mmi_bt_ftpc_get_state(U32 i);
void mmi_bt_ftpc_send_tpdisconnect(U32 i);
MMI_BOOL mmi_bt_ftpc_is_get_root(U32 i);
#endif /* __MMI_FTC_SUPPORT__ */ 

#endif /* __BT_MMI_FTP_H__ */ 

