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
 *   Telugu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   C file of telugu font rules 
 *
 * Author:
 *   Satish chandra (pmt00107)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#if defined (__MMI_LANG_TELUGU__)
#include "IndicEngineGprot.h"

const ire_character_info_table_struct telugu_character_info_table[] = 
{

    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc01 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc02 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc03 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc04 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc05 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc06 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc07 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc08 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc09 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc0a */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc0b */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc0c */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc0d */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc0e */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc0f */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc10 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc11 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc12 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc13 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc14 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc15 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc16 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc17 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc18 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc19 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc1a */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc1b */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc1c */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc1d */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc1e */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc1f */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc20 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc21 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc22 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc23 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc24 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc25 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc26 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc27 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc28 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc29 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc2a */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc2b */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc2c */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc2d */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc2e */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc2f */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc30 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc31 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc32 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc33 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc34 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc35 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc36 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc37 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc38 */
    {IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},     /* 0xc39 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc3a */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc3b */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc3c */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc3d */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc3e */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc3f */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc40 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc41 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc42 */
    /* PMT START MAUI_00027700 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0},   /* 0xc43 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0},   /* 0xc44 */      
    /* PMT END MAUI_00027700 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc45 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc46 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc47 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0},       /* 0xc48 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc49 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc4a */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc4b */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc4c */
    {0, 0, 0, IRE_HALANT_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0},       /* 0xc4d */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc4e */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc4f */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc50 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc51 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc52 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc53 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc54 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc55 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0},       /* 0xc56 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc57 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc58 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc59 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc5a */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc5b */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc5c */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc5d */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc5e */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc5f */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc60 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0}, /* 0xc61 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc62 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc63 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc64 */
    {0, 0, 0, 0, 0, 0, 0, 0},   /* 0xc65 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc66 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc67 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc68 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc69 */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc6a */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc6b */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc6c */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc6d */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc6e */
    {0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, IRE_POSTBASE_POSITION, 0},       /* 0xc6f */
};

const ire_character_info_table_struct telugu_ligature_info_table[] = 
{

    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec01 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec02 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec03 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec04 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec05 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec06 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec07 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec08 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec09 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec0a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec0b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec0c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec0d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec0e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec0f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec10 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec11 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec12 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec13 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec14 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec15 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec16 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec17 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec18 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec19 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec1a */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec1b */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec1c */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec1d */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec1e */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec1f */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec20 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec21 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec22 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec23 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec24 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec25 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec26 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec27 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec28 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec29 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec2a */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec2b */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec2c */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec2d */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec2e */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec2f */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec30 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec31 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec32 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec33 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec34 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec35 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec36 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec37 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0},    /* 0xec38 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0},  /* 0xec39 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec3a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec3b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec3c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec3d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec3e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec3f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec40 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec41 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec42 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec43 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec44 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec45 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec46 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec47 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec48 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec49 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec4a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec4b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec4c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec4d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec4e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec4f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec50 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec51 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec52 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec53 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec54 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec55 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec56 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec57 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec58 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec59 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec5a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec5b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec5c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec5d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec5e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec5f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec60 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec61 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec62 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec63 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec64 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec65 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec66 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec67 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec68 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec69 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec6a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec6b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec6c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec6d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec6e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec6f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec70 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec71 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec72 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec73 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec74 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec75 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec76 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec77 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec78 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec79 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec7a */
    /* MTI START MAUI_00029386 */    
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},      /* 0xec7b */
    /* MTI END MAUI_00029386 */        
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec7c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec7d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec7e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec7f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec80 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec81 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec82 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec83 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec84 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec85 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec86 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec87 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec88 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec89 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec8a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec8b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec8c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec8d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec8e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec8f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec90 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec91 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec92 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec93 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec94 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec95 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec96 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec97 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec98 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec99 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec9a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec9b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec9c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec9d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec9e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xec9f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca0 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca1 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca2 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca3 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca4 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca5 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca6 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca7 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca8 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeca9 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecaa */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecab */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecac */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecad */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecae */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecaf */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb0 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb1 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb2 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb3 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb4 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb5 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb6 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb7 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb8 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecb9 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecba */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecbb */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecbc */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecbd */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecbe */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecbf */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc0 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc1 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc2 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc3 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc4 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc5 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc6 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc7 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc8 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecc9 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecca */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeccb */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeccc */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeccd */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecce */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeccf */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd0 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd1 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd2 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd3 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd4 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd5 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd6 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd7 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd8 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecd9 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecda */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecdb */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecdc */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecdd */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecde */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecdf */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece0 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece1 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece2 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece3 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece4 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece5 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece6 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece7 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece8 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xece9 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecea */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeceb */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecec */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xeced */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecee */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecef */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf0 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf1 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf2 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf3 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf4 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf5 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf6 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf7 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf8 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecf9 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecfa */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecfb */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecfc */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecfd */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecfe */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xecff */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed00 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed01 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed02 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed03 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed04 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed05 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed06 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed07 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed08 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed09 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed0a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed0b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed0c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed0d */
    /* PMT START MAUI_00027829 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION, 0},       /* 0xed0e */
    /* PMT END MAUI_00027829 */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed0f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed10 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed11 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed12 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed13 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed14 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed15 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed16 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed17 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed18 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed19 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed1a */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed1b */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed1c */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed1d */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed1e */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed1f */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed20 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed21 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed22 */
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* PMT START MAUI_00027829 */   
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed23 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0},     /* 0xed24 */
    /* PMT END MAUI_00027829 */

};

const ire_glyph_info_table_struct TELUGU_CHANDRA_BINDU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_S_CHANDRA_BINDU, 0x0}, {TELUGU_S_CHANDRA_BINDU, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_ANUSVARA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_S_ANUSVARA, 0x0}, {TELUGU_S_ANUSVARA, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_VISARGA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_S_VISARGA, 0x0}, {TELUGU_S_VISARGA, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_A_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_A, 0x0}, {TELUGU_IV_A, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_AA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_AA, 0x0}, {TELUGU_IV_AA, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_I_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_I, 0x0}, {TELUGU_IV_I, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_II_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_II, 0x0}, {TELUGU_IV_II, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_U_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_U, 0x0}, {TELUGU_IV_U, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_UU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_UU, 0x0}, {TELUGU_IV_UU, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_IV_VR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_VR, 0x0}, {TELUGU_IV_VR, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_IV_VL_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_VL, 0x0}, {TELUGU_IV_VL, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_E_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_E, 0x0}, {TELUGU_IV_E, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_EE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_EE, 0x0}, {TELUGU_IV_EE, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_AI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_AI, 0x0}, {TELUGU_IV_AI, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_O_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_O, 0x0}, {TELUGU_IV_O, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_IV_OO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_OO, 0x0}, {TELUGU_IV_OO, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_IV_AU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_AU, 0x0}, {TELUGU_IV_AU, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_KA_Tbl[] = 
{
    /* KA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_KA, 0x0}, {TELUGU_C_KA, 0x0}},
    /* KA + AA = KAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_AA, 0x0}, {TELUGU_L_KAA, 0x0}},
    /* KA + I = KI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_I, 0x0}, {TELUGU_L_KA, TELUGU_DV_I, 0x0}},
    /* KA + II = KII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_II, 0x0}, {TELUGU_L_KA, TELUGU_DV_II, 0x0}},
    /* PMT START MAUI_00027829 */     
    /* KA + U = KU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_U, 0x0}, {TELUGU_L_KU, 0x0}},
    /* KA + UU = KUU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_UU, 0x0}, {TELUGU_L_KUU, 0x0}},
    /* PMT END MAUI_00027829 */ 
    /* KA + E = KE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_E, 0x0}, {TELUGU_L_KA, TELUGU_DV_E, 0x0}},
    /* KA + EE = KEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_EE, 0x0}, {TELUGU_L_KA, TELUGU_DV_EE, 0x0}},
    /* KA + AI = KAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_AI, 0x0}, {TELUGU_L_KA, TELUGU_DV_AI, 0x0}},
    /* KA + O = KO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_O, 0x0}, {TELUGU_L_KO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* KA + OO = KOO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_OO, 0x0}, {TELUGU_L_KOO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* KA + AU = KAU */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_DV_AU, 0x0}, {TELUGU_L_KAU, 0x0}},
    /* KA + HALANT = K */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_KA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_KA_HALANT, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */

};

const ire_glyph_info_table_struct TELUGU_KHA_Tbl[] = 
{
    /* KHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_KHA, 0x0}, {TELUGU_C_KHA, 0x0}},
    /* KHA + I = KHI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_I, 0x0}, {TELUGU_L_KHI, 0x0}},
    /* KHA + II = KHII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_II, 0x0}, {TELUGU_L_KHII, 0x0}},
    /* KHA + E = KHE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_E, 0x0}, {TELUGU_L_KHE, 0x0}},
    /* KHA + EE = KHEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_KHEE, 0x0}},
    /* KHA + AI = KHAI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_KHAI, 0x0}},
    /* KHA + O = KHO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_O, 0x0}, {TELUGU_L_KHO, 0x0}},
    /* KHA + OO = KHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_KHOO, 0x0}},
    /* KHA + AU = KHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_KHAU, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* KHA + HALANT = KH */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_KHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_KHA_HALANT, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */

};

const ire_glyph_info_table_struct TELUGU_GA_Tbl[] = 
{
    /* GA  */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_GA, 0x0}, {TELUGU_C_GA, 0x0}},
    /* GA + AA = GAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_AA, 0x0}, {TELUGU_L_GAA, 0x0}},
    /* GA + I = GI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_I, 0x0}, {TELUGU_L_GA, TELUGU_DV_I, 0x0}},
    /* GA + II = GII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_II, 0x0}, {TELUGU_L_GA, TELUGU_DV_II, 0x0}},
    /* GA + E = GE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_E, 0x0}, {TELUGU_L_GA, TELUGU_DV_E, 0x0}},
    /* GA + EE = GEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_EE, 0x0}, {TELUGU_L_GA, TELUGU_DV_EE, 0x0}},
    /* GA + AI = GAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_AI, 0x0}, {TELUGU_L_GA, TELUGU_DV_AI, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* GA + O = GO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_O, 0x0}, {TELUGU_L_GO, 0x0}},
    /* GA + OO = GOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_OO, 0x0}, {TELUGU_L_GOO, 0x0}},
    /* GA + AU = GAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_DV_AU, 0x0}, {TELUGU_L_GAU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* GA + AU = GAU */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_GA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_GA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_GHA_Tbl[] = 
{
    /* GHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_GHA, 0x0}, {TELUGU_C_GHA, 0x0}},
    /* GHA + I = GHI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_I, 0x0}, {TELUGU_L_GHA, TELUGU_DV_I, 0x0}},
    /* GHA + II = GHII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_II, 0x0}, {TELUGU_L_GHA, TELUGU_DV_II, 0x0}},
    /* GHA + E = GHE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_E, 0x0}, {TELUGU_L_GHE, 0x0}},
    /* GHA + EE = GHEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_GHEE, 0x0}},
    /* GHA + AI = GHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_GHE, TELUGU_ADV_AI, 0x0}},
    /* GHA + O = GHO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_O, 0x0}, {TELUGU_L_GHE, TELUGU_DV_U, 0x0}},
    /* GHA + OO = GHOO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_GHE, TELUGU_DV_AA, 0x0}},
    /* GHA + AU = GHAU */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_GHAU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* PMT START MAUI_00027829 */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_GHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_GHA, TELUGU_S_HALANT, 0x0}},
    /* PMT END MAUI_00027829 */

};

const ire_glyph_info_table_struct TELUGU_NGA_Tbl[] = 
{
    /* NGA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_NGA, 0x0}, {TELUGU_C_NGA, 0x0}},
    /* NGA + AA = NGAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_AA, 0x0}, {TELUGU_L_NGAA, 0x0}},
    /* NGA + I = NGI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_I, 0x0}, {TELUGU_L_NGI, 0x0}},
    /* NGA + II = NGII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_II, 0x0}, {TELUGU_L_NGII, 0x0}},
    /* NGA + U = NGU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_U, 0x0}, {TELUGU_L_NGU, 0x0}},
    /* NGA + UU = NGUU */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_UU, 0x0}, {TELUGU_L_NGU, TELUGU_DV_AA, 0x0}},
    /* NGA + E = NGE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_E, 0x0}, {TELUGU_L_NGE, 0x0}},
    /* NGA + EE = NGEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_EE, 0x0}, {TELUGU_L_NGEE, 0x0}},
    /* NGA + AI = NAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_AI, 0x0}, {TELUGU_L_NGE, TELUGU_ADV_AI, 0x0}},
    /* NGA + O = NO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_O, 0x0}, {TELUGU_L_NGO, 0x0}},
    /* NGA + OO = NOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_OO, 0x0}, {TELUGU_L_NGOO, 0x0}},
    /* NGA + AU = NAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NGA, TELUGU_DV_AU, 0x0}, {TELUGU_L_NGAU, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_CA_Tbl[] = 
{
    /* CA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_CA, 0x0}, {TELUGU_C_CA, 0x0}},
    /* CA + AA = CAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_AA, 0x0}, {TELUGU_L_CAA, 0x0}},
    /* CA + I = CI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_I, 0x0}, {TELUGU_L_CI, 0x0}},
    /* CA + II = CII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_II, 0x0}, {TELUGU_L_CII, 0x0}},
    /* CA + E = CE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_E, 0x0}, {TELUGU_L_CE, 0x0}},
    /* CA + E = CEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_EE, 0x0}, {TELUGU_L_CEE, 0x0}},
    /* CA + AI = CAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_AI, 0x0}, {TELUGU_L_CE, TELUGU_ADV_AI, 0x0}},
    /* CA + O = CO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_O, 0x0}, {TELUGU_L_CO, 0x0}},
    /* CA + OO = COO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_OO, 0x0}, {TELUGU_L_COO, 0x0}},
    /* CA + AU = CAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_DV_AU, 0x0}, {TELUGU_L_CAU, 0x0}},
    /* CA + HALANT = C */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_CA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_C_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_CHA_Tbl[] = 
{
    /* CHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_CHA, 0x0}, {TELUGU_C_CHA, 0x0}},
    /* CHA + AA = CHAA */
    /* PMT START MAUI_00027684 */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_AA, 0x0}, {TELUGU_L_CHAA, 0x0}},
    /* PMT END MAUI_00027684 */
    /* CHA + I = CHI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_I, 0x0}, {TELUGU_L_CHI, 0x0}},
    /* CHA + II = CHII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_II, 0x0}, {TELUGU_L_CHII, 0x0}},
    /* CHA + E = CHE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_E, 0x0}, {TELUGU_L_CHE, 0x0}},
    /* CHA + E = CHEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_CHEE, 0x0}},
    /* CHA + AI = CHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_CHE, TELUGU_ADV_AI, 0x0}},
    /* CHA + O = CHO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_O, 0x0}, {TELUGU_L_CHO, 0x0}},
    /* CHA + OO = CHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_CHOO, 0x0}},
    /* CHA + AU = CHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_CHAU, 0x0}},
    /* CHA + HALANT = CH */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_CHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_CH_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_JA_Tbl[] = 
{
    /* JA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_JA, 0x0}, {TELUGU_C_JA, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* JA + AA = JAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_AA, 0x0}, {TELUGU_L_JAA, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* JA + I = JI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_I, 0x0}, {TELUGU_L_JI, 0x0}},
    /* JA + II = JII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_II, 0x0}, {TELUGU_L_JII, 0x0}},
    /* JA + U = JU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_U, 0x0}, {TELUGU_L_JU, 0x0}},
    /* JA + UU = JUU */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_UU, 0x0}, {TELUGU_L_JU, TELUGU_DV_AA, 0x0}},
    /* JA + E = JE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_E, 0x0}, {TELUGU_L_JE, 0x0}},
    /* JA + EE = JEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_EE, 0x0}, {TELUGU_L_JEE, 0x0}},
    /* MTI START MAUI_00029386 */
    /* JA + AI = JAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_AI, 0x0}, {TELUGU_L_JE, TELUGU_ADV_AI, 0x0}},
    /* MTI END MAUI_00029386 */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* JA + O = JO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_O, 0x0}, {TELUGU_L_JO, 0x0}},
    /* JA + O = JO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_OO, 0x0}, {TELUGU_L_JOO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* JA + AU = JAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_DV_AU, 0x0}, {TELUGU_L_JAU, 0x0}},
    /* JA + HALANT = J */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_JA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_JA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_JHA_Tbl[] = 
{
    /* JHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_JHA, 0x0}, {TELUGU_C_JHA, 0x0}},
    /* JHA + I = JHI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_I, 0x0}, {TELUGU_L_JHA, TELUGU_DV_I, 0x0}},
    /* JHA + II = JHII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_II, 0x0}, {TELUGU_L_JHA, TELUGU_DV_II, 0x0}},
    /* JHA + E = JHE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_E, 0x0}, {TELUGU_L_JHA, TELUGU_DV_E, 0x0}},
    /* JHA + EE = JHEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_JHA, TELUGU_DV_EE, 0x0}},
    /* JHA + AI = JHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_JHA, TELUGU_DV_AI, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* JHA + O = JHO */
    {0, 2, 3, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_O, 0x0}, {TELUGU_L_JHA, TELUGU_DV_E, TELUGU_DV_U, 0x0}},
    /* JHA + OO = JHOO */
    {0, 2, 3, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_JHA, TELUGU_DV_E, TELUGU_DV_AA, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* JHA + AU = JHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_JHAU, 0x0}},
    /* JHA + HALANT = JH */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_JHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_JHA, TELUGU_S_HALANT, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */

};

const ire_glyph_info_table_struct TELUGU_NYA_Tbl[] = 
{
    /* NYA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_NYA, 0x0}, {TELUGU_C_NYA, 0x0}},
    /* NYA + AA = NYAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_AA, 0x0}, {TELUGU_L_NYAA, 0x0}},
    /* NYA + I = NYI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_I, 0x0}, {TELUGU_L_NYI, 0x0}},
    /* NYA + II = NYII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_II, 0x0}, {TELUGU_L_NYII, 0x0}},
    /* NYA + U = NYU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_U, 0x0}, {TELUGU_L_NYU, 0x0}},
    /* NYA + UU = NYUU */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_UU, 0x0}, {TELUGU_L_NYU, TELUGU_DV_AA, 0x0}},
    /* NYA + E = NYE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_E, 0x0}, {TELUGU_L_NYE, 0x0}},
    /* NYA + EE = NYEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_EE, 0x0}, {TELUGU_L_NYEE, 0x0}},
    /* NYA + AI = NYAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_AI, 0x0}, {TELUGU_L_NYE, TELUGU_ADV_AI, 0x0}},
    /* NYA + O = NYO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_O, 0x0}, {TELUGU_L_NYO, 0x0}},
    /* NYA + OO = NYOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_OO, 0x0}, {TELUGU_L_NYOO, 0x0}},
    /* NYA + O = NYO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_DV_AU, 0x0}, {TELUGU_L_NYAU, 0x0}},
    /* NYA + O = NYO */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_NYA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_NY_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_TTA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_TTA, 0x0}, {TELUGU_C_TTA, 0x0}},
    /* TTA + I = TTI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_I, 0x0}, {TELUGU_L_TTI, 0x0}},
    /* TTA + II = TTII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_II, 0x0}, {TELUGU_L_TTII, 0x0}},
    /* TTA + E = TTE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_E, 0x0}, {TELUGU_L_TTE, 0x0}},
    /* TTA + EE = TTEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_EE, 0x0}, {TELUGU_L_TTEE, 0x0}},
    /* TTA + AI = TTAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_AI, 0x0}, {TELUGU_L_TTE, TELUGU_ADV_AI, 0x0}},
    /* TTA + O = TTO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_O, 0x0}, {TELUGU_L_TTO, 0x0}},
    /* TTA + OO = TTOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_OO, 0x0}, {TELUGU_L_TTOO, 0x0}},
    /* TTA + O = TTO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_DV_AU, 0x0}, {TELUGU_L_TTAU, 0x0}},
    /* TTA + O = TTO */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_TT_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_TTHA_Tbl[] = 
{

    /* TTHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_TTHA, 0x0}, {TELUGU_C_TTHA, 0x0}},
    /* TTHAA + AA = TTHAAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_AA, 0x0}, {TELUGU_L_TTHAA, 0x0}},
    /* TTHAA + I = TTHI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_I, 0x0}, {TELUGU_L_TTHA, TELUGU_DV_I, 0x0}},
    /* TTHAA + II = TTHII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_II, 0x0}, {TELUGU_L_TTHA, TELUGU_DV_II, 0x0}},
    /* TTHAA + E = TTHE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_E, 0x0}, {TELUGU_L_TTHA, TELUGU_DV_E, 0x0}},
    /* TTHAA + EE = TTHEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_TTHA, TELUGU_DV_EE, 0x0}},
    /* TTHAA + AI = TTHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_TTHA, TELUGU_DV_AI, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* TTHAA + O = TTHO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_O, 0x0}, {TELUGU_L_TTHO, 0x0}},
    /* TTHAA + OO = TTHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_TTHOO, 0x0}},
    /* TTHAA + AU = TTHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_TTHAU, 0x0}},
    /* TTHAA + HALANT = TTH */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_TTHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_TTHA, TELUGU_S_HALANT, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */

};

const ire_glyph_info_table_struct TELUGU_DDA_Tbl[] = 
{
    /* DDA  */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_DDA, 0x0}, {TELUGU_C_DDA, 0x0}},
    /* DDA + AA = DDAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_AA, 0x0}, {TELUGU_L_DDAA, 0x0}},
    /* DDA + I = DDI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_I, 0x0}, {TELUGU_L_DDA, TELUGU_DV_I, 0x0}},
    /* DDA + II = DDII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_II, 0x0}, {TELUGU_L_DDA, TELUGU_DV_II, 0x0}},
    /* DDA + E = DDE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_E, 0x0}, {TELUGU_L_DDA, TELUGU_DV_E, 0x0}},
    /* DDA + EE = DDEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_EE, 0x0}, {TELUGU_L_DDA, TELUGU_DV_EE, 0x0}},
    /* DDA + AI = DDAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_AI, 0x0}, {TELUGU_L_DDA, TELUGU_DV_AI, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* DDA + O = DDO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_O, 0x0}, {TELUGU_L_DDO, 0x0}},
    /* DDA + OO = DDOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_OO, 0x0}, {TELUGU_L_DDOO, 0x0}},
    /* DDA + AU = DDAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_DV_AU, 0x0}, {TELUGU_L_DDAU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* DDA + HALANT = DD */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_DDA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_DDHA_Tbl[] = 
{
    /* DDA  */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_DDHA, 0x0}, {TELUGU_C_DDHA, 0x0}},
    /* DDHA + AA = DDHAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_AA, 0x0}, {TELUGU_L_DDHAA, 0x0}},
    /* DDHA + I = DDHI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_I, 0x0}, {TELUGU_L_DDHI, 0x0}},
    /* DDHA + II = DDHII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_II, 0x0}, {TELUGU_L_DDHII, 0x0}},
    /* DDHA + E = DDHE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_E, 0x0}, {TELUGU_L_DDHA, TELUGU_DV_E, 0x0}},
    /* DDHA + EE = DDHEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_DDHA, TELUGU_DV_EE, 0x0}},
    /* DDHA + AI = DDHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_DDHA, TELUGU_DV_AI, 0x0}},
    /* DDHA + O = DDHO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_O, 0x0}, {TELUGU_L_DDHO, 0x0}},
    /* DDHA + OO = DDHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_DDHOO, 0x0}},
    /* DDHA + AU = DDHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_DDHAU, 0x0}},
    /* DDHA + HALANT = DDH */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_DDHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_DDHA, TELUGU_S_HALANT, 0x0}},
};

const ire_glyph_info_table_struct TELUGU_NNA_Tbl[] = 
{
    /* NNA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_NNA, 0x0}, {TELUGU_C_NNA, 0x0}},
    /* NNA + AA = NNAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NNA, TELUGU_DV_AA, 0x0}, {TELUGU_L_NNAA, 0x0}},
    /* NNA + I = NNI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NNA, TELUGU_DV_I, 0x0}, {TELUGU_L_NNI, 0x0}},
    /* NNA + II = NNII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NNA, TELUGU_DV_II, 0x0}, {TELUGU_L_NNII, 0x0}},
    /* NNA + O = NNO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NNA, TELUGU_DV_O, 0x0}, {TELUGU_L_NNO, 0x0}},
    /* NNA + OO = NNOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NNA, TELUGU_DV_OO, 0x0}, {TELUGU_L_NNOO, 0x0}},
    /* NNA + AU = NNAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NNA, TELUGU_DV_AU, 0x0}, {TELUGU_L_NNAU, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_TA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_TA, 0x0}, {TELUGU_C_TA, 0x0}},
    /* TA + AA = TAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_AA, 0x0}, {TELUGU_L_TAA, 0x0}},
    /* TA + I = TI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_I, 0x0}, {TELUGU_L_TI, 0x0}},
    /* TA + II = TII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_II, 0x0}, {TELUGU_L_TII, 0x0}},
    /* TA + E = TE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_E, 0x0}, {TELUGU_L_TE, 0x0}},
    /* TA + EE = TEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_EE, 0x0}, {TELUGU_L_TEE, 0x0}},
    /* TA + AI = TAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_AI, 0x0}, {TELUGU_L_TE, TELUGU_ADV_AI, 0x0}},
    /* TA + O = TO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_O, 0x0}, {TELUGU_L_TO, 0x0}},
    /* TA + OO = TOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_OO, 0x0}, {TELUGU_L_TOO, 0x0}},
    /* TA + AU = TAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_DV_AU, 0x0}, {TELUGU_L_TAU, 0x0}},
    /* TA + HALANT = T */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_TA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_TA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_THA_Tbl[] = 
{
    /* THA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_THA, 0x0}, {TELUGU_C_THA, 0x0}},
    /* THA + AA = THAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_AA, 0x0}, {TELUGU_L_THAA, 0x0}},
    /* THA + I = THI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_I, 0x0}, {TELUGU_L_THI, 0x0}},
    /* THA + II = THII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_II, 0x0}, {TELUGU_L_THII, 0x0}},
    /* THA + E = THE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_E, 0x0}, {TELUGU_L_THA, TELUGU_DV_E, 0x0}},
    /* THA + EE = THEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_EE, 0x0}, {TELUGU_L_THA, TELUGU_DV_EE, 0x0}},
    /* THA + AI = THAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_AI, 0x0}, {TELUGU_L_THA, TELUGU_DV_AI, 0x0}},
    /* THA + O = THO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_O, 0x0}, {TELUGU_L_THO, 0x0}},
    /* THA + OO = THOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_OO, 0x0}, {TELUGU_L_THOO, 0x0}},
    /* THA + AU = THAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_DV_AU, 0x0}, {TELUGU_L_THAU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* THA + HALANT = TH */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_THA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_THA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_DA_Tbl[] = 
{
    /* DA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_DA, 0x0}, {TELUGU_C_DA, 0x0}},
    /* DA + AA = DAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_AA, 0x0}, {TELUGU_L_DAA, 0x0}},
    /* DA + I = DI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_I, 0x0}, {TELUGU_L_DI, 0x0}},
    /* DA + II = DII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_II, 0x0}, {TELUGU_L_DII, 0x0}},
    /* DA + E = DE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_E, 0x0}, {TELUGU_L_DA, TELUGU_DV_E, 0x0}},
    /* DA + EE = DEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_EE, 0x0}, {TELUGU_L_DA, TELUGU_DV_EE, 0x0}},
    /* DA + AI = DAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_AI, 0x0}, {TELUGU_L_DA, TELUGU_DV_AI, 0x0}},
    /* DA + O = DO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_O, 0x0}, {TELUGU_L_DO, 0x0}},
    /* DA + OO = DOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_OO, 0x0}, {TELUGU_L_DOO, 0x0}},
    /* DA + AU = DAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_DV_AU, 0x0}, {TELUGU_L_DAU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* DA + HALANT = D */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_DA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_DA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_DHA_Tbl[] = 
{
    /* DHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_DHA, 0x0}, {TELUGU_C_DHA, 0x0}},
    /* DHA + AA = DHAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_AA, 0x0}, {TELUGU_L_DHAA, 0x0}},
    /* DHA + I = DHI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_I, 0x0}, {TELUGU_L_DHI, 0x0}},
    /* DHA + II = DHII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_II, 0x0}, {TELUGU_L_DHII, 0x0}},
    /* DHA + E = DHE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_E, 0x0}, {TELUGU_L_DHA, TELUGU_DV_E, 0x0}},
    /* DHA + EE = DHEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_DHA, TELUGU_DV_EE, 0x0}},
    /* DHA + AI = DHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_DHA, TELUGU_DV_AI, 0x0}},
    /* DHA + O = DHO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_O, 0x0}, {TELUGU_L_DHO, 0x0}},
    /* DHA + OO = DHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_DHOO, 0x0}},
    /* DHA + AU = DHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_DHAU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* DHA + HALANT = DH */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_DHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_DHA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_NA_Tbl[] = 
{
    /* NA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_NA, 0x0}, {TELUGU_C_NA, 0x0}},
    /* NA + AA = NAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_AA, 0x0}, {TELUGU_L_NAA, 0x0}},
    /* NA + I = NI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_I, 0x0}, {TELUGU_L_NI, 0x0}},
    /* NA + II = NII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_II, 0x0}, {TELUGU_L_NII, 0x0}},
    /* NA + E = NE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_E, 0x0}, {TELUGU_L_NA, TELUGU_DV_E, 0x0}},
    /* NA + EE = NEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_EE, 0x0}, {TELUGU_L_NA, TELUGU_DV_EE, 0x0}},
    /* NA + AI = NAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_AI, 0x0}, {TELUGU_L_NA, TELUGU_DV_AI, 0x0}},
    /* NA + O = NO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_O, 0x0}, {TELUGU_L_NA, TELUGU_DV_O, 0x0}},
    /* NA + OO = NOO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_OO, 0x0}, {TELUGU_L_NA, TELUGU_DV_OO, 0x0}},
    /* NA + AU = NAU */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_DV_AU, 0x0}, {TELUGU_L_NA, TELUGU_DV_AU, 0x0}},
    /* NA + HALANT = N */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_NA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_NA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_PA_Tbl[] = 
{

    /*  PA  */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_PA, 0x0}, {TELUGU_C_PA, 0x0}},
    /* PA + AA = PAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_AA, 0x0}, {TELUGU_L_PAA, 0x0}},
    /* PA + I = PI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_I, 0x0}, {TELUGU_L_PA, TELUGU_DV_I, 0x0}},
    /* PA + II = PII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_II, 0x0}, {TELUGU_L_PA, TELUGU_DV_II, 0x0}},
    /* PA + U = PU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_U, 0x0}, {TELUGU_L_PU, 0x0}},
    /* PA + UU = PUU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_UU, 0x0}, {TELUGU_L_PUU, 0x0}},
    /* PA + E = PE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_E, 0x0}, {TELUGU_L_PA, TELUGU_DV_E, 0x0}},
    /* PA + EE = PEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_EE, 0x0}, {TELUGU_L_PA, TELUGU_DV_EE, 0x0}},
    /* PA + AI = PAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_AI, 0x0}, {TELUGU_L_PA, TELUGU_DV_AI, 0x0}},
    /* PA + O = PO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_O, 0x0}, {TELUGU_L_PO, 0x0}},
    /* PA + OO = POO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_OO, 0x0}, {TELUGU_L_POO, 0x0}},
    /* PA + AU = PAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_DV_AU, 0x0}, {TELUGU_L_PAU, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* PA + HALANT = P */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_PA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_PA, TELUGU_S_HALANT, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */

};

const ire_glyph_info_table_struct TELUGU_PHA_Tbl[] = 
{
    /* PHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_PHA, 0x0}, {TELUGU_C_PHA, 0x0}},
    /* PHA + AA = PHAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_AA, 0x0}, {TELUGU_L_PHAA, 0x0}},
    /* PHA + I = PHI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_I, 0x0}, {TELUGU_L_PHA, TELUGU_DV_I, 0x0}},
    /* PHA + II = PHII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_II, 0x0}, {TELUGU_L_PHA, TELUGU_DV_II, 0x0}},
    /* PHA + U = PHU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_U, 0x0}, {TELUGU_L_PHU, 0x0}},
    /* PHA + UU = PHUU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_UU, 0x0}, {TELUGU_L_PHUU, 0x0}},
    /* PHA + E = PHE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_E, 0x0}, {TELUGU_L_PHA, TELUGU_DV_E, 0x0}},
    /* PHA + EE = PHEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_PHA, TELUGU_DV_EE, 0x0}},
    /* PHA + AI = PHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_PHA, TELUGU_DV_AI, 0x0}},
    /* PHA + O = PHO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_O, 0x0}, {TELUGU_L_PHO, 0x0}},
    /* PHA + OO = PHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_PHOO, 0x0}},
    /* PHA + AU = PHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_PHAU, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* PHA + HALANT = PH */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_PHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_PHA, TELUGU_S_HALANT, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */

};

const ire_glyph_info_table_struct TELUGU_BA_Tbl[] = 
{
    /* BA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_BA, 0x0}, {TELUGU_C_BA, 0x0}},
    /* BA + AA = BAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_AA, 0x0}, {TELUGU_L_BAA, 0x0}},
    /* BA + I = BI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_I, 0x0}, {TELUGU_L_BI, 0x0}},
    /* BA + II = BII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_II, 0x0}, {TELUGU_L_BII, 0x0}},
    /* BA + E = BE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_E, 0x0}, {TELUGU_L_BE, 0x0}},
    /* BA + EE = BEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_EE, 0x0}, {TELUGU_L_BEE, 0x0}},
    /* BA + AI = BAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_AI, 0x0}, {TELUGU_L_BE, TELUGU_ADV_AI, 0x0}},
    /* BA + O = BO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_O, 0x0}, {TELUGU_L_BO, 0x0}},
    /* BA + OO = BOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_OO, 0x0}, {TELUGU_L_BOO, 0x0}},
    /* BA + AU = BAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_DV_AU, 0x0}, {TELUGU_L_BAU, 0x0}},
    /* BA + HALANT = B */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_BA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_BA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_BHA_Tbl[] = 
{
    /* BHA */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_BHA, 0x0}, {TELUGU_C_BHA, 0x0}},
    /* BHA + AA = BHAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_AA, 0x0}, {TELUGU_L_BHAA, 0x0}},
    /* BHA + I = BHI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_I, 0x0}, {TELUGU_L_BHI, 0x0}},
    /* BHA + II = BHII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_II, 0x0}, {TELUGU_L_BHII, 0x0}},
    /* BHA + E = BHE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_E, 0x0}, {TELUGU_L_BHE, 0x0}},
    /* BHA + EE = BHEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_BHEE, 0x0}},
    /* BHA + AI = BHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_BHE, TELUGU_ADV_AI, 0x0}},
    /* BHA + O = BHO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_O, 0x0}, {TELUGU_L_BHO, 0x0}},
    /* BHA + OO = BHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_BHOO, 0x0}},
    /* BHA + AU = BHAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_BHAU, 0x0}},
    /* BHA + HALANT = BH */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_BHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_BHA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_MA_Tbl[] = 
{
    /* MA  */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_MA, 0x0}, {TELUGU_C_MA, 0x0}},
    /* MA + I = MI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_I, 0x0}, {TELUGU_L_MA, TELUGU_DV_I, 0x0}},
    /* MA + II = MII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_II, 0x0}, {TELUGU_L_MA, TELUGU_DV_II, 0x0}},
    /* MA + E = ME */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_E, 0x0}, {TELUGU_L_MA, TELUGU_DV_E, 0x0}},
    /* MA + EE = MEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_EE, 0x0}, {TELUGU_L_MA, TELUGU_DV_EE, 0x0}},
    /* MA + AI = MAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_AI, 0x0}, {TELUGU_L_MA, TELUGU_DV_AI, 0x0}},
    /* MA + O = MO */
    {0, 2, 3, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_O, 0x0}, {TELUGU_L_MA, TELUGU_DV_E, TELUGU_DV_U, 0x0}},
    /* MA + OO = MOO */
    {0, 2, 3, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_OO, 0x0}, {TELUGU_L_MA, TELUGU_DV_E, TELUGU_DV_AA, 0x0}},
    /* MA + AU = MAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_DV_AU, 0x0}, {TELUGU_L_MAU, 0x0}},
    /* MA + AU = MAU */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_MA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_MA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_YA_Tbl[] = 
{
    /* YA  */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_YA, 0x0}, {TELUGU_C_YA, 0x0}},
    /* YA + I = YI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_I, 0x0}, {TELUGU_L_YA, 0x0}},
    /* YA + II = YII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_II, 0x0}, {TELUGU_L_YA, TELUGU_DV_AA, 0x0}},
    /* YA + E = YE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_E, 0x0}, {TELUGU_L_YE, 0x0}},
    /* YA + EE = YEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_EE, 0x0}, {TELUGU_L_YEE, 0x0}},
    /* YA + AI = YAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_AI, 0x0}, {TELUGU_L_YE, TELUGU_ADV_AI, 0x0}},
    /* YA + O = YO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_O, 0x0}, {TELUGU_L_YE, TELUGU_DV_U, 0x0}},
    /* YA + OO = YOO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_OO, 0x0}, {TELUGU_L_YE, TELUGU_DV_AA, 0x0}},
    /* YA + AU = YAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_DV_AU, 0x0}, {TELUGU_L_YAU, 0x0}},
    /* YA + AU = YAU */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_YA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_YA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_RA_Tbl[] = 
{
    /* RA  */
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_RA, 0x0}, {TELUGU_C_RA, 0x0}},
    /* RA + AA = RAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_AA, 0x0}, {TELUGU_L_RAA, 0x0}},

    /* RA + I = RI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_I, 0x0}, {TELUGU_L_RA, TELUGU_DV_I, 0x0}},
    /* RA + II = RII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_II, 0x0}, {TELUGU_L_RA, TELUGU_DV_II, 0x0}},
    /* RA + E = RE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_E, 0x0}, {TELUGU_L_RA, TELUGU_DV_E, 0x0}},
    /* RA + EE = REE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_EE, 0x0}, {TELUGU_L_RA, TELUGU_DV_EE, 0x0}},
    /* RA + AI = RAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_AI, 0x0}, {TELUGU_L_RA, TELUGU_DV_AI, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* RA + O = RO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_O, 0x0}, {TELUGU_L_RO, 0x0}},
    /* RA + OO = ROO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_OO, 0x0}, {TELUGU_L_ROO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* RA + AU = RAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_DV_AU, 0x0}, {TELUGU_L_RAU, 0x0}},
    /* RA + HALANT = R */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_RA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_RA, TELUGU_S_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_RRA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_RRA, 0x0}, {TELUGU_C_RRA, 0x0}},
    /* RRA + AA = RRAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_AA, 0x0}, {TELUGU_L_RRAA, 0x0}},
    /* RRA + I = RRI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_I, 0x0}, {TELUGU_L_RRI, 0x0}},
    /* RRA + II = RRII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_II, 0x0}, {TELUGU_L_RRII, 0x0}},
    /* RRA + E = RRE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_E, 0x0}, {TELUGU_L_RRE, 0x0}},
    /* RRA + EE = RREE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_EE, 0x0}, {TELUGU_L_RREE, 0x0}},
    /* RRA + AI = RRAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_AI, 0x0}, {TELUGU_L_RRE, TELUGU_ADV_AI, 0x0}},
    /* RRA + O = RRO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_O, 0x0}, {TELUGU_L_RRO, 0x0}},
    /* RRA + OO = RROO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_OO, 0x0}, {TELUGU_L_RROO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* RRA + AU = RRAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_DV_AU, 0x0}, {TELUGU_L_RRAU, 0x0}},
    /* RRA + HALANT = RR */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_RRA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_RRA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_LA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_LA, 0x0}, {TELUGU_C_LA, 0x0}},
    /* LA + AA = LAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_AA, 0x0}, {TELUGU_L_LAA, 0x0}},
    /* LA + I = LI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_I, 0x0}, {TELUGU_L_LI, 0x0}},
    /* LA + II = LII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_II, 0x0}, {TELUGU_L_LII, 0x0}},
    /* LA + E = LE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_E, 0x0}, {TELUGU_L_LE, 0x0}},
    /* LA + EE = LEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_EE, 0x0}, {TELUGU_L_LEE, 0x0}},
    /* LA + AI = LAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_AI, 0x0}, {TELUGU_L_LE, TELUGU_ADV_AI, 0x0}},
    /* LA + O = LO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_O, 0x0}, {TELUGU_L_LO, 0x0}},
    /* LA + OO = LOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_OO, 0x0}, {TELUGU_L_LOO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* LA + AU = LAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_DV_AU, 0x0}, {TELUGU_L_LAU, 0x0}},
    /* LA + HALANT = L */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_LA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_LA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_LLA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_LLA, 0x0}, {TELUGU_C_LLA, 0x0}},
    /* LLA + AA = LLAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_AA, 0x0}, {TELUGU_L_LLAA, 0x0}},
    /* LLA + I = LLI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_I, 0x0}, {TELUGU_L_LLI, 0x0}},
    /* LLA + II = LLII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_II, 0x0}, {TELUGU_L_LLII, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* LLA + U = LLU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_U, 0x0}, {TELUGU_L_LLU, 0x0}},
    /* LLA + II = LLII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_UU, 0x0}, {TELUGU_L_LLUU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* LLA + E = LLE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_E, 0x0}, {TELUGU_L_LLE, 0x0}},
    /* LLA + EE = LLEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_EE, 0x0}, {TELUGU_L_LLEE, 0x0}},
    /* LLA + AI = LLAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_AI, 0x0}, {TELUGU_L_LLE, TELUGU_ADV_AI, 0x0}},
    /* LLA + O = LLO */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_O, 0x0}, {TELUGU_L_LLO, 0x0}},
    /* LLA + OO = LLOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_OO, 0x0}, {TELUGU_L_LLOO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* LLA + AU = LLAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_DV_AU, 0x0}, {TELUGU_L_LLAU, 0x0}},
    /* LLA + HALANT = LL */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_LLA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_LLA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_VA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_VA, 0x0}, {TELUGU_C_VA, 0x0}},
    /* VA + AA = VAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_AA, 0x0}, {TELUGU_L_VAA, 0x0}},
    /* VA + I = VI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_I, 0x0}, {TELUGU_L_VI, 0x0}},
    /* VA + II = VII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_II, 0x0}, {TELUGU_L_VII, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* VA + U = VU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_U, 0x0}, {TELUGU_L_VU, 0x0}},
    /* VA + UU = VUU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_UU, 0x0}, {TELUGU_L_VUU, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* VA + E = VE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_E, 0x0}, {TELUGU_L_VE, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* VA + EE = VEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_EE, 0x0}, {TELUGU_L_VEE, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* VA + AI = VAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_AI, 0x0}, {TELUGU_L_VE, TELUGU_ADV_AI, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* VA + O = VO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_O, 0x0}, {TELUGU_L_VO, 0x0}},
    /* VA + OO = VOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_OO, 0x0}, {TELUGU_L_VOO, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* VA + AU = VAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_DV_AU, 0x0}, {TELUGU_L_VAU, 0x0}},
    /* VA + HALANT = V */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_VA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_VA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_SHA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_SHA, 0x0}, {TELUGU_C_SHA, 0x0}},
    /* SHA + AA = SHAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_AA, 0x0}, {TELUGU_L_SHAA, 0x0}},
    /* SHA + I = SHI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_I, 0x0}, {TELUGU_L_SHI, 0x0}},
    /* SHA + II = SHII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_II, 0x0}, {TELUGU_L_SHII, 0x0}},
    /* SHA + E = SHE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_E, 0x0}, {TELUGU_L_SHE, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* SHA + EE = SHEE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_EE, 0x0}, {TELUGU_L_SHEE, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* SHA + AI = SHAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_AI, 0x0}, {TELUGU_L_SHE, TELUGU_ADV_AI, 0x0}},
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* SHA + O = SHO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_O, 0x0}, {TELUGU_L_SHO, 0x0}},
    /* SHA + OO = SHOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_OO, 0x0}, {TELUGU_L_SHOO, 0x0}},
    /* SHA + AU = SHAU */
    /* 7.24 PMT  END TELUGU & PUNJABI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_DV_AU, 0x0}, {TELUGU_L_SHAU, 0x0}},
    /* SHA + HALANT = SH */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_SHA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_SHA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_SSA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_SSA, 0x0}, {TELUGU_C_SSA, 0x0}},
    /* SSA + AA = SSAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_AA, 0x0}, {TELUGU_L_SSAA, 0x0}},
    /* SSA + I = SSI */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_I, 0x0}, {TELUGU_L_SSI, 0x0}},
    /* SSA + II = SSII */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_II, 0x0}, {TELUGU_L_SSII, 0x0}},
    /* SSA + E = SSE */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_E, 0x0}, {TELUGU_L_SSE, 0x0}},
    /* SSA + EE = SSEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_EE, 0x0}, {TELUGU_L_SSEE, 0x0}},
    /* SSA + AI = SSAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_AI, 0x0}, {TELUGU_L_SSE, TELUGU_ADV_AI, 0x0}},
    /* SSA + O = SSO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_O, 0x0}, {TELUGU_L_SSO, 0x0}},
    /* SSA + OO = SSOO */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_OO, 0x0}, {TELUGU_L_SSOO, 0x0}},
    /* SSA + AU = SSAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_DV_AU, 0x0}, {TELUGU_L_SSAU, 0x0}},
    /* SSA + HALANT = SS */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_SSA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_SSA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_SA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_SA, 0x0}, {TELUGU_C_SA, 0x0}},
    /* SA + AA = SAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_AA, 0x0}, {TELUGU_L_SAA, 0x0}},
    /* SA + I = SI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_I, 0x0}, {TELUGU_L_SA, TELUGU_DV_I, 0x0}},
    /* SA + II = SII */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_II, 0x0}, {TELUGU_L_SA, TELUGU_DV_II, 0x0}},
    /* SA + E = SE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_E, 0x0}, {TELUGU_L_SA, TELUGU_DV_E, 0x0}},
    /* SA + EE = SEE */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_EE, 0x0}, {TELUGU_L_SA, TELUGU_DV_EE, 0x0}},
    /* SA + AI = SAI */
    {0, 2, 2, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_AI, 0x0}, {TELUGU_L_SA, TELUGU_DV_AI, 0x0}},
    /* SA + O = SO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_O, 0x0}, {TELUGU_L_SO, 0x0}},
    /* SA + OO = SOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_OO, 0x0}, {TELUGU_L_SOO, 0x0}},
    /* SA + AU = SAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_DV_AU, 0x0}, {TELUGU_L_SAU, 0x0}},
    /* SA + HALANT = S */
    {1, 2, 1, MMI_ALL_LANG, {TELUGU_C_SA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_SA_HALANT, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_HA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_C_HA, 0x0}, {TELUGU_C_HA, 0x0}},
    /* HA + AA = HAA */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_AA, 0x0}, {TELUGU_L_HAA, 0x0}},
    /* PMT START MAUI_00027829 */
    /* HA + I = HI */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_I, 0x0}, {TELUGU_L_HA, TELUGU_DV_I, 0x0}},
    /* HA + II = HII */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_II, 0x0}, {TELUGU_L_HA, TELUGU_DV_II, 0x0}},
    /* HA + E = HE */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_E, 0x0}, {TELUGU_L_HA, TELUGU_DV_E, 0x0}},
    /* HA + EE = HEE */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_EE, 0x0}, {TELUGU_L_HA, TELUGU_DV_EE, 0x0}},
    /* HA + AI = HAI */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_AI, 0x0}, {TELUGU_L_HA, TELUGU_DV_AI, 0x0}},
    /* PMT END MAUI_00027829 */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    /* HA + O = HO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_O, 0x0}, {TELUGU_L_HO, 0x0}},
    /* HA + OO = HOO */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_OO, 0x0}, {TELUGU_L_HOO, 0x0}},
    /* HA + AU = HAU */
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_DV_AU, 0x0}, {TELUGU_L_HAU, 0x0}},
    /* HA + HALANT = H */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_HA, TELUGU_S_HALANT, 0x0}},
    /* 7.24 PMT  END TELUGU & PUNJABI */
    /* PMT START MAUI_00027829 */
    {1, 2, 2, MMI_ALL_LANG, {TELUGU_C_HA, TELUGU_S_HALANT, 0x0}, {TELUGU_L_HA, TELUGU_S_HALANT, 0x0}},
    /* PMT END MAUI_00027829 */


};

const ire_glyph_info_table_struct TELUGU_MAA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_AA, 0x0}, {TELUGU_DV_AA, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_I, 0x0}, {TELUGU_DV_I, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MII_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_II, 0x0}, {TELUGU_DV_II, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_U, 0x0}, {TELUGU_DV_U, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MUU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_UU, 0x0}, {TELUGU_DV_UU, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MVR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_VR, 0x0}, {TELUGU_DV_VR, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MVRR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_VRR, 0x0}, {TELUGU_DV_VRR, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_ME_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_E, 0x0}, {TELUGU_DV_E, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MEE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_EE, 0x0}, {TELUGU_DV_EE, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MAI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_AI, 0x0}, {TELUGU_DV_AI, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_O, 0x0}, {TELUGU_DV_O, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MOO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_OO, 0x0}, {TELUGU_DV_OO, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_MAU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_DV_AU, 0x0}, {TELUGU_DV_AU, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_HALANT_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, 0x0}, {TELUGU_S_HALANT, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_KA, 0x0}, {TELUGU_L_SMALL_KA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_KHA, 0x0}, {TELUGU_L_SMALL_KHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_GA, 0x0}, {TELUGU_L_SMALL_GA, 0x0}}
    ,
    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_GHA, 0x0}, {TELUGU_L_SMALL_GHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_NGA, 0x0}, {TELUGU_L_SMALL_NGA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_CA, 0x0}, {TELUGU_L_SMALL_CA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_CHA, 0x0}, {TELUGU_L_SMALL_CHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_JA, 0x0}, {TELUGU_L_SMALL_JA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_JHA, 0x0}, {TELUGU_L_SMALL_JHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_NYA, 0x0}, {TELUGU_L_SMALL_NYA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_TTA, 0x0}, {TELUGU_L_SMALL_TTA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_TTHA, 0x0}, {TELUGU_L_SMALL_TTHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_DDA, 0x0}, {TELUGU_L_SMALL_DDA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_DDHA, 0x0}, {TELUGU_L_SMALL_DDHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_NNA, 0x0}, {TELUGU_L_SMALL_NNA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_TA, 0x0}, {TELUGU_L_SMALL_TA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_THA, 0x0}, {TELUGU_L_SMALL_THA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_DA, 0x0}, {TELUGU_L_SMALL_DA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_DHA, 0x0}, {TELUGU_L_SMALL_DHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_NA, 0x0}, {TELUGU_L_SMALL_NA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_PA, 0x0}, {TELUGU_L_SMALL_PA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_PHA, 0x0}, {TELUGU_L_SMALL_PHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_BA, 0x0}, {TELUGU_L_SMALL_BA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_BHA, 0x0}, {TELUGU_L_SMALL_BHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_MA, 0x0}, {TELUGU_L_SMALL_MA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_YA, 0x0}, {TELUGU_L_SMALL_YA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_RA, 0x0}, {TELUGU_L_SMALL_RA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_RRA, 0x0}, {TELUGU_L_SMALL_RRA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_LA, 0x0}, {TELUGU_L_SMALL_LA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_LLA, 0x0}, {TELUGU_L_SMALL_LLA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_VA, 0x0}, {TELUGU_L_SMALL_VA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_SHA, 0x0}, {TELUGU_L_SMALL_SHA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_SSA, 0x0}, {TELUGU_L_SMALL_SSA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_SA, 0x0}, {TELUGU_L_SMALL_SA, 0x0}},

    {0, 2, 1, MMI_ALL_LANG, {TELUGU_S_HALANT, TELUGU_C_HA, 0x0}, {TELUGU_L_SMALL_HA, 0x0}},

};

const ire_glyph_info_table_struct TELUGU_ADV_EE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_ADV_EE, 0x0}, {TELUGU_ADV_EE, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_ADV_AI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_ADV_AI, 0x0}, {TELUGU_ADV_AI, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_VRR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_VRR, 0x0}, {TELUGU_IV_VRR, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_VLL_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_IV_VLL, 0x0}, {TELUGU_IV_VLL, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_ZERO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_ZERO, 0x0}, {TELUGU_D_ZERO, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_ONE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_ONE, 0x0}, {TELUGU_D_ONE, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_TWO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_TWO, 0x0}, {TELUGU_D_TWO, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_THREE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_THREE, 0x0}, {TELUGU_D_THREE, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_FOUR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_FOUR, 0x0}, {TELUGU_D_FOUR, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_FIVE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_FIVE, 0x0}, {TELUGU_D_FIVE, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_SIX_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_SIX, 0x0}, {TELUGU_D_SIX, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_SEVEN_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_SEVEN, 0x0}, {TELUGU_D_SEVEN, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_EIGHT_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_EIGHT, 0x0}, {TELUGU_D_EIGHT, 0x0}}

};

const ire_glyph_info_table_struct TELUGU_NINE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {TELUGU_D_NINE, 0x0}, {TELUGU_D_NINE, 0x0}}

};

const ire_main_glyph_table_struct TELUGUTbl[] = 
{
    {TELUGU_CHANDRA_BINDU_Tbl, sizeof(TELUGU_CHANDRA_BINDU_Tbl) / sizeof(TELUGU_CHANDRA_BINDU_Tbl[0]), 1}       /* 0xc01 */
    ,
    {TELUGU_ANUSVARA_Tbl, sizeof(TELUGU_ANUSVARA_Tbl) / sizeof(TELUGU_ANUSVARA_Tbl[0]), 1}      /* 0xc02 */
    ,
    {TELUGU_VISARGA_Tbl, sizeof(TELUGU_VISARGA_Tbl) / sizeof(TELUGU_VISARGA_Tbl[0]), 1} /* 0xc03 */
    ,
    {NULL, 0, 0}    /* 0xc04 */
    ,
    {TELUGU_A_Tbl, sizeof(TELUGU_A_Tbl) / sizeof(TELUGU_A_Tbl[0]), 1}   /* 0xc05 */
    ,
    {TELUGU_AA_Tbl, sizeof(TELUGU_AA_Tbl) / sizeof(TELUGU_AA_Tbl[0]), 1}        /* 0xc06 */
    ,
    {TELUGU_I_Tbl, sizeof(TELUGU_I_Tbl) / sizeof(TELUGU_I_Tbl[0]), 1}   /* 0xc07 */
    ,
    {TELUGU_II_Tbl, sizeof(TELUGU_II_Tbl) / sizeof(TELUGU_II_Tbl[0]), 1}        /* 0xc08 */
    ,
    {TELUGU_U_Tbl, sizeof(TELUGU_U_Tbl) / sizeof(TELUGU_U_Tbl[0]), 1}   /* 0xc09 */
    ,
    {TELUGU_UU_Tbl, sizeof(TELUGU_UU_Tbl) / sizeof(TELUGU_UU_Tbl[0]), 1}        /* 0xc0a */
    ,
    {TELUGU_IV_VR_Tbl, sizeof(TELUGU_IV_VR_Tbl) / sizeof(TELUGU_IV_VR_Tbl[0]), 1}       /* 0xc0b */
    ,
    {TELUGU_IV_VL_Tbl, sizeof(TELUGU_IV_VL_Tbl) / sizeof(TELUGU_IV_VL_Tbl[0]), 1}       /* 0xc0c */
    ,
    {NULL, 0, 0}    /* 0xc0d */
    ,
    {TELUGU_E_Tbl, sizeof(TELUGU_E_Tbl) / sizeof(TELUGU_E_Tbl[0]), 1}   /* 0xc0e */
    ,
    {TELUGU_EE_Tbl, sizeof(TELUGU_EE_Tbl) / sizeof(TELUGU_EE_Tbl[0]), 1}        /* 0xc0f */
    ,
    {TELUGU_AI_Tbl, sizeof(TELUGU_AI_Tbl) / sizeof(TELUGU_AI_Tbl[0]), 1}        /* 0xc10 */
    ,
    {NULL, 0, 0}    /* 0xc11 */
    ,
    {TELUGU_O_Tbl, sizeof(TELUGU_O_Tbl) / sizeof(TELUGU_O_Tbl[0]), 1}   /* 0xc12 */
    ,
    {TELUGU_IV_OO_Tbl, sizeof(TELUGU_IV_OO_Tbl) / sizeof(TELUGU_IV_OO_Tbl[0]), 1}       /* 0xc13 */
    ,
    {TELUGU_IV_AU_Tbl, sizeof(TELUGU_IV_AU_Tbl) / sizeof(TELUGU_IV_AU_Tbl[0]), 1}       /* 0xc14 */
    ,
    {TELUGU_KA_Tbl, sizeof(TELUGU_KA_Tbl) / sizeof(TELUGU_KA_Tbl[0]), 2}        /* 0xc15 */
    ,
    {TELUGU_KHA_Tbl, sizeof(TELUGU_KHA_Tbl) / sizeof(TELUGU_KHA_Tbl[0]), 2}     /* 0xc16 */
    ,
    {TELUGU_GA_Tbl, sizeof(TELUGU_GA_Tbl) / sizeof(TELUGU_GA_Tbl[0]), 2}        /* 0xc17 */
    ,
    {TELUGU_GHA_Tbl, sizeof(TELUGU_GHA_Tbl) / sizeof(TELUGU_GHA_Tbl[0]), 2}     /* 0xc18 */
    ,
    {TELUGU_NGA_Tbl, sizeof(TELUGU_NGA_Tbl) / sizeof(TELUGU_NGA_Tbl[0]), 2}     /* 0xc19 */
    ,
    {TELUGU_CA_Tbl, sizeof(TELUGU_CA_Tbl) / sizeof(TELUGU_CA_Tbl[0]), 2}        /* 0xc1a */
    ,
    {TELUGU_CHA_Tbl, sizeof(TELUGU_CHA_Tbl) / sizeof(TELUGU_CHA_Tbl[0]), 2}     /* 0xc1b */
    ,
    {TELUGU_JA_Tbl, sizeof(TELUGU_JA_Tbl) / sizeof(TELUGU_JA_Tbl[0]), 2}        /* 0xc1c */
    ,
    {TELUGU_JHA_Tbl, sizeof(TELUGU_JHA_Tbl) / sizeof(TELUGU_JHA_Tbl[0]), 2}     /* 0xc1d */
    ,
    {TELUGU_NYA_Tbl, sizeof(TELUGU_NYA_Tbl) / sizeof(TELUGU_NYA_Tbl[0]), 2}     /* 0xc1e */
    ,
    {TELUGU_TTA_Tbl, sizeof(TELUGU_TTA_Tbl) / sizeof(TELUGU_TTA_Tbl[0]), 2}     /* 0xc1f */
    ,
    {TELUGU_TTHA_Tbl, sizeof(TELUGU_TTHA_Tbl) / sizeof(TELUGU_TTHA_Tbl[0]), 2}  /* 0xc20 */
    ,
    {TELUGU_DDA_Tbl, sizeof(TELUGU_DDA_Tbl) / sizeof(TELUGU_DDA_Tbl[0]), 2}     /* 0xc21 */
    ,
    {TELUGU_DDHA_Tbl, sizeof(TELUGU_DDHA_Tbl) / sizeof(TELUGU_DDHA_Tbl[0]), 2}  /* 0xc22 */
    ,
    {TELUGU_NNA_Tbl, sizeof(TELUGU_NNA_Tbl) / sizeof(TELUGU_NNA_Tbl[0]), 2}     /* 0xc23 */
    ,
    {TELUGU_TA_Tbl, sizeof(TELUGU_TA_Tbl) / sizeof(TELUGU_TA_Tbl[0]), 2}        /* 0xc24 */
    ,
    {TELUGU_THA_Tbl, sizeof(TELUGU_THA_Tbl) / sizeof(TELUGU_THA_Tbl[0]), 2}     /* 0xc25 */
    ,
    {TELUGU_DA_Tbl, sizeof(TELUGU_DA_Tbl) / sizeof(TELUGU_DA_Tbl[0]), 2}        /* 0xc26 */
    ,
    {TELUGU_DHA_Tbl, sizeof(TELUGU_DHA_Tbl) / sizeof(TELUGU_DHA_Tbl[0]), 2}     /* 0xc27 */
    ,
    {TELUGU_NA_Tbl, sizeof(TELUGU_NA_Tbl) / sizeof(TELUGU_NA_Tbl[0]), 2}        /* 0xc28 */
    ,
    {NULL, 0, 0}    /* 0xc29 */
    ,
    {TELUGU_PA_Tbl, sizeof(TELUGU_PA_Tbl) / sizeof(TELUGU_PA_Tbl[0]), 2}        /* 0xc2a */
    ,
    {TELUGU_PHA_Tbl, sizeof(TELUGU_PHA_Tbl) / sizeof(TELUGU_PHA_Tbl[0]), 2}     /* 0xc2b */
    ,
    {TELUGU_BA_Tbl, sizeof(TELUGU_BA_Tbl) / sizeof(TELUGU_BA_Tbl[0]), 2}        /* 0xc2c */
    ,
    {TELUGU_BHA_Tbl, sizeof(TELUGU_BHA_Tbl) / sizeof(TELUGU_BHA_Tbl[0]), 2}     /* 0xc2d */
    ,
    {TELUGU_MA_Tbl, sizeof(TELUGU_MA_Tbl) / sizeof(TELUGU_MA_Tbl[0]), 2}        /* 0xc2e */
    ,
    {TELUGU_YA_Tbl, sizeof(TELUGU_YA_Tbl) / sizeof(TELUGU_YA_Tbl[0]), 2}        /* 0xc2f */
    ,
    {TELUGU_RA_Tbl, sizeof(TELUGU_RA_Tbl) / sizeof(TELUGU_RA_Tbl[0]), 2}        /* 0xc30 */
    ,
    {TELUGU_RRA_Tbl, sizeof(TELUGU_RRA_Tbl) / sizeof(TELUGU_RRA_Tbl[0]), 1}     /* 0xc31 */
    ,
    {TELUGU_LA_Tbl, sizeof(TELUGU_LA_Tbl) / sizeof(TELUGU_LA_Tbl[0]), 1}        /* 0xc32 */
    ,
    {TELUGU_LLA_Tbl, sizeof(TELUGU_LLA_Tbl) / sizeof(TELUGU_LLA_Tbl[0]), 1}     /* 0xc33 */
    ,
    {NULL, 0, 0}    /* 0xc34 */
    ,
    {TELUGU_VA_Tbl, sizeof(TELUGU_VA_Tbl) / sizeof(TELUGU_VA_Tbl[0]), 1}        /* 0xc35 */
    ,
    {TELUGU_SHA_Tbl, sizeof(TELUGU_SHA_Tbl) / sizeof(TELUGU_SHA_Tbl[0]), 1}     /* 0xc36 */
    ,
    {TELUGU_SSA_Tbl, sizeof(TELUGU_SSA_Tbl) / sizeof(TELUGU_SSA_Tbl[0]), 1}     /* 0xc37 */
    ,
    {TELUGU_SA_Tbl, sizeof(TELUGU_SA_Tbl) / sizeof(TELUGU_SA_Tbl[0]), 1}        /* 0xc38 */
    ,
    {TELUGU_HA_Tbl, sizeof(TELUGU_HA_Tbl) / sizeof(TELUGU_HA_Tbl[0]), 1}        /* 0xc39 */
    ,
    {NULL, 0, 0}    /* 0xc3a */
    ,
    {NULL, 0, 0}    /* 0xc3b */
    ,
    {NULL, 0, 0}    /* 0xc3c */
    ,
    {NULL, 0, 0}    /* 0xc3d */
    ,
    {TELUGU_MAA_Tbl, sizeof(TELUGU_MAA_Tbl) / sizeof(TELUGU_MAA_Tbl[0]), 1}     /* 0xc3e */
    ,
    {TELUGU_MI_Tbl, sizeof(TELUGU_MI_Tbl) / sizeof(TELUGU_MI_Tbl[0]), 1}        /* 0xc3f */
    ,
    {TELUGU_MII_Tbl, sizeof(TELUGU_MII_Tbl) / sizeof(TELUGU_MII_Tbl[0]), 1}     /* 0xc40 */
    ,
    {TELUGU_MU_Tbl, sizeof(TELUGU_MU_Tbl) / sizeof(TELUGU_MU_Tbl[0]), 1}        /* 0xc41 */
    ,
    {TELUGU_MUU_Tbl, sizeof(TELUGU_MUU_Tbl) / sizeof(TELUGU_MUU_Tbl[0]), 1}     /* 0xc42 */
    ,
    {TELUGU_MVR_Tbl, sizeof(TELUGU_MVR_Tbl) / sizeof(TELUGU_MVR_Tbl[0]), 1}     /* 0xc43 */
    ,
    {TELUGU_MVRR_Tbl, sizeof(TELUGU_MVRR_Tbl) / sizeof(TELUGU_MVRR_Tbl[0]), 1}  /* 0xc44 */
    ,
    {NULL, 0, 0}    /* 0xc45 */
    ,
    {TELUGU_ME_Tbl, sizeof(TELUGU_ME_Tbl) / sizeof(TELUGU_ME_Tbl[0]), 1}        /* 0xc46 */
    ,
    {TELUGU_MEE_Tbl, sizeof(TELUGU_MEE_Tbl) / sizeof(TELUGU_MEE_Tbl[0]), 1}     /* 0xc47 */
    ,
    {TELUGU_MAI_Tbl, sizeof(TELUGU_MAI_Tbl) / sizeof(TELUGU_MAI_Tbl[0]), 1}     /* 0xc48 */
    ,
    {NULL, 0, 0}    /* 0xc49 */
    ,
    {TELUGU_MO_Tbl, sizeof(TELUGU_MO_Tbl) / sizeof(TELUGU_MO_Tbl[0]), 1}        /* 0xc4a */
    ,
    {TELUGU_MOO_Tbl, sizeof(TELUGU_MOO_Tbl) / sizeof(TELUGU_MOO_Tbl[0]), 1}     /* 0xc4b */
    ,
    {TELUGU_MAU_Tbl, sizeof(TELUGU_MAU_Tbl) / sizeof(TELUGU_MAU_Tbl[0]), 1}     /* 0xc4c */
    ,
    {TELUGU_HALANT_Tbl, sizeof(TELUGU_HALANT_Tbl) / sizeof(TELUGU_HALANT_Tbl[0]), 1}    /* 0xc4d */
    ,
    {NULL, 0, 0}    /* 0xc4e */
    ,
    {NULL, 0, 0}    /* 0xc4f */
    ,
    {NULL, 0, 0}    /* 0xc50 */
    ,
    {NULL, 0, 0}    /* 0xc51 */
    ,
    {NULL, 0, 0}    /* 0xc52 */
    ,
    {NULL, 0, 0}    /* 0xc53 */
    ,
    {NULL, 0, 0}    /* 0xc54 */
    ,
    {TELUGU_ADV_EE_Tbl, sizeof(TELUGU_ADV_EE_Tbl) / sizeof(TELUGU_ADV_EE_Tbl[0]), 1}    /* 0xc55 */
    ,
    {TELUGU_ADV_AI_Tbl, sizeof(TELUGU_ADV_AI_Tbl) / sizeof(TELUGU_ADV_AI_Tbl[0]), 1}    /* 0xc56 */
    ,
    {NULL, 0, 0}    /* 0xc57 */
    ,
    {NULL, 0, 0}    /* 0xc58 */
    ,
    {NULL, 0, 0}    /* 0xc59 */
    ,
    {NULL, 0, 0}    /* 0xc5a */
    ,
    {NULL, 0, 0}    /* 0xc5b */
    ,
    {NULL, 0, 0}    /* 0xc5c */
    ,
    {NULL, 0, 0}    /* 0xc5d */
    ,
    {NULL, 0, 0}    /* 0xc5e */
    ,
    {NULL, 0, 0}    /* 0xc5f */
    ,
    {TELUGU_VRR_Tbl, sizeof(TELUGU_VRR_Tbl) / sizeof(TELUGU_VRR_Tbl[0]), 1}     /* 0xc60 */
    ,
    {TELUGU_VLL_Tbl, sizeof(TELUGU_VLL_Tbl) / sizeof(TELUGU_VLL_Tbl[0]), 1}     /* 0xc61 */
    ,
    {NULL, 0, 0}    /* 0xc62 */
    ,
    {NULL, 0, 0}    /* 0xc63 */
    ,
    {NULL, 0, 0}    /* 0xc64 */
    ,
    {NULL, 0, 0}    /* 0xc65 */
    ,
    {TELUGU_ZERO_Tbl, sizeof(TELUGU_ZERO_Tbl) / sizeof(TELUGU_ZERO_Tbl[0]), 1}  /* 0xc66 */
    ,
    {TELUGU_ONE_Tbl, sizeof(TELUGU_ONE_Tbl) / sizeof(TELUGU_ONE_Tbl[0]), 1}     /* 0xc67 */
    ,
    {TELUGU_TWO_Tbl, sizeof(TELUGU_TWO_Tbl) / sizeof(TELUGU_TWO_Tbl[0]), 1}     /* 0xc68 */
    ,
    {TELUGU_THREE_Tbl, sizeof(TELUGU_THREE_Tbl) / sizeof(TELUGU_THREE_Tbl[0]), 1}       /* 0xc69 */
    ,
    {TELUGU_FOUR_Tbl, sizeof(TELUGU_FOUR_Tbl) / sizeof(TELUGU_FOUR_Tbl[0]), 1}  /* 0xc6a */
    ,
    {TELUGU_FIVE_Tbl, sizeof(TELUGU_FIVE_Tbl) / sizeof(TELUGU_FIVE_Tbl[0]), 1}  /* 0xc6b */
    ,
    {TELUGU_SIX_Tbl, sizeof(TELUGU_SIX_Tbl) / sizeof(TELUGU_SIX_Tbl[0]), 1}     /* 0xc6c */
    ,
    {TELUGU_SEVEN_Tbl, sizeof(TELUGU_SEVEN_Tbl) / sizeof(TELUGU_SEVEN_Tbl[0]), 1}       /* 0xc6d */
    ,
    {TELUGU_EIGHT_Tbl, sizeof(TELUGU_EIGHT_Tbl) / sizeof(TELUGU_EIGHT_Tbl[0]), 1}       /* 0xc6e */
    ,
    {TELUGU_NINE_Tbl, sizeof(TELUGU_NINE_Tbl) / sizeof(TELUGU_NINE_Tbl[0]), 1}  /* 0xc6f */
    ,

};

#if defined (__MMI_MULTITAP_TELUGU__)
/* PMT START ZI */
#if defined (__MMI_ZI_TELUGU__)
const UI_character_type default_telugu_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},	/* key 0 */
    {0x002e, 0x002c, 0x003f, 0x0021, 0x002d, '1', '\0'},	/* key 1 */
    {TELUGU_C_KA, TELUGU_C_KHA, TELUGU_IV_A, TELUGU_IV_AA, '2', '\0'},	/* key 2 */
    {TELUGU_C_GA, TELUGU_C_GHA, TELUGU_C_NGA, TELUGU_IV_I, TELUGU_IV_II, '3', '\0'},	/* key 3 */
    {TELUGU_C_CA, TELUGU_C_CHA, TELUGU_C_JA, TELUGU_C_JHA, TELUGU_C_NYA, TELUGU_IV_U, TELUGU_IV_UU,'4', '\0'},	/* key 4 */
    {TELUGU_C_TTA, TELUGU_C_TTHA, TELUGU_C_DDA, TELUGU_C_DDHA, TELUGU_C_NNA, TELUGU_IV_VR, '5', '\0'},	/* key 5 */
    {TELUGU_C_TA, TELUGU_C_THA, TELUGU_C_DA, TELUGU_C_DHA, TELUGU_IV_E, TELUGU_IV_EE, '6', '\0'},	/* key 6 */
    {TELUGU_C_NA, TELUGU_C_PA, TELUGU_C_PHA, TELUGU_C_BA, TELUGU_C_BHA,  TELUGU_IV_AI, '7', '\0'},	/* key 7 */
    {TELUGU_C_MA, TELUGU_C_YA, TELUGU_C_RA, TELUGU_IV_O, TELUGU_IV_OO, '8', '\0'},	/* key 8 */
    {TELUGU_C_LA, TELUGU_C_VA, TELUGU_C_SHA, TELUGU_C_SSA, TELUGU_C_SA, TELUGU_C_HA, TELUGU_C_LLA, TELUGU_IV_AU, '9', '\0'},	/* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_telugumatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},	/* key 0 */
    {0x002e, 0x002c, 0x003f, 0x0021, 0x002d, '1', TELUGU_S_HALANT, TELUGU_S_ANUSVARA, TELUGU_S_VISARGA, TELUGU_S_CHANDRA_BINDU, '\0'},	/* key 1 */
    {TELUGU_C_KA, TELUGU_C_KHA, TELUGU_IV_A, TELUGU_IV_AA, TELUGU_DV_AA, '2', '\0'},	/* key 2 */
    {TELUGU_C_GA, TELUGU_C_GHA, TELUGU_C_NGA, TELUGU_IV_I, TELUGU_IV_II, TELUGU_DV_I, TELUGU_DV_II, '3', '\0'},	/* key 3 */
    {TELUGU_C_CA, TELUGU_C_CHA, TELUGU_C_JA, TELUGU_C_JHA, TELUGU_C_NYA, TELUGU_IV_U, TELUGU_IV_UU, TELUGU_DV_U, TELUGU_DV_UU, '4', '\0'},	/* key 4 */
    {TELUGU_C_TTA, TELUGU_C_TTHA, TELUGU_C_DDA, TELUGU_C_DDHA, TELUGU_C_NNA, TELUGU_IV_VR, TELUGU_DV_VR, '5', '\0'},	/* key 5 */
    {TELUGU_C_TA, TELUGU_C_THA, TELUGU_C_DA, TELUGU_C_DHA, TELUGU_IV_E, TELUGU_IV_EE, TELUGU_DV_E, TELUGU_DV_EE, '6', '\0'},	/* key 6 */
    {TELUGU_C_NA, TELUGU_C_PA, TELUGU_C_PHA, TELUGU_C_BA, TELUGU_C_BHA,  TELUGU_IV_AI, TELUGU_DV_AI, '7', '\0'},	/* key 7 */
    {TELUGU_C_MA, TELUGU_C_YA, TELUGU_C_RA, TELUGU_IV_O, TELUGU_IV_OO, TELUGU_DV_O, TELUGU_DV_OO, '8', '\0'},	/* key 8 */
    {TELUGU_C_LA, TELUGU_C_VA, TELUGU_C_SHA, TELUGU_C_SSA, TELUGU_C_SA, TELUGU_C_HA, TELUGU_C_LLA, TELUGU_IV_AU, TELUGU_DV_AU, '9', '\0'},	/* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_telugumatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},	/* key 0 */
    {0x002e, 0x002c, 0x003f, 0x0021, 0x002d, '1', TELUGU_S_ANUSVARA, TELUGU_S_VISARGA, TELUGU_S_CHANDRA_BINDU, '\0'},	/* key 1 */
    {TELUGU_C_KA, TELUGU_C_KHA, TELUGU_IV_A, TELUGU_IV_AA, '2', '\0'},	/* key 2 */
    {TELUGU_C_GA, TELUGU_C_GHA, TELUGU_C_NGA, TELUGU_IV_I, TELUGU_IV_II, '3', '\0'},	/* key 3 */
    {TELUGU_C_CA, TELUGU_C_CHA, TELUGU_C_JA, TELUGU_C_JHA, TELUGU_C_NYA, TELUGU_IV_U, TELUGU_IV_UU, '4', '\0'},	/* key 4 */
    {TELUGU_C_TTA, TELUGU_C_TTHA, TELUGU_C_DDA, TELUGU_C_DDHA, TELUGU_C_NNA, TELUGU_IV_VR, '5', '\0'},	/* key 5 */
    {TELUGU_C_TA, TELUGU_C_THA, TELUGU_C_DA, TELUGU_C_DHA, TELUGU_IV_E, TELUGU_IV_EE, '6', '\0'},	/* key 6 */
    {TELUGU_C_NA, TELUGU_C_PA, TELUGU_C_PHA, TELUGU_C_BA, TELUGU_C_BHA,  TELUGU_IV_AI, '7', '\0'},	/* key 7 */
    {TELUGU_C_MA, TELUGU_C_YA, TELUGU_C_RA, TELUGU_IV_O, TELUGU_IV_OO, '8', '\0'},	/* key 8 */
    {TELUGU_C_LA, TELUGU_C_VA, TELUGU_C_SHA, TELUGU_C_SSA, TELUGU_C_SA, TELUGU_C_HA, TELUGU_C_LLA, TELUGU_IV_AU, '9', '\0'},	/* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#else
/* PMT END ZI */

const UI_character_type default_telugu_multitap_strings[MAX_MULTITAPS][32] = 
{

    /* PMT START MAUI_00027438 */
    {' ', TELUGU_D_ZERO, '0', '\0'},    /* key 0 */
    {TELUGU_C_KA, TELUGU_C_KHA, TELUGU_C_GA, TELUGU_C_GHA, TELUGU_C_NGA, TELUGU_D_ONE, '1', '\0'},      /* key 1 */
    {TELUGU_C_CA, TELUGU_C_CHA, TELUGU_C_JA, TELUGU_C_JHA, TELUGU_C_NYA, TELUGU_D_TWO, '2', '\0'},      /* key 2 */
    {TELUGU_C_TTA, TELUGU_C_TTHA, TELUGU_C_DDA, TELUGU_C_DDHA, TELUGU_C_NNA, TELUGU_D_THREE, '3', '\0'},        /* key 3 */
    {TELUGU_C_TA, TELUGU_C_THA, TELUGU_C_DA, TELUGU_C_DHA, TELUGU_C_NA, TELUGU_D_FOUR, '4', '\0'},      /* key 4 */
    {TELUGU_C_PA, TELUGU_C_PHA, TELUGU_C_BA, TELUGU_C_BHA, TELUGU_C_MA, TELUGU_D_FIVE, '5', '\0'},      /* key 5 */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {TELUGU_C_YA, TELUGU_C_RA, TELUGU_C_RRA, TELUGU_C_LA, TELUGU_C_LLA, TELUGU_C_VA, TELUGU_C_SHA, TELUGU_C_SSA, TELUGU_C_SA, TELUGU_C_HA, TELUGU_D_SIX, '6', '\0'},    /* key 6 */
    /* 7.24 PMT  END TELUGU & PUNJABI */
    {TELUGU_IV_A, TELUGU_IV_AA, TELUGU_IV_I, TELUGU_IV_II, TELUGU_IV_U, TELUGU_IV_UU, TELUGU_IV_VR, TELUGU_IV_VRR, TELUGU_IV_E, TELUGU_IV_EE, TELUGU_IV_AI, TELUGU_IV_O, TELUGU_IV_OO, TELUGU_IV_AU, TELUGU_D_SEVEN, '7', '\0'},        /* key 7 */
    {TELUGU_D_EIGHT, '8', '\0'},        /* key 8 */
    {TELUGU_D_NINE, '9', '\0'},         /* key 9 */
    /* PMT END MAUI_00027438 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_telugumatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* PMT START MAUI_00027438 */
    {' ', TELUGU_D_ZERO, '0', '\0'},    /* key 0 */
    {TELUGU_C_KA, TELUGU_C_KHA, TELUGU_C_GA, TELUGU_C_GHA, TELUGU_C_NGA, TELUGU_D_ONE, '1', '\0'},      /* key 1 */
    {TELUGU_C_CA, TELUGU_C_CHA, TELUGU_C_JA, TELUGU_C_JHA, TELUGU_C_NYA, TELUGU_D_TWO, '2', '\0'},      /* key 2 */
    {TELUGU_C_TTA, TELUGU_C_TTHA, TELUGU_C_DDA, TELUGU_C_DDHA, TELUGU_C_NNA, TELUGU_D_THREE, '3', '\0'},        /* key 3 */
    {TELUGU_C_TA, TELUGU_C_THA, TELUGU_C_DA, TELUGU_C_DHA, TELUGU_C_NA, TELUGU_D_FOUR, '4', '\0'},      /* key 4 */
    {TELUGU_C_PA, TELUGU_C_PHA, TELUGU_C_BA, TELUGU_C_BHA, TELUGU_C_MA, TELUGU_D_FIVE, '5', '\0'},      /* key 5 */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {TELUGU_C_YA, TELUGU_C_RA, TELUGU_C_RRA, TELUGU_C_LA, TELUGU_C_LLA, TELUGU_C_VA, TELUGU_C_SHA, TELUGU_C_SSA, TELUGU_C_SA, TELUGU_C_HA, TELUGU_D_SIX, '6', '\0'},    /* key 6 */
    /* 7.24 PMT  END TELUGU & PUNJABI */
    {TELUGU_IV_A, TELUGU_IV_AA, TELUGU_IV_I, TELUGU_IV_II, TELUGU_IV_U, TELUGU_IV_UU, TELUGU_IV_VR, TELUGU_IV_VRR, TELUGU_IV_E, TELUGU_IV_EE, TELUGU_IV_AI, TELUGU_IV_O, TELUGU_IV_OO, TELUGU_IV_AU, TELUGU_D_SEVEN, '7', '\0'},        /* key 7 */
    {TELUGU_DV_AA, TELUGU_DV_I, TELUGU_DV_II, TELUGU_DV_U, TELUGU_DV_UU, TELUGU_DV_VR, TELUGU_DV_VRR,

     TELUGU_DV_E, TELUGU_DV_EE, TELUGU_DV_AI, TELUGU_DV_O, TELUGU_DV_OO, TELUGU_DV_AU, TELUGU_D_EIGHT, '8', '\0'},      /* key 8 */
    {TELUGU_S_CHANDRA_BINDU, TELUGU_S_ANUSVARA, TELUGU_S_VISARGA, TELUGU_S_HALANT, TELUGU_D_NINE, '9', '\0'},   /* key 9 */
    /* PMT END MAUI_00027438 */
 #if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
 #else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
 #endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_telugumatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* PMT START MAUI_00027438 */
    {' ', TELUGU_D_ZERO, '0', '\0'},    /* key 0 */
    {TELUGU_C_KA, TELUGU_C_KHA, TELUGU_C_GA, TELUGU_C_GHA, TELUGU_C_NGA, TELUGU_D_ONE, '1', '\0'},      /* key 1 */
    {TELUGU_C_CA, TELUGU_C_CHA, TELUGU_C_JA, TELUGU_C_JHA, TELUGU_C_NYA, TELUGU_D_TWO, '2', '\0'},      /* key 2 */
    {TELUGU_C_TTA, TELUGU_C_TTHA, TELUGU_C_DDA, TELUGU_C_DDHA, TELUGU_C_NNA, TELUGU_D_THREE, '3', '\0'},        /* key 3 */
    {TELUGU_C_TA, TELUGU_C_THA, TELUGU_C_DA, TELUGU_C_DHA, TELUGU_C_NA, TELUGU_D_FOUR, '4', '\0'},      /* key 4 */
    {TELUGU_C_PA, TELUGU_C_PHA, TELUGU_C_BA, TELUGU_C_BHA, TELUGU_C_MA, TELUGU_D_FIVE, '5', '\0'},      /* key 5 */
    /* 7.24 PMT  START TELUGU & PUNJABI */
    {TELUGU_C_YA, TELUGU_C_RA, TELUGU_C_RRA, TELUGU_C_LA, TELUGU_C_LLA, TELUGU_C_VA, TELUGU_C_SHA, TELUGU_C_SSA, TELUGU_C_SA, TELUGU_C_HA, TELUGU_D_SIX, '6', '\0'},    /* key 6 */
    /* 7.24 PMT  END TELUGU & PUNJABI */
    {TELUGU_IV_A, TELUGU_IV_AA, TELUGU_IV_I, TELUGU_IV_II, TELUGU_IV_U, TELUGU_IV_UU, TELUGU_IV_VR, TELUGU_IV_VRR, TELUGU_IV_E, TELUGU_IV_EE, TELUGU_IV_AI, TELUGU_IV_O, TELUGU_IV_OO, TELUGU_IV_AU, TELUGU_D_SEVEN, '7', '\0'},        /* key 7 */
    {TELUGU_D_EIGHT, '8', '\0'},        /* key 8 */
    {TELUGU_S_CHANDRA_BINDU, TELUGU_S_ANUSVARA, TELUGU_S_VISARGA, TELUGU_D_NINE, '9', '\0'},    /* key 9 */
    /* PMT END MAUI_00027438 */
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
 *  get_telugu_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_telugu_multitap_string(S32 i)
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
        if (previous_char >= TELUGU_C_KA && previous_char <= TELUGU_C_HA)
        {
            return ((UI_character_type*) default_telugumatra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (TELUGU_IV_A):
                case (TELUGU_IV_AA):
                case (TELUGU_IV_I):
                case (TELUGU_IV_II):
                case (TELUGU_IV_U):
                case (TELUGU_IV_UU):
                case (TELUGU_IV_VR):
                case (TELUGU_IV_VL):
                case (TELUGU_IV_E):
                case (TELUGU_IV_EE):
                case (TELUGU_IV_AI):
                case (TELUGU_IV_O):
                case (TELUGU_IV_OO):
                case (TELUGU_IV_AU):
                case (TELUGU_DV_AA):
                case (TELUGU_DV_I):
                case (TELUGU_DV_II):
                case (TELUGU_DV_U):
                case (TELUGU_DV_UU):
                case (TELUGU_DV_VR):
                case (TELUGU_DV_VRR):
                case (TELUGU_DV_E):
                case (TELUGU_DV_EE):
                case (TELUGU_DV_AI):
                case (TELUGU_DV_O):
                case (TELUGU_DV_OO):
                case (TELUGU_DV_AU):
                {
                    return ((UI_character_type*) default_telugumatra1_multitap_strings[i]);
                    break;
                }
                default:
                {
                    return ((UI_character_type*) default_telugu_multitap_strings[i]);
                }
            }
        }

    }
    else
    {
        return ((UI_character_type*) default_telugu_multitap_strings[i]);
    }

}


/*****************************************************************************
 * FUNCTION
 *  get_telugu_single_line_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_telugu_single_line_multitap_string(S32 i)
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
        if (previous_char >= TELUGU_C_KA && previous_char <= TELUGU_C_HA)
        {
            return ((UI_character_type*) default_telugumatra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (TELUGU_IV_A):
                case (TELUGU_IV_AA):
                case (TELUGU_IV_I):
                case (TELUGU_IV_II):
                case (TELUGU_IV_U):
                case (TELUGU_IV_UU):
                case (TELUGU_IV_VR):
                case (TELUGU_IV_VL):
                case (TELUGU_IV_E):
                case (TELUGU_IV_EE):
                case (TELUGU_IV_AI):
                case (TELUGU_IV_O):
                case (TELUGU_IV_OO):
                case (TELUGU_IV_AU):
                case (TELUGU_DV_AA):
                case (TELUGU_DV_I):
                case (TELUGU_DV_II):
                case (TELUGU_DV_U):
                case (TELUGU_DV_UU):
                case (TELUGU_DV_VR):
                case (TELUGU_DV_VRR):
                case (TELUGU_DV_E):
                case (TELUGU_DV_EE):
                case (TELUGU_DV_AI):
                case (TELUGU_DV_O):
                case (TELUGU_DV_OO):
                case (TELUGU_DV_AU):
                {
                    return ((UI_character_type*) default_telugumatra1_multitap_strings[i]);
                    break;
                }
                default:
                {
                    return ((UI_character_type*) default_telugu_multitap_strings[i]);
                }

            }
        }

    }
    else
    {
        return ((UI_character_type*) default_telugu_multitap_strings[i]);
    }

}

#endif /* defined (__MMI_MULTITAP_TELUGU__) */ /* #if defined (__MMI_MULTITAP_TELUGU__)  */
#endif /* defined (__MMI_LANG_TELUGU__) */ /* #if defined (__MMI_LANG_TELUGU__) */

