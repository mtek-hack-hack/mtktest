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
 *	 gif_decoder_v2.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The drive of gif decoder version 2
 *		(supported on MT6228 and later version chips)8
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 // include header files
#include "kal_release.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "gpt_sw.h"
#include "visual_comm.h"
#include "drm_gprot.h"
#include "fat_fs.h"
#include "gif_decoder_v2.h"
#include	"bytestream_hw.h"
#include "2d_engine.h"
#include "visualhisr.h"

#if defined(USE_HW_GIF_DECODER_V2)

gif_dcb_struct gif_dcb;
gif_state_enum gif_state;
VISUAL_HISR_ID gif_hisr;						// hisr
kal_uint8 gif_gpt_handle;					// handler of gpt timer
gif_cache_struct gif_cache[GIF_CACHE_NUM];
kal_uint32 gif_cache_counter;		// current cache counter
kal_uint32 gif_cache_hit_count;	// accumulate the hit count
kal_uint8 gif_cache_index;
gif_disposal_method gif_last_disposal_method,gif_cur_disposal_method;
/*************************************************************************
* FUNCTION
*  gif_get_cache
*
* DESCRIPTION
*	1. serarch the cache to check if the id is in cache, otherwise , find the
*	oldest one and replace it.
*	2. the found cache index is store in the gif_cache_index
*
* PARAMETERS
*	id: cache id to distinguish differnt gif images.
*	ptr: cache address
*
* RETURNS
*	KAL_TRUE:	the id is in cache
*	KAL_FALSE:	the id is not in cache
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
kal_bool gif_get_cache(gif_config_struct *cfg, gif_cache_struct** ptr, kal_bool update)
{
	kal_uint32 i;
	kal_uint32 index;

	// search if the id is in the cache, start from the latest one
	i = 0;
	do{
		index = GIF_CACHE_GET_INDEX(gif_cache_counter-i++);
		if(cfg->cache_id == gif_cache[index].id && 
		   cfg->dest_x==gif_cache[index].dest_x &&
		   cfg->dest_y==gif_cache[index].dest_y)
		{
			gif_cache_hit_count++;
			gif_cache_index = index;
			*ptr = &gif_cache[index];
			return KAL_TRUE;
		}
	}while(i<GIF_CACHE_NUM);

	// not in cache and replace the oldest one
	if (update)
	{
	gif_cache_counter++;
	index = GIF_CACHE_GET_INDEX(gif_cache_counter-GIF_CACHE_NUM);
	*ptr = &gif_cache[index];
	gif_cache[index].valid_fn = 0;
	gif_cache[index].total_fn = 0xffff;
	gif_cache[index].latest_fn[0].fn = 0;
	gif_cache[index].latest_fn[1].fn = 0;
	gif_cache[index].id = cfg->cache_id;
	gif_cache[index].dest_x=cfg->dest_x;
	gif_cache[index].dest_y=cfg->dest_y;
	gif_cache_index = index;
	}

	return KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*  gif_reset_cache
*
* DESCRIPTION
*	reset the id of the cache
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*************************************************************************/
void gif_reset_cache(void)
{
	kal_uint32 i;

	for(i=0;i<GIF_CACHE_NUM;i++)
	{
		gif_cache[i].id = 0;
	}
}
/*************************************************************************
* FUNCTION
*  gif_reset_cache_entry
*
* DESCRIPTION
*	reset the id of the cache
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*************************************************************************/
void gif_reset_cache_entry(kal_uint32 id)
{
	kal_uint32 i;

	for(i=0;i<GIF_CACHE_NUM;i++)
	{
		if(gif_cache[i].id==id)
		 gif_cache[i].id = 0;
	}
}
/*************************************************************************
* FUNCTION
*  gif_update_cache_offset
*
* DESCRIPTION
*	1. decode one following frame
*	2. using polling instead interrupt event
*
* PARAMETERS
*
* RETURNS
*	KAL_TRUE	: a frame has been decoded
*	KAL_FALSE: decode fail
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
INTERNAL_FUNC void gif_update_cache_offset( kal_uint16 fn, kal_uint32 offset,gif_disposal_method last_disposal)
{
	gif_cache_struct *cache = &gif_cache[gif_cache_index];

	if( fn > cache->valid_fn)
	{
		if(fn < GIF_CACHE_FRAME_NUM)
		{
			cache->valid_fn = fn;
			cache->frame_offset[fn] = offset;
			cache->last_disposal[fn] = last_disposal;
		}
		else
		{
		 if(cache->latest_fn[0].fn==0 || cache->latest_fn[1].fn==0)
		 {
		  	 cache->latest_fn[0].fn = fn;
			 cache->latest_fn[0].offset =offset;
			 cache->latest_fn[0].last_disposal=last_disposal;
			 cache->latest_fn[1].fn = fn;
			 cache->latest_fn[1].offset =offset;
			 cache->latest_fn[1].last_disposal=last_disposal;
		 }
		 else if(fn < cache->latest_fn[0].fn)
		 {
			 cache->latest_fn[1].fn = cache->latest_fn[0].fn;
			 cache->latest_fn[1].offset = cache->latest_fn[0].offset;
			 cache->latest_fn[1].last_disposal=cache->latest_fn[0].last_disposal;
			 cache->latest_fn[0].fn = fn;
			 cache->latest_fn[0].offset =offset;
			 cache->latest_fn[0].last_disposal=last_disposal;
		 }
		 else if(fn > cache->latest_fn[0].fn && fn < cache->latest_fn[1].fn)
		 {
			 cache->latest_fn[1].fn = fn;
			 cache->latest_fn[1].offset = offset;
			 cache->latest_fn[1].last_disposal=last_disposal;
		 }
		 else if (fn > cache->latest_fn[1].fn)
		 {
			 cache->latest_fn[0].fn = cache->latest_fn[1].fn;
			 cache->latest_fn[0].offset = cache->latest_fn[1].offset;
			 cache->latest_fn[0].last_disposal=cache->latest_fn[1].last_disposal;
			 cache->latest_fn[1].fn = fn;
			 cache->latest_fn[1].offset =offset;
			 cache->latest_fn[1].last_disposal=last_disposal;

		 }
		}
	}
}
/*************************************************************************
* FUNCTION
*  gif_get_cache_offset
*
* DESCRIPTION
*	1. decode one following frame
*	2. using polling instead interrupt event
*
* PARAMETERS
*
* RETURNS
*	KAL_TRUE	: a frame has been decoded
*	KAL_FALSE: decode fail
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
INTERNAL_FUNC void gif_get_cache_offset( kal_uint16 fn, kal_uint32* offset)
{
	gif_cache_struct *cache = &gif_cache[gif_cache_index];

	if(fn > cache->valid_fn)
	{
		if(cache->latest_fn[0].fn != 0 && cache->latest_fn[1].fn != 0)
		{
			if(fn >= cache->latest_fn[0].fn && fn < cache->latest_fn[1].fn)
			{
				gif_dcb.cur_fn = cache->latest_fn[0].fn;
				*offset = cache->latest_fn[0].offset;
			}
			else if(fn >= cache->latest_fn[1].fn)
			{
				gif_dcb.cur_fn = cache->latest_fn[1].fn;
				*offset = cache->latest_fn[1].offset;
			}
			else
			{
				gif_dcb.cur_fn = cache->valid_fn;
				*offset = cache->frame_offset[cache->valid_fn];
			}
		}
		else
		{
			gif_dcb.cur_fn = cache->valid_fn;
			*offset = cache->frame_offset[cache->valid_fn];
		}

	}
	else
	{
		gif_dcb.cur_fn = fn;
		*offset = cache->frame_offset[fn];
	}
}

INTERNAL_FUNC void gif_get_last_disposal( kal_uint16 fn, gif_disposal_method* last_disposal)
{
  gif_cache_struct *cache = &gif_cache[gif_cache_index];

  last_disposal->disposal = GIF_NO_ACTION;

  if(fn==0)
  {
    *last_disposal=cache->frame_0_gce.last_disposal;

  /*
   if(cache->valid_fn==0)
   {
   	*last_disposal=gif_cur_disposal_method;
   }
   else if(cache->valid_fn< GIF_CACHE_FRAME_NUM)
   {
    	*last_disposal = cache->last_disposal[cache->valid_fn];
   }
   else
   {
    	*last_disposal = (cache->latest_fn[0].fn > cache->latest_fn[1].fn)? cache->latest_fn[0].last_disposal : cache->latest_fn[1].fn;
   }	*/
  }
  else
  {
	if(fn > cache->valid_fn)
	{
		if(cache->latest_fn[0].fn == fn)
		 *last_disposal = cache->latest_fn[0].last_disposal;
		else if(cache->latest_fn[1].fn == fn)
		 *last_disposal = cache->latest_fn[1].last_disposal;

	}
	else
	{
		*last_disposal = cache->last_disposal[fn];
	}
}

}

INTERNAL_FUNC void gif_lisr_entry(void)
{
	IRQMask(IRQ_GIF_CODE);
	//kal_activate_hisr(gif_hisr);
	visual_active_hisr(VISUAL_GIF_HISR_ID);
}

INTERNAL_FUNC void gif_hisr_entry(void)
{
  kal_uint32 boundary,offset,flush_dist=0;

	GIF_STOP_TIMER();
	gif_dcb.int_status = DRV_Reg(GIF_IRQ_STATUS);

	if(gif_dcb.int_status == GIF_STATUS_COMPLETE)
	{
	 hw_bytestream_dcb_struct *bytestream;
		boundary = DRV_Reg32(GIF_FILE_BOUNDARY);
	 flush_dist=boundary-gif_dcb.lzw_start;
	 GIF_TELL(&bytestream);
	 if(bytestream->t == HW_BYTESTREAM_TYPE_FILE &&
	    bytestream->type.file.buffer_content_size<flush_dist) //hw over read
	   gif_dcb.int_status=GIF_STATUS_PIXELERR;
	}

	gif_dcb.gif_cb(gif_dcb.int_status, gif_dcb.cur_fn);

	if(gif_dcb.int_status == GIF_STATUS_COMPLETE)
	{
		GIF_FLUSH(flush_dist);
		offset = GIF_TELL(NULL);
		gif_dcb.cur_fn++;
		gif_update_cache_offset(gif_dcb.cur_fn, offset,gif_cur_disposal_method);
		gif_state = GIF_STATE_READY;
		GIF_RESET();
	}
	else if(gif_dcb.int_status == GIF_STATUS_INEMPTY)
	{
		gif_state = GIF_STATE_PAUSE;
	}
	else
	{
		gif_state = GIF_STATE_ERR;
	}

	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
	IRQUnmask(IRQ_GIF_CODE);
}

INTERNAL_FUNC void gif_timeout_hander(void* p)
{
	gif_state = GIF_STATE_ERR;
	gif_dcb.is_timeout = KAL_TRUE;
	kal_print("hw gif decode timeout");
	DRV_WriteReg32(GIF_IRQ_EN, GIF_IRQ_EN_OFF);
	GIF_RESET();
	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
	if(gif_dcb.gif_cb  != NULL)
		gif_dcb.gif_cb(GIF_STATUS_TIMEOUT, gif_dcb.cur_fn);
}
INTERNAL_FUNC kal_bool gif_g2d_fillbg(void)
{
	gif_config_struct *cfg = gif_dcb.cfg;
    g2d_rectangle_fill_struct data;
    g2d_buffer_struct dest;
#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* Check-in with wrong CR
   if(gif_dcb.info.transparent_flag==KAL_TRUE &&gif_dcb.info.transparent_index == gif_dcb.info.bg_index)
    return KAL_FALSE;*/

    g2d_begin(G2D_OWNER_GDI,NULL);

    dest.base_address = (kal_uint32)cfg->output_buffer_adrs;
    dest.clip_x1 = cfg->clip_x1;
    dest.clip_y1 = cfg->clip_y1;
    dest.clip_x2 = cfg->clip_x2;
    dest.clip_y2 = cfg->clip_y2;
    switch(cfg->out_format)
    {
    case GIF_OUT_INDEX:
        dest.color_mode = FIRE_DEST_COLOR_8BPP_LUT_DIS;
        break;
    default:
	case GIF_OUT_RGB565:
        dest.color_mode = FIRE_DEST_COLOR_16BPP_RGB565;
        break;
	case GIF_OUT_RGB888:
        dest.color_mode = FIRE_DEST_COLOR_24BPP_RGB888;
        break;
    }
    dest.pitch = cfg->shadow_w;
    dest.height = cfg->shadow_h;
    dest.width = cfg->shadow_w;
    dest.x = 0;
    dest.y = 0;

    g2d_set_dest_buffer(G2D_OWNER_GDI, &dest);

/*
    data.start_x = cfg->dest_x;
    data.start_y = cfg->dest_y;
    data.width = cfg->expect_w;
    data.height = cfg->expect_h;
  */
    data.start_x = gif_last_disposal_method.left_position;
    data.start_y = gif_last_disposal_method.right_position;
    data.width = gif_last_disposal_method.width;;
    data.height = gif_last_disposal_method.height;;

#if 0  // disable for using MMI's bg_color   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
     data.fill_color=DRV_Reg32(GIF_BG_COLOR);  
   }
    data.gradient_fill_mode = KAL_FALSE;
    data.tilt_mode = KAL_FALSE;

    kal_prompt_trace(MOD_MMI, "hw disposal method: restore background(%d,%d)-(%d,%d) color=%x", 
                data.start_x,
                data.start_y,
                data.width,
                data.height,
                data.fill_color);

    g2d_fill_rectangle(G2D_OWNER_GDI, &data);

    g2d_end(G2D_OWNER_GDI);

	return KAL_TRUE;
}

/*INTERNAL_FUNC kal_uint8 gif_resz_ratio(kal_uint16 real, kal_uint16 expect)
{
	kal_uint32 ratio, i;

	if(real <= expect || expect == 0)
	{
		return 0;
	}
	else
	{
		ratio = real/expect;	// must > 1

		if(ratio*(kal_uint32)expect < (kal_uint32)real)
			ratio++;
		i = 1;
		while(i<16)
		{
			if(ratio <= (1<<i))
			{
				return (i);
			}
			else
			{
				i++;
			}
		}
		return ((i-1));
	}
}
*/
/*************************************************************************
* FUNCTION
*  gif_decode_hw
*
* DESCRIPTION
*	1. decode one following frame
*	2. using polling instead interrupt event
*
* PARAMETERS
*
* RETURNS
*	KAL_TRUE	: a frame has been decoded
*	KAL_FALSE: decode fail
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
INTERNAL_FUNC void gif_decode_hw(gif_config_struct *cfg)
{
	gif_info_struct *info = &gif_dcb.info;
	kal_uint32 out_format = cfg->out_format;
	kal_uint32 reg;
	kal_uint8 resz_w, resz_h, ct_size;
	hw_bytestream_dcb_struct *bytestream;
	gif_cache_struct *cache = &gif_cache[gif_cache_index];

	DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
	DRV_WriteReg32(GIF_IRQ_EN, GIF_IRQ_EN_OFF);
	//GIF_RESET();
	// the working buffer must be 4 byte aligned(remove after integration)
	ASSERT(((kal_uint32)cfg->stack_adrs & 3 ) == 0);
	ASSERT(((kal_uint32)cfg->tree_adrs & 3 ) == 0);
	ASSERT(((kal_uint32)cfg->LCT_adrs & 3 ) == 0);
	DRV_WriteReg32(GIF_TREE_START_ADDR, cfg->tree_adrs);
	DRV_WriteReg32(GIF_TREE_END_ADDR, cfg->tree_adrs+cfg->tree_size);
	DRV_WriteReg32(GIF_STK_START_ADDR, cfg->stack_adrs);
	DRV_WriteReg32(GIF_STK_END_ADDR,cfg->stack_adrs+cfg->stack_size);
	// DRV_WriteReg32(GIF_OUTFILE_START_ADDR, cfg->output_buffer_adrs);
	// DRV_WriteReg32(GIF_OUTFILE_END_ADDR, cfg->output_buffer_adrs+ cfg->output_buffer_size);
	DRV_WriteReg32(GIF_INFILE_COUNT, cfg->file_buffer_size);

	// calculate the resize ratio
	{
		kal_uint32 bytes_per_pixel;

		switch(cfg->out_format)
		{
		case GIF_OUT_INDEX: bytes_per_pixel=1;break;
		case GIF_OUT_RGB565: bytes_per_pixel=2;break;
		case GIF_OUT_RGB888: bytes_per_pixel=3;break;
		default: bytes_per_pixel=1;break;
		}
		if(cfg->expect_w==0) cfg->expect_w = info->lwidth;
		if(cfg->expect_h==0) cfg->expect_h = info->lheight;

		cfg->cal_work_buffer_info_func(
						&resz_w,
						&info->wb_dest_x,&info->wb_dest_y,
						&info->wb_width,&info->wb_height,
						cfg->work_buffer_size / bytes_per_pixel,
						info->lwidth,info->lheight,
						cfg->dest_x,cfg->dest_y,
						cfg->expect_w,cfg->expect_h,
						cfg->clip_x1,cfg->clip_y1,cfg->clip_x2,cfg->clip_y2);
		resz_h = resz_w;
	}

	info->use_work_buf = KAL_FALSE;
	info->resz_w = resz_w;
	info->resz_h  = resz_h;

	if((info->lwidth>>resz_w) != cfg->expect_w
	||(info->lheight>>resz_h)!= cfg->expect_h)
		info->use_work_buf = KAL_TRUE;

	/* Calculate the resized dimension and position of current frame */
	if(info->use_work_buf)
	{
	 /* Currently, Redraw whole background with bg color*/
	 gif_cur_disposal_method.left_position=	cfg->dest_x;;
	 gif_cur_disposal_method.right_position= cfg->dest_y;
	 gif_cur_disposal_method.width=cfg->expect_w;
	 gif_cur_disposal_method.height=cfg->expect_h;
	}
	else
	{
	 gif_cur_disposal_method.left_position=	cfg->dest_x+(info->x >> resz_w);
	 gif_cur_disposal_method.right_position= cfg->dest_y+(info->y >> resz_h);
	 gif_cur_disposal_method.width=info->w >> resz_w;
	 gif_cur_disposal_method.height=info->h >> resz_w;
	}

	if(resz_w || resz_h)
	{
		gif_dcb.resz_enable = KAL_TRUE;
		gif_dcb.resz_w = resz_w;
		gif_dcb.resz_h = resz_h;
		reg = (resz_h << 6)|(resz_w << 2)|1;
		DRV_WriteReg32(GIF_RESZ_CTRL, reg);
	}
	else
	{
		DRV_WriteReg32(GIF_RESZ_CTRL, 0);
	}

	// configure the clipping
	if(cfg->clip_enable)
	{
		kal_int32 x, y;

		out_format |= GIF_OUT_FORMAT_CLIP_EN;
		if(info->use_work_buf)
		{
			DRV_WriteReg32(GIF_LCD_WH, (info->wb_width<< 16)|info->wb_height);
			DRV_WriteReg32(GIF_CLIP_XY, (0 << 16)|0);
			DRV_WriteReg32(GIF_CLIP_WH, (info->wb_width<< 16)|info->wb_height);
			x = info->wb_dest_x;
			y = info->wb_dest_y;
		}
		else
		{
			DRV_WriteReg32(GIF_LCD_WH, ((cfg->shadow_w << 16)|cfg->shadow_h));
			DRV_WriteReg32(GIF_CLIP_XY, ((cfg->clip_x1 << 16)|cfg->clip_y1));
			DRV_WriteReg32(GIF_CLIP_WH, ((cfg->clip_x2- cfg->clip_x1+1)<< 16)|
				(cfg->clip_y2- cfg->clip_y1+1));
			x = cfg->dest_x  ;
			y = cfg->dest_y ;
		}
		if(x < 0 )
		{

			x *= -1;
			x |= 0x8000;
		}
		if(y < 0 )
		{

			y *= -1;
			y |= 0x8000;
		}
		DRV_WriteReg32(GIF_IMG_XY, ((x<< 16)|(y & 0xffff)));
		DRV_WriteReg32(GIF_IMG_OFFSET_XY, (((info->x >> resz_w) << 16)|
			(info->y >> resz_h)));
	}
	else
	{
		DRV_WriteReg32(GIF_IMG_XY, 0);
		DRV_WriteReg32(GIF_IMG_OFFSET_XY, 0);
	}

	if(gif_dcb.partial_enable == KAL_TRUE)
		out_format |= GIF_OUT_FORMAT_PARTIAL_EN;

	if(cfg->pack_enable)
	{
		out_format |= (GIF_OUT_FORMAT_PACK_EN)|(info->bpp<< 9);
		reg = cfg->p_resz_w_Q|(cfg->p_resz_w_N<<10)|(cfg->p_resz_w_D << 20);
		DRV_WriteReg32(GIF_PACK_RESZ_W, reg);
		reg = cfg->p_resz_h_Q|(cfg->p_resz_h_N<<10)|(cfg->p_resz_h_D << 20);
		DRV_WriteReg32(GIF_PACK_RESZ_H, reg);
	}
	DRV_WriteReg32(GIF_MIN_CODE_SIZE, info->min_code);
	DRV_WriteReg32(GIF_INTERLACE_CTRL, info->interlaced);
	GIF_SET_WIDTH_HEIGHT(info->w,info->h);
	if(info->LCT_flag)
	{
		DRV_WriteReg32(GIF_CT_START_ADDR, cfg->LCT_adrs);
		ct_size = info->LCT_size;
	}
	else
	{
		DRV_WriteReg32(GIF_CT_START_ADDR, cache->GCT);
		ct_size = cache->GCT_size;
	}
	if(!info->use_work_buf && info->transparent_flag && cfg->transparent_enable)
	{
		// always not output while encounter tc_index
		reg = 3|(info->transparent_index << 2);
		DRV_WriteReg32(GIF_TRANS_CTRL, reg);
	}
	else
	{
		DRV_WriteReg32(GIF_TRANS_CTRL, 0);
	}
	// set background color (RGB888) or index
	if(out_format != GIF_OUT_INDEX)
	{
#if 0 // disable for using MMI's bg_color 
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
        DRV_WriteReg32(GIF_BG_COLOR, cfg->bg_color);
	}
	else
	{
		DRV_WriteReg32(GIF_BG_COLOR, cache->bg_index << 24);
	}

	// update the lzw start address and the input buffer count
	GIF_TELL(&bytestream);
	if(cfg->decode_mode == GIF_DECODE_FILE )
	{
		/* HW issue that the ipnut file count can't be too small */
		if(bytestream->type.file.buffer_content_size<GIF_REFILL_THRESH)
		 GIF_REFILL();

		gif_dcb.lzw_start = (kal_uint32)bytestream->type.file.buffer_reader;
		DRV_WriteReg32(GIF_INFILE_START_ADDR,gif_dcb.lzw_start);
		if(gif_dcb.partial_enable)
			DRV_WriteReg32(GIF_INFILE_COUNT,bytestream->type.file.buffer_content_size);
	}
	else
	{
		gif_dcb.lzw_start = (kal_uint32)bytestream->type.mem.buffer_ptr+bytestream->type.mem.buffer_offset;
		DRV_WriteReg32(GIF_INFILE_START_ADDR,gif_dcb.lzw_start);
	}
	DRV_WriteReg32(GIF_OUT_FORMAT, out_format);

	if( info->use_work_buf)
	{
		kal_uint8 r,g,b;
		kal_uint32 *ct;
		kal_uint32 color, src_key,i;

		// report src_key(transparent index)
		// remove src_key color with different index
		DRV_WriteReg32(GIF_OUTFILE_START_ADDR, cfg->work_buffer_adrs);
		DRV_WriteReg32(GIF_OUTFILE_END_ADDR, cfg->work_buffer_adrs+ cfg->work_buffer_size);
		ct = (kal_uint32*)DRV_Reg32(GIF_CT_START_ADDR);
		color = ct[info->transparent_index];
		b = (color)&0xff;
		g = (color>>8)&0xff;
		r = (color>>16)&0xff;
		if(cfg->out_format == GIF_OUT_RGB888)
			src_key = (r<<16)|(g<<8)|b;
		else if(cfg->out_format == GIF_OUT_RGB565)
			src_key = ((r>>3)<<11)|((g>>2)<<5)|(b>>3);
		else // GIF_OUT_INDEX
			src_key = info->transparent_index;

		// remove the color of differnet trans.index but the same with transparent color
		for(i=0;i<=ct_size;i++)
		{
			if(cfg->out_format == GIF_OUT_RGB888)
			{
				if(src_key == ct[i])
				{
					ct[i] ^= (1<<17);
				}
			}
			else if(cfg->out_format == GIF_OUT_RGB565)
			{
				kal_uint32 r1,b1,g1;
				kal_uint32 c;

				b1 = (ct[i])&0xff;
				g1 = (ct[i]>>8)&0xff;
				r1 = (ct[i]>>16)&0xff;
				c = ((r1>>3)<<11)|((g1>>2)<<5)|(b1>>3);
				if( c == src_key)
				{
					ct[i] ^= (1<<20);
				}
			}
		}
		ct[info->transparent_index] = color; // restore again, because it was be changed.
		info->src_key_2d = src_key;
	}
	else
	{
		DRV_WriteReg32(GIF_OUTFILE_START_ADDR, cfg->output_buffer_adrs);
		DRV_WriteReg32(GIF_OUTFILE_END_ADDR, cfg->output_buffer_adrs+ cfg->output_buffer_size);
	}

	gif_get_last_disposal(gif_dcb.cur_fn,&gif_last_disposal_method);

/*
  	if(!gif_dcb.cache_hit)
	 gif_last_disposal_method.disposal=GIF_RESTORE_BG;
	*/

	// handling the disposal method according the the previou frame.
	if((cfg->disposal_en && (gif_last_disposal_method.disposal == GIF_RESTORE_BG)))
		gif_g2d_fillbg();

	DRV_WriteReg32(GIF_IRQ_EN, GIF_IRQ_EN_ALL);
	GIF_START_TIMER();
	GIF_START();
}

/*************************************************************************
* FUNCTION
*  gif_init
*
* DESCRIPTION
*	get resource memeory from caller(share the same resource with SW decoder)
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
void gif_init(void)
{
	if(gif_hisr == 0)
	{
   	//gif_hisr = kal_create_hisr("GIF_HISR",2,512,gif_hisr_entry,NULL);
   	VISUAL_Register_HISR(VISUAL_GIF_HISR_ID,gif_hisr_entry);
   	IRQ_Register_LISR(IRQ_GIF_CODE, gif_lisr_entry,"gif_lisr");
   	IRQSensitivity(IRQ_GIF_CODE,LEVEL_SENSITIVE);
	}
	IRQUnmask(IRQ_GIF_CODE);

	// initialize the GPT
	if(gif_gpt_handle == 0)
		GPTI_GetHandle(&gif_gpt_handle);
	gif_cache_counter = GIF_CACHE_INIT_COUTNER;
	gif_state = GIF_STATE_READY;
}
/*************************************************************************
* FUNCTION
*  gif_decode_process
*
* DESCRIPTION
*	get resource memeory from caller(share the same resource with SW decoder)
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
INTERNAL_FUNC gif_report_status_enum gif_decode_process(gif_config_struct *cfg)
{
	gif_info_struct *my_info = &gif_dcb.info;
	gif_cache_struct *cache = &gif_cache[gif_cache_index];
	gif_report_status_enum status = GIF_NO_FRAME;

	gif_cur_disposal_method.disposal=GIF_NO_ACTION;

	//gif_get_last_disposal(gif_dcb.cur_fn,&gif_last_disposal_method);

   do
   {
    	switch(GIF_GET_U8())
      {
			case GIF_EXT_LABEL:	// 0x21
						if(GIF_GET_U8() == GIF_GCE_LABEL)
						{	//	Process the GIF extension block(GCE)(0xf9)
							kal_uint8 a,b;

							GIF_FLUSH(1);
							a = GIF_GET_U8();
							my_info->disposal = (a>>2)&7;

							gif_cur_disposal_method.disposal=my_info->disposal;

							my_info->delay_time = GIF_GET_U16();
							b = GIF_GET_U8();
							if(a&GIF_GCE_PACK_TC_FLAG )
							{
								my_info->transparent_index = b;
								my_info->transparent_flag = KAL_TRUE;
							}
							else
							{
								my_info->transparent_flag = KAL_FALSE;
							}
							GIF_FLUSH(1);
						}
						else // skip other extensions
						{
							kal_uint32 len;
							while(1)
							{
								len = GIF_GET_U8();
								if(len ==0) break;
								GIF_FLUSH(len);
							}
						}
						break;
			case GIF_IMD_LABEL: // 0x2C, ',' image descriptor
			{
						kal_uint8 a;

						my_info->x = GIF_GET_U16();
						my_info->y = GIF_GET_U16();
						my_info->w = GIF_GET_U16();
						my_info->h = GIF_GET_U16();
						gif_dcb.timeout_period = GIF_TIMEOUT_PERIOD;
						a = GIF_GET_U8();
						my_info->LCT_flag = ((a&GIF_IMD_PACK_LCT_FLAG) != 0);
						my_info->interlaced = ((a&GIF_IMD_PACK_INTERLACE) != 0);
						if(my_info->LCT_flag)
						{	// retreive the LCT
							kal_uint32 i,bpp;

							bpp = (a&GIF_IMD_PACK_LCT_SIZE) + 1;
							my_info->bpp = bpp;
							my_info->LCT_size = (1 << bpp)-1;
							for(i=0; i<=my_info->LCT_size; i++)
							{
								kal_uint8 r,g,b;
								kal_uint32 e;

								r = GIF_GET_U8();
								g = GIF_GET_U8();
								b = GIF_GET_U8();
								e = (r<<16)|(g<<8)|(b);
								// replace MMI's source key color with XOR 1
								if(cfg->out_format == GIF_OUT_RGB565)
								{
									kal_uint16 x;

									x = ((r>>3)<<11)|((g>>2)<<5)|(b>>3);
									if(x == cfg->src_key)
									{
										e ^= 0x8;
									}
								}
								else // 888 and index color type
								{
									if(e == cfg->src_key)
									{
										e ^= 1;
									}
								}
								cfg->LCT_adrs[i] = e;
							}
						}
						// get minimum code size
						my_info->min_code = GIF_GET_U8();
						gif_decode_hw(cfg);
						status = GIF_DECODING;
						goto end;
			}
						break;
         case GIF_TRAILER_LABEL: // 0x3b, trailer
         			gif_dcb.trailer = KAL_TRUE;
      				cache->total_fn = gif_dcb.cur_fn-1;
      				status =  GIF_NO_FRAME;
      				gif_state = GIF_STATE_READY;
            		goto end;
    	}

	} while(GIF_IS_EOF()!= KAL_TRUE);
end:
	return status;

}

/*************************************************************************
* FUNCTION
*  gif_find_last_GCE
*
* DESCRIPTION
*	Find out the last GCE of the entire gif file
*
* PARAMETERS
*
* RETURNS
*	KAL_FALSE:	no gce found
* 	KAL_TRUE:	gce found
*
* GLOBALS AFFECTED
	NONE
*************************************************************************/
kal_bool gif_get_last_GCE(gif_cache_struct *cache,gif_config_struct *cfg)
{
 kal_uint32	file_offset;
 kal_uint32	LCT_size,len;
 kal_bool	result=KAL_FALSE;
 gif_gce_struct   *gce_struct;

 file_offset=GIF_TELL(NULL);

 gce_struct=&(cache->frame_0_gce);
 gce_struct->delay_time=0;
 gce_struct->transparent_flag=KAL_FALSE;
 gce_struct->last_disposal.disposal=GIF_NO_ACTION;

    do
   {
      	switch(GIF_GET_U8())
      {
			case GIF_EXT_LABEL:	// 0x21
						if(GIF_GET_U8() == GIF_GCE_LABEL)
						{	//	Process the GIF extension block(GCE)(0xf9)
							kal_uint8 a,b;

							GIF_FLUSH(1);
							a = GIF_GET_U8();
							gce_struct->last_disposal.disposal = (a>>2)&7;
							gce_struct->delay_time = GIF_GET_U16();

							b = GIF_GET_U8();
							if(a&GIF_GCE_PACK_TC_FLAG )
							{
								gce_struct->transparent_index = b;
								gce_struct->transparent_flag = KAL_TRUE;
							}
							else
							{
								gce_struct->transparent_flag = KAL_FALSE;
							}
							GIF_FLUSH(1);
							result=KAL_TRUE;

						}
						else // skip other extensions
						{
							while(1)
							{
								len = GIF_GET_U8();
								if(len ==0) break;
								GIF_FLUSH(len);
							}
						}
						break;
			case GIF_IMD_LABEL: // 0x2C, ',' image descriptor
			{
						kal_uint8 a;

						GIF_GET_U16();//x
						GIF_GET_U16();//y
						GIF_GET_U16();//w
						GIF_GET_U16();//h

						a = GIF_GET_U8();

						if((a&GIF_IMD_PACK_LCT_FLAG) != 0)
						{	// retreive the LCT
							kal_uint32 bpp;

							bpp = (a&GIF_IMD_PACK_LCT_SIZE) + 1;
							LCT_size = (1 << bpp)*3;
							GIF_FLUSH(LCT_size);
						}
						GIF_GET_U8(); //min code;

						while(1)// skip data blocks
						{
						 len = GIF_GET_U8();
						 if(len ==0) break;
						  GIF_FLUSH(len);
						}
			}
						break;
 	        	case GIF_TRAILER_LABEL: // 0x3b, trailer
			 goto end;
    	}
    }while(GIF_IS_EOF()!= KAL_TRUE);

end:

 /* Currently, Redraw whole background with bg color*/
   gce_struct->last_disposal.left_position=  cfg->dest_x;
   gce_struct->last_disposal.right_position= cfg->dest_y;

   if(cfg->expect_w==0 || cfg->expect_h==0)
   {
      gce_struct->last_disposal.width=cache->lwidth;
      gce_struct->last_disposal.height=cache->lheight;
   }
   else
   {
      gce_struct->last_disposal.width=    cfg->expect_w;
      gce_struct->last_disposal.height=   cfg->expect_h;
   }
 GIF_SEEK(file_offset);	//get back to the file offset
 return result;
}

/*************************************************************************
* FUNCTION
*  gif_decode_start
*
* DESCRIPTION
*	start to decode a specified frame of a gif image (non blocking)
*
* PARAMETERS
*
* RETURNS
*	GIF_DECODING
*  GIF_INVALID_FORMAT
*	GIF_NO_FRAME
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
gif_report_status_enum gif_decode_start(gif_config_struct *cfg, gif_info_struct *info)
{
	kal_uint32 offset;
	gif_cache_struct *cache;
	kal_bool cache_hit,result;
	gif_report_status_enum status;
	gif_info_struct *my_info = &gif_dcb.info;

	ASSERT(gif_state == GIF_STATE_READY);
	gif_state = GIF_STATE_BUSY;
	// ASSERT(cfg->file_buffer_size >= GIF_MIN_FILE_BUF_SIZE);
	ASSERT(cfg->gif_cb != NULL);

	kal_mem_set(&gif_dcb, 0, sizeof(gif_dcb));
	gif_dcb.cfg = cfg;
	gif_dcb.gif_cb = cfg->gif_cb;
     	gif_last_disposal_method.disposal = 0;
	if(cfg->decode_mode == GIF_DECODE_FILE)
	{

		gif_dcb.file_size = hw_bytestream_create_file(HW_BYTESTREAM_GIF, cfg->file_handle,(kal_uint8*)cfg->file_buffer_adrs, cfg->file_buffer_size);
		if(gif_dcb.file_size)
		{
			if(gif_dcb.file_size > cfg->file_buffer_size)
				gif_dcb.partial_enable = KAL_TRUE;
		}
	}
	else // GIF_DECODE_MEMORY: the total gif file is in the memory
	{
		hw_bytestream_create(HW_BYTESTREAM_GIF,(kal_uint8*)cfg->file_buffer_adrs,cfg->file_buffer_size);
 		gif_dcb.file_size = cfg->file_buffer_size;
	}

	GIF_TRY
	// get a cache
	cache_hit = gif_get_cache(cfg, &cache, KAL_TRUE);
	gif_dcb.cache_hit=cache_hit;

	offset = 0;
	if( cache_hit == KAL_TRUE)
	{
 		gif_get_cache_offset(cfg->frame_number,&offset);
 		if(cfg->frame_number > cache->total_fn || (offset+10) >= gif_dcb.file_size)
		{
			gif_state = GIF_STATE_READY;
			return GIF_NO_FRAME;
		}
		GIF_SEEK(offset);
	}
	else
	{
		kal_uint8 a;

 		if(GIF_GET_U8()!= 'G' || GIF_GET_U8() != 'I' || GIF_GET_U8() != 'F')
		{
			kal_print("GIF_INVALID_FORMAT");
			cache->id = 0;
			status = GIF_INVALID_FORMAT;
			gif_state = GIF_STATE_READY;
			goto end;
		}
		GIF_FLUSH(3);
 		cache->lwidth = GIF_GET_U16();
		cache->lheight = GIF_GET_U16();
		a = GIF_GET_U8();
		cache->GCT_flag = ((a&0x80) == 0x80);
		cache->bpp = ((a&0x7)+1);
		if(cfg->pack_enable == KAL_TRUE)
			ASSERT(cache->bpp == 1 || cache->bpp == 2 || cache->bpp == 4 || cache->bpp == 8);
		cache->GCT_size = (1 << (cache->bpp))-1; // 255 means 256
		cache->bg_index = GIF_GET_U8();
		GIF_FLUSH(1);
		// retreive the golbal color table
		if(cache->GCT_flag)
		{
			kal_uint32 i;

			for(i=0; i<=cache->GCT_size; i++)
			{
				kal_uint8 r,g,b;
				kal_uint32 e;

				r = GIF_GET_U8();
				g = GIF_GET_U8();
				b = GIF_GET_U8();
				e = (r<<16)|(g<<8)|(b);
				// replace MMI's source key color with XOR 1 Blue
				if(cfg->out_format == GIF_OUT_RGB565)
				{
					kal_uint16 x;

					x = ((r>>3)<<11)|((g>>2)<<5)|(b>>3);
					if(x == cfg->src_key)
					{
						e ^= 0x8;
					}
				}
				else // 888 and index color type
				{
					if(e == cfg->src_key)
					{
						e ^= 1;
					}
				}
				cache->GCT[i]=e;
			}
		}
		cache->frame_offset[0] = GIF_TELL(NULL);

		/* Find the disposal method, only when cacge miss. */
		result=gif_get_last_GCE(cache,cfg);
	}
	if(cfg->out_format == GIF_OUT_INDEX && cfg->GCT_adrs != NULL)
	{
		kal_mem_cpy(cfg->GCT_adrs,cache->GCT,sizeof(cache->GCT) );
	}

	my_info->lwidth = cache->lwidth;
	my_info->lheight = cache->lheight;
	my_info->GCT_flag = cache->GCT_flag;
	my_info->GCT_size = cache->GCT_size;
	my_info->bg_index = cache->bg_index;
	my_info->bpp = cache->bpp;

/*	if(cache->valid_fn==0 && result && !cache->frame_0_gce.transparent_flag)
	 gif_g2d_fillbg();*/

	status = gif_decode_process(cfg);
	if(status == GIF_NO_FRAME)
		cache->total_fn = cfg->frame_number -1;
	*info = gif_dcb.info;
	GIF_CATCH_BEGIN
	gif_state = GIF_STATE_READY;
	status = GIF_INVALID_FORMAT;
	GIF_CATCH_END

end:

	return status;
}

/*************************************************************************
* FUNCTION
*  gif_decode_resume
*
* DESCRIPTION
*	get resource memeory from caller(share the same resource with SW decoder)
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
gif_report_status_enum gif_decode_resume(gif_config_struct *cfg, gif_info_struct *info)
{

	hw_bytestream_dcb_struct *bytestream;
	gif_status_enum int_status;
	gif_report_status_enum status = GIF_DECODING;
	// kal_uint32 offset;

	GIF_TRY
	int_status = gif_dcb.int_status;
	if(int_status == GIF_STATUS_INEMPTY)
	{
		DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
		GIF_TELL(&bytestream);
		GIF_FLUSH(bytestream->type.file.buffer_content_size);
		GIF_REFILL();
		gif_dcb.lzw_start = (kal_uint32)bytestream->type.file.buffer_ptr;
		DRV_WriteReg32(GIF_INFILE_START_ADDR, gif_dcb.lzw_start);
		DRV_WriteReg32(GIF_INFILE_COUNT, bytestream->type.file.buffer_size);
		// status = GIF_DECODING;
		GIF_START_TIMER();
		GIF_RESUME();
	}
	else if(int_status == GIF_STATUS_COMPLETE)
	{
		status = gif_decode_process(cfg);
		*info = gif_dcb.info;
	}
	GIF_CATCH_BEGIN
	gif_state = GIF_STATE_READY;
	status = GIF_INVALID_FORMAT;
	GIF_CATCH_END

	return status;

}

/*************************************************************************
* FUNCTION
*  gif_decode_stop
*
* DESCRIPTION
*	get resource memeory from caller(share the same resource with SW decoder)
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
void gif_decode_stop(void)
{
	gif_state = GIF_STATE_READY;

	DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
	GIF_RESET();
	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
}

// #define GIF_UINT_TEST
#if defined (GIF_UINT_TEST)
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "rtfiles.h"

// unit test code start here
#define FILE_BUFFER_SIZE		(32*1024)
#define OUT_BUFFER_SIZE			(LCD_WIDTH*LCD_HEIGHT*2)
#define GIF_STACK_SIZE			(0x1000+4)
#define GIF_TREE_SIZE			(0x4000+4)
#define GIF_CT_SIZE				(256)	// x4

gif_config_struct gif_config;
gif_info_struct gif_info;
kal_uint8 in_buffer[FILE_BUFFER_SIZE];
kal_uint16 lcd_buffer[LCD_WIDTH*LCD_HEIGHT];
kal_uint16 lcd_buffer_i[LCD_WIDTH*LCD_HEIGHT];

kal_uint32 gif_tree[GIF_TREE_SIZE/sizeof(kal_uint32)];
kal_uint32 gif_stack[GIF_STACK_SIZE/ sizeof(kal_uint32)];
kal_uint32 gif_lct[GIF_CT_SIZE];
kal_uint8 file_name[256];
kal_wchar file_name_w[256];
kal_uint32 file_size;

#define  GIF_NUM		4
gif_config_struct gif_cfg[GIF_NUM];
kal_uint8 in_buf[GIF_NUM][FILE_BUFFER_SIZE];
kal_uint8 f_name[GIF_NUM][256];
kal_wchar f_name_w[GIF_NUM][256];
kal_uint32 fs[GIF_NUM];

kal_eventgrpid GIF_Events;
gif_status_enum cb_status;
kal_uint32 cb_fn;

volatile kal_bool  gif_stop_now = KAL_FALSE;

// test case 1:	one file, in order
// test case 2: 	one image in memory, in order
// test case 3:	one file in any order
// test case 4:	one image in memory decoded in any order.
// test case 5: 	four images (2 files and 2 in memory) decoded in order.
// test case 6: 	8 images (4 files and 4 in memory) decoded in any order.
// test case 7:	one image more than 100 frames decoded in order
// test case 8:	one image more than 100 frames decoded in order
// test case 9:	various clip, resizing ratio, and dest_x, dest_y
// test case 10:	pack mode
// test case 11:	various output mode(RGB888) ???
// test case 12: decode a very large file of 1,792,163 bytes(it takes about 2.9s)
// test case 13: verify timeout mechanism
void GPT3_Init_my(void)
{
	// clear pdn bit of GPT
	DRV_Reg(0x80000324) = 1;
	// set clock
	DRV_Reg(0x80100024) = 4; // 4: 1k, 7: 125hz
	// start free running
	DRV_Reg(0x8010001c) = 1;
}


kal_uint32 GPT3_GetCount(void)
{
	return DRV_Reg(0x80100020);
}

kal_uint32 GPT3_TimeDiff(kal_uint32 time1)
{
	kal_uint32 time2;

	time2 = DRV_Reg(0x80100020);
	if(time2 >= time1)
		return (time2 - time1);

	return (0xffff - time1 + time2);
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
	layer_data.source_color_format = LCD_LAYER_SOURCE_COLOR_RGB565;
	config_lcd_layer_window(0,&layer_data);

}	/* init_lcd_layer_window() */
static void LCD_Init(void)
{
	lcd_init(MAIN_LCD,0xF800);
	init_lcd_layer_window();
	SET_LCD_ROI_WINDOW_OFFSET(0,0);
	SET_LCD_ROI_WINDOW_SIZE(LCD_WIDTH,LCD_HEIGHT);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);

}
static void LCDDisplay_adrs( kal_uint16 w, kal_uint16 h, kal_uint16 x, kal_uint16 y, void* adrs)
{
	lcd_frame_update_struct lcd_data;

	lcd_power_ctrl(KAL_TRUE);
	SET_LCD_LAYER0_WINDOW_SIZE(w,h);
	SET_LCD_LAYER0_WINDOW_OFFSET(x,y);

	REG_LCD_LAYER0_BUFF_ADDR = (kal_uint32) adrs;
	lcd_data.module_id=LCD_UPDATE_MODULE_MEDIA;
	lcd_data.lcd_id=MAIN_LCD;
	lcd_data.fb_update_mode=LCD_SW_TRIGGER_MODE;
	lcd_data.lcm_start_x=0;
	lcd_data.lcm_start_y=0;
	lcd_data.lcm_end_x=LCD_WIDTH-1;
	lcd_data.lcm_end_y=LCD_HEIGHT-1;
	lcd_data.roi_offset_x=0;
	lcd_data.roi_offset_y=0;
	lcd_data.update_layer=LCD_LAYER0_ENABLE;

	lcd_fb_update(&lcd_data);
}
static void GIF_Display(void *adrs, kal_uint16 w, kal_uint16 h)
{
	LCDDisplay_adrs(w,h,0,0,adrs);
}

kal_uint32 fast_semi_crc(kal_uint8* src,kal_uint32 size)
{
	register kal_uint32 crc,temp,i;
	crc = 0;
	for(i=0;i<size;i++)
	{
		if(crc >>15) temp=1; else temp=0;
		crc = (((crc<<1) & 0x0ffff) + temp) ^ (kal_uint32)*src;
		src++;
	}
	return crc;
}
kal_uint32 gif_get_cache_key_from_file(kal_uint8* filename,kal_uint32 file_size)
{
	// Compute the cache key by filename and file size
	kal_uint32 cache_id;

	cache_id = (kal_uint32) fast_semi_crc((kal_uint8 *) filename, (kal_uint32)strlen((char *)filename));
	cache_id ^= (kal_uint32) file_size;

	return cache_id;
}

void gif_callback(gif_status_enum status, kal_uint32 fn)
{

	cb_status = status;
	cb_fn = fn;
	kal_set_eg_events(GIF_Events,1,KAL_OR);


}
// file mode, multi frame, no partila input, no resizing
void test_case_1(void)
{
	gif_config_struct *p = &gif_config;
	gif_report_status_enum status;

	//sprintf(file_name, "c:\\gif\\test1.gif"); // single frame
	sprintf(file_name, "c:\\gif\\3d_book2.gif"); // multi frame
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = GIF_DECODE_FILE;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);
	DRM_file_size(p->file_handle, &file_size);
	p->cache_id = gif_get_cache_key_from_file(file_name, file_size);
	p->file_buffer_adrs = in_buffer;
	p->file_buffer_size = file_size;
	p->output_buffer_adrs = (kal_uint8*)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;
	p->stack_adrs = gif_stack;
	p->stack_size = GIF_STACK_SIZE;
	p->tree_adrs = gif_tree;
	p->tree_size = GIF_TREE_SIZE;
	p->LCT_adrs = gif_lct;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH-1;
	p->clip_y2 = LCD_HEIGHT-1;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->pack_enable =  KAL_FALSE;
	// 1:1 ratio (pack mode)
	p->p_resz_w_Q = 0;
	p->p_resz_w_N = 1;
	p->p_resz_w_D = 0;
	p->p_resz_h_Q = 0;
	p->p_resz_h_N = 1;
	p->p_resz_h_D = 0;

	p->clip_enable = KAL_TRUE;
	p->out_format = GIF_OUT_RGB565;
	p->gif_cb = gif_callback;

	p->frame_number = 0;
	// decoding until GIF_NO_FRAME is occurs
	while(1)
	{
		kal_uint32 flag;

		status = gif_decode_start(p, &gif_info);
		if(status ==  GIF_INVALID_FORMAT || status == GIF_NO_FRAME)
			goto end;
		kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);

		while(1)
		{
			if(cb_status == GIF_STATUS_INEMPTY)
			{
				if(!gif_stop_now)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else
				{
					gif_decode_stop();
					goto end;
				}
			}
			else if (cb_status == GIF_STATUS_COMPLETE)
			{
				if(p->frame_number > cb_fn)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else if(p->frame_number == cb_fn)
				{
					GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					p->frame_number++;
					break;
				}
			}
			else
			{
				gif_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				break;
			}
		}
	}

end:
	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
}

// memory mode, single frame, no resizing
void test_case_2(void)
{
	gif_config_struct *p = &gif_config;
	gif_report_status_enum status;
	kal_uint32 bytes;

	p->decode_mode = GIF_DECODE_MEMORY;
	sprintf(file_name, "c:\\gif\\test1.gif"); // single
	kal_wsprintf(file_name_w,(char*)file_name);
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);
	DRM_file_size(p->file_handle, &file_size);
	p->cache_id = gif_get_cache_key_from_file(file_name, file_size);
	if(file_size <= sizeof in_buffer)
		DRM_read_file(p->file_handle,in_buffer, file_size, &bytes);
	else
		ASSERT(0);

	p->file_buffer_adrs = in_buffer;
	p->file_buffer_size = file_size;
	p->output_buffer_adrs = (kal_uint8*)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;
	p->stack_adrs = gif_stack;
	p->stack_size = GIF_STACK_SIZE;
	p->tree_adrs = gif_tree;
	p->tree_size = GIF_TREE_SIZE;
	p->LCT_adrs = gif_lct;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH-1;
	p->clip_x2 = LCD_HEIGHT-1;
	p->dest_x = 0;
	p->dest_y = 100;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->pack_enable =  KAL_FALSE;
	// 1:1 ratio (pack mode)
	p->p_resz_w_Q = 0;
	p->p_resz_w_N = 1;
	p->p_resz_w_D = 0;
	p->p_resz_h_Q = 0;
	p->p_resz_h_N = 1;
	p->p_resz_h_D = 0;

	p->clip_enable = KAL_TRUE;
	p->out_format = GIF_OUT_RGB565;
	p->frame_number = 0;
	p->gif_cb = gif_callback;

	while(1)
	{
		kal_uint32 flag;

		status = gif_decode_start(p, &gif_info);
		if(status ==  GIF_INVALID_FORMAT || status == GIF_NO_FRAME)
			goto end;
		kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);

		while(1)
		{
			if(cb_status == GIF_STATUS_INEMPTY)
			{
				if(!gif_stop_now)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else
				{
					gif_decode_stop();
					goto end;
				}
			}
			else if (cb_status == GIF_STATUS_COMPLETE)
			{
				if(p->frame_number > cb_fn)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else if(p->frame_number == cb_fn)
				{
					GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					p->frame_number++;
					break;
				}
			}
			else
			{
				gif_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				break;
			}
		}
	}
end:
	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);

}

// file mode, single frame, partial input, resizing
void test_case_3(void)
{
	gif_config_struct *p = &gif_config;
	gif_report_status_enum status;

	sprintf(file_name, "c:\\gif\\1.gif"); // multi frame BD_NC02.gif
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = GIF_DECODE_FILE;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);
	DRM_file_size(p->file_handle, &file_size);
	p->cache_id = gif_get_cache_key_from_file(file_name, file_size);
	p->file_buffer_adrs = in_buffer;
	p->file_buffer_size = 1024;
	p->output_buffer_adrs = (kal_uint8*)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;
	p->stack_adrs = gif_stack;
	p->stack_size = GIF_STACK_SIZE;
	p->tree_adrs = gif_tree;
	p->tree_size = GIF_TREE_SIZE;
	p->LCT_adrs = gif_lct;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH-1;
	p->clip_y2 = LCD_HEIGHT-1;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->pack_enable =  KAL_FALSE;
	// 1:1 ratio (pack mode)
	p->p_resz_w_Q = 0;
	p->p_resz_w_N = 1;
	p->p_resz_w_D = 0;
	p->p_resz_h_Q = 0;
	p->p_resz_h_N = 1;
	p->p_resz_h_D = 0;

	p->clip_enable = KAL_TRUE;
	p->out_format = GIF_OUT_RGB565;
	p->frame_number = 0;
	p->gif_cb = gif_callback;

	while(1)
	{
		kal_uint32 flag;

		status = gif_decode_start(p, &gif_info);
		if(status ==  GIF_INVALID_FORMAT || status == GIF_NO_FRAME)
			goto end;
		kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);

		while(1)
		{
			if(cb_status == GIF_STATUS_INEMPTY)
			{
				if(!gif_stop_now)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else
				{
					gif_decode_stop();
					goto end;
				}
			}
			else if (cb_status == GIF_STATUS_COMPLETE)
			{
				if(p->frame_number > cb_fn)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else if(p->frame_number == cb_fn)
				{
					GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					p->frame_number++;
					break;
				}
			}
			else
			{
				gif_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				break;
			}
		}
	}
end:
	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
}

// file mode, multi frame, partial input, random frame number, in order
// frame number larger than the GIF_CACHE_FRAME_NUM
void test_case_4(void)
{
	gif_config_struct *p = &gif_config;
	gif_report_status_enum status;
	kal_uint32 i;

	sprintf(file_name, "c:\\gif\\atsugari_0205bana.gif"); // multi frame atsugari_0205bana.gif
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = GIF_DECODE_FILE;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);
	DRM_file_size(p->file_handle, &file_size);
	p->cache_id = gif_get_cache_key_from_file(file_name, file_size);
	p->file_buffer_adrs = in_buffer;
	p->file_buffer_size = 1111;
	p->output_buffer_adrs = (kal_uint8*)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;
	p->stack_adrs = gif_stack;
	p->stack_size = GIF_STACK_SIZE;
	p->tree_adrs = gif_tree;
	p->tree_size = GIF_TREE_SIZE;
	p->LCT_adrs = gif_lct;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH-1;
	p->clip_y2 = LCD_HEIGHT-1;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->pack_enable =  KAL_FALSE;
	// 1:1 ratio (pack mode)
	p->p_resz_w_Q = 0;
	p->p_resz_w_N = 1;
	p->p_resz_w_D = 0;
	p->p_resz_h_Q = 0;
	p->p_resz_h_N = 1;
	p->p_resz_h_D = 0;

	p->clip_enable = KAL_TRUE;
	p->out_format = GIF_OUT_RGB565;
	p->gif_cb = gif_callback;

	// in random order
	srand( (unsigned)file_size);
	i=0;
	while(i<200)
	{
		kal_uint32 flag;

		p->frame_number = rand()%24;
		status = gif_decode_start(p, &gif_info);
		i++;
		if(status ==  GIF_INVALID_FORMAT || status == GIF_NO_FRAME)
			goto end;
		kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);

		while(1)
		{
			if(cb_status == GIF_STATUS_INEMPTY)
			{
				if(!gif_stop_now)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else
				{
					gif_decode_stop();
					goto end;
				}
			}
			else if (cb_status == GIF_STATUS_COMPLETE)
			{
				if(p->frame_number > cb_fn)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else if(p->frame_number == cb_fn)
				{
					GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					p->frame_number++;
					break;
				}
			}
			else
			{
				gif_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				break;
			}
		}
	}
end:

	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);

}

// concurrent 4 gif images decoding in order
// 2 in memory 2 in file
void test_case_5(void)
{
	gif_config_struct *p;
	kal_uint32 i,count;
	gif_report_status_enum status;
	kal_bool done[4] = {0};

	// file 1
	p = &gif_cfg[0];
	p->decode_mode = GIF_DECODE_FILE;
	sprintf(f_name[0], "c:\\gif\\BD_OF03.gif"); // multi frame
	p->dest_x = 0;
	p->dest_y = 0;

	// file 2
	p = &gif_cfg[1];
	p->decode_mode = GIF_DECODE_FILE;
	sprintf(f_name[1], "c:\\gif\\ehon01.gif"); // multi frame
	p->dest_x = LCD_WIDTH/2;
	p->dest_y = 0;

	// memory 1
	p = &gif_cfg[2];
	p->decode_mode = GIF_DECODE_MEMORY;
	sprintf(f_name[2], "c:\\gif\\color2full.gif"); // single frame
	p->dest_x = 0;
	p->dest_y = LCD_HEIGHT/2;

	// memory 2
	p = &gif_cfg[3];
	p->decode_mode = GIF_DECODE_MEMORY;
	sprintf(f_name[3], "c:\\gif\\test457.gif"); // multi frame
	p->dest_x = LCD_WIDTH/2;
	p->dest_y = LCD_HEIGHT/2;

	for(i=0;i<GIF_NUM;i++)
	{
		kal_uint32 bytes;

		p = &gif_cfg[i];
		kal_wsprintf(f_name_w[i],(char*)f_name[i]);
		p->file_handle = DRM_open_file(f_name_w[i],FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
		if(p->file_handle < 0 )
			ASSERT(0);
		DRM_file_size(p->file_handle, &fs[i]);
		if(p->decode_mode == GIF_DECODE_MEMORY)
		{
			p->file_buffer_size = sizeof in_buf[i];
			if(fs[i] <= sizeof in_buf[i])
				DRM_read_file(p->file_handle,in_buf[i], fs[i], &bytes);
			else
				ASSERT(0);
		}
		else
		{
			p->file_buffer_size = 1111;
		}
		p->cache_id = gif_get_cache_key_from_file(f_name[i], fs[i]);
		p->file_buffer_adrs = in_buf[i];
		p->output_buffer_adrs = (kal_uint8*)lcd_buffer;
		p->output_buffer_size = sizeof lcd_buffer;
		p->stack_adrs = gif_stack;
		p->stack_size = GIF_STACK_SIZE;
		p->tree_adrs = gif_tree;
		p->tree_size = GIF_TREE_SIZE;
		p->LCT_adrs = gif_lct;

		p->shadow_w = LCD_WIDTH;
		p->shadow_h = LCD_HEIGHT;
		p->clip_x1 = 0;
		p->clip_y1 = 0;
		p->clip_x2 = LCD_WIDTH-1;
		p->clip_y2 = LCD_HEIGHT-1;

		p->expect_w = LCD_WIDTH/2;
		p->expect_h = LCD_HEIGHT/2;

		p->pack_enable =  KAL_FALSE;
		// 1:1 ratio (pack mode)
		p->p_resz_w_Q = 0;
		p->p_resz_w_N = 1;
		p->p_resz_w_D = 0;
		p->p_resz_h_Q = 0;
		p->p_resz_h_N = 1;
		p->p_resz_h_D = 0;

		p->clip_enable = KAL_TRUE;
		p->out_format = GIF_OUT_RGB565;
		p->frame_number = 0;
		p->gif_cb = gif_callback;
	}
	count = 0;
	do{

		kal_uint32 flag;

		for(i=0; i<GIF_NUM; i++)
		{
			p = &gif_cfg[i];
			status = gif_decode_start(p, &gif_info);
			if( status == GIF_NO_FRAME)
			{
				p->frame_number = 0;
				if(done[i] == 0)
				{
					count++;
					done[i] = KAL_TRUE;
				}
				break;
			}
			else if(status == GIF_INVALID_FORMAT)
			{
				goto end;
			}

			kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);

			while(1)
			{
				if(cb_status == GIF_STATUS_INEMPTY)
				{
					if(!gif_stop_now)
					{
						status = gif_decode_resume(p, &gif_info);
						kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
					}
					else
					{
						gif_decode_stop();
						goto end;
					}
				}
				else if (cb_status == GIF_STATUS_COMPLETE)
				{
					if(p->frame_number > cb_fn)
					{
						status = gif_decode_resume(p, &gif_info);
						kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
					}
					else if(p->frame_number == cb_fn)
					{
						GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
						p->frame_number++;
						break;
					}
				}
				else
				{
					gif_decode_stop();
					dbg_print("\n\r decode fail %d !", cb_status);
					break;
				}
			}
		}
		if(count == GIF_NUM)
			break;
	}while(1);

end:

	for(i=0;i<GIF_NUM;i++)
	{
		p = &gif_cfg[i];
		DRM_close_file(p->file_handle);
	}

}
// stress test more than 3000 files (RGB565)
void test_case_6(void)
{
	kal_int32 s, file_count;
	FS_HANDLE handle;
	RTFDOSDirEntry de;
	gif_config_struct *p = &gif_config;
	gif_report_status_enum status;
	static kal_bool is_first = KAL_TRUE;

	file_count = 0;
	if(RTFSetCurrentDir(L"c:\\gif\\") < 0)
		while(1);
	while(1)
	{
		kal_uint32 bytes;

		if(is_first)
		{
			handle = RTFFindFirstEx(L"*.gif", 0, 0, &de, file_name_w, 256);
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
		p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
		if(p->file_handle < 0 )
			ASSERT(0);
		DRM_file_size(p->file_handle, &file_size);
		dbg_print("\r\n[%d] File: %s\t, size: %d\t, fn: ",file_count, file_name, file_size);
		if(file_size > 32*1024)
			p->decode_mode = GIF_DECODE_FILE;
		else
			p->decode_mode = GIF_DECODE_MEMORY;
		if(p->decode_mode == GIF_DECODE_MEMORY)
		{
			p->file_buffer_size = file_size;
			if(DRM_read_file(p->file_handle,in_buffer, file_size, &bytes) < 0)
				while(1);
		}
		else
		{
			p->file_buffer_size = 32*1024;
		}
		p->cache_id = gif_get_cache_key_from_file(file_name, file_size);
		p->file_buffer_adrs = in_buffer;
		p->output_buffer_adrs = (kal_uint8*)lcd_buffer;
		p->output_buffer_size = sizeof lcd_buffer;
		p->stack_adrs = gif_stack;
		p->stack_size = GIF_STACK_SIZE;
		p->tree_adrs = gif_tree;
		p->tree_size = GIF_TREE_SIZE;
		p->LCT_adrs = gif_lct;

		p->shadow_w = LCD_WIDTH;
		p->shadow_h = LCD_HEIGHT;
		p->clip_x1 = 0;
		p->clip_y1 = 0;
		p->clip_x2 = LCD_WIDTH-1;
		p->clip_y2 = LCD_HEIGHT-1;
		p->dest_x = 0;
		p->dest_y = 0;

		p->expect_w = LCD_WIDTH;
		p->expect_h = LCD_HEIGHT;

		p->pack_enable =  KAL_FALSE;
		// 1:1 ratio (pack mode)
		p->p_resz_w_Q = 0;
		p->p_resz_w_N = 1;
		p->p_resz_w_D = 0;
		p->p_resz_h_Q = 0;
		p->p_resz_h_N = 1;
		p->p_resz_h_D = 0;

		p->clip_enable = KAL_TRUE;
		p->out_format = GIF_OUT_RGB565;
		p->gif_cb = gif_callback;
		p->frame_number = 0;
	while(1)
	{
		kal_uint32 flag;

		status = gif_decode_start(p, &gif_info);
		if(status ==  GIF_INVALID_FORMAT || status == GIF_NO_FRAME)
			goto end;
		kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);

		while(1)
		{
			if(cb_status == GIF_STATUS_INEMPTY)
			{
				if(!gif_stop_now)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else
				{
					gif_decode_stop();
					goto end;
				}
			}
			else if (cb_status == GIF_STATUS_COMPLETE)
			{
				if(p->frame_number > cb_fn)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else if(p->frame_number == cb_fn)
				{
					GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					p->frame_number++;
					dbg_print("%d ", p->frame_number);
					break;
				}
			}
			else
			{
				gif_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				goto end;
			}
		}
	}

end:

	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	// kal_sleep_task(1);
	// GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
	}
	RTFFindClose(handle);
	is_first = KAL_TRUE;
}

// index mode
void test_case_7(void)
{
	gif_config_struct *p = &gif_config;
	gif_report_status_enum status;

	sprintf(file_name, "c:\\gif\\BD_NC02.gif"); // multi frame
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = GIF_DECODE_FILE;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);
	DRM_file_size(p->file_handle, &file_size);
	p->cache_id = gif_get_cache_key_from_file(file_name, file_size);
	p->file_buffer_adrs = in_buffer;
	p->file_buffer_size = 1024;
	p->output_buffer_adrs = (kal_uint8*)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;
	p->stack_adrs = gif_stack;
	p->stack_size = GIF_STACK_SIZE;
	p->tree_adrs = gif_tree;
	p->tree_size = GIF_TREE_SIZE;
	p->LCT_adrs = gif_lct;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH-1;
	p->clip_y2 = LCD_HEIGHT-1;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->pack_enable =  KAL_FALSE;
	// 1:1 ratio (pack mode)
	p->p_resz_w_Q = 0;
	p->p_resz_w_N = 1;
	p->p_resz_w_D = 0;
	p->p_resz_h_Q = 0;
	p->p_resz_h_N = 1;
	p->p_resz_h_D = 0;

	p->clip_enable = KAL_FALSE;
	p->out_format = GIF_OUT_INDEX;
	p->frame_number = 0;

	while(1)
	{
		kal_uint32 i;
		kal_uint32 *ct, WxH, w, h;
		kal_uint8 *out;
		kal_uint32 flag;

		status = gif_decode_start(p, &gif_info);
		if(status ==  GIF_INVALID_FORMAT || status == GIF_NO_FRAME)
			goto end;
		WxH = gif_info.w*gif_info.h;
		// refer to the color table
		out = (kal_uint8*)lcd_buffer;
		if(gif_info.LCT_flag)
			ct = p->LCT_adrs;
		else
			ct = gif_cache[gif_cache_index].GCT;
		kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
		while(1)
		{
			if(cb_status == GIF_STATUS_INEMPTY)
			{
				if(!gif_stop_now)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else
				{
					gif_decode_stop();
					goto end;
				}
			}
			else if (cb_status == GIF_STATUS_COMPLETE)
			{
				if(p->frame_number > cb_fn)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else if(p->frame_number == cb_fn)
				{
					for(i=0;i<WxH;i++)
					{
						lcd_buffer_i[i] = ((ct[out[i]]&0x00f80000)>>8)|((ct[out[i]]&0x0000fc00)>>5)|
							((ct[out[i]]&0x000000f8)>>3);
					}
					memset(lcd_buffer, 0 ,WxH);
					w = (gif_info.w>>gif_dcb.resz_w) + (gif_info.w&1);
					h = (gif_info.h>>gif_dcb.resz_h) + (gif_info.h&1);
					GIF_Display(lcd_buffer_i, w, h);
					p->frame_number++;
					break;
				}
			}
			else
			{
				gif_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				break;
			}
		}
	}

end:
	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
}

// unpack pack mode to the index mode
void GIF_UnPack(kal_uint8 *src, kal_uint8 *dst, kal_uint32 bit
	,kal_uint32 pixels)
{
	kal_uint32 i, j, index,pixel_per_byte, bytes;
	kal_uint8 *in,tmp;
	kal_uint8 *out;
	kal_uint8 pack_mask[] = {1,3,15};

	if(bit == 8)
	{
		memcpy(dst, src, pixels );
		return;
	}

	ASSERT(bit == 1 || bit == 2 || bit == 4 || bit == 8);
	in = src;
	out = dst;
	pixel_per_byte = 8/bit;
	bytes = pixels/pixel_per_byte + ((pixels%pixel_per_byte)!= 0);

	if(1)
	{
		for(i=0;i<bytes;i++)
		{
			tmp = in[i];
			for(j=0;j<pixel_per_byte;j++)
			{
				index = i*pixel_per_byte+j;
				if(index < pixels)
					out[index] = (tmp&pack_mask[bit>>1]);
				else
					break;
				tmp >>= bit;
			}
		}
	}
}
// pack mode
void test_case_8(void)
{
	gif_config_struct *p = &gif_config;
	gif_report_status_enum status;

	// 220_200_4.gif (Q,N,D)
	sprintf(file_name, "c:\\gif\\test113.gif"); // multi frame
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = GIF_DECODE_FILE;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);
	DRM_file_size(p->file_handle, &file_size);
	p->cache_id = gif_get_cache_key_from_file(file_name, file_size);
	p->file_buffer_adrs = in_buffer;
	p->file_buffer_size = 1024;
	p->output_buffer_adrs = (kal_uint8*)lcd_buffer_i;
	p->output_buffer_size = sizeof lcd_buffer_i;
	p->stack_adrs = gif_stack;
	p->stack_size = GIF_STACK_SIZE;
	p->tree_adrs = gif_tree;
	p->tree_size = GIF_TREE_SIZE;
	p->LCT_adrs = gif_lct;

	p->clip_enable = KAL_FALSE;	///@@@@@@@////
	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH-1;
	p->clip_y2 = LCD_HEIGHT-1;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->pack_enable =  KAL_TRUE;  ///@@@@@@@////
	// 1:1 ratio (pack mode)
	p->p_resz_w_Q = 0;
	p->p_resz_w_N = 1;
	p->p_resz_w_D = 0;
	p->p_resz_h_Q = 0;
	p->p_resz_h_N = 1;
	p->p_resz_h_D = 0;

	p->out_format = GIF_OUT_INDEX; ///@@@@@@@////
	p->frame_number = 0;
	p->gif_cb = gif_callback;

	while(1)
	{
		kal_uint32 i;
		kal_uint32 *ct, WxH, w, h;
		kal_uint8 *src, *dst;
		kal_uint32 flag;

		status = gif_decode_start(p, &gif_info);
		if(status ==  GIF_INVALID_FORMAT || status == GIF_NO_FRAME)
			goto end;
		kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
		while(1)
		{
			if(cb_status == GIF_STATUS_INEMPTY)
			{
				if(!gif_stop_now)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else
				{
					gif_decode_stop();
					goto end;
				}
			}
			else if (cb_status == GIF_STATUS_COMPLETE)
			{
				if(p->frame_number > cb_fn)
				{
					status = gif_decode_resume(p, &gif_info);
					kal_retrieve_eg_events(GIF_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				}
				else if(p->frame_number == cb_fn)
				{
					WxH = gif_info.w*gif_info.h;
					// refer to the color table
					src = (kal_uint8*)lcd_buffer_i;
					dst = (kal_uint8*)lcd_buffer;
					GIF_UnPack(src , dst, gif_info.bpp,WxH);
					if(gif_info.LCT_flag)
						ct = p->LCT_adrs;
					else
						ct = gif_cache[gif_cache_index].GCT;
					for(i=0;i<WxH;i++)
					{
						lcd_buffer_i[i] = ((ct[dst[i]]&0x00f80000)>>8)|((ct[dst[i]]&0x0000fc00)>>5)|
							((ct[dst[i]]&0x000000f8)>>3);
					}
					memset(lcd_buffer, 0 ,WxH);
					if(gif_dcb.resz_w)
						w = (gif_info.w>>gif_dcb.resz_w) + (gif_info.w&1);
					else
						w = gif_info.w;
					if(gif_dcb.resz_h)
						h = (gif_info.h>>gif_dcb.resz_h) + (gif_info.h&1);
					else
						h = gif_info.h;

					GIF_Display(lcd_buffer_i, w, h);
					p->frame_number++;
					break;
				}
			}
			else
			{
				gif_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				break;
			}
		}
	}

end:

	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	GIF_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
}

/*
void test_case_8(void)
{
}
void test_case_8(void)
{
}
*/
void gif_unit_test_main(void)
{
	IRQMaskAll();
	IRQUnmask(IRQ_CTIRQ1_CODE);
	IRQUnmask(IRQ_GPT_CODE);
	IRQUnmask(IRQ_LCD_CODE);
	IRQUnmask(IRQ_MSDC_CODE);
	IRQUnmask(IRQ_DMA_CODE);
	IRQUnmask(IRQ_UART1_CODE);

	GIF_Events = kal_create_event_group("GIF Events");
	LCD_Init();
	SD_Initialize();
	gif_init();
	//DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
	while(1)
	{

		test_case_1();
 		test_case_2();
 		test_case_3();
 		test_case_4();
 		test_case_5();
  		test_case_7();
		test_case_8();
 		test_case_6();

/*
		test_case_8();
 		test_case_7();
 		test_case_1();
 		test_case_2();
 		test_case_3();
 		test_case_4();
 		test_case_5();
		// stress test
 		test_case_6();
*/
	}
}

#endif	// end of the test

#endif // USE_HW_GIF_DECODER_V2
