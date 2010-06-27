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
 * USBDeviceGexdcl.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_USBDEVICE_GEXDCL_H
#define MMI_USBDEVICE_GEXDCL_H

#ifndef MMI_USBDEVICE_DEFS_H
#error "USBDeviceDefs.h should be included"
#endif 

#ifdef __MMI_USB_SUPPORT__

/***************************************************************************** 
* MMI USB context reference
*****************************************************************************/
extern MMI_USB_CONTEXT *mmi_usb_ptr;

#define MMI_USB_CTX(a) mmi_usb_ptr->a

/***************************************************************************** 
* MMI USB context defination and operation
*****************************************************************************/
/* MMI usb context bit-wise flag defination */
#define MMIUSB_MASK_BEFORE_POWERON  0x00000001
#define MMIUSB_MASK_PENDING_TIMER   0x00000002
#define MMIUSB_MASK_PORT_SWITCHING  0x00000004
#define MMIUSB_MASK_IS_CONNECT      0x00000008
#define MMIUSB_MASK_RESERVED_1      0x00000010
#define MMIUSB_MASK_RESERVED_2      0x00000020
#define MMIUSB_MASK_RESERVED_3      0x00000040
#define MMIUSB_MASK_RESERVED_4      0x00000080

/* MMI usb context bit-wise flag operation */
#define MMIUSB_GET_FLAG(a)       ( ((mmi_usb_ptr->flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMIUSB_SET_FLAG(a)       ( (mmi_usb_ptr->flag) |=  a )
#define MMIUSB_RESET_FLAG(a)   ( (mmi_usb_ptr->flag) &=  ~a )

#endif /* __MMI_USB_SUPPORT__ */ 

#endif /* MMI_USBDEVICE_GEXDCL_H */ 

