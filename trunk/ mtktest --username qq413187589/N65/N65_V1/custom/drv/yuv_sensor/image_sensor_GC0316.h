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

#define GC0316_WRITE_ID						    0x42
#define GC0316_READ_ID								0x43	
#define GC0316_SENSOR_ID							0x98	 

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

extern kal_bool gc_effect_on;
extern kal_bool gc_reinit;
kal_bool gc_EnterCarvingEffect = KAL_FALSE;

#ifdef DOUBLE_CAMERA_SUPPORT
extern kal_bool main_camera_is_ready;    
extern kal_bool sub_camera_is_ready  ;
extern kal_bool main_camera_active  ;
#ifndef WIN32
extern kal_bool mmi_polling_active_camera(void);
#endif
extern const char gpio_camera_reset_pin;
extern const char gpio_camera_cmpdn_pin;
extern const char gpio_camera_reset_pin_2;
extern const char gpio_camera_cmpdn_pin_2;
#define MODULE_RESET_PIN				      	 gpio_camera_reset_pin
#define MODULE_CMPDN_PIN					 gpio_camera_cmpdn_pin
#define MODULE_RESET_PIN_2				      	 gpio_camera_reset_pin_2
#define MODULE_CMPDN_PIN_2			         gpio_camera_cmpdn_pin_2 

#endif


void Delayms_GC0316(kal_uint32 ms)
{
      kal_uint32 delay;
      for (delay =0;delay <5000*ms;delay++) {}
}

void write_GC0316_shutter(kal_uint16 shutter)
{
	write_cmos_sensor(0x03, shutter/256);
	write_cmos_sensor(0x04, shutter & 0x00ff);
    
}	/* write_GC0316_shutter */
kal_uint16 read_GC0316_shutter(void)
{
	kal_uint16 shutter;
	shutter= (read_cmos_sensor(0x03)<<8 )|( read_cmos_sensor(0x04)&0xff);
	return shutter;	
}	/* read_GC0316_shutter */


void set_GC0316_dummy(kal_uint16 pixels, kal_uint16 lines)
{
	write_cmos_sensor(0x01,72+pixels);               //added by mengmei
   	write_cmos_sensor(0x02,34+lines);

}	/* set_GC0316_dummy */
/*************************************************************************
* FUNCTION
*	config_GC0316_window
*
* DESCRIPTION
*	This function config the hardware window of GC0316 for getting specified
*  data of that window.
*
* PARAMETERS
*	start_x : start column of the interested window
*  start_y : start row of the interested window
*  width  : column widht of the itnerested window
*  height : row depth of the itnerested window
*
* RETURNS
*	the data that read from GC0316
*
* GLOBALS AFFECTED
*
*************************************************************************/
void config_GC0316_window(kal_uint16 startx,kal_uint16 starty,kal_uint16 width, kal_uint16 height)
{

	
}	/* set_GC0316_dummy */



/*************************************************************************
* FUNCTION
*	init_OV76X0
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
kal_int8 init_GC0316(void)
{
	int idx;
	
	cis_module_power_on(KAL_TRUE);
	kal_sleep_task(2);
	camera_module_pin_set(SCCB_SERIAL_CLK_PIN, 1);
	camera_module_pin_set(SCCB_SERIAL_DATA_PIN, 1);
	kal_sleep_task(2);

	SET_CMOS_CLOCK_POLARITY_LOW;
	SET_VSYNC_POLARITY_LOW;
	SET_HSYNC_POLARITY_LOW;  

	ENABLE_CAMERA_INDATA_FORMAT;
	SET_CAMERA_INPUT_TYPE(INPUT_YUV422);
	SET_CAMERA_INPUT_ORDER(INPUT_ORDER_YCbY1Cr);
	
	ENABLE_CAMERA_TG_CLK_48M;
	UPLL_Enable(UPLL_OWNER_ISP);    
	set_isp_driving_current(ISP_DRIVING_8MA);


	REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;
	kal_sleep_task(2);	
	REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;
	kal_sleep_task(2);
	REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;

#ifdef DOUBLE_CAMERA_SUPPORT 
	main_camera_is_ready = image_sensor_is_main_camera_ready();
	sub_camera_is_ready = image_sensor_is_sub_camera_ready();

	// camera reset
	REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;
	kal_sleep_task(2);	
	REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;
	kal_sleep_task(2);
	REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;
	
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
*	power_off_GC0316
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

void power_off_GC0316(void)
{
	//POWER_OFF_MODULE;
	cis_module_power_on(KAL_FALSE);
	#ifndef HW_SCCB
	   SET_SCCB_CLK_LOW;
	   SET_SCCB_DATA_LOW;
	#endif
}	/* power_off_GC0316 */

/*************************************************************************
* FUNCTION
*	get_GC0316_id
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
void get_GC0316_id(kal_uint8 *sensor_write_id, kal_uint8 *sensor_read_id)
{
	*sensor_write_id=GC0316_WRITE_ID;
	*sensor_read_id=GC0316_READ_ID;
	
}	/* get_GC0316_id */

/*************************************************************************
* FUNCTION
*	get_GC0316_size
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
void get_GC0316_size(kal_uint16 *sensor_width, kal_uint16 *sensor_height)
{
	*sensor_width=IMAGE_SENSOR_VGA_WIDTH;		/* pixel numbers actually used in one frame */
	*sensor_height=IMAGE_SENSOR_VGA_HEIGHT;	      /* line numbers actually used in one frame */
}	/* get_GC0316_size */

/*************************************************************************
* FUNCTION
*	get_GC0316_period
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
void get_GC0316_period(kal_uint16 *pixel_number, kal_uint16 *line_number)
{
	*pixel_number=VGA_PERIOD_PIXEL_NUMS;		/* pixel numbers in one period of HSYNC */
	*line_number=VGA_PERIOD_LINE_NUMS;			/* line numbers in one period of VSYNC */
}	/* get_GC0316_period */

void GC0316_preview(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	volatile kal_uint32 CISCTL_mode =read_cmos_sensor(0x0f); //read mirror,upsidedown
	volatile kal_uint32 updown_mirror=(CISCTL_mode&0x30);
	
	kal_uint16 current_shutter;
noke_dbg_printf("Hongzhe.Liu : GC0316_preview ");
	sensor_cap_state=KAL_FALSE;

	g_bMJPEG_mode = KAL_FALSE;

    // 1. GC0306's clock control register causes sensor output some abnormal frame even if
    // it is written with the same value twice
    // 2. MJPEG preview/capture use the same clock divider, no need to update for
    // MJPEG encode mode
 //   if (sensor_config_data->isp_op_mode != ISP_MJPEG_ENCODE_MODE) {
        //write_cmos_sensor(0x11,0x80);	//MCLK = PCLK
//	}

	if((sensor_config_data->isp_op_mode==ISP_MJPEG_PREVIEW_MODE)||
		(sensor_config_data->isp_op_mode==ISP_MJPEG_ENCODE_MODE))  //// MPEG4 Encode Mode
	{
			MPEG4_encode_mode=KAL_FALSE;
			g_bMJPEG_mode = KAL_TRUE;

			write_cmos_sensor(0x01,0x9a); 
			write_cmos_sensor(0x02,0x20); 
			write_cmos_sensor(0xd6,0x41);
			write_cmos_sensor(0x28, 0x02); //                                                                                                                                                                                                                                                                    
			write_cmos_sensor(0x29, 0x49);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2a, 0x02); //exp_level_1, 14fps                                                                                                                                                                                                                                                  
			write_cmos_sensor(0x2b, 0x49);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2c, 0x09); //exp_level_2 , 7c4~7FPS, 58c~10FPS, 6a8~8.2FPS                                                                                                                                                                                                                       
			write_cmos_sensor(0x2d, 0xa6);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2e, 0x09); //exp_level_3                                                                                                                                                                                                                                                         
			write_cmos_sensor(0x2f, 0xa6); 					

			/* config TG of ISP to match the setting of image sensor*/
			SET_TG_OUTPUT_CLK_DIVIDER(3);			//10fps
			SET_CMOS_RISING_EDGE(0);
			SET_CMOS_FALLING_EDGE(2);
			ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
			SET_TG_PIXEL_CLK_DIVIDER(3);
			SET_CMOS_DATA_LATCH(2);
			//write_cmos_sensor(0xd8	,0x4	);  

			w_blank=160;
			h_blank=120;
			dummy_pixels=0;
	    		dummy_lines=255;	


	}
	else if(sensor_config_data->frame_rate==0x0F)		// MPEG4 Encode Mode
	    {
		    	MPEG4_encode_mode=KAL_TRUE;
			g_bMJPEG_mode = KAL_TRUE;
			write_cmos_sensor(0x01,0x9a); 
			write_cmos_sensor(0x02,0x22); 
			write_cmos_sensor(0xd6,0x41);
			write_cmos_sensor(0x28, 0x02); //                                                                                                                                                                                                                                                                    
			write_cmos_sensor(0x29, 0x49);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2a, 0x02); //exp_level_1, 14fps                                                                                                                                                                                                                                                  
			write_cmos_sensor(0x2b, 0x49);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2c, 0x09); //exp_level_2 , 7c4~7FPS, 58c~10FPS, 6a8~8.2FPS                                                                                                                                                                                                                       
			write_cmos_sensor(0x2d, 0xa6);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2e, 0x09); //exp_level_3                                                                                                                                                                                                                                                         
			write_cmos_sensor(0x2f, 0xa6); 					
			
		
		    /* config TG of ISP to match the setting of image sensor*/
			SET_TG_OUTPUT_CLK_DIVIDER(3);
	    		SET_CMOS_RISING_EDGE(0);
    			SET_CMOS_FALLING_EDGE(2);
			ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
		    	SET_TG_PIXEL_CLK_DIVIDER(3);
    			SET_CMOS_DATA_LATCH(2);

			w_blank=160;
			h_blank=120;

    			dummy_pixels=0;
		    	dummy_lines=20;
	    }
	    else
	    {
		    MPEG4_encode_mode=KAL_FALSE;

			write_cmos_sensor(0x01,0x8c); 
			write_cmos_sensor(0x02,0x28); 
			write_cmos_sensor(0xd6,0x58);
			write_cmos_sensor(0x28, 0x03); //                                                                                                                                                                                                                                                                    
			write_cmos_sensor(0x29, 0x18);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2a, 0x03); //exp_level_1, 14fps                                                                                                                                                                                                                                                  
			write_cmos_sensor(0x2b, 0x18);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2c, 0x09); //exp_level_2 , 7c4~7FPS, 58c~10FPS, 6a8~8.2FPS                                                                                                                                                                                                                       
			write_cmos_sensor(0x2d, 0xa0);                                                                                                                                                                                                                                                                       
			write_cmos_sensor(0x2e, 0x09); //exp_level_3                                                                                                                                                                                                                                                         
			write_cmos_sensor(0x2f, 0xa0);    					
	
		    /* config TG of ISP to match the setting of image sensor*/
		    SET_TG_OUTPUT_CLK_DIVIDER(2);	
		    SET_CMOS_RISING_EDGE(0);
		    SET_CMOS_FALLING_EDGE(1);  
		   ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
		   //DISABLE_CAMERA_PIXEL_CLKIN_ENABLE;		    
		    SET_TG_PIXEL_CLK_DIVIDER(2);
		    SET_CMOS_DATA_LATCH(1);


				w_blank=0;
				h_blank=4;

        dummy_pixels=0;
        dummy_lines=0;  
	    }
	 
	preview_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;

#if 0	// set updown mirror
	switch (sensor_config_data->image_mirror)
	{
		case IMAGE_NORMAL:
			write_cmos_sensor(0x0f, 0x30);
			write_cmos_sensor(0x45, 0x25);

        break;

    case IMAGE_H_MIRROR:
			write_cmos_sensor(0x0f, 0x20);
			write_cmos_sensor(0x45, 0x24);

        break;

    case IMAGE_V_MIRROR:
			write_cmos_sensor(0x0f, 0x10);
			write_cmos_sensor(0x45, 0x27);

        break;

    case IMAGE_HV_MIRROR:
			write_cmos_sensor(0x0f, 0x00);
			write_cmos_sensor(0x45, 0x26);

		break;
	}
#endif

	image_window->grab_start_x=8;////IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	image_window->grab_start_y=4;//IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines;
	
	#if 0
	image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
	image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT-4;
	#else
	image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH-w_blank;
	image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT-h_blank;
	#endif
	
	kal_sleep_task(10);		
}	/* GC0316_preview */
void GC0316_capture(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
    volatile kal_uint32 shutter=exposure_lines;
    kal_uint8 temp_reg;
    
    sensor_cap_state=KAL_TRUE;
	
	if(MPEG4_encode_mode)
	    ASSERT(0);
	
	//if(sensor_config_data->enable_shutter_tansfer==KAL_TRUE)
		//shutter=sensor_config_data->capture_shutter;
		
	#ifdef OUTPUT_DEBUG_INFO
	sprintf(temp_buffer, "Begin of GC0316_capture");
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	sprintf(temp_buffer, "cap_shutter:%d, pre_shut:%d", shutter, exposure_lines);
	rmmi_write_to_uart((kal_uint8*) temp_buffer, strlen(temp_buffer), KAL_TRUE);
	#endif

    if(!(sensor_config_data->frame_rate==0xF0))	// If not WEBCAM mode.
    {        
	// turn off night mode
                
    }
    	
	if ((image_window->image_target_width<=IMAGE_SENSOR_1M_WIDTH)&&
		(image_window->image_target_height<=IMAGE_SENSOR_1M_HEIGHT))
	{	/* Less than VGA Mode */
		if (image_window->digital_zoom_factor>=(ISP_DIGITAL_ZOOM_INTERVAL<<1))
		{
			
			SET_TG_PIXEL_CLK_DIVIDER(7);
			SET_CMOS_DATA_LATCH(4);
			
			if ((image_window->image_target_width==IMAGE_SENSOR_1M_WIDTH)&&
				(image_window->image_target_height==IMAGE_SENSOR_1M_HEIGHT))
			//	dummy_pixels=2000;
				dummy_pixels=0;
			else
				dummy_pixels=VGA_PERIOD_PIXEL_NUMS/4;
			dummy_lines=0;
		}
		else
		{
			if(sensor_config_data->frame_rate==0xF0)	// That means WEBCAM mode.
			{
			    SET_TG_OUTPUT_CLK_DIVIDER(1);	
		        SET_CMOS_RISING_EDGE(0);
		        SET_CMOS_FALLING_EDGE(1);
		        ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
				SET_TG_PIXEL_CLK_DIVIDER(1);
				SET_CMOS_DATA_LATCH(1);

				write_cmos_sensor(0xd8	,0x02); 
				
				start_grab_x_offset=0;
				start_grab_y_offset=0;
				
				dummy_pixels=0;
				dummy_lines=0;
			}
			else
			{

				if ((image_window->image_target_width==IMAGE_SENSOR_1M_WIDTH)&&
				(image_window->image_target_height==IMAGE_SENSOR_1M_HEIGHT))
				{
					SET_TG_OUTPUT_CLK_DIVIDER(7);	
		            SET_CMOS_RISING_EDGE(0);
		            SET_CMOS_FALLING_EDGE(5);
					ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
					SET_TG_PIXEL_CLK_DIVIDER(7);
					SET_CMOS_DATA_LATCH(5);
					shutter=read_GC0316_shutter();  
					shutter = shutter/4;
					write_GC0316_shutter(shutter);   

				}
			 
			else
			{
			    		SET_TG_OUTPUT_CLK_DIVIDER(2);	
		      			SET_CMOS_RISING_EDGE(0);
		      			SET_CMOS_FALLING_EDGE(1);
		      			ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
					SET_TG_PIXEL_CLK_DIVIDER(2);
					SET_CMOS_DATA_LATCH(1);

					shutter=read_GC0316_shutter();  
					//shutter = shutter/2;
					kal_prompt_trace(MOD_MMI,"third, shutter=%d " ,shutter);
					write_GC0316_shutter(shutter);  

				}	
				dummy_lines=0;
			}
		}
		
		capture_pclk_division=((DRV_Reg32(ISP_TG_PHASE_COUNTER_REG)&0xF0)>>4)+1;

		//shutter=read_GC0316_shutter();  //william 20070613
		//shutter=(shutter*preview_pclk_division)/capture_pclk_division;
		//shutter=(shutter*VGA_PERIOD_PIXEL_NUMS)/(VGA_PERIOD_PIXEL_NUMS+dummy_pixels);

		image_window->grab_start_x=8;  //IMAGE_SENSOR_VGA_INSERTED_PIXELS;
		image_window->grab_start_y=4;  //IMAGE_SENSOR_VGA_INSERTED_LINES+dummy_lines;
		image_window->exposure_window_width=IMAGE_SENSOR_VGA_WIDTH;
		image_window->exposure_window_height=IMAGE_SENSOR_VGA_HEIGHT-4 ; // minus 1 to avoid the last black line
	}
	
}	/* GC0316_capture() */

/*************************************************************************
* FUNCTION
*	write_GC0316_reg
*
* DESCRIPTION
*	This function set the register of GC0316.
*
* PARAMETERS
*	addr : the register index of GC0316
*  para : setting parameter of the specified register of GC0316
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void write_GC0316_reg(kal_uint32 addr, kal_uint32 para)
{
	//write_cmos_sensor(addr,para);
}	/* write_GC0316_reg() */

/*************************************************************************
* FUNCTION
*	read_cmos_sensor
*
* DESCRIPTION
*	This function read parameter of specified register from GC0316.
*
* PARAMETERS
*	addr : the register index of GC0316
*
* RETURNS
*	the data that read from GC0316
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 read_GC0316_reg(kal_uint32 addr)
{

	return (read_cmos_sensor(addr));		
}	/* read_GC0316_reg() */

/*************************************************************************
* FUNCTION
*	set_GC0316_shutter
*
* DESCRIPTION
*	This function set e-shutter of GC0316 to change exposure time.
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
void set_GC0316_shutter(kal_uint16 shutter)
{
	exposure_lines=shutter;
	//write_GC0316_shutter(shutter);
}	/* set_GC0316_shutter */

/*************************************************************************
* FUNCTION
*	set_GC0316_gain
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
kal_uint16 set_GC0316_gain(kal_uint16 gain)
{


}

/*************************************************************************
* FUNCTION
*	GC0316_night_mode
*
* DESCRIPTION
*	This function night mode of GC0316.
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
void GC0316_night_mode(kal_bool enable)
{

	kal_uint8  temp_reg;
	Delayms_GC0316(100);    //daemon 2008-3-27	
	temp_reg=read_cmos_sensor(0x41);
		
  	if(enable)
	{
		MAX_EXPOSURE_LINES=2*(PIXEL_CLK/MIN_FRAME_RATE)/VGA_PERIOD_PIXEL_NUMS;

		sensor_night_mode=KAL_TRUE;
		write_cmos_sensor(	0x19	,	0x33	);
		write_cmos_sensor(	0x1a	,	0x33	);
		
		write_cmos_sensor(	0x8d	,	0x13	);
		write_cmos_sensor(	0xdd	,	0x30	);
//		write_cmos_sensor( 0x41  , temp_reg & 0xdf);   // CLOSE ABS	
//		Delayms_GC0316(100);
//		write_cmos_sensor(	0xb0	,	0xf0	);
		write_cmos_sensor(	0x82	,	0x11	);		
		write_cmos_sensor(	0x87	,	0x91	);
		write_cmos_sensor(	0x88	,	0x10	);
		write_cmos_sensor(	0x89	,	0x08	);		


	}
	else
  	{
		MAX_EXPOSURE_LINES=(PIXEL_CLK/MIN_FRAME_RATE)/VGA_PERIOD_PIXEL_NUMS;

		sensor_night_mode=KAL_FALSE;
/*		if(gc_EnterCarvingEffect)
		{
			write_cmos_sensor(	0x8d	,	0xff	);
			write_cmos_sensor( 0x41  , 0x00);   // CLOSE ABS
		}
		else
		{
			write_cmos_sensor(	0x8d	,	0x23	);
			write_cmos_sensor( 0x41  , temp_reg | 0x20);   // Enable ABS
		}*/
		write_cmos_sensor(	0x19	,	0x00	);
		write_cmos_sensor(	0x1a	,	0x00	);

		write_cmos_sensor(	0xdd	,	0x10	);
		
		write_cmos_sensor(	0x82	,	0x34	);		
		write_cmos_sensor(	0x87	,	0x93	);
		write_cmos_sensor(	0x88	,	0x0a	);
		write_cmos_sensor(	0x89	,	0x4	);

		

	}

	Delayms_GC0316(100);
	if(camera_oper_data.pregain_mode==ISP_ONLY)
	    sensor_gain_base=BASEGAIN;
}
/*************************************************************************
* FUNCTION
*	set_GC0316_flashlight
*
* DESCRIPTION
*	turn on/off GC0316 flashlight .
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
void set_GC0316_flashlight(kal_bool enable)
{
	// Todo
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_zoom
*
* DESCRIPTION
*	GC0316 zoom setting.
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
kal_uint32 set_GC0316_param_zoom(kal_uint32 para)
{
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_contrast
*
* DESCRIPTION
*	GC0316 contrast setting.
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
kal_uint32 set_GC0316_param_contrast(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_brightness
*
* DESCRIPTION
*	GC0316 brightness setting.
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
kal_uint32 set_GC0316_param_brightness(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_hue
*
* DESCRIPTION
*	GC0316 hue setting.
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
kal_uint32 set_GC0316_param_hue(kal_uint32 para)
{
	// Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_gamma
*
* DESCRIPTION
*	GC0316 gamma setting.
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
kal_uint32 set_GC0316_param_gamma(kal_uint32 para)
{
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_wb
*
* DESCRIPTION
*	GC0316 wb setting.
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
kal_uint32 set_GC0316_param_wb(kal_uint32 para)
{
//	kal_uint16 rgain=0x80, ggain=0x80, bgain=0x80;
	kal_uint8  temp_reg;
	
	temp_reg=read_cmos_sensor(0x41);
	kal_prompt_trace(MOD_MMI,"Enter set_GC0306_param_wb - 0x41 = %x",temp_reg );

	if(gc_effect_on)
		return KAL_TRUE;

	switch (para)
	{
		case CAM_WB_AUTO:
			write_cmos_sensor(0x41,temp_reg|0x04);   // Enable AWB
			break;	
      
		case CAM_WB_CLOUD:
			write_cmos_sensor(0x41,temp_reg&~0x04);   // Enable AWB	
			write_cmos_sensor(0xc7,0x68); //WB_manual_gain
			write_cmos_sensor(0xc8,0x40);
			write_cmos_sensor(0xc9,0x50);
			break;		

		case CAM_WB_DAYLIGHT:
			write_cmos_sensor(0x41,temp_reg&~0x04);   // Enable AWB	
			write_cmos_sensor(0xc7,0x60);
			write_cmos_sensor(0xc8,0x40);
			write_cmos_sensor(0xc9,0x50);
			break;		

		case CAM_WB_INCANDESCENCE:
			write_cmos_sensor(0x41,temp_reg&~0x04);   // Enable AWB	
			write_cmos_sensor(0xc7,0x60);
			write_cmos_sensor(0xc8,0x40);
			write_cmos_sensor(0xc9,0x80);
			break;		

		case CAM_WB_FLUORESCENT:
			write_cmos_sensor(0x41,temp_reg&~0x04);   // Enable AWB	
			write_cmos_sensor(0xc7,0x50);
			write_cmos_sensor(0xc8,0x40);
			write_cmos_sensor(0xc9,0x70);
			break;		

		case CAM_WB_TUNGSTEN:
			write_cmos_sensor(0x41,temp_reg&~0x04);   // Enable AWB	
			write_cmos_sensor(0xc7,0x60);
			write_cmos_sensor(0xc8,0x52);
			write_cmos_sensor(0xc9,0x90);
			break;

		case CAM_WB_MANUAL:		
		    // TODO
			break;		

		default:
			return KAL_FALSE;			
	}	
	
	kal_sleep_task(20);
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_exposure
*
* DESCRIPTION
*	GC0316 exposure setting.
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
kal_uint32 set_GC0316_param_exposure(kal_uint32 para)
{

	switch (para)
	{
		case CAM_EV_NEG_4_3:    
            write_cmos_sensor(0x7a, 0xc0);		
			break;		
		case CAM_EV_NEG_3_3:
            write_cmos_sensor(0x7a, 0xd0);
			break;		
		case CAM_EV_NEG_2_3:
            write_cmos_sensor(0x7a, 0xe0);
			break;				
		case CAM_EV_NEG_1_3:
            write_cmos_sensor(0x7a, 0xf0);
			break;				
		case CAM_EV_ZERO:
            write_cmos_sensor(0x7a, 0x00);
			break;				
		case CAM_EV_POS_1_3:
            write_cmos_sensor(0x7a, 0x20);
			break;				
		case CAM_EV_POS_2_3:
            write_cmos_sensor(0x7a, 0x30);
			break;				
		case CAM_EV_POS_3_3:
            write_cmos_sensor(0x7a, 0x40);
			break;				
		case CAM_EV_POS_4_3:	
            write_cmos_sensor(0x7a, 0x50);
			break;
		default:
			return KAL_FALSE;    
	}			

	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_effect
*
* DESCRIPTION
*	GC0316 effect setting.
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
kal_uint32 set_GC0316_param_effect(kal_uint32 para)
{
    	kal_uint32  ret = KAL_TRUE;
   
			switch (para)
			{	
				case CAM_EFFECT_ENC_NORMAL:
					write_cmos_sensor(0x47,0x00);
					write_cmos_sensor(0x78,0x00);
					write_cmos_sensor(0x79,0x00);
					write_cmos_sensor(0x41,0x2f);
					
					write_cmos_sensor(0x40,0x7e);
			
					write_cmos_sensor(0x42,0x30);
					write_cmos_sensor(0x8b,0x0a);
					write_cmos_sensor(0x8c,0x10);
					write_cmos_sensor(0x8d,0x23);

					write_cmos_sensor(0xa0,0x50);
					//write_cmos_sensor(0xa1,0x40);
							write_cmos_sensor(0xa1,0x4c);

					gc_effect_on = KAL_FALSE;
					gc_EnterCarvingEffect = KAL_FALSE;
					break;		
				case CAM_EFFECT_ENC_GRAYSCALE:
					write_cmos_sensor(0x47,0x10);
					write_cmos_sensor(0x78,0x00);
					write_cmos_sensor(0x79,0x00);
					write_cmos_sensor(0x41,0x2f);

					write_cmos_sensor(0x40,0x7e);
			
					write_cmos_sensor(0x42,0x30);
					write_cmos_sensor(0x8b,0x0a);
					write_cmos_sensor(0x8c,0x10);
					write_cmos_sensor(0x8d,0x23);
			
					write_cmos_sensor(0xa0,0x48);
					write_cmos_sensor(0xa1,0x40);					
					gc_effect_on = KAL_TRUE;	
					gc_EnterCarvingEffect = KAL_FALSE;
					break;		
				case CAM_EFFECT_ENC_SEPIA:
					write_cmos_sensor(0x47,0x10);
					write_cmos_sensor(0x78,0xc0);
					write_cmos_sensor(0x79,0x10);  //20
					write_cmos_sensor(0x41,0x2f);

					write_cmos_sensor(0x40,0x7e);
			
					write_cmos_sensor(0x42,0x30);
					write_cmos_sensor(0x8b,0x0a);
					write_cmos_sensor(0x8c,0x10);
					write_cmos_sensor(0x8d,0x23);
			
					write_cmos_sensor(0xb0,0x00);
					write_cmos_sensor(0xa0,0x48);
					write_cmos_sensor(0xa1,0x40);					
					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_FALSE;
					break;		
				case CAM_EFFECT_ENC_COLORINV:
					write_cmos_sensor(0x47,0x00);
					write_cmos_sensor(0x78,0x00);
					write_cmos_sensor(0x79,0x00);
					write_cmos_sensor(0x41,0x40);

					write_cmos_sensor(0x40,0x7e);
			
					write_cmos_sensor(0x42,0x30);
					write_cmos_sensor(0x8b,0x0a);
					write_cmos_sensor(0x8c,0x10);
					write_cmos_sensor(0x8d,0x23);
            
					write_cmos_sensor(0xb0,0x00);
					write_cmos_sensor(0xa0,0x48);
					write_cmos_sensor(0xa1,0x40);					
					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_FALSE;
					
					break;		
				case CAM_EFFECT_ENC_SEPIAGREEN:
					write_cmos_sensor(0x47,0x10);
					write_cmos_sensor(0x78,0xe0);
					write_cmos_sensor(0x79,0xe0);
					write_cmos_sensor(0x41,0x2f);

					write_cmos_sensor(0x40,0x7e);
			
					write_cmos_sensor(0x42,0x30);
					write_cmos_sensor(0x8b,0x0a);
					write_cmos_sensor(0x8c,0x10);
					write_cmos_sensor(0x8d,0x23);
			
					write_cmos_sensor(0xb0,0x00);

					write_cmos_sensor(0xa0,0x50);
					write_cmos_sensor(0xa1,0x40);					
					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_FALSE;
					break;					
				case CAM_EFFECT_ENC_SEPIABLUE:
					write_cmos_sensor(0x47,0x10);
					write_cmos_sensor(0x78,0x20);
					write_cmos_sensor(0x79,0xc0);
					write_cmos_sensor(0x41,0x2f);

					write_cmos_sensor(0x40,0x7e);
			
					write_cmos_sensor(0x42,0x30);
					write_cmos_sensor(0x8b,0x0a);
					write_cmos_sensor(0x8c,0x10);
					write_cmos_sensor(0x8d,0x23);
			
					write_cmos_sensor(0xa0,0x48);
					write_cmos_sensor(0xa1,0x40);					
					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_FALSE;
					break;								
				/*case CAM_EFFECT_ENC_GRAYINV:
					write_cmos_sensor(0x3A,0x1C);		
					write_cmos_sensor(0x67,0x80);		
					write_cmos_sensor(0x68,0x80);
					write_cmos_sensor(0x56,0x40);						
					break;			*/					
				case CAM_EFFECT_ENC_COPPERCARVING:
					if(gc_reinit)  // is re-enter camera,wait AEC stable
					{
						kal_sleep_task(100);
						gc_reinit=KAL_FALSE;
					}									
					write_cmos_sensor(0x41,0x00);
					kal_sleep_task(40);				
					write_cmos_sensor(0x40,0x3c);
					write_cmos_sensor(0x42,0x34);
					kal_sleep_task(40);
					write_cmos_sensor(0xc7,0x20);
					write_cmos_sensor(0xc8,0x20);
					write_cmos_sensor(0xc9,0x20);					
					write_cmos_sensor(0x8b,0x3f);
					write_cmos_sensor(0x8c,0x00);
					write_cmos_sensor(0x8d,0xff);
				
					Delayms_GC0316(200);
					write_cmos_sensor(0xb0,0x00);

					write_cmos_sensor(0xa0,0x50);
					write_cmos_sensor(0xa1,0x50);

					write_cmos_sensor(0x47,0x10);
					write_cmos_sensor(0x78,0xe0);
					write_cmos_sensor(0x79,0x10);
					
					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_TRUE;

					break;								
			case CAM_EFFECT_ENC_BLUECARVING:
					if(gc_reinit)  // is re-enter camera,wait AEC stable
					{
						kal_sleep_task(100);
						gc_reinit=KAL_FALSE;
					}					
					write_cmos_sensor(0x41,0x00);
					kal_sleep_task(40);				
					write_cmos_sensor(0x40,0x3c);
					write_cmos_sensor(0x42,0x34);
					kal_sleep_task(40);
					write_cmos_sensor(0xc7,0x20);
					write_cmos_sensor(0xc8,0x20);
					write_cmos_sensor(0xc9,0x20);					
					write_cmos_sensor(0x8b,0x3f);
					write_cmos_sensor(0x8c,0x00);
					write_cmos_sensor(0x8d,0xff);
				
					Delayms_GC0316(200);
					write_cmos_sensor(0xb0,0x00);

					write_cmos_sensor(0xa0,0x50);
					write_cmos_sensor(0xa1,0x50);

					write_cmos_sensor(0x47,0x10);
					write_cmos_sensor(0x78,0x30);
					write_cmos_sensor(0x79,0x00);


					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_TRUE;

					break;								
				case CAM_EFFECT_ENC_CONTRAST:
					break;							
				case CAM_EFFECT_ENC_EMBOSSMENT:
					write_cmos_sensor(0x41,0x00);
					kal_sleep_task(40);				
					write_cmos_sensor(0x40,0x3c);
					write_cmos_sensor(0x42,0x34);
					kal_sleep_task(40);
					write_cmos_sensor(0xc7,0x20);
					write_cmos_sensor(0xc8,0x20);
					write_cmos_sensor(0xc9,0x20);					
					write_cmos_sensor(0x8b,0x3f);
					write_cmos_sensor(0x8c,0x00);
					write_cmos_sensor(0x8d,0xff);
				
					Delayms_GC0316(200);
					write_cmos_sensor(0xb0,0x00);

					write_cmos_sensor(0xa0,0x00);
					write_cmos_sensor(0xa1,0x50);

					write_cmos_sensor(0x47,0x00);
					write_cmos_sensor(0x78,0x00);
					write_cmos_sensor(0x79,0x00);

					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_TRUE;

					break;			
				case CAM_EFFECT_ENC_SKETCH: 		
				case CAM_EFFECT_ENC_BLACKBOARD:
					write_cmos_sensor(0x41,0x00);
					kal_sleep_task(40);				
					write_cmos_sensor(0x40,0x3c);
					write_cmos_sensor(0x42,0x34);
					kal_sleep_task(40);
					write_cmos_sensor(0xc7,0x10);
					write_cmos_sensor(0xc8,0x10);
					write_cmos_sensor(0xc9,0x10);					
					write_cmos_sensor(0x8b,0x3f);
					write_cmos_sensor(0x8c,0x00);
					write_cmos_sensor(0x8d,0xff);
				
					Delayms_GC0316(200);
					write_cmos_sensor(0xb0,0x00);

					write_cmos_sensor(0xa0,0x00);
					write_cmos_sensor(0xa1,0xf0);

					write_cmos_sensor(0x47,0x00);
					write_cmos_sensor(0x78,0x00);
					write_cmos_sensor(0x79,0x00);

					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_TRUE;

					break;		
				case CAM_EFFECT_ENC_WHITEBOARD:
					write_cmos_sensor(0x41,0x00);
					kal_sleep_task(40);				
					write_cmos_sensor(0x40,0x3c);
					write_cmos_sensor(0x42,0x34);
					kal_sleep_task(40);
					write_cmos_sensor(0xc7,0x20);
					write_cmos_sensor(0xc8,0x20);
					write_cmos_sensor(0xc9,0x20);					
					write_cmos_sensor(0x8b,0x3f);
					write_cmos_sensor(0x8c,0x00);
					write_cmos_sensor(0x8d,0xff);
				
					Delayms_GC0316(200);
					write_cmos_sensor(0xb0,0x00);

					write_cmos_sensor(0xa0,0x00);
					write_cmos_sensor(0xa1,0x70);

					write_cmos_sensor(0x47,0x00);
					write_cmos_sensor(0x78,0x00);
					write_cmos_sensor(0x79,0x00);

					gc_effect_on = KAL_TRUE;
					gc_EnterCarvingEffect = KAL_TRUE;

					break;			
				case CAM_EFFECT_ENC_JEAN:
				case CAM_EFFECT_ENC_OIL:			
				default:
					ret = KAL_FALSE;
			}
	Delayms_GC0316(100);	
	kal_sleep_task(20);
	return ret;
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_banding
*
* DESCRIPTION
*	GC0316 banding setting.
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
kal_uint32 set_GC0316_param_banding(kal_uint32 para)
{
	kal_uint8 banding;
	
	switch (para)
	{
		case CAM_BANDING_50HZ:
			if(g_bMJPEG_mode)   // MPEG mode , 12M
			{
				write_cmos_sensor(0x01,0x9a);
				write_cmos_sensor(0x02,0x20);
				write_cmos_sensor(0xd6,0x41);			
			}
			else   // 16M
			{
				write_cmos_sensor(0x01,0x8c);
				write_cmos_sensor(0x02,0x28);
				write_cmos_sensor(0xd6,0x58);
			}

			break;                        
		case CAM_BANDING_60HZ:
			if(g_bMJPEG_mode)   // MPEG mode , 12M
			{
				write_cmos_sensor(0x01,0x9D);  
				write_cmos_sensor(0x02,0x1e);  
				write_cmos_sensor(0xd6,0x36);			
			}
			else   // 16M
			{
				write_cmos_sensor(0x01,0x9d);
				write_cmos_sensor(0x02,0x1e);
				write_cmos_sensor(0xd6,0x48);  
			}

			break;
		default:
			return KAL_FALSE;		
	}	
	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_saturation
*
* DESCRIPTION
*	GC0316 SATURATION setting.
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
kal_uint32 set_GC0316_param_saturation(kal_uint32 para)
{
    // Not Support
	return KAL_FALSE;	
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_nightmode
*
* DESCRIPTION
*	GC0316 night mode setting.
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
kal_uint32 set_GC0316_param_nightmode(kal_uint32 para)
{
	GC0316_night_mode((kal_bool)para);
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_GC0316_param_ev
*
* DESCRIPTION
*	GC0316 ev setting.
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
kal_uint32 set_GC0316_param_ev(kal_uint32 para)
{
	return set_GC0316_param_exposure(para);
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	GC0316_yuv_sensor_setting
*
* DESCRIPTION
*	This function send command and parameter to yuv sensor module OV0306
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
kal_uint32 GC0316_yuv_sensor_setting(kal_uint32 cmd, kal_uint32 para)
{
	kal_uint32 ret = KAL_TRUE;
	switch (cmd)
	{
		case CAM_PARAM_ZOOM_FACTOR:
			ret = set_GC0316_param_zoom(para);		
			break;			
		case CAM_PARAM_CONTRAST:
			ret = set_GC0316_param_contrast(para);		
			break;					
		case CAM_PARAM_BRIGHTNESS:
			ret = set_GC0316_param_brightness(para);		
			break;							
		case CAM_PARAM_HUE:
			ret = set_GC0316_param_hue(para);		
			break;							
		case CAM_PARAM_GAMMA:
			ret = set_GC0316_param_gamma(para);		
			break;							
		//case CAM_PARAM_WB:
			//ret = set_GC0316_param_wb(para);		
			//break;
		case CAM_PARAM_EXPOSURE:
			ret = set_GC0316_param_exposure(para);		
			break;							
		case CAM_PARAM_EFFECT:
			ret = set_GC0316_param_effect(para);
			break;
		case CAM_PARAM_WB:                       
			ret = set_GC0316_param_wb(para);		
			break;
		case CAM_PARAM_BANDING:
			ret = set_GC0316_param_banding(para);		
			break;		
		case CAM_PARAM_SATURATION:
			ret = set_GC0316_param_saturation(para);				
			break;						
		case CAM_PARAM_NIGHT_MODE:
			ret = set_GC0316_param_nightmode(para);				
			break;						
		case CAM_PARAM_EV_VALUE:
			ret = set_GC0316_param_ev(para);				
			break;				
		default:
			ret = KAL_FALSE;
	}
	return ret;
}

/*************************************************************************
* FUNCTION
*	image_sensor_func_OV0306
*
* DESCRIPTION
*	OV0306 Image Sensor functions struct.
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
image_sensor_func_struct image_sensor_func_GC0316=
{
	init_GC0316,
	get_GC0316_id,
	get_GC0316_size,
	get_GC0316_period,
	GC0316_preview,
	GC0316_capture,
	write_GC0316_reg,
	read_GC0316_reg,
	set_GC0316_shutter,
	GC0316_night_mode,
	power_off_GC0316,
	set_GC0316_gain,
	set_GC0316_flashlight,
	GC0316_yuv_sensor_setting
};	/* image_sensor_func_GC0316 */




// write camera_para to sensor register
void camera_para_to_sensor_GC0316(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_GC0316_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		write_GC0316_reg(camera_para.SENSOR.reg[i].addr, camera_para.SENSOR.reg[i].para);
	}
	for(i=0; i<CCT_END_ADDR; i++)
	{
		write_GC0316_reg(camera_para.SENSOR.cct[i].addr, camera_para.SENSOR.cct[i].para);
	}
}

// update camera_para from sensor register
void sensor_to_camera_para_GC0316(void)
{
	kal_uint32	i;
	
	for(i=0; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_GC0316_reg(camera_para.SENSOR.reg[i].addr);
	}
	for(i=FACTORY_START_ADDR; 0xFFFFFFFF!=camera_para.SENSOR.reg[i].addr; i++)
	{
		camera_para.SENSOR.reg[i].para = read_GC0316_reg(camera_para.SENSOR.reg[i].addr);
	}
}

//------------------------Engineer mode---------------------------------

void  get_sensor_group_count_GC0316(kal_int32* sensor_count_ptr)
{
   *sensor_count_ptr=GROUP_TOTAL_NUMS;
   
	return;
}

void get_sensor_group_info_GC0316(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
	/*switch (group_idx)
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
	}*/
}

void get_sensor_item_info_GC0316(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr)
{
	kal_uint8 temp_reg;
	
	/*switch (group_idx)
	{
		case AWB_GAIN:
			switch (item_idx)
			{
				case 0:
				  sprintf(info_ptr->item_name_ptr,"AWB R Gain");
				  info_ptr->item_value=read_GC0316_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr);
				  info_ptr->is_true_false=KAL_FALSE;
				  info_ptr->is_read_only=KAL_FALSE;
				  info_ptr->is_need_restart=KAL_FALSE;
				  info_ptr->min=0;
				  info_ptr->max=0xff;
				break; 
				case 1:
				  sprintf(info_ptr->item_name_ptr,"AWB B Gain");
				  info_ptr->item_value=read_GC0316_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr);
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
				  
				  temp_reg = read_GC0316_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
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
				  
				  temp_reg = read_GC0316_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
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
				  
				  temp_reg = read_OV0306_gain();
				  
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
				  
				  temp_reg = read_GC0316_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
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
				  
				  temp_reg = read_GC0316_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
				  if(temp_reg&0xC0)0306
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
	}*/
}

kal_bool set_sensor_item_info_GC0316(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
{
   kal_uint8 temp_reg;
   kal_uint16 temp_gain;
   
   /*switch (group_idx)
	{
		case AWB_GAIN:
			switch (item_idx)
			{
				case 0:
				  camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].para = item_value;
				  write_GC0316_reg(camera_para.SENSOR.reg[AWB_GAIN_R_INDEX].addr,item_value);
				break;
				case 1:
				  camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].para = item_value;
				  write_GC0316_reg(camera_para.SENSOR.reg[AWB_GAIN_B_INDEX].addr,item_value);
				break; 
				default:
				   ASSERT(0);
			}			
		break;
		case PRE_GAIN:
			switch (item_idx)
			{
				case 0:
				  temp_reg = read_GC0316_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr);
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
				  write_GC0316_reg(camera_para.SENSOR.cct[PRE_GAIN_R_INDEX].addr,temp_reg);
				break;
				case 1:
				  temp_reg = read_GC0316_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr);
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
				  write_GC0316_reg(camera_para.SENSOR.cct[PRE_GAIN_B_INDEX].addr,temp_reg);
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
				  write_GC0316_reg(camera_para.SENSOR.cct[GLOBAL_GAIN_INDEX].addr,temp_reg);
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
				      temp_reg = read_GC0316_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg |= 0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_GC0316_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
				  }
				  else
				  {
				      temp_reg = read_GC0316_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr);
				      temp_reg &= ~0x10;
				      camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].para = temp_reg;
				      write_GC0316_reg(camera_para.SENSOR.reg[SENSOR_DBLC_INDEX].addr,temp_reg);
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
				  temp_reg = read_GC0316_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr);
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
				  write_GC0316_reg(camera_para.SENSOR.reg[GAMMA_ENABLE_INDEX].addr,temp_reg);
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
				  write_GC0316_reg(FAC_SENSOR_REG,item_value);
				break;
				default:
				   ASSERT(0);		
			}
		break;
		default:
		   ASSERT(0);
	}*/
	
	return KAL_TRUE;
}


kal_bool is_sensor_ready_GC0316()
{
	REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;
	kal_sleep_task(2);	
	REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;
	kal_sleep_task(2);
	REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;

	kal_sleep_task(2);
	sensor_id=(read_cmos_sensor(0x00));

#ifdef NOKE_DEBUG
	noke_dbg_printf("\r CAMERA : is_sensor_ready_GC0316 : sensor_id = 0x%04x \n", sensor_id);
#endif
	
	if( GC0316_SENSOR_ID == sensor_id )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*

    以下是主摄像头的初始化函数， 不同厂家的不一样。

*/
void main_camera_gc0316_init_func_default(void)
{
	write_cmos_sensor(0xf0, 0x00); //page0
	write_cmos_sensor(0x13, 0x01); //apwd
	Delayms_GC0316(200);
		//-close output-//
	write_cmos_sensor(0x43, 0x20);	//[6] pclk_en
	write_cmos_sensor(0x44, 0xa2);	//[6] output_en      
	write_cmos_sensor(0x40, 0x10);   
	write_cmos_sensor(0x41, 0x00); 
	write_cmos_sensor(0x47, 0x00);
	write_cmos_sensor(0x00, 0x00);
	write_cmos_sensor(0x00, 0x00);
	write_cmos_sensor(0x00, 0x00);  // delay some time
		//-nomal output-//
	Delayms_GC0316(200);
	write_cmos_sensor(0xc7, 0x50);  
	write_cmos_sensor(0xc8, 0x40);  
	write_cmos_sensor(0xc9, 0x48); 

	
	
	write_cmos_sensor(0x00, 0x98); //RO
	write_cmos_sensor(0x01, 0xBF); 
	write_cmos_sensor(0x02, 0x0C); 
	write_cmos_sensor(0x03, 0x00); 
	write_cmos_sensor(0x04, 0x8e);//0x8e,
	write_cmos_sensor(0x05, 0x00); 
	write_cmos_sensor(0x06, 0x00);
	write_cmos_sensor(0x07, 0x00); 
	write_cmos_sensor(0x08, 0x00);
	write_cmos_sensor(0x09, 0x01);  //width height YUV: 488-8
	write_cmos_sensor(0x0a, 0xfc);
	write_cmos_sensor(0x0b, 0x02);  //window width YUV: 648-8
	write_cmos_sensor(0x0c, 0x90);//0x88,
	write_cmos_sensor(0x0d, 0x22); 
	write_cmos_sensor(0x0e, 0x22); 
	write_cmos_sensor(0x0f, 0x30); 
	write_cmos_sensor(0x10, 0x24); 
	write_cmos_sensor(0x11, 0x00); 
	write_cmos_sensor(0x12, 0x10); 
	write_cmos_sensor(0x14, 0x00); 
	write_cmos_sensor(0x15, 0x08); 
	write_cmos_sensor(0x16, 0x04); 
	write_cmos_sensor(0x17, 0x08); 
	write_cmos_sensor(0x18, 0x02); 
	write_cmos_sensor(0x19, 0x00); 
	write_cmos_sensor(0x1a, 0x00); 
	write_cmos_sensor(0x1b, 0x00); 
	write_cmos_sensor(0x1c, 0x02); 
	write_cmos_sensor(0x1d, 0x02); 
	write_cmos_sensor(0x1e, 0x00); 
	write_cmos_sensor(0x1f, 0x00); 
		//BLK control
	write_cmos_sensor(0x59, 0x30); //global offset
	write_cmos_sensor(0x35, 0x6d); //BLK
	write_cmos_sensor(0x36, 0x15); 
		//--PRE_GAIN--//
	write_cmos_sensor(0x61, 0x80); //G0 gain
	write_cmos_sensor(0x63, 0x80); //R gain
	//write_cmos_sensor(0x65, 0x98); //B1 gain
		write_cmos_sensor(0x65, 0x90); //B1 gain///2009
	write_cmos_sensor(0x67, 0x80); //G1 gain
	write_cmos_sensor(0x68, 0x08); //[3:0]global 0x04=1.0X, 0x0f=3.99X 
	write_cmos_sensor(0xdb, 0x40);
	write_cmos_sensor(0xdc, 0x40);
		//-Color correction-//
		/*
	write_cmos_sensor(0x69, 0x40);
	write_cmos_sensor(0x6a, 0xf8); 
	write_cmos_sensor(0x6b, 0xf8);
	write_cmos_sensor(0x6c, 0x00);
	write_cmos_sensor(0x6d, 0x48);
	write_cmos_sensor(0x6e, 0xf4);*/
	write_cmos_sensor(	0x69,0x44	);
	write_cmos_sensor(	0x6a,0xf8	);
	write_cmos_sensor(	0x6b,0xf4	);
	write_cmos_sensor(	0x6c,0xfe	);
	write_cmos_sensor(	0x6d,0x53	);
	write_cmos_sensor(	0x6e,0xe7	);

		//-lens shading-// 
	write_cmos_sensor(0x70, 0x05);  //big lens
	write_cmos_sensor(0x71, 0x04); 
	write_cmos_sensor(0x72, 0x03); 
	write_cmos_sensor(0x73, 0x08); 
	write_cmos_sensor(0x74, 0x3d); 
	write_cmos_sensor(0x75, 0x51); 
	write_cmos_sensor(0x76, 0x00); 
	write_cmos_sensor(0x7d, 0x00);
		//-Defect,Noise-// 
	write_cmos_sensor(0x7e, 0x44); 
	write_cmos_sensor(0x7f, 0x84);
	write_cmos_sensor(0x80, 0x0c); //DN，0x18 
	write_cmos_sensor(0x81, 0x0c); //0x10//，0x80,0x81, 
	write_cmos_sensor(0x82, 0x34); //66
	write_cmos_sensor(0x83, 0x18); 
	write_cmos_sensor(0x84, 0x18); 
	write_cmos_sensor(0x85, 0x04);//0x02, 
	write_cmos_sensor(0x86, 0xff); 
	write_cmos_sensor(0x87, 0x93);//93   //0x94//，
		//-Edge enhance-// 
	write_cmos_sensor(0x88, 0x0a); //0a, 
	write_cmos_sensor(0x89, 0x04); //04, 
	write_cmos_sensor(0x8b, 0x0a); //5  edge_max
	write_cmos_sensor(0x8c, 0x10); //低4位 ：1 : adaptive enhance effect，0: edge effect 64
	write_cmos_sensor(0x8d, 0x23);//0x12, 
	write_cmos_sensor(0x8e, 0x32);//0x3f//，0x8d,0x8e，
		//-RGB GAMMA-//   gamma3-new
		/*
	write_cmos_sensor(0x8f, 0x19);
	write_cmos_sensor(0x90, 0x30);
	write_cmos_sensor(0x91, 0x44);
	write_cmos_sensor(0x92, 0x54);
	write_cmos_sensor(0x93, 0x63);
	write_cmos_sensor(0x94, 0x71);
	write_cmos_sensor(0x95, 0x7e);
	write_cmos_sensor(0x96, 0x94);
	write_cmos_sensor(0x97, 0xa6);
	write_cmos_sensor(0x98, 0xb6);
	write_cmos_sensor(0x99, 0xc3);
	write_cmos_sensor(0x9A, 0xcc);
	write_cmos_sensor(0x9B, 0xd5);
	write_cmos_sensor(0x9C, 0xdb);
	write_cmos_sensor(0x9D, 0xe4);
	write_cmos_sensor(0x9E, 0xe9);
	write_cmos_sensor(0x9F, 0xeb);*/
/*
	write_cmos_sensor(0x8f, 0x1b);
	write_cmos_sensor(0x90, 0x35);
	write_cmos_sensor(0x91, 0x48);
	write_cmos_sensor(0x92, 0x57);
	write_cmos_sensor(0x93, 0x63);
	write_cmos_sensor(0x94, 0x6e);
	write_cmos_sensor(0x95, 0x77);
	write_cmos_sensor(0x96, 0x88);
	write_cmos_sensor(0x97, 0x96);
	write_cmos_sensor(0x98, 0xA3);
	write_cmos_sensor(0x99, 0xaf);
	write_cmos_sensor(0x9A, 0xba);
	write_cmos_sensor(0x9B, 0xc4);
	write_cmos_sensor(0x9C, 0xce);
	write_cmos_sensor(0x9D, 0xE0);
	write_cmos_sensor(0x9E, 0xf0);
	write_cmos_sensor(0x9F, 0xFe);		
	*/

		//add by peter
	write_cmos_sensor(	0x8f  ,0x23);  
	write_cmos_sensor(	0x90  ,0x38);  
	write_cmos_sensor(	0x91  ,0x4F);  
	write_cmos_sensor(	0x92  ,0x61);  
	write_cmos_sensor(	0x93  ,0x72);  
	write_cmos_sensor(	0x94  ,0x80);  
	write_cmos_sensor(	0x95  ,0x8D);  
	write_cmos_sensor(	0x96  ,0xA2);  
	write_cmos_sensor(	0x97  ,0xB2);  
	write_cmos_sensor(	0x98  ,0xC0);  
	write_cmos_sensor(	0x99  ,0xCA);  
	write_cmos_sensor(	0x9a  ,0xD3);  
	write_cmos_sensor(	0x9b  ,0xDB);  
	write_cmos_sensor(	0x9c  ,0xE2);  
	write_cmos_sensor(	0x9d  ,0xED);  
	write_cmos_sensor(	0x9e  ,0xF6);  
	write_cmos_sensor(	0x9f  ,0xFD); 
		
		//--Y_gamma--//
	write_cmos_sensor(0xf1, 0x0a); 
	write_cmos_sensor(0xf2, 0x16); 
	write_cmos_sensor(0xf3, 0x20); 
	write_cmos_sensor(0xf4, 0x38); 
	write_cmos_sensor(0xf5, 0x4e); 
	write_cmos_sensor(0xf6, 0x64); 
	write_cmos_sensor(0xf7, 0x78); 
	write_cmos_sensor(0xf8, 0x8b); 
	write_cmos_sensor(0xf9, 0xaa); 
	write_cmos_sensor(0xfa, 0xc3); 
	write_cmos_sensor(0xfb, 0xd6); 
	write_cmos_sensor(0xfc, 0xe1); 
	write_cmos_sensor(0xfd, 0xe9);
	
		//-Y Color domai-//
	write_cmos_sensor(0x77, 0x80); //contrast_center
	write_cmos_sensor(0x78, 0x00); 
	write_cmos_sensor(0x79, 0x00); 
	write_cmos_sensor(0x7a, 0x00); 
	write_cmos_sensor(0x7b, 0x40); 
	write_cmos_sensor(0x7c, 0x00); //160
	write_cmos_sensor(0xa0, 0x50); //saturation, when open CC, use smaller saturation
	//write_cmos_sensor(0xa1, 0x40); //contrast//
	write_cmos_sensor(0xa1, 0x4c); //contrast//peter 200905
	write_cmos_sensor(0xa2, 0x30); //Cb_sat	
	write_cmos_sensor(0xa3, 0x30); //Cr_sat/
		//--  skin	--//
	write_cmos_sensor(0xa8, 0xf2); //，
	write_cmos_sensor(0xa9, 0x0e);
	write_cmos_sensor(0xaa, 0x00);
	write_cmos_sensor(0xab, 0xe0);
	write_cmos_sensor(0xac, 0xfc);
	write_cmos_sensor(0xad, 0x10);
	write_cmos_sensor(0xae, 0x80);
	write_cmos_sensor(0xaf, 0x80); 
	write_cmos_sensor(0xe8, 0x80); 
	write_cmos_sensor(0xe9, 0xff); 
	write_cmos_sensor(0xea, 0xff); 
	write_cmos_sensor(0xeb, 0x00); 
	write_cmos_sensor(0xec, 0x00); 
	write_cmos_sensor(0xed, 0x00); 
	write_cmos_sensor(0xee, 0x00); 
	write_cmos_sensor(0xef, 0xff);
		//--   AWB	--//
	/*write_cmos_sensor(0xba, 0x0f);   //0x08, //AWB	by jiu
	write_cmos_sensor(0xbb, 0x0f);  
	write_cmos_sensor(0xbc, 0x00); //0x01, 
	write_cmos_sensor(0xbd, 0xf0);  
	write_cmos_sensor(0xbe, 0x20);  
	write_cmos_sensor(0xbf, 0x40); //0x20,by jiu 
	write_cmos_sensor(0xc0, 0x66);  
	write_cmos_sensor(0xc1, 0xF0);  
	write_cmos_sensor(0xc2, 0x04);  //0x07
	write_cmos_sensor(0xc3, 0x80);  
	write_cmos_sensor(0xc4, 0x01);  
	write_cmos_sensor(0xc5, 0x41);  //，
	write_cmos_sensor(0xc6, 0x70); //0xff,//0x68, 
	write_cmos_sensor(0xc7, 0x58);  
	write_cmos_sensor(0xc8, 0x40);  
	write_cmos_sensor(0xc9, 0x5c);   //0x60,by jiu //，
	write_cmos_sensor(0xcd, 0x08); //R_ratio, 0x08, 
	write_cmos_sensor(0xce, 0x08); //0x08, 
	write_cmos_sensor(0xcf, 0x08); //0x08,*/

	write_cmos_sensor(0xba, 0x0f);   //0x08, //AWB	by jiu
	write_cmos_sensor(0xbb, 0x0f);  
	write_cmos_sensor(0xbc, 0x02); //0x01,  //，
	write_cmos_sensor(0xbd, 0xe0);  
	write_cmos_sensor(0xbe, 0x20);  
	write_cmos_sensor(0xbf, 0x40); //0x20,by jiu 
	write_cmos_sensor(0xc0, 0x00);  //  10, 66  
	write_cmos_sensor(0xc1, 0xf0);  
	write_cmos_sensor(0xc2, 0x04);  //0x07
	write_cmos_sensor(0xc3, 0x80);  
	write_cmos_sensor(0xc4, 0x01);  
	write_cmos_sensor(0xc5, 0x44);  //，
	write_cmos_sensor(0xc6, 0x70); //0xff,//0x68,  //，
	//write_cmos_sensor(0xcd, 0x08); //R_ratio, 0x08, 
	//write_cmos_sensor(0xce, 0x08); //0x08, 
	//write_cmos_sensor(0xcf, 0x08); 

	write_cmos_sensor(0xcd, 0x09); //R_ratio, 0x08, 
	write_cmos_sensor(0xce, 0x09); //0x08, 
	write_cmos_sensor(0xcf, 0x08); 
		//--   AE	 --//
	write_cmos_sensor(0xd0, 0x17); //0x37, //0x3f,  //， AEC_mode
	write_cmos_sensor(0xd1, 0x50);   // Y target , //48 peter 200905
	write_cmos_sensor(0xd2, 0xa6);  //margin;speed
	
	write_cmos_sensor(0xd4, 0x30); 
	write_cmos_sensor(0xd5, 0xC0); 
	write_cmos_sensor(0xd6, 0x7D);    //AEC_flicker_step  7D--25FPS
	write_cmos_sensor(0xd7, 0x02);    //exp_min_l  
	                                                                                                     
	write_cmos_sensor(0xf0, 0x00); //page0   
	write_cmos_sensor(0xd8, 0x02);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0xd9, 0xff); //，                                                                                                                                                                  
	write_cmos_sensor(0xda, 0xff);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0xdb, 0x40); //，                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	write_cmos_sensor(0xdd, 0x10); //[7:4]exp_level //                                                                                                                                                                                                                                                   
	write_cmos_sensor(0xde, 0xff);						                                                                                                                                                                                                                                                            
	write_cmos_sensor(0x20, 0x02);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x21, 0x80);//post gain limit，  c0                                                                                                                             
	write_cmos_sensor(0x22, 0x50);//pre gain limit    ,80                                                                                                                                                                                                            
	write_cmos_sensor(0x23, 0x88);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x24, 0x00);                                                                                                                                                                                                                          
	write_cmos_sensor(0x25, 0xaa);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x26, 0xcc);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x27, 0x16);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x28, 0x03); //                                                                                                                                                                                                                                                                    
	write_cmos_sensor(0x29, 0x18);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x2a, 0x03); //exp_level_1, 14fps                                                                                                                                                                                                                                                  
	write_cmos_sensor(0x2b, 0x18);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x2c, 0x06); //exp_level_2 , 7c4~7FPS, 58c~10FPS, 6a8~8.2FPS                                                                                                                                                                                                                       
	write_cmos_sensor(0x2d, 0xe0);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x2e, 0x06); //exp_level_3                                                                                                                                                                                                                                                         
	write_cmos_sensor(0x2f, 0xe0);                                                                                                                                                                                                                 
	write_cmos_sensor(0x30, 0x04);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x31, 0x00);                                                                                                                                                                                                                                                                                                        
	write_cmos_sensor(0x32, 0x00); 
	write_cmos_sensor(0x33, 0x0f); 
	write_cmos_sensor(0x34, 0x40); //，
		//-Measure window-// 
	write_cmos_sensor(0xe0, 0x01); //window
	write_cmos_sensor(0xe1, 0x01); 
	write_cmos_sensor(0xe2, 0x28); 
	write_cmos_sensor(0xe3, 0x1e); 
	write_cmos_sensor(0xe4, 0x0a); 
	write_cmos_sensor(0xe5, 0x0a); 
	write_cmos_sensor(0xe6, 0x1e); 
	write_cmos_sensor(0xe7, 0x14); 
		//- PGA_table -//                                               
	write_cmos_sensor(0xf0, 0x01); //page1, PGA_table                                    
	write_cmos_sensor(0x00, 0x04);                                                       
	write_cmos_sensor(0x01, 0x00);                                                       
	write_cmos_sensor(0x02, 0x04);                                                       
	write_cmos_sensor(0x03, 0x00); //,                                
	write_cmos_sensor(0x04, 0x04); //
	write_cmos_sensor(0x05, 0x00); //,
	write_cmos_sensor(0x06, 0x04);                                                       
	write_cmos_sensor(0x07, 0x00); //,                                                   
	write_cmos_sensor(0x08, 0x04);                                                       
	write_cmos_sensor(0x09, 0x00);                                                       
	write_cmos_sensor(0x0a, 0x04);                                                       
	write_cmos_sensor(0x0b, 0x00);                                                       
	write_cmos_sensor(0x0c, 0x04);  //level6                                                       
	write_cmos_sensor(0x0d, 0x00);                                                       
	write_cmos_sensor(0x0e, 0x04);  //level7                                                    
	write_cmos_sensor(0x0f, 0x01);                                                      
	write_cmos_sensor(0x10, 0x00);                                                       
	write_cmos_sensor(0x11, 0x00);                                                       
	write_cmos_sensor(0x12, 0x00);                                                       
	write_cmos_sensor(0x13, 0x00);                                                       
	write_cmos_sensor(0x14, 0x00);                                                       
	write_cmos_sensor(0x15, 0x00);                                                       
	write_cmos_sensor(0x16, 0x00);                                                       
	write_cmos_sensor(0x17, 0x00); //end of page1 
	
		//--   ISP	--//
	write_cmos_sensor(0xF0, 0x00); //page0

	write_cmos_sensor(0x13, 0x00);
	write_cmos_sensor(0x40, 0x7e); 
	write_cmos_sensor(0x41, 0x2f); //[5]close ABS	  
	write_cmos_sensor(0x42, 0x30); 

	write_cmos_sensor(0x45, 0x24); 
	write_cmos_sensor(0x47, 0x00); 
	write_cmos_sensor(0x48, 0x00); 
	write_cmos_sensor(0x49, 0x00); 
	write_cmos_sensor(0x4a, 0x00); 
	write_cmos_sensor(0x4b, 0x00); 
	write_cmos_sensor(0x4d, 0x00); 
	write_cmos_sensor(0x4e, 0x23); 
	write_cmos_sensor(0x4f, 0x11);//0x21, //,
	write_cmos_sensor(0x50, 0x1a); //
	//write_cmos_sensor(0xb0, 0xe8); //0xf0,//, 
	write_cmos_sensor(0xb1, 0x40);
	write_cmos_sensor(0xb2, 0x20);
		//-open output-//
	write_cmos_sensor(0x43, 0x60);	
	write_cmos_sensor(0x44, 0xe2);
	
	write_cmos_sensor(0x59, 0x50);  //global offset
	write_cmos_sensor(0x35, 0x0d);
	write_cmos_sensor(0x36, 0x10);
	write_cmos_sensor(0x37, 0x08);
	write_cmos_sensor(0x38, 0x08);
	write_cmos_sensor(0x39, 0x08);
	write_cmos_sensor(0x3a, 0x08);
	write_cmos_sensor(0x35, 0x6d);
	write_cmos_sensor(0x59, 0x38);

	kal_sleep_task(20);
	write_cmos_sensor(0xc0, 0x00); 
	
}
/*

    以下是副摄像头的初始化函数， 不同厂家的不一样。

*/
#if defined(DOUBLE_CAMERA_SUPPORT)
void sub_camera_gc0316_init_func_default(void)
{
	write_cmos_sensor(0xf0, 0x00); //page0
	write_cmos_sensor(0x13, 0x01); //apwd
	Delayms_GC0316(200);
		//-close output-//
	write_cmos_sensor(0x43, 0x20);	//[6] pclk_en
	write_cmos_sensor(0x44, 0xa2);	//[6] output_en      
	write_cmos_sensor(0x40, 0x10);   
	write_cmos_sensor(0x41, 0x00); 
	write_cmos_sensor(0x47, 0x00);
	write_cmos_sensor(0x00, 0x00);
	write_cmos_sensor(0x00, 0x00);
	write_cmos_sensor(0x00, 0x00);  // delay some time
		//-nomal output-//
	Delayms_GC0316(200);
	write_cmos_sensor(0xc7, 0x50);  
	write_cmos_sensor(0xc8, 0x40);  
	write_cmos_sensor(0xc9, 0x48); 

	
	
	write_cmos_sensor(0x00, 0x98); //RO
	write_cmos_sensor(0x01, 0xBF); 
	write_cmos_sensor(0x02, 0x0C); 
	write_cmos_sensor(0x03, 0x00); 
	write_cmos_sensor(0x04, 0x8e);//0x8e,
	write_cmos_sensor(0x05, 0x00); 
	write_cmos_sensor(0x06, 0x00);
	write_cmos_sensor(0x07, 0x00); 
	write_cmos_sensor(0x08, 0x00);
	write_cmos_sensor(0x09, 0x01);  //width height YUV: 488-8
	write_cmos_sensor(0x0a, 0xfc);
	write_cmos_sensor(0x0b, 0x02);  //window width YUV: 648-8
	write_cmos_sensor(0x0c, 0x90);//0x88,
	write_cmos_sensor(0x0d, 0x22); 
	write_cmos_sensor(0x0e, 0x22); 
	write_cmos_sensor(0x0f, 0x20); 
	write_cmos_sensor(0x10, 0x24); 
	write_cmos_sensor(0x11, 0x00); 
	write_cmos_sensor(0x12, 0x10); 
	write_cmos_sensor(0x14, 0x00); 
	write_cmos_sensor(0x15, 0x08); 
	write_cmos_sensor(0x16, 0x04); 
	write_cmos_sensor(0x17, 0x08); 
	write_cmos_sensor(0x18, 0x02); 
	write_cmos_sensor(0x19, 0x00); 
	write_cmos_sensor(0x1a, 0x00); 
	write_cmos_sensor(0x1b, 0x00); 
	write_cmos_sensor(0x1c, 0x02); 
	write_cmos_sensor(0x1d, 0x02); 
	write_cmos_sensor(0x1e, 0x00); 
	write_cmos_sensor(0x1f, 0x00); 
		//BLK control
	write_cmos_sensor(0x59, 0x30); //global offset
	write_cmos_sensor(0x35, 0x6d); //BLK
	write_cmos_sensor(0x36, 0x15); 
		//--PRE_GAIN--//
	write_cmos_sensor(0x61, 0x80); //G0 gain
	write_cmos_sensor(0x63, 0x80); //R gain
	//write_cmos_sensor(0x65, 0x98); //B1 gain
		write_cmos_sensor(0x65, 0x90); //B1 gain
	write_cmos_sensor(0x67, 0x80); //G1 gain
	write_cmos_sensor(0x68, 0x08); //[3:0]global 0x04=1.0X, 0x0f=3.99X 
	write_cmos_sensor(0xdb, 0x40);
	write_cmos_sensor(0xdc, 0x40);
		//-Color correction-//
		/*
	write_cmos_sensor(0x69, 0x40);
	write_cmos_sensor(0x6a, 0xf8); 
	write_cmos_sensor(0x6b, 0xf8);
	write_cmos_sensor(0x6c, 0x00);
	write_cmos_sensor(0x6d, 0x48);
	write_cmos_sensor(0x6e, 0xf4);*/
	write_cmos_sensor(	0x69,0x44	);
	write_cmos_sensor(	0x6a,0xf8	);
	write_cmos_sensor(	0x6b,0xf4	);
	write_cmos_sensor(	0x6c,0xfe	);
	write_cmos_sensor(	0x6d,0x53	);
	write_cmos_sensor(	0x6e,0xe7	);

		//-lens shading-// 
	write_cmos_sensor(0x70, 0x05);  //big lens
	write_cmos_sensor(0x71, 0x04); 
	write_cmos_sensor(0x72, 0x03); 
	write_cmos_sensor(0x73, 0x08); 
	write_cmos_sensor(0x74, 0x3d); 
	write_cmos_sensor(0x75, 0x51); 
	write_cmos_sensor(0x76, 0x00); 
	write_cmos_sensor(0x7d, 0x00);
		//-Defect,Noise-// 
	write_cmos_sensor(0x7e, 0x44); 
	write_cmos_sensor(0x7f, 0x84);
	write_cmos_sensor(0x80, 0x0c); //DN，0x18 
	write_cmos_sensor(0x81, 0x0c); //0x10//，0x80,0x81, 
	write_cmos_sensor(0x82, 0x34); //66
	write_cmos_sensor(0x83, 0x18); 
	write_cmos_sensor(0x84, 0x18); 
	write_cmos_sensor(0x85, 0x04);//0x02, 
	write_cmos_sensor(0x86, 0xff); 
	write_cmos_sensor(0x87, 0x93);//93   //0x94//，
		//-Edge enhance-// 
	write_cmos_sensor(0x88, 0x0a); //0a, 
	write_cmos_sensor(0x89, 0x04); //04, 
	write_cmos_sensor(0x8b, 0x0a); //5  edge_max
	write_cmos_sensor(0x8c, 0x10); //低4位 ：1 : adaptive enhance effect，0: edge effect 64
	write_cmos_sensor(0x8d, 0x23);//0x12, 
	write_cmos_sensor(0x8e, 0x32);//0x3f//，0x8d,0x8e，
		//-RGB GAMMA-//   gamma3-new
		/*
	write_cmos_sensor(0x8f, 0x19);
	write_cmos_sensor(0x90, 0x30);
	write_cmos_sensor(0x91, 0x44);
	write_cmos_sensor(0x92, 0x54);
	write_cmos_sensor(0x93, 0x63);
	write_cmos_sensor(0x94, 0x71);
	write_cmos_sensor(0x95, 0x7e);
	write_cmos_sensor(0x96, 0x94);
	write_cmos_sensor(0x97, 0xa6);
	write_cmos_sensor(0x98, 0xb6);
	write_cmos_sensor(0x99, 0xc3);
	write_cmos_sensor(0x9A, 0xcc);
	write_cmos_sensor(0x9B, 0xd5);
	write_cmos_sensor(0x9C, 0xdb);
	write_cmos_sensor(0x9D, 0xe4);
	write_cmos_sensor(0x9E, 0xe9);
	write_cmos_sensor(0x9F, 0xeb);*/

		//add by peter
	write_cmos_sensor(	0x8f  ,0x23);  
	write_cmos_sensor(	0x90  ,0x38);  
	write_cmos_sensor(	0x91  ,0x4F);  
	write_cmos_sensor(	0x92  ,0x61);  
	write_cmos_sensor(	0x93  ,0x72);  
	write_cmos_sensor(	0x94  ,0x80);  
	write_cmos_sensor(	0x95  ,0x8D);  
	write_cmos_sensor(	0x96  ,0xA2);  
	write_cmos_sensor(	0x97  ,0xB2);  
	write_cmos_sensor(	0x98  ,0xC0);  
	write_cmos_sensor(	0x99  ,0xCA);  
	write_cmos_sensor(	0x9a  ,0xD3);  
	write_cmos_sensor(	0x9b  ,0xDB);  
	write_cmos_sensor(	0x9c  ,0xE2);  
	write_cmos_sensor(	0x9d  ,0xED);  
	write_cmos_sensor(	0x9e  ,0xF6);  
	write_cmos_sensor(	0x9f  ,0xFD); 

	/*write_cmos_sensor(0x8f, 0x1b);
	write_cmos_sensor(0x90, 0x35);
	write_cmos_sensor(0x91, 0x48);
	write_cmos_sensor(0x92, 0x57);
	write_cmos_sensor(0x93, 0x63);
	write_cmos_sensor(0x94, 0x6e);
	write_cmos_sensor(0x95, 0x77);
	write_cmos_sensor(0x96, 0x88);
	write_cmos_sensor(0x97, 0x96);
	write_cmos_sensor(0x98, 0xA3);
	write_cmos_sensor(0x99, 0xaf);
	write_cmos_sensor(0x9A, 0xba);
	write_cmos_sensor(0x9B, 0xc4);
	write_cmos_sensor(0x9C, 0xce);
	write_cmos_sensor(0x9D, 0xE0);
	write_cmos_sensor(0x9E, 0xf0);
	write_cmos_sensor(0x9F, 0xFe);	*/	
	
		//--Y_gamma--//
	write_cmos_sensor(0xf1, 0x0a); 
	write_cmos_sensor(0xf2, 0x16); 
	write_cmos_sensor(0xf3, 0x20); 
	write_cmos_sensor(0xf4, 0x38); 
	write_cmos_sensor(0xf5, 0x4e); 
	write_cmos_sensor(0xf6, 0x64); 
	write_cmos_sensor(0xf7, 0x78); 
	write_cmos_sensor(0xf8, 0x8b); 
	write_cmos_sensor(0xf9, 0xaa); 
	write_cmos_sensor(0xfa, 0xc3); 
	write_cmos_sensor(0xfb, 0xd6); 
	write_cmos_sensor(0xfc, 0xe1); 
	write_cmos_sensor(0xfd, 0xe9);
	
		//-Y Color domai-//
	write_cmos_sensor(0x77, 0x80); //contrast_center
	write_cmos_sensor(0x78, 0x00); 
	write_cmos_sensor(0x79, 0x00); 
	write_cmos_sensor(0x7a, 0x00); 
	write_cmos_sensor(0x7b, 0x40); 
	write_cmos_sensor(0x7c, 0x00); 
	write_cmos_sensor(0xa0, 0x50); //saturation, when open CC, use smaller saturation
	write_cmos_sensor(0xa1, 0x48); //contrast
	write_cmos_sensor(0xa2, 0x30); //Cb_sat	
	write_cmos_sensor(0xa3, 0x30); //Cr_sat/
		//--  skin	--//
	write_cmos_sensor(0xa8, 0xf2); //，
	write_cmos_sensor(0xa9, 0x0e);
	write_cmos_sensor(0xaa, 0x00);
	write_cmos_sensor(0xab, 0xe0);
	write_cmos_sensor(0xac, 0xfc);
	write_cmos_sensor(0xad, 0x10);
	write_cmos_sensor(0xae, 0x80);
	write_cmos_sensor(0xaf, 0x80); 
	write_cmos_sensor(0xe8, 0x80); 
	write_cmos_sensor(0xe9, 0xff); 
	write_cmos_sensor(0xea, 0xff); 
	write_cmos_sensor(0xeb, 0x00); 
	write_cmos_sensor(0xec, 0x00); 
	write_cmos_sensor(0xed, 0x00); 
	write_cmos_sensor(0xee, 0x00); 
	write_cmos_sensor(0xef, 0xff);
		//--   AWB	--//
	/*write_cmos_sensor(0xba, 0x0f);   //0x08, //AWB	by jiu
	write_cmos_sensor(0xbb, 0x0f);  
	write_cmos_sensor(0xbc, 0x00); //0x01, 
	write_cmos_sensor(0xbd, 0xf0);  
	write_cmos_sensor(0xbe, 0x20);  
	write_cmos_sensor(0xbf, 0x40); //0x20,by jiu 
	write_cmos_sensor(0xc0, 0x66);  
	write_cmos_sensor(0xc1, 0xF0);  
	write_cmos_sensor(0xc2, 0x04);  //0x07
	write_cmos_sensor(0xc3, 0x80);  
	write_cmos_sensor(0xc4, 0x01);  
	write_cmos_sensor(0xc5, 0x41);  //，
	write_cmos_sensor(0xc6, 0x70); //0xff,//0x68, 
	write_cmos_sensor(0xc7, 0x58);  
	write_cmos_sensor(0xc8, 0x40);  
	write_cmos_sensor(0xc9, 0x5c);   //0x60,by jiu //，
	write_cmos_sensor(0xcd, 0x08); //R_ratio, 0x08, 
	write_cmos_sensor(0xce, 0x08); //0x08, 
	write_cmos_sensor(0xcf, 0x08); //0x08,*/

	write_cmos_sensor(0xba, 0x0f);   //0x08, //AWB	by jiu
	write_cmos_sensor(0xbb, 0x0f);  
	write_cmos_sensor(0xbc, 0x02); //0x01,  //，
	write_cmos_sensor(0xbd, 0xe0);  
	write_cmos_sensor(0xbe, 0x20);  
	write_cmos_sensor(0xbf, 0x40); //0x20,by jiu 
	write_cmos_sensor(0xc0, 0x00);  //  10, 66  
	write_cmos_sensor(0xc1, 0xf0);  
	write_cmos_sensor(0xc2, 0x04);  //0x07
	write_cmos_sensor(0xc3, 0x80);  
	write_cmos_sensor(0xc4, 0x01);  
	write_cmos_sensor(0xc5, 0x44);  //，
	write_cmos_sensor(0xc6, 0x70); //0xff,//0x68,  //，
//	write_cmos_sensor(0xcd, 0x08); //R_ratio, 0x08, 
//	write_cmos_sensor(0xce, 0x08); //0x08, 
//	write_cmos_sensor(0xcf, 0x08); 
		write_cmos_sensor(0xcd, 0x09); //R_ratio, 0x08, 
	write_cmos_sensor(0xce, 0x09); //0x08, 
	write_cmos_sensor(0xcf, 0x08); 
		//--   AE	 --//
	write_cmos_sensor(0xd0, 0x17); //0x37, //0x3f,  //， AEC_mode
	write_cmos_sensor(0xd1, 0x50);   // Y target , //peter 200905
	write_cmos_sensor(0xd2, 0xa6);  //margin;speed
	
	write_cmos_sensor(0xd4, 0x30); 
	write_cmos_sensor(0xd5, 0xC0); 
	write_cmos_sensor(0xd6, 0x7D);    //AEC_flicker_step  7D--25FPS
	write_cmos_sensor(0xd7, 0x02);    //exp_min_l  
	                                                                                                     
	write_cmos_sensor(0xf0, 0x00); //page0   
	write_cmos_sensor(0xd8, 0x02);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0xd9, 0xff); //，                                                                                                                                                                  
	write_cmos_sensor(0xda, 0xff);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0xdb, 0x40); //，                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	write_cmos_sensor(0xdd, 0x10); //[7:4]exp_level //                                                                                                                                                                                                                                                   
	write_cmos_sensor(0xde, 0xff);						                                                                                                                                                                                                                                                            
	write_cmos_sensor(0x20, 0x02);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x21, 0x80);//post gain limit，  c0                                                                                                                             
	write_cmos_sensor(0x22, 0x50);//pre gain limit    ,80                                                                                                                                                                                                            
	write_cmos_sensor(0x23, 0x88);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x24, 0x00);                                                                                                                                                                                                                          
	write_cmos_sensor(0x25, 0xaa);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x26, 0xcc);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x27, 0x16);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x28, 0x03); //                                                                                                                                                                                                                                                                    
	write_cmos_sensor(0x29, 0x18);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x2a, 0x03); //exp_level_1, 14fps                                                                                                                                                                                                                                                  
	write_cmos_sensor(0x2b, 0x18);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x2c, 0x06); //exp_level_2 , 7c4~7FPS, 58c~10FPS, 6a8~8.2FPS                                                                                                                                                                                                                       
	write_cmos_sensor(0x2d, 0xe0);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x2e, 0x06); //exp_level_3                                                                                                                                                                                                                                                         
	write_cmos_sensor(0x2f, 0xe0);                                                                                                                                                                                                                 
	write_cmos_sensor(0x30, 0x04);                                                                                                                                                                                                                                                                       
	write_cmos_sensor(0x31, 0x00);                                                                                                                                                                                                                                                                                                        
	write_cmos_sensor(0x32, 0x00); 
	write_cmos_sensor(0x33, 0x0f); 
	write_cmos_sensor(0x34, 0x40); //，
		//-Measure window-// 
	write_cmos_sensor(0xe0, 0x01); //window
	write_cmos_sensor(0xe1, 0x01); 
	write_cmos_sensor(0xe2, 0x28); 
	write_cmos_sensor(0xe3, 0x1e); 
	write_cmos_sensor(0xe4, 0x0a); 
	write_cmos_sensor(0xe5, 0x0a); 
	write_cmos_sensor(0xe6, 0x1e); 
	write_cmos_sensor(0xe7, 0x14); 
		//- PGA_table -//                                               
	write_cmos_sensor(0xf0, 0x01); //page1, PGA_table                                    
	write_cmos_sensor(0x00, 0x04);                                                       
	write_cmos_sensor(0x01, 0x00);                                                       
	write_cmos_sensor(0x02, 0x04);                                                       
	write_cmos_sensor(0x03, 0x00); //,                                
	write_cmos_sensor(0x04, 0x04); //
	write_cmos_sensor(0x05, 0x00); //,
	write_cmos_sensor(0x06, 0x04);                                                       
	write_cmos_sensor(0x07, 0x00); //,                                                   
	write_cmos_sensor(0x08, 0x04);                                                       
	write_cmos_sensor(0x09, 0x00);                                                       
	write_cmos_sensor(0x0a, 0x04);                                                       
	write_cmos_sensor(0x0b, 0x00);                                                       
	write_cmos_sensor(0x0c, 0x04);  //level6                                                       
	write_cmos_sensor(0x0d, 0x00);                                                       
	write_cmos_sensor(0x0e, 0x04);  //level7                                                    
	write_cmos_sensor(0x0f, 0x01);                                                      
	write_cmos_sensor(0x10, 0x00);                                                       
	write_cmos_sensor(0x11, 0x00);                                                       
	write_cmos_sensor(0x12, 0x00);                                                       
	write_cmos_sensor(0x13, 0x00);                                                       
	write_cmos_sensor(0x14, 0x00);                                                       
	write_cmos_sensor(0x15, 0x00);                                                       
	write_cmos_sensor(0x16, 0x00);                                                       
	write_cmos_sensor(0x17, 0x00); //end of page1 
	
		//--   ISP	--//
	write_cmos_sensor(0xF0, 0x00); //page0

	write_cmos_sensor(0x13, 0x00);
	write_cmos_sensor(0x40, 0x7e); 
	write_cmos_sensor(0x41, 0x2f); //[5]close ABS	  
	write_cmos_sensor(0x42, 0x30); 

	write_cmos_sensor(0x45, 0x25); 
	write_cmos_sensor(0x47, 0x00); 
	write_cmos_sensor(0x48, 0x00); 
	write_cmos_sensor(0x49, 0x00); 
	write_cmos_sensor(0x4a, 0x00); 
	write_cmos_sensor(0x4b, 0x00); 
	write_cmos_sensor(0x4d, 0x00); 
	write_cmos_sensor(0x4e, 0x23); 
	write_cmos_sensor(0x4f, 0x11);//0x21, //,
	write_cmos_sensor(0x50, 0x1a); //
	//write_cmos_sensor(0xb0, 0xe8); //0xf0,//, 
	write_cmos_sensor(0xb1, 0x40);
	write_cmos_sensor(0xb2, 0x20);
		//-open output-//
	write_cmos_sensor(0x43, 0x60);	
	write_cmos_sensor(0x44, 0xe2);
	
	write_cmos_sensor(0x59, 0x50);  //global offset
	write_cmos_sensor(0x35, 0x0d);
	write_cmos_sensor(0x36, 0x10);
	write_cmos_sensor(0x37, 0x08);
	write_cmos_sensor(0x38, 0x08);
	write_cmos_sensor(0x39, 0x08);
	write_cmos_sensor(0x3a, 0x08);
	write_cmos_sensor(0x35, 0x6d);
	write_cmos_sensor(0x59, 0x38);

	kal_sleep_task(20);
	write_cmos_sensor(0xc0, 0x00); 
	
}

#endif







