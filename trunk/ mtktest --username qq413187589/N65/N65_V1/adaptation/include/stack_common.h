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
 *   stack_common.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the following.
 *   1. All the module ID definitions.
 *   2. All the Stack SAPS.
 *   3. All the MSG code bases.
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
 *
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

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _STACK_COMMON_H
#define _STACK_COMMON_H


/*************************************************************************
 * Constant Definition
 *************************************************************************/
#define MAX_CUSTOM_MESSAGE_ID       1000   /* Maximum custom message ID */
#define MAX_CUSTOM_SAP_ID           10     /* Maximum custom SAP ID */ /* Don't modify */

/*************************************************************************
* Macros Without Parameters
 *************************************************************************/
#define MAX_SAPS                    256
/* Modify from 4 to 8 (8 * 32 bit = 256), because there are more modules now */
/* and maximum possible task number is 255 according to priority convention */
#define RPS_MASK_ARRAY_SIZE         8
#define RPS_ALLOCATE_ILM_MASK       31
#define RPS_ALLOCATE_ILM_SHIFT      5

typedef enum {

   MSG_ID_MM_CODE_BEGIN = 501,
   MSG_ID_MM_CODE_RANGE = 100,

   MSG_ID_CC_CODE_BEGIN = (MSG_ID_MM_CODE_BEGIN + MSG_ID_MM_CODE_RANGE),
   MSG_ID_CC_CODE_RANGE = 100,

   MSG_ID_DT_CODE_BEGIN = (MSG_ID_CC_CODE_BEGIN + MSG_ID_CC_CODE_RANGE),
   MSG_ID_DT_CODE_RANGE = 10,

   MSG_ID_CISS_CODE_BEGIN = (MSG_ID_DT_CODE_BEGIN + MSG_ID_DT_CODE_RANGE),
   MSG_ID_CISS_CODE_RANGE = 100,

   MSG_ID_SMS_CODE_BEGIN = (MSG_ID_CISS_CODE_BEGIN + MSG_ID_CISS_CODE_RANGE),
   MSG_ID_SMS_CODE_RANGE = 100,

   MSG_ID_SIM_CODE_BEGIN = (MSG_ID_SMS_CODE_BEGIN + MSG_ID_SMS_CODE_RANGE),
   MSG_ID_SIM_CODE_RANGE = 150,

   MSG_ID_L4C_CODE_BEGIN = (MSG_ID_SIM_CODE_BEGIN + MSG_ID_SIM_CODE_RANGE),
   MSG_ID_L4C_CODE_RANGE = 300,

   MSG_ID_TCM_CODE_BEGIN = (MSG_ID_L4C_CODE_BEGIN + MSG_ID_L4C_CODE_RANGE),
   MSG_ID_TCM_CODE_RANGE = 100,

   MSG_ID_CSM_CODE_BEGIN = (MSG_ID_TCM_CODE_BEGIN + MSG_ID_TCM_CODE_RANGE),
   MSG_ID_CSM_CODE_RANGE = 100,

   MSG_ID_SMSAL_CODE_BEGIN = (MSG_ID_CSM_CODE_BEGIN + MSG_ID_CSM_CODE_RANGE),
   MSG_ID_SMSAL_CODE_RANGE = 100,

   MSG_ID_SMU_CODE_BEGIN = (MSG_ID_SMSAL_CODE_BEGIN + MSG_ID_SMSAL_CODE_RANGE),
   MSG_ID_SMU_CODE_RANGE = 100,

   MSG_ID_UEM_CODE_BEGIN = (MSG_ID_SMU_CODE_BEGIN + MSG_ID_SMU_CODE_RANGE),
   MSG_ID_UEM_CODE_RANGE = 100,

   MSG_ID_RAC_CODE_BEGIN = (MSG_ID_UEM_CODE_BEGIN + MSG_ID_UEM_CODE_RANGE),
   MSG_ID_RAC_CODE_RANGE = 100,

   MSG_ID_USAT_CODE_BEGIN = (MSG_ID_RAC_CODE_BEGIN + MSG_ID_RAC_CODE_RANGE),
   MSG_ID_USAT_CODE_RANGE = 100,

   MSG_ID_PHB_CODE_BEGIN = (MSG_ID_USAT_CODE_BEGIN + MSG_ID_USAT_CODE_RANGE),
   MSG_ID_PHB_CODE_RANGE = 100,

   MSG_ID_ENG_CODE_BEGIN = (MSG_ID_PHB_CODE_BEGIN + MSG_ID_PHB_CODE_RANGE),
   MSG_ID_ENG_CODE_RANGE = 100,

   MSG_ID_L4A_CODE_BEGIN = (MSG_ID_ENG_CODE_BEGIN + MSG_ID_ENG_CODE_RANGE),
   MSG_ID_L4A_CODE_RANGE = 1300,

   MSG_ID_RLC_CODE_BEGIN = (MSG_ID_L4A_CODE_BEGIN + MSG_ID_L4A_CODE_RANGE),
   MSG_ID_RLC_CODE_RANGE = 100,

   /* MSG_ID_RRM_COMMON_CODE_BEGIN is used when __MTK_3G_MRAT_ARCH__ is defined */
   /* MSG_ID_RRM_CODE_BEGIN is reserved for backward compatible */
   MSG_ID_RRM_COMMON_CODE_BEGIN = (MSG_ID_RLC_CODE_BEGIN + MSG_ID_RLC_CODE_RANGE),
   MSG_ID_RRM_COMMON_CODE_RANGE = 100,
   MSG_ID_RRM_CODE_BEGIN = MSG_ID_RRM_COMMON_CODE_BEGIN,
   MSG_ID_RRM_CODE_RANGE = MSG_ID_RRM_COMMON_CODE_RANGE,

   MSG_ID_RCS_CODE_BEGIN = (MSG_ID_RRM_COMMON_CODE_BEGIN + MSG_ID_RRM_COMMON_CODE_RANGE),
   MSG_ID_RCS_CODE_RANGE = 100,

   MSG_ID_RMPC_CODE_BEGIN = (MSG_ID_RCS_CODE_BEGIN + MSG_ID_RCS_CODE_RANGE),
   MSG_ID_RMPC_CODE_RANGE = 200,
   
   MSG_ID_RRM_MPAL_DM_CODE_BEGIN = (MSG_ID_RMPC_CODE_BEGIN + MSG_ID_RMPC_CODE_RANGE),
   MSG_ID_RRM_MPAL_DM_CODE_RANGE = 100,

   MSG_ID_MAC_CODE_BEGIN = (MSG_ID_RRM_MPAL_DM_CODE_BEGIN + MSG_ID_RRM_MPAL_DM_CODE_RANGE),
   MSG_ID_MAC_CODE_RANGE = 100,
   
   MSG_ID_LAPDM_CODE_BEGIN = (MSG_ID_MAC_CODE_BEGIN + MSG_ID_MAC_CODE_RANGE),
   MSG_ID_LAPDM_CODE_RANGE = 100,
   
   MSG_ID_REASM_CODE_BEGIN = (MSG_ID_LAPDM_CODE_BEGIN + MSG_ID_LAPDM_CODE_RANGE),
   MSG_ID_REASM_CODE_RANGE = 100,
   
   MSG_ID_MPAL_CODE_BEGIN = (MSG_ID_REASM_CODE_BEGIN + MSG_ID_REASM_CODE_RANGE),
   MSG_ID_MPAL_CODE_RANGE = 100,
   
   MSG_ID_LLC_CODE_BEGIN = (MSG_ID_MPAL_CODE_BEGIN + MSG_ID_MPAL_CODE_RANGE),
   MSG_ID_LLC_CODE_RANGE = 100,
   
   MSG_ID_SND_CODE_BEGIN = (MSG_ID_LLC_CODE_BEGIN + MSG_ID_LLC_CODE_RANGE),
   MSG_ID_SND_CODE_RANGE = 100,
   
   MSG_ID_SM_CODE_BEGIN = (MSG_ID_SND_CODE_BEGIN + MSG_ID_SND_CODE_RANGE),
   MSG_ID_SM_CODE_RANGE = 100,
   
   MSG_ID_PPP_CODE_BEGIN = (MSG_ID_SM_CODE_BEGIN + MSG_ID_SM_CODE_RANGE),
   MSG_ID_PPP_CODE_RANGE = 100,
   
   MSG_ID_TDT_CODE_BEGIN = (MSG_ID_PPP_CODE_BEGIN + MSG_ID_PPP_CODE_RANGE),
   MSG_ID_T30_CODE_BEGIN = (MSG_ID_TDT_CODE_BEGIN + 9),
   MSG_ID_FA_CODE_BEGIN = (MSG_ID_T30_CODE_BEGIN + 50),
   MSG_ID_TDT_CODE_RANGE = 100,
   
   MSG_ID_L2R_CODE_BEGIN = (MSG_ID_TDT_CODE_BEGIN + MSG_ID_TDT_CODE_RANGE),
   MSG_ID_L2R_CODE_RANGE = 100,
   
   MSG_ID_RLP_CODE_BEGIN = (MSG_ID_L2R_CODE_BEGIN + MSG_ID_L2R_CODE_RANGE),
   MSG_ID_RLP_CODE_RANGE = 100,
   
   MSG_ID_MMIAPI_CODE_BEGIN = (MSG_ID_RLP_CODE_BEGIN + MSG_ID_RLP_CODE_RANGE),
   MSG_ID_MMIAPI_CODE_RANGE = 100,
   
   MSG_ID_MED_CODE_BEGIN = (MSG_ID_MMIAPI_CODE_BEGIN + MSG_ID_MMIAPI_CODE_RANGE),
   MSG_ID_MED_CODE_RANGE = 500,
   
   MSG_ID_VT_CODE_BEGIN = (MSG_ID_MED_CODE_BEGIN + MSG_ID_MED_CODE_RANGE),
   MSG_ID_VT_CODE_RANGE = 100,

   MSG_ID_F_CSR_CODE_BEGIN = (MSG_ID_VT_CODE_BEGIN + MSG_ID_VT_CODE_RANGE),
   MSG_ID_F_CSR_CODE_RANGE = 100,

   MSG_ID_ABM_CODE_BEGIN = (MSG_ID_F_CSR_CODE_BEGIN + MSG_ID_F_CSR_CODE_RANGE),
   MSG_ID_ABM_CODE_RANGE = 100,
   
   MSG_ID_SOC_CODE_BEGIN = (MSG_ID_ABM_CODE_BEGIN + MSG_ID_ABM_CODE_RANGE),
   MSG_ID_SOC_CODE_RANGE = 100,
   
   MSG_ID_TCPIP_CODE_BEGIN = (MSG_ID_SOC_CODE_BEGIN + MSG_ID_SOC_CODE_RANGE),
   MSG_ID_TCPIP_CODE_RANGE = 100,
   
   MSG_ID_WAP_CODE_BEGIN = (MSG_ID_TCPIP_CODE_BEGIN + MSG_ID_TCPIP_CODE_RANGE),
   MSG_ID_WAP_CODE_RANGE = 300,
   
   MSG_ID_EM_CODE_BEGIN = (MSG_ID_WAP_CODE_BEGIN + MSG_ID_WAP_CODE_RANGE),
   MSG_ID_EM_CODE_RANGE = 100,
   
   MSG_ID_IRDA_CODE_BEGIN = (MSG_ID_EM_CODE_BEGIN + MSG_ID_EM_CODE_RANGE),
   MSG_ID_IRDA_CODE_RANGE = 100,
   
   MSG_ID_OBEX_CODE_BEGIN = (MSG_ID_IRDA_CODE_BEGIN + MSG_ID_IRDA_CODE_RANGE),
   MSG_ID_OBEX_CODE_RANGE = 100,
   
   MSG_ID_IRCOMM_CODE_BEGIN = (MSG_ID_OBEX_CODE_BEGIN + MSG_ID_OBEX_CODE_RANGE),
   MSG_ID_IRCOMM_CODE_RANGE = 100,
   
   MSG_ID_MED_V_CODE_BEGIN = (MSG_ID_IRCOMM_CODE_BEGIN + MSG_ID_IRCOMM_CODE_RANGE),
   MSG_ID_MED_V_CODE_RANGE = 100,
   
   MSG_ID_J2ME_CODE_BEGIN = (MSG_ID_MED_V_CODE_BEGIN + MSG_ID_MED_V_CODE_RANGE),
   MSG_ID_J2ME_CODE_RANGE = 200,
   
   MSG_ID_EMAIL_CODE_BEGIN = (MSG_ID_J2ME_CODE_BEGIN + MSG_ID_J2ME_CODE_RANGE),
   MSG_ID_EMAIL_CODE_RANGE = 180,
   
   MSG_ID_FMT_MSG_CODE_BEGIN = (MSG_ID_EMAIL_CODE_BEGIN + MSG_ID_EMAIL_CODE_RANGE),
   MSG_ID_FMT_MSG_CODE_RANGE = 120,
   
   DRIVER_MSG_CODE_BEGIN = (MSG_ID_FMT_MSG_CODE_BEGIN + MSG_ID_FMT_MSG_CODE_RANGE),
   DRIVER_MSG_CODE_RANGE = 200,
   
   MSG_ID_NVRAM_CODE_BEGIN = (DRIVER_MSG_CODE_BEGIN + DRIVER_MSG_CODE_RANGE),
   MSG_ID_NVRAM_CODE_RANGE = 100,
   
   MSG_ID_DPS_MSG_START = (MSG_ID_NVRAM_CODE_BEGIN + MSG_ID_NVRAM_CODE_RANGE),
   MSG_ID_DPS_MSG_RANGE = 1000,
   
   MSG_ID_UDPS_MSG_START = (MSG_ID_DPS_MSG_START + MSG_ID_DPS_MSG_RANGE),
   MSG_ID_UDPS_MSG_RANGE = 1000,

   L1_MSG_CODE_BEGIN = (MSG_ID_UDPS_MSG_START + MSG_ID_UDPS_MSG_RANGE),
   L1_MSG_CODE_RANGE = 200,
   
   L1HISR_MSG_CODE_BEGIN = (L1_MSG_CODE_BEGIN + L1_MSG_CODE_RANGE),
   L1HISR_MSG_CODE_RANGE = 700,
   
   FT_MSG_CODE_BEGIN = (L1HISR_MSG_CODE_BEGIN + L1HISR_MSG_CODE_RANGE),
   FT_MSG_CODE_RANGE = 100,

   TST_MSG_CODE_BEGIN = (FT_MSG_CODE_BEGIN + FT_MSG_CODE_RANGE),
   TST_MSG_CODE_RANGE = 1200,
   
   SYSDEBUG_MSG_CODE_BEGIN = (TST_MSG_CODE_BEGIN + TST_MSG_CODE_RANGE),
   SYSDEBUG_MSG_CODE_RANGE = 100,
   
   CMUX_MSG_CODE_BEGIN = (SYSDEBUG_MSG_CODE_BEGIN + SYSDEBUG_MSG_CODE_RANGE),
   CMUX_MSG_CODE_RANGE = 1100,
   
   MSG_ID_IMPS_CODE_BEGIN = (CMUX_MSG_CODE_BEGIN + CMUX_MSG_CODE_RANGE),
   MSG_ID_IMPS_CODE_RANGE = 150,
   
   SIP_MSG_CODE_BEGIN = (MSG_ID_IMPS_CODE_BEGIN + MSG_ID_IMPS_CODE_RANGE),
   SIP_MSG_CODE_RANGE = 50,
   
   POC_MSG_CODE_BEGIN = (SIP_MSG_CODE_BEGIN + SIP_MSG_CODE_RANGE),
   POC_MSG_CODE_RANGE = 100,
   
   BCHS_MSG_CODE_BEGIN = (POC_MSG_CODE_BEGIN + POC_MSG_CODE_RANGE),
   BCHS_MSG_CODE_RANGE = 1000,
   
   BT_MSG_CODE_BEGIN = (BCHS_MSG_CODE_BEGIN + BCHS_MSG_CODE_RANGE),
   BT_MSG_CODE_RANGE = 600,
      
   XDM_MSG_CODE_BEGIN = (BT_MSG_CODE_BEGIN + BT_MSG_CODE_RANGE),
   XDM_MSG_CODE_RANGE = 50,
   
   WNDRV_MSG_CODE_BEGIN = (XDM_MSG_CODE_BEGIN + XDM_MSG_CODE_RANGE),
   WNDRV_MSG_CODE_RANGE = 100,

   SUPC_MSG_CODE_BEGIN = (WNDRV_MSG_CODE_BEGIN + WNDRV_MSG_CODE_RANGE),
   SUPC_MSG_CODE_RANGE  = 100,

   MSG_ID_DHCP_CODE_BEGIN = (SUPC_MSG_CODE_BEGIN + SUPC_MSG_CODE_RANGE),
   MSG_ID_DHCP_CODE_RANGE  = 50,
   
   MSG_ID_IPERF_CODE_BEGIN = (MSG_ID_DHCP_CODE_BEGIN + MSG_ID_DHCP_CODE_RANGE),
   MSG_ID_IPERF_CODE_RANGE  = 50,
   
   MSG_ID_TFTP_CODE_BEGIN = (MSG_ID_IPERF_CODE_BEGIN + MSG_ID_IPERF_CODE_RANGE),
   MSG_ID_TFTP_CODE_RANGE  = 50,
     
   SAF_MSG_CODE_BEGIN = (MSG_ID_TFTP_CODE_BEGIN + MSG_ID_TFTP_CODE_RANGE),
   SAF_MSG_CODE_RANGE = 50,
   
   VOIP_MSG_CODE_BEGIN = (SAF_MSG_CODE_BEGIN + SAF_MSG_CODE_RANGE),
   VOIP_MSG_CODE_RANGE = 100,
   
   VUART_MSG_CODE_BEGIN = (VOIP_MSG_CODE_BEGIN + VOIP_MSG_CODE_RANGE),
   VUART_MSG_CODE_RANGE  = 10,
 
   MSG_ID_MED_C_CODE_BEGIN = (VUART_MSG_CODE_BEGIN + VUART_MSG_CODE_RANGE),
   MSG_ID_MED_C_CODE_RANGE = 100,

   MSG_ID_SYNCML_CODE_BEGIN = (MSG_ID_MED_C_CODE_BEGIN + MSG_ID_MED_C_CODE_RANGE),
   MSG_ID_SYNCML_CODE_RANGE = 100,

   RTSP_MSG_CODE_BEGIN = (MSG_ID_SYNCML_CODE_BEGIN + MSG_ID_SYNCML_CODE_RANGE),
   RTSP_MSG_CODE_RANGE = 20,

   MSG_ID_MEXE_CODE_BEGIN = (RTSP_MSG_CODE_BEGIN + RTSP_MSG_CODE_RANGE),
   MSG_ID_MEXE_CODE_RANGE = 10,

   MSG_ID_DM_CODE_BEGIN = (MSG_ID_MEXE_CODE_BEGIN + MSG_ID_MEXE_CODE_RANGE),
   MSG_ID_DM_CODE_RANGE = 50,

   MSG_ID_DRMT_MSG_CODE_BEGIN = (MSG_ID_DM_CODE_BEGIN + MSG_ID_DM_CODE_RANGE),
   MSG_ID_DRMT_MSG_CODE_RANGE = 100,

   MSG_ID_GIS_MSG_CODE_BEGIN = (MSG_ID_DRMT_MSG_CODE_BEGIN + MSG_ID_DRMT_MSG_CODE_RANGE),
   MSG_ID_GIS_MSG_CODE_RANGE = 50,

   MSG_ID_CERTMAN_MSG_CODE_BEGIN = (MSG_ID_GIS_MSG_CODE_BEGIN + MSG_ID_GIS_MSG_CODE_RANGE),
   MSG_ID_CERTMAN_MSG_CODE_RANGE = 100,

   MSG_ID_MMI_CERTMAN_MSG_CODE_BEGIN = (MSG_ID_CERTMAN_MSG_CODE_BEGIN + MSG_ID_CERTMAN_MSG_CODE_RANGE),
   MSG_ID_MMI_CERTMAN_MSG_CODE_RANGE = 20,

   MSG_ID_TLS_CODE_BEGIN = (MSG_ID_MMI_CERTMAN_MSG_CODE_BEGIN + MSG_ID_MMI_CERTMAN_MSG_CODE_RANGE),
   MSG_ID_TLS_CODE_RANGE  = 20,

   MSG_ID_RATCM_CODE_BEGIN = (MSG_ID_TLS_CODE_BEGIN + MSG_ID_TLS_CODE_RANGE),
   MSG_ID_RATCM_CODE_RANGE = 200,

   MSG_ID_RATDM_CODE_BEGIN = (MSG_ID_RATCM_CODE_BEGIN + MSG_ID_RATCM_CODE_RANGE),
   MSG_ID_RATDM_CODE_RANGE = 100,

   MSG_ID_ADR_CODE_BEGIN = (MSG_ID_RATDM_CODE_BEGIN + MSG_ID_RATDM_CODE_RANGE),
   MSG_ID_ADR_CODE_RANGE = 100,

   MSG_ID_CSCE_CODE_BEGIN = (MSG_ID_ADR_CODE_BEGIN + MSG_ID_ADR_CODE_RANGE),
   MSG_ID_CSCE_CODE_RANGE = 100,

   MSG_ID_CSE_CODE_BEGIN = (MSG_ID_CSCE_CODE_BEGIN + MSG_ID_CSCE_CODE_RANGE),
   MSG_ID_CSE_CODE_RANGE = 100,

   MSG_ID_MEME_CODE_BEGIN = (MSG_ID_CSE_CODE_BEGIN + MSG_ID_CSE_CODE_RANGE),
   MSG_ID_MEME_CODE_RANGE = 100,

   MSG_ID_RRCE_CODE_BEGIN = (MSG_ID_MEME_CODE_BEGIN + MSG_ID_MEME_CODE_RANGE),
   MSG_ID_RRCE_CODE_RANGE = 100,

   MSG_ID_SIBE_CODE_BEGIN = (MSG_ID_RRCE_CODE_BEGIN + MSG_ID_RRCE_CODE_RANGE),
   MSG_ID_SIBE_CODE_RANGE = 100,

   MSG_ID_SLCE_CODE_BEGIN = (MSG_ID_SIBE_CODE_BEGIN + MSG_ID_SIBE_CODE_RANGE),
   MSG_ID_SLCE_CODE_RANGE = 200,

   MSG_ID_USIME_CODE_BEGIN = (MSG_ID_SLCE_CODE_BEGIN + MSG_ID_SLCE_CODE_RANGE),
   MSG_ID_USIME_CODE_RANGE = 100,

   MSG_ID_DBME_CODE_BEGIN = (MSG_ID_USIME_CODE_BEGIN + MSG_ID_USIME_CODE_RANGE),
   MSG_ID_DBME_CODE_RANGE = 20,

   MSG_ID_UMAC_CODE_BEGIN = (MSG_ID_DBME_CODE_BEGIN + MSG_ID_DBME_CODE_RANGE),
   MSG_ID_UMAC_CODE_RANGE = 100,

   MSG_ID_URLC_CODE_BEGIN = (MSG_ID_UMAC_CODE_BEGIN + MSG_ID_UMAC_CODE_RANGE),
   MSG_ID_URLC_CODE_RANGE = 100,

   MSG_ID_BMC_CODE_BEGIN = (MSG_ID_URLC_CODE_BEGIN + MSG_ID_URLC_CODE_RANGE),
   MSG_ID_BMC_CODE_RANGE = 100,

   MSG_ID_CSR_CODE_BEGIN = (MSG_ID_BMC_CODE_BEGIN + MSG_ID_BMC_CODE_RANGE),
   MSG_ID_CSR_CODE_RANGE = 100,

   MSG_ID_DRLC_CODE_BEGIN = (MSG_ID_CSR_CODE_BEGIN + MSG_ID_CSR_CODE_RANGE),
   MSG_ID_DRLC_CODE_RANGE = 100,

   MSG_ID_PDCP_CODE_BEGIN = (MSG_ID_DRLC_CODE_BEGIN + MSG_ID_DRLC_CODE_RANGE),
   MSG_ID_PDCP_CODE_RANGE = 100,

   MSG_ID_RABM_CODE_BEGIN = (MSG_ID_PDCP_CODE_BEGIN + MSG_ID_PDCP_CODE_RANGE),
   MSG_ID_RABM_CODE_RANGE = 100,

   MSG_ID_DM_CSCE_CODE_BEGIN = (MSG_ID_RABM_CODE_BEGIN + MSG_ID_RABM_CODE_RANGE),
   MSG_ID_DM_CSCE_CODE_RANGE = 100,

   MSG_ID_DM_GAS_CODE_BEGIN = (MSG_ID_DM_CSCE_CODE_BEGIN + MSG_ID_DM_CSCE_CODE_RANGE),
   MSG_ID_DM_GAS_CODE_RANGE = 200,

   MSG_ID_DM_MEME_CODE_BEGIN = (MSG_ID_DM_GAS_CODE_BEGIN + MSG_ID_DM_GAS_CODE_RANGE),
   MSG_ID_DM_MEME_CODE_RANGE = 100,

   MSG_ID_DM_RRCE_CODE_BEGIN = (MSG_ID_DM_MEME_CODE_BEGIN + MSG_ID_DM_MEME_CODE_RANGE),
   MSG_ID_DM_RRCE_CODE_RANGE = 100,

   MSG_ID_UL1_MSG_CODE_BEGIN = (MSG_ID_DM_RRCE_CODE_BEGIN + MSG_ID_DM_RRCE_CODE_RANGE),
   MSG_ID_UL1_MSG_CODE_RANGE = 200,

   MSG_ID_UL1HISR_MSG_CODE_BEGIN = (MSG_ID_UL1_MSG_CODE_BEGIN + MSG_ID_UL1_MSG_CODE_RANGE),
   MSG_ID_UL1HISR_MSG_CODE_RANGE = 5,

   MSG_ID_UL1C_MSG_CODE_BEGIN = (MSG_ID_UL1HISR_MSG_CODE_BEGIN + MSG_ID_UL1HISR_MSG_CODE_RANGE),
   MSG_ID_UL1C_MSG_CODE_RANGE = 10,

   MSG_ID_LL1_MSG_CODE_BEGIN = (MSG_ID_UL1C_MSG_CODE_BEGIN + MSG_ID_UL1C_MSG_CODE_RANGE),
   MSG_ID_LL1_MSG_CODE_RANGE = 100,

   MSG_ID_UL1TST_MSG_CODE_BEGIN = (MSG_ID_LL1_MSG_CODE_BEGIN + MSG_ID_LL1_MSG_CODE_RANGE),
   MSG_ID_UL1TST_MSG_CODE_RANGE = 50,

   /* Maximum 1000 custom message */
   CUSTOM_MSG_CODE_BEGIN = (MSG_ID_UL1TST_MSG_CODE_BEGIN + MSG_ID_UL1TST_MSG_CODE_RANGE + 1000)
} MSG_ID_CODE_BEGIN;


/*************************************************************************
* Type Definitions
 *************************************************************************/
typedef void (*FSM_FUNCTION) (void*, void*);

typedef enum {
   INVALID_SAP = 0,
/* PS_BEGIN */
   /* NAS */
   /* TBD */
   GMMREG_SAP,
   /* GMM_REG_SAP = GMMREG_SAP, */
   /* GMM_TIMER_SAP, */
   MM_SMS_SAP,
   MM_CC_SAP,
   MM_SS_SAP,
   MM_AS_SAP,
   MM_SIM_SAP,
   GMM_SM_SAP,
   MNCC_SAP,
   MNSMS_SAP,
   MMREG_SAP,
   MNSS_SAP,
   /* L4 */
   CSM_TDT_SAP,
   CSM_L2R_SAP,
   CSM_T30_SAP,
   CSM_SIM_SAP,
   T30_L4C_SAP,
   CSM_L4C_SAP,
   SMSAL_L4C_SAP,
   UEM_L4C_SAP,
   PHB_L4C_SAP,
   SMU_L4C_SAP,
   TCM_L4C_SAP,
   RAC_L4C_SAP,
   UART_L4C_SAP,
   /* RR */
#ifdef __MTK_3G_MRAT_ARCH__
   RRM_LAPDM_SAP,
#else
   RRM_RMPC_SAP,
   RMC_LAPDM_SAP,
   RLC_RMPC_SAP,
   RMPC_MPAL_SAP,
   MAC_RMPC_SAP,
   RR_PRR_SAP,
#endif
   LAPDM_MPAL_SAP,
   RLC_MAC_SAP,
   RLC_RRM_SAP,
   RLC_MPAL_SAP,
   RLC_REASM_SAP,
   MAC_RRM_SAP,
   RRM_MPAL_SAP,
   MAC_MPAL_SAP,
   MMI_AS_SAP,
   SMSAL_AS_SAP,
   /* GPRS */
   LLC_GMM_SAP,
   LLC_RLC_SAP,
   LLC_SNDCP_SAP,
   LLC_SMS_SAP,
   GMM_RLC_SAP,
   SNDCP_REG_SAP,
   SM_SNDCP_SAP,
   SMREG_SAP,
   PPP_L4C_SAP,
   TCM_PPP_SAP,
   /* DATA */
   L2R_RLP_SAP,
   RLP_RA_SAP,
   T30_FA_SAP,
   FA_RA_SAP,
   SNDCP_PPP_SAP,
   DATA_MPAL_SAP,
   L2R_SMU_SAP,

   /* DRIVER */
   PS_NVRAM_SAP,
   PS_SIM_SAP,

   /* VT */
   CSM_VT_SAP,
   VT_CSR_SAP,
   VT_F_CSR_SAP,

   /* Media Task */
   MED_SAP,
   L4_AUD_SAP=MED_SAP,

#if (!defined(MED_V_NOT_PRESENT))
   /* Media-v Task */
   MED_V_SAP,
#endif /* !MED_V_NOT_PRESENT */

#if (!defined(MED_C_NOT_PRESENT))
   /* Media-c Task */
   MED_C_SAP,
#endif /* !MED_C_NOT_PRESENT */

   /* MMI */
   MMI_L4C_SAP,
   ABM_MMI_SAP,
   MMI_ABM_SAP,
   MMI_MMI_SAP,
   MMI_FMT_SAP,
   MMI_WAP_SAP,
   MMI_JASYN_SAP,
   MMI_POC_SAP,
   MMI_SYNCML_SAP,
   SOC_MMI_SAP,

   /*WAP*/
   ABM_SOC_SAP,
   L4C_ABM_SAP,
   TCPIP_SOC_SAP,
   TCPIP_DHCP_SAP,
   WAP_MMI_SAP,
   WPS_APP_SAP,
   TDT_PPP_SAP,
   L2R_PPP_SAP,
   PPP_TCPIP_SAP,
   TCM_TCPIP_SAP,
   SOC_APP_SAP, /* SOCKET to Applications */
   SMSAL_SOC_SAP,
   EM_PS_SAP,

   MMI_J2ME_SAP,
   J2ME_MMI_SAP,
   WAP_J2ME_SAP,
   J2ME_WAP_SAP,
   J2ME_JASYN_SAP,

   EMAIL_MMI_SAP,
   IMPS_MMI_SAP,   
   SIP_APP_SAP,
   POC_MMI_SAP,

   XDM_APP_SAP,
   VOIP_MMI_SAP,
   SAF_APP_SAP,
   RTSP_APP_SAP,

   /* PS Unit Test */
   SME_SAP,
   SME_READER_SAP,
   SME_TIMER_SAP,
   /* PS_END */

   /* IrDA */
   OBEX_APP_SAP,
   IRCOMM_APP_SAP,
   IRDA_OBEX_SAP,
   IRDA_IRCOMM_SAP,   

   /* L1-L2, L1-MPAL */
   L1_MPAL_SAP,
   MPAL_L1_SAP,
   MAC_L1_SAP,
   L1_AS_SAP,
   L1HISR_AS_SAP,
   L1_GAS_SAP,
   L1HISR_GAS_SAP,
   L1_LAPDM_SAP,

   L1_L1_SAP,

   DRIVER_PS_SAP,
   DRIVER_L1_SAP,
   FT_TST_SAP,
   STACK_TIMER_SAP,
   STACK_SIM_TIMER_SAP,
   L4C_CMUX_SAP,
   CMUX_SAP,

   WNDRV_WNDRV_SAP,
   FT_WNDRV_SAP,
   WNDRV_SUPC_SAP,
   WNDRV_TCPIP_SAP,
   WNDRV_MMI_SAP,
   WNDRV_BT_SAP,
   
   SUPC_MMI_SAP,
   SUPC_ABM_SAP,

   DHCP_ABM_SAP,
   DHCP_SIP_SAP,

   IPERF_MMI_SAP,

   TFTP_APP_SAP,

   BCHS_L4C_SAP,
   BCHS_MMI_SAP,
   BT_A2DP_SAP,
   BT_APP_SAP,
   BT_AVRCP_SAP,
   BT_HFG_SAP,
   BT_BPP_SAP,
   BT_BIP_SAP,

   DT_L4C_SAP,

   GDC_SAP,
   GDD_SAP,

   DRMT_APP_SAP,
   DRMT_WAP_SAP,
   DRMT_MMI_SAP,

   GIS_SAP,

   CERTMAN_MMI_SAP,
   CERTMAN_APP_SAP,
   MMI_CERTMAN_APP_SAP,

   TLS_APP_SAP,

   RATCM_RRCE_SAP,
   RATCM_SLCE_SAP,
   RATCM_CSCE_SAP,
   RATCM_CSE_SAP,
   RATCM_USIME_SAP,
   RATCM_CSR_SAP,
   RATCM_BMC_SAP,
   RATCM_URLC_SAP,
   RATCM_LLC_SAP,
   RATCM_GAS_SAP,
   RATCM_RLC_SAP,
   MM_RATCM_SAP,
   SMSAL_RATCM_SAP,
   MM_RATDM_SAP,
   SM_RATDM_SAP,
   TCM_RATDM_SAP,
   RATCM_RATDM_SAP,
   RATDM_RATDM_SAP,
   RATDM_RABM_SAP,
   RATDM_SNDCP_SAP,
   RATDM_URLC_SAP,
   RAC_MEME_SAP,
   UAS_GAS_SAP,
   SLCE_URLC_SAP,
   RRCE_URLC_SAP,
   CSR_DRLC_SAP,
   BMC_DRLC_SAP,
   PDCP_DRLC_SAP,
   PDCP_URLC_SAP,
   RRCE_DRLC_SAP,
   MEME_DRLC_SAP,
   ADR_DRLC_SAP,
   ADR_UL1_SAP,
   DRLC_URLC_SAP,
   DRLC_UMAC_SAP,
   SLCE_PDCP_SAP,
   PDCP_RABM_SAP,
   SLCE_BMC_SAP,
   RRCE_BMC_SAP,
   SLCE_RABM_SAP,
   SLCE_CSR_SAP,
   SLCE_UMAC_SAP,
   RRCE_UMAC_SAP,
   MEME_UMAC_SAP,
   URLC_UMAC_SAP,
   URLC_URLC_SAP,
   CSR_UMAC_SAP,
   RRCE_CSCE_SAP,
   RRCE_MEME_SAP,
   CSCE_MEME_SAP,
   CSE_MEME_SAP,
   CSCE_SLCE_SAP,
   RRCE_SLCE_SAP,
   SIBE_SLCE_SAP,
   SIBE_UL1_SAP,
   MEME_SLCE_SAP,
   CSE_SLCE_SAP,
   SLCE_SLCE_SAP,
   CSCE_CSE_SAP,
   CSCE_SIBE_SAP,
   CSCE_USIME_SAP,
   CSE_SIBE_SAP,
   RRCE_SIBE_SAP,
   MEME_SIBE_SAP,
   RRCE_USIME_SAP,
   SLCE_UL1_SAP,
   MEME_UL1_SAP,
   RRCE_UL1_SAP,
   CSE_UL1_SAP,
   UMAC_UL1_SAP,
   UMAC_UMAC_SAP,
   UL1_L1_SAP,
   GAS_CSCE_SAP, 
   GAS_MEME_SAP,
   GAS_RRCE_SAP,
   CSR_L1AUD_SAP,
   UL1HISR_UL1_SAP,
   UL1C_SAP,
   UL1_UL1_SAP,
   UL1TST_FT_SAP,
   FT_UL1TST_SAP,
   VT_SAP,
   TCPIP_ABM_SAP,

   CUSTOM_SAP_BEGIN,

/*************************************************************************
 * Customer add message sap id here,
 * and maximum allow 10 sap id which limited by MAX_CUSTOM_SAP_ID
 *************************************************************************/

   LAST_SAP_CODE = CUSTOM_SAP_BEGIN + MAX_CUSTOM_SAP_ID 
} sap_type;

#define MOD_PH MOD_MPAL_READER

#endif /* _STACK_COMMON_H */

