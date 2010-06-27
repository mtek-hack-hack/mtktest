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
 *	 gif_decoder_v2.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  header file of the gif decoder V2.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef GIF_DECODER_H
#define GIF_DECODER_H

#define GIF_DECODER_BASE		GIFDEC_base

// MT6228 driver development
#define GIF_INFILE_START_ADDR 		(GIF_DECODER_BASE+0x0)
#define GIF_INFILE_COUNT		 		(GIF_DECODER_BASE+0x4)	// input byte cout
#define GIF_CT_START_ADDR 				(GIF_DECODER_BASE+0x8)
#define GIF_CT_END_ADDR			 		(GIF_DECODER_BASE+0xc)
#define GIF_TREE_START_ADDR	 		(GIF_DECODER_BASE+0x10)
#define GIF_TREE_END_ADDR 				(GIF_DECODER_BASE+0x14)
#define GIF_STK_START_ADDR 			(GIF_DECODER_BASE+0x18)
#define GIF_STK_END_ADDR 				(GIF_DECODER_BASE+0x1c)
#define GIF_OUTFILE_START_ADDR 		(GIF_DECODER_BASE+0x20)
#define GIF_OUTFILE_END_ADDR	 		(GIF_DECODER_BASE+0x24)
#define GIF_DEC_EN						(GIF_DECODER_BASE+0x28)
#define GIF_FILE_BOUNDARY		 		(GIF_DECODER_BASE+0x2c)
#define GIF_MIN_CODE_SIZE		 		(GIF_DECODER_BASE+0x30)
#define GIF_INTERLACE_CTRL		 		(GIF_DECODER_BASE+0x34)
#define GIF_IMG_WIDTH_HEIGHT 			(GIF_DECODER_BASE+0x38)
#define GIF_RESZ_CTRL					(GIF_DECODER_BASE+0x3c)
#define GIF_TRANS_CTRL			 		(GIF_DECODER_BASE+0x40)
#define GIF_BG_COLOR				 		(GIF_DECODER_BASE+0x44)
#define GIF_LCD_WH						(GIF_DECODER_BASE+0x4c)
#define GIF_CLIP_XY						(GIF_DECODER_BASE+0x50)
#define GIF_CLIP_WH						(GIF_DECODER_BASE+0x54)
#define GIF_IMG_XY						(GIF_DECODER_BASE+0x58)
#define GIF_IMG_OFFSET_XY				(GIF_DECODER_BASE+0x5c)
#define GIF_IRQ_EN				 		(GIF_DECODER_BASE+0x60)
#define GIF_IRQ_STATUS			 		(GIF_DECODER_BASE+0x64)
#define GIF_RST					 		(GIF_DECODER_BASE+0x68)
#define GIF_OUT_FORMAT			 		(GIF_DECODER_BASE+0x6c)
#define GIF_DEC_RESUME					(GIF_DECODER_BASE+0x70)
#define GIF_PACK_RESZ_W					(GIF_DECODER_BASE+0x74)
#define GIF_PACK_RESZ_H					(GIF_DECODER_BASE+0x78)

#define GIF_OUT_FORMAT_TYPE			0x0003
#define GIF_OUT_FORMAT_PARTIAL_EN	0x0008
#define GIF_OUT_FORMAT_CLIP_EN		0x0020
#define GIF_OUT_FORMAT_PACK_EN		0x0100
#define GIF_OUT_FORMAT_PACK_DEPTH	0x01e0

#define GIF_TRANS_CTRL_EN				0x0001
#define GIF_TRANS_CTRL_TYPE			0x0002	// 0: restore background, 1: not output
#define GIF_TRANS_CTRL_INDEX			0x03fc

#define GIF_BG_COLOR_INDEX				0xFF000000

// definitions
#define GIF_RESET_KEY				(0x1201)
#define GIF_STACK_SIZE				(0x1000+4)
#define GIF_TREE_SIZE				(0x4000+4)
#define GIF_GCT_SIZE					(0x400)	// 256x4
#define GIF_LCT_SIZE					(0x400)	// 256x4

// pack field of GCE (Graphic Control Extension)
#define GIF_GCE_PACK_TC_FLAG		0x01	// transparent flag
#define GIF_GCE_PACK_UI_FLAG		0x02	// user input flag
#define GIF_GCE_PACK_DP				0x1c	// disposal methed
// pack field of LSD (Logical Screen Descriptor)
#define GIF_LSD_PACK_GCT_SIZE		0x07
#define GIF_LSD_PACK_SORT_FLAG	0x08
#define GIF_LSD_PACK_COLOR_RES	0x70
#define GIF_LSD_PACK_GCT_FLAG		0x80
// pack field of IMD (Image Descriptor)
#define GIF_IMD_PACK_LCT_SIZE		0x07
#define GIF_IMD_PACK_SORT_FLAG	0x20
#define GIF_IMD_PACK_INTERLACE	0x40
#define GIF_IMD_PACK_LCT_FLAG		0x80

#define GIF_EXT_LABEL				0x21	// extension
#define GIF_GCE_LABEL				0xf9	// GCE label
#define GIF_IMD_LABEL				0x2c	// IMD label
#define GIF_TRAILER_LABEL			0x3b	// tailer label

#define GIF_MIN_FILE_BUF_SIZE		1024
#define GIF_REFILL_THRESH		4

#define GIF_IRQ_EN_ALL				0x3f
#define GIF_IRQ_EN_OFF				0

// macros
#define GIF_START_TIMER()		   		\
		gif_dcb.is_timeout = KAL_FALSE;\
		GPTI_StartItem(gif_gpt_handle,\
                  gif_dcb.timeout_period,\
                  gif_timeout_hander,\
                  NULL)

#define GIF_STOP_TIMER()			\
		GPTI_StopItem(gif_gpt_handle);\

#define GIF_START()		gif_dcb.int_status = 0;\
								DRV_WriteReg(GIF_DEC_EN, 1)

#define GIF_RESET()		DRV_WriteReg(GIF_RST, GIF_RESET_KEY);
#define GIF_RESUME()		gif_dcb.int_status = 0;\
								DRV_WriteReg(GIF_DEC_RESUME, 1)
#define GIF_SET_WIDTH_HEIGHT(w,h)	DRV_WriteReg32(GIF_IMG_WIDTH_HEIGHT,(((w)<<16)|(h)));

#define INTERNAL_FUNC			static
#define GIF_CACHE_NUM				8		// must be power of 2
#define GIF_CACHE_INIT_COUTNER	(GIF_CACHE_NUM-1)
#define GIF_CACHE_FRAME_NUM		16	// 32
#define GIF_CACHE_GET_INDEX(a)		((a)&(GIF_CACHE_NUM-1))
#define GIF_TIMEOUT_PERIOD			200	// x10ms

typedef enum{	
	GIF_STATE_IDLE,	
	GIF_STATE_READY,	
	GIF_STATE_PAUSE,
	GIF_STATE_BUSY,
	GIF_STATE_ERR
}gif_state_enum;

// specify in the GCE 
typedef enum{
	GIF_NO_ACTION,
	GIF_NOT_DISPOSAL,
	GIF_RESTORE_BG,
	GIF_RESTORE_PRE		// not support
}gif_disposal_enum;

typedef enum{
	GIF_OUT_RGB565 = 0,
	GIF_OUT_RGB888 = 1,
	GIF_OUT_INDEX = 2
}gif_out_format_enum;

typedef enum{
   GIF_STATUS_COMPLETE =			0x1,	// decode a frame completely
   GIF_STATUS_INEMPTY =				0x2,	// input buffer is empty before end of frame
   GIF_STATUS_OUTFULL =				0x4,	// ouptut buffer is empty before end of frame
   GIF_STATUS_PIXELERR =			0x8,	// the output decoded pixels is not the same as the frame size	
   GIF_STATUS_STKFULL =				0x10,	// stack buffer is not enough
   GIF_STATUS_TREEFULL =			0x20,	// tree buffer is not enough 
   GIF_STATUS_TREEERR =				0x40,	// decode with a invalid tree node
   GIF_STATUS_TIMEOUT = 			0x8000	// timeout (GPT)
}gif_status_enum;

typedef enum{
	GIF_DECODING			= 	5,
   GIF_FINISH_FRAME		=	0,
   GIF_NO_FRAME			=	3,
   GIF_INVALID_FORMAT	=	-2
}gif_report_status_enum;

typedef enum{
	GIF_DECODE_MEMORY, 	// the total image file is in the memory
	GIF_DECODE_FILE		// the caller provide a file handler
}gif_decode_mode_enum;

typedef void (*gif_cb_fp)(gif_status_enum status, kal_uint32 fn);

typedef struct {
	// the same for every frame
	kal_uint16 	lwidth;		// logical screen width
	kal_uint16 	lheight;		// logical screen height
	kal_bool		GCT_flag;	// is GCT(Global Color Table present
	kal_uint8	GCT_size;	// GCT size			
   kal_uint8	bg_index;	// background color index	

	// image descriptor for every frame (image descriptor)
   kal_uint16 x, y; 			// left and top position
   kal_uint16 w, h;	 		// local width and height of the image
   kal_bool LCT_flag;		// local color table exists
   kal_uint8 LCT_size;		// size of LCT
   kal_bool interlaced;		// is interlaced image?
	kal_uint8 bpp;				// bit per pixel	
	
	// Graphic Control Extension(reset for every frame)	
   kal_bool transparent_flag;        // is transparent 	
   kal_uint8 transparent_index;	
   gif_disposal_enum disposal;		// disposal method 
   kal_uint8 userInput;		// is user input ?	
	kal_uint16 delay_time;			// delay time of current frame
	kal_uint8 min_code;		// minimum code size
	kal_uint32 lzw_start;	// start address of the lzw code word
   kal_uint16 resz_w, resz_h;	 		// local width and height of the image	
	kal_uint32 src_key_2d;		// for 2D engine to perfrom the transparent
	
	kal_bool use_work_buf;		// decode output to the working buffer instead of output buffer
	kal_int16   wb_clip_x1, wb_clip_y1, wb_clip_x2, wb_clip_y2; // clip window 
	kal_int16   wb_dest_x, wb_dest_y; // destination at window
	kal_uint16  wb_width,wb_height;
	
}gif_info_struct;

typedef struct {
	kal_uint32 cache_id;		// specify a cache ID	
	FS_HANDLE file_handle;	// file handler of gif image
	kal_uint8* file_buffer_adrs; // file buffer to contain the gif image (at least 1k)
	kal_uint32 file_buffer_size;
	kal_uint8* output_buffer_adrs;// destination buffer address
	kal_uint32 output_buffer_size;
	kal_uint8* work_buffer_adrs;// destination buffer address
	kal_uint32 work_buffer_size;
	void (*cal_work_buffer_info_func)(
		kal_uint8 *ret_ratio,
		kal_int16 *wb_dest_x,kal_int16 *wb_dest_y,
		kal_uint16 *wb_width,kal_uint16 *wb_height,
		kal_uint32 wb_pixel_size,
		kal_uint16 img_w,kal_uint16 img_h,
		kal_int16 dest_x,kal_int16 dest_y,
		kal_uint16 expect_w,kal_uint16 expect_h,
		kal_int16 clipx1,kal_int16 clipy1,kal_int16 clipx2,kal_int16 clipy2);
	
	
	kal_uint32* stack_adrs; // working buffer 
	kal_uint32* tree_adrs; // working buffer 
	kal_uint32* GCT_adrs; // (only for index output and pack mode)
	kal_uint32* LCT_adrs; // must provide
	kal_uint32 stack_size;	// (0x1000+4)
	kal_uint32 tree_size;	//  (0x4000+4

	gif_cb_fp gif_cb;	// call back function while gif decoder generate a interrupt
	kal_uint16 shadow_w;	// destination window width
	kal_uint16 shadow_h;	// destination window height
	kal_int16 clip_x1, clip_y1, clip_x2, clip_y2; // clip window 
	kal_int16 dest_x, dest_y; // destination at window
	
	// resize function
	kal_uint16 expect_w;	
	kal_uint16 expect_h;
	
	// pack mode resizing parameters Q+N/D, for example, Q=1, N=3, D= 7, it means reszied to 7/10 
	// if no resizing (Q,N,D) have to be set as (0,1,0)
	kal_uint16 p_resz_w_Q;
	kal_uint16 p_resz_w_N;
	kal_uint16 p_resz_w_D;
	kal_uint16 p_resz_h_Q;
	kal_uint16 p_resz_h_N;
	kal_uint16 p_resz_h_D;

	kal_uint8 frame_number; // specify the frmae nubmer of gif file(input), 0 based
	kal_uint8 pack_enable;	// enable pack mode
	kal_bool clip_enable;	// enable clipping	
	gif_out_format_enum out_format; // specify the output format
	gif_decode_mode_enum decode_mode;	// specify the decode mode (memory or file)
	kal_bool transparent_enable; //it will overwrite the TC flag of the GCE 
	kal_bool disposal_en; // enable disposal handling
   kal_uint32  src_key;		// MMI's transparent color.	   
   kal_uint32  bg_color;    // MMI will pass bg_color to force using this color as background color. color format depeonds on destination format
}gif_config_struct;

typedef struct{
	gif_disposal_enum	disposal;
	/* This field is used for disposal_method == restore background */
	kal_int16		left_position;
	kal_int16		right_position;
	kal_uint16		width;
	kal_uint16		height;
}gif_disposal_method;

typedef struct{
	kal_uint16 fn;
	kal_uint32 offset;
	gif_disposal_method last_disposal;
}gif_largest_frame_offset;

typedef struct{
   kal_uint16 delay_time;  	     // delay time of current frame
   kal_bool transparent_flag;        // is transparent 	
   kal_uint8 transparent_index;	
   gif_disposal_method	last_disposal;
}gif_gce_struct;

typedef struct{
	kal_uint32 	GCT[256];		// global color table (must be 4 byte aligned)
	kal_uint32 	frame_offset[GIF_CACHE_FRAME_NUM]; // frame offset 
	gif_disposal_method	last_disposal[GIF_CACHE_FRAME_NUM]; // Keep the last disposal method of last frame
	kal_uint32	file_size;		// file size
	kal_uint32 	id;				// cache id
	kal_uint16 	lwidth;			// logical screen width
	kal_uint16 	lheight;			// logical screen height
	kal_bool		GCT_flag;		// is GCT(Global Color Table present
	kal_uint8	bpp;				// bit per pixel
	kal_uint8	GCT_size;		// GCT size			
   kal_uint8	bg_index;		// background color index	
	kal_uint16 	valid_fn;		// already cached frame number (only index to frame_offset)
	kal_uint16  total_fn;		// total frame number
	kal_int16   dest_x;
	kal_int16   dest_y;
	gif_largest_frame_offset	latest_fn[2]; 	// used to cache one latest frame beyond GIF_CACHE_FRAME_NUM
	gif_gce_struct		frame_0_gce;		//the disposal of last frame must apply on frame0;
}gif_cache_struct;

typedef struct{
   kal_bool  cache_hit;
	kal_uint8 timeout_period;				// time out period of gpt timer
	volatile kal_bool is_timeout;			// flag to indicate whther the gpt is expired	
	kal_bool partial_enable;				// partial input is enabled
	kal_bool trailer;							// indicate is tralier is reached	
	kal_bool resz_enable;	// is resizing is enable
	kal_uint8 resz_w;				// 1/ 2^(resz_w) 0~15
	kal_uint8 resz_h;				// 1/ 2^(resz_h) 0~15
	
	volatile kal_uint16 int_status;
	kal_uint16 cur_fn;						// specify current frame number
	
	gif_info_struct info;
	kal_uint32 file_size;					// record the size of the gif file
	gif_cb_fp gif_cb;	// call back function while gif decoder generate a interrupt
	kal_uint32 lzw_start;
	gif_config_struct *cfg;
	
}gif_dcb_struct;


// interfaces
void gif_init(void);
gif_report_status_enum gif_decode_start(gif_config_struct *cfg, gif_info_struct *info);
gif_report_status_enum gif_decode_resume(gif_config_struct *cfg, gif_info_struct *info);
void gif_decode_stop(void);
kal_bool gif_get_cache(gif_config_struct *cfg, gif_cache_struct** ptr,kal_bool update);

#endif //GIF_DECODER_H
