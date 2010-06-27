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
 *    hf_rules.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file of hindi font rule 
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
/* PMT RAKESH START 20061006 */
#include "gui.h"
/* PMT RAKESH START 20061006 */
#ifdef __MMI_HINDI_ALG__

#ifndef MMI_HINDI_RULES_H
#define MMI_HINDI_RULES_H

#define  G_MAX         30       /* maximun no. of glyph inputs that can be used to make a conjunct */
#define HF_DEFAULT_PADDING 0
#define  C_MAX        10        /* man no. of characters that can form a cluster */
#define  HF_RESERVED   0x0000
#define  SPACE         0x20
/* PMT RAKESH START 20061006 */
typedef enum
{
    MMI_ALL_LANG = 0,
    MMI_HINDI_LANG = 1,
    MMI_MARATHI_LANG = 2
} HINDI_RULES_LANGUAGE_ENUM;
typedef struct __HindiRulesLangSSC
{
    S8 *ssc_string;
    HINDI_RULES_LANGUAGE_ENUM language_enum;
} HindiRulesLangSSC;

/* PMT RAKESH END 20061006 */
#define  HF_HINDI_RANGE(ch)   ( ((U16)(ch)>=S_CHANDRA_BINDU && (U16)(ch)<=S_ABBR)?(1) : (0) )
#define  UNI2HINDI(ch)        (U16)((ch) - 0x900)
extern const U8 g_hindi_character_sign_array[];
extern const U8 g_hindi_character_extended_sign_array[];
extern const U8 g_hindi_character_type_array[];

#define  IdentifyCharacter(ch)  g_hindi_character_type_array[UNI2HINDI(ch)]
//#define  HF_CON_RANGE(ch)     (((ch >= STARTCON && ch <= ENDCON) || (ch >= STARTADDCON && ch <= ENDADDCON) || ch==0x0950 )?1 : 0 )
//#define  HF_INDVOW_RANGE(ch)  ((ch >= NIV_A && ch <=IV_AU )?(1) : (0) )
//#define  HF_DEPVOW_RANGE(ch)  ((ch >= DV_AA && ch <= DV_AU)?(1) : (0) )
//#define  HF_SIGN_RANGE(ch)    ( ((ch >= S_CHANDRA_BINDU && ch <= S_VISARGA ) || (ch >= NS_RESERVED1 && ch <= NS_AACCENT) || ch == S_NUKTA )? (1) : (0) )
//#define  HF_NUMERAL_RANGE(ch) ( (ch>=D_ZERO && ch<= D_NINE)? (1) : (0) )
#define  HF_ENGLISH_NUMERAL_RANGE(ch)  ( (ch>=0x30 && ch<=0x39)? (1) : (0) )
#define STARTCON    0x915       /* start of the consonant */
#define ENDCON      0x939       /* end of consonant */
#define STARTADDCON 0x958       /* start of the additional consonant */
#define ENDADDCON   0x95f       /* end of the additional consonant */
#define STARTDIG    0x966       /* start of the digits */
#define ENDIG       0x96f       /* end of the digits */
// #define  UI_HINDI_SIGN_RANGE(ch)  ch == 0x901 || ch == 0x902 || ch == 0x93c || ch == 0x941 || ch == 0x942|| ch == 0x943 || ch == 0x945 || ch == 0x947 || ch == 0x948|| ch == 0x94d
/* PMT RAKESH START 20061006 */
#define  UI_HINDI_SIGN_RANGE(ch)  (HF_HINDI_RANGE((ch)) &&  g_hindi_character_sign_array[UNI2HINDI((ch))]) || ( ((U16)(ch)>59647 && (U16)(ch)<59842) && g_hindi_character_extended_sign_array[(ch)-59648])
/* PMT RAKESH END 20061006 */
//#define  UI_HINDI_TOP_SIGN_RANGE(ch) ch == 0x901 || ch == 0x902 || ch == 0x945|| ch == 0x947 || ch == 0x948
//#define  UI_HINDI_BOTTOM_SIGN_RANGE(ch) ch == 0x941 || ch == 0x942 || ch == 0x943 || ch == 0x94d || ch ==0x93c
extern PU8 cluster_start_p;
extern PU8 cluster_end_p;
extern S32 use_multitap;
extern S32 parse_hindi;
extern S32 reset_hindi_pms;
extern S32 prev_char_btext_x;
extern S32 prev_char_bdwidth;
extern S32 new_bline;
extern S32 prev_char_text_x;
extern S32 prev_char_dwidth;
extern S32 prev_char_width;
extern S32 new_line;
extern S32 hf_padding;
extern U16 prev_character;

#define  init_cluster_start_p(buffer)     {                  \
                                    cluster_start_p = buffer;\
                                 }
#define init_cluster_end_p(buffer)     {                \
                                 cluster_end_p = buffer;\
                              }

#define  reset_use_multitap() use_multitap=0
#define  set_use_multitap()   use_multitap=1
#define  whether_use_multitap()   use_multitap

#define  hf_disable_hindi_rules_parsing() parse_hindi=0
#define hf_enable_hindi_rules_parsing()   parse_hindi=1
#define hf_is_hindi_rules_parsing() parse_hindi

#define  hf_disable_hindi_reset_hindi_params()  reset_hindi_pms=0
#define hf_enable_hindi_reset_hindi_params() reset_hindi_pms=1
#define hf_is_reset_hindi_params()   reset_hindi_pms

#define hf_padding_value(val) hf_padding=val;
#define hf_padding_def_value()   hf_padding=HF_DEFAULT_PADDING;

#define reset_hindi_bordered_params() {             \
                              prev_char_btext_x = 0;\
                              prev_char_bdwidth = 0;\
                              new_bline = 1;        \
                           }
#define reset_hindi_params()   {                \
                           prev_char_text_x = 0;\
                           prev_char_dwidth = 0;\
                           prev_char_width = 0; \
                           prev_character = 0;  \
                           new_line = 1;        \
                        }
typedef enum
{
    HF_INVALID = 0,
    CON,
    INDVOW,
    DEPVOW,
    SIGN,
    NUM,
    DIG,
    HALANT
} HF_CHARACTER;

typedef enum
{
    NORMAL,
    SPECIAL
} CONSONANT_CATEGORY;

typedef enum
{   /* VARIOUS SIGNS + INDEPENDENT VOWEL */
    S_CHANDRA_BINDU = 0x0901,
    S_BINDU = 0x902,
    S_VISARGA = 0x903,
    NIV_A = 0x904,
    IV_A = 0x905,
    IV_AA = 0x906,
    IV_I = 0x907,
    IV_II = 0x908,
    IV_U = 0x909,
    IV_UU = 0x90a,
    IV_R = 0x90b,
    NIV_L = 0x90c,
    NIV_CE = 0x90d,
    NIV_SE = 0x90e,
    IV_E = 0x90f,
    IV_AI = 0x910,
    NIV_CO = 0x911,
    NIV_SO = 0x912,
    IV_O = 0x913,
    IV_AU = 0x914,

    /* CONSONANTS */
    C_KA = 0x915,
    C_KHA = 0x916,
    C_GA = 0x917,
    C_GHA = 0x918,
    C_NGA = 0x919,
    C_CHA = 0x91a,
    C_CHHA = 0x91b,
    C_JA = 0x91c,
    C_JHA = 0x91d,
    C_NYA = 0x91e,
    C_TTA = 0x91f,
    C_TTHA = 0x920,
    C_DDA = 0x921,
    C_DDHA = 0x922,
    C_NNA = 0x923,
    C_TA = 0x924,
    C_THA = 0x925,
    C_DA = 0x926,
    C_DHA = 0x927,
    C_NA = 0x928,
    C_NNNA = 0x929,
    C_PA = 0x92a,
    C_PHA = 0x92b,
    C_BA = 0x92c,
    C_BHA = 0x92d,
    C_MA = 0x92e,
    C_YA = 0x92f,
    C_RA = 0x930,
    C_RRA = 0x931,
    C_LA = 0x932,
    C_LLA = 0x933,
    C_LLLA = 0x934,
    C_VA = 0x935,
    C_SHA = 0x936,
    C_SSA = 0x937,
    C_SA = 0x938,
    C_HA = 0x939,
    N_BLANK1 = 0x93a,
    N_BLANK2 = 0x93b,

    /* SIGNS */
    S_NUKTA = 0x93c,
    NS_AVAGRAHA = 0x93d,

    /* DEPENDENT VOWELS */
    DV_AA = 0x93e,
    DV_I = 0x93F,
    DV_II = 0x940,
    DV_U = 0x941,
    DV_UU = 0x942,
    DV_R = 0x943,
    NDV_RR = 0x944,
    DV_CE = 0x945,
    NDV_E = 0x946,
    DV_E = 0x947,
    DV_AI = 0x948,
    NDV_CO = 0x949,
    NDV_O = 0x94a,
    DV_O = 0x94b,
    DV_AU = 0x94c,

    /* SIGNS */
    S_HALANT = 0x94d,
    NS_RESERVED1 = 0x94e,
    NS_RESERVED2 = 0x94f,
    S_OM = 0x950,
    NS_UDATTA = 0x951,
    NS_ANUDATTA = 0x952,
    NS_GACCENT = 0x953,
    NS_AACCENT = 0x954,
    N_BLANK5 = 0x955,
    N_BLANK6 = 0x956,
    N_BLANK7 = 0x957,

    /* ADDITIONAL CONSONANT */
    AC_QA = 0x958,
    AC_KHHA = 0x959,
    AC_GHHA = 0x95a,
    AC_ZA = 0x95b,
    AC_DDDHA = 0x95c,
    AC_RHA = 0x95d,
    AC_FA = 0x95e,
    AC_YYA = 0x95f,

    /* GENERIC ADDITIONS */
    NG_RR = 0x960,
    NG_LL = 0x961,
    NG_L = 0x962,
    NG_VLL = 0x963,
    NG_D = 0x964,
    NG_DD = 0x965,

    /* DIGITS */
    D_ZERO = 0x966,
    D_ONE = 0x967,
    D_TWO = 0x968,
    D_THREE = 0x969,
    D_FOUR = 0x96a,
    D_FIVE = 0x96b,
    D_SIX = 0x96c,
    D_SEVEN = 0x96d,
    D_EIGHT = 0x96e,
    D_NINE = 0x96f,
    /* DEVANAGARI SPECIFIC ADDITOIN */
    S_ABBR = 0x970
} HF_CHARACTERS_ENUM;

typedef enum
{
    /* various half forms,ligature etc */
    L_KSHA = 0xE900,
    L_GYA = 0xE901,
    L_TTTA = 0xE902,
    L_TRA = 0xE903,
    L_SHRA = 0xE905,
    L_KRA = 0xE907,
    L_JRA = 0xE908,
    /* L_ZRA=0xE909, */
    L_FRA = 0xE90A,
    /* L_NFRA=0xE90B, */
    L_PRA = 0xE90C,
    L_SRA = 0xE90D,
    L_RU = 0xE90E,
    L_RUU = 0xE90F,
    H_KA = 0xE915,
    H_KHA = 0xE916,
    H_GA = 0xE917,
    H_GHA = 0xE918,
    H_CHA = 0xE91A,
    H_JA = 0xE91C,
    H_JHA = 0xE91D,
    H_NYA = 0xE91E,
    H_ANNA = 0xE923,
    H_TA = 0xE924,
    H_THA = 0xE925,
    H_DHA = 0xE927,
    H_NA = 0xE928,
    H_NNNA = 0xE929,
    H_PA = 0xE92A,
    H_PHA = 0xE92B,
    H_BA = 0xE92C,
    H_BHA = 0xE92D,
    H_MA = 0xE92E,
    H_YA = 0xE92F,
    H_LA = 0xE932,
    H_LLA = 0xE933,
    H_LLLA = 0xE934,
    H_VA = 0xE935,
    H_SHA = 0xE936,
    H_SSA = 0xE937,
    H_SA = 0xE938,
    H_HA = 0xE939,
    L_KKA = 0xE940,
    L_KTA = 0xE941,
    L_DAKA = 0xE942,
    L_DAKHA = 0xE943,
    L_DAGA = 0xE944,
    L_DAGHA = 0xE945,
    L_DADHA = 0xE947,
    L_DABHA = 0xE94B,
    L_DAMA = 0xE94C,
    L_TTTHA = 0xE951,
    L_DDAGA = 0xE952,
    L_DADA = 0xE953,
    L_DADDHA = 0xE954,
    L_DYA = 0xE948,     /* new */
    L_DVA = 0xE94E,     /* new */
    L_DDYA = 0xE94d,    /* new */
    L_TTTTA = 0xE94F,
    L_TTHA = 0xE950,
    L_NNNA = 0xE955,
    L_HMMA = 0xE956,
    L_HYA = 0xE957,
    H_KHSA = 0xE970,
    H_TTA = 0xE972,
    H_TRA = 0xE973,
    H_SHRA = 0xE975,
    L_NCAND = 0xE980,
    L_NBINDU = 0xE981,
    L_IRAHAL = 0xE985,
    L_IRAHALB = 0xE986,
    L_IIRAHALB = 0xE989,
    L_DVERA = 0xE98C,
    L_DVEBINRA = 0xE98D,
    L_DVAIRA = 0xE98F,
    L_DVAIBINRA = 0xE990,
    L_DVORA = 0xE992,
    L_DVOBINRA = 0xE993,
    L_MAU = 0xE994,
    L_DVAURA = 0xE995,
    L_DVAUBINRA = 0xE9AD,
    L_HRA = 0xE9A3,
    L_RABIN = 0xE97B,
    H_EYLASH = 0xE97D,
    SUP_RA = 0xE97E,
    SUB_RA = 0xE97F,
    L_MII = 0xE987,     /* new matra ligature */
    L_MIIRA = 0xE988,
    L_ME = 0xE98B,      /* new matra ligature */
    L_MAI = 0xE98E,
    L_MO = 0xE991,      /* new matra ligature */
    L_KHRA = 0xE996,
    L_GRA = 0xE997,
    L_GHRA = 0xE998,
    L_CHRA = 0xE999,
    L_JHRA = 0xE99B,
    L_THRA = 0xE99C,
    L_DRA = 0xE99D,
    L_DHRA = 0xE99E,
    L_NRA = 0xE99F,
    L_MRA = 0xE9A0,
    L_BRA = 0xE9A1,
    L_BHRA = 0xE9A2,
    L_YRA = 0xE9A4,
    H_PHA_N = 0xE9A7,
    H_GYA = 0xE9A8,
    H_JA_N = 0xE9A9,
    L_VRA = 0xE9AA,
    L_YA_N = 0xE9AB,
    L_KA_N = 0xE9AC,
    L_KHA_N = 0xE9AE,
    L_GA_N = 0xE9AF,
    L_KRA_N = 0xE9B0,
    L_KHRA_N = 0xE9B1,
    L_GRA_N = 0xE9B2,
    L_YRA_N = 0xE9B3,
    L_JRA_N = 0xE909,
    L_FRA_N = 0xE90B,
    /* PMT RAKESH START 20061006 */
#if defined(__MMI_LANG_MARATHI__)
    L_LA_LA = 0XE9B4,
    L_TTA_YA = 0XE9B5,
    L_TTHA_YA = 0XE9B6,
    L_DDA_YA = 0XE9B7,
    L_DDHA_YA = 0XE9B8,
    L_CHHA_YA = 0XE9B9,
    L_SHRA_CHA = 0XE904,
    L_SHRA_VA = 0XE906,
    L_SHRA_LA = 0XE9BC,
    L_SHRA_NA = 0XE9BD,
    L_SSA_TTA = 0XE9BE,
    L_GA_NA = 0XE9BF,
    L_DA_MA = 0XE9C0,
    L_SSA_TTA_RA = 0XE9C1,
#endif /* defined(__MMI_LANG_MARATHI__) */ 
    /* PMT RAKESH END 20061006 */

} HF_LIGATURES_ENUM;

typedef struct _hf_glyph_info
{
    U8 WhetherUcs2;             /* whether it is a ligature or unicode value */
    U8 nInputLen;               /* no. of input unicode values */
    U8 nOutputLen;              /* no, of output values */
    /* PMT RAKESH START 20061006 */
    U8 rule_language;
    /* PMT RAKESH END 20061006 */
    U16 Input_glyph[C_MAX];     /* no. of input glyph used to make conjunct */
    U16 Output_glyph[C_MAX];    /* no. of output glyph that has to be rendered */
} GLYPH_INFO_TABLE;

typedef struct _hf_main_table
{
    const GLYPH_INFO_TABLE *glyphinfo;  /* pointer to individual table */
    U16 nsize;                          /* size of individual character's array */
    U8 maxInputGlyphSize;               /* max input of glyph it can handle */
} MAIN_TABLE;

extern PU8 hf_get_next_cluster_p(PU8, PU8);
extern PU8 hf_get_prev_cluster_p(PU8, PU8);
extern S32 hf_size_of_current_cluster(PU8, PU8, U16);
extern S32 hf_cursor_position_delta_move_insert(PU16 text_p, PU16 cursor_p);
extern S32 hf_cursor_position_delta_move_delete(PU16 text_p, PU16 cursor_p);
extern S32 hf_get_current_cluster(PU8, PU8, PU16);
extern S32 hf_get_string_Dwidth_height(UI_string_type);
extern S32 hf_get_string_width_height(UI_string_type);
extern S32 hf_get_cluster(PU16);
extern S32 hf_get_consonant_cluster(PU16 *, PU8 *, S32);

/* S32 IdentifyCharacter( U16 ); */
extern S32 hf_hindi_rules(PU16, PU16, S32);
extern S32 hf_whether_first_cluster(PU16, PU16);

//void init_cluster_end_p(PU16 );
//void init_cluster_start_p(PU16 );
extern MMI_BOOL whether_ligature(PU16);

/* start farhad 09122004 */
extern void get_text_x(PS32, U16, S32, U16, U16);

/* void reset_hindi_params(void); */
extern void get_multitap_text_x(PS32, U16, S32, S32);
extern S32 hf_get_string_width_height(UI_string_type);
extern S32 hf_get_string_Dwidth_height(UI_string_type);
extern UI_character_type *get_hindi_multitap_string(S32);

/* PMT RAKESH START 20061006 */
#if defined(__MMI_MULTITAP_MARATHI__)
extern UI_character_type *get_marathi_multitap_string(S32);
extern UI_string_type get_marathi_single_line_multitap_string(S32);
#endif /* defined(__MMI_MULTITAP_MARATHI__) */ 
/* PMT RAKESH END 20061006 */
/* void reset_hindi_bordered_params(void); */
extern void get_bordered_text_x(PS32, U16, S32);

/* end farhad 09122004 */

/* PMT RAKESH START 20061006 */
extern void overwrite_current_language_for_hindi_rules_based_on_input_method(void);
extern void set_current_language_for_hindi_rules(void);
extern void restore_current_language_for_hindi_rules(void);
/* PMT RAKESH END 20061006 */
#endif /* MMI_HINDI_RULES_H */ 
#endif /* __MMI_HINDI_ALG__ */ 

