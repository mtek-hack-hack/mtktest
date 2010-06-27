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
 *    usb_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb hardware related function definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USB_DRV_H
#define USB_DRV_H

/* reserved for future use*/
//#define USB_SUPPORT_MUTIPLE_APP


#if defined (DRV_USB_IP_V3)
#define MAX_INTR_EP_NUM		4		/* 4 Tx and 3 Rx */

#define USB_EP0_MAXP			64		/* control pipe, the same when HS or FS */
#define USB_EP_BULK_MAXP_HS	512  	/* maximum packet size for high-speed bulk endpoints */
#define USB_EP_BULK_MAXP_FS	64  		/* maximum packet size for full-speed bulk endpoints */

#define USB_EP_ISO_MAXP_HB      (1024|(0x02<<11))
#define USB_EP_ISO_MAXP_HB_HS	3072 	/* maximum packet size for high-speed, high bandwidth isochronous endpoints */
#define USB_EP_ISO_MAXP_HS	1024 	/* maximum packet size for high-speed isochronous endpoints */
#define USB_EP_ISO_MAXP_FS	 	1023  	/* maximum packet size for full-speed isochronous endpoints */

#define USB_EP_INTR_MAXP_HB	(1024|(0x02<<11))

#define USB_EP_INTR_MAXP_HB_HS	3072   	/* maximum packet size for high-speed, high bandwidth interrupt endpoints */
#define USB_EP_INTR_MAXP_HS	1024   	/* maximum packet size for high-speed interrupt endpoints */
#define USB_EP_INTR_MAXP_FS	64   		/* maximum packet size for full-speed interrupt endpoints */

#else

#define MAX_INTR_EP_NUM		3		/* 3 Tx and 2 Rx */


#define USB_EP0_MAXP		8
#define USB_EP_BULK_MAXP	64  /* maximum packet size for bulk endpoints */

#if defined(DRV_USB_IP_V1)
#define USB_EP_INTR_MAXP	16   /* maximum packet size for interrupt endpoints */
#elif  defined(DRV_USB_IP_V2)
#define USB_EP_INTR_MAXP	8   /* maximum packet size for interrupt endpoints */
#endif
#endif


typedef enum 
{
	USB_DMA0_TYPE = 0,
	USB_DMA1_TYPE,
	USB_DMA2_TYPE
} USB_DMA_TYPE;


typedef enum 
{
	USB_TEST_MODE_TYPE_J = 0,
	USB_TEST_MODE_TYPE_K,
	USB_TEST_MODE_TYPE_SE0_NAK,
	USB_TEST_MODE_TYPE_PACKET
}USB_TEST_MODE_TYPE;


/* USB PDN owner id */
typedef enum
{
	USB_PDN_OWNER_USB,
	USB_PDN_OWNER_IRDA,
	USB_PDN_OWNER_UPLL	
} USB_PDN_OWNER;

/* IN, OUT pipe index for ep_number */
typedef enum 
{
	USB_TX_EP_TYPE = 0,
	USB_RX_EP_TYPE
} USB_EP_TYPE;


/* CTRL, BULK, INTR, ISO endpoint */
typedef enum
{
	USB_ENDPT_CTRL = 0,
	USB_ENDPT_BULK,
	USB_ENDPT_INTR,
	USB_ENDPT_ISO
}USB_ENDPT_TXFER_TYPE;

/* add for debug*/
typedef enum
{
	USB_CTRL_STALL_ENTRY_1 = 0,
	USB_CTRL_STALL_ENTRY_2,	
	USB_CTRL_STALL_ENTRY_3,
	USB_CTRL_STALL_ENTRY_4,
	USB_CTRL_STALL_ENTRY_5		/* for image class */	
}USB_CTRL_STALL_ENTRY;

/* endpoint 0 hardware control state*/
typedef enum
{
	USB_EP0_DRV_STATE_READ_END,
	USB_EP0_DRV_STATE_WRITE_RDY,
	USB_EP0_DRV_STATE_TRANSACTION_END,
	USB_EP0_DRV_STATE_CLEAR_SENT_STALL
}USB_EP0_DRV_STATE;

/* interrupt handler type*/
typedef enum
{
	USB_DRV_HDLR_RESET,
	USB_DRV_HDLR_SUSPEND,
	USB_DRV_HDLR_RESUME,
	USB_DRV_HDLR_EP0,
	USB_DRV_HDLR_EP_TX,
	USB_DRV_HDLR_EP_RX
}USB_DRV_HDLR_TYPE;

/* The set address action may be different for different hardware, 
    This is the current state for the set address function */
typedef enum
{
	USB_SET_ADDR_DATA,
	USB_SET_ADDR_STATUS
}UBS_SET_ADDR_STATE;


/* interrupt handler function type */
typedef void (*usb_drv_intr_handler_ptr)(void);
/* application dma callback function type */
typedef void (*usb_dma_callback)(void);

#ifdef _USB_VBUS_DETECT_WITH_NIRQ_
typedef void (*usb_vbus_callback)(void);
#endif


/* driver info functions */
extern void USB_Init_Drv_Info(void);
extern void USB_ResetDrv_Info(void);
extern void USB_Register_Drv_Info(USB_DRV_HDLR_TYPE type, kal_uint32 ep_num, usb_drv_intr_handler_ptr hdlr);
extern kal_uint32 USB_Get_HW_Error_Count(void);
extern void USB_Set_UnMask_Irq(kal_bool set);
extern kal_bool USB_Get_UnMask_Irq(void);
extern kal_bool USB_Get_Pro_USB_HISR(void);
extern kal_bool USB_Get_EP_Stall_Status(kal_uint8 ep_num, USB_EP_TYPE type);
#ifndef __OTG_ENABLE__
extern void USB_Drv_Activate_ISR(void);
extern void USB_Drv_Create_ISR(void);
#endif

#if defined(DRV_USB_IP_V3)
extern void USBDMA_Drv_Create_ISR(void);
extern void USBDMA_Drv_Activate_ISR(void);
#endif

/* system ctrl functions */
extern void USB_PDNEnable(USB_PDN_OWNER owner);
extern void USB_PDNDisable(USB_PDN_OWNER owner);
extern void USB_PDNmode(kal_bool pdn_en);
extern void USB_Reset_Drv(void);
extern void USB_Initialize_Drv(void);
extern void USB_Release_Drv(void);
extern void USB_SetAddress(kal_uint8 addr, UBS_SET_ADDR_STATE state);
extern kal_uint16 USB_GetFrameCount(void);

/* EP ctrl functinos */
extern void USB_TxEPInit(kal_uint8 epno, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type);
extern void USB_RxEPInit(kal_uint8 epno, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type);
extern void USB_EP0En(void);
extern void USB_TxEPEn(kal_uint8 no, kal_bool bDMA);
extern void USB_TxEPDis(kal_uint8 no, kal_bool bDMA);
extern void USB_RxEPEn(kal_uint8 no, kal_bool bDMA);
extern void USB_RxEPDis(kal_uint8 no, kal_bool bDMA);
extern void USB_TxEPClearDataTog(kal_uint8 epno);
extern void USB_RxEPClearDataTog(kal_uint8 epno);
extern void USB_TxEPClearData01(kal_uint8 epno);
#if 0
/* under construction !*/
#endif

extern void USB_EPFIFORead(kal_uint8 nEP, kal_uint16 nBytes, void *pDst);
extern void USB_EPFIFORead_Shift(kal_uint8 nEP, kal_uint16 nBytes, void *pDst, kal_uint32 shift);
extern void USB_EPFIFOWrite (kal_uint8 nEP, kal_uint16 nBytes, void *pSrc);
extern void USB_CtrlEPStall(kal_uint8 EPno, USB_EP_TYPE type, kal_bool en, USB_CTRL_STALL_ENTRY entry);
extern void USB_Get_EP0_Status(kal_bool *p_transaction_end, kal_bool *p_sent_stall);
extern void USB_Update_EP0_State(USB_EP0_DRV_STATE state, kal_bool stall, kal_bool end);
extern kal_uint32 USB_EP0_Pkt_Len(void);
extern void USB_EP_Bulk_Tx_Ready(kal_uint8 ep_num);
extern kal_uint32 USB_EP_Rx_Pkt_Len(kal_uint8 ep_num);
extern void USB_EP_Bulk_Rx_Ready(kal_uint8 ep_num);
extern kal_bool USB_Is_EP_Bulk_Tx_Empty(kal_uint8 ep_num);
extern void USB_Clear_Tx_EP_FIFO(kal_uint8 ep_num);
extern void USB_Clear_Rx_EP_FIFO(kal_uint8 ep_num);

/* DMA control functions */
extern void USB_Get_DMA_Channel(kal_uint8 ep_num, USB_EP_TYPE direction, kal_bool same_chan);
extern void USB_Stop_DMA_Channel(kal_uint8 ep_num, USB_EP_TYPE  type);
extern void USB_Free_DMA_Channel(kal_uint8 ep_num, USB_EP_TYPE  type);
extern void USB_DMA_Setup(kal_uint8 ep_num, USB_EP_TYPE  direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length, 
					usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);

extern kal_bool USB_DMA_Get_Run_Status(kal_uint8 ep_num, USB_EP_TYPE  type);
extern void USB_DMA_Set_Run_Status(kal_uint8 ep_num, USB_EP_TYPE  type, kal_bool status);
extern kal_uint32 USB_Get_DMA_Rx_Count(kal_uint8 ep_num);


#if defined(DRV_USB_IP_V3)
extern kal_bool USB_Is_High_Speed(void);
extern void USB_Enter_Test_Mode(USB_TEST_MODE_TYPE test_selector);
extern void USB_Reset_FIFO(void);

extern void USB_DMA_PP_Setup(kal_uint8 ep_num, USB_EP_TYPE direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr1, kal_uint32 length1, 
			kal_uint32 addr2, kal_uint32 length2, usb_dma_callback callback, kal_bool callback_upd_run, 
					USB_DMA_TYPE dma_type, kal_bool first_time, kal_bool set_a_first);

extern kal_uint32 USB_DMA_Get_Rx_Count(kal_uint8 ep_num);
extern kal_uint32 USB_DMA_Get_Rx_Address(kal_uint8 ep_num);

#endif

/* polling functions (used for exception log) */
extern void USB_Polling_Transmit_Done(kal_uint8 ep_num);
extern void USB_Polling_Transmit_Data(kal_uint8 ep_num, USB_EP_TYPE  direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
				usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);
extern void USB_Polling_Recv_Data(kal_uint8 ep_num);

extern void USB_HISR(void);
								
#ifdef _USB_VBUS_DETECT_WITH_NIRQ_
extern void USB_NIRQ_Registration(void (reg_hisr)(void));
#endif
								
#endif //USB_DRV_H
 


