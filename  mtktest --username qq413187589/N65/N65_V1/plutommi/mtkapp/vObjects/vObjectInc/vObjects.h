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
 * vObjects.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for common screen and function for vCard and vCalendar
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VOBJECTS_H
#define _MMI_VOBJECTS_H

#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "FileMgr.h"
#include "vObjectsResDef.h"
/* if some header should be include before this one */
/* 
 * Define
 */
#define VOBJ_DRV              MMI_PUBLIC_DRV
#define VOBJ_MAX_TEMP_FILE       6      /* Maximum 254 */
#define VOBJ_FILE_PATH           "Received"
#define VOBJ_VCARD_FILE_EXT         ".vcf"
#define VOBJ_VCLNDR_FILE_EXT     ".vcs"
#define VOBJ_TMP_FILE_NAME       "tmp"
#define VOBJ_VCARD_DEFAULT_FILE_NAME   "~vcard.vcf"
#define VOBJ_VCLNDR_DEFAULT_FILE_NAME  "~vcalendar.vcs"
#define VOBJ_VCLNDR_DEFAULT_FILE_NAME_FOR_AT  "~at_vcs.vcs"
#define VOBJ_MAX_PATH_LENGTH     FMGR_MAX_PATH_LEN*ENCODING_LENGTH
#define VOBJ_MAX_FILE_EXT_LEN    FMGR_MAX_EXT_LEN*ENCODING_LENGTH
#define VOBJ_MAX_FILENAME_LENGTH (FMGR_MAX_INPUT_FILE_LEN)*ENCODING_LENGTH

#define VOBJ_SRC_PORT            0x0000 /* For sending SMS */
#define VOBJ_VCARD_PORT       0x23f4
#define VOBJ_VCLNDR_PORT         0x23f5
#ifdef __MMI_VBOOKMARK__
#define VOBJ_VBKM_PORT         0x2000 /* temp number need to be change later*/
#endif
#define VOBJ_READ_BUFF_LEN       512
#define VOBJ_WRITE_BUFF_LEN      1024

#define  VOBJ_CR_CHAR         0x0D
#define  VOBJ_LF_CHAR         0x0A
#define  VOBJ_NULL            '\0'
#define  VOBJ_VALUE_SEP_STR   ":"
#define  VOBJ_QP_CRLF_STR     "=0D=0A="
#define  VOBJ_CRLF_STR     "\r\n"
#define  VOBJ_LF_STR       "\n"

#ifdef __MMI_DUAL_SIM__
#define VOBJ_SMS_PORT_REG_MASTER    0
#define VOBJ_SMS_PORT_REG_SLAVE      1

#endif

/* 
 * Typedef 
 */

typedef enum
{
    MMI_VOBJ_UNRECOGNIZED,
    MMI_VOBJ_VCARD,
    MMI_VOBJ_VCLNDR,
#ifdef __MMI_VBOOKMARK__
    MMI_VOBJ_VBKM,
#endif
    MMI_VOBJ_TOTAL
} vobj_object_type_enum;

#define VOBJ_TYPE_NUM   (MMI_VOBJ_TOTAL - 1)   /* define vobject type */

typedef struct
{   /* Global context */
    U16 curr_sms_port;
    U8 buffer_begin;
    U8 buffer_end;
#ifdef __MMI_VBOOKMARK__
    U8 obj_list[VOBJ_MAX_TEMP_FILE];
#else
    U8 obj_list;
#endif
    U16 sms_port_reg[VOBJ_TYPE_NUM];
    U8 sms_port_reg_count;
} vobj_context_struct;

typedef enum
{
    VOBJ_ERR_NO_ERROR = 0,
    VOBJ_ERR_EMPTY_NAME,
    VOBJ_ERR_DUPLICATE_NAME,
    VOBJ_ERR_MEMORY_FULL,
    VOBJ_ERR_INVALID_FILENAME,
    VOBJ_ERR_SELECT_PATH_TOO_LONG,
    VOBJ_ERR_UNSUPPORT_FORMAT,
    VOBJ_ERR_UNKNOWN
} vobj_file_err_enum;

typedef enum
{
    VOBJ_PARA_LANGUAGE,
    VOBJ_PARA_CHARSET,
    VOBJ_PARA_ENCODING,
    VOBJ_PARA_TOTAL
} vobj_desc_para_type_enum;

typedef enum
{
    VOBJ_EN_7BIT = 0,   /* 7-bit encoding */
    VOBJ_EN_8BIT,       /* 8-bit encoding */
    VOBJ_EN_QP,         /* Quoted-Printable */
    VOBJ_EN_BASE64,     /* Base64 */
    VOBJ_EN_OTHERS,     /* X-xxxx */
    VOBJ_EN_TOTAL
} vobj_ecoding_type_enum;

typedef enum
{
    VOBJ_CH_UTF8,
    VOBJ_CH_BIG5,
    VOBJ_CH_UTF7,
    VOBJ_CH_TOTAL
} vobj_charset_type_enum;

/* 
 * Extern Global Variable
 */
extern vobj_context_struct g_vobj_cntx;

/* 
 * Extern Global Function
 */
extern void mmi_vobj_init(void);
extern void mmi_vobj_deinit(void);

extern void mmi_vobj_register_sms_req(U16);
extern void mmi_vobj_register_vcard_sms_rsp(void *info);
extern void mmi_vobj_register_vclndr_sms_rsp(void *info);
#ifdef __MMI_VBOOKMARK__
extern void mmi_vobj_register_vbkm_sms_rsp(void *info);
#endif

extern void mmi_vobj_sms_receive_ind(void *info);
extern void mmi_vobj_sms_get_incoming_msg_req(U16 port);
extern void mmi_vobj_sms_get_incoming_msg_rsp(void *info);
extern BOOL mmi_vobj_is_pending_object(void);
extern void mmi_vobj_receive_ind_prompt(U8 type);
extern void mmi_vboj_entry_recv_popup(U8 type);
extern void mmi_vobj_entry_recv_object(void);
extern void mmi_vobj_entry_recv_object_abort(void);
extern void mmi_vobj_abort_object(void);
extern void mmi_vobj_clear_one_file_buffer(void);
extern U8 mmi_vobj_get_file_buffer_size(void);
extern void mmi_vobj_increase_file_buffer_counter(U8);
extern BOOL mmi_vobj_decrease_file_buffer_counter(void);
extern S32 mmi_vobj_fs_check_folder(void);
extern vobj_object_type_enum mmi_vobj_check_curr_file_type(void);
extern void mmi_vobj_entry_irda_processing_screen(void);
extern void mmi_vobj_get_full_path_name(U8 index, S8 *result, U8 type);
extern void mmi_vobj_irda_receive_ind(void *path_src, U32 type);
extern void mmi_vobj_opp_receive_ind(void *path_src, U32 type);
extern void mmi_vobj_get_full_tmp_path_name(U8 index, S8 *result, U8 type);

extern S8 mmi_vobj_uti_strnicmp(S8 *, S8 *, S32);

/* extern S32 mmi_vobj_uti_get_line(S8* strOutput,  FS_HANDLE fh); */
extern U8 mmi_vobj_uti_cmp_filed(S8 *srcString, const S8 *refString);
extern void mmi_vobj_util_eliminate_qp_CRLF(S8 *string);
extern U8 mmi_vobj_util_append_qp_CRLF(S8 *string);
extern S8 *mmi_vobj_uti_get_value(S8 *strString);
extern U8 mmi_vobj_get_file_buffer_slot(void);

/* sms port register*/
extern void mmi_vobj_increase_sms_register(U16 port);
extern void mmi_vobj_set_sms_register(void);
extern void mmi_vobj_register_sms_rsp(void *info);

/* play file arrival tone*/
extern void mmi_file_arrival_tone(void);

#endif /* _MMI_VOBJECTS_H */ /* END #define _MMI_VOBJECTS_H */

