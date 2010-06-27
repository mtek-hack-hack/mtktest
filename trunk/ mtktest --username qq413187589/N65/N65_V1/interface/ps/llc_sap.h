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
 *   llc.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   LLC related message identity definition
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


	/*-------------------------LLC messages---------------------*/
	MSG_ID_LLSMS_UNITDATA_REQ = MSG_ID_LLC_CODE_BEGIN,
	MSG_ID_LLTOM_UNITDATA_REQ,
	MSG_ID_LLGMM_UNITDATA_REQ,
	MSG_ID_LLGMM_ASSIGN_REQ,
	MSG_ID_LLGMM_TRIGGER_REQ,
	MSG_ID_LLGMM_SUSPEND_REQ,
	MSG_ID_LLGMM_RESUME_REQ,
	MSG_ID_LLSND_UNITDATA_REQ,
	MSG_ID_LLSND_DATA_REQ,
	MSG_ID_LLSND_XID_REQ,
	MSG_ID_LLSND_XID_RES,
	MSG_ID_LLSND_ESTABLISH_REQ,
	MSG_ID_LLSND_ESTABLISH_RES,
	MSG_ID_LLSND_RELEASE_REQ,
	MSG_ID_LLSND_CREATE_REG_REQ,
	MSG_ID_LLSND_SAPI_MEM_XID,
	MSG_ID_LLSND_RNR_STOP,
	MSG_ID_GRR_DATA_IND,
	MSG_ID_GRR_UNITDATA_IND,
	MSG_ID_GRR_STATUS_IND,
	MSG_ID_GRR_FLUSH_CNF,

	/* 3G specific messages */
#ifdef __MTK_3G_MRAT_ARCH__
	MSG_ID_RATCM_LLC_ASSIGN_REQ,
	MSG_ID_RATCM_LLC_RESUME_REQ,
	MSG_ID_RATCM_LLC_SUSPEND_REQ,
	MSG_ID_RATCM_LLC_TRIGGER_REQ,
	MSG_ID_RATCM_LLC_UNITDATA_REQ,
#endif
	/* End of 3G specific messages */

	MSG_ID_SAPI_MEM_FLOW_ON_REQ,
	MSG_ID_RLC_LLC_FLOW_CONTROL_OFF,
	MSG_ID_LL_TIMER_EXPIRY,
	MSG_ID_LL_CIPHER_RSP,
	MSG_ID_LL_DECIPHER_RSP,
	MSG_ID_RLC_LLC_RNR_TRIGGER,
	MSG_ID_LLSND_SAPI_ACT_REQ,
	MSG_ID_GRR_CIBUFF_AVAIL_IND,
	MSG_ID_AS_NAS_DATA_CNF,
	MSG_ID_LLSND_FLUSH_REQ,
	MSG_ID_LLSND_SAPI_DEACT_REQ,
	MSG_ID_LLC_CODE_END = MSG_ID_LLSND_SAPI_DEACT_REQ,
	/*----------------------- LLC_MSG_CODE_END -----------------*/


