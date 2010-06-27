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
 * HardwareHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Handles the Events Sent from Hardware queue
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

   FILENAME : HardwareHandler.c

   PURPOSE     : Handles the Events Sent from Hardware queue.

   REMARKS     : nil

   AUTHOR      : Pixtel Engineers

   DATE     : .


**************************************************************/

#include "MMI_include.h"
// #include "CustomCfg.h"

//#ifdef FIRST_PASS
//#include "BuildCfg.h"
//#endif

#include "ProtocolEvents.h"
#include "HardwareEventHandler.h"
#include "HardwareEvents.h"
/* Applications should be independant. This is required for customizing 
   packaging of applications.
   #include "Phonebook.h" */
#include "gpioInc.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#endif 

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 


#ifdef __MMI_TVOUT__
#include "PhoneSetupGprots.h"   /* Init TV-Out */
#endif 

#include "PowerOnChargerProt.h"

extern void DateTimerIndication(void *p);
extern void GpioDetectInd(void *info);
extern void VolumeChangeIndication(void *info);


/*****************************************************************************
 * FUNCTION
 *  InitHardwareEvents
 * DESCRIPTION
 *  Initialize the ProtocolEvents
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitHardwareEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_key_handle, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);
#ifdef __MMI_DUAL_SIM__    
    SetSlaveProtocolEventHandler(mmi_frm_key_handle, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);
#endif /* __MMI_DUAL_SIM__ */
    SetProtocolEventHandler(L4SetClockRSP, MSG_ID_MMI_EQ_SET_RTC_TIME_RSP);
    SetProtocolEventHandler(L4GetClockTimeRSP, MSG_ID_MMI_EQ_GET_RTC_TIME_RSP);
    SetProtocolEventHandler(DateTimerIndication, MSG_ID_MMI_EQ_CLOCK_TICK_IND);
    SetProtocolEventHandler(GpioDetectInd, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    SetProtocolEventHandler(GpioCtrlReqHdlr, MSG_ID_MMIAPI_DEVICE_GET_CTRL_REQ);
    SetProtocolEventHandler(GpioPlayReqHdlr, MSG_ID_MMIAPI_DEVICE_PLAY_REQ);

#ifdef __MMI_USB_SUPPORT__
    SetProtocolEventHandler(UsbDetectIndHdlr, MSG_ID_MMI_EQ_USBDETECT_IND);
#endif 

    /* GPIO device Detect indication event handler */
    SetProtocolEventHandler(GpioDetectInd, PRT_EQ_GPIO_DETECT_IND);
#ifdef __MMI_USB_SUPPORT__
    SetProtocolEventHandler(UsbDetectIndHdlr, PRT_EQ_USB_DETECT_IND);
#endif 
    /* volume change indication from L4 */
    /* SetProtocolEventHandler( VolumeChangeIndication, MSG_ID_MMI_EQ_VOLUME_CHANGE_IND); */

#ifdef __MMI_IRDA_SUPPORT__
    mmi_irda_init_protocol_event();
#endif 

    SetProtocolEventHandler((PsFuncPtr)mmi_gpio_backlight_ctrl_req_hdlr, MSG_ID_MMIAPI_BACKLIGHT_CONTROL_REQ);
    SetProtocolEventHandler((PsFuncPtr)mmi_gpio_led_ctrl_req_hdlr, MSG_ID_MMIAPI_LED_CONTROL_REQ);

#ifdef __MMI_TVOUT__
    /* init tvout - to re-register message handler */
    mmi_phnset_init_tvout();
#endif /* __MMI_TVOUT__ */

    SetProtocolEventHandler(mmi_get_battery_level_req_hdlr, MSG_ID_MMIAPI_GET_BATTERY_LEVEL_REQ);
    SetProtocolEventHandler(mmi_battery_level_notify_start_req_hdlr, MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_START_REQ);
    SetProtocolEventHandler(mmi_battery_level_notify_stop_req_hdlr, MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_STOP_REQ);   

}

/* MTK end */

