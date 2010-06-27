/****************************BF3603_BYD_VGA_Sensor***************************
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

#define BF3603_WRITE_ID							0x42
#define BF3603_READ_ID								0x43
#define BF3603_SENSOR_ID							0x3603

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


void write_BF3603_shutter(kal_uint16 shutter)
{
    kal_uint8 temp_reg;

	if(shutter<=VGA_EXPOSURE_LIMITATION)
	{
		extra_exposure_lines=0;
	}
	else
	{
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
}	/* write_BF3603_shutter */

kal_uint16 read_BF3603_shutter(void)
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
}	/* read_BF3603_shutter */


void set_BF3603_dummy(kal_uint16 pixels, kal_uint16 lines)
{
	write_cmos_sensor(0x2A,((pixels&0x700)>>4));
	write_cmos_sensor(0x2B,(pixels&0xFF));
	write_cmos_sensor(0x92,(lines&0xFF));
	write_cmos_sensor(0x93,((lines&0xFF00)>>8));
}	/* set_BF3603_dummy */


/*************************************************************************
* FUNCTION
*	init_BF3603
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
kal_int8 init_BF3603(void)
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
*	power_off_BF3603
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

void power_off_BF3603(void)
{
	cis_module_power_on(KAL_FALSE);      // Power Off CIS Power
	UPLL_Disable(UPLL_OWNER_ISP);
	#ifndef HW_SCCB
	   SET_SCCB_CLK_LOW;
	   SET_SCCB_DATA_LOW;
	#endif
}	/* power_off_BF3603 */

/*************************************************************************
* FUNCTION
*	get_BF3603_id
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
void get_BF3603_id(kal_uint8 *sensor_write_id, kal_uint8 *sensor_read_id)
{
	*sensor_write_id=BF3603_WRITE_ID;
	*sensor_read_id=BF3603_READ_ID;
}	/* get_BF3603_id */

/*************************************************************************
* FUNCTION
*	get_BF3603_size
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
void get_BF3603_size(kal_uint16 *sensor_width, kal_uint16 *sensor_height)
{
	*sensor_width=IMAGE_SENSOR_VGA_WIDTH;			/* pixel numbers actually used in one frame */
	*sensor_height=IMAGE_SENSOR_VGA_HEIGHT;		/* line numbers actually used in one frame */
}	/* get_BF3603_size */

/*************************************************************************
* FUNCTION
*	get_BF3603_period
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
void get_BF3603_period(kal_uint16 *pixel_number, kal_uint16 *line_number)
{
	*pixel_number=VGA_PERIOD_PIXEL_NUMS;		/* pixel numbers in one period of HSYNC */
	*line_number=VGA_PERIOD_LINE_NUMS;			/* line numbers in one period of VSYNC */
}	/* get_BF3603_period */

void BF3603_preview(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	volatile kal_uint32 temp_reg2=read_cmos_sensor(0x1E), temp_reg1=(temp_reg2&0x0F);
	kal_uint16 current_shutter;

	
	sensor_cap_state=KAL_FALSE;

	g_bMJPEG_mode = KAL_FALSE;

	kal_prompt_trace(MOD_MMI,"------->>>> BF3603 Begin");

		write_cmos_sensor(0x11,0x81);	//MCLK = PCLK
		
		if((sensor_config_data->isp_op_mode==ISP_MJPEG_PREVIEW_MODE)||
			(sensor_config_data->isp_op_mode==ISP_MJPEG_ENCODE_MODE))
		{   //MT6225 Vedio mode
	
				MPEG4_encode_mode=KAL_FALSE;
				g_bMJPEG_mode = KAL_TRUE;
	
				/* config TG of ISP to match the setting of image sensor*/
				SET_TG_OUTPUT_CLK_DIVIDER(1);			
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(1);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(1);
				SET_CMOS_DATA_LATCH(1);
				dummy_pixels=0;
			  dummy_lines=100;		
	
	/*
				SET_TG_OUTPUT_CLK_DIVIDER(7);			
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
			//MT6226 Vedio mode 
			kal_prompt_trace(MOD_MMI," BF3603  video");
				MPEG4_encode_mode=KAL_TRUE;
			
				/* config TG of ISP to match the setting of image sensor*/
				SET_TG_OUTPUT_CLK_DIVIDER(1);
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(1);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(1);
				SET_CMOS_DATA_LATCH(1);
	
				dummy_pixels=0;
				dummy_lines=100;
			}
			else
			{
			
			kal_prompt_trace(MOD_MMI," BF3603  preview");
				MPEG4_encode_mode=KAL_FALSE;
				
				/* config TG of ISP to match the setting of image sensor*/
				SET_TG_OUTPUT_CLK_DIVIDER(1);			
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(1);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(1);
				SET_CMOS_DATA_LATCH(1);
			
				dummy_pixels=0;
				dummy_lines=25;//anti_flicker
			}
		}
	
		preview_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
	
		switch (sensor_config_data->image_mirror)
		{
			case IMAGE_NORMAL:
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
				//while(temp_reg2 != (0x00|temp_reg1))
				{
					write_cmos_sensor(0x1E,(0x00|temp_reg1)); 
					temp_reg2=read_cmos_sensor(0x1E);
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
			case IMAGE_HV_MIRROR:
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
				//while(temp_reg2 != (0x30|temp_reg1))
				{
					 write_cmos_sensor(0x1E,(0x30|temp_reg1));
					 kal_prompt_trace(MOD_MMI," BF3603  4 ");
				};
				
			break;
		}
	     
		image_window->grab_start_x=IMAGE_SENSOR_VGA_INSERTED_PIXELS+start_grab_x_offset;
		image_window->grab_start_y=IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines+start_grab_y_offset/*-2*/;
		image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
		image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT+1;
		
		set_BF3603_dummy(dummy_pixels,dummy_lines);
		write_BF3603_shutter(exposure_lines);
		
		kal_sleep_task(30);

		write_cmos_sensor(0x13, 0x07);//when switch campture mode to preview mode ,AE must be enabled.

			
}	/* BF3603_preview */

void BF3603_capture(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
    volatile kal_uint32 shutter=exposure_lines;
    kal_uint8 temp_reg;
    kal_uint32 tmp_shutter;
    
    sensor_cap_state=KAL_TRUE;
	
	//if(MPEG4_encode_mode)
	// ASSERT(0);                           //modified by wyw
	   	
   if(sensor_config_data->enable_shutter_tansfer==KAL_TRUE)
		shutter=sensor_config_data->capture_shutter;
		

    if(!(sensor_config_data->frame_rate==0xF0))	// If not WEBCAM mode.
    {
		kal_prompt_trace(MOD_MMI,"Not WEBCAM MODE");  

	// Turn off night mode
        temp_reg=read_cmos_sensor(0x3B);
        write_cmos_sensor(0x3B,temp_reg&~0x80);

        write_cmos_sensor(0x13,0xE2);  // Turn OffF AGC/AEC
        
        shutter=read_BF3603_shutter();
	
    }
    	
	if ((image_window->image_target_width<=IMAGE_SENSOR_1M_WIDTH)&&
		(image_window->image_target_height<=IMAGE_SENSOR_1M_HEIGHT))
	{	/* Less than VGA Mode */
		if (image_window->digital_zoom_factor>=(ISP_DIGITAL_ZOOM_INTERVAL<<1))
		{
			kal_prompt_trace(MOD_MMI,"BF3603 ZOOM ");

			write_cmos_sensor(0x11,0x83);
			
			SET_TG_PIXEL_CLK_DIVIDER(7);
			SET_CMOS_DATA_LATCH(4);
				dummy_pixels=VGA_PERIOD_PIXEL_NUMS/4;
			dummy_lines=0;
		}
		else
		{
			if(sensor_config_data->frame_rate==0xF0)	//  WEBCAM  Preview mode.
			{
 			    write_cmos_sensor(0x11,0x81);
			    
			    SET_TG_PIXEL_CLK_DIVIDER(1);
				SET_CMOS_DATA_LATCH(1);
				
				start_grab_x_offset=0;
				start_grab_y_offset=0;
				dummy_pixels=0;
				dummy_lines=0;
			}
			else
			{
				kal_prompt_trace(MOD_MMI,"BF3603 Capture");

				write_cmos_sensor(0x11,0x81);
			    
				SET_TG_PIXEL_CLK_DIVIDER(3);
				SET_CMOS_DATA_LATCH(2);

			}
		}
		
		capture_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
		
		shutter=(2*shutter*preview_pclk_division)/capture_pclk_division;
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
		shutter=(shutter*VGA_PERIOD_PIXEL_NUMS)/(VGA_PERIOD_PIXEL_NUMS+dummy_pixels);
		if(shutter<1)
		shutter=1;
	 }
		

		image_window->grab_start_x=IMAGE_SENSOR_VGA_INSERTED_PIXELS;
		image_window->grab_start_y=IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines;
		image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
		image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT - 1; // minus 1 to avoid the last black line
	

	set_BF3603_dummy(dummy_pixels,dummy_lines);
	write_BF3603_shutter(shutter);
	

}	/* BF3603_capture() */

/*************************************************************************
* FUNCTION
*	write_BF3603_reg
*
* DESCRIPTION
*	This function set the register of BF3603.
*
* PARAMETERS
*	addr : the register index of BF3603
*  para : setting parameter of the specified register of BF3603
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void write_BF3603_reg(kal_uint32 addr, kal_uint32 para)
{
	write_cmos_sensor(addr,para);
}	/* write_BF3603_reg() */

/*************************************************************************
* FUNCTION
*	read_cmos_sensor
*
* DESCRIPTION
*	This function read parameter of specified register from BF3603.
*
* PARAMETERS
*	addr : the register index of BF3603
*
* RETURNS
*	the data that read from BF3603
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 read_BF3603_reg(kal_uint32 addr)
{
	return (read_cmos_sensor(addr));
}	/* read_BF3603_reg() */

/*************************************************************************
* FUNCTION
*	set_BF3603_shutter
*
* DESCRIPTION
*	This function set e-shutter of BF3603 to change exposure time.
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
void set_BF3603_shutter(kal_uint16 shutter)
{
	exposure_lines=shutter;
	write_BF3603_shutter(shutter);
}	/* set_BF3603_shutter */

/*************************************************************************
* FUNCTION
*	set_BF3603_gain
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
kal_uint16 set_BF3603_gain(kal_uint16 gain)
{
   return gain;
}

/*************************************************************************
* FUNCTION
*	BF3603_night_mode
*
* DESCRIPTION
*	This function night mode of BF3603.
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
void BF3603_night_mode(kal_bool enable)
{
    kal_uint8 night  = read_cmos_sensor(0x3B);
    kal_uint8 night2 = read_cmos_sensor(0x13);//read AEC/AWB/AGC 

    if (!sensor_cap_state)
		{
		if (enable)
			{
			if (g_bMJPEG_mode == KAL_TRUE)
				{
					// this mode is used by MT6225 Vedio Night mode
					write_cmos_sensor(0x3B, night & 0x1f);	
				}
			else
				{  
			                // this mode is used by camera or MPEG4 (MT6226 Vedio)Apps
			                
			                write_cmos_sensor(0xf0, 0x01);        
			                write_cmos_sensor(0X13, 0X00);    
			                write_cmos_sensor(0X3b, 0X00);   
			                write_cmos_sensor(0X04, 0X03);   
			                write_cmos_sensor(0X10, 0X7f);   
			                write_cmos_sensor(0X07, 0X00);    
			                write_cmos_sensor(0X2e, 0X05);  //(0X2e, 0X05) //分频//(0X2e, 0X0a); //不分频 //lj add 071123
			                write_cmos_sensor(0X2d, 0X88);  //(0X2d, 0X88) //分频//(0X2d, 0Xff); //不分频 //lj add 071123
			                write_cmos_sensor(0X13, night2);  
					  write_cmos_sensor(0x8e, 0x07);   //Min fps =4
			                write_cmos_sensor(0x8f, 0xd0); 
					  write_cmos_sensor(0x3b, 0xe2); 		
			                write_cmos_sensor(0xf0, 0x00);           
			                                                                                
			                
			        }
        		}

	else
		{
		if(g_bMJPEG_mode == KAL_TRUE)
			{
		                // this mode is used by MT6225 Vedio Normal mode
		                write_cmos_sensor(0x3B, night & 0x1F);          

			}
			else 
				{
			               // this mode is used by camera or MPEG4 Apps 
			                write_cmos_sensor(0xf0, 0x01);   
			               write_cmos_sensor(0x3B, 0xe2);      
			                write_cmos_sensor(0x8e, 0x04);    //xzs  add 081101  MinFPS=6
			                write_cmos_sensor(0x8f, 0xFb);    
			                write_cmos_sensor(0xf0, 0x00); 
			    	         
            			}
       		 }
    		}
}	/* BF3603_night_mode */

/*************************************************************************
* FUNCTION
*	set_BF3603_flashlight
*
* DESCRIPTION
*	turn on/off BF3603 flashlight .
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
void set_BF3603_flashlight(kal_bool enable)
{
	// Todo
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_zoom
*
* DESCRIPTION
*	BF3603 zoom setting.
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
kal_uint32 set_BF3603_param_zoom(kal_uint32 para)
{
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_contrast
*
* DESCRIPTION
*	BF3603 contrast setting.
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
kal_uint32 set_BF3603_param_contrast(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_brightness
*
* DESCRIPTION
*	BF3603 brightness setting.
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
kal_uint32 set_BF3603_param_brightness(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_hue
*
* DESCRIPTION
*	BF3603 hue setting.
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
kal_uint32 set_BF3603_param_hue(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_gamma
*
* DESCRIPTION
*	BF3603 gamma setting.
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
kal_uint32 set_BF3603_param_gamma(kal_uint32 para)
{
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_wb
*
* DESCRIPTION
*	BF3603 wb setting.
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
kal_uint32 set_BF3603_param_wb(kal_uint32 para)
{
	kal_uint16 rgain=0x80, ggain=0x80, bgain=0x80;
	kal_uint8  temp_reg;
	
	temp_reg=read_cmos_sensor(0x13);
	
	switch (para)
	{
		case CAM_WB_AUTO:
			write_cmos_sensor(0x01,0x50);
			write_cmos_sensor(0x02,0x7e);
			write_cmos_sensor(0x13,temp_reg|0x2);   // Enable AWB		
			break;

		case CAM_WB_CLOUD:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x44);
			write_cmos_sensor(0x02,0x7E);
			break;		

		case CAM_WB_DAYLIGHT:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x56);
			write_cmos_sensor(0x02,0x78);
			break;		

		case CAM_WB_INCANDESCENCE:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x7A);
			write_cmos_sensor(0x02,0x3E);
			break;		

		case CAM_WB_FLUORESCENT:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x4E);
			write_cmos_sensor(0x02,0x70);
			break;		

		case CAM_WB_TUNGSTEN:
			write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
			write_cmos_sensor(0x01,0x74);
			write_cmos_sensor(0x02,0x44);
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
*	set_BF3603_param_exposure
*
* DESCRIPTION
*	BF3603 exposure setting.
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
kal_uint32 set_BF3603_param_exposure(kal_uint32 para)
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
            write_cmos_sensor(0x55, 0xB8);
			break;				
		case CAM_EV_NEG_1_3:
            write_cmos_sensor(0x55, 0x98);
			break;				
		case CAM_EV_ZERO:
            write_cmos_sensor(0x55, 0x00);
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
*	set_BF3603_param_effect
*
* DESCRIPTION
*	BF3603 effect setting.
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
kal_uint32 set_BF3603_param_effect(kal_uint32 para)
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
			write_cmos_sensor(0x67,0x66);		
			write_cmos_sensor(0x68,0x98);
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
			write_cmos_sensor(0x67,0x70);		
			write_cmos_sensor(0x68,0x70);
			write_cmos_sensor(0x56,0x40);		
			break;					
		case CAM_EFFECT_ENC_SEPIABLUE:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0xA0);		
			write_cmos_sensor(0x68,0x60);
			write_cmos_sensor(0x56,0x40);		
			break;								
		case CAM_EFFECT_ENC_GRAYINV:
			write_cmos_sensor(0x3A,0x3c);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0x80);
			write_cmos_sensor(0x56,0x40);						
			break;								
		case CAM_EFFECT_ENC_COPPERCARVING:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0x80);		
			write_cmos_sensor(0x68,0xf0);
			write_cmos_sensor(0x56,0x40);		    	
			break;								
    	case CAM_EFFECT_ENC_BLUECARVING:
			write_cmos_sensor(0x3A,0x1C);		
			write_cmos_sensor(0x67,0x80);		
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
*	set_BF3603_param_banding
*
* DESCRIPTION
*	BF3603 banding setting.
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
kal_uint32 set_BF3603_param_banding(kal_uint32 para)
{
	kal_uint8 banding;
	
	banding=read_cmos_sensor(0x3b);

	kal_prompt_trace(MOD_MMI,"------>>Banding");

	switch (para)
	{
		case CAM_BANDING_50HZ:
			write_cmos_sensor(0x3b,banding|0x08);	    /* 50 Hz */	
			write_cmos_sensor(0xf0,0x01);	 
			write_cmos_sensor(0x80,0x01);	 
			write_cmos_sensor(0x9d,0x4c); 
			write_cmos_sensor(0xf0,0x00);  
			break;                        
		case CAM_BANDING_60HZ:
			write_cmos_sensor(0x3b,banding&0xF7);	    /* 60 Hz */
			write_cmos_sensor(0xf0,0x01);	 
			write_cmos_sensor(0x80,0x00);	 	
			write_cmos_sensor(0x9e,0x3f);	
			write_cmos_sensor(0xf0,0x00);	 
			break;
		default:
			return KAL_FALSE;		
	}	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_saturation
*
* DESCRIPTION
*	BF3603 SATURATION setting.
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
kal_uint32 set_BF3603_param_saturation(kal_uint32 para)
{
    // Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_nightmode
*
* DESCRIPTION
*	BF3603 night mode setting.
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
kal_uint32 set_BF3603_param_nightmode(kal_uint32 para)
{
	BF3603_night_mode((kal_bool)para);
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_BF3603_param_ev
*
* DESCRIPTION
*	BF3603 ev setting.
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
kal_uint32 set_BF3603_param_ev(kal_uint32 para)
{
	return set_BF3603_param_exposure(para);
}

/*************************************************************************
* FUNCTION
*	BF3603_yuv_sensor_setting
*
* DESCRIPTION
*	This function send command and parameter to yuv sensor module BF3603
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
kal_uint32 BF3603_yuv_sensor_setting(kal_uint32 cmd, kal_uint32 para)
{
	kal_uint32 ret = KAL_TRUE;
	switch (cmd)
	{
		case CAM_PARAM_ZOOM_FACTOR:
			ret = set_BF3603_param_zoom(para);		
			break;			
		case CAM_PARAM_CONTRAST:
			ret = set_BF3603_param_contrast(para);		
			break;					
		case CAM_PARAM_BRIGHTNESS:
			ret = set_BF3603_param_brightness(para);		
			break;							
		case CAM_PARAM_HUE:
			ret = set_BF3603_param_hue(para);		
			break;							
		case CAM_PARAM_GAMMA:
			ret = set_BF3603_param_gamma(para);		
			break;							
		case CAM_PARAM_WB:
			ret = set_BF3603_param_wb(para);		
			break;
		case CAM_PARAM_EXPOSURE:
			ret = set_BF3603_param_exposure(para);		
			break;							
		case CAM_PARAM_EFFECT:
			ret = set_BF3603_param_effect(para);
			break;		
		case CAM_PARAM_BANDING:
			ret = set_BF3603_param_banding(para);		
			break;		
		case CAM_PARAM_SATURATION:
			ret = set_BF3603_param_saturation(para);				
			break;						
		case CAM_PARAM_NIGHT_MODE:
			ret = set_BF3603_param_nightmode(para);				
			break;						
		case CAM_PARAM_EV_VALUE:
			ret = set_BF3603_param_ev(para);				
			break;				
		default:
			ret = KAL_FALSE;
	}
	return ret;
}

/*************************************************************************
* FUNCTION
*	image_sensor_func_BF3603
*
* DESCRIPTION
*	BF3603 Image Sensor functions struct.
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
image_sensor_func_struct image_sensor_func_BF3603=
{
	init_BF3603,
	get_BF3603_id,
	get_BF3603_size,
	get_BF3603_period,
	BF3603_preview,
	BF3603_capture,
	write_BF3603_reg,
	read_BF3603_reg,
	set_BF3603_shutter,
	BF3603_night_mode,
	power_off_BF3603,
	set_BF3603_gain,
	set_BF3603_flashlight,
	BF3603_yuv_sensor_setting
};	/* image_sensor_func_BF3603 */

/*************************************************************************
* FUNCTION
*	cam_module_func_config
*
* DESCRIPTION
*	This function maps the external camera module function API structure.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void image_sensor_func_config_BF3603(void)
{
	image_sensor_func=&image_sensor_func_BF3603;
}	/* cam_module_func_config() */
// write camera_para to sensor register
void camera_para_to_sensor_BF3603(void)
{
}

// update camera_para from sensor register
void sensor_to_camera_para_BF3603(void)
{
}
//------------------------Engineer mode---------------------------------

void  get_sensor_group_count_BF3603(kal_int32* sensor_count_ptr)
{
}

void get_sensor_group_info_BF3603(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
}

void get_sensor_item_info_BF3603(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr)
{
}

kal_bool set_sensor_item_info_BF3603(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
{

	return KAL_TRUE;
}

kal_bool is_sensor_ready_BF3603()
{
	kal_sleep_task(2);
	sensor_id=(read_cmos_sensor(0xFC)<<8)|read_cmos_sensor(0xFD);

#ifdef NOKE_DEBUG
	noke_dbg_printf("\r CAMERA : is_sensor_ready_BF3603 : sensor_id = 0x%04x \n", sensor_id);
#endif
	
	if( BF3603_SENSOR_ID == sensor_id )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*

    以下是主摄像头的初始化函数， 不同厂家的不一样。

*/

void main_camera_bf3603_init_func_default(void)
{
     write_cmos_sensor(0x12,0x80);
     write_cmos_sensor(0xff,0xff);
     write_cmos_sensor(0x09,0x01);
     write_cmos_sensor(0x11,0x80);
     write_cmos_sensor(0x13,0x00);
     write_cmos_sensor(0x01,0x15);
     write_cmos_sensor(0x02,0x22);
     write_cmos_sensor(0x87,0x18);
     write_cmos_sensor(0x8c,0x01);//01 分频  02 不分频  
     write_cmos_sensor(0x8d,0x7c);//7C 分频  64 不分频
     write_cmos_sensor(0x13,0x07);
	   // DBLK manual  
     write_cmos_sensor(0x28,0x03);
     write_cmos_sensor(0x2c,0x03);  
     write_cmos_sensor(0x00,0x20);
     write_cmos_sensor(0x0d,0x20);
     write_cmos_sensor(0x0e,0x20);
     write_cmos_sensor(0x0f,0x20);
     write_cmos_sensor(0x05,0x16);  
     write_cmos_sensor(0x14,0x16);
     write_cmos_sensor(0x06,0x19);  
     write_cmos_sensor(0x08,0x19);
     write_cmos_sensor(0x26,0x08);  
     write_cmos_sensor(0x27,0x08);
     write_cmos_sensor(0X1F,0xa0);
     write_cmos_sensor(0X22,0xa0);
	   //DBLK auto  
     write_cmos_sensor(0x28,0x00);
     write_cmos_sensor(0x2c,0x00);
     write_cmos_sensor(0x1e,0x30);  
     write_cmos_sensor(0x15,0x40);
     write_cmos_sensor(0x3A,0x03);
		 write_cmos_sensor(0x2f,0x00);
		 write_cmos_sensor(0x16,0x00);
		 write_cmos_sensor(0x29,0x04);
		 write_cmos_sensor(0x21,0x00);
		 write_cmos_sensor(0x04,0xbb);
		 write_cmos_sensor(0x56,0x40);
     //lens shading
		 write_cmos_sensor(0x35,0x60);
		 write_cmos_sensor(0x65,0x58);
     write_cmos_sensor(0x66,0x58);
     //global gain
		 write_cmos_sensor(0x82,0x16);
		 write_cmos_sensor(0x83,0x25);
		 write_cmos_sensor(0x84,0x1a);
		 write_cmos_sensor(0x85,0x26);
		 write_cmos_sensor(0x86,0x30);

		 write_cmos_sensor(0x96,0x26);// AE speed
		 write_cmos_sensor(0x97,0x0c);
		 write_cmos_sensor(0x2b,0x06);//06 分频  00 不分频
     write_cmos_sensor(0x70,0x2f);
     write_cmos_sensor(0x72,0x4f);
     write_cmos_sensor(0x73,0x2f);
     write_cmos_sensor(0x74,0x27);
     write_cmos_sensor(0x75,0x0e);
     write_cmos_sensor(0x69,0x00);
     write_cmos_sensor(0x76,0xff);
		 write_cmos_sensor(0x80,0x55);
		 write_cmos_sensor(0x89,0x02);//02 分频  05 不分频
		 write_cmos_sensor(0x8a,0xf8);//f8 分频  fc 不分频
     //black level
     write_cmos_sensor(0x90,0x20);
     write_cmos_sensor(0x91,0x1c);
     write_cmos_sensor(0x39,0x80);  
     write_cmos_sensor(0x3f,0x90);
     write_cmos_sensor(0x3b,0x60);
     write_cmos_sensor(0x3c,0x10);
     //gamma
		 write_cmos_sensor(0X40,0X20);
		 write_cmos_sensor(0X41,0X30);
		 write_cmos_sensor(0X42,0X28);
		 write_cmos_sensor(0X43,0X28);
		 write_cmos_sensor(0X44,0X1d);
		 write_cmos_sensor(0X45,0X15);
		 write_cmos_sensor(0X46,0X13);
		 write_cmos_sensor(0X47,0X10);
		 write_cmos_sensor(0X48,0X0E);
		 write_cmos_sensor(0X49,0X0B);
		 write_cmos_sensor(0X4b,0X0B);
		 write_cmos_sensor(0X4c,0X09);
		 write_cmos_sensor(0X4e,0X07);
		 write_cmos_sensor(0X4f,0X06);
		 write_cmos_sensor(0X50,0X05);
     //color matrix
		 write_cmos_sensor(0x51,0x30);
		 write_cmos_sensor(0x52,0x92);
		 write_cmos_sensor(0x53,0x02);
		 write_cmos_sensor(0x54,0x86);
		 write_cmos_sensor(0x57,0x30);
		 write_cmos_sensor(0x58,0x8a);
		 write_cmos_sensor(0x59,0x80);
		 write_cmos_sensor(0x5a,0x92);
		 write_cmos_sensor(0x5b,0x32);
	 
		 write_cmos_sensor(0x5c,0x2e);
		 write_cmos_sensor(0x5d,0x17);
		 // new  AWB
		 write_cmos_sensor(0x6a,0x01);
		 write_cmos_sensor(0x23,0x66);
		 write_cmos_sensor(0xa0,0x9f);
		 write_cmos_sensor(0xa1,0x51);
		 write_cmos_sensor(0xa2,0x10);
		 write_cmos_sensor(0xa3,0x26);
		 write_cmos_sensor(0xa4,0x0b);
		 write_cmos_sensor(0xa5,0x26);
		 write_cmos_sensor(0xa6,0x02);
		 write_cmos_sensor(0xa7,0x98);
		 write_cmos_sensor(0xa8,0x80);
		 write_cmos_sensor(0xa9,0x42);
		 write_cmos_sensor(0xaa,0x4b);
		 write_cmos_sensor(0xab,0x3e);
		 write_cmos_sensor(0xac,0x42);
		 write_cmos_sensor(0xad,0x43);
		 write_cmos_sensor(0xae,0x48);
		 write_cmos_sensor(0xaf,0x2b);
		 write_cmos_sensor(0xc5,0x32);
		 write_cmos_sensor(0xc6,0x34);
		 write_cmos_sensor(0xc7,0x39);
		 write_cmos_sensor(0xc8,0x2f);
		 write_cmos_sensor(0xc9,0x36);
		 write_cmos_sensor(0xca,0x3f);
		 write_cmos_sensor(0xcb,0x41);
		 write_cmos_sensor(0xcc,0x42);
		 write_cmos_sensor(0xcd,0x48);
		 write_cmos_sensor(0xce,0x44);
		 write_cmos_sensor(0xcf,0x4C);
		 write_cmos_sensor(0xd0,0x4B);
		 write_cmos_sensor(0xd1,0x55);
		 // color saturation
		 write_cmos_sensor(0xb0,0xe4);
		 write_cmos_sensor(0xb1,0xc0);
		 write_cmos_sensor(0xb2,0xb0);
		 write_cmos_sensor(0xb3,0x86);
		 //AE target
		 write_cmos_sensor(0x24,0x8a);
		 write_cmos_sensor(0x25,0x7a);
		 //anti webcamera banding
		 write_cmos_sensor(0x9d,0x4c);
}

/*

    以下是副摄像头的初始化函数， 不同厂家的不一样。

*/
#if defined(DOUBLE_CAMERA_SUPPORT)
void sub_camera_bf3603_init_func_default(void)
{
     write_cmos_sensor(0x12,0x80);
     write_cmos_sensor(0xff,0xff);
     write_cmos_sensor(0x09,0x01);
     write_cmos_sensor(0x11,0x80);
     write_cmos_sensor(0x13,0x00);
     write_cmos_sensor(0x01,0x15);
     write_cmos_sensor(0x02,0x22);
     write_cmos_sensor(0x87,0x18);
     write_cmos_sensor(0x8c,0x01);//01 分频  02 不分频  
     write_cmos_sensor(0x8d,0x7c);//7C 分频  64 不分频
     write_cmos_sensor(0x13,0x07);
	   // DBLK manual  
     write_cmos_sensor(0x28,0x03);
     write_cmos_sensor(0x2c,0x03);  
     write_cmos_sensor(0x00,0x20);
     write_cmos_sensor(0x0d,0x20);
     write_cmos_sensor(0x0e,0x20);
     write_cmos_sensor(0x0f,0x20);
     write_cmos_sensor(0x05,0x16);  
     write_cmos_sensor(0x14,0x16);
     write_cmos_sensor(0x06,0x19);  
     write_cmos_sensor(0x08,0x19);
     write_cmos_sensor(0x26,0x08);  
     write_cmos_sensor(0x27,0x08);
     write_cmos_sensor(0X1F,0xa0);
     write_cmos_sensor(0X22,0xa0);
	   //DBLK auto  
     write_cmos_sensor(0x28,0x00);
     write_cmos_sensor(0x2c,0x00);
     write_cmos_sensor(0x1e,0x30);  
     write_cmos_sensor(0x15,0x40);
     write_cmos_sensor(0x3A,0x03);
		 write_cmos_sensor(0x2f,0x00);
		 write_cmos_sensor(0x16,0x00);
		 write_cmos_sensor(0x29,0x04);
		 write_cmos_sensor(0x21,0x00);
		 write_cmos_sensor(0x04,0xbb);
		 write_cmos_sensor(0x56,0x40);
     //lens shading
		 write_cmos_sensor(0x35,0x60);
		 write_cmos_sensor(0x65,0x58);
     write_cmos_sensor(0x66,0x58);
     //global gain
		 write_cmos_sensor(0x82,0x16);
		 write_cmos_sensor(0x83,0x25);
		 write_cmos_sensor(0x84,0x1a);
		 write_cmos_sensor(0x85,0x26);
		 write_cmos_sensor(0x86,0x30);

		 write_cmos_sensor(0x96,0x26);// AE speed
		 write_cmos_sensor(0x97,0x0c);
		 write_cmos_sensor(0x2b,0x06);//06 分频  00 不分频
     write_cmos_sensor(0x70,0x2f);
     write_cmos_sensor(0x72,0x4f);
     write_cmos_sensor(0x73,0x2f);
     write_cmos_sensor(0x74,0x27);
     write_cmos_sensor(0x75,0x0e);
     write_cmos_sensor(0x69,0x00);
     write_cmos_sensor(0x76,0xff);
		 write_cmos_sensor(0x80,0x55);
		 write_cmos_sensor(0x89,0x02);//02 分频  05 不分频
		 write_cmos_sensor(0x8a,0xf8);//f8 分频  fc 不分频
     //black level
     write_cmos_sensor(0x90,0x20);
     write_cmos_sensor(0x91,0x1c);
     write_cmos_sensor(0x39,0x80);  
     write_cmos_sensor(0x3f,0x90);
     write_cmos_sensor(0x3b,0x60);
     write_cmos_sensor(0x3c,0x10);
     //gamma
		 write_cmos_sensor(0X40,0X20);
		 write_cmos_sensor(0X41,0X30);
		 write_cmos_sensor(0X42,0X28);
		 write_cmos_sensor(0X43,0X28);
		 write_cmos_sensor(0X44,0X1d);
		 write_cmos_sensor(0X45,0X15);
		 write_cmos_sensor(0X46,0X13);
		 write_cmos_sensor(0X47,0X10);
		 write_cmos_sensor(0X48,0X0E);
		 write_cmos_sensor(0X49,0X0B);
		 write_cmos_sensor(0X4b,0X0B);
		 write_cmos_sensor(0X4c,0X09);
		 write_cmos_sensor(0X4e,0X07);
		 write_cmos_sensor(0X4f,0X06);
		 write_cmos_sensor(0X50,0X05);
     //color matrix
		 write_cmos_sensor(0x51,0x30);
		 write_cmos_sensor(0x52,0x92);
		 write_cmos_sensor(0x53,0x02);
		 write_cmos_sensor(0x54,0x86);
		 write_cmos_sensor(0x57,0x30);
		 write_cmos_sensor(0x58,0x8a);
		 write_cmos_sensor(0x59,0x80);
		 write_cmos_sensor(0x5a,0x92);
		 write_cmos_sensor(0x5b,0x32);
	 
		 write_cmos_sensor(0x5c,0x2e);
		 write_cmos_sensor(0x5d,0x17);
		 // new  AWB
		 write_cmos_sensor(0x6a,0x01);
		 write_cmos_sensor(0x23,0x66);
		 write_cmos_sensor(0xa0,0x9f);
		 write_cmos_sensor(0xa1,0x51);
		 write_cmos_sensor(0xa2,0x10);
		 write_cmos_sensor(0xa3,0x26);
		 write_cmos_sensor(0xa4,0x0b);
		 write_cmos_sensor(0xa5,0x26);
		 write_cmos_sensor(0xa6,0x02);
		 write_cmos_sensor(0xa7,0x98);
		 write_cmos_sensor(0xa8,0x80);
		 write_cmos_sensor(0xa9,0x42);
		 write_cmos_sensor(0xaa,0x4b);
		 write_cmos_sensor(0xab,0x3e);
		 write_cmos_sensor(0xac,0x42);
		 write_cmos_sensor(0xad,0x43);
		 write_cmos_sensor(0xae,0x48);
		 write_cmos_sensor(0xaf,0x2b);
		 write_cmos_sensor(0xc5,0x32);
		 write_cmos_sensor(0xc6,0x34);
		 write_cmos_sensor(0xc7,0x39);
		 write_cmos_sensor(0xc8,0x2f);
		 write_cmos_sensor(0xc9,0x36);
		 write_cmos_sensor(0xca,0x3f);
		 write_cmos_sensor(0xcb,0x41);
		 write_cmos_sensor(0xcc,0x42);
		 write_cmos_sensor(0xcd,0x48);
		 write_cmos_sensor(0xce,0x44);
		 write_cmos_sensor(0xcf,0x4C);
		 write_cmos_sensor(0xd0,0x4B);
		 write_cmos_sensor(0xd1,0x55);
		 // color saturation
		 write_cmos_sensor(0xb0,0xe4);
		 write_cmos_sensor(0xb1,0xc0);
		 write_cmos_sensor(0xb2,0xb0);
		 write_cmos_sensor(0xb3,0x86);
		 //AE target
		 write_cmos_sensor(0x24,0x8a);
		 write_cmos_sensor(0x25,0x7a);
		 //anti webcamera banding
		 write_cmos_sensor(0x9d,0x4c); 
}
#endif


