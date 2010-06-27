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
 *    hf_rules.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   c file of hindi font rule 
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifdef __MMI_HINDI_ALG__

#include "gui.h"
#include "UCS2Prot.h"
#include "hf_rules.h"
PU8 cluster_start_p;
PU8 cluster_end_p = 0;
S32 use_multitap = 0;
S32 parse_hindi = 1;
S32 reset_hindi_pms = 1;
S32 prev_char_text_x = 0;
S32 prev_char_dwidth = 0;
S32 prev_char_width = 0;
U16 prev_character = 0;
S32 new_line = 1;
U16 temp_array[C_MAX] = {0};
S32 hf_padding = HF_DEFAULT_PADDING;
S32 prev_char_btext_x = 0;
S32 prev_char_bdwidth = 0;
S32 new_bline = 1;

/* PMT RAKESH START 20061006 */
#include "SSCStringHandle.h"
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
const HindiRulesLangSSC HRLangSSC[] = 
{
    {SSC_HINDI, MMI_HINDI_LANG},
    {SSC_MARATHI, MMI_MARATHI_LANG},
};
HINDI_RULES_LANGUAGE_ENUM hf_rules_current_set_language;
HINDI_RULES_LANGUAGE_ENUM hf_rules_prefered_set_language;

/* PMT RAKESH END 20061006 */

#define HINDI_CONVERT_U8_U16(character) ((character)[0]|((character)[1]<<8))

#define HINDI_FILL_CLUSTER()                                \
{                                                           \
   start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char); \
   nFill++;                                                 \
   start_char+=2;                                           \
}

#define HF_END_CLUSTER(start_cluster,start_char,nFill)\
{                                                     \
   if( start_char == cluster_end_p)                   \
   {                                                  \
      start_cluster[nFill] = (U16)NULL;               \
      cluster_start_p += nFill;                       \
      return nFill;                                   \
   }                                                  \
}

/* START TARUN 20041029 */
PU8 cursor_pointer_end_current_cluster;

/* END TARUN 20041029 */

                       /*    CONSONANT'S TABLES   */

const GLYPH_INFO_TABLE KA_Tbl[] = 
{

    /* ka + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_KA, 0x0}, {C_KA, 0x0}},
    /* Ka + nukta -> QA */
    {0, 2, 1, MMI_ALL_LANG, {C_KA, S_NUKTA, 0x0}, {AC_QA, 0x0}},
    /* Ka + Halant/Virama -> Half form of Ka */
    {1, 2, 1, MMI_ALL_LANG, {C_KA, S_HALANT, 0x0}, {H_KA, 0x0}},
    /* Ka + Nukta +Halant -> half form of Ka with Nukta */
    {1, 3, 1, MMI_ALL_LANG, {C_KA, S_NUKTA, S_HALANT, 0x0}, {L_KA_N, 0x0}},
    /* Ka + Halant + KA -> ligature form of KKA */
    {1, 3, 1, MMI_ALL_LANG, {C_KA, S_HALANT, C_KA, 0x0}, {L_KKA, 0x0}},
    /* Ka + Halant + Ta -> Kta */
    {1, 3, 1, MMI_ALL_LANG, {C_KA, S_HALANT, C_TA, 0x0}, {L_KTA, 0x0}},
    /* Ka + Halant + Ra -> Kra */
    {1, 3, 1, MMI_ALL_LANG, {C_KA, S_HALANT, C_RA, 0x0}, {L_KRA, 0x0}},
    /* Ka + Halant + Sha -> Ksha */
    {1, 3, 1, MMI_ALL_LANG, {C_KA, S_HALANT, C_SSA, 0x0}, {L_KSHA, 0x0}},
    /* Ka + Halant + Ra +Halant -> Kra +Halant */
    /* {1,4,2,MMI_ALL_LANG,     {C_KA,S_HALANT,C_RA,S_HALANT,0x0},  {L_KRA,S_HALANT,0x0}}, */
    /* Ka + Halant + Ra +Halant -> Kra +Halant */
    {1, 4, 1, MMI_ALL_LANG, {C_KA, S_NUKTA, S_HALANT, C_RA, 0x0}, {L_KRA_N, 0x0}},
    /* Ka + Halant + Sha + Halant -> Half form of Ksha */
    //{1,4,1,MMI_ALL_LANG,     {C_KA,S_HALANT,C_SSA,S_HALANT,0x0},  {H_KHSA,0x0}}
    //START FARHAD PMT 20050211     
    /* Ka + Halant + Ra + Halant -> Half Form of Ka + Ra + Halant */
    {1, 4, 3, MMI_ALL_LANG, {C_KA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_KA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE KHA_Tbl[] = 
{
    /* kha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_KHA, 0x0}, {C_KHA, 0x0}},
    /* kha + nukta -> khha */
    {0, 2, 1, MMI_ALL_LANG, {C_KHA, S_NUKTA, 0x0}, {AC_KHHA, 0x0}},
    /* Kha + halant  -> half form of kha */
    {1, 2, 1, MMI_ALL_LANG, {C_KHA, S_HALANT, 0x0}, {H_KHA, 0x0}},
    /* kha + nukta +halant -> half form of kha with nukta */
    {1, 3, 1, MMI_ALL_LANG, {C_KHA, S_NUKTA, S_HALANT, 0x0}, {L_KHA_N, 0x0}},
    /* kha + halant + ra -> Kha + subscript form of RA OR KHRA as a whole */
    {1, 3, 1, MMI_ALL_LANG, {C_KHA, S_HALANT, C_RA, 0x0}, {L_KHRA, 0x0}},       /* Question */
    /* kha + halant + ra + halant -> kha + RA subscript +halant */
    //{1,4,2,MMI_ALL_LANG,     {C_KHA,S_HALANT,C_RA,S_HALANT,0x0},  {L_KHRA,S_HALANT,0x0}},/*Question*/
    // START FARHAD PMT 20050211
    {1, 4, 1, MMI_ALL_LANG, {C_KHA, S_NUKTA, S_HALANT, C_RA, 0x0}, {L_KHRA_N, 0x0}},    /* Question */
    /* kha + halant + ra + halant -> half kha + RA subscript +halant */
    {1, 4, 3, MMI_ALL_LANG, {C_KHA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_KHA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE GA_Tbl[] = 
{
    /* ga + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_GA, 0x0}, {C_GA, 0x0}},
    /* ga + nukta -> nukta form of ga */
    {0, 2, 1, MMI_ALL_LANG, {C_GA, S_NUKTA, 0x0}, {AC_GHHA, 0x0}},
    /* ga + halant -> half form of ga */
    {1, 2, 1, MMI_ALL_LANG, {C_GA, S_HALANT, 0x0}, {H_GA, 0x0}},
    /* ga + nukta + halant -> half ga with nukta */
    {1, 3, 1, MMI_ALL_LANG, {C_GA, S_NUKTA, S_HALANT, 0x0}, {L_GA_N, 0x0}},
    /* ga + halant + ra -> ga + subscript form of RA */
    {1, 3, 1, MMI_ALL_LANG, {C_GA, S_HALANT, C_RA, 0x0}, {L_GRA, 0x0}}, /* Q */
    /* ga + halant + ra + halant -> ga + subscript form of RA + halant */
    /* START FARHAD PMT 20050211 */
    {1, 4, 1, MMI_ALL_LANG, {C_GA, S_NUKTA, S_HALANT, C_RA, 0x0}, {L_GRA_N, 0x0}},      /* Q */
    /* ga + halant + ra + halant -> halfga + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_GA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_GA, C_RA, S_HALANT, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_GA, S_HALANT, C_NA, 0x0}, {L_GA_NA, 0x0}}
#endif
};

const GLYPH_INFO_TABLE GHA_Tbl[] = 
{
    /* gha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_GHA, 0x0}, {C_GHA, 0x0}},
    /* gha + halant -> half form of gha */
    {1, 2, 1, MMI_ALL_LANG, {C_GHA, S_HALANT, 0x0}, {H_GHA, 0x0}},
    /* gha + halant + RA  -> gha + subscript form of RA */
    {1, 3, 1, MMI_ALL_LANG, {C_GHA, S_HALANT, C_RA, 0x0}, {L_GHRA, 0x0}},       /* Q */
    /* gha + halant + RA + halant -> gha + RA subscript + halant */
    /* START FARHAD PMT 20050211 */
    {1, 4, 3, MMI_ALL_LANG, {C_GHA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_GHA, C_RA, S_HALANT, 0x0}}       /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NGA_Tbl[] = 
{
    /* nga + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_NGA, 0x0}, {C_NGA, 0x0}},
    /* nga + halant + RA -> nga + subscript RA(special representation) */
    {1, 3, 2, MMI_ALL_LANG, {C_NGA, S_HALANT, C_RA, 0x0}, {C_NGA, SUB_RA, 0x0}},
    /* nga + halant + ka -> ligature L_DAKA */
    {1, 3, 1, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KA, 0x0}, {L_DAKA, 0x0}},
    /* nga + halant + ka -> ligature L_DAKHA */
    {1, 3, 1, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KHA, 0x0}, {L_DAKHA, 0x0}},
    /* nga + halant + ka -> ligature L_DAGA */
    {1, 3, 1, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GA, 0x0}, {L_DAGA, 0x0}},
    /* nga + halant + ka -> ligature L_DAGHA */
    {1, 3, 1, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GHA, 0x0}, {L_DAGHA, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KA, S_HALANT, 0x0}, {C_NGA, S_HALANT, C_KA, S_HALANT, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KHA, S_HALANT, 0x0}, {C_NGA, S_HALANT, C_KHA, S_HALANT, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GA, S_HALANT, 0x0}, {C_NGA, S_HALANT, C_GA, S_HALANT, 0x0}},
    /* nga + halant + ka -> ligature L_DAGHA */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GHA, S_HALANT, 0x0}, {C_NGA, S_HALANT, C_GHA, S_HALANT, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KA, DV_U, 0x0}, {C_NGA, S_HALANT, C_KA, DV_U, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KHA, DV_U, 0x0}, {C_NGA, S_HALANT, C_KHA, DV_U, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GA, DV_U, 0x0}, {C_NGA, S_HALANT, C_GA, DV_U, 0x0}},
    /* nga + halant + ka -> ligature L_DAGHA */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GHA, DV_U, 0x0}, {C_NGA, S_HALANT, C_GHA, DV_U, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KA, DV_UU, 0x0}, {C_NGA, S_HALANT, C_KA, DV_UU, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KHA, DV_UU, 0x0}, {C_NGA, S_HALANT, C_KHA, DV_UU, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GA, DV_UU, 0x0}, {C_NGA, S_HALANT, C_GA, DV_UU, 0x0}},
    /* nga + halant + ka -> ligature L_DAGHA */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GHA, DV_UU, 0x0}, {C_NGA, S_HALANT, C_GHA, DV_UU, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KA, DV_R, 0x0}, {C_NGA, S_HALANT, C_KA, DV_R, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_KHA, DV_R, 0x0}, {C_NGA, S_HALANT, C_KHA, DV_R, 0x0}},
    /* nga + halant + ka ->  */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GA, DV_R, 0x0}, {C_NGA, S_HALANT, C_GA, DV_R, 0x0}},
    /* nga + halant + ka -> ligature L_DAGHA */
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_GHA, DV_R, 0x0}, {C_NGA, S_HALANT, C_GHA, DV_R, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_NGA, S_HALANT, C_RA, S_HALANT, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_RA, DV_U, 0x0}, {C_NGA, S_HALANT, C_RA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_RA, DV_UU, 0x0}, {C_NGA, S_HALANT, C_RA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_NGA, S_HALANT, C_RA, DV_R, 0x0}, {C_NGA, S_HALANT, C_RA, DV_R, 0x0}},
	/* PMT RAKESH END 20061006 */

};

const GLYPH_INFO_TABLE CHA_Tbl[] = 
{
    /* cha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_CHA, 0x0}, {C_CHA, 0x0}},
    /* cha  + halant -> half form of cha   */
    {1, 2, 1, MMI_ALL_LANG, {C_CHA, S_HALANT, 0x0}, {H_CHA, 0x0}},
    /* cha + halant ra -> chra  OR cha + ra subscript */
    {1, 3, 1, MMI_ALL_LANG, {C_CHA, S_HALANT, C_RA, 0x0}, {L_CHRA, 0x0}},       /* Q */
    /* cha  + halant + ra + halant  -> chra + halant */
    /* START FARHAD PMT 20050211 */
    {1, 4, 3, MMI_ALL_LANG, {C_CHA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_CHA, C_RA, S_HALANT, 0x0}}       /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE CHHA_Tbl[] = 
{
    /* chha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_CHHA, 0x0}, {C_CHHA, 0x0}},
    /* chha + halant -> chha + halant */
    {0, 2, 2, MMI_ALL_LANG, {C_CHHA, S_HALANT, 0x0}, {C_CHHA, S_HALANT, 0x0}},
    /* chha + halant + ra -> chha + RA subscriprt(special representation) */
    {0, 3, 2, MMI_ALL_LANG, {C_CHHA, S_HALANT, C_RA, 0x0}, {C_CHHA, SUB_RA, 0x0}},

    {0, 4, 4, MMI_ALL_LANG, {C_CHHA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_CHHA, S_HALANT, C_RA, S_HALANT, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_CHHA, S_HALANT, C_RA, DV_U, 0x0}, {C_CHHA, S_HALANT, C_RA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_CHHA, S_HALANT, C_RA, DV_UU, 0x0}, {C_CHHA, S_HALANT, C_RA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_CHHA, S_HALANT, C_RA, DV_R, 0x0}, {C_CHHA, S_HALANT, C_RA, DV_R, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_CHHA, S_HALANT, C_YA, 0x0}, {L_CHHA_YA, 0x0}},
#endif
};

const GLYPH_INFO_TABLE JA_Tbl[] = 
{
    /* ja + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_JA, 0x0}, {C_JA, 0x0}},
    /* ja + halant -> half form of ja  */
    {1, 2, 1, MMI_ALL_LANG, {C_JA, S_HALANT, 0x0}, {H_JA, 0x0}},
    /* ja + nukta -> za */
    {0, 2, 1, MMI_ALL_LANG, {C_JA, S_NUKTA, 0x0}, {AC_ZA, 0x0}},
    /* ja + nukta + halant -> half za */
    {1, 3, 1, MMI_ALL_LANG, {C_JA, S_NUKTA, S_HALANT, 0x0}, {H_JA_N, 0x0}},
    /* ja + halant + ra -> jra  */
    {1, 3, 1, MMI_ALL_LANG, {C_JA, S_HALANT, C_RA, 0x0}, {L_JRA, 0x0}},
    /* ja + halant + nya -> GYA */
    {1, 3, 1, MMI_ALL_LANG, {C_JA, S_HALANT, C_NYA, 0x0}, {L_GYA, 0x0}},
    /* ja + halant + ra + halant -> jra + halant or ja + subscript RA + halant */
    {1, 4, 1, MMI_ALL_LANG, {C_JA, S_NUKTA, S_HALANT, C_RA, 0x0}, {L_JRA_N, 0x0}},

    /* ja + halant + nya + halant -> half form of GYA */
    /* START FARHAD PMT 20050211 */
    {1, 4, 2, MMI_ALL_LANG, {C_JA, S_HALANT, C_NYA, S_HALANT, 0x0}, {L_GYA, S_HALANT, 0x0}},
    /* ja + halant + ra + halant -> half ja + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_JA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_JA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE JHA_Tbl[] = 
{
    /* jha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_JHA, 0x0}, {C_JHA, 0x0}},
    /* jha + halant -> half jha  */
    {1, 2, 1, MMI_ALL_LANG, {C_JHA, S_HALANT, 0x0}, {H_JHA, 0x0}},
    /* jha + halant + ra-> jhra OR jha + subscript RA form */
    {1, 3, 1, MMI_ALL_LANG, {C_JHA, S_HALANT, C_RA, 0x0}, {L_JHRA, 0x0}},
    /*  jha + halant+ ra + halant  -> half jhra */
    /* START FARHAD PMT 20050211 */
    {1, 4, 3, MMI_ALL_LANG, {C_JHA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_JHA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NYA_Tbl[] = 
{
    /* nya + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_NYA, 0x0}, {C_NYA, 0x0}},
    /* nya + halant  -> half form of nya */
    {1, 2, 1, MMI_ALL_LANG, {C_NYA, S_HALANT, 0x0}, {H_NYA, 0x0}},
	/* PMT RAKESH END 20061006 */

};

const GLYPH_INFO_TABLE TTA_Tbl[] = 
{
    /* TTa + space -> TTa */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_TTA, 0x0}, {C_TTA, 0x0}},
    /* TTA + Halant -> TTA + Halant */
    {0, 2, 2, MMI_ALL_LANG, {C_TTA, S_HALANT, 0x0}, {C_TTA, S_HALANT, 0x0}},
    /* TTA + Halant + Ra -> TA + subscript RA */
    {1, 3, 2, MMI_ALL_LANG, {C_TTA, S_HALANT, C_RA, 0x0}, {C_TTA, SUB_RA, 0x0}},
    /* TTa + halant + TTa -> Ligature form of TTA below TTA */
    {1, 3, 1, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTA, 0x0}, {L_TTTTA, 0x0}},
    /* TTa + halant + TTHA -> Ligature form of TTHA below TTA */
    {1, 3, 1, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTHA, 0x0}, {L_TTHA, 0x0}},

    /* TTa + halant + TTa -> Ligature form of TTA below TTA */
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTA, S_HALANT, 0x0}, {C_TTA, S_HALANT, C_TTA, S_HALANT, 0x0}},

    /* TTa + halant + TTa -> Ligature form of TTA below TTA */
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTHA, S_HALANT, 0x0}, {C_TTA, S_HALANT, C_TTHA, S_HALANT, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTA, DV_U, 0x0}, {C_TTA, S_HALANT, C_TTA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTHA, DV_U, 0x0}, {C_TTA, S_HALANT, C_TTHA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTA, DV_UU, 0x0}, {C_TTA, S_HALANT, C_TTA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTHA, DV_UU, 0x0}, {C_TTA, S_HALANT, C_TTHA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTA, DV_R, 0x0}, {C_TTA, S_HALANT, C_TTA, DV_R, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_TTHA, DV_R, 0x0}, {C_TTA, S_HALANT, C_TTHA, DV_R, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_TTA, S_HALANT, C_RA, S_HALANT, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_RA, DV_U, 0x0}, {C_TTA, S_HALANT, C_RA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_RA, DV_UU, 0x0}, {C_TTA, S_HALANT, C_RA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTA, S_HALANT, C_RA, DV_R, 0x0}, {C_TTA, S_HALANT, C_RA, DV_R, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_TTA, S_HALANT, C_YA, 0x0}, {L_TTA_YA, 0x0}},
#endif
};

const GLYPH_INFO_TABLE TTHA_Tbl[] = 
{
    /* Tha -> Tha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_TTHA, 0x0}, {C_TTHA, 0x0}},
    /* TTHA + halant -> TTHA + Halant */
    {0, 2, 2, MMI_ALL_LANG, {C_TTHA, S_HALANT, 0x0}, {C_TTHA, S_HALANT, 0x0}},

    /* TTha + halant + Ra -> TTHA + subscript form of RA(special type) */
    {1, 3, 2, MMI_ALL_LANG, {C_TTHA, S_HALANT, C_RA, 0x0}, {C_TTHA, SUB_RA, 0x0}},
    /* TTha + halant + TTha -> TTHA + subscript form of RA(special type) */
    {1, 3, 1, MMI_ALL_LANG, {C_TTHA, S_HALANT, C_TTHA, 0x0}, {L_TTTHA, 0x0}},
    /* TTha + halant + TTha -> TTHA + subscript form of RA(special type) */
    {1, 4, 4, MMI_ALL_LANG, {C_TTHA, S_HALANT, C_TTHA, S_HALANT, 0x0}, {C_TTHA, S_HALANT, C_TTHA, S_HALANT, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_TTHA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_TTHA, S_HALANT, C_RA, S_HALANT, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTHA, S_HALANT, C_RA, DV_U, 0x0}, {C_TTHA, S_HALANT, C_RA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTHA, S_HALANT, C_RA, DV_UU, 0x0}, {C_TTHA, S_HALANT, C_RA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_TTHA, S_HALANT, C_RA, DV_R, 0x0}, {C_TTHA, S_HALANT, C_RA, DV_R, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_TTHA, S_HALANT, C_YA, 0x0}, {L_TTHA_YA, 0x0}},
#endif
};

const GLYPH_INFO_TABLE DDA_Tbl[] = 
{
    /* dda + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_DDA, 0x0}, {C_DDA, 0x0}},
    /* dda + halant -> dda+ halant */
    {1, 2, 2, MMI_ALL_LANG, {C_DDA, S_HALANT, 0x0}, {C_DDA, S_HALANT, 0x0}},
    /* Dda + nukta -> dda with nukta */
    {1, 2, 1, MMI_ALL_LANG, {C_DDA, S_NUKTA, 0x0}, {AC_DDDHA, 0x0}},
    /* Dda + nukta+ halant  -> dda with nukta + halant */
    {1, 3, 2, MMI_ALL_LANG, {C_DDA, S_NUKTA, S_HALANT, 0x0}, {AC_DDDHA, S_HALANT, 0x0}},
    /* dda + halant + ra -> dda + subscript ra(special represenatio */
    {1, 3, 2, MMI_ALL_LANG, {C_DDA, S_HALANT, C_RA, 0x0}, {C_DDA, SUB_RA, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 3, 1, MMI_ALL_LANG, {C_DDA, S_HALANT, C_GA, 0x0}, {L_DDAGA, 0x0}},
    /* dda + halant + ra -> ligature L_DADA */
    {1, 3, 1, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDA, 0x0}, {L_DADA, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 3, 1, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDHA, 0x0}, {L_DADDHA, 0x0}},

    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDHA, S_HALANT, 0x0}, {C_DDA, S_HALANT, C_DDHA, S_HALANT, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_GA, S_HALANT, 0x0}, {C_DDA, S_HALANT, C_GA, S_HALANT, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDA, S_HALANT, 0x0}, {C_DDA, S_HALANT, C_DDA, S_HALANT, 0x0}},

    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDHA, DV_U, 0x0}, {C_DDA, S_HALANT, C_DDHA, DV_U, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_GA, DV_U, 0x0}, {C_DDA, S_HALANT, C_GA, DV_U, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDA, DV_U, 0x0}, {C_DDA, S_HALANT, C_DDA, DV_U, 0x0}},

    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDHA, DV_UU, 0x0}, {C_DDA, S_HALANT, C_DDHA, DV_UU, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_GA, DV_UU, 0x0}, {C_DDA, S_HALANT, C_GA, DV_UU, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDA, DV_UU, 0x0}, {C_DDA, S_HALANT, C_DDA, DV_UU, 0x0}},

    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDHA, DV_R, 0x0}, {C_DDA, S_HALANT, C_DDHA, DV_R, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_GA, DV_R, 0x0}, {C_DDA, S_HALANT, C_GA, DV_R, 0x0}},
    /* dda + halant + ga -> ligature L_DDAGA */
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_DDA, DV_R, 0x0}, {C_DDA, S_HALANT, C_DDA, DV_R, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_DDA, S_HALANT, C_RA, S_HALANT, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_RA, DV_U, 0x0}, {C_DDA, S_HALANT, C_RA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_RA, DV_UU, 0x0}, {C_DDA, S_HALANT, C_RA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DDA, S_HALANT, C_RA, DV_R, 0x0}, {C_DDA, S_HALANT, C_RA, DV_R, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_DDA, S_HALANT, C_YA, 0x0}, {L_DDA_YA, 0x0}},
#endif
};

const GLYPH_INFO_TABLE DDHA_Tbl[] = 
{
    /* ddha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_DDHA, 0x0}, {C_DDHA, 0x0}},
    /* ddha + halant -> ddha + halant */
    {0, 2, 2, MMI_ALL_LANG, {C_DDHA, S_HALANT, 0x0}, {C_DDHA, S_HALANT, 0x0}},
    /* Ddha + nukta -> ddha with nukta form */
    {0, 2, 1, MMI_ALL_LANG, {C_DDHA, S_NUKTA, 0x0}, {AC_RHA, 0x0}},
    /* ddha + nukta + halant -> ddha with nukta form + halant */
    {1, 3, 2, MMI_ALL_LANG, {C_DDHA, S_NUKTA, S_HALANT, 0x0}, {AC_RHA, S_HALANT, 0x0}},
    /* ddha + halant + ra -> ddha + subscript ra(special form) */
    {1, 3, 2, MMI_ALL_LANG, {C_DDHA, S_HALANT, C_RA, 0x0}, {C_DDHA, SUB_RA, 0x0}},
    /* ddha + nukta + halant + ra -> ddha with nukta form + subscript ra(special form) */
    {1, 4, 2, MMI_ALL_LANG, {C_DDHA, S_NUKTA, S_HALANT, C_RA, 0x0}, {AC_RHA, SUB_RA, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_DDHA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_DDHA, S_HALANT, C_RA, S_HALANT, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DDHA, S_HALANT, C_RA, DV_U, 0x0}, {C_DDHA, S_HALANT, C_RA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DDHA, S_HALANT, C_RA, DV_UU, 0x0}, {C_DDHA, S_HALANT, C_RA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DDHA, S_HALANT, C_RA, DV_R, 0x0}, {C_DDHA, S_HALANT, C_RA, DV_R, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_DDHA, S_HALANT, C_YA, 0x0}, {L_DDHA_YA, 0x0}},
#endif
};

const GLYPH_INFO_TABLE NNA_Tbl[] = 
{
    /* Nna+ space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_NNA, 0x0}, {C_NNA, 0x0}},
    /* Nna + halant -> half Nna */
    {1, 2, 1, MMI_ALL_LANG, {C_NNA, S_HALANT, 0x0}, {H_ANNA, 0x0}},
    /* Nna + halant + ra -> half Nna + ra(nominal form) */
    {1, 3, 2, MMI_ALL_LANG, {C_NNA, S_HALANT, C_RA, 0x0}, {H_ANNA, C_RA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE TA_Tbl[] = 
{
    /* ta + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_TA, 0x0}, {C_TA, 0x0}},
    /* ta + halant -> half form of ta */
    {1, 2, 1, MMI_ALL_LANG, {C_TA, S_HALANT, 0x0}, {H_TA, 0x0}},
    /* ta + halant + ra ->  tra(ligature) */
    {1, 3, 1, MMI_ALL_LANG, {C_TA, S_HALANT, C_RA, 0x0}, {L_TRA, 0x0}},
    /* ta + halant + ra + halant -> half tra  */
    /* {1,4,1,MMI_ALL_LANG,           {C_TA,S_HALANT,C_RA,S_HALANT,0x0},  {H_TRA,0x0} },//vj 01/12/04 */
    /* ta + halant + ta -> TTA(ligature form) */
    {1, 3, 1, MMI_ALL_LANG, {C_TA, S_HALANT, C_TA, 0x0}, {L_TTTA, 0x0}}
    /* ta + halant + ta + halant -> half form of tta(ligature form) */
    /* {1,4,1,MMI_ALL_LANG,       {C_TA,S_HALANT,C_TA,S_HALANT,0x0},  {H_TTA,0x0} } */
	/* PMT RAKESH END 20061006 */

};

const GLYPH_INFO_TABLE THA_Tbl[] = 
{
    /* tha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_THA, 0x0}, {C_THA, 0x0}},
    /* tha + halant -> half form of tha */
    {1, 2, 1, MMI_ALL_LANG, {C_THA, S_HALANT, 0x0}, {H_THA, 0x0}},
    /* tha + halant + ra ->  tha + subscript form of RA */
    {1, 3, 1, MMI_ALL_LANG, {C_THA, S_HALANT, C_RA, 0x0}, {L_THRA, 0x0}},       /* Q */
    /* START FARHAD PMT 20050211 */
    /* tha + halant + ra + halant -> half tha + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_THA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_THA, C_RA, S_HALANT, 0x0}}       /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE DA_Tbl[] = 
{
    /* da + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_DA, 0x0}, {C_DA, 0x0}},
    /* da + halant -> da + halant */
    {0, 2, 2, MMI_ALL_LANG, {C_DA, S_HALANT, 0x0}, {C_DA, S_HALANT, 0x0}},
    /* da + halant + ra -> da + subscript ra  */
    {1, 3, 1, MMI_ALL_LANG, {C_DA, S_HALANT, C_RA, 0x0}, {L_DRA, 0x0}}, /* Q */
    /* da + halant + ya  ->  ligature dya */
    {1, 3, 1, MMI_ALL_LANG, {C_DA, S_HALANT, C_DA, 0x0}, {L_DYA, 0x0}},
    /* da +halant + da ->   ligature ddya */
    {1, 3, 1, MMI_ALL_LANG, {C_DA, S_HALANT, C_YA, 0x0}, {L_DDYA, 0x0}},
    /* da + halant + va   ->  ligature DVA */
    {1, 3, 1, MMI_ALL_LANG, {C_DA, S_HALANT, C_VA, 0x0}, {L_DVA, 0x0}},
    /* da + halant + dha   ->  ligature L_DADHA */
    {1, 3, 1, MMI_ALL_LANG, {C_DA, S_HALANT, C_DHA, 0x0}, {L_DADHA, 0x0}},
    /* da + halant + bha   ->  ligature L_DABHA */
    {1, 3, 1, MMI_ALL_LANG, {C_DA, S_HALANT, C_BHA, 0x0}, {L_DABHA, 0x0}},

    {1, 3, 1, MMI_ALL_LANG, {C_DA, S_HALANT, C_MA, 0x0}, {L_DAMA, 0x0}},

    /* da + halant + ya  ->  ligature dya */
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DA, S_HALANT, 0x0}, {C_DA, S_HALANT, C_DA, S_HALANT, 0x0}},
    /* da + halant + ya  ->  ligature dya */
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_YA, S_HALANT, 0x0}, {C_DA, S_HALANT, C_YA, S_HALANT, 0x0}},
    /* da + halant + va +halant  ->   */
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_VA, S_HALANT, 0x0}, {C_DA, S_HALANT, C_VA, S_HALANT, 0x0}},
    /* da + halant + va +halant  ->   */
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DHA, S_HALANT, 0x0}, {C_DA, S_HALANT, C_DHA, S_HALANT, 0x0}},
    /* da + halant + va +halant  ->   */
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_BHA, S_HALANT, 0x0}, {C_DA, S_HALANT, C_BHA, S_HALANT, 0x0}},
    /* da + halant + ma   ->  ligature L_DAMA */
    /* da + halant + ma   ->  ligature L_DAMA */
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_MA, S_HALANT, 0x0}, {C_DA, S_HALANT, C_MA, S_HALANT, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DA, DV_U, 0x0}, {C_DA, S_HALANT, C_DA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_YA, DV_U, 0x0}, {C_DA, S_HALANT, C_YA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_VA, DV_U, 0x0}, {C_DA, S_HALANT, C_VA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DHA, DV_U, 0x0}, {C_DA, S_HALANT, C_DHA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_BHA, DV_U, 0x0}, {C_DA, S_HALANT, C_BHA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_MA, DV_U, 0x0}, {C_DA, S_HALANT, C_MA, DV_U, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DA, DV_UU, 0x0}, {C_DA, S_HALANT, C_DA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_YA, DV_UU, 0x0}, {C_DA, S_HALANT, C_YA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_VA, DV_UU, 0x0}, {C_DA, S_HALANT, C_VA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DHA, DV_UU, 0x0}, {C_DA, S_HALANT, C_DHA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_BHA, DV_UU, 0x0}, {C_DA, S_HALANT, C_BHA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_MA, DV_UU, 0x0}, {C_DA, S_HALANT, C_MA, DV_UU, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DA, DV_R, 0x0}, {C_DA, S_HALANT, C_DA, DV_R, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_YA, DV_R, 0x0}, {C_DA, S_HALANT, C_YA, DV_R, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_VA, DV_R, 0x0}, {C_DA, S_HALANT, C_VA, DV_R, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_DHA, DV_R, 0x0}, {C_DA, S_HALANT, C_DHA, DV_R, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_BHA, DV_R, 0x0}, {C_DA, S_HALANT, C_BHA, DV_R, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_MA, DV_R, 0x0}, {C_DA, S_HALANT, C_MA, DV_R, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_DA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_DA, S_HALANT, C_RA, S_HALANT, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_DA, S_HALANT, C_MA, 0x0}, {L_DA_MA, 0x0}},
#endif 
};

const GLYPH_INFO_TABLE DHA_Tbl[] = 
{
    /* Dha +space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_DHA, 0x0}, {C_DHA, 0x0}},
    /* Dha + halant - > half form of Dha */
    {1, 2, 1, MMI_ALL_LANG, {C_DHA, S_HALANT, 0x0}, {H_DHA, 0x0}},
    /* Dha + halant + ra ->  Dhra OR dha + subscript ra */
    /* START FARHAD PMT 20050211 */
    {1, 3, 1, MMI_ALL_LANG, {C_DHA, S_HALANT, C_RA, 0x0}, {L_DHRA, 0x0}},
    /* Dha + halant + ra + halant ->  half dha + Ra + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_DHA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_DHA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NA_Tbl[] = 
{
    /* na + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_NA, 0x0}, {C_NA, 0x0}},
    /* na + halant  ->  half form of na */
    {1, 2, 1, MMI_ALL_LANG, {C_NA, S_HALANT, 0x0}, {H_NA, 0x0}},
    /* na + halant + ra  -> na + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_NA, S_HALANT, C_RA, 0x0}, {L_NRA, 0x0}}, /* Q */
    /* na + halant + na -> (ligature form) NNA */
    {1, 3, 1, MMI_ALL_LANG, {C_NA, S_HALANT, C_NA, 0x0}, {L_NNNA, 0x0}},
    /* START FARHAD PMT 20050211 */
    /* na + halant + ra + halant -> half na + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_NA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_NA, C_RA, S_HALANT, 0x0}},        /* Q */
    /* END FARHAD PMT 20050211 */

    /* na + halant + na + halant -> (ligature form) NNA + halant */
    {1, 4, 2, MMI_ALL_LANG, {C_NA, S_HALANT, C_NA, S_HALANT, 0x0}, {L_NNNA, S_HALANT, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NNNA_Tbl[] = 
{
    /* nna + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_NNNA, 0x0}, {C_NNNA, 0x0}},
    /* nna + halant  ->  half form of na */
    {1, 2, 1, MMI_ALL_LANG, {C_NNNA, S_HALANT, 0x0}, {H_NNNA, 0x0}},
    //  /* nna + halant + ra  -> na + subscript RA*/
    //{1,3,2,MMI_ALL_LANG,                     {C_NNNA,S_HALANT,C_RA,0x0},         {C_NNNA,DV_R,0x0} },/*Q*/
    /* nna + halant + na -> (ligature form) NNA */
    {1, 3, 1, MMI_ALL_LANG, {C_NNA, S_HALANT, C_NNA, 0x0}, {L_NNNA, 0x0}},
    /* START FARHAD PMT 20050211 */
    /* nna + halant + ra + halant -> half nna + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_NNNA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_NNNA, C_RA, S_HALANT, 0x0}},
    /* END FARHAD PMT 20050211 */

    /* nna + halant + na + halant -> (ligature form) NNA + halant */
    {1, 4, 2, MMI_ALL_LANG, {C_NNNA, S_HALANT, C_NNNA, S_HALANT, 0x0}, {L_NNNA, S_HALANT, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE PA_Tbl[] = 
{
    /* pa + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_PA, 0x0}, {C_PA, 0x0}},
    /* pa + halant -> half of pa */
    {1, 2, 1, MMI_ALL_LANG, {C_PA, S_HALANT, 0x0}, {H_PA, 0x0}},
    /* pa + halant + ra -> pra OR pa + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_PA, S_HALANT, C_RA, 0x0}, {L_PRA, 0x0}},
    /* START FARHAD PMT 20050211 */
    /* pa + halant + ra + halant -> half pa + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_PA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_PA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE PHA_Tbl[] = 
{
    /* pha +space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_PHA, 0x0}, {C_PHA, 0x0}},
    /* pha + halant -> half form of pha */
    {1, 2, 1, MMI_ALL_LANG, {C_PHA, S_HALANT, 0x0}, {H_PHA, 0x0}},
    /* pha + nukta -> pha with nukta form  */
    {1, 2, 1, MMI_ALL_LANG, {C_PHA, S_NUKTA, 0x0}, {AC_FA, 0x0}},
    /* pha + nukta + halant-> half pha with nukta */
    {1, 3, 1, MMI_ALL_LANG, {C_PHA, S_NUKTA, S_HALANT, 0x0}, {H_PHA_N, 0x0}},
    /* pha + halant + ra -> fra OR pha + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_PHA, S_HALANT, C_RA, 0x0}, {L_FRA, 0x0}},
    /* pha + nukta + halant + ra -> pha with nukta + subscript RA */
    /* START FARHAD PMT 20050211 */
    {1, 4, 1, MMI_ALL_LANG, {C_PHA, S_NUKTA, S_HALANT, C_RA, 0x0}, {L_FRA_N, 0x0}},

    /* pha + halant + ra + halant -> half pha + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_PHA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_PHA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
    /* pha + nukta + halant + ra + halant -> pha with nukta + subscript RA + halant */
    /* {1,4,1,MMI_ALL_LANG,                  {C_PHA,S_NUKTA,S_HALANT,C_RA,0x0},  {L_FRA_N,0x0} } */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE BA_Tbl[] = 
{
    /* ba + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_BA, 0x0}, {C_BA, 0x0}},
    /* ba + halant -> half form of ba */
    {1, 2, 1, MMI_ALL_LANG, {C_BA, S_HALANT, 0x0}, {H_BA, 0x0}},
    /* ba + halant + ra -> ba + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_BA, S_HALANT, C_RA, 0x0}, {L_BRA, 0x0}}, /* Q */
    /* ba + halant + ra + halant -> ba + subscript RA + halant */
    /* START FARHAD PMT 20050211 */
    {1, 4, 3, MMI_ALL_LANG, {C_BA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_BA, C_RA, S_HALANT, 0x0}} /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE BHA_Tbl[] = 
{
    /* bha  + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_BHA, 0x0}, {C_BHA, 0x0}},
    /* bha + halant -> half form of bha   */
    {1, 2, 1, MMI_ALL_LANG, {C_BHA, S_HALANT, 0x0}, {H_BHA, 0x0}},
    /* bha + halant + ra ->  bha + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_BHA, S_HALANT, C_RA, 0x0}, {L_BHRA, 0x0}},       /* Q */
    /* START FARHAD PMT 20050211 */
    /* bha + halant + ra + halant -> half bha + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_BHA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_BHA, C_RA, S_HALANT, 0x0}}       /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MA_Tbl[] = 
{
    /* ma  + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_MA, 0x0}, {C_MA, 0x0}},
    /* ma + halant -> half form of ma */
    {1, 2, 1, MMI_ALL_LANG, {C_MA, S_HALANT, 0x0}, {H_MA, 0x0}},
    /* ma + halant + ra -> ma + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_MA, S_HALANT, C_RA, 0x0}, {L_MRA, 0x0}}, /* Q */
    /* START FARHAD PMT 20050211 */
    /* ma + halant + ra + halant ->half ma + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_MA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_MA, C_RA, S_HALANT, 0x0}} /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE YA_Tbl[] = 
{
    /* ya + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_YA, 0x0}, {C_YA, 0x0}},
    /* ya + halant -> half form of ya */
    {1, 2, 1, MMI_ALL_LANG, {C_YA, S_HALANT, 0x0}, {H_YA, 0x0}},
    /* ya + nukta   -> ya with nukta form */
    {1, 2, 1, MMI_ALL_LANG, {C_YA, S_NUKTA, 0x0}, {AC_YYA, 0x0}},
    /* ya + nukta + halant -> half form of ya with nukta */
    {1, 3, 1, MMI_ALL_LANG, {C_YA, S_NUKTA, S_HALANT, 0x0}, {L_YA_N, 0x0}},
    /* ya + halant + ra -> ya + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_YA, S_HALANT, C_RA, 0x0}, {L_YRA, 0x0}}, /* Q */
    /* ya + halant + ra + halant -> ya+ subscript RA + halant */
    /* START FARHAD PMT 20050211 */
    {1, 4, 3, MMI_ALL_LANG, {C_YA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_YA, C_RA, S_HALANT, 0x0}},        /* Q */
    /* END FARHAD PMT 20050211 */
    /* ya + nukta + halant + ra -> ya with nukta + subscript form of RA */
    // {1,4,2,MMI_ALL_LANG,                  {C_YA,S_HALANT,C_RA,S_HALANT,0x0},  {AC_YYA,DV_R,0x0} },/*Q*/
    /* ya + nukta +halant + ra + halant -> ya with nukta + subscript RA + halant */
    {1, 4, 1, MMI_ALL_LANG, {C_YA, S_NUKTA, S_HALANT, C_RA, 0x0}, {L_YRA_N, 0x0}},
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE RA_Tbl[] = 
{
    /* ra + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_RA, 0x0}, {C_RA, 0x0}},
    /* ra + halant -> superscript form of RA */
    {1, 2, 1, MMI_ALL_LANG, {C_RA, S_HALANT, 0x0}, {SUP_RA, 0x0}},
    /* ra + U -> Ru  */
    {1, 2, 1, MMI_ALL_LANG, {C_RA, DV_U, 0x0}, {L_RU, 0x0}},
    /* ra + UU -> RU  */
    {1, 2, 1, MMI_ALL_LANG, {C_RA, DV_UU, 0x0}, {L_RUU, 0x0}},

    {1, 3, 1, MMI_ALL_LANG, {C_RA, S_HALANT, S_BINDU, 0x0}, {L_RABIN, 0x0}},

    /* RA + HAL + DV_E -> L_DVERA */
    {1, 3, 1, MMI_ALL_LANG, {C_RA, S_HALANT, DV_E, 0x0}, {L_DVERA, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {C_RA, S_HALANT, DV_AI, 0x0}, {L_DVAIRA, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {C_RA, S_HALANT, DV_O, 0x0}, {L_DVORA, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {C_RA, S_HALANT, DV_AU, 0x0}, {L_DVAURA, 0x0}},
    {1, 4, 1, MMI_ALL_LANG, {C_RA, S_HALANT, DV_E, S_BINDU, 0x0}, {L_DVEBINRA, 0x0}},

    {1, 4, 1, MMI_ALL_LANG, {C_RA, S_HALANT, DV_AI, S_BINDU, 0x0}, {L_DVAIBINRA, 0x0}},

    {1, 4, 1, MMI_ALL_LANG, {C_RA, S_HALANT, DV_O, S_BINDU, 0x0}, {L_DVOBINRA, 0x0}},

    /* {1,4,1,MMI_ALL_LANG, {C_RA,S_HALANT,DV_AU,S_BINDU,0x0},        {L_DVAUBINRA,0x0} }, */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE RRA_Tbl[] = 
{
    /* ra + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_RRA, 0x0}, {C_RRA, 0x0}},
    /* ra + halant -> eyelash RA */
    {1, 2, 1, MMI_ALL_LANG, {C_RRA, S_HALANT, 0x0}, {H_EYLASH, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE LA_Tbl[] = 
{
    /* la + space */
    {0, 1, 1, MMI_ALL_LANG, {C_LA, 0x0}, {C_LA, 0x0}},
    /* la + halant -> half form of la */
    {1, 2, 1, MMI_ALL_LANG, {C_LA, S_HALANT, 0x0}, {H_LA, 0x0}},
    /* la + halant + ra -> half forFm of la + ra(nominal form) */
    {1, 3, 2, MMI_ALL_LANG, {C_LA, S_HALANT, C_RA, 0x0}, {H_LA, C_RA, 0x0}},
#ifdef __MMI_LANG_MARATHI__    
    {1, 3, 1, MMI_MARATHI_LANG, {C_LA, S_HALANT, C_LA, 0x0}, {L_LA_LA, 0x0}},
#endif
};

const GLYPH_INFO_TABLE LLA_Tbl[] = 
{
    /* Lla */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_LLA, 0x0}, {C_LLA, 0x0}},
    //START FARHAD PMT 20050211
    //START VIJAY PMT 20050728....HALF FORM ADDED
    /* Lla + halant -> Half form of LLA */
    {0, 2, 1, MMI_ALL_LANG, {C_LLA, S_HALANT, 0x0}, {H_LLA, 0x0}},
    /* Lla + halant + ra-> Lla + halant + ra */
    {0, 3, 2, MMI_ALL_LANG, {C_LLA, S_HALANT, C_RA, 0x0}, {H_LLA, C_RA, 0x0}},
    /* Lla + halant + ra + Halant-> Lla + halant + ra + Halant */
    {0, 4, 4, MMI_ALL_LANG, {C_LLA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_LLA, C_RA, S_HALANT, 0x0}}
    //END VIJAY PMT 20050728
    //END FARHAD PMT 20050211
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE LLLA_Tbl[] = 
{
    /* Llla */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_LLLA, 0x0}, {C_LLLA, 0x0}},
    //START FARHAD PMT 20050211             
    //START VIJAY PMT 20050728....HALF FORM ADDED
    /* Llla + halant -> half form of LLLA */
    {0, 2, 1, MMI_ALL_LANG, {C_LLLA, S_HALANT, 0x0}, {H_LLLA, 0x0}},
    /* Llla + halant + ra-> Llla + halant + ra */
    {0, 3, 2, MMI_ALL_LANG, {C_LLLA, S_HALANT, C_RA, 0x0}, {H_LLLA, C_RA, 0x0}},
    /* Llla + halant + ra + Halant-> Llla + halant + ra + Halant */
    {0, 4, 3, MMI_ALL_LANG, {C_LLLA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_LLLA, C_RA, S_HALANT, 0x0}}
    //END VIJAY PMT 20050728
    //END FARHAD PMT 20050211
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE VA_Tbl[] = 
{
    /* va */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_VA, 0x0}, {C_VA, 0x0}},
    /* va + halant -> half form of va */
    {1, 2, 1, MMI_ALL_LANG, {C_VA, S_HALANT, 0x0}, {H_VA, 0x0}},
    /* va + halant + ra -> vra OR va + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {C_VA, S_HALANT, C_RA, 0x0}, {L_VRA, 0x0}}, /* Q */
    /* va + halant + ra + halant -> vra OR va + subscript RA +halant  */
    /* START FARHAD PMT 20050211 */
    {1, 4, 3, MMI_ALL_LANG, {C_VA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_VA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE SHA_Tbl[] = 
{
    /* sha */
    {0, 1, 1, MMI_ALL_LANG, {C_SHA, 0x0}, {C_SHA, 0x0}},
    /* sha + halant -> half form of sha */
    {1, 2, 1, MMI_ALL_LANG, {C_SHA, S_HALANT, 0x0}, {H_SHA, 0x0}},
    /* sha + halant + ra -> shra ligature */
    {1, 3, 1, MMI_ALL_LANG, {C_SHA, S_HALANT, C_RA, 0x0}, {L_SHRA, 0x0}},
    /* sha + halant + ra + halant -> half shra OR shra + halant */
    /* {1,4,1,MMI_ALL_LANG,           {C_SHA,S_HALANT,C_RA,S_HALANT,0x0},  {H_SHRA,0x0} } */
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_SHA, S_HALANT, C_CHA, 0x0}, {L_SHRA_CHA, 0x0}},
    {1, 3, 1, MMI_MARATHI_LANG, {C_SHA, S_HALANT, C_VA, 0x0}, {L_SHRA_VA, 0x0}},
    {1, 3, 1, MMI_MARATHI_LANG, {C_SHA, S_HALANT, C_LA, 0x0}, {L_SHRA_LA, 0x0}},
    {1, 3, 1, MMI_MARATHI_LANG, {C_SHA, S_HALANT, C_NA, 0x0}, {L_SHRA_NA, 0x0}}
#endif
};

const GLYPH_INFO_TABLE SSA_Tbl[] = 
{
    /* Ssa */
    {0, 1, 1, MMI_ALL_LANG, {C_SSA, 0x0}, {C_SSA, 0x0}},
    /* SSA + halant -> half form of SSA  */
    {1, 2, 1, MMI_ALL_LANG, {C_SSA, S_HALANT, 0x0}, {H_SSA, 0x0}},
    /* ssa + halant + ra -> half ssa + ra(nominal form) */
    /* START FARHAD PMT 20050211 */
    {1, 3, 2, MMI_ALL_LANG, {C_SSA, S_HALANT, C_RA, 0x0}, {H_SSA, C_RA, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 3, 1, MMI_MARATHI_LANG, {C_SSA, S_HALANT, C_TTA, 0x0}, {L_SSA_TTA, 0x0}},
#endif
    /* ssa + halant + ra + halant -> half ssa + ra + Halant */
    {1, 4, 3, MMI_ALL_LANG, {C_SSA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_SSA, C_RA, S_HALANT, 0x0}},
#ifdef __MMI_LANG_MARATHI__
    {1, 5, 1, MMI_MARATHI_LANG, {C_SSA, S_HALANT, C_TTA, S_HALANT, C_RA, 0x0}, {L_SSA_TTA_RA, 0x0}}
#endif
};

const GLYPH_INFO_TABLE SA_Tbl[] = 
{
    /* sa + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_SA, 0x0}, {C_SA, 0x0}},
    /* sa + halant -> half form of sa */
    {1, 2, 1, MMI_ALL_LANG, {C_SA, S_HALANT, 0x0}, {H_SA, 0x0}},
    /* sa + halant + ra -> sa + subscript RA OR sra */
    {1, 3, 1, MMI_ALL_LANG, {C_SA, S_HALANT, C_RA, 0x0}, {L_SRA, 0x0}},
    /* START FARHAD PMT 20050211 */
    /* sa + halan + ra + halant -> half sa + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {C_SA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_SA, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE HA_Tbl[] = 
{
    /* ha + space  */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {C_HA, 0x0}, {C_HA, 0x0}},
    /* ha + halant  -> half ha */
    {0, 2, 1, MMI_ALL_LANG, {C_HA, S_HALANT, 0x0}, {H_HA, 0x0}},
    /* ha + halant + ra -> ligature form OR ha + subscript RA(special form) */
    {1, 3, 1, MMI_ALL_LANG, {C_HA, S_HALANT, C_RA, 0x0}, {L_HRA, 0x0}},
    /* ha + halant + ya -> ligature form */
    {1, 3, 1, MMI_ALL_LANG, {C_HA, S_HALANT, C_YA, 0x0}, {L_HYA, 0x0}},
    /* ha + halant + ma -> ligature form */
    {1, 3, 1, MMI_ALL_LANG, {C_HA, S_HALANT, C_MA, 0x0}, {L_HMMA, 0x0}},
    /* ha + halant + ra + halant -> ligature form + halant OR ha + subscript RA(special form) + halant */
    {1, 4, 2, MMI_ALL_LANG, {C_HA, S_HALANT, C_RA, S_HALANT, 0x0}, {L_HRA, S_HALANT, 0x0}},

    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_YA, S_HALANT, 0x0}, {C_HA, S_HALANT, C_YA, S_HALANT, 0x0}},
    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_MA, S_HALANT, 0x0}, {C_HA, S_HALANT, C_MA, S_HALANT, 0x0}},

    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_RA, S_HALANT, 0x0}, {C_HA, S_HALANT, C_RA, S_HALANT, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_RA, DV_U, 0x0}, {C_HA, S_HALANT, C_RA, DV_U, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_RA, DV_UU, 0x0}, {C_HA, S_HALANT, C_RA, DV_UU, 0x0}},
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_RA, DV_R, 0x0}, {C_HA, S_HALANT, C_RA, DV_R, 0x0}},

    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_YA, DV_U, 0x0}, {C_HA, S_HALANT, C_YA, DV_U, 0x0}},
    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_MA, DV_U, 0x0}, {C_HA, S_HALANT, C_MA, DV_U, 0x0}},

    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_YA, DV_UU, 0x0}, {C_HA, S_HALANT, C_YA, DV_UU, 0x0}},
    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_MA, DV_UU, 0x0}, {C_HA, S_HALANT, C_MA, DV_UU, 0x0}},

    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_YA, DV_R, 0x0}, {C_HA, S_HALANT, C_YA, DV_R, 0x0}},
    /* ha + halant + ya -> ligature form */
    {1, 4, 4, MMI_ALL_LANG, {C_HA, S_HALANT, C_MA, DV_R, 0x0}, {C_HA, S_HALANT, C_MA, DV_R, 0x0}},
	/* PMT RAKESH END 20061006 */

};

                           /* ADDITIONAL CONSONANT'S TABLE */

const GLYPH_INFO_TABLE QA_Tbl[] = 
{
    /* qa + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_QA, 0x0}, {AC_QA, 0x0}},
    /* qa + Halant/Virama -> Half form of qa */
    {1, 2, 1, MMI_ALL_LANG, {AC_QA, S_HALANT, 0x0}, {L_KA_N, 0x0}},
    //  /* qa + Halant + Ra -> qra */
    {1, 3, 1, MMI_ALL_LANG, {AC_QA, S_HALANT, C_RA, 0x0}, {L_KRA_N, 0x0}},
    /* qa + Halant + Ra + Halant -> qra +Halant */
    /* {1,4,2,MMI_ALL_LANG,     {AC_QA,S_HALANT,C_RA,S_HALANT,0x0},  {L_KRA,S_HALANT,0x0}}, */
    /* START FARHAD PMT 20050211 */
    /* Qa + Halant + Ra + Halant -> Half Form of Ka + Ra + Halant */
    {1, 4, 3, MMI_ALL_LANG, {AC_QA, S_HALANT, C_RA, S_HALANT, 0x0}, {L_KA_N, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */

};

const GLYPH_INFO_TABLE KHHA_Tbl[] = 
{
    /* khha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_KHHA, 0x0}, {AC_KHHA, 0x0}},
    /* Khha + halant  -> half form of khha */
    {1, 2, 1, MMI_ALL_LANG, {AC_KHHA, S_HALANT, 0x0}, {L_KHA_N, 0x0}},
    /* khha + halant + ra -> Khha + subscript form of RA OR KHHRA as a whole */
    {1, 3, 1, MMI_ALL_LANG, {AC_KHHA, S_HALANT, C_RA, 0x0}, {L_KHRA_N, 0x0}},   /* Q *//* new */
    /* START FARHAD PMT 20050211 */
    /* khha + halant + ra + halant -> half khha + RA  + halant */
    {1, 4, 3, MMI_ALL_LANG, {AC_KHHA, S_HALANT, C_RA, S_HALANT, 0x0}, {L_KHA_N, C_RA, S_HALANT, 0x0}}   /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE GHHA_Tbl[] = 
{
    /* ghhaa + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_GHHA, 0x0}, {AC_GHHA, 0x0}},
    /* ghha + halant -> half form of ghha */
    {1, 2, 1, MMI_ALL_LANG, {AC_GHHA, S_HALANT, 0x0}, {L_GA_N, 0x0}},
    /* ghha + halant + ra -> ghha + subscript form of RA */
    {1, 3, 1, MMI_ALL_LANG, {AC_GHHA, S_HALANT, C_RA, 0x0}, {L_GRA_N, 0x0}},    /* Q *//* new */
    /* START FARHAD PMT 20050211 */
    /* ghha + halant + ra + halant -> half ghha + RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {AC_GHHA, S_HALANT, C_RA, S_HALANT, 0x0}, {L_GA_N, C_RA, S_HALANT, 0x0}}    /* Q */
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE ZA_Tbl[] = 
{
    /* za + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_ZA, 0x0}, {AC_ZA, 0x0}},
    /* za + halant -> half form of za  */
    {1, 2, 1, MMI_ALL_LANG, {AC_ZA, S_HALANT, 0x0}, {H_JA_N, 0x0}},
    /* za + halant + ra -> zra  */
    {1, 3, 1, MMI_ALL_LANG, {AC_ZA, S_HALANT, C_RA, 0x0}, {L_JRA_N, 0x0}},      /* new */
    /* za + halant + ra + halant -> zra + halant or za + subscript RA + halant */
    /* START FARHAD PMT 20050211 */
    {1, 4, 3, MMI_ALL_LANG, {AC_ZA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_JA_N, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE DDDHA_Tbl[] = 
{
    /* dddha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_DDDHA, 0x0}, {AC_DDDHA, 0x0}},
    /* dddha + halant -> dddha+ halant */
    {1, 2, 2, MMI_ALL_LANG, {AC_DDDHA, S_HALANT, 0x0}, {AC_DDDHA, S_HALANT, 0x0}},
    /* dddha + halant + ra -> dddha + subscript ra(special represenatio */
    /* {1,3,2,MMI_ALL_LANG,     {AC_DDDHA,S_HALANT,C_RA,0x0},                {AC_DDDHA,SUB_RA,0x0} } */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE RHA_Tbl[] = 
{
    /* rha + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_RHA, 0x0}, {AC_RHA, 0x0}},
    /* rha + halant -> rha + halant */
    {0, 2, 2, MMI_ALL_LANG, {AC_RHA, S_HALANT, 0x0}, {AC_RHA, S_HALANT, 0x0}},
    /* rha + halant + ra -> rha + subscript ra(special form) */
    /* {1,3,2,MMI_ALL_LANG,        {AC_RHA,S_HALANT,C_RA,0x0},                {AC_RHA,SUB_RA,0x0} } */
	/* PMT RAKESH END 20061006 */

};

const GLYPH_INFO_TABLE FA_Tbl[] = 
{
    /* fa +space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_FA, 0x0}, {AC_FA, 0x0}},
    /* fa + halant -> half form of fa */
    {1, 2, 1, MMI_ALL_LANG, {AC_FA, S_HALANT, 0x0}, {H_PHA_N, 0x0}},
    /* fa + halant + ra -> fra OR fa + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {AC_FA, S_HALANT, C_RA, 0x0}, {L_FRA_N, 0x0}},      /* new */
    /* START FARHAD PMT 20050211 */
    /* fa + halant + ra + halant -> half fa + ra + halant */
    {1, 4, 3, MMI_ALL_LANG, {AC_FA, S_HALANT, C_RA, S_HALANT, 0x0}, {H_PHA_N, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE YYA_Tbl[] = 
{
    /* yya + space */
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {AC_YYA, 0x0}, {AC_YYA, 0x0}},
    /* yya + halant -> half form of yya */
    {1, 2, 1, MMI_ALL_LANG, {AC_YYA, S_HALANT, 0x0}, {L_YA_N, 0x0}},
    /* yya + halant + ra -> yya + subscript RA */
    {1, 3, 1, MMI_ALL_LANG, {AC_YYA, S_HALANT, C_RA, 0x0}, {L_YRA_N, 0x0}},     /* Q *//* new */
    /* START FARHAD PMT 20050211 */
    /* yya + halant + ra + halant -> half yya+ RA + halant */
    {1, 4, 3, MMI_ALL_LANG, {AC_YYA, S_HALANT, C_RA, S_HALANT, 0x0}, {L_YA_N, C_RA, S_HALANT, 0x0}}
    /* END FARHAD PMT 20050211 */
	/* PMT RAKESH END 20061006 */
};

              /* VARIOUS SIGNS TABLES */
const GLYPH_INFO_TABLE CHNDR_BINDU_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {S_CHANDRA_BINDU, 0x0}, {S_CHANDRA_BINDU, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE BINDU_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {S_BINDU, 0x0}, {S_BINDU, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE VISARGA_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {S_VISARGA, 0x0}, {S_VISARGA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NUKTA_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {S_NUKTA, 0x0}, {S_NUKTA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE OM_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {S_OM, 0x0}, {S_OM, 0x0}}
	/* PMT RAKESH END 20061006 */
};

                        /* INDEPENDENT VOWEL'S TABLE */

const GLYPH_INFO_TABLE NSA_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NIV_A, 0x0}, {NIV_A, 0x0}}
	/* PMT RAKESH END 20061006 */
};
const GLYPH_INFO_TABLE A_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_A, 0x0}, {IV_A, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE AA_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_AA, 0x0}, {IV_AA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE I_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_I, 0x0}, {IV_I, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE II_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_II, 0x0}, {IV_II, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE U_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_U, 0x0}, {IV_U, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE UU_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_UU, 0x0}, {IV_UU, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE R_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_R, 0x0}, {IV_R, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NVL_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NIV_L, 0x0}, {NIV_L, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NCE_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NIV_CE, 0x0}, {NIV_CE, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NSE_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NIV_SE, 0x0}, {NIV_SE, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE E_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_E, 0x0}, {IV_E, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE AI_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_AI, 0x0}, {IV_AI, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NCO_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NIV_CO, 0x0}, {NIV_CO, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NCSO_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NIV_SO, 0x0}, {NIV_SO, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE O_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_O, 0x0}, {IV_O, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE AU_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {IV_AU, 0x0}, {IV_AU, 0x0}}
	/* PMT RAKESH END 20061006 */
};

                      /* DEPENDENT VOWEL SIGN/MATRAS TABLES */

const GLYPH_INFO_TABLE MAA_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_AA, 0x0}, {DV_AA, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {DV_AA, S_CHANDRA_BINDU, 0x0}, {L_NCAND, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {DV_AA, S_BINDU, 0x0}, {L_NBINDU, 0x0}},
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MI_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_I, 0x0}, {DV_I, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {DV_I, C_RA, S_HALANT, 0x0}, {L_IRAHAL, 0x0}},
    {1, 4, 1, MMI_ALL_LANG, {DV_I, C_RA, S_HALANT, S_BINDU, 0x0}, {L_IRAHALB, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MII_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_II, 0x0}, {DV_II, 0x0}},
    {1, 2, 1, MMI_ALL_LANG, {DV_II, S_BINDU, 0x0}, {L_MII, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {DV_II, C_RA, S_HALANT, 0x0}, {L_MIIRA, 0x0}},
    {1, 4, 1, MMI_ALL_LANG, {DV_II, C_RA, S_HALANT, S_BINDU, 0x0}, {L_IIRAHALB, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MU_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_U, 0x0}, {DV_U, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MUU_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_UU, 0x0}, {DV_UU, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MR_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_R, 0x0}, {DV_R, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MC_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_CE, 0x0}, {DV_CE, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {DV_CE, S_BINDU, 0x0}, {S_CHANDRA_BINDU, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE ME_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_E, 0x0}, {DV_E, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {DV_E, S_BINDU, 0x0}, {L_ME, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {DV_E, C_RA, S_HALANT, 0x0}, {L_DVERA, 0x0}},
    {1, 4, 1, MMI_ALL_LANG, {DV_E, C_RA, S_HALANT, S_BINDU, 0x0}, {L_DVEBINRA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MAI_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_AI, 0x0}, {DV_AI, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {DV_AI, S_BINDU, 0x0}, {L_MAI, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {DV_AI, C_RA, S_HALANT, 0x0}, {L_DVAIRA, 0x0}},
    {1, 4, 1, MMI_ALL_LANG, {DV_AI, C_RA, S_HALANT, S_BINDU, 0x0}, {L_DVAIBINRA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MCO_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NDV_CO, 0x0}, {NDV_CO, 0x0}},
    {1, 2, 1, MMI_ALL_LANG, {NDV_CO, S_BINDU, 0x0}, {L_NCAND, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MO_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_O, 0x0}, {DV_O, 0x0}},
    {1, 2, 1, MMI_ALL_LANG, {DV_O, S_BINDU, 0x0}, {L_MO, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {DV_O, C_RA, S_HALANT, 0x0}, {L_DVORA, 0x0}},
    {1, 4, 1, MMI_ALL_LANG, {DV_O, C_RA, S_HALANT, S_BINDU, 0x0}, {L_DVOBINRA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE MAU_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {DV_AU, 0x0}, {DV_AU, 0x0}},
    {1, 2, 1, MMI_ALL_LANG, {DV_AU, S_BINDU, 0x0}, {L_MAU, 0x0}},
    {1, 3, 1, MMI_ALL_LANG, {DV_AU, C_RA, S_HALANT, 0x0}, {L_DVAURA, 0x0}},
    {1, 4, 1, MMI_ALL_LANG, {DV_AU, C_RA, S_HALANT, S_BINDU, 0x0}, {L_DVAUBINRA, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE HAL_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {S_HALANT, 0x0}, {S_HALANT, 0x0}}
	/* PMT RAKESH END 20061006 */
};

/* vj */
const GLYPH_INFO_TABLE NGD_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NG_D, 0x0}, {NG_D, 0x0}}
	/* PMT RAKESH END 20061006 */
};

/* START VIJAY PMT 20050728 */
const GLYPH_INFO_TABLE NGDD_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {NG_DD, 0x0}, {NG_DD, 0x0}}
	/* PMT RAKESH END 20061006 */
};
const GLYPH_INFO_TABLE NABBR_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {S_ABBR, 0x0}, {S_ABBR, 0x0}}
	/* PMT RAKESH END 20061006 */
};

   //END VIJAY PMT 20050728
   //vj

                       /* NUMERALS TABLE */
const GLYPH_INFO_TABLE ZERO_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_ZERO, 0x0}, {D_ZERO, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE ONE_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_ONE, 0x0}, {D_ONE, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE TWO_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_TWO, 0x0}, {D_TWO, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE THREE_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_THREE, 0x0}, {D_THREE, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE FOUR_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_FOUR, 0x0}, {D_FOUR, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE FIVE_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_FIVE, 0x0}, {D_FIVE, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE SIX_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_SIX, 0x0}, {D_SIX, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE SEVEN_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_SEVEN, 0x0}, {D_SEVEN, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE EIGHT_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_EIGHT, 0x0}, {D_EIGHT, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const GLYPH_INFO_TABLE NINE_Tbl[] = 
{
	/* PMT RAKESH START 20061006 */
    {0, 1, 1, MMI_ALL_LANG, {D_NINE, 0x0}, {D_NINE, 0x0}}
	/* PMT RAKESH END 20061006 */
};

const MAIN_TABLE hfDvngTbl[] = 
{

    /* NULL for devanagari sign Short A */
    {CHNDR_BINDU_Tbl, sizeof(CHNDR_BINDU_Tbl) / sizeof(CHNDR_BINDU_Tbl[0]), 1}
    ,
    {BINDU_Tbl, sizeof(BINDU_Tbl) / sizeof(BINDU_Tbl[0]), 1}
    ,
    {VISARGA_Tbl, sizeof(VISARGA_Tbl) / sizeof(VISARGA_Tbl[0]), 1}
    ,
    /* INDEPENDENT VOWELS */
    /* NULL For Independent Vowel L,Chandra E,Short E,Chandra O,Short O */
    {NSA_Tbl, sizeof(NSA_Tbl) / sizeof(NSA_Tbl[0]), 1}
    ,
    {A_Tbl, sizeof(A_Tbl) / sizeof(A_Tbl[0]), 1}
    ,
    {AA_Tbl, sizeof(AA_Tbl) / sizeof(AA_Tbl[0]), 1}
    ,
    {I_Tbl, sizeof(I_Tbl) / sizeof(I_Tbl[0]), 1}
    ,
    {II_Tbl, sizeof(II_Tbl) / sizeof(II_Tbl[0]), 1}
    ,
    {U_Tbl, sizeof(U_Tbl) / sizeof(U_Tbl[0]), 1}
    ,
    {UU_Tbl, sizeof(UU_Tbl) / sizeof(UU_Tbl[0]), 1}
    ,
    {R_Tbl, sizeof(R_Tbl) / sizeof(R_Tbl[0]), 1}
    ,
    {NVL_Tbl, sizeof(NVL_Tbl) / sizeof(NVL_Tbl[0]), 1}
    ,
    {NCE_Tbl, sizeof(NCE_Tbl) / sizeof(NCE_Tbl[0]), 1}
    ,
    {NSE_Tbl, sizeof(NSE_Tbl) / sizeof(NSE_Tbl[0]), 1}
    ,
    {E_Tbl, sizeof(E_Tbl) / sizeof(E_Tbl[0]), 1}
    ,
    {AI_Tbl, sizeof(AI_Tbl) / sizeof(AI_Tbl[0]), 1}
    ,
    {NCO_Tbl, sizeof(NCO_Tbl) / sizeof(NCO_Tbl[0]), 1}
    ,
    {NCSO_Tbl, sizeof(NCSO_Tbl) / sizeof(NCSO_Tbl[0]), 1}
    ,
    {O_Tbl, sizeof(O_Tbl) / sizeof(O_Tbl[0]), 1}
    ,
    {AU_Tbl, sizeof(AU_Tbl) / sizeof(AU_Tbl[0]), 1}
    ,

    /* Consonants */
    {KA_Tbl, sizeof(KA_Tbl) / sizeof(KA_Tbl[0]), 4}
    ,
    {KHA_Tbl, sizeof(KHA_Tbl) / sizeof(KHA_Tbl[0]), 4}
    ,
    {GA_Tbl, sizeof(GA_Tbl) / sizeof(GA_Tbl[0]), 4}
    ,
    {GHA_Tbl, sizeof(GHA_Tbl) / sizeof(GHA_Tbl[0]), 4}
    ,
    {NGA_Tbl, sizeof(NGA_Tbl) / sizeof(NGA_Tbl[0]), 3}
    ,
    {CHA_Tbl, sizeof(CHA_Tbl) / sizeof(CHA_Tbl[0]), 4}
    ,
    {CHHA_Tbl, sizeof(CHHA_Tbl) / sizeof(CHHA_Tbl[0]), 3}
    ,
    {JA_Tbl, sizeof(JA_Tbl) / sizeof(JA_Tbl[0]), 4}
    ,
    {JHA_Tbl, sizeof(JHA_Tbl) / sizeof(JHA_Tbl[0]), 4}
    ,
    {NYA_Tbl, sizeof(NYA_Tbl) / sizeof(NYA_Tbl[0]), 1}
    ,
    {TTA_Tbl, sizeof(TTA_Tbl) / sizeof(TTA_Tbl[0]), 3}
    ,
    {TTHA_Tbl, sizeof(TTHA_Tbl) / sizeof(TTHA_Tbl[0]), 3}
    ,
    {DDA_Tbl, sizeof(DDA_Tbl) / sizeof(DDA_Tbl[0]), 3}
    ,
    {DDHA_Tbl, sizeof(DDHA_Tbl) / sizeof(DDHA_Tbl[0]), 4}
    ,
    {NNA_Tbl, sizeof(NNA_Tbl) / sizeof(NNA_Tbl[0]), 3}
    ,
    {TA_Tbl, sizeof(TA_Tbl) / sizeof(TA_Tbl[0]), 4}
    ,
    {THA_Tbl, sizeof(THA_Tbl) / sizeof(THA_Tbl[0]), 4}
    ,
    {DA_Tbl, sizeof(DA_Tbl) / sizeof(DA_Tbl[0]), 4}
    ,
    {DHA_Tbl, sizeof(DHA_Tbl) / sizeof(DHA_Tbl[0]), 4}
    ,
    {NA_Tbl, sizeof(NA_Tbl) / sizeof(NA_Tbl[0]), 4}
    ,
    {NNNA_Tbl, sizeof(NNNA_Tbl) / sizeof(NNNA_Tbl[0]), 4}
    ,
    {PA_Tbl, sizeof(PA_Tbl) / sizeof(PA_Tbl[0]), 4}
    ,
    {PHA_Tbl, sizeof(PHA_Tbl) / sizeof(PHA_Tbl[0]), 5}
    ,
    {BA_Tbl, sizeof(BA_Tbl) / sizeof(BA_Tbl[0]), 4}
    ,
    {BHA_Tbl, sizeof(BHA_Tbl) / sizeof(BHA_Tbl[0]), 4}
    ,
    {MA_Tbl, sizeof(MA_Tbl) / sizeof(MA_Tbl[0]), 4}
    ,
    {YA_Tbl, sizeof(YA_Tbl) / sizeof(YA_Tbl[0]), 4}
    ,
    {RA_Tbl, sizeof(RA_Tbl) / sizeof(RA_Tbl[0]), 2}
    ,
    {RRA_Tbl, sizeof(RRA_Tbl) / sizeof(RRA_Tbl[0]), 2}
    ,
    {LA_Tbl, sizeof(LA_Tbl) / sizeof(LA_Tbl[0]), 3}
    ,
    {LLA_Tbl, sizeof(LLA_Tbl) / sizeof(LLA_Tbl[0]), 3}
    ,
    {LLLA_Tbl, sizeof(LLLA_Tbl) / sizeof(LLLA_Tbl[0]), 3}
    ,
    {VA_Tbl, sizeof(VA_Tbl) / sizeof(VA_Tbl[0]), 4}
    ,
    {SHA_Tbl, sizeof(SHA_Tbl) / sizeof(SHA_Tbl[0]), 4}
    ,
    {SSA_Tbl, sizeof(SSA_Tbl) / sizeof(SSA_Tbl[0]), 3}
    ,
    {SA_Tbl, sizeof(SA_Tbl) / sizeof(SA_Tbl[0]), 4}
    ,
    {HA_Tbl, sizeof(HA_Tbl) / sizeof(HA_Tbl[0]), 4}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,

    /* Various Signs */
    /* NULL for Avagraha */
    {NUKTA_Tbl, sizeof(NUKTA_Tbl), 1}
    ,
    {NULL, 0, 0}
    ,

    /* Dependent Vowel Signs */
    /* Null for RR,Short E,Chandra O,Short O */
    {MAA_Tbl, sizeof(MAA_Tbl) / sizeof(MAA_Tbl[0]), 1}
    ,
    {MI_Tbl, sizeof(MI_Tbl) / sizeof(MI_Tbl[0]), 1}
    ,
    {MII_Tbl, sizeof(MII_Tbl) / sizeof(MII_Tbl[0]), 2}
    ,
    {MU_Tbl, sizeof(MU_Tbl) / sizeof(MU_Tbl[0]), 1}
    ,
    {MUU_Tbl, sizeof(MUU_Tbl) / sizeof(MUU_Tbl[0]), 1}
    ,
    {MR_Tbl, sizeof(MR_Tbl) / sizeof(MR_Tbl[0]), 1}
    ,
    {NULL, 0, 0}
    ,
    {MC_Tbl, sizeof(MC_Tbl) / sizeof(MC_Tbl[0]), 1}
    ,
    {NULL, 0, 0}
    ,
    {ME_Tbl, sizeof(ME_Tbl) / sizeof(ME_Tbl[0]), 2}
    ,
    {MAI_Tbl, sizeof(MAI_Tbl) / sizeof(MAI_Tbl[0]), 1}
    ,
    {MCO_Tbl, sizeof(MCO_Tbl) / sizeof(MCO_Tbl[0]), 1}
    ,
    {NULL, 0, 0}
    ,
    {MO_Tbl, sizeof(MO_Tbl) / sizeof(MO_Tbl[0]), 2}
    ,
    {MAU_Tbl, sizeof(MAU_Tbl) / sizeof(MAU_Tbl[0]), 1}
    ,

    /* Various Signs */
    {HAL_Tbl, sizeof(HAL_Tbl) / sizeof(HAL_Tbl[0]), 1}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {OM_Tbl, sizeof(OM_Tbl) / sizeof(OM_Tbl[0]), 1}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    /* Additional Consonant */
    {QA_Tbl, sizeof(QA_Tbl) / sizeof(QA_Tbl[0]), 1}
    ,
    {KHHA_Tbl, sizeof(KHHA_Tbl) / sizeof(GHHA_Tbl[0]), 1}
    ,
    {GHHA_Tbl, sizeof(GHHA_Tbl) / sizeof(GHHA_Tbl[0]), 1}
    ,
    {ZA_Tbl, sizeof(ZA_Tbl) / sizeof(ZA_Tbl[0]), 1}
    ,
    {DDDHA_Tbl, sizeof(DDDHA_Tbl) / sizeof(DDDHA_Tbl[0]), 1}
    ,
    {RHA_Tbl, sizeof(RHA_Tbl) / sizeof(RHA_Tbl[0]), 1}
    ,
    {FA_Tbl, sizeof(FA_Tbl) / sizeof(FA_Tbl[0]), 1}
    ,
    {YYA_Tbl, sizeof(YYA_Tbl) / sizeof(YYA_Tbl[0]), 1}
    ,

    /* Generic Addition,used in Sanskrit only */
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NGD_Tbl, sizeof(NGD_Tbl) / sizeof(NGD_Tbl[0]), 1}
    ,   /* vj */
    /* START VIJAY PMT 20050728 */
    {NGDD_Tbl, sizeof(NGDD_Tbl) / sizeof(NGDD_Tbl[0]), 1}
    ,
    /* END VIJAY PMT 20050728 */
    {ZERO_Tbl, sizeof(ZERO_Tbl) / sizeof(ZERO_Tbl[0]), 1}
    ,
    {ONE_Tbl, sizeof(ONE_Tbl) / sizeof(ONE_Tbl[0]), 1}
    ,
    {TWO_Tbl, sizeof(TWO_Tbl) / sizeof(TWO_Tbl[0]), 1}
    ,
    {THREE_Tbl, sizeof(THREE_Tbl) / sizeof(THREE_Tbl[0]), 1}
    ,
    {FOUR_Tbl, sizeof(FOUR_Tbl) / sizeof(FOUR_Tbl[0]), 1}
    ,
    {FIVE_Tbl, sizeof(FIVE_Tbl) / sizeof(FIVE_Tbl[0]), 1}
    ,
    {SIX_Tbl, sizeof(SIX_Tbl) / sizeof(SIX_Tbl[0]), 1}
    ,
    {SEVEN_Tbl, sizeof(SEVEN_Tbl) / sizeof(SEVEN_Tbl[0]), 1}
    ,
    {EIGHT_Tbl, sizeof(EIGHT_Tbl) / sizeof(EIGHT_Tbl[0]), 1}
    ,
    {NINE_Tbl, sizeof(NINE_Tbl) / sizeof(NINE_Tbl[0]), 1}
    ,
    /* START VIJAY PMT 20050728 */
    {NABBR_Tbl, sizeof(NABBR_Tbl) / sizeof(NABBR_Tbl[0]), 1}
    /* END VIJAY PMT 20050728 */
};

const U8 g_hindi_character_type_array[] = 
{
    HF_INVALID,
    SIGN,       /* S_CHANDRA_BINDU=0x0901, */
    SIGN,       /* S_BINDU=0x902, */
    SIGN,       /* S_VISARGA=0x903, */
    INDVOW,     /* NIV_A=0x904, */
    INDVOW,     /* IV_A=0x905, */
    INDVOW,     /* IV_AA=0x906, */
    INDVOW,     /* IV_I=0x907, */
    INDVOW,     /* IV_II=0x908, */
    INDVOW,     /* IV_U=0x909, */
    INDVOW,     /* IV_UU=0x90a, */
    INDVOW,     /* IV_R=0x90b, */
    INDVOW,     /* NIV_L=0x90c, */
    INDVOW,     /* NIV_CE=0x90d, */
    INDVOW,     /* NIV_SE=0x90e, */
    INDVOW,     /* IV_E=0x90f, */
    INDVOW,     /* IV_AI=0x910, */
    INDVOW,     /* NIV_CO=0x911, */
    INDVOW,     /* NIV_SO=0x912, */
    INDVOW,     /* IV_O=0x913, */
    INDVOW,     /* IV_AU=0x914, */
    CON,        /* C_KA=0x915, */
    CON,        /* C_KHA=0x916, */
    CON,        /* C_GA=0x917, */
    CON,        /* C_GHA=0x918, */
    CON,        /* C_NGA=0x919, */
    CON,        /* C_CHA=0x91a, */
    CON,        /* C_CHHA=0x91b, */
    CON,        /* C_JA=0x91c, */
    CON,        /* C_JHA=0x91d, */
    CON,        /* C_NYA=0x91e, */
    CON,        /* C_TTA=0x91f, */
    CON,        /* C_TTHA=0x920, */
    CON,        /* C_DDA=0x921, */
    CON,        /* C_DDHA=0x922, */
    CON,        /* C_NNA=0x923, */
    CON,        /* C_TA=0x924, */
    CON,        /* C_THA=0x925, */
    CON,        /* C_DA=0x926, */
    CON,        /* C_DHA=0x927, */
    CON,        /* C_NA=0x928, */
    CON,        /* C_NNNA=0x929, */
    CON,        /* C_PA=0x92a, */
    CON,        /* C_PHA=0x92b, */
    CON,        /* C_BA=0x92c, */
    CON,        /* C_BHA=0x92d, */
    CON,        /* C_MA=0x92e, */
    CON,        /* C_YA=0x92f, */
    CON,        /* C_RA=0x930, */
    CON,        /* C_RRA=0x931, */
    CON,        /* C_LA=0x932, */
    CON,        /* C_LLA=0x933, */
    CON,        /* C_LLLA=0x934, */
    CON,        /* C_VA=0x935, */
    CON,        /* C_SHA=0x936, */
    CON,        /* C_SSA=0x937, */
    CON,        /* C_SA=0x938, */
    CON,        /* C_HA=0x939, */
    HF_INVALID, /* N_BLANK1=0x93a, */
    HF_INVALID, /* N_BLANK2=0x93b, */
    SIGN,       /* S_NUKTA=0x93c, */
    SIGN,       /* NS_AVAGRAHA=0x93d, */
    DEPVOW,     /* DV_AA=0x93e, */
    DEPVOW,     /* DV_I=0x93F, */
    DEPVOW,     /* DV_II=0x940, */
    DEPVOW,     /* DV_U=0x941, */
    DEPVOW,     /* DV_UU=0x942, */
    DEPVOW,     /* DV_R=0x943, */
    DEPVOW,     /* NDV_RR=0x944, */
    DEPVOW,     /* DV_CE=0x945, */
    DEPVOW,     /* NDV_E=0x946, */
    DEPVOW,     /* DV_E=0x947, */
    DEPVOW,     /* DV_AI=0x948, */
    DEPVOW,     /* NDV_CO=0x949, */
    DEPVOW,     /* NDV_O=0x94a, */
    DEPVOW,     /* DV_O=0x94b, */
    DEPVOW,     /* DV_AU=0x94c, */
    HALANT,     /* S_HALANT=0x94d, */
    HF_INVALID, /* NS_RESERVED1=0x94e, */
    HF_INVALID, /* NS_RESERVED2=0x94f, */
    /* START VIJAY PMT 20050728..changed from SIGN */
    INDVOW,     /* S_OM=0x950, */
    /* END VIJAY PMT 20050728 */
    SIGN,       /* NS_UDATTA=0x951, */
    SIGN,       /* NS_ANUDATTA=0x952, */
    SIGN,       /* NS_GACCENT=0x953, */
    SIGN,       /* NS_AACCENT=0x954, */
    HF_INVALID, /* N_BLANK5=0x955, */
    HF_INVALID, /* N_BLANK6=0x956, */
    HF_INVALID, /* N_BLANK7=0x957, */
    CON,        /* AC_QA=0x958, */
    CON,        /* AC_KHHA=0x959, */
    CON,        /* AC_GHHA=0x95a, */
    CON,        /* AC_ZA=0x95b, */
    CON,        /* AC_DDDHA=0x95c, */
    CON,        /* AC_RHA=0x95d, */
    CON,        /* AC_FA=0x95e, */
    CON,        /* AC_YYA=0x95f, */
    HF_INVALID, /* NG_RR=0x960, */
    HF_INVALID, /* NG_LL=0x961, */
    HF_INVALID, /* NG_L=0x962, */
    HF_INVALID, /* NG_VLL=0x963, */
    /* START VIJAY PMT 20050728 */
    INDVOW,     /* NG_D=0x964, */
    INDVOW,     /* NG_DD=0x965, */
    /* END VIJAY PMT 20050728 */
    NUM,        /* D_ZERO=0x966, */
    NUM,        /* D_ONE=0x967, */
    NUM,        /* D_TWO=0x968, */
    NUM,        /* D_THREE=0x969, */
    NUM,        /* D_FOUR=0x96a, */
    NUM,        /* D_FIVE=0x96b, */
    NUM,        /* D_SIX=0x96c, */
    NUM,        /* D_SEVEN=0x96d, */
    NUM,        /* D_EIGHT=0x96e, */
    NUM,        /* D_NINE=0x96f, */
    /* START VIJAY PMT 20050728..changed from SIGN */
    INDVOW      /* S_ABBR=0x970 */
        /* END   PMT 20050728 */
};

const U8 g_hindi_character_sign_array[] = 
{
    FALSE,
    TRUE,   /* S_CHANDRA_BINDU=0x0901, */
    TRUE,   /* S_BINDU=0x902, */
    /* PMT START MAUI_00223197 */
    TRUE,   /* S_VISARGA=0x903, */
    /* PMT END MAUI_00223197 */
    FALSE,  /* NIV_A=0x904, */
    FALSE,  /* IV_A=0x905, */
    FALSE,  /* IV_AA=0x906, */
    FALSE,  /* IV_I=0x907, */
    FALSE,  /* IV_II=0x908, */
    FALSE,  /* IV_U=0x909, */
    FALSE,  /* IV_UU=0x90a, */
    FALSE,  /* IV_R=0x90b, */
    FALSE,  /* NIV_L=0x90c, */
    FALSE,  /* NIV_CE=0x90d, */
    FALSE,  /* NIV_SE=0x90e, */
    FALSE,  /* IV_E=0x90f, */
    FALSE,  /* IV_AI=0x910, */
    FALSE,  /* NIV_CO=0x911, */
    FALSE,  /* NIV_SO=0x912, */
    FALSE,  /* IV_O=0x913, */
    FALSE,  /* IV_AU=0x914, */
    FALSE,  /* C_KA=0x915, */
    FALSE,  /* C_KHA=0x916, */
    FALSE,  /* C_GA=0x917, */
    FALSE,  /* C_GHA=0x918, */
    FALSE,  /* C_NGA=0x919, */
    FALSE,  /* C_CHA=0x91a, */
    FALSE,  /* C_CHHA=0x91b, */
    FALSE,  /* C_JA=0x91c, */
    FALSE,  /* C_JHA=0x91d, */
    FALSE,  /* C_NYA=0x91e, */
    FALSE,  /* C_TTA=0x91f, */
    FALSE,  /* C_TTHA=0x920, */
    FALSE,  /* C_DDA=0x921, */
    FALSE,  /* C_DDHA=0x922, */
    FALSE,  /* C_NNA=0x923, */
    FALSE,  /* C_TA=0x924, */
    FALSE,  /* C_THA=0x925, */
    FALSE,  /* C_DA=0x926, */
    FALSE,  /* C_DHA=0x927, */
    FALSE,  /* C_NA=0x928, */
    FALSE,  /* C_NNNA=0x929, */
    FALSE,  /* C_PA=0x92a, */
    FALSE,  /* C_PHA=0x92b, */
    FALSE,  /* C_BA=0x92c, */
    FALSE,  /* C_BHA=0x92d, */
    FALSE,  /* C_MA=0x92e, */
    FALSE,  /* C_YA=0x92f, */
    FALSE,  /* C_RA=0x930, */
    FALSE,  /* C_RRA=0x931, */
    FALSE,  /* C_LA=0x932, */
    FALSE,  /* C_LLA=0x933, */
    FALSE,  /* C_LLLA=0x934, */
    FALSE,  /* C_VA=0x935, */
    FALSE,  /* C_SHA=0x936, */
    FALSE,  /* C_SSA=0x937, */
    FALSE,  /* C_SA=0x938, */
    FALSE,  /* C_HA=0x939, */
    FALSE,  /* N_BLANK1=0x93a, */
    FALSE,  /* N_BLANK2=0x93b, */
    TRUE,   /* S_NUKTA=0x93c, */
    FALSE,  /* NS_AVAGRAHA=0x93d, */
    FALSE,  /* DV_AA=0x93e, */
    FALSE,  /* DV_I=0x93F, */
    FALSE,  /* DV_II=0x940, */
    TRUE,   /* DV_U=0x941, */
    TRUE,   /* DV_UU=0x942, */
    TRUE,   /* DV_R=0x943, */
    FALSE,  /* NDV_RR=0x944, */
    TRUE,   /* DV_CE=0x945, */
    FALSE,  /* NDV_E=0x946, */
    TRUE,   /* DV_E=0x947, */
    TRUE,   /* DV_AI=0x948, */
    FALSE,  /* NDV_CO=0x949, */
    FALSE,  /* NDV_O=0x94a, */
    FALSE,  /* DV_O=0x94b, */
    FALSE,  /* DV_AU=0x94c, */
    TRUE,   /* S_HALANT=0x94d, */
    FALSE,  /* NS_RESERVED1=0x94e, */
    FALSE,  /* NS_RESERVED2=0x94f, */
    FALSE,  /* S_OM=0x950, */
    FALSE,  /* NS_UDATTA=0x951, */
    FALSE,  /* NS_ANUDATTA=0x952, */
    FALSE,  /* NS_GACCENT=0x953, */
    FALSE,  /* NS_AACCENT=0x954, */
    FALSE,  /* N_BLANK5=0x955, */
    FALSE,  /* N_BLANK6=0x956, */
    FALSE,  /* N_BLANK7=0x957, */
    FALSE,  /* AC_QA=0x958, */
    FALSE,  /* AC_KHHA=0x959, */
    FALSE,  /* AC_GHHA=0x95a, */
    FALSE,  /* AC_ZA=0x95b, */
    FALSE,  /* AC_DDDHA=0x95c, */
    FALSE,  /* AC_RHA=0x95d, */
    FALSE,  /* AC_FA=0x95e, */
    FALSE,  /* AC_YYA=0x95f, */
    FALSE,  /* NG_RR=0x960, */
    FALSE,  /* NG_LL=0x961, */
    FALSE,  /* NG_L=0x962, */
    FALSE,  /* NG_VLL=0x963, */
    FALSE,  /* NG_D=0x964, */
    FALSE,  /* NG_DD=0x965, */
    FALSE,  /* D_ZERO=0x966, */
    FALSE,  /* D_ONE=0x967, */
    FALSE,  /* D_TWO=0x968, */
    FALSE,  /* D_THREE=0x969, */
    FALSE,  /* D_FOUR=0x96a, */
    FALSE,  /* D_FIVE=0x96b, */
    FALSE,  /* D_SIX=0x96c, */
    FALSE,  /* D_SEVEN=0x96d, */
    FALSE,  /* D_EIGHT=0x96e, */
    FALSE,  /* D_NINE=0x96f, */
    FALSE   /* S_ABBR=0x970 */
};

const U8 g_hindi_character_extended_sign_array[] = 
{
    FALSE,  /* 59648 */
    FALSE,  /* 59649 */
    FALSE,  /* 59650 */
    FALSE,  /* 59651 */
    FALSE,  /* 59652 */
    FALSE,  /* 59653 */
    FALSE,  /* 59654 */
    FALSE,  /* 59655 */
    FALSE,  /* 59656 */
    FALSE,  /* 59657 */
    FALSE,  /* 59658 */
    FALSE,  /* 59659 */
    FALSE,  /* 59660 */
    FALSE,  /* 59661 */
    FALSE,  /* 59662 */
    FALSE,  /* 59663 */
    FALSE,  /* 59664 */
    FALSE,  /* 59665 */
    FALSE,  /* 59666 */
    FALSE,  /* 59667 */
    FALSE,  /* 59668 */
    FALSE,  /* 59669 */
    FALSE,  /* 59670 */
    FALSE,  /* 59671 */
    FALSE,  /* 59672 */
    FALSE,  /* 59673 */
    FALSE,  /* 59674 */
    FALSE,  /* 59675 */
    FALSE,  /* 59676 */
    FALSE,  /* 59677 */
    FALSE,  /* 59678 */
    FALSE,  /* 59679 */
    FALSE,  /* 59680 */
    FALSE,  /* 59681 */
    FALSE,  /* 59682 */
    FALSE,  /* 59683 */
    FALSE,  /* 59684 */
    FALSE,  /* 59685 */
    FALSE,  /* 59686 */
    FALSE,  /* 59687 */
    FALSE,  /* 59688 */
    FALSE,  /* 59689 */
    FALSE,  /* 59690 */
    FALSE,  /* 59691 */
    FALSE,  /* 59692 */
    FALSE,  /* 59693 */
    FALSE,  /* 59694 */
    FALSE,  /* 59695 */
    FALSE,  /* 59696 */
    FALSE,  /* 59697 */
    FALSE,  /* 59698 */
    FALSE,  /* 59699 */
    FALSE,  /* 59700 */
    FALSE,  /* 59701 */
    FALSE,  /* 59702 */
    FALSE,  /* 59703 */
    FALSE,  /* 59704 */
    FALSE,  /* 59705 */
    FALSE,  /* 59706 */
    FALSE,  /* 59707 */
    FALSE,  /* 59708 */
    FALSE,  /* 59709 */
    FALSE,  /* 59710 */
    FALSE,  /* 59711 */
    FALSE,  /* 59712 */
    FALSE,  /* 59713 */
    FALSE,  /* 59714 */
    FALSE,  /* 59715 */
    FALSE,  /* 59716 */
    FALSE,  /* 59717 */
    FALSE,  /* 59718 */
    FALSE,  /* 59719 */
    FALSE,  /* 59720 */
    FALSE,  /* 59721 */
    FALSE,  /* 59722 */
    FALSE,  /* 59723 */
    FALSE,  /* 59724 */
    FALSE,  /* 59725 */
    FALSE,  /* 59726 */
    FALSE,  /* 59727 */
    FALSE,  /* 59728 */
    FALSE,  /* 59729 */
    FALSE,  /* 59730 */
    FALSE,  /* 59731 */
    FALSE,  /* 59732 */
    FALSE,  /* 59733 */
    FALSE,  /* 59734 */
    FALSE,  /* 59735 */
    FALSE,  /* 59736 */
    FALSE,  /* 59737 */
    FALSE,  /* 59738 */
    FALSE,  /* 59739 */
    FALSE,  /* 59740 */
    FALSE,  /* 59741 */
    FALSE,  /* 59742 */
    FALSE,  /* 59743 */
    FALSE,  /* 59744 */
    FALSE,  /* 59745 */
    FALSE,  /* 59746 */
    FALSE,  /* 59747 */
    FALSE,  /* 59748 */
    FALSE,  /* 59749 */
    FALSE,  /* 59750 */
    FALSE,  /* 59751 */
    FALSE,  /* 59752 */
    FALSE,  /* 59753 */
    FALSE,  /* 59754 */
    FALSE,  /* 59755 */
    FALSE,  /* 59756 */
    FALSE,  /* 59757 */
    FALSE,  /* 59758 */
    FALSE,  /* 59759 */
    FALSE,  /* 59760 */
    FALSE,  /* 59761 */
    FALSE,  /* 59762 */
    FALSE,  /* 59763 */
    FALSE,  /* 59764 */
    FALSE,  /* 59765 */
    FALSE,  /* 59766 */
    FALSE,  /* 59767 */
    FALSE,  /* 59768 */
    FALSE,  /* 59769 */
    FALSE,  /* 59770 */
    TRUE,   /* 59771 */
    FALSE,  /* 59772 */
    FALSE,  /* 59773 */
    TRUE,   /* 59774 */
    TRUE,   /* 59775 */
    FALSE,  /* 59776 */
    FALSE,  /* 59777 */
    FALSE,  /* 59778 */
    FALSE,  /* 59779 */
    FALSE,  /* 59780 */
    FALSE,  /* 59781 */
    FALSE,  /* 59782 */
    FALSE,  /* 59783 */
    FALSE,  /* 59784 */
    FALSE,  /* 59785 */
    TRUE,   /* 59786 */
    TRUE,   /* 59787 */
    TRUE,   /* 59788 */
    TRUE,   /* 59789 */
    TRUE,   /* 59790 */
    TRUE,   /* 59791 */
    TRUE,   /* 59792 */
    FALSE,  /* 59793 */
    FALSE,  /* 59794 */
    FALSE,  /* 59795 */
    FALSE,  /* 59796 */
    FALSE,  /* 59797 */
    FALSE,  /* 59798 */
    FALSE,  /* 59799 */
    FALSE,  /* 59800 */
    FALSE,  /* 59801 */
    FALSE,  /* 59802 */
    FALSE,  /* 59803 */
    FALSE,  /* 59804 */
    FALSE,  /* 59805 */
    FALSE,  /* 59806 */
    FALSE,  /* 59807 */
    FALSE,  /* 59808 */
    FALSE,  /* 59809 */
    FALSE,  /* 59810 */
    FALSE,  /* 59811 */
    FALSE,  /* 59812 */
    FALSE,  /* 59813 */
    FALSE,  /* 59814 */
    FALSE,  /* 59815 */
    FALSE,  /* 59816 */
    FALSE,  /* 59817 */
    FALSE,  /* 59818 */
    FALSE,  /* 59819 */
    FALSE,  /* 59820 */
    FALSE,  /* 59821 */
    FALSE,  /* 59822 */
    FALSE,  /* 59823 */
    FALSE,  /* 59824 */
    FALSE,  /* 59825 */
    FALSE,  /* 59826 */
    FALSE,  /* 59827 */
    /* PMT RAKESH START 20061006 */
    FALSE,  /* 59828 */
    FALSE,  /* 59829 */
    FALSE,  /* 59830 */
    FALSE,  /* 59831 */
    FALSE,  /* 59832 */
    FALSE,  /* 59833 */
    FALSE,  /* 59834 */
    FALSE,  /* 59835 */
    FALSE,  /* 59836 */
    FALSE,  /* 59837 */
    FALSE,  /* 59838 */
    FALSE,  /* 59839 */
    FALSE,  /* 59840 */
    FALSE,  /* 59841 */
    /* PMT RAKESH END 20061006 */

};

/* conjunct ligatures */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

//U8 IdentifyCharacter( U16 ch )
  //{
   //  return hindi_character_array[UNI2HINDI(ch)];             
     /* if( HF_CON_RANGE(ch) )
        return CON;
        else if( HF_INDVOW_RANGE(ch) )
        return INDVOW;
        else if( HF_DEPVOW_RANGE(ch) )
        return DEPVOW;
        else if( HF_SIGN_RANGE(ch) )
        return SIGN;   
        else if( HF_NUMERAL_RANGE(ch) )
        return DIG;
        
        else return 0; */
/* } */
/*
 * MMI_BOOL hf_whether_ligature_range(U16 ligature )
 * {
 * switch(ligature)
 * {
 * case L_KSHA:
 * case L_GYA:
 * case L_TTTA:
 * case L_TRA:
 * case L_SHRA:
 * case L_KRA:
 * case L_JRA:
 * case L_ZRA:
 * case L_FRA:
 * case L_NFRA:
 * case L_PRA:
 * case L_SRA:
 * case L_RU:
 * case L_RUU:
 * case H_KA:
 * case H_KHA:
 * case H_GA:
 * case H_GHA:
 * case H_CHA:
 * case H_JA:
 * case H_JHA:
 * case H_NYA:
 * case H_ANNA:
 * case H_TA:
 * case H_THA:
 * case H_DHA:
 * case H_NA:
 * case H_NNNA:
 * case H_PA:
 * case H_PHA:
 * case H_BA:
 * case H_BHA:
 * case H_MA:
 * case H_YA:
 * case H_LA:
 * case H_LLA:
 * case H_LLLA:
 * case H_VA:
 * case H_SHA:
 * case H_SSA:
 * case H_SA:
 * case L_KKA:
 * case L_KTA:
 * case L_DYA:
 * case L_DVA:
 * case L_DDYA:
 * case L_TTTTA:
 * case L_TTHA:
 * case L_NNNA:
 * case L_HYA:
 * case H_KHSA:
 * case H_TTA:
 * case H_TRA:
 * case H_SHRA:
 * case L_HRA:
 * case H_EYLASH:
 * case SUP_RA:
 * case SUB_RA:
 * return TRUE;
 * default:
 * return FALSE;
 * }
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  hf_whether_conjunct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conjunct        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL hf_whether_conjunct(U16 conjunct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if( conjunct == L_KSHA  || conjunct == L_TRA || conjunct == L_SHRA || conjunct == L_TTTA)//cases of L_GYA,L_TTTA to be added */
    switch (conjunct)
    {
        case L_KSHA:
        case L_TRA:
        case L_SHRA:
        case L_TTTA:
        {
            return TRUE;
            break;
        }
        default:
            return FALSE;
    }
    //      return TRUE;
    //      else return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  hf_hindi_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  glyphoutput     [IN]        
 *  cluster         [IN]        
 *  nentry          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hf_hindi_rules(PU16 glyphoutput, PU16 cluster, S32 nentry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ch_index;
    MAIN_TABLE ind_table;
    const GLYPH_INFO_TABLE *char_table;
    S32 size;
    S32 noutglyph = 0;      /* no. of entries in output cluster to be given to renderer */
    S32 max_size;
    S32 matched = FALSE;
    S32 input = nentry;
    S32 tomatch = nentry;   /* nentries--no. of elements in the cluster */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (HF_HINDI_RANGE(*cluster))
    {
        /* START TARUN 20050108 */
        if (nentry == 1)
        {
            glyphoutput[nentry - 1] = *cluster;
            glyphoutput[nentry] = (U16) NULL;
            return nentry;
        }
        /* END TARUN 20050108 */
        while (nentry)
        {

            ch_index = UNI2HINDI(*cluster);         /* find the index of character in main table */
            ind_table = hfDvngTbl[ch_index - 1];    /* gets the individual charactr's table in main table */
            char_table = ind_table.glyphinfo;       /* holds the add. of individual character */
            size = ind_table.nsize;
            max_size = ind_table.maxInputGlyphSize;
            matched = FALSE;
            while (size)
            {
                size--;
                if (tomatch != char_table[size].nInputLen)  /* && max_size > nentry ) */
                {
                    continue;
                }
                /* PMT RAKESH START 20061006 */
                if ((char_table[size].rule_language) &&
                    (char_table[size].rule_language != hf_rules_current_set_language))
                {
                    continue;   
                }
                /* PMT RAKESH END 20061006 */
                else if (memcmp(char_table[size].Input_glyph, cluster, char_table[size].nInputLen * 2) == 0)
                {
                    //#if 0
                    //                                      if( *cluster == C_RA && input>=3 && (IdentifyCharacter(*(cluster-1)) == CON || IdentifyCharacter(*(cluster-1)) == DEPVOW) && *(cluster-1)!=DV_I )//change 01/12/04
                    //                                      {
                    //                                              memcpy( glyphoutput,char_table[size].Output_glyph,char_table[size].nOutputLen*2 );
                    //                                              glyphoutput[char_table[size].nOutputLen] = NULL;
                    //                                      }
                    //                                      else if( *cluster == C_RA && (*(cluster+1) == S_HALANT ))
                    //                                      {
                    //                                              memcpy( glyphoutput,char_table[size].Input_glyph,char_table[size].nInputLen*2 );
                    //                                              glyphoutput[char_table[size].nInputLen] = NULL;
                    //                                              glyphoutput++;
                    //                                      }
                    //                                      else if( (*(cluster+1) == S_HALANT) && (*(cluster+2)== NULL) )
                    //                                      {
                    //                                              memcpy( glyphoutput,char_table[size].Input_glyph,char_table[size].nInputLen*2 );
                    //                                              glyphoutput[char_table[size].nInputLen] = NULL;
                    //                                      }
                    //                                      else
                    //                                      {
                    //                                              memcpy( glyphoutput,char_table[size].Output_glyph,char_table[size].nOutputLen*2 );
                    //                                              glyphoutput[char_table[size].nOutputLen] = NULL;
                    //                                      }
                    //#endif//0
                    //#if 1
                    switch (*cluster)
                    {
                        case C_RA:
                        {
                            if (input >= 3 && (IdentifyCharacter(*(cluster - 1)) == CON || IdentifyCharacter(*(cluster - 1)) == DEPVOW) && *(cluster - 1) != DV_I)      /* change 01/12/04 */
                            {
                                memcpy(glyphoutput, char_table[size].Output_glyph, char_table[size].nOutputLen * 2);
                                glyphoutput[char_table[size].nOutputLen] = (U16) NULL;
                                break;
                            }
                            else if ((*(cluster + 1) == S_HALANT))
                            {
                                memcpy(glyphoutput, char_table[size].Input_glyph, char_table[size].nInputLen * 2);
                                glyphoutput[char_table[size].nInputLen] = (U16) NULL;
                                glyphoutput++;
                                break;
                            }
                            memcpy(glyphoutput, char_table[size].Output_glyph, char_table[size].nOutputLen * 2);
                            glyphoutput[char_table[size].nOutputLen] = (U16) NULL;
                            break;
                        }

                        default:
                        {
                            if ((*(cluster + 1) == S_HALANT) && (*(cluster + 2) == (U16) NULL))
                            {
                                memcpy(glyphoutput, char_table[size].Input_glyph, char_table[size].nInputLen * 2);
                                glyphoutput[char_table[size].nInputLen] = (U16) NULL;
                            }
                            else
                            {
                                memcpy(glyphoutput, char_table[size].Output_glyph, char_table[size].nOutputLen * 2);
                                glyphoutput[char_table[size].nOutputLen] = (U16) NULL;
                            }
                            break;
                        }
                    }
                    // #endif//1
                    nentry -= char_table[size].nInputLen;
                    glyphoutput += char_table[size].nOutputLen;
                    cluster += char_table[size].nInputLen;
                    noutglyph += char_table[size].nOutputLen;
                    matched = TRUE;
                    if (hf_whether_conjunct(*(glyphoutput - 1)) && *cluster == S_HALANT &&
                        IdentifyCharacter(*(cluster + 1)) == CON)
                    {
                        S32 conjunct = *(glyphoutput - 1);

                        switch (conjunct)
                        {
                            case L_KSHA:
                                *(glyphoutput - 1) = H_KHSA;
                                break;
                            case L_TRA:
                                *(glyphoutput - 1) = H_TRA;
                                break;
                            case L_SHRA:
                                *(glyphoutput - 1) = H_SHRA;
                                break;
                            case L_TTTA:
                                *(glyphoutput - 1) = H_TTA;
                                break;
                            default:
                                break;
                        }

                        //if( *(glyphoutput-1) == L_KSHA)
                        //*(glyphoutput-1)=H_KHSA;
                        //else if( *(glyphoutput-1) == L_TRA)
                        //*(glyphoutput-1)=H_TRA;
                        //else if( *(glyphoutput-1) == L_SHRA)
                        //*(glyphoutput-1)=H_SHRA;
                        ////cases of L_GYA to be added
                        //else if( *(glyphoutput-1) == L_TTTA)
                        //*(glyphoutput-1)=H_TTA;

                        *glyphoutput = (U16) NULL;
                        nentry -= 1;
                        cluster += 1;
                        noutglyph += 1;
                        matched = TRUE;
                        break;
                    }
                    /* vj 01/12/04 */
                    break;
                }

            }
            if (matched != TRUE)
            {
                --tomatch;
            }
            else
            {
                tomatch = nentry;
            }

        }
        return noutglyph;
    }
    else
    {
        glyphoutput[nentry - 1] = *cluster;
        glyphoutput[nentry] = (U16) NULL;
        return nentry;
    }

}

//void init_cluster_start_p(PU16 buffer)
//{
//      if(buffer!=NULL)
//      cluster_start_p = buffer;
//}
//void init_cluster_end_p(PU16 buffer)
//{
//      if(buffer!=NULL)
//      cluster_end_p = buffer;
//}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  hf_get_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cluster     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hf_get_cluster(PU16 cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFill = 0;                      /* no. of elements filled in the cluster */
    S32 j = 0;                          /* loop counter */
    S32 i;
    U16 temp;
    S32 ch;                             /* whether CON,INDVOW,DEPVOW,SIGN,NUM */
    PU16 start_cluster = cluster;
    PU8 start_char = cluster_start_p;   /* points to the starting character of the input string */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!HINDI_CONVERT_U8_U16(start_char))
    {
        return 0;
    }
    if (!HF_HINDI_RANGE(HINDI_CONVERT_U8_U16(start_char)))
    {
        HINDI_FILL_CLUSTER();
        start_cluster[nFill] = (U16) NULL;
        cluster_start_p += (nFill * 2);
        /* cluster_start_p=cluster_start_p+(nFill*2); */
        return nFill;
    }
    ch = IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char));
    nFill = 0;
    switch (ch)
    {
            /* if( ch == CON ) */
        case CON:
        {
            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
            //nFill++;start_char++;
            HINDI_FILL_CLUSTER();
            /* if( (cursor_pointer_end_current_cluster == start_char) || hf_end_cluster(start_cluster,start_char,nFill) )
               {
               return nFill;
               } */
            HF_END_CLUSTER(start_cluster, start_char, nFill);
            MMI_ASSERT(!(nFill > G_MAX));
            if (HINDI_CONVERT_U8_U16(start_char) == S_HALANT)
            {
                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                //nFill++;start_char++;
                HINDI_FILL_CLUSTER();
                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                   return nFill; */
                HF_END_CLUSTER(start_cluster, start_char, nFill);
                MMI_ASSERT(!(nFill > G_MAX));
                if (HINDI_CONVERT_U8_U16(start_char) == C_RA)
                {
                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                    //nFill++;start_char++;
                    HINDI_FILL_CLUSTER();
                    if (HINDI_CONVERT_U8_U16(start_char) == S_HALANT)
                    {
                        nFill = hf_get_consonant_cluster(&start_cluster, &start_char, nFill);
                    }
                    MMI_ASSERT(!(nFill > G_MAX));
                    if ((nFill % 2) && start_cluster[0] == C_RA)
                    {
                        if (HINDI_CONVERT_U8_U16(start_char) != DV_I &&
                            IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == DEPVOW)
                        {
                            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();

                        }
                        for (i = 0; i <= 1; i++)
                        {
                            temp_array[0] = start_cluster[0];
                            for (j = 0; j < nFill - 1; j++)
                            {
                                start_cluster[j] = start_cluster[j + 1];
                            }
                            start_cluster[j] = temp_array[0];
                        }
                        /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                           return nFill; */
                        HF_END_CLUSTER(start_cluster, start_char, nFill);
                        if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                        {
                            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                    }
                    else if (start_cluster[0] == C_RA)
                    {
                        temp = start_cluster[nFill - 1];
                        for (i = 0; i <= 1; i++)
                        {
                            temp_array[0] = start_cluster[0];
                            for (j = 0; j < nFill - 2; j++)
                            {
                                start_cluster[j] = start_cluster[j + 1];
                            }
                            start_cluster[j] = temp_array[0];
                        }
                        start_cluster[nFill - 1] = temp;
                    }
                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                       return nFill; */
                    HF_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                    if (HINDI_CONVERT_U8_U16(start_char) == DV_I)
                    {
                        //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                        //nFill++;start_char++;
                        HINDI_FILL_CLUSTER();
                        temp = start_cluster[nFill - 1];
                        for (j = nFill - 1; j >= 0; j--)
                        {
                            start_cluster[j + 1] = start_cluster[j];
                        }
                        start_cluster[j + 1] = temp;
                        /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                           return nFill; */
                        HF_END_CLUSTER(start_cluster, start_char, nFill);
                        MMI_ASSERT(!(nFill > G_MAX));
                        if (HINDI_CONVERT_U8_U16(start_char) == S_BINDU)
                        {
                            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                            MMI_ASSERT(!(nFill > G_MAX));
                        }
                    }
                    /* vijay 061204 */
                    else if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == DEPVOW ||
                             IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                    {
                        //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                        //nFill++;start_char++;
                        HINDI_FILL_CLUSTER();
                        /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                           return nFill; */
                        HF_END_CLUSTER(start_cluster, start_char, nFill);
                        MMI_ASSERT(!(nFill > G_MAX));
                        if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                        {
                            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                    }
                    /* vijay 061204 issue of U matra solved */
                }
                else if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == CON)
                {
                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                    //nFill++;start_char++;
                    HINDI_FILL_CLUSTER();
                    MMI_ASSERT(!(nFill > G_MAX));
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif /* 0 */ 
                    {
                        if (start_cluster[0] == C_RA && HINDI_CONVERT_U8_U16(start_char) == DV_I)
                        {
                            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* reordering logic */

                            /* chhoti E */
                            temp = start_cluster[nFill - 1];
                            for (j = nFill - 1; j >= 0; j--)
                            {
                                start_cluster[j + 1] = start_cluster[j];
                            }
                            start_cluster[j + 1] = temp;
                            //end chhoti E
                            //reordering logic                                         
                            /* temp_array[0] = start_cluster[3];
                               temp_array[1] = start_cluster[2];
                               temp_array[2] = start_cluster[0];
                               temp_array[3] = start_cluster[1];
                               for(j=0; j<=3; j++)
                               start_cluster[j] = temp_array[j]; */
                            /* end reordering */
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* start vijay changes done for the SIGN to be included in cluster */
                            if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                            {
                                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                //nFill++;start_char++;
                                HINDI_FILL_CLUSTER();
                                //start reordering logic Chhoti E
                                //START VIJAY PMT 20050728..COMMENTED AS NO REORDERING IS REQUIRED HERE
                                /* temp = start_cluster[nFill-2]; 
                                   start_cluster[nFill-2]=start_cluster[nFill-1];
                                   start_cluster[nFill-1] = temp; */
                                //END VIJAY PMT 20050728
                                //end          
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                   return nFill; */
                                HF_END_CLUSTER(start_cluster, start_char, nFill);
                            }
                            /* vijay end */
                        }
                        else if (((start_cluster[0] == C_RA) &&
                                  IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == DEPVOW))
                        {
                            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* reordering logic */
                            temp_array[0] = start_cluster[2];
                            temp_array[1] = start_cluster[3];
                            temp_array[2] = start_cluster[0];
                            temp_array[3] = start_cluster[1];
                            for (j = 0; j <= 3; j++)
                            {
                                start_cluster[j] = temp_array[j];
                            }
                            /* end reordering logic */
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                            MMI_ASSERT(!(nFill > G_MAX));
                            if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                            {
                                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                //nFill++;start_char++;
                                HINDI_FILL_CLUSTER();
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                   return nFill; */
                                HF_END_CLUSTER(start_cluster, start_char, nFill);
                            }

                        }
                        else if (start_cluster[0] == C_RA)
                        {
                            if (HINDI_CONVERT_U8_U16(start_char) == S_HALANT)
                            {
                                nFill = hf_get_consonant_cluster(&start_cluster, &start_char, nFill);
                            }
                            MMI_ASSERT(!(nFill > G_MAX));
                            if ((nFill % 2) && start_cluster[0] == C_RA)
                            {
                                for (i = 0; i <= 1; i++)
                                {
                                    temp_array[0] = start_cluster[0];
                                    for (j = 0; j < nFill - 1; j++)
                                    {
                                        start_cluster[j] = start_cluster[j + 1];
                                    }
                                    start_cluster[j] = temp_array[0];
                                }
                            }
                            else
                            {
                                temp = start_cluster[nFill - 1];
                                for (i = 0; i <= 1; i++)
                                {
                                    temp_array[0] = start_cluster[0];
                                    for (j = 0; j < nFill - 2; j++)
                                    {
                                        start_cluster[j] = start_cluster[j + 1];
                                    }
                                    start_cluster[j] = temp_array[0];
                                }
                                start_cluster[nFill - 1] = temp;
                            }
                            if (HINDI_CONVERT_U8_U16(start_char) == DV_I)
                            {
                                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                //nFill++;start_char++;
                                HINDI_FILL_CLUSTER();
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* reordering logic */
                                temp = start_cluster[nFill - 1];
                                for (j = nFill - 1; j >= 0; j--)
                                {
                                    start_cluster[j + 1] = start_cluster[j];
                                }
                                start_cluster[j + 1] = temp;
                                /* end */
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                   return nFill; */
                                HF_END_CLUSTER(start_cluster, start_char, nFill);
                                if (HINDI_CONVERT_U8_U16(start_char) == S_BINDU)
                                {
                                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                    //nFill++;start_char++;
                                    HINDI_FILL_CLUSTER();
                                    MMI_ASSERT(!(nFill > G_MAX));
                                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                       return nFill; */
                                    HF_END_CLUSTER(start_cluster, start_char, nFill);

                                }
                            }
                            else if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == DEPVOW ||
                                     IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                            {
                                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                //nFill++;start_char++;
                                HINDI_FILL_CLUSTER();
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                   return nFill; */
                                HF_END_CLUSTER(start_cluster, start_char, nFill);
                                if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                                {
                                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                    //nFill++;start_char++;
                                    HINDI_FILL_CLUSTER();
                                    MMI_ASSERT(!(nFill > G_MAX));
                                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                       return nFill; */
                                    HF_END_CLUSTER(start_cluster, start_char, nFill);
                                }
                            }
                        }
                        else
                        {
                            if (HINDI_CONVERT_U8_U16(start_char) == S_HALANT)
                            {
                                nFill = hf_get_consonant_cluster(&start_cluster, &start_char, nFill);
                            }
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* vj30/11/04 */
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                            /* vj30/11/04 */
                            if (HINDI_CONVERT_U8_U16(start_char) == DV_I)
                            {
                                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char)
                                //nFill++;start_char++;
                                HINDI_FILL_CLUSTER();
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* reordering logic */
                                temp = start_cluster[nFill - 1];
                                for (j = nFill - 1; j >= 0; j--)
                                {
                                    start_cluster[j + 1] = start_cluster[j];
                                }
                                start_cluster[j + 1] = temp;
                                /* end */
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                   return nFill; */
                                HF_END_CLUSTER(start_cluster, start_char, nFill);
                                if (HINDI_CONVERT_U8_U16(start_char) == S_BINDU)
                                {
                                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                    //nFill++;start_char++;
                                    HINDI_FILL_CLUSTER();
                                    MMI_ASSERT(!(nFill > G_MAX));
                                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                       return nFill; */
                                    HF_END_CLUSTER(start_cluster, start_char, nFill);
                                }
                            }
                            else if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == DEPVOW ||
                                     IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                            {
                                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                //nFill++;start_char++;
                                HINDI_FILL_CLUSTER();
                                MMI_ASSERT(!(nFill > G_MAX));
                                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                   return nFill; */
                                HF_END_CLUSTER(start_cluster, start_char, nFill);
                                if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                                {
                                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                                    //nFill++;start_char++;
                                    HINDI_FILL_CLUSTER();
                                    MMI_ASSERT(!(nFill > G_MAX));
                                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                                       return nFill; */
                                    HF_END_CLUSTER(start_cluster, start_char, nFill);
                                }
                            }
                        }
                    }   /* if not ligature */
                }       /* if not RA */
            }           /* end of if HALANT */
            else
            {
                if (HINDI_CONVERT_U8_U16(start_char) == DV_I)
                {
                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                    //nFill++;start_char++;
                    HINDI_FILL_CLUSTER();
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* reordering logic */
                    temp = start_cluster[0];
                    start_cluster[0] = start_cluster[nFill - 1];
                    start_cluster[nFill - 1] = temp;
                    /* end */
                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                       return nFill; */
                    HF_END_CLUSTER(start_cluster, start_char, nFill);
                    if (HINDI_CONVERT_U8_U16(start_char) == S_BINDU || HINDI_CONVERT_U8_U16(start_char) == S_VISARGA)
                    {
                        //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                        //nFill++;start_char++;
                        HINDI_FILL_CLUSTER();
                        MMI_ASSERT(!(nFill > G_MAX));
                        /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                           return nFill; */
                        HF_END_CLUSTER(start_cluster, start_char, nFill);

                    }
                }
                else if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == DEPVOW)
                {
                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                    //nFill++;start_char++;
                    HINDI_FILL_CLUSTER();
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                       return nFill; */
                    HF_END_CLUSTER(start_cluster, start_char, nFill);
                    if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                    {
                        //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                        //nFill++;start_char++;
                        HINDI_FILL_CLUSTER();
                        MMI_ASSERT(!(nFill > G_MAX));
                        /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                           return nFill; */
                        HF_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                }
                else if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                {
                    //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                    //nFill++;start_char++;
                    HINDI_FILL_CLUSTER();
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                       return nFill; */
                    HF_END_CLUSTER(start_cluster, start_char, nFill);
                    if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == DEPVOW)
                    {
                        if (HINDI_CONVERT_U8_U16(start_char) == DV_I)
                        {
                            //start_cluster[nFill] = *start_char;
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            /* reordering logic */
                            temp = start_cluster[nFill - 1];
                            for (j = nFill - 1; j >= 0; j--)
                            {
                                start_cluster[j + 1] = start_cluster[j];
                            }
                            start_cluster[j + 1] = temp;
                            /* end */
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                        else
                        {
                            //start_cluster[nFill] = *start_char;
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                        if (IdentifyCharacter(HINDI_CONVERT_U8_U16(start_char)) == SIGN)
                        {
                            //start_cluster[nFill] = *start_char;
                            //nFill++;start_char++;
                            HINDI_FILL_CLUSTER();
                            MMI_ASSERT(!(nFill > G_MAX));
                            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                               return nFill; */
                            HF_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                    }
                }
            }   /* if not halant */
            start_cluster[nFill] = (U16) NULL;
            cluster_start_p += (nFill * 2);
            return nFill;
            break;
        }       /* end of if first character is consonant */
            /* else if( ch == INDVOW ) */
        case INDVOW:
        {
            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
            //nFill++;start_char++;
            HINDI_FILL_CLUSTER();
            MMI_ASSERT(!(nFill > G_MAX));
            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
               return nFill; */
            HF_END_CLUSTER(start_cluster, start_char, nFill);
            /* START PMTFARHAD 20050224 */
            if (HINDI_CONVERT_U8_U16(start_char) == S_CHANDRA_BINDU || HINDI_CONVERT_U8_U16(start_char) == S_BINDU ||
                HINDI_CONVERT_U8_U16(start_char) == S_VISARGA)
                /* END PMTFARHAD 20050224 */
            {
                //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
                //nFill++;start_char++;
                HINDI_FILL_CLUSTER();
                MMI_ASSERT(!(nFill > G_MAX));
                /* if( hf_end_cluster(start_cluster,start_char,nFill) )
                   return nFill; */
                HF_END_CLUSTER(start_cluster, start_char, nFill);

            }
            start_cluster[nFill] = (U16) NULL;
            cluster_start_p += (nFill * 2);
            return nFill;
            break;
        }
            /* else if ( ch == DEPVOW ) */
        case DEPVOW:
        {
            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
            //nFill++;start_char++;
            HINDI_FILL_CLUSTER();
            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
               return nFill;
               else
               if(nFill > G_MAX) return nFill; */
            start_cluster[nFill] = (U16) NULL;
            cluster_start_p += (nFill * 2);
            return nFill;
            break;
        }
            /* else if ( ch == SIGN ) */
        case SIGN:
        {
            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
            //nFill++;start_char++;
            HINDI_FILL_CLUSTER();
            /* if( hf_end_cluster(start_cluster,start_char,nFill) )
               return nFill;
               else
               if(nFill > G_MAX) return nFill; */
            start_cluster[nFill] = (U16) NULL;
            cluster_start_p += (nFill * 2);
            return nFill;
            break;
        }
            /* any character other than Hindi */
            /* else */
        default:
        {
            //start_cluster[nFill] = HINDI_CONVERT_U8_U16(start_char);
            //nFill++;start_char++;
            HINDI_FILL_CLUSTER();
            start_cluster[nFill] = (U16) NULL;
            cluster_start_p += (nFill * 2);
            return nFill;
            break;
        }
    }
    return 0;
}   /* end of function get_cluster */

/* 17th nov start */


/*****************************************************************************
 * FUNCTION
 *  hf_get_consonant_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_cluster       [?]         
 *  start_char          [?]         
 *  nentry              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hf_get_consonant_cluster(PU16 *start_cluster, PU8 *start_char, S32 nentry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if( **start_char == S_HALANT )
       { */
    (*start_cluster)[nentry] = HINDI_CONVERT_U8_U16(*start_char);
    nentry++;
    (*start_char) += 2;
    if (nentry == G_MAX - 2)
    {
        return nentry;
    }
    if (*start_char == cluster_end_p)
    {
        return nentry;
    }
    if (IdentifyCharacter(HINDI_CONVERT_U8_U16(*start_char)) == CON)
    {
        (*start_cluster)[nentry] = HINDI_CONVERT_U8_U16(*start_char);
        nentry++;
        (*start_char) += 2;
        MMI_ASSERT(!(nentry > G_MAX));
        if (*start_char == cluster_end_p)
        {
            return nentry;
        }
        if (nentry > G_MAX)
        {
            return nentry;
        }
        if (HINDI_CONVERT_U8_U16(*start_char) == S_HALANT)
        {
            nentry = hf_get_consonant_cluster(start_cluster, start_char, nentry);
        }
    }
    else
    {
        return nentry;
    }
    /* }
       else
       return nentry; */
    return nentry;
}

/* 17th nov end */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  hf_get_next_cluster_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_p          [IN]        
 *  cursor_p        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PU8 hf_get_next_cluster_p(PU8 text_p, PU8 cursor_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 current_cursor_p = text_p;
    PU8 prev_cursor_p = text_p;
    U16 cluster_buffer[G_MAX];  /* just to fill the cluster for the purpose of getting its length */
    S32 len = 0;
    PU8 cursor_pointer = cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_pointer += 2;
    if (HINDI_CONVERT_U8_U16(cursor_p) == (U16) NULL)
    {
        return cursor_p;
    }
    else if (HF_HINDI_RANGE(HINDI_CONVERT_U8_U16(cursor_pointer)))
    {
        init_cluster_start_p(text_p);
        init_cluster_end_p(cursor_p);
    #if 0   /* No use as this condition never gets true */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ /* TARUN 20050108 */
        len = hf_get_cluster(cluster_buffer);
        current_cursor_p += (len * 2);
        return current_cursor_p;
    }
    else
    {
        return cursor_pointer;
    }
}


/*****************************************************************************
 * FUNCTION
 *  hf_get_prev_cluster_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_p          [IN]        
 *  cursor_p        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PU8 hf_get_prev_cluster_p(PU8 text_p, PU8 cursor_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 current_cursor_p = text_p;
    PU8 prev_cursor_p = text_p;
    S32 len = 0;
    U16 cluster_buffer[G_MAX];
    PU8 cursor_pointer = cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_pointer -= 2;
    if (HF_HINDI_RANGE(HINDI_CONVERT_U8_U16(cursor_pointer)))
    {
        init_cluster_start_p(text_p);
        init_cluster_end_p(cursor_p);
        while (current_cursor_p != cursor_p)
        {
            len = hf_get_cluster(cluster_buffer);
            prev_cursor_p = current_cursor_p;
            current_cursor_p += (len * 2);
            if (len == 0)
            {
                break;
            }
        }
        return prev_cursor_p;
    }
    else
    {
        return cursor_pointer;
    }
}


/*****************************************************************************
 * FUNCTION
 *  hf_size_of_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_p          [IN]        
 *  cursor_p        [IN]        
 *  cursor          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hf_size_of_current_cluster(PU8 text_p, PU8 cursor_p, U16 cursor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 muv_cursor_p = text_p;
    S32 len = 0;
    S32 pixel_size = 0;
    U16 cluster_buffer[G_MAX];
    U16 glyphoutput[G_MAX];
    PU8 cursor_pointer = cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_p == cursor_p)
    {
        return 0;
    }
    cursor_pointer -= 2;
    if (HF_HINDI_RANGE(HINDI_CONVERT_U8_U16(cursor_pointer)))
    {
        init_cluster_start_p(text_p);
        init_cluster_end_p(cursor_p);
        while (muv_cursor_p != cursor_p)
        {
            len = hf_get_cluster(cluster_buffer);
            muv_cursor_p += (len * 2);
            if (len == 0)
            {
                break;
            }
        }
        hf_hindi_rules(glyphoutput, cluster_buffer, len);
        if (cursor)
        {
            pixel_size = hf_get_string_width_height(glyphoutput);
        }
        else
        {
            pixel_size = hf_get_string_Dwidth_height(glyphoutput);
        }
        return pixel_size;
    }
    else
    {
        pixel_size = gui_get_character_width(HINDI_CONVERT_U8_U16(cursor_pointer));
        cursor_pointer_end_current_cluster = NULL;
        return pixel_size;
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  hf_get_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_p              [IN]        
 *  cursor_p            [IN]        
 *  output_buffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hf_get_current_cluster(PU8 text_p, PU8 cursor_p, PU16 output_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 cursor_pointer = cursor_p;
    PU8 muv_cursor_p = text_p;
    S32 len = 0;
    U16 glyphoutput[G_MAX];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_pointer_end_current_cluster = cursor_pointer;
    cursor_pointer -= 2;
    if (HF_HINDI_RANGE(HINDI_CONVERT_U8_U16(cursor_pointer)))
    {
        init_cluster_start_p(text_p);
        init_cluster_end_p(cursor_p);
        while (muv_cursor_p != cursor_p)
        {
            len = hf_get_cluster(output_buffer);
            muv_cursor_p += (len * 2);
            if (len == 0)
            {
                break;
            }
        }
        memset(glyphoutput, '\0', len);
        hf_hindi_rules(glyphoutput, output_buffer, len);
        /* vj 30/11/04 */
        memcpy(output_buffer, glyphoutput, mmi_ucs2strlen((const S8*)glyphoutput) * 2);
        output_buffer[mmi_ucs2strlen((const S8*)glyphoutput)] = (U16) NULL;
        /* vj 30/11/04 */
        cursor_pointer_end_current_cluster = NULL;
        return TRUE;
    }
    else
    {
        init_cluster_start_p(cursor_pointer);
        hf_get_cluster(output_buffer);
        hf_hindi_rules(glyphoutput, output_buffer, 1);
        /* vj 30/11/04 */
        memcpy(output_buffer, glyphoutput, 2);
        output_buffer[mmi_ucs2strlen((const S8*)glyphoutput)] = (U16) NULL;
        /* vj 30/11/04 */
        cursor_pointer_end_current_cluster = NULL;
        return TRUE;
    }
}

/* Start Farhad 30-04-2004 */

//void reset_hindi_params(void)
//{
//      prev_char_text_x = 0;
//      prev_char_dwidth = 0;
//      prev_char_width = 0;
//      new_line = 1;
//}
//START TARUN PMT 20050128
extern BOOL r2lMMIFlag;

/* END TARUN PMT 20050128 */


/*****************************************************************************
 * FUNCTION
 *  get_text_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptext_x                 [?]         
 *  current_character       [IN]        
 *  text_y                  [IN]        
 *  d_width                 [IN]        
 *  width                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_text_x(S32 *ptext_x, U16 current_character, S32 text_y, U16 d_width, U16 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* START TARUN PMT 20050128 */
    U8 is_hindi = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* START FARHAD PIXTELMTK  20050217 */
    if (current_character >= 0x0E01 && current_character <= 0x0E7F)
    {
        prev_char_text_x = *ptext_x;
        prev_char_dwidth = width;
        prev_char_width = width;
        /* START PMTFARHAD 20050224 */
        if (IsThaiAboveLineChar(current_character))
        {
            prev_char_dwidth = 0;
            prev_char_width = 0;
        }
        prev_character = current_character;
        /* END PMTFARHAD 20050224 */
        return;
    }
    /* END FARHAD PIXTELMTK  20050217 */

    if (!(UI_HINDI_CHARACTER_UCS2_RANGE(current_character)))
    {
        d_width = width;
        prev_char_dwidth = prev_char_width;
        is_hindi = 0;
        if (r2lMMIFlag)
        {
            return;
        }
    }
    /* END TARUN PMT 20050128 */
    if (new_line)
    {
        new_line = 0;
        if (UI_HINDI_CHARACTER_UCS2_RANGE(current_character))
        {
            *ptext_x = *ptext_x - hf_padding;
        }
        prev_char_text_x = *ptext_x;
        /* Get_CharWidthHeight_New( current_character,&prev_char_dwidth); */
        prev_char_dwidth = d_width;
        prev_char_width = width;
        prev_character = current_character;
        return;
    }
    /* PMT START MAUI_00223197 */
    if ((current_character != S_VISARGA) && UI_HINDI_SIGN_RANGE(current_character))
        /* PMT END MAUI_00223197 */
    {
        *ptext_x = prev_char_text_x;
        prev_char_dwidth = prev_char_dwidth;
        prev_char_width = prev_char_width;
    }
    else
    {
        if (is_hindi)
        {
            if (!(UI_HINDI_CHARACTER_UCS2_RANGE(prev_character)))
            {
                prev_char_text_x -= hf_padding;
            }
            /* if(current_character==59774|| current_character==59775)
               {
               *ptext_x = prev_char_dwidth + prev_char_text_x;
               return;
               } */
        }
        *ptext_x = prev_char_dwidth + prev_char_text_x;
        prev_char_text_x = *ptext_x;
        /* Get_CharWidthHeight_New( current_character,&prev_char_dwidth); */
        prev_char_dwidth = d_width;
        prev_char_width = width;
    }
    prev_character = current_character;
    return;
}

/* END */


/*****************************************************************************
 * FUNCTION
 *  get_multitap_text_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptext_x                 [?]         
 *  current_character       [IN]        
 *  Char_Range              [IN]        
 *  check_char              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_multitap_text_x(S32 *ptext_x, U16 current_character, S32 Char_Range, S32 check_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 prev_char_mtext_x = 0;
    static S32 prev_char_mdwidth = 0;
    S32 character_height;
    S32 text_x;
    S32 mtext_gap = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_ASSERT(!(*ptext_x > 128)); */
    text_x = *ptext_x;
    if (!(check_char))
    {
        switch (Char_Range)
        {
            case 1:
            {
                *ptext_x = 59;
                break;
            }
            case 2:
            {
                *ptext_x = 54;
                break;
            }
            case 3:
            {
                *ptext_x = 49;
                break;
            }
            case 4:
            {
                *ptext_x = 44;
                break;
            }
            case 5:
            {
                *ptext_x = 39;
                break;
            }
            case 6:
            {
                *ptext_x = 35;
                break;
            }
            case 7:
            {
                *ptext_x = 30;
                break;
            }
            case 8:
            {
                *ptext_x = 25;
                break;
            }
            case 9:
            {
                *ptext_x = 20;
                break;
            }
            case 10:
            {
                *ptext_x = 15;
                break;
            }
            case 11:
            {
                *ptext_x = 10;
                break;
            }
            case 12:
                /* START VIJAY PMT 20050725 */
            case 13:
            case 14:
                /* END VIJAY PMT 20050725 */
            {
                /* START VIJAY PMT 20050720.....initial value  = 5 */
                *ptext_x = 7;
                /* END VIJAY PMT 20050725 */
                break;
            }
            default:
            {
                *ptext_x = 3;
                break;
            }
        }
        /*
         * if(Char_Range == 1)
         * *ptext_x = 59;
         * else if(Char_Range == 2)
         * *ptext_x = 54;
         * else if(Char_Range == 3)
         * *ptext_x = 49;
         * else if(Char_Range == 4)
         * *ptext_x = 44;
         * else if(Char_Range == 5)
         * *ptext_x = 39;
         * else if(Char_Range == 6)
         * *ptext_x = 35;
         * else if(Char_Range == 7)
         * *ptext_x = 30;
         * else if(Char_Range == 8)
         * *ptext_x = 25;
         * else if(Char_Range == 9)
         * *ptext_x = 20;
         * else if(Char_Range == 10)
         * *ptext_x = 15;
         * else if(Char_Range == 11)
         * *ptext_x = 10;
         * else if(Char_Range == 12)
         * *ptext_x = 5;
         * else
         * *ptext_x = 0;
         */
        prev_char_mtext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &prev_char_mdwidth, &character_height);
        return;
    }
    /* if(HF_DEPVOW_RANGE(current_character)|| HF_SIGN_RANGE(current_character)) */
    if (IdentifyCharacter(current_character) == DEPVOW || IdentifyCharacter(current_character) == SIGN)
    {
        text_x = prev_char_mdwidth + prev_char_mtext_x + mtext_gap;
    }
    else
    {
        text_x = prev_char_mdwidth + prev_char_mtext_x;
    }
    Get_CharWidthHeight(current_character, &prev_char_mdwidth, &character_height);
    prev_char_mtext_x = text_x;
    if (current_character == DV_II)
    {
        *ptext_x = text_x + mtext_gap;
    }
    else
    {
        *ptext_x = text_x;
    }
}

/* start farhad 5-11-04  api to get the string width and height it uses width and dwidth both. */


/*****************************************************************************
 * FUNCTION
 *  hf_get_string_width_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hf_get_string_width_height(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* START VIJAY PMT 20050728 */
    hf_disable_hindi_rules_parsing();
    gui_measure_string(text, &w, &h);
    hf_enable_hindi_rules_parsing();
    /* END VIJAY PMT 20050728 */
    return (w);
}

/* api that use dwidth only */


/*****************************************************************************
 * FUNCTION
 *  hf_get_string_Dwidth_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hf_get_string_Dwidth_height(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* START VIJAY PMT 20050728 */
    hf_disable_hindi_rules_parsing();
    gui_measure_string(text, &w, &h);
    hf_enable_hindi_rules_parsing();
    /* END VIJAY PMT 20050728 */
    return (w);
}

/* end 5-11-04 */

/* Start vijay */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* End */

/* start farhad 08122004 */

//void reset_hindi_bordered_params(void)
//{
//      prev_char_btext_x = 0;
//      prev_char_bdwidth = 0;
//      new_bline = 1;
//}


/*****************************************************************************
 * FUNCTION
 *  get_bordered_text_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptext_x                 [?]         
 *  current_character       [IN]        
 *  text_y                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_bordered_text_x(S32 *ptext_x, U16 current_character, S32 text_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_ASSERT(!(*ptext_x > 128)); */
    if (new_bline)
    {
        new_bline = 0;
        prev_char_btext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &prev_char_bdwidth, &character_height);
        return;
    }
    /* PMT START MAUI_00223197 */
    if ((current_character != S_VISARGA) && UI_HINDI_SIGN_RANGE(current_character))
        /* PMT END MAUI_00223197 */
    {
        *ptext_x = prev_char_btext_x;
        prev_char_bdwidth = prev_char_bdwidth;
    }
    else
    {
        *ptext_x = prev_char_bdwidth + prev_char_btext_x;
        prev_char_btext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &prev_char_bdwidth, &character_height);
    }
    return;
}

//void reset_use_multitap(void)
//{
//      use_multitap=0;
//}
//
//void set_use_multitap(void)
//{
//      use_multitap=1;
//}
//
//S32 whether_use_multitap(void)
//{
//      return use_multitap;
//}

//S32 hf_disable_hindi_rules_parsing(void)
//{
//      parse_hindi=0;
//}
//
//S32 hf_enable_hindi_rules_parsing(void)
//{
//      parse_hindi=1;
//}
//
//S32 hf_is_hindi_rules_parsing(void)
//{
//      return parse_hindi;
//}

//void hf_disable_hindi_reset_hindi_params(void)
//{
//      reset_hindi_pms=0;
//}
//
//hf_enable_hindi_reset_hindi_params(void)
//{
//      reset_hindi_pms=1;
//}
//
//hf_is_reset_hindi_params(void)
//{
//      return reset_hindi_pms;
//}

//End farhad 08122004
//START FARHAD PMT 20050211


/*****************************************************************************
 * FUNCTION
 *  get_hindi_rules_for_whole_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_hindi_rules_for_whole_string(PU8 String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 StringArray[2048];
    U16 cluster_fill[G_MAX];
    U16 glyph_output[G_MAX];
    S32 Len;
    S32 cluster_length;
    U16 hindi_present = 0;
    U8 *temp_string = String;
    U16 unicode = 0;
    U16 Fill = 0;
    U16 clFill = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((temp_string[clFill] != '\0' || temp_string[clFill + 1] != '\0') && !hindi_present)
    {
        unicode = temp_string[clFill];
        unicode |= (temp_string[clFill + 1] << 8);
        if (UI_HINDI_CHARACTER_UCS2_RANGE(unicode))
        {
            hindi_present = 1;
        }
        clFill += 2;
    }
    if (hindi_present)
    {
        init_cluster_start_p(String);
        init_cluster_end_p(String);
        while (temp_string[0] != '\0' || temp_string[1] != '\0')
        {
            clFill = 0;
            unicode = temp_string[0];
            unicode |= (temp_string[1] << 8);
            cluster_length = hf_get_cluster( /* (PU16) */ cluster_fill);
            if (UI_HINDI_CHARACTER_UCS2_RANGE(unicode))
            {
                Len = hf_hindi_rules( /* (PU16) */ glyph_output, /* (PU16) */ cluster_fill, cluster_length);
                temp_string += cluster_length * 2;
                while (glyph_output[clFill] != '\0' /* || glyph_output[clFill+1]!='\0' */ )
                {
                    StringArray[Fill++] = (U8) (glyph_output[clFill] & 0x00ff);
                    StringArray[Fill++] = (U8) (glyph_output[clFill++] >> 8) & 0x00ff;
                }
            }
            else
            {
                StringArray[Fill++] = temp_string[0];
                StringArray[Fill++] = temp_string[1];
                temp_string += 2;
            }
        }
        StringArray[Fill++] = NULL;
        StringArray[Fill++] = NULL;
        memcpy(String, StringArray, Fill);
        /* String[Fill]=NULL; */
    }
}

/* END FARHAD PMT 20050211 */
/* PMT RAKESH START 20061006 */


/*****************************************************************************
 * FUNCTION
 *  set_current_language_for_hindi_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_language_for_hindi_rules(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U8 temp_str1[30];
    U8 temp_str2[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) temp_str1, (S8*) gLanguageArray[gCurrLangIndex].aLangSSC);
    for (index = 0; index < (sizeof(HRLangSSC) / sizeof(HRLangSSC[0])); index++)
    {
        mmi_asc_to_ucs2((S8*) temp_str2, (S8*) HRLangSSC[index].ssc_string);
        if (mmi_ucs2cmp((const S8*)temp_str1, (const S8*)temp_str2) == 0)
        {
            hf_rules_current_set_language = HRLangSSC[index].language_enum;
            hf_rules_prefered_set_language = hf_rules_current_set_language;
            return;
        }
    }
    hf_rules_current_set_language = HRLangSSC[0].language_enum;
    hf_rules_prefered_set_language = hf_rules_current_set_language;
}



/*****************************************************************************
 * FUNCTION
 *  overwrite_current_language_for_hindi_rules_based_on_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void overwrite_current_language_for_hindi_rules_based_on_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_input_mode == INPUT_MODE_MULTITAP_MARATHI)
    {
        hf_rules_current_set_language = MMI_MARATHI_LANG;
    }
    else if (MMI_current_input_mode == INPUT_MODE_MULTITAP_HINDI)
    {
        hf_rules_current_set_language = MMI_HINDI_LANG;
    }
}


/*****************************************************************************
 * FUNCTION
 *  restore_current_language_for_hindi_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_current_language_for_hindi_rules(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hf_rules_current_set_language = hf_rules_prefered_set_language;
}

/* PMT RAKESH END 20061006 */
#endif /* __MMI_HINDI_ALG__ */ 

