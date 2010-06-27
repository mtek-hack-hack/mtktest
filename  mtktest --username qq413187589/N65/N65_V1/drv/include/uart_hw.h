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
 *    uart_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UART_HW_H
#define UART_HW_H
#include "drv_features.h"
/*#define SLEEP_DONT_CARE_DBG_INFO */

/*UART1 MMP address, UART1_base = 0x80130000, UART2_base = 0x80180000,, UART3_base = 0x801b0000*/
/*used in Task or normal function*/
#define   UART_RBR(_baseaddr)          (_baseaddr+0x0)		/* Read only */
#define   UART_THR(_baseaddr)          (_baseaddr+0x0)		/* Write only */
#define   UART_IER(_baseaddr)          (_baseaddr+0x4)
#define   UART_IIR(_baseaddr)          (_baseaddr+0x8)		/* Read only */
#define   UART_FCR(_baseaddr)          (_baseaddr+0x8)		/* Write only */
#define   UART_LCR(_baseaddr)          (_baseaddr+0xc)
#define   UART_MCR(_baseaddr)          (_baseaddr+0x10)
#define   UART_LSR(_baseaddr)          (_baseaddr+0x14)
#define   UART_MSR(_baseaddr)          (_baseaddr+0x18)
#define   UART_SCR(_baseaddr)          (_baseaddr+0x1c)
#define   UART_DLL(_baseaddr)          (_baseaddr+0x0)
#define   UART_DLH(_baseaddr)          (_baseaddr+0x4)
#define   UART_EFR(_baseaddr)          (_baseaddr+0x8)		/* Only when LCR = 0xbf */
#define   UART_XON1(_baseaddr)         (_baseaddr+0x10)		/* Only when LCR = 0xbf */
#define   UART_XON2(_baseaddr)         (_baseaddr+0x14)		/* Only when LCR = 0xbf */
#define   UART_XOFF1(_baseaddr)        (_baseaddr+0x18)	/* Only when LCR = 0xbf */
#define   UART_XOFF2(_baseaddr)        (_baseaddr+0x1c)	/* Only when LCR = 0xbf */
#ifdef DRV_UART_6205B_REG
   #define	UART_RATE_STEP(_baseaddr)		   (_baseaddr+0x20)
   #define	UART_STEP_COUNT(_baseaddr)		   (_baseaddr+0x24)
   #define	UART_SAMPLE_COUNT(_baseaddr)     (_baseaddr+0x28)
#endif   /*DRV_UART_6205B_REG*/
#if 0
#ifdef MT6217/*TY add this 10/01/2004,*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /*MT6217*/
#endif
#if defined(DRV_UART_BASIC_REG)
   #define	UART_AUTOBAUD_EN(_baseaddr)		(_baseaddr+0x20)
   #define	UART_RATE_STEP(_baseaddr)		   (_baseaddr+0x24)
   #define	UART_STEP_COUNT(_baseaddr)		   (_baseaddr+0x28)
   #define	UART_SAMPLE_COUNT(_baseaddr)     (_baseaddr+0x2c)
   #define	UART_AUTOBAUD_REG(_baseaddr)     (_baseaddr+0x30)
   #define	UART_RATE_FIX_REG(_baseaddr)     (_baseaddr+0x34)
   #define	UART_AUTO_BAUDSAMPLE(_baseaddr)		(_baseaddr+0x38)
   #define	UART_ESCAPE_DAT(_baseaddr)		   (_baseaddr+0x40)
   #define	UART_ESCAPE_EN(_baseaddr)		   (_baseaddr+0x44)
   #define	UART_SLEEP_EN(_baseaddr)		   (_baseaddr+0x48)
#endif   /*DRV_UART_BASIC_REG*/
#if defined(DRV_UART_VFIFO_EN_REG)
	#define	UART_RXDMA(_baseaddr)	                (_baseaddr+0x4c)
#endif

//used only in LISR or HISR
#define   UART1_RBR   (UART1_base+0x0)		/* Read only */
#define   UART1_THR   (UART1_base+0x0)		/* Write only */
#define   UART1_IER   (UART1_base+0x4)
#define   UART1_IIR   (UART1_base+0x8)		/* Read only */
#define   UART1_FCR   (UART1_base+0x8)		/* Write only */
#define   UART1_LCR   (UART1_base+0xc)
#define   UART1_MCR   (UART1_base+0x10)
#define   UART1_LSR   (UART1_base+0x14)
#define   UART1_MSR   (UART1_base+0x18)
#define   UART1_SCR   (UART1_base+0x1c)
#define   UART1_DLL   (UART1_base+0x0)
#define   UART1_DLH   (UART1_base+0x4)
#define   UART1_EFR   (UART1_base+0x8)		/* Only when LCR = 0xbf */
#define   UART1_XON1  (UART1_base+0x10)		/* Only when LCR = 0xbf */
#define   UART1_XON2  (UART1_base+0x14)		/* Only when LCR = 0xbf */
#define   UART1_XOFF1  (UART1_base+0x18)	/* Only when LCR = 0xbf */
#define   UART1_XOFF2  (UART1_base+0x1c)	/* Only when LCR = 0xbf */
#ifdef DRV_UART_6205B_REG
   #define	UART1_RATE_STEP		(UART1_base+0x20)
   #define	UART1_STEP_COUNT		(UART1_base+0x24)
   #define	UART1_SAMPLE_COUNT   (UART1_base+0x28)
#endif   /*DRV_UART_6205B_REG*/
#if defined(DRV_UART_BASIC_REG)
   #define	UART1_AUTOBAUD_EN          		(UART1_base+0x20)
   #define	UART1_RATE_STEP		            (UART1_base+0x24)
   #define	UART1_STEP_COUNT		            (UART1_base+0x28)
   #define	UART1_SAMPLE_COUNT               (UART1_base+0x2c)
   #define	UART1_AUTOBAUD_REG               (UART1_base+0x30)
   #define	UART1_AUTO_BAUDSAMPLE(_baseaddr)		(UART1_base+0x38)

#endif   /*DRV_UART_BASIC_REG*/

#if defined(DRV_UART_VFIFO_EN_REG)
	#define	UART1_RXDMA(_baseaddr)						(UART1_base+0x4c)
#endif   /*DRV_UART_VFIFO_EN_REG*/

//used only in LISR or HISR
#define   UART2_RBR   (UART2_base+0x0)		/* Read only */
#define   UART2_THR   (UART2_base+0x0)		/* Write only */
#define   UART2_IER   (UART2_base+0x4)
#define   UART2_IIR   (UART2_base+0x8)		/* Read only */
#define   UART2_FCR   (UART2_base+0x8)		/* Write only */
#define   UART2_LCR   (UART2_base+0xc)
#define   UART2_MCR   (UART2_base+0x10)
#define   UART2_LSR   (UART2_base+0x14)
#define   UART2_MSR   (UART2_base+0x18)
#define   UART2_SCR   (UART2_base+0x1c)
#define   UART2_DLL   (UART2_base+0x0)
#define   UART2_DLH   (UART2_base+0x4)
#define   UART2_EFR   (UART2_base+0x8)		/* Only when LCR = 0xbf */
#define   UART2_XON1  (UART2_base+0x10)		/* Only when LCR = 0xbf */
#define   UART2_XON2  (UART2_base+0x14)		/* Only when LCR = 0xbf */
#define   UART2_XOFF1  (UART2_base+0x18)	/* Only when LCR = 0xbf */
#define   UART2_XOFF2  (UART2_base+0x1c)	/* Only when LCR = 0xbf */
#ifdef DRV_UART_6205B_REG
   #define	UART2_RATE_STEP		(UART2_base+0x20)
   #define	UART2_STEP_COUNT		(UART2_base+0x24)
   #define	UART2_SAMPLE_COUNT   (UART2_base+0x28)
#endif   /*DRV_UART_6205B_REG*/
#if defined(DRV_UART_BASIC_REG)
   #define	UART2_AUTOBAUD_EN          		(UART2_base+0x20)
   #define	UART2_RATE_STEP		            (UART2_base+0x24)
   #define	UART2_STEP_COUNT		            (UART2_base+0x28)
   #define	UART2_SAMPLE_COUNT               (UART2_base+0x2c)
   #define	UART2_AUTOBAUD_REG               (UART2_base+0x30)
   #define	UART2_AUTO_BAUDSAMPLE(UART2_base)		(UART2_base+0x38)

#endif   /*DRV_UART_BASIC_REG*/
#if defined(DRV_UART_VFIFO_EN_REG)
	#define	UART2_RXDMA(UART2_base)						(UART2_base+0x4c)
#endif

#if defined(DRV_UART_BASIC_REG)
#define   UART3_RBR   (UART3_base+0x0)		/* Read only */
#define   UART3_THR   (UART3_base+0x0)		/* Write only */
#define   UART3_IER   (UART3_base+0x4)
#define   UART3_IIR   (UART3_base+0x8)		/* Read only */
#define   UART3_FCR   (UART3_base+0x8)		/* Write only */
#define   UART3_LCR   (UART3_base+0xc)
#define   UART3_MCR   (UART3_base+0x10)
#define   UART3_LSR   (UART3_base+0x14)
#define   UART3_MSR   (UART3_base+0x18)
#define   UART3_SCR   (UART3_base+0x1c)
#define   UART3_DLL   (UART3_base+0x0)
#define   UART3_DLH   (UART3_base+0x4)
#define   UART3_EFR   (UART3_base+0x8)		/* Only when LCR = 0xbf */
#define   UART3_XON1  (UART3_base+0x10)		/* Only when LCR = 0xbf */
#define   UART3_XON2  (UART3_base+0x14)		/* Only when LCR = 0xbf */
#define   UART3_XOFF1  (UART3_base+0x18)	/* Only when LCR = 0xbf */
#define   UART3_XOFF2  (UART3_base+0x1c)	/* Only when LCR = 0xbf */
#define	 UART3_AUTOBAUD_EN          		(UART3_base+0x20)
#define	 UART3_RATE_STEP		            (UART3_base+0x24)
#define	 UART3_STEP_COUNT		            (UART3_base+0x28)
#define	 UART3_SAMPLE_COUNT               (UART3_base+0x2c)
#define	 UART3_AUTOBAUD_REG               (UART3_base+0x30)
#define	UART3_AUTO_BAUDSAMPLE(UART3_base)		(UART3_base+0x38)

#endif /*DRV_UART_BASIC_REG*/

#if defined(DRV_UART_VFIFO_EN_REG)
	#define	UART3_RXDMA(UART3_base)								(UART3_base+0x4c)
#endif /*DRV_UART_VFIFO_EN_REG*/

//IER
#define   UART_IER_ERBFI     	         0x0001
#define   UART_IER_ETBEI     	         0x0002
#define   UART_IER_ELSI     	         0x0004
#define   UART_IER_EDSSI   	         0x0008
#define   UART_IER_XOFFI    	         0x0020
#define   UART_IER_RTSI    	         0x0040
#define   UART_IER_CTSI    	         0x0080

#ifdef DRV_UART_6208_REG
   #define   UART1_IER_HW_NORMALINTS            0x000d
   #define   UART1_IER_HW_ALLINTS               0x000f
   #define   UART1_IER_SW_NORMALINTS    	      0x002d
   #define   UART1_IER_SW_ALLINTS       	      0x002f
   /*Disable MSR interrupt*/
   #define   UART2_IER_HW_NORMALINTS            0x0005
   #define   UART2_IER_HW_ALLINTS               0x0007
   #define   UART2_IER_SW_NORMALINTS    	      0x0025
   #define   UART2_IER_SW_ALLINTS       	      0x0027
#endif   /*DRV_UART_6208_REG*/
#if defined(DRV_UART_6205_REG) || defined(DRV_UART_6205B_REG) || defined(FPGA)|| defined(DRV_UART_BASIC_REG)
   #define   IER_HW_NORMALINTS                  0x000d
   #define   IER_HW_ALLINTS                     0x000f
   #define   IER_SW_NORMALINTS    	            0x002d
   #define   IER_SW_ALLINTS       	            0x002f
#endif   /*DRV_UART_6205_REG, DRV_UART_6205B_REG, FPGA, DRV_UART_BASIC_REG*/

#define   UART_IER_ALLOFF	            0x0000
#define   UART_IER_VFIFO			     0x0001	

#if defined(DRV_UART_6205B_REG) || defined(DRV_UART_BASIC_REG)
   #define	UART_RATE_STEP_16		   0x0000   /* baud = clock/UART_RATE_STEP/divisor */
   #define	UART_RATE_STEP_8		   0x0001
   #define	UART_RATE_STEP_4        0x0002
   #define	UART_RATE_STEP_COUNT    0x0003   /* baud = clock/UART_RATE_STEP_COUNT */
   #define  UART_STEP_COUNT_MASK    0x00ff
   #define  UART_SAMPLE_COUNT_MASK  0x00ff
#endif   /*DRV_UART_6205B_REG, DRV_UART_BASIC_REG*/

//FCR
#define   UART_FCR_FIFOEN              0x0001
#define   UART_FCR_CLRR    	         0x0002
#define   UART_FCR_CLRT    	         0x0004
#define   UART_FCR_FIFOINI	            0x0007
#define   UART_FCR_RX1Byte_Level    	0x0000
#define   UART_FCR_RX16Byte_Level    	0x0040
#define   UART_FCR_RX32Byte_Level    	0x0080
#define   UART_FCR_RX62Byte_Level    	0x00c0

#define   UART_FCR_TX1Byte_Level    	0x0000
#define   UART_FCR_TX16Byte_Level    	0x0010
#define   UART_FCR_TX32Byte_Level    	0x0020
#define   UART_FCR_TX62Byte_Level    	0x0030
#if ( (defined(SLEEP_DONT_CARE_DBG_INFO)) || (defined(__PRODUCTION_RELEASE__)) )
   #if defined(DRV_UART_6205_REG) || defined(FPGA)
	   #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX1Byte_Level | UART_FCR_FIFOINI)
	   #define   UART1_TxFIFO_DEPTH		         16
      #define   UART1_RxFIFO_DEPTH		         16
      #define   UART2_TxFIFO_DEPTH		         4
      #define   UART2_RxFIFO_DEPTH		         16
   #endif   /*DRV_UART_6205B_REG,FPGA*/
   
   #if defined(DRV_UART_BASIC_REG)
      #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX16Byte_Level | UART_FCR_FIFOINI)
	   #define   UART1_TxFIFO_DEPTH		         16
      #define   UART1_RxFIFO_DEPTH		         24
      #define   UART2_TxFIFO_DEPTH		         4
      #define   UART2_RxFIFO_DEPTH		         24
      #define	 UART_VFIFO_DEPTH						7
   #endif   /*DRV_UART_BASIC_REG*/
   
   #ifdef DRV_UART_6205B_REG
      #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX16Byte_Level | UART_FCR_FIFOINI)
	   #define   UART1_TxFIFO_DEPTH		         16
      #define   UART1_RxFIFO_DEPTH		         24
      #define   UART2_TxFIFO_DEPTH		         4
      #define   UART2_RxFIFO_DEPTH		         24
   #endif   /*DRV_UART_6205B_REG*/
   
   #ifdef DRV_UART_6208_REG
	   #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX32Byte_Level | UART_FCR_FIFOINI)
	   #define   UART_TxFIFO_DEPTH		         64
      #define   UART_RxFIFO_DEPTH		         32
   #endif /*DRV_UART_6208_REG*/
#else	/*!SLEEP_DONT_CARE_DBG_INFO*/
   #if defined(DRV_UART_6205_REG) || defined(FPGA)
	   #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX1Byte_Level | UART_FCR_FIFOINI)
	   #define   UART1_TxFIFO_DEPTH		         16
      #define   UART1_RxFIFO_DEPTH		         16
      #define   UART2_TxFIFO_DEPTH		         4
      #define   UART2_RxFIFO_DEPTH		         16
   #endif   /*DRV_UART_6205_REG,FPGA*/
   
   #if defined(DRV_UART_BASIC_REG)
      #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX16Byte_Level | UART_FCR_FIFOINI)
	   #define   UART1_TxFIFO_DEPTH		         16
      #define   UART1_RxFIFO_DEPTH		         24
      #define   UART2_TxFIFO_DEPTH		         4
      #define   UART2_RxFIFO_DEPTH		         24
      #define	 UART_VFIFO_DEPTH						7
   #endif   /*DRV_UART_BASIC_REG*/
   
   #ifdef DRV_UART_6205B_REG
	   #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX16Byte_Level | UART_FCR_FIFOINI)
	   #define   UART1_TxFIFO_DEPTH		         16
      #define   UART1_RxFIFO_DEPTH		         24
      #define   UART2_TxFIFO_DEPTH		         4
      #define   UART2_RxFIFO_DEPTH		         24
   #endif   /*DRV_UART_6205B_REG*/
   
   #ifdef DRV_UART_6208_REG
	   #define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX32Byte_Level | UART_FCR_FIFOINI)
	   #define   UART_TxFIFO_DEPTH		         64
      #define   UART_RxFIFO_DEPTH		         32
   #endif /*DRV_UART_6208_REG*/
#endif	/*SLEEP_DONT_CARE_DBG_INFO*/

//IIR,RO
#define   UART_IIR_INT_INVALID      	   0x0001
#define   UART_IIR_RLS          	         0x0006  // Receiver Line Status
#define   UART_IIR_RDA          	         0x0004  // Receive Data Available
#define   UART_IIR_CTI          	         0x000C  // Character Timeout Indicator
#define   UART_IIR_THRE         	         0x0002  // Transmit Holding Register Empty
#define   UART_IIR_MS           	         0x0000  // Check Modem Status Register
#define   UART_IIR_SWFlowCtrl             0x0010  // Receive XOFF characters
#define   UART_IIR_HWFlowCtrl          	0x0020  // CTS or RTS Rising Edge
#define   UART_IIR_FIFOS_ENABLED    	   0x00c0
#define   UART_IIR_NO_INTERRUPT_PENDING   0x0001
#define   UART_IIR_INT_MASK         	   0x001f

//===============================LCR================================
//WLS
#define   UART_WLS_8                      0x0003
#define   UART_WLS_7                      0x0002
#define   UART_WLS_6                      0x0001
#define   UART_WLS_5                      0x0000
#define   UART_DATA_MASK                  0x0003

//Parity
#define   UART_NONE_PARITY                0x0000
#define   UART_ODD_PARITY                 0x0008
#define   UART_EVEN_PARITY                0x0018
#define   UART_MARK_PARITY                0x0028
#define   UART_SPACE_PARITY               0x0038
#define   UART_PARITY_MASK                0x0038

//Stop bits
#define   UART_1_STOP                     0x0000
#define   UART_1_5_STOP                   0x0004  // Only valid for 5 data bits
#define   UART_2_STOP                     0x0004
#define   UART_STOP_MASK                  0x0004

#define   UART_LCR_DLAB                   0x0080
#define   UART_LCR_BREAK                  0x0040
//===============================LCR================================

//MCR
#define   UART_MCR_DTR    	               0x0001
#define   UART_MCR_RTS    	               0x0002
#define   UART_MCR_LOOPB    	            0x0010
#define   UART_MCR_IRE		               0x0040	//Enable IrDA modulation/demodulation
#define   UART_MCR_XOFF                   0x0080
#define   UART_MCR_Normal	               (UART_MCR_DTR | UART_MCR_RTS)

//LSR
#define   UART_LSR_DR         	         0x0001
#define   UART_LSR_OE         	         0x0002
#define   UART_LSR_PE         	         0x0004
#define   UART_LSR_FE         	         0x0008
#define   UART_LSR_BI         	         0x0010
#define   UART_LSR_THRE     	            0x0020
#define   UART_LSR_TEMT       	         0x0040
#define   UART_LSR_FIFOERR    	         0x0080

//MSR
#define   UART_MSR_DCTS                   0x0001
#define   UART_MSR_DDSR                   0x0002
#define   UART_MSR_TERI                   0x0004
#define   UART_MSR_DDCD                   0x0008
#define   UART_MSR_CTS                    0x0010
#define   UART_MSR_DSR                    0x0020
#define   UART_MSR_RI                     0x0040
#define   UART_MSR_DCD                    0x0080

//DLL
//DLM
//EFR
#define   UART_EFR_AutoCTS       	      0x0080
#define   UART_EFR_AutoRTS       	      0x0040
#define   UART_EFR_Enchance      	      0x0010
#define   UART_EFR_SWCtrlMask    	      0x000f
#define   UART_EFR_NoSWFlowCtrl   	      0x0000
#define   UART_EFR_ALLOFF		            0x0000
#define   UART_EFR_AutoRTSCTS       	   0x00c0
//Tx/Rx XON1/Xoff1 as flow control word
#define   UART_EFR_SWFlowCtrlX1   	      0x000a	
//Tx/Rx XON2/Xoff2 as flow control word
#define   UART_EFR_SWFlowCtrlX2   	      0x0005
//Tx/Rx XON1&XON2/Xoff1&Xoff2 as flow control word
#define   UART_EFR_SWFlowCtrlXAll   	   0x000f

/*AutoBaud*/
#if defined(DRV_UART_BASIC_REG)
#define   AUTOBAUD_EN          0x1
#define   AUTOBAUDSAMPLE_13M   0x6
#define   AUTOBAUDSAMPLE_26M   0xd 
#define   AUTOBAUDSAMPLE_52M   0x1b 

#endif   /*MDRV_UART_BASIC_REG*/

#if defined(DRV_UART_VFIFO_EN_REG)
#define	UART_RXDMA_ON							0x0001
#define  UART_RXDMA_OFF							0x0000
#define	UART_RXDMA_TIMEOUT				0x0002
#endif /*DRV_UART_VFIFO_EN_REG*/

#endif /*UART_HW_H*/


