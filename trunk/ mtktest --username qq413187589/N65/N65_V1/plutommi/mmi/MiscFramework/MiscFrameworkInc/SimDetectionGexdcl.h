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
 * SimDetectionGexdcl.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Global variable definitions for SimDetection modules
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
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : SimDetectionGexdcl.h

   PURPOSE     : Global variable definitions for SimDetection
               module.

   REMARKS     : nil

   AUTHOR      : Deepali

   DATE     : 12/03/03

**************************************************************/

#ifndef __SIM_DETECTION_EXDCL_H__
#define __SIM_DETECTION_EXDCL_H__
#include "SimDetectionDef.h"

extern PLMNINFO bcdPlmnsToDisplayName[];
extern U8 gNWProviderName[];
#ifdef __MMI_WLAN_FEATURES__
extern U8 gWLANProviderName[];
#endif

/* Lisen 04112005 */
typedef enum
{
    __911__,
#ifdef __MEXICO_ECC__
    __080__,
    __060__,
    __08__,
#endif /* __MEXICO_ECC__ */ 
#ifdef __RUSSIA_ECC__
    __01__,
    __02__,
    __03__,
    __001__,
    __002__,
    __003__,
#endif /* __RUSSIA_ECC__ */
#if defined(__CPHS__)
    __999__,
#endif
    __112__,
    MAX_EMERGENCYNUMBER
} neum_emergencynumber;

extern U16 EmergencyNumber[MAX_EMERGENCYNUMBER][4];

extern S8 gInputPwdBuffer[];

/* var hold PLMN to be used later on for displaying Roaming Symbol
   by comparing this value returned in MSG_ID_MMI_SMU_GET_IMSI_RSP */
extern U8 gPLMN[];
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
extern U8 gPLMN_2[];
#endif

extern S8 gServProvderName[];
extern S8 gOperatorName[];
extern S8 gShortOperatorName[];
extern S8 gOwnerName[];
extern U8 gOpNameValid;
extern U8 gShortOpnameValid;
extern U8 gSpnValid;

extern pwr_context_struct g_pwr_context;
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
extern pwr_context_struct g_pwr_context_2;
#endif

extern charbat_context_struct g_charbat_context;
#endif /* __SIM_DETECTION_EXDCL_H__ */ 

