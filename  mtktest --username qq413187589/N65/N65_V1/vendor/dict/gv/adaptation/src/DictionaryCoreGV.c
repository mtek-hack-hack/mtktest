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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/dict/gv/adaptation/src/DictionaryCoreGV.c,v 1.1 2007/05/17 07:26:37 bw Exp $
*
* $Id: DictionaryCoreGV.c,v 1.1 2007/05/17 07:26:37 bw Exp $
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
* $Log: DictionaryCoreGV.c,v $
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
 *   This file intends for Dictionary implementation of GV Engine.
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
#ifdef __MMI_DICT_GV__

#include "stdC.h"

#include "PixtelDataTypes.h"
#include "DebugInitDef.h"
#include "Unicodexdcl.h"
#include "DictionaryCoreGV.h"

/* ------------------ Third part include file ---------------------- */
#include "libdh.h"
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

/*
 * Global Variable
 */

/*-------------------------- Local Function------------------------*/
void mmi_dict_fetch_supp(U32 wordID, U32 flag, char *suppresult);

/*
 * Global Function
 */


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
    DictInit();
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_get_total_num
 * DESCRIPTION
 *  return total number of words in dictionary
 * PARAMETERS
 *  dict_word       [?]     
 * RETURNS
 *  Numebr of words in dictionary
 *****************************************************************************/
S32 mmi_dict_get_total_num(char *dict_word)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordID;
    S8 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];    /* U8 buffer to get word */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UnicodeToAnsii((PS8) wordbuff, (PS8) dict_word);
    if (!strlen(wordbuff))
    {
        return 0;
    }

    DictSearch(wordbuff, &wordID);          /* id of word being searched by the user */
    if ((wordID + 6) < MMI_DICT_WORDS_MAX)  /* If MAX word count is greater then the word searched */
    {
        return (6);
    }
    else    /* If we reached to the end of the word list then */
    {
        return (MMI_DICT_WORDS_MAX - wordID);   /* return the number of words left */
    }
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
    DictExit();
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_get_word_by_indx
 * DESCRIPTION
 *  To provide word from indexed position of Dictionary Database
 *  
 *  Nill
 * PARAMETERS
 *  lin             [IN]        
 *  Indx            [IN]        
 *  dict_word       [?]         
 *  word(?)         [OUT]       
 *  Language(?)     [IN]        Index,
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
BOOL mmi_dict_get_word_by_indx(U8 lin, U32 Indx, char *dict_word)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];    /* buffer ot get ANSII word from Engine */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Indx > MMI_DICT_WORDS_MAX)  /* Index greater then MAX Words? */
    {
        return FALSE;
    }

    switch (lin)
    {
        case DICT_ENGLISH:
        {
            memset(wordbuff, 0, MMI_DICT_CORE_WORD_MAX);    /* reset buffer to get word */
            /*--------------------------------------------------------------------------*/
            DictFetchEng((U16) Indx, wordbuff);             /* get word in wordbuff from engine */
            /*--------------------------------------------------------------------------*/
            wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';        /* extra care for NULL termination */
            AnsiiToUnicodeString((S8*) dict_word, (S8*) wordbuff);    /* unicode conversion */

        }
            break;
        case DICT_CHINESE:  /* Chinese there is no browse funcationality */
            return FALSE;
        default:
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
    U16 idBuff[MMI_DICT_ID_FETCH_MAX];          /* array of pointers to save ID's */
    S8 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];    /* U8 buffer to get word */

    U16 langMem[(MMI_DICT_ID_FETCH_MAX * (MMI_DICT_CORE_WORD_MAX + 1))];        /* U16 buffer for memory to get chinese word */
    U16 *langIDPtr[MMI_DICT_ID_FETCH_MAX];      /* array of pointers to get chinese word phrases */
    U16 UCS2word[(MMI_DICT_CORE_WORD_MAX + 1)]; /* +2 for length and null character */

    U32 Indx, count = 0, length;        /* count to get matched word numbers */
    mmi_dict_id_str_struct *fetchlist;  /* array of structure to return word list */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fetchlist = (mmi_dict_id_str_struct*) wordlist;

    MMI_ASSERT(!(nfetch > MMI_DICT_WORDS_MAX));

    switch (lin)    /* language selection */
    {
        case DICT_ENGLISH:
        {
            UnicodeToAnsii((PS8) wordbuff, (PS8) dict_word);    /* convert UCS2 word to ASCII */
            /*--------------------------------------------------------------------------*/
            count = DictWildSearch(wordbuff, mskip, nfetch, idBuff);    /* fetch word ID's form Engine */
            /*--------------------------------------------------------------------------*/
            if (count == 0)
            {
                return count;   /* If count 0, return 0 */
            }

            for (Indx = 0; Indx < count; Indx++)    /* Found matched words */
            {
                memset(wordbuff, 0, sizeof(wordbuff));      /* reset word buff */
                /*--------------------------------------------------------------------------*/
                DictFetchEng(idBuff[Indx], wordbuff);       /* fetch word correspoinding to ID */
                /*--------------------------------------------------------------------------*/
                wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';    /* extra care for NULL termination */
                AnsiiToUnicodeString((S8*) fetchlist[Indx].dict_word, (S8*) wordbuff);        /* unicode format */
                fetchlist[Indx].dict_id = (U32) idBuff[Indx];   /* save ID */
            }
        }
            break;

        case DICT_CHINESE:
        {
            /* nfetch = 16;                                                                                 // To check */
            memset(langMem, 0, sizeof(langMem));    /* reset buffer to get chinese word */
            for (Indx = 0; Indx < MMI_DICT_ID_FETCH_MAX; Indx++)        /* allocate memory from buffer to get chinese word */
            {
                langIDPtr[Indx] = &langMem[Indx * (MMI_DICT_CORE_WORD_MAX + 1)];        /* U16 buffer with MAX 32 characters */
            }

            UCS2word[0] = pfnUnicodeStrlen((PS8) dict_word);
            pfnUnicodeStrcpy((PS8) & UCS2word[1], dict_word);
            /*--------------------------------------------------------------------------*/
            count = CDictSearch(UCS2word, mskip, nfetch, langIDPtr);    /* get chinese word pointer */
            /*--------------------------------------------------------------------------*/
            if (count == 0)
            {
                return count;   /* if count 0: return */
            }
            for (Indx = 0; Indx < count; Indx++)    /* get each word */
            {
                length = langIDPtr[Indx][0];
                memset(&langIDPtr[Indx][length + 1], 0, ENCODING_LENGTH);       /* Extra care for Null termination */
                pfnUnicodeStrcpy((S8*) fetchlist[Indx].dict_word, (S8*) & langIDPtr[Indx][1]);        /* copy unicode strings in result */
                fetchlist[Indx].dict_id = 0;    /* For chinese NO ID is present */
            }
        }
            break;
        default:
            break;

    }
    return count;   /* return number of matched words */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search_id
 * DESCRIPTION
 *  To provide id of word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  lin             [IN]        
 *  lout            [IN]        
 *  Word(?)         [IN]        Input language, Out put language,
 * RETURNS
 *  Dictionary id of the word
 *****************************************************************************/
S32 mmi_dict_exact_search_id(char *dict_word, U8 lin, U8 lout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordID;                                 /* to get word ID */
    S8 wordbuff[(MMI_DICT_CORE_WORD_MAX + 1)];  /* to get word in ASCII */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pfnUnicodeStrlen((S8*) dict_word))
    {
        return -1;
    }

    UnicodeToAnsii((PS8) wordbuff, (PS8) dict_word);    /* conversion to ASCII */
    /*--------------------------------------------------------------------------*/
    DictSearch(wordbuff, &wordID);
    /*--------------------------------------------------------------------------*/
    if (wordID > MMI_DICT_WORDS_MAX)
    {
        return -1;
    }

    return wordID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search_prev_id
 * DESCRIPTION
 *  To provide id of previous word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  steps           [IN]        
 *  lin             [IN]        
 *  lout            [IN]        
 *  Word(?)         [IN]        Step, input language, Out put language,
 * RETURNS
 *  Dictionary id of the word
 *****************************************************************************/
S32 mmi_dict_exact_search_prev_id(char *dict_word, S32 steps, U8 lin, U8 lout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordID, returnID = 0, count = 0, reduceID = 1;  /* to get word ID */
    S32 distance;
    U8 same_count;
    S8 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];

    S8 string1[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];
    S8 string2[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH]; /* to get word in ASCII */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pfnUnicodeStrlen((S8*) dict_word))
    {
        return -1;
    }

    UnicodeToAnsii((PS8) wordbuff, (PS8) dict_word);    /* conversion to ASCII */
    /*--------------------------------------------------------------------------*/
    DictSearch(wordbuff, &wordID);
    /*--------------------------------------------------------------------------*/
    if (wordID >= MMI_DICT_WORDS_MAX)
    {
        return 0;
    }
    if (steps == 0)
    {
        return wordID;
    }

    AnsiiToUnicodeString(string1, wordbuff);    /* current word */

    while (count < steps)
    {
        returnID = wordID - reduceID;   /* decrement word ID and check extreme condidtions. */

        if (returnID >= MMI_DICT_WORDS_MAX)
        {
            return wordID;  /* if reached MAX then return MAX id */
        }

        DictFetchEng((U16) (returnID), wordbuff);   /* get previoud word */
        AnsiiToUnicodeString(string2, wordbuff);
        mmi_dict_compare_ucs2_strings(string1, string2, &same_count, &distance);        /* compare that rev word with current word */
        AnsiiToUnicodeString(string1, wordbuff);

        if (distance != 0)  /* got the word */
        {
            count++;    /* increment ID */
            reduceID++; /* increment index to get prev word */
        }
        else    /* skip this entry and read next prev */
        {
            reduceID++;
        }

    }
    return returnID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search_next_id
 * DESCRIPTION
 *  To provide id of previous word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  steps           [IN]        
 *  lin             [IN]        
 *  lout            [IN]        
 *  Word(?)         [IN]        Step, input language, Out put language,
 * RETURNS
 *  Dictionary id of the word
 *****************************************************************************/
S32 mmi_dict_exact_search_next_id(char *dict_word, S32 steps, U8 lin, U8 lout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* description same as above function */
    U16 wordID, returnID = 0, count = 0, increaseID = 1;    /* to get word ID */
    S32 distance;
    U8 same_count;
    S8 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];

    S8 string1[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];
    S8 string2[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH]; /* to get word in ASCII */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pfnUnicodeStrlen((S8*) dict_word))
    {
        return -1;
    }

    UnicodeToAnsii((PS8) wordbuff, (PS8) dict_word);    /* conversion to ASCII */
    /*--------------------------------------------------------------------------*/
    DictSearch(wordbuff, &wordID);
    /*--------------------------------------------------------------------------*/
    if (wordID >= MMI_DICT_WORDS_MAX)
    {
        return 0;
    }
    if (steps == 0)
    {
        return wordID;
    }

    AnsiiToUnicodeString(string1, wordbuff);

    while (count < steps)
    {
        returnID = wordID + increaseID;

        if (returnID >= MMI_DICT_WORDS_MAX)
        {
            return wordID;
        }

        DictFetchEng((U16) (returnID), wordbuff);
        AnsiiToUnicodeString(string2, wordbuff);
        mmi_dict_compare_ucs2_strings(string1, string2, &same_count, &distance);
        AnsiiToUnicodeString(string1, wordbuff);
        if (distance != 0)
        {
            count++;
            increaseID++;
        }
        else
        {
            increaseID++;
        }
    }
    return returnID;
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
S8 chineseResult[MMI_DICT_MEANING_RESULT_MAX];
U16 fexample[MMI_DICT_MEANING_RESULT_MAX];

BOOL mmi_dict_exact_search(char *dict_word, U8 lin, U8 lout, U32 supp, void *fetchresult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordID, i;  /* to get word ID */
    S8 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];
    S8 tempBuff[(MMI_DICT_CORE_WORD_MAX + 5) * ENCODING_LENGTH];        /* 5 for extra symbols */
    U16 tmplen;     /* to get length of parameters */

    U16 UCS2word[MMI_DICT_CORE_WORD_MAX + 1];   /* buffer for UCS2 word */

#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    S8 *chineseResult;
    U16 *fexample;
    T_DictEngWord fetchMeaning;     /* to get meaning */
    mmi_dict_result_struct *result; /* return result structure */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (mmi_dict_result_struct*) fetchresult;

    if (!pfnUnicodeStrlen((PS8) dict_word))
    {
        return FALSE;
    }

    chineseResult = (S8*) OslMalloc((U16) (MMI_DICT_MEANING_RESULT_MAX + 1));
    fexample = (U16*) OslMalloc((U16) (MMI_DICT_MEANING_RESULT_MAX * 2));
    memset(chineseResult, 0, MMI_DICT_MEANING_RESULT_MAX + 1);
    memset(fexample, 0, MMI_DICT_MEANING_RESULT_MAX * 2);

    switch (lin)
    {

        case DICT_ENGLISH:
        {
            UnicodeToAnsii((PS8) wordbuff, (PS8) dict_word);    /* conversion to ASCII */
            memset(&fetchMeaning, '\0', sizeof(fetchMeaning));
            /*--------------------------------------------------------------------------*/
            DictSearch(wordbuff, &wordID);          /* fetch ID of that word */
            DictFetchAll(wordID, &fetchMeaning);    /* fetch meaning of that word */
            /*--------------------------------------------------------------------------*/
            AnsiiToUnicodeString((PS8) result->dict_word, fetchMeaning.Eng);  /* copy word */
            //                                      AnsiiToUnicodeString(tempBuff, "\n");                                                                   // copy new line
            //                                      pfnUnicodeStrcat((PS8)result->dict_meaning,tempBuff);                                   // \n
            //                                      memset(tempBuff, 0, sizeof(tempBuff)); 
            if ((fetchMeaning.DJ[0]) || (fetchMeaning.KK[0]))
            {
                AnsiiToUnicodeString(tempBuff, "[");

                if (fetchMeaning.DJ[0])
                {
                    tmplen = fetchMeaning.DJ[0] + 1;    /* copy KK */
                    memset(&fetchMeaning.DJ[1] + tmplen, '\0', 2);      /* NULL termination */
                    for (i = 1; i <= tmplen; i++)
                    {
                        switch (fetchMeaning.DJ[i])
                        {
                            case 0xF200:
                                fetchMeaning.DJ[i] = 0xF400;
                                break;
                            case 0xF201:
                                fetchMeaning.DJ[i] = 0xF401;
                                break;
                            case 0xF202:
                                fetchMeaning.DJ[i] = 0xF402;
                                break;
                            case 0xF203:
                                fetchMeaning.DJ[i] = 0xF403;
                                break;
                        }
                    }
                    pfnUnicodeStrcat((PS8) tempBuff, (PS8) & fetchMeaning.DJ[1]);
                    pfnUnicodeStrcat((PS8) result->dict_meaning, (PS8) tempBuff);
                }
                memset(tempBuff, 0, sizeof(tempBuff));

                if (fetchMeaning.KK[0])
                {

                    AnsiiToUnicodeString(tempBuff, "/");
                    tmplen = fetchMeaning.KK[0] + 1;    /* copy KK */
                    memset(&fetchMeaning.KK[1] + tmplen, '\0', 2);      /* NULL termination */
                    for (i = 1; i <= tmplen; i++)
                    {
                        switch (fetchMeaning.KK[i])
                        {
                            case 0xF200:
                                fetchMeaning.KK[i] = 0xF400;
                                break;
                            case 0xF201:
                                fetchMeaning.KK[i] = 0xF401;
                                break;
                            case 0xF202:
                                fetchMeaning.KK[i] = 0xF402;
                                break;
                            case 0xF203:
                                fetchMeaning.DJ[i] = 0xF403;
                                break;
                        }
                    }
                    pfnUnicodeStrcat((PS8) tempBuff, (PS8) & fetchMeaning.KK[1]);
                    pfnUnicodeStrcat((PS8) result->dict_meaning, (PS8) tempBuff);
                }
                AnsiiToUnicodeString(tempBuff, "]");
                pfnUnicodeStrcat((PS8) result->dict_meaning, (PS8) tempBuff);
            }

            /* --------------------------------------------------------------------------------- */
            AnsiiToUnicodeString(tempBuff, "\n");   /* copy new line */
            pfnUnicodeStrcat((PS8) result->dict_meaning, tempBuff);     /* \n */

            /* ****************************Explanation************************* */
            tmplen = fetchMeaning.Expl[0];              /* get Expl length */
            memset(&fetchMeaning.Expl[1] + tmplen, '\0', 2);    /* Null termination */
            pfnUnicodeStrcat((PS8) result->dict_meaning, (PS8) & fetchMeaning.Expl[1]);
            /* ****************************************************************** */
            result->dict_suppflag = fetchMeaning.Supp;  /* supplimentary flag */

            if ((supp & MMI_DICT_SYNO) && (fetchMeaning.Supp & MMI_DICT_SYNO))  /* get Synonym */
            {
                mmi_dict_fetch_supp(wordID, MMI_DICT_SYNO, (PS8) result->dict_synonym);
            }

            if ((supp & MMI_DICT_ANTO) && (fetchMeaning.Supp & MMI_DICT_ANTO))  /* get antonoym */
            {
                mmi_dict_fetch_supp(wordID, MMI_DICT_ANTO, (PS8) result->dict_antonym);
            }

            if ((supp & MMI_DICT_SENTS) && (fetchMeaning.Supp & MMI_DICT_SENTS))        /* get sentence */
            {
                memset(fexample, '\0', MMI_DICT_EXAMPLE_SENTENCE_MAX);  /* reset */
                /*--------------------------------------------------------------------------*/
                DictFetchSupp((U16) wordID, MMI_DICT_SENTS, NULL, fexample);    /* get example string in fexample */
                /*--------------------------------------------------------------------------*/
                tmplen = fexample[0];   /* if example sentence length >0 */
                result->dict_example_sentence[0] = (tmplen & 0xFF00) >> 8;      /* make entry valid */
                result->dict_example_sentence[1] = (tmplen & 0x00FF);

                memset(&fexample[1] + tmplen, '\0', 2);
                pfnUnicodeStrcat((PS8) result->dict_example_sentence, (PS8) & fexample[1]);
            }
        }
            break;

        case DICT_CHINESE:
        {
            UCS2word[0] = pfnUnicodeStrlen((PS8) dict_word);
            pfnUnicodeStrcpy((PS8) & UCS2word[1], dict_word);
            memset(chineseResult, 0, ENCODING_LENGTH);
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
        #endif /* 0 */ 

            if (CDictFetch(UCS2word, chineseResult) == NULL)
            {
                if (chineseResult != NULL)
                {
                    OslMfree(chineseResult);
                }
                if (fexample != NULL)
                {
                    OslMfree(fexample);
                }
                return FALSE;
            }
            else
            {
                pfnUnicodeStrcpy((PS8) result->dict_word, dict_word); /* copy word */
                AnsiiToUnicodeString((PS8) fexample, (PS8) chineseResult);
                pfnUnicodeStrcat((PS8) result->dict_meaning, (PS8) fexample);

            }
        }
            break;
        default:
            break;
    }

    if (chineseResult != NULL)
    {
        OslMfree(chineseResult);
    }
    if (fexample != NULL)
    {
        OslMfree(fexample);
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_fetch_supp
 * DESCRIPTION
 *  To provide word ID meaning from Dictionary
 *  
 *  Nill
 * PARAMETERS
 *  wordID                          [IN]        
 *  flag                            [IN]        
 *  suppresult                      [?]         
 *  WordID(?)                       [IN]        Supplimentary flag, result
 *  mmi_dict_result_struct(?)       [IN]        To get result
 *  result(?)                       [OUT]       String
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dict_fetch_supp(U32 wordID, U32 flag, char *suppresult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 suppIdbuff[MMI_DICT_ID_FETCH_MAX + 1];  /* ID array to get supplimentary feild ID's */
    S8 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];
    U8 tmpucs2buff[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];
    U8 tmpcnt, tmplen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*--------------------------------------------------------------------------*/
    DictFetchSupp((U16) wordID, flag, suppIdbuff, NULL);    /* get supp ID's */
    /*--------------------------------------------------------------------------*/

    if ((tmplen = (U8) suppIdbuff[0]) > 0)  /* If supp feilds */
    {
        suppresult[0] = (tmplen & 0xFF00) << 8; /* make entry valid */
        suppresult[1] = (tmplen & 0x00FF);

        for (tmpcnt = 1; tmpcnt <= tmplen; tmpcnt++)
        {
            if (tmpcnt > 1)
            {
                AnsiiToUnicodeString(wordbuff, "\\");
                pfnUnicodeStrcat(suppresult, wordbuff);
            }
            memset(wordbuff, '\0', MMI_DICT_CORE_WORD_MAX); /* reset tempbuff */
            /*--------------------------------------------------------------------------*/
            DictFetchEng(suppIdbuff[tmpcnt], wordbuff);     /* fetch english words */
            /*--------------------------------------------------------------------------*/
            wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';        /* Null termination */
            AnsiiToUnicodeString((S8*) tmpucs2buff, (S8*) wordbuff);  /* UCS2 conversion */
            pfnUnicodeStrcat(suppresult, (PS8) tmpucs2buff);    /* result c0ncatenation */
        }
    }
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

#endif /* __MMI_DICT_GV__ */ 

