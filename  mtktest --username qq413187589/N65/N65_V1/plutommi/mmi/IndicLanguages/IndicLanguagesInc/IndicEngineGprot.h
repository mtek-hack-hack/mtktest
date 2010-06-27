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
 *    IndicEngineGprot.h
 *
 * Project:
 * --------
 *   Languages
 *
 * Description:
 * ------------
 *   Header file of Indic language Engine 
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

#ifndef MMI_INDIC_ENGINE_GPROT_H
#define MMI_INDIC_ENGINE_GPROT_H


#include "MMI_features.h"
#include "MMIDataType.h"
#include "IndicRuleEngineCommon.h"
/*PMT START MAUI_00530728 */
extern single_line_input_box MMI_inline_singleline_inputbox;
extern UI_character_type gui_EMS_current_character(UI_EMS_input_box *b);
extern UI_character_type gui_multi_line_current_character(multi_line_input_box *b);
extern UI_character_type gui_single_line_current_character(single_line_input_box *b);

/*PMT END MAUI_00530728 */

struct ire_g_context_struct
{
	S32 g_prev_char_text_x;
	S32 g_prev_char_dwidth;
	S32 g_prev_char_width;
	S32 g_prev_char_btext_x;
	S32 g_prev_char_bdwidth;
	S32 g_new_bline;
	S32 g_use_multitap;
	S32 g_reset_hindi_pms;
	S32 g_indic_padding;
	S32 g_new_line;
	S32 parse_hindi;
	S32 g_display_buffer_len;
	S32 g_ire_arabic_language_character_count;
	S32 g_ire_indic_language_character_count;
	U16 g_temp_array[10];
	U16 g_prev_character;
	PU8 g_cursor_end_curr_cluster_p;
	PU8 g_cluster_start_p;
	PU8 g_cluster_end_p;
	PU8	padding_val;
	/* START PMT PUNJABI TELUGU */
	U32 small_cons;
	U32 small_cons_halant_present;
	/* PMT START MAUI_00415927 */
	#if defined ( __MMI_BIDI_ALG__ ) && defined ( __MMI_INDIC_ALG__ )
	U32 zi_check_for_singleline;
	#endif
	/* PMT START MAUI_00027833 */
	U32 error_correction_for_rendering;      
	/* PMT END MAUI_00027833 */

	/* PMT END MAUI_00415927 */
	/* END PMT PUNJABI TELUGU */
};

extern struct ire_g_context_struct g_indic_rule_engine_cntx;

/*********************	EXTERN DEFINITIONS	*******************************/


/*This method will identify the characters which will participate in cluster formation */
extern S32 ire_get_cluster(PU16 buffer);

/*This method will search for the next cluster and returns the pointer to the begining of the cluster*/
extern PU8 ire_get_next_cluster_p(PU8 previous_cursor_p, PU8 current_cursor_p);

/*This method will find the current cluster and	copy it into the output buffer*/
extern S32 ire_get_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, PU16 output_buffer);

/*This method checks the input unicode value and returns the correponding language Id*/
extern U32 ire_get_character_lang_id(U16 character);

/*This method will return the size of cluster in numbers of pixels*/
extern S32 ire_size_of_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, U16 cursor);

/*This method will apply grammer rules on the input cluster buffer and copy the output buffer i.e glyphoutput*/
extern S32 ire_language_rules(PU16 glyphoutput, PU16 cluster, S32 nentry);

/*This method will find the length of cluster (special case CON + HALANT + CON + HALANT.......)*/
//extern S32 ire_get_consonant_cluster(PU16 *start_cluster, PU8 *start_char, S32 nentry);

//extern S32 ire_get_small_cons_cluster(PU16 *start_cluster, PU8 *startchar, S32 nentry);

/*This method will search the previous cluster and returns the pointer to the begining of cluster*/
extern PU8 ire_get_prev_cluster_p(PU8 text_p, PU8 cursor_p);

/*This method will calculate the width and height of the the input text*/
extern S32 ire_get_string_width_height(UI_string_type text);

/*This method will calculate the width, dwidth based upon the type of input characters*/
extern void ire_get_text_x(PS32, U16, S32, U16, U16);
/**/
extern void ire_get_multitap_text_x(S32 *ptext_x, U16 current_character, S32 Char_Range, S32 check_char);
/**/
extern void ire_get_bordered_text_x(PS32, U16, S32);

/*This method will apply the language rules on the input string*/
extern void ire_get_indic_rules_for_whole_string(PU8 String);

/*This method will identify the character type like consonant, dep vowel etc*/
extern S32 ire_identify_character_type(U16 currentCharacter);

/*This method will identify the character whether it belongs to sign category or not*/
extern S32 ire_identify_sign_range(U16 currentCharacter);

extern S32 ire_identify_char_small_consonant_family(U16 currentCharacter);
extern S32 ire_is_character_ext_consonant_capable(U16 prevCharacter) ;
extern S32 ire_is_character_nukta(U16 currentCharacter); 

/* PMT START MAUI_00027833 */
/* This method identifies for rendering correction and adds delta correction only for signs*/
extern void ire_small_con_rendering_correction(U16 previous_unicode);
/* PMT START MAUI_00027833 */
/**/
extern UI_character_type *get_marathi_multitap_string(S32);
/**/
extern UI_string_type get_marathi_single_line_multitap_string(S32);

/**/
#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
extern void overwrite_current_language_for_hindi_rules_based_on_input_method(void);

/*This method will set the current language*/
extern void set_current_language_for_hindi_rules(void);

/*This method will restore the current language and update the flag*/
extern void restore_current_language_for_hindi_rules(void);
#endif


/*********************	MACRO DEFINITIONS	*******************************/

#define  ire_init_cluster_start_p(buffer)\
{\
	g_indic_rule_engine_cntx.g_cluster_start_p = buffer;\
}

#define ire_init_cluster_end_p(buffer)\
{\
	g_indic_rule_engine_cntx.g_cluster_end_p = buffer;\
}

/* MTI START MAUI_00038534 */
#define ire_get_cluster_start_p() g_indic_rule_engine_cntx.g_cluster_start_p
#define ire_increment_cluster_start_p(value) g_indic_rule_engine_cntx.g_cluster_start_p += value;
/* MTI END MAUI_00038534 */

#define IRE_IS_CHAR_TYPE_CONSONANT(ch)	(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_CON)			? (1) : (0)

#define IRE_IS_CHAR_TYPE_DEP_VOWEL(ch)	(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_DEPVOWEL)	? (1) : (0)

#define IRE_IS_CHAR_TYPE_INDEP_VOWEL(ch) (ire_identify_character_type(ch) == IRE_CHAR_TYPE_INDEPVOWEL)	? (1) : (0)

#define IRE_IS_CHAR_TYPE_SIGN(ch)		(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_SIGN)		? (1) : (0)

#define IRE_IS_CHAR_TYPE_HALANT(ch)		(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_HALANT)		? (1) : (0)

#define IRE_IS_CHAR_TYPE_DIGIT(ch)		(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_DIGIT)		? (1) : (0)

#define IRE_IS_CHAR_TYPE_LIGATURE(ch)	(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_LIGATURE)	? (1) : (0)

#define IRE_UI_INDIC_SIGN_RANGE(ch)		(ire_identify_sign_range(ch)) ? (1) : (0)

/*To check whether the character lies in the Indic language range*/
#define IRE_INDIC_LANGUAGE_RANGE(ch)   ( ((U16)(ch)>=0x0900 && (U16)(ch)<=0x0DF4)?(1) : (0) )

#define IRE_GET_CHARACTER_LANG_ID(unicode)  ire_get_character_lang_id(unicode)
#define IRE_IS_CHAR_SIGN_CONSONANT(ch)  (ire_identify_char_small_consonant_family(ch) == IRE_CHAR_TYPE_SIGN_CONSONANT) ?(1) : (0)
#define IRE_IS_CHAR_NORMAL_CONSONANT(ch)  (ire_identify_char_small_consonant_family(ch) == IRE_CHAR_TYPE_NORMAL_CONSONANT) ?(1) : (0)
#define IRE_IS_CHAR_SPECIAL_SIGN(ch)   (ire_identify_char_small_consonant_family(ch)    == IRE_CHAR_TYPE_SPECIAL_SIGN) ?(1) : (0)
#define IRE_IS_CHAR_EXT_CONSONANT_CAPABLE(ch) ire_is_character_ext_consonant_capable(ch)
#define IRE_IS_CHAR_NUKTA(ch) ire_is_character_nukta(ch)
/* PMT START MAUI_00419974 */
#define IRE_INDIC_CHARACTER_UCS2_RANGE(x)     ( (((U16)(x) > 0x900)&&((U16)(x) < 0x0DF4) || ((U16)(x)>59647 && (U16)(x)<61010))?(1) : (0) )
/* PMT END MAUI_00419974 */
/* PMT START MAUI_00031694 */
/* PMT START ZI */
#define IRE_IS_PREV_CURR_SAME_LANG(PREV,CURR) ((PREV & 0xff80) ^ (CURR & 0xff80))? 0:1
#if !defined (NEPTUNE_MMI) && (defined(__MMI_ZI_HINDI__) || defined(__MMI_ZI_MARATHI__) || defined(__MMI_ZI_BENGALI__) || defined(__MMI_ZI_PUNJABI__) || defined(__MMI_ZI_TAMIL__) || defined(__MMI_ZI_TELUGU__)) 
extern U8 ire_IsValidInput(U16* Unicode, U8);
#endif
/* PMT END ZI */
/* PMT END MAUI_00031694 */

#define  ire_get_display_buffer_len()					g_indic_rule_engine_cntx.g_display_buffer_len				
#define ire_reset_use_multitap()						g_indic_rule_engine_cntx.g_use_multitap=0
#define ire_set_use_multitap_multi_line()				g_indic_rule_engine_cntx.g_use_multitap=1
#define ire_set_use_multitap_single_line()				g_indic_rule_engine_cntx.g_use_multitap=2
/*PMT START MAUI_00530728 */
#define ire_set_use_multitap_inline_single_line()	    g_indic_rule_engine_cntx.g_use_multitap=3
/*PMT END MAUI_00530728 */ 
#define ire_current_input_box_type()						g_indic_rule_engine_cntx.g_use_multitap
#define ire_disable_indic_rules_parsing()				g_indic_rule_engine_cntx.parse_hindi=1
#define ire_enable_indic_rules_parsing()				g_indic_rule_engine_cntx.parse_hindi=0
#define ire_is_indic_rules_parsing()					(!(g_indic_rule_engine_cntx.parse_hindi))
#define ire_disable_indic_reset_hindi_params()			g_indic_rule_engine_cntx.g_reset_hindi_pms=1
#define ire_enable_indic_reset_indic_params()			g_indic_rule_engine_cntx.g_reset_hindi_pms=0
#define ire_is_reset_indic_params()						(!(g_indic_rule_engine_cntx.g_reset_hindi_pms))
#define ire_indic_padding_value(val)					g_indic_rule_engine_cntx.g_indic_padding=val;
#define ire_indic_padding_def_value()					g_indic_rule_engine_cntx.g_indic_padding=0;

/* PMT START MAUI_00415927 */
#if defined ( __MMI_BIDI_ALG__ ) && defined ( __MMI_INDIC_ALG__ )
#define ire_check_arabic_and_indic()                     g_indic_rule_engine_cntx.zi_check_for_singleline
#define ire_reset_check_arabic_and_indic()			   g_indic_rule_engine_cntx.zi_check_for_singleline = 0;	
#define ire_set_check_arabic_and_indic()			       g_indic_rule_engine_cntx.zi_check_for_singleline = 1;
#endif
/* PMT END MAUI_00415927 */

#define ire_reset_indic_bordered_params()\
							{\
                                g_indic_rule_engine_cntx.g_prev_char_btext_x = 0;\
                                g_indic_rule_engine_cntx.g_prev_char_bdwidth = 0;\
                                g_indic_rule_engine_cntx.g_new_bline         = 1;\
							}

#define ire_reset_indic_params()\
						   {\
							   g_indic_rule_engine_cntx.g_prev_char_text_x	= 0;\
                               g_indic_rule_engine_cntx.g_prev_char_dwidth	= 0;\
                               g_indic_rule_engine_cntx.g_prev_char_width	= 0;\
                               g_indic_rule_engine_cntx.g_prev_character	= 0;\
                               g_indic_rule_engine_cntx.g_new_line          = 0;\
						   }

/* PMT START MAUI_00027833 */
#define IRE_IS_RENDERING_CORRECTION() g_indic_rule_engine_cntx.error_correction_for_rendering
#define IRE_RESET_RENDERING_CORRECTION() g_indic_rule_engine_cntx.error_correction_for_rendering = 0
#define IRE_GET_RENDERING_CORRECTION() g_indic_rule_engine_cntx.error_correction_for_rendering
#define IRE_SET_RENDERING_CORRECTION(ch) g_indic_rule_engine_cntx.error_correction_for_rendering = ch
/* PMT END MAUI_00027833 */

#endif /*End of MMI_INDIC_ENGINE_GPROT_H*/




/*************Bit pattern definition of gLangStatusFlag********/
/*
	
	MSB........................................................LSB
	15	14	13	12	11	10	9	8	7	6	5	4	3	2	1	0 
	.	.	.	.	.	.	.	.	.	.	.	.	.								
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	0	0		-	INVALID_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	0	1		-	IRE_NORMAL_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	1	0		-	IRE_SPECIAL_RA_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	1	1		-	IRE_SMALL_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	0	0		-
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	0	1		-
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	1	0		-
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	1	1		-
	.	.	.	.	.	.	.	.	.	.	.	.	.
	.	.	.	.	.	.	.	.	.	.	.	.	.  
	.	.	.	.	.	.	.	.	.		0	0	0					-	INVALID_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	0	0	1					-	IRE_PRE_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	0	1	0					-	IRE_POST_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	0	1	1					-	IRE_BELOW_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	1	0	0					-	IRE_ABOVE_BASE_DEP_VOWEL
	.	.	.		.	.	.	.	.		1	0	1					-	IRE_CENTER_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	1	1	0					-	IRE_MAX_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	1	1	1					-
	.	.		.	.	.	.	.	.	.
	.	.	.	.	.	.	.	.	.	0								-	IRE_INVALID_INDEP_VOWEL
	.	.	.	.	.	.	.	.	.	1								-	IRE_INDEP_VOWEL
	.	.	.	.	.	.	.	.	.								
	.	.	.	.	.	.	.	0	0									-	IRE_INVALID_SIGN
	.	.	.	.	.	.	.	0	1									-	IRE_HALANT_SIGN
	.	.	.	.	.	.	.	1	0									-	IRE_NORMAL_SIGN
	.	.	.	.	.	.	.	1	1									-	IRE_TAMIL_HAL_SIGN
	.	.	.	.	.	.	.
	.	.	.	.	.
	.	.	.	.	.	0	0											-	IRE_INVALID_LIGATURE
	.	.	.	.	.	0	1											-	IRE_NORMAL_LIGATURE
	.	.	.	.	.													
	.	.	.	.	0													-	IRE_INVALID_DIGIT
	.	.	.	.	1													-	IRE_NUMERIC_DIGIT
	.	.	.
	0	0	0	0														-   IRE_NO_POSITION			
	0	0	0	1														-	IRE_PREBASE_POSITION	
	0	0	1	0														-	IRE_POSTBASE_POSITION	
	0	0	1	1														-	IRE_ABOVE_BASE_POSITION	
	0	1	0	0														-	IRE_BELOW_BASE_POSITION	
	0	1	0	1														-	IRE_CENTER_BASE_POSITION
	0	1	1	0														-	IRE_MAX_POSITION		
	0	1	1	1														-

	MSB........................................................LSB		
	31	30	29	28	27	26	25	24	23	22	21	20	19	18	17	16
												
												0	0	0	0	0		- padding
												0	0	0	0	1
												.	.	.	.	.
												.	.	.	.	.
												.	.	.	.	.
												1	1	1	1	1



typedef struct languageFlag
{

	U32 consonant			:3;					//	bits for different consonant		
	U32 dep_vowel			:3;					//	bits for different dependent vowel	
	U32 indep_vowel			:1;					//	bits for independent vowel			
	U32 sign				:2;					//	bits for differnt sign				
	U32 ligature			:2;					//	bits for different ligature			
	U32 digit				:1;					//	bits for different digit			
	U32 char_position		:4;					//	bits for rendering info				
	U32 padding				:16;				//	bits for unicdoe value of character	
		
}gLanguageStatusFlag;

*/
