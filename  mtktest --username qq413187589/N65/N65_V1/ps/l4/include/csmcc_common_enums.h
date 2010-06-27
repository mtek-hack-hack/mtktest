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
 *	csmcc_common_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the enum types which are common to the L4.
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

#ifndef _CSMCC_COMMON_ENUMS_H
#define _CSMCC_COMMON_ENUMS_H

typedef enum
{
   CSMCC_ERROR,
   CSMCC_NO_ERROR,
   CSMCC_DTMF_QUERY,
   CSMCC_CMD_SUCC /* ripple add. */
} csmcc_error_enum;

typedef enum
{
   CSMCC_REL_HELD_OR_UDUB, /*0*/
   CSMCC_REL_ACTIVE_AND_ACCEPT, /*1*/
   CSMCC_REL_SPECIFIC_CALL, /*2*/
   CSMCC_HOLD_ACTIVE_AND_ACCEPT, /*3*/
   CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL, /*4*/
   CSMCC_ADD_HELD_CALL, /*5*/
   CSMCC_EXPLICIT_CALL_TRANSFER, /*6*/
   CSMCC_ACTIVATE_CCBS_CALL, /*7*/
   CSMCC_REL_ALL_EXCEPT_WAITING_CALL, /*8*/
   CSMCC_REL_SPECIFIC_ACTIVE_CALL, /* 9 */
   CSMCC_SWAP_CALL, /* 10 */
   CSMCC_REL_HELD,  /* 11 */
   CSMCC_REL_ACTIVE,  /* 12 */
   CSMCC_REL_ALL,  /* 13 */
   CSMCC_INVALID_CRSS_TYPE = 255
} csmcc_crss_req_enum;

typedef enum
{
   CSMCC_CLIR_INVOCATION,
   CSMCC_CLIR_SUPPRESSION,
   CSMCC_INVALID_CLIR_INFO = 255
} csmcc_clir_info_enum;

typedef enum
{
   CSMCC_NO_CALL_PRIORITY,
   CSMCC_CALL_PRIORITY_4, /* 1 */
   CSMCC_CALL_PRIORITY_3, /* 2 */
   CSMCC_CALL_PRIORITY_2, /* 3 */
   CSMCC_CALL_PRIORITY_1, /* 4 */
   CSMCC_CALL_PRIORITY_0, /* 5 */
   CSMCC_CALL_PRIORITY_B, /* 6 */
   CSMCC_CALL_PRIORITY_A /* 7 */
} csmcc_call_priority_enum;

typedef enum
{
   CSMCC_VOICE_CALL,
   CSMCC_AUX_VOICE_CALL,
   CSMCC_DATA_CALL,
   CSMCC_FAX_CALL,
   CSMCC_CSD_CALL,
   CSMCC_SAT_DATA_CALL,
   CSMCC_VIDEO_CALL,
   CSMCC_NO_CALL_TYPE,
   CSMCC_INVALID_CALL_TYPE = 255
} csmcc_call_type_enum;

typedef enum
{
   CSMCC_PREEMPT_BY_HOLD,
   CSMCC_PREEMPT_BY_REL
} csmcc_preempt_type_enum;

typedef enum
{
   CSMCC_CLI_UNAVAILABLE,
   CSMCC_CLI_REJECT_BY_USER,
   CSMCC_CLI_INTERACTION,
   CSMCC_COIN_LINE_PAYPHONE,
   CSMCC_INVALID_NO_CLI_CAUSE = 255
} csmcc_no_cli_cause_enum;

typedef enum
{
   CSMCC_USER,
   CSMCC_PRIVATE_NW_LOCAL_USER,
   CSMCC_PUBLIC_NW_LOCAL_USER,
   CSMCC_TRANSIT_NW,
   CSMCC_PUBLIC_NW_REMOTE_USER,
   CSMCC_PRIVATE_NW_REMOTE_USER,
   CSMCC_INTERNATIONAL_NW = 7,
   CSMCC_NW_BEYOND_INTERWORKING_POINT = 10
} csmcc_location_enum;

typedef enum
{
   CSMCC_NOT_END_TO_END = 1,
   CSMCC_DEST_IN_NON_PLMN_ISDN,
   CSMCC_ORIG_IN_NON_PLMN_ISDN,
   CSMCC_RETURN_PLMN_ISDN = 4,
   CSMCC_IN_BAND_AVAILABLE = 8,
   CSMCC_END_TO_END = 32,
   CSMCC_QUEUEING = 64
} csmcc_prog_desc_enum;

typedef enum
{
   CSMCC_ORIG_NONE = 0x00,
   CSMCC_MO_CALL = 0x01,
   CSMCC_MT_CALL = 0x02,
   CSMCC_NW_INIT_MO_CALL = 0x04
} csmcc_call_orig_enum;


typedef enum
{
   CSMCC_DIAL_TONE_ON,
   CSMCC_RING_BACK_TONE_ON,
   CSMCC_INTERCEPT_TONE_ON,
   CSMCC_NTW_CONGESTION_TONE_ON,
   CSMCC_BUSY_TONE_ON,
   CSMCC_CONFIRM_TONE_ON,
   CSMCC_ANSWER_TONE_ON,
   CSMCC_CALL_WAITING_TONE_ON,
   CSMCC_OFF_HOOK_WARNING_TONE_ON,
   CSMCC_TONES_OFF = 63,
   CSMCC_ALERTING_OFF = 79
} csmcc_signal_value_enum;

typedef enum
{
   CSMCC_ALERTING_PATTERN_1,
   CSMCC_ALERTING_PATTERN_2,
   CSMCC_ALERTING_PATTERN_3,
   CSMCC_ALERTING_PATTERN_5 = 4,
   CSMCC_ALERTING_PATTERN_6,
   CSMCC_ALERTING_PATTERN_7,
   CSMCC_ALERTING_PATTERN_8,
   CSMCC_ALERTING_PATTERN_9
} csmcc_alerting_pattern_enum;

typedef enum
{
   CSMCC_SAT_SETUP_CALL,
   CSMCC_SAT_HOLD_AND_SETUP_CALL,
   CSMCC_SAT_REL_AND_SETUP_CALL
} csmcc_sat_call_req_type_enum;

typedef enum
{
   CLCC_MO_CALL,
   CLCC_MT_CALL,
   CLCC_UNKNOWN_DIR
} clcc_dir_enum;

typedef enum
{
   CLCC_CALL_ACTIVE,
   CLCC_CALL_HELD,
   CLCC_CALL_DIALING,
   CLCC_CALL_ALERTING,
   CLCC_CALL_INCOMING,
   CLCC_CALL_WAITING
} clcc_state_enum;

typedef enum
{
   CLCC_VOICE_CALL,
   CLCC_DATA_CALL,
   CLCC_FAX_CALL,
   CLCC_VFD_VOICE, /* voice followed by data, voice mode */
   CLCC_AVD_VOICE, /* alternating voice/data, voice mode */
   CLCC_AVF_VOICE, /* alternating voice/fax, voice mode */
   CLCC_VFD_DATA,  /* voice followed by data, data mode */
   CLCC_AVD_DATA,  /* alternating voice/data, data mode */
   CLCC_AVF_FAX,  /* alternating voice/fax, fax mode */
   CLCC_UNKNOWN_MODE
} clcc_mode_enum;

typedef enum
{
   CLCC_NOT_MPTY,
   CLCC_MPTY
} clcc_mpty_enum;

typedef enum
{
   CSMCC_NOTIFY_CFU,             /* call forwarding active: CFU */
   CSMCC_NOTIFY_CFC,             /* call forwarding active: CFC */
   CSMCC_NOTIFY_CF,              /* call forwarded indication */
   CSMCC_NOTIFY_CF_CFU,          /* call forwarded indication: CFU */
   CSMCC_NOTIFY_CF_CFC,          /* call forwarded indication: CFC */
   CSMCC_NOTIFY_CF_CFB,          /* call forwarded indication: CFB */
   CSMCC_NOTIFY_CF_CFNRY,        /* call forwarded indication: CFNRY */
   CSMCC_NOTIFY_CF_CFNRC,        /* call forwarded indication: CFNRC */
   CSMCC_NOTIFY_BAC,             /* call barring active: BAC */
   CSMCC_NOTIFY_BAOC,            /* call barring active: BAOC */
   CSMCC_NOTIFY_BAIC,            /* call barring active: BAIC */
   CSMCC_NOTIFY_CW,              /* call waiting indication */
   CSMCC_NOTIFY_CALL_HELD,       /* call held indication */
   CSMCC_NOTIFY_CALL_RETRIEVED,  /* call retrieved indication */
   CSMCC_NOTIFY_MPTY,            /* MPTY call indication */
   CSMCC_NOTIFY_CUG,             /* CUG invocation indication */
   CSMCC_NOTIFY_CLIR_REJECT,     /* CLIR reject indication */
   CSMCC_NOTIFY_ECT_ACTIVE,      /* active ECT indication */
   CSMCC_NOTIFY_ECT_ALERTING,    /* alerting ECT indication */
   CSMCC_NOTIFY_CNAP,            /* CNAP indication */
   CSMCC_NOTIFY_CCBS,            /* CCBS invocation indication */
   CSMCC_NOTIFY_CD,         /* call is deflected or this mt call is a defelected call. */
   CSMCC_NOTIFY_HELD_CALL_RELEASED,  /* Generated by CSMCC, for 27.007 +CSSN, code2, 5. */
   CSMCC_NOTIFY_NONE = 255
} csmcc_notify_ss_type_enum;

typedef enum
{
   CSD_PROF_RATE_2400,
   CSD_PROF_RATE_4800,
   CSD_PROF_RATE_9600,
   CSD_PROF_RATE_14400,
   CSD_PROF_RATE_AUTO
} csmcc_csd_prof_rate_enum;

#ifdef __CPHS__

typedef enum {
   CSMCC_ALS_LINE1,
   CSMCC_ALS_LINE2,
   CSMCC_ALS_LINE1_2,
   CSMCC_ALS_NONE
} csmcc_als_line_id_enum;

#endif

/*coding standard*/
typedef enum {
   CSMCC_ITU_T_Q931,
   CSMCC_RESERVED_FOR_INTERNATIONAL,    
   CSMCC_NATIONAL,
   CSMCC_GSM_PLMNS_24008
}csmcc_coding_standard_enum;

#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif /* _CSMCC_COMMON_ENUMS_H */

