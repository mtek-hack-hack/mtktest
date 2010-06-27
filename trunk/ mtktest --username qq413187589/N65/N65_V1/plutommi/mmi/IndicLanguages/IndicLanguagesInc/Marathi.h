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
 *    Marathi.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    c file of marathi font rule 
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
#include "gui_data_types.h"
#include "MMIDataType.h"

#if defined (__MMI_LANG_MARATHI__)

typedef enum
{   /* VARIOUS SIGNS + INDEPENDENT VOWEL */
    MARATHI_S_CHANDRA_BINDU		= 0x0901,
    MARATHI_S_BINDU				= 0x0902,
    MARATHI_S_VISARGA			= 0x0903,
    MARATHI_NIV_A				= 0x0904,
    MARATHI_IV_A				= 0x0905,
    MARATHI_IV_AA				= 0x0906,
    MARATHI_IV_I				= 0x0907,
    MARATHI_IV_II				= 0x0908,
    MARATHI_IV_U				= 0x0909,
    MARATHI_IV_UU				= 0x090a,
    MARATHI_IV_R				= 0x090b,
    MARATHI_NIV_L				= 0x090c,
    MARATHI_NIV_CE				= 0x090d,
    MARATHI_NIV_SE				= 0x090e,
    MARATHI_IV_E				= 0x090f,
    MARATHI_IV_AI				= 0x0910,
    MARATHI_NIV_CO				= 0x0911,
    MARATHI_NIV_SO				= 0x0912,
    MARATHI_IV_O				= 0x0913,
    MARATHI_IV_AU				= 0x0914,

    /* CONSONANTS */
    MARATHI_C_KA				= 0x0915,
    MARATHI_C_KHA				= 0x0916,
    MARATHI_C_GA				= 0x0917,
    MARATHI_C_GHA				= 0x0918,
    MARATHI_C_NGA				= 0x0919,
    MARATHI_C_CHA				= 0x091a,
    MARATHI_C_CHHA				= 0x091b,
    MARATHI_C_JA				= 0x091c,
    MARATHI_C_JHA				= 0x091d,
    MARATHI_C_NYA				= 0x091e,
    MARATHI_C_TTA				= 0x091f,
    MARATHI_C_TTHA				= 0x0920,
    MARATHI_C_DDA				= 0x0921,
    MARATHI_C_DDHA				= 0x0922,
    MARATHI_C_NNA				= 0x0923,
    MARATHI_C_TA				= 0x0924,
    MARATHI_C_THA				= 0x0925,
    MARATHI_C_DA				= 0x0926,
    MARATHI_C_DHA				= 0x0927,
    MARATHI_C_NA				= 0x0928,
    MARATHI_C_NNNA				= 0x0929,
    MARATHI_C_PA				= 0x092a,
    MARATHI_C_PHA				= 0x092b,
    MARATHI_C_BA				= 0x092c,
    MARATHI_C_BHA				= 0x092d,
    MARATHI_C_MA				= 0x092e,
    MARATHI_C_YA				= 0x092f,
    MARATHI_C_RA				= 0x0930,
    MARATHI_C_RRA				= 0x0931,
    MARATHI_C_LA				= 0x0932,
    MARATHI_C_LLA				= 0x0933,
    MARATHI_C_LLLA				= 0x0934,
    MARATHI_C_VA				= 0x0935,
    MARATHI_C_SHA				= 0x0936,
    MARATHI_C_SSA				= 0x0937,
    MARATHI_C_SA				= 0x0938,
    MARATHI_C_HA				= 0x0939,
    MARATHI_N_BLANK1			= 0x093a,
    MARATHI_N_BLANK2			= 0x093b,

    /* SIGNS */
    MARATHI_S_NUKTA				= 0x093c,
    MARATHI_NS_AVAGRAHA			= 0x093d,

    /* DEPENDENT VOWELS */
    MARATHI_DV_AA				= 0x093e,
    MARATHI_DV_I				= 0x093f,
    MARATHI_DV_II				= 0x0940,
    MARATHI_DV_U				= 0x0941,
    MARATHI_DV_UU				= 0x0942,
    MARATHI_DV_R				= 0x0943,
    MARATHI_NDV_RR				= 0x0944,
    MARATHI_DV_CE				= 0x0945,
    MARATHI_NDV_E				= 0x0946,
    MARATHI_DV_E				= 0x0947,
    MARATHI_DV_AI				= 0x0948,
    MARATHI_NDV_CO				= 0x0949,
    MARATHI_NDV_O				= 0x094a,
    MARATHI_DV_O				= 0x094b,
    MARATHI_DV_AU				= 0x094c,

    /* SIGNS */
    MARATHI_S_HALANT			= 0x094d,
    MARATHI_NS_RESERVED1		= 0x094e,
    MARATHI_NS_RESERVED2		= 0x094f,
    MARATHI_S_OM				= 0x0950,
    MARATHI_NS_UDATTA			= 0x0951,
    MARATHI_NS_ANUDATTA			= 0x0952,
    MARATHI_NS_GACCENT			= 0x0953,
    MARATHI_NS_AACCENT			= 0x0954,
    MARATHI_N_BLANK5			= 0x0955,
    MARATHI_N_BLANK6			= 0x0956,
    MARATHI_N_BLANK7			= 0x0957,

    /* ADDITIONAL CONSONANT */
    MARATHI_AC_QA				= 0x0958,
    MARATHI_AC_KHHA				= 0x0959,
    MARATHI_AC_GHHA				= 0x095a,
    MARATHI_AC_ZA				= 0x095b,
    MARATHI_AC_DDDHA			= 0x095c,
    MARATHI_AC_RHA				= 0x095d,
    MARATHI_AC_FA				= 0x095e,
    MARATHI_AC_YYA				= 0x095f,

    /* GENERIC ADDITIONS */
    MARATHI_NG_RR				= 0x0960,
    MARATHI_NG_LL				= 0x0961,
    MARATHI_NG_L				= 0x0962,
    MARATHI_NG_VLL				= 0x0963,
    MARATHI_NG_D				= 0x0964,
    MARATHI_NG_DD				= 0x0965,

    /* DIGITS */
    MARATHI_D_ZERO				= 0x0966,
    MARATHI_D_ONE				= 0x0967,
    MARATHI_D_TWO				= 0x0968,
    MARATHI_D_THREE				= 0x0969,
    MARATHI_D_FOUR				= 0x096a,
    MARATHI_D_FIVE				= 0x096b,
    MARATHI_D_SIX				= 0x096c,
    MARATHI_D_SEVEN				= 0x096d,
    MARATHI_D_EIGHT				= 0x096e,
    MARATHI_D_NINE				= 0x096f,
    /* DEVANAGARI SPECIFIC ADDITOIN */
    MARATHI_S_ABBR				= 0x0970
}marathi_characters_enum;

typedef enum
{
    /* various half forms,ligature etc */
    MARATHI_L_KSHA				= 0xE900,
    MARATHI_L_GYA				= 0xE901,
    MARATHI_L_TTTA				= 0xE902,
    MARATHI_L_TRA				= 0xE903,
    MARATHI_L_SHRA				= 0xE905,
    MARATHI_L_KRA				= 0xE907,
    MARATHI_L_JRA				= 0xE908,
    /* L_ZRA=0xE909, */
    MARATHI_L_FRA				= 0xE90A,
    /* L_NFRA=0xE90B, */
    MARATHI_L_PRA				= 0xE90C,
    MARATHI_L_SRA				= 0xE90D,
    MARATHI_L_RU				= 0xE90E,
    MARATHI_L_RUU				= 0xE90F,
    MARATHI_H_KA				= 0xE915,
    MARATHI_H_KHA				= 0xE916,
    MARATHI_H_GA				= 0xE917,
    MARATHI_H_GHA				= 0xE918,
    MARATHI_H_CHA				= 0xE91A,
    MARATHI_H_JA				= 0xE91C,
    MARATHI_H_JHA				= 0xE91D,
    MARATHI_H_NYA				= 0xE91E,
    MARATHI_H_ANNA				= 0xE923,
    MARATHI_H_TA				= 0xE924,
    MARATHI_H_THA				= 0xE925,
    MARATHI_H_DHA				= 0xE927,
    MARATHI_H_NA				= 0xE928,
    MARATHI_H_NNNA				= 0xE929,
    MARATHI_H_PA				= 0xE92A,
    MARATHI_H_PHA				= 0xE92B,
    MARATHI_H_BA				= 0xE92C,
    MARATHI_H_BHA				= 0xE92D,
    MARATHI_H_MA				= 0xE92E,
    MARATHI_H_YA				= 0xE92F,
    MARATHI_H_LA				= 0xE932,
    MARATHI_H_LLA				= 0xE933,
    MARATHI_H_LLLA				= 0xE934,
    MARATHI_H_VA				= 0xE935,
    MARATHI_H_SHA				= 0xE936,
    MARATHI_H_SSA				= 0xE937,
    MARATHI_H_SA				= 0xE938,
    MARATHI_H_HA				= 0xE939,
    MARATHI_L_KKA				= 0xE940,
    MARATHI_L_KTA				= 0xE941,
    MARATHI_L_DAKA				= 0xE942,
    MARATHI_L_DAKHA				= 0xE943,
    MARATHI_L_DAGA				= 0xE944,
    MARATHI_L_DAGHA				= 0xE945,
    MARATHI_L_DADHA				= 0xE947,
    MARATHI_L_DABHA				= 0xE94B,
    MARATHI_L_DAMA				= 0xE94C,
    MARATHI_L_TTTHA				= 0xE951,
    MARATHI_L_DDAGA				= 0xE952,
    MARATHI_L_DADA				= 0xE953,
    MARATHI_L_DADDHA			= 0xE954,
    MARATHI_L_DYA				= 0xE948,     /* new */
    MARATHI_L_DVA				= 0xE94E,     /* new */
    MARATHI_L_DDYA				= 0xE94d,    /* new */
    MARATHI_L_TTTTA				= 0xE94F,
    MARATHI_L_TTHA				= 0xE950,
    MARATHI_L_NNNA				= 0xE955,
    MARATHI_L_HMMA				= 0xE956,
    MARATHI_L_HYA				= 0xE957,
    MARATHI_H_KHSA				= 0xE970,
    MARATHI_H_TTA				= 0xE972,
    MARATHI_H_TRA				= 0xE973,
    MARATHI_H_SHRA				= 0xE975,
    MARATHI_L_NCAND				= 0xE980,
    MARATHI_L_NBINDU			= 0xE981,
    MARATHI_L_IRAHAL			= 0xE985,
    MARATHI_L_IRAHALB			= 0xE986,
    MARATHI_L_IIRAHALB			= 0xE989,
    MARATHI_L_DVERA				= 0xE98C,
    MARATHI_L_DVEBINRA			= 0xE98D,
    MARATHI_L_DVAIRA			= 0xE98F,
    MARATHI_L_DVAIBINRA			= 0xE990,
    MARATHI_L_DVORA				= 0xE992,
    MARATHI_L_DVOBINRA			= 0xE993,
    MARATHI_L_MAU				= 0xE994,
    MARATHI_L_DVAURA			= 0xE995,
    MARATHI_L_DVAUBINRA			= 0xE9AD,
    MARATHI_L_HRA				= 0xE9A3,
    MARATHI_L_RABIN				= 0xE97B,
    MARATHI_H_EYLASH			= 0xE97D,
    MARATHI_SUP_RA				= 0xE97E,
    MARATHI_SUB_RA				= 0xE97F,
    MARATHI_L_MII				= 0xE987,     /* new matra ligature */
    MARATHI_L_MIIRA				= 0xE988,
    MARATHI_L_ME				= 0xE98B,      /* new matra ligature */
    MARATHI_L_MAI				= 0xE98E,
    MARATHI_L_MO				= 0xE991,      /* new matra ligature */
    MARATHI_L_KHRA				= 0xE996,
    MARATHI_L_GRA				= 0xE997,
    MARATHI_L_GHRA				= 0xE998,
    MARATHI_L_CHRA				= 0xE999,
    MARATHI_L_JHRA				= 0xE99B,
    MARATHI_L_THRA				= 0xE99C,
    MARATHI_L_DRA				= 0xE99D,
    MARATHI_L_DHRA				= 0xE99E,
    MARATHI_L_NRA				= 0xE99F,
    MARATHI_L_MRA				= 0xE9A0,
    MARATHI_L_BRA				= 0xE9A1,
    MARATHI_L_BHRA				= 0xE9A2,
    MARATHI_L_YRA				= 0xE9A4,
    MARATHI_H_PHA_N				= 0xE9A7,
    MARATHI_H_GYA				= 0xE9A8,
    MARATHI_H_JA_N				= 0xE9A9,
    MARATHI_L_VRA				= 0xE9AA,
    MARATHI_L_YA_N				= 0xE9AB,
    MARATHI_L_KA_N				= 0xE9AC,
    MARATHI_L_KHA_N				= 0xE9AE,
    MARATHI_L_GA_N				= 0xE9AF,
    MARATHI_L_KRA_N				= 0xE9B0,
    MARATHI_L_KHRA_N			        = 0xE9B1,
    MARATHI_L_GRA_N				= 0xE9B2,
    MARATHI_L_YRA_N				= 0xE9B3,
    MARATHI_L_JRA_N				= 0xE909,
    MARATHI_L_FRA_N				= 0xE90B,

#if defined(__MMI_LANG_MARATHI__)
    MARATHI_L_LA_LA			= 0XE9B4,
    MARATHI_L_TTA_YA			= 0XE9B5,
    MARATHI_L_TTHA_YA			= 0XE9B6,
    MARATHI_L_DDA_YA			= 0XE9B7,
    MARATHI_L_DDHA_YA			= 0XE9B8,
    MARATHI_L_CHHA_YA			= 0XE9B9,
    MARATHI_L_SHRA_CHA			= 0XE904,
    MARATHI_L_SHRA_VA			= 0XE906,
    MARATHI_L_SHRA_LA			= 0XE9BC,
    MARATHI_L_SHRA_NA			= 0XE9BD,
    MARATHI_L_SSA_TTA			= 0XE9BE,
    MARATHI_L_GA_NA				= 0XE9BF,
    MARATHI_L_DA_MA				= 0XE9C0,
    MARATHI_L_SSA_TTA_RA		= 0XE9C1
#endif /* defined(__MMI_LANG_MARATHI__) */ 

}marathi_ligatures_enum;

#if defined (__MMI_MULTITAP_MARATHI__)  


extern const UI_character_type default_marathi_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_marathimatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_marathimatra1_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_marathimatra2_multitap_strings[MAX_MULTITAPS][32];

extern UI_character_type *get_marathi_multitap_string(S32 i);
extern UI_character_type *get_marathi_single_line_multitap_string(S32 i);

#endif 
#endif