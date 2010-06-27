/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/InputMethod/ZI/adaptation/include/Zi8HMI.h,v 1.3 2007/10/08 09:08:40 bw Exp $
*
* $Id: Zi8HMI.h,v 1.3 2007/10/08 09:08:40 bw Exp $
*
* $Date: 2007/10/08 09:08:40 $
*
* $Name: 1.3 $
*
* $Locker$
*
* $Revision: 1.3 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: Zi8HMI.h,v $
* Revision 1.3  2007/10/08 09:08:40  bw
* P_U25U26_06B_V30_M31_bw_0003 MTK升级软件V36 TO V68
*
* Revision 1.2  2007/07/28 05:11:00  bw
* UNI@bw_20070728 13:10:02   新然返回的最大长度为118, 改大MAX_COUNT_CANDIDATES
*
* Revision 1.1  2007/05/17 07:26:23  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
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
 *    zi8hmi.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for zi8hmi.c
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
#if !defined(__ZI8HMI_H__)
#define __ZI8HMI_H__

#include "zi8api.h"

/* *************** */
/* eZiText related */
/* *************** */
#define MAX_NEWWORD_LENGTH         64
#define MAX_WORD_LENGTH            MAX_NEWWORD_LENGTH
#define MAX_ELEMENT_BUFFERSIZE    128   /* 30//128 */
#define MAX_WORD_BUFFERSIZE       128
#define MAX_CAND_BUFFERSIZE       256
#define MAX_PHONETIC_BUFFERSIZE   128
/* PMT dara Added on 1/12/2k4 */
#ifdef MMI_LOW_MEMORY_PHONE
#define MAX_PHONETIC_CANDSIZE      2    /* 20 */
#else /* MMI_LOW_MEMORY_PHONE */ 
/* PMT end */
#define MAX_PHONETIC_CANDSIZE      5    /* 20 */
#endif /* MMI_LOW_MEMORY_PHONE */ 

/*UNI@bw_20070728 13:10:02   新然返回的最大长度为118, 改大MAX_COUNT_CANDIDATES */
#define MAX_COUNT_CANDIDATES       120//99 新然的最大长度是120

#define USE_ELEMENTIMAGES           1   /* set to 0
                                           if component images are integrated
                                           within the Chinese font file */
#define ELEMENT_IMAGESIZE          32

#define MT_MINWORDLENGTH            1   /* ctrl MT predicted min. word length */

#define PREDICTION_STARTAT          5

/* *************************** */
/* phone book and call related */
/* *************************** */
#define MAX_CHAR_FOR_NAME          16
#define MAX_CHAR_FOR_NUMBER        16
#define MAX_NUMBER_OF_CALL_ENTRY   10
#define MAX_NUMBER_OF_PB_ENTRY    256

/* *************** */
/* display related */
/* *************** */
#define DEFAULT_FONTSIZE           16
#define LARGE_FONTSIZE             24
#define SMALL_FONTSIZE             12

#define MAX_CHAR_PER_LINE          16
#define MAX_NUMBER_OF_LINES         8

#define MAX_CHAR_LABELTOP          14
#define MAX_CHAR_LABELSOFT         10

#define MAX_MESSAGE_LENGTH        650   /* 256 */

#define SPACINGH                    1

#define DEFAULT_CHAR_WIDTH         (DEFAULT_FONTSIZE/2)
#define DEFAULT_LINE_HEIGHT        (DEFAULT_FONTSIZE+SPACINGH)

#define DISPLAY_SCREEN_WIDTH       (MAX_CHAR_PER_LINE   * DEFAULT_CHAR_WIDTH)
#define DISPLAY_SCREEN_HEIGHT      (MAX_NUMBER_OF_LINES * DEFAULT_LINE_HEIGHT)

#define POS_LABELTOPX              32
#define POS_LABELTOPY            (-23)

#define LARGE_LINE_HEIGHT          (LARGE_FONTSIZE+SPACINGH)

#define TIMEOUT_INTERVAL           15   /* in 10th of a second */
#define TIMEOUT_DOUBLECLICK         2   /* in 10th of a second */

/* ***************************************** */
/* dictionary size: 4K for each (uwd and pd) */
/* ***************************************** */
#define MAX_DICTIONARY_SIZE      (1024 * 4)

/* *************** */
/* keypad keys' id */
/* *************** */
typedef enum
{
    KEYDUMMY = 0x8001,
    KEYTIMEOUT = 0x8002,
    KEYUNKNOWN = 0x8003,
    KEYLEFT = 0x8004,
    KEYRIGHT = 0x8005,
    KEYUP = 0x8006,
    KEYDOWN = 0x8007,
    KEYGREEN = 0x8008,
    KEYRED = 0x8009,
    KEYPOWER = 0x800A,
    KEYSOFTL = 0x800B,
    KEYSOFTR = 0x800C,
    KEY1 = 0x8031,
    KEY2 = 0x8032,
    KEY3 = 0x8033,
    KEY4 = 0x8034,
    KEY5 = 0x8035,
    KEY6 = 0x8036,
    KEY7 = 0x8037,
    KEY8 = 0x8038,
    KEY9 = 0x8039,
    KEYSTAR = 0x802A,
    KEYPLUS = 0x802B,
    KEY0 = 0x8030,
    KEYHASH = 0x8023
} KEYID;

typedef enum
{
    TIMER_FUNCTION = 102,
    TIMER_DISPLAY_CLOCK = 101
} TIMER_ACTION;

typedef enum
{
    MENU_SIMPLIFIED,
    MENU_TRADITIONAL,
    MENU_ENGLISH
} MENU_LANGUAGE;

typedef enum
{
    TEXTID_123,
    TEXTID_1BY1,
    TEXTID_ABC,
    TEXTID_ADD,
    TEXTID_ALL,
    TEXTID_AM,
    TEXTID_CALL,
    TEXTID_CALLING,
    TEXTID_CANCEL,
    TEXTID_CHINESE,
    TEXTID_CLEAR,
    TEXTID_CONNECTED,
    TEXTID_DELETE,
    TEXTID_DELETE_ALL,
    TEXTID_DELETED,
    TEXTID_DIALED,
    TEXTID_DONE,
    TEXTID_EMPTY_BOX,
    TEXTID_END,
    TEXTID_END_MUTE,
    TEXTID_ENGLISH,
    TEXTID_EZI,
    TEXTID_EZI_ABC,
    TEXTID_EZI_BOPOMOFO,
    TEXTID_EZI_CANGJIE,
    TEXTID_EZI_PINYIN,
    TEXTID_EZI_STROKE,
    TEXTID_FAILADDWORD,
    TEXTID_HK,
    TEXTID_INBOX,
    TEXTID_LANG,
    TEXTID_MAIN_MENU,
    TEXTID_MESSAGE,
    TEXTID_MESSAGES,
    TEXTID_MODIFIED,
    TEXTID_MODIFY,
    TEXTID_MUTE,
    TEXTID_NAME,
    TEXTID_NEWWORD,
    TEXTID_NO,
    TEXTID_NO_LAST_DAILED_NUMBERS,
    TEXTID_NO_PHONE_NUMBERS,
    TEXTID_NO_UD_WORD,
    TEXTID_NUMBER,
    TEXTID_OPTIONS,
    TEXTID_ORDER_BOPOMOFO,
    TEXTID_ORDER_PINYIN,
    TEXTID_ORDER_STROKE,
    TEXTID_ORDER_UNICODE,
    TEXTID_OUTBOX,
    TEXTID_PB_ORDER,
    TEXTID_PHONEBOOK,
    TEXTID_PHONEBOOK2,
    TEXTID_PM,
    TEXTID_PRC,
    TEXTID_SAVE,
    TEXTID_SAVED,
    TEXTID_SEARCH,
    TEXTID_SELECT,
    TEXTID_SEND,
    TEXTID_SENDING,
    TEXTID_SENDMESSAGE,
    TEXTID_SETTINGS,
    TEXTID_SIMPLIFIED,
    TEXTID_START,
    TEXTID_STOP,
    TEXTID_SYM,
    TEXTID_TRADITIONAL,
    TEXTID_TW,
    TEXTID_UD,
    TEXTID_VIEW,
    TEXTID_WRITE,
    TEXTID_YES,

    TEXTID_NONE
} TEXT_IDS;

typedef enum
{
    OBJECTID_CARET,
    OBJECTID_BOX,
    OBJECTID_TEXT,
    OBJECTID_IMAGE
} OBJECT_IDS;

typedef enum
{
    ATTRIB_UNDERLINE,
    ATTRIB_REVERSE,
    ATTRIB_GREY,
    ATTRIB_UNDERLINE_REVERSE,
    ATTRIB_UNDERLINE_GREY,
    ATTRIB_NONE
} DISPLAY_ATTRIB;

typedef enum
{
    IME_NAME_TEXT,
    IME_NUMBER_TEXT,
    IME_SEARCH_PB_TEXT,
    IME_NORMAL_TEXT
} IME_TEXT_TYPE;

typedef enum
{
    IME_SKIP,
    IME_CANCEL,
    IME_CONTINUE,
    IME_DONE
} IME_RETURN_CODE;

typedef enum
{
    CALLOPT_CALL,
    CALLOPT_SEND,
    CALLOPT_SAVE,
    CALLOPT_MODIFY,
    CALLOPT_DELETE
} CALL_OPTIONS;

typedef enum
{
    MENU_PHONEBOOK,
    MENU_MESSAGES,
    MENU_SETTINGS,

    MENU_NOT_SELECTED
} MENU_ENTRIES;

typedef enum
{
    PHONEBOOK_IMAGE,
    MESSAGES_IMAGE,
    SETTINGS_IMAGE
} IMAGES_IDS;

typedef enum
{
    SUBMENU_PB_SEARCH,
    SUBMENU_PB_ADD,
    SUBMENU_PB_DELETE,
    SUBMENU_PB_EDIT,
    SUBMENU_PB_ORDER,

    SUBMENU_MESSAGES_INBOX,
    SUBMENU_MESSAGES_OUTBOX,
    SUBMENU_MESSAGES_WRITE,

    SUBMENU_SETTINGS_LANGUAGE,
    SUBMENU_SETTINGS_DICTIONARY,

    SUBMENU_DICTIONARY_ENGLISH,
    SUBMENU_DICTIONARY_CHINESE,

    SUBMENU_UD_ADD,
    SUBMENU_UD_DELETE,

    SUBMENU_DELETE_1BY1,
    SUBMENU_DELETE_ALL,

    SUBMENU_LANG_ENGLISH,
    SUBMENU_LANG_SIMPLIFIED,
    SUBMENU_LANG_TRADITIONAL,

    SUBMENU_NOT_SELECTED
} SUBMENU_ENTRIES;

typedef enum
{
    ADDWORD_FAILED,
    ADDWORD_OK
} ADDWORD_RETURN_CODE;

typedef enum
{
    ENGLISH_LANGUAGE,
    CHINESE_LANGUAGE,
    NUMBER_LANGUAGE,
    ANY_LANGUAGE
} SUPPORTED_LANGUAGES;

typedef enum
{
    PB_ORDER_UNICODE,
    PB_ORDER_STROKE,
    PB_ORDER_PINYIN,
    PB_ORDER_BOPOMOFO
} PB_ORDER;

typedef enum
{
    INPUT_NONE,
    INPUT_EZI_STROKE,
    INPUT_EZI_PINYIN,
    INPUT_EZI_BOPOMOFO,
    INPUT_EZI_CANGJIE,
    INPUT_EZI_ABC,
    INPUT_ABC,
    INPUT_123,
    INPUT_SYM,
    INPUT_EZI_MULTITAP_PINYIN,
    INPUT_EZI_MULTITAP_BOPOMOFO,
    INPUT_EZI_THAI,
    INPUT_EZI_RUSSIAN,
    INPUT_EZI_FRENCH,
    INPUT_EZI_GERMAN,
    INPUT_EZI_ITALIAN,
    INPUT_EZI_SPANISH,
    INPUT_EZI_HINDI,
    INPUT_EZI_ARABIC,
    INPUT_EZI_PERSIAN,
    INPUT_EZI_NORWEGIAN,
    INPUT_EZI_POLISH,
    INPUT_EZI_HEBREW,
    INPUT_EZI_PORTUGUESE,
    INPUT_EZI_TURKISH,
    INPUT_EZI_MALAY,
    INPUT_EZI_INDONESIAN,
    INPUT_EZI_VIETNAMESE,
    INPUT_EZI_SLOVAK,
    INPUT_EZI_DUTCH,
    INPUT_EZI_SWEDISH,
    INPUT_EZI_CROATIAN,
    INPUT_EZI_ROMANIAN,
    INPUT_EZI_SLOVENIAN,
    INPUT_EZI_GREEK,
    INPUT_EZI_CZECH,
    INPUT_EZI_FINNISH,
    INPUT_EZI_DANISH,
    INPUT_EZI_HUNGARIAN,
    INPUT_EZI_BULGARIAN
} INPUT_MODE;

typedef enum
{
    ALPHA_LANG_EN,
    ALPHA_LANG_FR,
    ALPHA_LANG_EN_FR,
    ALPHA_LANG_FR_EN,
    ALPHA_LANG_RU,
    ALPHA_LANG_DE,
    ALPHA_LANG_IT,
    ALPHA_LANG_ES,
    ALPHA_LANG_PT,
    ALPHA_LANG_TR,
    ALPHA_LANG_MS,
    ALPHA_LANG_ID,
    ALPHA_LANG_VI,
    ALPHA_LANG_SK,
    ALPHA_LANG_PL,
    ALPHA_LANG_NO,
    ALPHA_LANG_NL,
    ALPHA_LANG_SV,
    ALPHA_LANG_HR,
    ALPHA_LANG_RO,
    ALPHA_LANG_SL,
    ALPHA_LANG_EL,
    ALPHA_LANG_CZ,
    ALPHA_LANG_FI,
    ALPHA_LANG_DA,
    ALPHA_LANG_HI,
    ALPHA_LANG_HU,
    ALPHA_LANG_BG
} ALPHA_LANGUAGE;

typedef enum
{
    PHONETIC_1_STEP,
    PHONETIC_2_STEPS,
    PHONETIC_1_N_2_STEPS,
    PHONETIC_DIRECT,
    PHONETIC_MULTITAP
} IME_PHONETIC_METHOD;

typedef struct _DISPLAY_OBJECT
{
    struct _DISPLAY_OBJECT *pNext;
    OBJECT_IDS objectType;
    DISPLAY_ATTRIB display_attrib;
    int fontSize;
    int x;
    int y;
    int width;
    int height;
    int numOfChar;
    union
    {
        PZI8WCHAR text;
        PZI8UCHAR pixels;
    } data;

} DISPLAY_OBJECT, *PDISPLAY_OBJECT;

typedef struct _TEXT_SYSTEM
{
    TEXT_IDS textID;
    ZI8WCHAR ZI8ROMDATA ZI8ROMPOINTER English;
    ZI8WCHAR ZI8ROMDATA ZI8ROMPOINTER Simplified;
    ZI8WCHAR ZI8ROMDATA ZI8ROMPOINTER Traditional;

} TEXT_SYSTEM, *PTEXT_SYSTEM;

typedef struct _PHONE_BOOK
{
    ZI8WCHAR name[MAX_CHAR_FOR_NAME + 1];
    ZI8WCHAR number[MAX_CHAR_FOR_NUMBER + 1];
} PHONE_BOOK, *PPHONE_BOOK;

typedef struct _PHONENUMBER
{
    ZI8WCHAR number[MAX_CHAR_FOR_NUMBER + 1];
} PHONENUMBER, *PPHONENUMBER;

typedef struct _PREDEFINED_WORDS
{
    ZI8WCHAR ZI8ROMDATA ZI8ROMPOINTER pWord;
    ZI8UCHAR language;
} PREDEFINED_WORDS, *PPREDEFINED_WORDS;

/* typedef int (*PIMEPROCESSKEYFUNC)( int, int, int ); */
typedef IME_RETURN_CODE(*PIMEPROCESSKEYFUNC) (KEYID, int, int);

#define ZI_FRAME_SKIP_TIMEOUT  100
#define ZI_FRAME_START_TIMEOUT  100
#ifdef MMI_LOW_MEMORY_PHONE
#define ZI_CANDIDATE_BUFFER_SIZE 5      // 8 /* Number of characters per selection page */
#else 
#define ZI_CANDIDATE_BUFFER_SIZE ((UI_device_width)/gui_get_character_width(0x4E00)-2)  // 7 8 /* Number of characters per selection page */
#endif 
#define ZI_CANDIDATE_MAX_BUFFER_SIZE 256
#define ZI_COMPOSITION_BUFFER_SIZE         MAX_PHONETIC_BUFFERSIZE

#define ZI_IN_CATEGORY_5_FLAG                                                       0x0001
#define ZI_IN_CATEGORY_28_FLAG                                                     0x0002
#define ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG                    0x0004
#define ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG              0x0008

#define ZI_MULTITAP_TIMER_DURATION      800

#endif /* !defined(__ZI8HMI_H__) */ 

