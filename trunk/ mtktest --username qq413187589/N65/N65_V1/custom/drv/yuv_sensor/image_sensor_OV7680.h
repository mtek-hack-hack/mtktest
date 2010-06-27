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

#define OV7680_SENSOR_ID							0x7680
#define OV7680_WRITE_ID							0x42
#define OV7680_READ_ID								0x43
	
#define OV7680_VGA_PERIOD_PIXEL_NUMS						780
#define OV7680_VGA_PERIOD_LINE_NUMS						512
#define OV7680_VGA_EXPOSURE_LIMITATION					512

#define OV7680_IMAGE_SENSOR_VGA_INSERTED_PIXELS	       124    //124
#define OV7680_IMAGE_SENSOR_VGA_INSERTED_LINES			18

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


void write_OV7680_shutter(kal_uint16 shutter)
{
   	 kal_uint8 temp_reg;
	
}	/* write_OV7680_shutter */

kal_uint16 read_OV7680_shutter(void)
{
	kal_uint8 temp_reg1, temp_reg2, temp_reg3, temp_reg4, temp_reg5;
	kal_uint16 shutter;

	temp_reg1=read_cmos_sensor(0x0F);										// AEC[b1~b0]
	temp_reg2=read_cmos_sensor(0x10);										// AEC[b9~b2]										// AEC[b15~b10]
	
	temp_reg4=read_cmos_sensor(0x2D);
	temp_reg5=read_cmos_sensor(0x2E);
	
	shutter=(temp_reg1<<8)|(temp_reg2);	
	extra_exposure_lines=(temp_reg5<<8)|(temp_reg4);

	exposure_lines=shutter+extra_exposure_lines;
	return exposure_lines;
}	/* read_OV7680_shutter */

void write_OV7680_gain(kal_uint16 gain)
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
}  /* write_OV7680_gain */

kal_uint16 read_OV7680_gain(void)
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
}  /* read_OV7680_gain */

void set_OV7680_dummy(kal_uint16 pixels, kal_uint16 lines)
{

}	/* set_OV7680_dummy */

/*************************************************************************
* FUNCTION
*	config_OV7680_window
*
* DESCRIPTION
*	This function config the hardware window of OV7680 for getting specified
*  data of that window.
*
* PARAMETERS
*	start_x : start column of the interested window
*  start_y : start row of the interested window
*  width  : column widht of the itnerested window
*  height : row depth of the itnerested window
*
* RETURNS
*	the data that read from OV7680
*
* GLOBALS AFFECTED
*
*************************************************************************/
void config_OV7680_window(kal_uint16 startx,kal_uint16 starty,kal_uint16 width, kal_uint16 height)
{
	kal_uint16 endx=(startx+width-1);
	kal_uint16 endy=(starty+height-1);
	kal_uint8  temp_reg1, temp_reg2;
	kal_uint8  temp_width, temp_height;

#if defined(NOKE_DEBUG)
		noke_dbg_printf("config_OV7680_window   568\n\r");
#endif
		temp_width = width;
		temp_height = height;
		temp_reg1=(read_cmos_sensor(0x16)&0xbc);
		// Horizontal
		write_cmos_sensor(0x16,temp_reg1|(startx&0x3)|(((temp_width>>1)&0x1)<<6));	// b[5:3]:HREF end low 3bits. b[2:0]:HREF start low 3bits.
		write_cmos_sensor(0x17,(startx&0x3Fc)>>2);			// HREF start high 8bits
		write_cmos_sensor(0x18,(temp_width&0x3fc)>>2);			// HREF end high 8bits
		// Vertical
		temp_reg2=(read_cmos_sensor(0x16)&0xf3);
		write_cmos_sensor(0x16,temp_reg2|((starty&0x3)<<2));	// b[3:2]:VREF end low 2bits. b[1:0]:VREF start low 2bits.
		write_cmos_sensor(0x19,(starty&0x3FC)>>2);   			// VREF start high 8bits
		write_cmos_sensor(0x1A,temp_height>>1);	
}	/* config_OV7680_window */


/*************************************************************************
* FUNCTION
*	init_OV7680
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
kal_int8 init_OV7680(void)
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
*	power_off_OV7680
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

void power_off_OV7680(void)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("power_off_OV7680  1004\n\r");
#endif
	cis_module_power_on(KAL_FALSE);      // Power Off CIS Power modified by fred fan 2007-12-19 //ghw111
	UPLL_Disable(UPLL_OWNER_ISP);
	#ifndef HW_SCCB
           #if !defined(BEIW3H_BOARD_DRV)
	   SET_SCCB_CLK_LOW;
	   SET_SCCB_DATA_LOW;
	#endif
	#endif
}	/* power_off_OV7680 */

/*************************************************************************
* FUNCTION
*	get_OV7680_id
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
void get_OV7680_id(kal_uint8 *sensor_write_id, kal_uint8 *sensor_read_id)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("get_OV7680_id  1047\n\r");
#endif
	*sensor_write_id=OV7680_WRITE_ID;
	*sensor_read_id=OV7680_READ_ID;
}	/* get_OV7680_id */

/*************************************************************************
* FUNCTION
*	get_OV7680_size
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
void get_OV7680_size(kal_uint16 *sensor_width, kal_uint16 *sensor_height)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("get_OV7680_size  1071\n\r");
#endif
	*sensor_width=IMAGE_SENSOR_VGA_WIDTH;			/* pixel numbers actually used in one frame */
	*sensor_height=IMAGE_SENSOR_VGA_HEIGHT;		/* line numbers actually used in one frame */
}	/* get_OV7680_size */

/*************************************************************************
* FUNCTION
*	get_OV7680_period
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
void get_OV7680_period(kal_uint16 *pixel_number, kal_uint16 *line_number)
{
	*pixel_number=OV7680_VGA_PERIOD_PIXEL_NUMS;	/* pixel numbers in one period of HSYNC */
	*line_number=OV7680_VGA_PERIOD_LINE_NUMS;	/* line numbers in one period of VSYNC */
}	/* get_OV7680_period */

void OV7680_preview(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	volatile kal_uint32 temp_reg3,temp_reg2, temp_reg1;
	kal_uint8 iTemp;
	kal_uint16 current_shutter;
 
	sensor_cap_state=KAL_FALSE;
	g_bMJPEG_mode = KAL_FALSE;

		temp_reg2=read_cmos_sensor(0x0C);
		temp_reg1=(temp_reg2&0x3F);
#if defined(NOKE_DEBUG)
		noke_dbg_printf("OV7680_preview 1268   temp_reg1=%x\n\r  " ,temp_reg1);
		noke_dbg_printf("OV7680_preview 1169  temp_reg2=%x\n\r  " ,temp_reg2);
#endif		
		write_cmos_sensor(0x11,0x81);	//MCLK/2 = PCLK 81 modified by fred fan 2007_12-13 for test

		if(sensor_config_data->frame_rate==0x0F)		// MPEG4 Encode Mode
		{
			MPEG4_encode_mode=KAL_TRUE;
			
			if(hejctest)
			{
				hejctest = 0;
#if defined(NOKE_DEBUG)				
				noke_dbg_printf("sensor_config_data->frame_rate1208==0x0F");
#endif
				//kal_sleep_task(300);
				/* config TG of ISP to match the setting of image sensor*/
				SET_TG_OUTPUT_CLK_DIVIDER(3);
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(2);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(3);
				SET_CMOS_DATA_LATCH(2);
				dummy_pixels=0;
				dummy_lines=34;
			}
			else
			{
#if defined(NOKE_DEBUG)
				noke_dbg_printf("sensor_config_data->frame_rate1221=0x0F");
#endif
				//kal_sleep_task(300);
				//kal_prompt_trace(MOD_MMI,"+++++++++++++++++hejc11++++++++++++++");
				SET_TG_OUTPUT_CLK_DIVIDER(3);
				SET_CMOS_RISING_EDGE(0);
				SET_CMOS_FALLING_EDGE(2);
				ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(3);
				SET_CMOS_DATA_LATCH(1);
				dummy_pixels=0;
				dummy_lines=34;			
			}
		}
	    	else
	    	{
			MPEG4_encode_mode=KAL_FALSE;
#if defined(NOKE_DEBUG)
			noke_dbg_printf("sensor_config_data->frame_rate1236!=0x0F\n\r");
#endif
			SET_TG_OUTPUT_CLK_DIVIDER(3);
			SET_CMOS_RISING_EDGE(0);
			SET_CMOS_FALLING_EDGE(2);
			ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
			SET_TG_PIXEL_CLK_DIVIDER(3);
			SET_CMOS_DATA_LATCH(3);
			dummy_pixels = 0;
			dummy_lines = 34;
	   	 }

		preview_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
#if 0
	if(mmi_main_camera_active)
	sensor_config_data->image_mirror = IMAGE_HV_MIRROR;
	else
	sensor_config_data->image_mirror = IMAGE_V_MIRROR; //ghw111
#endif

		switch (sensor_config_data->image_mirror)	
		{
			case IMAGE_H_MIRROR:
#if defined(NOKE_DEBUG)
				noke_dbg_printf("IMAGE_NORMAL\n\r");
#endif
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
				while(temp_reg2 !=  (0x40|temp_reg1))
				{
#if defined(NOKE_DEBUG)
					noke_dbg_printf("IMAGE_NORMAL\n\r");
#endif
					write_cmos_sensor(0x0C,(0x40|temp_reg1));
					temp_reg2=read_cmos_sensor(0x0C);
#if defined(NOKE_DEBUG)
					noke_dbg_printf("OV7680_preview 1260   temp_reg2=%x\n\r  " ,temp_reg2);
#endif
					//write_cmos_sensor(0x78, iTemp | 0x00); // 0x78[6] must be equal to 0x1E[5]
				};
				break;
			case IMAGE_NORMAL://ghw111
#if defined(NOKE_DEBUG)
				noke_dbg_printf("IMAGE_H_MIRROR\n\r");
#endif
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CrYCbY1);//ghw111		
				while(temp_reg2 != (0x00|temp_reg1))
				{
					write_cmos_sensor(0x0C,(0x00|temp_reg1));
					temp_reg2=read_cmos_sensor(0x0C);
#if defined(NOKE_DEBUG)
					noke_dbg_printf("OV7680_preview 1271   temp_reg2=%x\n\r  " ,temp_reg2);
#endif
				};
				break;
			case IMAGE_V_MIRROR:
#if defined(NOKE_DEBUG)
				noke_dbg_printf("IMAGE_V_MIRROR\n\r");
#endif
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);	
				while(temp_reg2 != (0x80|temp_reg1))
				{
					write_cmos_sensor(0x0C,(0x80|temp_reg1));
					temp_reg2=read_cmos_sensor(0x0C);
#if defined(NOKE_DEBUG)
					noke_dbg_printf("OV7680_preview 1280   temp_reg2=%x\n\r  " ,temp_reg2);
#endif
				};
				break;
			case IMAGE_HV_MIRROR:
#if defined(NOKE_DEBUG)
				noke_dbg_printf("IMAGE_HV_MIRROR\n\r");
#endif
				SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);		
				while(temp_reg2 != (0xc0|temp_reg1))
				{
					write_cmos_sensor(0x0C,(0xc0|temp_reg1));
					temp_reg2=read_cmos_sensor(0x0C);
#if defined(NOKE_DEBUG)
					noke_dbg_printf("OV7680_preview 1291   temp_reg2=%x\n\r  " ,temp_reg2);
#endif
					//write_cmos_sensor(0x78, iTemp | 0x40);  // 0x78[6] must be equal to 0x1E[5]
				};
				break;
			}
		
#if defined(NOKE_DEBUG)
			noke_dbg_printf("IMAGE_SENSOR_VGA_INSERTED_PIXELS1336\n\r");/*alex.xie*/
#endif
			image_window->grab_start_x =164;//158//140+start_grab_x_offset;//+start_grab_x_offset;  //56+start_grab_x_offset;//158;//IMAGE_SENSOR_VGA_INSERTED_PIXELS+start_grab_x_offset;    ???2/4/8???
			image_window->grab_start_y =53;//18+dummy_lines+start_grab_y_offset;;//+dummy_lines+start_grab_y_offset;//17+dummy_lines+start_grab_y_offset;//44;//IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines+start_grab_y_offset;
			image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
			image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT;

			write_cmos_sensor(0x2A,0xc0);
			write_cmos_sensor(0x2B,0x30);
			write_cmos_sensor(0x2c,dummy_lines);

			kal_sleep_task(10);
			// Turn ON AEC/AGC/AWB
			write_cmos_sensor(0x13, 0xF7);  
			kal_sleep_task(50);		
}	/* OV7680_preview */

void OV7680_capture(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
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

		if(!(sensor_config_data->frame_rate==0xF0))	// If not WEBCAM mode.
		{ 
			// turn off night mode
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV7680_catch 1390\n\r");//ok
#endif			
			if(sensor_id == 0x7680)
			{
				;
			}
			write_cmos_sensor(0x13,0xE0);  // Turn OFF AEC/AGC/AWB
			shutter=read_OV7680_shutter();            
		}
    	
		if ((image_window->image_target_width<=IMAGE_SENSOR_1M_WIDTH)&&
			(image_window->image_target_height<=IMAGE_SENSOR_1M_HEIGHT))
		{	/* Less than VGA Mode */
			if (image_window->digital_zoom_factor>=(ISP_DIGITAL_ZOOM_INTERVAL<<1))
			{
#if defined(NOKE_DEBUG)
				noke_dbg_printf("OV7680_catch 1410\n\r");
#endif
				write_cmos_sensor(0x11,0x83);
				
				SET_TG_PIXEL_CLK_DIVIDER(7);
				SET_CMOS_DATA_LATCH(4);
				
				if ((image_window->image_target_width==IMAGE_SENSOR_1M_WIDTH)&&
					(image_window->image_target_height==IMAGE_SENSOR_1M_HEIGHT))
				{
#if defined(NOKE_DEBUG)
					noke_dbg_printf("OV7680_catch 1417\n\r");
#endif
					dummy_pixels=2000;
					if(sensor_id == 0x7680)
					{
						write_cmos_sensor(0x2A,0xF0);
						write_cmos_sensor(0x2B,0x00);
					}
				}
				else
				{
					dummy_pixels=VGA_PERIOD_PIXEL_NUMS/4;
#if defined(NOKE_DEBUG)
					noke_dbg_printf("OV7680_catch 14317\n\r");
#endif
				}
				dummy_lines=0;
			}
			else
			{
				if(sensor_config_data->frame_rate==0xF0)	// That means WEBCAM mode.
				{
					write_cmos_sensor(0x11,0x80);
#if defined(NOKE_DEBUG)
					noke_dbg_printf("OV7680_catch 1440\n\r");
#endif
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
					noke_dbg_printf("OV7680_catch 1452\n\r");//ok
#endif					
				    write_cmos_sensor(0x11,0x81);//0x81 modified by fred fan 2007-12-14
				    
					SET_TG_PIXEL_CLK_DIVIDER(3);
					SET_CMOS_DATA_LATCH(2);
					
					if ((image_window->image_target_width==IMAGE_SENSOR_1M_WIDTH)&&
						(image_window->image_target_height==IMAGE_SENSOR_1M_HEIGHT))
					{
#if defined(NOKE_DEBUG)
						noke_dbg_printf("OV7680_catch 1461\n\r");
#endif
						dummy_pixels=2000;
							write_cmos_sensor(0x2A,0xF0);
							write_cmos_sensor(0x2B,0xFF);
							write_cmos_sensor(0x2c,dummy_lines);
					}
					else
						dummy_pixels=0;
					dummy_lines=0;
				}
			}
			
			capture_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV7680_catch 1468  capture_pclk_division=%x\n\r  " ,capture_pclk_division);
#endif
			shutter=(shutter*preview_pclk_division)/capture_pclk_division;
			shutter=(shutter*VGA_PERIOD_PIXEL_NUMS)/(VGA_PERIOD_PIXEL_NUMS+dummy_pixels);
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV7680_catch 1468  shutter=%x\n\r  " ,shutter);
#endif
			image_window->grab_start_x=164; /*alex.xie*/
			image_window->grab_start_y=53;//+dummy_lines;
#if defined(NOKE_DEBUG)
			noke_dbg_printf("OV7680_catch 1475   image_window->grab_start_y=%x\n\r  " ,image_window->grab_start_y);
#endif
			image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
			image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT - 1; // minus 1 to avoid the last black line		
		}
	
		if(shutter<1)
			shutter=1;
}	/* OV7680_capture() */

/*************************************************************************
* FUNCTION
*	write_OV7680_reg
*
* DESCRIPTION
*	This function set the register of OV7680.
*
* PARAMETERS
*	addr : the register index of OV7680
*  para : setting parameter of the specified register of OV7680
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void write_OV7680_reg(kal_uint32 addr, kal_uint32 para)
{
	write_cmos_sensor(addr,para);
}	/* write_OV7680_reg() */

/*************************************************************************
* FUNCTION
*	read_cmos_sensor
*
* DESCRIPTION
*	This function read parameter of specified register from OV7680.
*
* PARAMETERS
*	addr : the register index of OV7680
*
* RETURNS
*	the data that read from OV7680
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 read_OV7680_reg(kal_uint32 addr)
{
	return (read_cmos_sensor(addr));
}	/* read_OV7680_reg() */

/*************************************************************************
* FUNCTION
*	set_OV7680_shutter
*
* DESCRIPTION
*	This function set e-shutter of OV7680 to change exposure time.
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
void set_OV7680_shutter(kal_uint16 shutter)
{
	exposure_lines=shutter;
	write_OV7680_shutter(shutter);
}	/* set_OV7680_shutter */

/*************************************************************************
* FUNCTION
*	set_OV7680_gain
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
kal_uint16 set_OV7680_gain(kal_uint16 gain)
{
   sensor_global_gain=(gain*sensor_gain_base)/BASEGAIN;
   write_OV7680_gain(sensor_global_gain);
   sensor_global_gain=(sensor_global_gain*BASEGAIN)/sensor_gain_base;
   return sensor_global_gain;
}

/*************************************************************************
* FUNCTION
*	OV7680_night_mode
*
* DESCRIPTION
*	This function night mode of OV7680.
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
void OV7680_night_mode(kal_bool enable)
{
		kal_uint8 night = read_cmos_sensor(0x3B);

			if (enable) 
			{
				write_cmos_sensor(0x15, 0xC4);
			}
			else
			{
				write_cmos_sensor(0x15,0x00);
			}
}	/* OV7680_night_mode */

/*************************************************************************
* FUNCTION
*	set_OV7680_flashlight
*
* DESCRIPTION
*	turn on/off OV7680 flashlight .
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
void set_OV7680_flashlight(kal_bool enable)
{
	// Todo
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_zoom
*
* DESCRIPTION
*	OV7680 zoom setting.
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
kal_uint32 set_OV7680_param_zoom(kal_uint32 para)
{
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_contrast
*
* DESCRIPTION
*	OV7680 contrast setting.
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
kal_uint32 set_OV7680_param_contrast(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_brightness
*
* DESCRIPTION
*	OV7680 brightness setting.
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
kal_uint32 set_OV7680_param_brightness(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_hue
*
* DESCRIPTION
*	OV7680 hue setting.
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
kal_uint32 set_OV7680_param_hue(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_gamma
*
* DESCRIPTION
*	OV7680 gamma setting.
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
kal_uint32 set_OV7680_param_gamma(kal_uint32 para)
{
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_wb
*
* DESCRIPTION
*	OV7680 wb setting.
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
kal_uint32 set_OV7680_param_wb(kal_uint32 para)
{
	kal_uint16 rgain=0x80, ggain=0x80, bgain=0x80;
	kal_uint8  temp_reg;

		temp_reg=read_cmos_sensor(0x13);
		switch (para)
		{
			case CAM_WB_AUTO:
				write_cmos_sensor(0x13,temp_reg|0x2);   // Enable AWB		
				break;

			case CAM_WB_CLOUD:  //7050K
				write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
				write_cmos_sensor(0x01,0x5C);
				write_cmos_sensor(0x02,0x56);
				break;		

			case CAM_WB_DAYLIGHT:  //6500K
				write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
				write_cmos_sensor(0x01,0x58);
				write_cmos_sensor(0x02,0x56);
				break;		

			case CAM_WB_INCANDESCENCE://8500K
				write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
				write_cmos_sensor(0x01,0x58);
				write_cmos_sensor(0x02,0x60);
				break;		

			case CAM_WB_FLUORESCENT://8500K
				write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
				write_cmos_sensor(0x01,0x58);
				write_cmos_sensor(0x02,0x60);
				break;		

			case CAM_WB_TUNGSTEN:  //2800K
				write_cmos_sensor(0x13,temp_reg&~0x2);  // Disable AWB				
				write_cmos_sensor(0x01,0xCC);
				write_cmos_sensor(0x02,0x40);
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
*	set_OV7680_param_exposure
*
* DESCRIPTION
*	OV7680 exposure setting.
*
* PARAMETERS
*	none
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 set_OV7680_param_exposure(kal_uint32 para)
{
	kal_uint8 temp;
		temp = read_cmos_sensor(0xd5);	
		write_cmos_sensor(0xd5, temp|0x04);	
		switch (para)
		{
		case CAM_EV_NEG_4_3:    
		    //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x40);	
			write_cmos_sensor(0xdf, 0x09);	
			break;		
		case CAM_EV_NEG_3_3:
		    //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x30);	
			write_cmos_sensor(0xdf, 0x09);	
			break;		
		case CAM_EV_NEG_2_3:
		    //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x20);	
			write_cmos_sensor(0xdf, 0x09);	
			break;				
		case CAM_EV_NEG_1_3:
		   //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x10);	
			write_cmos_sensor(0xdf, 0x09);	
			break;				
		case CAM_EV_ZERO:
		    //write_cmos_sensor(0x81, 0x04);	
			write_cmos_sensor(0xd6, 0x00);	
			break;				
		case CAM_EV_POS_1_3:
		    //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x10);	
			write_cmos_sensor(0xdf, 0x01);	
			break;				
		case CAM_EV_POS_2_3:
		    //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x20);	
			write_cmos_sensor(0xdf, 0x01);	
			break;				
		case CAM_EV_POS_3_3:
		    //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x30);	
			write_cmos_sensor(0xdf, 0x01);	
			break;				
		case CAM_EV_POS_4_3:	
		    //write_cmos_sensor(0x81, 0x06);	
			write_cmos_sensor(0xd6, 0x40);	
			write_cmos_sensor(0xdf, 0x01);	
			break;
		default:
			return KAL_FALSE;    
		}
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_effect
*
* DESCRIPTION
*	OV7680 effect setting.
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
kal_uint32 set_OV7680_param_effect(kal_uint32 para)
{
    kal_uint32  ret = KAL_TRUE;
	kal_uint8 temp;

		temp = read_cmos_sensor(0xd5);	
		temp &= 0x04;
		switch (para)
		{	
			case CAM_EFFECT_ENC_NORMAL:
				write_cmos_sensor(0x81,0x06);		
				write_cmos_sensor(0xd5,0x02|temp);
				write_cmos_sensor(0xDD,0x80);	
				write_cmos_sensor(0xDE,0x80);
				break;		
			case CAM_EFFECT_ENC_GRAYSCALE:
				write_cmos_sensor(0x81,0x07);		
				write_cmos_sensor(0xd5,0x20|temp);	
				write_cmos_sensor(0xDD,0x80);	
				write_cmos_sensor(0xDE,0x80);
				break;	
			case CAM_EFFECT_ENC_SEPIA:
				write_cmos_sensor(0x81,0x07);		
				write_cmos_sensor(0xd5,0x18|temp);
				write_cmos_sensor(0xDD,0xa0);	
				write_cmos_sensor(0xDE,0x40);			
				break;	
			case CAM_EFFECT_ENC_SEPIAGREEN:
				write_cmos_sensor(0x81,0x07);		
				write_cmos_sensor(0xd5,0x18|temp);
				write_cmos_sensor(0xDD,0x60);	
				write_cmos_sensor(0xDE,0x60);				
				break;		
			case CAM_EFFECT_ENC_SEPIABLUE:
				write_cmos_sensor(0x81,0x07);		
				write_cmos_sensor(0xd5,0x18|temp);
				write_cmos_sensor(0xDD,0x80);	
				write_cmos_sensor(0xDE,0xC0);					
				break;					
			case CAM_EFFECT_ENC_COLORINV:
				write_cmos_sensor(0x81,0x06);		
				write_cmos_sensor(0xd5,0x40|temp);	
				write_cmos_sensor(0xDD,0x80);	
				write_cmos_sensor(0xDE,0x80);
				break;			
									
			case CAM_EFFECT_ENC_GRAYINV:
							
			case CAM_EFFECT_ENC_COPPERCARVING:
								
	    		case CAM_EFFECT_ENC_BLUECARVING:
								
			case CAM_EFFECT_ENC_CONTRAST:
						
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
*	set_OV7680_param_banding
*
* DESCRIPTION
*	OV7680 banding setting.
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
kal_uint32 set_OV7680_param_banding(kal_uint32 para)
{
	kal_uint8 banding;

		//banding=read_cmos_sensor(0x14);
		switch (para)
		{
			case CAM_BANDING_50HZ:
				//write_cmos_sensor(0x14,banding&0xF6);	    // 50 Hz //		
				//write_cmos_sensor(0x20,XXXX);	// 50Hz Filter Value //
				//write_cmos_sensor(0x21,XXXX);					
	            break;

			case CAM_BANDING_60HZ:
				//write_cmos_sensor(0x14,banding|0x01);	    // 60 Hz //				
				//write_cmos_sensor(0x20,XXXX);	// 60Hz Filter Value //
				//write_cmos_sensor(0x21,XXXX);								
	            break;

			default:
				return KAL_FALSE;		
		}	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_saturation
*
* DESCRIPTION
*	OV7680 SATURATION setting.
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
kal_uint32 set_OV7680_param_saturation(kal_uint32 para)
{
    // Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_nightmode
*
* DESCRIPTION
*	OV7680 night mode setting.
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
kal_uint32 set_OV7680_param_nightmode(kal_uint32 para)
{
	OV7680_night_mode((kal_bool)para);
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_OV7680_param_ev
*
* DESCRIPTION
*	OV7680 ev setting.
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
kal_uint32 set_OV7680_param_ev(kal_uint32 para)
{
	return set_OV7680_param_exposure(para);
}

/*************************************************************************
* FUNCTION
*	OV7680_yuv_sensor_setting
*
* DESCRIPTION
*	This function send command and parameter to yuv sensor module OV7680
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
kal_uint32 OV7680_yuv_sensor_setting(kal_uint32 cmd, kal_uint32 para)
{
	kal_uint32 ret = KAL_TRUE;
	switch (cmd)
	{
		case CAM_PARAM_ZOOM_FACTOR:
			ret = set_OV7680_param_zoom(para);		
			break;			
		case CAM_PARAM_CONTRAST:
			ret = set_OV7680_param_contrast(para);		
			break;					
		case CAM_PARAM_BRIGHTNESS:
			ret = set_OV7680_param_brightness(para);		
			break;							
		case CAM_PARAM_HUE:
			ret = set_OV7680_param_hue(para);		
			break;							
		case CAM_PARAM_GAMMA:
			ret = set_OV7680_param_gamma(para);		
			break;							
		case CAM_PARAM_WB:
			ret = set_OV7680_param_wb(para);		
			break;
		case CAM_PARAM_EXPOSURE:
			ret = set_OV7680_param_exposure(para);		
			break;							
		case CAM_PARAM_EFFECT:
			ret = set_OV7680_param_effect(para);
			break;		
		case CAM_PARAM_BANDING:
			ret = set_OV7680_param_banding(para);		
			break;		
		case CAM_PARAM_SATURATION:
			ret = set_OV7680_param_saturation(para);				
			break;						
		case CAM_PARAM_NIGHT_MODE:
			ret = set_OV7680_param_nightmode(para);				
			break;						
		case CAM_PARAM_EV_VALUE:
			ret = set_OV7680_param_ev(para);				
			break;				
		default:
			ret = KAL_FALSE;
	}
	return ret;
}

/*************************************************************************
* FUNCTION
*	image_sensor_func_OV7680
*
* DESCRIPTION
*	OV7680 Image Sensor functions struct.
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
image_sensor_func_struct image_sensor_func_OV7680=
{
	init_OV7680,
	get_OV7680_id,
	get_OV7680_size,
	get_OV7680_period,
	OV7680_preview,
	OV7680_capture,
	write_OV7680_reg,
	read_OV7680_reg,
	set_OV7680_shutter,
	OV7680_night_mode,
	power_off_OV7680,
	set_OV7680_gain,
	set_OV7680_flashlight,
	OV7680_yuv_sensor_setting
};	/* image_sensor_func_OV7680 */

// write camera_para to sensor register
void camera_para_to_sensor_OV7680(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_OV7680_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_OV7680_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=0; i<CCT_END_ADDR; i++)
	{
		write_OV7680_reg(camera_para.SENSOR.cct[i].addr, camera_para.SENSOR.cct[i].para);
	}
}

// update camera_para from sensor register
void sensor_to_camera_para_OV7680(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_OV7680_reg(camera_para.SENSOR.reg[i].addr);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_OV7680_reg(camera_para.SENSOR.reg[i].addr);
	}
}

//------------------------Engineer mode---------------------------------

void  get_sensor_group_count_OV7680(kal_int32* sensor_count_ptr)
{
   *sensor_count_ptr=GROUP_TOTAL_NUMS;
   
	return;
}

void get_sensor_group_info_OV7680(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
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

void get_sensor_item_info_OV7680(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr)
{
	kal_uint8 temp_reg;
	
	switch (group_idx)
	{
		case AWB_GAIN:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"AWB R Gain");
				  info_ptr->item_value=read_OV7680_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr);
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0xff;
				break; 
				case 1:
				  sprintf(info_ptr->item_name_ptr,"AWB B Gain");
				  info_ptr->item_value=read_OV7680_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr);
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
				  
				  temp_reg = read_OV7680_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
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
				  
				  temp_reg = read_OV7680_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
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
				  
				  temp_reg = read_OV7680_gain();
				  
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
				  
				  temp_reg = read_OV7680_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
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
				  
				  temp_reg = read_OV7680_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
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

kal_bool set_sensor_item_info_OV7680(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
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
				  write_OV7680_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr,item_value);
				break;
				case 1:
				  camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].para = item_value;
				  write_OV7680_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr,item_value);
				break; 
				default:
				   ASSERT(0);
			}			
		break;
		case PRE_GAIN:
			switch (item_idx)
			{
				case 0:
				  temp_reg = read_OV7680_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
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
				  write_OV7680_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr,temp_reg);
				break;
				case 1:
				  temp_reg = read_OV7680_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
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
				  write_OV7680_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr,temp_reg);
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
				  write_OV7680_reg(camera_para.SENSOR.cct[GLOBAL_GAIN_INDEX].addr,temp_reg);
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
				      temp_reg = read_OV7680_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg |= 0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_OV7680_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
				  }
				  else
				  {
				      temp_reg = read_OV7680_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg &= ~0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_OV7680_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
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
				  temp_reg = read_OV7680_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
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
				  write_OV7680_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr,temp_reg);
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
				  write_OV7680_reg(FAC_SENSOR_REG,item_value);
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

kal_bool is_sensor_ready_OV7680()
{
	kal_sleep_task(4);
	write_cmos_sensor(0x12,0x80);
	kal_sleep_task(2);
	sensor_id=(read_cmos_sensor(0x0A)<<8)|read_cmos_sensor(0x0B);	

#ifdef NOKE_DEBUG
	noke_dbg_printf("\r CAMERA : is_sensor_ready_OV7680 : sensor_id = 0x%04x \n", sensor_id);
#endif
	
	if( OV7680_SENSOR_ID == sensor_id )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*

    以下是主摄像头的初始化函数， 不同厂家的不一样。

*/

void main_camera_ov7680_init_func_default(void)
{
	kal_uint8 temp;

	write_cmos_sensor(0x14, 0xc2);//0xc2
	write_cmos_sensor(0x63, 0x0b);
	write_cmos_sensor(0x64, 0x01);
	write_cmos_sensor(0x65, 0x0c);
	write_cmos_sensor(0x12, 0x01);
	write_cmos_sensor(0x0c, 0x06);
	write_cmos_sensor(0x82, 0x9a);
	write_cmos_sensor(0x22, 0x40);
	write_cmos_sensor(0x23, 0x20);
	write_cmos_sensor(0x31, 0x11);
	write_cmos_sensor(0x40, 0x10);
	write_cmos_sensor(0x4a, 0x42);
	write_cmos_sensor(0x4b, 0x64);
	write_cmos_sensor(0x67, 0x50);
	write_cmos_sensor(0x6b, 0x00);
	write_cmos_sensor(0x6c, 0x00);
	write_cmos_sensor(0x6d, 0x00);
	write_cmos_sensor(0x6e, 0x00);
	write_cmos_sensor(0x42, 0x4a);
	write_cmos_sensor(0x45, 0x40);
	write_cmos_sensor(0x3f, 0x46);
	write_cmos_sensor(0x48, 0x20);
	write_cmos_sensor(0x65, 0x8c);
	write_cmos_sensor(0x66, 0x02);
	write_cmos_sensor(0x67, 0x5c);
	write_cmos_sensor(0x12, 0x00);
	write_cmos_sensor(0x0c, 0x16);
	write_cmos_sensor(0x82, 0x9c);
	write_cmos_sensor(0x3e, 0x30);
	write_cmos_sensor(0x81, 0x07);
	write_cmos_sensor(0x8F, 0x54);
	write_cmos_sensor(0x90, 0x69);
	write_cmos_sensor(0x91, 0x0F);
	write_cmos_sensor(0x92, 0x99);
	write_cmos_sensor(0x93, 0x98);
	write_cmos_sensor(0x94, 0x0F);
	write_cmos_sensor(0x95, 0x0F);
	write_cmos_sensor(0x96, 0xFF);
	write_cmos_sensor(0x97, 0x00);
	write_cmos_sensor(0x98, 0x10);
	write_cmos_sensor(0x99, 0x20);
	write_cmos_sensor(0xb7, 0x90);
	write_cmos_sensor(0xb8, 0x8d);
	write_cmos_sensor(0xb9, 0x03);
	write_cmos_sensor(0xba, 0x2b);
	write_cmos_sensor(0xbb, 0x74);
	write_cmos_sensor(0xbc, 0x9f);
	write_cmos_sensor(0xbd, 0x5e);
	write_cmos_sensor(0xbe, 0x98);
	write_cmos_sensor(0xbf, 0x98);
	write_cmos_sensor(0xc0, 0x00);
	write_cmos_sensor(0xc1, 0x28);
	write_cmos_sensor(0xc2, 0x70);
	write_cmos_sensor(0xc3, 0x98);
	write_cmos_sensor(0xc4, 0x1a);
	write_cmos_sensor(0xa0,0x0e);
	write_cmos_sensor(0xa1 ,0x1a);
	write_cmos_sensor(0xa2  ,0x31);
	write_cmos_sensor(0xa3 ,0x5a);
	write_cmos_sensor(0xa4         ,0x69);
	write_cmos_sensor(0xa5         ,0x75);
	write_cmos_sensor(0xa6         ,0x82);
	write_cmos_sensor(0xa7         ,0x8d);
	write_cmos_sensor(0xa8         ,0x98);
	write_cmos_sensor(0xa9         ,0xa0);
	write_cmos_sensor(0xaa         ,0xae);
	write_cmos_sensor(0xab         ,0xba);
	write_cmos_sensor(0xac         ,0xcd);
	write_cmos_sensor(0xad         ,0xdd);
	write_cmos_sensor(0xae         ,0xec);
	write_cmos_sensor(0xaf ,0x20);
	write_cmos_sensor(0x31, 0x01);
	write_cmos_sensor(0x38, 0x04);
	write_cmos_sensor(0x34, 0x60);
	write_cmos_sensor(0x36, 0x40);
	write_cmos_sensor(0x37, 0x3b);
	write_cmos_sensor(0x89, 0x5c);
	write_cmos_sensor(0x8a, 0x11);
	write_cmos_sensor(0x8b, 0x12);
	write_cmos_sensor(0x8d, 0x50);
	write_cmos_sensor(0x96, 0xff);
	write_cmos_sensor(0x97, 0x00);
	write_cmos_sensor(0xb2, 0x06);
	write_cmos_sensor(0xb3, 0x03);
	write_cmos_sensor(0xb4, 0x03);
	write_cmos_sensor(0xb5, 0x03);
	write_cmos_sensor(0xb6, 0x03);
	write_cmos_sensor(0xd5, 0x02);
	write_cmos_sensor(0xdb, 0x40);
	write_cmos_sensor(0xdc, 0x40);
	write_cmos_sensor(0x24, 0x78);//0x90 //ghw111
	write_cmos_sensor(0x25, 0x70);//0x78//ghw111
	write_cmos_sensor(0x26, 0xc3);//0xc3
	write_cmos_sensor(0x2d, 0xff);
	write_cmos_sensor(0x2e, 0x02);//x0x05
	write_cmos_sensor(0x14, 0xb1);//0xa1
	write_cmos_sensor(0x11, 0x01);
	write_cmos_sensor(0x15, 0x40);
	write_cmos_sensor(0x2d, 0x00);
	write_cmos_sensor(0x2e, 0x00);
	write_cmos_sensor(0x4f, 0x99);
	write_cmos_sensor(0x50, 0x7f);
	write_cmos_sensor(0x21, 0x23);
	write_cmos_sensor(0x1e, 0x91);
	write_cmos_sensor(0x14, 0x11);//;   C1;   c2
	write_cmos_sensor(0x15, 0x00);//;   c0;c0 for night mode  
	write_cmos_sensor(0x28, 0x40);
	write_cmos_sensor(0x63, 0x0b);
	write_cmos_sensor(0x64, 0x0f);
	write_cmos_sensor(0x65, 0x07);
	write_cmos_sensor(0x12, 0x00);//write_cmos_sensorwrite_cmos_sensor(0x12, 0x01);  --- yuv  hejc
	write_cmos_sensor(0x0c, 0x06);

	normal_gain = read_cmos_sensor(0x00);  
	sensor_gain_base = read_OV7680_gain();   
}

/*

    以下是副摄像头的初始化函数， 不同厂家的不一样。

*/
#if defined(DOUBLE_CAMERA_SUPPORT)
void sub_camera_ov7680_init_func_default(void)
{
	kal_uint8 temp;

	write_cmos_sensor(0x14, 0xc2);//0xc2
	write_cmos_sensor(0x63, 0x0b);
	write_cmos_sensor(0x64, 0x01);
	write_cmos_sensor(0x65, 0x0c);
	write_cmos_sensor(0x12, 0x01);
	write_cmos_sensor(0x0c, 0x06);
	write_cmos_sensor(0x82, 0x9a);
	write_cmos_sensor(0x22, 0x40);
	write_cmos_sensor(0x23, 0x20);
	write_cmos_sensor(0x31, 0x11);
	write_cmos_sensor(0x40, 0x10);
	write_cmos_sensor(0x4a, 0x42);
	write_cmos_sensor(0x4b, 0x64);
	write_cmos_sensor(0x67, 0x50);
	write_cmos_sensor(0x6b, 0x00);
	write_cmos_sensor(0x6c, 0x00);
	write_cmos_sensor(0x6d, 0x00);
	write_cmos_sensor(0x6e, 0x00);
	write_cmos_sensor(0x42, 0x4a);
	write_cmos_sensor(0x45, 0x40);
	write_cmos_sensor(0x3f, 0x46);
	write_cmos_sensor(0x48, 0x20);
	write_cmos_sensor(0x65, 0x8c);
	write_cmos_sensor(0x66, 0x02);
	write_cmos_sensor(0x67, 0x5c);
	write_cmos_sensor(0x12, 0x00);
	write_cmos_sensor(0x0c, 0x16);
	write_cmos_sensor(0x82, 0x9c);
	write_cmos_sensor(0x3e, 0x30);
	write_cmos_sensor(0x81, 0x07);
	write_cmos_sensor(0x8F, 0x54);
	write_cmos_sensor(0x90, 0x69);
	write_cmos_sensor(0x91, 0x0F);
	write_cmos_sensor(0x92, 0x99);
	write_cmos_sensor(0x93, 0x98);
	write_cmos_sensor(0x94, 0x0F);
	write_cmos_sensor(0x95, 0x0F);
	write_cmos_sensor(0x96, 0xFF);
	write_cmos_sensor(0x97, 0x00);
	write_cmos_sensor(0x98, 0x10);
	write_cmos_sensor(0x99, 0x20);
	write_cmos_sensor(0xb7, 0x90);
	write_cmos_sensor(0xb8, 0x8d);
	write_cmos_sensor(0xb9, 0x03);
	write_cmos_sensor(0xba, 0x2b);
	write_cmos_sensor(0xbb, 0x74);
	write_cmos_sensor(0xbc, 0x9f);
	write_cmos_sensor(0xbd, 0x5e);
	write_cmos_sensor(0xbe, 0x98);
	write_cmos_sensor(0xbf, 0x98);
	write_cmos_sensor(0xc0, 0x00);
	write_cmos_sensor(0xc1, 0x28);
	write_cmos_sensor(0xc2, 0x70);
	write_cmos_sensor(0xc3, 0x98);
	write_cmos_sensor(0xc4, 0x1a);
	write_cmos_sensor(0xa0,0x0e);
	write_cmos_sensor(0xa1 ,0x1a);
	write_cmos_sensor(0xa2  ,0x31);
	write_cmos_sensor(0xa3 ,0x5a);
	write_cmos_sensor(0xa4         ,0x69);
	write_cmos_sensor(0xa5         ,0x75);
	write_cmos_sensor(0xa6         ,0x82);
	write_cmos_sensor(0xa7         ,0x8d);
	write_cmos_sensor(0xa8         ,0x98);
	write_cmos_sensor(0xa9         ,0xa0);
	write_cmos_sensor(0xaa         ,0xae);
	write_cmos_sensor(0xab         ,0xba);
	write_cmos_sensor(0xac         ,0xcd);
	write_cmos_sensor(0xad         ,0xdd);
	write_cmos_sensor(0xae         ,0xec);
	write_cmos_sensor(0xaf ,0x20);
	write_cmos_sensor(0x31, 0x01);
	write_cmos_sensor(0x38, 0x04);
	write_cmos_sensor(0x34, 0x60);
	write_cmos_sensor(0x36, 0x40);
	write_cmos_sensor(0x37, 0x3b);
	write_cmos_sensor(0x89, 0x5c);
	write_cmos_sensor(0x8a, 0x11);
	write_cmos_sensor(0x8b, 0x12);
	write_cmos_sensor(0x8d, 0x50);
	write_cmos_sensor(0x96, 0xff);
	write_cmos_sensor(0x97, 0x00);
	write_cmos_sensor(0xb2, 0x06);
	write_cmos_sensor(0xb3, 0x03);
	write_cmos_sensor(0xb4, 0x03);
	write_cmos_sensor(0xb5, 0x03);
	write_cmos_sensor(0xb6, 0x03);
	write_cmos_sensor(0xd5, 0x02);
	write_cmos_sensor(0xdb, 0x40);
	write_cmos_sensor(0xdc, 0x40);
	write_cmos_sensor(0x24, 0x78);//0x90 //ghw111
	write_cmos_sensor(0x25, 0x70);//0x78//ghw111
	write_cmos_sensor(0x26, 0xc3);//0xc3
	write_cmos_sensor(0x2d, 0xff);
	write_cmos_sensor(0x2e, 0x02);//x0x05
	write_cmos_sensor(0x14, 0xb1);//0xa1
	write_cmos_sensor(0x11, 0x01);
	write_cmos_sensor(0x15, 0x40);
	write_cmos_sensor(0x2d, 0x00);
	write_cmos_sensor(0x2e, 0x00);
	write_cmos_sensor(0x4f, 0x99);
	write_cmos_sensor(0x50, 0x7f);
	write_cmos_sensor(0x21, 0x23);
	write_cmos_sensor(0x1e, 0x91);
	write_cmos_sensor(0x14, 0x11);//;   C1;   c2
	write_cmos_sensor(0x15, 0x00);//;   c0;c0 for night mode  
	write_cmos_sensor(0x28, 0x40);
	write_cmos_sensor(0x63, 0x0b);
	write_cmos_sensor(0x64, 0x0f);
	write_cmos_sensor(0x65, 0x07);
	write_cmos_sensor(0x12, 0x00);//write_cmos_sensorwrite_cmos_sensor(0x12, 0x01);  --- yuv  hejc
	write_cmos_sensor(0x0c, 0x06);

	normal_gain = read_cmos_sensor(0x00);  
	sensor_gain_base = read_OV7680_gain();   
}
#endif

