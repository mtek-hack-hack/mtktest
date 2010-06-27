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
 * OPPMMI.h
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
#ifdef __MMI_OPP_SUPPORT__

#ifndef __OPP_MMI_H__
#define __OPP_MMI_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 

#include "L4Dr.h"
#include "FileManagerGProt.h"

#ifndef __OPP_MMI_GPROTS_H__
#error "OppMMIGprots.h should be included"
#endif 
#ifndef __BLUETOOTH_STRUCT_H_
#error "bluetooth_struct.h should be included"
#endif 

#define OPP_MAX_OBJ_NAME_LENGTH GOEP_MAX_OBJ_NAME
#define OPP_MAX_OBJ_MIME_LENGTH GOEP_MAX_MIME_TYPE
#define OPPC_MAX_OBEX_PACKET_LENGTH 14336
#define OPPS_MAX_OBEX_PACKET_LENGTH 14336
/***************************************************************************** 
* Enum Value
*****************************************************************************/
typedef enum
{

    OPP_FILE_GET_NAME,  /* Extract file name */
    OPP_FILE_GET_EXT,   /* Extract file extension */

    OPP_FILE_GET_LAST
} MMI_OPP_GET_FILE_ENUM;

typedef enum
{

    MMI_OPS_IDLE,   /* Initial state */
    MMI_OPS_OBEX_REGISTERING,/*Registering OBEX instance */
    MMI_OPS_SDP_REGISTERING,/* Registering OPP SDP */
    MMI_OPS_ACTIVE,         /* OPS service is active */
    MMI_OPS_ACCEPTING,      /* Received put indication from BCHS */
    MMI_OPS_ACCEPTED,       /* Sent successful response to BCHS */
    MMI_OPS_RECEIVING,      /* Receiving put indication */
    MMI_OPS_ABORTING,       /* Aborting receiving put indication */
    MMI_OPS_DISCONNECTING,  /* Disconnecting current session */
    MMI_OPS_DEACTIVATING    /* Send deactivate request to deactivate OPS service */
} MMI_OPS_STATE;

typedef enum
{

    MMI_OPC_IDLE,   /* Initial state */

    MMI_OPC_CONNECTING,     /* Send connect request to OPC service */
    MMI_OPC_CONNECTED,      /* Received successful response from server */
    MMI_OPC_SENDING,        /* Send put request to BCHS */
    MMI_OPC_ABORTING,       /* Abort current sending request */
    MMI_OPC_DISCONNECTING,   /* Received failed response from peer */
    MMI_OPC_TPDISCONNECTING  /* Send tp_disconnct to goep */
} MMI_OPC_STATE;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    U8 req_id;
    
    /* OPS */
    mmi_bth_bt_addr bt_device;
    MMI_OPS_STATE ops_state;
    FS_HANDLE h_recv;
    /* Temparary file serial number */
    U8 fcnt;
    U8 recv_file_cnt;
    U8 cur_recv_file_cnt;
    U8 opps_goep_conn_id;
    U8 opps_goep_req_id;
    U32 opps_cm_conn_id;
    U32 opps_push_buf[OPPS_MAX_OBEX_PACKET_LENGTH/4];

    /* OPC */
    MMI_OPC_STATE opc_state;
    FS_HANDLE h_snd;
    U8 oppc_goep_conn_id;
    U8 oppc_goep_req_id;
    U32 oppc_cm_conn_id;
    U8 *oppc_push_buf;

    /* Function Pointer for phone book when finish a vCard transmit */
    mmi_opp_sendobj_callback_fptr app_callback_fp;
    /* Total length of a object */
    U32 total_obj_len;
    /* Remain length of a object after multiple PUT command */
    U32 remain_put_len;

    /* Unused */

    /* Object name, Unicode encoding */
    S8 obj_name[OPP_MAX_OBJ_NAME_LENGTH];

    /* Sending Object name, Unicode encoding */
    S8 sending_obj_name[OPP_MAX_OBJ_NAME_LENGTH];
    S8 sending_obj_mime[OPP_MAX_OBJ_MIME_LENGTH];

    /* MMI OPP general flag collection */
    U32 flag;

    U32 send_obex_pkt_size;
    S8 fwd_file_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    MMI_BOOL disconnflag;
    S8 file_stored_folder_name[OPP_MAX_OBJ_NAME_LENGTH];
    U8 dev_name[GOEP_MAX_DEV_NAME];
} MMI_OPP_CONTEX;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* MMI OPP App context */
extern MMI_OPP_CONTEX *const g_mmi_opp_cntx_p;

/***************************************************************************** 
* MMI OPP context defination and operation
*****************************************************************************/
/* MMI usb context bit-wise flag defination */
#define MMIOPP_MASK_FOLDER_ERR      0x00000001
#define MMIOPP_MASK_FS_SANITY       0x00000002
#define MMIOPP_MASK_WRITE_FILE_FAIL      0x00000004
#define MMIOPP_MASK_DISK_FULL      0x00000008
#define MMIOPP_MASK_ROOT_DIR_FULL      0x00000010
#define MMIOPP_MASK_RESERVED_4      0x00000020
#define MMIOPP_MASK_RESERVED_5      0x00000040
#define MMIOPP_MASK_RESERVED_6      0x00000080
#define MMIOPP_MASK_ABORT_PRESS     0x00000100
#define MMIOPP_MASK_EMDKEY_PRESS    0x00000200
#define MMIOPP_MASK_ICON_BLOCK      0x00000400
#define MMIOPP_MASK_DEVICE_BUSY     0x00001000
#define MMIOPP_MASK_MULTI_RECEIV    0x00002000
#define MMIOPP_MASK_SHORT_NAME      0x00004000

/* MMI usb context bit-wise flag operation */
#define MMIOPP_GET_FLAG(a)       ( ((g_mmi_opp_cntx_p->flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMIOPP_SET_FLAG(a)       ( (g_mmi_opp_cntx_p->flag) |=  a )
#define MMIOPP_RESET_FLAG(a)   ( (g_mmi_opp_cntx_p->flag) &=  ~a )

/***************************************************************************** 
* Defination
*****************************************************************************/
#define MMI_OPP_ASSERT ASSERT
#define MMI_OPP_DEBUG_ASSERT ASSERT
#define MMI_OPP_CTX(x) g_mmi_opp_cntx_p->x

#define MMI_
#define MMI_OPP_LOG(x)                                                             \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x);                                           \
   }
#define MMI_OPP_LOG1(x, x1)                                                        \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1);                                       \
   }
#define MMI_OPP_LOG2(x, x1, x2)                                                    \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2);                                   \
   }
#define MMI_OPP_LOG3(x, x1, x2, x3)                                                \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3);                               \
   }
#define MMI_OPP_LOG_STATE()                                                        \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_OPP_CURR_STATE, MMI_OPP_CTX(ops_state), MMI_OPP_CTX(opc_state) );\
   }
#define MMI_OPS_LOG_STATE_ERR()                                                    \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_OPP_STATE_ERROR, MMI_OPP_CTX(ops_state) );\
   }
#define MMI_OPC_LOG_STATE_ERR()                                                    \
   {                                                                               \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_OPP_STATE_ERROR, MMI_OPP_CTX(opc_state) );\
   }
#define MMI_OPS_LOG_STATE(x)                                                               \
   {                                                                                       \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_OPP_STATE_TRANSITION, MMI_OPP_CTX(ops_state), x );\
   }
#define MMI_OPC_LOG_STATE(x)                                                               \
   {                                                                                       \
      MMI_TRACE(MMI_TRACE_G7_MISC, MMI_OPP_STATE_TRANSITION, MMI_OPP_CTX(opc_state), x );\
   }
#define MMI_OPS_STATE_TRANS(x)  \
{                               \
    MMI_OPS_LOG_STATE(x);       \
    MMI_OPP_CTX(ops_state) = x; \
}
#define MMI_OPC_STATE_TRANS(x)  \
{                               \
    MMI_OPC_LOG_STATE(x);       \
    MMI_OPP_CTX(opc_state) = x; \
}

/************************************/
/* Predefine file name and path     */
/***********************************/
#define MMI_OPP_RECV_OBJ_FILEPATH  FMGR_DEFAULT_FOLDER_RECEIVED
#define MMI_OPP_RECV_OBJ_FILENAME "OppRecv"
#define MMI_OPP_RECV_OBJ_FILEEXT  "tmp"
#define MMI_OPP_SND_DEFAULT_OBJNAME "MTK.obj"

#define MMI_OPP_MAKE_RECV_PATH(x)     do{         \
    if(mmi_bt_ftp_check_folder_existed_external(ftps_cntx_p->root_folder) == MMI_FALSE)  \
    { \
	   kal_wsprintf( (kal_uint16 *)x, "%c:\\", MMI_PUBLIC_DRV); \
   	   mmi_ucs2cat((PS8) x, (PS8) MMI_OPP_RECV_OBJ_FILEPATH);      \
   } \
   else \
   {   \
        mmi_ucs2cpy((PS8) x, (PS8) ftps_cntx_p->root_folder);  \
   }  \
}while(0)

#define MMI_OPP_MAKE_RECV_FILENAME(x, d)     do{           \
       U8 temp_name[32];        \
	MMI_OPP_MAKE_RECV_PATH(x);   \
	kal_wsprintf((kal_uint16 *)temp_name,"%s%02d.%s", MMI_OPP_RECV_OBJ_FILENAME, d, MMI_OPP_RECV_OBJ_FILEEXT);              \
	mmi_ucs2cat((PS8) x,(PS8)temp_name);                \
}while(0)


#define MMI_OPP_MAKE_RECV_STORE_NAME(x, y)   do{     \
	MMI_OPP_MAKE_RECV_PATH(x);   \
       mmi_ucs2cat((PS8) x, (PS8) y);    \
}while(0)

#if 0
#define MMI_OPP_MAKE_RECV_FILENAME(x, d)     do{           \
   U8 temp_name[32];        \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\",  MMI_PUBLIC_DRV);     \
   mmi_ucs2cat((PS8) x, (PS8) MMI_OPP_RECV_OBJ_FILEPATH);  \
   kal_wsprintf((kal_uint16 *)temp_name,"%s%02d.%s", MMI_OPP_RECV_OBJ_FILENAME, d, MMI_OPP_RECV_OBJ_FILEEXT);              \
   mmi_ucs2cat((PS8) x,(PS8)temp_name);                \
}while(0)


#define MMI_OPP_MAKE_RECV_STORE_NAME(x, y)   do{     \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\", MMI_PUBLIC_DRV);         \
   mmi_ucs2cat((PS8) x, (PS8) MMI_OPP_RECV_OBJ_FILEPATH);  \
   mmi_ucs2cat((PS8) x, (PS8) y);    \
}while(0)

#endif

#endif /* __OPP_MMI_H__ */ 

#endif /* __MMI_OPP_SUPPORT__ */ 

