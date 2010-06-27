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
 *   fmt_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : fmt_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */

#ifndef _FMT_STRUCT_H
#define _FMT_STRUCT_H

/* Enum and Struct */

/* Structure for Primitive */

/* for MSG_ID_MMI_FMT_COPY_REQ */
typedef struct {
	 kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8   action;
    kal_uint8   *src_file;
    kal_uint8   dest_file[(260+1)<<1];
} mmi_fmt_copy_req_strcut;

typedef struct {
	 kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 	 result;
    void    *callback; /* function handler of delete response msg */
} mmi_fmt_copy_rsp_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8	drive;
    kal_uint32	level;
} mmi_fmt_format_req_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8	drive;
} mmi_fmt_check_drive_req_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32	type;
    void	*filter;   /* address of filter mask */
    kal_uint8	*path;
    void     *callback; /* function handler of delete response msg */
} mmi_fmt_delete_req_strcut;

typedef mmi_fmt_copy_rsp_strcut mmi_fmt_format_rsp_strcut;
typedef mmi_fmt_copy_rsp_strcut mmi_fmt_check_drive_rsp_strcut;
typedef mmi_fmt_copy_rsp_strcut mmi_fmt_unmount_rsp_strcut;
typedef mmi_fmt_copy_rsp_strcut mmi_fmt_delete_rsp_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8	index;
    kal_uint32	mode;
} mmi_fmt_unmount_req_strcut;

typedef struct {
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_bool present;
	kal_uint32 type;
} mmi_fmt_get_msdc_status_rsp_strcut;

typedef struct {
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_uint32 type;
	kal_int32 cause;
} fmt_mmi_msdc_ind_struct;

typedef fmt_mmi_msdc_ind_struct fmt_mmi_card_plug_in_ind_struct;
typedef fmt_mmi_msdc_ind_struct fmt_mmi_card_plug_out_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_uint32 new_path_len;
    kal_uint32 type;
    kal_wchar file_path[261];
    kal_wchar *new_path;
} fmt_process_drm_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} fmt_fota_init_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} fmt_fota_init_rsp_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint32 length;
    void*      pkg_buffer;
} fmt_fota_write_data_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} fmt_fota_write_data_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} fmt_fota_finalize_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} fmt_fota_finalize_rsp_struct;

#endif /*#ifdef _FMT_STRUCT_H */

