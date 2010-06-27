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
 *  CSP.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : CSP.h

   PURPOSE     : Customer Service Profile

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Aug 6,03

**************************************************************/
#ifndef _PIXTEL_CSP_H
#define _PIXTEL_CSP_H
#include "MMIDataType.h"

typedef enum
{
    CSP_CT = 3,
    CSP_CFNRc,
    CSP_CFNRy,
    CSP_CFB,
    CSP_CFU
} CSP_CALL_OFFERING_ENUM;

typedef enum
{
    CSP_BIC_Roam = 3,
    CSP_BAIC,
    CSP_BOIC_exHC,
    CSP_BOIC,
    CSP_BOAC
} CSP_CALL_RESTRICTION_ENUM;

typedef enum
{
    CSP_CUG_OA = 3,
    CSP_Pref_CUG,
    CSP_AoC,
    CSP_CUG,
    CSP_MPTY
} CSP_OTHER_SS_ENUM;

typedef enum
{
    CSP_User_Signalling = 4,
    CSP_CCBS,
    CSP_CW,
    CSP_HOLD
} CSP_CALL_COMPLETION_ENUM;

typedef enum
{
    CSP_Validity_Period = 1,
    CSP_Protocol_ID,
    CSP_Del_Conf,
    CSP_Reply_path,
    CSP_SM_CB,
    CSP_SM_MO,
    CSP_SM_MT
} CSP_TELESERVICES_ENUM;

typedef enum
{
    ALS = 7
} CSP_CPHS_TELESERVICES_ENUM;

typedef enum
{
    CSP_SST = 7
} CSP_CPHS_FEATURES_ENUM;

typedef enum
{
    CSP_CLI_block = 0,
    CSP_CLI_send,
    CSP_MCI = 3,
    CSP_CoLP,
    CSP_CoLR,
    CSP_CLIP = 7
} CSP_NUMBER_IDENTIFICATION_ENUM;

typedef enum
{
    CSP_Multiple_Band = 2,
    CSP_Multiple_Subscriber_Profile,
    CSP_Voice_Broadcast_Service,
    CSP_Voice_Group_call,
    CSP_HSCSD,
    CSP_GPRS
} CSP_PHASE_2_ENUM;

typedef enum
{
    CSP_Language = 0,
    CSP_Data = 2,
    CSP_Fax,
    CSP_SM_MO_EMAIL,
    CSP_SM_MO_PAGING,
    CSP_VPS,
    CSP_PLMN_MODE
} CSP_VALUE_ADDED_SERVICES_ENUM;

typedef enum
{
    CSP_CALL_OFFERING_SERVICE_GROUP = 0,
    CSP_CALL_RESTRICTION_SERVICE_GROUP,
    CSP_OTHER_SS_SERVICE_GROUP,
    CSP_CALL_COMPLETION_SERVICE_GROUP,
    CSP_TELESERVICES_SERVICE_GROUP,
    CSP_CPHS_TELESERVICES_SERVICE_GROUP,
    CSP_CPHS_FEATURES_SERVICE_GROUP,
    CSP_NUMBER_IDENTIFICATION_SERVICE_GROUP,
    CSP_PHASE_2_SERVICE_GROUP,
    CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP,
    CSP_INFORMATION_NO_SERVICE_GROUP,
    CSP_TOTAL_SERVICE_GROUP
} CSP_SERVICE_GROUP_CODE;

extern U8 IsResetCSPGroupService(U8 serviceGroup, U8 service);
#ifdef __MMI_DUAL_SIM_MASTER__
extern U8 IsResetCSPGroupService_2(U8 serviceGroup, U8 service);
#endif
extern U8 IsInformationNumberAlowed(void);
extern void ClearCSPArray(void);
extern void InitialiseCSPInfoArray(U8 *cspInfo);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void InitialiseCSPInfoArray_2(U8 *cspInfo);
#endif
extern void CSPModifyHiliteHandlers(void);

#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_cphs_rearrange_call_main(U8 sim_source);
extern void mmi_cphs_rearrange_call_main_menu(U8 sim_source);
extern void mmi_cphs_rearrange_call_barring_main_menu(U8 sim_source);
extern void mmi_cphs_rearrange_call_barring_outgoing_menu(U8 sim_source);
extern void mmi_cphs_rearrange_call_barring_incoming_menu(U8 sim_source);
extern void mmi_cphs_rearrange_call_forwarding_menu(U8 sim_source);
extern void mmi_cphs_rearrange_caller_id_menu(U8 sim_source);
extern void mmi_cphs_rearrange_call_history_menu(U8 sim_source);
extern void mmi_cphs_rearrange_network_selection_menu(U8 sim_source);
extern void mmi_cphs_rearrange_message_main_menu(U8 sim_source);
extern void mmi_cphs_rearrange_message_setting_menu(U8 sim_source);
extern void mmi_cphs_rearrange_outgoing_call_management(U8 sim_source);
extern void mmi_cphs_rearrange_menu_items(U8 sim_source);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* _PIXTEL_CSP_H */ 

