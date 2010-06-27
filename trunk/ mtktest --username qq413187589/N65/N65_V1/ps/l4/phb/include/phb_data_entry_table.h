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
 * phb_data_entry_table.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is the data-entry-table. Data stucture of the table is defined, as well as functions
 *   for its basic operations.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHB_DATA_ENTRY_TABLE_H
#define _PHB_DATA_ENTRY_TABLE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 

    typedef struct
    {
        alpha_id_type alpha_id;
        kal_uint16 record_index;
        kal_uint8 storage;
        kal_uint8 ext_index;
        kal_uint8 tel_num_sig;
        kal_uint8 tel_num;
    } data_entry_struct;

    typedef struct
    {
        kal_uint16 record_index;
    #ifdef __PHB_USIM_SUPPORT__
        phb_type_enum type;
    #endif 
    } ext_index_struct;

    typedef struct
    {
        kal_uint16 slots;
        kal_uint16 used_count;
        data_entry_struct *table;
    } data_entry_table_type;

    extern kal_uint16 phb_det_get_size(kal_uint16 slots);
    extern void phb_det_new(data_entry_table_type *det, kal_uint16 slots);
    extern void phb_det_reset(data_entry_table_type *det);
    extern kal_uint16 phb_det_append(
                        data_entry_table_type *det,
                        alpha_id_type *alpha_id,
                        phb_storage_enum storage,
                        kal_uint16 record_index,
                        kal_uint8 signature,
                        kal_uint8 tel_num,
                        kal_uint8 ext_index);
    extern kal_bool phb_det_set(
                        data_entry_table_type *det,
                        kal_uint16 position,
                        alpha_id_type *alpha_id,
                        phb_storage_enum storage,
                        kal_uint16 record_index,
                        kal_uint8 signature,
                        kal_uint8 tel_num,
                        kal_uint8 ext_index);
    extern kal_bool phb_det_delete(data_entry_table_type *det, kal_uint16 position);
    extern data_entry_struct *phb_det_get(data_entry_table_type *det, kal_uint16 position);
    extern kal_uint16 phb_det_get_pos_by_record_index(data_entry_table_type *det, kal_uint16 record_index);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_DATA_ENTRY_TABLE_H */ 

