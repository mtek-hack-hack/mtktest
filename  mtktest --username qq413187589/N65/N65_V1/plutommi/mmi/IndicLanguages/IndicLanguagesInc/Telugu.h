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
 *   Telugu.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   ENUMS, Macros and function wrappers related to Telugu language.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_TELUGU_H
#define MMI_TELUGU_H

#include "MMI_features.h"
#include "MMIDataType.h"

#if defined (__MMI_LANG_TELUGU__)

#define IRE_TELUGU_LANG_START_RANGE        0xc00
#define IRE_TELUGU_LANG_END_RANGE          0xc6f
/* 7.24 PMT  START TELUGU & PUNJABI */
#define IRE_TELUGU_PROPRIETRY_START_RANGE  0xec00
 /* PMT START MAUI_00027829 */
#define IRE_TELUGU_PROPRIETRY_END_RANGE    0xed25
 /* PMT END MAUI_00027829 */
/* 7.24 PMT  END TELUGU & PUNJABI */

typedef enum
{

    /* VARIOUS SIGNS */

    TELUGU_S_CHANDRA_BINDU = 0xc01,
    TELUGU_S_ANUSVARA = 0xc02,
    TELUGU_S_VISARGA = 0xc03,

    /* INDEPENDENT VOWEL */

    TELUGU_IV_A = 0xc05,
    TELUGU_IV_AA = 0xc06,
    TELUGU_IV_I = 0xc07,
    TELUGU_IV_II = 0xc08,
    TELUGU_IV_U = 0xc09,
    TELUGU_IV_UU = 0xc0a,
    TELUGU_IV_VR = 0xc0b,
    TELUGU_IV_VL = 0xc0c,
    TELUGU_IV_E = 0xc0e,
    TELUGU_IV_EE = 0xc0f,
    TELUGU_IV_AI = 0xc10,
    TELUGU_IV_O = 0xc12,
    TELUGU_IV_OO = 0xc13,
    TELUGU_IV_AU = 0xc14,

    /*  CONSONANTS  */

    TELUGU_C_KA = 0xc15,
    TELUGU_C_KHA = 0xc16,
    TELUGU_C_GA = 0xc17,
    TELUGU_C_GHA = 0xc18,
    TELUGU_C_NGA = 0xc19,
    TELUGU_C_CA = 0xc1a,
    TELUGU_C_CHA = 0xc1b,
    TELUGU_C_JA = 0xc1c,
    TELUGU_C_JHA = 0xc1d,
    TELUGU_C_NYA = 0xc1e,
    TELUGU_C_TTA = 0xc1f,
    TELUGU_C_TTHA = 0xc20,
    TELUGU_C_DDA = 0xc21,
    TELUGU_C_DDHA = 0xc22,
    TELUGU_C_NNA = 0xc23,
    TELUGU_C_TA = 0xc24,
    TELUGU_C_THA = 0xc25,
    TELUGU_C_DA = 0xc26,
    TELUGU_C_DHA = 0xc27,
    TELUGU_C_NA = 0xc28,
    TELUGU_C_PA = 0xc2a,
    TELUGU_C_PHA = 0xc2b,
    TELUGU_C_BA = 0xc2c,
    TELUGU_C_BHA = 0xc2d,
    TELUGU_C_MA = 0xc2e,
    TELUGU_C_YA = 0xc2f,
    TELUGU_C_RA = 0xc30,
    TELUGU_C_RRA = 0xc31,
    TELUGU_C_LA = 0xc32,
    TELUGU_C_LLA = 0xc33,
    TELUGU_C_VA = 0xc35,
    TELUGU_C_SHA = 0xc36,
    TELUGU_C_SSA = 0xc37,
    TELUGU_C_SA = 0xc38,
    TELUGU_C_HA = 0xc39,

    /*  DEPENDENT VOWELS  */

    TELUGU_DV_AA = 0xc3e,
    TELUGU_DV_I = 0xc3f,
    TELUGU_DV_II = 0xc40,
    TELUGU_DV_U = 0xc41,
    TELUGU_DV_UU = 0xc42,
    TELUGU_DV_VR = 0xc43,
    TELUGU_DV_VRR = 0xc44,
    TELUGU_DV_E = 0xc46,
    TELUGU_DV_EE = 0xc47,
    TELUGU_DV_AI = 0xc48,
    TELUGU_DV_O = 0xc4a,
    TELUGU_DV_OO = 0xc4b,
    TELUGU_DV_AU = 0xc4c,
    TELUGU_S_HALANT = 0xc4d,
    TELUGU_ADV_EE = 0xc55,
    TELUGU_ADV_AI = 0xc56,
    TELUGU_IV_VRR = 0xc60,
    TELUGU_IV_VLL = 0xc61,

    /*  DIGITS  */

    TELUGU_D_ZERO = 0xc66,
    TELUGU_D_ONE = 0xc67,
    TELUGU_D_TWO = 0xc68,
    TELUGU_D_THREE = 0xc69,
    TELUGU_D_FOUR = 0xc6a,
    TELUGU_D_FIVE = 0xc6b,
    TELUGU_D_SIX = 0xc6c,
    TELUGU_D_SEVEN = 0xc6d,
    TELUGU_D_EIGHT = 0xc6e,
    TELUGU_D_NINE = 0xc6f

} telugu_characters_enum;

typedef enum
{

    /* 7.24 PMT  START TELUGU & PUNJABI */
    TELUGU_L_KA = 0xec01,
    TELUGU_L_KAA = 0xec02,
    TELUGU_L_NGAA = 0xec03,
    TELUGU_L_NGU = 0xec04,
    TELUGU_L_KHI = 0xec05,
    TELUGU_L_KHII = 0xec06,
    TELUGU_L_KHE = 0xec07,
    TELUGU_L_KHEE = 0xec08,
    TELUGU_L_KHAI = 0xec09,
    TELUGU_L_KHO = 0xec0a,
    TELUGU_L_KHOO = 0xec0b,
    TELUGU_L_KHAU = 0xec0c,
    TELUGU_L_GA = 0xec0d,
    TELUGU_L_GAA = 0xec0e,
    TELUGU_L_GHA = 0xec0f,
    TELUGU_L_GHE = 0xec10,
    TELUGU_L_GHEE = 0xec11,
    TELUGU_L_GHAU = 0xec12,

    TELUGU_L_NGI = 0xec13,
    TELUGU_L_NGII = 0xec14,

    /* Small Consonants */

    TELUGU_L_SMALL_KA = 0xec15,
    TELUGU_L_SMALL_KHA = 0xec16,
    TELUGU_L_SMALL_GA = 0xec17,
    TELUGU_L_SMALL_GHA = 0xec18,
    TELUGU_L_SMALL_NGA = 0xec19,
    TELUGU_L_SMALL_CA = 0xec1a,
    TELUGU_L_SMALL_CHA = 0xec1b,
    TELUGU_L_SMALL_JA = 0xec1c,
    TELUGU_L_SMALL_JHA = 0xec1d,
    TELUGU_L_SMALL_NYA = 0xec1e,
    TELUGU_L_SMALL_TTA = 0xec1f,
    TELUGU_L_SMALL_TTHA = 0xec20,
    TELUGU_L_SMALL_DDA = 0xec21,
    TELUGU_L_SMALL_DDHA = 0xec22,
    TELUGU_L_SMALL_NNA = 0xec23,
    TELUGU_L_SMALL_TA = 0xec24,
    TELUGU_L_SMALL_THA = 0xec25,
    TELUGU_L_SMALL_DA = 0xec26,
    TELUGU_L_SMALL_DHA = 0xec27,
    TELUGU_L_SMALL_NA = 0xec28,
    TELUGU_L_NGE = 0xec29,
    TELUGU_L_SMALL_PA = 0xec2a,
    TELUGU_L_SMALL_PHA = 0xec2b,
    TELUGU_L_SMALL_BA = 0xec2c,
    TELUGU_L_SMALL_BHA = 0xec2d,
    TELUGU_L_SMALL_MA = 0xec2e,

    TELUGU_L_SMALL_YA = 0xec2f,
    TELUGU_L_SMALL_RA = 0xec30,
    TELUGU_L_SMALL_RRA = 0xec31,
    TELUGU_L_SMALL_LA = 0xec32,
    TELUGU_L_SMALL_LLA = 0xec33,
    TELUGU_L_NGEE = 0xec34,
    TELUGU_L_SMALL_VA = 0xec35,
    TELUGU_L_SMALL_SHA = 0xec36,
    TELUGU_L_SMALL_SSA = 0xec37,
    TELUGU_L_SMALL_SA = 0xec38,
    TELUGU_L_SMALL_HA = 0xec39,

    TELUGU_L_NGO = 0xec3a,
    TELUGU_L_NGOO = 0xec3b,
    TELUGU_L_NGAU = 0xec3c,
    TELUGU_L_C_HALANT = 0xec3d,
    TELUGU_L_CAA = 0xec3e,
    TELUGU_L_CI = 0xec3f,
    TELUGU_L_CII = 0xec40,
    TELUGU_L_CE = 0xec41,
    TELUGU_L_CEE = 0xec42,
    TELUGU_L_CO = 0xec43,
    TELUGU_L_COO = 0xec44,
    TELUGU_L_CAU = 0xec45,

    TELUGU_L_CHAA = 0xec46,
    TELUGU_L_CHI = 0xec47,
    TELUGU_L_CHII = 0xec48,
    TELUGU_L_CHE = 0xec49,
    TELUGU_L_CHEE = 0xec4a,
    TELUGU_L_CHO = 0xec4b,
    TELUGU_L_CHOO = 0xec4c,
    TELUGU_L_CHAU = 0xec4d,
    TELUGU_L_CH_HALANT = 0xec4e,

    TELUGU_L_JI = 0xec4f,
    TELUGU_L_JII = 0xec50,
    TELUGU_L_JU = 0xec51,
    TELUGU_L_JE = 0xec52,
    TELUGU_L_JEE = 0xec53,
    TELUGU_L_JAU = 0xec54,
    TELUGU_L_JA_HALANT = 0xec55,
    TELUGU_L_JHA = 0xec56,
    TELUGU_L_JHAU = 0xec57,

    TELUGU_L_NYAA = 0xec58,
    TELUGU_L_NYI = 0xec59,
    TELUGU_L_NYII = 0xec5a,
    TELUGU_L_NYU = 0xec5b,
    TELUGU_L_NYE = 0xec5c,
    TELUGU_L_NYEE = 0xec5d,
    TELUGU_L_NYO = 0xec5e,
    TELUGU_L_NYOO = 0xec5f,
    TELUGU_L_NYAU = 0xec60,
    TELUGU_L_NY_HALANT = 0xec61,
    TELUGU_L_TTI = 0xec62,
    TELUGU_L_TTII = 0xec63,
    TELUGU_L_TTE = 0xec64,
    TELUGU_L_TTEE = 0xec65,
    TELUGU_L_TTO = 0xec66,
    TELUGU_L_TTOO = 0xec67,
    TELUGU_L_TTAU = 0xec68,
    TELUGU_L_TT_HALANT = 0xec69,
    TELUGU_L_TTHA = 0xec6a,
    TELUGU_L_TTHAA = 0xec6b,
    TELUGU_L_TTHAU = 0xec6c,
    TELUGU_L_DDA = 0xec6d,
    TELUGU_L_DDAA = 0xec6e,
    TELUGU_L_DDI = 0xec6f,
    TELUGU_L_DDII = 0xec70,
    TELUGU_L_DDO = 0xec71,
    TELUGU_L_DDOO = 0xec72,
    TELUGU_L_DDAU = 0xec73,
    TELUGU_L_DDHA = 0xec74,
    TELUGU_L_DDHAA = 0xec75,
    TELUGU_L_DDHI = 0xec76,
    TELUGU_L_DDHII = 0xec77,
    TELUGU_L_DDHO = 0xec78,
    TELUGU_L_DDHOO = 0xec79,
    TELUGU_L_DDHAU = 0xec7a,
    TELUGU_L_NNAA = 0xec7b,
    TELUGU_L_NNI = 0xec7c,
    TELUGU_L_NNII = 0xec7d,
    TELUGU_L_NNO = 0xec7e,
    TELUGU_L_NNOO = 0xec7f,
    TELUGU_L_NNAU = 0xec80,
    TELUGU_L_TA_HALANT = 0xec81,
    TELUGU_L_TAA = 0xec82,
    TELUGU_L_TI = 0xec83,
    TELUGU_L_TII = 0xec84,
    TELUGU_L_TE = 0xec85,
    TELUGU_L_TEE = 0xec86,
    TELUGU_L_TO = 0xec87,
    TELUGU_L_TOO = 0xec88,
    TELUGU_L_TAU = 0xec89,
    TELUGU_L_THA = 0xec8a,
    TELUGU_L_THAA = 0xec8b,
    TELUGU_L_THI = 0xec8c,
    TELUGU_L_THII = 0xec8d,
    TELUGU_L_THO = 0xec8e,
    TELUGU_L_THOO = 0xec8f,
    TELUGU_L_THAU = 0xec90,
    TELUGU_L_DA = 0xec91,
    TELUGU_L_DAA = 0xec92,
    TELUGU_L_DI = 0xec93,
    TELUGU_L_DII = 0xec94,
    TELUGU_L_DO = 0xec95,
    TELUGU_L_DOO = 0xec96,
    TELUGU_L_DAU = 0xec97,
    TELUGU_L_DHA = 0xec98,
    TELUGU_L_DHAA = 0xec99,
    TELUGU_L_DHI = 0xec9a,
    TELUGU_L_DHII = 0xec9b,
    TELUGU_L_DHO = 0xec9c,
    TELUGU_L_DHOO = 0xec9d,
    TELUGU_L_DHAU = 0xec9e,
    TELUGU_L_NA = 0xec9f,
    TELUGU_L_NAA = 0xeca0,
    TELUGU_L_NI = 0xeca1,
    TELUGU_L_NII = 0xeca2,
    TELUGU_L_PA = 0xeca3,
    TELUGU_L_PAA = 0xeca4,
    TELUGU_L_PU = 0xeca5,
    TELUGU_L_PUU = 0xeca6,
    TELUGU_L_PO = 0xeca7,
    TELUGU_L_POO = 0xeca8,
    TELUGU_L_PAU = 0xeca9,
    TELUGU_L_PHA = 0xecaa,
    TELUGU_L_PHAA = 0xecab,
    TELUGU_L_PHU = 0xecac,
    TELUGU_L_PHUU = 0xecad,
    TELUGU_L_PHO = 0xecae,
    TELUGU_L_PHOO = 0xecaf,
    TELUGU_L_PHAU = 0xecb0,
    TELUGU_L_BA_HALANT = 0xecb1,
    TELUGU_L_BAA = 0xecb2,
    TELUGU_L_BI = 0xecb3,
    TELUGU_L_BII = 0xecb4,
    TELUGU_L_BE = 0xecb5,
    TELUGU_L_BEE = 0xecb6,
    TELUGU_L_BO = 0xecb7,
    TELUGU_L_BOO = 0xecb8,
    TELUGU_L_BAU = 0xecb9,
    TELUGU_L_BHA_HALANT = 0xecba,
    TELUGU_L_BHAA = 0xecbb,
    TELUGU_L_BHI = 0xecbc,
    TELUGU_L_BHII = 0xecbd,
    TELUGU_L_BHE = 0xecbe,
    TELUGU_L_BHEE = 0xecbf,
    TELUGU_L_BHO = 0xecc0,
    TELUGU_L_BHOO = 0xecc1,
    TELUGU_L_BHAU = 0xecc2,
    TELUGU_L_MA = 0xecc3,
    TELUGU_L_MAU = 0xecc4,
    TELUGU_L_YA = 0xecc5,
    TELUGU_L_YE = 0xecc6,
    TELUGU_L_YEE = 0xecc7,
    TELUGU_L_YAU = 0xecc8,
    TELUGU_L_YA_HALANT = 0xecc9,
    TELUGU_L_RA = 0xecca,
    TELUGU_L_RAA = 0xeccb,
    TELUGU_L_RAU = 0xeccc,

    TELUGU_L_RRA_HALANT = 0xeccd,
    TELUGU_L_RRAA = 0xecce,
    TELUGU_L_RRI = 0xeccf,
    TELUGU_L_RRII = 0xecd0,
    TELUGU_L_RRE = 0xecd1,
    TELUGU_L_RREE = 0xecd2,
    TELUGU_L_RRO = 0xecd3,
    TELUGU_L_RROO = 0xecd4,
    TELUGU_L_RRAU = 0xecd5,
    TELUGU_L_LA_HALANT = 0xecd6,
    TELUGU_L_LAA = 0xecd7,
    TELUGU_L_LI = 0xecd8,
    TELUGU_L_LII = 0xecd9,
    TELUGU_L_LE = 0xecda,
    TELUGU_L_LEE = 0xecdb,
    TELUGU_L_LO = 0xecdc,
    TELUGU_L_LOO = 0xecdd,
    TELUGU_L_LAU = 0xecde,

    TELUGU_L_VA_HALANT = 0xecdf,
    TELUGU_L_VAA = 0xece0,
    TELUGU_L_VI = 0xece1,
    TELUGU_L_VII = 0xece2,
    TELUGU_L_VE = 0xece3,
    TELUGU_L_VEE = 0xece4,
    TELUGU_L_VO = 0xece5,
    TELUGU_L_VOO = 0xece6,
    TELUGU_L_VAU = 0xece7,

    TELUGU_L_SHA_HALANT = 0xece8,
    TELUGU_L_SHAA = 0xece9,
    TELUGU_L_SHI = 0xecea,
    TELUGU_L_SHII = 0xeceb,
    TELUGU_L_SHE = 0xecec,
    TELUGU_L_SHEE = 0xeced,
    TELUGU_L_SHO = 0xecee,
    TELUGU_L_SHOO = 0xecef,
    TELUGU_L_SHAU = 0xecf0,

    TELUGU_L_SSA_HALANT = 0xecf1,
    TELUGU_L_SSAA = 0xecf2,
    TELUGU_L_SSI = 0xecf3,
    TELUGU_L_SSII = 0xecf4,
    TELUGU_L_SSE = 0xecf5,
    TELUGU_L_SSEE = 0xecf6,
    TELUGU_L_SSO = 0xecf7,
    TELUGU_L_SSOO = 0xecf8,
    TELUGU_L_SSAU = 0xecf9,

    TELUGU_L_SA_HALANT = 0xecfa,
    TELUGU_L_SA = 0xecfb,
    TELUGU_L_SAA = 0xecfc,
    TELUGU_L_SO = 0xecfd,
    TELUGU_L_SOO = 0xecfe,
    TELUGU_L_SAU = 0xecff,
    TELUGU_L_HA = 0xed00,
    TELUGU_L_HAA = 0xed01,
    TELUGU_L_HO = 0xed02,
    TELUGU_L_HOO = 0xed03,
    TELUGU_L_LLA_HALANT = 0xed04,
    TELUGU_L_LLAA = 0xed05,
    TELUGU_L_LLI = 0xed06,
    TELUGU_L_LLII = 0xed07,
    TELUGU_L_LLE = 0xed08,
    TELUGU_L_LLEE = 0xed09,
    TELUGU_L_LLO = 0xed0a,
    TELUGU_L_LLOO = 0xed0b,
    TELUGU_L_LLAU = 0xed0c,

    TELUGU_L_KSHA = 0xed0d,
    TELUGU_L_KSHA_HALANT = 0xed0e,
    TELUGU_L_KO = 0xed0f,
    TELUGU_L_KOO = 0xed10,
    TELUGU_L_KAU = 0xed11,
    TELUGU_L_KA_HALANT = 0xed12,
    TELUGU_L_KHA_HALANT = 0xed13,
    TELUGU_L_GO = 0xed14,
    TELUGU_L_GOO = 0xed15,
    TELUGU_L_GAU = 0xed16,
    TELUGU_L_NYA_HALANT = 0xed17,
    TELUGU_L_JAA = 0xed18,
    TELUGU_L_JO = 0xed19,
    TELUGU_L_JOO = 0xed1a,
    TELUGU_L_TTHO = 0xed1b,
    TELUGU_L_TTHOO = 0xed1c,
    TELUGU_L_RO = 0xed1d,
    TELUGU_L_ROO = 0xed1e,
    TELUGU_L_HAU = 0xed1f,
    TELUGU_L_LLU = 0xed20,
    TELUGU_L_LLUU = 0xed21,
    TELUGU_L_VU = 0xed22,
    TELUGU_L_VUU = 0xed23,
    /* PMT START MAUI_00027829 */ 
    TELUGU_L_KU = 0xed24,
    TELUGU_L_KUU = 0xed25
     /* PMT END MAUI_00027829 */ 
    /* 7.24 PMT  END TELUGU & PUNJABI */

} telugu_ligatures_enum;

#if defined (__MMI_MULTITAP_TELUGU__)

extern const UI_character_type default_telugu_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_telugumatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_telugumatra1_multitap_strings[MAX_MULTITAPS][32];
/* PMT START ZI */
/* Code Removed */
/* PMT END ZI */

extern UI_character_type *get_telugu_multitap_string(S32 i);
extern UI_string_type get_telugu_single_line_multitap_string(S32);

#endif /* defined (__MMI_MULTITAP_TELUGU__) */ 
#endif /* defined (__MMI_LANG_TELUGU__) */ 
#endif /* MMI_TELUGU_H */ 

