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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/dict/trilogy/adaptation/src/DictionaryCoreTRILOGY.c,v 1.1 2007/05/17 07:26:37 bw Exp $
*
* $Id: DictionaryCoreTRILOGY.c,v 1.1 2007/05/17 07:26:37 bw Exp $
*
* $Date: 2007/05/17 07:26:37 $
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
* $Log: DictionaryCoreTRILOGY.c,v $
* Revision 1.1  2007/05/17 07:26:37  bw
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
 * DictionaryCore.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for Dictionary implementation according to Trilogy Library
 * 
 * MMI uses U32 word ID and U8 char buffer for results. 
 * Adaptation layer: 
 * U32      as Word ID (Typecast it to U16) as is where is
 * U8    Word buffer    
 * U16      buffer to save ID's  
 *
 * NOTE: MMI should reset its buffer before passing any data to Adaptation layer
 * 
 * Author:
 * Amit Kumar
 * -------
 *
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_DICT_TRILOGY__

#include "stdC.h"
#include "PixtelDataTypes.h"
#include "DebugInitDef.h"
#include "Unicodexdcl.h"
#include "DictionaryCoreTRILOGY.h"
#include "DictionaryMain.h"

/* ------------------ Third part include file ---------------------- */
#include "Dict_core.h"
/*------------------------------------------------------------------*/

/*
 * Typedef
 */

/*
 * Define
 */
#define MMI_DICT_WORDS_MAX             50000    /* MAX Dict words */

/*
 * Local Variable
 */

/*------------------ Global Variable ------------*/

/* for optimization to pass to other functions */
U16 g_dict_focus_word[MMI_DICT_CORE_WORD_MAX + 1];
U16 g_dict_last_best_matched_word[MMI_DICT_CORE_WORD_MAX + 1];
S32 g_dict_initial_total = -1;
S32 g_dict_from_history = 1;
U16 meaning[MMI_DICT_MEANING_RESULT_MAX + 1];

/*
 * Global Function
 */
extern U8 *GetCurrGuiBuffer(U16 scrnid);
extern S32 DynamicListGetHighlightedItem(U8 *string);

/*-------------------------- Local Function------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_init
 * DESCRIPTION
 *  Initialize Dictionary Engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_dict_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*--------------------------------------------------------------------------*/
    DictCoreInit();
    /*--------------------------------------------------------------------------*/
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exit
 * DESCRIPTION
 *  Terminate Dictionary Engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_dict_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*--------------------------------------------------------------------------*/
    DictCoreDeInit();
    /*--------------------------------------------------------------------------*/
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_get_total_num
 * DESCRIPTION
 *  To give the maximum number of words in reference to the focus word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  word(?)         [IN]        
 * RETURNS
 *  Number of words.
 *****************************************************************************/
S32 mmi_dict_get_total_num(char *dict_word)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count, length, distance;
    U8 same_count;
    U8 string1[(MMI_DICT_CORE_WORD_MAX + 1)], string2[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 UCS2word[(MMI_DICT_CORE_WORD_MAX + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_dict_last_best_matched_word will be filled in exact,next and previous word API. */
    length = pfnUnicodeStrlen((S8*) g_dict_last_best_matched_word);

    if (length >= 2)
    {
        memset(string2, 0, MMI_DICT_CORE_WORD_MAX);
        AnsiiToUnicodeString((S8*) string1, (S8*) "zo");
        memcpy(string2, g_dict_last_best_matched_word, 4);
        mmi_dict_compare_ucs2_strings((S8*) string1, (S8*) string2, &same_count, &distance);
        if (distance > 0)
        {
            g_dict_initial_total = 6;
            return 6;
        }
        else
        {

            memset(UCS2word, 0, ENCODING_LENGTH);

            if (!pfnUnicodeStrlen((S8*) g_dict_last_best_matched_word))
            {
                g_dict_initial_total = 0;
                return 0;
            }

            for (count = 0; count < 6; count++)
            {
                memset(UCS2word, 0, ENCODING_LENGTH);
                DictCoreSearchWordNext(UCS2word);
                if (pfnUnicodeStrlen((S8*) UCS2word))
                {
                    continue;
                }
                else
                {
                    count = count + 1;
                    break;
                }
            }
            g_dict_initial_total = count;
            DictCoreSearchWord((U8*) g_dict_last_best_matched_word, UCS2word);
            return count;
        }
    }
    else
    {
        g_dict_initial_total = 6;
        return 6;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_get_word_by_indx
 * DESCRIPTION
 *  To provide the focused word and set focus to the next non similar word
 *  
 *  Nill
 * PARAMETERS
 *  lin             [IN]        
 *  Indx            [IN]        
 *  dict_word       [?]         
 *  word(?)         [OUT]       Give the focused word
 *  Language(?)     [IN]        Index,
 * RETURNS
 *  TRUE :if the next word exist
 *  FALSE:if next word does not exist.
 *****************************************************************************/
BOOL mmi_dict_get_word_by_indx(U8 lin, U32 Indx, char *dict_word)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordbuff[MMI_DICT_CORE_WORD_MAX + 1], UCS2word[MMI_DICT_CORE_WORD_MAX + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lin)
    {
        case DICT_ENGLISH:
        case DICT_CHINESE:
        {
            memset(wordbuff, 0, MMI_DICT_CORE_WORD_MAX);
            memset(UCS2word, 0, ENCODING_LENGTH);
            /*--------------------------------------------------------------------------*/
            DictCoreSearchWordNext(UCS2word);
            /*--------------------------------------------------------------------------*/

            if (pfnUnicodeStrlen((S8*) UCS2word))
            {
                wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';
                pfnUnicodeStrcpy((S8*) dict_word, (S8*) g_dict_focus_word);
                pfnUnicodeStrcpy((S8*) g_dict_focus_word, (S8*) UCS2word);
                return TRUE;
            }
            else
            {
                wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';
                pfnUnicodeStrcpy((S8*) dict_word, (S8*) g_dict_focus_word);
                return FALSE;

            }

        }
            break;

    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_wild_search
 * DESCRIPTION
 *  To provide wild card search
 *  
 *  wordlist array size should match with nfetch
 * PARAMETERS
 *  lin             [IN]        
 *  dict_word       [?]         
 *  mskip           [IN]        
 *  nfetch          [IN]        
 *  wordlist        [?]         
 *  array(?)        [IN]        Of structure (mmi_dict_id_str_struct) to get word
 *  Language(?)     [IN]        Wild card, no. of skip characters, no. of fetch characters,
 *  Best(?)         [OUT]       Matched Wordlist
 * RETURNS
 *  number of matched words found
 *****************************************************************************/
U32 mmi_dict_wild_search(U8 lin, char *dict_word, U32 mskip, U32 nfetch, void *wordlist[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];
    U16 UCS2word[MMI_DICT_CORE_WORD_MAX + 1];
    U32 Indx = 0;
    mmi_dict_id_str_struct *fetchlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fetchlist = (mmi_dict_id_str_struct*) wordlist;
    switch (lin)
    {
        case DICT_ENGLISH:
        case DICT_CHINESE:
        {
            pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);
            memset(UCS2word, 0, ENCODING_LENGTH);
            /*--------------------------------------------------------------------------*/
            DictCoreSearchWord((U8*) wordbuff, UCS2word);
            /*--------------------------------------------------------------------------*/
            if (!pfnUnicodeStrlen((S8*) UCS2word))
            {
                break;
            }

            pfnUnicodeStrcpy((S8*) fetchlist[0].dict_word, (S8*) UCS2word);

            for (Indx = 1; Indx < MMI_DICT_ID_FETCH_MAX; Indx++)
            {
                memset(UCS2word, 0, MMI_DICT_CORE_WORD_MAX);
                /*--------------------------------------------------------------------------*/
                DictCoreSearchWordNext(UCS2word);
                /*--------------------------------------------------------------------------*/
                if (!pfnUnicodeStrlen((S8*) UCS2word))
                {
                    break;
                }

                wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';
                pfnUnicodeStrcpy((S8*) fetchlist[Indx].dict_word, (S8*) UCS2word);
                fetchlist[Indx].dict_id = 0;

            }
        }
            break;
        default:
            break;

    }

    return Indx;    /* return number of matched words */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search
 * DESCRIPTION
 *  To provide word meaning form Dictionary
 *  
 *  Nill
 * PARAMETERS
 *  dict_word                       [?]         
 *  lin                             [IN]        
 *  lout                            [IN]        
 *  supp                            [IN]        
 *  fetchresult                     [?]         
 *  Structure(?)                    [OUT]       With result value
 *  Word(?)                         [IN]        Input language, Out put language, supplimentary feilds, structure
 *  mmi_dict_result_struct(?)       [IN]        To get result
 * RETURNS
 *  TRUE/False
 *****************************************************************************/
BOOL mmi_dict_exact_search(char *dict_word, U8 lin, U8 lout, U32 supp, void *fetchresult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordbuff[MMI_DICT_CORE_WORD_MAX + 1], UCS2word[MMI_DICT_CORE_WORD_MAX + 1], tmplen;

    mmi_dict_result_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (mmi_dict_result_struct*) fetchresult;

    switch (lin)
    {

        case DICT_ENGLISH:
        case DICT_CHINESE:
        {

            memset(meaning, 0, MMI_DICT_MEANING_RESULT_MAX);
            pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);
            /*--------------------------------------------------------------------------*/
            DictCoreSearchWord((U8*) wordbuff, UCS2word);
            /*--------------------------------------------------------------------------*/
            if (!pfnUnicodeStrlen((S8*) UCS2word))
            {
                return FALSE;
            }
            /*--------------------------------------------------------------------------*/
            DictCoreSearchMeaning(UCS2word, (U16*) meaning);
            /*--------------------------------------------------------------------------*/
            meaning[MMI_DICT_MEANING_RESULT_MAX] = 0;   /* extra care */
            tmplen = pfnUnicodeStrlen((S8*) meaning);
            if (tmplen == 0)
            {
                return FALSE;
            }
            if (tmplen >= MMI_DICT_MEANING_RESULT_MAX)
            {
                meaning[MMI_DICT_MEANING_RESULT_MAX] = 0;
            }
            pfnUnicodeStrcpy((S8*) result->dict_meaning, (S8*) meaning);

        }

        default:
            break;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search_id
 * DESCRIPTION
 *  This function set the focus to the word and returns the number of words user can fetch in reference to the focus word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  lin             [IN]        
 *  lout            [IN]        
 *  Word(?)         [IN]        Language - in, language -out
 * RETURNS
 *  always 1
 *****************************************************************************/
S32 mmi_dict_exact_search_id(char *dict_word, U8 lin, U8 lout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordbuff[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 UCS2word[(MMI_DICT_CORE_WORD_MAX + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pfnUnicodeStrlen((PS8) dict_word))
    {
        g_dict_from_history = 1;
    }

    /*--------------------------------------------------------------------------*/
    if (g_dict_initial_total != -1 && g_dict_initial_total != 1)
    {
        return 1;
    }

    pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);
    memset(UCS2word, 0, ENCODING_LENGTH);
    DictCoreSearchWord((U8*) dict_word, UCS2word);
    /*--------------------------------------------------------------------------*/
    if (pfnUnicodeStrlen((S8*) UCS2word))
    {
        memset(g_dict_focus_word, 0, ENCODING_LENGTH);
        pfnUnicodeStrcpy((S8*) g_dict_focus_word, (S8*) UCS2word);
        pfnUnicodeStrcpy((S8*) g_dict_last_best_matched_word, (S8*) UCS2word);
    }
    else
    {
        memset(g_dict_focus_word, 0, ENCODING_LENGTH);
        DictCoreSearchWord((U8*) g_dict_last_best_matched_word, UCS2word);
        pfnUnicodeStrcpy((S8*) g_dict_focus_word, (S8*) UCS2word);
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search_prev_id
 * DESCRIPTION
 *  This function set the focus to the  previous word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  steps           [IN]        Number of steps previous word is required.
 *  lin             [IN]        
 *  lout            [IN]        
 *  Word(?)         [IN]        Language - in, language -out
 * RETURNS
 *  1 : focus is set
 *  0 : focus not set
 *****************************************************************************/
S32 mmi_dict_exact_search_prev_id(char *dict_word, S32 steps, U8 lin, U8 lout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string1[(MMI_DICT_CORE_WORD_MAX + 1)], string2[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 UCS2String[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 wordBuff[(MMI_DICT_CORE_WORD_MAX + 1)];
    U8 same_count;
    S32 distance, count = 0;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_MAIN);
    if (g_dict_from_history == 0 && guiBuffer)
    {
        return 1;
    }

    DictCoreSearchWord((U8*) dict_word, string1);
    while (count < steps)
    {
        memset(wordBuff, 0, ENCODING_LENGTH);

        DictCoreGetPreviousWord(wordBuff);
        if (!pfnUnicodeStrlen((S8*) wordBuff))
        {
            return 0;
        }
        pfnUnicodeStrcpy((S8*) string2, (S8*) wordBuff);
        mmi_dict_compare_ucs2_strings((S8*) string1, (S8*) string2, &same_count, &distance);
        pfnUnicodeStrcpy((PS8) string1, (PS8) string2);

        if (distance != 0)
        {
            count++;
            if (count < steps)
            {
                DictCoreSearchWord((U8*) string2, UCS2String);
                continue;
            }
            else
            {
                DictCoreSearchWord((U8*) string2, string1);
                break;
            }
        }
    }

    memset(g_dict_focus_word, 0, ENCODING_LENGTH);
    if (pfnUnicodeStrlen((S8*) string1))
    {
        pfnUnicodeStrcpy((S8*) g_dict_focus_word, (S8*) string1);
    }

    if (guiBuffer && DynamicListGetHighlightedItem(NULL) != 0)
    {
        g_dict_from_history = 0;
    }

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search_next_id
 * DESCRIPTION
 *  This function set the focus to the  next word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  steps           [IN]        Number of steps
 *  lin             [IN]        
 *  lout            [IN]        
 *  Word(?)         [IN]        Language - in, language -out
 * RETURNS
 *  0 : focus is set
 *  1 : focus not set
 *****************************************************************************/
S32 mmi_dict_exact_search_next_id(char *dict_word, S32 steps, U8 lin, U8 lout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string1[(MMI_DICT_CORE_WORD_MAX + 1)], string2[(MMI_DICT_CORE_WORD_MAX + 1)];
    U8 same_count;
    S32 distance, count = 0;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_MAIN);
    if (g_dict_initial_total > 1)   /* initially we know the exact number, so no need to search next. */
    {
        g_dict_initial_total--;
        if (g_dict_initial_total == 1)
        {
            g_dict_initial_total = -1;
        }

        return 1;
    }
    /* from history,initially,the highted item is always 0. and it takes maximum 32 item, so no need to search */
    if (guiBuffer && DynamicListGetHighlightedItem(NULL) == 0)
    {
        g_dict_from_history = 1;
        return 1;
    }

    // while taking say 64th form history item, just find the first item...thereafter no need to make next.
    // first time g_dict_from_history will be 1
    if (g_dict_from_history == 0 && guiBuffer)
    {
        return 1;
    }

    g_dict_initial_total = -1;

    DictCoreSearchWord((U8*) dict_word, string1);
    if (steps == 0)
    {
        memset(g_dict_focus_word, 0, ENCODING_LENGTH);
        if (pfnUnicodeStrlen((S8*) string1))
        {
            pfnUnicodeStrcpy((S8*) g_dict_focus_word, (S8*) string1);
        }

        if (guiBuffer && DynamicListGetHighlightedItem(NULL) != 0)
        {
            g_dict_from_history = 0;
        }
        return 1;
    }

    while (count < steps)
    {
        memset(string2, 0, ENCODING_LENGTH);
        DictCoreSearchWordNext(string2);

        if (!pfnUnicodeStrlen((S8*) string2))
        {
            return 0;
        }

        mmi_dict_compare_ucs2_strings((S8*) string1, (S8*) string2, &same_count, &distance);
        pfnUnicodeStrcpy((PS8) string1, (PS8) string2);

        if (distance != 0)
        {
            count++;
            if (count > steps)
            {
                break;
            }
        }
    }
    memset(g_dict_focus_word, 0, ENCODING_LENGTH);
    if (pfnUnicodeStrlen((S8*) string2))
    {
        pfnUnicodeStrcpy((S8*) g_dict_focus_word, (S8*) string2);
    }

    if (guiBuffer && DynamicListGetHighlightedItem(NULL) != 0)
    {
        g_dict_from_history = 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_compare_ucs2_strings
 * DESCRIPTION
 *  string1 and string2 are all UCS2 strings, compare them case insensitively.
 *  will compare only length of "MMI_DICT_CORE_WORD_MAX".
 *  For Dictionary Use only .
 *  
 *  Nill
 * PARAMETERS
 *  string1             [?]         
 *  string2             [?]         
 *  same_count          [?]         
 *  distance            [OUT]       0 if string are same
 *  String1(?)          [IN]        String2, distance,same count
 *  samecount(?)        [OUT]       Number of characters found same
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dict_compare_ucs2_strings(S8 *string1, S8 *string2, U8 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 len1, len2;
    U8 max_len, min_len;
    U8 i;
    U16 code1, code2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *same_count = 0;
    *distance = 0;

    len1 = (U8) pfnUnicodeStrlen(string1);
    len2 = (U8) pfnUnicodeStrlen(string2);

    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len && i < MMI_DICT_CORE_WORD_MAX; i++) /* Use Max Phonebook Strlen as upper bound */
        /* for (i = 0; i < max_len; i++) */
    {
        /* If all characters are identical from 0 to min_len. */
        if (i >= min_len)
        {
            /* First is greater than second */
            if (len1 > len2)
            {
                *distance = (U16) string1[i * ENCODING_LENGTH];
            }
            /* First and second is congruence */
            else if (len1 == len2)
            {
                *distance = 0;
            }
            /* len1 < len2: First is less than second */
            else
            {
                *distance = -(U16) string2[i * ENCODING_LENGTH];
            }

            //if (min_len == 0)
            //     *distance = - *distance;

            break;
        }

        /* First, compare from 0 to min_len */
        else
        {
            memcpy(&code1, (string1 + i * ENCODING_LENGTH), 2);
            memcpy(&code2, (string2 + i * ENCODING_LENGTH), 2);

            if ((*distance = mmi_dict_compare_chars(code1, code2)) == 0)
            {
                *same_count = *same_count + 1;
            }
            /* First and second is not equal, return distance */
            else
            {
                break;
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_compare_chars
 * DESCRIPTION
 *  compare two characters case insensitively
 *  
 *  Nill
 * PARAMETERS
 *  char1       [IN]        
 *  char2       [IN]        
 * RETURNS
 *  0 : char are same
 *  non zero if not same
 *****************************************************************************/
S32 mmi_dict_compare_chars(U16 char1, U16 char2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* try UCS2 matching */
    if (char1 == char2)
    {
        return 0;
    }

    /* if not, try ASCII case-insensitive matching */
    else if ((char1 < 0x007E) && (char2 < 0x007E))
    {
        if ((char1 <= 0x007b) && (char1 >= 0x0061))
        {
            char1 -= 0x20;
        }
        if ((char2 <= 0x007b) && (char2 >= 0x0061))
        {
            char2 -= 0x20;
        }

        return char1 - char2;
    }

    /* no match */
    return char1 - char2;
}
#endif /* __MMI_DICT_TRILOGY__ */ 

