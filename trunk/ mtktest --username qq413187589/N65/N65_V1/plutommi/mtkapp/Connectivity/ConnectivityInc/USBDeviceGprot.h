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
 * USBDeviceGprot.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_USBDEVICE_GPROT_H
#define MMI_USBDEVICE_GPROT_H

#ifdef __MMI_USB_SUPPORT__

/***************************************************************************** 
* Definations
*****************************************************************************/

/*****************/
/* MMI Usb state */
/*****************/
typedef enum
{

    MMI_USBSTATUS_UNKNOW = 0,           /* Unknow, initial state */
    MMI_USBSTATUS_PLUGIN,               /* Usb device pluged in */
    MMI_USBSTATUS_CONF_PAGE,            /* Usb device pluged in and MMI Screen is usb configure page */
    MMI_USBSTATUS_IGNORED,              /* Usb device pluged in, user ignore the configuration */
    MMI_USBSTATUS_PLUGOUT,              /* Usb device pluged out */
    MMI_USBSTATUS_MS_PROC,              /* Usb device is configuring as mass storage */
    MMI_USBSTATUS_MS,                   /* Usb device is in mass storage mode */
    MMI_USBSTATUS_CDCACM_PROC,          /* Usb device is configuring as com port emulator */
    // MMI_USBSTATUS_CDCACM_SWCHPORT,   /* Usb device is configuring as com port emulator */
    MMI_USBSTATUS_CDCACM,               /* Usb device is in com port emulator mode */
    MMI_USBSTATUS_WEBCAM,               /* Usb device is configuring as webcam */
    MMI_USBSTATUS_PICTBRIGE,            /* Usb device is configuring as pictbrige */
    MMI_USBSTATUS_ENUM_END              /* Last state, shall not modify this value */
} MMI_USB_STATUS;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void InitMMIUsbContext(void);
extern void InitializeUsbScr(void);
extern MMI_USB_STATUS GetUsbStatus(void);
extern void SetUsbStatus(MMI_USB_STATUS);
extern void PendingUsbDetectionHdlr(void);
extern void SetUsbBeforePowerOnFlag(BOOL flag); /* void SetUsbBeforePowerOnFlag(void); */
extern void UsbDetectIndHdlr(void *info);
extern void UsbPowerOnFinishHdlr(void *info);

#ifdef __USB_IN_NORMAL_MODE__
extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
extern pBOOL mmi_usb_check_path_exported(S8 *path);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
extern pBOOL mmi_usb_is_leaving_ms_mode(void);
extern MMI_BOOL mmi_usb_is_any_exported_drive(void);
extern void mmi_usb_shutdown_handler(void);
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __MMI_WEBCAM__
extern void mmi_usb_webcam_entry_app_scr(void);
extern MMI_BOOL mmi_usb_webcam_is_active(void);
#endif /* __MMI_WEBCAM__ */ 

extern void mmi_usb_set_background_still(MMI_BOOL isStill);

extern BOOL mmi_usb_is_network_services_available(void);

#endif /* __MMI_USB_SUPPORT__ */ 
#endif /* MMI_USBDEVICE_GPROT_H */ 

