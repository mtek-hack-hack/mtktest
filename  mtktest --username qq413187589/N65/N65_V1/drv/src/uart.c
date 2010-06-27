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
 *    uart.c      
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the uart1 driver and the adaption layer
 *   between driver and maui protocol.
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include    "kal_release.h"
#include    "stack_common.h"
#include    "stack_msgs.h"
#include    "app_ltlcom.h"       /* Task message communiction */
#include    "stack_buff_pool.h"
#include    "app_buff_alloc.h"
#include    "drv_comm.h"
#include    "reg_base.h"
#include    "uart_hw.h"
#include    "bmd.h"
#include    "intrCtrl.h"
#include    "drvpdn.h"
#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include    "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "uart_sw.h"
#include    "dma_hw.h"
#include    "dma_sw.h"
#include    "gpt_sw.h"
#include    "init.h"
#include    "drv_hisr.h"
#ifdef __ROMSA_SUPPORT__
#ifndef __ROMSA_EXPORT_UART_H__
#include "romsa_export_uart.h"
#endif
#include    "gpt_hw.h"
#endif

#ifdef VFIFO_DBG
#include "string.h"
static kal_uint32 gUART_TrxHandler_VFIFO;
static kal_uint32 gUART_RecHandler_VFIFO;
static kal_uint32 gUART_RecTimeOutHandler;
#endif

#ifdef MCU_13M
   #define   UART_CLOCK   13000000    /* 13M */
#endif   /*MCU_13M*/

#ifdef MCU_26M
   #define   UART_CLOCK   26000000    /* 26M */
#endif   /*MCU_26M*/

#ifdef MCU_39M
   #define   UART_CLOCK   39000000    /* 39M */
#endif   /*MCU_39M*/

#ifdef MCU_52M
   #define   UART_CLOCK   52000000    /* 52M */
#endif   /*MCU_52M*/

#ifdef MCU_104M
   #define   UART_CLOCK  52000000    /* 104M */
#endif   /*MCU_104M*/

#ifdef MCU_122_88M
   #define   UART_CLOCK  30720000    /* 104M */
#endif   /*MCU_104M*/

#ifdef MCU_208M
   #define   UART_CLOCK  52000000    /* 104M */
#endif   /*MCU_104M*/

kal_uint8 UART_handle;
#ifndef __PRODUCTION_RELEASE__
   kal_uint8 uart_lcr_save[MAX_UART_PORT_NUM];
#endif   /*__PRODUCTION_RELEASE__*/

#if defined(DRV_UART2_NORMAL_DMA)
   kal_uint8                      uart2_dmaport;
   static DMA_INPUT               uart2_input;
   static DMA_HWRINGBUFF_MENU     uart2_txmenu;
   static UART_RingBuffer_SaveIndex       uart2_index_save;
#endif   /*DRV_UART2_NORMAL_DMA*/

UARTStruct UARTPort[MAX_UART_PORT_NUM];
static kal_bool   UART2_Intr_is_Running;
static kal_bool   UART2_race_check;
static UART_flowCtrlMode  old_uart_portswitch_fctrl = fc_hw;

#ifdef DRV_DEBUG
kal_uint8 uart_initialize[MAX_UART_PORT_NUM];
#endif /*DRV_DEBUG*/


kal_uint8 send_Txilm[MAX_UART_PORT_NUM] = {
   KAL_FALSE,
   KAL_FALSE,
#ifdef __UART3_SUPPORT__
   KAL_FALSE
#endif   /*__UART3_SUPPORT__*/
};

kal_uint8 send_Rxilm[MAX_UART_PORT_NUM] = {
   KAL_TRUE,
   KAL_TRUE,
#ifdef __UART3_SUPPORT__
   KAL_TRUE
#endif   /*__UART3_SUPPORT__*/

};

const VOID_FUNC UART_HISR[MAX_UART_PORT_NUM] =
{
   UART1_HISR,
   UART2_HISR,
#ifdef __UART3_SUPPORT__
   UART3_HISR
#endif   /*__UART3_SUPPORT__*/
};

const kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM] =
{
   UART1_base,
   UART2_base,
#ifdef __UART3_SUPPORT__
   UART3_base
#endif   /*__UART3_SUPPORT__*/
};
#ifdef __DMA_UART_VIRTUAL_FIFO__
kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM] =
{ 
   KAL_TRUE, 
   KAL_TRUE,//KAL_TRUE, 
#ifdef __UART3_SUPPORT__
   KAL_TRUE,//KAL_FALSE
#endif   /*__UART3_SUPPORT__*/
};
#else
kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM] =
{
   KAL_FALSE,
   KAL_FALSE,
#ifdef __UART3_SUPPORT__
   KAL_FALSE
#endif   /*__UART3_SUPPORT__*/
};
#endif/*__DMA_UART_VIRTUAL_FIFO__*/

kal_uint8 uart_escape_state=0;
/*DCM setting*/
#ifdef DCM_ENABLE
extern kal_uint8 DCM_GetHandle(void);
extern void DCM_Disable(kal_uint8 handle);	
extern void DCM_Enable(kal_uint8 handle);
kal_uint8 uart3_dcm_handle;
#ifdef __BT_USE_UART2__
kal_uint8 uart2_dcm_handle;
#endif
#endif

#ifdef __MTK_TARGET__
extern int INT_QueryExceptionStatus(void);
#endif
void UART_Calback(void *parameter);
void U_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
/*UART Customization */
extern const UART_customize_function_struct *UART_GetFunc(void);
const UART_customize_function_struct *UartCustomFunc;
const UART_rings_struct *UART_rings;

void uart_customize_init(void)
{
	/* retreive the function table */
   UartCustomFunc=UART_GetFunc();
	/* use the entry in function table to retreive desired information */
   UART_rings = UartCustomFunc->UART_Get_Data();
   #ifdef __DMA_UART_VIRTUAL_FIFO__   
   U_configure_DMA_VFIFO();
   #endif

}  
/*check if chip can support auto escape*/

kal_bool uart_support_autoescape(void)
{      
   #if defined(DRV_UART_NO_AUTOESCAPE) || defined(FPGA)
      return KAL_FALSE;	
   #elif defined(DRV_UART_6218B_AUTOESCAPE)
      static kal_bool reentrance = KAL_FALSE;
      static kal_bool uart_autoescape = KAL_TRUE;

      if (KAL_FALSE == reentrance)
      {
         reentrance = KAL_TRUE;
         uart_autoescape = (INT_ecoVersion()>EN)?KAL_TRUE:KAL_FALSE;
      }
      return uart_autoescape;	
   #elif defined(DRV_UART_6219_AUTOESCAPE)
      static kal_bool reentrance = KAL_FALSE;
      static kal_bool uart_autoescape = KAL_TRUE;

      if (KAL_FALSE == reentrance)
      {
         reentrance = KAL_TRUE;
         uart_autoescape = (INT_ecoVersion()>BV)?KAL_TRUE:KAL_FALSE;
      }
      return uart_autoescape;	
	#else  /*not support auto escape*/	
	   return KAL_TRUE;	
	#endif
}

#if defined(DRV_UART2_NORMAL_DMA)
kal_uint8 uart_update_race_check;
void UART2_update_index_save(kal_uint32 type, kal_uint32 index)
{
   ASSERT(uart_update_race_check == 0);
   uart_update_race_check = 1;
   uart2_index_save.type = type;
   uart2_index_save.index = index;
   uart_update_race_check = 0;
}
#endif

void UART_sendilm(UART_PORT port, msg_type msgid)
{
   ilm_struct *UART_ilm;
   void *port_ptr=0;      
   
   /*TY adds the following decription 20041013
     The first if check is to avoid the case that owenr is UARTX_HISR*/   
   if (UARTPort[port].ownerid != UARTPort[port].UART_id)
   {
	   switch(msgid)
	   {
	   	case MSG_ID_UART_READY_TO_READ_IND:
	   	{	   		 	
	   		uart_ready_to_read_ind_struct *tmp;      
	   		tmp = (uart_ready_to_read_ind_struct *) 
	   		construct_local_para(sizeof(uart_ready_to_read_ind_struct),TD_UL);
	   		tmp->port = port;   		
	   		port_ptr = tmp;   	
	   	}	
	   	break;	
	   	case MSG_ID_UART_READY_TO_WRITE_IND:      		
	   	{
	   		uart_ready_to_write_ind_struct *tmp;      
	   		tmp = (uart_ready_to_write_ind_struct *) 
	   		construct_local_para(sizeof(uart_ready_to_write_ind_struct),TD_UL);
	   		tmp->port = port;   		
	   		port_ptr = tmp;
	   	}	   	
	   	break;
	   	case MSG_ID_UART_DSR_CHANGE_IND:   	   		
	   	{
	   		uart_dsr_change_ind_struct *tmp;      
	   		tmp = (uart_dsr_change_ind_struct *) 
	   		construct_local_para(sizeof(uart_dsr_change_ind_struct),TD_UL);
	   		tmp->port = port;   		
	   		port_ptr = tmp;   		
	   	}	
	   	break;
	   	case MSG_ID_UART_ESCAPE_DETECTED_IND:   	
	   	{
	   		uart_escape_detected_ind_struct *tmp;      
	   		tmp = (uart_escape_detected_ind_struct *) 
	   		construct_local_para(sizeof(uart_escape_detected_ind_struct),TD_UL);
	   		tmp->port = port;   		
	   		port_ptr = tmp;   		
	   	}	
	   	break;
	   	default:
	   	break;   	
	   }         
      DRV_BuildPrimitive(UART_ilm,
                         MOD_DRV_HISR,//UARTPort[port].UART_id,
                         UARTPort[port].ownerid,
                         msgid,
                         port_ptr);

      msg_send_ext_queue(UART_ilm);
   }
}

void U_ClrRxBuffer(UART_PORT port, module_type ownerid)  /*clear sw buffer*/
{
   kal_uint32 savedMask;
#if defined(DRV_UART_6208_FC_SETTING)
   kal_uint16 UART_IER_HW_NORMALINTS[MAX_UART_PORT_NUM] = {
      UART1_IER_HW_NORMALINTS,
      UART2_IER_HW_NORMALINTS
   };
   kal_uint16 UART_IER_SW_NORMALINTS[MAX_UART_PORT_NUM] = {
      UART1_IER_SW_NORMALINTS,
      UART2_IER_SW_NORMALINTS
   };
#endif   /*DRV_UART_6208_FC_SETTING*/

	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   savedMask = SaveAndSetIRQMask();
   BWrite_addr(UARTPort[port].Rx_Buffer) = 0;
   BRead_addr(UARTPort[port].Rx_Buffer) = 0;

#if defined(DRV_UART_6208_FC_SETTING)
   if (UARTPort[port].DCB.flowControl == fc_none)
      DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_HW_NORMALINTS[port]);
   else
   {
      if (UARTPort[port].DCB.flowControl == fc_hw)
         DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_HW_NORMALINTS[port]);
      else
      {
         if (UARTPort[port].DCB.flowControl == fc_sw)
            DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_SW_NORMALINTS[port]);
      }
   }
#else /*!DRV_UART_6208_FC_SETTING*/
   if (UARTPort[port].DCB.flowControl == fc_none)
      DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
   else
   {
      if (UARTPort[port].DCB.flowControl == fc_hw)
         DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
      else
      {
         if (UARTPort[port].DCB.flowControl == fc_sw)
            DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_SW_NORMALINTS);
      }
   }
#endif   /*DRV_UART_6208_FC_SETTING*/
   send_Rxilm[port] = KAL_TRUE;
   RestoreIRQMask(savedMask);
}

void U_ClrTxBuffer(UART_PORT port, module_type ownerid)  /*clear sw buffer*/
{
   kal_uint32 savedMask;
#if defined(DRV_UART_6208_FC_SETTING)
   kal_uint16 UART_IER_HW_NORMALINTS[MAX_UART_PORT_NUM] = {
      UART1_IER_HW_NORMALINTS,
      UART2_IER_HW_NORMALINTS
   };
   kal_uint16 UART_IER_SW_NORMALINTS[MAX_UART_PORT_NUM] = {
      UART1_IER_SW_NORMALINTS,
      UART2_IER_SW_NORMALINTS
   };
#endif   /*DRV_UART_6208_FC_SETTING*/

	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   savedMask = SaveAndSetIRQMask();

   BWrite_addr(UARTPort[port].Tx_Buffer) = 0;
   BRead_addr(UARTPort[port].Tx_Buffer) = 0;

#if defined(DRV_UART_6208_FC_SETTING)
   if (UARTPort[port].DCB.flowControl == fc_none)
      DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_HW_NORMALINTS[port]);
   else
   {
      if (UARTPort[port].DCB.flowControl == fc_hw)
         DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_HW_NORMALINTS[port]);
      else
      {
         if (UARTPort[port].DCB.flowControl == fc_sw)
            DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_SW_NORMALINTS[port]);
      }
   }
#else /*!DRV_UART_6208_FC_SETTING*/
   if (UARTPort[port].DCB.flowControl == fc_none)
      DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
   else
   {
      if (UARTPort[port].DCB.flowControl == fc_hw)
         DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
      else
      {
         if (UARTPort[port].DCB.flowControl == fc_sw)
            DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_SW_NORMALINTS);
      }
   }
#endif   /*DRV_UART_6208_FC_SETTING*/
   send_Txilm[port] = KAL_TRUE;
   RestoreIRQMask(savedMask);
}
void UART_EnableTX(UART_PORT port, kal_bool enable)
{
#ifdef __UART3_SUPPORT__
   if (port <= uart_port3)
#else
   if (port <= uart_port2)
#endif
   {
      UARTPort[port].EnableTX= enable;
      if(enable == KAL_TRUE)
           EnableTxIntr(UART_BaseAddr[port]);
   }
}

void UART_SleepOnTx_Enable(UART_PORT port, UART_SLEEP_ON_TX enable_flag)
{
#ifdef __UART3_SUPPORT__
   if (port <= uart_port3)
#else
   if (port <= uart_port2)
#endif
   {
      #if defined(DRV_UART_SLEEP_NO_FC)
      UARTPort[port].sleep_on_tx = enable_flag;
      #else
      UARTPort[port].sleep_on_tx = uart_sleep_on_tx_allow;
      #endif
   }
}

kal_uint16 U_GetBytesAvail(UART_PORT port)
{	
   kal_uint16 real_count;   
   Buf_GetBytesAvail(&(UARTPort[port].Rx_Buffer),real_count);
   return real_count;
}

kal_uint16 U_GetTxRoomLeft(UART_PORT port)
{
   kal_uint16 real_count;   
   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);   
   return real_count;
}

#ifndef __PRODUCTION_RELEASE__
#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE"
#endif /* __MTK_TARGET__ */
#endif   /*__PRODUCTION_RELEASE__*/
#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
kal_uint16 U_GetTxISRRoomLeft(UART_PORT port)
{
   kal_uint16 real_count;
   
   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);

   /*temp solution: to cover L1 trace bug*/
   if(real_count<=16)
   	real_count=0;
   else
     real_count-=16;
     
   return real_count;
}
#endif /* Note: for ROM code */
#ifndef __PRODUCTION_RELEASE__
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif   /*__PRODUCTION_RELEASE__*/
/* Note: for ROM code start */
#ifdef __ROMSA_SUPPORT__
/*for MCUROM*/
kal_uint16 U_ROM_GetTxISRRoomLeft(UART_PORT port)
{
   kal_uint16 real_count;
   //#ifdef __DMA_UART_VIRTUAL_FIFO__
   if(UART_VFIFO_support[port])
   	real_count=DMA_GetVFIFO_Roomleft(UARTPort[port].Tx_DMA_Ch);
   //#else
   else
      Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);
   //#endif
   return real_count;
}
UARTStruct *U_ROM_GetUARTPort(UART_PORT port)
{
   return &UARTPort[port];
}

kal_uint8 *U_ROM_GetUART_TXilm(UART_PORT port)
{
   return &send_Txilm[port];
}

void U_ROM_InformUARTOwner(UART_PORT port)
{
   send_Txilm[port] = KAL_TRUE;

   //#ifdef __DMA_UART_VIRTUAL_FIFO__
   if(UART_VFIFO_support[port])
   DMA_EnableINT(UARTPort[port].Tx_DMA_Ch);
   //#endif
}


void U_ROM_PushDataToBuf(UART_PORT port, kal_uint8 *data, kal_uint32 real_count)
{
   kal_uint32  index;

   for (index = 0; index < real_count; index++)
   {
      //#ifdef __DMA_UART_VIRTUAL_FIFO__
      if(UART_VFIFO_support[port])
      {
      	DMA_TASK_PUSH(UARTPort[port].Tx_DMA_Ch,*(data+index));
      }	
      //#else      
      else   
      {   
      	Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),*(data+index));
      }	
      //#endif
   }
   if(UART_VFIFO_support[port]==KAL_FALSE)/*not support VFIFO*/
   U_ROM_EnableTxIntr(port);
}
void U_ROM_EnableTxIntr(UART_PORT port)
{
   switch(port)
   {
      case uart_port1:
         EnableTxIntr(UART_BaseAddr[port]);
         break;
      case uart_port2:
         if (UART2_Intr_is_Running == KAL_FALSE)
         {
            EnableTxIntr(UART_BaseAddr[port]);
         }
         break;
      case uart_port3:
         EnableTxIntr(UART_BaseAddr[port]);
         break;
      default:
         ASSERT(0);
         break;
   }
}
#endif

#if defined(DRV_UART2_OLD_DMA)
kal_bool UART2DMA_Ini(kal_bool Tx)      //(KAL_TRUE ==> transmit, KAL_FALSE ==> receive)
{
        if (Tx == KAL_TRUE)
        {
           if (DMA1_CheckRunStat())
                        return KAL_FALSE;

                if (DMA1_CheckITStat())
                        return KAL_FALSE;

                //Size = 8bit, sinc en, dinc disable, hw management, 1 trans/dma cycle, USB master,Interrupt enable
                DRV_WriteReg(DMA1_CONTRL,DMA_CON_UART2TxNormal);
        }
        else
        {
           if (DMA2_CheckRunStat())
                        return KAL_FALSE;

                if (DMA2_CheckITStat())
                        return KAL_FALSE;
                //Size = 8bit, sinc disable, dinc enable, hw management, 1 trans/dma cycle, USB master,Interrupt enable
                DRV_WriteReg(DMA2_CONTRL,DMA_CON_UART2RxNormal);
        }
        return KAL_TRUE;
}
#endif   /*DRV_UART2_OLD_DMA*/
/*
* FUNCTION
*  GetUARTByte
*
* DESCRIPTION
*     This function is to read data from UART
*
* CALLS
*  This function is to receive data through UART
*
* PARAMETERS
*  None
*
* RETURNS
*  the data from UART
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 U_GetUARTByte(UART_PORT port)
{

  kal_uint8 data;

  while(1)
  {
    kal_uint16 LSR;
    LSR = DRV_Reg(UART_LSR(UART_BaseAddr[port]));
    if (LSR & UART_LSR_DR)
    {
      data = (kal_uint8)DRV_Reg(UART_RBR(UART_BaseAddr[port]));
      

      if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
       (uart_support_autoescape()==KAL_FALSE&&UARTPort[port].DCB.flowControl==fc_sw))     
      {
         if(uart_escape_state==0)
         {
            if(data==0x77)            
               uart_escape_state=0x77;
            else            
               return data;
         }
         else if (uart_escape_state==0x77)
         {
            uart_escape_state=0x0; 
            switch(data)
            {
               case 0x01:
                  return UARTPort[port].DCB.xonChar;
                  break;
               case 0x02:
                  return UARTPort[port].DCB.xoffChar;
                  break;               
               case 0x03:
                  return 0x77;                  
                  break;      
               default:                     
                  break;      
            }                                            
         }                           
      }
     	else
     	{
     		return data;
     	}     	      
    }
  }
}

/*
* FUNCTION
*  PutUARTByte
*
* DESCRIPTION
*     This function is to write data to UART
*
* CALLS
*  This function is to transmit data through UART
*
* PARAMETERS
*  None
*
* RETURNS
*  the data from UART
*
* GLOBALS AFFECTED
*   external_global
*/
void PutUARTRingBufferData(UART_PORT port)
{
#ifndef __DMA_UART_VIRTUAL_FIFO__
   
   kal_uint16  index;
   kal_uint16  real_count;
   kal_uint8   TX_DATA;
   kal_uint32 UART_BASE = UART_BaseAddr[port];
  
   /*ISR*/
   Buf_GetBytesAvail(&(UARTPort[port].Tx_Buffer_ISR),real_count);
   for (index = 0;index < real_count;index++)
   {
         Buf_Pop(&(UARTPort[port].Tx_Buffer_ISR),TX_DATA);
         DRV_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
   }
   /*Task*/
   Buf_GetBytesAvail(&(UARTPort[port].Tx_Buffer),real_count);
   for (index = 0;index < real_count;index++)
   {
         Buf_Pop(&(UARTPort[port].Tx_Buffer),TX_DATA);
         DRV_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
   }
#endif   
}

void U_PutUARTByte(UART_PORT port, kal_uint8 data)
{
  kal_uint16 LSR;

  while(1)
  {
    LSR = DRV_Reg(UART_LSR(UART_BaseAddr[port]));
    if ( LSR & UART_LSR_THRE )
    {
      DRV_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)data);
      break;
    }
  }
}
void PutUARTData(UART_PORT port, kal_uint8 escape_char, kal_uint8 data)
{
   
   if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
       (uart_support_autoescape()==KAL_FALSE))        
   {
      if (data == UARTPort[port].DCB.xonChar)
   	{
         PutUARTByte(port, escape_char);
         PutUARTByte(port, 0x01);            
   	}
   	else if (data == UARTPort[port].DCB.xoffChar)
   	{
   		PutUARTByte(port, escape_char);
         PutUARTByte(port, 0x02);            
   	}
   	else if (data == escape_char)
   	{
         PutUARTByte(port, escape_char);
         PutUARTByte(port, 0x03);            
   	}
   	else
   	{
   		PutUARTByte(port, data);
   	}         
   }
   else
   {
   	PutUARTByte(port, data);
   }   
}
void U_PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len)
{
   kal_uint16 index;
   for(index=0;index<len;index++)
      PutUARTByte(port,*(data+index));
}
void PutUARTDatas(UART_PORT port, kal_uint8 escape_char, kal_uint8 *data,kal_uint16 len)
{
   kal_uint16 index;
   for(index=0;index<len;index++)
      PutUARTData(port,escape_char,*(data+index));
}

void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid)
{
   kal_uint32   tmp_div;
   kal_uint16   divisor;
   kal_uint16   byte;
   kal_uint32   remainder;
   kal_uint32   UART_BASE = UART_BaseAddr[port];
   kal_uint32	uart_clock=0;
   
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   #ifdef DCM_ENABLE   
   #ifdef __BT_USE_UART2__
   if(port!=uart_port3 && port!=uart_port2)	
   {
    	DRV_WriteReg(UART_RATE_FIX_REG(UART_BASE),0xf);/*13*/   
      uart_clock=13000000;/*fixed uart clock for DCM*/
   } 	
   else
      uart_clock=UART_CLOCK;
   #else  
   if(port!=uart_port3)	
   {
    	DRV_WriteReg(UART_RATE_FIX_REG(UART_BASE),0xf);/*13*/   
      uart_clock=13000000;/*fixed uart clock for DCM*/
   } 	
   else
      uart_clock=UART_CLOCK;   
   #endif/*__BT_USE_UART2__*/ 
   #else
   uart_clock=UART_CLOCK;
   #endif/* DCM_ENABLE*/
   
    	

   if ( baudrate != UART_BAUD_AUTO ) /* no autobaud */
   {
                if (baudrate <= UART_BAUD_115200)
                {
              /* Set BaudRate   */             
              tmp_div = (uart_clock)/(16*baudrate);
              divisor =  (kal_uint16)tmp_div;

              remainder = (uart_clock)%(16*baudrate);
              
              if (remainder >= (8*baudrate))
                 divisor =  (kal_uint16)(tmp_div+1);
              else
                 divisor =  (kal_uint16)tmp_div;



#if defined(DRV_UART_HIGH_SPEED)
             DRV_WriteReg(UART_RATE_STEP(UART_BASE),0x0);
#endif

              /* GPIO_WriteAll(divisor); */
              byte = DRV_Reg(UART_LCR(UART_BASE));     /* DLAB start */
              DRV_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));

              DRV_WriteReg(UART_DLL(UART_BASE),(divisor & 0x00ff));
              DRV_WriteReg(UART_DLH(UART_BASE),((divisor >> 8)&0x00ff));
              DRV_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */
        #ifndef __PRODUCTION_RELEASE__
              uart_lcr_save[port] = byte;
        #endif   /*__PRODUCTION_RELEASE__*/
         }
#if defined(DRV_UART_HIGH_SPEED)
                else    //support high speed uart baudrate > 115200
                 {
         #if !defined(DRV_UART_SPEED_SAMPLE_COUNT)
        tmp_div = (uart_clock)/(4*baudrate);
        divisor =  (kal_uint16)tmp_div;
                                remainder = (uart_clock)%(4*baudrate);
              if (remainder >= (2*baudrate))
                 divisor =  (kal_uint16)(tmp_div+1);
              else
                 divisor =  (kal_uint16)tmp_div;

                                DRV_WriteReg(UART_RATE_STEP(UART_BASE),0x02);
              byte = DRV_Reg(UART_LCR(UART_BASE));     /* DLAB start */
              DRV_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));
              DRV_WriteReg(UART_DLL(UART_BASE),(divisor & 0x00ff));
              DRV_WriteReg(UART_DLH(UART_BASE),((divisor >> 8)&0x00ff));
              DRV_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */
         #else /* !defined(DRV_UART_SPEED_SAMPLE_COUNT) */
               kal_uint16   high_speed_div, data;
               kal_uint16	 sample_count, sample_point;

               data=(kal_uint16)(uart_clock/baudrate);
               high_speed_div = (data>>8) + 1; // divided by 256
      		         
		         tmp_div=uart_clock/(baudrate*high_speed_div);
		         divisor =  (kal_uint16)tmp_div;

               remainder = (uart_clock)%(high_speed_div*baudrate);
		         /*get (sample_count+1)*/
               if (remainder >= ((baudrate)*(high_speed_div))>>1)
                  divisor =  (kal_uint16)(tmp_div+1);
               else
                  divisor =  (kal_uint16)tmp_div;		      
         
               sample_count=divisor-1;
      
               /*get the sample point*/
               sample_point=(sample_count-1)>>1;
      
               /*configure register*/
               DRV_WriteReg(UART_RATE_STEP(UART_BASE),0x3);

               byte = DRV_Reg(UART_LCR(UART_BASE));     /* DLAB start */
               DRV_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));

               DRV_WriteReg(UART_DLL(UART_BASE),(high_speed_div & 0x00ff));
               DRV_WriteReg(UART_DLH(UART_BASE),((high_speed_div >> 8)&0x00ff));

               DRV_WriteReg(UART_STEP_COUNT(UART_BASE),sample_count);
               DRV_WriteReg(UART_SAMPLE_COUNT(UART_BASE),sample_point);
               DRV_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */      
         #endif /* !defined(DRV_UART_SPEED_SAMPLE_COUNT) */
                 }
#endif

        }
#if defined(DRV_UART_AUTO_BAUD)
        else
        {
           switch (uart_clock)
           {
              case   13000000:
              	 DRV_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_13M);
              	 DRV_WriteReg(UART_AUTOBAUD_EN(UART_BASE),AUTOBAUD_EN);
              break;
              case   26000000:
              	 DRV_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_26M);
              	 DRV_WriteReg(UART_AUTOBAUD_EN(UART_BASE),AUTOBAUD_EN);
              break;
              case   52000000:
              	 DRV_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_52M);
              	 DRV_WriteReg(UART_AUTOBAUD_EN(UART_BASE),AUTOBAUD_EN);
              break;
              default:
              break;
           }
              
        }
#endif
}
/*This function is to cover 6218B/6219 hw bug.
UART should not send receiving data to its FIFO when doing auto baud*/
void U_SetAutoBaud_Div(UART_PORT port, module_type ownerid)
{
   kal_uint32   UART_BASE = UART_BaseAddr[port];
   kal_uint8 byte;

	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   /*TY adds this compile option 20041006*/   
   if(uart_support_autoescape()==KAL_FALSE)
   {
      byte = DRV_Reg(UART_LCR(UART_BASE));     /* DLAB start */
      DRV_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));
      
      DRV_WriteReg(UART_DLL(UART_BASE),0xff);
      DRV_WriteReg(UART_DLH(UART_BASE),0xff);
      DRV_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */   
   }      
}   

void U_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{
   kal_uint16   byte;
   kal_uint16   IER;
   kal_uint32   savedMask;
   kal_uint32   UART_BASE = UART_BaseAddr[port];

#ifdef DRV_DEBUG
   if (uart_initialize[port] && (UARTPort[port].ownerid != ownerid))
       return;
#endif /*DRV_DEBUG*/
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   savedMask = SaveAndSetIRQMask();
   IER = DRV_Reg(UART_IER(UART_BASE));
   DRV_WriteReg(UART_IER(UART_BASE),UART_IER_ALLOFF);
   RestoreIRQMask(savedMask);

   U_SetBaudRate(port, UART_Config->baud, ownerid);

   /* Setup N81 */
   byte = DRV_Reg(UART_LCR(UART_BASE));     /* DLAB start */
   byte &= ~UART_DATA_MASK;
   switch(UART_Config->dataBits)
   {
      case len_5:
         byte |= UART_WLS_5;
         break;

      case len_6:
         byte |= UART_WLS_6;
         break;

      case len_7:
         byte |= UART_WLS_7;
         break;

      case len_8:
         byte |= UART_WLS_8;
         break;

      default:
         break;
   }
	byte &= ~UART_STOP_MASK;
   switch(UART_Config->stopBits)
   {
      case sb_1:
         byte |= UART_1_STOP;
         break;

      case sb_2:
         byte |= UART_2_STOP;
         break;

      case sb_1_5:
         byte |= UART_1_5_STOP;
         break;

      default:
         break;
   }

   byte &= ~UART_PARITY_MASK;
   switch(UART_Config->parity)
   {
      case pa_none:
         byte |= UART_NONE_PARITY;
         break;

      case pa_odd:
         byte |= UART_ODD_PARITY;
         break;

      case pa_even:
         byte |= UART_EVEN_PARITY;
         break;

      case pa_space:
         byte |= UART_SPACE_PARITY;
         break;

      default:
         break;
   }
   DRV_WriteReg(UART_LCR(UART_BASE),byte);            /* DLAB End */
   /* flowControl */
   byte = DRV_Reg(UART_LCR(UART_BASE));
   /* DRV_WriteReg(UART_LCR,(byte | UART_LCR_DLAB));   // DLAB start */
   DRV_WriteReg(UART_LCR(UART_BASE),0xbf);            /* Enchance setting */
   switch(UART_Config->flowControl)
   {
      case fc_none:
         DRV_WriteReg(UART_EFR(UART_BASE),UART_EFR_ALLOFF);
         break;

      case fc_hw:
#if defined(DRV_UART_6208_FC_SETTING)
         if (port == uart_port1)
            DRV_WriteReg(UART_EFR(UART_BASE),UART_EFR_AutoRTSCTS);
         else
            DRV_WriteReg(UART_EFR(UART_BASE),UART_EFR_ALLOFF);
#else /*!DRV_UART_6208_FC_SETTING*/
         DRV_WriteReg(UART_EFR(UART_BASE),UART_EFR_AutoRTSCTS);
#endif   /*DRV_UART_6208_FC_SETTING*/
         break;

      case fc_sw:
         DRV_WriteReg(UART_EFR(UART_BASE),UART_EFR_SWFlowCtrlX1);                               
         if(uart_support_autoescape()==KAL_TRUE)
         {  
            /*For META, Dont use auto escape*/ 
				if(stack_query_boot_mode() != FACTORY_BOOT)
				{
               #if !defined(DRV_UART_NO_AUTOESCAPE)
               /*For AutoEscape*/
               DRV_WriteReg(UART_ESCAPE_DAT(UART_BaseAddr[port]),0x77);
               DRV_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x1);
               #endif
            }
         }              
         break;

      default:    
         break;
   }
   #ifdef __DMA_UART_VIRTUAL_FIFO__
   if(UART_VFIFO_support[port])
     	DRV_WriteReg(UART_RXDMA(UART_BASE),UART_RXDMA_ON);
   #endif
   /* XON and XOFF characters */
   DRV_WriteReg(UART_XON1(UART_BASE),UART_Config->xonChar);
   DRV_WriteReg(UART_XOFF1(UART_BASE),UART_Config->xoffChar);
   DRV_WriteReg(UART_XON2(UART_BASE),UART_Config->xonChar);
   DRV_WriteReg(UART_XOFF2(UART_BASE),UART_Config->xoffChar);
   DRV_WriteReg(UART_LCR(UART_BASE),byte);         /* DLAB End */
#ifndef __PRODUCTION_RELEASE__
   uart_lcr_save[port] = byte;
#endif   /*__PRODUCTION_RELEASE__*/

   if (UART_Config->DSRCheck)
   {
      if (DRV_Reg(UART1_MSR) & UART_MSR_DSR)
      {
         switch(port)
         {
            case uart_port1:
               DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
               break;
            case uart_port2:
               DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
               break;
#ifdef __UART3_SUPPORT__
            case uart_port3:               
               #if ( (!defined(MT6217)) && (!defined(MT6218B)) )              
               DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);               
               #endif
               break;
#endif   /*__UART3_SUPPORT__*/
            default:
               ASSERT(0);
               break;
         }
      }
      else
      {
         switch(port)
         {
            case uart_port1:
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
               break;
            case uart_port2:
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
               break;
#ifdef __UART3_SUPPORT__
            case uart_port3:               
               #if !defined(DRV_UART_NO_UART3_PDN)
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);       
               #endif        
               break;
#endif   /*__UART3_SUPPORT__*/
            default:
               ASSERT(0);
               break;
         }
      }
   }
#if 0 /* power down control is moved to UART_TurnOnPower(). */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UART3_SUPPORT__
/* under construction !*/
            #if !defined(DRV_UART_NO_UART3_PDN)
/* under construction !*/
            #endif
/* under construction !*/
#endif   /*__UART3_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   kal_mem_cpy( &UARTPort[port].DCB, UART_Config, sizeof(UARTDCBStruct) );

   savedMask = SaveAndSetIRQMask();
   DRV_WriteReg(UART_IER(UART_BASE),IER);
   RestoreIRQMask(savedMask);
}

void U_ReadDCBConfig (UART_PORT port, UARTDCBStruct *DCB)
{
   kal_mem_cpy( DCB, &UARTPort[port].DCB, sizeof(UARTDCBStruct) );
}

void UART_loopback(UART_PORT port)
{
  kal_uint16 tmp;
  kal_uint32 UART_BASE = UART_BaseAddr[port];
  /* Enable Loop Back test!! */
  tmp = DRV_Reg(UART_MCR(UART_BASE));
  tmp |= UART_MCR_LOOPB;
  DRV_WriteReg(UART_MCR(UART_BASE),tmp);
}

void UART_HWInit(UART_PORT port)
{
   kal_uint8 tmp;
   UARTDCBStruct *DCBdefault;
   UARTDCBStruct  UART_DefaultConfig =
   {
      UART_BAUD_115200,    /* baud; */
      len_8,               /* dataBits; */
      sb_1,                /*stopBits; */
      pa_none,             /* parity; */
      fc_none,             /*no flow control*/
      0x11,                /* xonChar; */
      0x13,                /* xoffChar; */
      KAL_FALSE
   };
   kal_uint32 UART_BASE = UART_BaseAddr[port];
      
#ifdef __ROMSA_SUPPORT__
   /*for MCUROM*/
   #ifdef DRV_DEBUG
   UART_debug=KAL_TRUE;
   #else
   UART_debug=KAL_FALSE;
   #endif
   #ifdef __DMA_UART_VIRTUAL_FIFO__
   UART_Virtual_FIFO=KAL_TRUE;
   #else
   UART_Virtual_FIFO=KAL_FALSE;
   #endif
#endif
   
   switch(port)
   {
      case uart_port1:
         #if defined(DRV_MISC_PDN_NO_SET_CLR)
            DRV_Reg(DRVPDN_CON1) &= ~(DRVPDN_CON1_UART1);
         #else
            DRV_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_UART1);
         #endif
			#ifdef __DMA_UART_VIRTUAL_FIFO__
			if(UART_VFIFO_support[port])
			{
			   DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, UARTPort[uart_port1].Rx_DMA_Ch, KAL_FALSE);
		      DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, UARTPort[uart_port1].Tx_DMA_Ch, KAL_TRUE);
			   //UARTPort[port].Rx_DMA_Ch = VDMA_UART1RX_CH;
			   //UARTPort[port].Tx_DMA_Ch = VDMA_UART1TX_CH;
			}   
      	#endif
         break;
      case uart_port2:
         #ifdef DCM_ENABLE
         #ifdef __BT_USE_UART2__
            uart2_dcm_handle=DCM_GetHandle();
         #endif
         #endif
         #if defined(DRV_MISC_PDN_NO_SET_CLR)
            DRV_Reg(DRVPDN_CON1) &= ~(DRVPDN_CON1_UART2);
         #else
            DRV_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_UART2);
         #endif
			#ifdef __DMA_UART_VIRTUAL_FIFO__
			if(UART_VFIFO_support[port])
			{
			   DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, UARTPort[uart_port2].Rx_DMA_Ch, KAL_FALSE);
		      DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, UARTPort[uart_port2].Tx_DMA_Ch, KAL_TRUE);
			   //DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, VDMA_UART2RX_CH, KAL_FALSE);
		      //DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, (UART_rings->ring[port].tx_len /*+UART_rings->ring[port].txisr_len*/), VDMA_UART2TX_CH, KAL_TRUE);		   
			   //UARTPort[port].Rx_DMA_Ch = VDMA_UART2RX_CH;
			   //UARTPort[port].Tx_DMA_Ch = VDMA_UART2TX_CH;
			}   
        #endif
         break;
#ifdef __UART3_SUPPORT__
      case uart_port3:         
      	 #ifdef DCM_ENABLE
         uart3_dcm_handle=DCM_GetHandle();
         #endif
         #if !defined(DRV_UART_NO_UART3_PDN)
            #if defined(DRV_MISC_PDN_NO_SET_CLR)
               DRV_Reg(DRVPDN_CON1) &= ~(DRVPDN_CON1_UART3);
            #else
               DRV_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_UART3);
            #endif
         #endif
         #ifdef __DMA_UART_VIRTUAL_FIFO__
         if(UART_VFIFO_support[port])
         {
            DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, UARTPort[uart_port3].Rx_DMA_Ch, KAL_FALSE);
		      DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, UARTPort[uart_port3].Tx_DMA_Ch, KAL_TRUE);
			   //DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, VDMA_UART3RX_CH, KAL_FALSE);
		      //DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, VDMA_UART3TX_CH, KAL_TRUE);		   
			   //UARTPort[port].Rx_DMA_Ch = VDMA_UART3RX_CH;
			   //UARTPort[port].Tx_DMA_Ch = VDMA_UART3TX_CH;
			}   
         #endif/*__DMA_UART_VIRTUAL_FIFO__*/         
         break;
#endif   /*__UART3_SUPPORT__*/
      default:
         ASSERT(0);
         break;
   }

   DCBdefault = (UARTDCBStruct *)&UART_DefaultConfig;
   /* Setup N81,(UART_WLS_8 | UART_NONE_PARITY | UART_1_STOP) = 0x03 */
   /* BaudRate and autoflowcontrol */
   U_SetDCBConfig(port, DCBdefault, UARTPort[port].ownerid);

#ifdef UART_HIGHSPEED_TEST
   DRV_WriteReg(UART_RATE_STEP(UART_BASE),0x01);
   DRV_WriteReg(UART_LCR(UART_BASE),0xbf);
   DRV_WriteReg(UART_DLL(UART_BASE),0x07);
   DRV_WriteReg(UART_LCR(UART_BASE),0x03);
#endif   /*UART_HIGHSPEED_TEST*/
   /* SER_SetConfig((char *)DCBdefault); */

   tmp = DRV_Reg(UART_LSR(UART_BASE));
   tmp = DRV_Reg(UART_MSR(UART_BASE));
   /* DTR , RTS is on, data will be coming,Output2 is high */
   DRV_WriteReg(UART_MCR(UART_BASE),UART_MCR_Normal);
   DRV_WriteReg(UART_IER(UART_BASE),UART_IER_ALLOFF);
   /* Enable UART int. controller */
   /* UART1_IER, enable RDA, RLS, MS , disable THR interrupt */
   /* DRV_WriteReg(UART1_IER,UART_IER_RDA); */
   GPTI_GetHandle(&UARTPort[port].handle);
   UARTPort[port].Rec_state = UART_RecNormal;
   UARTPort[port].port_no = port;

   UARTPort[port].sleep_on_tx = uart_sleep_on_tx_allow;
   UARTPort[port].EnableTX= KAL_TRUE;
   UARTPort[port].power_on= KAL_TRUE;
   #if defined(DRV_UART_SLEEP_MODE)
   DRV_WriteReg(UART_SLEEP_EN(UART_BASE),KAL_TRUE);
   #endif
}

kal_bool U_Open(UART_PORT port, module_type ownerid)
{
   kal_uint32 UART_BASE = UART_BaseAddr[port];
   kal_uint16  MSR;
   kal_uint8 byte;
   #ifndef __DMA_UART_VIRTUAL_FIFO__
   kal_uint8 i;
   #endif
#if defined(DRV_UART_6208_FC_SETTING)
   kal_uint16 UART_IER_HW_NORMALINTS[MAX_UART_PORT_NUM] = {
      UART1_IER_HW_NORMALINTS,
      UART2_IER_HW_NORMALINTS
   };
   kal_uint16 UART_IER_SW_NORMALINTS[MAX_UART_PORT_NUM] = {
      UART1_IER_SW_NORMALINTS,
      UART2_IER_SW_NORMALINTS
   };
#endif   /*DRV_UART_6208_FC_SETTING*/

	if(port == uart_port_null)
		return KAL_FALSE;
		
	#ifdef DRV_DEBUG
	UARTPort[port].ownerid = ownerid;
	if (uart_initialize[port])
	       return KAL_TRUE;
	else
	       uart_initialize[port] = KAL_TRUE;
	#endif /*DRV_DEBUG*/
	
   if (UARTPort[port].initialized &&
   	(UARTPort[port].ownerid != MOD_UART1_HISR + port))
      return KAL_FALSE;
   UARTPort[port].initialized = KAL_TRUE;
   UARTPort[port].ownerid = ownerid;
   
   #ifndef __DMA_UART_VIRTUAL_FIFO__
	/* initialize the ring buffer according to the owner */
	for(i = 0; i < MAX_UART_PORT_NUM; i++)
	{
		if(UART_rings->ring[i].owerid == ownerid)
		{
			UARTPort[port].RingBuffers.rx_buffer = UART_rings->ring[i].rx_adrs;
			UARTPort[port].RingBuffers.tx_buffer = UART_rings->ring[i].tx_adrs;
			Buf_init(&(UARTPort[port].Rx_Buffer),(kal_uint8 *)(UARTPort[port].RingBuffers.rx_buffer),(kal_uint16)UART_rings->ring[i].rx_len);
		   Buf_init(&(UARTPort[port].Tx_Buffer),(kal_uint8 *)(UARTPort[port].RingBuffers.tx_buffer),(kal_uint16)UART_rings->ring[i].tx_len);   		  		   
		
			//#ifndef __DMA_UART_VIRTUAL_FIFO__
			if(UART_VFIFO_support[port]==KAL_FALSE)
			{
			UARTPort[port].RingBuffers.txISR_buffer = UART_rings->ring[i].txisr_adrs;
			Buf_init(&(UARTPort[port].Tx_Buffer_ISR),(kal_uint8 *)(UARTPort[port].RingBuffers.txISR_buffer),(kal_uint16)UART_rings->ring[i].txisr_len);						
			}   
		   //#endif // __DMA_UART_VIRTUAL_FIFO__
		   
		   break;
		}
	}
	
	/* the owner is not defined in ring buffer, use default=> ring[0]: com1, ring[1] com2 ... */
	if(i == MAX_UART_PORT_NUM)
	{
	   #if (defined(__MAUI_BASIC__)) && (defined(MONZA)) 
		#ifdef __UART3_SUPPORT__
		EXT_ASSERT((ownerid == MOD_UART1_HISR ||ownerid == MOD_UART2_HISR||ownerid == MOD_UART3_HISR),ownerid,0,0);			
		#else
		EXT_ASSERT((ownerid == MOD_UART1_HISR ||ownerid == MOD_UART2_HISR),ownerid,0,0);			
		#endif	
		#endif
   #endif // __DMA_UART_VIRTUAL_FIFO__
		
		UARTPort[port].RingBuffers.rx_buffer = UART_rings->ring[port].rx_adrs;
		UARTPort[port].RingBuffers.tx_buffer = UART_rings->ring[port].tx_adrs;
		Buf_init(&(UARTPort[port].Rx_Buffer),(kal_uint8 *)(UARTPort[port].RingBuffers.rx_buffer),(kal_uint16)UART_rings->ring[port].rx_len);
	   Buf_init(&(UARTPort[port].Tx_Buffer),(kal_uint8 *)(UARTPort[port].RingBuffers.tx_buffer),(kal_uint16)UART_rings->ring[port].tx_len);   
		//#ifndef __DMA_UART_VIRTUAL_FIFO__	
		if(UART_VFIFO_support[port]==KAL_FALSE)
		{
		UARTPort[port].RingBuffers.txISR_buffer = UART_rings->ring[port].txisr_adrs;
		Buf_init(&(UARTPort[port].Tx_Buffer_ISR),(kal_uint8 *)(UARTPort[port].RingBuffers.txISR_buffer),(kal_uint16)UART_rings->ring[port].txisr_len);				
	   }
		//#endif	   
   #ifndef __DMA_UART_VIRTUAL_FIFO__
	}
   #endif // __DMA_UART_VIRTUAL_FIFO__
      
   MSR = DRV_Reg(UART_MSR(UART_BASE));
   if (MSR & UART_MSR_DSR)
      UARTPort[port].DSR = io_high;
   else
      UARTPort[port].DSR = io_low;

   #ifdef __DMA_UART_VIRTUAL_FIFO__
   if(UART_VFIFO_support[port])
   {
   	/* Rx FIFO trigger = 1, Tx FIFO trigger is 1, FIFO enable and initialized,and using DMA mode 0.*/
   	// while using virtual fifo, dma mode must be set 0!!!
   	DRV_WriteReg(UART_FCR(UART_BASE),UART_VFIFO_DEPTH);
   //#else
   }
   else
   {
   	/* Rx FIFO trigger = 62, Tx FIFO trigger is 16, and FIFO enable. */
   	DRV_WriteReg(UART_FCR(UART_BASE),UART_FCR_Normal);
   }   
   #else
   /* Rx FIFO trigger = 62, Tx FIFO trigger is 16, and FIFO enable. */
   DRV_WriteReg(UART_FCR(UART_BASE),UART_FCR_Normal);
   #endif //__DMA_UART_VIRTUAL_FIFO__

#if defined(DRV_UART_6208_FC_SETTING)
   if (UARTPort[port].DCB.flowControl == fc_none)
      DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_HW_NORMALINTS[port]);
   else
   {
      if (UARTPort[port].DCB.flowControl == fc_hw)
         DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_HW_NORMALINTS[port]);
      else
      {
         if (UARTPort[port].DCB.flowControl == fc_sw)
            DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_SW_NORMALINTS[port]);
      }
   }
#else /*!DRV_UART_6208_FC_SETTING*/
	//#ifdef __DMA_UART_VIRTUAL_FIFO__
	if(UART_VFIFO_support[port])
	{
		#ifdef __DMA_UART_VIRTUAL_FIFO__
		// only turn on receive interrupt
		DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_VFIFO);
		DMA_Stop(UARTPort[port].Rx_DMA_Ch);
		DMA_Stop(UARTPort[port].Tx_DMA_Ch);
		DMA_Start(UARTPort[port].Rx_DMA_Ch);
		DMA_Start(UARTPort[port].Tx_DMA_Ch);		
   	DRV_WriteReg(UART_RXDMA(UART_BASE),UART_RXDMA_ON);
   	#else
   	ASSERT(0);/*wrong configuration*/
   	#endif
   }
   else
   {	
	   //#else //__DMA_UART_VIRTUAL_FIFO__
   	if (UARTPort[port].DCB.flowControl == fc_none)
   	   DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
   	else
   	{
   	   if (UARTPort[port].DCB.flowControl == fc_hw)
   	      DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
   	   else
   	   {
   	      if (UARTPort[port].DCB.flowControl == fc_sw)
   	      {
   	         DRV_WriteReg(UART_IER(UART_BaseAddr[port]),IER_SW_NORMALINTS);                        
   	         if(uart_support_autoescape()==KAL_TRUE)
   	         {
   	            /*For META, Dont use auto escape*/
					   if(stack_query_boot_mode() != FACTORY_BOOT)
					   {
   	               /*For AutoEscape*/
   	               byte = DRV_Reg(UART_LCR(UART_BASE));
   	               // DLAB start */
   	               DRV_WriteReg(UART_LCR(UART_BASE),0xbf);            /* Enchance setting */
   	               DRV_WriteReg(UART_XON1(UART_BaseAddr[port]),0x11);
   	               DRV_WriteReg(UART_XON2(UART_BaseAddr[port]),0x11);
   	               DRV_WriteReg(UART_XOFF1(UART_BaseAddr[port]),0x13);
   	               DRV_WriteReg(UART_XOFF2(UART_BaseAddr[port]),0x13);
                     #if !defined(DRV_UART_NO_AUTOESCAPE)
   	               DRV_WriteReg(UART_ESCAPE_DAT(UART_BaseAddr[port]),0x77);
   	               DRV_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x1);
   	               #endif
   	               DRV_WriteReg(UART_LCR(UART_BASE),byte);            /* Enchance setting */            
   	            }
   	         }              
   	      }   
   	   }
   	}
   }      
	//#endif //__DMA_UART_VIRTUAL_FIFO__
#endif   /*DRV_UART_6208_FC_SETTING*/
    /*For excetpion, we dont need to do the following */
    #ifdef __MTK_TARGET__
    if(INT_QueryExceptionStatus())
      return KAL_TRUE; 
   #endif   

   /* UARTPort[port].callback = FunCallBack; */
   /* UARTPort[port].initialized = KAL_TRUE; */
   /* initializ our ringbuffer,  */
   send_Rxilm[port] = KAL_TRUE;
   if (UARTPort[port].hisr == NULL)
   {
      //UARTPort[port].hisr = kal_create_hisr("UARTx_HISR",1,512,UART_HISR[port],NULL);
      UARTPort[port].hisr=(void*)0x1234;
      if(port==uart_port1)
         DRV_Register_HISR(DRV_UART1_HISR_ID,UART_HISR[port]);
      if(port==uart_port2)
         DRV_Register_HISR(DRV_UART2_HISR_ID,UART_HISR[port]);
      if(port==uart_port3)
         DRV_Register_HISR(DRV_UART3_HISR_ID,UART_HISR[port]);      
   }   

   switch(port)
   {
      case uart_port1:
         UARTPort[port].UART_id = MOD_UART1_HISR;
         IRQ_Register_LISR(IRQ_UART1_CODE, UART1_LISR,"UART1");
         IRQSensitivity(IRQ_UART1_CODE,LEVEL_SENSITIVE);
         if (UARTPort[port].power_on == KAL_TRUE)
            IRQUnmask(IRQ_UART1_CODE);
         break;
      case uart_port2:
         #if defined(DRV_UART2_NORMAL_DMA)
         //#ifndef __DMA_UART_VIRTUAL_FIFO__
         if(UART_VFIFO_support[uart_port2]==KAL_FALSE)
         {
            /*DMA initialize*/
            if (uart2_dmaport == 0)
               uart2_dmaport = DMA_GetChannel(DMA_UART2TX);
            uart2_txmenu.TMOD.burst_mode = 0;
            uart2_txmenu.TMOD.cycle = 0;
            uart2_txmenu.master = DMA_UART2TX;
            uart2_txmenu.addr = NULL;  /*1*/
            uart2_txmenu.WPPT = NULL; /*2*/
            uart2_txmenu.WPTO = NULL;     /*3*/

            uart2_input.type = DMA_HWTX_RINGBUFF;
            uart2_input.size = DMA_BYTE;
            uart2_input.menu = &uart2_txmenu;
            uart2_input.count = 0;       /*4*/
            uart2_input.callback = NULL;   /*5*/
         }   
         //#endif //__DMA_UART_VIRTUAL_FIFO__
         #endif   /*DRV_UART2_NORMAL_DMA*/
         UARTPort[port].UART_id = MOD_UART2_HISR;
         IRQ_Register_LISR(IRQ_UART2_CODE, UART2_LISR,"UART2");
         IRQSensitivity(IRQ_UART2_CODE,LEVEL_SENSITIVE);
         if (UARTPort[port].power_on == KAL_TRUE)
            IRQUnmask(IRQ_UART2_CODE);
         break;

#ifdef __UART3_SUPPORT__
      case uart_port3:
         UARTPort[port].UART_id = MOD_UART3_HISR;
         IRQ_Register_LISR(IRQ_UART3_CODE, UART3_LISR,"UART3");
         IRQSensitivity(IRQ_UART3_CODE,LEVEL_SENSITIVE);
         if (UARTPort[port].power_on == KAL_TRUE)
         IRQUnmask(IRQ_UART3_CODE);
         break;
#endif   /*__UART3_SUPPORT__*/
      default:
         ASSERT(0);
         break;
   }
   // enable virtual fifo

   return KAL_TRUE;
}
void U_Purge(UART_PORT port, UART_buffer dir, module_type ownerid)
{
   kal_uint32 UART_BASE = UART_BaseAddr[port];

	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   /* Rx FIFO trigger = 62, Tx FIFO trigger is 16, and FIFO enable. */
   if (dir == RX_BUF)
      DRV_WriteReg(UART_FCR(UART_BASE),(UART_FCR_Normal & ~UART_FCR_CLRT));
   else
      DRV_WriteReg(UART_FCR(UART_BASE),(UART_FCR_Normal & ~UART_FCR_CLRR));
}
void U_Close(UART_PORT port, module_type ownerid)
{
   kal_uint32 UART_BASE = UART_BaseAddr[port];
   
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   UARTPort[port].initialized = KAL_FALSE;
   UARTPort[port].ownerid = MOD_UART1_HISR+port;

   switch(port)
   {
      case uart_port1:
         IRQMask(IRQ_UART1_CODE);
         break;
      case uart_port2:
         IRQMask(IRQ_UART2_CODE);
         break;
#ifdef __UART3_SUPPORT__
      case uart_port3:
         IRQMask(IRQ_UART3_CODE);
         break;
#endif   /*__UART3_SUPPORT__*/
      default:
         ASSERT(0);
         break;
   }
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if(UART_VFIFO_support[port])
   {
		DMA_Stop(UARTPort[port].Rx_DMA_Ch);
		DMA_Stop(UARTPort[port].Tx_DMA_Ch);
   	DRV_WriteReg(UART_RXDMA(UART_BASE),UART_RXDMA_OFF);
   }	
#endif
   DRV_WriteReg(UART_IER(UART_BASE),UART_IER_ALLOFF);
   U_ConfigEscape(port, 0xff, 0, UARTPort[port].ownerid);
   U_ClrRxBuffer(port, UARTPort[port].ownerid);  /*clear sw RX buffer*/
   U_ClrTxBuffer(port, UARTPort[port].ownerid);  /*clear sw TX buffer*/
   U_Purge(port, RX_BUF, UARTPort[port].ownerid);/*clear sw RX FIFO*/
   U_Purge(port, TX_BUF, UARTPort[port].ownerid);/*clear sw TX FIFO*/
}

void U_SetOwner (UART_PORT port, kal_uint8 ownerid)
{
   #ifndef __PRODUCTION_RELEASE__
   kal_prompt_trace(MOD_UART1_HISR,"port: %d, ownerid: %d", port, ownerid);
   #endif   
   UARTPort[port].ownerid = ownerid;
}

module_type U_GetOwnerID(UART_PORT port)
{
	return UARTPort[port].ownerid;
}

void U_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid)
{
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   UARTPort[port].ESCDet.EscChar = EscChar;
   UARTPort[port].ESCDet.GuardTime = ESCGuardtime;
   if (UARTPort[port].ESCDet.GuardTime)
   {
      UARTPort[port].Rec_state = UART_RecNormal;
      GPTI_StartItem(UARTPort[port].handle,
                     (UARTPort[port].ESCDet.GuardTime/10),
                     UART_Calback,
                     &UARTPort[port]);
   }
}

void U_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid)    {}   /*NULL for all*/
void U_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid)   {}   /*NULL for DCE*/
void U_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid)    {}   /*NULL for DCE*/
void U_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid)
{
   kal_uint32 UART_BASE = UART_BaseAddr[port];
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   if (SDTR)
      DRV_Reg(UART_MCR(UART_BASE)) |= UART_MCR_DTR;
   else
      DRV_Reg(UART_MCR(UART_BASE)) &= ~UART_MCR_DTR;
}
void U_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS)
{
   kal_uint16 MSR;
   kal_uint32 UART_BASE = UART_BaseAddr[port];
   MSR = DRV_Reg(UART_MSR(UART_BASE));
   *SDSR = (IO_level)(( MSR & UART_MSR_DSR) >> 5);
   *SCTS = (IO_level)(( MSR & UART_MSR_CTS) >> 4);
}

void U_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid)
{
   kal_uint32 UART_BASE = UART_BaseAddr[port];

   if (SBREAK == io_high)
      DRV_Reg(UART_LCR(UART_BASE)) |= UART_LCR_BREAK;
   else
      DRV_Reg(UART_LCR(UART_BASE)) &= ~UART_LCR_BREAK;
}

kal_uint16 U_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
   kal_uint16  real_count,index;
   kal_uint16   data_count=0;
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
	
   if (status != NULL)
      *status = 0;

   DisableRxIntr(UART_BaseAddr[port]);
   if (status != NULL)
   {
      if (UARTPort[port].EscFound)
      {
         *status |= UART_STAT_EscDet;
         UARTPort[port].EscFound = KAL_FALSE;
      }
      if (UARTPort[port].breakDet)
      {
         *status |= UART_STAT_Break;
         UARTPort[port].breakDet = KAL_FALSE;
      }
   }

   EnableRxIntr(UART_BaseAddr[port]);
   do
   {
      Buf_GetBytesAvail(&(UARTPort[port].Rx_Buffer),real_count);
                  
      if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
          (uart_support_autoescape()==KAL_FALSE&& UARTPort[port].DCB.flowControl==fc_sw ))
      {  
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {
            Buf_Pop(&(UARTPort[port].Rx_Buffer),*(Buffaddr+data_count));           
            /*The following are for software flow control*/
            if(uart_escape_state==0)
            {
               if(*(Buffaddr+data_count)==0x77)
               {
                  uart_escape_state=0x77;               
               }   
               else   
               {
                  data_count++;
               }   
            }  
            else if (uart_escape_state==0x77)
            {
               switch(*(Buffaddr+data_count))
               {
                  case 0x01:
                     *(Buffaddr+data_count)=UARTPort[port].DCB.xonChar;
                     data_count++;
                     break;
                  case 0x02:                  
                     *(Buffaddr+data_count)=UARTPort[port].DCB.xoffChar; 
                     data_count++;                 
                     break;               
                  case 0x03:                  
                     *(Buffaddr+data_count)=0x77;
                     data_count++;
                     break;      
                  default:                  
                     break;      
               }                         
               uart_escape_state=0x0;        
            }                          
         }   
      }
      else/*HW flow control*/
      {
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {
            Buf_Pop(&(UARTPort[port].Rx_Buffer),*(Buffaddr+data_count));                             
            data_count++;
         }   
      }   
      //}      
      /*satisfy uart owner request, so break*/
      if (data_count == Length) break;            
      /* disable interrupt*/
      DisableRxIntr(UART_BaseAddr[port]);
      Buf_GetBytesAvail(&(UARTPort[port].Rx_Buffer),real_count);
      
       /*there is no data in ringbuffer, so break*/       
      if (real_count==0)
      {
        send_Rxilm[port] = KAL_TRUE;  
        EnableRxIntr(UART_BaseAddr[port]); 
        /* enable interrupt*/
        break;
      }
      EnableRxIntr(UART_BaseAddr[port]);
      /* enable interrupt*/
   }while(KAL_TRUE);        
   
   return data_count;
}

#ifdef DRV_DEBUG
kal_uint16 BMT_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length)
{
   kal_uint16  real_count,index;

   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
      switch(port)
      {
         case uart_port1:
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
            break;
         case uart_port2:
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
            break;
   #ifdef __UART3_SUPPORT__   	
         case uart_port3:  
            #if !defined(DRV_UART_NO_UART3_PDN)
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);            
            #endif
            break;
   #endif   /*__UART3_SUPPORT__*/
         default:
            ASSERT(0);
            break;
      }
   }

   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);
   if (real_count > Length)
   {
      real_count = Length;
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
   }

   for (index = 0; index < real_count; index++)
   {
      Buf_Push(&(UARTPort[port].Tx_Buffer),*(Buffaddr+index));
   }

   switch(port)
   {
      case uart_port1:
         EnableTxIntr(UART_BaseAddr[port]);
         break;
      case uart_port2:
         #if defined(DRV_UART2_OLD_DMA)
               if ((DMA1_CheckITStat())||(DMA1_CheckRunStat()))
               {
                  ;
               }
               else
               {
                  EnableTxIntr(UART_BaseAddr[port]);
               }
         #endif   /*DRV_UART2_OLD_DMA*/
         #if defined(DRV_UART2_NO_DMA) || defined(FPGA)
               EnableTxIntr(UART_BaseAddr[port]);
         #endif   /*(DRV_UART2_NO_DMA,FPGA)*/

         #if defined(DRV_UART2_NORMAL_DMA)
            if ((DMA_CheckITStat(uart2_dmaport))||(DMA_CheckRunStat(uart2_dmaport)))
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
         #endif   /*DRV_UART2_NORMAL_DMA*/
         break;
#ifdef __UART3_SUPPORT__
      case uart_port3:
         EnableTxIntr(UART_BaseAddr[port]);
         break;
#endif   /*__UART3_SUPPORT__*/
      default:
         ASSERT(0);
         break;
   }

   return real_count;
}
#endif   /*DRV_DEBUG*/
kal_uint16 U_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid )
{
#ifndef DRV_DEBUG
   kal_uint16  real_count,index;
   kal_uint32  savedMask;

	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid,  (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }

   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
      switch(port)
      {
         case uart_port1:
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
            break;
         case uart_port2:
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
            break;
   #ifdef __UART3_SUPPORT__
         case uart_port3:            
            #if !defined(DRV_UART_NO_UART3_PDN)
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);      
            #endif      
            break;
   #endif   /*__UART3_SUPPORT__*/
         default:
            ASSERT(0);
            break;
      }
   }
   
   savedMask = SaveAndSetIRQMask();
   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);
   if (real_count >= Length)
   {
      real_count = Length;
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
   }
   RestoreIRQMask(savedMask);

   for (index = 0; index < real_count; index++)
   {
      Buf_Push(&(UARTPort[port].Tx_Buffer),*(Buffaddr+index));
   }

   switch(port)
   {
      case uart_port1:
         EnableTxIntr(UART_BaseAddr[port]);
         break;
      case uart_port2:
         #if defined(DRV_UART2_NORMAL_DMA)
            savedMask = SaveAndSetIRQMask();
            if (UART2_Intr_is_Running == KAL_TRUE)
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
            RestoreIRQMask(savedMask);
         #endif   /*DRV_UART2_NORMAL_DMA*/
         #if defined(DRV_UART2_OLD_DMA)
            savedMask = SaveAndSetIRQMask();
            if ((DMA1_CheckITStat())||(DMA1_CheckRunStat()))
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
            RestoreIRQMask(savedMask);
         #endif   /*DRV_UART2_OLD_DMA*/
         #if defined(DRV_UART2_NO_DMA) || defined(FPGA)
            EnableTxIntr(UART_BaseAddr[port]);
         #endif   /*(DRV_UART2_NO_DMA,FPGA)*/
         break;
#ifdef __UART3_SUPPORT__
      case uart_port3:
         EnableTxIntr(UART_BaseAddr[port]);
         break;
#endif   /*__UART3_SUPPORT__*/
      default:
         ASSERT(0);
         break;
   }
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}

#ifndef __PRODUCTION_RELEASE__
#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE"
#endif /* __MTK_TARGET__ */
#endif   /*__PRODUCTION_RELEASE__*/
#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
kal_uint16 U_PutISRBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
#ifndef DRV_DEBUG
   kal_uint16  real_count,index;

   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if (UARTPort[port].power_on == KAL_FALSE)
      return Length;
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
      switch(port)
      {
         case uart_port1:
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
            break;
         case uart_port2:
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
            break;
   #ifdef __UART3_SUPPORT__
         case uart_port3:            
            #if !defined(DRV_UART_NO_UART3_PDN)
            DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);            
            #endif
            break;
   #endif   /*__UART3_SUPPORT__*/
         default:
            ASSERT(0);
            break;
      }
   }
   if(UARTPort[port].EnableTX == KAL_FALSE)
   {
   	return Length;
   }

   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);
   if (real_count > Length)
   {
      real_count = Length;
   }

   for (index = 0; index < real_count; index++)
   {
      Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),*(Buffaddr+index));
   }

   switch(port)
   {
      case uart_port1:
         EnableTxIntr(UART_BaseAddr[port]);
         break;
      case uart_port2:
         #if defined(DRV_UART2_OLD_DMA)
            if ((DMA1_CheckITStat())||(DMA1_CheckRunStat())||(UART2_Intr_is_Running == KAL_TRUE) )
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
         #endif /*DRV_UART2_OLD_DMA*/

         #if defined(DRV_UART2_NO_DMA) || defined(FPGA)
            EnableTxIntr(UART_BaseAddr[port]);
         #endif   /*(DRV_UART2_NO_DMA,FPGA)*/

         #if defined(DRV_UART2_NORMAL_DMA)
            if (UART2_Intr_is_Running == KAL_TRUE)
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
         #endif   /*DRV_UART2_NORMAL_DMA*/
         break;
#ifdef __UART3_SUPPORT__
      case uart_port3:
         break;
#endif   /*__UART3_SUPPORT__*/
      default:
         ASSERT(0);
         break;
   }
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}
#endif /* Note: for ROM code */

kal_uint16 U_SendISRData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
    kal_int32  real_count,index, data_count=0;
    kal_uint8 data;

    EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);            
    if (UARTPort[port].power_on == KAL_FALSE)
       return Length;
    if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
    (uart_support_autoescape()==KAL_FALSE) )
    {
       if (mode == 0)
       {
           real_count = U_PutISRBytes(port,Buffaddr,Length,ownerid);
       }
       else
       {
           if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
           {
              switch(port)
              {
                 case uart_port1:
                    DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
                    break;
                 case uart_port2:
                    DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
                    break;
           #ifdef __UART3_SUPPORT__                  
                 case uart_port3:                  
                  #if !defined(DRV_UART_NO_UART3_PDN)
                  DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);                  
                  #endif
                    break;
           #endif   /*__UART3_SUPPORT__*/
                 default:
                    ASSERT(0);
                    break;
              }
           }
              /*TY modify this to solve overrun issue 20041006*/    
              Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);           
              for (index = 0; (index < (real_count-1))&&(data_count<Length); index++)
              {
                 data_count++;
                 data = *(Buffaddr+index);
                 if (data == UARTPort[port].DCB.xonChar)
                 {
                       Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),escape_char);
                       Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),0x01);
                       real_count--;
                 	
                 }
                 else if (data == UARTPort[port].DCB.xoffChar)
                 {
                 	     Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),escape_char);
                       Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),0x02);
                       real_count--;
                 }
                 else if (data == escape_char)
                 {
                       Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),escape_char);
                       Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),0x03);
                       real_count--;
                 }
                 else
                 {
                 	Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),*(Buffaddr+index));
      
                 }
              }
      
              real_count = index;
      
              switch(port)
              {
                 case uart_port1:
                    EnableTxIntr(UART_BaseAddr[port]);
                    break;
                 case uart_port2:
                    #if defined(DRV_UART2_OLD_DMA)
                       if ((DMA1_CheckITStat())||(DMA1_CheckRunStat())||(UART2_Intr_is_Running == KAL_TRUE) )
                       {
                          ;
                       }
                       else
                       {
                          EnableTxIntr(UART_BaseAddr[port]);
                       }
                    #endif /*DRV_UART2_OLD_DMA*/
                    #if defined(DRV_UART2_NO_DMA) || defined(FPGA)
                       EnableTxIntr(UART_BaseAddr[port]);
                    #endif   /*(DRV_UART2_NO_DMA,FPGA)*/
      
                    #if defined(DRV_UART2_NORMAL_DMA)
                       if (UART2_Intr_is_Running == KAL_TRUE)
                       {
                          ;
                       }
                       else
                       {
                          EnableTxIntr(UART_BaseAddr[port]);
                       }
                    #endif   /*DRV_UART2_NORMAL_DMA*/
                    break;
           #ifdef __UART3_SUPPORT__
                 case uart_port3:
                    break;
           #endif   /*__UART3_SUPPORT__*/
                 default:
                    ASSERT(0);
                    break;
              }
          }
  	   }
  	   else
  	   {
           real_count = U_PutISRBytes(port,Buffaddr,Length,ownerid);
      }

    return real_count;
#else
    return Length;
#endif
}
#ifndef __PRODUCTION_RELEASE__
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif   /*__PRODUCTION_RELEASE__*/


kal_uint16 U_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
    kal_int32   real_count,index, data_count=0;
    kal_uint8   data;
    kal_uint32  savedMask;

    EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);        
    if (UARTPort[port].power_on == KAL_FALSE)
       return Length;
        
    if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
    (uart_support_autoescape()==KAL_FALSE) )     
    {
       if(mode == 0)
           real_count = U_PutBytes(port, Buffaddr,Length,ownerid);       
       else
       {
         if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
         {
            switch(port)
            {
               case uart_port1:
                  DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
                  break;
               case uart_port2:
                  DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
                  break;
         #ifdef __UART3_SUPPORT__
               case uart_port3:                  
               	#if !defined(DRV_UART_NO_UART3_PDN)
                  DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);                  
                  #endif
                  break;
         #endif   /*__UART3_SUPPORT__*/
               default:
                  ASSERT(0);
                  break;
            }
         }
      
         Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);
         /*TY modify this to solve overrun issue 20041006*/      
         for (index = 0;( index < (real_count-1) )&& (data_count <Length); index++)
         {
            data_count++;
            data = *(Buffaddr+index);
      
            if (data == UARTPort[port].DCB.xonChar)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer),0x01);
               real_count--;         
            }
            else if (data == UARTPort[port].DCB.xoffChar)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer),0x02);
               real_count--;
            }
            else if (data == escape_char)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer),0x03);            
               real_count--;
            }
            else
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),data);
            }        
         }
         
         real_count = index;
         if (real_count != Length)
         {
            send_Txilm[port] = KAL_TRUE;
         }      
         switch(port)
         {
            case uart_port1:
               EnableTxIntr(UART_BaseAddr[port]);
               break;
            case uart_port2:
               #if defined(DRV_UART2_NORMAL_DMA)
                  savedMask = SaveAndSetIRQMask();
                  if ((DMA_CheckITStat(uart2_dmaport))||(DMA_CheckRunStat(uart2_dmaport)))
                  {
                     ;
                  }
                  else
                  {
                     EnableTxIntr(UART_BaseAddr[port]);
                  }
                  RestoreIRQMask(savedMask);
               #endif   /*DRV_UART2_NORMAL_DMA*/
               #if defined(DRV_UART2_OLD_DMA)
                  savedMask = SaveAndSetIRQMask();
                  if ((DMA1_CheckITStat())||(DMA1_CheckRunStat()))
                  {
                     ;
                  }
                  else
                  {
                     EnableTxIntr(UART_BaseAddr[port]);
                  }
                  RestoreIRQMask(savedMask);
               #endif   /*DRV_UART2_OLD_DMA*/
               #if defined(DRV_UART2_NO_DMA) || defined(FPGA)
                  EnableTxIntr(UART_BaseAddr[port]);
               #endif   /*(DRV_UART2_NO_DMA,FPGA)*/
               break;
      #ifdef __UART3_SUPPORT__
            case uart_port3:
               EnableTxIntr(UART_BaseAddr[port]);
               break;
      #endif   /*__UART3_SUPPORT__*/
            default:
               ASSERT(0);
               break;
         }
      }
  	}
  	else
  	{
      real_count = U_PutBytes(port, Buffaddr,Length,ownerid); 
   }    
   return real_count;
#else
    return Length;
#endif
}
//============================== ISR level ====================
/*============================ UART1 ========================*/
void UART_RLSHandler(void *parameter)
{
   kal_uint16 LSR;
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE = UART_BaseAddr[UARTData->port_no];

   LSR = DRV_Reg(UART_LSR(UART_BASE));
   if (LSR & UART_LSR_BI)
   {
      UARTData->breakDet = KAL_TRUE;
      UART_Purge(UARTData->port_no,RX_BUF,UARTPort[UARTData->port_no].ownerid);
   }

   if ((LSR & UART_LSR_OE) ||
       (LSR & UART_LSR_FIFOERR))
   {
      DisableRLSIntr(UART_BASE);
   }
}

void UART_Calback(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   GPTI_StopItem(UARTData->handle);
   switch(UARTData->Rec_state)
   {
      case UART_Get3EscChar:
         UARTData->EscFound = KAL_TRUE;
         UARTData->Rec_state = UART_RecNormal;
         UARTData->EscCount = 0;
         UART_sendilm(UARTData->port_no, MSG_ID_UART_ESCAPE_DETECTED_IND);
         break;
      case UART_RecNormal:
         UARTData->Rec_state = UART_StartCheckESC;
         UARTData->EscCount = 0;
         break;

      case UART_StartCheckESC:
         UARTData->Rec_state = UART_RecNormal;
         UARTData->EscCount = 0;
         break;
   }
}
   

void UART_RecHandler(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE = UART_BaseAddr[UARTData->port_no];
   kal_uint16 RoomLeft;
   kal_uint16 LSR;
   kal_uint8  cRXChar;

   if (UARTData->ESCDet.GuardTime != 0)
      GPTI_StopItem(UARTData->handle);

   Buf_GetRoomLeft(&(UARTData->Rx_Buffer),RoomLeft);

   while (RoomLeft)
   {
      LSR = DRV_Reg(UART_LSR(UART_BASE));
      if (LSR & UART_LSR_BI)
      {
         UARTData->breakDet = KAL_TRUE;
         U_Purge(UARTData->port_no,RX_BUF,UARTPort[UARTData->port_no].ownerid);
         LSR = DRV_Reg(UART_LSR(UART_BASE));
      }

      if (LSR & UART_LSR_DR)
      {
            cRXChar = (kal_uint8)DRV_Reg(UART_RBR(UART_BASE));
            Buf_Push(&(UARTData->Rx_Buffer),cRXChar);
            RoomLeft--;
            if (UARTData->ESCDet.GuardTime != 0)
            {
               /* detect escape sequence  */
               if (UARTData->Rec_state != UART_RecNormal)
               {
                  if (cRXChar == UARTData->ESCDet.EscChar)
                  {
                     UARTData->EscCount++;
                     if(UARTData->EscCount == 3)
                     {
                        UARTData->Rec_state = UART_Get3EscChar;
                     }
                     else if(UARTData->EscCount > 3)
                     {
                        UARTData->Rec_state = UART_RecNormal;
                        UARTData->EscCount = 0;
                     }
                  }
                  else
                  {
                     UARTData->Rec_state = UART_RecNormal;
                     UARTData->EscCount = 0;
                  }
               }
            }
      }
      else
      {
            break;
      }
   }
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[UARTData->port_no].rx_cb(UARTData->port_no);
   
   if (UARTData->ESCDet.GuardTime != 0)
      GPTI_StartItem(UARTData->handle,
                     (UARTData->ESCDet.GuardTime/10),
                     UART_Calback,
                     &UARTPort[UARTData->port_no]);

   if (!RoomLeft)   /*buffer is full*/
      DisableRxIntr(UART_BASE);
}

void UART_TrxHandler(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE = UART_BaseAddr[UARTData->port_no];
   kal_uint16  byteCount,index;
   kal_uint16  real_count_TASK,real_count_ISR, real_count;
   kal_uint16  offset;
   kal_uint8   TX_DATA;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UART3_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif   /*__UART3_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /*0*/

#if defined(DRV_UART_2_FIFO_DEPTHS) || defined(FPGA)
   if (UARTData->port_no == uart_port1)
      byteCount = UART1_TxFIFO_DEPTH;
   else
      byteCount = UART2_TxFIFO_DEPTH;
#endif   /*(DRV_UART_2_FIFO_DEPTHS,FPGA)*/

#if defined(DRV_UART_1_FIFO_DEPTH)
   byteCount = UART_TxFIFO_DEPTH;
#endif   /*DRV_UART_1_FIFO_DEPTH*/

   Buf_GetBytesAvail(&(UARTData->Tx_Buffer_ISR),real_count_ISR);
   if (UARTPort[UARTData->port_no].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
      Buf_GetBytesAvail(&(UARTData->Tx_Buffer),real_count_TASK);
        if ((!real_count_ISR) && (!real_count_TASK))
        {
           switch(UARTData->port_no)
         {
            case uart_port1:
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
               break;
            case uart_port2:
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
               break;
   #ifdef __UART3_SUPPORT__
            case uart_port3:               
               #if ( (!defined(MT6217)) && (!defined(MT6218B)) )               
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);               
               #endif
               break;
   #endif   /*__UART3_SUPPORT__*/
            default:
               ASSERT(0);
               break;
         }
           DisableTxIntr(UART_BASE);
           return;
        }
   }

   real_count = real_count_ISR;
   if (real_count_ISR > byteCount)
   {
         real_count = byteCount;
   }

   for (index = 0;index < real_count;index++)
   {
         Buf_Pop(&(UARTData->Tx_Buffer_ISR),TX_DATA);
         DRV_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
   }

   if (real_count != byteCount)
   {
      Buf_GetBytesAvail(&(UARTData->Tx_Buffer),real_count_TASK);
      offset = byteCount - real_count;
      real_count = real_count_TASK;
      if (real_count_TASK > offset)
      {
         real_count = offset;
      }

      for (index = 0;index < real_count;index++)
      {
         Buf_Pop(&(UARTData->Tx_Buffer),TX_DATA);
         DRV_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
      }

      /*TY adds these to expand flexibility 2004/10/15*/
      UARTPort[UARTData->port_no].tx_cb(UARTData->port_no);      
   }

   if (UARTPort[UARTData->port_no].sleep_on_tx == uart_sleep_on_tx_allow)
   {
      if ( ( BRead_addr(UARTData->Tx_Buffer) != BWrite_addr(UARTData->Tx_Buffer) ) ||
           ( BRead_addr(UARTData->Tx_Buffer_ISR) != BWrite_addr(UARTData->Tx_Buffer_ISR) )
         )
      {
         ;
      }
      else
      {
         DisableTxIntr(UART_BASE);
      }
   }
}

void UART_MsHandler(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE = UART_BaseAddr[UARTData->port_no];
   kal_uint16  MSR;
   IO_level    DSR;
   MSR = DRV_Reg(UART_MSR(UART_BASE));

   if (MSR & UART_MSR_DSR)
      DSR = io_high;
   else
      DSR = io_low;

   if (DSR != UARTData->DSR)
   {
      UART_sendilm(UARTData->port_no, MSG_ID_UART_DSR_CHANGE_IND);
      UARTData->DSR = DSR;
   }

   if (UARTData->DCB.DSRCheck)
   {
      if (MSR & UART_MSR_DSR)
      {
         switch(UARTData->port_no)
         {
            case uart_port1:
               DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
               break;
            case uart_port2:
               DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
               break;
#ifdef __UART3_SUPPORT__
            case uart_port3:  
            #if !defined(DRV_UART_NO_UART3_PDN)
               DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);   
            #endif            
               break;
#endif   /*__UART3_SUPPORT__*/
            default:
               ASSERT(0);
               break;
         }
      }
      else
      {
         switch(UARTData->port_no)
         {
            case uart_port1:
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
               break;
            case uart_port2:
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
               break;
#ifdef __UART3_SUPPORT__
            case uart_port3: 
               #if !defined(DRV_UART_NO_UART3_PDN)
               DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);               
               #endif
               break;
#endif   /*__UART3_SUPPORT__*/
            default:
               ASSERT(0);
               break;
         }
      }
   }
}

void UART1_HISR(void)
{
   kal_uint16 IIR;
   IIR = DRV_Reg(UART1_IIR);
   if (IIR & UART_IIR_INT_INVALID)
   {
      IRQClearInt(IRQ_UART1_CODE);
      IRQUnmask(IRQ_UART1_CODE);
      return;
   }
   switch ( IIR & UART_IIR_INT_MASK )
   {

	  case UART_IIR_CTI:
	   #ifdef __DMA_UART_VIRTUAL_FIFO__	   
	   if(UART_VFIFO_support[uart_port1])
			UART_RecTimeOutHandler(&UARTPort[uart_port1]);
		else	
		   UART_RecHandler(&UARTPort[uart_port1]);
		#else
		   UART_RecHandler(&UARTPort[uart_port1]);
		#endif	
		
		break;
	  	case UART_IIR_RDA:
	  	//#ifndef __DMA_UART_VIRTUAL_FIFO__
	  	if(UART_VFIFO_support[uart_port1]==KAL_FALSE)
	  	   UART_RecHandler(&UARTPort[uart_port1]);
	  	   
	  	//#endif
	  	break;
     	case UART_IIR_THRE :
     	#ifdef __DMA_UART_VIRTUAL_FIFO__
     	if(UART_VFIFO_support[uart_port1])
     	UART_THRE_hdr_VFIFO(uart_port1);
     	else
     	{
     	   if(UARTPort[uart_port1].EnableTX == KAL_FALSE)     
     	break;

         UART_TrxHandler(&UARTPort[uart_port1]);
     	}      
     	#else
                if(UARTPort[uart_port1].EnableTX == KAL_FALSE)
                   {
                        break ;
                   }

         UART_TrxHandler(&UARTPort[uart_port1]);         
#endif
     	break;
      case UART_IIR_RLS:
         UART_RLSHandler(&UARTPort[uart_port1]);
         break;

      case UART_IIR_MS :
         UART_MsHandler(&UARTPort[uart_port1]);
         break;

      case UART_IIR_SWFlowCtrl:
         break;

      case UART_IIR_HWFlowCtrl:
         break;

      default:
         break;
   }
   IRQClearInt(IRQ_UART1_CODE);
   IRQUnmask(IRQ_UART1_CODE);
}

void UART1_LISR(void)
{
   IRQMask(IRQ_UART1_CODE);
   if (UARTPort[uart_port1].power_on == KAL_FALSE)
   {
      IRQClearInt(IRQ_UART1_CODE);
   }
   else
   {
      //kal_activate_hisr(UARTPort[uart_port1].hisr);
      drv_active_hisr(DRV_UART1_HISR_ID);
   }
}

/*============================ UART2 ========================*/
#if defined(DRV_UART2_OLD_DMA)
static kal_uint8 DMABuffer[UART_DMA_SIZE];
void UART2_TrxHandler(void)
{
   kal_uint32  savedMask;
   kal_uint16  byteCount,real_count_TASK,index,real_count_ISR, real_count;
   kal_uint8   TX_DATA;
   kal_uint16  offset;
   kal_uint16  DMA_Count=0;

   ASSERT(UART2_race_check == KAL_FALSE);

   UART2_race_check = KAL_TRUE;
   savedMask = SaveAndSetIRQMask();
   if ( (BRead_addr(UARTPort[uart_port2].Tx_Buffer) == BWrite_addr(UARTPort[uart_port2].Tx_Buffer)) &&
        (BRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR) == BWrite_addr(UARTPort[uart_port2].Tx_Buffer_ISR))
      )
   {
      if (UARTPort[uart_port2].sleep_on_tx == uart_sleep_on_tx_forbid)
      {
         DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
      }
      UART2_Intr_is_Running = KAL_FALSE;
      UART2_race_check = KAL_FALSE;
      /*TY adds these to expand flexibility 2004/10/15*/
       UARTPort[uart_port2].tx_cb(uart_port2);
      
	   /*if (send_Txilm[uart_port2])
	   {
	      UART_sendilm(uart_port2, MSG_ID_UART_READY_TO_WRITE_IND);
	      send_Txilm[uart_port2] = KAL_FALSE;
	   } */     
      RestoreIRQMask(savedMask);
      return;
   }
   RestoreIRQMask(savedMask);

   DMA1_Stop();
   UART_SetDMAIntr(UART_BaseAddr[uart_port2]);

   byteCount = UART_DMA_SIZE;

   Buf_GetBytesAvail(&(UARTPort[uart_port2].Tx_Buffer_ISR),real_count_ISR);

   real_count = real_count_ISR;
   if (real_count_ISR > byteCount)
   {
         real_count = byteCount;
   }

   DMA_Count = 0;
   for (index = 0;index < real_count;index++)
   {
         Buf_Pop(&(UARTPort[uart_port2].Tx_Buffer_ISR),TX_DATA);
         DMABuffer[DMA_Count++] = TX_DATA;
   }

   if (real_count != byteCount)
   {
      Buf_GetBytesAvail(&(UARTPort[uart_port2].Tx_Buffer),real_count_TASK);
      offset = byteCount - real_count;
      real_count = real_count_TASK;
      if (real_count_TASK > offset)
      {
         real_count = offset;
      }

      for (index = 0;index < real_count;index++)
      {
         Buf_Pop(&(UARTPort[uart_port2].Tx_Buffer),TX_DATA);
         DMABuffer[DMA_Count++] = TX_DATA;
      }
   }
   /*TY adds these to expand flexibility 2004/10/15*/
    UARTPort[uart_port2].tx_cb(uart_port2);

   if (DMA_Count)
   {
      UART2DMA_Ini(KAL_TRUE);  //DMA Transmit

      DMA1_Init((kal_uint32)DMABuffer,UART2_THR,DMA_Count,UART2_TrxHandler);

      DMA1_Start();
      UART2_race_check = KAL_FALSE;
   }
   else
   {
      UART2_race_check = KAL_FALSE;
      UART2_Intr_is_Running = KAL_FALSE;
   }
}
#endif   /*DRV_UART2_OLD_DMA*/

#if defined(DRV_UART2_NORMAL_DMA)
void UART2_TrxHandler(void)
{
   kal_uint16  real_count_TASK,real_count_ISR;
   kal_uint16  old_index;
   kal_uint32  savedMask;
   ASSERT(UART2_race_check == KAL_FALSE);


   savedMask = SaveAndSetIRQMask();
   UART2_race_check = KAL_TRUE;

   switch(uart2_index_save.type)
   {
      case uart_isr_buffer:
         BRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR) = uart2_index_save.index;
         break;
      case uart_normal_buffer:
         BRead_addr(UARTPort[uart_port2].Tx_Buffer) = uart2_index_save.index;
         break;
      default:
         break;
   }
   UART2_update_index_save(uart_null_buffer,0);

   if ( (BRead_addr(UARTPort[uart_port2].Tx_Buffer) == BWrite_addr(UARTPort[uart_port2].Tx_Buffer)) &&
        (BRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR) == BWrite_addr(UARTPort[uart_port2].Tx_Buffer_ISR))
      )
   {
      if (UARTPort[uart_port2].sleep_on_tx == uart_sleep_on_tx_forbid)
         DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);

      UART2_race_check = KAL_FALSE;
      UART2_Intr_is_Running = KAL_FALSE;
      RestoreIRQMask(savedMask);
      /*TY adds these to expand flexibility 2004/10/15*/      
      UARTPort[uart_port2].tx_cb(uart_port2);
      /*TY adds the above description 2004/10/14
        Whenever UART finishes all transmission, he also needs to 
        check send_Txilm[uart_port2] flag and send the message according
        to this flag*/	         
      return;
   }


   UART2_Intr_is_Running = KAL_TRUE;
   RestoreIRQMask(savedMask);

   DMA_Stop(uart2_dmaport);
   UART_SetDMAIntr(UART_BaseAddr[uart_port2]);

   Buf_GetBytesAvail(&(UARTPort[uart_port2].Tx_Buffer_ISR),real_count_ISR);

   if (real_count_ISR)
   {
      uart2_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR);  /*1*/
      #ifdef DRV_UART_6218_TX_DMA
      uart2_txmenu.WPPT = Buff_EndAddr(UARTPort[uart_port2].Tx_Buffer_ISR);
      #else /*!DRV_UART_6218_TX_DMA*/
      uart2_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port2].Tx_Buffer_ISR))-(kal_uint32)uart2_txmenu.addr+1); /*2*/
      #endif   /*DRV_UART_6218_TX_DMA*/

      uart2_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port2].Tx_Buffer_ISR);     /*3*/
      uart2_input.count = real_count_ISR;       /*4*/
      uart2_input.callback = UART2_TrxHandler;   /*5*/

      old_index = BRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR)+real_count_ISR;
      if (old_index>=BLength_addr(UARTPort[uart_port2].Tx_Buffer_ISR))
         old_index -= BLength_addr(UARTPort[uart_port2].Tx_Buffer_ISR);

      UART2_update_index_save(uart_isr_buffer,old_index);
      DMA_Config(uart2_dmaport, &uart2_input, KAL_TRUE);
      UART2_race_check = KAL_FALSE;
   }
   else
   {
      Buf_GetBytesAvail(&(UARTPort[uart_port2].Tx_Buffer),real_count_TASK);
      #ifdef __PRODUCTION_RELEASE__
      if(real_count_TASK > 128)
         real_count_TASK = 128;
      #endif   /*__PRODUCTION_RELEASE__*/ 
      
      if (real_count_TASK)
      {
         uart2_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port2].Tx_Buffer);  /*1*/
         #ifdef DRV_UART_6218_TX_DMA
         uart2_txmenu.WPPT = Buff_EndAddr(UARTPort[uart_port2].Tx_Buffer); /*2*/
         #else /*!DRV_UART_6218_TX_DMA*/
         uart2_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port2].Tx_Buffer))-(kal_uint32)uart2_txmenu.addr+1); /*2*/
         #endif	/*DRV_UART_6218_TX_DMA*/

         uart2_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port2].Tx_Buffer);     /*3*/
         uart2_input.count = real_count_TASK;       /*4*/
         uart2_input.callback = UART2_TrxHandler;   /*5*/

         old_index = BRead_addr(UARTPort[uart_port2].Tx_Buffer)+real_count_TASK;
         if (old_index>=BLength_addr(UARTPort[uart_port2].Tx_Buffer))
            old_index -= BLength_addr(UARTPort[uart_port2].Tx_Buffer);

         UART2_update_index_save(uart_normal_buffer,old_index);
         DMA_Config(uart2_dmaport, &uart2_input, KAL_TRUE);
         UART2_race_check = KAL_FALSE;
      }
      else
      {
         UART2_race_check = KAL_FALSE;
         UART2_Intr_is_Running = KAL_FALSE;
      }
   }
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[uart_port2].tx_cb(uart_port2);         
   
}
#endif   /*DRV_UART2_NORMAL_DMA*/

void UART2_HISR(void)
{
   kal_uint16 IIR;

   IIR = DRV_Reg(UART2_IIR);
   if (IIR & UART_IIR_INT_INVALID)
   {
      IRQClearInt(IRQ_UART2_CODE);
      IRQUnmask(IRQ_UART2_CODE);
      return;
   }

   switch ( IIR & UART_IIR_INT_MASK )
   {
      case UART_IIR_RLS:
         UART_RLSHandler(&UARTPort[uart_port2]);
         break;
	  case UART_IIR_CTI:
      #ifdef __DMA_UART_VIRTUAL_FIFO__	  
      if(UART_VFIFO_support[uart_port2])
			UART_RecTimeOutHandler(&UARTPort[uart_port2]);
		else	
		   UART_RecHandler(&UARTPort[uart_port2]);
		#else   
		   UART_RecHandler(&UARTPort[uart_port2]);
		#endif	
		
		break;
	  	case UART_IIR_RDA:
	  	//#ifndef __DMA_UART_VIRTUAL_FIFO__	
	  	if(UART_VFIFO_support[uart_port2]==KAL_FALSE)  
	  	   UART_RecHandler(&UARTPort[uart_port2]);
	  	//#endif
	  	break;
     	case UART_IIR_THRE :
     	#ifdef __DMA_UART_VIRTUAL_FIFO__	  
     	if(UART_VFIFO_support[uart_port2])
     	   UART_THRE_hdr_VFIFO(uart_port2);
     	else
     	{
     	   if(UARTPort[uart_port2].EnableTX == KAL_FALSE)	      
     	break;
            #if defined(DRV_UART2_NORMAL_DMA) || defined(DRV_UART2_OLD_DMA)
         UART2_TrxHandler();
         //UART_TrxHandler(&UARTPort[uart_port2]);		
      #endif   /*(DRV_UART2_NORMAL_DMA,DRV_UART2_OLD_DMA)*/

            #if defined(DRV_UART2_NO_DMA) || defined(FPGA)
         UART_TrxHandler(&UARTPort[uart_port2]);
      #endif   /*(DRV_UART2_NO_DMA,FPGA)*/
     	}        	   
     	#else/*__DMA_UART_VIRTUAL_FIFO__*/
	  if(UARTPort[uart_port2].EnableTX == KAL_FALSE)
	   {
	   	break;
	   }
         #if defined(DRV_UART2_NORMAL_DMA) || defined(DRV_UART2_OLD_DMA)
         UART2_TrxHandler();
         //UART_TrxHandler(&UARTPort[uart_port2]);		
#endif   /*(DRV_UART2_NORMAL_DMA,DRV_UART2_OLD_DMA)*/

         #if defined(DRV_UART2_NO_DMA) || defined(FPGA)
         UART_TrxHandler(&UARTPort[uart_port2]);
#endif   /*(DRV_UART2_NO_DMA,FPGA)*/
     	#endif/*__DMA_UART_VIRTUAL_FIFO__*/
         break;
      case UART_IIR_MS :
         UART_MsHandler(&UARTPort[uart_port2]);
         break;

      case UART_IIR_SWFlowCtrl:
         break;

      case UART_IIR_HWFlowCtrl:
         break;

      default:
         break;
   }
   IRQClearInt(IRQ_UART2_CODE);
   IRQUnmask(IRQ_UART2_CODE);
}

void UART2_LISR(void)
{
   IRQMask(IRQ_UART2_CODE);
   if (UARTPort[uart_port2].power_on == KAL_FALSE)
   {
      IRQClearInt(IRQ_UART2_CODE);
   }
   else
   {
      //kal_activate_hisr(UARTPort[uart_port2].hisr);
      drv_active_hisr(DRV_UART2_HISR_ID);
   }
}

#ifdef __UART3_SUPPORT__
void UART3_HISR(void)
{
   kal_uint16 IIR;

   IIR = DRV_Reg(UART3_IIR);
   if (IIR & UART_IIR_INT_INVALID)
   {
      IRQClearInt(IRQ_UART3_CODE);
      IRQUnmask(IRQ_UART3_CODE);
      return;
   }

   switch ( IIR & UART_IIR_INT_MASK )
   {
      case UART_IIR_RLS:
         UART_RLSHandler(&UARTPort[uart_port3]);
         break;
      case UART_IIR_CTI:
	   #ifdef __DMA_UART_VIRTUAL_FIFO__
	   if(UART_VFIFO_support[uart_port3])
			UART_RecTimeOutHandler(&UARTPort[uart_port3]);
		else	
		   UART_RecHandler(&UARTPort[uart_port3]);
		#else
		   UART_RecHandler(&UARTPort[uart_port3]);   
		#endif	
		
		break;
      case UART_IIR_RDA:
	  	//#ifndef __DMA_UART_VIRTUAL_FIFO__
	  	if(UART_VFIFO_support[uart_port3]==KAL_FALSE)
         UART_RecHandler(&UARTPort[uart_port3]);
	  	//#endif
         break;
      case UART_IIR_THRE :
     	#ifdef __DMA_UART_VIRTUAL_FIFO__
     	if(UART_VFIFO_support[uart_port3])
     	   UART_THRE_hdr_VFIFO(uart_port3);
     	else
     	{
     	   if(UARTPort[uart_port3].EnableTX == KAL_FALSE)         
            break;                  
         UART_TrxHandler(&UARTPort[uart_port3]);
     	}   
     	#else
     	if(UARTPort[uart_port3].EnableTX == KAL_FALSE)
      {
         break;
      }         
      UART_TrxHandler(&UARTPort[uart_port3]);
      #endif   
         break;
      case UART_IIR_MS :
         UART_MsHandler(&UARTPort[uart_port3]);
         break;

      case UART_IIR_SWFlowCtrl:
         break;

      case UART_IIR_HWFlowCtrl:
         break;

      default:
         break;
   }
   IRQClearInt(IRQ_UART3_CODE);
   IRQUnmask(IRQ_UART3_CODE);
}

void UART3_LISR(void)
{
   IRQMask(IRQ_UART3_CODE);
   if (UARTPort[uart_port3].power_on == KAL_FALSE)
   {
      IRQClearInt(IRQ_UART3_CODE);
   }
   else
   {
      //kal_activate_hisr(UARTPort[uart_port3].hisr);
      drv_active_hisr(DRV_UART3_HISR_ID);
   }
}
#endif   /*__UART3_SUPPORT__*/

#ifdef __USB_ENABLE__
   extern UARTStruct USB2UARTPort;
#endif   /*__USB_ENABLE__*/

void UART_SwitchPort(UART_PORT *APP_port, UART_PORT new_uart_port)
{
   //kal_uint32 savedMask;
   UARTStruct *uartport=0;

   if (*APP_port == new_uart_port)
      return;

   //savedMask = SaveAndSetIRQMask();
#ifdef __UART3_SUPPORT__
   if ( (*APP_port == uart_port1) || (*APP_port == uart_port2) || (*APP_port == uart_port3))
#else /*__UART3_SUPPORT__*/
   if ( (*APP_port == uart_port1) || (*APP_port == uart_port2) )
#endif /*__UART3_SUPPORT__*/
   {
      uartport = &UARTPort[*APP_port];
   }
#ifdef __USB_ENABLE__
   else if (*APP_port == uart_port_usb)
   {
      uartport = &USB2UARTPort;
   }
#endif   /*__USB_ENABLE__*/
   else
   {
      ASSERT(0);
   }
   
   if ((new_uart_port == uart_port_usb) || (*APP_port == uart_port_usb) )
   {
      if (new_uart_port == uart_port_usb)
      {
         old_uart_portswitch_fctrl = uartport->DCB.flowControl;
         uartport->DCB.flowControl = fc_hw;
      }
      else if ( (new_uart_port == uart_port1) || (new_uart_port == uart_port2) )
      {
         uartport->DCB.flowControl = old_uart_portswitch_fctrl;
      }
   }
   
   UART_Open(new_uart_port, uartport->ownerid);
   UART_SetDCBConfig(new_uart_port, &uartport->DCB, uartport->ownerid);
   UART_ConfigEscape(new_uart_port, uartport->ESCDet.EscChar, uartport->ESCDet.GuardTime, uartport->ownerid);
   UART_Close(*APP_port, uartport->ownerid);
   *APP_port = new_uart_port;
   //RestoreIRQMask(savedMask);
}
/*TY adds these to expand flexibility 2004/10/15*/
void UART_dafault_tx_cb(UART_PORT port)
{
   if (send_Txilm[port])
   {
      UART_sendilm(port, MSG_ID_UART_READY_TO_WRITE_IND);
      send_Txilm[port] = KAL_FALSE;
   }      
}
void UART_dafault_rx_cb(UART_PORT port)
{
   if (send_Rxilm[port])
   {
      UART_sendilm(port, MSG_ID_UART_READY_TO_READ_IND);
      send_Rxilm[port] = KAL_FALSE;
   }      
}

   

/*TY adds these to expand flexibility 2004/10/15*/
void U_Register_TX_cb(UART_PORT port, module_type ownerid, UART_TX_FUNC func)
{
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   UARTPort[port].tx_cb=func;   
}   
/*TY adds these to expand flexibility 2004/10/15*/
void U_Register_RX_cb(UART_PORT port, module_type ownerid, UART_RX_FUNC func)
{
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   UARTPort[port].rx_cb=func;   
}   

void UART_TurnOnPower(UART_PORT port, kal_bool enable)
{      
   kal_uint16 pdn_code=0;
   kal_uint8  irq_code=0;
   switch(port)
   {
      case uart_port1:
         pdn_code=DRVPDN_CON1_UART1;
         irq_code=IRQ_UART1_CODE;
         break;
      case uart_port2:
         pdn_code=DRVPDN_CON1_UART2;
         irq_code=IRQ_UART2_CODE;
         #ifdef DCM_ENABLE
         #ifdef __BT_USE_UART2__
         if(enable==KAL_TRUE)/*turn on power*/
            DCM_Disable(uart2_dcm_handle);
         else
            DCM_Enable(uart2_dcm_handle);
         #endif/*__BT_USE_UART2__*/            
         #endif/*DCM_ENABLE*/  
         break;
      case uart_port3:       	 	
      	 #ifdef __UART3_SUPPORT__
      	   #if !defined(DRV_UART_NO_UART3_PDN)
         pdn_code=DRVPDN_CON1_UART3;
         irq_code=IRQ_UART3_CODE;
         #endif
         #ifdef DCM_ENABLE
         if(enable==KAL_TRUE)/*turn on power*/
            DCM_Disable(uart3_dcm_handle);
         else
            DCM_Enable(uart3_dcm_handle);            
         #endif/*DCM_ENABLE*/   
         #endif/*__UART3_SUPPORT__*/
         break;
   }
   if(enable==KAL_TRUE)/*turn on power*/
   {
      DRV_Reg(DRVPDN_CON1+0x20)=pdn_code;
      //DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_ALLOFF);
      UARTPort[port].power_on = KAL_TRUE;
      IRQClearInt(irq_code);
      IRQUnmask(irq_code);
   }
   else/*turn off power*/
   {
      IRQMask(irq_code);
      //DRV_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_ALLOFF);
      DRV_Reg(DRVPDN_CON1+0x10)=pdn_code;
      UARTPort[port].power_on = KAL_FALSE;
   }
}   

/* This is to check that all the data in UART TX ring buffer is empty. */
kal_bool UART_CheckTxBufferEmpty(UART_PORT port)
{
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if(UART_VFIFO_support[port])
   {
	   return ((0==DMA_GetVFIFO_Avail(UARTPort[port].Tx_DMA_Ch)) ? KAL_TRUE : KAL_FALSE);
   }
   else
   {
#endif
	   kal_uint8 result;

	   Buf_IsEmpty(&(UARTPort[port].Tx_Buffer),result);
	   return ((Buff_isEmpty == result) ? KAL_TRUE : KAL_FALSE);
#ifdef __DMA_UART_VIRTUAL_FIFO__
   }
#endif
}

/* This is to check that all TX data have been sent out 
   including UART TX ring buffer and UART FIFO. */
kal_bool UART_CheckTxAllSentOut(UART_PORT port)
{
   if (UART_CheckTxBufferEmpty(port) == KAL_FALSE)
      return KAL_FALSE;
   if (UART_LSR_TEMT & DRV_Reg(UART_LSR(UART_BaseAddr[port])))
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void UART_GetTxBufferSize(UART_PORT port, kal_uint32 *total_size, kal_uint32 *rest_size)
{
	*total_size = UARTPort[port].Tx_Buffer.Length;
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if(UART_VFIFO_support[port])
	   *rest_size = DMA_GetVFIFO_Avail(UARTPort[port].Tx_DMA_Ch);
   else
#endif
	   Buf_GetBytesAvail(&(UARTPort[port].Tx_Buffer), *rest_size);
}

// uart dispatch funtion table
UartDriver_strcut UartDriver=
{
        U_Open,
        U_Close,
        U_GetBytes,
        U_PutBytes,
        U_GetBytesAvail,
        U_GetTxRoomLeft,
        U_PutISRBytes,
        U_GetTxISRRoomLeft, 
        U_Purge,
        U_SetOwner,
        U_SetFlowCtrl,
        U_ConfigEscape,
        U_SetDCBConfig,
        U_CtrlDCD,
        U_CtrlBreak,
        U_ClrRxBuffer,
        U_ClrTxBuffer,
        U_SetBaudRate,
        U_SendISRData,
        U_SendData,
        U_GetOwnerID,
        U_SetAutoBaud_Div,
        /*TY adds these to expand flexibility 2004/10/15*/
        U_Register_TX_cb,        
        U_Register_RX_cb,
        /*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/
        U_GetUARTByte,
        U_PutUARTByte,
        U_PutUARTBytes,
        /*for virtual com port to return DCB configuration*/
        U_ReadDCBConfig,
        U_CtrlRI,
        U_CtrlDTR,
        U_ReadHWStatus 
};

