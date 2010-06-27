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
 * Conversions.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum value, and structures for converting 
 *    realted utilities.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_CONVERSIONS_H
#define _MMI_CONVERSIONS_H
#include "kal_release.h"

#ifndef FALSE
  #define FALSE           0
#endif
#define TRUE            1
#define UNKOWN_UCS2_CHAR   0xFFEB

typedef enum
{
    BIG_5_ENCODING_TYPE,
    GB2312_ENCODING_TYPE,
    NO_OF_TEXT_ENCODING
} TextEncodingEnum;

typedef struct
{
    short start;
    short end;
} key_index_t;

/*-- function prototypes --*/
extern kal_uint16 mmi_chset_wchar_to_ucs2(kal_uint16 encode_char, TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_ucs2_to_wchar(kal_uint16 ucs2_char, TextEncodingEnum encoding);

extern kal_uint16 mmi_chset_text_to_ucs2_str(
                    kal_uint8 *dest,
                    kal_int16 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_text_to_ucs2_str_ex(
                    kal_uint8 *dest,
                    kal_int16 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding,
                    kal_uint32 *src_end_pos);

extern kal_uint16 mmi_chset_ucs2_to_text_str(
                    kal_uint8 *dest,
                    kal_int16 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_ucs2_to_text_str_ex(
                    kal_uint8 *dest,
                    kal_int16 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding,
                    kal_uint32 *src_end_pos);

extern kal_uint8 mmi_chset_is_text_in_str(kal_uint8 *src);

/*-- exposed global data --*/
extern const kal_uint8 *g_ucs2_to_encode_key_MSB[NO_OF_TEXT_ENCODING];
extern const kal_uint8 *g_encode_to_ucs2_key_MSB[NO_OF_TEXT_ENCODING];
extern const kal_uint16 *g_ucs2_to_encode_table[NO_OF_TEXT_ENCODING];
extern const kal_uint16 *g_encode_to_ucs2_table[NO_OF_TEXT_ENCODING];
extern const kal_uint16 g_unknown_encode_char[NO_OF_TEXT_ENCODING];
extern const kal_uint16 *g_text_encoding_name[NO_OF_TEXT_ENCODING];

#define CHSET_MAX_COUNT             25
#define CHSET_BIT_WORD_16           16
#define CHSET_BIT_WORD_8            8
#define CHSET_TMP_BUFF_SIZE         2048        /* the size of the temp buffer in mmi_chset_convert() */

typedef enum
{
    CHSET_BASE,
    MMI_CHSET_BASE = CHSET_BASE,
    CHSET_ARABIC_ISO,
    MMI_CHSET_ARABIC_ISO = CHSET_ARABIC_ISO,
    CHSET_ARABIC_WIN,
    MMI_CHSET_ARABIC_WIN = CHSET_ARABIC_WIN,
    /* PMT START PERSIAN */
    CHSET_PERSIAN_CP1097,
    MMI_CHSET_PERSIAN_CP1097 = CHSET_PERSIAN_CP1097,
    CHSET_PERSIAN_CP1098,
    MMI_CHSET_PERSIAN_CP1098 = CHSET_PERSIAN_CP1098,
    /* PMT END PERSIAN */
    CHSET_BALTIC_ISO,
    MMI_CHSET_BALTIC_ISO = CHSET_BALTIC_ISO,
    CHSET_BALTIC_WIN,
    MMI_CHSET_BALTIC_WIN = CHSET_BALTIC_WIN,
    CHSET_CEURO_ISO,
    MMI_CHSET_CEURO_ISO = CHSET_CEURO_ISO,
    CHSET_CEURO_WIN,
    MMI_CHSET_CEURO_WIN = CHSET_CEURO_WIN,
    CHSET_GREEK_ISO,
    MMI_CHSET_GREEK_ISO = CHSET_GREEK_ISO,
    CHSET_GREEK_WIN,
    MMI_CHSET_GREEK_WIN = CHSET_GREEK_WIN,
    CHSET_HEBREW_ISO,
    MMI_CHSET_HEBREW_ISO = CHSET_HEBREW_ISO,
    CHSET_HEBREW_WIN,
    MMI_CHSET_HEBREW_WIN = CHSET_HEBREW_WIN,
    CHSET_LATIN_ISO,
    MMI_CHSET_LATIN_ISO = CHSET_LATIN_ISO,
    CHSET_NORDIC_ISO,
    MMI_CHSET_NORDIC_ISO = CHSET_NORDIC_ISO,
    CHSET_SEURO_ISO,
    MMI_CHSET_SEURO_ISO = CHSET_SEURO_ISO,
    CHSET_TURKISH_ISO,
    MMI_CHSET_TURKISH_ISO = CHSET_TURKISH_ISO,
    CHSET_TURKISH_WIN,
    MMI_CHSET_TURKISH_WIN = CHSET_TURKISH_WIN,
    CHSET_WESTERN_ISO,
    MMI_CHSET_WESTERN_ISO = CHSET_WESTERN_ISO,
    CHSET_WESTERN_WIN,
    MMI_CHSET_WESTERN_WIN = CHSET_WESTERN_WIN,
    /* Add new (8-bit) encodings above this line */
    MMI_CHSET_8_BITS_END,
    CHSET_BIG5,
    MMI_CHSET_BIG5 = CHSET_BIG5,
    CHSET_GB2312,
    MMI_CHSET_GB2312 = CHSET_GB2312,
    CHSET_GB18030,
    MMI_CHSET_GB18030 = CHSET_GB18030,
    CHSET_UTF7,
    MMI_CHSET_UTF7 = CHSET_UTF7,
    CHSET_EUCKR,
    MMI_CHSET_EUCKR = CHSET_EUCKR,
    CHSET_THAI_WIN,
    MMI_CHSET_THAI_WIN = CHSET_THAI_WIN,
    CHSET_VIETNAMESE_WIN,
    MMI_CHSET_VIETNAMESE_WIN = CHSET_VIETNAMESE_WIN,
    MMI_CHSET_KOI8_R,     

    /* PLace all encodings using algo to above this one */
    CHSET_UTF16LE,
    MMI_CHSET_UTF16LE = CHSET_UTF16LE,
    CHSET_UTF16BE,
    MMI_CHSET_UTF16BE = CHSET_UTF16BE,
    CHSET_UTF8,
    MMI_CHSET_UTF8 = CHSET_UTF8,
    CHSET_UCS2,
    MMI_CHSET_UCS2 = CHSET_UCS2,
    CHSET_ASCII,
    MMI_CHSET_ASCII = CHSET_ASCII,
    CHSET_TOTAL,
    MMI_CHSET_TOTAL = CHSET_TOTAL 
} mmi_chset_enum, chset_enum;

/* do not change the order */
typedef enum _ENCODING_SCHEMES_ENUM
{
    BASE_ENCODING_SCHEME,

    ARABIC_ISO_TO_UCS2,
    UCS2_TO_ARABIC_ISO,

    ARABIC_WINDOWS_TO_UCS2,
    UCS2_TO_ARABIC_WINDOWS,
    /* PMT START PERSIAN */
    PERSIAN_CP1097_TO_UCS2,
    UCS2_TO_PERSIAN_CP1097,

    PERSIAN_CP1098_TO_UCS2,
    UCS2_TO_PERSIAN_CP1098,
    /* PMT END PERSIAN */
    BALTIC_ISO_TO_UCS2,
    UCS2_TO_BALTIC_ISO,

    BALTIC_WINDOWS_TO_UCS2,
    UCS2_TO_BALTIC_WINDOWS,

    CENTRAL_EUROPEAN_ISO_TO_UCS2,
    UCS2_TO_CENTRAL_EUROPEAN_ISO,

    CENTRAL_EUROPEAN_WINDOWS_TO_UCS2,
    UCS2_TO_CENTRAL_EUROPEAN_WINDOWS,

    GREEK_ISO_TO_UCS2,
    UCS2_TO_GREEK_ISO,

    GREEK_WINDOWS_TO_UCS2,
    UCS2_TO_GREEK_WINDOWS,

    HEBREW_ISO_TO_UCS2,
    UCS2_TO_HEBREW_ISO,

    HEBREW_WINDOWS_TO_UCS2,
    UCS2_TO_HEBREW_WINDOWS,

    LATIN_ISO_TO_UCS2,
    UCS2_TO_LATIN_ISO,

    NORDIC_ISO_TO_UCS2,
    UCS2_TO_NORDIC_ISO,

    SOUTH_EUROPEAN_ISO_TO_UCS2,
    UCS2_TO_SOUTH_EUROPEAN_ISO,

    TURKISH_ISO_TO_UCS2,
    UCS2_TO_TURKISH_ISO,

    TURKISH_WINDOWS_TO_UCS2,
    UCS2_TO_TURKISH_WINDOWS,

    WESTERN_ISO_TO_UCS2,
    UCS2_TO_WESTERN_ISO,

    WESTERN_WINDOWS_TO_UCS2,
    UCS2_TO_WESTERN_WINDOWS,

    /* Add new (8-bit) encodings above this line */
    MMI_CHSET_8_BITS_END_MARKER1,
    MMI_CHSET_8_BITS_END_MARKER2,

    BIG5_TO_UCS2,
    UCS2_TO_BIG5,

    GB2312_TO_UCS2,
    UCS2_TO_GB2312,

    EUCKR_WINDOWS_TO_UCS2,
    UCS2_TO_EUCKR_WINDOWS,

    THAI_WINDOWS_TO_UCS2,
    UCS2_TO_THAI_WINDOWS,

    VIETNAMESE_WINDOWS_TO_UCS2,
    UCS2_TO_VIETNAMESE_WINDOWS,

    KOI8_R_TO_UCS2,
    UCS2_TO_KOI8_R,

    /* PLace all encodings using algo to above this one */

    UTF8_TO_UCS2,
    UCS2_TO_UTF8,
    CHSET_PAIR_TOTAL
} mmi_chset_pair_enum;

extern mmi_chset_enum g_chset_text_encoding;    /* this value will be updated by MMI phone setup module */

extern kal_uint16 EncodingDecoding(
                    mmi_chset_pair_enum Scheme,
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos);
extern void mmi_chset_init(void);

extern kal_int32 mmi_chset_convert(
                    mmi_chset_enum src_type,
                    mmi_chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size);
extern kal_int32 mmi_chset_convert_ex(
                    mmi_chset_enum src_type,
                    mmi_chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos);

extern kal_int32 chset_convert(
                    chset_enum src_type,
                    chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size);
extern kal_int32 chset_convert_ex(
                    chset_enum src_type,
                    chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos);

extern void mmi_chset_use_space_for_unknown_character(void);
extern void mmi_chset_do_not_use_space_for_unknown_character(void);
extern mmi_chset_convert_with_src_length(
        mmi_chset_enum src_type,
        mmi_chset_enum dest_type,
        char *src_buff,
        kal_int32 src_size,
        char *dest_buff,
        kal_int32 dest_size);
extern kal_uint16 UCS2_TO_WCHAR(kal_uint16 src_char);

extern void mmi_chset_mixed_text_to_ucs2_str(
                kal_uint8 *dest,
                kal_int16 dest_size,
                kal_uint8 *src,
                mmi_chset_enum encoding);
extern void mmi_chset_mixed_text_to_ucs2_str_ex(
                kal_uint8 *dest,
                kal_int16 dest_size,
                kal_uint8 *src,
                mmi_chset_enum encoding,
                kal_uint32 *src_end_pos);

extern kal_int32 mmi_chset_text_to_ucs2(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_text_to_ucs2_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    kal_uint32 *src_end_pos);

/* UTF8 realted */
extern kal_int32 mmi_chset_utf8_to_ucs2(kal_uint8 *ucs2, kal_uint8 *utf8);
extern kal_int32 mmi_chset_ucs2_to_utf8(kal_uint8 *utf8, kal_uint16 ucs2);
extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_utf8_to_ucs2_string_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    kal_uint32 *src_end_pos);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_ucs2_to_utf8_string_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    kal_uint32 *src_end_pos);
extern kal_int32 mmi_chset_utf8_strlen(const kal_uint8 *s);

extern kal_bool mmi_chset_get_charset_id(const kal_int8 *chset_name, mmi_chset_enum *chset_id_p);
extern kal_bool chset_get_charset_id(const kal_int8 *chset_name, chset_enum *chset_id_p);
extern const kal_int8 *chset_get_preferred_mime_name(chset_enum chset_id);

extern kal_int8 mmi_chset_get_utf_byte_order(const kal_int8 *str_bom);

extern kal_int32 mmi_chset_utf16_strlen(const kal_int8 *str_utf16, mmi_chset_enum utf16_type);

extern kal_int32 mmi_chset_ucs2_to_utf16_bom_str(
                    kal_int8 *dest_utf16,
                    kal_int32 dest_size,
                    mmi_chset_enum utf16_type,
                    kal_int8 *src_ucs2,
                    kal_uint32 *src_end_pos);
#endif /* _MMI_CONVERSIONS_H */ 

