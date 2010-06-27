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
 *    Tamil.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    c file of tamil font rule 
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

#if defined (__MMI_LANG_TAMIL__) 

#define IRE_TAMIL_LANG_START_RANGE			0x0B80
#define IRE_TAMIL_LANG_END_RANGE			0x0BFA
#define IRE_TAMIL_PROPRIETRY_START_RANGE	0xEE00
#define IRE_TAMIL_PROPRIETRY_END_RANGE		0xEEFF


typedef enum
{
	/* VARIOUS SIGNS + INDEPENDENT VOWEL */
    
    TAMIL_S_VISARGA			= 0xb83,
    TAMIL_IV_A				= 0xb85,
    TAMIL_IV_AA				= 0xb86,
    TAMIL_IV_I				= 0xb87,
    TAMIL_IV_II				= 0xb88,
    TAMIL_IV_U				= 0xb89,
    TAMIL_IV_UU				= 0xb8a,
  
	TAMIL_IV_E				= 0xb8e,
	TAMIL_IV_EE				= 0xb8f,
    TAMIL_IV_AI				= 0xb90,
    TAMIL_IV_O				= 0xb92,
    TAMIL_IV_OO				= 0xb93,
    TAMIL_IV_AU				= 0xb94,

    /* CONSONANTS */
    TAMIL_C_KA				= 0xb95,
    TAMIL_C_NGA				= 0xb99,
    TAMIL_C_CHA				= 0xb9a,
    TAMIL_C_JA				= 0xb9c,
    TAMIL_C_NYA				= 0xb9e,
    TAMIL_C_TTA				= 0xb9f,   
    TAMIL_C_NNA				= 0xba3,
    TAMIL_C_TA				= 0xba4,
    TAMIL_C_NA				= 0xba8,
    TAMIL_C_NNNA			= 0xba9,
    TAMIL_C_PA				= 0xbaa,
    TAMIL_C_MA				= 0xbae,
    TAMIL_C_YA				= 0xbaf,
    TAMIL_C_RA				= 0xbb0,
	TAMIL_C_RRA				= 0xbb1,
    TAMIL_C_LA				= 0xbb2,
    TAMIL_C_LLA				= 0xbb3,
    TAMIL_C_LLLA			= 0xbb4,
    TAMIL_C_VA				= 0xbb5,
    TAMIL_C_SSA				= 0xbb7,
    TAMIL_C_SA				= 0xbb8,
    TAMIL_C_HA				= 0xbb9,
    


    /* DEPENDENT VOWELS */
    TAMIL_DV_AA			= 0xbbe,
    TAMIL_DV_I			= 0xbbf,
    TAMIL_DV_II			= 0xbc0,
    TAMIL_DV_U			= 0xbc1,
	TAMIL_DV_UU			= 0xbc2,
    TAMIL_DV_E			= 0xbc6,
	TAMIL_DV_EE			= 0xbc7,
    TAMIL_DV_AI			= 0xbc8,
    TAMIL_DV_O			= 0xbca,
	TAMIL_DV_OO			= 0xbcb,
    TAMIL_DV_AU			= 0xbcc,

    /* SIGNS */
    TAMIL_S_HALANT		= 0xbcd,
    
	/* APPEND DEPENDENT VOWEL */
    TAMIL_AD_AU			= 0xbd7,

    /* DIGITS */
    TAMIL_D_ZERO		= 0xbe6,
    TAMIL_D_ONE			= 0xbe7,
    TAMIL_D_TWO			= 0xbe8,
    TAMIL_D_THREE		= 0xbe9,
    TAMIL_D_FOUR		= 0xbea,
    TAMIL_D_FIVE		= 0xbeb,
    TAMIL_D_SIX			= 0xbec,
    TAMIL_D_SEVEN		= 0xbed,
    TAMIL_D_EIGHT		= 0xbee,
    TAMIL_D_NINE		= 0xbef,

	/* TAMIL NUMERICS */
	TAMIL_D_TEN			= 0xbf0,
	TAMIL_D_HUNDRED		= 0xbf1,
	TAMIL_D_THOUSAND	= 0xbf2,

	/* TAMIL SYMBOLS */
	TAMIL_OS_DAY		= 0xbf3,
	TAMIL_OS_MONTH		= 0xbf4,
	TAMIL_OS_YEAR		= 0xbf5,
	TAMIL_OS_DEBIT		= 0xbf6,
	TAMIL_OS_CREDIT		= 0xbf7,
	TAMIL_OS_ABOVE		= 0xbf8,

	/* CURRENCY SYMBOL */
	TAMIL_OS_RUPEE		= 0xbf9,

	/* TAMIL SYMBOLS */
	TAMIL_OS_NUMERNAL	= 0xbfa
    
}tamil_characters_enum;

typedef enum
{
    /* various ligature etc */
    TAMIL_L_KU				= 0xee01,
	TAMIL_L_KUU				= 0xee02,
	TAMIL_L_NGU				= 0xee03,
	TAMIL_L_NGUU			= 0xee04,
	TAMIL_L_CHU				= 0xee05,
	TAMIL_L_CHUU			= 0xee06,
	TAMIL_L_NYU				= 0xee07,
    TAMIL_L_TTI				= 0xee08,
	TAMIL_L_TTII			= 0xee09,	
	TAMIL_L_TTU				= 0xee0A,
	TAMIL_L_TTUU			= 0xee0B,
	TAMIL_L_NNU 			= 0xee0C,
	TAMIL_L_TU				= 0xee0D,
	TAMIL_L_NU  			= 0xee0E,
	TAMIL_L_NNNU			= 0xee0F,
	TAMIL_L_PU				= 0xee10,
	TAMIL_L_PUU				= 0xee11,
	TAMIL_L_MU				= 0xee12,
	TAMIL_L_MUU				= 0xee13,
	TAMIL_L_YU				= 0xee14,
	TAMIL_L_YUU				= 0xee15,
	TAMIL_L_RI				= 0xee16,
    TAMIL_L_RII				= 0xee17,		
	TAMIL_L_RU				= 0xee18,
	TAMIL_L_RUU				= 0xee19,
	TAMIL_L_RRU				= 0xee1A,
	TAMIL_L_LU				= 0xee1B,
	TAMIL_L_LLU				= 0xee1C,
	TAMIL_L_LLUU			= 0xee1D,	
	TAMIL_L_LLLU			= 0xee1E,
	TAMIL_L_LLLUU			= 0xee1F,
	TAMIL_L_VU				= 0xee20,
	TAMIL_L_VUU				= 0xee21,
	TAMIL_L_SHREE			= 0xee22,	
	TAMIL_L_RA_HALANT		= 0xee23,	
	TAMIL_L_APP_UU			= 0xee24,
	TAMIL_L_PA_HALANT		= 0xee25,
	TAMIL_L_RRA_HALANT		= 0xee26,
	TAMIL_L_KSHA			= 0xee27,
	TAMIL_L_KI				= 0xEE28,
	TAMIL_L_KII				= 0xee29,
	TAMIL_L_NGI		  		= 0xee2a,
	TAMIL_L_NGII			= 0xee2b,
	TAMIL_L_CHI				= 0xee2c, 
	TAMIL_L_CHII			= 0xee2d,	
	TAMIL_L_JI				= 0xee2e,
	TAMIL_L_JII				= 0xee2f,
	TAMIL_L_NYI				= 0xee30,
	TAMIL_L_NYII			= 0xee31,
	TAMIL_L_NNI				= 0xee32,
	TAMIL_L_NNII			= 0xee33,
	TAMIL_L_TI				= 0xee34,
	TAMIL_L_TII				= 0xee35,
	TAMIL_L_NI				= 0xee36,
	TAMIL_L_NII				= 0xee37,
	TAMIL_L_NNNI			= 0xee38,
	TAMIL_L_NNNII			= 0xee39,
	TAMIL_L_PI				= 0xee3a,
	TAMIL_L_PII				= 0xee3b,
	TAMIL_L_MI				= 0xee3c,
	TAMIL_L_MII				= 0xee3d,
	TAMIL_L_YI				= 0xee3e,
	TAMIL_L_YII				= 0xee3f,	
	TAMIL_L_RRI				= 0xee40,
	TAMIL_L_RRII			= 0xee41,	
	TAMIL_L_LI				= 0xee42,
	TAMIL_L_LII				= 0xee43,
	TAMIL_L_LLI				= 0xee44,
	TAMIL_L_LLII			= 0xee45,
	TAMIL_L_LLLI			= 0xee46,
	TAMIL_L_LLLII			= 0xee47,
	TAMIL_L_VI				= 0xee48,
	TAMIL_L_VII				= 0xee49,
	TAMIL_L_KSHI			= 0xee4a,
	TAMIL_L_KSHII			= 0xee4b,
	TAMIL_L_SSI				= 0xee4c,
	TAMIL_L_SSII			= 0xee4d,
	TAMIL_L_SI				= 0xee4e,
	TAMIL_L_SII				= 0xee4f,
	TAMIL_L_HI				= 0xee50,
	TAMIL_L_HII				= 0xee51
}tamil_ligatures_enum;




#if defined (__MMI_MULTITAP_TAMIL__) 

/* Following Arrays are use to insert character according tamil grammar rules  */

/* PMT START ZI */
#if defined (__MMI_ZI_TAMIL__)
    extern const UI_character_type default_tamil_multitap_strings[MAX_MULTITAPS][42];
    extern const UI_character_type default_tamilmatra_multitap_strings[MAX_MULTITAPS][42];
    extern const UI_character_type default_tamilmatra1_multitap_strings[MAX_MULTITAPS][42];
#else
    extern const UI_character_type default_tamil_multitap_strings[MAX_MULTITAPS][32];
    extern const UI_character_type default_tamilmatra_multitap_strings[MAX_MULTITAPS][32];
    extern const UI_character_type default_tamilmatra1_multitap_strings[MAX_MULTITAPS][32];
#endif
/* PMT END ZI */

/*Following functions are use for multitab */
extern UI_character_type *get_tamil_multitap_string(S32 i);
extern UI_string_type get_tamil_single_line_multitap_string(S32);

#endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */
#endif /* MMI_LANG_TAMIL */

