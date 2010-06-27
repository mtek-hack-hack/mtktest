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
 *    IndicRuleEngine.h
 *
 * Project:
 * --------
 *   Indic Languages
 *
 * Description:
 * ------------
 *   header file of Indic language engine 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/




#ifndef MMI_INDIC_RULE_ENGINE_H
#define MMI_INDIC_RULE_ENGINE_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "IndicEngineGprot.h"
#include "SSCStringHandle.h"

/**************			GLOBAL DEFINITION			*********************/

/*global pointer variable to hold the character info*/
U32 *g_character_status_flag_p  =	0;

/*global structure pointer which points to character info structure */
const ire_character_info_table_struct *g_lang_character_info_p;

/**************			EXTERN DEFINITION			*********************/

extern BOOL r2lMMIFlag;

/* PMT RAKESH END 20061006 */
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
const HindiRulesLangSSC HRLangSSC[] = 
{
    {SSC_HINDI, MMI_HINDI_LANG},
    {SSC_MARATHI, MMI_MARATHI_LANG},
};
indic_rules_ligature_enum hf_rules_current_set_language;
indic_rules_ligature_enum hf_rules_prefered_set_language;

/**************			MACROS DEFINITION			*********************/



#define NORMAL_CON							0x00000001
#define RA_CON								0x00000002
#define SMALL_CON							0x00000003
#define ALL_CONSONANT_TYPE					(NORMAL_CON | RA_CON | SMALL_CON)

#define PRE_BASE_DEPVOWEL					0x00000008
#define POST_BASE_DEPVOWEL					0x00000010
#define BELOW_BASE_DEPVOWEL					0x00000018
#define ABOVE_BASE_DEPVOWEL					0x00000020
#define CENTER_BASE_DEPVOWEL				0x00000028
/* START PMT PUNJABI TELUGU */
#define ABOVE_BASE_NORMAL_CON               0x00003001
#define BELOW_BASE                          0x00004000
/* END PMT PUNJABI TELUGU */

#define INDEPVOWEL							0x00000040

#define HALANT								0x00000080
#define NORMALSIGN							0x00000100

#define LIGATURE							0x00000200
#define DIGITS								0x00000800

#define IS_VALID_SIGN						0x00003000
#define MASK_HIGHER_ORDER_BYTES				0x00000FFF

#define TAMIL_HALANT_SIGN					0x00000180

#define  TWO								2
/*	To Convert U8 to U16 (unicode value) */
#define IRE_LANG_ID_CONVERT_U8_U16(pCharacter) ((pCharacter)[0]|((pCharacter)[1]<<8))

/*	To Convert previous val U8 to U16 (unicode value) */
#define IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(pCharacter) ((pCharacter - 2)[0]|((pCharacter - 2)[1]<<8))

/*	To Convert next value U8 to U16 (unicode value) */
#define IRE_LANG_ID_CONVERT_NEXT_VAL_U8_U16(pCharacter) ((pCharacter + 2)[0]|((pCharacter + 2)[1]<<8))


/*to check whether the current character lies in the language range*/
#define  IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(start_cluster,character,startRange,endRange,nFill)\
{\
	if((character<startRange) || (character>endRange))\
	{\
		start_cluster[nFill] = (U16)NULL;\
		g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);\
		return nFill;\
	}\
}

#define IRE_LANG_ID_FILL_CLUSTER_SMALL_CONS()						\
{																	\
   ++nFill;															\
   start_char+=2;													\
   g_indic_rule_engine_cntx.g_display_buffer_len++;					\
}
/*	fills the temporary buffer with unicode values,
	increment the array index and start character pointer	*/
#define IRE_LANG_ID_FILL_CLUSTER()									\
{																	\
   start_cluster[nFill] = IRE_LANG_ID_CONVERT_U8_U16(start_char);   \
   ++nFill;															\
   start_char+=2;													\
   g_indic_rule_engine_cntx.g_display_buffer_len++;					\
}                                           

#define IRE_LANG_ID_END_CLUSTER(start_cluster,start_char,nFill)	\
{																\
	if( start_char == g_indic_rule_engine_cntx.g_cluster_end_p)	\
	{															\
		start_cluster[nFill] = (U16)NULL;						\
		g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	\
		return nFill;											\
	}															\
}

/*to check whether the current character lies in the language range*/
#define  IRE_CHECK_CHARACTER_LANG_RANGE(character,startRange,endRange)  ( ((character<startRange )|| (character>endRange))? (0) : (1) )


/*macro to fill the global structure variable with full character info*/
#define IRE_IDENTIFY_CHARACTER(character,char_status_flag_p,startRange,mCharacterStatusFlag)\
{\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - startRange)-1);\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= mCharacterStatusFlag &	MASK_HIGHER_ORDER_BYTES;\
}

/*Con + Hal + Con2+  PreBase M -> Prebase M + Con + Hal + Con2  */
/*Con + PreBase M -> Prebase M + Con */
#define IRE_REORDER_PREBASE_MATRA(nEntries,tempCount,uTempVar)\
{\
	uTempVar = start_cluster[nEntries - 1];\
	for (tempCount = nEntries - 2; tempCount >= 0; tempCount--)\
	{\
		start_cluster[tempCount + 1] = start_cluster[tempCount];\
	}\
	start_cluster[0] = uTempVar;\
}


/*Ra + Hal + Con + PostBase M -> Con + Postbase M + Ra + Hal*/
/*Ra + Hal + Con -> Con + Ra + Hal*/
#define IRE_REORDER_RA_HALANT_CONS_SEQUENCE(nEntries,tempCount,uTempVar,i)\
{\
	for (i = 0; i <= 1; i++)\
	{\
		uTempVar = start_cluster[0];\
		for (tempCount = 0; tempCount < nEntries - 1; tempCount++)\
		{\
			start_cluster[tempCount] = start_cluster[tempCount + 1];\
		}\
		start_cluster[tempCount] = uTempVar;\
	}\
} 


/*Ra + Hal + Con + Hal -> */
/*Ra + Hal + Con + Hal + Con + Hal -> */
#define IRE_REORDER_RA_HALANT_CONS_HALANT_SEQUENCE(nEntries,tempCount,uTempVar,i)\
{\
	uTempVar = start_cluster[nEntries - 1];\
	for (i = 0; i <= 1; i++)\
	{\
		g_indic_rule_engine_cntx.g_temp_array[0] = start_cluster[0];\
		for (tempCount = 0; tempCount < nEntries - 2; tempCount++)\
		{\
			start_cluster[tempCount] = start_cluster[tempCount + 1];\
		}\
		start_cluster[tempCount] = g_indic_rule_engine_cntx.g_temp_array[0];\
	}\
	start_cluster[nEntries - 1] = uTempVar;\
}

/*CON1 + CenterBase M - > Pre + CON1 + Post*/
/* START PMT PATCH04052007 */
#define IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster,nFill,char_table_p,uTempVar,size,tempCount)\
{\
	uTempVar = start_cluster[nFill - 1];\
	for (tempCount = nFill - 2; tempCount >= 0; tempCount--)\
	{\
		start_cluster[tempCount + 1] = start_cluster[tempCount];\
	}\
	start_cluster[0]		        = char_table_p[size].output_buffer_glyph[0];\
	start_cluster[nFill]			= uTempVar;\
	start_cluster[nFill + 1]		= char_table_p[size].output_buffer_glyph[1];\
	start_char+=2;\
	nFill++;\
}

/*CON1 + Hal + CON2 - > CON1 + CON2 + Hal*/
#define IRE_REORDER_SMALL_CONS_HAL_CONS(nEntries,tempCount,uTempVar)\
{\
	uTempVar = start_cluster[1];\
	for (tempCount = 1; tempCount < nEntries - 1; tempCount++)\
	{\
		start_cluster[tempCount] = start_cluster[tempCount + 1];\
	}\
	start_cluster[tempCount] = uTempVar;\
}

/*CON1 + Hal + CON2 + PostBase M- > CON1 + PostBase M + CON2 + Hal*/
/*CON1 + Hal + CON2 + Hal + CON3 + PostBase M- > CON1 + PostBase M + CON2 + Hal + CON3 + Hal*/
/* START PMT PUNJABI TELUGU */
#define IRE_REORDER_SMALL_CON_POST_BASE_MATRA(nEntries,tempCount,uTempVar,i)\
{\
	for (tempCount = 1; tempCount <= nEntries - 2; tempCount++)\
	{\
		uTempVar = start_cluster[nEntries - tempCount ];\
        start_cluster[nEntries - tempCount] = start_cluster[nEntries - tempCount - 1];\
		start_cluster[nEntries - tempCount - 1 ] = uTempVar;\
	}\
}
/* END PMT PUNJABI TELUGU */

/**************			TYPEDEF'S DEFINITION			*********************/

/*Different language Id's */
typedef enum 
{
	IRE_LANGUAGE_ID_INVALID						= 0x00,
	IRE_LANGUAGE_ID_HINDI						= 0x01,	
    IRE_LANGUAGE_ID_BENGALI						= 0x02,
    IRE_LANGUAGE_ID_PUNJABI						= 0x03,
    IRE_LANGUAGE_ID_GUJRATI						= 0x04,
    IRE_LANGUAGE_ID_ORIYA						= 0x05,
    IRE_LANGUAGE_ID_TAMIL						= 0x06, 
    IRE_LANGUAGE_ID_TELUGU						= 0x07,
    IRE_LANGUAGE_ID_KANNADA						= 0x08,
    IRE_LANGUAGE_ID_MALAYALAM					= 0x09,
    IRE_LANGUAGE_ID_SINHALA						= 0x0A,
	IRE_LANGUAGE_ID_MARATHI						= 0x0B,
	IRE_LANGUAGE_ID_ENGLISH						= 0x0C,
    /*
	 *
	 * Add any new language id here
	 *
	 */
	IRE_LANGUAGE_ID_MAX	

}ire_language_id_enum;


#endif //MMI_INDIC_RULE_ENGINE_H
