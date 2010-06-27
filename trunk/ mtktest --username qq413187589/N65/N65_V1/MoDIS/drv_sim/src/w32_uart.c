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
 *   w32_uart.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Uart simulating functions
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <windows.h>
#include <stdio.h>

#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "app_buff_alloc.h"

#include "stacklib.h"
#include "stack_timer.h"

#include "syscomp_config.h"
#include "task_config.h"

#include "device.h"
#include "uart_sw.h"

#define MAX_PORT_NUM 256

UARTStruct	UARTPort[MAX_PORT_NUM] = {0};
HANDLE		UARTHandle[MAX_PORT_NUM] = {0};
COMSTAT		comstat[MAX_PORT_NUM] = {0};
kal_bool    g_b_ISR_flag = KAL_FALSE;

static BOOL breadytoread[MAX_PORT_NUM] = {0};
static BOOL breadytowrite[MAX_PORT_NUM] = {0};

void UART_SwitchPort(UART_PORT *APP_port, UART_PORT new_uart_port)
{	
}

//vito
extern module_type vp_GetOwnerID(UART_PORT port);

extern void vp_Open(UART_PORT port,module_type owner);
extern kal_uint16	vp_UART_PutBytes(	UART_PORT	port, 
								kal_uint8	*Buffaddr, 
								kal_uint16	Length,
								module_type  owner);
extern kal_uint16 vp_GetBytes(	UART_PORT	port, 
								kal_uint8	*Buffaddr, 
								kal_uint16	Length, 
								kal_uint8	*EscDect,
								module_type  owner);

kal_bool isVirtualUartUsed[MAX_PORT_NUM] = {KAL_FALSE};
//vito


module_type UART_GetOwnerID(UART_PORT port)
{
	//vito
	if(isVirtualUartUsed[port])
	{
		return vp_GetOwnerID(port);
	}
	//vito
	return UARTPort[port].ownerid;
}

/* for ISR*/
extern void                OSC_Register_ISR ( 
                                       osc_enum_isr_src  src_idx, 
                                       osc_type_func_ptr isr_func );

UART_PORT g_port;
msg_type g_msgid;

void UART_sendilm(UART_PORT port, msg_type msgid)
{   
   if (UARTPort[port].ownerid != UARTPort[port].UART_id)
   {  
	  g_port = port;
	  g_msgid = msgid;
	 
	  OSC_Activate_ISR(OSC_ISR_SRC_UART);
   }
}

static void UART_HISR(void)
{
	ilm_struct *UART_ilm;
	uart_ready_to_write_ind_struct* _data;

	if(g_msgid == MSG_ID_UART_READY_TO_WRITE_IND)
	{			    
	   	_data = (uart_ready_to_write_ind_struct *) construct_local_para(sizeof(uart_ready_to_write_ind_struct),TD_UL);
		_data->port = g_port; 
	}
	else
	{
		_data = NULL;
	}

	DRV_BuildPrimitive(UART_ilm,
                         UARTPort[g_port].UART_id,
                         UARTPort[g_port].ownerid,
                         g_msgid,
                         _data);

	msg_send_ext_queue(UART_ilm);
}

static kal_hisrid uart_hisr;

static void UART_LISR(void)
{
	uart_hisr = kal_create_hisr("UART_HISR", (kal_uint8)2, (kal_uint32)512,UART_HISR,(kal_uint8)0);
    kal_activate_hisr(uart_hisr);	
}


void L1SM_SleepEnable(kal_uint8 n){}
void UART_EnableTX(){}
void EINT_SW_Debounce_Modify(){}
void UART_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid)  {}

//////////////////////////////////////////////////////////////////////////////////////////////
void  DisableIRQ( void ){}

extern void tst_UART_Open(kal_uint8 port);
extern kal_uint16	tst_UART_PutBytes(	kal_uint8	port, 
								kal_uint8	*Buffaddr, 
								kal_uint16	Length,
								module_type  owner);
extern kal_uint16 tst_UART_GetBytes(	kal_uint8	port, 
								kal_uint8	*Buffaddr, 
								kal_uint16	Length, 
								kal_uint8	*EscDect,
								module_type  owner);

kal_bool UART_Open(UART_PORT port, module_type owner)
{
	DCB dcb;
	HANDLE hCom;
	char strbuf[32], destbuf[32];
	COMSTAT	comstat;
    DWORD	errors;
	COMMTIMEOUTS timeouts;
    int baudrate = CBR_115200;
    unsigned char flowCtrl = 0;  //0:none, 1:hw , 2:sw flow control    
	char tempbuf[1024];
	char path[1024];
	char *name;	
    
	if (MOD_TST_READER == owner)
	{
		tst_UART_Open((kal_uint8)port);
		return KAL_TRUE;
	}
	
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
        return 0;
	
	memset(tempbuf, 0, sizeof(tempbuf));
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%sMoDIS.ini", tempbuf);

	sprintf(strbuf, "UART%d", port+1);
	GetPrivateProfileString(strbuf, "COM_PORT", "COM1", destbuf, sizeof(destbuf), path);
	flowCtrl = GetPrivateProfileInt(strbuf, "flowcontrol", 0, path);
	baudrate = GetPrivateProfileInt(strbuf, "baud_rate", 115200, path);
	//vito

	if(strcmp(destbuf,"UT")==0)
	{
		isVirtualUartUsed[port] = KAL_TRUE;
		vp_Open(port,owner);
		return KAL_TRUE;
	}
	//vito
	hCom = CreateFile( destbuf,
                    GENERIC_READ | GENERIC_WRITE,
                    0,    // must be opened with exclusive-access
                    NULL, // no security attributes
                    OPEN_EXISTING, // must use OPEN_EXISTING
                    0,    // not overlapped I/O
                    NULL  // hTemplate must be NULL for comm devices
                    );

	if (hCom == INVALID_HANDLE_VALUE)// create fail
		return KAL_FALSE;
	
	//Turn off fAbortOnError first!	
	ClearCommError(hCom, &errors, &comstat);
    if(!GetCommState(hCom, &dcb))
	{
		CloseHandle(hCom);
		hCom = NULL;
		return KAL_FALSE;
	}
	
	dcb.DCBlength = sizeof(DCB);
    dcb.Parity = NOPARITY;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    dcb.BaudRate = baudrate;		///check!
    dcb.fBinary = TRUE;
    dcb.fParity = FALSE;

	if(flowCtrl == 1)  //hardware flow control
		dcb.fOutxCtsFlow = TRUE;
	else
		dcb.fOutxCtsFlow = FALSE;

    dcb.fOutxDsrFlow = FALSE;
    dcb.fDtrControl = DTR_CONTROL_DISABLE;
    dcb.fDsrSensitivity = FALSE;
    dcb.fTXContinueOnXoff = FALSE;
	dcb.fErrorChar = FALSE;
    dcb.fNull = FALSE;
	dcb.fAbortOnError = FALSE;

	if(flowCtrl == 2)  //software flow control
	{
		dcb.fOutX = TRUE;
		dcb.fInX = TRUE;
		dcb.XonChar = 0x11;
		dcb.XoffChar = 0x13;
	}
	else
	{
		dcb.fOutX = FALSE;
		dcb.fInX = FALSE;
		dcb.XonChar = 0;
		dcb.XoffChar = 0;
	}   
	
	if(flowCtrl == 2 || flowCtrl == 0) //sw or none flow control
		dcb.fRtsControl = RTS_CONTROL_ENABLE;
	else if(flowCtrl == 1)   //hw flow control
		dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;

    dcb.ErrorChar = 0;
    dcb.EofChar = 0;
    dcb.EvtChar = 0;				

	if(!SetCommState(hCom, &dcb))
    {
        CloseHandle(hCom);		
		return KAL_FALSE;
    }	

	if(SetupComm(hCom, 8192, 8192)==FALSE )
	{
		CloseHandle(hCom);		
		return KAL_FALSE;
	}

	PurgeComm(hCom, PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);	   
				
    timeouts.ReadIntervalTimeout = 0xFFFFFFFF;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.ReadTotalTimeoutConstant = 0;
    timeouts.WriteTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutConstant = 1000;
    if(SetCommTimeouts(hCom, &timeouts) == FALSE ) 
	{
		CloseHandle(hCom);		
		return KAL_FALSE;
	}		


	UARTPort[port].ownerid = owner;
	UARTHandle[port]  = hCom;
	breadytoread[port] = TRUE;
	
	//register ISR only once
	if(g_b_ISR_flag==KAL_FALSE)
	{
		OSC_Register_ISR(OSC_ISR_SRC_UART,  (osc_type_func_ptr) UART_LISR);
		g_b_ISR_flag = TRUE;
	}

	return KAL_TRUE;	
}

kal_uint16 UART_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    ///
    int wbytes;
    
    if (MOD_TST_READER == ownerid)
	{
		return tst_UART_PutBytes((kal_uint8)port, Buffaddr, Length, ownerid);
		//return 0;
	}
	//vito
	
	if(isVirtualUartUsed[port])
	{
		return vp_PutBytes(port,Buffaddr,Length,ownerid);
	}
	//vito
	
    if(ownerid != UARTPort[port].ownerid)
        return 0;
    
    if(!WriteFile(UARTHandle[port], Buffaddr, Length, &wbytes, NULL))
        return 0;
    
    if(wbytes < Length)
        breadytowrite[port] = TRUE;
    else
        breadytowrite[port] = FALSE;
        
    return wbytes;
}

kal_uint16 UART_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
	int real_read = 0;
	int i=0;
	
	if (MOD_TST_READER == ownerid)
	{
		return tst_UART_GetBytes((kal_uint8)port, Buffaddr, Length, status, ownerid );		
		//return 0;
	}
	//vito
	if(isVirtualUartUsed[port])
	{
		return vp_GetBytes(port,Buffaddr,Length,status,ownerid);
	}
	//vito

    if(ownerid != UARTPort[port].ownerid)
        return 0;
        
	if(status)	*status = 0;
	
	if(!ReadFile(UARTHandle[port],
			(LPVOID) Buffaddr,
			(DWORD)  Length,
			(LPDWORD)&real_read,
			NULL))
			return 0;						

    /*
	printf("\r\nUART:\r\n");
	for(i=0;i<real_read;i++)
		printf("%c", Buffaddr[i]);
	printf("\r\nUART:\r\n\r\n");
	*/

    if(real_read < Length)
        breadytoread[port] = TRUE;
    else
        breadytoread[port] = FALSE;
    			
	return real_read;
}


#define DRV_BuildPrimitive(_ilm,_srcid,_dstid,_msgid,_data) \
{\
   _ilm = allocate_ilm(_srcid);\
   _ilm->src_mod_id = _srcid;\
   _ilm->sap_id = DRIVER_PS_SAP;\
   _ilm->dest_mod_id = _dstid;\
   _ilm->msg_id = _msgid;\
   _ilm->local_para_ptr = (local_para_struct *)_data;\
   _ilm->peer_buff_ptr = NULL;\
}

#define DRV_SendPrimitive(_ilm,_srcid,_dstid,_msgid,_data, _sap_id) \
{\
   _ilm = allocate_ilm(_srcid);\
   _ilm->src_mod_id = _srcid;\
   _ilm->sap_id = _sap_id;\
   _ilm->dest_mod_id = _dstid;\
   _ilm->msg_id = _msgid;\
   _ilm->local_para_ptr = (local_para_struct *)_data;\
   _ilm->peer_buff_ptr = NULL;\
}


void CheckReadyToRead(UART_PORT port)
{
    COMSTAT	comstat;
    DWORD	errors;
    if(ClearCommError(UARTHandle[port], &errors, &comstat))
    {
        if(comstat.cbInQue)        
        {
            UART_sendilm(port, MSG_ID_UART_READY_TO_READ_IND);
            breadytoread[port] = FALSE;
        }
    }        
}

void CheckReadyToWrite(UART_PORT port)
{
    COMSTAT	comstat;
    DWORD	errors;
    if(ClearCommError(UARTHandle[port], &errors, &comstat))
    {
        if(comstat.fCtsHold==0 && comstat.fXoffHold==0 && comstat.fXoffSent==0)
        {            
			UART_sendilm(port, MSG_ID_UART_READY_TO_WRITE_IND);
            breadytowrite[port] = FALSE;
        }
    }            
}

void QueryUARTStatus()
{
    int i=0;
    //ready to read    
    for(i=0;i<MAX_PORT_NUM;i++)
    {
        if(breadytoread[i])
            CheckReadyToRead(i);
        if(breadytowrite[i])
            CheckReadyToWrite(i);
    }    
}

void UART_Close(UART_PORT port, module_type ownerid)
{
    CloseHandle(UARTHandle[port]);
}

void UART_Purge(UART_PORT port, UART_buffer dir, module_type ownerid)
{
}

///////////////////////////////////////////////////////////

int w32uart_available(UART_PORT port)
{
	
    DWORD dummy;
	if(!ClearCommError(UARTHandle[port], &dummy, &comstat[port]))
	{
		return 0;
	}
    return comstat[port].cbInQue;
}


void UART_ClrTxBuffer(UART_PORT port, module_type ownerid){}
void UART_ClrRxBuffer(UART_PORT port, module_type ownerid){}
kal_uint8 send_Rxilm[MAX_UART_PORT_NUM];
void UART_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid) {}
void UART_SetAutoBaud_Div(UART_PORT port, module_type ownerid) {}
void UART_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid) {}
void UART_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid){}
kal_uint16 UART_GetTxRoomLeft(UART_PORT port) {return 0; }
void UART_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid) {}
void UART_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid) {}
kal_uint8 lcd_sleeping_state=KAL_FALSE;
void ALERTER_PWROPEN(kal_bool ENABLE) {}
kal_uint16 UART_GetBytesAvail(UART_PORT port) { return 0; }


void PutUARTByte(UART_PORT port, kal_uint8 data)
{
}

void PutUARTData(UART_PORT port, kal_uint8 escape_char, kal_uint8 data)
{           
}

void PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len)
{
   kal_uint16 index;
   for(index=0;index<len;index++)
      PutUARTByte(port,*(data+index));
}

void PutUARTDatas(UART_PORT port, kal_uint8 escape_char, kal_uint8 *data,kal_uint16 len)
{
}

kal_uint16 UART_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid )
{
	return 0;
}

void PutUARTRingBufferData(UART_PORT port)
{
    
}

kal_uint8 GetUARTByte(UART_PORT port)
{
    return 0;
}

void UART_ReadDCBConfig (UART_PORT port, UARTDCBStruct *DCB)
{
}

void UART_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{
}

void UART_SetOwner (UART_PORT port, kal_uint8 owner)
{
}

kal_uint32 SaveAndSetIRQMask(void) {return 0;}
void RestoreIRQMask(kal_uint32 a) {}
void UART_TurnOnPower(UART_PORT port, kal_bool enable) {}
kal_bool UART_CheckTxBufferEmpty(UART_PORT port) {return KAL_TRUE;}
kal_bool UART_CheckTxAllSentOut(UART_PORT port) {return KAL_TRUE;}

void get_comm_port_str(UART_PORT port, char *dest)
{
	char strbuf[32], destbuf[32];
	char tempbuf[1024];
	char path[1024];
	char *name;
    
	if (dest == NULL)
		return;
	
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
        return 0;
	
	memset(tempbuf, 0, sizeof(tempbuf));
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%sMoDIS.ini", tempbuf);

	sprintf(strbuf, "UART%d", port+1);
	GetPrivateProfileString(strbuf, "COM_PORT", "COM1", destbuf, sizeof(destbuf), path);
	
	sprintf(dest, "%s", destbuf);
}
