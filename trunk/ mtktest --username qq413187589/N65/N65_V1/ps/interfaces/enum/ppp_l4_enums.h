/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   ppp_l4_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 ******************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
*******************************************************************************/


#ifndef _PPP_L4_ENUMS_H
#define _PPP_L4_ENUMS_H

typedef enum
{
    NULL_L2P = 1,
    PPP,
    MANUFACTURER_PROTOCOL    
} mmi_ltwoh_protocol_enum;

typedef enum
{
    NORMAL_LINK_TERMINATION,
    ABNORMAL_LINK_TERMINATION
} mmi_link_free_enum;

typedef enum
{
   PPPE_MOBILE_DEACT,
   PPPE_NW_DEACT
} pppcsd_deact_cause_enum;

typedef enum
{
   PPPE_NONE,
   PPPE_LCP_FAIL,
   PPPE_AUTH_FAIL,
   PPPE_IPCP_FAIL,
   PPPE_ESC_DETECT,
   PPPE_PLUGOUT_DETECT
} ppp_error_cause_enum;


enum
{
   PPPE_RESULT_SUCCESS,
   PPPE_RESULT_FAILED
};

typedef enum {
   FSM_INITIAL,
   FSM_STARTING,
   FSM_CLOSED,
   FSM_STOPPED,
   FSM_CLOSING,
   FSM_STOPPING,
   FSM_REQSENT,
   FSM_ACKRCVD,
   FSM_ACKSENT,
   FSM_OPENED,
   FSM_STATE_SIZE
} ppp_fsm_state_enum;

typedef enum {
    VENDOREXT = 0,
    CONF_REQ = 1,
    CONF_ACK = 2,
    CONF_NAK = 3,
    CONF_REJ = 4,
   TERM_REQ        =5,
   TERM_ACK        =6,
   CODE_REJ        =7,
    PROTO_REJ = 8,
   ECHO_REQ        =9,
    ECHO_RPLY = 10,
   DISCARD_REQ     =11,
   IDENTIFICATION  =12,
    TIMEREMAIN = 13,
    RESET_REQ = 14,
    RESET_ACK = 15,
    NULL_CODE = 0xFF
} ppp_fsm_code_enum;

/*
 * PPP Phase
 */
typedef enum
{
   PPP_INIT_STATE,
   PPP_LCP_STATE,
   PPP_AUTH_STATE,
   PPP_PDP_STATE,
   PPP_IPCP_STATE,
   PPP_DATA_STATE,
   PPP_TERM_0_STATE,
   PPP_TERM_1_STATE,
   PPP_TERM_2_STATE,
   PPP_TERM_3_STATE, /* CBM L4C deactivate PPP in PPP_DATA_STATE */
   PPP_STATE_SIZE
} ppp_state_enum;

/*
 * PPP FSM index  
 */
typedef enum
{
   LCP,
   AUTH,	
   IPCP,
   PPP_FSM_SIZE
} ppp_fsm_idx_enum;

#endif


