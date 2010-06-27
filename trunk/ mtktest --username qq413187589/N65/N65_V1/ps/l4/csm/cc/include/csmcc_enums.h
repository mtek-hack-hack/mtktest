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
 *	csmcc_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for enum types used in CSM(CC) module.
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


#ifndef _CSMCC_ENUMS_H
#define _CSMCC_ENUMS_H

/* The following enum types are used in CSMCC message handler */

typedef enum
{
   CSMCC_NO_REQ, /*0*/
   CSMCC_CALL_SETUP_REQ, /*1*/
   CSMCC_EMERGENCY_CALL_SETUP_REQ, /*2*/
   CSMCC_CALL_ACCEPT_REQ, /*3*/
   CSMCC_CALL_PREEMPT_REQ, /*4, non-L4C request */
   CSMCC_AUTO_ANSWER_REQ, /*5, non-L4C request */
   CSMCC_REL_HELD_OR_UDUB_REQ, /*6*/
   CSMCC_REL_ACTIVE_AND_ACCEPT_REQ, /*7*/
   CSMCC_REL_SPECIFIC_ACTIVE_CALL_REQ,/*8*/
   CSMCC_HOLD_ACTIVE_AND_ACCEPT_REQ, /*9*/
   CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL_REQ, /*10*/
   CSMCC_ADD_HELD_CALL_REQ, /*11*/
   CSMCC_EXPLICIT_CALL_TRANSFER_REQ, /*12*/
   CSMCC_CALL_DEFLECTION_REQ, /*13*/
   CSMCC_ACTIVATE_CCBS_CALL_REQ, /*14*/
   CSMCC_CALL_DISC_REQ, /*15*/
   CSMCC_MO_MODIFY_REQ, /*16*/
   CSMCC_REL_ALL_EXCEPT_WAITING_CALL_REQ, /*17*/
   CSMCC_ACMMAX_SET_REQ, /* 18 */
   CSMCC_ACM_RESET_REQ, /* 19 */
   CSMCC_SAT_SETUP_REQ, /* 20 */
   CSMCC_MT_MODIFY_REQ, /* 21, non-L4C request */
   CSMCC_ACCEPT_WAITING_CALL_REQ, /* 22, aux request */
   CSMCC_ACCEPT_CCBS_CALL_REQ, /* 23, aux request */
   CSMCC_ACCEPT_HELD_CALL_REQ, /* 24, aux request */
   CSMCC_WAIT_DATA_DEACTIVATE_REQ, /* 25, aux request */
   CSMCC_ALERTING_REQ, /* 26, non-L4C request */
   CSMCC_STARTUP_REQ, /* 27 */
   CSMCC_SAT_FILE_CHANGE_REQ, /* 28 */
   CSMCC_REL_SPECIFIC_CALL_REQ,/* 29 */
   CSMCC_UPDATE_ALS_REQ, /*30*/
   CSMCC_REL_ACTIVE_REQ, /* 31 */
   CSMCC_REL_HELD_REQ, /* 32 */
   CSMCC_SET_CSD_PROF_REQ, /* 33 */
   CSMCC_REL_ALL_REQ /* 34 */
} csmcc_req_enum;

/* The following enum types ared used to describe bc parameters */

typedef enum
{
   CSMCC_FR_ONLY = 1,
   CSMCC_DUAL_HR_PREF,
   CSMCC_DUAL_FR_PREF
} csmcc_radio_channel_enum;

typedef enum
{
   CSMCC_CIRCUIT_MODE,
   CSMCC_PACKET_MODE
} csmcc_transfer_mode_enum;

typedef enum
{
   CSMCC_SYNC_DATA,
   CSMCC_ASYNC_DATA
} csmcc_sync_enum;

typedef enum
{
   CSMCC_ITC_SPEECH,
   CSMCC_ITC_UDI,
   CSMCC_ITC_3_1_K_AUDIO,
   CSMCC_ITC_FAX_GROUP_3,
   CSMCC_OTHER_ITC = 5,
   CSMCC_ITC_AUX_SPEECH = 6,
   CSMCC_ITC_RESERVED = 7
} csmcc_itc_enum;

typedef enum
{
   CSMCC_ITC_RDI
} csmcc_other_itc_enum;

typedef enum
{
   CSMCC_UR_0_3_K = 1,
   CSMCC_UR_1_2_K,
   CSMCC_UR_2_4_K,
   CSMCC_UR_4_8_K,
   CSMCC_UR_9_6_K,
   CSMCC_UR_12_K
} csmcc_user_rate_enum;

typedef enum
{
   CSMCC_FNUR_NM,
   CSMCC_FNUR_9_6_K,
   CSMCC_FNUR_14_4_K,
   CSMCC_FNUR_19_2_K,
   CSMCC_FNUR_28_8_K,
   CSMCC_FNUR_38_4_K,
   CSMCC_FNUR_48_K,
   CSMCC_FNUR_56_K,
   CSMCC_FNUR_64_K,
   CSMCC_FNUR_33_6_K,
   CSMCC_FNUR_32_K,
   CSMCC_FNUR_31_2_K
} csmcc_fnur_enum;

typedef enum
{
   CSMCC_RA_NONE,
   CSMCC_RA_V110,
   CSMCC_RA_X31,
   CSMCC_RA_OTHER
} csmcc_rate_adaptation_enum;

typedef enum
{
   CSMCC_RA_V120,
   CSMCC_RA_H223,
   CSMCC_RA_PIAFS
} csmcc_other_rate_adaptation_enum;

typedef enum
{
   CSMCC_MT_NONE,
   CSMCC_MT_V21,
   CSMCC_MT_V22,
   CSMCC_MT_V22_BIS,
   CSMCC_MT_V26_TER = 5,
   CSMCC_MT_V32,
   CSMCC_MT_UNDEFINED,
   CSMCC_MT_AUTOBAUDING
} csmcc_modem_type_enum;

typedef enum
{
   CSMCC_OTHER_MT_NONE,
   CSMCC_MT_V34 = 2
} csmcc_other_modem_type_enum;

typedef enum
{
   CSMCC_FR_V1,
   CSMCC_HR_V1,
   CSMCC_FR_V2,
   CSMCC_FR_V3 = 4,
   CSMCC_HR_V3
} csmcc_speech_ver_enum;

typedef enum
{
   CSMCC_NO_DATA_COMPRESS,
   CSMCC_DATA_COMPRESS
} csmcc_data_compression_enum;

typedef enum
{
   CSMCC_SDU_INTEGRITY,
   CSMCC_UNSTRUCTURED = 3
} csmcc_structure_enum;

typedef enum
{
   CSMCC_HALF_DUPLEX,
   CSMCC_FULL_DUPLEX	
} csmcc_duplex_mode_enum;

typedef enum
{
   CSMCC_NIRR_NO_MEANING,
   CSMCC_NIRR_REQUESTED
} csmcc_nirr_enum;

typedef enum
{
   CSMCC_SAP_I440_450 = 1,
   CSMCC_SAP_X32 = 6
} csmcc_sap_enum;

typedef enum
{
   CSMCC_IR_8_K = 2,
   CSMCC_IR_16_K
} csmcc_intermediate_rate_enum;

typedef enum
{
   CSMCC_NO_NIC_ON_TX,
   CSMCC_NIC_ON_TX
} csmcc_nic_on_tx_enum;

typedef enum
{
   CSMCC_NO_NIC_ON_RX,
   CSMCC_NIC_ON_RX
} csmcc_nic_on_rx_enum;

typedef enum
{
   CSMCC_UIMI_NOT_ALLOWED,
   CSMCC_UIMI_UPTO_1_TCH,
   CSMCC_UIMI_UPTO_2_TCH,
   CSMCC_UIMI_UPTO_3_TCH,
   CSMCC_UIMI_UPTO_4_TCH
} csmcc_uimi_enum;

typedef enum
{
   CSMCC_UIL2P_X25 = 6,
   CSMCC_UIL2P_ISO_6429 = 8,
   CSMCC_UIL2P_VICEOTEX = 10,
   CSMCC_UIL2P_COP_NO_FLCT = 12,
   CSMCC_UIL2P_X75
} csmcc_uil2p_enum;

typedef enum
{
   CSMCC_1_STOP_BIT,
   CSMCC_2_STOP_BIT
} csmcc_nsb_enum;

typedef enum
{
   CSMCC_7_DATA_BIT,
   CSMCC_8_DATA_BIT
}csmcc_ndb_enum;

typedef enum
{
   CSMCC_PARITY_ODD,
   CSMCC_PARITY_EVEN = 2,
   CSMCC_PARITY_NONE,
   CSMCC_PARITY_FORCED_0,
   CSMCC_PARITY_FORCED_1
} csmcc_parity_enum;

typedef enum
{
   CSMCC_1_TCH,
   CSMCC_2_TCH,
   CSMCC_3_TCH,
   CSMCC_4_TCH,
   CSMCC_5_TCH,
   CSMCC_6_TCH,
   CSMCC_7_TCH,
   CSMCC_8_TCH
} csmcc_max_tch_enum;

typedef enum
{
   CSMCC_AIUR_NM,
   CSMCC_AIUR_9_6_K,
   CSMCC_AIUR_14_4_K,
   CSMCC_AIUR_19_2_K,
   CSMCC_AIUR_28_8_K = 5,
   CSMCC_AIUR_38_4_K,
   CSMCC_AIUR_43_2_K,
   CSMCC_AIUR_57_6_K
} csmcc_waiur_enum;

typedef enum
{
   CSMCC_ALTERNATE_MODE = 1,
   CSMCC_FALLBACK_MODE,
   CSMCC_SEQUENTIAL_MODE
} csmcc_repeat_ind_enum;

/* The following enum types are used to describe AT parameters */

typedef enum
{
   CSMCC_DEFAULT_ADDR_TYPE = 129,
   CSMCC_INTERNATIONAL_ADDR = 145
   
} csmcc_addr_type_enum;

typedef enum
{
   CSMCC_SINGLE_MODE,
   CSMCC_ALT_VOICE_FAX,
   CSMCC_ALT_VOICE_DATA,
   CSMCC_VOICE_FOLLOW_DATA,
   CSMCC_INVALID_CALL_MODE = 255
} csmcc_call_mode_enum;

typedef enum
{
   CSMCC_AUTOBAUDING,
   CSMCC_2400_BPS_V22BIS = 4,
   CSMCC_2400_BPS_V26TER = 5,
   CSMCC_4800_BPS_V32 = 6,
   CSMCC_9600_BPS_V32 = 7,
   CSMCC_9600_BPS_V34 = 12,
   CSMCC_14400_BPS_V34 = 14,
   CSMCC_19200_BPS_V34 = 15,
   CSMCC_28800_BPS_V34 = 16,
   CSMCC_2400_BPS_V120 = 36,
   CSMCC_4800_BPS_V120 = 38,
   CSMCC_9600_BPS_V120 = 39,
   CSMCC_14400_BPS_V120 = 43,
   CSMCC_19200_BPS_V120 = 47,
   CSMCC_28800_BPS_V120 = 48,
   CSMCC_38400_BPS_V120 = 49,
   CSMCC_48000_BPS_V120 = 50,
   CSMCC_56000_BPS_V120 = 51,
   CSMCC_2400_BPS_V110 = 68,
   CSMCC_4800_BPS_V110 = 70,
   CSMCC_9600_BPS_V110 = 71,
   CSMCC_14400_BPS_V110 = 75,
   CSMCC_19200_BPS_V110 = 79,
   CSMCC_28800_BPS_V110 = 80,
   CSMCC_38400_BPS_V110 = 81,
   CSMCC_48000_BPS_V110 = 82,
   CSMCC_56000_BPS_V110 = 83,
   CSMCC_INVALID_SPEED = 255
} csmcc_bearer_speed_enum;

typedef enum
{
   CSMCC_DATA_ASYNC,
   CSMCC_DATA_SYNC,
   CSMCC_PDA_UDI,
   CSMCC_PACKET_UDI,
   CSMCC_DATA_ASYNC_RDI,
   CSMCC_DATA_SYNC_RDI,
   CSMCC_PDA_RDI,
   CSMCC_PACKET_RDI,
   CSMCC_INVALID_BEARER_NAME = 255
} csmcc_bearer_name_enum;

typedef enum
{
   CSMCC_TRANSPARENT,
   CSMCC_NON_TRANSPARENT,
   CSMCC_TRANSPARENT_PREF,
   CSMCC_NON_TRANSPARENT_PREF,
   CSMCC_INVALID_BEARER_CE = 255 /*mtk00924: remove warning C2874W may be used before being set*/
} csmcc_bearer_ce_enum;

typedef enum
{
   CSMCC_SNS_VOICE,
   CSMCC_SNS_ALT_VOICE_FAX_VOICE_FIRST,
   CSMCC_SNS_FAX,
   CSMCC_SNS_ALT_VOICE_DATA_VOICE_FIRST,
   CSMCC_SNS_DATA,
   CSMCC_SNS_ALT_VOICE_FAX_FAX_FIRST,
   CSMCC_SNS_ALT_VOICE_DATA_DATA_FIRST,
   CSMCC_SNS_VOICE_FOLLOW_DATA
} csmcc_sns_mode_enum;

typedef enum
{
   CSMCC_CF_PARITY_AUTODETECT,
   CSMCC_CF_8_DATA_2_STOP,
   CSMCC_CF_8_DATA_1_PARITY_1_STOP,
   CSMCC_CF_8_DATA_1_STOP,
   CSMCC_CF_7_DATA_2_STOP,
   CSMCC_CF_7_DATA_1_PARITY_1_STOP,
   CSMCC_CF_7_DATA_1_STOP
} csmcc_cf_format_enum;

typedef enum
{
   CSMCC_CF_PARITY_ODD,
   CSMCC_CF_PARITY_EVEN,
   CSMCC_CF_PARITY_MARK,
   CSMCC_CF_PARITY_SPACE
} csmcc_cf_parity_enum;

typedef enum
{
   CSMCC_RAH_NOT_INCLUDED,
   CSMCC_RAH_INCLUDED
} csmcc_v120_rah_enum;

typedef enum
{
   CSMCC_MULTI_FRAME_EST_NOT_SUPPORT,
   CSMCC_MULTI_FRAME_EST_SUPPORT
} csmcc_v120_mfm_enum;

typedef enum
{
   CSMCC_BIT_TRANSPARENT_MODE,
   CSMCC_PROTOCOL_SENSITIVE_MODE
} csmcc_v120_mode_enum;

typedef enum
{
   CSMCC_LLI_NEG_NOT_ALLOWED,
   CSMCC_LLI_NEG_ALLOWED
} csmcc_v120_llineg_enum;

typedef enum
{
   CSMCC_DEFAULT_ASSIGNEE,
   CSMCC_ASSIGNOR_ONLY
} csmcc_v120_assign_enum;

typedef enum
{
   CSMCC_LOGICAL_LINK_ZERO,
   CSMCC_USER_INFO
} csmcc_v120_negtype_enum;

typedef enum
{
   CSMCC_NO_COMPRESSION,
   CSMCC_TRANSMIT_ONLY,
   CSMCC_RECEIVE_ONLY,
   CSMCC_BOTH_DIRECTION
} csmcc_data_compression_dir_enum;

typedef enum
{
   CSMCC_NO_DISC_IF_NO_NEGOTIATION,
   CSMCC_DISC_IF_NO_NEGOTIATION
} csmcc_data_compression_nego_enum;

typedef enum
{
   CSMCC_QUERY_CCM,
   CSMCC_DEACTIVATE_CCM_REPORTING,
   CSMCC_ACTIVEATE_CCM_REPORTING
} csmcc_aoc_mode_enum;

typedef enum
{
   CSMCC_DISABLE_CUG_TEMPORARY_MODE,
   CSMCC_ENABLE_CUG_TEMPORARY_MODE
} csmcc_cug_temporary_mode_enum;

typedef enum
{
   CSMCC_CUG_INDEX_0,
   CSMCC_CUG_INDEX_1,
   CSMCC_CUG_INDEX_2,
   CSMCC_CUG_INDEX_3,
   CSMCC_CUG_INDEX_4,
   CSMCC_CUG_INDEX_5,
   CSMCC_CUG_INDEX_6,
   CSMCC_CUG_INDEX_7,
   CSMCC_CUG_INDEX_8,
   CSMCC_CUG_INDEX_9,
   CSMCC_CUG_NO_INDEX
} csmcc_cug_index_enum;

typedef enum
{
   CSMCC_CUG_NO_SUPPRESS_INFO,
   CSMCC_CUG_SUPPRESS_OA,
   CSMCC_CUG_SUPPRESS_PREF_CUG,
   CSMCC_CUG_SUPPRESS_OA_AND_PREF_CUG
} csmcc_cug_suppress_enum;

typedef enum
{
   CSMCC_DATA,
   CSMCC_FAX_CLASS_1_TIA,
   CSMCC_FAX_CLASS_1_ITUT = 10,
   CSMCC_FAX_MANU_SPECIFIC = 2,
   CSMCC_FAX_CLASS_2 = 20,
   CSMCC_VOICE = 8,
   CSMCC_VOICEVIEW = 80
} csmcc_fclass_mode_enum;

typedef enum
{
   CSMCC_DETACH,         /* No TCH. */
   CSMCC_ATTACH_REQ, /* Wish to attach but wait TCH. */
   CSMCC_SPEECH_ON,
   CSMCC_SPEECH_OFF,  /* Speech is detached, but TCH still exists. */
   CSMCC_DATA_ATTACH_REQ,
   CSMCC_DATA_ATTACH   
} csmcc_attach_status_enum;

typedef enum
{
   CSMCC_NO_TCH,
   CSMCC_SPEECH_TCH,
   CSMCC_DATA_TCH,
   CSMCC_CHMODE_MODIFY
} csmcc_channel_info_enum;

typedef enum
{
   CSMCC_SETUP_MSG,
   CSMCC_DISCONNECT_MSG,
   CSMCC_ALERT_MSG,
   CSMCC_CALL_PROCESS_MSG,
   CSMCC_SYNC_MSG,
   CSMCC_PROGRESS_MSG,
   CSMCC_CALL_CONNECTED_MSG,
   CSMCC_ALL_CALLS_DISC_MSG = 129,
   CSMCC_CALL_ID_ASSIGN_MSG = 130
}csmcc_cpi_msg_type_enum; /*mtk00924 add 041210 for +ECPI*/

typedef enum
{
   CSMCC_CTM_NOT_SUPPORT,
   CSMCC_CTM_SUPPORT
} csmcc_ctm_enum;

/* mtk01602: REL4, TS 24.008 Table 10.5.135d
   Define Emergency Service Categories Enum */
typedef enum
{
   CSMCC_CATEGORY_UNSPECIFIED, 
   CSMCC_CATEGORY_POLICE,
   CSMCC_CATEGORY_AMBULANCE,
   CSMCC_CATEGORY_FIRE_BRIGADE = 4,
   CSMCC_CATEGORY_MARINE_GUARD = 8,
   CSMCC_CATEGORY_MOUNTAIN_RESCUE = 16,
   CSMCC_CATEGORY_RESERVED = 32
}csmcc_ecc_category_enum;

typedef enum
{
   CSMCC_LLC_UR_600_BPS = 1,
   CSMCC_LLC_UR_1200_BPS = 2,
   CSMCC_LLC_UR_2400_BPS = 3,
   CSMCC_LLC_UR_3600_BPS = 4,   
   CSMCC_LLC_UR_4800_BPS = 5,
   CSMCC_LLC_UR_7200_BPS = 6,
   CSMCC_LLC_UR_8000_BPS = 7,
   CSMCC_LLC_UR_9600_BPS = 8,
   CSMCC_LLC_UR_14400_BPS = 9,
   CSMCC_LLC_UR_16000_BPS = 10,
   CSMCC_LLC_UR_19200_BPS = 11,
   CSMCC_LLC_UR_32000_BPS = 12,	
   CSMCC_LLC_UR_48000_BPS = 14,
   CSMCC_LLC_UR_56000_BPS = 15,
   CSMCC_LLC_UR_64000_BPS = 16
}csmcc_llc_user_rate_enum;/*LLC IE 5A bit 1 to bit 5*/

#endif /* _CSMCC_ENUMS_H */


