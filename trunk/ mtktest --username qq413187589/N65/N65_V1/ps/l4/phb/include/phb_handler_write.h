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
 * phb_handler_write.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is declarations of write handler.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _PHB_HANDLER_WRITE_H_
#define _PHB_HANDLER_WRITE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _STACK_LTLCOM_H
#error "stack_ltlcom.h should be included"
#endif 

    typedef enum
    {
        WRITE_NONE,
        WRITE_CONTINUE = 0x03   /* To avoid conflict with READ_CONTINUE */
    } write_stage_enum;

    typedef enum
    {
        WRITE_USIM_NONE,
        WRITE_USIM_ANR = 0x03,  /* To avoid conflict with READ_CONTINUE */
        WRITE_USIM_EMAIL,
        WRITE_USIM_SNE,
        WRITE_USIM_IAP,
        WRITE_USIM_GRP,
        WRITE_USIM_CONTINUE
    } write_usim_stage_enum;

    typedef enum
    {
        WRITE_LN_NONE,
        WRITE_LN_READ = 0x10,   /* To avoid conflict with READ_CONTINUE */
        WRITE_LN_READ_CONTINUE,
        WRITE_LN_WRITE_CONTINUE,
        WRITE_LN_WRITE
    } write_ln_stage_enum;

    typedef enum
    {
        SYNC_NONE,
        SYNC_READ_FILE = 0x10,  /* To avoid conflict with READ_CONTINUE */
        SYNC_ERASE_SIM,         /* For VoIP */
        SYNC_READ,
        SYNC_READ_CONTINUE,
        SYNC_WRITE_CONTINUE
    } sync_stage_enum;

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    typedef enum
    {
        WRITE_LN_TYPE_SEQ_NONE,
        WRITE_LN_TYPE_SEQ_CONTINUE = 0x10   /* To avoid conflict with READ_CONTINUE */
    } write_ln_type_seq_stage_enum;

    extern void phb_shift_ln_type_seq(kal_uint16 del_seq_index, kal_uint8 type);
    extern void phb_write_ln_type_seq_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 

    extern void phb_write_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
    extern void phb_write_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
    extern void phb_sync_handler(ilm_struct *ilm_ptr, control_block_type *control_block);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_HANDLER_WRITE_H_ */ 

