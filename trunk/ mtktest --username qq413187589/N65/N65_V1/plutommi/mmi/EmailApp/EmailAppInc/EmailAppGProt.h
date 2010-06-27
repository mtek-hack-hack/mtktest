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

/*******************************************************************************
 * Filename:
 * ---------
 * EmailAppGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines global enum, constant and prototypes for Email application
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : EmailAppGProt.h

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : 30-01-2004

**************************************************************/
#ifndef _MMI_EMAILAPPGPROT_H
#define _MMI_EMAILAPPGPROT_H

/*---------------------------------------------------------------------------*/
/* Header files */
/*---------------------------------------------------------------------------*/
#include "customer_ps_inc.h"  /*for MMI_EMAIL_MAX_LEN_ADDR_LIST*/

/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Enum */
/*---------------------------------------------------------------------------*/

typedef enum
{
    EMAIL_STOP_NONE = 0,
    EMAIL_STOP_REQ,
    EMAIL_STOP_BACK_HIST,
    EMAIL_STOP_GOTO_IDLE,
    EMAIL_STOP_BACK_FROM_OTHER,
    EMAIL_START_REQ,
    EMAIL_MODULE_ACTIVE_NOW
} email_stop_cause_enum;

/*---------------------------------------------------------------------------*/
/* Struct */
/*---------------------------------------------------------------------------*/

/* structure to support email send interface for other applications */
typedef enum
{
    EMAIL_TO_FILL_FLAG = 0x01,
    EMAIL_CC_FILL_FLAG = 0x02,
#ifdef __MMI_EMAIL_BCC__
    EMAIL_BCC_FILL_FLAG = 0x04,
#endif /*__MMI_EMAIL_BCC__*/
    EMAIL_SUBJ_FILL_FLAG = 0x08,
    EMAIL_ATTCH_FILL_FLAG = 0x10,
    EMAIL_PRIOR_FILL_FLAG = 0x20,
    EMAIL_CONT_FILL_FLAG = 0x40    
} email_app_send_param_fill_enum;

typedef struct
{
    S8 *addr_mail;
    S8 *addr_name;
} mmi_email_app_send_addr_struct;

typedef struct
{
    mmi_email_app_send_addr_struct to_addr[MMI_EMAIL_MAX_LEN_ADDR_LIST];
    mmi_email_app_send_addr_struct cc_addr[MMI_EMAIL_MAX_LEN_ADDR_LIST];
#ifdef __MMI_EMAIL_BCC__
    mmi_email_app_send_addr_struct bcc_addr[MMI_EMAIL_MAX_LEN_ADDR_LIST];
#endif /*__MMI_EMAIL_BCC__*/
    S8 *subj;
    S8 *attch_file_path;
    S32 priority;
    S8 *cont;
    MMI_BOOL is_save_to_draft; /*if want to save to draft without compose screen, set TRUE*/
} mmi_email_app_send_param_struct;

typedef enum
{
    MMI_EMAIL_PRIOR_NORMAL = 0,
    MMI_EMAIL_PRIOR_LOW = 1,
    MMI_EMAIL_PRIOR_HIGH = 2
} mmi_email_app_prior_enum;


/*---------------------------------------------------------------------------*/
/* Variables */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Prototypes */
/*---------------------------------------------------------------------------*/
extern void mmi_email_init(void);
extern void mmi_email_deinit(void);
extern void mmi_email_ps_init_rsp(void *inMsg);
extern void mmi_email_ps_deinit_rsp(void *inMsg);

#ifdef __USB_IN_NORMAL_MODE__
extern U8 mmi_email_check_to_deinit(void);
extern U8 mmi_email_check_to_init(void);
#endif
extern U8 mmi_email_util_get_stop_cause(void);

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
extern U8 mmi_email_util_is_new_mail(void);
extern void mmi_email_entry_auto_chk_result(void);
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
extern void mmi_email_main_goto_idle(void);
extern void mmi_email_highlight_main_menu(void);
extern void mmi_email_phb_get_addr_callback(S8 *name, S8 *email);

extern void mmi_email_fmgr_send(S8 *filePath, BOOL is_short);
extern void mmi_email_fmgr_reset_status_icon(void);
extern void mmi_email_entry_snr_key_lock_result(void);


#ifdef __MMI_WLAN_FEATURES__
extern void mmi_email_wlan_hdlr(U16 status);
#endif


/* this function only support other app,
 * because EMAIL_FROM_APP & EMAIL_FILE_FROM_APP
 * & mmi_email_ps_start_req */
extern void mmi_email_app_send_init_param_to_null(mmi_email_app_send_param_struct *mail_param);
extern void mmi_email_app_send(
    mmi_email_app_send_param_struct *mail_param,
    email_app_send_param_fill_enum mail_param_fill_flag);

extern void mmi_email_app_send_cont(const S8* cont);
extern void mmi_email_app_send_to(const S8* to_addr);
extern void mmi_email_app_send_attch(const S8* file_path);

extern BOOL mmi_email_bearer_status_show_icon(void);

#endif /* _MMI_EMAILAPPGPROT_H */ // #ifndef _MMI_EMAILAPPGPROT_H

