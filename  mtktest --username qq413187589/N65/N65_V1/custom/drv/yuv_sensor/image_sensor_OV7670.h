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


#define OV7670_SENSOR_ID							0x7673
#define OV7670_WRITE_ID							0x42
#define OV7670_READ_ID								0x43

extern kal_uint8  start_grab_x_offset, start_grab_y_offset;
extern kal_bool   gVGAmode, sensor_night_mode, MPEG4_encode_mode, g_bMJPEG_mode ;
extern kal_uint8  normal_gain, night_gain;
extern kal_uint8  preview_pclk_division, capture_pclk_division;
extern kal_uint16 dummy_pixels, dummy_lines, extra_exposure_lines;
extern kal_uint16 exposure_lines;
extern kal_uint16 sensor_global_gain, sensor_gain_base;
/* Debug Message, Don't Care */
extern kal_uint16 sensor_frame_rate;

/* MAX/MIN Explosure Lines Used By AE Algorithm */
extern kal_uint16 MAX_EXPOSURE_LINES ;
extern kal_uint8  MIN_EXPOSURE_LINES ;
/* Parameter For Engineer mode function */
extern kal_uint32 FAC_SENSOR_REG;
/* Image Sensor ID */
extern kal_uint16 sensor_id;
extern kal_bool sensor_cap_state;
extern  kal_uint8 hejctest ;


extern kal_bool  mmi_main_camera_active;   


void write_OV7670_shutter(kal_uint16 shutter)
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
	write_cmos_sensor(0x04,( (temp_reg&0xFC) | (shutter&0x3) ));			// AEC[b1~b0]
	write_cmos_sensor(0x10,((shutter&0x3FC)>>2));								// AEC[b9~b2]
	write_cmos_sensor(0x07,((shutter&0x7C00)>>10));								// AEC[b10]/AEC[b15~b10]
}	/* write_OV7670_shutter */

kal_uint16 read_OV7670_shutter(void)
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
}	/* read_OV7670_shutter */

void write_OV7670_gain(kal_uint16 gain)
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
}  /* write_OV7670_gain */

kal_uint16 read_OV7670_gain(void)
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
}  /* read_OV7670_gain */

void set_OV7670_dummy(kal_uint16 pixels, kal_uint16 lines)
{
	write_cmos_sensor(0x2A,((pixels&0x700)>>4));
	write_cmos_sensor(0x2B,(pixels&0xFF));
	write_cmos_sensor(0x92,(lines&0xFF));
	write_cmos_sensor(0x93,((lines&0xFF00)>>8));
}	/* set_OV7670_dummy */

/*************************************************************************
* FUNCTION
*	config_OV7670_window
*
* DESCRIPTION
*	This function config the hardware window of OV76X0 for getting specified
*  data of that window.
*
* PARAMETERS
*	start_x : start column of the interested window
*  start_y : start row of the interested window
*  width  : column widht of the itnerested window
*  height : row depth of the itnerested window
*
* RETURNS
*	the data that read from OV76X0
*
* GLOBALS AFFECTED
*
*************************************************************************/
void config_OV7670_window(kal_uint16 startx,kal_uint16 starty,kal_uint16 width, kal_uint16 height)
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
	write_cmos_sensor(0x1A,(endy&0x3FC)>>2);		   	// VREF end high 8bits*/
}	/* config_OV7670_window */


/*************************************************************************
* FUNCTION
*	init_OV7670
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
kal_int8 init_OV7670(void)
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

}
/*************************************************************************
* FUNCTION
*	power_off_OV7670
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

void power_off_OV7670(void)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("power_off_OV7670  1004\n\r");
#endif
	cis_module_power_on(KAL_FALSE);      // Power Off CIS Power modified by fred fan 2007-12-19 //ghw111
	UPLL_Disable(UPLL_OWNER_ISP);
	#ifndef HW_SCCB
           #if !defined(BEIW3H_BOARD_DRV)
	   SET_SCCB_CLK_LOW;
	   SET_SCCB_DATA_LOW;
	#endif
	#endif
}	/* power_off_OV7670 */

/*************************************************************************
* FUNCTION
*	get_OV7670_id
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
void get_OV7670_id(kal_uint8 *sensor_write_id, kal_uint8 *sensor_read_id)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("get_OV7670_id  1047\n\r");
#endif
	*sensor_write_id=OV7670_WRITE_ID;
	*sensor_read_id=OV7670_READ_ID;
}	/* get_OV7670_id */

/*************************************************************************
* FUNCTION
*	get_OV7670_size
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
void get_OV7670_size(kal_uint16 *sensor_width, kal_uint16 *sensor_height)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("get_OV7670_size  1071\n\r");
#endif
	*sensor_width=IMAGE_SENSOR_VGA_WIDTH;			/* pixel numbers actually used in one frame */
	*sensor_height=IMAGE_SENSOR_VGA_HEIGHT;		/* line numbers actually used in one frame */
}	/* get_OV7670_size */

/*************************************************************************
* FUNCTION
*	get_OV7670_period
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
void get_OV7670_period(kal_uint16 *pixel_number, kal_uint16 *line_number)
{
	*pixel_number=VGA_PERIOD_PIXEL_NUMS;		// pixel numbers in one period of HSYNC //
	*line_number=VGA_PERIOD_LINE_NUMS;			//line numbers in one period of VSYNC//	
}	/* get_OV7670_period */
//extern BOOL  mmi_main_camera_active;  //ghw111
void OV76X0_preview(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	volatile kal_uint32 temp_reg2, temp_reg1;
	kal_uint16 current_shutter;
 
	sensor_cap_state=KAL_FALSE;
	g_bMJPEG_mode = KAL_FALSE;

	temp_reg2=read_cmos_sensor(0x1E);
	temp_reg1=(temp_reg2&0x0F);
	if (sensor_config_data->isp_op_mode != ISP_MJPEG_ENCODE_MODE) 
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("sensor_config_data->isp_op_mode =%d\n\r  " ,sensor_config_data->isp_op_mode);	
#endif
		write_cmos_sensor(0x11,0x80);	//MCLK = PCLK
	}

	if((sensor_config_data->isp_op_mode==ISP_MJPEG_PREVIEW_MODE)||
		(sensor_config_data->isp_op_mode==ISP_MJPEG_ENCODE_MODE))
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("OV76X0_preview    1082\n\r");
#endif
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
	}
	else
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("OV76X0_preview    1144\n\r");
#endif
#if defined(NOKE_DEBUG)
		noke_dbg_printf("OV76X0_preview   sensor_config_data->frame_rate =%d\n\r  " ,sensor_config_data->frame_rate);
#endif
		if(sensor_config_data->frame_rate==0x0F)		// MPEG4 Encode Mode
		{
		MPEG4_encode_mode=KAL_TRUE;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("OV76X0_preview    1148\n\r");
#endif
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
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV76X0_preview    1162\n\r");
#endif
			MPEG4_encode_mode=KAL_FALSE;
			/*UNI@bw070906 [6225 7670][all customers] preview framerate 为12.5fps */
			write_cmos_sensor(0x11,0x81);	// PCLK=MCLK/2 
			/* config TG of ISP to match the setting of image sensor*/
			SET_TG_OUTPUT_CLK_DIVIDER(1);			//30fps
			SET_CMOS_RISING_EDGE(0);
			SET_CMOS_FALLING_EDGE(1);
			ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
			SET_TG_PIXEL_CLK_DIVIDER(3);
			SET_CMOS_DATA_LATCH(2);
			dummy_pixels=0;
			dummy_lines=102;
		}
	}
	preview_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;

	temp_reg1 = 0x00;
	switch (sensor_config_data->image_mirror)
	{
		case IMAGE_V_MIRROR:

			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV76X0_preview    IMAGE_V_MIRROR\n\r");
#endif
			while(temp_reg2 != (0x00|temp_reg1))
			{
				write_cmos_sensor(0x1E,(0x00|temp_reg1));
				temp_reg2=read_cmos_sensor(0x1E);
			};
			break;
		case IMAGE_NORMAL:
			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV76X0_preview    IMAGE_NORMAL\n\r");
#endif
			while(temp_reg2 != (0x00|temp_reg1))
			{
				write_cmos_sensor(0x1E,(0x00|temp_reg1));/*0x20*/
				temp_reg2=read_cmos_sensor(0x1E);
			};
			break;
		case IMAGE_H_MIRROR:  //ghw111

			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV76X0_preview    IMAGE_H_MIRROR\n\r");
#endif
			while(temp_reg2 != (0x10|temp_reg1))
			{
				write_cmos_sensor(0x1E,(0x10|temp_reg1));
				temp_reg2=read_cmos_sensor(0x1E);
			};
			break;
		case IMAGE_HV_MIRROR:
			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV76X0_preview    IMAGE_HV_MIRROR\n\r");
#endif
			while(temp_reg2 != (0x30|temp_reg1))
			{
				write_cmos_sensor(0x1E,(0x30|temp_reg1));
				temp_reg2=read_cmos_sensor(0x1E);
			};
			break;
	}

	image_window->grab_start_x=IMAGE_SENSOR_VGA_INSERTED_PIXELS+start_grab_x_offset;
	image_window->grab_start_y=IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines+start_grab_y_offset-1;
	image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
	image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT;

	set_OV7670_dummy(dummy_pixels,dummy_lines);
	write_OV7670_shutter(exposure_lines);
	kal_sleep_task(30);
	if (sensor_config_data->isp_op_mode == ISP_MJPEG_ENCODE_MODE) 
	{
		current_shutter=read_OV7670_shutter();
		
		if (current_shutter < 510)
			current_shutter = 510;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("OV76X0_preview    1257\n\r");
#endif
		sensor_config_data->sensor_frame_rate = 10 * (48000000 / preview_pclk_division / 784 / current_shutter / 2); //1fps=10
	}
	else 
	{
		// ISP_MJPEG_ENCODE_MODE mode does not invok YUV setting API after preview function
		// If turn on AEC/AGC/AWB in ISP_MJPEG_ENCODE_MODE mode, the AWB setting will be overwriten.
		write_cmos_sensor(0x13, 0xF7);  // Turn ON AEC/AGC/AWB
	}
#if defined(NOKE_DEBUG)
	noke_dbg_printf("OV76X0_preview 11111111   1264\n\r");
#endif
	kal_sleep_task(100);		
}	/* OV76X0_preview */

void OV76X0_capture(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	volatile kal_uint32 shutter=exposure_lines;
	kal_uint8 temp_reg;

	sensor_cap_state=KAL_TRUE;

	if(MPEG4_encode_mode)
	{
		ASSERT(0);
	}
	
	if(sensor_config_data->enable_shutter_tansfer==KAL_TRUE)
	{
		shutter=sensor_config_data->capture_shutter;
	}


	#ifdef OUTPUT_DEBUG_INFO
	sprintf(temp_buffer, "Begin of OV76X0_capture");
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	sprintf(temp_buffer, "cap_shutter:%d, pre_shut:%d", shutter, exposure_lines);
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	#endif
	if(!(sensor_config_data->frame_rate==0xF0))	// If not WEBCAM mode.
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("OV76X0_capture    1291\n\r");
#endif
		temp_reg=read_cmos_sensor(0x3B);
		write_cmos_sensor(0x3B,temp_reg&~0x80);
		write_cmos_sensor(0x13,0xE0);  // Turn OFF AEC/AGC/AWB
		shutter=read_OV7670_shutter();
	}
	
	if ((image_window->image_target_width<=IMAGE_SENSOR_1M_WIDTH)&&
		(image_window->image_target_height<=IMAGE_SENSOR_1M_HEIGHT))
	{	/* Less than VGA Mode */
#if defined(NOKE_DEBUG)
	   	noke_dbg_printf("OV76X0_capture    13086\n\r");
#endif
		if (image_window->digital_zoom_factor>=(ISP_DIGITAL_ZOOM_INTERVAL<<1))
		{
			write_cmos_sensor(0x11,0x83);
			SET_TG_PIXEL_CLK_DIVIDER(7);
			SET_CMOS_DATA_LATCH(4);
			if ((image_window->image_target_width==IMAGE_SENSOR_1M_WIDTH)&&
				(image_window->image_target_height==IMAGE_SENSOR_1M_HEIGHT))
				dummy_pixels=2000;
			else
				dummy_pixels=VGA_PERIOD_PIXEL_NUMS/4;
			dummy_lines=102;
		}
	else
	{
		if(sensor_config_data->frame_rate==0xF0)	// That means WEBCAM mode.
		{
#if defined(NOKE_DEBUG)
		   	noke_dbg_printf("OV76X0_capture    1327\n\r");
#endif
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
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV76X0_capture    1341\n\r");
#endif
			write_cmos_sensor(0x11,0x81);    
			SET_TG_PIXEL_CLK_DIVIDER(3);
			SET_CMOS_DATA_LATCH(2);
			
			if ((image_window->image_target_width==IMAGE_SENSOR_1M_WIDTH)&&
				(image_window->image_target_height==IMAGE_SENSOR_1M_HEIGHT))
				dummy_pixels=1000;
			else
				dummy_pixels=0;
			dummy_lines=102;
		}
	}
	
	capture_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
	shutter=(shutter*preview_pclk_division)/capture_pclk_division;
	shutter=(shutter*VGA_PERIOD_PIXEL_NUMS)/(VGA_PERIOD_PIXEL_NUMS+dummy_pixels);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("OV76X0_capture    1360\n\r");
#endif
	image_window->grab_start_x=IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	image_window->grab_start_y=IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines;
	image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
	image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT - 1; // minus 1 to avoid the last black line
	}

	if(shutter<1)
		shutter=1;
	set_OV7670_dummy(dummy_pixels,dummy_lines);
	write_OV7670_shutter(shutter);
	#ifdef OUTPUT_DEBUG_INFO
	sprintf(temp_buffer, "cap_shut:%d, pre_shut:%d, pre_pclk_div=%d, cap_pclk_div=%d, dummy_p=%d, dummy_l=%d", shutter, exposure_lines, preview_pclk_division, capture_pclk_division, dummy_pixels, dummy_lines);
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	sprintf(temp_buffer, "End of OV76X0_capture");
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	#endif
}	/* OV76X0_capture() */

/*************************************************************************
* FUNCTION
*	write_OV7670_reg
*
* DESCRIPTION
*	This function set the register of OV76X0.
*
* PARAMETERS
*	addr : the register index of OV76X0
*  para : setting parameter of the specified register of OV76X0
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void write_OV7670_reg(kal_uint32 addr, kal_uint32 para)
{
	write_cmos_sensor(addr,para);
}	/* write_OV7670_reg() */

/*************************************************************************
* FUNCTION
*	read_cmos_sensor
*
* DESCRIPTION
*	This function read parameter of specified register from OV76X0.
*
* PARAMETERS
*	addr : the register index of OV76X0
*
* RETURNS
*	the data that read from OV76X0
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 read_OV7670_reg(kal_uint32 addr)
{
	return (read_cmos_sensor(addr));
}	/* read_OV7670_reg() */

/*************************************************************************
* FUNCTION
*	set_OV7670_shutter
*
* DESCRIPTION
*	This function set e-shutter of OV76X0 to change exposure time.
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
void set_OV7670_shutter(kal_uint16 shutter)
{
	exposure_lines=shutter;
	write_OV7670_shutter(shutter);
}	/* set_OV7670_shutter */

/*************************************************************************
* FUNCTION
*	set_OV7670_gain
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
kal_uint16 set_OV7670_gain(kal_uint16 gain)
{
   sensor_global_gain=(gain*sensor_gain_base)/BASEGAIN;
   write_OV7670_gain(sensor_global_gain);
   sensor_global_gain=(sensor_global_gain*BASEGAIN)/sensor_gain_base;
   return sensor_global_gain;
}

/*************************************************************************
* FUNCTION
*	OV76X0_night_mode
*
* DESCRIPTION
*	This function night mode of OV76X0.
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
void OV76X0_night_mode(kal_bool enable)
{
		kal_uint8 night = read_cmos_sensor(0x3B);

		 if (!sensor_cap_state) 
		{   
			if (enable) 
			{
				if (g_bMJPEG_mode == KAL_TRUE) 
				{
					write_cmos_sensor(0x3B, night & 0x1F);
					write_cmos_sensor(0x14, 0x38);
				}
				else 
				{
					write_cmos_sensor(0x3B, night | 0xC0);
					write_cmos_sensor(0x14, 0x38);
				}
			}
		 }
		else
		{
			if (g_bMJPEG_mode == KAL_TRUE) 
			{
				write_cmos_sensor(0x3B, night & 0x1F);
				write_cmos_sensor(0x14, 0x28);
			}
			else
			{
				write_cmos_sensor(0x3B,night&0x1F);
				write_cmos_sensor(0x14,0x28);
				write_cmos_sensor(0x2D,0x00);
				write_cmos_sensor(0x2E,0x00);
			}
		}
}	/* OV76X0_night_mode */

/*************************************************************************
* FUNCTION
*	set_OV7670_flashlight
*
* DESCRIPTION
*	turn on/off OV76X0 flashlight .
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
void set_OV7670_flashlight(kal_bool enable)
{
	// Todo
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_zoom
*
* DESCRIPTION
*	OV76X0 zoom setting.
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
kal_uint32 set_OV7670_param_zoom(kal_uint32 para)
{
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_contrast
*
* DESCRIPTION
*	OV76X0 contrast setting.
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
kal_uint32 set_OV7670_param_contrast(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_brightness
*
* DESCRIPTION
*	OV76X0 brightness setting.
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
kal_uint32 set_OV7670_param_brightness(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_hue
*
* DESCRIPTION
*	OV76X0 hue setting.
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
kal_uint32 set_OV7670_param_hue(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_gamma
*
* DESCRIPTION
*	OV76X0 gamma setting.
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
kal_uint32 set_OV7670_param_gamma(kal_uint32 para)
{
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_wb
*
* DESCRIPTION
*	OV76X0 wb setting.
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
kal_uint32 set_OV7670_param_wb(kal_uint32 para)
{
	kal_uint8  temp_reg;

	temp_reg=read_cmos_sensor(0x13);
	switch (para)
	{
		case CAM_WB_AUTO:
			write_cmos_sensor(0x01,0x56);
			write_cmos_sensor(0x02,0x44);
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
			break;		

		default:
			return KAL_FALSE;			
	}	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_exposure
*
* DESCRIPTION
*	OV76X0 exposure setting.
*
* PARAMETERS
*	none
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_OV7670_param_exposure(kal_uint32 para)
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
*	set_OV7670_param_effect
*
* DESCRIPTION
*	OV76X0 effect setting.
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
kal_uint32 set_OV7670_param_effect(kal_uint32 para)
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
		case CAM_EFFECT_ENC_SKETCH:			
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
*	set_OV7670_param_banding
*
* DESCRIPTION
*	OV76X0 banding setting.
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
kal_uint32 set_OV7670_param_banding(kal_uint32 para)
{
	kal_uint8 banding;


	banding=read_cmos_sensor(0x3b);
	switch (para)
	{
		case CAM_BANDING_50HZ:
			write_cmos_sensor(0x3b,banding|0x08);	    // 50 Hz //		
			write_cmos_sensor(0x9D,0x99);	// 50Hz Filter Value //					
            break;

		case CAM_BANDING_60HZ:
			write_cmos_sensor(0x3b,banding&0xF7);	    // 60 Hz //				
			write_cmos_sensor(0x9E,0x7F);	// 60Hz Filter Value//							
            break;

		default:
			return KAL_FALSE;		
	}	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_saturation
*
* DESCRIPTION
*	OV76X0 SATURATION setting.
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
kal_uint32 set_OV7670_param_saturation(kal_uint32 para)
{
    // Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_nightmode
*
* DESCRIPTION
*	OV76X0 night mode setting.
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
kal_uint32 set_OV7670_param_nightmode(kal_uint32 para)
{
	OV76X0_night_mode((kal_bool)para);
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7670_param_ev
*
* DESCRIPTION
*	OV76X0 ev setting.
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
kal_uint32 set_OV7670_param_ev(kal_uint32 para)
{
	return set_OV7670_param_exposure(para);
}

/*************************************************************************
* FUNCTION
*	OV76X0_yuv_sensor_setting
*
* DESCRIPTION
*	This function send command and parameter to yuv sensor module OV76X0
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
kal_uint32 OV76X0_yuv_sensor_setting(kal_uint32 cmd, kal_uint32 para)
{
	kal_uint32 ret = KAL_TRUE;
	switch (cmd)
	{
		case CAM_PARAM_ZOOM_FACTOR:
			ret = set_OV7670_param_zoom(para);		
			break;			
		case CAM_PARAM_CONTRAST:
			ret = set_OV7670_param_contrast(para);		
			break;					
		case CAM_PARAM_BRIGHTNESS:
			ret = set_OV7670_param_brightness(para);		
			break;							
		case CAM_PARAM_HUE:
			ret = set_OV7670_param_hue(para);		
			break;							
		case CAM_PARAM_GAMMA:
			ret = set_OV7670_param_gamma(para);		
			break;							
		case CAM_PARAM_WB:
			ret = set_OV7670_param_wb(para);		
			break;
		case CAM_PARAM_EXPOSURE:
			ret = set_OV7670_param_exposure(para);		
			break;							
		case CAM_PARAM_EFFECT:
			ret = set_OV7670_param_effect(para);
			break;		
		case CAM_PARAM_BANDING:
			ret = set_OV7670_param_banding(para);		
			break;		
		case CAM_PARAM_SATURATION:
			ret = set_OV7670_param_saturation(para);				
			break;						
		case CAM_PARAM_NIGHT_MODE:
			ret = set_OV7670_param_nightmode(para);				
			break;						
		case CAM_PARAM_EV_VALUE:
			ret = set_OV7670_param_ev(para);				
			break;				
		default:
			ret = KAL_FALSE;
	}
	return ret;
}

/*************************************************************************
* FUNCTION
*	image_sensor_func_OV7670
*
* DESCRIPTION
*	OV76X0 Image Sensor functions struct.
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
image_sensor_func_struct image_sensor_func_OV7670=
{
	init_OV7670,
	get_OV7670_id,
	get_OV7670_size,
	get_OV7670_period,
	OV76X0_preview,
	OV76X0_capture,
	write_OV7670_reg,
	read_OV7670_reg,
	set_OV7670_shutter,
	OV76X0_night_mode,
	power_off_OV7670,
	set_OV7670_gain,
	set_OV7670_flashlight,
	OV76X0_yuv_sensor_setting
};	/* image_sensor_func_OV7670 */

// write camera_para to sensor register
void camera_para_to_sensor_OV7670(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_OV7670_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_OV7670_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=0; i<CCT_END_ADDR; i++)
	{
		write_OV7670_reg(camera_para.SENSOR.cct[i].addr, camera_para.SENSOR.cct[i].para);
	}
}

// update camera_para from sensor register
void sensor_to_camera_para_OV7670(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_OV7670_reg(camera_para.SENSOR.reg[i].addr);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_OV7670_reg(camera_para.SENSOR.reg[i].addr);
	}
}

//------------------------Engineer mode---------------------------------

void  get_sensor_group_count_OV7670(kal_int32* sensor_count_ptr)
{
   *sensor_count_ptr=GROUP_TOTAL_NUMS;
   
	return;
}

void get_sensor_group_info_OV7670(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
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

void get_sensor_item_info_OV7670(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr)
{
	kal_uint8 temp_reg;
	
	switch (group_idx)
	{
		case AWB_GAIN:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"AWB R Gain");
				  info_ptr->item_value=read_OV7670_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr);
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0xff;
				break; 
				case 1:
				  sprintf(info_ptr->item_name_ptr,"AWB B Gain");
				  info_ptr->item_value=read_OV7670_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr);
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
				  
				  temp_reg = read_OV7670_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
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
				  
				  temp_reg = read_OV7670_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
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
				  
				  temp_reg = read_OV7670_gain();
				  
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
				  
				  temp_reg = read_OV7670_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
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
				  
				  temp_reg = read_OV7670_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
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

kal_bool set_sensor_item_info_OV7670(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
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
				  write_OV7670_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr,item_value);
				break;
				case 1:
				  camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].para = item_value;
				  write_OV7670_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr,item_value);
				break; 
				default:
				   ASSERT(0);
			}			
		break;
		case PRE_GAIN:
			switch (item_idx)
			{
				case 0:
				  temp_reg = read_OV7670_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
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
				  write_OV7670_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr,temp_reg);
				break;
				case 1:
				  temp_reg = read_OV7670_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
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
				  write_OV7670_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr,temp_reg);
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
				  write_OV7670_reg(camera_para.SENSOR.cct[GLOBAL_GAIN_INDEX].addr,temp_reg);
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
				      temp_reg = read_OV7670_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg |= 0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_OV7670_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
				  }
				  else
				  {
				      temp_reg = read_OV7670_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg &= ~0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_OV7670_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
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
				  temp_reg = read_OV7670_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
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
				  write_OV7670_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr,temp_reg);
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
				  write_OV7670_reg(FAC_SENSOR_REG,item_value);
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

kal_bool is_sensor_ready_OV7670()
{
	kal_sleep_task(4);
	write_cmos_sensor(0x12,0x80);
	kal_sleep_task(2);
	sensor_id=(read_cmos_sensor(0x0A)<<8)|read_cmos_sensor(0x0B);	

#ifdef NOKE_DEBUG
	noke_dbg_printf("\r CAMERA : is_sensor_ready_OV7670 : sensor_id = 0x%04x \n", sensor_id);
#endif
	
	if( OV7670_SENSOR_ID == sensor_id )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*

    以下是主摄像头的初始化函数， 不同厂家的不一样。

*/

void main_camera_ov7670_init_func_default(void)
{
	//write_cmos_sensor(0x11,0x01);
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

	// add by joe ovt 12/14/2006
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
	write_cmos_sensor(0x10,0x00);
	write_cmos_sensor(0x0d,0x40);
	write_cmos_sensor(0x14,0x28);
	write_cmos_sensor(0xa5,0x02);  
	write_cmos_sensor(0xab,0x02);  
	write_cmos_sensor(0x24,0x68);
	write_cmos_sensor(0x25,0x58);
	write_cmos_sensor(0x26,0xc2);   //e3
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
	//
	write_cmos_sensor(0x6a,0x40);
	write_cmos_sensor(0x01,0x56);
	write_cmos_sensor(0x02,0x44);
	write_cmos_sensor(0x13,0xe7);

	/* Color Matrix */

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
	/*UNI@bw070906 [6225 7670][all customers] preview framerate 为12.5fps */
	write_cmos_sensor(0x9d,0x4c);
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

	//L99 LENS
	write_cmos_sensor(0x62,0x00);
	write_cmos_sensor(0x63,0x00);
	write_cmos_sensor(0x64,0x06);
	write_cmos_sensor(0x65,0x00);
	write_cmos_sensor(0x66,0x05);
	write_cmos_sensor(0x94,0x05);
	//write_cmos_sensor(0x95,0x0D); //OVT joe 12/14/2006
	write_cmos_sensor(0x95,0x09);	//OVT joe 12/14/2006	

	normal_gain = read_cmos_sensor(0x00);
	sensor_gain_base = read_OV7670_gain();
}

/*

    以下是副摄像头的初始化函数， 不同厂家的不一样。

*/
#if defined(DOUBLE_CAMERA_SUPPORT)
void sub_camera_ov7670_init_func_default(void)
{
	//write_cmos_sensor(0x11,0x01);
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

	// add by joe ovt 12/14/2006
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
	write_cmos_sensor(0x10,0x00);
	write_cmos_sensor(0x0d,0x40);
	write_cmos_sensor(0x14,0x28);
	write_cmos_sensor(0xa5,0x02);  
	write_cmos_sensor(0xab,0x02);  
	write_cmos_sensor(0x24,0x68);
	write_cmos_sensor(0x25,0x58);
	write_cmos_sensor(0x26,0xc2);   //e3
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
	//
	write_cmos_sensor(0x6a,0x40);
	write_cmos_sensor(0x01,0x56);
	write_cmos_sensor(0x02,0x44);
	write_cmos_sensor(0x13,0xe7);

	/* Color Matrix */

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
	/*UNI@bw070906 [6225 7670][all customers] preview framerate 为12.5fps */
	write_cmos_sensor(0x9d,0x4c);
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

	//L99 LENS
	write_cmos_sensor(0x62,0x00);
	write_cmos_sensor(0x63,0x00);
	write_cmos_sensor(0x64,0x06);
	write_cmos_sensor(0x65,0x00);
	write_cmos_sensor(0x66,0x05);
	write_cmos_sensor(0x94,0x05);
	//write_cmos_sensor(0x95,0x0D); //OVT joe 12/14/2006
	write_cmos_sensor(0x95,0x09);	//OVT joe 12/14/2006	

	normal_gain = read_cmos_sensor(0x00);
	sensor_gain_base = read_OV7670_gain();
}
#endif
