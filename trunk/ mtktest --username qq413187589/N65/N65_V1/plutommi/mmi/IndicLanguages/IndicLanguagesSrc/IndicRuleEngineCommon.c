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
 *    IndicRuleEngineCommon.c
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
#include "IndicEngineGprot.h"
#include "BIDIDef.h"

/****************************EXTERN DEFINITION*********************/
#if defined (__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)

extern const ire_main_glyph_table_struct hfDvngTbl[]; 
extern const ire_character_info_table_struct hindi_character_info_table[]; 
extern const ire_character_info_table_struct hindi_ligature_info_table[]; 
#endif

#if defined (__MMI_LANG_TAMIL__) 

extern const ire_main_glyph_table_struct TamilDvngTbl[]; 
extern const ire_character_info_table_struct tamil_character_info_table[]; 
extern const ire_character_info_table_struct tamil_ligature_info_table[]; 

#endif
#if defined (__MMI_LANG_BENGALI__) 

extern const ire_main_glyph_table_struct BengaliDvngTbl[]; 
extern const ire_character_info_table_struct bengali_character_info_table[]; 
extern const ire_character_info_table_struct bengali_ligature_info_table[]; 

#endif
#if defined (__MMI_LANG_PUNJABI__) 

extern const ire_main_glyph_table_struct PunjabiTbl[]; 
extern const ire_character_info_table_struct punjabi_character_info_table[]; 
extern const ire_character_info_table_struct punjabi_ligature_info_table[]; 

#endif
#if defined (__MMI_LANG_TELUGU__) 

extern const ire_main_glyph_table_struct TELUGUTbl[]; 
extern const ire_character_info_table_struct telugu_character_info_table[]; 
extern const ire_character_info_table_struct telugu_ligature_info_table[]; 

#endif
/**********************ARRAY'S DEFINITION*****************************************************/

const ire_indic_languages_table_struct indic_lang_char_info_table[] = 
{
	{0,0,0,0},																						/*Invalid*/

#if defined (__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
	{IRE_HINDI_LANG_START_RANGE, IRE_HINDI_LANG_END_RANGE, hindi_character_info_table, hfDvngTbl },	/*Hindi*/
#else
	{0,0,0,0},
#endif

#if defined (__MMI_LANG_BENGALI__)
	{IRE_BENGALI_LANG_START_RANGE, IRE_BENGALI_LANG_END_RANGE, bengali_character_info_table, BengaliDvngTbl },	/*Bengali*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_PUNJABI__)
	{IRE_PUNJABI_LANG_START_RANGE, IRE_PUNJABI_LANG_END_RANGE, punjabi_character_info_table, PunjabiTbl },	/*Punjabi*/
#else
	{0,0,0,0},
#endif
	{0,0,0,0},																						/*Gujrati*/
	{0,0,0,0},																						/*Oriya*/

#if defined (__MMI_LANG_TAMIL__)
	{IRE_TAMIL_LANG_START_RANGE, IRE_TAMIL_LANG_END_RANGE, tamil_character_info_table, TamilDvngTbl },/*Tamil*/
#else
	{0,0,0,0},
#endif

#if defined (__MMI_LANG_TELUGU__)
	{IRE_TELUGU_LANG_START_RANGE, IRE_TELUGU_LANG_END_RANGE, telugu_character_info_table, TELUGUTbl }, /*Telugu*/
#else
	{0,0,0,0},
#endif	
	{0,0,0,0}																						/*Kannada*/
};																							  

const ire_indic_languages_table_struct indic_lang_ligature_info_table[] = 
{
	
	{0,0,0,0},																									/*Invalid*/

#if defined (__MMI_LANG_HINDI__)|| defined(__MMI_LANG_MARATHI__)
	{IRE_HINDI_PROPRIETRY_START_RANGE, IRE_HINDI_PROPRIETRY_END_RANGE, hindi_ligature_info_table, hfDvngTbl },	/*Hindi*/
#else
	{0,0,0,0},
#endif

#if defined (__MMI_LANG_BENGALI__)
	{IRE_BENGALI_PROPRIETRY_START_RANGE, IRE_BENGALI_PROPRIETRY_END_RANGE, bengali_ligature_info_table, BengaliDvngTbl },	/*Bengali*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_PUNJABI__)
	{IRE_PUNJABI_PROPRIETRY_START_RANGE, IRE_PUNJABI_PROPRIETRY_END_RANGE, punjabi_ligature_info_table, PunjabiTbl },/*Tamil*/
#else
	{0,0,0,0},
#endif
	{0,0,0,0},																									/*Gujrati*/
	{0,0,0,0},																									/*Oriya*/

#if defined (__MMI_LANG_TAMIL__)
	{IRE_TAMIL_PROPRIETRY_START_RANGE, IRE_TAMIL_PROPRIETRY_END_RANGE, tamil_ligature_info_table, TamilDvngTbl },/*Tamil*/
#else
	{0,0,0,0},
#endif
#if defined (__MMI_LANG_TELUGU__)
	{IRE_TELUGU_PROPRIETRY_START_RANGE, IRE_TELUGU_PROPRIETRY_END_RANGE, telugu_ligature_info_table, TELUGUTbl },           /*Telugu*/
#else
	{0,0,0,0},
#endif
	{0,0,0,0}																									/*Kannada*/
};
/* PMT START MAUI_00029915 */
//code removed
/* PMT END MAUI_00029915 */

