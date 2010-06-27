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
 *   2d_engine.h
 *
 * Project:
 * --------
 *   Device Test
 *
 * Description:
 * ------------
 *   G2D include file
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _G2DENGINE_H
#define _G2DENGINE_H

#include "drv_features.h"

#if defined(DRV_2D_ENGINE_V1) || defined(DRV_2D_ENGINE_V2)

#include "reg_base.h"

#define G2D_COMPLETE_EVENT      0x0001
#define DISABLE_MODE            0
#define ENABLE_MODE             1

#define G2D_FIRE_CTRL_REG               (G2D_base + 0x0100)
#define G2D_SUBMODE_CTRL_REG            (G2D_base + 0x0104)
#define G2D_COMM_CTRL_REG               (G2D_base + 0x0108)
#define G2D_INT_CTRL_REG                (G2D_base + 0x010C)
#define G2D_STATUS_REG                  (G2D_base + 0x0110)
#define G2D_SRC_BASE_ADDRESS_REG        (G2D_base + 0x0200)
    #if defined(DRV_2D_ENGINE_V2)
#define G2D_TRIANGLE_SLOPE_L_REG        (G2D_base + 0x0200)
    #endif
#define G2D_SRC_PITCH_REG               (G2D_base + 0x0204)
#define G2D_SRC_XY_REG                  (G2D_base + 0x0208)
#define G2D_SRC_WIDTH_HEIGHT_REG        (G2D_base + 0x020C)
#define G2D_SRC_KEY_COLOR_REG           (G2D_base + 0x0210)
    #if defined(DRV_2D_ENGINE_V1)
#define G2D_K1_REG                      (G2D_base + 0x0210)
#define G2D_SRC_ALPHA_REG               (G2D_base + 0x0214)
#define G2D_K2_REG                      (G2D_base + 0x0214)
#define G2D_PAT_FG_COLOR_REG            (G2D_base + 0x0218)
#define G2D_PAT_BG_COLOR_REG            (G2D_base + 0x021C)
#define G2D_DEST_ALPHA_REG              (G2D_base + 0x021C)
#define G2D_E_REG                       (G2D_base + 0x021C)
    #endif
#define G2D_DEST_BASE_ADDRESS_REG       (G2D_base + 0x0300)
#define G2D_DEST_PITCH_REG              (G2D_base + 0x0304)
#define G2D_DEST_XY_REG                 (G2D_base + 0x0308)
#define G2D_XY_START_REG                (G2D_base + 0x0308)
#define G2D_XY_END_REG                  (G2D_base + 0x030C)
#if defined(DRV_2D_ENGINE_V1)
#define G2D_DEST_WIDTH_HEIGHT_REG       (G2D_base + 0x030C)
#define G2D_CLP_LT_REG                  (G2D_base + 0x0500)
#define G2D_CLP_RB_REG                  (G2D_base + 0x0504)
#elif defined(DRV_2D_ENGINE_V2)
#define G2D_CIRCLE_CENTER_REG           (G2D_base+ 0x0308)
#define G2D_BEZIER_XY_START_REG         (G2D_base+ 0x0308)
#define G2D_CIRCLE_RADIUS_REG           (G2D_base+ 0x030C)
#define G2D_BEZIER_XY_MIDDLE_REG        (G2D_base+ 0x030C)
#define G2D_TRIANGLE_Y_END_REG          (G2D_base+ 0x030C)
#define G2D_BEZIER_XY_END_REG           (G2D_base+ 0x0310)
#define G2D_LINE_DELTA_XY_REG           (G2D_base+ 0x0310)
#define G2D_DEST_WIDTH_HEIGHT_REG       (G2D_base+ 0x0318)
#define G2D_START_COLOR_REG             (G2D_base+ 0x0400)
#define G2D_PAT_FG_COLOR_REG            (G2D_base+ 0x0400)
#define G2D_PAT_BG_COLOR_REG            (G2D_base+ 0x0404)
#define G2D_LINE_XY_SQRT_REG            (G2D_base+ 0x0404)
#define G2D_CLP_LT_REG                  (G2D_base+ 0x0408)
#define G2D_CLP_RB_REG                  (G2D_base+ 0x040C)
#define G2D_LINE_COPY_MASK_ADDR_REG     (G2D_base+ 0x0410)
#define G2D_ALPHA_GRADIENT_X_REG        (G2D_base+ 0x0410)
#define G2D_BEZIER_BUFFER_ADDR_REG      (G2D_base+ 0x0410)
#define G2D_TRIANGLE_SLOPE_R_REG        (G2D_base+ 0x0410)
#define G2D_RED_GRADIENT_X_REG          (G2D_base+ 0x0414)
#define G2D_BEZIER_SUBDIV_TIME_REG      (G2D_base+ 0x0414)
#define G2D_GREEN_GRADIENT_X_REG        (G2D_base+ 0x0418)
#define G2D_BLUE_GRADIENT_X_REG         (G2D_base+ 0x041C)
#define G2D_ALPHA_GRADIENT_Y_REG        (G2D_base+ 0x0420)
#define G2D_RED_GRADIENT_Y_REG          (G2D_base+ 0x0424)
#define G2D_GREEN_GRADIENT_Y_REG        (G2D_base+ 0x0428)
#define G2D_BLUE_GRADIENT_Y_REG         (G2D_base+ 0x042C)
#endif

#define REG_G2D_FIRE_CTRL               *((volatile unsigned int *)(G2D_base + 0x0100))
#define REG_G2D_SUBMODE_CTRL            *((volatile unsigned int *)(G2D_base + 0x0104))
#define REG_G2D_COMM_CTRL               *((volatile unsigned int *)(G2D_base + 0x0108))
#define REG_G2D_INT_CTRL                *((volatile unsigned int *)(G2D_base + 0x010C))
#define REG_G2D_STATUS                  *((volatile unsigned int *)(G2D_base + 0x0110))
#define REG_G2D_SRC_BASE_ADDRESS        *((volatile unsigned int *)(G2D_base + 0x0200))
#if defined(DRV_2D_ENGINE_V2)
#define REG_G2D_TRIANGLE_SLOPE_L        *((volatile unsigned int *)(G2D_base + 0x0200))
#endif
#define REG_G2D_SRC_PITCH               *((volatile unsigned int *)(G2D_base + 0x0204))
#define REG_G2D_SRC_XY                  *((volatile unsigned int *)(G2D_base + 0x0208))
#define REG_G2D_SRC_WIDTH_HEIGHT        *((volatile unsigned int *)(G2D_base + 0x020C))
#define REG_G2D_SRC_KEY_COLOR           *((volatile unsigned int *)(G2D_base + 0x0210))
#if defined(DRV_2D_ENGINE_V1)
#define REG_G2D_K1                      *((volatile unsigned int *)(G2D_base + 0x0210))
#define REG_G2D_SRC_ALPHA               *((volatile unsigned int *)(G2D_base + 0x0214))
#define REG_G2D_K2                      *((volatile unsigned int *)(G2D_base + 0x0214))
#define REG_G2D_PAT_FG_COLOR            *((volatile unsigned int *)(G2D_base + 0x0218))
#define REG_G2D_PAT_BG_COLOR            *((volatile unsigned int *)(G2D_base + 0x021C))
#define REG_G2D_DEST_ALPHA              *((volatile unsigned int *)(G2D_base + 0x021C))
#define REG_G2D_E                       *((volatile unsigned int *)(G2D_base + 0x021C))
#endif
#define REG_G2D_DEST_BASE_ADDRESS       *((volatile unsigned int *)(G2D_base + 0x0300))
#define REG_G2D_DEST_PITCH              *((volatile unsigned int *)(G2D_base + 0x0304))
#define REG_G2D_DEST_XY                 *((volatile unsigned int *)(G2D_base + 0x0308))
#define REG_G2D_XY_START                *((volatile unsigned int *)(G2D_base + 0x0308))
#define REG_G2D_XY_END                  *((volatile unsigned int *)(G2D_base + 0x030C))
#if defined(DRV_2D_ENGINE_V1)
#define REG_G2D_DEST_WIDTH_HEIGHT       *((volatile unsigned int *)(G2D_base + 0x030C))
#define REG_G2D_CLP_LT                  *((volatile unsigned int *)(G2D_base + 0x0500))
#define REG_G2D_CLP_RB                  *((volatile unsigned int *)(G2D_base + 0x0504))
#elif defined(DRV_2D_ENGINE_V2)
#define REG_G2D_CIRCLE_CENTER           *((volatile unsigned int *)(G2D_base + 0x0308))
#define REG_G2D_BEZIER_XY_START         *((volatile unsigned int *)(G2D_base + 0x0308))
#define REG_G2D_CIRCLE_RADIUS           *((volatile unsigned int *)(G2D_base + 0x030C))
#define REG_G2D_BEZIER_XY_MIDDLE        *((volatile unsigned int *)(G2D_base + 0x030C))
#define REG_G2D_TRIANGLE_Y_END          *((volatile unsigned int *)(G2D_base + 0x030C))
#define REG_G2D_BEZIER_XY_END           *((volatile unsigned int *)(G2D_base + 0x0310))
#define REG_G2D_LINE_DELTA_XY           *((volatile unsigned int *)(G2D_base + 0x0310))
#define REG_G2D_DEST_WIDTH_HEIGHT       *((volatile unsigned int *)(G2D_base + 0x0318))
#define REG_G2D_START_COLOR             *((volatile unsigned int *)(G2D_base + 0x0400))
#define REG_G2D_PAT_FG_COLOR            *((volatile unsigned int *)(G2D_base + 0x0400))
#define REG_G2D_PAT_BG_COLOR            *((volatile unsigned int *)(G2D_base + 0x0404))
#define REG_G2D_LINE_XY_SQRT            *((volatile unsigned int *)(G2D_base + 0x0404))
#define REG_G2D_CLP_LT                  *((volatile unsigned int *)(G2D_base + 0x0408))
#define REG_G2D_CLP_RB                  *((volatile unsigned int *)(G2D_base + 0x040C))
#define REG_G2D_LINE_COPY_MASK_ADDR     *((volatile unsigned int *)(G2D_base + 0x0410))
#define REG_G2D_ALPHA_GRADIENT_X        *((volatile unsigned int *)(G2D_base + 0x0410))
#define REG_G2D_BEZIER_BUFFER_ADDR      *((volatile unsigned int *)(G2D_base + 0x0410))
#define REG_G2D_TRIANGLE_SLOPE_R        *((volatile unsigned int *)(G2D_base + 0x0410))
#define REG_G2D_RED_GRADIENT_X          *((volatile unsigned int *)(G2D_base + 0x0414))
#define REG_G2D_BEZIER_SUBDIV_TIME      *((volatile unsigned int *)(G2D_base + 0x0414))
#define REG_G2D_GREEN_GRADIENT_X        *((volatile unsigned int *)(G2D_base + 0x0418))
#define REG_G2D_BLUE_GRADIENT_X         *((volatile unsigned int *)(G2D_base + 0x041C))
#define REG_G2D_ALPHA_GRADIENT_Y        *((volatile unsigned int *)(G2D_base + 0x0420))
#define REG_G2D_RED_GRADIENT_Y          *((volatile unsigned int *)(G2D_base + 0x0424))
#define REG_G2D_GREEN_GRADIENT_Y        *((volatile unsigned int *)(G2D_base + 0x0428))
#define REG_G2D_BLUE_GRADIENT_Y         *((volatile unsigned int *)(G2D_base + 0x042C))
#endif

#define G2D_TILT_SIZE_MASK              0x1F
#define G2D_TILT_BASE                   G2D_base+0x700
#if defined(DRV_2D_ENGINE_V1)
#define G2D_PALETTE_BASE                G2D_base+0x800
#endif

/* macro of graphic 2D engine tilt registers */
#if defined(DRV_2D_ENGINE_V1) && defined(__MTK_TARGET__)
#define GET_G2D_TILT(index)             *((volatile unsigned char *) (G2D_TILT_BASE+index))
#define SET_G2D_TILT(index,offset)      *((volatile unsigned char *) (G2D_TILT_BASE+index))=offset;
#endif

/* bit mapping of graphic 2D engine fire mode control register */
#define REG_FIRE_CTRL_SOURCE_COLOR_MODE_MASK    0x0E00
#define REG_FIRE_CTRL_DEST_COLOR_MODE_MASK      0x00E0
#define REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK    0x000F

#if defined(DRV_2D_ENGINE_V1) && defined(__MTK_TARGET__)
#define FIRE_SRC_COLOR_16BPP_LUT_DIS            0x0000
#define FIRE_SRC_COLOR_8BPP_LUT_DIS             0x0800
#define FIRE_SRC_COLOR_8BPP_LUT_EN              0x0C00

#define FIRE_DEST_COLOR_16BPP_LUT_DIS           0x0000
#define FIRE_DEST_COLOR_16BPP_LUT_EN            0x0040
#define FIRE_DEST_COLOR_8BPP_LUT_DIS            0x0080

#define FIRE_G2D_RECTANGLE_FILL                 0x0001
#define FIRE_G2D_RECTANGLE_PATTERN_FILL         0x0003
#define FIRE_G2D_BITBLT                         0x0004
#define FIRE_G2D_ALPHA_BLENDING                 0x0008
#define FIRE_G2D_FONT_CACHING                   0x000A
#define FIRE_G2D_LINE_DRAWING                   0x000B
#endif

#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define FIRE_SRC_COLOR_8BPP_LUT_DIS             0x0000
#define FIRE_SRC_COLOR_16BPP_RGB565             0x0200
#define FIRE_SRC_COLOR_32BPP_ARGB8888           0x0400
#define FIRE_SRC_COLOR_24BPP_RGB888             0x0600
#define FIRE_SRC_COLOR_16BPP_ARGB4444           0x0A00

#define FIRE_DEST_COLOR_8BPP_LUT_DIS            0x0000
#define FIRE_DEST_COLOR_16BPP_RGB565            0x0020
#define FIRE_DEST_COLOR_32BPP_ARGB8888          0x0040
#define FIRE_DEST_COLOR_24BPP_RGB888            0x0060
#define FIRE_DEST_COLOR_16BPP_ARGB4444          0x00A0

#define FIRE_G2D_LINE_DRAWING                   0x0000
#define FIRE_G2D_CIRCLE_DRAWING                 0x0001
#define FIRE_G2D_BEZIER_CURVE_DRAWIGN           0x0002
#define FIRE_G2D_TRIANGLE_FILL                  0x0003
#define FIRE_G2D_RECTANGLE_FILL                 0x0008
#define FIRE_G2D_BITBLT                         0x0009
#define FIRE_G2D_ALPHA_BLENDING                 0x000A
#define FIRE_G2D_ROP_BITBLT                     0x000B
#define FIRE_G2D_FONT_CACHING                   0x000C
#define FIRE_G2D_H_LINE_FILL_COLOR_GRAD         0x000D
#define FIRE_G2D_H_LINE_COPY_MASK               0x000E

#define G2D_SRC_8BPP_MODE                       0
#define G2D_SRC_16BPP_RGB565_MODE               1
#define G2D_SRC_32BPP_MODE                      2
#define G2D_SRC_24BPP_MODE                      3
#define G2D_SRC_16BPP_ARGB4444_MODE             5

#define G2D_DEST_8BPP_MODE                      0
#define G2D_DEST_16BPP_RGB565_MODE              1
#define G2D_DEST_32BPP_MODE                     2
#define G2D_DEST_24BPP_MODE                     3
#define G2D_DEST_16BPP_ARGB4444_MODE            5
#endif

/* bit mapping of graphic 2D engine status register */
#define REG_G2D_ENGINE_STATUS_BUSY_BIT          0x0001

#define BITBLT_TRANSFORM_MIRROR_ROTATE_90       0x00
#define BITBLT_TRANSFORM_ROTATE_90              0x01
#define BITBLT_TRANSFORM_ROTATE_270             0x02
#define BITBLT_TRANSFORM_MIRROR_ROTATE_270      0x03
#define BITBLT_TRANSFORM_ROTATE_180             0x04
#define BITBLT_TRANSFORM_MIRROR                 0x05
#define BITBLT_TRANSFORM_MIRROR_ROTATE_180      0x06
#define BITBLT_TRANSFORM_COPY                   0x07

#define G2D_CLIP_DISABLE                        0
#define G2D_CLIP_ENABLE                         1
#define G2D_SRC_KEY_DISABLE                     0
#define G2D_SRC_KEY_ENABLE                      1
#define D2D_SRC_KEY_ENABLE                      G2D_SRC_KEY_ENABLE
#define G2D_LINE_LINE_MODE                      0
#define G2D_LINE_DOTTED_MODE                    1
#define G2D_FONT_BACKGROUND_DISABLE             0
#define G2D_FONT_BACKGROUND_ENABLE              1
#define G2D_FONT_ITALIC_DISABLE                 0
#define G2D_FONT_ITALIC_ENABLE                  1

#if defined(DRV_2D_ENGINE_V1)
#define G2D_DEST_16BPP_LUT_DISABLE              0
#define G2D_DEST_16BPP_LUT_ENABLE               1
#define G2D_DEST_8BPP_LUT_DISABLE               2
#define G2D_SRC_16BPP_LUT_DISABLE               0
#define G2D_SRC_8BPP_LUT_DISABLE                1
#define G2D_SRC_8BPP_LUT_ENABLE                 2
#endif

/* bit mapping of 2D engine submode control register or software G2D function flag*/
#if defined(DRV_2D_ENGINE_V1)
    #define REG_SUBMODE_CTRL_ITALIC_FONT_BIT            0x8000
    #define REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT        0x4000
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    #define REG_SUBMODE_CTRL_ITALIC_FONT_BIT            0x80000000
    #define REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT        0x40000000
#endif

#if defined(DRV_2D_ENGINE_V1)
    #define REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK      0x0007
    #define REG_SUBMODE_CTRL_DOTTED_LINE_BIT            0x0800
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    #define REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK      0x00000007
    #define REG_SUBMODE_CTRL_DOTTED_LINE_BIT            0x00000800
#endif

#if defined(DRV_2D_ENGINE_V1)
#define REG_SUBMODE_CTRL_XY_MAJOR_BIT               0x0400
#define REG_SUBMODE_CTRL_X_INC_DEC_BIT              0x0200
#define REG_SUBMODE_CTRL_Y_INC_DEC_BIT              0x0100
#define REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT     0x0008
#endif

#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define REG_SUBMODE_CTRL_FONT_ORDER_BIT             0x20000000
#define REG_SUBMODE_CTRL_ALPHA_MASK                 0x00FF0000
#define REG_SUBMODE_CTRL_ROP_CODE_MASK              0x000F0000
#define REG_SUBMODE_CTRL_START_BIT_MASK             0x00070000
#define REG_SUBMODE_CTRL_ENABLE_ARCS_MASK           0x000F0000
#define REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT        0x00000100
#define REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT         0x00000040
#define REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK      0x00000030
#define REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT          0x00000008

#define BITBLT_TRANSFORM_DIRECTION_RB_CORNER        0x00000000      /* right buttom */
#define BITBLT_TRANSFORM_DIRECTION_LB_CORNER        0x00000010      /* left buttom */
#define BITBLT_TRANSFORM_DIRECTION_RT_CORNER        0x00000020      /* right top */
#define BITBLT_TRANSFORM_DIRECTION_LT_CORNER        0x00000030      /* left top */

#define G2D_REC_FILL_ITALIC_DISABLE             0       /* rectangle fill italic */
#define G2D_REC_FILL_ITALIC_ENABLE              1
#define G2D_FONT_ORDER_LSB_FIRST                0
#define G2D_FONT_ORDER_MSB_FIRST                1
#define G2D_BITBLT_ITALIC_DISABLE               0       /* bitlbt italic */
#define G2D_BITBLT_ITALIC_ENABLE                1
#define G2D_LINE_ANTI_ALIAS_DISABLE             0       /* line drawing anti-aliasing */
#define G2D_LINE_ANTI_ALIAS_ENABLE              1
#define G2D_REC_FILL_COLOR_GRAD_DISABLE         0       /* color gradient when rectangle fill */
#define G2D_REC_FILL_COLOR_GRAD_ENABLE          1
#define G2D_BITBLT_DEST_SRC_KEY_DISABLE         0
#define G2D_BITBLT_DEST_SRC_KEY_ENABLE          1

#define G2D_ROP_ALL_ZERO                        0x00
#define G2D_ROP_INV_AFTER_SRC_OR_DEST           0x01        /* ~(S|D) */
#define G2D_ROP_INV_SRC_AND_DEST                0x02        /* ~S & D */
#define G2D_ROP_INV_SRC                         0x03        /* ~S */
#define G2D_ROP_SRC_AND_INV_DEST                0x04        /* S & ~D */
#define G2D_ROP_INV_DEST                        0x05        /* ~D */
#define G2D_ROP_SRC_XOR_DEST                    0x06        /* S ^ D */
#define G2D_ROP_INV_AFTER_SRC_AND_DEST          0x07        /* ~(S & D) */
#define G2D_ROP_SRC_AND_DEST                    0x08        /* S & D */
#define G2D_ROP_INV_AFTER_SRC_XOR_DEST          0x09        /* ~(S ^ D) */
#define G2D_ROP_DEST                            0x0A        /* D */
#define G2D_ROP_INV_SRC_OR_DEST                 0x0B        /* ~S | D */
#define G2D_ROP_SRC                             0x0C        /* S */
#define G2D_ROP_SRC_OR_INV_DEST                 0x0D        /* S | ~D */
#define G2D_ROP_SRC_OR_DEST                     0x0E        /* S | D */
#define G2D_ROP_ALL_ONE                         0x0F

#define G2D_FONT_START_BIT_0                    0x00
#define G2D_FONT_START_BIT_1                    0x01
#define G2D_FONT_START_BIT_2                    0x02
#define G2D_FONT_START_BIT_3                    0x03
#define G2D_FONT_START_BIT_4                    0x04
#define G2D_FONT_START_BIT_5                    0x05
#define G2D_FONT_START_BIT_6                    0x06
#define G2D_FONT_START_BIT_7                    0x07

#define G2D_CIRCLE_ARC_1                        0x01
#define G2D_CIRCLE_ARC_2                        0x02
#define G2D_CIRCLE_ARC_1_2                      0x03
#define G2D_CIRCLE_ARC_3                        0x04
#define G2D_CIRCLE_ARC_1_3                      0x05
#define G2D_CIRCLE_ARC_2_3                      0x06
#define G2D_CIRCLE_ARC_1_2_3                    0x07
#define G2D_CIRCLE_ARC_4                        0x08
#define G2D_CIRCLE_ARC_1_4                      0x09
#define G2D_CIRCLE_ARC_2_4                      0x0A
#define G2D_CIRCLE_ARC_1_2_4                    0x0B
#define G2D_CIRCLE_ARC_3_4                      0x0C
#define G2D_CIRCLE_ARC_1_3_4                    0x0D
#define G2D_CIRCLE_ARC_2_3_4                    0x0E
#define G2D_CIRCLE_ARC_1_2_3_4                  0x0F
#endif

/* bit mapping of 2D engine common control register */
#define REG_COMMON_CTRL_G2D_ENGINE_RESET_BIT        0x0001
#if defined(DRV_2D_ENGINE_V1)
#define REG_COMMON_CTRL_G2D_PALETTE_ENABLE_BIT      0x0002
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT      0x0002
#endif
#define REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT         0x0004

/* macros of 2D engine fire mode control register */
#if defined(DRV_2D_ENGINE_V1)
#define SET_G2D_SRC_16BPP_LUT_DIS      REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_SOURCE_COLOR_MODE_MASK;\
                                       REG_G2D_FIRE_CTRL |= FIRE_SRC_COLOR_16BPP_LUT_DIS;
#define SET_G2D_SRC_8BPP_LUT_DIS       REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_SOURCE_COLOR_MODE_MASK;\
                                       REG_G2D_FIRE_CTRL |= FIRE_SRC_COLOR_8BPP_LUT_DIS;
#define SET_G2D_SRC_8BPP_LUT_EN        REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_SOURCE_COLOR_MODE_MASK;\
                                       REG_G2D_FIRE_CTRL |= FIRE_SRC_COLOR_8BPP_LUT_EN;

#define SET_G2D_DEST_16BPP_LUT_DIS     REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_DEST_COLOR_MODE_MASK;\
                                       REG_G2D_FIRE_CTRL |= FIRE_DEST_COLOR_16BPP_LUT_DIS;
#define SET_G2D_DEST_16BPP_LUT_EN      REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_DEST_COLOR_MODE_MASK;\
                                       REG_G2D_FIRE_CTRL |= FIRE_DEST_COLOR_16BPP_LUT_EN;
#define SET_G2D_DEST_8BPP_LUT_DIS      REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_DEST_COLOR_MODE_MASK;\
                                       REG_G2D_FIRE_CTRL |= FIRE_DEST_COLOR_8BPP_LUT_DIS;

#define SET_G2D_RECTANGLE_FILL_DEST_16BPP_LUT_DISABLE           REG_G2D_FIRE_CTRL = FIRE_G2D_RECTANGLE_FILL ;
#define SET_G2D_RECTANGLE_FILL_DEST_8BPP_LUT_DISABLE            REG_G2D_FIRE_CTRL = (FIRE_G2D_RECTANGLE_FILL | FIRE_DEST_COLOR_8BPP_LUT_DIS);
#define SET_G2D_RECTANGLE_PATTERN_FILL_DEST_16BPP_LUT_DISABLE   REG_G2D_FIRE_CTRL = FIRE_G2D_RECTANGLE_PATTERN_FILL;
#define SET_G2D_RECTANGLE_PATTERN_FILL_DEST_8BPP_LUT_DISABLE    REG_G2D_FIRE_CTRL = (FIRE_G2D_RECTANGLE_PATTERN_FILL|FIRE_DEST_COLOR_8BPP_LUT_DIS);
#define SET_G2D_FONT_CACHING_DEST_16BPP_LUT_DISABLE             REG_G2D_FIRE_CTRL = FIRE_G2D_FONT_CACHING;
#define SET_G2D_FONT_CACHING_DEST_8BPP_LUT_DISABLE              REG_G2D_FIRE_CTRL = (FIRE_G2D_FONT_CACHING|FIRE_DEST_COLOR_8BPP_LUT_DIS);
#define SET_G2D_LINE_DRAWING_DEST_16BPP_LUT_DISABLE             REG_G2D_FIRE_CTRL = FIRE_G2D_LINE_DRAWING;
#define SET_G2D_LINE_DRAWING_DEST_8BPP_LUT_DISABLE              REG_G2D_FIRE_CTRL = (FIRE_G2D_LINE_DRAWING|FIRE_DEST_COLOR_8BPP_LUT_DIS);

#define SET_G2D_BITBLT_16BPP_LUT_DISABLE        REG_G2D_FIRE_CTRL = FIRE_G2D_BITBLT;
#define SET_G2D_BITBLT_8BPP_LUT_DISABLE         REG_G2D_FIRE_CTRL = (FIRE_G2D_BITBLT | FIRE_SRC_COLOR_8BPP_LUT_DIS | FIRE_DEST_COLOR_8BPP_LUT_DIS);
#define SET_G2D_BITBLT_DEST_16BPP_LUT_ENABLE    REG_G2D_FIRE_CTRL = (FIRE_G2D_BITBLT | FIRE_SRC_COLOR_8BPP_LUT_DIS | FIRE_DEST_COLOR_16BPP_LUT_EN);

#define SET_G2D_ALPHA_BLENDING_SRC_16BPP_LUT_DISABLE        REG_G2D_FIRE_CTRL = FIRE_G2D_ALPHA_BLENDING;
#define SET_G2D_ALPHA_BLENDING_SRC_8BPP_LUT_ENABLE          REG_G2D_FIRE_CTRL = (FIRE_G2D_ALPHA_BLENDING|FIRE_SRC_COLOR_8BPP_LUT_EN) ;
#endif

#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    #define SET_G2D_SRC_COLOR_MODE(color_mode)      REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_SOURCE_COLOR_MODE_MASK;\
                                                    REG_G2D_FIRE_CTRL |= color_mode;
    #define SET_G2D_DEST_COLOR_MODE(color_mode)     REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_DEST_COLOR_MODE_MASK;\
                                                    REG_G2D_FIRE_CTRL |= color_mode;
    #define SET_G2D_FIRE_MODE(fire_mode)            REG_G2D_FIRE_CTRL &= ~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;\
                                                    REG_G2D_FIRE_CTRL |= fire_mode;
#endif

/* macros of G2D engine submode control register */
#define ENABLE_BITBLT_ITALIC_FONT           REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_ITALIC_FONT_BIT;
#define DISABLE_BITBLT_ITALIC_FONT          REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_ITALIC_FONT_BIT;
#define ENABLE_BITBLT_DOTTED_LINE           REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
#define DISABLE_BITBLT_DOTTED_LINE          REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
#define SET_BITBLT_TRANSFORM_MODE(n)        REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;\
                                            REG_G2D_SUBMODE_CTRL |= n;
#if defined(DRV_2D_ENGINE_V1)
    #define ENABLE_BITBLT_FONT_BACKGROUND       REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
    #define DISABLE_BITBLT_FONT_BACKGROUND      REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
    #define SET_BITBLT_Y_MAJOR                  REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_XY_MAJOR_BIT;
    #define SET_BITBLT_X_MAJOR                  REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_XY_MAJOR_BIT;
    #define SET_BITBLT_X_INCREAMENT             REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_X_INC_DEC_BIT;
    #define SET_BITBLT_X_DECREAMENT             REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_X_INC_DEC_BIT;
    #define SET_BITBLT_Y_INCREAMENT             REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_Y_INC_DEC_BIT;
    #define SET_BITBLT_Y_DECREAMENT             REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_Y_INC_DEC_BIT;
    #define ENABLE_BITBLT_TRANSPARENT           REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT;
    #define DISABLE_BITBLT_TRANSPARENT          REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT;
	#define IS_BITBLT_SRC_KEY_ENABLE                (REG_G2D_SUBMODE_CTRL & REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT)
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    #define ENABLE_BITBLT_FONT_BACKGROUND       REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
    #define DISABLE_BITBLT_FONT_BACKGROUND      REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
    #define SET_G2D_FONT_LSB_FIRST              REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_FONT_ORDER_BIT;
    #define SET_G2D_FONT_MSB_FIRST              REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_FONT_ORDER_BIT;
    #define SET_BITBLT_ALPHA_VALUE(alpha)       REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_ALPHA_MASK;\
                                                REG_G2D_SUBMODE_CTRL |= (alpha<<16);
    #define SET_BITBLT_ROP_MODE(rop)            REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_ROP_CODE_MASK;\
                                                REG_G2D_SUBMODE_CTRL |= rop;
    #define SET_FONT_START_BIT(bit)             REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_START_BIT_MASK;\
                                                REG_G2D_SUBMODE_CTRL |= (bit<<16);
    #define SET_CIRCLE_ENABLE_ARC(arc)          REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_ENABLE_ARCS_MASK;\
                                                REG_G2D_SUBMODE_CTRL |= arc;
    #define ENABLE_LINE_ANTI_ALIASING           REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;
    #define DISABLE_LINE_ANTI_ALIASING          REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;
    #define ENABLE_REC_FILL_COLOR_GRADIENT      REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT;
    #define DISABLE_REC_FILL_COLOR_GRADIENT     REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT;
    #define SET_BITBLT_DIRECTION(direction)     REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK;\
                                                REG_G2D_SUBMODE_CTRL |= direction;
    #define ENABLE_G2D_BITBLT_ITALIC_MODE       REG_G2D_SUBMODE_CTRL |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
    #define DISABLE_G2D_BITBLT_ITALIC_MODE      REG_G2D_SUBMODE_CTRL &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
    #define IS_BITBLT_SRC_KEY_ENABLE            (REG_G2D_COMM_CTRL & REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT)
#endif
/* macros of 2D engine status register */
#define G2D_ENGINE_IS_BUSY      (REG_G2D_STATUS & REG_G2D_ENGINE_STATUS_BUSY_BIT)

/* macros of 2D engine common control register */
#define RESET_G2D_ENGINE            (REG_G2D_COMM_CTRL |= REG_COMMON_CTRL_G2D_ENGINE_RESET_BIT);\
                                    (REG_G2D_COMM_CTRL &= ~REG_COMMON_CTRL_G2D_ENGINE_RESET_BIT);
#define ENABLE_G2D_ENGINE_CLIP      (REG_G2D_COMM_CTRL |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT);
#define DISABLE_G2D_ENGINE_CLIP     (REG_G2D_COMM_CTRL &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT);

#if defined(DRV_2D_ENGINE_V1)
    #define ENABLE_G2D_ENGINE_PALETTE   (REG_G2D_COMM_CTRL |= REG_COMMON_CTRL_G2D_PALETTE_ENABLE_BIT);
    #define DISABLE_G2D_ENGINE_PALETTE  (REG_G2D_COMM_CTRL &= ~REG_COMMON_CTRL_G2D_PALETTE_ENABLE_BIT);
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    #define ENABLE_G2D_ENGINE_SRC_KEY   (REG_G2D_COMM_CTRL |= REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT);
    #define DISABLE_G2D_ENGINE_SRC_KEY  (REG_G2D_COMM_CTRL &= ~REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT);
#endif

#define ENABLE_G2D_ENGINE_INT       REG_G2D_INT_CTRL = 1;
#define DISABLE_G2D_ENGINE_INT      REG_G2D_INT_CTRL = 0;

/* macro of graphic 2D engine tilt registers */
#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define GET_G2D_TILT(index) (((*((volatile unsigned int *) (G2D_TILT_BASE+(index&0xFC))))&((0xFF<<((index&0x03)<<3))))>>((index&0x03)<<3));
#define SET_G2D_TILT(index,offset)      \
{\
    kal_uint32 data;\
    kal_uint8 shift;\
    data=*((volatile unsigned int *)(G2D_TILT_BASE+(index&0xFC)));\
    shift=(index&0x03)<<3;\
    *((volatile unsigned int *) (G2D_TILT_BASE+(index&0xFC)))=(data&(~(0xFF<<shift)))|(offset<<shift);\
}
#endif

/* macro of graphic 2D engine color palette registers */
#if defined(DRV_2D_ENGINE_V1)
#define SET_G2D_PALETTE_COLOR(index,color)  *((volatile unsigned int *) (G2D_PALETTE_BASE+(index<<2))) = color;
#endif

#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define G2D_CMQ_LENGTH          512
#endif

#define G2D_CMQ_CTRL_REG        (GCMQ_base + 0x0000)
#define G2D_CMQ_STATUS_REG      (GCMQ_base + 0x0004)
#define G2D_CMQ_DATA_REG        (GCMQ_base + 0x0008)

#define REG_G2D_CMQ_CTRL        *((volatile unsigned int *)(GCMQ_base + 0x0000))
#define REG_G2D_CMQ_STATUS      *((volatile unsigned int *)(GCMQ_base + 0x0004))
#define REG_G2D_CMQ_DATA        *((volatile unsigned int *)(GCMQ_base + 0x0008))

#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define G2D_CMQ_QUEUE_BASE_ADDR_REG     (GCMQ_base + 0x000C)
#define G2D_CMQ_QUEUE_LENGTH_REG        (GCMQ_base + 0x0010)
#define REG_G2D_CMQ_QUEUE_BASE_ADDR     *((volatile unsigned int *)(GCMQ_base + 0x000C))
#define REG_G2D_CMQ_QUEUE_LENGTH        *((volatile unsigned int *)(GCMQ_base + 0x0010))
#endif

#define ENABLE_G2D_CMQ          REG_G2D_CMQ_CTRL=1;
#define DISABLE_G2D_CMQ         REG_G2D_CMQ_CTRL &=0xFE;

#define G2D_CMQ_IS_ENABLE       (REG_G2D_CMQ_CTRL & 0x01)

#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define ENABLE_G2D_CMQ_WRITE    REG_G2D_CMQ_CTRL |= 0x02;
#define DISABLE_G2D_CMQ_WRITE   REG_G2D_CMQ_CTRL &= 0xFFFFFFFD;
#endif

#if defined(DRV_2D_ENGINE_V1)
#define G2D_CMQ_FREE_SPACE          REG_G2D_CMQ_STATUS
#define WRITE_G2D_CMQ(addr,data)    REG_G2D_CMQ_DATA = ((addr<<16)|data);
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
#define G2D_CMQ_FREE_SPACE          (REG_G2D_CMQ_STATUS & 0x7FF)
#define G2D_CMQ_IS_WRITABLE         ((REG_G2D_CMQ_STATUS & 0x8000)>>15)
#define G2D_WRITE_CMQ(data) while (!G2D_CMQ_IS_WRITABLE) {};\
                                        REG_G2D_CMQ_DATA=data;
#endif

#define G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR         0x01000000
#define G2D_CMQ_SUBMODE_CTRL_REG_ADDR           0x01040000
#define G2D_CMQ_2D_COMMON_CTRL_REG_ADDR         0x01080000
                                                
#define G2D_CMQ_2D_STATUS_REG_ADDR              0x01100000
                                                
#define G2D_CMQ_SRC_BASE_L_ADDR                 0x02000000
#define G2D_CMQ_SRC_BASE_H_ADDR                 0x02020000
#define G2D_CMQ_SRC_PITCH_ADDR                  0x02040000
                                                
#define G2D_CMQ_SRC_X_ADDR                      0x020A0000
#define G2D_CMQ_SRC_Y_ADDR                      0x02080000
#define G2D_CMQ_SRC_HEIGHT_ADDR                 0x020C0000
#define G2D_CMQ_SRC_WIDTH_ADDR                  0x020E0000

#if defined(DRV_2D_ENGINE_V1)
    #define G2D_CMQ_SRCKEY_COLOR_ADDR           0x02100000
    #define G2D_CMQ_K1_ADDR                     0x02100000
    #define G2D_CMQ_SRC_ALPHA_ADDR              0x02140000
    #define G2D_CMQ_K2_ADDR                     0x02140000
    #define G2D_CMQ_PAT_FG_COLOR_ADDR           0x02180000
    #define G2D_CMQ_DEST_ALPHA_ADDR             0x021C0000
    #define G2D_CMQ_E_ADDR                      0x021C0000
    #define G2D_CMQ_PAT_BG_COLOR_ADDR           0x021C0000
                                                
    #define G2D_CMQ_DEST_BASE_L_ADDR            0x03000000
    #define G2D_CMQ_DEST_BASE_H_ADDR            0x03020000
    #define G2D_CMQ_DEST_PITCH_ADDR             0x03040000
    #define G2D_CMQ_DEST_Y_ADDR                 0x03080000
    #define G2D_CMQ_DEST_X_ADDR                 0x030A0000
    #define G2D_CMQ_Y_START_ADDR                0x03080000
    #define G2D_CMQ_X_START_ADDR                0x030A0000
    #define G2D_CMQ_DEST_HEIGHT_ADDR            0x030C0000
    #define G2D_CMQ_DEST_WIDTH_ADDR             0x030E0000
    #define G2D_CMQ_Y_END_ADDR                  0x030C0000
    #define G2D_CMQ_X_END_ADDR                  0x030E0000
                                                
    #define G2D_CMQ_CLIP_TOP_Y_ADDR             0x05000000
    #define G2D_CMQ_CLIP_LEFT_X_ADDR            0x05020000
    #define G2D_CMQ_CLIP_BOTTOM_Y_ADDR          0x05040000
    #define G2D_CMQ_CLIP_RIGHT_X_ADDR           0x05060000
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    #define G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR     0x01040000
    #define G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR     0x01060000
    #define G2D_CMQ_TRIANGLE_SLOPE_L_L_ADDR     0x02000000
    #define G2D_CMQ_TRIANGLE_SLOPE_L_H_ADDR     0x02020000
    #define G2D_CMQ_SRCKEY_COLOR_L_ADDR         0x02100000
    #define G2D_CMQ_SRCKEY_COLOR_H_ADDR         0x02120000

    #define G2D_CMQ_DEST_BASE_L_ADDR            0x03000000
    #define G2D_CMQ_DEST_BASE_H_ADDR            0x03020000
    #define G2D_CMQ_DEST_PITCH_ADDR             0x03040000
    #define G2D_CMQ_DEST_Y_ADDR                 0x03080000
    #define G2D_CMQ_DEST_X_ADDR                 0x030A0000
    #define G2D_CMQ_Y_START_ADDR                0x03080000
    #define G2D_CMQ_X_START_ADDR                0x030A0000
    #define G2D_CMQ_CIRCLE_CENTER_Y_ADDR        0x03080000
    #define G2D_CMQ_CIRCLE_CENTER_X_ADDR        0x030A0000
    #define G2D_CMQ_BEZIER_START_Y_ADDR         0x03080000
    #define G2D_CMQ_BEZIER_START_X_ADDR         0x030A0000
    #define G2D_CMQ_Y_END_ADDR                  0x030C0000
    #define G2D_CMQ_X_END_ADDR                  0x030E0000
    #define G2D_CMQ_CIRCLE_RADIUS_ADDR          0x030C0000
    #define G2D_CMQ_BEZIER_MIDDLE_Y_ADDR        0x030C0000
    #define G2D_CMQ_BEZIER_MIDDLE_X_ADDR        0x030E0000
    #define G2D_CMQ_TRIANGLE_Y_END_ADDR         0x030C0000
    #define G2D_CMQ_BEZIER_END_Y_ADDR           0x03100000
    #define G2D_CMQ_BEZIER_END_X_ADDR           0x03120000
    #define G2D_CMQ_LINE_DELTA_Y_ADDR           0x03100000
    #define G2D_CMQ_LINE_DELTA_X_ADDR           0x03120000
    #define G2D_CMQ_DEST_HEIGHT_ADDR            0x03180000
    #define G2D_CMQ_DEST_WIDTH_ADDR             0x031A0000
    #define G2D_CMQ_PAT_FG_COLOR_L_ADDR         0x04000000
    #define G2D_CMQ_PAT_FG_COLOR_H_ADDR         0x04020000
    #define G2D_CMQ_GRAD_START_COLOR_L_ADDR     0x04000000
    #define G2D_CMQ_GRAD_START_COLOR_H_ADDR     0x04020000
    #define G2D_CMQ_PAT_BG_COLOR_L_ADDR         0x04040000
    #define G2D_CMQ_PAT_BG_COLOR_H_ADDR         0x04060000
    #define G2D_CMQ_XY_SQRT_L_ADDR              0x04040000
    #define G2D_CMQ_XY_SQRT_H_ADDR              0x04060000
    #define G2D_CMQ_CLIP_TOP_Y_ADDR             0x04080000
    #define G2D_CMQ_CLIP_LEFT_X_ADDR            0x040A0000
    #define G2D_CMQ_CLIP_BOTTOM_Y_ADDR          0x040C0000
    #define G2D_CMQ_CLIP_RIGHT_X_ADDR           0x040E0000
    #define G2D_CMQ_ALPHA_GRAD_X_L_ADDR         0x04100000
    #define G2D_CMQ_ALPHA_GRAD_X_H_ADDR         0x04120000
    #define G2D_CMQ_BEZIER_BUF_START_L_ADDR     0x04100000
    #define G2D_CMQ_BEZIER_BUF_START_H_ADDR     0x04120000
    #define G2D_CMQ_TRIANGLE_SLOPE_R_L_ADDR     0x04100000
    #define G2D_CMQ_TRIANGLE_SLOPE_R_H_ADDR     0x04120000
    #define G2D_CMQ_MASK_BASE_L_ADDR            0x04100000
    #define G2D_CMQ_MASK_BASE_H_ADDR            0x04120000
    #define G2D_CMQ_RED_GRAD_X_L_ADDR           0x04140000
    #define G2D_CMQ_RED_GRAD_X_H_ADDR           0x04160000
    #define G2D_CMQ_BEZIER_SUBDIV_TIME_ADDR     0x04140000
    #define G2D_CMQ_GREEN_GRAD_X_L_ADDR         0x04180000
    #define G2D_CMQ_GREEN_GRAD_X_H_ADDR         0x041A0000
    #define G2D_CMQ_BLUE_GRAD_X_L_ADDR          0x041C0000
    #define G2D_CMQ_BLUE_GRAD_X_H_ADDR          0x041E0000
    #define G2D_CMQ_ALPHA_GRAD_Y_L_ADDR         0x04200000
    #define G2D_CMQ_ALPHA_GRAD_Y_H_ADDR         0x04220000
    #define G2D_CMQ_RED_GRAD_Y_L_ADDR           0x04240000
    #define G2D_CMQ_RED_GRAD_Y_H_ADDR           0x04260000
    #define G2D_CMQ_GREEN_GRAD_Y_L_ADDR         0x04280000
    #define G2D_CMQ_GREEN_GRAD_Y_H_ADDR         0x042A0000
    #define G2D_CMQ_BLUE_GRAD_Y_L_ADDR          0x042C0000
    #define G2D_CMQ_BLUE_GRAD_Y_H_ADDR          0x042E0000
#endif

#if (defined(__MTK_TARGET__))
typedef enum
{
#if defined(DRV_2D_ENGINE_V1)
    G2D_OPERATION_NULL=0,
    G2D_OPERATION_RECTANGLE_FILL,
    G2D_OPERATION_BITBLT,
    G2D_OPERATION_ALPHA_BLENDING,
    G2D_OPERATION_LINE_DRAWING,
    G2D_OPERATION_FONT_CACHING,
    G2D_OPERATION_END
#elif defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    G2D_OPERATION_LINE_DRAWING=0,
    G2D_OPERATION_CIRCLE_DRWAING,
    G2D_OPERATION_BEZIER_CURVE_DRAWING,
    G2D_OPERATION_TRIANGLE_FILL,
    G2D_OPERATION_RECTANGLE_FILL=8,
    G2D_OPERATION_BITBLT,
    G2D_OPERATION_ALPHA_BLENDING,
    G2D_OPERATION_ROP_BITBLT,
    G2D_OPERATION_FONT_CACHING,
    G2D_OPERATION_H_LINE_FILL,
    G2D_OPERATION_H_LINE_COPY_MASK,
    G2D_OPERATION_END
#endif
}   g2d_operation_enum;
#else
typedef enum
{
    G2D_OPERATION_LINE_DRAWING=0,
    G2D_OPERATION_CIRCLE_DRWAING,
    G2D_OPERATION_BEZIER_CURVE_DRAWING,
    G2D_OPERATION_TRIANGLE_FILL,
    G2D_OPERATION_RECTANGLE_FILL=8,
    G2D_OPERATION_BITBLT,
    G2D_OPERATION_ALPHA_BLENDING,
    G2D_OPERATION_ROP_BITBLT,
    G2D_OPERATION_FONT_CACHING,
    G2D_OPERATION_H_LINE_FILL,
    G2D_OPERATION_H_LINE_COPY_MASK,
    G2D_OPERATION_END
}   g2d_operation_enum;
#endif

typedef struct
{
    g2d_operation_enum g2d_operation_mode;
    kal_uint32 src_base_address;
    kal_uint16 src_pitch;
    kal_uint16 src_pitch_width;
    kal_uint16 dest_pitch_width;
    short src_x;
    short src_y;
    short dest_x;
    short dest_y;
    kal_uint16 src_width;
    kal_uint16 src_height;
    kal_uint32 src_key_color;
    kal_uint16 src_alpha;
    kal_uint32 pat_fg_color;
    kal_uint32 pat_bg_color;
    kal_uint16 dest_alpha;
    kal_uint32 dest_base_address;
    kal_uint16 dest_pitch;
    kal_uint16 dest_width;
    kal_uint16 dest_height;
    short start_x;
    short start_y;
    short end_x;
    short end_y;
    kal_uint16 clip_start_x;
    kal_uint16 clip_start_y;
    kal_uint16 clip_end_x;
    kal_uint16 clip_end_y;
    kal_uint8 dotted_mode;
    kal_uint8 bitblt_mode;
    kal_uint8 font_background_mode;
    kal_uint8 italic_mode;
    kal_uint16 dest_color_mode;
    kal_uint16 src_color_mode;
    kal_uint8 src_key_mode;
    kal_uint8 clip_mode;
#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
    kal_bool g2d_cmq_mode;
    kal_uint8 rop_mode;
    kal_uint8 line_anti_alias_mode;
    kal_uint8 color_gradient_mode;
    kal_uint8 circle_drawing_arc;
    kal_uint8 bezier_curve_divide_time;
    kal_uint8 font_start_position;
    kal_uint8 font_order;
    kal_uint16 circle_radius;
    kal_uint32 triangle_left_slope;
    kal_uint32 triangle_right_slope;
    short middle_x;
    short middle_y;
    double alpha_gradient_x;
    double alpha_gradient_y;
    double red_gradient_x;
    double red_gradient_y;
    double green_gradient_x;
    double green_gradient_y;
    double blue_gradient_x;
    double blue_gradient_y;
    kal_uint32 buffer_address;
    kal_uint16 buffer_size;
#endif
} g2d_parameter_struct;

typedef struct
{
    kal_uint32 base_address;
    short x;
    short y;
    kal_uint16 pitch;
    kal_uint16 width;
    kal_uint16 height;
    kal_uint16 color_mode;
    kal_uint16 clip_x1;
    kal_uint16 clip_x2;
    kal_uint16 clip_y1;
    kal_uint16 clip_y2;
} g2d_buffer_struct;

typedef struct
{
    kal_bool tilt_mode;
    kal_bool bold_mode;
    kal_bool border_mode;
    kal_bool enable_bg_color;
    kal_uint32 fg_color;
    kal_uint32 bg_color;
}   g2d_font_attribute_struct;

typedef struct 
{
    kal_uint32 font_address;
    kal_uint32 bit_offset;
    kal_uint16 font_width;
    kal_uint16 font_height;
    short start_x;
    short start_y;
}   g2d_font_struct;

typedef struct
{
    kal_bool    tilt_mode;
    kal_bool    src_key_mode;
    kal_uint8   blt_direction;
    kal_uint32  src_key_color;
    kal_bool    alpha_blending_mode;
    kal_uint8   alpha_value;
    kal_bool    rop_mode;
    kal_uint8   rop_value;
    kal_uint8   transform_value;
    g2d_buffer_struct *src_list;
    kal_uint16  list_count;
}   g2d_bitblt_struct;

typedef struct
{
    short circle_center_x;
    short circle_center_y;
    kal_uint16 circle_radius;
    kal_uint16 start_angle;
    kal_uint16 end_angle;
    kal_uint32 circle_color;
}   g2d_circle_struct;

typedef struct 
{
    short start_x;
    short start_y;
    short middle_x;
    short middle_y;
    short end_x;
    short end_y;
    kal_uint32 line_color;
}   g2d_bezier_curve_struct;

typedef struct 
{
    short *line_end_coordinate;
    kal_uint16 line_count;
    kal_bool antialias_mode;
    kal_bool dotted_mode;
    kal_uint32 line_color;
}   g2d_line_struct;

typedef struct
{
    short *point_coordinate;
    kal_uint16 polygon_number;
    kal_bool antialias_mode;
    kal_bool dotted_mode;
    kal_uint32 line_color;
}   g2d_polygon_struct;

typedef struct
{
    short first_x;
    short first_y;
    short second_x;
    short second_y;
    short middle_y;
    int slope1;
    int slope2;
    int slope3;
    int slope4;
    kal_bool two_triangle;      /* KAL_TRUE: draw two triangle, KAL_FALSE: draw one triangle */
}   g2d_triangle_para_struct;

typedef struct
{
    short *point_coordinate;
    kal_uint16 point_number;
    kal_uint32 fill_color;
}   g2d_polygon_fill_struct;

typedef struct
{
    short start_x;
    short start_y;
    kal_uint16 width;
    kal_uint16 height;
    kal_uint32 delta_gradient[8];
    kal_uint32 fill_color;
    kal_bool gradient_fill_mode;        /* 1: gradient rectangle fill */
    kal_bool tilt_mode;
}   g2d_rectangle_fill_struct;

typedef struct
{
    short *line_start_coordinate;               /* line_number *2 */
    kal_uint16 *line_width;             /* line_number */
    kal_uint16 line_number;
    kal_int32 *delta_gardient;          /* line_number *4 */
    kal_uint32 line_color;
}   g2d_gradient_line_struct;

typedef struct
{
    g2d_buffer_struct *src;
    kal_uint32 *mask_address;
    kal_uint32 mask_length;
    short *line_start_coordinate;
    kal_uint16 *line_width;
    kal_uint16 line_number;
}   g2d_line_copy_struct;

/* function declare in 2D_engine.c */

typedef enum
{
    G2D_OWNER_NONE=0,
    G2D_OWNER_GDI,
    G2D_OWNER_LCD,
    G2D_OWNER_ALL
}   g2d_owner_enum;

void g2d_LISR(void);
void g2d_HISR(void);
void g2d_init(void);
void g2d_deinit(void);
void g2d_set_tilt_data(kal_uint8 index, kal_uint8 tilt_value);
void g2d_set_color_palette(kal_uint8 index, kal_uint32 color);
void g2d_multi_bitblt(g2d_parameter_struct *g2d_data);
void g2d_accelerator(g2d_parameter_struct *g2d_data);
void g2d_set_clip_window(g2d_parameter_struct *g2d_data);
void g2d_alpha_bitblt(g2d_parameter_struct *g2d_data);
void g2d_line_drawing(g2d_parameter_struct *g2d_data);
void g2d_font_caching(g2d_parameter_struct *g2d_data);
void g2d_rectangle_fill(g2d_parameter_struct *g2d_data);
void g2d_bitblt(g2d_parameter_struct *g2d_data);

void g2d_sw_font_caching(g2d_parameter_struct *g2d_data);
void g2d_font_begin(kal_uint32 dest_address,kal_uint16 dest_pitch,kal_bool is_italic,
                        int clipx1,int clipy1,
                        int clipx2,int clipy2);
void g2d_font_end(void);
void g2d_font_draw(kal_uint32 font_address, int width,int height,int x,int y);
void g2d_font_color(kal_uint32 fg_color);
void g2d_rectangle_fill_without_clip(kal_uint32 dest_address,kal_uint32 dest_pitch,int x,int y,kal_uint32 width_height,kal_uint32 color);

void g2d_get_triangle_slope(short start_x, short start_y, short middle_x, short middle_y,
                                     short end_x, short end_y,g2d_triangle_para_struct *g2d_tri_data);
#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
void g2d_triangle_fill(g2d_parameter_struct *g2d_data);
void g2d_rop_bitblt(g2d_parameter_struct *g2d_data);
void g2d_circle_drawing(g2d_parameter_struct *g2d_data);
void g2d_bezier_curve_drawing(g2d_parameter_struct *g2d_data);
void g2d_line_gradient_drawing(g2d_parameter_struct *g2d_data);
void g2d_line_copy_drawing(g2d_parameter_struct *g2d_data);
#endif

kal_bool g2d_begin(kal_uint8 g2d_owner_id, void (*g2d_cb)());
void g2d_end(kal_uint8 g2d_owner_id);
void g2d_set_dest_buffer(kal_uint8 g2d_owner_id, g2d_buffer_struct *dest);
void g2d_font_set_attribute(kal_uint8 g2d_owner_id, g2d_font_attribute_struct *g2d_font_attr);
void g2d_draw_font(kal_uint8 g2d_owner_id, g2d_font_struct *g2d_font_data);
void g2d_bitblt1(kal_uint8 g2d_owner_id, g2d_bitblt_struct *g2d_bitblt_data);
void g2d_draw_arc(kal_uint8 g2d_owner_id, g2d_circle_struct *g2d_circle_data);
void g2d_draw_bezier_curve(kal_uint8 g2d_owner_id, g2d_bezier_curve_struct *g2d_bezier_data);
void g2d_draw_line(kal_uint8 g2d_owner_id, g2d_line_struct *g2d_line_data);
void g2d_draw_polygon(kal_uint8 g2d_owner_id, g2d_polygon_struct *g2d_polygon_data);
void g2d_fill_polygon(kal_uint8 g2d_owner_id, g2d_polygon_fill_struct *g2d_fill_polygon_data);
void g2d_fill_rectangle(kal_uint8 g2d_owner_id, g2d_rectangle_fill_struct *g2d_rec_fill_data);
void g2d_draw_gradient_h_line(kal_uint8 g2d_owner_id, g2d_gradient_line_struct *g2d_h_line_data);
void g2d_copy_h_line(kal_uint8 g2d_owner_id, g2d_line_copy_struct *g2d_copy_h_line_data);

#ifndef __MTK_TARGET__
void g2d_sw_bitblt_operation(g2d_parameter_struct *g2d_data);
void g2d_sw_circle_drawing(g2d_parameter_struct *g2d_data);
void g2d_sw_line_drawing(g2d_parameter_struct *g2d_data);
void g2d_sw_bezier_curve_drawing(g2d_parameter_struct *g2d_data);
void g2d_sw_triangle_fill(g2d_parameter_struct *g2d_data);
void g2d_sw_rectangle_fill(g2d_parameter_struct *g2d_data);
void g2d_sw_hline_copy(g2d_parameter_struct *g2d_data);
void g2d_sw_hline_gradient(g2d_parameter_struct *g2d_data);
#endif
#endif
#endif /* _G2DENGINE_H */


