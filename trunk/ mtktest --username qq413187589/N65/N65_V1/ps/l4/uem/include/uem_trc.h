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
 * uem_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _UEM_TRC_H
#define _UEM_TRC_H

#ifndef GEN_FOR_PC
#ifndef _STACK_CONFIG_H
#error "stack_config.h should be included before uem_trc.h"
#endif 
#else /* GEN_FOR_PC */ 
#include "kal_trace.h"
#endif /* GEN_FOR_PC */ 

#ifndef _KAL_TRACE_H
#error "kal_trace.h should be included before uem_trc.h"
#endif 

BEGIN_TRACE_MAP(MOD_UEM)
   /***************TRC MSG FOR UEM BEGIN ********************/
    /* TRACE_FUNC trace class */
    /* ----------------------- uem_msg_hdlr.c log ----------------------- */
    TRC_MSG(FUNC_UEM_KEYPAD_POWER_ON_IND, "uemdrv_keypad_power_on_ind_hdlr")
TRC_MSG(FUNC_UEM_ALARM_POWER_ON_IND, "uemdrv_alarm_power_on_ind_hdlr")
TRC_MSG(FUNC_UEMRTC_PERIOD_IND, "uemdrv_rtc_period_ind_hdlr")
TRC_MSG(FUNC_UEM_PMIC_IND, "uemdrv_pmic_ind_hdlr")
TRC_MSG(FUNC_UEM_WRITE_DATA_CNF, "uemnvm_write_data_cnf_hdlr")
TRC_MSG(FUNC_UEM_READ_DATA_CNF, "uemnvm_read_data_cnf_hdlr")
TRC_MSG(FUNC_UEM_SET_PROFILE_REQ, "ueml4c_set_profile_req_hdlr")
TRC_MSG(FUNC_UEM_STARTUP_REQ, "ueml4c_startup_req_hdlr")
TRC_MSG(FUNC_UEM_LANGUAGE_REQ, "uemsat_language_req_hdlr")
TRC_MSG(FUNC_UEM_CURRENT_TIME_REQ, "uemsat_current_time_req_hdlr") TRC_MSG(FUNC_UEM_EM_REQ, "ueml4c_em_req_hdlr")
    /* ----------------------- uem_proc_cmd.c log ----------------------- */
    TRC_MSG(FUNC_UEM_AUDIO_PLAY, "l4cuem_audio_play_req")
TRC_MSG(FUNC_UEM_AUDIO_STOP, "l4cuem_audio_stop_req")
TRC_MSG(FUNC_UEM_DEMO_EXT_IMELODY_RING, "l4cuem_demo_ext_imelody_ring_req")
TRC_MSG(FUNC_UEM_POEWR_OFF, "l4cuem_power_off_req")
TRC_MSG(FUNC_UEM_RTC_GET_TIME, "l4cuem_rtc_get_time_req")
TRC_MSG(FUNC_UEM_RTC_SET_TIME, "l4cuem_rtc_set_time_req")
TRC_MSG(FUNC_UEM_ALARM_GET_TIME, "l4cuem_alarm_get_time_req")
TRC_MSG(FUNC_UEM_RTC_CNFG_FORMAT, "l4cuem_rtc_cnfg_format_req")
TRC_MSG(FUNC_UEM_RTC_DELETE_DATE_TIME, "l4cuem_rtc_delete_date_time_req")
TRC_MSG(FUNC_UEM_SET_MUTE, "l4cuem_set_mute_req")
TRC_MSG(FUNC_UEM_GET_MUTE, "l4cuem_get_mute_req")
TRC_MSG(FUNC_UEM_GPIO_SET_LEVEL, "l4cuem_gpio_set_level_req")
TRC_MSG(FUNC_UEM_GET_EQUIP_ID, "l4cuem_get_equip_id_req")
TRC_MSG(FUNC_UEM_GET_BATTERY_STATUS, "l4cuem_get_battery_status_req")
TRC_MSG(FUNC_UEM_SET_SILENT_MODE, "l4cuem_set_silent_mode_req")
TRC_MSG(FUNC_UEM_GET_SILENT_MODE, "l4cuem_get_silent_mode_req")
TRC_MSG(FUNC_UEM_SET_ALERT_MODE, "l4cuem_set_alert_mode_req")
TRC_MSG(FUNC_UEM_GET_ALERT_MODE, "l4cuem_get_alert_mode_req")
TRC_MSG(FUNC_UEM_SET_GREETING_TEXT, "l4cuem_set_greeting_text_req")
TRC_MSG(FUNC_UEM_GET_GREETING_TEXT, "l4cuem_get_greeting_text_req")
TRC_MSG(FUNC_UEM_GPIO_GET_LEVEL, "l4cuem_gpio_get_level_req")
TRC_MSG(FUNC_UEM_EQUIP_SET_CC, "l4cuem_equip_set_cc_req")
TRC_MSG(FUNC_UEM_EQUIP_GET_CC, "l4cuem_equip_get_cc_req")
TRC_MSG(FUNC_UEM_SET_LANG, "l4cuem_set_lang_req")
TRC_MSG(FUNC_UEM_GET_LANG, "l4cuem_get_lang_req")
TRC_MSG(FUNC_UEM_SET_DATE_TIME_FORMAT, "l4cuem_set_date_time_format_req")
TRC_MSG(FUNC_UEM_GET_DATE_TIME_FORMAT, "l4cuem_get_date_time_format_req")
TRC_MSG(FUNC_UEM_POWER_RESET, "l4cuem_power_reset")
    /* ----------------------- uem_proc_msg.c log ----------------------- */
    TRC_MSG(FUNC_UEM_ALARM_DETECT, "uemdrv_alarm_detect_ind")
TRC_MSG(FUNC_UEM_RTC_PERIOD, "uemdrv_rtc_period_ind")
TRC_MSG(FUNC_UEM_KEYPAD_POWER_ON, "uemdrv_keypad_power_on_ind")
TRC_MSG(FUNC_UEM_PMIC_DETECT, "uemdrv_pmic_ind") TRC_MSG(FUNC_UEM_GPIO_DETECT, "uemdrv_gpio_detect_ind")
    /* ----------------------- uem_utility.c log ----------------------- */
    TRC_MSG(FUNC_UEM_SEND_MSG_TO_L4C, "uem_send_msg_to_l4c")
TRC_MSG(FUNC_UEM_SEND_MSG_TO_NVRAM, "uem_send_msg_to_nvram")
TRC_MSG(FUNC_UEM_SEND_MSG_TO_SAT, "uem_send_msg_to_sat")
TRC_MSG(FUNC_UEM_SEND_MSG_TO_AUD, "uem_send_msg_to_aud")
TRC_MSG(FUNC_UEM_SEND_MSG_TO_BMT, "uem_send_msg_to_bmt") TRC_MSG(FUNC_UEM_SEND_MSG_TO_UEM, "uem_send_msg_to_uem")
    /* TRACE_INFO trace class */
    /* ----------------------- uem_msg_hdlr.c log ----------------------- */
    TRC_MSG(INFO_UEM_SPEECH_SET_MODE, "l4cuem_speech_set_mode_req =%d")
    /* TRACE_STATE trace class */
    /* TRACE_WARNING trace class */
    /* ----------------------- uem_msg_hdlr.c log ----------------------- */
    TRC_MSG(WARNING_UEM_OUT_OF_RANGE, "out of range!")
    /* TRACE_ERROR trace class */
    /* ----------------------- uem_msg_hdlr.c log ----------------------- */
    TRC_MSG(ERROR_UEM_NVRAM_DATA_LEN, "nvram read data not match, original=%d nvram=%d data!")
   /***************TRC MSG FOR UEM END ********************/
    END_TRACE_MAP(MOD_UEM)
#endif /* _UEM_TRC_H */ 

