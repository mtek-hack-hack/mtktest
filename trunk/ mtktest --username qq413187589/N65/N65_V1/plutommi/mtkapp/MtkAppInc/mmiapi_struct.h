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
 * mmiapi_struct.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines message structures of MMI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMIAPI_STRUCT_
#define _MMIAPI_STRUCT_
#include "mmiapi_enum.h"

typedef struct
{
    kal_bool is_blocking;
    kal_bool is_gui;
    kal_bool result;
    int result_int;
    void *result_ptr;
} mmiapi_blocking_data_struct;

typedef struct
{
    LOCAL_PARA_HDR mmiapi_remote_proc_call_enum type;
    void *func_ptr;                 /* Function to be executed remotely */
    void (*finish_callback) (void); /* Callback after operation finished */
    void *blocking_data;            /* Blocking operation */
    union
    {
        int i;                                      /* Integer argument */
        void *p;                                    /* Pointer argument */
    } _u;
      kal_bool(*validate_callback) (kal_uint32);    /* Check whether to execute or not */
    kal_uint32 optional_param;                      /* Optional argument used validate_callback */
} mmiapi_remote_proc_call_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 action_type;
    module_type src_mod_id;
} mmiapi_action_register_ind_struct;
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 action_type;
} mmiapi_action_notify_ind_struct;
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
} mmiapi_unread_push_icon_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 type;
} mmiapi_mms_icon_ind_struct;

typedef struct
{
    kal_uint16 src_mod_id;
    kal_uint8 action_type;
} mmiapi_action_msg_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 src_mod_id;
    kal_uint8 action;
    kal_uint32 reserved;
} mmiapi_device_get_ctrl_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 result;
} mmiapi_device_get_ctrl_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 src_mod_id;
    kal_uint8 type;
    kal_uint8 level;
    kal_uint32 reserved;
} mmiapi_device_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 result;
} mmiapi_device_play_rsp_struct;

#ifdef MMIAPI_USING_SMS
typedef struct
{
    LOCAL_PARA_HDR l4c_number_struct addr;
    int port_number;
    kal_uint8 *msg; /* this field should be free by free_ctrl_buffer */
    int msg_length;
    smsal_dcs_enum dcs;
    void *blocking_data;
} mmiapi_sms_send_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
} mmiapi_sms_send_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int port_number;
    kal_bool enable;
    kal_bool remove_reminder_data;
    kal_bool isSlave; /* If support Dual SIM, register master port: 0, slave SIM port: 1 */
    void *blocking_data;
} mmiapi_sms_register_port_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_uint16 cause;
} mmiapi_sms_register_port_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int port_number;
    kal_bool only_new;
    void *blocking_data;
} mmiapi_sms_check_incoming_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR int result;  /* 0: TEXT_MSG  1:BIN_MSG  -1: no message */
} mmiapi_sms_check_incoming_msg_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int port_number;
    void *blocking_data;
} mmiapi_sms_get_incoming_msg_timestamp_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 scts[7];
} mmiapi_sms_get_incoming_msg_timestamp_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int port_number;
    void *blocking_data;
} mmiapi_sms_get_incoming_msg_address_req_struct;

typedef struct
{
    LOCAL_PARA_HDR l4_addr_bcd_struct incoming_address;
} mmiapi_sms_get_incoming_msg_address_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int port_number;
    void *blocking_data;
} mmiapi_sms_get_incoming_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 *message;  /* this field should be free by free_ctrl_buffer */
    int message_len;
} mmiapi_sms_get_incoming_msg_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR void *blocking_data;
} mmiapi_sms_get_host_address_req_struct;

typedef struct
{
    LOCAL_PARA_HDR l4_addr_bcd_struct host_address;
} mmiapi_sms_get_host_address_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR int serial;
    int port_number;
    smsal_dcs_enum dcs;
} mmiapi_sms_ind_struct;

#endif /* MMIAPI_USING_SMS */ 

#ifdef MMIAPI_USING_UI
typedef struct
{
    LOCAL_PARA_HDR void *blocking_data;
    kal_uint8 *editor_buffer;
    int maxlen;
    int type;
    kal_bool is_must_input;
} mmiapi_ui_enter_fullscreen_editor_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    int text_length;
    int dummy_para1;
    int dummy_para2;
    int dummy_para3;
    int dummy_prar4;
} mmiapi_ui_enter_fullscreen_editor_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR void *blocking_data;
} mmiapi_ui_enter_idle_screen_req_struct;

#endif /* MMIAPI_USING_UI */ 

/* backlight control */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
    kal_uint8 disable_timer;
} mmiapi_backlight_control_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
    kal_uint8 disable_timer;
} mmiapi_backlight_control_rsp_struct;

/* led control */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
} mmiapi_led_control_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 on_off;
} mmiapi_led_control_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 strNumber[183]; /* MUST with null terminator */
}mmi_make_call_req_ind_struct;

/* Get battery info */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 src_mod_id; 
} mmiapi_get_battery_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 battery_level;
} mmiapi_get_battery_level_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 src_mod_id; 
} mmiapi_battery_level_notify_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_bool result;
} mmiapi_battery_level_notify_start_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 battery_level; 
} mmiapi_battery_level_notify_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 src_mod_id;
} mmiapi_battery_level_notify_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_bool result; 
} mmiapi_battery_level_notify_stop_rsp_struct;

#endif /* _MMIAPI_STRUCT_ */ 

