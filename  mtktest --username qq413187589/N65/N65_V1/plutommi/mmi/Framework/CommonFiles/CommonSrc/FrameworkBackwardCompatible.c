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
* FrameworkBackwardCompatible.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends for framework backward compatible elements.
*
* Author:
* -------
*  Xiaodong Wang (mbj06019)
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "FrameworkGprot.h"
#include "Unicodexdcl.h"

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_STRING
/*****************************************************************************
 * FUNCTION
 *  AnsiiToUnicodeString
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
U16 AnsiiToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer)
{
    return mmi_asc_to_ucs2(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiNToUnicodeString
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
U16 AnsiiNToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    return mmi_asc_n_to_ucs2(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  UnicodeToAnsii
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
U16 UnicodeToAnsii(S8 *pOutBuffer, S8 *pInBuffer)
{
    return mmi_ucs2_to_asc(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  UnicodeNToAnsii
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
U16 UnicodeNToAnsii(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    return mmi_ucs2_n_to_asc(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  UnicodeToUCS2Encoding
 * DESCRIPTION
 *  convert unicode to UCS2 encoding
 * PARAMETERS
 *  unicode         [IN]        Value to be encoded
 *  charLength      [OUT]         
 *  arrOut          [OUT]         
 * RETURNS
 *  U8 -> Status
 *****************************************************************************/
U8 UnicodeToUCS2Encoding(U16 unicode, U8 *charLength, U8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U8)mmi_wc_to_ucs2(
                unicode, 
                charLength,
                arrOut);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2EncodingToUnicode
 * DESCRIPTION
 *  convert UCS2 encoded scheme to unicode
 * PARAMETERS
 *  pUnicode        [IN]       	array containing  UCS2 encoded characters
 *  arr             [IN]        unicode equivalent
 * RETURNS
 *  U8 -> Status
 *****************************************************************************/
U8 UCS2EncodingToUnicode(PU16 pUnicode, PU8 arr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (U8)mmi_ucs2_to_wc(pUnicode, arr);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strlen
 * DESCRIPTION
 *  Gives the length of UCS2 encoded string
 * PARAMETERS
 *  arrOut      [IN]        array containing  UCS2 encoded characters
 * RETURNS
 *  U16 -> Status
 *****************************************************************************/
S32 UCS2Strlen(const S8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S32)mmi_ucs2strlen(arrOut);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strcmp
 * DESCRIPTION
 *  compares two strings
 * PARAMETERS
 *  string1     [IN]        > first String
 *  string2     [OUT]       > Second String
 * RETURNS
 *  
 *****************************************************************************/
S32 UCS2Strcmp(const S8 *string1, const S8 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return (S32)mmi_ucs2cmp(string1, string2);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strcpy
 * DESCRIPTION
 *  copies the one UCS2 encoded string to other
 * PARAMETERS
 *  strDestination      [OUT]       StrDest-> Destination array
 *  strSource           [IN]        
 * RETURNS
 *  PS8 -> pointer to destination string or NULL
 *****************************************************************************/
S8 *UCS2Strcpy(S8 *strDestination, const S8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return mmi_ucs2cpy(strDestination, strSource);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strncmp
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
S32 UCS2Strncmp(const S8 *string1, const S8 *string2, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return mmi_ucs2ncmp(
				string1,
				string2,
				size);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strncpy
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
S8 *UCS2Strncpy(S8 *strDestination, const S8 *strSource, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return mmi_ucs2ncpy(
				strDestination,
				strSource,
				size);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strcat
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
S8 *UCS2Strcat(S8 *strDestination, const S8 *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return mmi_ucs2cat(strDestination, strSource);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strncat
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
S8 *UCS2Strncat(S8 *strDestination, const S8 *strSource, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On the Target */
    return mmi_ucs2ncat(
                    strDestination, 
                    strSource,
                    size);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strstr
 * DESCRIPTION
 *  Finds the first occurrence of string2 in string1
 * PARAMETERS
 *  str1        [IN]  string to search in.       
 *  str2        [IN]  string to search for.      
 * RETURNS
 *  returns a pointer to the first occurrence of string2 in
 *  string1, or NULL if string2 does not occur in string1
 *****************************************************************************/
S8 *UCS2Strstr(const S8 *str1, const S8 *str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucs2str(str1, str2);    
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strchr
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
S8 *UCS2Strchr(const S8 *strSrc, U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucs2chr(strSrc, c);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strrchr
 * DESCRIPTION
 *  Scan a UCS2 encoded string for the last occurrence of a character.
 * PARAMETERS
 *  string        [IN]  UCS2 encoded string to search in.       
 *  ch            [IN]  UCS2 encoded wide-character to search for.      
 * RETURNS
 *  returns pointer to the last occurrence of ch in string
 *  returns NULL if ch does not occur in string
 *****************************************************************************/
S8 *UCS2Strrchr(const S8 * string, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucs2rchr(string, ch);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strupr
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
S8 *UCS2Strupr(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucs2upr(string);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strlwr
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
S8 *UCS2Strlwr(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucs2lwr(string);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Stricmp
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
S32 UCS2Stricmp(const S8 *str_src, const S8 *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucs2icmp(str_src, str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Strnicmp
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
S32 UCS2Strnicmp(const S8 *str_src, const S8 *str_dst, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return mmi_ucs2nicmp(str_src, 
						str_dst, 
                        count);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2StrTrimLeft
 * DESCRIPTION
 *  skip over the TrimChars
 * PARAMETERS
 *  strSrc          [IN]        
 *  TrimChars       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *UCS2StrTrimLeft(const S8 *strSrc, const S8 *TrimChars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_ucs2trim_left(strSrc, TrimChars);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2StrGetStr
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
S32 UCS2StrGetStr(const S8 *strSrc, const S8 *break_chars, S32 *read_length, S16 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_ucs2find(strSrc, break_chars, read_length, direction);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2StrGetNumInt
 * DESCRIPTION
 *  to parse over a int number, including positive and negative signs (+,-).
 * PARAMETERS
 *  strSrc          [IN]        
 *  out_num         [?]         Is the parsed int number
 *  read_length     [?]         
 * RETURNS
 *  1: parse successfully ; -1: parse number fail.
 *****************************************************************************/
S32 UCS2StrGetNumInt(const S8 *strSrc, S32 *out_num, S32 *read_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_ucs2toi(strSrc, out_num, read_length);
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiToUnicodeString_Ex
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
U16 AnsiiToUnicodeString_Ex(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return mmi_asc_to_ucs2_ex(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiNToUnicodeString_Ex
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
U16 AnsiiNToUnicodeString_Ex(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_asc_n_to_ucs2_ex(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiCharToUnicodeWideChar
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
U16 AnsiiCharToUnicodeWideChar(U16 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    return mmi_asc_to_wcs(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiCharToUnicodeWideCharEx
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
U16 AnsiiCharToUnicodeWideCharEx(U16 *dest, S8 *src, U32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return mmi_asc_to_wcs_ex(dest, src, src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiCharNToUnicodeWideChar
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
U16 AnsiiCharNToUnicodeWideChar(U16 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_asc_n_to_wcs(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiCharNToUnicodeWideCharEx
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
U16 AnsiiCharNToUnicodeWideCharEx(U16 *dest, S8 *src, U32 len, U32 *src_end_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    return mmi_asc_n_to_wcs_ex(dest, src, len, src_end_pos);
}


/*****************************************************************************
 * FUNCTION
 *  UnicodeWideCharToAnsiiChar
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
U16 UnicodeWideCharToAnsiiChar(S8 *pOutBuffer, U16 *pInBuffer)
{
   	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    return mmi_wcs_to_asc(pOutBuffer, pInBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  UnicodeWidecharNToAnsii
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
U16 UnicodeWidecharNToAnsii(S8 *pOutBuffer, U16 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return mmi_wcs_n_to_asc(pOutBuffer, pInBuffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcslen
 * DESCRIPTION
 *  Gets the number of characters of the given UCS2 encoded string(wide-character), 
 *  not including the final null wide-characters.
 * PARAMETERS          
 *  string    [IN]  UCS2 encoded string(wide-character) which length is to
 *                  be computed.      
 * RETURNS
 *  The number of characters of a wide-character string.
 *****************************************************************************/
S32 UCS2Wcslen(const U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcslen(string);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcscmp
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
S32 UCS2Wcscmp(const U16 *str_src, const U16 *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return mmi_wcscmp(str_src, str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsncmp
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
S32 UCS2Wcsncmp(const U16 *str_src, const U16 *str_dst, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcsncmp(str_src, 
					   str_dst, 
                       count);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcscpy
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
U16 *UCS2Wcscpy(U16 *str_dst, const U16 *str_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcscpy(str_dst, str_src);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsncpy
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
U16 *UCS2Wcsncpy(U16 *str_dst, const U16 *str_src, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcsncpy(str_dst, str_src, count);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcscat
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
U16 *UCS2Wcscat(U16 *str_dst, const U16 *str_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	return mmi_wcscat(str_dst, str_src); 
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsncat
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
U16 *UCS2Wcsncat(U16 *str_dst, const U16 *str_src, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcsncat(str_dst, str_src, count);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsstr
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
U16 *UCS2Wcsstr(U16 *string, const U16 *str_char_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcsstr(string, str_char_set);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcschr
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
U16 *UCS2Wcschr(const U16 *string,  U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcschr(string, ch);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsrchr
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
U16 *UCS2Wcsrchr(const U16 * string, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    return mmi_wcsrchr(string, ch);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcslwr
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
U16 *UCS2Wcslwr(U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     return mmi_wcslwr(string);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsupr
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
U16 *UCS2Wcsupr(U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcsupr(string);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsicmp
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
S32 UCS2Wcsicmp(const U16 *str_src, const U16 *str_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcsicmp(str_src, str_dst);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2Wcsnicmp
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
S32 UCS2Wcsnicmp(const U16 *str_src, const U16 *str_dst, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return mmi_wcsnicmp(str_src, 
		                str_dst, 
                        count);    
}

#endif /* MMI_FRM_BACKWARD_COMPATIBLE_STRING */

