/****************************BF3403_BYD_VGA_Sensor***************************
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
 *   image_sensor.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor driver function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "sccb.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "camera_para.h"
#include "upll_ctrl.h"
#include "med_api.h"


#define BF3403_WRITE_ID							0x42
#define BF3403_READ_ID								0x43
#define BF3403_SENSOR_ID							0x3403

extern kal_uint8  start_grab_x_offset, start_grab_y_offset;
extern kal_bool   gVGAmode, sensor_night_mode, MPEG4_encode_mode, g_bMJPEG_mode;
extern kal_uint8  preview_pclk_division, capture_pclk_division;
extern kal_uint16 dummy_pixels, dummy_lines, extra_exposure_lines;
extern kal_uint16 exposure_lines;

/* MAX/MIN Explosure Lines Used By AE Algorithm */
extern kal_uint16 MAX_EXPOSURE_LINES;
extern kal_uint8  MIN_EXPOSURE_LINES;
/* Parameter For Engineer mode function */
extern kal_uint32 FAC_SENSOR_REG;
/* Image Sensor ID */
extern kal_uint16 sensor_id;

extern kal_bool sensor_cap_state;

extern kal_uint16 sensor_frame_rate;



void write_BF3403_shutter(kal_uint16 shutter)
{
    kal_uint8 temp_reg;

	if(shutter<=VGA_EXPOSURE_LIMITATION)
	{
		sensor_frame_rate=(10*PIXEL_CLK/VGA_PERIOD_PIXEL_NUMS)/(VGA_PERIOD_LINE_NUMS+dummy_lines);
		extra_exposure_lines=0;
	}
	else
	{
		sensor_frame_rate=(10*PIXEL_CLK/VGA_PERIOD_PIXEL_NUMS)/(shutter+dummy_lines);
		extra_exposure_lines=shutter-VGA_EXPOSURE_LIMITATION;
	}

	if(shutter>VGA_EXPOSURE_LIMITATION)
		shutter=VGA_EXPOSURE_LIMITATION;
		
	write_cmos_sensor(0x2D,extra_exposure_lines&0xFF);                   // ADVFL(LSB of extra exposure lines)
	write_cmos_sensor(0x2E,(extra_exposure_lines&0xFF00)>>8);            // ADVFH(MSB of extra exposure lines)

	temp_reg=read_cmos_sensor(0x04);
	write_cmos_sensor(0x04,( (temp_reg&0xFC) | (shutter&0x3) ));		// AEC[b1~b0]
	write_cmos_sensor(0x10,((shutter&0x3FC)>>2));					// AEC[b9~b2]
	write_cmos_sensor(0x07,((shutter&0x7C00)>>10));					// AEC[b10]/AEC[b15~b10]
}	/* write_BF3403_shutter */

kal_uint16 read_BF3403_shutter(void)
{
	kal_uint8 temp_reg1, temp_reg2, temp_reg3, temp_reg4, temp_reg5;
	kal_uint16 shutter;

	temp_reg1=read_cmos_sensor(0x04);										// AEC[b1~b0]
	temp_reg2=read_cmos_sensor(0x10);										// AEC[b9~b2]
	temp_reg3=read_cmos_sensor(0x07);										// AEC[b15~b10]
	
	temp_reg4=read_cmos_sensor(0x2D);
	temp_reg5=read_cmos_sensor(0x2E);
	
	shutter=((temp_reg3&0x1F)<<10)|(temp_reg2<<2)|(temp_reg1&0x3);	// AEC[b10]/AEC[b15~b10]
	extra_exposure_lines=(temp_reg5<<8)|(temp_reg4);
	
	exposure_lines=shutter+extra_exposure_lines;

	return exposure_lines;
}	/* read_BF3403_shutter */

void write_BF3403_gain(kal_uint16 gain)
{
   kal_uint16 temp_reg;
   
   if(gain>=1*BASEGAIN && gain<2*BASEGAIN)
   {
      sensor_global_gain=gain&(~0x3);
      temp_reg=(sensor_global_gain-1*BASEGAIN)/4;
   }
   else if(gain>=2*BASEGAIN && gain<4*BASEGAIN)
   {
      sensor_global_gain=gain&(~0x7);
      temp_reg=0x10;
      temp_reg|=(sensor_global_gain-2*BASEGAIN)/8;
   }
   else if(gain>=4*BASEGAIN && gain<8*BASEGAIN)
   {
      sensor_global_gain=gain&(~0xF);
      temp_reg=0x30;
      temp_reg|=(sensor_global_gain-4*BASEGAIN)/16;
   }
   else if(gain>=8*BASEGAIN && gain<16*BASEGAIN)
   {
      sensor_global_gain=gain&(~0x1F);
      temp_reg=0x70;
      temp_reg|=(sensor_global_gain-8*BASEGAIN)/32;
   }
   else if(gain>=16*BASEGAIN)
   {
      sensor_global_gain=gain&(~0x3F);
      temp_reg=0xF0;
      temp_reg|=(sensor_global_gain-16*BASEGAIN)/64;
   }
   else
      ASSERT(0);
   
   write_cmos_sensor(0x00,temp_reg);
}  /* write_BF3403_gain */

kal_uint16 read_BF3403_gain(void)
{
   kal_uint16 sensor_gain;
   kal_uint16 temp_reg;
   
   temp_reg=read_cmos_sensor(0x00);
   sensor_gain=(BASEGAIN+((temp_reg&0x1F)*BASEGAIN)/16);
   
   if(temp_reg&0x20)
      sensor_gain<<=1;
      
   if(temp_reg&0x40)
      sensor_gain<<=1;
      
   if(temp_reg&0x80)
      sensor_gain<<=1;
      
   return sensor_gain;
}  /* read_BF3403_gain */

void set_BF3403_dummy(kal_uint16 pixels, kal_uint16 lines)
{
	write_cmos_sensor(0x2A,((pixels&0x700)>>4));
	write_cmos_sensor(0x2B,(pixels&0xFF));
	write_cmos_sensor(0x92,(lines&0xFF));
	write_cmos_sensor(0x93,((lines&0xFF00)>>8));
}	/* set_BF3403_dummy */

/*************************************************************************
* FUNCTION
*	config_BF3403_window
*
* DESCRIPTION
*	This function config the hardware window of BF3403 for getting specified
*  data of that window.
*
* PARAMETERS
*	start_x : start column of the interested window
*  start_y : start row of the interested window
*  width  : column widht of the itnerested window
*  height : row depth of the itnerested window
*
* RETURNS
*	the data that read from BF3403
*
* GLOBALS AFFECTED
*
*************************************************************************/
void config_BF3403_window(kal_uint16 startx,kal_uint16 starty,kal_uint16 width, kal_uint16 height)
{
	kal_uint16 endx=(startx+width-1);
	kal_uint16 endy=(starty+height-1);
	kal_uint8  temp_reg1, temp_reg2;
	
	temp_reg1=(read_cmos_sensor(0x03)&0xF0);
	temp_reg2=(read_cmos_sensor(0x32)&0xC0);

	// Horizontal
	write_cmos_sensor(0x32,0x80|((endx&0x7)<<3)|(startx&0x7));	// b[5:3]:HREF end low 3bits. b[2:0]:HREF start low 3bits.
	write_cmos_sensor(0x17,(startx&0x7F8)>>3);			// HREF start high 8bits
	write_cmos_sensor(0x18,(endx&0x7F8)>>3);			// HREF end high 8bits
	// Vertical
	write_cmos_sensor(0x03,temp_reg1|((endy&0x3)<<2)|(starty&0x3));	// b[3:2]:VREF end low 2bits. b[1:0]:VREF start low 2bits.
	write_cmos_sensor(0x19,(starty&0x3FC)>>2);   			// VREF start high 8bits
	write_cmos_sensor(0x1A,(endy&0x3FC)>>2);		   	// VREF end high 8bits
}	/* config_BF3403_window */



/*************************************************************************
* FUNCTION
*	init_BF3403
*
* DESCRIPTION
*	This function initialize the registers of CMOS sensor and ISP control register.
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
kal_int8 init_BF3403(void)
{
	int idx;

	cis_module_power_on(KAL_TRUE);     
	kal_sleep_task(2);				 
	camera_module_pin_set(SCCB_SERIAL_CLK_PIN, 1);
	camera_module_pin_set(SCCB_SERIAL_DATA_PIN, 1);
	kal_sleep_task(2);
 
	RESET_CMOS_SENSOR_MODE2;			
	SET_CMOS_CLOCK_POLARITY_LOW;
	SET_VSYNC_POLARITY_LOW;
	SET_HSYNC_POLARITY_LOW;  
	ENABLE_CAMERA_INDATA_FORMAT;
	SET_CAMERA_INPUT_TYPE(INPUT_YUV422);
	ENABLE_CAMERA_TG_CLK_48M;
	UPLL_Enable(UPLL_OWNER_ISP);    
	set_isp_driving_current(camera_para.SENSOR.reg[CMMCLK_CURRENT_INDEX].para);
	POWER_ON_CMOS_SENSOR;
	kal_sleep_task(2);

#ifdef DOUBLE_CAMERA_SUPPORT 
	main_camera_is_ready = image_sensor_is_main_camera_ready();
	sub_camera_is_ready = image_sensor_is_sub_camera_ready();

	// camera reset
	INIT_CAMERA_SENSOR_RESET;
	
	main_camera_active = mmi_polling_active_camera();

	if( 
		KAL_TRUE == main_camera_is_ready 
		&& ( KAL_FALSE == sub_camera_is_ready ||KAL_TRUE == main_camera_active)
	)
	{
		camera_module_pin_set( MODULE_CMPDN_PIN_2, 1 );
		kal_sleep_task(2);	
		camera_module_pin_set( MODULE_CMPDN_PIN, 0 );
		INIT_MAIN_CAMERA_SENSOR;
		main_camera_active = KAL_TRUE;
	}
	else if( 
		KAL_TRUE == sub_camera_is_ready 
		&& ( KAL_FALSE == main_camera_is_ready||KAL_FALSE == main_camera_active )
	)
	{
		camera_module_pin_set( MODULE_CMPDN_PIN, 1 );
		kal_sleep_task(2);	
		camera_module_pin_set( MODULE_CMPDN_PIN_2, 0 );
		INIT_SUB_CAMERA_SENSOR;
		main_camera_active = KAL_FALSE;
	}
	else
	{
		cis_module_power_on(KAL_FALSE); 
		return -1;
	}
	return -1;
#else /* DOUBLE_CAMERA_SUPPORT */
	INIT_CAMERA_SENSOR_RESET;
	camera_module_pin_set( MODULE_CMPDN_PIN, 0 );
	kal_sleep_task(2);

	if( KAL_TRUE == image_sensor_is_main_camera_ready() )
	{
		INIT_MAIN_CAMERA_SENSOR;
	}
	cis_module_power_on(KAL_FALSE); 
	return -1;
#endif /* DOUBLE_CAMERA_SUPPORT */

}	/* init_cmos_sensor() */

/*************************************************************************
* FUNCTION
*	power_off_BF3403
*
* DESCRIPTION
*	This function is to turn off sensor module power.
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

void power_off_BF3403(void)
{
	cis_module_power_on(KAL_FALSE);      // Power Off CIS Power
	UPLL_Disable(UPLL_OWNER_ISP);
	#ifndef HW_SCCB
	   SET_SCCB_CLK_LOW;
	   SET_SCCB_DATA_LOW;
	#endif
}	/* power_off_BF3403 */

/*************************************************************************
* FUNCTION
*	get_BF3403_id
*
* DESCRIPTION
*	This function return the sensor read/write id of SCCB interface.
*
* PARAMETERS
*	*sensor_write_id : address pointer of sensor write id
*  *sensor_read_id  : address pointer of sensor read id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_BF3403_id(kal_uint8 *sensor_write_id, kal_uint8 *sensor_read_id)
{
	*sensor_write_id=BF3403_WRITE_ID;
	*sensor_read_id=BF3403_READ_ID;
}	/* get_BF3403_id */

/*************************************************************************
* FUNCTION
*	get_BF3403_size
*
* DESCRIPTION
*	This function return the image width and height of image sensor.
*
* PARAMETERS
*	*sensor_width : address pointer of horizontal effect pixels of image sensor
*  *sensor_height : address pointer of vertical effect pixels of image sensor
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_BF3403_size(kal_uint16 *sensor_width, kal_uint16 *sensor_height)
{
	*sensor_width=IMAGE_SENSOR_VGA_WIDTH;			/* pixel numbers actually used in one frame */
	*sensor_height=IMAGE_SENSOR_VGA_HEIGHT;		/* line numbers actually used in one frame */
}	/* get_BF3403_size */

/*************************************************************************
* FUNCTION
*	get_BF3403_period
*
* DESCRIPTION
*	This function return the image width and height of image sensor.
*
* PARAMETERS
*	*pixel_number : address pointer of pixel numbers in one period of HSYNC
*  *line_number : address pointer of line numbers in one period of VSYNC
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_BF3403_period(kal_uint16 *pixel_number, kal_uint16 *line_number)
{
	*pixel_number=VGA_PERIOD_PIXEL_NUMS;		/* pixel numbers in one period of HSYNC */
	*line_number=VGA_PERIOD_LINE_NUMS;			/* line numbers in one period of VSYNC */
}	/* get_BF3403_period */

void BF3403_preview(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	volatile kal_uint32 temp_reg2=read_cmos_sensor(0x1E), temp_reg1=(temp_reg2&0x0F);
	kal_uint16 current_shutter;
	kal_uint16 reg_35;
	kal_uint16 reg_1e;
	
	sensor_cap_state=KAL_FALSE;

	g_bMJPEG_mode = KAL_FALSE;

	kal_prompt_trace(MOD_MMI,"------->>>> BF3403 Begin");

		write_cmos_sensor(0x11,0x80);	//MCLK = PCLK
		
		if((sensor_config_data->isp_op_mode==ISP_MJPEG_PREVIEW_MODE)||
			(sensor_config_data->isp_op_mode==ISP_MJPEG_ENCODE_MODE))
		{
	
				MPEG4_encode_mode=KAL_FALSE;
				g_bMJPEG_mode = KAL_TRUE;
	
				/* config TG of ISP to match the setting of image sensor*/
				SET_TG_OUTPUT_CLK_DIVIDER(3);			//10fps
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(2);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(3);
				SET_CMOS_DATA_LATCH(2);
				dummy_pixels=0;
			  dummy_lines=255;		
	
	/*
				SET_TG_OUTPUT_CLK_DIVIDER(7);			//7.5fps
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(3);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(7);
				SET_CMOS_DATA_LATCH(3);
	*/
		}
		else
		{
			if(sensor_config_data->frame_rate==0x0F)		// MPEG4 Encode Mode
			{
			
			kal_prompt_trace(MOD_MMI," BF3403  video");
				MPEG4_encode_mode=KAL_TRUE;
			
				/* config TG of ISP to match the setting of image sensor*/
				SET_TG_OUTPUT_CLK_DIVIDER(3);
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(2);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(3);
				SET_CMOS_DATA_LATCH(2);
	
				dummy_pixels=0;
				dummy_lines=20;
			}
			else
			{
			
			kal_prompt_trace(MOD_MMI," BF3403  preview");
				MPEG4_encode_mode=KAL_FALSE;
				
				/* config TG of ISP to match the setting of image sensor*/
				SET_TG_OUTPUT_CLK_DIVIDER(3);			//30fps
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(2);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(3);
				SET_CMOS_DATA_LATCH(2);
			
				dummy_pixels=0;
				dummy_lines=255;
			}
		}
	
		preview_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
	
		switch (sensor_config_data->image_mirror)
		{
			case IMAGE_HV_MIRROR:
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
				//while(temp_reg2 != (0x00|temp_reg1))
				{
					write_cmos_sensor(0x1E,(0x30|temp_reg1)); 
					temp_reg2=(0x00|temp_reg1);
				};
 			break;
			case IMAGE_H_MIRROR:
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
				while(temp_reg2 != (0x20|temp_reg1))
				{
					write_cmos_sensor(0x1E,(0x20|temp_reg1));
					temp_reg2=read_cmos_sensor(0x1E);
				};
			break;
			case IMAGE_V_MIRROR:
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
				while(temp_reg2 != (0x10|temp_reg1))
				{
					write_cmos_sensor(0x1E,(0x10|temp_reg1));
					temp_reg2=read_cmos_sensor(0x1E);
				};
			break;
			case IMAGE_NORMAL:
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
				//while(temp_reg2 != (0x30|temp_reg1))
				{
					write_cmos_sensor(0x1E,(0x00|temp_reg1));																																																																																		   
					temp_reg2=(0x00|temp_reg1); 	
					
					write_cmos_sensor(0xf0,0x01);
					write_cmos_sensor(0xe0,0x0E);
					write_cmos_sensor(0x1f,0x10);
					write_cmos_sensor(0x22,0x10);
					write_cmos_sensor(0x33,0x80);
					write_cmos_sensor(0x34,0x88);
					write_cmos_sensor(0x35,0x20);
					write_cmos_sensor(0x3F,0xA0);
					write_cmos_sensor(0xf0,0x00);
				};

			break;
		}
	
		image_window->grab_start_x=IMAGE_SENSOR_VGA_INSERTED_PIXELS+start_grab_x_offset;
		image_window->grab_start_y=IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines+start_grab_y_offset;
		image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
		image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT;
		
		set_BF3403_dummy(dummy_pixels,dummy_lines);
		write_BF3403_shutter(exposure_lines);
		kal_sleep_task(30);
		
	
		if (sensor_config_data->isp_op_mode == ISP_MJPEG_ENCODE_MODE) {
			current_shutter=read_BF3403_shutter();
			if (current_shutter < 510)
				current_shutter = 510;
	
			sensor_config_data->sensor_frame_rate = 10 * (48000000 / preview_pclk_division / 784 / current_shutter / 2); // 1fps=10
		}else {
			// ISP_MJPEG_ENCODE_MODE mode does not invok YUV setting API after preview function
			// If turn on AEC/AGC/AWB in ISP_MJPEG_ENCODE_MODE mode, the AWB setting will be overwriten.
			write_cmos_sensor(0x13, 0xF7);	// Turn ON AEC/AGC/AWB
		}
	
		kal_sleep_task(100);
}	/* BF3403_preview */

void BF3403_capture(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
    volatile kal_uint32 shutter=exposure_lines;
    kal_uint8 temp_reg;
    kal_uint32 tmp_shutter;
    
    sensor_cap_state=KAL_TRUE;
	
	//if(MPEG4_encode_mode)
	// ASSERT(0);                           //modified by wyw
	   	
	if(sensor_config_data->enable_shutter_tansfer==KAL_TRUE)
		shutter=sensor_config_data->capture_shutter;
		
	#ifdef OUTPUT_DEBUG_INFO
	sprintf(temp_buffer, "Begin of BF3403_capture");
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	sprintf(temp_buffer, "cap_shutter:%d, pre_shut:%d", shutter, exposure_lines);
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	#endif

    if(!(sensor_config_data->frame_rate==0xF0))	// If not WEBCAM mode.
    {
		kal_prompt_trace(MOD_MMI,"Not WEBCAM MODE");  

	// Turn off night mode
        temp_reg=read_cmos_sensor(0x3B);
        write_cmos_sensor(0x3B,temp_reg&~0x80);

        write_cmos_sensor(0x13,0xE2);  // Turn OffF AGC/AWB/AEC
        
        shutter=read_BF3403_shutter();
	// sensor_global_gain=read_BF3403_gain();
    }
    	
	if ((image_window->image_target_width<=IMAGE_SENSOR_1M_WIDTH)&&
		(image_window->image_target_height<=IMAGE_SENSOR_1M_HEIGHT))
	{	/* Less than VGA Mode */
		if (image_window->digital_zoom_factor>=(ISP_DIGITAL_ZOOM_INTERVAL<<1))
		{
			kal_prompt_trace(MOD_MMI,"BF3403 ZOOM ");

			write_cmos_sensor(0x11,0x83);
			
			SET_TG_PIXEL_CLK_DIVIDER(7);
			SET_CMOS_DATA_LATCH(4);
			
			if ((image_window->image_target_width==IMAGE_SENSOR_1M_WIDTH)&&
				(image_window->image_target_height==IMAGE_SENSOR_1M_HEIGHT))
				dummy_pixels=2000;
			else
				dummy_pixels=VGA_PERIOD_PIXEL_NUMS/4;
			dummy_lines=0;
		}
		else
		{
			if(sensor_config_data->frame_rate==0xF0)	// That means WEBCAM mode.
			{
 			    write_cmos_sensor(0x11,0x80);
			    
			    SET_TG_PIXEL_CLK_DIVIDER(1);
				SET_CMOS_DATA_LATCH(1);
				
				start_grab_x_offset=0;
				start_grab_y_offset=0;
				
				dummy_pixels=200;
				dummy_lines=0;
			}
			else
			{
				kal_prompt_trace(MOD_MMI,"BF3403 Capture");

				write_cmos_sensor(0x11,0x81);
			    
				SET_TG_PIXEL_CLK_DIVIDER(3);
				SET_CMOS_DATA_LATCH(2);

			}
		}
		
		capture_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
		
		shutter=(2*shutter*preview_pclk_division)/(4*capture_pclk_division);
		shutter=(shutter*VGA_PERIOD_PIXEL_NUMS)/(VGA_PERIOD_PIXEL_NUMS+dummy_pixels);
			if(shutter<1)
		shutter=1;
		}

	if ((image_window->image_target_width>=IMAGE_SENSOR_1M_WIDTH)&&
			(image_window->image_target_height>=IMAGE_SENSOR_1M_HEIGHT))
			{

			write_cmos_sensor(0x11,0x83);
			
			SET_TG_PIXEL_CLK_DIVIDER(3);
			SET_CMOS_DATA_LATCH(3);
					
			dummy_pixels=1200;
			capture_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
		
		shutter=(shutter*preview_pclk_division)/capture_pclk_division;
		shutter=(2*shutter*VGA_PERIOD_PIXEL_NUMS)/(2*(VGA_PERIOD_PIXEL_NUMS+dummy_pixels));
			   }
		

		image_window->grab_start_x=IMAGE_SENSOR_VGA_INSERTED_PIXELS;
		image_window->grab_start_y=IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines;
		image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
		image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT - 1; // minus 1 to avoid the last black line
	

	set_BF3403_dummy(dummy_pixels,dummy_lines);
	write_BF3403_shutter(shutter);
	//write_BF3403_gain(sensor_global_gain+10);
	//kal_sleep_task(10);
	//write_BF3403_gain(sensor_global_gain);
	
	#ifdef OUTPUT_DEBUG_INFO
	sprintf(temp_buffer, "cap_shut:%d, pre_shut:%d, pre_pclk_div=%d, cap_pclk_div=%d, dummy_p=%d, dummy_l=%d", shutter, exposure_lines, preview_pclk_division, capture_pclk_division, dummy_pixels, dummy_lines);
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	sprintf(temp_buffer, "End of BF3403_capture");
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	#endif
}	/* BF3403_capture() */

/*************************************************************************
* FUNCTION
*	write_BF3403_reg
*
* DESCRIPTION
*	This function set the register of BF3403.
*
* PARAMETERS
*	addr : the register index of BF3403
*  para : setting parameter of the specified register of BF3403
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void write_BF3403_reg(kal_uint32 addr, kal_uint32 para)
{
	write_cmos_sensor(addr,para);
}	/* write_BF3403_reg() */

/*************************************************************************
* FUNCTION
*	read_cmos_sensor
*
* DESCRIPTION
*	This function read parameter of specified register from BF3403.
*
* PARAMETERS
*	addr : the register index of BF3403
*
* RETURNS
*	the data that read from BF3403
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 read_BF3403_reg(kal_uint32 addr)
{
	return (read_cmos_sensor(addr));
}	/* read_BF3403_reg() */

/*************************************************************************
* FUNCTION
*	set_BF3403_shutter
*
* DESCRIPTION
*	This function set e-shutter of BF3403 to change exposure time.
*
* PARAMETERS
*	shutter : exposured lines
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void set_BF3403_shutter(kal_uint16 shutter)
{
	exposure_lines=shutter;
	write_BF3403_shutter(shutter);
}	/* set_BF3403_shutter */

/*************************************************************************
* FUNCTION
*	set_BF3403_gain
*
* DESCRIPTION
*	This function is to set global gain to sensor.
*
* PARAMETERS
*	gain : sensor global gain(base: 0x40)
*
* RETURNS
*	the actually gain set to sensor.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 set_BF3403_gain(kal_uint16 gain)
{
   sensor_global_gain=(gain*sensor_gain_base)/BASEGAIN;
   write_BF3403_gain(sensor_global_gain);
   sensor_global_gain=(sensor_global_gain*BASEGAIN)/sensor_gain_base;
   return sensor_global_gain;
}

/*************************************************************************
* FUNCTION
*	BF3403_night_mode
*
* DESCRIPTION
*	This function night mode of BF3403.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void BF3403_night_mode(kal_bool enable)
{
    kal_uint8 night  = read_cmos_sensor(0x3B);
    kal_uint8 night2 = read_cmos_sensor(0x13);//read AEC/AWB/AGC 

    if (!sensor_cap_state)
		{
		if (enable)
			{
			if (g_bMJPEG_mode == KAL_TRUE)
				{
					//
					// this mode is used by MJPEG mode only
					//
					write_cmos_sensor(0x3B, night & 0x1f);
					 /* set Max gain to 16X */                                                     
					write_cmos_sensor(0x14, 0x38); 
				}
			else
				{  
			                //                                                                            
			                // this mode is used by camera or MPEG4 Apps
			                //
			                write_cmos_sensor(0x3B, night | 0xE0);//(0x3B, night | 0xC0);//分频//(0x3B, night | 0xE0);//不分频
			                
			                write_cmos_sensor(0xf0, 0x01);    //lj add 071122     
			                write_cmos_sensor(0x8e, 0x0f);    //lj add 071122     
			                write_cmos_sensor(0x8f, 0xa0);    //lj add 071122    
			                write_cmos_sensor(0X13, 0X00);    //lj add 071123
			                write_cmos_sensor(0X3b, 0X00);    //lj add 071123
			                write_cmos_sensor(0X04, 0X03);    //lj add 071123
			                write_cmos_sensor(0X10, 0X7f);    //lj add 071123
			                write_cmos_sensor(0X07, 0X00);    //lj add 071123
			                //write_cmos_sensor(0X11, 0X83); 
			                write_cmos_sensor(0X2e, 0X0a);  //(0X2e, 0X05) //分频//(0X2e, 0X0a); //不分频 //lj add 071123
			                write_cmos_sensor(0X2d, 0Xff);  //(0X2d, 0X88) //分频//(0X2d, 0Xff); //不分频 //lj add 071123
			                write_cmos_sensor(0X13, night2);  //lj add 071123
			                write_cmos_sensor(0xf0, 0x00);    //lj add 071123       
			                                                                        
			                write_cmos_sensor(0x3B, night | 0xE0);//(0x3B, night | 0xC0);//分频//(0x3B, night | 0xE0);//不分频 //lj add 071122
			               // write_cmos_sensor(0x8e, 0x00);    //lj add 071122 
			                //write_cmos_sensor(0x8f, 0x00);    //lj add 071122
			                
			                /* set Max gain to 16X */
			                write_cmos_sensor(0x14, 0x38);
			        }
        		}

	else
		{
		if(g_bMJPEG_mode == KAL_TRUE)
			{
		                //
		                // this mode is used by MJPEG mode only
		                //                                              
		                write_cmos_sensor(0x3B, night & 0x1F);          
		                /* set Max gain to 8X */
		                write_cmos_sensor(0x14, 0x28);
			}
			else 
				{
			                //
			                // this mode is used by camera or MPEG4 Apps    
			                //
			                write_cmos_sensor(0x3B, night&0x1F);
			                
			                write_cmos_sensor(0xf0, 0x01); //lj add 071122
			                write_cmos_sensor(0X3b, 0Xa2);    //lj add 071123
			                write_cmos_sensor(0x8e, 0x08); //(0x8e, 0x02) //分频//(0x8e, 0x04);//不分频//lj add 071122
			                write_cmos_sensor(0x8f, 0x00); //(0x8f, 0x00)//分频//(0x8f, 0x00);//不分频 //lj add 071122
			                write_cmos_sensor(0xf0, 0x00); //lj add 071122
			                
			                write_cmos_sensor(0x8e, 0x00);    //lj add 071122
			                write_cmos_sensor(0x8f, 0x00);    //lj add 071122
			                
			                /* set Max gain to 8X */
					  write_cmos_sensor(0x14, 0x28);
			                write_cmos_sensor(0x2D, 0x00);
			                write_cmos_sensor(0x2E, 0x00);
					
            			}
       		 }
    		}
}	/* BF3403_night_mode */

/*************************************************************************
* FUNCTION
*	set_BF3403_flashlight
*
* DESCRIPTION
*	turn on/off BF3403 flashlight .
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void set_BF3403_flashlight(kal_bool enable)
{
	// Todo
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_zoom
*
* DESCRIPTION
*	BF3403 zoom setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_zoom(kal_uint32 para)
{
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_contrast
*
* DESCRIPTION
*	BF3403 contrast setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_contrast(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_brightness
*
* DESCRIPTION
*	BF3403 brightness setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_brightness(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_hue
*
* DESCRIPTION
*	BF3403 hue setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_hue(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_gamma
*
* DESCRIPTION
*	BF3403 gamma setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_gamma(kal_uint32 para)
{
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_wb
*
* DESCRIPTION
*	BF3403 wb setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_wb(kal_uint32 para)
{
	kal_uint16 rgain=0x80, ggain=0x80, bgain=0x80;
	kal_uint8  temp_reg;
	
	temp_reg=read_cmos_sensor(0x13);
	
	switch (para)
	{
		case CAM_WB_AUTO:
			write_cmos_sensor(0x01,0x66);//(0x01,0x56),modified by wyw
			write_cmos_sensor(0x02,0x6c);//(0x02,0x44),modified by wyw
			write_cmos_sensor(0x13,temp_reg|0x2);   // Enable AWB		
			break;

		case CAM_WB_CLOUD:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x52);
			write_cmos_sensor(0x02,0x6c);
			break;		

		case CAM_WB_DAYLIGHT:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x52);
			write_cmos_sensor(0x02,0x66);
			break;		

		case CAM_WB_INCANDESCENCE:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x8c);
			write_cmos_sensor(0x02,0x59);
			break;		

		case CAM_WB_FLUORESCENT:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x7e);
			write_cmos_sensor(0x02,0x49);
			break;		

		case CAM_WB_TUNGSTEN:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x90);
			write_cmos_sensor(0x02,0x3D);
			break;

		case CAM_WB_MANUAL:		
		    // TODO
			break;		

		default:
			return KAL_FALSE;			
	}	

	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_exposure
*
* DESCRIPTION
*	BF3403 exposure setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_exposure(kal_uint32 para)
{
	switch (para)
	{
		case CAM_EV_NEG_4_3:    
            write_cmos_sensor(0x55, 0xF8);		
			break;		
		case CAM_EV_NEG_3_3:
            write_cmos_sensor(0x55, 0xD8);
			break;		
		case CAM_EV_NEG_2_3:
            write_cmos_sensor(0x55, 0xC8);
			break;				
		case CAM_EV_NEG_1_3:
            write_cmos_sensor(0x55, 0xA8);
			break;				
		case CAM_EV_ZERO:
            write_cmos_sensor(0x55, 0x88);
			break;				
		case CAM_EV_POS_1_3:
            write_cmos_sensor(0x55, 0x18);
			break;				
		case CAM_EV_POS_2_3:
            write_cmos_sensor(0x55, 0x38);
			break;				
		case CAM_EV_POS_3_3:
            write_cmos_sensor(0x55, 0x58);
			break;				
		case CAM_EV_POS_4_3:	
            write_cmos_sensor(0x55, 0x78);
			break;
		default:
			return KAL_FALSE;    
	}	
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_effect
*
* DESCRIPTION
*	BF3403 effect setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_effect(kal_uint32 para)
{
    kal_uint32  ret = KAL_TRUE;
	switch (para)
	{	
		case CAM_EFFECT_ENC_NORMAL:
			write_cmos_sensor(0x3A,0x0C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0x80);
			write_cmos_sensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_GRAYSCALE:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0x80);
			write_cmos_sensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_SEPIA:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0xC0);
			write_cmos_sensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_COLORINV:
			write_cmos_sensor(0x3A,0x2C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0x80);
			write_cmos_sensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_SEPIAGREEN:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0x40);		
			write_cmos_sensor(0x68,0x40);
			write_cmos_sensor(0x56,0x40);		
			break;					
		case CAM_EFFECT_ENC_SEPIABLUE:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0xA0);		
			write_cmos_sensor(0x68,0x40);
			write_cmos_sensor(0x56,0x40);		
			break;								
		case CAM_EFFECT_ENC_GRAYINV:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0x80);
			write_cmos_sensor(0x56,0x40);						
			break;								
		case CAM_EFFECT_ENC_COPPERCARVING:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0xF0);
			write_cmos_sensor(0x56,0x40);		    	
			break;								
    	case CAM_EFFECT_ENC_BLUECARVING:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0xB0);		
			write_cmos_sensor(0x68,0x60);
			write_cmos_sensor(0x56,0x40);		
			break;								
		case CAM_EFFECT_ENC_CONTRAST:
			write_cmos_sensor(0x3A,0x0C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0x80);
			write_cmos_sensor(0x56,0x80);
			break;							
		case CAM_EFFECT_ENC_EMBOSSMENT:
			 write_cmos_sensor(0x3A,0x14);	/*浮雕*/
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0x80);
			write_cmos_sensor(0x56,0x80);
			break;
		case CAM_EFFECT_ENC_SKETCH:	
			write_cmos_sensor(0x3A,0x24);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x44,0x00);
			write_cmos_sensor(0x56,0xa0);
			break;	
		case CAM_EFFECT_ENC_BLACKBOARD:
		case CAM_EFFECT_ENC_WHITEBOARD:
		case CAM_EFFECT_ENC_JEAN:
		case CAM_EFFECT_ENC_OIL:			
		default:
			ret = KAL_FALSE;
	}
	
	return ret;
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_banding
*
* DESCRIPTION
*	BF3403 banding setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_banding(kal_uint32 para)
{
	kal_uint8 banding;
	
	banding=read_cmos_sensor(0x3b);
	
	switch (para)
	{
		case CAM_BANDING_50HZ:
			write_cmos_sensor(0x3b,banding|0x08);	    /* 50 Hz */	
			write_cmos_sensor(0xf0,0x01);	 //wyw add for banding  071021
			write_cmos_sensor(0x80,0x01);	 //wyw add for banding  071021
			write_cmos_sensor(0xf0,0x00);  //wyw add for banding  070021
			write_cmos_sensor(0x80,0x5b);	 //lj add for banding  071021
			write_cmos_sensor(0x9d,0x99); // (0x9d,0x4c);//分频//(0x9d,0x99);//不分频
			break;                        
		case CAM_BANDING_60HZ:
			write_cmos_sensor(0x3b,banding&0xF7);	    /* 60 Hz */
			write_cmos_sensor(0xf0,0x01);	 //wyw add for banding  071021
			write_cmos_sensor(0x80,0x00);	 //wyw add for banding  071021
			write_cmos_sensor(0xf0,0x00);	 //wyw add for banding	070021
			write_cmos_sensor(0x80,0x5b);	 //lj add for banding  071021			
			write_cmos_sensor(0x9e,0x7f);	//(0x9e,0x3f); //分频//(0x9e,0x7f);//不分频 
			break;
		default:
			return KAL_FALSE;		
	}	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_saturation
*
* DESCRIPTION
*	BF3403 SATURATION setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_saturation(kal_uint32 para)
{
    // Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_nightmode
*
* DESCRIPTION
*	BF3403 night mode setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_nightmode(kal_uint32 para)
{
	BF3403_night_mode((kal_bool)para);
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3403_param_ev
*
* DESCRIPTION
*	BF3403 ev setting.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_BF3403_param_ev(kal_uint32 para)
{
	return set_BF3403_param_exposure(para);
}

/*************************************************************************
* FUNCTION
*	BF3403_yuv_sensor_setting
*
* DESCRIPTION
*	This function send command and parameter to yuv sensor module BF3403
*  to configure it
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 BF3403_yuv_sensor_setting(kal_uint32 cmd, kal_uint32 para)
{
	kal_uint32 ret = KAL_TRUE;
	switch (cmd)
	{
		case CAM_PARAM_ZOOM_FACTOR:
			ret = set_BF3403_param_zoom(para);		
			break;			
		case CAM_PARAM_CONTRAST:
			ret = set_BF3403_param_contrast(para);		
			break;					
		case CAM_PARAM_BRIGHTNESS:
			ret = set_BF3403_param_brightness(para);		
			break;							
		case CAM_PARAM_HUE:
			ret = set_BF3403_param_hue(para);		
			break;							
		case CAM_PARAM_GAMMA:
			ret = set_BF3403_param_gamma(para);		
			break;							
		case CAM_PARAM_WB:
			ret = set_BF3403_param_wb(para);		
			break;
		case CAM_PARAM_EXPOSURE:
			ret = set_BF3403_param_exposure(para);		
			break;							
		case CAM_PARAM_EFFECT:
			ret = set_BF3403_param_effect(para);
			break;		
		case CAM_PARAM_BANDING:
			ret = set_BF3403_param_banding(para);		
			break;		
		case CAM_PARAM_SATURATION:
			ret = set_BF3403_param_saturation(para);				
			break;						
		case CAM_PARAM_NIGHT_MODE:
			ret = set_BF3403_param_nightmode(para);				
			break;						
		case CAM_PARAM_EV_VALUE:
			ret = set_BF3403_param_ev(para);				
			break;				
		default:
			ret = KAL_FALSE;
	}
	return ret;
}

/*************************************************************************
* FUNCTION
*	image_sensor_func_BF3403
*
* DESCRIPTION
*	BF3403 Image Sensor functions struct.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
image_sensor_func_struct image_sensor_func_BF3403=
{
	init_BF3403,
	get_BF3403_id,
	get_BF3403_size,
	get_BF3403_period,
	BF3403_preview,
	BF3403_capture,
	write_BF3403_reg,
	read_BF3403_reg,
	set_BF3403_shutter,
	BF3403_night_mode,
	power_off_BF3403,
	set_BF3403_gain,
	set_BF3403_flashlight,
	BF3403_yuv_sensor_setting
};	/* image_sensor_func_BF3403 */

// write camera_para to sensor register
void camera_para_to_sensor_BF3403(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_BF3403_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_BF3403_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=0; i<CCT_END_ADDR; i++)
	{
		write_BF3403_reg(camera_para.SENSOR.cct[i].addr, camera_para.SENSOR.cct[i].para);
	}
}

// update camera_para from sensor register
void sensor_to_camera_para_BF3403(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_BF3403_reg(camera_para.SENSOR.reg[i].addr);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_BF3403_reg(camera_para.SENSOR.reg[i].addr);
	}
}

//------------------------Engineer mode---------------------------------

void  get_sensor_group_count_BF3403(kal_int32* sensor_count_ptr)
{
   *sensor_count_ptr=GROUP_TOTAL_NUMS;
   
	return;
}

void get_sensor_group_info_BF3403(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
	switch (group_idx)
	{
		case AWB_GAIN:
			sprintf(group_name_ptr, "AWB Gain");
			*item_count_ptr = 2;			
		break;
		case PRE_GAIN:
			sprintf(group_name_ptr, "CCT");
			*item_count_ptr = 3;
		break;
		case SENSOR_DBLC:
			sprintf(group_name_ptr, "DBLC");
			*item_count_ptr = 1;			
		break;
		case GAMMA_ENABLE:
			sprintf(group_name_ptr, "Gamma");
			*item_count_ptr = 1;			
		break;
		case CMMCLK_CURRENT:
			sprintf(group_name_ptr, "CMMCLK Current");
			*item_count_ptr = 1;
		break;		
		case FRAME_RATE_LIMITATION:
			sprintf(group_name_ptr, "Frame Rate Limitation");
			*item_count_ptr = 2;
		break;
		case REGISTER_EDITOR:
			sprintf(group_name_ptr, "Register Editor");
			*item_count_ptr = 2;
		break;		
		default:
		   ASSERT(0);
	}
}

void get_sensor_item_info_BF3403(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr)
{
	kal_uint8 temp_reg;
	
	switch (group_idx)
	{
		case AWB_GAIN:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"AWB R Gain");
				  info_ptr->item_value=read_BF3403_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr);
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0xff;
				break; 
				case 1:
				  sprintf(info_ptr->item_name_ptr,"AWB B Gain");
				  info_ptr->item_value=read_BF3403_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr);
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0xff;
				break;		 
				default:
				   ASSERT(0);
			}
		break;
		case PRE_GAIN:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"Pregain-R");
				  
				  temp_reg = read_BF3403_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
				  temp_reg &= 0x30;
				  temp_reg >>= 4; 
				  
				  if(temp_reg==0)
				      info_ptr->item_value=1000;
				  else if(temp_reg==1)
				      info_ptr->item_value=1250;
				  else if(temp_reg==2)
				      info_ptr->item_value=1500;
				  else if(temp_reg==3)
				      info_ptr->item_value=1750;
				      
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=1000;
				  info_ptr->max=1875;
				break; 
				case 1:
				  sprintf(info_ptr->item_name_ptr,"Pregain-B");
				  
				  temp_reg = read_BF3403_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
				  temp_reg &= 0xC0;
				  temp_reg >>= 6; 
				  
				  if(temp_reg==0)
				      info_ptr->item_value=1000;
				  else if(temp_reg==1)
				      info_ptr->item_value=1250;
				  else if(temp_reg==2)
				      info_ptr->item_value=1500;
				  else if(temp_reg==3)
				      info_ptr->item_value=1750;
				  
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=1000;
				  info_ptr->max=1875;
				break;
				case 2:
				  sprintf(info_ptr->item_name_ptr,"SENSOR_BASEGAIN");
				  
				  temp_reg = read_BF3403_gain();
				  
				  info_ptr->item_value=(temp_reg*1000)/BASEGAIN;
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=1000;
				  info_ptr->max=16000;
				break;
				default:
				   ASSERT(0);		
			}
		break;
		case SENSOR_DBLC:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"DBLC Enable");
				  
				  temp_reg = read_BF3403_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				  if(temp_reg&0x10)
				  {
				      info_ptr->item_value=1;
				  }
				  else
				  {
				      info_ptr->item_value=0;
				  }
				  
				  info_ptr->is_true_false=KAL_TRUE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=1;
				break;  
				default:
				   ASSERT(0);
			}
		break;
		case GAMMA_ENABLE:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"GAMMA_ENABLE");
				  
				  temp_reg = read_BF3403_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
				  if(temp_reg&0xC0)
				  {
				      info_ptr->item_value=1;
				  }
				  else
				  {
				      info_ptr->item_value=0;
				  }
				  
				  info_ptr->is_true_false=KAL_TRUE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=1;
				break;  
				default:
				   ASSERT(0);
			}
		break;
		case CMMCLK_CURRENT:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"Drv Cur[2,4,6,8]mA");
				  
				  temp_reg=camera_para.SENSOR.reg[CMMCLK_CURRENT_INDEX].para;
				  if(temp_reg==ISP_DRIVING_2MA)
				  {
				      info_ptr->item_value=2;
				  }
				  else if(temp_reg==ISP_DRIVING_4MA)
				  {
				      info_ptr->item_value=4;
				  }
				  else if(temp_reg==ISP_DRIVING_6MA)
				  {
				      info_ptr->item_value=6;
				  }
				  else if(temp_reg==ISP_DRIVING_8MA)
				  {
				      info_ptr->item_value=8;
				  }
				  
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_TRUE;
				  info_ptr->min=2;
				  info_ptr->max=8;
				break;
				default:
				   ASSERT(0);
			}
		break;
		case FRAME_RATE_LIMITATION:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"Max Exposure Lines");
				  info_ptr->item_value=MAX_EXPOSURE_LINES;
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_TRUE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0;
				break;
				case 1:
				  sprintf(info_ptr->item_name_ptr,"Min Frame Rate");
				  info_ptr->item_value=MIN_FRAME_RATE;
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_TRUE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0;
				break;
				default:
				   ASSERT(0);
			}
		break;
		case REGISTER_EDITOR:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"REG Addr.");
				  info_ptr->item_value=0;
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0xFF;
				break;
				case 1:
				  sprintf(info_ptr->item_name_ptr,"REG Value");
				  info_ptr->item_value=0;
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0xFF;
				break;
				default:
				   ASSERT(0);		
			}
		break;
		default:
			ASSERT(0); 
	}
}

kal_bool set_sensor_item_info_BF3403(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
{
   kal_uint8 temp_reg;
   kal_uint16 temp_gain;
   
   switch (group_idx)
	{
		case AWB_GAIN:
			switch (item_idx)
			{
				case 0:
				  camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].para = item_value;
				  write_BF3403_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr,item_value);
				break;
				case 1:
				  camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].para = item_value;
				  write_BF3403_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr,item_value);
				break; 
				default:
				   ASSERT(0);
			}			
		break;
		case PRE_GAIN:
			switch (item_idx)
			{
				case 0:
				  temp_reg = read_BF3403_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
				  temp_reg &= ~0x30;
				  
				  if(item_value>=1000 && item_value<=1125)
				      temp_reg |= 0x00;
				  else if(item_value>1125 && item_value<=1375)
				      temp_reg |= 0x10;
				  else if(item_value>1375 && item_value<=1625)
				      temp_reg |= 0x20;
				  else if(item_value>1625 && item_value<=1875)
				      temp_reg |= 0x30;
				  else
				  		return KAL_FALSE;
				  
				  camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].para = temp_reg;
				  write_BF3403_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr,temp_reg);
				break;
				case 1:
				  temp_reg = read_BF3403_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
				  temp_reg &= ~0xC0;
				  
				  if(item_value>=1000 && item_value<=1125)
				      temp_reg |= 0x00;
				  else if(item_value>1125 && item_value<=1375)
				      temp_reg |= 0x40;
				  else if(item_value>1375 && item_value<=1625)
				      temp_reg |= 0x80;
				  else if(item_value>1625 && item_value<=1875)
				      temp_reg |= 0xC0;
				  else
				  		return KAL_FALSE;
				  		
				  camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].para = temp_reg;
				  write_BF3403_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr,temp_reg);
				break;
				case 2:
				  temp_gain = (item_value*BASEGAIN)/1000;
				
				  if(temp_gain>=1*BASEGAIN && temp_gain<2*BASEGAIN)
				  {
				      sensor_global_gain=temp_gain&(~0x3);
				      temp_reg=(sensor_global_gain-1*BASEGAIN)/4;
				  }
				  else if(temp_gain>=2*BASEGAIN && temp_gain<4*BASEGAIN)
				  {
				      sensor_global_gain=2*BASEGAIN;
				      temp_reg=0x10;
				  }
				  else if(temp_gain>=4*BASEGAIN && temp_gain<8*BASEGAIN)
				  {
				      sensor_global_gain=4*BASEGAIN;
				      temp_reg=0x30;
				  }
				  else if(temp_gain>=8*BASEGAIN && temp_gain<16*BASEGAIN)
				  {
				      sensor_global_gain=8*BASEGAIN;
				      temp_reg=0x70;
				  }
				  else if(temp_gain>=16*BASEGAIN)
				  {
				      sensor_global_gain=16*BASEGAIN;
				      temp_reg=0xF0;
				  }
				  else
				      return KAL_FALSE;
				  		
				  		
				  camera_para.SENSOR.cct[GLOBAL_GAIN_INDEX].para = temp_reg;
				  write_BF3403_reg(camera_para.SENSOR.cct[GLOBAL_GAIN_INDEX].addr,temp_reg);
				  break;
				default:
				   ASSERT(0);	
			}
		break;
		case SENSOR_DBLC:
			switch (item_idx)
			{
				case 0:
				  if(item_value==1)
				  {
				      temp_reg = read_BF3403_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg |= 0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_BF3403_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
				  }
				  else
				  {
				      temp_reg = read_BF3403_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg &= ~0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_BF3403_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
				  }
				break;
				default:
				   ASSERT(0);
			}
		break;
		case GAMMA_ENABLE:
			switch (item_idx)
			{
				case 0:
				  temp_reg = read_BF3403_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
				  temp_reg &= ~0xC0;
				  if(item_value==1)
				  {
				      temp_reg |= 0x80; 
				      camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].para = temp_reg;
				  }
				  else
				  {
				      temp_reg &= ~0x80; 
				      camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].para = temp_reg;
				  }
				  write_BF3403_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr,temp_reg);
				break;
				default:
				   ASSERT(0);
			}
		break;
		case CMMCLK_CURRENT:
			switch (item_idx)
			{
				case 0:
				  if(item_value==2)
				  {
				      camera_para.SENSOR.reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
				      set_isp_driving_current(ISP_DRIVING_2MA);
				  }
				  else if(item_value==3 || item_value==4)
				  {
				      camera_para.SENSOR.reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
				      set_isp_driving_current(ISP_DRIVING_4MA);
				  }
				  else if(item_value==5 || item_value==6)
				  {
				      camera_para.SENSOR.reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
				      set_isp_driving_current(ISP_DRIVING_6MA);
				  }
				  else
				  {
				      camera_para.SENSOR.reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
				      set_isp_driving_current(ISP_DRIVING_8MA);
				  }
				break;
				default:
				   ASSERT(0);
			}
		break;
		case FRAME_RATE_LIMITATION:
			switch (item_idx)
			{
				   ASSERT(0);	
			}
		break;
		case REGISTER_EDITOR:
			switch (item_idx)
			{
				case 0:
				  FAC_SENSOR_REG=item_value;
				break;
				case 1:
				  write_BF3403_reg(FAC_SENSOR_REG,item_value);
				break;
				default:
				   ASSERT(0);		
			}
		break;
		default:
		   ASSERT(0);
	}
	
	return KAL_TRUE;
}


kal_bool is_sensor_ready_BF3403()
{
	kal_sleep_task(2);
	sensor_id=(read_cmos_sensor(0xFC)<<8)|read_cmos_sensor(0xFD);

#ifdef NOKE_DEBUG
	noke_dbg_printf("\r CAMERA : is_sensor_ready_BF3403 : sensor_id = 0x%04x \n", sensor_id);
#endif
	
	if( BF3403_SENSOR_ID == sensor_id )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*

    以下是主摄像头的初始化函数， 不同厂家的不一样。

*/

void main_camera_bf3403_init_func_default(void)
{
	// BF3403 Initail Reg.
	write_cmos_sensor(0x11,0x80);
	write_cmos_sensor(0x3a,0x0C);
	write_cmos_sensor(0x3D,0xC0);
	write_cmos_sensor(0x12,0x00);
	write_cmos_sensor(0x15,0x40);

	write_cmos_sensor(0x17,0x13);
	write_cmos_sensor(0x18,0x01);
	write_cmos_sensor(0x32,0xbF);
	write_cmos_sensor(0x19,0x02);
	write_cmos_sensor(0x1a,0x7a);
	write_cmos_sensor(0x03,0x0a);

	write_cmos_sensor(0x0c,0x00);
	write_cmos_sensor(0x3e,0x00);
	write_cmos_sensor(0x70,0x3a);
	write_cmos_sensor(0x71,0x35);
	write_cmos_sensor(0x72,0x11);
	write_cmos_sensor(0x73,0xf0);
	write_cmos_sensor(0xa2,0x02);

	write_cmos_sensor(0x7a,0x20);
	write_cmos_sensor(0x7b,0x03);
	write_cmos_sensor(0x7c,0x0a);
	write_cmos_sensor(0x7d,0x1a);
	write_cmos_sensor(0x7e,0x3f);
	write_cmos_sensor(0x7f,0x4e);
	write_cmos_sensor(0x80,0x5b);
	write_cmos_sensor(0x81,0x68);
	write_cmos_sensor(0x82,0x75);
	write_cmos_sensor(0x83,0x7f);
	write_cmos_sensor(0x84,0x89);
	write_cmos_sensor(0x85,0x9a);
	write_cmos_sensor(0x86,0xa6);
	write_cmos_sensor(0x87,0xbd);
	write_cmos_sensor(0x88,0xd3);
	write_cmos_sensor(0x89,0xe8);

	write_cmos_sensor(0x13,0xe0);
	write_cmos_sensor(0x00,0x00);
	write_cmos_sensor(0x10,0x7f);//(0x10,0x00) modified by wyw 071008
	write_cmos_sensor(0x0d,0x40);
	write_cmos_sensor(0x14,0x28);
	write_cmos_sensor(0xa5,0x02);  
	write_cmos_sensor(0xab,0x02);  
	write_cmos_sensor(0x24,0x68);
	write_cmos_sensor(0x25,0x58);
	write_cmos_sensor(0x26,0xc2); 
	write_cmos_sensor(0x9f,0x78);
	write_cmos_sensor(0xa0,0x68);
	write_cmos_sensor(0xa1,0x03);
	write_cmos_sensor(0xa6,0xD8);
	write_cmos_sensor(0xa7,0xD8);
	write_cmos_sensor(0xa8,0xf0);
	write_cmos_sensor(0xa9,0x90);
	write_cmos_sensor(0xaa,0x14);
	write_cmos_sensor(0x13,0xe5);

	write_cmos_sensor(0x0e,0x61);
	write_cmos_sensor(0x0f,0x4b);
	write_cmos_sensor(0x16,0x02);
	write_cmos_sensor(0x1e,0x07);
	write_cmos_sensor(0x21,0x02);
	write_cmos_sensor(0x22,0x91);
	write_cmos_sensor(0x29,0x07);
	write_cmos_sensor(0x33,0x0b);
	write_cmos_sensor(0x35,0x0b);
	write_cmos_sensor(0x37,0x1d);
	write_cmos_sensor(0x38,0x71);
	write_cmos_sensor(0x39,0x2a);
	write_cmos_sensor(0x3c,0x78);
	write_cmos_sensor(0x4d,0x40);
	write_cmos_sensor(0x4e,0x20);
	write_cmos_sensor(0x69,0x00);
	write_cmos_sensor(0x6b,0x0a);
	write_cmos_sensor(0x74,0x10);	

	write_cmos_sensor(0x8d,0x4f);
	write_cmos_sensor(0x8e,0x00);
	write_cmos_sensor(0x8f,0x00);
	write_cmos_sensor(0x90,0x00);
	write_cmos_sensor(0x91,0x00);
	write_cmos_sensor(0x96,0x00);
	write_cmos_sensor(0x9a,0x80);
	write_cmos_sensor(0xb0,0x84);
	write_cmos_sensor(0xb1,0x0c);
	write_cmos_sensor(0xb2,0x0e);
	write_cmos_sensor(0xb3,0x82);
	write_cmos_sensor(0xb8,0x0a);

	write_cmos_sensor (0x43,0x0a);
	write_cmos_sensor(0x44,0xf2);
	write_cmos_sensor(0x45,0x39);
	write_cmos_sensor(0x46,0x62);
	write_cmos_sensor(0x47,0x3d);
	write_cmos_sensor(0x48,0x55);
	write_cmos_sensor(0x59,0x83);
	write_cmos_sensor(0x5a,0x0d);
	write_cmos_sensor(0x5b,0xcd);
	write_cmos_sensor(0x5c,0x8c);
	write_cmos_sensor(0x5d,0x77);
	write_cmos_sensor(0x5e,0x16);
	write_cmos_sensor(0x6c,0x0a);
	write_cmos_sensor(0x6d,0x65);
	write_cmos_sensor(0x6e,0x11);
	write_cmos_sensor(0x6f,0x9e);

	write_cmos_sensor(0x6a,0x40);
	write_cmos_sensor(0x01,0x5a);//(0x01,0x56);//wyw modify 071008
	write_cmos_sensor(0x02,0x60);//(0x02,0x44);//wyw modify 071008
	write_cmos_sensor(0x13,0xe7);

	/* BF3403 Color Matrix */

	write_cmos_sensor(0x4f,0x88);
	write_cmos_sensor(0x50,0x8B);
	write_cmos_sensor(0x51,0x04);
	write_cmos_sensor(0x52,0x11);
	write_cmos_sensor(0x53,0x8C);
	write_cmos_sensor(0x54,0x9D);
	write_cmos_sensor(0x55,0x00);
	write_cmos_sensor(0x56,0x40);
	write_cmos_sensor(0x57,0x80);
	write_cmos_sensor(0x58,0x9A);

	write_cmos_sensor(0x41,0x08);
	write_cmos_sensor(0x3f,0x00);
	write_cmos_sensor(0x75,0x04);
	write_cmos_sensor(0x76,0x60);
	write_cmos_sensor(0x4c,0x00);
	write_cmos_sensor(0x77,0x01);
	write_cmos_sensor(0x3D,0xC2);
	write_cmos_sensor(0x4b,0x09);
	write_cmos_sensor(0xc9,0x30);
	write_cmos_sensor(0x41,0x38);
	write_cmos_sensor(0x56,0x40);

	write_cmos_sensor(0x34,0x11);
	write_cmos_sensor(0x3b,0x12);
	write_cmos_sensor(0xa4,0x88);
	write_cmos_sensor(0x96,0x00);
	write_cmos_sensor(0x97,0x30);
	write_cmos_sensor(0x98,0x20);
	write_cmos_sensor(0x99,0x30);
	write_cmos_sensor(0x9a,0x84);
	write_cmos_sensor(0x9b,0x29);
	write_cmos_sensor(0x9c,0x03);
	write_cmos_sensor(0x9d,0x99);
	write_cmos_sensor(0x9e,0x7f);
	write_cmos_sensor(0x78,0x04);

	write_cmos_sensor(0x79,0x01);
	write_cmos_sensor(0xc8,0xf0);
	write_cmos_sensor(0x79,0x0f);
	write_cmos_sensor(0xc8,0x00);
	write_cmos_sensor(0x79,0x10);
	write_cmos_sensor(0xc8,0x7e);
	write_cmos_sensor(0x79,0x0a);
	write_cmos_sensor(0xc8,0x80);
	write_cmos_sensor(0x79,0x0b);
	write_cmos_sensor(0xc8,0x01);
	write_cmos_sensor(0x79,0x0c);
	write_cmos_sensor(0xc8,0x0f);
	write_cmos_sensor(0x79,0x0d);
	write_cmos_sensor(0xc8,0x20);
	write_cmos_sensor(0x79,0x09);
	write_cmos_sensor(0xc8,0x80);
	write_cmos_sensor(0x79,0x02);
	write_cmos_sensor(0xc8,0xc0);
	write_cmos_sensor(0x79,0x03);
	write_cmos_sensor(0xc8,0x40);
	write_cmos_sensor(0x79,0x05);
	write_cmos_sensor(0xc8,0x30);
	write_cmos_sensor(0x79,0x26);

	////lj add for BF3403 20071120
	write_cmos_sensor(0xf0,0x01);
	write_cmos_sensor(0x11,0x80);//(0x11,0x81)//分频//(0x11,0x80)//不分频      
	write_cmos_sensor(0x6b,0x00);///////******
	write_cmos_sensor(0x16,0x00);                                                 
	write_cmos_sensor(0x1e,0x37);                                                 
	write_cmos_sensor(0x26,0xc8);                                                
	write_cmos_sensor(0x27,0xc8);                                                 
	write_cmos_sensor(0x1f,0x20);                                                 
	write_cmos_sensor(0x22,0x20);                                                 
	write_cmos_sensor(0x29,0x04);                                                 
	write_cmos_sensor(0x2f,0x01);                                                 
	write_cmos_sensor(0x23,0x09);                                                 
	write_cmos_sensor(0x81,0x01);                                                 
	write_cmos_sensor(0xa4,0x01); // awb speed
	write_cmos_sensor(0xa5,0x2c); // awb threshold
	write_cmos_sensor(0xa8,0x26); // awb threshold
	write_cmos_sensor(0xa1,0x80);
	//write_cmos_sensor(0xa2,0x7d);
	write_cmos_sensor(0x51,0x2f);// Color matrix  0x51-0x5b , 15
	write_cmos_sensor(0x52,0x93);                                                 
	write_cmos_sensor(0x53,0x04);                                                 
	write_cmos_sensor(0x54,0x82);                                                 
	write_cmos_sensor(0x57,0x2f);                                                 
	write_cmos_sensor(0x58,0x8d);                                                 
	write_cmos_sensor(0x59,0x82);                                                 
	write_cmos_sensor(0x5a,0x8d);                                                 
	write_cmos_sensor(0x5b,0x2f);                                                 
	write_cmos_sensor(0xb1,0xb5);                                                 
	write_cmos_sensor(0xb2,0xd0);                                                 
	write_cmos_sensor(0x3f,0x90);    //20080312                                             
	write_cmos_sensor(0x39,0x90);                                                 
	write_cmos_sensor(0x40,0x24);  //Gamma slope    0x40-0x50
	write_cmos_sensor(0x41,0x2F);                                                 
	write_cmos_sensor(0x42,0x3D);                                                 
	write_cmos_sensor(0x43,0x2E);                                                 
	write_cmos_sensor(0x44,0x1d);                                                 
	write_cmos_sensor(0x45,0x19);                                                 
	write_cmos_sensor(0x46,0x12);                                                 
	write_cmos_sensor(0x47,0x0f);                                                 
	write_cmos_sensor(0x48,0x0a);                                                 
	write_cmos_sensor(0x49,0x08);                                                 
	write_cmos_sensor(0x4b,0x09);                                                 
	write_cmos_sensor(0x4c,0x0a);                                                 
	write_cmos_sensor(0x4e,0x05);                                                 
	write_cmos_sensor(0x4f,0x05);                                                 
	write_cmos_sensor(0x50,0x04);                                                                                                  
	write_cmos_sensor(0x92,0x66);//(0x92,0x19)//分频//(0x92,0x66);//不分频//dummy line register,set anti_banding  step
	//add for FR=7.5  
	write_cmos_sensor(0x3b,0x82);
	//write_cmos_sensor(0x8e,0x02);//(0x8e,0x02)//分频//(0x8e,0x04);//不分频
	//write_cmos_sensor(0x8f,0x00);//(0x8f,0x00)//分频//(0x8f,0x00);//不分频   

	//Add for ae speed  
	write_cmos_sensor(0x81,0x01); 
	write_cmos_sensor(0X83,0X0e);
	write_cmos_sensor(0X84,0X15);

	//Add 20080312
	write_cmos_sensor(0x84,0x10); 
	write_cmos_sensor(0X85,0X10);
	write_cmos_sensor(0X86,0X12);
	                
	write_cmos_sensor(0x9d,0x99);//(0x9d,0x4c)//分频//(0x9d,0x99);//不分频
	write_cmos_sensor(0x9e,0x7f);//(0x9e,0x3f)//分频//(0x9e,0x7f);//不分频
	write_cmos_sensor(0x88,0x02);//(0x88,0x01)//分频//(0x88,0x02);//不分频
	write_cmos_sensor(0x89,0xaa);//(0x89,0x55)//分频//(0x89,0xaa);//不分频
	write_cmos_sensor(0x24,0x84);//AE limitation
	write_cmos_sensor(0x25,0x72);//AE target

	write_cmos_sensor(0x09,0x01);

	//add for bad pixel
	write_cmos_sensor(0x61,0x40);
	write_cmos_sensor(0x62,0x40);
	write_cmos_sensor(0x63,0x10);
	write_cmos_sensor(0x64,0x00);
	write_cmos_sensor(0x65,0x6e);
	write_cmos_sensor(0x66,0x0a);
	write_cmos_sensor(0x75,0x13);
	write_cmos_sensor(0x25,0x72);

	// add for red aera
	write_cmos_sensor(0x5c,0x01);

	/*
	write_cmos_sensor(0x74,0x06);
	write_cmos_sensor(0x75,0x15);
	write_cmos_sensor(0x76,0x08);

	//add 12 26 
	write_cmos_sensor(0x28,0x03);
	write_cmos_sensor(0x2c,0x03);
	write_cmos_sensor(0x00,0x10);
	write_cmos_sensor(0x0d,0x20);
	write_cmos_sensor(0x0e,0x10);
	write_cmos_sensor(0x0f,0x20);   
	*/   

	write_cmos_sensor(0xf0,0x00); 
	      
	//camera_para_to_sensor();    // switch to preview mode key setting
}

/*

    以下是副摄像头的初始化函数， 不同厂家的不一样。

*/
#if defined(DOUBLE_CAMERA_SUPPORT)
void sub_camera_bf3403_init_func_default(void)
{
	// BF3403 Initail Reg.
	write_cmos_sensor(0x11,0x80);
	write_cmos_sensor(0x3a,0x0C);
	write_cmos_sensor(0x3D,0xC0);
	write_cmos_sensor(0x12,0x00);
	write_cmos_sensor(0x15,0x40);

	write_cmos_sensor(0x17,0x13);
	write_cmos_sensor(0x18,0x01);
	write_cmos_sensor(0x32,0xbF);
	write_cmos_sensor(0x19,0x02);
	write_cmos_sensor(0x1a,0x7a);
	write_cmos_sensor(0x03,0x0a);

	write_cmos_sensor(0x0c,0x00);
	write_cmos_sensor(0x3e,0x00);
	write_cmos_sensor(0x70,0x3a);
	write_cmos_sensor(0x71,0x35);
	write_cmos_sensor(0x72,0x11);
	write_cmos_sensor(0x73,0xf0);
	write_cmos_sensor(0xa2,0x02);

	write_cmos_sensor(0x7a,0x20);
	write_cmos_sensor(0x7b,0x03);
	write_cmos_sensor(0x7c,0x0a);
	write_cmos_sensor(0x7d,0x1a);
	write_cmos_sensor(0x7e,0x3f);
	write_cmos_sensor(0x7f,0x4e);
	write_cmos_sensor(0x80,0x5b);
	write_cmos_sensor(0x81,0x68);
	write_cmos_sensor(0x82,0x75);
	write_cmos_sensor(0x83,0x7f);
	write_cmos_sensor(0x84,0x89);
	write_cmos_sensor(0x85,0x9a);
	write_cmos_sensor(0x86,0xa6);
	write_cmos_sensor(0x87,0xbd);
	write_cmos_sensor(0x88,0xd3);
	write_cmos_sensor(0x89,0xe8);

	write_cmos_sensor(0x13,0xe0);
	write_cmos_sensor(0x00,0x00);
	write_cmos_sensor(0x10,0x7f);//(0x10,0x00) modified by wyw 071008
	write_cmos_sensor(0x0d,0x40);
	write_cmos_sensor(0x14,0x28);
	write_cmos_sensor(0xa5,0x02);  
	write_cmos_sensor(0xab,0x02);  
	write_cmos_sensor(0x24,0x68);
	write_cmos_sensor(0x25,0x58);
	write_cmos_sensor(0x26,0xc2); 
	write_cmos_sensor(0x9f,0x78);
	write_cmos_sensor(0xa0,0x68);
	write_cmos_sensor(0xa1,0x03);
	write_cmos_sensor(0xa6,0xD8);
	write_cmos_sensor(0xa7,0xD8);
	write_cmos_sensor(0xa8,0xf0);
	write_cmos_sensor(0xa9,0x90);
	write_cmos_sensor(0xaa,0x14);
	write_cmos_sensor(0x13,0xe5);

	write_cmos_sensor(0x0e,0x61);
	write_cmos_sensor(0x0f,0x4b);
	write_cmos_sensor(0x16,0x02);
	write_cmos_sensor(0x1e,0x07);
	write_cmos_sensor(0x21,0x02);
	write_cmos_sensor(0x22,0x91);
	write_cmos_sensor(0x29,0x07);
	write_cmos_sensor(0x33,0x0b);
	write_cmos_sensor(0x35,0x0b);
	write_cmos_sensor(0x37,0x1d);
	write_cmos_sensor(0x38,0x71);
	write_cmos_sensor(0x39,0x2a);
	write_cmos_sensor(0x3c,0x78);
	write_cmos_sensor(0x4d,0x40);
	write_cmos_sensor(0x4e,0x20);
	write_cmos_sensor(0x69,0x00);
	write_cmos_sensor(0x6b,0x0a);
	write_cmos_sensor(0x74,0x10);	

	write_cmos_sensor(0x8d,0x4f);
	write_cmos_sensor(0x8e,0x00);
	write_cmos_sensor(0x8f,0x00);
	write_cmos_sensor(0x90,0x00);
	write_cmos_sensor(0x91,0x00);
	write_cmos_sensor(0x96,0x00);
	write_cmos_sensor(0x9a,0x80);
	write_cmos_sensor(0xb0,0x84);
	write_cmos_sensor(0xb1,0x0c);
	write_cmos_sensor(0xb2,0x0e);
	write_cmos_sensor(0xb3,0x82);
	write_cmos_sensor(0xb8,0x0a);

	write_cmos_sensor (0x43,0x0a);
	write_cmos_sensor(0x44,0xf2);
	write_cmos_sensor(0x45,0x39);
	write_cmos_sensor(0x46,0x62);
	write_cmos_sensor(0x47,0x3d);
	write_cmos_sensor(0x48,0x55);
	write_cmos_sensor(0x59,0x83);
	write_cmos_sensor(0x5a,0x0d);
	write_cmos_sensor(0x5b,0xcd);
	write_cmos_sensor(0x5c,0x8c);
	write_cmos_sensor(0x5d,0x77);
	write_cmos_sensor(0x5e,0x16);
	write_cmos_sensor(0x6c,0x0a);
	write_cmos_sensor(0x6d,0x65);
	write_cmos_sensor(0x6e,0x11);
	write_cmos_sensor(0x6f,0x9e);

	write_cmos_sensor(0x6a,0x40);
	write_cmos_sensor(0x01,0x5a);//(0x01,0x56);//wyw modify 071008
	write_cmos_sensor(0x02,0x60);//(0x02,0x44);//wyw modify 071008
	write_cmos_sensor(0x13,0xe7);

	/* BF3403 Color Matrix */

	write_cmos_sensor(0x4f,0x88);
	write_cmos_sensor(0x50,0x8B);
	write_cmos_sensor(0x51,0x04);
	write_cmos_sensor(0x52,0x11);
	write_cmos_sensor(0x53,0x8C);
	write_cmos_sensor(0x54,0x9D);
	write_cmos_sensor(0x55,0x00);
	write_cmos_sensor(0x56,0x40);
	write_cmos_sensor(0x57,0x80);
	write_cmos_sensor(0x58,0x9A);

	write_cmos_sensor(0x41,0x08);
	write_cmos_sensor(0x3f,0x00);
	write_cmos_sensor(0x75,0x04);
	write_cmos_sensor(0x76,0x60);
	write_cmos_sensor(0x4c,0x00);
	write_cmos_sensor(0x77,0x01);
	write_cmos_sensor(0x3D,0xC2);
	write_cmos_sensor(0x4b,0x09);
	write_cmos_sensor(0xc9,0x30);
	write_cmos_sensor(0x41,0x38);
	write_cmos_sensor(0x56,0x40);

	write_cmos_sensor(0x34,0x11);
	write_cmos_sensor(0x3b,0x12);
	write_cmos_sensor(0xa4,0x88);
	write_cmos_sensor(0x96,0x00);
	write_cmos_sensor(0x97,0x30);
	write_cmos_sensor(0x98,0x20);
	write_cmos_sensor(0x99,0x30);
	write_cmos_sensor(0x9a,0x84);
	write_cmos_sensor(0x9b,0x29);
	write_cmos_sensor(0x9c,0x03);
	write_cmos_sensor(0x9d,0x99);
	write_cmos_sensor(0x9e,0x7f);
	write_cmos_sensor(0x78,0x04);

	write_cmos_sensor(0x79,0x01);
	write_cmos_sensor(0xc8,0xf0);
	write_cmos_sensor(0x79,0x0f);
	write_cmos_sensor(0xc8,0x00);
	write_cmos_sensor(0x79,0x10);
	write_cmos_sensor(0xc8,0x7e);
	write_cmos_sensor(0x79,0x0a);
	write_cmos_sensor(0xc8,0x80);
	write_cmos_sensor(0x79,0x0b);
	write_cmos_sensor(0xc8,0x01);
	write_cmos_sensor(0x79,0x0c);
	write_cmos_sensor(0xc8,0x0f);
	write_cmos_sensor(0x79,0x0d);
	write_cmos_sensor(0xc8,0x20);
	write_cmos_sensor(0x79,0x09);
	write_cmos_sensor(0xc8,0x80);
	write_cmos_sensor(0x79,0x02);
	write_cmos_sensor(0xc8,0xc0);
	write_cmos_sensor(0x79,0x03);
	write_cmos_sensor(0xc8,0x40);
	write_cmos_sensor(0x79,0x05);
	write_cmos_sensor(0xc8,0x30);
	write_cmos_sensor(0x79,0x26);

	////lj add for BF3403 20071120
	write_cmos_sensor(0xf0,0x01);
	write_cmos_sensor(0x11,0x80);//(0x11,0x81)//分频//(0x11,0x80)//不分频      
	write_cmos_sensor(0x6b,0x00);///////******
	write_cmos_sensor(0x16,0x00);                                                 
	write_cmos_sensor(0x1e,0x37);                                                 
	write_cmos_sensor(0x26,0xc8);                                                
	write_cmos_sensor(0x27,0xc8);                                                 
	write_cmos_sensor(0x1f,0x20);                                                 
	write_cmos_sensor(0x22,0x20);                                                 
	write_cmos_sensor(0x29,0x04);                                                 
	write_cmos_sensor(0x2f,0x01);                                                 
	write_cmos_sensor(0x23,0x09);                                                 
	write_cmos_sensor(0x81,0x01);                                                 
	write_cmos_sensor(0xa4,0x01); // awb speed
	write_cmos_sensor(0xa5,0x2c); // awb threshold
	write_cmos_sensor(0xa8,0x26); // awb threshold
	write_cmos_sensor(0xa1,0x80);
	//write_cmos_sensor(0xa2,0x7d);
	write_cmos_sensor(0x51,0x2f);// Color matrix  0x51-0x5b , 15
	write_cmos_sensor(0x52,0x93);                                                 
	write_cmos_sensor(0x53,0x04);                                                 
	write_cmos_sensor(0x54,0x82);                                                 
	write_cmos_sensor(0x57,0x2f);                                                 
	write_cmos_sensor(0x58,0x8d);                                                 
	write_cmos_sensor(0x59,0x82);                                                 
	write_cmos_sensor(0x5a,0x8d);                                                 
	write_cmos_sensor(0x5b,0x2f);                                                 
	write_cmos_sensor(0xb1,0xb5);                                                 
	write_cmos_sensor(0xb2,0xd0);                                                 
	write_cmos_sensor(0x3f,0x90);    //20080312                                             
	write_cmos_sensor(0x39,0x90);                                                 
	write_cmos_sensor(0x40,0x24);  //Gamma slope    0x40-0x50
	write_cmos_sensor(0x41,0x2F);                                                 
	write_cmos_sensor(0x42,0x3D);                                                 
	write_cmos_sensor(0x43,0x2E);                                                 
	write_cmos_sensor(0x44,0x1d);                                                 
	write_cmos_sensor(0x45,0x19);                                                 
	write_cmos_sensor(0x46,0x12);                                                 
	write_cmos_sensor(0x47,0x0f);                                                 
	write_cmos_sensor(0x48,0x0a);                                                 
	write_cmos_sensor(0x49,0x08);                                                 
	write_cmos_sensor(0x4b,0x09);                                                 
	write_cmos_sensor(0x4c,0x0a);                                                 
	write_cmos_sensor(0x4e,0x05);                                                 
	write_cmos_sensor(0x4f,0x05);                                                 
	write_cmos_sensor(0x50,0x04);                                                                                                  
	write_cmos_sensor(0x92,0x66);//(0x92,0x19)//分频//(0x92,0x66);//不分频//dummy line register,set anti_banding  step
	//add for FR=7.5  
	write_cmos_sensor(0x3b,0x82);
	//write_cmos_sensor(0x8e,0x02);//(0x8e,0x02)//分频//(0x8e,0x04);//不分频
	//write_cmos_sensor(0x8f,0x00);//(0x8f,0x00)//分频//(0x8f,0x00);//不分频   

	//Add for ae speed  
	write_cmos_sensor(0x81,0x01); 
	write_cmos_sensor(0X83,0X0e);
	write_cmos_sensor(0X84,0X15);

	//Add 20080312
	write_cmos_sensor(0x84,0x10); 
	write_cmos_sensor(0X85,0X10);
	write_cmos_sensor(0X86,0X12);
	                
	write_cmos_sensor(0x9d,0x99);//(0x9d,0x4c)//分频//(0x9d,0x99);//不分频
	write_cmos_sensor(0x9e,0x7f);//(0x9e,0x3f)//分频//(0x9e,0x7f);//不分频
	write_cmos_sensor(0x88,0x02);//(0x88,0x01)//分频//(0x88,0x02);//不分频
	write_cmos_sensor(0x89,0xaa);//(0x89,0x55)//分频//(0x89,0xaa);//不分频
	write_cmos_sensor(0x24,0x84);//AE limitation
	write_cmos_sensor(0x25,0x72);//AE target

	write_cmos_sensor(0x09,0x01);

	//add for bad pixel
	write_cmos_sensor(0x61,0x40);
	write_cmos_sensor(0x62,0x40);
	write_cmos_sensor(0x63,0x10);
	write_cmos_sensor(0x64,0x00);
	write_cmos_sensor(0x65,0x6e);
	write_cmos_sensor(0x66,0x0a);
	write_cmos_sensor(0x75,0x13);
	write_cmos_sensor(0x25,0x72);

	// add for red aera
	write_cmos_sensor(0x5c,0x01);

	/*
	write_cmos_sensor(0x74,0x06);
	write_cmos_sensor(0x75,0x15);
	write_cmos_sensor(0x76,0x08);

	//add 12 26 
	write_cmos_sensor(0x28,0x03);
	write_cmos_sensor(0x2c,0x03);
	write_cmos_sensor(0x00,0x10);
	write_cmos_sensor(0x0d,0x20);
	write_cmos_sensor(0x0e,0x10);
	write_cmos_sensor(0x0f,0x20);   
	*/   

	write_cmos_sensor(0xf0,0x00); 
	      
	//camera_para_to_sensor();    // switch to preview mode key setting
}
#endif










