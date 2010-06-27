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
 *    IndicRuleEngineCommon.h
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

#ifndef MMI_INDIC_RULE_ENGINE_COMMON_H
#define MMI_INDIC_RULE_ENGINE_COMMON_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_ems.h"
#include "wgui_inputs.h"
#include "wgui_categories_inputsenum.h"

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#define MAX_MULTITAPS         12
#else 
#define MAX_MULTITAPS         10
#endif 

#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
#include "Hindi.h"
#endif

#ifdef __MMI_LANG_TAMIL__
#include "Tamil.h"
#endif

#ifdef __MMI_LANG_MARATHI__
#include "Marathi.h"
#endif

#ifdef __MMI_LANG_BENGALI__
#include "Bengali.h"
#endif

/* START PMT PUNJABI TELUGU */
#ifdef __MMI_LANG_PUNJABI__
#include "Punjabi.h"
#endif

#ifdef __MMI_LANG_TELUGU__
#include "Telugu.h"
#endif
/* END PMT PUNJABI TELUGU */
#define  C_MAX                      10  /* man no. of characters that can form a cluster */
#define  G_MAX                      14  /* maximun no. of glyph inputs that can be used to make a conjunct */
#define  INDIC_RESERVED                0x0000
#define  SPACE                      0x20

/**************     TYPEDEF'S STRUCTURES DEFINITION      ************************/
typedef struct
{
    U32 consonant:3;        /* bits for different consonant     */
    U32 dep_vowel:3;        /* bits for different dependent vowel  */
    U32 indep_vowel:1;      /* bits for independent vowel       */
    U32 sign:2;             /* bits for differnt sign           */
    U32 ligature:2;         /* bits for different ligature         */
    U32 digit:1;            /* bits for different digit         */
    U32 char_position:4;    /* bits for rendering info          */
    U32 padding:16;         /* bits for unicdoe value of character */

} ire_character_info_table_struct;

typedef struct
{
    U8 is_con_hal_ligature;         /* whether it is a ligature or unicode value */
    U8 input_buffer_len;            /* no. of input unicode values */
    U8 output_buffer_len;           /* no, of output values */
    U8 rule_language;
    U16 input_buffer_glyph[C_MAX];  /* no. of input glyph used to make conjunct */
    U16 output_buffer_glyph[C_MAX]; /* no. of output glyph that has to be rendered */

} ire_glyph_info_table_struct;

typedef struct
{
    const ire_glyph_info_table_struct *glyph_info_p;    /* pointer to individual table */
    U16 nsize;                                          /* size of individual character's array */
    U8 max_input_glyph_size;                            /* max input of glyph it can handle */

} ire_main_glyph_table_struct;

typedef struct
{
    U16 start_range;    /* Start Range of language */
    U16 end_range;      /* End Range of language   */
    const ire_character_info_table_struct *indic_char_info_flag_p;      /*   Pointer the base address of language array   */
    const ire_main_glyph_table_struct *indic_main_info_table_p; /* Pointer the base address of language ligature array   */

} ire_indic_languages_table_struct;

typedef enum
{
    MMI_ALL_LANG = 0,
    MMI_HINDI_LANG = 1,
    MMI_MARATHI_LANG = 2
} indic_rules_ligature_enum;

typedef struct __HindiRulesLangSSC
{
    S8 *ssc_string;
    indic_rules_ligature_enum language_enum;
} HindiRulesLangSSC;

/**************         TYPEDEF'S ENUMERATION DEFINITION       *********************/

/* Various types of consonant */
typedef enum
{
	IRE_NOT_A_CONS							= 0x00,
	IRE_NORMAL_CONSONANT					= 0x01,
	IRE_RA_CONSONANT						= 0x02,
	IRE_SMALL_CONSONANT						= 0x03,
	IRE_MAX_CONSONANT						= 0x04

}ire_character_type_consonant_enum;

/*Various types of dependent vowel*/
typedef enum 
{
	IRE_NOT_A_DEP_VOWEL						= 0x00,
	IRE_PRE_BASE_DEP_VOWEL					= 0x01,
	IRE_POST_BASE_DEP_VOWEL					= 0x02,
	IRE_BELOW_BASE_DEP_VOWEL				= 0x03,
	IRE_ABOVE_BASE_DEP_VOWEL				= 0x04,
	IRE_CENTER_BASE_DEP_VOWEL				= 0x05,
	IRE_MAX_DEP_VOWEL						= 0x06

}ire_dep_vowel_enum;

/*Various types of Independent vowel*/
typedef enum
{
	IRE_NOT_A_INDEP_VOWEL					= 0x00,
	IRE_INDEP_VOWEL							= 0x01
										
}ire_character_type_indep_vowel_enum;

/*Various types of sign*/
typedef enum 
{
	IRE_NOT_A_SIGN							= 0x00,
	IRE_HALANT_SIGN							= 0x01,
	IRE_NORMAL_SIGN                         = 0x02,
	IRE_TAMIL_HAL_SIGN						= 0x03
}ire_character_type_sign_enum;

/*Various types of ligature*/
typedef enum 
{
	IRE_NOT_A_LIGATURE						= 0x00,
	IRE_NORMAL_LIGATURE						= 0x01

}ire_character_type_ligature_enum;

/*Various types of digit*/
typedef enum 
{
	IRE_NOT_A_DIGIT							= 0x00,
	IRE_NUMERIC_DIGIT						= 0x01

}ire_character_type_digit_enum;

/*Various types of digit*/
typedef enum 
{
	IRE_NO_POSITION							= 0x00,
	IRE_PREBASE_POSITION					= 0x01,
	IRE_POSTBASE_POSITION					= 0x02,
	IRE_ABOVE_BASE_POSITION					= 0x03,
	IRE_BELOW_BASE_POSITION					= 0x04,
	IRE_CENTER_BASE_POSITION				= 0x05,
	IRE_MAX_POSITION						= 0x06

}ire_character_position_info_enum;

/*Various types of digit*/
typedef enum 
{
    IRE_CHAR_TYPE_INVALID,
    IRE_CHAR_TYPE_CON,
    IRE_CHAR_TYPE_INDEPVOWEL,
    IRE_CHAR_TYPE_DEPVOWEL,
    IRE_CHAR_TYPE_SIGN,
    IRE_CHAR_TYPE_HALANT,
    IRE_CHAR_TYPE_LIGATURE,
    IRE_CHAR_TYPE_DIGIT,
    IRE_CHAR_TYPE_SIGN_CONSONANT,
    IRE_CHAR_TYPE_NORMAL_CONSONANT,
    IRE_CHAR_TYPE_SPECIAL_SIGN,
    IRE_CHAR_TYPE_TOTAL
} ire_character_type_info_enum;

extern UI_EMS_input_box MMI_EMS_inputbox;
extern U8 MMI_all_input_mode_set[INPUT_MODE_MAX_NUM];

/* Two arrays for indic and arabic family input modes */
extern const U8 input_mode_array_for_indic_family[];
extern const U8 input_mode_array_for_arabic_family[];

#ifdef __MMI_BIDI_ALG__
    #define IRE_INCREMENT_LANGUAGE_VARIABLES(c)	                                                     \
    {																                                 	     \
	    if(IRE_INDIC_LANGUAGE_RANGE(c))								                                	\
	    {															                                	\
		    ++g_indic_rule_engine_cntx.g_ire_indic_language_character_count;			    			\
	    }															                                	\
	    else                                                                                            \
	    {                                                                                               \
		    PMT_BIDI_TYPES default_direction = BIDI_L;                                                  \
		    bidi_get_char_type((U8*) &c, (U8*) & default_direction);                                           \
		    if ((default_direction == AL) || (default_direction == AN) || (default_direction == BIDI_R))  \
		    {                                                                                             \
			    ++g_indic_rule_engine_cntx.g_ire_arabic_language_character_count;						  \
		    }                                                                                             \
	    }                                                                                                 \
    }
#else
    #define IRE_INCREMENT_LANGUAGE_VARIABLES(c)	NULL
#endif

#ifdef __MMI_BIDI_ALG__
    #define IRE_DECREMENT_LANGUAGE_VARIABLES(c)                                                      	\
    {																	                                    \
	    if(IRE_INDIC_LANGUAGE_RANGE(c))									                                    \
	    {																                                    \
		    --g_indic_rule_engine_cntx.g_ire_indic_language_character_count;				        		\
	    }															                                    	\
	    else                                                                                                \
	    {															                                    	\
		    PMT_BIDI_TYPES default_direction = BIDI_L;                                                      \
		    bidi_get_char_type((U8*) &c, (U8*) & default_direction);                                               \
		    if ((default_direction == AL) || (default_direction == AN) || (default_direction == BIDI_R))    \
		    {                                                                                               \
			    --g_indic_rule_engine_cntx.g_ire_arabic_language_character_count;						    \
		    }																                                \
	    }                                                                                                   \
    }
#else
    #define IRE_DECREMENT_LANGUAGE_VARIABLES(c)	NULL
#endif

#ifdef __MMI_BIDI_ALG__
    #define IRE_RESET_LANGUAGE_VARIABLES()					                                        \
    {																                                    	\
	    g_indic_rule_engine_cntx.g_ire_indic_language_character_count = 0;						        	\
	    g_indic_rule_engine_cntx.g_ire_arabic_language_character_count = 0;					            	\
    }
#else
    #define IRE_RESET_LANGUAGE_VARIABLES()	NULL
#endif							

#ifdef __MMI_BIDI_ALG__	
#define IRE_INSERTED_ARABIC_COUNT() g_indic_rule_engine_cntx.g_ire_arabic_language_character_count						
#define IRE_INSERTED_INDIC_COUNT() 	g_indic_rule_engine_cntx.g_ire_indic_language_character_count					
#endif /*__MMI_BIDI_ALG__*/

#ifdef __MMI_LANG_TELUGU__
#define IRE_GET_SMALL_CONSONANT_FLAG() g_indic_rule_engine_cntx.small_cons
#else   
#define IRE_GET_SMALL_CONSONANT_FLAG() NULL
#endif

#ifdef __MMI_LANG_TELUGU__
#define IRE_SET_SMALL_CONSONANT_FLAG() g_indic_rule_engine_cntx.small_cons = 1
#else   
#define IRE_SET_SMALL_CONSONANT_FLAG() NULL
#endif

#ifdef __MMI_LANG_TELUGU__
#define IRE_RESET_SMALL_CONSONANT_FLAG() g_indic_rule_engine_cntx.small_cons = 0
#else   
#define IRE_RESET_SMALL_CONSONANT_FLAG() NULL
#endif 

#ifdef __MMI_LANG_TELUGU__
#define IRE_GET_SMALL_CONS_HALANT_FLAG() g_indic_rule_engine_cntx.small_cons_halant_present
#else   
#define IRE_GET_SMALL_CONS_HALANT_FLAG() NULL
#endif

#ifdef __MMI_LANG_TELUGU__
#define IRE_SET_SMALL_CONS_HALANT_FLAG() g_indic_rule_engine_cntx.small_cons_halant_present =1
#else   
#define IRE_SET_SMALL_CONS_HALANT_FLAG() NULL
#endif

#ifdef __MMI_LANG_TELUGU__
#define IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG() g_indic_rule_engine_cntx.small_cons_halant_present =2
#else   
#define IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG() NULL
#endif

#ifdef __MMI_LANG_TELUGU__
#define IRE_RESET_SMALL_CONS_HALANT_FLAG() g_indic_rule_engine_cntx.small_cons_halant_present =0
#else   
#define IRE_RESET_SMALL_CONS_HALANT_FLAG() NULL
#endif 
/* PMT START MAUI_00029915 */
//code removed
/* PMT END MAUI_00029915 */

#endif /*End of MMI_INDIC_RULE_ENGINE_COMMON_H*/

/*************Bit pattern definition of gLangStatusFlag********/
/*
 * 
 * MSB........................................................LSB
 * 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0 
 * .  .  .  .  .  .  .  .  .  .  .  .  .                       
 * .  .  .  .  .  .  .  .  .  .  .  .  .  0  0  0     -  INVALID_CONSONANT
 * .  .  .  .  .  .  .  .  .  .  .  .  .  0  0  1     -  IRE_NORMAL_CONSONANT
 * .  .  .  .  .  .  .  .  .  .  .  .  .  0  1  0     -  IRE_SPECIAL_RA_CONSONANT
 * .  .  .  .  .  .  .  .  .  .  .  .  .  0  1  1     -  IRE_SMALL_CONSONANT
 * .  .  .  .  .  .  .  .  .  .  .  .  .  1  0  0     -
 * .  .  .  .  .  .  .  .  .  .  .  .  .  1  0  1     -
 * .  .  .  .  .  .  .  .  .  .  .  .  .  1  1  0     -
 * .  .  .  .  .  .  .  .  .  .  .  .  .  1  1  1     -
 * .  .  .  .  .  .  .  .  .  .  .  .  .
 * .  .  .  .  .  .  .  .  .  .  .  .  .  
 * .  .  .  .  .  .  .  .  .     0  0  0              -  INVALID_DEP_VOWEL
 * .  .  .  .  .  .  .  .  .  .  0  0  1              -  IRE_PRE_BASE_DEP_VOWEL
 * .  .  .  .  .  .  .  .  .  .  0  1  0              -  IRE_POST_BASE_DEP_VOWEL
 * .  .  .  .  .  .  .  .  .  .  0  1  1              -  IRE_BELOW_BASE_DEP_VOWEL
 * .  .  .  .  .  .  .  .  .  .  1  0  0              -  IRE_ABOVE_BASE_DEP_VOWEL
 * .  .  .     .  .  .  .  .     1  0  1              -  IRE_CENTER_BASE_DEP_VOWEL
 * .  .  .  .  .  .  .  .  .  .  1  1  0              -  IRE_MAX_DEP_VOWEL
 * .  .  .  .  .  .  .  .  .  .  1  1  1              -
 * .  .     .  .  .  .  .  .  .
 * .  .  .  .  .  .  .  .  .  0                       -  IRE_INVALID_INDEP_VOWEL
 * .  .  .  .  .  .  .  .  .  1                       -  IRE_INDEP_VOWEL
 * .  .  .  .  .  .  .  .  .                       
 * .  .  .  .  .  .  .  0  0                          -  IRE_INVALID_SIGN
 * .  .  .  .  .  .  .  0  1                          -  IRE_HALANT_SIGN
 * .  .  .  .  .  .  .  1  0                          -  IRE_NORMAL_SIGN
 * .  .  .  .  .  .  .  1  1                          -  IRE_TAMIL_HAL_SIGN
 * .  .  .  .  .  .  .
 * .  .  .  .  .
 * .  .  .  .  .  0  0                                -  IRE_INVALID_LIGATURE
 * .  .  .  .  .  0  1                                -  IRE_NORMAL_LIGATURE
 * .  .  .  .  .                                      
 * .  .  .  .  0                                      -  IRE_INVALID_DIGIT
 * .  .  .  .  1                                      -  IRE_NUMERIC_DIGIT
 * .  .  .
 * 0  0  0  0                                         -   IRE_NO_POSITION        
 * 0  0  0  1                                         -  IRE_PREBASE_POSITION 
 * 0  0  1  0                                         -  IRE_POSTBASE_POSITION   
 * 0  0  1  1                                         -  IRE_ABOVE_BASE_POSITION 
 * 0  1  0  0                                         -  IRE_BELOW_BASE_POSITION 
 * 0  1  0  1                                         -  IRE_CENTER_BASE_POSITION
 * 0  1  1  0                                         -  IRE_MAX_POSITION     
 * 0  1  1  1                                         -
 * 
 * MSB........................................................LSB    
 * 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16
 * 
 * 0  0  0  0  0     - padding
 * 0  0  0  0  1
 * .  .  .  .  .
 * .  .  .  .  .
 * .  .  .  .  .
 * 1  1  1  1  1
 * 
 * 
 * 
 * typedef struct languageFlag
 * {
 * 
 * U32 consonant        :3;               // bits for different consonant     
 * U32 dep_vowel        :3;               // bits for different dependent vowel  
 * U32 indep_vowel         :1;               // bits for independent vowel       
 * U32 sign          :2;               // bits for differnt sign           
 * U32 ligature         :2;               // bits for different ligature         
 * U32 digit            :1;               // bits for different digit         
 * U32 char_position    :4;               // bits for rendering info          
 * U32 padding          :16;           // bits for unicdoe value of character 
 * 
 * }gLanguageStatusFlag;
 * 
 */

