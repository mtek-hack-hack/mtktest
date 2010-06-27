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
 *   aud_nvram_struct.h
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *  FILENAME : nvram_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */

#ifndef _AUD_NVRAM_STRUCT_H
#define _AUD_NVRAM_STRUCT_H

/* Enum and Struct */
typedef struct {

    kal_uint32   vmid_idx_bmp;
    kal_uint32   reserved;
    kal_uint32	 free_size;

} nvram_vm_info_struct;


/* Structure for Primitive */

/* for MSG_ID_NVRAM_VM_GET_INFO_REQ */
typedef struct {

    kal_uint8 	 ref_count;
    kal_uint16 	 msg_len;

} nvram_vm_getinfo_req_struct;


/* for MSG_ID_NVRAM_VM_GET_INFO_CNF */
typedef struct {

    kal_uint8 	 ref_count;
    kal_uint16 	 msg_len;

	nvram_vm_info_struct vminfo;
    nvram_vm_errno_enum	 status;

} nvram_vm_getinfo_cnf_struct;


/* for MSG_ID_NVRAM_VM_WRITE_REQ */
typedef struct{

    kal_uint8 	 ref_count;
    kal_uint16	 msg_len;

    kal_uint8    vmid;
    kal_uint16	 *pbuf;
    kal_uint16	 buf_len;
    nvram_vm_write_enum	 write_flag;

} nvram_vm_write_req_struct;



/* for MSG_ID_NVRAM_VM_WRITE_CNF */
typedef struct{
    kal_uint8 	 ref_count;
    kal_uint16	 msg_len;

    kal_uint8    vmid;
    kal_uint16   written_len;
    nvram_vm_errno_enum	 status;

} nvram_vm_write_cnf_struct;



/* for MSG_ID_NVRAM_VM_READ_REQ */
typedef struct{

    kal_uint8	 ref_count;
    kal_uint16	 msg_len;

    kal_uint8    vmid;
    kal_uint16	 *pbuf;
    kal_uint16 	 buf_len;
    kal_uint32 	 offset;

} nvram_vm_read_req_struct;


/* for MSG_ID_NVRAM_VM_READ_CNF */
typedef struct{

    kal_uint8 	 ref_count;
    kal_uint16 	 msg_len;

    kal_uint8    vmid;
    kal_uint16	 read_len;
    nvram_vm_errno_enum	 status;

} nvram_vm_read_cnf_struct;


/* for MSG_ID_NVRAM_VM_DELETE_REQ */
typedef struct{

    kal_uint8	 ref_count;
    kal_uint16	 msg_len;

    kal_uint8    vmid;
    kal_uint16	 reserved;

} nvram_vm_delete_req_struct;


/* for MSG_ID_NVRAM_VM_DELETE_CNF */
typedef struct{

    kal_uint8 	 ref_count;
    kal_uint16 	 msg_len;

    kal_uint8    vmid;
    nvram_vm_errno_enum	 status;

} nvram_vm_delete_cnf_struct;

#endif /*#ifdef _AUD_NVRAM_STRUCT_H */


