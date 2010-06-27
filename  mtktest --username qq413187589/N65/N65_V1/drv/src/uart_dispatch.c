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
 *    UartDispatch.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 *============================================================================*/
#include "kal_release.h"
#include "uart_sw.h"

static UartHandle_struct UartHandle[uart_max_port];

void UART_Register(UART_PORT port, UartType_enum type, UartDriver_strcut* drv)
{
	ASSERT(port <= uart_max_port);
	UartHandle[port].type = type;
	UartHandle[port].drv = drv;
}

kal_bool UART_Open(UART_PORT port, module_type ownerid)
{
   if (port == uart_port_null)
      return KAL_FALSE;
	ASSERT(UartHandle[port].drv->Open);
	return UartHandle[port].drv->Open(port,ownerid);
}

void UART_Close(UART_PORT port, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->Close);
	UartHandle[port].drv->Close(port, ownerid);	
}

kal_uint16 UART_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->GetBytes);
	return UartHandle[port].drv->GetBytes(port, Buffaddr,Length,status,ownerid);
}

kal_uint16 UART_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->PutBytes);
	return UartHandle[port].drv->PutBytes(port, Buffaddr,Length,ownerid);
}

kal_uint16 UART_GetBytesAvail(UART_PORT port)
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->GetRxAvail);
	return UartHandle[port].drv->GetRxAvail(port);
}

kal_uint16 UART_GetTxRoomLeft(UART_PORT port)
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->GetTxAvail);
	return UartHandle[port].drv->GetTxAvail(port);
}

kal_uint16 UART_PutISRBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->PutISRBytes);
	return UartHandle[port].drv->PutISRBytes(port, Buffaddr,Length,ownerid);
}

kal_uint16 UART_GetTxISRRoomLeft(UART_PORT port)
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->GetISRTxAvail);
	return UartHandle[port].drv->GetISRTxAvail(port);	
}

kal_uint16 UART_SendISRData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->SendISRData);
	return UartHandle[port].drv->SendISRData(port, Buffaddr, Length, mode, escape_char, ownerid);		
}

kal_uint16 UART_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid )
{
   if (port == uart_port_null)
      return 0;
	ASSERT(UartHandle[port].drv->SendData);
	return UartHandle[port].drv->SendData(port, Buffaddr, Length, mode, escape_char, ownerid);		
}
void UART_Purge(UART_PORT port, UART_buffer dir, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->Purge);
	UartHandle[port].drv->Purge(port,dir, ownerid);
}

void UART_SetOwner (UART_PORT port, kal_uint8 ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->SetOwner);
	UartHandle[port].drv->SetOwner(port,ownerid);
	
}

void UART_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->SetFlowCtrl);
	UartHandle[port].drv->SetFlowCtrl(port,XON, ownerid);
}

void UART_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->ConfigEscape);
	UartHandle[port].drv->ConfigEscape(port,EscChar,ESCGuardtime, ownerid);
	
}

void UART_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->SetDCBConfig);
	UartHandle[port].drv->SetDCBConfig(port,UART_Config, ownerid);	
}

void UART_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid)  
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->CtrlDCD);
	UartHandle[port].drv->CtrlDCD(port,SDCD, ownerid);
}

void UART_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->CtrlBreak);
	UartHandle[port].drv->CtrlBreak(port,SBREAK, ownerid);	
}

void UART_ClrRxBuffer(UART_PORT port, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->ClrRxBuffer);
	UartHandle[port].drv->ClrRxBuffer(port, ownerid);
}

void UART_ClrTxBuffer(UART_PORT port, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->ClrTxBuffer);
	UartHandle[port].drv->ClrTxBuffer(port, ownerid);
}

void UART_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid)
{
   if (port == uart_port_null)
      return;
	ASSERT(UartHandle[port].drv->SetBaudRate);
	UartHandle[port].drv->SetBaudRate(port,baudrate, ownerid);	
}
module_type UART_GetOwnerID(UART_PORT port)
{
   if (port == uart_port_null)
      return MOD_NIL;
	ASSERT(UartHandle[port].drv->GetOwnerID);
	return UartHandle[port].drv->GetOwnerID(port);	
}
void UART_SetAutoBaud_Div(UART_PORT port, module_type ownerid)
{
   if (port == uart_port_null)
      return;
   ASSERT(UartHandle[port].drv->SetAutoBaud_Div);
	UartHandle[port].drv->SetAutoBaud_Div(port, ownerid);		
}
/*TY adds these to expand flexibility 2004/10/15*/
void UART_Register_TX_cb(UART_PORT port, module_type ownerid, UART_TX_FUNC func)
{
   if (port == uart_port_null)
      return;
   ASSERT(UartHandle[port].drv->UART_Register_TX_cb);
	UartHandle[port].drv->UART_Register_TX_cb(port, ownerid, func);		
}
void UART_Register_RX_cb(UART_PORT port, module_type ownerid, UART_RX_FUNC func)
{
   if (port == uart_port_null)
      return;
   ASSERT(UartHandle[port].drv->UART_Register_RX_cb);
	UartHandle[port].drv->UART_Register_RX_cb(port, ownerid, func);		
}
/*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/
kal_uint8 GetUARTByte(UART_PORT port)
{
   if (port == uart_port_null)
      return 0;
   ASSERT(UartHandle[port].drv->GetUARTByte);	
	return UartHandle[port].drv->GetUARTByte(port);
}   
void PutUARTByte(UART_PORT port, kal_uint8 data)
{
   if (port == uart_port_null)
      return;
   ASSERT(UartHandle[port].drv->PutUARTByte);	
	UartHandle[port].drv->PutUARTByte(port, data);
}   
void PutUARTBytes(UART_PORT port, kal_uint8 *data, kal_uint16 len)
{
   if (port == uart_port_null)
      return;
   ASSERT(UartHandle[port].drv->PutUARTByte);	
	UartHandle[port].drv->PutUARTBytes(port, data, len);		   
}
void UART_ReadDCBConfig(UART_PORT port, UARTDCBStruct *DCB)
{
   if (port == uart_port_null)
      return;
   ASSERT(UartHandle[port].drv->ReadDCBConfig);	
	UartHandle[port].drv->ReadDCBConfig(port, DCB);		   
}
void UART_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid)    
{
   if (port == uart_port_null)
      return;
   if(UartHandle[port].drv->CtrlRI!=NULL)   
      UartHandle[port].drv->CtrlRI(port, SRI, ownerid);		   
}  
void UART_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid)
{
   if (port == uart_port_null)
      return;
   if(UartHandle[port].drv->CtrlDTR!=NULL)   
      UartHandle[port].drv->CtrlDTR(port, SDTR, ownerid);
}
void UART_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS)
{
   if (port == uart_port_null)
      return;
   if(UartHandle[port].drv->ReadHWStatus!=NULL)   
      UartHandle[port].drv->ReadHWStatus(port, SDSR, SCTS);
}   