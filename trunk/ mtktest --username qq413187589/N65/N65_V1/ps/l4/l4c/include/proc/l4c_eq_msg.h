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
 *	l4c_eq_msg.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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


#ifndef _L4C_EQ_MSG_H
#define _L4C_EQ_MSG_H



extern void l4cuem_power_on_ind (kal_uint8 poweron_mode,
                                 kal_uint8 battery_level);

extern void l4cuem_audio_play_finish_ind (kal_uint8 result, kal_uint16  identifier);

extern void l4cuem_gpio_detect_ind (kal_uint8 gpio_device,
                                    kal_bool on_off);

extern void l4cuem_vm_general_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_vm_stop_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_vm_pause_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_vm_get_info_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_vm_record_finish_ind_hdlr (
                                  local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_vm_play_finish_ind_hdlr (
                                  local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_vm_record_full_ind (void);
extern void l4cuem_vm_play_finish_ind (void);


extern void l4cuem_alarm_detect_ind (rtc_format_struct *rtc_time);

extern void l4cuem_rtc_period_ind (kal_uint8 rtc_type, rtc_format_struct *rtc_time);

extern void l4cuem_keypad_detect_ind (kal_bool (*drv_get_key_func)(kbd_data *));

extern void l4cuem_battery_status_ind (kal_uint8 battery_status,
                                       kal_uint8 battery_voltage);

extern void l4cuem_get_adc_all_channel_ind (kal_int32	    vbat,
		                                          kal_int32	bat_temp,
		                                          kal_int32	vaux,
		                                          kal_int32	charge_current,
		                                          kal_int32	vcharger);

extern void l4cuem_startup_cnf_hdlr(local_para_struct *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr);

extern void l4cuem_set_profile_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_audio_play_by_name_cnf_hdlr (local_para_struct  *local_para_ptr,
                           peer_buff_struct *peer_buff_ptr);

extern void l4cuem_audio_stop_by_name_cnf_hdlr (local_para_struct  *local_para_ptr,
                           peer_buff_struct *peer_buff_ptr);

extern void l4cuem_audio_play_by_string_cnf_hdlr (local_para_struct  *local_para_ptr,
                           peer_buff_struct *peer_buff_ptr);

extern void l4cuem_audio_stop_by_string_cnf_hdlr (local_para_struct  *local_para_ptr,
                           peer_buff_struct *peer_buff_ptr);

extern void l4cuem_get_audio_profile_cnf_hdlr(local_para_struct *local_para_ptr, 
                           peer_buff_struct *peer_buff_ptr);

extern void l4cuem_get_volume_cnf_hdlr(local_para_struct *local_para_ptr, 
                           peer_buff_struct *peer_buff_ptr);

extern void l4cuem_get_gain_cnf_hdlr(local_para_struct *local_para_ptr, 
                           peer_buff_struct * peer_buff_ptr);

extern void l4cuem_get_audio_param_cnf_hdlr(local_para_struct *local_para_ptr , 
                           peer_buff_struct *peer_buff_ptr);                           
                           
extern void l4cuem_set_audio_profile_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);

extern void l4cuem_set_audio_param_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);


extern void l4cuem_set_hw_level_cnf_hdlr (local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);
extern void l4c_uart_transfer_ind_hdlr(local_para_struct  *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);


extern void l4c_keypad_input_press_hdlr (void);

extern void l4c_keypad_input_pause_hdlr (void);

extern void l4c_keypad_input_long_press_hdlr (void);

extern void l4c_keypad_input_repeat_hdlr (void);

extern void l4cuem_usbdetect_ind(kal_uint8  action);

extern void l4cuem_usb_power_on_ind(void);

#define l4c_equeue_onekey_to_kbdbuffer(_event,_key)   \
{\
   l4c_kbd_buffer.kbd_data_buffer[l4c_kbd_buffer.kbd_data_buffer_windex].Keyevent = _event;\
   l4c_kbd_buffer.kbd_data_buffer[l4c_kbd_buffer.kbd_data_buffer_windex].Keydata[0] = _key;\
   l4c_kbd_buffer.kbd_data_buffer_windex++;\
   l4c_kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);\
   if(l4c_kbd_buffer.kbd_data_buffer_windex==l4c_kbd_buffer.kbd_data_buffer_rindex)\
   {\
	   l4c_kbd_buffer.kbd_data_buffer_windex--;\
	   l4c_kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);\
	   while(l4c_kbd_buffer.kbd_data_buffer[l4c_kbd_buffer.kbd_data_buffer_windex].Keyevent != kbd_onekey_press)\
	   {\
		   l4c_kbd_buffer.kbd_data_buffer_windex--;\
		   l4c_kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);\
	   }\
   }\
}

#define l4c_dequeue_onekey_from_kbdbuffer(_event,_key)   \
{\
   _event = l4c_kbd_buffer.kbd_data_buffer[l4c_kbd_buffer.kbd_data_buffer_rindex].Keyevent;\
   _key = l4c_kbd_buffer.kbd_data_buffer[l4c_kbd_buffer.kbd_data_buffer_rindex].Keydata[0];\
   l4c_kbd_buffer.kbd_data_buffer_rindex++;\
   l4c_kbd_buffer.kbd_data_buffer_rindex &= (kbd_buffer_size-1);\
}

#define l4c_clear_kbdbuffer() \
{\
   kal_mem_set(l4c_kbd_buffer.kbd_data_buffer, 0xff, sizeof(kbd_data)* kbd_buffer_size);\
   l4c_kbd_buffer.kbd_data_buffer_windex = 0 ;\
   l4c_kbd_buffer.kbd_data_buffer_rindex = 0 ;\
}

extern kal_bool l4c_kbd_getkeydata(kbd_data *keydata);

extern void l4cuem_leave_precharge_ind(void);

extern void l4cuem_pmic_config_cnf(kal_uint8 src_id, kal_uint8 request_type, pmic_config_param_struct request);

extern void l4cuem_rf_test_gsm_cnf(kal_uint8 src_id, kal_uint8 request_type, rf_test_gsm_param_struct request);

extern void l4cuem_fm_radio_config_cnf(kal_uint8 src_id, kal_uint8 request_type, fm_radio_config_param_struct request);

extern void l4cuem_rf_test_wifi_cnf(kal_uint8 src_id, kal_uint8 request_type, rf_test_wifi_param_struct request);

#endif /* l4c_eq_msg.h */


