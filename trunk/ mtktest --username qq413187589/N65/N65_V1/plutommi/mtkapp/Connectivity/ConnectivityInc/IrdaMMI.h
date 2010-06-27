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
 * IrdaMMI.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IRDA_MMI_H__
#define __IRDA_MMI_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifdef __MMI_IRDA_SUPPORT__

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 
#ifndef __IRDA_MMI_GPROTS_H__
#error "IrdaMMIGprots.h should be included"
#endif 

#include "L4Dr.h"
#include "FileManagerGProt.h"

/***************************************************************************** 
* Enum Value
*****************************************************************************/
typedef enum
{

    IRDA_FILE_GET_NAME, /* Extract file name */
    IRDA_FILE_GET_EXT,  /* Extract file extension */

    IRDA_FILE_GET_LAST
} MMI_IRDA_GET_FILE_ENUM;

typedef enum
{

    MMI_IRDA_ACT_UNKNOW,    /* Initial action: unknow */
    MMI_IRDA_ACT_CLOSE,     /* IRDA is not active */
    MMI_IRDA_ACT_IDLE,      /* MMI IRDA is in idle state */
    MMI_IRDA_ACT_SND,       /* MMI IRDA is sending object to obex */
    MMI_IRDA_ACT_RECV,      /* MMI IRDA is receiving object to obex */
    MMI_IRDA_ACT_BIDIR,     /* MMI IRDA is sending and receiving at the same time */

    MMI_IRDA_ACT_LAST   /* This is the last MMI IRDA action */
} MMI_IRDA_MAJOR_ACT_TYPE;

typedef enum
{

    MMI_IRDA_MINACT_SND_UNKNOW, /* Initial minor action: unknow */

    MMI_IRDA_MINACT_SND_DISCONNECTED,           /* Disconnected */
    MMI_IRDA_MINACT_SND_CONNECT_WAITING,        /* Connect request sent, waiting for response */
    MMI_IRDA_MINACT_SND_CONNECTED,              /* Connect request has been confirmed */
    MMI_IRDA_MINACT_SND_PUT_OBJ_WAITING,        /* Put request sent, waiting for response */
    MMI_IRDA_MINACT_SND_PUT_OBJ_CNF,            /* Put request has been confirmed */
    MMI_IRDA_MINACT_SND_PUT_OBJ_FIN_WAITING,    /* Last put request sent, waiting for response */
    MMI_IRDA_MINACT_SND_PUT_OBJ_FIN_CNF,        /* Last put request has been confirmed */

    MMI_IRDA_MINACT_SND_LAST    /* This is the last MMI IRDA minor action */
} MMI_IRDA_MINOR_ACT_SND_TYPE;

typedef enum
{

    MMI_IRDA_MINACT_RECV_UNKNOW,    /* Initial minor action: unknow */

    MMI_IRDA_MINACT_RECV_DISCONNECTED,  /* Disconnected */
    MMI_IRDA_MINACT_RECV_CONNECTED,     /* Connect request has been confirmed */
    MMI_IRDA_MINACT_RECV_OBJ_RECVED,    /* Put request sent, waiting for response */
    MMI_IRDA_MINACT_RECV_OBJ_FIN,       /* Put request has been confirmed */

    MMI_IRDA_MINACT_RECV_LAST   /* This is the last MMI IRDA minor action */
} MMI_IRDA_MINOR_ACT_RECV_TYPE;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{

    /* MMI IRDA staus */
    MMI_IRDA_MAJOR_ACT_TYPE act;
    MMI_IRDA_MINOR_ACT_SND_TYPE snd_act;
    MMI_IRDA_MINOR_ACT_RECV_TYPE recv_act;

    /* Function Pointer for phone book when finish a vCard transmit */
    mmi_irda_sendobj_callback_fptr app_callback_fp;

    /* Send/Recv File Handler */
    FS_HANDLE h_snd;
    FS_HANDLE h_recv;
    FS_HANDLE h_recv_folder;

    /* Pointer to object for application sending command */
    void *obj_cntx_p;

    /* Object name, Unicode encoding */
    S8 obj_name[80];

    /* Temparary file serial number */
    U8 fcnt;

    /* Total length of a object */
    U32 total_obj_len;

    /* Remain length of a object after multiple PUT command */
    U32 remain_put_len;

    /* First packet flag */
    U8 first_pkt_flag;

    /* Total pending received objects counter */
    U8 recv_file_cnt;

    /* MMI Irda general flag collection */
    U32 flag;

    /* Max OBEX sending packet size */
    U16 send_obex_pkt_size;
} MMI_IRDA_CONTEX;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* MMI IRDA App context */
extern MMI_IRDA_CONTEX *const g_mmi_irda_cntx_p;

/***************************************************************************** 
* MMI IRDA context defination and operation
*****************************************************************************/
/* MMI usb context bit-wise flag defination */
#define MMIIRDA_MASK_FOLDER_ERR      0x00000001
#define MMIIRDA_MASK_FS_SANITY       0x00000002
#define MMIIRDA_MASK_IRCOMM_ACTIVE   0x00000004
#define MMIIRDA_MASK_DISK_FULL       0x00000008
#define MMIIRDA_MASK_ROOT_DIR_FULL     0x00000010
#define MMIIRDA_MASK_WRITE_FILE_FAIL      0x00000020
#define MMIIRDA_MASK_RESERVED_5      0x00000040
#define MMIIRDA_MASK_RESERVED_6      0x00000080

/* MMI usb context bit-wise flag operation */
#define MMIIRDA_GET_FLAG(a)       ( ((g_mmi_irda_cntx_p->flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMIIRDA_SET_FLAG(a)       ( (g_mmi_irda_cntx_p->flag) |=  a )
#define MMIIRDA_RESET_FLAG(a)   ( (g_mmi_irda_cntx_p->flag) &=  ~a )

/***************************************************************************** 
* Defination
*****************************************************************************/
#define mmi_irda_assert ASSERT
#define MMI_IRDA_DEBUG_ASSERT ASSERT
#define MMI_IRDA_CTX(x) g_mmi_irda_cntx_p->x

#define MMI_IRDA_LOG_STATE_ERR()                                             \
   {                                                                         \
      MMI_TRACE(MMI_TRACE_ERROR, MMI_IRDA_STATE_ERROR, MMI_IRDA_CTX(act) );\
      MMI_IRDA_DEBUG_ASSERT(0);                                              \
   }

#define MMI_IRDA_LOG_STATE(x)                                                        \
   {                                                                                 \
      MMI_TRACE(MMI_TRACE_STATE, MMI_IRDA_STATE_TRANSITION, MMI_IRDA_CTX(act), x );\
   }

#define MMI_IRDA_STATE_TRANS(x) \
{                               \
    MMI_IRDA_LOG_STATE(x);      \
    MMI_IRDA_CTX(act) = x;      \
}

/*
 * #define MMI_IRDA_INIT_CTX(data)       \
 * {                                     \
 * data.action = MMI_IRDA_ACT_UNKNOW; \
 * data.phb_callback_fp = 0; \   
 * data.phb_obj_p = 0; \   
 * data.total_obj_len = 0; \   
 * data.remain_put_len = 0; \   
 * data.first_pkt_flag = 0; \   
 * data.h = 0; }
 */

/************************************/
/* Predefine file name and path     */
/***********************************/
#define MMI_IRDA_RECV_OBJ_FILEPATH "Received"
#define MMI_IRDA_RECV_OBJ_FILENAME "Receiving"
#define MMI_IRDA_RECV_OBJ_FILEEXT  "tmp"
#define MMI_IRDA_SND_DEFAULT_OBJNAME "MTK.obj"

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */

#define MMI_IRDA_MAKE_RECV_FILENAME(x, d)                                                                                                                                                                                 \
if((mmi_irda_retrieve_obj_type( MMI_IRDA_CTX( obj_name )) == (U32)FMGR_TYPE_VCF) || (mmi_irda_retrieve_obj_type( MMI_IRDA_CTX( obj_name )) == (U32)FMGR_TYPE_VCS) || (!fmgr_is_msdc_present())){ \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\%s%02d.%s",                                                                                                                                                                   \
      MMI_PUBLIC_DRV, MMI_IRDA_RECV_OBJ_FILEPATH, MMI_IRDA_RECV_OBJ_FILENAME, d, MMI_IRDA_RECV_OBJ_FILEEXT );}                                                                                                            \
else{                                                                                                                                                                                                                     \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\%s%02d.%s",                                                                                                                                                                   \
   gIrdaStorageLocation, MMI_IRDA_RECV_OBJ_FILEPATH, MMI_IRDA_RECV_OBJ_FILENAME, d, MMI_IRDA_RECV_OBJ_FILEEXT );}
#else /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#define MMI_IRDA_MAKE_RECV_FILENAME(x, d)               \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\%s%02d.%s", \
      MMI_PUBLIC_DRV, MMI_IRDA_RECV_OBJ_FILEPATH, MMI_IRDA_RECV_OBJ_FILENAME, d, MMI_IRDA_RECV_OBJ_FILEEXT );

#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */

#define MMI_IRDA_MAKE_RECV_PATH(x)                                                                                                                                                                                        \
if((mmi_irda_retrieve_obj_type( MMI_IRDA_CTX( obj_name )) == (U32)FMGR_TYPE_VCF) || (mmi_irda_retrieve_obj_type( MMI_IRDA_CTX( obj_name )) == (U32)FMGR_TYPE_VCS) || (!fmgr_is_msdc_present())){ \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\",                                                                                                                                                                            \
   MMI_PUBLIC_DRV, MMI_IRDA_RECV_OBJ_FILEPATH ); }                                                                                                                                                                        \
else{                                                                                                                                                                                                                     \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\",                                                                                                                                                                            \
   gIrdaStorageLocation, MMI_IRDA_RECV_OBJ_FILEPATH );}
#else /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#define MMI_IRDA_MAKE_RECV_PATH(x)             \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\", \
      MMI_PUBLIC_DRV, MMI_IRDA_RECV_OBJ_FILEPATH );

#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_irda_init_received_folder(void);
extern void mmi_irda_ir_close_ind_handler(void *msg);
extern void mmi_irda_ircomm_connect_handler(void *msg);
extern void mmi_irda_ircomm_discon_handler(void *msg);
extern void mmi_irda_obex_connect_ind_handler(void *msg);
extern void mmi_irda_obex_connect_cnf_handler(void *msg);
extern void mmi_irda_obex_put_object_cnf_handler(void *msg);
extern void mmi_irda_obex_put_object_ind_handler(void *msg, int mod_src, void *peer_buf);
extern void mmi_irda_obex_connection_terminated(MMI_IRDA_SND_ERR_TYPE cause);
extern void mmi_irda_obex_snd_abort(void);
extern void mmi_irda_obex_snd_disconnect(MMI_IRDA_SND_ERR_TYPE cause);
extern void mmi_irda_obex_disconnect_cleanup(void);
extern void mmi_irda_obex_disconnect_ind_handler(void *msg);
extern void mmi_irda_send_msg_to_obex(U16 msg_id, void *p_local_para, void *p_peer_buff);
extern void mmi_irda_send_msg_to_lmp(U16 msg_id, void *p_local_para, void *p_peer_buff);
extern void mmi_irda_send_msg_to_ircomm(U16 msg_id, void *p_local_para, void *p_peer_buff);
extern S8 *mmi_irda_get_file_name_ext(S8 *pathfileName, MMI_IRDA_GET_FILE_ENUM type);
extern void mmi_irda_notify_register_app(U16 *path);
extern MMI_IRDA_MAJOR_ACT_TYPE mmi_irda_get_cur_action(void);
extern void mmi_irda_obex_close_recv_file_handlers(void);

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
extern U32 mmi_irda_retrieve_obj_type(S8 *);
#endif /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#endif /* __MMI_IRDA_SUPPORT__ */ 

#endif /* __IRDA_MMI_H__ */ 

