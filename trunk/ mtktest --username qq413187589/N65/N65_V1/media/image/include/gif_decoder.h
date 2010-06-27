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
 *   gif_decoder.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for GIF decoder 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef GIF_DECODER_H
#define GIF_DECODER_H

// base address
#define GIF_DECODER_BASE		GIF_base

// register address
#define GIF_GCT_BASE_ADDR			GIF_DECODER_BASE+0x4
#define GIF_LCT_BASE_ADDR			GIF_DECODER_BASE+0x8
#define GIF_STACK_BASE_ADDR		GIF_DECODER_BASE+0xc
#define GIF_GCE_REG					GIF_DECODER_BASE+0x10	// input by sw.
#define GIF_TREE_BASE_ADDR		   GIF_DECODER_BASE+0x14
#define GIF_DEC_CTL_ADDR			GIF_DECODER_BASE+0x18
#define GIF_STATUS_REG				GIF_DECODER_BASE+0x1c
#define GIF_START_REG				GIF_DECODER_BASE+0x20
#define GIF_INT_CTL_REG				GIF_DECODER_BASE+0x24
#define GIF_ORGB_BASE_ADDR		   GIF_DECODER_BASE+0x30
#define GIF_RESET_REG				GIF_DECODER_BASE+0x34
#define GIF_MIN_BUF_RANGE			GIF_DECODER_BASE+0x38	// not used
#define GIF_MAX_BUF_RANGE			GIF_DECODER_BASE+0x3c	// not used
#define GIF_INFILE_START			GIF_DECODER_BASE+0x40
#define GIF_INFILE_END				GIF_DECODER_BASE+0x44
#define GIF_IMG_REG_1				GIF_DECODER_BASE+0x48	// not used
#define GIF_IMG_REG_2				GIF_DECODER_BASE+0x4c	// not used
#define GIF_IMG_REG_3				GIF_DECODER_BASE+0x50	// not used
#define GIF_LSD_REG_1				GIF_DECODER_BASE+0x54
#define GIF_LSD_REG_2				GIF_DECODER_BASE+0x58

// bit positions
#define GIF_GCE_TC_FLG				0x1		// transparency control flag
#define GIF_GCE_TC_INDEX			0x1E		// transparency color index

#define GIF_DEC_CTL_RS				0x1		// restricted size(0:small,1:large)
#define GIF_DEC_CTL_OUT				0x2		// ouput path(1:resizer, 0:memory)

#define GIF_STATUS_FINISH_FILE	0x1
#define GIF_STATUS_FINISH_FRMAE	0x2		// decoding complete 
#define GIF_STATUS_TEXT				0x4		// Text extension block is present
#define GIF_STATUS_GCE				0x8		// Graphic control extension is present
#define GIF_STATUS_END				0x10		// Gif decoder reach the end of the file

#define GIF_IMG_REG3_LCT_SIZE				0x7	// local color table size
#define GIF_IMG_REG3_LCT_INTERLACE		0x40	// is interlaced
#define GIF_IMG_REG3_LCT_FLG				0x80	// is LCT present

#define GIF_LSD2_PXL_RATIO			0xFF			// pixel aspect ratio
#define GIF_LSD2_BG					0xFF00		// background color
#define GIF_LSD2_GCT_SIZE			0x70000		// GCT size
#define GIF_LSD2_GCT_SORT			0x80000		// is GCT sorted
#define GIF_LSD2_BPP					0x700000		// bits per pixel
#define GIF_LSD2_GCT_FLG			0x800000		// is GCT present

#define GIF_GCE_DISPOSAL			0x1c

// constants 
#define GIF_RESET_KEY				0x1201
#define GIF_STACK_SIZE				(0x1000+4)
#define GIF_TREE_SIZE				(0x4000+4)
#define GIF_GCT_SIZE					(0x200)
#define GIF_LCT_SIZE					(0x200)
#define GIF_GUARD_PATTERN			0x12345678
//#define GIF_TIMEOUT_PERIOD			200	// x 10ms
#define GIF_SOFTKEY					0xFFFF

// return values
#define GIF_FINISH_FRAME		0
#define GIF_LAST_FRAME			1
#define GIF_OUT_OF_RANGE		2
#define GIF_NO_FRAME				3

#define GIF_DECODE_TIMEOUT		-1
#define GIF_TRUNCATED_FILE		-2
#define GIF_FORMAT_ERROR		-3
#define GIF_MEM_INSUFFICEITN  -4
#define GIF_HW_DECODE_FAIL		-5

// macro
#define GIF_START()		DRV_WriteReg(GIF_START_REG, 1);
#define GIF_RESET()		DRV_WriteReg32(GIF_RESET_REG, GIF_RESET_KEY)

typedef enum{
	GIF_MEMORY = 0,
	GIF_RESIZER = 1
}gif_out_location_enum;

typedef enum{
	GIF_STATE_READY,	
	GIF_STATE_BUSY			
}gif_state_enum;

typedef enum{
	GIF_NO_ACTION,
	GIF_NOT_DISPOSAL,
	GIF_RESTORE_BG,
	GIF_RESTORE_PRE,

	GIF_MTK_NO_ACTION   // don't force the disposal method
}gif_disposal_enum;

// structures
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
typedef struct {
	kal_uint32 stack_size;
	kal_uint32 tree_size;
	kal_uint32 GCT_size;
	kal_uint32 LCT_size;
	
	kal_uint8 *stack;
	kal_uint8 *tree;
	kal_uint8 *GCT;
	kal_uint8 *LCT;
}gif_resource_struct;
#endif
typedef struct {

	// image info
	kal_uint16 	width;		// image width
	kal_uint16 	height;		// image height
	kal_uint16	x;				// image top 
	kal_uint16	y;				// image left
	kal_uint16 	lwidth;		// logical screen width
	kal_uint16 	lheight;		// logical screen height

	kal_uint8	LCT_flag;	// is LCT(Local Color Table) present
	kal_uint8 	LCT_size;	// LCT size 
	kal_uint8	interlace;	// is interlaced
	kal_uint8	bg;			// background color(index)
	kal_uint8	bpp;			// bits per pixel
	kal_uint8	GCT_flag;	// is GCT(Global Color Table present
	kal_uint8	GCT_size;	// GCT size		

	kal_uint8 transparent_index;
	kal_uint8 transparent_flag;

	kal_uint8  	delay_time;
	kal_uint16 	bg_color;		// backgroud color in RGB565
}gif_info_struct;

typedef struct{
	kal_uint8 *img_adrs;
	kal_uint32 img_size;
	kal_uint16 frame_number; // specify the frmae nubmer of gif file(input), 0 based
	gif_disposal_enum disposal_force; 	// force the disposal method instead of specified in gif file.	
	kal_bool reset; // force the gif decoder to decode from the 1st frame 

	kal_uint32 shadow_adrs;
	kal_uint16 shadow_width,shadow_height;
	kal_int16 clip_x1, clip_y1, clip_x2, clip_y2;
	kal_int16 dest_x, dest_y;
	kal_uint32 work_adrs,work_size;	
	kal_bool  decode_test;
}gif_para_struct;

typedef struct{
	gif_out_location_enum out_location;	// specify output to memory or resizer
	kal_uint8 gpt_handle;					// handler of gpt timer 
	kal_uint8 timeout_period;				// time out period of gpt timer
	volatile kal_bool is_timeout;						// flag to indicate whther the gpt is expired	
	gif_state_enum state;	
	kal_bool trailer;							// indicate is tralier is reached	
	kal_uint16 frame_counter;				// specify the frame number of gif file (out)
	gif_info_struct gif_info;	
	kal_uint8 *img_adrs,*img_end,*current_adrs;				// specify the current frame address 	
}gif_dcb_struct;

extern void GIF_Reset(void);
extern kal_int32 GIF_DecodeFirst(kal_uint8* src, void* dest, kal_uint32 size);
extern kal_int32  GIF_DecodeNext(void* dest);
extern void GIF_DecodeEnd(void);
extern kal_int32 GIF_Display_HW(gif_para_struct *s, gif_info_struct *info);

#endif // GIF_DECODER_H


