/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   tasks_create_func.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains the create function for tasks that defined in syscomp,
 *   (i.e. built-in tasks). Those optional tasks create or not , depend on 
 *   specific feature ON/OFF.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"


/*************************************************************************
* FUNCTION
*  custom_irda_create
*
* DESCRIPTION
*  Customize irda create function.
*  Return KAL_FALSE directly if irda should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_irda_create(comptask_handler_struct **handle)
{
#ifdef __IRDA_SUPPORT__
   return irda_create(handle);
#else
   return KAL_FALSE;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_obex_create
*
* DESCRIPTION
*  Customize obex create function.
*  Return KAL_FALSE directly if obex should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_obex_create(comptask_handler_struct **handle)
{
#if defined(__IRDA_SUPPORT__) && !defined(OBEX_NOT_PRESENT)
   return obex_create(handle);
#else
   return KAL_FALSE;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_ircomm_create
*
* DESCRIPTION
*  Customize ircomm create function.
*  Return KAL_FALSE directly if ircomm should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_ircomm_create(comptask_handler_struct **handle)
{
#if defined(__IRDA_SUPPORT__) && !defined(IRCOMM_NOT_PRESENT)
   return ircomm_create(handle);
#else
   return KAL_FALSE;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_usb_create
*
* DESCRIPTION
*  Customize usb create function.
*  Return KAL_FALSE directly if usb should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_usb_create(comptask_handler_struct **handle)
{
#ifdef __USB_ENABLE__
   return usb_create(handle);
#else
   return KAL_FALSE;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_abm_create
*
* DESCRIPTION
*  Customize ABM create function.
*  Return KAL_FALSE directly if ABM should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_abm_create(comptask_handler_struct **handle)
{
#ifdef ABM_NOT_PRESENT
   return KAL_FALSE;
#else
   return abm_create(handle);
#endif /* ABM_NOT_PRESENT */
}

/*************************************************************************
* FUNCTION
*  custom_ppp_create
*
* DESCRIPTION
*  Customize PPP create function.
*  Return KAL_FALSE directly if PPP should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_ppp_create(comptask_handler_struct **handle)
{
#ifdef PPP_NOT_PRESENT
   return KAL_FALSE;
#else
   return ppp_create(handle);
#endif /* PPP_NOT_PRESENT */
}

/*************************************************************************
* FUNCTION
*  custom_tcpip_create
*
* DESCRIPTION
*  Customize TCPIP create function.
*  Return KAL_FALSE directly if TCPIP should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_tcpip_create(comptask_handler_struct **handle)
{
#ifdef TCPIP_NOT_PRESENT
   return KAL_FALSE;
#else
   return tcpip_create(handle);
#endif /* TCPIP_NOT_PRESENT */
}

/*************************************************************************
* FUNCTION
*  custom_socket_create
*
* DESCRIPTION
*  Customize SOCKET create function.
*  Return KAL_FALSE directly if SOCKET should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_socket_create(comptask_handler_struct **handle)
{
#ifdef SOC_NOT_PRESENT
   return KAL_FALSE;
#else
   return socket_create(handle);
#endif /* SOC_NOT_PRESENT */
}

/*************************************************************************
* FUNCTION
*  custom_wap_create
*
* DESCRIPTION
*  Customize WAP create function.
*  Return KAL_FALSE directly if WAP should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_wap_create(comptask_handler_struct **handle)
{
#ifdef WAP_NOT_PRESENT
   return KAL_FALSE;
#else
   return wap_create(handle);
#endif /* WAP_NOT_PRESENT */
}

/*************************************************************************
* FUNCTION
*  custom_wps_create
*
* DESCRIPTION
*  Customize WPS create function.
*  Return KAL_FALSE directly if WPS should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_wps_create(comptask_handler_struct **handle)
{
#ifdef WPS_NOT_PRESENT
   return KAL_FALSE;
#else
#if !defined(WIN32)
   return wps_create(handle);
#else
   return 0 ;
#endif
#endif /* WAP_NOT_PRESENT */
}

/*************************************************************************
* FUNCTION
*  custom_jam_create
*
* DESCRIPTION
*  Customize JAM create function.
*  Return KAL_FALSE directly if JAM should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_jvm_create(comptask_handler_struct **handle)
{
#ifdef __J2ME__
   return jvm_create(handle);
#else
   return KAL_FALSE;
#endif /*  __J2ME__ */
}

/*************************************************************************
* FUNCTION
*  custom_jdaemon_create
*
* DESCRIPTION
*  Customize JASYN create function.
*  Return KAL_FALSE directly if JASYN should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_jdaemon_create(comptask_handler_struct **handle)
{
#ifdef __J2ME__
   return jdaemon_create(handle);
#else
   return KAL_FALSE;
#endif /*  __J2ME__ */
}

/*************************************************************************
* FUNCTION
*  custom_email_create
*
* DESCRIPTION
*  Customize email create function.
*  Return KAL_FALSE directly if email should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_email_create(comptask_handler_struct **handle)
{
#ifdef __EMAIL__
   return email_create(handle);
#else
   return KAL_FALSE;
#endif /*  __EMAIL__ */
}

/*************************************************************************
* FUNCTION
*  custom_imps_create
*
* DESCRIPTION
*  Customize IMPS create function.
*  Return KAL_FALSE directly if IMPS should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_imps_create(comptask_handler_struct **handle)
{
#ifdef __IMPS__
   return imps_create(handle);
#else
   return KAL_FALSE;
#endif /* __IMPS__ */
}

/*************************************************************************
* FUNCTION
*  custom_sip_create
*
* DESCRIPTION
*  Customize SIP create function.
*  Return KAL_FALSE directly if SIP should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_sip_create(comptask_handler_struct **handle)
{
#ifdef __SIP__
   return sip_create(handle);
#else
   return KAL_FALSE;
#endif /*  __SIP__ */
}

/*************************************************************************
* FUNCTION
*  custom_poc_create
*
* DESCRIPTION
*  Customize POC create function.
*  Return KAL_FALSE directly if POC should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_poc_create(comptask_handler_struct **handle)
{
#ifdef __POC__
   return poc_create(handle);
#else
   return KAL_FALSE;
#endif /*  __POC__ */
}

/*************************************************************************
* FUNCTION
*  custom_tp_task_create
*
* DESCRIPTION
*  Customize touch-panel task create function.
*  Return KAL_FALSE directly if touch-panel task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_tp_task_create(comptask_handler_struct **handle)
{
#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
   return tp_task_create(handle);
#else /* TOUCH_PANEL_SUPPORT || HAND_WRITING */
   return KAL_FALSE;
#endif /*  TOUCH_PANEL_SUPPORT || HAND_WRITING */
}

/*************************************************************************
* FUNCTION
*  custom_xdm_create
*
* DESCRIPTION
*  Customize XDM task create function.
*  Return KAL_FALSE directly if XDM task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_xdm_create(comptask_handler_struct **handle)
{
#if defined(__XDM__)
   return xdm_create(handle);
#else /* __XDM__ */
   return KAL_FALSE;
#endif /* __XDM__ */
}

/*************************************************************************
* FUNCTION
*  custom_bt_create
*
* DESCRIPTION
*  Customize BT task create function.
*  Return KAL_FALSE directly if BT task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_bt_create(comptask_handler_struct **handle)
{
#if defined(__BTMTK__)
   return bt_create(handle);
#else /* __BTMTK__ */
   return KAL_FALSE;
#endif /* __BTMTK__ */
}

/*************************************************************************
* FUNCTION
*  custom_wndrv_create
*
* DESCRIPTION
*  Customize WNDRV task create function.
*  Return KAL_FALSE directly if WNDRV task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_wndrv_create(comptask_handler_struct **handle)
{
#if defined(__WIFI_SUPPORT__)
   return wndrv_create(handle);
#else /* __WIFI_SUPPORT__ */
   return KAL_FALSE;
#endif /* __WIFI_SUPPORT__ */
}

/*************************************************************************
* FUNCTION
*  custom_supc_create
*
* DESCRIPTION
*  Customize SUPC task create function.
*  Return KAL_FALSE directly if SUPC task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_supc_create(comptask_handler_struct **handle)
{
#if defined(__WIFI_SUPPORT__)
   return supc_create(handle);
#else /* __WIFI_SUPPORT__ */
   return KAL_FALSE;
#endif /* __WIFI_SUPPORT__ */
}

/*************************************************************************
* FUNCTION
*  custom_idlerecl_create
*
* DESCRIPTION
*  Customize idle reclaim task create function.
*  Unlike others, the compile option is defined at custom_memorydevice.h
*  Return KAL_FALSE directly if SUPC task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_idlerecl_create(comptask_handler_struct **handle)
{
#if defined(__NOR_FDM5__) && defined(__MTK_TARGET__)
   return idlerecl_create(handle);
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MTK_TARGET__)
   return idle_recl_create(handle);
#else /* __NOR_FDM5__ */
   return KAL_FALSE;
#endif /* __NOR_FDM5__ && __MTK_TARGET__ */
}

/*************************************************************************
* FUNCTION
*  custom_syncml_create
*
* DESCRIPTION
*  Customize SYNCML task create function.
*  Return KAL_FALSE directly if SYNCML task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_syncml_create(comptask_handler_struct **handle)
{
#if defined(__SYNCML_SUPPORT__)
   return syncml_create(handle);
#else /* __SYNCML_SUPPORT__ */
   return KAL_FALSE;
#endif /* __SYNCML_SUPPORT__ */
}

/*************************************************************************
* FUNCTION
*  custom_dhcp_create
*
* DESCRIPTION
*  Customize DHCP task create function.
*  Return KAL_FALSE directly if DHCP task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_dhcp_create(comptask_handler_struct **handle)
{
#ifdef __WIFI_SUPPORT__
   return dhcp_create(handle);
#else /* !__WIFI_SUPPORT__ */
   return KAL_FALSE;
#endif /* !__WIFI_SUPPORT__ */
}

/*************************************************************************
* FUNCTION
*  custom_tftp_create
*
* DESCRIPTION
*  Customize TFTP task create function.
*  Return KAL_FALSE directly if TFTP task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_tftp_create(comptask_handler_struct **handle)
{
#ifdef __TFTP__
   return tftp_create(handle);
#else /* !__TFTP__ */
   return KAL_FALSE;
#endif /* !__TFTP__ */
}


/*************************************************************************
* FUNCTION
*  custom_saf_create
*
* DESCRIPTION
*  Customize SAF create function.
*  Return KAL_FALSE directly if SAF should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_saf_create(comptask_handler_struct **handle)
{
#ifdef __SAF__
   return saf_create(handle);
#else
   return KAL_FALSE;
#endif /*  __SAF__ */
}

/*************************************************************************
* FUNCTION
*  custom_voip_create
*
* DESCRIPTION
*  Customize VOIP create function.
*  Return KAL_FALSE directly if VOIP should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_voip_create(comptask_handler_struct **handle)
{
#ifdef __VOIP__
   return voip_create(handle);
#else
   return KAL_FALSE;
#endif /*  __VOIP__ */
}

/*************************************************************************
* FUNCTION
*  custom_rtsp_create
*
* DESCRIPTION
*  Customize RTSP create function.
*  Return KAL_FALSE directly if RTSP should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_rtsp_create(comptask_handler_struct **handle)
{
#ifdef __RTSP__
   return rtsp_create(handle);
#else
   return KAL_FALSE;
#endif /*  __RTSP__ */
}

/*************************************************************************
* FUNCTION
*  custom_dm_create
*
* DESCRIPTION
*  Customize DM create function.
*  Return KAL_FALSE directly if DM should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_dm_create(comptask_handler_struct **handle)
{
#ifdef SYNCML_DM_SUPPORT
   return dm_create(handle);
#else
   return KAL_FALSE;
#endif /*  SYNCML_DM_SUPPORT */
}

/*************************************************************************
* FUNCTION
*  custom_tdmb_create
*
* DESCRIPTION
*  Customize tdmb create function.
*  Return KAL_FALSE directly if irda should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_tdmb_create(comptask_handler_struct **handle)
{
#ifdef __TDMB_SUPPORT__
   return tdmb_task_create(handle);
#else
   return KAL_FALSE;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_vt_create
*
* DESCRIPTION
*  Customize VT create function.
*  Return KAL_FALSE directly if VT should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_vt_create(comptask_handler_struct **handle)
{
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#else   /* __3G_VIDEO_CALL__ */
   return KAL_FALSE;
#endif /*  __3G_VIDEO_CALL__ */
}


/*****************************************************************************
 * FUNCTION
 *  custom_certman_create
 * DESCRIPTION
 *  Customize CERTMAN task create function.
 *  Return KAL_FALSE directly if CERTMAN task should not be created.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_bool custom_certman_create(comptask_handler_struct **handle)
{
#ifdef __CERTMAN_SUPPORT__
   return certman_create(handle);
#else
   return KAL_FALSE;
#endif /*  __CERTMAN_SUPPORT__ */
}


/*************************************************************************
* FUNCTION
*  custom_tls_create
*
* DESCRIPTION
*  Customize TLS task create function.
*  Return KAL_FALSE directly if TLS task should not be created.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_tls_create(comptask_handler_struct **handle)
{
#ifdef __SSL_SUPPORT__
   return tls_create(handle);
#else /* !__SSL_SUPPORT__ */
   return KAL_FALSE;
#endif /* !__SSL_SUPPORT__ */
}

