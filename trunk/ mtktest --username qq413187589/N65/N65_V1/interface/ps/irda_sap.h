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
 *  permission of MediaTek Inc. (C) 2003
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   irda_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MM related message identity definition
 *
 * Author:
 * -------
 * -------
 *****************************************************************************/
 
/*----------------------- MM_MSG_CODE_BEGIN------------------*/
	/* mesage received from TIMER at LMP SAP */
	/*TBD*/

	/* messages received from LMP at LAP */
	/* these message will not be used because the function call methodledge is used */
	MSG_ID_LAP_CONNECT_REQUEST=MSG_ID_IRDA_CODE_BEGIN,
	MSG_ID_LAP_DISCOVERY_REQUEST,
	MSG_ID_LAP_DATA_REQUEST,
	MSG_ID_LAP_DISCONNECT_REQUEST,
	MSG_ID_LAP_CONNECT_RESPONSE,
//	MSG_ID_IRDA_READY_TO_WRITE_IND,
	
	/* messages received from LAP at LMP */
	MSG_ID_LAP_DISCOVERY_INDICATION,
	MSG_ID_LAP_DISCOVERY_CONFIRM,
	MSG_ID_LAP_CONNECT_INDICATION,
	MSG_ID_LAP_CONNECT_CONFIRM,
	MSG_ID_LAP_DATA_INDICATION,
	MSG_ID_LAP_DISCONNECT_INDICATION,
	MSG_ID_LAP_DISCOVERY_MEDIA_BUSY_ERROR,
	
	/* messages received from upper layer at TTP SAP */
	MSG_ID_TTP_DATA_REQUEST,
	MSG_ID_TTP_CONNECT_REQUEST,
	MSG_ID_TTP_CONNECT_RESPONSE,
	MSG_ID_TTP_DISCONNECT_REQUEST,

	/* messages received from upper layer at LMP SAP */
	MSG_ID_LMP_DATA_REQUEST,
	MSG_ID_LMP_CONNECT_REQUEST,
	MSG_ID_LMP_CONNECT_RESPONSE,
	MSG_ID_LMP_DISCONNECT_REQUEST,			/* disconnect LSAP connection */
	MSG_ID_LMP_LINK_DISCONNECT_REQUEST,		/* disconnect LAP connection */
	MSG_ID_IAS_GET_REMOTE_LSAP_SEL,			
	
	/* message received from lower layer(LMP, TTP, IAS) at upper layer (TTP, IAS, upper AP) */
	MSG_ID_LMP_DATA_INDICATION,
	MSG_ID_LMP_CONNECT_INDICATION,
	MSG_ID_LMP_CONNECT_CONFIRM,
	MSG_ID_LMP_LSAP_DISCONNECT_INDICATION,		/* LSAP disconnect for specified module */
	MSG_ID_LMP_LINK_DISCONNECT_INDICATION,		/* LAP link disconnect */
	MSG_ID_IRDA_CLOSE_IND,
	
	MSG_ID_TTP_DATA_INDICATION,
	MSG_ID_TTP_CONNECT_INDICATION,
	MSG_ID_TTP_CONNECT_CONFIRM,
	MSG_ID_TTP_LSAP_DISCONNECT_INDICATION,		/* LSAP disconnect for specified module */
	
	MSG_ID_IAS_GET_REMOTE_LSAP_SEL_CONFIRM,	
	
	MSG_ID_IRDA_OPEN,
	MSG_ID_IRDA_CLOSE,
	/*IRDA*/
   MSG_ID_IRDA_READY_TO_WRITE_IND,
   MSG_ID_IRDA_END_OF_DISCOVERY_IND,        
   MSG_ID_FLC_LMP_IRPDU_HIGH_THRESHOLD_HIT,
	MSG_ID_IRAP_LMP_DL_IRPDU_RESUME,        
/*----------------------- IRDA_MSG_CODE_END--------------------*/

