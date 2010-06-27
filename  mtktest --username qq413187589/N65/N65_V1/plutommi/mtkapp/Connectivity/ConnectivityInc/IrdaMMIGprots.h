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
 * IrdaMMIGprots.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IRDA_MMI_GPROTS_H__
#define __IRDA_MMI_GPROTS_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifdef __MMI_IRDA_SUPPORT__

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 

/***************************************************************************** 
* Definations
*****************************************************************************/

/*****************************************/
/* Error cause for Object Send error     */
/****************************************/
typedef enum
{

    MMI_IRDA_ERR_SUCCESS,       /* Success */
    MMI_IRDA_ERR_USER,          /* User termanited */
    MMI_IRDA_ERR_TIMEOUT,       /* Irda Response time out */
    MMI_IRDA_ERR_BAD_FILE,      /* File operating error */
    MMI_IRDA_ERR_EMPTY_FILE,    /* File operating error */
    MMI_IRDA_ERR_REJECT,        /* Reject by Server */
    MMI_IRDA_ERR_BIDIR,         /* Bidirection connection. Not support currently */
    MMI_IRDA_ERR_DISCONNECT,    /* Under layer disconnect */
    MMI_IRDA_ERR_SENDING,       /* Under layer disconnect */

    MMI_IRDA_ERR_LAST   /* This is the last error type */
} MMI_IRDA_SND_ERR_TYPE;

/************************************/
/* Error cause for Received object  */
/* Notify applications              */
/***********************************/
typedef enum
{

    MMI_IRDA_NFY_SUCCESS,           /* Success and file removed */
    MMI_IRDA_NFY_UNRECOGNIZED,      /* Unrecognized type for object */
    MMI_IRDA_NFY_MOVE_FAIL,         /* Application move object fial. */
    MMI_IRDA_NFY_DISK_FULL,         /* Disk full. */
    MMI_IRDA_NFY_ROOT_DIR_FULL,     /* Root directory full. */
    MMI_IRDA_NFY_WRITE_FILE_FAIL,   /* Write file failed */

    MMI_IRDA_NFY_LAST   /* This is the last error type */
} MMI_IRDA_NFY_TYPE;

/* Type for application callback function pointer */
typedef void (*mmi_irda_sendobj_callback_fptr) (void *, U32);
typedef MMI_IRDA_NFY_TYPE(*mmi_irda_obj_notify_fptr) (void *);

#define MMI_IRDA_OPEN_PERIOD  10        /* minutes */
#define MMI_IRDA_OPEN_ALWAYS 0xFFFF

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_irda_init_protocol_event(void);
extern void mmi_irda_init_cntx(void);
extern U8 mmi_irda_get_recv_files_cnt(void);
extern void mmi_irda_set_recv_files_cnt(U8 cnt);
extern void mmi_irda_ir_open(U16 duration);
extern void mmi_irda_ir_close(void);
extern void mmi_irda_obex_snd_abort(void);
extern MMI_IRDA_SND_ERR_TYPE mmi_irda_send_obj(
                                void *obj_p,
                                U32 len,
                                S8 *obj_name_p,
                                mmi_irda_sendobj_callback_fptr fp);
extern MMI_IRDA_SND_ERR_TYPE mmi_irda_send_file_obj(S8 *path, mmi_irda_sendobj_callback_fptr fp);
extern void mmi_irda_entry_idle_notify_scr(void);
extern U8 mmi_irda_retrieve_put_prog_percentage(void);
extern void mmi_irda_scr_open_func(void);
extern BOOL mmi_irda_is_sending(void);
extern BOOL mmi_irda_is_recving(void);
extern void mmi_irda_notify_recv_err(MMI_IRDA_NFY_TYPE cause);
extern void mmi_irda_force_ir_open(void);
extern void mmi_irda_force_ir_close(void);
extern BOOL mmi_irda_is_open(void);
extern BOOL mmi_irda_is_ircomm_active(void);
extern void mmi_irda_ircomm_disconnect_request(void);

/* shantanu - for saving themes through IRDA */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
typedef enum
{
    NO_FILE_RECV,
    FILE_RECV
} irda_file_recv_enum;

typedef enum
{
    DISK_EMPTY,
    DISK_FULL
} irda_is_disk_full_enum;

/* PMT DLT_FIXES - TK 20060225 START */
extern U8 mmi_irda_is_any_theme_file_rcv(void);

/* PMT DLT_FIXES - TK 20060225 END */
extern void mmi_irda_theme_show_idle_notify_scr(void);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* shantanu - for saving themes through IRDA */

/* PMT PANKAJ START */
extern void mmi_irda_fmgr_forward_to_irda_callback(void *buf_p, U32 result);
extern void mmi_irda_entry_fmgr_fwd(void);

/* PMT PANKAJ END */
#endif /* __MMI_IRDA_SUPPORT__ */ 

#endif /* __IRDA_MMI_GPROTS_H__ */ 

