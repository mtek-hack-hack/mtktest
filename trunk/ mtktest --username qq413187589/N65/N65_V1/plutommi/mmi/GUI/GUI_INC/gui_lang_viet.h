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
 * gui_lang_viet.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for displaying Vietnamese Language
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_LANG_VIET_H
#define _MMI_LANG_VIET_H

#include "gui_data_types.h"
/* if some header should be include before this one */

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    VIET_VOWEL_CAPITAL_A,               /* 0x0041 */
    VIET_VOWEL_CAPITAL_E,               /* 0x0045 */
    VIET_VOWEL_CAPITAL_I,               /* 0x0049 */
    VIET_VOWEL_CAPITAL_O,               /* 0x004F */
    VIET_VOWEL_CAPITAL_U,               /* 0x0055 */
    VIET_VOWEL_CAPITAL_Y,               /* 0x0059 */
    VIET_VOWEL_SMALL_A,                 /* 0x0061 */
    VIET_VOWEL_SMALL_E,                 /* 0x0065 */
    VIET_VOWEL_SMALL_I,                 /* 0x0069 */
    VIET_VOWEL_SMALL_O,                 /* 0x006F */
    VIET_VOWEL_SMALL_U,                 /* 0x0075 */
    VIET_VOWEL_SMALL_Y,                 /* 0x0079 */
    VIET_VOWEL_CAPITAL_A_CIRCUMFLEX,    /* 0x00C2 */
    VIET_VOWEL_CAPITAL_E_CIRCUMFLEX,    /* 0x00CA */
    VIET_VOWEL_CAPITAL_O_CIRCUMFLEX,    /* 0x00D4 */
    VIET_VOWEL_SMALL_A_CIRCUMFLEX,      /* 0x00E2 */
    VIET_VOWEL_SMALL_E_CIRCUMFLEX,      /* 0x00EA */
    VIET_VOWEL_SMALL_O_CIRCUMFLEX,      /* 0x00F4 */
    VIET_VOWEL_CAPITAL_A_BREVE,         /* 0x0102 */
    VIET_VOWEL_SMALL_A_BREVE,           /* 0x0103 */
    VIET_VOWEL_CAPITAL_O_HORN,          /* 0x01A0 */
    VIET_VOWEL_SMALL_O_HORN,            /* 0x01A1 */
    VIET_VOWEL_CAPITAL_U_HORN,          /* 0x01AF */
    VIET_VOWEL_SMALL_U_HORN,            /* 0x01B0 */
    VIET_VOWEL_NONE
} viet_vowel_letter;

typedef enum
{
    VIET_TONE_GRAVE_ACCENT,     /* 0x0300 */
    VIET_TONE_ACCUTE_ACCENT,    /* 0x0301 */
    VIET_TONE_TILDE,            /* 0x0303 */
    VIET_TONE_HOOK_ABOVE,       /* 0x0309 */
    VIET_TONE_DOT_BELOW,        /* 0x0323 */
    VIET_TONE_NONE
} viet_tone_mark;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern const U16 mmi_viet_vowel_tone[5][24];

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern UI_character_type mmi_viet_combine_vowel_tone(viet_vowel_letter vw, viet_tone_mark vt);
extern viet_vowel_letter mmi_viet_vowel_letter(UI_character_type ch);
extern viet_tone_mark mmi_viet_tone_mark(UI_character_type ch);

#endif /* _MMI_LANG_VIET_H */ 

