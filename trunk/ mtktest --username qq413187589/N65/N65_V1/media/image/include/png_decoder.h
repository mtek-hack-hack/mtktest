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
 *	 png_decoder.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  header file of the png decoder .
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
#ifndef PNG_DECODER_H
#define PNG_DECODER_H

#define PNG_NEW_BUFFER_INTERFACE

#define PNG_MY_INT	26
#define PNG_BASE_ADRS			0x80640000

#define PNG_IN_START				(PNG_BASE_ADRS+0x0)
#define PNG_IN_COUNT				(PNG_BASE_ADRS+0x4)
#define PNG_CT_START				(PNG_BASE_ADRS+0x8)
#define PNG_CT_END				(PNG_BASE_ADRS+0xc)
#define PNG_OUT_START			(PNG_BASE_ADRS+0x10)
#define PNG_OUT_END				(PNG_BASE_ADRS+0x14)
#define PNG_HCLEN_START			(PNG_BASE_ADRS+0x18)
#define PNG_HCLEN_END			(PNG_BASE_ADRS+0x1c)
#define PNG_HLEN_START			(PNG_BASE_ADRS+0x20)
#define PNG_HLEN_END				(PNG_BASE_ADRS+0x24)
#define PNG_HLIT_START			(PNG_BASE_ADRS+0x28)
#define PNG_HLIT_END				(PNG_BASE_ADRS+0x2c)
#define PNG_HDIST_START			(PNG_BASE_ADRS+0x30)
#define PNG_HDIST_END			(PNG_BASE_ADRS+0x34)
#define PNG_BUFF0_START			(PNG_BASE_ADRS+0x38)
#define PNG_BUFF0_END			(PNG_BASE_ADRS+0x3c)
#define PNG_BUFF1_START			(PNG_BASE_ADRS+0x40)
#define PNG_BUFF1_END			(PNG_BASE_ADRS+0x44)
#define PNG_LZ77_START			(PNG_BASE_ADRS+0x48)
#define PNG_LZ77_END				(PNG_BASE_ADRS+0x4c)
#define PNG_COLOR_TYPE			(PNG_BASE_ADRS+0x50)
#define PNG_IMG_WH				(PNG_BASE_ADRS+0x54)
#define PNG_DECODE_EN			(PNG_BASE_ADRS+0x58)
#define PNG_INTERLACE_EN		(PNG_BASE_ADRS+0x5c)
#define PNG_ADLER					(PNG_BASE_ADRS+0x60)
#define PNG_LCD_WH				(PNG_BASE_ADRS+0x68)
#define PNG_CLIP_XY				(PNG_BASE_ADRS+0x6c)
#define PNG_CLIP_WH				(PNG_BASE_ADRS+0x70)
#define PNG_IMG_XY				(PNG_BASE_ADRS+0x74)
#define PNG_RST					(PNG_BASE_ADRS+0x78)
#define PNG_OUT_FROMAT			(PNG_BASE_ADRS+0x7c)
#define PNG_RESIZE_CTRL			(PNG_BASE_ADRS+0x80)
#define PNG_RESUME_REG			(PNG_BASE_ADRS+0x84)
#define PNG_IRQ_EN				(PNG_BASE_ADRS+0x88)
#define PNG_IRQ_STATUS			(PNG_BASE_ADRS+0x8c)
#define PNG_IDAT_COUNT			(PNG_BASE_ADRS+0x90)
#define PNG_CHUNK_TYPE			(PNG_BASE_ADRS+0x94)
#define PNG_CRC_REG				(PNG_BASE_ADRS+0x98)
#define PNG_IDAT_BOUNDARY		(PNG_BASE_ADRS+0x9c)
#define PNG_TRAN_TABLE			(PNG_BASE_ADRS+0xa0)
#define PNG_TRAN_CON				(PNG_BASE_ADRS+0xa4)
#define PNG_TRAN_KEY1			(PNG_BASE_ADRS+0xa8)
#define PNG_TRAN_KEY2			(PNG_BASE_ADRS+0xac)
#define PNG_BACK_GROUND			(PNG_BASE_ADRS+0xb0)
#define PNG_IDAT_BUFFER			(PNG_BASE_ADRS+0xb4)
#define PNG_IDEX_NUM				(PNG_BASE_ADRS+0xb8)

#define PNG_OUT_FORMAT_PATRIAL				0x04	// enable partial input(this one is correct)
#define PNG_OUT_FORMAT_CLIP_EN				0x10	// enable clip and pitch
#define PNG_OUT_FORMAT_IPP_EN					0x20	// output to image processor

#define PNG_IRQ_EN_ALL							0x3f

#define PNG_IRQ_STATUS_IDLE					0x0
#define PNG_IRQ_STATUS_IMG_COMPLETE			0x1
#define PNG_IRQ_STATUS_IN_EMPTY				0x2
#define PNG_IRQ_STATUS_BLOCK_END				0x4
#define PNG_IRQ_STATUS_COLOR_INDEX_ERR		0x8
#define PNG_IRQ_STATUS_FILTER_TYPE_ERR		0x10
#define PNG_IRQ_STATUS_OUT_EMPTY				0x20

#define PNG_IRQ_STATUS_TIMEOUT				0x7f

#define COLOR_TYPE_ALPHA_BIT					0x4

#define PNG_TRAN_CON_TRAN_ENABLE				0x1
#define PNG_TRAN_CON_TRAN_OUT					0x2	// 0: output background color, 1: no output
#define PNG_TRAN_CON_TRAN_TABLE				0x4
#define PNG_TRAN_CON_ARGB						0x8  // transparent trunk of one color key and output by ARGB

// the boundary of the IDAT chunk must >  input buffer boundary+4
// 	or < input buffer boundary -4
#define PNG_PARTIAL_LIMIT 		4		
#define PNG_CRC_LEN				4
//#define PNG_TIMEOUT_PERIOD		200

#define PNG_HAVE_IHDR               0x01
#define PNG_HAVE_PLTE               0x02
#define PNG_HAVE_IDAT               0x04
#define PNG_HAVE_tRNS               0x08
#define PNG_HAVE_bKGD               0x10

// error code
#define PNG_NO_ERR				0
#define PNG_INVALID_IMG			1
#define PNG_ADLER_ERR			2

// macros
#define PNG_DECODE_RUN()		PNG_START_TIMER();\
										DRV_WriteReg(PNG_DECODE_EN, 1)
#define PNG_RESET()				DRV_WriteReg(PNG_RST,0x1201);
										
#define PNG_RESUME()				PNG_START_TIMER();\
										DRV_WriteReg(PNG_RESUME_REG, 1);

#define PNG_GET_INT(ptr)		(*(kal_uint8*)(ptr)<<24|*(kal_uint8*)((ptr)+1)<<16 |\
										*(kal_uint8*)((ptr)+2)<<8|*(kal_uint8*)((ptr)+3))
										
#define PNG_GET_ADLER(ptr)		(kal_uint32)(*(kal_uint8*)(ptr)|*(kal_uint8*)((ptr)+1)<<8 |\
										*(kal_uint8*)((ptr)+2)<<16|*(kal_uint8*)((ptr)+3)<<24)

#define PNG_START_TIMER()		   		\
		png_dcb.is_timeout = KAL_FALSE;\
		GPTI_StartItem(png_gpt_handle,\
                  png_dcb.timeout_period,\
                  png_timeout_hander,\
                  NULL)

#define PNG_STOP_TIMER()			\
		GPTI_StopItem(png_gpt_handle);\

#define PNG_ERR_READ_FILE		121
#define PNG_ERR_READ_MEM		122

typedef enum{	
   PNG_FINISH_IMAGE		=	0,
   PNG_INPUT_EMPTY		=	1,
   PNG_DECODING			=  2,
   PNG_BLOCK_END			=	3,
   PNG_USE_G2D				= 	4,
   PNG_DECODE_TIMEOUT	=	-1,
   PNG_FORMAT_ERROR		=	-2,
   PNG_MEM_INSUFFICEITN 	= 	-4,
   
   PNG_SW_DECODE_ERR			= -40,
   PNG_SW_TOO_LARGE			= -41
}png_report_status_enum;

typedef enum{
	PNG_STATE_IDLE,
	PNG_STATE_READY,
	PNG_STATE_BUSY,
	PNG_STATE_PAUSE_BLKEND,
	PNG_STATE_PAUSE_INEMPTY,
	PNG_STATE_HANDLE_PATRIAL,
	PNG_STATE_ERR
}png_state_enum;

typedef enum{
	COLOR_TYPE_GRAY = 0,
	COLOR_TYPE_RGB = 2,
	COLOR_TYPE_INDEX = 3,
	COLOR_TYPE_GRAY_A = 4,
	COLOR_TYPE_RGB_A = 6
}png_color_type_enum;

typedef enum{
	RGB565,
	RGB888,
	ARGB4444,
	ARGB8888
}png_out_format_enum;

typedef enum{
	PNG_RESTORE_BG = 0,
	PNG_NOT_OUTPUT = 2
}png_tran_out_enum;

typedef enum{
	PNG_DECODE_MEMORY, 	// the total image file is in the memory
	PNG_DECODE_FILE		// the caller provide a file handler
}png_decode_mode_enum;


typedef union{
	kal_uint8 index;
	kal_uint16 gray;
	struct {
		kal_uint16 r;
		kal_uint16 g;
		kal_uint16 b;
	}color;	
}bKGD_type_union;


typedef union{
	kal_uint8 index;	
	kal_uint16 gray;
	struct {
		kal_uint16 r;
		kal_uint16 g;
		kal_uint16 b;
	}color;	
}tRNS_type_union;

typedef void (*png_cb_fp)(png_report_status_enum status );
#define CT_LEN			256
#define HCLEN_LEN		0x400
#define HLEN_LEN		0x400
#define HLIT_LEN		0x400
#define HDIST_LEN		0x400
#define BUFF0_LEN		0x2000
#define BUFF1_LEN		0x2000
#define LZ77_LEN		1024*32+4
/*
#define PNG_HW_BUFFER	(CT_LEN*2 + HCLEN_LEN +HLEN_LEN + HLIT_LEN + HDIST_LEN + \
									BUFF0_LEN +  BUFF1_LEN + LZ77_LEN)
*/
#define PNG_HW_BUFFER  1024*100

typedef struct {
	kal_uint32* hclen;
	kal_uint32* hlen;
	kal_uint32* hlit;
	kal_uint32* hdist;
	kal_uint32* buff0;
	kal_uint32* buff1;
	kal_uint32* LZ77;
	kal_uint32* color_table;
	kal_uint32*  color_table_t;	// transparent pallete 
}png_internal_buffer_struct;

typedef struct {
	FS_HANDLE file_handle;	// file handler of png image
	kal_uint32 in_buffer_adrs; // file buffer to contain the png image
	kal_uint32 in_buffer_size; // for PNG_DECODE_MEMORY, it should be the file size.
	kal_uint32 output_buffer_adrs;// destination buffer address
	kal_uint32 output_buffer_size;
	
	// work_buffer_info
	kal_uint32 work_buffer_adrs; // working buffer address
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
	
	
	// working buffers (must be 4 bytes aligned)
	#ifndef PNG_NEW_BUFFER_INTERFACE
	kal_uint32* hclen;	// huffman code lengh (16k)
	kal_uint32* hlen;	// huffman length (16k)
	kal_uint32* hlit;	// huffman litteral (16k)
	kal_uint32* hdist;	// huffman distance (16k)
	kal_uint32* buff0;	// line buffer 0 (16k)
	kal_uint32* buff1;	// line buffer 1 (16k)
	kal_uint32* LZ77;	// LZ77 sliding window (32k+4)
	kal_uint32* color_table;	// color table (256x4)
	kal_uint32* color_table_t;	// transparent pallete (256)
	#else
	kal_uint32* color_table;	// color table (256x4)
	kal_uint32* color_table_t;	// transparent pallete (256)	
	kal_uint32* upper_buffer;		// a total buffer pool
	#endif
	
	png_cb_fp cb;	// callback function

	// clipping function
	kal_uint16 shadow_w;	// destination window width
	kal_uint16 shadow_h;	// destination window height
	kal_int16 clip_x1, clip_y1, clip_x2, clip_y2; // clip window 
	kal_int16 dest_x, dest_y; // destination at window
	
	// resize function
	kal_uint16 expect_w;	// expected width used to caculate the resizing ratio
	kal_uint16 expect_h;	// expected heigh
		
	// kal_bool resize_en;	// enable resizing function
	kal_bool clip_en;	// enable clipping function
	png_out_format_enum out_format; // output format contol
	png_decode_mode_enum decode_mode;
	kal_uint32 src_key;	// MMI's source key color
	kal_uint32 png_timeout_period;
}png_config_struct;

typedef struct{
	kal_uint32 t_color;	// output, transparent color(palette and non-palette)
	kal_uint32 bg_color; // background color in RGB888
	kal_uint32 src_key;	// source key for 2D engine to perform transparent bitblt	
	kal_uint16 img_w;		// image width
	kal_uint16 img_h;		// image height
	kal_uint16 num_trans; // for pallete type 	
	kal_uint8 num_plte;	 // number of the palette entries (0 based)
	kal_bool interlaced;	// is image interlaced
	png_color_type_enum color_type;// the color type of the image
	kal_uint8 bit_depth;	// the bit depth of the image
	tRNS_type_union trans;	// transparent chunk
	bKGD_type_union bKGD;	// backgound color chunk	
	kal_uint16 resz_w;		// image width after resize
	kal_uint16 resz_h;		// image height after resize
	kal_bool use_work_buf;	// use working buffer instead of output buffer 	
	
	kal_int16   wb_clip_x1, wb_clip_y1, wb_clip_x2, wb_clip_y2; // clip window 
	kal_int16   wb_dest_x, wb_dest_y; // destination at window
	kal_uint16  wb_width,wb_height;
}png_inform_struct;


// png hw decoder
typedef struct{
	png_config_struct* cfg;
	volatile kal_bool is_timeout;
	kal_uint16 timeout_period;

#if defined(USE_HW_PNG_DECODER_V1)
	png_inform_struct info;
	
	kal_uint32 z_count;		// curreent unused IDAT count	
	kal_uint32 IDAT_num;		// current number of IDAT chunk
	//kal_uint32 adler;			// adler of the PNG decoded data
	kal_uint32 file_size;	// record the size of the file
	kal_uint32 crc;			// crc of a chunk
	kal_uint32 flags;			// indicate the current status
	volatile kal_uint32 status;	// record interrupt status
	png_cb_fp cb;	// callback function
	kal_uint32 my_idat_count;
	kal_uint32 my_idat_remain;
	
	kal_bool partial_en;
	kal_bool resz_en;
	kal_bool is_IEND;
	kal_uint8 resz_w;		// 1/ 2^(resz_w) 0~15
	kal_uint8 resz_h;		// 1/ 2^(resz_h) 0~15	
	// use 2d to work around
	// kal_bool use_2d_engine;
#elif defined(USE_SW_PNG_DECODER)
	kal_uint32 file_index;
	kal_int32 result;
#endif	
}png_dcb_struct;


#if defined(USE_HW_PNG_DECODER_V1)
#define png_init_hw 				png_init
#define png_decode_start_hw 	png_decode_start
#define png_decode_resume_hw	png_decode_resume
#define png_decode_stop_hw		png_decode_stop
#elif (defined(USE_SW_PNG_DECODER) || ((defined(USE_HW_PNG_DECODER_V1))&&(!__MTK_TARGET__)))
#define png_init_sw 				png_init
#define png_decode_start_sw 	png_decode_start
#define png_decode_resume_sw	png_decode_resume
#define png_decode_stop_sw		png_decode_stop
#endif

extern void png_init(void);
extern png_report_status_enum png_decode_start(png_config_struct *cfg, png_inform_struct *info);
extern png_report_status_enum png_decode_resume(void);
extern void png_decode_stop(void);
extern void sw_png_hook_png_decode_progress_callback(kal_int32 (*png_decode_progress_callback)(void));
extern void sw_png_hook_img_update_callback(void (*image_update_callback)(kal_int32 x1,kal_int32 y1,kal_int32 x2,kal_int32 y2));

#endif // PNG_DECODER_H
