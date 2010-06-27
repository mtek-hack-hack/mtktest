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
 *    drv_sap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for SAP of driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

/*UART*/
MSG_ID_UART_READY_TO_READ_IND = DRIVER_MSG_CODE_BEGIN,
MSG_ID_UART_READY_TO_WRITE_IND,
MSG_ID_UART_DSR_CHANGE_IND,
MSG_ID_UART_ESCAPE_DETECTED_IND,
MSG_ID_UART_PLUGIN_IND,
MSG_ID_UART_PLUGOUT_IND,
/*BMT*/
MSG_ID_BMT_CHARGER_IND,
MSG_ID_BMT_ADC_DATA_REQ,
MSG_ID_BMT_ADC_DATA_CONF,
MSG_ID_BMT_LEAVE_PRECHARGE_IND,

MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
MSG_ID_BMT_ADC_ADD_ITEM_REQ,
MSG_ID_BMT_ADC_REMOVE_ITEM_REQ,
MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,

/*AUX*/
MSG_ID_AUX_PLUGIN,
MSG_ID_AUX_PLUGOUT,
MSG_ID_AUX_DETECT,   /*old*/
MSG_ID_AUX_CALL_SETUP_REQ_IND, 
MSG_ID_AUX_CALL_CONNECT_REQ_IND,
MSG_ID_AUX_CALL_DISCONNECT_REQ_IND,
MSG_ID_AUX_ID,
MSG_ID_READ_ALL_ADC_CHANNEL_REQ,
MSG_ID_ADC_ALL_CHANNEL_CONF,

/*USB*/
MSG_ID_USB_A_PLUGIN_IND,
MSG_ID_USB_A_PLUGOUT_IND,
MSG_ID_USB_B_PLUGIN_IND,
MSG_ID_USB_B_PLUGOUT_IND,
MSG_ID_DRVUEM_USBCFG_REQ,
MSG_ID_DRVUEM_USBCFG_CNF,
MSG_ID_USBD_START_HNP,
MSG_ID_SRP_INIT,
MSG_ID_OTG_DISPLAY_IND,
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
MSG_ID_USB_MSDRV_RESET_IND,				/* mass storage messages */
MSG_ID_USB_MSDRV_REC_DONE_CONF,
MSG_ID_USB_MSDRV_TRX_DONE_CONF,
MSG_ID_USB_MSDRV_CLEAR_STALL_REQ,
MSG_ID_USB_MSHOST_START_IND,
MSG_ID_USB_MSHOST_QUERY_IND,
MSG_ID_OTG_MS_INSERT_IND,
MSG_ID_OTG_MS_REMOVE_IND,
MSG_ID_OTG_CARD_DETECT_IND,
MSG_ID_OTG_HDLR_IND,
MSG_ID_USB_FT_IND,					/* CDC ACM factory mode messages */
MSG_ID_USB_FT_START_REQ,
MSG_ID_USB_FT_TX_DONE_IND,
MSG_ID_USB_FT_RX_DATA_IND,
MSG_ID_USB_IRDGB_START_IND,                     /* IRDBG */          

/*USB video and media msg */
MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ,
MSG_ID_USB_MED_SET_CAMERA_ATTR_CNF,
MSG_ID_MED_USB_START_VIDEO_REQ, 
MSG_ID_USB_MED_START_VIDEO_CNF,
MSG_ID_USB_MED_CHANGE_VIDEO_IND,
MSG_ID_USB_MED_START_STILL_IND,
MSG_ID_USB_MED_START_VIDEO_IND,
MSG_ID_MED_USB_DEVICE_STILL_REQ,
MSG_ID_USB_MED_DEVICE_STILL_CNF,
MSG_ID_MED_USB_PAUSE_REQ,
MSG_ID_USB_MED_PAUSE_CNF,
MSG_ID_MED_USB_RESUME_VIDEO_REQ,
MSG_ID_USB_MED_RESUME_VIDEO_CNF,
MSG_ID_USB_MED_STOP_IND,
MSG_ID_USB_MED_ABORT_IND,
MSG_ID_MED_USB_STOP_REQ,
MSG_ID_USB_MED_STOP_CNF,

/*USB video internal msg */
MSG_ID_USB_ENUM_DONE,
MSG_ID_USB_VIDEO_COMPLETE,
MSG_ID_USB_VIDEO_DMA_DONE,
MSG_ID_USB_VIDEO_CHANGE_SIZE,
MSG_ID_USB_STILL_CAPTURE,
MSG_ID_USB_STILL_COMPLETE,
MSG_ID_USB_VIDEO_STILL_DMA_DONE,
MSG_ID_USB_VIDEO_STILL_DMA_PARTIAL,
MSG_ID_USB_VIDEO_INCALL_DMA_DONE,
MSG_ID_USB_VIDEO_INCALL_TIMEOUT,
MSG_ID_USB_VIDEO_INCALL_CHANGE_SIZE,
MSG_ID_USB_VIDEO_ABORT,

/* msgs between USB and MMI */
MSG_ID_USB_MMI_DPS_DISCOVERY_IND,
MSG_ID_USB_MMI_DPS_HREQUEST_IND,
MSG_ID_MMI_USB_DPS_HREQUEST_CONF,
MSG_ID_USB_MMI_DPS_HRESPONSE_IND,
MSG_ID_MMI_USB_DPS_HRESPONSE_CONF,
MSG_ID_MMI_USB_DPS_DREQUEST_REQ,
MSG_ID_USB_MMI_DPS_DREQUEST_CONF,
MSG_ID_MMI_USB_DPS_DRESPONSE_REQ,
MSG_ID_USB_MMI_DPS_DRESPONSE_CONF,
MSG_ID_USB_MMI_PTP_CONNECT_TO_PC_IND,
MSG_ID_USB_MMI_PTP_OPEN_FILE_FAIL_IND,
MSG_ID_USB_MMI_PTP_HOST_RESET_IND,
MSG_ID_MMI_USB_PTP_HOST_RESET_CNF,
MSG_ID_MMI_USB_START_JOB_REQ,
MSG_ID_MMI_USB_CLOSE_JOB_REQ,

/* USB image internal msg */
MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF,
MSG_ID_USB_PTPIMAGE_DMA_TX_DONE_CONF,
MSG_ID_USB_PTPIMAGE_RESET_IND,

/*MSDC*/
MSG_ID_MSDC_CARD_DETECT_IND,
MSG_ID_SIM_PLUS_DETECT_IND,
MSG_ID_MSDC2_CARD_DETECT_IND,

/*USB charging*/
MSG_ID_BMT_USB_IND,
MSG_ID_BMT_USB_READ_CALI_DONE_IND,

/*touch panel*/
MSG_ID_TP_EVENT_IND,
MSG_ID_TP_CALI_DONE,
MSG_ID_TP_PEN_DOWN_IND,

/*TDMB*/
MSG_ID_TDMB_TURN_ON_REQUEST, MSG_ID_TDMB_CODE_BEGIN = MSG_ID_TDMB_TURN_ON_REQUEST,
MSG_ID_TDMB_TURN_ON_CONFIRM,
MSG_ID_TDMB_TURN_OFF_REQUEST,
MSG_ID_TDMB_TURN_OFF_CONFIRM,
MSG_ID_TDMB_SET_BAND_REQUEST,
MSG_ID_TDMB_SET_BAND_CONFIRM,
MSG_ID_TDMB_AUTO_SCAN_REQUEST,
MSG_ID_TDMB_AUTO_SCAN_CONFIRM,
MSG_ID_TDMB_SET_FREQUENCY_REQUEST,
MSG_ID_TDMB_SET_FREQUENCY_CONFIRM,
MSG_ID_TDMB_SELECT_SERVICE_REQUEST,
MSG_ID_TDMB_SELECT_SERVICE_CONFIRM,
MSG_ID_TDMB_GET_SIGNAL_REQUEST,
MSG_ID_TDMB_GET_SIGNAL_CONFIRM,
MSG_ID_TDMB_START_ANNOUNCEMENT_REQUEST,
MSG_ID_TDMB_START_ANNOUNCEMENT_CONFIRM,
MSG_ID_TDMB_END_ANNOUNCEMENT_REQUEST,
MSG_ID_TDMB_END_ANNOUNCEMENT_CONFIRM,
MSG_ID_TDMB_SET_IDLE_REQUEST,
MSG_ID_TDMB_SET_IDLE_CONFIRM,
MSG_ID_TDMB_MCI_RECONFIG_INDICATION,
MSG_ID_TDMB_GET_ENSEMBLE_INFO_REQUEST,
MSG_ID_TDMB_GET_ENSEMBLE_INFO_CONFIRM,
MSG_ID_TDMB_DEMOD_MCI_RECONFIG_INDICATION,
MSG_ID_TDMB_DEMOD_ANNOUNCEMENT_INDICATION,
MSG_ID_TDMB_ANNOUNCEMENT_INDICATION,
MSG_ID_TDMB_SET_ANNOUNCEMENT_REQUEST,
MSG_ID_TDMB_SET_ANNOUNCEMENT_CONFIRM,
MSG_ID_TDMB_DATA_INDICATION,
MSG_ID_TDMB_SERVICE_END_INDICATION,
MSG_ID_TDMB_FIC_IND_INDICATION,
MSG_ID_TDMB_MSC_IND_INDICATION,
MSG_ID_TDMB_STOP_AUTO_SCAN_REQUEST, MSG_ID_TDMB_CODE_END = MSG_ID_TDMB_STOP_AUTO_SCAN_REQUEST,
MSG_ID_TDMB_INT_ARRIVE,

