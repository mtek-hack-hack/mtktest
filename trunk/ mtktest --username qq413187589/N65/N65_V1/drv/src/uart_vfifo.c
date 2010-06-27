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
 *    uart_vfifo.c      
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functions for virtual FIFO
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include    "kal_release.h"
#include    "stack_common.h"
#include    "stack_msgs.h"
#include    "app_ltlcom.h"       /* Task message communiction */
#include    "stack_buff_pool.h"
#include    "app_buff_alloc.h"
#include    "drv_comm.h"
#include    "reg_base.h"
#include    "uart_hw.h"
#include    "bmd.h"
#include    "intrCtrl.h"
#include    "drvpdn.h"
#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include    "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "uart_sw.h"
#include    "dma_hw.h"
#include    "dma_sw.h"
#include    "gpt_sw.h"
#include    "init.h"
#ifdef __ROMSA_SUPPORT__
#ifndef __ROMSA_EXPORT_UART_H__
#include "romsa_export_uart.h"
#endif
#include    "gpt_hw.h"
#endif

#ifdef __DMA_UART_VIRTUAL_FIFO__

/*variable*/
extern const kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM];
extern UARTStruct UARTPort[MAX_UART_PORT_NUM];
extern const UART_rings_struct *UART_rings;
extern kal_uint8 uart_escape_state;
extern kal_uint8 send_Rxilm[MAX_UART_PORT_NUM];
extern kal_uint8 send_Txilm[MAX_UART_PORT_NUM];
/*function*/ 
extern void UART_sendilm(UART_PORT port, msg_type msgid);
extern void UART_Calback(void *parameter);
/*UART API*/
kal_uint16 U_GetTxISRRoomLeft_VFIFO(UART_PORT port)
{ 
   kal_uint16 real_count; 
	real_count=DMA_GetVFIFO_Roomleft(UARTPort[port].Tx_DMA_Ch);

   /*temp solution: to cover L1 trace bug*/
   if(real_count<=16)
   	real_count=0;
   else
     real_count-=16;
     
   return real_count;
}
kal_uint16 U_GetTxRoomLeft_VFIFO(UART_PORT port)
{
   kal_uint16 real_count;
   kal_uint32  savedMask;
   savedMask = SaveAndSetIRQMask();
	real_count=DMA_GetVFIFO_Roomleft(UARTPort[port].Tx_DMA_Ch);
	RestoreIRQMask(savedMask);
 
   return real_count;
}
kal_uint16 U_GetBytesAvail_VFIFO(UART_PORT port)
{	
   kal_uint16 real_count;
   real_count=DMA_GetVFIFO_Avail(UARTPort[port].Rx_DMA_Ch);
   return real_count;
}
kal_uint8 U_GetUARTByte_VFIFO(UART_PORT port)
{

  kal_uint8 data;
  kal_uint8 ch = UARTPort[port].Rx_DMA_Ch;
  kal_uint16  real_count=0;
  while(1)
  {
     real_count=DMA_GetVFIFO_Avail(ch);
     if (real_count!=0)
     {
        data = DMA_POP(ch);
        if( uart_support_autoescape()==KAL_TRUE)              
        {
           return data;
        }  
        //#else
        else
        {
           if(UARTPort[port].DCB.flowControl==fc_sw)
           {     
              if(uart_escape_state==0)
              {
                 if(data==0x77)            
                    uart_escape_state=0x77;
                 else            
                    return data;
              }
              else if (uart_escape_state==0x77)
              {
                 uart_escape_state=0x0; 
                 switch(data)
                 {
                    case 0x01:
                       return UARTPort[port].DCB.xonChar;
                       break;
                    case 0x02:
                       return UARTPort[port].DCB.xoffChar;
                       break;               
                    case 0x03:
                       return 0x77;                  
                       break;      
                    default:                     
                       break;      
                 }                                            
              }                           
           }
           else
              return data;            
         }       
     }
  }        
}
void U_PutUARTByte_VFIFO(UART_PORT port, kal_uint8 data)
{
  kal_uint16 ffsta;
  kal_uint8 ch = UARTPort[port].Tx_DMA_Ch;

  while(1)
  {
    ffsta = DRV_Reg(DMA_FFSTA(ch));
    if (!(ffsta & DMA_FFSTA_FULL)) // fifo not full
    {
      DMA_PUSH(ch,data);
      break;
    }
  }
}
void PutUARTData_VFIFO(UART_PORT port, kal_uint8 escape_char, kal_uint8 data)
{
          
   if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
       (uart_support_autoescape()==KAL_FALSE))     
   {
		if (data == UARTPort[port].DCB.xonChar)
   	{
         PutUARTByte(port, escape_char);
         PutUARTByte(port, 0x01);            
   	}
   	else if (data == UARTPort[port].DCB.xoffChar)
   	{
   		PutUARTByte(port, escape_char);
         PutUARTByte(port, 0x02);            
   	}
   	else if (data == escape_char)
   	{
         PutUARTByte(port, escape_char);
         PutUARTByte(port, 0x03);            
   	}
   	else
   	{
   		PutUARTByte(port, data);
   	}         
   }
   else
   {
   	PutUARTByte(port, data);
   }        
}
kal_uint16 U_GetBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
   kal_uint16  real_count,index;
   kal_uint8 ch = UARTPort[port].Rx_DMA_Ch;
   kal_uint16   data_count=0;
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);

   if (status != NULL)
      *status = 0;

   // get available bytes in rx ring buffer
	real_count = DMA_GetVFIFO_Avail(ch);
   
   if (status != NULL)
   {
      if (UARTPort[port].EscFound)
      {
         *status |= UART_STAT_EscDet;
         UARTPort[port].EscFound = KAL_FALSE;
      }
      if (UARTPort[port].breakDet)
      {
         *status |= UART_STAT_Break;
         UARTPort[port].breakDet = KAL_FALSE;
      }
   }
   do
   {      
      real_count = DMA_GetVFIFO_Avail(ch);      
      if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
          (uart_support_autoescape()==KAL_FALSE&& UARTPort[port].DCB.flowControl==fc_sw ))
      {  
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {                
            *(Buffaddr+data_count) = DMA_POP(ch); 
            /*The following are for software flow control*/
            if(uart_escape_state==0)
            {
               if(*(Buffaddr+data_count)==0x77)
               {
                  uart_escape_state=0x77;               
               }   
               else   
               {
                  data_count++;
               }   
            }  
            else if (uart_escape_state==0x77)
            {
               switch(*(Buffaddr+data_count))
               {
                  case 0x01:
                     *(Buffaddr+data_count)=UARTPort[port].DCB.xonChar;
                     data_count++;
                     break;
                  case 0x02:                  
                     *(Buffaddr+data_count)=UARTPort[port].DCB.xoffChar; 
                     data_count++;                 
                     break;               
                  case 0x03:                  
                     *(Buffaddr+data_count)=0x77;
                     data_count++;
                     break;      
                  default:                  
                     break;      
               }                         
               uart_escape_state=0x0;        
            }                          
         }   
      }
      else/*HW flow control*/
      {
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {            
            *(Buffaddr+data_count) = DMA_POP(ch); 
            data_count++;
         }   
      }         
      /*satisfy uart owner request, so break*/
      if (data_count == Length) break;            
      /* disable interrupt*/      
      DMA_DisableINT(ch);      
      real_count = DMA_GetVFIFO_Avail(ch);
       /*there is no data in ringbuffer, so break*/       
      if (real_count==0)
      {
        send_Rxilm[port] = KAL_TRUE;          
        DMA_EnableINT(ch);
        /* enable interrupt*/
        break;
      }      
      DMA_EnableINT(ch);
      /* enable interrupt*/
   }while(KAL_TRUE);      
     
   DMA_EnableINT(ch);
   return data_count;	   
}


kal_uint16 U_PutBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
	kal_uint8 ch = UARTPort[port].Tx_DMA_Ch;
#ifndef DRV_DEBUG
   kal_uint16  real_count,index;
   kal_uint32  savedMask;
    
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid,  (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
	   switch(port)
	   {
	      case uart_port1:
	         DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
	         break;
	      case uart_port2:
	         DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
	         break;
	#ifdef __UART3_SUPPORT__
	      case uart_port3:
	         #if !defined(DRV_UART_NO_UART3_PDN)
	         DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);
	         #endif
	         break;
	#endif   /*__UART3_SUPPORT__*/
	      default:
	         ASSERT(0);
	         break;
	   }
   }
   real_count = DMA_GetVFIFO_Roomleft(ch);
#ifdef VFIFO_DBG
{
	kal_char s[50];
	sprintf(s,"uart_putbytes,len %d,left %d",Length,real_count);
	kal_print(s);
}
#endif

   if (real_count >= Length)
   {
      real_count = Length;
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
      DMA_EnableINT(ch);
   }
   if(ownerid==MOD_TST_READER)
   {
      for (index = 0; index < real_count; index++)
      {
      	savedMask = SaveAndSetIRQMask();   
      	if(!IS_VFIFO_FULL(ch))
      	{
      		DMA_PUSH(ch,*(Buffaddr+index));
      	}	
      	else
      	{
      	   real_count=index;
      	   send_Txilm[port] = KAL_TRUE;
      	   DMA_EnableINT(ch);      	   
      	   RestoreIRQMask(savedMask);	
      	   break;
      	 }   
          RestoreIRQMask(savedMask);	
      }
   }   
   else/*not TST */
   {
      for (index = 0; index < real_count; index++)
      {
      	DMA_PUSH(ch,*(Buffaddr+index));
      }      
   }      
   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}
kal_uint16 U_PutISRBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
	kal_uint8 ch = UARTPort[port].Tx_DMA_Ch;
#ifndef DRV_DEBUG
   kal_uint16  real_count,index;
    
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
	   switch(port)
	   {
	      case uart_port1:
	         DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
	         break;
	      case uart_port2:
	         DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
	         break;
	#ifdef __UART3_SUPPORT__
	      case uart_port3:
	         #if ( (defined(MT6219))||defined(MT6226M)||(defined(MT6228))|| defined(MT6229) || defined(MT6230)|| (defined(MT6226))|| (defined(MT6227)) || defined(MT6225) )
	         DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);
	         #endif
	         break;
	#endif   /*__UART3_SUPPORT__*/
	      default:
	         ASSERT(0);
	         break;
	   }
   }
   real_count = DMA_GetVFIFO_Roomleft(ch);
#ifdef VFIFO_DBG
{
	kal_char s[50];
	sprintf(s,"uart_putbytes,len %d,left %d",Length,real_count);
	kal_print(s);
}
#endif

   if (real_count >= Length)
   {
      real_count = Length;
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
      DMA_EnableINT(ch);
   }
   
   for (index = 0; index < real_count; index++)
   {   	
   	DMA_PUSH(ch,*(Buffaddr+index));   		
   }
   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}
kal_uint16 U_SendData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
    kal_int16   real_count,index;
    kal_uint8   data;
    kal_uint8 ch = UARTPort[port].Tx_DMA_Ch;
    kal_uint32  savedMask;

   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid,  (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }      
   
   if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
    (uart_support_autoescape()==KAL_FALSE) )
   {
      if(mode == 0)
          real_count = UART_PutBytes(port, Buffaddr, Length, ownerid);
      else
      {
        if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
        {
           switch(port)
           {
              case uart_port1:
                 DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
                 break;
              case uart_port2:
                 DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
                 break;
        #ifdef __UART3_SUPPORT__
              case uart_port3:
                 #if !defined(DRV_UART_NO_UART3_PDN)
                 DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);
                 #endif
                 break;
        #endif   /*__UART3_SUPPORT__*/
              default:
                 ASSERT(0);
                 break;
           }
        }
        
	   real_count = DMA_GetVFIFO_Roomleft(ch);
      #ifdef VFIFO_DBG
      {
      	char s[50];
      	sprintf(s,"uart_SendData,len %d,left %d",Length,real_count);
      	kal_print(s);
      }
      #endif
      
	   if (real_count > Length)
	   {
	      real_count = Length;
	   }
	   else
	   {
	      send_Txilm[port] = KAL_TRUE;
	      DMA_EnableINT(ch);
	   }
      
         for (index = 0; index < real_count; index++)
         {
	   	   data = *(Buffaddr+index);
	   	
	   	if (data == UARTPort[port].DCB.xonChar)
	   	{   
	   	   savedMask = SaveAndSetIRQMask(); 		     					
      		if(!IS_VFIFO_FULL(ch))
	   		{
	   		     DMA_PUSH(ch,escape_char);
	   		     DMA_PUSH(ch,0x01);
	   		}    
      		else
      		{
      			RestoreIRQMask(savedMask);	
      	   	break;
      		}   
         	RestoreIRQMask(savedMask);				
	   		 
	   	}
 	   	else if (data == UARTPort[port].DCB.xoffChar)
	   	{
	   	    savedMask = SaveAndSetIRQMask(); 	
      		if(!IS_VFIFO_FULL(ch))
	   		{
	   		     DMA_PUSH(ch,escape_char);
	   		     DMA_PUSH(ch,0x02);
	   		}     
	   		else
      		{
      			RestoreIRQMask(savedMask);	
      	   	break;
      		}  
         	RestoreIRQMask(savedMask);				
      					
	   	}
        		else if (data == escape_char)
	   	{
	   	   savedMask = SaveAndSetIRQMask(); 		     					
	   		if(!IS_VFIFO_FULL(ch))
	   		{
	   		     DMA_PUSH(ch,escape_char);
	   		     DMA_PUSH(ch,0x03);
	   		}     
	   		else
      		{
      			RestoreIRQMask(savedMask);				
      	   	break;
      		}  			     
	   		      	RestoreIRQMask(savedMask);				
      
	   	}
	   	 else
	   	 {
	   	   savedMask = SaveAndSetIRQMask(); 		     							 	
	   	   if(!IS_VFIFO_FULL(ch))
	   		{
	   	   	DMA_PUSH(ch,data);
	   	   }	
	   		else
      		{
      			RestoreIRQMask(savedMask);	
      	   	break;
      		} 	
      		RestoreIRQMask(savedMask);				
      
	   	 }
	   	
         }
         real_count = index;
      
	   }   
	}
	else
	{
     real_count = UART_PutBytes(port, Buffaddr, Length, ownerid);
   }   
   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);
   return real_count;
#else
    return Length;
#endif
}
kal_uint16 U_SendISRData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
    kal_int16   real_count,index;
    kal_uint8   data;
    kal_uint8 ch = UARTPort[port].Tx_DMA_Ch;

   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }
            
       if( (stack_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw)||
       (uart_support_autoescape()==KAL_FALSE) )  
       {
          if(mode == 0)
              real_count = UART_PutISRBytes(port, Buffaddr, Length, ownerid);
          else
          {
            if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
            {
               switch(port)
               {
                  case uart_port1:
                     DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
                     break;
                  case uart_port2:
                     DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
                     break;
            #ifdef __UART3_SUPPORT__
                  case uart_port3:
                     #if !defined(DRV_UART_NO_UART3_PDN)
                     DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);
                     #endif            
                     break;
            #endif   /*__UART3_SUPPORT__*/
                  default:
                     ASSERT(0);
                     break;
               }
            }
            
   	      real_count = DMA_GetVFIFO_Roomleft(ch);
            #ifdef VFIFO_DBG
            {
            	char s[50];
            	sprintf(s,"uart_SendData,len %d,left %d",Length,real_count);
            	kal_print(s);
            }
            #endif
   
   	   if (real_count > Length)
   	   {
   	      real_count = Length;
   	   }
   	   else
   	   {
   	      send_Txilm[port] = KAL_TRUE;
   	      DMA_EnableINT(ch);
   	   }
         
         for (index = 0; index < real_count; index++)
         {
   	   	data = *(Buffaddr+index);
   	   	if (data == UARTPort[port].DCB.xonChar)
   	   	{   
   	   		DMA_PUSH(ch,escape_char);
   	   		DMA_PUSH(ch,0x01); 
   	   	}
    	   	else if (data == UARTPort[port].DCB.xoffChar)
   	   	{
   	   	   DMA_PUSH(ch,escape_char);
   	   		DMA_PUSH(ch,0x02);
         
   	   	}
            else if (data == escape_char)
   	   	{
   	   		DMA_PUSH(ch,escape_char);
   	   		DMA_PUSH(ch,0x03);
   	   	}
   	   	else
   	   	{
   	   	   DMA_PUSH(ch,data);		     	   	   
            }
         }   
      }    		    
  	}
  	else
  	{
      real_count = UART_PutISRBytes(port, Buffaddr, Length, ownerid);
   }    
   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);   
   return real_count;
#else
    return Length;
#endif
}


/************************ISR level**************************************************/
kal_uint32 last_w;
kal_uint32 last_r;
void UART_RecTimeOutHandler(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE = UART_BaseAddr[UARTData->port_no];
   kal_uint16 avail;
   kal_uint8 ch;
   volatile kal_uint8 tmp;

#ifdef VFIFO_DBG
	gUART_RecTimeOutHandler++;
#endif

   // clear the timeout interrupt
 	tmp = DRV_Reg(UART_RXDMA(UART_BASE));

   //check if no incomming data ----for future don't remove it.
   //if(!(DRV_Reg(UART_RXDMA(UART_BASE))&UART_RXDMA_TIMEOUT))
   	//return;

   // inform the upper layer to check virtual fifo remains data
   ch = UARTData->Rx_DMA_Ch;
   avail = DMA_GetVFIFO_Avail(ch);
   if(avail == 0)
   	return;
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[UARTData->port_no].rx_cb(UARTData->port_no);
   
	DMA_DisableINT(ch);

   if (UARTData->ESCDet.GuardTime != 0)   
   {
      UARTStruct *UARTData=(UARTStruct *)parameter;
      
      switch(UARTData->Rec_state)
      {
         case UART_Get3EscChar:                        
            UARTData->Rec_state = UART_RecNormal;            
            UARTData->EscCount = 0;
            
            break;
         case UART_RecNormal:
            UARTData->Rec_state = UART_RecNormal;     
            UARTData->EscCount = 0;
            
            break;      
         case UART_StartCheckESC:                                          
            if(avail>3)
            {
               UARTData->Rec_state = UART_RecNormal;            
               UARTData->EscCount = 0;
            }
            else
            {
               kal_uint16 i;
               kal_uint8 data;
               last_w=DRV_Reg32(DMA_WRPTR(ch));  
               for(i=1;i<(avail+1);i++)
               {                                     
                  last_w--;
                  if( (last_w) <(kal_uint32) UART_rings->ring[UARTData->port_no].rx_adrs )
                     last_w=(kal_uint32)UART_rings->ring[UARTData->port_no].rx_adrs+
                             UART_rings->ring[UARTData->port_no].rx_len-1;                  
                  data=DRV_Reg8((last_w));                                               
                  if(data==UARTData->ESCDet.EscChar)
                  {
                     UARTData->EscCount++;
                     if(UARTData->EscCount == 3)
                     {
                        UARTData->Rec_state = UART_Get3EscChar;
                     }                     
                     else if(UARTData->EscCount > 3)
                     {
                        UARTData->Rec_state = UART_RecNormal;
                        UARTData->EscCount = 0;
                     }                     
                  }   
                  else
                  {
                        
                     UARTData->Rec_state = UART_RecNormal; 
                     UARTData->EscCount = 0;
                  }                                                       
               }                   

            }     
            break;
            default:
            break;
      }           
      GPTI_StartItem(UARTData->handle,
                        (UARTData->ESCDet.GuardTime/10),
                        UART_Calback,
                        &UARTPort[UARTData->port_no]);                                
      
   }                  

}

// called by DMA ISR while tx fifo is under the threshold

void UART_TrxHandler_VFIFO(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_int16 room;
   kal_uint8 ch;

#ifdef VFIFO_DBG
	gUART_TrxHandler_VFIFO++;
#endif
	ch = UARTData->Tx_DMA_Ch;
   room = DMA_GetVFIFO_Roomleft(ch);
   if(room == 0)
   	return;
	/* inform the upper layer to send data to vfifo*/
	/*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[UARTData->port_no].tx_cb(UARTData->port_no);
	
   DMA_DisableINT(ch);

}

// called by DMA ISR while rx vfifo is over the threshold
void UART_RecHandler_VFIFO(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_int16 avail;
   kal_uint8 ch;

#ifdef VFIFO_DBG
	gUART_RecHandler_VFIFO++;
#endif

	ch = UARTData->Rx_DMA_Ch;
   avail = DMA_GetVFIFO_Avail(ch);
   if(avail == 0)
   	return;
	// inform the upper layer to get data from vfifo
	/*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[UARTData->port_no].rx_cb(UARTData->port_no);
   
	DMA_DisableINT(ch);
}
void UART_THRE_hdr_VFIFO(UART_PORT port)
{
   kal_uint16 avail;
   kal_uint32 UART_BASE = UART_BaseAddr[port];
   
   /*check if there is data in ring buffer*/	
   avail=DMA_GetVFIFO_Avail(UARTPort[port].Tx_DMA_Ch); 	
   if(avail==0)
   {
      switch(port)
      {
         case uart_port1:
            DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART1,PDN_UART1);
            break;
         case uart_port2:
            DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
            break;
   #ifdef __UART3_SUPPORT__
         case uart_port3:
            #if !defined(DRV_UART_NO_UART3_PDN)
            DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);
            #endif
            break;
   #endif   /*__UART3_SUPPORT__*/
         default:
            ASSERT(0);
            break;
      }      
      DisableTxIntr(UART_BASE);
   }
}   

void U_configure_DMA_VFIFO(void)
{
   #if defined(DRV_UART_DMA_VFIFO_CONFIG1)
   if(UART_rings->not_support_VFIFO==uart_port1)
   {
      UARTPort[uart_port2].Rx_DMA_Ch=11;//12;
      UARTPort[uart_port2].Tx_DMA_Ch=10;//11;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=12;//13;
      UARTPort[uart_port3].Tx_DMA_Ch=13;//14;
      #endif
      UART_VFIFO_support[uart_port1]=KAL_FALSE;
   }
   else if(UART_rings->not_support_VFIFO==uart_port2)
   {
      UARTPort[uart_port1].Rx_DMA_Ch=10;//11;
      UARTPort[uart_port1].Tx_DMA_Ch=11;//12;
      #ifdef __UART3_SUPPORT__         
      UARTPort[uart_port3].Rx_DMA_Ch=12;//13;
      UARTPort[uart_port3].Tx_DMA_Ch=13;//14; 
      #endif
      UART_VFIFO_support[uart_port2]=KAL_FALSE;
   }
   else if(UART_rings->not_support_VFIFO==uart_port3)
   {
      UARTPort[uart_port1].Rx_DMA_Ch=10;//11;
      UARTPort[uart_port1].Tx_DMA_Ch=12;//13;
      UARTPort[uart_port2].Rx_DMA_Ch=11;//12;
      UARTPort[uart_port2].Tx_DMA_Ch=13;//14;
      #ifdef __UART3_SUPPORT__       
      UART_VFIFO_support[uart_port3]=KAL_FALSE;
      #endif
   }   
   else
   {
      UART_VFIFO_support[uart_port2]=KAL_FALSE;
      UARTPort[uart_port1].Rx_DMA_Ch=10;//11;
      UARTPort[uart_port1].Tx_DMA_Ch=11;//12;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=12;//13;
      UARTPort[uart_port3].Tx_DMA_Ch=13;//14;
      #endif
   }    
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG2)
   if(UART_rings->not_support_VFIFO==uart_port1)
   {
      UARTPort[uart_port2].Rx_DMA_Ch=12;
      UARTPort[uart_port2].Tx_DMA_Ch=11;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=14;
      #endif
      UART_VFIFO_support[uart_port1]=KAL_FALSE;
   }
   else if(UART_rings->not_support_VFIFO==uart_port2)
   {
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=12;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=14;
      #endif
      UART_VFIFO_support[uart_port2]=KAL_FALSE;
   }
   else if(UART_rings->not_support_VFIFO==uart_port3)
   {
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=13;
      UARTPort[uart_port2].Rx_DMA_Ch=12;
      UARTPort[uart_port2].Tx_DMA_Ch=14;
      #ifdef __UART3_SUPPORT__
      UART_VFIFO_support[uart_port3]=KAL_FALSE;
      #endif
   }   
   else
   {
      UART_VFIFO_support[uart_port2]=KAL_FALSE;
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=12;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=14;
      #endif
   }    
   #endif        
}   

#if 1
extern kal_bool U_Open(UART_PORT port, module_type owner);
extern void U_Close(UART_PORT port, module_type ownerid);
extern void U_Purge(UART_PORT port, UART_buffer dir, module_type ownerid);
extern void U_SetOwner (UART_PORT port, kal_uint8 owner);
extern void U_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid);
extern void U_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid);
extern void U_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
extern void U_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid);
extern void U_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid);
extern void U_ClrRxBuffer(UART_PORT port, module_type ownerid);
extern void U_ClrTxBuffer(UART_PORT port, module_type ownerid);
extern void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid);
extern module_type U_GetOwnerID(UART_PORT port);
extern void U_SetAutoBaud_Div(UART_PORT port, module_type ownerid);
extern void U_Register_TX_cb(UART_PORT port, module_type owner, UART_TX_FUNC func);
extern void U_Register_RX_cb(UART_PORT port, module_type owner, UART_RX_FUNC func);
extern void U_PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len);
extern void U_ReadDCBConfig (UART_PORT port, UARTDCBStruct *DCB);
extern void U_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid);   /*NULL for DCE*/
extern void U_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid);
extern void U_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS);
// uart dispatch funtion table
UartDriver_strcut UartDriver_VFIFO=
{
        U_Open,
        U_Close,
        U_GetBytes_VFIFO,
        U_PutBytes_VFIFO,
        U_GetBytesAvail_VFIFO,
        U_GetTxRoomLeft_VFIFO,
        U_PutISRBytes_VFIFO,
        U_GetTxISRRoomLeft_VFIFO, 
        U_Purge,
        U_SetOwner,
        U_SetFlowCtrl,
        U_ConfigEscape,
        U_SetDCBConfig,
        U_CtrlDCD,
        U_CtrlBreak, 
        U_ClrRxBuffer,
        U_ClrTxBuffer,
        U_SetBaudRate,
        U_SendISRData_VFIFO,
        U_SendData_VFIFO,
        U_GetOwnerID,
        U_SetAutoBaud_Div,
        /*TY adds these to expand flexibility 2004/10/15*/
        U_Register_TX_cb,        
        U_Register_RX_cb,
        /*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/
        U_GetUARTByte_VFIFO,
        U_PutUARTByte_VFIFO,
        U_PutUARTBytes,
        /*for virtual com port to return DCB configuration*/
        U_ReadDCBConfig,
        U_CtrlRI,
        U_CtrlDTR,
        U_ReadHWStatus         
};
#endif
#endif //__DMA_UART_VIRTUAL_FIFO__



