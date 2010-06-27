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
 * CalculatorResDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines resource id for calculator application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_CALCULATOR_RESDEF_H
#define _MMI_CALCULATOR_RESDEF_H

#include "MMI_features.h"
#ifdef __MMI_CALCULATOR__

#include "MMIDataType.h" 

/* 
 * Typedef 
 */
typedef enum
{
    STR_ID_CALC_MENU = CALCULATOR_BASE + 1
} STR_ID_CALC_ENUM;

typedef enum
{
    IMG_ID_CALC_PLUS = CALCULATOR_BASE + 1,
    IMG_ID_CALC_MINUS,
    IMG_ID_CALC_MULTIPLY,
    IMG_ID_CALC_DIVIDE,
    IMG_ID_CALC_EQUAL,
#ifndef __MMI_SLIM_CALCULATOR__
    IMG_ID_CALC_MP,
    IMG_ID_CALC_MM,
    IMG_ID_CALC_MC,
    IMG_ID_CALC_MR,
#endif /* __MMI_SLIM_CALCULATOR__ */ 
    IMG_ID_CALC_MAIN,
    IMG_ID_CALC_MENU_ICON
} IMG_ID_CALC_ENUM;

#if defined(__MMI_TOUCH_CALCULATOR__)
typedef enum
{
    IMG_ID_TOUCH_CALC_KEY0 = IMG_ID_CALC_MENU_ICON + 1,
    IMG_ID_TOUCH_CALC_KEY1,
    IMG_ID_TOUCH_CALC_KEY2,
    IMG_ID_TOUCH_CALC_KEY3,
    IMG_ID_TOUCH_CALC_KEY4,
    IMG_ID_TOUCH_CALC_KEY5,
    IMG_ID_TOUCH_CALC_KEY6,
    IMG_ID_TOUCH_CALC_KEY7,
    IMG_ID_TOUCH_CALC_KEY8,
    IMG_ID_TOUCH_CALC_KEY9,
    IMG_ID_TOUCH_CALC_KEY_DOT,
    IMG_ID_TOUCH_CALC_KEY_EQUAL,
    IMG_ID_TOUCH_CALC_PLUS,
    IMG_ID_TOUCH_CALC_MINUS,
    IMG_ID_TOUCH_CALC_MULTIPLY,
    IMG_ID_TOUCH_CALC_DIVIDE,
    IMG_ID_TOUCH_CALC_MP,
    IMG_ID_TOUCH_CALC_MM,
    IMG_ID_TOUCH_CALC_MC,
    IMG_ID_TOUCH_CALC_MR,
    IMG_ID_TOUCH_CALC_EQUAL,
    /*shaokai add it.start 090814*/
    IMG_ID_TOUCH_CALC_TITLE,
    /*shaokai add it.end 090814*/
    IMG_ID_TOUCH_CALC_MAIN
} IMG_ID_TOUCH_CALC_ENUM;
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
#endif /* __MMI_CALCULATOR__ */
#endif /*_MMI_CALCULATOR_RESDEF_H*/
