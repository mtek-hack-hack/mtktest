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
 *   isp_flashlight.h
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229
 *
 * Description:
 * ------------
 *   flash light control
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ISP_FLASHLIGHT_H
#define _ISP_FLASHLIGHT_H

#include "drv_features.h" 
#if (defined(ISP_SUPPORT))

#include "isp_if.h"

typedef enum
{
	FLASHLIGHT_STANDBY_STATE=0,
	FLASHLIGHT_CHARGE_STATE,        // XENON FLASHLIGHT ONLY	
	FLASHLIGHT_READY_STATE,		    // XENON FLASHLIGHT ONLY
	FLASHLIGHT_RECHARGE_STATE,		// XENON FLASHLIGHT ONLY	
	FLASHLIGHT_PRE_STROBE_STATE,		
	FLASHLIGHT_PRE_STROBE_DONE_STATE,			
	FLASHLIGHT_TRIGGER_STATE,		
	FLASHLIGHT_TRIGGER_DONE_STATE,
	FLASHLIGHT_MAIN_STROBE_STATE	
} FLASHLIGHT_OPERATION_STATE_ENUM;

#if (!defined(DRV_ISP_6219_SERIES))
extern FLASHLIGHT_OPERATION_STATE_ENUM flashlight_operation_state;
extern kal_bool fake_main_flash_frame_flag, fake_sub_flash_frame_flag;
extern kal_int32  flashlight_idx, flashlight_main_idx; 
extern kal_uint32 flashlight_lum, flashlight_main_lum;
extern kal_uint16  flashlight_sensor_gain, flashlight_isp_gain;
extern kal_uint8   flashlight_awb_idx, flashlight_awb_weight;
extern kal_uint16  flashlight_awb_r_backup, flashlight_awb_g_backup, flashlight_awb_b_backup;
extern kal_uint32  flash_ae_info;

extern kal_uint16 isp_tg_delay_lines;
void init_flashlight(void);
void flashlight_pre_process(void);
void flashlight_post_process(void);
kal_bool flashlight_redeye_process(kal_uint32  capture_delay_frame);
void flashlight_trigger_process(void);
void flashlight_stop_process(void);
void flashlight_hisr(void);

void flashlight_prestrobe(void);
void flashlight_poststrobe(void);
kal_bool flashlight_redeye(kal_uint32  capture_delay_frame);
void flashlight_trigger(void);
kal_uint32  flashlight_ae_cal(void);
kal_uint32  flashlight_ae_proc(void);
void  flashlight_awb_proc(void);

// Xenon Flash Define
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))
#define MAX_STRPBE_POLLING_TIME   100 // 32K ticks, ~3ms
typedef enum
{
	XENON_FLASHLIGHT_CHARGING,    
	XENON_FLASHLIGHT_CHARGE_TIMEOUT,    	
	XENON_FLASHLIGHT_READY
} XENON_FLASHLIGHT_STATUS_ENUM;

typedef enum
{
    XENON_RETCODE_NOT_READY=0,          // charging, not ready    
    XENON_RETCODE_READY,                // stop charging, ready    
    XENON_RETCODE_CHARGE_STOP,          // stop charge
    XENON_RETCODE_CHARGE_TIMEOUT,       // timeout stop charging, not ready
    XENON_RETCODE_CHARGE_LOW_BATTERY,   // low battery stop charging, not ready 
    XENON_RETCODE_NO 
} XENON_RETCODE_ENUM;

typedef struct 
{
    kal_uint32  voltage;            // mV,    
} xenon_para_struct;

typedef struct 
{
    kal_uint8   retcode;                // XENON_RETCODE_ENUM    
    kal_bool    charge_status;          // charge status, KAL_TRUE/KAL_FALSE
    kal_uint8   charge_index;           // charge index    
    kal_uint32  max_charge_duty;        // ms, charge timeout limit
    kal_uint32  low_battery_volt;       // mV                    
    kal_uint32  ready_polling_period;   // ms, ready check every period time            
    kal_uint32  pre_strobe_period;      // us, period between pre-strobes
    kal_uint32  pre_strobe_duty;        // us, prestrobe duty before main strobe    
    kal_uint32  pre_strobe_times;       // precharge times before main strobe                        
    kal_uint32  redeye_strobe_duty;     // us, red eye reduction strobe duty before main strobe        
    kal_uint32  redeye_strobe_offset;   // line, red eye reduction strobe offset
    kal_uint32  redeye_strobe_wait_frame;// frame num, red eye reduction strobe wait frame for main strobe    
    kal_uint32  main_strobe_duty;       // us, main strobe duty
} xenon_info_struct;

typedef struct
{
   kal_int8 (* xenon_init)(void);
   kal_bool (* xenon_charge)(kal_bool on, xenon_para_struct *para);   
   kal_uint32 (* xenon_get_charge_level_count)(void);   
   kal_bool (* xenon_set_charge_level)(kal_uint32 level);            
   kal_uint8 (* get_xenon_ready_status)(xenon_para_struct *para);
   xenon_info_struct *(* get_xenon_info)(void);
   kal_bool (* xenon_strobe)(kal_bool on);         
} xenon_func_struct;

extern xenon_func_struct   *p_xenon_func;
extern xenon_info_struct   *p_xenon_info;
// config xenon flash initial
//void isp_xenon_flashlight_init(void);
// Setting customize driver funciton map
void xenon_func_config(void);
// functions for MED inaterface 
xenon_info_struct *isp_xenon_flashlight_charge(kal_bool on, xenon_para_struct *para);
xenon_info_struct *isp_xenon_flashlight_ready_check(xenon_para_struct *para);
xenon_info_struct *get_isp_xenon_flashlight_info(void);
#endif  // XENON_FLASHLIGHT_ANTI_RED_EYE

#endif  /* MT6228||MT6226||MT6227||MT6229 ||MT6230 */

// Interface for customize sensor driver
typedef struct 
{
    kal_uint32  pixels;             // Sensor active pixel number
    kal_uint32  lines;              // Sensor active line number
} flashlight_preview_para_struct;
typedef struct 
{
    kal_uint32  default_pclk;       // Sensor pixel clock(Ex:24000000)
    kal_uint32  pixels;             // Sensor active pixel number
    kal_uint32  lines;              // Sensor active line number
    kal_uint32  shutter;            // Sensor current shutter
} flashlight_capture_para_struct;
extern flashlight_preview_para_struct flashlight_preview_para;
extern flashlight_capture_para_struct flashlight_capture_para;
void flashlight_preview_config(flashlight_preview_para_struct *para, image_sensor_config_struct *sensor_config_data);
kal_uint32 flashlight_capture_config(flashlight_capture_para_struct *para, image_sensor_config_struct *sensor_config_data);


extern FLASHLIGHT_OPERATION_STATE_ENUM flashlight_operation_state;
extern kal_uint16	AWB_Rgain_Backup,AWB_GRgain_Backup,AWB_Bgain_Backup,AWB_GBgain_Backup;
extern kal_uint8 AE_INDEX_Backup;
extern kal_bool fake_main_flash_frame_flag, fake_sub_flash_frame_flag;
extern kal_int32  flashlight_idx, flashlight_main_idx; 
extern kal_uint32 flashlight_lum, flashlight_main_lum;
extern kal_uint16  flashlight_sensor_gain, flashlight_isp_gain;
extern int flashlight_miss_count;

#define FLASHLIGHT_MAX_AE_RANGE (42)
#define FLASHLIGHT_MAX_AE_NUM   (40)
#define FLASHLIGHT_CENTER_AE_NUM (25)
#define FLASHLIGHT_MIN_AE_NUM   (0)
extern const kal_uint16 EVSTEP_FLASH_01[];
#define FLASHLIGHT_MAX_TBL_SIZE (20)
extern kal_uint8   xenon_awb_mix_tbl[3][FLASHLIGHT_MAX_TBL_SIZE];

#endif /* _ISP_FLASHLIGHT_H */
#endif /* MT6219||MT6228||MT6226||MT6227||MT6229 ||MT6230*/

