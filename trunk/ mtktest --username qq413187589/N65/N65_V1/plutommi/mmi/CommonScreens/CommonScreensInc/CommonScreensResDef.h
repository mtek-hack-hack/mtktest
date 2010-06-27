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
 * Filename:
 * ---------
 *  CommonScreensenum.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : CommonScreensenum.h

   PURPOSE     : This file defines enum value for global resources used in Common Screens.

   REMARKS     : 

   AUTHOR      : MTK00866

   DATE     : 05-23-2005

**************************************************************/
#ifndef __COMMONSCREENS_RES_H__
#define __COMMONSCREENS_RES_H__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalDefs.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
    typedef enum
    {
        SCR_INPUT_METHOD_LIST = COMMON_SCREENS_BASE,
        SCR_SYMBOL_PICKER_SCREEN,
        SCR_INPUT_METHOD_AND_DONE,
        SCR_POPUP_SCREEN,
        SCR_CONFIRM_SCREEN,
        SCR_CONFIRM_WINDOW_SCREEN,
        SCR_QUICK_SEARCH_INPUT_METHOD_LIST,
        SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE,
        SCR_ID_ASM_MEM_FULL,
        SCR_AP_REQUIRED_INPUT_METHOD_LIST,
        SCR_APPMEM_STOP_PROMPT, 
        SCR_APPMEM_STOP_PROGRESSING,
        SCR_FRM_UNIT_TEST,
        SCR_COMMON_SCREENS_END
    } SCREENID_LIST_COMMON_SCREENS;

    typedef enum
    {
        /* STR_INPUT_METHOD_CAPTION=COMMON_SCREENS_BASE,==> replaced by Global String */
        STR_INPUT_METHOD_MENU_MULTITAP_ABC = COMMON_SCREENS_BASE,
        STR_INPUT_METHOD_MENU_MULTITAP_abc,
        STR_INPUT_METHOD_MENU_SMART_ABC,
        STR_INPUT_METHOD_MENU_SMART_abc,
        STR_INPUT_METHOD_MENU_SMART_Abc,
        STR_INPUT_METHOD_MENU_NUMERIC,
        STR_INPUT_METHOD_MENU_MULTITAP_BOPOMO,
        STR_INPUT_METHOD_MENU_BOPOMO,
        STR_INPUT_METHOD_MENU_TRADITIONAL_CHINESE_STROKE,
        STR_INPUT_METHOD_MENU_MULTITAP_PINYIN,
        STR_INPUT_METHOD_MENU_PINYIN,
        STR_INPUT_METHOD_MENU_SIMPLIFIED_CHINESE_STROKE,
        STR_INPUT_METHOD_MENU_INSERT_SYMBOLS,
        STR_INPUT_METHOD_MENU_SELECT_SYMBOL,
        #if defined (__MMI_MULTITAP_HINDI__) 
        STR_INPUT_METHOD_MENU_MULTITAP_HINDI,
        #endif
        STR_INPUT_METHOD_MENU_MULTITAP_U_SPANISH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_SPANISH,
        STR_INPUT_METHOD_MENU_SMART_U_SPANISH,
        STR_INPUT_METHOD_MENU_SMART_L_SPANISH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_DANISH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_DANISH,
        STR_INPUT_METHOD_MENU_SMART_U_DANISH,
        STR_INPUT_METHOD_MENU_SMART_L_DANISH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_POLISH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_POLISH,
        STR_INPUT_METHOD_MENU_SMART_U_POLISH,
        STR_INPUT_METHOD_MENU_SMART_L_POLISH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_FRENCH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_FRENCH,
        STR_INPUT_METHOD_MENU_SMART_U_FRENCH,
        STR_INPUT_METHOD_MENU_SMART_L_FRENCH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_GERMAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_GERMAN,
        STR_INPUT_METHOD_MENU_SMART_U_GERMAN,
        STR_INPUT_METHOD_MENU_SMART_L_GERMAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_ITALIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_ITALIAN,
        STR_INPUT_METHOD_MENU_SMART_U_ITALIAN,
        STR_INPUT_METHOD_MENU_SMART_L_ITALIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_RUSSIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_RUSSIAN,
        STR_INPUT_METHOD_MENU_SMART_U_RUSSIAN,
        STR_INPUT_METHOD_MENU_SMART_L_RUSSIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_BULGARIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_BULGARIAN,
        STR_INPUT_METHOD_MENU_SMART_U_BULGARIAN,
        STR_INPUT_METHOD_MENU_SMART_L_BULGARIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_UKRAINIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_UKRAINIAN,
        STR_INPUT_METHOD_MENU_SMART_U_UKRAINIAN,
        STR_INPUT_METHOD_MENU_SMART_L_UKRAINIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_THAI,
        STR_INPUT_METHOD_MENU_SMART_THAI,
        #if defined (__MMI_ZI_HINDI__) || defined (__MMI_T9_HINDI__) 
        STR_INPUT_METHOD_MENU_SMART_HINDI,
        #endif
        STR_INPUT_METHOD_MENU_MULTITAP_ARABIC,
        STR_INPUT_METHOD_MENU_ARABIC_NUMERIC,
        STR_INPUT_METHOD_MENU_SMART_ARABIC,
        STR_INPUT_METHOD_MENU_MULTITAP_PERSIAN,
        STR_INPUT_METHOD_MENU_SMART_PERSIAN,
        #if defined (__MMI_MULTITAP_URDU__)
        STR_INPUT_METHOD_MENU_MULTITAP_URDU,
        #endif
        #if defined (__MMI_ZI_URDU__) 
        STR_INPUT_METHOD_MENU_SMART_URDU,
        #endif
        STR_INPUT_METHOD_MENU_SMART_HEBREW,
        STR_INPUT_METHOD_MENU_MULTITAP_HEBREW,
        STR_INPUT_METHOD_MENU_MULTITAP_U_TURKISH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_TURKISH,
        STR_INPUT_METHOD_MENU_SMART_U_TURKISH,
        STR_INPUT_METHOD_MENU_SMART_L_TURKISH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_PORTUGUESE,
        STR_INPUT_METHOD_MENU_MULTITAP_L_PORTUGUESE,
        STR_INPUT_METHOD_MENU_SMART_U_PORTUGUESE,
        STR_INPUT_METHOD_MENU_SMART_L_PORTUGUESE,
        STR_INPUT_METHOD_MENU_MULTITAP_U_INDONESIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_INDONESIAN,
        STR_INPUT_METHOD_MENU_SMART_U_INDONESIAN,
        STR_INPUT_METHOD_MENU_SMART_L_INDONESIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_CZECH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_CZECH,
        STR_INPUT_METHOD_MENU_SMART_U_CZECH,
        STR_INPUT_METHOD_MENU_SMART_L_CZECH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_MALAY,
        STR_INPUT_METHOD_MENU_MULTITAP_L_MALAY,
        STR_INPUT_METHOD_MENU_SMART_U_MALAY,
        STR_INPUT_METHOD_MENU_SMART_L_MALAY,
        STR_INPUT_METHOD_MENU_MULTITAP_U_VIETNAMESE,
        STR_INPUT_METHOD_MENU_MULTITAP_L_VIETNAMESE,
        STR_INPUT_METHOD_MENU_SMART_U_VIETNAMESE,
        STR_INPUT_METHOD_MENU_SMART_L_VIETNAMESE,
        STR_INPUT_METHOD_MENU_MULTITAP_U_FINNISH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_FINNISH,
        STR_INPUT_METHOD_MENU_SMART_U_FINNISH,
        STR_INPUT_METHOD_MENU_SMART_L_FINNISH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_HUNGARIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_HUNGARIAN,
        STR_INPUT_METHOD_MENU_SMART_U_HUNGARIAN,
        STR_INPUT_METHOD_MENU_SMART_L_HUNGARIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_SLOVAK,
        STR_INPUT_METHOD_MENU_MULTITAP_L_SLOVAK,
        STR_INPUT_METHOD_MENU_SMART_U_SLOVAK,
        STR_INPUT_METHOD_MENU_SMART_L_SLOVAK,
        STR_INPUT_METHOD_MENU_MULTITAP_U_DUTCH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_DUTCH,
        STR_INPUT_METHOD_MENU_SMART_U_DUTCH,
        STR_INPUT_METHOD_MENU_SMART_L_DUTCH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_NORWEGIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_NORWEGIAN,
        STR_INPUT_METHOD_MENU_SMART_U_NORWEGIAN,
        STR_INPUT_METHOD_MENU_SMART_L_NORWEGIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_SWEDISH,
        STR_INPUT_METHOD_MENU_MULTITAP_L_SWEDISH,
        STR_INPUT_METHOD_MENU_SMART_U_SWEDISH,
        STR_INPUT_METHOD_MENU_SMART_L_SWEDISH,
        STR_INPUT_METHOD_MENU_MULTITAP_U_CROATIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_CROATIAN,
        STR_INPUT_METHOD_MENU_SMART_U_CROATIAN,
        STR_INPUT_METHOD_MENU_SMART_L_CROATIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_ROMANIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_ROMANIAN,
        STR_INPUT_METHOD_MENU_SMART_U_ROMANIAN,
        STR_INPUT_METHOD_MENU_SMART_L_ROMANIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_SLOVENIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_L_SLOVENIAN,
        STR_INPUT_METHOD_MENU_SMART_U_SLOVENIAN,
        STR_INPUT_METHOD_MENU_SMART_L_SLOVENIAN,
        STR_INPUT_METHOD_MENU_MULTITAP_U_GREEK,
        STR_INPUT_METHOD_MENU_MULTITAP_L_GREEK,
        STR_INPUT_METHOD_MENU_SMART_U_GREEK,
        STR_INPUT_METHOD_MENU_SMART_L_GREEK,
    #if defined(__MMI_LANG_HINDI__)
        STR_INPUT_METHOD_MENU_SELECT_VOWEL,
    #endif 
        /* please insert before here */
        STR_INPUT_METHOD_MENU_TOTAL,
    #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        STR_ID_IME_WRITING_LANGUAGE_123,
        STR_ID_IMG_WRITING_LANGUAGE_NONE,
    #endif
        STR_ID_APPMEM_WAITING_FOR_STOP,
        STR_ID_APPMEM_ATTR_STOPPING,
        STR_ID_APPMEM_PROMPT_STOP_APP,
        STR_ID_APPMEM_STOP, 
        STR_ID_APPMEM_WAIT,      
        STR_ID_APPMEM_OUT_OF_MEMORY,
        STR_ID_APPMEM_NOTIFY_STARTING_NEW,
        STR_ID_APPMEM_NOTIFY_STOPPED,
        STR_ID_APPMEM_NOTIFY_STOP_FAILED,       
        #if defined (__MMI_MULTITAP_MARATHI__) 
        STR_INPUT_METHOD_MENU_MULTITAP_MARATHI,
        #endif
        #if defined (__MMI_ZI_MARATHI__) 
        STR_INPUT_METHOD_MENU_SMART_MARATHI,
        #endif 
        #if defined (__MMI_MULTITAP_TAMIL__) 
		STR_INPUT_METHOD_MENU_MULTITAP_TAMIL,
        #endif
        #if defined (__MMI_ZI_TAMIL__) 
        STR_INPUT_METHOD_MENU_SMART_TAMIL,
        #endif
        #if defined (__MMI_MULTITAP_BENGALI__)  
        STR_INPUT_METHOD_MENU_MULTITAP_BENGALI,
        #endif
       #if defined (__MMI_ZI_BENGALI__) 
        STR_INPUT_METHOD_MENU_SMART_BENGALI,
        #endif
        #if defined (__MMI_MULTITAP_PUNJABI__) 
		STR_INPUT_METHOD_MENU_MULTITAP_PUNJABI,
        #endif
        #if defined (__MMI_ZI_PUNJABI__) 
        STR_INPUT_METHOD_MENU_SMART_PUNJABI,
        #endif
        #if defined (__MMI_MULTITAP_TELUGU__) 
		STR_INPUT_METHOD_MENU_MULTITAP_TELUGU,
        #endif
        #if defined (__MMI_ZI_TELUGU__) 
        STR_INPUT_METHOD_MENU_SMART_TELUGU,
        #endif
        STR_ID_COMMONSCREEN_STR_END
    } STRINGID_LIST_COMMON_SCREENS;
#ifdef __cplusplus
}
#endif 
#endif /* __COMMONSCREENS_RES_H__ */ 

