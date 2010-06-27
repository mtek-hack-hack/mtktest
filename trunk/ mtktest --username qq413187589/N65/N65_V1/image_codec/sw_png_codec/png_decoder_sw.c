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
 *	 png_decoder_sw.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Software png decoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "gpt_sw.h"
#include "visual_comm.h"
#include "drm_gprot.h"
#include "fat_fs.h"
#include "png_decoder.h"
#include "kal_adm.h"
#include "png.h"
#include "setjmp.h"
#include "img_resizer.h"

#define PNG_HEAP_SIZE 90*1024  // bytes

#if defined(USE_SW_PNG_DECODER)

#ifdef PNG_NEW_BUFFER_INTERFACE
static kal_uint8 *png_heap;
static kal_uint8 **row_img_ptr;
#else
static kal_uint8 png_heap[PNG_HEAP_SIZE];
static kal_uint8 *row_img_ptr[IMG_MAX_HEIGHT];
#endif

KAL_ADM_ID png_dm_id;
static png_structp png_ptr;
static png_infop info_ptr;
static png_dcb_struct png_dcb;
kal_bool is_PNG_cliped;
static kal_uint8 png_gpt_handle;

#define PNG_SW_RAISE(x)		longjmp(png_ptr->jmpbuf, x)

typedef struct{
	kal_uint32 adrs;
	kal_uint32 len;
}m_log_struct;

#ifdef PNG_DBG_MEM	
static kal_uint32 m_index,max_alloc;
static m_log_struct m_log[256];
#endif
void (*_image_update_callback)(kal_int32 x1,kal_int32 y1,kal_int32 x2,kal_int32 y2) = NULL;
static png_voidp my_malloc(png_structp png_ptr, png_size_t size)
{
	png_voidp buf;

	buf = kal_adm_alloc(png_dm_id, size);
	if(buf == NULL) 
	{
		kal_uint32  left;
		
		left = kal_adm_get_total_left_size(png_dm_id);
		kal_prompt_trace(MOD_MED, "PNG malloc fail!!, len: %d, left: %d", size, left);
	}
	
#ifdef PNG_DBG_MEM	
	else
	{
		if(size > max_alloc)
			max_alloc = size;
		m_index &= 1023;
		m_log[m_index].len = (kal_uint32)size;
		m_log[m_index++].adrs = (kal_uint32)buf;
	}	
#endif

	return buf;
}
static void my_free(png_structp png_ptr, png_voidp ptr)
{
	
#ifdef PNG_DBG_MEM		
	kal_uint32 i = 1024;

	for(i=0;i<1024;i++)
	{
		if(m_log[i].adrs == (kal_uint32)ptr)
		{
			m_log[i].adrs = 0xEEEEEEEE;
			break;
		}
	}
	if(i == 1024)
		ASSERT(0);
#endif

	kal_adm_free(png_dm_id, ptr);
}

static void my_read_mem(png_structp pnt_ptr, png_bytep data, png_size_t len)
{
	kal_uint8 *src;

	src = (kal_uint8*)(png_dcb.cfg->in_buffer_adrs + png_dcb.file_index);
	kal_mem_cpy(data, src, len);
	png_dcb.file_index += len;
	if(png_dcb.file_index > png_dcb.cfg->in_buffer_size)
		PNG_SW_RAISE(PNG_ERR_READ_MEM);
}

static void my_read_file(png_structp pnt_ptr, png_bytep data, png_size_t len)
{
	kal_uint32 read;
	FS_HANDLE handle = png_dcb.cfg->file_handle;
	
	if(DRM_read_file(handle, data, len, &read) != FS_NO_ERROR)
		PNG_SW_RAISE(PNG_ERR_READ_FILE);	
	if(read != len)
		PNG_SW_RAISE(PNG_ERR_READ_FILE);	
 }

#if defined (_NAND_FLASH_BOOTING_)
#pragma arm section code = "PRIMARY_CODE" // move it into first NAND boot section
#endif
void png_init_sw(void)
{	
	// keep empty
}
#if defined(_NAND_FLASH_BOOTING_)
#pragma arm section code
#endif
extern 	kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);

#if defined(PNG_SW_UT)
static kal_uint32 t1, t2, period;
#endif

void png_timeout_hander(void* p) 
{
 png_dcb.is_timeout = KAL_TRUE;
}
void png_stop_timer(void)
{
    PNG_STOP_TIMER();
}
void sw_png_hook_img_update_callback(void (*image_update_callback)(kal_int32 x1,kal_int32 y1,kal_int32 x2,kal_int32 y2))
{
   _image_update_callback = image_update_callback;
}

png_report_status_enum png_decode_start_sw(png_config_struct *cfg, png_inform_struct *info)
{	
	kal_int32 result;
	kal_uint32 dest_x2,dest_y2;
	
#if defined(PNG_SW_UT)
	//dgb_print("png_decode_start_sw \r\n");
	t1 = drv_get_current_time();
#endif

#ifdef PNG_DBG_MEM
	m_index = 0;
	kal_mem_set(m_log, 0, sizeof m_log);
#endif

	#ifdef PNG_NEW_BUFFER_INTERFACE
	png_heap = (kal_uint8*)cfg->upper_buffer;
	row_img_ptr = (kal_uint8**)(cfg->upper_buffer + PNG_HEAP_SIZE/4);
	#endif
	//if(!png_dm_id)
	if(1)
	{
		png_dm_id = kal_adm_create(png_heap, PNG_HEAP_SIZE, NULL, KAL_FALSE);
		if (png_dm_id == 0)
		  ASSERT(0);
	}
	kal_mem_set(&png_dcb, 0, sizeof(png_dcb));
	png_dcb.cfg = cfg;	
	png_ptr = png_create_read_struct_2(PNG_LIBPNG_VER_STRING,
		 NULL, NULL, NULL,NULL,my_malloc,my_free);
	if (png_ptr == NULL)
	{
		ASSERT(0);
	}
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL)
	{
		ASSERT(0);
	}
	
	if(cfg->decode_mode == PNG_DECODE_FILE)
	{
		png_set_read_fn(png_ptr,(void *)NULL,my_read_file);
		
	}
	else // the total file is in the memory
	{
		png_set_read_fn(png_ptr,(void *)NULL,my_read_mem);
	}
   if ((result = setjmp(png_jmpbuf(png_ptr))) != 0)
   {
		png_dcb.result = result;
   	    kal_print("png sw decoder report error !");   	
		png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
		return result;
   }	   
   
   	//--init and start timer Here--
   	png_dcb.timeout_period = cfg->png_timeout_period;
   	if(png_gpt_handle == 0)
	 GPTI_GetHandle(&png_gpt_handle);
	 
	PNG_START_TIMER();
	 
	
   
	// read all PNG info up to image data
	png_read_info(png_ptr, info_ptr);
	
	#if defined(PNG_SW_UT)
	//dgb_print("color type: %d, w: %d, h: %d, interlaced: %d\r\n",
		info_ptr->color_type, info_ptr->width, info_ptr->height, info_ptr->interlace_type);
	#endif
	
	if (info_ptr->bit_depth == 16)
	   png_set_strip_16(png_ptr); // strip 16bits to 8bits
	if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE || info_ptr->bit_depth < 8)
	   png_set_expand(png_ptr);
	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
	   png_set_expand(png_ptr);
	if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY ||
	   info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
	   png_set_gray_to_rgb(png_ptr); // gray to RGB

	if(cfg->out_format != ARGB8888 || cfg->clip_en == KAL_TRUE)
		png_set_strip_alpha(png_ptr);
	// ARGB8888 is only supported while cfg->clip_en == KAL_FALSE;
	if(cfg->out_format == ARGB8888 && cfg->clip_en == KAL_TRUE)
		ASSERT(0);
	// after the transformations have been registered update info_ptr data        
	png_read_update_info(png_ptr, info_ptr);
	if(info_ptr->width > IMG_MAX_WIDTH || info_ptr->height > IMG_MAX_HEIGHT)
	{
		PNG_SW_RAISE(PNG_SW_TOO_LARGE);
	}
	info->img_w = info_ptr->width;
	info->img_h = info_ptr->height;
	info->bit_depth = info_ptr->bit_depth;
	info->color_type = info_ptr->color_type;
	info->num_trans = info_ptr->num_trans;
	info->num_plte = info_ptr->num_palette;
	info->interlaced = info_ptr->interlace_type;	
	info->use_work_buf = KAL_FALSE;
	
	
	IMG_RESIZER.src_key=cfg->src_key;
	if(cfg->out_format == RGB565)
		IMG_RESIZER.bytesperpixel = 2;
	else if(cfg->out_format == RGB888)		
		IMG_RESIZER.bytesperpixel = 3;
	else if(cfg->out_format == ARGB8888)
		IMG_RESIZER.bytesperpixel = 4;
	else
		ASSERT(0);

	is_PNG_cliped = cfg->clip_en;
	if(cfg->clip_en == KAL_TRUE)
	{
		IMG_RESIZER.clipx1 = cfg->clip_x1;
		IMG_RESIZER.clipx2 = cfg->clip_x2;
		IMG_RESIZER.clipy1 = cfg->clip_y1;
		IMG_RESIZER.clipy2 = cfg->clip_y2;
		IMG_RESIZER.out_buf = (kal_uint8*)cfg->output_buffer_adrs;
		IMG_RESIZER.out_buf_w = cfg->shadow_w;	
		IMG_RESIZER.interlaced = (kal_bool)png_ptr->interlaced;
		if(cfg->expect_w==0) cfg->expect_w = info->img_w;
		if(cfg->expect_h==0) cfg->expect_h = info->img_h;	
		if(cfg->expect_w < info_ptr->width || cfg->expect_h < info_ptr->height)
		{
			dest_x2 = (cfg->dest_x+cfg->expect_w-1);
			dest_y2 = (cfg->dest_y+cfg->expect_h-1);
		}
		else
		{
			dest_x2 = (cfg->dest_x+info_ptr->width-1);
			dest_y2 = (cfg->dest_y+info_ptr->height-1);
		}
		#if defined(PNG_NEW_BUFFER_INTERFACE)
		if(0 == png_img_resizer_init(info_ptr->width,info_ptr->height, cfg->dest_x, cfg->dest_y, dest_x2, dest_y2,(kal_uint8*)cfg->work_buffer_adrs, cfg->work_buffer_size)){
	      PNG_SW_RAISE(PNG_SW_TOO_LARGE);
	   }else if(-1 == png_img_resizer_init(info_ptr->width,info_ptr->height, cfg->dest_x, cfg->dest_y, dest_x2, dest_y2,(kal_uint8*)cfg->work_buffer_adrs, cfg->work_buffer_size)){
	      return PNG_FINISH_IMAGE;
	   }
		#else
		if(0 == png_img_resizer_init(info_ptr->width,info_ptr->height, cfg->dest_x, cfg->dest_y, dest_x2, dest_y2)){
			PNG_SW_RAISE(PNG_SW_TOO_LARGE);
	   }else if(-1 == png_img_resizer_init(info_ptr->width,info_ptr->height, cfg->dest_x, cfg->dest_y, dest_x2, dest_y2)){
	      return PNG_FINISH_IMAGE;
	   }
		#endif	
			
        if (_image_update_callback) {
           (*_image_update_callback)(cfg->dest_x, cfg->dest_y,dest_x2,dest_y2);
        }
		png_read_image(&png_dcb.is_timeout,png_ptr, NULL);
	}
	else
	{
		kal_uint32 row;
		
		for(row=0;row<info_ptr->height;row++)
			row_img_ptr[row] = (kal_uint8*)cfg->output_buffer_adrs + info_ptr->rowbytes*row;		
		png_read_image(&png_dcb.is_timeout,png_ptr, row_img_ptr);
	}
	
	if(png_dcb.is_timeout)
	 PNG_SW_RAISE(PNG_DECODE_TIMEOUT);
		
	png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL); 	
	cfg->cb(PNG_FINISH_IMAGE);

	#if defined(PNG_SW_UT)
	period = drv_get_duration_ms(t1);
	//dgb_print("total takes %d ms", period);
	#endif
	
	PNG_STOP_TIMER();
	return PNG_DECODING; 
	
}

png_report_status_enum png_decode_resume_sw(void)
{
	return PNG_FINISH_IMAGE;
}

void png_decode_stop_sw(void)
{
}

#if defined(PNG_SW_UT)
#include "rtfiles.h"
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"

#define FILE_BUFFER_SIZE  32*1024

static kal_uint8 in_buffer[FILE_BUFFER_SIZE];
static kal_uint16 lcd_buffer[LCD_WIDTH*LCD_HEIGHT];

static kal_uint8 file_name[256];
static kal_wchar file_name_w[256];
static kal_uint32 file_size;

static kal_eventgrpid my_Events;
static png_report_status_enum cb_status;
static png_config_struct png_config; 
static png_inform_struct png_info1;
static volatile kal_bool png_stop_now = KAL_FALSE;

static kal_uint32 t1, t2, period;
static kal_uint32 video_get_current_time(void)
{
	return (DRV_Reg32(0x80200230));
}

static kal_uint32 video_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
	kal_uint32 result;
	if (previous_time > current_time)
	{
		result = 0x80000 - previous_time + current_time;
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
}

static kal_uint32 video_get_duration_ms(kal_uint32 previous_time)
{
	kal_uint32 result;
	kal_uint32 current_time;
	
	current_time = video_get_current_time();
	result = video_get_duration_tick(previous_time, current_time);
	result*=1000;
	result/=32768;
	return result;
}

static void init_lcd_layer_window(void)
{
	lcd_layer_struct layer_data = {0};

	layer_data.source_key=0xFFFF;
	layer_data.source_key_enable=KAL_FALSE;
	layer_data.color_palette_enable=KAL_FALSE;
	layer_data.color_palette_select=0;
	layer_data.opacity_enable=KAL_FALSE;
	layer_data.opacity_value=10;
	layer_data.x_offset=0;
	layer_data.y_offset=0;
	layer_data.frame_buffer_address=(kal_uint32) lcd_buffer;
	layer_data.row_number=LCD_HEIGHT;
	layer_data.column_number=LCD_WIDTH;
	layer_data.rotate_value=0;											
	//layer_data.source_color_format = LCD_LAYER_SOURCE_COLOR_RGB565;
	//layer_data.memory_output= KAL_FALSE;
	//layer_data.memory_output= KAL_FALSE;
	config_lcd_layer_window(0,&layer_data);

}	/* init_lcd_layer_window() */
static void LCD_Init(void)
{
	lcd_power_up();
	lcd_init(MAIN_LCD,0xF800);
	init_lcd_layer_window();
	//SET_LCD_ROI_WINDOW_OFFSET(0,0);
	//SET_LCD_ROI_WINDOW_SIZE(LCD_WIDTH,LCD_HEIGHT);
	// turn on the backlight (GPIO5)
	GPIO_InitIO(1,5);
	GPIO_WriteIO(1,5);
	
}

static void LCDDisplay_adrs( kal_uint16 w, kal_uint16 h, kal_uint16 x, kal_uint16 y, void* adrs)
{
	lcd_frame_update_struct lcd_data = {0};

	lcd_power_up();
	SET_LCD_LAYER0_WINDOW_SIZE(w,h);
	SET_LCD_LAYER0_WINDOW_OFFSET(x,y);
	
	REG_LCD_LAYER0_BUFF_ADDR = (kal_uint32) adrs;
	lcd_data.module_id=LCD_UPDATE_MODULE_MMI;
	lcd_data.lcd_id=MAIN_LCD;
	lcd_data.fb_update_mode=LCD_SW_TRIGGER_MODE;
	lcd_data.lcm_start_x=0;
	lcd_data.lcm_start_y=0;
	lcd_data.lcm_end_x=LCD_WIDTH-1;
	lcd_data.lcm_end_y=LCD_HEIGHT-1;
	lcd_data.roi_offset_x=0;
	lcd_data.roi_offset_y=0;
	lcd_data.update_layer=LCD_LAYER0_ENABLE;
	lcd_data.memory_output = KAL_FALSE;
	lcd_data.block_mode_flag= KAL_TRUE;
	//lcd_data.tv_output = KAL_FALSE;
	lcd_fb_update(&lcd_data);	
}

static void LCD_Display(void *adrs, kal_uint16 w, kal_uint16 h)
{
	LCDDisplay_adrs(w,h,0,0,adrs);
}

void png_callback(png_report_status_enum status)
{
	cb_status = status;
	kal_set_eg_events(my_Events,1,KAL_OR);		
}

void png_main(void)
{
	kal_int32 s, file_count;
	RTFDOSDirEntry de;
	png_config_struct *p = &png_config;
	png_report_status_enum status;
	static kal_bool is_first = KAL_TRUE;		
	kal_uint32 flag;

	
 	LCD_Init();
	file_count = 0;
	if(RTFSetCurrentDir(L"c:\\png\\") < 0)
		while(1);
	while(1)
	{		
		kal_uint32 bytes;		
		
		if(is_first)
		{
			handle = RTFFindFirstEx(L"*.png", 0, 0, &de, file_name_w, 256);
			ASSERT(handle > 0);
			is_first = KAL_FALSE;
		}
		else
		{
			status = RTFFindNextEx(handle,&de,file_name_w, 256);
		}
		if(status != RTF_NO_ERROR)
			break;
		file_count++;
		kal_dchar2char(file_name_w,(char*)file_name);
		kal_wsprintf(file_name_w,(char*)file_name);
		p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,0);
		if(p->file_handle < 0 )
			ASSERT(0);
		DRM_file_size(p->file_handle, &file_size);	
		//dgb_print("\r\n[%d] File: %s\t, size: %d\t\r\n",file_count, file_name, file_size);
		if(file_size > sizeof in_buffer)
			p->decode_mode = PNG_DECODE_FILE;	
		else
			p->decode_mode = PNG_DECODE_MEMORY;	
		if(p->decode_mode == PNG_DECODE_MEMORY)
		{
			p->in_buffer_size = file_size;
			if(DRM_read_file(p->file_handle,in_buffer, file_size, &bytes) < 0)
				while(1);
		}		
		else
		{
			p->in_buffer_size = sizeof in_buffer;
		}		

		p->in_buffer_adrs = (kal_uint32)in_buffer;
		p->output_buffer_adrs = (kal_uint32)lcd_buffer;
		p->output_buffer_size = sizeof lcd_buffer;
	
		p->shadow_w = LCD_WIDTH;
		p->shadow_h = LCD_HEIGHT;
		p->clip_x1 = 20;
		p->clip_y1 = 20;
		p->clip_x2 = LCD_WIDTH-10;
		p->clip_y2 = LCD_HEIGHT-10;
		p->dest_x = 20;
		p->dest_y = 20;

		p->expect_w = LCD_WIDTH-30;
		p->expect_h = LCD_HEIGHT-30;
		
		p->clip_en = KAL_TRUE;
		p->out_format = RGB565;
		p->cb = png_callback;
		
		t1 = video_get_current_time();				
		status = png_decode_start_sw(p, &png_info1);
		if(status == PNG_DECODING)
			kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);		
		else
		{			
			//dgb_print("\n\r decode fail %d !", status);
			goto end;		
		}
		t2 = video_get_current_time();		
		period = video_get_duration_ms(t1);
		//dgb_print("png sw decode time in %d ms\r\n", period);
		LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);	

end:	

	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	}
	RTFFindClose(handle);
	is_first = KAL_TRUE;
}

#endif // PNG_SW_UT
#endif // USE_SW_PNG_DECODER
