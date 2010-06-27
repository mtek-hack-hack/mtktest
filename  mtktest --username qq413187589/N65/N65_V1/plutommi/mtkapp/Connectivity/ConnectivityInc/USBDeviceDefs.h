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
 * USBDeviceDefs.h
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

#ifndef MMI_USBDEVICE_DEFS_H
#define MMI_USBDEVICE_DEFS_H

#ifdef __MMI_USB_SUPPORT__

/***************************************************************************** 
* Definations
*****************************************************************************/

/* Number of menu items in usb config page */
#define MAX_USB_MENUITEM   2    /* 3 */

/* The delay time period when usb config screen is allowed to display */
#define PENDING_USBDETECTION_HDLR_TIMER_DUR  3000       /* 3 sec */

/* The display time of shutdown for mass storage notification screen */
#define USB_SHUTDOWN_SCR_TIMER_DUR  2000        /* 2 sec */

/***************************************************************************** 
* Enumation
*****************************************************************************/

/*****************************/
/* MMI Usb config menu items */
/*****************************/
typedef enum
{

    MMI_USB_CONFIG_MENU_MS = 0,
#ifdef __MMI_WEBCAM__
    MMI_USB_CONFIG_MENU_WEBCAM,
#endif 
    MMI_USB_CONFIG_MENU_CDCACM,

    MMI_USB_CONFIG_MENU_PICTBRIGE,

    MMI_USB_CONFIG_MENU_RESERVED,

    MMI_USB_CONFIG_MENU_END
} MMI_USB_CONFIG_MENU;

typedef enum
{
    MMI_USB_WEBCAM_DISCONNECT,
    MMI_USB_WEBCAM_CONNECTED,
    MMI_USB_WEBCAM_LISTENING,
    MMI_USB_WEBCAM_RUNNING,
    MMI_USB_WEBCAM_PAUSE
} MMI_USB_WEBCAM_STATE;

/***************************************************************************** 
* Structure
*****************************************************************************/

/********************/
/* MMI Usb context * */
/********************/
typedef struct
{
    /*   Usb config screen might interrupt every screen, if user press END key at usb    */
    /* config screen, shall distory config screen itself and execute the END key handler */
    /* register by original screen                                                       */
    FuncPtr EndKeyFuncPtr;

    /*
     * Bit 0: Before Power on Flag
     * Bit 1: Pending Timer Flag
     * Bit 2: Usb plug out during switch port
     */
    U32 flag;

#ifdef __MMI_WEBCAM__
    U16 webcam_state;
    BOOL webcam_is_sub_display;
    BOOL webcam_is_clam_close;
#endif /* __MMI_WEBCAM__ */ 

    U16 current_img;

    /* MMI usb state (previous, only use when interrupt at config page) */
    MMI_USB_STATUS usb_status_prev;

    /* MMI usb state (current) */
    MMI_USB_STATUS usb_status;

    /* Previous PS and TST  port setting, for restore when plug out usb device */
    U8 ps_port_prev;
    U8 tst_port_prev;

    U8 reset_type;
} MMI_USB_CONTEXT;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern BOOL PermitUsbCfgScreenDisplay(void);
extern void SendUsbConfigToHW(U8 mode);
extern void UsbConfigRspHdlr(void *info);
extern void UsbGpioDetectIndHdlr(void *info);
extern void EntryUsbDetectQueryScr(void);
extern void ShowUsbScr(void);
extern void ShowUsbChgCmpltScr(void);
extern void ShowSubLCDUsbScr(void);
extern void ExitSubLCDUsbScr(void);
extern void ShowSubLCDUsbChgrCmpltScr(void);
extern void ExitSubLCDUsbChgrCmpltScr(void);
extern void UsbPwnOnThenPwnOn(void);
extern void InitUsbModeEventHandler(void);
extern void UsbDetectScrHlightHdlr(S32 index);
extern void UsbDetectScrLskHdlr(void);
extern void UsbDetectScrRskHdlr(void);
extern void UsbDetectScrENDKeyHdlr(void);
extern void ExitUsbDetectQueryScr(void);
extern void UsbUartSwitchRspHdlr(void *info);
extern void SendUsbUartSwitchToHW(U8 app, U8 new_port);
extern void SendUsbGetUartPortToHW(void);
extern void UsbSendMsgToHW(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void UsbConfigFirstPage(U8 mode);
extern void UsbGetUartPortRspHdlr(void *info);
extern void UsbCfgMSTimeoutHdlr(void);
extern void UsbConfigMassStorage(void);
extern void UsbConfigCDCACM(void);
extern U8 GetUsbDefAppSetting(void);
extern void mmi_usb_set_reset_type(U8 reset_type);

/* extern void PendingUsbDetectionAtPowerOnHdlr(void); */

#endif /* __MMI_USB_SUPPORT__ */ 

#endif /* MMI_USBDEVICE_DEFS_H */ 

