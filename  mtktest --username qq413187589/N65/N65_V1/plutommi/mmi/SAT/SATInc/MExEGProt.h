/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   MExEGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended for MExE appliction.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef __MExE_GPROT_H__
#define __MExE_GPROT_H__

#ifdef __MMI_MExE_SUPPORT__

typedef struct
{
    pBOOL MExE_valid;

    pBOOL ORPK_support;
    pBOOL ARPK_support;
    pBOOL TPRPK_support;

    pBOOL ORPK_finish;
    pBOOL ARPK_finish;
    pBOOL TPRPK_finish;

    U16 idx_certificate;
    U16 sender_module;

    U8 file_index;
    U8 authority_certificate; /* 1: certificate of an authority */
    U8 certificate_type;
    U8 required_type;

    U8 rpk_record_length;
    U8 rpk_record_total;
    U8 rpk_record_read;

    U8 key_identifier_length;
    U8 *key_identifier;

    U8 certificate_identifier_length;
    U8 *certificate_identifier;

    U8 certificate_file_id[2];
    U8 certificate_file_total_cycle;
    U8 certificate_file_read_cycle;
    U16 certificate_file_offset;
    U16 certificate_file_length;
    U8 *certificate_data;
} mexe_context_struct;


extern void mmi_mexe_init(void);
extern void mmi_mexe_get_sim_certificate_req(void *info);
extern void mmi_mexe_get_sim_certificate_rsp(void);
extern void mmi_mexe_send_sim_certificate_record_ind(void);
extern void mmi_mexe_send_sim_certificate_record_res(void *info);
extern void mmi_mexe_read_service_table_req(void);
extern void mmi_mexe_read_service_table_rsp(void *info);
extern void mmi_mexe_read_rpk_file_info_req(U8 file_id);
extern void mmi_mexe_read_rpk_file_info_rsp(void *info);
extern void mmi_mexe_read_rpk_file_req(U8 file_id);
extern void mmi_mexe_read_rpk_file_rsp(void *info);
extern void mmi_mexe_retrieve_certificate_handler(void);
extern void mmi_mexe_finish_rpk_file(pBOOL);
extern void mmi_mexe_read_rpk_instance_req(void);
extern void mmi_mexe_read_rpk_instance_rsp(void *info);

#endif /* __MMI_MExE_SUPPORT__ */

#endif /* __MExE_GPROT_H__ */

