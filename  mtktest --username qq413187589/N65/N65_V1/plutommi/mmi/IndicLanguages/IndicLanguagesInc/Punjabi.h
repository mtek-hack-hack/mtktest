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
 *    Punjabi.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   c file of punjabi font rule 
 *
 *
 * Author:
 * Rakesh Singh (mti00098)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_PUNJABI_H__
#define __MMI_PUNJABI_H__

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"

#if defined (__MMI_LANG_PUNJABI__)

#define IRE_PUNJABI_LANG_START_RANGE         0x0A00
#define IRE_PUNJABI_LANG_END_RANGE        0x0A74

#define IRE_PUNJABI_PROPRIETRY_START_RANGE   0xEAFF
#define IRE_PUNJABI_PROPRIETRY_END_RANGE     0xEB11

typedef enum
{
    /* VARIOUS SIGNS + INDEPENDENT VOWEL */
    PUNJABI_S_ADAK_BINDI = 0x0A01,
    PUNJABI_S_BINDI = 0x0A02,
    PUNJABI_S_VISARGA = 0x0A03,
    PUNJABI_IV_A = 0x0A05,
    PUNJABI_IV_AA = 0x0A06,
    PUNJABI_IV_I = 0x0A07,
    PUNJABI_IV_II = 0x0A08,
    PUNJABI_IV_U = 0x0A09,
    PUNJABI_IV_UU = 0x0A0a,
    PUNJABI_IV_EE = 0x0A0f,
    PUNJABI_IV_AI = 0x0A10,
    PUNJABI_IV_OO = 0x0A13,
    PUNJABI_IV_AU = 0x0A14,

    /* CONSONANTS */
    PUNJABI_C_KA = 0x0A15,
    PUNJABI_C_KHA = 0x0A16,
    PUNJABI_C_GA = 0x0A17,
    PUNJABI_C_GHA = 0x0A18,
    PUNJABI_C_NGA = 0x0A19,
    PUNJABI_C_CA = 0x0A1a,
    PUNJABI_C_CHA = 0x0A1b,
    PUNJABI_C_JA = 0x0A1c,
    PUNJABI_C_JHA = 0x0A1d,
    PUNJABI_C_NYA = 0x0A1e,
    PUNJABI_C_TTA = 0x0A1f,
    PUNJABI_C_TTHA = 0x0A20,
    PUNJABI_C_DDA = 0x0A21,
    PUNJABI_C_DDHA = 0x0A22,
    PUNJABI_C_NNA = 0x0A23,
    PUNJABI_C_TA = 0x0A24,
    PUNJABI_C_THA = 0x0A25,
    PUNJABI_C_DA = 0x0A26,
    PUNJABI_C_DHA = 0x0A27,
    PUNJABI_C_NA = 0x0A28,
    PUNJABI_C_PA = 0x0A2a,
    PUNJABI_C_PHA = 0x0A2b,
    PUNJABI_C_BA = 0x0A2c,
    PUNJABI_C_BHA = 0x0A2d,
    PUNJABI_C_MA = 0x0A2e,
    PUNJABI_C_YA = 0x0A2f,
    PUNJABI_C_RA = 0x0A30,
    PUNJABI_C_LA = 0x0A32,
    PUNJABI_C_LLA = 0x0A33,
    PUNJABI_C_VA = 0x0A35,
    PUNJABI_C_SHA = 0x0A36,
    PUNJABI_C_SA = 0x0A38,
    PUNJABI_C_HA = 0x0A39,

    /* SIGNS */
    PUNJABI_S_NUKTA = 0x0A3c,

    /* DEPENDENT VOWELS */
    PUNJABI_DV_AA = 0x0A3e,
    PUNJABI_DV_I = 0x0A3f,
    PUNJABI_DV_II = 0x0A40,
    PUNJABI_DV_U = 0x0A41,
    PUNJABI_DV_UU = 0x0A42,
    PUNJABI_DV_EE = 0x0A47,
    PUNJABI_DV_AI = 0x0A48,
    PUNJABI_DV_OO = 0x0A4b,
    PUNJABI_DV_AU = 0x0A4c,

    /* SIGNS */
    PUNJABI_S_HALANT = 0x0A4d,

    /* ADDITIONAL CONSONANT */
    PUNJABI_AC_KHHA = 0x0A59,
    PUNJABI_AC_GHHA = 0x0A5a,
    PUNJABI_AC_ZA = 0x0A5b,
    PUNJABI_AC_RRA = 0x0A5c,
    PUNJABI_AC_FA = 0x0A5e,
    /* MTI START MAUI_00030057 */
    PUNJABI_S_DANDA = 0x0A64,
    /* MTI END MAUI_00030057 */

    /* DIGITS */
    PUNJABI_D_ZERO = 0x0A66,
    PUNJABI_D_ONE = 0x0A67,
    PUNJABI_D_TWO = 0x0A68,
    PUNJABI_D_THREE = 0x0A69,
    PUNJABI_D_FOUR = 0x0A6a,
    PUNJABI_D_FIVE = 0x0A6b,
    PUNJABI_D_SIX = 0x0A6c,
    PUNJABI_D_SEVEN = 0x0A6d,
    PUNJABI_D_EIGHT = 0x0A6e,
    PUNJABI_D_NINE = 0x0A6f,

    /* PUNJABI SPECIFIC ADDITOIN */
    PUNJABI_AC_TIPPI = 0x0A70,
    PUNJABI_AC_ADDAK = 0x0A71,
    PUNJABI_AC_IRI = 0x0A72,
    PUNJABI_AC_URA = 0x0A73,
    PUNJABI_AC_ONKAR = 0x0A74
} punjabi_characters_enum;

typedef enum
{
    /* various half forms,ligature etc */
    PUNJABI_L_YA = 0xEB00,
    PUNJABI_L_HA = 0xEB01,
    PUNJABI_L_VA = 0xEB02,
    PUNJABI_L_RA = 0xEB03,
    PUNJABI_L_ADDAK = 0xEB04,
    PUNJABI_L_NCAND = 0xEB05,
    PUNJABI_L_NBINDU = 0xEB06,
    PUNJABI_L_IIBINDU = 0xEB07,
    /* MTI START MAUI_00035628 */
    PUNJABI_IV_I_TIPPI = 0xEB08,
    /* MTI END MAUI_00035628 */
    PUNJABI_L_OOBINDU = 0xEB09,
    PUNJABI_L_OOCBINDU = 0xEB0A,
    PUNJABI_L_EEBINDU = 0xEB0B,
    /* MTI START MAUI_00035628 */
    PUNJABI_IV_I_ADDAK = 0xEB0C,
    /* MTI END MAUI_00035628 */
    PUNJABI_L_AIBINDU = 0xEB0D,
    /* MTI START MAUI_00035628 */
    PUNJABI_IV_II_BINDI = 0xEB0E,
    /* MTI END MAUI_00035628 */
    PUNJABI_L_AUCBINDU = 0xEB0F,
    PUNJABI_L_AUBINDU = 0xEB10

} punjabi_ligatures_enum;

#if defined (__MMI_MULTITAP_PUNJABI__)
/* Following Arrays are used to insert character according to punjabi grammar rules */
/* PMT START ZI */
#if defined(__MMI_ZI_PUNJABI__)
    extern const UI_character_type default_punjabi_multitap_strings[MAX_MULTITAPS][45];
    extern const UI_character_type default_punjabimatra_multitap_strings[MAX_MULTITAPS][45];
    extern const UI_character_type default_punjabimatra1_multitap_strings[MAX_MULTITAPS][45];
    extern const UI_character_type default_punjabimatra2_multitap_strings[MAX_MULTITAPS][45];
#else
    extern const UI_character_type default_punjabi_multitap_strings[MAX_MULTITAPS][32];
    extern const UI_character_type default_punjabimatra_multitap_strings[MAX_MULTITAPS][32];
    extern const UI_character_type default_punjabimatra1_multitap_strings[MAX_MULTITAPS][32];
    extern const UI_character_type default_punjabimatra2_multitap_strings[MAX_MULTITAPS][32];
#endif
/* PMT END ZI */
extern UI_character_type *get_punjabi_multitap_string(S32 i);

#endif /* defined (__MMI_MULTITAP_PUNJABI__) */ 
#endif /* defined (__MMI_LANG_PUNJABI__) */ 

#endif /* __MMI_PUNJABI_H__ */ 

