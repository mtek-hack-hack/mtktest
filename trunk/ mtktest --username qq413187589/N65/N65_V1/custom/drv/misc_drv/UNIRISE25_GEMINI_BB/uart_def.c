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
 *    uart_def.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the size of UART ring buffer
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "drv_comm.h"
#include "uart_sw.h"

/*
1. remove get_mem by using allocate static array
2. use different buffer size for __PRODUCTION_RELEASE__
3. the buffer size is depending on the owner instead uart port
*/

UART_flowCtrlMode  *UART_Get_FlowCtrl_Mode(void);
const UART_rings_struct *UART_Get_Data(void);


#ifndef __PRODUCTION_RELEASE__
// define the uart ring buffer size
#define L4_RX_LENGTH				2048
#define L4_TX_LENGTH				3584
#define L4_TXISR_LENGTH			3072
#define TST_RX_LENGTH			2048
#define TST_TX_LENGTH			3584
#define TST_TXISR_LENGTH		3072
#define CUSTOM_RX_LENGTH		2048
#define CUSTOM_TX_LENGTH		3584
#define CUSTOM_TXISR_LENGTH	3072
#else	
// define the uart ring buffer size
#define L4_RX_LENGTH				2048
#define L4_TX_LENGTH				3584
#define L4_TXISR_LENGTH			3072
#define TST_RX_LENGTH			2048
#define TST_TX_LENGTH			3584
#define TST_TXISR_LENGTH		3072
#define CUSTOM_RX_LENGTH		2048
#define CUSTOM_TX_LENGTH		3584
#define CUSTOM_TXISR_LENGTH	3072
#endif	// __PRODUCTION_RELEASE__

// L4 ring buffer
kal_uint8 L4_RxRingBuffer[L4_RX_LENGTH];
kal_uint8 L4_TxRingBuffer[L4_TX_LENGTH];
kal_uint8 L4_TxISRRingBuffer[L4_TXISR_LENGTH];

// tst ring buffer
kal_uint8 TST_RxRingBuffer[TST_RX_LENGTH];
kal_uint8 TST_TxRingBuffer[TST_TX_LENGTH];
kal_uint8 TST_TxISRRingBuffer[TST_TXISR_LENGTH];


#ifdef __UART3_SUPPORT__
// uart3 ring buffer
kal_uint8 CUSTOM_RxRingBuffer[CUSTOM_RX_LENGTH];
kal_uint8 CUSTOM_TxRingBuffer[CUSTOM_TX_LENGTH];
kal_uint8 CUSTOM_TxISRRingBuffer[CUSTOM_TXISR_LENGTH];
#endif //__UART3_SUPPORT__

const UART_rings_struct	UART_custom_rings = 
{
	{
		{
			L4_RxRingBuffer,
			L4_TxRingBuffer,			
			L4_TxISRRingBuffer,			
			sizeof L4_RxRingBuffer,
			sizeof L4_TxRingBuffer,			
			sizeof L4_TxISRRingBuffer,			
			MOD_L4C,
		},		
		{  
			TST_RxRingBuffer,
			TST_TxRingBuffer,			
			TST_TxISRRingBuffer,			
			sizeof TST_RxRingBuffer,
			sizeof TST_TxRingBuffer,			
			sizeof TST_TxISRRingBuffer,			
			MOD_TST_READER,
		},  
		#ifdef __UART3_SUPPORT__		
		{
			CUSTOM_RxRingBuffer,
			CUSTOM_TxRingBuffer,
			CUSTOM_TxISRRingBuffer,
			sizeof CUSTOM_RxRingBuffer,
			sizeof CUSTOM_TxRingBuffer,
			sizeof CUSTOM_TxISRRingBuffer,
			MOD_UART3_HISR,
		},						 
		#endif	// __UART3_SUPPORT__
	},
	#ifdef __UART3_SUPPORT__		
	uart_port2/*which one not support VFIFO*/			
	#else
	uart_port3/*which one not support VFIFO*/			
	#endif
};
const UART_rings_struct *UART_Get_Data(void) 
{
   return (&UART_custom_rings);
}

const UART_customize_function_struct uart_custom_func =
{
     UART_Get_Data
};            

const UART_customize_function_struct *UART_GetFunc(void)
{
   return (&uart_custom_func);  
}   
        
UART_flowCtrlMode  UART_GetFlowCtrl(UART_PORT uart_port)
{
 UART_flowCtrlMode flow_ctrl;
 
   switch(uart_port)
   {
      case uart_port1:
         flow_ctrl=fc_none;
         break;
      case uart_port2:
         flow_ctrl=fc_none;
         break;
#ifdef __UART3_SUPPORT__
      case uart_port3:
         flow_ctrl=fc_none;
         break;
#endif         
#ifdef __IRDA_SUPPORT__
      case uart_port_irda:
         flow_ctrl=fc_none;
         break;
#endif
#ifdef __USB_ENABLE__
      case uart_port_usb:
         flow_ctrl=fc_none;
         break;    
#endif      
#ifdef __BT_SUPPORT__
      case uart_port_bluetooth:
         flow_ctrl=fc_none;
         break;
#endif         
      default:
         flow_ctrl=fc_none;
         break;
                               
   } 
   return(flow_ctrl);      
}


