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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/InputMethod/ZI/project/U25_06B/v6_official/inc/zi8api.h,v 1.1 2007/05/17 07:26:36 bw Exp $
*
* $Id: zi8api.h,v 1.1 2007/05/17 07:26:36 bw Exp $
*
* $Date: 2007/05/17 07:26:36 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: zi8api.h,v $
* Revision 1.1  2007/05/17 07:26:36  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/* zi8api.h 
*/
/*****************************************************************************
* COPYRIGHT ZI AND SUBJECT TO CONFIDENTIALITY RESTRICTIONS                   *
*                                                                            *
* This file is the confidential and proprietary property of Zi Corporation   *
* of Canada, Inc. ("Zi") or one of its affiliates.                           *
**************************************************************************** */

/* Note: This file is ANSI C
**
** This file provides the definitions for constants and structures used in the
** eZiText core library.
**
** All of these definitions will generally remain the same regardless
** of platform.
**
*/
#include "zi8cfg.h" 
#include "zi8types.h"


/* prevent multiple inclusion */
#ifndef _ZI8_API_H
#define _ZI8_API_H 

#define ZI8TRUE                        1
#define ZI8FALSE                       0
#define ZI8NULL                        0

/* These ZI8_GETCHARSET_* are defined only for compatibility with version 3.0 */
#define ZI8_GETCHARSET_ZH              1
#define ZI8_GETCHARSET_ZH_TW           2
#define ZI8_GETCHARSET_ZH_HK           4
#define ZI8_GETCHARSET_ZH_ALL          7

#define ZI8_GETMODE_DEFAULT            0
#define ZI8_GETMODE_STROKES            0
#define ZI8_GETMODE_PINYIN             1
#define ZI8_GETMODE_BOPOMOFO           2
#define ZI8_GETMODE_1KEYPRESS_PINYIN   3
#define ZI8_GETMODE_1KEYPRESS_BOPOMOFO 4
#define ZI8_GETMODE_COMPONENTS_ONLY    5
#define ZI8_GETMODE_ROMAJI_2_HIRAGANA  6
#define ZI8_GETMODE_CANGJIE            7
#define ZI8_GETMODE_PINYIN_NAME        (0x80 | ZI8_GETMODE_PINYIN)
#define ZI8_GETMODE_BOPOMOFO_NAME      (0x80 | ZI8_GETMODE_BOPOMOFO)

#define ZI8_GETMODE_KEYPRESS_ICON      1

#define ZI8_GETCONTEXT_DEFAULT         0x01
#define ZI8_GETCONTEXT_SMS             0x01
#define ZI8_GETCONTEXT_SURNAME         0x02
#define ZI8_GETCONTEXT_JP_NAME         0x02
#define ZI8_GETCONTEXT_GIVENNAME       0x04
#define ZI8_GETCONTEXT_CHINESE_PUNCT   0x08
#define ZI8_GETCONTEXT_NO_RADICALS     0x40  /* ORed with other GetContext */
#define ZI8_GETCONTEXT_NO_DUPLICATE    0x80  /* ORed with other GetContext */
#define ZI8_GETCONTEXT_SINGLE_CHAR     0x20  /* ORed with other GetContext */

#define ZI8_GETOPTION_DEFAULT          0
#define ZI8_GETOPTION_CHARSNCOMPS      1
#define ZI8_GETOPTION_NOCOMPONENTS     2
#define ZI8_GETOPTION_ALLCOMPONENTS    3
#define ZI8_GETOPTION_SAMESOUND        4
#define ZI8_GETOPTION_WORDCHARCOUNT    5
#define ZI8_GETOPTION_NOCOMPLETION     2
#define ZI8_GETOPTION_GET_SPELLING2    0x80
#define ZI8_GETOPTION_GET_SPELLING     0x81
#define ZI8_GETOPTION_STRINGS          0x80
#define ZI8_GETOPTION_WSTRINGS         0x81
#define ZI8_GETOPTION_ROMAJI           1
#define ZI8_GETOPTION_HIRAGANA         2
#define ZI8_GETOPTION_KATAKANA         3
#define ZI8_GETOPTION_COMPOSITE        4
#define ZI8_GETOPTION_SMILEYS          5
#define ZI8_GETOPTION_HALFWIDTH        6 /* 1/2 width katakana */
#define ZI8_GETOPTION_HIRAGANA_INFO    0x40 /* Ored with option COMPOSITE */
#define ZI8_GETOPTION_STEM_INFO        0x80 /* Ored with other GetOption */
#define ZI8_GETOPTION_RBPROCESS        0x10 /* Ored with other GetOption */
#define ZI8_GETOPTION_INT_RBPROCESS    0x20 /* Ored with other GetOption */

#define ZI8_CHARSET_LATIN1             0
#define ZI8_CHARSET_UNICODE            1
#define ZI8_CHARSET_GSMDEFAULT         2

#define ZI8_LANG_GSMDEFAULT            0
#define ZI8_LANG_ZH                    1
#define ZI8_LANG_PY                    2
#define ZI8_LANG_EN                    3
#define ZI8_LANG_FR                    4
#define ZI8_LANG_DE                    5
#define ZI8_LANG_ES                    6

#define ZI8_LANG_PT                    8
#define ZI8_LANG_SV                    9
#define ZI8_LANG_FI                    10
#define ZI8_LANG_NO                    11
#define ZI8_LANG_DA                    12
#define ZI8_LANG_NL                    13
#define ZI8_LANG_EL                    14
#define ZI8_LANG_TR                    15
#define ZI8_LANG_JP                    16
#define ZI8_LANG_KO                    18
#define ZI8_LANG_AR                    19
#define ZI8_LANG_IN                    20
#define ZI8_LANG_MS                    21
#define ZI8_LANG_PL                    22
#define ZI8_LANG_CS                    23
#define ZI8_LANG_IW                    24
#define ZI8_LANG_VI                    25
#define ZI8_LANG_SK                    26
#define ZI8_LANG_EU                    27
#define ZI8_LANG_BN                    28
#define ZI8_LANG_HR                    29
#define ZI8_LANG_CH                    30
#define ZI8_LANG_ET                    31
#define ZI8_LANG_HI                    32
#define ZI8_LANG_HU                    33
#define ZI8_LANG_LV                    34
#define ZI8_LANG_LT                    35
#define ZI8_LANG_FA                    36
#define ZI8_LANG_PA                    37
#define ZI8_LANG_RO                    38
#define ZI8_LANG_RU                    39
#define ZI8_LANG_SR                    40
#define ZI8_LANG_SL                    41
#define ZI8_LANG_TH                    42
#define ZI8_LANG_UR                    43
#define ZI8_LANG_UK                    44
#define ZI8_LANG_TL                    45
#define ZI8_LANG_EN2                   46
#define ZI8_LANG_IT                    47
#define ZI8_LANG_IS                    48
#define ZI8_LANG_BG                    49
#define ZI8_LANG_PT2                   50
#define ZI8_LANG_ES2                   51
#define ZI8_LANG_FR2                   52
#define ZI8_LANG_MR                    53
#define ZI8_LANG_SW                    54
#define ZI8_LANG_GU                    55
#define ZI8_LANG_KN                    56
#define ZI8_LANG_TA                    57
#define ZI8_LANG_ARB                   127 
#define ZI8_AUXTABLE_ZH1               128
#define ZI8_AUXTABLE_JP1               129

#define ZI8_SUBLANG_DEFAULT            7

#define ZI8_SUBLANG_ZH                 1
#define ZI8_SUBLANG_ZH_TW              2
#define ZI8_SUBLANG_ZH_HK              4
#define ZI8_SUBLANG_ZH_ALL             7

#define ZI8_SUBLANG_EN_US              1
#define ZI8_SUBLANG_EN_UK              2
#define ZI8_SUBLANG_EN_ALL             7

#define ZI8_SUBLANG_PR_BR              1
#define ZI8_SUBLANG_PR_PR              2
#define ZI8_SUBLANG_PR_ALL             7

#define ZI8_COMPARE_EXACT              0x08
#define ZI8_COMPARE_MASK               0x07
#define ZI8_COMPARE_STROKE             1
#define ZI8_COMPARE_PINYIN             2
#define ZI8_COMPARE_BOPOMOFO           3
#define ZI8_COMPARE_STROKE_BYTYPESONLY 4
#define ZI8_COMPARE_CANGJIE            5
   
/* uwd search options */
#define ZI8_UWD_OPT_DEFAULT            0x00 /* seq. order based on the
                                               learning order */
#define ZI8_UWD_OPT_EXACTMATCH         0x01 /* exact match candidates first
                                               then followed by others */
#define ZI8_UWD_OPT_LATESTMATCH        0x02 /* latest match first followed by
                                               exact match candidates then
                                               followed by others */

#define ZI8_STROKE_WILDCARD            0
#define ZI8_STROKE_DOWN                1
#define ZI8_STROKE_DOT                 2
#define ZI8_STROKE_CURVED_HOOK         3
#define ZI8_STROKE_OVER                4
#define ZI8_STROKE_OVER_DOWN           5
#define ZI8_STROKE_DOWN_OVER           6
#define ZI8_STROKE_LEFT                7
#define ZI8_STROKE_OVER_DOWN_OVER      8
#define ZI8_STROKE_MORE                9
#define ZI8_STROKE_TURN                10

#define ZI8_CODE_WILDCARD              (ZI8_BASE_STROKES+ZI8_STROKE_WILDCARD)
#define ZI8_CODE_MORE                  (ZI8_BASE_STROKES+ZI8_STROKE_MORE)
#define ZI8_CODE_LEFT                  (ZI8_BASE_STROKES+ZI8_STROKE_LEFT)
#define ZI8_CODE_OVER                  (ZI8_BASE_STROKES+ZI8_STROKE_OVER)
#define ZI8_CODE_DOT                   (ZI8_BASE_STROKES+ZI8_STROKE_DOT)
#define ZI8_CODE_DOWN                  (ZI8_BASE_STROKES+ZI8_STROKE_DOWN)
#define ZI8_CODE_TURN                  (ZI8_BASE_STROKES+ZI8_STROKE_TURN)
#define ZI8_CODE_DOWN_OVER             (ZI8_BASE_STROKES+ZI8_STROKE_DOWN_OVER)
#define ZI8_CODE_OVER_DOWN             (ZI8_BASE_STROKES+ZI8_STROKE_OVER_DOWN)
#define ZI8_CODE_CURVED_HOOK           (ZI8_BASE_STROKES+ZI8_STROKE_CURVED_HOOK)
#define ZI8_CODE_OVER_DOWN_OVER     (ZI8_BASE_STROKES+ZI8_STROKE_OVER_DOWN_OVER)

#define ZI8_CODE_LATIN_PUNCT           (ZI8_BASE_LATIN_KEYS+1)
#define ZI8_CODE_LATIN_ABC             (ZI8_BASE_LATIN_KEYS+2)
#define ZI8_CODE_LATIN_DEF             (ZI8_BASE_LATIN_KEYS+3)
#define ZI8_CODE_LATIN_GHI             (ZI8_BASE_LATIN_KEYS+4)
#define ZI8_CODE_LATIN_JKL             (ZI8_BASE_LATIN_KEYS+5)
#define ZI8_CODE_LATIN_MNO             (ZI8_BASE_LATIN_KEYS+6)
#define ZI8_CODE_LATIN_PQRS            (ZI8_BASE_LATIN_KEYS+7)
#define ZI8_CODE_LATIN_TUV             (ZI8_BASE_LATIN_KEYS+8)
#define ZI8_CODE_LATIN_WXYZ            (ZI8_BASE_LATIN_KEYS+9)

#define ZI8_CODE_LATIN_KEY1            0x31
#define ZI8_CODE_LATIN_KEY2            (ZI8_BASE_LATIN_KEYS+2)
#define ZI8_CODE_LATIN_KEY3            (ZI8_BASE_LATIN_KEYS+3)
#define ZI8_CODE_LATIN_KEY4            (ZI8_BASE_LATIN_KEYS+4)
#define ZI8_CODE_LATIN_KEY5            (ZI8_BASE_LATIN_KEYS+5)
#define ZI8_CODE_LATIN_KEY6            (ZI8_BASE_LATIN_KEYS+6)
#define ZI8_CODE_LATIN_KEY7            (ZI8_BASE_LATIN_KEYS+7)
#define ZI8_CODE_LATIN_KEY8            (ZI8_BASE_LATIN_KEYS+8)
#define ZI8_CODE_LATIN_KEY9            (ZI8_BASE_LATIN_KEYS+9)
#define ZI8_CODE_LATIN_KEY0            (ZI8_BASE_LATIN_KEYS+10)

#define ZI8_CODE_SEPARATOR             (ZI8_BASE_PINYIN-1)
#define ZI8_CODE_PHONETIC_SEPARATOR    (ZI8_BASE_PINYIN-1)
#define ZI8_CODE_PINYIN_SEPARATOR      (ZI8_BASE_PINYIN-1)
#define ZI8_CODE_BPMF_SEPARATOR        (ZI8_BASE_PINYIN-1)
#define ZI8_CODE_CANGJIE_SEPARATOR     (0x20) /* ' ' */
#define ZI8_ONEKEY_SEPARATOR           (ZI8_BASE_LATIN_KEYS+13)

#define ZI8_CODE_BPMF_B                (ZI8_BASE_BPMF+0)
#define ZI8_CODE_BPMF_P                (ZI8_BASE_BPMF+1)
#define ZI8_CODE_BPMF_M                (ZI8_BASE_BPMF+2)
#define ZI8_CODE_BPMF_F                (ZI8_BASE_BPMF+3)
#define ZI8_CODE_BPMF_D                (ZI8_BASE_BPMF+4)
#define ZI8_CODE_BPMF_T                (ZI8_BASE_BPMF+5)
#define ZI8_CODE_BPMF_N                (ZI8_BASE_BPMF+6)
#define ZI8_CODE_BPMF_L                (ZI8_BASE_BPMF+7)
#define ZI8_CODE_BPMF_G                (ZI8_BASE_BPMF+8)
#define ZI8_CODE_BPMF_K                (ZI8_BASE_BPMF+9)
#define ZI8_CODE_BPMF_H                (ZI8_BASE_BPMF+10)
#define ZI8_CODE_BPMF_J                (ZI8_BASE_BPMF+11)
#define ZI8_CODE_BPMF_Q                (ZI8_BASE_BPMF+12)
#define ZI8_CODE_BPMF_X                (ZI8_BASE_BPMF+13)
#define ZI8_CODE_BPMF_ZH               (ZI8_BASE_BPMF+14)
#define ZI8_CODE_BPMF_CH               (ZI8_BASE_BPMF+15)
#define ZI8_CODE_BPMF_SH               (ZI8_BASE_BPMF+16)
#define ZI8_CODE_BPMF_R                (ZI8_BASE_BPMF+17)
#define ZI8_CODE_BPMF_Z                (ZI8_BASE_BPMF+18)
#define ZI8_CODE_BPMF_C                (ZI8_BASE_BPMF+19)
#define ZI8_CODE_BPMF_S                (ZI8_BASE_BPMF+20)
#define ZI8_CODE_BPMF_A                (ZI8_BASE_BPMF+21)
#define ZI8_CODE_BPMF_O                (ZI8_BASE_BPMF+22)
#define ZI8_CODE_BPMF_E                (ZI8_BASE_BPMF+23)
#define ZI8_CODE_BPMF_EH               (ZI8_BASE_BPMF+24)
#define ZI8_CODE_BPMF_AI               (ZI8_BASE_BPMF+25)
#define ZI8_CODE_BPMF_EI               (ZI8_BASE_BPMF+26)
#define ZI8_CODE_BPMF_AU               (ZI8_BASE_BPMF+27)
#define ZI8_CODE_BPMF_OU               (ZI8_BASE_BPMF+28)
#define ZI8_CODE_BPMF_AN               (ZI8_BASE_BPMF+29)
#define ZI8_CODE_BPMF_EN               (ZI8_BASE_BPMF+30)
#define ZI8_CODE_BPMF_ANG              (ZI8_BASE_BPMF+31)
#define ZI8_CODE_BPMF_ENG              (ZI8_BASE_BPMF+32)
#define ZI8_CODE_BPMF_ER               (ZI8_BASE_BPMF+33)
#define ZI8_CODE_BPMF_I                (ZI8_BASE_BPMF+34)
#define ZI8_CODE_BPMF_U                (ZI8_BASE_BPMF+35)
#define ZI8_CODE_BPMF_IU               (ZI8_BASE_BPMF+36)

#define ZI8_CODE_PINYIN_A              (ZI8_BASE_PINYIN+0)
#define ZI8_CODE_PINYIN_B              (ZI8_BASE_PINYIN+1)
#define ZI8_CODE_PINYIN_C              (ZI8_BASE_PINYIN+2)
#define ZI8_CODE_PINYIN_D              (ZI8_BASE_PINYIN+3)
#define ZI8_CODE_PINYIN_E              (ZI8_BASE_PINYIN+4)
#define ZI8_CODE_PINYIN_F              (ZI8_BASE_PINYIN+5)
#define ZI8_CODE_PINYIN_G              (ZI8_BASE_PINYIN+6)
#define ZI8_CODE_PINYIN_H              (ZI8_BASE_PINYIN+7)
#define ZI8_CODE_PINYIN_I              (ZI8_BASE_PINYIN+8)
#define ZI8_CODE_PINYIN_J              (ZI8_BASE_PINYIN+9)
#define ZI8_CODE_PINYIN_K              (ZI8_BASE_PINYIN+10)
#define ZI8_CODE_PINYIN_L              (ZI8_BASE_PINYIN+11)
#define ZI8_CODE_PINYIN_M              (ZI8_BASE_PINYIN+12)
#define ZI8_CODE_PINYIN_N              (ZI8_BASE_PINYIN+13)
#define ZI8_CODE_PINYIN_O              (ZI8_BASE_PINYIN+14)
#define ZI8_CODE_PINYIN_P              (ZI8_BASE_PINYIN+15)
#define ZI8_CODE_PINYIN_Q              (ZI8_BASE_PINYIN+16)
#define ZI8_CODE_PINYIN_R              (ZI8_BASE_PINYIN+17)
#define ZI8_CODE_PINYIN_S              (ZI8_BASE_PINYIN+18)
#define ZI8_CODE_PINYIN_T              (ZI8_BASE_PINYIN+19)
#define ZI8_CODE_PINYIN_U              (ZI8_BASE_PINYIN+20)
#define ZI8_CODE_PINYIN_V              (ZI8_BASE_PINYIN+21)
#define ZI8_CODE_PINYIN_W              (ZI8_BASE_PINYIN+22)
#define ZI8_CODE_PINYIN_X              (ZI8_BASE_PINYIN+23)
#define ZI8_CODE_PINYIN_Y              (ZI8_BASE_PINYIN+24)
#define ZI8_CODE_PINYIN_Z              (ZI8_BASE_PINYIN+25)

#define ZI8_CODE_TONES_1               (ZI8_BASE_TONES+0)
#define ZI8_CODE_TONES_2               (ZI8_BASE_TONES+1)
#define ZI8_CODE_TONES_3               (ZI8_BASE_TONES+2)
#define ZI8_CODE_TONES_4               (ZI8_BASE_TONES+3)
#define ZI8_CODE_TONES_5               (ZI8_BASE_TONES+4)

/* ONE KEY PRESS: KEYS MAPPING */
#define ZI8_ONEKEY_KEY1                (ZI8_BASE_LATIN_KEYS+1)
#define ZI8_ONEKEY_KEY2                (ZI8_BASE_LATIN_KEYS+2)
#define ZI8_ONEKEY_KEY3                (ZI8_BASE_LATIN_KEYS+3)
#define ZI8_ONEKEY_KEY4                (ZI8_BASE_LATIN_KEYS+4)
#define ZI8_ONEKEY_KEY5                (ZI8_BASE_LATIN_KEYS+5)
#define ZI8_ONEKEY_KEY6                (ZI8_BASE_LATIN_KEYS+6)
#define ZI8_ONEKEY_KEY7                (ZI8_BASE_LATIN_KEYS+7)
#define ZI8_ONEKEY_KEY8                (ZI8_BASE_LATIN_KEYS+8)
#define ZI8_ONEKEY_KEY9                (ZI8_BASE_LATIN_KEYS+9)
#define ZI8_ONEKEY_KEY0                (ZI8_BASE_LATIN_KEYS+10)
#define ZI8_ONEKEY_KEY11               (ZI8_BASE_LATIN_KEYS+11)
#define ZI8_ONEKEY_KEY12               (ZI8_BASE_LATIN_KEYS+12)

/* ONE KEY PRESS: PINYIN LETTERS MAPPING */
#define ZI8_ONEKEY_PY_EXACT            ZI8_ONEKEY_KEY1
#define ZI8_ONEKEY_PY_A                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_PY_B                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_PY_C                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_PY_D                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_PY_E                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_PY_F                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_PY_G                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_PY_H                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_PY_I                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_PY_J                ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_PY_K                ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_PY_L                ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_PY_M                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_PY_N                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_PY_O                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_PY_P                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_PY_Q                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_PY_R                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_PY_S                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_PY_T                ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_PY_U                ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_PY_V                ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_PY_W                ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_PY_X                ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_PY_Y                ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_PY_Z                ZI8_ONEKEY_KEY9

/* ONE KEY PRESS: BOPOMOFO (ZHUYIN) SYMBOLS MAPPING */
#define ZI8_ONEKEY_ZY_EXACT            ZI8_ONEKEY_KEY1
#define ZI8_ONEKEY_ZY_B                ZI8_ONEKEY_KEY1
#define ZI8_ONEKEY_ZY_P                ZI8_ONEKEY_KEY1
#define ZI8_ONEKEY_ZY_M                ZI8_ONEKEY_KEY1
#define ZI8_ONEKEY_ZY_F                ZI8_ONEKEY_KEY1
#define ZI8_ONEKEY_ZY_D                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_ZY_T                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_ZY_N                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_ZY_L                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_ZY_G                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_ZY_K                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_ZY_H                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_ZY_J                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_ZY_Q                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_ZY_X                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_ZY_ZH               ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_ZY_CH               ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_ZY_SH               ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_ZY_R                ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_ZY_Z                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_ZY_C                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_ZY_S                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_ZY_A                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_ZY_O                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_ZY_E                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_ZY_EH               ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_ZY_AI               ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_ZY_EI               ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_ZY_AU               ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_ZY_OU               ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_ZY_AN               ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_ZY_EN               ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_ZY_ANG              ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_ZY_ENG              ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_ZY_ER               ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_ZY_I                ZI8_ONEKEY_KEY0
#define ZI8_ONEKEY_ZY_U                ZI8_ONEKEY_KEY0
#define ZI8_ONEKEY_ZY_IU               ZI8_ONEKEY_KEY0

/* eZiTap KEY MAPPINGS */
#define ZI8_ONEKEY_TIMEOUT             (ZI8_BASE_LATIN_KEYS+14) 
#define ZI8_ONEKEY_SPACE               (ZI8_BASE_LATIN_KEYS+15) 
#define ZI8_ONEKEY_DONE                (ZI8_BASE_LATIN_KEYS+16) 
#define ZI8_ONEKEY_BS                  (ZI8_BASE_LATIN_KEYS+17) 
#define ZI8_ONEKEY_PREVIOUS            (ZI8_BASE_LATIN_KEYS+18) 
#define ZI8_ONEKEY_NEXT                (ZI8_BASE_LATIN_KEYS+19) 
#define ZI8_ONEKEY_PGUP                (ZI8_BASE_LATIN_KEYS+20) 
#define ZI8_ONEKEY_PGDN                (ZI8_BASE_LATIN_KEYS+21) 


#define ZI8_ERROR_PUD                  42
#define ZI8_ERROR_PUD_NO_ERROR         (ZI8_ERROR_PUD+0)
#define ZI8_ERROR_MAX_PUDS_EXCEEDED    (ZI8_ERROR_PUD+1)
#define ZI8_ERROR_BAD_PUD_FORMAT       (ZI8_ERROR_PUD+2)
#define ZI8_ERROR_BAD_PUD_HANDLE       (ZI8_ERROR_PUD+3)
#define ZI8_ERROR_PUD_UNCHANGED        (ZI8_ERROR_PUD+4)
#define ZI8_ERROR_PUD_NOSPACE          (ZI8_ERROR_PUD+5)
#define ZI8_ERROR_DUPLICATE            (ZI8_ERROR_PUD+6)
#define ZI8_ERROR_PUD_CORRUPTED        (ZI8_ERROR_PUD+7)
#define ZI8_ERROR_PUD_NOEXIST          (ZI8_ERROR_PUD+8)
#define ZI8_ERROR_PUD_INVALID_PLACE    (ZI8_ERROR_PUD+9)
#define ZI8_ERROR_PUD_SIZE_TOO_SMALL   (ZI8_ERROR_PUD+10)

#define ZI8RBC_OK                      0
#define ZI8RBC_INVALID_CMD             1
#define ZI8RBC_INVALID_ELEMENT         2
#define ZI8RBC_OVERFLOW                3

#define ZI8RBM_STARTCONVERSION         0
#define ZI8RBM_DONE                    1
#define ZI8RBM_REVERT                  2
#define ZI8RBM_NEXTPHRASE              3
#define ZI8RBM_PREVPHRASE              4
#define ZI8RBM_SLIDERIGHT              5
#define ZI8RBM_SLIDELEFT               6
#define ZI8RBM_GETCAND4PHRASE          7
#define ZI8RBM_NEXTCAND4PHRASE         8
#define ZI8RBM_PREVCAND4PHRASE         9
#define ZI8RBM_SETALGORITHM            10

#define ZI8RBA_DESCEND                 0
#define ZI8RBA_ASCEND                  1
#define ZI8RBA_CENTEROUT               2

#define ZI8MTC_WORD_FORMED             0
#define ZI8MTC_WORD_PREDICTED          1
#define ZI8MTC_OVERFLOW                2
#define ZI8MTC_ERROR_INPUT             3
#define ZI8MTC_NO_CHANGE               4
#define ZI8MTC_NEXTWORD_PREDICTION     5
#define ZI8MTC_LITERALS_FULL           6

#define ZI8_CASE_DEFAULT               0    /* preserve original case */
#define ZI8_CASE_UPPER                 1
#define ZI8_CASE_LOWER                 2
#define ZI8_CASE_TITLE                 3

#define ZI8_SO_DEFAULT                 0
#define ZI8_SO_EXACT_ROM_DATA          1
#define ZI8_SO_EXACT_PD_DATA           2
#define ZI8_SO_EXACT_UWD_DATA          3
#define ZI8_SO_EXACT_OEM_DATA          4
#define ZI8_SO_OTHERS_ROM_DATA         5
#define ZI8_SO_OTHERS_PD_DATA          6
#define ZI8_SO_OTHERS_UWD_DATA         7
#define ZI8_SO_OTHERS_OEM_DATA         8
#define ZI8_SO_MAX_SIZE                (ZI8_SO_OTHERS_OEM_DATA+1)

#define ZI8_CODE_CANGJIE_WILDCARD      (0x2A) /* '*' */
#define ZI8_CODE_CANGJIE_A             (0x41) /* 'A' */
#define ZI8_CODE_CANGJIE_B             (0x42) /* 'B' */
#define ZI8_CODE_CANGJIE_C             (0x43) /* 'C' */
#define ZI8_CODE_CANGJIE_D             (0x44) /* 'D' */
#define ZI8_CODE_CANGJIE_E             (0x45) /* 'E' */
#define ZI8_CODE_CANGJIE_F             (0x46) /* 'F' */
#define ZI8_CODE_CANGJIE_G             (0x47) /* 'G' */
#define ZI8_CODE_CANGJIE_H             (0x48) /* 'H' */
#define ZI8_CODE_CANGJIE_I             (0x49) /* 'I' */
#define ZI8_CODE_CANGJIE_J             (0x4A) /* 'J' */
#define ZI8_CODE_CANGJIE_K             (0x4B) /* 'K' */
#define ZI8_CODE_CANGJIE_L             (0x4C) /* 'L' */
#define ZI8_CODE_CANGJIE_M             (0x4D) /* 'M' */
#define ZI8_CODE_CANGJIE_N             (0x4E) /* 'N' */
#define ZI8_CODE_CANGJIE_O             (0x4F) /* 'O' */
#define ZI8_CODE_CANGJIE_P             (0x50) /* 'P' */
#define ZI8_CODE_CANGJIE_Q             (0x51) /* 'Q' */
#define ZI8_CODE_CANGJIE_R             (0x52) /* 'R' */
#define ZI8_CODE_CANGJIE_S             (0x53) /* 'S' */
#define ZI8_CODE_CANGJIE_T             (0x54) /* 'T' */
#define ZI8_CODE_CANGJIE_U             (0x55) /* 'U' */
#define ZI8_CODE_CANGJIE_V             (0x56) /* 'V' */
#define ZI8_CODE_CANGJIE_W             (0x57) /* 'W' */
#define ZI8_CODE_CANGJIE_X             (0x58) /* 'W' */
#define ZI8_CODE_CANGJIE_Y             (0x59) /* 'Y' */

#define ZI8_ONEKEY_CJ_A                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_CJ_B                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_CJ_C                ZI8_ONEKEY_KEY2
#define ZI8_ONEKEY_CJ_D                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_CJ_E                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_CJ_F                ZI8_ONEKEY_KEY3
#define ZI8_ONEKEY_CJ_G                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_CJ_H                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_CJ_I                ZI8_ONEKEY_KEY4
#define ZI8_ONEKEY_CJ_J                ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_CJ_K                ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_CJ_L                ZI8_ONEKEY_KEY5
#define ZI8_ONEKEY_CJ_M                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_CJ_N                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_CJ_O                ZI8_ONEKEY_KEY6
#define ZI8_ONEKEY_CJ_P                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_CJ_Q                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_CJ_R                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_CJ_S                ZI8_ONEKEY_KEY7
#define ZI8_ONEKEY_CJ_T                ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_CJ_U                ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_CJ_V                ZI8_ONEKEY_KEY8
#define ZI8_ONEKEY_CJ_W                ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_CJ_X                ZI8_ONEKEY_KEY9
#define ZI8_ONEKEY_CJ_Y                ZI8_ONEKEY_KEY9

/* ******************** */
/* structure of the API */
/* ******************** */

    /* For Japanese:
       correlates element groups in the element buffer to the character
       groups (word) in the candidate buffer
    */
    typedef struct _ZI8_CANDIDATE_INFO
    {
        ZI8UCHAR ElementItem;
        ZI8UCHAR CandidateItem;
    } ZI8_CANDIDATE_INFO;
    typedef struct _ZI8_CANDIDATE_INFO ZI8RAMPOINTER PZI8_CANDIDATE_INFO;

    typedef struct _ZI8GETPARAM
    {  
        ZI8UCHAR  Language;
        ZI8UCHAR  GetMode;
        ZI8UCHAR  SubLanguage;
        ZI8UCHAR  Context;
        ZI8UCHAR  GetOptions;
        PZI8WCHAR pElements;
        ZI8UCHAR  ElementCount;
        PZI8WCHAR pCurrentWord;
        ZI8UCHAR  WordCharacterCount;
        PZI8WCHAR pCandidates;
        ZI8UCHAR  MaxCandidates;
        ZI8WCHAR  FirstCandidate;
        ZI8UCHAR  wordCandidates;
        ZI8UCHAR  count;
        ZI8UCHAR  letters;
        PZI8UCHAR pScratch;
    } ZI8GETPARAM;
    typedef struct _ZI8GETPARAM ZI8RAMPOINTER PZI8GETPARAM;

    typedef struct _ZI8LISTPARAM
    {
        PZI8UCHAR pPhoneBook;
        ZI8UCHAR  OffsetAlphaField;
        ZI8UCHAR  AlphaFieldSize;
        ZI8UCHAR  EntrySize;
        ZI8UCHAR  Entries;
        PZI8UCHAR pScratch;
    } ZI8LISTPARAM;
    typedef struct _ZI8LISTPARAM ZI8RAMPOINTER PZI8LISTPARAM;

    typedef PZI8UCHAR (*PFZI8PHONEBOOK)(ZI8USHORT ElementIndex);

    typedef struct _ZI8LISTFUNCPARAM
    {
        PFZI8PHONEBOOK pPhoneBook;
        ZI8UCHAR       OffsetAlphaField;
        ZI8UCHAR       AlphaFieldSize;
        ZI8UCHAR       EntrySize;
        ZI8UCHAR       Entries;
        PZI8UCHAR      pScratch;
    } ZI8LISTFUNCPARAM;
    typedef struct _ZI8LISTFUNCPARAM ZI8RAMPOINTER PZI8LISTFUNCPARAM;

    /* This structure is used for the language table reference by
       Zi8InitializeDynamic()*/
    typedef struct _ZI8_LANGUAGE_ENTRY
    {
        ZI8UCHAR           Language;
        PZI8VOID           pTable;
    } ZI8_LANGUAGE_ENTRY;
    typedef struct _ZI8_LANGUAGE_ENTRY ZI8RAMPOINTER PZI8_LANGUAGE_ENTRY;


    /* These declarations support user defined phone book */
    typedef ZI8BOOL (*PFZI8GETUDPBENTRY)      ( ZI8USHORT Index,
                                                ZI8UCHAR CharSet,
                                                PZI8VOID pBuffer,
                                                ZI8UCHAR Length );

    typedef ZI8BOOL (*PFZI8GETOEMDATAENTRY)   ( ZI8USHORT usIndex,
                                                PZI8WCHAR pBuffer,
                                                ZI8UCHAR  uMaxBufferSize,
                                                PZI8VOID  pOther );

    typedef struct _ZI8RBPARAMS
    {
        ZI8UCHAR    Language;
        ZI8UCHAR    rbCommand;
        PZI8WCHAR   pElements;
        ZI8UCHAR    ElementCount;
        ZI8UCHAR    Context;
        PZI8WCHAR   pCompositeSentence;
        ZI8UCHAR    SentenceSize;
        ZI8UCHAR    NumOfPhrase;
        ZI8UCHAR    PhraseIndex;
        PZI8WCHAR   pAltCandidates;
        ZI8UCHAR    AltCandidatesSize;
        ZI8UCHAR    MaxCandidateCount;
        ZI8USHORT   TotalCandidateCount;
        ZI8UCHAR    CandidateIndex;
        ZI8UCHAR    CandidateArrangement;
        ZI8UCHAR    InternalUseBuffer[ZI8_INTERNAL_DATA_SIZE1];
    } ZI8RBPARAMS;
    typedef struct _ZI8RBPARAMS ZI8RAMPOINTER PZI8RBPARAMS;

    /* keymap layout structure for eZiTap */
    typedef struct _ZI8LAYOUTINFO
    {
        PZI8WCHAR	pKeyUpper[12];
        PZI8WCHAR	pKeyLower[12];
    } ZI8LAYOUTINFO;
    typedef struct _ZI8LAYOUTINFO ZI8RAMPOINTER PZI8LAYOUTINFO;

    /* I/O structure for eZiTap */
    typedef struct _ZI8MTPARAM
    {
        ZI8UCHAR    Language;
        PZI8WCHAR   pElements;
        ZI8WCHAR    ElementCount;
        PZI8WCHAR   pCandidates;
        ZI8WCHAR    SizeOfCandidatesBuff;
        PZI8WCHAR   pFormedWordW;
        ZI8WCHAR    SizeOfFormedWordWBuff;
        ZI8UCHAR    MaxCandidates;
        ZI8UCHAR    uMinWordLength;
        ZI8BOOL     bPredictOnTimeout;
        ZI8UCHAR    uCaseType;
        ZI8UCHAR    uCandCount;
        ZI8UCHAR    uConfirmedChars;
        ZI8UCHAR    uLastCharIndex;
        ZI8BOOL     bSkipAdd2UWD;
        ZI8UCHAR    InternalData[16];
        ZI8UCHAR    SubLanguage;
        PZI8WCHAR   pCurrentWord;
        ZI8UCHAR    WordCharacterCount;
        ZI8BOOL     bCircularCandidates;
        ZI8UCHAR    uActiveChars;           /* for 1st candidate */
        ZI8UCHAR    uRemainingChars;        /* for 1st candidate */
    } ZI8MTPARAM;
    typedef struct _ZI8MTPARAM ZI8RAMPOINTER PZI8MTPARAM;

#ifdef ZI8_NO_GLOBAL_VARIABLES

#define ZI8_GBL_PARM1        ZI8RAMPOINTER pGlobal
#define ZI8_GBL_PARM       , PZI8VOID      pGlobal

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8GetGlobalDataSize
                                              ( void );

#else /* #ifdef ZI8_NO_GLOBAL_VARIABLES */

#define ZI8_GBL_PARM1
#define ZI8_GBL_PARM

#endif /* #else    #ifdef ZI8_NO_GLOBAL_VARIABLES */

/* ******************************* */
/* prototypes of the API functions */
/* ******************************* */

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8Initialize
                                              ( void ZI8_GBL_PARM1 );    
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8InitializeDynamic
                                              ( PZI8VOID p
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetVersion
                                              ( void ZI8_GBL_PARM1 );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8GetBuildID
                                              ( void ZI8_GBL_PARM1 );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8GetOEMID
                                              ( void ZI8_GBL_PARM1 );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8SetCompareMode
                                              ( ZI8UCHAR compareMode,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C int      Zi8Compare
                                              ( const PZI8VOID string1,
                                                const PZI8VOID string2 
                                                ZI8_GBL_PARM );  
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsComponent
                                              ( ZI8WCHAR wc 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsCharacter
                                              ( ZI8WCHAR wc 
                                                ZI8_GBL_PARM );   
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsElement
                                              ( ZI8WCHAR wc 
                                                ZI8_GBL_PARM ); 
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8SetMaxNamesInUse
                                              ( ZI8USHORT usMaxSize 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8SetMaxWordLength
                                              ( ZI8UCHAR length 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetMaxWordLength
                                              ( void ZI8_GBL_PARM1 );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8SetMaxCountValue
                                              ( ZI8LONG maxCountValue 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetCandidates
                                              ( PZI8GETPARAM pGetParam 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8LONG  Zi8GetCandidatesCount
                                              ( PZI8GETPARAM pGetParam 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsMatch
                                              ( PZI8GETPARAM pGetParam,
                                                ZI8WCHAR c 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsMatch2
                                              ( PZI8GETPARAM pGetParam,
                                                PZI8WCHAR pWord 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetListCandidates
                                              ( PZI8GETPARAM pGetParam,
                                                PZI8LISTPARAM pListParam 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetListCandidatesFunc
                                              ( PZI8GETPARAM pGetParam,
                                                PZI8LISTFUNCPARAM pListParam
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsWordW
                                              ( PZI8WCHAR pWord,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsWordW2
                                              ( PZI8WCHAR pWord,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C void     Zi8GetAlphaWord
                                              ( ZI8UCHAR language,
                                                ZI8WCHAR wcCandidate,
                                                PZI8UCHAR szString,
                                                ZI8UCHAR size
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C void     Zi8GetAlphaWordW
                                              ( ZI8UCHAR language,
                                                ZI8WCHAR wcCandidate,
                                                PZI8WCHAR pwString,
                                                ZI8UCHAR size
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetChecksum
                                              ( ZI8UCHAR language,
                                                ZI8UCHAR TableType
                                                ZI8_GBL_PARM );
    /* optional routines for Chinese character conversions */
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8UnicodeToGB
                                              ( ZI8WCHAR wc
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8UnicodeToBig5
                                              ( ZI8WCHAR wc
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8GBToUnicode
                                              ( ZI8WCHAR wc
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8Big5ToUnicode
                                              ( ZI8WCHAR wc
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8ComplexToSimp
                                              ( PZI8WCHAR pCharacter,
                                                ZI8USHORT count
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8SimpToComplex
                                              ( PZI8WCHAR pCharacter,
                                                ZI8USHORT count
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetCharInfo
                                              ( ZI8WCHAR wc,
                                                PZI8WCHAR pCharInfoBuffer,
                                                ZI8UCHAR MaxInfoBuffer,
                                                ZI8UCHAR GetMode
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetCharInfo2
                                              ( ZI8WCHAR wc,
                                                PZI8WCHAR pCharInfoBuffer,
                                                ZI8UCHAR MaxInfoBuffer,
                                                ZI8UCHAR GetMode,
                                                PZI8WCHAR pElements,
                                                ZI8UCHAR uElementCount
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetCharInfo3
                                              ( ZI8WCHAR wc,
                                                PZI8WCHAR pCharInfoBuffer,
                                                ZI8UCHAR MaxInfoBuffer,
                                                ZI8UCHAR GetMode,
                                                PZI8WCHAR pElements,
                                                ZI8UCHAR uElementCount
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8GetCompID
                                              ( ZI8WCHAR wc
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetCompInfo
                                              ( ZI8WCHAR compID,
                                                PZI8WCHAR pInfo
                                                ZI8_GBL_PARM );
    /* functions for the Personal User Dictionary */
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8AttachPUD
                                              ( PZI8UCHAR pDict,
                                                ZI8USHORT size
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8DetachPUD
                                              ( ZI8UCHAR Pud,
                                                PZI8UCHAR pDict
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8GetPUDfreeSpace
                                              ( ZI8UCHAR Pud,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8AddUDWordW
                                              ( ZI8UCHAR Pud,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8DeleteUDWordW
                                              ( ZI8UCHAR Pud,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C PZI8VOID Zi8GetUDWordW
                                              ( ZI8UCHAR Pud,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR MaxChar, 
                                                PZI8GETPARAM pGetParam,
                                                PZI8VOID pPlace,
                                                ZI8BOOL bReverse
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8LONG  Zi8GetUDWordWCount
                                              ( ZI8UCHAR Pud,
                                                PZI8GETPARAM pGetParam
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8IsUDWordW
                                              ( ZI8UCHAR Pud,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8RefUDWordW
                                              ( ZI8UCHAR Pud, 
                                                PZI8WCHAR pWord, 
                                                ZI8UCHAR language 
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8RefUDWordW2
                                              ( ZI8UCHAR Pud, 
                                                PZI8WCHAR pWord, 
                                                ZI8UCHAR language, 
                                                ZI8UCHAR secondaryLanguage
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8GetLastError
                                              ( void ZI8_GBL_PARM1 );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8AttachUDPB
                                              ( PFZI8GETUDPBENTRY pUDPBEntry
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8DetachUDPB
                                              ( ZI8UCHAR udpbID, 
                                                PFZI8GETUDPBENTRY pUDPBEntry
                                                ZI8_GBL_PARM );
    /* These helper functions have been added to extract strings from
       the candidates buffer when the candidate words are inline and separated
       by zero value.
    */
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8Copy(  PZI8UCHAR pDestination,
                                                PZI8GETPARAM pGetParams,
                                                ZI8UCHAR index
                                                ZI8_GBL_PARM ); 
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8CopyW( PZI8WCHAR pDestination,
                                                PZI8GETPARAM pGetParams,
                                                ZI8UCHAR index
                                                ZI8_GBL_PARM ); 
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8CopyWordList
                                              ( PZI8UCHAR pDestination,
                                                ZI8UCHAR  MaxChar,
                                                PZI8UCHAR pWordList,
                                                ZI8UCHAR index
                                                ZI8_GBL_PARM ); 
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8CopyWordListW
                                              ( PZI8WCHAR pDestination,
                                                ZI8UCHAR  MaxChar,
                                                PZI8WCHAR pWordList,
                                                ZI8UCHAR index
                                                ZI8_GBL_PARM ); 
    /* functions for the Used Word Dictionary */
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8AttachUWD
                                              ( PZI8UCHAR pUWD,
                                                ZI8USHORT size
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8DetachUWD
                                              ( ZI8UCHAR UWD_id,
                                                PZI8UCHAR pUWD
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8AddUsedWordW
                                              ( ZI8UCHAR UWD_id,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8AddUsedWordW2
                                              ( ZI8UCHAR UWD_id,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR Language,
                                                ZI8UCHAR SubLanguage
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8AddUsedKanji
                                              ( ZI8UCHAR UWD_id,
                                                PZI8WCHAR pKanjiWord,
                                                PZI8WCHAR pHiragana
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8SetUWDsearchOption
                                              ( ZI8UCHAR newOpt
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8RBprocess
                                              ( PZI8RBPARAMS pRBParams
                                                ZI8_GBL_PARM );

    /* OTA ENHANCEMENT API */
    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8FreeSpaceSizePUD
                                              ( ZI8UCHAR Pud_ID
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8NewSubPDid
                                              ( ZI8UCHAR Pud_ID,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8AddSubPDWordW
                                              ( ZI8UCHAR Pud_ID,
                                                ZI8UCHAR SubPud_ID,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR language,
                                                ZI8BOOL bForce
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8DeleteSubPDWordW
                                              ( ZI8UCHAR Pud_ID,
                                                ZI8UCHAR SubPud_ID,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8DeleteSubPD
                                              ( ZI8UCHAR Pud_ID,
                                                ZI8UCHAR SubPud_ID,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C PZI8VOID Zi8GetSubPDWordW
                                              ( ZI8UCHAR Pud_ID,
                                                ZI8UCHAR SubPud_ID,
                                                PZI8WCHAR pWord,
                                                ZI8UCHAR MaxChar,
                                                PZI8GETPARAM pGetParam,
                                                PZI8VOID pPlace,
                                                ZI8BOOL bReverse
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8LONG Zi8GetSubPDWordWCount
                                              ( ZI8UCHAR Pud_ID,
                                                ZI8UCHAR SubPud_ID,
                                                PZI8GETPARAM pGetParam
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8SetSearchSubPDOrder
                                              ( ZI8UCHAR Pud_ID,
                                                PZI8UCHAR pSubPud_ID,
                                                ZI8UCHAR language,
                                                ZI8UCHAR numOfSubPDs
                                                ZI8_GBL_PARM );

    /* For latin: conversion between byte to/from Unicode */
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8ConvertUC2WC
                                              ( ZI8UCHAR uc,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8ConvertWC2UC
                                              ( ZI8WCHAR wc,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8ConvertWC2Key
                                              ( ZI8WCHAR wc,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );
    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8ConvertUC2Key
                                              ( ZI8UCHAR uc,
                                                ZI8UCHAR language
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8UTF8ToUCS2
                                              ( PZI8UCHAR UTF8Start,
                                                ZI8USHORT UTF8Size,
                                                PZI8WCHAR UCS2Start,
                                                ZI8USHORT UCS2Size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8UCS2ToUTF8
                                              ( PZI8WCHAR UCS2Start,
                                                ZI8USHORT UCS2Size,
                                                PZI8UCHAR UTF8Start,
                                                ZI8USHORT UTF8Size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8MTinitialize
                                              ( void
                                                ZI8_GBL_PARM1 );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8MTinitializeDynamic
                                              ( PZI8VOID pLanguageTable
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8MTsetLayout
                                              ( PZI8LAYOUTINFO pLayout
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8MTgetVersion
                                              ( void
                                                ZI8_GBL_PARM1 );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8MTgetBuildID
                                              ( void
                                                ZI8_GBL_PARM1 );

    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8MTgetOEMID
                                              ( void
                                                ZI8_GBL_PARM1 );

    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8MTgetDataVersion
                                              ( ZI8UCHAR lang 
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C PZI8WCHAR Zi8MTgetWordWptr
                                              ( PZI8WCHAR pCandidates,
                                                ZI8USHORT index
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8MTprocess
                                              ( PZI8MTPARAM pGetParam
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8MTgetCount4KeyLayout
                                              ( ZI8UCHAR ucLang,
                                                ZI8WCHAR key
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8MTgetKeyLayout
                                              ( ZI8UCHAR ucLang,
                                                ZI8BOOL bUpper,
                                                ZI8WCHAR wcKey,
                                                PZI8WCHAR pCharLayout
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8LONG Zi8MTgetCandidateCount
                                              ( PZI8MTPARAM pMTParam 
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8MTgetCurrentFirstCandidate
                                              ( PZI8MTPARAM pMTParam 
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8ConvertPY2ZY
                                              ( PZI8WCHAR pyBuff,
                                                ZI8WCHAR  pyBuffSize,
                                                PZI8WCHAR zyBuff,
                                                ZI8WCHAR  zyBuffSize
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8ConvertZY2PY
                                              ( PZI8WCHAR pyBuff,
                                                ZI8WCHAR  pyBuffSize,
                                                PZI8WCHAR zyBuff,
                                                ZI8WCHAR  zyBuffSize
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8ConvertChars2Ligature
                                              ( ZI8UCHAR language,
                                                PZI8WCHAR awcString,
                                                ZI8USHORT size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8ConvertLigature2Chars
                                              ( ZI8UCHAR language,
                                                PZI8WCHAR awcString,
                                                ZI8USHORT size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8ConvertKO2WC
                                              ( ZI8WCHAR wc_ko
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR Zi8ConvertWC2KO
                                              ( ZI8WCHAR wc
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8SetLatinSearchOrder
                                              ( PZI8UCHAR pSearchOrderArray,
                                                ZI8UCHAR  uArraySize 
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8SetPredictionStartAt
                                              ( ZI8UCHAR uIndex
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8AttachOEMdata
                                              ( PFZI8GETOEMDATAENTRY pEntry,
                                                ZI8USHORT size,
                                                PZI8VOID  pOther
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8DetachOEMdata
                                              ( ZI8UCHAR OEMdataID
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8VOID Zi8SetCandidateBufferSize
                                              ( ZI8USHORT size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8USHORT Zi8GetCandidateBufferSize
                                              ( void 
                                                ZI8_GBL_PARM1 );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL  Zi8SetHighlightedWordW
                                              ( PZI8WCHAR pwcWord,
                                                ZI8UCHAR Language,
                                                ZI8UCHAR SubLanguage
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8WCHAR  Zi8GetZHWordList
                                              ( PZI8WCHAR pCurrentWord,
                                                ZI8UCHAR  WordCharacterCount,
                                                ZI8UCHAR  SubLanguage,
                                                ZI8WCHAR  FirstCandidate,
                                                PZI8WCHAR pCandidates,
                                                ZI8UCHAR  MaxCandidates,
                                                ZI8WCHAR  MaxCandBufferSize,
                                                ZI8BOOL   bCompleteWord
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8UCHAR Zi8AttachUWD_ZH
                                              ( PZI8UCHAR pUWD_ZH,
                                                ZI8USHORT size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8DetachUWD_ZH
                                              ( ZI8UCHAR UWD_ZH_id,
                                                PZI8UCHAR pUWD_ZH
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8AddUsedWordW_ZH
                                              ( ZI8UCHAR UWD_ZH_id,
                                                PZI8WCHAR pWord,
                                                ZI8USHORT size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8ULONG Zi8AlphaCheckSum
                                              ( ZI8UCHAR Language
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8FKPWordW
                                              ( ZI8UCHAR language,
                                                ZI8WCHAR wcCandidate,
                                                PZI8WCHAR pwString,
                                                ZI8UCHAR size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C ZI8BOOL Zi8FKPWord
                                              ( ZI8UCHAR language,
                                                ZI8WCHAR wcCandidate,
                                                PZI8UCHAR szString,
                                                ZI8UCHAR size
                                                ZI8_GBL_PARM );

    ZI8FUNCTION ZI8_IMPORT_C PZI8UCHAR Zi8GetEngineCCFG
                                              ( void );

#endif /* #ifndef _ZI8_API_H */
