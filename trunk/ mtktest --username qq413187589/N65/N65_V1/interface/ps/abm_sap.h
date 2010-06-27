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
 *   abm.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   ABM related message identity definition
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

	/*-------------- ABM_MSG_CODE_BEGIN ------------------------*/
	/* Message from SOC */
   MSG_ID_SOC_ABM_ACTIVATE_REQ = MSG_ID_ABM_CODE_BEGIN,
   MSG_ID_SOC_ABM_DEACTIVATE_REQ,
   MSG_ID_SOC_ABM_IPADDR_CONFLICT_IND,

   /* Message from L4C */
   MSG_ID_L4C_PS_ABM_SETUP_RSP,
   MSG_ID_L4C_PS_ABM_DISC_RSP,
   MSG_ID_L4C_PS_ABM_DISC_IND,

   MSG_ID_L4C_CC_ABM_SETUP_RSP,
   MSG_ID_L4C_CC_ABM_DISC_RSP,
   MSG_ID_L4C_CC_ABM_DISC_IND,

   MSG_ID_L4CABM_START_REQ,
   MSG_ID_L4CABM_GET_GPRS_ACCOUNT_INFO_REQ,
   MSG_ID_L4CABM_SET_GPRS_ACCOUNT_INFO_REQ,

   /* Message to MMI */
   MSG_ID_MMI_ABM_WIFI_INIT_CNF,
   MSG_ID_MMI_ABM_WIFI_DEINIT_CNF,
   MSG_ID_MMI_ABM_WIFI_CONNECT_CNF,
   MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF,
   MSG_ID_MMI_ABM_WIFI_AP_LIST_CNF,
   MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_IND,
   MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_IND,
   MSG_ID_MMI_ABM_WIFI_CONNECT_IND,
   MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND,
   MSG_ID_MMI_ABM_IPADDR_UPDATE_IND,
   MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND,
   MSG_ID_MMI_ABM_IPADDR_CHANGE_CNF,

   /* Message from MMI */
   MSG_ID_MMI_ABM_WIFI_INIT_REQ,
   MSG_ID_MMI_ABM_WIFI_DEINIT_REQ,
   MSG_ID_MMI_ABM_WIFI_CONNECT_REQ,
   MSG_ID_MMI_ABM_WIFI_DISCONNECT_REQ,
   MSG_ID_MMI_ABM_WIFI_AP_LIST_REQ,
   MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_REJ,
   MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_REJ,
   MSG_ID_MMI_ABM_IPADDR_CHANGE_REQ,
   
   #ifdef  __UCM_SUPPORT__
   MSG_ID_MMI_ABM_CSD_CALL_APPROVE_REQ,
   MSG_ID_MMI_ABM_CSD_CALL_APPROVE_CNF,
   MSG_ID_ABM_L4C_GET_CSD_CALL_NUM_RSP,
   #endif /* __UCM_SUPPORT__ */

   /* Message from SUPC */
   MSG_ID_SUPC_ABM_WIFI_INIT_CNF,
   MSG_ID_SUPC_ABM_WIFI_DEINIT_CNF,
   MSG_ID_SUPC_ABM_WIFI_CONNECT_CNF,
   MSG_ID_SUPC_ABM_WIFI_CONNECT_IND,
   MSG_ID_SUPC_ABM_WIFI_DISCONNECT_CNF,
   MSG_ID_SUPC_ABM_WIFI_DISCONNECT_IND,
   MSG_ID_SUPC_ABM_WIFI_AP_LIST_CNF,


   MSG_ID_ABM_CODE_END = MSG_ID_SUPC_ABM_WIFI_AP_LIST_CNF,
	/*--------------- ABM_MSG_CODE_END--------------------*/


