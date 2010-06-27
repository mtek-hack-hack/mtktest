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

/*******************************************************************************
 * Filename:
 * ---------
 *	  bl_uart_hw.h
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   This file is intends for UART driver.
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
 
#ifndef _BOOTLOADER_UART_HW_H
#define _BOOTLOADER_UART_HW_H


#define UART1_base   0x80130000
#define UART2_base   0x80180000


//UART1 MMP address
#define   UART1_RBR     (UART1_base+0x0)    /* Read only */
#define   UART1_THR     (UART1_base+0x0)	  /* Write only */
#define   UART1_IER     (UART1_base+0x4)
#define   UART1_IIR     (UART1_base+0x8)    /* Read only */
#define   UART1_FCR     (UART1_base+0x8)    /* Write only */
#define   UART1_LCR     (UART1_base+0xc)
#define   UART1_MCR     (UART1_base+0x10)
#define   UART1_LSR     (UART1_base+0x14)
#define   UART1_MSR     (UART1_base+0x18)
#define   UART1_SCR     (UART1_base+0x1c)
#define   UART1_DLL     (UART1_base+0x0)
#define   UART1_DLH     (UART1_base+0x4)
#define   UART1_EFR     (UART1_base+0x8)    /* Only when LCR = 0xbf */
#define   UART1_XON1    (UART1_base+0x10)   /* Only when LCR = 0xbf */
#define   UART1_XON2    (UART1_base+0x14)   /* Only when LCR = 0xbf */
#define   UART1_XOFF1   (UART1_base+0x18)   /* Only when LCR = 0xbf */
#define   UART1_XOFF2   (UART1_base+0x1c)   /* Only when LCR = 0xbf */
#define   UART1_SPEED   (UART1_base+0x24)


//UART2 MMP address
#define   UART2_RBR     (UART2_base+0x0)    /* Read only */
#define   UART2_THR     (UART2_base+0x0)	  /* Write only */
#define   UART2_IER     (UART2_base+0x4)
#define   UART2_IIR     (UART2_base+0x8)    /* Read only */
#define   UART2_FCR     (UART2_base+0x8)    /* Write only */
#define   UART2_LCR     (UART2_base+0xc)
#define   UART2_MCR     (UART2_base+0x10)
#define   UART2_LSR     (UART2_base+0x14)
#define   UART2_MSR     (UART2_base+0x18)
#define   UART2_SCR     (UART2_base+0x1c)
#define   UART2_DLL     (UART2_base+0x0)
#define   UART2_DLH     (UART2_base+0x4)
#define   UART2_EFR     (UART2_base+0x8)    /* Only when LCR = 0xbf */
#define   UART2_XON1    (UART2_base+0x10)   /* Only when LCR = 0xbf */
#define   UART2_XON2    (UART2_base+0x14)   /* Only when LCR = 0xbf */
#define   UART2_XOFF1   (UART2_base+0x18)   /* Only when LCR = 0xbf */
#define   UART2_XOFF2   (UART2_base+0x1c)   /* Only when LCR = 0xbf */]
#define   UART2_SPEED   (UART2_base+0x24)


//UART3 MMP address
#define   UART3_RBR     (UART3_base+0x0)    /* Read only */
#define   UART3_THR     (UART3_base+0x0)	  /* Write only */
#define   UART3_IER     (UART3_base+0x4)
#define   UART3_IIR     (UART3_base+0x8)    /* Read only */
#define   UART3_FCR     (UART3_base+0x8)    /* Write only */
#define   UART3_LCR     (UART3_base+0xc)
#define   UART3_MCR     (UART3_base+0x10)
#define   UART3_LSR     (UART3_base+0x14)
#define   UART3_MSR     (UART3_base+0x18)
#define   UART3_SCR     (UART3_base+0x1c)
#define   UART3_DLL     (UART3_base+0x0)
#define   UART3_DLH     (UART3_base+0x4)
#define   UART3_EFR     (UART3_base+0x8)    /* Only when LCR = 0xbf */
#define   UART3_XON1    (UART3_base+0x10)   /* Only when LCR = 0xbf */
#define   UART3_XON2    (UART3_base+0x14)   /* Only when LCR = 0xbf */
#define   UART3_XOFF1   (UART3_base+0x18)   /* Only when LCR = 0xbf */
#define   UART3_XOFF2   (UART3_base+0x1c)   /* Only when LCR = 0xbf */


//IER
#define   UART_IER_ERBFI     	      0x0001
#define   UART_IER_ETBEI     	      0x0002
#define   UART_IER_ELSI     	      0x0004
#define   UART_IER_EDSSI   	      0x0008
#define   UART_IER_XOFFI    	      0x0020
#define   UART_IER_RTSI    	      0x0040
#define   UART_IER_CTSI    	      0x0080
#define   IER_HW_NORMALINTS         0x000d
#define   IER_HW_ALLINTS            0x000f
#define   IER_SW_NORMALINTS         0x002d
#define   IER_SW_ALLINTS            0x002f
#define   UART_IER_ALLOFF           0x0000


//FCR
#define   UART_FCR_FIFOEN           0x0001
#define   UART_FCR_CLRR    	      0x0002
#define   UART_FCR_CLRT    	      0x0004
#define   UART_FCR_FIFOINI	         0x0007
#define   UART_FCR_RX1Byte_Level    0x0000
#define   UART_FCR_RX16Byte_Level   0x0040
#define   UART_FCR_RX32Byte_Level   0x0080
#define   UART_FCR_RX62Byte_Level   0x00c0

#define   UART_FCR_TX1Byte_Level    0x0000
#define   UART_FCR_TX16Byte_Level   0x0010
#define   UART_FCR_TX32Byte_Level   0x0020
#define   UART_FCR_TX62Byte_Level   0x0030

#define   UART_FCR_Normal		   (UART_FCR_TX16Byte_Level | UART_FCR_RX32Byte_Level | UART_FCR_FIFOINI)


//IIR,RO
#define   UART_IIR_INT_INVALID      0x0001
#define   UART_IIR_RLS          	   0x0006  // Receiver Line Status
#define   UART_IIR_RDA          	   0x0004  // Receive Data Available
#define   UART_IIR_CTI          	   0x000C  // Character Timeout Indicator
#define   UART_IIR_THRE         	   0x0002  // Transmit Holding Register Empty
#define   UART_IIR_MS            	0x0000  // Check Modem Status Register
#define   UART_IIR_SWFlowCtrl     	0x0010  // Receive XOFF characters
#define   UART_IIR_HWFlowCtrl      	0x0020  // CTS or RTS Rising Edge
#define   UART_IIR_FIFOS_ENABLED  	0x00c0
#define   UART_IIR_NO_INTERRUPT_PENDING   0x0001
#define   UART_IIR_INT_MASK         0x001f

//===============================LCR================================
//WLS
#define   UART_WLS_8                0x0003
#define   UART_WLS_7                0x0002
#define   UART_WLS_6                0x0001
#define   UART_WLS_5                0x0000
#define   UART_DATA_MASK            0x0003

//Parity
#define   UART_NONE_PARITY          0x0000
#define   UART_ODD_PARITY           0x0008
#define   UART_EVEN_PARITY          0x0018
#define   UART_MARK_PARITY          0x0028
#define   UART_SPACE_PARITY         0x0038
#define   UART_PARITY_MASK          0x0038

//Stop bits
#define   UART_1_STOP               0x0000
#define   UART_1_5_STOP             0x0004  // Only valid for 5 data bits
#define   UART_2_STOP               0x0004
#define   UART_STOP_MASK            0x0004

#define   UART_LCR_DLAB             0x0080

//===============================LCR================================

//MCR
#define   UART_MCR_DTR    	         0x0001
#define   UART_MCR_RTS    	         0x0002
#define   UART_MCR_LOOPB    	      0x0010
#define   UART_MCR_IRE		         0x0040  //Enable IrDA modulation/demodulation
#define   UART_MCR_XOFF             0x0080
#define   UART_MCR_Normal	         (UART_MCR_DTR | UART_MCR_RTS)

//LSR
#define   UART_LSR_DR         	   0x0001
#define   UART_LSR_OE         	   0x0002
#define   UART_LSR_PE         	   0x0004
#define   UART_LSR_FE         	   0x0008
#define   UART_LSR_BI         	   0x0010
#define   UART_LSR_THRE     	      0x0020
#define   UART_LSR_TEMT       	   0x0040
#define   UART_LSR_FIFOERR    	   0x0080

//MSR
#define   UART_MSR_DCTS             0x0001
#define   UART_MSR_DDSR             0x0002
#define   UART_MSR_TERI             0x0004
#define   UART_MSR_DDCD             0x0008
#define   UART_MSR_CTS              0x0010
#define   UART_MSR_DSR              0x0020
#define   UART_MSR_RI               0x0040
#define   UART_MSR_DCD              0x0080

//DLL
//DLM
//EFR
#define   UART_EFR_AutoCTS       	0x0080
#define   UART_EFR_AutoRTS       	0x0040
#define   UART_EFR_Enchance      	0x0010
#define   UART_EFR_SWCtrlMask    	0x000f
#define   UART_EFR_NoSWFlowCtrl   	0x0000
#define   UART_EFR_ALLOFF		      0x0000
#define   UART_EFR_AutoRTSCTS       0x00c0

//Tx/Rx XON1/Xoff1 as flow control word
#define   UART_EFR_SWFlowCtrlX1   	0x000a	

//Tx/Rx XON2/Xoff2 as flow control word
#define   UART_EFR_SWFlowCtrlX2   	0x0005

//Tx/Rx XON1&XON2/Xoff1&Xoff2 as flow control word
#define   UART_EFR_SWFlowCtrlXAll   0x000f	

#define   UART_TxFIFO_DEPTH		48
#define   UART_RxFIFO_DEPTH		62


#endif