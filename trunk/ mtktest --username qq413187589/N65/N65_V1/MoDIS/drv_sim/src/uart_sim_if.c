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
 *   uart_sim_if.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *	UART driver interface.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "uart_sim_inc.h"
void vp_setPort(kal_uint16 index,UART_PORT port)
{
	if(index <MAX_VIRTUAL_PORT_SUPPORT)
	{
	    vport[index].port= port;
	}
}

vp_contextT *vp_getPort(UART_PORT port)
{
    kal_uint32 p;

    for(p=0; p<MAX_VIRTUAL_PORT_SUPPORT;p++)
    {
        if(vport[p].port == port) return & vport[p];
    }
    ASSERT(0);
	return NULL;
}
void send_data_available(vp_contextT *vp)
{
    ilm_struct *ilm;
   uart_ready_to_read_ind_struct* localPtr=( uart_ready_to_read_ind_struct*)
                                            construct_local_para(sizeof(uart_ready_to_read_ind_struct),0);    
    localPtr->port = vp->port;

    ilm=allocate_ilm(MOD_VUART);
    ilm->peer_buff_ptr = NULL;
    ilm->local_para_ptr =(local_para_struct*) localPtr;
    ilm->msg_id = MSG_ID_UART_READY_TO_READ_IND;
    ilm->sap_id = 0;
    ilm->src_mod_id = MOD_VUART ;
    ilm->dest_mod_id =vp->owner;
    msg_send_ext_queue(ilm);

}

void vuart_handleDataInd(local_para_struct *localPtr,peer_buff_struct *peerptr)
{
    vp_contextT *vp;
    uart_data_ind_struct *getBytes=(uart_data_ind_struct *)localPtr;
    vp=vp_getPort(getBytes->port);
    if(vp != NULL)
    {
        kal_uint32 i;
        i = vp->currentDataPos;
        while(1)
        {
            if(vp->rxDataArray[i] == NULL)
            {
                vp->rxDataArray[i] = peerptr;
                //notify data available
                if(getBytes->sendReadyToRead)
                {
                    send_data_available(vp);
                }
                return;
            }
           WRAP_INC(i);
           if(i == vp->currentDataPos)
           {
            return;
           }
        }
    }
}

void vuart_handleSetConfigInd(local_para_struct *localPtr)
{
    vp_contextT *vp;
    uart_set_config_ind_struct *config=(uart_set_config_ind_struct *)localPtr;
    vp=vp_getPort(config->port);
    vp->is_WriteSuspend = config->is_WriteSuspend;
    vp->owner = config->owner;
    vp->maxWriteLength = config->maxWriteLength;
}
 /*******************************************************************************
 
/*****************************************************************************
* FUNCTION
*    cmux_notifyBufferAvailable
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*    vp_Open
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
 kal_bool vp_Open(UART_PORT port, module_type owner)
{
// send notify to VP task
return KAL_TRUE;            
}





/*****************************************************************************
* FUNCTION
*    vp_Close
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_Close(UART_PORT port)
{

    // send notify to VP task
}





/*****************************************************************************
* FUNCTION
*    vp_GetBytes
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

kal_uint16 vp_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
    // get data from "injected" peer buffer
    vp_contextT *vp= vp_getPort(port);
    kal_uint8     *dataPtr;
    kal_uint16    dataLength;
    kal_uint8    *dstPtr= Buffaddr;
    kal_uint16   lenToRead = Length;
        
    while(vp->rxDataArray[vp->currentDataPos]
        && 0 < lenToRead)
    {
         dataPtr=get_pdu_ptr(vp->rxDataArray[vp->currentDataPos], & dataLength);

         if( dataLength > lenToRead)
         {
            kal_mem_cpy(dstPtr,dataPtr,lenToRead);
            lenToRead = 0;
            vp->rxDataArray[vp->currentDataPos]->free_header_space += lenToRead;
            vp->rxDataArray[vp->currentDataPos]->pdu_len -= lenToRead;
         }
         else
         {
            kal_mem_cpy(dstPtr,dataPtr,dataLength);
            lenToRead -= dataLength;
            dstPtr += dataLength;
            free_peer_buff(vp->rxDataArray[vp->currentDataPos]);
            vp->rxDataArray[vp->currentDataPos]=NULL;

            WRAP_INC(vp->currentDataPos);
         }
    }

	return (kal_uint16)(Length - lenToRead);
}





/*****************************************************************************
* FUNCTION
*    vp_PutBytes
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
kal_uint16 vp_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    // send out ilm to check
    ilm_struct *ilm;
    kal_uint16 noUse;
    peer_buff_struct *peer;
    uart_putbytes_req_struct *localPtr;
    vp_contextT *portPtr;

    kal_uint16     writtenLength;
    
    portPtr= vp_getPort(port);

    if(portPtr->is_WriteSuspend)
    {
        return 0;
    }
    
    if(portPtr->maxWriteLength < Length)
    {
        writtenLength = portPtr->maxWriteLength;
    }
    else
    {
        writtenLength = Length;
    }

    localPtr=(uart_putbytes_req_struct *)
                                            construct_local_para(sizeof(uart_putbytes_req_struct),0);    
    localPtr->port = port;
    localPtr->owner = ownerid;

    peer = construct_peer_buff(writtenLength,0,0, 0);
    kal_mem_cpy(get_pdu_ptr(peer,&noUse), Buffaddr, writtenLength);

    ilm=allocate_ilm(ownerid);
    ilm->peer_buff_ptr = peer;
    ilm->local_para_ptr =(local_para_struct*) localPtr;
    ilm->msg_id = MSG_ID_UART_PUTBYTES_REQ;
    ilm->sap_id = 0;
    ilm->src_mod_id = ownerid;
    ilm->dest_mod_id =MOD_VUART ;
    msg_send_ext_queue(ilm);
    return writtenLength;
}
    





/*****************************************************************************
* FUNCTION
*    vp_GetBytesAvail
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

kal_uint16 vp_GetBytesAvail(UART_PORT port)
{
    // calculate bytes available
return 0;
}





/*****************************************************************************
* FUNCTION
*    vp_GetTxRoomLeft
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

kal_uint16 vp_GetTxRoomLeft(UART_PORT port)
{
    // always return a maximum value
return 0;
}



/*****************************************************************************
* FUNCTION
*    vp_SetOwner
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_SetOwner (UART_PORT port, kal_uint8 owner)
{
    // send notify to VP
}





/*****************************************************************************
* FUNCTION
*    vp_SetFlowCtrl
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_SetFlowCtrl(UART_PORT port, kal_bool XON)
{
// send notify to VP
}







/*****************************************************************************
* FUNCTION
*    vp_CtrlDCD
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_CtrlDCD(UART_PORT port, IO_level SDCD)
{
    // send notify to VP
}





/*****************************************************************************
* FUNCTION
*    vp_CtrlBreak
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_CtrlBreak(UART_PORT port, IO_level SBREAK)
{
    // send notify to VP
}








/*****************************************************************************
* FUNCTION
*    vp_GetOwnerID
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/


module_type vp_GetOwnerID(UART_PORT port)
{
    // read data from context
    vp_contextT *portPtr;
    
    portPtr= vp_getPort(port);
	return portPtr->owner;

}



/*****************************************************************************
* FUNCTION
*    vp_SetBaudRate
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

// the following function is not supported
void vp_SetBaudRate(UART_PORT port, UART_baudrate baudrate)
{
// send notify to VP
}



/*****************************************************************************
* FUNCTION
*    UART_SetDCBConfig
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config)
{
// send notify to VP
}



/*****************************************************************************
* FUNCTION
*    vp_SetAutoBaud_Div
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_SetAutoBaud_Div(UART_PORT port)
{
// send notify to VP
}


/*****************************************************************************
* FUNCTION
*    vp_ClrRxBuffer
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_ClrRxBuffer(UART_PORT port)
{
// clear and release all buffer
}



/*****************************************************************************
* FUNCTION
*    vp_ClrTxBuffer
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_ClrTxBuffer(UART_PORT port)
{

// do nothing.
}




/*****************************************************************************
* FUNCTION
*    vp_ConfigEscape
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void vp_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime)
{
//send notify to VP
}



/*****************************************************************************
* FUNCTION
*    vp_GetFlowCtrl
* DESCRIPTION
*   
*
* PARAMETERS
*  void
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

UART_flowCtrlMode vp_GetFlowCtrl(UART_PORT port)
{
    // send notify to VP
return fc_none;
}

