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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
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
kal_uint8 config_video_editor(MMDI_SCENERIO_ID scenario_id, 
                        video_editor_data_path_struct *video_editor_para, 
                              lcd_frame_update_to_mem_struct *lcd_para)                        
{                
   #if defined(DRV_IDP_6228_SERIES)      
      config_video_editor_legacy_series(scenario_id, 
                                            video_editor_para, 
                                            lcd_para);                       
   #elif defined(DRV_IDP_6238_SERIES)      
      config_video_editor_6238_series(scenario_id, 
                                            video_editor_para, 
                                            lcd_para);
   #endif  	            
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
void video_editor_data_path1(MMDI_SCENERIO_ID scenario_id, 
                             video_editor_data_path_struct *video_editor_para, 
                             lcd_frame_update_to_mem_struct *lcd_para,
                             kal_bool enable_effect)                        
{        
   #if defined(DRV_IDP_6228_SERIES)      
      video_editor_data_path1_legacy_series(scenario_id, 
                                            video_editor_para, 
                                            lcd_para,
                                            enable_effect);                       
   #elif defined(DRV_IDP_6238_SERIES)      
      video_editor_data_path1_6238_series(scenario_id, 
                                            video_editor_para, 
                                            lcd_para,
                                            enable_effect);
   #endif  	            
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
void video_editor_data_path2(void)                        
{
   #if defined(DRV_IDP_6228_SERIES)      
      video_editor_data_path2_legacy_series();
   #elif defined(DRV_IDP_6238_SERIES)      
      video_editor_data_path2_6238_series();
   #endif  	         
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
void start_video_editor_data_path(video_editor_data_path_struct *video_editor_para, kal_bool enable_effect)   
{   /* change video editor*/    
   #if defined(DRV_IDP_6228_SERIES)      
      start_video_editor_data_path_legacy_series(video_editor_para, enable_effect);
   #elif defined(DRV_IDP_6238_SERIES)      
      start_video_editor_data_path_6238_series(video_editor_para, enable_effect);
   #endif  	
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
kal_bool is_video_editor_running(void)
{
   #if defined(DRV_IDP_6228_SERIES)      
      return (is_video_editor_running_legacy_series());
   #elif defined(DRV_IDP_6238_SERIES)      
      return (is_video_editor_running_6238_series());
   #endif  	      
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
void reconfig_video_editor(MMDI_SCENERIO_ID scenario_id, 
                           video_editor_data_path_struct *video_editor_para,
                           lcd_frame_update_to_mem_struct *lcd_para)
{   
   #if defined(DRV_IDP_6228_SERIES)      
      reconfig_video_editor_legacy_series(scenario_id, video_editor_para, lcd_para);
   #elif defined(DRV_IDP_6238_SERIES)      
      reconfig_video_editor_6238_series(scenario_id, video_editor_para, lcd_para);
   #endif  	
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
void close_video_editor_data_path(void)
{       
   #if defined(DRV_IDP_6228_SERIES)      
      close_video_editor_data_path_legacy_series();
   #elif defined(DRV_IDP_6238_SERIES)      
      close_video_editor_data_path_6238_series();
   #endif  	
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
void adjustment_contrast_video_editor(kal_uint8 contrast_value)
{
	#if defined(DRV_IDP_6228_SERIES)      
      adjustment_contrast_video_editor_legacy_series(contrast_value);
   #elif defined(DRV_IDP_6238_SERIES)      
      adjustment_contrast_video_editor_6238_series(contrast_value);
   #endif  	
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
void adjustment_brightness_video_editor(kal_uint8 brightness_value)
{
	#if defined(DRV_IDP_6228_SERIES)      
      adjustment_brightness_video_editor_legacy_series(brightness_value);
   #elif defined(DRV_IDP_6238_SERIES)      
      adjustment_brightness_video_editor_6238_series(brightness_value);
   #endif  	
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
void config_video_editor_effect(VIDEO_EDITOR_EFFECT_ENUM effect, kal_uint8 brightness, kal_uint8 contrast)
{
   #if defined(DRV_IDP_6228_SERIES)      
      config_video_editor_effect_legacy_series(effect, brightness, contrast);
   #elif defined(DRV_IDP_6238_SERIES)      
      config_video_editor_effect_6238_series(effect, brightness, contrast);
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
void config_video_decode_effect(VIDEO_DECODE_EFFECT_ENUM effect)
{
   #if defined(DRV_IDP_6228_SERIES)      
      config_video_decode_effect_legacy_series(effect);
   #elif defined(DRV_IDP_6238_SERIES)      
      config_video_decode_effect_6238_series(effect);
   #endif  	
}   


#endif //__VIDEO_EDITOR__


