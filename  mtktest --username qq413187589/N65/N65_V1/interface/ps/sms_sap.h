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
 *   sms.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SMS related message identity definition
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


	/*------------------- SMS_MSG_CODE_BEGIN--------------------*/
	MSG_ID_GMMSMS_REG_STATE_IND = MSG_ID_SMS_CODE_BEGIN,
	MSG_ID_LLSMS_UNITDATA_IND,
	MSG_ID_MMSMS_EST_IND,
	MSG_ID_MMSMS_EST_CNF,
	MSG_ID_MMSMS_DATA_IND,
	MSG_ID_MMSMS_REL_IND,
	MSG_ID_MMSMS_ERR_IND,
	MSG_ID_MMSMS_EST_REJ,
	MSG_ID_SMS_TIMER_EXPIRY,
	MSG_ID_MMSMS_EST_INTR,

	/* 3G */
	MSG_ID_GMMSMS_EST_CNF,
	MSG_ID_GMMSMS_EST_REJ,
	MSG_ID_GMMSMS_ERR_IND,
	MSG_ID_GMMSMS_UNITDATA_IND,

	/*MSGS_FROM_SMSAL*/
	MSG_ID_SMS_SUBMIT,
	MSG_ID_SMS_SUBMIT_ABORT,
	MSG_ID_SMS_COMMAND,
	MSG_ID_SMS_COMMAND_ABORT,
	MSG_ID_SMS_DELIVER_REPORT_ACK,
	MSG_ID_SMS_DELIVER_REPORT_NACK,
	MSG_ID_SMS_SERVICE_REQ,
	MSG_ID_SMS_MORE_MSG_SEND_REQ,
	MSG_ID_SMS_TRY_NEXT_BEARER_REQ,
	MSG_ID_SMS_MEM_AVL_NOTIF,
	MSG_ID_SMS_CODE_END = MSG_ID_SMS_MEM_AVL_NOTIF,
	/*------------------- SMS_MSG_CODE_END----------------------*/


