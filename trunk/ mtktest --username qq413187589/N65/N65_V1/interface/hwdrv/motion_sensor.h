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
 *    motion_sensor.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for motion sensor driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MOTIONSENSOR_H
#define _MOTIONSENSOR_H

#define SIN_INTERVAL_NUM 91
#define SIN_0   0   
#define SIN_1   9   
#define SIN_2   18  
#define SIN_3   27  
#define SIN_4   36  
#define SIN_5   45  
#define SIN_6   53  
#define SIN_7   62  
#define SIN_8   71  
#define SIN_9   80  
#define SIN_10  89  
#define SIN_11  98  
#define SIN_12  106 
#define SIN_13  115 
#define SIN_14  124 
#define SIN_15  132 
#define SIN_16  141 
#define SIN_17  150 
#define SIN_18  158 
#define SIN_19  167 
#define SIN_20  175 
#define SIN_21  183 
#define SIN_22  192 
#define SIN_23  200 
#define SIN_24  208 
#define SIN_25  216 
#define SIN_26  224 
#define SIN_27  232 
#define SIN_28  240 
#define SIN_29  248 
#define SIN_30  256 
#define SIN_31  264 
#define SIN_32  271 
#define SIN_33  279 
#define SIN_34  286 
#define SIN_35  294 
#define SIN_36  301 
#define SIN_37  308 
#define SIN_38  315 
#define SIN_39  322 
#define SIN_40  329 
#define SIN_41  336 
#define SIN_42  342 
#define SIN_43  349 
#define SIN_44  356 
#define SIN_45  362 
#define SIN_46  368 
#define SIN_47  374 
#define SIN_48  380 
#define SIN_49  386 
#define SIN_50  392 
#define SIN_51  398 
#define SIN_52  403 
#define SIN_53  409 
#define SIN_54  414 
#define SIN_55  419 
#define SIN_56  424 
#define SIN_57  429 
#define SIN_58  434 
#define SIN_59  439 
#define SIN_60  443 
#define SIN_61  448 
#define SIN_62  452 
#define SIN_63  456 
#define SIN_64  460 
#define SIN_65  464 
#define SIN_66  468 
#define SIN_67  471 
#define SIN_68  475 
#define SIN_69  478 
#define SIN_70  481 
#define SIN_71  484 
#define SIN_72  487 
#define SIN_73  490 
#define SIN_74  492 
#define SIN_75  494 
#define SIN_76  497 
#define SIN_77  499 
#define SIN_78  501 
#define SIN_79  503 
#define SIN_80  504 
#define SIN_81  506 
#define SIN_82  507 
#define SIN_83  508 
#define SIN_84  509 
#define SIN_85  510 
#define SIN_86  511 
#define SIN_87  511 
#define SIN_88  512 
#define SIN_89  512 
#define SIN_90  512 

#define MOTION_SENSOR_BUFFER_SIZE 128

typedef enum {
      BUFF_EMPTY,
      BUFF_DATA_EXIST,
      BUFF_FULL
} Motion_Sensor_BuffState_enum;

typedef struct
{
   kal_int16	x_acc;
   kal_int16 	y_acc;
   kal_int16 	z_acc;
}MotionSensorDataStruct;

typedef struct
{
   kal_int16	x_gain;
   kal_int16 	y_gain;
   kal_int16 	z_gain;
   kal_int16	x_offset;
   kal_int16 	y_offset;
   kal_int16 	z_offset;
}MotionSensorCaliStruct;
                        
typedef void (*MS_DATA_FUNC)(void *parameter, Motion_Sensor_BuffState_enum state); 
typedef void (*MS_INT_CB_FUNC)(void); 

typedef struct
{
   MotionSensorCaliStruct cali;
   MotionSensorDataStruct pre;   
   kal_uint8              sample_period;
   kal_uint8              gpt_handle;
   kal_uint32             acc_offset;   
   kal_uint32             low_g_level; 
   kal_uint32             high_g_level;   
   kal_uint32             low_g_debounce; 
   kal_uint32             high_g_debounce;   
   MS_DATA_FUNC           cb_func;
   MS_INT_CB_FUNC         low_g_cb;
   MS_INT_CB_FUNC         high_g_cb;
	void                   *para;		
}MotionSensorStruct;

typedef struct
{
   MotionSensorDataStruct  motion_sensor_data[MOTION_SENSOR_BUFFER_SIZE];
   kal_uint16     motion_sensor_rindex;
   kal_uint16     motion_sensor_windex;
}MotionSensorBufferStruct;

/*customization part*/
typedef struct {
   /*ADC*/
	kal_uint16 x_0g_adc;
	kal_uint16 x_1g_adc;
	kal_uint16 x_minus1g_adc;
	kal_uint16 y_0g_adc;
	kal_uint16 y_1g_adc;
	kal_uint16 y_minus1g_adc;
	kal_uint16 z_0g_adc;
	kal_uint16 z_1g_adc;
	kal_uint16 z_minus1g_adc;		
	
	kal_bool   int_support;	
	kal_uint8  int_level;
	kal_uint8  int_chan;
} MotionSensor_custom_data_struct;

typedef struct {  
   MotionSensor_custom_data_struct * (*ms_get_data)(void);
   void (*ms_read_adc)(kal_uint16 *x, kal_uint16 *y, kal_uint16 *z);
   void (*ms_custom_init)(void);
   void (*ms_power_up)(void);
   void (*ms_power_down)(void);
   /*read interrupt*/
   void (*ms_read_int_status)(kal_bool *low_g, kal_bool *high_g);   
   /*clear interrupt*/
   void (*ms_clear_int_status)(void);   
   void (*ms_configure_low_g)(kal_uint32 debounce, kal_uint32 threshold);
   void (*ms_configure_high_g)(kal_uint32 debounce, kal_uint32 threshold);
}MotionSensor_customize_function_struct;

/*For MMI */
extern void motion_sensor_complete_cali(void);
extern void motion_sensor_cancel_cali(void);
extern void motion_sensor_start_cali(void);
extern void motion_sensor_read_cali(MotionSensorCaliStruct *cali);
extern void motion_sensor_set_cali(MotionSensorCaliStruct cali);
extern kal_bool motion_sensor_power(kal_bool enable);
extern void motion_sensor_conf_sample_period(kal_uint32 period);
extern void motion_sensor_flush_buff(void);
extern void motion_sensor_cb_registration(MS_DATA_FUNC cb_fun, void *para);
extern void motion_sensor_sample(kal_bool enable);
extern void motion_sensor_conf_filter(kal_uint32 acc_offset);
extern kal_bool motion_sensor_get_data(MotionSensorDataStruct  *ms_data);
extern void motion_sensor_int_cb_registration(MS_INT_CB_FUNC low_g_cb_fun, MS_INT_CB_FUNC high_g_cb_fun);
extern void motion_sensor_int_config(kal_uint32 low_g_level, kal_uint32 high_g_level,
                              kal_uint32 low_g_debounce, kal_uint32 high_g_debounce);
extern void motion_sensor_int_enable(kal_bool enable);                              
/*For driver */
extern void motion_sensor_eint_hisr(void);
extern kal_bool motion_sensor_filter(MotionSensorDataStruct data);
extern void motion_sensor_sample_cb(void *parameter);
extern void motion_sensor_check_cali(kal_int16 x, kal_int16 y, kal_int16 z);
extern void motion_sensor_init(void);
extern void motion_sensor_get_acc(MotionSensorDataStruct *acc_data,
                           kal_uint16 x_adc, kal_uint16 y_adc, kal_uint16 z_adc);
extern void motion_sensor_sample_cb(void *parameter);
extern void motion_sensor_reset(void);
#ifdef __MOTION_SENSOR_TILT_SUPPORT__
extern void motion_sensor_get_tilt(kal_uint16 x, kal_uint16 y, kal_uint16 z);
extern kal_uint16 motion_sensor_get_angle(kal_uint16 value);
#endif
#endif