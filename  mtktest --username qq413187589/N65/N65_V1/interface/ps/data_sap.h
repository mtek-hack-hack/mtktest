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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   data.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   DATA related message identity definition
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


/*------------------- DATA_MSG_CODE_BEGIN -------------------*/

	/*------------------- TDT Messages -------------------------*/
   MSG_ID_CSM_TDT_ACTIVATE_REQ = MSG_ID_TDT_CODE_BEGIN,
   MSG_ID_CSM_TDT_DEACTIVATE_REQ,
   MSG_ID_CSM_TDT_UART_SETOWNER_REQ,
   MSG_ID_CSM_TDT_ESC_OFF_REQ, 
   MSG_ID_PPP_TDT_DATA_REQ,
   MSG_ID_TDT_CODE_END = MSG_ID_PPP_TDT_DATA_REQ,
	
	/*------------------- L2R Messages -------------------------*/
   MSG_ID_CSM_L2R_ACTIVATE_REQ = MSG_ID_L2R_CODE_BEGIN,
   MSG_ID_CSM_L2R_DEACTIVATE_REQ,
   MSG_ID_CSM_L2R_UART_SETOWNER_REQ,
   MSG_ID_CSM_L2R_ESC_OFF_REQ,  
   MSG_ID_PPP_L2R_DATA_REQ,  
   MSG_ID_SMU_L2R_DATA_REQ,
  
   MSG_ID_L2R_RLP_CONN_CNF,
   MSG_ID_L2R_RLP_CONN_IND,
   MSG_ID_L2R_RLP_XID_IND,  
   MSG_ID_L2R_RLP_TEST_CNF,          /* test cnf */
   MSG_ID_L2R_RLP_UNITDATA_IND,   /* ui */
   MSG_ID_L2R_RLP_DISC_CNF,
   MSG_ID_L2R_RLP_DISC_IND,
   MSG_ID_L2R_RLP_DETACH_CNF,
   MSG_ID_L2R_RLP_ERROR_IND,
   MSG_ID_L2R_RLP_RESET_CNF,
   MSG_ID_L2R_RLP_RESET_IND,
   MSG_ID_L2R_RLP_DATA_IND,   
   MSG_ID_L2R_RLP_READY_IND,   
   MSG_ID_L2R_RLP_CHANGE_RATE_IND,
   MSG_ID_L2R_RLP_PREPARE_REMAP_IND,
   MSG_ID_L2R_RLP_REMAP_IND,       
   MSG_ID_FLC_CSD_DL_APPDU_RESUME,
   MSG_ID_L2R_CODE_END = MSG_ID_L2R_RLP_REMAP_IND,
   
   /*------------------- RLP Messages -------------------------*/
	MSG_ID_L2R_RLP_ATTACH_REQ = MSG_ID_RLP_CODE_BEGIN,
   MSG_ID_L2R_RLP_DATA_REQ,
   MSG_ID_L2R_RLP_CONN_REQ,
   MSG_ID_L2R_RLP_CONN_RESP,
   MSG_ID_L2R_RLP_RESET_RESP,
   MSG_ID_L2R_RLP_RESET_REQ,
   MSG_ID_L2R_RLP_DISC_REQ,
   MSG_ID_L2R_RLP_UNITDATA_REQ,
   MSG_ID_L2R_RLP_XID_REQ,
   MSG_ID_L2R_RLP_TEST_REQ,
   MSG_ID_L2R_RLP_PREPARE_REMAP_RESP,
   MSG_ID_L2R_RLP_REMAP_RESP,
   MSG_ID_L2R_RLP_DETACH_REQ,
   MSG_ID_RLP_RA_DATA_REQ,  
   MSG_ID_RLP_RA_DATA_IND,      
	MSG_ID_FLC_RLP_RR_REQ,
	MSG_ID_FLC_RLP_RNR_REQ,
   MSG_ID_L2R_RLP_ABOVE_UP_THRESHOLD_IND,
   MSG_ID_L2R_RLP_BELOW_UP_THRESHOLD_IND,

   MSG_ID_CSD_UART_READY_TO_READ,
   MSG_ID_CSD_UART_READY_TO_WRITE,
   MSG_ID_CSD_UART_DATA_REQ,
   MSG_ID_CSD_UART_FULL_IND,
   MSG_ID_CSD_ACTIVATE_REQ,
   MSG_ID_CSD_DEACTIVATE_REQ,
   MSG_ID_CSD_RA_DATA_REQ,  
   MSG_ID_CSD_RA_DATA_IND,      
   MSG_ID_CSD_CEEL_CHANGE_START_IND,
   MSG_ID_CSD_CEEL_CHANGE_FINIDSH_IND,
   MSG_ID_CSD_UPLINK_TICK_IND,
   MSG_ID_CSD_DOWNLINK_TICK_IND,
   MSG_ID_RLP_CODE_END = MSG_ID_CSD_DOWNLINK_TICK_IND,

	/*------------------- T30 Messages -------------------------*/
   MSG_ID_CSM_T30_ACTIVATE_REQ = MSG_ID_T30_CODE_BEGIN,
   MSG_ID_CSM_T30_DEACTIVATE_REQ,
   MSG_ID_CSM_T30_FAX_RATE_REQ,

   MSG_ID_L4C_T30_RW_STR_PARAM_REQ,
   MSG_ID_L4C_T30_RW_PARAM_REQ,
   MSG_ID_L4C_T30_TX_MSG_REQ, 
   MSG_ID_L4C_T30_RX_MSG_REQ,
   MSG_ID_L4C_T30_TX_BCS_REQ,
   MSG_ID_L4C_T30_RX_BCS_REQ,
   MSG_ID_L4C_T30_TX_SILENCE_REQ,
   MSG_ID_L4C_T30_RX_SILENCE_REQ,
   MSG_ID_L4C_T30_TRANSFER_UART_REQ,
   MSG_ID_L4C_T30_TX_PPM_REQ,

   MSG_ID_FA_T30_ACTIVATE_CNF,
   MSG_ID_FA_T30_DEACTIVATE_CNF,
   MSG_ID_FA_T30_TX_DATA_CNF, 
   MSG_ID_FA_T30_RX_DATA_CNF, 
   MSG_ID_FA_T30_DISC_IND,
   MSG_ID_FA_T30_CMD_CNF,

   MSG_ID_FA_T30_CMD_IND,
   MSG_ID_FA_T30_DATA_IND,
   MSG_ID_FA_T30_GET_CMD_IND,
   MSG_ID_FA_T30_GET_DATA_IND,

   MSG_ID_FA_T30_TX_DATA_END_IND,
   MSG_ID_FA_T30_RX_DATA_END_IND,
   MSG_ID_FA_T30_TX_CMD_END_IND, 
   MSG_ID_FA_T30_RX_CMD_END_IND, 

   MSG_ID_FA_T30_GETMORE_DATA_IND,
   MSG_ID_FA_T30_OVERFLOW_IND,
   MSG_ID_FA_T30_DATA_AVAILABLE_IND,
   MSG_ID_FA_T30_RATE_CHANGE_IND,
   MSG_ID_FA_T30_HDLC_IND,
   MSG_ID_T30_CODE_END = MSG_ID_FA_T30_HDLC_IND,

	/*------------------- FA Messages -------------------------*/
   MSG_ID_T30_FA_ACTIVATE_REQ = MSG_ID_FA_CODE_BEGIN,
   MSG_ID_T30_FA_DEACTIVATE_REQ, 
   MSG_ID_T30_FA_CMD_REQ, 
   MSG_ID_T30_FA_DATA_REQ,   
   MSG_ID_T30_FA_TX_DATA_REQ, 
   MSG_ID_T30_FA_RX_DATA_REQ, 
   MSG_ID_T30_FA_FAX_RATE_REQ,  
   MSG_ID_T30_FA_SEND_DATA_REQ, 
   MSG_ID_FA_T30_HDLC_REQ,

   MSG_ID_RA_FA_PROCESS_CMD_IND,

   MSG_ID_RA_FA_ACTIVATE_CNF, 
   MSG_ID_RA_FA_DL_Q_FULL_IND, 
   MSG_ID_RA_FA_DL_Q_OVERFLOW_IND, 
   MSG_ID_RA_FA_UL_Q_UNDERFLOW_IND, 
   MSG_ID_RA_FA_TX_DATA_CNF, 
   MSG_ID_RA_FA_RX_DATA_CNF, 
   MSG_ID_RA_FA_RX_DATA_END_IND, 
   MSG_ID_RA_FA_TX_DATA_END_IND, 
   MSG_ID_RA_FA_RX_CMD_END_IND, 
   MSG_ID_RA_FA_TX_CMD_END_IND, 
   MSG_ID_RA_FA_RX_MSG_REC_IND, 
   MSG_ID_RA_FA_RATE_CHANGE_IND,
   MSG_ID_FA_CODE_END = MSG_ID_RA_FA_RATE_CHANGE_IND,
  
/*------------------- DATA_MSG_CODE_END ---------------------*/
	


