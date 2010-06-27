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
 * gui_lang_viet.c
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
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_LANG_VIET_C
#define _MMI_LANG_VIET_C

/*  Include: MMI header file */
#include "MMI_features.h"
#ifdef __MMI_LANG_VIETNAMESE__
#include "gui_lang_viet.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
const U16 mmi_viet_vowel[] = {0x0041, 0x0045, 0x0049, 0x004F, 0x0055, 0x0059,
    0x0061, 0x0065, 0x0069, 0x006F, 0x0075, 0x0079,
    0x00C2, 0x00CA, 0x00D4, 0x00E2, 0x00EA, 0x00F4,
    0x0102, 0x0103, 0x01A0, 0x01A1, 0x01AF, 0x01B0
};
const U16 mmi_viet_vowel_tone[5][24] = { {0x00C0, 0x00C8, 0x00CC, 0x00D2, 0x00D9, 0x1EF2,
                                          0x00E0, 0x00E8, 0x00EC, 0x00F2, 0x00F9, 0x1EF3,
                                          0x1EA6, 0x1EC0, 0x1ED2, 0x1EA7, 0x1EC1, 0x1ED3,
                                          0x1EB0, 0x1EB1, 0x1EDC, 0x1EDD, 0x1EEA, 0x1EEB},
{0x00C1, 0x00C9, 0x00CD, 0x00D3, 0x00DA, 0x00DD,
 0x00E1, 0x00E9, 0x00ED, 0x00F3, 0x00FA, 0x00FD,
 0x1EA4, 0x1EBE, 0x1ED0, 0x1EA5, 0x1EBF, 0x1ED1,
 0x1EAE, 0x1EAF, 0x1EDA, 0x1EDB, 0x1EE8, 0x1EE9},
{0x00C3, 0x1EBC, 0x0128, 0x00D5, 0x0168, 0x1EF8,
 0x00E3, 0x1EBD, 0x0129, 0x00F5, 0x0169, 0x1EF9,
 0x1EAA, 0x1EC4, 0x1ED6, 0x1EAB, 0x1EC5, 0x1ED7,
 0x1EB4, 0x1EB5, 0x1EE0, 0x1EE1, 0x1EEE, 0x1EEF},
{0x1EA2, 0x1EBA, 0x1EC8, 0x1ECE, 0x1EE6, 0x1EF6,
 0x1EA3, 0x1EBB, 0x1EC9, 0x1ECF, 0x1EE7, 0x1EF7,
 0x1EA8, 0x1EC2, 0x1ED4, 0x1EA9, 0x1EC3, 0x1ED5,
 0x1EB2, 0x1EB3, 0x1EDE, 0x1EDF, 0x1EEC, 0x1EED},
{0x1EA0, 0x1EB8, 0x1ECA, 0x1ECC, 0x1EE4, 0x1EF4,
 0x1EA1, 0x1EB9, 0x1ECB, 0x1ECD, 0x1EE5, 0x1EF5,
 0x1EAC, 0x1EC6, 0x1ED8, 0x1EAD, 0x1EC7, 0x1ED9,
 0x1EB6, 0x1EB7, 0x1EE2, 0x1EE3, 0x1EF0, 0x1EF1}
};

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_viet_tone_mark
 * DESCRIPTION
 *  To get the type of the tone mark
 *  
 *  This is used to get the type of the tone mark.
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  viet_tone
 *****************************************************************************/
viet_tone_mark mmi_viet_tone_mark(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= 0x0300 && ch <= 0x0323)
    {
        if (0x0300 == ch)
        {
            return VIET_TONE_GRAVE_ACCENT;
        }
        else if (0x0301 == ch)
        {
            return VIET_TONE_ACCUTE_ACCENT;
        }
        else if (0x0303 == ch)
        {
            return VIET_TONE_TILDE;
        }
        else if (0x0309 == ch)
        {
            return VIET_TONE_HOOK_ABOVE;
        }
        else if (0x0323 == ch)
        {
            return VIET_TONE_DOT_BELOW;
        }
        else
        {
            return VIET_TONE_NONE;
        }
    }
    else
    {
        return VIET_TONE_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_viet_vowel_letter
 * DESCRIPTION
 *  To get the type of the vowel letter
 *  
 *  This is used to get the type of the vowel letter.
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  viet_vowel_letter
 *****************************************************************************/
viet_vowel_letter mmi_viet_vowel_letter(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= 0x0041 && ch <= 0x01B0)
    {
        if (0x0079 >= ch)
        {
            if (0x0059 >= ch)
            {
                if (0x0049 >= ch)
                {
                    if (0x0041 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_A;
                    }
                    else if (0x0045 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_E;
                    }
                    else if (0x0049 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_I;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
                else
                {
                    if (0x004F == ch)
                    {
                        return VIET_VOWEL_CAPITAL_O;
                    }
                    else if (0x0055 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_U;
                    }
                    else if (0x0059 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_Y;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
            }
            else
            {
                if (0x0069 >= ch)
                {
                    if (0x0061 == ch)
                    {
                        return VIET_VOWEL_SMALL_A;
                    }
                    else if (0x0065 == ch)
                    {
                        return VIET_VOWEL_SMALL_E;
                    }
                    else if (0x0069 == ch)
                    {
                        return VIET_VOWEL_SMALL_I;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
                else
                {
                    if (0x006F == ch)
                    {
                        return VIET_VOWEL_SMALL_O;
                    }
                    else if (0x0075 == ch)
                    {
                        return VIET_VOWEL_SMALL_U;
                    }
                    else if (0x0079 == ch)
                    {
                        return VIET_VOWEL_SMALL_Y;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
            }
        }
        else
        {
            if (0x00F4 >= ch)
            {
                if (0x00D4 >= ch)
                {
                    if (0x00C2 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_A_CIRCUMFLEX;
                    }
                    else if (0x00CA == ch)
                    {
                        return VIET_VOWEL_CAPITAL_E_CIRCUMFLEX;
                    }
                    else if (0x00D4 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_O_CIRCUMFLEX;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
                else
                {
                    if (0x00E2 == ch)
                    {
                        return VIET_VOWEL_SMALL_A_CIRCUMFLEX;
                    }
                    else if (0x00EA == ch)
                    {
                        return VIET_VOWEL_SMALL_E_CIRCUMFLEX;
                    }
                    else if (0x00F4 == ch)
                    {
                        return VIET_VOWEL_SMALL_O_CIRCUMFLEX;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
            }
            else
            {
                if (0x01A0 >= ch)
                {
                    if (0x0102 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_A_BREVE;
                    }
                    else if (0x0103 == ch)
                    {
                        return VIET_VOWEL_SMALL_A_BREVE;
                    }
                    else if (0x01A0 == ch)
                    {
                        return VIET_VOWEL_CAPITAL_O_HORN;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
                else
                {
                    if (0x01A1 == ch)
                    {
                        return VIET_VOWEL_SMALL_O_HORN;
                    }
                    else if (0x01AF == ch)
                    {
                        return VIET_VOWEL_CAPITAL_U_HORN;
                    }
                    else if (0x01B0 == ch)
                    {
                        return VIET_VOWEL_SMALL_U_HORN;
                    }
                    else
                    {
                        return VIET_VOWEL_NONE;
                    }
                }
            }
        }
    }
    else
    {
        return VIET_VOWEL_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_viet_combine_vowel_tone
 * DESCRIPTION
 *  To get the combination of the vowel and the tone mark
 *  
 *  This is used to get the combination of the vowel and the tone mark.
 * PARAMETERS
 *  vw      [IN]        Viet_tone vt
 *  vt      [IN]        
 * RETURNS
 *  UI_character_type
 *****************************************************************************/
UI_character_type mmi_viet_combine_vowel_tone(viet_vowel_letter vw, viet_tone_mark vt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vw != VIET_VOWEL_NONE && vt != VIET_TONE_NONE)
    {
        return (UI_character_type) mmi_viet_vowel_tone[vt][vw];
    }
    else
    {
        return (UI_character_type) 0x0020;
    }
}

#endif /* __MMI_LANG_VIETNAMESE__ */ 
#endif /* _MMI_LANG_VIET_C */ 

