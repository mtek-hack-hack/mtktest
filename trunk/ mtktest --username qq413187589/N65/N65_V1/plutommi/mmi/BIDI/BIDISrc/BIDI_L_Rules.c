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
 *    bidi_l_rules.c
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

   FILENAME : BIDI_L_Rules.c

   PURPOSE     : Main functions of Rule L1 to L4 of BIDI Algorithm

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : Aug-23-2004

**************************************************************/
#include "MMI_include.h"
#include "BidiDef.h"
#include "BidiProt.h"

#ifdef __BIDI_CONSOLE__
#include "CommonProts.h"
#else 
#endif 


/*****************************************************************************
 * FUNCTION
 *  resolve_lines
 * DESCRIPTION
 *  
 * PARAMETERS
 *  paragraphEmbeddingLevel     [IN]        
 *  inputString                 [?]         
 *  paraCount                   [IN]        
 *  mirrorFlag                  [IN]        
 *  pInput_Types                [?]         
 *  pInput_Levels               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void resolve_lines(
        U8 paragraphEmbeddingLevel,
        U8 *inputString,
        U16 paraCount,
        pBOOL mirrorFlag,
        U8 *pInput_Types,
        U8 *pInput_Levels)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lineCount = 0;
    U16 *pBreak = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* break lines at LS */
        lineCount = bidi_resolve_lines(inputString, paraCount, pBreak);

        /* resolve whitespace */
        bidi_resolve_white_space(paragraphEmbeddingLevel, pInput_Types, pInput_Levels, lineCount);

        if (mirrorFlag)
        {
            get_mirror(inputString, pInput_Levels, lineCount);
        }

        /* reorder each line in place */
        bidi_reorder(paragraphEmbeddingLevel, inputString, pInput_Levels, lineCount);

        //Changed by Yogesh 20041224
        //              inputString += lineCount;
        inputString += lineCount * BIDI_ENCODING_LENGTH;
        pInput_Levels += lineCount;
        pBreak += pBreak ? lineCount : 0;
        pInput_Types += lineCount;
        paraCount -= lineCount;

    } while (paraCount);
}


/*****************************************************************************
 * FUNCTION
 *  bidi_resolve_white_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_level          [IN]        
 *  pInput_Types        [IN]        
 *  pInput_Level        [?]         
 *  lineCount           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bidi_resolve_white_space(U8 base_level, const U8 *pInput_Types, U8 *pInput_Level, U16 lineCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cur_level = 0, old_level = base_level;
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (iCount = 0; iCount < lineCount; iCount++)
    {
        switch (pInput_Types[iCount])
        {
            case WS:
                //START TARUN 20041204
                //cur_level++;
                //break;
                //END TARUN 20041204
            case RLE:
            case LRE:
            case LRO:
            case RLO:
            case PDF:
            case BN:
                pInput_Level[iCount] = old_level;
                cur_level++;
                break;
            case S:
            case BIDI_B:
                bidi_set_level_run(pInput_Level, cur_level, iCount, base_level);
                cur_level = 0;
                pInput_Level[iCount] = base_level;
                break;
            default:
                cur_level = 0;
                break;
        }
        old_level = pInput_Level[iCount];
    }
    bidi_set_level_run(pInput_Level, cur_level, iCount, base_level);
}


/*****************************************************************************
 * FUNCTION
 *  bidi_set_level_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pinput_level        [?]         
 *  cur_level           [IN]        
 *  iStart              [IN]        
 *  base_level          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bidi_set_level_run(U8 *pinput_level, U8 cur_level, U16 iStart, U8 base_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (iCount = iStart - 1; iCount >= iStart - cur_level; iCount--)
    {
        pinput_level[iCount] = base_level;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bidi_resolve_lines
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pinput      [?]         
 *  cCount      [IN]        
 *  pBreak      [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 bidi_resolve_lines(U8 *pinput, U16 cCount, U16 *pBreak)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* skip characters not of type LS */
    for (iCount = 0; iCount < (cCount); iCount++)
    {
        //START TARUN PMT 20041214
        //START Changed by Yogesh 20041224
        //              if ((pinput[iCount] == LS)||(pBreak && pBreak[iCount])||(pinput[iCount] == NL) )
        if (((pinput[iCount * BIDI_ENCODING_LENGTH] == LS) && (pinput[(iCount * BIDI_ENCODING_LENGTH) + 1] == 0)) ||
            (pBreak && pBreak[iCount]) || ((pinput[iCount * BIDI_ENCODING_LENGTH] == NL) &&
                                           (pinput[(iCount * BIDI_ENCODING_LENGTH) + 1] == 0)))
            //END Changed by Yogesh 20041224
            //END TARUN PMT 20041214
        {
            iCount++;
            break;
        }
    }

    return iCount;
}


/*****************************************************************************
 * FUNCTION
 *  get_mirror
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputString         [?]         
 *  input_levels        [?]         
 *  lineCount           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_mirror(U8 *inputString, U8 *input_levels, U16 lineCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (iCount = 0; iCount < lineCount; iCount++)
    {
        if (!ODD(input_levels[iCount]))
        {
            continue;
        }
        get_mirror_char(&inputString[iCount * BIDI_ENCODING_LENGTH]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_mirror_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pinput      [?]     
 * RETURNS
 *  
 *****************************************************************************/
pBOOL get_mirror_char(U8 *pinput)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 charInput = 0;
    S32 nFirst = 0;
    S32 nLast = nMaxIndexBidiMirror;
    S32 nMid;

#ifdef __UCS2_ENCODING
    U8 charLen;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __ASCII
    charInput = (U16) (*pinput);
#endif 
#ifdef __UCS2_ENCODING
    mmi_ucs2_to_wc((U16*) & charInput, pinput);
#endif 

    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;

        if (bidiCharMirror[nMid].bidiChar == charInput)
        {

        #ifdef __ASCII
            *pinput = (U8) (bidiCharMirror[nMid].bidiMirror);
        #endif 
        #ifdef __UCS2_ENCODING
            mmi_wc_to_ucs2(bidiCharMirror[nMid].bidiMirror, &charLen, pinput);
        #endif 
            return TRUE;
        }
        else if (bidiCharMirror[nMid].bidiMirror == charInput)
        {

        #ifdef __ASCII
            *pinput = (U8) (bidiCharMirror[nMid].bidiChar);
        #endif 
        #ifdef __UCS2_ENCODING
            mmi_wc_to_ucs2(bidiCharMirror[nMid].bidiChar, &charLen, pinput);
        #endif 
            return TRUE;
        }
        else
        {
            //START YOGESH 20041122        
            //if(bidiCharMirror[nMid].bidiChar>charInput)
            if (bidiCharMirror[nMid].bidiChar < charInput)
                /* END YOGESH 20041122 */
            {
                nFirst = nMid + 1;
            }
            else
            {
                nLast = nMid - 1;
            }
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  bidi_reorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_level      [IN]        
 *  pinput          [?]         
 *  input_level     [?]         
 *  cCount          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 bidi_reorder(U8 base_level, U8 *pinput, U8 *input_level, U16 cCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 iCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iCount < cCount)
    {
        /* By Yogesh on 20040904 */
        iCount += bidi_reorder_level(
                    base_level,
                    pinput + iCount * BIDI_ENCODING_LENGTH,
                    input_level + iCount,
                    (U16) (cCount - iCount),
                    FALSE);
    }
    return iCount;
}


/*****************************************************************************
 * FUNCTION
 *  bidi_reorder_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  level               [IN]        
 *  pinput              [?]         
 *  input_level         [?]         
 *  cCount              [IN]        
 *  reverse_flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 bidi_reorder_level(U8 level, U8 *pinput, U8 *input_level, U16 cCount, pBOOL reverse_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reverse_flag = reverse_flag || ODD(level);

    for (iCount = 0; iCount < cCount; iCount++)
    {
        if (input_level[iCount] < level)
        {
            break;
        }
        else if (input_level[iCount] > level)
        {
            /* By Yogesh on 20040904 */
            iCount += bidi_reorder_level(
                        (U8) (level + 1),
                        pinput + iCount * BIDI_ENCODING_LENGTH,
                        input_level + iCount,
                        (U16) (cCount - iCount),
                        reverse_flag) - 1;
        }
    }
    //START Changed by Yogesh 20041224
    //    if (reverse_flag)
    if (reverse_flag && iCount)
        /* END Changed by Yogesh 20041224 */
    {
        bidi_reverse(pinput, iCount);
    }
    /* START Changed by Yogesh 20041224 */
    if (!iCount)
    {
        iCount = 1;
    }
    /* END Changed by Yogesh 20041224 */
    return iCount;
}


/*****************************************************************************
 * FUNCTION
 *  bidi_reverse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pinput      [?]         
 *  cCount      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bidi_reverse(U8 *pinput, U16 cCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cTemp;

    /* START Changed by Yogesh 20041224 : Function body changed */
    S16 iCount = 0, jCount = 0, kCount = 0;
    pBOOL bFlag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iCount < cCount)
    {
        bFlag = FALSE;
        for (jCount = iCount; jCount < cCount; jCount++)
        {
            if (pinput[jCount * BIDI_ENCODING_LENGTH] == 0x0a && pinput[jCount * BIDI_ENCODING_LENGTH + 1] == 0x00)
            {
                /* jCount--; */
                bFlag = TRUE;
                break;
            }
        }

        for (kCount = iCount; kCount < (iCount + (jCount - iCount) / 2); kCount++)
        {
        #ifdef __ASCII
            cTemp = pinput[kCount];
            pinput[kCount] = pinput[jCount - 1 - kCount];
            pinput[jCount - 1 - kCount] = cTemp;
        #endif /* __ASCII */ 
        #ifdef __UCS2_ENCODING
            cTemp = pinput[kCount * BIDI_ENCODING_LENGTH];
            pinput[kCount * BIDI_ENCODING_LENGTH] = pinput[(jCount + iCount - 1 - kCount) * BIDI_ENCODING_LENGTH];
            pinput[(jCount + iCount - 1 - kCount) * BIDI_ENCODING_LENGTH] = cTemp;
            cTemp = pinput[kCount * BIDI_ENCODING_LENGTH + 1];
            pinput[kCount * BIDI_ENCODING_LENGTH + 1] =
                pinput[(jCount + iCount - 1 - kCount) * BIDI_ENCODING_LENGTH + 1];
            pinput[(jCount + iCount - 1 - kCount) * BIDI_ENCODING_LENGTH + 1] = cTemp;
        #endif /* __UCS2_ENCODING */ 
        }
        if (bFlag)
        {
            jCount++;
        }
        iCount = jCount;
    }
    /* END Changed by Yogesh 20041224 : Function body changed */
}

