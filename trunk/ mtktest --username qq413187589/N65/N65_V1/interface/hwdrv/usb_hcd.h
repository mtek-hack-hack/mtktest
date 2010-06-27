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
 *    usb_hcd.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb host hardware related function definitions. Provide for usb protocol module.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_HCD_H
#define USB_HCD_H

#include "usb_drv.h"

#define USB_HCD_MAX_EP_NUM	4

typedef enum
{
	USB_HCD_HDLR_ATTACH,
	USB_HCD_HDLR_DETACH,
	USB_HCD_HDLR_RESUME,
	USB_HCD_HDLR_TOKEN_DONE
} USB_HCD_HDLR_TYPE;

typedef enum
{
	USB_HCD_ENDPT_CTRL,
	USB_HCD_ENDPT_BULK,
	USB_HCD_ENDPT_INTR,
	USB_HCD_ENDPT_ISO
}USB_HCD_ENDPT_TYPE;

typedef enum
{
	USB_HCD_PIPE_DIR_IN,
	USB_HCD_PIPE_DIR_OUT
}USB_HCD_PIPE_DIRECTION;

typedef enum
{
	USB_HCD_OK,
	USB_HCD_NO_RESPONSE,	
	USB_HCD_TIMEOUT,	
	USB_HCD_STALL, 
	USB_HCD_DETATCH
}USB_HCD_STATUS;

typedef enum
{
	USB_HCD_BUS_SUSPEND_SOF,
	USB_HCD_BUS_RESUME_SOF, 
	USB_HCD_BUS_ASSERT_RESUME,
	USB_HCD_BUS_DEASSERT_RESUME
}USB_HCD_BUS_TYPE;

/* interrupt handler function type */
typedef void (*usb_hcd_intr_handler_ptr)(USB_HCD_STATUS result, kal_uint32 param);

extern void USB_HCD_Init_Drv_Info(void);
extern void USB_HCD_Register_Drv_Info(USB_HCD_HDLR_TYPE type, kal_uint32 ep_num, usb_hcd_intr_handler_ptr hdlr);
extern kal_uint8 USB_HCD_Get_FM_Pkt_Size(void);
extern void USB_HCD_Set_UnMask_Irq(kal_bool set);
extern kal_bool USB_HCD_Get_UnMask_Irq(void);
extern void USB_HCD_Dis_Attach(void);
extern void USB_HCD_En_Attach(void);
//extern void USB_HCD_Drv_Activate_ISR(void);

extern void USB_HCD_Initialize_Drv(void);
extern void USB_HCD_Release_Drv(void);
extern void USB_HCD_SetAddress(kal_uint8 addr);
extern void USB_HCD_Resume(void);
extern void USB_HCD_Suspend(void);
extern void  USB_HCD_Delay_Reset_Device(USB_HCD_STATUS reset_reason, kal_uint32 timeout);
extern void USB_HCD_Bus_Control(USB_HCD_BUS_TYPE type);

extern kal_uint8 USB_HCD_Get_EP_Channel(void);
extern void USB_HCD_Free_EP_Channel(void);
extern void USB_HCD_Set_EP_Max_Pkt(kal_uint8 index, kal_uint16 max_pkt_size);
extern void USB_HCD_Clear_Data01(kal_uint8 index);
extern void USB_HCD_EP0En(void);
extern void USB_HCD_InEPEn(kal_uint8 index, kal_uint8 no, USB_HCD_ENDPT_TYPE ep_type, kal_uint8 interval, kal_bool bDMA);
extern void USB_HCD_OutEPEn(kal_uint8 index, kal_uint8 no, USB_HCD_ENDPT_TYPE ep_type, kal_uint8 interval, kal_bool bDMA);
extern void USB_HCD_InEPDis(kal_uint8 index);
extern void USB_HCD_OutEPDis(kal_uint8 index);
extern kal_bool USB_HCD_Recv_Req(kal_uint8 index, kal_uint16 nBytes, void *pDst);
extern kal_bool USB_HCD_Send_Req(kal_uint8 index, kal_uint16 nBytes, void *pSrc);
extern void USB_HCD_EP0_Setup_Req(kal_uint16 nBytes, void *pSrc);
extern void USB_HCD_EP0_Data_Req(USB_HCD_PIPE_DIRECTION direction, kal_uint16 nBytes, void *pData);
extern void USB_HCD_EP0_Status_Req(USB_HCD_PIPE_DIRECTION direction);

extern void USB_HCD_Get_DMA_Channel(void);
extern void USB_HCD_Stop_DMA_Channel(void);
extern void USB_HCD_Free_DMA_Channel(void);
extern void USB_HCD_DMA_Setup(kal_uint32 index, USB_EP_TYPE  type, kal_uint32 addr, kal_uint32 length, kal_bool callback_upd_run);

extern void USB_HCD_HISR(void);

#endif	/* USB_HCD_H */

