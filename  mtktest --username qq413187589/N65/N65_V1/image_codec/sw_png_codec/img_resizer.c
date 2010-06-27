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
 *	 img_resizer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Software png resizer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"
#include "img_resizer.h"

// #pragma arm section zidata = "INTERNZI"
#ifdef PNG_NEW_BUFFER_INTERFACE
static kal_uint8 *img_want_x_buffer;
static kal_uint8 *img_want_y_buffer;
static kal_uint16 *img_want_x_mapping; // map source y to dest y
static kal_uint16 *img_want_y_mapping; 
#define IMG_RESZ_BUFFER_SIZE	(3*(IMG_MAX_WIDTH+IMG_MAX_HEIGHT))
#else
static kal_uint8 img_want_x_buffer[IMG_MAX_WIDTH];
static kal_uint8 img_want_y_buffer[IMG_MAX_HEIGHT];
static kal_uint16 img_want_x_mapping[IMG_MAX_HEIGHT]; // map source y to dest y
static kal_uint16 img_want_y_mapping[IMG_MAX_HEIGHT]; 
#endif
img_resizer_struct IMG_RESIZER;
// #pragma arm section zidata

#if defined(__MTK_TARGET__)&& defined(PNG_SW_USE_ISRAM)
#pragma arm section code = "INTERNCODE"
#endif /* __MTK_TARGET__ */

void img_resizer_put_row(kal_uint8 *src, kal_uint32 width, kal_uint32 row_num, kal_uint32 step)
{
	kal_uint32 i,x,y;	
	kal_uint8 *in, *out;
	register img_resizer_struct *r = &IMG_RESIZER;

	if(r->bytesperpixel == 2)
	{ // RGB888 -> RGB565
		kal_uint16 tmp_color;
		kal_uint16 *w = (kal_uint16*)src;
		kal_uint8 *rp = src;

		if(((kal_uint32)src & 1) != 0)
		{
			src++;
			w = (kal_uint16*)src;;			
		}
			
		i = width;
		while(i--)
		{
			tmp_color = ((*(rp)>>3)<<11)|((*(rp+1)>>2)<<5)|((*(rp+2)>>3));
			
			if(tmp_color==r->src_key)//avoid src_key of MMI
			 tmp_color^=1;
			 
			*w++ = tmp_color;			
			rp += 3;
		}
	}
	else if(r->bytesperpixel == 3)
	{
	 kal_uint16 *w = (kal_uint16*)src;
	 kal_uint8 *rp = src;
	 kal_uint8 srckey[3];
	 
	 //avoid src_key of MMI
	 srckey[2]=(r->src_key & 0xFF);        //B
	 srckey[1]=(r->src_key & 0xFF00)>>8;   //G
	 srckey[0]=(r->src_key & 0xFF0000)>>16;//R
		
	 i = width;
	 while(i--)
	 {
	  if(rp[0]==srckey[0] && rp[1]==srckey[1] && rp[2]==srckey[2])
	   rp[2]^=0x01;	
	   
	   rp+=3;
		}		
	}
	
	if(r->resize ==  KAL_TRUE)
	{
		kal_uint16 *x_mapping;
		kal_uint8 *out_base, *x_buf;	
		
		if(img_want_y_buffer[row_num] != 1)
			return;
		y = img_want_y_mapping[row_num];
		out_base = r->out_buf + (y*r->out_buf_w) * r->bytesperpixel;
		x_buf = 	img_want_x_buffer;
		x_mapping = img_want_x_mapping;
	   
	   if(r->bytesperpixel==3)
	   {
   		for(i = r->want_start_sx; i < width; i += step)
   		{ // i index of source x
   			if(*(x_buf+i))
   			{	
   				x = *(x_mapping + i);
   				out = out_base + x * r->bytesperpixel;
   				in = src + i*r->bytesperpixel;
		         /*RGB 2 BGR*/   				
   				out[0] = in[2];
   				out[1] = in[1];
   				out[2] = in[0];
   				//kal_mem_cpy(out, in, r->bytesperpixel);
   			}
   		}
   	}
   	else
   	{
		for(i = r->want_start_sx; i < width; i += step)
		{ // i index of source x
			if(*(x_buf+i))
			{	
				x = *(x_mapping + i);
				out = out_base + x * r->bytesperpixel;
				in = src + i*r->bytesperpixel;
				kal_mem_cpy(out, in, r->bytesperpixel);
			}
		}
   	   
   	}
	}
	else
	{
		if(row_num < r->want_start_sy || row_num > r->want_end_sy)
			return;
		in = src + r->want_start_sx*r->bytesperpixel;
		out =  r->out_buf + 
			(r->want_dx1 + (row_num+r->offset_dy)*r->out_buf_w)*
			r->bytesperpixel;
			
		if(r->bytesperpixel==3)
		{
		 kal_uint32 pixels;
		 pixels=(r->want_dx2-r->want_dx1+1)*r->bytesperpixel;
		 for(i=0;i<pixels;i+=3)
		 {
		   /*RGB 2 BGR*/
		   out[i] =   in[i+2];
   		out[i+1] = in[i+1];
   		out[i+2] = in[i];
		 }		 
		}
		else
		{
		 kal_mem_cpy(out,in,(r->want_dx2-r->want_dx1+1)*r->bytesperpixel);		   
		}		
	}
	
}
	
void img_resizer_put_pixel(kal_uint32 x, kal_uint32 y, kal_uint8 *src)
{
	kal_uint32 dx, dy;
	kal_uint8 *out, *in;
	kal_uint16 tmp_color;
	register img_resizer_struct *r = &IMG_RESIZER;
	
	if(r->bytesperpixel == 2)
	{
		tmp_color = ((*(src)>>3)<<11)|((*(src+1)>>2)<<5)|((*(src+2)>>3));
		if(tmp_color==r->src_key)  //avoid src_key of MMI
		 tmp_color^=1;
		in = (kal_uint8*)&tmp_color;
	}
	else if(r->bytesperpixel == 3)
	{
		in = src;
	 	
	 	if(in[2]==(r->src_key & 0xFF)&& //avoid src_key of MMI
	 	   in[1]==((r->src_key & 0xFF00)>>8)&&
	 	   in[0]==((r->src_key & 0xFF0000)>>16))
	 	{
	 	 in[2]^=1;	
	}
	 	
	}
	
	if(r->resize ==  KAL_TRUE)
	{
		if(img_want_y_buffer[y] != 1 || img_want_x_buffer[x] != 1)
			return;
		dx = img_want_x_mapping[x];
		dy = img_want_y_mapping[y];								
	}
	else
	{
		if(x < r->want_start_sx || x > r->want_end_sx ||
			y < r->want_start_sy || y > r->want_end_sy )
			return;
		dx = x + r->offset_dx;
		dy = y + r->offset_dy;				
	}
	out = r->out_buf + (dx + dy*r->out_buf_w) * r->bytesperpixel;
	
	if(r->bytesperpixel == 3)
	{
		out[0] =   in[2];
   	out[1] = in[1];
   	out[2] = in[0]; 
	}	
	else
	kal_mem_cpy(out, in, r->bytesperpixel);
}

#if defined(__MTK_TARGET__)&& defined(PNG_SW_USE_ISRAM)
#pragma arm section code
#endif /* __MTK_TARGET__ */

// input image is always RGB888, output can be RGB565 or RGB888
#ifdef PNG_NEW_BUFFER_INTERFACE
//if init correct, return 1, if init fail return 0, if IMG_CLIP_RECT_TEST correct, return -1
kal_int32 png_img_resizer_init(  
				kal_int32 src_width,kal_int32 src_height, 
				kal_int32 dest_x1,kal_int32 dest_y1,kal_int32 dest_x2,kal_int32 dest_y2, 
				kal_uint8 *upper_buffer, kal_uint32 upper_buffer_size)

#else
kal_int32 png_img_resizer_init(  
				kal_int32 src_width,kal_int32 src_height, 
				kal_int32 dest_x1,kal_int32 dest_y1,kal_int32 dest_x2,kal_int32 dest_y2)
#endif
{
	kal_int32 dest_width;
	kal_int32 dest_height;
	kal_int32 dir_x;
	kal_int32 dir_y;
	register img_resizer_struct *r = &IMG_RESIZER;

	// we don't support 1, 8 bites color format in this resizer
	if(src_width<=0 || src_width>IMG_MAX_WIDTH) return 0;
	if(src_height<=0 || src_height>IMG_MAX_HEIGHT ) return 0;
	
#ifdef PNG_NEW_BUFFER_INTERFACE
	ASSERT(	upper_buffer_size >= IMG_RESZ_BUFFER_SIZE)
	img_want_x_buffer = (kal_uint8*)upper_buffer;
	upper_buffer += IMG_MAX_WIDTH;
	img_want_y_buffer = (kal_uint8*)upper_buffer;
	upper_buffer += IMG_MAX_HEIGHT;
	img_want_x_mapping = (kal_uint16*)upper_buffer; 
	upper_buffer += 2*IMG_MAX_HEIGHT;
	img_want_y_mapping = (kal_uint16*)upper_buffer;
#endif

	kal_mem_set( img_want_x_buffer, 0, IMG_MAX_WIDTH);
	kal_mem_set( img_want_x_mapping, 0, IMG_MAX_WIDTH*2);
	kal_mem_set( img_want_y_buffer, 0, IMG_MAX_HEIGHT);
	kal_mem_set( img_want_y_mapping, 0, IMG_MAX_HEIGHT*2);

	dir_x=dir_y=1;
	if(dest_x1>dest_x2)
	{
		ASSERT(0); // current, we only support dir_x >0
		SWAP(kal_int32,dest_x1,dest_x2);
		dir_x = -1;
	}
	if(dest_y1>dest_y2)
	{
		SWAP(kal_int32,dest_y1,dest_y2);
		dir_y = -1;
	}
		
	r->dest = r->out_buf;
	r->offset_dx = dest_x1;
	r->offset_dy = dest_y1;
	dest_width = dest_x2-dest_x1+1;
	dest_height = dest_y2-dest_y1+1;
		
	r->want_dx1 = dest_x1;
	r->want_dy1 = dest_y1;
	r->want_dx2 = dest_x2;
	r->want_dy2 = dest_y2;

	r->dir_x = dir_x;
	r->dir_y = dir_y; 
	
	// check the clipping area	
	//IMG_CLIP_RECT_TEST(r->want_dx1,r->want_dy1,r->want_dx2,r->want_dy2,return 0); // no pixel will be render !!
	
   if(r->want_dx1 > r->want_dx2  || r->want_dy1 > r->want_dy2) {       
      return 0;       
   }
   else if(r->want_dx2 < IMG_RESIZER.clipx1 || 
           r->want_dy2 < IMG_RESIZER.clipy1 || 
           r->want_dx1 > IMG_RESIZER.clipx2 ||
           r->want_dy1 > IMG_RESIZER.clipy2) {         
            
      return -1;   
   }   
   else
   {	
      if(r->want_dx1 < IMG_RESIZER.clipx1) { 
         r->want_dx1 = IMG_RESIZER.clipx1; 
      }
      
      if(r->want_dy1 < IMG_RESIZER.clipy1) { 
         r->want_dy1 = IMG_RESIZER.clipy1; 
      }
      
      if(r->want_dx2 > IMG_RESIZER.clipx2) { 
         r->want_dx2 = IMG_RESIZER.clipx2; 
      }
      
      if(r->want_dy2 > IMG_RESIZER.clipy2) { 
         r->want_dy2 = IMG_RESIZER.clipy2; 
      }
   }

	// non resize handler
	if(src_width == dest_width && src_height == dest_height)
	{
		r->resize = KAL_FALSE;
		r->dest = r->out_buf;
		if(dir_x >0)
		{
			r->want_start_sx = r->want_dx1 - dest_x1;
			r->want_end_sx 	= r->want_dx2 - dest_x1;			
		}
		else
		{
			r->want_start_sx = r->want_dx2 - dest_x1;
			r->want_end_sx  = r->want_dx1 - dest_x1;
		}
		if(dir_y >0)
		{
			r->want_start_sy = r->want_dy1 - dest_y1;
			r->want_end_sy 	= r->want_dy2 - dest_y1;			
		}
		else
		{
			r->want_start_sy = r->want_dy2 - dest_y1;
			r->want_end_sy  = r->want_dy1 - dest_y1;			
		}

		return 1;		
	}

	r->resize = KAL_TRUE;
	// make want_x table
	{
		kal_int32 x;
		kal_int32 i;
		kal_int32 multiply_factor = (src_width <<16)/ dest_width;
		kal_int32 start_dx,end_dx,index = 0;
		kal_uint32 want_x_count = 0;

		if(dir_x>0)
		{
			start_dx = r->want_dx1;
			end_dx = r->want_dx2;
		}
		else
		{
			start_dx = r->want_dx2;
			end_dx = r->want_dx1;
		}		
		r->want_start_sx = (((start_dx - dest_x1) * multiply_factor) >> 16);
		img_want_x_buffer[r->want_start_sx] = 1;
		for(i=1, x=start_dx+dir_x; x<=end_dx; x+=dir_x, i++)
		{
			kal_int32 d = x - dest_x1;

			index = ((d * multiply_factor) >> 16);
			img_want_x_buffer[index] = 1;
		}
		r->want_end_sx = index;
		for(i = r->want_start_sx; i<= r->want_end_sx; i++)
		{
			if(img_want_x_buffer[i])
			{
				img_want_x_mapping[i] = r->want_dx1 + want_x_count++;
			}					
		}
		
	}
	// make want_y table
	{
			kal_int32 y;
			kal_int32 i;
			kal_int32 multiply_factor = (src_height <<16)/ dest_height;
			kal_int32 start_dy,end_dy,index = 0;
			kal_uint32 want_y_count = 0;

			kal_mem_set( img_want_y_buffer, 0, sizeof img_want_y_buffer);
			if(dir_y>0)
			{
				start_dy = r->want_dy1;
				end_dy = r->want_dy2;
			}
			else
			{
				start_dy = r->want_dy2;
				end_dy = r->want_dy1;
			}
			r->want_start_sy = (((start_dy - dest_y1) * multiply_factor) >> 16);
			img_want_y_buffer[r->want_start_sy] = 1;				
			for(y=start_dy+dir_y; y<=end_dy; y+=dir_y)
			{
				kal_int32 d = y - dest_y1;
	
				index = ((d * multiply_factor) >> 16);
				img_want_y_buffer[index] = 1;
			}
			r->want_end_sy = index;
			for(i = r->want_start_sy; i<= r->want_end_sy; i++)
			{
				if(img_want_y_buffer[i])
				{
					img_want_y_mapping[i] = r->want_dy1 + want_y_count++;
				}					
			}
		}

	return 1;
}

