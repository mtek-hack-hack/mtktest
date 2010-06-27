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
 *    TouchPad.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for keypad table
 *
 * Author:msz00184
 * -------
 * 
 *
 *============================================================================
*/ 
#if (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__))

#ifndef _TOUCHPAD_CUSTOM_H_
#define _TOUCHPAD_CUSTOM_H_
#endif

#include "stdlib.h"
#include "kal_release.h"    /* Basic data type */
#include "stack_common.h"   /* message and module IDs */
#include "stack_msgs.h"     /* enum for message IDs */
#include "app_ltlcom.h"     /* Task message communiction */
#include "syscomp_config.h" /* type of system module components */
#include "task_config.h"    /* Task creation */
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /* Stack timer */
#include "drv_comm.h"
#include "kbd_table.h"
#include "keypad_sw.h"
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */
#include "syscomp_config.h"
#include "custom_config.h"
#include "gpio_sw.h"
#include "intrCtrl.h"
#include "eint.h"
#include "sccb.h"
#include "GlobalConstants.h"

#include "uart_sw.h"
#include "eint.h"
#include "gpt_sw.h"

//extern void touchpad_ic_reset_to_normal(void);
//extern void touchpad_ic_reset_to_sleep(void);

extern void Touchpad_Init(void);
extern void Touchpad_HISR(void);
 
extern kbd_struct KBD;
extern kal_bool send_kbdilm;

//#define TOUCHPAD_DEBUG
#define TOUCH_PAD_USE_KEY_COLUMN

#if defined(TOUCH_PAD_USE_KEY_COLUMN)
    #define TOUCH_PAD_KEY_COLUMN_NUM    (2)
#endif

#define TOUCHPAD_UART_PORT  (uart_port2)    /* UART port for TOUCHPAD */
#define TOUCHPAD_UART_BAUD_RATE (38400)     /* defaule UART baud rate  */

#define TOUCHPAD_UART_SetOwner UART_SetOwner
#define TOUCHPAD_UART_GetBytes UART_GetBytes
#define TOUCHPAD_UART_PutBytes PutUARTByte
#define TOUCHPAD_UART_ClrTxBuffer UART_ClrTxBuffer
#define TOUCHPAD_UART_ClrRxBuffer UART_ClrRxBuffer

#define TOUCHPAD_MAX_UART_LENGTH    (2) // MAX length of controller return data in bytes

#define MAX_TOUCHPAD_KEY    (10)    // MAX. touch keys can be supported

#ifdef __CUST_NEW__
   extern const char gpio_touchpad_ldo_pw_pin;
   extern const char gpio_touchpad_low_pw_pin;
   #define TOUCH_PAD_KEY_LDO_POWER  gpio_touchpad_ldo_pw_pin    // touchpad power pin
   #define TOUCH_PAD_KEY_LOW_POWER  gpio_touchpad_low_pw_pin    // touchpad lower power mode control pin
#else /*__CUST_NEW__*/
   #define TOUCH_PAD_KEY_LDO_POWER (30)    // touchpad power pin
   #define TOUCH_PAD_KEY_LOW_POWER (29)    // touchpad lower power mode control pin
#endif /*__CUST_NEW__*/

#define KEYPAD_SCANNER_COL  (7)
#define KEYPAD_SCANNER_ROW  (6)
#define KEYPAD_SCANNER_KEYS (KEYPAD_SCANNER_COL * KEYPAD_SCANNER_ROW)

#define COL_BASIC_REG         (0x10204081)
#define COL_BASIC_REG1        (0x81020408)
#define KEYPAD_SCANNER_REG    (COL_BASIC_REG << TOUCH_PAD_KEY_COLUMN_NUM) //(0x40810204)
#define KEYPAD_SCANNER_REG1   (0x3FF & (COL_BASIC_REG1 >> (KEYPAD_SCANNER_COL - TOUCH_PAD_KEY_COLUMN_NUM))) //(0x00000020)

typedef enum{
	KBD_OWNER_NONE = 0,
	KBD_OWNER_KEYPAD	= 1,
	KBD_OWNER_TOUCHPAD = 2
}kbd_owner_enum;

#endif  /*  (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__)) */
