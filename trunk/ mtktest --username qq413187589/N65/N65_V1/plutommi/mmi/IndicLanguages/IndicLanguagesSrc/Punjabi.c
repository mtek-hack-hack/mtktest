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
 *    Punjabi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   C file of punjabi font rule 
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
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "gui_data_types.h"
#include "IndicEngineGprot.h"

#if defined (__MMI_LANG_PUNJABI__)
#ifndef NULL
#define NULL   0
#endif 

const ire_character_info_table_struct punjabi_character_info_table[] = 
{
    /* INDEPENDENT VOWEL */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A01 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A02 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A03 */

    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A04 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A05 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A06 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A07 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A08 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A09 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A0A */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0B */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0C */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0D */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0E */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A0F */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A10 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A11 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A12 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A13 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A14 */

    /* CONSONANTS */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A15 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A16 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A17 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A18 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A19 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A1A */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A1B */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A1C */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A1D */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A1E */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A1F */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A20 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A21 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A22 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A23 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A24 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A25 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A26 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A27 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A28 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A29 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A2A */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A2B */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A2C */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A2D */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A2E */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A2F */
    /* MTI START MAUI_00030759 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A30 */
    /* MTI START MAUI_00030759 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A31 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A32 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A33 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A34 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A35 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A36 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A37 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A38 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A39 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A3A */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A3B */

    /* SIGNS */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A3C */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A3D */

    /* DEPENDENT VOWELS */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A3E */
    {0, IRE_PRE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0},   /* 0x0A3F */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0x0A40 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A41 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A42 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A43 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A44 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A45 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A46 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A47 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A48 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A49 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A4A */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A4B */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A4C */

    /* SIGNS */
    {0, 0, 0, IRE_HALANT_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A4D */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A4E */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A4F */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A50 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A51 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A52 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A53 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A54 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A55 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A56 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A57 */

    /* ADDITIONAL CONSONANT */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A58 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A59 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A5A */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A5B */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A5C */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A5D */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A5E */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A5F */

    /* GENERIC ADDITIONS */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A60 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A61 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A62 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A63 */
    /* MTI START MAUI_00030057 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0},   /* 0x0A64 */
    /* MTI END MAUI_00030057 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A65 */

    /* DIGITS */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A66 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A67 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A68 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A69 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A6A */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A6B */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A6C */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A6D */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A6E */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0},   /* 0x0A6F */

    /* DEVANAGARI SPECIFIC ADDITOIN */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A70 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0x0A71 */
    /* MTI START MAUI_00030758 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A72 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A73 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0x0A74 */
    /* MTI END MAUI_00030758 */
};

const ire_character_info_table_struct punjabi_ligature_info_table[] = 
{
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xEB00 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB01 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB02 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB03 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_PREBASE_POSITION, 0},      /* 0xEB04 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xEB05 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xEB06 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xEB07 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xEB08 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB09 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB0A */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB0B */
    /* MTI START MAUI_00035628 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},   /* 0xEB0C */
    /* MTI END MAUI_00035628 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB0D */
    /* MTI START MAUI_00035628 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},   /* 0xEB0E */
    /* MTI END MAUI_00035628 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB0F */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0},   /* 0xEB10 */
};

 /*    CONSONANT'S TABLES   */

const ire_glyph_info_table_struct PUNJABI_KA_Tbl[] = 
{

    /* KA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_KA, 0x0}, {PUNJABI_C_KA, 0x0}},
    /* KA + Halant -> KA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_KA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_KA, 0x0}},
    /* KA + Halant + Ya -> KYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_KA, PUNJABI_L_YA, 0x0}},
    /* KA + Halant + Ra -> KRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_KA, PUNJABI_L_RA, 0x0}},
    /* KA + Halant + Va -> KVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_KA, PUNJABI_L_VA, 0x0}},
    /* KA + Halant + Ha -> kkha */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_KA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_KHA_Tbl[] = 
{
    /* KHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_KHA, 0x0}, {PUNJABI_C_KHA, 0x0}},
    /* KHA + Halant -> KHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_KHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_KHA, 0x0}},
    /* KHA + Halant + Ya -> KHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_KHA, PUNJABI_L_YA, 0x0}},
    /* KHA + Halant + Ra -> KHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_KHA, PUNJABI_L_RA, 0x0}},
    /* KHA + Halant + Va -> KHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_KHA, PUNJABI_L_VA, 0x0}},
    /* KHA + Halant + Ha -> KHha */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_KHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_KHA, PUNJABI_L_HA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_GA_Tbl[] = 
{
    /* GA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_GA, 0x0}, {PUNJABI_C_GA, 0x0}},
    /* GA + Halant -> GA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_GA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_GA, 0x0}},
    /* GA + Halant + Ya -> GYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_GA, PUNJABI_L_YA, 0x0}},
    /* GA + Halant + Ra -> GRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_GA, PUNJABI_L_RA, 0x0}},
    /* GA + Halant + Va -> GVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_GA, PUNJABI_L_VA, 0x0}},
    /* GA + Halant + Ha -> GAha */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_GA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_GHA_Tbl[] = 
{
    /* GHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_GHA, 0x0}, {PUNJABI_C_GHA, 0x0}},
    /* GHA + Halant -> GHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_GHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_GHA, 0x0}},
    /* GHA + Halant + Ya -> GHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_GHA, PUNJABI_L_YA, 0x0}},
    /* GHA + Halant + RA -> ligature form of GHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_GHA, PUNJABI_L_RA, 0x0}},
    /* GHA + Halant + Va -> GHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_GHA, PUNJABI_L_VA, 0x0}},
    /* GHA + Halant + Ha -> GHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_GHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_GHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_NGA_Tbl[] = 
{
    /* NGA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NGA, 0x0}, {PUNJABI_C_NGA, 0x0}},
    /* NGA + Halant -> NGA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_NGA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_NGA, 0x0}},
    /* NGA + Halant + Ya -> NGYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NGA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_NGA, PUNJABI_L_YA, 0x0}},
    /* NGA + Halant + Ra -> NGRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NGA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_NGA, PUNJABI_L_RA, 0x0}},
    /* NGA + Halant + Va -> NGVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NGA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_NGA, PUNJABI_L_VA, 0x0}},
    /* NGA + Halant + Ha -> NGAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NGA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_NGA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_CA_Tbl[] = 
{
    /* CA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_CA, 0x0}, {PUNJABI_C_CA, 0x0}},
    /* CA + Halant -> CA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_CA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_CA, 0x0}},
    /* CA + Halant + Ya -> CYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_CA, PUNJABI_L_YA, 0x0}},
    /* CA + Halant + Ra -> CRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_CA, PUNJABI_L_RA, 0x0}},
    /* CA + Halant + Va -> CVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_CA, PUNJABI_L_VA, 0x0}},
    /* CA + Halant + Ha -> CAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_CA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_CHA_Tbl[] = 
{
    /* CHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_CHA, 0x0}, {PUNJABI_C_CHA, 0x0}},
    /* CHA + Halant -> CHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_CHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_CHA, 0x0}},
    /* CHA + Halant + Ya -> CHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_CHA, PUNJABI_L_YA, 0x0}},
    /* CHA + Halant + Ra -> CHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_CHA, PUNJABI_L_RA, 0x0}},
    /* CHA + Halant + Va -> CHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_CHA, PUNJABI_L_VA, 0x0}},
    /* CHA + Halant + Ha -> chaha */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_CHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_CHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_JA_Tbl[] = 
{
    /* JA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_JA, 0x0}, {PUNJABI_C_JA, 0x0}},
    /* JA + Halant -> JA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_JA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_JA, 0x0}},
    /* JA + Halant + Ya -> JYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_JA, PUNJABI_L_YA, 0x0}},
    /* JA + Halant + Ra -> JRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_JA, PUNJABI_L_RA, 0x0}},
    /* JA + Halant + Va -> JVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_JA, PUNJABI_L_VA, 0x0}},
    /* JA + Halant + Ha -> JAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_JA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_JHA_Tbl[] = 
{
    /* JHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_JHA, 0x0}, {PUNJABI_C_JHA, 0x0}},
    /* JHA + Halant -> JHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_JHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_JHA, 0x0}},
    /* JHA + Halant + Ya -> JHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_JHA, PUNJABI_L_YA, 0x0}},
    /* JHA + Halant + Ra -> JHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_JHA, PUNJABI_L_RA, 0x0}},
    /* JHA + Halant + Va -> JHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_JHA, PUNJABI_L_VA, 0x0}},
    /* JHA + Halant + Ha -> JHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_JHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_CHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_NYA_Tbl[] = 
{
    /* NYA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NYA, 0x0}, {PUNJABI_C_NYA, 0x0}},
    /* NYA + Halant -> NYA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_NYA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_NYA, 0x0}},
    /* NYA + Halant + Ya -> NYYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NYA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_NYA, PUNJABI_L_YA, 0x0}},
    /* NYA + Halant + Ra -> NYRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NYA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_NYA, PUNJABI_L_RA, 0x0}},
    /* NYA + Halant + Va -> NYVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NYA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_NYA, PUNJABI_L_VA, 0x0}},
    /* NYA + Halant + Ha -> NYAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NYA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_NYA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_TTA_Tbl[] = 
{
    /* TTA + space -> TTa */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_TTA, 0x0}, {PUNJABI_C_TTA, 0x0}},
    /* TTA + Halant -> TTA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_TTA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_TTA, 0x0}},
    /* TTA + Halant + Ya -> TTYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_TTA, PUNJABI_L_YA, 0x0}},
    /* TTA + Halant + Ra -> TTRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_TTA, PUNJABI_L_RA, 0x0}},
    /* TTA + Halant + Va -> TTVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_TTA, PUNJABI_L_VA, 0x0}},
    /* TTA + Halant + Ha -> TTAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_TTA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_TTHA_Tbl[] = 
{
    /* TTHA -> TTHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_TTHA, 0x0}, {PUNJABI_C_TTHA, 0x0}},
    /* TTHA + Halant -> TTHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_TTHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_TTHA, 0x0}},
    /* TTHA + Halant + Ya -> TTHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_TTHA, PUNJABI_L_YA, 0x0}},
    /* TTHA + Halant + Ra -> TTHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_TTHA, PUNJABI_L_RA, 0x0}},
    /* TTHA + Halant + Va -> TTHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_TTHA, PUNJABI_L_VA, 0x0}},
    /* TTHA + Halant + Ha -> TTHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TTHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_TTHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_DDA_Tbl[] = 
{
    /* DDA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DDA, 0x0}, {PUNJABI_C_DDA, 0x0}},
    /* DDA + Halant -> DDA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_DDA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_DDA, 0x0}},
    /* DDA + Halant + Ya -> DDYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_DDA, PUNJABI_L_YA, 0x0}},
    /* DDA + Halant + Ra -> DDRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_DDA, PUNJABI_L_RA, 0x0}},
    /* DDA + Halant + Va -> DDVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_DDA, PUNJABI_L_VA, 0x0}},
    /* DDA + Halant + Ha -> DDAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_DDA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_DDHA_Tbl[] = 
{
    /* DDHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DDHA, 0x0}, {PUNJABI_C_DDHA, 0x0}},
    /* DDHA + Halant -> DDHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_DDHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_DDHA, 0x0}},
    /* DDHA + Halant + Ya -> DDHAYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_DDHA, PUNJABI_L_YA, 0x0}},
    /* DDHA + Halant + Ra -> DDHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_DDHA, PUNJABI_L_RA, 0x0}},
    /* DDHA + Halant + Va -> DDHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_DDHA, PUNJABI_L_VA, 0x0}},
    /* DDHA + Halant + Ha -> DDHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DDHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_DDHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_NNA_Tbl[] = 
{
    /* NNA+ space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NNA, 0x0}, {PUNJABI_C_NNA, 0x0}},
    /* NNA + Halant -> NNA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_NNA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_NNA, 0x0}},
    /* NNA + Halant + Ya -> NNYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NNA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_NNA, PUNJABI_L_YA, 0x0}},
    /* NNA + Halant + Ra -> NNRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NNA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_NNA, PUNJABI_L_RA, 0x0}},
    /* NNA + Halant + Va -> NNVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NNA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_NNA, PUNJABI_L_VA, 0x0}},
    /* NNA + Halant + Ha -> NNAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NNA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_NNA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_TA_Tbl[] = 
{
    /* TA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_TA, 0x0}, {PUNJABI_C_TA, 0x0}},
    /* TA + Halant -> TA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_TA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_TA, 0x0}},
    /* TA + Halant + Ya -> TYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_TA, PUNJABI_L_YA, 0x0}},
    /* TA + Halant + Ra -> TRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_TA, PUNJABI_L_RA, 0x0}},
    /* TA + Halant + Va -> TVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_TA, PUNJABI_L_VA, 0x0}},
    /* TA + Halant + Ha -> TAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_TA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_TA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_THA_Tbl[] = 
{
    /* THA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_THA, 0x0}, {PUNJABI_C_THA, 0x0}},
    /* THA + Halant -> THA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_THA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_THA, 0x0}},
    /* THA + Halant + Ya -> THYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_THA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_THA, PUNJABI_L_YA, 0x0}},
    /* THA + Halant + Ra -> THRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_THA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_THA, PUNJABI_L_RA, 0x0}},
    /* THA + Halant + Va -> THVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_THA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_THA, PUNJABI_L_VA, 0x0}},
    /* THA + Halant + Ha -> THAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_THA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_THA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_DA_Tbl[] = 
{
    /* DA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DA, 0x0}, {PUNJABI_C_DA, 0x0}},
    /* DA + Halant -> DA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_DA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_DA, 0x0}},
    /* DA + Halant + Ya -> DYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_DA, PUNJABI_L_YA, 0x0}},
    /* DA + Halant + Ra -> DRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_DA, PUNJABI_L_RA, 0x0}},
    /* DA + Halant + Va -> DVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_DA, PUNJABI_L_VA, 0x0}},
    /* DA + Halant + Ha -> DAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_DA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_DHA_Tbl[] = 
{
    /* DHA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DHA, 0x0}, {PUNJABI_C_DHA, 0x0}},
    /* DHA + Halant -> DHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_DHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_DHA, 0x0}},
    /* DHA + Halant + Ya -> DHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_DHA, PUNJABI_L_YA, 0x0}},
    /* DHA + Halant + Ra -> DHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_DHA, PUNJABI_L_RA, 0x0}},
    /* DHA + Halant + Va -> DHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_DHA, PUNJABI_L_VA, 0x0}},
    /* DHA + Halant + Ha -> DHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_DHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_DHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_NA_Tbl[] = 
{
    /* NA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NA, 0x0}, {PUNJABI_C_NA, 0x0}},
    /* NA + Halant -> NA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_NA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_NA, 0x0}},
    /* NA + Halant + Ya -> NYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_NA, PUNJABI_L_YA, 0x0}},
    /* NA + Halant + Ra -> NRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_NA, PUNJABI_L_RA, 0x0}},
    /* NA + Halant + Va -> NVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_NA, PUNJABI_L_VA, 0x0}},
    /* NA + Halant + Ha -> NAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_NA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_NA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_PA_Tbl[] = 
{
    /* PA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_PA, 0x0}, {PUNJABI_C_PA, 0x0}},
    /* PA + Halant -> PA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_PA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_PA, 0x0}},
    /* PA + Halant + Ya -> PYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_PA, PUNJABI_L_YA, 0x0}},
    /* PA + Halant + Ra -> PRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_PA, PUNJABI_L_RA, 0x0}},
    /* PA + Halant + Va -> PVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_PA, PUNJABI_L_VA, 0x0}},
    /* PA + Halant + Ha -> PAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_PA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_PHA_Tbl[] = 
{
    /* PHA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_PHA, 0x0}, {PUNJABI_C_PHA, 0x0}},
    /* PHA + Halant -> PHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_PHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_PHA, 0x0}},
    /* PHA + Halant + Ya -> PHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_PHA, PUNJABI_L_YA, 0x0}},
    /* PHA + Halant + Ra -> PHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_PHA, PUNJABI_L_RA, 0x0}},
    /* PHA + Halant + Va -> PHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_PHA, PUNJABI_L_VA, 0x0}},
    /* PHA + Halant + Ha -> PHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_PHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_PHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_BA_Tbl[] = 
{
    /* BA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_BA, 0x0}, {PUNJABI_C_BA, 0x0}},
    /* BA + Halant -> BA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_BA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_BA, 0x0}},
    /* BA + Halant + Ya -> BYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_BA, PUNJABI_L_YA, 0x0}},
    /* BA + Halant + Ra -> BRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_BA, PUNJABI_L_RA, 0x0}},
    /* BA + Halant + Va -> BVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_BA, PUNJABI_L_VA, 0x0}},
    /* BA + Halant + Ha -> BAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_BA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_BHA_Tbl[] = 
{
    /* BHA  + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_BHA, 0x0}, {PUNJABI_C_BHA, 0x0}},
    /* BHA + Halant -> BHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_BHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_BHA, 0x0}},
    /* BHA + Halant + Ya -> BHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_BHA, PUNJABI_L_YA, 0x0}},
    /* BHA + Halant + Ra -> BHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_BHA, PUNJABI_L_RA, 0x0}},
    /* BHA + Halant + Va -> BHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_BHA, PUNJABI_L_VA, 0x0}},
    /* BHA + Halant + Ha -> BHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_BHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_BHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_MA_Tbl[] = 
{
    /* MA  + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_MA, 0x0}, {PUNJABI_C_MA, 0x0}},
    /* MA + Halant -> MA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_MA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_MA, 0x0}},
    /* MA + Halant + Ya -> MYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_MA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_MA, PUNJABI_L_YA, 0x0}},
    /* MA + Halant + Ra -> MRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_MA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_MA, PUNJABI_L_RA, 0x0}},
    /* MA + Halant + Va -> MVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_MA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_MA, PUNJABI_L_VA, 0x0}},
    /* MA + Halant + Ha -> MAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_MA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_MA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_YA_Tbl[] = 
{
    /* YA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_YA, 0x0}, {PUNJABI_C_YA, 0x0}},
    /* YA + Halant -> YA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_YA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_YA, 0x0}},
    /* YA + Halant + Ya -> YYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_YA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_YA, PUNJABI_L_YA, 0x0}},
    /* YA + Halant + Ra -> YRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_YA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_YA, PUNJABI_L_RA, 0x0}},
    /* YA + Halant + Va -> YVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_YA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_YA, PUNJABI_L_VA, 0x0}},
    /* YA + Halant + Ha -> YAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_YA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_YA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_RA_Tbl[] = 
{
    /* RA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_RA, 0x0}, {PUNJABI_C_RA, 0x0}},
    /* RA + Halant -> RA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_RA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_RA, 0x0}},
    /* RA + Halant + Ya -> RYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_RA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_RA, PUNJABI_L_YA, 0x0}},
    /* RA + Halant + Ra -> RRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_RA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_RA, PUNJABI_L_RA, 0x0}},
    /* RA + Halant + Va -> RVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_RA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_RA, PUNJABI_L_VA, 0x0}},
    /* RA + Halant + Ha -> RAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_RA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_RA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_LA_Tbl[] = 
{
    /* LA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_LA, 0x0}, {PUNJABI_C_LA, 0x0}},
    /* LA + Halant -> LA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_LA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_LA, 0x0}},
    /* LA + Halant + Ya -> LYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_LA, PUNJABI_L_YA, 0x0}},
    /* LA + Halant + Ra -> LRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_LA, PUNJABI_L_RA, 0x0}},
    /* LA + Halant + Va -> LVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_LA, PUNJABI_L_VA, 0x0}},
    /* LA + Halant + Ha -> LA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_LA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_LLA_Tbl[] = 
{
    /* LLA */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_LLA, 0x0}, {PUNJABI_C_LLA, 0x0}},
    /* LLA + Halant -> LLA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_LLA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_LLA, 0x0}},
    /* LLA + Halant + Ya -> LLYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LLA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_LLA, PUNJABI_L_YA, 0x0}},
    /* LLA + Halant + Ra -> LLRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LLA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_LLA, PUNJABI_L_RA, 0x0}},
    /* LLA + Halant + Va -> LLVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LLA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_LLA, PUNJABI_L_VA, 0x0}},
    /* LLA + Halant + Ha -> LLAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_LLA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_LLA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_VA_Tbl[] = 
{
    /* VA */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_VA, 0x0}, {PUNJABI_C_VA, 0x0}},
    /* VA + Halant -> VA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_VA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_VA, 0x0}},
    /* VA + Halant + Ya -> VYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_VA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_VA, PUNJABI_L_YA, 0x0}},
    /* VA + Halant + Ra -> VRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_VA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_VA, PUNJABI_L_RA, 0x0}},
    /* VA + Halant + Va -> VVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_VA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_VA, PUNJABI_L_VA, 0x0}},
    /* VA + Halant + Ha -> VAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_VA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_VA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_SHA_Tbl[] = 
{
    /* SHA */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_SHA, 0x0}, {PUNJABI_C_SHA, 0x0}},
    /* SHA + Halant -> SHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_SHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_SHA, 0x0}},
    /* SHA + Halant + Ya -> SHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_SHA, PUNJABI_L_YA, 0x0}},
    /* SHA + Halant + Ra -> SHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_SHA, PUNJABI_L_RA, 0x0}},
    /* SHA + Halant + Va -> SHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_SHA, PUNJABI_L_VA, 0x0}},
    /* SHA + Halant + Ha -> SHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_SHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_SA_Tbl[] = 
{
    /* SA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_SA, 0x0}, {PUNJABI_C_SA, 0x0}},
    /* SA + Halant -> SA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_SA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_SA, 0x0}},
    /* SA + Halant + Ya -> SYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_SA, PUNJABI_L_YA, 0x0}},
    /* SA + Halant + Ra -> SRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_SA, PUNJABI_L_RA, 0x0}},
    /* SA + Halant + Va -> SVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_SA, PUNJABI_L_VA, 0x0}},
    /* SA + Halant + Ha -> SAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_SA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_SA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_HA_Tbl[] = 
{
    /* HA + space  */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_HA, 0x0}, {PUNJABI_C_HA, 0x0}},
    /* HA + Halant -> HA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_C_HA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_C_HA, 0x0}},
    /* HA + Halant + Ya -> HYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_HA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_C_HA, PUNJABI_L_YA, 0x0}},
    /* HA + Halant + Ra -> HRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_HA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_C_HA, PUNJABI_L_RA, 0x0}},
    /* HA + Halant + Va -> HVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_HA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_C_HA, PUNJABI_L_VA, 0x0}},
    /* HA + Halant + Ha -> HA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_C_HA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_C_HA, PUNJABI_L_HA, 0x0}},

};

                           /* ADDITIONAL CONSONANT'S TABLE */

const ire_glyph_info_table_struct PUNJABI_KHHA_Tbl[] = 
{
    /* KHHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_KHHA, 0x0}, {PUNJABI_AC_KHHA, 0x0}},
    /* KHHA + Halant -> KHHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_AC_KHHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_AC_KHHA, 0x0}},
    /* KHHA + Halant + Ya -> KHHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_KHHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0},
     {PUNJABI_AC_KHHA, PUNJABI_L_YA, 0x0}},
    /* KHHA + Halant + Ra -> KHHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_KHHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0},
     {PUNJABI_AC_KHHA, PUNJABI_L_RA, 0x0}},
    /* KHHA + Halant + Va -> KHHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_KHHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0},
     {PUNJABI_AC_KHHA, PUNJABI_L_VA, 0x0}},
    /* KHHA + Halant + Ha -> KHHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_KHHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0},
     {PUNJABI_AC_KHHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_GHHA_Tbl[] = 
{
    /* GHHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_GHHA, 0x0}, {PUNJABI_AC_GHHA, 0x0}},
    /* GHHA + Halant -> GHHA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_AC_GHHA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_AC_GHHA, 0x0}},
    /* GHHA + Halant + Ya -> GHHYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_GHHA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0},
     {PUNJABI_AC_GHHA, PUNJABI_L_YA, 0x0}},
    /* GHHA + Halant + Ra -> GHHRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_GHHA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0},
     {PUNJABI_AC_GHHA, PUNJABI_L_RA, 0x0}},
    /* GHHA + Halant + Va -> GHHVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_GHHA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0},
     {PUNJABI_AC_GHHA, PUNJABI_L_VA, 0x0}},
    /* GHHA + Halant + Ha -> GHHAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_GHHA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0},
     {PUNJABI_AC_GHHA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_ZA_Tbl[] = 
{
    /* ZA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_ZA, 0x0}, {PUNJABI_AC_ZA, 0x0}},
    /* ZA + Halant -> ZA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_AC_ZA, 0x0}},
    /* ZA + Halant + Ya -> ZYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_AC_ZA, PUNJABI_L_YA, 0x0}},
    /* ZA + Halant + Ra -> ZRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_AC_ZA, PUNJABI_L_RA, 0x0}},
    /* ZA + Halant + Va -> ZVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_AC_ZA, PUNJABI_L_VA, 0x0}},
    /* ZA + Halant + Ha -> ZAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_AC_ZA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_RRA_Tbl[] = 
{
    /* RRA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_RRA, 0x0}, {PUNJABI_AC_RRA, 0x0}},
    /* RRA + Halant -> RRA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_AC_RRA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_AC_RRA, 0x0}},
    /* RRA + Halant + Ya -> RRYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_RRA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_AC_RRA, PUNJABI_L_YA, 0x0}},
    /* RRA + Halant + Ra -> RRRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_RRA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_AC_RRA, PUNJABI_L_RA, 0x0}},
    /* RRA + Halant + Va -> RRVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_RRA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_AC_RRA, PUNJABI_L_VA, 0x0}},
    /* RRA + Halant + Ha -> RRAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_RRA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_AC_RRA, PUNJABI_L_HA, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_FA_Tbl[] = 
{
    /* FA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_FA, 0x0}, {PUNJABI_AC_FA, 0x0}},
    /* FA + Halant -> FA */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_AC_FA, PUNJABI_S_HALANT, 0x0}, {PUNJABI_AC_FA, 0x0}},
    /* FA + Halant + Ya -> FYA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_FA, PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_AC_FA, PUNJABI_L_YA, 0x0}},
    /* FA + Halant + Ra -> FRA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_FA, PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_AC_FA, PUNJABI_L_RA, 0x0}},
    /* FA + Halant + Va -> FVA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_FA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_AC_FA, PUNJABI_L_VA, 0x0}},
    /* FA + Halant + Ha -> FAHA */
    {0, 3, 2, MMI_ALL_LANG, {PUNJABI_AC_FA, PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_AC_FA, PUNJABI_L_HA, 0x0}},

};

              /* VARIOUS SIGNS TABLES */
const ire_glyph_info_table_struct PUNJABI_ADAK_BINDU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_S_ADAK_BINDI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_BINDI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_BINDI, 0x0}, {PUNJABI_S_BINDI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_VISARGA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_VISARGA, 0x0}, {PUNJABI_S_VISARGA, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_NUKTA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_NUKTA, 0x0}, {PUNJABI_S_NUKTA, 0x0}}
};

                        /* INDEPENDENT VOWEL'S TABLE */

const ire_glyph_info_table_struct PUNJABI_A_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_A, 0x0}, {PUNJABI_IV_A, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_AA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_AA, 0x0}, {PUNJABI_IV_AA, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_I_Tbl[] = 
{
    /* MTI START MAUI_00035628 */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_I, 0x0}, {PUNJABI_IV_I, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_I, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_I_TIPPI, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_I, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_I_ADDAK, 0x0}}
    /* MTI END MAUI_00035628 */
};

const ire_glyph_info_table_struct PUNJABI_II_Tbl[] = 
{
    /* MTI START MAUI_00035628 */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_II, 0x0}, {PUNJABI_IV_II, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_II, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_II_BINDI, 0x0}}
    /* MTI END MAUI_00035628 */
};

const ire_glyph_info_table_struct PUNJABI_U_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_U, 0x0}, {PUNJABI_IV_U, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_UU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_UU, 0x0}, {PUNJABI_IV_UU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_EE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_EE, 0x0}, {PUNJABI_IV_EE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_AI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_AI, 0x0}, {PUNJABI_IV_AI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_OO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_OO, 0x0}, {PUNJABI_IV_OO, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_AU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_AU, 0x0}, {PUNJABI_IV_AU, 0x0}}
};

                      /* DEPENDENT VOWEL SIGN/MATRAS TABLES */

const ire_glyph_info_table_struct PUNJABI_MAA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_AA, 0x0}, {PUNJABI_DV_AA, 0x0}},
    /* MTI START MAUI_00035628 */
    /* CODE REMOVED */
    /* MTI START MAUI_00035628 */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_AA, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_NBINDU, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_I, 0x0}, {PUNJABI_DV_I, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MII_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_II, 0x0}, {PUNJABI_DV_II, 0x0}},
    /* MTI START MAUI_00035628 */
    /* CODE REMOVED */
    /* MTI START MAUI_00035628 */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_II, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_IIBINDU, 0x0}},

};

const ire_glyph_info_table_struct PUNJABI_MU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_U, 0x0}, {PUNJABI_DV_U, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_MUU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_UU, 0x0}, {PUNJABI_DV_UU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_MEE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_EE, 0x0}, {PUNJABI_DV_EE, 0x0}},
    /* MTI START MAUI_00035628 */
    /* CODE REMOVED */
    /* MTI START MAUI_00035628 */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_EE, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_EEBINDU, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MAI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_AI, 0x0}, {PUNJABI_DV_AI, 0x0}},
    /* MTI START MAUI_00035628 */
    /* CODE REMOVED */
    /* MTI START MAUI_00035628 */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_AI, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_AIBINDU, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MOO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_OO, 0x0}, {PUNJABI_DV_OO, 0x0}},
    /* MTI START MAUI_00035628 */
    /* CODE REMOVED */
    /* MTI START MAUI_00035628 */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_OO, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_OOBINDU, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MAU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_AU, 0x0}, {PUNJABI_DV_AU, 0x0}},
    /* MTI START MAUI_00035628 */
    /* CODE REMOVED */
    /* MTI START MAUI_00035628 */
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_AU, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_AUBINDU, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_HAL_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, 0x0}, {PUNJABI_S_HALANT, 0x0}}
};

/* MTI START MAUI_00030057 */
const ire_glyph_info_table_struct PUNJABI_DANDA_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_DANDA, 0x0}, {PUNJABI_S_DANDA, 0x0}}

};
/* MTI END MAUI_00030057 */
                       /* NUMERALS TABLE */
const ire_glyph_info_table_struct PUNJABI_ZERO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_ZERO, 0x0}, {PUNJABI_D_ZERO, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_ONE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_ONE, 0x0}, {PUNJABI_D_ONE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_TWO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_TWO, 0x0}, {PUNJABI_D_TWO, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_THREE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_THREE, 0x0}, {PUNJABI_D_THREE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_FOUR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_FOUR, 0x0}, {PUNJABI_D_FOUR, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_FIVE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_FIVE, 0x0}, {PUNJABI_D_FIVE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_SIX_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_SIX, 0x0}, {PUNJABI_D_SIX, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_SEVEN_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_SEVEN, 0x0}, {PUNJABI_D_SEVEN, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_EIGHT_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_EIGHT, 0x0}, {PUNJABI_D_EIGHT, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_NINE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_NINE, 0x0}, {PUNJABI_D_NINE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_TIPPI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_AC_TIPPI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_ADDAK_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_AC_ADDAK, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_IRI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_IRI, 0x0}, {PUNJABI_AC_IRI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_URA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_URA, 0x0}, {PUNJABI_AC_URA, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_ONKAR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_ONKAR, 0x0}, {PUNJABI_AC_ONKAR, 0x0}}
};

const ire_main_glyph_table_struct PunjabiTbl[] = 
{
    /* VARIOUS SIGNS */
    {PUNJABI_ADAK_BINDU_Tbl, sizeof(PUNJABI_ADAK_BINDU_Tbl) / sizeof(PUNJABI_ADAK_BINDU_Tbl[0]), 1}     /* 0x0A01 */
    ,
    {PUNJABI_BINDI_Tbl, sizeof(PUNJABI_BINDI_Tbl) / sizeof(PUNJABI_BINDI_Tbl[0]), 1}    /* 0x0A02 */
    ,
    {PUNJABI_VISARGA_Tbl, sizeof(PUNJABI_VISARGA_Tbl) / sizeof(PUNJABI_VISARGA_Tbl[0]), 1}      /* 0x0A03 */
    ,
    {NULL, 0, 0}    /* 0x0A04 */
    ,
    /* INDEPENDENT VOWELS */
    {PUNJABI_A_Tbl, sizeof(PUNJABI_A_Tbl) / sizeof(PUNJABI_A_Tbl[0]), 1}        /* 0x0A05 */
    ,
    {PUNJABI_AA_Tbl, sizeof(PUNJABI_AA_Tbl) / sizeof(PUNJABI_AA_Tbl[0]), 1}     /* 0x0A06 */
    ,
    /* MTI START MAUI_00035628 */
    {PUNJABI_I_Tbl, sizeof(PUNJABI_I_Tbl) / sizeof(PUNJABI_I_Tbl[0]), 2}        /* 0x0A07 */
    /* MTI END MAUI_00035628 */
    ,
    /* MTI START MAUI_00035628 */
    {PUNJABI_II_Tbl, sizeof(PUNJABI_II_Tbl) / sizeof(PUNJABI_II_Tbl[0]), 2}     /* 0x0A08 */
    /* MTI END MAUI_00035628 */
    ,
    {PUNJABI_U_Tbl, sizeof(PUNJABI_U_Tbl) / sizeof(PUNJABI_U_Tbl[0]), 1}        /* 0x0A09 */
    ,
    {PUNJABI_UU_Tbl, sizeof(PUNJABI_UU_Tbl) / sizeof(PUNJABI_UU_Tbl[0]), 1}     /* 0x0A0A */
    ,
    {NULL, 0, 0}    /* 0x0A0B */
    ,
    {NULL, 0, 0}    /* 0x0A0C */
    ,
    {NULL, 0, 0}    /* 0x0A0D */
    ,
    {NULL, 0, 0}    /* 0x0A0E */
    ,
    {PUNJABI_EE_Tbl, sizeof(PUNJABI_EE_Tbl) / sizeof(PUNJABI_EE_Tbl[0]), 1}     /* 0x0A0F */
    ,
    {PUNJABI_AI_Tbl, sizeof(PUNJABI_AI_Tbl) / sizeof(PUNJABI_AI_Tbl[0]), 1}     /* 0x0A10 */
    ,
    {NULL, 0, 0}    /* 0x0A11 */
    ,
    {NULL, 0, 0}    /* 0x0A12 */
    ,
    {PUNJABI_OO_Tbl, sizeof(PUNJABI_OO_Tbl) / sizeof(PUNJABI_OO_Tbl[0]), 1}     /* 0x0A13 */
    ,
    {PUNJABI_AU_Tbl, sizeof(PUNJABI_AU_Tbl) / sizeof(PUNJABI_AU_Tbl[0]), 1}     /* 0x0A14 */
    ,
    /* CONSONANTS */
    {PUNJABI_KA_Tbl, sizeof(PUNJABI_KA_Tbl) / sizeof(PUNJABI_KA_Tbl[0]), 3}     /* 0x0A15 */
    ,
    {PUNJABI_KHA_Tbl, sizeof(PUNJABI_KHA_Tbl) / sizeof(PUNJABI_KHA_Tbl[0]), 3}  /* 0x0A16 */
    ,
    {PUNJABI_GA_Tbl, sizeof(PUNJABI_GA_Tbl) / sizeof(PUNJABI_GA_Tbl[0]), 3}     /* 0x0A17 */
    ,
    {PUNJABI_GHA_Tbl, sizeof(PUNJABI_GHA_Tbl) / sizeof(PUNJABI_GHA_Tbl[0]), 3}  /* 0x0A18 */
    ,
    {PUNJABI_NGA_Tbl, sizeof(PUNJABI_NGA_Tbl) / sizeof(PUNJABI_NGA_Tbl[0]), 3}  /* 0x0A19 */
    ,
    {PUNJABI_CA_Tbl, sizeof(PUNJABI_CA_Tbl) / sizeof(PUNJABI_CA_Tbl[0]), 3}     /* 0x0A1A */
    ,
    {PUNJABI_CHA_Tbl, sizeof(PUNJABI_CHA_Tbl) / sizeof(PUNJABI_CHA_Tbl[0]), 3}  /* 0x0A1B */
    ,
    {PUNJABI_JA_Tbl, sizeof(PUNJABI_JA_Tbl) / sizeof(PUNJABI_JA_Tbl[0]), 3}     /* 0x0A1C */
    ,
    {PUNJABI_JHA_Tbl, sizeof(PUNJABI_JHA_Tbl) / sizeof(PUNJABI_JHA_Tbl[0]), 3}  /* 0x0A1D */
    ,
    {PUNJABI_NYA_Tbl, sizeof(PUNJABI_NYA_Tbl) / sizeof(PUNJABI_NYA_Tbl[0]), 3}  /* 0x0A1E */
    ,
    {PUNJABI_TTA_Tbl, sizeof(PUNJABI_TTA_Tbl) / sizeof(PUNJABI_TTA_Tbl[0]), 3}  /* 0x0A1F */
    ,
    {PUNJABI_TTHA_Tbl, sizeof(PUNJABI_TTHA_Tbl) / sizeof(PUNJABI_TTHA_Tbl[0]), 3}       /* 0x0A20 */
    ,
    {PUNJABI_DDA_Tbl, sizeof(PUNJABI_DDA_Tbl) / sizeof(PUNJABI_DDA_Tbl[0]), 3}  /* 0x0A21 */
    ,
    {PUNJABI_DDHA_Tbl, sizeof(PUNJABI_DDHA_Tbl) / sizeof(PUNJABI_DDHA_Tbl[0]), 3}       /* 0x0A22 */
    ,
    {PUNJABI_NNA_Tbl, sizeof(PUNJABI_NNA_Tbl) / sizeof(PUNJABI_NNA_Tbl[0]), 3}  /* 0x0A23 */
    ,
    {PUNJABI_TA_Tbl, sizeof(PUNJABI_TA_Tbl) / sizeof(PUNJABI_TA_Tbl[0]), 3}     /* 0x0A24 */
    ,
    {PUNJABI_THA_Tbl, sizeof(PUNJABI_THA_Tbl) / sizeof(PUNJABI_THA_Tbl[0]), 3}  /* 0x0A25 */
    ,
    {PUNJABI_DA_Tbl, sizeof(PUNJABI_DA_Tbl) / sizeof(PUNJABI_DA_Tbl[0]), 3}     /* 0x0A26 */
    ,
    {PUNJABI_DHA_Tbl, sizeof(PUNJABI_DHA_Tbl) / sizeof(PUNJABI_DHA_Tbl[0]), 3}  /* 0x0A27 */
    ,
    {PUNJABI_NA_Tbl, sizeof(PUNJABI_NA_Tbl) / sizeof(PUNJABI_NA_Tbl[0]), 3}     /* 0x0A28 */
    ,
    {NULL, 0, 0}    /* 0x0A29 */
    ,
    {PUNJABI_PA_Tbl, sizeof(PUNJABI_PA_Tbl) / sizeof(PUNJABI_PA_Tbl[0]), 3}     /* 0x0A2A */
    ,
    {PUNJABI_PHA_Tbl, sizeof(PUNJABI_PHA_Tbl) / sizeof(PUNJABI_PHA_Tbl[0]), 3}  /* 0x0A2B */
    ,
    {PUNJABI_BA_Tbl, sizeof(PUNJABI_BA_Tbl) / sizeof(PUNJABI_BA_Tbl[0]), 3}     /* 0x0A2C */
    ,
    {PUNJABI_BHA_Tbl, sizeof(PUNJABI_BHA_Tbl) / sizeof(PUNJABI_BHA_Tbl[0]), 3}  /* 0x0A2D */
    ,
    {PUNJABI_MA_Tbl, sizeof(PUNJABI_MA_Tbl) / sizeof(PUNJABI_MA_Tbl[0]), 3}     /* 0x0A2E */
    ,
    {PUNJABI_YA_Tbl, sizeof(PUNJABI_YA_Tbl) / sizeof(PUNJABI_YA_Tbl[0]), 3}     /* 0x0A2F */
    ,
    {PUNJABI_RA_Tbl, sizeof(PUNJABI_RA_Tbl) / sizeof(PUNJABI_RA_Tbl[0]), 3}     /* 0x0A30 */
    ,
    {NULL, 0, 0}    /* 0x0A31 */
    ,
    {PUNJABI_LA_Tbl, sizeof(PUNJABI_LA_Tbl) / sizeof(PUNJABI_LA_Tbl[0]), 3}     /* 0x0A32 */
    ,
    {PUNJABI_LLA_Tbl, sizeof(PUNJABI_LLA_Tbl) / sizeof(PUNJABI_LLA_Tbl[0]), 3}  /* 0x0A33 */
    ,
    {NULL, 0, 0}    /* 0x0A34 */
    ,
    {PUNJABI_VA_Tbl, sizeof(PUNJABI_VA_Tbl) / sizeof(PUNJABI_VA_Tbl[0]), 3}     /* 0x0A35 */
    ,
    {PUNJABI_SHA_Tbl, sizeof(PUNJABI_SHA_Tbl) / sizeof(PUNJABI_SHA_Tbl[0]), 3}  /* 0x0A36 */
    ,
    {NULL, 0, 0}    /* 0x0A37 */
    ,
    {PUNJABI_SA_Tbl, sizeof(PUNJABI_SA_Tbl) / sizeof(PUNJABI_SA_Tbl[0]), 3}     /* 0x0A38 */
    ,
    {PUNJABI_HA_Tbl, sizeof(PUNJABI_HA_Tbl) / sizeof(PUNJABI_HA_Tbl[0]), 3}     /* 0x0A39 */
    ,
    {NULL, 0, 0}    /* 0x0A3A */
    ,
    {NULL, 0, 0}    /* 0x0A3B */
    ,
    /* VARIOUS SIGNS */
    {PUNJABI_NUKTA_Tbl, sizeof(PUNJABI_NUKTA_Tbl) / sizeof(PUNJABI_NUKTA_Tbl[0]), 1}    /* 0x0A3C */
    ,
    {NULL, 0, 0}    /* 0x0A3D */
    ,
    /* DEPENDENT VOWEL SIGNS */
    {PUNJABI_MAA_Tbl, sizeof(PUNJABI_MAA_Tbl) / sizeof(PUNJABI_MAA_Tbl[0]), 2}  /* 0x0A3E */
    ,
    {PUNJABI_MI_Tbl, sizeof(PUNJABI_MI_Tbl) / sizeof(PUNJABI_MI_Tbl[0]), 1}     /* 0x0A3F */
    ,
    {PUNJABI_MII_Tbl, sizeof(PUNJABI_MII_Tbl) / sizeof(PUNJABI_MII_Tbl[0]), 2}  /* 0x0A40 */
    ,
    {PUNJABI_MU_Tbl, sizeof(PUNJABI_MU_Tbl) / sizeof(PUNJABI_MU_Tbl[0]), 1}     /* 0x0A41 */
    ,
    {PUNJABI_MUU_Tbl, sizeof(PUNJABI_MUU_Tbl) / sizeof(PUNJABI_MUU_Tbl[0]), 1}  /* 0x0A42 */
    ,
    {NULL, 0, 0}    /* 0x0A43 */
    ,
    {NULL, 0, 0}    /* 0x0A44 */
    ,
    {NULL, 0, 0}    /* 0x0A45 */
    ,
    {NULL, 0, 0}    /* 0x0A46 */
    ,
    {PUNJABI_MEE_Tbl, sizeof(PUNJABI_MEE_Tbl) / sizeof(PUNJABI_MEE_Tbl[0]), 2}  /* 0x0A47 */
    ,
    {PUNJABI_MAI_Tbl, sizeof(PUNJABI_MAI_Tbl) / sizeof(PUNJABI_MAI_Tbl[0]), 2}  /* 0x0A48 */
    ,
    {NULL, 0, 0}    /* 0x0A49 */
    ,
    {NULL, 0, 0}    /* 0x0A4A */
    ,
    {PUNJABI_MOO_Tbl, sizeof(PUNJABI_MOO_Tbl) / sizeof(PUNJABI_MOO_Tbl[0]), 2}  /* 0x0A4B */
    ,
    {PUNJABI_MAU_Tbl, sizeof(PUNJABI_MAU_Tbl) / sizeof(PUNJABI_MAU_Tbl[0]), 2}  /* 0x0A4C */
    ,
    /* VARIOUS SIGNS */
    {PUNJABI_HAL_Tbl, sizeof(PUNJABI_HAL_Tbl) / sizeof(PUNJABI_HAL_Tbl[0]), 1}  /* 0x0A4D */
    ,
    {NULL, 0, 0}    /* 0x0A4E */
    ,
    {NULL, 0, 0}    /* 0x0A4F */
    ,
    {NULL, 0, 0}    /* 0x0A50 */
    ,
    {NULL, 0, 0}    /* 0x0A51 */
    ,
    {NULL, 0, 0}    /* 0x0A52 */
    ,
    {NULL, 0, 0}    /* 0x0A53 */
    ,
    {NULL, 0, 0}    /* 0x0A54 */
    ,
    {NULL, 0, 0}    /* 0x0A55 */
    ,
    {NULL, 0, 0}    /* 0x0A56 */
    ,
    {NULL, 0, 0}    /* 0x0A57 */
    ,
    {NULL, 0, 0}    /* 0x0A58 */
    ,
    /* ADDITIONAL CONSONANTS */
    {PUNJABI_KHHA_Tbl, sizeof(PUNJABI_KHHA_Tbl) / sizeof(PUNJABI_KHHA_Tbl[0]), 3}       /* 0x0A59 */
    ,
    {PUNJABI_GHHA_Tbl, sizeof(PUNJABI_GHHA_Tbl) / sizeof(PUNJABI_GHHA_Tbl[0]), 3}       /* 0x0A5A */
    ,
    {PUNJABI_ZA_Tbl, sizeof(PUNJABI_ZA_Tbl) / sizeof(PUNJABI_ZA_Tbl[0]), 3}     /* 0x0A5B */
    ,
    {PUNJABI_RRA_Tbl, sizeof(PUNJABI_RRA_Tbl) / sizeof(PUNJABI_RRA_Tbl[0]), 3}  /* 0x0A5C */
    ,
    {NULL, 0, 0}    /* 0x0A5D */
    ,
    {PUNJABI_FA_Tbl, sizeof(PUNJABI_FA_Tbl) / sizeof(PUNJABI_FA_Tbl[0]), 3}     /* 0x0A5E */
    ,
    {NULL, 0, 0}    /* 0x0A5F */
    ,
    {NULL, 0, 0}    /* 0x0A60 */
    ,
    {NULL, 0, 0}    /* 0x0A61 */
    ,
    {NULL, 0, 0}    /* 0x0A62 */
    ,
    {NULL, 0, 0}    /* 0x0A63 */
    ,
/* MTI START MAUI_00030057 */
    {PUNJABI_DANDA_Tbl, sizeof(PUNJABI_DANDA_Tbl) / sizeof(PUNJABI_DANDA_Tbl[0]), 1}                        //0x0A64
/* MTI END MAUI_00030057 */
    ,
    {NULL, 0, 0}    /* 0x0A65 */
    ,
    /* DIGITS */
    {PUNJABI_ZERO_Tbl, sizeof(PUNJABI_ZERO_Tbl) / sizeof(PUNJABI_ZERO_Tbl[0]), 1}       /* 0x0A66 */
    ,
    {PUNJABI_ONE_Tbl, sizeof(PUNJABI_ONE_Tbl) / sizeof(PUNJABI_ONE_Tbl[0]), 1}  /* 0x0A67 */
    ,
    {PUNJABI_TWO_Tbl, sizeof(PUNJABI_TWO_Tbl) / sizeof(PUNJABI_TWO_Tbl[0]), 1}  /* 0x0A68 */
    ,
    {PUNJABI_THREE_Tbl, sizeof(PUNJABI_THREE_Tbl) / sizeof(PUNJABI_THREE_Tbl[0]), 1}    /* 0x0A69 */
    ,
    {PUNJABI_FOUR_Tbl, sizeof(PUNJABI_FOUR_Tbl) / sizeof(PUNJABI_FOUR_Tbl[0]), 1}       /* 0x0A6A */
    ,
    {PUNJABI_FIVE_Tbl, sizeof(PUNJABI_FIVE_Tbl) / sizeof(PUNJABI_FIVE_Tbl[0]), 1}       /* 0x0A6B */
    ,
    {PUNJABI_SIX_Tbl, sizeof(PUNJABI_SIX_Tbl) / sizeof(PUNJABI_SIX_Tbl[0]), 1}  /* 0x0A6C */
    ,
    {PUNJABI_SEVEN_Tbl, sizeof(PUNJABI_SEVEN_Tbl) / sizeof(PUNJABI_SEVEN_Tbl[0]), 1}    /* 0x0A6D */
    ,
    {PUNJABI_EIGHT_Tbl, sizeof(PUNJABI_EIGHT_Tbl) / sizeof(PUNJABI_EIGHT_Tbl[0]), 1}    /* 0x0A6E */
    ,
    {PUNJABI_NINE_Tbl, sizeof(PUNJABI_NINE_Tbl) / sizeof(PUNJABI_NINE_Tbl[0]), 1}       /* 0x0A6F */
    ,
    /* SPECIFIC ADDITIONS */
    {PUNJABI_TIPPI_Tbl, sizeof(PUNJABI_TIPPI_Tbl) / sizeof(PUNJABI_TIPPI_Tbl[0]), 1}    /* 0x0A70 */
    ,
    {PUNJABI_ADDAK_Tbl, sizeof(PUNJABI_ADDAK_Tbl) / sizeof(PUNJABI_ADDAK_Tbl[0]), 1}    /* 0x0A71 */
    ,
    {PUNJABI_IRI_Tbl, sizeof(PUNJABI_IRI_Tbl) / sizeof(PUNJABI_IRI_Tbl[0]), 1}  /* 0x0A72 */
    ,
    {PUNJABI_URA_Tbl, sizeof(PUNJABI_URA_Tbl) / sizeof(PUNJABI_URA_Tbl[0]), 1}  /* 0x0A73 */
    ,
    {PUNJABI_ONKAR_Tbl, sizeof(PUNJABI_ONKAR_Tbl) / sizeof(PUNJABI_ONKAR_Tbl[0]), 1}    /* 0x0A74 */

};

#if defined (__MMI_MULTITAP_PUNJABI__)

/* PMT START ZI */
#if defined (__MMI_ZI_PUNJABI__)

const UI_character_type default_punjabi_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, 0x002e, 0x002c, 0x003f, 0x0021, '1', 0x0040, 0x0027, 0x0022, 0x002d, 0x0028, 0x0029, 0x002f, 0x003a, 0x005f, 0x003b, 0x002b, 0x0026, 0x0025, 0x002a, 0x003d, 0x003c, 0x003e, 0x20ac, 0x00a3, 0x0024, 0x00a5, 0x00a4, 0x005b, 0x005d, 0x007b, 0x007d, 0x005c, 0x007e, 0x005e, 0x00bf, 0x00a1, 0x00a7, 0x0023, '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, '2', '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, '3', '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_AC_ZA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, 0x002e, 0x002c, 0x003f, 0x0021, '1', 0x0040, 0x0027, 0x0022, 0x002d, 0x0028, 0x0029, 0x002f, 0x003a, 0x005f, 0x003b, 0x002b, 0x0026, 0x0025, 0x002a, 0x003d, 0x003c, 0x003e, 0x20ac, 0x00a3, 0x0024, 0x00a5, 0x00a4, 0x005b, 0x005d, 0x007b, 0x007d, 0x005c, 0x007e, 0x005e, 0x00bf, 0x00a1, 0x00a7, 0x0023, PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, PUNJABI_S_HALANT, '1', '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_DV_AA, PUNJABI_DV_I, PUNJABI_DV_II, PUNJABI_DV_U, PUNJABI_DV_UU, '2', '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_DV_EE, PUNJABI_DV_AI, PUNJABI_DV_OO, PUNJABI_DV_AU, '3', '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_AC_ZA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra1_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, 0x002e, 0x002c, 0x003f, 0x0021, '1', 0x0040, 0x0027, 0x0022, 0x002d, 0x0028, 0x0029, 0x002f, 0x003a, 0x005f, 0x003b, 0x002b, 0x0026, 0x0025, 0x002a, 0x003d, 0x003c, 0x003e, 0x20ac, 0x00a3, 0x0024, 0x00a5, 0x00a4, 0x005b, 0x005d, 0x007b, 0x007d, 0x005c, 0x007e, 0x005e, 0x00bf, 0x00a1, 0x00a7, 0x0023, PUNJABI_S_BINDI, '1', '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, '2', '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, '3', '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_AC_ZA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_punjabimatra2_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, 0x002e, 0x002c, 0x003f, 0x0021, '1', 0x0040, 0x0027, 0x0022, 0x002d, 0x0028, 0x0029, 0x002f, 0x003a, 0x005f, 0x003b, 0x002b, 0x0026, 0x0025, 0x002a, 0x003d, 0x003c, 0x003e, 0x20ac, 0x00a3, 0x0024, 0x00a5, 0x00a4, 0x005b, 0x005d, 0x007b, 0x007d, 0x005c, 0x007e, 0x005e, 0x00bf, 0x00a1, 0x00a7, 0x0023, PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, PUNJABI_S_HALANT, '1', '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, '2', '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, '3', '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_AC_ZA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#else
/* PMT END ZI */

const UI_character_type default_punjabi_multitap_strings[MAX_MULTITAPS][32] = 
{

/* MTI START MAUI_00030057 */
    {' ', PUNJABI_S_DANDA, PUNJABI_D_ZERO, '0', '\0'},   /* key 0 */
/* MTI END MAUI_00030057 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    /* MTI START MAUI_00030758 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_D_EIGHT, '8', '\0'},       /* key 8 */
    {PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},        /* key 9 */
    /* MTI END MAUI_00030758 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra_multitap_strings[MAX_MULTITAPS][32] = 
{
/* MTI START MAUI_00030057 */
    {' ', PUNJABI_S_DANDA, PUNJABI_D_ZERO, '0', '\0'},   /* key 0 */
/* MTI END MAUI_00030057 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    /* MTI START MAUI_00030758 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_DV_AA, PUNJABI_DV_I, PUNJABI_DV_II, PUNJABI_DV_U, PUNJABI_DV_UU, PUNJABI_DV_EE, PUNJABI_DV_AI, PUNJABI_DV_OO, PUNJABI_DV_AU, PUNJABI_D_EIGHT, '8', '\0'},  /* key 8 */
/* MTI START MAUI_00030568 */
    {PUNJABI_S_VISARGA, PUNJABI_S_HALANT, PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},        /* key 9 */
    /* MTI END MAUI_00030758 */
/* MTI END MAUI_00030568 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
/* MTI START MAUI_00030057 */
    {' ', PUNJABI_S_DANDA, PUNJABI_D_ZERO, '0', '\0'},   /* key 0 */
/* MTI END MAUI_00030057 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    /* MTI START MAUI_00030758 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_D_EIGHT, '8', '\0'},       /* key 8 */
/* MTI START MAUI_00030568 */
    {PUNJABI_S_BINDI, PUNJABI_S_VISARGA, PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},      /* key 9 */
    /* MTI END MAUI_00030758 */
/* MTI END MAUI_00030568 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* MTI START MAUI_00030568 */
const UI_character_type default_punjabimatra2_multitap_strings[MAX_MULTITAPS][32] = 
{
/* MTI START MAUI_00030057 */
    {' ', PUNJABI_S_DANDA, PUNJABI_D_ZERO, '0', '\0'},   /* key 0 */
/* MTI END MAUI_00030057 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    /* MTI START MAUI_00030758 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_D_EIGHT, '8', '\0'},       /* key 8 */
    {PUNJABI_S_VISARGA, PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},      /* key 9 */
    /* MTI END MAUI_00030758 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* PMT START ZI */
#endif
/* PMT END ZI */

/*****************************************************************************
 * FUNCTION
 *  get_punjabi_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_punjabi_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*PMT START MAUI_00530728 */
    switch(ire_current_input_box_type())
    {
        case 1:
            previous_char = gui_multi_line_current_character(&MMI_multiline_inputbox);
            break;
        case 2:
            previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
            break;
        case 3:
            previous_char = gui_single_line_current_character(&MMI_inline_singleline_inputbox);
            break;
        default:
            previous_char = gui_EMS_current_character(&MMI_EMS_inputbox);
            break;
    }
    /*PMT END MAUI_00530728 */
    if (previous_char)
    {
        if (previous_char >= PUNJABI_C_KA && previous_char <= PUNJABI_C_HA || previous_char >= PUNJABI_AC_KHHA &&
            previous_char <= PUNJABI_AC_FA)
        {
            return ((UI_character_type*) default_punjabimatra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (PUNJABI_DV_AA):
                /* MTI START MAUI_00030568 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030568 */
                /* MTI START MAUI_00030759 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030759 */
                case (PUNJABI_IV_AA):
                /* MTI START MAUI_00030759 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030759 */
                case (PUNJABI_IV_EE):

                /* MTI START MAUI_00030568 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030568 */
                case (PUNJABI_DV_II):
                case (PUNJABI_DV_EE):
                case (PUNJABI_DV_AI):
                case (PUNJABI_DV_OO):
                case (PUNJABI_DV_AU):
                case (PUNJABI_IV_II):
                case (PUNJABI_IV_AI):
                /* MTI START MAUI_00030759 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030759 */
                case (PUNJABI_IV_AU):
                /* MTI START MAUI_00036801 */
                case (PUNJABI_IV_U):
                case (PUNJABI_IV_UU):
                case (PUNJABI_IV_OO):
                /* MTI END MAUI_00036801 */
                {
                    return ((UI_character_type*) default_punjabimatra1_multitap_strings[i]);
                    break;
                }
                /* MTI START MAUI_00030568 */
                /* MTI START MAUI_00030759 */
                case (PUNJABI_IV_A):
                case (PUNJABI_IV_I):
                /* MTI END MAUI_00030759 */
                case (PUNJABI_DV_I):
                case (PUNJABI_DV_U):
                case (PUNJABI_DV_UU):
                {
                    return ((UI_character_type*) default_punjabimatra2_multitap_strings[i]);
                    break;
                }
                /* MTI END MAUI_00030568 */
                default:
                {
                    return ((UI_character_type*) default_punjabi_multitap_strings[i]);
                }
            }
        }

    }
    else
    {
        return ((UI_character_type*) default_punjabi_multitap_strings[i]);
    }

}


/*****************************************************************************
 * FUNCTION
 *  get_punjabi_single_line_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_punjabi_single_line_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
    /* For performance improval */
    if (previous_char)
    {
        if (previous_char >= PUNJABI_C_KA && previous_char <= PUNJABI_C_HA || previous_char >= PUNJABI_AC_KHHA &&
            previous_char <= PUNJABI_AC_FA)
        {
            return ((UI_character_type*) default_punjabimatra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (PUNJABI_DV_AA):
                /* MTI START MAUI_00030568 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030568 */
                /* MTI START MAUI_00030759 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030759 */
                case (PUNJABI_IV_AA):
                /* MTI START MAUI_00030759 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030759 */
                case (PUNJABI_IV_EE):

                /* MTI START MAUI_00030568 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030568 */
                case (PUNJABI_DV_II):
                case (PUNJABI_DV_EE):
                case (PUNJABI_DV_AI):
                case (PUNJABI_DV_OO):
                case (PUNJABI_DV_AU):
                case (PUNJABI_IV_II):
                case (PUNJABI_IV_AI):
                /* MTI START MAUI_00030759 */
                /* CODE REMOVED */
                /* MTI END MAUI_00030759 */
                case (PUNJABI_IV_AU):
                /* MTI START MAUI_00036801 */
                case (PUNJABI_IV_U):
                case (PUNJABI_IV_UU):
                case (PUNJABI_IV_OO):
                /* MTI END MAUI_00036801 */
                {
                    return ((UI_character_type*) default_punjabimatra1_multitap_strings[i]);
                    break;
                }
                /* MTI START MAUI_00030568 */
                /* MTI START MAUI_00030759 */
                case (PUNJABI_IV_A):
                case (PUNJABI_IV_I):
                /* MTI END MAUI_00030759 */
                case (PUNJABI_DV_I):
                case (PUNJABI_DV_U):
                case (PUNJABI_DV_UU):
                {
                    return ((UI_character_type*) default_punjabimatra2_multitap_strings[i]);
                    break;
                }
                /* MTI END MAUI_00030568 */
                default:
                {
                    return ((UI_character_type*) default_punjabi_multitap_strings[i]);
                }

            }
        }

    }
    else
    {
        return ((UI_character_type*) default_punjabi_multitap_strings[i]);
    }

}

#endif /* defined (__MMI_MULTITAP_PUNJABI__) */ /* #if defined (__MMI_MULTITAP_PUNJABI__)  */
#endif /* defined (__MMI_LANG_PUNJABI__) */ /* #if defined (__MMI_LANG_PUNJABI__) */

