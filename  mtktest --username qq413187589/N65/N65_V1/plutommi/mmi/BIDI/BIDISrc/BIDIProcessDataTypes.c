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
 *    bidiprocessdatatypes.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : BIDIProcessDataTypes.c

   PURPOSE     : Main functions of Rule L1 to L4 of BIDI Algorithm

   REMARKS     : nil

   AUTHOR      : Vijay/Bilal

   DATE     : Aug-23-2004

**************************************************************/
#include "MMI_include.h"
#include "BidiDef.h"
#include "BidiProt.h"

/* START TARUN PMT 20041015 */
extern U8 input_types[];    /* source array for storing the direction codes of the input string */
extern U8 input_levels[];   /* This global contains all the embedding levels */
extern U8 dest_levels[];    /* destitnation array for processed levels */
extern U8 dest_types[];     /* Destination array for storing the direction codes of the input string */

/* END TARUN PMT */

/****************************************************************************
Returns BIDI_L or BIDI_R depends on the embedding level & take embeddings levels as parametre
Returns BIDI_R if level is odd
Returns BIDI_L if level is Even     
*****************************************************************************/
#define TOKEN_FOR_LEVEL(x) ((x & 1)? BIDI_R:BIDI_L)

/**************************************************************
Rule:X9
Removes the explicit codes & calculates length of the remaining text & assigns it to textLength.
it modifies the global data structure textLength
It also removes any BN(ParaGraph) delimiter
******************************************************************/


/*****************************************************************************
 * FUNCTION
 *  delete_explicit_direction_codes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputTypes                  [?]         
 *  inputLen                    [IN]        
 *  all_embeddings_level        [?]         
 *  destLevels                  [?]         
 *  destTypes                   [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 delete_explicit_direction_codes(
        U8 *inputTypes,
        U16 inputLen,
        U8 *all_embeddings_level,
        U8 *destLevels,
        U8 *destTypes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount = 0, jCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iCount < inputLen)
    {
        U16 code;

        //START Changed by Yogesh 20041224
        //START TARUN PMT 20041015
        code = inputTypes[iCount];
        //code=input_types[iCount];
        //END TARUN PMT
        if (!((code == RLE) || (code == LRE) || (code == RLO) || (code == LRO) || (code == PDF) || (code == BN)))
        {   /* checking for the presence of RLE,RLO,LRE,LRO,PDF,BN */
            /* dest_levels[jCount]=dest_levels[iCount]; */
            destLevels[jCount] = destLevels[iCount];
            all_embeddings_level[jCount] = all_embeddings_level[iCount];
            /* dest_types[jCount]=dest_types[iCount]; */
            destTypes[jCount] = destTypes[iCount];
            /* END Changed by Yogesh 20041224 */
            jCount++;
        }
        iCount++;
    }
    return jCount;  /* Returns length of the textLength when RLE,RLO,PDF,LRE,BN,LRE are removed */
}

/*********************End of Rule X9*****************************************/

/********************************************************************************
Rule:X10
Calculates the sor(start of run),eor(end of the run) & number of the run levels.
it works with one level at a time. All w1-w7 rules are coded here.
**********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  get_run_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputLen                    [IN]        
 *  paragraphEmbeddingLevel     [IN]        
 *  destLevels                  [?]         
 *  destTypes                   [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void get_run_level(U16 inputLen, U8 paragraphEmbeddingLevel, U8 *destLevels, U8 *destTypes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 lastLevel, calLevel, currentLevel;
    U8 calType, lastType;
    U16 begin = 0, range;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lastLevel = paragraphEmbeddingLevel;    /* At start we put to equal paraGraphembeddingLevel */
    while (begin < inputLen)                /* checking for length */
    {
        //START Changed by Yogesh 20041224
        //currentLevel=dest_levels[begin];
        currentLevel = destLevels[begin];
        lastType = TOKEN_FOR_LEVEL(GETMAX(currentLevel, lastLevel));    /* calculation of sor */
        range = begin + 1;  /* number of characters at the same level */
        //   for(;begin<inputLen && dest_levels[range]==currentLevel;)//calculate tokens having at same level
        //              for(;range<inputLen && dest_levels[range]==currentLevel;)//calculate tokens having at same level
        for (; range < inputLen && destLevels[range] == currentLevel;)  /* calculate tokens having at same level */
        {
            range++;
        }

        /* Changed by Yogesh on Bilal suggestion 20040902 */
        if (range < inputLen)
            /* calLevel=dest_levels[range]; */
        {
            calLevel = destLevels[range];
        }
        else
        {
            calLevel = paragraphEmbeddingLevel;
        }
        calType = TOKEN_FOR_LEVEL(GETMAX(calLevel, currentLevel));      /* calcution of eor */
        //              processWeakTokens(begin,range,currentLevel,lastType,calType,dest_types);//w1-w7 Rules   
        //              processNeutralTokens(begin, range, currentLevel, lastType, calType,dest_types);//N1-N2  
        //              processImplicitLevels(begin, range, currentLevel, lastType, calType,dest_levels,dest_types);//I1_I2
        processWeakTokens(begin, range, currentLevel, lastType, calType, destTypes);    /* w1-w7 Rules */
        processNeutralTokens(begin, range, currentLevel, lastType, calType, destTypes); /* N1-N2 */
        processImplicitLevels(begin, range, currentLevel, lastType, calType, destLevels, destTypes);    /* I1_I2 */
        /* END Changed by Yogesh 20041224 */
        lastLevel = currentLevel;
        begin = range;
    }
}

/****************************************************************************
Aplies Rule W1-W7
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  processWeakTokens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  begin               [IN]        
 *  range               [IN]        
 *  currentLevel        [IN]        
 *  sor                 [IN]        
 *  eor                 [IN]        
 *  dest_types          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void processWeakTokens(U16 begin, U16 range, U16 currentLevel, U8 sor, U8 eor, U8 *dest_types)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/***************************************************************************
Rule W1
Find all NSM & change them to the type of the previous character
If NSM is at the start of the run level, change it with sor
*******************************************************************************/
    S16 iCount, jCount;
    U8 lastType = sor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (iCount = begin; iCount < range; iCount++)
    {
        U8 tempToken = dest_types[iCount];

        if (tempToken == NSM)
        {
            dest_types[iCount] = lastType;
        }
        else
        {
            lastType = tempToken;   /* BBB */
        }
    }
/***************************************************************************
Rule W2
Find the EN & go back till u find AL,BIDI_R,BIDI_L,sor,if u find AL change EN to AL
*******************************************************************************/
    for (iCount = begin; iCount < range; iCount++)
    {
        U8 tempToken = dest_types[iCount];

        if (tempToken == EN)
        {
            for (jCount = iCount - 1; jCount >= begin; jCount--)
            {
                U16 temp = dest_types[jCount];

                if ((temp == BIDI_R) || (temp == BIDI_L) || (temp == AL) || (temp == sor))
                {
                    if (temp == AL)
                    {
                        //START Changed by Yogesh 20041228
                        //dest_types[jCount]=AL;
                        dest_types[iCount] = BIDI_L;
                        /* END Changed by Yogesh 20041228 */
                    }
                    break;
                }

            }
        }
    }
/***************************************************************************
Rule W3
Replace all ALs to BIDI_R.
*******************************************************************************/
    for (iCount = begin; iCount < range; iCount++)
    {
        if (dest_types[iCount] == AL)
        {
            dest_types[iCount] = BIDI_R;
        }
    }

/***************************************************************************
Rule W4
Change ES(Eurpoian seperator) to EN between two EN,s.
CS(common seperator) between two numbers of the same type changes to that type.
First & last token will not play part in Rule
*******************************************************************************/
    for (jCount = begin + 1; jCount < range - 1; jCount++)
    {
        if (dest_types[jCount] == CS || dest_types[jCount] == ES)
        {
            U8 lastToken = dest_types[jCount - 1];
            U8 nextToken = dest_types[jCount + 1];

            if ((dest_types[jCount] == ES || dest_types[jCount] == CS) && lastToken == EN && nextToken == EN)
            {
                dest_types[jCount] = EN;
            }
            else if (dest_types[jCount] == CS && lastToken == nextToken && lastToken == AN)
            {
                dest_types[jCount] = lastToken;
            }
        }
    }
/***************************************************************************
Rule W5
Change  sequence of ET(Eurpoian Terminator) adjacent to EN to all EN,s.
*******************************************************************************/
    for (iCount = begin; iCount < range; ++iCount)
    {
        if (dest_types[iCount] == ET)   /* get end of sequence */
        {
            U8 temp;

            //START Changed by Yogesh 20041224
            //                      U8 validToken[]={ET};
            U8 validToken[1] = {ET};
            U16 carryStart = iCount;

            //Changed by Yogesh on Bilal suggestion 20040904
            //                      U16 varRunRate = get_run_rate(dest_types,carryStart, range,  validToken,4);
            U16 varRunRate = get_run_rate(dest_types, carryStart, range, validToken, 1);

            /* END Changed by Yogesh 20041224 */
            if (carryStart == begin)    /* check values at ends of sequence */
            {
                temp = sor;
            }
            else
            {
                temp = dest_types[carryStart - 1];
            }
            if (temp != EN)
            {
                if (varRunRate == range)
                {
                    temp = eor;
                }
                else
                {
                    temp = dest_types[varRunRate];
                }
            }

            if (temp == EN)
            {
                setTokens(dest_types, carryStart, varRunRate, EN);
            }
            iCount = varRunRate;

        }

    }
/*********************************************************************************************
RuleW6:change remaining teriminators into neutrals
*********************************************************************************************/
    iCount = begin;
    while (iCount < range)
    {
        U8 temp = dest_types[iCount];

        if (temp == CS || temp == ET || temp == ES)
        {
            dest_types[iCount] = ON;
        }
        /* Changed by Yogesh on Bilal suggestion 20040830 */
        iCount++;
    }
/***************************************************************************
Rule W7
Find the EN & go back till u find AL,BIDI_R,BIDI_L,sor,if u find BIDI_L change EN to AL
*******************************************************************************/
    for (iCount = begin; iCount < range; iCount++)
    {
        U8 tempToken = dest_types[iCount];

        if (tempToken == EN)
        {
            for (jCount = iCount - 1; jCount >= begin; jCount--)
            {
                U8 temp = dest_types[jCount];

                if ((temp == BIDI_R) || (temp == BIDI_L) || (temp == AL) || (temp == sor))
                {
                    if (temp == BIDI_L)
                    {
                        /* dest_types[jCount]=BIDI_L; START Yogesh 20041101 */
                        dest_types[iCount] = BIDI_L;    /* START Yogesh 20041101 */

                    }
                    break;
                }

            }
        }
    }
}

/**********************************************************************************************
used to find a particular sequence & returns immediate next index following token
***********************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  get_run_rate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_types      [?]         
 *  base            [IN]        
 *  rate            [IN]        
 *  correctType     [?]         
 *  length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 get_run_rate(U8 *dest_types, U16 base, U16 rate, U8 *correctType, U16 length)     /* return the base if match is not found */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;
    pBOOL bFlag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    --base; /* check with vijay */

    while (++base < rate)
    {
        U8 temp = dest_types[base];

        bFlag = FALSE;
        for (iCount = 0; iCount < length; ++iCount)
        {
            if (temp == correctType[iCount])
            {
                bFlag = TRUE;
                break;
            }
        }
        if (bFlag)
        {
            continue;
        }
        /* can't find a match in correctType */
        return base;
    }
    return rate;
}

/****************************************************************************************************
set new Token types
****************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  setTokens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_types      [?]         
 *  begin           [IN]        
 *  range           [IN]        
 *  newType         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void setTokens(U8 *dest_types, U16 begin, U16 range, U8 newType)       /* check */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (begin < range)
    {
        dest_types[begin] = newType;
        begin++;
    }
}

/*************************************************************************************************
Rule N1 & N2
Processes the Neutral Types
**************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  processNeutralTokens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  begin               [IN]        
 *  range               [IN]        
 *  currentLevel        [IN]        
 *  sor                 [IN]        
 *  eor                 [IN]        
 *  dest_types          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void processNeutralTokens(U16 begin, U16 range, U16 currentLevel, U8 sor, U8 eor, U8 *dest_types)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    // on entry, only these tokens are checked in destTokenTypes
    //Changed by Yogesh on Bilal suggestion 20040904
    //U16 validToken[]= {BIDI_L, BIDI_R, EN, AN, BIDI_B, S, WS, ON};
    U8 validToken[] = {BIDI_B, S, WS, ON};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = begin; i < range; ++i)
    {
        U16 temp = dest_types[i];

        if (temp == WS || temp == ON || temp == BIDI_B || temp == S)
        {
            /* find bounds of run of neutrals */
            U8 leadingToken;
            U8 trailingToken;
            U8 validatedToken;
            U16 runBegin = i;

            /* Changed by Yogesh on Bilal suggestion 20040904 */
            U16 runRange = get_run_rate(dest_types, runBegin, range, validToken, 4);

            /* determine effective types at ends of run */

            if (runBegin == begin)
            {
                leadingToken = sor;
            }
            else
            {
                leadingToken = dest_types[runBegin - 1];
                if (leadingToken == BIDI_L || leadingToken == BIDI_R)
                {
                    /* match found for the strong type */
                }
                else if (leadingToken == AN)
                {
                    leadingToken = BIDI_R;
                }
                else if (leadingToken == EN)
                {
                    /* last clause */

                    leadingToken = BIDI_R;
                }
            }

            if (runRange == range)
            {
                trailingToken = eor;
            }
            else
            {
                trailingToken = dest_types[runRange];
                if (trailingToken == BIDI_L || trailingToken == BIDI_R)
                {
                    /* Match found here */
                }
                else if (trailingToken == AN)
                {
                    trailingToken = BIDI_R;
                }
                else if (trailingToken == EN)
                {
                    trailingToken = BIDI_R;
                }
            }

            if (leadingToken == trailingToken)
            {
                /* Rule N1. */
                validatedToken = leadingToken;
            }
            else
            {
                /* Rule N2. */

                validatedToken = TOKEN_FOR_LEVEL(currentLevel);
            }

            setTokens(dest_types, runBegin, runRange, validatedToken);

            /* skip over run of (former) neutrals */
            i = runRange;
        }
    }
}

/**************************************************************************************************************
Rule:I1 & I2
Resolves the implicit levels
**************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  processImplicitLevels
 * DESCRIPTION
 *  
 * PARAMETERS
 *  begin               [IN]        
 *  range               [IN]        
 *  currentLevel        [IN]        
 *  sor                 [IN]        
 *  eor                 [IN]        
 *  dest_levels         [?]         
 *  dest_types          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void processImplicitLevels(U16 begin, U16 range, U16 currentLevel, U8 sor, U8 eor, U8 *dest_levels, U8 *dest_types)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((currentLevel & 1) == 0)
    {   /* even level */
        for (iCount = begin; iCount < range; ++iCount)
        {
            U8 temp = dest_types[iCount];

            if (temp == BIDI_L)
            {
                /* no change */
            }
            else if (temp == BIDI_R)
            {
                dest_levels[iCount] += 1;
            }
            else if (temp == AN || temp == EN)
            {
                dest_levels[iCount] += 2;
            }
        }
    }
    else
    {   /* odd level */
        for (iCount = begin; iCount < range; ++iCount)
        {
            U8 temp = dest_types[iCount];

            if (temp == BIDI_R)
            {
                /* no change */
            }
            else if (temp == BIDI_L || temp == AN || temp == EN)
            {
                dest_levels[iCount] += 1;
            }

        }
    }
}

/**************************************************************************************************************
Resinserting the explicit levels
returns the textLength
***************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  insert_explicit_direction_codes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputTypes                  [?]         
 *  inputLen                    [IN]        
 *  paragraphEmbeddingLevel     [IN]        
 *  all_embeddings_level        [?]         
 *  dest_levels                 [?]         
 *  dest_types                  [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 insert_explicit_direction_codes(
        U8 *inputTypes,
        U16 inputLen,
        U8 paragraphEmbeddingLevel,
        U8 *all_embeddings_level,
        U8 *dest_levels,
        U8 *dest_types)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (iCount = inputLen; --iCount >= 0;)
    {
        S16 kCount;
        U8 temp = inputTypes[iCount];

        kCount = inputLen;
        if (temp == LRE || temp == RLE || temp == LRO || temp == RLO || temp == PDF || temp == BN)
        {
            all_embeddings_level[iCount] = 0;
            dest_types[iCount] = temp;
            dest_levels[iCount] = 0xff;
        }
        else
        {
            --kCount;
            all_embeddings_level[iCount] = all_embeddings_level[kCount];
            dest_types[iCount] = dest_types[kCount];
            dest_levels[iCount] = dest_levels[kCount];
        }
    }

    // now propagate forward the levels information (could have 
    // propagated backward, the main thing is not to introduce a level
    // break where one doesn't already exist).

    if (dest_levels[0] == -1)
    {
        dest_levels[0] = paragraphEmbeddingLevel;
    }
    for (iCount = 1; iCount < inputLen; ++iCount)
    {
        if (dest_levels[iCount] == -1)
        {
            dest_levels[iCount] = dest_levels[iCount - 1];
        }
    }

    // Embedding information is for informational purposes only
    // so need not be adjusted.

    return inputLen;
}

