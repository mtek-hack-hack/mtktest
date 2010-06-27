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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/dict/motech/adaptation/src/DictionaryCoreMOTECH.c,v 1.1 2007/05/17 07:26:37 bw Exp $
*
* $Id: DictionaryCoreMOTECH.c,v 1.1 2007/05/17 07:26:37 bw Exp $
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
* $Log: DictionaryCoreMOTECH.c,v $
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
 *   This file intends for Dictionary implementation according to Motech Library
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
#ifdef __MMI_DICT_MOTECH__

#include "stdC.h"
#include "PixtelDataTypes.h"
#include "DebugInitDef.h"
#include "Unicodexdcl.h"
#include "DictionaryCoreMOTECH.h"

/* --------- Third part include file ----------- */
#include "de_api.h"
/*---------------------------------------*/

/*
 * Typedef
 */

/*
 * Define
 */
#define MMI_DICT_WORDS_MAX       50000  /* MAX Dictionary words */
#define MMI_DICT_MEMORY_POOL_SIZE   27000

/*
 * Local Variable
 */
static U8 g_dict_memory_pool[MMI_DICT_MEMORY_POOL_SIZE];
DEData dict_engine_data;
DEReturnValue dict_ErrCode, *dict_error_code;
WCONTENT *word_meaning;

/* 
 * Global Variable
 */

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
 *  TRUE / FALSE
 *****************************************************************************/
pBOOL mmi_dict_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dict_mem_size = 0;

    dict_engine_data.pRAM = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get working memory size */
    dict_mem_size = DEGetMemSize(&dict_engine_data, (U8*) & dict_ErrCode);
    PRINT_INFORMATION(("---[DictionaryCore.c] Dictionary memory required:%ld \n", dict_mem_size));

    if ((dict_ErrCode != DE_OK) || (dict_mem_size > MMI_DICT_MEMORY_POOL_SIZE))
    {
        PRINT_INFORMATION(("---[DictionaryCore.c] Failed to get the memory from engine"));
        return FALSE;
    }

    //dict_engine_data.pRAM = (void*)OslMalloc((U16)(dict_mem_size)); /* Use static memory instead */
    //memset(g_dict_memory_pool, 0, MMI_DICT_MEMORY_POOL_SIZE);
    dict_engine_data.pRAM = (void*)&g_dict_memory_pool;

    /* Initialize engine */
    dict_ErrCode = DEInit(&dict_engine_data);

    if (dict_ErrCode != DE_OK)
    {
        PRINT_INFORMATION(("---[DictionaryCore.c] Failed to initialize the engine \n"));
        return FALSE;
    }
    else
    {
        return TRUE;
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
 *  TRUE / FALSE
 *****************************************************************************/
pBOOL mmi_dict_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if(dict_engine_data.pRAM != NULL) /* Use static memory instead */
    //   OslMfree(dict_engine_data.pRAM);

    dict_ErrCode = DETerminate(&dict_engine_data);

    if (dict_ErrCode != DE_OK)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }

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
    S16 stepsMoved, length;
    S32 distance;
    U8 same_count;
    U16 string1[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 string2[(MMI_DICT_CORE_WORD_MAX + 1)];  /* to get word in ASCII */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pfnUnicodeStrcpy((PS8) string2, (PS8) dict_word);   /* conversion to ASCII */

    length = pfnUnicodeStrlen((S8*) string2);

    if (length >= 2)        /* Is word string > 2 */
    {                       /* yes: get the no. of words after current word */
        memset(string2, 0, MMI_DICT_CORE_WORD_MAX);
        AnsiiToUnicodeString((S8*) string1, (S8*) "zo");
        memcpy(string2, dict_word, 4);
        mmi_dict_compare_ucs2_strings((S8*) string1, (S8*) string2, &same_count, &distance);
        if (distance > 0)   /* is there are more words then return 6 as we have more */
            /* words after zo also [done for speed optimization] */
        {
            return 6;
        }
        else    /* NO: we have reached to ZO or any word after this */
        {       /* get no. of words after current owrd by lib API */
            DESearchWord(&dict_engine_data, string2, string1);
            stepsMoved = DEChangeFocus(&dict_engine_data, (S16) 6);

            DESearchWord(&dict_engine_data, string2, string1);

            if (stepsMoved == 0)
            {
                return 1;
            }
            else
            {
                return stepsMoved + 1;
            }
        }
    }

    return 6;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_get_word_by_indx
 * DESCRIPTION
 *  To provide the focused and set focus to the next non similar word
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
    U16 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];
    U16 UCS2word[MMI_DICT_CORE_WORD_MAX + 1];
    U16 dict_next_word[MMI_DICT_CORE_WORD_MAX + 1];

    S16 stepsMoved;
    U8 same_count;
    S32 distance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lin)
    {
        case DICT_ENGLISH:
        case DICT_CHINESE:
        {
            memset(wordbuff, 0, MMI_DICT_CORE_WORD_MAX);    /* reset buffer to get word */

            /*--------------------------------------------------------------------------*/
            dict_ErrCode = DEGetWord(&dict_engine_data, 0, wordbuff);   /* current focus word */
            /*--------------------------------------------------------------------------*/
            if (dict_ErrCode != DE_OK)
            {
                return FALSE;
            }
            /*--------------------------------------------------------------------------*/
            stepsMoved = DEChangeFocus(&dict_engine_data, (S16) 1);     /* next focus */
            /*--------------------------------------------------------------------------*/
            if (stepsMoved != 1)
            {
                wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';
                pfnUnicodeStrcpy((S8*) dict_word, (S8*) wordbuff);    /* copy previous focus word */
                return FALSE;   /* return fasle as there is no word after it */
            }
            /*--------------------------------------------------------------------------*/
            dict_ErrCode = DEGetWord(&dict_engine_data, (U16) 0, dict_next_word);       /* read next word */
            /*--------------------------------------------------------------------------*/
            if (dict_ErrCode != DE_OK)
            {
                return FALSE;
            }

            mmi_dict_compare_ucs2_strings((S8*) dict_next_word, (S8*) wordbuff, &same_count, &distance);
            if (distance == 0)  /* next and pre word are same */
            {
                /*--------------------------------------------------------------------------*/
                DESearchWord(&dict_engine_data, wordbuff, UCS2word);    /* change focus to current word */
                stepsMoved = DEChangeFocus(&dict_engine_data, (S16) 2); /* chage focus by 2 as next and current words are same */
                /*--------------------------------------------------------------------------*/
            }
            wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';    /* extra care for NULL termination */
            pfnUnicodeStrcpy((S8*) dict_word, (S8*) wordbuff);        /* unicode conversion */
        }
            break;
            /* Chinese: there is no browse funcationality */
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
    U16 wordbuff[MMI_DICT_CORE_WORD_MAX + 1];   /* U8 buffer to get word */
    U16 UCS2word[MMI_DICT_CORE_WORD_MAX + 1];

    U32 Indx = 0;
    DEReturnValue dictErr;
    mmi_dict_id_str_struct *fetchlist;  /* array of structure to return word list */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fetchlist = (mmi_dict_id_str_struct*) wordlist;
    switch (lin)    /* language selection */
    {
        case DICT_ENGLISH:  /* will not work in case of English */
        case DICT_CHINESE:
        {
            pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);  /* convert UCS2 word to ASCII */
            /*--------------------------------------------------------------------------*/
            dictErr = DESearchWord(&dict_engine_data, wordbuff, UCS2word);
            if (dictErr != DE_OK)
            {
                break;
            }
            /*--------------------------------------------------------------------------*/
            pfnUnicodeStrcpy((S8*) fetchlist[0].dict_word, (S8*) UCS2word);   /* unicode format */

            for (Indx = 1; Indx < MMI_DICT_ID_FETCH_MAX; Indx++)        /* Found matched words */
            {
                memset(wordbuff, 0, MMI_DICT_CORE_WORD_MAX);    /* reset word buff */
                /*--------------------------------------------------------------------------*/
                dict_ErrCode = DEGetWord(&dict_engine_data, (U16) Indx, wordbuff);      /* get words by the index */
                /*--------------------------------------------------------------------------*/
                if (dict_ErrCode == DE_OK)
                {
                    wordbuff[MMI_DICT_CORE_WORD_MAX] = '\0';    /* extra care for NULL termination */
                    pfnUnicodeStrcpy((S8*) fetchlist[Indx].dict_word, (S8*) wordbuff);        /* unicode format */
                    fetchlist[Indx].dict_id = 0;    /* save ID */
                }
                else
                {
                    break;
                }
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
 * PARAMETERS
 *  dict_word       [?]         
 *  lin             [IN]        
 *  lout            [IN]        
 *  supp            [IN]        
 *  fetchresult     [?]         
 *  Word, input language, Out put language, supplimentary feilds, structure(?)
 *  (mmi_dict_result_struct) to get result(?)
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
BOOL mmi_dict_exact_search(char *dict_word, U8 lin, U8 lout, U32 supp, void *fetchresult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 wordbuff[MMI_DICT_CORE_WORD_MAX], tmplen, count, length;        /* to get word in ASCII */
    U8 *meaning = NULL, *synonyms = NULL, *antonyms = NULL;
    U32 dictSize;
    U16 UCS2word[MMI_DICT_CORE_WORD_MAX * ENCODING_LENGTH]; /* buffer has maximum 64 character. do not change */
    DEReturnValue dictErr;
    WORDLIST *word_list;
    ONEEXP *expl;
    WCONTENT *w_content;
    mmi_dict_result_struct *result;                         /* return result structure */

    result = (mmi_dict_result_struct*) fetchresult;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lin)
    {
        case DICT_ENGLISH:
        case DICT_CHINESE:
        {
            pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);  /* conversion to ASCII */
            /* memset(word_meaning, '\0', sizeof(fetchMeaning)); */
            word_meaning = NULL;

            /*--------------------------------------------------------------------------*/
            dictErr = DESearchWord(&dict_engine_data, wordbuff, UCS2word);
            if (dictErr != DE_OK)
            {
                break;
            }
            /*--------------------------------------------------------------------------*/
            dictSize = DEInstantGetWordContentSize(&dict_engine_data, TRUE, UCS2word);  /* This API is case sensitive. */
            if (dictSize == 0)
            {
                return FALSE;
            }
            else if (dictSize > 2000)   /* on target we can not alocate more then 2k */
            {
                return FALSE;
            }
            word_meaning = (WCONTENT*) OslMalloc((U16) (dictSize));    /* memory for lib */
            meaning = (U8*) OslMalloc((U16) (dictSize));    /* memory for local info */
            memset(meaning, 0, dictSize);
            dictErr = DEInstantGetWordContent(&dict_engine_data, TRUE, UCS2word, word_meaning); /* word meaning in link list format */
            if (dictErr != DE_OK)
            {
                return FALSE;
            }

            pfnUnicodeStrcpy((S8*) result->dict_word, (S8*) UCS2word);      /* word copied into return structure */
            //        AnsiiToUnicodeString((S8*)wordbuff, (S8*)"\n");                                                         // copy new line
            //        pfnUnicodeStrcpy((S8*)meaning,(S8*)wordbuff);

            /*--------------------------------------------------------------------------*/
        #ifdef __MTK_TARGET__
            w_content = word_meaning;
            while (w_content != NULL)
            {
                if (w_content->pContent->phoneSym)  /* phonetic symbols */
                {
                    U16 i, temp_len;

                    /* Replace phonetic encoding */
                    temp_len = pfnUnicodeStrlen((S8*) w_content->pContent->phoneSym);
                    for (i = 0; i <= temp_len; i++)
                    {
                        switch (w_content->pContent->phoneSym[i])
                        {
                            case 0x0275:
                                w_content->pContent->phoneSym[i] = 0xF403;
                                break;
                            default:
                                break;
                        }
                    }

                    pfnUnicodeStrcat((S8*) meaning, (S8*) w_content->pContent->phoneSym);     /* add phonetic */
                    AnsiiToUnicodeString((S8*) wordbuff, (S8*) "\n"); /* copy new line */
                    pfnUnicodeStrcat((S8*) meaning, (S8*) wordbuff);

                }

                expl = w_content->pContent->explanation;
                while (expl != NULL)
                {
                    switch (expl->typeofword)
                    {
                        case TYPE_NOUN:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[noun]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_PRON:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[pronoun]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_VI:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[verb intransitive]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_VT:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[verb transitive]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_ADJ:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[adjective]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_ADV:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[adverb]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_PREP:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[preposition]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_CONJ:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[conjunction]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_INT:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[interjection]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                        case TYPE_ABBR:
                            AnsiiToUnicodeString((S8*) UCS2word, (S8*) "[abbreviation]");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) UCS2word);
                            break;

                    }
                    word_list = expl->interpretation;
                    while (word_list != NULL)
                    {
                        if (pfnUnicodeStrlen((S8*) word_list->pWord) != 0)
                        {
                            pfnUnicodeStrcat((S8*) meaning, (S8*) word_list->pWord);
                        }
                        word_list = word_list->pNext;
                        if (word_list != NULL)
                        {
                            memset(wordbuff, 0, ENCODING_LENGTH);
                            AnsiiToUnicodeString((S8*) wordbuff, (S8*) "\\");
                            pfnUnicodeStrcat((S8*) meaning, (S8*) wordbuff);
                        }
                    }

                    expl = expl->pNext;

                    if (expl != NULL)
                    {
                        memset(wordbuff, 0, ENCODING_LENGTH);
                        AnsiiToUnicodeString((S8*) wordbuff, (S8*) "\n");     /* copy new line */
                        pfnUnicodeStrcat((S8*) meaning, (S8*) wordbuff);
                    }
                }

                if (w_content->pContent->numofSynonym && (supp & MMI_DICT_SYNO))
                {
                    tmplen = w_content->pContent->numofSynonym;
                    synonyms = (U8*) OslMalloc((U16) (tmplen * ((MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH)));
                    memset(synonyms, 0, ENCODING_LENGTH);

                    for (count = 0; count < w_content->pContent->numofSynonym; count++)
                    {
                        pfnUnicodeStrcat((S8*) synonyms, (S8*) w_content->pContent->pSynonym[count]);

                        if (count != (w_content->pContent->numofSynonym - 1))
                        {
                            AnsiiToUnicodeString((S8*) wordbuff, (S8*) "\\");
                            pfnUnicodeStrcat((S8*) synonyms, (S8*) wordbuff);
                        }
                    }
                }

                if (w_content->pContent->numofAntonym && (supp & MMI_DICT_ANTO))
                {
                    tmplen = w_content->pContent->numofAntonym;
                    antonyms = (U8*) OslMalloc((U16) (tmplen * ((MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH)));
                    memset(antonyms, 0, ENCODING_LENGTH);

                    for (count = 0; count < w_content->pContent->numofAntonym; count++)
                    {
                        pfnUnicodeStrcat((S8*) antonyms, (S8*) w_content->pContent->pAntonym[count]);

                        if (count != (w_content->pContent->numofAntonym - 1))
                        {
                            AnsiiToUnicodeString((S8*) wordbuff, (S8*) "\\");
                            pfnUnicodeStrcat((S8*) antonyms, (S8*) wordbuff);
                        }
                    }
                }
                length = pfnUnicodeStrlen((S8*) meaning);

                if (length > MMI_DICT_MEANING_RESULT_MAX)   /* precaution for large content */
                {
                    U16 terminate;

                    terminate = MMI_DICT_MEANING_RESULT_MAX * ENCODING_LENGTH;
                    memset(&meaning[terminate], 0, 2);
                    pfnUnicodeStrcpy((S8*) result->dict_meaning, (S8*) meaning);

                }
                else
                {
                    U16 terminate;

                    terminate = length * ENCODING_LENGTH;
                    memset(&meaning[terminate], 0, 2);
                    pfnUnicodeStrcpy((S8*) result->dict_meaning, (S8*) meaning);
                }

                if (synonyms != NULL && pfnUnicodeStrlen((S8*) synonyms))
                {
                    length = pfnUnicodeStrlen((S8*) synonyms);
                    result->dict_synonym[0] = (length & 0xFF00) >> 8;
                    result->dict_synonym[1] = (length & 0x00FF);
                    result->dict_synonym[2] = result->dict_synonym[3] = 0;

                    if (length > MMI_DICT_SYNO_ANTO_LENGTH_MAX)
                    {
                        U16 terminate;

                        terminate = MMI_DICT_SYNO_ANTO_LENGTH_MAX * ENCODING_LENGTH;
                        memset(&synonyms[terminate], 0, 2);
                        pfnUnicodeStrcpy((S8*) & result->dict_synonym[2], (S8*) synonyms);

                    }
                    else
                    {
                        U16 terminate;

                        terminate = length * ENCODING_LENGTH;
                        memset(&synonyms[terminate], 0, 2);
                        pfnUnicodeStrcpy((S8*) & result->dict_synonym[2], (S8*) synonyms);
                    }
                }

                if (antonyms != NULL && pfnUnicodeStrlen((S8*) antonyms))
                {
                    length = pfnUnicodeStrlen((S8*) antonyms);
                    result->dict_antonym[0] = (length & 0xFF00) >> 8;
                    result->dict_antonym[1] = (length & 0x00FF);
                    if (length > MMI_DICT_SYNO_ANTO_LENGTH_MAX)
                    {
                        U16 terminate;

                        terminate = MMI_DICT_SYNO_ANTO_LENGTH_MAX * ENCODING_LENGTH;
                        memset(&antonyms[terminate], 0, 2);
                        pfnUnicodeStrcpy((S8*) & result->dict_antonym[2], (S8*) antonyms);
                    }
                    else
                    {
                        U16 terminate;

                        terminate = length * ENCODING_LENGTH;
                        memset(&antonyms[terminate], 0, 2);
                        pfnUnicodeStrcpy((S8*) & result->dict_antonym[2], (S8*) antonyms);
                    }
                }
                w_content = w_content->pNext;   /* at present words from single library are shown. */
            }
        #endif /* __MTK_TARGET__ */ 
        }
            break;

        default:
            break;
    }

    OslMfree(word_meaning);

    if (meaning != NULL)
    {
        OslMfree(meaning);
    }

    if (antonyms != NULL)
    {
        OslMfree(antonyms);
    }

    if (synonyms != NULL)
    {
        OslMfree(synonyms);
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_exact_search_id
 * DESCRIPTION
 *  This function set the focus to the word
 *  
 *  Nill
 * PARAMETERS
 *  dict_word       [?]         
 *  lin             [IN]        
 *  lout            [IN]        
 *  Word(?)         [IN]        Language - in, language -out
 * RETURNS
 *  Number of words
 *****************************************************************************/
S32 mmi_dict_exact_search_id(char *dict_word, U8 lin, U8 lout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DEReturnValue dictErr;

    /* to get word ID */
    U16 wordbuff[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 UCS2word[(MMI_DICT_CORE_WORD_MAX + 1)]; /* to get word in ASCII */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);  /* conversion to ASCII */
    /*--------------------------------------------------------------------------*/
    dictErr = DESearchWord(&dict_engine_data, wordbuff, UCS2word);
    /*--------------------------------------------------------------------------*/
    if (dictErr != DE_OK)
    {
        return -1;
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
    DEReturnValue dictErr;
    S16 stepsMoved, focusMove = -2;
    U16 wordbuff[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 string1[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 string2[(MMI_DICT_CORE_WORD_MAX + 1)];  /* to get word in ASCII */

    U8 same_count;
    S32 distance, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);  /* conversion to ASCII */
    /*--------------------------------------------------------------------------*/
    dictErr = DESearchWord(&dict_engine_data, wordbuff, string1);       /* focus set */
    /*--------------------------------------------------------------------------*/
    if (dictErr != DE_OK)
    {
        return 0;
    }
    /*--------------------------------------------------------------------------*/
    if (steps <= 0)
    {
        return 1;
    }
    stepsMoved = DEChangeFocus(&dict_engine_data, (S16) - 1);

    if (stepsMoved != -1)
    {
        return 0;   /* No previous word */
    }

    while (count < steps)
    {
        dictErr = DEGetWord(&dict_engine_data, 0, string2); /* get current focus word */
        mmi_dict_compare_ucs2_strings((S8*) string1, (S8*) string2, &same_count, &distance);
        pfnUnicodeStrcpy((PS8) string1, (PS8) string2);

        if (distance != 0)  /* distance = -1, 1 */
        {
            count++;
            if (count < steps)
            {
                stepsMoved = DEChangeFocus(&dict_engine_data, (S16) - 1);
            }
            else
            {
                break;
            }

            if (stepsMoved != -1)
            {
                return 0;
            }
        }
        else    /* same word */
        {
            dictErr = DESearchWord(&dict_engine_data, string2, wordbuff);
            stepsMoved = DEChangeFocus(&dict_engine_data, (S16)focusMove);   /* to check */
            if (stepsMoved != focusMove)
            {
                return 0;
            }
            focusMove--;
        }
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
    DEReturnValue dictErr;
    S16 stepsMoved, focusMove = 2;                             /* to get word ID */
    U16 wordbuff[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 string1[(MMI_DICT_CORE_WORD_MAX + 1)];
    U16 string2[(MMI_DICT_CORE_WORD_MAX + 1)];  /* to get word in ASCII */

    U8 same_count;
    S32 distance, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pfnUnicodeStrcpy((PS8) wordbuff, (PS8) dict_word);  /* conversion to ASCII */
    /*--------------------------------------------------------------------------*/
    dictErr = DESearchWord(&dict_engine_data, wordbuff, string1);       /* set focus */
    /*--------------------------------------------------------------------------*/
    if (dictErr != DE_OK)
    {
        return 0;
    }
    /*--------------------------------------------------------------------------*/
    if (steps <= 0)
    {
        return 1;
    }

    stepsMoved = DEChangeFocus(&dict_engine_data, (S16) 1);

    if (stepsMoved != 1)
    {
        return 0;
    }
    /*--------------------------------------------------------------------------*/
    while (count < steps)
    {
        dictErr = DEGetWord(&dict_engine_data, 0, string2);
        mmi_dict_compare_ucs2_strings((S8*) string1, (S8*) string2, &same_count, &distance);

        pfnUnicodeStrcpy((PS8) string1, (PS8) string2);
        if (distance != 0)
        {
            count++;
            if (count < steps)
            {
                stepsMoved = DEChangeFocus(&dict_engine_data, (S16) 1);
            }
            else
            {
                break;
            }

            if (stepsMoved != 1)
            {
                return 0;
            }

        }
        else
        {
            dictErr = DESearchWord(&dict_engine_data, string2, wordbuff);
            stepsMoved = DEChangeFocus(&dict_engine_data, (S16)focusMove);
            if (stepsMoved != focusMove)
            {
                return 0;
            }
            focusMove++;
        }
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
#endif /* __MMI_DICT_MOTECH__ */ 

