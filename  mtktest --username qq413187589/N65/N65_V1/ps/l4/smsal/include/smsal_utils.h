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
 *	smsal_utils.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the header file of smsal_sms.c
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _SMSAL_UTILS_H
#define _SMSAL_UTILS_H

extern 
void smsal_decode_dcs(kal_uint8                dcs,
                      smsal_alphabet_enum      *alphabet_type,
                      smsal_msg_class_enum     *msg_class,
                      kal_bool                 *is_compress,
                      smsal_msg_waiting_struct *msg_wait 
                     );
                     
extern                     
kal_uint8 smsal_set_dcs(kal_uint8 dcs, smsal_alphabet_enum alphabet_type);
                        
extern kal_bool smsal_is_len_in8bit(kal_uint8 dcs);

extern kal_uint16 smsal_msg_len_in_character(kal_uint8 dcs, 
                                             kal_uint16 len,
                                             kal_uint8 last_byte);

extern kal_uint16 smsal_msg_len_in_octet(kal_uint8 dcs, kal_uint16 len);

extern kal_uint8 smsal_dcs_to_mmi(kal_uint8 dcs);

/* This function does not perform any conversion, just pack the
 * the octets into septets assuming that data is in GSM7-bit */
extern void smsal_gsm7_pack( kal_uint8  *old_data_ptr,
                             kal_uint8  *new_data_ptr,
                             kal_uint16      data_len,
                             kal_uint16        offset );

extern void smsal_gsm7_unpack( kal_uint8  *old_data_ptr,
                               kal_uint8  *new_data_ptr,
                               kal_uint16      data_len,
                               kal_uint16        offset );

kal_uint16 smsal_compute_udh_offset(kal_uint8 udhl);

extern void smsal_bitmap_clr_index(kal_uint16 index, kal_uint8 *bitmap_ptr);
extern void smsal_bitmap_set_index(kal_uint16 index, kal_uint8 *bitmap_ptr);

extern kal_uint16 smsal_bitmap_get_next_index(kal_uint16 start_idx, kal_uint8 *bitmap_ptr);
extern kal_bool   smsal_bitmap_is_index_set(kal_uint16 query_idx, kal_uint8 *bitmap_ptr);

#endif /* _SMSAL_UTILS_H */


