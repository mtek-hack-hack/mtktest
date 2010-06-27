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
 *  Ascii.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Ascii.c
   Author:        Manish
   Date Created:  Feb 5-2003
   Contains:      
**********************************************************************************/

#include "MMI_include.h"
#include "Asciiprot.h"
#include "string.h"


/*****************************************************************************
 * FUNCTION
 *  AsciiStrlen
 * DESCRIPTION
 *  Gives the length of Ascii encoded string
 * PARAMETERS
 *  arrOut      [IN]        
 *  PS8(?)      [IN]        > array containing  Ascii encoded characters
 * RETURNS
 *  U16 -> Status
 *****************************************************************************/
S32 AsciiStrlen(const S8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*arrOut)
    {
        ++count;
        ++arrOut;
    }

    return count;

}


/*****************************************************************************
 * FUNCTION
 *  AsciiStrcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strDestination      [?]         
 *  strSource           [IN]        
 *  PS8(?)              [IN]        > array containing  Ascii encoded characters
 * RETURNS
 *  PS8
 *****************************************************************************/
PS8 AsciiStrcpy(S8 *strDestination, const S8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK added by JL 040130 for copy error issue */
    while (!((*strDestination == 0) && (*strSource == 0)))
    {
        ++strDestination;
        ++strSource;
    }

    strDestination = '\0';
    return strDestination;

}


/*****************************************************************************
 * FUNCTION
 *  AsciiStrcmp
 * DESCRIPTION
 *  Compares the ascii encoded strings
 * PARAMETERS
 *  string1     [IN]        
 *  string2     [IN]        
 * RETURNS
 *  S16 -> Status
 *****************************************************************************/
S32 AsciiStrcmp(const S8 *string1, const S8 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* while( (*string1) && (*string2) )
       {
       if((*string1 - *string2) != 0)
       {
       break;
       }
       else
       {
       string1++;
       string2++;
       
       }
       
       }
       return   (*string1 - *string2); */

    while (*string1 == *string2)
    {
        if (*string1 == '\0')
        {
            return 0;
        }

        string1++;
        string2++;

    }
    return (*string1 - *string2);

}


/*****************************************************************************
 * FUNCTION
 *  AsciiStrncmp
 * DESCRIPTION
 *  Compares the ascii encoded strings of specified length
 * PARAMETERS
 *  string1     [IN]        
 *  string2     [IN]        
 *  size        [IN]        
 * RETURNS
 *  S16 -> Status
 *****************************************************************************/
S32 AsciiStrncmp(const S8 *string1, const S8 *string2, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < size)
    {

        if (string1[count] != string2[count])
        {
            return string1[count] - string2[count];
        }
        ++count;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  AsciiStrncpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strDestination      [?]         
 *  strSource           [IN]        
 *  size                [IN]        
 *  PS8(?)              [IN]        > array containing  Ascii encoded characters
 * RETURNS
 *  PS8
 *****************************************************************************/
PS8 AsciiStrncpy(S8 *strDestination, const S8 *strSource, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*strDestination = *strSource) && (count < size))
    {
        ++strDestination;
        ++strSource;
        ++count;
    }

    strDestination = '\0';
    return strDestination;

}


/*****************************************************************************
 * FUNCTION
 *  AsciiStrcat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strDestination      [?]         
 *  strSource           [IN]        
 * RETURNS
 *  PS8
 *****************************************************************************/
PS8 AsciiStrcat(S8 *strDestination, const S8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 *dest = strDestination;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest = dest + AsciiStrlen(strDestination);
    AsciiStrcpy(dest, strSource);
    return strDestination;

}

/* Dummy funtion to be removed later on */


/*****************************************************************************
 * FUNCTION
 *  AsciiStrtok
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strToken        [?]         
 *  strDelimit      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *AsciiStrtok(char *strToken, const char *strDelimit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return "";
}

