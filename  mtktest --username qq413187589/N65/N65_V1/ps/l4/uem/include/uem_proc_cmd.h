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
 * uem_drivers_cmd.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4C->UEM driver command.
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
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _UEM_PROC_CMD_H
#define _UEM_PROC_CMD_H

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern kal_uint8 uem_adc_on;
extern eventid uem_adc_timer_id;

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern void l4cuem_audio_play_req(kal_uint8 audio_sound_id, kal_uint8 audio_play_style, kal_uint16 identifier);

extern void l4cuem_audio_stop_req(kal_uint8 audio_sound_id);

extern void l4cuem_audio_set_volume_req(kal_uint8 volume_type, kal_uint8 volume_level);

extern void l4cuem_audio_get_volume_req(kal_uint8 volume_type);

extern void l4cuem_demo_ext_imelody_ring_req
    (kal_uint8 *imelody, kal_uint16 len, kal_uint8 play_style, kal_uint16 identifier);

extern void l4cuem_power_off_req(void);

extern kal_uint8 l4cuem_rtc_get_count_req(kal_uint8 rtc_type);

extern kal_bool l4cuem_rtc_get_hw_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *rtctime);

extern kal_bool l4cuem_rtc_get_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *rtctime);

extern void l4cuem_rtc_set_time_req(kal_uint8 rtc_type, rtc_alarm_info_struct rtctime, kal_uint8 setting_type);

extern void l4cuem_alarm_get_time_req(kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *alarm_info);

extern void l4cuem_rtc_cnfg_format_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, kal_uint8 rtc_format_id);

extern void l4cuem_rtc_delete_date_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id);

extern void l4cuem_speech_set_mode_req(kal_bool speech_mode_onoff);

extern void l4cuem_call_status_req_ind(kal_uint8 ind_type);

extern void l4cuem_set_mute_req(kal_uint8 audio_device, kal_bool mute_onoff);

extern void l4cuem_get_mute_req(kal_uint8 audio_device, kal_bool *is_mute);

extern void l4cuem_gpio_set_level_req(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);

extern void l4cuem_pattern_play_req(kal_uint8 pattern, kal_uint8 action);

extern void l4cuem_pattern_stop_req(kal_uint8 pattern);

extern void l4cuem_get_equip_id_req(kal_uint8 equip_id, kal_uint8 *equip_string);

extern void l4cuem_get_battery_status_req(kal_uint8 *battery_status, kal_uint8 *battery_vol);

extern void l4cuem_set_silent_mode_req(kal_bool is_silent);

extern void l4cuem_get_silent_mode_req(kal_uint8 *is_silent);

extern void l4cuem_set_alert_mode_req(kal_uint8 alert_mode);

extern void l4cuem_get_alert_mode_req(kal_uint8 *alert_mode);

extern void l4cuem_get_greeting_text_req
    (kal_uint8 *mode, kal_uint8 *text_dcs, kal_uint8 *greeting_text, kal_uint8 *text_no);

extern void l4cuem_set_greeting_text_req
    (kal_bool mode, kal_uint8 text_dcs, kal_uint8 *greeting_text, kal_uint8 no_text);

extern void l4cuem_gpio_get_level_req(kal_uint8 gpio_device, kal_uint8 *gpio_dev_level);

extern void l4cuem_equip_set_cc_req(kal_uint8 country_code);

extern void l4cuem_equip_get_cc_req(kal_uint8 *country_code);

extern void l4cuem_set_lang_req(kal_uint8 lang_id_0, kal_uint8 lang_id_1);

extern void l4cuem_get_lang_req(kal_uint8 *lang_id);

extern void l4cuem_set_date_time_format_req(kal_bool is_date_set, kal_uint8 mode);

extern void l4cuem_get_date_time_format_req(kal_bool is_date_set, kal_uint8 *mode);

extern kal_bool l4cuem_set_accustic_value(kal_uint8 volume_type, kal_uint8 volume_level, kal_uint8 volume_gain);

extern void l4cuem_get_accustic_value(
                kal_uint8 volume_type,
                /* volume_type_enum */ kal_uint8 volume_level);

extern kal_bool l4cuem_power_reset(
                    kal_uint8 reset_type /* pmic_reset_type_enum */ );

extern void l4cuem_get_audio_profile_req(kal_uint8 mode);

extern void l4cuem_get_audio_param_req(void);

extern void l4cuem_set_audio_mode(kal_uint8 mode);

extern kal_bool l4cuem_get_hw_level_req(l4cuem_set_hw_level_req_struct *hw_level);

extern void l4cuem_get_adc_all_channel_stop_req(void);

extern void l4cuem_get_adc_all_channel_start_req(void);

extern void l4cuem_battery_status_res_req(kal_uint8 status_type);
extern void l4cuem_usbdetect_res_req(kal_uint8 action);

extern void l4cuem_em_dcm_enable_req(kal_bool enable);
extern void l4cuem_em_uart_poweron_req(kal_uint8 uart_power_setting);

#ifdef __USB_ENABLE__
extern void l4cuem_usbconfig_req(kal_uint8 src_id, kal_uint8 mode, kal_uint32 reserved);
#endif 

extern void l4cuem_em_pmic_config_req(kal_uint8 src_id, kal_uint8 request_type, pmic_config_param_struct request);

extern void l4cuem_em_rf_test_gsm_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_gsm_param_struct request);

extern void l4cuem_em_rf_test_wifi_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_wifi_param_struct request);

extern void l4cuem_em_fm_radio_config_req(kal_uint8 src_id, kal_uint8 request_type, fm_radio_config_param_struct request);

extern void l4cuem_startup_cnf_rsp(void);

extern void l4cuem_gpio_detect_res_req(kal_uint8 ext_gpio_device);

#endif /* _UEM_PROC_CMD_H */ /* uem_proc_cmd.h */

