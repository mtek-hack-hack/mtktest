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
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE const staticRUED IN ACCORDANCE
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
*    Tamil.c
*
* Project:
* --------
*   Maui
*
* Description:
* ------------
*   C file of tamil font rule 
*
*
* Author:
* Satish chandra (mti00107)
* 
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
*
* 
* 
* 
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


#include "MMI_include.h"
#ifndef __MMI_TAMIL_H__
#define __MMI_TAMIL_H__


#if defined (__MMI_LANG_TAMIL__)

#include "gui_data_types.h"
#include "IndicEngineGprot.h"

#ifndef NULL
#define NULL   0
#endif 

const ire_character_info_table_struct tamil_character_info_table[] = 
{

    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b81 */

    /* VARIOUS SIGNS */

    {0, 0, 0, 0, 0, 0, 0, 0},   /* ANUSVARA not is use 0xb82 */
    /* MTI START MAUI_00031250 */    
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* VISARGA 0x0b83 */
    /* MTI END MAUI_00031250 */    
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b84 */

    /* INDEPENDENT VOWEL */

    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_A  0x0b85 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_AA 0x0b86 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_I 0x0b87 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_II 0x0b88 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_U 0x0b89 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_UU 0x0b8a */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b8b */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b8c */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b8d */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_E 0x0b8e */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_EE 0x0b8f */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_AI   0x0b90 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b91 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_O    0x0b92 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_OO   0x0b93 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* IV_AU   0x0b94 */

    /* CONSONANTS */

    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_KA0 0x0b95 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b96 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b97 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b98 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_NGA 0x0b99 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_CA  0x0b9a */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b9b */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_JA  0x0b9c */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0b9d */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_JA 0x0b9e */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_TA 0x0b9f */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0ba0 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0ba1 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0ba2 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_NHA 0x0ba3 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_THA  0x0ba4 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0ba5 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0ba6 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0ba7 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_NA  0x0ba8 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_NA2 0x0ba9 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_PA  0x0baa */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bab */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bac */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bad */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_MA  0x0bae */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_YA  0x0baf */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_RA  0x0bb0 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_RXA 0x0bb1 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_LA  0x0bb2 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_LAA 0x0bb3 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_LHA 0x0bb4 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_VA  0x0bb5 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* CON_KS 0x0bb6 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_KS 0x0bb7 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_LXX 0x0bb8 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* CON_HA 0x0bb9 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bba */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bbb */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bbc */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bbd */

    /* DEPENDENT VOWELS */

    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* D_AA  0x0bbe    */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* D_I   0x0bbf   */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* D_II  0x0bc0  */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* D_U   0x0bc1   */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* D_UU  0x0bc2  */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bc3 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bc4 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bc5 */
    {0, IRE_PRE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0},   /* D_E  0x0bc6 */
    {0, IRE_PRE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0},   /* D_EE 0x0bc7 */
    {0, IRE_PRE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0},   /* D_AI 0x0bc8 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bc9 */
    {0, IRE_CENTER_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},       /* D_O  0x0bca */
    {0, IRE_CENTER_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},       /* D_OO 0x0bcb */
    {0, IRE_CENTER_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},       /* D_OO 0x0bcc */

    /* SIGNS */

    {0, 0, 0, IRE_TAMIL_HAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},    /* HAL 0x0bcd */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bce */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bcf */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd0 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd1 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd2 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd3 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd4 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd5 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd6 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POST_BASE_DEP_VOWEL, 0},       /* D_AU 0x0bd7 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd8 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bd9 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bda */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bdb */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bdd */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bde */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0bdf */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0be0 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0be1 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0be2 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0be3 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0be4 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* INVALID 0x0be5 */

    /* DIGITS */

    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_0 0x0be6 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_1 0x0be7 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_2 0x0be8 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_3 0x0be9 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_4 0x0bea */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_5 0x0beb */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_6 0x0bec */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_7 0x0bed */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_8 0x0bee */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_9 0x0bef */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_10 0x0bf0 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_100 0x0bf1 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* NUM_1000  0x0bf2 */

    /* OTHER SIGNS */

    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_DAY 0x0bf3 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_MONTH 0x0bf4 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_YEAR 0x0bf5 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_DEBIT 0x0bf6 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_CREDIT 0x0bf7 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_AS_ABOVE  0x0bf8 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_RUPEES 0x0bf9 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* SYM_NUMERAL 0x0bfa */
};

const ire_character_info_table_struct tamil_ligature_info_table[] = 
{
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* KU 0xee01 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* KUU 0xee02 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* L_03 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee04 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee05 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee06 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee07 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee08 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee09 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee0a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee0b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee0c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee0d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee0e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee0f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee10 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee11 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee12 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee13 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee14 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee15 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee16 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee17 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee18 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee19 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee1a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee1b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee1c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee1d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee1e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee1f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee20 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee21 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee22 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee23 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee24 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee25 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee26 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee27 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee28 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee29 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee2a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee2b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee2c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee2d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee2e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee2f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee30 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee31 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee32 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee33 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee34 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee35 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee36 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee37 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee38 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee39 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee3a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee3b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee3c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee3d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee3e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee3f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee40 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee41 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee42 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee43 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee44 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee45 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee46 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee47 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee48 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee49 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee4a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee4b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee4c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee4d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee4e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee4f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee50 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xee51 */

};

/* Independent Vowels */

const static ire_glyph_info_table_struct TAMIL_VISARGA_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_S_VISARGA, 0x0}, {TAMIL_S_VISARGA, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_A_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_A, 0x0}, {TAMIL_IV_A, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_AA_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_AA, 0x0}, {TAMIL_IV_AA, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_I_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_I, 0x0}, {TAMIL_IV_I, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_II_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_II, 0x0}, {TAMIL_IV_II, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_U_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_U, 0x0}, {TAMIL_IV_U, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_UU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_UU, 0x0}, {TAMIL_IV_UU, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_E_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_E, 0x0}, {TAMIL_IV_E, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_EE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_EE, 0x0}, {TAMIL_IV_EE, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_AI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_AI, 0x0}, {TAMIL_IV_AI, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_O_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_O, 0x0}, {TAMIL_IV_O, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_OO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_OO, 0x0}, {TAMIL_IV_OO, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_AU_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_IV_AU, 0x0}, {TAMIL_IV_AU, 0x0}}

};

/*    CONSONANT'S TABLES   */

const static ire_glyph_info_table_struct TAMIL_KA_Tbl[] = 
{

    /* KA + space */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_KA, 0x0}, {TAMIL_C_KA, 0x0}},
    /* KA + I -> KI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_KA, TAMIL_DV_I, 0x0}, {TAMIL_L_KI, 0x0}},
    /* KA + II -> KII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_KA, TAMIL_DV_II, 0x0}, {TAMIL_L_KII, 0x0}},
    /* KA + U -> KU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_KA, TAMIL_DV_U, 0x0}, {TAMIL_L_KU, 0x0}},
    /* KA + UU -> KUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_KA, TAMIL_DV_UU, 0x0}, {TAMIL_L_KUU, 0x0}},
    /* KA + Halant + SSA -> KSHA */
    {0, 3, 1, MMI_ALL_LANG, {TAMIL_C_KA, TAMIL_S_HALANT, TAMIL_C_SSA, 0x0}, {TAMIL_L_KSHA, 0x0}},
    /* KA + Halant + SSA -> KSHI */
    {0, 4, 1, MMI_ALL_LANG, {TAMIL_C_KA, TAMIL_S_HALANT, TAMIL_C_SSA, TAMIL_DV_I, 0x0}, {TAMIL_L_KSHI, 0x0}},
    /* KA + Halant + SSA -> KSHII */
    {0, 4, 1, MMI_ALL_LANG, {TAMIL_C_KA, TAMIL_S_HALANT, TAMIL_C_SSA, TAMIL_DV_II, 0x0}, {TAMIL_L_KSHII, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_NGA_Tbl[] = 
{
    /* NGA + space */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_NGA, 0x0}, {TAMIL_C_NGA, 0x0}},
    /* NGA + I -> NGI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NGA, TAMIL_DV_I, 0x0}, {TAMIL_L_NGI, 0x0}},
    /* NGA + II -> NGII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NGA, TAMIL_DV_II, 0x0}, {TAMIL_L_NGII, 0x0}},
    /* NGA + U -> NGU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NGA, TAMIL_DV_U, 0x0}, {TAMIL_L_NGU, 0x0}},
    /* NGA + UU -> NGUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NGA, TAMIL_DV_UU, 0x0}, {TAMIL_L_NGUU, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_CHA_Tbl[] = 
{
    /* CA + space */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_CHA, 0x0}, {TAMIL_C_CHA, 0x0}},
    /* CA + II -> CAII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_CHA, TAMIL_DV_I, 0x0}, {TAMIL_L_CHI, 0x0}},
    /* CA + II -> CAII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_CHA, TAMIL_DV_II, 0x0}, {TAMIL_L_CHII, 0x0}},
    /* CA + U -> CU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_CHA, TAMIL_DV_U, 0x0}, {TAMIL_L_CHU, 0x0}},
    /* CA + U -> CUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_CHA, TAMIL_DV_UU, 0x0}, {TAMIL_L_CHUU, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_JA_Tbl[] = 
{
    /* JA + space */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_JA, 0x0}, {TAMIL_C_JA, 0x0}},
    /* JA + II -> JAII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_JA, TAMIL_DV_I, 0x0}, {TAMIL_L_JI, 0x0}},
    /* JA + II -> JAII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_JA, TAMIL_DV_II, 0x0}, {TAMIL_L_JII, 0x0}},

};

const static ire_glyph_info_table_struct TAMIL_NYA_Tbl[] = 
{
    /* NYA + space */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_NYA, 0x0}, {TAMIL_C_NYA, 0x0}},
    /* NYA + II -> NYII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NYA, TAMIL_DV_I, 0x0}, {TAMIL_L_NYI, 0x0}},
    /* NYA + II -> NYII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NYA, TAMIL_DV_II, 0x0}, {TAMIL_L_NYII, 0x0}},
    /* NYA + U  -> NYU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NYA, TAMIL_DV_U, 0x0}, {TAMIL_L_NYU, 0x0}},
    /* NYA + UU  -> NYUU */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_NYA, TAMIL_DV_UU, 0x0}, {TAMIL_L_NYU, TAMIL_L_APP_UU, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_TTA_Tbl[] = 
{
    /* TTA + space -> TTA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_TTA, 0x0}, {TAMIL_C_TTA, 0x0}},
    /* TTA + I -> TTI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_TTA, TAMIL_DV_I, 0x0}, {TAMIL_L_TTI, 0x0}},
    /* TTA + II -> TTII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_TTA, TAMIL_DV_II, 0x0}, {TAMIL_L_TTII, 0x0}},
    /* TTA + U -> TTU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_TTA, TAMIL_DV_U, 0x0}, {TAMIL_L_TTU, 0x0}},
    /* TTA + UU -> TTUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_TTA, TAMIL_DV_UU, 0x0}, {TAMIL_L_TTUU, 0x0}},

};


const static ire_glyph_info_table_struct TAMIL_NNA_Tbl[] = 
{
    /* NNA + space -> NNA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_NNA, 0x0}, {TAMIL_C_NNA, 0x0}},
    /* NNA + I -> NNI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NNA, TAMIL_DV_I, 0x0}, {TAMIL_L_NNI, 0x0}},
    /* NNA + I -> NNII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NNA, TAMIL_DV_II, 0x0}, {TAMIL_L_NNII, 0x0}},
    /* NNA + U -> NNU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NNA, TAMIL_DV_U, 0x0}, {TAMIL_L_NNU, 0x0}},
    /* NNA + UU -> NNUU */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_NNA, TAMIL_DV_UU, 0x0}, {TAMIL_L_NNU, TAMIL_L_APP_UU, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_TA_Tbl[] = 
{
    /* TA + space -> TA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_TA, 0x0}, {TAMIL_C_TA, 0x0}},
    /* TA + I -> TI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_TA, TAMIL_DV_I, 0x0}, {TAMIL_L_TI, 0x0}},
    /* TA + II -> TII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_TA, TAMIL_DV_II, 0x0}, {TAMIL_L_TII, 0x0}},
    /* TA + U -> TU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_TA, TAMIL_DV_U, 0x0}, {TAMIL_L_TU, 0x0}},
    /* TA + U -> TUU */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_TA, TAMIL_DV_UU, 0x0}, {TAMIL_L_TU, TAMIL_L_APP_UU, 0x0}}

};


const static ire_glyph_info_table_struct TAMIL_NA_Tbl[] = 
{
    /* NA + space -> NA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_NA, 0x0}, {TAMIL_C_NA, 0x0}},
    /* NA + I -> NI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NA, TAMIL_DV_I, 0x0}, {TAMIL_L_NI, 0x0}},
    /* NA + II -> NII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NA, TAMIL_DV_II, 0x0}, {TAMIL_L_NII, 0x0}},
    /* NA + U -> NU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NA, TAMIL_DV_U, 0x0}, {TAMIL_L_NU, 0x0}},
    /* NA + UU -> NUU */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_NA, TAMIL_DV_UU, 0x0}, {TAMIL_L_NU, TAMIL_L_APP_UU, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_NNNA_Tbl[] = 
{
    /* NNNA + space -> NNNA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_NNNA, 0x0}, {TAMIL_C_NNNA, 0x0}},
    /* NNNA + I -> NNNI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NNNA, TAMIL_DV_I, 0x0}, {TAMIL_L_NNNI, 0x0}},
    /* NNNA + UU -> NNNUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NNNA, TAMIL_DV_II, 0x0}, {TAMIL_L_NNNII, 0x0}},
    /* NNNA + U -> NNNU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_NNNA, TAMIL_DV_U, 0x0}, {TAMIL_L_NNNU, 0x0}},
    /* NNNA + UU -> NNNUU */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_NNNA, TAMIL_DV_UU, 0x0}, {TAMIL_L_NNNU, TAMIL_L_APP_UU, 0x0}},

};

const static ire_glyph_info_table_struct TAMIL_PA_Tbl[] = 
{
    /* PA + space -> PA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_PA, 0x0}, {TAMIL_C_PA, 0x0}},
    /* PA + I -> PI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_PA, TAMIL_DV_I, 0x0}, {TAMIL_L_PI, 0x0}},
    /* PA + II -> PII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_PA, TAMIL_DV_II, 0x0}, {TAMIL_L_PII, 0x0}},
    /* PA + U -> PU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_PA, TAMIL_DV_U, 0x0}, {TAMIL_L_PU, 0x0}},
    /* PA + UU -> PUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_PA, TAMIL_DV_UU, 0x0}, {TAMIL_L_PUU, 0x0}},
    /* PA + HALANT  */
    {1, 2, 1, MMI_ALL_LANG, {TAMIL_C_PA, TAMIL_S_HALANT, 0x0}, {TAMIL_L_PA_HALANT, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_MA_Tbl[] = 
{
    /* MA + space -> MA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_MA, 0x0}, {TAMIL_C_MA, 0x0}},
    /* MA + I -> MI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_MA, TAMIL_DV_I, 0x0}, {TAMIL_L_MI, 0x0}},
    /* MA + II -> MII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_MA, TAMIL_DV_II, 0x0}, {TAMIL_L_MII, 0x0}},
    /* MA + U -> MU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_MA, TAMIL_DV_U, 0x0}, {TAMIL_L_MU, 0x0}},
    /* MA + UU -> MUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_MA, TAMIL_DV_UU, 0x0}, {TAMIL_L_MUU, 0x0}},

};

const static ire_glyph_info_table_struct TAMIL_YA_Tbl[] = 
{
    /* YA + space -> YA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_YA, 0x0}, {TAMIL_C_YA, 0x0}},
    /* YA + I -> YI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_YA, TAMIL_DV_I, 0x0}, {TAMIL_L_YI, 0x0}},
    /* YA + II -> YII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_YA, TAMIL_DV_II, 0x0}, {TAMIL_L_YII, 0x0}},
    /* YA + U -> YU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_YA, TAMIL_DV_U, 0x0}, {TAMIL_L_YU, 0x0}},
    /* YA + UU -> YUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_YA, TAMIL_DV_UU, 0x0}, {TAMIL_L_YUU, 0x0}},

};


const static ire_glyph_info_table_struct TAMIL_RA_Tbl[] = 
{
    /* RA + space -> RA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_RA, 0x0}, {TAMIL_C_RA, 0x0}},
    /* RA + I -> RI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_RA, TAMIL_DV_I, 0x0}, {TAMIL_L_RI, 0x0}},
    /* RA + II -> RII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_RA, TAMIL_DV_II, 0x0}, {TAMIL_L_RII, 0x0}},
    /* RA + U -> RU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_RA, TAMIL_DV_U, 0x0}, {TAMIL_L_RU, 0x0}},
    /* RA + UU -> RUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_RA, TAMIL_DV_UU, 0x0}, {TAMIL_L_RUU, 0x0}},
    /* RA + HALANT  */
    {1, 2, 1, MMI_ALL_LANG, {TAMIL_C_RA, TAMIL_S_HALANT, 0x0}, {TAMIL_L_RA_HALANT, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_RRA_Tbl[] = 
{
    /* RRA + space -> RRA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_RRA, 0x0}, {TAMIL_C_RRA, 0x0}},
    /* RRA + I -> RRI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_RRA, TAMIL_DV_I, 0x0}, {TAMIL_L_RRI, 0x0}},
    /* RRA + II -> RRII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_RRA, TAMIL_DV_II, 0x0}, {TAMIL_L_RRII, 0x0}},
    /* RRA + U -> RRU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_RRA, TAMIL_DV_U, 0x0}, {TAMIL_L_RRU, 0x0}},
    /* RRA + UU -> RRUU */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_RRA, TAMIL_DV_UU, 0x0}, {TAMIL_L_RRU, TAMIL_L_APP_UU, 0x0}},
    /* RRA + HALANT  */
    {1, 2, 1, MMI_ALL_LANG, {TAMIL_C_RRA, TAMIL_S_HALANT, 0x0}, {TAMIL_L_RRA_HALANT, 0x0}}
};

const static ire_glyph_info_table_struct TAMIL_LA_Tbl[] = 
{
    /* LA + space -> LA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_LA, 0x0}, {TAMIL_C_LA, 0x0}},
    /* LA + I -> LI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LA, TAMIL_DV_I, 0x0}, {TAMIL_L_LI, 0x0}},
    /* LA + II -> LII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LA, TAMIL_DV_II, 0x0}, {TAMIL_L_LII, 0x0}},
    /* LA + U -> LU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LA, TAMIL_DV_U, 0x0}, {TAMIL_L_LU, 0x0}},
    /* LA + UU -> LUU */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_LA, TAMIL_DV_UU, 0x0}, {TAMIL_L_LU, TAMIL_L_APP_UU, 0x0}},

};

const static ire_glyph_info_table_struct TAMIL_LLA_Tbl[] = 
{
    /* LLA + space -> LLA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_LLA, 0x0}, {TAMIL_C_LLA, 0x0}},
    /* LLA + I -> LLI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLA, TAMIL_DV_I, 0x0}, {TAMIL_L_LLI, 0x0}},
    /* LLA + II -> LLII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLA, TAMIL_DV_II, 0x0}, {TAMIL_L_LLII, 0x0}},
    /* LLA + U -> LLU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLA, TAMIL_DV_U, 0x0}, {TAMIL_L_LLU, 0x0}},
    /* LLA + space -> LA */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLA, TAMIL_DV_UU, 0x0}, {TAMIL_L_LLUU, 0x0}},

};

const static ire_glyph_info_table_struct TAMIL_LLLA_Tbl[] = 
{
    /* LLLA + space -> LLLA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_LLLA, 0x0}, {TAMIL_C_LLLA, 0x0}},
    /* LLLA + I -> LLLI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLLA, TAMIL_DV_I, 0x0}, {TAMIL_L_LLLI, 0x0}},
    /* LLLA + II -> LLLII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLLA, TAMIL_DV_II, 0x0}, {TAMIL_L_LLLII, 0x0}},
    /* LLLA + U -> LLLU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLLA, TAMIL_DV_U, 0x0}, {TAMIL_L_LLLU, 0x0}},
    /* LLLA + UU -> LLLUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_LLLA, TAMIL_DV_UU, 0x0}, {TAMIL_L_LLLUU, 0x0}},

};

const static ire_glyph_info_table_struct TAMIL_VA_Tbl[] = 
{
    /* VA + space -> VA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_VA, 0x0}, {TAMIL_C_VA, 0x0}},
    /* VA + I -> VI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_VA, TAMIL_DV_I, 0x0}, {TAMIL_L_VI, 0x0}},
    /* VA + II -> VII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_VA, TAMIL_DV_II, 0x0}, {TAMIL_L_VII, 0x0}},
    /* VA + U -> VU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_VA, TAMIL_DV_U, 0x0}, {TAMIL_L_VU, 0x0}},
    /* VA + UU -> VUU */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_VA, TAMIL_DV_UU, 0x0}, {TAMIL_L_VUU, 0x0}},
};

const static ire_glyph_info_table_struct TAMIL_SSA_Tbl[] = 
{

    /* SSA + space -> SSA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_SSA, 0x0}, {TAMIL_C_SSA, 0x0}},
    /* SSA + I -> SSI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_SSA, TAMIL_DV_I, 0x0}, {TAMIL_L_SSI, 0x0}},
    /* SSA + II -> SSII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_SSA, TAMIL_DV_II, 0x0}, {TAMIL_L_SSII, 0x0}},

};

const static ire_glyph_info_table_struct TAMIL_SA_Tbl[] = 
{
    /* SA + space -> SA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_SA, 0x0}, {TAMIL_C_SA, 0x0}},
    /* SA + I -> SI */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_SA, TAMIL_DV_I, 0x0}, {TAMIL_L_SI, 0x0}},
    /* SA + II -> SII */
    {0, 2, 1, MMI_ALL_LANG, {TAMIL_C_SA, TAMIL_DV_II, 0x0}, {TAMIL_L_SII, 0x0}},
    /* SA + Halant + Ra + II -> SRI */
    {0, 4, 1, MMI_ALL_LANG, {TAMIL_C_SA, TAMIL_S_HALANT, TAMIL_C_RA, TAMIL_DV_II, 0x0}, {TAMIL_L_SHREE, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_HA_Tbl[] = 
{
    /* HA + space -> HA */
    {0, 1, 1, MMI_ALL_LANG, {TAMIL_C_HA, 0x0}, {TAMIL_C_HA, 0x0}},
    /* HA + I -> HII */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_HA, TAMIL_DV_I, 0x0}, {TAMIL_L_HI, 0x0}},
    /* HA + I -> HII */
    {0, 2, 2, MMI_ALL_LANG, {TAMIL_C_HA, TAMIL_DV_II, 0x0}, {TAMIL_L_HII, 0x0}},

};

/* Dependent Vowels  */

const static ire_glyph_info_table_struct TAMIL_MAA_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_AA, 0x0}, {TAMIL_DV_AA, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MI_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_I, 0x0}, {TAMIL_DV_I, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MII_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_II, 0x0}, {TAMIL_DV_II, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MU_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_U, 0x0}, {TAMIL_DV_U, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MUU_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_UU, 0x0}, {TAMIL_DV_UU, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_ME_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_E, 0x0}, {TAMIL_DV_E, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MEE_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_EE, 0x0}, {TAMIL_DV_EE, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MAI_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_DV_AI, 0x0}, {TAMIL_DV_AI, 0x0}}

};

/* central base matra */

const static ire_glyph_info_table_struct TAMIL_MO_Tbl[] = 
{

    {0, 1, 2, MMI_ALL_LANG, {TAMIL_DV_O, 0x0}, {TAMIL_DV_E, TAMIL_DV_AA, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MOO_Tbl[] = 
{

    {0, 1, 2, MMI_ALL_LANG, {TAMIL_DV_OO, 0x0}, {TAMIL_DV_EE, TAMIL_DV_AA, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MAU_Tbl[] = 
{

    {0, 1, 2, MMI_ALL_LANG, {TAMIL_DV_AU, 0x0}, {TAMIL_DV_E, TAMIL_AD_AU, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_HAL_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_S_HALANT, 0x0}, {TAMIL_S_HALANT, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_AP_AU_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_AD_AU, 0x0}, {TAMIL_AD_AU, 0x0}}

};

/* Digit TABLE */

const static ire_glyph_info_table_struct TAMIL_ZERO_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_ZERO, 0x0}, {TAMIL_D_ZERO, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_ONE_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_ONE, 0x0}, {TAMIL_D_ONE, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_TWO_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_TWO, 0x0}, {TAMIL_D_TWO, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_THREE_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_THREE, 0x0}, {TAMIL_D_THREE, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_FOUR_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_FOUR, 0x0}, {TAMIL_D_FOUR, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_FIVE_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_FIVE, 0x0}, {TAMIL_D_FIVE, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_SIX_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_SIX, 0x0}, {TAMIL_D_SIX, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_SEVEN_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_SEVEN, 0x0}, {TAMIL_D_SEVEN, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_EIGHT_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_EIGHT, 0x0}, {TAMIL_D_EIGHT, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_NINE_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_NINE, 0x0}, {TAMIL_D_NINE, 0x0}}

};

/* Tamil Numerics */

const static ire_glyph_info_table_struct TAMIL_TEN_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_TEN, 0x0}, {TAMIL_D_TEN, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_HUNDRED_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_HUNDRED, 0x0}, {TAMIL_D_HUNDRED, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_THOUSAND_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_D_THOUSAND, 0x0}, {TAMIL_D_THOUSAND, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_DAY_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_DAY, 0x0}, {TAMIL_OS_DAY, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_MONTH_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_MONTH, 0x0}, {TAMIL_OS_MONTH, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_YEAR_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_YEAR, 0x0}, {TAMIL_OS_YEAR, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_DEBIT_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_DEBIT, 0x0}, {TAMIL_OS_DEBIT, 0x0}}

};


const static ire_glyph_info_table_struct TAMIL_CREDIT_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_CREDIT, 0x0}, {TAMIL_OS_CREDIT, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_ABOVE_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_ABOVE, 0x0}, {TAMIL_OS_ABOVE, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_RUPEE_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_RUPEE, 0x0}, {TAMIL_OS_RUPEE, 0x0}}

};

const static ire_glyph_info_table_struct TAMIL_NUMERAL_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {TAMIL_OS_NUMERNAL, 0x0}, {TAMIL_OS_NUMERNAL, 0x0}}

};

const ire_main_glyph_table_struct TamilDvngTbl[] = 
{

    /* NULL for devanagari sign Short A */
    {NULL, 0, 0}    /* 0B81 */
    ,
    {NULL, 0, 0}    /* 0B82 */
    ,
    {TAMIL_VISARGA_Tbl, sizeof(TAMIL_VISARGA_Tbl) / sizeof(TAMIL_VISARGA_Tbl[0]), 1}    /* 0B83 */
    ,
    /* INDEPENDENT VOWELS */

    {NULL, 0, 0}    /* 0B84 */
    ,
    {TAMIL_A_Tbl, sizeof(TAMIL_A_Tbl) / sizeof(TAMIL_A_Tbl[0]), 1}      /* 0B85 */
    ,
    {TAMIL_AA_Tbl, sizeof(TAMIL_AA_Tbl) / sizeof(TAMIL_AA_Tbl[0]), 1}   /* 0B86 */
    ,
    {TAMIL_I_Tbl, sizeof(TAMIL_I_Tbl) / sizeof(TAMIL_I_Tbl[0]), 1}      /* 0B87 */
    ,
    {TAMIL_II_Tbl, sizeof(TAMIL_II_Tbl) / sizeof(TAMIL_II_Tbl[0]), 1}   /* 0B88 */
    ,
    {TAMIL_U_Tbl, sizeof(TAMIL_U_Tbl) / sizeof(TAMIL_U_Tbl[0]), 1}      /* 0B89 */
    ,
    {TAMIL_UU_Tbl, sizeof(TAMIL_UU_Tbl) / sizeof(TAMIL_UU_Tbl[0]), 1}   /* 0B8A */
    ,
    {NULL, 0, 0}    /* 0B8B */
    ,
    {NULL, 0, 0}    /* 0B8C */
    ,
    {NULL, 0, 0}    /* 0B8D */
    ,
    {TAMIL_E_Tbl, sizeof(TAMIL_E_Tbl) / sizeof(TAMIL_E_Tbl[0]), 1}      /* 0B8E */
    ,
    {TAMIL_EE_Tbl, sizeof(TAMIL_EE_Tbl) / sizeof(TAMIL_EE_Tbl[0]), 1}   /* 0B8F */
    ,
    {TAMIL_AI_Tbl, sizeof(TAMIL_AI_Tbl) / sizeof(TAMIL_AI_Tbl[0]), 1}   /* 0B90 */
    ,
    {NULL, 0, 0}    /* 0B91 */
    ,
    {TAMIL_O_Tbl, sizeof(TAMIL_O_Tbl) / sizeof(TAMIL_O_Tbl[0]), 1}      /* 0B92 */
    ,
    {TAMIL_OO_Tbl, sizeof(TAMIL_OO_Tbl) / sizeof(TAMIL_OO_Tbl[0]), 1}   /* 0B93 */
    ,
    {TAMIL_AU_Tbl, sizeof(TAMIL_AU_Tbl) / sizeof(TAMIL_AU_Tbl[0]), 1}   /* 0B94 */
    ,
    /* Consonants */
    {TAMIL_KA_Tbl, sizeof(TAMIL_KA_Tbl) / sizeof(TAMIL_KA_Tbl[0]), 4}   /* 0B95 */
    ,
    {NULL, 0, 0}    /* 0B96 */
    ,
    {NULL, 0, 0}    /* 0B97 */
    ,
    {NULL, 0, 0}    /* 0B98 */
    ,
    {TAMIL_NGA_Tbl, sizeof(TAMIL_NGA_Tbl) / sizeof(TAMIL_NGA_Tbl[0]), 2}        /* 0B99 */
    ,
    {TAMIL_CHA_Tbl, sizeof(TAMIL_CHA_Tbl) / sizeof(TAMIL_CHA_Tbl[0]), 2}        /* 0B9A */
    ,
    {NULL, 0, 0}    /* 0B9B */
    ,
    {TAMIL_JA_Tbl, sizeof(TAMIL_JA_Tbl) / sizeof(TAMIL_JA_Tbl[0]), 2}   /* 0B9C */
    ,
    {NULL, 0, 0}    /* 0B9D */
    ,
    {TAMIL_NYA_Tbl, sizeof(TAMIL_NYA_Tbl) / sizeof(TAMIL_NYA_Tbl[0]), 2}        /* 0B9E */
    ,
    {TAMIL_TTA_Tbl, sizeof(TAMIL_TTA_Tbl) / sizeof(TAMIL_TTA_Tbl[0]), 2}        /* 0B9F */
    ,
    {NULL, 0, 0}    /* 0BA0 */
    ,
    {NULL, 0, 0}    /* 0BA1 */
    ,
    {NULL, 0, 0}    /* 0BA2 */
    ,
    {TAMIL_NNA_Tbl, sizeof(TAMIL_NNA_Tbl) / sizeof(TAMIL_NNA_Tbl[0]), 2}        /* 0BA3 */
    ,
    {TAMIL_TA_Tbl, sizeof(TAMIL_TA_Tbl) / sizeof(TAMIL_TA_Tbl[0]), 2}   /* 0BA4 */
    ,
    {NULL, 0, 0}    /* 0BA5 */
    ,
    {NULL, 0, 0}    /* 0BA6 */
    ,
    {NULL, 0, 0}    /* 0BA7 */
    ,
    {TAMIL_NA_Tbl, sizeof(TAMIL_NA_Tbl) / sizeof(TAMIL_NA_Tbl[0]), 2}   /* 0BA8 */
    ,
    {TAMIL_NNNA_Tbl, sizeof(TAMIL_NNNA_Tbl) / sizeof(TAMIL_NNNA_Tbl[0]), 2}     /* 0BA9 */
    ,
    {TAMIL_PA_Tbl, sizeof(TAMIL_PA_Tbl) / sizeof(TAMIL_PA_Tbl[0]), 2}   /* 0BAA */
    ,
    {NULL, 0, 0}    /* 0BAB */
    ,
    {NULL, 0, 0}    /* 0BAC */
    ,
    {NULL, 0, 0}    /* 0BAD */
    ,
    {TAMIL_MA_Tbl, sizeof(TAMIL_MA_Tbl) / sizeof(TAMIL_MA_Tbl[0]), 2}   /* 0BAE */
    ,
    {TAMIL_YA_Tbl, sizeof(TAMIL_YA_Tbl) / sizeof(TAMIL_YA_Tbl[0]), 2}   /* 0BAF */
    ,
    {TAMIL_RA_Tbl, sizeof(TAMIL_RA_Tbl) / sizeof(TAMIL_RA_Tbl[0]), 2}   /* 0BB0 */
    ,
    {TAMIL_RRA_Tbl, sizeof(TAMIL_RRA_Tbl) / sizeof(TAMIL_RRA_Tbl[0]), 2}        /* 0BB1 */
    ,
    {TAMIL_LA_Tbl, sizeof(TAMIL_LA_Tbl) / sizeof(TAMIL_LA_Tbl[0]), 2}   /* 0BB2 */
    ,
    {TAMIL_LLA_Tbl, sizeof(TAMIL_LLA_Tbl) / sizeof(TAMIL_LLA_Tbl[0]), 2}        /* 0BB3 */
    ,
    {TAMIL_LLLA_Tbl, sizeof(TAMIL_LLLA_Tbl) / sizeof(TAMIL_LLLA_Tbl[0]), 2}     /* 0BB4 */
    ,
    {TAMIL_VA_Tbl, sizeof(TAMIL_VA_Tbl) / sizeof(TAMIL_VA_Tbl[0]), 2}   /* 0BB5 */
    ,
    {NULL, 0, 0}    /* 0BB6 */
    ,
    {TAMIL_SSA_Tbl, sizeof(TAMIL_SSA_Tbl) / sizeof(TAMIL_SSA_Tbl[0]), 2}        /* 0BB7 */
    ,
    {TAMIL_SA_Tbl, sizeof(TAMIL_SA_Tbl) / sizeof(TAMIL_SA_Tbl[0]), 4}   /* 0BB8 */
    ,
    {TAMIL_HA_Tbl, sizeof(TAMIL_HA_Tbl) / sizeof(TAMIL_HA_Tbl[0]), 2}   /* 0BB9 */
    ,
    {NULL, 0, 0}    /* 0BBA */
    ,
    {NULL, 0, 0}    /* 0BBB */
    ,
    {NULL, 0, 0}    /* 0BBC */
    ,
    {NULL, 0, 0}    /* 0BBD */
    ,
    /* Dependent Vowel Signs */

    {TAMIL_MAA_Tbl, sizeof(TAMIL_MAA_Tbl) / sizeof(TAMIL_MAA_Tbl[0]), 1}        /* 0BBE */
    ,
    {TAMIL_MI_Tbl, sizeof(TAMIL_MI_Tbl) / sizeof(TAMIL_MI_Tbl[0]), 1}   /* 0BBF */
    ,
    {TAMIL_MII_Tbl, sizeof(TAMIL_MII_Tbl) / sizeof(TAMIL_MII_Tbl[0]), 1}        /* 0BC0 */
    ,
    {TAMIL_MU_Tbl, sizeof(TAMIL_MU_Tbl) / sizeof(TAMIL_MU_Tbl[0]), 1}   /* 0BC1 */
    ,
    {TAMIL_MUU_Tbl, sizeof(TAMIL_MUU_Tbl) / sizeof(TAMIL_MUU_Tbl[0]), 1}        /* 0BC2 */
    ,
    {NULL, 0, 0}    /* 0BC3 */
    ,
    {NULL, 0, 0}    /* 0BC4 */
    ,
    {NULL, 0, 0}    /* 0BC5 */
    ,
    {TAMIL_ME_Tbl, sizeof(TAMIL_ME_Tbl) / sizeof(TAMIL_ME_Tbl[0]), 1}   /* 0BC6 */
    ,
    {TAMIL_MEE_Tbl, sizeof(TAMIL_MEE_Tbl) / sizeof(TAMIL_MEE_Tbl[0]), 1}        /* 0BC7 */
    ,
    {TAMIL_MAI_Tbl, sizeof(TAMIL_MAI_Tbl) / sizeof(TAMIL_MAI_Tbl[0]), 1}        /* 0BC8 */
    ,
    {NULL, 0, 0}    /* 0BC9 */
    ,
    {TAMIL_MO_Tbl, sizeof(TAMIL_MO_Tbl) / sizeof(TAMIL_MO_Tbl[0]), 1}   /* 0BCA */
    ,
    {TAMIL_MOO_Tbl, sizeof(TAMIL_MOO_Tbl) / sizeof(TAMIL_MOO_Tbl[0]), 1}        /* 0BCB */
    ,
    {TAMIL_MAU_Tbl, sizeof(TAMIL_MAU_Tbl) / sizeof(TAMIL_MAU_Tbl[0]), 1}        /* 0BCC */
    ,
    {TAMIL_HAL_Tbl, sizeof(TAMIL_HAL_Tbl) / sizeof(TAMIL_HAL_Tbl[0]), 1}        /* 0BCD */
    ,
    {NULL, 0, 0}    /* 0BCE */
    ,
    {NULL, 0, 0}    /* 0BCF */
    ,
    {NULL, 0, 0}    /* 0BD0 */
    ,
    {NULL, 0, 0}    /* 0BD1 */
    ,
    {NULL, 0, 0}    /* 0BD2 */
    ,
    {NULL, 0, 0}    /* 0BD3 */
    ,
    {NULL, 0, 0}    /* 0BD4 */
    ,
    {NULL, 0, 0}    /* 0BD5 */
    ,
    {NULL, 0, 0}    /* 0BD6 */
    ,
    /* AU Length Mark */
    {TAMIL_AP_AU_Tbl, sizeof(TAMIL_AP_AU_Tbl) / sizeof(TAMIL_AP_AU_Tbl[0]), 1}  /* 0BD7 */
    ,
    {NULL, 0, 0}    /* 0BD8 */
    ,
    {NULL, 0, 0}    /* 0BD9 */
    ,
    {NULL, 0, 0}    /* 0BDA */
    ,
    {NULL, 0, 0}    /* 0BDB */
    ,
    {NULL, 0, 0}    /* 0BDC */
    ,
    {NULL, 0, 0}    /* 0BDD */
    ,
    {NULL, 0, 0}    /* 0BDE */
    ,
    {NULL, 0, 0}    /* 0BDF */
    ,
    {NULL, 0, 0}    /* 0BE0 */
    ,
    {NULL, 0, 0}    /* 0BE1 */
    ,
    {NULL, 0, 0}    /* 0BE2 */
    ,
    {NULL, 0, 0}    /* 0BE3 */
    ,
    {NULL, 0, 0}    /* 0BE4 */
    ,
    {NULL, 0, 0}    /* 0BE5 */
    ,
    /* Digits */
    {TAMIL_ZERO_Tbl, sizeof(TAMIL_ZERO_Tbl) / sizeof(TAMIL_ZERO_Tbl[0]), 1}     /* 0BE6 */
    ,
    {TAMIL_ONE_Tbl, sizeof(TAMIL_ONE_Tbl) / sizeof(TAMIL_ONE_Tbl[0]), 1}        /* 0BE7 */
    ,
    {TAMIL_TWO_Tbl, sizeof(TAMIL_TWO_Tbl) / sizeof(TAMIL_TWO_Tbl[0]), 1}        /* 0BE8 */
    ,
    {TAMIL_THREE_Tbl, sizeof(TAMIL_THREE_Tbl) / sizeof(TAMIL_THREE_Tbl[0]), 1}  /* 0BE9 */
    ,
    {TAMIL_FOUR_Tbl, sizeof(TAMIL_FOUR_Tbl) / sizeof(TAMIL_FOUR_Tbl[0]), 1}     /* 0BEA */
    ,
    {TAMIL_FIVE_Tbl, sizeof(TAMIL_FIVE_Tbl) / sizeof(TAMIL_FIVE_Tbl[0]), 1}     /* 0BEB */
    ,
    {TAMIL_SIX_Tbl, sizeof(TAMIL_SIX_Tbl) / sizeof(TAMIL_SIX_Tbl[0]), 1}        /* 0BEC */
    ,
    {TAMIL_SEVEN_Tbl, sizeof(TAMIL_SEVEN_Tbl) / sizeof(TAMIL_SEVEN_Tbl[0]), 1}  /* 0BED */
    ,
    {TAMIL_EIGHT_Tbl, sizeof(TAMIL_EIGHT_Tbl) / sizeof(TAMIL_EIGHT_Tbl[0]), 1}  /* 0BEE */
    ,
    {TAMIL_NINE_Tbl, sizeof(TAMIL_NINE_Tbl) / sizeof(TAMIL_NINE_Tbl[0]), 1}     /* 0BEF */
    ,
    {TAMIL_TEN_Tbl, sizeof(TAMIL_TEN_Tbl) / sizeof(TAMIL_TEN_Tbl[0]), 1}        /* 0BF0 */
    ,
    {TAMIL_HUNDRED_Tbl, sizeof(TAMIL_HUNDRED_Tbl) / sizeof(TAMIL_HUNDRED_Tbl[0]), 1}    /* 0BF1 */
    ,
    {TAMIL_THOUSAND_Tbl, sizeof(TAMIL_THOUSAND_Tbl) / sizeof(TAMIL_THOUSAND_Tbl[0]), 1} /* 0BF2 */

    /* Additional Signs */
    ,
    {TAMIL_DAY_Tbl, sizeof(TAMIL_DAY_Tbl) / sizeof(TAMIL_DAY_Tbl[0]), 1}        /* 0BF3 */
    ,
    {TAMIL_MONTH_Tbl, sizeof(TAMIL_MONTH_Tbl) / sizeof(TAMIL_MONTH_Tbl[0]), 1}  /* OBF4 */
    ,
    {TAMIL_YEAR_Tbl, sizeof(TAMIL_YEAR_Tbl) / sizeof(TAMIL_YEAR_Tbl[0]), 1}     /* OBF5 */
    ,
    {TAMIL_DEBIT_Tbl, sizeof(TAMIL_DEBIT_Tbl) / sizeof(TAMIL_DEBIT_Tbl[0]), 1}  /* OBF6 */
    ,
    {TAMIL_CREDIT_Tbl, sizeof(TAMIL_CREDIT_Tbl) / sizeof(TAMIL_CREDIT_Tbl[0]), 1}       /* OBF7 */
    ,
    {TAMIL_ABOVE_Tbl, sizeof(TAMIL_ABOVE_Tbl) / sizeof(TAMIL_ABOVE_Tbl[0]), 1}  /* OBF8 */
    ,
    {TAMIL_RUPEE_Tbl, sizeof(TAMIL_RUPEE_Tbl) / sizeof(TAMIL_RUPEE_Tbl[0]), 1}  /* OBF8 */
    ,
    {TAMIL_NUMERAL_Tbl, sizeof(TAMIL_NUMERAL_Tbl) / sizeof(TAMIL_NUMERAL_Tbl[0]), 1}    /* OBFA */

};

/* In editors, this array is used for language indication */

#if defined (__MMI_MULTITAP_TAMIL__)
#if defined (__MMI_ZI_TAMIL__)
/* PMT START ZI */
const UI_character_type default_tamil_multitap_strings[MAX_MULTITAPS][42] = 
{
    {' ', '0', '\0'},	/* key 0 */
    {0x002e, 0x002c, 0x003f, 0x0021, '1', 0x0040, 0x0027, 0x0022, 0x002d, 0x0028, 0x0029, 0x002f, 0x003a, 0x005f, 0x003b, 0x002b, 0x0026, 0x0025, 0x002a, 0x003d, 0x003c, 0x003e, 0x20ac, 0x00a3, 0x0024, 0x00a5, 0x00a4, 0x005b, 0x005d, 0x007b, 0x007d, 0x005c, 0x007e, 0x005e, 0x00bf, 0x00a1, 0x00a7, 0x0023, TAMIL_S_VISARGA, '\0'},	/* key 1 */
    {TAMIL_IV_A, TAMIL_IV_AA, TAMIL_IV_I, TAMIL_IV_II, TAMIL_IV_U, TAMIL_IV_UU, '2', '\0'},	/* key 2 */
    {TAMIL_IV_E, TAMIL_IV_EE, TAMIL_IV_AI, TAMIL_IV_O, TAMIL_IV_OO, TAMIL_IV_AU, '3', '\0'},	/* key 3 */
    {TAMIL_C_KA, TAMIL_C_NGA, TAMIL_C_CHA, TAMIL_C_NYA, '4', '\0'},	/* key 4 */
    {TAMIL_C_TTA, TAMIL_C_NNA, TAMIL_C_TA, TAMIL_C_NA, '5', '\0'},	/* key 5 */
    {TAMIL_C_PA, TAMIL_C_MA, TAMIL_C_YA, '6', '\0'},	/* key 6 */
    {TAMIL_C_RA, TAMIL_C_LA, TAMIL_C_VA, '7', '\0'},	/* key 7 */
    {TAMIL_C_LLLA, TAMIL_C_LLA, TAMIL_C_RRA, TAMIL_C_NNNA, '7', '\0'},	/* key 8 */
    {TAMIL_C_JA, TAMIL_C_SSA, TAMIL_C_SA, TAMIL_C_HA, '9', '\0'},	/* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* When previous character is consonant */
const UI_character_type default_tamilmatra_multitap_strings[MAX_MULTITAPS][42] = 
{
    {' ', '0', '\0'},	/* key 0 */
    {0x002e, 0x002c, 0x003f, 0x0021, '1', 0x0040, 0x0027, 0x0022, 0x002d, 0x0028, 0x0029, 0x002f, 0x003a, 0x005f, 0x003b, 0x002b, 0x0026, 0x0025, 0x002a, 0x003d, 0x003c, 0x003e, 0x20ac, 0x00a3, 0x0024, 0x00a5, 0x00a4, 0x005b, 0x005d, 0x007b, 0x007d, 0x005c, 0x007e, 0x005e, 0x00bf, 0x00a1, 0x00a7, 0x0023, TAMIL_S_HALANT, TAMIL_S_VISARGA, '\0'},	/* key 1 */
    {TAMIL_IV_A, TAMIL_IV_AA, TAMIL_IV_I, TAMIL_IV_II, TAMIL_IV_U, TAMIL_IV_UU, TAMIL_DV_AA, TAMIL_DV_I, TAMIL_DV_II, TAMIL_DV_U, TAMIL_DV_UU, '2', '\0'},	/* key 2 */
    {TAMIL_IV_E, TAMIL_IV_EE, TAMIL_IV_AI, TAMIL_IV_O, TAMIL_IV_OO, TAMIL_IV_AU, TAMIL_DV_E, TAMIL_DV_EE,TAMIL_DV_AI, TAMIL_DV_O, TAMIL_DV_OO, TAMIL_DV_AU, TAMIL_IV_E, TAMIL_IV_EE, TAMIL_IV_AI, TAMIL_IV_O, TAMIL_IV_OO, TAMIL_IV_AU, '3', '\0'},	/* key 3 */
    {TAMIL_C_KA, TAMIL_C_NGA, TAMIL_C_CHA, TAMIL_C_NYA, '4', '\0'},	/* key 4 */
    {TAMIL_C_TTA, TAMIL_C_NNA, TAMIL_C_TA, TAMIL_C_NA, '5', '\0'},	/* key 5 */
    {TAMIL_C_PA, TAMIL_C_MA, TAMIL_C_YA, '6', '\0'},	/* key 6 */
    {TAMIL_C_RA, TAMIL_C_LA, TAMIL_C_VA, '7', '\0'},	/* key 7 */
    {TAMIL_C_LLLA, TAMIL_C_LLA, TAMIL_C_RRA, TAMIL_C_NNNA, '7', '\0'},	/* key 8 */
    {TAMIL_C_JA, TAMIL_C_SSA, TAMIL_C_SA, TAMIL_C_HA, '9', '\0'},	/* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_tamilmatra1_multitap_strings[MAX_MULTITAPS][42] = 
{
    {' ', '0', '\0'},	/* key 0 */
    {0x002e, 0x002c, 0x003f, 0x0021, '1', 0x0040, 0x0027, 0x0022, 0x002d, 0x0028, 0x0029, 0x002f, 0x003a, 0x005f, 0x003b, 0x002b, 0x0026, 0x0025, 0x002a, 0x003d, 0x003c, 0x003e, 0x20ac, 0x00a3, 0x0024, 0x00a5, 0x00a4, 0x005b, 0x005d, 0x007b, 0x007d, 0x005c, 0x007e, 0x005e, 0x00bf, 0x00a1, 0x00a7, 0x0023, TAMIL_S_VISARGA, '\0'},	/* key 1 */
    {TAMIL_IV_A, TAMIL_IV_AA, TAMIL_IV_I, TAMIL_IV_II, TAMIL_IV_U, TAMIL_IV_UU, '2', '\0'},	/* key 2 */
    {TAMIL_IV_E, TAMIL_IV_EE, TAMIL_IV_AI, TAMIL_IV_O, TAMIL_IV_OO, TAMIL_IV_AU, '3', '\0'},	/* key 3 */
    {TAMIL_C_KA, TAMIL_C_NGA, TAMIL_C_CHA, TAMIL_C_NYA, '4', '\0'},	/* key 4 */
    {TAMIL_C_TTA, TAMIL_C_NNA, TAMIL_C_TA, TAMIL_C_NA, '5', '\0'},	/* key 5 */
    {TAMIL_C_PA, TAMIL_C_MA, TAMIL_C_YA, '6', '\0'},	/* key 6 */
    {TAMIL_C_RA, TAMIL_C_LA, TAMIL_C_VA, '7', '\0'},	/* key 7 */
    {TAMIL_C_LLLA, TAMIL_C_LLA, TAMIL_C_RRA, TAMIL_C_NNNA, '7', '\0'},	/* key 8 */
    {TAMIL_C_JA, TAMIL_C_SSA, TAMIL_C_SA, TAMIL_C_HA, '9', '\0'},	/* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

#else
/* PMT END ZI */

/* START PMT PUNJABI TELUGU */
/* CODE REMOVED */
/* END PMT PUNJABI TELUGU */

/* Following arrays are use for multitap. When Zi and T9 are disables */

const UI_character_type default_tamil_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', TAMIL_D_ZERO, '0', '\0'},                         /* key 0 */
    /* START PMT PATCH04052007 */
    {TAMIL_C_KA, TAMIL_C_NGA, TAMIL_D_ONE, '1', '\0'},      /* key 1 */
    {TAMIL_C_CHA, TAMIL_C_JA, TAMIL_C_NYA, TAMIL_D_TWO, '2', '\0'},     /* key 2 */
    {TAMIL_C_TTA, TAMIL_C_NNA, TAMIL_D_THREE, '3', '\0'},   /* key 3 */
    {TAMIL_C_TA, TAMIL_C_NA, TAMIL_C_NNNA, TAMIL_D_FOUR, '4', '\0'},    /* key 4 */
    {TAMIL_C_PA, TAMIL_C_MA, TAMIL_D_FIVE, '5', '\0'},      /* key 5 */
    {TAMIL_C_YA, TAMIL_C_RA, TAMIL_C_RRA, TAMIL_C_LA, TAMIL_C_LLA, TAMIL_C_LLLA, TAMIL_C_VA, TAMIL_C_SSA, TAMIL_C_SA, TAMIL_C_HA, TAMIL_D_SIX, '6', '\0'},      /* key 6 */
    {TAMIL_IV_A, TAMIL_IV_AA, TAMIL_IV_I, TAMIL_IV_II, TAMIL_IV_U, TAMIL_IV_UU, TAMIL_IV_E, TAMIL_IV_EE, TAMIL_IV_AI, TAMIL_IV_O, TAMIL_IV_OO, TAMIL_IV_AU, TAMIL_D_SEVEN, '7', '\0'},  /* key 7 */
    /* MTI START MAUI_00030716 */
    {TAMIL_D_EIGHT, '8', '\0'},                             /* key 8 */
    /* MTI END MAUI_00030716 */
    {TAMIL_S_VISARGA, TAMIL_D_NINE, '9', '\0'},                              /* key 9 */
    /* END PMT PATCH04052007 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* When previous character is consonant */
const UI_character_type default_tamilmatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* START PMT PATCH04052007 */
    {' ', TAMIL_D_ZERO, '0', '\0'},                         /* key 0 */
    {TAMIL_C_KA, TAMIL_C_NGA, TAMIL_D_ONE, '1', '\0'},      /* key 1 */
    {TAMIL_C_CHA, TAMIL_C_JA, TAMIL_C_NYA, TAMIL_D_TWO, '2', '\0'},     /* key 2 */
    {TAMIL_C_TTA, TAMIL_C_NNA, TAMIL_D_THREE, '3', '\0'},   /* key 3 */
    {TAMIL_C_TA, TAMIL_C_NA, TAMIL_C_NNNA, TAMIL_D_FOUR, '4', '\0'},    /* key 4 */
    {TAMIL_C_PA, TAMIL_C_MA, TAMIL_D_FIVE, '5', '\0'},      /* key 5 */
    {TAMIL_C_YA, TAMIL_C_RA, TAMIL_C_RRA, TAMIL_C_LA, TAMIL_C_LLA, TAMIL_C_LLLA, TAMIL_C_VA, TAMIL_C_SSA, TAMIL_C_SA, TAMIL_C_HA, TAMIL_D_SIX, '6', '\0'},      /* key 6 */
    /* MTI START MAUI_00030716 */
    {TAMIL_IV_A, TAMIL_IV_AA, TAMIL_IV_I, TAMIL_IV_II, TAMIL_IV_U, TAMIL_IV_UU, TAMIL_IV_E, TAMIL_IV_EE, TAMIL_IV_AI, TAMIL_IV_O, TAMIL_IV_OO, TAMIL_IV_AU, TAMIL_D_SEVEN, '7', '\0'}, /* key 7 */
    {TAMIL_DV_AA, TAMIL_DV_I, TAMIL_DV_II, TAMIL_DV_U, TAMIL_DV_UU, TAMIL_DV_E, TAMIL_DV_EE, TAMIL_DV_AI, TAMIL_DV_O, TAMIL_DV_OO, TAMIL_DV_AU, TAMIL_D_EIGHT, '8', '\0'},      /* key 8 */
    /* MTI END MAUI_00030716 */
    {TAMIL_S_VISARGA, TAMIL_S_HALANT, TAMIL_D_NINE, '9', '\0'}, /* key 9 */
    /* END PMT PATCH04052007 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_tamilmatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* START PMT PATCH04052007 */
    {' ', TAMIL_D_ZERO, '0', '\0'},                         /* key 0 */
    {TAMIL_C_KA, TAMIL_C_NGA, TAMIL_D_ONE, '1', '\0'},      /* key 1 */
    {TAMIL_C_CHA, TAMIL_C_JA, TAMIL_C_NYA, TAMIL_D_TWO, '2', '\0'},     /* key 2 */
    {TAMIL_C_TTA, TAMIL_C_NNA, TAMIL_D_THREE, '3', '\0'},   /* key 3 */
    {TAMIL_C_TA, TAMIL_C_NA, TAMIL_C_NNNA, TAMIL_D_FOUR, '4', '\0'},    /* key 4 */
    {TAMIL_C_PA, TAMIL_C_MA, TAMIL_D_FIVE, '5', '\0'},      /* key 5 */
    {TAMIL_C_YA, TAMIL_C_RA, TAMIL_C_RRA, TAMIL_C_LA, TAMIL_C_LLA, TAMIL_C_LLLA, TAMIL_C_VA, TAMIL_C_SSA, TAMIL_C_SA, TAMIL_C_HA, TAMIL_D_SIX, '6', '\0'},      /* key 6 */
    /* MTI START MAUI_00030716 */
    {TAMIL_IV_A, TAMIL_IV_AA, TAMIL_IV_I, TAMIL_IV_II, TAMIL_IV_U, TAMIL_IV_UU, TAMIL_IV_E, TAMIL_IV_EE, TAMIL_IV_AI, TAMIL_IV_O, TAMIL_IV_OO, TAMIL_IV_AU, TAMIL_D_SEVEN, '7', '\0'}, /* key 7 */
    {TAMIL_D_EIGHT, '8', '\0'},                             /* key 8 */
    /* MTI END MAUI_00030716 */
    {TAMIL_S_VISARGA, TAMIL_D_NINE, '9', '\0'},             /* key 9 */
    /* END PMT PATCH04052007 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* PMT START ZI */
#endif
/* PMT END ZI */
/* START PMT PUNJABI TELUGU */
/* CODE REMOVED */
/* END PMT PUNJABI TELUGU */


/*****************************************************************************
 * FUNCTION
 *  get_tamil_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_tamil_multitap_string(S32 i)
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
        if (previous_char >= TAMIL_C_KA && previous_char <= TAMIL_C_HA)
        {
            return ((UI_character_type*) default_tamilmatra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (TAMIL_DV_AA):
                case (TAMIL_DV_I):
                case (TAMIL_DV_II):
                case (TAMIL_DV_U):
                case (TAMIL_DV_UU):
                case (TAMIL_DV_E):
                case (TAMIL_DV_EE):
                case (TAMIL_DV_AI):
                case (TAMIL_DV_O):
                case (TAMIL_DV_OO):
                case (TAMIL_DV_AU):
                case (TAMIL_IV_A):
                case (TAMIL_IV_AA):
                case (TAMIL_IV_I):
                case (TAMIL_IV_II):
                case (TAMIL_IV_U):
                case (TAMIL_IV_UU):
                case (TAMIL_IV_E):
                case (TAMIL_IV_EE):
                case (TAMIL_IV_O):
                case (TAMIL_IV_OO):
                case (TAMIL_IV_AU):
                {
                    /* START PMT PUNJABI TELUGU */
                    return ((UI_character_type*) default_tamilmatra1_multitap_strings[i]);
                    /* END PMT PUNJABI TELUGU */
                    break;
                }
                default:
                    return ((UI_character_type*) default_tamil_multitap_strings[i]);

            }
        }
    }
    else
    {
        return ((UI_character_type*) default_tamil_multitap_strings[i]);
    }

}


/*****************************************************************************
 * FUNCTION
 *  get_tamil_single_line_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_tamil_single_line_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
    if (previous_char)
    {
        if (previous_char >= TAMIL_C_KA && previous_char <= TAMIL_C_HA)
        {
            return ((UI_character_type*) default_tamilmatra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (TAMIL_DV_AA):
                case (TAMIL_DV_I):
                case (TAMIL_DV_II):
                case (TAMIL_DV_U):
                case (TAMIL_DV_UU):
                case (TAMIL_DV_E):
                case (TAMIL_DV_EE):
                case (TAMIL_DV_AI):
                case (TAMIL_DV_O):
                case (TAMIL_DV_OO):
                case (TAMIL_DV_AU):
                case (TAMIL_IV_A):
                case (TAMIL_IV_AA):
                case (TAMIL_IV_I):
                case (TAMIL_IV_II):
                case (TAMIL_IV_U):
                case (TAMIL_IV_UU):
                case (TAMIL_IV_E):
                case (TAMIL_IV_EE):
                case (TAMIL_IV_O):
                case (TAMIL_IV_OO):
                case (TAMIL_IV_AU):
                {
                    /* START PMT PUNJABI TELUGU */
                    return ((UI_character_type*) default_tamilmatra1_multitap_strings[i]);
                    /* END PMT PUNJABI TELUGU */
                    break;
                }
                default:
                {
                    return ((UI_character_type*) default_tamil_multitap_strings[i]);
                }

            }
        }
    }
    else
    {
        return ((UI_character_type*) default_tamil_multitap_strings[i]);
    }

}
#endif /* defined (__MMI_MULTITAP_TAMIL__) */ 

#endif /* defined (__MMI_LANG_TAMIL__) */ 

#endif /* __MMI_TAMIL_H__ */ 

