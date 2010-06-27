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
 * pictruemsg.c
 *
 * Project:
 * --------
 * PDG1
 *
 * Description:
 * ------------
 * This file implements Picture Message back end application.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 */
#include "MMI_include.h"

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

#ifndef _MMI_PICMSG_C
#define _MMI_PICMSG_C

// #ifdef __MMI_PICMSG__

/*  Include: MMI header file */
#include "picturemsg.h"
#include "PicMsgApiToOthers.h"
#include "CommonNSM.h"
#include "ems.h"
#include "customer_ps_inc.h"

#include "smsguiinterfacetype.h"

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 ************************* Define ****************************
 */
#define MODULUS                  241
#define ONE_BYTE_SIZE            8
#define MMI_EXTRA_BMP_HEADER_SIZE   6
#define PIC_MSG_SIGNATURE        "0504158A"
#define RING_TONE_MSG_SIGNATURE     "05041581"
#define BMP_HEADER_SIZE          (sizeof(BmpFileHeader_sturct)-2)
#define MAX_PIC_HIEGHT_PIXEL     32
#define MAX_PIC_WIDTH_PIXEL         96 / ONE_BYTE_SIZE  /* We store 8 bits in one bytes */
#define MAX_BMP_HDR_SIZE         64

/* Start JP */
#define     MAX_NSM_PIC_WIDTH    72
#define     MAX_NSM_PIC_HEIGHT      28
/* End JP */

/* 
 *************************** Typedef  *******************************
 */
typedef enum
{
    SMRT_NORMAL_SMS_0,
    SMRT_PICTURE_SMS_1,
    SMRT_RING_TONE_SMS_2
} smrt_sms_type_enum;

typedef enum
{
    PMSG_FIRST_FOUR_BITS = 1,
    PMSG_SECOND_FOUR_BITS = 2
} pmsg_bits_position_enum;

/* 
 *************** Function Declaration *****************************
 */

S16 mmi_smrt_message_type(U8 *SmsData);

#if (0)
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 

U8 *mmi_pmsg_convert_ota_to_bmp(U8 *otaData);
U8 *mmi_pmsg_convert_bmp_to_ota(U8 *BmpBuffer);
U8 mmi_pmsg_convert_ascii_hex_to_dec(S8 character);
U8 mmi_pmsg_convert_binary_dec_to_hex(const U8 DecimalVal, U8 part);

void mmi_pmsg_convert_ascii_hex_string_2_dec_string(U8 *DecStr, U8 *AsciiStr);
void mmi_pmsg_convert_dec_string_2_ascii_hex_string(U8 *AsciiStr, U8 *DecStr);

U8 *mmi_pmsg_create_ota_data(U8 *BinaryData, S16 H, S16 W);
U8 *mmi_pmsg_create_bmp_data(void);
void mmi_pmsg_set_default_values_bmp_header(void);
S16 mmi_pmsg_read_picture_header(U8 *OtaPattern);
S16 mmi_pmsg_read_bmp_data(U8 *RawData, U8 *BmpData, S16 *H, S16 *W);
U16 mmi_pmsg_get_size_bmp_data(U8 *BmpData);
U16 mmi_pmsg_get_size_ota_data(U8 *OtaBuffer);
BOOL mmi_pmsg_is_smart_picture(U8 *BmpData);

S16 mmi_pmsg_add_bmp_header_info(U8 *BmpData);
U16 mmi_pmsg_add_picture_text(U8 *OtaData, U8 *TextBuffer);
void mmi_pmsg_add_nokia_header(U8 *PictureMessage, U8 TotalSegment, U8 CurrentSegment);
void mmi_pmsg_add_header(U8 *header, U16 HeaderLen, U8 *Data, U16 DataLen);

void mmi_pmsg_shift_n_bytes(S8 *Data, S16 offset, S16 nBytes, S16 length);
U8 mmi_pmsg_get_n_bits(U8 *Data, U16 Offset, U16 Bits);
U8 mmi_pmsg_get_next_byte(void);
void mmi_pmsg_fskip(FS_HANDLE fp, S16 num_bytes);

S16 mmi_pmsg_string_search(S8 *Pattern, S8 *Text);
S16 mmi_pmsg_hash(S8 *str);
S16 mmi_pmsg_HashN(S8 *Str, S16 PatternLength);
S16 mmi_pmsg_HashIncrement(S8 *str, S16 PrevIndex, S16 PrevHash, S16 PatternLength);

/* 
 ************************ Global Variables ****************************
 */
/* This is a BMP Header which strored the information of file */
static BmpFileHeader_sturct g_pmsg_BmpHeader;

/*  This var shall store the pointer of OTA data to retrieve the values */
static U8 *OTAdata = NULL;

/*  This var shall store the pointer index of OTA data to retrieve the values */
static U16 g_pmsg_ota_index = 0;

/* This var shall store the Text of Picture message and shall be used by Category screen to show the text */
S8 g_pmsg_TextInMessage[MAX_PICTEXT_BUFF_SIZE + (TEXT_BUFF_PADDING)];

/* This var shall store the Ota Picture len */
static U16 gOtaDataLen = 0;

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
extern nsm_msg_struct g_nsm_msg_context;
#endif 

#if defined(__MMI_SMART_MESSAGE_MT__)
#include "MessagesExDcl.h"
extern nsm_picmsg_text_struct picmsg_text_struct;
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
/* 
 ************************ Global Functions ****************************
 */
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);

/* 
 ************************ Temp Var for testing and debugging the code ********
 */
// Assh..whole data.
//S8  OTAdata[] = "0B0504158A000000030103013000000002010000481C01FF5C0151C104555FFFFEAA00278A00AAAFFFFF5C00001500155FFFBEB8000802002AAFFF7FD8005D04000557FFBFF800012800DAAFFF5FF0000E40001557FFBEF80000A0008AABFF5FD0000100001555FFAFF8000080000AABFF55D8000000000555FFAAB8800000000AAAFF557DC000001505557F0B0504158A00000003010302AAAAF80002EFA22AFF555C100015F554457FA0A80A802FA0AA22FF405801405500151474A028E880AA280280BE4015DC01557F00047EA029FE002AFFA802BE4015FF4055FFF4007C800BAC80AAACF800BE00101440151C14015D80A88800AB382800BA415841005110540155AAA82000A80B8000AA555801005415000150AAA80B0504158A000000030103030200A8000002A8";
// Line S8  OTAdata[] = "00480E01803804020300C01800600C06030100400C002006020301806006001802010080C030010008030180C0600800C0060180C040300600600200C040201003003001806020301801801800802030100C00800C006030101806004006002018180C030060030018080C060100200000080C040301803000000606020100801000";
// Chess Data.
//S8  OTAdata[] = "0040400100FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00";
// PMT data.
//S8  OTAdata[] = "00481C01FFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF5FFFAFFAFFFAFFFF000000FF57FFAFFAFFFAFFFF000000FF59FFAF7AFFFAFFFF000000FF5E0FAEBAFFFAFFFF000000FF5FEFADDAFFFAFFFF000000FF5FEFADDAFFFAFFFF000000FF5FEFBBEEFFFAFFFF000000FF5F0FB7F6FFFAFFFF000000";
// Function Spec data.
//S8  OTAdata[] = "00480E01FFFFFFFFFFFFFFFFFF000000000000000000FFFFFFFFFFFFFFFFFF00000000000000000010F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";

/*********************************************************************************
 ************************* Funtion Definition Starts *****************************
 *********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_set_default_values_bmp_header
 * DESCRIPTION
 *  Set default values in BMP Header.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pmsg_set_default_values_bmp_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_pmsg_BmpHeader, 0x00, BMP_HEADER_SIZE + 2);
    g_pmsg_BmpHeader.BmpBMPFileHeader.Signature = (U16) 19778;
    g_pmsg_BmpHeader.BmpBMPFileHeader.DataOffset = (U32) BMP_HEADER_SIZE;
    g_pmsg_BmpHeader.BmpBMPInfoHeader.HeaderSize = (U32) 40;
    g_pmsg_BmpHeader.BmpBMPInfoHeader.Bits = (U16) 1;
    g_pmsg_BmpHeader.BmpBMPInfoHeader.Planes = (U16) 1;
    g_pmsg_BmpHeader.BmpColors1.Blue = (U8) 255;
    g_pmsg_BmpHeader.BmpColors1.Green = (U8) 255;
    g_pmsg_BmpHeader.BmpColors1.Red = (U8) 255;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_convert_ota_to_bmp
 * DESCRIPTION
 *  Converter of OTA format to BMP format.
 * PARAMETERS
 *  Data        [?]     
 *  S8 *, OTA data.(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_pmsg_convert_ota_to_bmp(U8 *Data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 PictureHeaderLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmsg_ota_index = 0;

    PictureHeaderLen = mmi_pmsg_read_picture_header(Data);

    if (PictureHeaderLen == -1)
    {
        return NULL;
    }

    mmi_pmsg_shift_n_bytes((S8*) Data, 0, (S16) PictureHeaderLen, gOtaDataLen);        /* Remove the Picture Message Header */

    OTAdata = Data;

    mmi_pmsg_set_default_values_bmp_header();

    return mmi_pmsg_create_bmp_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_convert_bmp_to_ota
 * DESCRIPTION
 *  Convets the BMP file format to OTA format
 * PARAMETERS
 *  BmpBuffer       [?]     
 *  Bmp Buffer.(?)
 * RETURNS
 *  Pointer to OTA data.
 *****************************************************************************/
U8 *mmi_pmsg_convert_bmp_to_ota(U8 *BmpBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Hight = 0;
    S16 Width = 0;

    /* U8 BmpBinaryData[(PIC_BUFF_MAX_LEN)]; */
    U8 *BmpBinaryData;
    U8 *ptr_OtaData = NULL;
    U8 *BmpDataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AshBmpDataHex */
    BmpBinaryData = OslMalloc(PIC_BUFF_MAX_LEN);
    BmpDataPtr = BmpBuffer + MMI_EXTRA_BMP_HEADER_SIZE; /* removed the MMI header information */

    memset(BmpBinaryData, '\0', (PIC_BUFF_MAX_LEN));

    if (mmi_pmsg_read_bmp_data(BmpBinaryData, BmpDataPtr, &Hight, &Width) != 0)
    {
        return NULL;
    }

    ptr_OtaData = mmi_pmsg_create_ota_data(BmpBinaryData, Hight, Width);
    OslMfree(BmpBinaryData);
    /* return mmi_pmsg_create_ota_data(BmpBinaryData, Hight,Width); */
    return ptr_OtaData;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_read_bmp_data
 * DESCRIPTION
 *  Read the whole bits format of Bmp file.
 * PARAMETERS
 *  RawData     [?]     
 *  BmpData     [?]     
 *  H           [?]     
 *  W           [?]     
 *  File Name with Path of Bmp file and pointe of data to store picture data.(?)
 * RETURNS
 *  -1 if any error.
 *****************************************************************************/
S16 mmi_pmsg_read_bmp_data(U8 *RawData, U8 *BmpData, S16 *H, S16 *W)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 RotatedData[MAX_PIC_HIEGHT_PIXEL][MAX_PIC_WIDTH_PIXEL];
    S16 i = 0, j = 0;
    S16 width = 0;
    S16 height = 0;
    S16 num_colors = 0;
    S16 index = 0;
    S16 x = 0;
    BOOL complement_flag = FALSE;   /* JP for predefined NSM Pictures */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(RotatedData, '\0', MAX_PIC_HIEGHT_PIXEL * MAX_PIC_WIDTH_PIXEL);

    /* check to see if it is a valid bitmap file */

    if ((BmpData[index++] != 'B') || (BmpData[index++] != 'M'))
    {
        PRINT_INFORMATION("It is not a bitmap file.\n");
        return -1;
    }

    /* read in the width and height of the image, and the number of colors used; ignore the rest */
    index += 16;

    width = BmpData[index++];
    width |= BmpData[index++] << ONE_BYTE_SIZE;

    index += 2;

    height = BmpData[index++];
    height |= BmpData[index++] << ONE_BYTE_SIZE;

    index += 22;

    num_colors = BmpData[index++];
    num_colors |= BmpData[index++] << ONE_BYTE_SIZE;

    if (num_colors > 1)
    {
        PRINT_INFORMATION("It is a multi color bitmap file.\n");
        complement_flag = TRUE;
        /* return -1; *//* JP commented for tracker issue 396 */
    }

    /* First Header end. */
    index += 6;

    /* Skip the color table */
    index += 8;

    if (width / ONE_BYTE_SIZE > 8)
    {
        j = 12;
    }
    else
    {
        j = 8;
    }

    for (x = 0; x < height; x++)
    {
        for (i = 0; i < j; i++)
        {
            /* 
             * JP 20050629
             * We have to complement Predfined NSM
             * Picture data
             */
            if (complement_flag)
            {
                RotatedData[x][i] = (~BmpData[index++]);
            }
            else
            {
                RotatedData[x][i] = (BmpData[index++]);
            }

        }
    }

    index = 0;

    for (i = x - 1; i >= 0; i--)
    {
        for (j = 0; j < width / ONE_BYTE_SIZE; j++)
        {
            RawData[index++] = RotatedData[i][j];
        }
    }

    *H = height;
    *W = width;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_create_bmp_data
 * DESCRIPTION
 *  Prepared the BMP file format based on OTA data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_pmsg_create_bmp_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 BmpDataHeader[MAX_BMP_HDR_SIZE];
    U8 RotatedData[MAX_PIC_HIEGHT_PIXEL][MAX_PIC_WIDTH_PIXEL];
    U8 *BmpData = NULL;
    S16 HeaderLen = 0;
    S16 TotalSizeOfBmp = 0;
    S16 index = 0;
    S16 x = 0, i = 0, j = 0, k = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(RotatedData, '\0', MAX_PIC_HIEGHT_PIXEL * MAX_PIC_WIDTH_PIXEL);
    memset(BmpDataHeader, '\0', MAX_BMP_HDR_SIZE);

    /* this is info field. */
    mmi_pmsg_get_next_byte();

    /* this is width field. */
    g_pmsg_BmpHeader.BmpBMPInfoHeader.Width = (U32) mmi_pmsg_get_next_byte();

    /* this is height field. */
    g_pmsg_BmpHeader.BmpBMPInfoHeader.Height = (U32) mmi_pmsg_get_next_byte();

    /* this is Depth field. */
    mmi_pmsg_get_next_byte();

    HeaderLen = (S16) g_pmsg_BmpHeader.BmpBMPInfoHeader.Width / ONE_BYTE_SIZE;

    for (i = 0; i < gOtaDataLen; i++)
    {
        RotatedData[j][k] = mmi_pmsg_get_next_byte();
        k++;
        if (k >= HeaderLen)
        {
            k = 0;
            j++;
        }
    }

    if (HeaderLen > 8)
    {
        HeaderLen = 12;
    }
    else if (HeaderLen > 4)
    {
        HeaderLen = 8;
    }
    else
    {
        HeaderLen = 4;
    }

    /* Six extra bytes added for MMI support */
    TotalSizeOfBmp = BMP_HEADER_SIZE + (HeaderLen * j) + MMI_EXTRA_BMP_HEADER_SIZE;

    /* Put the real size of BMP */
    g_pmsg_BmpHeader.BmpBMPFileHeader.FileSize = (U32) TotalSizeOfBmp - MMI_EXTRA_BMP_HEADER_SIZE;

    memcpy(&BmpDataHeader, &g_pmsg_BmpHeader, BMP_HEADER_SIZE + 2);

    BmpData = (U8*) OslMalloc(TotalSizeOfBmp);
    /* memset((S8*)BmpData,'\0',TotalSizeOfBmp); */

    BmpData[index++] = 0x1;
    BmpData[index++] = 0x0;
    BmpData[index++] = (U8) ((g_pmsg_BmpHeader.BmpBMPFileHeader.FileSize & 0x000000FF));
    BmpData[index++] = (U8) ((g_pmsg_BmpHeader.BmpBMPFileHeader.FileSize & 0x0000FF00) >> 8);
    BmpData[index++] = (U8) ((g_pmsg_BmpHeader.BmpBMPFileHeader.FileSize & 0x00FF0000) >> 16);
    BmpData[index++] = (U8) ((g_pmsg_BmpHeader.BmpBMPFileHeader.FileSize & 0xFF000000) >> 24);

    for (i = 0; i < BMP_HEADER_SIZE; i++)
    {
        BmpData[index++] = BmpDataHeader[i + 2];
    }

    for (i = j - 1; i >= 0; i--)
    {
        for (x = 0; x < HeaderLen; x++)
        {
            BmpData[index++] = RotatedData[i][x];
        }
    }

    return (U8*) BmpData;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_get_next_byte
 * DESCRIPTION
 *  Combine the two Hex value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_pmsg_get_next_byte(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = OTAdata[g_pmsg_ota_index];
    g_pmsg_ota_index++;

    return value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_get_n_bits
 * DESCRIPTION
 *  Find out the required bits in given data.
 * PARAMETERS
 *  Data        [?]         Offset and req bits.
 *  Offset      [IN]        
 *  Bits        [IN]        
 * RETURNS
 *  Bits value.
 *****************************************************************************/
U8 mmi_pmsg_get_n_bits(U8 *Data, U16 Offset, U16 Bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = Offset / ONE_BYTE_SIZE;
    U8 BitsfromFirstIndex = ONE_BYTE_SIZE - (Offset % ONE_BYTE_SIZE);
    U8 firstByte = Data[index];
    U8 secondByte = Data[index + 1];
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Bits > ONE_BYTE_SIZE)
    {
        return 0;
    }

    result = (firstByte << (ONE_BYTE_SIZE - BitsfromFirstIndex)) | (secondByte >> BitsfromFirstIndex);

    result = result >> (ONE_BYTE_SIZE - Bits);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_convert_ascii_hex_to_dec
 * DESCRIPTION
 *  Converts Ascii value to Decimal value
 * PARAMETERS
 *  character       [IN]        
 *  S8 ascii values(?)
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
U8 mmi_pmsg_convert_ascii_hex_to_dec(S8 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (character > 47 && character < 58)   /* Digits 0..9 */
    {
        return (character - 48);
    }
    else if (character > 64 && character < 71)  /* Characters A..F */
    {
        return (character - 55);
    }
    else if (character > 96 && character < 103) /* Characters a..f */
    {
        return (character - 87);
    }
    else
    {
        return (0xFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_convert_binary_dec_to_hex
 * DESCRIPTION
 *  Converts Binary value to Hex value.
 * PARAMETERS
 *  DecimalVal      [IN]        
 *  part            [IN]        Which says about first byte or second byte data needed.
 * RETURNS
 *  U8 Hex value.
 *****************************************************************************/
U8 mmi_pmsg_convert_binary_dec_to_hex(const U8 DecimalVal, U8 part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Firstpart = 0xf0 & DecimalVal;
    U8 Secondpart = 0xf & DecimalVal;
    U8 ReturnVal = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Firstpart >>= 4;

    ReturnVal = Secondpart;
    if (part == PMSG_FIRST_FOUR_BITS)
    {
        ReturnVal = Firstpart;
    }

    if (ReturnVal < 10)
    {
        ReturnVal += 48;
    }
    else
    {
        ReturnVal += 55;
    }

    return ReturnVal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_fskip
 * DESCRIPTION
 *  Skip the file pointer of num bytes.
 * PARAMETERS
 *  fp              [IN]        
 *  num_bytes       [IN]        
 *  file pointer and skip times.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pmsg_fskip(FS_HANDLE fp, S16 num_bytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 errorCode = 0;
    S8 Data[64];
    U32 read_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Read( fp, (void*)Data, num_bytes, &read_len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_create_ota_data
 * DESCRIPTION
 *  Creates OTA file.
 * PARAMETERS
 *  BinaryData      [?]         
 *  H               [IN]        
 *  W               [IN]        
 *  Pointer to OTA data,Pointer of binary data, Hieght and width.(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_pmsg_create_ota_data(U8 *BinaryData, S16 H, S16 W)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;
    S16 index = 0;
    U8 *OtaData = NULL;
    U16 DataSize = (H * W / ONE_BYTE_SIZE) + 4; /* infofield, width, height, and depth */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gOtaDataLen = DataSize;
    OtaData = (U8*) OslMalloc(MAX_DATA_SIZE);
    memset(OtaData, '\0', MAX_DATA_SIZE);

    /* Put OTA tyep field */
    OtaData[index++] = 0x02;

    /* Put OTA Size field */
    OtaData[index++] = (U8) ((DataSize & 0xff00) >> ONE_BYTE_SIZE);
    OtaData[index++] = (U8) (DataSize & 0x00ff);

    /* Put Info field */
    OtaData[index++] = 0x00;

    /* Put width */
    OtaData[index++] = (U8) W;

    /* Put Hieght */
    OtaData[index++] = (U8) H;

    /* Put Color */
    OtaData[index++] = 0x01;

    /* Put Data */
    for (i = 0; i < W * H / ONE_BYTE_SIZE; i++)
    {
        OtaData[index++] = BinaryData[i];
    }

    return OtaData;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_string_search
 * DESCRIPTION
 *  This algorithm uses hashing to implement string searching in linear time.
 * PARAMETERS
 *  Pattern     [?]     
 *  Text        [?]     In which pattern is to be search.
 * RETURNS
 *  if success then starting location of pattern else -1 if pattern not found.
 *****************************************************************************/
S16 mmi_pmsg_string_search(S8 *Pattern, S8 *Text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 num_iteration = 0;
    S16 PatternLength = 0;
    S16 PatternHash = 0;
    S16 TextHash = 0;
    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Pattern == NULL || Text == NULL)
    {
        return -1;
    }
    else
    {

        PatternLength = strlen((S8*) Pattern);
        num_iteration = strlen((S8*) Text) - PatternLength + 1;

        /* Find initial hash values for Pattern and Text */
        /* These are called FINGERPRINT */
        PatternHash = mmi_pmsg_hash(Pattern);
        TextHash = mmi_pmsg_HashN(Text, PatternLength);

        for (i = 0; i < num_iteration; i++)
        {
            if ((PatternHash == TextHash) && !(strncmp(Pattern, (Text + i), PatternLength)))
            {
                return i;
            }
            TextHash = mmi_pmsg_HashIncrement(Text, i, TextHash, PatternLength);
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_hash
 * DESCRIPTION
 *  Calculate the hash of given string.
 * PARAMETERS
 *  str     [?]     
 *  Pointer to given string.(?)
 * RETURNS
 *  Hash value.
 *****************************************************************************/
S16 mmi_pmsg_hash(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sum = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; *str; str++)
    {
        sum += *str;
    }

    return sum % MODULUS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_HashN
 * DESCRIPTION
 *  Calculate the hash value of given number of bytes.
 * PARAMETERS
 *  Str                 [?]         
 *  PatternLength       [IN]        
 *  Pointer to Data, Length of Pattern which hash value to be needed.(?)
 * RETURNS
 *  Calculated hash value.
 *****************************************************************************/
S16 mmi_pmsg_HashN(S8 *Str, S16 PatternLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ch = Str[PatternLength];
    S16 HashValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Str[PatternLength] = '\0';
    HashValue = mmi_pmsg_hash(Str);
    Str[PatternLength] = ch;

    return HashValue;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_HashIncrement
 * DESCRIPTION
 *  Increment the hash values by removing previous value and adding next value.
 * PARAMETERS
 *  str                 [?]         
 *  PrevIndex           [IN]        
 *  PrevHash            [IN]        
 *  PatternLength       [IN]        
 *  Pointer to given String, Previous Index, Previous hash value, Pattern Length.(?)
 * RETURNS
 *  New hash value.
 *****************************************************************************/
S16 mmi_pmsg_HashIncrement(S8 *str, S16 PrevIndex, S16 PrevHash, S16 PatternLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    val = (PrevHash - (S16) str[PrevIndex]) + (str[PrevIndex + PatternLength]);

    return val < 0 ? val + MODULUS : val % MODULUS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_shift_n_bytes
 * DESCRIPTION
 *  Remove the specified N byte from the given Data and shift the whole values.
 * PARAMETERS
 *  Data        [?]         Location from Data to be removed, Number of byte to be removed.
 *  offset      [IN]        
 *  nBytes      [IN]        
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pmsg_shift_n_bytes(S8 *Data, S16 offset, S16 nBytes, S16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = offset, j = 0;
    S8 *DataPtr = Data + offset + nBytes;
    S16 len = length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len > 0)
    {
        Data[index++] = *DataPtr++;
        len--;
    }

    for (j = 0; j < nBytes; j++)
    {
        Data[index++] = '\0';
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_add_header
 * DESCRIPTION
 *  Add the Header into given data. ( Data must be big enought to add header buffer)
 * PARAMETERS
 *  header          [?]         
 *  HeaderLen       [IN]        
 *  Data            [?]         & Data Size.
 *  DataLen         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pmsg_add_header(U8 *header, U16 HeaderLen, U8 *Data, U16 DataLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *DataBackUp = NULL;
    U16 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataBackUp = (U8*) OslMalloc(DataLen + HeaderLen + 4);
    memset(DataBackUp, 0x00, (DataLen + HeaderLen + 4));

    while (j < HeaderLen)
    {
        DataBackUp[i++] = header[j];
        j++;
    }

    j = 0;
    while (j < DataLen)
    {
        DataBackUp[i++] = Data[j];
        j++;
    }

    memset(Data, 0x00, i + 1);

    j = 0;
    while (j < i)
    {
        Data[j] = DataBackUp[j];
        j++;
    }
    OslMfree(DataBackUp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_read_picture_header
 * DESCRIPTION
 *  Read the Picture Header information and put the checks.
 * PARAMETERS
 *  OtaPattern      [?]     
 *  Pointer to OtaData.(?)
 * RETURNS
 *  If error return -1 else len of picture message header.
 *****************************************************************************/
S16 mmi_pmsg_read_picture_header(U8 *OtaPattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 RecvVal = 0;
    U16 index = 0;
    S16 i = 0;
    U16 OtaDataLen = 0;

    /* S8 tempTextBuffer[MAX_PICTEXT_BUFF_SIZE+(TEXT_BUFF_PADDING)]; */
    S8 *tempTextBuffer = NULL;
    U16 charType = 0;
    EMSData *pEms;
    U16 EmsDataLen = 0;
    U8 missSegStr[] = EMS_MISS_SEG_DELIMIT_STR;
    U16 missSegStrLen = strlen((const char*)missSegStr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);
    EmsDataLen = pEms->textLength / 2;
    memset(g_pmsg_TextInMessage, '\0', MAX_PICTEXT_BUFF_SIZE + (TEXT_BUFF_PADDING));

    /* Version Information */
    RecvVal = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
    index += ONE_BYTE_SIZE;

    if (RecvVal != 48)
    {
        return -1;
    }

    /* Type */
    RecvVal = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
    index += ONE_BYTE_SIZE;
    charType = RecvVal;

    if (RecvVal == 0 || RecvVal == 1)   /* Message Text */
    {
        /* Item Len */
        OtaDataLen = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
        index += ONE_BYTE_SIZE;

        RecvVal = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
        index += ONE_BYTE_SIZE;

        OtaDataLen <<= ONE_BYTE_SIZE;
        OtaDataLen = OtaDataLen | RecvVal;

        /* tempTextBuffer = OslMalloc((MAX_PICTEXT_BUFF_SIZE+TEXT_BUFF_PADDING)); */
        tempTextBuffer = OslMalloc((OtaDataLen) + TEXT_BUFF_PADDING);

        /* memset(tempTextBuffer, '\0',(MAX_PICTEXT_BUFF_SIZE+TEXT_BUFF_PADDING)); */
        memset(tempTextBuffer, '\0', ((OtaDataLen) + TEXT_BUFF_PADDING));

        /* Read the Text */
        for (i = 0; i < OtaDataLen; i++)
        {
            tempTextBuffer[i] = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
            index += ONE_BYTE_SIZE;
        }

        if (charType == 0)
        {
            mmi_asc_to_ucs2((S8*) g_pmsg_TextInMessage, (S8*) tempTextBuffer);
        }
        else
        {
            /* For Unicode character : JP */
            {
                S32 count = 0;
                U8 temp = 0;

                while (count < OtaDataLen)
                {
                    temp = tempTextBuffer[count];
                    tempTextBuffer[count] = tempTextBuffer[count + 1];
                    tempTextBuffer[count + 1] = temp;
                    count = count + 2;
                }

                mmi_ucs2cpy((S8*) g_pmsg_TextInMessage, (S8*) (tempTextBuffer));
            }
        }
        OslMfree(tempTextBuffer);

        /* Read the OTA bitmat type : 02 */
        RecvVal = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
        index += ONE_BYTE_SIZE;

        if (RecvVal != 2)
        {
            return -1;
        }
    }
    else if (RecvVal == 2)
    {
        /* There is not text part in message */
    }
    else
    {
        return -1;
    }

    OtaDataLen = 0;

    /* Read the len of OTA data */
    OtaDataLen = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
    index += ONE_BYTE_SIZE;

    RecvVal = mmi_pmsg_get_n_bits(OtaPattern, index, ONE_BYTE_SIZE);
    index += ONE_BYTE_SIZE;

    OtaDataLen <<= ONE_BYTE_SIZE;
    gOtaDataLen = OtaDataLen | RecvVal;

    /* Incomplete message content */
    if (((EmsDataLen - (index / ONE_BYTE_SIZE)) < gOtaDataLen) ||
        !strncmp((const char*)(OtaPattern + (EmsDataLen - missSegStrLen)), (const char*)missSegStr, missSegStrLen))
    {
        return -1;
    }

    return (index / ONE_BYTE_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_smrt_message_type
 * DESCRIPTION
 *  Find Out the type of Message.
 * PARAMETERS
 *  SmsData     [?]     
 *  Pointer to SMS data.(?)
 * RETURNS
 *  TYPE of SMS ( Normal, Picture or Ring Tone)
 *****************************************************************************/
S16 mmi_smrt_message_type(U8 *SmsData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 IsFindPattern = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search the picture message signature */
    IsFindPattern = mmi_pmsg_string_search((S8*) PIC_MSG_SIGNATURE, (S8*) SmsData);
    if (IsFindPattern >= 0)
    {
        return SMRT_PICTURE_SMS_1;
    }

    /* search the ring tone message signature */
    IsFindPattern = mmi_pmsg_string_search((S8*) RING_TONE_MSG_SIGNATURE, (S8*) SmsData);
    if (IsFindPattern >= 0)
    {
        return SMRT_RING_TONE_SMS_2;
    }

    /* search the ring tone message signature */
    IsFindPattern = mmi_pmsg_string_search((S8*) RING_TONE_MELODY_SIGNATURE, (S8*) SmsData);
    if (IsFindPattern >= 0)
    {
        return SMRT_RING_TONE_SMS_2;
    }

    /* It is neither Picture massage nor Rong tone */
    return SMRT_NORMAL_SMS_0;
}

#if (0)
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
#endif /* (0) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_add_picture_text
 * DESCRIPTION
 *  Prepared the Picture message format and add the picture text.
 * PARAMETERS
 *  OtaData         [?]     
 *  TextBuffer      [?]     
 *  OTA data & text buffer.(?)
 * RETURNS
 *  Length of OTA data with header.
 *****************************************************************************/
U16 mmi_pmsg_add_picture_text(U8 *OtaData, U8 *TextBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 TextLen;                    /* = (mmi_ucs2strlen((S8*)TextBuffer)*2); */
    U16 DataLen = gOtaDataLen + 3;  /* type (02 for OTA-bitmap), length ( 2 bytes) */

    /* U8  OtaText[MAX_PICTEXT_BUFF_SIZE+TEXT_BUFF_PADDING]; */
    U8 *OtaText = NULL;
    U16 index = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OtaText = OslMalloc((MAX_PICTEXT_BUFF_SIZE + TEXT_BUFF_PADDING));
    memset(OtaText, 0x00, MAX_PICTEXT_BUFF_SIZE + TEXT_BUFF_PADDING);

    /* Version */
    OtaText[index++] = 0x30;

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

    if (g_nsm_msg_context.UCS2_count > 0)
    {
        /* text type */
        OtaText[index++] = 0x01;
        TextLen = (mmi_ucs2strlen((S8*) TextBuffer) * 2); /* JP */
    }
    else
    {
        /* text type */
        OtaText[index++] = 0x00;
        TextLen = strlen((S8*) TextBuffer); /* JP */
    }

#elif defined(__MMI_SMART_MESSAGE_MT__)

    if (picmsg_text_struct.ucs2_count > 0)
    {
        /* text type */
        OtaText[index++] = 0x01;
        TextLen = (mmi_ucs2strlen((S8*) TextBuffer) * 2); /* JP */
    }
    else
    {
        /* text type */
        OtaText[index++] = 0x00;
        TextLen = strlen((S8*) TextBuffer); /* JP */
    }
#endif 

    /* text length */
    OtaText[index++] = (U8) ((TextLen & 0xff00) >> ONE_BYTE_SIZE);
    OtaText[index++] = (U8) (TextLen & 0x00ff);

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (picmsg_text_struct.ucs2_count > 0)
    {
#elif (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    if (g_nsm_msg_context.UCS2_count > 0)
    {
#endif 
        /* For Unicode text : Reverse bytes order for Nokia chinese problem */
        {
            U8 temp1 = 0;
            U8 temp2 = 0;
            U8 temparr[3] = {0, 0, 0};
            U16 count = 0;

            while (i < TextLen)
            {
                temp1 = TextBuffer[i];
                i++;
                temp2 = TextBuffer[i];
                i++;
                temparr[0] = temp2;
                temparr[1] = temp1;
                for (count = 0; count < 2; count++)
                {
                    OtaText[index++] = (U8) temparr[count];
                }

                /* Reset all temp variables */
                temp1 = 0;
                temp2 = 0;
                memset(temparr, 0x00, sizeof(temparr));
            }
        }
    }
    else
    {
        /* Only ascii text : DO not change bytes order */
        while (i < TextLen)
        {
            OtaText[index++] = (U8) TextBuffer[i];
            i++;
        }
    }

    mmi_pmsg_add_header(OtaText, index, OtaData, DataLen);
    OslMfree(OtaText);

    return (U16) (index + DataLen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_add_nokia_header
 * DESCRIPTION
 *  Prefix the Nokia Header on given Picture Message.
 * PARAMETERS
 *  PictureMessage      [?]         
 *  TotalSegment        [IN]        
 *  CurrentSegment      [IN]        
 *  OTA data ,Total Part & Part of Header (first, second or third ..)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pmsg_add_nokia_header(U8 *PictureMessage, U8 TotalSegment, U8 CurrentSegment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S16 NokiaTotalSegmentLocation = 21;
    const S16 NokiaCurrectSegmentLocation = 23;
    const S16 NokiaHeaderSize = 24;
    const S16 NokiaMaxSegments = 4;

    U8 NokiaHeader[MAX_NOKIA_HEADER_SIZE];
    U8 SegmentNumber[] = { '0', '1', '2', '3', '4' };
    U16 DataSize = strlen((S8*) PictureMessage);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((PictureMessage == NULL)
        || (TotalSegment > NokiaMaxSegments) || (CurrentSegment > NokiaMaxSegments) || (DataSize > 296))
    {
        return;
    }

    memset(NokiaHeader, 0x00, MAX_NOKIA_HEADER_SIZE);

    strcpy((S8*) NokiaHeader, (S8*) "0B0504158A00000003010301");

    NokiaHeader[NokiaTotalSegmentLocation] = SegmentNumber[TotalSegment];

    NokiaHeader[NokiaCurrectSegmentLocation] = SegmentNumber[CurrentSegment];

    mmi_pmsg_add_header(NokiaHeader, NokiaHeaderSize, PictureMessage, DataSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_convert_ascii_hex_string_2_dec_string
 * DESCRIPTION
 *  Convert the ascii string into Decimal string.
 * PARAMETERS
 *  DecStr          [?]     
 *  AsciiStr        [?]     
 *  Pointer to Dec string & Pointer to Ascii string.Ascii len must be even number.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pmsg_convert_ascii_hex_string_2_dec_string(U8 *DecStr, U8 *AsciiStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *AsciiStrPtr = AsciiStr;
    U8 *DecStrPtr = DecStr;
    U8 FirstVal = 0;
    U8 SecondVal = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (AsciiStrPtr == NULL)
    {
        return;
    }

    while (*AsciiStrPtr != '\0')
    {
        FirstVal = mmi_pmsg_convert_ascii_hex_to_dec(*AsciiStrPtr++);
        SecondVal = mmi_pmsg_convert_ascii_hex_to_dec(*AsciiStrPtr++);
        *DecStrPtr++ = ((FirstVal << 4) | (SecondVal));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_convert_dec_string_2_ascii_hex_string
 * DESCRIPTION
 *  Convert the Decimal string into ascii string.
 * PARAMETERS
 *  AsciiStr        [?]     
 *  DecStr          [?]     
 *  Pointer to Ascii string & Pointer to Dec string. Ascii string len must be double of Dec string.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pmsg_convert_dec_string_2_ascii_hex_string(U8 *AsciiStr, U8 *DecStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *AsciiStrPtr = AsciiStr;
    U8 *DecStrPtr = DecStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DecStrPtr == NULL)
    {
        return;
    }

    while (*DecStrPtr != '\0')
    {
        *AsciiStrPtr++ = mmi_pmsg_convert_binary_dec_to_hex(*DecStrPtr, PMSG_FIRST_FOUR_BITS);
        *AsciiStrPtr++ = mmi_pmsg_convert_binary_dec_to_hex(*DecStrPtr, PMSG_SECOND_FOUR_BITS);
        DecStrPtr++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_get_size_bmp_data
 * DESCRIPTION
 *  This fun find out the real size of Bmp data.
 * PARAMETERS
 *  BmpData     [?]     
 *  Pointer of BMP data MMI format.(?)
 * RETURNS
 *  Size of Bmp file.
 *****************************************************************************/
U16 mmi_pmsg_get_size_bmp_data(U8 *BmpData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 BmpDataSize = 0;
    S16 index = 2;
    U16 val[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    val[0] = (U16) BmpData[index++];
    val[1] = (U16) BmpData[index++];
    val[2] = (U16) BmpData[index++];
    val[3] = (U16) BmpData[index++];

    BmpDataSize = (U16) (val[3] << 24 | val[2] << 16 | val[1] << 8 | val[0]);

    return (BmpDataSize + MMI_EXTRA_BMP_HEADER_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_get_size_ota_data
 * DESCRIPTION
 *  This fun find out the real size of Ota Picture data.
 * PARAMETERS
 *  OtaBuffer       [?]     
 *  Pointer of Ota data .(?)
 * RETURNS
 *  Size of Ota Data.
 *****************************************************************************/
U16 mmi_pmsg_get_size_ota_data(U8 *OtaBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 OtaHeaderLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OtaHeaderLen = mmi_pmsg_read_picture_header(OtaBuffer);

    if (OtaHeaderLen == -1)
    {
        return 0;
    }

    return (U16) (gOtaDataLen + OtaHeaderLen) * 2 + 8;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_add_bmp_header_info
 * DESCRIPTION
 *  This fun added the BMP extra header info to show the Picture in UI.Prepared MMI format.
 * PARAMETERS
 *  BmpData     [?]     
 *  Pointer of BMP data .(?)
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_pmsg_add_bmp_header_info(U8 *BmpData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 HeaderInfo[16];
    U16 BmpDataSize = 0;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_pmsg_is_smart_picture(BmpData) == FALSE)
    {
        return -1;
    }

    memset(HeaderInfo, 0x00, 16);

    BmpDataSize = ((BmpData[2]) | (BmpData[3] << 8) | (BmpData[4] << 16) | (BmpData[5] << 24));
    HeaderInfo[index++] = 0x1;
    HeaderInfo[index++] = 0x0;
    HeaderInfo[index++] = (S8) ((BmpDataSize & 0x000000FF));
    HeaderInfo[index++] = (S8) ((BmpDataSize & 0x0000FF00) >> 8);
    HeaderInfo[index++] = (S8) ((BmpDataSize & 0x00FF0000) >> 16);
    HeaderInfo[index++] = (S8) ((BmpDataSize & 0xFF000000) >> 24);

    mmi_pmsg_add_header((U8*) HeaderInfo, index, (U8*) BmpData, BmpDataSize);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pmsg_is_smart_picture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  BmpData     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_pmsg_is_smart_picture(U8 *BmpData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = 0, num_colors = 0;
    U8 height;
    U8 width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((BmpData[index++] != 'B') || (BmpData[index++] != 'M'))
    {
        PRINT_INFORMATION("It is not a bitmap file.\n");
        return FALSE;
    }

    /* Start : JP check of height and width NSM picture */
    index += 16;    /* Hack */

    width = BmpData[index];

    if ((width > MAX_NSM_PIC_WIDTH) || (width == 0))    /* Width is greater then 72 */
    {
        return FALSE;
    }

    index += 4; /* Hack */
    height = BmpData[index];

    if ((height > MAX_NSM_PIC_HEIGHT) || (height == 0)) /* Height is greater then 72 */
    {
        return FALSE;
    }
    /* index += 40; */
    /* End : JP check of height and width NSM picture */
    index += 20;

    num_colors = BmpData[index++];
    num_colors |= BmpData[index++] << ONE_BYTE_SIZE;

    if (num_colors > 1)
    {
        PRINT_INFORMATION("It is a multi color bitmap file.\n");
        num_colors = 1; /* JP for tracker issue 20050628 */
        /* return FALSE; */
    }
    return TRUE;
}
#endif /* _MMI_PICMSG_C */ /* if include picmsg_c */
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

