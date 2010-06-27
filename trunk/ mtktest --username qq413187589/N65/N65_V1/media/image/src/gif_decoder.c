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
*   gif_decoder.c
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   driver for GIF decoder
*   
*
* Author:
* -------
*   Kumar Chen  
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Revision:   1.11  $
* $Modtime:   Aug 19 2005 13:29:42  $
* $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/media/image/src/gif_decoder.c-arc  $
 * 
 *    Rev 1.11   Aug 19 2005 17:21:34   mtk00479
 * remove assertion while the clipping parameters are not resonable.
 * Resolution for 12417: [GIF][Modify]remove assertion while clipping parameters are not reasonable.
 * 
 *    Rev 1.10   Aug 15 2005 10:51:00   mtk00479
 * change the compile option (MT6219) with (USE_HW_GIF_DECODER_V1)
 * Resolution for 12332: [GIF]Change the compile option MT6219 with USE_HW_GIF_DECODER_V1
 * 
 *    Rev 1.9   Jun 17 2005 11:18:40   mtk00479
 * The 2D interfaces has been changed from call by value to call by reference.
 * Resolution for 11558: [GIF][Modify]The 2D interfaces has been changed from call by value to call by reference.
 * 
 *    Rev 1.8   May 17 2005 00:58:28   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 * 
 *    Rev 1.7   Jan 18 2005 00:49:04   BM
 * append new line in W05.04
 * 
 *    Rev 1.6   Oct 05 2004 14:11:28   mtk00479
 * Write the guarding pattern for every gif frames
 * Resolution for 8073: [GIF][Modify]Write the guarding pattern for every gif frames
 * 
 *    Rev 1.5   Sep 17 2004 16:18:20   mtk00479
 * Using new G2D interface instead of old ones
 * Resolution for 7719: [Media][BugFix]
 * 
 *    Rev 1.4   Sep 15 2004 13:32:52   mtk00479
 * 1. modify timeout mechanism
 * 2. remove assertion as hw gif decode failed and return error status
 * Resolution for 1051: Sound Recorder-Assert fail: 0 gif_decoder.c 353 - MMI
 * 
 *    Rev 1.3   Aug 05 2004 13:51:52   mtk00479
 * 1. Detect the hw decoder failed case
 * 2. Add a new API to config the resource by caller
 * Resolution for 7023: [GIF]Add a new API to config resource and detect HW decode fail
 * 
 *    Rev 1.2   Jul 23 2004 17:49:14   mtk00481
 * MMI assume the first gif still have transparent color.
 * 
 *    Rev 1.1   Jul 23 2004 17:25:02   mtk00479
 * Timeout mechanism does not work due to compiler optimization.
 * Resolution for 6815: [GIF][BugFix]Timeout mechanism doesnot work due to the compiler optimization.
 * 
 *    Rev 1.0   Jun 11 2004 16:56:32   BM
 * Initial revision.
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================ 
****************************************************************************/
 // include header files
#include "kal_release.h"
#include "reg_base.h"
#include "drv_comm.h"
#include "gif_decoder.h"
#include "gpt_sw.h"
#include "visual_comm.h"
#include "2d_engine.h"

#if defined(USE_HW_GIF_DECODER_V1)
 // global variables
#define ALIGN_4		__align(4)
gif_resource_struct gif_resource;
gif_dcb_struct gif_dcb;

/*************************************************************************
* FUNCTION
*  GIF_Config_resource
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
void GIF_Config_resource(gif_resource_struct* resource)
{
	ASSERT(((kal_uint32)resource->stack & 3)==0);
	ASSERT(((kal_uint32)resource->tree & 3)==0);
	ASSERT(((kal_uint32)resource->GCT & 3)==0);
	ASSERT(((kal_uint32)resource->LCT & 3)==0);
	ASSERT(resource->GCT_size == 0x200);
	ASSERT(resource->LCT_size == 0x200);
	
	gif_resource = *resource;
 }

/*************************************************************************
* FUNCTION
*  GIF_Reset
*
* DESCRIPTION
*	reset the gif decoder and control block
*
* PARAMETERS
*	
* RETURNS
*   
* GLOBALS AFFECTED
*	gif_dcb
*************************************************************************/
void GIF_Reset(void)
{

	DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);

	GIF_RESET();
	DRV_WriteReg32(GIF_STACK_BASE_ADDR, gif_resource.stack);
 	DRV_WriteReg32(GIF_TREE_BASE_ADDR, gif_resource.tree);
 	DRV_WriteReg32(GIF_GCT_BASE_ADDR, gif_resource.GCT);
 	DRV_WriteReg32(GIF_LCT_BASE_ADDR, gif_resource.LCT);

	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);	
	
	gif_dcb.out_location = GIF_MEMORY;
	//gif_dcb.timeout_period = GIF_TIMEOUT_PERIOD;
	gif_dcb.is_timeout = KAL_FALSE;
	gif_dcb.frame_counter = 0;
	gif_dcb.trailer = KAL_FALSE;		
	if(gif_dcb.gpt_handle == 0)
		GPTI_GetHandle(&gif_dcb.gpt_handle);
	
	kal_mem_set(&gif_dcb.gif_info,0,sizeof(gif_info_struct));
 }

/*************************************************************************
* FUNCTION
*  GIF_CheckGuardPatternValid
*
* DESCRIPTION
*	Check the if the guard patterns of stack and tree memory are corrupted
*
* PARAMETERS
*	
* RETURNS
*   
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool GIF_CheckGuardPatternValid(void)
{
	kal_uint32 *stack,*tree;

	stack = (kal_uint32*)(gif_resource.stack+gif_resource.stack_size-4);
	tree = (kal_uint32*)(gif_resource.tree+gif_resource.tree_size-4);
	if((*stack != GIF_GUARD_PATTERN) ||(*tree != GIF_GUARD_PATTERN))
	{
		ASSERT(0); // guard pattern has been corrupted by GIF decoder => increase the working memory
	}
	
	return KAL_TRUE;	
}
/*************************************************************************
* FUNCTION
*  GIF_TimeOutHandler
*
* DESCRIPTION
*	Callback function of gpt timer, and launched while GIF decoder failed to decode
*	a specified file.
*
* PARAMETERS
*	
* RETURNS
*   
* GLOBALS AFFECTED
*	
*************************************************************************/

void GIF_TimeOutHandler(void *parameter)
{
	gif_dcb.is_timeout = KAL_TRUE;	
}
/*************************************************************************
* FUNCTION
*  GIF_GetInfo
*
* DESCRIPTION
*	Retreive the frame information provided by GIF decoder.
*
* PARAMETERS
*	
* RETURNS
*   
* GLOBALS AFFECTED
*	
*************************************************************************/

void GIF_GetInfo(gif_info_struct *out)
{
	kal_uint32 reg;

	// Image descriptor
	reg = DRV_Reg32(GIF_IMG_REG_1);
	out->height = (kal_uint16)(reg & 0xFFFF); 
	out->width = (kal_uint16)(reg >> 16);
	
	reg = DRV_Reg32(GIF_IMG_REG_2);
	out->y = (kal_uint16)(reg & 0xFFFF); 
	out->x = (kal_uint16)(reg >> 16);
	
	reg = DRV_Reg32(GIF_IMG_REG_3);
	out->LCT_size = (reg & GIF_IMG_REG3_LCT_SIZE); 
	out->interlace = (reg & GIF_IMG_REG3_LCT_INTERLACE) >> 6;
	out->LCT_flag = (reg & GIF_IMG_REG3_LCT_FLG) >> 7;

	// Logical screen descriptor
	reg = DRV_Reg32(GIF_LSD_REG_1);
	out->lheight = (kal_uint16)(reg & 0xFFFF); 
	out->lwidth = (kal_uint16)(reg >> 16);

	reg = DRV_Reg32(GIF_LSD_REG_2);
	out->bg = (reg & GIF_LSD2_BG) >> 8; 
	out->GCT_size = (reg & GIF_LSD2_GCT_SIZE) >> 16; 	
	out->bpp = (reg & GIF_LSD2_BPP) >> 20; 
	out->GCT_flag= (reg & GIF_LSD2_GCT_FLG) >> 23;
	
}
/*************************************************************************
* FUNCTION
*  GIF_DisplayFirst
*
* DESCRIPTION
*	decode the first frame of a gif file
*
* PARAMETERS
*	src: 	buffer contains the gif file
*	dest:	buffer for outputting the decoded frame data(RGB565)
*	size: file size of gif file
*
* RETURNS
*	gif_error_enum
*
* GLOBALS AFFECTED
*	gif_dcb
*
*************************************************************************/
kal_int32 GIF_DecodeFirst(kal_uint8* src, void* dest, kal_uint32 size)
{
	kal_uint32 m,n;

	if(((kal_uint32)src&3 !=0) || ((kal_uint32)dest&3 !=0))
		ASSERT(0);
	
	// protect GIF decoder from stepping over GIF_INFILE_END	
	n= size/4;
	m = size%4;
	if(m == 3)
		DRV_WriteReg32(GIF_INFILE_END, (src+size+35));
	else
		DRV_WriteReg32(GIF_INFILE_END, (src+ (n*4+3)+35));	
	DRV_WriteReg32(GIF_INFILE_START,src);

	return GIF_DecodeNext( dest);
} 

/*************************************************************************
* FUNCTION
*  GIF_DisplayNext
*
* DESCRIPTION
*	decode the following frame of a gif file
*
* PARAMETERS
*	dest:	buffer for outputing the decoded frame data(RGB565)
*
* RETURNS
*	gif_error_enum
*
* GLOBALS AFFECTED
*	gif_dcb
*
*************************************************************************/
kal_int32  GIF_DecodeNext(void* dest)
{
	kal_uint8 status;
	kal_uint8 bg_index;
	kal_uint16 *gct_ptr;
		
	DRV_WriteReg32(GIF_GCE_REG,((gif_dcb.gif_info.transparent_index<< 1)| \
		(gif_dcb.gif_info.transparent_flag)));
	DRV_WriteReg32(GIF_ORGB_BASE_ADDR,dest);
	gif_dcb.is_timeout = KAL_FALSE;
	
	GIF_START();
   GPTI_StartItem(gif_dcb.gpt_handle,
                  gif_dcb.timeout_period,
                  GIF_TimeOutHandler,
                  NULL);
	
	// busy waiting may be replaced by retreive event group
	while(1)
	{
		volatile kal_bool *timeout = &gif_dcb.is_timeout;

		status = DRV_Reg(GIF_STATUS_REG);
		// check if gif decoder is completed or not 
		if(status & ~GIF_STATUS_GCE) 
		{
			GPTI_StopItem(gif_dcb.gpt_handle);
			gif_dcb.is_timeout = KAL_FALSE;
			break;
		}							
		if(*timeout)
		{
			status = DRV_Reg(GIF_STATUS_REG);
			// check if gif decoder is completed or not 
			if(status & ~GIF_STATUS_GCE) 
			{
				GPTI_StopItem(gif_dcb.gpt_handle);
				gif_dcb.is_timeout = KAL_FALSE;
				break;
			}			
			break;		
		}		
	}
	
	// check if the guard pattern still exists
	GIF_CheckGuardPatternValid();
	
	// retreive gif info and backgroud color
	GIF_GetInfo(&gif_dcb.gif_info);
	bg_index = gif_dcb.gif_info.bg;
	gct_ptr = (kal_uint16*)gif_resource.GCT;
	if(bg_index < (1 << (gif_dcb.gif_info.GCT_size+1)))
	{
		gif_dcb.gif_info.bg_color = gct_ptr[bg_index];
	}
	else
	{
		gif_dcb.gif_info.bg_color = 0xFFFF;
		//dbg_print("!!!!Background index exceed the size of GCT!!!!\r\n");
	}
		
	if(status & (GIF_STATUS_FINISH_FRMAE |GIF_STATUS_FINISH_FILE)) // one frame 
	{
		if(status & GIF_STATUS_FINISH_FILE)	
		{		
			//dbg_print("HW file finish!\r\n");
			return GIF_LAST_FRAME;
		}			
		else
		{
			//dbg_print("HW frame finish!\r\n");
			return GIF_FINISH_FRAME;
		}
	}
	else if(status & GIF_STATUS_END) // truncated gif file
	{
		//ASSERT(0);
		return GIF_TRUNCATED_FILE;
	}
	else if(gif_dcb.is_timeout) // hw decoder failed to decode the gif file
	{
		//ASSERT(0);
		return GIF_DECODE_TIMEOUT;
	}
	//ASSERT(0);
	return GIF_FORMAT_ERROR;	
}

/*************************************************************************
* FUNCTION
*  GIF_G2D_FillBG
*
* DESCRIPTION
*	Fill the logical screen with specified position and background color
*
* PARAMETERS
*	gif_para_struct: specifying configuration parameters
*	gif_info_struct: specifying logical screen size and background color
* RETURNS
*	gif_error_enum
*
* GLOBALS AFFECTED
*	gif_dcb
*
*************************************************************************/
kal_bool GIF_G2D_FillBG(const gif_para_struct *s, gif_info_struct *info)
{
	g2d_parameter_struct g2d; 

	// out of clip window
	if((s->dest_x+info->lwidth-1)< s->clip_x1)
		return KAL_FALSE;	
	if(s->dest_x > s->clip_x2)
		return KAL_FALSE;
	if((s->dest_y+info->lheight-1) < s->clip_y1)
		return KAL_FALSE;
	if(s->dest_y > s->clip_y2)
		return KAL_FALSE;	
	if(s->dest_x < 0)
	{
		g2d.dest_x = 0;
		g2d.dest_width = info->lwidth+s->dest_x;
	}
	else
	{
		g2d.dest_x = s->dest_x;
		g2d.dest_width = info->lwidth;

	}
	if(s->dest_y < 0)
	{
		g2d.dest_y = 0;
		g2d.dest_height = info->lheight+s->dest_y;
	}
	else
	{
		g2d.dest_y = s->dest_y;
		g2d.dest_height = info->lheight;
	}
	
	g2d.clip_start_x = s->clip_x1;
	g2d.clip_start_y = s->clip_y1;
	g2d.clip_end_x = s->clip_x2;
	g2d.clip_end_y = s->clip_y2;	
	
//	g2d.dest_pitch = s->shadow_width*2; 
	g2d.dest_pitch_width = s->shadow_width; 
//	g2d.dest_base_address = (kal_uint32)s->shadow_adrs+(s->shadow_width*g2d.dest_y+g2d.dest_x)*2;
	g2d.dest_base_address = (kal_uint32)s->shadow_adrs;

	g2d.dest_color_mode = G2D_DEST_16BPP_LUT_DISABLE;
	g2d.src_color_mode = G2D_SRC_16BPP_LUT_DISABLE;
	g2d.clip_mode = G2D_CLIP_ENABLE;
	g2d.pat_fg_color = info->bg_color;

	g2d.g2d_operation_mode=G2D_OPERATION_RECTANGLE_FILL;
	g2d_accelerator(&g2d);	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  GIF_G2D_BitBlt
*
* DESCRIPTION
*	Copy the frame into logical screen with transparent color
*
* PARAMETERS
*	gif_para_struct: specifying configuration parameters
*	gif_info_struct: specifying logical screen size and transparent flag
* RETURNS
*	gif_error_enum
*
* GLOBALS AFFECTED
*	gif_dcb
*
*************************************************************************/
void GIF_G2D_BitBlt(const gif_para_struct *s, gif_info_struct *info)
{
	g2d_parameter_struct g2d;
	
	if((s->dest_x+info->x) < 0)
	{
		if((s->dest_x+info->x+info->width-1) < 0)
			return;
		g2d.src_x = -1*(s->dest_x+info->x);
		g2d.src_width = info->width+s->dest_x+info->x;
		g2d.dest_x = 0;	
	}
	else
	{
		g2d.src_x = 0;
		g2d.src_width =info->width;
		g2d.dest_x = s->dest_x+info->x;
	}
	if((s->dest_y+info->y) < 0)
	{
		if((s->dest_y+info->y+info->height-1) <0)
			return;
		g2d.src_y = -1*(s->dest_y+info->y);
		g2d.src_height = info->height+s->dest_y+info->y;
		g2d.dest_y = 0;
	}
	else
	{
		g2d.src_y = 0;
		g2d.src_height = info->height;
		g2d.dest_y = s->dest_y+info->y;		
	}
//	g2d.src_pitch = info->width*2;
	g2d.src_pitch_width = info->width;
	g2d.src_key_color = GIF_SOFTKEY;

	g2d.dest_width = g2d.src_width;
	g2d.dest_height = g2d.src_height;
//	g2d.dest_pitch = s->shadow_width*2;
//	g2d.src_base_address = (kal_uint32)s->work_adrs+((g2d.src_y*info->width)+g2d.src_x)*2;	
//	g2d.dest_base_address = (kal_uint32)s->shadow_adrs+((g2d.dest_y*s->shadow_width)+g2d.dest_x)*2;	
	g2d.dest_pitch_width = s->shadow_width;
	g2d.src_base_address = (kal_uint32)s->work_adrs;	
	g2d.dest_base_address = (kal_uint32)s->shadow_adrs;	

	g2d.clip_start_x = s->clip_x1;
	g2d.clip_start_y = s->clip_y1;
	g2d.clip_end_x = s->clip_x2;
	g2d.clip_end_y = s->clip_y2;	
	
	g2d.src_color_mode = G2D_SRC_16BPP_LUT_DISABLE;
	g2d.dest_color_mode = G2D_DEST_16BPP_LUT_DISABLE;
	g2d.clip_mode = G2D_CLIP_ENABLE;
	g2d.bitblt_mode = BITBLT_TRANSFORM_COPY;
	g2d.src_key_mode = gif_dcb.gif_info.transparent_flag;

	g2d.g2d_operation_mode=G2D_OPERATION_BITBLT;
	g2d_accelerator(&g2d);	
}


/*************************************************************************
* FUNCTION
*  GIF_Display_HW
*
* DESCRIPTION
*	Display a GIF frame with specified parameters
*
* PARAMETERS
*	gif_para_struct: specifying configuration parameters
*	gif_info_struct: specifying logical screen size and transparent flag
* RETURNS
*	gif_error_enum
*
* GLOBALS AFFECTED
*	gif_dcb
*
*************************************************************************/
kal_int32 GIF_Display_HW(gif_para_struct *s, gif_info_struct *info)
{
	kal_uint8 *GIF_src, *GIF_end;
	kal_uint32 n; 
	gif_disposal_enum gif_disposal;
	kal_int32 status;
	kal_uint32 *ptr;

	//ENTER_CRITICAL();
	ASSERT(gif_dcb.state == GIF_STATE_READY);
	gif_dcb.state = GIF_STATE_BUSY;
	//EXIT_CRITICAL();

	if( (s->frame_number != 0)&&
		 (gif_dcb.frame_counter == 0)&&
		 (s->reset == KAL_FALSE))
		 ASSERT(0);
	
	if( (s->clip_x1 > s->clip_x2)||
		 (s->clip_y1 > s->clip_y2))
		 return GIF_FINISH_FRAME;
		 //ASSERT(0);		 
	
	if(s->reset || (s->frame_number == 0))
	{
		gif_dcb.img_adrs = s->img_adrs;
		gif_dcb.current_adrs = s->img_adrs;
		gif_dcb.img_end = s->img_adrs+s->img_size;
		GIF_Reset();
	}
	if(gif_dcb.trailer )
	{			
		status =  GIF_NO_FRAME;
		goto gif_display_end;
	}
	
	// initial guard pattern for stack and tree memorys(for every frame)
	ptr = (kal_uint32*)(gif_resource.stack+gif_resource.stack_size-4);
	*ptr = GIF_GUARD_PATTERN;
	ptr = (kal_uint32*)(gif_resource.tree+gif_resource.tree_size-4);
	*ptr = GIF_GUARD_PATTERN;	
		
	GIF_src = gif_dcb.current_adrs;
	GIF_end = gif_dcb.img_end;
	if(gif_dcb.frame_counter  == 0)
	{
		// check gif header 
		if(GIF_src[0] != 'G' || GIF_src[1] != 'I' || GIF_src[2]   != 'F') 
		{
			status = GIF_FORMAT_ERROR;
			goto gif_display_end;
		}
		
		n = GIF_src[10]; // pack field of LSD
		GIF_src += 13;		
		/*	skip the global color palette	*/
		if(n&0x80)
		{
			n=1<<((n&0x7)+1); // GCT size				
			GIF_src += 3*n;
		}
		else
		{
			//dbg_print("!!!! NO GCT EXIST!!!!\r\n");
			//ASSERT(0); // not exist of GCT			
		}
	}
	
	if(GIF_src >= (GIF_end)) 
	{
		status =  GIF_NO_FRAME;
		goto gif_display_end;
	}
   do
   {
   	kal_uint16 w,h;

    	switch(*GIF_src++)
      {	
			case '!':	// 0x21
						if(*GIF_src++==0xf9)
						{	//	Process the GIF extension block(GCE)
							if(GIF_src[1]&0x01)
							{	
								gif_dcb.gif_info.transparent_index = GIF_src[4];
								gif_dcb.gif_info.transparent_flag = 1;
							}
							// use disposal method specified by gif file or user
							if(s->disposal_force == GIF_MTK_NO_ACTION)
								gif_disposal = (GIF_src[1]&0x1c)>>2;
							else
								gif_disposal = s->disposal_force;
							
							//dbg_print("disposal %d!\r\n",gif_disposal);
							// return delay time 
							gif_dcb.gif_info.delay_time = GIF_src[2];								
							GIF_src+=6;
						}
						else // skip other extensions 
						{
							int offset;
							while(1)
							{
								offset= *GIF_src++;
								if(offset==0) break;
								GIF_src += offset;
							}
						}
						break;
			case ',': // 0x2C, image descriptor							
						w = (kal_uint16)(GIF_src[5]<< 8)|(kal_uint16)GIF_src[4];
						h = (kal_uint16)(GIF_src[7]<< 8)|(kal_uint16)GIF_src[6];
						if(w*h*2 > s->work_size)
						{
							//dbg_print("working memory is not enough, WxH: %dx%d\r\n", w,h);
							//ASSERT(0);
							status = GIF_MEM_INSUFFICEITN;														
							goto gif_display_end;
						}
						gif_dcb.timeout_period = 100 * ((w*h)/(640*480)+1); // 1 second per (640x480)
						GIF_src += 8;

						// skip LCT if exist
						n = *GIF_src++;
						if(n&0x80)
						{	
							n=1<<((n&0x7)+1);
							GIF_src += n*3;
						}
						// skip LZW code size
						GIF_src++;
						
						// skip data blocks 
						do{
						n = *GIF_src++;							
						GIF_src += n;
						}while(n != 0);  
						
						// trigger hw decoder
						DRVPDN_Disable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);
						if(gif_dcb.frame_counter == 0)	
						{						
							status = GIF_DecodeFirst(s->img_adrs,(void*)s->work_adrs, s->img_size);									
						}
						else
						{
							status = GIF_DecodeNext((void*)s->work_adrs);							
						}			
						if(status < 0)			
							goto	gif_display_end;							
						if(w != gif_dcb.gif_info.width ||
							h != gif_dcb.gif_info.height)
						{
							status = GIF_HW_DECODE_FAIL;
							goto gif_display_end;
						}						 
						if(status == GIF_LAST_FRAME)
						{
							gif_dcb.trailer = KAL_TRUE; // hardware detect the trailer
						}
						else if(GIF_src[0] == 0x3B||GIF_src[1] == 0x3B)
						{
							gif_dcb.trailer = KAL_TRUE; // software detect the trailer
						}												
						if(/*gif_dcb.frame_counter == 0 || */gif_disposal == GIF_RESTORE_BG)							
						{
							kal_bool tmp;
							
							if(!s->decode_test)
							{
								tmp = GIF_G2D_FillBG(s,&gif_dcb.gif_info); 
								if( tmp == KAL_FALSE)
								{
									if(gif_dcb.trailer == KAL_TRUE)
										status = GIF_LAST_FRAME;
									else
										status = GIF_OUT_OF_RANGE;
									goto gif_display_end;
								}
							}
						}	
						if(!s->decode_test)
							GIF_G2D_BitBlt(s,&gif_dcb.gif_info);										
						if(s->frame_number == gif_dcb.frame_counter)
						{
							gif_dcb.frame_counter++;
							gif_dcb.current_adrs = GIF_src;							
							if(gif_dcb.trailer == KAL_TRUE)
								status = GIF_LAST_FRAME;

							goto gif_display_end;
						}
						gif_dcb.frame_counter++;
						break;
         case ';': // 0x3b, trailer                  
                  //dbg_print("SW file finish!\r\n");
                  gif_dcb.trailer = KAL_TRUE;
                  status = GIF_LAST_FRAME;
                  goto gif_display_end;
            		break;
    	}
    	if(gif_dcb.trailer) 
    	{
    		status = GIF_LAST_FRAME;
    		goto gif_display_end;
    	}
	} while(GIF_src < GIF_end);

   status = GIF_TRUNCATED_FILE;

gif_display_end:	  

	if(status < 0)
		GIF_Reset();	
	if(status == GIF_LAST_FRAME)
	{
		if(s->frame_number > (gif_dcb.frame_counter-1))
			status = GIF_NO_FRAME;
	}	
	*info = gif_dcb.gif_info;
	gif_dcb.state = GIF_STATE_READY;
	DRVPDN_Enable(DRVPDN_CON3,DRVPDN_CON3_GIF,PDN_GIF);						

	return status;
}

#endif // MT6219


