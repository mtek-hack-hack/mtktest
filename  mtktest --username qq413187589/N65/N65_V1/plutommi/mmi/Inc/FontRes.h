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
 *  FontRes.h
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

#ifndef _FONTRES_H_
#define _FONTRES_H_

#include "MMIDataType.h"
// #include "FontData.h"
#include "MMI_features.h"

//#define SMALL_FONT  1
//#define MEDIUM_FONT 2
//#define LARGE_FONT  3
#ifdef __UCS2_ENCODING
#define LANGUAGE_NAME 40
#else 
#define LANGUAGE_NAME 20
#endif 

#define  SSC_SIZE 10
#define  LCC_SIZE 8
// #define MAX_LANGUAGES 2

#define  MAX_FONT_TYPES      6
#define  SMALL_FONT        0x0000
#define  MEDIUM_FONT    0x0001
#define  LARGE_FONT        0x0002
#define  SUBLCD_FONT    0x0003
#define  DIALER_FONT    0x0004
#define  VIRTUAL_KEYBOARD_FONT      0x0005

#define  NORMAL_DISPLAY_FONT                    0x80000000
#define  SMALLCAPS_DISPLAY_FONT                 0x40000000

#define  FONTATTRIB_NORMAL                   0x00000001
#define  FONTATTRIB_BOLD                        0x00000002
#define  FONTATTRIB_ITALIC                      0x00000004
#define  FONTATTRIB_OBLIQUE                     0x00000008
#define  FONTATTRIB_UNDERLINE                   0x00000010
#define  FONTATTRIB_STRIKETHROUGH               0x00000020

#define  MAX_FONTS_DATA       6
#define  MAX_FONT_FAMILIES    6

typedef struct Range
{
    U32 nMin;
    U32 nMax;
} RangeData;

typedef struct RangeInfo
{
    U16 nNoOfRanges;
    const RangeData *pRangeData;

} RangeDetails;

typedef struct _CustFontData
{
    U8 nHeight;
    U8 nWidth;
    U8 nAscent;
    U8 nDescent;
    U8 nEquiDistant;
    U8 nCharBytes;
    U16 nMaxChars;
#ifdef __MMI_INDIC_ALG__
    U8 *pDWidthArray;   /* vijay added during merge */
#endif 
    U8 *pWidthArray;
    U32 *pOffsetArray;
    U8 *pDataArray;
    U32 *pRange;
    U16 pFontType[MAX_FONT_TYPES][2];
    const RangeDetails *pRangeDetails;
} sCustFontData;

typedef struct _FontFamily
{
    U16 nTotalFonts;
    sCustFontData *fontData[MAX_FONTS_DATA];
} sFontFamily;

typedef struct _LanguageDetails
{
    U8 aName[LANGUAGE_NAME];
    U8 aLangSSC[SSC_SIZE];
    U8 nCurrentFamily;
    sFontFamily *fontfamilyList[MAX_FONT_FAMILIES];
    U8 aLangCountryCode[LCC_SIZE];
} sLanguageDetails;

/* sLanguageDetails gLanguageArray[MAX_LANGUAGES]; */

#endif /* _FONTRES_H_ */ 

