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
 *   system_inc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains declaration of system-related functions which can be
 *   customized.
 *
 * Author:
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef _SYSTEM_INC_H
#define _SYSTEM_INC_H

/*************************************************************************
 * External function declaration
 *************************************************************************/
#ifdef __IRDA_SUPPORT__

extern kal_bool irda_create(comptask_handler_struct **handle); 

extern kal_bool dummy_irda_ap_create(comptask_handler_struct **handle);

#ifndef OBEX_NOT_PRESENT
extern kal_bool obex_create(comptask_handler_struct **handle);
#endif /* OBEX_NOT_PRESENT */ 

#ifndef IRCOMM_NOT_PRESENT
extern kal_bool ircomm_create(comptask_handler_struct **handle);
#endif /* IRCOMM_NOT_PRESENT */ 

#endif /* __IRDA_SUPPORT__ */

#ifdef __USB_ENABLE__
extern kal_bool usb_create(comptask_handler_struct **handle);
#endif	/* __USB_ENABLE__ */

#ifndef ABM_NOT_PRESENT
extern kal_bool abm_create(comptask_handler_struct **handle);
#endif	/* #ifndef ABM_NOT_PRESENT */

#ifndef PPP_NOT_PRESENT
extern kal_bool ppp_create(comptask_handler_struct **handle);
#endif	/* #ifndef PPP_NOT_PRESENT */

#ifndef TCPIP_NOT_PRESENT
extern kal_bool tcpip_create(comptask_handler_struct **handle);
#endif	/* #ifndef TCPIP_NOT_PRESENT */

#ifndef SOC_NOT_PRESENT
extern kal_bool socket_create(comptask_handler_struct **handle);
#endif	/* #ifndef SOC_NOT_PRESENT */

#ifndef WAP_NOT_PRESENT
extern kal_bool wap_create(comptask_handler_struct **handle);
#if !defined(WIN32)
extern kal_bool wps_create(comptask_handler_struct **handle);
#endif

#endif	/* #ifndef WAP_NOT_PRESENT */

#ifdef __J2ME__
extern kal_bool jvm_create(comptask_handler_struct **handle);
extern kal_bool jdaemon_create(comptask_handler_struct **handle);
#endif	/* #ifdef __J2ME__ */

#ifdef __EMAIL__
extern kal_bool email_create(comptask_handler_struct **handle);
#endif	/* #ifdef __EMAIL__ */

#ifdef __IMPS__
extern kal_bool imps_create(comptask_handler_struct **handle);
#endif	/* #ifdef __IMPS__ */

#ifdef __SIP__
extern kal_bool sip_create(comptask_handler_struct **handle);
#endif	/* #ifdef __SIP__ */

#ifdef __POC__
extern kal_bool poc_create(comptask_handler_struct **handle);
#endif	/* #ifdef __POC__ */

#ifdef TOUCH_PANEL_SUPPORT
extern kal_bool tp_task_create(comptask_handler_struct **handle);
#endif   /* TOUCH_PANEL_SUPPORT */

#ifdef __BTMTK__
extern kal_bool bt_create(comptask_handler_struct **handle);
#endif   /* __BTMTK__ */

#ifdef __XDM__
extern kal_bool xdm_create(comptask_handler_struct **handle);
#endif	/* #ifdef __XDM__ */

#ifdef __WIFI_SUPPORT__
extern kal_bool wndrv_create(comptask_handler_struct **handle);
extern kal_bool supc_create(comptask_handler_struct **handle);
extern kal_bool dummy_supc_create(comptask_handler_struct **handle);
extern kal_bool dhcp_task_create(comptask_handler_struct **handle);
#endif /* __WIFI_SUPPORT__ */

#ifdef __TFTP__
extern kal_bool tftp_task_create(comptask_handler_struct **handle);
#endif /* __TFTP__ */

#ifdef __SAF__
extern kal_bool saf_create(comptask_handler_struct **handle);
#endif	/* #ifdef __SAF__ */

#ifdef __VOIP__
extern kal_bool voip_create(comptask_handler_struct **handle);
#endif	/* #ifdef __VOIP__ */

#ifdef __SYNCML_SUPPORT__
extern kal_bool syncml_create(comptask_handler_struct **handle);
#endif  /* __SYNCML_SUPPORT__ */

#ifdef __RTSP__
extern kal_bool rtsp_create(comptask_handler_struct **handle);
#endif  /* __RTSP__ */

#ifdef SYNCML_DM_SUPPORT
extern kal_bool dm_create(comptask_handler_struct **handle);
#endif /* SYNCML_DM_SUPPORT */

#ifdef __3G_VIDEO_CALL__       
/* under construction !*/
#endif  /* __3G_VIDEO_CALL__ */

#ifdef __CERTMAN_SUPPORT__
extern kal_bool certman_create(comptask_handler_struct **handle);
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __SSL_SUPPORT__
extern kal_bool tls_create(comptask_handler_struct **handle);
#endif /* __SSL_SUPPORT__ */

/*************************************************************************
 * External global variable declaration
 *************************************************************************/
extern task_indx_type mod_task_g[RPS_TOTAL_STACK_MODULES];

/*************************************************************************
 * Customized functions' prototype
 *************************************************************************/
extern void custom_config_mod_task_g(void);
extern void custom_configmem(kal_uint32 *system_mem_sz, kal_uint32** system_mem_addr, kal_uint32 *debug_mem_sz, kal_uint32** debug_mem_addr);
extern void custom_config_ctrl_buff_info(void);
extern void customization_check(void);
extern kal_uint32 custom_config_task_stack_size(task_indx_type task_indx);
extern kal_uint32 custom_config_task_extq_size(task_indx_type task_indx);
extern kal_bool custom_irda_create(comptask_handler_struct **handle);
extern kal_bool custom_dummy_irda_ap_create(comptask_handler_struct **handle);
extern kal_bool custom_obex_create(comptask_handler_struct **handle);
extern kal_bool custom_ircomm_create(comptask_handler_struct **handle);
extern kal_bool custom_usb_create(comptask_handler_struct **handle);
extern kal_bool custom_abm_create(comptask_handler_struct **handle);
extern kal_bool custom_ppp_create(comptask_handler_struct **handle);
extern kal_bool custom_tcpip_create(comptask_handler_struct **handle);
extern kal_bool custom_socket_create(comptask_handler_struct **handle);
extern kal_bool custom_wap_create(comptask_handler_struct **handle);
extern kal_bool custom_wps_create(comptask_handler_struct **handle);
extern kal_bool custom_imps_create(comptask_handler_struct **handle);
extern kal_bool custom_jvm_create(comptask_handler_struct **handle);
extern kal_bool custom_jdaemon_create(comptask_handler_struct **handle);
extern kal_bool custom_email_create(comptask_handler_struct **handle);
extern kal_bool custom_sip_create(comptask_handler_struct **handle);
extern kal_bool custom_poc_create(comptask_handler_struct **handle);
extern kal_bool custom_tp_task_create(comptask_handler_struct **handle);
extern kal_bool custom_bchs_create(comptask_handler_struct **handle);
extern kal_bool custom_xdm_create(comptask_handler_struct **handle);
extern kal_bool custom_bt_create(comptask_handler_struct **handle);
extern kal_bool custom_wndrv_create(comptask_handler_struct **handle);
extern kal_bool custom_supc_create(comptask_handler_struct **handle);
extern kal_bool custom_dummy_supc_create(comptask_handler_struct **handle);
extern kal_bool custom_dhcp_create(comptask_handler_struct **handle);
extern kal_bool custom_idlerecl_create(comptask_handler_struct **handle);
extern kal_bool custom_tftp_create(comptask_handler_struct **handle);
extern kal_bool custom_saf_create(comptask_handler_struct **handle);
extern kal_bool custom_voip_create(comptask_handler_struct **handle);
extern kal_bool custom_syncml_create(comptask_handler_struct **handle);
extern kal_bool custom_rtsp_create(comptask_handler_struct **handle);
extern kal_bool custom_dm_create(comptask_handler_struct **handle);
extern kal_bool custom_tdmb_create(comptask_handler_struct **handle);
extern kal_bool custom_vt_create(comptask_handler_struct **handle);
extern kal_bool custom_certman_create(comptask_handler_struct **handle);
extern kal_bool custom_tls_create(comptask_handler_struct **handle);

#endif	/* _SYSTEM_INC_H */

