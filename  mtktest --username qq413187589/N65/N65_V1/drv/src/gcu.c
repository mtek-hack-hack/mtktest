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
 *    gcu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the GCU driver.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "gcu.h"
#include "drvpdn.h"
#include "reg_base.h"


#if defined(DRV_GCU_REG_32BITS)
/*
* FUNCTION                                                            
*	GCU_isBUZY
*
* DESCRIPTION                                                           
*   	check whether GCU is computing new keyn stream
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE, GCU is computing new keyn stream
*	KAL_FALSE, GCU isn't computing new keyn stream
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool GCU_isBUZY(void)
{
	kal_uint32 STAT = DRV_Reg32(GCU_STAT);
	if (STAT & GCU_STAT_BUZY)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
}

/*
* FUNCTION                                                            
*	GCU_InputData
*
* DESCRIPTION                                                           
*   	Input GPRS Encryption Algorithm keys.
*	(Message keys and Secret keys)
*
* CALLS  
*
* PARAMETERS
*	data: the struct of the message keys and secret keys
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GCU_InputData(gcu_input *data)
{
	//Secret Key 0-4

	DRV_WriteReg32(GCU_KC0,((data->SK1 << 16) | data->SK0));
	DRV_WriteReg32(GCU_KC1,((data->SK3 << 16) | data->SK2));

	
	//Message Key 0-1
	DRV_WriteReg32(GCU_INPUT,((data->MK1 << 16)  | data->MK0));

	if (data->DIRECTION == 1)
	   DRV_WriteReg32(GCU_CTRL,(GCU_CTRL_DIR |GCU_CTRL_NORMAL));
	else
	   DRV_WriteReg32(GCU_CTRL,GCU_CTRL_NORMAL);
}

#else	/*!DRV_GCU_REG_32BITS*/

/*
* FUNCTION                                                            
*	GCU_isBUZY
*
* DESCRIPTION                                                           
*   	check whether GCU is computing new keyn stream
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE, GCU is computing new keyn stream
*	KAL_FALSE, GCU isn't computing new keyn stream
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool GCU_isBUZY(void)
{
	kal_uint16 STAT = DRV_Reg(GCU_STAT);
	if (STAT & GCU_STAT_BUZY)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
}

/*
* FUNCTION                                                            
*	GCU_InputData
*
* DESCRIPTION                                                           
*   	Input GPRS Encryption Algorithm keys.
*	(Message keys and Secret keys)
*
* CALLS  
*
* PARAMETERS
*	data: the struct of the message keys and secret keys
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GCU_InputData(gcu_input *data)
{
	//Secret Key 0-4
	DRV_WriteReg(GCU_KC0,data->SK0);
	DRV_WriteReg(GCU_KC1,data->SK1);
	DRV_WriteReg(GCU_KC2,data->SK2);
	DRV_WriteReg(GCU_KC3,data->SK3);
	
	//Message Key 0-1
	DRV_WriteReg(GCU_INPUT0,data->MK0);
	DRV_WriteReg(GCU_INPUT1,data->MK1);
	
	if (data->DIRECTION == 1)
	   DRV_WriteReg(GCU_CTRL,(GCU_CTRL_DIR |GCU_CTRL_NORMAL));
	else
	   DRV_WriteReg(GCU_CTRL,GCU_CTRL_NORMAL);
}
#endif	/*MT6218*/


kal_bool gea_cidecipher (kal_uint8 *src_buff_ptr,
	   kal_uint8 *dest_buff_ptr,	
	   kal_uint16 buff_len,
	   kal_uint8 cipher_algo,	   
	   kal_bool direction,
	   kal_uint8 *input_sk,
	   kal_uint32 input_mk)
{
   kal_uint16 index1;
   kal_uint16 index2;
   kal_uint32 key;
   kal_uint8  *key_ptr;
   gcu_input input;
   
   input.SK3 = input_sk[1] | (input_sk[0] << 8);
   input.SK2 = input_sk[3] | (input_sk[2] << 8);
   input.SK1 = input_sk[5] | (input_sk[4] << 8);
   input.SK0 = input_sk[7] | (input_sk[6] << 8);
   /* INPUT */
   input.MK0 = (kal_int16) input_mk;         /* LSB */
   input.MK1 = (kal_int16)(input_mk >> 16);  /* MSB */

   input.DIRECTION = direction;   /*decipher=1;cipher=0*/

   key_ptr = (kal_uint8 *)&key;
   
   DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_GCU,PDN_GCU);
   
   GCU_InputData(&input);
         
   if(cipher_algo == 1) /*A5_1 == 1*/
      GCU_GEA1Start(); /* for uplink link. According to spec. 04.64 */
   else if(cipher_algo == 2)
      GCU_GEA2Start(); /* for uplink link. According to spec. 04.64 */
   #if defined(DRV_GCU_GEA3)
   else if(cipher_algo == 3)
   	GCU_GEA3Start();  
   #endif 	
   else
      ASSERT(0);
   
	for(index1=0;index1 < ((buff_len+3)/4);index1++)
   {
      GCU_ReadKey(key);
      for(index2=0;index2 < 4;index2++)
	   {
	      if((index1*4+index2) == buff_len)
	         break;
	      #if defined(DRV_GCU_GEA3)  // Julie : GEA3 RBO reverse with bithe GEA1 and GEA2 
   				if(cipher_algo == 3)
   					   dest_buff_ptr[(index1*4+index2)] = src_buff_ptr[(index1*4+index2)] ^ key_ptr[3-index2];
   				else
   						 dest_buff_ptr[(index1*4+index2)] = src_buff_ptr[(index1*4+index2)] ^ key_ptr[index2]; 
	      #else    
	        dest_buff_ptr[(index1*4+index2)] = src_buff_ptr[(index1*4+index2)] ^ key_ptr[index2];
	      #endif
	   }
   }
   DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_GCU,PDN_GCU);
	return KAL_TRUE;
}

#ifdef DRV_GCU_REV_BIT_DISABLE/*only 6218B has this, Others projects dont have*/
void GCU_Disable_ReverseBit(void)
{
   DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_GCU,PDN_GCU);
   // clear GCU reverse bit
   DRV_Reg(GCU_CTRL) &= ~GCU_CTRL_RBO;
   DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_GCU,PDN_GCU);	
}	
#endif


