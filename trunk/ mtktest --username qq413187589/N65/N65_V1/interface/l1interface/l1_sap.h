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
 * l1_sap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Layer 1 and Protocol Stack related message identity definition
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Note that GPRS REQ should before GSM CNF/IND, GSM should before 
   GPRS for MPAL's requirement!!! That is, all REQ first and GSM 
   before GPRS, and then all CNF/IND together with GSM before GPRS */ 

/* Request for GSM */

MSG_ID_MPHC_POWER_SCAN_REQ = L1_MSG_CODE_BEGIN,
MSG_ID_MPHC_MANUSEL_PWRSCAN_REQ,
MSG_ID_MPHC_MANUSEL_PWRSCAN_STOP_REQ,
MSG_ID_MPHC_BSIC_SYNC_REQ,
MSG_ID_MPHC_SPECIFIC_SYNC_REQ,
MSG_ID_MPHC_SERV_BCCH_MONITOR_REQ,
MSG_ID_MPHC_IDLE_CCCH_START_REQ,
MSG_ID_MPHC_CCCH_UPDATE_REQ,
MSG_ID_MPHC_PAGE_MODE_CHANGE_REQ,
MSG_ID_MPHC_RANDOM_ACCESS_REQ,
MSG_ID_MPHC_RACH_ABORT_REQ,
MSG_ID_MPHC_IMMED_ASSIGN_REQ,
MSG_ID_MPHC_CHANNEL_ASSIGN_REQ,
MSG_ID_MPHC_CHANNEL_RELEASE_REQ,
MSG_ID_MPHC_HANDOVER_REQ,
MSG_ID_MPHC_HANDOVER_ACCESS_STOP_REQ,
MSG_ID_MPHC_CHANNEL_RECONNECT_REQ,
MSG_ID_MPHC_FREQUENCY_REDEFINITION_REQ,
MSG_ID_MPHC_CHANNEL_MODE_MODIFY_REQ,
MSG_ID_MPHC_CIPHERING_MODE_COMMAND_REQ,
MSG_ID_MPHC_CLOSE_TCH_LOOP_REQ,
MSG_ID_MPHC_OPEN_TCH_LOOP_REQ,
MSG_ID_MPHC_DAI_TEST_REQ,
MSG_ID_MPHC_POWER_CLASS_REQ,
MSG_ID_MPHC_CELL_OPTION_UPDATE_REQ,
MSG_ID_MPHC_EXTENDED_MEAS_REQ,
MSG_ID_MPHC_NEIGHBOR_MEAS_REQ,
MSG_ID_MPHC_NEIGHBOR_BSIC_START_REQ,
MSG_ID_MPHC_NEIGHBOR_BSIC_STOP_REQ,
MSG_ID_MPHC_NEIGHBOR_SYS_INFO_READ_REQ,
MSG_ID_MPHC_NEIGHBOR_SYS_INFO_STOP_REQ,
MSG_ID_MPHC_CELL_BSIC_START_REQ,
MSG_ID_MPHC_CELL_BSIC_STOP_REQ,
MSG_ID_MPHC_CELL_SYS_INFO_READ_REQ,
MSG_ID_MPHC_CELL_SYS_INFO_STOP_REQ,
MSG_ID_MPHC_CBCH_CONFIG_REQ,
MSG_ID_MPHC_CBCH_START_REQ,
MSG_ID_MPHC_CBCH_STOP_REQ,
MSG_ID_MPHC_CBCH_SKIP_REQ,
MSG_ID_MPHC_DEACTIVATE_REQ,
MSG_ID_MPHC_SIM_READY_NOTIFY_REQ,
#ifdef __PS_SERVICE__
/* Request for GPRS */

MSG_ID_MPHP_DOWNLINK_SINGLE_BLOCK_REQ,
MSG_ID_MPHP_INTERFERENCE_MEAS_REQ,
MSG_ID_MPHP_NEIGHBOR_PBCCH_START_REQ,
MSG_ID_MPHP_NEIGHBOR_PBCCH_STOP_REQ,
MSG_ID_MPHP_PACKET_IDLE_CCCH_START_REQ,
MSG_ID_MPHP_PACKET_CCCH_CONFIG_REQ,
MSG_ID_MPHP_PACKET_IDLE_PCCCH_START_REQ,
MSG_ID_MPHP_PACKET_DOWNLINK_ASSIGNMENT_REQ,
MSG_ID_MPHP_PACKET_EXTENDED_MEAS_REQ, 
MSG_ID_MPHP_PACKET_NC_MEAS_START_REQ,
MSG_ID_MPHP_PACKET_NC_MEAS_STOP_REQ,
MSG_ID_MPHP_PACKET_PAGE_MODE_UPDATE_REQ,
MSG_ID_MPHP_PACKET_PDCH_RELEASE_REQ,
MSG_ID_MPHP_PACKET_RANDOM_ACCESS_REQ,
MSG_ID_MPHP_PACKET_UNASSIGNMENT_REQ,
MSG_ID_MPHP_PACKET_UPLINK_ASSIGNMENT_REQ,
MSG_ID_MPHP_PACKET_TIMESLOT_RECONFIGURE_REQ,
MSG_ID_MPHP_PBCCH_START_REQ,
MSG_ID_MPHP_PBCCH_STOP_REQ,
MSG_ID_MPHP_PCCCH_CONFIG_REQ,
MSG_ID_MPHP_PDCH_FAIL_RECONNECT_REQ,
MSG_ID_MPHP_POLL_RESPONSE_REQ,
MSG_ID_MPHP_POWER_CONTROL_UPDATE_REQ,
MSG_ID_MPHP_PRACH_ABORT_REQ,
MSG_ID_MPHP_REPEAT_ALLOCATION_REQ,
MSG_ID_MPHP_TIMING_ADVANCE_UPDATE_REQ,
MSG_ID_MPHP_UPLINK_SINGLE_BLOCK_REQ,
#endif  /* __PS_SERVICE__ */ 
#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __EGPRS_MODE__
MSG_ID_MPHP_EGPRS_LOOP_REQ,
MSG_ID_MPHP_UPDATE_IR_RESET_REQ,
#endif

#ifdef __GEMINI__   
MSG_ID_MPHC_SIM_STATUS_UPDATE_REQ,
MSG_ID_MPHC_SUSPEND_ALT_L1_REQ,
MSG_ID_MPHC_RESUME_REQ,
#endif /*end of __GEMINI__*/

/* Confirmation & Indication for GSM */

MSG_ID_MPHC_POWER_SCAN_CNF,
MSG_ID_MPHC_MANUSEL_PWRSCAN_CNF,
MSG_ID_MPHC_BSIC_SYNC_CNF,
MSG_ID_MPHC_UNITDATA_IND,
MSG_ID_MPHC_RANDOM_ACCESS_CNF,
MSG_ID_MPHC_IMMED_ASSIGN_CNF,
MSG_ID_MPHC_CHANNEL_ASSIGN_CNF,
MSG_ID_MPHC_CHANNEL_RELEASE_CNF,
MSG_ID_MPHC_HANDOVER_CNF,
MSG_ID_MPHC_HANDOVER_ACCESS_START_IND,
MSG_ID_MPHC_HANDOVER_CONNECTED_IND,
MSG_ID_MPHC_HANDOVER_ACCESS_STOP_CNF,
MSG_ID_MPHC_CHANNEL_RECONNECT_CNF,
MSG_ID_MPHC_FREQUENCY_REDEFINITION_CNF,
MSG_ID_MPHC_CHANNEL_MODE_MODIFY_CNF,
MSG_ID_MPHC_CIPHERING_MODE_COMMAND_CNF,
MSG_ID_MPHC_CLOSE_TCH_LOOP_CNF,
MSG_ID_MPHC_OPEN_TCH_LOOP_CNF,
MSG_ID_MPHC_EXTENDED_MEAS_IND,
MSG_ID_MPHC_BLOCK_QUALITY_IND,
MSG_ID_MPHC_SERV_IDLE_MEAS_IND,
MSG_ID_MPHC_SERV_DEDI_MEAS_IND,
MSG_ID_MPHC_NEIGHBOR_MEAS_IND,
MSG_ID_MPHC_NEIGHBOR_BSIC_IND,
MSG_ID_MPHC_CELL_BSIC_IND,
MSG_ID_MPHC_DEACTIVATE_CNF,

#ifdef __PS_SERVICE__
/* Confirmation & Indication for GPRS */

MSG_ID_MPHP_DOWNLINK_SINGLE_BLOCK_CNF,
MSG_ID_MPHP_INTERFERENCE_MEAS_IND,
MSG_ID_MPHP_PACKET_BLOCK_QUALITY_IND,
MSG_ID_MPHP_PACKET_DATA_IND,
MSG_ID_MPHP_PACKET_DOWNLINK_ASSIGNMENT_CNF,
MSG_ID_MPHP_PACKET_EXTENDED_MEAS_IND,
MSG_ID_MPHP_PACKET_NC_MEAS_IND,
MSG_ID_MPHP_PACKET_RANDOM_ACCESS_CNF,
MSG_ID_MPHP_PACKET_SERV_MEAS_IND,
MSG_ID_MPHP_PACKET_UNASSIGNMENT_CNF,
MSG_ID_MPHP_PACKET_UPLINK_ASSIGNMENT_CNF,
MSG_ID_MPHP_PACKET_TIMESLOT_RECONFIGURE_CNF,
MSG_ID_MPHP_PDCH_FAIL_RECONNECT_CNF,
MSG_ID_MPHP_POLL_RESPONSE_CNF,
MSG_ID_MPHP_REPEAT_ALLOCATION_IND,
MSG_ID_MPHP_UPLINK_SINGLE_BLOCK_CNF,
#endif  /* __PS_SERVICE__ */   
#ifdef __EGPRS_MODE__
MSG_ID_MPHP_EGPRS_LOOP_CNF,
#endif
#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef L1A_SIM
MSG_ID_L1C_L1A_REPORT,
#endif
