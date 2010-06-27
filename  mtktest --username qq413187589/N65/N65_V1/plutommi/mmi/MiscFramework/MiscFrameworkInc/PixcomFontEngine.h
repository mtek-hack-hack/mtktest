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
 *  PixcomFontEngine.h
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

   FILENAME : PixcomFontengine.h

   PURPOSE     : Fontengine header

   REMARKS     : nil

   AUTHOR      : Anku Jain and Arun Gupta

   DATE     : May 25, 2002

**************************************************************/

#include "MMIDataType.h"

#ifndef _PIXCOMFONTENGINE_H
#define _PIXCOMFONTENGINE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "MMI_features.h"

    /* to check the control chars */
    /* add 0x0A,0x0D~0x0F for displaying control characters as space */
    /* add 0xA0 for NBSP in Vietnamese as space */
#define FONT_TEST_CONTROL_CHAR(c)      \
(     (c=='\t'/* 0x09 */)                \
   || (c==0x08)                        \
   || (c==0x0A)                        \
   || (c==0x0D)                        \
   || (c==0x0E)                        \
   || (c==0x0F)                        \
   || (c==0xA0)                        \
)

#define FONT_TEST_FORMATTING_CHARS(c)   ((c) >= 0x200C && (c)<= 0x200f)    
#define FONT_TEST_DATE_CHARS(c)   ((c) >= 0x87 && (c)<= 0x93)    
#define FONT_TEST_CRLF_ANF_SPACE_PROPRIETARY_SYMBOL(c) ((c) >= 133 & (c)<=134) /* for new line and space symbol used in symbol table */
#define FONT_TEST_SPACE_CHAR(c) ((c) >= 0x2000 && (c)<= 0x200B)
#define FONT_TEST_ZERO_WIDTH_SPACE(c) ((c) == 0x200B)

    /* for R2L characters */
#define MAX_SHOW_STRING_TEXT_LENGTH          700
#define MAX_NUM_OF_CHAR_FOR_EACH_LINE         ((UI_DEVICE_WIDTH/2)*2) /*(in bytes).  assume LCD width fill with 1 pixel text and 1 pixel gap */

#define FONT_TEST_BIDI_CONTROL_CHAR(c) ((c==0x06)||(c==0x07)||(c==0x08)||(c==0x09)||(c==0x0A)||(c==0x0D))
#define FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(c) (c == 0x20 ? 1:0)
#define FONT_TEST_ASCII_CHARACTER(c)   (((UI_character_type)(c)<=(UI_character_type)0xFF)?(1):(0))

    typedef struct stFontAttribute
    {
        U8 bold;
        U8 italic;
        U8 underline;
        U8 size;
        U8 color;
        U8 type;
        U8 oblique;
        U8 smallCaps;
    }
    stFontAttribute;

    /* for R2L characters */
    typedef struct stL2RLangSSC
    {
        S8 *sscString;
    } L2RLangSSC;
typedef enum
{
    MMI_FONT_ENGINE_NO_ERROR = 0,
    MMI_FONT_ENGINE_NO_TRUNCATION,
    MMI_FONT_ENGINE_TRUNCATION,
    MMI_FONT_ENGINE_ERROR_NULL_STRING,
    MMI_FONT_ENGINE_ZERO_LENGTH,
    MMI_FONT_ENGINE_ERROR_NO_TRUNCATION_AVAILABLE,
    MMI_FONT_ENGINE_END_OF_ENUM
} mmi_font_engine_error_message_enum;

/* Begin: For Font Cache */
#ifndef LOW_COST_SUPPORT
#define __MMI_FONT_CACHE_SUPPORT__
#endif

#ifdef __MMI_FONT_CACHE_SUPPORT__
#define LATIN_CHAR_HT_SIZE 		128
#define LATIN_CHAR_HT_MASK		0x007f
#define OTHERS_CHAR_HT_SIZE 	256
#define OTHERS_CHAR_HT_MASK		0x00ff
#else
#define LATIN_CHAR_HT_SIZE 		2
#define LATIN_CHAR_HT_MASK		0x0001
#define OTHERS_CHAR_HT_SIZE 	2
#define OTHERS_CHAR_HT_MASK		0x0001
#endif

    typedef struct
    {
        U32 unicode;
        U16 Width;
        U16 Height;
        U16 Ascent;
        U16 Descent;
        U8 *CharData;
        U32 NumChar;
        U8 count;
        U32 gnCurrentFont;
        S32 index;
    #ifdef __MMI_INDIC_ALG__
        U16 DWidth;
    #endif 
    } CharHashTable;
    /* End: For Font Cache */

    /* --------------------------- Public Functions and Variables ------------------------- */

    extern void TestDiffFonts(void);

    /* -------------------------- Private Functions and Variables ------------------------- */

    //static U32 GetFontdata(U32 Ch, stFontAttribute Font, U8 *CharData);
    //static void SetTilt(void);

    /* Public functions                                        */

    extern void Get_CharWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight);
    extern void Get_CharBoundingBox(
                    U32 Ch,
                    S32 *pCharWidth,
                    S32 *pCharHeight,
                    S32 *pBoxXoffset,
                    S32 *pBoxYoffset,
                    S32 *pBoxWidth,
                    S32 *pBoxHeight);
    extern U32 Get_CharNumInWidth(U8 *String, U32 width, U8 checklinebreak);
    extern U32 Get_CharNumInWidth_w(U8 *String, U32 width, U8 checklinebreak, U32 gap);
    extern U32 Get_CharNumInWidth_internal(U8 *String, U32 width, U8 checklinebreak, U32 gap);
    extern S32 Get_CharHeight(void);
    extern S32 Get_CharAscent(void);
    extern S32 Get_CharDescent(void);
    extern S32 Get_CharHeightOfAllLang(U8 size);
    extern void Get_StringWidthHeight(U8 *String, S32 *pWidth, S32 *pHeight);
    extern void Get_StringWidthHeight_n(U8 *String, S32 n, S32 *pWidth, S32 *pHeight);
    extern void Get_StringWidthHeight_w(U8 *String, S32 w, S32 *pWidth, S32 *pHeight);
    extern U8 *Get_Current_Lang_CountryCode(void);
    extern S32 Get_CharDisplayHeightOfAllLangAndType(U8 size);
    extern S32 Get_CharDisplayAscentOfAllType(void);
    extern S32 Get_CharDisplayDescentOfAllType(void);
    extern S32 Get_CharDisplayHeightofAllType(void);
    /* PMT dara added for Multitap thai */
    extern void Get_StringWidthHeight_multitap(U8 *String, S32 w, S32 *pWidth, S32 *pHeight);
    extern U32 Get_StringWidthHeight_variant(U8 *string, S32 w, S32 n, S32 *pWidth, S32 *pHeight, S32 max_width);

    extern void Get_StringWidthHeight_wn(U8 *String, S32 w, S32 n, S32 *pWidth, S32 *pHeight);
    extern U32 Get_StringWidthHeight_internal(
                    U8 *String, 
                    S32 w, 
                    S32 n, 
                    S32 *pWidth, 
                    S32 *pHeight,
                    MMI_BOOL enableTruncated,
                    S32 targetWidth, 
                    U8 checklinebreak, 
                    S32* baseline);
    extern S32 Get_StringHeight(void);
    extern U8 SetFont(stFontAttribute Font, U8);
    extern void GetFont(stFontAttribute *Font, U8* arrCount);
    /* static void  ShowChar(U32 LineHeight, U32 x, U32 y, stFontAttribute Font, U8 Background, U8 *CharData, U32 NumChar); */
    extern U32 ShowString(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight);
    extern U32 ShowString_n(
                U32 x_unsigned,
                U32 y_unsigned,
                stFontAttribute Font,
                U8 BackGround,
                U8 *String,
                int Len,
                U32 LineHeight);
    extern U32 ShowStringBordered(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight);
    extern U32 ShowStringBordered_n(
                U32 x_unsigned,
                U32 y_unsigned,
                stFontAttribute Font,
                U8 BackGround,
                U8 *String,
                int Len,
                U32 LineHeight);
    extern U32 ShowString_baseline(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, S32 baseline, U8 default_direction);
    extern U32 ShowStringBordered_baseline(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, S32 baseline, U8 default_direction);
    extern U32 ShowStringBordered_by_direction(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight, U8 default_direction);
    extern U32 ShowString_by_direction(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight, U8 default_direction);

    extern void GetLangIndex(U8 *pCount, S32 *pnFontIndex, S32 *pnIndex, U32 nCh, U32 *pnBase);
    extern S32 SearchIndexinList(U8 nListIndex, U16 nFontCount, U32 nCh, U32 *pnBase);
    extern S32 SearchInPropFont(U32 nCh, U32 *pnBase);
    extern S32 Get_PropWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent);

    extern S32 Get_FontHeight(stFontAttribute Font, U8 arrCount);
    extern U32 Get_StringLength_InCluster(U8* input_str, U32 len, U32 base_len);

    /* for stacked Display */
    extern BOOL RequireToMoveCursor(U16 preCh, U16 curCh);
    extern U32 ShowStackedString(
                S32 CurrentX,
                S32 CurrentY,
                stFontAttribute Font,
                U8 BackGround,
                U8 *String,
                U32 LineHeight,
                MMI_BOOL Bordered,
                S32 len,
                MMI_BOOL enableTruncated,
                U8 *truncated_symbol,
                S32 xwidth_boundary,
                U8 assign_direction);
    extern void ShowStackedChar(
                    S32 CurrentX,
                    S32 CurrentY,
                    stFontAttribute Font,
                    U8 BackGround,
                    U16 curCh,
                    U32 LineHeight,
                    U32 Bordered,
                    U16 pre2Ch,
                    U16 preCh);

    /* for R2L characters */
    extern BOOL IsL2RMMIStyle(void);
    extern mmi_font_engine_error_message_enum mmi_font_engine_show_truncated_text(
                S32 x, 
                S32 y,
                S32 xwidth, 
                U8* st, 
                U8* truncated_symbol, 
                stFontAttribute Font,
                U8 BackGround,
                U32 LineHeight, 
                MMI_BOOL bordered);
    extern void mmi_fe_show_char_at_xy(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U16 ch);
    extern void mmi_fe_enable_date_char_display(void);
    extern void mmi_fe_disable_date_char_display(void);
    extern void mmi_fe_enable_proprietary_symbol_display(void);
    extern void mmi_fe_disable_proprietary_symbol_display(void);
    extern void mmi_fe_measure_string_by_char_num(U8* st, S32 numofchar, S32* width, S32* height);

#ifdef __cplusplus
}
#endif 

#endif /* _PIXCOMFONTENGINE_H */ 

/*-----------------------------------------------------------------------*/
/*--------------------------- *** End *** -------------------------------*/
/*-----------------------------------------------------------------------*/

