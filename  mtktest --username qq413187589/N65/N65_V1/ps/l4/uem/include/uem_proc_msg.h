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

/*******************************************************************************
 * Filename:
 * ---------
 * uem_drivers_msg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4C<-UEM message handle.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _UEM_PROC_MSG_H
#define _UEM_PROC_MSG_H

/***************************************************************************** 
* External Functions
*****************************************************************************/
extern void uemdrv_keypad_detect_ind(kal_bool(*drv_get_key_func) (kbd_data *));

extern void uemdrv_alarm_detect_ind(void);

extern void uemdrv_rtc_period_ind(void);

extern void uemdrv_keypad_power_on_ind(void);

extern void uemdrv_exception_power_on_ind(void);

extern void uemdrv_pmic_ind(kal_uint8 status_type);

extern void uemdrv_gpio_detect_ind(kal_uint8 gpio_device);

extern void uemdrv_audio_play_finish_ind(kal_uint8 result, kal_uint16 identifier);

#ifdef __USB_ENABLE__
extern void uemdrv_usb_power_on_ind(void);

extern void uemdrv_usb_detect_ind(kal_uint8 action);

extern void uemdrv_usb_config_cnf(kal_uint8 mode, kal_bool result, kal_uint32 reserved);
#endif /* __USB_ENABLE__ */ 

extern void uemdrv_prechr_power_on_ind(void);

extern void uemdrv_get_hw_level_pwm_info_req(kal_uint8 type, kal_uint8 level, kal_uint8 *info1, kal_uint8 *info2);

extern void uemdrv_get_hw_level_alter_info_req(kal_uint8 level, kal_uint8 *info1, kal_uint8 *info2);

extern void uem_poweron_timer_expiry_hdlr(void *ptr);

extern void uem_poweron_timer_start(kal_uint32 time_in_ms);

extern void uemdrv_rf_test_gsm_powerscan_callback(kal_int16 *arfcn, kal_int16 *power);

#endif /* _UEM_PROC_MSG_H */ /* uem_proc_msg.h */

