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
#if defined(MT6238)
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


//#ifdef __VIDEO_EDITOR__
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
kal_uint8 config_video_editor_6238_series(MMDI_SCENERIO_ID scenario_id, 
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
void video_editor_data_path1_6238_series(MMDI_SCENERIO_ID scenario_id, 
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
    
    /* config PRZ */
    {
       RESZ_PRZ_STRUCT prz_struct;
       
       memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
       
       prz_struct.image_src = RESZ_SOURCE_ROTATOR;
       prz_struct.dedicate_memory = KAL_TRUE;       
       prz_struct.continous = KAL_FALSE;          
       prz_struct.int_en = KAL_FALSE;          
       prz_struct.output_to_CRZ = KAL_FALSE;
       prz_struct.output_to_IPP1 = KAL_TRUE;
       prz_struct.output_to_Y2R1 = KAL_FALSE;
       
       prz_struct.coarse_en = KAL_FALSE;
       prz_struct.src_width = video_editor_para->video_src_width;	
       prz_struct.src_height = video_editor_para->video_src_height;	
       prz_struct.tar_width = video_editor_para->video_tar_width;	
       prz_struct.tar_height = video_editor_para->video_tar_height;	       
       prz_struct.work_mem_line = 4;              
       prz_struct.work_mem_addr= 0x40000000;       
                          
       RESZ_PRZConfig(&prz_struct);
    }
    
                        
    /* config IPP1 */
    {
       SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                           IMGPROC_IPP_IO_IPP2_TO_IBW2);
                                 
    }
    if((enable_effect==KAL_TRUE)&&(video_editor_IDP_para.effect_cb!=NULL))
    {
       video_editor_IDP_para.effect_cb();  
    }        
    
    /* config IBW2 */
   {
      IMGDMA_IBW2_STRUCT ibw2_struct;
      
      memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
      
      ibw2_struct.lcd_trigger = KAL_TRUE;                         
      ibw2_struct.direct_couple = KAL_TRUE;                       
      ibw2_struct.int_en = KAL_FALSE;                              
      ibw2_struct.pan = KAL_FALSE;                                 
      ibw2_struct.restart = KAL_FALSE;                             
      ibw2_struct.output_IRT1=KAL_FALSE;                            
                                                                   
      ibw2_struct.width = video_editor_para->video_tar_width;
      ibw2_struct.height = video_editor_para->video_tar_height;
                                                                   
      ibw2_struct.clip_left = 0;                                   
      ibw2_struct.clip_right = video_editor_para->video_tar_width;
      ibw2_struct.clip_top = 0;
      ibw2_struct.clip_bottom = video_editor_para->video_tar_height;
            
      IMGDMA_IBW2Config(&ibw2_struct);
   }
    
   /* config IRT0*/
   {
      IMGDMA_IRT0_STRUCT irt0_struct;
      
      memset(&irt0_struct, 0, sizeof(IMGDMA_IRT0_STRUCT));

      irt0_struct.int_en=KAL_FALSE; /**< enable int or not */
      irt0_struct.restart=KAL_FALSE; /**< restart or not */
      irt0_struct.src_video_dec=KAL_TRUE; /**< video dec or video enc as source */
      irt0_struct.buf_h264=KAL_FALSE; /**< h.264 or mp4 buffer */
      irt0_struct.rotate=IRT0_ROT_OFF; /**< rotate direction */
      irt0_struct.flip=KAL_FALSE; /**< flip or not */
      irt0_struct.bypass=KAL_TRUE; /**< bypass rotate or not */
      irt0_struct.output=IRT0_OUTPUT_PRZ; /**< output module */
      //????? need new interface
      irt0_struct.fifo_base=0; /**< fifo base address */
      irt0_struct.width=video_editor_para->video_src_width; /**< width */
      irt0_struct.height=video_editor_para->video_src_height; /**< height */
      irt0_struct.pix_num=video_editor_para->video_src_width*video_editor_para->video_src_height; /**< total pixel number */
      irt0_struct.fifo_len=8; /**< fifo len */
      
      IMGDMA_IRT0Config(&irt0_struct);
   }
        
    /* config video decode DMA */
   {
      IMGDMA_VIDEO_DECODE_STRUCT video_decode_dma_struct;
      
      memset(&video_decode_dma_struct, 0, sizeof(IMGDMA_VIDEO_DECODE_STRUCT));
      
      video_decode_dma_struct.decode_done_int = KAL_FALSE;                  
      video_decode_dma_struct.y_base_addr = video_editor_para->source_video_y_buffer_address;
      video_decode_dma_struct.u_base_addr = video_editor_para->source_video_u_buffer_address;
      video_decode_dma_struct.v_base_addr = video_editor_para->source_video_v_buffer_address;
      video_decode_dma_struct.width=video_editor_para->video_src_width;; /* decode width */      
      video_decode_dma_struct.height=video_editor_para->video_src_height;; /* decode height */
      video_decode_dma_struct.decode_done_int=KAL_FALSE; /* decode done interrupt */
      video_decode_dma_struct.buf_h264=KAL_FALSE; /* h.264 or mp4 buffer */
      video_decode_dma_struct.flip=KAL_FALSE; /* flip */
      video_decode_dma_struct.bypass_irt0=KAL_TRUE; /* bypass irt0 */
      video_decode_dma_struct.rot=VIDEO_ENCODE_ROT_OFF;
            
      IMGDMA_VIDEODECODE_DMAConfig(&video_decode_dma_struct);
   }
            
    /*config LCD memory output*/    
    lcd_para->memory_data_format=LCD_WMEM_RGB565;     
    lcd_para->fb_update_mode=LCD_DIRECT_COUPLE_MODE;     
    lcd_fb_update_to_memory(lcd_para);    
                
    ENABLE_IPP_Y2R0();
    ENABLE_IMGPROC_HW_IPP();    
    ENABLE_PRZ();        
    ENABLE_IRT0();        
        
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
void video_editor_data_path2_6238_series(void)                        
{
    video_editor_data_path_struct *video_editor_para;
    lcd_frame_update_to_mem_struct *lcd_para;
                         
    if (current_image_data_path_owner != SCENARIO_VIDEO_EDITOR_ID)
    {
        ASSERT(0);        
    }
    // disable path 1 modules
    {
       DISABLE_IPP_Y2R0();
       DISABLE_IMGPROC_HW_IPP();    
       RESET_PRZ;        
       DISABLE_IRT0();          	
    }	
            
    video_editor_is_running=KAL_FALSE;    
    video_editor_para=&video_editor_IDP_para;  
    lcd_para=&video_editor_lcd_para;   
                        
    /* config IBR1 */
    {
       IMGDMA_IBR1_STRUCT ibr1_struct;
     
       memset(&ibr1_struct, 0, sizeof(IMGDMA_IBR1_STRUCT));
     
       ibr1_struct.base_addr = video_editor_para->lcd_buffer_address;
       ibr1_struct.pixel_number = (video_editor_para->video_src_width * video_editor_para->video_src_height);
       ibr1_struct.data_type = IBR1_TYPE_RGB565;
       ibr1_struct.data_order = IBR1_ORDER_BGR888;
       ibr1_struct.int_en = KAL_FALSE;
     
       IMGDMA_IBR1Config(&ibr1_struct);
     }	
    {
    /* config R2Y0 */
    SET_IMGPROC_R2Y0_SRC(IMGPROC_R2Y0_IO_IBR1_TO_R2Y0 | 
                         IMGPROC_R2Y0_IO_R2Y0_TO_PRZ);
   }  
     /* config PRZ */
  {
     RESZ_PRZ_STRUCT prz_struct;
     
     memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
     
     prz_struct.image_src = RESZ_SOURCE_R2Y;
     prz_struct.dedicate_memory = KAL_TRUE;       
     prz_struct.continous = KAL_FALSE;          
     prz_struct.int_en = KAL_FALSE;          
     prz_struct.output_to_CRZ = KAL_FALSE;
     prz_struct.output_to_IPP1 = KAL_TRUE;
     prz_struct.output_to_Y2R1 = KAL_FALSE;
     
     prz_struct.coarse_en = KAL_FALSE;
     prz_struct.src_width = video_editor_para->video_src_width;
     prz_struct.src_height = video_editor_para->video_src_height;
     prz_struct.tar_width = video_editor_para->video_src_width;
     prz_struct.tar_height = video_editor_para->video_src_height;
     
     prz_struct.work_mem_line = 4;          
     prz_struct.work_mem_addr = 0x40000000;
     
                        
     RESZ_PRZConfig(&prz_struct);
  }               
   /* config IPP1 */
  {
     SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                         IMGPROC_IPP_IO_IPP1_TO_OVL);
                               
  }    
	     
   {
     /* config OVL */
     IMGDMA_OVL_STRUCT ovl_struct;
     
     memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
     
     ovl_struct.int_en = KAL_FALSE;
     ovl_struct.restart = KAL_FALSE;
     ovl_struct.pixel_engine = PIXEL_ENGINE_IPP1;
     
     ovl_struct.ouput_jpeg = KAL_FALSE;
     ovl_struct.ouput_drz = KAL_FALSE;
     ovl_struct.output_vdoenc = KAL_TRUE;
     ovl_struct.ouput_y2r0 = KAL_FALSE;
     ovl_struct.ouput_prz = KAL_FALSE;    
     ovl_struct.overlay_frame_mode = KAL_FALSE;
             
     IMGDMA_OVLConfig(&ovl_struct);
  } 
   /* config video encode DMA Write */
  {
     IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
     
     memset(&video_encode_dma_struct, 0, sizeof(IMGDMA_VIDEO_ENCODE_STRUCT));
     
     video_encode_dma_struct.restart = KAL_FALSE;
     video_encode_dma_struct.w_trigger_r = KAL_FALSE;
     video_encode_dma_struct.read_done_int = KAL_FALSE;
     video_encode_dma_struct.wrtie_done_int = KAL_TRUE;//inform video codec
     
     video_encode_dma_struct.y_base_addr1 = (kal_uint32) video_editor_para->target_video_y_buffer_address;
     video_encode_dma_struct.u_base_addr1 = (kal_uint32) video_editor_para->target_video_u_buffer_address;
     video_encode_dma_struct.v_base_addr1 = (kal_uint32) video_editor_para->target_video_v_buffer_address;                                            
     
     video_encode_dma_struct.encode_width = video_editor_para->video_src_width;
     video_encode_dma_struct.encode_height = video_editor_para->video_src_height;
     
     IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);
  }
                
   /*enable all HW module*/
   START_IMGDMA_VIDEO_ENCODE();       
   ENABLE_R2Y0();
   ENABLE_IMGPROC_HW_R2Y0();              
   ENABLE_PRZ();  
   ENABLE_IMGPROC_HW_IPP();            
   START_IBR1();                                  
             
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
void start_video_editor_data_path_6238_series(video_editor_data_path_struct *video_editor_para, kal_bool enable_effect)   
{   /* change video editor*/    
    volatile kal_uint16 i;
    
    ASSERT(video_editor_is_running==KAL_FALSE);  
    {
      /*enable path2 HW module*/
      STOP_IMGDMA_VIDEO_ENCODE();       
      DISABLE_R2Y0();
      DISABLE_IMGPROC_HW_R2Y0();              
      RESET_PRZ;  
      DISABLE_IMGPROC_HW_IPP();            
      STOP_IBR1();      	
    }	
              
    if(main_lcd_operation_state!=LCD_SW_UPDATE_STATE)     
    {
       wait_video_editor_update_flag=KAL_FALSE;    
       video_editor_is_running=KAL_TRUE;
       STOP_IBW2();
       STOP_IMGDMA_VIDEO_DECODE();
              
       video_editor_IDP_para.source_video_y_buffer_address= video_editor_para->source_video_y_buffer_address;
       video_editor_IDP_para.source_video_u_buffer_address= video_editor_para->source_video_u_buffer_address;
       video_editor_IDP_para.source_video_v_buffer_address= video_editor_para->source_video_v_buffer_address;
              
       video_editor_IDP_para.target_video_y_buffer_address= video_editor_para->target_video_y_buffer_address;
       video_editor_IDP_para.target_video_u_buffer_address= video_editor_para->target_video_u_buffer_address;
       video_editor_IDP_para.target_video_v_buffer_address= video_editor_para->target_video_v_buffer_address;
                     
       video_editor_data_path1(SCENARIO_VIDEO_EDITOR_ID, &video_editor_IDP_para, &video_editor_lcd_para, enable_effect);
       
       START_IBW2();
       START_IMGDMA_VIDEO_DECODE();                                                
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
kal_bool is_video_editor_running_6238_series(void)
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
void reconfig_video_editor_6238_series(MMDI_SCENERIO_ID scenario_id, 
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
       lcd_para->fb_update_mode=LCD_DIRECT_COUPLE_MODE;       
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
void close_video_editor_data_path_6238_series(void)
{         
	  
   /*disable all HW module*/
   lcd_stop_hw_update(MAIN_LCD);
   // decode path
   STOP_IMGDMA_VIDEO_DECODE();  
   DISABLE_IRT0();      
   RESET_CRZ();   
   DISABLE_IMGPROC_HW_IPP();
   DISABLE_IPP_Y2R0();   
   STOP_IBW2();
   DISABLE_IRT1();   
   //RGB to YUV path
   STOP_IMGDMA_VIDEO_ENCODE();  
   DISABLE_R2Y0();     
   DISABLE_IMGPROC_HW_R2Y0();              
   RESET_PRZ;  
   DISABLE_IMGPROC_HW_IPP();
   STOP_OVL();            
   STOP_IBR1(); 	  
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
void adjustment_contrast_video_editor_6238_series(kal_uint8 contrast_value)
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
   
   //IMGPROC_SetBrightContrast(SCENARIO_VIDEO_EDITOR_ID, &cba_para);
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
void adjustment_brightness_video_editor_6238_series(kal_uint8 brightness_value)
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
   
   //IMGPROC_SetBrightContrast(SCENARIO_VIDEO_EDITOR_ID, &cba_para);
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
void config_video_editor_effect_6238_series(VIDEO_EDITOR_EFFECT_ENUM effect, kal_uint8 brightness, kal_uint8 contrast)
{   
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
void config_video_decode_effect_6238_series(VIDEO_DECODE_EFFECT_ENUM effect)
{   
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
}   

//#endif /*__VIDEO_EDITOR__*/


#endif /* (defined(MT6238) */


