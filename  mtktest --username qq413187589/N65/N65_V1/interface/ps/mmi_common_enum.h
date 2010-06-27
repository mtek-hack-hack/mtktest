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
 /*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   mmi_common_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mmi common enum
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _MMI_COMMON_ENUM_H
#define _MMI_COMMON_ENUM_H

typedef enum
{
   CBS0_GERMAN = 0,
   CBS0_ENGLISH,
   CBS0_ITALIAN,
   CBS0_FRENCH,
   CBS0_SPANISH,
   CBS0_DUTCH,
   CBS0_SWEDISH,
   CBS0_DANISH,
   CBS0_PORTUGUESE,
   CBS0_FINNISH,
   CBS0_NORWEGIAN,
   CBS0_GREEK,
   CBS0_TURKISH,
   CBS0_HUNGARIAN,
   CBS0_POLISH,
   CBS0_LANG_UNSPECIFIED,

   CBS1_CZECH = 16,
   CBS1_HEBREW,
   CBS1_ARABIC,
   CBS1_RUSSIAN,


   CBS2_AA, // AFAR, 20
   CBS2_AB, // ABKHAZIAN
   CBS2_AF, // AFRIKAANS
   CBS2_AM, // AMHARIC
   //CBS2_AR, // ARABIC
   CBS2_AS, // ASSAMESE
   CBS2_AY, // AYMARA
   CBS2_AZ, // AZERBAIJANI

   CBS2_BA, // BASHKIR
   CBS2_BE, // BYELORUSSIAN
   CBS2_BG, // BULGARIAN, 30
   CBS2_BH, // BIHARI
   CBS2_BI, // BISLAMA
   CBS2_BN, // BENGALI; BANGLA
   CBS2_BO, // TIBETAN
   CBS2_BR, // BRETON

   CBS2_CA, // CATALAN
   CBS2_CO, // CORSICAN
   //CBS2_CS, // CZECH
   CBS2_CY, // WELSH

   //CBS2_DA, // DANISH, 40
   //CBS2_DE, // GERMAN
   CBS2_DZ, // BHUTANI

   //CBS2_EL, // GREEK
   //CBS2_EN, // ENGLISH
   CBS2_EO, // ESPERANTO
   //CBS2_ES, // SPANISH
   CBS2_ET, // ESTONIAN
   CBS2_EU, // BASQUE

   CBS2_FA, // PERSIAN
   //CBS2_FI, // FINNISH, 50
   CBS2_FJ, // FIJI
   CBS2_FO, // FAROESE
   //CBS2_FR, // FRENCH
   CBS2_FY, // FRISIAN

   CBS2_GA, // IRISH
   CBS2_GD, // SCOTS GAELIC
   CBS2_GL, // GALICIAN
   CBS2_GN, // GUARANI
   CBS2_GU, // GUJARATI

   CBS2_HA, // HAUSA, 60
   //CBS2_HE, // HEBREW (FORMERLY IW)
   CBS2_HI, // HINDI
   CBS2_HR, // CROATIAN
   //CBS2_HU, // HUNGARIAN
   CBS2_HY, // ARMENIAN

   CBS2_IA, // INTERLINGUA
   CBS2_ID, // INDONESIAN (FORMERLY IN)
   CBS2_IE, // INTERLINGUE
   CBS2_IK, // INUPIAK
   CBS2_IS, // ICELANDIC, 70
   //CBS2_IT, // ITALIAN
   CBS2_IU, // INUKTITUT

   CBS2_JA, // JAPANESE
   CBS2_JW, // JAVANESE

   CBS2_KA, // GEORGIAN
   CBS2_KK, // KAZAKH
   CBS2_KL, // GREENLANDIC
   CBS2_KM, // CAMBODIAN
   CBS2_KN, // KANNADA
   CBS2_KO, // KOREAN, 80
   CBS2_KS, // KASHMIRI
   CBS2_KU, // KURDISH
   CBS2_KY, // KIRGHIZ

   CBS2_LA, // LATIN
   CBS2_LN, // LINGALA
   CBS2_LO, // LAOTHIAN
   CBS2_LT, // LITHUANIAN
   CBS2_LV, // LATVIAN, LETTISH

   CBS2_MG, // MALAGASY
   CBS2_MI, // MAORI, 90
   CBS2_MK, // MACEDONIAN
   CBS2_ML, // MALAYALAM
   CBS2_MN, // MONGOLIAN
   CBS2_MO, // MOLDAVIAN
   CBS2_MR, // MARATHI
   CBS2_MS, // MALAY
   CBS2_MT, // MALTESE
   CBS2_MY, // BURMESE

   CBS2_NA, // NAURU
   CBS2_NE, // NEPALI, 100
   //CBS2_NL, // DUTCH
   //CBS2_NO, // NORWEGIAN

   CBS2_OC, // OCCITAN
   CBS2_OM, // (AFAN) OROMO
   CBS2_OR, // ORIYA

   CBS2_PA, // PUNJABI
   //CBS2_PL, // POLISH
   CBS2_PS, // PASHTO, PUSHTO
   //CBS2_PT, // PORTUGUESE

   CBS2_QU, // QUECHUA, 110

   CBS2_RM, // RHAETO-ROMANCE
   CBS2_RN, // KIRUNDI
   CBS2_RO, // ROMANIAN
   //CBS2_RU, // RUSSIAN
   CBS2_RW, // KINYARWANDA

   CBS2_SA, // SANSKRIT
   CBS2_SD, // SINDHI
   CBS2_SG, // SANGHO
   CBS2_SH, // SERBO-CROATIAN
   CBS2_SI, // SINHALESE, 120
   CBS2_SK, // SLOVAK
   CBS2_SL, // SLOVENIAN
   CBS2_SM, // SAMOAN
   CBS2_SN, // SHONA
   CBS2_SO, // SOMALI
   CBS2_SQ, // ALBANIAN
   CBS2_SR, // SERBIAN
   CBS2_SS, // SISWATI
   CBS2_ST, // SESOTHO
   CBS2_SU, // SUNDANESE, 130
   //CBS2_SV, // SWEDISH
   CBS2_SW, // SWAHILI

   CBS2_TA, // TAMIL
   CBS2_TE, // TELUGU
   CBS2_TG, // TAJIK
   CBS2_TH, // THAI
   CBS2_TI, // TIGRINYA
   CBS2_TK, // TURKMEN
   CBS2_TL, // TAGALOG
   CBS2_TN, // SETSWANA, 140
   CBS2_TO, // TONGA
   //CBS2_TR, // TURKISH
   CBS2_TS, // TSONGA
   CBS2_TT, // TATAR
   CBS2_TW, // TWI

   CBS2_UG, // UIGHUR
   CBS2_UK, // UKRAINIAN
   CBS2_UR, // URDU
   CBS2_UZ, // UZBEK

   CBS2_VI, // VIETNAMESE, 150
   CBS2_VO, // VOLAPUK

   CBS2_WO, // WOLOF

   CBS2_XH, // XHOSA

   CBS2_YI, // YIDDISH (FORMERLY JI)
   CBS2_YO, // YORUBA

   CBS2_ZA, // ZHUANG
   CBS2_ZH, // CHINESE
   CBS2_ZU, // ZULU, 158
   CBS_INVALID = 255
} mmi_phnset_language_enum;

#endif /* _MMI_COMMON_ENUM_H */