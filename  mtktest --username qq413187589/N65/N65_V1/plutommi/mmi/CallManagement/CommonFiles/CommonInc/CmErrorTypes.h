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
 *  CmErrorTypes.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : CmErrorTypes.h

   PURPOSE     : Error Maps for CM causes

   REMARKS     : nil

   AUTHOR      : Ashish G.

   DATE     : sep' 03, 2002

**************************************************************/
#ifndef __MMI_UCM__

#ifndef _CM_ERROR_TYPES_H
#define _CM_ERROR_TYPES_H

#define ERROR_BASE                     SIM_CAUSE_END+1
#define UNKNOWN_ERROR                  ERROR_BASE+2
#define NO_ACTIVE_CALL                 ERROR_BASE+3
#define ERR_CM_UNKNOWN                 ERROR_BASE+4
#define ERR_CM_MT_DATA_CALL            ERROR_BASE+5

#define ERR_L4C_GEN_CAUSE                    CM_L4C_GEN_CAUSE
#define ERR_L4C_USSD_ABORT                      CM_L4C_CC_CALL_ABORT
#define ERR_L4C_FDN_FAIL                     PHB_L4C_ERROR
#define ERR_UNASSIGNED_NUM                   CM_UNASSIGNED_NUM
#define ERR_INVALID_NUMBER_FORMAT            CM_INVALID_NUMBER_FORMAT
#define ERR_NO_ROUTE_TO_DESTINATION          CM_NO_ROUTE_TO_DESTINATION
#define ERR_CALL_REJECTED                    CM_CALL_REJECTED
#define ERR_DEST_OUT_OF_ORDER                CM_DEST_OUT_OF_ORDER
#define ERR_FACILITY_REJECT                  CM_FACILITY_REJECT
#define ERR_TEMPORARY_FAILURE                CM_TEMPORARY_FAILURE
#define ERR_SWITCH_EQUIPMENT_CONGESTION   CM_SWITCH_EQUIPMENT_CONGESTION
#define ERR_REQ_FAC_NOT_SUBS                 CM_REQ_FAC_NOT_SUBS
#define ERR_SER_UNAVAILABLE                  CM_SER_UNAVAILABLE
#define ERR_BEARER_SER_UNIMPL                CM_BEARER_SER_UNIMPL
#define ERR_INVALID_TI_VALUE                 CM_INVALID_TI_VALUE
#define ERR_USER_NOT_IN_CUG                  CM_USER_NOT_IN_CUG
#define ERR_INCOMPATIBLE_DEST                CM_INCOMPATIBLE_DEST
#define ERR_SEMANTIC_ERR                     CM_SEMANTIC_ERR
#define ERR_INTER_WRK_UNSPECIFIED            CM_INTER_WRK_UNSPECIFIED
#define ERR_CHANNEL_UN_ACCP                  CM_CHANNEL_UN_ACCP
#define ERR_NO_CIRCUIT_CHANNEL_AVAIL         CM_NO_CIRCUIT_CHANNEL_AVAIL
#define ERR_NETWORK_OUT_OF_ORDER             CM_NETWORK_OUT_OF_ORDER
#define ERR_QOS_UNAVAIL                      CM_QOS_UNAVAIL
#define ERR_INVALID_TRANSIT_NW_SEL           CM_INVALID_TRANSIT_NW_SEL
#define ERR_REQUESTED_CKT_CHANEL_NOT_AVIL    CM_REQUESTED_CKT_CHANEL_NOT_AVIL
#define ERR_RESOURCE_UNAVAIL_UNSPECIFIED        CM_RESOURCE_UNAVAIL_UNSPECIFIED
#define ERR_OPR_DTR_BARRING                  CM_OPR_DTR_BARRING
#define ERR_CALL_BARRED                      CM_CALL_BARRED
#define ERR_IC_BAR_CUG                       CM_IC_BAR_CUG
#define ERR_BEARER_CAP_NOT_AUTHORISED        CM_BEARER_CAP_NOT_AUTHORISED
#define ERR_BEARER_CAP_NOT_AVAIL             CM_BEARER_CAP_NOT_AVAIL
#define ERR_USER_BUSY                        CM_USER_BUSY
#define ERR_NO_USER_RESPONDING               CM_NO_USER_RESPONDING
#define ERR_NO_ANSWER_ON_ALERT               CM_NO_ANSWER_ON_ALERT
#define ERR_ACM_EXCEEDED                     CM_ACM_EXCEEDED
#define ERR_REQ_FACILITY_UNAVAIL             CM_REQ_FACILITY_UNAVAIL
#define ERR_RESERVED                         CM_RESERVED
#define ERR_NORMAL_CALL_CLR                  CM_NORMAL_CALL_CLR
#define ERR_NUMBER_CHANGED                   CM_NUMBER_CHANGED
#define ERR_PRE_EMPTION                      CM_PRE_EMPTION
#define ERR_NON_SEL_USER_CLEAR               CM_NON_SEL_USER_CLEAR
#define ERR_RES_STATUS_ENQ                   CM_RES_STATUS_ENQ
#define ERR_NORMAL_UNSPECIFIED               CM_NORMAL_UNSPECIFIED
#define ERR_ACCESS_INFO_DISCARDED            CM_ACCESS_INFO_DISCARDED
#define ERR_RESTR_DIGITAL_INFO               CM_RESTR_DIGITAL_INFO
#define ERR_SER_OPT_UNIMPL                   CM_SER_OPT_UNIMPL
#define ERR_INVALID_MANDATORY_INF            CM_INVALID_MANDATORY_INF
#define ERR_MSG_TYPE_UNIMPL                  CM_MSG_TYPE_UNIMPL
#define ERR_MSG_TYPE_NOT_COMPATIBLE          CM_MSG_TYPE_NOT_COMPATIBLE
#define ERR_IE_NON_EX                        CM_IE_NON_EX
#define ERR_COND_IE_ERR                      CM_COND_IE_ERR
#define ERR_INCOMP_MESG_WITH_STATE           CM_INCOMP_MESG_WITH_STATE
#define ERR_RECOVERY_ON_TIMER_EXPIRY         CM_RECOVERY_ON_TIMER_EXPIRY
#define ERR_PROTOCOL_ERR_UNSPECIFIED         CM_PROTOCOL_ERR_UNSPECIFIED
#define ERR_CSMCC_NO_RESPONSE_FROM_NW        CSMCC_NO_RESPONSE_FROM_NW
#define ERR_NETWORK_FAILURE                  CM_MM_NETWORK_FAILURE
#define ERR_IE_NOT_IMPLEMENTED               CM_MM_IE_NOT_IMPLEMENTED
#define ERR_CONDITIONAL_MM_IE_ERROR          CM_MM_CONDITIONAL_MM_IE_ERROR
#define ERR_CSMCC_CMD_NOT_ALLOW              CSMCC_CMD_NOT_ALLOW
#define ERR_CSMCC_ILLEGAL_DTMF_TONE          CSMCC_ILLEGAL_DTMF_TONE
#define ERR_CSMCC_CALL_ACCEPT_NOT_ALLOW      CSMCC_CALL_ACCEPT_NOT_ALLOW
#define ERR_MS_ID_NOT_DERIVED_BY_NW          CM_MM_MS_ID_NOT_DERIVED_BY_NW
#define ERR_IMPLICIT_DETACH                  CM_MM_IMPLICIT_DETACH
#define ERR_MSG_NOT_COMPAT_WITH_PROTO_STATE     CM_MM_MSG_NOT_COMPAT_WITH_PROTO_STATE
#define ERR_PROTO_ERROR_UNSPECIFIED          CM_MM_PROTO_ERROR_UNSPECIFIED
#define ERR_IMSI_UNKNOWN_IN_HLR              CM_MM_IMSI_UNKNOWN_IN_HLR
#define ERR_IMSI_UNKNOWN_IN_VLR              CM_MM_IMSI_UNKNOWN_IN_VLR
#define ERR_IMEI_NOT_ACCEPTED                CM_MM_IMEI_NOT_ACCEPTED
#define ERR_GPRS_NOT_ALLOWED                 CM_MM_GPRS_NOT_ALLOWED
#define ERR_GPRS_NON_GPRS_NOT_ALLOWED        CM_MM_GPRS_NON_GPRS_NOT_ALLOWED
#define ERR_PLMN_NOT_ALLOWED                 CM_MM_PLMN_NOT_ALLOWED
#define ERR_LOCATION_AREA_NOT_ALLOWED        CM_MM_LOCATION_AREA_NOT_ALLOWED
#define ERR_ROAMING_AREA_NOT_ALLOWED         CM_MM_ROAMING_AREA_NOT_ALLOWED
#define ERR_GPRS_NOT_ALLOWED_IN_PLMN         CM_MM_GPRS_NOT_ALLOWED_IN_PLMN
#define ERR_NO_SUITABLE_CELLS_IN_LA          CM_MM_NO_SUITABLE_CELLS_IN_LA
#define ERR_MSC_TEMP_NOT_REACHABLE           CM_MM_MSC_TEMP_NOT_REACHABLE
#define ERR_SERV_OPTION_NOT_SUPPORTED        CM_MM_SERV_OPTION_NOT_SUPPORTED
#define ERR_REQ_SERV_OPTION_NOT_SUBSCRIBED      CM_MM_REQ_SERV_OPTION_NOT_SUBSCRIBED
#define ERR_SERV_OPTION_TEMP_OUT_OF_ORDER    CM_MM_SERV_OPTION_TEMP_OUT_OF_ORDER
#define ERR_CALL_CANNOT_BE_IDENTIFIED        CM_MM_CALL_CANNOT_BE_IDENTIFIED
#define ERR_NO_PDP_CONTEXT_ACTIVATED         CM_MM_NO_PDP_CONTEXT_ACTIVATED
#define ERR_SEMANTICALLY_INCORRECT_MSG       CM_MM_SEMANTICALLY_INCORRECT_MSG
#define ERR_INVALID_MM_MAND_INFO             CM_MM_INVALID_MM_MAND_INFO
#define ERR_MSG_TYPE_NON_EXISTENT            CM_MM_MSG_TYPE_NON_EXISTENT
#define ERR_MSG_TYPE_NOT_IMPLEMENTED         CM_MM_MSG_TYPE_NOT_IMPLEMENTED
#define ERR_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE  CM_MM_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE
#define ERR_ACCESS_CLASS_BARRED              CM_MM_ACCESS_CLASS_BARRED
#define ERR_CSMCC_ILLEGAL_CALL_ID            CSMCC_ILLEGAL_CALL_ID
#define ERR_CSMCC_CALL_ALLOC_FAIL            CSMCC_CALL_ALLOC_FAIL
#define ERR_CSMCC_BC_FILL_FAIL               CSMCC_BC_FILL_FAIL
#define ERR_CSMCC_ILLEGAL_BC                 CSMCC_ILLEGAL_BC
#define ERR_CSMCC_MODIFY_ACTUAL_MODE         CSMCC_MODIFY_ACTUAL_MODE
#define ERR_CSMCC_DATA_ACT_FAIL              CSMCC_DATA_ACT_FAIL
#define ERR_ILLEGAL_MS                       CM_MM_ILLEGAL_MS
#define ERR_ILLEGAL_ME                       CM_MM_ILLEGAL_ME
#define ERR_MAC_FAILURE                      CM_MM_MAC_FAILURE
#define ERR_SYNC_FAILURE                     CM_MM_SYNC_FAILURE
#define ERR_CONGESTION                       CM_MM_CONGESTION
#define ERR_CSMCC_CALL_RE_EST                CSMCC_CALL_RE_EST
#define ERR_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN   CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN
#define ERR_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX   CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX
#define ERR_CM_MM_ACCESS_BARRED              CM_MM_ACCESS_BARRED
#define ERR_CM_MM_ASSIGNMENT_REJECT          CM_MM_ASSIGNMENT_REJECT
#define ERR_CM_MM_RANDOM_ACCES_FAILURE    CM_MM_RANDOM_ACCES_FAILURE
#define ERR_CM_MM_RR_NO_SERVICE              CM_MM_RR_NO_SERVICE
#define ERR_CM_MM_RR_CONN_RELEASE            CM_MM_RR_CONN_RELEASE
#define ERR_CM_MM_AUTH_FAILURE               CM_MM_AUTH_FAILURE
#define ERR_CM_MM_IMSI_DETACH                CM_MM_IMSI_DETACH
#define ERR_CM_MM_ABORT_BY_NW                CM_MM_ABORT_BY_NW
#define ERR_CM_MM_CONN_TIMEOUT               CM_MM_CONN_TIMEOUT

#define ERR_CM_MM_CM_ENQUEUE_FAIL            CM_MM_CM_ENQUEUE_FAIL
#define ERR_CM_MM_NOT_UPDATED                CM_MM_NOT_UPDATED
#define ERR_CM_MM_STATE_NOT_ALLOWED_CM CM_MM_STATE_NOT_ALLOWED_CM
#define ERR_CM_MM_EMERGENCY_NOT_ALLOWED         CM_MM_EMERGENCY_NOT_ALLOWED
#define ERR_CM_MM_NO_SERVICE                 CM_MM_NO_SERVICE
#define ERR_CM_MM_CAUSE_NONE                 CM_MM_CAUSE_NONE
#define ERR_CM_SS_SYSTEMFAILURE	             CM_SS_ERR_SYSTEMFAILURE

#endif /* _CM_ERROR_TYPES_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "CmErrorTypesEX.h"
#endif /* __MMI_UCM__ */