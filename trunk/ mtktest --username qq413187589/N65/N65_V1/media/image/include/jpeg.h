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
 *	jpeg.h
 *
 * Project:
 * --------
 *   MT6218B, MT6219, MT6217
 *
 * Description:
 * ------------
 *   This file is intends for JPEG codec driver.
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JPEG_H
#define _JPEG_H

#include "drv_features.h"

#if(defined(MT6217)||defined(MT6218B))
 #define JPEG_DRV_V1 
#elif(defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
 #define JPEG_DRV_V2
#elif(defined(MT6228)||defined(MT6229)||defined(MT6230))
 #define JPEG_DRV_V3
#endif

#if (defined(DRV_JPG_DEC_SUPPORT)||defined(DRV_JPG_ENC_SUPPORT))

#if(defined (DRV_JPG_SW_DEC_SUPPORT))
 #include "image.h"
 #include "jpeg_sw.h"
 #include "sw_jpeg_decoder.h"
#endif

//#if (defined(MT6217)||(defined(MT6218B)) || (defined(MT6219))||defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6228)||defined(MT6229))
#if(defined(__MTK_TARGET__))
#include "reg_base.h"
#endif
#include "lcd_if.h"
typedef enum
{
	JPEG_DECODER_IDLE_STATE=0,
	JPEG_DECODER_STANDBY_STATE,
	JPEG_DECODER_DECODING_STATE
}	JPEG_DECODER_STATE_ENUM;

typedef enum
{
	JPEG_DECODER_RETRY_DISABLE=0,
	JPEG_DECODER_RETRY_THUMBNAIL
}JPEG_DECODER_RETRY_ENUM;

#define JPEG_DECODER_MODULE		0

#define JPEG_DECODE_BREAK_INT_EVENT		0x01

#if (defined(DRV_JPG_HW_ENC_SUPPORT))
	#define JPEG_ENCODE_INT_EVENT			0x02

	#define JPEG_ENCODER_MODULE	1
	#include "visual_comm.h"
	#include "imgproc.h"
	#include "imgdma.h"

	typedef enum
	{
		JPEG_ENCODER_IDLE_STATE=0,
		JPEG_ENCODER_STANDBY_STATE,
		JPEG_ENCODER_ENCODING_STATE
	}	JPEG_ENCODER_STATE_ENUM;
	#define JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER		32
#elif(defined(DRV_JPG_SW_DEC_SUPPORT)) //temp solution of MT6225 DVT
/*
	#include "imgdma.h"
	typedef enum
	{
		JPEG_ENCODER_IDLE_STATE=0,
		JPEG_ENCODER_STANDBY_STATE,
		JPEG_ENCODER_ENCODING_STATE
	}	JPEG_ENCODER_STATE_ENUM;
	#define JPEG_ENCODER_IDMA_LINE_BUFFER_NUMBER		32
*/
#endif

#define RESIZER_WORKING_MEM_LINE_NUMBER		4
#define JPEG_PROGRESSIVE_BUFFER_LINE_NUMBER	16

#if (defined(MT6218B))
	#define MAX_RESIZER_INPUT_WIDTH	320
	#define MAX_RESIZER_INPUT_HEIGHT	320
#elif (defined(MT6217)||defined(DRV_JPG_DEC_19_SERIES))
	#define MAX_RESIZER_INPUT_WIDTH	320
	#define MAX_RESIZER_INPUT_HEIGHT	320
#elif (defined(DRV_JPG_DEC_28_SERIES))
	#define MAX_RESIZER_INPUT_WIDTH	640
	#define MAX_RESIZER_INPUT_HEIGHT	640
#endif

#define JPEG_DECODER_JPEG_FILE_START_ADDR_REG			(JPEG_CODEC_base + 0x00)
#define JPEG_DECODER_TABLE_ADDR_REG							(JPEG_CODEC_base + 0x04)
#define JPEG_DECODER_SAMPLE_FACTOR_REG						(JPEG_CODEC_base + 0x08)
#define JPEG_DECODER_COMPENT_ID_REG							(JPEG_CODEC_base + 0x0C)
#define JPEG_DECODER_TOTAL_MCU_NUMBER_REG					(JPEG_CODEC_base + 0x10)
#define JPEG_DECODER_MCU_NUMBER_PER_MCU_ROW_REG 		(JPEG_CODEC_base + 0x14)
#define JPEG_DECODER_COMP0_DU_NUM_PER_MCU_ROW_REG		(JPEG_CODEC_base + 0x18)
#define JPEG_DECODER_COMP1_DU_NUM_PER_MCU_ROW_REG		(JPEG_CODEC_base + 0x1C)
#define JPEG_DECODER_COMP2_DU_NUM_PER_MCU_ROW_REG		(JPEG_CODEC_base + 0x20)
#define JPEG_DECODER_COMP0_DATA_UNIT_NUMBER_REG			(JPEG_CODEC_base + 0x24)
#define JPEG_DECODER_COMP1_DATA_UNIT_NUMBER_REG			(JPEG_CODEC_base + 0x28)
#define JPEG_DECODER_COMP2_DATA_UNIT_NUMBER_REG			(JPEG_CODEC_base + 0x2C)
#define JPEG_DECODER_COMP0_PROG_START_ADDR_REG			(JPEG_CODEC_base + 0x30)
#define JPEG_DECODER_COMP1_PROG_START_ADDR_REG			(JPEG_CODEC_base + 0x34)
#define JPEG_DECODER_COMP2_PROG_START_ADDR_REG			(JPEG_CODEC_base + 0x38)
#define JPEG_DECODER_CTRL_REG									(JPEG_CODEC_base + 0x3C)
#define JPEG_DECODER_TRIGGER_REG								(JPEG_CODEC_base + 0x40)
#define JPEG_DECODER_ABORT_REG								(JPEG_CODEC_base + 0x44)
#define JEPG_DECODER_STOP_ADDR_REG							(JPEG_CODEC_base + 0x48)
#define JPEG_DECODER_FILE_SIZE_REG							(JPEG_CODEC_base + 0x4C)
#define JEPG_DECODER_INTERLEAVE_FIRST_MCU_INDEX_REG	(JPEG_CODEC_base + 0x50)
#define JEPG_DECODER_INTERLEAVE_LAST_MCU_INDEX_REG		(JPEG_CODEC_base + 0x54)
#define JEPG_DECODER_COMP0_FIRST_MCU_INDEX_REG			(JPEG_CODEC_base + 0x58)
#define JEPG_DECODER_COMP0_LAST_MCU_INDEX_REG			(JPEG_CODEC_base + 0x5C)
#define JEPG_DECODER_COMP1_FIRST_MCU_INDEX_REG			(JPEG_CODEC_base + 0x60)
#define JEPG_DECODER_COMP1_LAST_MCU_INDEX_REG			(JPEG_CODEC_base + 0x64)
#define JEPG_DECODER_COMP2_FIRST_MCU_INDEX_REG			(JPEG_CODEC_base + 0x68)
#define JEPG_DECODER_COMP2_LAST_MCU_INDEX_REG			(JPEG_CODEC_base + 0x6C)
#define JPEG_DECODER_Q_TABLE_ID_REG							(JPEG_CODEC_base + 0x70)
#define JPEG_DECODER_INT_STATUS_REG							(JPEG_CODEC_base + 0x74)
#define JPEG_DECODER_DMA_ADDR_REG							(JPEG_CODEC_base + 0x78)

#define REG_JPEG_DECODER_JPEG_FILE_START_ADDR			*((volatile unsigned int *) (JPEG_CODEC_base + 0x00))
#define REG_JPEG_DECODER_TABLE_ADDR							*((volatile unsigned int *) (JPEG_CODEC_base + 0x04))
#define REG_JPEG_DECODER_SAMPLE_FACTOR						*((volatile unsigned int *) (JPEG_CODEC_base + 0x08))
#define REG_JPEG_DECODER_COMPENT_ID							*((volatile unsigned int *) (JPEG_CODEC_base + 0x0C))
#define REG_JPEG_DECODER_TOTAL_MCU_NUMBER					*((volatile unsigned int *) (JPEG_CODEC_base + 0x10))
#define REG_JPEG_DECODER_MCU_NUMBER_PER_MCU_ROW 		*((volatile unsigned int *) (JPEG_CODEC_base + 0x14))
#define REG_JPEG_DECODER_COMP0_DU_NUM_PER_MCU_ROW		*((volatile unsigned int *) (JPEG_CODEC_base + 0x18))
#define REG_JPEG_DECODER_COMP1_DU_NUM_PER_MCU_ROW		*((volatile unsigned int *) (JPEG_CODEC_base + 0x1C))
#define REG_JPEG_DECODER_COMP2_DU_NUM_PER_MCU_ROW		*((volatile unsigned int *) (JPEG_CODEC_base + 0x20))
#define REG_JPEG_DECODER_COMP0_DATA_UNIT_NUMBER			*((volatile unsigned int *) (JPEG_CODEC_base + 0x24))
#define REG_JPEG_DECODER_COMP1_DATA_UNIT_NUMBER			*((volatile unsigned int *) (JPEG_CODEC_base + 0x28))
#define REG_JPEG_DECODER_COMP2_DATA_UNIT_NUMBER			*((volatile unsigned int *) (JPEG_CODEC_base + 0x2C))
#define REG_JPEG_DECODER_COMP0_PROG_START_ADDR			*((volatile unsigned int *) (JPEG_CODEC_base + 0x30))
#define REG_JPEG_DECODER_COMP1_PROG_START_ADDR			*((volatile unsigned int *) (JPEG_CODEC_base + 0x34))
#define REG_JPEG_DECODER_COMP2_PROG_START_ADDR			*((volatile unsigned int *) (JPEG_CODEC_base + 0x38))
#define REG_JPEG_DECODER_CTRL									*((volatile unsigned int *) (JPEG_CODEC_base + 0x3C))
#define REG_JPEG_DECODER_TRIGGER								*((volatile unsigned int *) (JPEG_CODEC_base + 0x40))
#define REG_JPEG_DECODER_ABORT								*((volatile unsigned int *) (JPEG_CODEC_base + 0x44))
#define REG_JEPG_DECODER_STOP_ADDR							*((volatile unsigned int *) (JPEG_CODEC_base + 0x48))
#define REG_JPEG_DECODER_FILE_SIZE							*((volatile unsigned int *) (JPEG_CODEC_base + 0x4C))
#define REG_JEPG_DECODER_INTERLEAVE_FIRST_MCU_INDEX	*((volatile unsigned int *) (JPEG_CODEC_base + 0x50))
#define REG_JEPG_DECODER_INTERLEAVE_LAST_MCU_INDEX		*((volatile unsigned int *) (JPEG_CODEC_base + 0x54))
#define REG_JEPG_DECODER_COMP0_FIRST_MCU_INDEX			*((volatile unsigned int *) (JPEG_CODEC_base + 0x58))
#define REG_JEPG_DECODER_COMP0_LAST_MCU_INDEX			*((volatile unsigned int *) (JPEG_CODEC_base + 0x5C))
#define REG_JEPG_DECODER_COMP1_FIRST_MCU_INDEX			*((volatile unsigned int *) (JPEG_CODEC_base + 0x60))
#define REG_JEPG_DECODER_COMP1_LAST_MCU_INDEX			*((volatile unsigned int *) (JPEG_CODEC_base + 0x64))
#define REG_JEPG_DECODER_COMP2_FIRST_MCU_INDEX			*((volatile unsigned int *) (JPEG_CODEC_base + 0x68))
#define REG_JEPG_DECODER_COMP2_LAST_MCU_INDEX			*((volatile unsigned int *) (JPEG_CODEC_base + 0x6C))
#define REG_JPEG_DECODER_Q_TABLE_ID							*((volatile unsigned int *) (JPEG_CODEC_base + 0x70))
#define REG_JPEG_DECODER_INT_STATUS							*((volatile unsigned int *) (JPEG_CODEC_base + 0x74))
#define REG_JPEG_DECODER_DMA_ADDR							*((volatile unsigned int *) (JPEG_CODEC_base + 0x78))

/* bit mapping of JPEG sample factore register */
#define JPEG_SAMPLE_FACTOR_H_SF1_MASK	0x0C00
#define JPEG_SAMPLE_FACTOR_V_SF1_MASK	0x0300
#define JPEG_SAMPLE_FACTOR_H_SF2_MASK	0x00C0
#define JPEG_SAMPLE_FACTOR_V_SF2_MASK	0x0030
#define JPEG_SAMPLE_FACTOR_H_SF3_MASK	0x000C
#define JPEG_SAMPLE_FACTOR_V_SF3_MASK	0x0003

#define SAMPLE_FACTOR1	0x00
#define SAMPLE_FACTOR2	0x01
#define SAMPLE_FACTOR3	0x03

/* bit mapping of JPEG component ID register */
#define JPEG_COMPONENT_ID1_MASK		0xFF000000
#define JPEG_COMPONENT_ID2_MASK		0x00FF0000
#define JPEG_COMPONENT_ID3_MASK		0x0000FF00

/* bit mapping of JPEG number of dummy blocks per mcu row in noninterleave mode register */
#define JPEG_NON_INTERLEAVE_DUMMY_BLOCK_MASK			0x00003000
#define JPEG_NON_INTERLEAVE_BLOCK_PER_MCU_ROW_MASK	0x000003FF

/* bit mappingf of JPEG control register */
#define JPEG_CTRL_PROGRESSIVE_BIT		0x40000000
#define JPEG_CTRL_BLOCK10_COMP_MASK		0x38000000
#define JPEG_CTRL_BLOCK9_COMP_MASK		0x07000000
#define JPEG_CTRL_BLOCK8_COMP_MASK		0x00E00000
#define JPEG_CTRL_BLOCK7_COMP_MASK		0x001C0000
#define JPEG_CTRL_BLOCK6_COMP_MASK		0x00038000
#define JPEG_CTRL_BLOCK5_COMP_MASK		0x00007000
#define JPEG_CTRL_BLOCK4_COMP_MASK		0x00000E00
#define JPEG_CTRL_BLOCK3_COMP_MASK		0x000001C0
#define JPEG_CTRL_BLOCK2_COMP_MASK		0x00000038
#define JPEG_CTRL_BLOCK1_COMP_MASK		0x00000007

#define JPEG_CTRL_CATEGORY_COMPONENT1	0x04
#define JPEG_CTRL_CATEGORY_COMPONENT2	0x05
#define JPEG_CTRL_CATEGORY_COMPONENT3	0x06
#define JPEG_CTRL_CATEGORY_UNUSED		0x07
/* bit mapping of Q-table ID register */
#define Q_TABLE_ID_COMP1			0x00000F00
#define Q_TABLE_ID_COMP2			0x000000F0
#define Q_TABLE_ID_COMP3			0x0000000F

/* bit mapping of JPEG decoder interrupt status register */
#define JPEG_INT_STATUS_MASK					0x07
#define JPEG_INT_STATUS_FILE_OVERFLOW_BIT	0x04
#define JPEG_INT_STATUS_BREAKPOINT_BIT		0x02
#define JPEG_INT_STATUS_EOF_BIT				0x01

/* macros of JPEG decoder abort register */
#define RESET_JPEG_DECODER		REG_JPEG_DECODER_ABORT = 0x01;

/* macros of JPEG decoder trigger register */
#define START_JPEG_DECODER		REG_JPEG_DECODER_TRIGGER = 0x01;

/* macros of JPEG decoder sample factor register */
#define SET_JPEG_SAMPLE_FACTOR_H1(n)	REG_JPEG_DECODER_SAMPLE_FACTOR &= ~JPEG_SAMPLE_FACTOR_H_SF1_MASK;\
													REG_JPEG_DECODER_SAMPLE_FACTOR |= ((n-1)<<10);
#define SET_JPEG_SAMPLE_FACTOR_V1(n)	REG_JPEG_DECODER_SAMPLE_FACTOR &= ~JPEG_SAMPLE_FACTOR_V_SF1_MASK;\
													REG_JPEG_DECODER_SAMPLE_FACTOR |= ((n-1)<<8);
#define SET_JPEG_SAMPLE_FACTOR_H2(n)	REG_JPEG_DECODER_SAMPLE_FACTOR &= ~JPEG_SAMPLE_FACTOR_H_SF2_MASK;\
													REG_JPEG_DECODER_SAMPLE_FACTOR |= ((n-1)<<6);
#define SET_JPEG_SAMPLE_FACTOR_V2(n)	REG_JPEG_DECODER_SAMPLE_FACTOR &= ~JPEG_SAMPLE_FACTOR_V_SF2_MASK;\
													REG_JPEG_DECODER_SAMPLE_FACTOR |= ((n-1)<<4);
#define SET_JPEG_SAMPLE_FACTOR_H3(n)	REG_JPEG_DECODER_SAMPLE_FACTOR &= ~JPEG_SAMPLE_FACTOR_H_SF3_MASK;\
													REG_JPEG_DECODER_SAMPLE_FACTOR |= ((n-1)<<2);
#define SET_JPEG_SAMPLE_FACTOR_V3(n)	REG_JPEG_DECODER_SAMPLE_FACTOR &= ~JPEG_SAMPLE_FACTOR_V_SF3_MASK;\
													REG_JPEG_DECODER_SAMPLE_FACTOR |= (n-1);

/* macros of JPEG component ID register */
#define SET_JPEG_COMPONENT1_ID(n)	REG_JPEG_DECODER_COMPENT_ID &= ~JPEG_COMPONENT_ID1_MASK;\
												REG_JPEG_DECODER_COMPENT_ID |= (n<<24);
#define SET_JPEG_COMPONENT2_ID(n)	REG_JPEG_DECODER_COMPENT_ID &= ~JPEG_COMPONENT_ID2_MASK;\
												REG_JPEG_DECODER_COMPENT_ID |= (n<<16);
#define SET_JPEG_COMPONENT3_ID(n)	REG_JPEG_DECODER_COMPENT_ID &= ~JPEG_COMPONENT_ID3_MASK;\
												REG_JPEG_DECODER_COMPENT_ID |= (n<<8);

/* macros of dummy blcok per mcu row in interleave mode */
#define SET_JPEG_COMP0_DUMMY_BLOCKS_PER_MCU_ROW(n)	REG_JPEG_DECODER_COMP0_DU_NUM_PER_MCU_ROW &= ~JPEG_NON_INTERLEAVE_DUMMY_BLOCK_MASK;\
																	REG_JPEG_DECODER_COMP0_DU_NUM_PER_MCU_ROW |= (n<<12);
#define SET_JPEG_COMP0_BLOCKS_PER_MCU_ROW(n)			REG_JPEG_DECODER_COMP0_DU_NUM_PER_MCU_ROW &= ~JPEG_NON_INTERLEAVE_BLOCK_PER_MCU_ROW_MASK;\
																	REG_JPEG_DECODER_COMP0_DU_NUM_PER_MCU_ROW |= n;

#define SET_JPEG_COMP1_DUMMY_BLOCKS_PER_MCU_ROW(n)	REG_JPEG_DECODER_COMP1_DU_NUM_PER_MCU_ROW &= ~JPEG_NON_INTERLEAVE_DUMMY_BLOCK_MASK;\
																	REG_JPEG_DECODER_COMP1_DU_NUM_PER_MCU_ROW |= (n<<12);
#define SET_JPEG_COMP1_BLOCKS_PER_MCU_ROW(n)			REG_JPEG_DECODER_COMP1_DU_NUM_PER_MCU_ROW &= ~JPEG_NON_INTERLEAVE_BLOCK_PER_MCU_ROW_MASK;\
																	REG_JPEG_DECODER_COMP1_DU_NUM_PER_MCU_ROW |= n;

#define SET_JPEG_COMP2_DUMMY_BLOCKS_PER_MCU_ROW(n)	REG_JPEG_DECODER_COMP2_DU_NUM_PER_MCU_ROW &= ~JPEG_NON_INTERLEAVE_DUMMY_BLOCK_MASK;\
																	REG_JPEG_DECODER_COMP2_DU_NUM_PER_MCU_ROW |= (n<<12);
#define SET_JPEG_COMP2_BLOCKS_PER_MCU_ROW(n)			REG_JPEG_DECODER_COMP2_DU_NUM_PER_MCU_ROW &= ~JPEG_NON_INTERLEAVE_BLOCK_PER_MCU_ROW_MASK;\
																	REG_JPEG_DECODER_COMP2_DU_NUM_PER_MCU_ROW |= n;

/* macros of JPEG decoder control register */
#define SET_JPEG_PROGRESSIVE_MODE	REG_JPEG_DECODER_CTRL |= JPEG_CTRL_PROGRESSIVE_BIT;
#define SET_JPEG_BASELINE_MODE		REG_JPEG_DECODER_CTRL &= ~JPEG_CTRL_PROGRESSIVE_BIT;
#define SET_JPEG_CATEGORY_COMPONENT_ID(block,cmp_id)	REG_JPEG_DECODER_CTRL &= ~(0x07<<(block*3));\
																		REG_JPEG_DECODER_CTRL |= (cmp_id << (block*3));

/* macros of Q-Table ID register */
#define SET_JPEG_COMPONENT1_Q_TABLE(n)	REG_JPEG_DECODER_Q_TABLE_ID &= ~Q_TABLE_ID_COMP1;\
													REG_JPEG_DECODER_Q_TABLE_ID |= (n<<8);
#define SET_JPEG_COMPONENT2_Q_TABLE(n)	REG_JPEG_DECODER_Q_TABLE_ID &= ~Q_TABLE_ID_COMP2;\
													REG_JPEG_DECODER_Q_TABLE_ID |= (n<<4);
#define SET_JPEG_COMPONENT3_Q_TABLE(n)	REG_JPEG_DECODER_Q_TABLE_ID &= ~Q_TABLE_ID_COMP3;\
													REG_JPEG_DECODER_Q_TABLE_ID |= n;

#if (defined(DRV_JPG_ENC_SUPPORT))
/* definition for jpeg encode result */
#define JPEG_ENCODE_DONE	0x01
#define JPEG_ENCODE_STALL	0x02

#if (defined(DRV_JPG_ENC_28_SERIES))
#define JPEG_FORMAT_GRAY			0
#define JPEG_FORMAT_YUV422			1
#define JPEG_FORMAT_YUV420 		2
#endif

#define JPEG_ENCODER_RESET_REG			(JPEG_CODEC_base + 0X8C)
#define JPEG_ENCODER_CTRL_REG				(JPEG_CODEC_base + 0X90)
#define JPEG_ENCODER_INT_STATUS_REG		(JPEG_CODEC_base + 0X94)
#define JPEG_ENCODER_BLOCK_COUNT_REG	(JPEG_CODEC_base + 0X98)
#define JPEG_ENCODER_QUALITY_REG			(JPEG_CODEC_base + 0X9C)
#define JPEG_ENCODER_DEST_ADDR_REG		(JPEG_CODEC_base + 0XA0)
#define JPEG_ENCODER_DMA_ADDR_REG		(JPEG_CODEC_base + 0XA4)
#define JPEG_ENCODER_STOP_ADDR_REG		(JPEG_CODEC_base + 0XA8)
#if (defined(DRV_JPG_ENC_28_SERIES))
#define JPEG_ENCODER_CONT_SHOT_FRAME_NUM_REG			(JPEG_CODEC_base + 0xAC)
#define JPEG_ENCODER_CONT_SHOT_CURR_FRAME_NUM_REG	(JPEG_CODEC_base + 0xB0)
#define JPEG_ENCODER_DEST_ADDR2_REG						(JPEG_CODEC_base + 0XB4)
#define JPEG_ENCODER_DMA_ADDR2_REG						(JPEG_CODEC_base + 0XB8)
#define JPEG_ENCODER_STOP_ADDR2_REG						(JPEG_CODEC_base + 0XBC)
#endif

#define REG_JPEG_ENCODER_RESET			*((volatile unsigned int *) (JPEG_CODEC_base + 0X8C))
#define REG_JPEG_ENCODER_CTRL				*((volatile unsigned int *) (JPEG_CODEC_base + 0X90))
#define REG_JPEG_ENCODER_INT_STATUS		*((volatile unsigned int *) (JPEG_CODEC_base + 0X94))
#define REG_JPEG_ENCODER_BLOCK_COUNT	*((volatile unsigned int *) (JPEG_CODEC_base + 0X98))
#define REG_JPEG_ENCODER_QUALITY			*((volatile unsigned int *) (JPEG_CODEC_base + 0X9C))
#define REG_JPEG_ENCODER_DEST_ADDR		*((volatile unsigned int *) (JPEG_CODEC_base + 0XA0))
#define REG_JPEG_ENCODER_DMA_ADDR		*((volatile unsigned int *) (JPEG_CODEC_base + 0XA4))
#define REG_JPEG_ENCODER_STOP_ADDR		*((volatile unsigned int *) (JPEG_CODEC_base + 0XA8))
#if (defined(DRV_JPG_ENC_28_SERIES))
#define REG_JPEG_ENCODER_CONT_SHOT_FRAME_NUM			*((volatile unsigned int *) (JPEG_CODEC_base + 0XAC))
#define REG_JPEG_ENCODER_CONT_SHOT_CURR_FRAME_NUM	*((volatile unsigned int *) (JPEG_CODEC_base + 0XB0))
#define REG_JPEG_ENCODER_DEST_ADDR2		*((volatile unsigned int *) (JPEG_CODEC_base + 0XB4))
#define REG_JPEG_ENCODER_DMA_ADDR2		*((volatile unsigned int *) (JPEG_CODEC_base + 0XB8))
#define REG_JPEG_ENCODER_STOP_ADDR2		*((volatile unsigned int *) (JPEG_CODEC_base + 0XBC))
#endif

/* bit mapping of JPEG encoder control register */
#define JPEG_ENCODER_ENABLE_BIT			0x00000001
#define JPEG_ENCODER_GRAYSCALE_BIT		0x00000002
#define JPEG_ENCODER_INT_ENABLE_BIT		0x00000004
#if (defined(DRV_JPG_ENC_28_SERIES))
#define JPEG_ENCODER_YUV_FORMAT_BIT		0x00000008
#define JPEG_ENCODER_APP_FORMAT_BIT		0x00000010
#define JPEG_ENCODER_CONT_SHOT_BIT		0x00000020
#define JPEG_ENCODER_ADDR_SWITCH_BIT	0x00000040
#endif

/* bit mapping of JPEG encoder interrupt status register */
#define JPEG_ENCODER_DONE_INT_STATUS 	0x00000001
#define JPEG_ENCODER_STALL_INT_STATUS	0x00000002
#if (defined(DRV_JPG_ENC_28_SERIES))
#define JPEG_ENCODER_STALL1_INT_STATUS	0x00000010
#define JPEG_ENCODER_STALL2_INT_STATUS	0x00000020
#endif
/* bit mapping of JPEG encoder quality register */
#if (defined (DRV_JPG_SW_DEC_SUPPORT))
#define JPEG_ENCODER_HIGH_QUALITY	0
#define JPEG_ENCODER_GOOD_QUALITY	1
#define JPEG_ENCODER_FAIR_QUALITY	2 /* using default quantization table */
#define JPEG_ENCODER_POOR_QUALITY	3
#else
#if (defined(MT6219)||defined(MT6228))
#define JPEG_ENCODER_HIGH_QUALITY	3
#define JPEG_ENCODER_GOOD_QUALITY	2
#define JPEG_ENCODER_FAIR_QUALITY	1
#define JPEG_ENCODER_POOR_QUALITY	0
#else//#elif (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6229))
#define JPEG_ENCODER_QUALITY_0_3		0x3
#define JPEG_ENCODER_QUALITY_0_2		0x2
#define JPEG_ENCODER_QUALITY_0_1		0x1
#define JPEG_ENCODER_QUALITY_0_0		0x0
#define JPEG_ENCODER_QUALITY_1_3		0x7
#define JPEG_ENCODER_QUALITY_1_2		0x6
#define JPEG_ENCODER_QUALITY_1_1		0x5
#define JPEG_ENCODER_QUALITY_1_0		0x4
#define JPEG_ENCODER_QUALITY_2_3		0xB
#define JPEG_ENCODER_QUALITY_2_2		0xA
#define JPEG_ENCODER_QUALITY_2_1		0x9
#define JPEG_ENCODER_QUALITY_2_0		0x8
#define JPEG_ENCODER_QUALITY_3_3		0xF
#define JPEG_ENCODER_QUALITY_3_2		0xE
#define JPEG_ENCODER_QUALITY_3_1		0xD
#define JPEG_ENCODER_QUALITY_3_0		0xC

#define JPEG_ENCODER_HIGH_QUALITY	JPEG_ENCODER_QUALITY_0_3
#define JPEG_ENCODER_GOOD_QUALITY	JPEG_ENCODER_QUALITY_0_2
#define JPEG_ENCODER_FAIR_QUALITY	JPEG_ENCODER_QUALITY_0_1
#define JPEG_ENCODER_POOR_QUALITY	JPEG_ENCODER_QUALITY_0_0
#endif

#endif /*DRV_JPG_SW_DEC_SUPPORT*/

/* macros of JPEG encoder reset register */
#define RESET_JPEG_ENCODER		REG_JPEG_ENCODER_RESET = 1;\
										REG_JPEG_ENCODER_RESET = 0;
#define RELOAD_STALL_ADDRESS	REG_JPEG_ENCODER_RESET |= 0x10;

/* macros of JPEG encoder control register */
#define ENABLE_JPEG_ENCODER				REG_JPEG_ENCODER_CTRL |= JPEG_ENCODER_ENABLE_BIT;
#define SET_JPEG_ENCODER_COLOR_MODE		REG_JPEG_ENCODER_CTRL &= ~JPEG_ENCODER_GRAYSCALE_BIT;
#define SET_JPEG_ENCODER_GRAY_MODE		REG_JPEG_ENCODER_CTRL |= JPEG_ENCODER_GRAYSCALE_BIT;
#define ENABLE_JPEG_ENCODER_INT			REG_JPEG_ENCODER_CTRL |= JPEG_ENCODER_INT_ENABLE_BIT;
#define DISABLE_JPEG_ENCODER_INT			REG_JPEG_ENCODER_CTRL &= ~JPEG_ENCODER_INT_ENABLE_BIT;
#if (defined(DRV_JPG_ENC_28_SERIES))
#define SET_JPEG_ENCODER_FORMAT_YUV422	REG_JPEG_ENCODER_CTRL &= ~JPEG_ENCODER_YUV_FORMAT_BIT;
#define SET_JPEG_ENCODER_FORMAT_YUV420	REG_JPEG_ENCODER_CTRL |= JPEG_ENCODER_YUV_FORMAT_BIT;
#define ENABLE_JPEG_ENCODER_JFIF_MODE	REG_JPEG_ENCODER_CTRL |= JPEG_ENCODER_APP_FORMAT_BIT;
#define DISABLE_JPEG_ENCODER_JFIF_MODE	REG_JPEG_ENCODER_CTRL &= ~JPEG_ENCODER_APP_FORMAT_BIT;
#define ENABLE_JPEG_ENCODER_CONT_SHOT	REG_JPEG_ENCODER_CTRL |= JPEG_ENCODER_CONT_SHOT_BIT;
#define DISABLE_JPEG_ENCODER_CONT_SHOT	REG_JPEG_ENCODER_CTRL &= ~JPEG_ENCODER_CONT_SHOT_BIT;
#define ENABLE_JPEG_ENCODER_ADDR_SWITCH	REG_JPEG_ENCODER_CTRL |= JPEG_ENCODER_ADDR_SWITCH_BIT;
#define DISABLE_JPEG_ENCODER_ADDR_SWITCH	REG_JPEG_ENCODER_CTRL &= ~JPEG_ENCODER_ADDR_SWITCH_BIT;
#endif

/* macros of JPEG encoder quality control register */
#define SET_JPEG_ENCODER_HIGH_QUALITY	REG_JPEG_ENCODER_QUALITY=JPEG_ENCODER_HIGH_QUALITY;
#define SET_JPEG_ENCODER_GOOD_QUALITY	REG_JPEG_ENCODER_QUALITY=JPEG_ENCODER_GOOD_QUALITY;
#define SET_JPEG_ENCODER_FAIR_QUALITY	REG_JPEG_ENCODER_QUALITY=JPEG_ENCODER_FAIR_QUALITY;
#define SET_JPEG_ENCODER_POOR_QUALITY	REG_JPEG_ENCODER_QUALITY=JPEG_ENCODER_POOR_QUALITY;
#define SET_JPEG_ENCODER_QUALITY(quality)		REG_JPEG_ENCODER_QUALITY=quality;

#define JPEG_ENCODER_IS_RUNNING 		(!(REG_JPEG_ENCODER_INT_STATUS & 0x01))
#endif /* MT6219 */

/* register definition of Resizer registers */
#if (defined(MT6218B))
#define RESIZER_CTRL_REG	   			(RESIZER_base + 0x00)
#define RESIZER_STATUS_REG				   (RESIZER_base + 0x04)
#define RESIZER_SOURCE_IMAGE_SIZE_REG	(RESIZER_base + 0x08)
#define RESIZER_TARGET_IMAGE_SIZE_REG	(RESIZER_base + 0x0C)
#define RESIZER_BLOCK_CS_CFG_REG		   (RESIZER_base + 0x10)
#define RESIZER_Y_LINE_BUFFER_ADDR_REG	(RESIZER_base + 0x14)
#define RESIZER_U_LINE_BUFFER_ADDR_REG	(RESIZER_base + 0x18)
#define RESIZER_V_LINE_BUFFER_ADDR_REG	(RESIZER_base + 0x1C)
#define RESIZER_FINE_RESIZE_CFG_REG		(RESIZER_base + 0x20)
#define RESIZER_Y_WORK_MEM_ADDR_REG		(RESIZER_base + 0x24)
#define RESIZER_U_WORK_MEM_ADDR_REG		(RESIZER_base + 0x28)
#define RESIZER_V_WORK_MEM_ADDR_REG		(RESIZER_base + 0x2C)
#define RESIZER_YUV2RGB_CFG_REG			(RESIZER_base + 0x30)
#define RESIZER_TARGET_MEM_ADDR_REG		(RESIZER_base + 0x34)
#define RESIZER_LINE_BUFFER_SIZE_REG	(RESIZER_base + 0x38)
#define RESIZER_YUV2RGB_INT_STATUS_REG	(RESIZER_base + 0x40)

#define REG_RESIZER_CTRL			   	*((volatile unsigned int *) (RESIZER_base + 0x00))
#define REG_RESIZER_STATUS				   *((volatile unsigned int *) (RESIZER_base + 0x04))
#define REG_RESIZER_SOURCE_IMAGE_SIZE	*((volatile unsigned int *) (RESIZER_base + 0x08))
#define REG_RESIZER_TARGET_IMAGE_SIZE	*((volatile unsigned int *) (RESIZER_base + 0x0C))
#define REG_RESIZER_BLOCK_CS_CFG		   *((volatile unsigned int *) (RESIZER_base + 0x10))
#define REG_RESIZER_Y_LINE_BUFFER_ADDR	*((volatile unsigned int *) (RESIZER_base + 0x14))
#define REG_RESIZER_U_LINE_BUFFER_ADDR	*((volatile unsigned int *) (RESIZER_base + 0x18))
#define REG_RESIZER_V_LINE_BUFFER_ADDR	*((volatile unsigned int *) (RESIZER_base + 0x1C))
#define REG_RESIZER_FINE_RESIZE_CFG		*((volatile unsigned int *) (RESIZER_base + 0x20))
#define REG_RESIZER_Y_WORK_MEM_ADDR		*((volatile unsigned int *) (RESIZER_base + 0x24))
#define REG_RESIZER_U_WORK_MEM_ADDR		*((volatile unsigned int *) (RESIZER_base + 0x28))
#define REG_RESIZER_V_WORK_MEM_ADDR		*((volatile unsigned int *) (RESIZER_base + 0x2C))
#define REG_RESIZER_YUV2RGB_CFG			*((volatile unsigned int *) (RESIZER_base + 0x30))
#define REG_RESIZER_TARGET_MEM_ADDR		*((volatile unsigned int *) (RESIZER_base + 0x34))
#define REG_RESIZER_LINE_BUFFER_SIZE	*((volatile unsigned int *) (RESIZER_base + 0x38))
#define REG_RESIZER_YUV2RGB_INT_STATUS	*((volatile unsigned int *) (RESIZER_base + 0x40))

/* bit mapping of resizer control register */
#define RESIZER_CTRL_RESET_MASK                 0x00070000
#define RESIZER_CTRL_ENABLE_MASK                0x00000007
#define RESIZER_CTRL_BLOCK_CS_ENABLE_BIT		   0x00000001
#define RESIZER_CTRL_FINE_RESIZE_ENABLE_BIT		0x00000002
#define RESIZER_CTRL_YUV2RGB_ENABLE_BIT			0x00000004
#define RESIZER_CTRL_BLOCK_CS_RESET_BIT			0x00010000
#define RESIZER_CTRL_FINE_RESIZE_RESET_BIT		0x00020000
#define RESIZER_CTRL_YUV2RGB_RESET_BIT			   0x00040000

/* bit mapping of resizer status register */
#define RESIZER_CTRL_BLOCK_CS_BUSY_BIT			0x00000001
#define RESIZER_CTRL_FINE_RESIZE_BUSY_BIT		0x00000002
#define RESIZER_CTRL_YUV2RGB_BUSY_BIT			0x00000004

/* bit mapping of resizer source and target size register */
#define RESIZER_IMAGE_SIZE_WIDTH_MASK			0x000003FF
#define RESIZER_IMAGE_SIZE_HEIGHT_MASK			0x01FF0000

/* bit mapping of resizer block coarse shrink config register */
#define RESIZER_BLOCk_CS_CFG_V_V_SAMPLE_FACTOR_MASK	0x0000C000
#define RESIZER_BLOCk_CS_CFG_V_H_SAMPLE_FACTOR_MASK	0x00003000
#define RESIZER_BLOCk_CS_CFG_U_V_SAMPLE_FACTOR_MASK	0x00000C00
#define RESIZER_BLOCk_CS_CFG_U_H_SAMPLE_FACTOR_MASK	0x00000300
#define RESIZER_BLOCk_CS_CFG_Y_V_SAMPLE_FACTOR_MASK	0x000000C0
#define RESIZER_BLOCk_CS_CFG_Y_H_SAMPLE_FACTOR_MASK	0x00000030
#define RESIZER_BLOCk_CS_CFG_PLC_MASK				      0x0000000C
#define RESIZER_BLOCk_CS_CFG_CS_FACTOR_MASK			   0x00000003

/* definition of resizer block CS register */
#define BLOCK_CS_1_1			   0x00000000
#define BLOCK_CS_1_4			   0x00000001
#define BLOCK_CS_1_16			0x00000002
#define BLOCK_CS_1_64			0x00000003
#define BLOCK_PLC_0				0x00000000
#define BLOCK_PLC_1				0x00000004
#define BLOCK_Y_H_FACTOR_1		0x00000000
#define BLOCK_Y_H_FACTOR_2		0x00000010
#define BLOCK_Y_H_FACTOR_4		0x00000020
#define BLOCK_Y_V_FACTOR_1		0x00000000
#define BLOCK_Y_V_FACTOR_2		0x00000040
#define BLOCK_Y_V_FACTOR_4		0x00000080
#define BLOCK_U_H_FACTOR_1		0x00000000
#define BLOCK_U_H_FACTOR_2		0x00000100
#define BLOCK_U_H_FACTOR_4		0x00000200
#define BLOCK_U_V_FACTOR_1		0x00000000
#define BLOCK_U_V_FACTOR_2		0x00000400
#define BLOCK_U_V_FACTOR_4		0x00000800
#define BLOCK_V_H_FACTOR_1		0x00000000
#define BLOCK_V_H_FACTOR_2		0x00001000
#define BLOCK_V_H_FACTOR_4		0x00002000
#define BLOCK_V_V_FACTOR_1		0x00000000
#define BLOCK_V_V_FACTOR_2		0x00004000
#define BLOCK_V_V_FACTOR_4		0x00008000

/* bit mapping of resizer fine resize config register */
#define RESIZER_FINE_RESIZE_WORK_MEM_SIZE_MASK	0x03FF0000
#define RESIZER_FINE_RESIZE_SEQ_BIT				   0x00008000
#define RESIZER_FINE_RESIZE_HR_SRC_MASK			0x0000000C
#define RESIZER_FINE_RESIZE_PLC_MASK			   0x00000003

/* definition of fine resize config register */
#define FINE_RESIZE_HR_SRC_BLOCK_CS	0x00000000
#define FINE_RESIZE_HR_SRC_MEM		0x00000004
#define FINE_RESIZE_PLC_00			   0x00000000
#define FINE_RESIZE_PLC_01			   0x00000001

/* bit mapping of YUV2RGB config register */
#define RESIZER_YUV2RGB_INT_ENABLE_BIT	0x00008000
#define RESIZER_YUV2RGB_SRC_BIT			0x00000001

/* bit mapping of resizer line buffer size register */
#define RESIZER_BLOCk_CS_Y_LINE_BUFF_SIZE_MASK	0x000003FF
#define RESIZER_BLOCk_CS_U_LINE_BUFF_SIZE_MASK	0x000FFC00
#define RESIZER_BLOCk_CS_V_LINE_BUFF_SIZE_MASK	0x3FF00000

/* bit mapping of image resizer interupt status register */
#define RESIZER_YUV2RGB_INT_STATUS_BIT	0x00000001

/* Macros of resizer control register */
#define RESET_RESIZER               REG_RESIZER_CTRL=RESIZER_CTRL_RESET_MASK;\
                                    REG_RESIZER_CTRL=0;
#define SET_BLOCK_CS_RESET		   	REG_RESIZER_CTRL |= RESIZER_CTRL_BLOCK_CS_RESET_BIT;
#define CLEAR_BLOCK_CS_RESET		   REG_RESIZER_CTRL &= ~RESIZER_CTRL_BLOCK_CS_RESET_BIT;
#define SET_FINE_RESIZE_RESET		   REG_RESIZER_CTRL |= RESIZER_CTRL_FINE_RESIZE_RESET_BIT;
#define CLEAR_FINE_RESIZE_RESET  	REG_RESIZER_CTRL &= ~RESIZER_CTRL_FINE_RESIZE_RESET_BIT;
#define SET_YUV2RGB_RESET			   REG_RESIZER_CTRL |= RESIZER_CTRL_YUV2RGB_RESET_BIT;
#define CLEAR_YUV2RGB_RESET			REG_RESIZER_CTRL &= ~RESIZER_CTRL_YUV2RGB_RESET_BIT;
#define ENABLE_BLOCK_CS_BLOCK		   REG_RESIZER_CTRL |= RESIZER_CTRL_BLOCK_CS_ENABLE_BIT
#define DISABLE_BLOCK_CS_BLOCK		REG_RESIZER_CTRL &= ~RESIZER_CTRL_BLOCK_CS_ENABLE_BIT
#define ENABLE_FINE_RESIZE_BLOCK	   REG_RESIZER_CTRL |= RESIZER_CTRL_FINE_RESIZE_ENABLE_BIT
#define DISABLE_FINE_RESIZE_BLOCK	REG_RESIZER_CTRL &= ~RESIZER_CTRL_FINE_RESIZE_ENABLE_BIT
#define ENABLE_YUV2RGB_BLOCK		   REG_RESIZER_CTRL |= RESIZER_CTRL_YUV2RGB_ENABLE_BIT
#define DISABLE_YUV2RGB_BLOCK	   	REG_RESIZER_CTRL &= ~RESIZER_CTRL_YUV2RGB_ENABLE_BIT
#define ENABLE_RESIZER              REG_RESIZER_CTRL = RESIZER_CTRL_ENABLE_MASK;

/* Macros of resizer status register */
#define IS_BLOCK_CS_BUSY		 (REG_RESIZER_STATUS & RESIZER_CTRL_BLOCK_CS_BUSY_BIT)
#define IS_FINE_RESIZE_BUSY	 (REG_RESIZER_STATUS & RESIZER_CTRL_FINE_RESIZE_BUSY_BIT)
#define IS_YUV2RGB_BUSY			 (REG_RESIZER_STATUS & RESIZER_CTRL_YUV2RGB_BUSY_BIT)

/* Macros of resizer source image size register */
#define SET_RESIZER_SRC_SIZE(width, height)		REG_RESIZER_SOURCE_IMAGE_SIZE=(width|(height<<16));

/* Macros of resizer target image size register */
#define SET_RESIZER_TARGET_SIZE(width, height)	REG_RESIZER_TARGET_IMAGE_SIZE=(width|(height<<16));

/* Macros of resizer block coarse shrinking config register */
#define SET_RESIZER_BLOCK_CS_V_V_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_V_V_SAMPLE_FACTOR_MASK;\
										            			REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<14);
#define SET_RESIZER_BLOCK_CS_V_H_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_V_H_SAMPLE_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<12);
#define SET_RESIZER_BLOCK_CS_U_V_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_U_V_SAMPLE_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<10);
#define SET_RESIZER_BLOCK_CS_U_H_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_U_H_SAMPLE_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<8);
#define SET_RESIZER_BLOCK_CS_Y_V_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_Y_V_SAMPLE_FACTOR_MASK;\
            													REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<6);
#define SET_RESIZER_BLOCK_CS_Y_H_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_Y_H_SAMPLE_FACTOR_MASK;\
				            									REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<4);
#define SET_RESIZER_BLOCK_CS_PLC(plc)		   		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_PLC_MASK;\
								            					REG_RESIZER_BLOCK_CS_CFG |= plc;
#define SET_RESIZER_BLOCK_CS_FACTOR(factor)			REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_CS_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= factor;

/* macros of resizer fine resizer config register */
#define SET_RESIZER_FINE_RESIZE_WORK_MEM_SIZE(line)	REG_RESIZER_FINE_RESIZE_CFG &= ~RESIZER_FINE_RESIZE_WORK_MEM_SIZE_MASK;\
               													REG_RESIZER_FINE_RESIZE_CFG |= (line<<16);
#define SET_RESIZER_FINE_RESIZE_HR_SRC_MEM   			REG_RESIZER_FINE_RESIZE_CFG &= ~RESIZER_FINE_RESIZE_HR_SRC_MASK;\
					               								REG_RESIZER_FINE_RESIZE_CFG |= RESIZER_FINE_RESIZE_HR_SRC_MEM;
#define SET_RESIZER_FINE_RESIZE_HR_SRC_BLOCK_CS 		REG_RESIZER_FINE_RESIZE_CFG &= ~RESIZER_FINE_RESIZE_HR_SRC_MASK;
#define SET_RESIZER_FINE_RESIZE_PLC(plc)			      REG_RESIZER_FINE_RESIZE_CFG &= ~RESIZER_FINE_RESIZE_PLC_MASK;\
               													REG_RESIZER_FINE_RESIZE_CFG |= plc;
#define ENABLE_RESIZER_FINE_RESIZE_SEQ	      			REG_RESIZER_FINE_RESIZE_CFG |= RESIZER_FINE_RESIZE_SEQ_BIT;
#define DISABLE_RESIZER_FIEN_RESIZE_SEQ		   		REG_RESIZER_FINE_RESIZE_CFG &= ~RESIZER_FINE_RESIZE_SEQ_BIT;


/* macros of resizer YUV2RGB config register */
#define ENABLE_RESIZER_YUV2RGB_INT		REG_RESIZER_YUV2RGB_CFG |= RESIZER_YUV2RGB_INT_ENABLE_BIT;
#define DISABLE_RESIZER_YUV2RGB_INT		REG_RESIZER_YUV2RGB_CFG &= ~RESIZER_YUV2RGB_INT_ENABLE_BIT;

/* macros of resizer line buffer size register */
#define SET_RESIZER_FINE_RESIZE_Y_LINE_BUFFER(n)	REG_RESIZER_LINE_BUFFER_SIZE &= ~RESIZER_BLOCk_CS_Y_LINE_BUFF_SIZE_MASK; \
            													REG_RESIZER_LINE_BUFFER_SIZE |= n;
#define SET_RESIZER_FINE_RESIZE_U_LINE_BUFFER(n)	REG_RESIZER_LINE_BUFFER_SIZE &= ~RESIZER_BLOCk_CS_U_LINE_BUFF_SIZE_MASK; \
				            									REG_RESIZER_LINE_BUFFER_SIZE |= (n<<10);
#define SET_RESIZER_FINE_RESIZE_V_LINE_BUFFER(n)	REG_RESIZER_LINE_BUFFER_SIZE &= ~RESIZER_BLOCk_CS_V_LINE_BUFF_SIZE_MASK; \
								            					REG_RESIZER_LINE_BUFFER_SIZE |= (n<<20);

/* macros of resizer interrupt status register */
#define IS_RESIZER_COMPLETE_INT		(REG_RESIZER_YUV2RGB_INT_STATUS & RESIZER_YUV2RGB_INT_STATUS_BIT)

#elif (defined(MT6217))
#define RESIZER_CONFIG_REG	   			(RESIZER_base + 0x00)
#define RESIZER_CTRL_REG	   			(RESIZER_base + 0x04)
#define RESIZER_STATUS_REG				   (RESIZER_base + 0x08)
#define RESIZER_INT_STATUS_REG			(RESIZER_base + 0x0C)
#define RESIZER_SOURCE_IMAGE_SIZE_REG	(RESIZER_base + 0x10)
#define RESIZER_TARGET_IMAGE_SIZE_REG	(RESIZER_base + 0x14)
#define RESIZER_H_RATIO_REG				(RESIZER_base + 0x18)
#define RESIZER_V_RATIO_REG				(RESIZER_base + 0x1C)
#define RESIZER_H_RESIDUAL_REG			(RESIZER_base + 0x20)
#define RESIZER_V_RESIDUAL_REG			(RESIZER_base + 0x24)
#define RESIZER_BLOCK_CS_CFG_REG		   (RESIZER_base + 0x30)
#define RESIZER_Y_LINE_BUFFER_ADDR_REG	(RESIZER_base + 0x34)
#define RESIZER_U_LINE_BUFFER_ADDR_REG	(RESIZER_base + 0x38)
#define RESIZER_V_LINE_BUFFER_ADDR_REG	(RESIZER_base + 0x3C)
#define RESIZER_FINE_RESIZE_CFG_REG		(RESIZER_base + 0x40)
#define RESIZER_LINE_BUFFER_SIZE			(RESIZER_base + 0x50)
#define RESIZER_WORK_MEM_ADDR_REG		(RESIZER_base + 0x5C)
#define RESIZER_YUV2RGB_CFG_REG			(RESIZER_base + 0x80)
#define RESIZER_TARGET_MEM_ADDR_REG		(RESIZER_base + 0x84)

#define REG_RESIZER_CONFIG			   	*((volatile unsigned int *) (RESIZER_base + 0x00))
#define REG_RESIZER_CTRL			   	*((volatile unsigned int *) (RESIZER_base + 0x04))
#define REG_RESIZER_STATUS				   *((volatile unsigned int *) (RESIZER_base + 0x08))
#define REG_RESIZER_INT_STATUS			*((volatile unsigned int *) (RESIZER_base + 0x0C))
#define REG_RESIZER_SOURCE_IMAGE_SIZE	*((volatile unsigned int *) (RESIZER_base + 0x10))
#define REG_RESIZER_TARGET_IMAGE_SIZE	*((volatile unsigned int *) (RESIZER_base + 0x14))
#define REG_RESIZER_H_RATIO				*((volatile unsigned int *) (RESIZER_base + 0x18))
#define REG_RESIZER_V_RATIO				*((volatile unsigned int *) (RESIZER_base + 0x1C))
#define REG_RESIZER_H_RESIDUAL			*((volatile unsigned int *) (RESIZER_base + 0x20))
#define REG_RESIZER_V_RESIDUAL			*((volatile unsigned int *) (RESIZER_base + 0x24))
#define REG_RESIZER_BLOCK_CS_CFG		   *((volatile unsigned int *) (RESIZER_base + 0x30))
#define REG_RESIZER_Y_LINE_BUFFER_ADDR	*((volatile unsigned int *) (RESIZER_base + 0x34))
#define REG_RESIZER_U_LINE_BUFFER_ADDR	*((volatile unsigned int *) (RESIZER_base + 0x38))
#define REG_RESIZER_V_LINE_BUFFER_ADDR	*((volatile unsigned int *) (RESIZER_base + 0x3C))
#define REG_RESIZER_FINE_RESIZE_CFG		*((volatile unsigned int *) (RESIZER_base + 0x40))
#define REG_RESIZER_LINE_BUFFER_SIZE	*((volatile unsigned int *) (RESIZER_base + 0x50))
#define REG_RESIZER_WORK_MEM_ADDR		*((volatile unsigned int *) (RESIZER_base + 0x5C))
#define REG_RESIZER_YUV2RGB_CFG			*((volatile unsigned int *) (RESIZER_base + 0x80))
#define REG_RESIZER_TARGET_MEM_ADDR		*((volatile unsigned int *) (RESIZER_base + 0x84))

/* bit mapping of resizer control register */
#define RESIZER_CTRL_RESET_MASK              0x000F0000
#define RESIZER_CTRL_ENABLE_MASK             0x0000000F
#define RESIZER_CTRL_BLOCK_CS_ENABLE_BIT	   0x00000001
#define RESIZER_CTRL_HR_ENABLE_BIT				0x00000002
#define RESIZER_CTRL_VR_ENABLE_BIT				0x00000004
#define RESIZER_CTRL_YUV2RGB_ENABLE_BIT		0x00000008
#define RESIZER_CTRL_BLOCK_CS_RESET_BIT		0x00010000
#define RESIZER_CTRL_HR_RESET_BIT				0x00020000
#define RESIZER_CTRL_VR_RESET_BIT				0x00040000
#define RESIZER_CTRL_YUV2RGB_RESET_BIT			0x00080000

/* bit mapping of resizer status register */
#define RESIZER_STAT_BLOCK_CS_BUSY_BIT			0x00000001
#define RESIZER_STAT_HR_BUSY_BIT					0x00000002
#define RESIZER_STAT_VR_BUSY_BIT					0x00000004
#define RESIZER_STAT_YUV2RGB_BUSY_BIT			0x00000008
#define RESIZER_STAT_BLOCK_CS_INTRA_BUSY_BIT	0x00000010

/* bit mapping of resizer interrupt status register */
#define RESIZER_INT_STAT_BLOCK_CS_BIT		0x00000001
#define RESIZER_INT_STAT_HR_BIT				0x00000002
#define RESIZER_INT_STAT_VR_BIT				0x00000004
#define RESIZER_YUV2RGB_INT_STATUS_BIT		0x00000008
#define RESIZER_YUV2RGB_INT_ENABLE_BIT		0x00008000
#define RESIZER_BLOCK_CS_INT_ENABLE_BIT	0x00010000
#define RESIZER_HR_INT_ENABLE_BIT			0x00000010
#define RESIZER_VR_INT_ENABLE_BIT			0x00000020

/* bit mapping of resizer source and target size register */
#define RESIZER_IMAGE_SIZE_WIDTH_MASK			0x000007FF
#define RESIZER_IMAGE_SIZE_HEIGHT_MASK			0x07FF0000

/* bit mapping of resizer block coarse shrink config register */
#define RESIZER_BLOCk_CS_CFG_V_V_SAMPLE_FACTOR_MASK	0x0000C000
#define RESIZER_BLOCk_CS_CFG_V_H_SAMPLE_FACTOR_MASK	0x00003000
#define RESIZER_BLOCk_CS_CFG_U_V_SAMPLE_FACTOR_MASK	0x00000C00
#define RESIZER_BLOCk_CS_CFG_U_H_SAMPLE_FACTOR_MASK	0x00000300
#define RESIZER_BLOCk_CS_CFG_Y_V_SAMPLE_FACTOR_MASK	0x000000C0
#define RESIZER_BLOCk_CS_CFG_Y_H_SAMPLE_FACTOR_MASK	0x00000030
#define RESIZER_BLOCk_CS_CFG_CS_FACTOR_MASK			   0x00000003

/* definition of resizer block CS register */
#define BLOCK_CS_1_1			   0x00000000
#define BLOCK_CS_1_4			   0x00000001
#define BLOCK_CS_1_16			0x00000002
#define BLOCK_CS_1_64			0x00000003
#define BLOCK_Y_H_FACTOR_1		0x00000000
#define BLOCK_Y_H_FACTOR_2		0x00000010
#define BLOCK_Y_H_FACTOR_4		0x00000020
#define BLOCK_Y_H_FACTOR_0		0x00000030
#define BLOCK_Y_V_FACTOR_1		0x00000000
#define BLOCK_Y_V_FACTOR_2		0x00000040
#define BLOCK_Y_V_FACTOR_4		0x00000080
#define BLOCK_Y_V_FACTOR_0		0x000000C0
#define BLOCK_U_H_FACTOR_1		0x00000000
#define BLOCK_U_H_FACTOR_2		0x00000100
#define BLOCK_U_H_FACTOR_4		0x00000200
#define BLOCK_U_H_FACTOR_0		0x00000300
#define BLOCK_U_V_FACTOR_1		0x00000000
#define BLOCK_U_V_FACTOR_2		0x00000400
#define BLOCK_U_V_FACTOR_4		0x00000800
#define BLOCK_U_V_FACTOR_0		0x00000C00
#define BLOCK_V_H_FACTOR_1		0x00000000
#define BLOCK_V_H_FACTOR_2		0x00001000
#define BLOCK_V_H_FACTOR_4		0x00002000
#define BLOCK_V_H_FACTOR_0		0x00003000
#define BLOCK_V_V_FACTOR_1		0x00000000
#define BLOCK_V_V_FACTOR_2		0x00004000
#define BLOCK_V_V_FACTOR_4		0x00008000
#define BLOCK_V_V_FACTOR_0		0x0000C000

/* bit mapping of resizer fine resize config register */
#define RESIZER_FINE_RESIZE_WORK_MEM_SIZE_MASK	0xFFFF0000

/* bit mapping of resizer line buffer size register */
#define RESIZER_BLOCk_CS_LINE_BUFF_SIZE_MASK	0x0000FFFF

/* Macros of resizer control register */
#define RESET_RESIZER               REG_RESIZER_CTRL=RESIZER_CTRL_RESET_MASK;\
                                    REG_RESIZER_CTRL=0;
#define SET_BLOCK_CS_RESET		   	REG_RESIZER_CTRL |= RESIZER_CTRL_BLOCK_CS_RESET_BIT;
#define CLEAR_BLOCK_CS_RESET		   REG_RESIZER_CTRL &= ~RESIZER_CTRL_BLOCK_CS_RESET_BIT;
#define SET_HR_RESET		   			REG_RESIZER_CTRL |= RESIZER_CTRL_HR_RESET_BIT;
#define CLEAR_HR_RESET  				REG_RESIZER_CTRL &= ~RESIZER_CTRL_HR_RESET_BIT;
#define SET_VR_RESET		   			REG_RESIZER_CTRL |= RESIZER_CTRL_VR_RESET_BIT;
#define CLEAR_VR_RESET  				REG_RESIZER_CTRL &= ~RESIZER_CTRL_VR_RESET_BIT;
#define SET_YUV2RGB_RESET			   REG_RESIZER_CTRL |= RESIZER_CTRL_YUV2RGB_RESET_BIT;
#define CLEAR_YUV2RGB_RESET			REG_RESIZER_CTRL &= ~RESIZER_CTRL_YUV2RGB_RESET_BIT;
#define ENABLE_BLOCK_CS_BLOCK		   REG_RESIZER_CTRL |= RESIZER_CTRL_BLOCK_CS_ENABLE_BIT
#define DISABLE_BLOCK_CS_BLOCK		REG_RESIZER_CTRL &= ~RESIZER_CTRL_BLOCK_CS_ENABLE_BIT
#define ENABLE_HR_BLOCK		   		REG_RESIZER_CTRL |= RESIZER_CTRL_HR_ENABLE_BIT
#define DISABLE_HR_BLOCK				REG_RESIZER_CTRL &= ~RESIZER_CTRL_HR_ENABLE_BIT
#define ENABLE_VR_BLOCK		   		REG_RESIZER_CTRL |= RESIZER_CTRL_VR_ENABLE_BIT
#define DISABLE_VR_BLOCK				REG_RESIZER_CTRL &= ~RESIZER_CTRL_VR_ENABLE_BIT
#define ENABLE_YUV2RGB_BLOCK		   REG_RESIZER_CTRL |= RESIZER_CTRL_YUV2RGB_ENABLE_BIT
#define DISABLE_YUV2RGB_BLOCK	   	REG_RESIZER_CTRL &= ~RESIZER_CTRL_YUV2RGB_ENABLE_BIT
#define ENABLE_RESIZER              REG_RESIZER_CTRL = RESIZER_CTRL_ENABLE_MASK;

/* Macros of resizer status register */
#define IS_BLOCK_CS_BUSY		(REG_RESIZER_STATUS & RESIZER_STAT_BLOCK_CS_BUSY_BIT)
#define IS_HR_BUSY	 			(REG_RESIZER_STATUS & RESIZER_STAT_HR_BUSY_BIT)
#define IS_VR_BUSY	 			(REG_RESIZER_STATUS & RESIZER_STAT_VR_BUSY_BIT)
#define IS_YUV2RGB_BUSY			(REG_RESIZER_STATUS & RESIZER_STAT_YUV2RGB_BUSY_BIT)

/* Macros of resizer source image size register */
#define SET_RESIZER_SRC_SIZE(width, height)		REG_RESIZER_SOURCE_IMAGE_SIZE=(width|(height<<16));

/* Macros of resizer target image size register */
#define SET_RESIZER_TARGET_SIZE(width, height)	REG_RESIZER_TARGET_IMAGE_SIZE=(width|(height<<16));

/* Macros of resizer block coarse shrinking config register */
#define SET_RESIZER_BLOCK_CS_V_V_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_V_V_SAMPLE_FACTOR_MASK;\
										            			REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<14);
#define SET_RESIZER_BLOCK_CS_V_H_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_V_H_SAMPLE_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<12);
#define SET_RESIZER_BLOCK_CS_U_V_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_U_V_SAMPLE_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<10);
#define SET_RESIZER_BLOCK_CS_U_H_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_U_H_SAMPLE_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<8);
#define SET_RESIZER_BLOCK_CS_Y_V_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_Y_V_SAMPLE_FACTOR_MASK;\
            													REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<6);
#define SET_RESIZER_BLOCK_CS_Y_H_FACTOR(factor)		REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_Y_H_SAMPLE_FACTOR_MASK;\
				            									REG_RESIZER_BLOCK_CS_CFG |= ((factor>>1)<<4);
#define SET_RESIZER_BLOCK_CS_FACTOR(factor)			REG_RESIZER_BLOCK_CS_CFG &= ~RESIZER_BLOCk_CS_CFG_CS_FACTOR_MASK;\
													            REG_RESIZER_BLOCK_CS_CFG |= factor;

/* macros of resizer fine resizer config register */
#define SET_RESIZER_FINE_RESIZE_WORK_MEM_SIZE(line)	REG_RESIZER_FINE_RESIZE_CFG &= ~RESIZER_FINE_RESIZE_WORK_MEM_SIZE_MASK;\
               													REG_RESIZER_FINE_RESIZE_CFG |= (line<<16);

/* macros of resizer YUV2RGB config register */
#define ENABLE_RESIZER_YUV2RGB_INT		REG_RESIZER_YUV2RGB_CFG |= RESIZER_YUV2RGB_INT_ENABLE_BIT;
#define DISABLE_RESIZER_YUV2RGB_INT		REG_RESIZER_YUV2RGB_CFG &= ~RESIZER_YUV2RGB_INT_ENABLE_BIT;

/* macros of resizer line buffer size register */
#define SET_RESIZER_CS_LINE_BUFFER(n)		REG_RESIZER_LINE_BUFFER_SIZE &= ~RESIZER_BLOCk_CS_LINE_BUFF_SIZE_MASK; \
            										REG_RESIZER_LINE_BUFFER_SIZE |= n;

/* macros of resizer interrupt status register */
#define IS_RESIZER_COMPLETE_INT		(REG_RESIZER_INT_STATUS & RESIZER_YUV2RGB_INT_STATUS_BIT)
#endif /* MT6218B, MT6217 */

#if (defined(DRV_JPG_DATA_PATH_19_SERIES))
#define REG_RESIZER_STATUS		 *((volatile unsigned int *) (RESIZER_base + 0x08))
#define RESIZER_CTRL_BLOCK_CS_BUSY_BIT			0x00000001
#define RESIZER_CTRL_HR_BUSY_BIT					0x00000002
#define RESIZER_CTRL_VR_BUSY_BIT					0x00000004

#define IS_BLOCK_CS_BUSY		(REG_RESIZER_STATUS & RESIZER_CTRL_BLOCK_CS_BUSY_BIT)
#define IS_HR_BUSY	 			(REG_RESIZER_STATUS & RESIZER_CTRL_HR_BUSY_BIT)
#define IS_VR_BUSY			 	(REG_RESIZER_STATUS & RESIZER_CTRL_VR_BUSY_BIT)
#elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
#define REG_PRZ_STATUS			*((volatile unsigned int *) (PRZ_base + 0x08))
#define PRZ_CTRL_BLOCK_CS_BUSY_BIT			0x00000001
#define PRZ_CTRL_HR_BUSY_BIT					0x00000002
#define PRZ_CTRL_VR_BUSY_BIT					0x00000004

#define IS_BLOCK_CS_BUSY		(REG_PRZ_STATUS & PRZ_CTRL_BLOCK_CS_BUSY_BIT)
#define IS_HR_BUSY	 			(REG_PRZ_STATUS & PRZ_CTRL_HR_BUSY_BIT)
#define IS_VR_BUSY			 	(REG_PRZ_STATUS & PRZ_CTRL_VR_BUSY_BIT)
#endif

/* markers of JPEG standard */
#define JPEG_MARKER_SOF0		0xC0
#define JPEG_MARKER_SOF1		0xC1
#define JPEG_MARKER_SOF2		0xC2
#define JPEG_MARKER_SOF3		0xC3
#define JPEG_MARKER_SOF5		0xC5
#define JPEG_MARKER_SOF6		0xC6
#define JPEG_MARKER_SOF7		0xC7
#define JPEG_MARKER_SOF9		0xC9
#define JPEG_MARKER_SOF10		0xCA
#define JPEG_MARKER_SOF11		0xCB
#define JPEG_MARKER_SOF13		0xCD
#define JPEG_MARKER_SOF14		0xCE
#define JPEG_MARKER_SOF15		0xCF
#define JPEG_MARKER_DHT			0xC4
#define JPEG_MARKER_DAC			0xCC
#define JPEG_MARKER_RST0		0xD0
#define JPEG_MARKER_RST1		0xD1
#define JPEG_MARKER_RST2		0xD2
#define JPEG_MARKER_RST3		0xD3
#define JPEG_MARKER_RST4		0xD4
#define JPEG_MARKER_RST5		0xD5
#define JPEG_MARKER_RST6		0xD6
#define JPEG_MARKER_RST7		0xD7
#define JPEG_MARKER_SOI			0xD8
#define JPEG_MARKER_EOI			0xD9
#define JPEG_MARKER_SOS			0xDA
#define JPEG_MARKER_DQT			0xDB
#define JPEG_MARKER_DNL			0xDC
#define JPEG_MARKER_DRI			0xDD
#define JPEG_MARKER_DHP			0xDE
#define JPEG_MARKER_EXP			0xDF
#define JPEG_MARKER_APP0		0xE0
#define JPEG_MARKER_APP1		0xE1
#define JPEG_MARKER_APP2		0xE2
#define JPEG_MARKER_APP3		0xE3
#define JPEG_MARKER_APP4		0xE4
#define JPEG_MARKER_APP5		0xE5
#define JPEG_MARKER_APP15		0xEF
#define JPEG_MARKER_JPG0		0xF0
#define JPEG_MARKER_JPG14		0xFD
#define JPEG_MARKER_COM			0xFE

/* definition of TAG ID for EXIF file */
#define EXIF_TAG_IMAGE_WIDTH			0x0100
#define EXIF_TAG_IMAGE_HEIGHT			0x0101
#define EXIF_TAG_COMPRESSION			0x0103
#define EXIF_TAG_PIXEL_COMPOSITION	0x0106
#define EXIF_TAG_STRIP_OFFSET			0x0111
#define EXIF_TAG_JPEG_SOI_OFFSET		0x0201
#define EXIF_TAG_JPEG_SIZE				0x0202

#define EXIF_NON_COMPRESSED		1
#define EXIF_JPEG_COMPRESSED		6

#define EXIF_NON_COMPRESSED_RGB	2
#define EXIF_NON_COMPRESSED_YUV	6

#define EXIF_TAG_TYPE_SHORT		3
#define EXIF_TAG_TYPE_LONG			4

#define NO_THUMBNAIL_MODE			0
#define JFIF_MODE_RGB				1
#define JFIF_EXTENSION_MODE_RGB	2
#define JFIF_EXTENSION_MODE_JPEG	3
#define EXIF_MODE_RGB				4
#define EXIF_MODE_JPEG				5

typedef struct
{
	kal_bool		jpg_progressive;
	kal_uint16  jpg_width;
	kal_uint16	jpg_height;
	kal_uint16	jpg_decode_width;		/* picture width after decode with dummy data */
	kal_uint16	jpg_decode_height;		/* picture width after decode with dummy data */
	kal_uint8	jpg_precision;
	kal_uint8 	number_of_component;
	kal_uint8 	y_h_sample_factor;
	kal_uint8 	y_v_sample_factor;
	kal_uint8 	u_h_sample_factor;
	kal_uint8 	u_v_sample_factor;
	kal_uint8 	v_h_sample_factor;
	kal_uint8 	v_v_sample_factor;
	kal_uint8	max_h_sample_factor;
	kal_uint8	max_v_sample_factor;
	kal_uint8 	component_id1;
	kal_uint8 	component_id2;
	kal_uint8 	component_id3;
	kal_uint8 	q_table_id1;		/* Q table ID of component 1*/
	kal_uint8	q_table_id2;		/* Q table ID of component 2*/
	kal_uint8	q_table_id3;		/* Q table ID of component 3*/
	kal_uint8	progressive_decode_times;
	kal_uint16  interleave_mcu_increament_index;
	kal_uint16  non_interleav_mcu_increament_index_y;
	kal_uint16  non_interleav_mcu_increament_index_u;
	kal_uint16  non_interleav_mcu_increament_index_v;
	kal_uint32  thumbnail_offset;
	kal_uint32  jpeg_decoder_ctrl_reg;
	kal_uint32  reset_jpeg_file_size;

	kal_uint8	jfif_mode;
	kal_uint32 	thumbnail_size;
} jpeg_parameter_struct;

typedef struct
{
	kal_bool  	jpeg_thumbnail_mode;				/* decode thumbnail or not */
	kal_uint8	jpeg_decode_retry_flag;

	kal_uint32  jpeg_file_handle;					/* JPEG file handler */
	kal_uint32	jpeg_file_buffer_address;		/* the start address of JPEG file located */
	kal_uint32	jpeg_file_size;					/* the size of JPEG file to be decoded */
	kal_uint32	jpeg_file_buffer_size;			/* the buffer size for JPEG file to be decoded */
	kal_uint32  rest_jpeg_file_size;				/* the rest JPEG file size that waiting for decode */
	kal_uint32	intmem_start_address;			/* internal memory start address for hardware engine buffer */
	kal_uint32	intmem_size;						/* internal memory size for hardware engine buffer */
	kal_uint32	extmem_start_address;			/* external memroy start address for hardware engine buffer */
	kal_uint32	extmem_size;						/* external memory size for hardware engine buffer */
	kal_uint32	image_buffer_address;			/* image buffer address for jpeg decode result */
	kal_uint32	image_buffer_size;				/* image buffer size for jpeg decode result */
	kal_uint16	image_width;						/* the image width after decoder and resizer */
															/* for MT6228 and MT6229, the image width is for LCD display */
	kal_uint16	image_height;						/* the image height after decoder and resizer */
															/* for MT6228 and MT6229 the image height is for LCD display */
	kal_uint16  image_clip_x1;						/* clip window start x for clipping decoded image */
	kal_uint16  image_clip_x2;						/* clip window end x for clipping decoded image */
	kal_uint16	image_clip_y1;						/* clip window start y for clipping decoded image */
	kal_uint16	image_clip_y2;						/* clip window end y for clipping decoded image */

	#ifdef 	DRV_IMG_PITCH_MODE_SUPPORT
	kal_bool		image_pitch_mode;					/* KAL_TRUE or KAL_FALSE for block mode of decoded image */
	kal_uint16	image_pitch_bytes;				/* pitch width */
	#endif

	#ifdef DRV_IMG_RGB888_OUTPUT_SUPPORT
	kal_uint8	image_data_format;				/* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
	#endif

	#ifdef DRV_IMG_MEM_OUTPUT_SUPPORT
	kal_bool		memory_output;						/* output another image for TV output */
	kal_uint16	memory_output_width;				/* image width for TV output */
	kal_uint16	memory_output_height;			/* image height for TV output */
	kal_uint32 	memory_output_buffer_address;
	kal_uint32 	memory_output_buffer_size;
#endif
	
	//#if defined (DRV_JPG_SW_DEC_SUPPORT)
	kal_uint32 	jpg_timeout_period;			/* Currently only effect in sw_jpeg_decoer */
	//#endif
	
	void (*jpeg_decode_cb) (kal_uint8 return_code);	/* call back function for jpeg decoder */
}	jpeg_decode_process_struct;

/* temp solution */
#if 0 //move to img_comm.h
#if(!defined(__SW_JPEG_CODEC_SUPPORT__) && defined(DRV_RGB_RESIZE_SUPPORT))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
//#if (defined(DRV_JPG_RESIZE_SUPPORT))
typedef struct
{
	kal_uint32  jpeg_file_handle;					/* JPEG file handler */
	kal_uint32	jpeg_file_buffer_address;		/* the start address of JPEG file located */
	kal_uint32	jpeg_file_size;					/* the size of JPEG file to be decoded */
	kal_uint32	jpeg_file_buffer_size;			/* the buffer size for JPEG file to be decoded */
	kal_uint32  rest_jpeg_file_size;				/* the rest JPEG file size that waiting for decode */
	kal_uint32	intmem_start_address;			/* internal memory start address for hardware engine buffer */
	kal_uint32	intmem_size;						/* internal memory size for hardware engine buffer */
	kal_uint32	extmem_start_address;			/* external memroy start address for hardware engine buffer */
	kal_uint32	extmem_size;						/* external memory size for hardware engine buffer */
	kal_uint16 	target_width;						/* the width of target image */
	kal_uint16 	target_height;						/* the height of target image */
	kal_uint8  	image_quality;						/* the image quality after encoded */
	kal_uint32	target_jpeg_file_address;		/* the start address for encoded JPEG file */
	kal_uint32 	target_jpeg_file_buffer_size;	/* the maximum size of jpeg file after encode */

	#ifdef DRV_JPG_ENC_MULTI_FORMAT_SUPPORT
	kal_uint8	jpeg_yuv_mode;						/* YUV420, YUV422 or Gray mode*/
	#endif

	#ifdef DRV_JPG_ENC_THUMBNAIL_SUPPORT
	kal_bool		thumbnail_mode;
	kal_uint16	thumbnail_width;
	kal_uint16 	thumbnail_height;
	#endif

	#ifdef DRV_JPG_ENC_OVERLAY_SUPPORT
	kal_bool 	overlay_frame_mode;				/* KAL_TRUE or KAL_FALSE */
	kal_uint8	overlay_color_depth;				/* 1/2/4/8 bpp */
	kal_uint8	overlay_frame_source_key;
	kal_uint16  overlay_frame_width;
	kal_uint16	overlay_frame_height;
	kal_uint32  overlay_frame_buffer_address;
	#endif
}	jpeg_file_resize_struct;
//#endif

#if (defined(DRV_JPG_HW_ENC_SUPPORT))
typedef struct
{
	IMGDMA_DATA_TYPE_ENUM type;				/* RGB565 or RGB888 */
	IMGDMA_DATA_ORDER_ENUM data_order;		/* BGR888 or RGB888 */
	kal_uint32 image_buffer_address;			/* the RGB565 image buffer start address */
	kal_uint32 intmem_start_address;			/* internal memory start address for hardware engine buffer */
	kal_uint32 intmem_size;						/* internal memory size for hardware engine buffer */
	kal_uint32 extmem_start_address;			/* external memroy start address for hardware engine buffer */
	kal_uint32 extmem_size;						/* external memory size for hardware engine buffer */
	kal_uint16 image_width;						/* the width of image source */
	kal_uint16 image_height;					/* the height of image source */
	kal_uint16 target_width;					/* the width of target image */
	kal_uint16 target_height;					/* the height of target image */
	kal_uint8  image_quality;					/* the image quality after encoded */
	kal_uint8  jpeg_gray_mode;					/* encode a file as gray mode or not */
	kal_uint32 jpeg_file_start_address;		/* the start address for encoded JPEG file */
	kal_uint32 jpeg_file_buffer_size;		/* the maximum size of jpeg file after encode */

	#ifdef DRV_JPG_ENC_MULTI_FORMAT_SUPPORT
	kal_uint8	jpeg_yuv_mode;						/* YUV420, YUV422 or Gray mode*/
	#endif

	#ifdef DRV_JPG_ENC_THUMBNAIL_SUPPORT
	kal_bool		thumbnail_mode;					/* add thumbnail in JPEG file or not */
	kal_uint16	thumbnail_width;
	kal_uint16 	thumbnail_height;
	#endif

	#ifdef DRV_JPG_ENC_OVERLAY_SUPPORT
	kal_bool 	overlay_frame_mode;				/* KAL_TRUE or KAL_FALSE */
	kal_uint8	overlay_color_depth;				/* 1/2/4/8 bpp */
	kal_uint8	overlay_frame_source_key;		/* source key of the overlay frame buffer */
	kal_uint16  overlay_frame_width;				/* overlay frame width */
	kal_uint16	overlay_frame_height;			/* overlay frame height */
	kal_uint32  overlay_frame_buffer_address;	/* bsae address of the overlay frame buffer */
#endif
	void (*jpeg_encode_cb) (kal_uint8 return_code);	/* call back function for jpeg encoder */
}	jpeg_encode_process_struct;

#define JPEG_ENCODER_COLOR_MODE		KAL_FALSE
#define JPEG_ENCODER_GRAY_MODE		KAL_TRUE
#endif //DRV_JPG_HW_ENC_SUPPORT

/* definition of Jpeg decode process return code */
#define JPEG_DECODE_SUCCESS								0x00
#define JPEG_DECODE_DECODING								0x01
#define JPEG_DECODE_INT_BUFFER_NOT_ENOUGH		0x02
#define JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH		0x03
#define JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH		0x04
#define JPEG_DECODE_NO_UV_COMPONENT			0x05	/* only for MT6218B */
#define JPEG_DECODE_DECODER_OVERFLOW_FAIL		0x06	/* JPEG decoder overflow */
#define JPEG_DECODE_DECODER_BREAK_FAIL			0x07	/* JPEG file end can't find */
#define JPEG_DECODE_DECODER_TIMEOUT_FAIL		0x08	/* JPEG decoder decode timeout fail */
#define JPEG_DECODE_RESIZER_FAIL			0x09	/* resizer resize fail */
#define JPEG_DECODE_RESIZER_TIMEOUT_FAIL		0x0A	/* Resizer timeout fail */
#define JPEG_DECODE_WRONG_JPEG_FILE			0x0B
#define JPEG_DECODE_UNSUPPORT_FORMAT			0x0C
#define JPEG_DECODE_BUFFER_SIZE_FAIL			0x0D	/* JPEG decoder buffer sizer fail */
#define JPEG_DECODE_TARGET_SIZE_FAIL			0x0E
#define JPEG_DECODE_NO_THUMBNAIL_FAIL			0x0F	/* Retry jpeg thumbnail but no thumbnail found */
#define JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL		0x10
#define JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL		0x11
#define JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL		0x12
#define JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL	0x13
#define JPEG_DECODE_DIMENSION_FAIL			0x10
#define JPEG_DECODE_FILE_READ_ERROR			0x20
#define JPEG_DECODE_SAMPLE_FACTOR_NOT_SUPPORT		0x21
#define JPEG_DECODE_ABORTED                 0x22

#define JPEG_DECODE_RGB_THUMBNAIL						0x80

/* definition of JPEG encode process return code */
#define JPEG_ENCODE_SUCCESS				0x80
#define JPEG_ENCODE_BUFFER_FULL			0x81

/* definition for jpeg decode result */
#define JPEG_DECODE_FILE_OVERFLOW	0x01
#define JPEG_DECODE_BREAK				0x02
#define JPEG_DECODE_COMPLETE			0x04


#define jpeg_DRM_read_file(jpeg_file_handle,jpg_file_ptr,jpeg_file_buffer_size,fs_read_size)\
	if(DRM_read_file(jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, fs_read_size)!=FS_NO_ERROR)\
	{\
	 jpeg_drm_read_error_count++;\
	 jpeg_driver_status=JPEG_DECODE_FILE_READ_ERROR;\
	 return JPEG_DECODE_FILE_READ_ERROR;}
	 
#define jpeg_DRM_seek_file(jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN)\
 if(DRM_seek_file(jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN)<0)\
	{\
	 jpeg_drm_seek_error_count++;\
	 jpeg_driver_status=JPEG_DECODE_FILE_READ_ERROR;\
	 return JPEG_DECODE_FILE_READ_ERROR;}
	 
#if (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_DEC_28_SERIES))
#define JPEG_DECODE_IMG_DMA_COMPLETE   0x08
#endif

/* definition of resizer result */
#define JPEG_RESIZER_RESIZING		0x00
#define JPEG_RESIZER_COMPLETE		0x01
#define JPEG_RESIZER_FAIL			0x02

extern jpeg_parameter_struct jpeg_file_para;
extern jpeg_decode_process_struct jpeg_decode_config_data;
extern volatile JPEG_DECODER_STATE_ENUM jpeg_decoder_operation_state;

#if (defined(DRV_JPG_HW_ENC_SUPPORT))

kal_uint8 config_jpeg_encoder(jpeg_encode_process_struct *jpeg_data);
kal_uint32 jpeg_encode_process(jpeg_encode_process_struct *jpeg_encode_para);
kal_uint8 exit_jpeg_encode_process(void);
kal_uint32 jpeg_encode_snapshot_process(jpeg_encode_process_struct *jpeg_encode_para);

extern jpeg_encode_process_struct jpeg_encode_config_data;
extern volatile JPEG_ENCODER_STATE_ENUM jpeg_encoder_operation_state;
extern kal_uint8 jpeg_encoder_encode_result;
#elif (defined(DRV_JPG_SW_ENC_SUPPORT))
kal_uint32 jpeg_encode_process(jpeg_encode_process_struct *jpeg_encode_para);
extern jpeg_encode_process_struct jpeg_encode_config_data;
//extern kal_uint8 jpeg_encoder_encode_result;
//extern volatile JPEG_ENCODER_STATE_ENUM jpeg_encoder_operation_state;
#endif


void jpeg_codec_power_up(void);
void jpeg_codec_power_down(void);
void jpeg_codec_init(void);
void jpeg_codec_deinit(void);
kal_uint32 jpeg_decode_time_estimate(void);
void get_jpeg_resize_size(kal_uint32 jpg_file_handle,kal_uint32 jpg_file_start_address,
								  kal_uint32 jpg_file_buffer_size,
		                    kal_uint16 *display_width, kal_uint16 *display_height,
      		              kal_uint16 *resize_width, kal_uint16 *resize_height);

void get_jpeg_file_size(kal_uint32 jpg_file_handle,kal_uint32 jpg_file_start_address,
								kal_uint32 jpg_file_buffer_size,kal_uint16 *image_width,
								kal_uint16 *image_height);

kal_uint8 stop_jpeg_decode_process(void);
kal_uint8 jpeg_decode_process(jpeg_decode_process_struct *jpeg_decode_para);
void jpeg_video_play_callback(kal_uint8 return_code);
void start_jpeg_video_play(lcd_frame_update_struct *lcd_para);

void sw_jpeg_hook_decode_progress_callback(kal_int32 (*decode_progress_callback)(void));


#if(defined(DRV_JPG_SW_DEC_SUPPORT))
kal_uint8 jpeg_video_play(jpeg_decode_process_struct *jpeg_decode_para,kal_bool update_to_lcd);
#else
kal_uint8 jpeg_video_play(jpeg_decode_process_struct *jpeg_decode_para,
								  kal_uint16 *frame_buf_ptr, kal_uint16 frame_buf_width,kal_bool update_to_lcd);
#endif
void stop_jpeg_video_play(void);
kal_uint32 decode_jpeg_next_block(void);
void jfif_thumbnail_swap(kal_uint32 jpeg_file_addr);
#if (defined(DRV_JPG_RESIZE_SUPPORT))
kal_uint32 jpeg_resize_process(jpeg_file_resize_struct *jpeg_resize_para);
#endif

#endif
#endif /* _JPEG_H */


