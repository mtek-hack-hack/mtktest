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
 * Unitconvertor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines struct, enum, and function prototypes of Unit Convertor application.
 *
 * Author:
 * -------
 * -------
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

/**********************************************************************************
   Filename:      unitconvertor.h
   Author:        Vandana M
   Date Created:  July-14-2003
   Contains:      Unitconvertor
**********************************************************************************/
#ifndef __MMI_UNITCONVERTOR_H
#define __MMI_UNITCONVERTOR_H

#include "MMI_features.h"
#if defined (__MMI_UNIT_CONVERTER__) || defined (__MMI_EXTENDED_UNIT_CONVERTER__)
#include "MMIDataType.h"
#include "UnitconvertorResDef.h"
/* 
 * Define
 */

/* 
 * Typedef 
 */

typedef enum
{
    UCONV_UNIT = 0,
    UCONV_METRIC_CAP,   /* metric caption */
    UCONV_METIRC,       /* metric */
    UCONV_ENG_CAP,      /* English caption */
    UCONV_ENG,          /* English */
    UCONV_INLINE_TOTAL
} UCONV_INLINE_ITEM_ENUM;

typedef enum
{
    UCONV_CAPTION = 0,
    UCONV_UNIT1,
    UCONV_INPUT1,
    UCONV_UNIT2,
    UCONV_RESULT,
    UCONV_INLINE_TOTAL2
} UCONV_INLINE_ITEM_ENUM2;

typedef enum
{
    UCONV_WEIGHT = 0,
    UCONV_LENGTH
#ifdef __MMI_EXTENDED_UNIT_CONVERTER__
        ,
    UCONV_VOLUME,
    UCONV_TEMPERATURE,
    UCONV_VELOCITY,
    UCONV_SHOES,
    UCONV_CLOTHES,
    UCONV_SURFACE
#endif /* __MMI_EXTENDED_UNIT_CONVERTER__ */ 
} UCONV_UNIT_TYPE;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
extern void UconvInit(void);
extern void UconvDeInit(void);

extern void EntryUConvMenu(void);
extern void UConvCustomInlineFunction(void);
extern void HighlightUconvMenu(void);

#ifdef __MMI_EXTENDED_UNIT_CONVERTER__
extern void mmi_uconv_goto_compute_screen_lg(void);
extern void mmi_uconv_exit_compute_lg(void);
extern void mmi_uconv_entry_compute_lg(void);
extern void mmi_uconv_highlight_inline_item_lg(S32 nIndex);

extern void mmi_uconv_highlight_inline_select1(S32 index);
extern void mmi_uconv_highlight_inline_select2(S32 index);
extern void mmi_uconv_compute_result(U8 *text, U8 *cursor, S32 text_length);
extern void mmi_uconv_compute_temperature_result(U8 *text, U8 *cursor, S32 text_length);
extern void mmi_uconv_compute_shoes_result(void);
extern void mmi_uconv_compute_clothes_result(void);
extern void mmi_uconv_verify_shoes_input(U16 *input);
extern void mmi_uconv_verify_clothes_input(U16 *input);
#else /* __MMI_EXTENDED_UNIT_CONVERTER__ */ 
extern void HighlightUConvInlineLenghSelect(S32 index);
extern void ComputeLengthResult(void);
extern void UConvGoToComputeScreen(void);
extern void EntryUConvCompute(void);
extern void HighlightUConvInlineItem(S32 nIndex);
extern void HighlightUConvInlineWeightSelect(S32 index);
#endif /* __MMI_EXTENDED_UNIT_CONVERTER__ */ 

#endif /* defined (__MMI_UNIT_CONVERTER__) || defined (__MMI_EXTENDED_UNIT_CONVERTER__) */ /* __MMI_UNITCONVERTOR_H */
#endif /* __MMI_UNITCONVERTOR_H */ 

