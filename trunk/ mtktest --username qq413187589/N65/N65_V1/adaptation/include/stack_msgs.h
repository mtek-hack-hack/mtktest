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
 *   stack_msgs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides a template for header files. This space
 *   should be used to describe the file contents
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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

#ifndef _STACK_MSGS_H
#define _STACK_MSGS_H

/*************************************************************************
 * Type Definitions
 *************************************************************************/

typedef enum {
   MSG_ID_INVALID_TYPE = 0,

#if defined(__MTK_TARGET__) || defined(KAL_ON_NUCLEUS) || defined (MTK_KAL_MNT) || defined (KAL_ON_OSCAR) || defined(KAL_ON_THREADX)

#ifndef __L1_STANDALONE__

   #include "mm_sap.h"
   MSG_ID_MM_CODE_CHECK_POINT,

   #include "cc_sap.h"
   MSG_ID_CC_CODE_CHECK_POINT,

   #include "dt_sap.h"
   MSG_ID_DT_CODE_CHECK_POINT,

   #include "ciss_sap.h"
   MSG_ID_CISS_CODE_CHECK_POINT,

   #include "sms_sap.h"
   MSG_ID_SMS_CODE_CHECK_POINT,

   #include "sim_sap.h"
   MSG_ID_SIM_CODE_CHECK_POINT,

   #include "l4_sap.h"
   MSG_ID_L4_CODE_CHECK_POINT,

   #include "mmi_sap.h"
   MSG_ID_MMI_CODE_CHECK_POINT,

   #include "rr_sap.h"
   MSG_ID_RR_CODE_CHECK_POINT,

   #include "llc_sap.h"
   MSG_ID_LLC_CODE_CHECK_POINT,

   #include "sndcp_sap.h"
   MSG_ID_SND_CODE_CHECK_POINT,

   #include "sm_sap.h"
   MSG_ID_SM_CODE_CHECK_POINT,

   #include "ppp_sap.h"
   MSG_ID_PPP_CODE_CHECK_POINT,

   #include "data_sap.h"
   MSG_ID_DATA_CODE_CHECK_POINT,

   #include "mmiapi_sap.h"
   MSG_ID_MMIAPI_CODE_CHECK_POINT,

   #include "med_sap.h"
   MSG_ID_MED_CODE_CHECK_POINT,

#ifdef __3G_VIDEO_CALL__       
/* under construction !*/
/* under construction !*/
#endif   /* __3G_VIDEO_CALL__ */

   #include "abm_sap.h"
   MSG_ID_ABM_CODE_CHECK_POINT,

   #include "soc_sap.h"
   MSG_ID_SOC_CODE_CHECK_POINT,

   #include "tcpip_sap.h"
   MSG_ID_TCPIP_CODE_CHECK_POINT,

   #include "wap_sap.h"  
   MSG_ID_WAP_CODE_CHECK_POINT,

   #include "em_sap.h"
   MSG_ID_EM_CODE_CHECK_POINT,

   #include "irda_sap.h"
   MSG_ID_IRDA_CODE_CHECK_POINT,

   #include "obex_sap.h"
   MSG_ID_OBEX_CODE_CHECK_POINT,

   #include "ircomm_sap.h"
   MSG_ID_IRCOMM_CODE_CHECK_POINT,

#ifndef MED_V_NOT_PRESENT
   #include "med_v_sap.h"
   MSG_ID_MED_V_CODE_CHECK_POINT,
#endif /* !MED_V_NOT_PRESENT */

   #include "j2me_sap.h"
   MSG_ID_J2ME_CODE_CHECK_POINT,

   #include "email_sap.h"
   MSG_ID_EMAIL_CODE_CHECK_POINT,

#if ( !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
   #include "fmt_sap.h"
   MSG_ID_FMT_CODE_CHECK_POINT,
#endif /* !FMT_NOT_PRESENT */

#endif /* !__L1_STANDALONE__ */

   #include "drv_sap.h"
   MSG_ID_DRV_CODE_CHECK_POINT,

   #include "nvram_sap.h"
   MSG_ID_NVRAM_CODE_CHECK_POINT,
   
#endif /* __MTK_TARGET__ || KAL_ON_THREADX || MTK_KAL_MNT || KAL_ON_OSCAR */

#ifdef DUMMY_PROTOCOL
#ifdef __GSM_RAT__
   #include "dps_sap.h"
   MSG_ID_DPS_CODE_CHECK_POINT,
#endif   /* __GSM_RAT__ */
   
#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
#endif   /* __WCDMA_RAT__ */
#endif /* DUMMY_PROTOCOL */

   #include "l1_sap.h"
   MSG_ID_L1_CODE_CHECK_POINT,

   #include "l1hisr_sap.h"
   MSG_ID_L1HISR_CODE_CHECK_POINT,

   #include "ft_sap.h"
   MSG_ID_FT_CODE_CHECK_POINT,

#if defined(__MTK_TARGET__) || defined(KAL_ON_NUCLEUS) || defined (MTK_KAL_MNT) || defined (KAL_ON_OSCAR) || defined(KAL_ON_THREADX)

   #include "tstsap.h"
   MSG_ID_TST_CODE_CHECK_POINT,
  
#endif  /* __MTK_TARGET__ || KAL_ON_NUCLEUS || MTK_KAL_MNT || KAL_ON_OSCAR || KAL_ON_THREADX */
  
   #include "sysservice_sap.h"
   MSG_ID_SYSSERVICE_CODE_CHECK_POINT,
   
#if defined(__MTK_TARGET__) || defined(KAL_ON_NUCLEUS) || defined (MTK_KAL_MNT) || defined (KAL_ON_OSCAR) || defined(KAL_ON_THREADX)
   
   #include "cmux_sap.h"
   MSG_ID_CMUX_CODE_CHECK_POINT,
   
   #include "imps_sap.h"
   MSG_ID_IMPS_CODE_CHECK_POINT,
   
   #include "sip_sap.h"
   MSG_ID_SIP_CODE_CHECK_POINT,

   #include "poc_sap.h"
   MSG_ID_POC_CODE_CHECK_POINT,
  
   #include "bluetooth_sap.h"
   MSG_ID_BT_CODE_CHECK_POINT,
   
   #include "xdm_sap.h"
   MSG_ID_XDM_CODE_CHECK_POINT,
   
   #include "wndrv_sap.h"
   MSG_ID_WNDRV_CODE_CHECK_POINT,
   
   #include "supc_sap.h"
   MSG_ID_SUPC_CODE_CHECK_POINT,

   #include "dhcp_sap.h"
   MSG_ID_DHCP_CODE_CHECK_POINT,

   #include "iperf_sap.h"
   MSG_ID_IPERF_CODE_CHECK_POINT,

   #include "tftp_sap.h"
   MSG_ID_TFTP_CODE_CHECK_POINT,
   
   #include "saf_sap.h"
   MSG_ID_SAF_CODE_CHECK_POINT,
   
   #include "voip_sap.h"
   MSG_ID_VOIP_CODE_CHECK_POINT,

   #include "uart_sim_sap.h"
   MSG_ID_VUART_CODE_CHECK_POINT,

#ifndef MED_C_NOT_PRESENT
   #include "med_c_sap.h"
   MSG_ID_MED_C_CODE_CHECK_POINT,
#endif /* !MED_C_NOT_PRESENT */

   #include "syncml_sap.h"
   MSG_ID_SYNCML_CODE_CHECK_POINT,

   #include "rtsp_sap.h"
   MSG_ID_RTSP_CODE_CHECK_POINT,

   #include "mexe_sap.h"
   MSG_ID_MEXE_CODE_CHECK_POINT,

   #include "dm_sap.h"
   MSG_ID_DM_CODE_CHECK_POINT,

#ifdef __DRM_SUPPORT__
   #include "drmt_sap.h"
   MSG_ID_DRMT_CODE_CHECK_POINT,
#endif /* __DRM_SUPPORT__ */

   #include "gis_sap.h"
   MSG_ID_GIS_CODE_CHECK_POINT,

#ifdef __CERTMAN_SUPPORT__
   #include "certman_sap.h"
   MSG_ID_CERTMAN_CODE_CHECK_POINT,

   #include "CertManMMI_sap.h"
   MSG_ID_MMI_CERTMAN_CODE_CHECK_POINT,
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __SSL_SUPPORT__
   #include "tls_sap.h"
   MSG_ID_TLS_CODE_CHECK_POINT,
#endif /* __SSL_SUPPORT__ */

#endif /* __MTK_TARGET__ || KAL_ON_NUCLEUS || MTK_KAL_MNT || KAL_ON_OSCAR || KAL_ON_THREADX */

   #include "ratcm_sap.h"
   MSG_ID_RATCM_CODE_CHECK_POINT,

   #include "ratdm_sap.h"
   MSG_ID_RATDM_CODE_CHECK_POINT,

#ifdef  __WCDMA_RAT__
/* under construction !*/
#ifndef __L1_STANDALONE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	/* !__L1_STANDALONE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __WCDMA_RAT__ */

#if defined(__MTK_TARGET__) || defined(KAL_ON_NUCLEUS) || defined (MTK_KAL_MNT) || defined (KAL_ON_OSCAR) || defined(KAL_ON_THREADX)

/*************************************************************************
 * Custom to add message id here, and maximum allow 1000 messages which 
 * limited by END_MSG_CODE_BEGIN 
 *************************************************************************/
   #include "custom_sap.h"   
   
#endif /* __MTK_TARGET__ || KAL_ON_NUCLEUS || MTK_KAL_MNT || KAL_ON_OSCAR || KAL_ON_THREADX */

MSG_ID_END
} msg_type;

/*************************************************************************
 * Macros With Parameters
 *************************************************************************/

#ifndef __L1_STANDALONE__
   #define MSG_ID_MMI_MESSAGE_SUM  (MSG_ID_L4A_CODE_END -   MSG_ID_L4A_CODE_BEGIN)
#endif /* !__L1_STANDALONE__ */

#endif /* _STACK_MSGS_H */

