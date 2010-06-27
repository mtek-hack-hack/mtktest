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
 *  GSM7BitDefaultAlphabet.h
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
/**************************************************************

   FILENAME : GSM7BitDefaultAlphabet.h

   PURPOSE     : .

   REMARKS     : .

   AUTHOR      : .

   DATE     : 11-07-03

**************************************************************/

#ifndef _PIXCOM_GSM_7BIT_DEFAULT_ALPHABET_H
#define _PIXCOM_GSM_7BIT_DEFAULT_ALPHABET_H

#include "MMIDataType.h"

#define GSM_7BIT_DEFAULT_ALPHABET_DEBUG   1

#ifndef OSL_MEMORY_DUMP
extern U8 *CovertStringForPlatform(U8 *data, U16 len, U8 format, U16 *outLen);
extern U8 *CovertStringForSIM(U8 *data, U16 len, U8 format, U16 *outLen);
#else /* OSL_MEMORY_DUMP */ 
extern U8 *CovertStringForPlatformInt(U8 *data, U16 len, U8 format, U16 *outLen, S8 *fileName, S32 lineNumber);
extern U8 *CovertStringForSIMInt(U8 *data, U16 len, U8 format, U16 *outLen, S8 *fileName, S32 lineNumber);

#define CovertStringForPlatform(data,len,format,outLen) CovertStringForPlatformInt(data,len,format,outLen,__FILE__,__LINE__)
#define CovertStringForSIM(data,len,format,outLen) CovertStringForSIMInt(data,len,format,outLen,__FILE__,__LINE__)
#endif /* OSL_MEMORY_DUMP */ 

extern U8 ConvertDigitToChar(U8 digit);
extern void *SwapEndian(void *Addr, const int Nb);
extern U8 *ConvertBCDToString(U8 *BCDNumber, U16 len, U16 *outLen);

extern void ConvertGSM7BitDefaultEncodingToAscii(U8 *message, U8 *msg, U16 length, U16 *outLen);
extern void ConvertAsciiEncodingToGSM7BitDefault(U8 *message, U8 *msg, U16 length, U16 *outLen);
extern U8 GSM7BitMapDefaultToASCIIByte(U8 input);
extern U8 GSM7BitMapASCIIToDefaultByte(U8 input);

typedef enum
{
    MMI_DEFAULT_DCS = 0x00, /* GSM 7-bit */
    MMI_8BIT_DCS = 0x04,    /* 8-bit */
    /* micha1008 */
    MMI_UCS2_DCS = 0x08,    /* UCS2 */
    MMI_UCS2_81 = 0x09,     /* Add for extra handle for UCS2 0x81 */
    MMI_UCS2_82 = 0x10      /* Add for extra handle for UCS2 0x82 */
} MMIDCSENUM;

extern S32 InputboxConvertGSMToDeviceEncoding(
            U8 *inBuffer,
            U8 *outBuffer,
            U8 inBufferLength,
            S32 outBufferSize,
            S32 UCS2_count,
            S32 GSM_ext_count,
            U8 flag);
extern S32 InputboxConvertDeviceEncodingToGSM(
            U8 *inBuffer,
            U8 *outBuffer,
            S32 outBufferSize,
            S32 UCS2_count,
            S32 GSM_ext_count,
            U8 flag);

#endif /* _PIXCOM_GSM_7BIT_DEFAULT_ALPHABET_H */ 

