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
 * Conversions.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements utilities for encoding/decoding between two charsets
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
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "CharsetTable.h"
#include "stdC.h"

/* Handling UCS2 string not aligned with 2 bytes. (Obigo adopts UTF8 by default) */
#define MMI_CHSET_DBG_ASSERT(_expr)
// #define MMI_CHSET_UTF8_FAULT_TOLERANT
#define MMI_CHSET_UTF8_ALLOW_BOM
#define CAST_PU8(RAW)   ((kal_uint8*)(RAW))
#define CAST_CPU8(RAW)  ((const kal_uint8*)(RAW))
#define GET_U8_BYTE_TO_U16(RAW, i)  ((kal_uint16)(CAST_CPU8(RAW)[i]))
#define STR_SIZE(len) ((len)<<1)
#define STR_AT(RAW, n) ((void*)(CAST_PU8(RAW)+STR_SIZE(n)))
#define CHR_AT(RAW, n) ((kal_uint16)(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n))+(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n)+1)<<8)))
#define SET_CHR_AT(RAW, n, value)   do {                          \
                              kal_uint8 *_p = STR_AT(RAW, n);     \
                              kal_uint16 v= (kal_uint16) (value); \
                              _p[0] = (kal_uint8) (v & 0xff);     \
                              _p[1] = (kal_uint8) (v >> 8);       \
                           } while (0)
#define CHR(x)      ((kal_uint16)(x))

#if defined(__MMI_CHSET_ARABIC_ISO__) || defined(__MMI_CHSET_ARABIC_WIN__) || defined(__MMI_CHSET_BALTIC_ISO__) || defined(__MMI_CHSET_BALTIC_WIN__) || defined(__MMI_CHSET_CEURO_ISO__) || defined(__MMI_CHSET_CEURO_WIN__) || defined(__MMI_CHSET_GREEK_ISO__) || defined(__MMI_CHSET_GREEK_WIN__) || defined(__MMI_CHSET_HEBREW_ISO__) || defined(__MMI_CHSET_HEBREW_WIN__) || defined(__MMI_CHSET_LATIN_ISO__) || defined(__MMI_CHSET_NORDIC_ISO__) || defined(__MMI_CHSET_SEURO_ISO__) || defined(__MMI_CHSET_TURKISH_ISO__) || defined(__MMI_CHSET_TURKISH_WIN__) || defined(__MMI_CHSET_WESTERN_ISO__) || defined(__MMI_CHSET_WESTERN_WIN__) || defined(__MMI_CHSET_PERSIAN_CP1097__) || defined(__MMI_CHSET_PERSIAN_CP1098__)
#define __MMI_CHSET_ALPHABET_SUPPORT__
#endif /* defined(__MMI_CHSET_ARABIC_ISO__) || defined(__MMI_CHSET_ARABIC_WIN__) || defined(__MMI_CHSET_BALTIC_ISO__) || defined(__MMI_CHSET_BALTIC_WIN__) || defined(__MMI_CHSET_CEURO_ISO__) || defined(__MMI_CHSET_CEURO_WIN__) || defined(__MMI_CHSET_GREEK_ISO__) || defined(__MMI_CHSET_GREEK_WIN__) || defined(__MMI_CHSET_HEBREW_ISO__) || defined(__MMI_CHSET_HEBREW_WIN__) || defined(__MMI_CHSET_LATIN_ISO__) || defined(__MMI_CHSET_NORDIC_ISO__) || defined(__MMI_CHSET_SEURO_ISO__) || defined(__MMI_CHSET_TURKISH_ISO__) || defined(__MMI_CHSET_TURKISH_WIN__) || defined(__MMI_CHSET_WESTERN_ISO__) || defined(__MMI_CHSET_WESTERN_WIN__) || defined(__MMI_CHSET_PERSIAN_CP1097__) || defined(__MMI_CHSET_PERSIAN_CP1098__) */ 

#if defined(__MMI_CHSET_BIG5__) || defined(__MMI_CHSET_GB2312__)
#define __MMI_CHSET_IDEOGRAM_SUPPORT__
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/
#define INVERSE_HIGH_LOW_BYTE(x) (((x) >> 8) | (((x) & 0xff)<<8))

#define MERGE_TO_WCHAR(high, low)  (high << 8) + ((kal_uint8)low)
#define UTF16_HIGH_START      0xD800
#define UTF16_HIGH_END        0xDBFF
#define UTF16_LOW_START       0xDC00
#define UTF16_LOW_END         0xDFFF

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct _char_set_ref
{
    mmi_chset_enum chset_id;
    const kal_int8 **chset_name_array;
    kal_uint8 chset_name_count;
} char_set_ref;

typedef struct
{
    const Mapping_Struct *pMappingTable;
    const kal_uint16 *pConversnTable;
    kal_uint16 TotalMapTbIndex;
    kal_uint8 Input_word_bits;
    kal_uint8 Output_word_bits;
    kal_uint16 UndefChar;   /* currently taken undefchar as quesmark */
} mmi_chset_info_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __MMI_CHSET_WESTERN_ISO__
static const kal_int8 *g_chset_western_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-1", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-1:1987",
    (const kal_int8 *)"iso-ir-100",
    (const kal_int8 *)"ISO_8859-1",
    (const kal_int8 *)"latin1",
    (const kal_int8 *)"l1",
    (const kal_int8 *)"IBM819",
    (const kal_int8 *)"CP819",
    (const kal_int8 *)"csISOLatin1"
};

#define CHSET_WESTERN_ISO_NAME_COUNT sizeof(g_chset_western_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_WESTERN_ISO__ */ 

#ifdef __MMI_CHSET_CEURO_ISO__
static const kal_int8 *g_chset_ceuro_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-2", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-2:1987",
    (const kal_int8 *)"iso-ir-101",
    (const kal_int8 *)"ISO_8859-2",
    (const kal_int8 *)"latin2",
    (const kal_int8 *)"l2",
    (const kal_int8 *)"csISOLatin2"
};

#define CHSET_CEURO_ISO_NAME_COUNT sizeof(g_chset_ceuro_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_CEURO_ISO__ */ 

#ifdef __MMI_CHSET_SEURO_ISO__
static const kal_int8 *g_chset_seuro_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-3", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-3:1988",
    (const kal_int8 *)"iso-ir-109",
    (const kal_int8 *)"ISO_8859-3",
    (const kal_int8 *)"latin3",
    (const kal_int8 *)"l3",
    (const kal_int8 *)"csISOLatin3"
};

#define CHSET_SEURO_ISO_NAME_COUNT sizeof(g_chset_seuro_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_SEURO_ISO__ */ 

#ifdef __MMI_CHSET_BALTIC_ISO__
static const kal_int8 *g_chset_baltic_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-4", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-4:1988",
    (const kal_int8 *)"iso-ir-110",
    (const kal_int8 *)"ISO_8859-4",
    (const kal_int8 *)"latin4",
    (const kal_int8 *)"l4",
    (const kal_int8 *)"csISOLatin4"
};

#define CHSET_BALTIC_ISO_NAME_COUNT sizeof( g_chset_baltic_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_BALTIC_ISO__ */ 

#ifdef __MMI_CHSET_ARABIC_ISO__
static const kal_int8 *g_chset_arabic_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-6", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-6:1987",
    (const kal_int8 *)"iso-ir-127",
    (const kal_int8 *)"ISO_8859-6",
    (const kal_int8 *)"ECMA-114",
    (const kal_int8 *)"ASMO-708",
    (const kal_int8 *)"arabic",
    (const kal_int8 *)"csISOLatinArabic"
};

#define CHSET_ARABIC_ISO_NAME_COUNT sizeof(g_chset_arabic_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_ARABIC_ISO__ */ 

#ifdef __MMI_CHSET_GREEK_ISO__
static const kal_int8 *g_chset_greek_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-7", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-7:1987",
    (const kal_int8 *)"iso-ir-126",
    (const kal_int8 *)"ISO_8859-7",
    (const kal_int8 *)"ELOT_928",
    (const kal_int8 *)"ECMA-118",
    (const kal_int8 *)"greek",
    (const kal_int8 *)"greek8",
    (const kal_int8 *)"csISOLatinGreek"
};

#define CHSET_GREEK_ISO_NAME_COUNT sizeof(g_chset_greek_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_GREEK_ISO__ */ 

#ifdef __MMI_CHSET_HEBREW_ISO__
static const kal_int8 *g_chset_hebrew_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-8", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-8:1988",
    (const kal_int8 *)"iso-ir-138",
    (const kal_int8 *)"ISO_8859-8",
    (const kal_int8 *)"hebrew",
    (const kal_int8 *)"csISOLatinHebrew"
};

#define CHSET_HEBREW_ISO_NAME_COUNT sizeof(g_chset_hebrew_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_HEBREW_ISO__ */ 

#ifdef __MMI_CHSET_TURKISH_ISO__
static const kal_int8 *g_chset_turkish_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-9", /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-9:1989",
    (const kal_int8 *)"iso-ir-148",
    (const kal_int8 *)"ISO_8859-9",
    (const kal_int8 *)"latin5",
    (const kal_int8 *)"l5",
    (const kal_int8 *)"csISOLatin5"
};

#define CHSET_TURKISH_ISO_NAME_COUNT sizeof(g_chset_turkish_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_TURKISH_ISO__ */ 

#ifdef __MMI_CHSET_NORDIC_ISO__
static const kal_int8 *g_chset_nordic_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-10",    /* preferred MIME name */
    (const kal_int8 *)"iso-ir-157",
    (const kal_int8 *)"l6",
    (const kal_int8 *)"ISO_8859-10:1992",
    (const kal_int8 *)"csISOLatin6",
    (const kal_int8 *)"latin6",
};

#define CHSET_NORDIC_ISO_NAME_COUNT sizeof(g_chset_nordic_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_NORDIC_ISO__ */ 

#ifdef __MMI_CHSET_LATIN_ISO__
static const kal_int8 *g_chset_latin_iso_name[] = 
{
    (const kal_int8 *)"ISO-8859-15",    /* preferred MIME name */
    (const kal_int8 *)"ISO_8859-15",
    (const kal_int8 *)"Latin-9"
};

#define CHSET_LATIN_ISO_NAME_COUNT sizeof(g_chset_latin_iso_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_LATIN_ISO__ */ 

#ifdef __MMI_CHSET_UTF7__
static const kal_int8 *g_chset_utf7_name[] = 
{
    (const kal_int8 *)"UTF-7"
};

#define CHSET_UTF7_NAME_COUNT sizeof(g_chset_utf7_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_UTF7__ */ 

static const kal_int8 *g_chset_utf8_name[] = 
{
    (const kal_int8 *)"UTF-8"
};

#define CHSET_UTF8_NAME_COUNT sizeof(g_chset_utf8_name)/sizeof(kal_int8*)

#ifdef __MMI_CHSET_CEURO_WIN__
static const kal_int8 *g_chset_ceuro_win_name[] = 
{
    (const kal_int8 *)"windows-1250"
};

#define CHSET_CEURO_WIN_NAME_COUNT sizeof(g_chset_ceuro_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_CEURO_WIN__ */ 

#ifdef __MMI_CHSET_WESTERN_WIN__
static const kal_int8 *g_chset_western_win_name[] = 
{
    (const kal_int8 *)"windows-1252"
};

#define CHSET_WESTERN_WIN_NAME_COUNT sizeof(g_chset_western_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_WESTERN_WIN__ */ 

#ifdef __MMI_CHSET_GREEK_WIN__
static const kal_int8 *g_chset_greek_win_name[] = 
{
    (const kal_int8 *)"windows-1253"
};

#define CHSET_GREEK_WIN_NAME_COUNT sizeof(g_chset_greek_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_GREEK_WIN__ */ 

#ifdef __MMI_CHSET_TURKISH_WIN__
static const kal_int8 *g_chset_turkish_win_name[] = 
{
    (const kal_int8 *)"windows-1254"
};

#define CHSET_TURKISH_WIN_NAME_COUNT sizeof(g_chset_turkish_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_TURKISH_WIN__ */ 

#ifdef __MMI_CHSET_HEBREW_WIN__
static const kal_int8 *g_chset_hebrew_win_name[] = 
{
    (const kal_int8 *)"windows-1255"
};

#define CHSET_HEBREW_WIN_NAME_COUNT sizeof(g_chset_hebrew_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_HEBREW_WIN__ */ 

#ifdef __MMI_CHSET_ARABIC_WIN__
static const kal_int8 *g_chset_arabic_win_name[] = 
{
    (const kal_int8 *)"windows-1256"
};

#define CHSET_ARABIC_WIN_NAME_COUNT sizeof(g_chset_arabic_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_ARABIC_WIN__ */ 

#ifdef __MMI_CHSET_BALTIC_WIN__
static const kal_int8 *g_chset_baltic_win_name[] = 
{
    (const kal_int8 *)"windows-1257"
};

#define CHSET_BALTIC_WIN_NAME_COUNT sizeof(g_chset_baltic_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_BALTIC_WIN__ */ 

#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__
static const kal_int8 *g_chset_vietnamese_win_name[] = 
{
    (const kal_int8 *)"windows-1258"
};

#define CHSET_VIETNAMESE_WIN_NAME_COUNT sizeof(g_chset_vietnamese_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_VIETNAMESE_WINDOWS__ */ 

#ifdef __MMI_CHSET_THAI_WINDOWS__
static const kal_int8 *g_chset_thai_win_name[] = 
{
    (const kal_int8 *)"windows-874"
};

#define CHSET_THAI_WIN_NAME_COUNT sizeof(g_chset_thai_win_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_THAI_WINDOWS__ */ 

#ifdef __MMI_CHSET_PERSIAN_CP1097__
static const kal_int8 *g_chset_persian_cp1097_name[] = 
{
    (const kal_int8 *)"CP1097"
};

#define CHSET_PERSIAN_CP1097_NAME_COUNT sizeof(g_chset_persian_cp1097_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_PERSIAN_CP1097__ */ 

#ifdef __MMI_CHSET_PERSIAN_CP1098__
static const kal_int8 *g_chset_persian_cp1098_name[] = 
{
    (const kal_int8 *)"CP1098"
};

#define CHSET_PERSIAN_CP1098_NAME_COUNT sizeof(g_chset_persian_cp1098_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_PERSIAN_CP1098__ */ 

#ifdef __MMI_CHSET_BIG5__
static const kal_int8 *g_chset_big5_name[] = 
{
    (const kal_int8 *)"Big5",   /* preferred MIME name */
    (const kal_int8 *)"csBig5"
};

#define CHSET_BIG5_NAME_COUNT sizeof(g_chset_big5_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_BIG5__ */ 

#ifdef __MMI_CHSET_GB2312__
static const kal_int8 *g_chset_gb3212_name[] = 
{
    (const kal_int8 *)"GB2312", /* preferred MIME name */
    (const kal_int8 *)"csGB2312"
};

#define CHSET_GB2312_NAME_COUNT sizeof(g_chset_gb3212_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_GB2312__ */ 

#ifdef __MMI_CHSET_GB18030__
static const kal_int8 *g_chset_gb18030_name[] = 
{
    (const kal_int8 *)"GB18030",    /* preferred MIME name */
    (const kal_int8 *)"GBK",
    (const kal_int8 *)"CP936",
    (const kal_int8 *)"MS936",
    (const kal_int8 *)"windows-936"
};

#define CHSET_GB18030_NAME_COUNT sizeof(g_chset_gb18030_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_GB18030__ */ 

#ifdef __MMI_CHSET_EUCKR_WIN__
static const kal_int8 *g_chset_euckr_name[] = 
{
    (const kal_int8 *)"EUC-KR", /* preferred MIME name */
    (const kal_int8 *)"csEUCKR"
};

#define CHSET_EUCKR_NAME_COUNT sizeof(g_chset_euckr_name)/sizeof(kal_int8*)
#endif /* __MMI_CHSET_EUCKR_WIN__ */ 

static const kal_int8 *g_chset_ucs2_name[] = 
{
    (const kal_int8 *)"ISO-10646-UCS-2",
    (const kal_int8 *)"csUnicode"
};

#define CHSET_UCS2_NAME_COUNT sizeof(g_chset_ucs2_name)/sizeof(kal_int8*)

static const kal_int8 *g_chset_ascii_name[] = 
{
    (const kal_int8 *)"US-ASCII",   /* preferred MIME name */
    (const kal_int8 *)"ANSI_X3.4-1968",
    (const kal_int8 *)"iso-ir-6",
    (const kal_int8 *)"ANSI_X3.4-1986",
    (const kal_int8 *)"ISO_646.irv:1991",
    (const kal_int8 *)"ASCII",
    (const kal_int8 *)"ISO646-US",
    (const kal_int8 *)"us",
    (const kal_int8 *)"IBM367",
    (const kal_int8 *)"cp367",
    (const kal_int8 *)"csASCII"
};

#define CHSET_ASCII_NAME_COUNT sizeof(g_chset_ascii_name)/sizeof(kal_int8*)

static const kal_int8 *g_chset_utf16le_name[] = 
{
    (const kal_int8 *)"UTF-16LE"
};

#define CHSET_UTF16LE_NAME_COUNT sizeof(g_chset_utf16le_name)/sizeof(kal_int8*)

static const kal_int8 *g_chset_utf16be_name[] = 
{
    (const kal_int8 *)"UTF-16BE",
    (const kal_int8 *)"UTF-16"
};

#define CHSET_UTF16BE_NAME_COUNT sizeof(g_chset_utf16be_name)/sizeof(kal_int8*)

#ifdef __MMI_CHSET_KOI8_R__

static const kal_int8 *g_chset_koi8_r_name[] = 
{
    (const kal_int8 *)"KOI8-R",
    (const kal_int8 *)"csKOI8R"
};

#define CHSET_KOI8_R_NAME_COUNT sizeof(g_chset_koi8_r_name)/sizeof(kal_int8*)

#endif /* __MMI_CHSET_KOI8_R__ */

static const char_set_ref g_char_set_ref_tbl[] = 
{
#ifdef __MMI_CHSET_WESTERN_ISO__
    {MMI_CHSET_WESTERN_ISO, g_chset_western_iso_name, CHSET_WESTERN_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_CEURO_ISO__
    {MMI_CHSET_CEURO_ISO, g_chset_ceuro_iso_name, CHSET_CEURO_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_SEURO_ISO__
    {MMI_CHSET_SEURO_ISO, g_chset_seuro_iso_name, CHSET_SEURO_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_BALTIC_ISO__
    {MMI_CHSET_BALTIC_ISO, g_chset_baltic_iso_name, CHSET_BALTIC_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_ARABIC_ISO__
    {MMI_CHSET_ARABIC_ISO, g_chset_arabic_iso_name, CHSET_ARABIC_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_GREEK_ISO__
    {MMI_CHSET_GREEK_ISO, g_chset_greek_iso_name, CHSET_GREEK_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_HEBREW_ISO__
    {MMI_CHSET_HEBREW_ISO, g_chset_hebrew_iso_name, CHSET_HEBREW_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_TURKISH_ISO__
    {MMI_CHSET_TURKISH_ISO, g_chset_turkish_iso_name, CHSET_TURKISH_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_NORDIC_ISO__
    {MMI_CHSET_NORDIC_ISO, g_chset_nordic_iso_name, CHSET_NORDIC_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_LATIN_ISO__
    {MMI_CHSET_LATIN_ISO, g_chset_latin_iso_name, CHSET_LATIN_ISO_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_UTF7__
    {MMI_CHSET_UTF7, g_chset_utf7_name, CHSET_UTF7_NAME_COUNT},
#endif 

    {MMI_CHSET_UTF8, g_chset_utf8_name, CHSET_UTF8_NAME_COUNT},

    {MMI_CHSET_UTF16LE, g_chset_utf16le_name, CHSET_UTF16LE_NAME_COUNT},

    {MMI_CHSET_UTF16BE, g_chset_utf16be_name, CHSET_UTF16BE_NAME_COUNT},

    {MMI_CHSET_ASCII, g_chset_ascii_name, CHSET_ASCII_NAME_COUNT},

    {MMI_CHSET_UCS2, g_chset_ucs2_name, CHSET_UCS2_NAME_COUNT},

#ifdef __MMI_CHSET_CEURO_WIN__
    {MMI_CHSET_CEURO_WIN, g_chset_ceuro_win_name, CHSET_CEURO_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_WESTERN_WIN__
    {MMI_CHSET_WESTERN_WIN, g_chset_western_win_name, CHSET_WESTERN_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_GREEK_WIN__
    {MMI_CHSET_GREEK_WIN, g_chset_greek_win_name, CHSET_GREEK_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_TURKISH_WIN__
    {MMI_CHSET_TURKISH_WIN, g_chset_turkish_win_name, CHSET_TURKISH_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_HEBREW_WIN__
    {MMI_CHSET_HEBREW_WIN, g_chset_hebrew_win_name, CHSET_HEBREW_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_ARABIC_WIN__
    {MMI_CHSET_ARABIC_WIN, g_chset_arabic_win_name, CHSET_ARABIC_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_BALTIC_WIN__
    {MMI_CHSET_BALTIC_WIN, g_chset_baltic_win_name, CHSET_BALTIC_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__
    {MMI_CHSET_VIETNAMESE_WIN, g_chset_vietnamese_win_name, CHSET_VIETNAMESE_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_THAI_WINDOWS__
    {MMI_CHSET_THAI_WIN, g_chset_thai_win_name, CHSET_THAI_WIN_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_PERSIAN_CP1097__
    {MMI_CHSET_PERSIAN_CP1097, g_chset_persian_cp1097_name, CHSET_PERSIAN_CP1097_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_PERSIAN_CP1098__
    {MMI_CHSET_PERSIAN_CP1098, g_chset_persian_cp1098_name, CHSET_PERSIAN_CP1098_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_BIG5__
    {MMI_CHSET_BIG5, g_chset_big5_name, CHSET_BIG5_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_GB2312__
    {MMI_CHSET_GB2312, g_chset_gb3212_name, CHSET_GB2312_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_GB18030__
    {MMI_CHSET_GB18030, g_chset_gb18030_name, CHSET_GB18030_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_EUCKR_WIN__
    {MMI_CHSET_EUCKR, g_chset_euckr_name, CHSET_EUCKR_NAME_COUNT},
#endif 

#ifdef __MMI_CHSET_KOI8_R__
    {MMI_CHSET_KOI8_R, g_chset_koi8_r_name, CHSET_KOI8_R_NAME_COUNT},
#endif /* __MMI_CHSET_KOI8_R__ */

    {MMI_CHSET_TOTAL, NULL, 0},
};

/***************************************************************************** 
* Local Function
*****************************************************************************/
static kal_int32 mmi_chset_stricmp(const kal_char *dst, const kal_char *src);
static kal_int32 mmi_chset_utf16_to_ucs2_string(
                    kal_int8 *dest_ucs2,
                    kal_int32 dest_size,
                    kal_int8 *src_utf16,
                    mmi_chset_enum utf16_type,
                    kal_uint32 *src_end_pos);

static kal_int32 mmi_chset_ucs2_to_utf16_string(
                    kal_int8 *dest_utf16,
                    kal_int32 dest_size,
                    mmi_chset_enum utf16_type,
                    kal_bool include_bom,
                    kal_int8 *src_ucs2,
                    kal_uint32 *src_end_pos);

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
const key_index_t *g_chset_ucs2_to_encode_key_LSB_index[NO_OF_TEXT_ENCODING] = 
{
#ifdef __MMI_CHSET_BIG5__
    g_chset_ucs2_to_big5_key_LSB_index,
#else 
    NULL,
#endif 
#ifdef __MMI_CHSET_GB2312__
    g_chset_ucs2_to_gb2312_key_LSB_index
#else 
    NULL
#endif 
};

const key_index_t *g_chset_encode_to_ucs2_key_LSB_index[NO_OF_TEXT_ENCODING] = 
{
#ifdef __MMI_CHSET_BIG5__
    g_chset_big5_to_ucs2_key_LSB_index,
#else 
    NULL,
#endif 
#ifdef __MMI_CHSET_GB2312__
    g_chset_gb2312_to_ucs2_key_LSB_index
#else 
    NULL
#endif 
};

const kal_uint8 *g_chset_ucs2_to_encode_key_MSB[NO_OF_TEXT_ENCODING] = 
{
#ifdef __MMI_CHSET_BIG5__
    g_chset_ucs2_to_big5_key_MSB,
#else 
    NULL,
#endif 
#ifdef __MMI_CHSET_GB2312__
    g_chset_ucs2_to_gb2312_key_MSB
#else 
    NULL
#endif 
};

const kal_uint8 *g_chset_encode_to_ucs2_key_MSB[NO_OF_TEXT_ENCODING] = 
{
#ifdef __MMI_CHSET_BIG5__
    g_chset_big5_to_ucs2_key_MSB,
#else 
    NULL,
#endif 
#ifdef __MMI_CHSET_GB2312__
    g_chset_gb2312_to_ucs2_key_MSB
#else 
    NULL
#endif 
};

const kal_uint16 *g_chset_ucs2_to_encode_table[NO_OF_TEXT_ENCODING] = 
{
#ifdef __MMI_CHSET_BIG5__
    g_chset_ucs2_to_big5_table,
#else 
    NULL,
#endif 
#ifdef __MMI_CHSET_GB2312__
    g_chset_ucs2_to_gb2312_table
#else 
    NULL
#endif 
};

const kal_uint16 *g_chset_encode_to_ucs2_table[NO_OF_TEXT_ENCODING] = 
{
#ifdef __MMI_CHSET_BIG5__
    g_chset_big5_to_ucs2_table,
#else 
    NULL,
#endif 
#ifdef __MMI_CHSET_GB2312__
    g_chset_gb2312_to_ucs2_table
#else 
    NULL
#endif 
};

const kal_uint16 g_chset_unknown_encode_char_no_space[] = 
{
    0xFFFF,
    0xFFFF
};

const kal_uint16 g_chset_unknown_encode_char_space[] = 
{
    0x20,
    0x20
};

const kal_uint16 *g_chset_unknown_encode_char = g_chset_unknown_encode_char_no_space;
#endif /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 

static const kal_uint8 g_cheset_utf8_bytes_per_char[16] = 
{
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 2, 2, 3, 4  /* we don't support UCS4 */
};

const kal_uint8 g_chset_state[] = 
{
    0,

#ifdef __MMI_CHSET_ARABIC_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_ARABIC_WIN__
    1,
#else 
    0,
#endif 

    /* PMT START PERSIAN */
#ifdef __MMI_CHSET_PERSIAN_CP1097__
    1,
#else 
    0,
#endif 
#ifdef __MMI_CHSET_PERSIAN_CP1098__
    1,
#else 
    0,
#endif 
    /* PMT END PERSIAN */
#ifdef __MMI_CHSET_BALTIC_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_BALTIC_WIN__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_CEURO_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_CEURO_WIN__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_GREEK_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_GREEK_WIN__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_HEBREW_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_HEBREW_WIN__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_LATIN_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_NORDIC_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_SEURO_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_TURKISH_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_TURKISH_WIN__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_WESTERN_ISO__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_WESTERN_WIN__
    1,
#else 
    0,
#endif 

    1,  /* MMI_CHSET_8_BITS_END *//* Add new (8-bit) encodings above this line */

#ifdef __MMI_CHSET_BIG5__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_GB2312__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_GB18030__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_UTF7__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_EUCKR_WIN__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_THAI_WINDOWS__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__
    1,
#else 
    0,
#endif 

#ifdef __MMI_CHSET_KOI8_R__
    1,
#else
    0,
#endif

    /* PLace all encodings using algo to above this one */
    1,  /* MMI_CHSET_UTF16LE, */
    1,  /* MMI_CHSET_UTF16BE, */
    1,  /* MMI_CHSET_UTF8, */
    1,  /* MMI_CHSET_UCS2, */
    1,  /* MMI_CHSET_ASCII */
    1   /* MMI_CHSET_TOTAL */
};

typedef enum
{
    CHSET_BASE_ENUM,

#ifdef __MMI_CHSET_ARABIC_ISO__
    CHSET_ARABIC_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_ARABIC_WIN__
    CHSET_ARABIC_WIN_ENUM,
#endif 
    /* PMT START PERSIAN */
#ifdef __MMI_CHSET_PERSIAN_CP1097__
    CHSET_PERSIAN_CP1097_ENUM,
#endif 
#ifdef __MMI_CHSET_PERSIAN_CP1098__
    CHSET_PERSIAN_CP1098_ENUM,
#endif 
    /* PMT END PERSIAN */
#ifdef __MMI_CHSET_BALTIC_ISO__
    CHSET_BALTIC_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_BALTIC_WIN__
    CHSET_BALTIC_WIN_ENUM,
#endif 

#ifdef __MMI_CHSET_CEURO_ISO__
    CHSET_CEURO_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_CEURO_WIN__
    CHSET_CEURO_WIN_ENUM,
#endif 

#ifdef __MMI_CHSET_GREEK_ISO__
    CHSET_GREEK_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_GREEK_WIN__
    CHSET_GREEK_WIN_ENUM,
#endif 

#ifdef __MMI_CHSET_HEBREW_ISO__
    CHSET_HEBREW_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_HEBREW_WIN__
    CHSET_HEBREW_WIN_ENUM,
#endif 

#ifdef __MMI_CHSET_LATIN_ISO__
    CHSET_LATIN_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_NORDIC_ISO__
    CHSET_NORDIC_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_SEURO_ISO__
    CHSET_SEURO_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_TURKISH_ISO__
    CHSET_TURKISH_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_TURKISH_WIN__
    CHSET_TURKISH_WIN_ENUM,
#endif 

#ifdef __MMI_CHSET_WESTERN_ISO__
    CHSET_WESTERN_ISO_ENUM,
#endif 

#ifdef __MMI_CHSET_WESTERN_WIN__
    CHSET_WESTERN_WIN_ENUM,
#endif 

    CHSET_CEURO_8_BITS_END_ENUM,    /* MMI_CHSET_8_BITS_END *//* Add new (8-bit) encodings above this line */

#ifdef __MMI_CHSET_BIG5__
    CHSET_BIG5_ENUM,
#endif 

#ifdef __MMI_CHSET_GB2312__
    CHSET_GB2312_ENUM,
#endif 

#ifdef __MMI_CHSET_GB18030__
    CHSET_GB18030_ENUM,
#endif 

#ifdef __MMI_CHSET_UTF7__
    CHSET_UTF7_ENUM,
#endif 

    CHSET_UTF16LE_ENUM,
    CHSET_UTF16BE_ENUM,

#ifdef __MMI_CHSET_EUCKR_WIN__
    CHSET_EUCKR_ENUM,
#endif 

#ifdef __MMI_CHSET_THAI_WINDOWS__
    CHSET_THAI_ENUM,
#endif 

#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__
    CHSET_VIETNAMESE_ENUM,
#endif 

#ifdef __MMI_CHSET_KOI8_R__
    CHSET_KOI8_R_ENUM,
#endif  

    CHSET_TOTAL_ENUM
} mmi_chset_count_enum;

 /*   Extern Declarations */
mmi_chset_info_struct g_chset_tbl[CHSET_PAIR_TOTAL];

#if defined(__MMI_CHSET_BIG5__)
mmi_chset_enum g_chset_text_encoding = MMI_CHSET_BIG5;
#elif defined(__MMI_CHSET_GB2312__)
mmi_chset_enum g_chset_text_encoding = MMI_CHSET_GB2312;
#else 
mmi_chset_enum g_chset_text_encoding = MMI_CHSET_UTF8;
#endif 

/***************************************************************************** 
* Global Function
*****************************************************************************/
#ifdef __MMI_CHSET_GB18030__


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_gb18030_to_ucs2_2_byte_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  dest        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_chset_gb18030_to_ucs2_2_byte_search(kal_uint16 src, kal_uint16 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 start, end, mid;
    kal_uint16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start = 0;
    end = mmi_chset_gb18030_ucs2_2byte_size() - 1;
    while (start <= end)
    {
        if ((end - start) == 1) /* to prevent missed-comaprison */
        {
            mid = end;
        }
        else
        {
            mid = (start + end) / 2;
        }
        result = g_chset_gb18030_to_ucs2_2_byte_tbl[mid].gb_code;
        if (src > result)
        {
            start = mid + 1;
        }
        else if (src < result)
        {
            end = mid - 1;
        }
        else    /* found */
        {
            *dest = g_chset_gb18030_to_ucs2_2_byte_tbl[mid].ucs2_code;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_gb18030_to_ucs2_4_byte_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  dest        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_chset_gb18030_to_ucs2_4_byte_search(kal_uint32 src, kal_uint16 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 start, end, mid;
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start = 0;
    end = mmi_chset_gb18030_ucs2_4byte_size() - 1;
    while (start <= end)
    {
        if ((end - start) == 1) /* to prevent missed-comaprison */
        {
            mid = end;
        }
        else
        {
            mid = (start + end) / 2;
        }
        result =
            (kal_uint32) ((g_chset_gb18030_to_ucs2_4_byte_tbl[mid].gb_code_high << 16) +
                          (g_chset_gb18030_to_ucs2_4_byte_tbl[mid].gb_code_low));
        if (src > result)
        {
            start = mid + 1;
        }
        else if (src < result)
        {
            end = mid - 1;
        }
        else    /* found */
        {
            *dest = g_chset_gb18030_to_ucs2_4_byte_tbl[mid].ucs2_code;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_gb18030_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  inLen           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_gb18030_to_ucs2(unsigned char *pOutBuffer, unsigned char *pInBuffer, kal_int32 inLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char c1, c2, c3, c4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pre-insert unknown character */
    pOutBuffer[0] = 0xff;
    pOutBuffer[1] = 0xff;

    c1 = pInBuffer[0];
    if (c1 < 0x80)  /* 1 byte */
    {
        pOutBuffer[0] = pInBuffer[0];
        pOutBuffer[1] = 0x00;
        return 1;   /* consume 1 byte */
    }

    if (inLen >= 2)
    {
        c2 = pInBuffer[1];
    }
    else
    {
        return 1;   /* consume 1 byte */
    }

    /* 2 bytes */
    if ((c1 >= 0x81 && c1 <= 0xfe) && ((c2 >= 0x40 && c2 <= 0x7e) || (c2 >= 0x80 && c2 <= 0xfe)))
    {
        kal_uint16 src, dest;

        src = (((c1 << 8) & 0xff00) + c2);

        /* binary search 2 bytes table */
        if (mmi_chset_gb18030_to_ucs2_2_byte_search(src, &dest))
        {
            pOutBuffer[0] = (unsigned char)(dest & 0xff);
            pOutBuffer[1] = (unsigned char)(dest >> 8);
            return 2;
        }
        else
        {
            return 1;   /* consume 1 byte */
        }
    }

    if (inLen >= 4) /* 4 bytes */
    {
        c3 = pInBuffer[2];
        c4 = pInBuffer[3];;

        if (c1 >= 0x81 && c2 <= 0xfe)
            if (c2 >= 0x30 && c2 <= 0x39)
                if (c3 >= 0x81 && c3 <= 0xfe)
                    if (c4 >= 0x30 && c4 <= 0x39)
                    {
                        kal_uint32 src;
                        kal_uint16 dest;

                        /* binary search 4 bytes table */
                        src = (kal_uint32) ((c1 << 24) + (c2 << 16) + (c3 << 8) + c4);

                        if (mmi_chset_gb18030_to_ucs2_4_byte_search(src, &dest))
                        {
                            pOutBuffer[0] = (unsigned char)(dest & 0xff);
                            pOutBuffer[1] = (unsigned char)(dest >> 8);
                            return 4;
                        }
                        else
                        {
                            return 1;   /* consume 1 byte */
                        }
                    }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_gb18030_to_ucs2_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  dest_size       [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 mmi_chset_gb18030_to_ucs2_str(
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *in_cursor = pInBuffer;
    char *out_cursor = pOutBuffer;
    char tmp_result[2];

    kal_uint16 diget_len;
    kal_int32 in_len = strlen(pInBuffer);
    kal_int32 out_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (in_len && dest_size > (out_len + 2))
    {
        diget_len = mmi_chset_gb18030_to_ucs2((unsigned char*)&tmp_result, (unsigned char*)in_cursor, in_len);
        if (tmp_result[0] == 0xFF && tmp_result[1] == 0xFF && in_len == diget_len)
        {
            /* the last remained data of pInBuffer may be segmented */
            break;
        }
        in_len -= diget_len;
        in_cursor += diget_len;

        out_cursor[0] = tmp_result[0];
        out_cursor[1] = tmp_result[1];
        out_cursor += 2;
        out_len += 2;
    }
    *src_end_pos = (kal_uint32) in_cursor;

    pOutBuffer[out_len] = 0;
    pOutBuffer[++out_len] = 0;
    return (out_len + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_gb18030_to_ucs2_str_with_src_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  dest_size       [IN]        
 *  in_len          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 mmi_chset_gb18030_to_ucs2_str_with_src_length(
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_int32 in_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *in_cursor = pInBuffer;
    char *out_cursor = pOutBuffer;
    char tmp_result[2];

    kal_uint16 diget_len;
    kal_int32 out_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (in_len && dest_size > (out_len + 2))
    {
        diget_len = mmi_chset_gb18030_to_ucs2((unsigned char*)&tmp_result, (unsigned char*)in_cursor, in_len);
        in_len -= diget_len;
        in_cursor += diget_len;

        out_cursor[0] = tmp_result[0];
        out_cursor[1] = tmp_result[1];
        out_cursor += 2;
        out_len += 2;
    }

    return (out_len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_gb18030_2_byte_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  dest        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_chset_ucs2_to_gb18030_2_byte_search(kal_uint16 src, kal_uint32 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 start, end, mid;
    kal_uint16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start = 0;
    end = mmi_chset_ucs2_gb18030_2byte_size() - 1;
    while (start <= end)
    {
        if ((end - start) == 1) /* to prevent missed-comaprison */
        {
            mid = end;
        }
        else
        {
            mid = (start + end) / 2;
        }
        result = g_chset_ucs2_to_gb18030_2_byte_tbl[mid].ucs2_code;
        if (src > result)
        {
            start = mid + 1;
        }
        else if (src < result)
        {
            end = mid - 1;
        }
        else    /* found */
        {
            *dest = g_chset_ucs2_to_gb18030_2_byte_tbl[mid].gb_code;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_gb18030_4_byte_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  dest        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_chset_ucs2_to_gb18030_4_byte_search(kal_uint16 src, kal_uint32 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 start, end, mid;
    kal_uint16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start = 0;
    end = mmi_chset_ucs2_gb18030_4byte_size() - 1;
    while (start <= end)
    {
        if ((end - start) == 1) /* to prevent missed-comaprison */
        {
            mid = end;
        }
        else
        {
            mid = (start + end) / 2;
        }
        result = g_chset_ucs2_to_gb18030_4_byte_tbl[mid].ucs2_code;
        if (src > result)
        {
            start = mid + 1;
        }
        else if (src < result)
        {
            end = mid - 1;
        }
        else    /* found */
        {
            *dest =
                (kal_uint32) ((g_chset_ucs2_to_gb18030_4_byte_tbl[mid].gb_code_high << 16) +
                              g_chset_ucs2_to_gb18030_4_byte_tbl[mid].gb_code_low);
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_gb18030
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_ucs2_to_gb18030(unsigned char *pOutBuffer, unsigned char *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ucs2_char;
    kal_uint32 gb_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* single byte */
    if (pInBuffer[1] == 0 && pInBuffer[0] < 0x80)
    {
        pOutBuffer[0] = pInBuffer[0];
        return 1;
    }

    ucs2_char = ((pInBuffer[1] << 8) + pInBuffer[0]);
    /* search 2 bytes table */
    if (mmi_chset_ucs2_to_gb18030_2_byte_search(ucs2_char, &gb_char))
    {
        pOutBuffer[0] = (unsigned char)((gb_char >> 8) & 0xff);
        pOutBuffer[1] = (unsigned char)(gb_char & 0xff);
        return 2;
    }

    /* search 4 bytes table */
    if (mmi_chset_ucs2_to_gb18030_4_byte_search(ucs2_char, &gb_char))
    {
        pOutBuffer[0] = (unsigned char)((gb_char >> 24) & 0xff);
        pOutBuffer[1] = (unsigned char)((gb_char >> 16) & 0xff);
        pOutBuffer[2] = (unsigned char)((gb_char >> 8) & 0xff);
        pOutBuffer[3] = (unsigned char)(gb_char & 0xff);
        return 4;
    }

    /* unknown character */
    pOutBuffer[0] = 0xff;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_gb18030_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  dest_size       [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 mmi_chset_ucs2_to_gb18030_str(
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *in_cursor = pInBuffer;
    char *out_cursor = pOutBuffer;
    char tmp_result[4];

    kal_int32 out_len = 0;
    kal_int32 i;
    kal_uint16 result_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((in_cursor[0] != 0) || (in_cursor[1] != 0) && (dest_size > (out_len + 2)))
    {
        result_len = mmi_chset_ucs2_to_gb18030((unsigned char*)&tmp_result, (unsigned char*)in_cursor);

        for (i = (result_len - 1); i >= 0; i--)
        {
            out_cursor[i] = tmp_result[i];
        }

        in_cursor += 2;
        out_cursor += result_len;
        out_len += result_len;
    }
    *src_end_pos = (kal_uint32) in_cursor;

    pOutBuffer[out_len] = 0;
    pOutBuffer[++out_len] = 0;
    return (out_len + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_gb18030_str_with_src_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  dest_size       [IN]        
 *  src_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 mmi_chset_ucs2_to_gb18030_str_with_src_length(
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_int32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *in_cursor = pInBuffer;
    char *out_cursor = pOutBuffer;
    char tmp_result[4];

    kal_int32 out_len = 0;
    kal_int32 i;
    kal_uint16 result_len;
    kal_int32 src_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (src_index < src_size && (dest_size > (out_len + 2)))
    {
        result_len = mmi_chset_ucs2_to_gb18030((unsigned char*)&tmp_result, (unsigned char*)in_cursor);

        for (i = (result_len - 1); i >= 0; i--)
        {
            out_cursor[i] = tmp_result[i];
        }

        in_cursor += 2;
        out_cursor += result_len;
        out_len += result_len;
        src_index += 2;
    }

    return (out_len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_convert_with_src_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  dest_type       [IN]        
 *  src_buff        [IN]        
 *  src_size        [IN]        
 *  dest_buff       [OUT]       
 *  dest_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_convert_with_src_length(
            mmi_chset_enum src_type,
            mmi_chset_enum dest_type,
            char *src_buff,
            kal_int32 src_size,
            char *dest_buff,
            kal_int32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_type == MMI_CHSET_GB18030 && dest_type == MMI_CHSET_UCS2)
    {
        return mmi_chset_gb18030_to_ucs2_str_with_src_length(dest_buff, src_buff, dest_size, src_size);
    }
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_GB18030)
    {
        return mmi_chset_ucs2_to_gb18030_str_with_src_length(dest_buff, src_buff, dest_size, src_size);
    }
    /* only support GB18030 for now */
    return 0;

}
#endif /* __MMI_CHSET_GB18030__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_use_space_for_unknown_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chset_use_space_for_unknown_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    g_chset_unknown_encode_char = g_chset_unknown_encode_char_space;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_do_not_use_space_for_unknown_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chset_do_not_use_space_for_unknown_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    g_chset_unknown_encode_char = g_chset_unknown_encode_char_no_space;
#endif 
}

#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_binary_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key                 [IN]        
 *  lookup_table        [IN]        
 *  start               [IN]        
 *  end                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 mmi_chset_binary_search(
                    const kal_uint8 key,
                    const kal_uint8 *lookup_table,
                    kal_int16 start,
                    kal_int16 end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (start <= end)
    {
        kal_int16 mid = (start + end) / 2;

        if (key > lookup_table[mid])
        {
            start = mid + 1;
        }
        else if (key < lookup_table[mid])
        {
            end = mid - 1;
        }
        else    /* key == target */
        {
            return mid;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_encode_decode_algo2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Scheme          [IN]        
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  nBuffsize       [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 mmi_chset_encode_decode_algo2(
                    mmi_chset_pair_enum Scheme,
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 nBuffsize,
                    kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (Scheme)
    {
    #ifdef __MMI_CHSET_GB2312__
        case GB2312_TO_UCS2:
            return mmi_chset_text_to_ucs2_str_ex(
                    (kal_uint8*) pOutBuffer,
                    (kal_int16) nBuffsize,
                    (kal_uint8*) pInBuffer,
                    GB2312_ENCODING_TYPE,
                    src_end_pos);
        case UCS2_TO_GB2312:
            return mmi_chset_ucs2_to_text_str_ex(
                    (kal_uint8*) pOutBuffer,
                    (kal_int16) nBuffsize,
                    (kal_uint8*) pInBuffer,
                    GB2312_ENCODING_TYPE,
                    src_end_pos);
    #endif /* __MMI_CHSET_GB2312__ */ 
    #ifdef __MMI_CHSET_BIG5__
        case BIG5_TO_UCS2:
            return mmi_chset_text_to_ucs2_str_ex(
                    (kal_uint8*) pOutBuffer,
                    (kal_int16) nBuffsize,
                    (kal_uint8*) pInBuffer,
                    BIG_5_ENCODING_TYPE,
                    src_end_pos);
        case UCS2_TO_BIG5:
            return mmi_chset_ucs2_to_text_str_ex(
                    (kal_uint8*) pOutBuffer,
                    (kal_int16) nBuffsize,
                    (kal_uint8*) pInBuffer,
                    BIG_5_ENCODING_TYPE,
                    src_end_pos);
    #endif /* __MMI_CHSET_BIG5__ */ 
        default:
            return 0;
    }
}

/* dest_size must be >= 4 */


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_text_to_ucs2_str_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 *  encoding        [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_text_to_ucs2_str_ex(
            kal_uint8 *dest,
            kal_int16 dest_size,
            kal_uint8 *src,
            TextEncodingEnum encoding,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const key_index_t *key_LSB_index_table = g_chset_encode_to_ucs2_key_LSB_index[encoding];
    const kal_uint8 *key_MSB_table = g_chset_encode_to_ucs2_key_MSB[encoding];
    const kal_uint16 *ucs2_table = g_chset_encode_to_ucs2_table[encoding];

    kal_uint8 key_LSB;
    kal_uint8 key_MSB;
    kal_int16 start;
    kal_int16 end;
    kal_int16 pos = 0;
    kal_int16 index;
    kal_uint8 *src_end = src + strlen((char*)src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*(src) != 0) /* I do not know how we assume that this is end of data.. Currently we are taking only chinese encodings for
                           the optimized algo so we can take it as 2 bytes */
    {
        if (*(src) <= 0x7f)
        {
            *(dest + pos) = *src;
            pos++;
            *(dest + pos) = 0;
            pos++;
            src += 1;
        }
        else
        {
            key_LSB = (kal_uint8) (*(src));
            start = key_LSB_index_table[key_LSB].start;

            if (start < 0)
            {
                if (src_end - src <= 1)
                {
                    /* can't encoding the character. The data may be segmented. */
                    break;
                }
                else
                {
                    dest[pos] = (kal_uint8) g_chset_unknown_encode_char[encoding];
                    dest[pos + 1] = (kal_uint8) (g_chset_unknown_encode_char[encoding] >> 8);
                }
            }
            else
            {
                key_MSB = (kal_uint8) (*(src + 1));
                end = key_LSB_index_table[key_LSB].end;
                if ((index = mmi_chset_binary_search(key_MSB, key_MSB_table, start, end)) < 0)  /* key MSB not found */
                {
                    if (src_end - src <= 1)
                    {
                        /* can't encoding the character. The data may be segmented. */
                        break;
                    }
                    else
                    {
                        dest[pos] = (kal_uint8) g_chset_unknown_encode_char[encoding];
                        dest[pos + 1] = (kal_uint8) (g_chset_unknown_encode_char[encoding] >> 8);
                    }
                }
                else
                {
                    dest[pos] = (kal_uint8) ucs2_table[index];
                    dest[pos + 1] = (kal_uint8) (ucs2_table[index] >> 8);

                }
            }
            src += 2;
            pos += 2;
        }
        if (pos >= dest_size - 2)
        {
            break;
        }
    }
    *src_end_pos = (kal_uint32) src;
    dest[pos] = 0;
    dest[pos + 1] = 0;
    return pos + 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_text_to_ucs2_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 *  encoding        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_text_to_ucs2_str(kal_uint8 *dest, kal_int16 dest_size, kal_uint8 *src, TextEncodingEnum encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32) src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_text_to_ucs2_str_ex(dest, dest_size, src, encoding, &src_end_pos);
}

/* dest_size must be >= 4 */


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_text_str_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 *  encoding        [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_ucs2_to_text_str_ex(
            kal_uint8 *dest,
            kal_int16 dest_size,
            kal_uint8 *src,
            TextEncodingEnum encoding,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const key_index_t *key_LSB_index_table = g_chset_ucs2_to_encode_key_LSB_index[encoding];
    const kal_uint8 *key_MSB_table = g_chset_ucs2_to_encode_key_MSB[encoding];
    const kal_uint16 *encode_table = g_chset_ucs2_to_encode_table[encoding];
    kal_uint8 key_LSB;
    kal_uint8 key_MSB;
    kal_int16 start;
    kal_int16 end;
    kal_int16 index;
    kal_int16 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*src || *(src + 1))
    {
        if (*src <= 0x7f && *(src + 1) == 0)
        {
            *(dest + pos) = *(src);
            pos++;
        }
        else
        {
            /*
             * The original conversion tables of mmi_chset_ucs2_to_text_str() seem to assume the src is big-endian,
             * but the src should be little-endian. We need to change the byte order.
             */
            key_LSB = (kal_uint8) (*(src + 1));
            start = key_LSB_index_table[key_LSB].start;
            if (start < 0)
            {
                dest[pos] = (kal_uint8) (g_chset_unknown_encode_char[encoding] >> 8);
                dest[pos + 1] = (kal_uint8) g_chset_unknown_encode_char[encoding];
            }
            else
            {
                key_MSB = (kal_uint8) (*(src));
                end = key_LSB_index_table[key_LSB].end;
                if ((index = mmi_chset_binary_search(key_MSB, key_MSB_table, start, end)) < 0)  /* key MSB not found */
                {
                    dest[pos] = (kal_uint8) (g_chset_unknown_encode_char[encoding] >> 8);
                    dest[pos + 1] = (kal_uint8) g_chset_unknown_encode_char[encoding];
                }
                else
                {
                    dest[pos] = (kal_uint8) (encode_table[index] >> 8);
                    dest[pos + 1] = (kal_uint8) encode_table[index];
                }

            }
            pos += 2;
        }
        src += 2;

        if (pos >= dest_size - 2)
        {
            break;
        }
    }
    *src_end_pos = (kal_uint32) src;
    dest[pos] = 0;
    dest[pos + 1] = 0;
    return pos + 2;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_text_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        Src buffer length should be 2 time value
 *  encoding        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_ucs2_to_text_str(kal_uint8 *dest, kal_int16 dest_size, kal_uint8 *src, TextEncodingEnum encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32) src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_ucs2_to_text_str_ex(dest, dest_size, src, encoding, &src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_is_text_in_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_chset_is_text_in_str(kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*src != 0 || *(src + 1) != 0)
    {
        if (*src <= 0x7f && *(src + 1) == 0)
        {
            src += 2;
        }
        else
        {
            return TRUE;
        }
    }
    return FALSE;
}
#endif /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_wchar_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  encode_char     [IN]        
 *  encoding        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_wchar_to_ucs2(kal_uint16 encode_char, TextEncodingEnum encoding)
{
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const key_index_t *key_LSB_index_table = g_chset_encode_to_ucs2_key_LSB_index[encoding];
    const kal_uint8 *key_MSB_table = g_chset_encode_to_ucs2_key_MSB[encoding];
    const kal_uint16 *ucs2_table = g_chset_encode_to_ucs2_table[encoding];

    kal_uint8 key_LSB = (kal_uint8) (encode_char & 0xff);
    kal_uint8 key_MSB;
    kal_int16 start = key_LSB_index_table[key_LSB].start;
    kal_int16 end;
    kal_int16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start < 0)  /* key LSB not found in index table */
    {
        return UNKOWN_UCS2_CHAR;
    }

    key_MSB = (kal_uint8) (encode_char >> 8);
    end = key_LSB_index_table[key_LSB].end;
    if ((index = mmi_chset_binary_search(key_MSB, key_MSB_table, start, end)) < 0)      /* key MSB not found */
    {
        return UNKOWN_UCS2_CHAR;
    }

    return ucs2_table[index];
#else /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
    return UNKOWN_UCS2_CHAR;
#endif /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_wchar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2_char       [IN]        
 *  encoding        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mmi_chset_ucs2_to_wchar(kal_uint16 ucs2_char, TextEncodingEnum encoding)
{
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const key_index_t *key_LSB_index_table = g_chset_ucs2_to_encode_key_LSB_index[encoding];
    const kal_uint8 *key_MSB_table = g_chset_ucs2_to_encode_key_MSB[encoding];
    const kal_uint16 *encode_table = g_chset_ucs2_to_encode_table[encoding];

    kal_uint8 key_LSB = (kal_uint8) (ucs2_char >> 8);
    kal_uint8 key_MSB;
    kal_int16 start = key_LSB_index_table[key_LSB].start;
    kal_int16 end;
    kal_int16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start < 0)  /* key LSB not found in index table */
    {
        return g_chset_unknown_encode_char[encoding];
    }

    key_MSB = (kal_uint8) (ucs2_char & 0xff);
    end = key_LSB_index_table[key_LSB].end;
    if ((index = mmi_chset_binary_search(key_MSB, key_MSB_table, start, end)) < 0)      /* key MSB not found */
    {
        return g_chset_unknown_encode_char[encoding];
    }

    return encode_table[index];
#else /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
    return 0xffff;
#endif /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_text_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_text_to_ucs2(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_convert(g_chset_text_encoding, MMI_CHSET_UCS2, (char*)src, (char*)dest, dest_size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_text_to_ucs2_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_text_to_ucs2_ex(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src, kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_convert_ex(
            g_chset_text_encoding,
            MMI_CHSET_UCS2,
            (char*)src,
            (char*)dest,
            dest_size,
            src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_mixed_text_to_ucs2_str_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 *  encoding        [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chset_mixed_text_to_ucs2_str_ex(
        kal_uint8 *dest,
        kal_int16 dest_size,
        kal_uint8 *src,
        mmi_chset_enum encoding,
        kal_uint32 *src_end_pos)
{
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 pos = 0;
    kal_bool copy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_chset_state[encoding] == 0)
    {
        copy = KAL_TRUE;
    }
    else
    {
        copy = KAL_FALSE;
    }

    while (*src != 0 || *(src + 1) != 0)
    {
        if (copy || (*src <= 0x7f && *(src + 1) == 0))
        {
            *(dest + pos) = *src;
            pos++;
            *(dest + pos) = *(src + 1);
            pos++;
        }
        else
        {
            if (pos <= dest_size - 4)
            {
                mmi_chset_convert(encoding, MMI_CHSET_UCS2, (char*)src, (char*)(dest + pos), 4);
            }
            pos += 2;
        }
        src += 2;
        if (pos >= dest_size - 2)
        {
            break;
        }
    }
    *src_end_pos = (kal_uint32) src;
    dest[pos] = 0;
    dest[pos + 1] = 0;
#else /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
    kal_int16 pos = 0;

    while (*src != 0 || *(src + 1) != 0)
    {
        *(dest + pos) = *src;
        pos++;
        *(dest + pos) = *(src + 1);
        pos++;
        src += 2;
        if (pos >= dest_size - 2)
        {
            break;
        }
    }
    *src_end_pos = (kal_uint32) src;
    dest[pos] = 0;
    dest[pos + 1] = 0;
#endif /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_mixed_text_to_ucs2_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        Src buffer length should be 2 time value
 *  encoding        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chset_mixed_text_to_ucs2_str(kal_uint8 *dest, kal_int16 dest_size, kal_uint8 *src, mmi_chset_enum encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32) src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_mixed_text_to_ucs2_str_ex(dest, dest_size, src, encoding, &src_end_pos);
}

/* return big endian value */


/*****************************************************************************
 * FUNCTION
 *  UCS2_TO_WCHAR
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_char        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 UCS2_TO_WCHAR(kal_uint16 src_char)
{
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 src_buff[4];
    kal_uint8 dest_buff[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_buff[0] = (kal_uint8) (src_char & 0xFF);
    src_buff[1] = (kal_uint8) (src_char >> 8);
    src_buff[2] = 0;
    src_buff[3] = 0;
    if (mmi_chset_convert(MMI_CHSET_UCS2, g_chset_text_encoding, (char*)src_buff, (char*)dest_buff, 4))
    {
        return (kal_uint16) (dest_buff[0] << 8 | dest_buff[1]);
    }
    else
    {
        return 0xA440;
    }
#else /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
    return 0xA440;
#endif /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_init
 * DESCRIPTION
 *  Routine for initializing the related data structures of the various encoding types
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chset_init(void)
{
#ifdef __MMI_CHSET_BIG5__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_chset_tbl[BIG5_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[BIG5_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[BIG5_TO_UCS2].UndefChar = 0xFF1F;

    g_chset_tbl[UCS2_TO_BIG5].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_BIG5].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_BIG5].UndefChar = 0xA148;
#endif /* __MMI_CHSET_BIG5__ */ 

#ifdef __MMI_CHSET_GB2312__
    g_chset_tbl[GB2312_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[GB2312_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[GB2312_TO_UCS2].UndefChar = 0xFF1F;

    g_chset_tbl[UCS2_TO_GB2312].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_GB2312].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_GB2312].UndefChar = 0x233F;
#endif /* __MMI_CHSET_GB2312__ */ 

#ifdef __MMI_CHSET_TURKISH_ISO__
    g_chset_tbl[TURKISH_ISO_TO_UCS2].pConversnTable = &g_chset_turkish_ucs2_iso[0];
    g_chset_tbl[TURKISH_ISO_TO_UCS2].pMappingTable = &g_chset_map_turkish_ucs2_iso[0];
    g_chset_tbl[TURKISH_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_turkish_ucs2_iso_size();
    g_chset_tbl[TURKISH_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[TURKISH_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[TURKISH_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_TURKISH_ISO].pConversnTable = &g_chset_ucs2_turkish_iso[0];
    g_chset_tbl[UCS2_TO_TURKISH_ISO].pMappingTable = &g_chset_map_ucs2_turkish_iso[0];
    g_chset_tbl[UCS2_TO_TURKISH_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_turkish_iso_size();
    g_chset_tbl[UCS2_TO_TURKISH_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_TURKISH_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_TURKISH_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_TURKISH_ISO__ */ 

#ifdef __MMI_CHSET_TURKISH_WIN__
    g_chset_tbl[TURKISH_WINDOWS_TO_UCS2].pConversnTable = &g_chset_turkish_ucs2_win[0];
    g_chset_tbl[TURKISH_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_turkish_ucs2_win[0];
    g_chset_tbl[TURKISH_WINDOWS_TO_UCS2].TotalMapTbIndex = mmi_chset_map_turkish_ucs2_win_size();
    g_chset_tbl[TURKISH_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[TURKISH_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[TURKISH_WINDOWS_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_TURKISH_WINDOWS].pConversnTable = &g_chset_ucs2_turkish_win[0];
    g_chset_tbl[UCS2_TO_TURKISH_WINDOWS].pMappingTable = &g_chset_map_ucs2_turkish_win[0];
    g_chset_tbl[UCS2_TO_TURKISH_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_turkish_win_size();
    g_chset_tbl[UCS2_TO_TURKISH_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_TURKISH_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_TURKISH_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_TURKISH_WIN__ */ 

#ifdef __MMI_CHSET_BALTIC_ISO__
    g_chset_tbl[BALTIC_ISO_TO_UCS2].pConversnTable = &g_chset_baltic_ucs2_iso[0];
    g_chset_tbl[BALTIC_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[BALTIC_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[BALTIC_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[BALTIC_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[BALTIC_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_BALTIC_ISO].pConversnTable = &g_chset_ucs2_baltic_iso[0];
    g_chset_tbl[UCS2_TO_BALTIC_ISO].pMappingTable = &g_chset_map_ucs2_baltic_iso[0];
    g_chset_tbl[UCS2_TO_BALTIC_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_baltic_iso_size();
    g_chset_tbl[UCS2_TO_BALTIC_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_BALTIC_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_BALTIC_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_BALTIC_ISO__ */ 

#ifdef __MMI_CHSET_BALTIC_WIN__
    g_chset_tbl[BALTIC_WINDOWS_TO_UCS2].pConversnTable = &g_chset_baltic_ucs2_win[0];
    g_chset_tbl[BALTIC_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[BALTIC_WINDOWS_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[BALTIC_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[BALTIC_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[BALTIC_WINDOWS_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_BALTIC_WINDOWS].pConversnTable = &g_chset_ucs2_baltic_win[0];
    g_chset_tbl[UCS2_TO_BALTIC_WINDOWS].pMappingTable = &g_chset_map_ucs2_baltic_win[0];
    g_chset_tbl[UCS2_TO_BALTIC_WINDOWS].TotalMapTbIndex = mmi_chset_map_baltic_ucs2_win_size();
    g_chset_tbl[UCS2_TO_BALTIC_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_BALTIC_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_BALTIC_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_BALTIC_WIN__ */ 

#ifdef __MMI_CHSET_CEURO_ISO__
    g_chset_tbl[CENTRAL_EUROPEAN_ISO_TO_UCS2].pConversnTable = &g_chset_ceuro_ucs2_iso[0];
    g_chset_tbl[CENTRAL_EUROPEAN_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[CENTRAL_EUROPEAN_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[CENTRAL_EUROPEAN_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[CENTRAL_EUROPEAN_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[CENTRAL_EUROPEAN_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_ISO].pConversnTable = &g_chset_ucs2_ceuro_iso[0];
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_ISO].pMappingTable = &g_chset_map_ucs2_ceuro_iso[0];
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_ceuro_iso_size();
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_CEURO_ISO__ */ 

#ifdef __MMI_CHSET_CEURO_WIN__
    g_chset_tbl[CENTRAL_EUROPEAN_WINDOWS_TO_UCS2].pConversnTable = &g_chset_ceuro_ucs2_win[0];
    g_chset_tbl[CENTRAL_EUROPEAN_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[CENTRAL_EUROPEAN_WINDOWS_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[CENTRAL_EUROPEAN_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[CENTRAL_EUROPEAN_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[CENTRAL_EUROPEAN_WINDOWS_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_WINDOWS].pConversnTable = &g_chset_ucs2_ceuro_win[0];
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_WINDOWS].pMappingTable = &g_chset_map_ucs2_ceuro_win[0];
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_ceuro_win_size();
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_CENTRAL_EUROPEAN_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_CEURO_WIN__ */ 

#ifdef __MMI_CHSET_GREEK_ISO__
    g_chset_tbl[GREEK_ISO_TO_UCS2].pConversnTable = &g_chset_greek_ucs2_iso[0];
    g_chset_tbl[GREEK_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[GREEK_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[GREEK_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[GREEK_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[GREEK_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_GREEK_ISO].pConversnTable = &g_chset_ucs2_greek_iso[0];
    g_chset_tbl[UCS2_TO_GREEK_ISO].pMappingTable = &g_chset_map_ucs2_greek_iso[0];
    g_chset_tbl[UCS2_TO_GREEK_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_greek_iso_size();
    g_chset_tbl[UCS2_TO_GREEK_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_GREEK_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_GREEK_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_GREEK_ISO__ */ 

#ifdef __MMI_CHSET_GREEK_WIN__
    g_chset_tbl[GREEK_WINDOWS_TO_UCS2].pConversnTable = &g_chset_greek_ucs2_win[0];
    g_chset_tbl[GREEK_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[GREEK_WINDOWS_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[GREEK_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[GREEK_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[GREEK_WINDOWS_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_GREEK_WINDOWS].pConversnTable = &g_chset_ucs2_greek_win[0];
    g_chset_tbl[UCS2_TO_GREEK_WINDOWS].pMappingTable = &g_chset_map_ucs2_greek_win[0];
    g_chset_tbl[UCS2_TO_GREEK_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_greek_win_size();
    g_chset_tbl[UCS2_TO_GREEK_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_GREEK_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_GREEK_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_GREEK_WIN__ */ 

#ifdef __MMI_CHSET_HEBREW_ISO__
    g_chset_tbl[HEBREW_ISO_TO_UCS2].pConversnTable = &g_chset_hebrew_ucs2_iso[0];
    g_chset_tbl[HEBREW_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[HEBREW_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[HEBREW_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[HEBREW_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[HEBREW_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_HEBREW_ISO].pConversnTable = &g_chset_ucs2_hebrew_iso[0];
    g_chset_tbl[UCS2_TO_HEBREW_ISO].pMappingTable = &g_chset_map_ucs2_hebrew_iso[0];
    g_chset_tbl[UCS2_TO_HEBREW_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_hebrew_iso_size();
    g_chset_tbl[UCS2_TO_HEBREW_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_HEBREW_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_HEBREW_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_HEBREW_ISO__ */ 

#ifdef __MMI_CHSET_LATIN_ISO__
    g_chset_tbl[LATIN_ISO_TO_UCS2].pConversnTable = &g_chset_latin_ucs2_iso[0];
    g_chset_tbl[LATIN_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[LATIN_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[LATIN_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[LATIN_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[LATIN_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_LATIN_ISO].pConversnTable = &g_chset_ucs2_latin_iso[0];
    g_chset_tbl[UCS2_TO_LATIN_ISO].pMappingTable = &g_chset_map_ucs2_latin_iso[0];
    g_chset_tbl[UCS2_TO_LATIN_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_latin_iso_size();
    g_chset_tbl[UCS2_TO_LATIN_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_LATIN_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_LATIN_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_LATIN_ISO__ */ 

#ifdef __MMI_CHSET_NORDIC_ISO__
    g_chset_tbl[NORDIC_ISO_TO_UCS2].pConversnTable = &g_chset_nordic_ucs2_iso[0];
    g_chset_tbl[NORDIC_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[NORDIC_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[NORDIC_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[NORDIC_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[NORDIC_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_NORDIC_ISO].pConversnTable = &g_chset_ucs2_nordic_iso[0];
    g_chset_tbl[UCS2_TO_NORDIC_ISO].pMappingTable = &g_chset_map_ucs2_nordic_iso[0];
    g_chset_tbl[UCS2_TO_NORDIC_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_nordic_iso_size();
    g_chset_tbl[UCS2_TO_NORDIC_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_NORDIC_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_NORDIC_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_NORDIC_ISO__ */ 

#ifdef __MMI_CHSET_SEURO_ISO__
    g_chset_tbl[SOUTH_EUROPEAN_ISO_TO_UCS2].pConversnTable = &g_chset_seuro_ucs2_iso[0];
    g_chset_tbl[SOUTH_EUROPEAN_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[SOUTH_EUROPEAN_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[SOUTH_EUROPEAN_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[SOUTH_EUROPEAN_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[SOUTH_EUROPEAN_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_SOUTH_EUROPEAN_ISO].pConversnTable = &g_chset_ucs2_seuro_iso[0];
    g_chset_tbl[UCS2_TO_SOUTH_EUROPEAN_ISO].pMappingTable = &g_chset_map_ucs2_seuro_iso[0];
    g_chset_tbl[UCS2_TO_SOUTH_EUROPEAN_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_seuro_iso_size();
    g_chset_tbl[UCS2_TO_SOUTH_EUROPEAN_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_SOUTH_EUROPEAN_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_SOUTH_EUROPEAN_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_SEURO_ISO__ */ 

#ifdef __MMI_CHSET_WESTERN_ISO__
    g_chset_tbl[WESTERN_ISO_TO_UCS2].pConversnTable = &g_chset_western_ucs2_iso[0];
    g_chset_tbl[WESTERN_ISO_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[WESTERN_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[WESTERN_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[WESTERN_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[WESTERN_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_WESTERN_ISO].pConversnTable = &g_chset_ucs2_western_iso[0];
    g_chset_tbl[UCS2_TO_WESTERN_ISO].pMappingTable = &g_chset_map_ucs2_western_iso[0];
    g_chset_tbl[UCS2_TO_WESTERN_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_western_iso_size();
    g_chset_tbl[UCS2_TO_WESTERN_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_WESTERN_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_WESTERN_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_WESTERN_ISO__ */ 

#ifdef __MMI_CHSET_WESTERN_WIN__
    g_chset_tbl[WESTERN_WINDOWS_TO_UCS2].pConversnTable = &g_chset_western_ucs2_win[0];
    g_chset_tbl[WESTERN_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[WESTERN_WINDOWS_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[WESTERN_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[WESTERN_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[WESTERN_WINDOWS_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_WESTERN_WINDOWS].pConversnTable = &g_chset_ucs2_western_win[0];
    g_chset_tbl[UCS2_TO_WESTERN_WINDOWS].pMappingTable = &g_chset_map_ucs2_western_win[0];
    g_chset_tbl[UCS2_TO_WESTERN_WINDOWS].TotalMapTbIndex = mmi_chset_map_western_ucs2_win_size();
    g_chset_tbl[UCS2_TO_WESTERN_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_WESTERN_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_WESTERN_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_WESTERN_WIN__ */ 

#ifdef __MMI_CHSET_ARABIC_ISO__
    g_chset_tbl[ARABIC_ISO_TO_UCS2].pConversnTable = &g_chset_arabic_ucs2_iso[0];
    g_chset_tbl[ARABIC_ISO_TO_UCS2].pMappingTable = &g_chset_map_arabic_ucs2_iso[0];
    g_chset_tbl[ARABIC_ISO_TO_UCS2].TotalMapTbIndex = mmi_chset_map_arabic_ucs2_iso_size();
    g_chset_tbl[ARABIC_ISO_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[ARABIC_ISO_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[ARABIC_ISO_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_ARABIC_ISO].pConversnTable = &g_chset_ucs2_arabic_iso[0];
    g_chset_tbl[UCS2_TO_ARABIC_ISO].pMappingTable = &g_chset_map_ucs2_arabic_iso[0];
    g_chset_tbl[UCS2_TO_ARABIC_ISO].TotalMapTbIndex = mmi_chset_map_ucs2_arabic_iso_size();
    g_chset_tbl[UCS2_TO_ARABIC_ISO].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_ARABIC_ISO].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_ARABIC_ISO].UndefChar = 0x3F;
#endif /* __MMI_CHSET_ARABIC_ISO__ */ 

#ifdef __MMI_CHSET_ARABIC_WIN__
    g_chset_tbl[ARABIC_WINDOWS_TO_UCS2].pConversnTable = &g_chset_arabic_ucs2_win[0];
    g_chset_tbl[ARABIC_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[ARABIC_WINDOWS_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[ARABIC_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[ARABIC_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[ARABIC_WINDOWS_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_ARABIC_WINDOWS].pConversnTable = &g_chset_ucs2_arabic_win[0];
    g_chset_tbl[UCS2_TO_ARABIC_WINDOWS].pMappingTable = &g_chset_map_ucs2_arabic_win[0];
    g_chset_tbl[UCS2_TO_ARABIC_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_arabic_win_size();
    g_chset_tbl[UCS2_TO_ARABIC_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_ARABIC_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_ARABIC_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_ARABIC_WIN__ */ 
    /* PMT START PERSIAN */
#ifdef __MMI_CHSET_PERSIAN_CP1097__
    g_chset_tbl[PERSIAN_CP1097_TO_UCS2].pConversnTable = &g_chset_persian_ucs2_cp1097[0];
    g_chset_tbl[PERSIAN_CP1097_TO_UCS2].pMappingTable = &g_chset_map_persian_ucs2_cp1097[0];
    g_chset_tbl[PERSIAN_CP1097_TO_UCS2].TotalMapTbIndex = mmi_chset_map_persian_ucs2_cp1097_size();
    g_chset_tbl[PERSIAN_CP1097_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[PERSIAN_CP1097_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[PERSIAN_CP1097_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_PERSIAN_CP1097].pConversnTable = &g_chset_ucs2_persian_cp1097[0];
    g_chset_tbl[UCS2_TO_PERSIAN_CP1097].pMappingTable = &g_chset_map_ucs2_persian_cp1097[0];
    g_chset_tbl[UCS2_TO_PERSIAN_CP1097].TotalMapTbIndex = mmi_chset_map_ucs2_persian_cp1097_size();
    g_chset_tbl[UCS2_TO_PERSIAN_CP1097].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_PERSIAN_CP1097].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_PERSIAN_CP1097].UndefChar = 0x3F;
#endif /* __MMI_CHSET_PERSIAN_CP1097__ */ 
#ifdef __MMI_CHSET_PERSIAN_CP1098__
    g_chset_tbl[PERSIAN_CP1098_TO_UCS2].pConversnTable = &g_chset_persian_ucs2_cp1098[0];
    g_chset_tbl[PERSIAN_CP1098_TO_UCS2].pMappingTable = &g_chset_map_persian_ucs2_cp1098[0];
    g_chset_tbl[PERSIAN_CP1098_TO_UCS2].TotalMapTbIndex = mmi_chset_map_persian_ucs2_cp1098_size();
    g_chset_tbl[PERSIAN_CP1098_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[PERSIAN_CP1098_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[PERSIAN_CP1098_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_PERSIAN_CP1098].pConversnTable = &g_chset_ucs2_persian_cp1098[0];
    g_chset_tbl[UCS2_TO_PERSIAN_CP1098].pMappingTable = &g_chset_map_ucs2_persian_cp1098[0];
    g_chset_tbl[UCS2_TO_PERSIAN_CP1098].TotalMapTbIndex = mmi_chset_map_ucs2_persian_cp1098_size();
    g_chset_tbl[UCS2_TO_PERSIAN_CP1098].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_PERSIAN_CP1098].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_PERSIAN_CP1098].UndefChar = 0x3F;
#endif /* __MMI_CHSET_PERSIAN_CP1098__ */ 
    /* PMT END PERSIAN */
#ifdef __MMI_CHSET_HEBREW_WIN__
    g_chset_tbl[HEBREW_WINDOWS_TO_UCS2].pConversnTable = &g_chset_hebrew_ucs2_win[0];
    g_chset_tbl[HEBREW_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_ucs2_common[0];
    g_chset_tbl[HEBREW_WINDOWS_TO_UCS2].TotalMapTbIndex = mmi_chset_map_ucs2_common_size();
    g_chset_tbl[HEBREW_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[HEBREW_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[HEBREW_WINDOWS_TO_UCS2].UndefChar = 0x003F;

    g_chset_tbl[UCS2_TO_HEBREW_WINDOWS].pConversnTable = &g_chset_ucs2_hebrew_win[0];
    g_chset_tbl[UCS2_TO_HEBREW_WINDOWS].pMappingTable = &g_chset_map_ucs2_hebrew_win[0];
    g_chset_tbl[UCS2_TO_HEBREW_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_hebrew_win_size();
    g_chset_tbl[UCS2_TO_HEBREW_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_HEBREW_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_HEBREW_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_HEBREW_WIN__ */ 

#ifdef __MMI_CHSET_EUCKR_WIN__
    g_chset_tbl[EUCKR_WINDOWS_TO_UCS2].pConversnTable = &g_chset_euckr_ucs2_win[0];
    g_chset_tbl[EUCKR_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_euckr_ucs2_win[0];
    g_chset_tbl[EUCKR_WINDOWS_TO_UCS2].TotalMapTbIndex = g_chset_map_euckr_ucs2_win_size();
    g_chset_tbl[EUCKR_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[EUCKR_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[EUCKR_WINDOWS_TO_UCS2].UndefChar = 0x003F;
    g_chset_tbl[UCS2_TO_EUCKR_WINDOWS].pConversnTable = &g_chset_ucs2_euckr_win[0];
    g_chset_tbl[UCS2_TO_EUCKR_WINDOWS].pMappingTable = &g_chset_map_ucs2_euckr_win[0];
    g_chset_tbl[UCS2_TO_EUCKR_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_euckr_win_size();
    g_chset_tbl[UCS2_TO_EUCKR_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_EUCKR_WINDOWS].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_EUCKR_WINDOWS].UndefChar = 0x003F;
#endif /* __MMI_CHSET_EUCKR_WIN__ */ 
#ifdef __MMI_CHSET_THAI_WINDOWS__
    g_chset_tbl[THAI_WINDOWS_TO_UCS2].pConversnTable = &g_chset_thai_ucs2_win[0];
    g_chset_tbl[THAI_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_thai_ucs2_win[0];
    g_chset_tbl[THAI_WINDOWS_TO_UCS2].TotalMapTbIndex = g_chset_map_thai_ucs2_win_size();
    g_chset_tbl[THAI_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[THAI_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[THAI_WINDOWS_TO_UCS2].UndefChar = 0x003F;
    g_chset_tbl[UCS2_TO_THAI_WINDOWS].pConversnTable = &g_chset_ucs2_thai_win[0];
    g_chset_tbl[UCS2_TO_THAI_WINDOWS].pMappingTable = &g_chset_map_ucs2_thai_win[0];
    g_chset_tbl[UCS2_TO_THAI_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_thai_win_size();
    g_chset_tbl[UCS2_TO_THAI_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_THAI_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_THAI_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_THAI_WINDOWS__ */ 
#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__
    g_chset_tbl[VIETNAMESE_WINDOWS_TO_UCS2].pConversnTable = &g_chset_vietnamese_ucs2_win[0];
    g_chset_tbl[VIETNAMESE_WINDOWS_TO_UCS2].pMappingTable = &g_chset_map_vietnamese_ucs2_win[0];
    g_chset_tbl[VIETNAMESE_WINDOWS_TO_UCS2].TotalMapTbIndex = g_chset_map_vietnamese_ucs2_win_size();
    g_chset_tbl[VIETNAMESE_WINDOWS_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[VIETNAMESE_WINDOWS_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[VIETNAMESE_WINDOWS_TO_UCS2].UndefChar = 0x003F;
    g_chset_tbl[UCS2_TO_VIETNAMESE_WINDOWS].pConversnTable = &g_chset_ucs2_vietnamese_win[0];
    g_chset_tbl[UCS2_TO_VIETNAMESE_WINDOWS].pMappingTable = &g_chset_map_ucs2_vietnamese_win[0];
    g_chset_tbl[UCS2_TO_VIETNAMESE_WINDOWS].TotalMapTbIndex = mmi_chset_map_ucs2_vietnamese_win_size();
    g_chset_tbl[UCS2_TO_VIETNAMESE_WINDOWS].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_VIETNAMESE_WINDOWS].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_VIETNAMESE_WINDOWS].UndefChar = 0x3F;
#endif /* __MMI_CHSET_VIETNAMESE_WINDOWS__ */ 

#ifdef __MMI_CHSET_KOI8_R__
    g_chset_tbl[KOI8_R_TO_UCS2].pConversnTable = &g_chset_koi8_r_ucs2[0];
    g_chset_tbl[KOI8_R_TO_UCS2].pMappingTable = &g_chset_map_koi8_r_ucs2[0];
    g_chset_tbl[KOI8_R_TO_UCS2].TotalMapTbIndex = mmi_chset_map_koi8_r_ucs2_size();
    g_chset_tbl[KOI8_R_TO_UCS2].Input_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[KOI8_R_TO_UCS2].Output_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[KOI8_R_TO_UCS2].UndefChar = 0x003F;
    g_chset_tbl[UCS2_TO_KOI8_R].pConversnTable = &g_chset_ucs2_koi8_r[0];
    g_chset_tbl[UCS2_TO_KOI8_R].pMappingTable = &g_chset_map_ucs2_koi8_r[0];
    g_chset_tbl[UCS2_TO_KOI8_R].TotalMapTbIndex = mmi_chset_map_ucs2_koi8_r_size();
    g_chset_tbl[UCS2_TO_KOI8_R].Input_word_bits = CHSET_BIT_WORD_16;
    g_chset_tbl[UCS2_TO_KOI8_R].Output_word_bits = CHSET_BIT_WORD_8;
    g_chset_tbl[UCS2_TO_KOI8_R].UndefChar = 0x3F;
#endif /* __MMI_CHSET_KOI8_R__ */

}

#ifdef __MMI_CHSET_ALPHABET_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  BinarySearchForEncodings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  CharToSearch        [IN]        
 *  Scheme              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 BinarySearchForEncodings(kal_uint16 CharToSearch, mmi_chset_pair_enum Scheme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 StartValue = 0, MidValue = 0, LastValue = 0;
    const Mapping_Struct *pMappingTable = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LastValue = g_chset_tbl[Scheme].TotalMapTbIndex;
    pMappingTable = g_chset_tbl[Scheme].pMappingTable;
    for (MidValue = ((StartValue + LastValue) / 2); StartValue <= LastValue; MidValue = (StartValue + LastValue) / 2)
    {
        if (CharToSearch > pMappingTable[MidValue].end_value)
        {
            StartValue = MidValue + 1;
        }
        else if (CharToSearch < pMappingTable[MidValue].start_value)
        {
            LastValue = MidValue - 1;
        }
        else
        {
            return (kal_int32) MidValue;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_encode_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Scheme          [IN]        
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  dest_size       [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 mmi_chset_encode_decode(
                    mmi_chset_pair_enum Scheme,
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 UndefChar = 0;
    kal_int32 count = 0;
    kal_int32 SearchedValueIndex = -1;
    kal_uint8 InputWordBits, OutputWordBits;
    kal_uint16 index;
    const Mapping_Struct *pMappingTable = 0;
    const kal_uint16 *pConversnTable = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pConversnTable = g_chset_tbl[Scheme].pConversnTable;
    pMappingTable = g_chset_tbl[Scheme].pMappingTable;
    InputWordBits = g_chset_tbl[Scheme].Input_word_bits;
    OutputWordBits = g_chset_tbl[Scheme].Output_word_bits;
    UndefChar = g_chset_tbl[Scheme].UndefChar;

    if (pConversnTable != 0 && pMappingTable != 0)  /* If mapping table exist */
    {
        if (InputWordBits == CHSET_BIT_WORD_16)
        {
            for (count = 0; pInBuffer[count] != 0 || pInBuffer[count + 1] != 0; count = count + 2)
            {
                kal_uint16 TempChar;

                /* check for maximum output bufer size */
                if ((OutputWordBits == CHSET_BIT_WORD_16) && (count >= dest_size - 2))
                {
                    count = (kal_uint16) dest_size - 2;
                    break;
                }
                else if ((OutputWordBits == CHSET_BIT_WORD_8) && (count / 2 >= dest_size - 1))
                {
                    count = (kal_uint16) (dest_size - 1) * 2;
                    break;
                }

                TempChar = (kal_uint8) pInBuffer[count + 1];
                TempChar <<= 8;
                TempChar |= (kal_uint8) (pInBuffer[count]);

                if (TempChar < (pMappingTable[0].start_value))
                {
                    SearchedValueIndex = -1;
                }
                else
                {
                    SearchedValueIndex = BinarySearchForEncodings(TempChar, Scheme);
                }

                if (SearchedValueIndex >= 0)
                {
                    index = TempChar - pMappingTable[(kal_uint16) SearchedValueIndex].start_value;
                    index = pMappingTable[(kal_uint16) SearchedValueIndex].index + index;

                    if (OutputWordBits == CHSET_BIT_WORD_16)
                    {
                        pOutBuffer[count] = (kal_uint8) pConversnTable[index];
                        pOutBuffer[count + 1] = (kal_uint8) (pConversnTable[index] >> 8);
                    }
                    else
                    {
                        pOutBuffer[count / 2] = (kal_uint8) pConversnTable[index];
                    }
                }
                else
                {
                    /* can't encoding the character. */
                    if (OutputWordBits == CHSET_BIT_WORD_16)
                    {
                        pOutBuffer[count] = (kal_uint8) UndefChar;
                        pOutBuffer[count + 1] = (kal_uint8) (UndefChar >> 8);
                    }
                    else
                    {
                        pOutBuffer[count / 2] = (kal_uint8) UndefChar;
                    }
                    
                    if (pInBuffer[count + 2] == 0 && pInBuffer[count + 3] == 0)
                    {
                        /* The data may be segmented at the end of pInBuffer[]. */
                        break;
                    }                    
                }
            }

            *src_end_pos = (kal_uint32) (pInBuffer + count);

            if (OutputWordBits == CHSET_BIT_WORD_16)
            {
                pOutBuffer[count] = 0;
                pOutBuffer[++count] = 0;
                return count + 1;
            }
            else
            {
                pOutBuffer[count / 2] = 0;
                return (count / 2 + 1);
            }
        }       /* if InputWordBits=CHSET_BIT_WORD_16 */
        else    /* if InputWordBits=CHSET_BIT_WORD_8 */
        {
            kal_uint8 TempChar;

            for (count = 0; pInBuffer[count] != 0; count++)
            {
                TempChar = pInBuffer[count];
                /* check for maximum output bufer size */
                if ((OutputWordBits == CHSET_BIT_WORD_16) && (count * 2 >= dest_size - 2))
                {
                    count = ((kal_uint16) dest_size - 2) / 2;
                    break;
                }
                else if ((OutputWordBits == CHSET_BIT_WORD_8) && (count >= dest_size - 1))
                {
                    count = (kal_uint16) dest_size - 1;
                    break;
                }

                if (TempChar < (pMappingTable[0].start_value))
                {
                    SearchedValueIndex = -1;
                }
                else
                {
                    SearchedValueIndex = BinarySearchForEncodings(TempChar, Scheme);
                }

                if (SearchedValueIndex >= 0)
                {
                    index = TempChar - pMappingTable[(kal_uint16) SearchedValueIndex].start_value;
                    index = pMappingTable[(kal_uint16) SearchedValueIndex].index + index;
                    if (OutputWordBits == CHSET_BIT_WORD_16)
                    {
                        pOutBuffer[count * 2] = (kal_uint8) pConversnTable[index];
                        pOutBuffer[count * 2 + 1] = (kal_uint8) (pConversnTable[index] >> 8);
                    }
                    else
                    {
                        pOutBuffer[count] = (kal_uint8) pConversnTable[index];
                    }
                }
                else
                {
                    if (OutputWordBits == CHSET_BIT_WORD_16)
                    {
                        pOutBuffer[count * 2] = (kal_uint8) UndefChar;
                        pOutBuffer[count * 2 + 1] = (kal_uint8) (UndefChar >> 8);
                    }
                    else
                    {
                        pOutBuffer[count] = (kal_uint8) UndefChar;
                    }
                }
            }

            *src_end_pos = (kal_uint32) (pInBuffer + count);

            if (OutputWordBits == CHSET_BIT_WORD_16)
            {
                pOutBuffer[count * 2] = 0;
                pOutBuffer[(count * 2) + 1] = 0;
                return (count * 2 + 2);
            }
            else
            {
                pOutBuffer[count] = 0;
                return (count + 1);
            }
        }   /* if InputWordBits=CHSET_BIT_WORD_8 */
    }       /* If mapping table exist */
    return 0;
}

#endif /* __MMI_CHSET_ALPHABET_SUPPORT__ */ 


#ifdef __MMI_CHSET_EUCKR_WIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_chset_encode_decode_algo3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Scheme          [IN]        
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  dest_size       [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 mmi_chset_encode_decode_algo3(
                    mmi_chset_pair_enum Scheme,
                    char *pOutBuffer,
                    char *pInBuffer,
                    kal_int32 dest_size,
                    kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 UndefChar = 0;
    kal_int32 count = 0, temp_count = 0;
    kal_int32 SearchedValueIndex = -1;
    kal_uint8 InputWordBits, OutputWordBits;
    kal_uint16 index;
    const Mapping_Struct *pMappingTable = 0;
    const kal_uint16 *pConversnTable = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pConversnTable = g_chset_tbl[Scheme].pConversnTable;
    pMappingTable = g_chset_tbl[Scheme].pMappingTable;
    InputWordBits = g_chset_tbl[Scheme].Input_word_bits;
    OutputWordBits = g_chset_tbl[Scheme].Output_word_bits;
    UndefChar = g_chset_tbl[Scheme].UndefChar;

    if (Scheme == EUCKR_WINDOWS_TO_UCS2)
    {
        if (pConversnTable != 0 && pMappingTable != 0)  /* If mapping table exist */
        {
            for (count = 0;
                 (count < dest_size - 2) && (pInBuffer[count - temp_count] != 0 ||
                                             pInBuffer[count - temp_count + 1] != 0); count = count + 2)
            {
                kal_uint16 TempChar;

                if (pInBuffer[count - temp_count] < 0xA1)
                {
                    pOutBuffer[count] = pInBuffer[count - temp_count];
                    pOutBuffer[count + 1] = 0;
                    temp_count++;
                    continue;
                }

                TempChar = (kal_uint8) pInBuffer[count - temp_count + 1];
                TempChar <<= 8;
                TempChar |= (kal_uint8) (pInBuffer[count - temp_count]);

                if (TempChar < (pMappingTable[0].start_value))
                {
                    SearchedValueIndex = -1;
                }
                else
                {
                    SearchedValueIndex = BinarySearchForEncodings(TempChar, Scheme);
                }

                if (SearchedValueIndex >= 0)
                {
                    index = TempChar - pMappingTable[(kal_uint16) SearchedValueIndex].start_value;
                    index = pMappingTable[(kal_uint16) SearchedValueIndex].index + index;

                    pOutBuffer[count] = (kal_uint8) pConversnTable[index];
                    pOutBuffer[count + 1] = (kal_uint8) (pConversnTable[index] >> 8);
                }
                else
                {
                    /* can't encoding the character. */
                    if (pInBuffer[count - temp_count + 2] == 0 && pInBuffer[count - temp_count + 3] == 0)
                    {
                        /* The data may be segmented at the end of pInBuffer[]. */
                        break;
                    }

                    pOutBuffer[count] = (kal_uint8) pInBuffer[count - temp_count + 1];  /* (kal_uint8)UndefChar; */
                    pOutBuffer[count + 1] = (kal_uint8) (pInBuffer[count - temp_count]);        /* (kal_uint8)(UndefChar>>8); */
                }
            }
            *src_end_pos = (kal_uint32) (pInBuffer + count);
            pOutBuffer[count] = 0;
            pOutBuffer[++count] = 0;
            return count + 1;
        }
    }
    else
    {
        temp_count = 0;
        if (pConversnTable != 0 && pMappingTable != 0)  /* If mapping table exist */
        {
            for (count = 0; pInBuffer[count] != 0 || pInBuffer[count + 1] != 0; count = count + 2)
            {
                kal_uint16 TempChar;

                /* check for maximum output bufer size */
                if (temp_count >= dest_size - 2)
                {
                    temp_count = (kal_uint16) dest_size - 2;
                    break;
                }

                TempChar = (kal_uint8) pInBuffer[count + 1];
                TempChar <<= 8;
                TempChar |= (kal_uint8) (pInBuffer[count]);

                if (TempChar < 0xA1)
                {
                    pOutBuffer[temp_count] = TempChar;
                    temp_count++;
                    continue;
                }

                if (TempChar < (pMappingTable[0].start_value))
                {
                    SearchedValueIndex = -1;
                }
                else
                {
                    SearchedValueIndex = BinarySearchForEncodings(TempChar, Scheme);
                }

                if (SearchedValueIndex >= 0)
                {
                    index = TempChar - pMappingTable[(kal_uint16) SearchedValueIndex].start_value;
                    index = pMappingTable[(kal_uint16) SearchedValueIndex].index + index;

                    pOutBuffer[temp_count] = (kal_uint8) pConversnTable[index];
                    pOutBuffer[temp_count + 1] = (kal_uint8) (pConversnTable[index] >> 8);
                }
                else
                {
                    /* can't encoding the character. */
                    if (pInBuffer[count + 2] == 0 && pInBuffer[count + 3] == 0)
                    {
                        /* The data may be segmented at the end of pInBuffer[]. */
                        break;
                    }

                    pOutBuffer[temp_count] = (kal_uint8) UndefChar;
                    pOutBuffer[temp_count + 1] = (kal_uint8) (UndefChar >> 8);
                }
                temp_count += 2;
            }
            *src_end_pos = (kal_uint32) (pInBuffer + count);

            pOutBuffer[temp_count] = 0;
            pOutBuffer[++temp_count] = 0;
            return temp_count + 1;
        }
    }
    return 0;
}

#endif /* __MMI_CHSET_EUCKR_WIN__ */ 


/*****************************************************************************
 * FUNCTION
 *  EncodingDecoding
 * DESCRIPTION
 *  This function encodes the input string to desired encoding type.
 * PARAMETERS
 *  Scheme          [IN]        
 *  pOutBuffer      [OUT]       
 *  pInBuffer       [IN]        
 *  dest_size       [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  number of bytes in output string
 *****************************************************************************/
kal_uint16 EncodingDecoding(
            mmi_chset_pair_enum Scheme,
            char *pOutBuffer,
            char *pInBuffer,
            kal_int32 dest_size,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Scheme == UTF8_TO_UCS2)
    {
        return (kal_uint16) mmi_chset_utf8_to_ucs2_string_ex(
                                (kal_uint8*) pOutBuffer,
                                dest_size,
                                (kal_uint8*) pInBuffer,
                                src_end_pos);
    }
    else if (Scheme == UCS2_TO_UTF8)
    {
        return (kal_uint16) mmi_chset_ucs2_to_utf8_string_ex(
                                (kal_uint8*) pOutBuffer,
                                dest_size,
                                (kal_uint8*) pInBuffer,
                                src_end_pos);
    }
#ifdef __MMI_CHSET_BIG5__
    else if (BIG5_TO_UCS2 <= Scheme && Scheme <= UCS2_TO_BIG5)  /* Patch added to use different algorithm for chinese encodings */
    {
        return mmi_chset_encode_decode_algo2(Scheme, pOutBuffer, pInBuffer, dest_size, src_end_pos);    /* Length is hardcode for now to maximum */
    }
#endif /* __MMI_CHSET_BIG5__ */ 
#ifdef __MMI_CHSET_GB2312__
    else if (GB2312_TO_UCS2 <= Scheme && Scheme <= UCS2_TO_GB2312)      /* Patch added to use different algorithm for chinese encodings */
    {
        return mmi_chset_encode_decode_algo2(Scheme, pOutBuffer, pInBuffer, dest_size, src_end_pos);    /* Length is hardcode for now to maximum */
    }
#endif /* __MMI_CHSET_GB2312__ */ 

#ifdef __MMI_CHSET_EUCKR_WIN__
    else if (Scheme == EUCKR_WINDOWS_TO_UCS2)
    {
        return mmi_chset_encode_decode_algo3(Scheme, pOutBuffer, pInBuffer, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_EUCKR_WIN__ */ 
#ifdef __MMI_CHSET_EUCKR_WIN__
    else if (Scheme == UCS2_TO_EUCKR_WINDOWS)
    {
        return mmi_chset_encode_decode_algo3(Scheme, pOutBuffer, pInBuffer, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_EUCKR_WIN__ */ 

#ifdef __MMI_CHSET_ALPHABET_SUPPORT__
    else    /* For all of the rest encodings. */
    {
        return mmi_chset_encode_decode(Scheme, pOutBuffer, pInBuffer, dest_size, src_end_pos);
    }
#else /* __MMI_CHSET_ALPHABET_SUPPORT__ */ 
    else
    {
        return 0;
    }
#endif /* __MMI_CHSET_ALPHABET_SUPPORT__ */ 
}

#define MMI_UTF8
#ifdef MMI_CHSET_UTF8_ALLOW_BOM


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_is_utf8_BOM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static __inline kal_bool mmi_chset_is_utf8_BOM(const kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str[0] == 0xEF && str[1] == 0xBB && str[2] == 0xBF)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}
#endif /* MMI_CHSET_UTF8_ALLOW_BOM */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf8_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static __inline int mmi_chset_ucs2_to_utf8_len(kal_uint16 ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2 < (kal_uint16) 0x80)
    {
        return 1;
    }
    else if (ucs2 < (kal_uint16) 0x800)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf8_strlen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_utf8_strlen(const kal_uint8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count = 0;
    int rawlen;
    int d;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s == NULL)
    {
        MMI_CHSET_DBG_ASSERT(0);
        return 0;
    }

    rawlen = strlen((const char*)s);

#ifdef MMI_CHSET_UTF8_ALLOW_BOM
    if (rawlen >= 3 && mmi_chset_is_utf8_BOM(s))
    {
        s += 3;
        rawlen -= 3;
    }
#endif /* MMI_CHSET_UTF8_ALLOW_BOM */ 

    while (*s != '\0' && rawlen > 0)
    {
        d = g_cheset_utf8_bytes_per_char[*s >> 4];
        if (d == 0)
        {
        #ifdef MMI_CHSET_UTF8_FAULT_TOLERANT
            /* skip this character */
            rawlen--;
            s++;
            continue;
        #else /* MMI_CHSET_UTF8_FAULT_TOLERANT */ 
            MMI_CHSET_DBG_ASSERT(0);
            return count;
        #endif /* MMI_CHSET_UTF8_FAULT_TOLERANT */ 
        }
        if (d > rawlen)
        {
            return count;
        }

        rawlen -= d;
        s += d;

        count++;
    }

    MMI_CHSET_DBG_ASSERT(rawlen == 0);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf8_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [OUT]       
 *  utf8        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_utf8_to_ucs2(kal_uint8 *dest, kal_uint8 *utf8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 c = utf8[0];
    int count = g_cheset_utf8_bytes_per_char[c >> 4];
    kal_uint16 ucs2 = 0xFFFF;   /* invalid character */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (count)
    {
        case 1:
            ucs2 = (kal_uint16) c;
            break;
        case 2:
            if (utf8[1])
            {
                ucs2 = ((kal_uint16) (c & 0x1f) << 6) | (kal_uint16) (utf8[1] ^ 0x80);
            }
            break;
        case 3:
            if (utf8[1] && utf8[2])
            {
                ucs2 = ((kal_uint16) (c & 0x0f) << 12)
                    | ((kal_uint16) (utf8[1] ^ 0x80) << 6) | (kal_uint16) (utf8[2] ^ 0x80);
            }
            break;
        case 4:
            break;
        default:
            count = 1;   /* the character cannot be converted, return 1 means always consume 1 byte */
            break;
    }

    SET_CHR_AT(dest, 0, ucs2);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  utf8        [OUT]       
 *  ucs2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_ucs2_to_utf8(kal_uint8 *utf8, kal_uint16 ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2 < (kal_uint16) 0x80)
    {
        count = 1;
    }
    else if (ucs2 < (kal_uint16) 0x800)
    {
        count = 2;
    }
    else
    {
        count = 3;
    }
    switch (count)
    {
        case 3:
            utf8[2] = 0x80 | (ucs2 & 0x3f);
            ucs2 = ucs2 >> 6;
            ucs2 |= 0x800;
        case 2:
            utf8[1] = 0x80 | (ucs2 & 0x3f);
            ucs2 = ucs2 >> 6;
            ucs2 |= 0xc0;
        case 1:
            utf8[0] = (kal_uint8) ucs2;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf8_to_ucs2_string_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_utf8_to_ucs2_string_ex(
            kal_uint8 *dest,
            kal_int32 dest_size,
            kal_uint8 *src,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos = 0;
    int cnt;
    int src_len = strlen((const char*)src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_CHSET_UTF8_ALLOW_BOM
    if (src_len >= 3 && mmi_chset_is_utf8_BOM(src))
    {
        src += 3;
    }
#endif /* MMI_CHSET_UTF8_ALLOW_BOM */ 

    MMI_CHSET_DBG_ASSERT((dest_size % 2) == 0);
    dest_size -= (dest_size % 2);
    *src_end_pos = (kal_uint32) src; /* set src_end_pos first */

    if (dest_size < 2)
    {
        MMI_CHSET_DBG_ASSERT(0);    /* dest wont be NULL-terminated */
        return 0;
    }

    while (*src && pos < dest_size - 2)
    {
        cnt = mmi_chset_utf8_to_ucs2(dest + pos, src);
         if (((kal_uint32)src - (*src_end_pos)) > (src_len - cnt) &&
             (*(dest + pos) == 0xFF && *(dest + pos + 1) == 0xFF) &&
            !(*src == 0xEF && *(src+1) == 0xBF && *(src+2) == 0xBF))
        {
            /* 
             * If src isn't 0xEF, 0xBF, 0xBF and its remain length is not enough but dest is 0xFFFF, we will abort the process.
             * dest data is invalid character because src data is not enough to convert 
             */
            break;
        }
        if (cnt == 0)   /* abnormal case */
        {
        #ifdef MMI_CHSET_UTF8_FAULT_TOLERANT
            src++;
        #else 
            break;
        #endif 
        }
        else    /* normal case */
        {
            src += cnt;
            pos += 2;
        }
    }
    *src_end_pos = (kal_uint32) src;
    dest[pos] = 0;
    dest[pos + 1] = 0;
    return pos + 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf8_to_ucs2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32) src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_utf8_to_ucs2_string_ex(dest, dest_size, src, &src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf8_string_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 *  src_end_pos     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_ucs2_to_utf8_string_ex(
            kal_uint8 *dest,
            kal_int32 dest_size,
            kal_uint8 *src,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (src[0] || src[1])
    {
        if (pos + mmi_chset_ucs2_to_utf8_len(CHR_AT(src, 0)) >= dest_size)      /* leave space of '\0' */
        {
            MMI_CHSET_DBG_ASSERT(0);
            break;
        }

        pos += mmi_chset_ucs2_to_utf8(dest + pos, CHR_AT(src, 0));
        src += 2;
        if (pos >= dest_size - 1)
        {
            break;
        }
    }
    if (pos >= dest_size)
    {
        MMI_CHSET_DBG_ASSERT(0);
        dest[dest_size - 1] = 0;
    }
    else
    {
        dest[pos] = 0;
    }
    *src_end_pos = (kal_uint32) src;
    return pos + 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf8_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]       
 *  dest_size       [IN]        
 *  src             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32) src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_ucs2_to_utf8_string_ex(dest, dest_size, src, &src_end_pos);
}

/* Not including zero character '\0' */


/*****************************************************************************
 * FUNCTION
 *  mmi_charset_ucs2_to_utf8_length_in_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  raw     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw)
{
#if 1
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len = (kal_dchar_strlen((const char*)raw)) / 2;
#else /* 1 */ 
/* under construction !*/
#endif /* 1 */ 
    int utf8_len = 0;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        utf8_len += mmi_chset_ucs2_to_utf8_len(CHR_AT(raw, i));
    }

    return utf8_len;
}

/* Not including zero character "\0\0" */


/*****************************************************************************
 * FUNCTION
 *  mmi_charset_utf8_to_ucs2_length_in_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  raw     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return STR_SIZE(mmi_chset_utf8_strlen(raw));
}

#ifdef __MMI_CHSET_UTF7__
/* Globals Used */
#define BASE64_MAXINDEX 64
static const char base64_data[BASE64_MAXINDEX] = 
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};


/*****************************************************************************
 * FUNCTION
 *  direct_chars_ucs2_to_utf
 * DESCRIPTION
 *  checks wheather the input unicode character
 *  is a direct pass away character in terms of UTF-7.
 * PARAMETERS
 *  number      [IN]        
 * RETURNS
 *  1 or 0 -- 1 for yes and 0 for no
 *****************************************************************************/
unsigned short direct_chars_ucs2_to_utf(unsigned short number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number > 127)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_char_index_in_base64array
 * DESCRIPTION
 *  returns an index corresponding to the input
 *  value from Base64 Array
 * PARAMETERS
 *  char_to_search      [IN]        
 * RETURNS
 *  a short value i.e the index corresponding
 *  to the input value
 *****************************************************************************/
short get_char_index_in_base64array(char char_to_search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (char_to_search == '+')
    {
        return 62;
    }
    else if (char_to_search == '/')
    {
        return 63;
    }
    else if (char_to_search >= '0' && char_to_search <= '9')
    {
        return 52 + (char_to_search - '0');
    }
    else if (char_to_search >= 'a' && char_to_search <= 'z')
    {
        return 26 + (char_to_search - 'a');
    }
    else if (char_to_search >= 'A' && char_to_search <= 'Z')
    {
        return char_to_search - 'A';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_utf_ucs2_chars
 * DESCRIPTION
 *  Convert a buffer between 2 character sets.
 * PARAMETERS
 *  output_chars            [OUT]           Output buffer
 *  current_input_chars     [IN/OUT]        
 *  prev_input_char         [IN]            Previous encoded character
 *  combination_no          [IN]            Consecutive combination of three or may be two chars
 *  output_len              [IN]            Length of output string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_utf_ucs2_chars(
        char *output_chars,
        char *current_input_chars,
        char prev_input_char,
        int combination_no,
        int *output_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short final_char = 0, index = 0, ctr = 0;
    char temp_char, prev_bits, current_bits, prev_char = get_char_index_in_base64array(prev_input_char);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (ctr = 0; ctr < 3; ctr++)
    {
        if (current_input_chars[ctr] == 0)
        {
            current_input_chars[ctr] = 'A';
        }

        index = get_char_index_in_base64array(current_input_chars[ctr]);

        /*
         * Every UTF7 char would be transfered to 6 bits according "Modified Base 64"
         * Every Unicode is 16 bits (2 bytes)
         * Three UTF7 chars will encode one Unicode in worst case.
         * There are three cases:
         * Case 1: (No previous char)
         *     Need 3 UTF7 chars encode 1 Unicode, and remain 2 bits
         *     - combination_no: 0
         * Case 2: (Previous char remains 2 bits, and still need 3 UTF7 chars)
         *     Need more 3 UTF7 chars to encode 1 Unicode, and remain 4 bits
         *     - combination_no: 1
         * Case 3: (Previous char remains 4 bits, and only need 2 UTF7 chars)
         *     Need more 2 UTF7 chars to encode 1 Unicode. (no remained bits)
         *     - combination_no: 2
         */
        switch (combination_no)
        {
            case 0:
                final_char = final_char | ((unsigned short)(index << 10) >> (6 * ctr));
                break;
            case 1:
                prev_bits = prev_char & 0x03;
                current_bits = (index & 0x3C) >> 2;
                temp_char = (prev_bits << 4) | current_bits;
                final_char = final_char | ((unsigned short)(temp_char << 10) >> (6 * ctr));
                prev_char = index;
                break;
            case 2:
                prev_bits = prev_char & 0x0F;
                current_bits = (index & 0x30) >> 4;
                temp_char = (prev_bits << 2) | current_bits;
                final_char = final_char | ((unsigned short)(temp_char << 10) >> (6 * ctr));
                prev_char = index;
                break;
        }
    }

    memcpy(output_chars + (*output_len), &final_char, sizeof(short));
    *output_len += 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf7_to_ucs2_str
 * DESCRIPTION
 *  decodes UTF7 Buffer to MMI UCS Buffer for after recieving a mail.
 *  refer RFC 2152 to get UTF7 format
 * PARAMETERS
 *  g_unicode_decoded_buf       [OUT]       Decoded Data
 *  g_encoded_buf               [IN]        This is UTF7 encoded buffer to be converted
 *  data_size                   [IN]        Size of destination buffer (bytes)
 * RETURNS
 *  length of decoded buffer
 *****************************************************************************/
int mmi_chset_utf7_to_ucs2_str(char *g_unicode_decoded_buf, char *g_encoded_buf, int data_size, kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ctr = 0, output_len = 0, temp_ctr = 0, no_decoded_combinations = 0;
    char current_encoded_buf[3] = {0}, prev_last_char = 0, ch;
    int g_plus_indicator_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_encoded_buf[ctr] != 0 && output_len < data_size - 2)
    {
        ch = g_encoded_buf[ctr];
        /*
         * When the char is '+', begin to decode UTF7 according "Modified Base 64" (REC 2045).
         * When the char is '-', end of decoding UTF7 according "Modified Base 64".
         */
        if ((ch != '+') && (g_plus_indicator_flag == 0))
        {
            /* the octet value should be less than 0x7F */
            g_unicode_decoded_buf[output_len++] = ch;
            g_unicode_decoded_buf[output_len++] = 0;
        }
        else
        {
            char temp_buff = 0; /* For taking care for the unicode + character */

            if ((ch != '-') && (g_plus_indicator_flag == 1))
            {
                current_encoded_buf[temp_ctr++] = ch;
            }

            if ((temp_ctr == 3 && no_decoded_combinations != 2) || (temp_ctr == 2 && no_decoded_combinations == 2))
            {
                /*
                 * Every UTF7 char would be transfered to 6 bits according "Modified Base 64"
                 * Every Unicode is 16 bits (2 bytes)
                 * Three UTF7 chars will encode one Unicode in worst case.
                 * There are three cases:
                 * Case 1: (No previous char)
                 *     Need 3 UTF7 chars encode 1 Unicode, and remain 2 bits
                 *     - no_decoded_combinations: 0
                 * Case 2: (Previous char remains 2 bits, and still need 3 UTF7 chars)
                 *     Need more 3 UTF7 chars to encode 1 Unicode, and remain 4 bits
                 *     - no_decoded_combinations: 1
                 * Case 3: (Previous char remains 4 bits, and only need 2 UTF7 chars)
                 *     Need more 2 UTF7 chars to encode 1 Unicode. (no remained bits)
                 *     - no_decoded_combinations: 2
                 */
                mmi_utf_ucs2_chars(
                    g_unicode_decoded_buf,
                    current_encoded_buf,
                    prev_last_char,
                    no_decoded_combinations,
                    &output_len);
                no_decoded_combinations++;
                prev_last_char = (no_decoded_combinations) ? current_encoded_buf[2] : NULL;
                if (no_decoded_combinations == 3)
                {
                    no_decoded_combinations = 0;
                }
                current_encoded_buf[0] = 0;
                current_encoded_buf[1] = 0;
                current_encoded_buf[2] = 0;
                temp_ctr = 0;
            }

            g_plus_indicator_flag = 1;

            if ((ch == '-') && (temp_ctr != 0))
            {
                mmi_utf_ucs2_chars(
                    g_unicode_decoded_buf,
                    current_encoded_buf,
                    prev_last_char,
                    no_decoded_combinations % 3,
                    &output_len);
                /* handle this condition in decoder where chars less then 3 */
                current_encoded_buf[0] = 0;
                current_encoded_buf[1] = 0;
                current_encoded_buf[2] = 0;

                prev_last_char = 0;
                no_decoded_combinations = 0;
                g_plus_indicator_flag = 0;
                temp_ctr = 0;
            }
            else if ((ch == '-') && (temp_ctr == 0))
            {
                current_encoded_buf[0] = 0;
                current_encoded_buf[1] = 0;
                current_encoded_buf[2] = 0;

                prev_last_char = 0;
                no_decoded_combinations = 0;
                g_plus_indicator_flag = 0;
                temp_ctr = 0;
            }
            temp_buff = g_encoded_buf[ctr + 1];
            if (ch == '+' && temp_buff == '-')  /* Fot taking care for the unicode '+' character */
            {
                g_unicode_decoded_buf[output_len++] = ch;
                g_unicode_decoded_buf[output_len++] = 0;
            }
        }
        ctr++;
    }

    *src_end_pos = (kal_uint32)(&g_encoded_buf[ctr]);

    g_unicode_decoded_buf[output_len] = 0;
    g_unicode_decoded_buf[output_len + 1] = 0;
    return (2 * (output_len + 1));;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2_utf_chars
 * DESCRIPTION
 *  this function encodes a particular special symbol from MMI Buffer to UTF7 Data.
 * PARAMETERS
 *  output_chars        [OUT]       Encoded equivalant
 *  output_len          [OUT]       Length of the output string
 *  current_char        [IN]        Current character
 *  prev_char           [IN]        Previous character
 *  no_of_chars         [IN]        Number of consecutive special chars
 *  encode_flag         [IN]        
 *  data_size           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucs2_utf_chars(
        char *output_chars,
        int *output_len,
        unsigned short current_char,
        unsigned short prev_char,
        int no_of_chars,
        int encode_flag,
        int data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (encode_flag)
    {
        /*
         * Encode UTF7 chars from Unicode
         * Every Unicode is 16 bits (2 bytes)
         * Every UTF7 char would be transfered from 6 bits according "Modified Base 64"
         * One Unicode will encode three UTF7 chars in worst case (lacked bits will be 0).
         * There are three cases:
         * Case 1: (No previous Unicode)
         *     1 Unicode encodes 2 UTF7 chars, and remains 4 bits
         *     - no_of_chars: 0
         * Case 2: (Previous Unicode remains 4 bits)
         *     Previous Unicode(4 bits) and 1 Unicode encode 3 UTF7 chars, and remain 2 bits
         *     - no_of_chars: 1
         * Case 3: (Previous Unicode remains 2 bits)
         *     Previous Unicode(2 bits) and 1 Unicode encode 3 UTF7 chars, and no remained bits
         *     - no_of_chars: 2
         */
        switch (no_of_chars)
        {
            case 0:
                if (*output_len < data_size - 1)
                {
                    output_chars[(*output_len)++] = base64_data[(current_char & 0xFC00) >> 10];
                    output_chars[(*output_len)++] = base64_data[(current_char & 0x03F0) >> 4];
                }
                break;
            case 1:
                if (*output_len < data_size - 2)
                {
                    output_chars[(*output_len)++] =
                        base64_data[((prev_char & 0x000F) << 2) | ((current_char & 0xC000) >> 14)];
                    output_chars[(*output_len)++] = base64_data[(current_char & 0x3F00) >> 8];
                    output_chars[(*output_len)++] = base64_data[(current_char & 0x00FC) >> 2];
                }
                break;
            case 2:
                if (*output_len < data_size - 2)
                {
                    output_chars[(*output_len)++] =
                        base64_data[((prev_char & 0x0003) << 4) | ((current_char & 0xF000) >> 12)];
                    output_chars[(*output_len)++] = base64_data[(current_char & 0x0FC0) >> 6];
                    output_chars[(*output_len)++] = base64_data[(current_char & 0x003F)];
                }
                break;
        }
    }
    else
    {
        /*
         * Encode UTF7 chars with padding 0 bits
         * Every Unicode is 16 bits (2 bytes)
         * Every UTF7 char would be transfered from 6 bits according "Modified Base 64"
         * One Unicode will encode three UTF7 chars in worst case (lacked bits will be 0).
         * There are three cases:
         * Case 1: (Previous Unicode remains 4 bits)
         *     Previous Unicode(4 bits) encodes UTF7 chars with 2 padding bits(0).
         *     - no_of_chars: 1
         * Case 2: (Previous Unicode remains 2 bits)
         *     Previous Unicode(2 bits) encodes UTF7 chars with 4 padding bits(0).
         *     - no_of_chars: 2
         */
        switch (no_of_chars)
        {
            case 1:
                if (*output_len < data_size)
                {
                    output_chars[(*output_len)++] = base64_data[((prev_char & 0x000F) << 2)];
                }
                break;
            case 2:
                if (*output_len < data_size)
                {
                    output_chars[(*output_len)++] = base64_data[((prev_char & 0x0003) << 4)];
                }
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf7_str
 * DESCRIPTION
 *  Encodes the MMI UCS Buffer to UTF7 Buffer for sending a mail
 * PARAMETERS
 *  g_encoded_buf       [OUT]       Encoded Data
 *  g_data_buf          [IN]        MMI Editor Data
 *  data_size           [IN]        
 * RETURNS
 *  Nothing
 *****************************************************************************/
int mmi_chset_ucs2_to_utf7_str(char *g_encoded_buf, char *g_data_buf, int data_size, kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char ucs2_data_buf[7] = {0}, temp_char[3];
    unsigned short *current_char, prev_char = 0;
    int output_len = 0, ucs2_chars_count = 0, len = 0, ctr = 0, encode_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_size -= 2;
    prev_char = 0;

    while (!(g_data_buf[ctr] == NULL && g_data_buf[ctr + 1] == NULL))   /* ctr < len * 2 ) */
    {
        temp_char[0] = g_data_buf[ctr];
        temp_char[1] = g_data_buf[ctr + 1];
        temp_char[2] = 0;

        current_char = (unsigned short*)temp_char;

        if (temp_char[0] == '+')
        {
            if (encode_flag == 1)
            {
                encode_flag = 0;
                if (ucs2_chars_count)
                {
                    mmi_ucs2_utf_chars(
                        g_encoded_buf,
                        &output_len,
                        *current_char,
                        prev_char,
                        ucs2_chars_count,
                        encode_flag,
                        data_size);
                }
                g_encoded_buf[output_len++] = '-';
            }

            if (output_len < data_size - 1)
            {
                g_encoded_buf[output_len++] = '+';
                g_encoded_buf[output_len++] = '-';
            }
            else
            {
                break;
            }
            ucs2_chars_count = 0;
        }
        else if (direct_chars_ucs2_to_utf(*current_char))
        {
            /*
             * If Unicode value is less than 0x7F, 
             * leaving "Modified Base 64" encoding and encode char directly.
             */
            if (encode_flag == 1)
            {
                encode_flag = 0;
                if (ucs2_chars_count)
                {
                    mmi_ucs2_utf_chars(
                        g_encoded_buf,
                        &output_len,
                        *current_char,
                        prev_char,
                        ucs2_chars_count,
                        encode_flag,
                        data_size);
                }
                g_encoded_buf[output_len++] = '-';
            }
            if (output_len < data_size)
            {
                g_encoded_buf[output_len++] = (char)(*current_char);
            }
            else
            {
                break;
            }

            ucs2_chars_count = 0;
        }
        else
        {
            /*
             * If Unicode value is larger than 0x7F, 
             * entering "Modified Base 64" encoding.
             */
            if (encode_flag == 0)
            {
                g_encoded_buf[output_len++] = '+';
                encode_flag = 1;
            }

            /*
             * Encode UTF7 chars from Unicode
             * Every Unicode is 16 bits (2 bytes)
             * Every UTF7 char would be transfered from 6 bits according "Modified Base 64"
             * One Unicode will encode three UTF7 chars in worst case (padding bits in 0).
             * There are three cases:
             * Case 1: (No previous Unicode)
             *     1 Unicode encodes 2 UTF7 chars, and remains 4 bits
             *     - ucs2_chars_count: 0
             * Case 2: (Previous Unicode remains 4 bits)
             *     Previous Unicode(4 bits) and 1 Unicode encode 3 UTF7 chars, and remain 2 bits
             *     - ucs2_chars_count: 1
             * Case 3: (Previous Unicode remains 2 bits)
             *     Previous Unicode(2 bits) and 1 Unicode encode 3 UTF7 chars, and no remained bits
             *     - ucs2_chars_count: 2
             */
            mmi_ucs2_utf_chars(
                g_encoded_buf,
                &output_len,
                *current_char,
                prev_char,
                ucs2_chars_count,
                encode_flag,
                data_size);
            ucs2_chars_count++;
            if (ucs2_chars_count == 3)
            {
                ucs2_chars_count = 0;
            }
        }
        ctr += 2;
        prev_char = *current_char;
    }

    *src_end_pos = (kal_uint32)(&g_data_buf[ctr]);

    g_encoded_buf[output_len] = 0;
    return output_len + 1;
}

#endif /* __MMI_CHSET_UTF7__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_convert_ex
 * DESCRIPTION
 *  Convert string between 2 character sets. (will add the terminate character)
 * PARAMETERS
 *  src_type        [IN]        Charset type of source
 *  dest_type       [IN]        Charset type of destination
 *  src_buff        [IN]        Buffer stores source string
 *  dest_buff       [OUT]       Buffer stores destination string
 *  dest_size       [IN]        Size of destination buffer (bytes)
 *  src_end_pos     [OUT]       
 * RETURNS
 *  Length of destination string, including null terminator. (bytes)
 *****************************************************************************/
kal_int32 mmi_chset_convert_ex(
            mmi_chset_enum src_type,
            mmi_chset_enum dest_type,
            char *src_buff,
            char *dest_buff,
            kal_int32 dest_size,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* unsupported charset */
    *src_end_pos = (kal_uint32) src_buff;

    if (src_type >= MMI_CHSET_TOTAL || dest_type >= MMI_CHSET_TOTAL)
    {
        return 0;
    }

    if (g_chset_state[src_type] == 0)
    {
        return 0;
    }

    if (g_chset_state[dest_type] == 0)
    {
        return 0;
    }

    if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_UTF8)
    {
        return EncodingDecoding(UCS2_TO_UTF8, dest_buff, src_buff, dest_size, src_end_pos);
    }
    else if (src_type == MMI_CHSET_UTF8 && dest_type == MMI_CHSET_UCS2)
    {
        return EncodingDecoding(UTF8_TO_UCS2, dest_buff, src_buff, dest_size, src_end_pos);
    }
    /* UTF-16 */
    else if (src_type == MMI_CHSET_UTF16LE && dest_type == MMI_CHSET_UCS2)
    {
        return mmi_chset_utf16_to_ucs2_string(
                (kal_int8*) dest_buff,
                dest_size,
                (kal_int8*) src_buff,
                MMI_CHSET_UTF16LE,
                src_end_pos);
    }
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_UTF16LE)
    {
        return mmi_chset_ucs2_to_utf16_string(
                (kal_int8*) dest_buff,
                dest_size,
                MMI_CHSET_UTF16LE,
                KAL_FALSE,
                (kal_int8*) src_buff,
                src_end_pos);
    }
    else if (src_type == MMI_CHSET_UTF16BE && dest_type == MMI_CHSET_UCS2)
    {
        return mmi_chset_utf16_to_ucs2_string(
                (kal_int8*) dest_buff,
                dest_size,
                (kal_int8*) src_buff,
                MMI_CHSET_UTF16BE,
                src_end_pos);
    }
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_UTF16BE)
    {
        return mmi_chset_ucs2_to_utf16_string(
                (kal_int8*) dest_buff,
                dest_size,
                MMI_CHSET_UTF16BE,
                KAL_FALSE,
                (kal_int8*) src_buff,
                src_end_pos);
    }
#ifdef __MMI_CHSET_UTF7__
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_UTF7)
    {
        return mmi_chset_ucs2_to_utf7_str(dest_buff, src_buff, dest_size, src_end_pos);
    }

    else if (src_type == MMI_CHSET_UTF7 && dest_type == MMI_CHSET_UCS2)
    {
        return mmi_chset_utf7_to_ucs2_str(dest_buff, src_buff, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_UTF7__ */ 
#ifdef __MMI_CHSET_EUCKR_WIN__
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_EUCKR)
    {
        return EncodingDecoding(UCS2_TO_EUCKR_WINDOWS, dest_buff, src_buff, dest_size, src_end_pos);
    }

    else if (src_type == MMI_CHSET_EUCKR && dest_type == MMI_CHSET_UCS2)
    {
        return EncodingDecoding(EUCKR_WINDOWS_TO_UCS2, dest_buff, src_buff, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_EUCKR_WIN__ */ 
#ifdef __MMI_CHSET_THAI_WINDOWS__
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_THAI_WIN)
    {
        return EncodingDecoding(UCS2_TO_THAI_WINDOWS, dest_buff, src_buff, dest_size, src_end_pos);
    }

    else if (src_type == MMI_CHSET_THAI_WIN && dest_type == MMI_CHSET_UCS2)
    {
        return EncodingDecoding(THAI_WINDOWS_TO_UCS2, dest_buff, src_buff, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_THAI_WINDOWS__ */ 
#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_VIETNAMESE_WIN)
    {
        return EncodingDecoding(UCS2_TO_VIETNAMESE_WINDOWS, dest_buff, src_buff, dest_size, src_end_pos);
    }

    else if (src_type == MMI_CHSET_VIETNAMESE_WIN && dest_type == MMI_CHSET_UCS2)
    {
        return EncodingDecoding(VIETNAMESE_WINDOWS_TO_UCS2, dest_buff, src_buff, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_VIETNAMESE_WINDOWS__ */ 
#ifdef __MMI_CHSET_KOI8_R__
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_KOI8_R)
    {
        return EncodingDecoding(UCS2_TO_KOI8_R, dest_buff, src_buff, dest_size, src_end_pos);
    }
	
    else if (src_type == MMI_CHSET_KOI8_R && dest_type == MMI_CHSET_UCS2)
    {
        return EncodingDecoding(KOI8_R_TO_UCS2, dest_buff, src_buff, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_KOI8_R__ */

#ifdef __MMI_CHSET_GB18030__
    else if (src_type == MMI_CHSET_GB18030 && dest_type == MMI_CHSET_UCS2)
    {
        return mmi_chset_gb18030_to_ucs2_str(dest_buff, src_buff, dest_size, src_end_pos);
    }
    else if (src_type == MMI_CHSET_UCS2 && dest_type == MMI_CHSET_GB18030)
    {
        return mmi_chset_ucs2_to_gb18030_str(dest_buff, src_buff, dest_size, src_end_pos);
    }
#endif /* __MMI_CHSET_GB18030__ */ 
#if defined(__MMI_CHSET_ALPHABET_SUPPORT__) || defined(__MMI_CHSET_IDEOGRAM_SUPPORT__)
    else    /* intermedia conversion required */
    {
        if (src_type == MMI_CHSET_UCS2)
        {
            return EncodingDecoding(
                    (mmi_chset_pair_enum) (BASE_ENCODING_SCHEME + (dest_type - MMI_CHSET_BASE) * 2),
                    dest_buff,
                    src_buff,
                    dest_size,
                    src_end_pos);
        }
        else if (dest_type == MMI_CHSET_UCS2)
        {
            return EncodingDecoding(
                    (mmi_chset_pair_enum) (BASE_ENCODING_SCHEME + (src_type - MMI_CHSET_BASE) * 2 - 1),
                    dest_buff,
                    src_buff,
                    dest_size,
                    src_end_pos);
        }
        else
        {
            kal_uint16 result_len;

            char *tmp_buff = get_ctrl_buffer(CHSET_TMP_BUFF_SIZE);

            EncodingDecoding(
                (mmi_chset_pair_enum) (BASE_ENCODING_SCHEME + (src_type - MMI_CHSET_BASE) * 2 - 1),
                tmp_buff,
                src_buff,
                CHSET_TMP_BUFF_SIZE,
                src_end_pos);

            result_len = EncodingDecoding(
                            (mmi_chset_pair_enum) (BASE_ENCODING_SCHEME + (dest_type - MMI_CHSET_BASE) * 2),
                            dest_buff,
                            tmp_buff,
                            dest_size,
                            src_end_pos);

            free_ctrl_buffer(tmp_buff);
            return result_len;
        }
    }
#else /* defined(__MMI_CHSET_ALPHABET_SUPPORT__) || defined(__MMI_CHSET_IDEOGRAM_SUPPORT__) */ 
    return 0;
#endif /* defined(__MMI_CHSET_ALPHABET_SUPPORT__) || defined(__MMI_CHSET_IDEOGRAM_SUPPORT__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  chset_convert_ex
 * DESCRIPTION
 *  Convert string between 2 character sets. (will add the terminate character)
 * PARAMETERS
 *  src_type        [IN]        Charset type of source
 *  dest_type       [IN]        Charset type of destination
 *  src_buff        [IN]        Buffer stores source string
 *  dest_buff       [OUT]       Buffer stores destination string
 *  dest_size       [IN]        Size of destination buffer (bytes)
 *  src_end_pos     [OUT]       
 * RETURNS
 *  Length of destination string, including null terminator. (bytes)
 *****************************************************************************/
kal_int32 chset_convert_ex(
            chset_enum src_type,
            chset_enum dest_type,
            char *src_buff,
            char *dest_buff,
            kal_int32 dest_size,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_convert_ex(src_type, dest_type, src_buff, dest_buff, dest_size, src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_convert
 * DESCRIPTION
 *  Convert string between 2 character sets. (will add the terminate character)
 * PARAMETERS
 *  src_type        [IN]        Charset type of source
 *  dest_type       [IN]        Charset type of destination
 *  src_buff        [IN]        Buffer stores source string
 *  dest_buff       [OUT]       Buffer stores destination string
 *  dest_size       [IN]        Size of destination buffer (bytes)
 * RETURNS
 *  Length of destination string, including null terminator. (bytes)
 *****************************************************************************/
kal_int32 mmi_chset_convert(
            mmi_chset_enum src_type,
            mmi_chset_enum dest_type,
            char *src_buff,
            char *dest_buff,
            kal_int32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32) src_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_convert_ex(src_type, dest_type, src_buff, dest_buff, dest_size, &src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  chset_convert
 * DESCRIPTION
 *  Convert string between 2 character sets. (will add the terminate character)
 * PARAMETERS
 *  src_type        [IN]        Charset type of source
 *  dest_type       [IN]        Charset type of destination
 *  src_buff        [IN]        Buffer stores source string
 *  dest_buff       [OUT]       Buffer stores destination string
 *  dest_size       [IN]        Size of destination buffer (bytes)
 * RETURNS
 *  Length of destination string, including null terminator. (bytes)
 *****************************************************************************/
kal_int32 chset_convert(
            chset_enum src_type,
            chset_enum dest_type,
            char *src_buff,
            char *dest_buff,
            kal_int32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_convert(src_type, dest_type, src_buff, dest_buff, dest_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_charset_id
 * DESCRIPTION
 *  This function is used for get the charset id
 * PARAMETERS
 *  chset_name      [IN]        Charset name
 *  chset_id_p      [OUT]       Charset ID
 * RETURNS
 *  retrun KAL_TRUE if succeed, otherwise return KAL_FALSE
 *****************************************************************************/
kal_bool mmi_chset_get_charset_id(const kal_int8 *chset_name, mmi_chset_enum *chset_id_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL == chset_name) || (*chset_name == '\0'))
    {
        return KAL_FALSE;
    }

    j = sizeof(g_char_set_ref_tbl) / (sizeof(char_set_ref)) - 1;

    while (j)
    {
        for (i = 0; i < g_char_set_ref_tbl[j - 1].chset_name_count; i++)
        {
            if (0 == mmi_chset_stricmp((kal_char*) chset_name, (kal_char*) g_char_set_ref_tbl[j - 1].chset_name_array[i]))
            {
                *chset_id_p = g_char_set_ref_tbl[j - 1].chset_id;
                return KAL_TRUE;
            }
        }
        j--;
    }

    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  chset_get_charset_id
 * DESCRIPTION
 *  This function is used for get the charset id
 * PARAMETERS
 *  chset_name      [IN]        Charset name
 *  chset_id_p      [OUT]       Charset ID
 * RETURNS
 *  retrun KAL_TRUE if succeed, otherwise return KAL_FALSE
 *****************************************************************************/
kal_bool chset_get_charset_id(const kal_int8 *chset_name, chset_enum *chset_id_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_get_charset_id(chset_name, chset_id_p);
}


/*****************************************************************************
 * FUNCTION
 *  chset_get_preferred_mime_name
 * DESCRIPTION
 *  This function is used for get the preferred MIME name of character set via
 *  the character set id.
 * PARAMETERS
 *  chset_id        [IN]        Character set id.
 * RETURNS
 *  If successful, retrun the const pointer to the character set name,
 *  otherwise return NULL
 *****************************************************************************/
const kal_int8 *chset_get_preferred_mime_name(chset_enum chset_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    j = sizeof(g_char_set_ref_tbl) / (sizeof(char_set_ref)) - 1;

    while (j)
    {
        j--;
        if (g_char_set_ref_tbl[j].chset_id == chset_id)
        {
            return g_char_set_ref_tbl[j].chset_name_array[0];
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_stricmp
 * DESCRIPTION
 *  mmi_chset_stricmp perform a case-insensitive string comparision.
 * PARAMETERS
 *  dst     [IN]        Strings to compare
 *  src     [IN]        Strings to compare
 * RETURNS
 *  <0 if dst < src
 *  0 if dst = src
 *  >0 if dst > src
 *****************************************************************************/
static kal_int32 mmi_chset_stricmp(const kal_char *dst, const kal_char *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 f, l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if (((f = (kal_uint8) (*(dst++))) >= 'A') && (f <= 'Z'))
        {
            f -= ('A' - 'a');
        }

        if (((l = (kal_uint8) (*(src++))) >= 'A') && (l <= 'Z'))
        {
            l -= ('A' - 'a');
        }

    } while (f && (f == l));

    return (f - l);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_get_utf_byte_order
 * DESCRIPTION
 *  The function is used for get the byte order via the byte order mark .
 * PARAMETERS
 *  str_bom     [IN]        The byte order mark.
 * RETURNS
 *  returns MMI_CHSET_UTF16LE if the stream is little-endian
 *  returns MMI_CHSET_UTF16BE if the stream is big-endian
 *  returns MMI_CHSET_UTF8 if the input BOM is a UTF-8's BOM
 *  Otherwise returns -1
 *****************************************************************************/
kal_int8 mmi_chset_get_utf_byte_order(const kal_int8 *str_bom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar wc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wc = MERGE_TO_WCHAR(str_bom[0], str_bom[1]);

    switch (wc)
    {
        case 0xFFFE:
            return MMI_CHSET_UTF16LE;

        case 0xFEFF:
            return MMI_CHSET_UTF16BE;

        case 0xEFBB:
            if (0xBF == str_bom[2])
                return MMI_CHSET_UTF8;
            else
                return -1;

        default:
            return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf16_strlen
 * DESCRIPTION
 *  The function is used for gets the number of characters of the given UTF16
 *  encoded string, not including the beginning BOM and the final null
 *  character.
 *  Here we only accept FFFE/FEFF marks as endianness indicators in the
 *  beginning of the stream(See RFC 2781 section 3.2 specifies).
 *  If there is no BOM, the text default is interpreted as big-endian.
 *  The function does not count the surrogate pair. Because of it can't translate
 *  to UCS2.
 * PARAMETERS
 *  str_utf16       [IN]        UTF-16 encoded string which length is to be computed.
 *  utf16_type      [IN]        The type of input UTF-16 encoded string. MMI_CHSET_UTF16LE or MMI_CHSET_UTF16BE
 * RETURNS
 *  The number of characters of the input UTF16 encoded string.
 *****************************************************************************/
kal_int32 mmi_chset_utf16_strlen(const kal_int8 *str_utf16, mmi_chset_enum utf16_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 utf16_bo;
    kal_int32 count = 0;
    kal_wchar wc1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(str_utf16);
    ASSERT((MMI_CHSET_UTF16BE == utf16_type) || (MMI_CHSET_UTF16LE == utf16_type));

    utf16_bo = mmi_chset_get_utf_byte_order(str_utf16);

    if (-1 != utf16_bo)
    {
        str_utf16 += 2;
        /* Don't count the beginning BOM */
    }
    else
    {
        utf16_bo = utf16_type;
    }

    while (str_utf16[0] || str_utf16[1])
    {
        wc1 = ((utf16_bo == MMI_CHSET_UTF16BE) ?
               MERGE_TO_WCHAR(str_utf16[0], str_utf16[1]) : MERGE_TO_WCHAR(str_utf16[1], str_utf16[0]));

        /* we ignore the surrogate pair */
        if (((wc1 >= UTF16_HIGH_START) && (wc1 <= UTF16_HIGH_END)) ||
            ((wc1 >= UTF16_LOW_START) && (wc1 <= UTF16_LOW_END)))
        {
            str_utf16 += 2;
        }
        else
        {
            /* normal case */
            count++;
            str_utf16 += 2;
        }
    }

    return count;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_utf16_to_ucs2_string
 * DESCRIPTION
 *  Converts text encoded using the Unicode transformation format UTF-16
 *  into the Unicode UCS-2 character set.
 * PARAMETERS
 *  dest_ucs2       [OUT]       Destination buffer. On return, contains the Unicode encoded output string.
 *  dest_size       [IN]        The size of Destination buffer.
 *  src_utf16       [IN]        The UTF-16 encoded input string.
 *  utf16_type      [IN]        The type of input UTF-16 encoded string. MMI_CHSET_UTF16LE or MMI_CHSET_UTF16BE
 *  src_end_pos     [OUT]       The point to the end of converted sub-string at the input string.
 * RETURNS
 *  The number of converted bytes, including the final null wide-characters.
 *****************************************************************************/
static kal_int32 mmi_chset_utf16_to_ucs2_string(
                    kal_int8 *dest_ucs2,
                    kal_int32 dest_size,
                    kal_int8 *src_utf16,
                    mmi_chset_enum utf16_type,
                    kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 utf16_bo;
    kal_int32 count = 0;
    kal_wchar wc1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dest_ucs2 && src_utf16 && src_end_pos);
    ASSERT((MMI_CHSET_UTF16BE == utf16_type) || (MMI_CHSET_UTF16LE == utf16_type));

    utf16_bo = mmi_chset_get_utf_byte_order(src_utf16);

    if (-1 != utf16_bo)
    {
        src_utf16 += 2;
        /* needn't convert the beginning BOM */
    }
    else
    {
        utf16_bo = utf16_type;
    }

    while ((src_utf16[0] || src_utf16[1]) && (count < (dest_size - 2)))
    {
        wc1 = ((MMI_CHSET_UTF16BE == utf16_bo) ?
               MERGE_TO_WCHAR(src_utf16[0], src_utf16[1]) : MERGE_TO_WCHAR(src_utf16[1], src_utf16[0]));

        /* we ignore surrogate pair */
        if (((wc1 >= UTF16_HIGH_START) && (wc1 <= UTF16_HIGH_END)) ||
            ((wc1 >= UTF16_LOW_START) && (wc1 <= UTF16_LOW_END)))
        {
            src_utf16 += 2;
        }
        else
        {
            /* normal case */
            dest_ucs2[0] = wc1 & 0xFF;
            dest_ucs2[1] = wc1 >> 8;
            src_utf16 += 2;
            dest_ucs2 += 2;
            count += 2;
        }
    }

    dest_ucs2[0] = '\0';
    dest_ucs2[1] = '\0';

    *src_end_pos = (kal_uint32) src_utf16;
    return (count + 2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf16_string
 * DESCRIPTION
 *  Converts Unicode text into UTF-16 encoding.
 * PARAMETERS
 *  dest_utf16      [OUT]       Destination buffer. On return, contains the Unicode encoded output string.
 *  dest_size       [IN]        The size of Destination buffer.
 *  utf16_type      [IN]        The type of input UTF-16 encoded string. MMI_CHSET_UTF16LE or MMI_CHSET_UTF16BE
 *  include_bom     [IN]        Should include the byte order mark in the UTF-16 encoded output string.
 *  src_ucs2        [IN]        The UTF-16 encoded input string.
 *  src_end_pos     [OUT]       The point to the end of converted sub-string at the input string.
 * RETURNS
 *  The number of converted bytes, including the final null wide-characters.
 *****************************************************************************/
static kal_int32 mmi_chset_ucs2_to_utf16_string(
                    kal_int8 *dest_utf16,
                    kal_int32 dest_size,
                    mmi_chset_enum utf16_type,
                    kal_bool include_bom,
                    kal_int8 *src_ucs2,
                    kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 count = 0;
    kal_wchar wc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dest_utf16 && src_ucs2 && src_end_pos);
    ASSERT((MMI_CHSET_UTF16BE == utf16_type) || (MMI_CHSET_UTF16LE == utf16_type));

    if (include_bom)
    {
        if (MMI_CHSET_UTF16BE == utf16_type)
        {
            dest_utf16[0] = (kal_int8) 0xFF;
            dest_utf16[1] = (kal_int8) 0xFE;
        }
        else
        {
            dest_utf16[0] = (kal_int8) 0xFE;
            dest_utf16[1] = (kal_int8) 0xFF;
        }
        dest_utf16 += 2;
        dest_size -= 2;
        count += 2;
    }

    while ((src_ucs2[0] || src_ucs2[1]) && (count < (dest_size - 2)))
    {
        wc = MERGE_TO_WCHAR(src_ucs2[1], src_ucs2[0]);

        /* UTF-16 surrogate values are illegal in UCS2; 
           0xffff or 0xfffe are both reserved values */
        if (!(wc >= UTF16_HIGH_START && wc <= UTF16_LOW_END))
        {
            if (MMI_CHSET_UTF16LE == utf16_type)
            {
                dest_utf16[0] = src_ucs2[0];
                dest_utf16[1] = src_ucs2[1];
            }
            else
            {
                dest_utf16[0] = src_ucs2[1];
                dest_utf16[1] = src_ucs2[0];
            }
            dest_utf16 += 2;
            count += 2;
        }
        src_ucs2 += 2;
    }

    dest_utf16[0] = '\0';
    dest_utf16[1] = '\0';

    *src_end_pos = (kal_uint32) src_ucs2;
    return (count + 2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_chset_ucs2_to_utf16_bom_str
 * DESCRIPTION
 *  Converts Unicode text into UTF-16 encoding and include the byte order mark
 *  in the UTF-16 encoded output string.
 * PARAMETERS
 *  dest_utf16      [OUT]       Destination buffer. On return, contains the Unicode encoded output string.
 *  dest_size       [IN]        The size of Destination buffer.
 *  utf16_type      [IN]        The type of input UTF-16 encoded string. MMI_CHSET_UTF16LE or MMI_CHSET_UTF16BE
 *  src_ucs2        [IN]        The UTF-16 encoded input string.
 *  src_end_pos     [OUT]       The point to the end of converted sub-string at the input string.
 * RETURNS
 *  The number of converted bytes, including the final null wide-characters.
 *****************************************************************************/
kal_int32 mmi_chset_ucs2_to_utf16_bom_str(
            kal_int8 *dest_utf16,
            kal_int32 dest_size,
            mmi_chset_enum utf16_type,
            kal_int8 *src_ucs2,
            kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_ucs2_to_utf16_string(dest_utf16, dest_size, utf16_type, KAL_TRUE, src_ucs2, src_end_pos);
}

