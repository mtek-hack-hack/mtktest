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
 *    bidipararules.c
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

   FILENAME : BIDIParaRules.c

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

//END TARUN PMT
//START Added by Yogesh 20050831
#ifdef __BIDI_CONSOLE__
#include "CommonProts.h"
#else /* __BIDI_CONSOLE__ */ 
#endif /* __BIDI_CONSOLE__ */ 
/* END Added by Yogesh 20050831 */
/*********************************************************************
   This function will take the unicode character array as input,
   outputs the directional code array and returns the string len.
********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  get_direction_codes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputTypes      [?]         
 *  inputString     [?]         
 *  sLen            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 get_direction_codes(U8 *inputTypes, U8 *inputString, S16 sLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount = 0;

    /* START Added by Yogesh 20050831 */
    U16 charInput = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_wc((U16*) & charInput, (U8*) (&inputString[iCount * BIDI_ENCODING_LENGTH]));
    /* END Added by Yogesh 20050831 */

    /* START Added by Yogesh 20041224 */
    if (sLen)
        //START Changed by Yogesh 20050831
        //      while( inputString[iCount*BIDI_ENCODING_LENGTH] !=0 && iCount<sLen )
        while (charInput != 0 && iCount < sLen)
            /* END Changed by Yogesh 20050831 */
        {
            bidi_get_char_type(&inputString[iCount * BIDI_ENCODING_LENGTH], &inputTypes[iCount]);
            iCount++;
            /* START Added by Yogesh 20050831 */
            mmi_ucs2_to_wc((U16*) & charInput, (U8*) (&inputString[iCount * BIDI_ENCODING_LENGTH]));
            /* END Added by Yogesh 20050831 */
        }
    else
        //END Added by Yogesh 20041224
        //START Changed by Yogesh 20050831
        //      while( inputString[iCount*BIDI_ENCODING_LENGTH] !=0)
        while (charInput != 0)
            /* END Changed by Yogesh 20050831 */
        {
            bidi_get_char_type(&inputString[iCount * BIDI_ENCODING_LENGTH], &inputTypes[iCount]);
            iCount++;
            /* START Added by Yogesh 20050831 */
            mmi_ucs2_to_wc((U16*) & charInput, (U8*) (&inputString[iCount * BIDI_ENCODING_LENGTH]));
            /* END Added by Yogesh 20050831 */
        }
    return iCount;
}

/************************************************************************
This routine will take the given stream of charcaters as input and break
them in to diffrent paragraphs by taking only the text between paragraph 
seperator directional code 'B'.it returns the revised character count.
*************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  identify_paragraphs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputTypes      [?]         
 *  inputLen        [IN]        
 *  bFlag           [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 identify_paragraphs(U8 *inputTypes, U16 inputLen, pBOOL *bFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //START Changed by Yogesh 20041224 : Function Body Changed
    //Loop till you get paragraph seperator
    for (iCount = 0; ((iCount < inputLen) && (inputTypes[iCount] != BIDI_B)); iCount++);
    if (iCount < inputLen && inputTypes[iCount] == BIDI_B)
    {
        *bFlag = TRUE;
        /* START TARUN PMT 20050202 */
        if (inputTypes[iCount + 1] == BIDI_B)
        {
            iCount++;
        }
        //END TARUN PMT 20050202
        //inputTypes[iCount++] = 0;
    }
    //END Changed by Yogesh 20041224 : Function Body Changed
    //START Commented by YOGESH 20041224 : Added above lines so not required now
    return iCount;
}

/***********************************************************************
This function looks for the first token of any strong type
ie AL , BIDI_L and BIDI_R , then sets the parahraph embedding level depending
upon the strong type. paragraph embedding level is 0  by default ,0
if first strong type is BIDI_L and 1 if first strong type is AL or BIDI_R.
*************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  get_para_embedding_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputTypes      [?]         
 *  inputLen        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 get_para_embedding_level(U8 *inputTypes, U16 inputLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 strongCharType = 0xffff;    /* This will store the first strong character in the */

    /* given input string */
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (iCount = 0; iCount < inputLen; ++iCount)
    {
        U8 token = inputTypes[iCount];

        if (token == AL || token == BIDI_L || token == BIDI_R)
        {
            strongCharType = token;
            break;
        }
    }
    /* return the embedding level depending upon the strong character Type */

    switch (strongCharType)
    {
        case -1:
        case BIDI_L:
        default:
            return 0;
            break;
        case AL:
        case BIDI_R:
            return 1;
            break;
    }
}

/* Returns the least odd level corresponding to the given input level */


/*****************************************************************************
 * FUNCTION
 *  getLeastOddEmbeddingLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pEmbeddinglevel     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 getLeastOddEmbeddingLevel(U8 pEmbeddinglevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ODD(pEmbeddinglevel) ? pEmbeddinglevel + 2 : pEmbeddinglevel + 1;
}

/* Returns the least odd level corresponding to the given input level */


/*****************************************************************************
 * FUNCTION
 *  getLeastEvenEmbeddingLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pEmbeddinglevel     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 getLeastEvenEmbeddingLevel(U8 pEmbeddinglevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ODD(pEmbeddinglevel) ? pEmbeddinglevel + 1 : pEmbeddinglevel + 2;
}

/* This function is to determine all explicit embedding levels and directions.
   if any directional type of RLE ,LRE,LRO or RLO appears */
//START Changed by Yogesh 20041224 : Function definition changed
//Get all explicit embedding level
//START TARUN PMT 20041015
//void resolve_explicit_embedding_levels(U8* inputTypes,U16 inputLen,U8 paraEmbeddingLevel,U8* all_embeddings_level)
//void resolve_explicit_embedding_levels(U16 inputLen,U8 paraEmbeddingLevel/*,U8* all_embeddings_level*/)
//END TARUN PMT


/*****************************************************************************
 * FUNCTION
 *  resolve_explicit_embedding_levels
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputTypes              [?]         
 *  inputLen                [IN]        
 *  paraEmbeddingLevel      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void resolve_explicit_embedding_levels(U8 *inputTypes, U16 inputLen, U8 paraEmbeddingLevel)    /* ,U8* all_embeddings_level) */
/* END Changed by Yogesh 20041224 */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    //all the local variables used for stack operations
    //keeps track of stack full/empty status 
    U16 stackFullIndicator = 0;

    //This is to keep track for the invalid embedding level in the case 
    //when RLE ,LRE , RLO or LRO happens at level 60
    U16 stackAboutToFullIndicator = 0;

    /* used as an index to the embedding levels stack */
    U16 stackIndex = 0;

    /* For storing the updated value of embedding level */
    U8 newEmbeddingLevel;

    /* This array is used to store all the embedding levels encountered */
    U8 pushedEmbeddingValues[MAX_LEVEL_EMBEDDING];

    U8 token;
    U8 presentEmbeddingLevel = paraEmbeddingLevel;
    U8 presentEmbeddingValue = paraEmbeddingLevel;
    S16 iCount = 0; /* Loop Counter */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iCount < inputLen)
    {
        input_levels[iCount] = presentEmbeddingValue;
        //START Changed by Yogesh 20041224 : Revert back Tarun Changes as function def changed
        //START TARUN PMT 20041015
        token = inputTypes[iCount];
        //token = input_types[iCount];
        //END TARUN PMT
        //END Changed by Yogesh 20041224 : Revert back Tarun Changes as function def changed
        //process if RLE ,LRE ,RLO ,LRO are there
        if (token == RLE || token == LRE || token == LRO || token == RLO)
        {
            /* proceed only when current level is valid */
            if (stackFullIndicator == 0)
            {
                if (token == RLE || token == RLO)
                {
                    /* Get the least odd embedding level */
                    newEmbeddingLevel = getLeastOddEmbeddingLevel(presentEmbeddingLevel);
                }
                else
                {
                    /* Get the least even embedding level */
                    newEmbeddingLevel = getLeastEvenEmbeddingLevel(presentEmbeddingLevel);
                }

                /*
                 * If this updated embedding level does not cross the boundry of
                 * MAX_LEVEL_EMBEDDING remember this embedding level by pushing in to the stack
                 */
                if (newEmbeddingLevel < MAX_LEVEL_EMBEDDING)
                {
                    pushedEmbeddingValues[stackIndex] = newEmbeddingLevel;
                    stackIndex++;
                    presentEmbeddingLevel = newEmbeddingLevel;

                    if (token == LRO || token == RLO)
                    {
                        presentEmbeddingValue = (presentEmbeddingLevel | 0x80);
                    }
                    else
                    {
                        presentEmbeddingValue = presentEmbeddingLevel;
                    }

                    /* Now push this embedding in to the stack */
                    pushedEmbeddingValues[stackIndex] = presentEmbeddingValue;
                }

                if (presentEmbeddingValue == MAX_LEVEL_EMBEDDING - 1)
                {
                    stackAboutToFullIndicator++;
                }
            }   /* if (stackFullIndicator == 0) */
            stackFullIndicator++;
        }       /* if RLE ,LRE , LRO , RLO */
        else
        {
            if (token == PDF)
            {
                /*
                 * This is just like an end brace '}' and we have to find start brace'{' 
                 * corresponding to each PDF stack is already full , decrement it 
                 * since we are going to pop one embedding level
                 */
                if ((stackAboutToFullIndicator > 0) && (presentEmbeddingLevel != MAX_LEVEL_EMBEDDING))
                {
                    stackAboutToFullIndicator--;
                }
                else
                {
                    stackIndex--;
                }

                /* pop up the embedding value from the stack */
                presentEmbeddingValue = pushedEmbeddingValues[stackIndex];
                /* get the overriding status */
                presentEmbeddingLevel = presentEmbeddingValue & 0x7f;
            }   /* if( token == PDF ) */
            else
            {
                if (token == BIDI_B)
                {
                    /* Reset all the variables as 'BIDI_B' is the last token processed */
                    presentEmbeddingLevel = paraEmbeddingLevel;
                    presentEmbeddingValue = paraEmbeddingLevel;
                    stackIndex = 0;
                    stackAboutToFullIndicator = 0;
                    pushedEmbeddingValues[iCount] = paraEmbeddingLevel;
                }   /* if(token==BIDI_B) */
            }       /* if( token == PDF ) */
        }
        iCount++;
    }   /* End of while loop */
}


/*****************************************************************************
 * FUNCTION
 *  set_dest_levels
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nSCount             [IN]        
 *  nECount             [IN]        
 *  paraEmbedLevel      [IN]        
 *  pDestLevels         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void set_dest_levels(U16 nSCount, U16 nECount, U8 paraEmbedLevel, U8 *pDestLevels)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      while (startCount<=endCount)
    //              dest_levels[startCount++] = paraEmbedLevel;
    while (nSCount < nECount)
    {
        pDestLevels[nSCount++] = paraEmbedLevel;
    }
}


/*****************************************************************************
 * FUNCTION
 *  copy_direction_codes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dTypes      [?]         
 *  sTypes      [?]         
 *  nCount      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void copy_direction_codes(U8 *dTypes, U8 *sTypes, U16 nCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (iCount = 0; iCount < nCount; iCount++)
    {
        dTypes[iCount] = sTypes[iCount];
    }
}

