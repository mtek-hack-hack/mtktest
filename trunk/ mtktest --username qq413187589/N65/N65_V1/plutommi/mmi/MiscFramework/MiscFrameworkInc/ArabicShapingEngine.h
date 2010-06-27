/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/plutommi/mmi/MiscFramework/MiscFrameworkInc/ArabicShapingEngine.h,v 1.2 2007/06/15 05:13:26 bw Exp $
*
* $Id: ArabicShapingEngine.h,v 1.2 2007/06/15 05:13:26 bw Exp $
*
* $Date: 2007/06/15 05:13:26 $
*
* $Name: 1.2 $
*
* $Locker$
*
* $Revision: 1.2 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: ArabicShapingEngine.h,v $
* Revision 1.2  2007/06/15 05:13:26  bw
* UNI@bw_20070614 16:11:36 因ArabicStringShape2 无定义, 使用 ArabicShapeEngine2 替换
*
* Revision 1.1  2007/05/17 07:22:40  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
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
 * ArabicShapingEngine.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is header file for ArabicShapingEngine
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


#ifdef __MMI_ARSHAPING_ENGINE__

#define UNICODE_ARABIC(ch)        (U16)((ch) - 0x620)
#define UNICODE_ARABIC_FORM_B(ch)        (U16)((ch) - 0xFE70)
#define UNICODE_ARABIC_FORM_A(ch)        (U16)((ch) - 0xFB50)
#define UI_ARABIC_CHARACTER_RANGE(ch)      ((((U16)(ch) > 0x620)&&((U16)(ch) < 0x6FF))?(1) : (0) )
extern const U8 g_arabic_base_char_array[];
extern const U8 g_arabic_form_A_char_array[];
extern const U8 g_arabic_form_B_char_array[];
//#define WHETHER_JOIN_CHARACTER(ch)      (((ch>=0x622 && ch<=0x625)||(ch>=0x62f && ch<=0x632)||ch==0x627||ch==0x648)?(1) : (0))
#define UI_ARABIC_FORM_A_RANGE(ch)      ((((U16)(ch) >= 0xFB50)&&((U16)(ch) <= 0xFDFD))?(1) : (0) )
#define UI_ARABIC_FORM_B_RANGE(ch)      ((((U16)(ch) >= 0xFE70)&&((U16)(ch) <= 0xFEFF))?(1) : (0) )
#define ARABIC_LIGATURE_LENGTH	5
#define LANGUAGE_FOR_LIGATURE	0
#define  WHETHER_JOIN_CHARACTER(ch)  (UI_ARABIC_CHARACTER_RANGE(ch) &&  g_arabic_base_char_array[UNICODE_ARABIC(ch)]) || (UI_ARABIC_FORM_B_RANGE(ch) &&  g_arabic_form_B_char_array[UNICODE_ARABIC_FORM_B(ch)])
/* PMT END PERSIAN */

#define NULL  0
typedef struct
{
    U16 nominalForm;
    U16 preForm;
    U16 postForm;
    U16 middleForm;
} ARABIC_SHAPE_TABLE;

typedef enum
{
    /* Nominal glyph Forms */
    N_HAMZA = 0x0621,
    N_MADDA_ON_ALEF = 0x622,
    N_HAMZA_ON_ALEF = 0x623,
    N_HAMZA_ON_WOW = 0x624,
    N_HAMZA_UNDER_ALEF = 0x625,
    N_HAMZA_ON_YEH = 0x626,
    N_ALEF = 0x627,
    N_BEH = 0x628,
    N_TEH_MARBUTA = 0x629,
    N_TEH = 0x62A,
    N_THEH = 0x62B,
    N_JEEM = 0x62C,
    N_HAH = 0x62D,
    N_KHAH = 0x62E,
    N_DAL = 0x62F,
    N_THAL = 0x630,
    N_REH = 0x631,
    N_ZAIN = 0x632,
    N_SEEN = 0x633,
    N_SHEEN = 0x634,
    N_SAD = 0x635,
    N_DAD = 0x636,
    N_TAH = 0x637,
    N_ZAH = 0x638,
    N_AIN = 0x639,
    N_GHAIN = 0x63A,
    N_TATWEEL = 0x640,
    N_FEH = 0x641,
    N_QAF = 0x642,
    N_KAF = 0x643,
    N_LAM = 0x644,
    N_MEEM = 0x645,
    N_NOON = 0x646,
    N_HEH = 0x647,
    N_WAW = 0x648,
    N_ALEF_MAKSURA = 0x649,
    N_YEH = 0x64A,
    N_PEH = 0x67E,
    N_TCHEH = 0x686,
    N_JEH = 0x698,
    N_KHEHEH = 0x6A9,
    N_GAF = 0x6AF,
    N_FARSIYEH = 0x6CC,
    /* Ligatures */
    N_MADDA_ON_LAMALEF = 0xFEF5,
    N_HAMZA_ON_LAMALEF = 0xFEF7,
    N_HAMZA_UNDER_LAMALEF = 0xFEF9,
    N_LAMALEF = 0xFEFB
        /* PMT END PERSIAN */
} NOMINAL_CHARACTERS_ENUM;

typedef enum
{
    /* left joining Form */
    L_MADDA_ON_ALEF = 0xFE81,
    L_HAMZA_ON_ALEF = 0xFE83,
    L_HAMZA_ON_WOW = 0xFE85,
    L_HAMZA_UNDER_ALEF = 0xFE87,
    L_HAMZA_ON_YEH = 0xFE8B,
    L_ALEF = 0xFE8D,
    L_BEH = 0xFE91,
    L_TEH_MARBUTA = 0xFE93,
    L_TEH = 0xFE97,
    L_THEH = 0xFE9B,
    L_JEEM = 0xFE9F,
    L_HAH = 0xFEA3,
    L_KHAH = 0xFEA7,
    L_DAL = 0xFEA9,
    L_THAL = 0xFEAB,
    L_REH = 0xFEAD,
    L_ZAIN = 0xFEAF,
    L_SEEN = 0xFEB3,
    L_SHEEN = 0xFEB7,
    L_SAD = 0xFEBB,
    L_DAD = 0xFEBF,
    L_TAH = 0xFEC3,
    L_ZAH = 0xFEC7,
    L_AIN = 0xFECB,
    L_GHAIN = 0xFECF,
    /* L_TATWEEL=0x640, same for all forms. */
    L_FEH = 0xFED3,
    L_QAF = 0xFED7,
    L_KAF = 0xFEDB,
    L_LAM = 0xFEDF,
    L_MEEM = 0xFEE3,
    L_NOON = 0xFEE7,
    L_HEH = 0xFEEB,
    L_WAW = 0xFEED,
    L_ALEF_MAKSURA = 0xFEEF,
    L_YEH = 0xFEF3,
    L_PEH = 0xFB58,
    L_TCHEH = 0xFB7C,
    L_JEH = 0xFB8A,
    L_KHEHEH = 0xFB90,
    L_GAF = 0xFB94,
    L_FARSIYEH = 0xFBFE,
    /* Ligatures */
    L_MADDA_ON_LAMALEF = 0xFEF5,
    L_HAMZA_ON_LAMALEF = 0xFEF7,
    L_HAMZA_UNDER_LAMALEF = 0xFEF9,
    L_LAMALEF = 0xFEFB
        /* PMT END PERSIAN */
} LEFT_JOINING_CHARACTERS_ENUM;

typedef enum
{
    /* Right joining Form */
    R_MADDA_ON_ALEF = 0xFE82,
    R_HAMZA_ON_ALEF = 0xFE84,
    R_HAMZA_ON_WOW = 0xFE86,
    R_HAMZA_UNDER_ALEF = 0xFE88,
    R_HAMZA_ON_YEH = 0xFE8A,
    R_ALEF = 0xFE8E,
    R_BEH = 0xFE90,
    R_TEH_MARBUTA = 0xFE94,
    R_TEH = 0xFE96,
    R_THEH = 0xFE9A,
    R_JEEM = 0xFE9E,
    R_HAH = 0xFEA2,
    R_KHAH = 0xFEA6,
    R_DAL = 0xFEAA,
    R_THAL = 0xFEAC,
    R_REH = 0xFEAE,
    R_ZAIN = 0xFEB0,
    R_SEEN = 0xFEB2,
    R_SHEEN = 0xFEB6,
    R_SAD = 0xFEBA,
    R_DAD = 0xFEBE,
    R_TAH = 0xFEC2,
    R_ZAH = 0xFEC6,
    R_AIN = 0xFECA,
    R_GHAIN = 0xFECE,
    /* R_TATWEEL=0x640, same for all forms. */
    R_FEH = 0xFED2,
    R_QAF = 0xFED6,
    R_KAF = 0xFEDA,
    R_LAM = 0xFEDE,
    R_MEEM = 0xFEE2,
    R_NOON = 0xFEE6,
    R_HEH = 0xFEEA,
    R_WAW = 0xFEEE,
    R_ALEF_MAKSURA = 0xFEF0,
    R_YEH = 0xFEF2,
    R_PEH = 0xFB57,
    R_TCHEH = 0xFB7B,
    R_JEH = 0xFB8B,
    R_KHEHEH = 0xFB8F,
    R_GAF = 0xFB93,
    R_FARSIYEH = 0xFBFD,
    /* Ligatures */
    R_MADDA_ON_LAMALEF = 0xFEF6,
    R_HAMZA_ON_LAMALEF = 0xFEF8,
    R_HAMZA_UNDER_LAMALEF = 0xFEFA,
    R_LAMALEF = 0xFEFC
        /* PMT END PERSIAN */
} RIGHT_JOINING_CHARACTERS_ENUM;

typedef enum
{
    /* Middle joining Form */
    M_MADDA_ON_ALEF = 0xFE82,
    M_HAMZA_ON_ALEF = 0xFE84,
    M_HAMZA_ON_WOW = 0xFE86,
    M_HAMZA_UNDER_ALEF = 0xFE88,
    M_HAMZA_ON_YEH = 0xFE8C,
    M_ALEF = 0xFE8E,
    M_BEH = 0xFE92,
    M_TEH_MARBUTA = 0xFE94,
    M_TEH = 0xFE98,
    M_THEH = 0xFE9C,
    M_JEEM = 0xFEA0,
    M_HAH = 0xFEA4,
    M_KHAH = 0xFEA8,
    M_DAL = 0xFEAA,
    M_THAL = 0xFEAC,
    M_REH = 0xFEAE,
    M_ZAIN = 0xFEB0,
    M_SEEN = 0xFEB4,
    M_SHEEN = 0xFEB8,
    M_SAD = 0xFEBC,
    M_DAD = 0xFEC0,
    M_TAH = 0xFEC4,
    M_ZAH = 0xFEC8,
    M_AIN = 0xFECC,
    M_GHAIN = 0xFED0,
    /* M_TATWEEL=0x640, same for all forms. */
    M_FEH = 0xFED4,
    M_QAF = 0xFED8,
    M_KAF = 0xFEDC,
    M_LAM = 0xFEE0,
    M_MEEM = 0xFEE4,
    M_NOON = 0xFEE8,
    M_HEH = 0xFEEC,
    M_WAW = 0xFEEE,
    M_ALEF_MAKSURA = 0xFEF0,
    /* PMT START PERSIAN */
    M_YEH = 0xFEF4,
    M_PEH = 0xFB59,
    M_TCHEH = 0xFB7D,
    M_JEH = 0xFB8B,
    M_KHEHEH = 0xFB91,
    M_GAF = 0xFB95,
    M_FARSIYEH = 0xFBFF,
    /* Ligatures */
    M_MADDA_ON_LAMALEF = 0xFEF6,
    M_HAMZA_ON_LAMALEF = 0xFEF8,
    M_HAMZA_UNDER_LAMALEF = 0xFEFA,
    M_LAMALEF = 0xFEFC
        /* PMT END PERSIAN */
} MIDDLE_JOINING_CHARACTERS_ENUM;

typedef enum
{
    /* Nominal glyph Forms */
    N_HAMZA_FORM_B = 0xFE80,
    N_MADDA_ON_ALEF_FORM_B = 0xFE81,
    N_HAMZA_ON_ALEF_FORM_B = 0xFE83,
    N_HAMZA_ON_WOW_FORM_B = 0xFE85,
    N_HAMZA_UNDER_ALEF_FORM_B = 0xFE87,
    N_HAMZA_ON_YEH_FORM_B = 0xFE89,
    N_ALEF_FORM_B = 0xFE8D,
    N_BEH_FORM_B = 0xFE8F,
    N_TEH_MARBUTA_FORM_B = 0xFE93,
    N_TEH_FORM_B = 0xFE95,
    N_THEH_FORM_B = 0xFE99,
    N_JEEM_FORM_B = 0xFE9D,
    N_HAH_FORM_B = 0xFEA1,
    N_KHAH_FORM_B = 0xFEA5,
    N_DAL_FORM_B = 0xFEA9,
    N_THAL_FORM_B = 0xFEAB,
    N_REH_FORM_B = 0xFEAD,
    N_ZAIN_FORM_B = 0xFEAF,
    N_SEEN_FORM_B = 0xFEB1,
    N_SHEEN_FORM_B = 0xFEB5,
    N_SAD_FORM_B = 0xFEB9,
    N_DAD_FORM_B = 0xFEBD,
    N_TAH_FORM_B = 0xFEC1,
    N_ZAH_FORM_B = 0xFEC5,
    N_AIN_FORM_B = 0xFEC9,
    N_GHAIN_FORM_B = 0xFECD,    
    N_FEH_FORM_B = 0xFED1,
    N_QAF_FORM_B = 0xFED5,
    N_KAF_FORM_B = 0xFED9,
    N_LAM_FORM_B = 0xFEDD,
    N_MEEM_FORM_B = 0xFEE1,
    N_NOON_FORM_B = 0xFEE5,
    N_HEH_FORM_B = 0xFEE9,
    N_WAW_FORM_B = 0xFEED,
    N_ALEF_MAKSURA_FORM_B = 0xFEEF,
    N_YEH_FORM_B = 0xFEF1
} NOMINAL_CHARACTERS_FORM_B_ENUM;

typedef enum
{
    /* Nominal glyph Forms */
    N_PEH_FORM_A = 0xFB56,
    N_TCHEH_FORM_A = 0xFB7A,
    N_JEH_FORM_A = 0xFB8A,
    N_KHEHEH_FORM_A = 0xFB8E,
    N_GAF_FORM_A = 0xFB92,
    N_FARSIYEH_FORM_A = 0xFBFC
} NOMINAL_CHARACTERS_FORM_A_ENUM;

typedef struct _ligature_glyph_info
{    
    U8 nInputLen;               /* no. of input unicode values */
    U8 nOutputLen;              /* no, of output values */
    U8 language_for_ligature;
    U16 Input_glyph[ARABIC_LIGATURE_LENGTH];     /* no. of input glyph used to make conjunct */
    U16 Output_glyph[ARABIC_LIGATURE_LENGTH];    /* no. of output glyph that has to be rendered */
} LIGATURE_INFO_TABLE;

typedef struct _arabic_main_table
{
    const LIGATURE_INFO_TABLE *glyphinfo;  /* pointer to individual table */
    U16 nsize;                          /* size of individual character's array */
    U8 maxInputGlyphSize;               /* max input of glyph it can handle */
} ARABIC_MAIN_TABLE;


extern void ArabicShapeEngine(PU16, PU16);

extern void arabic_ligature_rules(PU16, PU16, PU16, PU16);

extern void ArabicShapeEngine2(PU16 , PU16 , PU16 , PU16 );/*UNI@bw_20070614 16:11:36 因ArabicStringShape2 无定义, 使用 ArabicShapeEngine2 替换*/
extern void ArabicStringShape2(PU16 , PU16 , PU16 , PU16 );

#endif /* __MMI_ARSHAPING_ENGINE__ */ 

