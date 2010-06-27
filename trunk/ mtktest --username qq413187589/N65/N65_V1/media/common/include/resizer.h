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
 *    resizer.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of resizer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef RESIZER_H
#define RESIZER_H

#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "resizer_6238_series.h"

#else

#if (defined(DRV_IDP_6219_SERIES))
#define RESZ_BASE				(RESIZER_base)
// registers
#define RESZ_CFG				RESZ_BASE+0
#define RESZ_CON				RESZ_BASE+0x4
#define RESZ_STA				RESZ_BASE+0x8
#define RESZ_INT				RESZ_BASE+0xc
#define RESZ_SRCSZ1			RESZ_BASE+0x10
#define RESZ_TARSZ1			RESZ_BASE+0x14
#define RESZ_HRATIO1			RESZ_BASE+0x18
#define RESZ_VRATIO1			RESZ_BASE+0x1c
#define RESZ_HRES1			RESZ_BASE+0x20
#define RESZ_VRES1			RESZ_BASE+0x24
#define RESZ_BLKCSCFG		RESZ_BASE+0x30
#define RESZ_YLMBASE			RESZ_BASE+0x34
#define RESZ_ULMBASE			RESZ_BASE+0x38
#define RESZ_VLMBASE			RESZ_BASE+0x3c
#define RESZ_FRCFG			RESZ_BASE+0x40
#define RESZ_YWMBASE			RESZ_BASE+0x44
#define RESZ_UWMBASE			RESZ_BASE+0x48
#define RESZ_VWMBASE			RESZ_BASE+0x4c
#define RESZ_YLBSIZE			RESZ_BASE+0x50
#define RESZ_ULBSIZE			RESZ_BASE+0x54
#define RESZ_VLBSIZE			RESZ_BASE+0x58
#define RESZ_PRWMBASE		RESZ_BASE+0x5c
#define RESZ_SRCSZ2			RESZ_BASE+0x60
#define RESZ_TARSZ2			RESZ_BASE+0x64
#define RESZ_HRATIO2			RESZ_BASE+0x68
#define RESZ_VRATIO2			RESZ_BASE+0x6c
#define RESZ_HRES2			RESZ_BASE+0x70
#define RESZ_VRES2			RESZ_BASE+0x74

// bit mask
#define RESZ_CFG_PELSRC1	0x0000000f
#define RESZ_CFG_PCON		0x00000010
#define RESZ_CFG_PSEL		0x00000020
#define RESZ_CFG_PRUN		0x00000040
#define RESZ_CFG_PELSRC2	0x00000f00
#define RESZ_CFG_BWA0		0x000f0000
#define RESZ_CFG_BWB0		0x00f00000
#define RESZ_CFG_BWA1		0x0f000000
#define RESZ_CFG_BWB1		0xf0000000

#define RESZ_CON_BLKCSENA			0x00000001
#define RESZ_CON_BLKHRENA			0x00000002
#define RESZ_CON_BLKVRENA			0x00000004
#define RESZ_CON_PELHRENA			0x00000020
#define RESZ_CON_PELVRENA			0x00000040
#define RESZ_CON_BLKCSRST			0x00010000
#define RESZ_CON_BLKHRRST			0x00020000
#define RESZ_CON_BLKVRRST			0x00040000
#define RESZ_CON_PELHRRST			0x00200000
#define RESZ_CON_PELVRRST			0x00400000

#define RESZ_STA_BLKCSBUSY			0x00000001
#define RESZ_STA_BLKHRBUSY			0x00000002
#define RESZ_STA_BLKVRBUSY			0x00000004
#define RESZ_STA_PELHRBUSY			0x00000020
#define RESZ_STA_PELVRBUSY			0x00000040
#define RESZ_STA_P2NDRUN			0x00000080

#define RESZ_INT_BLKCSINT			0x00000001
#define RESZ_INT_BLKHRINT			0x00000002
#define RESZ_INT_BLKVRINT			0x00000004
#define RESZ_INT_PELHRINT			0x00000002
#define RESZ_INT_PELVRINT			0x00000004

#define RESZ_HRES1_MAX				2046
#define RESZ_VRES1_MAX				2046

#define RESZ_BLKCSCFG_CSF			0x00000003
#define RESZ_BLKCSCFG_HY			0x00000030
#define RESZ_BLKCSCFG_VY			0x000000c0
#define RESZ_BLKCSCFG_HU			0x00000300
#define RESZ_BLKCSCFG_VU			0x00000c00
#define RESZ_BLKCSCFG_HV			0x00003000
#define RESZ_BLKCSCFG_VV			0x0000c000
#define RESZ_BLKCSCFG_INTEN		0x00010000

#define RESZ_FRCFG_VRSS				0x00000001
#define RESZ_FRCFG_HRINTEN			0x00000010
#define RESZ_FRCFG_VRINTEN			0x00000020
#define RESZ_FRCFG_PCSF1			0x00000300
#define RESZ_FRCFG_PCSF2			0x00000c00
#define RESZ_FRCFG_SEQ				0x00008000
#define RESZ_FRCFG_WMSZ				0xffff0000

   #if (defined(MT6219))
   #define RESZ_H_RATIO_SHIFT_BITS  21
   #define RESZ_V_RATIO_SHIFT_BITS  21
   #elif (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))
   #define RESZ_H_RATIO_SHIFT_BITS  20
   #define RESZ_V_RATIO_SHIFT_BITS  20
   #endif
// NOte: block mode stands for JPEG decoder
typedef enum{
	SRC_CAMERA = 0,
	SRC_MPEG4 = 1,
	SRC_PNG = 2,
	SRC_GIF = 3,
	SRC_MEM = 4,
	SRC_JPEG_DECODER = 5
}RESZ_PXL_SRC_ENUM;

typedef enum{
	RESZ_INIT,
	RESZ_READY,
	RESZ_BUSY
}RESZ_STATE_ENUM;

typedef enum{
	RESZ_CS_1_1 = 0,
	RESZ_CS_1_4 = 1,
	RESZ_CS_1_16 = 2,
	RESZ_CS_1_64 = 3
}RESZ_CS_FACTOR_ENUM;

typedef enum{
	RESZ_HY_SF_1 = 0,
	RESZ_HY_SF_2 = 1,
	RESZ_HY_SF_4 = 2,
	RESZ_HY_SF_NONE = 3
}RESZ_HY_SAMPLING_FACTOR_ENUM;

typedef enum{
	RESZ_VY_SF_1 = 0,
	RESZ_VY_SF_2 = 1,
	RESZ_VY_SF_4 = 2,
	RESZ_VY_SF_NONE = 3
}RESZ_VY_SAMPLING_FACTOR_ENUM;

typedef enum{
	RESZ_HU_SF_1 = 0,
	RESZ_HU_SF_2 = 1,
	RESZ_HU_SF_4 = 2,
	RESZ_HU_SF_NONE = 3
}RESZ_HU_SAMPLING_FACTOR_ENUM;

typedef enum{
	RESZ_VU_SF_1 = 0,
	RESZ_VU_SF_2 = 1,
	RESZ_VU_SF_4 = 2,
	RESZ_VU_SF_NONE = 3
}RESZ_VU_SAMPLING_FACTOR_ENUM;

typedef enum{
	RESZ_HV_SF_1 = 0,
	RESZ_HV_SF_2 = 1,
	RESZ_HV_SF_4 = 2,
	RESZ_HV_SF_NONE = 3
}RESZ_HV_SAMPLING_FACTOR_ENUM;

typedef enum{
	RESZ_VV_SF_1 = 0,
	RESZ_VV_SF_2 = 1,
	RESZ_VV_SF_4 = 2,
	RESZ_VV_SF_NONE = 3
}RESZ_VV_SAMPLING_FACTOR_ENUM;


// structures
typedef struct{
	kal_uint32 src1			:4;// select pixel based image source(RESZ_PXL_SRC_ENUM)
	kal_uint32 pcontinue		:1;// if pixel based resizing continue(1: continue resizeing, 0: single resizing
	kal_uint32 pixel_sel		:1;// determine pixel-based or block based image(block mode imply jpeg decoder as source )
	kal_uint32 run2			:1;// resize two times
	kal_uint32					:1;// padding
	kal_uint32 src2			:4;// select pixel based image source2
	kal_uint32					:4;// padding
}RESZ_CFG_STRUCT;

typedef struct{
	// sampling factors
	kal_uint32 csf	:2;// coarse shrink factor(RESZ_CS_FACTOR_ENUM)
	kal_uint32 		:2;
	kal_uint32 hy	:2;// Y horizontal sampling factor(RESZ_HY_SAMPLING_FACTOR_ENUM)
	kal_uint32 vy	:2;// Y vertical sampling factor(RESZ_VY_SAMPLING_FACTOR_ENUM)
	kal_uint32 hu	:2;// U horizontal sampling factor(RESZ_HU_SAMPLING_FACTOR_ENUM)
	kal_uint32 vu	:2;// U vertical sampling factor(RESZ_VU_SAMPLING_FACTOR_ENUM)
	kal_uint32 hv	:2;// V horizontal sampling factor(RESZ_HV_SAMPLING_FACTOR_ENUM)
	kal_uint32 vv	:2;// V vertical sampling factor(RESZ_VV_SAMPLING_FACTOR_ENUM)

	// size of line bffer
	kal_uint32 ylbsize:16;// Y component line buffer size
	kal_uint32 ulbsize:16;// U component line buffer size
	kal_uint32 vlbsize:16;// V component line buffer size

	// size of working memory
	kal_uint32 wmsize:16;

	// base address of line buffers
	kal_uint32 ylmbase:32;
	kal_uint32 ulmbase:32;
	kal_uint32 vlmbase:32;

	// base address of working memory
	kal_uint32 ywmbase:32;
	kal_uint32 uwmbase:32;
	kal_uint32 vwmbase:32;
}RESZ_BLK_CFG_STRUCT;

typedef struct{
	kal_uint16 wmsize;
	kal_uint32 wmbase;
}RESZ_PXL_CFG_STRUCT;

typedef struct{
	MMDI_SCENERIO_ID owner;
	RESZ_STATE_ENUM state;
	RESZ_CFG_STRUCT cfg;	
}RESZ_DCB_STRUCT;

// macro
#define RESZ_BYPASS() 				DRV_Reg32(RESZ_BASE+0x90) |= 0x8000
#define RESZ_SET_WMBASE_PXL(a) 	DRV_WriteReg32(RESZ_PRWMBASE, (a))
#define RESZ_SET_WMBASE_BLK(y,u,v)	\
{\
	DRV_WriteReg32(RESZ_YWMBASE, y);\
	DRV_WriteReg32(RESZ_UWMBASE, u);\
	DRV_WriteReg32(RESZ_VWMBASE, v);\
}
#define RESZ_SET_LMBASE_BLK(y,u,v)	\
{\
	DRV_WriteReg32(RESZ_YLMBASE, y);\
	DRV_WriteReg32(RESZ_ULMBASE, u);\
	DRV_WriteReg32(RESZ_VLMBASE, v);\
}

#define RESZ_SET_LBSIZE_BLK(y,u,v)	\
{\
	DRV_WriteReg(RESZ_YLBSIZE, y);\
	DRV_WriteReg(RESZ_ULBSIZE, u);\
	DRV_WriteReg(RESZ_VLBSIZE, v);\
}


#define RESZ_NO_OWNER		LAST_MOD_ID + 0x11
#define RESZ_BLK_EN			0x7
#if (defined(MT6219))
#define RESZ_PXL_EN			0x60
#define RESZ_BLK_RST			0x70000
#define RESZ_PXL_RST			0x600000
#elif (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))
#define RESZ_PXL_EN			0x6
#define RESZ_BLK_RST			0x70000
#define RESZ_PXL_RST			0x60000
#endif
#define RESZ_ALL_RST			RESZ_BLK_RST|RESZ_PXL_RST

// error code
#define NO_ERROR							0
#define RESZ_ERR_INVALID_SIZE			1


// extern
extern kal_int32 API RESZ_Init(void);
extern kal_int32 API RESZ_Open(MMDI_SCENERIO_ID owner);
extern kal_int32 API RESZ_Close(MMDI_SCENERIO_ID owner);
extern kal_int32 API RESZ_Config(RESZ_CFG_STRUCT *cfg, void *s, MMDI_SCENERIO_ID owner);
extern kal_int32 API RESZ_SetSize(kal_uint32 src_w, kal_uint32 src_h, kal_uint32 tar_w, kal_uint32 tar_h, MMDI_SCENERIO_ID owner);
extern kal_int32 API RESZ_SetSize2(kal_uint32 src_w, kal_uint32 src_h, kal_uint32 tar_w, kal_uint32 tar_h, MMDI_SCENERIO_ID owner);
extern kal_int32 API RESZ_Start(MMDI_SCENERIO_ID owner);
extern kal_int32 API RESZ_Stop(MMDI_SCENERIO_ID owner);
extern kal_bool API RESZ_CheckBusy(void);
extern kal_int32 INTERN RESZ_SetWMSize(kal_uint16 size, kal_bool pixel);

#elif (defined(DRV_IDP_6228_SERIES))
   #define RESZ_H_RATIO_SHIFT_BITS  20
   #define RESZ_V_RATIO_SHIFT_BITS  20

	/* DRZ definition */
	#define PRZ_CONFIG_REG					(PRZ_base + 0x00)
	#define PRZ_CTRL_REG	   				(PRZ_base + 0x04)
	#define PRZ_STATUS_REG					(PRZ_base + 0x08)
	#define PRZ_INT_STATUS_REG				(PRZ_base + 0x0C)
	#define PRZ_SOURCE_IMAGE_SIZE_REG	(PRZ_base + 0x10)
	#define PRZ_TARGET_IMAGE_SIZE_REG	(PRZ_base + 0x14)
	#define PRZ_H_RATIO_REG					(PRZ_base + 0x18)
	#define PRZ_V_RATIO_REG					(PRZ_base + 0x1C)
	#define PRZ_H_RESIDUAL_REG				(PRZ_base + 0x20)
	#define PRZ_V_RESIDUAL_REG				(PRZ_base + 0x24)
	#define PRZ_BLOCK_CS_CFG_REG		   (PRZ_base + 0x30)
	#define PRZ_Y_LINE_BUFFER_ADDR_REG	(PRZ_base + 0x34)
	#define PRZ_U_LINE_BUFFER_ADDR_REG	(PRZ_base + 0x38)
	#define PRZ_V_LINE_BUFFER_ADDR_REG	(PRZ_base + 0x3C)
	#define PRZ_FINE_RESIZE_CFG_REG		(PRZ_base + 0x40)
	#define PRZ_LINE_BUFFER_SIZE_REG		(PRZ_base + 0x50)
	#define PRZ_WORK_MEM_ADDR_REG			(PRZ_base + 0x5C)

	#define REG_PRZ_CONFIG		   		*((volatile unsigned int *) (PRZ_base + 0x00))
	#define REG_PRZ_CTRL			   		*((volatile unsigned int *) (PRZ_base + 0x04))
	#define REG_PRZ_STATUS					*((volatile unsigned int *) (PRZ_base + 0x08))
	#define REG_PRZ_INT_STATUS				*((volatile unsigned int *) (PRZ_base + 0x0C))
	#define REG_PRZ_SOURCE_IMAGE_SIZE	*((volatile unsigned int *) (PRZ_base + 0x10))
	#define REG_PRZ_TARGET_IMAGE_SIZE	*((volatile unsigned int *) (PRZ_base + 0x14))
	#define REG_PRZ_H_RATIO					*((volatile unsigned int *) (PRZ_base + 0x18))
	#define REG_PRZ_V_RATIO					*((volatile unsigned int *) (PRZ_base + 0x1C))
	#define REG_PRZ_H_RESIDUAL				*((volatile unsigned int *) (PRZ_base + 0x20))
	#define REG_PRZ_V_RESIDUAL				*((volatile unsigned int *) (PRZ_base + 0x24))
	#define REG_PRZ_BLOCK_CS_CFG		   *((volatile unsigned int *) (PRZ_base + 0x30))
	#define REG_PRZ_Y_LINE_BUFFER_ADDR	*((volatile unsigned int *) (PRZ_base + 0x34))
	#define REG_PRZ_U_LINE_BUFFER_ADDR	*((volatile unsigned int *) (PRZ_base + 0x38))
	#define REG_PRZ_V_LINE_BUFFER_ADDR	*((volatile unsigned int *) (PRZ_base + 0x3C))
	#define REG_PRZ_FINE_RESIZE_CFG		*((volatile unsigned int *) (PRZ_base + 0x40))
	#define REG_PRZ_LINE_BUFFER_SIZE		*((volatile unsigned int *) (PRZ_base + 0x50))
	#define REG_PRZ_WORK_MEM_ADDR			*((volatile unsigned int *) (PRZ_base + 0x5C))

	/* bit mapping of PRZ config register */
	#define PRZ_CONFIG_LINE_BUF_SEL_BIT	0x00000080
	#define PRZ_CONFIG_PIXEL_SRC_MASK	0x0000000F
	#define PRZ_CONFIG_SRC_SEL_BIT		0x00000020
	#define PRZ_CONFIG_CONT_RUN_BIT		0x00000010

	#define PRZ_CONFIG_PIXEL_SRC_CAMERA_ISP				0
	#define PRZ_CONFIG_PIXEL_SRC_MPEG4_ENCODE_DMA		1
	#define PRZ_CONFIG_PIXEL_SRC_MPEG4_DECODE_DMA		2
	#define PRZ_CONFIG_PIXEL_SRC_IBW4_DMA					3
	#define PRZ_CONFIG_PIXEL_SRC_IPP							4
	#define PRZ_CONFIG_PIXEL_SRC_JPEG_DECODER				5
	/* bit mapping of PRZ control register */
	#define PRZ_CTRL_RESET_MASK                 	0x00070000
	#define PRZ_CTRL_ENABLE_MASK                	0x00000007
	#define PRZ_CTRL_BLOCK_CS_ENABLE_BIT		  	0x00000001
	#define PRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT		0x00000002
	#define PRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT		0x00000004
	#define PRZ_CTRL_BLOCK_CS_RESET_BIT				0x00010000
	#define PRZ_CTRL_H_FINE_RESIZE_RESET_BIT		0x00020000
	#define PRZ_CTRL_V_FINE_RESIZE_RESET_BIT		0x00040000

	/* bit mapping of PRZ status register */
	#define PRZ_CTRL_BLOCK_CS_BUSY_BIT				0x00000001
	#define PRZ_CTRL_H_FINE_RESIZE_BUSY_BIT		0x00000002
	#define PRZ_CTRL_V_FINE_RESIZE_BUSY_BIT		0x00000004

	/* bit mapping of PRZ interrupt status register */
	#define PRZ_CTRL_BLOCK_CS_INT_BIT				0x00000001
	#define PRZ_CTRL_H_FINE_RESIZE_INT_BIT			0x00000002
	#define PRZ_CTRL_V_FINE_RESIZE_INT_BIT			0x00000004

	/* bit mapping of PRZ source and target size register */
	#define PRZ_IMAGE_SIZE_WIDTH_MASK			0x0000FFFF
	#define PRZ_IMAGE_SIZE_HEIGHT_MASK			0xFFFF0000

	/* bit mapping of PRZ block coarse shrink config register */
	#define PRZ_BLOCK_CS_CFG_BLOCK_INT_ENABLE_BIT		0x00010000
	#define PRZ_BLOCk_CS_CFG_V_V_SAMPLE_FACTOR_MASK		0x0000C000
	#define PRZ_BLOCk_CS_CFG_V_H_SAMPLE_FACTOR_MASK		0x00003000
	#define PRZ_BLOCk_CS_CFG_U_V_SAMPLE_FACTOR_MASK		0x00000C00
	#define PRZ_BLOCk_CS_CFG_U_H_SAMPLE_FACTOR_MASK		0x00000300
	#define PRZ_BLOCk_CS_CFG_Y_V_SAMPLE_FACTOR_MASK		0x000000C0
	#define PRZ_BLOCk_CS_CFG_Y_H_SAMPLE_FACTOR_MASK		0x00000030
	#define PRZ_BLOCk_CS_CFG_CS_FACTOR_MASK			   0x00000003

	/* definition of resizer block CS register */
	#define BLOCK_CS_1_1			   0x00000000
	#define BLOCK_CS_1_4			   0x00000001
	#define BLOCK_CS_1_16			0x00000002
	#define BLOCK_CS_1_64			0x00000003
	#define BLOCK_Y_H_FACTOR_1		0x00000000
	#define BLOCK_Y_H_FACTOR_2		0x00000010
	#define BLOCK_Y_H_FACTOR_4		0x00000020
	#define BLOCK_NO_Y_H_COMP		0x00000030
	#define BLOCK_Y_V_FACTOR_1		0x00000000
	#define BLOCK_Y_V_FACTOR_2		0x00000040
	#define BLOCK_Y_V_FACTOR_4		0x00000080
	#define BLOCK_NO_Y_V_COMP		0x000000C0
	#define BLOCK_U_H_FACTOR_1		0x00000000
	#define BLOCK_U_H_FACTOR_2		0x00000100
	#define BLOCK_U_H_FACTOR_4		0x00000200
	#define BLOCK_NO_U_H_COMP		0x00000300
	#define BLOCK_U_V_FACTOR_1		0x00000000
	#define BLOCK_U_V_FACTOR_2		0x00000400
	#define BLOCK_U_V_FACTOR_4		0x00000800
	#define BLOCK_NO_U_V_COMP		0x00000CC0
	#define BLOCK_V_H_FACTOR_1		0x00000000
	#define BLOCK_V_H_FACTOR_2		0x00001000
	#define BLOCK_V_H_FACTOR_4		0x00002000
	#define BLOCK_NO_V_H_COMP		0x00003000
	#define BLOCK_V_V_FACTOR_1		0x00000000
	#define BLOCK_V_V_FACTOR_2		0x00004000
	#define BLOCK_V_V_FACTOR_4		0x00008000
	#define BLOCK_NO_V_V_COMP		0x0000C000

	/* bit mapping of PRZ fine resize config register */
	#define PRZ_FINE_RESIZE_WORK_MEM_SIZE_MASK	0xFFFF0000
	#define PRZ_FINE_RESIZE_OUTPUT_SEL_BIT			0x00008000
	#define PRZ_FINE_RESIZE_CS_MASK					0x00000300
	#define PRZ_H_FINE_RESIZE_INT						0x00000010
	#define PRZ_V_FINE_RESIZE_INT						0x00000020

	/* bit mapping of PRZ line buffer size register */
	#define PRZ_LINE_BUFF_SIZE_MASK					0x0000FFFF

	/* Macros of PRZ control register */
	#define SET_PRZ_SRC(src)				REG_PRZ_CONFIG &= ~PRZ_CONFIG_PIXEL_SRC_MASK;\
													REG_PRZ_CONFIG |= src;
	#define SET_PRZ_PIXEL_MODE				REG_PRZ_CONFIG |= PRZ_CONFIG_SRC_SEL_BIT;
	#define SET_PRZ_BLOCK_MODE				REG_PRZ_CONFIG &= ~PRZ_CONFIG_SRC_SEL_BIT;
	#define SET_PRZ_CONT_MODE				REG_PRZ_CONFIG |= PRZ_CONFIG_CONT_RUN_BIT;
	#define SET_PRZ_SINGLE_MODE			REG_PRZ_CONFIG &= ~PRZ_CONFIG_CONT_RUN_BIT;
	#define SET_PRZ_SHARED_MEMORY			REG_PRZ_CONFIG &= ~PRZ_CONFIG_LINE_BUF_SEL_BIT;
	#define SET_PRZ_DEDICATED_MEMORY		REG_PRZ_CONFIG |= PRZ_CONFIG_LINE_BUF_SEL_BIT;

	/* Macros of PRZ control register */
	#define RESET_PRZ               			REG_PRZ_CTRL=PRZ_CTRL_RESET_MASK;\
                                   			REG_PRZ_CTRL=0;
	#define SET_BLOCK_CS_RESET			  	 	REG_PRZ_CTRL |= PRZ_CTRL_BLOCK_CS_RESET_BIT;
	#define CLEAR_BLOCK_CS_RESET				REG_PRZ_CTRL &= ~PRZ_CTRL_BLOCK_CS_RESET_BIT;
	#define SET_PRZ_H_FINE_RESIZE_RESET		REG_PRZ_CTRL |= PRZ_CTRL_H_FINE_RESIZE_RESET_BIT;
	#define CLEAR_PRZ_H_FINE_RESIZE_RESET  REG_PRZ_CTRL &= ~PRZ_CTRL_H_FINE_RESIZE_RESET_BIT;
	#define SET_PRZ_V_FINE_RESIZE_RESET		REG_PRZ_CTRL |= PRZ_CTRL_V_FINE_RESIZE_RESET_BIT;
	#define CLEAR_PRZ_V_FINE_RESIZE_RESET  REG_PRZ_CTRL &= ~PRZ_CTRL_V_FINE_RESIZE_RESET_BIT;

	#define ENABLE_BLOCK_CS_BLOCK		   REG_PRZ_CTRL |= PRZ_CTRL_BLOCK_CS_ENABLE_BIT;
	#define DISABLE_BLOCK_CS_BLOCK		REG_PRZ_CTRL &= ~PRZ_CTRL_BLOCK_CS_ENABLE_BIT;
	#define ENABLE_PRZ_H_LINE				REG_PRZ_CTRL |= PRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT;
	#define DISABLE_PRZ_H_LINE				REG_PRZ_CTRL &= ~PRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT;
	#define ENABLE_PRZ_V_LINE				REG_PRZ_CTRL |= PRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT;
	#define DISABLE_PRZ_V_LINE				REG_PRZ_CTRL &= ~PRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT;
	#define ENABLE_PRZ  		            REG_PRZ_CTRL = PRZ_CTRL_ENABLE_MASK;

	/* Macros of PRZ status register */
	#define IS_BLOCK_CS_BUSY		 		(REG_PRZ_STATUS & PRZ_CTRL_BLOCK_CS_BUSY_BIT)
	#define IS_PRZ_H_FINE_RESIZE_BUSY	(REG_PRZ_STATUS & PRZ_CTRL_H_FINE_RESIZE_BUSY_BIT)
	#define IS_PRZ_V_FINE_RESIZE_BUSY	(REG_PRZ_STATUS & PRZ_CTRL_V_FINE_RESIZE_BUSY_BIT)

	/* Macros of PRZ source image size register */
	#define SET_PRZ_SRC_SIZE(width, height)		REG_PRZ_SOURCE_IMAGE_SIZE=(width|(height<<16));

	/* Macros of PRZ target image size register */
	#define SET_PRZ_TARGET_SIZE(width, height)	REG_PRZ_TARGET_IMAGE_SIZE=(width|(height<<16));

/* Macros of resizer block coarse shrinking config register */
	#define SET_PRZ_BLOCK_CS_V_V_FACTOR(factor)		REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCk_CS_CFG_V_V_SAMPLE_FACTOR_MASK;\
										            			REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<14);
	#define SET_PRZ_BLOCK_CS_V_H_FACTOR(factor)		REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCk_CS_CFG_V_H_SAMPLE_FACTOR_MASK;\
													            REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<12);
	#define SET_PRZ_BLOCK_CS_U_V_FACTOR(factor)		REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCk_CS_CFG_U_V_SAMPLE_FACTOR_MASK;\
													            REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<10);
	#define SET_PRZ_BLOCK_CS_U_H_FACTOR(factor)		REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCk_CS_CFG_U_H_SAMPLE_FACTOR_MASK;\
													            REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<8);
	#define SET_PRZ_BLOCK_CS_Y_V_FACTOR(factor)		REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCk_CS_CFG_Y_V_SAMPLE_FACTOR_MASK;\
            													REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<6);
	#define SET_PRZ_BLOCK_CS_Y_H_FACTOR(factor)		REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCk_CS_CFG_Y_H_SAMPLE_FACTOR_MASK;\
				            									REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<4);
	#define SET_PRZ_BLOCK_CS_FACTOR(factor)			REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCk_CS_CFG_CS_FACTOR_MASK;\
													            REG_PRZ_BLOCK_CS_CFG |= factor;

	/* macros of PRZ fine resizer config register */
	#define SET_PRZ_FINE_RESIZE_WORK_MEM_SIZE(line)	REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_WORK_MEM_SIZE_MASK;\
               												REG_PRZ_FINE_RESIZE_CFG |= (line<<16);
	#define SET_PRZ_FINE_RESIZE_OUTPUT_IPP				REG_PRZ_FINE_RESIZE_CFG |= PRZ_FINE_RESIZE_OUTPUT_SEL_BIT;
	#define SET_PRZ_FINE_RESIZE_OUTPUT_IMG_DMA		REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_OUTPUT_SEL_BIT;
	#define ENABLE_PRZ_H_RESIZE_INT						REG_PRZ_FINE_RESIZE_CFG |= PRZ_H_FINE_RESIZE_INT;
	#define DISABLE_PRZ_H_RESIZE_INT						REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_H_FINE_RESIZE_INT;
	#define ENABLE_PRZ_V_RESIZE_INT						REG_PRZ_FINE_RESIZE_CFG |= PRZ_V_FINE_RESIZE_INT;
	#define DISABLE_PRZ_V_RESIZE_INT						REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_V_FINE_RESIZE_INT;

	/* macros of PRZ line buffer size register */
	#define SET_PRZ_FINE_RESIZE_LINE_BUFFER(n)		REG_PRZ_LINE_BUFFER_SIZE = n;

	/* CRZ definition */
	#define CRZ_CONFIG_REG					(CRZ_base + 0x00)
	#define CRZ_CTRL_REG	   				(CRZ_base + 0x04)
	#define CRZ_STATUS_REG					(CRZ_base + 0x08)
	#define CRZ_INT_STATUS_REG				(CRZ_base + 0x0C)
	#define CRZ_SOURCE_IMAGE_SIZE_REG	(CRZ_base + 0x10)
	#define CRZ_TARGET_IMAGE_SIZE_REG	(CRZ_base + 0x14)
	#define CRZ_H_RATIO_REG					(CRZ_base + 0x18)
	#define CRZ_V_RATIO_REG					(CRZ_base + 0x1C)
	#define CRZ_H_RESIDUAL_REG				(CRZ_base + 0x20)
	#define CRZ_V_RESIDUAL_REG				(CRZ_base + 0x24)
	#define CRZ_FINE_RESIZE_CFG_REG		(CRZ_base + 0x40)
	#define CRZ_WORK_MEM_ADDR_REG			(CRZ_base + 0x5C)

	#define REG_CRZ_CONFIG		   		*((volatile unsigned int *) (CRZ_base + 0x00))
	#define REG_CRZ_CTRL			   		*((volatile unsigned int *) (CRZ_base + 0x04))
	#define REG_CRZ_STATUS					*((volatile unsigned int *) (CRZ_base + 0x08))
	#define REG_CRZ_INT_STATUS				*((volatile unsigned int *) (CRZ_base + 0x0C))
	#define REG_CRZ_SOURCE_IMAGE_SIZE	*((volatile unsigned int *) (CRZ_base + 0x10))
	#define REG_CRZ_TARGET_IMAGE_SIZE	*((volatile unsigned int *) (CRZ_base + 0x14))
	#define REG_CRZ_H_RATIO					*((volatile unsigned int *) (CRZ_base + 0x18))
	#define REG_CRZ_V_RATIO					*((volatile unsigned int *) (CRZ_base + 0x1C))
	#define REG_CRZ_H_RESIDUAL				*((volatile unsigned int *) (CRZ_base + 0x20))
	#define REG_CRZ_V_RESIDUAL				*((volatile unsigned int *) (CRZ_base + 0x24))
	#define REG_CRZ_FINE_RESIZE_CFG		*((volatile unsigned int *) (CRZ_base + 0x40))
	#define REG_CRZ_WORK_MEM_ADDR			*((volatile unsigned int *) (CRZ_base + 0x5C))

	/* bit mapping of CRZ config register */
	#define CRZ_CONFIG_LINE_BUF_SEL_BIT	0x00000080
	#define CRZ_CONFIG_PIXEL_SRC_MASK	0x0000000F
	#define CRZ_CONFIG_SRC_SEL_BIT		0x00000020
	#define CRZ_CONFIG_CONT_RUN_BIT		0x00000010

	#define CRZ_CONFIG_PIXEL_SRC_CAMERA_ISP				0
	#define CRZ_CONFIG_PIXEL_SRC_MPEG4_ENCODE_DMA		1
	#define CRZ_CONFIG_PIXEL_SRC_MPEG4_DECODE_DMA		2
	#define CRZ_CONFIG_PIXEL_SRC_IBW_DMA					3
	#define CRZ_CONFIG_PIXEL_SRC_IPP							6

	/* bit mapping of CRZ control register */
	#define CRZ_CTRL_RESET_MASK                 	0x00060000
	#define CRZ_CTRL_ENABLE_MASK                	0x00000006
	#define CRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT		0x00000002
	#define CRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT		0x00000004
	#define CRZ_CTRL_H_FINE_RESIZE_RESET_BIT		0x00020000
	#define CRZ_CTRL_V_FINE_RESIZE_RESET_BIT		0x00040000

	/* bit mapping of CRZ status register */
	#define CRZ_CTRL_H_FINE_RESIZE_BUSY_BIT		0x00000002
	#define CRZ_CTRL_V_FINE_RESIZE_BUSY_BIT		0x00000004

	/* bit mapping of CRZ interrupt status register */
	#define CRZ_CTRL_H_FINE_RESIZE_INT_BIT			0x00000002
	#define CRZ_CTRL_V_FINE_RESIZE_INT_BIT			0x00000004

	/* bit mapping of CRZ source and target size register */
	#define CRZ_IMAGE_SIZE_WIDTH_MASK				0x0000FFFF
	#define CRZ_IMAGE_SIZE_HEIGHT_MASK				0xFFFF0000

	/* bit mapping of CRZ fine resize config register */
	#define CRZ_FINE_RESIZE_WORK_MEM_SIZE_MASK	0xFFFF0000
	#define CRZ_H_FINE_RESIZE_INT						0x00000010
	#define CRZ_V_FINE_RESIZE_INT						0x00000020

	/* macros of CRZ config register */
	#define SET_CRZ_DEDICATED_MEMORY		REG_CRZ_CONFIG |= CRZ_CONFIG_LINE_BUF_SEL_BIT;
	#define SET_CRZ_SHARED_MEMORY			REG_CRZ_CONFIG &= ~CRZ_CONFIG_LINE_BUF_SEL_BIT;
	#define SET_CRZ_PIXEL_BASED_IMAGE	REG_CRZ_CONFIG |= CRZ_CONFIG_SRC_SEL_BIT;
	#define SET_CRZ_BLOCK_BASED_IMAGE	REG_CRZ_CONFIG &= ~CRZ_CONFIG_SRC_SEL_BIT;
	#define SET_CRZ_CONT_RUN_MODE			REG_CRZ_CONFIG |= CRZ_CONFIG_CONT_RUN_BIT;
	#define SET_CRZ_SINGLE_RUN_MODE		REG_CRZ_CONFIG &= ~CRZ_CONFIG_CONT_RUN_BIT;
	#define SET_CRZ_PIXEL_BASED_SRC(n)	REG_CRZ_CONFIG &= ~CRZ_CONFIG_PIXEL_SRC_MASK;\
												 	REG_CRZ_CONFIG |= n;

	/* marcos of CRZ control register */
	#define RESET_CRZ               			REG_CRZ_CTRL=CRZ_CTRL_RESET_MASK;\
                                   			REG_CRZ_CTRL=0;
	#define SET_CRZ_H_FINE_RESIZE_RESET		REG_CRZ_CTRL |= CRZ_CTRL_H_FINE_RESIZE_RESET_BIT;
	#define CLEAR_CRZ_H_FINE_RESIZE_RESET  REG_CRZ_CTRL &= ~CRZ_CTRL_H_FINE_RESIZE_RESET_BIT;
	#define SET_CRZ_V_FINE_RESIZE_RESET		REG_CRZ_CTRL |= CRZ_CTRL_V_FINE_RESIZE_RESET_BIT;
	#define CLEAR_CRZ_V_FINE_RESIZE_RESET  REG_CRZ_CTRL &= ~CRZ_CTRL_V_FINE_RESIZE_RESET_BIT;

	#define ENABLE_CRZ_H_LINE				REG_CRZ_CTRL |= CRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT;
	#define DISABLE_CRZ_H_LINE				REG_CRZ_CTRL &= ~CRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT;
	#define ENABLE_CRZ_V_LINE				REG_CRZ_CTRL |= CRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT;
	#define DISABLE_CRZ_V_LINE				REG_CRZ_CTRL &= ~CRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT;
	#define ENABLE_CRZ  		            REG_CRZ_CTRL = CRZ_CTRL_ENABLE_MASK;

	/* Macros of CRZ status register */
	#define IS_CRZ_H_FINE_RESIZE_BUSY	(REG_CRZ_STATUS & CRZ_CTRL_H_FINE_RESIZE_BUSY_BIT)
	#define IS_CRZ_V_FINE_RESIZE_BUSY	(REG_CRZ_STATUS & CRZ_CTRL_V_FINE_RESIZE_BUSY_BIT)

	/* Macros of CRZ source image size register */
	#define SET_CRZ_SRC_SIZE(width, height)		REG_CRZ_SOURCE_IMAGE_SIZE=(width|(height<<16));

	/* Macros of CRZ target image size register */
	#define SET_CRZ_TARGET_SIZE(width, height)	REG_CRZ_TARGET_IMAGE_SIZE=(width|(height<<16));

	/* macros of CRZ fine resizer config register */
	#define SET_CRZ_FINE_RESIZE_WORK_MEM_SIZE(line)	REG_CRZ_FINE_RESIZE_CFG &= ~CRZ_FINE_RESIZE_WORK_MEM_SIZE_MASK;\
               												REG_CRZ_FINE_RESIZE_CFG |= (line<<16);
	#define ENABLE_CRZ_H_RESIZE_INT						REG_CRZ_FINE_RESIZE_CFG |= CRZ_H_FINE_RESIZE_INT;
	#define DISABLE_CRZ_H_RESIZE_INT						REG_CRZ_FINE_RESIZE_CFG &= ~CRZ_H_FINE_RESIZE_INT;
	#define ENABLE_CRZ_V_RESIZE_INT						REG_CRZ_FINE_RESIZE_CFG |= CRZ_V_FINE_RESIZE_INT;
	#define DISABLE_CRZ_V_RESIZE_INT						REG_CRZ_FINE_RESIZE_CFG &= ~CRZ_V_FINE_RESIZE_INT;

	/* DRZ definition */
	#define DRZ_START_REG					(DRZ_base + 0x00)
	#define DRZ_CONFIG_REG	   			(DRZ_base + 0x04)
	#define DRZ_STATUS_REG					(DRZ_base + 0x08)
	#define DRZ_INT_ACK_REG					(DRZ_base + 0x0C)
	#define DRZ_SOURCE_IMAGE_SIZE_REG	(DRZ_base + 0x10)
	#define DRZ_TARGET_IMAGE_SIZE_REG	(DRZ_base + 0x14)
	#define DRZ_H_RATIO_REG					(DRZ_base + 0x20)
	#define DRZ_V_RATIO_REG					(DRZ_base + 0x24)
	#define DRZ_DEBUG_INFO		      	(DRZ_base + 0x30)

	#define REG_DRZ_START			   	*((volatile unsigned int *) (DRZ_base + 0x00))
	#define REG_DRZ_CONFIG		   		*((volatile unsigned int *) (DRZ_base + 0x04))
	#define REG_DRZ_STATUS					*((volatile unsigned int *) (DRZ_base + 0x08))
	#define REG_DRZ_INT_ACK					*((volatile unsigned int *) (DRZ_base + 0x0C))
	#define REG_DRZ_SOURCE_IMAGE_SIZE	*((volatile unsigned int *) (DRZ_base + 0x10))
	#define REG_DRZ_TARGET_IMAGE_SIZE	*((volatile unsigned int *) (DRZ_base + 0x14))
	#define REG_DRZ_H_RATIO					*((volatile unsigned int *) (DRZ_base + 0x20))
	#define REG_DRZ_V_RATIO					*((volatile unsigned int *) (DRZ_base + 0x24))

	/* bit mapping of DRZ configuration register */
	#define DRZ_CONFIG_PIXEL_SEL_BIT			0x00000010
	#define DRZ_CONFIG_AUTO_RESTART_BIT		0x00000008
	#define DRZ_CONFIG_INT_ENABLE_BIT		0x00000001

	/* bit mapping of DRZ status register */
	#define DRZ_STATUS_BUSY_BIT				0x00010000
	#define DRZ_STATUS_INT_BIT					0x00000001

	/* bit mapping of DRZ interrupt acknowledge register */
	#define DRZ_INT_ACK_BIT						0x00000001

	/* macros of DRZ start register */
	#define START_DRZ								REG_DRZ_START=1;
	#define STOP_DRZ								REG_DRZ_START=0;

	/* macros of DRZ configuration register */
	#define SET_DRZ_SRC_VIDEO_ENCODE_DMA	REG_DRZ_CONFIG &= ~DRZ_CONFIG_PIXEL_SEL_BIT;
	#define SET_DRZ_SRC_IBW3_DMA				REG_DRZ_CONFIG |= DRZ_CONFIG_PIXEL_SEL_BIT;
	#define ENABLE_DRZ_AUTO_RESTART			REG_DRZ_CONFIG |= DRZ_CONFIG_AUTO_RESTART_BIT;
	#define DISABLE_DRZ_AUTO_RESTART			REG_DRZ_CONFIG &= ~DRZ_CONFIG_AUTO_RESTART_BIT;
	#define ENABLE_DRZ_INT						REG_DRZ_CONFIG |= DRZ_CONFIG_INT_ENABLE_BIT;
	#define DISABLE_DRZ_INT						REG_DRZ_CONFIG &= ~DRZ_CONFIG_INT_ENABLE_BIT;

	/* macros of DRZ status register */
	#define DRZ_IS_RUNNING						(REG_DRZ_STATUS & DRZ_STATUS_BUSY_BIT)

	/* macros of DRZ interrupt ACK register */
	#define ACK_DRZ_INT							REG_DRZ_INT_ACK=DRZ_INT_ACK_BIT;
	/*Enum*/
	typedef enum{
   RESZ_SOURCE_MPEG4_ENCODE_DMA,
   RESZ_SOURCE_MPEG4_DECODE_DMA,
   RESZ_SOURCE_IBW3,
   RESZ_SOURCE_IBW4,   
   RESZ_SOURCE_IPP,
   RESZ_SOURCE_ISP,
   RESZ_SOURCE_JPEG_DECODER
   }RESZ_SOURCE_ENUM;   
	/*structure */
	typedef struct{
	RESZ_SOURCE_ENUM image_src;
	kal_bool auto_restart;
	kal_bool int_en;	
	kal_uint16 src_height;
	kal_uint16 src_width;
	kal_uint16 tar_height;
	kal_uint16 tar_width;	
   }RESZ_DRZ_STRUCT;
   
   typedef struct{
	RESZ_SOURCE_ENUM image_src;
	kal_bool dedicate_memory;
	kal_bool continous;
	kal_bool int_en;	
	kal_uint16 src_height;
	kal_uint16 src_width;
	kal_uint16 tar_height;
	kal_uint16 tar_width;	
	kal_uint16 work_mem_line;	
	kal_uint32 work_mem_addr;
   }RESZ_CRZ_STRUCT;
   
   typedef struct{
	RESZ_SOURCE_ENUM image_src;	
	kal_bool         dedicate_memory;
	kal_bool         continous;			
	kal_bool         int_en;	
	kal_bool         output_2_IPP;		
	kal_bool         coarse_en;
	kal_uint16       src_height;
	kal_uint16       src_width;	
	kal_uint16       tar_height;
	kal_uint16       tar_width;	
	kal_uint16       work_mem_line;	
	kal_uint32       work_mem_addr;
	
	kal_uint32       y_line_buff_addr;
	kal_uint32       u_line_buff_addr;
	kal_uint32       v_line_buff_addr;	
	kal_uint32       y_line_buff_size;
	
	kal_uint32       coarse_ratio;
	kal_uint8        y_h_factor;
	kal_uint8        y_v_factor;
	kal_uint8        u_h_factor;
	kal_uint8        u_v_factor;
	kal_uint8        v_h_factor;
	kal_uint8        v_v_factor;	
		
   }RESZ_PRZ_STRUCT;
   
extern void RESZ_CRZConfig(RESZ_CRZ_STRUCT *crz_struct);
extern void RESZ_PRZConfig(RESZ_PRZ_STRUCT *prz_struct);
extern void RESZ_DRZConfig(RESZ_DRZ_STRUCT *drz_struct);
	
#elif defined(DRV_IDP_6225_SERIES)
	#if defined(MT6225)
#define RESZ_BASE				(PRZ_base)
#define RESZ_CFG				(RESZ_BASE+0)
#define RESZ_CON				(RESZ_BASE+0x4)
#define RESZ_STA				(RESZ_BASE+0x8)
#define RESZ_INT				(RESZ_BASE+0xc)
#define RESZ_SRCSZ1			(RESZ_BASE+0x10)
#define RESZ_TARSZ1			(RESZ_BASE+0x14)
#define RESZ_HRATIO1			(RESZ_BASE+0x18)
#define RESZ_VRATIO1			(RESZ_BASE+0x1c)
#define RESZ_HRES1			(RESZ_BASE+0x20)
#define RESZ_VRES1			(RESZ_BASE+0x24)
#define RESZ_FRCFG			(RESZ_BASE+0x40)
#define RESZ_PRWMBASE		(RESZ_BASE+0x5c)

#define RESZ_YUV2RGB	   	(RESZ_BASE+0x80)
#define RESZ_TMBASE_RGB1   (RESZ_BASE+0x84)
#define RESZ_TMBASE_RGB2   (RESZ_BASE+0x88)
#define RESZ_INFO0		   (RESZ_BASE+0xb0)
#define RESZ_INFO1		   (RESZ_BASE+0xb4)
#define RESZ_INFO2		   (RESZ_BASE+0xb8)
#define RESZ_INFO3		   (RESZ_BASE+0xbc)
#define RESZ_INFO4		   (RESZ_BASE+0xc0)
#define RESZ_INFO5		   (RESZ_BASE+0xc4)
#define RESZ_TMBASE_Y		(RESZ_BASE+0xd0)
#define RESZ_TMBASE_U		(RESZ_BASE+0xd4)
#define RESZ_TMBASE_V		(RESZ_BASE+0xd8)


#define REG_RESZ_CFG				*((volatile unsigned int *) (RESZ_BASE+0))
#define REG_RESZ_CON				*((volatile unsigned int *) (RESZ_BASE+0x4))
#define REG_RESZ_STA				*((volatile unsigned int *) (RESZ_BASE+0x8))
#define REG_RESZ_INT				*((volatile unsigned int *) (RESZ_BASE+0xc))
#define REG_RESZ_SRCSZ1			*((volatile unsigned int *) (RESZ_BASE+0x10))
#define REG_RESZ_TARSZ1			*((volatile unsigned int *) (RESZ_BASE+0x14))
#define REG_RESZ_HRATIO1		*((volatile unsigned int *) (RESZ_BASE+0x18))
#define REG_RESZ_VRATIO1		*((volatile unsigned int *) (RESZ_BASE+0x1c))
#define REG_RESZ_HRES1			*((volatile unsigned int *) (RESZ_BASE+0x20))
#define REG_RESZ_VRES1			*((volatile unsigned int *) (RESZ_BASE+0x24))
#define REG_RESZ_FRCFG			*((volatile unsigned int *) (RESZ_BASE+0x40))
#define REG_RESZ_PRWMBASE		*((volatile unsigned int *) (RESZ_BASE+0x5c))
                                                                           
#define REG_RESZ_YUV2RGB	   *((volatile unsigned int *) (RESZ_BASE+0x80))
#define REG_RESZ_TMBASE_RGB1  *((volatile unsigned int *) (RESZ_BASE+0x84))
#define REG_RESZ_TMBASE_RGB2  *((volatile unsigned int *) (RESZ_BASE+0x88))
#define REG_RESZ_INFO0		   *((volatile unsigned int *) (RESZ_BASE+0xb0))
#define REG_RESZ_INFO1		   *((volatile unsigned int *) (RESZ_BASE+0xb4))
#define REG_RESZ_INFO2		   *((volatile unsigned int *) (RESZ_BASE+0xb8))
#define REG_RESZ_INFO3		   *((volatile unsigned int *) (RESZ_BASE+0xbc))
#define REG_RESZ_INFO4		   *((volatile unsigned int *) (RESZ_BASE+0xc0))
#define REG_RESZ_INFO5		   *((volatile unsigned int *) (RESZ_BASE+0xc4))
#define REG_RESZ_TMBASE_Y		*((volatile unsigned int *) (RESZ_BASE+0xd0))
#define REG_RESZ_TMBASE_U		*((volatile unsigned int *) (RESZ_BASE+0xd4))
#define REG_RESZ_TMBASE_V		*((volatile unsigned int *) (RESZ_BASE+0xd8))                                                                                                                                                                                
                              
/*RESZ_CFG*/                  
#define RESZ_CFG_PELSRC1	0x0000000f
#define RESZ_CFG_PCON		0x00000010
#define RESZ_CFG_PSEL		0x00000020
                              
/*RESZ_CON*/                  
#define RESZ_CON_PELHRENA			0x00000002
#define RESZ_CON_PELVRENA			0x00000004
#define RESZ_CON_OUTENA	   		0x00000008
#define RESZ_CON_PELHRRST			0x00020000
#define RESZ_CON_PELVRRST			0x00040000
#define RESZ_CON_OUTRST		   	0x00080000
/*RESZ_STA*/
#define RESZ_STA_PELHRBUSY			0x00000002
#define RESZ_STA_PELVRBUSY			0x00000004
#define RESZ_STA_OUTBUSY			0x00000008
/*RESZ_INT*/
#define RESZ_INT_PELHRINT			0x00000002
#define RESZ_INT_PELVRINT			0x00000004
#define RESZ_INT_Y2RINT  			0x00000008
/*RESZ_FRCFG*/
#define RESZ_FRCFG_VRSS				0x00000001
#define RESZ_FRCFG_HRINTEN			0x00000010
#define RESZ_FRCFG_VRINTEN			0x00000020
#define RESZ_FRCFG_PCSF1			0x00000300
#define RESZ_FRCFG_WMSZ_MASK	   0x3ff0000
#define RESZ_FRCFG_WMSZ_SHIFT	   16
#define RESZ_FRCFG_HRINT         0x10   
#define RESZ_FRCFG_VRINT         0x20


/*RESZ_YUB2RGB*/
#define RESZ_YUB2RGB_ENABLE_BIT	      1
#define RESZ_YUB2RGB_INT_ENABLE_BIT	   0x8000

#define RESZ_HRES1_MAX				2046
#define RESZ_VRES1_MAX				2046
  
#define RESZ_H_RATIO_SHIFT_BITS  17
#define RESZ_V_RATIO_SHIFT_BITS  17
   
#define API
#define RESZ_PXL_EN			0xe
#define RESZ_PXL_RST			0xe0000
#define RESZ_CTRL_H_FINE_RESIZE_RESET_BIT  0x20000
#define RESZ_CTRL_V_FINE_RESIZE_RESET_BIT  0x40000
#define RESZ_CTRL_RGB2YUB_RESET_BIT        0x80000
#define RESZ_CTRL_H_FINE_RESIZE_ENABLE_BIT 0x2 
#define RESZ_CTRL_V_FINE_RESIZE_ENABLE_BIT 0x4
#define RESZ_CTRL_RGB2YUB_ENABLE_BIT       0x8

#define IDP_VR_MAXIMUM_RESZ_WM_SIZE (240*4*3)
#define IDP_CP_MAXIMUM_RESZ_WM_SIZE (1280*4*3)
#define IDP_IC_MAXIMUM_RESZ_WM_SIZE (1280*4*3)

/*error code*/
#define NO_ERROR							0
#define RESZ_ERR_INVALID_SIZE			1


/*macro*/

#define RESZ_SET_WMBASE_PXL(a) 	   DRV_WriteReg32(RESZ_PRWMBASE, (a))
#define RESZ_START()                DRV_WriteReg32(RESZ_CON, RESZ_PXL_EN)      
#define RESZ_STOP()                 DRV_WriteReg32(RESZ_CON, RESZ_PXL_RST)      
#define RESZ_RGB_2_YUB_ENABLE()     REG_RESZ_YUV2RGB&=~RESZ_YUB2RGB_ENABLE_BIT
#define RESZ_RGB_2_YUB_DISABLE()    REG_RESZ_YUV2RGB|=RESZ_YUB2RGB_ENABLE_BIT
#define RESZ_HR_INT_ENABLE()        REG_RESZ_FRCFG|=RESZ_FRCFG_HRINT
#define RESZ_HR_INT_DISABLE()        REG_RESZ_FRCFG&=~RESZ_FRCFG_HRINT
#define RESZ_VR_INT_ENABLE()        REG_RESZ_FRCFG|=RESZ_FRCFG_VRINT
#define RESZ_VR_INT_DISABLE()        REG_RESZ_FRCFG&=~RESZ_FRCFG_VRINT
#define RESZ_RGB2YUV_INT_ENABLE()   REG_RESZ_YUV2RGB|=RESZ_YUB2RGB_INT_ENABLE_BIT
#define RESZ_RGB2YUV_INT_DISABLE()   REG_RESZ_YUV2RGB&=~RESZ_YUB2RGB_INT_ENABLE_BIT
 
#define SET_RESZ_SRC_SIZE(width, height)		REG_RESZ_SRCSZ1=(width|(height<<16))	
#define SET_RESZ_TARGET_SIZE(width, height)	REG_RESZ_TARSZ1=(width|(height<<16))

#define SET_RESZ_FINE_RESIZE_WORK_MEM_SIZE(line)	REG_RESZ_FRCFG &= ~RESZ_FRCFG_WMSZ_MASK;\
               												REG_RESZ_FRCFG |= (line<<16);
               												
#define SET_RESZ_COARSE_RESIZE_1_2	      REG_RESZ_FRCFG &=RESZ_FRCFG_PCSF1;\
                                          REG_RESZ_FRCFG |=0x100;
#define SET_RESZ_COARSE_RESIZE_1_4	      REG_RESZ_FRCFG &=RESZ_FRCFG_PCSF1;\
                                          REG_RESZ_FRCFG |=0x200;
#define SET_RESZ_COARSE_RESIZE_1_8	      REG_RESZ_FRCFG &=RESZ_FRCFG_PCSF1;\
                                          REG_RESZ_FRCFG |=0x300;                                          
#define SET_RESZ_COARSE_RESIZE_NONE	      REG_RESZ_FRCFG &=~RESZ_FRCFG_PCSF1;                  												
/* marcos of CRZ control register */
#define RESET_RESZ()          			   REG_RESZ_CON=RESZ_PXL_RST;\
                                			   REG_RESZ_CON=0;
#define SET_RESZ_H_FINE_RESIZE_RESET()	   REG_RESZ_CON |= RESZ_CTRL_H_FINE_RESIZE_RESET_BIT;
#define CLEAR_RESZ_H_FINE_RESIZE_RESET()  REG_RESZ_CON &= ~RESZ_CTRL_H_FINE_RESIZE_RESET_BIT;
#define SET_RESZ_V_FINE_RESIZE_RESET()	   REG_RESZ_CON |= RESZ_CTRL_V_FINE_RESIZE_RESET_BIT;
#define CLEAR_RESZ_V_FINE_RESIZE_RESET()  REG_RESZ_CON &= ~RESZ_CTRL_V_FINE_RESIZE_RESET_BIT;
#define SET_RESZ_RGB2YUB_RESET()	         REG_RESZ_CON |= RESZ_CTRL_RGB2YUB_RESET_BIT;
#define CLEAR_RESZ_RGB2YUB_RESET()        REG_RESZ_CON &= ~RESZ_CTRL_RGB2YUB_RESET_BIT;

#define ENABLE_RESZ_H_LINE()				   REG_RESZ_CON |= RESZ_CTRL_H_FINE_RESIZE_ENABLE_BIT;
#define DISABLE_RESZ_H_LINE()				   REG_RESZ_CON &= ~RESZ_CTRL_H_FINE_RESIZE_ENABLE_BIT;
#define ENABLE_RESZ_V_LINE()				   REG_RESZ_CON |= RESZ_CTRL_V_FINE_RESIZE_ENABLE_BIT;
#define DISABLE_RESZ_V_LINE()				   REG_RESZ_CON &= ~RESZ_CTRL_V_FINE_RESIZE_ENABLE_BIT;
#define ENABLE_RESZ_RGB2YUB()				   REG_RESZ_CON |= RESZ_CTRL_RGB2YUB_ENABLE_BIT;
#define DISABLE_RESZ_RGB2YUB()		      REG_RESZ_CON &= ~RESZ_CTRL_RGB2YUB_ENABLE_BIT;
		/*the above are for 6225*/  
	#elif defined(MT6235)
		/* RESZ definition */
		#define RESZ_CONFIG				  (RESZ_base + 0x00)
		#define RESZ_CTRL	   			  (RESZ_base + 0x04)
		#define RESZ_STA				    (RESZ_base + 0x08)
		#define RESZ_INT_STATUS			  (RESZ_base + 0x0C)
		#define RESZ_SOURCE_IMAGE_SIZE  (RESZ_base + 0x10)
		#define RESZ_TARGET_IMAGE_SIZE  (RESZ_base + 0x14)
		#define RESZ_H_RATIO				  (RESZ_base + 0x18)
		#define RESZ_V_RATIO			  	  (RESZ_base + 0x1C)
		#define RESZ_GMC				     (RESZ_base + 0x3C)/*6235*/
	   #define RESZ_FRCG               (RESZ_base + 0x40)
	   #define RESZ_Y_BASE             (RESZ_base + 0x44)/*6235*/
	   #define RESZ_U_BASE             (RESZ_base + 0x48)/*6235*/
	   #define RESZ_V_BASE             (RESZ_base + 0x4C)/*6235*/
	   #define RESZ_RGB_BASE1          (RESZ_base + 0x84)/*6235*/
	   #define RESZ_RGB_BASE2          (RESZ_base + 0x88)/*6235*/
	   #define RESZ_TMBASE_RGB1          (RESZ_base + 0x84)/*6235*/
	   #define RESZ_TMBASE_RGB2          (RESZ_base + 0x88)/*6235*/
	
		#define REG_RESZ_CONFIG            *((volatile unsigned int *)(RESZ_CONFIG))
		#define REG_RESZ_CTRL              *((volatile unsigned int *)(RESZ_CTRL))
		#define REG_RESZ_STA            *((volatile unsigned int *)(RESZ_STA))
		#define REG_RESZ_INT_STATUS        *((volatile unsigned int *)(RESZ_INT_STATUS))
		#define REG_RESZ_SOURCE_IMAGE_SIZE *((volatile unsigned int *)(RESZ_SOURCE_IMAGE_SIZE))
		#define REG_RESZ_TARGET_IMAGE_SIZE *((volatile unsigned int *)(RESZ_TARGET_IMAGE_SIZE))
		#define REG_RESZ_H_RATIO           *((volatile unsigned int *)(RESZ_H_RATIO))
		#define REG_RESZ_V_RATIO           *((volatile unsigned int *)(RESZ_V_RATIO))
		#define REG_RESZ_GMC               *((volatile unsigned int *)(RESZ_GMC))/*6235*/
		#define REG_RESZ_FRCG              *((volatile unsigned int *)(RESZ_FRCG))
		#define REG_RESZ_Y_BASE            *((volatile unsigned int *)(RESZ_Y_BASE))/*6235*/
		#define REG_RESZ_U_BASE            *((volatile unsigned int *)(RESZ_U_BASE))/*6235*/
		#define REG_RESZ_V_BASE            *((volatile unsigned int *)(RESZ_V_BASE))/*6235*/
		#define REG_RESZ_RGB_BASE1         *((volatile unsigned int *)(RESZ_RGB_BASE1))/*6235*/
		#define REG_RESZ_RGB_BASE2         *((volatile unsigned int *)(RESZ_RGB_BASE2))/*6235*/
		
		
		#define RESZ_CONFIG_OUTPUT_FMT_MASK  0x00000030
		#define RESZ_CONFIG_CONT_RUN_BIT     0x00000100
		#define RESZ_CONFIG_LINE_BUF_SEL_BIT 0x00000200
		#define RESZ_CONFIG_FRAME_START_INT  0x00000400
		#define RESZ_CONFIG_FRAME_END_INT    0x00000800
		#define RESZ_CONFIG_ECV              0x00001000
		#define RESZ_CONFIG_VSRSTEN          0x00002000
		#define RESZ_CONFIG_NORFDB           0x00004000
		#define RESZ_CONFIG_NORRGBDB         0x00008000/*6235*/
		#define RESZ_CTRL_LBMAX_MASK         0x03ff0000
		
		#define RESZ_UV_MASK 0X0000FFFF
		#define RESZ_GMCPIXEL_MASK 0XFFFF0000
		
		/* bit mapping of RESZ control register */
		#define RESZ_CTRL_RESET_MASK         0x00010000
		#define RESZ_CTRL_ENABLE_MASK        0x00000001
		#define RESZ_FRAME_END_INT_BIT  0x1
		#define RESZ_FRAME_START_INT_BIT  0x2
		
		
		#define RESZ_H_RATIO_SHIFT_BITS  20
		
		#define RESZ_V_RATIO_SHIFT_BITS  20
			
			/* macros of RESZ config register */
		
		#define SET_RESZ_OUTPUT_FMT(fmt)                                 \
		  do {                                          \
		    REG_RESZ_CONFIG &= ~RESZ_CONFIG_OUTPUT_FMT_MASK;         \
		    REG_RESZ_CONFIG |= (fmt<<4);                   \
		  } while(0)
		
		#define SET_RESZ_CONT_RUN_MODE()                                 \
		  do { REG_RESZ_CONFIG |= RESZ_CONFIG_CONT_RUN_BIT; } while(0)
		
		#define SET_RESZ_SINGLE_RUN_MODE()                               \
		  do { REG_RESZ_CONFIG &= ~RESZ_CONFIG_CONT_RUN_BIT; } while(0)
		  
		#define SET_RESZ_DEDICATED_MEMORY()                                  \
		  do { REG_RESZ_CONFIG |= RESZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)
		
		#define SET_RESZ_SHARED_MEMORY()                                     \
		  do { REG_RESZ_CONFIG &= ~RESZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)
		
		#define ENABLE_RESZ_FS_INT()                                \
		  do {                                                  \
		    REG_RESZ_CONFIG |= RESZ_CONFIG_FRAME_START_INT;                   \
		  } while(0)
			
		#define DISABLE_RESZ_FS_INT()                               \
		  do {                                                  \
		    REG_RESZ_CONFIG &= ~RESZ_CONFIG_FRAME_START_INT;                  \
		  } while(0)
		  
		#define ENABLE_RESZ_FE_INT()                                \
		  do {                                                  \
		    REG_RESZ_CONFIG |= RESZ_CONFIG_FRAME_END_INT;                   \
		  } while(0)
			
		#define DISABLE_RESZ_FE_INT()                               \
		  do {                                                  \
		    REG_RESZ_CONFIG &= ~RESZ_CONFIG_FRAME_END_INT;                  \
		  } while(0)  
		  
		#define SET_RESZ_ECV(ecv)                  \
		  do {                                          \
		    REG_RESZ_CONFIG &= ~RESZ_CONFIG_ECV;         \
		    REG_RESZ_CONFIG |= (ecv<<12);                   \
		  } while(0)
		
		
		#define ENABLE_RESZ_VSYNC_RST()                                \
		  do {                                                  \
		    REG_RESZ_CONFIG |= RESZ_CONFIG_VSRSTEN;                   \
		  } while(0)
			
		#define DISABLE_RESZ_VSYNC_RST()                               \
		  do {                                                  \
		    REG_RESZ_CONFIG &= ~RESZ_CONFIG_VSRSTEN;                  \
		  } while(0)  
		
		#define ENABLE_RESZ_REG_DOUBLE_BUF()                                \
		  do {                                                  \
		    REG_RESZ_CONFIG &= ~RESZ_CONFIG_NORFDB;                   \
		  } while(0)
			
		#define DISABLE_RESZ_REG_DOUBLE_BU()                               \
		  do {                                                  \
		    REG_RESZ_CONFIG |=RESZ_CONFIG_NORFDB;                  \
		  } while(0)  
		
		#define ENABLE_RESZ_RGB_DOUBLE_BUF()                                \
		  do {                                                  \
		    REG_RESZ_CONFIG &= ~RESZ_CONFIG_NORRGBDB;                   \
		  } while(0)
			
		#define DISABLE_RESZ_RGB_DOUBLE_BU()                               \
		  do {                                                  \
		    REG_RESZ_CONFIG |= RESZ_CONFIG_NORRGBDB;                  \
		  } while(0)  
		    
		  
		#define SET_RESZ_LBMAX(n)                        \
		  do {                                          \
		    REG_RESZ_CONFIG &= ~RESZ_CTRL_LBMAX_MASK;     \
		    REG_RESZ_CONFIG |= (n << 16);                \
		  } while(0)
		
		
		#define SET_RESZ_UV_SEL(usel, vsel)                  \
		  do {                                          \
		    REG_RESZ_FRCG &= ~RESZ_UV_MASK;         \
		    REG_RESZ_FRCG = ((usel<<8)|(vsel));                   \
		  } while(0)
		  
		#define SET_RESZ_GMCPIXEL(num)                  \
		  do {                                          \
		    REG_RESZ_FRCG &= ~RESZ_GMCPIXEL_MASK;         \
		    REG_RESZ_FRCG = (num<<16);                   \
		  } while(0)
		   
			/* marcos of RESZ control register */
		#define RESET_RESZ()                               \
		  do {                                            \
		    REG_RESZ_CTRL = RESZ_CTRL_RESET_MASK;           \
		    REG_RESZ_CTRL = 0;                             \
		  } while(0)
		
		#define ENABLE_RESZ()                            \
		  do {                                          \
		    REG_RESZ_CTRL = RESZ_CTRL_ENABLE_MASK;        \
		  } while(0)
		
		#define RESZ_START()                            \
		  do {                                          \
		    REG_RESZ_CTRL = RESZ_CTRL_ENABLE_MASK;        \
		  } while(0)
			/* Macros of RESZ status register */
		#define RESZ_STATUS_INPUT_BUSY_BIT  (1 << 0)
		#define RESZ_STATUS_OUTPUT_BUSY_BIT (1 << 1)
		
		#define IS_RESZ_INPUT_BUSY  (REG_RESZ_STA & RESZ_STATUS_INPUT_BUSY_BIT)
		#define IS_RESZ_OUTPUT_BUSY (REG_RESZ_STA & RESZ_STATUS_OUTPUT_BUSY_BIT)
		
		
			/* Macros of RESZ source image size register */
		#define SET_RESZ_SRC_SIZE(width, height) \
		  do { REG_RESZ_SOURCE_IMAGE_SIZE = (width | (height << 16)); } while(0)
		
			/* Macros of RESZ target image size register */
		#define SET_RESZ_TARGET_SIZE(width, height) \
		  do { REG_RESZ_TARGET_IMAGE_SIZE = (width | (height << 16)); } while(0)
		
	#endif /*MT6235*/ 
// NOte: block mode stands for JPEG decoder
typedef enum{
	SRC_CAMERA = 0,
	SRC_MPEG4 = 1,
	SRC_PNG = 2,
	SRC_GIF = 3,
	SRC_MEM = 4	
}RESZ_PXL_SRC_ENUM;

typedef enum{
	RESZ_INIT,
	RESZ_READY,
	RESZ_BUSY
}RESZ_STATE_ENUM;

typedef enum{
   RESZ_COARSE_NONE,
	RESZ_COARSE_1_2,
	RESZ_COARSE_1_4,
	RESZ_COARSE_1_8	
}RESZ_COARSE_ENUM;

typedef struct{
		
	/* RGB565 base address*/
	kal_uint32 rgb_tar_base1;
	kal_uint32 rgb_tar_base2;

   /* YUV420 base address*/
   kal_uint32 y_tar_base;
	kal_uint32 u_tar_base;
	kal_uint32 v_tar_base;
	
	/* base address of working memory*/
	kal_uint32 wmbase;
	kal_uint32 wmsize;
		
	kal_bool continous;
	kal_bool yuv_to_rgb;
	kal_uint32 source_width;
	kal_uint32 source_height;
	kal_uint32 target_width;
	kal_uint32 target_height;	
	kal_uint16 int_en; 
	RESZ_COARSE_ENUM   coarse_resize;	   
	
	void (*resize_cb) (kal_uint8 return_code);
					
}RESZ_CFG_STRUCT;

typedef struct{
	MMDI_SCENERIO_ID owner;
	RESZ_STATE_ENUM state;
	RESZ_CFG_STRUCT cfg;
}RESZ_DCB_STRUCT;


/*extern function*/  
kal_int32 RESZ_Init(void);
kal_int32 RESZ_Open(MMDI_SCENERIO_ID owner);
kal_int32 RESZ_Close(MMDI_SCENERIO_ID owner);
void RESZ_Config(RESZ_CFG_STRUCT *resize_struct);
void RESZ_zoom(kal_uint32 src_w, kal_uint32 src_h, 
                 kal_uint32 tar_w, kal_uint32 tar_h);	
kal_bool RESZ_is_buffer_release(kal_uint32 buffer);         
kal_bool mjpeg_get_encode_buffer(kal_uint32 *buf);        
#endif/*MT6228, MT6229, MT6230*/
#endif //RESIZER_H
#endif //RESIZER_H
