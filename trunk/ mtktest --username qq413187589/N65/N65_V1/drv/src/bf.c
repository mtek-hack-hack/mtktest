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
 *    bf.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the ring-buffer API
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "BMd.h"


/*
* FUNCTION                                                            
*	Buff_init
*
* DESCRIPTION                                                           
*   	This function is to let a memory area become a ring-buffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	Buffaddr: the start addr of memory area
*	uTotalSize: the size of the memory area
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void Buff_init(BUFFER_INFO *Buf,kal_uint8 *Buffaddr, kal_uint16 uTotalSize)
{	
	Buf->Read = 0;
	Buf->Write = 0;
	Buf->Length = uTotalSize;
	Buf->CharBuffer = Buffaddr;
}

/*
* FUNCTION                                                            
*	Buff_Push
*
* DESCRIPTION                                                           
*   	This function is to put a data to ring-buffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	*pushData: the data will be put into ring-buffer
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void Buff_Push(BUFFER_INFO *Buf,kal_uint8 *pushData)
{
	*BuffWrite(Buf) = *pushData;	
	BWrite(Buf)++;
	if (BWrite(Buf) >= BLength(Buf))
	{
		BWrite(Buf) -= BLength(Buf);
	}
}

/*
* FUNCTION                                                            
*	Buff_Pop
*
* DESCRIPTION                                                           
*   	This function is to pop a data from ring-buffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	*popData: the data will be pop from ring-buffer
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void Buff_Pop(BUFFER_INFO *Buf,kal_uint8 *popData)
{
	*popData= *BuffRead(Buf);
	BRead(Buf)++;
	if (BRead(Buf) >= BLength(Buf))
	{
		BRead(Buf) -= BLength(Buf);
	}

}

void Buff_look(BUFFER_INFO *Buf,kal_uint8 *popData,kal_uint8 num)
{
   kal_uint8 index;
   kal_uint16 tmp;
   
   tmp = BRead(Buf);
   for(index=0;index<num;index++)
   {
	   *popData= *(Buf->CharBuffer+tmp);
	   
	   tmp++;
	   if (tmp >= BLength(Buf))
	   {
		   tmp -= BLength(Buf);
	   }
	}
}
/*
* FUNCTION                                                            
*	Buff_IsEmpty
*
* DESCRIPTION                                                           
*   	This function is check whether ring-buffer is empty
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 Buff_IsEmpty(BUFFER_INFO *Buf)
{
	kal_uint8 status;
	if ( BRead(Buf) == BWrite(Buf) ) 
	{
		status = Buff_isEmpty;
	}
	else
	{
		status = Buff_notEmpty;
	}
	return status;
}

/*
* FUNCTION                                                            
*	Buff_IsFull
*
* DESCRIPTION                                                           
*   	This function is check whether ring-buffer is full
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 Buff_IsFull (BUFFER_INFO *Buf)
{
	kal_uint8 status;
	kal_uint16 tmp = BRead(Buf);
	if (tmp == 0)
		tmp = BLength(Buf);

	if ( (tmp-BWrite(Buf)) == 1)
	{
		status = Buff_isFull;
	}
	else
	{
		status = Buff_notFull;
	}
	return status;
}

/*
* FUNCTION                                                            
*	Buff_GetRoomLeft
*
* DESCRIPTION                                                           
*   	This function is obtain the size of the residual space 
*	in ring-buffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	
* RETURNS
*	the size of the residual space 
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint16 Buff_GetRoomLeft (BUFFER_INFO *Buf)
{
	kal_uint16	RoomLeft = 0;
	if ( BRead(Buf) <= BWrite(Buf) ) 
	{
                RoomLeft = BLength(Buf) - BWrite(Buf) + BRead(Buf) - 1;
	}
	else
	{
		RoomLeft = BRead(Buf) - BWrite(Buf) - 1;
	}

	return RoomLeft;
}

/*
* FUNCTION                                                            
*	Buff_GetBytesAvail
*
* DESCRIPTION                                                           
*   	This function is obtain the size of the used space 
*	in ring-buffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	
* RETURNS
*	the size of the used space
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint16 Buff_GetBytesAvail (BUFFER_INFO *Buf)
{
	kal_uint16	BytesAvail = 0;
	if (BWrite(Buf) >= BRead(Buf))
		BytesAvail = BWrite(Buf) - BRead(Buf);
	else 
		BytesAvail = BLength(Buf) - BRead(Buf) + BWrite(Buf);	

	return BytesAvail;
}

/*
* FUNCTION                                                            
*	Buff_GetLength
*
* DESCRIPTION                                                           
*   	This function is to obtain the total size of the ring-buffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	
* RETURNS
*	the total size of the ring-buffer
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint16 Buff_GetLength(BUFFER_INFO *Buf)
{
	return Buf->Length;
}

/*
* FUNCTION                                                            
*	Buff_Flush
*
* DESCRIPTION                                                           
*   	This function is to reset the ring-buffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void Buff_Flush (BUFFER_INFO *Buf)
{
	Buf->Write = Buf->Read = 0;
}

/*
* FUNCTION                                                            
*	Get32FromBuff
*
* DESCRIPTION                                                           
*   	This function is to obtain a 32bit data from ringbuffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	*DATA: the data will be obtain from ringbuffer
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void Get32FromBuff(BUFFER_INFO *Buf,kal_uint32 *DATA)
{
	kal_uint8	tmp,index;
	kal_uint32 	tmp32;
	*DATA =0;
	for (index =0;index < 4;index++)
	{
		Buff_Pop(Buf,&tmp);
		tmp32 = (kal_uint32)tmp;
		//(*DATA) |= (tmp32 << (24-8*index));
		(*DATA) |= (tmp32 << (8*index));
	}
}

/*
* FUNCTION                                                            
*	Put32toBuff
*
* DESCRIPTION                                                           
*   	This function is to put a 32bit data to ringbuffer
*
* CALLS  
*
* PARAMETERS
*	*Buf: struct of BUFFER_INFO
*	*DATA: the data will be put into ringbuffer
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void Put32toBuff(BUFFER_INFO *Buf,kal_uint32 *DATA)
{
	kal_uint8	tmp,index;
	kal_uint32 	tmp32;
	for (index =0;index < 4;index++)
	{
		//tmp32 = ((*DATA) >> (24-8*index));
		tmp32 = ((*DATA) >> (8*index));
		tmp = (kal_uint8)tmp32;		
		Buff_Push(Buf,&tmp);
	}		
}

/*
* FUNCTION                                                            
*	MemCPY
*
* DESCRIPTION                                                           
*   	This function is to copy memory block
*
* CALLS  
*
* PARAMETERS
*	dst: destination address.
*	src: source address.
*	len: copy length
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void MemCPY(kal_uint8 *dst,kal_uint8 *src,kal_uint32 len)
{
	kal_uint32 index;
	for (index = 0; index < len; index++) 
		*dst++ = *src++;
}

/*
* FUNCTION                                                            
*	MemSET
*
* DESCRIPTION                                                           
*   	This function is to set a value to a memory blcok
*
* CALLS  
*
* PARAMETERS
*	dst: destination address.
*	len: copy length
*	data: the value
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void MemSET(kal_uint8 *dst,kal_uint8 data,kal_uint32 len)
{
	kal_uint32 index;
	for (index = 0; index < len; index++) 
		*dst++ = data;
}

