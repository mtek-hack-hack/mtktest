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
 * usb_trc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the index trace of USB module
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _USB_TRC_H
#define _USB_TRC_H

#include "kal_trace.h"


#ifdef __TST_MODULE__
	#ifndef GEN_FOR_PC
		#ifndef _STACK_CONFIG_H
			#error "stack_config.h should be included before tst_config.h"
		#endif
	#endif /* GEN_FOR_PC */

	#ifndef _KAL_TRACE_H
		#error "kal_trace.h should be included before tst_trace.h"
	#endif

#ifdef __USB_ENABLE__
	BEGIN_TRACE_MAP(MOD_USB)
#else /*!__USB_ENABLE__*/
	BEGIN_TRACE_MAP(MOD_UART1_HISR)
#endif   /*__USB_ENABLE__*/

	TRC_MSG(USB_RESET_TIMES, "USB already us reset %d timesr")
	TRC_MSG(USB_IS_SUSPEND, "USB is suspend")
	TRC_MSG(USB_IS_RESUME, "USB is resume")
	TRC_MSG(USB_IS_CONFIGURE, "USB is configured")
	TRC_MSG(USB_PLUG_OUT, "USB is plugged out")
	TRC_MSG(USB_DRV_IS_ERROR_1, "HW ERROR: error status is %d, fast mode status is %d")
	TRC_MSG(USB_DRV_IS_ERROR_2, "HW ERROR in host mode")
	TRC_MSG(USB_DRV_IS_ERROR_3, "HW ERROR D+ down")
	TRC_MSG(USBACM_DMA_CALLBACK, "USB DMA TX callback %d bytes")
	TRC_MSG(USBACM_THRESHOLD_ON, "Threshold is ON")
	TRC_MSG(USBACM_THRESHOLD_OFF, "Threshold is OFF")
	TRC_MSG(USBACM_PC_SENT,  "PC sent %d")
	TRC_MSG(USBACM_RESET_READY_TO_READ_FLAG, "reset ready to read flag")
	TRC_MSG(USBACM_INIT_READY_TO_READ_FLAG, "initialize ready to read flag")
	TRC_MSG(USBACM_OPEN_READY_TO_READ_FLAG, "open by %d owner reset ready to read flag")
	TRC_MSG(USBACM_CLEAR_RX_BUF_READY_TO_READ_FLAG, "clear RX buf by %d owner reset ready to read flag")
	TRC_MSG(USBACM_CLEAR_TX_BUF_READY_TO_READ_FLAG, "clear TX buf by %d owner reset ready to read flag")
	TRC_MSG(USBACM_INTR, "ACM intr pipe sent %d bytes")
	TRC_MSG(USBACM_CLEAR_TX_ISR_BUF, "clear TX ISR buffer")
	TRC_MSG(USBACM_OPEN, "USB ACM UART OPEN")
	TRC_MSG(USBACM_CLOSE, "USB ACM UART close by %d owner")
	TRC_MSG(USBACM_SET_OWNER, "USB ACM set %d owner")
	TRC_MSG(USBACM_SEND_ISR_DATA, "USB ACM send ISR data %d bytes")
	TRC_MSG(USBACM_PUT_ISR_BYTES, "USB ACM put ISR bytes %d bytes")
	TRC_MSG(USBACM_PUT_BYTES, "USB ACM put bytes %d bytes")
	TRC_MSG(USBACM_PUT_BYTES_BUF_FULL, "USB ACM buffer is full because put bytes by %d owner")
	TRC_MSG(USBACM_CLEAR_RX_BUF, "USB ACM clear RX buffer")
	TRC_MSG(USBACM_GET_BYTES_BUF_EMPTY, "USB ACM buffer is empty because get bytes by %d owner")
	TRC_MSG(USBACM_FAIL_NOT_UNMASK, "USB ACM not unmask because USB fail")
	TRC_MSG(USBACM_GET_BYTES, "USB ACM get bytes %d bytes")
	TRC_MSG(USBACM_CLEAR_TX_BUF, "USB ACM clear TX buffer")
	TRC_MSG(USBACM_CLEAR_RDY_W, "USB ACM clear readt to write flag by %d owner")
	TRC_MSG(USBIMAGE_GET, "Printer send %d bytes")
	TRC_MSG(USBMS_DMA_TIME_OUT, "USB MS RX DMA time out")
	TRC_MSG(USBMS_ERROR_CMD, "USB MS %d error cmd")
	TRC_MSG(USBVIDEO_INIT, "USB video is init")
	TRC_MSG(USBVIDEO_RELEASE, "USB video is released")
	TRC_MSG(USBVIDEO_VC_ERROR_CMD, "USB video VC %d error cmd")
	TRC_MSG(USBVIDEO_VS_ERROR_CMD, "USB video VS %d error cmd")
	TRC_MSG(USBVIDEO_STILL_PROBE_NONE, "USB video reset still commit index because video commit doen")
	TRC_MSG(USBVIDEO_SET_COMMIT_VIDEO_STATE, " USB video Set commit video state %d")
	TRC_MSG(USBVIDEO_STILL_COMMIT_DONE, "USB video still commit %d index")
	TRC_MSG(USBVIDEO_GET_BUFFER, "USB video get video buffer buff r %d, w%d, f %d ")
	TRC_MSG(USBVIDEO_COMPLETE_BUFFER, "USB video complete video buffer buff r %d, w%d, f %d ")
	TRC_MSG(USBVIDEO_DMA_DONE, "USB video DMA done buff r %d, w%d, f %d ")
	TRC_MSG(USBVIDEO_STILL_ERROR, "WARNING: state is still but commit is 0")


#ifdef __USB_ENABLE__
	END_TRACE_MAP(MOD_USB)
#else /*!__USB_ENABLE__*/
	END_TRACE_MAP(MOD_UART1_HISR)
#endif   /*__USB_ENABLE__*/


#endif   /*__TST_MODULE__*/

#endif /* _USB_TRC_H */

