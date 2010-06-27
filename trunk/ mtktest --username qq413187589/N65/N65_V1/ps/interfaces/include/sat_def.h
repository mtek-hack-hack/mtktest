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
 *	sat_def.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file defines the data structure, enum and constant for SAT.
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


#ifndef SAT_DEF_H
#define SAT_DEF_H

extern kal_uint8 abm_get_sate_total_bearer(void);

#define SIZE_OF_CMD_DETAIL               5
#define SIZE_OF_SAT_LOCI                 7
#define SIZE_OF_CB_DATA                 88
#define SIZE_OF_SAT_ADDR_OR_SS_STRING  255
#define SIZE_OF_SAT_ADDR                41
#define SIZE_OF_SAT_SUBADDR             21
#define SIZE_OF_SAT_CCP                 13
#define SIZE_OF_SMS_DL_ACK             128

#define CSD_NWT_ACCT_ID (abm_get_sate_total_bearer())
#define GPRS_NWT_ACCT_ID (abm_get_sate_total_bearer()+1)

typedef enum
{
   CMD_DETAIL_TAG=1,
   DEVICE_ID_TAG,
   RESULT_TAG,
   DURATION_TAG,
   ALPHA_ID_TAG,
   ADDRESS_TAG,
   CCP_TAG,
   SUBADDR_TAG,
   SS_STRING_TAG,
   USSD_STRING_TAG,			/* 10 */
   SMS_TPDU_TAG,
   CB_PAGE_TAG,
   TEXT_STRING_TAG,
   TONE_TAG,
   ITEM_TAG,
   ITEM_ID_TAG,
   RSP_LEN_TAG,
   FILE_LIST_TAG,
   LOCI_TAG,
   IMEI_TAG,						/* 20 */
   HELP_REQ_TAG,
   NET_MEASURE_RES_TAG,
   DEFAULT_TEXT_TAG,
   ITEM_NEXT_ACTION_IND_TAG,
   EVENT_LIST_TAG,
   CAUSE_TAG,
   LOCATION_STATUS_TAG,
   TID_TAG,
   BCCH_CHAN_LIST_TAG,
   ICON_ID_TAG,					/* 30 */
   ITEM_ICON_ID_LIST_TAG,
   CARD_READER_STATUS_TAG,
   CARD_ATR_TAG,
   C_APDU_TAG,
   R_APDU_TAG,
   TIMER_ID_TAG,
   TIMER_VALUE_TAG,
   DATE_TIME_ZONE_TAG,
   CC_REQ_ACTION_TAG,
   AT_CMD_TAG,					/* 40 */
   AT_RSP_TAG,
   BC_REPEAT_IND_TAG,
   IMMEDIATE_RSP_TAG,
   DTMF_STRING_TAG,
   LANGUAGE_TAG,
   TA_TAG,
   RFU1_TAG,
   BROWSER_ID_TAG,
   URL_TAG,
   BEARER_TAG,					/* 50 */
   PROVISIONING_REF_FILE_TAG,
   BROWSER_TERMINATION_CAUSE_TAG,
   BEARER_DESCRIPTION_TAG,
   CHAN_DATA_TAG,
   CHAN_DATA_LEN_TAG,
   CHAN_STATUS_TAG,
   BUFFER_SIZE_TAG,
   CARD_READER_ID_TAG,
   RFU2_TAG,
   SIM_ME_INTERFACE_LEVEL_TAG,/* 60 */
   RFU3_TAG,
   OTHER_ADDR_TAG,
   RFU4_TAG,
   RFU5_TAG,
   NETWORK_ACCESS_NAME_TAG=0x47,
   PROACTIVE_CMD_TAG=0xD0,
   SMS_PP_DL_TAG,
   CB_DL_TAG,
   MENU_SELECTION_TAG,
   CALL_CONTROL_TAG,
   MO_SMS_CONTROL_TAG,
   EVENT_DL_TAG,
   TIMER_EXPIR_TAG,
   RFU6_TAG=0xDF
}sat_tag_enum;

typedef enum
{
   CMD_REFRESH=0x01,
   CMD_MORE_TIME=0x02,
   CMD_POLL_INTERVAL=0x03,    
   CMD_POLLING_OFF=0x04,   
   CMD_SETUP_EVENT_LIST=0x05,    
   CMD_SETUP_CALL=0x10,
   CMD_SEND_SS=0x11,
   CMD_SEND_USSD=0x12,
   CMD_SEND_SMS=0x13,
   CMD_DTMF=0x14,
   CMD_LAUNCH_BROWSER=0x15,
   CMD_PLAY_TONE=0x20,
   CMD_DSPL_TXT=0x21,
   CMD_GET_INKEY=0x22,
   CMD_GET_INPUT=0x23,
   CMD_SELECT_ITEM=0x24,
   CMD_SETUP_MENU=0x25,
   CMD_PROVIDE_LOCAL_INFO=0x26,
   CMD_TIMER_MANAGER=0x27,
   CMD_IDLE_MODEL_TXT=0x28,
   CMD_PERFORM_CARD_APDU=0x30,
   CMD_POWER_ON_CARD=0x31,
   CMD_POWER_OFF_CARD=0x32,
   CMD_GET_READER_STATUS=0x33,
   CMD_RUN_AT=0x34,
   CMD_LANGUAGE_NOTIFY=0x35,
   CMD_OPEN_CHAN=0x40,
   CMD_CLOSE_CHAN=0x41,
   CMD_RECEIVE_DATA=0x42,
   CMD_SEND_DATA=0x43,
   CMD_GET_CHAN_STATUS=0x44,
   CMD_RFU=0x60,
   CMD_END_PROACTIVE_SESSION=0x81,
   CMD_DETAIL=0xFF
}sat_proactive_cmd_enum;

typedef enum
{
   ENV_SMS_DL,
   ENV_CB_DL,
   ENV_MENU_SELECT,    
   ENV_CALL_CTRL_BY_SIM,   
   ENV_SMS_CTRL_BY_SIM    
}sat_envelope_cmd_enum;

typedef enum
{
   EVDL_MT_CALL,
   EVDL_CALL_CONNECT,
   EVDL_CALL_DISCONNECT,
   EVDL_LOCATION_STATUS,
   EVDL_USER_ACTIVITY,
   EVDL_IDLE_SCREEN_AVAILABLE,
   EVDL_CARD_READER_STATUS,
   EVDL_LANGUAGE_SELECTION,
   EVDL_BROWSER_TERMINATION,
   EVDL_DATA_AVAILABLE,
   EVDL_CHANNEL_STATUS
}sat_event_download_enum;

typedef enum
{
   SAT_UNPACKED_SMS_ALPHABET=0x04,
   SAT_UCS2_ALPHABET=0x08
}sat_dcs_enum;

typedef enum
{
   TIME_MIN,
   TIME_SEC,
   TIME_TENTHS_OF_SEC    
}sat_time_unit_enum;

typedef enum
{
   TYPE_ONLY_DIGIT,         // mtk01488: digit only and sms default alphabet
   TYPE_SMS_DEFAULT_SET,    // mtk01488: alphabet set and SMS default alphabet
   TYPE_UCS2,               // mtk01488: alphabet set and UCS2 alphabet
   TYPE_YES_NO,
   TYPE_ONLY_DIGIT_UCS2     // mtk01488: digit only and UCS2 alphabet
}sat_input_type_enum;

typedef enum
{
   PRI_NORMAL=0,
   PRI_HIGH=1
}sat_dspl_priority_enum;

typedef enum
{
   CLEAR_AFTER_DELAY=0,
   CLEAR_BY_USR=1
}sat_clear_text_enum;

typedef enum
{
   ICON_DSPL_BUT_REPLACE_TEXT=0,
   ICON_DSPL_WITH_TEXT=1
}sat_icon_qualifier_enum;

typedef enum
{
   PRESENT_TYPE_NONE,
   PRESENT_TYPE_DATA_VALUE,
   PRESENT_TYPE_NAVI    
}sat_select_item_presentation_type_enum;

typedef enum
{
   SAT_SETUP_CALL=ADDRESS_TAG,
   SAT_SEND_SS=SS_STRING_TAG,
   SAT_SEND_USSD=USSD_STRING_TAG    
}sat_call_ctrl_type_enum;

typedef enum
{
   TYPE_LOCATION_INFO=0,
   TYPE_IMEI,
   TYPE_NET_MEASURE,
   TYPE_DATE_TIME_ZONE,
   TYPE_LANGUAGE_SET,
   TYPE_TIMING_ADVANCE    
}sat_local_info_enum;

typedef enum
{
   SAT_ALLOWED_NO_MODIFICATION=0,
   SAT_NOT_ALLOWED,
   SAT_ALLOWED_WITH_MODIFICATION,
   SAT_SIM_ERROR
}sat_call_ctrl_by_sim_result_enum;

typedef enum
{
   DEVICE_KEYPAD=0x01,
   DEVICE_DISPLAY=0x02,
   DEVICE_EARPIECE=0x03,    
   DEVICE_ADDITIONAL_CARD_READER_0=0x10,   
   DEVICE_ADDITIONAL_CARD_READER_1=0x11,
   DEVICE_ADDITIONAL_CARD_READER_2=0x12,   
   DEVICE_ADDITIONAL_CARD_READER_3=0x13,
   DEVICE_ADDITIONAL_CARD_READER_4=0x14,   
   DEVICE_ADDITIONAL_CARD_READER_5=0x15,
   DEVICE_ADDITIONAL_CARD_READER_6=0x16,   
   DEVICE_ADDITIONAL_CARD_READER_7=0x17,            
   DEVICE_CHAN_1=0x21,
   DEVICE_CHAN_2=0x22,      
   DEVICE_CHAN_3=0x23,
   DEVICE_CHAN_4=0x24,      
   DEVICE_CHAN_5=0x25,
   DEVICE_CHAN_6=0x26,      
   DEVICE_CHAN_7=0x27,
   DEVICE_SIM=0x81,
   DEVICE_ME=0x82,
   DEVICE_NET=0x83
}sat_device_id_enum;

typedef enum
{
   SAT_CMD_PERFORMED_SUCCESSFULLY=	0,
   SAT_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION=	0X01,
   SAT_CMD_PERFORMED_WITH_MISSING_INFO=	0X02,
   SAT_REFRESH_PERFORMED_WITH_ADDITIONAL_EF_READ=	0X03,
   SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL=	0X04,
   SAT_CMD_PERFORMED_BUT_MODIFIED_CC_BY_SIM=	0X05,
   SAT_CMD_PERFORMED_LIMITED_SERVICE=	0X06,
   SAT_CMD_PERFORMED_WITH_MODIFIED=	0X07,
   SAT_PROACTIVE_CMD_TERMINATED_BY_USER=	0X10,
   SAT_BACKWARD_MOVE_IN_PROACTIVE_SESSION_BY_USER=	0X11,
   SAT_NO_RESPONSE_FROM_USER=	0X12,
   SAT_HELP_INFO_REQUEST_BY_USER=	0X13,
   SAT_USSD_SS_TRANSACTION_TERMINATION_BY_USER=	0X14,
   SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD=	0X20,
   SAT_NET_CURRENTLY_UNABLE_TO_PROCESS_CMD=	0X21,
   SAT_USER_DID_NOT_ACCEPT_THE_PROACTIVE_CMD=	0X22,
   SAT_USER_CLEAR_DOWN_CALL_BEFORE_CONNECTION_RELEASE=	0X23,
   SAT_ACTION_IN_CONTRACTION_WITH_CURRENT_TIMER_STATE=	0X24,
   SAT_INTERACTION_WITH_CALL_CTRL_BY_SIM_TEMPORARY_ERROR=	0X25,
   SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE=	0X26,
   SAT_CMD_BEYOND_ME_CAP=	0X30,
   SAT_CMD_TYPE_NOT_UNDERSTAND_BY_ME=	0X31,
   SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME=	0X32,
   SAT_CMD_NUMBER_NOT_KNOWN_BY_ME=	0X33,
   SAT_SS_RETURN_ERROR=	0X34,
   SAT_SMS_RP_ERROR=	0X35,
   SAT_ERROR_REQUIRED_VALUE_MISSING=	0X36,
   SAT_USSD_RETURN_ERROR=	0X37,
   SAT_MULTICARD_CMD_ERROR=	0X38,
   SAT_INTERACTION_WITH_CALL_CTRL_BY_SIM_PERMANENT_ERROR=	0X39,
   SAT_BEARER_INDEPENDENT_PROTOCOL_ERROR=	0X3A
}sat_terminal_res_enum;

typedef enum
{
   SAT_NO_SPECIFIC_CAUSE,
   SAT_SCREEN_BUSY,
   SAT_ME_CURRENTLY_BUSY_ON_CALL,
   SAT_ME_CURRENTLY_BUSY_ON_SS,
   SAT_NO_SERVICE,
   SAT_ACCESS_CTRL_CLASS_BAR,
   SAT_RR_NOT_BRANTED,
   SAT_NOT_IN_SPEECH_MODE,
   SAT_ME_CURRENTLY_BUSY_ON_USSD,
   SAT_ME_CURRENTLY_BUSY_ON_DTMF
}sat_additional_info_for_res_enum;

typedef enum
{
    SAT_BIP_NO_SPECIFIC_CAUSE,
    SAT_BIP_NO_CHANNEL_AVAILABLE,
    SAT_BIP_CHANNEL_CLOSED,
    SAT_BIP_CHANNEL_IDENTIFIER_NOT_VALID,
    SAT_BIP_REQUESTED_BUFFER_SIZE_NOT_AVAILABLE,
    SAT_BIP_SECURITY_ERROR,
    SAT_BIP_REQUESTED_TRANSPORT_LEVEL_NOT_AVAILABLE
}sat_bearer_independent_protocol_additional_info_for_res_enum;

typedef enum
{
    SAT_CSD_BEARER = 0x01,
    SAT_GPRS_BEARER
}sat_bearer_enum;

typedef enum
{
    SAT_UDP_PROTOCOL = 0x01,
    SAT_TCP_PROTOCOL,
    SAT_RAW_PROTOCOL
}sat_protocol_type_enum;


/*
typedef enum
{
    CSD_NWT_ACCT_ID = 0x15,
    GPRS_NWT_ACCT_ID = 0x16
}sat_nwt_acct_id_enum;
*/

typedef enum
{
    SAT_CLOSE_CHANNEL_FINISHED,
    SAT_SEND_DATA_FINISHED,
    SAT_SEND_DATA_TERMINATED,
    SAT_RECEIVE_DATA_FINISHED,
    SAT_RECEIVE_DATA_TERMINATED,    
    SAT_DISCONNECT_EVENT_DOWNLOAD
} sat_notify_mmi_enum;

typedef enum
{
   SAT_LAUNCH_BROWSER_IF_NOT_ALREADY_LAUNCHED = 0x00,
   SAT_USE_EXISTING_BROWSER = 0x02,
   SAT_CLOSE_EXISTING_BROWSER_AND_LAUNCH_NEW = 0x03
}sat_launch_browser_mode_enum;

typedef enum
{
   SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE,
   SAT_LAUNCH_BROWSER_BEARER_UNAVALIABLE,
   SAT_LAUNCH_BROWSER_BROWSER_UNAVALIABLE,
   SAT_LAUNCH_BROWSER_ME_UNABLE_TO_READ_PROVISION_DATA
}sat_launch_browser_additional_info_for_res_enum;

typedef enum
{
   SAT_BROWSER_USER_TERMINATION,
   SAT_BROWSER_ERROR_TERMINATION
}sat_browser_termination_mode_enum;

/* proactive SIM command struct */
typedef enum
{
   SETUP_CALL_IF_NO_ANOTHER_CALL,
   SETUP_CALL_WITH_REDIAL_IF_NO_ANOTHER_CALL,
   SETUP_CALL_PUT_ANOTHER_HOLD,    
   SETUP_CALL_WITH_REDIAL_PUT_ANOTHER_HOLD,   
   SETUP_CALL_DISCON_ANOTHER,    
   SETUP_CALL_WITH_REDIAL_DISCON_ANOTHER   
}sat_setup_call_condition_enum;

typedef enum
{
   SAT_DL_BUSY,
   SAT_DL_ERROR
}sat_sms_dl_error_cause_enum;
 
typedef enum
{
   SAT_RR_IDLE,
   SAT_RR_NOT_IDLE
}sat_me_status_enum;

typedef enum
{
   SAT_OPERATION_CHANGED_BY_SIM,
   SAT_NUM_CHANGED_BY_SIM,
   SAT_ALPHA_ID_IND,
   SIM_MEM_PROBLEM,
   SIM_SECRET_CODE_REJ,
   SIM_TECH_PROBLEM
}sat_mmi_info_type_enum;

typedef enum
{
   SAT_TONE_DIAL=0x01,
   SAT_TONE_CALLED_SUBSCRIBER_BUSY=0x02,
   SAT_TONE_CONGESTION=0x03,
   SAT_TONE_RADIO_PATH_ACK=0x04,
   SAT_TONE_RADIO_NO_PATH=0x05,
   SAT_TONE_ERROR=0x06,
   SAT_TONE_CALL_WAITING=0x07,
   SAT_TONE_RING=0x08,
   SAT_TONE_GENERAL_BEEP=0x10,
   SAT_TONE_POS_ACK=0x11,
   SAT_TONE_NEG_ACK=0x12
}sat_tone_id_enum;

typedef enum
{
   SAT_NO_CHANNEL=0x00,
   SAT_CH1=0x21,
   SAT_CH2=0x22,
   SAT_CH3=0x23,
   SAT_CH4=0x24,
   SAT_CH5=0x25,
   SAT_CH6=0x26,
   SAT_CH7=0x27
}sat_channel_id_enum;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

kal_bool sat_create_timer (void);

/* terminal response related struct */

#endif


