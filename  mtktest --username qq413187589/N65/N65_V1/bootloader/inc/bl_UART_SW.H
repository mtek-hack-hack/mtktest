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
 *   bl_uart_sw.h
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
 
#ifndef _BOOTLOADER_UART_SW_H
#define _BOOTLOADER_UART_SW_H

#include <bl_UART_HW.H>

/*
 * Baud rates.
 */
typedef enum {
    UART_BAUD_75,
    UART_BAUD_150,
    UART_BAUD_300,
    UART_BAUD_600,
    UART_BAUD_1200,
    UART_BAUD_2400,
    UART_BAUD_4800,
    UART_BAUD_7200,
    UART_BAUD_9600,
    UART_BAUD_14400,
    UART_BAUD_19200,
    UART_BAUD_28800,
    UART_BAUD_38400,
    UART_BAUD_57600,
    UART_BAUD_115200
} T_baudrate;


/*
 * Bits per character.
 */
typedef enum {
    wls_5,
    wls_6,
    wls_7,
    wls_8
} T_bitsPerCharacter;


/*
 * Stop bits.
 */
typedef enum {
    sb_1,
    sb_2,
    sb_1_5
} T_stopBits;


/*
 * Parity.
 */
typedef enum {
    pa_none,
    pa_even,
    pa_odd,
    pa_space,
    pa_mark
} T_parity;


/*
 * Flow control mode.
 */
typedef enum {
    fc_none,
    fc_rts,
    fc_dtr,
    fc_xoff
} T_flowCtrlMode;


/*
 * Interrupt.
 */
typedef enum {
    Int_MS,
    Int_RLS,
    Int_THR,
    Int_RDA
} T_Interrupt;


void uart_init(void);
void UART_PutBytes(kal_uint8 *, kal_uint16 , kal_uint16 *);
void UART_GetBytes(kal_uint8 *, kal_uint16 , kal_uint16 *);
void GetUARTByte_nonLoop(kal_uint8 *, kal_uint16 *);
void PutUARTByte(kal_uint8 data);
kal_uint8   GetUARTByte(void);
void UART_WriteReg(kal_uint32 addr, kal_uint16 data);
kal_uint16 UART_ReadReg(kal_uint32 addr);

void uart2_init(void);
void UART2_LISR(void);

#define UART2_RX_BUFFER_SIZE	1024
#define UART2_TX_BUFFER_SIZE	1024

extern kal_uint8 uart2_rx_buffer[UART2_RX_BUFFER_SIZE];
extern kal_uint8 uart2_tx_buffer[UART2_TX_BUFFER_SIZE];
extern kal_uint16 uart2_tx_buffer_count;
extern kal_uint16 uart2_rx_buffer_head;
extern kal_uint16 uart2_rx_buffer_tail;
extern kal_uint16 uart2_tx_buffer_head;
extern kal_uint16 uart2_tx_buffer_tail;

extern kal_uint32 uart2_tx_size;
extern kal_uint32 uart2_tx_offset;
extern kal_uint32 uart2_rx_size;
extern kal_uint32 uart2_rx_offset;
extern kal_uint32 uart2_tx_file_base_address;
extern kal_uint8 uart2_rx_check_sum;
extern kal_uint8 uart2_tx_check_sum;

kal_uint16 uart2_get_byte(void);

#endif