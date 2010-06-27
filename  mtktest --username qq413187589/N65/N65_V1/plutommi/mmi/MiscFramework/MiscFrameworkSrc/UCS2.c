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
 *   UCS2.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   UCS2 utility
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      UCS2.c
   Author:        Manish
   Date Created:  Feb 5-2003
   Contains:      
**********************************************************************************/

#include "MMIDataType.h"
#include "Ucs2dcl.h"
#include "Ucs2prot.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "DebugInitDef.h"
#include "app_str.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_wc_to_ucs2
 * DESCRIPTION
 *  convert unicode to UCS2 encoding
 * PARAMETERS
 *  unicode         [IN]        Value to be encoded
 *  charLength      [OUT]         
 *  arrOut          [OUT]         
 * RETURNS
 *  U8 -> Status
 *****************************************************************************/
U8 mmi_wc_to_ucs2(U16 unicode, U8 *charLength, U8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U8)app_unicode_to_ucs2encoding(
                (kal_uint16)unicode, 
                (kal_uint8*)charLength,
                (kal_uint8*)arrOut);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2_to_wc
 * DESCRIPTION
 *  convert UCS2 encoded scheme to unicode
 * PARAMETERS
 *  pUnicode        [IN]       	array containing  UCS2 encoded characters
 *  arr             [IN]        unicode equivalent
 * RETURNS
 *  U8 -> Status
 *****************************************************************************/
U8 mmi_ucs2_to_wc(PU16 pUnicode, PU8 arr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U8)app_ucs2encoding_to_unicode((kal_wchar *)pUnicode, (kal_uint8*)arr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2strlen
 * DESCRIPTION
 *  Gives the length of UCS2 encoded string
 * PARAMETERS
 *  arrOut      [IN]        array containing  UCS2 encoded characters
 * RETURNS
 *  U16 -> Status
 *****************************************************************************/
S32 mmi_ucs2strlen(const S8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S32)app_ucs2_strlen((const kal_int8 *)arrOut);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2cpy
 * DESCRIPTION
 *  copies the one UCS2 encoded string to other
 * PARAMETERS
 *  strDestination      [OUT]       StrDest-> Destination array
 *  strSource           [IN]        
 * RETURNS
 *  PS8 -> pointer to destination string or NULL
 *****************************************************************************/
S8 *mmi_ucs2cpy(S8 *strDestination, const S8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S8*)app_ucs2_strcpy((kal_int8*)strDestination, (const kal_int8*)strSource);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2cmp
 * DESCRIPTION
 *  compares two strings
 * PARAMETERS
 *  string1     [IN]        > first String
 *  string2     [OUT]       > Second String
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_ucs2cmp(const S8 *string1, const S8 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S32)app_ucs2_strcmp((const kal_int8*)string1, (const kal_int8*)string2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2ncmp
 * DESCRIPTION
 *  compares two strings
 *  
 *  In size pass no of characters not bytes
 * PARAMETERS
 *  string1     [IN]        > first String
 *  string2     [OUT]       > Second String
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
/* MTK Added by Tim for solve a potential wrong answer when string1 and string2 are the same and less than "size" */
S32 mmi_ucs2ncmp(const S8 *string1, const S8 *string2, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S32)app_ucs2_strncmp(
                    (const kal_int8*)string1,
                    (const kal_int8*)string2,
                    (kal_uint32)size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2ncpy
 * DESCRIPTION
 *  copies the one UCS2 encoded string to other
 *  
 *  In size pass no of characters not bytes
 * PARAMETERS
 *  strDestination      [OUT]       StrDest-> Destination array
 *  strSource           [IN]        
 *  size                [IN]        
 * RETURNS
 *  PS8 -> pointer to destination string or NULL
 *****************************************************************************/
S8 *mmi_ucs2ncpy(S8 *strDestination, const S8 *strSource, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S8*)app_ucs2_strncpy(
                    (kal_int8*)strDestination,
                    (const kal_int8*)strSource,
                    (kal_uint32)size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2cat
 * DESCRIPTION
 *  
 *  
 *  User has to ensure that enough space is
 *  available in destination
 * PARAMETERS
 *  strDestination      [OUT]         
 *  strSource           [IN]        
 * RETURNS
 *  PS8
 *****************************************************************************/
S8 *mmi_ucs2cat(S8 *strDestination, const S8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S8*)app_ucs2_strcat((kal_int8*)strDestination, (const kal_int8*)strSource);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2ncat
 * DESCRIPTION
 *  
 *  
 *  User has to ensure that enough space is
 *  available in destination
 * PARAMETERS
 *  strDestination      [OUT]         
 *  strSource           [IN]        
 *  size                [IN]        
 * RETURNS
 *  PS8
 *****************************************************************************/
S8 *mmi_ucs2ncat(S8 *strDestination, const S8 *strSource, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S8*)app_ucs2_strncat(
                    (kal_int8*)strDestination, 
                    (const kal_int8*)strSource,
                    (kal_uint32)size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2chr
 * DESCRIPTION
 *  Searches a UCS2 encoded string for a given wide-character,
 *  which may be the null character L'\0'.
 * PARAMETERS
 *  strSrc        [IN]  UCS2 encoded string to search in.       
 *  c             [IN]  UCS2 encoded wide-character to search for.      
 * RETURNS
 *  returns pointer to the first occurrence of ch in string
 *  returns NULL if ch does not occur in string
 *****************************************************************************/
S8 *mmi_ucs2chr(const S8 *strSrc, U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8 *)app_ucs2_strchr((const kal_int8 *)strSrc,  (kal_wchar)c);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2trim_left
 * DESCRIPTION
 *  skip over the TrimChars
 * PARAMETERS
 *  strSrc          [IN]        
 *  TrimChars       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_ucs2trim_left(const S8 *strSrc, const S8 *TrimChars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *chr = (U16*) strSrc;
    S32 trim_length = mmi_ucs2strlen(TrimChars);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*chr)
    {
        S32 i = 0;

        for (; i < trim_length; i++)
        {
            if (*chr == ((U16*) TrimChars)[i])
            {
                chr++;
                break;
            }
        }
        if (i == trim_length)
        {
            return (S8*) chr;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2find
 * DESCRIPTION
 *  search for the break_chars and store how many chars have been read over to reach
 *  the desired break_char in read_length
 * PARAMETERS
 *  strSrc          [IN]        
 *  break_chars     [IN]        
 *  read_length     [?]         
 *  direction       [IN]        1: sesarch forward ; -1: search backward.
 * RETURNS
 *  1: found the break_chars ;  -1: searched over the whole strSrc and do not fing the break_chars
 *****************************************************************************/
S32 mmi_ucs2find(const S8 *strSrc, const S8 *break_chars, S32 *read_length, S16 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src = (U16*) strSrc;
    S32 x = 0;
    S32 break_chars_length = mmi_ucs2strlen(break_chars);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*src)
    {
        for (x = 0; x < break_chars_length; x++)
        {
            if (*src == ((U16*) break_chars)[x])
            {
                if (direction > 0)
                {
                    *read_length = src - (U16*) strSrc;
                }
                else
                {
                    *read_length = (U16*) strSrc - src;
                }
                return 1;
            }
        }
        src += direction;
    }
    return -1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2toi
 * DESCRIPTION
 *  to parse over a int number, including positive and negative signs (+,-).
 * PARAMETERS
 *  strSrc          [IN]        
 *  out_num         [?]         Is the parsed int number
 *  read_length     [?]         
 * RETURNS
 *  1: parse successfully ; -1: parse number fail.
 *****************************************************************************/
S32 mmi_ucs2toi(const S8 *strSrc, S32 *out_num, S32 *read_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define     GETNUM(wchar_p) (*wchar_p - L'0')

    U16 *src = (U16*) strSrc;
    BOOL is_negative = FALSE;
    S32 num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*src == L'-')
    {
        is_negative = TRUE;
        src++;
    }
    if (*src == L'+')
    {
        src++;
    }
    if (GETNUM(src) < 0 || GETNUM(src) > 9)
    {
        return -1;
    }
    while (*src)
    {
        if (GETNUM(src) < 0 || GETNUM(src) > 9)
        {
            break;
        }
        num = num * 10 + GETNUM(src);
        src++;
    }

    *read_length = src - (U16*) strSrc;

    if (is_negative)
    {
        *out_num = -num;
    }
    else
    {
        *out_num = num;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_asc_to_ucs2
 * DESCRIPTION
 *  Converts Ansii encode string to unicode
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be as large
 * PARAMETERS
 *  pOutBuffer      [OUT]     
 *  pInBuffer       [IN]     
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_asc_to_ucs2(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U16)app_asc_str_to_ucs2_str((kal_int8*)pOutBuffer, (kal_int8*)pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_asc_n_to_ucs2
 * DESCRIPTION
 *  Converts N character Ansii encode string to unicode
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be as large
 * PARAMETERS
 *  pOutBuffer      [OUT]         
 *  pInBuffer       [IN]         
 *  len             [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_asc_n_to_ucs2(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U16)app_asc_str_n_to_ucs2_str(
                    (kal_int8*)pOutBuffer,
                    (kal_int8*)pInBuffer,
                    (kal_uint32)len);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_asc_to_ucs2_Ex
 * DESCRIPTION
 *  The function is used for convert ANSII string to UCS2 string. The caller
 *  need to make sure the pOutBuffer  size must have enough space or the function
 *  causes the memory corruption. The function will add the terminated character
 *  at the end of pOutBuffer array. The byte order of UCS2 character(output param)
 *  is little endian.
 *  Unlike mmi_asc_to_ucs2, it will ignore the controls in ANSII string. 
 * PARAMETERS
 *  pOutBuffer      [OUT]   UCS2 destination string  
 *  pInBuffer       [IN]    ANSII source string  
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_asc_to_ucs2_ex(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 count = -1;
    U8 charLen = 0;
    U8 arrOut[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pInBuffer != '\0')
    {
        if ((*pInBuffer > 0x00)&&(*pInBuffer < 0x20)||(*pInBuffer == 0x07F))
		{
			pInBuffer++;
            continue;
		}

        mmi_wc_to_ucs2((U16) * ((PU8) pInBuffer), &charLen, arrOut);

        pOutBuffer[++count] = arrOut[0];
        pOutBuffer[++count] = arrOut[1];
        pInBuffer++;
     }

    pOutBuffer[++count] = '\0';
    pOutBuffer[++count] = '\0';
    return count + 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_asc_n_to_ucs2_Ex
 * DESCRIPTION
 *  The function is used for convert the characters of ANSII string to UCS2
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(output param) is
 *  little endian.
 *  Unlike mmi_asc_n_to_ucs2, it will ignore the controls in ANSII string.
 * PARAMETERS
 *  pOutBuffer      [OUT]  UCS2 destination string.        
 *  pInBuffer       [IN]   ANSII source string      
 *  len             [IN]   size in bytes     
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_asc_n_to_ucs2_ex(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 count = -1;
    U8 charLen = 0;
    U8 arrOut[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len)
    {
        if ((*pInBuffer > 0x00)&&(*pInBuffer < 0x20)||(*pInBuffer == 0x07F))
		{
			pInBuffer++;
			len--;
            continue;
		}

        mmi_wc_to_ucs2((U16) * ((PU8) pInBuffer), &charLen, arrOut);

        pOutBuffer[++count] = arrOut[0];
        pOutBuffer[++count] = arrOut[1];

        if (*pInBuffer == '\0')
        {
            break;
        }
        else
        {
            pInBuffer++;
        }        

        len--;

    }

    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2_to_asc
 * DESCRIPTION
 *  Converts Unicode encode string to Ascii
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be  large enough
 * PARAMETERS
 *  pOutBuffer      [OUT]     
 *  pInBuffer       [IN]     
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_ucs2_to_asc(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U16)app_ucs2_str_to_asc_str((kal_int8*)pOutBuffer,(kal_int8*)pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2_n_to_asc
 * DESCRIPTION
 *  Converts N character Unicode encode string to Ascii
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be  large enough
 * PARAMETERS
 *  pOutBuffer      [OUT]         
 *  pInBuffer       [IN]         
 *  len             [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_ucs2_n_to_asc(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U16)app_ucs2_str_n_to_asc_str(
                    (kal_int8*)pOutBuffer,
                    (kal_int8*)pInBuffer,
                    (kal_uint32)len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2rchr
 * DESCRIPTION
 *  Scan a UCS2 encoded string for the last occurrence of a character.
 * PARAMETERS
 *  string        [IN]  UCS2 encoded string to search in.       
 *  ch            [IN]  UCS2 encoded wide-character to search for.      
 * RETURNS
 *  returns pointer to the last occurrence of ch in string
 *  returns NULL if ch does not occur in string
 *****************************************************************************/
S8 *mmi_ucs2rchr(const S8 * string, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*)app_ucs2_strrchr((const kal_int8 *)string, (kal_wchar)ch);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2upr
 * DESCRIPTION
 *  app_ucs2_strupr converts upper-case characters in a null-terminated 
 *  UCS2 encoded string their upper-case equivalents.  
 * PARAMETERS
 *  string    [IN]  UCS2 encoded string to change to upper case.      
 * RETURNS
 *  returns a pointer to the converted string. Because the modification is 
 *  done in place, the pointer returned is the same as the pointer passed 
 *  as the input argument.
 *****************************************************************************/
S8 *mmi_ucs2upr(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8 *)app_ucs2_strupr((kal_int8 *)string);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2nicmp
 * DESCRIPTION
 *  Compares two UCS2 encoded strings for lexical order without regard to case. 
 *  The comparison stops after: 
 *  (1) a difference between the strings is found; 
 *  (2) the end of the strings is reached;
 *  (3) count characters have been compared.
 * PARAMETERS
 *  str_src   [IN]  UCS2 encoded destination string for 
 *                  left-hand side of comparison.
 *  str_dst   [IN]  UCS2 encoded source string for right-hand 
 *                  side of comparison. 
 *  count     [IN]  Number of characters to compare.    
 * RETURNS
 *  returns -1 if str_src <  str_dst
 *  returns  0 if str_src == str_dst
 *  returns +1 if str_src >  str_dst
 *****************************************************************************/
S32 mmi_ucs2nicmp(const S8 *str_src, const S8 *str_dst, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return (S32)app_ucs2_strnicmp((const kal_int8 *)str_src, 
								 (const kal_int8 *)str_dst, 
                                 (kal_uint32) count);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2lwr
 * DESCRIPTION
 *  mmi_ucs2lwr converts lower-case characters in a null-terminated 
 *  UCS2 encoded string their lower-case equivalents.  
 * PARAMETERS
 *  string    [IN]  UCS2 encoded string to change to upper case.      
 * RETURNS
 *  returns a pointer to the converted string. Because the modification is 
 *  done in place, the pointer returned is the same as the pointer passed 
 *  as the input argument.
 *****************************************************************************/
S8 *mmi_ucs2lwr(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8 *)app_ucs2_strlwr((kal_int8 *)string);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2icmp
 * DESCRIPTION
 *  UCS2SStricmp perform a case-insensitive UCS2 encoded string
 *  (wide-character) comparison.
 * PARAMETERS
 *  str_src   [IN]  UCS2 encoded destination string for 
 *                  left-hand side of comparison.
 *  str_dst   [IN]  UCS2 encoded source string for right-hand 
 *                  side of comparison. 
 * RETURNS
 *  returns -1 if str_src <  str_dst
 *  returns  0 if str_src == str_dst
 *  returns +1 if str_src >  str_dst
 *****************************************************************************/
S32 mmi_ucs2icmp(const S8 *str_src, const S8 *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)app_ucs2_stricmp((const kal_int8*)str_src, (const kal_int8*)str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_asc_to_wcs
 * DESCRIPTION
 *  The function is used for convert ANSII string to UCS2 string. The caller
 *  need to make sure the pOutBuffer  size must have enough space or the function
 *  causes the memory corruption. The function will add the terminated character
 *  at the end of pOutBuffer array. The byte order of UCS2 character(output param)
 *  is little endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]  UCS2 destination string   
 *  pInBuffer       [IN]   ANSII source string  
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_asc_to_wcs(U16 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    return (U16)app_asc_str_to_ucs2_wcs((kal_wchar *)pOutBuffer, (kal_int8 *)pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_asc_n_to_wcs
 * DESCRIPTION
 *  The function is used for convert the characters of ANSII string to UCS2
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(output param) is
 *  little endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]   UCS2 destination string.      
 *  pInBuffer       [IN]    ANSII source string     
 *  len             [IN]    size in bytes   
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_asc_n_to_wcs(U16 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16)app_asc_str_n_to_ucs2_wcs((kal_wchar *)pOutBuffer, (kal_int8 *)pInBuffer, (kal_uint32)len);
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcs_to_asc_str
 * DESCRIPTION
 *  The function is used for convert UCS2 string to ANSII string. 
 *  The caller need to make sure the pOutBuffer  size must have enough space 
 *  or the function causes the memory corruption. The function will add the 
 *  terminated character at the end of pOutBuffer array. 
 * PARAMETERS
 *  pOutBuffer      [OUT]   ANSII destination string  
 *  pInBuffer       [IN]    UCS2 source string 
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_wcs_to_asc(S8 *pOutBuffer, U16 *pInBuffer)
{
   	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    return (U16)app_ucs2_wcs_to_asc_str((kal_int8 *)pOutBuffer, (kal_wchar *)pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcs_n_to_asc
 * DESCRIPTION
 *  The function is used for convert the characters of UCS2 string to ANSII
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(input param) is 
 *  little endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]    ANSII destination string.     
 *  pInBuffer       [IN]     UCS2 source string.    
 *  len             [IN]     Length in bytes.  
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_wcs_n_to_asc(S8 *pOutBuffer, U16 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return (U16)app_ucs2_wcs_n_to_asc_str((kal_int8 *)pOutBuffer, (kal_wchar *)pInBuffer, (kal_uint32) len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcslen
 * DESCRIPTION
 *  Gets the number of characters of the given UCS2 encoded string(wide-character), 
 *  not including the final null wide-characters.
 * PARAMETERS          
 *  string    [IN]  UCS2 encoded string(wide-character) which length is to
 *                  be computed.      
 * RETURNS
 *  The number of characters of a wide-character string.
 *****************************************************************************/
S32 mmi_wcslen(const U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)app_ucs2_wcslen((const kal_wchar *)string);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcscmp
 * DESCRIPTION
 *  Compares two UCS2 encoded strings(wide-character) and returns an integer to 
 *  indicate whether the destination string is less than the source string, 
 *  the two are equal, or whether the destination string is greater than the 
 *  source string.
 * PARAMETERS          
 *  str_src   [IN]  UCS2 encoded destination string(wide-character) for 
 *                  left-hand side of comparison.
 *  str_dst   [IN]  UCS2 encoded source string(wide-character) for right-hand 
 *                  side of comparison.       
 * RETURNS
 *  returns <0 if str_src <  str_dst
 *  returns  0 if str_src == str_dst
 *  returns >0 if str_src >  str_dst
 *****************************************************************************/
S32 mmi_wcscmp(const U16 *str_src, const U16 *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return (S32) app_ucs2_wcscmp((const kal_wchar *)str_src, (const kal_wchar *)str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsncmp
 * DESCRIPTION
 *  Compares two UCS2 encoded strings(wide-character) for lexical order. 
 *  The comparison stops after: 
 *  (1) a difference between the strings is found; 
 *  (2) the end of the strings is reached;
 *  (3) count characters have been compared (wide-character strings).
 * PARAMETERS
 *  str_src   [IN]  UCS2 encoded destination string(wide-character) for 
 *                  left-hand side of comparison.
 *  str_dst   [IN]  UCS2 encoded source string(wide-character) for right-hand 
 *                  side of comparison. 
 *  count     [IN]  Number of characters to compare.    
 * RETURNS
 *  returns -1 if str_src <  str_dst
 *  returns  0 if str_src == str_dst
 *  returns +1 if str_src >  str_dst
 *****************************************************************************/
S32 mmi_wcsncmp(const U16 *str_src, const U16 *str_dst, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) app_ucs2_wcsncmp((const kal_wchar *)str_src, 
								  (const kal_wchar *)str_dst, 
                                  (kal_uint32) count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcscpy
 * DESCRIPTION
 *  Copies the UCS2 encoded source string(wide-character) into the destination 
 *  string; Assumes enough space in the destination string.
 * PARAMETERS
 *  str_dst   [OUT]  UCS2 encoded destination string(wide-character) over which 
 *                   the source string is to be copied.
 *  str_src   [IN]   UCS2 encoded source string(wide-character) to be copied 
 *                   over the destination string.
 * RETURNS
 *  A pointer to the destination string.
 *****************************************************************************/
U16 *mmi_wcscpy(U16 *str_dst, const U16 *str_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*)app_ucs2_wcscpy((kal_wchar*)str_dst, (const kal_wchar*)str_src);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsncpy
 * DESCRIPTION
 *  Copies count characters from the source string to the destination string.  
 *  Note:
 *  Unlike ANSI C standard library function wcsncpy. If count is less than the 
 *  length of source, NULL wide-characters also is put onto the end of the 
 *  copied string. But if count is greater than the length of sources, str_dst 
 *  is not padded with null characters to length count (wide-characters).
 * PARAMETERS
 *  str_dst   [OUT]  UCS2 encoded destination string(wide-character) over which 
 *                   the source string is to be copied.
 *  str_src   [IN]   UCS2 encoded source string(wide-character) to be copied 
 *                   over the destination string.
 *  count     [IN]   max number of characters to copy.
 * RETURNS
 *  A pointer to the destination string.
 *****************************************************************************/
U16 *mmi_wcsncpy(U16 *str_dst, const U16 *str_src, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16 *)app_ucs2_wcsncpy((kal_wchar *)str_dst, (const kal_wchar *)str_src, (kal_uint32)count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcscat
 * DESCRIPTION
 *  Concatenates the source string onto the end of the destination string. 
 *  Assumes enough space in the destination string.
 * PARAMETERS
 *  str_dst   [OUT]  UCS2 encoded destination string(wide-character) over which 
 *                   "str_src" is to be copied.      
 *  str_src   [IN]   UCS2 encoded source string(wide-character) to be copied 
 *                   over "str_dst".      
 * RETURNS
 *  A pointer to the destination string.
 *****************************************************************************/
U16 *mmi_wcscat(U16 *str_dst, const U16 *str_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	return  (U16*)app_ucs2_wcscat((kal_wchar*)str_dst, (const kal_wchar*)str_src); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsncat
 * DESCRIPTION
 *  Appends at most count characters of the source string onto the
 *  end of destination string, and ALWAYS terminates with a null character.
 *  If count is greater than the length of source string, the length of source 
 *  string is used instead.  (Like app_ucs2_wcsncpy, this routine does not pad out
 *  to count characters).
 * PARAMETERS
 *  str_dst   [OUT]  UCS2 encoded destination string(wide-character) to be appended.        
 *  str_src   [IN]   UCS2 encoded source string(wide-character) to be appended 
 *                   to the end of destination string.      
 *  count     [IN]   Number of characters to append.       
 * RETURNS
 *  A pointer to the destination string.
 *****************************************************************************/
U16 *mmi_wcsncat(U16 *str_dst, const U16 *str_src, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*)app_ucs2_wcsncat((kal_wchar*)str_dst, (const kal_wchar*)str_src, (kal_uint32) count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsstr
 * DESCRIPTION
 *  Find a substring.
 * PARAMETERS
 *  string        [IN]  UCS2 encoded string(wide-character) to search.       
 *  str_char_set  [IN]  UCS2 encoded string(wide-character) to search for.      
 * RETURNS
 *  Returns a pointer to the first occurrence of str_char_set in string, or 
 *  NULL if str_char_set does not appear in string. If str_char_set points to 
 *  a string of zero length, the function returns string. 
 *****************************************************************************/
U16 *mmi_wcsstr(U16 *string, const U16 *str_char_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*)app_ucs2_wcsstr((const U16*)string, (const U16*)str_char_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcschr
 * DESCRIPTION
 *  Searches a UCS2 encoded string(wide-character) for a given wide-character,
 *  which may be the null character L'\0'.
 * PARAMETERS
 *  string        [IN]  UCS2 encoded string(wide-character) to search in.       
 *  ch            [IN]  UCS2 encoded wide-character to search for.      
 * RETURNS
 *  returns pointer to the first occurrence of ch in string
 *  returns NULL if ch does not occur in string
 *****************************************************************************/
U16 *mmi_wcschr(const U16 *string,  U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*)app_ucs2_wcschr((const kal_wchar*)string,  (kal_uint16)ch);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsrchr
 * DESCRIPTION
 *  Scan a UCS2 encoded string(wide-character) for the last occurrence of a 
 *  character.
 * PARAMETERS
 *  string        [IN]  UCS2 encoded string(wide-character) to search in.       
 *  ch            [IN]  UCS2 encoded wide-character to search for.      
 * RETURNS
 *  returns pointer to the last occurrence of ch in string
 *  returns NULL if ch does not occur in string
 *****************************************************************************/
U16 *mmi_wcsrchr(const U16 * string, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    return (U16*)app_ucs2_wcsrchr((const kal_wchar*)string, (kal_uint16)ch);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcslwr
 * DESCRIPTION
 *  mmi_wcslwr converts upper-case characters in a null-terminated 
 *  UCS2 encoded string(wide-character) to their lower-case equivalents.  
 * PARAMETERS
 *  string    [IN]  UCS2 encoded string(wide-character) to change to lower 
 *                  case.      
 * RETURNS
 *  returns a pointer to the converted string. Because the modification is 
 *  done in place, the pointer returned is the same as the pointer passed 
 *  as the input argument.
 *****************************************************************************/
U16 *mmi_wcslwr(U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     return (U16*)app_ucs2_wcslwr((kal_wchar *)string);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsupr
 * DESCRIPTION
 *  app_ucs2_wcsrchr converts upper-case characters in a null-terminated 
 *  UCS2 encoded string(wide-character) to their upper-case equivalents.  
 * PARAMETERS
 *  string    [IN]  UCS2 encoded string(wide-character) to change to upper 
 *                  case.      
 * RETURNS
 *  returns a pointer to the converted string. Because the modification is 
 *  done in place, the pointer returned is the same as the pointer passed 
 *  as the input argument.
 *****************************************************************************/
U16 *mmi_wcsupr(U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*)app_ucs2_wcsupr((kal_wchar*)string);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsicmp
 * DESCRIPTION
 *  mmi_wcsicmp perform a case-insensitive wchar_t UCS2 encoded 
 *  string(wide-character) comparison. 
 * PARAMETERS
 *  str_src   [IN]  UCS2 encoded destination string(wide-character) for 
 *                  left-hand side of comparison.
 *  str_dst   [IN]  UCS2 encoded source string(wide-character) for right-hand 
 *                  side of comparison.       
 * RETURNS
 *  returns <0 if str_src <  str_dst
 *  returns  0 if str_src == str_dst
 *  returns >0 if str_src >  str_dst
 *****************************************************************************/
S32 mmi_wcsicmp(const U16 *str_src, const U16 *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)app_ucs2_wcsicmp((const kal_wchar*)str_src, (const kal_wchar*)str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wcsnicmp
 * DESCRIPTION
 *  Compares two UCS2 encoded strings(wide-character) for lexical order 
 *  without regard to case. 
 *  The comparison stops after: 
 *  (1) a difference between the strings is found; 
 *  (2) the end of the strings is reached;
 *  (3) count characters have been compared (wide-character strings).
 * PARAMETERS
 *  str_src   [IN]  UCS2 encoded destination string(wide-character) for 
 *                  left-hand side of comparison.
 *  str_dst   [IN]  UCS2 encoded source string(wide-character) for right-hand 
 *                  side of comparison. 
 *  count     [IN]  Number of characters to compare.    
 * RETURNS
 *  returns -1 if str_src <  str_dst
 *  returns  0 if str_src == str_dst
 *  returns +1 if str_src >  str_dst
 *****************************************************************************/
S32 mmi_wcsnicmp(const U16 *str_src, const U16 *str_dst, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return (S32)app_ucs2_wcsnicmp((const kal_wchar*)str_src, 
		                          (const kal_wchar*)str_dst, 
                                  (kal_uint32) count);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucs2str
 * DESCRIPTION
 *  Finds the first occurrence of string2 in string1
 * PARAMETERS
 *  str1        [IN]  string to search in.       
 *  str2        [IN]  string to search for.      
 * RETURNS
 *  returns a pointer to the first occurrence of string2 in
 *  string1, or NULL if string2 does not occur in string1
 *****************************************************************************/
S8 *mmi_ucs2str(const S8 *str1, const S8 *str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cp = (S8 *) str1;
    S8 *s1, *s2;
    
    if (!(*str2 || *(str2+1)))
    {    
        return((S8 *)str1);
    }
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*cp || *(cp+1))
    {
        s1 = cp;
        s2 = (S8 *) str2;
        
        while ((*s1 || *(s1+1)) 
               && (*s2 || *(s2+1)) 
               && !((*s1-*s2) || (*(s1+1)-*(s2+1))))
        {
            s1 += 2;
            s2 += 2;
        }
        
        if (!(*s2 || *(s2+1)))
        {
            return(cp);
        }
        
        cp += 2;
    }
    
    return NULL;    
}


/*****************************************************************************
 * FUNCTION
 *  app_asc_str_to_ucs2_wcs_ex
 * DESCRIPTION
 *  The function is used for convert ANSII string to UCS2 string. The caller
 *  need to make sure the dest size must have enough space or the function
 *  causes the memory corruption. The function will add the terminated character
 *  at the end of dest array. The byte order of UCS2 character(output param)
 *  is little endian.
 * PARAMETERS
 *  dest            [OUT]  UCS2 destination string.   
 *  src             [IN]   ANSII source string.
 *  src_end_pos     [OUT]  The point to the end of converted sub-string at the input string.
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_asc_to_wcs_ex(U16 *dest, S8 *src, U32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return app_asc_str_to_ucs2_wcs_ex((kal_wchar *)dest, (kal_int8 *)src, (kal_uint32 *)src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  app_asc_str_n_to_ucs2_wcs_ex
 * DESCRIPTION
 *  The function is used for convert the characters of ANSII string to UCS2
 *  string. The caller need to make sure the dest size must have enough space 
 *  or the function causes the memory corruption. The function will add the 
 *  terminated character at the end of dest array. The byte order of UCS2 
 *  character(output param) is little endian.
 * PARAMETERS
 *  dest            [OUT]  UCS2 destination string.   
 *  src             [IN]   ANSII source string.
 *  len             [IN]   Size in bytes 
 *  src_end_pos     [OUT]  The point to the end of converted sub-string at the input string.
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
U16 mmi_asc_n_to_wcs_ex(U16 *dest, S8 *src, U32 len, U32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    return app_asc_str_n_to_ucs2_wcs_ex((kal_wchar *)dest, (kal_int8 *)src, (kal_uint32)len, (kal_uint32 *)src_end_pos);
}


