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
 *    bidi.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   bidirectional algorithm engine
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : BIDI.c

   PURPOSE     : Main functions of BIDI Algorithm

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : Aug-23-2004

**************************************************************/
#include "MMI_include.h"
#ifndef __BIDI_CONSOLE__
#endif 

#define __MMI_BIDI__    /* To be placed in MMI_features.h later */
#ifdef __MMI_BIDI__

#include "BidiProt.h"
#include "BidiDef.h"

#ifdef __BIDI_CONSOLE__
#include "CommonProts.h"
#else /* __BIDI_CONSOLE__ */ 
#endif /* __BIDI_CONSOLE__ */ 

#define BIDI_CONSIDER_DIFF_INPUT_METHOD_BEHAVIOR 0

U8 input_types[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH]; /* source array for storing the direction codes of the input string */
U8 input_levels[MAX_LEVEL_EMBEDDING];                   /* This global contains all the embedding levels */
U8 dest_levels[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH]; /* destitnation array for processed levels */
U8 dest_types[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];  /* Destination array for storing the direction codes of the input string */
U8 localLogicalBuffer[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];

/*PMT IRE START*/
/*code removed*/
/*PMT IRE END*/


/*****************************************************************************
 * FUNCTION
 *  bidi_main
 * DESCRIPTION
 *  fill the string buffer to bidirectional algorithm
 * PARAMETERS
 *  logicalStr              [IN]        Input string for bidi
 *  logicalStrLen           [IN]        String length of input string
 *  logicalCurPos           [IN]        Current cursor position of input string
 *  visualStr               [OUT]       Final output string from bidi algorithm
 *  visualStrLen            [OUT]       String length of final output string
 *  visualCurPos            [OUT]       Cursor position of final output string
 *  fSwap                   [IN]        If true, then reserse the string after apply bidi algorithm
 *  inputMode               [IN]        
 *  logicalHilightStart     [IN]        Word hilight start position of input string
 *  logicalHilightEnd       [IN]        Word hilight end position of input string
 *  visualHilightStart      [OUT]       Word hilight start position of output string
 *  visualHilightEnd        [OUT]       Word hilight end position of output string
 * RETURNS
 *  void
 *****************************************************************************/
void bidi_main(
        U8 *logicalStr,
        U16 logicalStrLen,
        U16 logicalCurPos,
        U8 *visualStr,
        U16 *visualStrLen,
        U16 *visualCurPos,
        pBOOL fSwap,
        U8 inputMode,
        U16 logicalHilightStart,
        U16 logicalHilightEnd,
        U16 *visualHilightStart,
        U16 *visualHilightEnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 paragraphEmbeddingLevel = 0;

#if BIDI_CONSIDER_DIFF_INPUT_METHOD_BEHAVIOR
    U8 lastType;
    pBOOL flag = FALSE;
#endif /* BIDI_CONSIDER_DIFF_INPUT_METHOD_BEHAVIOR */ 
    pBOOL bCheckFlag;
    S16 iCount, nParaCount = 0;
    U8 *pInputType = input_types;
    U8 *pInputLevels = input_levels;
    U8 *pDestLevels = dest_levels;
    U8 *pDestTypes = dest_types;
    U8 *pLogicalBuffer = localLogicalBuffer;
    U8 *pVisualBuffer = visualStr;
    U16 mark;

    /* START TARUN PMT 20050202 */
    U8 newLineflag = 0;

    /* END TARUN PMT 20050202 */
    U8 testHilighOneCharFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(input_types, 0,sizeof(input_types));
    memset(input_levels, 0,sizeof(input_levels));
    memset(dest_levels, 0,sizeof(dest_levels));
    memset(dest_types, 0,sizeof(dest_types));
    memset(localLogicalBuffer, 0,sizeof(localLogicalBuffer));

    if (logicalStrLen == 0)
    {
        /* *visualCurPos = 0; */
        *visualCurPos = 0xFFFF;
        *visualStr = 0;
        *(visualStr + 1) = 0;
        *visualStrLen = 0;
        *visualHilightStart = 0;
        *visualHilightEnd = 0;
        return;
    }

    if (logicalCurPos != 0xFFFF)
    {
        if (logicalCurPos < logicalHilightEnd)
        {
            logicalCurPos = logicalHilightEnd;
        }
        if (logicalHilightStart > logicalHilightEnd)
        {
            logicalHilightStart = logicalHilightEnd;
        }
    }


/*PMT IRE START*/
/*removed unwanted code*/
/*PMT IRE END*/
    mmi_ucs2ncpy((S8*) localLogicalBuffer, (const S8*)logicalStr, (U32) logicalStrLen);

#if BIDI_CONSIDER_DIFF_INPUT_METHOD_BEHAVIOR
    if (inputMode == BIDI_R)
    {
        bidi_get_char_type((U8*) & localLogicalBuffer[(logicalStrLen - 1) * BIDI_ENCODING_LENGTH], (U8*) & lastType);
        if (lastType == WS)
        {
            localLogicalBuffer[(logicalStrLen - 1) * BIDI_ENCODING_LENGTH] = 0;
            localLogicalBuffer[(logicalStrLen - 1) * BIDI_ENCODING_LENGTH + 1] = 0;
            if (logicalCurPos == logicalStrLen)
            {
                flag = TRUE;
                logicalCurPos--;
            }
            logicalStrLen--;
        }

        set_bidi_cursor_pos((U8*) localLogicalBuffer, logicalCurPos, (U16) CURSOR_MARK);

        logicalStrLen = (U16) mmi_ucs2strlen((const S8*)localLogicalBuffer);

        set_bidi_cursor_pos((U8*) localLogicalBuffer, logicalStrLen, (U16) LAST_MARK);
    }
    else
#endif /* BIDI_CONSIDER_DIFF_INPUT_METHOD_BEHAVIOR */ 
    {
        if (logicalCurPos != 0xFFFF)
        {
            set_bidi_cursor_pos((U8*) localLogicalBuffer, logicalCurPos, (U16) CURSOR_MARK);
        }
    }

    set_bidi_cursor_pos((U8*) localLogicalBuffer, logicalHilightEnd, (U16) SECOND_HIGHLT);
    set_bidi_cursor_pos((U8*) localLogicalBuffer, (U16) (logicalHilightStart), (U16) FIRST_HIGHLT);

    mmi_ucs2cpy((S8*) visualStr, (const S8*)localLogicalBuffer);
    logicalStrLen = get_direction_codes((U8*) input_types, (U8*) localLogicalBuffer, 0);

    iCount = 0;

    while (iCount < logicalStrLen)
    {
        bCheckFlag = FALSE;
        nParaCount = identify_paragraphs(pInputType, (U16) (logicalStrLen - iCount), &bCheckFlag);
        if (logicalCurPos < nParaCount)
        {
            newLineflag = 1;
        }
        copy_direction_codes(pDestTypes, pInputType, (U16) nParaCount);
        if (bCheckFlag)
        {
            pDestTypes[nParaCount] = 0;
            pInputType[nParaCount] = 0;
            if (pInputType[nParaCount - 1] == BIDI_B)
            {
                pDestTypes[nParaCount - 1] = 0;
                pInputType[nParaCount - 1] = 0;
            }
        }

        /*----------------------------------------------------------------*/
        /* We use bidi_main line by line, so we can't get the paragraph   */
        /* embedding level from the current line.                         */
        /* Now change to set the paragraph embedding                      */
        /* level by the flag: fSwap.                                       */
        /*----------------------------------------------------------------*/
        /* paragraphEmbeddingLevel = get_para_embedding_level(pInputType, nParaCount); */
        paragraphEmbeddingLevel = (fSwap == 1) ? 1 : 0;
        set_dest_levels(0, nParaCount, paragraphEmbeddingLevel, pDestLevels);

        get_run_level(nParaCount, paragraphEmbeddingLevel, pDestLevels, pDestTypes);
        resolve_lines(paragraphEmbeddingLevel, pVisualBuffer, nParaCount, TRUE, pDestTypes, pDestLevels);

        if (bCheckFlag)
        {
            nParaCount++;
        }
        pInputType += nParaCount;
        pInputLevels += nParaCount;
        pDestLevels += nParaCount;
        pDestTypes += nParaCount;
        pLogicalBuffer += nParaCount * 2;
        pVisualBuffer += nParaCount * 2;
        iCount += nParaCount;
    }

    *visualStrLen = (U16) mmi_ucs2strlen((const S8*)visualStr);

    if (fSwap)
    {
        bidi_reverse((U8*) visualStr, *visualStrLen);
    }

    *visualCurPos = 0xFFFF;
    /* START Changed by YOGESH PMT 20050912 */
    while (find_mark(visualStr, *visualStrLen, &mark, (U16*) & iCount))
        /* END YOGESH PMT 20050912 */
    {
        switch (mark)
        {
            case LAST_MARK:
            case CURSOR_MARK:
        #if BIDI_CONSIDER_DIFF_INPUT_METHOD_BEHAVIOR
                if (inputMode == BIDI_R)
                {
                    *visualCurPos = get_bidi_cursor_pos(visualStr, (U16) LAST_MARK);

                    if (lastType == WS)
                    {
                        set_bidi_cursor_pos(visualStr, *visualCurPos, (U16) (0x0020));
                    }

                    *visualCurPos = get_bidi_cursor_pos(visualStr, (U16) CURSOR_MARK);
                }
                else
        #endif /* BIDI_CONSIDER_DIFF_INPUT_METHOD_BEHAVIOR */ 
                {
                    *visualCurPos = get_bidi_cursor_pos(visualStr, (U16) CURSOR_MARK);
                }
                testHilighOneCharFlag = 1;
                break;
            case SECOND_HIGHLT:
                *visualHilightEnd = get_bidi_cursor_pos(visualStr, (U16) SECOND_HIGHLT);
                testHilighOneCharFlag = 0;
                break;
            case FIRST_HIGHLT:
                *visualHilightStart = get_bidi_cursor_pos(visualStr, (U16) FIRST_HIGHLT);
                testHilighOneCharFlag = 0;

                break;
        }
    }

    if (testHilighOneCharFlag == 0 && *visualHilightEnd == *visualHilightStart)
    {
        *visualHilightEnd = *visualHilightStart = *visualCurPos + 1;
    }

    if ((logicalHilightStart == 0) && (logicalHilightEnd == 0))
    {
        *visualHilightEnd = 0;
        *visualHilightStart = 0;
    }

    if ((*visualHilightEnd <
         /*=*/ *visualHilightStart) /* && (!(*visualHilightStart == 0 && *visualHilightEnd == 0)) */ )
    {
        (*visualHilightEnd)++;
        (*visualHilightStart)++;
    }

    *visualStrLen = (U16) mmi_ucs2strlen((const S8*)visualStr);
}


/*****************************************************************************
 * FUNCTION
 *  set_bidi_cursor_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_str       [?]         
 *  cursor_pos      [IN]        
 *  cursor_mark     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL set_bidi_cursor_pos(U8 *input_str, U16 cursor_pos, U16 cursor_mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sLen, iCount;
    U8 cTemp[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wc_to_ucs2(cursor_mark, (U8*) & sLen, cTemp);

    sLen = (U16) mmi_ucs2strlen((const S8*)input_str);

    if (sLen < cursor_pos)
    {
        return FALSE;
    }

    for (iCount = cursor_pos; iCount <= sLen; iCount++)
    {
        U8 cTempSwap;

        cTempSwap = input_str[iCount * BIDI_ENCODING_LENGTH];
        input_str[iCount * BIDI_ENCODING_LENGTH] = cTemp[0];
        cTemp[0] = cTempSwap;
        cTempSwap = input_str[iCount * BIDI_ENCODING_LENGTH + 1];
        input_str[iCount * BIDI_ENCODING_LENGTH + 1] = cTemp[1];
        cTemp[1] = cTempSwap;
    }

    input_str[iCount * BIDI_ENCODING_LENGTH] = cTemp[0];
    input_str[iCount * BIDI_ENCODING_LENGTH + 1] = cTemp[1];

    return TRUE;
}

/* START Changed by YOGESH PMT 20050912 */


/*****************************************************************************
 * FUNCTION
 *  find_mark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_str           [?]         
 *  input_strLen        [IN]        
 *  cur_mark            [?]         
 *  cur_pos             [?]         
 * RETURNS
 *  
 *****************************************************************************/
pBOOL find_mark(U8 *input_str, U16 input_strLen, U16 *cur_mark, U16 *cur_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sLen, iCount = 0;
    U8 cTemp[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((input_str[iCount * 2] == 0) && (input_str[iCount * 2 + 1] == 0)) && iCount <= input_strLen)
        /* END YOGESH PMT 20050912 */
    {
        mmi_wc_to_ucs2(LAST_MARK, (U8*) & sLen, cTemp);
        if ((input_str[iCount * BIDI_ENCODING_LENGTH] == cTemp[0]) &&
            (input_str[iCount * BIDI_ENCODING_LENGTH + 1] == cTemp[1]))
        {
            *cur_mark = LAST_MARK;
            *cur_pos = iCount;
            return TRUE;
        }
        mmi_wc_to_ucs2(CURSOR_MARK, (U8*) & sLen, cTemp);
        if ((input_str[iCount * BIDI_ENCODING_LENGTH] == cTemp[0]) &&
            (input_str[iCount * BIDI_ENCODING_LENGTH + 1] == cTemp[1]))
        {
            *cur_mark = CURSOR_MARK;
            *cur_pos = iCount;
            return TRUE;
        }
        mmi_wc_to_ucs2(SECOND_HIGHLT, (U8*) & sLen, cTemp);
        if ((input_str[iCount * BIDI_ENCODING_LENGTH] == cTemp[0]) &&
            (input_str[iCount * BIDI_ENCODING_LENGTH + 1] == cTemp[1]))
        {
            *cur_mark = SECOND_HIGHLT;
            *cur_pos = iCount;
            return TRUE;
        }
        mmi_wc_to_ucs2(FIRST_HIGHLT, (U8*) & sLen, cTemp);
        if ((input_str[iCount * BIDI_ENCODING_LENGTH] == cTemp[0]) &&
            (input_str[iCount * BIDI_ENCODING_LENGTH + 1] == cTemp[1]))
        {
            *cur_mark = FIRST_HIGHLT;
            *cur_pos = iCount;
            return TRUE;
        }
        iCount++;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  get_bidi_cursor_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_str       [?]         
 *  cursor_mark     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 get_bidi_cursor_pos(U8 *input_str, U16 cursor_mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sLen, iCount = 0;
    U8 cTemp[2];
    S16 cur_pos = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wc_to_ucs2(cursor_mark, (U8*) & sLen, cTemp);

    /* while((input_str[iCount*BIDI_ENCODING_LENGTH]!=0)&&(input_str[iCount*BIDI_ENCODING_LENGTH+1]!=0)) */
    while (!((input_str[iCount * 2] == 0) && (input_str[iCount * 2 + 1] == 0)))
    {
        if ((input_str[iCount * BIDI_ENCODING_LENGTH] == cTemp[0]) &&
            (input_str[iCount * BIDI_ENCODING_LENGTH + 1] == cTemp[1]))
        {
            cur_pos = iCount;
        }
        if (cur_pos != -1)
        {
            input_str[iCount * BIDI_ENCODING_LENGTH] = input_str[(iCount + 1) * BIDI_ENCODING_LENGTH];
            input_str[iCount * BIDI_ENCODING_LENGTH + 1] = input_str[(iCount + 1) * BIDI_ENCODING_LENGTH + 1];
        }
        iCount++;
    }
    return (U16) ((cur_pos == -1) ? 0 : cur_pos);
}


/*****************************************************************************
 * FUNCTION
 *  bidi_get_char_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_char      [?]     
 *  charType        [?]     
 * RETURNS
 *  
 *****************************************************************************/
pBOOL bidi_get_char_type(U8 *input_char, U8 *charType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = nMaxIndexBidiTypeMap;
    S32 nMid;

    U16 charInput = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __ASCII
    charInput = (U16) (*input_char);
#endif 
#ifdef __UCS2_ENCODING
    mmi_ucs2_to_wc((U16*) & charInput, (U8*) (input_char));
#endif 

    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;
        //START YOGESH PMT 20041108
        //              if((bidiCharTypeMap[nMid].sIndex<= charInput)&&((bidiCharTypeMap[nMid].sIndex+ (U16)bidiCharTypeMap[nMid].nCount)>= charInput))
        if ((bidiCharTypeMap[nMid].sIndex <= charInput) &&
            ((bidiCharTypeMap[nMid].sIndex + (U16) bidiCharTypeMap[nMid].nCount) > charInput))
            /* END YOGESH PMT 20041108 */
        {
            *charType = bidiCharTypeMap[nMid].type;
            return TRUE;
        }
        //START YOGESH PMT 20041108
        //              if (charInput>(bidiCharTypeMap[nMid].sIndex+ (U16)bidiCharTypeMap[nMid].nCount))
        if (charInput >= (bidiCharTypeMap[nMid].sIndex + (U16) bidiCharTypeMap[nMid].nCount))
        {
            /* END YOGESH PMT 20041108 */
            nFirst = nMid + 1;
        }
        else
        {
            if (charInput < bidiCharTypeMap[nMid].sIndex)
            {
                nLast = nMid - 1;
            }
            else
            {
                nLast = nMid;
            }
        }
    }

    *charType = BIDI_L; /* Default Type */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  bidi_get_para_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_str       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 bidi_get_para_direction(U8 *input_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 input_types[MAX_TEXT_LENGTH*BIDI_ENCODING_LENGTH];//source array for storing the direction codes of the input string */
    U16 sLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //START CHANGED by Yogesh 20041224
    //   sLen=get_direction_codes(input_types,input_str);
    sLen = get_direction_codes(input_types, input_str, 0);
    /* END CHANGED by Yogesh 20041224 */

    return (get_para_embedding_level(input_types, sLen)) ? BIDI_R : BIDI_L;
}
#endif /* __MMI_BIDI__ */ 

