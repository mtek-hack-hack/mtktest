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
 * Filename:
 * ---------
 *  Majung.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Game Majung.
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
 *
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
#include "MMI_include.h"
#include "GameDefs.h"

#ifdef IS_MAJUNG_BASE_GAME

#include "GameInc.h"
#include "MajungProts.h"
#include "MajungResDef.h"
#include "MajungConst.h"

// #define MAJUNG_LEVEL_GEN             /* Enable this to run level generator on PC */

#ifdef MAJUNG_LEVEL_GEN
#define MAJUNG_DUMP_LEVEL_SIZE_WIDTH (6)        /* enter level size to make here */
#define MAJUNG_DUMP_LEVEL_SIZE_HEIGHT (8)
#define MAJUNG_DUMP_LEVEL_COUNT_PERTIME (10)
#endif /* MAJUNG_LEVEL_GEN */ 

/* gdi feature */
#include "lcd_sw_rnd.h"
/* gdi feature */

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
#include "GameProts.h"
#endif

/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
#define MAJUNGBACKGROUND      2479

__align(2)
     const U8 MAJUNGBackground[MAJUNGBACKGROUND] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x09, 0x99, 0x00, 0xFF, 0x03, 0x08, 0x75, 0x6E, 0x74, 0x69, 0x74, 0x6C, 0x65,
         0x64, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63,
         0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00, 0xFF, 0x01, 0x03, 0x43,
         0x43, 0x0A, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59, 0x02, 0x00, 0x00,
         0x00, 0xFF, 0x51, 0x03, 0x07, 0x44, 0x1E, 0x00, 0xC0, 0x54, 0x00, 0xB0, 0x07, 0x62, 0x00, 0x90,
         0x48, 0x6F, 0x00, 0xC1, 0x0B, 0x00, 0xB1, 0x07, 0x64, 0x00, 0x91, 0x48, 0x67, 0x00, 0xC2, 0x01,
         0x00, 0xB2, 0x07, 0x6A, 0x00, 0x92, 0x47, 0x7C, 0x00, 0x43, 0x7E, 0x00, 0x3C, 0x7F, 0x00, 0x40,
         0x7C, 0x81, 0x70, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x3C,
         0x50, 0x00, 0x47, 0x51, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x53, 0x50, 0x91, 0x48, 0x00, 0x00, 0x49,
         0x67, 0x81, 0x20, 0x92, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x48, 0x00,
         0x00, 0x92, 0x40, 0x00, 0x00, 0x90, 0x4C, 0x7C, 0x00, 0x92, 0x3C, 0x50, 0x00, 0x47, 0x50, 0x00,
         0x43, 0x5A, 0x00, 0x40, 0x5A, 0x81, 0x20, 0x91, 0x49, 0x00, 0x00, 0x4A, 0x51, 0x50, 0x92, 0x3C,
         0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x40, 0x00, 0x00, 0x3C, 0x51, 0x00, 0x43, 0x5A,
         0x00, 0x47, 0x51, 0x00, 0x40, 0x53, 0x81, 0x70, 0x40, 0x00, 0x00, 0x90, 0x4C, 0x00, 0x00, 0x92,
         0x3C, 0x00, 0x00, 0x91, 0x4A, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x4F,
         0x7C, 0x00, 0x91, 0x4B, 0x7D, 0x00, 0x92, 0x3C, 0x50, 0x00, 0x43, 0x53, 0x00, 0x47, 0x49, 0x00,
         0x40, 0x51, 0x81, 0x70, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x47, 0x00, 0x00,
         0x3C, 0x51, 0x00, 0x47, 0x51, 0x00, 0x43, 0x53, 0x00, 0x40, 0x53, 0x50, 0x91, 0x4B, 0x00, 0x00,
         0x4A, 0x51, 0x81, 0x20, 0x92, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x4F,
         0x00, 0x00, 0x92, 0x40, 0x00, 0x00, 0x90, 0x48, 0x67, 0x00, 0x92, 0x47, 0x52, 0x00, 0x43, 0x5A,
         0x00, 0x3C, 0x49, 0x00, 0x40, 0x5A, 0x81, 0x20, 0x91, 0x4A, 0x00, 0x00, 0x49, 0x53, 0x50, 0x92,
         0x47, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x48, 0x00, 0x00, 0x92, 0x40, 0x00,
         0x00, 0x90, 0x4C, 0x7C, 0x00, 0x92, 0x47, 0x53, 0x00, 0x3C, 0x51, 0x00, 0x43, 0x5A, 0x00, 0x40,
         0x5A, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x49, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x3C, 0x00,
         0x00, 0x43, 0x00, 0x00, 0x91, 0x48, 0x7C, 0x00, 0x92, 0x47, 0x67, 0x00, 0x43, 0x6C, 0x00, 0x40,
         0x6E, 0x00, 0x3C, 0x6E, 0x81, 0x70, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x40,
         0x00, 0x00, 0x47, 0x51, 0x00, 0x3C, 0x50, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x5A, 0x81, 0x69, 0x90,
         0x4C, 0x00, 0x07, 0x92, 0x47, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x91, 0x48, 0x00, 0x00, 0x92, 0x40,
         0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x4F, 0x7C, 0x00, 0x91, 0x4C, 0x7D, 0x00, 0x92, 0x47, 0x52,
         0x00, 0x43, 0x53, 0x00, 0x3C, 0x49, 0x00, 0x40, 0x5A, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x4C,
         0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x91, 0x4D, 0x7C, 0x00,
         0x92, 0x47, 0x52, 0x00, 0x3C, 0x50, 0x00, 0x43, 0x52, 0x00, 0x40, 0x5A, 0x81, 0x70, 0x40, 0x00,
         0x00, 0x91, 0x4D, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00,
         0x00, 0x3C, 0x00, 0x00, 0x90, 0x48, 0x67, 0x00, 0x91, 0x4F, 0x7C, 0x00, 0x92, 0x3C, 0x51, 0x00,
         0x47, 0x53, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x67, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x4F, 0x00,
         0x00, 0x92, 0x3C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x91, 0x4D, 0x7D, 0x00, 0x92,
         0x47, 0x52, 0x00, 0x3C, 0x51, 0x00, 0x43, 0x53, 0x00, 0x40, 0x5A, 0x81, 0x70, 0x40, 0x00, 0x00,
         0x91, 0x4D, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x90, 0x48, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00,
         0x3C, 0x00, 0x00, 0x90, 0x4C, 0x6F, 0x00, 0x91, 0x4C, 0x7D, 0x00, 0x92, 0x47, 0x52, 0x00, 0x43,
         0x53, 0x00, 0x40, 0x53, 0x00, 0x3C, 0x48, 0x81, 0x70, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47,
         0x00, 0x00, 0x40, 0x00, 0x00, 0x47, 0x51, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x67, 0x00, 0x3C, 0x50,
         0x81, 0x70, 0x3C, 0x00, 0x00, 0x90, 0x4C, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x91, 0x4C, 0x00,
         0x00, 0x92, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x4D, 0x7C, 0x00, 0x91, 0x4D, 0x7D, 0x00,
         0x92, 0x48, 0x78, 0x00, 0x45, 0x70, 0x00, 0x41, 0x72, 0x00, 0x3E, 0x7C, 0x81, 0x70, 0x3E, 0x00,
         0x00, 0x45, 0x00, 0x00, 0x48, 0x00, 0x00, 0x41, 0x00, 0x00, 0x48, 0x50, 0x00, 0x45, 0x52, 0x00,
         0x41, 0x53, 0x00, 0x3E, 0x51, 0x50, 0x91, 0x4D, 0x00, 0x00, 0x4E, 0x6F, 0x81, 0x20, 0x92, 0x48,
         0x00, 0x00, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x4D, 0x00, 0x00, 0x92, 0x3E, 0x00, 0x00,
         0x90, 0x51, 0x7C, 0x00, 0x92, 0x48, 0x42, 0x00, 0x45, 0x50, 0x00, 0x41, 0x52, 0x00, 0x3E, 0x49,
         0x81, 0x20, 0x91, 0x4E, 0x00, 0x00, 0x4F, 0x5A, 0x50, 0x92, 0x48, 0x00, 0x00, 0x41, 0x00, 0x00,
         0x45, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x48, 0x3F, 0x00, 0x45, 0x51, 0x00, 0x41, 0x51, 0x00, 0x3E,
         0x42, 0x81, 0x70, 0x3E, 0x00, 0x00, 0x90, 0x51, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x91, 0x4F,
         0x00, 0x00, 0x92, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x54, 0x7C, 0x00, 0x91, 0x50, 0x7C,
         0x00, 0x92, 0x45, 0x53, 0x00, 0x48, 0x49, 0x00, 0x41, 0x53, 0x00, 0x3E, 0x49, 0x81, 0x70, 0x3E,
         0x00, 0x00, 0x48, 0x00, 0x00, 0x45, 0x00, 0x00, 0x41, 0x00, 0x00, 0x48, 0x49, 0x00, 0x45, 0x52,
         0x00, 0x41, 0x52, 0x00, 0x3E, 0x51, 0x50, 0x91, 0x50, 0x00, 0x00, 0x4F, 0x53, 0x81, 0x20, 0x92,
         0x48, 0x00, 0x00, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00, 0x92, 0x3E, 0x00,
         0x00, 0x90, 0x4D, 0x7C, 0x00, 0x92, 0x45, 0x52, 0x00, 0x3E, 0x50, 0x00, 0x48, 0x42, 0x00, 0x41,
         0x52, 0x81, 0x20, 0x91, 0x4F, 0x00, 0x00, 0x4E, 0x7C, 0x50, 0x92, 0x45, 0x00, 0x00, 0x48, 0x00,
         0x00, 0x3E, 0x00, 0x00, 0x90, 0x4D, 0x00, 0x00, 0x92, 0x41, 0x00, 0x00, 0x90, 0x51, 0x7C, 0x00,
         0x92, 0x3E, 0x52, 0x00, 0x48, 0x48, 0x00, 0x45, 0x52, 0x00, 0x41, 0x53, 0x81, 0x70, 0x41, 0x00,
         0x00, 0x91, 0x4E, 0x00, 0x00, 0x92, 0x3E, 0x00, 0x00, 0x48, 0x00, 0x00, 0x45, 0x00, 0x00, 0x91,
         0x4D, 0x7C, 0x00, 0x92, 0x48, 0x64, 0x00, 0x45, 0x6C, 0x00, 0x3E, 0x6E, 0x00, 0x41, 0x6A, 0x81,
         0x70, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x48, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x48, 0x48, 0x00,
         0x3E, 0x50, 0x00, 0x45, 0x53, 0x00, 0x41, 0x53, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x4D, 0x00,
         0x00, 0x92, 0x48, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x54, 0x7C, 0x00, 0x91,
         0x51, 0x7D, 0x00, 0x92, 0x48, 0x49, 0x00, 0x45, 0x53, 0x00, 0x3E, 0x51, 0x00, 0x41, 0x53, 0x06,
         0x90, 0x51, 0x00, 0x81, 0x6A, 0x92, 0x3E, 0x00, 0x00, 0x91, 0x51, 0x00, 0x00, 0x92, 0x48, 0x00,
         0x00, 0x45, 0x00, 0x00, 0x41, 0x00, 0x00, 0x91, 0x53, 0x7C, 0x00, 0x92, 0x48, 0x49, 0x00, 0x45,
         0x53, 0x00, 0x3E, 0x49, 0x00, 0x41, 0x53, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00,
         0x92, 0x48, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00, 0x92, 0x3E, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90,
         0x4D, 0x7D, 0x00, 0x91, 0x54, 0x6F, 0x00, 0x92, 0x48, 0x50, 0x00, 0x3E, 0x52, 0x00, 0x45, 0x53,
         0x00, 0x41, 0x5A, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x54, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00,
         0x3E, 0x00, 0x00, 0x45, 0x00, 0x00, 0x91, 0x53, 0x7C, 0x00, 0x92, 0x48, 0x52, 0x00, 0x45, 0x53,
         0x00, 0x41, 0x67, 0x00, 0x3E, 0x50, 0x81, 0x70, 0x3E, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00, 0x92,
         0x48, 0x00, 0x00, 0x90, 0x4D, 0x00, 0x00, 0x92, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x51,
         0x7C, 0x00, 0x91, 0x51, 0x7C, 0x00, 0x92, 0x3E, 0x52, 0x00, 0x48, 0x51, 0x00, 0x45, 0x53, 0x00,
         0x41, 0x67, 0x81, 0x70, 0x41, 0x00, 0x00, 0x48, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x45, 0x00, 0x00,
         0x48, 0x50, 0x00, 0x45, 0x52, 0x00, 0x41, 0x5A, 0x00, 0x3E, 0x52, 0x81, 0x70, 0x3E, 0x00, 0x00,
         0x90, 0x51, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x91, 0x51, 0x00, 0x00, 0x92, 0x41, 0x00, 0x00,
         0x45, 0x00, 0x00, 0x90, 0x4F, 0x7C, 0x00, 0x91, 0x4F, 0x67, 0x00, 0x92, 0x4A, 0x78, 0x00, 0x47,
         0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x7A, 0x81, 0x70, 0x40, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4A,
         0x00, 0x00, 0x43, 0x00, 0x00, 0x4A, 0x41, 0x00, 0x47, 0x49, 0x00, 0x40, 0x48, 0x00, 0x43, 0x50,
         0x50, 0x91, 0x4F, 0x00, 0x00, 0x50, 0x7D, 0x81, 0x20, 0x92, 0x4A, 0x00, 0x00, 0x40, 0x00, 0x00,
         0x47, 0x00, 0x00, 0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x53, 0x5A, 0x00, 0x92,
         0x4A, 0x49, 0x00, 0x47, 0x49, 0x00, 0x40, 0x50, 0x00, 0x43, 0x51, 0x81, 0x20, 0x91, 0x50, 0x00,
         0x00, 0x51, 0x5A, 0x50, 0x92, 0x4A, 0x00, 0x00, 0x40, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00,
         0x00, 0x4A, 0x49, 0x00, 0x40, 0x49, 0x00, 0x47, 0x51, 0x00, 0x43, 0x51, 0x81, 0x70, 0x43, 0x00,
         0x00, 0x90, 0x53, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x91, 0x51, 0x00, 0x00, 0x92, 0x47, 0x00,
         0x00, 0x40, 0x00, 0x00, 0x90, 0x56, 0x7C, 0x00, 0x91, 0x52, 0x7C, 0x00, 0x92, 0x4A, 0x49, 0x00,
         0x47, 0x51, 0x00, 0x43, 0x52, 0x00, 0x40, 0x48, 0x00, 0x4A, 0x42, 0x00, 0x40, 0x51, 0x00, 0x43,
         0x52, 0x81, 0x70, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x4A,
         0x00, 0x00, 0x4A, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x50, 0x00, 0x4A, 0x50, 0x00, 0x47, 0x53,
         0x00, 0x43, 0x5A, 0x50, 0x91, 0x52, 0x00, 0x00, 0x51, 0x52, 0x81, 0x20, 0x92, 0x40, 0x00, 0x00,
         0x47, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x90, 0x56, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x4F,
         0x6F, 0x00, 0x92, 0x40, 0x13, 0x00, 0x4A, 0x38, 0x00, 0x47, 0x50, 0x00, 0x43, 0x34, 0x81, 0x20,
         0x91, 0x51, 0x00, 0x00, 0x50, 0x7C, 0x50, 0x92, 0x40, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4A, 0x00,
         0x00, 0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x53, 0x7C, 0x00, 0x92, 0x4A, 0x7C,
         0x00, 0x47, 0x6F, 0x00, 0x43, 0x7C, 0x00, 0x40, 0x6F, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x50,
         0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x91, 0x4F, 0x7D, 0x00,
         0x92, 0x4A, 0x41, 0x00, 0x47, 0x51, 0x00, 0x43, 0x51, 0x00, 0x40, 0x49, 0x81, 0x70, 0x40, 0x00,
         0x00, 0x47, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x43, 0x00, 0x00, 0x4A, 0x64, 0x00, 0x47, 0x68, 0x00,
         0x41, 0x72, 0x00, 0x43, 0x64, 0x81, 0x70, 0x43, 0x00, 0x00, 0x91, 0x4F, 0x00, 0x00, 0x92, 0x4A,
         0x00, 0x00, 0x47, 0x00, 0x00, 0x41, 0x00, 0x00, 0x90, 0x59, 0x7C, 0x00, 0x91, 0x53, 0x7C, 0x00,
         0x92, 0x4A, 0x41, 0x00, 0x47, 0x50, 0x00, 0x43, 0x53, 0x00, 0x41, 0x49, 0x0E, 0x90, 0x53, 0x00,
         0x81, 0x62, 0x92, 0x43, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x47, 0x00,
         0x00, 0x41, 0x00, 0x00, 0x91, 0x54, 0x7C, 0x00, 0x92, 0x4A, 0x51, 0x00, 0x47, 0x52, 0x00, 0x43,
         0x52, 0x00, 0x41, 0x50, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x54, 0x00, 0x00, 0x92, 0x4A, 0x00,
         0x00, 0x90, 0x59, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x4F, 0x7C, 0x00,
         0x91, 0x56, 0x7C, 0x00, 0x92, 0x4A, 0x50, 0x00, 0x47, 0x50, 0x00, 0x41, 0x50, 0x00, 0x43, 0x53,
         0x81, 0x70, 0x43, 0x00, 0x00, 0x91, 0x56, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x47, 0x00, 0x00,
         0x41, 0x00, 0x00, 0x91, 0x54, 0x7C, 0x00, 0x92, 0x4A, 0x50, 0x00, 0x47, 0x52, 0x00, 0x43, 0x53,
         0x00, 0x41, 0x52, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x54, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00,
         0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x53, 0x7C, 0x00, 0x91,
         0x53, 0x7C, 0x00, 0x92, 0x4A, 0x48, 0x00, 0x47, 0x52, 0x00, 0x41, 0x3F, 0x00, 0x43, 0x50, 0x81,
         0x70, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x41, 0x00, 0x00, 0x4A, 0x5A, 0x00,
         0x47, 0x58, 0x00, 0x43, 0x56, 0x00, 0x41, 0x60, 0x81, 0x70, 0x41, 0x00, 0x00, 0x90, 0x53, 0x00,
         0x00, 0x92, 0x4A, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00,
         0x90, 0x54, 0x7C, 0x00, 0x91, 0x54, 0x6F, 0x00, 0x92, 0x4C, 0x78, 0x00, 0x47, 0x78, 0x00, 0x43,
         0x78, 0x00, 0x48, 0x78, 0x81, 0x70, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x43,
         0x00, 0x00, 0x4C, 0x42, 0x00, 0x48, 0x51, 0x00, 0x47, 0x41, 0x00, 0x43, 0x41, 0x50, 0x91, 0x54,
         0x00, 0x00, 0x55, 0x5A, 0x81, 0x20, 0x92, 0x4C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00,
         0x90, 0x54, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x58, 0x67, 0x00, 0x92, 0x4C, 0x3F, 0x00,
         0x47, 0x42, 0x00, 0x43, 0x41, 0x00, 0x48, 0x52, 0x81, 0x20, 0x91, 0x55, 0x00, 0x00, 0x56, 0x53,
         0x50, 0x92, 0x4C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00, 0x47, 0x51,
         0x00, 0x4C, 0x50, 0x00, 0x48, 0x42, 0x00, 0x43, 0x52, 0x81, 0x70, 0x43, 0x00, 0x00, 0x90, 0x58,
         0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x91, 0x56, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x4C, 0x00,
         0x00, 0x90, 0x5B, 0x7C, 0x00, 0x91, 0x57, 0x7C, 0x00, 0x92, 0x4C, 0x50, 0x00, 0x48, 0x42, 0x00,
         0x47, 0x49, 0x00, 0x43, 0x49, 0x81, 0x70, 0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x4C, 0x00, 0x00,
         0x47, 0x00, 0x00, 0x4C, 0x50, 0x00, 0x48, 0x50, 0x00, 0x47, 0x52, 0x00, 0x43, 0x52, 0x50, 0x91,
         0x57, 0x00, 0x00, 0x56, 0x6F, 0x81, 0x20, 0x92, 0x4C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00,
         0x00, 0x90, 0x5B, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x54, 0x6F, 0x00, 0x92, 0x4C, 0x51,
         0x00, 0x48, 0x50, 0x00, 0x47, 0x52, 0x00, 0x43, 0x53, 0x81, 0x20, 0x91, 0x56, 0x00, 0x00, 0x55,
         0x5A, 0x50, 0x92, 0x4C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00,
         0x92, 0x43, 0x00, 0x00, 0x90, 0x58, 0x7C, 0x00, 0x92, 0x4C, 0x5A, 0x00, 0x48, 0x5A, 0x00, 0x47,
         0x6F, 0x00, 0x43, 0x6F, 0x81, 0x70, 0x43, 0x00, 0x00, 0x91, 0x55, 0x00, 0x00, 0x92, 0x4C, 0x00,
         0x00, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x91, 0x54, 0x67, 0x00, 0x92, 0x4C, 0x6E, 0x00, 0x48,
         0x65, 0x00, 0x47, 0x70, 0x00, 0x43, 0x6C, 0x81, 0x70, 0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x4C,
         0x00, 0x00, 0x47, 0x00, 0x00, 0x4C, 0x4A, 0x00, 0x48, 0x4A, 0x00, 0x47, 0x48, 0x00, 0x43, 0x47,
         0x81, 0x48, 0x90, 0x58, 0x00, 0x28, 0x92, 0x4C, 0x00, 0x00, 0x48, 0x00, 0x00, 0x91, 0x54, 0x00,
         0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x5B, 0x6F, 0x00, 0x91, 0x4F, 0x7C, 0x00,
         0x92, 0x4C, 0x50, 0x00, 0x48, 0x50, 0x00, 0x47, 0x50, 0x00, 0x43, 0x54, 0x81, 0x70, 0x43, 0x00,
         0x00, 0x91, 0x4F, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x91,
         0x4D, 0x7C, 0x00, 0x92, 0x4C, 0x46, 0x00, 0x48, 0x48, 0x00, 0x47, 0x46, 0x00, 0x43, 0x49, 0x81,
         0x70, 0x43, 0x00, 0x00, 0x91, 0x4D, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x90, 0x5B, 0x00, 0x00,
         0x92, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00, 0x90, 0x54, 0x6F, 0x00, 0x91, 0x4C, 0x7C, 0x00, 0x92,
         0x4C, 0x51, 0x00, 0x48, 0x4B, 0x00, 0x47, 0x27, 0x00, 0x43, 0x52, 0x81, 0x70, 0x43, 0x00, 0x00,
         0x91, 0x4C, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x91, 0x4B,
         0x7D, 0x00, 0x92, 0x4C, 0x50, 0x00, 0x47, 0x4E, 0x00, 0x43, 0x50, 0x00, 0x48, 0x52, 0x81, 0x70,
         0x48, 0x00, 0x00, 0x91, 0x4B, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00, 0x92,
         0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x58, 0x7C, 0x00, 0x91, 0x4A, 0x7C, 0x00, 0x92, 0x4C,
         0x51, 0x00, 0x47, 0x50, 0x00, 0x43, 0x52, 0x00, 0x48, 0x52, 0x81, 0x70, 0x48, 0x00, 0x00, 0x47,
         0x00, 0x00, 0x4C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x4C, 0x53, 0x00, 0x47, 0x52, 0x00, 0x48, 0x51,
         0x00, 0x43, 0x52, 0x81, 0x70, 0x43, 0x00, 0x00, 0x90, 0x58, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00,
         0x91, 0x4A, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

#define MAJUNGMOVE      138
__align(2)
     const U8 MAJUNGMove[MAJUNGMOVE] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x74, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x05, 0x24, 0xB7, 0x00, 0xC0, 0x0A, 0x00, 0xB0, 0x07,
         0x60, 0x00, 0x90, 0x48, 0x64, 0x00, 0xC1, 0x61, 0x00, 0xB1, 0x07, 0x7C, 0x00, 0x91, 0x48, 0x64,
         0x81, 0x70, 0x90, 0x48, 0x00, 0x00, 0x4A, 0x64, 0x81, 0x70, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x81,
         0x70, 0x4C, 0x00, 0x00, 0x4F, 0x64, 0x81, 0x70, 0x4F, 0x00, 0x00, 0x54, 0x64, 0x81, 0x70, 0x54,
         0x00, 0x00, 0x91, 0x48, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

#ifdef __MMI_GAME_MAJUNG_176x220__
#define __MAJUNG_DRAW_SCORE__
#define __MAJUNG_DRAW_EXIT__

#define LEVEL_ROW_COUNT_EASY        (6)
#define LEVEL_COLUMN_COUNT_EASY     (8)
#define LEVEL_ROW_COUNT_NORMAL      (8)
#define LEVEL_COLUMN_COUNT_NORMAL   (10)
#define LEVEL_ROW_COUNT_HARD        (10)
#define LEVEL_COLUMN_COUNT_HARD     (12)

#define MAJUNG_BLOCK_ROW_COUNT         (12)
#define MAJUNG_BLOCK_COLUMN_COUNT      (14)

#define MAJUNG_LEVEL_COUNT    (50)
#define ENERGYBAR_POS_X       (160)
#define ENERGYBAR_POS_Y       (18)
#define MAJUNG_BRICK_WIDTH    (12)
#define MAJUNG_BRICK_HEIGHT   (18)
#define MAJUNG_THICK_BRICK_Y_MARGIN (0) /* the y difference btw thick img top and
                                           brick img buttom */
#define UNIT_ENERGY_INCREASE_PER_SCORE (6)
#define MAJUNG_ENERGY_LIMIT         (20)
#define MAJUNG_ENERGY_INIT    (20)

#define MAJUNG_SCORE_X (5)
#define MAJUNG_SCORE_Y (200)
#define MAJUNG_EXIT_X  (142)
#define MAJUNG_EXIT_Y  (200)
#define MAJUNG_EXIT_WIDTH (28)
#define MAJUNG_EXIT_HEIGHT (14)

#define MAJUNG_DIGIT_WIDTH (6)
 #elif defined(__MMI_GAME_MAJUNG_240x320__)
#define __MAJUNG_DRAW_SCORE__
#define __MAJUNG_DRAW_EXIT__

#define LEVEL_ROW_COUNT_EASY        (6)
#define LEVEL_COLUMN_COUNT_EASY (8)
#define LEVEL_ROW_COUNT_NORMAL      (8)
#define LEVEL_COLUMN_COUNT_NORMAL (10)
#define LEVEL_ROW_COUNT_HARD        (10)
#define LEVEL_COLUMN_COUNT_HARD     (12)

#define MAJUNG_LEVEL_COUNT (50)
#define ENERGYBAR_POS_X (225)
#define ENERGYBAR_POS_Y (30)

#define MAJUNG_BRICK_WIDTH       (17)
#define MAJUNG_BRICK_HEIGHT         (25)

#define MAJUNG_BLOCK_ROW_COUNT      (12)
#define MAJUNG_BLOCK_COLUMN_COUNT   (14)
#define MAJUNG_THICK_BRICK_Y_MARGIN (3) /* the y difference btw thick img top and
                                           brick img buttom */
#define UNIT_ENERGY_INCREASE_PER_SCORE (8)
#define MAJUNG_ENERGY_LIMIT         (20)
#define MAJUNG_ENERGY_INIT    (20)

#define MAJUNG_SCORE_X        (10)
#define MAJUNG_SCORE_Y        (290)
#define MAJUNG_EXIT_X  (185)
#define MAJUNG_EXIT_Y         (295)
#define MAJUNG_EXIT_WIDTH     (40)
#define MAJUNG_EXIT_HEIGHT    (20)

#define MAJUNG_DIGIT_WIDTH    (9)

#elif defined(__MMI_GAME_MAJUNG_320x240__)
#define __MAJUNG_DRAW_SCORE__
#define __MAJUNG_DRAW_EXIT__

#define LEVEL_ROW_COUNT_EASY        (6)
#define LEVEL_COLUMN_COUNT_EASY     (8)
#define LEVEL_ROW_COUNT_NORMAL      (8)
#define LEVEL_COLUMN_COUNT_NORMAL   (10)
#define LEVEL_ROW_COUNT_HARD        (10)
#define LEVEL_COLUMN_COUNT_HARD     (12)

#define MAJUNG_BLOCK_ROW_COUNT         (12)
#define MAJUNG_BLOCK_COLUMN_COUNT      (14)

#define MAJUNG_LEVEL_COUNT    (50)
#define ENERGYBAR_POS_X       (295)
#define ENERGYBAR_POS_Y       (30)
#define MAJUNG_BRICK_WIDTH    (16)
#define MAJUNG_BRICK_HEIGHT   (21)
#define MAJUNG_THICK_BRICK_Y_MARGIN (3) /* the y difference btw thick img top and
                                           brick img buttom */
#define UNIT_ENERGY_INCREASE_PER_SCORE (8)
#define MAJUNG_ENERGY_LIMIT         (20)
#define MAJUNG_ENERGY_INIT    (20)

#define MAJUNG_SCORE_X (10)
#define MAJUNG_SCORE_Y (210)
#define MAJUNG_EXIT_X  (275)
#define MAJUNG_EXIT_Y  (205)
#define MAJUNG_EXIT_WIDTH (40)
#define MAJUNG_EXIT_HEIGHT (20)

#define MAJUNG_DIGIT_WIDTH (7)
 #endif 

/************************************************************************/
/* Structure                                                            */
/************************************************************************/
typedef enum
{
    BLOCK_TYPE_EMPTY,
    BLOCK_TYPE_BRICK
} majung_block_type_enum;

typedef enum
{
    LEVEL_EASY = 0,
    LEVEL_NORMAL,
    LEVEL_HARD
} majung_level_enum;

typedef enum
{
    BRICK_1W = 0,
    BRICK_2W,
    BRICK_3W,
    BRICK_4W,
    BRICK_5W,
    BRICK_6W,
    BRICK_7W,
    BRICK_8W,
    BRICK_9W,
    BRICK_1T,
    BRICK_2T,
    BRICK_3T,
    BRICK_4T,
    BRICK_5T,
    BRICK_6T,
    BRICK_7T,
    BRICK_8T,
    BRICK_9T,
    BRICK_2S,
    BRICK_3S,
    BRICK_4S,
    BRICK_5S,
    BRICK_6S,
    BRICK_7S,
    BRICK_8S,
    BRICK_9S,
    BRICK_A,    /* east */
    BRICK_B,    /* west */
    BRICK_C,    /* south */
    BRICK_D,    /* north */
    BRICK_F,    /* chung */
    BRICK_G,    /* bai */
    BRICK_H,    /* fa */
    BRICK_TOTOAL_COUNT
} majung_brick_id_enum;

typedef enum
{
    PAIR_ZERO_TURN,
    PAIR_ONE_TURN,
    PAIR_TWO_TURN
} majung_pair_type_enum;

typedef enum
{
    PLAY_STATE,
    CONNECT_STATE
} majung_state_enum;

typedef enum
{
    CONNECT_HOR,
    CONNECT_VER,
    CONNECT_LU, /*  left to up */
    CONNECT_RU, /*  right to up */
    CONNECT_LD, /*  left to down */
    CONNECT_RD  /*  right to down */
} majung_connect_type_enum;

typedef struct
{
    U16 block_type;
    U16 brick_id;
    BOOL need_redraw;
} majung_brick_struct;

typedef struct
{
    S16 x;
    S16 y;
} majung_pos_struct;

typedef struct
{
    U8 connect_type;
    U8 block_index;
} majung_connect_struct;

/************************************************************************/
/* Audio [Const]                                                        */
/************************************************************************/
/* May put audio raw data here */

/************************************************************************/
/* Golbal Varable [xxxx Byte]                                           */
/************************************************************************/
/* remember to init those value correctly */
BOOL majung_is_gameover = FALSE;
BOOL majung_is_new_game = TRUE;
BOOL majung_is_resume = TRUE;
U8 majung_game_level = LEVEL_EASY;
S16 majung_game_grade = 0;
U16 majung_timer_elapse = 100;

#if defined (__MMI_GAME_MULTICHANNEL_SOUND__)
S32 majung_background_midi;
S32 majung_move_midi;
#endif /* defined (__MMI_GAME_MULTICHANNEL_SOUND__) */ 

#ifdef __MMI_GAME_MAJUNG_176x220__
U16 majung_lcd_width = 176;
U16 majung_lcd_height = 220;
#elif defined(__MMI_GAME_MAJUNG_240x320__)
U16 majung_lcd_width = 240;
U16 majung_lcd_height = 320;
#elif defined(__MMI_GAME_MAJUNG_320x240__)
U16 majung_lcd_width = 320;
U16 majung_lcd_height = 240;
#endif 

S16 majung_selected_idx;
S16 majung_hilight_idx;

S16 majung_connect_list_count;
S16 majung_connect_list_index;

S16 majung_brick_start_offset_x;
S16 majung_brick_start_offset_y;
S16 majung_energy;
S16 majung_remain_brick;
BOOL majung_draw_background;
BOOL is_majung_exit_pressed;

majung_connect_struct majung_connect_list[MAJUNG_BLOCK_ROW_COUNT + MAJUNG_BLOCK_COLUMN_COUNT * 2];
majung_brick_struct majung_block_list[(MAJUNG_BLOCK_ROW_COUNT) * (MAJUNG_BLOCK_COLUMN_COUNT)];
majung_pos_struct majung_pair_turn_list[2]; /* can only have two turns */
majung_pair_type_enum majung_pair_type;
majung_state_enum majung_state;

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
static U16 mmi_majung_language_index;
#define MMI_MAJUNG_STRING_COUNT 1
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

/************************************************************************/
/* Function Declare                                                     */
/************************************************************************/
/* Game framework related functions */
S16 Majung_Calc_Best_Grade(S16 old_grade, S16 new_grade);   /* descide which is best grade */
void Majung_Enter_Game(void);                               /* entry function of the game */
void Majung_Exit_Game(void);                                /* exit function - usually will stop timer and release buffer */
void Majung_Draw_GameOver(void);                            /* draw gameover screen */

/* Game play functions */
void Majung_Render(void);
void Majung_Gameover(void);
void Majung_Init_Game(void);    /* draw gameover screen */
void Majung_Load_New_Stage(void);
void Majung_CountDown_Timer(void);
void Majung_Render_Energy(void);

/* User Input */
void Majung_Move_Right(void);
void Majung_Move_Left(void);
void Majung_Move_Down(void);
void Majung_Move_Up(void);
void Majung_Select(void);
void Majung_Keyboard_Key_Handler(S32 vkey_code, S32 key_state);

/* Connet function */
BOOL Majung_Pair_Check_Zero_Turn(S16 x1, S16 y1, S16 x2, S16 y2);
BOOL Majung_Pair_Check(S16 src_idx_x, S16 src_idx_y, S16 dest_idx_x, S16 dest_idx_y);

void Majung_Draw_Connection(void);
BOOL Majung_Pair_Check_Zero_Turn(S16 x1, S16 y1, S16 x2, S16 y2);
void Manjung_Connet_Join(S16 x1, S16 y1, S16 x2, S16 y2, S16 x3, S16 y3);

void Majung_Update_Block(S16 idx);

void Majung_Draw_Score(void);
void Majung_Draw_Exit(void);

#ifdef MAJUNG_LEVEL_GEN
void Majung_Level_Dump(void);
#endif 

#ifdef __MMI_TOUCH_SCREEN__
/* touch screen */
void mmi_majung_pen_down_hdlr(mmi_pen_point_struct);
void mmi_majung_pen_up_hdlr(mmi_pen_point_struct);
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  Majung_Draw_Exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Draw_Exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_majung_exit_pressed == FALSE)
    {
        gdi_image_draw_id(MAJUNG_EXIT_X, MAJUNG_EXIT_Y, IMG_GX_MAJUNG_EXIT_UP);
    }
    else
    {
        gdi_image_draw_id(MAJUNG_EXIT_X, MAJUNG_EXIT_Y, IMG_GX_MAJUNG_EXIT_DOWN);
    }

}


/*****************************************************************************
 * FUNCTION
 *  Majung_Draw_Score
 * DESCRIPTION
 *  show Score
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Draw_Score(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ID_TYPE image_id;   /* store the last digit of tick */
    S16 position_shift;     /* the position offset of digit displayed */
    S32 tmp_tick;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_tick = majung_game_grade;
    position_shift = (MAJUNG_DIGIT_WIDTH * 5) + 3;
    gdi_image_draw_id(MAJUNG_SCORE_X, MAJUNG_SCORE_Y, IMG_GX_MAJUNG_BOX);
    do
    {
        image_id = IMG_GX_MAJUNG_0 + (tmp_tick % 10);
        tmp_tick = tmp_tick / 10;
    #if defined(__MMI_GAME_MAJUNG_176x220__)
        gdi_image_draw_id(MAJUNG_SCORE_X + position_shift, MAJUNG_SCORE_Y + 1, image_id);
    #elif defined(__MMI_GAME_MAJUNG_240x320__)
        gdi_image_draw_id(MAJUNG_SCORE_X + position_shift - 5, MAJUNG_SCORE_Y + 5, image_id);
    #elif defined(__MMI_GAME_MAJUNG_320x240__)
        gdi_image_draw_id(MAJUNG_SCORE_X + position_shift - 7, MAJUNG_SCORE_Y + 2, image_id);
    #endif 

        position_shift -= (MAJUNG_DIGIT_WIDTH + 1);

    } while (tmp_tick != 0);

}


/*****************************************************************************
 * FUNCTION
 *  Majung_Enter_GFX
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Enter_GFX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_GX_MAJUNG_GAME_ICON;    /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_MAJUNG_GAME_NAME;    /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME;     /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;           /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;       /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;       /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GAME_HELP;         /* "Game Help" string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GX_MAJUNG_LEVEL_EASY;      /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_GX_MAJUNG_LEVEL_NORMAL;    /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_GX_MAJUNG_LEVEL_HARD;      /* level string ID */

    /* add slot in NVRAMEnum.h */
    GFX.game_data.grade_nvram_id_list[0] = NVRAM_GX_MAJUNG_EASY_SCORE;  /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[1] = NVRAM_GX_MAJUNG_NORMAL_SCORE;        /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = NVRAM_GX_MAJUNG_HARD_SCORE;  /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = NVRAM_GX_MAJUNG_LEVEL;   /* current lvl idnex stored in NVRAM */

    /* help */
    GFX.game_data.help_str_id = STR_GX_MAJUNG_HELP_DESCRIPTION; /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&majung_game_grade);       /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&majung_game_level);        /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) (&majung_is_new_game); /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = Majung_Calc_Best_Grade; /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = Majung_Enter_Game;  /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = Majung_Exit_Game;    /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = Majung_Draw_GameOver;        /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Calc_Best_Grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 Majung_Calc_Best_Grade(S16 old_grade, S16 new_grade)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_grade > old_grade)
    {
        return new_grade;
    }
    else
    {
        return old_grade;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Draw_GameOver
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Draw_GameOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_GAMEOVER();
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_gfx_draw_gameover_screen(
        IMG_GX_MAJUNG_GAMEOVER,
        IMG_GX_MAJUNG_GRADESMAP,
        IMG_GX_MAJUNG_COUNT,
        majung_game_grade);
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    mmi_gfx_draw_gameover_screen(
        mmi_gfx_get_multilanguage_image_ID(
         mmi_majung_language_index, 
         IMG_GX_MAJUNG_GAMEOVER_LANGUAGE0, 
         MMI_MAJUNG_STRING_COUNT, 
         0),
        IMG_GX_MAJUNG_GRADESMAP,
        IMG_GX_MAJUNG_COUNT,
        majung_game_grade);
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /*
     * test
     * 
     * U8    buffer[64];
     * U8    buffer_UCS2[64];
     * S32   str_width;
     * 
     * GFX_PLAY_AUDIO_GAMEOVER();
     * 
     * gui_reset_text_clip();
     * gui_set_font(&MMI_medium_font);
     * gui_show_transparent_image(6, 10,get_image(IMG_GX_MAJUNG_GAMEOVER),  0);
     * gui_show_transparent_image(29, 35,get_image(IMG_GX_MAJUNG_GRADESMAP),0);
     * 
     * sprintf((PS8)buffer, "%d", majung_game_grade );
     * mmi_asc_to_ucs2((PS8) buffer_UCS2, (PS8)buffer);
     * 
     * 
     * str_width = gui_get_string_width((UI_string_type)buffer_UCS2);
     * 
     * if(r2lMMIFlag)
     * gui_move_text_cursor(((majung_lcd_width-str_width)>>1)+str_width,41);
     * else
     * gui_move_text_cursor((majung_lcd_width-str_width)>>1,41);      
     * 
     * gui_set_text_color(gui_color(0,0,0));
     * gui_print_text((UI_string_type)buffer_UCS2);
     * 
     */

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  Majung_Enter_Game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Enter_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MAJUNG_LEVEL_GEN
    /* for level gen */
    Majung_Level_Dump();
    /* end of level gen */
#endif /* MAJUNG_LEVEL_GEN */ 

    if (majung_is_new_game == TRUE)
    {
        Majung_Init_Game(); /* is new game, otherwise resume game */
    }
    else
    {
        majung_is_resume = TRUE;
    }

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_majung_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_majung_language_index, 
        IMG_GX_MAJUNG_GAMEOVER_LANGUAGE0, 
        MMI_MAJUNG_STRING_COUNT);
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    clear_screen();

    majung_is_new_game = FALSE;
    majung_is_gameover = FALSE;
    majung_draw_background = TRUE;

    SetKeyHandler(Majung_Move_Right, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Majung_Move_Left, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Majung_Move_Down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Majung_Move_Up, KEY_UP_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(Majung_Move_Right, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(Majung_Move_Left, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(Majung_Move_Down, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(Majung_Move_Up, KEY_2, KEY_EVENT_DOWN);

    SetKeyHandler(Majung_Select, KEY_5, KEY_EVENT_DOWN);

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_OPEN_BACKGROUND_SOUND(MAJUNGBackground, MAJUNGBACKGROUND, majung_background_midi);
    GFX_PLAY_BACKGROUND_SOUND(majung_background_midi);

    GFX_OPEN_DUMMY_BACKGROUND_SOUND();
    GFX_PLAY_DUMMY_BACKGROUND_SOUND();

    GFX_OPEN_SOUND_EFFECTS_MIDI(MAJUNGMove, MAJUNGMOVE, 1, majung_move_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    register_keyboard_key_handler(Majung_Keyboard_Key_Handler);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_majung_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_majung_pen_up_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    gui_start_timer(majung_timer_elapse, Majung_CountDown_Timer);

    for (i = 0; i < MAJUNG_BLOCK_ROW_COUNT * MAJUNG_BLOCK_COLUMN_COUNT; i++)
    {
        majung_block_list[i].need_redraw = TRUE;
    }

    if (majung_state == CONNECT_STATE)
    {
        gui_start_timer(100, Majung_Draw_Connection);
    }
    /* start game loop */
    Majung_Render();
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Exit_Game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Exit_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_STOP_SOUND_EFFECTS_MIDI(majung_move_midi);

    GFX_CLOSE_SOUND_EFFECTS_MIDI(majung_move_midi);

    GFX_STOP_DUMMY_BACKGROUND_SOUND();
    GFX_CLOSE_DUMMY_BACKGROUND_SOUND();

    GFX_STOP_BACKGROUND_SOUND(majung_background_midi);
    GFX_CLOSE_BACKGROUND_SOUND(majung_background_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    gui_cancel_timer(Majung_CountDown_Timer);
    gui_cancel_timer(Majung_Draw_Connection);
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Load_New_Stage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Load_New_Stage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* init game here */
    S16 i, j;
    S16 idx;
    S16 level_row_count = 0;
    S16 level_col_count = 0;
    S16 level_brick_count;
    S16 level_brick_idx;
    S16 stage_idx = 0;
    S16 level_idx_shift_x = 0;
    S16 level_idx_shift_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init some parameter for load game level into block list */
    if (majung_game_level == LEVEL_EASY)
    {
        level_idx_shift_x = 2;  /* this two shifts bricks to screen center */
        level_idx_shift_y = 2;
        level_col_count = LEVEL_COLUMN_COUNT_EASY;
        level_row_count = LEVEL_ROW_COUNT_EASY;

        stage_idx = rand() % MAJUNG_LEVEL_COUNT;

        majung_timer_elapse = 2000;
    #if defined(__MMI_GAME_MAJUNG_320x240__)
        majung_brick_start_offset_x = 55;
        majung_brick_start_offset_y = -5;
    #else
        majung_brick_start_offset_x = 0;
        majung_brick_start_offset_y = 0;
    #endif

    }
    else if (majung_game_level == LEVEL_NORMAL)
    {
        level_idx_shift_x = 1;
        level_idx_shift_y = 1;
        level_col_count = LEVEL_COLUMN_COUNT_NORMAL;
        level_row_count = LEVEL_ROW_COUNT_NORMAL;

        stage_idx = rand() % MAJUNG_LEVEL_COUNT;

        majung_timer_elapse = 2200;
    #if defined(__MMI_GAME_MAJUNG_320x240__)
        majung_brick_start_offset_x = 55;
        majung_brick_start_offset_y = -5;
    #else
        majung_brick_start_offset_x = 0;
        majung_brick_start_offset_y = 0;
    #endif
    }
    else if (majung_game_level == LEVEL_HARD)
    {
        level_idx_shift_x = 1;
        level_idx_shift_y = 1;
        level_col_count = LEVEL_COLUMN_COUNT_HARD;
        level_row_count = LEVEL_ROW_COUNT_HARD;

        stage_idx = rand() % MAJUNG_LEVEL_COUNT;

        majung_timer_elapse = 2400;
    #if defined(__MMI_GAME_MAJUNG_240x320__)
        majung_brick_start_offset_x = -6;
        majung_brick_start_offset_y = -6;
    #elif defined(__MMI_GAME_MAJUNG_320x240__)
        majung_brick_start_offset_x = 52;
        majung_brick_start_offset_y = -8;
    #else
        majung_brick_start_offset_x = -3;
        majung_brick_start_offset_y = -3;
    #endif /* defined(__MMI_GAME_MAJUNG_240x320__) */ 
    }

    majung_remain_brick = level_col_count * level_row_count;
    level_brick_count = level_row_count * level_col_count;
    level_brick_idx = 0;

    /* clear all block list */
    for (i = 0; i < MAJUNG_BLOCK_ROW_COUNT; i++)
    {
        for (j = 0; j < MAJUNG_BLOCK_COLUMN_COUNT; j++)
        {
            idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j;
            majung_block_list[idx].block_type = BLOCK_TYPE_EMPTY;
            majung_block_list[idx].need_redraw = TRUE;
        }
    }

    /* load level into block list */
    for (i = 0; i < MAJUNG_BLOCK_ROW_COUNT; i++)
    {
        for (j = 0; j < MAJUNG_BLOCK_COLUMN_COUNT; j++)
        {

            if ((j >= level_idx_shift_x) && (j < level_idx_shift_x + level_col_count) && (i >= level_idx_shift_y) && (i < level_idx_shift_y + level_row_count)) /* the pos has brick */
            {
                idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j;
                majung_block_list[idx].block_type = BLOCK_TYPE_BRICK;
                if (majung_game_level == LEVEL_EASY)
                {
                    majung_block_list[idx].brick_id = majung_easy_level[stage_idx][level_brick_idx++];
                }
                else if (majung_game_level == LEVEL_NORMAL)
                {
                    majung_block_list[idx].brick_id = majung_normal_level[stage_idx][level_brick_idx++];
                }
                else if (majung_game_level == LEVEL_HARD)
                {
                    majung_block_list[idx].brick_id = majung_hard_level[stage_idx][level_brick_idx++];
                }
            }
            else
            {
                idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j;
                majung_block_list[idx].block_type = BLOCK_TYPE_EMPTY;
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Init_Game
 * DESCRIPTION
 *  Game initilization
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Init_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Majung_Load_New_Stage();

    majung_energy = MAJUNG_ENERGY_INIT;
    majung_game_grade = 0;
    is_majung_exit_pressed = FALSE;

    majung_hilight_idx = (MAJUNG_BLOCK_ROW_COUNT >> 1) * MAJUNG_BLOCK_COLUMN_COUNT + (MAJUNG_BLOCK_COLUMN_COUNT >> 1);
    majung_selected_idx = -1;
    majung_state = PLAY_STATE;
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Render
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color bg_color = gdi_act_color_from_rgb(255,30, 150, 30);
    gdi_color hilight_color = gdi_act_color_from_rgb(255,255, 0, 0);
    S16 pos_x;
    S16 pos_y;
    S16 i, j;
    S16 idx;
    U16 img_id;
    U16 idx_x;
    U16 idx_y;
    S16 neightbor_idx;
    S16 shift_x1, shift_x2, shift_y1, shift_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw background */
    if (majung_draw_background == TRUE)
    {
        gdi_draw_solid_rect(0, 0, majung_lcd_width - 1, majung_lcd_height - 1, bg_color);
        majung_draw_background = FALSE;
    }

    for (i = 0; i < MAJUNG_BLOCK_ROW_COUNT; i++)
    {
        for (j = 0; j < MAJUNG_BLOCK_COLUMN_COUNT; j++)
        {
            pos_x = majung_brick_start_offset_x + j * MAJUNG_BRICK_WIDTH;
            pos_y = majung_brick_start_offset_y + i * MAJUNG_BRICK_HEIGHT;
            idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j;

            if (majung_block_list[idx].need_redraw == TRUE)
            {

                /* same row, has previous block */
                if (j > 0)
                {
                    neightbor_idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j - 1;
                    if (majung_block_list[neightbor_idx].block_type != BLOCK_TYPE_BRICK)
                    {
                        shift_x1 = 0;
                    }
                    else
                    {
                        shift_x1 = 1;
                    }
                }
                else
                {
                    shift_x1 = 0;
                }

                if (j < MAJUNG_BLOCK_COLUMN_COUNT - 1)
                {
                    neightbor_idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j + 1;
                    if (majung_block_list[neightbor_idx].block_type != BLOCK_TYPE_BRICK)
                    {
                        shift_x2 = 1;
                    }
                    else
                    {
                        shift_x2 = 0;
                    }
                }
                else
                {
                    shift_x2 = 1;
                }

                if (i > 0)
                {
                    neightbor_idx = (i - 1) * MAJUNG_BLOCK_COLUMN_COUNT + j;
                    if (majung_block_list[neightbor_idx].block_type != BLOCK_TYPE_BRICK)
                    {
                        shift_y1 = 0;
                    }
                    else
                    {
                        shift_y1 = 1;
                    }
                }
                else
                {
                    shift_y1 = 0;
                }

                if (i < MAJUNG_BLOCK_ROW_COUNT - 1)
                {
                    neightbor_idx = (i + 1) * MAJUNG_BLOCK_COLUMN_COUNT + j;
                    if (majung_block_list[neightbor_idx].block_type != BLOCK_TYPE_BRICK)
                    {
                        shift_y2 = 1;
                    }
                    else
                    {
                        shift_y2 = 0;
                    }
                }
                else
                {
                    shift_y2 = 1;
                }

                gdi_draw_solid_rect(
                    pos_x + shift_x1,
                    pos_y + shift_y1,
                    pos_x + MAJUNG_BRICK_WIDTH + shift_x2 - 1,
                    pos_y + MAJUNG_BRICK_HEIGHT + shift_y2 - 1,
                    bg_color);
            }
        }
    }

    for (i = 0; i < MAJUNG_BLOCK_ROW_COUNT; i++)
    {
        for (j = 0; j < MAJUNG_BLOCK_COLUMN_COUNT; j++)
        {
            pos_x = majung_brick_start_offset_x + j * MAJUNG_BRICK_WIDTH;
            pos_y = majung_brick_start_offset_y + i * MAJUNG_BRICK_HEIGHT;
            idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j;

            if (majung_block_list[idx].need_redraw == TRUE)
            {
                if (majung_block_list[idx].block_type == BLOCK_TYPE_BRICK)
                {
                    img_id = IMG_GX_MAJUNG_BRICK_1W + majung_block_list[idx].brick_id;
                    gdi_image_draw_id(pos_x, pos_y, img_id);

                    gdi_draw_point(pos_x, pos_y, bg_color);
                    gdi_draw_point(pos_x + MAJUNG_BRICK_WIDTH, pos_y, bg_color);
                    gdi_draw_point(pos_x, pos_y + MAJUNG_BRICK_HEIGHT, bg_color);
                    gdi_draw_point(pos_x + MAJUNG_BRICK_WIDTH, pos_y + MAJUNG_BRICK_HEIGHT, bg_color);

                    /* draw selected */
                    if (majung_selected_idx == idx)
                    {
                        img_id = IMG_GX_MAJUNG_BRICK_1W_SEL + majung_block_list[idx].brick_id;
                        gdi_image_draw_id(pos_x, pos_y, img_id);
                    }

                    /* block below it */
                    neightbor_idx = (i + 1) * MAJUNG_BLOCK_COLUMN_COUNT + j;

                    if (majung_block_list[neightbor_idx].block_type != BLOCK_TYPE_BRICK)
                    {
                        pos_x = majung_brick_start_offset_x + j * MAJUNG_BRICK_WIDTH;
                        pos_y =
                            majung_brick_start_offset_y + (i + 1) * MAJUNG_BRICK_HEIGHT - MAJUNG_THICK_BRICK_Y_MARGIN;
                        gdi_image_draw_id(pos_x, pos_y, IMG_GX_MAJUNG_THICK);
                    }
                }
            }
        }
    }

    for (i = 0; i < MAJUNG_BLOCK_ROW_COUNT; i++)
    {
        for (j = 0; j < MAJUNG_BLOCK_COLUMN_COUNT; j++)
        {
            if (i > 0)
            {
                idx = i * MAJUNG_BLOCK_COLUMN_COUNT + j;
                neightbor_idx = (i - 1) * MAJUNG_BLOCK_COLUMN_COUNT + j;

                if ((majung_block_list[idx].block_type == BLOCK_TYPE_EMPTY) &&
                    (majung_block_list[neightbor_idx].block_type == BLOCK_TYPE_BRICK))
                {

                    pos_x = majung_brick_start_offset_x + j * MAJUNG_BRICK_WIDTH;
                    pos_y = majung_brick_start_offset_y + i * MAJUNG_BRICK_HEIGHT - MAJUNG_THICK_BRICK_Y_MARGIN;

                    gdi_image_draw_id(pos_x, pos_y, IMG_GX_MAJUNG_THICK);
                }
            }

            majung_block_list[idx].need_redraw = FALSE;
        }
    }

    if (majung_state == CONNECT_STATE && majung_is_resume == TRUE)
    {
        /* draw connected part */

        S16 idx, idx_x, idx_y, j, pos_x, pos_y;
        U16 type;

        majung_is_resume = FALSE;

        for (j = 0; j < majung_connect_list_index; j++)
        {
            idx = majung_connect_list[j].block_index;

            /* draw highlight frame */
            idx_x = idx % (MAJUNG_BLOCK_COLUMN_COUNT);
            idx_y = idx / (MAJUNG_BLOCK_COLUMN_COUNT);

            pos_x = majung_brick_start_offset_x + idx_x * MAJUNG_BRICK_WIDTH;
            pos_y = majung_brick_start_offset_y + idx_y * MAJUNG_BRICK_HEIGHT;

            type = majung_connect_list[j].connect_type;
            gui_show_transparent_image(pos_x, pos_y, (PU8) GetImage((U16) (IMG_GX_MAJUNG_CONNECT_HOR + type)), 0);
            Majung_Update_Block(idx);
        }
    }

    /* draw highlight frame */
    idx_x = majung_hilight_idx % (MAJUNG_BLOCK_COLUMN_COUNT);
    idx_y = majung_hilight_idx / (MAJUNG_BLOCK_COLUMN_COUNT);

    pos_x = majung_brick_start_offset_x + idx_x * MAJUNG_BRICK_WIDTH;
    pos_y = majung_brick_start_offset_y + idx_y * MAJUNG_BRICK_HEIGHT;
    gdi_draw_rect(pos_x + 1, pos_y + 1, pos_x + MAJUNG_BRICK_WIDTH - 1, pos_y + MAJUNG_BRICK_HEIGHT - 1, hilight_color);
    /* draw highlight frame */

    /* draw energy */
    Majung_Render_Energy();

#if defined(__MAJUNG_DRAW_SCORE__)
    /* draw score */
    Majung_Draw_Score();
#endif /* defined(__MAJUNG_DRAW_SCORE__) */ 
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MAJUNG_DRAW_EXIT__)
    /* draw exit icon */
    Majung_Draw_Exit();
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MAJUNG_DRAW_EXIT__) */ 
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Render_Energy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Render_Energy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAJUNG_ENERGY_LIMIT; i++)
    {
        if (majung_energy >= MAJUNG_ENERGY_LIMIT - i - 1)
        {
            gdi_image_draw_id(ENERGYBAR_POS_X, ENERGYBAR_POS_Y + i * 4, (U16) (IMG_GX_MAJUNG_BAR_FILL_1 + i));
        }
        else
        {
            gdi_image_draw_id(ENERGYBAR_POS_X, ENERGYBAR_POS_Y + i * 4, (U16) (IMG_GX_MAJUNG_BAR_EMPTY_1 + i));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Gameover
 * DESCRIPTION
 *  Gameover function
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    majung_is_gameover = TRUE;
    majung_is_new_game = TRUE;

    /* call this function to draw gameover screen */
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Majung_CountDown_Timer
 * DESCRIPTION
 *  timer function
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_CountDown_Timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (majung_energy > 0)
    {
        if (majung_state == PLAY_STATE) /* add this term to avoid dead when connectino problem, 050819 David */
        {
            majung_energy--;
        }
        gui_start_timer(majung_timer_elapse, Majung_CountDown_Timer);
        Majung_Render_Energy();

        gui_BLT_double_buffer(114, 0, UI_device_width - 1, UI_device_height - 1);

    }
    else
    {
        /* energy reaches 0 */
        Majung_Gameover();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Connect_Zero_Turn
 * DESCRIPTION
 *  Update connect list for drawing
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Connect_Zero_Turn(S16 x1, S16 y1, S16 x2, S16 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 line_count = 0;
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x1 == x2)
    {
        line_count = abs(y2 - y1);
        for (i = 1; i < line_count; i++)
        {
            if (y1 < y2)
            {
                majung_connect_list[majung_connect_list_count].block_index = (y1 + i) * MAJUNG_BLOCK_COLUMN_COUNT + x1;
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_VER;
                majung_connect_list_count++;
            }
            else
            {
                majung_connect_list[majung_connect_list_count].block_index = (y1 - i) * MAJUNG_BLOCK_COLUMN_COUNT + x1;
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_VER;
                majung_connect_list_count++;
            }
        }
    }
    else if (y1 == y2)
    {
        line_count = abs(x2 - x1);
        for (i = 1; i < line_count; i++)
        {
            if (x1 < x2)
            {
                majung_connect_list[majung_connect_list_count].block_index = y1 * MAJUNG_BLOCK_COLUMN_COUNT + x1 + i;
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_HOR;
                majung_connect_list_count++;
            }
            else
            {
                majung_connect_list[majung_connect_list_count].block_index = y1 * MAJUNG_BLOCK_COLUMN_COUNT + x1 - i;
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_HOR;
                majung_connect_list_count++;
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  Manjung_Connet_Join
 * DESCRIPTION
 *  Update connection join for drawing
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  x3      [IN]        
 *  y3      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Manjung_Connet_Join(S16 x1, S16 y1, S16 x2, S16 y2, S16 x3, S16 y3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    majung_connect_list[majung_connect_list_count].block_index = y2 * MAJUNG_BLOCK_COLUMN_COUNT + x2;

    if (x1 < x3)
    {
        if (y1 < y3)
        {
            if (x1 == x2)
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_RU;
            }
            else
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_LD;
            }
        }
        else
        {
            if (x1 == x2)
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_RD;
            }
            else
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_LU;
            }
        }
    }
    else
    {
        if (y1 < y3)
        {
            if (x1 == x2)
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_LU;
            }
            else
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_RD;
            }
        }
        else
        {
            if (x1 == x2)
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_LD;
            }
            else
            {
                majung_connect_list[majung_connect_list_count].connect_type = CONNECT_RU;
            }
        }
    }

    majung_connect_list_count++;
}


/*****************************************************************************
 * FUNCTION
 *  Manjung_Calc_Connection
 * DESCRIPTION
 *  Update connect list for drawing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Manjung_Calc_Connection()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 src_idx_x;
    S16 src_idx_y;
    S16 dest_idx_x;
    S16 dest_idx_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    majung_connect_list_count = 0;

    /* calc src position */
    src_idx_x = majung_selected_idx % (MAJUNG_BLOCK_COLUMN_COUNT);
    src_idx_y = majung_selected_idx / (MAJUNG_BLOCK_COLUMN_COUNT);

    /* calc dest position */
    dest_idx_x = majung_hilight_idx % (MAJUNG_BLOCK_COLUMN_COUNT);
    dest_idx_y = majung_hilight_idx / (MAJUNG_BLOCK_COLUMN_COUNT);

    if (majung_pair_type == PAIR_ZERO_TURN)
    {
        Majung_Connect_Zero_Turn(src_idx_x, src_idx_y, dest_idx_x, dest_idx_y);
    }
    else if (majung_pair_type == PAIR_ONE_TURN)
    {
        Majung_Connect_Zero_Turn(src_idx_x, src_idx_y, majung_pair_turn_list[0].x, majung_pair_turn_list[0].y);

        Manjung_Connet_Join(
            src_idx_x,
            src_idx_y,
            majung_pair_turn_list[0].x,
            majung_pair_turn_list[0].y,
            dest_idx_x,
            dest_idx_y);

        Majung_Connect_Zero_Turn(majung_pair_turn_list[0].x, majung_pair_turn_list[0].y, dest_idx_x, dest_idx_y);

    }
    else if (majung_pair_type == PAIR_TWO_TURN)
    {
        Majung_Connect_Zero_Turn(src_idx_x, src_idx_y, majung_pair_turn_list[0].x, majung_pair_turn_list[0].y);

        Manjung_Connet_Join(
            src_idx_x,
            src_idx_y,
            majung_pair_turn_list[0].x,
            majung_pair_turn_list[0].y,
            majung_pair_turn_list[1].x,
            majung_pair_turn_list[1].y);

        Majung_Connect_Zero_Turn(
            majung_pair_turn_list[0].x,
            majung_pair_turn_list[0].y,
            majung_pair_turn_list[1].x,
            majung_pair_turn_list[1].y);

        Manjung_Connet_Join(
            majung_pair_turn_list[0].x,
            majung_pair_turn_list[0].y,
            majung_pair_turn_list[1].x,
            majung_pair_turn_list[1].y,
            dest_idx_x,
            dest_idx_y);

        Majung_Connect_Zero_Turn(majung_pair_turn_list[1].x, majung_pair_turn_list[1].y, dest_idx_x, dest_idx_y);
    }

    // Majung_Render(); // debug use */

    //      for( i = 0 ; i < majung_connect_list_count ; i++)
    //      {
    //                      
    //              idx_x = majung_connect_list[i].block_index%(MAJUNG_BLOCK_COLUMN_COUNT);
    //              idx_y = majung_connect_list[i].block_index/(MAJUNG_BLOCK_COLUMN_COUNT);
    //
    //              pos_x = majung_brick_start_offset_x+idx_x*MAJUNG_BRICK_WIDTH;
    //              pos_y = majung_brick_start_offset_y+idx_y*MAJUNG_BRICK_HEIGHT;
    //
    //              gui_draw_rectangle(pos_x, pos_y, pos_x + 5, pos_y + 5, gui_color(0,255,255));
    //      }

    /* gui_BLT_double_buffer(0,0, majung_lcd_width - 1, majung_lcd_height -1); */

}


/*****************************************************************************
 * FUNCTION
 *  Majung_Pair_Check_Zero_Turn
 * DESCRIPTION
 *  Check if two block may connect without turn
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL Majung_Pair_Check_Zero_Turn(S16 x1, S16 y1, S16 x2, S16 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_zero_turn_paired;
    S16 pos_1, pos_2;
    S16 test_count;
    S16 i;
    S16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* test if they can do zero turn pair */
    if ((x1 != x2) && (y1 != y2))
    {
        return FALSE;
    }

    is_zero_turn_paired = TRUE;

    /* same column test */
    if (x1 == x2)
    {
        /* set pos_2 larger than pos_1 */
        if (y1 < y2)
        {
            pos_1 = y1;
            pos_2 = y2;
        }
        else
        {
            pos_1 = y2;
            pos_2 = y1;
        }

        test_count = pos_2 - pos_1;

        if (test_count != 0)
        {
            for (i = 1; i < test_count; i++)
            {
                idx = (i + pos_1) * MAJUNG_BLOCK_COLUMN_COUNT + x1;
                if (majung_block_list[idx].block_type == BLOCK_TYPE_BRICK)
                {
                    is_zero_turn_paired = FALSE;
                    break;
                }
            }
        }
    }

    /* same row test */
    if (y1 == y2)
    {
        /* set pos_2 larger than pos_1 */
        if (x1 < x2)
        {
            pos_1 = x1;
            pos_2 = x2;
        }
        else
        {
            pos_1 = x2;
            pos_2 = x1;
        }

        test_count = pos_2 - pos_1;
        if (test_count != 0)
        {
            for (i = 1; i < test_count; i++)
            {
                idx = y1 * MAJUNG_BLOCK_COLUMN_COUNT + (pos_1 + i);
                if (majung_block_list[idx].block_type == BLOCK_TYPE_BRICK)
                {
                    is_zero_turn_paired = FALSE;
                    break;
                }
            }
        }
    }

    return is_zero_turn_paired;
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Pair_Check
 * DESCRIPTION
 *  Check if two block may connect
 * PARAMETERS
 *  src_idx_x       [IN]        
 *  src_idx_y       [IN]        
 *  dest_idx_x      [IN]        
 *  dest_idx_y      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL Majung_Pair_Check(S16 src_idx_x, S16 src_idx_y, S16 dest_idx_x, S16 dest_idx_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 idx;
    S16 join_idx_x;
    S16 join_idx_y;
    S16 join_idx_1;
    S16 join_idx_2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (majung_block_list[majung_selected_idx].brick_id != majung_block_list[majung_hilight_idx].brick_id)
    {
        return FALSE;
    }

   /************************************************************************/
    /* check 0 turn pair                                     */
   /************************************************************************/
    if (Majung_Pair_Check_Zero_Turn(src_idx_x, src_idx_y, dest_idx_x, dest_idx_y))
    {
        majung_pair_type = PAIR_ZERO_TURN;
        return TRUE;
    }

   /************************************************************************/
    /* check 1 turn pair                                     */
   /************************************************************************/
    /* first join */
    join_idx_x = src_idx_x;
    join_idx_y = dest_idx_y;

    idx = join_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + join_idx_x;

    if (majung_block_list[idx].block_type != BLOCK_TYPE_BRICK)
    {
        if ((Majung_Pair_Check_Zero_Turn(src_idx_x, src_idx_y, join_idx_x, join_idx_y)) &&
            (Majung_Pair_Check_Zero_Turn(dest_idx_x, dest_idx_y, join_idx_x, join_idx_y)))
        {
            majung_pair_type = PAIR_ONE_TURN;
            majung_pair_turn_list[0].x = join_idx_x;
            majung_pair_turn_list[0].y = join_idx_y;
            return TRUE;
        }
    }

    /* second join */
    join_idx_x = dest_idx_x;
    join_idx_y = src_idx_y;

    idx = join_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + join_idx_x;

    if (majung_block_list[idx].block_type != BLOCK_TYPE_BRICK)
    {
        if ((Majung_Pair_Check_Zero_Turn(src_idx_x, src_idx_y, join_idx_x, join_idx_y)) &&
            (Majung_Pair_Check_Zero_Turn(dest_idx_x, dest_idx_y, join_idx_x, join_idx_y)))
        {
            majung_pair_type = PAIR_ONE_TURN;
            majung_pair_turn_list[0].x = join_idx_x;
            majung_pair_turn_list[0].y = join_idx_y;
            return TRUE;
        }
    }

   /************************************************************************/
    /* check 2 turn pair                                                    */
   /************************************************************************/
    /* expand src brick */
    /* expand to right */
    if (src_idx_x < MAJUNG_BLOCK_COLUMN_COUNT)
    {
        for (i = 1; i < (MAJUNG_BLOCK_COLUMN_COUNT - src_idx_x); i++)
        {
            join_idx_x = src_idx_x + i;
            join_idx_1 = src_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + join_idx_x;
            join_idx_2 = dest_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + join_idx_x;

            if ((majung_block_list[join_idx_1].block_type != BLOCK_TYPE_BRICK))
            {
                if ((majung_block_list[join_idx_2].block_type != BLOCK_TYPE_BRICK) &&
                    (Majung_Pair_Check_Zero_Turn(src_idx_x, src_idx_y, join_idx_x, src_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(join_idx_x, src_idx_y, join_idx_x, dest_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(join_idx_x, dest_idx_y, dest_idx_x, dest_idx_y)))
                {

                    majung_pair_turn_list[0].x = join_idx_x;
                    majung_pair_turn_list[0].y = src_idx_y;

                    majung_pair_turn_list[1].x = join_idx_x;
                    majung_pair_turn_list[1].y = dest_idx_y;

                    majung_pair_type = PAIR_TWO_TURN;

                    return TRUE;
                }
            }
            else
            {
                break;
            }
        }
    }

    /* expand to left */
    if (src_idx_x > 0)
    {
        for (i = 1; i < (src_idx_x + 1); i++)
        {
            join_idx_x = src_idx_x - i;
            join_idx_1 = src_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + join_idx_x;
            join_idx_2 = dest_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + join_idx_x;

            if ((majung_block_list[join_idx_1].block_type != BLOCK_TYPE_BRICK))
            {
                if ((majung_block_list[join_idx_2].block_type != BLOCK_TYPE_BRICK) &&
                    (Majung_Pair_Check_Zero_Turn(src_idx_x, src_idx_y, join_idx_x, src_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(join_idx_x, src_idx_y, join_idx_x, dest_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(join_idx_x, dest_idx_y, dest_idx_x, dest_idx_y)))
                {
                    majung_pair_turn_list[0].x = join_idx_x;
                    majung_pair_turn_list[0].y = src_idx_y;

                    majung_pair_turn_list[1].x = join_idx_x;
                    majung_pair_turn_list[1].y = dest_idx_y;

                    majung_pair_type = PAIR_TWO_TURN;

                    return TRUE;
                }
            }
            else
            {
                break;
            }
        }
    }

    /* expand to down */
    if (src_idx_y < MAJUNG_BLOCK_ROW_COUNT)
    {
        for (i = 1; i < (MAJUNG_BLOCK_ROW_COUNT - src_idx_y); i++)
        {
            join_idx_y = src_idx_y + i;
            join_idx_1 = join_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + src_idx_x;
            join_idx_2 = join_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + dest_idx_x;

            if ((majung_block_list[join_idx_1].block_type != BLOCK_TYPE_BRICK))
            {
                if ((majung_block_list[join_idx_2].block_type != BLOCK_TYPE_BRICK) &&
                    (Majung_Pair_Check_Zero_Turn(src_idx_x, src_idx_y, src_idx_x, join_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(src_idx_x, join_idx_y, dest_idx_x, join_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(dest_idx_x, join_idx_y, dest_idx_x, dest_idx_y)))
                {
                    majung_pair_turn_list[0].x = src_idx_x;
                    majung_pair_turn_list[0].y = join_idx_y;

                    majung_pair_turn_list[1].x = dest_idx_x;
                    majung_pair_turn_list[1].y = join_idx_y;

                    majung_pair_type = PAIR_TWO_TURN;

                    return TRUE;
                }
            }
            else
            {
                break;
            }
        }
    }

    /* expand to up */
    if (src_idx_y > 0)
    {
        for (i = 1; i < (src_idx_y + 1); i++)
        {
            join_idx_y = src_idx_y - i;
            join_idx_1 = join_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + src_idx_x;
            join_idx_2 = join_idx_y * MAJUNG_BLOCK_COLUMN_COUNT + dest_idx_x;

            if ((majung_block_list[join_idx_1].block_type != BLOCK_TYPE_BRICK))
            {
                if ((majung_block_list[join_idx_2].block_type != BLOCK_TYPE_BRICK) &&
                    (Majung_Pair_Check_Zero_Turn(src_idx_x, src_idx_y, src_idx_x, join_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(src_idx_x, join_idx_y, dest_idx_x, join_idx_y)) &&
                    (Majung_Pair_Check_Zero_Turn(dest_idx_x, join_idx_y, dest_idx_x, dest_idx_y)))
                {
                    majung_pair_turn_list[0].x = src_idx_x;
                    majung_pair_turn_list[0].y = join_idx_y;

                    majung_pair_turn_list[1].x = dest_idx_x;
                    majung_pair_turn_list[1].y = join_idx_y;

                    majung_pair_type = PAIR_TWO_TURN;

                    return TRUE;
                }
            }
            else
            {
                break;
            }
        }
    }

    /* update first selected's expansion map */

    /* Majung_Render();  // debug use */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Move_Right
 * DESCRIPTION
 *  Move selection to right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Move_Right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx_x;
    S16 idx_y;
    S16 level_shift_x = 0, level_col_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(majung_game_level)
    {
	case  LEVEL_EASY:
		level_shift_x = 2;
		level_col_count = LEVEL_COLUMN_COUNT_EASY;
		break;
	case  LEVEL_NORMAL:
		level_shift_x = 1;
		level_col_count = LEVEL_COLUMN_COUNT_NORMAL;
		break;
	case  LEVEL_HARD:
		level_shift_x = 1;
		level_col_count = LEVEL_COLUMN_COUNT_HARD;
		break;
    }

    if (majung_state == PLAY_STATE)
    {
        idx_x = majung_hilight_idx % MAJUNG_BLOCK_COLUMN_COUNT;
        idx_y = majung_hilight_idx / MAJUNG_BLOCK_COLUMN_COUNT;

        if (idx_x < level_shift_x + level_col_count - 1)
        {
            idx_x++;
        }

        Majung_Update_Block(majung_hilight_idx);

        majung_hilight_idx = idx_y * MAJUNG_BLOCK_COLUMN_COUNT + idx_x;

        Majung_Update_Block(majung_hilight_idx);
        Majung_Render();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Move_Left
 * DESCRIPTION
 *  Move selection to left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Move_Left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx_x;
    S16 idx_y;
    S16 level_shift_x = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (majung_state == PLAY_STATE)
    {
        idx_x = majung_hilight_idx % MAJUNG_BLOCK_COLUMN_COUNT;
        idx_y = majung_hilight_idx / MAJUNG_BLOCK_COLUMN_COUNT;

		switch(majung_game_level)
		{
		case  LEVEL_EASY:
			level_shift_x = 2;
			break;
		case  LEVEL_NORMAL:
			level_shift_x = 1;
			break;
		case  LEVEL_HARD:
			level_shift_x = 1;
			break;
		}

        if (idx_x > level_shift_x)
        {
            idx_x--;
        }

        Majung_Update_Block(majung_hilight_idx);

        majung_hilight_idx = idx_y * MAJUNG_BLOCK_COLUMN_COUNT + idx_x;

        Majung_Update_Block(majung_hilight_idx);

        Majung_Render();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Move_Up
 * DESCRIPTION
 *  Move selection to up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Move_Up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx_x;
    S16 idx_y;
    S16 level_shift_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (majung_state == PLAY_STATE)
    {
        idx_x = majung_hilight_idx % MAJUNG_BLOCK_COLUMN_COUNT;
        idx_y = majung_hilight_idx / MAJUNG_BLOCK_COLUMN_COUNT;

		switch(majung_game_level)
		{
		case  LEVEL_EASY:
			level_shift_y = 2;
			break;
		case  LEVEL_NORMAL:
			level_shift_y = 1;
			break;
		case  LEVEL_HARD:
			level_shift_y = 1;
			break;
		}

        if (idx_y > level_shift_y)
        {
            idx_y--;
        }

        Majung_Update_Block(majung_hilight_idx);

        majung_hilight_idx = idx_y * MAJUNG_BLOCK_COLUMN_COUNT + idx_x;

        Majung_Update_Block(majung_hilight_idx);

        Majung_Render();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Move_Down
 * DESCRIPTION
 *  Move selection to down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Move_Down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx_x;
    S16 idx_y;
    S16 level_row_count = 0, level_shift_y = 0;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(majung_game_level)
    {
	case  LEVEL_EASY:
		level_shift_y = 2;
		level_row_count = LEVEL_ROW_COUNT_EASY;
		break;
	case  LEVEL_NORMAL:
		level_shift_y = 1;
		level_row_count = LEVEL_ROW_COUNT_NORMAL;
		break;
	case  LEVEL_HARD:
		level_shift_y = 1;
		level_row_count = LEVEL_ROW_COUNT_HARD;
		break;
    }
	
    if (majung_state == PLAY_STATE)
    {
        idx_x = majung_hilight_idx % MAJUNG_BLOCK_COLUMN_COUNT;
        idx_y = majung_hilight_idx / MAJUNG_BLOCK_COLUMN_COUNT;

        if (idx_y <  level_shift_y + level_row_count  - 1)
        {
            idx_y++;
        }

        Majung_Update_Block(majung_hilight_idx);

        majung_hilight_idx = idx_y * MAJUNG_BLOCK_COLUMN_COUNT + idx_x;

        Majung_Update_Block(majung_hilight_idx);

        Majung_Render();
    }

}


/*****************************************************************************
 * FUNCTION
 *  Majung_Draw_Connection
 * DESCRIPTION
 *  Draw Connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Draw_Connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx_x;
    S16 idx_y;
    S16 pos_x;
    S16 pos_y;
    S16 idx;
    U16 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* no more to draw */
    if (majung_connect_list_index >= majung_connect_list_count)
    {
        majung_block_list[majung_selected_idx].block_type = BLOCK_TYPE_EMPTY;
        majung_block_list[majung_hilight_idx].block_type = BLOCK_TYPE_EMPTY;

        Majung_Update_Block(majung_selected_idx);
        Majung_Update_Block(majung_hilight_idx);

        majung_selected_idx = -1;
        majung_state = PLAY_STATE;

        GFX_PLAY_VIBRATION();
        /* add score */
        majung_game_grade++;

        majung_remain_brick -= 2;
        if (majung_remain_brick == 0)
        {
        #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
            GFX_STOP_SOUND_EFFECTS_MIDI(majung_move_midi);

            GFX_PLAY_SOUND_EFFECTS_MIDI(majung_move_midi);
        #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

            majung_timer_elapse -= 30;
            if (majung_timer_elapse < 100)
            {
                majung_timer_elapse = 100;
            }

            Majung_Load_New_Stage();
        }
        else
        {
        #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
            GFX_STOP_SOUND_EFFECTS_MIDI(majung_move_midi);

            GFX_PLAY_SOUND_EFFECTS_MIDI(majung_move_midi);
        #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        }
        majung_energy += UNIT_ENERGY_INCREASE_PER_SCORE;
        if (majung_energy >= MAJUNG_ENERGY_LIMIT)
        {
            majung_energy = MAJUNG_ENERGY_LIMIT;
        }

        Majung_Render_Energy();

        gui_start_timer(majung_timer_elapse, Majung_CountDown_Timer);

        Majung_Render();
        return;
    }
    else
    {
        idx = majung_connect_list[majung_connect_list_index].block_index;

        /* draw highlight frame */
        idx_x = idx % (MAJUNG_BLOCK_COLUMN_COUNT);
        idx_y = idx / (MAJUNG_BLOCK_COLUMN_COUNT);

        pos_x = majung_brick_start_offset_x + idx_x * MAJUNG_BRICK_WIDTH;
        pos_y = majung_brick_start_offset_y + idx_y * MAJUNG_BRICK_HEIGHT;

        type = majung_connect_list[majung_connect_list_index].connect_type;
        gui_show_transparent_image(pos_x, pos_y, (PU8) GetImage((U16) (IMG_GX_MAJUNG_CONNECT_HOR + type)), 0);
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

        Majung_Update_Block(idx);

        majung_connect_list_index++;
        majung_state = CONNECT_STATE;
        gui_start_timer(100, Majung_Draw_Connection);
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Select
 * DESCRIPTION
 *  Press selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 src_idx_x, src_idx_y;
    S16 dest_idx_x, dest_idx_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calc src position */
    src_idx_x = majung_selected_idx % (MAJUNG_BLOCK_COLUMN_COUNT);
    src_idx_y = majung_selected_idx / (MAJUNG_BLOCK_COLUMN_COUNT);

    /* calc dest position */
    dest_idx_x = majung_hilight_idx % (MAJUNG_BLOCK_COLUMN_COUNT);
    dest_idx_y = majung_hilight_idx / (MAJUNG_BLOCK_COLUMN_COUNT);

    if (majung_state == PLAY_STATE)
    {
        if (majung_selected_idx != -1)
        {
            Majung_Update_Block(majung_selected_idx);
        }

        /* already select one */
        if ((majung_selected_idx != -1) && (majung_selected_idx != majung_hilight_idx))
        {
            /* if have a correct pair */
            if ((majung_block_list[majung_hilight_idx].block_type == BLOCK_TYPE_BRICK) &&
                (majung_block_list[majung_selected_idx].block_type == BLOCK_TYPE_BRICK) &&
                (Majung_Pair_Check(src_idx_x, src_idx_y, dest_idx_x, dest_idx_y)))
            {
                Majung_Update_Block(majung_selected_idx);
                Majung_Update_Block(majung_hilight_idx);

                Manjung_Calc_Connection();

                majung_connect_list_index = 0;
                Majung_Draw_Connection();

                return;
            }
            else    /* wrong pair */
            {
                /* modified 050826 David : originally wrong choice cancel both select and highlight,
                   for better touch penal performance, change the move to "setting the newly selected  
                   to be new hilight and cancel last highlight */
                /* majung_selected_idx = -1; */

                S16 temp_idx = majung_selected_idx;

                majung_selected_idx = majung_hilight_idx;
                /* majung_hilight_idx = -1; */
                Majung_Update_Block(temp_idx);
                Majung_Update_Block(majung_selected_idx);
            }
        }
        else
        {

            /* change selection */
            if (majung_block_list[majung_hilight_idx].block_type == BLOCK_TYPE_BRICK)
            {
                if (majung_selected_idx != majung_hilight_idx)
                {
                    majung_selected_idx = majung_hilight_idx;
                }
                else
                {
                    majung_selected_idx = -1;
                }
            }

        }

        Majung_Update_Block(majung_selected_idx);
        Majung_Update_Block(majung_hilight_idx);

        Majung_Render();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Majung_Update_Block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Update_Block(S16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx_x, idx_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx == -1)
    {
        return;
    }

    majung_block_list[idx].need_redraw = TRUE;
    idx_x = idx % (MAJUNG_BLOCK_COLUMN_COUNT);
    idx_y = idx / (MAJUNG_BLOCK_COLUMN_COUNT);

    if (idx_x > 0)
    {
        idx = idx_y * MAJUNG_BLOCK_COLUMN_COUNT + idx_x - 1;
        majung_block_list[idx].need_redraw = TRUE;
    }

    if (idx_x < MAJUNG_BLOCK_COLUMN_COUNT - 1)
    {
        idx = idx_y * MAJUNG_BLOCK_COLUMN_COUNT + idx_x + 1;
        majung_block_list[idx].need_redraw = TRUE;
    }

    if (idx_y > 0)
    {
        idx = (idx_y - 1) * MAJUNG_BLOCK_COLUMN_COUNT + idx_x;
        majung_block_list[idx].need_redraw = TRUE;
    }

    if (idx_y < MAJUNG_BLOCK_ROW_COUNT - 1)
    {
        idx = (idx_y + 1) * MAJUNG_BLOCK_COLUMN_COUNT + idx_x;
        majung_block_list[idx].need_redraw = TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  Majung_Keyboard_Key_Handler
 * DESCRIPTION
 *  Allow to use keyboard in PC_sumulator
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Keyboard_Key_Handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    if (key_state)
    {
        switch (vkey_code)  /* key down */
        {
            case 37:
                Majung_Move_Left();     /* left */
                break;
            case 38:
                Majung_Move_Up();       /* up */
                break;
            case 39:
                Majung_Move_Right();    /* right */
                break;
            case 40:
                Majung_Move_Down();     /* down */
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 

}

/************************************************************************/
/* From this line are level generator                                   */
/************************************************************************/
#ifdef MAJUNG_LEVEL_GEN


/*****************************************************************************
 * FUNCTION
 *  Majung_Level_Gen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL Majung_Level_Gen(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 total_count = width * height;
    S16 idx_x;
    S16 idx_y;
    S16 index1, index2;
    S16 index;
    S16 empty_block_idx[MAJUNG_BLOCK_COLUMN_COUNT * MAJUNG_BLOCK_ROW_COUNT];
    S16 empty_block_count;
    S16 brick_1_idx;
    S16 brick_2_idx;
    S16 src_idx_x, src_idx_y;
    S16 dest_idx_x, dest_idx_y;
    U16 brick_type;
    S16 try_count;
    U16 up_idx;
    U16 down_idx;
    U16 left_idx;
    U16 right_idx;
    BOOL brick_used[BRICK_TOTOAL_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BRICK_TOTOAL_COUNT; i++)
    {
        brick_used[i] = FALSE;
    }

    for (i = 0; i < MAJUNG_BLOCK_COLUMN_COUNT * MAJUNG_BLOCK_ROW_COUNT; i++)
    {
        majung_block_list[i].block_type = BLOCK_TYPE_EMPTY;
        majung_block_list[i].brick_id = 255;
    }

    try_count = 100;

    while (total_count > 0)
    {
        empty_block_count = 0;

        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                index = (i + 1) * MAJUNG_BLOCK_COLUMN_COUNT + (j + 1);

                if (majung_block_list[index].block_type != BLOCK_TYPE_BRICK)
                {
                    up_idx = (i) * MAJUNG_BLOCK_COLUMN_COUNT + (j + 1);
                    down_idx = (i + 2) * MAJUNG_BLOCK_COLUMN_COUNT + (j + 1);
                    left_idx = (i + 1) * MAJUNG_BLOCK_COLUMN_COUNT + (j);
                    right_idx = (i + 1) * MAJUNG_BLOCK_COLUMN_COUNT + (j + 2);

                    if ((majung_block_list[up_idx].block_type != BLOCK_TYPE_BRICK) ||
                        (majung_block_list[down_idx].block_type != BLOCK_TYPE_BRICK) ||
                        (majung_block_list[left_idx].block_type != BLOCK_TYPE_BRICK) ||
                        (majung_block_list[right_idx].block_type != BLOCK_TYPE_BRICK))
                    {
                        empty_block_idx[empty_block_count] = index;
                        empty_block_count++;
                    }
                    else
                    {
                        return FALSE;
                    }
                }

            }

        }

        index1 = rand() % empty_block_count;
        brick_1_idx = empty_block_idx[index1];

        index2 = rand() % empty_block_count;
        brick_2_idx = empty_block_idx[index2];

        if (index1 != index2)
        {
            /* these code avoid too many adjecent brick */
            if ((brick_1_idx == brick_2_idx - 1) ||
                (brick_1_idx == brick_2_idx + 1) ||
                (brick_1_idx == brick_2_idx - MAJUNG_BLOCK_COLUMN_COUNT) ||
                (brick_1_idx == brick_2_idx + MAJUNG_BLOCK_COLUMN_COUNT))
            {
                if (rand() % 10 < 8)
                {
                    continue;
                }
            }

            /* calc src position */
            src_idx_x = brick_1_idx % (MAJUNG_BLOCK_COLUMN_COUNT);
            src_idx_y = brick_1_idx / (MAJUNG_BLOCK_COLUMN_COUNT);

            /* calc dest position */
            dest_idx_x = brick_2_idx % (MAJUNG_BLOCK_COLUMN_COUNT);
            dest_idx_y = brick_2_idx / (MAJUNG_BLOCK_COLUMN_COUNT);

            if (Majung_Pair_Check(src_idx_x, src_idx_y, dest_idx_x, dest_idx_y))
            {
                /*
                 * cancel for stage more than 66 bricks            
                 * while(1)
                 * {
                 */
                brick_type = rand() % BRICK_TOTOAL_COUNT;
                /*
                 * cancel for stage more than 66 bricks            
                 * 
                 * if(brick_used[brick_type] == FALSE)
                 * {
                 * brick_used[brick_type] = TRUE;
                 * break;
                 * }
                 * 
                 * }
                 */
                majung_block_list[brick_1_idx].block_type = BLOCK_TYPE_BRICK;
                majung_block_list[brick_2_idx].block_type = BLOCK_TYPE_BRICK;

                majung_block_list[brick_1_idx].brick_id = brick_type;
                majung_block_list[brick_2_idx].brick_id = brick_type;

                total_count -= 2;
            }
            else
            {
                if (total_count == 2)
                {
                    return FALSE;
                }

                if (total_count == 4)
                {
                    try_count -= 10;
                }

                if (total_count == 6)
                {
                    try_count -= 6;
                }

                if (try_count <= 0)
                {
                    return FALSE;
                }
                else
                {
                    try_count--;
                }
            }
        }
    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  Majung_Level_Dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Majung_Level_Dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 level_count_max = MAJUNG_DUMP_LEVEL_COUNT_PERTIME;

    S32 level_brick_width = MAJUNG_DUMP_LEVEL_SIZE_WIDTH;
    S32 level_brick_height = MAJUNG_DUMP_LEVEL_SIZE_HEIGHT;

    S16 i;
    S16 j;
    S16 index;
    S32 level_count = 0;

    FILE *pfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_draw_id(100, 100, IMG_GX_MAJUNG_THICK);

    pfile = fopen("C:\\game\\level.txt", "w");

    if (pfile)
    {
        fprintf(pfile, "static const U8 majung_%dx%d_level[][] = {	", level_brick_width, level_brick_height);

        while (level_count < level_count_max)
        {
            if (Majung_Level_Gen(level_brick_width, level_brick_height))
            {
                if (level_count != 0)
                {
                    fprintf(
                        pfile,
                        "											{	",
                        level_brick_width,
                        level_brick_height);
                }
                else
                {
                    fprintf(pfile, "{	", level_brick_width, level_brick_height);
                }

                for (i = 0; i < level_brick_height; i++)
                {
                    for (j = 0; j < level_brick_width; j++)
                    {

                        //       if( (j == 0) && (i != 0) )
                        //       {
                        //               fprintf(pfile, "\n");
                        //               fprintf(pfile, "                                                                                                ");
                        //       }

                        index = (i + 1) * MAJUNG_BLOCK_COLUMN_COUNT + (j + 1);
                        if ((i == level_brick_height - 1) && (j == level_brick_width - 1))
                        {
                            fprintf(pfile, "%2d},", majung_block_list[index].brick_id);
                        }
                        else
                        {
                            fprintf(pfile, "%2d,", majung_block_list[index].brick_id);
                        }

                    }
                }

                level_count++;
                fprintf(pfile, "\n");
            }
        }

        fclose(pfile);

    }
}

#endif /* MAJUNG_LEVEL_GEN */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_majung_pen_down_hdlr
 * DESCRIPTION
 *  Allow to use keyboard in PC_sumulator
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__

void mmi_majung_pen_down_hdlr(mmi_pen_point_struct pos)
{
    S16 level_shift_x = 0, level_shift_y = 0, level_row_count = 0, level_col_count = 0, row = 0, column = 0;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(majung_game_level)
    {
	case  LEVEL_EASY:
		level_shift_x = 2;
		level_shift_y = 2;
		level_row_count = LEVEL_ROW_COUNT_EASY;
		level_col_count = LEVEL_COLUMN_COUNT_EASY;
		break;
	case  LEVEL_NORMAL:
		level_shift_x = 1;
		level_shift_y = 1;
		level_row_count = LEVEL_ROW_COUNT_NORMAL;
		level_col_count = LEVEL_COLUMN_COUNT_NORMAL;
		break;
	case  LEVEL_HARD:
		level_shift_x = 1;
		level_shift_y = 1;
		level_row_count = LEVEL_ROW_COUNT_HARD;
		level_col_count = LEVEL_COLUMN_COUNT_HARD;
		break;
    }

    if (pos.x > MAJUNG_EXIT_X && pos.x < MAJUNG_EXIT_X + MAJUNG_EXIT_WIDTH
        && pos.y > MAJUNG_EXIT_Y && pos.y < MAJUNG_EXIT_Y + MAJUNG_EXIT_HEIGHT)
    {
        is_majung_exit_pressed = TRUE;
        Majung_Render();
    }
    else if (pos.x < majung_brick_start_offset_x + MAJUNG_BRICK_WIDTH ||
             pos.x >= majung_brick_start_offset_x + (MAJUNG_BLOCK_COLUMN_COUNT - 1) * MAJUNG_BRICK_WIDTH ||
             pos.y < majung_brick_start_offset_y + MAJUNG_BRICK_HEIGHT ||
             pos.y >= majung_brick_start_offset_y + (MAJUNG_BLOCK_ROW_COUNT - 1) * MAJUNG_BRICK_HEIGHT)
    {
        return;
    }
    else if (majung_state == PLAY_STATE)
    {
        Majung_Update_Block(majung_hilight_idx);
		row =   (pos.y - majung_brick_start_offset_y) / MAJUNG_BRICK_HEIGHT;
		column = (pos.x -  majung_brick_start_offset_x) / MAJUNG_BRICK_WIDTH;
		if(row < level_shift_y || row >= level_shift_y + level_row_count)
			return;
		if(column < level_shift_x || column >= level_shift_x + level_col_count)
			return;
        majung_hilight_idx =
            (pos.y - majung_brick_start_offset_y) / MAJUNG_BRICK_HEIGHT * MAJUNG_BLOCK_COLUMN_COUNT + (pos.x -
                                                                                                       majung_brick_start_offset_x)
            / MAJUNG_BRICK_WIDTH;
        Majung_Select();
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_majung_pen_up_hdlr
 * DESCRIPTION
 *  Allow to use keyboard in PC_sumulator
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_majung_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_majung_exit_pressed == TRUE)
    {
        is_majung_exit_pressed = FALSE;
        Majung_Render();

        if (pos.x > MAJUNG_EXIT_X && pos.x < MAJUNG_EXIT_X + MAJUNG_EXIT_WIDTH
            && pos.y > MAJUNG_EXIT_Y && pos.y < MAJUNG_EXIT_Y + MAJUNG_EXIT_HEIGHT)
        {
            GoBackHistory();
        }

    }

    /* nothing here currently */

}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* IS_MAJUNG_BASE_GAME */ 

