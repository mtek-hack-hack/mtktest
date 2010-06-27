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
 *    dma_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for DMA driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef _DMA_HW_H
#define _DMA_HW_H

#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )
   /*****************
    * DMA Registers *
    *****************/
   #define DMA_GLBSTS                  (DMA_base+0x0000) /*Global status register */
   /* ch#1 (USB) */                    
   #define DMA1_MSBSRC                 (DMA_base+0x0004) /*Address source MSB bits */
   #define DMA1_LSBSRC                 (DMA_base+0x0008) /*Address source LSB bits */
   #define DMA1_MSBDST                 (DMA_base+0x000C) /*Address dest MSB bits   */
   #define DMA1_LSBDST                 (DMA_base+0x0010) /*Address dest LSB bits   */
   #define DMA1_COUNT                  (DMA_base+0x0014) /*Transfer count          */
   #define DMA1_CONTRL                 (DMA_base+0x0018) /*Control register        */
   #define DMA1_START                  (DMA_base+0x001C) /*Start register          */
   #define DMA1_INTSTS                 (DMA_base+0x0020) /*Interrupt status        */
   #define DMA1_ACKINT                 (DMA_base+0x0024) /*Interrupt acknowledge   */
   /* ch#2 (DSP) */                    
   #define DMA2_MSBSRC                 (DMA_base+0x0104) /*Address source MSB bits */
   #define DMA2_LSBSRC                 (DMA_base+0x0108) /*Address source LSB bits */
   #define DMA2_MSBDST                 (DMA_base+0x010C) /*Address dest MSB bits   */
   #define DMA2_LSBDST                 (DMA_base+0x0110) /*Address dest LSB bits   */
   #define DMA2_COUNT                  (DMA_base+0x0114) /*Transfer count          */
   #define DMA2_CONTRL                 (DMA_base+0x0118) /*Control register        */
   #define DMA2_START                  (DMA_base+0x011C) /*Start register          */
   #define DMA2_INTSTS                 (DMA_base+0x0120) /*Interrupt status        */
   #define DMA2_ACKINT                 (DMA_base+0x0124) /*Interrupt acknowledge   */
                                       
                                       
   #define DMA_GLBSTS_RUN1             0x0001
   #define DMA_GLBSTS_RUN2             0x0010
   #define DMA_GLBSTS_IT1              0x0002
   #define DMA_GLBSTS_IT2              0x0020
                                       
   #define DMA_CON_SIZEMASK            0x0003
                                       
   #define DMA_CON_SIZE_MASK           0x0003
   #define DMA_CON_SINC                0x0004
   #define DMA_CON_DINC                0x0008
   #define DMA_CON_DRQ                 0x0010   /*1: HW management,0:SW */
   #define DMA_CON_TMOD                0x0020   /*1: Block mode, 0:Single mode*/
   #define DMA_CON_MAS                 0x0100   /*00:,01:UART1 Rx(1)/UART1 Tx(2),10: UART2 tx(1),UART2 rx(2),11:SIM*/
   #define DMA_CON_CYCLE_MASK          0x3e00   /* Burst mode cycle */
   #define DMA_CON_ITEN                0x8000   /*Interrupt enable*/
   
   //Size = 8bit, sinc en, dinc disable, hw management, 
   //1 trans/dma cycle, UART1 master,Interrupt enable
   #define DMA_CON_UART1TxNormal       0x8034
   //Size = 8bit, sinc disable, dinc enable, hw management, 
   //1 trans/dma cycle, UART1 master,Interrupt enable
   #define DMA_CON_UART1RxNormal       0x8038
   //Size = 8bit, sinc en, dinc disable, hw management, 
   //1 trans/dma cycle, UART2 master,Interrupt enable
   #define DMA_CON_UART2TxNormal       0x8054
   //Size = 8bit, sinc disable, dinc enable, hw management, 
   //1 trans/dma cycle, UART2 master,Interrupt enable
   #define DMA_CON_UART2RxNormal       0x8058
   //Size = 32bit, sinc en, dinc disable, hw management, 
   //1 trans/dma cycle, USB master,Interrupt enable
   #define DMA_CON_USBTxNormal         0x8016
   //Size = 32bit, sinc disable, dinc enable, hw management, 
   //1 trans/dma cycle, USB master,Interrupt enable
   #define DMA_CON_USBRxNormal         0x801a
   
   #define DMA_START_BIT               0x8000
   #define DMA_STOP_BIT                0x0000
   
   #define DMA_INTSTS_MASK             0x8000
   
   #define DMA_ACKINT_BIT              0x8000

#else

   /*4~11 hw management dma, 1~3 are normal dma*/
   #define DMA_GLBSTA                  (DMA_base+0x0000) 
   #define DMA_SRC(_n)                 (DMA_base+(0x0100*(_n)))           /*_n = 1~3*/
   #define DMA_DST(_n)                 (DMA_base+0x0004+(0x0100*(_n)))    /*_n = 1~3*/
   #define DMA_WPPT(_n)                (DMA_base+0x0008+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_WPTO(_n)                (DMA_base+0x000c+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_COUNT(_n)               (DMA_base+0x0010+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_CON(_n)                 (DMA_base+0x0014+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_START(_n)               (DMA_base+0x0018+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_INTSTA(_n)              (DMA_base+0x001c+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_ACKINT(_n)              (DMA_base+0x0020+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_RLCT(_n)                (DMA_base+0x0024+(0x0100*(_n)))    /*_n = 1~11*/  /*DEBUG*/
   #define DMA_LIMITER(_n)             (DMA_base+0x0028+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_PGMADDR(_n)             (DMA_base+0x002c+(0x0100*(_n)))    /*_n = 4~11*/
                                       
   #define DMA_GLBSTA_RUN(_n)          (0x00000001 << (2*(_n-1)))  /*_n = 1~11*/
   #define DMA_GLBSTA_IT(_n)           (0x00000002 << (2*(_n-1)))  /*_n = 1~11*/
                                       
   #define DMA_COUNT_MASK              0xffff
                                       
   /*DMA_CON*/                         
   #define DMA_CON_SIZE_MASK           0x00000003
   #define DMA_CON_SIZE_BYTE           0x00000000
   #define DMA_CON_SIZE_SHORT          0x00000001
   #define DMA_CON_SIZE_LONG           0x00000002
                                       
   #define DMA_CON_SINC                0x00000004
   #define DMA_CON_DINC                0x00000008
   #define DMA_CON_DRQ                 0x00000010  /*1:hw, 0:sw*/
                                       
#ifdef MT6218                          
   #define DMA_CON_TMOD                0x00000100  /*1:burst, 0:single*/
   #define DMA_CON_CYCLE_MASK          0x00003e00  /*burst cycle*/
#else                                  
   #define DMA_CON_B2W                 0x00000020  /*word to byte or byte to word*/
   #define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
   #define DMA_CON_BURST_4BEAT         0x00000200  /*4-beat incrementing burst*/
   #define DMA_CON_BURST_8BEAT         0x00000400  /*8-beat incrementing burst*/
   #define DMA_CON_BURST_16BEAT        0x00000600  /*16-beat incrementing burst*/
#endif                                 
                                       
   #define DMA_CON_ITEN                0x00008000  /*Interrupt enable*/
   #define DMA_CON_WPSD                0x00010000  /*0:at source, 1: at destination*/
   #define DMA_CON_WPEN                0x00020000  /*0:disable, 1: enable*/
   #define DMA_CON_DIR                 0x00040000  /*Only valid when dma = 4~11*/
   #define DMA_CON_MASTER_MASK         0x00f00000  /*Only valid when dma = 4~11*/
                                       
   #define DMA_CON_RXCONTRL            (DMA_CON_DIR|DMA_CON_DINC) /*hw management*/
   #define DMA_CON_TXCONTRL            (DMA_CON_SINC) /*hw management*/
   #define DMA_CON_SWCOPY              (DMA_CON_SINC|DMA_CON_DINC) /*hw management*/
                                       
   #define DMA_CON_MASTER_SIM          0x00
   #define DMA_CON_MASTER_MSDC         0x01
   #define DMA_CON_MASTER_IRDATX       0x02
   #define DMA_CON_MASTER_IRDARX       0x03
   #if defined(MT6238)
   
   #define DMA_CON_MASTER_RESERVED_1       0x04
   #define DMA_CON_MASTER_RESERVED_2       0x05
   #define DMA_CON_MASTER_RESERVED_3       0x06
   #define DMA_CON_MASTER_RESERVED_4       0x07
   
   #else
   
   #define DMA_CON_MASTER_USB1RX       0x04
   #define DMA_CON_MASTER_USB1TX       0x05
   #define DMA_CON_MASTER_USB2RX       0x06
   #define DMA_CON_MASTER_USB2TX       0x07
   
   #endif

   #define DMA_CON_MASTER_UART1TX      0x08
   #define DMA_CON_MASTER_UART1RX      0x09
   #define DMA_CON_MASTER_UART2TX      0x0a
   #define DMA_CON_MASTER_UART2RX      0x0b
   #define DMA_CON_MASTER_UART3TX      0x0c
   #define DMA_CON_MASTER_UART3RX      0x0d
   #define DMA_CON_MASTER_IDMA         0x0e
   
#if ( !defined(MT6218B) && !defined(MT6217) )
   #define DMA_CON_MASTER_NFITX        0x0f
   #define DMA_CON_MASTER_NFIRX        0x10
#endif                                 
                                       
#if defined(MT6238)
   #define DMA_CON_MASTER_DSPDMA2       0x11
   #define DMA_CON_MASTER_I2CTX        	0x12
   #define DMA_CON_MASTER_I2CRX        	0x13
   #define DMA_CON_MASTER_MSDC2        	0x14
   #define DMA_CON_MASTER_SIM2        	0x15
 #endif

   #define DMA_START_BIT               0x00008000
   #define DMA_STOP_BIT                0x00000000
   #define DMA_ACKINT_BIT              0x00008000
   #define DMA_INTSTA_BIT              0x00008000
                                       
   #define DMA_RLCT_MASK               0x0000ffff
                                       
   #define DMA_LIMITER_MASK            0x000000ff
   // add for virtual fifo
#if ( defined(MT6218B) || defined(MT6217) )
   #define DMA_VFIFO_CH_S               10      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               13      // end of DMA Virtual fifo    
#else                                  
   #define DMA_VFIFO_CH_S               11      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               14      // end of DMA Virtual fifo    
#endif                                 
                                       

#if defined(MT6238)       
   #define DMA_VPORT_BASE              0x61000000
#else  /* MT6238 */
   #define DMA_VPORT_BASE              0x78000000
#endif  /* MT6238 */

   #define DMA_VPORT(_n)               (DMA_VPORT_BASE+0x0100*(_n-DMA_VFIFO_CH_S))    /*_n = 10~13*/
   #define DMA_WRPTR(_n)               (DMA_base+0x0030+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_RDPTR(_n)               (DMA_base+0x0034+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFCNT(_n)               (DMA_base+0x0038+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFSTA(_n)               (DMA_base+0x003c+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_ALTLEN(_n)              (DMA_base+0x0040+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFSIZE(_n)              (DMA_base+0x0044+(0x0100*(_n)))    /*_n = 10~13*/

   #define DMA_FFSTA_FULL              0x0001
   #define DMA_FFSTA_EMPTY             0x0002
   #define DMA_FFSTA_ALERT             0x0004

   #define DMA_POP(_n)                 *(volatile kal_uint8*)DMA_VPORT(_n)
   #define DMA_PUSH(_n,_data)          *(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data
   #define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
   #define DMA_GetVFIFO_Roomleft(ch)   DRV_Reg(DMA_FFSIZE(ch)) - DMA_GetVFIFO_Avail(ch)
   #define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_FFSTA(ch)) & DMA_FFSTA_FULL)
   #define DMA_EnableINT(ch)           DRV_Reg32(DMA_CON(ch)) |= DMA_CON_ITEN
   #define DMA_DisableINT(ch)          DRV_Reg32(DMA_CON(ch)) &= ~DMA_CON_ITEN
   #define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                       DMA_PUSH(ch,data)   

#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
#else   /* __WCDMA_RAT__ */
   #define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)      // trigger level of tx vfifo
#endif  /* __WCDMA_RAT__ */

   #define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo

   #define DMA_VIFOF_ALERT_LENGTH      0x3f         // flow control trigger level
   
#endif


#endif

