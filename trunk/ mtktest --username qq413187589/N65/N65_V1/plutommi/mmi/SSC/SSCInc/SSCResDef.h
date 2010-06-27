/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   SSCResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SSC resource definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SSC_RES_DEF_H__
#define __SSC_RES_DEF_H__

#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ENTER_SSC = IDLE_APP_BASE + 300
} SSC_SCR_ID_ENUM;

/* String IDs */
typedef enum
{
    SSC_SCR_LANGUAGE_ENGLISH_STR_ID = IDLE_APP_BASE + 300,
#if defined(__MMI_LANG_SM_CHINESE__)
    SSC_SCR_LANGUAGE_SCHINESE_STR_ID,
#endif
#if defined(__MMI_LANG_TR_CHINESE__)
    SSC_SCR_LANGUAGE_TCHINESE_STR_ID,
#endif    
    SSC_SCR_LANGUAGE_DEFAULT_STR_ID,
#if defined(__MMI_LANG_SPANISH__)
    SSC_SCR_LANGUAGE_SPANISH_STR_ID,
#endif 
#if defined(__MMI_LANG_DANISH__)
    SSC_SCR_LANGUAGE_DANISH_STR_ID,
#endif 
#if defined(__MMI_LANG_POLISH__)
    SSC_SCR_LANGUAGE_POLISH_STR_ID,
#endif 
#if defined(__MMI_LANG_FRENCH__)
    SSC_SCR_LANGUAGE_FRENCH_STR_ID,
#endif 
#if defined(__MMI_LANG_GERMAN__)
    SSC_SCR_LANGUAGE_GERMAN_STR_ID,
#endif 
#if defined(__MMI_LANG_ITALIAN__)
    SSC_SCR_LANGUAGE_ITALIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_THAI__)
    SSC_SCR_LANGUAGE_THAI_STR_ID,
#endif 
#if defined(__MMI_LANG_RUSSIAN__)
    SSC_SCR_LANGUAGE_RUSSIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_BULGARIAN__)
    SSC_SCR_LANGUAGE_BULGARIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_UKRAINIAN__)
    SSC_SCR_LANGUAGE_UKRAINIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_PORTUGUESE__)
    SSC_SCR_LANGUAGE_PORTUGUESE_STR_ID,
#endif 
#if defined(__MMI_LANG_TURKISH__)
    SSC_SCR_LANGUAGE_TURKISH_STR_ID,
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
    SSC_SCR_LANGUAGE_VIETNAMESE_STR_ID,
#endif 
#if defined(__MMI_LANG_INDONESIAN__)
    SSC_SCR_LANGUAGE_INDONESIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_CZECH__)
    SSC_SCR_LANGUAGE_CZECH_STR_ID,
#endif 
#if defined(__MMI_LANG_MALAY__)
    SSC_SCR_LANGUAGE_MALAY_STR_ID,
#endif 
#if defined(__MMI_LANG_FINNISH__)
    SSC_SCR_LANGUAGE_FINNISH_STR_ID,
#endif 
#if defined(__MMI_LANG_HUNGARIAN__)
    SSC_SCR_LANGUAGE_HUNGARIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_SLOVAK__)
    SSC_SCR_LANGUAGE_SLOVAK_STR_ID,
#endif 
#if defined(__MMI_LANG_DUTCH__)
    SSC_SCR_LANGUAGE_DUTCH_STR_ID,
#endif 
#if defined(__MMI_LANG_NORWEGIAN__)
    SSC_SCR_LANGUAGE_NORWEGIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_SWEDISH__)
    SSC_SCR_LANGUAGE_SWEDISH_STR_ID,
#endif 
#if defined(__MMI_LANG_CROATIAN__)
    SSC_SCR_LANGUAGE_CROATIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_ROMANIAN__)
    SSC_SCR_LANGUAGE_ROMANIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_SLOVENIAN__)
    SSC_SCR_LANGUAGE_SLOVENIAN_STR_ID,
#endif 
#if defined(__MMI_LANG_GREEK__)
    SSC_SCR_LANGUAGE_GREEK_STR_ID,
#endif 
#if defined (__MMI_LANG_HEBREW__)
    SSC_SCR_LANGUAGE_HEBREW_STR_ID,
#endif
#if defined (__MMI_LANG_ARABIC__)
    SSC_SCR_LANGUAGE_ARABIC_STR_ID,
#endif
#if defined (__MMI_LANG_PERSIAN__)
    SSC_SCR_LANGUAGE_PERSIAN_STR_ID,
#endif 
#if defined (__MMI_LANG_URDU__)
    SSC_SCR_LANGUAGE_URDU_STR_ID,
#endif
#if defined (__MMI_LANG_HINDI__)
    SSC_SCR_LANGUAGE_HINDI_STR_ID,
#endif
#if defined (__MMI_LANG_TAMIL__)
    SSC_SCR_LANGUAGE_TAMIL_STR_ID,
#endif 
#if defined (__MMI_LANG_BENGALI__)
    SSC_SCR_LANGUAGE_BENGALI_STR_ID,
#endif
#if defined (__MMI_LANG_MARATHI__)
    SSC_SCR_LANGUAGE_MARATHI_STR_ID,
#endif 
#if defined (__MMI_LANG_PUNJABI__)
    SSC_SCR_LANGUAGE_PUNJABI_STR_ID,
#endif
#if defined (__MMI_LANG_TELUGU__)
    SSC_SCR_LANGUAGE_TELUGU_STR_ID,
#endif
#if defined(__MMI_LANG_SM_CHINESE__)
    SSC_STR_ERR_SET_SCHINESE,
#endif
#if defined(__MMI_LANG_TR_CHINESE__)
    SSC_STR_ERR_SET_TCHINESE,
#endif
#if defined(__MMI_LANG_SPANISH__)
    SSC_STR_ERR_SET_SPANISH,
#endif 
#if defined(__MMI_LANG_DANISH__)
    SSC_STR_ERR_SET_DANISH,
#endif 
#if defined(__MMI_LANG_POLISH__)
    SSC_STR_ERR_SET_POLISH,
#endif 
#if defined(__MMI_LANG_FRENCH__)
    SSC_STR_ERR_SET_FRENCH,
#endif 
#if defined(__MMI_LANG_GERMAN__)
    SSC_STR_ERR_SET_GERMAN,
#endif 
#if defined(__MMI_LANG_ITALIAN__)
    SSC_STR_ERR_SET_ITALIAN,
#endif 
#if defined(__MMI_LANG_THAI__)
    SSC_STR_ERR_SET_THAI,
#endif 
#if defined(__MMI_LANG_RUSSIAN__)
    SSC_STR_ERR_SET_RUSSIAN,
#endif 
#if defined(__MMI_LANG_BULGARIAN__)
    SSC_STR_ERR_SET_BULGARIAN,
#endif 
#if defined(__MMI_LANG_UKRAINIAN__)
    SSC_STR_ERR_SET_UKRAINIAN,
#endif 
#if defined(__MMI_LANG_PORTUGUESE__)
    SSC_STR_ERR_SET_PORTUGUESE,
#endif 
#if defined(__MMI_LANG_TURKISH__)
    SSC_STR_ERR_SET_TURKISH,
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
    SSC_STR_ERR_SET_VIETNAMESE,
#endif 
#if defined(__MMI_LANG_INDONESIAN__)
    SSC_STR_ERR_SET_INDONESIAN,
#endif 
#if defined(__MMI_LANG_CZECH__)
    SSC_STR_ERR_SET_CZECH,
#endif 
#if defined(__MMI_LANG_MALAY__)
    SSC_STR_ERR_SET_MALAY,
#endif 
#if defined(__MMI_LANG_FINNISH__)
    SSC_STR_ERR_SET_FINNISH,
#endif 
#if defined(__MMI_LANG_HUNGARIAN__)
    SSC_STR_ERR_SET_HUNGARIAN,
#endif 
#if defined(__MMI_LANG_SLOVAK__)
    SSC_STR_ERR_SET_SLOVAK,
#endif 
#if defined(__MMI_LANG_DUTCH__)
    SSC_STR_ERR_SET_DUTCH,
#endif 
#if defined(__MMI_LANG_NORWEGIAN__)
    SSC_STR_ERR_SET_NORWEGIAN,
#endif 
#if defined(__MMI_LANG_SWEDISH__)
    SSC_STR_ERR_SET_SWEDISH,
#endif 
#if defined(__MMI_LANG_CROATIAN__)
    SSC_STR_ERR_SET_CROATIAN,
#endif 
#if defined(__MMI_LANG_ROMANIAN__)
    SSC_STR_ERR_SET_ROMANIAN,
#endif 
#if defined(__MMI_LANG_SLOVENIAN__)
    SSC_STR_ERR_SET_SLOVENIAN,
#endif 
#if defined(__MMI_LANG_GREEK__)
    SSC_STR_ERR_SET_GREEK,
#endif 
#if defined (__MMI_LANG_HEBREW__)
    SSC_STR_ERR_SET_HEBREW,
#endif
#if defined (__MMI_LANG_ARABIC__)
    SSC_STR_ERR_SET_ARABIC,
#endif
#if defined (__MMI_LANG_PERSIAN__)
    SSC_STR_ERR_SET_PERSIAN,
#endif 
#if defined (__MMI_LANG_URDU__)
    SSC_STR_ERR_SET_URDU,
#endif 
#if defined (__MMI_LANG_HINDI__)
    SSC_STR_ERR_SET_HINDI,
#endif
#if defined (__MMI_LANG_TAMIL__)
    SSC_STR_ERR_SET_TAMIL,
#endif 
#if defined (__MMI_LANG_BENGALI__)
    SSC_STR_ERR_SET_BENGALI,
#endif 
#if defined (__MMI_LANG_MARATHI__)
    SSC_STR_ERR_SET_MARATHI,
#endif 
#if defined (__MMI_LANG_PUNJABI__)
    SSC_STR_ERR_SET_PUNJABI,
#endif
#if defined (__MMI_LANG_TELUGU__)
    SSC_STR_ERR_SET_TELUGU,
#endif

    /* please add language ssc string definition above this line */
    SSC_SCR_ENGINEER_MODE_STR_ID,
    SSC_SCR_FACTORY_MODE_STR_ID,
    SSC_SCR_IMEI_CAPTION_ID,
    SSC_SCR_SW_VERSION_CAPTION_ID,
    SSC_SCR_HW_VERSION_CAPTION_ID,
    SSC_SCR_SERIAL_NUMBER_CAPTION_ID,
    SSC_STR_ERR_SET_DEFAULT,
    SSC_STR_ERR_SET_ENGLISH
} SSC_STR_ID_ENUM;

#endif /* __SSC_RES_DEF_H__ */

