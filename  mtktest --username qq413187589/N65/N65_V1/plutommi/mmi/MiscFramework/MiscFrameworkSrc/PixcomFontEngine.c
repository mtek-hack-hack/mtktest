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
 *    pixcomfontengine.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   font engine related function calls
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
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*  Include
*****************************************************************************/
#include "MMI_include.h"
#include <signal.h>
#include "FontData.h"
#include "gui_data_types.h"

#ifdef __MMI_MAINLCD_240X320__

#include "MTKPropFont20.h"
#if defined(__MMI_ZI__)

#if defined(__MMI_ZI_V7__)
#include "ZiV7ExtraCharacter20.h"
#else 
#include "ZiExtraCharacter20.h"
#endif 

#endif /* defined(__MMI_ZI__) */ 

#else /* __MMI_MAINLCD_240X320__ */ 

#include "MTKPropFont.h"
#if defined(__MMI_ZI__)
#if defined(__MMI_ZI_V7__)
#include "ZiV7ExtraCharacter14.h"
#else 
#include "ZiExtraCharacter.h"
#endif 
#endif /* defined(__MMI_ZI__) */ 

#endif /* __MMI_MAINLCD_240X320__ */ 
#ifdef __MMI_ARSHAPING_ENGINE__
#include "ArabicGProt.h"
#endif 

#include "gui.h"
#include "PixcomFontEngine.h"

/* For Langauge */
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif /* __MMI_INDIC_ALG__ */ 

#ifdef __MMI_ARSHAPING_ENGINE__
#include "ArabicGProt.h"
#endif 

#ifdef __MMI_LANG_VIETNAMESE__
#include "gui_lang_viet.h"
#endif 

#include "BIDIDEF.h"
#include "BIDIGProt.h"


#if defined(__MMI_LANG_THAI__)
#include "ThaiGProt.h"
#endif

#include "ATHandlerProt.h"
#include "SSCStringHandle.h"
#include "BIDIDEF.h"
#include "BIDIGProt.h"
#include "UCS2Prot.h"
#include "Gdi_font.h"
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
#endif


/*****************************************************************************
*  Define
*****************************************************************************/
#define FONTENGINE_IRAM_PLACEMENT   0
#define BORDERED_TEXT_NO_BOUNDARY 1     /* MTK justin */

/* transparent color (blue) */
#define TRANSPARENT_COLOR_R 0
#define TRANSPARENT_COLOR_G 0
#define TRANSPARENT_COLOR_B 0xff
#define FE_DISPLAY_FLAG_DATE_CHAR  0x01
#define FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR  0x02

/*****************************************************************************
*  Global Variables
*****************************************************************************/
U8 gnCurrentFontAttrib = FONTATTRIB_NORMAL;
U8 gbFontType = 0;
static U32 fe_display_flag = 0;

U32 gThaiLineHeight = 17;

void SetFontValues(U32 nFont, U8 arrCount);

/* extern sLanguageDetails gLanguageArray[MAX_LANGUAGES]; */
extern sLanguageDetails *gLanguageArray;
extern void gdi_font_begin(gdi_color fg_color, U8 font_attr);
extern void gdi_font_end(void);

/* MTK steven for removing compile warnings */
extern void gdi_show_char_bordered(
                S32 x,
                S32 y,
                gdi_color text_color,
                gdi_color border_color,
                U8 *font_data,
                U32 font_data_size,
                U16 char_width,
                U16 char_height,
                U8 font_attr);
extern void gdi_show_char(
                S32 x,
                S32 y,
                gdi_color color,
                U8 *font_data,
                U32 font_data_size,
                U16 char_width,
                U16 char_height,
                U8 font_attr);

extern BOOL r2lMMIFlag;

#ifdef __MMI_BIDI_ALG__
extern U8 MMI_bidi_input_type;
U16 show_pwcWord[MAX_SHOW_STRING_TEXT_LENGTH];
U8 show_visual_str[MAX_SHOW_STRING_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
#endif /* __MMI_BIDI_ALG__ */ 
#ifdef __MMI_ARSHAPING_ENGINE__
static U16 fe_ShaToOrg[MAX_SHOW_STRING_TEXT_LENGTH];
#endif 


#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
extern MMI_BOOL mmi_trace_screen_string(S32 x, S32 y, U8 *str, S32 len, S32 Bordered);
extern MMI_BOOL mmi_trace_screen_char(S32 x, S32 y, U16 unicode, S32 len, S32 Bordered);
#endif


/* For Font Cache */
CharHashTable charHashTableLatin[LATIN_CHAR_HT_SIZE];
CharHashTable charHashTableOthers[OTHERS_CHAR_HT_SIZE];

#ifdef __MMI_MAINLCD_240X320__

const RangeData gMTKProprietaryFont_RangeData[45]={
{2,2},
{108,108},
{133,134},
{331,331},
{593,593},
{596,596},
{601,603},
{609,609},
{618,618},
{643,643},
{650,650},
{652,652},
{658,658},
{711,711},
{714,716},
{719,719},
{729,729},
{7747,7747},
{7751,7751},
{8213,8213},
{8216,8217},
{8220,8221},
{8230,8231},
{8242,8243},
{8245,8246},
{8248,8251},
{8260,8260},
{8364,8364},
{8482,8482},
{12289,12290},
{12298,12303},
{61440,61442},
{61444,61445},
{61447,61447},
{62464,62467},
{62469,62505},
{62720,62725},
{65104,65104},
{65106,65106},
{65108,65111},
{65113,65114},
{65124,65124},
{65281,65374},
{65377,65380},
{65515,65515},
};

const RangeDetails gMTKProprietaryFont_RangeInfo={
45,
gMTKProprietaryFont_RangeData
};

sCustFontData gMTKProprietaryFont = 
{
    20, 20, 17, 3, 0, 50, 500,
#ifdef __MMI_INDIC_ALG__
    (U8 *) NULL,
#endif 
    (U8 *) MTKProprietaryFont20_Width, (U32 *) MTKProprietaryFont20_Offset, (U8 *) MTKProprietaryFont20_Data,
        (U32 *) MTKProprietaryFont20_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gMTKProprietaryFont_RangeInfo
};

#if defined(__MMI_ZI__)

#if defined(__MMI_ZI_V7__)

const RangeData gZiExtraCharacter_RangeData[162] = 
{
    {61184, 61192},
    {61200, 61201},
    {61203, 61203},
    {61206, 61206},
    {61209, 61209},
    {61214, 61214},
    {61217, 61228},
    {61230, 61231},
    {61233, 61238},
    {61243, 61247},
    {61249, 61254},
    {61256, 61256},
    {61259, 61260},
    {61264, 61264},
    {61268, 61270},
    {61274, 61274},
    {61276, 61280},
    {61282, 61282},
    {61287, 61287},
    {61289, 61291},
    {61293, 61293},
    {61295, 61300},
    {61302, 61319},
    {61321, 61322},
    {61324, 61330},
    {61332, 61333},
    {61335, 61337},
    {61339, 61339},
    {61342, 61342},
    {61346, 61347},
    {61349, 61352},
    {61354, 61354},
    {61357, 61358},
    {61360, 61360},
    {61364, 61365},
    {61367, 61367},
    {61369, 61371},
    {61373, 61373},
    {61375, 61376},
    {61378, 61378},
    {61382, 61384},
    {61386, 61386},
    {61389, 61389},
    {61392, 61393},
    {61396, 61396},
    {61399, 61399},
    {61401, 61403},
    {61406, 61407},
    {61411, 61411},
    {61413, 61416},
    {61418, 61418},
    {61421, 61421},
    {61424, 61424},
    {61427, 61427},
    {61431, 61431},
    {61435, 61435},
    {61437, 61442},
    {61445, 61445},
    {61447, 61448},
    {61450, 61450},
    {61452, 61452},
    {61455, 61461},
    {61464, 61464},
    {61466, 61468},
    {61470, 61470},
    {61472, 61474},
    {61477, 61477},
    {61479, 61485},
    {61487, 61487},
    {61491, 61491},
    {61493, 61493},
    {61496, 61498},
    {61501, 61502},
    {61504, 61504},
    {61508, 61509},
    {61511, 61517},
    {61523, 61523},
    {61525, 61525},
    {61530, 61530},
    {61532, 61535},
    {61538, 61538},
    {61540, 61540},
    {61542, 61542},
    {61544, 61545},
    {61547, 61551},
    {61553, 61558},
    {61561, 61561},
    {61563, 61564},
    {61566, 61566},
    {61568, 61568},
    {61570, 61571},
    {61574, 61575},
    {61578, 61582},
    {61586, 61587},
    {61589, 61591},
    {61594, 61595},
    {61597, 61598},
    {61600, 61600},
    {61605, 61606},
    {61609, 61611},
    {61624, 61626},
    {61633, 61633},
    {61635, 61635},
    {61637, 61637},
    {61642, 61642},
    {61656, 61656},
    {61663, 61663},
    {61685, 61685},
    {61688, 61688},
    {61691, 61692},
    {61695, 61695},
    {61703, 61704},
    {61708, 61709},
    {61713, 61713},
    {61715, 61715},
    {61718, 61718},
    {61732, 61732},
    {61743, 61743},
    {61750, 61750},
    {61752, 61752},
    {61754, 61755},
    {61760, 61760},
    {61762, 61762},
    {61764, 61765},
    {61769, 61772},
    {61775, 61775},
    {61787, 61787},
    {61791, 61791},
    {61793, 61793},
    {61795, 61796},
    {61801, 61801},
    {61811, 61811},
    {61815, 61816},
    {61823, 61823},
    {61825, 61825},
    {61836, 61837},
    {61844, 61844},
    {61850, 61850},
    {61872, 61872},
    {61878, 61878},
    {61915, 61915},
    {61924, 61924},
    {61926, 61927},
    {61930, 61930},
    {61938, 61938},
    {61969, 61969},
    {61979, 61979},
    {61989, 61989},
    {61995, 61995},
    {62041, 62041},
    {62043, 62043},
    {62046, 62047},
    {62051, 62051},
    {62067, 62067},
    {62080, 62080},
    {62084, 62084},
    {62090, 62090},
    {62095, 62095},
    {62098, 62098},
    {62213, 62249},
    {62257, 62261},
    {62305, 62330},
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    162,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    20, 20, 17, 3, 0, 50, 500,
#ifdef __MMI_INDIC_ALG__
    (U8 *) NULL,
#endif 
    (U8 *) ZiV7ExtraCharacter20_Width, (U32 *) ZiV7ExtraCharacter20_Offset, (U8 *) ZiV7ExtraCharacter20_Data,
    (U32 *) ZiV7ExtraCharacter20_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};

#else /* defined(__MMI_ZI_V7__) */ 

const RangeData gZiExtraCharacter_RangeData[5] = 
{
    {61440, 61448},
    {61456, 62398},
    {62469, 62505},
    {62513, 62517},
    {62561, 62586},
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    5,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    20, 20, 17, 3, 0, 50, 500,
#ifdef __MMI_INDIC_ALG__
    (U8 *) NULL,
#endif 
    (U8 *) ZiExtraCharacter20_Width, (U32 *) ZiExtraCharacter20_Offset, (U8 *) ZiExtraCharacter20_Data,
        (U32 *) ZiExtraCharacter20_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};
#endif /* defined(__MMI_ZI_V7__) */ 

#endif /* defined(__MMI_ZI__) */ 

#else /* __MMI_MAINLCD_240X320__ */ /* not defined __MMI_MAINLCD_240X320__ */

const RangeData gMTKProprietaryFont_RangeData[46]={
{2,2},
{133,134},
{230,230},
{240,240},
{331,331},
{593,593},
{596,596},
{601,603},
{609,609},
{618,618},
{643,643},
{650,650},
{652,652},
{658,658},
{711,711},
{714,716},
{719,719},
{729,729},
{7735,7735},
{7747,7747},
{7751,7751},
{8213,8213},
{8216,8217},
{8220,8221},
{8230,8231},
{8242,8243},
{8245,8246},
{8248,8251},
{8260,8260},
{8364,8364},
{8482,8482},
{12289,12290},
{12298,12303},
{61440,61442},
{61444,61445},
{61447,61447},
{62464,62467},
{62720,62725},
{65104,65104},
{65106,65106},
{65108,65111},
{65113,65114},
{65124,65125},
{65281,65374},
{65377,65380},
{65515,65515},
};

const RangeDetails gMTKProprietaryFont_RangeInfo=
{
46,
gMTKProprietaryFont_RangeData
};

sCustFontData gMTKProprietaryFont = 
{
    14, 14, 12, 2, 0, 25, 500,
#ifdef __MMI_INDIC_ALG__
    (U8 *) NULL,
#endif 
    (U8 *) MTKProprietaryFont_Width, (U32 *) MTKProprietaryFont_Offset, (U8 *) MTKProprietaryFont_Data,
        (U32 *) MTKProprietaryFont_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gMTKProprietaryFont_RangeInfo
};

#if defined(__MMI_ZI__)

#if defined(__MMI_ZI_V7__)

const RangeData gZiExtraCharacter_RangeData[162] = 
{
    {61184, 61192},
    {61200, 61201},
    {61203, 61203},
    {61206, 61206},
    {61209, 61209},
    {61214, 61214},
    {61217, 61228},
    {61230, 61231},
    {61233, 61238},
    {61243, 61247},
    {61249, 61254},
    {61256, 61256},
    {61259, 61260},
    {61264, 61264},
    {61268, 61270},
    {61274, 61274},
    {61276, 61280},
    {61282, 61282},
    {61287, 61287},
    {61289, 61291},
    {61293, 61293},
    {61295, 61300},
    {61302, 61319},
    {61321, 61322},
    {61324, 61330},
    {61332, 61333},
    {61335, 61337},
    {61339, 61339},
    {61342, 61342},
    {61346, 61347},
    {61349, 61352},
    {61354, 61354},
    {61357, 61358},
    {61360, 61360},
    {61364, 61365},
    {61367, 61367},
    {61369, 61371},
    {61373, 61373},
    {61375, 61376},
    {61378, 61378},
    {61382, 61384},
    {61386, 61386},
    {61389, 61389},
    {61392, 61393},
    {61396, 61396},
    {61399, 61399},
    {61401, 61403},
    {61406, 61407},
    {61411, 61411},
    {61413, 61416},
    {61418, 61418},
    {61421, 61421},
    {61424, 61424},
    {61427, 61427},
    {61431, 61431},
    {61435, 61435},
    {61437, 61442},
    {61445, 61445},
    {61447, 61448},
    {61450, 61450},
    {61452, 61452},
    {61455, 61461},
    {61464, 61464},
    {61466, 61468},
    {61470, 61470},
    {61472, 61474},
    {61477, 61477},
    {61479, 61485},
    {61487, 61487},
    {61491, 61491},
    {61493, 61493},
    {61496, 61498},
    {61501, 61502},
    {61504, 61504},
    {61508, 61509},
    {61511, 61517},
    {61523, 61523},
    {61525, 61525},
    {61530, 61530},
    {61532, 61535},
    {61538, 61538},
    {61540, 61540},
    {61542, 61542},
    {61544, 61545},
    {61547, 61551},
    {61553, 61558},
    {61561, 61561},
    {61563, 61564},
    {61566, 61566},
    {61568, 61568},
    {61570, 61571},
    {61574, 61575},
    {61578, 61582},
    {61586, 61587},
    {61589, 61591},
    {61594, 61595},
    {61597, 61598},
    {61600, 61600},
    {61605, 61606},
    {61609, 61611},
    {61624, 61626},
    {61633, 61633},
    {61635, 61635},
    {61637, 61637},
    {61642, 61642},
    {61656, 61656},
    {61663, 61663},
    {61685, 61685},
    {61688, 61688},
    {61691, 61692},
    {61695, 61695},
    {61703, 61704},
    {61708, 61709},
    {61713, 61713},
    {61715, 61715},
    {61718, 61718},
    {61732, 61732},
    {61743, 61743},
    {61750, 61750},
    {61752, 61752},
    {61754, 61755},
    {61760, 61760},
    {61762, 61762},
    {61764, 61765},
    {61769, 61772},
    {61775, 61775},
    {61787, 61787},
    {61791, 61791},
    {61793, 61793},
    {61795, 61796},
    {61801, 61801},
    {61811, 61811},
    {61815, 61816},
    {61823, 61823},
    {61825, 61825},
    {61836, 61837},
    {61844, 61844},
    {61850, 61850},
    {61872, 61872},
    {61878, 61878},
    {61915, 61915},
    {61924, 61924},
    {61926, 61927},
    {61930, 61930},
    {61938, 61938},
    {61969, 61969},
    {61979, 61979},
    {61989, 61989},
    {61995, 61995},
    {62041, 62041},
    {62043, 62043},
    {62046, 62047},
    {62051, 62051},
    {62067, 62067},
    {62080, 62080},
    {62084, 62084},
    {62090, 62090},
    {62095, 62095},
    {62098, 62098},
    {62213, 62249},
    {62257, 62261},
    {62305, 62330},
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    162,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    14, 14, 12, 2, 0, 25, 500,
#ifdef __MMI_INDIC_ALG__
    (U8 *) NULL,
#endif 
    (U8 *) ZiV7ExtraCharacter14_Width, (U32 *) ZiV7ExtraCharacter14_Offset, (U8 *) ZiV7ExtraCharacter14_Data,
    (U32 *) ZiV7ExtraCharacter14_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};

#else /* defined(__MMI_ZI_V7__) */ 
const RangeData gZiExtraCharacter_RangeData[5] = 
{
    {322, 322},
    {341, 341},
    {352, 352},
    {61440, 61448},
    {61456, 62398},
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    5,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    14, 14, 12, 2, 0, 25, 500,
#ifdef __MMI_INDIC_ALG__
    (U8 *) NULL,
#endif 
    (U8 *) ZiExtraCharacter_Width, (U32 *) ZiExtraCharacter_Offset, (U8 *) ZiExtraCharacter_Data,
        (U32 *) ZiExtraCharacter_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};
#endif /* defined(__MMI_ZI_V7__) */ 

#endif /* defined(__MMI_ZI__) */ 

#endif /* __MMI_MAINLCD_240X320__ */ 


U32 gnCurrentFont;
sCustFontData *gpCurrentFont = NULL;
extern U16 gMaxDeployedLangs;
extern U16 gCurrLangIndex;

/*****************************************************************************
*  Global Function
*****************************************************************************/
#ifndef __MMI_LANG_THAI__
static U32 ShowString_internal(
                    S32 x, 
                    S32 y, 
                    stFontAttribute Font, 
                    U8 BackGround, 
                    U8 *String, 
                    S32 len, 
                    S32 BaseLineHeight,
                    U32 Bordered,
                    MMI_BOOL enable_truncated,
                    U8 *truncated_symbol, 
                    S32 xwidth_boundary,
                    U8 assign_direction);

#endif
U32 Get_StringWidthHeight_internal(
            U8 *String, 
            S32 w, 
            S32 n, 
            S32 *pWidth, 
            S32 *pHeight,
            MMI_BOOL enableTruncated,
            S32 targetWidth,
            U8 checklinebreak,
            S32 *baseline);

void SetFontValues(U32 nFont, U8 arrCount);



U8 mmi_ucs2_to_wc(PU16 pUnicode, PU8 arr);

/**************************************************************/
extern void text_drawpixel2(S32 x, S32 y);
extern color UI_current_text_color;
extern color UI_text_border_color;

/* extern color UI_text_color; */
extern void (*_ui_text_putpixel) (S32 x, S32 y, color c);
extern void (*_ui_text_putpixel_unconditional) (S32 x, S32 y, color c);
extern void UI_set_current_text_color(color c);


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_date_char_display
 * DESCRIPTION
 *  To enable special date character (133~147 0x85~0x93) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_date_char_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fe_display_flag |= FE_DISPLAY_FLAG_DATE_CHAR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_date_char_display
 * DESCRIPTION
 *  To disable special date character (133~147 0x85~0x93) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_date_char_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fe_display_flag &= (~FE_DISPLAY_FLAG_DATE_CHAR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_proprietary_symbol_display
 * DESCRIPTION
 *  To enable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_proprietary_symbol_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fe_display_flag |= FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_proprietary_symbol_display
 * DESCRIPTION
 *  To disable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_proprietary_symbol_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fe_display_flag &= (~FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR);

}


/*****************************************************************************
 * FUNCTION
 *  Get_Current_Lang_CountryCode
 * DESCRIPTION
 *  To get current language's country code
 *  
 *  This is used to get current language's country code
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 *
 *****************************************************************************/
U8 *Get_Current_Lang_CountryCode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) gLanguageArray[gCurrLangIndex].aLangCountryCode;
}


/*****************************************************************************
 * FUNCTION
 *  SetFont
 * DESCRIPTION
 *  To set the fonts.
 *  
 *  This is used to set all different type of font with different sizes.
 * PARAMETERS
 *  Font            [IN]        
 *  arrCount        [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 SetFont(stFontAttribute Font, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gnCurrentFont = Font.size;
    gbFontType = Font.smallCaps;
    gnCurrentFontAttrib = 0;

    if (gbFontType != 0)
    {
        gbFontType = 0;
    }

    if (Font.bold)
    {
        gnCurrentFontAttrib |= FONTATTRIB_BOLD;
    }
    if (Font.italic)
    {
        gnCurrentFontAttrib |= FONTATTRIB_ITALIC;
    }
    if (Font.oblique)
    {
        gnCurrentFontAttrib |= FONTATTRIB_OBLIQUE;
    }
    if (Font.underline)
    {
        gnCurrentFontAttrib |= FONTATTRIB_UNDERLINE;
    }
    if (!gnCurrentFontAttrib)
    {
        gnCurrentFontAttrib |= FONTATTRIB_NORMAL;
    }

    SetFontValues(gnCurrentFont, arrCount);

    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  GetFont
 * DESCRIPTION
 *  To get the current font.
 *  
 *  This is used to get current font attribute.
 * PARAMETERS
 *  Font            [IN/OUT]        
 *  arrCount        [IN/OUT]        
 * RETURNS
 *  U8
 *****************************************************************************/
void GetFont(stFontAttribute *Font, U8 *arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Font ->size = gnCurrentFont;
    Font ->smallCaps = gbFontType;	

    if ((gnCurrentFontAttrib & FONTATTRIB_BOLD))
    {
        Font->bold = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_ITALIC))
    {
        Font->italic = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_OBLIQUE))
    {
        Font->oblique = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_UNDERLINE))
    {
        Font->underline = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_NORMAL))
    {
    }
	

}

/*****************************************************************************
 * FUNCTION
 *  SetFontValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nFont           [IN]        
 *  arrCount        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetFontValues(U32 nFont, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->nTotalFonts) > nFont)
    {
        gpCurrentFont =
            gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->fontData[nFont];
    }
    else
    {
        gpCurrentFont = gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->fontData[0];
    }
}

#if(FONTENGINE_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 
#endif /* (FONTENGINE_IRAM_PLACEMENT) */ 

#if defined(__MMI_ZI__)


/*****************************************************************************
 * FUNCTION
 *  SearchInZiExtraFont
 * DESCRIPTION
 *  To search a character in the Zi Extra font
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nCh         [IN]        
 *  pnBase      [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
S32 SearchInZiExtraFont(U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirst = 0;
    S16 nLast = gZiExtraCharacter.pRangeDetails->nNoOfRanges - 1;
    S16 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if ((nCh >= gZiExtraCharacter_RangeData[nMid].nMin) && (nCh <= gZiExtraCharacter_RangeData[nMid].nMax))
        {
            *pnBase = gZiExtraCharacter_RangeData[nMid].nMin;
            return gZiExtraCharacter.pRange[nMid];

        }
        if (nCh > gZiExtraCharacter_RangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}
#endif /* defined(__MMI_ZI__) */ 

/*****************************************************************************
 * FUNCTION
 *  GetFontdata
 * DESCRIPTION
 *  To get font resource and data for a specific UCS2 character
 * PARAMETERS
 *  Ch              [IN]        
 *  Font            [IN]        
 *  ppCharData   [OUT]   
 *  pnWidth       [OUT]   
 *  pnHeight      [OUT]   
 *  pdataWidth  [OUT]   
 *  pdataHeight [OUT]   
 * RETURNS
 *  U32 the number of byte of the font resource
 *****************************************************************************/
#ifdef __MMI_INDIC_ALG__
static U32 GetFontdata(U32 Ch, stFontAttribute Font, U8 **ppCharData, U16 *pnWidth, U16 *pnDWidth, U16 *pnHeight, U16 *pdataWidth, U16 *pdataHeight, PU16 ascent, PU16 descent)
#else 
static U32 GetFontdata(U32 Ch, stFontAttribute Font, U8 **ppCharData, U16 *pnWidth, U16 *pnHeight, U16 *pdataWidth, U16 *pdataHeight, PU16 ascent, PU16 descent)
#endif 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S32 NumChar = 0;
    S32 index = -1;
    S32 nFontIndex = -1;
    U32 nIndexInList;
    U32 nBase;
    U32 nHashKey = 0;
    CharHashTable *charHashTable;

#ifdef __MMI_INDIC_ALG__
    sCustFontData *CurrentFont = gpCurrentFont;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *pnDWidth = 0;
#endif /* __MMI_INDIC_ALG__ */ 

    if (Ch & 0xFF00)
    {
        charHashTable = charHashTableOthers;
        nHashKey = Ch & OTHERS_CHAR_HT_MASK;
    }
    else
    {
        charHashTable = charHashTableLatin;
        nHashKey = Ch & LATIN_CHAR_HT_MASK;
    }

    if (charHashTable[nHashKey].unicode == Ch && charHashTable[nHashKey].gnCurrentFont == gnCurrentFont)
    {
        *ppCharData = charHashTable[nHashKey].CharData;
        *pnWidth = charHashTable[nHashKey].Width;
        *pnHeight = charHashTable[nHashKey].Height;
    #ifdef __MMI_INDIC_ALG__
        *pnDWidth = charHashTable[nHashKey].DWidth;
    #endif 
        /* usually the character width = data width */
        *pdataHeight = *pnHeight;
        *pdataWidth = * pnWidth; 
        *ascent = charHashTable[nHashKey].Ascent;
        *descent = charHashTable[nHashKey].Descent;
        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
            gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
        }
        else
        {
            /* when bold word, character width is more one than data width */
            *pnWidth = *pnWidth + 1;
        }
        
        return charHashTable[nHashKey].NumChar;
    }

    charHashTable[nHashKey].unicode = Ch;
    GetLangIndex(&count, &nFontIndex, &index, Ch, &nBase);
    charHashTable[nHashKey].count = count;
    charHashTable[nHashKey].gnCurrentFont = gnCurrentFont;
    charHashTable[nHashKey].index = index;

    if (index > -1)
    {

        /* Comments : No error handling is being  done if some characters come that is not
           currently supported then nothing can be displayed */

        SetFontValues(nFontIndex, count);
        charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->nWidth;
        charHashTable[nHashKey].Height = *pnHeight = gpCurrentFont->nHeight;
        charHashTable[nHashKey].Ascent = *ascent = gpCurrentFont->nAscent;
        charHashTable[nHashKey].Descent = *descent = gpCurrentFont->nDescent;

        if (gpCurrentFont->nEquiDistant)
        {

            charHashTable[nHashKey].NumChar = NumChar = gpCurrentFont->nCharBytes;
            nIndexInList = index + (NumChar * (Ch - nBase));
            charHashTable[nHashKey].CharData = *ppCharData = (gpCurrentFont->pDataArray + nIndexInList);

        }
        else
        {
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].NumChar = NumChar =
                (gpCurrentFont->pOffsetArray[nIndexInList + 1] - gpCurrentFont->pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gpCurrentFont->pDataArray + gpCurrentFont->pOffsetArray[nIndexInList]);

        }
    #ifdef __MMI_INDIC_ALG__
        if (gpCurrentFont->pDWidthArray)
            charHashTable[nHashKey].DWidth = *pnDWidth = gpCurrentFont->pDWidthArray[nIndexInList];
        gpCurrentFont = CurrentFont;
    #endif /* __MMI_INDIC_ALG__ */ 
        /* usually the character width = data width */
        *pdataHeight = *pnHeight;
        *pdataWidth = * pnWidth;    
        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
        
        }
        else
        {
            /* when bold word, character width is one more than data width */
            *pnWidth = *pnWidth + 1;
        }

        return NumChar;
    }
    else
    {

    #if defined(__MMI_ZI__)
        index = SearchInZiExtraFont(Ch, &nBase);
    #else 
        index = SearchInPropFont(Ch, &nBase);
    #endif 

        if (index == -1)
        {
        #if defined(__MMI_ZI__)
            index = SearchInPropFont(Ch, &nBase);
            if (index == -1)
            {
        #endif /* defined(__MMI_ZI__) */ 

                Ch = 65515; /* 0x4E01;//0x000F; */
                index = SearchInPropFont(Ch, &nBase);
                if (index == -1)
                {
                #ifdef __MMI_INDIC_ALG__
                    gpCurrentFont = CurrentFont;
                #endif 
                    return NumChar;
                }
            #if defined(__MMI_ZI__)
            }
            charHashTable[nHashKey].Height = *pnHeight = gMTKProprietaryFont.nHeight;
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gMTKProprietaryFont.pWidthArray[nIndexInList];
            charHashTable[nHashKey].Ascent = *ascent = gMTKProprietaryFont.nAscent;
            charHashTable[nHashKey].Descent = *descent = gMTKProprietaryFont.nDescent;
            charHashTable[nHashKey].NumChar = NumChar =
                (gMTKProprietaryFont.pOffsetArray[nIndexInList + 1] - gMTKProprietaryFont.pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gMTKProprietaryFont.pDataArray + gMTKProprietaryFont.pOffsetArray[nIndexInList]);
        #ifdef __MMI_INDIC_ALG__
            charHashTable[nHashKey].DWidth = *pnWidth;
        #endif 

            goto label_out;
            #endif /* defined(__MMI_ZI__) */ 

        }

    #if defined(__MMI_ZI__)
        charHashTable[nHashKey].Height = *pnHeight = gZiExtraCharacter.nHeight;
        nIndexInList = index + (Ch - nBase);
        charHashTable[nHashKey].Width = *pnWidth = gZiExtraCharacter.pWidthArray[nIndexInList];
        charHashTable[nHashKey].Ascent = *ascent = gZiExtraCharacter.nAscent;
        charHashTable[nHashKey].Descent = *descent = gZiExtraCharacter.nDescent;
        charHashTable[nHashKey].NumChar = NumChar =
            (gZiExtraCharacter.pOffsetArray[nIndexInList + 1] - gZiExtraCharacter.pOffsetArray[nIndexInList]);
        charHashTable[nHashKey].CharData = *ppCharData =
            (gZiExtraCharacter.pDataArray + gZiExtraCharacter.pOffsetArray[nIndexInList]);
      label_out:;
    #else /* defined(__MMI_ZI__) */ 
        charHashTable[nHashKey].Height = *pnHeight = gMTKProprietaryFont.nHeight;
        nIndexInList = index + (Ch - nBase);
        charHashTable[nHashKey].Width = *pnWidth = gMTKProprietaryFont.pWidthArray[nIndexInList];
        charHashTable[nHashKey].Ascent = *ascent = gMTKProprietaryFont.nAscent;
        charHashTable[nHashKey].Descent = *descent = gMTKProprietaryFont.nDescent;
        charHashTable[nHashKey].NumChar = NumChar =
            (gMTKProprietaryFont.pOffsetArray[nIndexInList + 1] - gMTKProprietaryFont.pOffsetArray[nIndexInList]);
        charHashTable[nHashKey].CharData = *ppCharData =
            (gMTKProprietaryFont.pDataArray + gMTKProprietaryFont.pOffsetArray[nIndexInList]);
    #endif /* defined(__MMI_ZI__) */ 

    }
#ifdef __MMI_INDIC_ALG__
    gpCurrentFont = CurrentFont;
#endif
    /* usually the character width = data width */
    *pdataHeight = *pnHeight;
    *pdataWidth = * pnWidth;    
    if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
            gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {
    
    }
    else
    {
        /* when bold word, character width is one more than data width */
        *pnWidth = *pnWidth + 1;
    }    

    return NumChar;
}


/**************************************************************

   FUNCTION NAME     : GetLangIndex()

   PURPOSE           : To get the language index of the character.

   INPUT PARAMETERS  : U32 nCh - Character to look for

   OUTPUT PARAMETERS : U8* pCount - The langugae Index
                    S32* pnIndex - The offset of the character in the array
                    U32* pnBase -  Base of Character set

   RETURNS           : void
   REMARKS           : Gets the character information

**************************************************************/
void GetLangIndex(U8 * pCount, S32 * pnFontIndex, S32 * pnIndex, U32 nCh, U32 * pnBase)
{
    /* first check the index in the current language. 90% of the cases strings will be from current language */
    U16 nFontCount;
    sFontFamily *pFontFamily;
    U16 nFontAttrib = gnCurrentFontAttrib;

    *pCount = 0;

    while (*pCount < gMaxDeployedLangs)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        pFontFamily = gLanguageArray[*pCount].fontfamilyList[gLanguageArray[*pCount].nCurrentFamily];
        nFontCount = 0;
        if (gnCurrentFontAttrib & FONTATTRIB_BOLD && (U32) (pFontFamily->fontData[nFontCount]->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD)) /* this will test for bold font.. which ever font is bold will betaken */
            /* bold is super set. If font is displayed for bold and italic then the bold font will be made as italic */
        {
            nFontAttrib = FONTATTRIB_BOLD;
        }
        else
        {
            nFontAttrib &= ~FONTATTRIB_BOLD;
            if (!nFontAttrib)
            {
                nFontAttrib |= FONTATTRIB_NORMAL;
            }
        }

        while (nFontCount < pFontFamily->nTotalFonts)
        {
            if ((U32) (pFontFamily->fontData[nFontCount]->pFontType[gnCurrentFont][gbFontType] & nFontAttrib))
            {
                if (nCh >= pFontFamily->fontData[nFontCount]->pRangeDetails->pRangeData[0].nMin &&
                    nCh <=
                    pFontFamily->fontData[nFontCount]->pRangeDetails->pRangeData[pFontFamily->fontData[nFontCount]->
                                                                                 pRangeDetails->nNoOfRanges - 1].nMax)
                {

                    *pnIndex = SearchIndexinList(*pCount, nFontCount, nCh, pnBase);
                    if (*pnIndex == -1)
                    {
                        ++nFontCount;
                    }
                    else
                    {
                        gpCurrentFont = pFontFamily->fontData[nFontCount];
                        *pnFontIndex = nFontCount;
                        return;
                    }

                }   /* if(nCh>=pFontFamily->fontData[nFontCount].pRangeData[0].nMin && */
                else
                {
                    ++nFontCount;
                }
            }
            else
            {
                ++nFontCount;
            }
        }   /* while(nFontCount < pFontFamily->nTotalFonts) */
        ++(*pCount);

    }   /* while(*pCount < gMaxDeployedLangs) */



    if (*pnIndex == -1)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SearchIndexinList
 * DESCRIPTION
 *  To search index and base of the character in a language.
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nListIndex      [IN]        
 *  nFontCount      [IN]        
 *  nCh             [IN]        
 *  pnBase          [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
S32 SearchIndexinList(U8 nListIndex, U16 nFontCount, U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirst = 0;
    S16 nLast =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRangeDetails->nNoOfRanges - 1;
    const RangeData *pRangeData =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRangeDetails->pRangeData;
    U32 *pRange =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRange;
    S16 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if ((nCh >= pRangeData[nMid].nMin) && (nCh <= pRangeData[nMid].nMax))
        {
            *pnBase = pRangeData[nMid].nMin;
            return pRange[nMid];

        }
        if (nCh > pRangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  SearchInPropFont
 * DESCRIPTION
 *  To search a character in the properitory font
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nCh         [IN]        
 *  pnBase      [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
S32 SearchInPropFont(U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirst = 0;
    S16 nLast = gMTKProprietaryFont.pRangeDetails->nNoOfRanges - 1;
    S16 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if ((nCh >= gMTKProprietaryFont_RangeData[nMid].nMin) && (nCh <= gMTKProprietaryFont_RangeData[nMid].nMax))
        {
            *pnBase = gMTKProprietaryFont_RangeData[nMid].nMin;
            return gMTKProprietaryFont.pRange[nMid];

        }
        if (nCh > gMTKProprietaryFont_RangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}

/**************************************************************

   FUNCTION NAME     : Get_CharWidthHeight_internal()

   PURPOSE           : To get char widths

   INPUT PARAMETERS  : U32 Ch

   OUTPUT PARAMETERS : nil

   RETURNS           : S32

   REMARKS           : This is used to get char widths

**************************************************************/
#ifdef __MMI_INDIC_ALG__
void Get_CharWidthHeight_internal(U32 Ch, S32 *pdWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent)
#else 
void Get_CharWidthHeight_internal(U32 Ch, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent)
#endif 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    S32 index = -1;
    U32 nBase;
    S32 nFontIndex = -1;
    sCustFontData *CurrentFont = gpCurrentFont;
    /* for font cache */
    U32 nHashKey = 0;
    CharHashTable *charHashTable;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FONT_TEST_FORMATTING_CHARS(Ch) || 
        (FONT_TEST_DATE_CHARS(Ch) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR))) ||
        (FONT_TEST_CRLF_ANF_SPACE_PROPRIETARY_SYMBOL(Ch) && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
    {
#ifdef __MMI_INDIC_ALG__
        *pdWidth = 0;
        *pHeight = 0;
        *pAscent = 0;
        *pDescent = 0;
#else 
        *pWidth = 0;
        *pHeight = 0;
        *pAscent = 0;
        *pDescent = 0;
#endif 
        return;
    }
    
    if (Ch & 0xFF00)
    {
        charHashTable = charHashTableOthers;
        nHashKey = Ch & OTHERS_CHAR_HT_MASK;
    }
    else
    {
        charHashTable = charHashTableLatin;
        nHashKey = Ch & LATIN_CHAR_HT_MASK;
    }
    if (charHashTable[nHashKey].unicode == Ch && charHashTable[nHashKey].gnCurrentFont == gnCurrentFont)
    {
    #ifdef __MMI_INDIC_ALG__
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(Ch))
        {
            *pdWidth = charHashTable[nHashKey].DWidth;
        }
        else
        {
            *pdWidth = charHashTable[nHashKey].Width;
        }
    #else /* __MMI_INDIC_ALG__ */ 
        *pWidth = charHashTable[nHashKey].Width;
#endif /* __MMI_INDIC_ALG__ */ 
        *pHeight = charHashTable[nHashKey].Height;
        *pAscent = charHashTable[nHashKey].Ascent;
        *pDescent = charHashTable[nHashKey].Descent;

        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
             gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            
        }
        else
        {
        #ifdef __MMI_INDIC_ALG__
            *pdWidth = *pdWidth + 1;
        #else /* __MMI_INDIC_ALG__ */
            *pWidth = *pWidth +1;    
        #endif /* __MMI_INDIC_ALG__ */
        }
        return;
    }
    /* for font cache */

    GetLangIndex(&count, &nFontIndex, &index, Ch, &nBase);

    if (index > -1)
    {
    #ifdef __MMI_INDIC_ALG__
        if (count >= gMaxDeployedLangs)
        {
            *pdWidth = 0;
            *pHeight = 0;
            *pAscent = 0;
            *pDescent = 0;
            gpCurrentFont = CurrentFont;
            return;
        }
    #endif /* __MMI_INDIC_ALG__ */ 
        SetFontValues(gnCurrentFont, count);
        *pHeight = gpCurrentFont->nHeight;
        *pAscent = gpCurrentFont -> nAscent;
        *pDescent = gpCurrentFont -> nDescent;
        
    #ifdef __MMI_INDIC_ALG__
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(Ch))
        {
            *pdWidth = gpCurrentFont->pDWidthArray[index + (Ch - nBase) /* +103 */ ];
        }
        else
        {
            if (gpCurrentFont->nEquiDistant)
                *pdWidth = gpCurrentFont->nWidth;
            else
                *pdWidth = gpCurrentFont->pWidthArray[index + (Ch - nBase)];
        }
    #else /* __MMI_INDIC_ALG__ */ 
        if (gpCurrentFont->nEquiDistant)
            *pWidth = gpCurrentFont->nWidth;
        else
            *pWidth = gpCurrentFont->pWidthArray[index + (Ch - nBase)];
    #endif /* __MMI_INDIC_ALG__ */ 
    }
    else
    {
    #ifdef __MMI_INDIC_ALG__
        Get_PropWidthHeight(Ch, pdWidth, pHeight, pAscent, pDescent);
    #else 
        Get_PropWidthHeight(Ch, pWidth, pHeight, pAscent, pDescent);
    #endif 
    }
    gpCurrentFont = CurrentFont;
    if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
         gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
        !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {
        
    }
    else
    {
#ifdef __MMI_INDIC_ALG__
            *pdWidth = *pdWidth + 1;
#else /* __MMI_INDIC_ALG__ */
            *pWidth = *pWidth + 1;  
#endif /* __MMI_INDIC_ALG__ */
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_engine_get_baseline_internal
 * DESCRIPTION
 *  This is used to get the baseline for first n (len) character of the input string (st).
 * PARAMETERS
 *  st                   [IN]        
 *  len                 [IN]        
 *  Font               [IN]        
 * RETURNS
 *  S32             [OUT] baseline for the string
 *****************************************************************************/
S32 mmi_font_engine_get_baseline_internal(U8 *st, S32 len, stFontAttribute Font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 baseline = 0;
    U32 unicode = 0;
    S32 Width, Height, Ascent, Descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error check */
    if (len < 0)
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    if (st == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    while (len != 0)
    {
        if ((st[0] == '\0') && (st[1] == '\0'))
            break;
        len --;

        unicode = st[0];
        unicode |= (st[1] << 8);
        Get_CharWidthHeight_internal(unicode, &Width,& Height, &Ascent, &Descent);
        if (Ascent > baseline)
            baseline = Ascent;
        st+=2;
    }
    
    return baseline;

}



BOOL cancelWidth = 0;
#ifndef __MMI_LANG_THAI__       /* Remove compile warnings */
/*****************************************************************************
 * FUNCTION
 *  ShowString_internal
 * DESCRIPTION
 *  To display a string in the screen
 *  
 *  This is used to display the string in the screen
 * PARAMETERS
 *  x                       [IN]        
 *  y                       [IN]        
 *  Font                    [IN]        
 *  BackGround              [IN]        
 *  String                  [?]         [?]
 *  len                     [IN]        
 *  LineHeight              [IN]        
 *  Bordered                [IN]        
 *  enable_truncated        [IN]        
 *  truncated_symbol        [?]         
 *  xwidth_boundary         [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 ShowString_internal(
            S32 x,
            S32 y,
            stFontAttribute Font,
            U8 BackGround,
            U8 *String,
            S32 len,
            S32 BaseLineHeight,
            U32 Bordered,
            MMI_BOOL enable_truncated,
            U8 *truncated_symbol,
            S32 xwidth_boundary,
            U8 assign_direction)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //W05.38 Remove GDI_ENTER_CRITICAL_SECTION outside GDI
    //GDI_ENTER_CRITICAL_SECTION(ShowString_internal)
    U8 *CharData;

    U32 NumChar;
    U32 Counter = 0;
    S32 CurrentX;
    /* nHgt, nWidth is the height and width of character and 
        dataHgt, dataWidth is the data height and width */
    U16 nHgt;
    U16 nWidth;
    U16 dtHgt;
    U16 dtWidth;
    /* the x width of string */
    U32 string_width = 0;
    U16 ascent = 0;
    U16 descent = 0;

#ifdef __MMI_INDIC_ALG__
    U16 nDWidth;
#endif 
    S32 nXOffset;
    S32 nYOffset;
    S32 yy;
    U16 unicode = 0;

#if defined(__MMI_LANG_VIETNAMESE__)
    U16 next_unicode = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
#ifdef __MMI_INDIC_ALG__
    static S32 single_time_bidi = 0;
    static S32 hindi_rule_string = 1;
#endif /* __MMI_INDIC_ALG__ */ 
    U8 font_attr = 0;
    gdi_color border_color = 0, text_color;
    S32 clip_x1, clip_y1, clip_x2, clip_y2;

#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U16 visual_str_len;
    U16 visual_cur_pos;
    S32 nLen;
    U16 visual_hilight_start;
    U16 visual_hilight_end;
#endif /* __MMI_BIDI_ALG__ */ 
#if defined(__MMI_BIDI_ALG__) || defined(__MMI_INDIC_ALG__)
    S32 check_len = len; /* used to check every character in the string */
    U8 *temp_string = String;
#endif /* defined(__MMI_BIDI_ALG__) || defined(__MMI_INDIC_ALG__) */ 
#if defined(__MMI_ARSHAPING_ENGINE__)
    MMI_BOOL IS_ARABIC = MMI_FALSE;
#endif
#if defined(__MMI_BIDI_ALG__)
    MMI_BOOL IS_BIDI = MMI_FALSE;
#endif
#if defined(__MMI_INDIC_ALG__)
    static MMI_BOOL IS_INDIC = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Error Check */
    if (len == 0)
    {
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    }
    if (String == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    if (Bordered && 
        UI_text_border_color.r == TRANSPARENT_COLOR_R && 
        UI_text_border_color.g == TRANSPARENT_COLOR_G && 
        UI_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        Bordered = 0;
    }
    
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	mmi_trace_screen_string(x, y, String, len, Bordered);
#endif

    /* check if shaping is necessary */
#if defined(__MMI_BIDI_ALG__)
    temp_string = String;
    check_len = len;
    while (check_len != 0)
    {
        U8 dic = 0;
        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);

    #if defined(__MMI_ARSHAPING_ENGINE__)
        if (IS_ARABIC_CHARACTER(unicode))
            IS_ARABIC = MMI_TRUE;
    #endif

        bidi_get_char_type((U8*)(&unicode), &dic);

        if (assign_direction == BIDI_R)
        {
            if (dic != BIDI_R && dic!= AL)
                IS_BIDI = MMI_TRUE;
        }
        else
        {
            if (dic == BIDI_R || dic == AL)
                IS_BIDI = MMI_TRUE;
        }
    
        /*if (IS_BIDI_CHARACTER(unicode))
            IS_BIDI = MMI_TRUE;*/
        
        if (IS_BIDI
    #if defined(__MMI_ARSHAPING_ENGINE__)
            && IS_ARABIC
    #endif
            )
            break;
        temp_string += 2;
    }
    unicode = 0;
#endif


#ifdef __MMI_INDIC_ALG__
    if (!single_time_bidi && !cancelWidth)  
#endif 
    {
    #ifdef __MMI_BIDI_ALG__
        nLen = mmi_ucs2strlen((const char *)String);
        if(nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH) 
            len = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
//        MMI_ASSERT(!(nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH));
        if (len > 0)
            mmi_ucs2ncpy((S8 *) show_pwcWord, (S8 *) String, len);
        else
            mmi_ucs2cpy((S8 *) show_pwcWord, (S8 *) String);
        nLen = mmi_ucs2strlen((const char *)show_pwcWord);
    #if defined(__MMI_ARSHAPING_ENGINE__)
        if (IS_ARABIC)
        {
            ArabicShapeEngine_ext((U16*)&nLen, show_pwcWord);
        }
    #endif /* __MMI_ARSHAPING_ENGINE__ */
        String = (U8 *) show_pwcWord;
        logical_cur_pos = 0;

        if (assign_direction == BIDI_R || assign_direction == AL)
        {
            if (IS_BIDI)
                bidi_main((U8 *) String, (U16) mmi_ucs2strlen((const S8 *)String), logical_cur_pos,
                          show_visual_str, &visual_str_len, &visual_cur_pos,
                          MMI_TRUE, MMI_bidi_input_type, 0, 0, &visual_hilight_start, &visual_hilight_end);
        }
        else    /* if(default_direction == BIDI_L) */
        {
            if (IS_BIDI)
                bidi_main((U8 *) String, (U16) mmi_ucs2strlen((const S8 *)String),
                          logical_cur_pos, show_visual_str, &visual_str_len, &visual_cur_pos,
                          MMI_FALSE, MMI_bidi_input_type, 0, 0, &visual_hilight_start, &visual_hilight_end);
        }
    #ifdef __MMI_INDIC_ALG__
        if (r2lMMIFlag)
        {
            if (IS_BIDI)
                ire_get_indic_rules_for_whole_string(show_visual_str);
            else
                ire_get_indic_rules_for_whole_string(String);
            hindi_rule_string = 0;
        }
    #endif /* __MMI_INDIC_ALG__ */ 
        if (IS_BIDI)
        {
            if ((r2lMMIFlag && assign_direction == BIDI_L) || (!r2lMMIFlag && assign_direction != BIDI_L))
                bidi_reverse(show_visual_str, (U16) mmi_ucs2strlen((const S8 *)show_visual_str));
            String = show_visual_str;
        }
        else
        {
            if ((r2lMMIFlag && assign_direction == BIDI_L) || (!r2lMMIFlag && assign_direction != BIDI_L))
                bidi_reverse(String, (U16) mmi_ucs2strlen((const S8 *)String));
        }
        
    #endif /* __MMI_BIDI_ALG__ */ 
    }

    //START FARHAD PMT 20050211 : For hindi character sudden disappear 
    //UI_current_text_color = UI_text_color;     
    //END FARHAD PMT 20050211
    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
        font_attr |= FONTATTRIB_ITALIC;
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
        font_attr |= FONTATTRIB_OBLIQUE;

    if (Font.underline)
        font_attr |= FONTATTRIB_UNDERLINE;

    {
        if (Bordered)
            border_color =
                gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);

        text_color =
            gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    }

    gdi_font_begin(text_color, font_attr);

    CurrentX = x;
#ifdef __MMI_INDIC_ALG__
    /* Indic has been processed, it is not necessary to process again. */
    if (r2lMMIFlag && !cancelWidth && !single_time_bidi)
    {
        IS_INDIC = MMI_FALSE;
        hindi_rule_string = 1;
        goto DISPLAY_DIRECTLY;
    }
    /* check if calling IRE is necessary */
    temp_string = String;
    check_len = len; 
    while (check_len != 0 && !IS_INDIC)
    {
        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);
        if(IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
            IS_INDIC = MMI_TRUE;
        if (IS_INDIC)
            break;
        temp_string += 2;
    }
    unicode = 0;
    
    if (!IS_INDIC)
        goto DISPLAY_DIRECTLY;
    
    if (ire_is_reset_indic_params())
        ire_reset_indic_params();
    if (Font.color == 0)
        Font.color = 15;
    if (ire_is_indic_rules_parsing() && hindi_rule_string)
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length;
        U16 glyph_output[G_MAX];
        S32 Len;

        S32 total_len = 0;
        S32 original_len = 0;

        S32 width, height;

	#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
        overwrite_current_language_for_hindi_rules_based_on_input_method();
    #endif /*defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )*/
        ire_init_cluster_start_p(String);
        if (len > 0)
        {
            ire_init_cluster_end_p(String + (len *2));
        }
        else
        {
            ire_init_cluster_end_p(String + (2 *mmi_ucs2strlen((const char *)String) + 1));
        }
        original_len = len;
        ire_disable_indic_rules_parsing();
        ire_disable_indic_reset_hindi_params();
        single_time_bidi = 1;
        if (BaseLineHeight == -1)
        {
            BaseLineHeight = mmi_font_engine_get_baseline_internal(String, mmi_ucs2strlen((S8*)String), Font);
        }

        
	/*This loop takes the string cluster by cluster and renders the string*/
        do
        {
            if (total_len == original_len)
                break;
     		
            cluster_length = ire_get_cluster(cluster_fill);
            total_len += cluster_length;
            if (original_len > 0)
            {
                if (total_len > original_len || total_len > len)
                    break;
            }
            if (cluster_length)
            {
                U32 initial_small_cons_flag =0;
                U32 initial_correction_flag =0;
                Len = ire_language_rules(glyph_output, cluster_fill, ire_get_display_buffer_len());
                initial_correction_flag = IRE_GET_RENDERING_CORRECTION();
                initial_small_cons_flag = IRE_GET_SMALL_CONSONANT_FLAG();
                /* MTI START MAUI_00038534 */
               	#if defined(__MMI_LANG_VIETNAMESE__)	
                if ((glyph_output[0] > 0x0040) && (glyph_output[0] < 0x01B1))
                {
                    U16 *next_unicode = (U16 *) ire_get_cluster_start_p();                                  
                    tone_mark = mmi_viet_tone_mark(*next_unicode);
                        if (VIET_TONE_NONE != tone_mark)
                        {
                        viet_vowel = mmi_viet_vowel_letter(glyph_output[0]);
                        if (VIET_VOWEL_NONE != viet_vowel)
                        {
                            glyph_output[0] = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                            ire_increment_cluster_start_p(2); 
                            

                            
                        }
                    }
                    
                    
                     
                }
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
                /* MTI END MAUI_00038534 */
                Get_StringWidthHeight((U8 *) glyph_output, &width, &height);
                if(initial_small_cons_flag !=(IRE_GET_SMALL_CONSONANT_FLAG()))
                {
                    IRE_SET_SMALL_CONSONANT_FLAG();
                }
               if(IRE_GET_RENDERING_CORRECTION()!=initial_correction_flag)
               {
                   IRE_SET_RENDERING_CORRECTION(initial_correction_flag) ;
               }
                /* Cluster shouldn't be truncated. Check the width */
                if (enable_truncated && string_width + width > xwidth_boundary)
                    break;
                ShowString_internal(x, y, Font, BackGround, (U8*)glyph_output, Len, BaseLineHeight, Bordered, MMI_FALSE, NULL, -1, assign_direction);
                if (r2lMMIFlag)
                    x -= width;
                else
                    x += width;
            }
            string_width += width;
        } while (cluster_length);
        /* print truncated symbol */
        if (enable_truncated && truncated_symbol != NULL)
        {
            ShowString_internal(x, y, Font, BackGround, truncated_symbol, -1, BaseLineHeight, Bordered, MMI_FALSE, NULL, -1, assign_direction);
        }
        ire_enable_indic_rules_parsing();
        ire_enable_indic_reset_indic_params();
        single_time_bidi = 0;
        gdi_font_end();
        IS_INDIC = MMI_FALSE;
        return MMI_FONT_ENGINE_NO_ERROR;
    }
    hindi_rule_string = 1;
#endif /* __MMI_INDIC_ALG__ */ 

#if defined(__MMI_INDIC_ALG__)
DISPLAY_DIRECTLY:
#endif

    if (BaseLineHeight == -1)
    {
        if (len <= 0)
        {
            len = mmi_ucs2strlen((const char *)String);
        }        
        BaseLineHeight = mmi_font_engine_get_baseline_internal(String, len, Font);
    }
    while (len != 0)
    {
        U16 prev_unicode = 0;

    NEXT:
        if ((String[0] == '\0') && (String[1] == '\0'))
            break;
        len--;

        prev_unicode = unicode;
        unicode = String[0];
        unicode |= (String[1] << 8);

        if (FONT_TEST_CONTROL_CHAR(unicode) || (FONT_TEST_SPACE_CHAR(unicode) && !FONT_TEST_ZERO_WIDTH_SPACE(unicode)))
        {
            unicode = 0x20;
	    }
        if (FONT_TEST_ZERO_WIDTH_SPACE(unicode)||
            FONT_TEST_FORMATTING_CHARS(unicode) || 
            (FONT_TEST_DATE_CHARS(unicode) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR))) ||
            (FONT_TEST_CRLF_ANF_SPACE_PROPRIETARY_SYMBOL(unicode) && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
        {
            String += 2;
            if (len == 0) /* when the formatting character is the last character in the string */
                break;
            else
                goto NEXT;
        }
        
    #if defined(__MMI_LANG_VIETNAMESE__)
        if ((unicode > 0x0040) && (unicode < 0x01B1))
        {
            next_unicode = String[2];
            next_unicode |= (String[3] << 8);
            tone_mark = mmi_viet_tone_mark(next_unicode);
            if (VIET_TONE_NONE != tone_mark)
            {
                viet_vowel = mmi_viet_vowel_letter(unicode);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    unicode = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    String += 2;
                }
            }
        }
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    #ifdef __MMI_INDIC_ALG__
        NumChar = GetFontdata(unicode, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
    #else 
        NumChar = GetFontdata(unicode, Font, &CharData, &nWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
    #endif 
        Counter++;
    #ifdef __MMI_INDIC_ALG__
    
        if(!IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
    #endif
        {
            yy = y + (BaseLineHeight - ascent);
        }
    #ifdef __MMI_INDIC_ALG__
        else
        {
            yy = y;

        }
    #endif
        if (r2lMMIFlag
    #ifdef __MMI_INDIC_ALG__
            && (!cancelWidth)
    #endif 
            )
        {
        #ifdef __MMI_INDIC_ALG__
            if (IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
            {
                if (IRE_UI_INDIC_SIGN_RANGE(prev_unicode))
                    CurrentX -= 0;
                else if (IRE_UI_INDIC_SIGN_RANGE(unicode))
                {
                    U16 next_unicode = 0;
                    PU8 CharData1=NULL;
	                U16 nWidth1 = 0;
                    U16 nDWidth1 = 0;
                    U16 nHgt1 = 0;
                    U16 dtWidth1 = 0, dtHgt1 = 0;
                    next_unicode = String[2];
                    next_unicode |= (String[3] << 8);
                    /* Use getfontdata instead of get_charwidth.
                     *  Reason: 
                     *      In next loop, the character is the target to be displayed.
                     *      Use GetFontData to cache the info and
                     *      then in next loop, it would be a little faster to get font data
                     */
                    GetFontdata(next_unicode, Font, &CharData1, &nWidth1, &nDWidth1, &nHgt1, &dtWidth1, &dtHgt1, &ascent, &descent);
                    CurrentX -= nDWidth1;					
		        }
                else
                    /* PMT START MAUI_00419974 */		
                    if(nDWidth)
                    {
                        CurrentX -= nDWidth;
                    }
                    else
                    {
		        CurrentX -= nWidth;
                    }
                    /* PMT END MAUI_00419974 */                   
            }
            else
        #endif /* __MMI_INDIC_ALG__ */ 
                CurrentX -= nWidth;
        }
        nXOffset = CurrentX + nWidth;
        nYOffset = yy + nHgt;
    #if defined(__MMI_INDIC_ALG__)
        if ((cancelWidth || !r2lMMIFlag) && IS_INDIC)
             ire_get_text_x(&CurrentX, unicode, yy, nDWidth, nWidth);
    #endif /* defined(__MMI_INDIC_ALG__) */ 
    #if defined(__MMI_INDIC_ALG__)
        if ((CurrentX > clip_x2) && !r2lMMIFlag)
            break;
	#endif
        /* to check string width boundary when skiping first pass */
        string_width += nWidth;
        if (enable_truncated &&
		#if defined(__MMI_INDIC_ALG__)
			!IS_INDIC &&
		#endif
			string_width > xwidth_boundary)
            break;

        if (Bordered)
            gdi_show_char_bordered(CurrentX, yy, text_color, border_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        else if (!
                 (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                  gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                 !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }
        else
        {
            gdi_show_char(CurrentX + 1, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }

        if (!r2lMMIFlag)
            CurrentX += nWidth;

        String += 2;
    #if !defined(__MMI_INDIC_ALG__)
        /* Skip unnecessary action when the character is out of clip */
        if ((CurrentX > clip_x2) && !r2lMMIFlag)
            break;
    #endif /*__MMI_INDIC_ALG__*/
    }

    /* Print truncated_symbol in the end */
    if (enable_truncated && truncated_symbol != NULL)
    {        
		if (r2lMMIFlag)
			CurrentX += nWidth;

        ShowString_internal(CurrentX, y, Font, BackGround, truncated_symbol, -1, BaseLineHeight, Bordered, MMI_FALSE, NULL, -1, assign_direction);
    }
    
    gdi_font_end();

    /* GDI_RETURN (CurrentX); */

    /* GDI_EXIT_CRITICAL_SECTION(ShowString_internal) */
    return CurrentX;

}
#endif /* __MMI_LANG_THAI__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_display_direction
 * DESCRIPTION
 *  To get display direction by the content
 * PARAMETERS
 *  st      [IN]     the string input   
 *  dic           [OUT]        the display direction get by string content
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_font_engine_error_message_enum mmi_fe_get_display_direction(U8* st, U8* dic)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error check */
    if (st == NULL) return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    bidi_get_char_type((U8 *) st, (U8 *) & default_direction);
    if (default_direction == BIDI_R || default_direction == AL)
    {
        (*dic) = BIDI_R;
    }
    else
    {
        (*dic) = BIDI_L;
    }
    return MMI_FONT_ENGINE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_width_by_fixed_char_width
 * DESCRIPTION
 *  To get string width by the fixed char width.
 *  the fixed char width is count by the max width of the character.
 *  And the string width is the max char width multiple the numofchar.
 *  The characte of Arabic series, Indic series, Thai and Vietnamese language is not allowed
 *  to be the input. 
 * PARAMETERS
 *  numofchar [IN]  the number of character of the string
 *  st            [IN]  all the character would be displayed as a char in the string. 
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_fe_measure_string_by_char_num(U8* st, S32 numofchar, S32* width, S32* height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = mmi_ucs2strlen((const char*)st);
    S32 max_w = 0, max_ascent = 0, max_descent = 0;
    S32 w = 0, h = 0, ascent = 0, descent = 0;
    S32 i = 0;
    U32 unicode = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < len * 2; i += 2)
    {
        unicode = st[i];
        unicode |= (st[i + 1] << 8);
        Get_CharWidthHeight_internal(unicode, &w, &h, &ascent, &descent);
        max_w = (w > max_w) ? w : max_w;
        max_ascent = (ascent > max_ascent) ? ascent : max_ascent;
        max_descent = (descent > max_descent) ? descent : max_descent;
        
    }

    *width = (max_w * numofchar);
    *height = (max_ascent + max_descent);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_engine_show_truncated_text
 * DESCRIPTION
 *  Print truncated text
 *  
 *  If length of text is greater  than screen width then the text is truncated. 
 *  The assign truncated symbol are shown at end of text
 * PARAMETERS
 *  x                       [IN]        Start x positoin
 *  y                       [IN]        Start Y position
 *  xwidth                  [IN]        Width of text in pixels to display
 *  st                      [IN]        Text to display
 *  truncated_symbol        [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary
 *  Font                    [IN]        Font attribute
 *  BackGround              [IN]        
 *  LineHeight              [IN]        
 *  bordered                [IN]        
 *  border(?)               [IN]        
 *  Background(?)           [IN]        Background color
 * RETURNS
 *  S32                         [OUT]   for checking if the string has been truncated
 *****************************************************************************/
mmi_font_engine_error_message_enum mmi_font_engine_show_truncated_text(S32 x, S32 y,S32 xwidth, U8 *st, U8 *truncated_symbol, stFontAttribute Font,U8 BackGround,U32 LineHeight, MMI_BOOL bordered )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_xwidth; /* the new width after subtract truncated_symbol width from original width*/
    S32 height;
    S32 symbol_width; /* the width of turncated symbol string */
    S32 symbol_height; /* the width of truncated symbol string */
    S32 baseline = 0;
    U8 default_direction = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for error check */
    if (st == NULL) return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    mmi_fe_get_display_direction(st, &default_direction);
    
    /* for check if truncation is necessary */
    Get_StringWidthHeight_internal(st, 0, mmi_ucs2strlen((S8*)st), &new_xwidth, &height,MMI_FALSE, -1, 0, &baseline);
    
    if (bordered && 
        UI_text_border_color.r == TRANSPARENT_COLOR_R && 
        UI_text_border_color.g == TRANSPARENT_COLOR_G && 
        UI_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        bordered = MMI_FALSE;
    }
    if (new_xwidth <= xwidth)
    {
        if (bordered)
        {
            ShowStringBordered_baseline(x, y, Font, BackGround, st, baseline, default_direction);
        }
        else
        {
            ShowString_baseline(x, y, Font, BackGround, st, baseline, default_direction);
        }
        return MMI_FONT_ENGINE_NO_TRUNCATION;
    }
    
    Get_StringWidthHeight(truncated_symbol, &symbol_width, &symbol_height);
    if (bordered)
    {
        symbol_width += 2;
    }

    new_xwidth = xwidth - symbol_width;
    if (new_xwidth < 0)
        return MMI_FONT_ENGINE_ERROR_NO_TRUNCATION_AVAILABLE;
#if defined(__MMI_LANG_THAI__)
    ShowStackedString(x, y, Font, BackGround, st, LineHeight, bordered, -1, MMI_TRUE, truncated_symbol, new_xwidth, default_direction);
#else
    ShowString_internal(x, y, Font, BackGround, st, -1, baseline, bordered, MMI_TRUE, truncated_symbol, new_xwidth, default_direction);
#endif
    return MMI_FONT_ENGINE_TRUNCATION;

}


/*****************************************************************************
 * FUNCTION
 *  ShowString_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_unsigned      [IN]        
 *  y_unsigned      [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  Len             [IN]        
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowString_n(
        U32 x_unsigned,
        U32 y_unsigned,
        stFontAttribute Font,
        U8 BackGround,
        U8 *String,
        int Len,
        U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_get_display_direction(String, &default_direction);

#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x_unsigned, y_unsigned, Font, BackGround, String, LineHeight, 0, Len, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x_unsigned, y_unsigned, Font, BackGround, String, Len, -1, MMI_FALSE, MMI_FALSE, NULL, -1, default_direction);
#endif/*__MMI_LANG_THAI__*/ 
}

U32 ShowString_baseline(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, S32 baseline, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);  
    
#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x, y, Font, BackGround, String, baseline, MMI_FALSE, -1, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x, y, Font, BackGround, String, -1, baseline, MMI_FALSE, MMI_FALSE, NULL, -1, default_direction);
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  ShowString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowString(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    U8 default_direction = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);
    mmi_fe_get_display_direction(String, &default_direction);
#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x, y, Font, BackGround, String, LineHeight, MMI_FALSE, nLen, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x, y, Font, BackGround, String, nLen, -1, MMI_FALSE, MMI_FALSE, NULL, -1, default_direction);
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered_baseline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowStringBordered_baseline(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, S32 baseline, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x, y, Font, BackGround, String, baseline, MMI_TRUE, -1, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x, y, Font, BackGround, String, -1, baseline, MMI_TRUE, MMI_FALSE, NULL, -1, default_direction);
#endif 
}

U32 ShowString_by_direction(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);  
    
#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x, y, Font, BackGround, String, LineHeight, MMI_FALSE, nLen, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x, y, Font, BackGround, String, nLen, -1, MMI_FALSE, MMI_FALSE, NULL, -1, default_direction);
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowStringBordered(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    U8 default_direction = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_get_display_direction(String, &default_direction);

#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x, y, Font, BackGround, String, LineHeight, MMI_TRUE, nLen, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x, y, Font, BackGround, String, nLen, -1, MMI_TRUE, MMI_FALSE, NULL, -1, default_direction);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_unsigned      [IN]        
 *  y_unsigned      [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  Len             [IN]        
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowStringBordered_n(
        U32 x_unsigned,
        U32 y_unsigned,
        stFontAttribute Font,
        U8 BackGround,
        U8 *String,
        int Len,
        U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_get_display_direction(String, &default_direction);
#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x_unsigned, y_unsigned, Font, BackGround, String, LineHeight, MMI_TRUE, Len, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x_unsigned, y_unsigned, Font, BackGround, String, Len, -1, MMI_TRUE, MMI_FALSE, NULL, -1, default_direction);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered_by_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowStringBordered_by_direction(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);

#if defined(__MMI_LANG_THAI__)
    return ShowStackedString(x, y, Font, BackGround, String, LineHeight, MMI_TRUE, nLen, MMI_FALSE, NULL, -1, default_direction);
#else
    return ShowString_internal(x, y, Font, BackGround, String, nLen, -1, MMI_TRUE, MMI_FALSE, NULL, -1, default_direction);
#endif 
}



/*****************************************************************************
 * FUNCTION
 *  Get_CharWidth
 * DESCRIPTION
 *  To get char widths
 *  
 *  This is used to get char widths
 * PARAMETERS
 *  Ch          [IN]        
 *  pdWidth     [?]         
 * RETURNS
 *  S32(?)
 *****************************************************************************/
void Get_CharWidth(U32 Ch, S32 *pdWidth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    S32 index = -1;
    U32 nBase;
    S32 Height = 0, Ascent = 0, Descent = 0;
    S32 nFontIndex = -1;
    sCustFontData *CurrentFont = gpCurrentFont;

    /* for font cache */
    U32 nHashKey = 0;
    CharHashTable *charHashTable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FONT_TEST_FORMATTING_CHARS(Ch))
    {
        *pdWidth = 0;
        return;
    }

    if (Ch & 0xFF00)
    {
        charHashTable = charHashTableOthers;
        nHashKey = Ch & OTHERS_CHAR_HT_MASK;
    }
    else
    {
        charHashTable = charHashTableLatin;
        nHashKey = Ch & LATIN_CHAR_HT_MASK;
    }
    if (charHashTable[nHashKey].unicode == Ch && charHashTable[nHashKey].gnCurrentFont == gnCurrentFont)
    {
        *pdWidth = charHashTable[nHashKey].Width;
        return;
    }
    /* for font cache */

    GetLangIndex(&count, &nFontIndex, &index, Ch, &nBase);
    if (index > -1)
    {
        if (count >= gMaxDeployedLangs)
        {
            *pdWidth = 0;
            gpCurrentFont = CurrentFont;
            return;
        }
        SetFontValues(gnCurrentFont, count);
        if (gpCurrentFont->nEquiDistant)
        {
            *pdWidth = gpCurrentFont->nWidth;
        }
        else
        {
            *pdWidth = gpCurrentFont->pWidthArray[index + (Ch - nBase)];
        }
    }
    else
    {
        Get_PropWidthHeight(Ch, pdWidth, &Height, &Ascent, &Descent);
    }
    gpCurrentFont = CurrentFont;

        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
             gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            
        }
        else
        {
                *pdWidth = *pdWidth + 1;
        }
   return;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  
 *  This is used to get char number in specified width
 * PARAMETERS
 *  String              [IN]        
 *  width               [IN]        
 *  checklinebreak      [IN]        
 *  number(?)           [OUT]       Of characters
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_CharNumInWidth_internal(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nwidth = 0, chwidth, chheight;
    U32 nchar = 0, line_break_char_counter = 0;
    U16 ch;
    U8 linebreakflag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_wc(&ch, String);
    if (ch == 0)
    {
        return 0;
    }

    do
    {
        mmi_ucs2_to_wc(&ch, String);

        if (checklinebreak)
        {
            linebreakflag = FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(ch);
        }

        if (FONT_TEST_BIDI_CONTROL_CHAR(ch))
        {
            chwidth = 0;
        }
        else
        {
            Get_CharWidthHeight(ch, (S32*) & chwidth, (S32*) & chheight);
            chwidth += gap;
        }

        nwidth += chwidth;
        String += 2;
        nchar++;
        if (checklinebreak)
        {
            if (UI_STRING_END_OF_STRING_CHARACTER(ch))
            {
                line_break_char_counter = nchar;
            }

            if (linebreakflag)
            {
                line_break_char_counter = nchar;
            }
            /*
             * if (!FONT_TEST_ASCII_CHARACTER(ch))
             * {
             * line_break_char_counter = 0;
             * }
             */
        }

    } while (nwidth <= width && ch != 0 /* && ch != 0x0A && ch != 0x0D */ );

    if (checklinebreak)
    {
        if (line_break_char_counter == 0)
        {
            nchar--;
        }
        else
        {
            nchar = line_break_char_counter;
        }
    }
    else
    {
        nchar--;
    }

    return nchar;

}



/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  
 *  This is used to get char number in specified width
 * PARAMETERS
 *  String              [IN]        
 *  width               [IN]        
 *  checklinebreak      [IN]        
 *  number(?)           [OUT]       Of characters
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_CharNumInWidth_w(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return Get_CharNumInWidth_internal(String, width, checklinebreak, gap);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  
 *  This is used to get char number in specified width
 * PARAMETERS
 *  String              [IN]        
 *  width               [IN]        
 *  checklinebreak      [IN]        
 *  number(?)           [OUT]       Of characters
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_CharNumInWidth(U8 *String, U32 width, U8 checklinebreak)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return Get_CharNumInWidth_internal(String, width, checklinebreak, 1);

}

/**************************************************************

   FUNCTION NAME     : Get_CharWidthHeight()

   PURPOSE           : To get char widths

   INPUT PARAMETERS  : U32 Ch

   OUTPUT PARAMETERS : nil

   RETURNS           : S32

   REMARKS           : This is used to get char widths

**************************************************************/
void Get_CharWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent = 0;
    S32 descent = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_CharWidthHeight_internal(Ch, pWidth, pHeight, &ascent, &descent);
}


/**************************************************************

   FUNCTION NAME     : Get_CharBoundingBox()

   PURPOSE           : To get the bounding box of "drawn area" of a character

   INPUT PARAMETERS  : U32 Ch

   OUTPUT PARAMETERS : pCharWidth - width of character
                     pCharHeight    - height of character
                     pBoxXoffset    - X offset of the bounding box of drawn area relative to the top-left corner
                     pBoxYoffset    - Y offset of the bounding box of drawn area  relative to the top-left corner
                     pBoxWidth      - width of the bounding box of drawn area 
                     pBoxHeight     - height of the bounding box of drawn area 

   RETURNS           : void

   REMARKS           : 
                     1. It does not handle Hindi properly.
                     2. The function is slow because it process internal font data.
                     3. This function can be used to align a character in a better way because the "drawn area" is aligned
                       differently for different font database.
**************************************************************/
void Get_CharBoundingBox(U32 Ch, S32 * pCharWidth, S32 * pCharHeight, S32 * pBoxXoffset, S32 * pBoxYoffset,
                         S32 * pBoxWidth, S32 * pBoxHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *font_data;
    U32 font_data_size;
    U16 char_height;
    U16 char_width;
    U16 data_height;
    U16 data_width;
#ifdef __MMI_INDIC_ALG__
    U16 char_d_width = 0;
#endif 
    S32 fx1, fy1, fx2, fy2, x, y;
    U16 ascent = 0, descent = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_INDIC_ALG__
    font_data_size =
        GetFontdata(Ch, *UI_font /* dummy parameter */ , &font_data, &char_width, &char_d_width, &char_height, &data_width, &data_height, &ascent, &descent);
#else /* __MMI_INDIC_ALG__ */ 
    font_data_size = GetFontdata(Ch, *UI_font /* dummy parameter */ , &font_data, &char_width, &char_height, &data_width, &data_height, &ascent, &descent);
#endif /* __MMI_INDIC_ALG__ */ 

    *pCharWidth = char_width;
    *pCharHeight = char_height;

    fx1 = char_width - 1;   /* min X of drawn area */
    fx2 = 0;                /* max X of drawn area */
    fy1 = char_height - 1;  /* min Y of drawn area */
    fy2 = 0;                /* max Y of drawn area */

    x = 0;
    y = 0;

    while (font_data_size--)
    {
        U8 pattern = *font_data++;

        if (!pattern)
        {
            U32 nTemp;

            x += 8;
            nTemp = x / char_width;
            if (nTemp)
            {
                y += nTemp;
                char_height -= (U16) nTemp;
                if (!char_height)
                {
                    break;
                }
            }

            x %= char_width;
        }
        else
        {
            S32 i;

            for (i = 0; i < 8; i++)
            {
                if (pattern & 1)
                {
                    if (x < fx1)
                    {
                        fx1 = x;
                    }
                    if (y < fy1)
                    {
                        fy1 = y;
                    }
                    if (x > fx2)
                    {
                        fx2 = x;
                    }
                    if (y > fy2)
                    {
                        fy2 = y;
                    }
                }

                x++;
                if (x == (S32) char_width)
                {
                    y++;
                    char_height--;
                    x = 0;
                    if (!char_height)
                    {
                        break;
                    }
                }
                pattern >>= 1;
            }
        }
    }

    MMI_DBG_ASSERT(fx2 >= fx1 && fy2 >= fy1);

    *pBoxXoffset = fx1;
    *pBoxYoffset = fy1;
    *pBoxWidth = fx2 - fx1 + 1;
    *pBoxHeight = fy2 - fy1 + 1;
}


/*****************************************************************************
 * FUNCTION
 *  Get_PropWidthHeight
 * DESCRIPTION
 *  To get char widths
 *  
 *  This is used to get char widths
 * PARAMETERS
 *  Ch          [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_PropWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBase = 0;
    S32 index = -1;
    U32 nIndexInList = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Add Steven 2005.06.03 */
#if defined(__MMI_ZI__)
    index = SearchInZiExtraFont(Ch, &nBase);
#else 
    index = SearchInPropFont(Ch, &nBase);
#endif 

    if (index == -1)
    {
    #if defined(__MMI_ZI__)
        index = SearchInPropFont(Ch, &nBase);
        if (index == -1)
        {
    #endif /* defined(__MMI_ZI__) */ 

            Ch = 65515;
            index = SearchInPropFont(Ch, &nBase);
            if (index == -1)
            {
                return index;
            }

        #if defined(__MMI_ZI__)
        }
        nIndexInList = index + (Ch - nBase);
        *pHeight = gMTKProprietaryFont.nHeight;
        *pWidth = gMTKProprietaryFont.pWidthArray[nIndexInList];
        *pAscent = gMTKProprietaryFont.nAscent;
        *pDescent = gMTKProprietaryFont.nDescent;
        goto label_out2;
        #endif /* defined(__MMI_ZI__) */ 

    }

#if defined(__MMI_ZI__)
    nIndexInList = index + (Ch - nBase);
    *pHeight = gZiExtraCharacter.nHeight;
    *pWidth = gZiExtraCharacter.pWidthArray[nIndexInList];
    *pAscent = gZiExtraCharacter.nAscent;
    *pDescent = gZiExtraCharacter.nDescent;
  label_out2:;
#else /* defined(__MMI_ZI__) */ 
    nIndexInList = index + (Ch - nBase);
    *pHeight = gMTKProprietaryFont.nHeight;
    *pWidth = gMTKProprietaryFont.pWidthArray[nIndexInList];
    *pAscent = gMTKProprietaryFont.nAscent;
    *pDescent = gMTKProprietaryFont.nDescent;
#endif /* defined(__MMI_ZI__) */ 
    /* MTK End */
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight
 * DESCRIPTION
 *  To get string width and height
 *  
 *  This is used to get string widths
 * PARAMETERS
 *  String      [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
 * RETURNS
 *  S32(?)
 *****************************************************************************/
void Get_StringWidthHeight(U8 *String, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen;
    S32 baseline = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);
    Get_StringWidthHeight_internal(String, 0, nLen, pWidth, pHeight, MMI_FALSE, -1, 0, &baseline);
        
}

#if(FONTENGINE_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 
#endif /* (FONTENGINE_IRAM_PLACEMENT) */ 

/* july-28-2002 manju: required by UI elements. This function measures a text string's width upto a given number of characters */


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_n
 * DESCRIPTION
 *  To get string widths and height upto a given number of characters
 *  
 *  This is used to get string widths upto a given number of characters
 * PARAMETERS
 *  String      [IN]        
 *  n           [IN]        
 *  pWidth      [IN]        
 *  pHeight     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_n(U8 *String, S32 n, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 baseline = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    Get_StringWidthHeight_internal(String, 0, n, pWidth, pHeight, MMI_FALSE, -1, 0, &baseline);

}

/* PMT dara added for Multitap thai */


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_multitap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String      [?]         
 *  w           [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_multitap(U8 *String, S32 w, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 StrWidth = 0;
    S32 Counter = 0;
    S32 nHeight = 0;
    U16 unicode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pHeight = 0;
    *pWidth = 0;

    if (String == NULL)
    {
        return;
    }

    while (1)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        memcpy(&unicode, String, 2);

        Get_CharWidthHeight(unicode, &StrWidth, &nHeight);
        /* Consider the Thai String length is different from others */

        (*pWidth) += (StrWidth + w);
        if (*pHeight < nHeight)
        {
            *pHeight = nHeight;
        }
        Counter++;

        String += 2;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_w
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String      [?]         
 *  w           [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_w(U8 *String, S32 w, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen= 0;
    S32 baseline = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);
    Get_StringWidthHeight_internal(String, w, nLen, pWidth, pHeight, MMI_FALSE, -1, 0, &baseline);
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_wn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String      [?]         
 *  w           [IN]        
 *  n           [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_wn(U8 *String, S32 w, S32 n, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 baseline = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight_internal(String, w, n, pWidth, pHeight, MMI_FALSE, -1, 0, &baseline);
    
}

/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_variant
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String          [?]         
 *  w               [IN]        
 *  n               [IN]        
 *  pWidth          [?]         
 *  pHeight         [?]         
 *  max_width       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 Get_StringWidthHeight_variant(U8 *string, S32 w, S32 n, S32 *pWidth, S32 *pHeight, S32 max_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 baseline = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return Get_StringWidthHeight_internal(string, w, n, pWidth, pHeight, MMI_TRUE, max_width, 0, &baseline);
}

/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String       [?]         
 *  w             [IN]        
 *  n              [IN]        
 *  pWidth      [?]         
 *  pHeight     [?] 
 *  targetWidth  [IN]
 *  checklinebreak [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_StringWidthHeight_internal(
            U8 *String, 
            S32 w, 
            S32 n, 
            S32 *pWidth, 
            S32 *pHeight,
            MMI_BOOL enableTruncated,
            S32 targetWidth, 
            U8 checklinebreak,
            S32 *baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 StrWidth = 0;
    S32 Counter = 0;
    S32 nHeight = 0;
    U16 unicode = 0;
    U16 curCh = 0, preCh = 0, pre2Ch = 0;
    S32 prev_width = 0;
    S32 prev_height = 0;
    U32 numofChar = 0;
    S32 ascent = 0, descent = 0;
    S32 max_ascent = 0, max_descent = 0;

#if defined(__MMI_LANG_VIETNAMESE__)
    U16 next_unicode = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

#ifdef __MMI_BIDI_ALG__
    S32 nLen;
#endif

#if defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_INDIC_ALG__)
    S32 check_len = n; /* used to check every character in the string */
    U8 *temp_string = String;
#endif
#if defined(__MMI_ARSHAPING_ENGINE__)
    MMI_BOOL IS_ARABIC = MMI_FALSE;
#endif
#if defined(__MMI_INDIC_ALG__)
    MMI_BOOL IS_INDIC = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialization */
    *pHeight = 0;
    *pWidth = 0;
    /* error check */
    if (String == NULL || n == 0 || (enableTruncated && targetWidth == 0))
    {
        return numofChar;
    }

    /* check if shaping is necessary */
#if defined(__MMI_ARSHAPING_ENGINE__)
    temp_string = String;
    check_len = n;
    while (check_len != 0)
    {
        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);

        if (IS_ARABIC_CHARACTER(unicode))
            IS_ARABIC = MMI_TRUE;
        if (IS_ARABIC)
            break;
        temp_string += 2;
    }
    
#endif

    *baseline = 0;
    *pHeight = 0;
    *pWidth = 0;
#ifdef __MMI_INDIC_ALG__
    /* check if calling IRE is necessary */
    temp_string = String;
    check_len = n; 
    while (check_len != 0)
    {
        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);

        if(IRE_INDIC_LANGUAGE_RANGE(unicode))
            IS_INDIC = MMI_TRUE;
        if (IS_INDIC)
            break;
        temp_string += 2;
    }

    if (!IS_INDIC)
    {
    #if defined(__MMI_ARSHAPING_ENGINE__)
        if (IS_ARABIC)
        {
            /* there is no Indic character but there is Arabic character. Shaping should be applied. */
            nLen = mmi_ucs2strlen((const char*)String);
            //MMI_ASSERT(!(nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH));
            if (nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH) nLen = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
            if (n < nLen) nLen = n;
            mmi_ucs2ncpy((S8*) show_pwcWord, (S8*) String,nLen);
            show_pwcWord[nLen] = 0;
            nLen = mmi_ucs2strlen((const char*)show_pwcWord);
            if (enableTruncated)
            {
                memset(fe_ShaToOrg, 0x00, MAX_SHOW_STRING_TEXT_LENGTH);
                ArabicShapeEngine2_ext((U16*)&nLen, (U16*)show_pwcWord, NULL, fe_ShaToOrg);
            }
            else
            {
                ArabicShapeEngine_ext((U16*)&nLen, (U16*)show_pwcWord);
            }
            String = (U8*) show_pwcWord;
        }
    #endif
        goto COUNTING_DIRECTLY;
    }

    if (ire_is_reset_indic_params())
    {
        ire_reset_indic_params();
    }
    if (ire_is_indic_rules_parsing())
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length;
        U16 glyph_output[G_MAX];
        S32 Len;
        S32 len;

        S32 total_len = 0;
        S32 original_len = 0;
        
        S32 width, height;
        U8 indic_width_adjustment_flag=0;
        U8 temp_flag =0;
        PU8 CharData=NULL;
	 U16 nWidth = 0;
        U16 nDWidth = 0;
        U16 nHgt = 0;
        U16 dtWidth = 0, dtHgt = 0;
        U16 ascent = 0;
        U16 descent = 0;
        stFontAttribute Font;

#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
    overwrite_current_language_for_hindi_rules_based_on_input_method();
#endif /*defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )*/
        pre2Ch = 0;
        preCh = 0;
        
         memset( (U16 *)glyph_output, '\0', sizeof(glyph_output)); 
         memset( (U16 *)cluster_fill, '\0', sizeof(cluster_fill));

        if (String == NULL)
        {
            return numofChar;
        }
    #if defined(__MMI_ARSHAPING_ENGINE__)
        nLen = mmi_ucs2strlen((const char*)String);
        //MMI_ASSERT(!(nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH));
        if(nLen>MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH) nLen = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
        if(n< nLen) nLen = n;
        if (IS_ARABIC)
        {
            mmi_ucs2ncpy((S8*) show_pwcWord, (S8*) String,nLen);
            show_pwcWord[nLen] = 0;
            nLen = mmi_ucs2strlen((const char*)show_pwcWord);
            if (nLen)
            {
                if (enableTruncated)
                {
                    memset(fe_ShaToOrg, 0x00, MAX_SHOW_STRING_TEXT_LENGTH);
                    ArabicShapeEngine2_ext((U16*)&nLen, (U16*)show_pwcWord, NULL, fe_ShaToOrg);
                }
                else
                {
                    ArabicShapeEngine_ext((U16*)&nLen, (U16*)show_pwcWord);
                }
            }
            String = (U8*) show_pwcWord;
        }
    #endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 
        ire_init_cluster_start_p(String);
        len = gui_strlen((UI_string_type) String);
    
        if (len > 0)
        {
            ire_init_cluster_end_p(String + (len * 2));
        }
        else
        {
            ire_init_cluster_end_p(String + (2 * mmi_ucs2strlen((const char*)String) + 1));
        }
        original_len = len;
    
        ire_disable_indic_rules_parsing();
        ire_disable_indic_reset_hindi_params();
        /* This loop takes the string cluster by cluster and finds the width  */
	/* and height of the string                                           */
        do
        {
    
	    if (total_len == original_len)
                break;
			
            cluster_length = ire_get_cluster(cluster_fill);
            total_len += cluster_length;
            if (original_len > 0)
            {
                if (total_len > original_len || total_len > n)
                {
                    break;
                }
            }
    
            if (cluster_length)
            {
                Len = ire_language_rules(glyph_output, cluster_fill, ire_get_display_buffer_len());
		Get_StringWidthHeight_w((U8*) glyph_output,w,&width, &height );
                if (height > *pHeight)
                {
                    *pHeight = height;
                }
                *pWidth += width;
                if ((!indic_width_adjustment_flag))
                {
                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(*glyph_output))
                    {
                        GetFontdata(
                            (U16) (glyph_output[0]),
                            Font,
                            &CharData,
                            &nWidth,
                            &nDWidth,
                            &nHgt,
                            &dtWidth,
                            &dtHgt,
                            &ascent,
                            &descent);
                        indic_width_adjustment_flag = 1;
                    }
                    else
                    {
                        indic_width_adjustment_flag = 2;
                    }

                }
                if ((indic_width_adjustment_flag == 1) && (!IRE_INDIC_CHARACTER_UCS2_RANGE(*glyph_output)))
                {
                    (*pWidth) += (nWidth - nDWidth);
                    indic_width_adjustment_flag = 0;
                    temp_flag = 1;
                }
                if ((indic_width_adjustment_flag == 2) && (IRE_INDIC_CHARACTER_UCS2_RANGE(*glyph_output)))
                {
                    GetFontdata((U16) (glyph_output[0]), Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt,&ascent,&descent);
                    (*pWidth) += (nWidth - nDWidth);
                    indic_width_adjustment_flag = 0;
                }
    /* MTI START MAUI_00038534 */
               	#if defined(__MMI_LANG_VIETNAMESE__)	
                if ((glyph_output[0] > 0x0040) && (glyph_output[0] < 0x01B1))
                {
                    U16 *next_unicode = (U16 *) ire_get_cluster_start_p();                                  
                    tone_mark = mmi_viet_tone_mark(*next_unicode);
                        if (VIET_TONE_NONE != tone_mark)
                        {
                        viet_vowel = mmi_viet_vowel_letter(glyph_output[0]);
                        if (VIET_VOWEL_NONE != viet_vowel)
                        {
                            glyph_output[0] = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                            ire_increment_cluster_start_p(2); 
                            

                            
                        }
                    }
                    
                    
                     
                }
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
                /* MTI END MAUI_00038534 */
                    if (enableTruncated)
                    {
                        if ((*pWidth) > targetWidth)
                        {
                            *pWidth = prev_width;
                            *pHeight = prev_height;
                            break;
                        }
                        else
                        {
                        #if defined(__MMI_ARSHAPING_ENGINE__)
                            if (IS_ARABIC)
                            {
                                numofChar = fe_ShaToOrg[total_len - 1];
                            }
                            else
                        #endif
                            {
                                numofChar += cluster_length;
                            }
                        }
                    }		

            }
        } while (cluster_length);
        if ((temp_flag) && (IRE_INDIC_CHARACTER_UCS2_RANGE(*glyph_output)))
        {

            GetFontdata((U16) (glyph_output[0]), Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt,&ascent,&descent);
            (*pWidth) += (nWidth - nDWidth);
        }

        ire_enable_indic_rules_parsing();
        ire_enable_indic_reset_indic_params();
        return numofChar;
    }
#endif /* __MMI_INDIC_ALG__ */ 


    if (String == NULL)
    {
        return numofChar;
    }
#if defined (__MMI_ARSHAPING_ENGINE__) && !defined(__MMI_INDIC_ALG__)    
    if (!IS_ARABIC)
        goto COUNTING_DIRECTLY;
    
    nLen = mmi_ucs2strlen((const char*)String);
    /* MMI_ASSERT(!(nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH)); */
    if (nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH)
        nLen = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
    if (n < nLen)
        nLen = n;
    /* mmi_ucs2cpy((S8*) show_pwcWord, (S8*) String); */
    mmi_ucs2ncpy((S8*) show_pwcWord, (S8*) String, nLen);
    show_pwcWord[nLen] = 0;
    nLen = mmi_ucs2strlen((const char*)show_pwcWord);
    if (enableTruncated)
    {
        memset(fe_ShaToOrg, 0x00, MAX_SHOW_STRING_TEXT_LENGTH);
        ArabicShapeEngine2_ext((U16*)&nLen, (U16*)show_pwcWord, NULL, fe_ShaToOrg);
    }
    else
    {
        ArabicShapeEngine_ext((U16*)&nLen, (U16*)show_pwcWord);
    }
    String = (U8*) show_pwcWord;
#endif /* defined (__MMI_ARSHAPING_ENGINE__) && !defined(__MMI_INDIC_ALG__)   */ 

#if defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_INDIC_ALG__)
COUNTING_DIRECTLY:
#endif

    *pHeight = 0;
    *pWidth = 0;

    while (Counter < n)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        prev_width = *pWidth;
        prev_height = *pHeight;
        memcpy(&unicode, String, 2);
    #if defined(__MMI_LANG_VIETNAMESE__)
        if ((unicode > 0x0040) && (unicode < 0x01B1))
        {
            next_unicode = String[2];
            next_unicode |= (String[3] << 8);
            tone_mark = mmi_viet_tone_mark(next_unicode);
            if (VIET_TONE_NONE != tone_mark)
            {
                viet_vowel = mmi_viet_vowel_letter(unicode);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    unicode = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    String += 2;
                    //n += 1;
                    Counter += 1;
                }
            }
        }
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
        Get_CharWidthHeight_internal(unicode, &StrWidth, &nHeight, &ascent, &descent);
        /* Consider the Thai String length is different from others */
        curCh = unicode;
    #if defined(__MMI_LANG_THAI__)
        if (curCh >= 0x0E01 && curCh <= 0x0E7F)
        {
            //curCh = unicode;
            // Base line character, can combinate with above vowels,bottom vowels, tone mark, and sign
            if (IsThaiBaseLineChar(curCh))
            {
                //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
                //moved ahead to let the circyle sign on the top of previous or previous2 character
                if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
                {
                    *pWidth = *pWidth - 4 + (S32) StrWidth + w;
                }
                else
                {
                    *pWidth = *pWidth + (S32) StrWidth + w;
                }
            }
            /* For Thai digits and base line sign, the only thing we have to do is moving cursor */
            else if (IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
            {
                *pWidth = *pWidth + (S32) StrWidth;
            }
            else if (IsThaiToneMark(curCh))
            {
                if (IsThaiBaseLineChar(preCh) || IsThaiAboveLineChar(preCh) || IsThaiBottomLineChar(preCh))
                {
                }
                else if (preCh == 0x0E47 || preCh == 0x0E4C)
                {
                    /* move the tone mark to next character space */
                    *pWidth = *pWidth + (S32) StrWidth + w;
                }
                else
                {
                    *pWidth = *pWidth + (S32) StrWidth  + w;
                }
            }

            if (*pHeight < gThaiLineHeight)
            {
                *pHeight = gThaiLineHeight; /* If  the string has Thai characters,the height will become gThaiLineHeight(now the value is 17) */
            }
            pre2Ch = preCh;
            preCh = curCh;
        }
        else
    #endif /* defined(__MMI_LANG_THAI__) */
    #ifdef __MMI_INDIC_ALG__
            if (IRE_INDIC_CHARACTER_UCS2_RANGE(curCh))
            {
                U16 nextCharUCS2;
                U32 curCh_type=0;
                memcpy(&nextCharUCS2, String + 2, 2);
                curCh_type = ire_identify_char_small_consonant_family(curCh);
                if (IRE_GET_SMALL_CONSONANT_FLAG() && (curCh_type==IRE_CHAR_TYPE_SIGN_CONSONANT))
                {
                    
                    /* PMT START MAUI_00027833 */
                    if(IRE_IS_RENDERING_CORRECTION())
                    {
                        
                        U16 previousCharUCS2 = 0 ;
                        PU8 index  = NULL;
                        S32 prev_width = 0;
                        index = String - 2;
                        previousCharUCS2 = (index[1] << 8) | index[0] ;
                        Get_CharWidth(curCh, &StrWidth);
                        Get_CharWidth(previousCharUCS2, &prev_width);

                        if ((curCh_type == IRE_CHAR_TYPE_SIGN_CONSONANT)  /* && ( ire_identify_character_type(previousCharUCS2) != 3 ) */ 
                            && (*pWidth < StrWidth + IRE_IS_RENDERING_CORRECTION()))
                        {
                            
                            if(!IRE_UI_INDIC_SIGN_RANGE(previousCharUCS2))
                            {
                                *pWidth -= prev_width;
                                (*pWidth) += (StrWidth + IRE_IS_RENDERING_CORRECTION()) ;
                            }
                            else
                            {
                                (*pWidth) = StrWidth + IRE_IS_RENDERING_CORRECTION();
                            }
                            IRE_RESET_RENDERING_CORRECTION();
                        }
                        else if( prev_width < StrWidth)
                        {
                            *pWidth += (StrWidth - prev_width);
                            IRE_RESET_RENDERING_CORRECTION();
                        }
                        else
                        {
                            (*pWidth) += 0;
                        }


                        IRE_RESET_RENDERING_CORRECTION();    
                    }
                    else
                    {
                        (*pWidth) += 0;
                        IRE_RESET_RENDERING_CORRECTION(); 
                    }
                  
                    
                    IRE_RESET_SMALL_CONSONANT_FLAG();
                }
                else if ((IRE_UI_INDIC_SIGN_RANGE(curCh) || (curCh_type==IRE_CHAR_TYPE_SPECIAL_SIGN)) &&
                     (!(curCh_type==IRE_CHAR_TYPE_SIGN_CONSONANT)))
                {
                    (*pWidth) += 0;
                    if (curCh_type==IRE_CHAR_TYPE_SPECIAL_SIGN)
                     {
                        
                        /* PMT START MAUI_00027833 */
                        IRE_RESET_RENDERING_CORRECTION();
                        /* PMT END MAUI_00027833 */ 
                         IRE_RESET_SMALL_CONSONANT_FLAG();
                     }

                }
                else
                {
                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(nextCharUCS2) || nextCharUCS2 == 0)
                    {
                        (*pWidth) += StrWidth;
                    }
                    else
                    {
                        Get_CharWidth(curCh, &StrWidth);
                        (*pWidth) += StrWidth;
                    }
                    if (IRE_GET_SMALL_CONSONANT_FLAG() && (curCh_type==IRE_CHAR_TYPE_NORMAL_CONSONANT))
                     {
                        /* PMT START MAUI_00027833 */
                        IRE_RESET_RENDERING_CORRECTION();
                        /* PMT END MAUI_00027833 */ 
                         IRE_RESET_SMALL_CONSONANT_FLAG();
                     }

                }
            }
            else
#endif /* __MMI_INDIC_ALG__ */ 
        {
            (*pWidth) += (StrWidth + w);
        }

        if (*pHeight < nHeight)
        {
            *pHeight = nHeight;
        }
        if (*baseline < ascent)
            *baseline = ascent;
        if (max_ascent < ascent)
            max_ascent = ascent;
        if (max_descent < descent)
            max_descent = descent;
        if (enableTruncated)
        {
            if ((*pWidth) > targetWidth)
            {
                *pWidth = prev_width;
                *pHeight = prev_height;
                return numofChar;
            }
            else
            {
            #if defined(__MMI_ARSHAPING_ENGINE__)
                if (IS_ARABIC)
                {
                    numofChar = fe_ShaToOrg[Counter] + 1;
                }
                else
            #endif
                {
                    numofChar = Counter + 1;
                }
            }
        }        
        Counter++;

        String += 2;
    }

    if (*pHeight < max_ascent + max_descent)
    {
        *pHeight = max_ascent + max_descent;
    }
    
    UI_UNUSED_PARAMETER(pre2Ch);
    UI_UNUSED_PARAMETER(preCh);

    return numofChar;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharHeight
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharHeight()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) gpCurrentFont->nHeight;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightofAllType
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayHeightofAllType()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) (gpCurrentFont->nHeight + 2);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharAscent
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharAscent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) gpCurrentFont->nAscent;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDescent
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDescent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) gpCurrentFont->nDescent;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayDescentOfAllType
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayDescentOfAllType()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) (gpCurrentFont->nDescent + 1);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayAscentOfAllType
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayAscentOfAllType()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) (gpCurrentFont->nAscent + 1);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightOfAllLangAndType
 * DESCRIPTION
 *  To get maximum char height regardless of language and font type 
 *  
 *  Justin. for WAP layout formating.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayHeightOfAllLangAndType(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (Get_CharHeightOfAllLang(size) + 2);
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharHeightOfAllLang
 * DESCRIPTION
 *  To get maximum char height regardless of language
 *  
 *  Justin. for WAP layout formating.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharHeightOfAllLang(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lang_index;
    sFontFamily *pFontFamily;
    S32 height = 0, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (lang_index = 0; lang_index < gMaxDeployedLangs; lang_index++)
    {
        pFontFamily = gLanguageArray[lang_index].fontfamilyList[gLanguageArray[lang_index].nCurrentFamily];
        if ((h = (S32) pFontFamily->fontData[size]->nHeight) > height)
        {
            height = h;
        }
    }

    if (height < (S32) gMTKProprietaryFont.nHeight)
    {
        height = (S32) gMTKProprietaryFont.nHeight;
    }

#if defined(__MMI_ZI__)
    if (height < (S32) gZiExtraCharacter.nHeight)
    {
        height = (S32) gZiExtraCharacter.nHeight;
    }
#endif /* defined(__MMI_ZI__) */ 

    return height;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringHeight
 * DESCRIPTION
 *  To get string height
 *  
 *  This is used to get string height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_StringHeight()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sFontFamily *pFontFamily;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pFontFamily = gLanguageArray[gCurrLangIndex].fontfamilyList[gLanguageArray[gCurrLangIndex].nCurrentFamily];
    return (S32) (pFontFamily->fontData[gnCurrentFont]->nHeight);

#if 0
/* under construction !*/
#endif /* 0 */ 
}

/*****************************************************************************
 * FUNCTION
 *  Get_StringLength_InCluster
 * DESCRIPTION
 *  Get the string length in cluster 
 * PARAMETERS
 *  input_str       [IN]        
 *  len             [IN]        
 *  base_len        [IN]        
 * RETURNS
 *  U32 - the string length according the clusters
 *****************************************************************************/
U32 Get_StringLength_InCluster(U8* input_str, U32 len, U32 base_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 val = base_len; /* Assume the string length in cluster is the same with base_len */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INDIC_ALG__
    if (ire_is_reset_indic_params())
    {
        ire_reset_indic_params();
    }
    if (ire_is_indic_rules_parsing())
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length = 0;
        S32 total_len = 0;

        ire_init_cluster_start_p(input_str);
        ire_init_cluster_end_p(input_str + (len *2));
        ire_disable_indic_rules_parsing();
        ire_disable_indic_reset_hindi_params();

        /*This loop takes the string cluster by cluster and renders the string*/
        do
        {
            if (total_len >= len)
            {
                /* Parsing the string finished */
                break;
            }
     		
            cluster_length = ire_get_cluster(cluster_fill);
            total_len += cluster_length;
            if (total_len > base_len)
            {
                /* 
                 * the total_len according the clusters is larger than base_len. 
                 * Don't need to paser continually. 
                 */
                break;
            }
        } while (cluster_length);

        ire_enable_indic_rules_parsing();
        ire_enable_indic_reset_indic_params();

        if (total_len > base_len)
        {
            /*
             * The endding character is part of the cluster.
             * We will discard that part.
             */
            val = total_len - cluster_length;
        }
        else
        {
            val = total_len;
        }
    }
#endif /* __MMI_INDIC_ALG__ */

    return val;
}



/*****************************************************************************
 * FUNCTION
 *  TestDiffFonts
 * DESCRIPTION
 *  To test the different fonts with diferent sizes.
 *  
 *  This is used to test the different fonts with diferent sizes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *  
 *****************************************************************************/
void TestDiffFonts()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0, y = 20;
    stFontAttribute fontInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontInfo.bold = 0;
    fontInfo.italic = 0;
    fontInfo.underline = 0;

    fontInfo.size = 9;  /* (size 8..15 FOR type 2..5 ) & (size 9...15 FOR type 1 ) */
    fontInfo.type = 1;  /* 1...5 */

    for (count = 0; count < 2; count++)
    {
        ShowString(0, y, fontInfo, 0, (PU8) "abcdefghij", 30);
        y += 20;

        ShowString(0, y, fontInfo, 0, (PU8) "klmnopqrst", 30);
        y += 20;

        ShowString(0, y, fontInfo, 0, (PU8) "uvwxyz", 30);
        fontInfo.size += 1;
        y += 20;

    }
}


/*****************************************************************************
 * FUNCTION
 *  Get_FontHeight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f               [IN]        
 *  arrCount        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 Get_FontHeight(stFontAttribute f, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sFontFamily *pFontFamily;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pFontFamily = gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily];
    return (S32) (pFontFamily->fontData[f.size]->nHeight);
}


/*****************************************************************************
 * FUNCTION
 *  RequireToMoveCursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  preCh       [IN]        
 *  curCh       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL RequireToMoveCursor(U16 preCh, U16 curCh)
{
#if defined(__MMI_LANG_THAI__)
    pBOOL isPreBaseLineChar = IsThaiBaseLineChar(preCh);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curCh >= 0x0E01 && curCh <= 0x0E7F)
    {

        if (IsThaiBaseLineChar(curCh) || IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
        {   /* For base level character */
            return TRUE;
        }
        else if (IsThaiAboveLineChar(curCh))
        {   /* For above level character */
            if (isPreBaseLineChar)
            {
                return FALSE;
            }
            /*else if (curCh == 0x0E4C && preCh != 0x0E4C && preCh != 0x0E47)
            {
                return FALSE;
            }*/
            else
            {
                return TRUE;
            }

        }
        else if (IsThaiBottomLineChar(curCh))
        {   /* For below level character */
            if (isPreBaseLineChar)
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }
        }
        else if (IsThaiToneMark(curCh))
        {   /* For Tone mark characters */

            if (isPreBaseLineChar || IsThaiAboveLineChar(preCh) || IsThaiBottomLineChar(preCh))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }

        }
        else
        {
            return TRUE;
        }
    }
    else
#endif
    {
        return TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ShowCharFuncDispatch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  LineHeight      [IN]        
 *  nWidth          [IN]        
 *  nHgt            [IN]        
 *  CurrentX        [IN]        
 *  CurrentY        [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  CharData        [?]         
 *  NumChar         [IN]        
 *  Bordered        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void ShowCharFuncDispatch(
                        U32 LineHeight,
                        U16 nWidth,
                        U16 nHgt,
                        S32 CurrentX,
                        S32 CurrentY,
                        stFontAttribute Font,
                        U8 BackGround,
                        U8 *CharData,
                        U32 NumChar,
                        U32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nXOffset, nYOffset;
    U8 font_attr = 0;
    gdi_color border_color = 0, text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    {
        if (Bordered)
        {
            border_color = gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
        }

        text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    }

    /*
     * MTK Terry to consider Thai display in ShowStackedString
     * if(LineHeight>0)
     * {
     * 
     * if(LineHeight==gThaiLineHeight ) //If the line height is equal to 17 points
     * CurrentY+=(LineHeight-(S32)nHgt-1); // Lower one pixel to centralize ThaiFont
     * else
     * CurrentY+=(LineHeight-(S32)nHgt);
     * 
     * }
     */
    nXOffset = CurrentX + nWidth;
    nYOffset = CurrentY + nHgt;
    if (Bordered)
    {
        gdi_show_char_bordered(
            CurrentX,
            CurrentY,
            text_color,
            border_color,
            CharData,
            NumChar,
            nWidth,
            nHgt,
            font_attr);
    }
    else if (!
             (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
              gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
             !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {
        gdi_show_char(CurrentX, CurrentY, text_color, CharData, NumChar, nWidth, nHgt, font_attr);
    }
    else
    {
        gdi_show_char(CurrentX + 1, CurrentY, text_color, CharData, NumChar, nWidth, nHgt, font_attr);
        gdi_show_char(CurrentX, CurrentY, text_color, CharData, NumChar, nWidth, nHgt, font_attr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowStackedString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  CurrentX        [IN]        
 *  CurrentY        [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 *  Bordered        [IN]        
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowStackedString(
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
        U8 assign_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* GDI_ENTER_CRITICAL_SECTION(ShowStackedString) */
    U8 *CharData;
    U32 NumChar;
    U16 nHgt;
    U16 nWidth;
    U16 dtHgt;
    U16 dtWidth;
    S32 baseline = 0;
    S32 temp_len = 0;
    BOOL has_thai_char = MMI_FALSE;
    S32 iX = 0, iY = 0;
    static U16 curCh = 0, preCh = 0, pre2Ch = 0, nextCharUCS2 = 0;
    gdi_color border_color, text_color;
    U8 font_attr = 0;
    S32 str_width, str_height;
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    /* the x width of string */
    U32 string_width = 0;
    S32 truncated_x_boundary = 0;
    U16 ascent = 0, descent = 0;

#if defined(__MMI_LANG_VIETNAMESE__)
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
#ifdef __MMI_INDIC_ALG__
    U16 nDWidth = 0;
    static S32 single_time_bidi = 0; 
#if defined(__MMI_BIDI_ALG__)    
    static S32 hindi_rule_string = 1;
#endif
#endif /* __MMI_INDIC_ALG__ */ 

#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U8 *temp_text_P;
    U16 visual_str_len;
    U16 visual_cur_pos;
    S32 nLen;
    U16 visual_hilight_start;
    U16 visual_hilight_end;
#endif /* __MMI_BIDI_ALG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Error check */
    if (len == 0)
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    if (String == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    if (Bordered && 
        UI_text_border_color.r == TRANSPARENT_COLOR_R && 
        UI_text_border_color.g == TRANSPARENT_COLOR_G && 
        UI_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        Bordered = 0;
    }



    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    
    Get_StringWidthHeight_internal(String, 0, mmi_ucs2strlen((const char *)String), &str_width, &str_height, MMI_FALSE, -1, 0, &baseline);
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	mmi_trace_screen_string(CurrentX, CurrentY, String, len, Bordered);
#endif
#ifdef __MMI_INDIC_ALG__
    if (!single_time_bidi && !cancelWidth)
#endif 
    {
    #ifdef __MMI_BIDI_ALG__
        nLen = mmi_ucs2strlen((const char*)String);
        if(nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH) 
            len = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
//        MMI_ASSERT(!(nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH));
        if (len > 0)
        {
            mmi_ucs2ncpy((S8*) show_pwcWord, (S8*) String, len);
        }
        else
        {
            mmi_ucs2cpy((S8*) show_pwcWord, (S8*) String);
        }
        nLen = mmi_ucs2strlen((const char*)show_pwcWord);
    #if defined(__MMI_ARSHAPING_ENGINE__)
        ArabicShapeEngine_ext((U16*)&nLen, show_pwcWord);
    #endif /* __MMI_ARSHAPING_ENGINE__ */
        String = (U8*) show_pwcWord;
        logical_cur_pos = 0;

        if (assign_direction == BIDI_R || assign_direction == AL)
        {
            bidi_main(
                (U8*) String,
                (U16) mmi_ucs2strlen((const S8*)String),
                logical_cur_pos,
                show_visual_str,
                &visual_str_len,
                &visual_cur_pos,
                MMI_TRUE,
                MMI_bidi_input_type,
                0,
                0,
                &visual_hilight_start,
                &visual_hilight_end);
            assign_direction = BIDI_R;
        }
        else    /* if(default_direction == BIDI_L) */
        {
            bidi_main(
                (U8*) String,
                (U16) mmi_ucs2strlen((const S8*)String),
                logical_cur_pos,
                show_visual_str,
                &visual_str_len,
                &visual_cur_pos,
                MMI_FALSE,
                MMI_bidi_input_type,
                0,
                0,
                &visual_hilight_start,
                &visual_hilight_end);
            assign_direction = BIDI_L;
        }
    #ifdef __MMI_INDIC_ALG__
        if (r2lMMIFlag)
        {
            ire_get_indic_rules_for_whole_string(show_visual_str);
            hindi_rule_string = 0;
        }
    #endif /* __MMI_INDIC_ALG__ */ 
        if ((r2lMMIFlag && assign_direction == BIDI_L) || (!r2lMMIFlag && assign_direction != BIDI_L))
        {
            bidi_reverse(show_visual_str, (U16) mmi_ucs2strlen((const S8*)show_visual_str));
        }

        temp_text_P = String;
        String = show_visual_str;
    #endif /* __MMI_BIDI_ALG__ */ 
    }

    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    if (Bordered)
    {
        border_color = gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
    }
    text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    gdi_font_begin(text_color, font_attr);

    /* check x boundary for truncated string display */
    if (enableTruncated)
    {
        if (r2lMMIFlag)
        {
            truncated_x_boundary = CurrentX - xwidth_boundary;
        }
        else
        {
            truncated_x_boundary = CurrentX + xwidth_boundary;
        }
    }
    //UI_current_text_color = UI_text_color;
    //Process string
#ifdef __MMI_INDIC_ALG__
    if (ire_is_reset_indic_params())
    {
        ire_reset_indic_params();
    }
    if (Font.color == 0)
    {
        Font.color = 15;
    }
    //For hindi character sudden disappear 
    //UI_current_text_color = UI_text_color;
    if (ire_is_indic_rules_parsing())
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length;
        U16 glyph_output[G_MAX];
        S32 Len;
        S32 total_len = 0;
        S32 original_len = 0;
        S32 width, height;
        pre2Ch = 0;
        preCh = 0;
        ire_init_cluster_start_p(String);
        if (len > 0)
        {
            ire_init_cluster_end_p(String + (len * 2));
        }
        else
        {
            ire_init_cluster_end_p(String + (2 * mmi_ucs2strlen((const char*)String) + 1));
        }
        original_len = len;
        ire_disable_indic_rules_parsing();
        ire_disable_indic_reset_hindi_params();
        /* W05.34 For Hindi with Bidi issue */
        single_time_bidi = 1;
        do
        {
			cluster_length = ire_get_cluster(cluster_fill);

            total_len += cluster_length;
            if (original_len > 0)
            {
                if (total_len > original_len)
                {
                    break;
                }
            }
            if (cluster_length)
            {
	        Len = ire_language_rules(glyph_output, cluster_fill, ire_get_display_buffer_len());
                Get_StringWidthHeight((U8*) glyph_output, &width, &height);
                /* Cluster shouldn't be truncated. Check the width */
                if (truncated_symbol != NULL && string_width + width > xwidth_boundary)
                    break;
                ShowStackedString(CurrentX, CurrentY, Font, BackGround, (U8*) glyph_output, LineHeight, Bordered, len, MMI_FALSE, NULL, -1, assign_direction);
                CurrentX += width;
            }
        } while (cluster_length);
        /* print truncated symbol */
        if (enableTruncated && truncated_symbol != NULL)
        {
            ShowStackedString(CurrentX, CurrentY, Font, BackGround, truncated_symbol, LineHeight, Bordered, -1, MMI_FALSE, NULL, -1, assign_direction);
        }        
        ire_enable_indic_rules_parsing();
        ire_enable_indic_reset_indic_params();
        /* W05.34 For Hindi with Bidi issue */
        single_time_bidi = 0;
        gdi_font_end();

        return MMI_FONT_ENGINE_NO_ERROR;
        /* GDI_RETURN(0); */
    }
#endif /* __MMI_INDIC_ALG__ */ 

    if (r2lMMIFlag)
    {

        while (1)
        {
            curCh = (String[temp_len] | (String[temp_len + 1] << 8));
            if (curCh >= 0x0E01 && curCh <= 0x0E7F)
            {
                has_thai_char = MMI_TRUE;
                break;
            }
            temp_len += 2;
            if (curCh == 0x0000)
            {
                break;
            }
        }

        if (has_thai_char == MMI_TRUE)
        {
            bidi_reverse(String, (U16) mmi_ucs2strlen((const S8*)String));
            Get_StringWidthHeight(String, &str_width, &str_height);
            if (enableTruncated)
            {
                S32 truncate_width = 0;
                S32 truncate_height = 0;
                if (truncated_symbol != NULL)
                    Get_StringWidthHeight(truncated_symbol, &truncate_width, &truncate_height);
                    
                CurrentX -= (xwidth_boundary + truncate_width);
                truncated_x_boundary = CurrentX + xwidth_boundary;

            }
            else
            {
                CurrentX -= str_width;
            }
        }

    }

    while (len != 0)
    {
    NEXT:
        iX = CurrentX;
        iY = CurrentY;
        /* prepare the unicode of current and next characters */
        curCh = (String[0] | (String[1] << 8));
        nextCharUCS2 = (String[2] | (String[3] << 8));

        if (curCh == 0x0000)
        {
            break;
        }

        len--;

        if (FONT_TEST_CONTROL_CHAR(curCh) || (FONT_TEST_SPACE_CHAR(curCh) && !FONT_TEST_ZERO_WIDTH_SPACE(curCh)))
        {
            curCh = 0x20;
        }
        if (FONT_TEST_ZERO_WIDTH_SPACE(curCh)||
            FONT_TEST_FORMATTING_CHARS(curCh) || 
            (FONT_TEST_DATE_CHARS(curCh) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR))) ||
            (FONT_TEST_CRLF_ANF_SPACE_PROPRIETARY_SYMBOL(curCh) && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
        {
            String+=2;
            if (len == 0)
                break;
            pre2Ch = preCh;
            preCh = curCh;
            goto NEXT;
        }
    #if defined(__MMI_LANG_VIETNAMESE__)
        if ((curCh > 0x0040) && (curCh < 0x01B1))
        {
            tone_mark = mmi_viet_tone_mark(nextCharUCS2);
            if (VIET_TONE_NONE != tone_mark)
            {
                viet_vowel = mmi_viet_vowel_letter(curCh);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    curCh = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    String += 2;
                }
            }
        }
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    #if defined(__MMI_INDIC_ALG__)
        NumChar = GetFontdata(curCh, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
        ire_get_text_x(&iX, curCh, iY, nDWidth, nWidth);
    #else /* defined(__MMI_INDIC_ALG__) */ 
        NumChar = GetFontdata(curCh, Font, &CharData, &nWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
    #endif /* defined(__MMI_INDIC_ALG__) */ 

#ifdef __MMI_LANG_THAI__
        /* check if current character is in Thai character ranges */
        if (curCh >= 0x0E01 && curCh <= 0x0E7F)
        {
            /* Base line character, can combinate with above vowels,bottom vowels, tone mark, and sign */
            if (IsThaiBaseLineChar(curCh))
            {
                //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
                //moved ahead to let the circyle sign on the top of previous or previous2 character
                if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
                {
                    iX -= 4;
                }
                CurrentX = (iX + (S32) nWidth);
            }
            /* For Thai digits and base line sign, the only thing we have to do is moving cursor */
            else if (IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
            {
                CurrentX = (iX + (S32) nWidth);
            }
            else if (IsThaiAboveLineChar(curCh))
            {
                /* Above line characters */
                iY -= 1;    /* Reserver 1 pixtel vertical interleaving */
                if (IsThaiBaseLineChar(preCh))
                {
                    /* Process the X coordinate when combining with other base line characters */
                    iX -= ((S32) nWidth);
                    if (IsThaiLongTailChar(preCh))  /* move ahead 3 pixels, */
                    {
                        iX -= 3;
                    }
                    else if (preCh == 0x0E0A || preCh == 0x0E0B)
                    {
                        iX -= 2;
                    }
                    else if (preCh == 0x0E2C)   /* move ahead 6 pixels */
                    {
                        iX -= 6;
                    }
                }
            }
            else if (IsThaiBottomLineChar(curCh))
            {
                /* Bottom line characters */
                if (IsThaiBaseLineChar(preCh))
                {
                    iX -= ((S32) nWidth);
                    if (preCh == 0x0E2C)
                    {
                        iX -= 2;    /* move ahead for 2 pixels */
                    }
                }
            }
            else if (IsThaiToneMark(curCh))
            {
                /* Tone marks */
                iY -= 1;
                if (IsThaiBaseLineChar(preCh))
                {
                    iX -= ((S32) nWidth);
                    if (preCh == 0x0E33)
                    {
                        iY -= 3;    /* move tone mark higher */
                        if (IsThaiBaseLineChar(pre2Ch))
                        {
                            iX -= 7;    /* Move tone mark ahead across the width of */
                        }
                    }
                    else if (nextCharUCS2 == 0x0E33)
                    {
                        iY -= 3;    /* move tone mark higher */
                    }
                    else if (IsThaiLongTailChar(preCh))
                    {
                        iX -= 3;    /* move tone mark ahead for 3 pixel */
                    }
                    else if (preCh == 0x0E0A || preCh == 0x0E0B)
                    {
                        iX -= 2;
                    }
                    else if (preCh == 0x0E2C)
                    {
                        iX -= 6;
                    }
                }
                else if (IsThaiAboveLineChar(preCh))
                {
                    iY -= 3;
                    iX -= ((S32) nWidth);
                    if (IsThaiLongTailChar(pre2Ch))
                    {
                        iX -= 3;
                    }
                    else if (pre2Ch == 0x0E0A || pre2Ch == 0x0E0B)
                    {
                        iX -= 2;
                    }
                    else if (pre2Ch == 0x0E2C)
                    {
                        iX -= 6;
                    }
                }
                else if (IsThaiBottomLineChar(preCh))
                {
                    iX -= ((S32) nWidth);
                    if (IsThaiLongTailChar(pre2Ch))
                    {
                        iX -= 3;
                    }
                }
                else if (preCh == 0x0E47 || preCh == 0x0E4C)
                {
                    /* move the tone mark to next character space */
                    iX += ((S32) nWidth);
                    CurrentX += ((S32) nWidth);
                }
                else
                {
                    CurrentX += ((S32) nWidth);
                }
            }
            iY += (baseline - ascent);
            if (enableTruncated)
            {
                if (r2lMMIFlag && !has_thai_char)
                {
                    if (iX < truncated_x_boundary) break;
                }
                else
                {
                    if (iX + dtWidth > truncated_x_boundary) break;
                }
            }
            ShowCharFuncDispatch(LineHeight, dtWidth, dtHgt, iX, iY, Font, BackGround, CharData, NumChar, Bordered);
        }
        else    /* non-Thai char */
#endif //__MMI_LANG_THAI__
        {
            if (r2lMMIFlag
        #ifdef __MMI_INDIC_ALG__
                && (!cancelWidth)
        #endif 
                )
            {
            #ifdef __MMI_INDIC_ALG__
                if (IRE_INDIC_CHARACTER_UCS2_RANGE(curCh))
                {
                    if (IRE_UI_INDIC_SIGN_RANGE(preCh))
                    {
                        CurrentX -= 0;
                    }
                    else if (IRE_UI_INDIC_SIGN_RANGE(curCh))
                    {
                        CurrentX -= nWidth;
                    }
                    else
                    {
                        CurrentX -= nDWidth;
                    }
                }
                else
            #endif /* __MMI_INDIC_ALG__ */ 
                if (!has_thai_char)
                {
                    CurrentX -= nWidth;
                }
            }
        #ifndef __MMI_INDIC_ALG__
            iX = CurrentX;
        #endif 
            iY += (baseline - ascent);
            if (enableTruncated)
            {
                if (r2lMMIFlag)
                {
                    if (iX < truncated_x_boundary) break;
                }
                else
                {
                    if (iX + dtWidth > truncated_x_boundary) break;
                }
            }
            ShowCharFuncDispatch(LineHeight, dtWidth, dtHgt, iX, iY, Font, BackGround, CharData, NumChar, Bordered);

            if (!r2lMMIFlag || has_thai_char)
            {
                CurrentX += nWidth;
            }
        }
        nHgt = (U8) LineHeight;
        pre2Ch = preCh;
        preCh = curCh;
        String += 2;
        /* W05.50 Skip unnecessary action when the character is out of clip */
        if ((iX > clip_x2) && !r2lMMIFlag)
        {
            break;
        }
        string_width += nWidth;
    }
    /* Print truncated_symbol in the end */
    if (enableTruncated && truncated_symbol != NULL)
    {
        ShowStackedString(iX, CurrentY, Font, BackGround, truncated_symbol, LineHeight, Bordered, -1, MMI_FALSE, NULL, -1, assign_direction);
    }

    gdi_font_end();

    return CurrentX;
    //GDI_RETURN(CurrentX);
    //GDI_EXIT_CRITICAL_SECTION(ShowStackedString)
}


/*****************************************************************************
 * FUNCTION
 *  ShowStackedChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  CurrentX        [IN]        
 *  CurrentY        [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  curCh           [IN]        
 *  LineHeight      [IN]        
 *  Bordered        [IN]        
 *  pre2Ch          [IN]        
 *  preCh           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ShowStackedChar(
        S32 CurrentX,
        S32 CurrentY,
        stFontAttribute Font,
        U8 BackGround,
        U16 curCh,
        U32 LineHeight,
        U32 Bordered,
        U16 pre2Ch,
        U16 preCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* GDI_ENTER_CRITICAL_SECTION(ShowStackedChar) */
    U8 *CharData;
    U32 NumChar;
    /* nHgt, nWidth is the height and width of character and 
        dataHgt, dataWidth is the data height and width */    
    U16 nHgt;
    U16 nWidth;
    U16 dtWidth;
    U16 dtHgt;
    U16 ascent = 0;
    U16 descent = 0;
#ifdef __MMI_INDIC_ALG__
    U16 nDWidth;
#endif 
    S32 iX = CurrentX;
    S32 iY = CurrentY;
    gdi_color border_color = 0, text_color;
    U8 font_attr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (FONT_TEST_FORMATTING_CHARS(curCh) || curCh == 0x0)
        return;

    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    {
        if (Bordered)
        {
            border_color = gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
        }

        text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    }

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	mmi_trace_screen_char(CurrentX, CurrentY, curCh, 0, Bordered);
#endif

    if (FONT_TEST_CONTROL_CHAR(curCh) || (FONT_TEST_SPACE_CHAR(curCh) &&! FONT_TEST_ZERO_WIDTH_SPACE(curCh)))
    {
        curCh = 0x20;
    }
    if (FONT_TEST_FORMATTING_CHARS(curCh) || FONT_TEST_ZERO_WIDTH_SPACE(curCh) ||
        (FONT_TEST_DATE_CHARS(curCh) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR))) ||
        (FONT_TEST_CRLF_ANF_SPACE_PROPRIETARY_SYMBOL(curCh) && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
    {
        return;
    }
#ifdef __MMI_INDIC_ALG__
    NumChar = GetFontdata(curCh, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
#else 
    NumChar = GetFontdata(curCh, Font, &CharData, &nWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
#endif 

    gdi_font_begin(text_color, font_attr);

#ifdef __MMI_LANG_THAI__
    /* adjust iX and iY for Thai characters */
    if (curCh >= 0x0E01 && curCh <= 0x0E7F)
    {
        if (IsThaiBaseLineChar(curCh))
        {
            if (IsThaiLongTailChar(curCh))
            {
                iX += 1;
            }
            //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
            //moved ahead to let the circyle sign on the top of previous or previous2 character
            if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
            {
                iX -= 1;
            }

        }
        else if (IsThaiAboveLineChar(curCh))
        {
            /* Above line characters */
            iY -= 1;    /* Reserver 1 pixtel vertical interleaving */
            if (IsThaiBaseLineChar(preCh))
            {
                /* Process the X coordinate when combining with other base line characters */
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(preCh))  /* move ahead 3 pixels, */
                {
                    iX -= 3;
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)   /* move ahead 6 pixels */
                {
                    iX -= 6;
                }
            }

        }
        else if (IsThaiBottomLineChar(curCh))
        {
            /* Bottom line characters */
            if (IsThaiBaseLineChar(preCh))
            {
                iX -= ((S32) nWidth);
                if (preCh == 0x0E2C)
                {
                    iX -= 2;    /* move ahead for 2 pixels */
                }
            }
        }
        else if (IsThaiToneMark(curCh))
        {
            /* Tone marks */
            iY -= 1;
            if (IsThaiBaseLineChar(preCh))
            {
                iX -= ((S32) nWidth);
                if (preCh == 0x0E33)
                {
                    iY -= 3;    /* move tone mark higher */
                    if (IsThaiBaseLineChar(pre2Ch))
                    {
                        iX -= 7;    /* Move tone mark ahead across the width of */
                    }

                }
                //else if(nextCharUCS2 == 0x0E33)
                //       iY -= 3;//move tone mark higher
                else if (IsThaiLongTailChar(preCh))
                {
                    iX -= 3;    /* move tone mark ahead for 3 pixel */
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)
                {
                    iX -= 6;
                }
            }
            else if (IsThaiAboveLineChar(preCh))
            {
                iY -= 3;
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(pre2Ch))
                {
                    iX -= 3;
                }
                else if (pre2Ch == 0x0E0A || pre2Ch == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (pre2Ch == 0x0E2C)
                {
                    iX -= 6;
                }
            }
            else if (IsThaiBottomLineChar(preCh))
            {
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(pre2Ch))
                {
                    iX -= 3;
                }
            }
            else if (preCh == 0x0E47 || preCh == 0x0E4C)
            {
                /* move the tone mark to next character space */
                iX += ((S32) nWidth);
            }

        }
        //(1)Other cases: For Thai digits and base line sign, the only thing we have to do is moving cursor
        //(2)Show Characters
        ShowCharFuncDispatch(LineHeight, dtWidth, dtHgt, iX, iY, Font, BackGround, CharData, NumChar, Bordered);

    }
    else    /* non-Thai char */
#endif //__MMI_LANG_THAI__
    {
        ShowCharFuncDispatch(LineHeight, dtWidth, dtHgt, iX, iY, Font, BackGround, CharData, NumChar, Bordered);
    }
    gdi_font_end();
    /* GDI_EXIT_CRITICAL_SECTION(ShowStackedChar) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_char_at_xy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_show_char_at_xy(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *CharData;
    U32 NumChar;
    /* nHgt, nWidth is the height and width of character and 
        dataHgt, dataWidth is the data height and width */    
    U16 nHgt;
    U16 nWidth;
    U16 dtWidth;
    U16 dtHgt;
    U16 ascent = 0;
    U16 descent = 0;
#ifdef __MMI_INDIC_ALG__
    U16 nDWidth;
#endif 
    gdi_color text_color;
    U8 font_attr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (FONT_TEST_FORMATTING_CHARS(ch) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR)))
        return;

    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    if (FONT_TEST_CONTROL_CHAR(ch))
    {
        ch = 0x20;
    }
#ifdef __MMI_INDIC_ALG__
    NumChar = GetFontdata(ch, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
#else 
    NumChar = GetFontdata(ch, Font, &CharData, &nWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
#endif 

    gdi_font_begin(text_color, font_attr);
    ShowCharFuncDispatch(0, dtWidth, dtHgt, x, y, Font, BackGround, CharData, NumChar, 0);
    gdi_font_end();
}


const L2RLangSSC l2RLangSSC[] = 
{
    SSC_ARABIC,
    SSC_PERSIAN,
    SSC_URDU,
    SSC_HEBREW
};


/*****************************************************************************
 * FUNCTION
 *  IsL2RMMIStyle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL IsL2RMMIStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U8 temp_str1[30];
    U8 temp_str2[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) temp_str1, (S8*) gLanguageArray[gCurrLangIndex].aLangSSC);

    for (index = 0; index < (sizeof(l2RLangSSC) / sizeof(l2RLangSSC[0])); index++)
    {
        mmi_asc_to_ucs2((S8*) temp_str2, (S8*) l2RLangSSC[index].sscString);
        /* pTemp = (U8 *) temp_str; */

        if (mmi_ucs2cmp((const S8*)temp_str1, (const S8*)temp_str2) == 0)
        {
            return MMI_TRUE;
        }

    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  ShowDebugString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  String          [?]         
 *  len             [IN]        
 *  LineHeight      [IN]        
 *  Bordered        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowDebugString(S32 x, S32 y, stFontAttribute Font, U8 *String, S32 len, U32 LineHeight, U32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* GDI_ENTER_CRITICAL_SECTION(ShowDebugString) */
    U8 *CharData;

    U32 NumChar;
    U32 Counter = 0;
    S32 CurrentX;
    U16 nHgt;
    U16 nWidth;
    S32 nXOffset;
    S32 nYOffset;
    S32 yy;
    U16 unicode = 0;
    U16 dtWidth;
    U16 dtHgt;
    U16 ascent = 0;
    U16 descent = 0;
#ifdef __MMI_INDIC_ALG__
    U16 nDWidth = 0;
#endif 

    U8 font_attr = 0;
    gdi_color border_color = 0, text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    {
        if (Bordered)
        {
            border_color = gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
        }

        text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    }

    gdi_font_begin(text_color, font_attr);

    CurrentX = x;
    while (len != 0)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        len--;

        unicode = String[0];
        unicode |= (String[1] << 8);

        if (FONT_TEST_CONTROL_CHAR(unicode) || (FONT_TEST_SPACE_CHAR(unicode)))
        {
            unicode = 0x20;
        }

    #ifdef __MMI_INDIC_ALG__
        NumChar = GetFontdata(unicode, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
    #else 
        NumChar = GetFontdata(unicode, Font, &CharData, &nWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent);
    #endif 

        Counter++;

        if (LineHeight > 0)
        {
            yy = y + LineHeight - nHgt;
        }
        else
        {
            yy = y;
        }

        nXOffset = CurrentX + nWidth;
        nYOffset = yy + nHgt;

        if (Bordered)
        {
            gdi_show_char_bordered(CurrentX, yy, text_color, border_color, CharData, NumChar, nWidth, nHgt, font_attr);
        }
        else if (!
                 (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                  gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                 !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }
        else
        {
            gdi_show_char(CurrentX + 1, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }

        CurrentX += nWidth;

        nHgt = (U8) LineHeight;
        String += 2;
    }
    gdi_font_end();

    return CurrentX;
    /* GDI_RETURN (CurrentX); */

    /* GDI_EXIT_CRITICAL_SECTION(ShowDebugString) */

}

/*-----------------------------------------------------------------------*/
/*--------------------------- *** End *** -------------------------------*/
/*-----------------------------------------------------------------------*/

