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
 *   img_comm.c
 *
 * Project:
 * --------
 *    MT6219, MT6226, MT6227, MT6228, MT6229 and MT6230
 *
 * Description:
 * ------------
 *   MT6219, MT6226, MT6227 Resizer, Image processor and Image DMA configuration function
 *   MT6228, MT6229, MT6230 image data path configuration
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(MT6228) || defined(MT6229)|| defined(MT6230)
#include "reg_base.h"
#include "drv_comm.h"
#include "jpeg.h"
#include "visual_comm.h"
#include "visualhisr.h"
#include "imgproc.h" 
#include "resizer.h"
#include "isp_if.h"
#include "image_effect.h"
#include "lcd_if.h"
#include "2d_engine.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "med_status.h"
#include "video_dec_glb.h"
#include "img_comm.h"
#ifdef TV_OUT_SUPPORT
#include "tv_out.h"
#include "upll_ctrl.h"
#endif /*TV_OUT_SUPPORT */ 
#if (defined(ISP_SUPPORT))
#include "ae_awb.h"   
#endif 

#ifdef __VIDEO_EDITOR__
/*video editor backup parameters*/
video_editor_data_path_struct video_editor_IDP_para;
lcd_frame_update_to_mem_struct video_editor_lcd_para; 
kal_bool wait_video_editor_update_flag=KAL_FALSE;
kal_bool video_editor_is_running=KAL_FALSE;

/*****************************************************************************
 * FUNCTION
 *  config_video_editor
 * DESCRIPTION
 *  This function is to set up video editor image data path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/  
kal_uint8 config_video_editor_legacy_series(MMDI_SCENERIO_ID scenario_id, 
                        video_editor_data_path_struct *video_editor_para, 
                              lcd_frame_update_to_mem_struct *lcd_para)                        
{                
    if ((current_image_data_path_owner != scenario_id)||(scenario_id != SCENARIO_VIDEO_EDITOR_ID))
    {
        ASSERT(0);
    }    
    /*back up IDP parameters*/    
    memcpy(&video_editor_IDP_para, video_editor_para, sizeof(video_editor_data_path_struct));
    memcpy(&video_editor_lcd_para, lcd_para, sizeof(lcd_frame_update_to_mem_struct));
    vid_enc_w_cb = video_editor_para->video_cb;
            
    return 0;
}     
/*****************************************************************************
 * FUNCTION
 *  video_editor_data_path1
 * DESCRIPTION
 *  This function is to enable video editor image data path1. 
 *  It could add image effect and overlay 
 *  in this path.
 * PARAMETERS
 *  scenario_id: scenario id 
 *  *video_editor_para: path 1 parameters
 *  lcd_frame_update_to_mem_struct: update to memory parameters
 *  enable_effect: enable effect or not
 * RETURNS
 *  None
 *****************************************************************************/
void video_editor_data_path1_legacy_series(MMDI_SCENERIO_ID scenario_id, 
                             video_editor_data_path_struct *video_editor_para, 
                             lcd_frame_update_to_mem_struct *lcd_para,
                             kal_bool enable_effect)                        
{        
    IMGDMA_VIDEO_DECODE_STRUCT video_decode_dma_struct;    
    IMGDMA_IBW2_STRUCT ibw2_struct;    
    RESZ_PRZ_STRUCT  prz_struct;    
    
    if ((current_image_data_path_owner != scenario_id)||(scenario_id != SCENARIO_VIDEO_EDITOR_ID))
    {
        ASSERT(0);
    }    
    
	 /*XXXXX config PRZ */
	 prz_struct.image_src=RESZ_SOURCE_MPEG4_DECODE_DMA;	
	 prz_struct.dedicate_memory=KAL_TRUE;
	 prz_struct.continous=KAL_FALSE;			
	 prz_struct.int_en=KAL_FALSE;	
	 prz_struct.output_2_IPP=KAL_TRUE;		
	 prz_struct.coarse_en=KAL_FALSE;
	 prz_struct.src_height=video_editor_para->video_src_height;
	 prz_struct.src_width=video_editor_para->video_src_width;	
	 prz_struct.tar_height=video_editor_para->video_tar_height;
	 prz_struct.tar_width=video_editor_para->video_tar_width;	
	 prz_struct.work_mem_line=4;		
    
	 RESZ_PRZConfig(&prz_struct);
    
    /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    //ENABLE_IPP_CONTRAST_BRIGHT;
    SET_IPP_GRAPH_MODE(IPP_VIDEO_MODE);
    
    if((enable_effect==KAL_TRUE)&&(video_editor_IDP_para.effect_cb!=NULL))
    {
       video_editor_IDP_para.effect_cb();  
    }    
    /* XXXXXO config IBW2 */
    ibw2_struct.frame1_base_addr = video_editor_para->lcd_buffer_address;
    ibw2_struct.frame2_base_addr = video_editor_para->lcd_buffer_address;
    ibw2_struct.width = video_editor_para->video_tar_width;
    ibw2_struct.height = video_editor_para->video_tar_height;    
    ibw2_struct.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB565;
    ibw2_struct.pixel_engine = PIXEL_ENGINE_IPP1;        
    ibw2_struct.direct_couple = KAL_FALSE;    
    ibw2_struct.int_en = KAL_FALSE;
    ibw2_struct.pan = KAL_FALSE;
    ibw2_struct.pitch = KAL_FALSE;
    ibw2_struct.restart = KAL_FALSE;
    ibw2_struct.enable_IBW2 = KAL_FALSE;
    ibw2_struct.lcd_trigger = KAL_TRUE;
    ibw2_struct.cb = NULL;    
	 
    IMGDMA_IBW2Config(&ibw2_struct);

    /* XXXXXO config video decode DMA */
    video_decode_dma_struct.decode_done_int = KAL_FALSE;
    video_decode_dma_struct.width = video_editor_para->video_src_width;
    video_decode_dma_struct.height = video_editor_para->video_src_height;
    REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1 = video_editor_para->source_video_y_buffer_address;
    REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1 = video_editor_para->source_video_u_buffer_address;
    REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1 = video_editor_para->source_video_v_buffer_address;
    IMGDMA_VIDEODECODE_DMAConfig(&video_decode_dma_struct);

    /*config LCD memory output*/    
    lcd_para->memory_data_format=LCD_WMEM_RGB565;     
    lcd_para->fb_update_mode=LCD_HW_TRIGGER_MODE;     
    lcd_fb_update_to_memory(lcd_para);        
}
/*****************************************************************************
 * FUNCTION
 *  video_editor_data_path2
 * DESCRIPTION
 *  This function is to enable video editor image data path2. 
 * PARAMETERS
 *  None
 * RETURNS
 *  None
 *****************************************************************************/
void video_editor_data_path2_legacy_series(void)                        
{
    video_editor_data_path_struct *video_editor_para;
    lcd_frame_update_to_mem_struct *lcd_para;
    
     
    RESZ_PRZ_STRUCT prz_struct;     
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_IBR1_STRUCT ibr1_struct;    
    IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
            
    if (current_image_data_path_owner != SCENARIO_VIDEO_EDITOR_ID)
            {
        ASSERT(0);        
            }
    video_editor_is_running=KAL_FALSE;    
    video_editor_para=&video_editor_IDP_para;  
    lcd_para=&video_editor_lcd_para;   
                
    /* XXXXXO config IBR1 */
    ibr1_struct.base_addr = video_editor_para->lcd_buffer_address;
    ibr1_struct.pixel_number = (video_editor_para->video_tar_width * video_editor_para->video_tar_height - 1);
    ibr1_struct.data_type = IBR1_TYPE_RGB565;
    ibr1_struct.data_order = IBR1_ORDER_RGB888;
    ibr1_struct.int_en = KAL_FALSE;

    IMGDMA_IBR1Config(&ibr1_struct);
      
   /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    DISABLE_IPP_INT;
    IPP_CTRL_REG = 0;
    SET_IPP_GRAPH_MODE(IPP_IMGPROC_MODE);//IPP_IMAGE_ENCODE_MODE
    SET_IPP_R2Y_SRC_IMGDMA;       
   
   /*XXXXX config PRZ */
	 prz_struct.image_src=RESZ_SOURCE_IPP;		   
	 prz_struct.dedicate_memory=KAL_TRUE;	
	 prz_struct.continous=KAL_FALSE;			
	 prz_struct.int_en=KAL_FALSE;	
	 prz_struct.output_2_IPP=KAL_FALSE;		
	 prz_struct.coarse_en=KAL_FALSE;
	 prz_struct.src_height=video_editor_para->video_tar_height;
	 prz_struct.src_width=video_editor_para->video_tar_width;	
	 prz_struct.tar_height=video_editor_para->video_tar_height;
	 prz_struct.tar_width=video_editor_para->video_tar_width;	
	 prz_struct.work_mem_line=4;		
	 
	 RESZ_PRZConfig(&prz_struct);
	 
	 /* XXXXXO config IBR2 */
    ibr2_struct.restart = KAL_FALSE;
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_PRZ;    
    ibr2_struct.overlay_frame_mode = KAL_FALSE;
    
    IMGDMA_IBR2Config(&ibr2_struct);
	 
    /* XXXXXO config video encode DMA write */
    video_encode_dma_struct.wdma_pixel_engine = PIXEL_ENGINE_PRZ;
    video_encode_dma_struct.rdma_destination_engine = PIXEL_ENGINE_NONE;
    video_encode_dma_struct.restart = KAL_FALSE;
    video_encode_dma_struct.w_trigger_r = KAL_FALSE;
    video_encode_dma_struct.read_done_int = KAL_FALSE;
    video_encode_dma_struct.wrtie_done_int = KAL_TRUE;/*enable interrupt to inform video encoder*/
    /*we only do once hence we don't need to assign 2nd buffer addr*/
    video_encode_dma_struct.y_base_addr1 = (kal_uint32) video_editor_para->target_video_y_buffer_address;
    video_encode_dma_struct.u_base_addr1 = (kal_uint32) video_editor_para->target_video_u_buffer_address;
    video_encode_dma_struct.v_base_addr1 = (kal_uint32) video_editor_para->target_video_v_buffer_address;

    video_encode_dma_struct.encode_width = video_editor_para->video_tar_width;
    video_encode_dma_struct.encode_height =video_editor_para->video_tar_height;

    IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);    
                
    START_IBR1;          
}
/*****************************************************************************
 * FUNCTION
 *  start_video_editor_data_path
 * DESCRIPTION
 *  This function is to change source and target video buffer address
 * PARAMETERS
 *  video_editor_para: source and target video buffer address
 *  enable_effect: enable effect or not
 * RETURNS
 *  None
 *****************************************************************************/
/*called by video HISR*/
void start_video_editor_data_path_legacy_series(video_editor_data_path_struct *video_editor_para, kal_bool enable_effect)   
{   /* change video editor*/    
    volatile kal_uint16 i;

    ASSERT(video_editor_is_running==KAL_FALSE);    
    
    if(main_lcd_operation_state!=LCD_SW_UPDATE_STATE)     
    {
       wait_video_editor_update_flag=KAL_FALSE;    
       video_editor_is_running=KAL_TRUE;
       STOP_IBW2;
       STOP_IMGDMA_VIDEO_DECODE;
              
       video_editor_IDP_para.source_video_y_buffer_address= video_editor_para->source_video_y_buffer_address;
       video_editor_IDP_para.source_video_u_buffer_address= video_editor_para->source_video_u_buffer_address;
       video_editor_IDP_para.source_video_v_buffer_address= video_editor_para->source_video_v_buffer_address;
              
       video_editor_IDP_para.target_video_y_buffer_address= video_editor_para->target_video_y_buffer_address;
       video_editor_IDP_para.target_video_u_buffer_address= video_editor_para->target_video_u_buffer_address;
       video_editor_IDP_para.target_video_v_buffer_address= video_editor_para->target_video_v_buffer_address;
                     
       video_editor_data_path1(SCENARIO_VIDEO_EDITOR_ID, &video_editor_IDP_para, &video_editor_lcd_para, enable_effect);
       
       START_IBW2;
       START_IMGDMA_VIDEO_DECODE;                                                
       for (i = 0; i < 0x80; i++);
    }
    else
    {
       wait_video_editor_update_flag=KAL_TRUE;
       video_editor_is_running=KAL_FALSE;
    }
}   /* start_video_editor_data_path() */
/*****************************************************************************
 * FUNCTION
 *  is_video_editor_running
 * DESCRIPTION
 *  This function is to check if video editor is running
 * PARAMETERS
 *  None
 * RETURNS
 *  None
 *****************************************************************************/
kal_bool is_video_editor_running_legacy_series(void)
{
   return video_editor_is_running;   
}
    
/*****************************************************************************
 * FUNCTION
 *  reconfig_video_editor
 * DESCRIPTION
 *  This function is to reconfig overlay frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/                  
void reconfig_video_editor_legacy_series(MMDI_SCENERIO_ID scenario_id, 
                           video_editor_data_path_struct *video_editor_para,
                           lcd_frame_update_to_mem_struct *lcd_para)
{   
    if ((current_image_data_path_owner != scenario_id)||(scenario_id != SCENARIO_VIDEO_EDITOR_ID))
    {
        ASSERT(0);
    }    
    /* XXXXXO config overlay frame */
    /*change overlay buffer frame buffer address*/
    
    /*config LCD memory output*/    
    if(lcd_para!=NULL)
    {
       /*apply in the next start*/
       lcd_para->memory_data_format=LCD_WMEM_RGB565; 
       lcd_para->fb_update_mode=LCD_HW_TRIGGER_MODE;       
       memcpy(&video_editor_lcd_para, lcd_para, sizeof(lcd_frame_update_to_mem_struct));              
    }   
}                              
/*****************************************************************************
 * FUNCTION
 *  close_video_editor_data_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  None
 * RETURNS
 *  None
 *****************************************************************************/
void close_video_editor_data_path_legacy_series(void)
{       
    lcd_stop_hw_update(MAIN_LCD);
    STOP_IMGDMA_VIDEO_DECODE;
    STOP_IMGDMA_VIDEO_ENCODE;
    RESET_PRZ;
    STOP_DRZ;
    RESET_IPP;
    DISABLE_IPP;
    STOP_IBW2;
    STOP_IBW3;
    STOP_IBR2;
}   /* close_video_decode_data_path() */

/*****************************************************************************
 * FUNCTION
 *  adjustment_contrast_video_editor
 * DESCRIPTION
 *  This function is to adjust contrast in video editor
 * PARAMETERS
 *  contrast value: contrast value
 * RETURNS
 *  None
 *****************************************************************************/
/*XXXXX TY coding in 2006/08/11*/
/*add image effect in video editor*/
void adjustment_contrast_video_editor_legacy_series(kal_uint8 contrast_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	/* Input data mapping between MMI and driver */
	if(contrast_value<128)
	{
		contrast_value/=4;
	}
	else
	{
		contrast_value=((contrast_value-128)*3/4)+32;	// decrease maximum contrast gain
	}

 	cba_para.contrast=contrast_value;
 	cba_para.bright=(*((volatile unsigned short *) (IMGPROC_BRIADJ1)))&0xFF;
 	cba_para.dark=(*((volatile unsigned short *) (IMGPROC_BRIADJ2)))&0xFF;

	IMGPROC_SetBrightContrast(SCENARIO_VIDEO_EDITOR_ID, &cba_para);
}
/*****************************************************************************
 * FUNCTION
 *  adjustment_brightness_video_editor
 * DESCRIPTION
 *  This function is to adjust brightness in video editor
 * PARAMETERS
 *  brightness value: brightness value
 * RETURNS
 *  None
 *****************************************************************************/
void adjustment_brightness_video_editor_legacy_series(kal_uint8 brightness_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	if(brightness_value>=128)
	{
		cba_para.bright=(brightness_value-128)<<1;
		cba_para.dark=0;
	}
	else
	{
		cba_para.dark=((128-brightness_value)<<1)-1;
		cba_para.bright=0;
	}
	cba_para.contrast=(*((volatile unsigned short *) (IMGPROC_CONADJ)))&0xFF;

	IMGPROC_SetBrightContrast(SCENARIO_VIDEO_EDITOR_ID, &cba_para);
}
/*****************************************************************************
 * FUNCTION
 *  config_video_editor_effect
 * DESCRIPTION
 *  This function is to config image effect in video editor
 * PARAMETERS
 *  effect: image effect
 *  brightness: brightness
 *  contrast: contrast
 * RETURNS
 *  None
 *****************************************************************************/
void config_video_editor_effect_legacy_series(VIDEO_EDITOR_EFFECT_ENUM effect, kal_uint8 brightness, kal_uint8 contrast)
{
   IMGPROC_GAMMA_STRUCT gma_para;
   
   /*config brightness and contrast*/   
   adjustment_contrast_video_editor(brightness);
   adjustment_brightness_video_editor(contrast);
   ENABLE_IPP_CONTRAST_BRIGHT;
   
   switch(effect)
   {
      case VIDEO_EDITOR_EFFECT_GRAYSCALE:
			SET_IPP_HUE_SAT(IMGPROC_HSA_GRAY);
			break;
		case VIDEO_EDITOR_EFFECT_SEPIA:
		   SET_IPP_HUE_SAT(IMGPROC_HSA_COLORIZE);
			DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	      DRV_WriteReg32(IMGPROC_COLORIZEV, 36);
			break;
		case VIDEO_EDITOR_EFFECT_SEPIAGREEN:
			SET_IPP_HUE_SAT(IMGPROC_HSA_COLORIZE);			
			DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	      DRV_WriteReg32(IMGPROC_COLORIZEV, -30);
			break;
		case VIDEO_EDITOR_EFFECT_SEPIABLUE:
			SET_IPP_HUE_SAT(IMGPROC_HSA_COLORIZE);
			DRV_WriteReg32(IMGPROC_COLORIZEU, 88);
	      DRV_WriteReg32(IMGPROC_COLORIZEV, -30);
			break;
		case VIDEO_EDITOR_EFFECT_COLORINV:
		   SET_IPP_HUE_SAT(IMGPROC_HSA_NONE);
			gma_para.gamma=0;
	      gma_para.off0=0;
	      gma_para.off1=0;
	      gma_para.off2=0;
	      gma_para.off3=0;
	      gma_para.off4=0;
	      gma_para.off5=0;
	      gma_para.off6=0;
	      gma_para.off7=0;
	      gma_para.slp0=0x10;
	      gma_para.slp1=0x10;
	      gma_para.slp2=0x10;
	      gma_para.slp3=0x10;
	      gma_para.slp4=0x10;
	      gma_para.slp5=0x10;
	      gma_para.slp6=0x10;
	      gma_para.slp7=0x10;
	      IMGPROC_SetGamma(SCENARIO_VIDEO_EDITOR_ID, &gma_para);
	      
	      ENABLE_IPP_COLOR_INV;
	      ENABLE_IPP_GAMMA_CORRECTION;
			break;		
		case VIDEO_EDITOR_EFFECT_GRAYINV:
		   SET_IPP_HUE_SAT(IMGPROC_HSA_GRAY);
		   ENABLE_IPP_COLOR_INV;
	      break;					
		case VIDEO_EDITOR_EFFECT_NONE:			
		   SET_IPP_HUE_SAT(IMGPROC_HSA_NONE);
		   DISABLE_IPP_GAMMA_CORRECTION;
		   DISABLE_IPP_COLOR_ADJUST;
		   DISABLE_IPP_COLOR_INV;		   
			break;
	   default:
			break;						         
	}		
}
/*****************************************************************************
 * FUNCTION
 *  config_video_decode_effect
 * DESCRIPTION
 *  This function is to config image effect in video decode effect
 * PARAMETERS
 *  effect: image effect
 *  brightness: brightness
 *  contrast: contrast
 * RETURNS
 *  None
 *****************************************************************************/   
void config_video_decode_effect_legacy_series(VIDEO_DECODE_EFFECT_ENUM effect)
{
   IMGPROC_GAMMA_STRUCT gma_para;
           
   switch(effect)
   {
      case VIDEO_DECODE_EFFECT_GRAYSCALE:
			SET_IPP_HUE_SAT(IMGPROC_HSA_GRAY);
			break;
		case VIDEO_DECODE_EFFECT_SEPIA:
		   SET_IPP_HUE_SAT(IMGPROC_HSA_COLORIZE);
			DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	      DRV_WriteReg32(IMGPROC_COLORIZEV, 36);
			break;
		case VIDEO_DECODE_EFFECT_SEPIAGREEN:
			SET_IPP_HUE_SAT(IMGPROC_HSA_COLORIZE);			
			DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	      DRV_WriteReg32(IMGPROC_COLORIZEV, -30);
			break;
		case VIDEO_DECODE_EFFECT_SEPIABLUE:
			SET_IPP_HUE_SAT(IMGPROC_HSA_COLORIZE);
			DRV_WriteReg32(IMGPROC_COLORIZEU, 88);
	      DRV_WriteReg32(IMGPROC_COLORIZEV, -30);
			break;
		case VIDEO_DECODE_EFFECT_COLORINV:
		   SET_IPP_HUE_SAT(IMGPROC_HSA_NONE);
			gma_para.gamma=0;
	      gma_para.off0=0;
	      gma_para.off1=0;
	      gma_para.off2=0;
	      gma_para.off3=0;
	      gma_para.off4=0;
	      gma_para.off5=0;
	      gma_para.off6=0;
	      gma_para.off7=0;
	      gma_para.slp0=0x10;
	      gma_para.slp1=0x10;
	      gma_para.slp2=0x10;
	      gma_para.slp3=0x10;
	      gma_para.slp4=0x10;
	      gma_para.slp5=0x10;
	      gma_para.slp6=0x10;
	      gma_para.slp7=0x10;
	      IMGPROC_SetGamma(SCENARIO_MPEG_DECODE_ID, &gma_para);
	      
	      ENABLE_IPP_COLOR_INV;
	      ENABLE_IPP_GAMMA_CORRECTION;
			break;		
		case VIDEO_DECODE_EFFECT_GRAYINV:
		   SET_IPP_HUE_SAT(IMGPROC_HSA_GRAY);
		   ENABLE_IPP_COLOR_INV;
	      break;					
		case VIDEO_DECODE_EFFECT_NONE:			
		   SET_IPP_HUE_SAT(IMGPROC_HSA_NONE);
		   DISABLE_IPP_GAMMA_CORRECTION;
		   DISABLE_IPP_COLOR_ADJUST;
		   DISABLE_IPP_COLOR_INV;		   
			break;
	   default:
			break;						         
	}		
}   

#endif /*__VIDEO_EDITOR__*/
/*****************************************************************************
 * FUNCTION
 *  config_RGB2YUV420_data_path
 * DESCRIPTION
 *  This function is to translate RGB to YUV 
 * PARAMETERS
 *  scenario_id: scenario id
 *  rgb2yuv420_struct: 
 * RETURNS
 *  None
 *****************************************************************************/
/*XXXXX TY coding in 2006/07/30*/
/*translate RGB888/565 to YUV 420*/
void config_RGB2YUV420_data_path_legacy_series(MMDI_SCENERIO_ID scenario_id, RGB2YUV420_struct  *rgb2yuv420_struct)
{   
    RESZ_PRZ_STRUCT prz_struct;     
    IMGDMA_IBR2_STRUCT ibr2_struct;
    IMGDMA_IBR1_STRUCT ibr1_struct;    
    IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
                      
    /* XXXXXO config IBR1 */
    ibr1_struct.base_addr = rgb2yuv420_struct->src_address;
    ibr1_struct.pixel_number = (rgb2yuv420_struct->src_width * rgb2yuv420_struct->src_height - 1);
    ibr1_struct.data_type = rgb2yuv420_struct->type;
    ibr1_struct.data_order = rgb2yuv420_struct->order;
    ibr1_struct.int_en = KAL_FALSE;

    IMGDMA_IBR1Config(&ibr1_struct);
      
   /* config IPP */
    RESET_IPP;
    ENABLE_IPP;
    DISABLE_IPP_INT;
    IPP_CTRL_REG = 0;
    SET_IPP_GRAPH_MODE(IPP_IMGPROC_MODE);//IPP_IMAGE_ENCODE_MODE
    SET_IPP_R2Y_SRC_IMGDMA;       
   
   /*XXXXX config PRZ */
	 prz_struct.image_src=RESZ_SOURCE_IPP;		   
	 prz_struct.dedicate_memory=KAL_TRUE;	
	 prz_struct.continous=KAL_FALSE;			
	 prz_struct.int_en=KAL_FALSE;	
	 prz_struct.output_2_IPP=KAL_FALSE;		
	 prz_struct.coarse_en=KAL_FALSE;
	 prz_struct.src_height=rgb2yuv420_struct->src_height;
	 prz_struct.src_width=rgb2yuv420_struct->src_width;	
	 prz_struct.tar_height=rgb2yuv420_struct->src_height;
	 prz_struct.tar_width=rgb2yuv420_struct->src_width;	
	 prz_struct.work_mem_line=4;		
    //prz_struct.work_mem_addr=(kal_uint32) intmem_get_buffer((rgb2yuv420_struct->src_width* RESIZER_WORKING_MEM_LINE_NUMBER *3));
	 
	 RESZ_PRZConfig(&prz_struct);
	 
	 /* XXXXXO config IBR2 */
    ibr2_struct.restart = KAL_FALSE;
    ibr2_struct.int_en = KAL_FALSE;
    ibr2_struct.pixel_engine = PIXEL_ENGINE_PRZ;    
    ibr2_struct.overlay_frame_mode = KAL_FALSE;
    
    IMGDMA_IBR2Config(&ibr2_struct);
	 
    /* XXXXXO config video encode DMA write */
    video_encode_dma_struct.wdma_pixel_engine = PIXEL_ENGINE_PRZ;
    video_encode_dma_struct.rdma_destination_engine = PIXEL_ENGINE_NONE;
    video_encode_dma_struct.restart = KAL_FALSE;
    video_encode_dma_struct.w_trigger_r = KAL_FALSE;
    video_encode_dma_struct.read_done_int = KAL_FALSE;
    video_encode_dma_struct.wrtie_done_int = KAL_FALSE;
    /*we only do once hence we don't need to assign 2nd buffer addr*/
    video_encode_dma_struct.y_base_addr1 = (kal_uint32) rgb2yuv420_struct->tar_address;
    video_encode_dma_struct.u_base_addr1 = (kal_uint32) rgb2yuv420_struct->tar_address +
        rgb2yuv420_struct->src_width * rgb2yuv420_struct->src_height;
    video_encode_dma_struct.v_base_addr1 = (kal_uint32) rgb2yuv420_struct->tar_address +
        ((rgb2yuv420_struct->src_width * rgb2yuv420_struct->src_height * 5) >> 2);

    video_encode_dma_struct.encode_width = rgb2yuv420_struct->src_width;
    video_encode_dma_struct.encode_height = rgb2yuv420_struct->src_height;

    IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);    
                
    START_IBR1;  
          
    /*wait until video Encode DMA finish moving data*/
    while (IMGDMA_VIDEO_ENCODE_W_IS_BUSY)
    {
        kal_sleep_task(1);
    };          
}   

/*****************************************************************************
 * FUNCTION
 *  stop_RGB2YUV420_data_path
 * DESCRIPTION
 *  This function is to stop translating RGB to YUV 
 * PARAMETERS
 *  scenario_id: scenario id
 *  rgb2yuv420_struct: 
 * RETURNS
 *  None
 *****************************************************************************/
void stop_RGB2YUV420_data_path_legacy_series(void)
{    
    RESET_PRZ;    
    RESET_IPP;
    DISABLE_IPP;    
    STOP_IBR2;
    STOP_IBR1;
    STOP_IMGDMA_VIDEO_ENCODE;
}   

#endif /* (defined(MT6228) || defined(MT6229))|| defined(MT6230)) */ /* MT6228, MT6229 */


