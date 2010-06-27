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
 *    drvsignals.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for driver primitives.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DRVSIGNALS_H
#define _DRVSIGNALS_H

#include "bmt.h"

/*RTC driver*/
#define RTC_TC_IND			0
#define RTC_AL_IND			1
typedef struct {
	LOCAL_PARA_HDR
	kal_uint8 		rtc_ind;
} RTC_Primitive;

/*Kbd driver*/
#define Kbd_KeyPress			0
#define Kbd_KeyRelease		1
typedef struct {
	LOCAL_PARA_HDR
	kal_uint8 		kp_status;
	kal_uint8 		key;
} Kbd_Primitive;

/*Communicated with MMI, charging status*/
typedef enum 
{
   BMT_CHARGER_IN = 0,
   BMT_CHARGER_OUT,
   BMT_OVERVOLPROTECT,
   BMT_OVERBATTEMP,
   BMT_LOWBATTEMP,
   BMT_OVERCHARGECURRENT,
   BMT_CHARGE_COMPLETE,
   BMT_INVALID_BAT,
   BMT_INVALID_CHARGER,
   BMT_CHARGE_TIMEOUT,
   BMT_LOWCHARGECURRENT,
   BMT_CHARGE_BAD_CONTACT,
   BMT_BATTERY_BAD_CONTACT,
   BMT_USB_CHARGER_IN,
   BMT_USB_CHARGER_OUT,
   BMT_USB_NO_CHARGING_IN,
   BMT_USB_NO_CHARGING_OUT
}BMT_CHR_STAT;

typedef struct {
	LOCAL_PARA_HDR
	BMT_CHR_STAT 		status;
} drvuem_pmic_ind_struct;

/*ADC scheduler*/
typedef struct {
	LOCAL_PARA_HDR
	kal_uint8 		adc_sche_id;
	kal_int32 		volt;
	double         adc_value;
} bmt_adc_measure_done_conf_struct;

typedef struct {
	LOCAL_PARA_HDR
	kal_uint8 adc_sche_id;
} bmt_adc_add_item_req_struct;

typedef struct {
	LOCAL_PARA_HDR
	kal_uint8 adc_sche_id;
} bmt_adc_remove_item_req_struct;

typedef struct {
	LOCAL_PARA_HDR
	kal_uint8   adc_sche_id;
	kal_uint8   evaluate_count;
	kal_uint32  period;
} bmt_adc_modify_parameters_req_struct;

/*AUX task*/
typedef enum 
{
   AUX_ID_PLUGOUT=0,
   AUX_ID_TVOUT,
   AUX_ID_EARPHONE,
   AUX_ID_KEY_PRESS,
   AUX_ID_KEY_RELEASE,
   AUX_ID_UART,
   AUX_ID_CLAM_OPEN,
   AUX_ID_CLAM_CLOSE,
   AUX_ID_TVOUT_OUT,
   AUX_MAX_ID
}AUX_ID;
typedef struct {
	LOCAL_PARA_HDR
	AUX_ID   aux_id;
} aux_id_struct;

/*Engineering mode*/
typedef struct {
   LOCAL_PARA_HDR
   kal_int32 		vbat;	/*Battery Voltage(micro-voltage)*/
   kal_int32     bat_temp;	/*Battery Temperature(¢J)*/
   kal_int32 		vaux;		/*AUX Voltage(micro-voltage)*/
   kal_int32 		charge_current;	/*Charge current(micro-A)*/
   kal_int32 		vcharger;	/*Charger Voltage(micro-voltage)*/
} adc_all_channel_struct;

/*USB driver*/
typedef struct {
	LOCAL_PARA_HDR
   void                 *pData; /* Pointer to data buffer */
   kal_int32             nBuffLen; /* Length of data buffer */
	kal_int32             nBytesRecv; /* Number of bytes received */
} usb_ms_rec_done_conf_struct;

/*L4->USB*/
typedef struct {
   LOCAL_PARA_HDR
	/*Please include "usb_comm.h"*/
   kal_uint8         mode;  /* USB_DEVICE_TYPE */
   kal_uint32        *parameter;
} drvuem_usbcfg_req_struct;

/*USB->L4*/
typedef struct {
   LOCAL_PARA_HDR
   kal_uint8         mode;  /* USB_DEVICE_TYPE */
   kal_uint32        reserved;
   kal_bool          result;
} drvuem_usbcfg_cnf_struct;

/*USB->L4*/
typedef enum 
{
   DETECT_ACTION_UNKNOWN=0,
   DETECT_ACTION_PLUGIN,
   DETECT_ACTION_PLUGOUT,
   DETECT_ACTION_MAX_ID
}USB_DETECT_ACTION_ID;

typedef struct {
   LOCAL_PARA_HDR
   USB_DETECT_ACTION_ID         action;  /*1: Plugin, 0:PlugOut*/
}drvuem_usbdetect_ind_struct;

// add for usb charging
typedef enum{
	BMT_USB_100,
	BMT_USB_500
}bmt_usb_ind_enum;

typedef struct{
	LOCAL_PARA_HDR
#ifdef  __USB_MULTI_CHARGE_CURRENT__
	kal_uint8  usb_ind;
#else
	bmt_usb_ind_enum usb_ind;
#endif
}bmt_usb_ind_struct;

typedef struct{
	LOCAL_PARA_HDR
	power_on_enum power_on;
	kal_uint32 	poweron_time_left;
}drvuem_power_on_ind_struct;


#endif

