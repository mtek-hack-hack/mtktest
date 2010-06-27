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
 * nvram_io.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is startup_handler() of NVRAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_IO_H
#define NVRAM_IO_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 
#ifndef NVRAM_ENUMS_H
#error "nvram_enums.h should be included"
#endif 

    extern nvram_errno_enum nvram_read_data_item(
                                ltable_entry_struct *ldi,
                                kal_uint16 rec_index,
                                /* multi-rec read support */ kal_uint16 rec_amount,
                                /* multi-rec read support */ kal_uint8 *buffer,
                                kal_uint16 buffer_size);
    extern nvram_errno_enum nvram_write_data_item(
                                ltable_entry_struct *ldi,
                                kal_uint16 index,
                                kal_uint8 *data,
                                kal_bool is_init);
    extern void nvram_get_default_value_to_write
        (ltable_entry_struct *ldi, kal_uint16 rec_number, kal_uint8 *buffer, kal_uint16 buffer_size);
/* __GEMINI__ */
    extern kal_bool nvram_reset_data_items(nvram_reset_category_enum reset_category, ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount);
/* __GEMINI__ */

    extern kal_bool nvram_reset_data_item_difference(ltable_entry_struct *ldi);

#ifdef __SHADOW_NVRAM__
    extern void nvram_flush_shadow(void);
    extern nvram_errno_enum nvram_add_shadow_request
        (ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint8 *buffer);
    
    extern kal_uint8 nvram_get_next_flush_lid(void);
    extern void nvram_get_dirty_list(kal_uint8 *list);
    extern kal_uint8 nvram_get_total_dirty(void);
#endif /* __SHADOW_NVRAM__ */ 

#ifdef __SECURITY_OTP__
#define NVRAM_VALIDATE_OTP(buffer, buffer_size) \
{\
    kal_uint16 i;\
    \
    /* buffer must be kal_uint8[] */\
    ASSERT(sizeof(buffer) == sizeof(buffer)/sizeof(kal_uint8));\
    kal_mem_set(&(buffer - 2), 0, 2);\
    \
    for(i = 0; i < (buffer_size - 2) / 2; i++)\
    {\
        buffer[buffer_size - 2] += buffer[i];\
        buffer[buffer_size - 1] += buffer[i + 1];\
    }\
}
#define nvram_get_otp_offset(offset, x) \
{\
    kal_uint16 i;\
    offset = 0;\
    \
    for(i = 0; i < otp_item_total; i++)\
    {\
        nvram_otp_ltable[i].LID = x;\
        offset = nvram_otp_ltable[i].offset;\
        break;\
    }\
}

    extern void nvram_otp_construct(void);
    extern nvram_errno_enum nvram_read_otp_data_item(ltable_entry_struct* ldi, kal_uint8* buffer, kal_uint16 buffer_size);
    extern nvram_errno_enum nvram_write_otp_data_item(ltable_entry_struct* ldi, kal_uint8* data);
#endif /* __SECURITY_OTP__ */

#ifdef __cplusplus
}
#endif 

#endif /* NVRAM_IO_H */ 

