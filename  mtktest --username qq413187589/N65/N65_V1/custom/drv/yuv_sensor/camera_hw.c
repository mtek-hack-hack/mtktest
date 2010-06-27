/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/custom/drv/yuv_sensor/OV7670/camera_hw.c,v 1.5 2007/09/03 05:56:42 bw Exp $
*
* $Id: camera_hw.c 268 2009-09-28 06:17:23Z liuhongzhe $
*
* $Date: 2009-09-28 14:17:23 +0800 (鏄熸湡涓�, 28 涔濇湀 2009) $
*
* $Name: 1.5 $
*
* $Locker$
*
* $Revision: 268 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: camera_hw.c,v $
* Revision 1.5  2007/09/03 05:56:42  bw
* UNI@bw_20070831 17:44:56    减小开机后的待机电流
*
* Revision 1.4  2007/08/29 06:12:54  bw
* UNI@bw070829 [6225 platform ov7670][All] double camera support
*
* Revision 1.3  2007/06/13 05:28:09  bw
* P_6226_bw_D01_Z801 805camera无法播放短音问题
*
* Revision 1.2  2007/06/04 01:32:25  bw
* p_6226_bw_D01_Z800修改进入camera时不能播放短音问题
*
* Revision 1.1  2007/05/22 03:42:44  bw
* UNI@bw070522  移动目录
*
* Revision 1.1  2007/05/17 07:11:41  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
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
 *   camera_hw.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Camera HW control API
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(ISP_SUPPORT)
#include "drv_comm.h"
#include "stdio.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "sccb.h"
#include "ae_awb.h"
#include "camera_para.h"
#include "med_api.h"
#include "alerter_sw.h"
#include "alerter_hw.h"
#include "gpio_hw.h"

#if defined(HORSERACE_SUPPORT)
extern kal_bool  tv_fm_camera_is_power_on;
#endif /* HORSERACE_SUPPORT */


void camera_module_pin_set( kal_uint16 port, kal_uint16 data )
{
	if ( GPIO_MAGIC_NUM == (port & GPIO_MAGIC_NUM) )
	{
		GPIO_InitIO(1, port);
		GPIO_ModeSetup(port, 0);
		GPIO_WriteIO(data, port);
	}
	else
	{
		GPO_ModeSetup(port, 0);
		GPO_WriteIO(data, port);
	}
}

void cis_module_power_on(kal_bool on)
{

	if(on==KAL_TRUE)
	{
		sccb_setDelay(0);		
		sccb_config(SCCB_SW_8BIT, 0x42, 0x43, NULL);

		camera_module_pin_set( MODULE_POWER_PIN, 1 );

		camera_module_pin_set( MODULE_RESET_PIN, 1 );
		kal_sleep_task(2);
		camera_module_pin_set( MODULE_RESET_PIN, 0 );
		kal_sleep_task(2);
		camera_module_pin_set( MODULE_RESET_PIN, 1 );

		camera_module_pin_set( MODULE_CMPDN_PIN, 1 );
		
#ifdef  DOUBLE_CAMERA_SUPPORT 
		camera_module_pin_set( MODULE_CMPDN_PIN_2, 1 );
#endif			
#if defined(HORSERACE_SUPPORT)
		tv_fm_camera_is_power_on = KAL_TRUE;
#endif /* HORSERACE_SUPPORT */
	}
	else
	{
        	// Sensor Module Power 
		camera_module_pin_set( MODULE_POWER_PIN, 1 );

		camera_module_pin_set( MODULE_RESET_PIN, 1 );
		kal_sleep_task(2);
		camera_module_pin_set( MODULE_RESET_PIN, 0 );
		kal_sleep_task(2);
		camera_module_pin_set( MODULE_RESET_PIN, 1 );

		// Sensor Power, CMOS Sensor Power Down Signal Output      
		camera_module_pin_set( MODULE_CMPDN_PIN, 1 );
		
#ifdef  DOUBLE_CAMERA_SUPPORT 
		camera_module_pin_set( MODULE_CMPDN_PIN_2, 1 );
#endif	

		// SCCB Low
		camera_module_pin_set( SCCB_SERIAL_CLK_PIN, 0 );
		camera_module_pin_set( SCCB_SERIAL_DATA_PIN, 0 );

        	// Sensor Module Power 
		camera_module_pin_set( MODULE_POWER_PIN, 0 );        	 

		camera_module_pin_set( MODULE_RESET_PIN, 0 );

#if defined(HORSERACE_SUPPORT)
		tv_fm_camera_is_power_on = KAL_FALSE;
#endif /* HORSERACE_SUPPORT */
   }
}

void flashlight_power_on(kal_bool on)
{
}

#ifdef __MAIN_CAMERA_WITH_FLASH__

 #ifdef HORSERACE_SUPPORT
extern void noke_drv_horse_race_camera_flash_light_on(kal_bool light_on);
 #endif

/*****************************************************************************
 * FUNCTION
 *  noke_drv_camera_flash_light_on
 * DESCRIPTION
 *  capture photo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern const char gpio_photo_flashlight_en_pin;
void noke_drv_camera_flash_light_on(kal_bool light_on)
{
#ifdef HORSERACE_SUPPORT
/* If use horse race as flash light ...  */
	noke_drv_horse_race_camera_flash_light_on(light_on);
#else
	GPIO_ModeSetup(gpio_photo_flashlight_en_pin, 0);   	
	GPIO_InitIO(1, gpio_photo_flashlight_en_pin);
	if( light_on )
	{
		GPIO_WriteIO(1,gpio_photo_flashlight_en_pin);
	}else{
		GPIO_WriteIO(0,gpio_photo_flashlight_en_pin);
	}
#endif
}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */

#endif
