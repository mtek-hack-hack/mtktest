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
 *  GSM7BitDefaultAlphabet.c
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
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : GSM7BitDefaultAlphabet.c

   PURPOSE     : Converts GSM 7-bit Default alphabet to ascii and
               Ascii to GSM 7-bit Default alphabet

   REMARKS     : .

   AUTHOR      : .

   DATE     : 11-07-03

**************************************************************/

#include "MMI_include.h"
#include "GSM7BitDefaultAlphabet.h"

/* micha1018 */

#ifndef GSM_7BIT_DEFAULT_ALPHABET_DEBUG
#undef PRINT_INFORMATION
#define PRINT_INFORMATION(args) NULL
#endif /* GSM_7BIT_DEFAULT_ALPHABET_DEBUG */ 

#define SWAP_SHORT(Var)  *Var = *(short*)         SwapEndian((void*)Var, sizeof(short))
#define SWAP_USHORT(Var) *Var = *(unsigned short*)SwapEndian((void*)Var, sizeof(short))
#define SWAP_LONG(Var)   *Var = *(long*)          SwapEndian((void*)Var, sizeof(long))
#define SWAP_ULONG(Var)  *Var = *(unsigned long*) SwapEndian((void*)Var, sizeof(long))
#define SWAP_FLOAT(Var)  *Var = *(float*)         SwapEndian((void*)Var, sizeof(float))
#define SWAP_DOUBLE(Var) *Var = *(double*)        SwapEndian((void*)Var, sizeof(double))

#define UI_GET_NEXT_BYTE(p,c)          \
{  c=(*p);                             \
   p+=1;                               \
}

#define UI_GET_PREVIOUS_BYTE(p,c)         \
{  p-=1;                                  \
   c=(*p);                                \
}

#define UI_INSERT_BYTE(p,c)               \
{  (*((p))++)=(U8)(c);                    \
}

#define UI_SWAP_U16_BYTES(c) (c)=((c)>>8)|((c)<<8)

#define _EURO_CHARACTER_UCS2     (0x20AC)
#define _EURO_CHARACTER          (0xA2)
#define _ESCAPE_CHARACTER        (27)
#define _SPACE_CHARACTER         (32)

extern const U8 AsciiToDefaultArray[];
extern const U8 ExtendedAsciiToDefaultArray[];
extern const U8 DefaultToExtendedAsciiArray[];
extern const U8 DefaultToAsciiArray[];


const U8 DefaultToAsciiArray[128] = 
{
    64, 163, 36, 165, 232, 233, 249, 236, 242, 199,
    10, 216, 248, 13, 197, 229, 16, 95, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 198, 230,
    223, 200, 32, 33, 34, 35, 164, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 161, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 196, 214, 209, 220, 167, 191, 97, 98, 99,
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 228, 246, 241, 252, 224
};

const U8 DefaultToExtendedAsciiArray[128] = 
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    32, 0, 0, 0, 0, 0, 0, 0, 0, 0,  /* Page Break at 10=32 Change Later */
    94, 0, 0, 0, 0, 0, 0, 32, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    123, 125, 0, 0, 0, 0, 0, 92, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    91, 126, 93, 0, 124, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 162, 0, 0, 0, 0, 0, 0, 0, 0, /* Euro character at 101 changed to 162 */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

const U8 AsciiToDefaultArray[] = 
{
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    10, 32, 32, 13, 32, 32, 16, 32, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 32, 32,
    32, 32, 32, 33, 34, 35, 2, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 0, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 32, 32, 32, 32, 17, 32, 97, 98, 99,
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 64, 32, 1, 36, 3, 32, 95, 32, 32,
    32, 32, 32, 64, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 96, 32, 32, 32, 32, 91, 14, 28, 9,
    31, 32, 32, 32, 32, 32, 32, 32, 32, 93,
    32, 32, 32, 32, 92, 32, 11, 32, 32, 32,
    94, 32, 32, 30, 127, 32, 32, 32, 123, 15,
    29, 32, 4, 5, 32, 32, 7, 32, 32, 32,
    32, 125, 8, 32, 32, 32, 124, 32, 12, 6,
    32, 32, 126, 32, 32, 32
};

const U8 ExtendedAsciiToDefaultArray[] = 
{
    0, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 27, 32, 32,
    32, 32, 10, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 60, 47, 62, 20, 32, 32, 32, 32, 32,
    32, 101, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 40, 64, 41, 61, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 101, 32, 32, 32, 32, 32, 32, 32,    /* Changed character at 162 to 101 (old value was 32) */
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32
};


/*****************************************************************************
 * FUNCTION
 *  ConvertGSM7BitDefaultEncodingToAscii
 * DESCRIPTION
 *  Converts 7 bit encoding to 8 bit Ascii
 * PARAMETERS
 *  message     [IN]        Output Buffer
 *  msg         [IN]        Input Buffer
 *  length      [IN]        No of bytes to be converted
 *  outLen      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void ConvertGSM7BitDefaultEncodingToAscii(U8 *message, U8 *msg, U16 length, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < length; i++)
    {
        if (msg[i] != 27)   /* escape char ? */
        {
            /* if(msg[i]!=13)       //CR ? */
            message[j++] = DefaultToAsciiArray[msg[i]];
        }
        else
        {
            /* treat escape char as a space */
            message[j++] = 32;
        }
    }
    if (outLen != NULL)
    {
        *outLen = j;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GSM7BitMapDefaultToASCIIByte
 * DESCRIPTION
 *  Converts 7 bit encoding to 8 bit Ascii
 * PARAMETERS
 *  input       [IN]        (GSM 7 bit encoded value)
 *  none(?)     [OUT]       
 * RETURNS
 *  U8 (ASCII value)
 *****************************************************************************/
U8 GSM7BitMapDefaultToASCIIByte(U8 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input == 27)
    {
        return 32;  /* return space for "Escape" */
    }
    if (input == 13)
    {
        return 13;  /* Returning same value, but UI should skip CR */
    }
    return DefaultToAsciiArray[input];  /* use the table for the rest */
}


/*****************************************************************************
 * FUNCTION
 *  GSM7BitMapASCIIToDefaultByte
 * DESCRIPTION
 *  Converts  8 bit Ascii to 7 bit encoding
 * PARAMETERS
 *  input       [IN]        (ASCII value)
 *  none(?)     [OUT]       
 * RETURNS
 *  U8 (GSM 7 bit encoded value)
 *****************************************************************************/
U8 GSM7BitMapASCIIToDefaultByte(U8 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return AsciiToDefaultArray[input];
}


/*****************************************************************************
 * FUNCTION
 *  ConvertAsciiEncodingToGSM7BitDefault
 * DESCRIPTION
 *  Converts  8 bit Ascii to 7 bit encoding
 * PARAMETERS
 *  message     [IN]        Output Buffer
 *  msg         [IN]        Input Buffer
 *  length      [IN]        No of bytes to be converted
 *  outLen      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void ConvertAsciiEncodingToGSM7BitDefault(U8 *message, U8 *msg, U16 length, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = 0; i < length; i++, j++)
    {
        message[j] = AsciiToDefaultArray[msg[i]];
    }
    if (outLen != NULL)
    {
        *outLen = j;
    }
}

#ifndef OSL_MEMORY_DUMP


/*****************************************************************************
 * FUNCTION
 *  CovertStringForSIM
 * DESCRIPTION
 *  Converts data from Platfrorm (ASCII or UCS2) format to one specified
 * PARAMETERS
 *  data            [IN]        Pointer to dat to be converted
 *  len             [IN]        No of bytes to be converted
 *  format          [IN]        Format to which data is to be converted 7 bit. 8 bit or UCS2
 *  outLen          [?]         
 *  outlen(?)       [OUT]       Pointer in which output length will be returned
 * RETURNS
 *  Pointer to data containing converted data
 *****************************************************************************/
U8 *CovertStringForSIM(U8 *data, U16 len, U8 format, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convertedData = NULL;
    U16 outLength;
    U16 *tempData;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > 0)
    {
        switch (format)
        {
            case MMI_DEFAULT_DCS:
                {
                    U8 *tempData;

                    convertedData = OslMalloc((len) + 1);
                    tempData = OslMalloc(len);
                    mmi_ucs2_n_to_asc((PS8) tempData, (PS8) data, len);
                    ConvertAsciiEncodingToGSM7BitDefault(
                        convertedData,
                        tempData,
                        (U16) (len / ENCODING_LENGTH),
                        &outLength);
                    OslMfree(tempData);
                    convertedData[outLength] = 0;
                    if (outLen != NULL)
                    {
                        *outLen = outLength + 1;
                    }
                }
                break;

            case MMI_8BIT_DCS:
                convertedData = OslMalloc((len / ENCODING_LENGTH) + 1);
                mmi_ucs2_n_to_asc((PS8) convertedData, (PS8) data, len);
                memset((void*)&convertedData[len / ENCODING_LENGTH], 0, 1);
                if (outLen != NULL)
                {
                    *outLen = len / ENCODING_LENGTH + 1;
                }
                break;

            case MMI_UCS2_DCS:
                convertedData = OslMalloc((len) + ENCODING_LENGTH);
                memcpy(convertedData, data, len);
                memset((void*)&convertedData[len], 0, ENCODING_LENGTH);
                if (outLen != NULL)
                {
                    *outLen = len + ENCODING_LENGTH;
                }
                tempData = (U16*) convertedData;
                for (i = 0; i < len * 2 / ENCODING_LENGTH; i += 2)
                {
                    SWAP_USHORT(tempData);
                    tempData++;
                }
                break;
        }

        return convertedData;
    }
    else
    {
        U8 noOfNulls;

        if (format == MMI_UCS2_DCS)
        {
            noOfNulls = 2;
        }
        else
        {
            noOfNulls = 1;
        }
        convertedData = OslMalloc(noOfNulls);
        memset((void*)convertedData, 0, noOfNulls);
        if (outLen != NULL)
        {
            *outLen = noOfNulls;
        }
        return convertedData;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CovertStringForPlatform
 * DESCRIPTION
 *  Converts data from specified format to Platform type (UCS2 or ASCII)
 * PARAMETERS
 *  data            [IN]        Pointer to data to be converted
 *  len             [IN]        No of bytes to be converted
 *  format          [IN]        Format of input data
 *  outLen          [?]         
 *  outlen(?)       [OUT]       Pointer in which output length will be returned
 * RETURNS
 *  Pointer to data containing converted data
 *****************************************************************************/
U8 *CovertStringForPlatform(U8 *data, U16 len, U8 format, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convertedData = NULL;
    U16 *tempData;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > 0)
    {
        switch (format)
        {
            case (MMI_DEFAULT_DCS):
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* 0 */

                convertedData = OslMalloc((len * ENCODING_LENGTH) + ENCODING_LENGTH);
                InputboxConvertGSMToDeviceEncoding(data, convertedData, len, (len * ENCODING_LENGTH) + ENCODING_LENGTH, MMI_DEFAULT_DCS, 0, 1);
                *outLen = mmi_ucs2strlen((PS8) convertedData) * ENCODING_LENGTH + ENCODING_LENGTH;

                break;

            case (MMI_8BIT_DCS):
                convertedData = OslMalloc((len * ENCODING_LENGTH) + ENCODING_LENGTH);
                mmi_asc_n_to_ucs2((PS8) convertedData, (PS8) data, len);
                memset((void*)&convertedData[len * ENCODING_LENGTH], 0, ENCODING_LENGTH);
                if (outLen != NULL)
                {
                    *outLen = len * ENCODING_LENGTH + ENCODING_LENGTH;
                }
                break;

            case (MMI_UCS2_DCS):
                convertedData = OslMalloc(len + 1 + ENCODING_LENGTH);   /* prevent odd len number */
                memset((void*)convertedData, 0, len + 1 + ENCODING_LENGTH);
                memcpy(convertedData, data, len);
                if (outLen != NULL)
                {
                    *outLen = len + ENCODING_LENGTH;
                }
                tempData = (U16*) convertedData;
                for (i = 0; i < len; i += 2)
                {
                    SWAP_USHORT(tempData);
                    tempData++;
                }
                break;

                /* micha1008 begin */
            case (MMI_UCS2_81):
                convertedData = OslMalloc((len + 1) * 2 + ENCODING_LENGTH);     /* prevent odd len number */
                memset((void*)convertedData, 0, (len + 1) * 2 + ENCODING_LENGTH);

                InputboxConvertGSMToDeviceEncoding(
                    data,
                    convertedData,
                    (U8) len,
                    (len + 1) * 2 + ENCODING_LENGTH,
                    MMI_UCS2_81,
                    0,
                    1);
                break;

            case (MMI_UCS2_82):
                convertedData = OslMalloc((len + 1) * 2 + ENCODING_LENGTH);     /* prevent odd len number */
                memset((void*)convertedData, 0, (len + 1) * 2 + ENCODING_LENGTH);

                InputboxConvertGSMToDeviceEncoding(
                    data,
                    convertedData,
                    (U8) len,
                    (len + 1) * 2 + ENCODING_LENGTH,
                    MMI_UCS2_82,
                    0,
                    1);
                break;
                /* micha1008 end */

        }
        return convertedData;
    }
    else
    {
        convertedData = OslMalloc(ENCODING_LENGTH);
        memset((void*)convertedData, 0, ENCODING_LENGTH);
        if (outLen != NULL)
        {
            *outLen = ENCODING_LENGTH;
        }
        return convertedData;
    }
}
#else /* OSL_MEMORY_DUMP */ 


/*****************************************************************************
 * FUNCTION
 *  CovertStringForSIMInt
 * DESCRIPTION
 *  Converts data from Platfrorm (ASCII or UCS2) format to one specified
 * PARAMETERS
 *  data            [IN]        Pointer to dat to be converted
 *  len             [IN]        No of bytes to be converted
 *  format          [IN]        Format to which data is to be converted 7 bit. 8 bit or UCS2
 *  outLen          [?]         
 *  fileName        [?]         
 *  lineNumber      [IN]        
 *  outlen(?)       [OUT]       Pointer in which output length will be returned
 * RETURNS
 *  Pointer to data containing converted data
 *****************************************************************************/
U8 *CovertStringForSIMInt(U8 *data, U16 len, U8 format, U16 *outLen, S8 *fileName, S32 lineNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convertedData;
    U16 outLength;
    U16 *tempData;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > 0)
    {
        switch (format)
        {
            case MMI_DEFAULT_DCS:
                {
                    U8 *tempData;

                    convertedData = OslMallocCHK((len) + 1, fileName, lineNumber);
                    tempData = OslMallocCHK(len, fileName, lineNumber);
                    mmi_ucs2_n_to_asc((PS8) tempData, (PS8) data, len);
                    ConvertAsciiEncodingToGSM7BitDefault(
                        convertedData,
                        tempData,
                        (U16) (len / ENCODING_LENGTH),
                        &outLength);
                    OslMfree(tempData);
                    convertedData[outLength] = 0;
                    if (outLen != NULL)
                    {
                        *outLen = outLength + 1;
                    }
                }
                break;

            case MMI_8BIT_DCS:
                convertedData = OslMallocCHK((len / ENCODING_LENGTH) + 1, fileName, lineNumber);
                mmi_ucs2_n_to_asc((PS8) convertedData, (PS8) data, len);
                memset((void*)&convertedData[len / ENCODING_LENGTH], 0, 1);
                if (outLen != NULL)
                {
                    *outLen = len / ENCODING_LENGTH + 1;
                }
                break;

            case MMI_UCS2_DCS:
                convertedData = OslMallocCHK((len) + ENCODING_LENGTH, fileName, lineNumber);
                memcpy(convertedData, data, len);
                memset((void*)&convertedData[len], 0, ENCODING_LENGTH);
                if (outLen != NULL)
                {
                    *outLen = len + ENCODING_LENGTH;
                }
                tempData = (U16*) convertedData;
                for (i = 0; i < len * 2 / ENCODING_LENGTH; i += 2)
                {
                    SWAP_USHORT(tempData);
                    tempData++;
                }
                break;
        }

        return convertedData;
    }
    else
    {
        U8 noOfNulls;

        if (format == MMI_UCS2_DCS)
        {
            noOfNulls = 2;
        }
        else
        {
            noOfNulls = 1;
        }
        convertedData = OslMallocCHK(noOfNulls, fileName, lineNumber);
        memset((void*)convertedData, 0, noOfNulls);
        if (outLen != NULL)
        {
            *outLen = noOfNulls;
        }
        return convertedData;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CovertStringForPlatformInt
 * DESCRIPTION
 *  Converts data from specified format to Platform type (UCS2 or ASCII)
 * PARAMETERS
 *  data            [IN]        Pointer to data to be converted
 *  len             [IN]        No of bytes to be converted
 *  format          [IN]        Format of input data
 *  outLen          [?]         
 *  fileName        [?]         
 *  lineNumber      [IN]        
 *  outlen(?)       [OUT]       Pointer in which output length will be returned
 * RETURNS
 *  Pointer to data containing converted data
 *****************************************************************************/
U8 *CovertStringForPlatformInt(U8 *data, U16 len, U8 format, U16 *outLen, S8 *fileName, S32 lineNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convertedData;
    U16 outLength;
    U16 *tempData;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > 0)
    {
        switch (format)
        {
            case (MMI_DEFAULT_DCS):
                {
                    U8 *tempData;
    
                    convertedData = OslMallocCHK((len * ENCODING_LENGTH) + ENCODING_LENGTH, fileName, lineNumber);
                    tempData = OslMallocCHK(len, fileName, lineNumber);
                    ConvertGSM7BitDefaultEncodingToAscii(tempData, data, len, &outLength);
                    mmi_asc_n_to_ucs2((PS8) convertedData, (PS8) tempData, outLength);
                    memset((void*)&convertedData[outLength * ENCODING_LENGTH], 0, ENCODING_LENGTH);
                    OslMfree(tempData);
                }
                if (outLen != NULL)
                {
                    *outLen = outLength * ENCODING_LENGTH + ENCODING_LENGTH;
                }
                break;

            case (MMI_8BIT_DCS):
                convertedData = OslMallocCHK((len * ENCODING_LENGTH) + ENCODING_LENGTH, fileName, lineNumber);
                mmi_asc_n_to_ucs2((PS8) convertedData, (PS8) data, len);
                memset((void*)&convertedData[len * ENCODING_LENGTH], 0, ENCODING_LENGTH);
                if (outLen != NULL)
                {
                    *outLen = len * ENCODING_LENGTH + ENCODING_LENGTH;
                }
                break;

            case (MMI_UCS2_DCS):
                convertedData = OslMallocCHK(len + ENCODING_LENGTH, fileName, lineNumber);
                memcpy(convertedData, data, len);
                memset((void*)&convertedData[len], 0, ENCODING_LENGTH);
                if (outLen != NULL)
                {
                    *outLen = len + ENCODING_LENGTH;
                }
                tempData = (U16*) convertedData;
                for (i = 0; i < len; i += 2)
                {
                    SWAP_USHORT(tempData);
                    tempData++;
                }
                break;

        }
        return convertedData;
    }
    else
    {
        convertedData = OslMallocCHK(ENCODING_LENGTH, fileName, lineNumber);
        memset((void*)convertedData, 0, ENCODING_LENGTH);
        if (outLen != NULL)
        {
            *outLen = ENCODING_LENGTH;
        }
        return convertedData;
    }
}
#endif /* OSL_MEMORY_DUMP */ 


/*****************************************************************************
 * FUNCTION
 *  ConvertBCDToString
 * DESCRIPTION
 *  Converts  BCD Digits to Character String
 * PARAMETERS
 *  BCDNumber       [?]         
 *  len             [IN]        
 *  outLen          [?]         
 *  of(?)           [OUT]       Character String  will be returned
 *  msg(?)          [IN]        Input Buffer
 *  message(?)      [IN]        Output Buffer
 *  outlen(?)       [OUT]       Pointer to variable which will have output length
 * RETURNS
 *  Character String of BCD Characters
 *****************************************************************************/
U8 *ConvertBCDToString(U8 *BCDNumber, U16 len, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *outString;
    U8 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    outString = OslMalloc(2 * len + 1);

    /* micha1104, #211 */
    if (BCDNumber[0] == 0x91)
    {
        outString[j++] = '+';
    }

    /* micha1104, #211 */
    for (i = 1; i < len; i++)
    {
        outString[j++] = ConvertDigitToChar((U8) (BCDNumber[i] & 0x0F));
        outString[j] = ConvertDigitToChar((U8) ((BCDNumber[i] >> 4) & 0x0F));
        if (outString[j++] == 0)
        {
            if (outLen)
            {
                *outLen = j;
            }
            return outString;
        }
    }
    outString[j++] = 0;
    if (outLen)
    {
        *outLen = j;
    }
    return outString;
}


/*****************************************************************************
 * FUNCTION
 *  ConvertDigitToChar
 * DESCRIPTION
 *  Converts  BCD Digit to Char
 * PARAMETERS
 *  digit       [IN]        BCD Digit
 * RETURNS
 *  Character format of BCD Digit
 *****************************************************************************/
U8 ConvertDigitToChar(U8 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2006/02/13 Re-assign the value of BCD encoding numbers */
    if (digit < 10)
    {
        return 48 + digit;
    }
    else if (digit == 10)
    {
        return 42;  /* '*' */
    }
    else if (digit == 11)
    {
        return 35;      /* '#' */
    }
    else if (digit == 12)
    {
        return 0x70;    /* 'p' */
    }
    else if (digit == 13)
    {
        return 0x77;    /* 'w' */
    }
    else if (digit == 14)
    {
        return 43;  /* '+' */
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SwapEndian
 * DESCRIPTION
 *  Converts  Little Endian to Big Endian & vice versa
 * PARAMETERS
 *  Addr        [IN]        Pointer to data to be swapped
 *  Nb          [IN]        No. of bytes to be swapped
 * RETURNS
 *  Pointer to Swapped Digits(?)
 *****************************************************************************/
void *SwapEndian(void *Addr, const int Nb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1014 begin */
    static char Swapped[16];
    static U32 Result_align[4];
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (Nb)
    {
        case 2:
            Swapped[0] = *((char*)Addr + 1);
            Swapped[1] = *((char*)Addr);
            break;
        case 4:
            Swapped[0] = *((char*)Addr + 3);
            Swapped[1] = *((char*)Addr + 2);
            Swapped[2] = *((char*)Addr + 1);
            Swapped[3] = *((char*)Addr);
            break;
        case 8:
            Swapped[0] = *((char*)Addr + 7);
            Swapped[1] = *((char*)Addr + 6);
            Swapped[2] = *((char*)Addr + 5);
            Swapped[3] = *((char*)Addr + 4);
            Swapped[4] = *((char*)Addr + 3);
            Swapped[5] = *((char*)Addr + 2);
            Swapped[6] = *((char*)Addr + 1);
            Swapped[7] = *((char*)Addr);
            break;
        case 16:
            Swapped[0] = *((char*)Addr + 15);
            Swapped[1] = *((char*)Addr + 14);
            Swapped[2] = *((char*)Addr + 13);
            Swapped[3] = *((char*)Addr + 12);
            Swapped[4] = *((char*)Addr + 11);
            Swapped[5] = *((char*)Addr + 10);
            Swapped[6] = *((char*)Addr + 9);
            Swapped[7] = *((char*)Addr + 8);
            Swapped[8] = *((char*)Addr + 7);
            Swapped[9] = *((char*)Addr + 6);
            Swapped[10] = *((char*)Addr + 5);
            Swapped[11] = *((char*)Addr + 4);
            Swapped[12] = *((char*)Addr + 3);
            Swapped[13] = *((char*)Addr + 2);
            Swapped[14] = *((char*)Addr + 1);
            Swapped[15] = *((char*)Addr);
            break;
    }

    for (i = 0; i < 16; i++)
    {
        *((char*)Result_align + i) = Swapped[i];
    }

    return (void*)Result_align;
    /* micha1014 end */
}

/* flag=1: Handle extended characters. flag=0: Ignore extended characters  */
/* UCS2_count=0 for Default DCS, non zero for UCS2 DCS                  */


/*****************************************************************************
 * FUNCTION
 *  InputboxConvertGSMToDeviceEncoding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inBuffer            [?]         
 *  outBuffer           [?]         
 *  inBufferLength      [IN]        
 *  outBufferSize       [IN]        
 *  UCS2_count          [IN]        
 *  GSM_ext_count       [IN]        
 *  flag                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 InputboxConvertGSMToDeviceEncoding(
        U8 *inBuffer,
        U8 *outBuffer,
        U8 inBufferLength,
        S32 outBufferSize,
        S32 UCS2_count,
        S32 GSM_ext_count,
        U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    UI_buffer_type p1 = (UI_buffer_type) inBuffer;
    UI_buffer_type p2 = (UI_buffer_type) outBuffer;
    UI_character_type c, cc;
    S32 out_count = 0;
    U8 in_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag)
    {
        if (UCS2_count == 0)    /* ASCII */
        {
            while (!done)
            {
                UI_GET_NEXT_BYTE(p1, c);
                in_count++;
                if (UI_STRING_END_OF_STRING_CHARACTER(c) && (in_count > inBufferLength))        /* Also check in_conut to make sure all chracter converted */
                {
                    done = 1;
                    UI_STRING_INSERT_CHARACTER(p2, c);  /* Insert NULL terminator */
                    out_count += ENCODING_LENGTH;
                }
                else if (UI_TEST_ESC_CHARACTER(c))
                {
                    cc = c;
                    UI_GET_NEXT_BYTE(p1, c);
                    in_count++;
                    c = DefaultToExtendedAsciiArray[c];
                    if (UI_TEST_GSM_EXTENDED(c))
                    {
                        UI_STRING_INSERT_CHARACTER(p2, c);
                        out_count += ENCODING_LENGTH;
                    }
                    else
                    {
                        UI_GET_PREVIOUS_BYTE(p1, c);
                        in_count--;
                        c = DefaultToAsciiArray[cc];
                        UI_STRING_INSERT_CHARACTER(p2, c);
                        out_count += ENCODING_LENGTH;
                    }
                }
                else
                {
                    c = DefaultToAsciiArray[c];
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    out_count += ENCODING_LENGTH;
                }
                if (out_count >= (outBufferSize - 2))   /* To ensure null terminator at the end when exceeds buffer. */
                {
                    done = 1;
                    UI_STRING_INSERT_CHARACTER(p2, 0);
                    out_count += ENCODING_LENGTH;
                }
            }
        }
        else    /* MMI_PHB_UCS2 */
    #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 and 0x82 UCS2 */
        if (UCS2_count == 0x08)
    #endif 
        {
            while (!done)
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, c);
                UI_SWAP_U16_BYTES(c);
                if (UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    done = 1;
                }
                //if(c==_EURO_CHARACTER_UCS2) 
                //  c=_EURO_CHARACTER;
                UI_STRING_INSERT_CHARACTER(p2, c);  /* Append character here, including null terminator */
                out_count += ENCODING_LENGTH;

                if (out_count >= (outBufferSize - 2))   /* To ensure null terminator at the end when exceeds buffer. */
                {
                    done = 1;
                    UI_STRING_INSERT_CHARACTER(p2, 0);
                    out_count += ENCODING_LENGTH;
                }
            }
        }
    #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 and 0x82 UCS2 */
        else if (UCS2_count == 0x09)    /* MMI_PHB_UCS2_81 */
        {
            U16 base_ptr;
            U8 i, length;

            UI_GET_NEXT_BYTE(p1, c);
            UI_GET_NEXT_BYTE(p1, c);
            length = (U8) c;
            base_ptr = (*p1) << 7;
            UI_GET_NEXT_BYTE(p1, c);

            for (i = 0; i < length; i++)
            {
                if (out_count >= (outBufferSize - 2))
                {
                    break;
                }

                UI_GET_NEXT_BYTE(p1, c);

                if (c < 0x80)   /* Default GSM character */
                {
                    c = DefaultToAsciiArray[c];
                }
                else    /* UCS2 character */
                {
                    c &= 0x7F;
                    c += base_ptr;
                }
                *(p2)++ = c & 0xFF;
                *(p2)++ = c >> 8 & 0xFF;
            }

            UI_STRING_INSERT_CHARACTER(p2, 0);  /* Add null terminator at the end */
            out_count += ENCODING_LENGTH;
        }
        else if (UCS2_count == 0x10)    /* MMI_PHB_UCS2_82 */
        {
            U16 base_ptr;
            U8 i, length;

            UI_GET_NEXT_BYTE(p1, c);
            UI_GET_NEXT_BYTE(p1, c);
            length = (U8) c;
            base_ptr = (*p1) << 8;
            UI_GET_NEXT_BYTE(p1, c);
            base_ptr |= (*p1);
            UI_GET_NEXT_BYTE(p1, c);

            for (i = 0; i < length; i++)
            {
                if (out_count >= (outBufferSize - 2))
                {
                    break;
                }

                UI_GET_NEXT_BYTE(p1, c);

                if (c < 0x80)   /* Default GSM character */
                {
                    *(p2)++ = (U8) DefaultToAsciiArray[c];
                    *(p2)++ = 0x0;
                }
                else    /* UCS2 character */
                {
                    c &= 0x7F;
                    c += base_ptr;

                    *(p2)++ = c & 0xFF;
                    *(p2)++ = c >> 8 & 0xFF;
                }

                out_count += ENCODING_LENGTH;
            }

            UI_STRING_INSERT_CHARACTER(p2, 0);  /* Add null terminator at the end */
            out_count += ENCODING_LENGTH;
        }
    #endif /* defined(__PHB_0x81_SUPPORT__) */ 
    }
    return out_count;
}

/* flag=1: Handle extended characters. flag=0: Ignore extended characters  */
/* UCS2_count=0 for Default DCS, non zero for UCS2 DCS                  */


/*****************************************************************************
 * FUNCTION
 *  InputboxConvertDeviceEncodingToGSM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inBuffer            [?]         
 *  outBuffer           [?]         
 *  outBufferSize       [IN]        
 *  UCS2_count          [IN]        
 *  GSM_ext_count       [IN]        
 *  flag                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 InputboxConvertDeviceEncodingToGSM(
        U8 *inBuffer,
        U8 *outBuffer,
        S32 outBufferSize,
        S32 UCS2_count,
        S32 GSM_ext_count,
        U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    UI_buffer_type p1 = (UI_buffer_type) inBuffer;
    UI_buffer_type p2 = (UI_buffer_type) outBuffer;
    UI_character_type c;
    S32 out_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag)
    {
        if (UCS2_count == 0)
        {
            while (!done)
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, c);
                if (UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    done = 1;
                    UI_INSERT_BYTE(p2, c);
                    out_count += 1;
                }
                else if (UI_TEST_GSM_EXTENDED(c))
                {
                    UI_INSERT_BYTE(p2, _ESCAPE_CHARACTER);
                    c = ExtendedAsciiToDefaultArray[c];
                    UI_INSERT_BYTE(p2, c);
                    out_count += 2; /* MTK 2003-12-29 */
                }
                else
                {
                    c = AsciiToDefaultArray[c];
                    UI_INSERT_BYTE(p2, c);
                    out_count += 1;
                }
                if (out_count >= outBufferSize)
                {
                    done = 1;
                }
            }
        }
        else
        {
            while (!done)
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, c);
                if (UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    done = 1;
                }
                /* if(c==_EURO_CHARACTER) c=_EURO_CHARACTER_UCS2; */
                UI_SWAP_U16_BYTES(c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                out_count += ENCODING_LENGTH;
                if (out_count >= outBufferSize)
                {
                    done = 1;
                }
            }
        }
    }
    else
    {
        if (UCS2_count == 0)
        {
            while (!done)
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, c);
                if (UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    done = 1;
                    UI_INSERT_BYTE(p2, c);
                }
                else
                {
                    c = AsciiToDefaultArray[c];
                    UI_INSERT_BYTE(p2, c);
                }
                out_count += 1;
                if (out_count >= outBufferSize)
                {
                    done = 1;
                }
            }
        }
        else
        {
            while (!done)
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, c);
                if (UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    done = 1;
                }
                /* if(c==_EURO_CHARACTER) c=_EURO_CHARACTER_UCS2; */
                UI_SWAP_U16_BYTES(c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                out_count += ENCODING_LENGTH;
                if (out_count >= outBufferSize)
                {
                    done = 1;
                }
            }
        }
    }
    return (out_count);
}

