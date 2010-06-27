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
 *   isp_if.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6226M,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   This file is intends for ISP driver.
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
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h" 
#include "drv_comm.h"
#include "stdio.h"
#include "string.h"
#include "IntrCtrl.h"
#include "gpio_sw.h"
#include "jpeg.h"
#include "exif.h"
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "img_comm.h"
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
#include "sccb.h"
#include "isp_if.h"
#include "med_api.h"
#include "image_effect.h"
#if (defined(ISP_SUPPORT))
#include "image_sensor.h"
#include "camera_para.h"
#endif
#include "ae_awb.h"
#include "af.h"
#include "imgproc.h"
#include "resizer.h"
#include "isp_device_if.h"
#if (defined(YUV_SENSOR_SUPPORT))
#include "isp_yuv_if.h"
#endif
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
#include "lens_module.h"
#endif

#include "med_status.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#include "tv_out.h"
#endif
#if (!defined(DRV_ISP_6219_SERIES))
#include "isp_flashlight.h"
#endif
#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
#endif  // END_OF_WEBCAM_SUPPORT

#ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
   #include "SST_sla.h"
#endif

kal_bool ae_counting_flag=KAL_TRUE;

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);

extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
extern void video_enc_reset_buffer_counter(void);
extern void isp_ibw2_cb(void);

#if defined(ANALOG_TV_SUPPORT)
extern kal_bool mmi_get_analog_tv_current_state(void);
#endif

kal_uint8	isp_sleep_mode_handler=0xFF;
#if ((!defined(DRV_ISP_6219_SERIES))&&defined(ISP_SUPPORT))
extern ae_lut_info_struct lut_info;
#endif
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
extern camera_preview_data_path_struct			ipp_preview_data;
#endif

kal_uint8 ae_count=0;
kal_uint8 hist_idx=0;
kal_uint8	camera_system_operation_mode=CAMERA_SYSTEM_NORMAL_MODE;
kal_uint32 isp_frame_count=0;

#if defined(ANALOG_TV_SUPPORT)
kal_bool isp_in_idle_int=KAL_FALSE;
#endif

kal_eventgrpid camera_isp_event_id=NULL;
volatile kal_uint32 isp_int_status;
kal_uint16 isp_tg_delay_lines=0;
kal_bool tg_interrupt_flag=KAL_FALSE;

kal_bool wait_first_frame_flag=KAL_TRUE;
kal_bool isp_first_preview_frame=KAL_TRUE;
volatile kal_uint8 isp_preview_2a_enable=0;
kal_uint8 isp_preview_frame=0;
kal_uint16 isp_frame_period;
kal_uint16 image_setting_index=0;
kal_bool awb_enable_flag_backup=KAL_TRUE;
kal_bool ae_enable_flag_backup=KAL_TRUE;
kal_uint8 ae_hw_frame_count_backup[2]={1,1};
image_sensor_func_struct *image_sensor_func;
kal_uint16 image_sensor_width,image_sensor_height;

lens_func_struct *lens_func;
#if (defined(AF_SUPPORT))
#if (defined(YUV_SENSOR_SUPPORT))
kal_uint8 yuv_af_status;
kal_uint8 yuv_af_check_count=0;
#else
kal_int8 lens_err_check=1;
kal_uint8 af_next_step_idx=0;
kal_uint8 af_count=0;
kal_uint16 af_next_detail_pos;
#endif
#endif
kal_uint32	vd_blanking_lines = 0;
kal_uint32 time_tick_buff[10];
kal_uint32 time_tick;

const kal_uint8 sine_lut[91]={	 0, 1, 2, 3, 4, 6, 7, 8, 9,10,
											11,12,13,14,15,17,18,19,20,21,
											22,23,24,25,26,27,28,29,30,31,
											32,33,34,35,36,37,38,39,39,40,
											41,42,43,44,44,45,46,47,48,48,
											49,50,50,51,52,52,53,54,54,55,
											55,56,57,57,58,58,58,59,59,60,
											60,61,61,61,62,62,62,62,63,63,
											63,63,63,64,64,64,64,64,64,64,
											64};

/*************************************************************************
* FUNCTION
*	camera_isp_LISR
*
* DESCRIPTION
*	Entry function of ISP LISR
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void camera_isp_LISR(void)
{
#if (defined(ISP_SUPPORT))
	kal_uint32 int_status;
	kal_uint32 save_irq_mask;

	save_irq_mask=SaveAndSetIRQMask();
	IRQMask(IRQ_CAMERA_CODE);
	isp_frame_count++;
	int_status=DRV_Reg32(ISP_INT_STATUS_REG);
	isp_int_status=0;
	RestoreIRQMask(save_irq_mask);
	if (int_status & REG_CAMERA_INT_FRAME_READY_ENABLE_BIT)
	{
#if (defined(DRV_ISP_6228_SERIES))
		if(tg_interrupt_flag==KAL_TRUE)
		{
			ENABLE_CAMERA_TG_DONE_INT;	
#if (defined(WEBCAM_SUPPORT))
/* For WEBCAM MT6228+TG sync AE/AWB frame ready and jpeg encode interrupt sync */
			usbvideo_camera_fr_flag = KAL_TRUE;
#endif
		}
#endif		
#if (!defined(DRV_ISP_6225_SERIES))
		/* Accumulation for AWB */
		Acc_R=REG_ISP_OPD_Y_RESULT;
		Acc_G=REG_ISP_OPD_MG_RESULT;
		Acc_B=REG_ISP_OPD_RB_RESULT;
		Acc_Cnt=REG_ISP_OPD_PIXEL_COUNT;
#endif		
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))		
		/* Focus Value for AF */
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))		
		AF_Result0=REG_ISP_ATF_RESULT1;
		AF_Result1=REG_ISP_ATF_RESULT2;
		AF_Result2=REG_ISP_ATF_RESULT3;
		AF_Result3=REG_ISP_ATF_RESULT4;
		AF_Result4=REG_ISP_ATF_RESULT5;
#elif (defined(DRV_ISP_6228_SERIES))
		AF_Result0=REG_ISP_AF_RESULT1;
		AF_Result1=REG_ISP_AF_RESULT2;
		AF_Result2=REG_ISP_AF_RESULT3;
		AF_Result3=REG_ISP_AF_RESULT4;
		AF_Result4=REG_ISP_AF_RESULT5;
#endif	
		AF_frame_VD_log();		
#endif
		
#if (defined(DRV_ISP_6219_SERIES))
		/* Luminance for AE */
		lum[0]=REG_ISP_AE_WINDOW1_RESULT;
		lum[1]=REG_ISP_AE_WINDOW2_RESULT;
		lum[2]=REG_ISP_AE_WINDOW3_RESULT;
		lum[3]=REG_ISP_AE_WINDOW4_RESULT;
		lum[4]=REG_ISP_AE_WINDOW5_RESULT;
		lum[5]=REG_ISP_AE_WINDOW6_RESULT;
		lum[6]=REG_ISP_AE_WINDOW7_RESULT;
		lum[7]=REG_ISP_AE_WINDOW8_RESULT;
		lum[8]=REG_ISP_AE_WINDOW9_RESULT;
	
		/* Histogram for Flare */
		histogram[0]=REG_ISP_AE_A_NUMBER_RESULT;
		histogram[1]=REG_ISP_AE_B_NUMBER_RESULT;
		histogram[2]=REG_ISP_AE_C_NUMBER_RESULT;
		histogram[3]=REG_ISP_AE_D_NUMBER_RESULT;
		histogram[4]=REG_ISP_AE_E_NUMBER_RESULT;
#endif		

 #if defined(ANALOG_TV_SUPPORT) 
            if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
		{
                    if(isp_in_idle_int==KAL_FALSE)
                    {
                  
                        isp_in_idle_int=KAL_TRUE;
			ENABLE_CAMERA_IDLE_INT;
			DISABLE_VIEW_FINDER_MODE;
	             }
	        }
            else
            	{
 #endif
		if (isp_digital_zoom_flag==KAL_TRUE)
		{
			ENABLE_CAMERA_IDLE_INT;
#if (defined(DRV_ISP_6219_SERIES))
			if (isp_operation_state==ISP_MPEG4_ENCODE_STATE)
				ENABLE_IBW2_INT;
#endif
			DISABLE_VIEW_FINDER_MODE;
#if (defined(DRV_ISP_6219_SERIES))
			if(ae_count==camera_oper_data.ae_setting_cal_delay_frame)
			{
				ae_count++;
				ae_count%=camera_oper_data.ae_awb_cal_period;
			}
#endif
		}
 #if defined(ANALOG_TV_SUPPORT) 
                }
#endif
		isp_int_status |= ISP_INT_FRAME_READY;
	}

	if (int_status & REG_CAMERA_INT_IDLE_ENABLE_BIT)
	{
		isp_idle_done_flag=KAL_TRUE;
		isp_int_status |= ISP_INT_IDLE;

	   #if defined(ANALOG_TV_SUPPORT) 
            if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
               {
                    DISABLE_CMOS_SESNOR;
		    #if defined(__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__)			
			if (isp_operation_state==ISP_MPEG4_ENCODE_STATE)
			{
                      kal_uint16 pixel_count,line_count;
        		  pixel_count=*(volatile unsigned int *) 0x80690428;
        		  line_count=*(volatile unsigned int *) 0x8069042C;
			  ENABLE_IBW2_INT;
			  if((!IMGDMA_IBW2_IS_BUSY)||((pixel_count==0)&&(line_count==0)))
                       {
				  isp_ibw2_cb();		/* for zoom setting */
			   }
			 }
		    #endif 	/*__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__*/		   
	       }
            else
	   	{
	   #endif			
		if (isp_digital_zoom_flag==KAL_TRUE)
		{
			DISABLE_CMOS_SESNOR;
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
			if (isp_operation_state==ISP_MPEG4_ENCODE_STATE)
			{
#ifndef __SYNC_LCM_SW_SUPPORT__
#if (defined(DRV_ISP_6227_SERIES))
        	    kal_uint16 pixel_count,line_count;	    
        		pixel_count=*(volatile unsigned int *) 0x80690428;
        		line_count=*(volatile unsigned int *) 0x8069042C;			    
				ENABLE_IBW2_INT;				
				if((!IMGDMA_IBW2_IS_BUSY)||((pixel_count==0)&&(line_count==0)))
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#if(defined(MT6238))
				ENABLE_IBW2_INT();
#else				
				ENABLE_IBW2_INT;
#endif				
				if(!IMGDMA_IBW2_IS_BUSY)
#endif				
				{
					isp_ibw2_cb();		/* for zoom setting */		
				}
			}
#if defined(__3G_VIDEO_CALL__) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__3G_VIDEO_CALL__*/
#else
				if ((sync_lcm_enable_mode==KAL_TRUE)&&(video_encode_dc_flag==KAL_TRUE))
					isp_ibw2_cb();
				else
				{
#if (defined(DRV_ISP_6227_SERIES))
        	    kal_uint16 pixel_count,line_count;
        		pixel_count=*(volatile unsigned int *) 0x80690428;
        		line_count=*(volatile unsigned int *) 0x8069042C;
				ENABLE_IBW2_INT;
				if((!IMGDMA_IBW2_IS_BUSY)||((pixel_count==0)&&(line_count==0)))
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#if(defined(MT6238))
				ENABLE_IBW2_INT();
#else				
				ENABLE_IBW2_INT;
#endif				
				if(!IMGDMA_IBW2_IS_BUSY)
#endif
				{
					isp_ibw2_cb();		/* for zoom setting */
				}
			}
			}
#endif /* __SYNC_LCM_SW_SUPPORT__ */
#endif				
		}
#if defined(ANALOG_TV_SUPPORT) 
                }
#endif
	}
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
	if (int_status & REG_CAMERA_INT_ISP_DONE_ENABLE_BIT)
	{
		isp_int_status |= ISP_INT_ISP_DONE;
      #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
         isp_int_status &= ~ISP_INT_ISP_DONE;
		   SLA_HWLogging("ISP", SA_stop);
      #endif
	}

	if (int_status & REG_CAMERA_INT_AE_DONE_ENABLE_BIT)
	{
		isp_int_status |= ISP_INT_AE_DONE;
	}

	if (int_status & REG_CAMERA_INT_ATF_DONE_ENABLE_BIT)
	{
		isp_int_status |= ISP_INT_ATF_DONE;
	}

	if (((int_status & REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT)!= 0)
		&&((REG_ISP_INT_ENABLE & REG_CAMERA_INT_FLASH_SEL_ENABLE_BIT)== 0))
	{
		//frame rate check
		time_tick_buff[time_tick]=drv_get_current_time();
		time_tick++;
		time_tick%=10;

#if (defined(DRV_ISP_6227_SERIES))
		//Avoid ae get accumulation frame
		if(AE_FRAME_COUNT==1)
		{						
		/* Luminance for AE */
		lum[0]=REG_ISP_AE_WINDOW1_RESULT;
		lum[1]=REG_ISP_AE_WINDOW2_RESULT;
		lum[2]=REG_ISP_AE_WINDOW3_RESULT;
		lum[3]=REG_ISP_AE_WINDOW4_RESULT;
		lum[4]=REG_ISP_AE_WINDOW5_RESULT;
		lum[5]=REG_ISP_AE_WINDOW6_RESULT;
		lum[6]=REG_ISP_AE_WINDOW7_RESULT;
		lum[7]=REG_ISP_AE_WINDOW8_RESULT;
		lum[8]=REG_ISP_AE_WINDOW9_RESULT;
	
		/* Histogram for Flare */
		histogram[0]=REG_ISP_AE_A_NUMBER_RESULT;
		histogram[1]=REG_ISP_AE_B_NUMBER_RESULT;
		histogram[2]=REG_ISP_AE_C_NUMBER_RESULT;
		histogram[3]=REG_ISP_AE_D_NUMBER_RESULT;
		histogram[4]=REG_ISP_AE_E_NUMBER_RESULT;
			ae_counting_flag=KAL_TRUE;
		}
		else
			ae_counting_flag=KAL_FALSE;
#endif			
		ae_hw_frame_count_backup[1]=ae_hw_frame_count_backup[0];
		ae_hw_frame_count_backup[0]=AE_FRAME_COUNT;
		isp_int_status |= ISP_INT_TG_DONE;
	}

	if (((int_status & REG_CAMERA_INT_FLASH_DONE_ENABLE_BIT)!= 0)
		&&((REG_ISP_INT_ENABLE & REG_CAMERA_INT_FLASH_SEL_ENABLE_BIT)!= 0))
	{
		//frame rate check
		time_tick_buff[time_tick]=drv_get_current_time();
		time_tick++;
		time_tick%=10;

#if (defined(DRV_ISP_6227_SERIES))
		//Avoid ae get accumulation frame
		if(AE_FRAME_COUNT==1)
		{						
		/* Luminance for AE */
		lum[0]=REG_ISP_AE_WINDOW1_RESULT;
		lum[1]=REG_ISP_AE_WINDOW2_RESULT;
		lum[2]=REG_ISP_AE_WINDOW3_RESULT;
		lum[3]=REG_ISP_AE_WINDOW4_RESULT;
		lum[4]=REG_ISP_AE_WINDOW5_RESULT;
		lum[5]=REG_ISP_AE_WINDOW6_RESULT;
		lum[6]=REG_ISP_AE_WINDOW7_RESULT;
		lum[7]=REG_ISP_AE_WINDOW8_RESULT;
		lum[8]=REG_ISP_AE_WINDOW9_RESULT;
	
		/* Histogram for Flare */
		histogram[0]=REG_ISP_AE_A_NUMBER_RESULT;
		histogram[1]=REG_ISP_AE_B_NUMBER_RESULT;
		histogram[2]=REG_ISP_AE_C_NUMBER_RESULT;
		histogram[3]=REG_ISP_AE_D_NUMBER_RESULT;
		histogram[4]=REG_ISP_AE_E_NUMBER_RESULT;
			ae_counting_flag=KAL_TRUE;
		}
		else
			ae_counting_flag=KAL_FALSE;
#endif
		ae_hw_frame_count_backup[1]=ae_hw_frame_count_backup[0];
		ae_hw_frame_count_backup[0]=AE_FRAME_COUNT;
		isp_int_status |= ISP_INT_VD_DONE;
      #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
		   SLA_HWLogging("ISP", SA_start);
		   SLA_HWLogging("BW2", SA_start);
      #endif
	}
#elif (defined(DRV_ISP_6228_SERIES))
	if (int_status & REG_CAMERA_INT_ISP_DONE_ENABLE_BIT)
	{
		isp_int_status |= ISP_INT_ISP_DONE;
      #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
         isp_int_status &= ~ISP_INT_ISP_DONE;
		   SLA_HWLogging("ISP", SA_stop);
      #endif
	}

	if (int_status & REG_CAMERA_INT_AE_DONE_ENABLE_BIT)
	{
		isp_int_status |= ISP_INT_AE_DONE;
	}

	if (int_status & REG_CAMERA_INT_ATF_DONE_ENABLE_BIT)
	{
		isp_int_status |= ISP_INT_ATF_DONE;
	}

	if (((int_status & REG_CAMERA_INT_TG_DONE_ENABLE_BIT)!= 0)
		&&((REG_ISP_INT_ENABLE & REG_CAMERA_INT_VSYNC_ENABLE_BIT)== 0))
	{
		DISABLE_CAMERA_TG_DONE_INT;  // Turn off TG interrupt to prevent continous trigger in specific line period
		
#if (defined(WEBCAM_SUPPORT))
/* For WEBCAM MT6228+TG sync AE/AWB frame ready and jpeg encode interrupt sync */
		usbvideo_camera_fr_flag = KAL_FALSE;
#endif
		ae_hw_frame_count_backup[1]=ae_hw_frame_count_backup[0];
		ae_hw_frame_count_backup[0]=AE_FRAME_COUNT;
		isp_int_status |= ISP_INT_TG_DONE;
	}

	if (((int_status & REG_CAMERA_INT_TG_DONE_ENABLE_BIT)!= 0)
		&&((REG_ISP_INT_ENABLE & REG_CAMERA_INT_VSYNC_ENABLE_BIT)!= 0))
	{
		ae_hw_frame_count_backup[1]=ae_hw_frame_count_backup[0];
		ae_hw_frame_count_backup[0]=AE_FRAME_COUNT;
		isp_int_status |= ISP_INT_VD_DONE;
      #ifdef IMAGE_DATA_PATH_TIMING_ANALYSIS
		   SLA_HWLogging("ISP", SA_start);
		   SLA_HWLogging("BW2", SA_start);
      #endif
	}
#endif
	if (isp_int_status!=0)
	{
		visual_active_hisr(VISUAL_CAMERA_HISR_ID);
	}
	else
	{
		IRQUnmask(IRQ_CAMERA_CODE);
	}
#endif
}	/* isp_LISR() */

/*************************************************************************
* FUNCTION
*	camera_isp_HISR
*
* DESCRIPTION
*	Entry function of ISP HISR
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void camera_isp_HISR(void)
{
#if (defined(ISP_SUPPORT))
	if (isp_int_status & ISP_INT_IDLE)
	{
		#if defined(ANALOG_TV_SUPPORT)&&!defined(__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__) 
                 if(mmi_get_analog_tv_current_state()==KAL_TRUE)		 	
             	{
			#if   (!defined(MT6225) )  //remove by hongzhe.liu      	
		   SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
		   SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
		   RESZ_Stop(SCENARIO_CAMERA_PREVIEW_ID);
				stop_image_dma(SCENARIO_CAMERA_PREVIEW_ID);  //forrest
				IMGDMA_Close(SCENARIO_CAMERA_PREVIEW_ID);   //forrest	   
   		   STOP_LCD_TRANSFER;
   		   START_LCD_TRANSFER;
		   config_image_dma(SCENARIO_CAMERA_PREVIEW_ID,isp_preview_config_data.target_width,
			   							  isp_preview_config_data.target_height);   //forrest		   
		   RESZ_SetSize(isp_preview_config_data.source_width,isp_preview_config_data.source_height,
								 isp_preview_config_data.target_width,isp_preview_config_data.target_height,
								 SCENARIO_CAMERA_PREVIEW_ID);
		   RESZ_Start(SCENARIO_CAMERA_PREVIEW_ID);
                   ENABLE_CMOS_SESNOR;
		   DISABLE_CAMERA_IDLE_INT;
		   ENABLE_VIEW_FINDER_MODE;
		   isp_in_idle_int=KAL_FALSE;
			#else // defined(MT6225)=TRUE . add by hongzhe.liu
				SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
				SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
				DISABLE_VERTICAL_SUB_SAMPLE;
				DISABLE_HORIZONTAL_SUB_SAMPLE;	
				SET_HSUB_SRC_SIZE(isp_grab_width);
				SET_VSUB_SRC_SIZE(isp_grab_height);
				SET_HSUB_DST_SIZE(isp_preview_config_data.source_width);
				SET_VSUB_DST_SIZE(isp_preview_config_data.source_height);
				RESZ_Stop(SCENARIO_CAMERA_PREVIEW_ID);
	   			STOP_LCD_TRANSFER;   			
		 		START_LCD_TRANSFER;
		   
				RESZ_SetSize(isp_preview_config_data.source_width,isp_preview_config_data.source_height,
									 isp_preview_config_data.target_width,isp_preview_config_data.target_height,
									 SCENARIO_CAMERA_PREVIEW_ID);
				RESZ_Start(SCENARIO_CAMERA_PREVIEW_ID);
				ENABLE_CMOS_SESNOR;
				DISABLE_CAMERA_IDLE_INT;
				ENABLE_VIEW_FINDER_MODE;
				SET_CAMERA_PREVIEW_MODE;
				SET_CAMERA_FRAME_RATE(2);
			       isp_in_idle_int=KAL_FALSE;
			#endif	// (!defined(MT6225) )  add by hongzhe.liu
             	}
		else   
	   	{
	   #endif /*ANALOG_TV_SUPPORT*/			

		if (isp_digital_zoom_flag==KAL_TRUE)
		{
	   	if (isp_operation_state==ISP_PREVIEW_STATE)
			{
#if (defined(YUV_SENSOR_SUPPORT))
				SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
				SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
#else
				SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
				SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
				ae_config((isp_grab_width*isp_horizontal_subsample),(isp_grab_height*isp_vertical_subsample));
#endif /* YUV_SENSOR_SUPPORT */
#if (defined(DRV_ISP_6219_SERIES))
				SET_SUB_SAMPLE_MODE(isp_sub_sample_mode);
				RESZ_Stop(SCENARIO_CAMERA_PREVIEW_ID);
				stop_image_dma(SCENARIO_CAMERA_PREVIEW_ID);
				IMGDMA_Close(SCENARIO_CAMERA_PREVIEW_ID);
   			STOP_LCD_TRANSFER;
   			START_LCD_TRANSFER;
				config_image_dma(SCENARIO_CAMERA_PREVIEW_ID,isp_preview_config_data.target_width,
									  isp_preview_config_data.target_height);
				RESZ_SetSize(isp_preview_config_data.source_width,isp_preview_config_data.source_height,
								 isp_preview_config_data.target_width,isp_preview_config_data.target_height,
								 SCENARIO_CAMERA_PREVIEW_ID);
				RESZ_Start(SCENARIO_CAMERA_PREVIEW_ID);
#elif (defined(DRV_ISP_6227_SERIES))
				ENABLE_VERTICAL_SUB_SAMPLE;
				ENABLE_HORIZONTAL_SUB_SAMPLE;
				SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));
				SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
				SET_HSUB_DST_SIZE(isp_preview_config_data.source_width);
				SET_VSUB_DST_SIZE(isp_preview_config_data.source_height);
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))	
				af_zone_setting(dsc_status.af.metering);
#endif
				RESZ_Stop(SCENARIO_CAMERA_PREVIEW_ID);
				stop_image_dma(SCENARIO_CAMERA_PREVIEW_ID);
				IMGDMA_Close(SCENARIO_CAMERA_PREVIEW_ID);
   			STOP_LCD_TRANSFER;
			#ifndef __SYNC_LCM_SW_SUPPORT__
   			START_LCD_TRANSFER;
   		#else
   			if (sync_lcm_enable_mode==KAL_FALSE)
   			{
	   			STOP_LCD_TRANSFER;
	   			START_LCD_TRANSFER;
   			}
   		#endif
				config_image_dma(SCENARIO_CAMERA_PREVIEW_ID,isp_preview_config_data.target_width,
									  isp_preview_config_data.target_height);
				RESZ_SetSize(isp_preview_config_data.source_width,isp_preview_config_data.source_height,
								 isp_preview_config_data.target_width,isp_preview_config_data.target_height,
								 SCENARIO_CAMERA_PREVIEW_ID);
				RESZ_Start(SCENARIO_CAMERA_PREVIEW_ID);
#elif (defined(DRV_ISP_6225_SERIES))
				DISABLE_VERTICAL_SUB_SAMPLE;
				DISABLE_HORIZONTAL_SUB_SAMPLE;	
				SET_HSUB_SRC_SIZE(isp_grab_width);
				SET_VSUB_SRC_SIZE(isp_grab_height);
				SET_HSUB_DST_SIZE(isp_preview_config_data.source_width);
				SET_VSUB_DST_SIZE(isp_preview_config_data.source_height);
				RESZ_Stop(SCENARIO_CAMERA_PREVIEW_ID);
   			STOP_LCD_TRANSFER;   			
				RESZ_SetSize(isp_preview_config_data.source_width,isp_preview_config_data.source_height,
								 isp_preview_config_data.target_width,isp_preview_config_data.target_height,
								 SCENARIO_CAMERA_PREVIEW_ID);
				RESZ_Start(SCENARIO_CAMERA_PREVIEW_ID);
				RESZ_start_zoom();
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
				ENABLE_VERTICAL_SUB_SAMPLE;
				ENABLE_HORIZONTAL_SUB_SAMPLE;
				SET_HSUB_SRC_SIZE((isp_grab_width*isp_horizontal_subsample));
				SET_VSUB_SRC_SIZE((isp_grab_height*isp_vertical_subsample));
				SET_HSUB_DST_SIZE(isp_preview_config_data.source_width);
				SET_VSUB_DST_SIZE(isp_preview_config_data.source_height);
				reconfig_camera_preview_data_path(SCENARIO_CAMERA_PREVIEW_ID,&ipp_preview_data);
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))	
				af_zone_setting(dsc_status.af.metering);
#endif
#endif	
				if(isp_fast_zoom_data.start==KAL_FALSE)
				{
					isp_digital_zoom_flag=KAL_FALSE;
				}
				ENABLE_CMOS_SESNOR;
				DISABLE_CAMERA_IDLE_INT;
				ENABLE_VIEW_FINDER_MODE;
			}

#if (defined(DRV_ISP_6225_SERIES))			
	   	if (isp_operation_state==ISP_MJPEG_ENCODE_STATE)
			{
				SET_YUV_TG_GRAB_PIXEL(isp_grab_start_x,isp_grab_width);
				SET_YUV_TG_GRAB_LINE(isp_grab_start_y,isp_grab_height);
				DISABLE_VERTICAL_SUB_SAMPLE;
				DISABLE_HORIZONTAL_SUB_SAMPLE;	
				SET_HSUB_SRC_SIZE(isp_grab_width);
				SET_VSUB_SRC_SIZE(isp_grab_height);
				SET_HSUB_DST_SIZE(mjpeg_encode_data.source_width);
				SET_VSUB_DST_SIZE(mjpeg_encode_data.source_height);
				RESZ_Stop(SCENARIO_MJPEG_ENCODE_ID);
   			STOP_LCD_TRANSFER;
				RESZ_SetSize(mjpeg_encode_data.source_width,mjpeg_encode_data.source_height,
								 mjpeg_encode_data.target_width,mjpeg_encode_data.target_height,
								 SCENARIO_MJPEG_ENCODE_ID);
				RESZ_Start(SCENARIO_MJPEG_ENCODE_ID);
				RESZ_start_zoom();
				if(isp_fast_zoom_data.start==KAL_FALSE)
				{
					isp_digital_zoom_flag=KAL_FALSE;
				}
				ENABLE_CMOS_SESNOR;
				DISABLE_CAMERA_IDLE_INT;
				ENABLE_VIEW_FINDER_MODE;
			}
#endif
		}
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))			
      else if(flashlight_operation_state == FLASHLIGHT_TRIGGER_STATE)
      {   // Flash Light Control        
         flashlight_hisr();
      }    					
#endif

#if defined(ANALOG_TV_SUPPORT)&&!defined(__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__) 
}
#endif

	   kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR);
		IRQUnmask(IRQ_CAMERA_CODE);
	
		/* Fast Zoom In Config */
		if(isp_fast_zoom_data.start==KAL_TRUE)
		{
			if(fast_zoom_count==isp_fast_zoom_data.zoom_speed+1)
			{
				if(isp_fast_zoom_data.zoom_in==KAL_TRUE)
				{
					if((isp_digital_zoom_factor+isp_fast_zoom_data.zoom_step)<=isp_fast_zoom_data.zoom_limit)
					{
						isp_digital_zoom((kal_uint8)(isp_digital_zoom_factor+isp_fast_zoom_data.zoom_step));
						fast_zoom_count=0;
					}
				}
				else
				{
					if((isp_digital_zoom_factor-isp_fast_zoom_data.zoom_step)>=10)
					{
						isp_digital_zoom((kal_uint8)(isp_digital_zoom_factor-isp_fast_zoom_data.zoom_step));
						fast_zoom_count=0;
					}
					else
					{
						isp_fast_zoom_data.start=KAL_FALSE;
						isp_fast_zoom_setting(isp_fast_zoom_data);
					}
				}
			}		
			fast_zoom_count++;
		}
	}

#if (defined(YUV_SENSOR_SUPPORT))
	if ((isp_int_status & ISP_INT_VD_DONE)||(isp_int_status & ISP_INT_TG_DONE))
	{
#if (defined(WEBCAM_SUPPORT))
        if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
        {
            if(usbvideo_attr_setting_PU_index!=0)
                usbvideo_camera_effect_background_setting_attr();		
        }
#endif
#if (defined(AF_SUPPORT))
		if(isp_operation_state==ISP_PREVIEW_STATE)
		{
			if(af_operation_state==AF_SEARCH_STATE)
			{
				yuv_af_status=image_sensor_func->yuv_sensor_setting(CAM_PARAM_YUV_AF_STATUS,0);
				if(yuv_af_status==AF_BUSY)
					yuv_af_check_count++;
				else
				{
					if(yuv_af_status==AF_SEARCH_SUCCESS)
						isp_preview_config_data.cam_focus_cb(1);	/* Inform MMI AF Success Zone */
					else
						isp_preview_config_data.cam_focus_cb(0xFF);	/* Inform MMI AF Fail */
					af_operation_state=AF_FREEZE_STATE;
				}
				if(yuv_af_check_count>camera_oper_data.yuv_af_timeout_frame)
				{
					isp_preview_config_data.cam_focus_cb(0xFF);
					af_operation_state=AF_FREEZE_STATE;
				}
			}
        }
#endif
		if ((image_setting_index!=0)&&(isp_operation_state!=ISP_STANDBY_STATE)&&(stack_query_boot_mode()!=FACTORY_BOOT))
			background_image_setting();		
		if(wait_first_frame_flag==KAL_TRUE)
		{
			isp_preview_frame++;
			if(isp_preview_frame==camera_oper_data.preview_delay_frame)
			{
				kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR);
				wait_first_frame_flag=KAL_FALSE;
			}
		}
		else
			kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR);
	}
	IRQUnmask(IRQ_CAMERA_CODE);
#else /* !(YUV_SENSOR_SUPPORT) */

#if defined(ANALOG_TV_SUPPORT)      
    if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
   {

	if ((isp_int_status & ISP_INT_VD_DONE)||(isp_int_status & ISP_INT_TG_DONE))
	{
#if (defined(WEBCAM_SUPPORT))
        if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
        {
            if(usbvideo_attr_setting_PU_index!=0)
                usbvideo_camera_effect_background_setting_attr();		
        }
#endif
#if (defined(AF_SUPPORT))
		if(isp_operation_state==ISP_PREVIEW_STATE)
		{
			if(af_operation_state==AF_SEARCH_STATE)
			{
				yuv_af_status=image_sensor_func->yuv_sensor_setting(CAM_PARAM_YUV_AF_STATUS,0);
				if(yuv_af_status==AF_BUSY)
					yuv_af_check_count++;
				else
				{
					if(yuv_af_status==AF_SEARCH_SUCCESS)
						isp_preview_config_data.cam_focus_cb(1);	/* Inform MMI AF Success Zone */
					else
						isp_preview_config_data.cam_focus_cb(0xFF);	/* Inform MMI AF Fail */
					af_operation_state=AF_FREEZE_STATE;
				}
				if(yuv_af_check_count>camera_oper_data.yuv_af_timeout_frame)
				{
					isp_preview_config_data.cam_focus_cb(0xFF);
					af_operation_state=AF_FREEZE_STATE;
				}
			}
		}
#endif		
		if ((image_setting_index!=0)&&(isp_operation_state!=ISP_STANDBY_STATE)&&(stack_query_boot_mode()!=FACTORY_BOOT))
			background_image_setting();		
		if(wait_first_frame_flag==KAL_TRUE)
		{
			isp_preview_frame++;
			if(isp_preview_frame==camera_oper_data.preview_delay_frame)
			{
				kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR);
				wait_first_frame_flag=KAL_FALSE;
			}
		}
		else
			kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR);
	}
	IRQUnmask(IRQ_CAMERA_CODE);
}	
else
{
#endif	/*ANALOG_TV_SUPPORT*/	

#if (defined(DRV_ISP_6219_SERIES))
	if (isp_int_status & ISP_INT_FRAME_READY)
	{
		if (isp_operation_state==ISP_PREVIEW_STATE)
		{
			if (isp_preview_config_data.cam_preview_cb!=0)
			{
				if ((ae_count==camera_oper_data.ae_setting_shut_delay_frame)&&
					 (ae_enable_flag==ISP_ON)&&(ae_awb_cal_complete==1))
					image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
				if ((ae_count==camera_oper_data.ae_setting_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						ae_set_pregain(pregain);
					if(awb_enable_flag==ISP_ON)
						awb_set_gain();
				#if (defined(DRV_ISP_6219_SERIES))
					/* Flare */
					if((camera_oper_data.flare_camera_enable==KAL_TRUE)&&(isp_preview_config_data.image_effect==0))
					{
						SET_AWB_R_GAIN(flare_gain);										
						SET_AWB_G_GAIN(flare_gain);
						SET_AWB_B_GAIN(flare_gain);
						SET_GAMMA_RGB_FLARE_R(flare_offset);
						SET_GAMMA_RGB_FLARE_G(flare_offset);
						SET_GAMMA_RGB_FLARE_B(flare_offset);
						SET_GAMMA_RGB_FLARE_SIGN_R_HIGH;
						SET_GAMMA_RGB_FLARE_SIGN_G_HIGH;
						SET_GAMMA_RGB_FLARE_SIGN_B_HIGH;
					}
				#endif
				}
				if ((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if (isp_first_preview_frame==KAL_TRUE)
						isp_preview_2a_enable=1;
					else if(wait_first_frame_flag==KAL_FALSE)
					{
					#if (defined(DRV_ISP_6219_SERIES))
						if((camera_oper_data.flare_camera_enable==KAL_TRUE)&&(isp_preview_config_data.image_effect==0))
						{
							get_histogram_info(hist_idx);
							hist_idx++;
							hist_idx%=3;
						}
					#endif
						ae_awb_cal_complete=0;
						isp_preview_config_data.cam_preview_cb(0);
						ae_count++;
						ae_count%=camera_oper_data.ae_awb_cal_period;
					}
				}

				if(ae_awb_cal_complete==1)
				{
					ae_count++;
					ae_count%=camera_oper_data.ae_awb_cal_period;
				}
			}

			/* Auto Low Light Swith */
			if((isp_preview_config_data.image_effect==0) &&(isp_preview_config_data.night_mode==KAL_FALSE)
				&&(ae_enable_flag==ISP_ON)&&(stack_query_boot_mode()!=FACTORY_BOOT))
			{	/* FACTORY_BOOT for CCT */
				if(avglum<camera_oper_data.ae_lowlight_threshold)
					set_camera_mode_para(CAMERA_PARA_AUTO_LOWLIGHT_MODE);
				else if(avglum>camera_oper_data.ae_lowlight_off_threshold)
					set_camera_mode_para(CAMERA_PARA_PREVIEW_MODE);
			}
		}
		else if ((isp_operation_state==ISP_MPEG4_ENCODE_STATE)||(isp_operation_state==ISP_VIDEO_FULLDUPLEX_ENCODE_STATE))
		{
			if (mpeg4_encode_data.cam_encode_cb!=0)
			{
				if ((ae_count==camera_oper_data.ae_setting_shut_delay_frame)&&
					 (ae_enable_flag==ISP_ON)&&(ae_awb_cal_complete==1))
					image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
				if ((ae_count==camera_oper_data.ae_setting_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						ae_set_pregain(pregain);
					if(awb_enable_flag==ISP_ON)
						awb_set_gain();										
				#if (defined(DRV_ISP_6219_SERIES))
					/* Flare */
					
					if((camera_oper_data.flare_video_enable==KAL_TRUE)&&(isp_preview_config_data.image_effect==0))
					{
						SET_AWB_R_GAIN(flare_gain);										
						SET_AWB_G_GAIN(flare_gain);
						SET_AWB_B_GAIN(flare_gain);
						SET_GAMMA_RGB_FLARE_R(flare_offset);
						SET_GAMMA_RGB_FLARE_G(flare_offset);
						SET_GAMMA_RGB_FLARE_B(flare_offset);
						SET_GAMMA_RGB_FLARE_SIGN_R_HIGH;
						SET_GAMMA_RGB_FLARE_SIGN_G_HIGH;
						SET_GAMMA_RGB_FLARE_SIGN_B_HIGH;
					}
				#endif
				}
				if ((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if (isp_first_preview_frame==KAL_TRUE)
						isp_preview_2a_enable=1;
					else if(wait_first_frame_flag==KAL_FALSE)
               				{
					#if (defined(DRV_ISP_6219_SERIES))
						if((camera_oper_data.flare_video_enable==KAL_TRUE)&&(isp_preview_config_data.image_effect==0))
						{
							get_histogram_info(hist_idx);
							hist_idx++;
							hist_idx%=3;
						}
					#endif
						ae_awb_cal_complete=0;
						mpeg4_encode_data.cam_encode_cb(0);
						ae_count++;
						ae_count%=camera_oper_data.ae_awb_cal_period;
               				}
				}

				if(ae_awb_cal_complete==1)
				{
					ae_count++;
					ae_count%=camera_oper_data.ae_awb_cal_period;
				}
			}

			/* Auto Low Light Switch */
			if((isp_preview_config_data.image_effect==0) &&(isp_preview_config_data.night_mode==KAL_FALSE)
				&&(ae_enable_flag==ISP_ON))
			{
				if(avglum<camera_oper_data.ae_video_lowlight_threshold)
					set_camera_mode_para(CAMERA_PARA_VIDEO_AUTO_LOWLIGHT_MODE);
				else if(avglum>camera_oper_data.ae_video_lowlight_off_threshold)
					set_camera_mode_para(CAMERA_PARA_VIDEO_MODE);
			}
		}

#if (defined(WEBCAM_SUPPORT))
		else if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
		{   // Webcam AE/AWB
			if (g_usbvideo_camera_data.usbvideo_cam_preview_cb!=0)
			{
				if ((ae_count==camera_oper_data.ae_setting_shut_delay_frame)&&
					 (ae_enable_flag==ISP_ON)&&(ae_awb_cal_complete==1))
					image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
				if ((ae_count==camera_oper_data.ae_setting_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						ae_set_pregain(pregain);
					if(awb_enable_flag==ISP_ON)
						awb_set_gain();										
				}
				if ((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(wait_first_frame_flag==KAL_FALSE)
					{
						ae_awb_cal_complete=0;
						g_usbvideo_camera_data.usbvideo_cam_preview_cb(0);
						ae_count++;
						ae_count%=camera_oper_data.ae_awb_cal_period;
					}
				}
				
				if(ae_awb_cal_complete==1)
				{
					ae_count++;
					ae_count%=camera_oper_data.ae_awb_cal_period;
				}
			}			
		if(usbvideo_attr_setting_PU_index!=0)
			usbvideo_camera_effect_background_setting_attr();		
		}				
#endif  //END_OF_WEBCAM_SUPPORT		
		
		if(wait_first_frame_flag==KAL_TRUE)
		{
			isp_preview_frame++;
			if(isp_preview_frame==camera_oper_data.preview_delay_frame)
			{
				kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_FRAME_READY_EVENT,KAL_OR);
				wait_first_frame_flag=KAL_FALSE;
			}
		}
		else
			kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_FRAME_READY_EVENT,KAL_OR);

		if ((image_setting_index!=0)&&(isp_operation_state!=ISP_STANDBY_STATE)&&(stack_query_boot_mode()!=FACTORY_BOOT))
			background_image_setting();
		IRQUnmask(IRQ_CAMERA_CODE);
	}

#else /* !(defined(DRV_ISP_6219_SERIES)) */
	if (isp_int_status & ISP_INT_FRAME_READY)
	{
#if ( defined(DRV_ISP_6228_SERIES)&& defined(WEBCAM_SUPPORT) )
/* For WEBCAM MT6228+TG sync AE/AWB frame ready and jpeg encode interrupt sync */
      if((tg_interrupt_flag==KAL_TRUE)&&
         (usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE))
         usbvideo_camera_frame_ready();
#endif
		if ((image_setting_index!=0)&&(isp_operation_state!=ISP_STANDBY_STATE)&&(stack_query_boot_mode()!=FACTORY_BOOT))
			background_image_setting();	    
		IRQUnmask(IRQ_CAMERA_CODE);
	}

	if ((isp_int_status & ISP_INT_VD_DONE)||(isp_int_status & ISP_INT_TG_DONE))
	{
		if ((isp_operation_state==ISP_PREVIEW_STATE)||(isp_operation_state==ISP_CAPTURE_BARCODE_STATE))
		{
			if (cam_preview_cb!=0)
			{
				if ((ae_count==camera_oper_data.ae_setting_shut_delay_frame)&&(ae_awb_cal_complete==1)
					&&(ae_enable_flag==ISP_ON))
					image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
				if ((ae_count==camera_oper_data.ae_setting_sensor_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						image_sensor_func->set_sensor_gain(sensor_pregain);
				}
				if ((ae_count==camera_oper_data.ae_setting_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						ae_set_isp_pregain();
					if(awb_enable_flag==ISP_ON)
						awb_set_gain();
					if((isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)&&(stack_query_boot_mode()!=FACTORY_BOOT))
						set_anti_low_light_para(AE_INDEX_ENV);
				}
				isp_preview_2a_enable=0;
				if ((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_awb_cal_complete==1))
				{
					#if (defined(DRV_ISP_6227_SERIES))
					if(ae_counting_flag==KAL_TRUE) //Avoid ae get accumulation frame
					#else	// MT6228||MT6229
					if(AE_FRAME_COUNT==1) //Avoid ae get accumulation frame
					#endif
					{						
						if (isp_first_preview_frame==KAL_TRUE)
							isp_preview_2a_enable=1;
						else if(wait_first_frame_flag==KAL_FALSE)
						{
							ae_awb_cal_complete=0;
							cam_preview_cb(0);
							ae_count++;
							ae_count%=camera_oper_data.ae_awb_cal_period;
						}
						ae_counting_flag=KAL_TRUE;
					}
					else
						ae_counting_flag=KAL_FALSE;
				}
				if((ae_awb_cal_complete==1)&&
					(!((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_counting_flag==KAL_FALSE))) )
				{					/* cal complete && not wait hw ae count  */						
					ae_count++;
					ae_count%=camera_oper_data.ae_awb_cal_period;
				}
			}

#if (defined(AF_SUPPORT))
			if((dsc_status.af.trigger==CAM_AF_ONE_TIME)||(dsc_status.af.trigger==CAM_AF_CONTINUE))
			{
				if(avglum<camera_oper_data.ae_lowlight_threshold)
				{
					if(stack_query_boot_mode()!=FACTORY_BOOT)
					set_camera_mode_para(CAMERA_PARA_AF_LOWLIGHT_MODE);
					set_af_proc_para(dsc_status.af.mode,KAL_TRUE);
				}
				else if(avglum>camera_oper_data.ae_lowlight_off_threshold)
				{
					if(stack_query_boot_mode()!=FACTORY_BOOT)
					set_camera_mode_para(CAMERA_PARA_AF_NORMAL_MODE);
					set_af_proc_para(dsc_status.af.mode,KAL_FALSE);
				}
			}
#endif
		
#if (defined(AF_SUPPORT))
			if(dsc_status.af.mode==CAM_AF_MANUAL_MODE)	/* Manual Focus */
			{
				if(dsc_status.af.mfdir == CAM_FOCUS_FORWARD_CONTINUE)
					lens_func->lens_af_step_cw(af_oper_data.manual_focus_step);
				else if(dsc_status.af.mfdir == CAM_FOCUS_BACKWARD_CONTINUE)
					lens_func->lens_af_step_ccw(af_oper_data.manual_focus_step);
			}
			else	/* Auto Focus */
			{
				if (AF_release_delay<af_oper_data.AF_count_release)//delay check for AF release before AF press
				{
					AF_release_delay++;	
				}
				else//AF_release_delay>=AF_count_release
				{
					if ((dsc_status.af.trigger==CAM_AF_ONE_TIME)||(dsc_status.af.trigger==CAM_AF_CONTINUE))//AF key press
					{
						if(ae_enable_flag==ISP_ON)
						{
							/* if AE stable & AE, AWB callback end, then w/o needing to wait for set gain frame */
							if ((AE_INDEX_C==AE_INDEX)&&(ae_awb_cal_complete==1))//stable AE & AE callback end
							{
								if (af_operation_state==AF_COLLECT_STATE)//first AF state 
								{
									ae_enable_flag=ISP_OFF;
									awb_enable_flag=ISP_OFF;
								}
							}
						}
						else if ((ae_enable_flag==ISP_OFF)&&(awb_enable_flag==ISP_OFF))//AE, AWB disable
						{
							if (af_operation_state==AF_FREEZE_STATE)//AF freeze state return from AF callback
							{
								af_count = af_oper_data.AF_count_max;
								ae_enable_flag=ae_enable_flag_backup;
								awb_enable_flag=awb_enable_flag_backup;
							}
						}
						if((ae_enable_flag==ISP_OFF)&&(awb_enable_flag==ISP_OFF))//AE, AWB disable
						{
							/* prevent AF window shift for 6228 */
							if (af_oper_data.AF_wind_y_delay < af_oper_data.AF_wind_y_delay_count)
							{
								if (af_oper_data.AF_wind_y_delay == 0)
									af_zone_setting(dsc_status.af.metering);
								af_oper_data.AF_wind_y_delay++;
							}
							else
							{
							if((af_operation_state==AF_COLLECT_STATE) && (af_count<af_oper_data.AF_count_max))
							{
								af_count++;
								if(af_detail_search==KAL_FALSE)
								{
									if((af_count==af_oper_data.AF_count_max) || (AF_check_AF_count(af_count)==KAL_TRUE))
									{
										af_count = af_oper_data.AF_count_max;
#if(defined(AF_Debug_Function))
										if(af_debug_flag==0)
										{
#endif					
										get_af_info(dsc_status.af.index);
										af_next_step_idx=get_af_table_index(dsc_status.af.index);
										if(af_next_step_idx != dsc_status.af.index)
										{
												lens_func->lens_af_move_to((kal_int32)camera_lens_step.AF[af_next_step_idx].pos);
											AF_step_move_log((kal_int16)camera_lens_step.AF[af_next_step_idx].pos);
											dsc_status.af.index=af_next_step_idx;
											af_count=0;
										}
										else
										{
											AF_small_check_count = 0;//reset small check count	
											af_check_FV = 0;//reset stable back count
										}
#if(defined(AF_Debug_Function))
										}
										else
										{
											AF_debug_scan();
										}
#endif			
									}
								}
								else
								{
									if((af_detail_idx<AF_CHECK_COUNT_D) && (af_check_FV>0))
									{
										if((af_count==af_oper_data.AF_count_max) || (AF_check_AF_count(af_count)==KAL_TRUE))
										{
											af_count = af_oper_data.AF_count_max;
											get_af_detail_info(af_detail_idx);
											af_next_detail_pos=get_af_detail_pos(af_detail_idx);
											if (af_operation_state==AF_COLLECT_STATE)
											{										
												lens_func->lens_af_move_to((kal_int32)af_next_detail_pos);
												AF_step_move_log((kal_int16)af_next_detail_pos);
											}
											af_detail_idx = AF_af_detail_idx_update(af_detail_idx);
											if (af_detail_idx == 0)
											{
												af_check_FV = 0;//reset AF slow count
											}
											if (af_operation_state==AF_COLLECT_STATE)//continue to collect
											{
												af_count=0;
											}	
										}
									}
									if ((af_detail_idx==0) && (af_check_FV == 0))//stablize step back to detail search pos
									{
										af_check_FV = AF_slow_back_check(af_check_FV);
										af_count = 0;
									}
								}
							}
							}
							if((af_operation_state==AF_SEARCH_STATE)&&(af_cal_complete==KAL_TRUE))
							{
								af_cal_complete=KAL_FALSE;
								cam_focus_cb(0);
							}
						}
					}
				}
			}
#endif			
		}
		else if (isp_operation_state==ISP_MPEG4_ENCODE_STATE)
		{
			if (mpeg4_encode_data.cam_encode_cb!=0)
			{
				if ((ae_count==camera_oper_data.ae_setting_shut_delay_frame)&&
					 (ae_enable_flag==ISP_ON)&&(ae_awb_cal_complete==1))
					image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
				if ((ae_count==camera_oper_data.ae_setting_sensor_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						image_sensor_func->set_sensor_gain(sensor_pregain);
				}
				if ((ae_count==camera_oper_data.ae_setting_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						ae_set_isp_pregain();
					if(awb_enable_flag==ISP_ON)
						awb_set_gain();
					
					if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
						set_anti_low_light_para(AE_INDEX_ENV);
				}
				isp_preview_2a_enable=0;
				if ((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_awb_cal_complete==1))
				{
				#if (defined(DRV_ISP_6227_SERIES))
					if(ae_counting_flag==KAL_TRUE) //Avoid ae get accumulation frame
				#else	// MT6228||MT6229
					if(AE_FRAME_COUNT==1) //Avoid ae get accumulation frame
				#endif
					{						
						if (isp_first_preview_frame==KAL_TRUE)
							isp_preview_2a_enable=1;
						else if(wait_first_frame_flag==KAL_FALSE)
	               {
							ae_awb_cal_complete=0;
							mpeg4_encode_data.cam_encode_cb(0);
							ae_count++;
							ae_count%=camera_oper_data.ae_awb_cal_period;
	               }
						ae_counting_flag=KAL_TRUE;
					}
					else
						ae_counting_flag=KAL_FALSE;
				}

				if((ae_awb_cal_complete==1)&&
					(!((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_counting_flag==KAL_FALSE))) )
				{					/* cal complete && not wait hw ae count  */						

					ae_count++;
					ae_count%=camera_oper_data.ae_awb_cal_period;
				}
			}
		}

#if (defined(WEBCAM_SUPPORT))	// !MT6219
		else if(usbvideo_cam_operation_state==USBVIDEO_CAM_PREVIEW_CHECK_STATE)
		{   // Webcam AE/AWB
			if (g_usbvideo_camera_data.usbvideo_cam_preview_cb!=0)
			{
				// For use VD interrupt sensor modules, Enable AE Counter
					if( ae_count==(camera_oper_data.ae_awb_cal_period-3) )										
						ENABLE_AE_COUNT;	
				if ((ae_count==camera_oper_data.ae_setting_shut_delay_frame)&&
					 (ae_enable_flag==ISP_ON)&&(ae_awb_cal_complete==1))
					image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);
				if ((ae_count==camera_oper_data.ae_setting_sensor_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					image_sensor_func->set_sensor_gain(sensor_pregain);
				}
				if ((ae_count==camera_oper_data.ae_setting_gain_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(ae_enable_flag==ISP_ON)
						ae_set_isp_pregain();
					if(awb_enable_flag==ISP_ON)
						awb_set_gain();	
					
					if(isp_preview_config_data.image_effect==CAM_EFFECT_ENC_NORMAL)
						set_anti_low_light_para(AE_INDEX_ENV);									
				}
				if ((ae_count==camera_oper_data.ae_setting_cal_delay_frame)&&(ae_awb_cal_complete==1))
				{
					if(wait_first_frame_flag==KAL_FALSE)
					{
        				// For use VD interrupt sensor modules, Disable AE Counter
       						DISABLE_AE_COUNT;										
						ae_awb_cal_complete=0;
						g_usbvideo_camera_data.usbvideo_cam_preview_cb(0);
						ae_count++;
						ae_count%=camera_oper_data.ae_awb_cal_period;
					}
				}
				
				if(ae_awb_cal_complete==1)
				{
					ae_count++;
					ae_count%=camera_oper_data.ae_awb_cal_period;
				}
			}			
		    	if(usbvideo_attr_setting_PU_index!=0)
				usbvideo_camera_effect_background_setting_attr();		
		}				
#endif  //END_OF_WEBCAM_SUPPORT		

		if(wait_first_frame_flag==KAL_TRUE)
		{
			isp_preview_frame++;
			if(isp_preview_frame==camera_oper_data.preview_delay_frame)
			{
				kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR);
				wait_first_frame_flag=KAL_FALSE;
			}
		}
#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))		
	    else if((flashlight_operation_state == FLASHLIGHT_PRE_STROBE_STATE)||
	            (flashlight_operation_state == FLASHLIGHT_TRIGGER_STATE))
	    {   // Flash Light Control        
		    flashlight_hisr();
		    if((flashlight_operation_state == FLASHLIGHT_PRE_STROBE_DONE_STATE)||
		       (flashlight_operation_state == FLASHLIGHT_TRIGGER_DONE_STATE))
		        kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR);		    
        }    			
#endif        
		else
			kal_set_eg_events(camera_isp_event_id,CAMERA_ISP_VD_READY_EVENT,KAL_OR);
		IRQUnmask(IRQ_CAMERA_CODE);

	}
#endif

#if defined(ANALOG_TV_SUPPORT)      
}
#endif

#endif /* !(YUV_SENSOR_SUPPORT) */

#if (defined(DRV_ISP_6219_SERIES))
	if ((isp_digital_zoom_flag==KAL_TRUE)&&(isp_operation_state==ISP_MPEG4_ENCODE_STATE)&&
		 (isp_enter_exit_process_flag==KAL_FALSE))
	{
	    kal_uint16 pixel_count,line_count;	    
		pixel_count=*(volatile unsigned int *) 0x80690428;
		line_count=*(volatile unsigned int *) 0x8069042C;

		if ((img_dma_ibw2_int==KAL_TRUE)||((pixel_count==0)&&(line_count==0)))
		{
			img_dma_ibw2_int=KAL_FALSE;

			SET_TG_GRAB_PIXEL(isp_grab_start_x,(isp_grab_width*isp_horizontal_subsample));
			SET_TG_GRAB_LINE(isp_grab_start_y,(isp_grab_height*isp_vertical_subsample));
			ae_config((isp_grab_width*isp_horizontal_subsample),(isp_grab_height*isp_vertical_subsample));
			SET_SUB_SAMPLE_MODE(isp_sub_sample_mode);

	  		RESZ_Stop(SCENARIO_MPEG_ENCODE_ID);
   		stop_image_dma(SCENARIO_MPEG_ENCODE_ID);
   		IMGDMA_Close(SCENARIO_MPEG_ENCODE_ID);
			(*(volatile unsigned int *) 0x80690404) &= ~1; /* disable IBW2 interrupt */
   		video_enc_reset_buffer_counter();
   		STOP_LCD_TRANSFER;
   		START_LCD_TRANSFER;
   		config_image_dma(SCENARIO_MPEG_ENCODE_ID,mpeg4_encode_data.image_target_width,
   							  mpeg4_encode_data.image_target_height);
   		RESZ_SetSize(mpeg4_encode_data.image_source_width,mpeg4_encode_data.image_source_height,
   						 mpeg4_encode_data.mpeg4_image_width,mpeg4_encode_data.mpeg4_image_height,
   						 SCENARIO_MPEG_ENCODE_ID);
   		RESZ_Start(SCENARIO_MPEG_ENCODE_ID);
			isp_digital_zoom_flag=KAL_FALSE;
			ENABLE_CMOS_SESNOR;
			DISABLE_CAMERA_IDLE_INT;
			ENABLE_VIEW_FINDER_MODE;
			ae_count=0;
			hist_idx=0;
		}
	}
#endif	/* replace 27/28 zoom setting to isp_ibw2_cb() */
#endif
}	/* isp_HISR() */



extern unsigned int analog_tv_recording ;

/*************************************************************************
* FUNCTION
*	init_isp_if
*
* DESCRIPTION
*	initialize ISP interface
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void init_isp_if(void)
{
#if (defined(ISP_SUPPORT))
	kal_uint32 save_irq_mask;

  	save_irq_mask=SaveAndSetIRQMask();
	DRV_Reg(DRVPDN_CON3) &= (~DRVPDN_CON3_ISP);  /* Power on ISP */
  	RestoreIRQMask(save_irq_mask);

	if (isp_sleep_mode_handler==0xFF)
		isp_sleep_mode_handler = L1SM_GetHandle();
   L1SM_SleepDisable(isp_sleep_mode_handler);

	/* set the GPIO48 and GPIO49 mode as camera interface for RESET and PWRDN*/
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	GPIO_ModeSetup(48,1);
	GPIO_ModeSetup(49,1);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	GPIO_ModeSetup(12,1);
	GPIO_ModeSetup(13,1);
#elif (defined(DRV_ISP_6225_SERIES))
	GPIO_ModeSetup(10,1);	GPIO_InitIO(1,10);	//Reset
	//GPIO_ModeSetup(11,1);   GPIO_InitIO(1,11);	//PWR Down
	GPIO_ModeSetup(12,1);   GPIO_InitIO(0,12);	//V-sync
	GPIO_ModeSetup(13,1);   GPIO_InitIO(0,13);	//H-sync
	GPIO_ModeSetup(14,1);   GPIO_InitIO(1,14);	//CMMCLK
	GPIO_ModeSetup(15,1);   GPIO_InitIO(1,15);	//Data7
	GPIO_ModeSetup(16,1);   GPIO_InitIO(1,16);	//Data6
	GPIO_ModeSetup(17,1);   GPIO_InitIO(1,17);	//Data5
	GPIO_ModeSetup(18,1);   GPIO_InitIO(1,18);	//Data4
	GPIO_ModeSetup(19,1);   GPIO_InitIO(1,19);	//Data3
	GPIO_ModeSetup(20,1);   GPIO_InitIO(1,20);	//Data2
	GPIO_ModeSetup(21,1);   GPIO_InitIO(1,21);	//Data1
	GPIO_ModeSetup(22,1);   GPIO_InitIO(1,22);	//Data0
#endif

	/* configure CMOS sensor mode configuration register */
#if (defined(DRV_ISP_6219_SERIES))
	SET_VSYNC_POLARITY_LOW;
	DISABLE_AUTO_HSYNC_PIXEL_CAL;
#endif
	RESET_CMOS_SENSOR;
	POWER_ON_CMOS_SENSOR;
	ENABLE_CMOS_SESNOR;

	DRV_WriteReg32(ISP_PREPROCESS_CTRL1_REG,0x80003100);
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES))
	DISABLE_Y_LPF;			/* TBD:LPF customization to camera_para */
	DISABLE_C_LPF;
#endif
#if (defined(DRV_ISP_6228_SERIES))
	DISABLE_VERTICAL_LPF;
#endif

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)  
 #if defined(TVIN_SUPPORT)
       if(mmi_get_tvin_current_state()==KAL_TRUE)
	 #else  
               if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
	 #endif		
      	{
               /* Set Low to MCLK */
	SET_CMOS_FALLING_EDGE(0);
	DISABLE_CAMERA_TG_PHASE_COUNTER;
	DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;

	}
      else
      	{
      #endif	 /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	

	/* configure TG phase counter register */
	SET_TG_OUTPUT_CLK_DIVIDER(1);//P_U2_M19_bw_Z0009
        SET_CMOS_RISING_EDGE(0); //P_U2_M19_bw_Z0009
        SET_CMOS_DATA_LATCH(1);  //P_U2_M19_bw_Z0009
	SET_CMOS_FALLING_EDGE(1);		//set to HW default
	SET_TG_PIXEL_CLK_DIVIDER(1);	//set to HW default
	ENABLE_CAMERA_TG_PHASE_COUNTER;
	ENABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)  
       }
         DISABLE_CAMERA_PIXEL_CLKIN_ENABLE;
	 DISABLE_CAMERA_INDATA_FORMAT;
         SET_CAMERA_INPUT_TYPE(INPUT_BAYER);
#endif

	/* debug function */
#if (defined(DRV_ISP_6219_SERIES))
	DISABLE_GMC_DEBUG_OUTPUT;
	SET_GMC_RGB565_MODE;
	DISABLE_DEBUG_DATA_COUNTER;
	SET_DEBUG_OUTPUT_MODE(REG_DEBUG_GMC_OUTPUT_COUNT);
#endif
	isp_first_preview_frame=KAL_TRUE;
	isp_preview_2a_enable=0;
	isp_operation_state=ISP_STANDBY_STATE;
	isp_digital_zoom_factor=ISP_MIN_DIGITAL_ZOOM_FACTOR;

   if (camera_isp_event_id==NULL)
      camera_isp_event_id=kal_create_event_group("ISP_EVT");

	IRQ_Register_LISR(IRQ_CAMERA_CODE, camera_isp_LISR,"Camera ISR");

	VISUAL_Register_HISR(VISUAL_CAMERA_HISR_ID,camera_isp_HISR);

#if (!defined(DRV_ISP_6219_SERIES))
	cam_preview_cb = NULL;
	cam_focus_cb = NULL;
	/* default dsc_status setting */
	dsc_status.dscmode		= CAM_AUTO_DSC;
	dsc_status.ae.metering	= CAM_AE_METER_AUTO;
	dsc_status.ae.flash		= CAM_FLASH_AUTO;
	dsc_status.af.trigger	= CAM_AF_RELEASE;
	dsc_status.af.mode		= CAM_AF_AUTO_MODE;
	dsc_status.af.metering	= CAM_AF_SINGLE_ZONE;
	dsc_status.af.mfdir		= CAM_FOCUS_STOP;
#endif

	/* default camera_oper_data setting */
	camera_oper_data.ae_high_banding_target_enable = KAL_TRUE;
	camera_oper_data.flare_camera_enable=KAL_FALSE;
	camera_oper_data.flare_video_enable=KAL_FALSE;
	camera_oper_data.ae_setting_sensor_gain_delay_frame=100;
	camera_oper_data.preview_defect_table_enable=KAL_FALSE;
	camera_oper_data.capture_defect_table_enable=KAL_FALSE;
	camera_oper_data.shading_table_mode_set = CAMERA_SHADING_NORMAL_SET;/* select shading table mode */
#if (defined(YUV_SENSOR_SUPPORT)&&defined(AF_SUPPORT))	
	camera_oper_data.yuv_af_timeout_frame=20;
#endif
	camera_oper_data.extreme_CT_fixWB_enable = KAL_FALSE;
	camera_oper_data.outdoor_fixWB_enable = KAL_FALSE;

#if (!(defined(DRV_ISP_6219_SERIES)||defined(YUV_SENSOR_SUPPORT)))/* AE smooth default init before custom init */
	AE_Smooth_Init();
	ae_iso_priority_Init();
#endif
	
        #if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)      
           #if defined(TVIN_SUPPORT)   
	     if(mmi_get_tvin_current_state()==KAL_TRUE)		
	          {init_tvin_operation_para(&camera_oper_data);}
	    #else //if defined(ANALOG_TV_SUPPORT)  
             if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
		  {init_analog_tv_operation_para(&camera_oper_data);}	 	
           #endif	   	
	      else 
        #endif	 /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/		
	      {init_camera_operation_para(&camera_oper_data);}

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)      
         #if defined(TVIN_SUPPORT)   
           if(mmi_get_tvin_current_state()==KAL_FALSE)
	 #else  
             if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
         #endif   
         {
#endif  /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	

	if( (camera_oper_data.isp_pregain_max<BASEGAIN) || (camera_oper_data.sensor_pregain_max<BASEGAIN) ||
		 (camera_oper_data.shutter_compensate_max<BASEGAIN) || (camera_oper_data.pregain_compensate_max<BASEGAIN) )
		ASSERT(0);
	
	if((camera_oper_data.ae_smooth_upper_bound<camera_para.AE.TargetLum)||
		(camera_oper_data.ae_smooth_lower_bound>camera_para.AE.TargetLum))
		ASSERT(0);
		
	if( (camera_oper_data.ae_awb_cal_period<=camera_oper_data.ae_setting_gain_delay_frame) ||
		 (camera_oper_data.ae_awb_cal_period<=camera_oper_data.ae_setting_shut_delay_frame) ||
		 (camera_oper_data.ae_awb_cal_period<=camera_oper_data.ae_setting_cal_delay_frame) )
		ASSERT(0);

	/* To prevent wait much long time */
	if(camera_oper_data.preview_display_wait_frame>5)
		camera_oper_data.preview_display_wait_frame=5;
	
	/* To protect invalide value */
	if(camera_oper_data.capture_delay_frame>3)
		camera_oper_data.capture_delay_frame=1;

	/* To protect invalide value */
	if((camera_oper_data.preview_delay_frame>3)||(camera_oper_data.preview_delay_frame==0))
		camera_oper_data.preview_delay_frame=1;

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)     
        }
   else
 	{
   	/* To protect invalide value */
	if(camera_oper_data.capture_delay_frame>3)
		camera_oper_data.capture_delay_frame=1;

	/* To protect invalide value */
	if((camera_oper_data.preview_delay_frame>16)||(camera_oper_data.preview_delay_frame==0))
		camera_oper_data.preview_delay_frame=1;		

   	}
#endif  /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	

#else
	/* To protect invalide value */
	if(camera_oper_data.capture_delay_frame>3)
		camera_oper_data.capture_delay_frame=1;

	/* To protect invalide value */
	if((camera_oper_data.preview_delay_frame>16)||(camera_oper_data.preview_delay_frame==0))
		camera_oper_data.preview_delay_frame=1;		
#endif /* YUV_SENSOR_SUPPORT */
	
#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)   
        #if defined(TVIN_SUPPORT)   
             if(mmi_get_tvin_current_state()==KAL_FALSE)     
	 #else  
             if(mmi_get_analog_tv_current_state()==KAL_FALSE)	
        #endif   
        {
#endif   /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	
	camera_oper_data.isp_pregain_min=BASEGAIN;
	camera_oper_data.sensor_pregain_min=BASEGAIN;
	if(camera_oper_data.pregain_mode==ISP_ONLY)
	{
		camera_oper_data.pregain_max = camera_oper_data.isp_pregain_max;
		camera_oper_data.pregain_min = camera_oper_data.isp_pregain_min;
	}
	else if(camera_oper_data.pregain_mode==SENSOR_ONLY)
	{
		camera_oper_data.pregain_max = camera_oper_data.sensor_pregain_max;
		camera_oper_data.pregain_min = camera_oper_data.sensor_pregain_min;
	}
	else
	{
		camera_oper_data.pregain_max = (camera_oper_data.isp_pregain_max)*(camera_oper_data.sensor_pregain_max)/BASEGAIN;
		camera_oper_data.pregain_min = (camera_oper_data.isp_pregain_min)*(camera_oper_data.sensor_pregain_min)/BASEGAIN;
	}

	if(camera_oper_data.pregain_compensate_max > camera_oper_data.pregain_max)
		ASSERT(0);
	
	if(camera_oper_data.ae_setting_sensor_gain_delay_frame==100)
		camera_oper_data.ae_setting_sensor_gain_delay_frame=camera_oper_data.ae_setting_gain_delay_frame;

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)   
}
#endif

#endif /* YUV_SENSOR_SUPPORT */
	
#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)   
    #if defined(TVIN_SUPPORT)   
      if(mmi_get_tvin_current_state()==KAL_TRUE)   
              {tvin_func_config();}
    #else //if defined(ANALOG_TV_SUPPORT)
	if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
	{ 
		analog_tv_func_config();
	}		 	
    #endif	  
      else
#endif	  /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/		
	{

		#if defined(TV_RECORD_SUPPORT)
		if( 	analog_tv_recording == 1)		
		{
			analog_tv_func_config();		
		}
		else
		{
			image_sensor_func_config();			
		}
		#else
			image_sensor_func_config();
		#endif
	}

#if (!defined(YUV_SENSOR_SUPPORT))
    #if defined(ANALOG_TV_SUPPORT)
	if(mmi_get_analog_tv_current_state()==KAL_FALSE)
    	{
    #endif
	init_ae();
	init_awb();
    #if defined(ANALOG_TV_SUPPORT)
        }
    #endif
#endif

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)   
         #if defined(TVIN_SUPPORT)   
             if(mmi_get_tvin_current_state()==KAL_TRUE)   
		  {tvin_para_to_isp();}	
	 #else //if defined(ANALOG_TV_SUPPORT)  
             if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
             	  { analog_tv_para_to_isp();}
         #endif  	
        else 
        {
#endif  /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	
	load_camera_para();
#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)  
        }
#endif

#if (!defined(YUV_SENSOR_SUPPORT))
#if defined(ANALOG_TV_SUPPORT)
	if(mmi_get_analog_tv_current_state()==KAL_FALSE)
#endif
	{ init_histogram_setting(); }
#endif
#if (!(defined(DRV_ISP_6219_SERIES)||defined(YUV_SENSOR_SUPPORT)))/* AE smooth update custom para & init table */
	init_ae_smooth_custom_para(AE_SMOOTH_PREVIEW);
#endif
		
	sensor_err_check=image_sensor_func->sensor_init();
	image_sensor_func->get_sensor_size(&image_sensor_width,&image_sensor_height);
#if (!defined(YUV_SENSOR_SUPPORT))
      #if defined(ANALOG_TV_SUPPORT)
	if(mmi_get_analog_tv_current_state()==KAL_FALSE)
    #endif
	{ image_sensor_func->set_sensor_eshutter((kal_uint16)eShutter);}
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(YUV_SENSOR_SUPPORT)))
	if(dsc_support_info.dsccomp.flashlight==KAL_TRUE)
		init_flashlight();
    #if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
    xenon_func_config();
    p_xenon_func->xenon_init();
    #endif		
#endif

#if (!defined(YUV_SENSOR_SUPPORT))
#if (defined(AF_SUPPORT)&&(!defined(DRV_ISP_6219_SERIES)))
	if(dsc_support_info.dsccomp.autofocus==KAL_TRUE)
	{
		init_af();
		lens_func_config();
		lens_err_check=lens_func->lens_init();
		lens_func->lens_power_on();
		lens_func->lens_af_move_to((kal_int32)camera_lens.AF[camera_lens.INFO.af_home_idx].pos);
		AF_step_move_log((kal_int16)camera_lens.AF[camera_lens.INFO.af_home_idx].pos);
		dsc_status.af.index=camera_lens.INFO.af_home_idx;
		af_operation_state=AF_STANDBY_STATE;
	}
	else
		ASSERT(0);

	init_af_operation_para(&af_oper_data);
#endif
#endif /* YUV_SENSOR_SUPPORT */

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)   
#if (!defined(YUV_SENSOR_SUPPORT))
        #if defined(TVIN_SUPPORT)   
             if(mmi_get_tvin_current_state()==KAL_TRUE)    
	 #else  
             if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
	 #endif	   
 {
 	
	REG_ISP_LPF_CTRL|=0x00100000;	//speed up isp date rate (enable isp internal buffer)
	/* Clean OB and RAW gain */
	SET_RAW_DATA_R_OFFSET_ADJ(0);
	SET_RAW_DATA_GR_OFFSET_ADJ(0);
	SET_RAW_DATA_B_OFFSET_ADJ(0);
	SET_RAW_DATA_GB_OFFSET_ADJ(0);
	#if(defined(MT6227)||defined(MT6225)||defined(MT6229)||defined(MT6230))
        REG_ISP_RAW_GAIN_CTRL1 = 0x00800080;
        REG_ISP_RAW_GAIN_CTRL2 = 0x00800080;
       #endif
 }
#endif
#endif	/*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	

#if (defined(YUV_SENSOR_SUPPORT))
	REG_ISP_LPF_CTRL|=0x00100000;	//speed up isp date rate (enable isp internal buffer)
	/* Clean OB and RAW gain */
	SET_RAW_DATA_R_OFFSET_ADJ(0);
	SET_RAW_DATA_GR_OFFSET_ADJ(0);
	SET_RAW_DATA_B_OFFSET_ADJ(0);
	SET_RAW_DATA_GB_OFFSET_ADJ(0);
	#if(defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))
    REG_ISP_RAW_GAIN_CTRL1 = 0x00800080;
    REG_ISP_RAW_GAIN_CTRL2 = 0x00800080;
    #endif
#endif

	ENABLE_CAMERA_FRAME_READY_INT;
	DISABLE_CAMERA_RESIZER_OVERRUN_INT;
	DISABLE_CAMERA_IDLE_INT;
	DISABLE_CAMERA_GMC_OVERRUN_INT;
#if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6225))		
//	DISABLE_CAMERA_FRAME_READY_INT;
	DISABLE_CAMERA_ISP_DONE_INT;
	DISABLE_CAMERA_AE_DONE_INT;
	DISABLE_CAMERA_ATF_DONE_INT;
	DISABLE_CAMERA_AVSYNC_DONE_INT;
	DISABLE_CAMERA_FLASH_DONE_INT;
	ENABLE_CAMERA_VD_DONE_INT;
#elif (defined(MT6228))		
//	DISABLE_CAMERA_FRAME_READY_INT;
	DISABLE_CAMERA_ISP_DONE_INT;
	DISABLE_CAMERA_AE_DONE_INT;
	DISABLE_CAMERA_ATF_DONE_INT;
	ENABLE_CAMERA_VD_DONE_INT;
#elif (defined(MT6229)||defined(MT6230))		
//	DISABLE_CAMERA_FRAME_READY_INT;
	DISABLE_CAMERA_ISP_DONE_INT;
	DISABLE_CAMERA_AE_DONE_INT;
	DISABLE_CAMERA_ATF_DONE_INT;
	DISABLE_CAMERA_AVSYNC_DONE_INT;
	DISABLE_CAMERA_FLASH_DONE_INT;
	ENABLE_CAMERA_VD_DONE_INT;
#endif

 	IRQSensitivity(IRQ_CAMERA_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_CAMERA_CODE);

	exposure_window.isp_hsub_factor=1;
	exposure_window.isp_vsub_factor=1;
	camera_process_stage=0;
	camera_process_stage|=LEAVE_INIT_ISP_IF;
#endif
}	/* init_isp_if() */

void set_isp_interrupt_trigger_delay_lines(kal_uint16 lines)
{
	isp_tg_delay_lines=lines;
	if(isp_tg_delay_lines==0)
	{
#if (defined(DRV_ISP_6219_SERIES))		
	ENABLE_CAMERA_FRAME_READY_INT;
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))		
	DISABLE_CAMERA_FLASH_DONE_INT;
	ENABLE_CAMERA_VD_DONE_INT;
#elif (defined(DRV_ISP_6228_SERIES))		
	DISABLE_CAMERA_TG_DONE_INT;
	ENABLE_CAMERA_VD_DONE_INT;
	tg_interrupt_flag=KAL_FALSE;
#endif
	}
	else
	{
#if (defined(DRV_ISP_6219_SERIES))		
	ENABLE_CAMERA_FRAME_READY_INT;
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6229_SERIES))		
	DISABLE_CAMERA_VD_DONE_INT;
	ENABLE_CAMERA_FLASH_DONE_INT;
	SET_CAMERA_FLASH_START_LINENO(isp_tg_delay_lines);
#elif (defined(DRV_ISP_6228_SERIES))		
	DISABLE_CAMERA_VD_DONE_INT;
	ENABLE_CAMERA_TG_DONE_INT;
	if(isp_tg_delay_lines<8)
		isp_tg_delay_lines=8;
	SET_CAMERA_TG_START_LINENO(isp_tg_delay_lines>>3);
	tg_interrupt_flag=KAL_TRUE;
#endif		
	}
}

void set_vd_blanking_lines(kal_uint32 lines)
{
	vd_blanking_lines	= lines;
}

kal_uint32 get_vd_blanking_lines(void)
{
	return vd_blanking_lines;
}

kal_uint16 get_camera_frame_period(void)
{
   kal_uint16 pixel_number, line_number;
   kal_uint32 temp_period;

	image_sensor_func->get_sensor_period(&pixel_number, &line_number);
	temp_period=((kal_uint32) (pixel_number*isp_grab_height*(((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1)));
#if (defined(MCU_104M)||defined(MCU_52M))
	isp_frame_period=(kal_uint16)(temp_period/52000);
#elif (defined(MCU_26M))
	isp_frame_period=(kal_uint16)(temp_period/26000);
#endif

#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	if((REG_ISP_TG_PHASE_COUNTER & REG_TGPC_PIXEL_CLK_SELECT_BIT)!= 0)
		isp_frame_period=(kal_uint16)(temp_period/48000);
#endif

	return isp_frame_period;
}

/*************************************************************************
* FUNCTION
*	power_off_isp
*
* DESCRIPTION
*	Turn off the ISP interface
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
extern void  mmi_set_analog_tv_current_state(kal_uint8 uState);
extern void AnalogTV_PowerOff_Close_I2C_Leakage(void);
void power_off_isp(void)
{
#if (defined(ISP_SUPPORT))
	kal_uint32 save_irq_mask;

#if !defined(TV_RECORD_SUPPORT)
	if (isp_operation_state!=ISP_STANDBY_STATE)
		ASSERT(0);
#else
	isp_operation_state = ISP_STANDBY_STATE ;
#endif
	
#ifdef ANALOG_TV_SUPPORT
	/*modify for TV 大电流by James  11.11.08*/	
	mmi_set_analog_tv_current_state(KAL_FALSE);
	init_isp_if( );	
	kal_sleep_task(2);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Add It For Test power_off_isp().....\r\n");
#endif
#endif 	

	POWER_OFF_CMOS_SENSOR;
	DISABLE_CMOS_SESNOR;
	REG_ISP_VIEW_FINDER_MODE_CTRL=0;	/* Clear ISP Pre/Cap Mode and disable view finder mode */
	IRQMask(IRQ_CAMERA_CODE);
	isp_operation_state=ISP_IDLE_STATE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
#if(!defined(MT6238))
	IRQMask(IRQ_SCCB_CODE);
#endif
#endif
	isp_first_preview_frame=KAL_TRUE;

	/* Set Low to MCLK */
	SET_CMOS_FALLING_EDGE(0);
	DISABLE_CAMERA_TG_PHASE_COUNTER;
	DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;
	
  	save_irq_mask=SaveAndSetIRQMask();
	DRV_Reg(DRVPDN_CON3) |= DRVPDN_CON3_ISP;  /* Power off ISP */
	RestoreIRQMask(save_irq_mask);
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	DRV_Reg(DRVPDN_CON2) |= DRVPDN_CON2_SCCB;  /* Power off SCCB */
#endif
	if(image_sensor_func->sensor_power_off!=0)
	{
		image_sensor_func->sensor_power_off();		/* Power off Sensor */
	}
   L1SM_SleepEnable(isp_sleep_mode_handler);

#if (defined(DRV_ISP_6227_SERIES))
    #ifndef __CUST_NEW__
	if(dsc_support_info.dsccomp.flashlight==KAL_TRUE)
		GPIO_ModeSetup(6,0);	/* Flash Triger Pin Mux to GPIO Mode */
    #endif /* __CUST_NEW__ */
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
    #ifndef __CUST_NEW__
	if(dsc_support_info.dsccomp.flashlight==KAL_TRUE)
		GPIO_ModeSetup(0,0);	/* Flash Triger Pin Mux to GPIO Mode */
    #endif /* __CUST_NEW__ */
#endif

#if (defined(AF_SUPPORT)&&(!defined(DRV_ISP_6219_SERIES)))
#if (defined(YUV_SENSOR_SUPPORT))
	camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	af_operation_state=AF_IDLE_STATE;
#else /* !(YUV_SENSOR_SUPPORT) */
	if(dsc_support_info.dsccomp.autofocus==KAL_TRUE)
	{
		lens_func->lens_af_move_to((kal_int32)camera_lens.AF[camera_lens.INFO.af_home_idx].pos);
		dsc_status.af.index=camera_lens.INFO.af_home_idx;
		lens_func->lens_power_off();
		af_operation_state=AF_IDLE_STATE;
	}
#endif
#endif
	camera_process_stage|=LEAVE_POWER_OFF_ISP;
#endif
#ifdef ANALOG_TV_SUPPORT
AnalogTV_PowerOff_Close_I2C_Leakage();
#endif 

#if defined(NOKE_DEBUG)
noke_dbg_printf("\r\n Huyanwei Debug End power_off_isp()\r\n");
#endif
}	/* power_off_isp() */



void power_off_isp_leakage(void)
{
#if (defined(ISP_SUPPORT))
	kal_uint32 save_irq_mask;

	isp_operation_state = ISP_STANDBY_STATE;

#ifdef ANALOG_TV_SUPPORT
	/*modify for TV 大电流by James  11.11.08*/	
	mmi_set_analog_tv_current_state(KAL_FALSE);
	init_isp_if( );	
	kal_sleep_task(2);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Add It For Test power_off_isp().....\r\n");
#endif
#endif 	

	
	POWER_OFF_CMOS_SENSOR;
	DISABLE_CMOS_SESNOR;
	REG_ISP_VIEW_FINDER_MODE_CTRL=0;	/* Clear ISP Pre/Cap Mode and disable view finder mode */
	IRQMask(IRQ_CAMERA_CODE);
	isp_operation_state=ISP_IDLE_STATE;
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
#if(!defined(MT6238))
	IRQMask(IRQ_SCCB_CODE);
#endif
#endif
	isp_first_preview_frame=KAL_TRUE;

	/* Set Low to MCLK */
	SET_CMOS_FALLING_EDGE(0);
	DISABLE_CAMERA_TG_PHASE_COUNTER;
	DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;
	
  	save_irq_mask=SaveAndSetIRQMask();
	DRV_Reg(DRVPDN_CON3) |= DRVPDN_CON3_ISP;  /* Power off ISP */
	RestoreIRQMask(save_irq_mask);
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	DRV_Reg(DRVPDN_CON2) |= DRVPDN_CON2_SCCB;  /* Power off SCCB */
#endif

	if( (image_sensor_func != NULL ) && (image_sensor_func->sensor_power_off!=0) )
	{
		image_sensor_func->sensor_power_off();		/* Power off Sensor */
	}
   L1SM_SleepEnable(isp_sleep_mode_handler);

#if (defined(DRV_ISP_6227_SERIES))
    #ifndef __CUST_NEW__
	if(dsc_support_info.dsccomp.flashlight==KAL_TRUE)
		GPIO_ModeSetup(6,0);	/* Flash Triger Pin Mux to GPIO Mode */
    #endif /* __CUST_NEW__ */
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
    #ifndef __CUST_NEW__
	if(dsc_support_info.dsccomp.flashlight==KAL_TRUE)
		GPIO_ModeSetup(0,0);	/* Flash Triger Pin Mux to GPIO Mode */
    #endif /* __CUST_NEW__ */
#endif

#if (defined(AF_SUPPORT)&&(!defined(DRV_ISP_6219_SERIES)))
#if (defined(YUV_SENSOR_SUPPORT))
	camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	af_operation_state=AF_IDLE_STATE;
#else /* !(YUV_SENSOR_SUPPORT) */
	if(dsc_support_info.dsccomp.autofocus==KAL_TRUE)
	{
		lens_func->lens_af_move_to((kal_int32)camera_lens.AF[camera_lens.INFO.af_home_idx].pos);
		dsc_status.af.index=camera_lens.INFO.af_home_idx;
		lens_func->lens_power_off();
		af_operation_state=AF_IDLE_STATE;
	}
#endif

#endif
	camera_process_stage|=LEAVE_POWER_OFF_ISP;
#endif

#ifdef ANALOG_TV_SUPPORT
AnalogTV_PowerOff_Close_I2C_Leakage();
#endif 

}	/* power_off_isp() */

void get_image_sensor_exposure_window(kal_uint16 *exposure_pixel, kal_uint16 *exposure_line)
{
	*exposure_pixel=exposure_window.exposure_pixel;
	*exposure_line=exposure_window.exposure_line;
}	/* get_image_sensor_exposure_window() */

/*************************************************************************
* FUNCTION
*	isp_contrast_setting
*
* DESCRIPTION
*	This function is for setting the image contrast
*
* PARAMETERS
*	contrast_level : ISP contrast gain level (0~127)
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void isp_contrast_setting(kal_uint8 contrast_level)
{
#if (defined(ISP_SUPPORT))
	SET_Y_CONTRAST_GAIN((contrast_level>>1));
#endif
}

/*************************************************************************
* FUNCTION
*	isp_bright_setting
*
* DESCRIPTION
*	This function is for setting the image brightness
*
* PARAMETERS
*	bright_level : ISP brightness value level
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void isp_bright_setting(kal_uint8 bright_level)
{
#if (defined(ISP_SUPPORT))
   if (bright_level<128)
   {
   	bright_level=127-bright_level;
	   SET_Y_BRIGHT_NEG_SIGN;
	   SET_Y_BRIGHT_OFFSET(bright_level);
   }
   else
   {
   	SET_Y_BRIGHT_POS_SIGN;
	   SET_Y_BRIGHT_OFFSET((bright_level-128));
	}
#endif
}

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
/*************************************************************************
* FUNCTION
*	adjustment_isp_hue_para
*
* DESCRIPTION
*	This function adjustments hue parameters in PREVIEW and CAPTURE mode 
*	by ISP
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void adjustment_isp_hue_para(kal_uint16 degree)
{
	ISP_HUE_STURCT hue_para;

	if(degree<=90)
	{
		hue_para.c11=sine_lut[90-degree];
		hue_para.c12=sine_lut[degree];
		hue_para.c21=-sine_lut[degree];
		hue_para.c22=sine_lut[90-degree];
	}
	else if(degree>90 && degree<=180)
	{
		hue_para.c11=-sine_lut[degree-90];
		hue_para.c12=sine_lut[180-degree];
		hue_para.c21=-sine_lut[180-degree];
		hue_para.c22=-sine_lut[degree-90];
	}
	else if(degree>180 && degree<=270)
	{
		hue_para.c11=-sine_lut[270-degree];
		hue_para.c12=-sine_lut[degree-180];
		hue_para.c21=sine_lut[degree-180];
		hue_para.c22=-sine_lut[270-degree];
	}
	else if(degree>270 && degree<=360)
	{
		hue_para.c11=sine_lut[degree-270];
		hue_para.c12=-sine_lut[360-degree];
		hue_para.c21=sine_lut[360-degree];
		hue_para.c22=sine_lut[degree-270];
	}
	else
	{
		ASSERT(0);
	}

	ENABLE_IMGPROC_HUE;
	SET_IMGPROC_HUE11(hue_para.c11);
	SET_IMGPROC_HUE12(hue_para.c12);
	SET_IMGPROC_HUE21(hue_para.c21);
	SET_IMGPROC_HUE22(hue_para.c22);
}

void disable_adjustment_isp_hue_para(void)
{
	DISABLE_IMGPROC_HUE;
}
#endif


kal_uint8 camera_image_setting(kal_uint8 type_sel, kal_uint16 para)
{
#if (defined(ISP_SUPPORT))
	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_PREVIEW_ID;
	switch (isp_operation_state)
	{
		case ISP_PREVIEW_STATE:
			scene_id=SCENARIO_CAMERA_PREVIEW_ID;
		break;
		case ISP_MPEG4_ENCODE_STATE:
			scene_id=SCENARIO_MPEG_ENCODE_ID;
		break;
		case ISP_CAPTURE_MEM_STATE:
			scene_id=SCENARIO_CAMERA_CAPTURE_MEM_ID;
		break;
		case ISP_CAPTURE_JPEG_STATE:
			scene_id=SCENARIO_CAMERA_CAPTURE_JPEG_ID;
		break;
		case ISP_CAPTURE_BARCODE_STATE:
			scene_id=SCENARIO_CAMERA_CAPTURE_BARCODE_ID;
		break;
		case ISP_MJPEG_ENCODE_STATE:
			scene_id=SCENARIO_MJPEG_ENCODE_ID;
		break;
		case ISP_VIDEO_FULLDUPLEX_ENCODE_STATE:
			scene_id=SCENARIO_FULLVIDEO_ID;
		break;        
		default:
			ASSERT(0);
		break;
	}

	switch (type_sel)
	{
		case CAM_PARAM_ZOOM_FACTOR:
			isp_digital_zoom((kal_uint8)para);
		break;
		case CAM_PARAM_CONTRAST:
      	isp_preview_config_data.contrast_level=(kal_uint8) para;
		break;
		case CAM_PARAM_BRIGHTNESS:
			isp_preview_config_data.brightness_level=(kal_uint8)para;
		break;
		case CAM_PARAM_HUE:
			if (scene_id==SCENARIO_MPEG_ENCODE_ID)
				ASSERT(0);
			isp_preview_config_data.hue_value=para;
		break;
		case CAM_PARAM_WB:
      	isp_preview_config_data.wb_mode=(kal_uint8)para;
		break;
		case CAM_PARAM_EXPOSURE:
			isp_preview_config_data.ev_value=(kal_uint8)para;
		break;
		case CAM_PARAM_EFFECT:
			isp_preview_config_data.image_effect=(kal_uint8)para;
		break;
		case CAM_PARAM_BANDING:
         isp_preview_config_data.banding_freq=(kal_uint8)para;
		break;
		case CAM_PARAM_SATURATION:
	      isp_preview_config_data.saturation_value=(kal_uint8) para;
		break;
		case CAM_PARAM_NIGHT_MODE:
			isp_preview_config_data.night_mode=(kal_bool) para;
		break;
		case CAM_PARAM_EV_VALUE:
	      isp_preview_config_data.exposure_value=(kal_uint8) para;
		break;
	}

	if (VIEW_FINDER_MODE_IS_ENABLE)
	{
		image_setting_index |= (1<<type_sel);
		return KAL_TRUE;
	}

#if (defined(YUV_SENSOR_SUPPORT))
	camera_yuv_image_setting(type_sel, para);
#else
 #if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)  	
         #if defined(TVIN_SUPPORT)  	
             if(mmi_get_tvin_current_state()==KAL_TRUE)   
         #else
             if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
	  #endif	  
 	{
	camera_yuv_image_setting(type_sel, para);
 	}
 else
 	{
 #endif /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	

	switch (type_sel)
	{
		case CAM_PARAM_CONTRAST:
			adjustment_brightness_contrast_para(scene_id,isp_preview_config_data.brightness_level,isp_preview_config_data.contrast_level);
		break;
		case CAM_PARAM_BRIGHTNESS:
			adjustment_brightness_contrast_para(scene_id,isp_preview_config_data.brightness_level,isp_preview_config_data.contrast_level);
		break;
		case CAM_PARAM_HUE:
			if (scene_id==SCENARIO_MPEG_ENCODE_ID)
				ASSERT(0);
			adjustment_hue_para(scene_id,para);
		break;
		case CAM_PARAM_WB:
			awb_set_manual_gain((kal_uint8)para);
			awb_set_gain();
		break;
		case CAM_PARAM_EXPOSURE:
			ae_set_ev((kal_int8) (para-4));
		break;
		case CAM_PARAM_EFFECT:
			image_effect_enc_process((kal_uint8)para);
		break;
		case CAM_PARAM_BANDING:
			ae_select_band((kal_uint8)para);
		break;
		case CAM_PARAM_SATURATION:
		   adjustment_saturation_para(scene_id,(kal_uint8)para);
		break;
		case CAM_PARAM_NIGHT_MODE:
			image_sensor_func->set_camera_night_mode(para);
            /* skip setting for cct mode */
    		if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)				
    		{
			if(para)
			set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);
         else
         {
            if(isp_operation_state==ISP_MPEG4_ENCODE_STATE)
         	   set_camera_mode_para(CAMERA_PARA_VIDEO_MODE);
            else
         	   set_camera_mode_para(CAMERA_PARA_PREVIEW_MODE);
         }
            }            
			if(isp_preview_config_data.image_effect!=0)
				image_effect_enc_process(isp_preview_config_data.image_effect);
		break;
		case CAM_PARAM_GAMMA:
			if (scene_id==SCENARIO_MPEG_ENCODE_ID)
				ASSERT(0);
			adjustment_gamma_para(scene_id,(kal_uint8)para);
		break;
		case CAM_PARAM_EV_VALUE:
			ae_set_expovalue((kal_int8) (para));
		break;
	}

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)  	
}
#endif

#endif /* YUV_SENSOR_SUPPORT */
	return KAL_TRUE;
#endif /* ISP_SUPPORT */
}	/* camera_image_setting() */

void background_image_setting(void)
{
#if (defined(ISP_SUPPORT))
	kal_uint8 i;

	MMDI_SCENERIO_ID scene_id=SCENARIO_CAMERA_PREVIEW_ID;
	switch (isp_operation_state)
	{
		case ISP_PREVIEW_STATE:
			scene_id=SCENARIO_CAMERA_PREVIEW_ID;
		break;
		case ISP_MPEG4_ENCODE_STATE:
			scene_id=SCENARIO_MPEG_ENCODE_ID;
		break;
		case ISP_CAPTURE_MEM_STATE:
			scene_id=SCENARIO_CAMERA_CAPTURE_MEM_ID;
		break;
		case ISP_CAPTURE_JPEG_STATE:
			scene_id=SCENARIO_CAMERA_CAPTURE_JPEG_ID;
		break;
		case ISP_CAPTURE_BARCODE_STATE:
			scene_id=SCENARIO_CAMERA_CAPTURE_BARCODE_ID;
		break;
		case ISP_MJPEG_ENCODE_STATE:
			scene_id=SCENARIO_MJPEG_ENCODE_ID;
		break;
		case ISP_VIDEO_FULLDUPLEX_ENCODE_STATE:
			scene_id=SCENARIO_FULLVIDEO_ID;
		break;        
		default:
			ASSERT(0);
		break;
	}

#if (defined(YUV_SENSOR_SUPPORT))
	background_yuv_image_setting();
#else
#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)   
        #if defined(TVIN_SUPPORT)   
             if(mmi_get_tvin_current_state()==KAL_TRUE)   
	 #else  
             if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
	 #endif	

 	{
	background_yuv_image_setting();
 	}
 else
 	{
 #endif  /*TVIN_SUPPORT||ANALOG_TV_SUPPORT*/	

	if (image_setting_index & (1<<CAM_PARAM_EFFECT))
	{
		image_effect_enc_process(isp_preview_config_data.image_effect);
		image_setting_index &=~(1<<CAM_PARAM_EFFECT);
	}

	for (i=0;i<CAM_NO_OF_PARAM;i++)
	{
		if (image_setting_index & (1<<i))
		{
			switch (i)
			{
				case CAM_PARAM_CONTRAST:
					adjustment_brightness_contrast_para(scene_id,isp_preview_config_data.brightness_level,isp_preview_config_data.contrast_level);
				break;
				case CAM_PARAM_BRIGHTNESS:
					adjustment_brightness_contrast_para(scene_id,isp_preview_config_data.brightness_level,isp_preview_config_data.contrast_level);
				break;
				case CAM_PARAM_HUE:
					if (scene_id==SCENARIO_MPEG_ENCODE_ID)
						ASSERT(0);
					adjustment_hue_para(scene_id,isp_preview_config_data.hue_value);
				break;
				case CAM_PARAM_WB:
					awb_set_manual_gain(isp_preview_config_data.wb_mode);
					awb_set_gain();
				break;
				case CAM_PARAM_EXPOSURE:
					ae_set_ev((kal_int8) (isp_preview_config_data.ev_value-4));
				break;
				case CAM_PARAM_BANDING:
					ae_select_band(isp_preview_config_data.banding_freq);
				break;
				case CAM_PARAM_SATURATION:
				   adjustment_saturation_para(scene_id,isp_preview_config_data.saturation_value);
				break;
				case CAM_PARAM_NIGHT_MODE:
					image_sensor_func->set_camera_night_mode(isp_preview_config_data.night_mode);
                    /* skip setting for cct mode */
            		if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)				
            		{		
					if(isp_preview_config_data.night_mode)
						set_camera_mode_para(CAMERA_PARA_NIGHT_MODE);
               else
               {
                  if(isp_operation_state==ISP_MPEG4_ENCODE_STATE)
         	         set_camera_mode_para(CAMERA_PARA_VIDEO_MODE);
                  else
         	         set_camera_mode_para(CAMERA_PARA_PREVIEW_MODE);
               }
                    }                
					if(isp_preview_config_data.image_effect!=0)
						image_effect_enc_process(isp_preview_config_data.image_effect);
				break;
				case CAM_PARAM_EV_VALUE:
					ae_set_expovalue(isp_preview_config_data.exposure_value);
				break;
			}
			image_setting_index &=~(1<<i);
		}
	}

#if defined(TVIN_SUPPORT)||defined(ANALOG_TV_SUPPORT)   
}
#endif

#endif /* YUV_SENSOR_SUPPORT */
#endif /* ISP_SUPPORT */
}	/* background_image_setting() */

void camera_operation_setting(kal_uint8 func_sel, kal_uint16 para)
{
#if ((!defined(DRV_ISP_6219_SERIES))&&defined(ISP_SUPPORT))
#if (defined(YUV_SENSOR_SUPPORT))
	camera_yuv_operation_setting(func_sel, para);
#else /* !(YUV_SENSOR_SUPPORT) */
       #if defined(ANALOG_TV_SUPPORT)  
          if(mmi_get_analog_tv_current_state()==KAL_TRUE)	
	    {
	     camera_yuv_operation_setting(func_sel, para);
 	    }
         else
        {
     #endif  /*ANALOG_TV_SUPPORT*/	
	switch(func_sel)
	{
		case CAM_DSC_MODE:
			/* CAM_AUTO_DSC, CAM_PORTRAIT, CAM_LANDSCAPE, CAM_SPORT, CAM_FLOWER, CAM_NIGHTSCENE,
				CAM_TV_MODE, CAM_AV_MODE, CAM_ISO_MODE. Each mode are EXCLUSIVE!! */
			dsc_status.dscmode=para;
			lut_info.dscmode=dsc_status.dscmode;
			AE_LUT=get_ae_lut(lut_info);
			/* update AE_INDEX_ENV with table offset */
			AE_INDEX_ENV = ae_env_index_offset(AE_INDEX);
			MAX_EXPOSURE_LINES=AE_LUT[0].shutter;
			if(device_support_info.ae.iris>1)
				IRIS_LUT=get_iris_lut(lut_info);
			/* init start index of change mode */
			AE_INDEX = ae_apply_index_update(dsc_status.dscmode, dsc_status.ae.iso, AE_INDEX_ENV);
    			AE_INDEX_C = AE_INDEX;
				
            if(device_support_info.ae.sensor_basegain==0)
                device_support_info.ae.sensor_basegain = BASEGAIN;
				
			if(dsc_status.dscmode==CAM_NIGHTSCENE)
				camera_image_setting(CAM_PARAM_NIGHT_MODE,1);
			else
				camera_image_setting(CAM_PARAM_NIGHT_MODE,0);
#if (defined(AF_SUPPORT))				
			if(dsc_status.dscmode==CAM_FLOWER)
			{
				dsc_status.af.mode=CAM_AF_MACRO_MODE;
				dsc_status.af.range=AF_MACRO_RANGE;
				af_table_search_range_config(dsc_status.af.range);
				set_af_proc_para(dsc_status.af.mode,KAL_FALSE);
			}
			else if(dsc_status.dscmode==CAM_LANDSCAPE)
			{
				dsc_status.af.mode=CAM_AF_INFINITE_MODE;
				dsc_status.af.range=AF_INFINITE_RANGE;
				af_table_search_range_config(dsc_status.af.range);
				set_af_proc_para(dsc_status.af.mode,KAL_FALSE);
			}
			else if((dsc_status.dscmode==CAM_PORTRAIT)||(dsc_status.dscmode==CAM_SPORT)||
				(dsc_status.dscmode==CAM_NIGHTSCENE)||(dsc_status.dscmode==CAM_AUTO_DSC))
			{
				dsc_status.af.mode=CAM_AF_AUTO_MODE;
				dsc_status.af.range=AF_AUTO_RANGE;
				af_table_search_range_config(dsc_status.af.range);
				set_af_proc_para(dsc_status.af.mode,KAL_FALSE);
			}
#endif
		break;
		case CAM_AE_METERING:
			/* CAM_AE_METER_AUTO, CAM_AE_METER_SPOT, CAM_AE_METER_CENTRAL, CAM_AE_METER_AVERAGE for auto exposure */
			dsc_status.ae.metering=para;
		break;
#if (defined(AF_SUPPORT))
		case CAM_AF_KEY:
			/* CAM_AF_RELEASE, CAM_AF_ONE_TIME, CAM_AF_CONTINUE for triggering auto focus */
			if(dsc_status.af.mode==CAM_AF_MANUAL_MODE)
			{
				ASSERT(0);
			}
			if((para==CAM_AF_ONE_TIME)||(para==CAM_AF_CONTINUE))
			{
				if (af_operation_state == AF_FREEZE_STATE)//add delay when AF in freeze
				{
					AF_release_delay = 0;//AF delay count
					af_operation_state=AF_COLLECT_STATE;
				}
				else if (af_operation_state == AF_STANDBY_STATE)//correct state w/o delay
				{
				af_operation_state=AF_COLLECT_STATE;
			        }
				else//invalid AF state
				{
					ASSERT(0);
				}
			}
			else
			{
				af_operation_state=AF_STANDBY_STATE;
				ae_enable_flag=ae_enable_flag_backup;
				awb_enable_flag=awb_enable_flag_backup;
				AF_release_delay = 0;//AF delay count when AF release
			}
			af_trigger_setting((kal_uint8)para);
			af_fail_count=0;
			af_detail_search=KAL_FALSE;
			af_count=0;
			af_oper_data.AF_wind_y_delay = 0;//6228 with y shift
			dsc_status.af.trigger=para;
		break;
		case CAM_AF_METERING:
			/* CAM_AF_SINGLE_ZONE, CAM_AF_MULTI3_ZONE, CAM_AF_MULTI5_ZONE */
			dsc_status.af.metering=para;
			af_zone_setting(dsc_status.af.metering);
		break;
		case CAM_AF_MODE:
			/* CAM_AF_AUTO_MODE, CAM_AF_MACRO_MODE, CAM_AF_INFINITE_MODE, CAM_AF_MANUAL_MODE */
			if(isp_preview_config_data.dsc_mode==CAM_FLOWER)//scenario modified
			{
				dsc_status.af.mode=CAM_AF_MACRO_MODE;
				dsc_status.af.range=AF_MACRO_RANGE;
				af_table_search_range_config(dsc_status.af.range);
			}
			else
			{
				dsc_status.af.mode=para;
				if(dsc_status.af.mode==CAM_AF_AUTO_MODE)
					dsc_status.af.range=AF_AUTO_RANGE;
				else if(dsc_status.af.mode==CAM_AF_MACRO_MODE)
					dsc_status.af.range=AF_MACRO_RANGE;
				else if(dsc_status.af.mode==CAM_AF_INFINITE_MODE)
					dsc_status.af.range=AF_INFINITE_RANGE;
				af_table_search_range_config(dsc_status.af.range);
			}
			if(dsc_status.af.mode!=CAM_AF_MANUAL_MODE)
				set_af_proc_para(dsc_status.af.mode,KAL_FALSE);
		break;
		case CAM_MANUAL_FOCUS_DIR:
			/* CAM_FOCUS_STOP, CAM_FOCUS_FORWARD, CAM_FOCUS_BACKWARD, CAM_FOCUS_FORWARD_CONTINUE, CAM_FOCUS_BACKWARD_CONTINUE */
			dsc_status.af.mfdir=para;
			if((dsc_status.af.mode==CAM_AF_MANUAL_MODE)&&
				((dsc_status.af.mfdir == CAM_FOCUS_FORWARD)||(dsc_status.af.mfdir == CAM_FOCUS_BACKWARD)))
				manual_focus_setting(dsc_status.af.mfdir);
		break;
#endif
		case CAM_SHUTTER_PRIORITY:
			/* index of shutter value while shutter_priority enable */
			dsc_status.ae.tv=para;
		break;
		case CAM_APERTURE_PRIORITY:
			/* index of aperture value while aperture_priority enable */
			dsc_status.ae.av=para;
		break;
		case CAM_ISO:
			/* CAM_ISO_AUTO, CAM_ISO_100, CAM_ISO_200, CAM_ISO_400 */
			dsc_status.ae.iso=para;
			if (dsc_status.dscmode == CAM_ISO_MODE)
			{
				/* init start index of change mode */
				AE_INDEX = ae_apply_index_update(dsc_status.dscmode, dsc_status.ae.iso, AE_INDEX_ENV);
    				AE_INDEX_C = AE_INDEX;
			}
		break;
		case CAM_FLASH_MODE:
			/* CAM_FLASH_OFF, CAM_FLASH_ON, CAM_FLASH_AUTO, CAM_FLASH_REDEYE */
			dsc_status.ae.flash=para;
		break;
	}
#if defined(ANALOG_TV_SUPPORT)  
}
#endif

#endif /* YUV_SENSOR_SUPPORT */
#endif
}

void set_isp_driving_current(kal_uint8 current)
{
#if (defined(ISP_SUPPORT))
   kal_uint32 save_irq_mask;
	kal_uint16 current_value=0;

	switch (current)
	{
		case ISP_DRIVING_2MA:
			current_value=0;
		break;
		case ISP_DRIVING_4MA:
			current_value=0x2;
		break;
		case ISP_DRIVING_6MA:
			current_value=0x1;
		break;
		case ISP_DRIVING_8MA:
			current_value=0x3;
		break;
	}

	save_irq_mask=SaveAndSetIRQMask();
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES))
	*((volatile unsigned short *) 0x80000708) &= ~0x18;
	*((volatile unsigned short *) 0x80000708) |= (current_value<<3);
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
	*((volatile unsigned int *) (0x80000714)) &= ~0x06;
	*((volatile unsigned int *) (0x80000714)) |= (current_value<<1);
#elif (defined(DRV_ISP_6225_SERIES))
	*((volatile unsigned short *) 0x80000704) &= ~0x18;
	*((volatile unsigned short *) 0x80000704) |= (current_value<<3);
#endif
   RestoreIRQMask(save_irq_mask);
#endif /* ISP_SUPPORT */
}	/* set_isp_driving_current() */

#endif /* MT6219 */
