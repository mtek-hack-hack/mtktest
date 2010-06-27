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
 *    Bengali.h
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
 * Rakesh (PMT00098)
 * Satish (PMT00107)
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_BENGALI_H
#define MMI_BENGALI_H
#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"

#ifdef __MMI_LANG_BENGALI__

#define IRE_BENGALI_LANG_START_RANGE		0x0980
#define IRE_BENGALI_LANG_END_RANGE			0x09FD
#define IRE_BENGALI_PROPRIETRY_START_RANGE	0xE9FF
/* PMT START MAUI_00027782 */
#define IRE_BENGALI_PROPRIETRY_END_RANGE	0xEAC6
/* PMT END MAUI_00027782 */

typedef enum
{
	/* VARIOUS SIGNS + INDEPENDENT VOWEL */
    BENGALI_S_CHANDRA_BINDU		= 0x981,
    BENGALI_S_ANUSVARA			= 0x982,
    BENGALI_S_VISARGA			= 0x983,

    BENGALI_IV_A				= 0x985,
    BENGALI_IV_AA				= 0x986,
    BENGALI_IV_I				= 0x987,
    BENGALI_IV_II				= 0x988,
    BENGALI_IV_U				= 0x989,
    BENGALI_IV_UU				= 0x98a,
    BENGALI_IV_VR				= 0x98b,
    BENGALI_IV_VL				= 0x98c,
	BENGALI_IV_E				= 0x98f,
    BENGALI_IV_AI				= 0x990,

    BENGALI_IV_O				= 0x993,
    BENGALI_IV_AU				= 0x994,

    /* CONSONANTS */
    BENGALI_C_KA				= 0x995,
    BENGALI_C_KHA				= 0x996,
    BENGALI_C_GA				= 0x997,
    BENGALI_C_GHA				= 0x998,
    BENGALI_C_NGA				= 0x999,
    BENGALI_C_CA				= 0x99a,
    BENGALI_C_CHA				= 0x99b,
    BENGALI_C_JA				= 0x99c,
    BENGALI_C_JHA				= 0x99d,
    BENGALI_C_NYA				= 0x99e,
    BENGALI_C_TTA				= 0x99f,  
    BENGALI_C_TTHA				= 0x9a0,
    BENGALI_C_DDA				= 0x9a1,
    BENGALI_C_DDHA				= 0x9a2,
    BENGALI_C_NNA				= 0x9a3,
    BENGALI_C_TA				= 0x9a4,
    BENGALI_C_THA				= 0x9a5,
    BENGALI_C_DA				= 0x9a6,
    BENGALI_C_DHA				= 0x9a7,
    BENGALI_C_NA				= 0x9a8,

    BENGALI_C_PA				= 0x9aa,
    BENGALI_C_PHA				= 0x9ab,
    BENGALI_C_BA				= 0x9ac,
    BENGALI_C_BHA				= 0x9ad,
    BENGALI_C_MA				= 0x9ae,
    BENGALI_C_YA				= 0x9af,
    BENGALI_C_RA				= 0x9b0,

    BENGALI_C_LA				= 0x9b2,
    
    BENGALI_C_SHA				= 0x9b6,
    BENGALI_C_SSA				= 0x9b7,
    BENGALI_C_SA				= 0x9b8,
    BENGALI_C_HA				= 0x9b9,
    BENGALI_C_INV				= 0x9ba,

    // VARIOUS SIGNS
    BENGALI_S_NUKTA			    = 0x9bc,
    BENGALI_S_AVAGRAH			= 0x9bd,


    /* DEPENDENT VOWELS */
    BENGALI_DV_AA			= 0x9be,
    BENGALI_DV_I			= 0x9bf,
    BENGALI_DV_II			= 0x9c0,
    BENGALI_DV_U			= 0x9c1,
	BENGALI_DV_UU			= 0x9c2,
	BENGALI_DV_VR			= 0x9c3,
	BENGALI_DV_VRR			= 0x9c4,
    
	BENGALI_DV_E			= 0x9c7,
    BENGALI_DV_AI			= 0x9c8,
    
    BENGALI_DV_O			= 0x9cb,
    BENGALI_DV_AU			= 0x9cc,

    /* SIGNS */
    BENGALI_S_HALANT		= 0x9cd,
    
	/* APPEND DEPENDENT VOWEL */
    BENGALI_AD_TA			= 0x9ce,
    BENGALI_AD_AU			= 0x9d7,

    /* CONSONANTS */
	BENGALI_C_RRA			= 0x9dc,
	BENGALI_C_RHA			= 0x9dd,
	BENGALI_C_YYA			= 0x9df,

	BENGALI_C_VRR			= 0x9e0,
    BENGALI_C_VLL			= 0x9e1,

	BENGALI_S_VRR			= 0x9e2,
    BENGALI_S_VLL			= 0x9e3,
/* PMT START MAUI_00027782 */
    BENGALI_S_DANDA			= 0x9e4,
/* PMT END MAUI_00027782 */
    
    /* DIGITS */
    BENGALI_D_ZERO		    = 0x9e6,
    BENGALI_D_ONE			= 0x9e7,
    BENGALI_D_TWO			= 0x9e8,
    BENGALI_D_THREE		    = 0x9e9,
    BENGALI_D_FOUR		    = 0x9ea,
    BENGALI_D_FIVE		    = 0x9eb,
    BENGALI_D_SIX			= 0x9ec,
    BENGALI_D_SEVEN		    = 0x9ed,
    BENGALI_D_EIGHT		    = 0x9ee,
    BENGALI_D_NINE		    = 0x9ef,

	BENGALI_C_MRA 	        = 0x9f0,
	BENGALI_C_LRA 	        = 0x9f1,
	BENGALI_OS_RUPEE 	    = 0x9f2,
	BENGALI_C_RUPEE_SIGN 	= 0x9f3,
	BENGALI_C_CURONE 	    = 0x9f4,
	BENGALI_C_CURTWO 	    = 0x9f5,

    BENGALI_C_CURTHREE	    = 0x9f6,
    BENGALI_C_CURFOUR	    = 0x9f7,
    BENGALI_OS_CURLESSDEN	= 0x9f8,
    BENGALI_OS_CURDENSIXTEEN= 0x9f9,

	BENGALI_OS_ISSHAR		= 0x9fa
}bengali_characters_enum;


typedef enum
{
    /* Two conjunct Ligatutres */
    BENGALI_L_KA_KA			= 0xEA00,
    BENGALI_L_NGA_KA        = 0xEA01,
    BENGALI_L_LA_KA         = 0xEA02,
    BENGALI_L_SSA_KA        = 0xEA03,
    BENGALI_L_SA_KA         = 0xEA04,
    BENGALI_L_NGA_KHA       = 0xEA05,
    BENGALI_L_SA_KHA        = 0xEA06,
    BENGALI_L_NGA_GA        = 0xEA07,
    BENGALI_L_LA_GA         = 0xEA08,
    BENGALI_L_GA_GA         = 0xEA09,
    BENGALI_L_CA_CA         = 0xEA0A,
    BENGALI_L_NYA_CA        = 0xEA0B,
    BENGALI_L_SHA_CA        = 0xEA0C,
    BENGALI_L_CA_CHA        = 0xEA0D,
    BENGALI_L_NYA_CHA       = 0xEA0E,
    BENGALI_L_SHA_CHA		= 0xEA0F,
    BENGALI_L_NYA_JA        = 0xEA10,
    BENGALI_L_BA_JA         = 0xEA11,
    BENGALI_L_JA_JHA        = 0xEA12,
    BENGALI_L_NYA_JHA       = 0xEA13,
    BENGALI_L_JA_NYA        = 0xEA14,
    BENGALI_L_CA_NYA        = 0xEA15,
    BENGALI_L_KA_TTA        = 0xEA16,
    BENGALI_L_TTA_TTA       = 0xEA17,
    BENGALI_L_NNA_TTA       = 0xEA18,
    BENGALI_L_NA_TTA        = 0xEA19,
    BENGALI_L_PA_TTA        = 0xEA1A,
    BENGALI_L_LA_TTA        = 0xEA1B,
    BENGALI_L_SSA_TTA       = 0xEA1C,
    BENGALI_L_SA_TTA        = 0xEA1D,
    BENGALI_L_NNA_TTHA      = 0xEA1E,
    BENGALI_L_NA_TTHA       = 0xEA1F,
    BENGALI_L_SSA_TTHA      = 0xEA20,
    BENGALI_L_DDA_DDA       = 0xEA21,
    BENGALI_L_NNA_DDA       = 0xEA22,
    BENGALI_L_NA_DDA        = 0xEA23,
    BENGALI_L_LA_DDA        = 0xEA24,
    BENGALI_L_NNA_DDHA      = 0xEA25,
    BENGALI_L_NA_DDHA       = 0xEA26,
    BENGALI_L_NNA_NNA       = 0xEA27,
    BENGALI_L_SSA_NNA       = 0xEA28,
    BENGALI_L_HA_NNA        = 0xEA29,
    BENGALI_L_KA_TA           = 0xEA2A,
    BENGALI_L_TA_TA           = 0xEA2B,
    BENGALI_L_NA_TA           = 0xEA2C,
    BENGALI_L_PA_TA		    = 0xEA2D,
    BENGALI_L_SA_TA         = 0xEA2E,
    BENGALI_L_TA_THA        = 0xEA2F,
    BENGALI_L_NA_THA        = 0xEA30,
    BENGALI_L_SA_THA        = 0xEA31,
    BENGALI_L_DA_DA         = 0xEA32,
    BENGALI_L_NA_DA         = 0xEA33,
    BENGALI_L_BA_DA         = 0xEA34,
    BENGALI_L_GA_DHA        = 0xEA35,
    BENGALI_L_DA_DHA        = 0xEA36,
    BENGALI_L_NA_DHA        = 0xEA37,
    BENGALI_L_BA_DHA        = 0xEA38,
    BENGALI_L_GA_NA         = 0xEA39,
    BENGALI_L_GHA_NA        = 0xEA3A,
    BENGALI_L_TA_NA         = 0xEA3B,
    BENGALI_L_DHA_NA        = 0xEA3C,
    BENGALI_L_NA_NA         = 0xEA3D,
    BENGALI_L_PA_NA         = 0xEA3E,
    BENGALI_L_MA_NA         = 0xEA3F,
    BENGALI_L_SHA_NA        = 0xEA40,
    BENGALI_L_SA_NA         = 0xEA41,
    BENGALI_L_HA_NA         = 0xEA42,
    BENGALI_L_PA_PA         = 0xEA43,
    BENGALI_L_LA_PA         = 0xEA44,
    BENGALI_L_SSA_PA        = 0xEA45,
    BENGALI_L_SA_PA         = 0xEA46,
    BENGALI_L_MA_PHA        = 0xEA47,
    BENGALI_L_LA_PHA        = 0xEA48,
    BENGALI_L_SSA_PHA       = 0xEA49,
    BENGALI_L_SA_PHA        = 0xEA4A,
    BENGALI_L_YA            = 0xEA4B, /* ligature for YA */
    BENGALI_L_NGA_BA        = 0xEA4C,
    BENGALI_L_JA_RA         = 0xEA4D,
    BENGALI_L_NNA_RA        = 0xEA4E,
    BENGALI_L_JA_BA         = 0xEA4F,
    BENGALI_L_CHA_RA         = 0xEA50,
    BENGALI_L_THA_BA        = 0xEA51,
    BENGALI_L_DA_BA         = 0xEA52,
    BENGALI_L_DHA_BA        = 0xEA53,
    BENGALI_L_NA_BA         = 0xEA54,
    BENGALI_L_BA_BA         = 0xEA55,
    BENGALI_L_MA_BA         = 0xEA56,
    BENGALI_L_LA_BA         = 0xEA57,
    BENGALI_L_SHA_BA        = 0xEA58,
    BENGALI_L_SA_BA         = 0xEA59,
    BENGALI_L_HA_BA         = 0xEA5A,
    BENGALI_L_CA_BA         = 0xEA5B,
    BENGALI_L_DDA_BA        = 0xEA5C,
    BENGALI_L_MA_BHA        = 0xEA5D,
    BENGALI_L_DA_BHA        = 0xEA5E,
    BENGALI_L_KA_MA         = 0xEA5F,
    BENGALI_L_GA_MA         = 0xEA60,
    BENGALI_L_NGA_MA        = 0xEA61,
    BENGALI_L_NNA_MA        = 0xEA62,
    BENGALI_L_TA_MA         = 0xEA63,
    BENGALI_L_NA_MA         = 0xEA64,
    BENGALI_L_MA_MA         = 0xEA65,
    BENGALI_L_LA_MA         = 0xEA66,
    BENGALI_L_SHA_MA        = 0xEA67,
    BENGALI_L_SSA_MA        = 0xEA68,
    BENGALI_L_SA_MA         = 0xEA69,
    BENGALI_L_HA_MA         = 0xEA6A,
    BENGALI_L_KA_RA         = 0xEA6B,
    BENGALI_L_KHA_RA        = 0xEA6C,
    BENGALI_L_GA_RA         = 0xEA6D,
    BENGALI_L_GHA_RA        = 0xEA6E,
/* PMT START MAUI_00029051 */
    BENGALI_L_TTA_NNA       = 0xEA6F,
/* PMT END MAUI_00029051 */
    BENGALI_L_DA_RA         = 0xEA70,
    BENGALI_L_DHA_RA        = 0xEA71,
    BENGALI_L_NCHAND         = 0xEA72,
    BENGALI_L_TA_RA         = 0xEA73,
    BENGALI_L_THA_RA        = 0xEA74,
    BENGALI_L_BA_RA         = 0xEA75,
    BENGALI_L_BHA_RA        = 0xEA76,
    BENGALI_L_PHA_RA        = 0xEA77,
    BENGALI_L_TTA_RA        = 0xEA78,
    BENGALI_L_DDA_RA        = 0xEA79,
    BENGALI_L_HA_RA         = 0xEA7A,
    BENGALI_L_SA_RA         = 0xEA7B,
    BENGALI_L_SHA_RA        = 0xEA7C,
    BENGALI_L_MA_RA         = 0xEA7D,
    BENGALI_L_KA_LA         = 0xEA7E,
    BENGALI_L_GA_LA         = 0xEA7F,
    BENGALI_L_PA_LA         = 0xEA80,
    BENGALI_L_PHA_LA        = 0xEA81,
    BENGALI_L_BA_LA         = 0xEA82,
    BENGALI_L_MA_LA         = 0xEA83,
    BENGALI_L_LA_LA         = 0xEA84,
    BENGALI_L_SHA_LA        = 0xEA85,
    BENGALI_L_SA_LA         = 0xEA86,
    BENGALI_L_HA_LA         = 0xEA87,
    BENGALI_L_KA_SSA        = 0xEA88,
    BENGALI_L_KA_SA         = 0xEA89,
    BENGALI_L_NA_SA         = 0xEA8A,
    BENGALI_L_PA_SA         = 0xEA8B,
    /* Three conjunct Ligatutres */
    BENGALI_L_KA_SSA_MA     = 0xEA8C,
    BENGALI_L_CA_CHA_BA     = 0xEA8D,
    BENGALI_L_CA_CHA_RA     = 0xEA8E,
    BENGALI_L_JA_JA         = 0xEA8F,
    BENGALI_L_NNA_DDA_RA    = 0xEA90,
    BENGALI_L_TA_TA_BA      = 0xEA91,
    BENGALI_L_DA_BHA_RA     = 0xEA92,
    BENGALI_L_NA_TA_BA      = 0xEA93,
    BENGALI_L_NA_TA_RA      = 0xEA94,
    BENGALI_L_NA_DA_RA      = 0xEA95,
    BENGALI_L_NA_DA_BA      = 0xEA96,
    BENGALI_L_MA_PA_RA      = 0xEA97,
    BENGALI_L_MA_BHA_RA     = 0xEA98,
    BENGALI_L_SA_PA_RA      = 0xEA99,
    BENGALI_L_SA_TA_RA      = 0xEA9A,
    BENGALI_L_NA_DHA_RA     = 0xEA9B,
    BENGALI_L_SA_TTA_RA     = 0xEA9C,
    BENGALI_L_SA_TA_BA      = 0xEA9D,
    BENGALI_L_LA_DDA_RA     = 0xEA9E,
    BENGALI_L_SSA_KA_RA     = 0xEA9F,
    BENGALI_L_DDA_BHA_RA     = 0xEAA0,
    BENGALI_L_NA_DDA_RA     = 0xEAA1,
    BENGALI_L_SA_KA_RA      = 0xEAA2,
    BENGALI_L_KA_TTA_RA     = 0xEAA3,
    BENGALI_L_SSA_PA_RA     = 0xEAA4,
    BENGALI_L_DA_DA_RA      = 0xEAA5,
    BENGALI_L_NNA_TTA_RA    = 0xEAA6,
    BENGALI_L_JHA_RA        = 0xEAA7,
    BENGALI_L_JHA_BA        = 0xEAA8,
    BENGALI_L_NYA_BA        = 0xEAA9,
    BENGALI_L_CHA_BA        = 0xEAAA,
    BENGALI_H_RA            = 0xEAAB,
/* PMT START MAUI_00029051 */
    BENGALI_L_KA_PA         = 0xEAAC,
    BENGALI_L_MA_TA         = 0xEAAD,
    BENGALI_L_MA_THA        = 0xEAAE,
    BENGALI_L_KA_SHA        = 0xEAAF,
/* PMT END MAUI_00029051 */
    BENGALI_L_MA_PA         = 0xEAB0,
    BENGALI_L_DA_MA         = 0xEAB1,
    BENGALI_L_TA_BA         = 0xEAB2,
    BENGALI_L_YA_BA         = 0xEAB3,
    BENGALI_L_BHA_BA        = 0xEAB4,
    BENGALI_L_NYA_RA        = 0xEAB5,
/* PMT START MAUI_00027782 */
    BENGALI_L_H_SHA         = 0xEAB6,
    BENGALI_L_H_NA	    = 0xEAB7,
    BENGALI_L_H_GA	    = 0xEAB8,
    BENGALI_L_H_PA	    = 0xEAB9,
    BENGALI_L_H_NNA	    = 0xEABA,
    BENGALI_L_H_LA	    = 0xEABB,
    BENGALI_L_H_SA	    = 0xEABC,
    BENGALI_L_H_SSA	    = 0xEABD,
    BENGALI_L_H_AF_LA       = 0xEABE,
    BENGALI_L_H_AF_NA       = 0xEABF,
    BENGALI_L_H_AF_MA       = 0xEAC0,
/* PMT START MAUI_00029051 */
    BENGALI_L_RA	    = 0xEAC1,
    BENGALI_L_TA_NNA	    = 0xEAC2,
/* PMT END MAUI_00029051 */
    BENGALI_L_H_AF_BA       = 0xEAC3,
    BENGALI_L_M_U	    = 0xEAC4,
    BENGALI_L_M_UU	    = 0xEAC5,
/* PMT START MAUI_00029051 */
    BENGALI_L_DDA_GA        = 0xEAC6
/* PMT END MAUI_00029051 */
/* PMT END MAUI_00027782 */
}bengali_ligatures_enum;


#if defined (__MMI_MULTITAP_BENGALI__)
/* PMT START ZI */ 
#if defined(__MMI_ZI_BENGALI__)
    extern const UI_character_type default_bengali_multitap_strings[MAX_MULTITAPS][45];
    extern const UI_character_type default_bengalimatra_multitap_strings[MAX_MULTITAPS][45];
    extern const UI_character_type default_bengalimatra1_multitap_strings[MAX_MULTITAPS][45];
#else
    extern const UI_character_type default_bengali_multitap_strings[MAX_MULTITAPS][32];
    extern const UI_character_type default_bengalimatra_multitap_strings[MAX_MULTITAPS][32];
    extern const UI_character_type default_bengalimatra1_multitap_strings[MAX_MULTITAPS][32];
#endif
/* PMT END ZI */


extern UI_character_type *get_bengali_multitap_string(S32 i);
extern UI_string_type get_bengali_single_line_multitap_string(S32);
#endif
#endif
#endif


