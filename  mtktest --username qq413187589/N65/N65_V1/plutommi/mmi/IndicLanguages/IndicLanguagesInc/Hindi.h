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
 *    Hindi.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file of hindi font rule 
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
#ifndef MMI_HINDI_H
#define MMI_HINDI_H

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"

#if defined (__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)

#define IRE_HINDI_LANG_START_RANGE        0x0900
#define IRE_HINDI_LANG_END_RANGE       0x0970

#define IRE_HINDI_PROPRIETRY_START_RANGE  0xE8FF
#define IRE_HINDI_PROPRIETRY_END_RANGE    0xE9C1

typedef enum
{   /* VARIOUS SIGNS + INDEPENDENT VOWEL */
    HINDI_S_CHANDRA_BINDU = 0x0901,
    HINDI_S_BINDU = 0x0902,
    HINDI_S_VISARGA = 0x0903,
    HINDI_NIV_A = 0x0904,
    HINDI_IV_A = 0x0905,
    HINDI_IV_AA = 0x0906,
    HINDI_IV_I = 0x0907,
    HINDI_IV_II = 0x0908,
    HINDI_IV_U = 0x0909,
    HINDI_IV_UU = 0x090a,
    HINDI_IV_R = 0x090b,
    HINDI_NIV_L = 0x090c,
    HINDI_NIV_CE = 0x090d,
    HINDI_NIV_SE = 0x090e,
    HINDI_IV_E = 0x090f,
    HINDI_IV_AI = 0x0910,
    HINDI_NIV_CO = 0x0911,
    HINDI_NIV_SO = 0x0912,
    HINDI_IV_O = 0x0913,
    HINDI_IV_AU = 0x0914,

    /* CONSONANTS */
    HINDI_C_KA = 0x0915,
    HINDI_C_KHA = 0x0916,
    HINDI_C_GA = 0x0917,
    HINDI_C_GHA = 0x0918,
    HINDI_C_NGA = 0x0919,
    HINDI_C_CHA = 0x091a,
    HINDI_C_CHHA = 0x091b,
    HINDI_C_JA = 0x091c,
    HINDI_C_JHA = 0x091d,
    HINDI_C_NYA = 0x091e,
    HINDI_C_TTA = 0x091f,
    HINDI_C_TTHA = 0x0920,
    HINDI_C_DDA = 0x0921,
    HINDI_C_DDHA = 0x0922,
    HINDI_C_NNA = 0x0923,
    HINDI_C_TA = 0x0924,
    HINDI_C_THA = 0x0925,
    HINDI_C_DA = 0x0926,
    HINDI_C_DHA = 0x0927,
    HINDI_C_NA = 0x0928,
    HINDI_C_NNNA = 0x0929,
    HINDI_C_PA = 0x092a,
    HINDI_C_PHA = 0x092b,
    HINDI_C_BA = 0x092c,
    HINDI_C_BHA = 0x092d,
    HINDI_C_MA = 0x092e,
    HINDI_C_YA = 0x092f,
    HINDI_C_RA = 0x0930,
    HINDI_C_RRA = 0x0931,
    HINDI_C_LA = 0x0932,
    HINDI_C_LLA = 0x0933,
    HINDI_C_LLLA = 0x0934,
    HINDI_C_VA = 0x0935,
    HINDI_C_SHA = 0x0936,
    HINDI_C_SSA = 0x0937,
    HINDI_C_SA = 0x0938,
    HINDI_C_HA = 0x0939,
    N_BLANK1 = 0x093a,
    N_BLANK2 = 0x093b,

    /* SIGNS */
    HINDI_S_NUKTA = 0x093c,
    HINDI_NS_AVAGRAHA = 0x093d,

    /* DEPENDENT VOWELS */
    HINDI_DV_AA = 0x093e,
    HINDI_DV_I = 0x093f,
    HINDI_DV_II = 0x0940,
    HINDI_DV_U = 0x0941,
    HINDI_DV_UU = 0x0942,
    HINDI_DV_R = 0x0943,
    HINDI_NDV_RR = 0x0944,
    HINDI_DV_CE = 0x0945,
    HINDI_NDV_E = 0x0946,
    HINDI_DV_E = 0x0947,
    HINDI_DV_AI = 0x0948,
    HINDI_NDV_CO = 0x0949,
    HINDI_NDV_O = 0x094a,
    HINDI_DV_O = 0x094b,
    HINDI_DV_AU = 0x094c,

    /* SIGNS */
    HINDI_S_HALANT = 0x094d,
    NS_RESERVED1 = 0x094e,
    NS_RESERVED2 = 0x094f,
    HINDI_S_OM = 0x0950,
    HINDI_NS_UDATTA = 0x0951,
    HINDI_NS_ANUDATTA = 0x0952,
    HINDI_NS_GACCENT = 0x0953,
    HINDI_NS_AACCENT = 0x0954,
    N_BLANK5 = 0x0955,
    N_BLANK6 = 0x0956,
    N_BLANK7 = 0x0957,

    /* ADDITIONAL CONSONANT */
    HINDI_AC_QA = 0x0958,
    HINDI_AC_KHHA = 0x0959,
    HINDI_AC_GHHA = 0x095a,
    HINDI_AC_ZA = 0x095b,
    HINDI_AC_DDDHA = 0x095c,
    HINDI_AC_RHA = 0x095d,
    HINDI_AC_FA = 0x095e,
    HINDI_AC_YYA = 0x095f,

    /* GENERIC ADDITIONS */
    HINDI_NG_RR = 0x0960,
    HINDI_NG_LL = 0x0961,
    HINDI_NG_L = 0x0962,
    HINDI_NG_VLL = 0x0963,
    HINDI_NG_D = 0x0964,
    HINDI_NG_DD = 0x0965,

    /* DIGITS */
    HINDI_D_ZERO = 0x0966,
    HINDI_D_ONE = 0x0967,
    HINDI_D_TWO = 0x0968,
    HINDI_D_THREE = 0x0969,
    HINDI_D_FOUR = 0x096a,
    HINDI_D_FIVE = 0x096b,
    HINDI_D_SIX = 0x096c,
    HINDI_D_SEVEN = 0x096d,
    HINDI_D_EIGHT = 0x096e,
    HINDI_D_NINE = 0x096f,
    /* DEVANAGARI SPECIFIC ADDITOIN */
    HINDI_S_ABBR = 0x0970
} hindi_characters_enum;

typedef enum
{
    /* various half forms,ligature etc */
    HINDI_L_KSHA = 0xE900,
    HINDI_L_GYA = 0xE901,
    HINDI_L_TTTA = 0xE902,
    HINDI_L_TRA = 0xE903,
    HINDI_L_SHRA = 0xE905,
    HINDI_L_KRA = 0xE907,
    HINDI_L_JRA = 0xE908,
    /* L_ZRA=0xE909, */
    HINDI_L_FRA = 0xE90A,
    /* L_NFRA=0xE90B, */
    HINDI_L_PRA = 0xE90C,
    HINDI_L_SRA = 0xE90D,
    HINDI_L_RU = 0xE90E,
    HINDI_L_RUU = 0xE90F,
    HINDI_H_KA = 0xE915,
    HINDI_H_KHA = 0xE916,
    HINDI_H_GA = 0xE917,
    HINDI_H_GHA = 0xE918,
    HINDI_H_CHA = 0xE91A,
    HINDI_H_JA = 0xE91C,
    HINDI_H_JHA = 0xE91D,
    HINDI_H_NYA = 0xE91E,
    HINDI_H_ANNA = 0xE923,
    HINDI_H_TA = 0xE924,
    HINDI_H_THA = 0xE925,
    HINDI_H_DHA = 0xE927,
    HINDI_H_NA = 0xE928,
    HINDI_H_NNNA = 0xE929,
    HINDI_H_PA = 0xE92A,
    HINDI_H_PHA = 0xE92B,
    HINDI_H_BA = 0xE92C,
    HINDI_H_BHA = 0xE92D,
    HINDI_H_MA = 0xE92E,
    HINDI_H_YA = 0xE92F,
    HINDI_H_LA = 0xE932,
    HINDI_H_LLA = 0xE933,
    HINDI_H_LLLA = 0xE934,
    HINDI_H_VA = 0xE935,
    HINDI_H_SHA = 0xE936,
    HINDI_H_SSA = 0xE937,
    HINDI_H_SA = 0xE938,
    HINDI_H_HA = 0xE939,
    HINDI_L_KKA = 0xE940,
    HINDI_L_KTA = 0xE941,
    HINDI_L_DAKA = 0xE942,
    HINDI_L_DAKHA = 0xE943,
    HINDI_L_DAGA = 0xE944,
    HINDI_L_DAGHA = 0xE945,
    HINDI_L_DADHA = 0xE947,
    HINDI_L_DABHA = 0xE94B,
    HINDI_L_DAMA = 0xE94C,
    HINDI_L_TTTHA = 0xE951,
    HINDI_L_DDAGA = 0xE952,
    HINDI_L_DADA = 0xE953,
    HINDI_L_DADDHA = 0xE954,
    HINDI_L_DYA = 0xE948,   /* new */
    HINDI_L_DVA = 0xE94E,   /* new */
    HINDI_L_DDYA = 0xE94d,  /* new */
    HINDI_L_TTTTA = 0xE94F,
    HINDI_L_TTHA = 0xE950,
    HINDI_L_NNNA = 0xE955,
    HINDI_L_HMMA = 0xE956,
    HINDI_L_HYA = 0xE957,
    HINDI_H_KHSA = 0xE970,
    HINDI_H_TTA = 0xE972,
    HINDI_H_TRA = 0xE973,
    HINDI_H_SHRA = 0xE975,
    HINDI_L_NCAND = 0xE980,
    HINDI_L_NBINDU = 0xE981,
    HINDI_L_IRAHAL = 0xE985,
    HINDI_L_IRAHALB = 0xE986,
    HINDI_L_IIRAHALB = 0xE989,
    HINDI_L_CHANDRA_BINDU = 0xE98A,
    HINDI_L_DVERA = 0xE98C,
    HINDI_L_DVEBINRA = 0xE98D,
    HINDI_L_DVAIRA = 0xE98F,
    HINDI_L_DVAIBINRA = 0xE990,
    HINDI_L_DVORA = 0xE992,
    HINDI_L_DVOBINRA = 0xE993,
    HINDI_L_MAU = 0xE994,
    HINDI_L_DVAURA = 0xE995,
    HINDI_L_DVAUBINRA = 0xE9AD,
    HINDI_L_HRA = 0xE9A3,
    HINDI_L_RABIN = 0xE97B,
    HINDI_H_EYLASH = 0xE97D,
    HINDI_SUP_RA = 0xE97E,
    HINDI_SUB_RA = 0xE97F,
    HINDI_L_MII = 0xE987,   /* new matra ligature */
    HINDI_L_MIIRA = 0xE988,
    HINDI_L_ME = 0xE98B,    /* new matra ligature */
    HINDI_L_MAI = 0xE98E,
    HINDI_L_MO = 0xE991,    /* new matra ligature */
    HINDI_L_KHRA = 0xE996,
    HINDI_L_GRA = 0xE997,
    HINDI_L_GHRA = 0xE998,
    HINDI_L_CHRA = 0xE999,
    HINDI_L_JHRA = 0xE99B,
    HINDI_L_THRA = 0xE99C,
    HINDI_L_DRA = 0xE99D,
    HINDI_L_DHRA = 0xE99E,
    HINDI_L_NRA = 0xE99F,
    HINDI_L_MRA = 0xE9A0,
    HINDI_L_BRA = 0xE9A1,
    HINDI_L_BHRA = 0xE9A2,
    HINDI_L_YRA = 0xE9A4,
    HINDI_H_PHA_N = 0xE9A7,
    HINDI_H_GYA = 0xE9A8,
    HINDI_H_JA_N = 0xE9A9,
    HINDI_L_VRA = 0xE9AA,
    HINDI_L_YA_N = 0xE9AB,
    HINDI_L_KA_N = 0xE9AC,
    HINDI_L_KHA_N = 0xE9AE,
    HINDI_L_GA_N = 0xE9AF,
    HINDI_L_KRA_N = 0xE9B0,
    HINDI_L_KHRA_N = 0xE9B1,
    HINDI_L_GRA_N = 0xE9B2,
    HINDI_L_YRA_N = 0xE9B3,
    HINDI_L_JRA_N = 0xE909,
    HINDI_L_FRA_N = 0xE90B

#if defined(__MMI_LANG_MARATHI__)
    ,HINDI_L_LA_LA = 0XE9B4,
    HINDI_L_TTA_YA = 0XE9B5,
    HINDI_L_TTHA_YA = 0XE9B6,
    HINDI_L_DDA_YA = 0XE9B7,
    HINDI_L_DDHA_YA = 0XE9B8,
    HINDI_L_CHHA_YA = 0XE9B9,
    HINDI_L_SHRA_CHA = 0XE904,
    HINDI_L_SHRA_VA = 0XE906,
    HINDI_L_SHRA_LA = 0XE9BC,
    HINDI_L_SHRA_NA = 0XE9BD,
    HINDI_L_SSA_TTA = 0XE9BE,
    HINDI_L_GA_NA = 0XE9BF,
    HINDI_L_DA_MA = 0XE9C0,
    HINDI_L_SSA_TTA_RA = 0XE9C1
#endif /* defined(__MMI_LANG_MARATHI__) */ 
} hindi_ligatures_enum;

#if defined (__MMI_MULTITAP_HINDI__)
/* Following Arrays are use to insert character according hindi grammar rules  */

#if defined (__MMI_ZI_V7__) && defined (__MMI_ZI_HINDI__)

extern const UI_character_type default_hindi_multitap_strings[MAX_MULTITAPS][45];
extern const UI_character_type default_hindimatra_multitap_strings[MAX_MULTITAPS][45];
extern const UI_character_type default_hindimatra1_multitap_strings[MAX_MULTITAPS][45];
extern const UI_character_type default_hindimatra2_multitap_strings[MAX_MULTITAPS][45];
extern const UI_character_type default_hindimatra3_multitap_strings[MAX_MULTITAPS][45];

#else 
extern const UI_character_type default_hindi_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_hindimatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_hindimatra1_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_hindimatra2_multitap_strings[MAX_MULTITAPS][32];
#endif
extern UI_character_type *get_hindi_multitap_string(S32 i);

#endif /* defined (__MMI_MULTITAP_HINDI__) */ /* #if defined (__MMI_MULTITAP_HINDI__)  */
#endif /* defined (__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) */ 

#endif /* MMI_HINDI_H */ 

