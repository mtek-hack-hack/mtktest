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
 * CallsCost.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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

   FILENAME : Calls_Defs.h

   PURPOSE     : Call application 

   REMARKS     : nil

   AUTHOR      : PixTel

   DATE     : Jan 15,02

**************************************************************/

#ifndef _PIXTEL_CALLSCOST_H
#define _PIXTEL_CALLSCOST_H

#define MSG_MMI_CC_GET_CCM_REQ_STRUCT        mmi_cc_get_ccm_req_struct
#define MSG_MMI_CC_GET_CCM_RSP_STRUCT        mmi_cc_get_ccm_rsp_struct
#define MSG_MMI_CC_GET_ACM_REQ_STRUCT        mmi_cc_get_acm_req_struct
#define MSG_MMI_CC_GET_ACM_RSP_STRUCT        mmi_cc_get_acm_rsp_struct
#define MSG_MMI_CC_GET_MAX_ACM_REQ_STRUCT    mmi_cc_get_max_acm_req_struct
#define MSG_MMI_CC_GET_MAX_ACM_RSP_STRUCT    mmi_cc_get_max_acm_rsp_struct

#define MSG_MMI_CC_RESET_ACM_REQ_STRUCT      mmi_cc_reset_acm_req_struct
#define MSG_MMI_CC_RESET_ACM_RSP_STRUCT      mmi_cc_reset_acm_rsp_struct
#define MSG_MMI_CC_SET_MAX_ACM_REQ_STRUCT    mmi_cc_set_max_acm_req_struct
#define MSG_MMI_CC_SET_MAX_ACM_RSP_STRUCT    mmi_cc_set_max_acm_rsp_struct

#define MSG_MMI_SMU_GET_PUC_REQ_STRUCT       mmi_smu_get_puc_req_struct
#define MSG_MMI_SMU_GET_PUC_RSP_STRUCT       mmi_smu_get_puc_rsp_struct
#define MSG_MMI_SMU_SET_PUC_REQ_STRUCT       mmi_smu_set_puc_req_struct
#define MSG_MMI_SMU_SET_PUC_RSP_STRUCT       mmi_smu_set_puc_rsp_struct

extern void HighlightCHISTCallCostItem(S32 index);
extern void HighlightCHISTCallCost(void);
extern void HighlightCHISTLastCost(void);
extern void HighlightCHISTAllCost(void);
extern void HighlightCHISTResetCost(void);
extern void HighlightCHISTMaxCost(void);
extern void HighlightCHISTPriceAndUnit(void);
extern void HighlightPriceAndUnitHandler(S32 index);

extern void HintCHISTLastCost(U16 index);
extern void HintCHISTAllCost(U16 index);
extern void HintCHISTMaxCost(U16 index);
extern void HintCHISTPriceAndUnit(U16 index);

extern void EntryCHISTCallCost(void);
extern void ExitCHISTCallCost(void);
extern void EntryCHISTResetCost(void);
extern void EntryCHISTSetMaxCost(void);
extern void ExitCHISTSetMaxCost(void);
extern void EntryCHISTSetPriceUnit(void);
extern void ExitCHISTSetPriceUnit(void);
extern void EntryCHISTSetMaxCostConfirm(void);
extern void EntryCHISTSetPriceUnitConfirm(void);
extern void ExitCHISTSetPriceUnitConfirm(void);

extern void CHISTGetCallCost(void);
extern void CHISTValidateMaxCost(void);
extern void CHISTValidatePriceUnit(void);

extern void RspPin2ForCallCostSuccess(void);
extern void ReqGetLastCallCost(void);
extern void RspGetLastCallCost(void *info);
extern void ReqGetAllCallCost(void);
extern void RspGetAllCallCost(void *info);
extern void ReqGetMaxCallCost(void);
extern void RspGetMaxCallCost(void *info);
extern void ReqGetPriceAndUnit(void);
extern void RspGetPriceAndUnit(void *info);

extern void RspResetAllCallCost(void *info);
extern void ReqSetMaxCallCost(void);
extern void RspSetMaxCallCost(void *info);
extern void ReqSetPriceAndUnit(void);
extern void RspSetPriceAndUnit(void *info);

extern void CHISTConvertPPU(S8 *reqBuf, S8 *inputBuf);
extern void CHISTGoBackCallCostHistory(void);

#endif /* _PIXTEL_CALLSCOST_H */ 

