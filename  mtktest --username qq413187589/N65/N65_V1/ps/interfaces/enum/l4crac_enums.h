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
 *	l4rac_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for enum definition between RAC and L4C.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef  _L4CRAC_ENUMS_H
#define  _L4CRAC_ENUMS_H

typedef enum
{
   MS_CLASS_A,
   MS_CLASS_B,   
   MS_CLASS_CG,
   MS_CLASS_CC
} ms_mobile_class_enum;


typedef enum
{
   REG_STATE_NOT_REGISTERED=0,
   REG_STATE_REGISTERED,
   REG_STATE_SEARCHING,
   REG_STATE_REG_DENIED,
   REG_STATE_UNKNOWN,
   REG_STATE_NOT_ACTIVE
} reg_state_enum;


typedef enum
{
   REG_LA_RA_CHANGED,
   REG_NO_PLMN,
   REG_ON_PLMN,
   REG_LIMITED_SERVICE
} reg_status_cause_enum;

typedef enum
{
   L4C_RAC_OK,
   L4C_RAC_NO_CELL,
   L4C_RAC_LIMITED_SERVICE,
   L4C_RAC_ERROR,
   L4C_RAC_INVALID_SIM,
   L4C_RAC_ATTEMPT_TO_UPDATE,
   L4C_RAC_SEARCHING, /* Johnny 2005/11/07: add new temp gsm_status for MMI: L4C_RAC_SEARCHING */
   L4C_RAC_NULL
} l4c_rac_response_enum;

typedef enum
{
   GPRS_ATTACHED,                   /* GPRS Attached */
   GPRS_NO_COVERAGE,             /* No GPRS coverage */
   GPRS_LIMITED_SERVICE,       /* GPRS not Attached */
   GPRS_INVALID_SIM,               /* SIM invalid for GPRS */
   GPRS_REGISTERING,               /* GPRS Attach on going */
   GPRS_CELL_FOUND,                    /* GPRS coverage found */
   GPRS_NULL                                 /* GPRS not activated */
} l4c_rac_gprs_status_enum;

typedef enum
{
   L4C_RAT_NONE,
   L4C_RAT_GSM,
   L4C_RAT_UMTS,
   L4C_RAT_GSM_UMTS
} l4c_rat_enum;

//#ifdef __GEMINI__
typedef enum 
{
  L4C_SERVICE_INACTIVE_DUE_TO_RR_SUSPEND = 0,
  L4C_SERVICE_ACTIVE = 1
}l4c_rac_mmrr_service_status_enum;//GEMINI, 20080217
//#endif

#endif /* _L4CRAC_ENUMS_H */


