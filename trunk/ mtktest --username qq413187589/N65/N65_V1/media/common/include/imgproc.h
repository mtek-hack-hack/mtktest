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
 *    imgproc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of image processor
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef IMGPROC_H
#define IMGPROC_H

#include "scn_comm.h"
#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "imgproc_6238_series.h"

#else


#if (defined(DRV_IDP_6219_SERIES)||defined(DRV_IDP_6228_SERIES))
#include "reg_base.h"
#define IMGPROC_BASE                (IMGPROC_base)

#define IMGPROC_IMAGE_CON           IMGPROC_BASE+0x0
#define IMGPROC_CON                 IMGPROC_BASE+0x4
#define IMGPROC_INTREN              IMGPROC_BASE+0x8
#define IMGPROC_INTR                IMGPROC_BASE+0xC
#define IMGPROC_HUE11               IMGPROC_BASE+0x100
#define IMGPROC_HUE12               IMGPROC_BASE+0x104
#define IMGPROC_HUE21               IMGPROC_BASE+0x108
#define IMGPROC_HUE22               IMGPROC_BASE+0x10c
#define IMGPROC_SAT                 IMGPROC_BASE+0x110
#define IMGPROC_BRIADJ1             IMGPROC_BASE+0x120
#define IMGPROC_BRIADJ2             IMGPROC_BASE+0x124
#define IMGPROC_CONADJ              IMGPROC_BASE+0x128
#define IMGPROC_COLORIZEU           IMGPROC_BASE+0x130
#define IMGPROC_COLORIZEV           IMGPROC_BASE+0x134
#define IMGPROC_MASK11              IMGPROC_BASE+0x140
#define IMGPROC_MASK12              IMGPROC_BASE+0x144
#define IMGPROC_MASK13              IMGPROC_BASE+0x148
#define IMGPROC_MASK21              IMGPROC_BASE+0x14c
#define IMGPROC_MASK22              IMGPROC_BASE+0x150
#define IMGPROC_MASK23              IMGPROC_BASE+0x154
#define IMGPROC_MASK31              IMGPROC_BASE+0x158
#define IMGPROC_MASK32              IMGPROC_BASE+0x15c
#define IMGPROC_MASK33              IMGPROC_BASE+0x160
#define IMGPROC_SCALE               IMGPROC_BASE+0x164
#define IMGPROC_GAMMA_OFF0          IMGPROC_BASE+0x170
#define IMGPROC_GAMMA_OFF1          IMGPROC_BASE+0x174
#define IMGPROC_GAMMA_OFF2          IMGPROC_BASE+0x178
#define IMGPROC_GAMMA_OFF3          IMGPROC_BASE+0x17c
#define IMGPROC_GAMMA_OFF4          IMGPROC_BASE+0x180
#define IMGPROC_GAMMA_OFF5          IMGPROC_BASE+0x184
#define IMGPROC_GAMMA_OFF6          IMGPROC_BASE+0x188
#define IMGPROC_GAMMA_OFF7          IMGPROC_BASE+0x18c
#define IMGPROC_GAMMA_SLP0          IMGPROC_BASE+0x190
#define IMGPROC_GAMMA_SLP1          IMGPROC_BASE+0x194
#define IMGPROC_GAMMA_SLP2          IMGPROC_BASE+0x198
#define IMGPROC_GAMMA_SLP3          IMGPROC_BASE+0x19c
#define IMGPROC_GAMMA_SLP4          IMGPROC_BASE+0x1a0
#define IMGPROC_GAMMA_SLP5          IMGPROC_BASE+0x1a4
#define IMGPROC_GAMMA_SLP6          IMGPROC_BASE+0x1a8
#define IMGPROC_GAMMA_SLP7          IMGPROC_BASE+0x1ac
#define IMGPROC_GAMMA_CON           IMGPROC_BASE+0x1b0
#define IMGPROC_COLOR1R_OFFX        IMGPROC_BASE+0x200
#define IMGPROC_COLOR2R_OFFX        IMGPROC_BASE+0x204
#define IMGPROC_COLOR1G_OFFX        IMGPROC_BASE+0x208
#define IMGPROC_COLOR2G_OFFX        IMGPROC_BASE+0x20c
#define IMGPROC_COLOR1B_OFFX        IMGPROC_BASE+0x210
#define IMGPROC_COLOR2B_OFFX        IMGPROC_BASE+0x214
#define IMGPROC_COLOR1R_OFFY        IMGPROC_BASE+0x220
#define IMGPROC_COLOR2R_OFFY        IMGPROC_BASE+0x224
#define IMGPROC_COLOR1G_OFFY        IMGPROC_BASE+0x228
#define IMGPROC_COLOR2G_OFFY        IMGPROC_BASE+0x22c
#define IMGPROC_COLOR1B_OFFY        IMGPROC_BASE+0x230
#define IMGPROC_COLOR2B_OFFY        IMGPROC_BASE+0x234
#define IMGPROC_COLOR0R_SLP         IMGPROC_BASE+0x240
#define IMGPROC_COLOR1R_SLP         IMGPROC_BASE+0x244
#define IMGPROC_COLOR2R_SLP         IMGPROC_BASE+0x248
#define IMGPROC_COLOR0G_SLP         IMGPROC_BASE+0x250
#define IMGPROC_COLOR1G_SLP         IMGPROC_BASE+0x254
#define IMGPROC_COLOR2G_SLP         IMGPROC_BASE+0x258
#define IMGPROC_COLOR0B_SLP         IMGPROC_BASE+0x260
#define IMGPROC_COLOR1B_SLP         IMGPROC_BASE+0x264
#define IMGPROC_COLOR2B_SLP         IMGPROC_BASE+0x268
#define IMGPROC_MASK_CON            IMGPROC_BASE+0x300
#define IMGPROC_IMGWIDTH            IMGPROC_BASE+0x304
#define IMGPROC_IMGHEIGHT           IMGPROC_BASE+0x308
#define IMGPROC_START_SRC           IMGPROC_BASE+0x30c
#define IMGPROC_START_DST           IMGPROC_BASE+0x310
#define IMGPROC_DUMMYPXL            IMGPROC_BASE+0x314

#define IMGPROC_IMAGE_CON_EN        0x8000	// encode mode, RGB->YUV, JPEG encoder
#define IMGPROC_IMAGE_CON_IE	      0x4000	// image effect mode, RGB->RGB, stand along image
#define IMGPROC_IMAGE_CON_MPEG_EN   0x3000	// MPEG encode mode, YUV->YUV,RGB, different dimension
#define IMGPROC_IMAGE_CON_CA        0x2000	// capture mode, YUV->YUV,RGB, the same image dimension
#define IMGPROC_IMAGE_CON_DE        0x1000	// decode mode, YUV->RGV
#define IMGPROC_IMAGE_CON_MASK      0x0F00
#define IMGPROC_IMAGE_CON_GMA       0x0040
#define IMGPROC_IMAGE_CON_CLR       0x0020
#define IMGPROC_IMAGE_CON_INV       0x0010
#define IMGPROC_IMAGE_CON_CBA       0x0008
#define IMGPROC_IMAGE_CON_HSA       0x0007

#define IMGPROC_CON_START				0x1	// start the image filtering process
#define IMGPROC_CON_STOP				0x2	// stop the image filtering process
#define IMGPROC_CON_INIT				0x10	// reset some coefficients including hue, saturation, brightness and contrast

#define IMGPROC_INTR_INT				0x1 // interrupt is asserted

// definitions
#define INTERN
#define API
#define IMGPROC_EVENT		((kal_uint32)0x00000001)

// error code
#define NO_ERROR			0


//macro
#define ENABLE_EFFECT(e)            DRV_Reg(IMGPROC_IMAGE_CON) &= 0xff00;   \
                                    DRV_Reg(IMGPROC_IMAGE_CON) |= e
#define FILTER_EFFECT(e)       		DRV_Reg(IMGPROC_IMAGE_CON) &= 0xf000;   \
                                    DRV_Reg(IMGPROC_IMAGE_CON) |= (e)
#define IMGPROC_RESET()					DRV_WriteReg(IMGPROC_CON, 0);\
												DRV_WriteReg(IMGPROC_CON, IMGPROC_CON_INIT)
#define IMGPROC_START_FILTER()		DRV_WriteReg(IMGPROC_CON, 0);\
												DRV_WriteReg(IMGPROC_CON, IMGPROC_CON_START)
#define IMGPROC_STOP_FILTER()			DRV_WriteReg(IMGPROC_CON, 0);\
												DRV_WriteReg(IMGPROC_CON, IMGPROC_CON_STOP)
#define GAMMA_INC()						DRV_Reg(IMGPROC_GAMMA_CON) = 1;
#define GAMMA_DEC()						DRV_Reg(IMGPROC_GAMMA_CON) = 0;
#define IMGPROEC_ENABLE_INT()			DRV_WriteReg(IMGPROC_INTREN, 1)
#define IMGPROC_DISABLE_INT()			DRV_WriteReg(IMGPROC_INTREN, 0)


// structures and enums
typedef void (*IMGPROC_CALLBACK)();

typedef enum{
	IMGPROC_ENCODE = 0x8000,		// RGB->YUV
	IMGPROC_EFFECT = 0x4000,		// RGB->RGB (Memory effect, GIF decoder)
	IMGPROC_MPEG_ENCODE = 0x3000,	// YUV->YUV, RGB (MPEG4 encoder)
	IMGPROC_CAPTURE = 0x2000,		// YUV->YUV (JPEG encoder)
	IMGPROC_DECODE = 0x1000,		// YUV->RGB (preview, JPEG decoder, MPEG4 dedocer)
	IMGPROC_BYPASS = 0
}IMGPROC_MODE_ENUM;

typedef enum{
	IMGPROC_INIT,
	IMGPROC_READY,
	IMGPROC_BUSY
}IMGPROC_STATE_ENUM;

typedef enum{
	IMGPROC_PIXEL,
	IMGPROC_FILTER
}IMGPROC_TYPE_ENUM ;

typedef enum{
	IMGPROC_HSA_NONE = 0,
	IMGPROC_HSA_GRAY = 1,
	IMGPROC_HSA_COLORIZE = 2,
	IMGPROC_HSA_HUE = 5,
	IMGPROC_HSA_SAT = 6,
	IMGPROC_HSA_HUE_SAT = 7
}IMGPROC_HSA_ENUM ;


typedef enum{
 FILTER_NONE = 			0,
 FILTER_LP	=				0x500,
 FILTER_HP	=				0x600,
 FILTER_HP_SCAL =			0x700,
 FILTER_BLUR =				0x900,
 FILTER_BLUR_MORE =		0xa00,
 FILTER_UNSHAP =			0xb00,
 FILTER_MAX =				0xc00,
 FILTER_MED =				0xd00,
 FILTER_MIN =				0xe00
}IMGPROC_FILTER_ENUM;

// remove bit-filted declaration
typedef struct{
	IMGPROC_HSA_ENUM hsa;// hue and saturation adjustment
	kal_uint8 cba;// contrast and brightness adjustment enable
	kal_uint8 inv;// color invert enable
	kal_uint8 clr;// color adjustment enable
	kal_uint8 gma;// gamma correction enable
}IMGPROC_PIXEL_EFFECT_STURCT;

 typedef struct{
	MMDI_SCENERIO_ID owner;// scenerio ID
	IMGPROC_STATE_ENUM state;// state of image processor
	IMGPROC_MODE_ENUM gmode;// stands for operaton mode
	IMGPROC_FILTER_ENUM mask;// various mask effects(indicate filter mode or pixel mode)
	kal_uint8 feature;// effects of pixel type
	IMGPROC_CALLBACK cb;
 }IMGPROC_DCB_STRUCT;

 typedef struct{
 	kal_int8 c11;
 	kal_int8 c12;
 	kal_int8 c21;
 	kal_int8 c22;
 }IMGPROC_HUE_STURCT;

 typedef struct{
 	kal_uint8 bright;
 	kal_uint8 dark;
 	kal_uint8 contrast;
 }IMGPROC_BRI_CON_STURCT;


 typedef struct{
 	kal_int8 c11;
 	kal_int8 c12;
 	kal_int8 c13;
 	kal_int8 c21;
 	kal_int8 c22;
 	kal_int8 c23;
 	kal_int8 c31;
 	kal_int8 c32;
 	kal_int8 c33;
 }IMGPROC_MASK_STURCT;

 typedef struct{
 	kal_bool gamma;	// 1: gamma > 1, 0: gamma <= 1
 	kal_uint8 off0;
 	kal_uint8 off1;
 	kal_uint8 off2;
 	kal_uint8 off3;
 	kal_uint8 off4;
 	kal_uint8 off5;
 	kal_uint8 off6;
 	kal_uint8 off7;
 	kal_uint8 slp0;
 	kal_uint8 slp1;
 	kal_uint8 slp2;
 	kal_uint8 slp3;
 	kal_uint8 slp4;
 	kal_uint8 slp5;
 	kal_uint8 slp6;
 	kal_uint8 slp7;
 }IMGPROC_GAMMA_STRUCT;

 typedef struct{
 	kal_uint8 r1x;
 	kal_uint8 r1y;
 	kal_uint8 r2x;
 	kal_uint8 r2y;
	kal_uint8 r0slp;
	kal_uint8 r1slp;
	kal_uint8 r2slp;
 	kal_uint8 g1x;
 	kal_uint8 g1y;
 	kal_uint8 g2x;
 	kal_uint8 g2y;
	kal_uint8 g0slp;
	kal_uint8 g1slp;
	kal_uint8 g2slp;
 	kal_uint8 b1x;
 	kal_uint8 b1y;
 	kal_uint8 b2x;
 	kal_uint8 b2y;
	kal_uint8 b0slp;
	kal_uint8 b1slp;
	kal_uint8 b2slp;
 }IMGPROC_COLORIZE_STRUCT;

 extern kal_int32 API IMGPROC_Init(void);
 extern kal_int32 API IMGPROC_Open(MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_Close(MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_SelectMode(IMGPROC_MODE_ENUM mode, MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_SetPixelEffect(IMGPROC_PIXEL_EFFECT_STURCT *s, MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_SetMask(IMGPROC_FILTER_ENUM mask, MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_Start(MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_Stop(MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_WaitComplete(MMDI_SCENERIO_ID owner);
 extern kal_int32 API IMGPROC_SetHUE(MMDI_SCENERIO_ID owner, IMGPROC_HUE_STURCT* s);
 extern kal_int32 API IMGPROC_SetSAT(MMDI_SCENERIO_ID owner, kal_uint8 sat);
 extern kal_int32 API IMGPROC_SetBrightContrast(MMDI_SCENERIO_ID owner, IMGPROC_BRI_CON_STURCT* s);
 extern kal_int32 API IMGPROC_SetMaskContent(MMDI_SCENERIO_ID owner, IMGPROC_MASK_STURCT* s);
 extern kal_int32 API IMGPROC_SetMaskScaleDown(MMDI_SCENERIO_ID owner, kal_uint8 scale);
 extern kal_int32 API IMGPROC_SetColorize(MMDI_SCENERIO_ID owner, IMGPROC_COLORIZE_STRUCT* s);
 extern kal_int32 API IMGPROC_SetGamma(MMDI_SCENERIO_ID owner, IMGPROC_GAMMA_STRUCT* s);

#if (defined(DRV_IDP_6228_SERIES))

#define IMGPROC_IMAGE_CON           IMGPROC_BASE+0x0
#define IMGPROC_CON                 IMGPROC_BASE+0x4
#define IMGPROC_INTREN              IMGPROC_BASE+0x8
#define IMGPROC_INTR                IMGPROC_BASE+0xC

#define IPP_CTRL_REG						*((volatile unsigned short *) (IMGPROC_base+0x0000))
#define IPP_MASK_FILTER_CTRL_REG		*((volatile unsigned short *) (IMGPROC_base+0x0004))
#define IPP_INT_CTRL_REG				*((volatile unsigned short *) (IMGPROC_base+0x0008))
#define IPP_INT_STATUS_REG				*((volatile unsigned short *) (IMGPROC_base+0x000C))
#define IPP_STATUS_REG					*((volatile unsigned short *) (IMGPROC_base+0x0010))
#define IPP_HUE_C11_COEFF_REG			*((volatile unsigned short *) (IMGPROC_base+0x0100))
#define IPP_HUE_C12_COEFF_REG			*((volatile unsigned short *) (IMGPROC_base+0x0104))
#define IPP_HUE_C21_COEFF_REG			*((volatile unsigned short *) (IMGPROC_base+0x0108))
#define IPP_HUE_C22_COEFF_REG			*((volatile unsigned short *) (IMGPROC_base+0x010C))
#define IPP_SAT_ADJ_COEFF_REG			*((volatile unsigned short *) (IMGPROC_base+0x0110))
#define IPP_BRIGHT_B1_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0120))
#define IPP_BRIGHT_B2_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0124))
#define IPP_CONTRAST_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0128))
#define IPP_COLOR_U_COEFF_REG			*((volatile unsigned short *) (IMGPROC_base+0x0130))
#define IPP_COLOR_V_COEFF_REG			*((volatile unsigned short *) (IMGPROC_base+0x0134))
#define IPP_MASK_C11_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0140))
#define IPP_MASK_C12_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0144))
#define IPP_MASK_C13_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0148))
#define IPP_MASK_C21_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x014C))
#define IPP_MASK_C22_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0150))
#define IPP_MASK_C23_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0154))
#define IPP_MASK_C31_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0158))
#define IPP_MASK_C32_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x015C))
#define IPP_MASK_C33_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0160))
#define IPP_MASK_DOWN_SCALE_COEFF_REG		*((volatile unsigned short *) (IMGPROC_base+0x0164))
#define IPP_GAMMA_OFFSET0_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0170))
#define IPP_GAMMA_OFFSET1_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0174))
#define IPP_GAMMA_OFFSET2_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0178))
#define IPP_GAMMA_OFFSET3_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x017C))
#define IPP_GAMMA_OFFSET4_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0180))
#define IPP_GAMMA_OFFSET5_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0184))
#define IPP_GAMMA_OFFSET6_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0188))
#define IPP_GAMMA_OFFSET7_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x018C))
#define IPP_GAMMA_SLOPE0_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0190))
#define IPP_GAMMA_SLOPE1_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0194))
#define IPP_GAMMA_SLOPE2_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x0198))
#define IPP_GAMMA_SLOPE3_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x019C))
#define IPP_GAMMA_SLOPE4_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x01A0))
#define IPP_GAMMA_SLOPE5_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x01A4))
#define IPP_GAMMA_SLOPE6_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x01A8))
#define IPP_GAMMA_SLOPE7_COEFF_REG	*((volatile unsigned short *) (IMGPROC_base+0x01AC))
#define IPP_GAMMA_CTRL_REG				*((volatile unsigned short *) (IMGPROC_base+0x01B0))
#define IPP_COLOR_ADJ_OFFSET2_X_RED_REG	*((volatile unsigned short *) (IMGPROC_base+0x0200))
#define IPP_COLOR_ADJ_OFFSET3_X_RED_REG	*((volatile unsigned short *) (IMGPROC_base+0x0204))
#define IPP_COLOR_ADJ_OFFSET2_X_GREEN_REG	*((volatile unsigned short *) (IMGPROC_base+0x0208))
#define IPP_COLOR_ADJ_OFFSET3_X_GREEN_REG	*((volatile unsigned short *) (IMGPROC_base+0x020C))
#define IPP_COLOR_ADJ_OFFSET2_X_BLUE_REG	*((volatile unsigned short *) (IMGPROC_base+0x0210))
#define IPP_COLOR_ADJ_OFFSET3_X_BLUE_REG	*((volatile unsigned short *) (IMGPROC_base+0x0214))
#define IPP_COLOR_ADJ_OFFSET2_Y_RED_REG	*((volatile unsigned short *) (IMGPROC_base+0x0220))
#define IPP_COLOR_ADJ_OFFSET3_Y_RED_REG	*((volatile unsigned short *) (IMGPROC_base+0x0224))
#define IPP_COLOR_ADJ_OFFSET2_Y_GREEN_REG	*((volatile unsigned short *) (IMGPROC_base+0x0228))
#define IPP_COLOR_ADJ_OFFSET3_Y_GREEN_REG	*((volatile unsigned short *) (IMGPROC_base+0x022C))
#define IPP_COLOR_ADJ_OFFSET2_Y_BLUE_REG	*((volatile unsigned short *) (IMGPROC_base+0x0230))
#define IPP_COLOR_ADJ_OFFSET3_Y_BLUE_REG	*((volatile unsigned short *) (IMGPROC_base+0x0234))
#define IPP_COLOR_ADJ_SLOPE1_RED_REG 		*((volatile unsigned short *) (IMGPROC_base+0x0240))
#define IPP_COLOR_ADJ_SLOPE2_RED_REG 		*((volatile unsigned short *) (IMGPROC_base+0x0244))
#define IPP_COLOR_ADJ_SLOPE3_RED_REG 		*((volatile unsigned short *) (IMGPROC_base+0x0248))
#define IPP_COLOR_ADJ_SLOPE1_GREEN_REG		*((volatile unsigned short *) (IMGPROC_base+0x0250))
#define IPP_COLOR_ADJ_SLOPE2_GREEN_REG		*((volatile unsigned short *) (IMGPROC_base+0x0254))
#define IPP_COLOR_ADJ_SLOPE3_GREEN_REG		*((volatile unsigned short *) (IMGPROC_base+0x0258))
#define IPP_COLOR_ADJ_SLOPE1_BLUE_REG		*((volatile unsigned short *) (IMGPROC_base+0x0260))
#define IPP_COLOR_ADJ_SLOPE2_BLUE_REG		*((volatile unsigned short *) (IMGPROC_base+0x0264))
#define IPP_COLOR_ADJ_SLOPE3_BLUE_REG 		*((volatile unsigned short *) (IMGPROC_base+0x0268))
#define IPP_IMAGE_FRAME_WIDTH_REG			*((volatile unsigned short *) (IMGPROC_base+0x0304))
#define IPP_IMAGE_FRAME_HEIGHT_REG			*((volatile unsigned short *) (IMGPROC_base+0x0308))
#define IPP_IMAGE_SRC_BASE_ADDR_REG			*((volatile unsigned int *) (IMGPROC_base+0x030C))
#define IPP_IMAGE_DEST_BASE_ADDR_REG		*((volatile unsigned int *) (IMGPROC_base+0x0310))
#define IPP_IMAGE_DUMMY_PIXEL_REG			*((volatile unsigned short *) (IMGPROC_base+0x0314))
#define IPP_RGB2YUV_SOURCE_SELECT_REG		*((volatile unsigned short *) (IMGPROC_base+0x0318))
#define IPP_THUMBNAIL_OUTPUT_ENABLE_REG	*((volatile unsigned short *) (IMGPROC_base+0x031C))
#define IPP_ENABLE_CTRL_REG					*((volatile unsigned short *) (IMGPROC_base+0x0320))

/* bit mapping of image engine control register */
#define REG_IPP_CTRL_GRAPH_MODE_MASK		0xF000
#define REG_IPP_CTRL_MASK_FILTER_MASK		0x0F00
#define REG_IPP_CTRL_SRC_RGB_SELECT_BIT	0x0080
#define REG_IPP_CTRL_GAMMA_ENABLE_BIT		0x0040
#define REG_IPP_CTRL_COLOR_ADJ_ENABLE_BIT	0x0020
#define REG_IPP_CTRL_COLOR_INV_ENABLE_BIT	0x0010
#define REG_IPP_CTRL_CB_ENABLE_BIT			0x0008
#define REG_IPP_CTRL_HUE_SAT_SELECT_MASK	0x0007

#define IPP_COLOR_RGB565				0
#define IPP_COLOR_RGB888				1

#define IPP_IMAGE_ENCODE_MODE					0x8
#define IPP_ZOOM_IN_MODE						0x6
#define IPP_IMGPROC_MODE						0x5
#define IPP_VIDEO_MODE							0x3
#define IPP_CAPTURE_MODE						0x2
#define IPP_PREVIEW_PLAYBACK_MODE			0x1

#define IPP_FILTER_NONE							0x0
#define IPP_FILTER_LINEAR_LP					0x5
#define IPP_FILTER_LINEAR_HP					0x6
#define IPP_FILTER_LINEAR_HP_SCALE_DOWN	0x7
#define IPP_FILTER_BLUR							0x9
#define IPP_FILTER_MORE_BLUR					0xA
#define IPP_FILTER_UNSHARP						0xB
#define IPP_FILTER_MAXIMUM_RANKING			0xC
#define IPP_FILTER_MEDIAN_RANKING			0xD
#define IPP_FILTER_MINIMUM_RANKING			0xE

#define IPP_GAMMA_CORRECTION					0x40
#define IPP_COLOR_ADJUST						0x20
#define IPP_COLOR_INVERT						0x10
#define IPP_CONTRAST_AND_BRIGHTNESS			0x08

#define IPP_HUE_SAT_GRAY_SCALE_EFFECT		0x01
#define IPP_HUE_SAT_COLOR_EFFECT				0x02
#define IPP_HUE_SAT_HUE_ADJUST_EFFECT		0x05
#define IPP_HUE_SAT_SAT_ADJUST_EFFECT		0x06
#define IPP_HUE_SAT_ADJUST_EFFECT			0x07

/* bit mapping of Mask filter control register */
#define REG_MASK_FILTER_CTRL_RESET_BIT		0x0010
#define REG_MASK_FILTER_CTRL_ENABLE_BIT	0x0004
#define REG_MASK_FILTER_CTRL_STOP_BIT		0x0002
#define REG_MASK_FILTER_CTRL_START_BIT		0x0001

/* bit mapping of image processor enable register */
#define REG_IPP_ENABLE_BIT						0x0001
#define REG_IPP_RESET_BIT						0x0004

/* macros of IPP control register */
#define SET_IPP_GRAPH_MODE(n)			IPP_CTRL_REG &= ~REG_IPP_CTRL_GRAPH_MODE_MASK;\
												IPP_CTRL_REG |= (n<<12);
#define SET_IPP_MASK_FILTER(n)		IPP_CTRL_REG &= ~REG_IPP_CTRL_MASK_FILTER_MASK;\
												IPP_CTRL_REG |= (n<<8);
#define SET_IPP_FILTER_SRC_RGB565	IPP_CTRL_REG &= ~REG_IPP_CTRL_SRC_RGB_SELECT_BIT;
#define SET_IPP_FILTER_SRC_RGB888	IPP_CTRL_REG |= REG_IPP_CTRL_SRC_RGB_SELECT_BIT;
#define ENABLE_IPP_GAMMA_CORRECTION		IPP_CTRL_REG |=REG_IPP_CTRL_GAMMA_ENABLE_BIT;
#define DISABLE_IPP_GAMMA_CORRECTION	IPP_CTRL_REG &= ~REG_IPP_CTRL_GAMMA_ENABLE_BIT;
#define ENABLE_IPP_COLOR_ADJUST		IPP_CTRL_REG |= REG_IPP_CTRL_COLOR_ADJ_ENABLE_BIT;
#define DISABLE_IPP_COLOR_ADJUST		IPP_CTRL_REG &= ~REG_IPP_CTRL_COLOR_ADJ_ENABLE_BIT;
#define ENABLE_IPP_COLOR_INV			IPP_CTRL_REG |= REG_IPP_CTRL_COLOR_INV_ENABLE_BIT;
#define DISABLE_IPP_COLOR_INV			IPP_CTRL_REG &= ~REG_IPP_CTRL_COLOR_INV_ENABLE_BIT;
#define ENABLE_IPP_CONTRAST_BRIGHT	IPP_CTRL_REG |= REG_IPP_CTRL_CB_ENABLE_BIT;
#define DISABLE_IPP_CONTRAST_BRIGHT	IPP_CTRL_REG &= ~REG_IPP_CTRL_CB_ENABLE_BIT;
#define SET_IPP_HUE_SAT(n)				IPP_CTRL_REG &= ~REG_IPP_CTRL_HUE_SAT_SELECT_MASK;\
												IPP_CTRL_REG |= n;

/* macro of mask filter control register */
#define RESET_PIXEL_BASE_IPP			IPP_MASK_FILTER_CTRL_REG |= REG_MASK_FILTER_CTRL_RESET_BIT;
#define START_MASK_FILTER				IPP_MASK_FILTER_CTRL_REG |= REG_MASK_FILTER_CTRL_START_BIT;
#define STOP_MASK_FILTER				IPP_MASK_FILTER_CTRL_REG |= REG_MASK_FILTER_CTRL_STOP_BIT;
#define ENABLE_MASK_FILTER				IPP_MASK_FILTER_CTRL_REG |= REG_MASK_FILTER_CTRL_ENABLE_BIT;
#define DISABLE_MASK_FILTER			IPP_MASK_FILTER_CTRL_REG &= ~REG_MASK_FILTER_CTRL_ENABLE_BIT;

/* macro of image processor interrupt register */
#define ENABLE_IPP_INT					IPP_INT_CTRL_REG =1;
#define DISABLE_IPP_INT					IPP_INT_CTRL_REG=0;

/* macro of IPP status regiseter */
#define IS_IPP_IS_BUSY					(IPP_STATUS_REG & 0x01)
/* macro of image processor machine enable register */
#define ENABLE_IPP			IPP_ENABLE_CTRL_REG |= 	REG_IPP_ENABLE_BIT;
#define DISABLE_IPP			IPP_ENABLE_CTRL_REG &= ~REG_IPP_ENABLE_BIT;
#define RESET_IPP				IPP_ENABLE_CTRL_REG &= ~REG_IPP_RESET_BIT;\
									IPP_ENABLE_CTRL_REG |= REG_IPP_RESET_BIT;

#define SET_IPP_R2Y_SRC_IMGDMA		IPP_RGB2YUV_SOURCE_SELECT_REG=1;

#define ENABLE_THUMBNAIL_OUTPUT		IPP_THUMBNAIL_OUTPUT_ENABLE_REG=1;
#define DISABLE_THUMBNAIL_OUTPUT		IPP_THUMBNAIL_OUTPUT_ENABLE_REG=0;


typedef struct
{
	kal_uint8 filter_mode;
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;

	kal_uint8 src_color_mode;				/* IPP_COLOR_RGB565 or IPP_COLOR_RGB888 */
	kal_uint8 dest_color_mode;				/* IPP_COLOR_RGB565 or IPP_COLOR_RGB888 */
	kal_uint8 src_color_order;				/* RGB565 or RGB888 */
	kal_uint32 src_address;
	kal_uint32 dest_address;
	kal_uint16 src_width;
	kal_uint16 src_height;

	void (*ipp_effect_cb) (void);
} ipp_effect_struct;
#endif
#endif
#endif //IMGPROC_H
#endif //IMGPROC_H
