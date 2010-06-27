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
 * BTMMIFtpGprots.h
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

#ifndef __BT_MMI_FTP_GPROTS_H__
#define __BT_MMI_FTP_GPROTS_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef BT_MMI_CM_H
#error "BTMMICm.h should be included"
#endif 

#ifdef __MMI_BT_MTK_SUPPORT__

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)

#include "FileMgr.h"
#include "Ucs2prot.h"
#include "Kal_release.h"

/************************************/
/* Error cause for Received object  */
/* Notify applications              */
/***********************************/
typedef enum
{
    MMI_FTPC_NOTIFY_DISK_FULL,                  /* Disk full. */
    MMI_FTPC_NOTIFY_ROOT_DIR_FULL,              /* Root Directory full. */
    MMI_FTPC_NOTIFY_WRITE_FILE_FAIL,            /* Write File Fail. */
    MMI_FTPC_NOTIFY_CONNECTION_DISCONNECTED,    /* Failure occurs in bluetooth connection disconnected */
    MMI_FTPC_NOTIFY_REJECT_FROM_SERVER,         /* Failure occurs due to server's rejection */
    MMI_FTPC_NOTIFY_ACTION_NOT_ALLOWED,         /* Failure occurs due to wrong state */
    MMI_FTPC_NOTIFY_BROWSE_FILES_FAILED,         /* Setting folder failed, popup string */
    MMI_FTPC_NOTIFY_GOEP_STATUS_BUSY,         /* connect_rsp failed with goep_status_busy, popup string */    
    MMI_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST,  /* workong folder z:\@folder\ not exist*/
    MMI_FTPC_NOTIFY_FS_DEVICE_BUSY,               /* 6223P:  FS API card non blocking*/
    MMI_FTPC_NOTIFY_LAST                        /* This is the last error type */
} mmi_ftpc_notify_enum;

/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/
#define FTP_MAX_OBJ_NAME_LEN            ((FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH)
#define FTP_MAX_OBJ_CREATED_DATE_LEN    (80)
#define FTP_MAX_OBJ_SIZE_LEN            (16)
#define FTP_MAX_FILE_WRITER_BUF_SIZE    (1024)
#define FTP_WRITER_BUF_THRESHOLD        (512)
#define FTP_MAX_PARSE_FILE_INFO_NUMBER  (200)
#define FTP_MAX_PARSE_THRESHOLD         (30)
#define FTP_MAX_CLIENT_SUPPORT          (1)
#define FTP_MAX_SERVER_SUPPORT          (1)
#define FTPS_MEM_BUFF_SIZE              (14336)
#define FTPC_MEM_BUFF_SIZE              (14336)
#define FTP_NOTY_STR_SIZE               (32)
#define FTPC_PROG_UPD_DUR               (2000)
#define FTPS_FOLDER_CONTENT_PATH_SIZE   (64)    /* should > 2 * "Z:\\@ftp\\folder_content_%d" */
#define FTPC_FOLDER_OBJ_PATH_SIZE       (64)    /* should > 2 * "Z:\\@ftp\\folder_object_%d" */

/* L for wide char, @ for hidden working folder */
#define FTP_FOLDER_PATH                 (L"Z:\\@ftp\\") /* working folder */
#define FTP_SHARED_FOLDER_PATH_FILE     (L"Z:\\@ftp\\shared_file_path") /* for saving shared folder */

/* for saving folder content */
#define FTPS_MAKE_FOLDER_CONTENT(x, i)              \
   kal_wsprintf( (kal_uint16 *)x, "Z:\\@ftp\\folder_content_%d", i);

/* for saving unparsed folder content */
#define FTPC_MAKE_FOLDER_OBJECT(x, i)              \
   kal_wsprintf( (kal_uint16 *)x, "Z:\\@ftp\\folder_object_%d", i);

/* for saving parsed folder content */
#define FTPC_MAKE_FOLDER_PARSED(x, i)              \
   kal_wsprintf( (kal_uint16 *)x, "Z:\\@ftp\\fc.tmp_%d", i);

/*****************************************************************
    MACRO
*****************************************************************/
#ifdef WIN32
#define FTP_DEBUG(x) x
#else 
#define FTP_DEBUG(x)
#endif 
#define MMI_FTP_ASSERT ASSERT

/* FTPC state trace defined here due to the FTPC's operations may be issued from ftpscr.c or ftp.c */
#ifdef __MMI_FTC_SUPPORT__
#define MMI_FTPC_LOG_STATE_ERR(i)                                                                  \
   {                                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_STATE_ERROR, i, (act_client_cntx_p+i)->ftpc_state);\
   }
#define MMI_FTPC_LOG_STATE(i, x)                                                                            \
   {                                                                                                        \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_FTP_STATE_TRANSITION, i, (act_client_cntx_p+i)->ftpc_state, x );\
   }
#define MMI_FTPC_STATE_TRANS(i, x)                                                             \
{                                                                                              \
    FTP_DEBUG(kal_print("FTPC STATE_TRANS FROM STATE: %d",(act_client_cntx_p+i)->ftpc_state););\
    MMI_FTPC_LOG_STATE((i), (x));                                                              \
    (act_client_cntx_p+i)->ftpc_state = (x);                                                   \
    FTP_DEBUG(kal_print("  TO STATE: %d\n",(act_client_cntx_p+i)->ftpc_state););               \
}

#define FTPC_MAKE_RECV_PATH(x)    do{                      \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\", MMI_PUBLIC_DRV);         \
   mmi_ucs2cat((PS8)x, (PS8)FTPC_RECV_OBJ_FILEPATH);                 \
}while(0)

#define MMI_FTP_RECV_TMP_OBJNAME "FtpRecv"
#define MMI_FTP_RECV_TMP_OBJEXT  "tmp"
#define MMI_FTP_MAKE_RECV_TMP_OBJNAME(x, d) do{       \
    U8 temp_name[32];                                                              \
    kal_wsprintf( (kal_uint16 *)x, "%c:\\", MMI_PUBLIC_DRV);       \
    mmi_ucs2cat((PS8)x, (PS8)FTPC_RECV_OBJ_FILEPATH);                 \
    kal_wsprintf( (kal_uint16 *)temp_name, "%s%02d.%s",   \
        MMI_FTP_RECV_TMP_OBJNAME, d, MMI_FTP_RECV_TMP_OBJEXT );    \
    mmi_ucs2cat((PS8)x, (PS8)temp_name);                 \
}while(0)
        


#endif /* __MMI_FTC_SUPPORT__ */ 

/************************************************************************
    Extern Global Function
*************************************************************************/
extern void mmi_bt_ftp_init(void);      /* global ftp init function for CM */
extern void mmi_bt_ftp_deinit(void);    /* global ftp deinit function for CM */
extern void mmi_bt_ftp_event_hdlr(msg_type msg_id, void *msg);  /* protocol event hdlr */
extern void mmi_bt_ftp_usb_plugin_hdle(void); /* call back func for usb plug in */
extern BOOL mmi_bt_ftp_usb_plugin_check(void);

#ifdef __MMI_FTS_SUPPORT__
extern void mmi_bt_ftps_activate(void);                     /* server activate function for CM */
extern void mmi_bt_ftps_deactivate(void);                   /* server deactivate function for CM */
extern void mmi_bt_ftps_disconnect_client(mmi_bth_bt_addr bd_addr, U32 g_conn_id);      /* server disconnect function for CM */
extern void mmi_bt_ftps_sdp_register_cnf_hdlr(void *msg);   /* server register confirm function for CM */
extern void mmi_bt_ftps_sdp_deregister_cnf_hdlr(void *msg); /* server deregister confirm function for CM */
extern BOOL mmi_ftp_server_is_receiving(void);              /* temp patch for camera module */
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
extern void mmi_bt_ftpc_connect_server(mmi_bth_bt_addr bd_addr, U8 req_id);     /* global ftp client connect function for CM */
#endif 

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 
#endif /* __BT_MMI_FTP_GPROTS_H__ */ 

