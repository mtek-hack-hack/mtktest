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

#include "custom_mmi_default_value.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



kal_uint8  start_grab_x_offset=0, start_grab_y_offset=0;
kal_bool   gVGAmode=KAL_TRUE, sensor_night_mode=KAL_FALSE, MPEG4_encode_mode=KAL_FALSE, g_bMJPEG_mode = KAL_FALSE;
kal_uint8  normal_gain=0, night_gain=SENSOR_NIGHT_MODE_GAIN;
kal_uint8  preview_pclk_division=0, capture_pclk_division=0;
kal_uint16 dummy_pixels=0, dummy_lines=0, extra_exposure_lines=0;
kal_uint16 exposure_lines=0;
kal_uint16 sensor_global_gain=BASEGAIN, sensor_gain_base=0x0;
/* Debug Message, Don't Care */
kal_uint16 sensor_frame_rate;

/* MAX/MIN Explosure Lines Used By AE Algorithm */
kal_uint16 MAX_EXPOSURE_LINES=(PIXEL_CLK/MIN_FRAME_RATE)/VGA_PERIOD_PIXEL_NUMS;
kal_uint8  MIN_EXPOSURE_LINES=2;
/* Parameter For Engineer mode function */
kal_uint32 FAC_SENSOR_REG;
/* Image Sensor ID */
kal_uint16 sensor_id=0;
kal_bool sensor_cap_state=KAL_FALSE;
kal_uint8 hejctest = 1;

kal_bool gc_effect_on = KAL_FALSE ;
kal_bool gc_reinit  = KAL_FALSE;
kal_uint16 w_blank = 0 ;
kal_uint16 h_blank = 0 ;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#ifdef DOUBLE_CAMERA_SUPPORT

#ifndef WIN32
extern kal_bool mmi_polling_active_camera(void);
#endif

 /* 当sub camera不存在能够使用main camera*/
kal_bool main_camera_is_ready=KAL_TRUE;
kal_bool sub_camera_is_ready=KAL_TRUE;
kal_bool main_camera_active=KAL_TRUE;
kal_bool   sub_camera_is_ready_polling(void)
{
	return  sub_camera_is_ready;
}
kal_bool   main_camera_is_ready_polling(void)
{
	return  main_camera_is_ready;
}
  
#endif /* DOUBLE_CAMERA_SUPPORT */

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

kal_uint16 Main_Camera_Id_Type = 0;
noke_drv_camera_info_struct noke_drv_main_camera_info_array[MAIN_CAMERA_INFO_ARRAY_SIZE+1];


#if defined(DOUBLE_CAMERA_SUPPORT)
extern kal_bool  mmi_main_camera_active; 
kal_uint16 Sub_Camera_Id_Type = 0;
noke_drv_camera_info_struct noke_drv_sub_camera_info_array[SUB_CAMERA_INFO_ARRAY_SIZE+1];
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

kal_uint16 Sensor_write_id = 0x0042;
kal_uint16 Sensor_read_id = 0x0043;

#ifndef HW_SCCB

void SCCB_send_byte(kal_uint8 send_byte)
{
	volatile signed char i;
	volatile kal_uint32 j;

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (send_byte & (1<<i))
		{
			SET_SCCB_DATA_HIGH;
		}
		else
		{
			SET_SCCB_DATA_LOW;
		}
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SET_SCCB_CLK_HIGH;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SET_SCCB_CLK_LOW;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
	}
	/* don't care bit, 9th bit */
	SET_SCCB_DATA_LOW;
	SET_SCCB_DATA_INPUT;
	SET_SCCB_CLK_HIGH;
	for(j=0;j<SENSOR_I2C_DELAY;j++);
	SET_SCCB_CLK_LOW;
	SET_SCCB_DATA_OUTPUT;
}	/* SCCB_send_byte() */

kal_uint8 SCCB_get_byte(void)
{
	volatile signed char i;
	volatile kal_uint32 j;
	kal_uint8 get_byte=0;

	SET_SCCB_DATA_INPUT;

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		SET_SCCB_CLK_HIGH;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		if (GET_SCCB_DATA_BIT)
			get_byte |= (1<<i);
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SET_SCCB_CLK_LOW;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
	}
	/* don't care bit, 9th bit */
	SET_SCCB_DATA_OUTPUT;
	SET_SCCB_DATA_HIGH;
	for(j=0;j<SENSOR_I2C_DELAY;j++);
	SET_SCCB_CLK_HIGH;
	for(j=0;j<SENSOR_I2C_DELAY;j++);
	SET_SCCB_CLK_LOW;

	return get_byte;
}	/* SCCB_get_byte() */

#endif

void write_cmos_sensor(kal_uint32 addr, kal_uint32 para)
{
	volatile kal_uint32 j;
	
	#ifdef HW_SCCB
		SET_SCCB_DATA_LENGTH(3);
		ENABLE_SCCB;
		REG_SCCB_DATA = Sensor_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = addr;
		REG_SCCB_DATA = para;
		while (SCCB_IS_WRITTING) {};
	#else
		I2C_START_TRANSMISSION;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SCCB_send_byte(Sensor_write_id);
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SCCB_send_byte(addr);
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SCCB_send_byte(para);
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		I2C_STOP_TRANSMISSION;
	#endif /* HW_SCCB */
}	/* write_cmos_sensor() */

kal_uint32 read_cmos_sensor(kal_uint32 addr)
{
	volatile kal_uint32 j;
	kal_uint8 get_byte=0;
	
	#ifdef HW_SCCB
		SET_SCCB_DATA_LENGTH(2);
		ENABLE_SCCB;
		REG_SCCB_DATA = Sensor_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = addr;
		while (SCCB_IS_WRITTING) {};
		ENABLE_SCCB;
		REG_SCCB_DATA = Sensor_read_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA=0;
		while (SCCB_IS_READING) {};
		get_byte = REG_SCCB_READ_DATA & 0xFF;
	#else
		I2C_START_TRANSMISSION;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SCCB_send_byte(Sensor_write_id);
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SCCB_send_byte(addr);
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		I2C_STOP_TRANSMISSION;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		I2C_START_TRANSMISSION;
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		SCCB_send_byte(Sensor_read_id);
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		get_byte=SCCB_get_byte();
		for(j=0;j<SENSOR_I2C_DELAY;j++);
		I2C_STOP_TRANSMISSION;
	#endif

	return get_byte;
}	/* read_cmos_sensor() */


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


#include "image_sensor_OV7670.h"	
#include "image_sensor_OV7680.h"	
#include "image_sensor_BF3403.h"	
#include "image_sensor_BF3503.h"	
#include "image_sensor_BF3603.h"	
#include "image_sensor_GC0316.h"	
#include "image_sensor_GC0307.h"	


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

noke_drv_camera_info_struct noke_drv_main_camera_info_array[MAIN_CAMERA_INFO_ARRAY_SIZE+1]={
	{
		ID_MAIN_CAMERA_OV7670_DEFAULT, "OV7670 default main camera", 
		OV7670_SENSOR_ID,OV7670_WRITE_ID,OV7670_READ_ID,CMOS_SENSOR,
		&image_sensor_func_OV7670,
		camera_para_to_sensor_OV7670,
		sensor_to_camera_para_OV7670,
		get_sensor_group_count_OV7670,
		get_sensor_group_info_OV7670,
		get_sensor_item_info_OV7670,
		set_sensor_item_info_OV7670,
		is_sensor_ready_OV7670,
		main_camera_ov7670_init_func_default
	}, 
	{
		ID_MAIN_CAMERA_OV7680_DEFAULT, "OV7680 default main camera", 
		OV7680_SENSOR_ID,OV7680_WRITE_ID,OV7680_READ_ID,CMOS_SENSOR,
		&image_sensor_func_OV7680,
		camera_para_to_sensor_OV7680,
		sensor_to_camera_para_OV7680,
		get_sensor_group_count_OV7680,
		get_sensor_group_info_OV7680,
		get_sensor_item_info_OV7680,
		set_sensor_item_info_OV7680,
		is_sensor_ready_OV7680,
		main_camera_ov7680_init_func_default
	}, 
	{
		ID_MAIN_CAMERA_BF3403_DEFAULT, "BF3403 default main camera", 
		BF3403_SENSOR_ID,BF3403_WRITE_ID,BF3403_READ_ID,CMOS_SENSOR,
		&image_sensor_func_BF3403,
		camera_para_to_sensor_BF3403,
		sensor_to_camera_para_BF3403,
		get_sensor_group_count_BF3403,
		get_sensor_group_info_BF3403,
		get_sensor_item_info_BF3403,
		set_sensor_item_info_BF3403,
		is_sensor_ready_BF3403,
		main_camera_bf3403_init_func_default
	}, 
	{
		ID_MAIN_CAMERA_BF3503_DEFAULT, "BF3503 default main camera", 
		BF3503_SENSOR_ID,BF3503_WRITE_ID,BF3503_READ_ID,CMOS_SENSOR,
		&image_sensor_func_BF3503,
		camera_para_to_sensor_BF3503,
		sensor_to_camera_para_BF3503,
		get_sensor_group_count_BF3503,
		get_sensor_group_info_BF3503,
		get_sensor_item_info_BF3503,
		set_sensor_item_info_BF3503,
		is_sensor_ready_BF3503,
		main_camera_bf3503_init_func_default
	}, 
	{
		ID_MAIN_CAMERA_BF3603_DEFAULT, "BF3603 default main camera", 
		BF3603_SENSOR_ID,BF3603_WRITE_ID,BF3603_READ_ID,CMOS_SENSOR,
		&image_sensor_func_BF3603,
		camera_para_to_sensor_BF3603,
		sensor_to_camera_para_BF3603,
		get_sensor_group_count_BF3603,
		get_sensor_group_info_BF3603,
		get_sensor_item_info_BF3603,
		set_sensor_item_info_BF3603,
		is_sensor_ready_BF3603,
		main_camera_bf3603_init_func_default
	}, 
	{
		ID_MAIN_CAMERA_GC0316_DEFAULT, "GC0316 default main camera", 
		GC0316_SENSOR_ID,GC0316_WRITE_ID,GC0316_READ_ID,CMOS_SENSOR,
		&image_sensor_func_GC0316,
		camera_para_to_sensor_GC0316,
		sensor_to_camera_para_GC0316,
		get_sensor_group_count_GC0316,
		get_sensor_group_info_GC0316,
		get_sensor_item_info_GC0316,
		set_sensor_item_info_GC0316,
		is_sensor_ready_GC0316,
		main_camera_gc0316_init_func_default
	}, 
	{
		ID_MAIN_CAMERA_GC0307_DEFAULT, "GC0307 default main camera", 
		GC0307_SENSOR_ID,GC0307_WRITE_ID,GC0307_READ_ID,CMOS_SENSOR,
		&image_sensor_func_GC0307,
		camera_para_to_sensor_GC0307,
		sensor_to_camera_para_GC0307,
		get_sensor_group_count_GC0307,
		get_sensor_group_info_GC0307,
		get_sensor_item_info_GC0307,
		set_sensor_item_info_GC0307,
		is_sensor_ready_GC0307,
		main_camera_gc0307_init_func_default
	}, 
	{
		ID_MAIN_CAMERA_MAX, "ERROR", 
	}
};

#if defined(DOUBLE_CAMERA_SUPPORT)
noke_drv_camera_info_struct noke_drv_sub_camera_info_array[SUB_CAMERA_INFO_ARRAY_SIZE+1]={
	/*ID_SUB_CAMERA_OV7670_DEFAULT*/
	{
		ID_SUB_CAMERA_OV7670_DEFAULT, "OV7670 default sub camera", 
		OV7670_SENSOR_ID,OV7670_WRITE_ID,OV7670_READ_ID,CMOS_SENSOR,
		&image_sensor_func_OV7670,
		camera_para_to_sensor_OV7670,
		sensor_to_camera_para_OV7670,
		get_sensor_group_count_OV7670,
		get_sensor_group_info_OV7670,
		get_sensor_item_info_OV7670,
		set_sensor_item_info_OV7670,
		is_sensor_ready_OV7670,
		sub_camera_ov7670_init_func_default
	}, 
	{
		ID_SUB_CAMERA_OV7680_DEFAULT, "OV7680 default sub camera", 
		OV7680_SENSOR_ID,OV7680_WRITE_ID,OV7680_READ_ID,CMOS_SENSOR,
		&image_sensor_func_OV7680,
		camera_para_to_sensor_OV7680,
		sensor_to_camera_para_OV7680,
		get_sensor_group_count_OV7680,
		get_sensor_group_info_OV7680,
		get_sensor_item_info_OV7680,
		set_sensor_item_info_OV7680,
		is_sensor_ready_OV7680,
		sub_camera_ov7680_init_func_default
	}, 
	{
		ID_SUB_CAMERA_BF3403_DEFAULT, "BF3403 default sub camera", 
		BF3403_SENSOR_ID,BF3403_WRITE_ID,BF3403_READ_ID,CMOS_SENSOR,
		&image_sensor_func_BF3403,
		camera_para_to_sensor_BF3403,
		sensor_to_camera_para_BF3403,
		get_sensor_group_count_BF3403,
		get_sensor_group_info_BF3403,
		get_sensor_item_info_BF3403,
		set_sensor_item_info_BF3403,
		is_sensor_ready_BF3403,
		sub_camera_bf3403_init_func_default
	}, 
	{
		ID_SUB_CAMERA_BF3503_DEFAULT, "BF3503 default sub camera", 
		BF3503_SENSOR_ID,BF3503_WRITE_ID,BF3503_READ_ID,CMOS_SENSOR,
		&image_sensor_func_BF3503,
		camera_para_to_sensor_BF3503,
		sensor_to_camera_para_BF3503,
		get_sensor_group_count_BF3503,
		get_sensor_group_info_BF3503,
		get_sensor_item_info_BF3503,
		set_sensor_item_info_BF3503,
		is_sensor_ready_BF3503,
		sub_camera_bf3503_init_func_default
	}, 
	{
		ID_SUB_CAMERA_BF3603_DEFAULT, "BF3603 default sub camera", 
		BF3603_SENSOR_ID,BF3603_WRITE_ID,BF3603_READ_ID,CMOS_SENSOR,
		&image_sensor_func_BF3603,
		camera_para_to_sensor_BF3603,
		sensor_to_camera_para_BF3603,
		get_sensor_group_count_BF3603,
		get_sensor_group_info_BF3603,
		get_sensor_item_info_BF3603,
		set_sensor_item_info_BF3603,
		is_sensor_ready_BF3603,
		sub_camera_bf3603_init_func_default
	}, 
	{
		ID_SUB_CAMERA_GC0316_DEFAULT, "GC0316 default sub camera", 
		GC0316_SENSOR_ID,GC0316_WRITE_ID,GC0316_READ_ID,CMOS_SENSOR,
		&image_sensor_func_GC0316,
		camera_para_to_sensor_GC0316,
		sensor_to_camera_para_GC0316,
		get_sensor_group_count_GC0316,
		get_sensor_group_info_GC0316,
		get_sensor_item_info_GC0316,
		set_sensor_item_info_GC0316,
		is_sensor_ready_GC0316,
		sub_camera_gc0316_init_func_default
	}, 
	{
		ID_SUB_CAMERA_GC0307_DEFAULT, "GC0307 default sub camera", 
		GC0307_SENSOR_ID,GC0307_WRITE_ID,GC0307_READ_ID,CMOS_SENSOR,
		&image_sensor_func_GC0307,
		camera_para_to_sensor_GC0307,
		sensor_to_camera_para_GC0307,
		get_sensor_group_count_GC0307,
		get_sensor_group_info_GC0307,
		get_sensor_item_info_GC0307,
		set_sensor_item_info_GC0307,
		is_sensor_ready_GC0307,
		sub_camera_gc0307_init_func_default
	}, 
	{
		ID_SUB_CAMERA_MAX, "ERROR", 
	}
};
#endif



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


extern S16 noke_drv_nvram_value_asscess_req(
	kal_bool is_write,
	U8 nDataItemId, 
	void * pDataBuffer, 
	U8 nDataType   /* 1 = DS_BYTE   2 = DS_SHORT  8 = DS_DOUBLE */
);



static void init_image_sensor_id()
{
	S16 error;
	kal_uint16 sensor_id=0xFFFF;
	//ReadValueInt(NVRAM_CAMERA_MODULE_ID, &sensor_id, 2 /* DS_SHORT */, &error, __FILE__, __LINE__);

	//error = noke_drv_nvram_value_asscess_req( KAL_FALSE, NVRAM_CAMERA_MODULE_ID,  &sensor_id, 2 );

	Main_Camera_Id_Type = sensor_id & 0x00FF;
#if defined(DOUBLE_CAMERA_SUPPORT)
	Sub_Camera_Id_Type = (sensor_id&0xFF00) >> 8 ;
#endif


#ifdef NOKE_DEBUG
#if defined(DOUBLE_CAMERA_SUPPORT)
	noke_dbg_printf("\rHongzhe.Liu : read camera ID : [0x%02x] [0x%02x] \n",  Main_Camera_Id_Type, Sub_Camera_Id_Type );
#else
	noke_dbg_printf("\rHongzhe.Liu : read camera ID : [0x%02x]  \n",  Main_Camera_Id_Type );
#endif
#endif

	if( 0xFF == Main_Camera_Id_Type
		|| Main_Camera_Id_Type >= ID_MAIN_CAMERA_MAX
#if defined(DOUBLE_CAMERA_SUPPORT)
		|| 0xFF == Sub_Camera_Id_Type
		|| Sub_Camera_Id_Type >= ID_SUB_CAMERA_MAX		
#endif
		||  1 /* NVRAM_READ_SUCCESS */!=error
	)
	{
#if (MAIN_CAMERA == OV7670)
		Main_Camera_Id_Type = ID_MAIN_CAMERA_OV7670_DEFAULT;
#endif
#if (MAIN_CAMERA == OV7680)
		Main_Camera_Id_Type = ID_MAIN_CAMERA_OV7680_DEFAULT;
#endif
#if (MAIN_CAMERA == BF3403)
		Main_Camera_Id_Type = ID_MAIN_CAMERA_BF3403_DEFAULT;
#endif
#if (MAIN_CAMERA == BF3503)
		Main_Camera_Id_Type = ID_MAIN_CAMERA_BF3503_DEFAULT;
#endif
#if (MAIN_CAMERA == GC0316)
		Main_Camera_Id_Type = ID_MAIN_CAMERA_GC0316_DEFAULT;
#endif
#if (MAIN_CAMERA == GC0307)
		Main_Camera_Id_Type = ID_MAIN_CAMERA_GC0307_DEFAULT;
#endif
#if defined(DOUBLE_CAMERA_SUPPORT)
	#if (SUB_CAMERA == OV7670)
		Sub_Camera_Id_Type = ID_SUB_CAMERA_OV7670_DEFAULT;
	#endif			
	#if (SUB_CAMERA == OV7680)
		Sub_Camera_Id_Type = ID_SUB_CAMERA_OV7680_DEFAULT;
	#endif	
	#if (SUB_CAMERA == BF3403)
		Sub_Camera_Id_Type = ID_SUB_CAMERA_BF3403_DEFAULT;
	#endif	
	#if (SUB_CAMERA == BF3503)
		Sub_Camera_Id_Type = ID_SUB_CAMERA_BF3503_DEFAULT;
	#endif	
	#if (SUB_CAMERA == GC0316)
		Sub_Camera_Id_Type = ID_SUB_CAMERA_GC0316_DEFAULT;
	#endif			
	#if (SUB_CAMERA == GC0307)
		Sub_Camera_Id_Type = ID_SUB_CAMERA_GC0307_DEFAULT;
	#endif			
#endif
	}

#ifdef NOKE_DEBUG
#if defined(DOUBLE_CAMERA_SUPPORT)
	noke_dbg_printf("\rHongzhe.Liu : camera ID : [0x%02x] [0x%02x] \n",  Main_Camera_Id_Type, Sub_Camera_Id_Type );
#else
	noke_dbg_printf("\rHongzhe.Liu : camera ID : [0x%02x]  \n",  Main_Camera_Id_Type );
#endif
#endif

	if( NULL == noke_drv_main_camera_info_array[Main_Camera_Id_Type]. image_sensor_func
#if defined(DOUBLE_CAMERA_SUPPORT)
		|| NULL == noke_drv_sub_camera_info_array[Sub_Camera_Id_Type]. image_sensor_func
#endif
	)
	{
#ifdef NOKE_DEBUG
		noke_dbg_printf("\rHongzhe.Liu : camera func is NULL\n");
#endif
		ASSERT(0);
	}

}

void image_sensor_func_config(void)
{
	init_image_sensor_id();
	
#if !defined(DOUBLE_CAMERA_SUPPORT)	
	image_sensor_func=noke_drv_main_camera_info_array[Main_Camera_Id_Type].image_sensor_func;
	Sensor_write_id = noke_drv_main_camera_info_array[Main_Camera_Id_Type].sensor_write_id;
	Sensor_read_id = noke_drv_main_camera_info_array[Main_Camera_Id_Type].sensor_read_id;
#else
	if(mmi_main_camera_active == KAL_TRUE )
	{
		image_sensor_func=noke_drv_main_camera_info_array[Main_Camera_Id_Type].image_sensor_func;
		Sensor_write_id = noke_drv_main_camera_info_array[Main_Camera_Id_Type].sensor_write_id;
		Sensor_read_id = noke_drv_main_camera_info_array[Main_Camera_Id_Type].sensor_read_id;
	}
	else
	{
		image_sensor_func=noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].image_sensor_func;
		Sensor_write_id = noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].sensor_write_id;
		Sensor_read_id = noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].sensor_read_id;
	}
#endif	
}	

// write camera_para to sensor register
void camera_para_to_sensor(void)
{
#if !defined(DOUBLE_CAMERA_SUPPORT)	
	noke_drv_main_camera_info_array[Main_Camera_Id_Type].camera_para_to_sensor();
#else
	if(mmi_main_camera_active == KAL_TRUE )
	{
		noke_drv_main_camera_info_array[Main_Camera_Id_Type].camera_para_to_sensor();
	}
	else
	{
		noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].camera_para_to_sensor();
	}
#endif	
}

// update camera_para from sensor register
void sensor_to_camera_para(void)
{
#if !defined(DOUBLE_CAMERA_SUPPORT)	
	noke_drv_main_camera_info_array[Main_Camera_Id_Type].sensor_to_camera_para();
#else
	if(mmi_main_camera_active == KAL_TRUE )
	{
		noke_drv_main_camera_info_array[Main_Camera_Id_Type].sensor_to_camera_para();
	}
	else
	{
		noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].sensor_to_camera_para();
	}
#endif	
}

//------------------------Engineer mode---------------------------------

void  get_sensor_group_count(kal_int32* sensor_count_ptr)
{
#if !defined(DOUBLE_CAMERA_SUPPORT)	
	noke_drv_main_camera_info_array[Main_Camera_Id_Type].get_sensor_group_count(sensor_count_ptr);
#else
	if(mmi_main_camera_active == KAL_TRUE )
	{
		noke_drv_main_camera_info_array[Main_Camera_Id_Type].get_sensor_group_count(sensor_count_ptr);
	}
	else
	{
		noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].get_sensor_group_count(sensor_count_ptr);
	}
#endif	
}

void get_sensor_group_info(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
#if !defined(DOUBLE_CAMERA_SUPPORT)	
	noke_drv_main_camera_info_array[Main_Camera_Id_Type].get_sensor_group_info(group_idx,  group_name_ptr,  item_count_ptr);
#else
	if(mmi_main_camera_active == KAL_TRUE )
	{
		noke_drv_main_camera_info_array[Main_Camera_Id_Type].get_sensor_group_info(group_idx,  group_name_ptr,  item_count_ptr);
	}
	else
	{
		noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].get_sensor_group_info(group_idx,  group_name_ptr,  item_count_ptr);
	}
#endif	
}

void get_sensor_item_info(kal_uint16 group_idx,kal_uint16 item_idx, ENG_sensor_info* info_ptr)
{
#if !defined(DOUBLE_CAMERA_SUPPORT)	
	noke_drv_main_camera_info_array[Main_Camera_Id_Type].get_sensor_item_info(group_idx,item_idx, info_ptr);
#else
	if(mmi_main_camera_active == KAL_TRUE )
	{
		noke_drv_main_camera_info_array[Main_Camera_Id_Type].get_sensor_item_info(group_idx,item_idx, info_ptr);
	}
	else
	{
		noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].get_sensor_item_info(group_idx,item_idx, info_ptr);
	}
#endif	
}

kal_bool set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
{
#if !defined(DOUBLE_CAMERA_SUPPORT)	
	noke_drv_main_camera_info_array[Main_Camera_Id_Type].set_sensor_item_info(group_idx,item_idx,item_value);
#else
	if(mmi_main_camera_active == KAL_TRUE )
	{
		noke_drv_main_camera_info_array[Main_Camera_Id_Type].set_sensor_item_info(group_idx,item_idx,item_value);
	}
	else
	{
		noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].set_sensor_item_info(group_idx,item_idx,item_value);
	}
#endif	
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

kal_char* main_camera_info_summary(void) 
{ 
	return noke_drv_main_camera_info_array[Main_Camera_Id_Type].camera_info;
} 


kal_bool image_sensor_is_main_camera_ready(void)
{
	INIT_CAMERA_SENSOR_RESET;
#if defined(DOUBLE_CAMERA_SUPPORT)
	camera_module_pin_set( MODULE_CMPDN_PIN_2, 1 );
	kal_sleep_task(2);	
#endif
	camera_module_pin_set( MODULE_CMPDN_PIN, 0 );
	
	return noke_drv_main_camera_info_array[Main_Camera_Id_Type].is_sensor_ready();
}


#if defined(DOUBLE_CAMERA_SUPPORT)
kal_char* sub_camera_info_summary(void) 
{ 
	return noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].camera_info;
} 



kal_bool image_sensor_is_sub_camera_ready(void)
{
	INIT_CAMERA_SENSOR_RESET;
	camera_module_pin_set( MODULE_CMPDN_PIN, 1 );
	kal_sleep_task(2);	
	camera_module_pin_set( MODULE_CMPDN_PIN_2, 0 );

	return noke_drv_sub_camera_info_array[Sub_Camera_Id_Type].is_sensor_ready();
}
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

kal_bool noke_drv_camera_id_set( kal_uint16 camera_id )
{
	S16 write_error,check_error;
	kal_uint16 camera_id_check;
#ifdef NOKE_DEBUG
		noke_dbg_printf("\rHongzhe.Liu :noke_drv_camera_id_set 0x%04x\n", camera_id);
#endif
	if( 0xFFFF != camera_id 
		&& ID_MAIN_CAMERA_MAX>( camera_id & 0x00FF ) 
#if defined(DOUBLE_CAMERA_SUPPORT)
		&& ID_SUB_CAMERA_MAX>( ( camera_id & 0xFF00 )>>8 ) 
#endif
	)
	{
#ifdef NOKE_DEBUG
		noke_dbg_printf("\rHongzhe.Liu :before WriteValueInt\n");
#endif
		//WriteValueInt(NVRAM_CAMERA_MODULE_ID, &camera_id, 2 /* DS_SHORT */, &write_error, __FILE__, __LINE__);
		//write_error = noke_drv_nvram_value_asscess_req( KAL_TRUE, NVRAM_CAMERA_MODULE_ID,  &camera_id, 2 );
#ifdef NOKE_DEBUG
		noke_dbg_printf("\rHongzhe.Liu :after WriteValueInt\n");
#endif
		//ReadValueInt(NVRAM_CAMERA_MODULE_ID, &camera_id_check, 2 /* DS_SHORT */, &check_error, __FILE__, __LINE__);
		//check_error = noke_drv_nvram_value_asscess_req( KAL_FALSE, NVRAM_CAMERA_MODULE_ID,  &camera_id_check, 2 );
#ifdef NOKE_DEBUG
		noke_dbg_printf("\rHongzhe.Liu :after ReadValueInt\n");
#endif
		if(camera_id_check!=camera_id || 1 /* NVRAM_READ_SUCCESS */ != write_error)
		{
			return KAL_FALSE;
		}
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
}

kal_bool noke_drv_camera_reg_set(kal_uint16 * addr_array, kal_uint16 * value_array,  kal_uint8 count)
{
	int i;
	for(i=0; i<count; i++)
	{
		write_cmos_sensor(addr_array[i], value_array[i]);
	}
}

void noke_drv_get_camera_info(char * buffer, int buffer_len)
{
	int i=0;

	int info_len = 8/*[0xFFFF]*/ 
		+ 1 /* ^ */
		+ ID_MAIN_CAMERA_MAX*(1/* $ */ + strlen(noke_drv_main_camera_info_array[0].camera_info) )
#if defined(DOUBLE_CAMERA_SUPPORT)
		+ ID_SUB_CAMERA_MAX*(1/* $ */ + strlen(noke_drv_sub_camera_info_array[0].camera_info) )
#endif
		;

	if( info_len >= buffer_len )
	{
		sprintf(buffer, "----- Error -----");
		return;
	}
	
	memset(buffer, 0x00, buffer_len);
#if defined(DOUBLE_CAMERA_SUPPORT)	
	sprintf(buffer, "[0x%04x", Main_Camera_Id_Type | ( Sub_Camera_Id_Type<<8) );
#else
	sprintf(buffer, "[0x%04x", Main_Camera_Id_Type);
#endif
	
	for( i=0; i<ID_MAIN_CAMERA_MAX; i++)
	{
		strcat( buffer, "$" );
		strcat( buffer, noke_drv_main_camera_info_array[0].camera_info );
	}
	strcat( buffer, "^" );
#if defined(DOUBLE_CAMERA_SUPPORT)
	for( i=0; i<ID_SUB_CAMERA_MAX; i++)
	{
		strcat( buffer, "$" );
		strcat( buffer, noke_drv_sub_camera_info_array[0].camera_info );
	}
#endif
	strcat( buffer, "]" );
}








