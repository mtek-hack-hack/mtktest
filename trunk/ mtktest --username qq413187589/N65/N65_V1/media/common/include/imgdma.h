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
 *    imgdma.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of image dma
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef IMGDMA_H
#define IMGDMA_H

#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "imgdma_6238_series.h"

#else

#if (defined(DRV_IDP_6219_SERIES))
#define IMGDMA_BASE 		(IMGDMA_base)

#define IMGDMA_STA		(IMGDMA_BASE+0x000)
#define IMGDMA_ACKINT	(IMGDMA_BASE+0x004)
// JPEG DMA
#define IMGDMA_JPEG_STR (IMGDMA_BASE+0x100)
#define IMGDMA_JPEG_CON	(IMGDMA_BASE+0x104)
#define IMGDMA_JPEG_BSADDR (IMGDMA_BASE+0x108)
#define IMGDMA_JPEG_HSIZE (IMGDMA_BASE+0x10C)
#define IMGDMA_JPEG_VSIZE (IMGDMA_BASE+0x110)
#define IMGDMA_JPEG_FIFOLEN (IMGDMA_BASE+0x114)
#define IMGDMA_JPEG_WRPTR	(IMGDMA_BASE+0x118)
#define IMGDMA_JPEG_WRXCNT	(IMGDMA_BASE+0x11C)
#define IMGDMA_JPEG_WRYCNT	(IMGDMA_BASE+0x120)
#define IMGDMA_JPEG_RDPTR	(IMGDMA_BASE+0x124)
#define IMGDMA_JPEG_RDXCNT	(IMGDMA_BASE+0x128)
#define IMGDMA_JPEG_RDYCNT	(IMGDMA_BASE+0x12C)
#define IMGDMA_JPEG_FFCNT	(IMGDMA_BASE+0x130)
#define IMGDMA_JPEG_FFWRYIDX	(IMGDMA_BASE+0x134)
#define IMGDMA_JPEG_FFRDYIDX	(IMGDMA_BASE+0x138)
// VDO DMA
#define IMGDMA_VDO_STR	(IMGDMA_BASE+0x200)
#define IMGDMA_VDO_CON	(IMGDMA_BASE+0x204)
#define IMGDMA_VDO_BSADDR1	(IMGDMA_BASE+0x208)
#define IMGDMA_VDO_BSADDR2	(IMGDMA_BASE+0x20C)
#define IMGDMA_VDO_HSIZE	(IMGDMA_BASE+0x210)
#define IMGDMA_VDO_VSIZE	(IMGDMA_BASE+0x214)
#define IMGDMA_VDO_HCNT	(IMGDMA_BASE+0x218)
#define IMGDMA_VDO_VCNT	(IMGDMA_BASE+0x21C)
// IBW1 DMA
#define IMGDMA_IBW1_STR	(IMGDMA_BASE+0x300)
#define IMGDMA_IBW1_CON	(IMGDMA_BASE+0x304)
#define IMGDMA_IBW1_BSADDR	(IMGDMA_BASE+0x308)
#define IMGDMA_IBW1_PXLNUM	(IMGDMA_BASE+0x30C)
#define IMGDMA_IBW1_RMGPXL	(IMGDMA_BASE+0x310)
// IBW2 DMA
#define IMGDMA_IBW2_STR	(IMGDMA_BASE+0x400)
#define IMGDMA_IBW2_CON	(IMGDMA_BASE+0x404)
#define IMGDMA_IBW2_BSADDR1 (IMGDMA_BASE+0x408)
#define IMGDMA_IBW2_BSADDR2 (IMGDMA_BASE+0x40C)
#define IMGDMA_IBW2_HSIZE (IMGDMA_BASE+0x410)
#define IMGDMA_IBW2_VSIZE (IMGDMA_BASE+0x414)
#define IMGDMA_IBW2_HPITCH1 (IMGDMA_BASE+0x418)
#define IMGDMA_IBW2_HPITCH2 (IMGDMA_BASE+0x41C)
#define IMGDMA_IBW2_VPITCH1 (IMGDMA_BASE+0x420)
#define IMGDMA_IBW2_VPITCH2 (IMGDMA_BASE+0x424)
#define IMGDMA_IBW2_HCNT (IMGDMA_BASE+0x428)
#define IMGDMA_IBW2_VCNT (IMGDMA_BASE+0x42C)
// IBR1 DMA
#define IMGDMA_IBR1_STR	(IMGDMA_BASE+0x500)
#define IMGDMA_IBR1_CON	(IMGDMA_BASE+0x504)
#define IMGDMA_IBR1_BSADDR	(IMGDMA_BASE+0x508)
#define IMGDMA_IBR1_PXLNUM	(IMGDMA_BASE+0x50C)
#define IMGDMA_IBR1_RMGPXL	(IMGDMA_BASE+0x510)

// bit position
#define IMGDMA_STA_JPEGIT	0x1
#define IMGDMA_STA_VDOIT	0x2
#define IMGDMA_STA_IBW1IT	0x4
#define IMGDMA_STA_IBW2IT	0x8
#define IMGDMA_STA_IBR1IT	0x10
#define IMGDMA_STA_TWCIT	0x100
#define IMGDMA_STA_JPEGRUN	0x10000
#define IMGDMA_STA_VDORUN	0x20000
#define IMGDMA_STA_IBW1RUN	0x40000
#define IMGDMA_STA_IBW2RUN	0x80000
#define IMGDMA_STA_IBR1RUN	0x100000

#define IMGDMA_JPEG_CON_IT 0x1 // enable interrupt
#define IMGDMA_JPEG_CON_GRAY 0x2 // gray mode

#define IMGDMA_VDO_CON_DONEIT 0x1 // enalbe interrupt of second run
#define IMGDMA_VDO_CON_DIR 0x2 // 1:encode, 0: decode
#define IMGDMA_VDO_CON_TWC 0x4 // enable twice resize
#define IMGDMA_VDO_CON_TWCIT 0x8 // enable interrupt of first run
#define IMGDMA_VDO_CON_AUTORSTR 0x10 // enable auto restart per frame
#define IMGDMA_VDO_CON_ROT_MASK 0x60 // rotation
#define IMGDMA_VDO_CON_ROT_0   0x0 // rotate 0 degree
#define IMGDMA_VDO_CON_ROT_90  0x2 // rotate 90 degree
#define IMGDMA_VDO_CON_ROT_180 0x4 // rotate 180 degree
#define IMGDMA_VDO_CON_ROT_270 0x6 // rotate 270 degree

#define IMGDMA_IBW1_CON_IT 0x1 // enable interrupt

#define IMGDMA_IBW2_CON_IT 0x1 // enable interrupt
#define IMGDMA_IBW2_CON_TWC 0x2 // enable twice resize
#define IMGDMA_IBW2_CON_LCD 0x4 // enable hardware handshake with LCD
#define IMGDMA_IBW2_CON_ATUORSTR 0x08 // enable auto restart per frame
#define IMGDMA_IBW2_CON_DC 0x10 // enable directly coupling with LCD
#define IMGDMA_IBW2_CON_PAN 0x20 // enable picture panning

#define IMGDMA_IBR1_CON_IT 0x1 // enable interrupt
#define IMGDMA_IBR1_CON_FMT 0x2 // data format
#define IMGDMA_IBR1_CON_ORDER 0x4 // data order

typedef void (*IDMA_Callback)();

typedef enum{
	IMGDMA_JPEG_CH,
	IMGDMA_VDO_CH,
	IMGDMA_IBW1_CH,
	IMGDMA_IBW2_CH,
	IMGDMA_IBR1_CH,
	IMGDMA_ALL_CH
}IMGDMA_CHANNEL_ENUM;

typedef enum{
	IMGDMA_MPEG4_DECODE,
	IMGDMA_MPEG4_ENCODE
}IMGDMA_DIR_ENUM;

typedef enum{
	IBR1_TYPE_RGB565,
	IBR1_TYPE_RGB888
}IMGDMA_DATA_TYPE_ENUM;

typedef enum{
	IBR1_ORDER_BGR888,
	IBR1_ORDER_RGB888
}IMGDMA_DATA_ORDER_ENUM;

typedef enum{
	IMGDMA_INIT,
	IMGDMA_READY,
	IMGDMA_BUSY
}IMGDMA_STATE_ENUM;

typedef enum{
	IMGDMA_STOP_NOW,
	IMGDMA_STOP_CALLBACK,	// for channel without enable auto_restart
	IMGDMA_STOP_AT_FRAME_BOUNDARY, // for channel eanbled auto_restart
	IMGDMA_STOP_IDLE
}IMGDMA_STOP_ENUM;

typedef struct{
	kal_uint32 bs;	// line buffer base address
	kal_uint16 width;	// image width(minus 1 before writing to register)
	kal_uint16 height; // image height
	kal_uint16 fifo;	// fifo length
	kal_bool gray; // 1: for gray mode, 0: for color mode
	IDMA_Callback cb;	// interrupt callback function NULL: disable interrupt
}IMGDMA_JPEG_STRUCT;

typedef struct{
	IMGDMA_DIR_ENUM dir;	// 1: for MEPG4 encode, 0: for MPEG4 decode
	kal_bool	twice;	// 1: enable twice resizing 0: disable
	kal_bool restart; // 1: automatic reastart while current frame is finished
	kal_uint32 bs1;	// first base address
	kal_uint32 bs2;	// second base address
	kal_uint16 width;	// frame width (1 stands for 1)(max 255)
	kal_uint16 height;	// frame height
	void (*cb1)(kal_uint32 yuv_address);	// interrupt callback function NULL: disable interrupt(first run)
	IDMA_Callback cb2;	// interrupt callback function NULL: disable interrupt(second run)
}IMGDMA_VDO_STRUCT;

typedef struct{
	kal_uint32 bs;	// buffer base address
	kal_uint32 pxlnum; // number of pixels(minus 1 before writing to register)
	IDMA_Callback cb;	// interrupt callback function NULL: disable interrupt
}IMGDMA_IBW1_STRUCT;

typedef struct{
	kal_bool	twice; // 1: enable twice resizing 0: disable
	kal_bool restart; // 1: automatic reastart while current frame is finished
	kal_bool lcd_hk; // signaling LCD DMA while current frame is complete.
	kal_bool couple; // directly coupling to LCD DMA
	kal_bool pan; // picture panning
	kal_uint32 bs1; // first base address
	kal_uint32 bs2; // second base address
	kal_uint16 width;	// image width(minus 1 before writing to register)
	kal_uint16 height; // image height
	kal_uint16 hpitch1; // horizontal pitch 1
	kal_uint16 hpitch2; // horizontal pitch 2
	kal_uint16 vpitch1; // vertical pitch 1
	kal_uint16 vpitch2; // vertical pitch 2
	IDMA_Callback cb;	// interrupt callback function NULL: disable interrupt
}IMGDMA_IBW2_STRUCT;

typedef struct{
	IMGDMA_DATA_TYPE_ENUM	type; //RGB565 or RGB888
	IMGDMA_DATA_ORDER_ENUM	order; //BGR888 or RGB888
	kal_uint32 bs;	// base address
	kal_uint32 pxlnum; // number of pixels(minus 1 before writing to register)
	IDMA_Callback cb;	// interrupt callback function NULL: disable interrupt
}IMGDMA_IBR1_STRUCT;

typedef struct{
	kal_bool twice;
	kal_bool stop_cb[IMGDMA_ALL_CH];
	MMDI_SCENERIO_ID owner;
	IMGDMA_STATE_ENUM state[IMGDMA_ALL_CH];
	IDMA_Callback cb[IMGDMA_ALL_CH+1]; // one for first run of VDO
}IMGDMA_DCB_STRUCT;

// macros
#define IMGDMA_STR(ch)					(IMGDMA_BASE+0x100*(ch+1))
#define IMGDMA_CON(ch)					(IMGDMA_BASE+0x100*(ch+1)+4)
#define IMGDMA_START(ch)				{DRV_WriteReg32(IMGDMA_STR(ch), 0); \
                                    DRV_WriteReg32(IMGDMA_STR(ch), 1);}
#define IMGDMA_STOP(ch)					DRV_WriteReg32(IMGDMA_STR(ch), 0)
#define IMGDMA_ENABLE_INT(ch) 		DRV_Reg((0x100*(ch+1)+ 4))|= 1
#define IMGDMA_DISABLE_INT(ch) 		DRV_Reg((0x100*(ch+1)+ 4))&= ~1
#define IMGDMA_IS_BUSY(ch)				((DRV_Reg32(IMGDMA_STA)>>16) & (1<<ch))
#define IMGDMA_ACKI(n)					DRV_WriteReg32(IMGDMA_ACKINT,n) // n: IMGDMA_STA_JPEGIT, ...

// definitons
#define NO_ERROR 							0
#define IMGDMA_ACCESS_DENY				1

#define ENABLE_IBW2_INT			*((volatile unsigned int *)IMGDMA_IBW2_CON) |= IMGDMA_IBW2_CON_IT;
#define DISABLE_IBW2_INT		*((volatile unsigned int *)IMGDMA_IBW2_CON) &= ~IMGDMA_IBW2_CON_IT;

#define IMGDMA_IBW2_IS_BUSY		(*((volatile unsigned int *) IMGDMA_STA)&(1<<(IMGDMA_IBW2_CH+16)))

// extern functions
extern void IMGDMA_Init(void);
extern kal_int32 IMGDMA_JpegConfig(IMGDMA_JPEG_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_VdoConfig(IMGDMA_VDO_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_IBW1Config(IMGDMA_IBW1_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_IBW2Config(IMGDMA_IBW2_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_IBR1Config(IMGDMA_IBR1_STRUCT *s, kal_bool start, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_Start(IMGDMA_CHANNEL_ENUM ch, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_Stop(IMGDMA_CHANNEL_ENUM ch, IMGDMA_STOP_ENUM stop, IDMA_Callback stop_cb, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_WaitComplete(IMGDMA_CHANNEL_ENUM ch, MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_Open(MMDI_SCENERIO_ID owner);
extern kal_int32 IMGDMA_Close(MMDI_SCENERIO_ID owner);
extern kal_bool IMGDMA_CheckBusy(IMGDMA_CHANNEL_ENUM ch, MMDI_SCENERIO_ID owner);
#elif (defined(DRV_IDP_6228_SERIES))
	/* register definition of Image DMA */
	#define IMGDMA_STATUS_REG							(IMGDMA_base + 0x0000)
	#define IMGDMA_INT_ACK_REG							(IMGDMA_base + 0x0004)

	#define REG_IMGDMA_STATUS							*((volatile unsigned int *)(IMGDMA_base + 0x0000))
	#define REG_IMGDMA_INT_ACK							*((volatile unsigned int *)(IMGDMA_base + 0x0004))

	/* bit mapping of image dma status register */
	#define IMGDMA_IBW4_BUSY_BIT						0x02000000
	#define IMGDMA_IBW3_BUSY_BIT						0x01000000
	#define IMGDMA_IBR2_BUSY_BIT						0x00800000
	#define IMGDMA_IBR1_BUSY_BIT						0x00400000
	#define IMGDMA_IBW2_BUSY_BIT						0x00200000
	#define IMGDMA_IBW1_BUSY_BIT						0x00100000
	#define IMGDMA_VIDEO_DECODE_BUSY_BIT			0x00080000
	#define IMGDMA_VIDEO_ENCODE_R_BUSY_BIT			0x00040000
	#define IMGDMA_VIDEO_ENCODE_W_BUSY_BIT			0x00020000
	#define IMGDMA_JPEG_BUSY_BIT						0x00010000

	#define IMGDMA_IBW4_INT_STATUS_BIT					0x00000200
	#define IMGDMA_IBW3_INT_STATUS_BIT					0x00000100
	#define IMGDMA_IBR2_INT_STATUS_BIT					0x00000080
	#define IMGDMA_IBR1_INT_STATUS_BIT					0x00000040
	#define IMGDMA_IBW2_INT_STATUS_BIT					0x00000020
	#define IMGDMA_IBW1_INT_STATUS_BIT					0x00000010
	#define IMGDMA_VIDEO_DECODE_INT_STATUS_BIT		0x00000008
	#define IMGDMA_VIDEO_ENCODE_R_INT_STATUS_BIT		0x00000004
	#define IMGDMA_VIDEO_ENCODE_W_INT_STATUS_BIT		0x00000002
	#define IMGDMA_JPEG_INT_STATUS_BIT					0x00000001

	/* bit mapping of image dma interrupt ACK register */
	#define IMGDMA_IBW4_INT_ACK_BIT					0x00000200
	#define IMGDMA_IBW3_INT_ACK_BIT					0x00000100
	#define IMGDMA_IBR2_INT_ACK_BIT					0x00000080
	#define IMGDMA_IBR1_INT_ACK_BIT					0x00000040
	#define IMGDMA_IBW2_INT_ACK_BIT					0x00000020
	#define IMGDMA_IBW1_INT_ACK_BIT					0x00000010
	#define IMGDMA_VIDEO_DECODE_INT_ACK_BIT		0x00000008
	#define IMGDMA_VIDEO_ENCODE_R_INT_ACK_BIT		0x00000004
	#define IMGDMA_VIDEO_ENCODE_W_INT_ACK_BIT		0x00000002
	#define IMGDMA_JPEG_INT_ACK_BIT					0x00000001

	/* macros of image dma status register */
	#define IMGDMA_IBW4_IS_BUSY						(REG_IMGDMA_STATUS & IMGDMA_IBW4_BUSY_BIT)
	#define IMGDMA_IBW3_IS_BUSY						(REG_IMGDMA_STATUS & IMGDMA_IBW3_BUSY_BIT)
	#define IMGDMA_IBR2_IS_BUSY						(REG_IMGDMA_STATUS & IMGDMA_IBR2_BUSY_BIT)
	#define IMGDMA_IBR1_IS_BUSY						(REG_IMGDMA_STATUS & IMGDMA_IBR1_BUSY_BIT)
	#define IMGDMA_IBW2_IS_BUSY						(REG_IMGDMA_STATUS & IMGDMA_IBW2_BUSY_BIT)
	#define IMGDMA_IBW1_IS_BUSY						(REG_IMGDMA_STATUS & IMGDMA_IBW1_BUSY_BIT)
	#define IMGDMA_VIDEO_DECODE_IS_BUSY				(REG_IMGDMA_STATUS & IMGDMA_VIDEO_DECODE_BUSY_BIT)
	#define IMGDMA_VIDEO_ENCODE_R_IS_BUSY			(REG_IMGDMA_STATUS & IMGDMA_VIDEO_ENCODE_R_BUSY_BIT)
	#define IMGDMA_VIDEO_ENCODE_W_IS_BUSY			(REG_IMGDMA_STATUS & IMGDMA_VIDEO_ENCODE_W_BUSY_BIT)
	#define IMGDMA_JPEG_IS_BUSY						(REG_IMGDMA_STATUS & IMGDMA_JPEG_BUSY_BIT)

	/* macros of image dma interrupt ACK register */
	#define ACK_IMGDMA_IBW4_INT						REG_IMGDMA_INT_ACK = IMGDMA_IBW4_INT_ACK_BIT;
	#define ACK_IMGDMA_IBW3_INT						REG_IMGDMA_INT_ACK = IMGDMA_IBW3_INT_ACK_BIT;
	#define ACK_IMGDMA_IBR2_INT						REG_IMGDMA_INT_ACK = IMGDMA_IBR2_INT_ACK_BIT;
	#define ACK_IMGDMA_IBR1_INT						REG_IMGDMA_INT_ACK = IMGDMA_IBR1_INT_ACK_BIT;
	#define ACK_IMGDMA_IBW2_INT						REG_IMGDMA_INT_ACK = IMGDMA_IBW2_INT_ACK_BIT;
	#define ACK_IMGDMA_IBW1_INT						REG_IMGDMA_INT_ACK = IMGDMA_IBW1_INT_ACK_BIT;
	#define ACK_IMGDMA_VIDEO_DECODE_INT				REG_IMGDMA_INT_ACK = IMGDMA_VIDEO_DECODE_INT_ACK_BIT;
	#define ACK_IMGDMA_VIDEO_ENCODE_R_INT			REG_IMGDMA_INT_ACK = IMGDMA_VIDEO_ENCODE_R_INT_ACK_BIT;
	#define ACK_IMGDMA_VIDEO_ENCODE_W_INT			REG_IMGDMA_INT_ACK = IMGDMA_VIDEO_ENCODE_W_INT_ACK_BIT;
	#define ACK_IMGDMA_JPEG_INT						REG_IMGDMA_INT_ACK = IMGDMA_JPEG_INT_ACK_BIT;

	/* register definition of JPEG image DMA */
	#define IMGDMA_JPEG_START_REG						(IMGDMA_base + 0x0100)
	#define IMGDMA_JPEG_CTRL_REG						(IMGDMA_base + 0x0104)
	#define IMGDMA_JPEG_BASE_ADDR_REG				(IMGDMA_base + 0x0108)
	#define IMGDMA_JPEG_WIDTH_REG						(IMGDMA_base + 0x010C)
	#define IMGDMA_JPEG_HEIGHT_REG					(IMGDMA_base + 0x0110)
	#define IMGDMA_JPEG_FIFO_LENGTH_REG				(IMGDMA_base + 0x0114)

	#define REG_IMGDMA_JPEG_START						*((volatile unsigned int *)(IMGDMA_base + 0x0100))
	#define REG_IMGDMA_JPEG_CTRL						*((volatile unsigned int *)(IMGDMA_base + 0x0104))
	#define REG_IMGDMA_JPEG_BASE_ADDR				*((volatile unsigned int *)(IMGDMA_base + 0x0108))
	#define REG_IMGDMA_JPEG_WIDTH						*((volatile unsigned int *)(IMGDMA_base + 0x010C))
	#define REG_IMGDMA_JPEG_HEIGHT					*((volatile unsigned int *)(IMGDMA_base + 0x0110))
	#define REG_IMGDMA_JPEG_FIFO_LENGTH				*((volatile unsigned int *)(IMGDMA_base + 0x0114))

	/* bit mapping of JPEG image dma control register */
	#define IMGDMA_JPEG_PIXEL_SRC_SEL_BIT			0x00000080
	#define IMGDMA_JPEG_AUTO_RESTART_BIT			0x00000008
	#define IMGDMA_JPEG_DATA_FORMAT_MASK			0x00000006
	#define IMGDMA_JPEG_INT_ENABLE_BIT				0x00000001

	#define IMGDMA_JPEG_FORMAT_YUV422				0x00000000
	#define IMGDMA_JPEG_FORMAT_GRAY					0x00000002
	#define IMGDMA_JPEG_FORMAT_YUV420				0x00000004

	#define IMGDMA_JPEG_SRC_CRZ						0x00000000
	#define IMGDMA_JPEG_SRC_PRZ						0x00000080

	/* macros of JPEG image DMA start register */
	#define START_IMGDMA_JPEG							REG_IMGDMA_JPEG_START=1;
	#define STOP_IMGDMA_JPEG							REG_IMGDMA_JPEG_START=0;

	/* macros of JPEG image DMA control register */
	#define SET_IMGDMA_JPEG_SRC_CRZ					REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_PIXEL_SRC_SEL_BIT;
	#define SET_IMGDMA_JPEG_SRC_PRZ					REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_PIXEL_SRC_SEL_BIT;
	#define ENABLE_IMGDMA_JPEG_AUTO_RESTART		REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_AUTO_RESTART_BIT;
	#define DISABLE_IMGDMA_JPEG_AUTO_RESTART		REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_AUTO_RESTART_BIT;
	#define SET_IMGDMA_JPEG_YUV422					REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_DATA_FORMAT_MASK;
	#define SET_IMGDMA_JPEG_YUV420					REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_DATA_FORMAT_MASK;\
																REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_FORMAT_YUV420;
	#define SET_IMGDMA_JPEG_GRAY						REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_DATA_FORMAT_MASK;\
																REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_FORMAT_GRAY;
	#define ENABLE_IMGDMA_JPEG_INT					REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_INT_ENABLE_BIT;
	#define DISABLE_IMGDMA_JPEG_INT					REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_INT_ENABLE_BIT;

	/* register definition of video encode image DMA */
	#define IMGDMA_VIDEO_ENCODE_START_REG			(IMGDMA_base + 0x0200)
	#define IMGDMA_VIDEO_ENCODE_CTRL_REG			(IMGDMA_base + 0x0204)
	#define IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1_REG	(IMGDMA_base + 0x0210)
	#define IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1_REG	(IMGDMA_base + 0x0214)
	#define IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1_REG	(IMGDMA_base + 0x0218)
	#define IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2_REG	(IMGDMA_base + 0x0220)
	#define IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2_REG	(IMGDMA_base + 0x0224)
	#define IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2_REG	(IMGDMA_base + 0x0228)
	#define IMGDMA_VIDEO_ENCODE_WIDTH_REG			(IMGDMA_base + 0x0230)
	#define IMGDMA_VIDEO_ENCODE_HEIGHT_REG			(IMGDMA_base + 0x0234)

	#define REG_IMGDMA_VIDEO_ENCODE_START			*((volatile unsigned int *)(IMGDMA_base + 0x0200))
	#define REG_IMGDMA_VIDEO_ENCODE_CTRL			*((volatile unsigned int *)(IMGDMA_base + 0x0204))
	#define REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1	*((volatile unsigned int *)(IMGDMA_base + 0x0210))
	#define REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1	*((volatile unsigned int *)(IMGDMA_base + 0x0214))
	#define REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1	*((volatile unsigned int *)(IMGDMA_base + 0x0218))
	#define REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2	*((volatile unsigned int *)(IMGDMA_base + 0x0220))
	#define REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2	*((volatile unsigned int *)(IMGDMA_base + 0x0224))
	#define REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2	*((volatile unsigned int *)(IMGDMA_base + 0x0228))
	#define REG_IMGDMA_VIDEO_ENCODE_WIDTH			*((volatile unsigned int *)(IMGDMA_base + 0x0230))
	#define REG_IMGDMA_VIDEO_ENCODE_HEIGHT			*((volatile unsigned int *)(IMGDMA_base + 0x0234))

	/* bit mapping of video encode image dma control register */
	#define IMGDMA_VIDEO_ENCODE_W_PIXEL_SRC_BIT	0x00000080
	#define IMGDMA_VIDEO_ENCODE_R_PIXEL_DEST_BIT	0x00000040
	#define IMGDMA_VIDEO_ENCODE_AUTO_RESTART_BIT	0x00000010
	#define IMGDMA_VIDEO_ENCODE_R_INT_BIT			0x00000008
	#define IMGDMA_VIDEO_ENCODE_W_TRIGGER_R_BIT	0x00000004
	#define IMGDMA_VIDEO_ENCODE_W_INT_BIT			0x00000001

	/* macros of Video encode image DMA start register */
	#define START_IMGDMA_VIDEO_ENCODE				REG_IMGDMA_VIDEO_ENCODE_START=1;
	#define STOP_IMGDMA_VIDEO_ENCODE					REG_IMGDMA_VIDEO_ENCODE_START=0;

	/* macros of video encode image dma control register */
	#define SET_VIDEO_ENCODE_SRC_CRZ					REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_W_PIXEL_SRC_BIT;
	#define SET_VIDEO_ENCODE_SRC_PRZ					REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_W_PIXEL_SRC_BIT;
	#define SET_VIDEO_ENCODE_R_DEST_PRZ				REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_R_PIXEL_DEST_BIT;
	#define SET_VIDEO_ENCODE_R_DEST_DRZ				REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_R_PIXEL_DEST_BIT;
	#define ENABLE_VIDEO_ENCODE_AUTO_RESTART		REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_AUTO_RESTART_BIT;
	#define DISABLE_VIDEO_ENCODE_AUTO_RESTART		REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_AUTO_RESTART_BIT;
	#define ENABLE_VIDEO_ENCODE_R_INT				REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_R_INT_BIT;
	#define DISABLE_VIDEO_ENCODE_R_INT				REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_R_INT_BIT;
	#define ENABLE_VIDEO_ENCODE_W_TRIGGER_R		REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_W_TRIGGER_R_BIT;
	#define DISABLE_VIDEO_ENCODE_W_TRIGGER_R		REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_W_TRIGGER_R_BIT;
	#define ENABLE_VIDEO_ENCODE_W_INT				REG_IMGDMA_VIDEO_ENCODE_CTRL |= IMGDMA_VIDEO_ENCODE_W_INT_BIT;
	#define DISABLE_VIDEO_ENCODE_W_INT				REG_IMGDMA_VIDEO_ENCODE_CTRL &= ~IMGDMA_VIDEO_ENCODE_W_INT_BIT;

	/* register definition of Video decode image dma */
	#define IMGDMA_VIDEO_DECODE_START_REG			(IMGDMA_base + 0x0280)
	#define IMGDMA_VIDEO_DECODE_CTRL_REG			(IMGDMA_base + 0x0284)
	#define IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1_REG	(IMGDMA_base + 0x0290)
	#define IMGDMA_VIDEO_DECODE_U_BASE_ADDR1_REG	(IMGDMA_base + 0x0294)
	#define IMGDMA_VIDEO_DECODE_V_BASE_ADDR1_REG	(IMGDMA_base + 0x0298)
	#define IMGDMA_VIDEO_DECODE_Y_BASE_ADDR2_REG	(IMGDMA_base + 0x02A0)
	#define IMGDMA_VIDEO_DECODE_U_BASE_ADDR2_REG	(IMGDMA_base + 0x02A4)
	#define IMGDMA_VIDEO_DECODE_V_BASE_ADDR2_REG	(IMGDMA_base + 0x02A8)
	#define IMGDMA_VIDEO_DECODE_WIDTH_REG			(IMGDMA_base + 0x02B0)
	#define IMGDMA_VIDEO_DECODE_HEIGHT_REG			(IMGDMA_base + 0x02B4)

	#define REG_IMGDMA_VIDEO_DECODE_START			*((volatile unsigned int *)(IMGDMA_base + 0x0280))
	#define REG_IMGDMA_VIDEO_DECODE_CTRL			*((volatile unsigned int *)(IMGDMA_base + 0x0284))
	#define REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1	*((volatile unsigned int *)(IMGDMA_base + 0x0290))
	#define REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1	*((volatile unsigned int *)(IMGDMA_base + 0x0294))
	#define REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1	*((volatile unsigned int *)(IMGDMA_base + 0x0298))
	#define REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR2	*((volatile unsigned int *)(IMGDMA_base + 0x02A0))
	#define REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR2	*((volatile unsigned int *)(IMGDMA_base + 0x02A4))
	#define REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR2	*((volatile unsigned int *)(IMGDMA_base + 0x02A8))
	#define REG_IMGDMA_VIDEO_DECODE_WIDTH			*((volatile unsigned int *)(IMGDMA_base + 0x02B0))
	#define REG_IMGDMA_VIDEO_DECODE_HEIGHT			*((volatile unsigned int *)(IMGDMA_base + 0x02B4))

	/* bit mapping of video decode image dma control register */
	#define IMGDMA_VIDEO_DECODE_INT_BIT				0x00000001

	/* macros of Video decode image DMA start register */
	#define START_IMGDMA_VIDEO_DECODE				REG_IMGDMA_VIDEO_DECODE_START=1;
	#define STOP_IMGDMA_VIDEO_DECODE					REG_IMGDMA_VIDEO_DECODE_START=0;

	/* macros of video decode image dma control register */
	#define ENABLE_VIDEO_DECODE_INT				REG_IMGDMA_VIDEO_DECODE_CTRL |= IMGDMA_VIDEO_DECODE_INT_BIT;
	#define DISABLE_VIDEO_DECODE_INT				REG_IMGDMA_VIDEO_DECODE_CTRL &= ~IMGDMA_VIDEO_DECODE_INT_BIT;

	/* register definition of IBW1 image dma */
	#define IMGDMA_IBW1_START_REG					(IMGDMA_base + 0x0300)
	#define IMGDMA_IBW1_CTRL_REG					(IMGDMA_base + 0x0304)
	#define IMGDMA_IBW1_BASE_ADDR1_REG			(IMGDMA_base + 0x0308)
	#define IMGDMA_IBW1_BASE_ADDR2_REG			(IMGDMA_base + 0x030C)
	#define IMGDMA_IBW1_WIDTH_REG					(IMGDMA_base + 0x0310)
	#define IMGDMA_IBW1_HEIGHT_REG				(IMGDMA_base + 0x0314)
	#define IMGDMA_IBW1_CLIP_LEFT_RIGHT_REG	(IMGDMA_base + 0x0318)
	#define IMGDMA_IBW1_CLIP_TOP_BUTTOM_REG	(IMGDMA_base + 0x031C)
	#define IMGDMA_IBW1_DEST_PITCH1_REG			(IMGDMA_base + 0x0320)
	#define IMGDMA_IBW1_DEST_PITCH2_REG			(IMGDMA_base + 0x0324)

	#define REG_IMGDMA_IBW1_START					*((volatile unsigned int *)(IMGDMA_base + 0x0300))
	#define REG_IMGDMA_IBW1_CTRL					*((volatile unsigned int *)(IMGDMA_base + 0x0304))
	#define REG_IMGDMA_IBW1_BASE_ADDR1			*((volatile unsigned int *)(IMGDMA_base + 0x0308))
	#define REG_IMGDMA_IBW1_BASE_ADDR2			*((volatile unsigned int *)(IMGDMA_base + 0x030C))
	#define REG_IMGDMA_IBW1_WIDTH					*((volatile unsigned int *)(IMGDMA_base + 0x0310))
	#define REG_IMGDMA_IBW1_HEIGHT				*((volatile unsigned int *)(IMGDMA_base + 0x0314))
	#define REG_IMGDMA_IBW1_CLIP_LEFT_RIGHT	*((volatile unsigned int *)(IMGDMA_base + 0x0318))
	#define REG_IMGDMA_IBW1_CLIP_TOP_BUTTOM	*((volatile unsigned int *)(IMGDMA_base + 0x031C))
	#define REG_IMGDMA_IBW1_DEST_PITCH1			*((volatile unsigned int *)(IMGDMA_base + 0x0320))
	#define REG_IMGDMA_IBW1_DEST_PITCH2			*((volatile unsigned int *)(IMGDMA_base + 0x0324))

	#define IMGDMA_IBW2_START_REG					(IMGDMA_base + 0x0400)
	#define IMGDMA_IBW2_CTRL_REG					(IMGDMA_base + 0x0404)
	#define IMGDMA_IBW2_BASE_ADDR1_REG			(IMGDMA_base + 0x0408)
	#define IMGDMA_IBW2_BASE_ADDR2_REG			(IMGDMA_base + 0x040C)
	#define IMGDMA_IBW2_WIDTH_REG					(IMGDMA_base + 0x0410)
	#define IMGDMA_IBW2_HEIGHT_REG				(IMGDMA_base + 0x0414)
	#define IMGDMA_IBW2_CLIP_LEFT_RIGHT_REG	(IMGDMA_base + 0x0418)
	#define IMGDMA_IBW2_CLIP_TOP_BUTTOM_REG	(IMGDMA_base + 0x041C)
	#define IMGDMA_IBW2_DEST_PITCH1_REG			(IMGDMA_base + 0x0420)
	#define IMGDMA_IBW2_DEST_PITCH2_REG			(IMGDMA_base + 0x0424)
	#define IMGDMA_IBW_PIXEL_COUNT_REG			(IMGDMA_base + 0x0428)
	#define IMGDMA_IBW_LINE_COUNT_REG			(IMGDMA_base + 0x042C)

	#define REG_IMGDMA_IBW2_START					*((volatile unsigned int *)(IMGDMA_base + 0x0400))
	#define REG_IMGDMA_IBW2_CTRL					*((volatile unsigned int *)(IMGDMA_base + 0x0404))
	#define REG_IMGDMA_IBW2_BASE_ADDR1			*((volatile unsigned int *)(IMGDMA_base + 0x0408))
	#define REG_IMGDMA_IBW2_BASE_ADDR2			*((volatile unsigned int *)(IMGDMA_base + 0x040C))
	#define REG_IMGDMA_IBW2_WIDTH					*((volatile unsigned int *)(IMGDMA_base + 0x0410))
	#define REG_IMGDMA_IBW2_HEIGHT				*((volatile unsigned int *)(IMGDMA_base + 0x0414))
	#define REG_IMGDMA_IBW2_CLIP_LEFT_RIGHT	*((volatile unsigned int *)(IMGDMA_base + 0x0418))
	#define REG_IMGDMA_IBW2_CLIP_TOP_BUTTOM	*((volatile unsigned int *)(IMGDMA_base + 0x041C))
	#define REG_IMGDMA_IBW2_DEST_PITCH1			*((volatile unsigned int *)(IMGDMA_base + 0x0420))
	#define REG_IMGDMA_IBW2_DEST_PITCH2			*((volatile unsigned int *)(IMGDMA_base + 0x0424))
	#define REG_IMGDMA_IBW2_PIXEL_COUNT			*((volatile unsigned int *)(IMGDMA_base + 0x0428))
	#define REG_IMGDMA_IBW2_LINE_COUNT			*((volatile unsigned int *)(IMGDMA_base + 0x042C))

	/* bit mapping of IBW1 and IBW2 control register */
	#define IMGDMA_IBW_PIXEL_SRC_MASK			0x00000180
	#define IMGDMA_IBW_OUTPUT_FORMAT_BIT		0x00000040
	#define IMGDMA_IBW_PAN_ENABLE_BIT			0x00000020
	#define IMGDMA_IBW_DC_ENABLE_BIT				0x00000010
	#define IMGDMA_IBW_AUTO_RESTART_BIT			0x00000008
	#define IMGDMA_IBW_TRIGGER_LCD_BIT			0x00000004
	#define IMGDMA_IBW_DEST_PITCH_BIT			0x00000002
	#define IMGDMA_IBW_INT_BIT						0x00000001

	#define IMGDMA_IBW_PIXEL_SRC_IPP1			0x00000000
	#define IMGDMA_IBW_PIXEL_SRC_IPP2			0x00000080
	#define IMGDMA_IBW_PIXEL_SRC_CRZ				0x00000100
	#define IMGDMA_IBW_PIXEL_SRC_PRZ				0x00000180

	#define IMGDMA_IBW_OUTPUT_RGB565				0x00000000
	#define IMGDMA_IBW_OUTPUT_RGB888				0x00000040

	/* macros of IBW1,IBW2 start register */
	#define START_IBW1								REG_IMGDMA_IBW1_START=1;
	#define STOP_IBW1									REG_IMGDMA_IBW1_START=0;
	#define START_IBW2								REG_IMGDMA_IBW2_START=1;
	#define STOP_IBW2									REG_IMGDMA_IBW2_START=0;

	/* macros of IBW1 and IBW2 control register */
	#define SET_IBW1_PIXEL_SRC_IPP1				REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;
	#define SET_IBW1_PIXEL_SRC_IPP2				REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_PIXEL_SRC_IPP2;
	#define SET_IBW1_PIXEL_SRC_CRZ				REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_PIXEL_SRC_CRZ;
	#define SET_IBW1_PIXEL_SRC_PRZ				REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_PIXEL_SRC_PRZ;
	#define SET_IBW1_PIXEL_SRC(pixel_src)		REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW1_CTRL |= pixel_src;
	#define SET_IBW1_OUTPUT_RGB565				REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_OUTPUT_FORMAT_BIT;
	#define SET_IBW1_OUTPUT_RGB888				REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_OUTPUT_FORMAT_BIT;
	#define SET_IBW1_OUTPUT_FORMAT(format)		REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_OUTPUT_FORMAT_BIT;\
															REG_IMGDMA_IBW1_CTRL |= format;
	#define ENABLE_IBW1_PAN							REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_PAN_ENABLE_BIT;
	#define DISABLE_IBW1_PAN						REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_PAN_ENABLE_BIT;
	#define ENABLE_IBW1_DC							REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_DC_ENABLE_BIT;
	#define DISABLE_IBW1_DC							REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_DC_ENABLE_BIT;
	#define ENABLE_IBW1_AUTO_RESTART				REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_AUTO_RESTART_BIT;
	#define DISABLE_IBW1_AUTO_RESTART			REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_AUTO_RESTART_BIT;
	#define ENABLE_IBW1_TRIGGER_LCD				REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_TRIGGER_LCD_BIT;
	#define DISABLE_IBW1_TRIGGER_LCD				REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_TRIGGER_LCD_BIT;
	#define ENABLE_IBW1_DEST_PITCH				REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_DEST_PITCH_BIT;
	#define DISABLE_IBW1_DEST_PITCH				REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_DEST_PITCH_BIT;
	#define ENABLE_IBW1_INT							REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW_INT_BIT;
	#define DISABLE_IBW1_INT						REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW_INT_BIT;

	#define SET_IBW2_PIXEL_SRC_IPP1				REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;
	#define SET_IBW2_PIXEL_SRC_IPP2				REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_PIXEL_SRC_IPP2;
	#define SET_IBW2_PIXEL_SRC_CRZ				REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_PIXEL_SRC_CRZ;
	#define SET_IBW2_PIXEL_SRC_PRZ				REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_PIXEL_SRC_PRZ;
	#define SET_IBW2_PIXEL_SRC(pixel_src)		REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW2_CTRL |= pixel_src;
	#define SET_IBW2_OUTPUT_RGB565				REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_OUTPUT_FORMAT_BIT;
	#define SET_IBW2_OUTPUT_RGB888				REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_OUTPUT_FORMAT_BIT;
	#define SET_IBW2_OUTPUT_FORMAT(format)		REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_OUTPUT_FORMAT_BIT;\
															REG_IMGDMA_IBW2_CTRL |= format;
	#define ENABLE_IBW2_PAN							REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_PAN_ENABLE_BIT;
	#define DISABLE_IBW2_PAN						REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_PAN_ENABLE_BIT;
	#define ENABLE_IBW2_DC							REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_DC_ENABLE_BIT;
	#define DISABLE_IBW2_DC							REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_DC_ENABLE_BIT;
	#define ENABLE_IBW2_AUTO_RESTART				REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_AUTO_RESTART_BIT;
	#define DISABLE_IBW2_AUTO_RESTART			REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_AUTO_RESTART_BIT;
	#define ENABLE_IBW2_TRIGGER_LCD				REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_TRIGGER_LCD_BIT;
	#define DISABLE_IBW2_TRIGGER_LCD				REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_TRIGGER_LCD_BIT;
	#define ENABLE_IBW2_DEST_PITCH				REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_DEST_PITCH_BIT;
	#define DISABLE_IBW2_DEST_PITCH				REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_DEST_PITCH_BIT;
	#define ENABLE_IBW2_INT							REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW_INT_BIT;
	#define DISABLE_IBW2_INT						REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW_INT_BIT;

	/* register definition of IBW3 */
	#define IMGDMA_IBW3_START_REG					(IMGDMA_base + 0x0500)
	#define IMGDMA_IBW3_CTRL_REG					(IMGDMA_base + 0x0504)
	#define IMGDMA_IBW3_WIDTH_REG					(IMGDMA_base + 0x0510)
	#define IMGDMA_IBW3_HEIGHT_REG				(IMGDMA_base + 0x0514)

	#define REG_IMGDMA_IBW3_START					*((volatile unsigned int *)(IMGDMA_base + 0x0500))
	#define REG_IMGDMA_IBW3_CTRL					*((volatile unsigned int *)(IMGDMA_base + 0x0504))
	#define REG_IMGDMA_IBW3_WIDTH					*((volatile unsigned int *)(IMGDMA_base + 0x0510))
	#define REG_IMGDMA_IBW3_HEIGHT				*((volatile unsigned int *)(IMGDMA_base + 0x0514))

	/* macros of IBW3,IBW4 start register */
	#define START_IBW3								REG_IMGDMA_IBW3_START=1;
	#define STOP_IBW3									REG_IMGDMA_IBW3_START=0;
	#define START_IBW4								REG_IMGDMA_IBW4_START=1;
	#define STOP_IBW4									REG_IMGDMA_IBW4_START=0;

	/* macros of IBW3 control register */
	#define SET_IBW3_PIXEL_SRC_IPP1				REG_IMGDMA_IBW3_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;
	#define SET_IBW3_PIXEL_SRC_IPP2				REG_IMGDMA_IBW3_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW3_CTRL |= IMGDMA_IBW_PIXEL_SRC_IPP2;
	#define SET_IBW3_PIXEL_SRC_CRZ				REG_IMGDMA_IBW3_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW3_CTRL |= IMGDMA_IBW_PIXEL_SRC_CRZ;
	#define SET_IBW3_PIXEL_SRC_PRZ				REG_IMGDMA_IBW3_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW3_CTRL |= IMGDMA_IBW_PIXEL_SRC_PRZ;
	#define SET_IBW3_PIXEL_SRC(pixel_src)		REG_IMGDMA_IBW3_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW3_CTRL |= pixel_src;
	#define ENABLE_IBW3_AUTO_RESTART				REG_IMGDMA_IBW3_CTRL |= IMGDMA_IBW_AUTO_RESTART_BIT;
	#define DISABLE_IBW3_AUTO_RESTART			REG_IMGDMA_IBW3_CTRL &= ~IMGDMA_IBW_AUTO_RESTART_BIT;
	#define ENABLE_IBW3_INT							REG_IMGDMA_IBW3_CTRL |= IMGDMA_IBW_INT_BIT;
	#define DISABLE_IBW3_INT						REG_IMGDMA_IBW3_CTRL &= ~IMGDMA_IBW_INT_BIT;

	/* register definition of IBW4 */
	#define IMGDMA_IBW4_START_REG						(IMGDMA_base + 0x0580)
	#define IMGDMA_IBW4_CTRL_REG						(IMGDMA_base + 0x0584)
	#define IMGDMA_IBW4_WIDTH_REG						(IMGDMA_base + 0x0590)
	#define IMGDMA_IBW4_HEIGHT_REG					(IMGDMA_base + 0x0594)

	#define REG_IMGDMA_IBW4_START						*((volatile unsigned int *)(IMGDMA_base + 0x0580))
	#define REG_IMGDMA_IBW4_CTRL						*((volatile unsigned int *)(IMGDMA_base + 0x0584))
	#define REG_IMGDMA_IBW4_WIDTH						*((volatile unsigned int *)(IMGDMA_base + 0x0590))
	#define REG_IMGDMA_IBW4_HEIGHT					*((volatile unsigned int *)(IMGDMA_base + 0x0594))

	/* macros of IBW4 control register */
	#define SET_IBW4_PIXEL_SRC_IPP1				REG_IMGDMA_IBW4_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;
	#define SET_IBW4_PIXEL_SRC_IPP2				REG_IMGDMA_IBW4_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW4_CTRL |= IMGDMA_IBW_PIXEL_SRC_IPP2;
	#define SET_IBW4_PIXEL_SRC_CRZ				REG_IMGDMA_IBW4_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW4_CTRL |= IMGDMA_IBW_PIXEL_SRC_CRZ;
	#define SET_IBW4_PIXEL_SRC_PRZ				REG_IMGDMA_IBW4_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW4_CTRL |= IMGDMA_IBW_PIXEL_SRC_PRZ;
	#define SET_IBW4_PIXEL_SRC(pixel_src)		REG_IMGDMA_IBW4_CTRL &= ~IMGDMA_IBW_PIXEL_SRC_MASK;\
															REG_IMGDMA_IBW4_CTRL |= pixel_src;
	#define ENABLE_IBW4_AUTO_RESTART				REG_IMGDMA_IBW4_CTRL |= IMGDMA_IBW_AUTO_RESTART_BIT;
	#define DISABLE_IBW4_AUTO_RESTART			REG_IMGDMA_IBW4_CTRL &= ~IMGDMA_IBW_AUTO_RESTART_BIT;
	#define ENABLE_IBW4_INT							REG_IMGDMA_IBW4_CTRL |= IMGDMA_IBW_INT_BIT;
	#define DISABLE_IBW4_INT						REG_IMGDMA_IBW4_CTRL &= ~IMGDMA_IBW_INT_BIT;

	/* register definition of IBR1 */
	#define IMGDMA_IBR1_START_REG					(IMGDMA_base + 0x0600)
	#define IMGDMA_IBR1_CTRL_REG					(IMGDMA_base + 0x0604)
	#define IMGDMA_IBR1_BASE_ADDR_REG			(IMGDMA_base + 0x0608)
	#define IMGDMA_IBR1_PIXEL_NUMBER_REG		(IMGDMA_base + 0x060C)

	#define REG_IMGDMA_IBR1_START					*((volatile unsigned int *)(IMGDMA_base + 0x0600))
	#define REG_IMGDMA_IBR1_CTRL					*((volatile unsigned int *)(IMGDMA_base + 0x0604))
	#define REG_IMGDMA_IBR1_BASE_ADDR			*((volatile unsigned int *)(IMGDMA_base + 0x0608))
	#define REG_IMGDMA_IBR1_PIXEL_NUMBER		*((volatile unsigned int *)(IMGDMA_base + 0x060C))

	/* bit mapping of IBR1 control register*/
	#define IMGDMA_IBR1_DATA_ORDER_BIT			0x00000004
	#define IMGDMA_IBR1_DATA_FORMAT_BIT			0x00000002
	#define IMGDMA_IBR1_INT_BIT					0x00000001

	#define IMGDMA_IBR1_INTPUT_RGB565			0x00000000
	#define IMGDMA_IBR1_INTPUT_RGB888			0x00000002

	/* macros of IBR1 start register */
	#define START_IBR1								REG_IMGDMA_IBR1_START=1;
	#define STOP_IBR1									REG_IMGDMA_IBR1_START=0;

	/* macros of IBR1 control register */
	#define SET_IMGDMA_IBR1_DATA_ORDER_RGB888	REG_IMGDMA_IBR1_CTRL &= ~IMGDMA_IBR1_DATA_ORDER_BIT;
	#define SET_IMGDMA_IBR1_DATA_ORDER_BGR888	REG_IMGDMA_IBR1_CTRL |= IMGDMA_IBR1_DATA_ORDER_BIT;
	#define SET_IMGDMA_IBR1_DATA_RGB565			REG_IMGDMA_IBR1_CTRL &= ~IMGDMA_IBR1_DATA_FORMAT_BIT;
	#define SET_IMGDMA_IBR1_DATA_RGB888			REG_IMGDMA_IBR1_CTRL |= IMGDMA_IBR1_DATA_FORMAT_BIT;
	#define ENABLE_IMGDMA_IBR1_INT				REG_IMGDMA_IBR1_CTRL |= IMGDMA_IBR1_INT_BIT;
	#define DISABLE_IMGDMA_IBR1_INT				REG_IMGDMA_IBR1_CTRL &= ~IMGDMA_IBR1_INT_BIT;

	/* register definition of IBW2 */
	#define IMGDMA_IBR2_START_REG					(IMGDMA_base + 0x0700)
	#define IMGDMA_IBR2_CTRL_REG					(IMGDMA_base + 0x0704)
	#define IMGDMA_IBR2_BASE_ADDR_REG			(IMGDMA_base + 0x0708)
	#define IMGDMA_IBR2_CONFIG_REG				(IMGDMA_base + 0x070C)
	#define IMGDMA_IBR2_WIDTH_REG					(IMGDMA_base + 0x0710)
	#define IMGDMA_IBR2_HEIGHT_REG				(IMGDMA_base + 0x0714)
	#define IMGDMA_IBR2_COLOR_PALETTE_BASE		(IMGDMA_base + 0x0800)

	#define REG_IMGDMA_IBR2_START					*((volatile unsigned int *)(IMGDMA_base + 0x0700))
	#define REG_IMGDMA_IBR2_CTRL					*((volatile unsigned int *)(IMGDMA_base + 0x0704))
	#define REG_IMGDMA_IBR2_BASE_ADDR			*((volatile unsigned int *)(IMGDMA_base + 0x0708))
	#define REG_IMGDMA_IBR2_CONFIG				*((volatile unsigned int *)(IMGDMA_base + 0x070C))
	#define REG_IMGDMA_IBR2_WIDTH					*((volatile unsigned int *)(IMGDMA_base + 0x0710))
	#define REG_IMGDMA_IBR2_HEIGHT				*((volatile unsigned int *)(IMGDMA_base + 0x0714))

	/* bit mapping of IBR2 control register */
	#define IMGDMA_IBR2_PIXEL_SEL_BIT			0x00000080
	#define IMGDMA_IBR2_PALETTE_ENABLE_BIT		0x00000010
	#define IMGDMA_IBR2_AUTO_RESTART_BIT		0x00000008
	#define IMGDMA_IBR2_PHOTO_FRAME_MODE_MASK	0x00000006
	#define IMGDMA_IBR2_INT_BIT					0x00000001

	#define IMGDMA_IBR2_1BPP_PHOTO_FRAME		0x00000000
	#define IMGDMA_IBR2_2BPP_PHOTO_FRAME		0x00000002
	#define IMGDMA_IBR2_4BPP_PHOTO_FRAME		0x00000004
	#define IMGDMA_IBR2_8BPP_PHOTO_FRAME		0x00000006

	#define OVERLAY_1BPP_PHOTO_FRAME				IMGDMA_IBR2_1BPP_PHOTO_FRAME
	#define OVERLAY_2BPP_PHOTO_FRAME				IMGDMA_IBR2_2BPP_PHOTO_FRAME
	#define OVERLAY_4BPP_PHOTO_FRAME				IMGDMA_IBR2_4BPP_PHOTO_FRAME
	#define OVERLAY_8BPP_PHOTO_FRAME				IMGDMA_IBR2_8BPP_PHOTO_FRAME

	/* bit mapping of IBR2 configuration register */
	#define IMGDMA_IBR2_SRC_KEY_COLOR_MASK		0x0000FF00
	#define IMGDMA_IBR2_V_SCALE_RATIO_MASK		0x000000F0
	#define IMGDMA_IBR2_H_SCALE_RATIO_MASK		0x0000000F

	/* macros of IBR2 start register */
	#define START_IBR2								REG_IMGDMA_IBR2_START=1;
	#define STOP_IBR2									REG_IMGDMA_IBR2_START=0;

	/* macros of IBR2 control register */
	#define SET_IMGDMA_IBR2_SRC_CRZ				REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_PIXEL_SEL_BIT;
	#define SET_IMGDMA_IBR2_SRC_PRZ				REG_IMGDMA_IBR2_CTRL |= IMGDMA_IBR2_PIXEL_SEL_BIT;
	#define ENABLE_IMGDMA_IBR2_PALETTE			REG_IMGDMA_IBR2_CTRL |= IMGDMA_IBR2_PALETTE_ENABLE_BIT;
	#define DISABLE_IMGDMA_IBR2_PALETTE			REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_PALETTE_ENABLE_BIT;
	#define ENABLE_IMGDMA_IBR2_AUTO_RESTART	REG_IMGDMA_IBR2_CTRL |= IMGDMA_IBR2_AUTO_RESTART_BIT;
	#define DISABLE_IMGDMA_IBR2_AUTO_RESTART	REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_AUTO_RESTART_BIT;
	#define SET_IMGDMA_IBR2_PHOTO_FRAME_DEPTH(n)	REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_PHOTO_FRAME_MODE_MASK;\
																REG_IMGDMA_IBR2_CTRL |= n;
	#define ENABLE_IMGDMA_IBR2_INT				REG_IMGDMA_IBR2_CTRL |= IMGDMA_IBR2_INT_BIT;
	#define DISABLE_IMGDMA_IBR2_INT				REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_INT_BIT;

	/* macros of IBR2 config register */
	#define SET_IMGDMA_IBR2_SRC_KEY(color)		REG_IMGDMA_IBR2_CONFIG &= ~IMGDMA_IBR2_SRC_KEY_COLOR_MASK;\
															REG_IMGDMA_IBR2_CONFIG |= (color<<8);
	#define SET_IMGDMA_IBR2_V_RATIO(ratio)		REG_IMGDMA_IBR2_CONFIG &= ~IMGDMA_IBR2_V_SCALE_RATIO_MASK;\
															REG_IMGDMA_IBR2_CONFIG |= (ratio<<4);
	#define SET_IMGDMA_IBR2_H_RATIO(ratio)		REG_IMGDMA_IBR2_CONFIG &= ~IMGDMA_IBR2_H_SCALE_RATIO_MASK;\
															REG_IMGDMA_IBR2_CONFIG |= ratio;

typedef enum
{
	IBR1_TYPE_RGB565,
	IBR1_TYPE_RGB888
}IMGDMA_DATA_TYPE_ENUM;

typedef enum
{
	IBR1_ORDER_BGR888,
	IBR1_ORDER_RGB888
}IMGDMA_DATA_ORDER_ENUM;

#define DATA_ORDER_RGB888		0
#define DATA_ORDER_BGR888		1

void set_overlay_palette(kal_uint8 palette_size,kal_uint32 *palette_addr_ptr);

/*add for 6228/6229*/
typedef void (*IDMA_Callback)(void);

typedef enum{
	IMGDMA_JPEG_CH,
	IMGDMA_VDO_CH,
	IMGDMA_IBW1_CH,
	IMGDMA_IBW2_CH,
	IMGDMA_IBR1_CH,
	IMGDMA_ALL_CH
}IMGDMA_CHANNEL_ENUM;

typedef enum{
	IMGDMA_MPEG4_DECODE,
	IMGDMA_MPEG4_ENCODE
}IMGDMA_DIR_ENUM;


typedef enum{
	IMGDMA_INIT,
	IMGDMA_READY,
	IMGDMA_BUSY
}IMGDMA_STATE_ENUM;

typedef enum{
	IMGDMA_STOP_NOW,
	IMGDMA_STOP_CALLBACK,	// for channel without enable auto_restart
	IMGDMA_STOP_AT_FRAME_BOUNDARY, // for channel eanbled auto_restart
	IMGDMA_STOP_IDLE
}IMGDMA_STOP_ENUM;

typedef enum{
   PIXEL_ENGINE_IPP1,
   PIXEL_ENGINE_IPP2,
   PIXEL_ENGINE_PRZ,   
   PIXEL_ENGINE_CRZ,
   PIXEL_ENGINE_DRZ,
   PIXEL_ENGINE_NONE
}IMGDMA_PIXEL_ENGINE_ENUM;   


/*XXXXX add in 2006/04/24*/
typedef enum
{
	IMGDMA_OUTPUT_TYPE_RGB565,
	IMGDMA_OUTPUT_TYPE_RGB888
}IMGDMA_OUTPUT_TYPE_ENUM;


typedef struct{
	kal_uint32 bs;	// line buffer base address
	kal_uint16 width;	// image width(minus 1 before writing to register)
	kal_uint16 height; // image height
	kal_uint16 fifo;	// fifo length
	kal_bool gray; // 1: for gray mode, 0: for color mode
	IDMA_Callback cb;	// interrupt callback function NULL: disable interrupt
}IMGDMA_JPEG_STRUCT;

typedef struct{
	IMGDMA_DIR_ENUM dir;	// 1: for MEPG4 encode, 0: for MPEG4 decode
	kal_bool	twice;	// 1: enable twice resizing 0: disable
	kal_bool restart; // 1: automatic reastart while current frame is finished
	kal_uint32 bs1;	// first base address
	kal_uint32 bs2;	// second base address
	kal_uint16 width;	// frame width (1 stands for 1)(max 255)
	kal_uint16 height;	// frame height
	void (*cb1)(kal_uint32 yuv_address);	// interrupt callback function NULL: disable interrupt(first run)
	IDMA_Callback cb2;	// interrupt callback function NULL: disable interrupt(second run)
}IMGDMA_VDO_STRUCT;

typedef struct{
	kal_uint32 bs;	      /*buffer base address*/
	kal_uint16 width;    /*image width*/
	kal_uint16 height;   /*image height*/
	IMGDMA_PIXEL_ENGINE_ENUM 	pixel_engine;/*define pixel engine*/
	IMGDMA_OUTPUT_TYPE_ENUM      output_format;/*output format*/
	kal_bool auto_restart; /*auto restart*/	
}IMGDMA_IBW1_STRUCT;

typedef struct{	
	kal_uint16 width;    /*image width*/
	kal_uint16 height;   /*image height*/
	IMGDMA_PIXEL_ENGINE_ENUM 	pixel_engine;/*define pixel engine*/	
	kal_bool auto_restart; /*auto restart*/	
	kal_bool int_en;                   /*interrup enable*/  
}IMGDMA_IBW3_STRUCT;                       
 
typedef struct{	
	kal_uint16 width;    /*image width*/
	kal_uint16 height;   /*image height*/
	IMGDMA_PIXEL_ENGINE_ENUM 	pixel_engine;/*define pixel engine*/	
	kal_bool auto_restart; /*auto restart*/	
	kal_bool int_en;                   /*interrup enable*/  
}IMGDMA_IBW4_STRUCT;                       
 

typedef struct{
	kal_uint32 base_addr;	           /*buffer base address*/	
	kal_uint32 pixel_number;           /*pixel numbers*/
	IMGDMA_DATA_TYPE_ENUM data_type;	  /*RGB565 or RGB888 */	
	IMGDMA_DATA_ORDER_ENUM data_order; /*RGB888 or BGR888 */
	kal_bool int_en;                   /*interrup enable*/  
}IMGDMA_IBR1_STRUCT;

typedef struct{		
	kal_bool restart;                         /* 1: automatic reastart while current frame is finished*/
	kal_bool int_en;                          /*interrup enable*/  
	IMGDMA_PIXEL_ENGINE_ENUM 	pixel_engine; /*define pixel engine*/	
	/*overlay frame configuration*/
	kal_bool 	overlay_frame_mode;				/* KAL_TRUE or KAL_FALSE */
	kal_uint32  overlay_frame_buffer_address;	/* bsae address of the overlay frame buffer */	
	kal_uint16  overlay_frame_width;				/* overlay frame width */
	kal_uint16	overlay_frame_height;			/* overlay frame height */	
	kal_uint16  overlay_frame_target_width;   /* overlay frame target width */
	kal_uint16	overlay_frame_target_height;  /* overlay frame target height */	
	kal_uint8	overlay_color_depth;				/* 1/2/4/8 bpp */
	kal_uint8	overlay_frame_source_key;		/* source key of the overlay frame buffer */				
}IMGDMA_IBR2_STRUCT;

typedef struct{			
	kal_uint32	jpeg_file_buffer_address;		/* the start address of JPEG file located */
   kal_uint16 	target_width;						/* the width of target image */
	kal_uint16 	target_height;						/* the height of target image */
	kal_uint16 	fifo_size;						   /* FIFO size */
	IMGDMA_PIXEL_ENGINE_ENUM 	pixel_engine; /*define pixel engine*/	
	kal_uint8	jpeg_yuv_mode;						/* YUV420, YUV422 or Gray mode*/
	kal_bool    restart;                      /* 1: automatic reastart while current frame is finished*/
   		
}IMGDMA_JPEG_DMA_STRUCT;

typedef struct{					
	kal_uint32  y_base_addr1;                     /*Base addr1 Y */
   kal_uint32  y_base_addr2;                     /*Base addr2 Y */
   kal_uint32  u_base_addr1;                     /*Base addr1 U */
   kal_uint32  u_base_addr2;                     /*Base addr2 U */
   kal_uint32  v_base_addr1;                     /*Base addr1 V */
   kal_uint32  v_base_addr2;                     /*Base addr2 V */
   
   kal_uint16  encode_width;                     /*encode width*/  
   kal_uint16  encode_height;                    /*encode height*/
	
	IMGDMA_PIXEL_ENGINE_ENUM 	wdma_pixel_engine;        /*define WDMA pixel engine*/	
	IMGDMA_PIXEL_ENGINE_ENUM 	rdma_destination_engine;  /*define RDMA destination engine*/	
   kal_bool    restart;                      /* 1: automatic reastart while current frame is finished*/
   kal_bool    wrtie_done_int;                     /*write done interrupt*/
   kal_bool    read_done_int;                      /*read done interrupt*/		   		
   kal_bool    w_trigger_r;                      /* 1: automatic reastart while current frame is finished*/		   		
   
}IMGDMA_VIDEO_ENCODE_STRUCT;

typedef struct{					
	kal_uint32  y_base_addr1;                     /*Base addr1 Y */
   kal_uint32  y_base_addr2;                     /*Base addr2 Y */
   kal_uint32  u_base_addr1;                     /*Base addr1 U */
   kal_uint32  u_base_addr2;                     /*Base addr2 U */
   kal_uint32  v_base_addr1;                     /*Base addr1 V */
   kal_uint32  v_base_addr2;                     /*Base addr2 V */
   
   kal_uint16  width;                            /*decode width*/  
   kal_uint16  height;                           /*decode height*/
		   
   kal_bool    decode_done_int;                  /*decode done interrupt*/
      
}IMGDMA_VIDEO_DECODE_STRUCT;

typedef struct{					
	kal_uint32 frame1_base_addr;
	kal_uint32 frame2_base_addr;
	kal_uint16 width;
	kal_uint16 height;
   kal_uint16 pitch1_bytes; // horizontal pitch 1
	kal_uint16 pitch2_bytes; // horizontal pitch 2	
	kal_uint16 clip_left;
	kal_uint16 clip_right;
	kal_uint16 clip_top;
	kal_uint16 clip_bottom;	
	IDMA_Callback cb;
	kal_uint8  dest_color_mode;   
   IMGDMA_PIXEL_ENGINE_ENUM 	pixel_engine;        /*define pixel engine*/	
   kal_bool   lcd_trigger;
   kal_bool   int_en;
   kal_bool   pan;
   kal_bool   direct_couple;
   kal_bool   restart;
   kal_bool   pitch;      
   kal_bool   enable_IBW2;      
}IMGDMA_IBW2_STRUCT;

/*extern functions*/

void IMGDMA_IBW2Config(IMGDMA_IBW2_STRUCT *ibw2_struct);
void IMGDMA_VIDEODECODE_DMAConfig(IMGDMA_VIDEO_DECODE_STRUCT *video_decode_dma_struct);
void IMGDMA_VIDEOENCODE_DMAConfig(IMGDMA_VIDEO_ENCODE_STRUCT *video_encode_dma_struct);
void IMGDMA_JPEGDMAConfig(IMGDMA_JPEG_DMA_STRUCT *jpeg_dma_struct);
void IMGDMA_IBR2Config(IMGDMA_IBR2_STRUCT *ibr2_struct);
void IMGDMA_IBR1Config(IMGDMA_IBR1_STRUCT *ibr1_struct);
void IMGDMA_IBW4Config(IMGDMA_IBW4_STRUCT *ibw4_struct);
void IMGDMA_IBW3Config(IMGDMA_IBW3_STRUCT *ibw3_struct);
void IMGDMA_IBW1Config(IMGDMA_IBW1_STRUCT *ibw1_struct);
void video_enc_reset_buffer_counter(void);

#endif
#endif // IMGDMA_H

#endif // IMGDMA_H

