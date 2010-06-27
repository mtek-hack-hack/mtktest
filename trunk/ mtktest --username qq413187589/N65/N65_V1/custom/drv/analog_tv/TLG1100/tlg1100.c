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
#define YUV_SENSOR_SUPPORT 1

#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "sccb.h"
#include "isp_if.h"
#include "tlg1100.h"
#include "camera_para.h"
#include "upll_ctrl.h"
#include "med_api.h"


//#define __EV_LCD_WQVGA_RESOLUTION_SUPPORT__

#include "tlg1100api.h"
#include "tlg1100app.h"
#include "tlg1100i2c.h"

/*  2009.06.01 added by hongzhe.liu for tlg1100 gpio/gpo set +*/

extern const char gpio_tlg1100_power_en;
extern const char gpio_tlg1100_reset_pin;
extern const char gpio_tlg1100_i2c_scl;
extern const char gpio_tlg1100_i2c_sda;


#define SET_ANALOG_TV_CLK_OUTPUT		       GPIO_InitIO(OUTPUT,gpio_tlg1100_i2c_scl);
#define SET_ANALOG_TV_DATA_OUTPUT		GPIO_InitIO(OUTPUT,gpio_tlg1100_i2c_sda);
#define SET_ANALOG_TV_DATA_INPUT		       GPIO_InitIO(INPUT,gpio_tlg1100_i2c_sda);
#define SET_ANALOG_TV_CLK_HIGH			GPIO_WriteIO(1,gpio_tlg1100_i2c_scl);
#define SET_ANALOG_TV_CLK_LOW			       GPIO_WriteIO(0,gpio_tlg1100_i2c_scl);
#define SET_ANALOG_TV_DATA_HIGH			GPIO_WriteIO(1,gpio_tlg1100_i2c_sda);
#define SET_ANALOG_TV_DATA_LOW			GPIO_WriteIO(0,gpio_tlg1100_i2c_sda);
#define GET_ANALOG_TV_DATA_BIT			GPIO_ReadIO(gpio_tlg1100_i2c_sda)

/*  2009.06.01 added by hongzhe.liu for tlg1100 gpio/gpo set -*/

extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPIO_WriteIO(char data, char port);
extern void GPIO_InitIO(char direction, char port);
extern kal_uint8 mmi_analog_tv_get_selected_mode(void);

extern kal_uint8 mmi_get_analog_tv_selected_district(void);
extern kal_uint8  mmi_get_analog_tv_current_channel(void);
extern kal_bool mmi_analog_tv_is_full_screen(void);

/* analog tv chip ID */
kal_uint8 analog_tv_chip_id=0;
kal_uint8 analog_tv_start_grab_x_offset=0, analog_tv_start_grab_y_offset=0;
kal_bool analog_tv_MPEG4_encode_mode=KAL_FALSE;
kal_uint16 analog_tv_dummy_pixels=0, analog_tv_dummy_lines=0;
kal_uint32 analog_tv_i2c_addr = TLGI2C_DEFAULT_BASE_ADDR;

kal_bool  tv_chip_is_on=KAL_FALSE;
#ifdef OUTPUT_DEBUG_INFO
char analog_tv_temp_buffer[256];
extern int sprintf();
extern int rmmi_write_to_uart();
#endif
kal_bool Is_TV_Chip_Work_On(void)
{  
      return  tv_chip_is_on;

}

#if defined(HORSERACE_SUPPORT)
extern kal_bool  tv_fm_camera_is_power_on;
#endif /* HORSERACE_SUPPORT */

void gpio_tlg1100_power_en_on(kal_bool on)     
{
   if(on==KAL_TRUE)
   {
	if ((gpio_tlg1100_power_en & GPIO_MAGIC_NUM) == GPIO_MAGIC_NUM)
	{
		GPIO_InitIO(1, gpio_tlg1100_power_en);
		GPIO_ModeSetup(gpio_tlg1100_power_en, 0);
		GPIO_WriteIO(1, gpio_tlg1100_power_en);
	}
	else
	{
	     GPO_ModeSetup(gpio_tlg1100_power_en, 0);
	     GPO_WriteIO(1, gpio_tlg1100_power_en);	
	}
#if defined(HORSERACE_SUPPORT)
	tv_fm_camera_is_power_on = KAL_TRUE;
#endif /* HORSERACE_SUPPORT */
   }
   else
   {
	if ((gpio_tlg1100_power_en& GPIO_MAGIC_NUM) == GPIO_MAGIC_NUM)
	{
		GPIO_InitIO(1, gpio_tlg1100_power_en);
		GPIO_ModeSetup(gpio_tlg1100_power_en, 0);
		GPIO_WriteIO(0, gpio_tlg1100_power_en);
	}
	else
	{
	     GPO_ModeSetup(gpio_tlg1100_power_en, 0);
	     GPO_WriteIO(0, gpio_tlg1100_power_en);	
	}
#if defined(HORSERACE_SUPPORT)
	tv_fm_camera_is_power_on = KAL_FALSE;
#endif /* HORSERACE_SUPPORT */
     }  	
}

void tlg1100_reset(void)
 {
 	kal_uint16 iDelay;	
  
       GPIO_ModeSetup(gpio_tlg1100_reset_pin, 0);
	GPIO_InitIO(1, gpio_tlg1100_reset_pin);
	GPIO_WriteIO(1, gpio_tlg1100_reset_pin);
	for (iDelay = 0; iDelay < 100; iDelay++);
	GPIO_WriteIO(0, gpio_tlg1100_reset_pin);
	for (iDelay = 0; iDelay < 10000; iDelay++);
	GPIO_WriteIO(1, gpio_tlg1100_reset_pin);
        kal_sleep_task(2);
}

void  TLG1100_PowerOff(void);

void TLG1100_I2C_Test()
{
	unsigned short data = 10;
	unsigned short i = 10;
	while(i--){
		data = 10;
		TLGI2C_WriteReg(TLGI2C_DEFAULT_BASE_ADDR,0x189, 0x0007 );
		data = 0;
		TLGI2C_ReadReg(TLGI2C_DEFAULT_BASE_ADDR, 0x189, &data);
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\rI2c test : data = 0x%04x [should be 0x0007]\n" ,data);
#endif
		if( data == 0x0007 )
			return;
	}
}

/*We  need  check this  function  according HW design*/
void  TLG1100_PowerOn(void)
{
     kal_uint8  district_selected;


    if(Is_TV_Chip_Work_On()==KAL_TRUE)
    {
#if defined(NOKE_DEBUG)
	    	noke_dbg_printf("\r hongzhe.liu TLG1100_PowerOn ... Tv Started Already \n");
#endif
		TLG1100_PowerOff();
    }

	 
	
	gpio_tlg1100_power_en_on(KAL_TRUE);

	kal_sleep_task(4);				// To wait for Stable Power
	tlg1100_reset();	
	kal_sleep_task(4);
	GPIO_ModeSetup(gpio_tlg1100_i2c_scl,0);
	GPIO_ModeSetup(gpio_tlg1100_i2c_sda,0);
#if 0 //if debug
	TLG1100_I2C_Test(); //hongzhe.liu add for test
#endif
	  analog_tv_i2c_addr = TLGI2C_GetAddress();
        TLGAPP_Init(analog_tv_i2c_addr);
		
        //TLG_ReadReg(analog_tv_i2c_addr,0x0010,reg);	     
	//	if(*reg!=0x26c8)
	//		 return -1;	      		

    district_selected=mmi_get_analog_tv_selected_district();
	/*UNI@bw_20070614 重新整理地区列表并将巴西和阿根廷放到n制式里*/
	/*UNI@bw_20070607 添加地区并整理*/
	/*UNI@bw_20070515 19:36:11 整理更新地区列表*/
	if(district_selected>=ANALOG_TV_CHINA_START && district_selected<=ANALOG_TV_CHINA_END)		//china
  		TLGAPP_SetChannelMapChina();
	else if(district_selected>=ANALOG_TV_SHENZHEN_START&& district_selected<=ANALOG_TV_SHENZHEN_END)	//shengzhen
  		TLGAPP_SetChannelMapShenzhen();
  	else if(district_selected>=ANALOG_TV_EUROPE_START && district_selected<=ANALOG_TV_EUROPE_END)	//europe
  		TLGAPP_SetChannelMapEurope();
  	else if(district_selected>=ANALOG_TV_VIETNAM_START&& district_selected<=ANALOG_TV_VIETNAM_END)	//vietnam
  		TLGAPP_SetChannelMapVietnam();
	else if(district_selected>=ANALOG_TV_HONGKONG_START && district_selected<=ANALOG_TV_HONGKONG_END)  //Hongkong
		TLGAPP_SetChannelMapHongkong();
	else if(district_selected>=ANALOG_TV_AMERICA_START && district_selected<=ANALOG_TV_AMERICA_END) 	//usa
		TLGAPP_SetChannelMapAmerica();
	else if(district_selected>=ANALOG_TV_BRAZIL_START&& district_selected<=ANALOG_TV_BRAZIL_END)   //brazil
		TLGAPP_SetChannelMapBrazil();
	else if(district_selected>=ANALOG_TV_ARGENTINA_START&& district_selected<=ANALOG_TV_ARGENTINA_END)	//argentina
		TLGAPP_SetChannelMapArgentina();
	else if(district_selected>=ANALOG_TV_JAPAN_START&& district_selected<=ANALOG_TV_JAPAN_END)	//japan
		TLGAPP_SetChannelMapJapan();
  	else		//china
  		TLGAPP_SetChannelMapChina();

/*UNI@bw_20070514 17:17:13  添加5个地区列表*/
      tv_chip_is_on=KAL_TRUE;
	 
}

void  TLG1100_FM_PowerOn(void)
{

   GPIO_ModeSetup(gpio_tlg1100_i2c_scl,0);
   GPIO_ModeSetup(gpio_tlg1100_i2c_sda,0);

     gpio_tlg1100_power_en_on(KAL_TRUE);
   
     kal_sleep_task(4);				// To wait for Stable Power
     tlg1100_reset();
	kal_sleep_task(4);
	GPIO_ModeSetup(gpio_tlg1100_i2c_scl,0);
	GPIO_ModeSetup(gpio_tlg1100_i2c_sda,0);
     analog_tv_i2c_addr = TLGI2C_GetAddress();	   
     TLGAPP_Init(analog_tv_i2c_addr);
     
     TLGAPP_SetChannelMapFM();
    // TLGAPP_SetChannel(279);
    tv_chip_is_on=KAL_TRUE;
  
}

extern void cis_module_power_on(kal_bool on);
extern void HorseRace_PowerOff(void);

void  TLG1100_PowerOff(void)
{

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\rTLG1100_PowerOff: turn off...\n" );
#endif

	/*071104:1711 : 
		Ensure the last call for the tv chip is SetChannel before power down.
		This avoid the reentering tv app tuning fail.
	*/
	//----TLGAPP_SetChannel(mmi_get_analog_tv_current_channel());

       tlg1100_reset();
       kal_sleep_task(10);       
       if(GetCurrentState()!=2) //P_6226_M38_bw_Z0002 解决TV状态下来电接不通  2==CM_INCOMING_STATE 
        {
           TLGAPP_PowerDown();
        }   

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\rTLG1100_PowerOff: after TLGAPP_PowerDown()...\n" );
#endif
	
      gpio_tlg1100_power_en_on(KAL_FALSE);      	 
#if 1 //hongzhe.liu
	cis_module_power_on(KAL_FALSE) ;
#else
	GPIO_ModeSetup(gpio_tlg1100_i2c_scl,0);
	GPIO_InitIO(1, gpio_tlg1100_i2c_scl);		
	GPIO_WriteIO(0, gpio_tlg1100_i2c_scl);		

	GPIO_ModeSetup(gpio_tlg1100_i2c_sda,0);		
	GPIO_InitIO(1, gpio_tlg1100_i2c_sda);	
	GPIO_WriteIO(0, gpio_tlg1100_i2c_sda);		
#endif	
       tv_chip_is_on=KAL_FALSE;
}


void AnalogTV_PowerOff_Close_I2C_Leakage(void)
{
#if 1 //hongzhe.liu
	gpio_tlg1100_power_en_on(KAL_FALSE); 
	cis_module_power_on(KAL_FALSE) ;
#else
	GPIO_ModeSetup(gpio_tlg1100_i2c_scl,0);
	GPIO_InitIO(1, gpio_tlg1100_i2c_scl);		
	GPIO_WriteIO(0, gpio_tlg1100_i2c_scl);		

	GPIO_ModeSetup(gpio_tlg1100_i2c_sda,0);		
	GPIO_InitIO(1, gpio_tlg1100_i2c_sda);	
	GPIO_WriteIO(0, gpio_tlg1100_i2c_sda);	
#endif	
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Huyanwei Debg Exit TV Leakage .....\r\n");
#endif
}


void AnalogTV_PowerOff_CloseLeakage(void)
{

	gpio_tlg1100_power_en_on(KAL_TRUE);
	kal_sleep_task(4);				// To wait for Stable Power
	tlg1100_reset();	
	kal_sleep_task(4);
	GPIO_ModeSetup(gpio_tlg1100_i2c_scl,0);
	GPIO_ModeSetup(gpio_tlg1100_i2c_sda,0);

	analog_tv_i2c_addr = TLGI2C_GetAddress();
       TLGAPP_Init(analog_tv_i2c_addr);

      tv_chip_is_on=KAL_TRUE;
	   
	kal_sleep_task(100);
	if(GetCurrentState()!=2) //P_6226_M38_bw_Z0002 解决TV状态下来电接不通  2==CM_INCOMING_STATE 
       {
           TLGAPP_PowerDown();
       }   
	kal_sleep_task(2);	
       SET_ANALOG_TV_CLK_LOW;   //Avoid current Leakage
       SET_ANALOG_TV_DATA_LOW;
       kal_sleep_task(2);
       gpio_tlg1100_power_en_on(KAL_FALSE);      
       tv_chip_is_on=KAL_FALSE;	


}




void power_off_analog_tv(void)
{
	TLG1100_PowerOff();	   
}	

kal_int8 init_analog_tv(void)
{

	int ret; 
     
    /*UHF&VHF*/

       ENABLE_CAMERA_INDATA_FORMAT;
       SET_CAMERA_INPUT_TYPE(INPUT_YUV422);
     
	SET_CMOS_CLOCK_POLARITY_LOW;
//	SET_VSYNC_POLARITY_LOW;  //low active
//	SET_HSYNC_POLARITY_LOW;  //low active
	SET_VSYNC_POLARITY_HIGH;  //high active
	SET_HSYNC_POLARITY_HIGH;  //high active 
	set_isp_driving_current(ISP_DRIVING_8MA);   
	set_isp_interrupt_trigger_delay_lines(1);

	
	TLG1100_PowerOn();

	if ( tv_chip_is_on )
	{
		TLGAPP_SetChannel(mmi_get_analog_tv_current_channel());
	}

	return 1;
}
	
#include "device.h"
#include "l1audio.h"
void  analog_tv_preview(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	
           kal_uint8  district_selected;


	
		ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;		
		//SET_TG_PIXEL_CLK_DIVIDER(3);
		//SET_CMOS_DATA_LATCH(2);	      	
		SET_CAMERA_INPUT_ORDER(INPUT_ORDER_YCrY1Cb);

	      TLG_SetCbCrOrder( tlg_i2c_addr, TLG_CBCR_SWAP );

            /*UNI@bw070428  NTSC 和 PAL 分开*/
                district_selected=mmi_get_analog_tv_selected_district();
		/*UNI@bw_20070614 重新整理地区列表并将巴西和阿根廷放到n制式里*/
		/*UNI@bw_20070607 添加地区并整理*/
		/*UNI@bw_20070515 19:36:11 整理更新地区列表*/
		//district_selected>=ANLAOG_TV_NTSL_START && district_selected>=ANLAOG_TV_NTSL_START	
                if(district_selected>=ANLAOG_TV_NTSL_START && district_selected<=ANALOG_TV_NTSL_END)
                {
               #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__) 
		     if((mmi_analog_tv_is_full_screen()==1)&&(mmi_analog_tv_is_320_240_screen()==0)) //400*420
                    {
                    TLG_SetExtHSync(analog_tv_i2c_addr, 139, 858, 1, 20, 264, 525);
                    TLG_SetExtVSync(analog_tv_i2c_addr, 1, 20, 0, 0, 0, 0);
	            TLG_SetHDecimate(analog_tv_i2c_addr, 0);
		    image_window->grab_start_x=5;    
	            image_window->grab_start_y=4;   
	              image_window->exposure_window_width=704;   
	              image_window->exposure_window_height=232; 
			  
		       }
			  else   //320*240 or  240*196
			  {
               	#endif /*__EV_LCD_WQVGA_RESOLUTION_SUPPORT__*/

			/*
		  	TLG_SetExtHSync(analog_tv_i2c_addr, 139, 858, 1, 20, 264, 525);
                  	TLG_SetExtVSync(analog_tv_i2c_addr, 1, 20, 0, 0, 0, 0);
	          	TLG_SetHDecimate(analog_tv_i2c_addr, 1);
			*/
			TLG_SetQVGA_NTSC(analog_tv_i2c_addr);
               	
                  image_window->grab_start_x=5;    
	          image_window->grab_start_y=4;   
	          image_window->exposure_window_width=352;   
	          image_window->exposure_window_height=232;
                }
           #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__) 
                }
           #endif /*__EV_LCD_WQVGA_RESOLUTION_SUPPORT__*/
                else
                {
                
            #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__) 
                  if((mmi_analog_tv_is_full_screen()==1)&&(mmi_analog_tv_is_320_240_screen()==0)) //400*420
                    {
                    TLG_SetExtHSync(analog_tv_i2c_addr, 145, 864, 1, 22, 311, 625);
                    TLG_SetExtVSync(analog_tv_i2c_addr, 1, 22, 0, 0, 0, 0);
	             TLG_SetHDecimate(analog_tv_i2c_addr, 0);
		       image_window->grab_start_x=17;    
	              image_window->grab_start_y=16;    
                    image_window->exposure_window_width=640;   
	             image_window->exposure_window_height=264;   	  
		       }
			else   //320*240 or  240*196  
			{
             #endif /*__EV_LCD_WQVGA_RESOLUTION_SUPPORT__*/

			/* set TLG_SetExtHSync second param to 146 caused the color turn to green, so change to 145 */
			 //TLG_SetExtHSync(analog_tv_i2c_addr, 146, 864, 1, 22, 311, 625);
			 /*
			 TLG_SetExtHSync(analog_tv_i2c_addr, 146, 864, 1, 22, 311, 625);
                      TLG_SetExtVSync(analog_tv_i2c_addr, 1, 22, 0, 0, 0, 0);
	               TLG_SetHDecimate(analog_tv_i2c_addr, 1);
	               */
			TLG_SetQVGA_PAL(analog_tv_i2c_addr);
				 
		image_window->grab_start_x=16;    
	        image_window->grab_start_y=16;    
                image_window->exposure_window_width=340;   
	        image_window->exposure_window_height=264;   
              #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__) 
                }
              #endif /*__EV_LCD_WQVGA_RESOLUTION_SUPPORT__*/

	    }


#ifdef ANALOG_TV_TEST_PATTERN_MODE
	TLGAPP_TurnOnTestPattern();
#endif
#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\ranalog_tv_preview exit \n"  );
#endif
}	


/***************************************************************
funtion name:get_analog_tv_period 
purpose: called by video_enc_dma_lisr() in mpeg4 encode procedure
*****************************************************************/
void get_analog_tv_period(kal_uint16 *pixel_number, kal_uint16 *line_number)
{
        //*pixel_number=TVIN_PERIOD_PIXEL_NUMS;			/* pixel numbers in one period of HSYNC */
	// *line_number=TVIN_PERIOD_LINE_NUMS;				/* line numbers in one period of VSYNC */
}	

void get_analog_tv_size(kal_uint16 *sensor_width, kal_uint16 *sensor_height)
{
	*sensor_width=640;			/* pixel numbers actually used in one frame */
	*sensor_height=480;		/* line numbers actually used in one frame */
}

void get_analog_tv_id(kal_uint8 *sensor_write_id, kal_uint8 *sensor_read_id)
{
	//Todo
}
void analog_tv_capture(image_sensor_exposure_window_struct *image_window, image_sensor_config_struct *sensor_config_data)
{
	//Todo
	/* config TG of ISP to match the setting of image sensor*/
#if 0
		ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;		
		SET_TG_PIXEL_CLK_DIVIDER(3);
		SET_CMOS_DATA_LATCH(2);		      	
	
	image_window->grab_start_x = 0;
	image_window->grab_start_y = 1;
	image_window->exposure_window_width=0x160;    	
	image_window->exposure_window_height=0xe8;
#endif	
}

void write_analog_tv_reg(kal_uint32 addr, kal_uint32 para)
{
	//Todo
}
kal_uint32 read_analog_tv_reg(kal_uint32 addr)
{
	//Todo
	 
  
	return KAL_TRUE;
}
void set_analog_tv_shutter(kal_uint16 shutter)
{
}
void analog_tv_night_mode(kal_bool enable)
{
	//Todo
}


kal_uint16 set_analog_tv_gain(kal_uint16 gain)
{
	
}
void set_analog_tv_flashlight(kal_bool enable)
{
	// Todo
}

/*************************************************************************
* FUNCTION
*	set_analog_tv_param_contrast
*
* DESCRIPTION
*	analog tv  contrast setting.
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
kal_uint32 set_analog_tv_contrast(kal_uint32 para)
{

	
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_analog_tv_param_brightness
*
* DESCRIPTION
*	analog tv brightness setting.
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
kal_uint32 set_analog_tv_brightness(kal_uint32 para)
{
    


	return KAL_TRUE;	
}


/*************************************************************************
* FUNCTION
*	set_analog_tv_param_hue
*
* DESCRIPTION
*	analog tv hue setting.
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
kal_uint32 set_analog_tv_hue(kal_uint32 para)
{
	// Todo
    
		
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_analog_tv_param_saturation
*
* DESCRIPTION
*	analog tv SATURATION setting.
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
kal_uint32 set_analog_tv_saturation(kal_uint32 para)
{
   
	
	return KAL_TRUE;	
}

/*************************************************************************
* FUNCTION
*	set_analog_tv_param_banding
*
* DESCRIPTION
*	analog tv banding setting.
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
kal_uint32 analog_tv_yuv_sensor_setting(kal_uint32 cmd, kal_uint32 para)
{
	 //Todo
	
	kal_uint32 ret = KAL_TRUE;
	
	return ret;

}

/************************************************************
description: keep analog tv the same struct with sensor,if not use,clear the content.

***************************************************************/
image_sensor_func_struct image_sensor_func_tlg1100 =
{
	init_analog_tv,
	get_analog_tv_id,
	get_analog_tv_size,
	get_analog_tv_period,
	analog_tv_preview,
	analog_tv_capture,
	write_analog_tv_reg,
	read_analog_tv_reg,
	set_analog_tv_shutter,
	analog_tv_night_mode,
	power_off_analog_tv,
	set_analog_tv_gain,
	set_analog_tv_flashlight,
	analog_tv_yuv_sensor_setting
};	


void analog_tv_func_config(void)
{
	image_sensor_func=&image_sensor_func_tlg1100;
	/* cam_module_func_config() */
}
