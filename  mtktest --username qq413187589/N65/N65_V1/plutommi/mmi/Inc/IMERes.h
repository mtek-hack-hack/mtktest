/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   IMERes.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is header file for IME structure for Multiple Bin.
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
#ifndef _IME_Res_H_
#define _IME_Res_H_

#include "MMI_features.h"

/* __CUSTPACK_MULTIBIN     Terry   BEGIN */
#define MAX_LDB_NUMBER 20
#include "CommonScreensenum.h"
#include "SettingDefs.h"
#include "gui_data_types.h"
#include "wgui_categories_inputsenum.h"
#include "EditorPenGprot.h"
#include "gui_virtual_keyboard.h"

/*  MBJ Hongyu Guo added @ 2007/02/06 */
typedef enum {
    IME_LANG_ATTR_NONE          = 0x0,
    IME_LANG_ATTR_ENGLISH_ONLY  = 0x1,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT = 0x02,
    IME_LANG_ATTR_ALPHABETIC    = 0x10,
    IME_LANG_ATTR_PHONETIC      = 0x20,
    IME_LANG_ATTR_STROKE        = 0x40,
    IME_LANG_ATTR_SYMBOLIC      = 0x80,
    IME_LANG_ATTR_NUMBERIC      = 0x100
}   ime_lang_attr_enum;

typedef enum {
    IME_MODE_ATTR_NONE          = 0x0,
    IME_MODE_ATTR_UPPERCASE     = 0x1,
    IME_MODE_ATTR_LOWERCASE     = 0x2,
    IME_MODE_ATTR_TITLECASE     = 0x4,
    IME_MODE_ATTR_SMART         = 0x10,
    IME_MODE_ATTR_MULTITAP      = 0x20,
    IME_MODE_ATTR_DIRECT        = 0x40,
    IME_MODE_ATTR_EXTSPELL      = 0x1000,  /* (for T9) request multitap symbol from external integration layer */
    IME_MODE_ATTR_SPSPELL       = 0x2000   /* allow ShuangPin? */
}   ime_mode_attr_enum;
/*  end - MBJ Hongyu Guo added @ 2007/02/06 */

typedef enum {
    IME_WRITING_LANG_ABC, /* English */
    IME_WRITING_LANG_FR, /* French */
    IME_WRITING_LANG_ES, /* SPANISH */
    IME_WRITING_LANG_DA, /* DANISH */
    IME_WRITING_LANG_PL, /* POLISH */
    IME_WRITING_LANG_PT, /* PORTUGUESE */
    IME_WRITING_LANG_IT, /* ITALIAN */
    IME_WRITING_LANG_DE, /* GERMAN */
    IME_WRITING_LANG_MS, /* MALAY */
    IME_WRITING_LANG_ID, /* INDONESIAN */
    IME_WRITING_LANG_CS, /* CZECH */
    IME_WRITING_LANG_NO, /* NORWEGIAN */
    IME_WRITING_LANG_SK, /*SLOVAK  */
    IME_WRITING_LANG_NL, /*DUTCH  */
    IME_WRITING_LANG_FI, /* FINNISH */
    IME_WRITING_LANG_HU, /* HUNGARIAN */
    IME_WRITING_LANG_VI, /* VIETNAMESE */
    IME_WRITING_LANG_TR, /* TURKISH */
    IME_WRITING_LANG_RU, /* RUSSIAN */
    IME_WRITING_LANG_BG, /* BULGARIAN */
    IME_WRITING_LANG_UK, /* UKRAINIAN */
    IME_WRITING_LANG_AR, /* ARABIC */
    IME_WRITING_LANG_PS, /* PERSIAN */
    IME_WRITING_LANG_HE, /* HEBREW */
    IME_WRITING_LANG_TH, /* Thai */
    IME_WRITING_LANG_EL, /* GREEK */
    IME_WRITING_LANG_ZHTW, /* Traditional Chinese */
    IME_WRITING_LANG_ZHCN, /* Simpled Chinese */
    IME_WRITING_LANG_SV, /* SWEDISH */
    IME_WRITING_LANG_SH, /* CROATIAN */
    IME_WRITING_LANG_RO, /* ROMANIAN */
    IME_WRITING_LANG_SL, /* SLOVENIAN */
    IME_WRITING_LANG_HI, /* HINDI */
    IME_WRITING_LANG_MR, /* MARATHI */
    IME_WRITING_LANG_UR, /* URDU */
    IME_WRITING_LANG_TA, /* Tamil */
    IME_WRITING_LANG_BE, /* Bengali */
    IME_WRITING_LANG_PA, /* Punjabi */
    IME_WRITING_LANG_TE, /* Telugu */
    IME_WRITING_LANG_123,
    IME_WRITING_LANG_NONE,
    IME_WRITING_LANG_TOTAL
}   ime_support_writing_lang_enum;

#define IME_IS_ENGLISH_ONLY(lang_attr)  (lang_attr & IME_LANG_ATTR_ENGLISH_ONLY > 0 ? 1 : 0)
#define IME_IS_MIXED_LANG_SUPPORT(lang_attr)    (((lang_attr) & (IME_LANG_ATTR_MIXED_LANG_SUPPORT)) > 0 ? 1 : 0 )
#define IME_IS_SMART_INPUT_METHOD(input_attr)   ((input_attr & (IME_MODE_ATTR_SMART)) > 0 ? 1 : 0) 
#define IME_IS_CHINESE_WRITING_LANG(wlang) (((wlang ==IME_WRITING_LANG_ZHTW) || (wlang == IME_WRITING_LANG_ZHCN) )) 

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
    #define MAX_WRITING_LANG 20
#endif


#if defined(__MMI_T9__)
#include "t9api.h"

typedef struct T9LdbMemData_s
{
    T9U16 wLdbNum;          /* Language ID */
    T9U32 nNumFullBlk;      /* Number of the blocks whose */
    /* data size is BLOCKSIZE. */
    /* BLOCKSIZE is the size of each */
    /* block with assumption that all */
    /* data blocks but the last one */
    /* are in the same size. */
    T9U32 dwLastBlkSize;    /* Size of the last data block if */
    /* its size is smaller than */
    /* BLOCKSIZE. Set to 0 if the */
    /* size equals BLOCKSIZE. And */
    /* this block should be added */
    /* into nNumFullBlk. */
#if defined(__MMI_T9_V7__)
    //START PMT VANDANA 20051506
    //Increased the size to 7 as russian has 7 language database arrays
    //PMT CZ_PO_TU START 20050812   
    //Increased the size to 9 as Turkish has 9 language database arrays
    //PMT NO_AR_SL_DU START 20050909
    //Increased the size to 10 as Arabic has 10 language database arrays
    //PMT LANGUAGE START 20051221
    //Increased the size to 12 as Greek has 11 language database arrays
    const T9U8 T9FARDATA *dwLdbDataBlk[12];
    //PMT LANGUAGE END 20051221
    //PMT NO_AR_SL_DU END 20050909
    //PMT CZ_PO_TU END 20050812     
    //END PMT
#else /* defined(__MMI_T9_V7__) */ 
    //START PMT VANDANA 20051506
    //PMT CZ_PO_TU START 20050812   
    //Increased the size to 9 as Turkish has 9 language database arrays
    //PMT NO_AR_SL_DU START 20050909
    //Increased the size to 10 as Arabic has 10 language database arrays
    //PMT LANGUAGE START 20051221
    //Increased the size to 12 as Greek has 11 language database arrays
    const T9U8 FARDATA *dwLdbDataBlk[12];
    //PMT LANGUAGE END 20051221
    //PMT NO_AR_SL_DU END 20050909
    //PMT CZ_PO_TU END 20050812     
    //END PMT
#endif /* defined(__MMI_T9_V7__) */ 
    /* Pointers to each data block. */
} T9LdbMemData;

#elif defined(__MMI_ZI__)
#include "zi8api.h"
#define ZI_TR_CHINESE 0
#define ZI_SIM_CHINESE 1
#endif 

typedef struct _IMEModeDetails
{
    SUPPORT_INPUT_MODES IME_Mode_ID;
    SUPPORT_INPUT_TYPES IME_Type_ID;
    U16 Common_Screen_StringID;
    U16 Prefered_IMEStringID;
    U16 Lang_Special_Attrib;
    U16 Mode_Special_Attrib;
    ime_support_writing_lang_enum lang_id;
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    U8 aLangCountryCode[LCC_SIZE];
#endif    
//Liu jun add 20070319
#if defined(__MMI_TOUCH_SCREEN__)
    U32 Handwriting_Attrib;
#endif/*__MMI_TOUCH_SCREEN__*/
//Liu jun add end
} sIMEModeDetails;

#if defined(__MMI_T9__)
typedef T9LdbMemData sIMELDBDetails;
#elif defined(__MMI_ZI__)
#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)
typedef ZI8_LANGUAGE_ENTRY sIMELDBDetails[MAX_LDB_NUMBER];
#else 
typedef ZI8_LANGUAGE_ENTRY sIMELDBDetails;
#endif 
#else 
typedef char sIMELDBDetails;
#endif 

typedef enum
{
    ZiV5,
    ZiV6,
    T9V6,
    T9V7,
    IME_OTHERS
} sIMEModuleDetails;

// for mixed lang support  
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
typedef struct
{
    ime_support_writing_lang_enum lang_id;
    UI_string_type lang_str_ptr;
    SUPPORT_INPUT_MODES default_input_mode;
#if defined(__MMI_MIXED_LANG_SUPPORT__)    
    MMI_BOOL mixed_lang_support;
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */
}ime_writing_lang_struct;
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */

//Liu jun add 20070319

#if defined(__MMI_TOUCH_SCREEN__)

#define IME_HAND_WRITING_ATTRIB(has_candidate, caps_lock_input_mode, vk_type, hand_writing_type) \
        (U32)(((has_candidate)<<24) | (((U8)caps_lock_input_mode)<<16) | (((U8)vk_type)<<8) | ((U8)hand_writing_type))

#define IME_HAN_WRITING_INVALID_INPUT_MODE 0xFF

#define IME_HAN_WRITING_INVALID_VK_TYPE 0xFF

#define IME_HAND_WRITING_INVALID IME_HAND_WRITING_ATTRIB(0, IME_HAN_WRITING_INVALID_INPUT_MODE, IME_HAN_WRITING_INVALID_VK_TYPE, 0)

#endif/*__MMI_TOUCH_SCREEN__*/

//Liu jun add end
        
/* __CUSTPACK_MULTIBIN     Terry   END */
#endif /* _IME_Res_H_ */ /* IME_RES_H */

