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
 *  Thai.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Thai language module
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "gui_data_types.h"
#include "ThaiGProt.h"
#include "Thai.h"
#include "wgui_inputs.h"
#include "gui_ems.h"
#include "gui_inputs.h"

/****************************************************************************** 
* External Global variables
***************************************************************************** */

/****************************************************************************** 
* External Global Functions
***************************************************************************** */

/****************************************************************************** 
* Global variables
***************************************************************************** */
#if defined(__MMI_MULTITAP_THAI__)
#if defined(__MMI_MULTITAP_THAI_PROFILE_1__)
/* the begining key mapping 
  * only leading vowel, sign, consonant are allowed
  */
const UI_character_type default_multitap_thai_strings_normal[MAX_MULTITAPS][32] = 
{
    {'0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */ /* only leading vowel allowed when first input */
    {THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};
/* after a consonant is input 
  * all are allowed
  */
const UI_character_type default_multitap_thai_strings_con[MAX_MULTITAPS][32] = 
{
    {THAI_AV_MAIHAN_AKAT, THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_BV_SARA_U, THAI_BV_SARA_UU, '0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_FV_SARA_A, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */
    {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};
/* after tone mark 
  * no other tone mark, above and below vowel
  */
const UI_character_type default_multitap_thai_strings_tone[MAX_MULTITAPS][32] = 
{
    {'0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_FV_SARA_A, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */
    {THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};
/* After Above and Below vowel
  * no above and below vowel is allowed
  */
const UI_character_type default_multitap_thai_strings_vowel[MAX_MULTITAPS][32] = 
{
    {'0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_FV_SARA_A, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */
    {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};

#else 
#if 1
//def ADH_THAI_KEYPAD
/* for default case, it should be __MMI_MULTITAP_THAI_PROFILE_2__ */

/* the begining key mapping 
  * only leading vowel, sign, consonant are allowed
  */
const UI_character_type default_multitap_thai_strings_normal[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
     /* key5 */ {THAI_D_FIVE, 0x0031, '\0'},
    /* key1 */ { THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_D_ONE, 0x0032, '\0'},
    /* key2 */ {THAI_C_CHO_CHAN,THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0033, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN,THAI_C_DO_DEK, THAI_C_TO_TAO,  THAI_D_THREE, 0x0034, '\0'},
    /* key4 */ {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};

/* after a consonant is input 
  * all are allowed
  */
const UI_character_type default_multitap_thai_strings_con[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
/* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0031, '\0'},

    /* key1 */ { THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_FV_SARA_A, THAI_AV_MAIHAN_AKAT,THAI_D_ONE, 0x0032, '\0'},
    /* key2 */ {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0033, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO,THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_D_THREE, 0x0034, '\0'},
    /* key4 */ { THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_D_FOUR, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_BV_SARA_U, THAI_BV_SARA_UU, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* after tone mark 
  * no other tone mark, above and below vowel
  */
const UI_character_type default_multitap_thai_strings_tone[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
/* key5 */ { THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0031, '\0'},
    /* key1 */ { THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_FV_SARA_A, THAI_D_ONE,0x0032, '\0'},
    /* key2 */ {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0033, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO,THAI_D_THREE, 0x0034, '\0'},
    /* key4 */ { THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0035, '\0'},
  
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};


/* After Above and Below vowel
  * no above and below vowel is allowed
  */
const UI_character_type default_multitap_thai_strings_vowel[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
 /* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0031, '\0'},

    /* key1 */ { THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU,  THAI_FV_SARA_A, THAI_AV_MAIHAN_AKAT, THAI_D_ONE,0x0032, '\0'},
    /* key2 */ {THAI_C_CHO_CHAN,THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0033, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO,THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_D_THREE, 0x0034, '\0'},
    /* key4 */ { THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_D_FOUR, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_BV_SARA_U, THAI_BV_SARA_UU, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_multitap_thai_strings_sara_aa[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
  /* key5 */ {THAI_D_FIVE, 0x0031, '\0'},
    /* key1 */ { THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_FV_SARA_A, THAI_D_ONE,0x0032, '\0'},
    /* key2 */ {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0033, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_D_THREE, 0x0034, '\0'},
    /* key4 */ {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0035, '\0'},

    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};

#else  //ADH_THAI_SOFTKEY
/* for default case, it should be __MMI_MULTITAP_THAI_PROFILE_2__ */

/* the begining key mapping 
  * only leading vowel, sign, consonant are allowed
  */
const UI_character_type default_multitap_thai_strings_normal[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};

/* after a consonant is input 
  * all are allowed
  */
const UI_character_type default_multitap_thai_strings_con[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, THAI_AV_MAIHAN_AKAT, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_BV_SARA_U, THAI_BV_SARA_UU, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* after tone mark 
  * no other tone mark, above and below vowel
  */
const UI_character_type default_multitap_thai_strings_tone[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ { THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* After Above and Below vowel
  * no above and below vowel is allowed
  */
const UI_character_type default_multitap_thai_strings_vowel[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, THAI_AV_MAIHAN_AKAT, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_BV_SARA_U, THAI_BV_SARA_UU, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_multitap_thai_strings_sara_aa[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};
#endif  


#endif

#endif

/***************************************************************************** 
* Local Variables
*****************************************************************************/
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
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  IsThaiUpDownVowel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiUpDownVowel(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_AV_MAIHAN_AKAT || ch >= THAI_AV_SARA_I && ch <= THAI_BV_PHINTHU || ch == THAI_AV_MAITAIKHU)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiConsonant
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiConsonant(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= THAI_C_KO_KAI && ch <= THAI_C_HO_NOKHUK)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiToneMark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiToneMark(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_TM_MAI_EK || ch == THAI_TM_MAI_THO || ch == THAI_TM_MAI_TRI || ch == THAI_TM_MAI_CHATTAWA)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiBaseLineChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiBaseLineChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= THAI_C_KO_KAI && ch <= THAI_S_KHOMUT)
    {
        /* above vowels */
        if (ch != THAI_AV_MAIHAN_AKAT && ch != THAI_AV_MAITAIKHU && ch != THAI_AV_SARA_I && 
            ch != THAI_AV_SARA_II && ch != THAI_AV_SARA_UE && ch != THAI_AV_SARA_UEE &&
            /* Tone marks */
            ch != THAI_TM_MAI_CHATTAWA && ch != THAI_TM_MAI_EK && ch != THAI_TM_MAI_THO && ch != THAI_TM_MAI_TRI &&
            /* Below vowels */
            ch != THAI_BV_PHINTHU && ch != THAI_BV_SARA_U && ch != THAI_BV_SARA_UU && 
            /* Signs */
            ch != THAI_S_ANGKHANKHU && ch != THAI_S_FONGMAN && ch != THAI_S_KHOMUT && ch != THAI_S_LAKKHANGYAO && 
            ch != THAI_S_MAIYAMOK && ch != THAI_S_NIKHAHIT && ch != THAI_S_PAIYANNOI && ch != THAI_S_THANTHAKHAT && ch != THAI_S_YAMAKKAN &&
            /* Exclude Thai digits */
            ch <= THAI_D_ZERO)
        {
            return MMI_TRUE;
        }
        else
        {
            return FALSE;
        }

    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiAboveLineChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiAboveLineChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_AV_MAIHAN_AKAT || ch == THAI_AV_SARA_I || ch == THAI_AV_SARA_II || ch == THAI_AV_SARA_UE || ch == THAI_AV_SARA_UEE || ch == THAI_AV_MAITAIKHU || ch == THAI_S_THANTHAKHAT)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiBottomLineChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiBottomLineChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_BV_SARA_U || ch == THAI_BV_SARA_UU || ch == THAI_BV_PHINTHU)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiLongTailChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiLongTailChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_C_PO_PLA || ch == THAI_C_FO_FA || ch == THAI_C_FO_FAN)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiDigitChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiDigitChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= THAI_D_ZERO && ch <= THAI_D_NINE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiBaseSignChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiBaseSignChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_S_PAIYANNOI || ch == THAI_SB_BAHT || ch == THAI_S_MAIYAMOK || ch == THAI_S_FONGMAN || ch == THAI_S_ANGKHANKHU || ch == THAI_S_KHOMUT)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HaveThaiCharacter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL HaveThaiCharacter(U16 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ch = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        ch = str[0];
        if (ch == 0)
        {
            return FALSE;
        }
        if (ch >= THAI_C_KO_KAI && ch <= THAI_S_KHOMUT)
        {
            return TRUE;
        }
        str++;
    }
    return FALSE;

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
#endif

#if defined(__MMI_MULTITAP_THAI__)
extern mmi_editor_inoutbox_enum MMI_current_input_box_type;
extern UI_EMS_input_box MMI_EMS_inputbox;
extern UI_character_type gui_multi_line_current_character(multi_line_input_box *b);
extern UI_character_type gui_EMS_current_character(UI_EMS_input_box *b);
extern UI_character_type gui_single_line_current_character(single_line_input_box *b);
/*****************************************************************************
 * FUNCTION
 *  get_thai_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_thai_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type prev_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_input_box_type)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:    
            prev_char = gui_multi_line_current_character(&MMI_multiline_inputbox);
            break;
        case EDITOR_EMS_INPUT_BOX:
            prev_char = gui_EMS_current_character(&MMI_EMS_inputbox);
            break;
        case EDITOR_SINGLE_LINE_INPU_BOX:
        case EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
        case EDITOR_INLINE_TEXT:    
            prev_char = gui_single_line_current_character(&MMI_singleline_inputbox);
            break;
        default:
            prev_char = 0;
    }
    
    if (prev_char)
    {
        if ((prev_char >= THAI_C_KO_KAI) && (prev_char <= THAI_S_KHOMUT)) /* Thai character */
        {
            if (prev_char == THAI_FV_SARA_AA)
            {
                /* THAI_FV_SARA_A + THAI_FV_SARA_A is a special case for two following vowel combination. */
                return ((UI_character_type*) default_multitap_thai_strings_sara_aa[i]);
            } 
            else  if (IsThaiToneMark(prev_char))
            {
                return ((UI_character_type*) default_multitap_thai_strings_tone[i]);
            }
            else if (IsThaiConsonant(prev_char))
            {
                return ((UI_character_type*) default_multitap_thai_strings_con[i]);
            }
            else if (IsThaiUpDownVowel(prev_char))
            {
                return ((UI_character_type*) default_multitap_thai_strings_vowel[i]);
            }
        }
        else
        {
            return ((UI_character_type*) default_multitap_thai_strings_normal[i]);
        }
    }
    else{
        return ((UI_character_type*) default_multitap_thai_strings_normal[i]);
    }

    return ((UI_character_type*) default_multitap_thai_strings_normal[i]);
}

#endif /* defined(__MMI_MULTITAP_THAI__) */

