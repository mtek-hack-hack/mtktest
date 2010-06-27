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
 * phb_utils.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file contains utility functions for PHB module.
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
#ifndef _PHB_UTILS_H
#define _PHB_UTILS_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 

#include "phb_defs.h"

#define PHB_UTILS_INVALID_VALUE ~0

/** 
 * Number of bytes should be retained for SIM encoding:
 * 1. 0x80: 1 byte coding, 2 bytes 0xFF.
 * 2. 0x81: 1 byte coding, 1 byte length, 1 byte code page offset.
 * 3. 0x82: 1 byte coding, 1 byte length, 2 bytes cod page.
 *
 * This constant could be used for allocating buffer when invoking phb_encode_to_sim() 
 * to enconde characters into SIM.
 */
#define SIM_ENCODE_MARGIN 4

    typedef enum
    {
        shift_down,
        shift_up
    } shift_op_enum;

    /* The enumeration here uses values defined in 03.38 directly. */
    typedef enum
    {
        CHARSET_ASCII = 0x00,
        CHARSET_UCS2 = 0x08
    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
            ,
        CHARSET_UCS2_81 = 0x09, /* Add for extra handle for UCS2 0x81 */
        CHARSET_UCS2_82 = 0x10  /* Add for extra handle for UCS2 0x82 */
    #endif /* __PHB_0x81_SUPPORT__ */ 
    } istring_charset_enum;

    typedef struct
    {
        kal_uint8 length;
        kal_uint8 charset;
        kal_uint8 *data;
    } istring_type;

    typedef enum
    {
        CODING_AUTO,
        CODING_DEFAULT_7BITS,
        CODING_UCS2_80 = 0x80,
        CODING_UCS2_81 = 0x81,
        CODING_UCS2_82 = 0x82
    } sim_alpha_id_coding_enum;

/**
 * Shall returns an integer greater than, equal to, or less than 0, according to `first' is 
 * greater than, equal to, or less than `second'.
 */
    typedef int (*bin_search_cmp_func_type) (void *external_data, int external_pos, void *key);

    /* Generic array shift functions */
    extern void table_shift(
                    kal_uint16 *used_count,
                    kal_uint16 *slots,
                    void *array,
                    kal_uint16 element_size,
                    shift_op_enum op,
                    kal_uint16 from);
    extern void table_range_shift(
                    kal_uint16 *used_count,
                    kal_uint16 *slots,
                    void *array,
                    kal_uint16 element_size,
                    shift_op_enum op,
                    kal_uint16 from,
                    kal_uint16 to);

    /* istring functions */
#define phb_more_significant_char(x) (x >> 8 & 0xFF)
#define phb_less_significant_char(x) (x  & 0xFF)
    extern kal_uint8 istring_encode_to_sim(
                        sim_alpha_id_coding_enum coding,
                        istring_type *istr,
                        kal_uint8 buffer_len,
                        kal_uint8 *buffer);
    extern kal_uint8 istring_decode_from_sim(kal_uint8 raw_data_len, kal_uint8 *raw_data, istring_type *decoded_str);
    extern kal_uint8 istring_decode_0x81_to_0x80(
                        kal_uint8 raw_data_len,
                        kal_uint8 *raw_data,
                        istring_type *decoded_str);
    extern kal_uint8 istring_decode_0x82_to_0x80(
                        kal_uint8 raw_data_len,
                        kal_uint8 *raw_data,
                        istring_type *decoded_str);
    extern kal_uint8 istring_len(istring_type *istr);
    extern kal_uint16 istring_char_at(istring_type *istr, kal_uint8 offset);

    extern kal_bool is_chars_equal(kal_uint16 char1, kal_uint16 char2);
    extern kal_int32 compare_chars(kal_uint16 char1, kal_uint16 char2);

    /* BCD functions */
#define phb_more_significant_nibble(x) (x >> 4 & 0x0F)
#define phb_less_significant_nibble(x) (x  & 0x0F)

    extern kal_uint16 bcd2string(kal_uint8 length, kal_uint8 *tel_number, char *bcd_array);
    extern kal_uint8 bcd2char(kal_uint8 bcd);
    extern kal_uint16 get_next_bcd_digit(
                        kal_uint8 *bcd_array,
                        kal_uint16 offset,
                        kal_bool *is_first,
                        kal_uint8 *digit);
    extern kal_int8 compare_n_string_bcd(char const *str, kal_uint8 *bcd_array, kal_uint16 len);
    extern kal_int8 compare_n_bcd(kal_uint8 *first_bcd_array, kal_uint8 *second_bcd_array, kal_uint16 n);
    extern kal_int16 bcd_len(kal_uint8 *bcd_array, kal_uint16 n);
    extern kal_int16 bcd_exact_len(kal_uint8 *bcd_array, kal_uint16 n);

    /* Check whether each byte of ptr are all 0x0F */
    extern kal_bool is_empty(kal_uint8 *ptr, kal_uint16 len);

    extern kal_uint32 phb_abs(kal_int32 val);

    extern int binary_search(void *collection[], int low, int high, void *key, bin_search_cmp_func_type compare_func);

    extern void phb_shift_ln(kal_uint8 end_index, void *data);

    extern char *find_pinying_str_for_ucs2(kal_uint16 ucs2_code);

    /* MTK 2003-12-30 Wilson, For PinYin Sort and Search */
    extern kal_bool find_pinyin_str_for_ucs2_with_tone(kal_uint8 *inputString, kal_uint8 *outputString);

    extern kal_bool find_pinyin_str_for_ucs2_without_tone(kal_uint8 *inputString, kal_uint8 *outputString);
    /* End MTK */

    extern kal_bool phb_is_prefix(alpha_id_type *target, alpha_id_type *candidate);

    /* 03.38 encodes charset information into bit 3 and 2 */
#define get_0338_charset_bits(x) (x & 0x0C)

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_UTILS_H */ 

