/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc.(C) 2005
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
 *    app_str.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   string related utility 
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

#include "kal_non_specific_general_types.h"
#include "app_str.h"

#include <string.h> 
#include <ctype.h>

#define ENCODING_LENGTH       2


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_tolower
 * DESCRIPTION
 *  Convert character to lowercase.
 * PARAMETERS
 *  c     [IN]    Character to convert. 
 * RETURNS
 *  return the point to the converted character.
 *****************************************************************************/
kal_int8* app_ucs2_tolower(kal_int8 *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar wc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    wc = *(c+1)<<8|(kal_uint8)(*c);

    wc = app_ucs2_towlower(wc);

    *(c+1) = (kal_int8)(wc>>8);
    *(c)   = (kal_int8)(wc);

    return c;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_toupper
 * DESCRIPTION
 *  Convert character to uppercase.
 * PARAMETERS
 *  c     [IN]     Character to convert. 
 * RETURNS
 *  return the point to the converted character.
 *****************************************************************************/
kal_int8* app_ucs2_toupper(kal_int8 *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar wc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    wc = *(c+1)<<8|(kal_uint8)(*c);

    wc = app_ucs2_towupper(wc);

    *(c+1) = (kal_int8)(wc>>8);
    *(c)   = (kal_int8)(wc);

    return c;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strlen
 * DESCRIPTION
 *  The function is used for query UCS2 string length in character not in bytes.
  * PARAMETERS
 *  arrOut    [IN]  UCS2 string     
 * RETURNS
 *  Return UCS2 string length in character not in bytes
 *****************************************************************************/
kal_int32 app_ucs2_strlen(const kal_int8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 nCount = 0;
    kal_int32 nLength = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check for NULL character only at the odd no. of bytes 
       assuming forst byte start from zero */
    if (arrOut)
    {
        while (arrOut[nCount] != 0 || arrOut[nCount + 1] != 0)
        {
            ++nLength;
            nCount += 2;
        }
    }
    return nLength; /* One is added to count 0th byte */
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strcmp
 * DESCRIPTION
 *  The function is used for compare UCS2 strings. 
 * PARAMETERS
 *  string1     [IN]   UCS2 string1
 *  string2     [IN]   UCS2 string2
 * RETURNS
 *  <0 - string1 less than string2
 *   0 - string1 identical to string2
 *  >0 - string1 greater than string2
 *****************************************************************************/
kal_int32 app_ucs2_strcmp(const kal_int8 *string1, const kal_int8 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*string1 == *string2) && (*(string1 + 1) == *(string2 + 1)))
    {

        if ((*string1 == 0) && (*(string1 + 1) == 0))
        {
            return 0;
        }

        string1 += 2;
        string2 += 2;

    }   /* End of while */

    /* The return value indicates the lexicographic relation of string1 to string2 */
    /* ie  < 0 , > 0 and 0 */
    if (*string1 == *string2 && *(string1 + 1) != *(string2 + 1))
    {
        return (*(string1 + 1) - *(string2 + 1));
    }
    else
    {
        return (*string1 - *string2);

    }

}

/*****************************************************************************
 * FUNCTION
 *  app_ucs2_unconditional_strcmp
 * DESCRIPTION
 *  compares two strings no conditional about uppercase and lowercase. 
 * PARAMETERS
 *  string1     [IN]        > first String
 *  string2     [IN]        > Second String
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 app_ucs2_unconditional_strcmp(const kal_int8 *string1, const kal_int8 *string2)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*string1 == *string2) || 
           ((*string1 + 0x20) == *string2) || 
           (*string1 == (*string2 + 0x20)) && 
		   (*(string1 + 1) == *(string2 + 1)))
    {

        if ((*string1 == 0) && (*(string1 + 1) == 0))
        {
            return 0;
        }

        string1 += 2;
        string2 += 2;

    }   /* End of while */

    /* The return value indicates the lexicographic relation of string1 to string2 */
    /* ie  < 0 , > 0 and 0 */
    if (*string1 == *string2 && *(string1 + 1) != *(string2 + 1))
    {
        return (*(string1 + 1) - *(string2 + 1));
    }
    else
    {
        return (*string1 - *string2);

    }
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strcpy
 * DESCRIPTION
 *  The function is used for copy UCS2 string. 
 * PARAMETERS
 *  strDestination  [OUT]   UCS2 destination string
 *  strSource       [IN]    UCS2 source string
 * RETURNS
 *  Return the destination string.
 *****************************************************************************/
kal_int8 *app_ucs2_strcpy(kal_int8 *strDestination, const kal_int8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_wchar count = 1;
    kal_int8 *temp = strDestination;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strSource == NULL)
    {
        if (strDestination)
        {
            *(strDestination + count - 1) = '\0';
            *(strDestination + count) = '\0';
        }
        return temp;

    }

    if (strDestination == NULL || strSource == NULL)
    {
        return NULL;
    }
    while (!((*(strSource + count) == 0) && (*(strSource + count - 1) == 0)))
    {

        *(strDestination + count - 1) = *(strSource + count - 1);
        *(strDestination + count) = *(strSource + count);
        count += 2;
    }

    *(strDestination + count - 1) = '\0';
    *(strDestination + count) = '\0';

    return temp;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strncmp
 * DESCRIPTION
 *  The function is used for compare UCS2 characters of two strings. Size is 
 *  the character number not the byte numbers.
 * PARAMETERS
 *  string1     [IN]  UCS2 string1
 *  string2     [IN]  UCS2 string2
 *  size        [IN]  Number in character (not byte)      
 * RETURNS
 *  <0 - string1 substring less than string2 substring
 *   0 - string1 substring identical to string2 substring
 *  >0 - string1 substring greater than string2 substring
 *****************************************************************************/
/* MTK Added by Tim for solve a potential wrong answer when string1 and string2 are the same and less than "size" */
kal_int32 app_ucs2_strncmp(const kal_int8 *string1, const kal_int8 *string2, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 count = 0;
    kal_wchar nStr1;
    kal_wchar nStr2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = size << 1;   /* User is passing no of charcters not bytes */

    while (count < size)
    {
        nStr1 = (string1[1] << 8) | (kal_uint8)string1[0];
        nStr2 = (string2[1] << 8) | (kal_uint8)string2[0];
        if (nStr1 == 0 || nStr2 == 0 || nStr1 != nStr2)
        {
            return nStr1 - nStr2;
        }
        string1 += 2;
        string2 += 2;
        count += 2;
    }
    return 0;
}

/* End MTK: Tim */


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strncpy
 * DESCRIPTION
 *  The function is used for copy UCS2 characters of one string to another.
 *  If size is less than the length of strSource, a null character is still 
 *  appended automatically to strDestination. If size is greater than the 
 *  length of strSource, strDestination is padding with null characters up 
 *  to length size. The function behavior is a little bit different from strncpy.
 * PARAMETERS
 *  strDestination  [OUT]  UCS2 destination string
 *  strSource       [IN]   UCS2 source string
 *  size            [IN]   Size in character (not byte)
 * RETURNS
 *  Return the destination string.
 *****************************************************************************/
kal_int8 *app_ucs2_strncpy(kal_int8 *strDestination, const kal_int8 *strSource, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_wchar count = 1;
    kal_uint32 count1 = 0;
    kal_int8 *temp = strDestination;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = size * 2;

    /* MMI_ASSERT(!(strDestination == NULL)); */

    while (!((*(strSource + count) == 0) && (*(strSource + count - 1) == 0)) && (count1 < size))
    {

        *(strDestination + count - 1) = *(strSource + count - 1);
        *(strDestination + count) = *(strSource + count);
        count += 2;
        count1 += 2;
    }

    *(strDestination + count - 1) = '\0';
    *(strDestination + count) = '\0';

    return temp;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strcat
 * DESCRIPTION
 *  The function is used for append strSource to strDestination and terminate
 *  the resulting string with a null character. 
 * PARAMETERS
 *  strDestination   [OUT]  UCS2 destination string       
 *  strSource        [IN]   UCS2 source string     
 * RETURNS
 *  Return the destination string
 *****************************************************************************/
kal_int8 *app_ucs2_strcat(kal_int8 *strDestination, const kal_int8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int8 *dest = strDestination;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest = dest + app_ucs2_strlen(strDestination) * ENCODING_LENGTH;

    app_ucs2_strcpy(dest, strSource);
    return strDestination;

}




/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strstr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a       [IN]        
 *  p       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_wchar *app_ucs2_strstr(const kal_wchar *a, const kal_wchar *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, m, n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL || a == NULL)
    {
        return NULL;
    }

    m = app_ucs2_wcslen(a);
    n = app_ucs2_wcslen(p);

    for (i = 0; i < m; i++)
    {
        int i_tmp = i;
        int j = 0;

        while (*(a + i) == *(p + j))
        {
            i++;
            j++;

            if (j == n)
            {
                return (kal_wchar*) (a + i_tmp);
            }
            else if (i >= m)
            {
                return NULL;
            }
        }
        i = i_tmp;
    }
    return NULL;
}



/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strchr
 * DESCRIPTION
 *  Searches a UCS2 encoded string for a given wide-character,
 *  which may be the null character L'\0'.
 * PARAMETERS
 *  string        [IN]  UCS2 encoded string to search in.       
 *  ch            [IN]  UCS2 encoded wide-character to search for.      
 * RETURNS
 *  returns pointer to the first occurrence of ch in string
 *  returns NULL if ch does not occur in string
 *****************************************************************************/
kal_int8 *app_ucs2_strchr(const kal_int8 *string,  kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *chr = (kal_int8*) string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if ((*(chr+1)<<8|(kal_uint8)(*chr)) == ch)
        {
            return chr;
        }
        chr += 2;
    } while (*chr || *(chr+1));

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strrchr
 * DESCRIPTION
 *  Scan a UCS2 encoded string for the last occurrence of a character.
 * PARAMETERS
 *  string        [IN]  UCS2 encoded string to search in.       
 *  ch            [IN]  UCS2 encoded wide-character to search for.      
 * RETURNS
 *  returns pointer to the last occurrence of ch in string
 *  returns NULL if ch does not occur in string
 *****************************************************************************/
kal_int8 *app_ucs2_strrchr(const kal_int8 * string, kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *cursor = (kal_int8 *)string;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    while (*cursor || *(cursor+1))              /* find end of string */
    {
        cursor += 2;
    }
    
    /* search towards front */
    while ((kal_int8 *)string != cursor && 
           (*(cursor+1)<<8|(kal_uint8)(*cursor)) != ch)
    {
        cursor -= 2;
    }
    
    if ((*(cursor+1)<<8|(kal_uint8)(*cursor)) == ch)          /* found ?*/
    {
        return cursor;
    }
    
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strupr
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
kal_int8 *app_ucs2_strupr(kal_int8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *cursor;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor=(kal_int8*)string;

    while(*cursor || *(cursor+1))
    {
        app_ucs2_toupper(cursor);        
        cursor += 2;
    }
    
    return string;
}

/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strlwr
 * DESCRIPTION
 *  app_ucs2_strlwr converts lower-case characters in a null-terminated 
 *  UCS2 encoded string their lower-case equivalents.  
 * PARAMETERS
 *  string    [IN]  UCS2 encoded string to change to upper case.      
 * RETURNS
 *  returns a pointer to the converted string. Because the modification is 
 *  done in place, the pointer returned is the same as the pointer passed 
 *  as the input argument.
 *****************************************************************************/
kal_int8 *app_ucs2_strlwr(kal_int8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *cursor;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor=(kal_int8*)string;

    while(*cursor || *(cursor+1))
    {
        app_ucs2_tolower(cursor); 
        cursor += 2;
    }
    
    return string;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_stricmp
 * DESCRIPTION
 *  app_ucs2_stricmp perform a case-insensitive UCS2 encoded string
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
kal_int32 app_ucs2_stricmp(const kal_int8 *str_src, const kal_int8 *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *src = (kal_int8 *)str_src;
    kal_int8 *dst = (kal_int8 *)str_dst;
    kal_wchar first = 0;
    kal_wchar last = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        first = app_ucs2_towlower((kal_wchar)(*(src+1)<<8|(kal_uint8)(*src))); 
        last =  app_ucs2_towlower((kal_wchar)(*(dst+1)<<8|(kal_uint8)(*dst))); 
        src += 2;
        dst += 2;
    } while ( first && (first == last) );
    
    
    return (kal_int32)(first - last);
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strnicmp
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
kal_int32 app_ucs2_strnicmp(const kal_int8 *str_src, 
                            const kal_int8 *str_dst, 
                            kal_uint32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *src = (kal_int8 *)str_src;
    kal_int8 *dst = (kal_int8 *)str_dst;
    kal_wchar first = 0;
    kal_wchar last = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count) 
    {
        do {
            first = app_ucs2_towlower((kal_wchar)(*(src+1)<<8|(kal_uint8)(*src))); 
            last =  app_ucs2_towlower((kal_wchar)(*(dst+1)<<8|(kal_uint8)(*dst))); 
            src += 2;
            dst += 2;
        } while ( (--count) && first && (first == last) );
    }
    
    return (kal_int32)(first - last);
}




/*****************************************************************************
 * FUNCTION
 *  app_ucs2_towlower
 * DESCRIPTION
 *  Convert character to lowercase.
 * PARAMETERS
 *  wc      [IN]  Character to convert.
 * RETURNS
 *  Each of these routines converts a copy of wc, if possible, and returns the 
 *  result.
 ****************************************************************************/
kal_wchar app_ucs2_towlower(kal_wchar wc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Latin Basic        0x0000 ~ 0x007F */
    /* Latin-1            0x0080 ~ 0x00FF */
    /* Latin extend-A     0x0100 ~ 0x017F */
    /* Latin extend-B     0x0180 ~ 0x024F */
    /* Greek              0x0370 ~ 0x03FF */
    /* Cyrillic           0x0400 ~ 0x04FF */
    
    if ((wc >= 0x0041 && wc <= 0x005A) || /* Latin basic */
        (wc >= 0x00C0 && wc <= 0x00D6) || (wc >= 0x00D8 && wc <= 0x00DE) || /* Latin-1 */
        (wc >= 0x0410 && wc <= 0x042F) || /* Cyrillic */
        (wc >= 0x0391 && wc <= 0x03A1) || (wc >= 0x03A3 && wc <= 0x03AA)) /* Greek */
    {
        return (wc + 0x0020);
    }
    else if (wc == 0x0102 || /* Latin extend-A */
             wc == 0x01A0 || wc == 0x01AF || wc == 0x0187 || wc == 0x018B ||  /* Latin extend-B */
             wc == 0x0191 || wc == 0x01AB || wc == 0x01B8 || wc == 0x01F2) /* Latin extend-B */
    {
        return (wc + 0x0001);
    }
    else if (wc >= 0x0400 && wc <= 0x040F) /* Cyrillic */
    {
        return (wc + 0x50);
    }
    else if (wc == 0x0490) /* Cyrillic */
    {
        return 0x0491;
    }
    else if (wc >= 0x0100 && wc <= 0x0137 || wc >= 0x014A && wc <= 0x0177 || /* Latin extend-A */
             wc >= 0x0182 && wc <= 0x0185 || wc >= 0x0198 && wc <= 0x01A5 || /* Latin extend-B */
             wc >= 0x01DE && wc <= 0x01EF || wc >= 0x01F8 && wc <= 0x01FF || /* Latin extend-B */
             wc >= 0x0222 && wc <= 0x0233) /* Latin extend-B */ 
    {
        if ((wc & 0x0001) == 0) /* odd is small case */
            return wc + 1;
        else
            return wc;
    }
    else if (wc >= 0x0139 && wc <= 0x0148 ||  /* Latin extend-A */
             wc >= 0x0179 && wc <= 0x017E ||wc >= 0x01B3 && wc <= 0x01B6 ||  /* Latin extend-B */
             wc >= 0x01CD && wc <= 0x01DC) /* Latin extend-B*/
    {
        if ((wc & 0x0001) == 1) /* even is small case */
            return wc + 1;
        else
            return wc;
    }
    else
    {
        return wc;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_towupper
 * DESCRIPTION
 *  Convert character to uppercase.
 * PARAMETERS
 *  wc      [IN]  Character to convert.
 * RETURNS
 *  Each of these routines converts a copy of wc, if possible, and returns the 
 *  result.
 *****************************************************************************/
kal_wchar app_ucs2_towupper(kal_wchar wc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Latin Basic        0x0000 ~ 0x007F */
    /* Latin-1            0x0080 ~ 0x00FF */
    /* Latin extend-A     0x0100 ~ 0x017F */
    /* Latin extend-B     0x0180 ~ 0x024F */
    /* Greek              0x0370 ~ 0x03FF */
    /* Cyrillic           0x0400 ~ 0x04FF */
    
    if ((wc >= 0x0061 && wc <= 0x007A) || /* Latin basic */
        (wc >= 0x00E0 && wc <= 0x00F6) || (wc >= 0x00F8 && wc <= 0x00FE) || /* Latin-1 */
        (wc >= 0x0430 && wc <= 0x044F) || /* Cyrillic */
        (wc >= 0x03B1 && wc <= 0x03C1) || (wc >= 0x03C3 && wc <= 0x03CA)) /* Greek */
    {
        return (wc - 0x0020);
    }
    else if (wc == 0x0103 || /* Latin extend-A */
             wc == 0x01A1 || wc == 0x01B0 || wc == 0x0188 || wc == 0x018C ||  /* Latin extend-B */
             wc == 0x0192 || wc == 0x01AC || wc == 0x01B9 || wc == 0x01F3) /* Latin extend-B */
    {
        return (wc - 0x0001);
    }
    else if (wc >= 0x0450 && wc <= 0x045f) /* Cyrillic */
    {
        return (wc - 0x50);
    }
    else if (wc == 0x0491) /* Cyrillic */
    {
        return 0x0490;
    }
    else if (wc >= 0x0100 && wc <= 0x0137 ||wc >= 0x014A && wc <= 0x0177 || /* Latin extend-A */
             wc >= 0x0182 && wc <= 0x0185 ||wc >= 0x0198 && wc <= 0x01A5 || /* Latin extend-B */
             wc >= 0x01DE && wc <= 0x01EF ||wc >= 0x01F8 && wc <= 0x01FF || /* Latin extend-B */
             wc >= 0x0222 && wc <= 0x0233) /* Latin extend-B */ 
    {
        if ((wc & 1) == 1) /* odd is small case */
            return wc - 1;
        else
            return wc;
    }
    else if (wc >= 0x0139 && wc <= 0x0148 || /* Latin extend-A */
             wc >= 0x0179 && wc <= 0x017E || wc >= 0x01B3 && wc <= 0x01B6 ||  /* Latin extend-B */
             wc >= 0x01CD && wc <= 0x01DC) /* Latin extend-B*/
    {
        if ((wc & 1) == 0) /* even is small case */
            return wc - 1;
        else
            return wc;
    }
    else
    {
        return wc;
    }    
    
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcslen
 * DESCRIPTION
 *  Gets the number of characters of the given UCS2 encoded string(wide-character), 
 *  not including the final null wide-characters.
 * PARAMETERS          
 *  string    [IN]  UCS2 encoded string(wide-character) which length is to
 *                  be computed.      
 * RETURNS
 *  The number of characters of a wide-character string.
 *****************************************************************************/
kal_int32 app_ucs2_wcslen(const kal_wchar *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_wchar *str_tmp = string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(*str_tmp)
    {
        ++str_tmp;
    }
    
    return (kal_int32) (str_tmp - string);
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcscmp
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
kal_int32 app_ucs2_wcscmp(const kal_wchar *str_src, const kal_wchar *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while((*str_src == *str_dst) && *str_src)
    {
        ++str_src, ++str_dst;        
    }      

    return (kal_int32)(*str_src - *str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsncmp
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
 *  returns <0 if str_src <  str_dst
 *  returns  0 if str_src == str_dst
 *  returns >0 if str_src >  str_dst
 *****************************************************************************/
kal_int32 app_ucs2_wcsncmp(const kal_wchar *str_src, 
                           const kal_wchar *str_dst, 
                           kal_uint32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!count)
    {
        return 0;
    }    

    while ((--count) && (*str_src) && (*str_src == *str_dst))
    {
        ++str_src,++str_dst;        
    }   

    return (kal_int32)(*str_src - *str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcscpy
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
kal_wchar *app_ucs2_wcscpy(kal_wchar *str_dst, const kal_wchar *str_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *str_tmp = str_dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *str_tmp = *str_src;
    
    while(*str_src)
    {
        *(++str_tmp) = *(++str_src); /* Copy str_src over str_dst */
    }
    
    return str_dst;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsncpy
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
kal_wchar *app_ucs2_wcsncpy(kal_wchar *str_dst, const kal_wchar *str_src, kal_uint32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *str_tmp = str_dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count && *str_src)
    {    
        *str_tmp = *str_src; /* copy string */
        ++str_tmp, ++str_src;
        --count;
    }    
    
    *str_tmp = L'\0';   
    
    return str_dst;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcscat
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
kal_wchar *app_ucs2_wcscat(kal_wchar *str_dst, const kal_wchar *str_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *str_tmp = str_dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	while(*str_tmp)
    {
        ++str_tmp;            /* find end of str_dst */
    }
    
    while(*str_src)
    {
        *str_tmp= *str_src;   /* Copy str_src to end of str_dst */
        ++str_tmp, ++str_src;
    }

    *str_tmp = L'\0';

    return  str_dst;          /* return str_dst */
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsncat
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
kal_wchar *app_ucs2_wcsncat(kal_wchar *str_dst, const kal_wchar *str_src, kal_uint32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *str_tmp = str_dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(*str_tmp)
    {
        ++str_tmp;               /* find end of str_dst */
    }

    while (count && *str_src)
    {    
        *str_tmp = *str_src;     /* copy string */
        ++str_tmp, ++str_src;
        --count;
    }

    *str_tmp = L'\0';
    
    return str_dst;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsstr
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
kal_wchar *app_ucs2_wcsstr(const kal_wchar *string, const kal_wchar *str_char_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *str_tmp = (kal_wchar *) string;
    kal_wchar *cursor1, *cursor2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*str_tmp)
    {
        cursor1 = str_tmp;
        cursor2 = (kal_wchar *) str_char_set;

        while ((*cursor1)&&(*cursor2)&&!(*cursor1 - *cursor2))
        {
            cursor1++, cursor2++;
        }

        if (!*cursor2)
        {
            return str_tmp;
        }

        ++str_tmp;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcschr
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
kal_wchar *app_ucs2_wcschr(const kal_wchar *string,  kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*string && *string != ch)
    {
        ++string;
    }
    
    if (*string == ch)
    {
        return (kal_wchar *)string;
    }
    
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsrchr
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
kal_wchar *app_ucs2_wcsrchr(const kal_wchar * string, kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *start = (kal_wchar *)string;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    while (*string)                /* find end of string */
    {
        ++string;
    }
    
    /* search towards front */
    while (string != start && *string != ch)
    {
        --string;
    }
    
    if (*string == ch)             /* found ? */
    {
        return (kal_wchar *)string;
    }
    
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcslwr
 * DESCRIPTION
 *  app_ucs2_wcsrchr converts upper-case characters in a null-terminated 
 *  UCS2 encoded string(wide-character) to their lower-case equivalents.  
 * PARAMETERS
 *  string    [IN]  UCS2 encoded string(wide-character) to change to lower 
 *                  case.      
 * RETURNS
 *  returns a pointer to the converted string. Because the modification is 
 *  done in place, the pointer returned is the same as the pointer passed 
 *  as the input argument.
 *****************************************************************************/
kal_wchar *app_ucs2_wcslwr(kal_wchar *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *cursor;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (cursor=string; *cursor; ++cursor)
    {
        *cursor = app_ucs2_towlower(*cursor);        
    }
    return string;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsupr
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
kal_wchar *app_ucs2_wcsupr(kal_wchar *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *cursor;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (cursor=string; *cursor; cursor++)
    {
        *cursor = app_ucs2_towupper(*cursor); 
    }
    
    return string;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsicmp
 * DESCRIPTION
 *  app_ucs2_wcsicmp perform a case-insensitive UCS2 encoded string
 *  (wide-character) comparison. 
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
kal_int32 app_ucs2_wcsicmp(const kal_wchar *str_src, const kal_wchar *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar first, last;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        first = app_ucs2_towupper(*str_dst);
        last = app_ucs2_towupper(*str_src);
        str_dst++;
        str_src++;
    } while (first && (first == last));
    
    return (kal_int32)(first - last);
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcsnicmp
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
kal_int32 app_ucs2_wcsnicmp(const kal_wchar *str_src, 
                            const kal_wchar *str_dst, 
                            kal_uint32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar first = 0;
    kal_wchar last = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count) 
    {
        do {
            first = app_ucs2_towupper(*str_dst);
            last = app_ucs2_towupper(*str_src);
            str_dst++;
            str_src++;
        } while ( (--count) && first && (first == last) );
    }
    
    return (kal_int32)(first - last);
}


/*****************************************************************************
 * FUNCTION
 *  app_asc_str_to_ucs2_str
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
kal_uint16 app_asc_str_to_ucs2_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int16 count = -1;
    kal_uint8 charLen = 0;
    kal_uint8 arrOut[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pInBuffer != '\0')
    {

        app_unicode_to_ucs2encoding((kal_wchar) (*((kal_uint8 *)pInBuffer)), &charLen, arrOut);

        // #ifdef MMI_ON_WIN32
        pOutBuffer[++count] = arrOut[0];
        pOutBuffer[++count] = arrOut[1];
        pInBuffer++;
        // #endif

    #ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
        pOutBuffer[++count] = arrOut[1];    /* arrOut[0]; */
        pOutBuffer[++count] = arrOut[0];    /* arrOut[1]; */
        pInBuffer++;
    #endif /* __FOR_TESTING */ 

    }

    pOutBuffer[++count] = '\0';
    pOutBuffer[++count] = '\0';
    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  app_asc_str_n_to_ucs2_str
 * DESCRIPTION
 *  The function is used for convert the characters of ANSII string to UCS2
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(output param) is
 *  little endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]   UCS2 destination string.      
 *  pInBuffer       [IN]    ANSII source string     
 *  len             [IN]    Length in bytes   
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_asc_str_n_to_ucs2_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int16 count = -1;
    kal_uint8 charLen = 0;
    kal_uint8 arrOut[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len)
    {

        app_unicode_to_ucs2encoding((kal_wchar) (*((kal_uint8 *)pInBuffer)), &charLen, arrOut);

        // #ifdef MMI_ON_WIN32
        pOutBuffer[++count] = arrOut[0];
        pOutBuffer[++count] = arrOut[1];
        pInBuffer++;
        // #endif

    #ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
        pOutBuffer[++count] = arrOut[1];    /* arrOut[0]; */
        pOutBuffer[++count] = arrOut[0];    /* arrOut[1]; */
        pInBuffer++;
    #endif /* __FOR_TESTING */ 

        len--;

    }

    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  app_asc_str_to_ucs2_str_ex
 * DESCRIPTION
 *  The function is used for convert ANSII string to UCS2 string. The caller
 *  need to make sure the pOutBuffer  size must have enough space or the function
 *  causes the memory corruption. The function will add the terminated character
 *  at the end of pOutBuffer array. The byte order of UCS2 character(output param)
 *  is little endian.
 *  Unlike app_asc_str_to_ucs2_str, it will ignore the controls in ANSII string.
 * PARAMETERS
 *  pOutBuffer      [OUT]  UCS2 destination string   
 *  pInBuffer       [IN]   ANSII source string  
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_asc_str_to_ucs2_str_ex(kal_int8 *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int16 count = -1;
    kal_uint8 charLen = 0;
    kal_uint8 arrOut[2];

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

        app_unicode_to_ucs2encoding((kal_wchar) (*((kal_uint8 *)pInBuffer)), &charLen, arrOut);
        
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
 *  app_asc_str_n_to_ucs2_str_ex
 * DESCRIPTION
 *  The function is used for convert the characters of ANSII string to UCS2
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(output param) is
 *  little endian.
 *  Unlike app_asc_str_n_to_ucs2_str, it will ignore the controls in ANSII string.
 * PARAMETERS
 *  pOutBuffer      [OUT]   UCS2 destination string.      
 *  pInBuffer       [IN]    ANSII source string     
 *  len             [IN]    Length in bytes   
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_asc_str_n_to_ucs2_str_ex(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int16 count = -1;
    kal_uint8 charLen = 0;
    kal_uint8 arrOut[2];

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

        app_unicode_to_ucs2encoding((kal_wchar) (*((kal_uint8 *)pInBuffer)), &charLen, arrOut);

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
 *  app_ucs2_str_to_asc_str
 * DESCRIPTION
 *  The function is used for convert UCS2 string to ANSII string. 
 *  The caller need to make sure the pOutBuffer  size must have enough space 
 *  or the function causes the memory corruption. The function will add the 
 *  terminated character at the end of pOutBuffer array. The byte order of 
 *  UCS2 character(input param) is little endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]   ANSII destination string  
 *  pInBuffer       [IN]    UCS2 source string 
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_ucs2_str_to_asc_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*pInBuffer == 0) && (*(pInBuffer + 1) == 0)))
    {
        *pOutBuffer = *(pInBuffer);

    #ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
        *pOutBuffer = *(pInBuffer + 1);
    #endif 
        pInBuffer += 2;
        pOutBuffer++;
        count++;
    }

    *pOutBuffer = 0;
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  app_asc_str_to_ucs2_wcs
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
kal_uint16 app_asc_str_to_ucs2_wcs(kal_wchar *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *start = pOutBuffer;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pInBuffer)
    {
        *(pOutBuffer++) =  (kal_wchar)(*(pInBuffer++));
    }

    *pOutBuffer = L'\0';
    
    return (kal_uint16)(pOutBuffer - start);
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
kal_uint16 app_asc_str_to_ucs2_wcs_ex(kal_wchar *dest, kal_int8 *src, kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *start = dest;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*src)
    {
        *(dest++) =  (kal_wchar)(*(src++));
    }

    *dest = L'\0';

    *src_end_pos = (kal_uint32)src;
    
    return (kal_uint16)(dest - start);
}


/*****************************************************************************
 * FUNCTION
 *  app_asc_str_n_to_ucs2_wcs
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
kal_uint16 app_asc_str_n_to_ucs2_wcs(kal_wchar *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *start = pOutBuffer;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*pInBuffer) && (len))
    {
        *(pOutBuffer++) =  (kal_wchar)(*(pInBuffer++));
		--len;
    }

    *pOutBuffer = L'\0';
    
    return (kal_uint16)(pOutBuffer - start);
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
kal_uint16 app_asc_str_n_to_ucs2_wcs_ex(kal_wchar *dest, kal_int8 *src, kal_uint32 len, kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *start = dest;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*src) && (len))
    {
        *(dest++) =  (kal_wchar)(*(src++));
        --len;
    }

    *dest = L'\0';

    *src_end_pos = (kal_uint32)src;
    
    return (kal_uint16)(dest - start);
}


/*****************************************************************************
 * FUNCTION
 *  app_widechar_unicode_to_ansii
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
kal_uint16 app_ucs2_wcs_to_asc_str(kal_int8 *pOutBuffer, kal_wchar *pInBuffer)
{
   	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *start = pOutBuffer;    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pInBuffer)
    {
        *(pOutBuffer++) =  (kal_int8)(*(pInBuffer++));
    }
	
    *pOutBuffer = '\0';
    
    return (kal_uint16)(pOutBuffer - start);
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_wcs_n_to_asc_str
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
kal_uint16 app_ucs2_wcs_n_to_asc_str(kal_int8 *pOutBuffer, kal_wchar *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *start = pOutBuffer;    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*pInBuffer) && (len))
    {
        *(pOutBuffer++) =  (kal_int8)(*(pInBuffer++));
		len -= 2;
    }
	
    *pOutBuffer = '\0';
    
    return (kal_uint16)(pOutBuffer - start);
}



/*****************************************************************************
 * FUNCTION
 *  app_ucs2_str_n_to_asc_str
 * DESCRIPTION
 *  The function is used for convert the characters of UCS2 string to ANSII
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(input param) is l
 *  ittle endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]    ANSII destination string.     
 *  pInBuffer       [IN]     UCS2 source string.    
 *  len             [IN]     Length in bytes.  
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_ucs2_str_n_to_asc_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((len) && (!((*pInBuffer == 0) && (*(pInBuffer + 1) == 0))))
    {
        *pOutBuffer = *(pInBuffer);

    #ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
        *pOutBuffer = *(pInBuffer + 1);
    #endif 
        pInBuffer += 2;
        pOutBuffer++;
        count++;
        len -= 2;
    }

    return count;
}



/*****************************************************************************
 * FUNCTION
 *  app_unicode_to_ucs2encoding
 * DESCRIPTION
 *  convert unicode to UCS2 encoding
 * PARAMETERS
 *  unicode         [IN]        Value to be encoded
 *  charLength      [OUT]         
 *  arrOut          [OUT]         
 *  array           [OUT]       Of kal_uint8
 * RETURNS
 *  kal_uint8 -> Status
 *****************************************************************************/
kal_uint8 app_unicode_to_ucs2encoding(kal_wchar unicode, kal_uint8 *charLength, kal_uint8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 status = 1;
    kal_uint8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (arrOut != 0)
    {

        if (unicode < 256)
        {
            arrOut[index++] = *((kal_uint8*) (&unicode));
            arrOut[index] = 0;

        }
        else
        {
            arrOut[index++] = *((kal_uint8*) (&unicode));
            arrOut[index] = *(((kal_uint8*) (&unicode)) + 1);

        }
        *charLength = 2;
    }
    else
    {

        status = 0;
    }

#ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
    if (arrOut != 0)
    {

        if (unicode < 256)
        {
            arrOut[index++] = 0;    /* *((kal_uint8*)(&unicode)); */
            arrOut[index] = *((kal_uint8*) (&unicode));

        }
        else
        {
            arrOut[index++] = *(((kal_uint8*) (&unicode)) + 1);        /* *((kal_uint8*)(&unicode)); */
            arrOut[index] = *((kal_uint8*) (&unicode)); /* *(((kal_uint8*)(&unicode)) + 1); */

        }
        *charLength = 2;
    }
    else
    {

        status = 0;
    }
#endif /* __FOR_TESTING */ 

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2encoding_to_unicode
 * DESCRIPTION
 *  convert UCS2 encoded scheme to unicode
 * PARAMETERS
 *  pUnicode        [OUT]       Equivalent  
 *  arr             [IN]        array containing  UCS2 encoded characters
 * RETURNS
 *  kal_uint8 -> Status
 *****************************************************************************/
kal_uint8 app_ucs2encoding_to_unicode(kal_wchar *pUnicode, kal_uint8 *arr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 index = 0;
    kal_uint8 status = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((arr != NULL) && (pUnicode != NULL))
    {

        *((kal_uint8*) (pUnicode)) = arr[index++];
        *(((kal_uint8*) (pUnicode)) + 1) = arr[index];
    }
    else
    {

        status = 0;
    }

#ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
    if ((arr != NULL) && (pUnicode != NULL))
    {

        *((kal_uint8*) (pUnicode)) = arr[index];            /* arr[index++]; */
        *(((kal_uint8*) (pUnicode)) + 1) = arr[index++];    /* arr[index]; */
    }
    else
    {

        status = 0;
    }
#endif /* __FOR_TESTING */ 
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strtolower
 * DESCRIPTION
 *  Convert a string to all-lower-case string
 * PARAMETERS
 *  s          [IN/OUT]   UCS2 encoded string      
 * RETURNS
 *  return pointer to the character string passed in.
 *****************************************************************************/
kal_wchar *app_ucs2_strtolower(kal_wchar *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return app_ucs2_wcslwr(s);    
}


/*****************************************************************************
 * FUNCTION
 *  app_unicode_to_utf8_len
 * DESCRIPTION
 *  Calculate the byte number that convert Unicode encode to UTF8 encode
 * PARAMETERS
 *  ucs2            [IN]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 app_unicode_to_utf8_len(kal_wchar ucs2)
{
	if (ucs2 < (kal_wchar) 0x80)
		return 1;
	else if (ucs2 < (kal_wchar) 0x800)
		return 2;
	else
		return 3;
}



/*****************************************************************************
 * FUNCTION
 *  app_stricmp
 * DESCRIPTION
 *  Case-insensitive string comparison.
 *  app_stricmp() compares string s to string t case-insensitively;
 * PARAMETERS
 *  s            [IN]         
 *  t            [IN]         
 * RETURNS
 *  return <0 if s<t, 0 if s==t, or >0 if s>t
 *****************************************************************************/
kal_int32 app_stricmp(kal_char *s, kal_char *t)
{
    for ( ; tolower(*s) == tolower(*t); s++, t++)
        if (*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}


/*****************************************************************************
 * FUNCTION
 *  app_strnicmp
 * DESCRIPTION
 *  Case-insensitive string comparison for up to n characters.
 * PARAMETERS
 *  s            [IN]         
 *  t            [IN]         
 *  n            [IN]    number of compared characters
 * RETURNS
 *  return <0 if s<t, 0 if s==t, or >0 if s>t.
 *****************************************************************************/
kal_int32 app_strnicmp(kal_char *s, kal_char *t, int n)
{
    if (n < 0)
        return n;

    for ( ; --n >= 0 && tolower(*s) == tolower(*t); s++, t++)
        if (*s == '\0')
            return 0;

    if (n < 0)
        return 0;
    else
        return tolower(*s) - tolower(*t);
}


/*****************************************************************************
 * FUNCTION
 *  app_strtolower
 * DESCRIPTION
 *  Convert a string to all-lower-case string
 * PARAMETERS
 *  s            [IN/OUT]         
 * RETURNS
 *  return pointer to the character string passed in.
 *****************************************************************************/
kal_char *app_strtolower(kal_char *s)
{
    kal_char *orig = s;

    for ( ; *s != '\0'; s++)
        *s = tolower(*s);
    return orig;
}


/*****************************************************************************
 * FUNCTION
 *  app_log2
 * DESCRIPTION
 *  Find the log base 2 of an integer. The log base 2 of an integer is
 *  the same as the position of the highest bit set.
 * PARAMETERS
 *  i            [IN]
 * RETURNS
 *  the log base 2 of an integer
 *****************************************************************************/
kal_int32 app_log2(kal_uint32 i)
{
    int r = 0;

    while (i >>= 1)
        r++;
    return r;

}


/*****************************************************************************
 * FUNCTION
 *  app_log10
 * DESCRIPTION
 *  Find the log base 10 of an integer.
 *  log10(i) = log2(i) / log2(10) = log2(i) * (1/log2(10)
 *  ~= log2(v) * 1233/4096 = log2(v) * 1233 >> 12
 *  Adding one is needed because the log2() rounds down.
 *  Finally, since the value t is only an approximation, that may be off
 *  by one, hte exact value is found by substracting the vlaue of
 *  v < power_of_10[t].
 *  
 * PARAMETERS
 *  i            [IN]
 * RETURNS
 *  the log base 10 of an integer
 *****************************************************************************/
kal_int32 app_log10(kal_uint32 i)
{
    kal_int32 t;
    kal_uint32 power_of_10[] = {
        1, 10, 100, 1000, 10000, 100000,
        1000000, 10000000, 100000000, 1000000000};

    t = (app_log2(i) + 1) * 1233 >> 12;
    return (t - (i < power_of_10[t]));
}


/*****************************************************************************
 * FUNCTION
 *  app_digits
 * DESCRIPTION
 *  return the digits in decimal format of an unsigned integer
 * PARAMETERS
 *  i            [IN] 
 * RETURNS
 *  the digits of a unsigned integer in decimal format.
 *****************************************************************************/
kal_int32 app_intdigits(kal_uint32 i)
{
    return app_log10(i) + 1;
}


/*****************************************************************************
 * FUNCTION
 *  app_ucs2_strncat
 * DESCRIPTION
 *  The function is used for append the first size characters of strSource 
 *  to strDestination and terminate the resulting string with a null character. 
 * PARAMETERS
 *  strDestination      [OUT]   UCS2 destination string      
 *  strSource           [IN]    UCS2 source string    
 *  size                [IN]    Size in character (not byte)    
 * RETURNS
 *  Return the destination string
 *****************************************************************************/
kal_int8 *app_ucs2_strncat(kal_int8 *strDestination, const kal_int8 *strSource, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int8 *dest = strDestination;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest = dest + app_ucs2_strlen(strDestination) * ENCODING_LENGTH;

    app_ucs2_strncpy(dest, strSource, size);
    return strDestination;

}

#if defined(APP_STRING_API_BACKWARD_COMPATIBLE)
/*****************************************************************************
 * FUNCTION
 *  app_ansii_to_unicodestring
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
kal_uint16 app_ansii_to_unicodestring(kal_int8 *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_asc_str_to_ucs2_str(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  app_ansii_to_unicodestring_ex
 * DESCRIPTION
 *  The function is used for convert ANSII string to UCS2 string. The caller
 *  need to make sure the pOutBuffer  size must have enough space or the function
 *  causes the memory corruption. The function will add the terminated character
 *  at the end of pOutBuffer array. The byte order of UCS2 character(output param)
 *  is little endian.
 *  Unlike app_asc_str_to_ucs2_str, it will ignore the controls in ANSII string.
 * PARAMETERS
 *  pOutBuffer      [OUT]  UCS2 destination string   
 *  pInBuffer       [IN]   ANSII source string  
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_ansii_to_unicodestring_ex(kal_int8 *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_asc_str_to_ucs2_str_ex(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  app_ansii_n_to_unicodestring
 * DESCRIPTION
 *  The function is used for convert the characters of ANSII string to UCS2
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(output param) is
 *  little endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]   UCS2 destination string.      
 *  pInBuffer       [IN]    ANSII source string     
 *  len             [IN]    Length in bytes   
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_ansii_n_to_unicodestring(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_asc_str_n_to_ucs2_str(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  app_ansii_n_to_unicodestring_ex
 * DESCRIPTION
 *  The function is used for convert the characters of ANSII string to UCS2
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(output param) is
 *  little endian.
 *  Unlike app_asc_str_n_to_ucs2_str, it will ignore the controls in ANSII string.
 * PARAMETERS
 *  pOutBuffer      [OUT]   UCS2 destination string.      
 *  pInBuffer       [IN]    ANSII source string     
 *  len             [IN]    Length in bytes   
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_ansii_n_to_unicodestring_ex(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_asc_str_n_to_ucs2_str_ex(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  app_unicode_to_ansii
 * DESCRIPTION
 *  The function is used for convert UCS2 string to ANSII string. 
 *  The caller need to make sure the pOutBuffer  size must have enough space 
 *  or the function causes the memory corruption. The function will add the 
 *  terminated character at the end of pOutBuffer array. The byte order of 
 *  UCS2 character(input param) is little endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]   ANSII destination string  
 *  pInBuffer       [IN]    UCS2 source string 
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_unicode_to_ansii(kal_int8 *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_ucs2_str_to_asc_str(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  app_unicode_n_to_ansii
 * DESCRIPTION
 *  The function is used for convert the characters of UCS2 string to ANSII
 *  string. The caller need to make sure the pOutBuffer size is greater than 
 *  len and the function doesn't add the terminated character at the end of 
 *  the pOutBuffer array. The byte order of UCS2 character(input param) is l
 *  ittle endian.
 * PARAMETERS
 *  pOutBuffer      [OUT]    ANSII destination string.     
 *  pInBuffer       [IN]     UCS2 source string.    
 *  len             [IN]     Length in bytes.  
 * RETURNS
 *  Return the bytes to convert.
 *****************************************************************************/
kal_uint16 app_unicode_n_to_ansii(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_ucs2_str_n_to_asc_str(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  app_widechar_ansii_to_unicode
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
kal_uint16 app_widechar_ansii_to_unicode(kal_wchar *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_asc_str_to_ucs2_wcs(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  app_widechar_ansii_to_unicode_ex
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
kal_uint16 app_widechar_ansii_to_unicode_ex(kal_wchar *dest, kal_int8 *src, kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return app_asc_str_to_ucs2_wcs_ex(dest, src, src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  app_widechar_ansii_n_to_unicode
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
kal_uint16 app_widechar_ansii_n_to_unicode(kal_wchar *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return app_asc_str_n_to_ucs2_wcs(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  app_widechar_ansii_n_to_unicode_ex
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
kal_uint16 app_widechar_ansii_n_to_unicode_ex(kal_wchar *dest, kal_int8 *src, kal_uint32 len, kal_uint32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_asc_str_n_to_ucs2_wcs_ex(dest, src, len, src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  app_widechar_unicode_to_ansii
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
kal_uint16 app_widechar_unicode_to_ansii(kal_int8 *pOutBuffer, kal_wchar *pInBuffer)
{
   	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return app_ucs2_wcs_to_asc_str(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  app_widechar_unicode_n_to_ansii
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
kal_uint16 app_widechar_unicode_n_to_ansii(kal_int8 *pOutBuffer, kal_wchar *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return app_ucs2_wcs_n_to_asc_str(pOutBuffer, pInBuffer, len);
}
#endif /* defined(APP_STRING_API_BACKWARD_COMPATIBLE) */
