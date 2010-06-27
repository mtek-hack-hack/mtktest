/*************************************************************************
 *
 * MODULE NAME:    rda5868_uart.c
 * PROJECT CODE:   rda5868
 * DESCRIPTION:    rda5868 uart drv.
 * MAINTAINER:     mql
 * CREATION DATE:  18/12/08
 *
 * SOURCE CONTROL: $Id: rda5868_uart.c,v 2.6 2009/8/14 18:08:38 mql Exp $
 *
 * LICENSE:
 *     This source code is copyright (c) 2008-2009 rda.
 *     All rights reserved.
 *
 * NOTES TO USERS:
 *   None.
 *		
 *************************************************************************/
#ifdef __BT_RDA5868__
#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"          /* message and module IDs */
#include "stack_msgs.h"            /* enum for message IDs */
#include "app_ltlcom.h"       	/* Task message communiction */
#include "syscomp_config.h"         /* type of system module components */
#include "task_config.h"      	/* Task creation */
#include "stacklib.h"        	   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       	/* Event scheduler */
#include "stack_timer.h"      	/* Stack timer */
#include "stdio.h"                  /* Basic C I/O functions */
#include "eint.h"                   /* External interrupt */

#include "uart_sw.h"               /* header file for UART */
#include "Bt_hw_define.h"
#include "rda5868.h"





#define RDA5868_RX_BUF_SIZE   128
/*****************************************************************************
* FUNCTION
*   rda5868_uart_stop
* DESCRIPTION
*   Stop uart
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void rda5868_uart_stop(void)
{
   UART_Close(BT_UART_PORT, MOD_MMI);
   UART_TurnOnPower(BT_UART_PORT, KAL_FALSE);
}


/*****************************************************************************
* FUNCTION
*   rda5868_uart_start
* DESCRIPTION
*   Start UART for 5868
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void rda5868_uart_start(void)
{
   UART_TurnOnPower(BT_UART_PORT, KAL_TRUE);
   UART_Open (BT_UART_PORT, MOD_MMI);
   
}

/*****************************************************************************
* FUNCTION
*   rda5868_uart_configure
* DESCRIPTION
*   Configure baud rate of UART
* PARAMETERS
*   baud    IN    baud rate of UART port
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void rda5868_uart_configure(unsigned baud)
{
   UARTDCBStruct dcb =
   {
      UART_BAUD_921600,    /* init */
      len_8,                 /* dataBits; */
      sb_1,                 /* stopBits; */
      pa_none,              /* parity; */
      fc_none,
      0x11,                 /* xonChar; */
      0x13,                 /* xoffChar; */
      KAL_FALSE
   };

   dcb.baud = (UART_baudrate)baud;

   UART_SetDCBConfig (BT_UART_PORT, &dcb, MOD_MMI);
}


/*****************************************************************************
* FUNCTION
*   rda5868_uart_rx
* DESCRIPTION
*   Read Rx buffer in UART when receive READY_TO_READ_IND or DATA_TO_READ_IND
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void rda5868_uart_rx(void)
{
   kal_uint16 rx_length;
   kal_uint8 rx_buff[128];
   kal_uint8 status;
   rx_length = UART_GetBytes(BT_UART_PORT, rx_buff, RDA5868_RX_BUF_SIZE, &status, MOD_MMI);
      
}


/*****************************************************************************
* FUNCTION
*   rda5868_uart_tx
* DESCRIPTION
*   Send data to Tx buffer
* PARAMETERS
*   buf            IN      buffer of data to be sent
*   num_to_send   IN       number of bytes to be sent
*   num_send      OUT     buffer to store actual size of data sent.
* RETURNS
*   TRUE if all bytes sent; otherwise, FALSE.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
unsigned char rda5868_uart_tx(kal_uint8 *buf, unsigned short num_to_send, unsigned short *num_send)
{

   
   *num_send = (kal_uint16)UART_PutBytes(BT_UART_PORT, (kal_uint8*)buf, (kal_uint16)num_to_send, MOD_MMI);

  // kal_prompt_trace(0, "num_to_send: %d, num_send: %d", num_to_send, *num_send);
   if(*num_send == num_to_send)
      return KAL_TRUE;
   else
   {
      return KAL_FALSE;
   }
}



/*****************************************************************************
* FUNCTION
*   RDA5868_uart_rx_cb
* DESCRIPTION
*   Callback function when RX interrupt comes
* PARAMETERS
*   port	IN UART power number
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void RDA5868_uart_rx_cb(UART_PORT port)
{
   ilm_struct *msg;
   ASSERT(port == BT_UART_PORT);

    msg = allocate_ilm(MOD_UART3_HISR);
    msg->src_mod_id = MOD_UART3_HISR;
    msg->dest_mod_id = MOD_MMI;
    msg->sap_id = INVALID_SAP;
    msg->msg_id = MSG_ID_UART_READY_TO_READ_IND;
    msg->local_para_ptr = NULL;
    msg->peer_buff_ptr = NULL;
    msg_send_ext_queue_to_head(msg);

}


void RDA5868_uart_tx_cb(UART_PORT port)
{
   ilm_struct *msg;
   ASSERT(port == BT_UART_PORT);

   msg = allocate_ilm(MOD_UART3_HISR);
   msg->src_mod_id = MOD_UART3_HISR;
   msg->dest_mod_id = MOD_MMI;
   msg->sap_id = INVALID_SAP;
   msg->msg_id = MSG_ID_UART_READY_TO_WRITE_IND;
   msg->local_para_ptr = NULL;
   msg->peer_buff_ptr = NULL;
   msg_send_ext_queue_to_head(msg);

}

void RDA5868_uart_register_cb(void)
{
#ifdef __MTK_TARGET__
   UART_Register_RX_cb(BT_UART_PORT, MOD_MMI, RDA5868_uart_rx_cb);
   UART_Register_TX_cb(BT_UART_PORT, MOD_MMI, RDA5868_uart_tx_cb);
#endif
}

/*
void rda5868_uart_write(kal_uint8 *data[],kal_uint8 len,kal_uint8 num)
{
}
*/
#endif



