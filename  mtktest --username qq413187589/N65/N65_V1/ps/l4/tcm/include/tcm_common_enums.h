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
 * TCM_COMMON_ENUMS.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common ENUM of TCM.
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
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _TCM_COMMON_ENUMS_H
#define _TCM_COMMON_ENUMS_H

#ifndef _l3_INC_ENUMS_H
   #error include l3_inc_enums.h before tcm_common_enums.h
#endif /* ~_TCM_COMMON_ENUMS_H */

#ifndef _MMI_SM_ENUMS_H
   #error include mmi_sm_enums.h before tcm_common_enums.h
#endif /* ~_MMI_SM_ENUMS_H */

/* definitions for qos type */

typedef enum
{
    ATCI_REQ_QOS = 0,
    ATCI_MIN_QOS,
    ATCI_NEG_QOS 	/* SATe */
} atci_qos_enum;

/* Number of mobility and context data states */
enum
{
    TCM_MOBILITY_STATES   = 2,
    TCM_CNTXT_DATA_STATES = 3
};

/* This enumeration defines the modes of operation of the TCM FSM. */
typedef enum
{
    TCM_NORMAL_MODE,
    TCM_AUTO_MODE
} tcm_fsm_mode_enum;

/* This enumeration defines the validity of the context information
 * present in the SIB.
 */
typedef enum
{
    TCM_CNTXT_INVALID,
    TCM_CNTXT_VALID
} tcm_cntxt_valid_enum;

/* MMI: added */
typedef enum
{
    TCM_CONFIG_OPTION_FROM_SIB,
    TCM_CONFIG_OPTION_FROM_MSG
}tcm_source_of_config_enum;

/* Enumerated type for the addressing scheme to be used */
typedef enum
{
    MMI_DYNAMIC,
    MMI_STATIC,
    MMI_STATIC_AFTER_PDP_STARTUP
}mmi_addr_scheme_enum;

/* Enumerated type for the Ppd startup type. This could be internal
 * (via ATCI) or external (via PPP).
 */
typedef enum
{
   MMI_INTERNAL,
   MMI_EXTERNAL
}mmi_startup_type_enum; 

/* This enumerations defines the parameter codes that are passed to
 * the Taf database read and write procedures. Each code defines a
 * set of variables that are read or written.
 */
typedef enum
{
    MMI_CONTEXT_ID,
    MMI_NSAPI,
    MMI_PDPADDR,
    MMI_REQ_MIN_QOS,
    MMI_NEG_QOS,
    MMI_QOS_MOD_TYPE,
    MMI_L2P,
    MMI_APN,
    MMI_PROTO_OPTIONS,
    MMI_PDALGO,
    MMI_INITBY,
    MMI_TFT_IN_USE,
    MMI_TFT_UNDER_MOD,
    MMI_CONTEXT,
    MMI_PRIMARY_CONTEXT_ID,
 
    MMI_IN_USE_TO_UNDR_MOD_TFT, 
    MMI_DEL_MOD_TFT, 
    MMI_DATA_XFER, 
    MMI_PRIM_CNTXT_ID,
    MMI_NEG_QOS_PDP_ADDR,
    MMI_ACTIVATE_CNF,
    MMI_STARTUP,
    MMI_STARTUP_QOS,
    MMI_STATE_STARTUP,
    MMI_CHECK_PRIM_SEC,
    MMI_PRIM_N_TYPE_CONTEXT,
    MMI_STATE,
    MMI_L2P_PDPADDR_CONFIG,
    MMI_ALL_PARAMS,
    /* added for ATCI Handler */
    MMI_REQ_QOS,
    MMI_MIN_QOS,
    MMI_DCONT,
    MMI_MODTYPE,
    MMI_OP_TFT,
    MMI_TFT_PARAMS,
    MMI_DSCONT
}mmi_shared_param_enum;

/* This enumeration defines the state an nsapi could be in.
 * It could be either idle or be assigned to a context (in use).
 */
typedef enum
{
    MMI_SIB_IDLE   = 0,
    MMI_SIB_IN_USE = 1
}mmi_sib_usage_enum;

/* This enumeration defines the different states that the context
 * data FSM of TCM could be in. These states are context active,
 * context inactive and awaiting TE response state.
 */
typedef enum
{
    MMI_CONTEXT_INACTIVE_STATE = 0,
    MMI_AWAIT_TE_RSP_STATE     = 1,
    MMI_CONTEXT_ACTIVE_STATE   = 2
}mmi_context_state_enum;

/* The enumeration defines states that the mobility FSM of the TCM
 * module could take. These states are attached and detached state.
 */
typedef enum
{
    MMI_DETACHED_STATE = 0,
    MMI_ATTACHED_STATE = 1
}mmi_mobility_state_enum;

/* Default qos enumerations. These values assigned to the defaults
 * are present in stack_interface.h
 */
/* Default values for req_qos field of the session information block
 * type.
 */
enum
{
    DEF_REQ_PRECEDENCE      = SUBSCRIBED_PREC_CLASS,
    DEF_REQ_DELAY           = SUBSCRIBED_DELAY_CLASS,
    DEF_REQ_RELIABILITY     = SUBSCRIBED_REL_CLASS,
    DEF_REQ_PEAK_THRUPUT    = SUBSCRIBED_PTC,
    DEF_REQ_MEAN_THRUPUT    = BEST_EFFORT_THROUGHPUT,
    DEF_REQ_TRAFFIC_CLASS   = SUBSCRIBED_TRAFFIC_CLASS,
    DEF_REQ_MAX_BITRATE_UL  = SUBSCRIBED_MAX_BIT_RATE_UPLINK,
    DEF_REQ_MAX_BITRATE_DL  = SUBSCRIBED_MAX_BIT_RATE_DOWNLINK,
    DEF_REQ_GUAR_BITRATE_UL = SUBSCRIBED_GUARANTD_BIT_RATE_UPLINK,
    DEF_REQ_GUAR_BITRATE_DL = SUBSCRIBED_GUARANTD_BIT_RATE_DOWNLINK,
    DEF_REQ_DELIVERY_ORDER  = SUBSCRIBED_DELIVERY_ORDER,
    DEF_REQ_MAX_SDU_SIZE    = SUBSCRIBED_MS_TO_NW_MAX_SDU_SIZE,
    DEF_REQ_SDU_ERROR_RATIO = SUBSCRIBED_SDU_ERR_RATIO,
    DEF_REQ_RESIDUAL_BER    = SUBSCRIBED_BIT_ERROR_RATE,
    DEF_REQ_TRANSFER_DELAY  = SUBSCRIBED_TRANSFER_DELAY,
    DEF_REQ_DELIVERY_ERRONEOUS_SDUS   = SUBSCRIBED_DELIVERY_OF_ERR_SDU,
    DEF_REQ_TRAFFIC_HANDLING_PRIORITY = SUBSCRIBED_TRAFFIC_HNDL_PRIORITY
};

/* Default values for min_qos field of the session information
 * block type.
 */
enum
{
    DEF_MIN_PRECEDENCE      = SUBSCRIBED_PREC_CLASS,
    DEF_MIN_DELAY           = SUBSCRIBED_DELAY_CLASS,
    DEF_MIN_RELIABILITY     = SUBSCRIBED_REL_CLASS,
    DEF_MIN_PEAK_THRUPUT    = SUBSCRIBED_PTC,
    /* Differs from requested default qos enumerations */
    DEF_MIN_MEAN_THRUPUT    = SUBSCRIBED_MEAN_THROUGHPUT,
    DEF_MIN_TRAFFIC_CLASS   = SUBSCRIBED_TRAFFIC_CLASS,
    DEF_MIN_MAX_BITRATE_UL  = SUBSCRIBED_MAX_BIT_RATE_UPLINK,
    DEF_MIN_MAX_BITRATE_DL  = SUBSCRIBED_MAX_BIT_RATE_DOWNLINK,
    DEF_MIN_GUAR_BITRATE_UL = SUBSCRIBED_GUARANTD_BIT_RATE_UPLINK,
    DEF_MIN_GUAR_BITRATE_DL = SUBSCRIBED_GUARANTD_BIT_RATE_DOWNLINK,
    DEF_MIN_DELIVERY_ORDER  = SUBSCRIBED_DELIVERY_ORDER,
    DEF_MIN_MAX_SDU_SIZE    = SUBSCRIBED_MS_TO_NW_MAX_SDU_SIZE,
    DEF_MIN_SDU_ERROR_RATIO = SUBSCRIBED_SDU_ERR_RATIO, 
    DEF_MIN_RESIDUAL_BER    = SUBSCRIBED_BIT_ERROR_RATE,
    DEF_MIN_TRANSFER_DELAY  = SUBSCRIBED_TRANSFER_DELAY,
    DEF_MIN_DELIVERY_ERRONEOUS_SDUS   = SUBSCRIBED_DELIVERY_OF_ERR_SDU,
    DEF_MIN_TRAFFIC_HANDLING_PRIORITY = SUBSCRIBED_TRAFFIC_HNDL_PRIORITY
};

/* Enumerations for defaults for the Compress/Decompression
 * algorithm.
 */
enum
{
    DEF_DCOMP =  SND_NO_DCOMP,   /* no compression */
    DEF_PCOMP =  SND_NO_PCOMP    /* no compression */
};

/* Definitions to indicate the type required for TafFillQoS
 * procedure.
 */
typedef enum
{
    MMI_REQUIRED = 0,
    MMI_MINIMUM  = 1
}mmi_qos_type_enum;

/* Packet filter type enumerations */
typedef enum
{
    PF_TYPE_ONE = 0,
    PF_TYPE_TWO,
    PF_TYPE_THREE,
    PF_TYPE_NONE
} packet_filter_type_enum;

/* Packet filter component type enumerations */
typedef enum
{
    PF_IPV4_SRC_ADDR_TYPE = 0x10,
    PF_IPV6_SRC_ADDR_TYPE = 0x20,
    PF_PROT_ID_NEXT_HDR_TYPE = 0x30,
    PF_SINGLE_DST_PORT_TYPE = 0x40,
    PF_DST_PORT_RANGE_TYPE = 0x41,
    PF_SINGLE_SRC_PORT_TYPE = 0x50,
    PF_SRC_PORT_RANGE_TYPE = 0x51,
    PF_SECURITY_PARAM_INDX_TYPE = 0x60,
    PF_TYPE_OF_SERV_TRAFFIC_CLASS_TYPE = 0x70,
    PF_FLOW_LABEL_TYPE = 0x80    
} packet_filter_comp_type_enum;

typedef enum
{
  MMI_NOT_REG_NOT_SEARCHING = 0,
  MMI_REG_IN_HOME = 1,
  MMI_NOT_REG_SEARCHING = 2,
  MMI_REG_DENIED = 3,
  MMI_UNKNOWN = 4,
  MMI_REG_ROAMING = 5,
  MMI_CELL_INFO = 6
}nwreg_update_enum;

typedef enum
{
   TCM_MMI_APP,
   TCM_WAP_APP
} app_src_enum;

#endif/* tcm_common_enums.h */


