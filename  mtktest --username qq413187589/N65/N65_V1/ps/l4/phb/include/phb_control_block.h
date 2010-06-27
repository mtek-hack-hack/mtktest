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
 * phb_control_block.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is the control_block.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHB_CONTROL_BLOCK_H
#define _PHB_CONTROL_BLOCK_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 
#ifndef _L4C2PHB_ENUMS_H
#error "l4c2phb_enums.h should be included"
#endif 
#ifndef _PHB_DEFS_H
#error "phb_defs.h should be included"
#endif 

    typedef struct _control_block_struct control_block_type;

    typedef void (*return_func_type) (ilm_struct *ilm_ptr, control_block_type *control_block);
    typedef void (*controller_func_type) (ilm_struct *ilm_ptr, control_block_type *control_block);
    typedef void (*err_handler_func_type) (ilm_struct *ilm_ptr, control_block_type *control_block);
    typedef void (*receive_IO_func_type) (ilm_struct *ilm_ptr, control_block_type *control_block);

    struct _control_block_struct
    {
        kal_uint8               ID;               /* ID of this control_block */
        kal_uint16              primary_ID;      /* Primary EF ID */
        kal_uint16              secondary_ID;    /* Secondary EF ID, if primary EF is chained */

        kal_uint16              index;               /* index of PHB */
        kal_uint16              actual_count;        /* already operated in this iteration */
        kal_uint16              total;               /* total to be operated */
        kal_uint16              total_piggyback;     /* total to be piggybacked */
        kal_uint16              length;              /* length to read from SIM and NVRAM */
        kal_uint16              record_index;        /* Location to read, write in primary_ID */
    #ifdef __USIM_SUPPORT__
        kal_uint8               path[6];              /* Absolute EF path */
    #endif /* __PHB_USIM_SUPPORT__ */
    #ifdef __PHB_USIM_SUPPORT__
        kal_uint8               temp_iap[PHB_IAP_MAX_OBJECT];
        phb_email_struct        temp_email_entry;
        phb_anr_struct          temp_anra;
        phb_anr_struct          temp_anrb;
        phb_anr_struct          temp_anrc;
        l4_name_struct          temp_sne;
        kal_uint8               temp_group_id;
        kal_uint8               group_id[MAX_PHB_SIM_ENTRY];
        kal_uint8               hidden_info;
    #endif /* __PHB_USIM_SUPPORT__ */ 
        phb_type_enum           ext1_parent_type; /* Only has meaning when __PHB_USIM_SUPPORT__ is on */
        phb_type_enum           type;

        phb_storage_enum        storage;

        kal_uint8               *data;    /* write buffer */

        kal_uint8               seg_record_index; /* Location to write segmented telephone number, in secondary_ID */
        kal_uint8               seg_len;          /* Length of segmented telephone number to write in this iteration. */
        kal_uint8               seg_total;        /* Accumulated total length of segmented telephone number already written */

        phb_entry_struct        temp_entry;    /* buffer storing data read from SIM for reassembly */

        kal_uint8               match_result;

        kal_uint16              candidate;
        void                    *candidate_name_num_index; /* Type should be name_num_index_type* */

        return_func_type        return_location;
        controller_func_type    controller;
        err_handler_func_type   err_handler;

        receive_IO_func_type    IO_cnf_receive;

        kal_uint8               proc_stage;
        IO_state_enum           IO_stage;

        kal_uint16              cause;   /* The cause value returned to upper layer, if error encountered during IO */
        void                    *local_param_ptr;
        void                    *peer_buf_ptr;
        kal_bool                need_free_peer;

        kal_uint8               src_id;       /* used by layer 4 controller */
        msg_type                cnf_msg_id;    /* used by read handler */

        kal_bool                is_allocated;
    };

    extern void phb_control_block_construct(control_block_type *control_block, kal_uint8 ID);
    extern void phb_control_block_set_param(
                    control_block_type *control_block,
                    kal_uint8 proc_stage,
                    void *local_param_ptr,
                    void *peer_buf_ptr);
    extern void phb_control_block_set(
                    control_block_type *control_block,
                    return_func_type return_location,
                    controller_func_type controller,
                    err_handler_func_type err_handler,
                    kal_uint8 proc_stage);
    extern void phb_control_block_set_IO(
                    control_block_type *control_block,
                    phb_type_enum type,
                    kal_uint16 index,
                    kal_uint16 total);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_CONTROL_BLOCK_H */ 

