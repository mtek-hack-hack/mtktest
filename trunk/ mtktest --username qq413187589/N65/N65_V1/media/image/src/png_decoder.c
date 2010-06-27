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
 *	 png_decoder.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Driver of the png decoder .
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
#include	"bytestream_hw.h"
#include "png_decoder.h"
#include "2d_engine.h"
#include "visualhisr.h"

// #define USE_HW_PNG_DECODER
#if defined(USE_HW_PNG_DECODER_V1)
static png_dcb_struct png_dcb;
static png_state_enum png_state;
static VISUAL_HISR_ID png_hisr;
static kal_uint8 png_gpt_handle;

// constant
#define PNG_IDAT_BUF_LEN		8*1024

static kal_uint8 png_signature[8] = {137, 80, 78, 71, 13, 10, 26, 10};
static const kal_uint8 png_IHDR[5] = { 73,  72,  68,  82, '\0'};
static const kal_uint8 png_IDAT[5] = { 73,  68,  65,  84, '\0'};
static const kal_uint8 png_IEND[5] = { 73,  69,  78,  68, '\0'};
static const kal_uint8 png_PLTE[5] = { 80,  76,  84,  69, '\0'};
static const kal_uint8 png_tRNS[5] = {116,  82,  78,  83, '\0'};
static const kal_uint8 png_bKGD[5] = { 98,  75,  71,  68, '\0'};
#define DONT_CARE	1
static const kal_uint8 png_type_channel[] = {1,DONT_CARE,3,1,2,DONT_CARE,4};
static kal_uint32 png_idat_buf[PNG_IDAT_BUF_LEN/4+1];
static kal_uint32 idat_buf_len = PNG_IDAT_BUF_LEN;

/*************************************************************************
* FUNCTION
*  png_assemble_idat
*
* DESCRIPTION
*	1. assemle the IDAT chunk into png_idat_buf
*	2. check if the last IDAT is reached
*  3. there are two special case: a. only one data chunk and less than 4 bytes
*		b. the last remaining bytes are less than 4 bytes
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	png_dcb.my_idat_remain
*
*************************************************************************/
static void png_assemble_idat(void)
{
	kal_uint32 remain,len,size;
	kal_uint8 *ptr = (kal_uint8*)png_idat_buf;
	kal_uint8 buf[4];

	remain = png_dcb.my_idat_remain ;
	size = idat_buf_len;
	while(1)
	{
		if(remain)
		{
			len = remain;
			goto no_header;
		}
		else
		{
			// encounter a new IDAT chunk
			len = PNG_GET_U32();
			if(len > 0x1000000)
				PNG_RAISE(1);
			PNG_GET_ARRAY(buf, 4);
		}
		if(!kal_mem_cmp(buf,png_IDAT,4) && len!=0)
		{
no_header:
			if(size >= len)
			{
				// read entire IDAT chunk into buffer
				PNG_GET_ARRAY(ptr, len);
				PNG_FLUSH(4);// crc
				size -= len;
				ptr += len;
				remain = 0;
			}
			else if(size > 0)
			{
				// fill the idat buffer and record the remaining IDAT bytes
				PNG_GET_ARRAY(ptr, size);
				remain  = len -size;
				png_dcb.my_idat_remain = remain;
				break;
			}
			else if (size == 0)
			{
				png_dcb.my_idat_remain = len;
				break;
			}
		}
		else
		{
			// all IDAT is finished
			png_dcb.z_count = ptr - (kal_uint8*)png_idat_buf;
			png_dcb.is_IEND = KAL_TRUE;
			break;
		}
	}
}
/*************************************************************************
* FUNCTION
*  png_remove_srckey_color
*
* DESCRIPTION
*	modify the same color with the transparent index
*
* PARAMETERS
*	index: transparent index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*static void png_remove_srckey_color( kal_uint32 index)
{
	kal_uint32 i,count;
	kal_uint32 src_key;
	kal_uint32 *ct = png_dcb.cfg->color_table;

	src_key = ct[index];
	count = png_dcb.info.num_plte;
	for(i=0;i<=count;i++)
	{
		if(src_key == ct[i])
		{
			// modify the blue
			ct[i] ^= 1;
		}
	}
	ct[index]= src_key;
}*/
/*************************************************************************
* FUNCTION
*  png_timeout_hander
*
* DESCRIPTION
*	call back function of the GPT timer ot handle the decoding timeout.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_timeout_hander(void* p)
{
	png_dcb.is_timeout = KAL_TRUE;
	kal_print("hw png decode timeout");
	DRV_WriteReg32(PNG_IRQ_EN, 0);
	PNG_RESET();
	png_state = PNG_STATE_READY;
	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_PNG,PDN_PNG);
	if(png_dcb.cb  != NULL)
		png_dcb.cb(PNG_DECODE_TIMEOUT);
}
/*************************************************************************
* FUNCTION
*  png_resz_ratio
*
* DESCRIPTION
*	calculate the resizing ratio according to the real size and expected one
*
* PARAMETERS
*	real: actual image width or height
*	expect: expected image width or height
*
* RETURNS
* 	The resizing ratio
*
* GLOBALS AFFECTED
*
*************************************************************************/
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
#endif
/*************************************************************************
* FUNCTION
*  png_g2d_bitblt
*
* DESCRIPTION
*	bitblit the png_work_buffer onto the destination LCD frame buffer.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
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
#endif

/*************************************************************************
* FUNCTION
*  png_get_gray_scale
*
* DESCRIPTION
*	1. Transform the gray value from low bit depth into 8 bit depth
*	2. Transfrom the 16-bepth gray value into 8-bit depth.
* PARAMETERS
*	bit_depth: original bit depth of the gray value
*	gray: gray value to be transformed.
*
* RETURNS
*   The transformed 8-bit gray value.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 png_get_gray_scale(kal_uint32 bit_depth, kal_uint32 gray)
{
	kal_uint32 loop,value;

	ASSERT(gray <= ((1<<bit_depth)-1));
	if(gray == ((1<<bit_depth)-1))
		return 0xff;
	if(gray == 0)
		return gray;

	if(bit_depth < 8)
	{
		value = gray;
		loop = (8/bit_depth) -1 ;
		while(loop--)
		{
			value = (value << bit_depth);
			value |= gray;
		}
		return value;
	}
	else if(bit_depth == 8)
	{
		return gray;
	}
	else
	{
		return gray >> 8;
	}
}
/*************************************************************************
* FUNCTION
*  png_decode_hw
*
* DESCRIPTION
*	1. start to decode the specific PNG image (first time of a image)
*	2. input all of the registers of png decoder
*	3. trigger the decoding process
*
* PARAMETERS
*	z_len: length of IDAT count
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
// len: length of IDAT count
static void png_decode_hw(kal_uint32 z_len)
{
	register png_config_struct *cfg = png_dcb.cfg;
	png_inform_struct *info = &png_dcb.info;
	kal_uint32 reg,out_format;
	kal_uint8 resz_w=0, resz_h=0;

	DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_PNG,PDN_PNG);
	DRV_WriteReg32(PNG_IRQ_EN, 0);
	PNG_RESET();

	png_dcb.my_idat_remain = z_len;
	png_assemble_idat();
	DRV_WriteReg32(PNG_IN_START, png_idat_buf);
	DRV_WriteReg32(PNG_IN_COUNT, idat_buf_len+4);
	if(png_dcb.z_count >= 4)
	{
		DRV_WriteReg32(PNG_IDAT_COUNT, png_dcb.z_count);
	}
	else if(png_dcb.z_count > 0)
	{
		kal_uint32 reg,i;
		kal_uint8 *ptr = (kal_uint8*)png_idat_buf;

		for(reg=0,i=0; i<png_dcb.z_count; i++)
		{
			 reg |= (ptr[i] << (8*i));
		}
		DRV_WriteReg32(PNG_IDAT_BUFFER, reg);
		DRV_WriteReg32(PNG_IDAT_COUNT, png_dcb.z_count);
	}
	else
		DRV_WriteReg32(PNG_IDAT_COUNT, idat_buf_len);

	// configure the buffers
	#if defined(PNG_NEW_BUFFER_INTERFACE)
	{
		register kal_uint32 buf_index;

		buf_index = (kal_uint32)cfg->color_table_t;
		buf_index += CT_LEN*4;
		DRV_WriteReg32(PNG_HCLEN_START, buf_index);
		buf_index += HCLEN_LEN;
		DRV_WriteReg32(PNG_HLEN_START, buf_index);
		buf_index += HLEN_LEN;
		DRV_WriteReg32(PNG_HLIT_START, buf_index);
		buf_index += HLIT_LEN;
		DRV_WriteReg32(PNG_HDIST_START, buf_index);
		buf_index += HDIST_LEN;
		DRV_WriteReg32(PNG_BUFF0_START, buf_index);
		buf_index += BUFF0_LEN;
		DRV_WriteReg32(PNG_BUFF1_START, buf_index);
		buf_index += BUFF1_LEN;
		DRV_WriteReg32(PNG_LZ77_START, buf_index);
	}
	#else
	DRV_WriteReg32(PNG_HCLEN_START, cfg->hclen);
	DRV_WriteReg32(PNG_HLEN_START, cfg->hlen);
	DRV_WriteReg32(PNG_HLIT_START, cfg->hlit);
	DRV_WriteReg32(PNG_HDIST_START, cfg->hdist);
	DRV_WriteReg32(PNG_BUFF0_START, cfg->buff0);
	DRV_WriteReg32(PNG_BUFF1_START, cfg->buff1);
	DRV_WriteReg32(PNG_LZ77_START, cfg->LZ77);
	#endif
	DRV_WriteReg32(PNG_CT_START, cfg->color_table);
	DRV_WriteReg32(PNG_TRAN_TABLE, cfg->color_table_t);

	reg = (info->bit_depth << 3)|(info->color_type);
	DRV_WriteReg8(PNG_COLOR_TYPE, reg);
	DRV_WriteReg8(PNG_INTERLACE_EN, info->interlaced);
	DRV_WriteReg32(PNG_IMG_WH, (info->img_w << 16) | info->img_h);

	// partial input have to be enabled always
	out_format = cfg->out_format|PNG_OUT_FORMAT_PATRIAL;
	// use software to remove MMI's source key
	if((info->color_type == COLOR_TYPE_RGB || info->color_type == COLOR_TYPE_RGB_A)
		&&(cfg->out_format == RGB565|| cfg->out_format == RGB888))
		info->use_work_buf = KAL_TRUE;

	// calculate resz_w , resz_h
	{
		kal_uint32 bytes_per_pixel;

		switch(cfg->out_format)
		{
		case RGB565: bytes_per_pixel=2;break;
		case RGB888: bytes_per_pixel=3;break;
		case ARGB8888: bytes_per_pixel=4;break;
		default: bytes_per_pixel=1;break;
		}
		if(cfg->expect_w==0) cfg->expect_w = info->img_w;
		if(cfg->expect_h==0) cfg->expect_h = info->img_h;

		cfg->cal_work_buffer_info_func(
						&resz_w,
						&info->wb_dest_x,&info->wb_dest_y,
						&info->wb_width,&info->wb_height,
						cfg->work_buffer_size / bytes_per_pixel,
						info->img_w,info->img_h,
						cfg->dest_x,cfg->dest_y,
						cfg->expect_w,cfg->expect_h,
						cfg->clip_x1,cfg->clip_y1,cfg->clip_x2,cfg->clip_y2);
		resz_h = resz_w;
	}

	info->use_work_buf = KAL_FALSE;
	info->resz_w = resz_w;
	info->resz_h = resz_h;

	// configure the resizing
	if((info->img_w>>resz_w) != cfg->expect_w
	||(info->img_h>>resz_h)!= cfg->expect_h)
	{
		// use 2D engine to perform transparent
		info->use_work_buf = KAL_TRUE;
	}

	if(resz_w || resz_h)
	{	// use software resizer to perform fine resizing
		png_dcb.resz_en = KAL_TRUE;
		png_dcb.resz_w = resz_w;
		png_dcb.resz_h = resz_h;
		reg = (resz_w << 8)|(resz_h << 4)|1;
		DRV_WriteReg32(PNG_RESIZE_CTRL, reg);
	}
	else
	{
		DRV_WriteReg32(PNG_RESIZE_CTRL, 0);
	}

	// transparent control
	if(png_dcb.flags & PNG_HAVE_tRNS)
	{
		reg = PNG_TRAN_CON_TRAN_ENABLE;
		if(cfg->out_format == ARGB4444 || cfg->out_format == ARGB8888)
		{
			reg |= PNG_TRAN_CON_ARGB;
		}
		if(info->color_type == COLOR_TYPE_INDEX)
		{
			if(info->num_trans == 1)
			{
				DRV_WriteReg32(PNG_TRAN_KEY1, (info->trans.index<<16));
			}
			else
			{
				//DRV_WriteReg32(PNG_TRAN_TABLE, cfg->color_table_t);
				reg |= PNG_TRAN_CON_TRAN_TABLE;
			}
		}
		else if(info->color_type == COLOR_TYPE_GRAY)
		{
			DRV_WriteReg32(PNG_TRAN_KEY1, (info->trans.gray << 16));
		}
		else if(info->color_type == COLOR_TYPE_RGB)
		{
			DRV_WriteReg32(PNG_TRAN_KEY1, (info->trans.color.r));
			DRV_WriteReg32(PNG_TRAN_KEY2, (info->trans.color.g << 16)|
				(info->trans.color.g));
		}
		else
			PNG_RAISE(1);

		// background control
		if(png_dcb.flags & PNG_HAVE_bKGD)
		{
			if(info->color_type == COLOR_TYPE_INDEX)
			{
				DRV_WriteReg32(PNG_BACK_GROUND, info->bKGD.index << 24);
			}
			else if(info->color_type == COLOR_TYPE_GRAY)
			{
				kal_uint32 gray;

				gray = info->bKGD.gray;
				if(info->bit_depth > 8)
					gray = gray >> (8);
				DRV_WriteReg32(PNG_BACK_GROUND, gray << 24);
			}
			else if(info->color_type == COLOR_TYPE_RGB)
			{
				kal_uint32 r,g,b;
				r = info->bKGD.color.r;
				g = info->bKGD.color.g;
				b = info->bKGD.color.b;
				if(info->bit_depth > 8)
				{
					r = r >> (info->bit_depth -8);
					g = g >> (info->bit_depth -8);
					b = b >> (info->bit_depth -8);
				}
				DRV_WriteReg32(PNG_BACK_GROUND, ((r<<16)|(g<<8)|b));
			}
		}
		else
		{	// no bKGD
			if((info->color_type == COLOR_TYPE_GRAY || info->color_type ==
				COLOR_TYPE_INDEX) && info->num_trans == 1)
			{
				info->use_work_buf = KAL_TRUE;
				reg = 0;
			}
			else if(info->use_work_buf)
			{
				// without bKGD and output to working buffer
				info->use_work_buf = KAL_TRUE;
				reg = 0;
			}
			else
			{
				reg |= PNG_TRAN_CON_TRAN_OUT;
			}
		}
		DRV_WriteReg32(PNG_TRAN_CON, reg);
	}
	else
	{
		DRV_WriteReg32(PNG_TRAN_CON, 0);
	}

	// configure the clipping
	if(cfg->clip_en)
	{
		kal_int32 x, y;

		out_format |= PNG_OUT_FORMAT_CLIP_EN;
		if(info->use_work_buf)
		{
			DRV_WriteReg32(PNG_LCD_WH, ((info->wb_width<< 16)|info->wb_height));
			DRV_WriteReg32(PNG_CLIP_XY, ((0 << 16)|0));
			DRV_WriteReg32(PNG_CLIP_WH, ((info->wb_width)<< 16)|
				(info->wb_height));
			x = info->wb_dest_x;
			y = info->wb_dest_y;
		}
		else
		{
			DRV_WriteReg32(PNG_LCD_WH, ((cfg->shadow_w << 16)|cfg->shadow_h));
			DRV_WriteReg32(PNG_CLIP_XY, ((cfg->clip_x1 << 16)|cfg->clip_y1));
			DRV_WriteReg32(PNG_CLIP_WH, ((cfg->clip_x2- cfg->clip_x1+ 1)<< 16)|
				(cfg->clip_y2- cfg->clip_y1+ 1));
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
		DRV_WriteReg32(PNG_IMG_XY, ((x<< 16)|(y & 0xffff)));
	}
	else
	{
		DRV_WriteReg32(PNG_IMG_XY, 0);
	}
	DRV_WriteReg8(PNG_OUT_FROMAT, out_format);
	DRV_WriteReg8(PNG_IRQ_EN, PNG_IRQ_EN_ALL);

	if(info->use_work_buf)
	{
		kal_uint8 r,g,b,bit_depth;
		kal_uint32 *ct;
		kal_uint16 gray;
		kal_uint32 color, src_key=0,count,i;

		DRV_WriteReg32(PNG_OUT_START, cfg->work_buffer_adrs);
		DRV_WriteReg32(PNG_OUT_END, cfg->work_buffer_adrs+cfg->work_buffer_size-2);
		if(info->color_type == COLOR_TYPE_GRAY)
		{
			gray = info->trans.gray;
			bit_depth = info->bit_depth;
			gray = png_get_gray_scale(bit_depth, gray);
			r = g = b = gray;
			if(cfg->out_format == RGB888)
				src_key = (r<<16)|(g<<8)|b;
			else
				src_key = ((r>>3)<<11)|((g>>2)<<5)|(b>>3);

		}
		else if(info->color_type == COLOR_TYPE_INDEX)
		{
			ct = (kal_uint32*)cfg->color_table;
			color = ct[info->trans.index];
			b = (color)&0xff;
			g = (color>>8)&0xff;
			r = (color>>16)&0xff;
			if(cfg->out_format == RGB888)
				src_key = (r<<16)|(g<<8)|b;
			else
				src_key = ((r>>3)<<11)|((g>>2)<<5)|(b>>3);
			count = png_dcb.info.num_plte;
			// remove the color of differnet trans.index but the same with transparent color
			for(i=0;i<=count;i++)
			{
				if(cfg->out_format == RGB888)
				{
					if(src_key == ct[i])
					{
						ct[i] ^= (1<<17); // xor R
					}
				}
				else if(cfg->out_format == RGB565)
				{
					kal_uint32 r1,b1,g1;
					b1 = (ct[i])&0xff;
					g1 = (ct[i]>>8)&0xff;
					r1 = (ct[i]>>16)&0xff;
					if(((r1>>3)<<11)|((g1>>2)<<5)|(b1>>3) == src_key)
					{
						ct[i] ^= (1<<20);	// xor R
					}
				}
			}
			ct[info->trans.index] = color;
			//png_remove_srckey_color(info->trans.index);
		}
		// src_key for 2d engine to perform bitblit
		png_dcb.info.src_key = src_key;
		// not decode until the caller give the working buffer
	}
	else
	{
		DRV_WriteReg32(PNG_OUT_START, cfg->output_buffer_adrs);
		DRV_WriteReg32(PNG_OUT_END, cfg->output_buffer_adrs+cfg->output_buffer_size-2);
	}
		PNG_DECODE_RUN();

}
/*************************************************************************
* FUNCTION
*  png_crc_reset
*
* DESCRIPTION
*	reset the crc value
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_crc_reset(void)
{
	png_dcb.crc = 0xffffffffL;
}
/*************************************************************************
* FUNCTION
*  png_crc_finish
*
* DESCRIPTION
*	check the crc value is correct or not
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE:	the crc value is correct
*	KAL_FALSE:	the crc value is wrong
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool png_crc_finish(void)
{
	kal_uint32 crc;

	crc = PNG_GET_U32();
	if((crc ^ 0xffffffff) == png_dcb.crc)
		return KAL_TRUE;

	return KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*  png_crc_read
*
* DESCRIPTION
*	1. read the data into buffer
*	2. calculate the crc value
*
* PARAMETERS
*	buf:	buffer to contain the read data
*	len:	number to data to be read
*
* RETURNS
*
* GLOBALS AFFECTED
*	png_dcb.crc
*
*************************************************************************/
static void png_crc_read(void *buf,kal_uint32 len)
{
	extern kal_uint32 png_update_crc(kal_uint32 crc, kal_uint8 *buf,
                         kal_uint32 len);

	PNG_GET_ARRAY(buf,len);
	png_dcb.crc = png_update_crc(png_dcb.crc, (kal_uint8*)buf, len);
}
/*************************************************************************
* FUNCTION
*  png_get_uint_32
*
* DESCRIPTION
*	 Grab an unsigned 32-bit integer from a buffer in big-endian format
*
* PARAMETERS
*	buf: buffer containing data to be translated
*
* RETURNS
*	unsigned 32-bit integer
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 png_get_uint_32(kal_uint8* buf)
{
   kal_uint32 i = ((kal_uint32)(*buf) << 24) +
      ((kal_uint32)(*(buf + 1)) << 16) +
      ((kal_uint32)(*(buf + 2)) << 8) +
      (kal_uint32)(*(buf + 3));

   return (i);
}
/*************************************************************************
* FUNCTION
*  png_get_uint_16
*
* DESCRIPTION
*	Grab an unsigned 16-bit integer from a buffer in big-endian format.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint16 png_get_uint_16(kal_uint8* buf)
{
   kal_uint16 i = (kal_uint16)(((kal_uint16)(*buf) << 8) +
      (kal_uint16)(*(buf + 1)));

   return (i);
}
/*************************************************************************
* FUNCTION
*  png_IHDR_Handler
*
* DESCRIPTION
*	1. parse the IHDR chunk
*	2. check if the line buffer is large enough
*
* PARAMETERS
*	len: length of the IHDR
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_IHDR_Handler(kal_uint32 len)
{
	kal_uint8 buf[13];
	png_inform_struct *info = &png_dcb.info;
	kal_uint32 size,byte;

	if(png_dcb.flags & PNG_HAVE_IHDR)
	{
		PNG_RAISE(1);
	}
	else
		png_dcb.flags |= PNG_HAVE_IHDR;
	if(len != 13)
	{
		PNG_RAISE(1);
	}
	png_crc_read(buf,13);
	if(!png_crc_finish())
	{
		PNG_RAISE(1);
	}
	info->img_w = png_get_uint_32(buf);
	info->img_h = png_get_uint_32(buf+4);
	info->bit_depth = buf[8];
	info->color_type = buf[9];
	info->interlaced = buf[12];
	byte = (info->bit_depth > 8)?(2):(1);
	size = png_type_channel[info->color_type]*byte*info->img_w;
	if(size > BUFF0_LEN)
		PNG_RAISE(1);

}
/*************************************************************************
* FUNCTION
*  png_PLTE_Handler
*
* DESCRIPTION
*	parse the PLTE chunk
*
* PARAMETERS
*	len: length of the PLTE
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_PLTE_Handler(kal_uint32 len)
{
	kal_uint32 *ct = png_dcb.cfg->color_table;
	png_inform_struct *info = &png_dcb.info;
	kal_uint32 count = (1 << info->bit_depth),i;

	if(!(png_dcb.flags & PNG_HAVE_IHDR) ||
		(png_dcb.flags & PNG_HAVE_PLTE)||
		(png_dcb.flags & PNG_HAVE_IDAT))
	{
		PNG_RAISE(1);
	}
	else
		png_dcb.flags |= PNG_HAVE_PLTE;
	if(len > 3*count || (len%3))
	{
		PNG_RAISE(1);
	}
	count = len/3;
	info->num_plte = count-1;
	for(i=0;i<count;i++)
	{
		kal_uint8 buf[3];
		kal_uint32 c;

		png_crc_read(buf,3);
		c = (buf[0]<<16)|(buf[1]<<8)|(buf[2]);

		// replace MMI's source key color with XOR 1
		if(png_dcb.cfg->out_format == RGB565)
		{
			kal_uint32 x;

			x = ((buf[0]>>3)<<11)|((buf[1]>>2)<<5)|(buf[2]>>3);
			if(x == png_dcb.cfg->src_key)
			{
				//png_dcb.src_hit = KAL_TRUE;
				c ^= 0x8;
			}
		}
		else if(png_dcb.cfg->out_format == RGB888)
		{
			if(c == png_dcb.cfg->src_key)
			{
				//png_dcb.src_hit = KAL_TRUE;
				c ^= 1;
			}
		}

		ct[i] = c;
	}
	if(!png_crc_finish())
	{
		PNG_RAISE(1);
	}
}
/*************************************************************************
* FUNCTION
*  png_tRNS_Handler
*
* DESCRIPTION
*	parse the tRNS chunk
*
* PARAMETERS
*	len: length of the tRNS chunk
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_tRNS_Handler(kal_uint32 len)
{
	png_inform_struct *info = &png_dcb.info;
	kal_uint32 count = (1 << info->bit_depth);
	kal_uint8 buf[6];

	if(!(png_dcb.flags & PNG_HAVE_IHDR) ||
		(png_dcb.flags & PNG_HAVE_tRNS)||
		(png_dcb.flags & PNG_HAVE_IDAT))
	{
		PNG_RAISE(1);
	}
	else
		png_dcb.flags |= PNG_HAVE_tRNS;

	if(info->color_type == COLOR_TYPE_INDEX)
	{
		if(len > count)
		{
			PNG_RAISE(1);
		}
		info->num_trans = len;
		if(len ==1)
		{
			 png_crc_read(&info->trans.index,1);
		}
		else
		{
			kal_uint8 *ptr = (kal_uint8*)png_dcb.cfg->color_table_t;
			png_crc_read(ptr,len);
		}
		if(!png_crc_finish())
		{
			PNG_RAISE(1);
		}
	}
	else if(info->color_type == COLOR_TYPE_GRAY)
	{
		if(len != 2)
		{
			PNG_RAISE(0);
		}
		png_crc_read(buf,2);
		info->trans.gray = png_get_uint_16(buf);
		if(!png_crc_finish())
		{
			PNG_RAISE(1);
		}
		info->num_trans = 1;
	}
	else if(info->color_type == COLOR_TYPE_RGB)
	{
		if(len != 6)
		{
			PNG_RAISE(0);
		}
		png_crc_read(buf,6);
		if(!png_crc_finish())
		{
			PNG_RAISE(1);
		}
		info->num_trans = 1;
		info->trans.color.r = png_get_uint_16(buf);
		info->trans.color.g = png_get_uint_16(buf+2);
		info->trans.color.b = png_get_uint_16(buf+4);
	}
	else
	{
		PNG_RAISE(1);
	}

}
/*************************************************************************
* FUNCTION
*  png_bKGD_Handler
*
* DESCRIPTION
*	parse the bKGD chunk
*
* PARAMETERS
*	len: length of the bKGD chunk
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_bKGD_Handler(kal_uint32 len)
{
	png_inform_struct *info = &png_dcb.info;

	if(!(png_dcb.flags & PNG_HAVE_IHDR) ||
		(png_dcb.flags & PNG_HAVE_bKGD)||
		(png_dcb.flags & PNG_HAVE_IDAT))
	{
		PNG_RAISE(1);
	}
	else
		png_dcb.flags |= PNG_HAVE_bKGD;

	if(info->color_type == COLOR_TYPE_INDEX)
	{
		if(len != 1)
			PNG_RAISE(1);
		png_crc_read(&info->bKGD.index,1);
	}
	else if(info->color_type == COLOR_TYPE_GRAY || info->color_type == COLOR_TYPE_GRAY_A)
	{
		if(len != 2)
			PNG_RAISE(1);
		png_crc_read(&info->bKGD.gray,2);
	}
	else if(info->color_type == COLOR_TYPE_RGB || info->color_type == COLOR_TYPE_RGB_A)
	{
		kal_uint8 buf[6];
		if(len != 6)
			PNG_RAISE(1);
		png_crc_read(buf,6);
		info->bKGD.color.r = png_get_uint_16(buf);
		info->bKGD.color.g = png_get_uint_16(buf+2);
		info->bKGD.color.b = png_get_uint_16(buf+4);
	}
	if(!png_crc_finish())
		PNG_RAISE(1);

}
/*************************************************************************
* FUNCTION
*  png_IDAT_Handler
*
* DESCRIPTION
*	start to parse the first IDAT chunk
*
* PARAMETERS
*	len: length of the first IDAT chunk
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_IDAT_Handler(kal_uint32 len)
{
	if(!(png_dcb.flags & PNG_HAVE_IHDR))
		PNG_RAISE(1);
	png_dcb.flags |= PNG_HAVE_IDAT;
	png_decode_hw(len);
}
/*************************************************************************
* FUNCTION
*  png_decode_process
*
* DESCRIPTION
*	start to parse the PNG image.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_decode_process(void)
{
	kal_uint8 buf[8];

	PNG_GET_ARRAY(buf,8);
	if(kal_mem_cmp(buf, png_signature, 8)!= 0)
		PNG_RAISE(1);

	while(PNG_IS_EOF()!= KAL_TRUE)
	{
		kal_uint32 len;

		len = PNG_GET_U32();
		png_crc_reset();
		png_crc_read(buf,4);
		if(!kal_mem_cmp(buf,png_IHDR,4))
		{
			png_IHDR_Handler(len);
		}
		else if(!kal_mem_cmp(buf,png_PLTE,4))
		{
			png_PLTE_Handler(len);
		}
		else if(!kal_mem_cmp(buf,png_tRNS,4))
		{
			png_tRNS_Handler(len);
		}
		else if(!kal_mem_cmp(buf,png_IDAT,4))
		{
			png_IDAT_Handler(len);
			return ;
		}
		else if(!kal_mem_cmp(buf,png_bKGD,4))
		{
			png_bKGD_Handler(len);
		}
		else if(!kal_mem_cmp(buf,png_IEND,4))
		{
			PNG_RAISE(1);
		}
		else
		{
			PNG_FLUSH(len+PNG_CRC_LEN);
		}
	}
	PNG_RAISE(1);
	//return PNG_FORMAT_ERROR;
}
/*************************************************************************
* FUNCTION
*  png_hisr_entry
*
* DESCRIPTION
*	1. hisr entry function of the PNG interrupt
*	2. calling the callback function registered by the caller
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_hisr_entry(void)
{
	kal_uint32 status;
	png_report_status_enum report;

	PNG_STOP_TIMER();
	status = DRV_Reg(PNG_IRQ_STATUS);
	png_dcb.status = status;
	if(status == PNG_IRQ_STATUS_IMG_COMPLETE)
	{
		//1:  check the ADLER checksum
		report = PNG_FINISH_IMAGE;
		png_state = PNG_STATE_READY;
		PNG_RESET();
	}
	else if(status == PNG_IRQ_STATUS_BLOCK_END)
	{
		if( DRV_Reg(PNG_DECODE_EN)== 0 )
			DRV_WriteReg(PNG_DECODE_EN, 1);
		report = PNG_BLOCK_END;
	}
	else if(status == PNG_IRQ_STATUS_IN_EMPTY)
	{
		report = PNG_INPUT_EMPTY;
	}
	else
	{
		report = PNG_FORMAT_ERROR;
		png_state = PNG_STATE_READY;
		PNG_RESET();
	}
	png_dcb.cb(report);
	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_PNG,PDN_PNG);
	IRQUnmask(IRQ_PNG_CODE);
}
/*************************************************************************
* FUNCTION
*  png_lisr_entry
*
* DESCRIPTION
*	lisr entry function of the png interrupt
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void png_lisr_entry(void)
{
	IRQMask(IRQ_PNG_CODE);
	//kal_activate_hisr(png_hisr);
	visual_active_hisr(VISUAL_PNG_HISR_ID);
}
/*************************************************************************
* FUNCTION
*  png_init
*
* DESCRIPTION
*	Initialization of the driver of the PNG decoder
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void png_init(void)
{
	if(png_hisr == 0)
	{
   	//png_hisr = kal_create_hisr("PNG_HISR",2,512,png_hisr_entry,NULL);
   	VISUAL_Register_HISR(VISUAL_PNG_HISR_ID,png_hisr_entry);
   	png_hisr=VISUAL_PNG_HISR_ID;
   	IRQ_Register_LISR(IRQ_PNG_CODE, png_lisr_entry,"png_lisr");
   	IRQSensitivity(IRQ_PNG_CODE,LEVEL_SENSITIVE);
	}
	if(png_gpt_handle == 0)
		GPTI_GetHandle(&png_gpt_handle);
	png_state = PNG_STATE_READY;
	IRQUnmask(IRQ_PNG_CODE);
}
/*************************************************************************
* FUNCTION
*  png_decode_start
*
* DESCRIPTION
*	1. start to decode a PNG image (async interface )
*	2. calling the callback function while the PNG interrupt is generated or
*		GPT timer is expired
*
* PARAMETERS
*	cfg:	configuration of the driver of PNG decoder
*	info: information of the decoded PNG image
*
* RETURNS
*	PNG_DECODING: the driver is decoding the PNG image without any error
*	PNG_FORMAT_ERROR: the input PNG image is invalid
*
* GLOBALS AFFECTED
*
*************************************************************************/
png_report_status_enum png_decode_start_hw(png_config_struct *cfg, png_inform_struct *info)
{
	png_report_status_enum status;

	ASSERT(png_state == PNG_STATE_READY);
	png_state = PNG_STATE_BUSY;
	ASSERT(cfg->cb != NULL);

	kal_mem_set(&png_dcb, 0, sizeof(png_dcb));
	png_dcb.cb = cfg->cb;
	png_dcb.cfg = cfg;
	if(cfg->decode_mode == PNG_DECODE_FILE)
	{
		// reserve 4 bytes for the partial input limiation
		png_dcb.file_size = hw_bytestream_create_file(HW_BYTESTREAM_PNG,
			cfg->file_handle,
			(kal_uint8*)(cfg->in_buffer_adrs),
			cfg->in_buffer_size);
		if(png_dcb.file_size)
		{
			//png_dcb.in_count = png_dcb.file_size;
			if(png_dcb.file_size > cfg->in_buffer_size)
				png_dcb.partial_en = KAL_TRUE;
		}
		else
		{
			png_state = PNG_STATE_READY;
			status = PNG_FORMAT_ERROR;
			goto end;
		}
	}
	else // the total file is in the memory
	{
		hw_bytestream_create(HW_BYTESTREAM_PNG,(kal_uint8*)cfg->in_buffer_adrs,cfg->in_buffer_size);
 		png_dcb.file_size = cfg->in_buffer_size;
 		// png_dcb.in_count = png_dcb.file_size;
	}
	png_dcb.timeout_period = cfg->png_timeout_period;
	status = PNG_DECODING;
	PNG_TRY
	png_decode_process();
	PNG_CATCH_BEGIN
	png_state = PNG_STATE_READY;
	status = PNG_FORMAT_ERROR;
	PNG_CATCH_END
	//if(info->use_work_buf == KAL_TRUE)
		//status = PNG_USE_G2D;
	kal_mem_cpy(info, &png_dcb.info, sizeof(png_inform_struct) );
end:

	return status;
}
/*************************************************************************
* FUNCTION
*  png_decode_resume
*
* DESCRIPTION
*	1. keep decoding the remaing PNG images
*	2. calling the callback function while the PNG interrupt is generated or
*		GPT timer is expired
*
* PARAMETERS
*
* RETURNS
*	PNG_DECODING: the driver is decoding the PNG image without any error
*	PNG_FORMAT_ERROR: the input PNG image is invalid
*	PNG_FINISH_IMAGE: the total image has been decoded successfully
*
* GLOBALS AFFECTED
*
*************************************************************************/
png_report_status_enum png_decode_resume(void)
{
	kal_uint32 status;
	png_report_status_enum report;

	ASSERT(png_state == PNG_STATE_BUSY);
	DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_PNG,PDN_PNG);
	status = png_dcb.status;
	report = PNG_DECODING;

	PNG_TRY
	if(status == PNG_IRQ_STATUS_BLOCK_END)
	{
		if(!png_dcb.is_IEND)
		{
			png_assemble_idat();
			DRV_WriteReg32(PNG_IN_START, png_idat_buf);
			DRV_WriteReg32(PNG_IN_COUNT, idat_buf_len+4);
			if(png_dcb.z_count >= 4)
			{
				DRV_WriteReg32(PNG_IDAT_COUNT, png_dcb.z_count);
			}
			else if(png_dcb.z_count > 0)
			{
				kal_uint32 reg,i;
				kal_uint8 *ptr = (kal_uint8*)png_idat_buf;

				for(reg=0,i=0; i<png_dcb.z_count; i++)
				{
					 reg |= (ptr[i] << (8*i));
				}
				DRV_WriteReg32(PNG_IDAT_BUFFER, reg);
				DRV_WriteReg32(PNG_IDAT_COUNT, png_dcb.z_count);
			}
			else
				DRV_WriteReg32(PNG_IDAT_COUNT, idat_buf_len);

			PNG_RESUME();
		}
		else
		{
			PNG_RESET();
			png_state = PNG_STATE_READY;
			report =  PNG_FINISH_IMAGE;
		}
	}
	else if(status == PNG_IRQ_STATUS_IN_EMPTY)
	{
		PNG_RAISE(1);
	}
	PNG_CATCH_BEGIN
	png_state = PNG_STATE_READY;
	report = PNG_FORMAT_ERROR;
	PNG_CATCH_END

	return report;
}
/*************************************************************************
* FUNCTION
*  png_decode_stop
*
* DESCRIPTION
*	stop decoding the PNG image (abort in the meddle of the decoding process)
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void png_decode_stop_hw(void)
{
	png_state = PNG_STATE_READY;

	DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_PNG,PDN_PNG);
	IRQMask(IRQ_PNG_CODE);
	DRV_WriteReg32(PNG_IRQ_EN, 0);
	PNG_RESET();
	IRQUnmask(IRQ_PNG_CODE);
	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_PNG,PDN_PNG);
}
#endif //USE_HW_PNG_DECODER_V1

//------------------------------------------------------------------------//
//							Unit Test Code 												  //
//------------------------------------------------------------------------//
#if defined (PNG_MODULE_BURN_TEST)
#undef PNG_UNIT_TEST
// --------------------remove --------------------------//
#define MT6228_BURNING_SYSRAM_SIZE  128*1024
#pragma arm section zidata = "SYSRAMZI"
__align(4) kal_uint8 g_burning_sysram[MT6228_BURNING_SYSRAM_SIZE];
#pragma arm section zidata
kal_bool g_burning_sysram_ready = KAL_TRUE;

kal_uint8* drvtest_get_sysram(kal_uint32 *p_size)
{
	if(g_burning_sysram_ready == KAL_FALSE)
	{
		while(1);
	}

	*p_size = MT6228_BURNING_SYSRAM_SIZE;

	g_burning_sysram_ready = KAL_FALSE;

	return g_burning_sysram;
}

void drvtest_release_sysram(void)
{
	g_burning_sysram_ready = KAL_TRUE;
}
// --------------------remove --------------------------//

kal_eventgrpid my_Events;
png_report_status_enum cb_status;
png_config_struct png_config;
png_inform_struct png_info;
volatile kal_bool png_stop_now = KAL_FALSE;

#define MY_GET_BUF(a,b,c)		a = (kal_uint32*)b; b += (c);
#define PNG_OUTPUT_SIZE		(sizeof basn6a08_result)

void png_callback(png_report_status_enum status)
{
	cb_status = status;
	kal_set_eg_events(my_Events,1,KAL_OR);
}

#include "basn6a08.c"
#include "basn6a08_result.c"
kal_bool png_module_burn_test(void)
{
	png_config_struct *p = &png_config;
	png_report_status_enum status;
	kal_uint32 flag,bytes,buf_size;
	kal_uint8 *buffer;
	extern kal_uint8* drvtest_get_sysram(kal_uint32 *p_size);
	extern void drvtest_release_sysram(void);

	png_init();
	my_Events = kal_create_event_group("my Events");

	p->in_buffer_adrs = (kal_uint32)basn6a08;
	p->in_buffer_size = sizeof basn6a08 ;

	buffer = drvtest_get_sysram(&buf_size);
	p->output_buffer_adrs = (kal_uint32)buffer;
	buffer += PNG_OUTPUT_SIZE;
	p->output_buffer_size = PNG_OUTPUT_SIZE+1024;

	MY_GET_BUF(p->hclen, buffer, HCLEN_LEN);
	MY_GET_BUF(p->hlen, buffer, HLEN_LEN);
	MY_GET_BUF(p->hlit, buffer, HLIT_LEN);
	MY_GET_BUF(p->hdist, buffer, HDIST_LEN);
	MY_GET_BUF(p->buff0, buffer, BUFF0_LEN);
	MY_GET_BUF(p->buff1, buffer, BUFF1_LEN);
	MY_GET_BUF(p->LZ77, buffer, LZ77_LEN);
	MY_GET_BUF(p->color_table, buffer, 1024);
	MY_GET_BUF(p->color_table_t, buffer, 256);

	p->shadow_w = 32;
	p->shadow_h = 32;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = 32;
	p->clip_y2 = 32;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = 0;
	p->expect_h = 0;

	p->clip_en = KAL_FALSE;
	p->out_format = RGB888;
	p->cb = png_callback;

	status = png_decode_start(p, &png_info);
	if(status ==  PNG_FORMAT_ERROR)
		goto end;
	kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
	while(1)
	{
		if (cb_status == PNG_BLOCK_END)
		{
			if(!png_stop_now)
			{
				status = png_decode_resume();
				if(status == PNG_DECODING)
					kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				else if(status == PNG_FINISH_IMAGE)
				{
					goto end;
				}
				else
				{
					goto end;
				}
			}
			else
			{
				png_decode_stop();
				goto end;
			}
		}
		else if(cb_status == PNG_INPUT_EMPTY)
		{
			ASSERT(0);
		}
		else if(cb_status == PNG_FINISH_IMAGE)
		{
			ASSERT(0);
			goto end;
		}
		else	// PNG_DECODE_TIMEOUT, PNG_FORMAT_ERROR
		{
			png_decode_stop();
			break;
		}
	}

end:
	drvtest_release_sysram();
	// compare the result
	if(memcmp((kal_uint8*)p->output_buffer_adrs, basn6a08_result, PNG_OUTPUT_SIZE))
	{
		return KAL_FALSE;
	}
	else
	{
		return KAL_TRUE;
	}

}

void png_test_main(void)
{
	png_module_burn_test();
}

#endif // PNG_MODULE_BURN_TEST
// #define PNG_UINT_TEST
#if defined (PNG_UINT_TEST)
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "rtfiles.h"

// unit test code start here
//#define FILE_BUFFER_SIZE		(16*1024)
#define FILE_BUFFER_SIZE		(16*1024)
#define OUT_BUFFER_SIZE			(LCD_WIDTH*LCD_HEIGHT*2)

kal_uint32 hdist[HDIST_LEN/4];
kal_uint32 hlit[HLIT_LEN/4];
kal_uint32 LZ77[LZ77_LEN/4];
kal_uint32 hclen[HCLEN_LEN/4];
kal_uint32 hlen[HLEN_LEN/4];
kal_uint32 buff0[BUFF0_LEN/4];
kal_uint32 buff1[BUFF1_LEN/4];
kal_uint32 color_table[CT_LEN];
kal_uint32 color_table_t[CT_LEN];	// transparent pallete

png_internal_buffer_struct png_buffers = 	{hclen,
	hlen, hlit, hdist, buff0,
	buff1,LZ77, color_table, color_table_t};

kal_uint8 in_buffer[FILE_BUFFER_SIZE];
kal_uint16 lcd_buffer[LCD_WIDTH*LCD_HEIGHT];

kal_uint8 file_name[256];
kal_wchar file_name_w[256];
kal_uint32 file_size;

kal_eventgrpid my_Events;
png_report_status_enum cb_status;
png_config_struct png_config;
png_inform_struct png_info;
volatile kal_bool png_stop_now = KAL_FALSE;

static kal_uint32 t1, t2;
void GPT3_Init_my(void)
{
	// clear pdn bit of GPT
	DRV_Reg(0x80000324) = 1;
	// set clock
	DRV_Reg(0x80100024) = 0; // 16k Hz
	// start free running
	DRV_Reg(0x8010001c) = 1;
}


kal_uint32 GPT3_GetCount(void)
{
	volatile kal_uint32 t;

	t = DRV_Reg(0x80100020);
	return t;
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
static void LCD_Display(void *adrs, kal_uint16 w, kal_uint16 h)
{
	LCDDisplay_adrs(w,h,0,0,adrs);
}


void png_callback(png_report_status_enum status)
{

	cb_status = status;
	kal_set_eg_events(my_Events,1,KAL_OR);


}

// file mode, multi frame, no partila input, no resizing
void test_case_1(void)
{
	png_config_struct *p = &png_config;
	png_report_status_enum status;
	kal_uint32 flag;


	sprintf(file_name, "c:\\png\\basn2c08.png");
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = PNG_DECODE_FILE;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);

	DRM_file_size(p->file_handle, &file_size);
	p->in_buffer_adrs = (kal_uint32)in_buffer;
	p->in_buffer_size = sizeof in_buffer;
	p->output_buffer_adrs = (kal_uint32)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;

	p->hclen = png_buffers.hclen;
	p->hlen = png_buffers.hlen;
	p->hlit = png_buffers.hlit;
	p->hdist = png_buffers.hdist;
	p->buff0 = png_buffers.buff0;
	p->buff1 = png_buffers.buff1;
	p->LZ77 = png_buffers.LZ77;
	p->color_table = png_buffers.color_table;
	p->color_table_t = png_buffers.color_table_t;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH;
	p->clip_y2 = LCD_HEIGHT;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->clip_en = KAL_TRUE;
	p->out_format = RGB565;
	p->cb = png_callback;

	t1 = GPT3_GetCount();
	status = png_decode_start(p, &png_info);
	if(status ==  PNG_FORMAT_ERROR)
		goto end;
	kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
	while(1)
	{
		if(cb_status == PNG_INPUT_EMPTY)
		{
			ASSERT(0);
		}
		else if (cb_status == PNG_BLOCK_END)
		{
			if(!png_stop_now)
			{
				status = png_decode_resume();
				if(status == PNG_DECODING)
					kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				else if(status == PNG_FINISH_IMAGE)
				{
					t2 = GPT3_TimeDiff(t1);
					dbg_print("\t period: %d",t2);
					LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					goto end;
				}
				else
				{
					dbg_print("\n\r decode fail %d !", cb_status);
					goto end;
				}
			}
			else
			{
				png_decode_stop();
				goto end;
			}
		}
		else if(cb_status == PNG_FINISH_IMAGE)
		{
			LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
			goto end;
		}
		else	// PNG_DECODE_TIMEOUT, PNG_FORMAT_ERROR
		{
			png_decode_stop();
			dbg_print("\n\r decode fail %d !", cb_status);
			break;
		}
	}

end:
	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	//LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
}



// memory mode, no partila input, no resizing
void test_case_2(void)
{
	png_config_struct *p = &png_config;
	png_report_status_enum status;
	kal_uint32 flag,bytes;


	sprintf(file_name, "c:\\png\\OI2N2C16.PNG");
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = PNG_DECODE_MEMORY;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);

	DRM_file_size(p->file_handle, &file_size);
	if(file_size > sizeof in_buffer)
	{
			p->decode_mode = PNG_DECODE_FILE;
	}
	else
	{
		if(DRM_read_file(p->file_handle,in_buffer, file_size, &bytes) < 0)
			while(1);
	}

	p->in_buffer_adrs = (kal_uint32)in_buffer;
	p->in_buffer_size = file_size;
	p->output_buffer_adrs = (kal_uint32)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;

	p->hclen = png_buffers.hclen;
	p->hlen = png_buffers.hlen;
	p->hlit = png_buffers.hlit;
	p->hdist = png_buffers.hdist;
	p->buff0 = png_buffers.buff0;
	p->buff1 = png_buffers.buff1;
	p->LZ77 = png_buffers.LZ77;
	p->color_table = png_buffers.color_table;
	p->color_table_t = png_buffers.color_table_t;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH;
	p->clip_y2 = LCD_HEIGHT;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->clip_en = KAL_TRUE;
	p->out_format = RGB565;
	p->cb = png_callback;

	t1 = GPT3_GetCount();
	status = png_decode_start(p, &png_info);
	if(status ==  PNG_FORMAT_ERROR)
		goto end;
	kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
	while(1)
	{
		if (cb_status == PNG_BLOCK_END)
		{
			if(!png_stop_now)
			{
				status = png_decode_resume();
				if(status == PNG_DECODING)
					kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				else if(status == PNG_FINISH_IMAGE)
				{
					t2 = GPT3_TimeDiff(t1);
					dbg_print("\t period: %d",t2);
					LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					goto end;
				}
				else
				{
					dbg_print("\n\r decode fail %d !", cb_status);
					goto end;
				}
			}
			else
			{
				png_decode_stop();
				goto end;
			}
		}
		else if(cb_status == PNG_INPUT_EMPTY)
		{
			ASSERT(0);
		}
		else if(cb_status == PNG_FINISH_IMAGE)
		{
			ASSERT(0);
			LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
			goto end;
		}
		else	// PNG_DECODE_TIMEOUT, PNG_FORMAT_ERROR
		{
			png_decode_stop();
			dbg_print("\n\r decode fail %d !", cb_status);
			break;
		}
	}

end:
	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	//LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
}

// verify using 2D special case
void test_case_4(void)
{
	png_config_struct *p = &png_config;
	png_report_status_enum status;
	kal_uint32 flag;


	sprintf(file_name, "c:\\png\\cos-email.png");
	kal_wsprintf(file_name_w,(char*)file_name);
	p->decode_mode = PNG_DECODE_FILE;
	p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
	if(p->file_handle < 0 )
		ASSERT(0);

	DRM_file_size(p->file_handle, &file_size);
	p->in_buffer_adrs = (kal_uint32)in_buffer;
	p->in_buffer_size = sizeof in_buffer;
	p->output_buffer_adrs = (kal_uint32)lcd_buffer;
	p->output_buffer_size = sizeof lcd_buffer;

	p->hclen = png_buffers.hclen;
	p->hlen = png_buffers.hlen;
	p->hlit = png_buffers.hlit;
	p->hdist = png_buffers.hdist;
	p->buff0 = png_buffers.buff0;
	p->buff1 = png_buffers.buff1;
	p->LZ77 = png_buffers.LZ77;
	p->color_table = png_buffers.color_table;
	p->color_table_t = png_buffers.color_table_t;

	p->shadow_w = LCD_WIDTH;
	p->shadow_h = LCD_HEIGHT;
	p->clip_x1 = 0;
	p->clip_y1 = 0;
	p->clip_x2 = LCD_WIDTH;
	p->clip_y2 = LCD_HEIGHT;
	p->dest_x = 0;
	p->dest_y = 0;

	p->expect_w = LCD_WIDTH;
	p->expect_h = LCD_HEIGHT;

	p->clip_en = KAL_TRUE;
	p->out_format = RGB565;
	p->cb = png_callback;

	t1 = GPT3_GetCount();
	status = png_decode_start(p, &png_info);
	if(status ==  PNG_FORMAT_ERROR)
		goto end;
	kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
	while(1)
	{
		if(cb_status == PNG_INPUT_EMPTY)
		{
			ASSERT(0);
		}
		else if (cb_status == PNG_BLOCK_END)
		{
			if(!png_stop_now)
			{
				status = png_decode_resume();
				if(status == PNG_DECODING)
					kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
				else if(status == PNG_FINISH_IMAGE)
				{
					t2 = GPT3_TimeDiff(t1);
					dbg_print("\t period: %d",t2);
					LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
					goto end;
				}
				else
				{
					dbg_print("\n\r decode fail %d !", cb_status);
					goto end;
				}
			}
			else
			{
				png_decode_stop();
				goto end;
			}
		}
		else if(cb_status == PNG_FINISH_IMAGE)
		{
			LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
			goto end;
		}
		else if(cb_status == PNG_USE_G2D)
		{
			p->output_buffer_adrs = (kal_uint32)lcd_buffer;
			status = png_decode_resume();
			if(status == PNG_DECODING)
				kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
			else if(status == PNG_FINISH_IMAGE)
			{
				LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
				goto end;
			}
			else
			{
				dbg_print("\n\r decode fail %d !", cb_status);
				goto end;
			}
		}
		else	// PNG_DECODE_TIMEOUT, PNG_FORMAT_ERROR
		{
			png_decode_stop();
			dbg_print("\n\r decode fail %d !", cb_status);
			break;
		}
	}

end:
	LCD_Display(png_work_buffer, png_dcb.info.img_w, png_dcb.info.img_h);
	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	//LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
}
void test_case_all(void)
{
	kal_int32 s, file_count;
	FS_HANDLE handle;
	RTFDOSDirEntry de;
	png_config_struct *p = &png_config;
	png_report_status_enum status;
	static kal_bool is_first = KAL_TRUE;
	kal_uint32 flag;

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
		p->file_handle = DRM_open_file(file_name_w,FS_READ_ONLY|FS_OPEN_NO_DIR,DRM_PERMISSION_DISPLAY);
		if(p->file_handle < 0 )
			ASSERT(0);
		DRM_file_size(p->file_handle, &file_size);
		dbg_print("\r\n[%d] File: %s\t, size: %d\t",file_count, file_name, file_size);
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

		p->hclen = png_buffers.hclen;
		p->hlen = png_buffers.hlen;
		p->hlit = png_buffers.hlit;
		p->hdist = png_buffers.hdist;
		p->buff0 = png_buffers.buff0;
		p->buff1 = png_buffers.buff1;
		p->LZ77 = png_buffers.LZ77;
		p->color_table = png_buffers.color_table;
		p->color_table_t = png_buffers.color_table_t;

		p->shadow_w = LCD_WIDTH;
		p->shadow_h = LCD_HEIGHT;
		p->clip_x1 = 0;
		p->clip_y1 = 0;
		p->clip_x2 = LCD_WIDTH;
		p->clip_y2 = LCD_HEIGHT;
		p->dest_x = 0;
		p->dest_y = 0;

		p->expect_w = LCD_WIDTH;
		p->expect_h = LCD_HEIGHT;

		p->clip_en = KAL_TRUE;
		p->out_format = RGB565;
		p->cb = png_callback;

		t1 = GPT3_GetCount();
		status = png_decode_start(p, &png_info);
		if(status == PNG_DECODING)
			kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
		else
		{
			dbg_print("\n\r decode fail %d !", status);
			goto end;
		}

		while(1)
		{
			if (cb_status == PNG_BLOCK_END)
			{
				if(!png_stop_now)
				{
					status = png_decode_resume();
					if(status == PNG_DECODING)
						kal_retrieve_eg_events(my_Events,(1),KAL_OR_CONSUME,&flag,KAL_SUSPEND);
					else if(status == PNG_FINISH_IMAGE)
					{
						t2 = GPT3_TimeDiff(t1);
						dbg_print("\t period: %d",t2);
						dbg_print(" decode pass !");
						LCD_Display(lcd_buffer, LCD_WIDTH, LCD_HEIGHT);
						goto end;
					}
					else
					{
						dbg_print("\n\r decode fail %d !", cb_status);
						goto end;
					}
				}
				else
				{
					png_decode_stop();
					goto end;
				}
			}
			else if(cb_status == PNG_FINISH_IMAGE)
			{
				ASSERT(0);
			}
			else	// PNG_DECODE_TIMEOUT, PNG_FORMAT_ERROR
			{
				png_decode_stop();
				dbg_print("\n\r decode fail %d !", cb_status);
				break;
			}
		}

end:

	DRM_close_file(p->file_handle);
	memset(lcd_buffer, 0x55, sizeof lcd_buffer);
	}
	RTFFindClose(handle);
	is_first = KAL_TRUE;
}

// verify the function of png_get_gray_scale
void test_case_3(void)
{
	kal_uint32 i,j;
	kal_uint8 bit[] = {1,2,4,8,16};

	for(i=0;i<sizeof bit;i++)
	{
		dbg_print("bit depth = %d\r\n", bit[i]);
		for(j=0;j<(1<<bit[i]);j++)
		{
			kal_uint32 value;

			value = png_get_gray_scale(bit[i], j);
			dbg_print("gray: %x => %x \t", j, value);
		}
		dbg_print("\r\n");
	}
}
void png_test_main(void)
{
	my_Events = kal_create_event_group("my Events");
	GPT3_Init_my();
	LCD_Init();
	SD_Initialize();
	png_init();
	g2d_init();

	while(1)
	{
		test_case_1();
		test_case_all();
	}

}
#endif	// PNG_UNIT_TEST

