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
 *   bl_uart.c
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   UART driver.
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
 
#include <kal_release.h>
#include <bl_uart_hw.h>
#include <bl_uart_sw.h>


// 52MHz based!
// 9: 115200 bps
// 8: 57600  bps
#define UART_BAUD_RATE        9  


kal_uint16   UART_Baud_Table[10] = {
//#if ( defined(MPLL_52MHZ) || defined(MPLL_104MHZ) )
#if ( defined(MCU_52M) || defined(MCU_104M) )
   29544,  10834, 2708,  1352, 676,  340, 168, 84, 56, 28};
#else
   14773,  5417,  1354,  677,  339,  169,  85, 42, 28, 14}; 
#endif


/**********************************************************
Description : UART register read write module
Input       : address to access, data to be written for write operation.
Output      : return data for read operation.
***********************************************************/

void UART_WriteReg(kal_uint32 addr, kal_uint16 data)
{
   *(volatile kal_uint8 *) addr = (kal_uint8)data;
}


kal_uint16 UART_ReadReg(kal_uint32 addr)
{
   volatile kal_uint8 tmp;
   tmp = *(volatile kal_uint8 *) addr;
   return (kal_uint16)tmp;
}


/**********************************************************
Description : UART put single/multiple bytes
Input       : 8-bits data to be sent
Output      : Non
***********************************************************/

void PutUARTByte(kal_uint8 data)
{
   volatile kal_uint16 LSR;

   while(1)
   {
      LSR = UART_ReadReg(UART1_LSR);
      if ( LSR & UART_LSR_THRE )
      {
         UART_WriteReg(UART1_THR, (kal_uint16)data);
         break;
      }
   }
}


/**********************************************************
Description : Checking end of transferring
Input       : Non
Output      : Non
***********************************************************/

void CheckUARTSendEnd(void)
{
  kal_uint16 LSR;
  kal_uint16 timeout=0xffff;

  while(timeout--)
  {
    LSR = UART_ReadReg(UART1_LSR);
    if ( LSR & UART_LSR_TEMT )
      break;
  }
}

/**********************************************************
Description : UART initialization
Input       : Non
Output      : Non
***********************************************************/

void uart_init(void)
{
   volatile kal_uint16 tmp;
   
   // Setup 8-N-1,(UART_WLS_8 | UART_NONE_PARITY | UART_1_STOP) = 0x03
   UART_WriteReg(UART1_LCR,0x0003);
  
   // Set BaudRate 
   tmp = UART_ReadReg(UART1_LCR);
   tmp |= UART_LCR_DLAB;
   UART_WriteReg(UART1_LCR, tmp);
   // config by UART_BAUD_RATE(9:115200)
   UART_WriteReg(UART1_DLL, UART_Baud_Table[UART_BAUD_RATE]&0xff);  
   UART_WriteReg(UART1_DLH, UART_Baud_Table[UART_BAUD_RATE]>>8);
   UART_WriteReg(UART1_LCR, 0x0003);
   // Enable Fifo, and Rx Trigger level = 16bytes, flush Tx, Rx fifo
   // (UART_FCR_FIFOEN | UART_FCR_4Byte_Level | UART_FCR_RFR | UART_FCR_TFR) = 0x47
   UART_WriteReg(UART1_FCR, 0x0047);

   // DTR , RTS is on, data will be coming,Output2 is high
   UART_WriteReg(UART1_MCR,(kal_uint16)0x0003);
  
   // UART1_IER, enable RDA, RLS, MS , disable THR interrupt
   // UART_WriteReg(UART1_IER, UART_IER_RDA);
   UART_WriteReg(UART1_IER, IER_HW_NORMALINTS);
   //IRQSensitivity(IRQ_UART1_CODE, LEVEL_SENSITIVE);
   //IRQUnmask(IRQ_UART1_CODE);
   
   for (tmp=0; tmp<0xff; tmp++);
}
