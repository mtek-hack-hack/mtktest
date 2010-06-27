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
 *    simd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SIM driver.
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
#include 	"kal_release.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"task_config.h"
#include 	"stacklib.h"
#include  	"drv_comm.h"
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include    "sim_hw.h"
#include    "sim_al.h"
#include    "dma_sw.h"
#include    "sim_sw.h"
#include    "drvpdn.h"
#include    "drv_hisr.h"

//#if ( (!defined(MT6208)) && (!defined(FPGA)) )
#if !defined(DRV_SIM_MT6208_SERIES)
#ifndef DRV_MULTIPLE_SIM
#include    "init.h"

#ifdef SIM_ADDDMA
#include    "dma_hw.h"
#endif   /*SIM_ADDDMA*/
#include		"usim_drv.h"

#ifndef __MAUI_BASIC__
#include 	"nvram_user_defs.h"
#include 	"nvram_struct.h"
#endif

#include "pwic.h"

#define SIM_DEFAULT_TOUT_VALUE      0x983
#define SIM_CMD_TOUT_VALUE          0x1400
kal_uint32 TOUTValue = SIM_DEFAULT_TOUT_VALUE;
static kal_uint8  TOUT_Factor=1;
/*Maybe changed when the unit of the HW TOUT counter is changed!!*/
const kal_uint8  ClkStopTimeTable[3][2]={  {0,5},
                                           {3,11},
                                           {6,19}
                                    };

Sim_Card SimCard;
kal_uint8 reset_index;
kal_uint8 PTS_data[4];
kal_bool  TS_HSK_ENABLE;
kal_char sim_dbg_str[200];
#if defined(__USIM_DRV__)
kal_bool sim_ATR_fail;
#endif

//#ifdef MT6205B
#if defined(DRV_SIM_MT6205B_SERIES)
   #ifdef __SIM_ENHANCED_SPEED__
      static kal_bool PTS_check = KAL_TRUE;
   #else
      static kal_bool PTS_check = KAL_FALSE;
   #endif
#else /*!MT6205B*/
   static kal_bool PTS_check = KAL_TRUE;
#endif   /*!MT6205B*/

static kal_uint32   	SIM_ERROR_LINE[MAX_SIM_ERROR_LINE];
static kal_uint8 	  	SIM_ERROR_LINE_INDEX;
static kal_bool   	sim_error_tag;


extern int sprintf(char *, const char *, ...);
void sim_assert(kal_uint32 line)
{
	 sim_error_tag = KAL_TRUE;
    SIM_ERROR_LINE[SIM_ERROR_LINE_INDEX&(MAX_SIM_ERROR_LINE - 1)] = line;
    SIM_ERROR_LINE_INDEX++;
}
void sim_assert_update_nvram(void)
{
	#ifndef __MAUI_BASIC__
   ilm_struct *ilm_ptr;
   peer_buff_struct *peer_buffer_ptr;
   sim_nvram_param_struct* data_stream;
   nvram_write_req_struct* parm_stream;
   kal_uint16 data_len;
   
   parm_stream = (nvram_write_req_struct *)construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
   peer_buffer_ptr = construct_peer_buff(sizeof(SIM_ERROR_LINE), 0, 0, TD_CTRL);
   
   data_stream = (sim_nvram_param_struct *)get_pdu_ptr(peer_buffer_ptr, &data_len);
   
   memcpy(data_stream, SIM_ERROR_LINE, sizeof(SIM_ERROR_LINE));
   
   //data_stream->ptr = SIM_ERROR_LINE;
   //data_stream->size = sizeof(SIM_ERROR_LINE);
   
   ((nvram_write_req_struct*) parm_stream)->file_idx =  NVRAM_EF_SIM_ASSERT_LID;
   ((nvram_write_req_struct*) parm_stream)->para = 1;

	ilm_ptr = allocate_ilm(MOD_SIM);
	ilm_ptr->src_mod_id = MOD_SIM;
	ilm_ptr->msg_id = MSG_ID_NVRAM_WRITE_REQ;
	ilm_ptr->sap_id = DRIVER_PS_SAP;
	ilm_ptr->local_para_ptr = (local_para_struct *)parm_stream;
	ilm_ptr->peer_buff_ptr = (peer_buff_struct *)peer_buffer_ptr;	 
	ilm_ptr->dest_mod_id = MOD_NVRAM;
	msg_send_ext_queue(ilm_ptr);
	#endif
	
}

void sim_dump_error_line(void)
{
	if (sim_error_tag != KAL_FALSE)
   {
   	kal_sprintf(sim_dbg_str,"[SIM dump]:Index=%d,SIM_ERROR_LINE=%d,%d,%d,%d", SIM_ERROR_LINE_INDEX, SIM_ERROR_LINE[0], SIM_ERROR_LINE[1], SIM_ERROR_LINE[2], SIM_ERROR_LINE[3]);
   	kal_print(sim_dbg_str);
   	sim_error_tag = KAL_FALSE;
		sim_assert_update_nvram();
   }
}

void SIM_Initialize(kal_uint8 format, kal_uint8 power);

//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
   kal_uint8                        sim_dmaport;
#ifdef SIM_ADDDMA
   static DMA_INPUT                 sim_input;
   //#ifdef MT6218B
   #if defined(DRV_SIM_DMA_6218B)
      #pragma arm section rwdata = "INTERNRW", zidata = "INTERNZI"
      static kal_uint8          baud_data[640];
      #pragma arm section rwdata , zidata
      static DMA_FULLSIZE_HWMENU    sim_menu;
      extern void dma_ch1_stop(void);
      extern void dma_ch1_init(kal_uint32 dstaddr, kal_uint16 len, kal_uint8 limiter);
      extern void dma_ch1_start(kal_uint32 srcaddr);
   #else /*!MT6218B*/
      static DMA_HWMENU             sim_menu;
   #endif   /*MT6218B*/
#endif   /*SIM_ADDDMA*/
#endif   /*MT6218,MT6218B*/

#ifdef SIM_ADDDMA
   //#if ( (defined(MT6205)) || (defined(MT6205B)) )
   #if defined(DRV_SIM_MT6205B_SERIES)
      kal_bool SIM_DMAIni(kal_bool Tx)	/*(KAL_TRUE ==> transmit, KAL_FALSE ==> receive)*/
      {
         if (DMA2_CheckRunStat())
      			DMA2_Stop();
      
         if (DMA2_CheckITStat())
      			DMA2_Stop();
      			
      	if (Tx == KAL_TRUE)
      	{
      		/* Size = 8bit, sinc en, dinc disable, hw management, 1 trans/dma cycle, USB master,Interrupt disable */
      		DRV_WriteReg(DMA2_CONTRL,DMA_CON_SimTxNormal);
      	}
      	else
      	{
      		/* Size = 8bit, sinc disable, dinc enable, hw management, 1 trans/dma cycle, USB master,Interrupt disable */
      		DRV_WriteReg(DMA2_CONTRL,DMA_CON_SimRxNormal);
      	}
      	return KAL_TRUE;
      }
   #endif   /*MT6205,MT6205B*/
#endif /*SIM_ADDDMA*/

//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
void SIM_L1Reset(void)
{
   SIM_DisAllIntr();
   
#ifdef SIM_ADDDMA
   if (sim_dmaport != 0)
      DMA_Stop(sim_dmaport);
#endif   /*SIM_ADDDMA*/
   
   SIM_FIFO_Flush();
   //De-activate SIM card
   if (DRV_Reg(SIM_CTRL)&SIM_CTRL_SIMON)
   {
      SimCard.State = SIM_WaitRejectDone;
      DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_SIMOFF|SIM_IRQEN_NATR));
      DRV_Reg(SIM_CTRL) &= ~SIM_CTRL_SIMON;
   }
   else
   {
      SIM_Initialize(SimCard.Data_format,SimCard.Power);
   }
}
#endif   /*! MT6205,MT6205B*/
kal_uint32 SIM_GetCurrentTime(void)
{
	return (DRV_Reg32(TDMA_base+0x0230));	
}
kal_uint32 SIM_GetDurationTick(kal_uint32 previous_time, kal_uint32 current_time)
{
	return drv_get_duration_tick(previous_time, current_time);
}

void SIM_SetRXTIDE(kal_uint16 RXTIDE)
{
	kal_uint16 TIDE;
	TIDE = DRV_Reg(SIM_TIDE);
	TIDE &= ~SIM_TIDE_RXMASK;
	TIDE |= (RXTIDE-1);
	DRV_WriteReg(SIM_TIDE,TIDE);
}

void SIM_SetTXTIDE(kal_uint16 _TXTIDE)
{
	kal_uint16 TIDE;
	TIDE = DRV_Reg(SIM_TIDE);
	TIDE &= ~SIM_TIDE_TXMASK;
	TIDE |= ((_TXTIDE+1) <<8);
	DRV_WriteReg(SIM_TIDE,TIDE);
}

#ifdef NoT0CTRL
kal_uint8 SIM_CheckSW(kal_uint16 ACK)
{
   if ((ACK & 0x00f0) == 0x0060)
			return KAL_TRUE;
	if ((ACK & 0x00f0) == 0x0090)
		return KAL_TRUE;
   
   return KAL_FALSE;
}
#endif   /*NoT0CTRL*/

kal_bool SIM_ResetNoATR(kal_uint8 pow)	//For normal case reset
{
	//Only enable SIM interrupt
	
	SimCard.State = SIM_WAIT_FOR_ATR;
	reset_index = 0;
	SimCard.Power = pow;

	//Deactivate the SIM card
	SIM_L1Reset();
	
	SIM_WaitEvent(SimCard,RST_READY);
	if (SimCard.result == SIM_SUCCESS)
	{
	   return KAL_TRUE;
	}
	else
	{
	   return KAL_FALSE;
	}
}

void SIM_Initialize(kal_uint8 format, kal_uint8 power)
{
	kal_uint16 tmp;
	kal_uint16 Conf;
	
	//tmp = *(volatile kal_uint16 *)0x80140070;
	//if (tmp != 1)
	   //while(1);
	SimCard.Data_format = format;
	SimCard.Power = power;
	dbg_print("SIM_Initialize power: %d, format: %d, TS_HSK_ENABLE: %d", power, format, TS_HSK_ENABLE);
	//Setup the SIM control module, SIM_BRR, SIM_CONF
	//Set SIMCLK = 13M/4, and BAUD RATE = default value(F=372,D=1);
	DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372));
   
	if (format != SIM_direct)
	{	
	   Conf = SIM_CONF_InDirect;
	}
	else
	{
	   Conf = SIM_CONF_Direct;
	}
	
   #ifdef PMIC_VSIM_SEL
   if (power == SIM_30V)
      pmic_adpt_set_vsim(PMIC_VSIM_3_0);
   else
      pmic_adpt_set_vsim(PMIC_VSIM_1_8);
   #elif !defined(PMIC_PRESENT)
	if (power != SIM_30V)
	{
		Conf |= SIM_CONF_SIMSEL;
	}
	#else /*Phone setting*/
	if (power == SIM_30V)
	{
		Conf |= SIM_CONF_SIMSEL;
	}
	#endif   /*Phone setting*/
	if (TS_HSK_ENABLE == KAL_TRUE)
	   Conf |= (SIM_CONF_TXHSK | SIM_CONF_RXHSK);

   DRV_WriteReg(SIM_CONF,Conf);
   
   if (TS_HSK_ENABLE == KAL_TRUE)
   {
      SIM_SetRXRetry(1);
	   SIM_SetTXRetry(1);
   }
   else
   {
      SIM_SetRXRetry(0);
	   SIM_SetTXRetry(0);
   }

	//Set the ATRTout as 9600etu
	SIM_SetTOUT(TOUTValue);
   
   // reset interrupts, flush rx, tx fifo
	SIM_FIFO_Flush();
		
	//Set the txfifo and rxfifo tide mark
	SIM_SetRXTIDE(1);
	
	//Read Interrupt Status
	tmp = DRV_Reg(SIM_STS);
	
	SimCard.State = SIM_WAIT_FOR_ATR;
	
	//Enable Interrupt
	DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_Normal & ~SIM_IRQEN_RXERR));
   SimCard.recDataErr = KAL_FALSE;
	//activate the SIM card, and activate the SIMCLK
	
	SIM_Active();
	////dbg_print("SIM ACtive\r\n");
}

kal_bool SIM_PTSProcess(kal_uint8 *TxBuffaddr, kal_uint8 Txlength)	//Bool lalasun
{
	kal_uint8    index;
	kal_uint8    tmp;

	#if defined(__USIM_DRV__)
	if(DRV_Reg(SIM_COUNT))
		USIM_CLR_FIFO();
	SIM_SetTOUT(TOUTValue);	
	#endif
	
	for (index = 0; index < Txlength; index++)
	{
	   PTS_data[index]=0;
		tmp = *(TxBuffaddr+index);
		DRV_WriteReg(SIM_DATA,tmp);
	}

	SimCard.State = SIM_PROCESS_PTS;

	SIM_SetRXTIDE(Txlength);
	DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
	
	SIM_WaitEvent(SimCard,PTS_END);
	
	if ((SimCard.recDataErr == KAL_TRUE) 
	   || (SimCard.result == SIM_INIPTSERR))
   {
      SimCard.recDataErr = KAL_FALSE;
      return KAL_FALSE;
   }
   
	for (index = 0; index < Txlength; index++)
	{
		if (PTS_data[index]!=*(TxBuffaddr+index))
		{
			return KAL_FALSE;
		}
	}
	// Some high speed SIM card after clock rate change have to wait a while to
	// to receive the first command.
	if(PTS_data[1] != 0x00)
		kal_sleep_task(10);
	
	return KAL_TRUE;
}

kal_bool SIM_ProcessATRData(void)
{
   kal_uint8 index;
	kal_uint16 tmp,tmp1;
	kal_uint16 SIM_BRR_REG;
	kal_uint8 ptsdata[4];
	kal_uint16 TOUT;
	kal_uint8 Dvalue = 1;

	#if defined(__USIM_DRV__)
	if(sim_ATR_fail)
	{
	   SIM_WaitEvent(SimCard,ATR_END);
	   
	   if (SimCard.recDataErr == KAL_TRUE)
	   {
	      SimCard.recDataErr = KAL_FALSE;
	      return KAL_FALSE;
	   }
	}
	else
	{
		kal_mem_cpy(SimCard.recData, usim_dcb.ATR_data+1, usim_dcb.ATR_index-1);
	}
	#else
	SIM_WaitEvent(SimCard,ATR_END);
	
	if (SimCard.recDataErr == KAL_TRUE)
	{
		SimCard.recDataErr = KAL_FALSE;
		return KAL_FALSE;
	}	
	#endif
	
   index = 1;
   if (SimCard.recData[0] & 0x00f0)
   {
      if (SimCard.recData[0] & TAMask)
      {
         tmp = SimCard.recData[index]; //TA1
         index++;
         ////dbg_print("TA1=%x\r\n",tmp);
         if ((tmp == 0x0011)||(tmp == 0x0001))
         {
            //Don't process ATR data!!
            SimCard.State = SIM_PROCESSCMD;
            SIMCmdInit();
            #ifdef NoT0CTRL
	         SimCard.cmdState = SIMD_CmdIdle;
	         #endif
	         TOUTValue = SIM_CMD_TOUT_VALUE;
            SIM_SetTOUT(TOUTValue);
	         return KAL_TRUE;
         }
         else
         {
            switch (tmp)
            {
               case 0x0094:		//F = 512,D=8
                  SimCard.sim_card_speed = sim_card_enhance_speed_64;
#if 1
                  if (!PTS_check)
#else
/* under construction !*/
#endif
                  {
                     Dvalue = 1;
                     ptsdata[0]=0xff;
					   	ptsdata[1]=0x00;
					   	ptsdata[2]=0xff;
					   	if (!SIM_PTSProcess(ptsdata,3))
					   	{
					   	   return KAL_FALSE;
					   	}
					   	TOUTValue = SIM_CMD_TOUT_VALUE;
						   SIM_SetTOUT(TOUTValue);
				      }
                  else
                  {
//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
                     kal_uint32 savedMask;
#endif   /*MT6218B*/
					   	Dvalue = 8;
					   	ptsdata[0]=0xff;
					   	ptsdata[1]=0x10;
					   	ptsdata[2]=0x94;
					   	ptsdata[3]=0x7b;
					   	SimCard.Speed = Speed64;
					   	
					   	if (!SIM_PTSProcess(ptsdata,4))
					   	{
					   	   return KAL_FALSE;
					   	}
//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
                     if (INT_ecoVersion() < GN)
                     {
					   	   savedMask = SaveAndSetIRQMask();
					   	   dma_ch1_stop();
					   	   RestoreIRQMask(savedMask);
					      }
#endif   /*MT6218B*/
					   	SIM_BRR_REG = DRV_Reg(SIM_BRR);
					   	SIM_BRR_REG &= SIM_BRR_CLKMSK;
					   	SIM_BRR_REG |= SIM_BRR_BAUD_Div64;
					   	DRV_Reg(SIM_BRR) = SIM_BRR_REG;
					   	TOUT_Factor = 8;  //hw-specific
					   	TOUTValue = TOUT_Factor*SIM_CMD_TOUT_VALUE;
					   	SIM_SetTOUT(TOUTValue);
                  }
        				break;
        					
        			case 0x0095:		//F=512,D=16
        			   SimCard.sim_card_speed = sim_card_enhance_speed_32;
//#if !defined(MT6205B)
#if !defined(DRV_SIM_MT6205B_SERIES)
                  if (!PTS_check)
#else
                  if (1)
#endif
                  {
        				   Dvalue = 1;
	        			   ptsdata[0]=0xff;
					      ptsdata[1]=0x00;
					      ptsdata[2]=0xff;
					      if (!SIM_PTSProcess(ptsdata,3))
						   {
						      return KAL_FALSE;
						   }
						   TOUTValue = SIM_CMD_TOUT_VALUE;
						   SIM_SetTOUT(TOUTValue);
						}
                  else
                  {
//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
                     kal_uint32 savedMask;
#endif   /*MT6218B*/
        				   Dvalue = 16;
        				   ptsdata[0]=0xff;
					      ptsdata[1]=0x10;
					      ptsdata[2]=0x95;
					      ptsdata[3]=0x7a;
					      SimCard.Speed = Speed32;
					      
					      if (!SIM_PTSProcess(ptsdata,4))
						   {
						      return KAL_FALSE;
						   }
//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
                     if (INT_ecoVersion() < GN)
                     {
					   	   savedMask = SaveAndSetIRQMask();
					   	   dma_ch1_stop();
					   	   RestoreIRQMask(savedMask);
					      }
#endif   /*MT6218B*/
						   SIM_BRR_REG = DRV_Reg(SIM_BRR);
					      SIM_BRR_REG &= SIM_BRR_CLKMSK;
					      SIM_BRR_REG |= SIM_BRR_BAUD_Div32;
					      DRV_Reg(SIM_BRR) = SIM_BRR_REG;
						   TOUT_Factor = 16;
					      TOUTValue = TOUT_Factor*SIM_CMD_TOUT_VALUE;
					      SIM_SetTOUT(TOUTValue);
                  }
        				break;
        			
	        		default:		//F=372,D=1
	        			Dvalue = 1;
	        			ptsdata[0]=0xff;
					   ptsdata[1]=0x00;
					   ptsdata[2]=0xff;
					   if (!SIM_PTSProcess(ptsdata,3))
						{
						   return KAL_FALSE;
						}
						TOUTValue = SIM_CMD_TOUT_VALUE;
						SIM_SetTOUT(TOUTValue);
        				break;
        		}
         }
      }  /*if (SimCard.recData[0] & TAMask)*/
        		
      if (SimCard.recData[0] & TBMask)
      {
         tmp = SimCard.recData[index];
         ////dbg_print("TB1=%x\r\n",tmp);
         index++;
      }
      if (SimCard.recData[0] & TCMask)
      {
         tmp = SimCard.recData[index];
         ////dbg_print("TC1=%x\r\n",tmp);
         if (tmp != 0xff && tmp != 0x00)
        	{
            return KAL_FALSE;
         }
        	index++;
      }
      
      if (SimCard.recData[0] & TDMask)
      {
         tmp = SimCard.recData[index];	///TD1
         index++;
         ////dbg_print("TD1=%x\r\n",tmp);
         if (tmp & TCMask)	//TC2 is obtain
        	{
            if (tmp & TAMask)
            {
               tmp1 = SimCard.recData[index];
               ////dbg_print("TA2=%x\r\n",tmp1);
               index++;
            }
				if (tmp & TBMask)	
        		{
        			tmp1 = SimCard.recData[index];
        			////dbg_print("TB2=%x\r\n",tmp1);
        			index++;
        		}
        		if (tmp & TCMask)	//TC2
        		{
        		   tmp1 = SimCard.recData[index];
               ////dbg_print("TC2=%x\r\n",tmp1);
               TOUT = (kal_uint16)(960*Dvalue);
               TOUT = (TOUT*tmp1)/4;   /*(/4)is hw-specific*/
               index++;
               TOUTValue = TOUT+8;
               //////dbg_print("TOUT=%x\r\n",TOUT);
               DRV_WriteReg(SIM_TOUT,TOUT);
        		}        			
         }
      }  /*if (SimCard.recData[0] & TDMask)*/
   }/*if (SimCard.recData[0] & 0x00f0)*/
	SimCard.State = SIM_PROCESSCMD;
	SIMCmdInit();
	#ifdef NoT0CTRL
	SimCard.cmdState = SIMD_CmdIdle;
	#endif   /*NoT0CTRL*/
	return KAL_TRUE;
}

void SIM_Cmdhandler(void)
{
#ifndef SIM_ADDDMA
   while(SIM_FIFO_GetLev())
   {
      *(SimCard.rxbuffer+SimCard.recDataLen) = (kal_uint8)DRV_Reg(SIM_DATA);
      SimCard.recDataLen++;
   }
#endif /*SIM_ADDDMA*/
   SIM_SetEvent(SimCard,SIM_SUCCESS);
   return;
}

#ifndef SIM_ADDDMA
void SIM_Txhandler(void)
{
#ifdef NoT0CTRL
   kal_uint8 index;
   kal_uint16 reslen;
   reslen = SimCard.txsize - SimCard.txindex;
   if(reslen <= 15)
   {
      for(index=0;index<reslen;index++)
      {
         DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
         SimCard.txindex++;
      }
      SIM_SetRXTIDE(2);
      SimCard.cmdState = SIM_WaitProcByte;
      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
   }
   else
   {
      for(index=0;index<15;index++)
      {
         DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
         SimCard.txindex++;
      }
      SIM_SetTXTIDE(0);
      DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_CMDNormal|SIM_IRQEN_TX));
   }
   return;
#else   /*NoT0CTRL*/
   kal_uint8 index;
   kal_uint16 reslen;
   
   reslen = SimCard.txsize - SimCard.txindex;
   if(reslen <= 15)
   {
      for(index=0;index<reslen;index++)
      {
         DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
         SimCard.txindex++;
      }
      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
   }
   else
   {
      for(index=0;index<15;index++)
      {
         DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
         SimCard.txindex++;
      }
      SIM_SetTXTIDE(0);
      DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_CMDNormal|SIM_IRQEN_TX));
   }
#endif   /*NoT0CTRL*/
}
#endif   /*SIM_ADDDMA*/

void SIM_Rxhandler(kal_uint16 sim_int)
{
   kal_uint16 TS;
   kal_uint8  index;
   
   if (SimCard.State == SIM_WAIT_FOR_ATR)
	{
		TS = DRV_Reg(SIM_DATA);
		
		if ((TS == 0x003f) || (TS == 0x003b))
		{
			SimCard.State = SIM_PROCESS_ATR;

			DRV_Reg(SIM_CONF) |= 
			         (SIM_CONF_TXHSK | SIM_CONF_RXHSK |SIM_CONF_TOUTEN);

			/* *(volatile kal_uint16 *)SIM_CONF |= SIM_CONF_TOUTEN; */
			SIM_SetRXTIDE(12);
			SIM_SetRXRetry(7);
			SIM_SetTXRetry(7);
         SimCard.recDataLen = 0;
         
			SIM_SetEvent(SimCard,SIM_SUCCESS);
			SimCard.EvtFlag = ATR_END;
			DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
		}
		else
		{	
			reset_index++;	//Change format!!, don't change power
			if (reset_index>1)
			{
				reset_index = 0;
				SIM_SetEvent(SimCard,SIM_CARDERR);
				SIM_ASSERT(0);
			}
			else
			{
				if (SimCard.Data_format == SIM_indirect)
				{
					SimCard.Data_format = SIM_direct;
					SIM_L1Reset();
				}
				else
				{
					SimCard.Data_format = SIM_indirect;
					SIM_L1Reset();
				}
			}
		}
		return;	
	}
	
	if (SimCard.State == SIM_PROCESS_ATR)
	{
	   while(1)
      {
         if (SIM_FIFO_GetLev())
         {
            SimCard.recData[SimCard.recDataLen] = (kal_uint8)DRV_Reg(SIM_DATA);
            SimCard.recDataLen++;
         }
         else
         {
            if (sim_int & SIM_STS_TOUT)
            {
               SIM_SetEvent(SimCard,SIM_SUCCESS);
            }
            break;
		   }
      }
      return;
	}
	
	if (SimCard.State == SIM_PROCESS_PTS)
	{
		index = 0;
		while(KAL_TRUE)
		{
			PTS_data[index] = (kal_uint8)DRV_Reg(SIM_DATA);
			index++;
			
			if (SIM_FIFO_GetLev()==0)
			{
				SIM_SetEvent(SimCard,SIM_SUCCESS);
				break;
			}
		}
		SIM_DisAllIntr();
		return;
	}
	
	if (SimCard.State == SIM_PROCESSCMD)
	{
#ifdef SIM_ADDDMA
	   ////dbg_print("something error\r\n");
#else /*SIM_ADDDMA*/
#ifdef NoT0CTRL
{
   kal_uint16 ACK;
   while(SIM_FIFO_GetLev())
   {
      if (SimCard.cmdState == SIM_WaitProcByte)
      {
         ACK = DRV_Reg(SIM_DATA);
         if ((ACK == SimCard.INS) || (ACK == (SimCard.INS+1)))    //ACK
         {
            if (SimCard.txsize != 5)
            {
               /*Trx command*/
               DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
               SimCard.txindex++;
               SIM_SetTXTIDE(0);
               DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_CMDNormal | SIM_IRQEN_TX));
               SimCard.cmdState = SIM_AckDataState;
               return;
            }
            else
            {
               SIM_SetTXTIDE(0xffff);
               DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
               SimCard.cmdState = SIM_AckDataState;
               continue;
            }
         }
         
         if ((ACK == (~SimCard.INS & 0x00ff)) || (ACK == (~(SimCard.INS+1)& 0x00ff)))    ///NACK
         {
            if (SimCard.txsize != 5)
            {
               DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
               SimCard.txindex++;
               SIM_SetRXTIDE(1);
               SimCard.cmdState = SIM_WaitProcByte;
               /*Trx command*/
               DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
               return;
            }
            else
            {
               SIM_SetTXTIDE(0xffff);
               SimCard.cmdState = SIM_NAckDataState;
               DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
            }
            continue;
         }
         
         if (ACK == 0x60)    //ACK
         {
            continue;
         }
         if (SIM_CheckSW(ACK))    //ACK
         {
            SimCard.SW1 = (kal_uint8)ACK;
            SIM_SetRXTIDE(1);
            SimCard.recDataLen++;
            SimCard.cmdState = SIM_WaitSWByte;
            continue;
         }
      }
      
      if (SimCard.cmdState == SIM_WaitSWByte)
      {
         SimCard.SW2 = (kal_uint8)DRV_Reg(SIM_DATA);
         /*SimCard.recDataLen++;*/
         SimCard.recDataLen--;
         SIM_SetEvent(SimCard,SIM_SUCCESS);
         return;
      }
      
      if (SimCard.cmdState == SIM_AckDataState)
      {
         *(SimCard.rxbuffer+SimCard.recDataLen) = (kal_uint8)DRV_Reg(SIM_DATA);
         SimCard.recDataLen++;
         if (SimCard.recsize == SimCard.recDataLen)
         {
            SimCard.cmdState = SIM_WaitProcByte;
         }
         continue;
      }
      
      if (SimCard.cmdState == SIM_NAckDataState)
      {
         *(SimCard.rxbuffer+SimCard.recDataLen) = (kal_uint8)DRV_Reg(SIM_DATA);
         SimCard.recDataLen++;
         SimCard.cmdState = SIM_WaitProcByte;
         continue;
      }
   }  /*while(SIM_FIFO_GetLev())*/
   if (SimCard.txsize == 5)
   {
      if ((SimCard.recsize+2 - SimCard.recDataLen) > 15)
      {
         SIM_SetRXTIDE(CMD_RECBUFSIZE-8);
      }
      else
      {
         SIM_SetRXTIDE(SimCard.recsize+2 - SimCard.recDataLen);
      }

      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
   }
}
#else /*NoT0CTRL*/
	   while(SIM_FIFO_GetLev())
      {
         *(SimCard.rxbuffer+SimCard.recDataLen) = (kal_uint8)DRV_Reg(SIM_DATA);
         SimCard.recDataLen++;
      }
#endif /*NoT0CTRL*/
#endif /*SIM_ADDDMA*/
		return;
	}
}

void SIM_HISR(void)
{
	kal_uint16 	sim_int;
	
	sim_int = DRV_Reg(SIM_STS);

	////dbg_print("sim_int=%x\r\n",sim_int);
	if ( sim_int & SIM_STS_TXERR)
	{
	   ////dbg_print("SIM_STS_TXERR\r\n");
	   if (SimCard.State == SIM_PROCESSCMD)
	   {
	      SimCard.State = SIM_SERIOUSERR;
	      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_TOUT);
	      SIM_ASSERT(0);
	   }
	   else
	   {
	      SIM_Reject();
	      SIM_ASSERT(0);
	      //SIM_SetEvent(SimCard,SIM_INIPTSERR);
	   }
	}

	if ( sim_int & SIM_STS_TX)
	{
	   ////dbg_print("SIM_STS_TX\r\n");
	   //SIM_DisIntr(SIM_IRQEN_TX);
#ifdef  SIM_ADDDMA
	   ////dbg_print("something error\r\n");
#else /*SIM_ADDDMA*/
      SIM_Txhandler();  /* Only used for no DMA */
#endif /*SIM_ADDDMA*/
	}
	
	if ( sim_int & SIM_STS_TOUT)
	{
	   ////dbg_print("703SIM_STS_TOUT\r\n");
	   if(SimCard.State == SIM_WAIT_FOR_ATR)
	   {
	      SIM_SetEvent(SimCard,SIM_INIPTSERR);
	      SIM_ASSERT(0);
	   }
	   
	   if(SimCard.State == SIM_PROCESS_ATR) 
	   {
	      SIM_Rxhandler(sim_int);
	   }
	   
	   if( SimCard.State == SIM_PROCESS_PTS)
	   {
         SIM_SetEvent(SimCard,SIM_INIPTSERR);
         SIM_ASSERT(0);
	   }
	   
	   if (SimCard.State == SIM_PROCESSCMD)
	   {
	      if(SimCard.recDataErr == KAL_TRUE)
	      {
	         SIM_SetEvent(SimCard,SIM_CMDRECERR);
	         SIM_ASSERT(0);
	      }
	      else
	      {
	         switch(SimCard.cmdState)
	         {
	            case SIM_ProcessClk:
	               ////dbg_print("SIM_ProcessClk\r\n");
	               SIM_SetEvent(SimCard,SIM_CLKPROC);
	               break;
	               
	            case SIM_StopClk:
	               ////dbg_print("SIM_StopClk\r\n");
	               SIM_Idle(SimCard.clkStopLevel);
	               break;
	               
	            default: /*normal command case*/
	               #ifdef NoT0CTRL
	               if (SimCard.cmdState == SIM_WaitProcByte)
	               {
   	               kal_uint8 ACK;
	                  kal_uint8 Error;
	                  Error = KAL_TRUE;
	                  while(SIM_FIFO_GetLev())
	                  {
      	               ACK = (kal_uint8)DRV_Reg(SIM_DATA);
	                     if (ACK == 0x60)    //NULL
                        {
                           continue;
                        }
                        if (SIM_CheckSW(ACK))    //ACK
                        {
                           SimCard.SW1 = ACK;
                           SimCard.SW2 = (kal_uint8)DRV_Reg(SIM_DATA);
                           SIM_SetEvent(SimCard,SIM_SUCCESS);
                           Error = KAL_FALSE;
                        }
                        else
                        {
                           break;
                        }
	                  }
	                  if (Error)
	                  {
      	               SIM_SetEvent(SimCard,SIM_CMDTOUT);
      	               SIM_ASSERT(0);
	                  }
	               }
	               else
	               {
   	               SIM_SetEvent(SimCard,SIM_CMDTOUT);
   	               SIM_ASSERT(0);
	               }
	               #else /*NoT0CTRL*/
	               SIM_ASSERT(0);
	               SimCard.timeout = KAL_TRUE;
	               SIM_SetEvent(SimCard,SIM_CMDTOUT);
	               #endif   /*NoT0CTRL*/
	               break;
	         }/*endof switch*/
	      }
	   }/*if (SimCard.State == SIM_PROCESSCMD)*/
	   
	   if (SimCard.State == SIM_SERIOUSERR)
	   {
         SIM_SetEvent(SimCard,SIM_CMDTXERR);
         SIM_ASSERT(0);
	   }
	   SIM_DisAllIntr();
	}
	
	if (sim_int & SIM_STS_RX)
	{
	   ////dbg_print("SIM_STS_RX\r\n");
	   if(SimCard.timeout != KAL_TRUE)
      SIM_Rxhandler(sim_int);
	}

   if ( sim_int & SIM_STS_OV)
   {
      ////dbg_print("SIM_STS_OV\r\n");
      SimCard.recDataErr = KAL_TRUE;
      if (SimCard.State == SIM_PROCESSCMD)
      {
			SIM_ASSERT(0);
	   }
   }
   
	if ( sim_int & SIM_STS_RXERR)
	{
	   ////dbg_print("SIM_STS_RXERR\r\n");
	   SimCard.recDataErr = KAL_TRUE;
	   DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_TOUT);
      if (SimCard.State == SIM_PROCESSCMD)
      {
			SIM_ASSERT(0);
	   }
	}
	
   if ( (sim_int &  SIM_IRQEN_T0END)
       && (SimCard.State == SIM_PROCESSCMD))
	{
	   ////dbg_print("SIM_IRQEN_T0END\r\n");
      SIM_Cmdhandler();
      SIM_DisAllIntr();
	}
	
	if ( sim_int & SIM_STS_NATR)
	{
	   ////dbg_print("SIM_STS_NATR\r\n");
	   SIM_DisAllIntr();
	   if (SimCard.SIM_ENV == ME_18V_30V)
	   {
	      if (SimCard.Power == SimCard.initialPower)
         {
            if (SimCard.Power != SIM_30V)
            {
               SimCard.Power = SIM_30V;
            }
            else
            {
               SimCard.Power = SIM_18V;
            }
            SIM_L1Reset();
         }
         else
         {
            SIM_Reject();
         }
	   }
	   else
	   {
	      SIM_Reject();
	   }
   }

	if ( sim_int & SIM_STS_SIMOFF)
	{
	   ////dbg_print("SIM_STS_SIMOFF\r\n");
		SIM_DisAllIntr();
      if (SimCard.State == SIM_PWROFF)
      {
         DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
         if (SimCard.reject_set_event)
         {
            SIM_SetEvent(SimCard,SIM_NOREADY);
            SIM_ASSERT(0);
         }
      }
      else
      {
//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
         if (SimCard.State == SIM_WaitRejectDone)
         {
            SIM_Initialize(SimCard.Data_format,SimCard.Power);
         }
         else
         {
            SIM_ASSERT(0);
         }
#else /*! (MT6205,MT6205B)*/
         SIM_Initialize(SimCard.Data_format,SimCard.Power);
#endif   /*MT6205,MT6205B*/
      }
	}
	IRQClearInt(IRQ_SIM_CODE);
	IRQUnmask(IRQ_SIM_CODE);   
}

void SIM_LISR(void)
{
   IRQMask(IRQ_SIM_CODE);
   drv_active_hisr(DRV_SIM_HISR_ID);
}

#if 1
//==========================SIM adaption=============================
/*
* FUNCTION                                                            
*  L1sim_PowerOff
*
* DESCRIPTION                                                           
*     The function requests the driver to deactivate SIM
*
* CALLS  
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_PowerOff(void)  //Validate
{
   SIM_DisAllIntr();
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   if(DRV_Reg(SIM_CTRL) | SIM_CTRL_HALT)
   	DRV_Reg(SIM_CTRL) &= ~SIM_CTRL_HALT;
   SimCard.reject_set_event = KAL_FALSE;
   SIM_Reject();
   //DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
}

/*
* FUNCTION
*	L1sim_Reset
*
* DESCRIPTION
*   	The function L1sim_Reset is used to reset SIM by specific voltage
*
* CALLS
*
* PARAMETERS
*	resetVolt: Request the driver to reset SIM at voltage resetVolt
*	resultVolt: The pointer to the voltage after the driver reset SIM. 
*	(RESET_3V,RESET_5V)
*	Info: The pointer to buffer of ATR data returned from SIM
*
* RETURNS
*	SIM_NO_ERROR	No SIM error
*	SIM_NO_INSERT	No SIM inserted
*	SIM_CARD_ERROR	SIM fatal error
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 L1sim_Core_Reset(kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info)	//Validate
{
   kal_uint8 index;
   
   kal_sleep_task(2);
   SIM_DisAllIntr();
   SimCard.sim_card_speed = sim_card_normal_speed;
   SimCard.reject_set_event = KAL_TRUE;
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   TOUTValue = SIM_DEFAULT_TOUT_VALUE;
   TOUT_Factor=1;
   SimCard.clkStop = KAL_FALSE;
	SimCard.Speed = Speed372;
	SimCard.State = SIM_WAIT_FOR_ATR;
	SimCard.Power = resetVolt;
	SimCard.initialPower = resetVolt;
	
	#if defined(__USIM_DRV__)
	{
		SimCard.Data_format = usim_dcb.dir;
		SimCard.result = SIM_SUCCESS;
		sim_ATR_fail = KAL_FALSE;
	}
	#else
	SimCard.Data_format = SIM_direct; 
	reset_index = 0;
	SimCard.result = SIM_NOREADY;
	SIM_L1Reset();
	
	SIM_WaitEvent(SimCard,RST_READY);
	
	if (SimCard.result == SIM_NOREADY)
	{
	   //L1sim_PowerOff();
	   return SIM_NO_INSERT;
	}
	
	if (SimCard.result == SIM_CARDERR)
	{
		if (SimCard.Power == SIM_30V)
		{
			SimCard.Power = SIM_18V;
			SIM_L1Reset();
		}
		else
		{
			SimCard.Power = SIM_30V;
			SIM_L1Reset();
		}
		SIM_WaitEvent(SimCard,RST_READY);
	}
	
	#endif
	if (SimCard.result == SIM_SUCCESS)
	{
		index=0;
		while(1)
		{
			if (!SIM_ProcessATRData())
			{
				index++;
				if (index == 3)
				{
				   PTS_check = KAL_FALSE;
				}
				else if (index > 3)
				{
				   PTS_check = KAL_FALSE;
					L1sim_PowerOff();
					return SIM_CARD_ERROR;
				}
				#if defined(__USIM_DRV__)
				sim_ATR_fail = KAL_TRUE;
				#endif
				SIM_ResetNoATR(SimCard.Power);
			}
			else
			{
			   if (resultVolt != NULL)
			   {
			      *resultVolt = SimCard.Power;
			   }
			   if (Info != NULL)
			   {
	            for (index = 0;index < SimCard.recDataLen;index++)
	            {
   		         Info->info[index] = SimCard.recData[index];
	            }
	         }
				return SIM_NO_ERROR;
			}
		}
	}
	else
	{
	   L1sim_PowerOff();
		return SIM_CARD_ERROR;
	}
}

kal_uint8 L1sim_Reset(kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info)	//Validate
{
   kal_uint8 result;
   TS_HSK_ENABLE = KAL_TRUE;
   result = L1sim_Core_Reset(resetVolt,resultVolt,Info);
   if (result != SIM_NO_ERROR)
   {
   	kal_print("[SIM]: SIM reset fail with TS_HSK_ENABLE");   	
      TS_HSK_ENABLE = KAL_FALSE;
      result = L1sim_Core_Reset(resetVolt,resultVolt,Info);
   }
   if(result == SIM_NO_ERROR)
   {
   	kal_sprintf(sim_dbg_str,"[SIM]:SIM RESET OK, power:%d ,speed:%d",SimCard.Power,SimCard.Speed);
   	kal_print(sim_dbg_str);
   }
   else
   {
   	kal_sprintf(sim_dbg_str,"[SIM]:SIM RESET FAIL, result:%d", result);
   	kal_print(sim_dbg_str);
   }
   return result;
}

void L1sim_NormalBaud(void)
{
//#if ( (defined(MT6218)) || (defined(MT6218B)) )
#if defined(DRV_SIM_BAUD_6218B_SERIES)
   SIM_DisAllIntr();
   if (SimCard.clkStop == KAL_TRUE)
   {
      SIM_ActiveClk();
   }
   else
   {
      DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   }
   DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372));
#endif   /*MT6218,MT6218B*/
}

void L1sim_ChangeBaud(void)
{
//#if ( (defined(MT6218)) || (defined(MT6218B)) )
#if defined(DRV_SIM_BAUD_6218B_SERIES)
   SIM_DisAllIntr();
   if (SimCard.clkStop == KAL_TRUE)
   {
      SIM_ActiveClk();
   }
   else
   {
      DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   }
   DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | (0x17<<2)));
#endif   /*MT6218,MT6218B*/
}

/*
* FUNCTION                                                            
*	L1sim_Configure
*
* DESCRIPTION                                                           
*   	The function indicates clock mode when idle.
*
* CALLS  
*
* PARAMETERS
*	clockMode: The clockMode defines the clock mode when idle.
*		CLOCK_STOP_AT_HIGH,CLOCK_STOP_AT_LOW,CLOCK_STOP_NOT_ALLOW
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Configure(kal_uint8 clockMode)	//Validate
{
	switch (clockMode)
	{
		case CLOCK_STOP_AT_HIGH:
		   // #if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   DRV_Reg(SIM_CONF) |= SIM_CONF_HALTEN;
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard.clkStop = KAL_TRUE;
			SimCard.clkStopLevel = KAL_TRUE;
			break;
			
		case CLOCK_STOP_AT_LOW:
		   //#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   DRV_Reg(SIM_CONF) |= SIM_CONF_HALTEN;
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard.clkStop = KAL_TRUE;
			SimCard.clkStopLevel = KAL_FALSE;
			break;
			
		case CLOCK_STOP_NOT_ALLOW:
		   //#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   DRV_Reg(SIM_CONF) &= ~SIM_CONF_HALTEN;
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard.clkStop = KAL_FALSE;
			break;
			
		default:
			break;
	}
}

/*
* FUNCTION                                                            
*	SIM_CMD
*
* DESCRIPTION                                                           
*   	The function is used to transmit coded command and 
*	its following data to the driver.
*
* CALLS  
*
* PARAMETERS
*	txData: Pointer to the transmitted command and data.
*	txSize:	The size of the transmitted command and data from AL to driver.
*	expSize: The size of expected data from SIM
*	result: Pointer to received data 
* 	rcvSize: Pointer to the size of data received
*	parityError: 1 (parity error) or 0(no parity error)
*
* RETURNS
*	status(high byte:sw1 low byte: sw2)
*
* GLOBALS AFFECTED
*   external_global
*/

kal_uint16 SIM_CMD(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error)
//kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  expSize, kal_uint8  *result,kal_uint8  *rcvSize, kal_uint8 *Error)
{
   kal_uint16 SW;
   kal_uint8 index;
   kal_uint16 INS;
   kal_uint16 temp;
   kal_uint16 expSize = *rcvSize;
#ifdef   SIM_ADDDMA 
	kal_bool	txDelay = KAL_FALSE;
   kal_uint32 txaddr;
   kal_uint32 rxaddr;   
#endif/*SIM_ADDDMA*/
   kal_uint32 savedMask = 0; 

	if(result == NULL && *rcvSize != 0)
	{
		*Error = KAL_TRUE;
	  	return 0;
	}
	if (SimCard.State != SIM_PROCESSCMD)
	{
	   *Error = KAL_TRUE;
	   return 0;
	}
   
   #ifdef NoT0CTRL 
   if ((SimCard.cmdState != SIMD_CmdIdle)&&(SimCard.cmdState != SIM_StopClk))
   {
      *Error = KAL_TRUE;
      return 0;
   }
   #endif   /*NoT0CTRL*/

   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #endif
   /*for clock stop mode*/
   SIM_DisAllIntr();
   
   if (SimCard.clkStop == KAL_TRUE)
   {
      SIM_ActiveClk();
   }
   else
   {
      DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   }

   SIM_DisAllIntr();
   
   if( (SimCard.Speed != Speed372) &&
       ((DRV_Reg(SIM_CTRL)) & SIM_CTRL_HALT) 
     )     
   {
      DRV_Reg(SIM_CONF) &= ~SIM_CONF_TOUTEN;
      SIM_SetTOUT(ClkStopTimeTable[SimCard.Speed][0]*TOUT_Factor);
      DRV_Reg(SIM_CONF) |= SIM_CONF_TOUTEN;
      SimCard.cmdState = SIM_ProcessClk;
      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_TOUT);
      SIM_WaitEvent(SimCard,CLK_PROC);
   }
	else if(SimCard.is_err && SimCard.Speed == Speed32) // to solve ROSSINI SIM issue
	{		
		kal_uint32 t1;
	
		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 5); // delay 500 clock cycles (152us) 
		
	}
   DRV_Reg(SIM_CONF) &= ~SIM_CONF_TOUTEN;

   kal_set_eg_events(SimCard.event,0,KAL_AND);  //2: NU_AND
   
   SIM_SetTOUT(TOUTValue);
   SIM_FIFO_Flush();
   *Error = KAL_FALSE;
   SimCard.recDataErr = KAL_FALSE;
	
#ifdef SIM_ADDDMA
   txaddr = (kal_uint32)txData;
   rxaddr = (kal_uint32)result;
#else /*SIM_ADDDMA*/
   SimCard.txbuffer = txData;
   SimCard.txsize = txSize;
   SimCard.rxbuffer = result;
   SimCard.recDataLen = 0;
#ifdef NoT0CTRL 
   SimCard.recsize = expSize;
   SimCard.txindex = 0;
   SimCard.INS = *(txData+1);
#endif   /*NoT0CTRL*/
#endif/*SIM_ADDDMA*/

#ifndef NoT0CTRL
   INS = (kal_uint16)*(txData+1);
   SIM_SetIMP3(*(txData+4));
   SimCard.cmdState = SIM_WaitCmdEnd;
#endif   /*NoT0CTRL*/
   
#ifdef SIM_ADDDMA   
   for(index=0;index<5;index++)
   {
      DRV_WriteReg(SIM_DATA,*(txData+index));
   }
   //DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);
   
   //#if ( (defined(MT6205)) || (defined(MT6205B)) )
   #if defined(DRV_SIM_MT6205B_SERIES)
      DMA2_Stop();
   #else /*!MT6205, MT6205B*/
      DMA_Stop(sim_dmaport);
   #endif   /*MT6205, MT6205B*/
   SIM_SetRXTIDE(1);
   if (expSize == 0)
   {
      #if defined(SIM_DEBUG_INFO)
		kal_print("SIM TX");
	  #endif
	  
      SIM_SetTXTIDE(0);
      //#if ( defined(MT6205) || defined(MT6205B) )
      #if defined(DRV_SIM_MT6205B_SERIES)
         SIM_DMAIni(KAL_TRUE); //Transmit
         DMA2_Init((txaddr+5),SIM_DATA,txSize-5,NULL);
         /*DMA2_Start();*/
      //#elif defined(MT6218B)
      #elif defined(DRV_SIM_DMA_6218B)
         sim_menu.source  = (kal_uint32)(txaddr+5);  /*1*/
         sim_menu.destination = SIM_DATA;
         sim_input.type = DMA_HWTX; /*2*/
         sim_input.count = txSize-5;       /*3*/
			if(sim_input.count > SIM_TX_DELAY_LEN && SimCard.Speed > Speed372 
				&& SimCard.is_err)
				txDelay = KAL_TRUE;			
         sim_input.callback = NULL;   /*4*/
      #else /*MT6218, MT6219, MT6217, MT6226, MT6227, MT6228, MT6229*/
         sim_menu.addr = (kal_uint32)(txaddr+5);  /*1*/
         sim_input.type = DMA_HWTX; /*2*/
         sim_input.count = txSize-5;       /*3*/
			if(sim_input.count > SIM_TX_DELAY_LEN && SimCard.Speed > Speed372)
				txDelay = KAL_TRUE;
         sim_input.callback = NULL;   /*4*/
         /*DMA_Config(sim_dmaport, &sim_input, KAL_TRUE);     */
      #endif

      INS |= SIM_INS_INSD;
   }
   else
   {
      #if defined(SIM_DEBUG_INFO)
	  kal_print("SIM RX");
	  #endif
	  
      SIM_SetTXTIDE(0xffff);
      
      //#if ( defined(MT6205) || defined(MT6205B) )
      #if defined(DRV_SIM_MT6205B_SERIES)
         SIM_DMAIni(KAL_FALSE); //Receive
         DMA2_Init(SIM_DATA,rxaddr,expSize,NULL);
         /*DMA2_Start();*/
      //#elif defined(MT6218B)
      #elif defined(DRV_SIM_DMA_6218B)
         sim_menu.source  = SIM_DATA;                 /*1*/
 			sim_menu.destination = (kal_uint32)(rxaddr);
         sim_input.type = DMA_HWRX; /*2*/
         sim_input.count = expSize;       /*3*/
         sim_input.callback = NULL;   /*4*/
      #else /*MT6218, MT6219, MT6217, MT6226, MT6227, MT6228, MT6229*/
         sim_menu.addr = (kal_uint32)(rxaddr);  /*1*/
         sim_input.type = DMA_HWRX; /*2*/
         sim_input.count = expSize;       /*3*/
         sim_input.callback = NULL;   /*4*/
         /*DMA_Config(sim_dmaport, &sim_input, KAL_TRUE);  */
      #endif
   }
   temp = DRV_Reg(SIM_STS);
   DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDDMANormal);
#else /*SIM_ADDDMA*/
#ifdef NoT0CTRL
   for(index=0;index<5;index++)
   {
      DRV_WriteReg(SIM_DATA,*(txData+index));
   }
   SimCard.txindex = 5;
   SimCard.cmdState = SIM_WaitProcByte;
   
   if (expSize == 0) //Transmit
   {
      if (txSize == 5)
      {
         SIM_SetRXTIDE(2);
      }
      else
      {
         SIM_SetRXTIDE(1);
      }
   }
   else
   {
      if ((expSize+3) > 15)
      {
         SIM_SetRXTIDE(CMD_RECBUFSIZE-8);
      }
      else
      {
         SIM_SetRXTIDE(expSize+3);
      }
   }
   temp = DRV_Reg(SIM_STS);
   DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
#else /*NoT0CTRL*/
   if(txSize <= 15)
   {
      for(index=0;index<txSize;index++)
      {
         DRV_WriteReg(SIM_DATA,*(txData+index));
      }
      SimCard.txindex = txSize;
      temp = DRV_Reg(SIM_STS);
      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
   }
   else
   {
      for(index=0;index<15;index++)
      {
         DRV_WriteReg(SIM_DATA,*(txData+index));
      }
      SimCard.txindex = 15;
      SIM_SetTXTIDE(0);
      temp = DRV_Reg(SIM_STS);
      DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_CMDNormal|SIM_IRQEN_TX));
   }
  
   if (expSize > 0)
   {
      if (expSize > 15)
      {
         SIM_SetRXTIDE(CMD_RECBUFSIZE);
      }
      else
      {
         SIM_SetRXTIDE(expSize);
      }
      /* maybe changed for 64k rate */
   }
   else
   {
      INS |= SIM_INS_INSD;
   }
#endif /*NoT0CTRL*/
#endif/*SIM_ADDDMA*/

#ifdef SIM_ADDDMA
   //#if ( defined(MT6205) || defined(MT6205B) )
   #if defined(DRV_SIM_MT6205B_SERIES)
      //DMA2_Start();
   //#elif defined(MT6218B)
   #elif defined(DRV_SIM_DMA_6218B)
      DMA_FullSize_Config(sim_dmaport, &sim_input, KAL_FALSE);
   #else /*MT6218, MT6219, MT6217, MT6226, MT6227, MT6228, MT6229*/
      DMA_Config(sim_dmaport, &sim_input, KAL_FALSE);
   #endif
#endif   /*SIM_ADDDMA*/

	{
		extern void DMA_Run(kal_uint8 channel);


		if(txDelay == KAL_FALSE)
			savedMask = SaveAndSetIRQMask();
#ifndef    NoT0CTRL
		SIM_SetCmdINS(INS);
#endif   /*NoT0CTRL*/

#ifdef SIM_ADDDMA
	/* add delay(1ms) between ACK and first transmit data for enhance speed card */
	//#if ( defined(MT6205) || defined(MT6205B) )
	//#elif defined(MT6218B)
	#if defined(DRV_SIM_MT6205B_SERIES)|| defined(DRV_SIM_MT6208_SERIES)
	#elif defined(DRV_SIM_DMA_6218B) 
	if(txDelay == KAL_TRUE)
	{
		kal_uint32 i,j;
		
		i = SIM_TX_DELAY_LOOP;
		j = SIM_TX_DELAY_LOOP*10;
		while(j--)
		{
			if(DRV_Reg(SIM_STATUS)&(SIM_STATUS_ACK|SIM_STATUS_NACK))
				break;
		}			
		while(i--);
	}			
	#else	
	if(txDelay == KAL_TRUE)
	{
		volatile kal_uint32 t1,t2;
		kal_uint32 loop = SIM_TX_DELAY_LOOP*10;
		
		while(loop--)
		{
			if(DRV_Reg(SIM_STATUS)&(SIM_STATUS_ACK|SIM_STATUS_NACK))
				break;
		}			
		t1 = SIM_GetCurrentTime();
		do{
		t2 = SIM_GetCurrentTime(); 	
		}while(SIM_GetDurationTick(t1,t2) < 32);
	}		
	#endif

	//#if ( defined(MT6205) || defined(MT6205B) )
	#if defined(DRV_SIM_MT6205B_SERIES)
	DMA2_Start();
	#else	
	DMA_Run(sim_dmaport);	
	#endif
#endif   /*SIM_ADDDMA*/

		if(txDelay == KAL_FALSE ){	
			RestoreIRQMask(savedMask);
			if(0 == savedMask)
				kal_print("[SIM]:savedMask == 0");
		}
	}

   DRV_Reg(SIM_CONF) |= SIM_CONF_TOUTEN;   
   SIM_WaitEvent(SimCard,CMD_END);

#ifdef SIM_ADDDMA
   //#if ( defined(MT6205) || defined(MT6205B) )
   #if defined(DRV_SIM_MT6205B_SERIES)
      DMA2_Stop();
   #else /*MT6218, MT6218B, MT6219, MT6217, MT6226, MT6227, MT6228, MT6229*/
      DMA_Stop(sim_dmaport);
   #endif
#endif   /*SIM_ADDDMA*/
   
#ifdef NoT0CTRL
   SimCard.initialPower = SimCard.cmdState;
   SimCard.cmdState = SIMD_CmdIdle;
#endif   /*NoT0CTRL*/
   
   if (SimCard.result == SIM_SUCCESS && SimCard.recDataErr == KAL_FALSE)
   {
    #ifdef  SIM_ADDDMA
    if(expSize != 0) 
       *rcvSize = expSize - DRV_Reg(SIM_IMP3);
   //DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);
    #else /*SIM_ADDDMA*/
   *rcvSize = SimCard.recDataLen;
    #endif /*SIM_ADDDMA*/
   
   #if defined(SIM_DEBUG_INFO)
   kal_print("SIM_SUCCESS");
   #endif
   
      #ifdef NoT0CTRL
      SW = (SimCard.SW2 | (SimCard.SW1 << 8));
      #else /*NoT0CTRL*/
      SIM_ObtainSW(SW);
      #endif   /*NoT0CTRL*/
      //dbg_print("SW=%x\r\n",SW);
      /*for clock stop mode*/
      if(SimCard.clkStop == KAL_TRUE)
      {
         SIM_DisAllIntr();
         DRV_Reg(SIM_CONF) &= ~SIM_CONF_TOUTEN;
         SIM_SetTOUT(ClkStopTimeTable[SimCard.Speed][1]*TOUT_Factor);
         DRV_Reg(SIM_CONF) |= SIM_CONF_TOUTEN;
         SimCard.cmdState = SIM_StopClk;
         DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_TOUT);
      }
      return SW;
   }
   else
   {
   	kal_sprintf(sim_dbg_str,"[SIM]:SIM_CMD fail status=%d", SimCard.result);
   	kal_print(sim_dbg_str);
      //SimCard.recDataErr = KAL_FALSE;
		SimCard.is_err = KAL_TRUE;
      *Error = KAL_TRUE;
      return 0;
   }
}

/*
* FUNCTION
*	L1sim_Enable_Enhanced_Speed
*
* DESCRIPTION                                                           
*   	The function must call before L1sim_Reset. Otherwise, enhance speed is disable.
*     This function can enable enhance speed mode or not.
*
* CALLS  
*
* PARAMETERS
*	enable: KAL_TRUE: enable enhanced speed. KAL_FALSE: disable it.
*
* RETURNS
*	NULL
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Enable_Enhanced_Speed(kal_bool enable)
{
   PTS_check = enable;
}
void L1sim_Enable_Enhanced_Speed_2(kal_bool enable)   // nick
{
   PTS_check = enable;
}

/*
* FUNCTION                                                            
*	L1sim_Cmd
*
* DESCRIPTION                                                           
*   	The function is used to implement re-try command mechanism.
*
* CALLS  
*
* PARAMETERS
*	txData: Pointer to the transmitted command and data.
*	txSize:	The size of the transmitted command and data from AL to driver.
*	expSize: The size of expected data from SIM
*	result: Pointer to received data 
* 	rcvSize: Pointer to the size of data received
*	parityError: 1 (parity error) or 0(no parity error)
*
* RETURNS
*	status(high byte:sw1 low byte: sw2)
*
* GLOBALS AFFECTED
*   external_global
*/
sim_card_speed_type L1sim_Get_CardSpeedType_2(void)
{}

sim_card_speed_type L1sim_Get_CardSpeedType(void)
{
   return SimCard.sim_card_speed;
}

/*
* FUNCTION                                                            
*	L1sim_Cmd
*
* DESCRIPTION                                                           
*   	The function is used to implement re-try command mechanism.
*
* CALLS  
*
* PARAMETERS
*	txData: Pointer to the transmitted command and data.
*	txSize:	The size of the transmitted command and data from AL to driver.
*	expSize: The size of expected data from SIM
*	result: Pointer to received data 
* 	rcvSize: Pointer to the size of data received
*	parityError: 1 (parity error) or 0(no parity error)
*
* RETURNS
*	status(high byte:sw1 low byte: sw2)
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint16 L1sim_Cmd_2(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error)
{}

kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error)
{
   kal_uint8 index;
   kal_uint16 SW;

   #if defined(SIM_DEBUG_INFO)
   kal_sprintf(sim_dbg_str,"L1sim_Cmd(1) txSize=%d, rcvSize=%d", txSize, *rcvSize);
   kal_print(sim_dbg_str);
	#endif
	
   if (SimCard.State != SIM_PROCESSCMD)
   {
      *Error = KAL_TRUE;
      return 0;
   }   
   // while encounter physical errors, deactivate the SIM immediately
   for(index=0;index<3;index++)
   {
   	SimCard.timeout = KAL_FALSE;
      SW = SIM_CMD(txData,txSize,result,rcvSize,Error);
      
      #if defined(SIM_DEBUG_INFO)
      kal_sprintf(sim_dbg_str,"L1sim_Cmd(2) txSize=%d, rcvSize=%d, fifo: %d", txSize, *rcvSize, DRV_Reg(SIM_COUNT));
      kal_print(sim_dbg_str);
      #endif
      
      #if defined(__USIM_DRV__)
		if(SimCard.timeout && SimCard.app_proto == USIM_PROTOCOL)
		{
		   /*SimCard.timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave*/
		   SimCard.timeout = KAL_FALSE;
			L1sim_PowerOff();	
			return SW;
		}
		#endif
      if (*Error == 0)
         break;
   }
   
   if ( ((SW&0xf000) != 0x6000) && ((SW&0xf000) != 0x9000) )
   {
      *Error = KAL_TRUE;
   }
   
   if(*Error)
   {
		kal_sprintf(sim_dbg_str,"[SIM]:SIM_CMD fail result=%d, status=%x", SimCard.result, SW);
		kal_print(sim_dbg_str);
		kal_sprintf(sim_dbg_str,"[SIM]: recDataErr=%d, timeout=%d, cmdState=%d, event_state=%d, EvtFlag=%d, clkStop=%d, app_proto=%d",
			SimCard.recDataErr, SimCard.timeout, SimCard.cmdState, SimCard.event_state, 
			SimCard.EvtFlag, SimCard.clkStop, SimCard.app_proto);
		kal_print(sim_dbg_str);	
	}				
   /*SimCard.timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave*/
   SimCard.timeout = KAL_FALSE;
   return SW;
}

//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
void SIM_BaudDMA_START(void)
{
   if ( (SimCard.Speed == Speed372) && (INT_ecoVersion() < GN) )
   {
      dma_ch1_start((kal_uint32)baud_data);
   }
}
#endif   /*MT6218B*/
/*
* FUNCTION                                                            
*	L1sim_Init
*
* DESCRIPTION                                                           
*   	The function L1sim_Init initialize the SIM driver.
*
* CALLS  
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Init(void)		//Validate
{
	kal_uint16 tmp;
	SimCard.SIM_ENV = SIM_GetCurrentEnv();
	if (SimCard.SIM_ENV == ME_30V_ONLY)
	{
	   SimCard.Power = SIM_30V;
	}
	else
	{
	   SimCard.Power = SIM_18V;
	}

	SimCard.Data_format = SIM_direct;
	SimCard.State = SIM_WAIT_FOR_ATR;
	SimCard.clkStop = KAL_FALSE;
	SimCard.Speed = Speed372;

//#if (defined(MT6218B))
#if defined(DRV_SIM_DMA_6218B)
   #ifdef SIM_ADDDMA
      if (sim_dmaport == 0)
      {
         kal_uint16 baud_index;
         if (INT_ecoVersion() < GN)
         {
            for(baud_index=0;baud_index<640;baud_index++)
            {
               if (((baud_index+1)&3)!=0)
                  baud_data[baud_index] = (SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372);
               else
                  baud_data[baud_index] = (SIM_BRR_CLK_Div4 | (0x17<<2));
            }
            dma_ch1_init(SIM_BRR,sizeof(baud_data), 0xb9);
         }
         sim_dmaport = DMA_FullSize_GetChannel(DMA_SIM);         
      }
      
      sim_menu.TMOD.burst_mode = 0;
      sim_menu.master = DMA_SIM;
      sim_menu.source = NULL;      /*1*/
      sim_menu.destination = NULL;
      
      sim_input.type = DMA_HWTX; /*2*/
      sim_input.size = DMA_BYTE;
      sim_input.menu = &sim_menu;
      sim_input.count = 0;       /*3*/
      sim_input.callback = NULL;   /*4*/
   #endif   /*SIM_ADDDMA*/
//#elif ( (!defined(MT6205)) && (!defined(MT6205B)) )
   #elif !defined(DRV_SIM_MT6205B_SERIES)
   /*MT6218,MT6219,MT6217, MT6226, MT6227, MT6228, MT6229*/
   #ifdef SIM_ADDDMA
      if (sim_dmaport == 0)
         sim_dmaport = DMA_GetChannel(DMA_SIM);
      
      sim_menu.TMOD.burst_mode = 0;
      sim_menu.master = DMA_SIM;
      sim_menu.addr = NULL;  /*1*/
      
      sim_input.type = DMA_HWTX; /*2*/
      sim_input.size = DMA_BYTE;
      sim_input.menu = &sim_menu;
      sim_input.count = 0;       /*3*/
      sim_input.callback = NULL;   /*4*/
   #endif   /*SIM_ADDDMA*/
#endif

	tmp = DRV_Reg(SIM_STS);

	if (SimCard.event == NULL)
	   SimCard.event = kal_create_event_group("SIMEVT");

   DRV_Register_HISR(DRV_SIM_HISR_ID, SIM_HISR);
   IRQ_Register_LISR(IRQ_SIM_CODE, SIM_LISR,"SIM handler");

	IRQSensitivity(IRQ_SIM_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_SIM_CODE);
}
#endif
//================================ Layer type SIM driver start ==================================
/*************************************************************************
* FUNCTION
*  L1sim_Cmd_Layer
*
* DESCRIPTION
*	Layer type sim driver (transport layer) which maps C-APDU into C-TPDU for T=0
*
* PARAMETERS
*	txData:	address of the tx buffer including the command header and optional tx data
*	txSize:	size of data to be transfer including command buffer(5 bytes):(Lc+5) and 
				will be updated by real transfered data count.
*	rxData:	address of the rx buffer 
*	rxSize:	expect received data size not including the sw1 and sw2 and will be updataed 
				by the real received data coung
*
* RETURNS
*  kal_uint16: status bytes of (sw1<<8|sw2), and 0 to indicate a physical error detected
					by the driver such as timeout.
*
* GLOBALS AFFECTED
*
*************************************************************************/
sim_status L1sim_Cmd_Layer(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize)
{
	kal_bool warn, case4, sim_card;
	kal_uint8 sw1, sw2, error, gp, rs, *tx;	
   kal_uint8 sim_get_resp_sim[] = {0xa0, 0xc0, 0x00, 0x00, 0x00 }; // 0xa0: SIM, 0x00: USIM	
	sim_status status, status_w = 0;
	kal_uint32 rx_len,rx_buf_len;
	// sim_protocol_app_enum p = SimCard.app_proto;

	dbg_print("L1sim_Cmd_Layer\r\n");
	if(rxData != NULL && *rxSize ==0)
	   rx_buf_len = 256;
	else
	   rx_buf_len = *rxSize;
	if(SimCard.cmd_case == usim_case_4)
	{
		case4 = KAL_TRUE;
		*txSize -= 1;
		*rxSize = 0;
	}
	else
		case4 = KAL_FALSE;
	tx = txData;
	status = L1sim_Cmd(tx, (kal_uint16)*txSize, rxData, (kal_uint16*)rxSize, &error);
	rx_len = *rxSize;
	rxData += *rxSize;
	rs = SW1_RESEND_USIM;
	//if(SIM_PROTOCOL == p)
	if(txData[0] == 0xA0)  // some usim will compatiable with SIM after received 0xa0....
	{
		gp = SW1_GET_RESP_SIM;
		sim_get_resp_sim[0] = GET_RESP_CLA_SIM;
		sim_card = KAL_TRUE;
	}
	else
	{	// USIM_PROTOCOL (0x61 and 0x6c are only for case2 and case4
		gp = SW1_GET_RESP_USIM;
		sim_get_resp_sim[0] = GET_RESP_CLA_USIM;
		sim_card = KAL_FALSE;
	}	
	warn = KAL_FALSE;
	for(;;)
	{
		if(error == KAL_TRUE)
			return STATUS_FAIL;
		sw1 = status>>8;
		sw2 = status&0xff;
		if(sw1 == gp)
		{	// get response  0x61
			dbg_print("get response  %x \r\n", sw1);
			if(rxData == NULL)
			{
				dbg_print("!!! ERR  NULL rx buffer \r\n");
				return status;
			}
			tx = sim_get_resp_sim;
			if( sw2 > (rx_buf_len - rx_len))
				sw2 = (rx_buf_len - rx_len);
			*rxSize = sw2;
			tx[LEN_INDEX] = sw2;
			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error);
			if(error == KAL_TRUE)
				return STATUS_FAIL;
			if(sim_card)
				break;
			else
			{
				rx_len += *rxSize;
				ASSERT(rx_len <= rx_buf_len);
				rxData += *rxSize;

			}
			
		}
		else if(!sim_card && sw1 == rs)
		{	// resend the previous cmd 0x6c
			dbg_print("resend  command %x \r\n", sw1);
			if(rxData == NULL)
			{
				dbg_print("!!! ERR NULL rx buffer");
				return status;
			}
			tx[LEN_INDEX] = sw2;
			*rxSize = sw2;
			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error);
		}
		else if(!sim_card && case4 && 
			(sw1 == SW1_WARN1 || sw1== SW1_WARN2|| (status != STATUS_OK && (sw1&0xf0 == 0x90))))
		{	// warning status
			dbg_print("warning status %x \r\n", sw1);
			warn = KAL_TRUE;
			status_w = status;
			tx = sim_get_resp_sim;
			tx[LEN_INDEX] = 0;
			*rxSize = 0;
			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error);
			if(error == KAL_TRUE)
				return STATUS_FAIL;
			else
			{
				rx_len += *rxSize;
				ASSERT(rx_len <= rx_buf_len);				
				rxData += *rxSize;
			}			
		}
		else
		{	// command complete
			dbg_print("command complete %x \r\n", status);
			ASSERT(rx_len <= rx_buf_len);
			if(warn == KAL_TRUE)
				return status_w;
			return status;
		}		
	}	
	
	return status;
}
//================================ Layer type SIM driver end ==================================

//================================SIM test code==================================
#ifdef DEVDRV_TEST
kal_uint8 Volt;
kal_uint8 resVolt;
AtrStruct ATRInfo;

#if 1
void PinCheck(kal_uint8 *inputdata,kal_uint16 *res)
{
	kal_uint8 cmd[50],j;
	kal_uint16 rec;
	kal_uint16 SW;
	kal_uint8 parity_err;
	
	cmd[0]= 0xa0;
	cmd[1]= 0x20;
	cmd[2]= 0x0;
	cmd[3]= 0x01;
	cmd[4]= 0x08;
	for (j=0;j<8;j++)
	{
		cmd[j+5]= *(inputdata+j);
	}
	
	//SIM_Command(&sim_cmd);
	rec = 0;
	SW = L1sim_Cmd(cmd,13,NULL,&rec, &parity_err);
	if (parity_err)
	{
		//////dbg_print("Parity Error\r\n");
	}
	//////dbg_print("PinCheck SW=%x\r\n",SW);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}


void SelectFile(kal_uint8 *inputdata,kal_uint16 *res)
{
	kal_uint8 cmd[50];
	kal_uint16 rec;
	kal_uint8 parity_err;
	kal_uint16 SW;
	
	cmd[0]= 0xa0;
	cmd[1]= 0xa4;
	cmd[2]= 0x0;
	cmd[3]= 0x0;
	cmd[4]= 0x02;
	
	cmd[5]= *inputdata;
	cmd[6]= *(inputdata+1);
		
	//SIM_Command(&sim_cmd);
	rec = 0;
	SW = L1sim_Cmd(cmd,7,NULL,&rec, &parity_err);
	if (parity_err)
	{
		//////dbg_print("Parity Error\r\n");
	}
	*res = (kal_uint8)(SW >> 8);
	*(res+1) = (kal_uint8)SW;
	//////dbg_print("SelectFile SW=%x\r\n",SW);

	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	//////dbg_print("Select File cmd is ok\r\n");
}

void GetResponse(kal_uint8 len, kal_uint16 *res)
{
	kal_uint8 cmd[50];
	kal_uint16 i;
	kal_uint16 rec;
	kal_uint8 resp[50];
	kal_uint16 SW;
	kal_uint8 parity_err;

	cmd[0]= 0xa0;
	cmd[1]= 0xc0;
	cmd[2]= 0x0;
	cmd[3]= 0x0;
	cmd[4]= len;
		
	//SIM_Command(&sim_cmd);
	rec = len;
	SW = L1sim_Cmd(cmd,5,(kal_uint8 *)resp,&rec, &parity_err);
	for(i=0;i<rec;i++)
	{
		res[i] = (kal_uint16)resp[i];
	}
	*(res+rec) = (kal_uint8)(SW >> 8);
	*(res+rec+1) = (kal_uint8)SW;
	if (parity_err)
	{
		//////dbg_print("Parity Error\r\n");
	}
	
	//////dbg_print("GetResponse SW=%x\r\n",SW);
	
	//////dbg_print("the voltage value=%x\r\n",res[13]);
}

void ReadBinary(kal_uint8 len, kal_uint16 *res)
{
	kal_uint8 cmd[50];
	kal_uint16 i;
	kal_uint16 rec;
	kal_uint8 resp[50];
	kal_uint16 SW;
	kal_uint8 parity_err;

	cmd[0]= 0xa0;
	cmd[1]= 0xb0;
	cmd[2]= 0x0;
	cmd[3]= 0x0;
	cmd[4]= len;
		
	//SIM_Command(&sim_cmd);
	rec = len;
	SW = L1sim_Cmd(cmd,5,(kal_uint8 *)resp,&rec, &parity_err);
	for(i=0;i<rec;i++)
	{
		res[i] = (kal_uint16)resp[i];
	}
	*(res+rec) = (kal_uint8)(SW >> 8);
	*(res+rec+1) = (kal_uint8)SW;
	if (parity_err)
	{
		//////dbg_print("Parity Error\r\n");
	}
	//////dbg_print("ReadBinary SW=%x\r\n",SW);
	
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	//////dbg_print("Read Binary cmd is ok\r\n");
	//////dbg_print("the read data [14]=%x\r\n",res[13]);	
}


kal_bool vcc_check(void)
{
	kal_uint8 cmd[50];
	kal_uint16 resp[300];
	kal_uint16 temp;

	#if 1
//	GetResponse(20,resp);
//	GetResponse(20,resp);
//	cmd[0]= 0x7f;
//	cmd[1]= 0x20;
//	SelectFile(cmd,resp);
	cmd[0]= 0x7f;
	cmd[1]= 0x20;
	SelectFile(cmd,resp);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	//////dbg_print("rec length=%d\r\n",*(resp+1));
	GetResponse(*(resp+1),resp);
	temp = resp[13] & 0x000d;
	
	SimCard.clkStop = KAL_TRUE;
	
	if (temp & 0x0001)
	{
		if ((temp & 0x0004)!=0)
		{
			SimCard.clkStopLevel = KAL_TRUE;	//bit 3
		}
		
		if ((temp & 0x0008)!=0)		//bit 4
		{
			SimCard.clkStopLevel = KAL_FALSE;
		}
	
		if ((temp & 0x000c) == 0)	//default
		{
			SimCard.clkStopLevel = KAL_FALSE;
		}
	}
	else
	{
		if ((temp & 0x0004)!=0)
		{
			SimCard.clkStopLevel = KAL_TRUE;	//bit 3
		}
		
		if ((temp & 0x0008)!=0)		//bit 4
		{
			SimCard.clkStopLevel = KAL_FALSE;
		}
	
		if ((temp & 0x000c) == 0)	//default
		{
			SimCard.clkStopLevel = KAL_FALSE;
		}
	}
	temp = resp[13] & 0x000d;
	if (temp == 0)
	{
		SimCard.clkStop = KAL_FALSE;
		////////dbg_print("fasfda&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\r\n");
	}
	
	temp = resp[13] & 0x0070;
	temp >>= 4;
	//////dbg_print("the volt=%d\r\n",temp);
	if ( temp == 1)	//3V card
	{
		if (SimCard.Power == SIM_18V)
		{
			//////dbg_print("3V reset\r\n");
			L1sim_Reset(SIM_30V,NULL,NULL);
			//return SimCard.result;
		}
	}
	if (temp == 0)	//5V card
	{
		if (SimCard.Power == SIM_30V)
		{
			//////dbg_print("5V reset\r\n");
			L1sim_Reset(SIM_18V,NULL,NULL);	
			//return SimCard.result;
		}
	}
	#endif
	//#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) ) 
	#if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
	if (SimCard.clkStop == KAL_TRUE)
	{
      DRV_Reg(SIM_CONF) |= SIM_CONF_HALTEN;	   
	}
	#endif   /*MT6205,MT6205B,MT6218*/
	
	return KAL_TRUE;
}

void CheckPinCMD(void)
{
	kal_uint8 cmd[50];
	kal_uint16 resp[300];
	
	//1
	cmd[0]= 0x7f;
	cmd[1]= 0x20;
	SelectFile(cmd,resp);

	//2
	GetResponse(*(resp+1),resp);
	
	//3
	cmd[0]= 0x6f;
	cmd[1]= 0xae;
	SelectFile(cmd,resp);
	GetResponse(*(resp+1),resp);	//GD
	
	//4
	ReadBinary(1,resp);
	
	//5
	cmd[0]= 0x3f;
	cmd[1]= 0x00;
	SelectFile(cmd,resp);
	
	//6
	cmd[0]= 0x2f;
	cmd[1]= 0xe2;
	SelectFile(cmd,resp);
	
	//7
	ReadBinary(10,resp);
	
	//8
	cmd[0]= 0x7f;
	cmd[1]= 0x20;
	SelectFile(cmd,resp);
	
	//9
	cmd[0]= 0x6f;
	cmd[1]= 0x05;
	SelectFile(cmd,resp);
	
	//10
	GetResponse(*(resp+1),resp);
	
	#if 1
	//11
	ReadBinary(5,resp);
	#endif
	
	//12
	cmd[0]= 0x6f;
	cmd[1]= 0x39;
	SelectFile(cmd,resp);
	
	//13
	GetResponse(*(resp+1),resp);
	
	//14
	cmd[0]= 0x6f;
	cmd[1]= 0x37;
	SelectFile(cmd,resp);
	
	//15
	GetResponse(*(resp+1),resp);
	
	//16
	cmd[0]= 0x6f;
	cmd[1]= 0x41;
	SelectFile(cmd,resp);
	
	//17
	GetResponse(*(resp+1),resp);
	
	//18
	cmd[0]= 0x32;
	cmd[1]= 0x34;
	cmd[2]= 0x36;
	cmd[3]= 0x38;
	cmd[4]= 0xff;
	cmd[5]= 0xff;
	cmd[6]= 0xff;
	cmd[7]= 0xff;
	PinCheck(cmd,resp);
	
	//////dbg_print("Check PIN END..\r\n");
}

void closeSIMcmd(void)
{
	kal_uint8 cmd[50];
	kal_uint16 resp[300];
	
	cmd[0]= 0x6f;
	cmd[1]= 0x37;
	SelectFile(cmd,resp);
	
	GetResponse(*(resp+1),resp);
	
	cmd[0]= 0x6f;
	cmd[1]= 0x41;
	SelectFile(cmd,resp);
	
	GetResponse(*(resp+1),resp);
	SIM_Reject();
}

#endif

void Sim_test(void)
{
	kal_uint8 result;
	#ifdef MT6238
	int i;
	/*
		I haven't finish 2 SIM interface driver, in MT6238 DVT, we build 2 loads for 2 SIM controller test
		In MT6238 burning test load, we have to toggle 2 SIM controller in one load, just hardcore ask SIM controller 2 to do reset SIM
	*/
	/*turn on power*/
	DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_SIM2,PDN_SIM);
	/*ask SIM2 controller to activation SIM*/
	DRV_Reg(0x81130000) |= SIM_CTRL_SIMON;

	for(i=0;i<40000;i++);

	/*do deactivation*/
	DRV_Reg(0x81130000) &= ~(SIM_CTRL_SIMON);
	
	#endif
	result = L1sim_Reset(SIM_30V,&resVolt,&ATRInfo);
	if (result == SIM_NO_ERROR)
	{
		//dbg_print("SIM has no Error!\r\n");
	}
	if (result == SIM_CARD_ERROR)
	{
		//dbg_print("SIM CARD has something error!\r\n");
		return;
	}
	
	if (result == SIM_NO_INSERT)
	{
		//dbg_print("SIM CARD no insert!\r\n");
		return;
	}
	//dbg_print("the resVolt=%x\r\n",resVolt);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
		#if 1
		if (vcc_check())
		{
			//dbg_print("VCC check is ok\r\n");
		//	break;
		}
		else
		{
			//dbg_print("VCC check is Failed\r\n");
		}
		#endif
		//return;
		CheckPinCMD();
		//////dbg_print("=========================================\r\n");
		#if 1
		//////dbg_print("Will be close the sim!!\r\n");
		//delay1s(50);
		closeSIMcmd();
		//SIM_Reject();
		//dbg_print("SIM is closed!!\r\n");
		#endif
}
#endif /* DEVDRV_TEST */
#endif // DRV_MULTIPLE_SIM
#else /*MT6208, FPGA only*/

#include "pwic.h"

static kal_uint16 TOUTValue = 0x260;
static kal_uint8 TOUT_Factor=1;
/*Maybe changed when the unit of the HW TOUT counter is changed!!*/
const kal_uint8  ClkStopTimeTable[3][2]={  {0,1},
                                       {1,2},
                                       {2,4}
                                    };
Sim_Card SimCard;
kal_uint8 reset_index;
kal_uint8 PTS_data[4];
static kal_bool PTS_check = KAL_FALSE;

void SIM_SetRXTIDE(kal_uint16 RXTIDE)
{
   kal_uint16 TIDE;
   TIDE = DRV_Reg(SIM_TIDE);
   TIDE &= ~SIM_TIDE_RXMASK;
   TIDE |= (RXTIDE-1);
   DRV_WriteReg(SIM_TIDE,TIDE);
}

void SIM_SetTXTIDE(kal_uint16 _TXTIDE)
{
   kal_uint16 TIDE;
   TIDE = DRV_Reg(SIM_TIDE);
   TIDE &= ~SIM_TIDE_TXMASK;
   TIDE |= ((_TXTIDE+1) <<8);
   DRV_WriteReg(SIM_TIDE,TIDE);
}

kal_uint8 SIM_CheckSW(kal_uint16 ACK)
{
   if ((ACK & 0x00f0) == 0x0060)
         return KAL_TRUE;
   if ((ACK & 0x00f0) == 0x0090)
      return KAL_TRUE;
   
   return KAL_FALSE;
}

kal_bool SIM_ResetNoATR(kal_uint8 pow)   //For normal case reset
{
   //Only enable SIM interrupt
   SimCard.State = SIM_WAIT_FOR_ATR;
   reset_index = 0;
   SimCard.Power = pow;

   //Deactivate the SIM card
   SIM_L1Reset();
   
   SIM_WaitEvent(SimCard,RST_READY);
   if (SimCard.result == SIM_SUCCESS)
   {
      return KAL_TRUE;
   }
   else
   {
      return KAL_FALSE;
   }
}

void SIM_Initialize(kal_uint8 format, kal_uint8 power)
{
   kal_uint16 tmp;
   kal_uint16 Conf;
   
   SimCard.Data_format = format;
   SimCard.Power = power;
   
   //Setup the SIM control module, SIM_BRR, SIM_CONF
   //Set SIMCLK = 13M/4, and BAUD RATE = default value(F=372,D=1);
   DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372));

   if (format != SIM_direct)
   {  
      Conf = SIM_CONF_InDirect;
   }
   else
   {
      Conf = SIM_CONF_Direct;
   }
   
   #ifdef PMIC_VSIM_SEL
   if (power == SIM_30V)
      pmic_adpt_set_vsim(PMIC_VSIM_3_0);
   else
      pmic_adpt_set_vsim(PMIC_VSIM_1_8);
   #elif !defined(PMIC_PRESENT)
	if (power != SIM_30V)
	{
		Conf |= SIM_CONF_SIMSEL;
	}
	#else /*Phone setting*/
	if (power == SIM_30V)
	{
		Conf |= SIM_CONF_SIMSEL;
	}
	#endif   /*Phone setting*/
	
   DRV_WriteReg(SIM_CONF,Conf);
      
   SIM_SetRXRetry(0);
   SIM_SetTXRetry(0);

   //Set the ATRTout as 9600etu
   SIM_SetTOUT(TOUTValue);
   
   // reset interrupts, flush rx, tx fifo
   SIM_FIFO_Flush();
      
   //Set the txfifo and rxfifo tide mark
   SIM_SetRXTIDE(1);
   
   //Read Interrupt Status
   tmp = DRV_Reg(SIM_STS);
   
   //Enable Interrupt
   DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);

   SimCard.recDataErr = KAL_FALSE;
   //activate the SIM card, and activate the SIMCLK
   SIM_Active();
   ////dbg_print("SIM ACtive\r\n");
}

kal_bool SIM_PTSProcess(kal_uint8 *TxBuffaddr, kal_uint8 Txlength)   //Bool lalasun
{
   kal_uint8    index;
   kal_uint8    tmp;
   
   for (index = 0; index < Txlength; index++)
   {
      PTS_data[index]=0;
      tmp = *(TxBuffaddr+index);
      DRV_WriteReg(SIM_DATA,tmp);
   }

   SimCard.State = SIM_PROCESS_PTS;

   SIM_SetRXTIDE(Txlength);
   DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
   
   SIM_WaitEvent(SimCard,PTS_END);
   
   if ((SimCard.recDataErr == KAL_TRUE) 
      || (SimCard.result == SIM_INIPTSERR))
   {
      SimCard.recDataErr = KAL_FALSE;
      return KAL_FALSE;
   }
   
   for (index = 0; index < Txlength; index++)
   {
      if (PTS_data[index]!=*(TxBuffaddr+index))
      {
         //////dbg_print("PPS is error\r\n");  
         return KAL_FALSE;
      }
   }
   return KAL_TRUE;
}

kal_bool SIM_ProcessATRData(void)
{
   kal_uint8 index;
   kal_uint16 tmp,tmp1;
   kal_uint16 SIM_BRR_REG;
   kal_uint8 ptsdata[4];
   kal_uint16 TOUT;
   kal_uint8 Dvalue = 1;
        
   SIM_WaitEvent(SimCard,ATR_END);
   
   if (SimCard.recDataErr == KAL_TRUE)
   {
      SimCard.recDataErr = KAL_FALSE;
      return KAL_FALSE;
   }
   
   index = 1;
   if (SimCard.recData[0] & 0x00f0)
   {
      if (SimCard.recData[0] & TAMask)
      {
         tmp = SimCard.recData[index]; //TA1
         index++;
         
         if ((tmp == 0x0011)||(tmp == 0x0001))
         {
            //Don't process ATR data!!
            SimCard.State = SIM_PROCESSCMD;
            SimCard.cmdState = SIMD_CmdIdle;
            return KAL_TRUE;
         }
         else
         {
            switch (tmp)
            {
               case 0x0094:      //F = 512,D=8
                  SimCard.sim_card_speed = sim_card_enhance_speed_64;
#if 1
                  if (!PTS_check)
#else
/* under construction !*/
#endif
                  {
                     Dvalue = 1;
                     ptsdata[0]=0xff;
					   	ptsdata[1]=0x00;
					   	ptsdata[2]=0xff;
					   	if (!SIM_PTSProcess(ptsdata,3))
					   	{
					   	   return KAL_FALSE;
					   	}
				      }
                  else
                  {
					   	Dvalue = 8;
					   	ptsdata[0]=0xff;
					   	ptsdata[1]=0x10;
					   	ptsdata[2]=0x94;
					   	ptsdata[3]=0x7b;
					   	SimCard.Speed = Speed64;
					   	if (!SIM_PTSProcess(ptsdata,4))
					   	{
					   	   return KAL_FALSE;
					   	}
					   	SIM_BRR_REG = DRV_Reg(SIM_BRR);
					   	SIM_BRR_REG &= SIM_BRR_CLKMSK;
					   	SIM_BRR_REG |= SIM_BRR_BAUD_Div64;
					   	DRV_Reg(SIM_BRR) = SIM_BRR_REG;

					   	TOUT_Factor = 8;
					   	TOUTValue = TOUT_Factor*TOUTValue;
					   	SIM_SetTOUT(TOUTValue);
                  }
                  break;
                     
               case 0x0095:      //F=512,D=16
                  SimCard.sim_card_speed = sim_card_enhance_speed_32;
#if 1
                  Dvalue = 1;
                  ptsdata[0]=0xff;
                  ptsdata[1]=0x00;
                  ptsdata[2]=0xff;
                  if (!SIM_PTSProcess(ptsdata,3))
                  {
                     return KAL_FALSE;
                  }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                  break;
               
               default:    //F=372,D=1
                  Dvalue = 1;
                  ptsdata[0]=0xff;
                  ptsdata[1]=0x00;
                  ptsdata[2]=0xff;
                  if (!SIM_PTSProcess(ptsdata,3))
                  {
                     return KAL_FALSE;
                  }
                  break;
            }
         }
      }  /*if (SimCard.recData[0] & TAMask)*/
            
      if (SimCard.recData[0] & TBMask)
      {
         tmp = SimCard.recData[index];
         ////dbg_print("TB1=%x\r\n",tmp);
         index++;
      }
      if (SimCard.recData[0] & TCMask)
      {
         tmp = SimCard.recData[index];
         ////dbg_print("TC1=%x\r\n",tmp);
         if (tmp != 0xff && tmp != 0x00)
         {
            return KAL_FALSE;
         }
         index++;
      }
      
      if (SimCard.recData[0] & TDMask)
      {
         tmp = SimCard.recData[index]; ///TD1
         index++;
         ////dbg_print("TD1=%x\r\n",tmp);
         if (tmp & TCMask) //TC2 is obtain
         {
            if (tmp & TAMask)
            {
               tmp1 = SimCard.recData[index];
               ////dbg_print("TA2=%x\r\n",tmp1);
               index++;
            }
            if (tmp & TBMask) 
            {
               tmp1 = SimCard.recData[index];
               ////dbg_print("TB2=%x\r\n",tmp1);
               index++;
            }
            if (tmp & TCMask) //TC2
            {
               tmp1 = SimCard.recData[index];
               ////dbg_print("TC2=%x\r\n",tmp1);
               TOUT = (kal_uint16)(60*Dvalue);
               TOUT = TOUT*tmp1;
               index++;
               TOUTValue = TOUT+2;
               //////dbg_print("TOUT=%x\r\n",TOUT);
               DRV_WriteReg(SIM_TOUT,TOUT);
            }                 
         }
      }  /*if (SimCard.recData[0] & TDMask)*/
   }/*if (SimCard.recData[0] & 0x00f0)*/
   SimCard.State = SIM_PROCESSCMD;
   
   SimCard.cmdState = SIMD_CmdIdle;

   return KAL_TRUE;
}

void SIM_Txhandler(void)
{
   kal_uint8 index;
   kal_uint16 reslen;
   reslen = SimCard.txsize - SimCard.txindex;
   if(reslen <= 15)
   {
      for(index=0;index<reslen;index++)
      {
         DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
         SimCard.txindex++;
      }
      SIM_SetRXTIDE(2);
      SimCard.cmdState = SIM_WaitProcByte;
      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
   }
   else
   {
      for(index=0;index<15;index++)
      {
         DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
         SimCard.txindex++;
      }
      SIM_SetTXTIDE(0);
      DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_Normal|SIM_IRQEN_TX));
   }
   return;
}

void SIM_Rxhandler(kal_uint16 sim_int)
{
   kal_uint16 TS;
   kal_uint8  index;
   
   if (SimCard.State == SIM_WAIT_FOR_ATR)
   {
      TS = DRV_Reg(SIM_DATA);
      
      if ((TS == 0x003f) || (TS == 0x003b))
      {
         SimCard.State = SIM_PROCESS_ATR;

         DRV_Reg(SIM_CONF) |= 
                  (SIM_CONF_TXHSK | SIM_CONF_RXHSK |SIM_CONF_TOUTEN);

         /* *(volatile kal_uint16 *)SIM_CONF |= SIM_CONF_TOUTEN; */
         SIM_SetRXTIDE(20);
         SIM_SetRXRetry(7);
         SIM_SetTXRetry(7);
         SimCard.recDataLen = 0;
         
         SIM_SetEvent(SimCard,SIM_SUCCESS);
         SimCard.EvtFlag = ATR_END;
         
         DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
      }
      else
      {  
         reset_index++; //Change format!!, don't change power
         if (reset_index>1)
         {
            reset_index = 0;
            SIM_SetEvent(SimCard,SIM_CARDERR);
         }
         else
         {
            if (SimCard.Data_format == SIM_indirect)
            {
               SimCard.Data_format = SIM_direct;
               SIM_L1Reset();
            }
            else
            {
               SimCard.Data_format = SIM_indirect;
               SIM_L1Reset();
            }
         }
      }
      return;  
   }
   
   if (SimCard.State == SIM_PROCESS_ATR)
   {
      while(1)
      {
         if (SIM_FIFO_GetLev())
         {
            SimCard.recData[SimCard.recDataLen] = DRV_Reg(SIM_DATA);
            ////dbg_print("ATR data=%x\r\n",SimCard.recData[SimCard.recDataLen]);
            SimCard.recDataLen++;
         }
         else
         {
            if (sim_int & SIM_STS_TOUT)
            {
               SIM_SetEvent(SimCard,SIM_SUCCESS);
            }
            break;
         }
      }
      return;
   }
   
   if (SimCard.State == SIM_PROCESS_PTS)
   {
      index = 0;
      while(KAL_TRUE)
      {
         PTS_data[index] = DRV_Reg(SIM_DATA);
         index++;
         
         if (SIM_FIFO_GetLev()==0)
         {
            SIM_SetEvent(SimCard,SIM_SUCCESS);
            break;
         }
      }
      SIM_DisAllIntr();
      return;
   }
   
   if (SimCard.State == SIM_PROCESSCMD)
   {
      kal_uint16 ACK;
          
      while(SIM_FIFO_GetLev())
      {
         if (SimCard.cmdState == SIM_WaitProcByte)
         {
            ACK = DRV_Reg(SIM_DATA);

            if ((ACK == SimCard.INS) || (ACK == (SimCard.INS+1)))    //ACK
            {
               if (SimCard.txsize != 5)
               {
                  /*Trx command*/
                  DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
                  SimCard.txindex++;
                  SIM_SetTXTIDE(0);
                  DRV_WriteReg(SIM_IRQEN,(SIM_IRQEN_Normal | SIM_IRQEN_TX));
                  SimCard.cmdState = SIM_AckDataState;
                  return;
               }
               else
               {
                  SIM_SetTXTIDE(0xffff);
                  DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
                  SimCard.cmdState = SIM_AckDataState;
                  continue;
               }
            }
         
            if ((ACK == (~SimCard.INS & 0x00ff)) || (ACK == (~(SimCard.INS+1)& 0x00ff)))    ///NACK
            {
               if (SimCard.txsize != 5)
               {
                  DRV_WriteReg(SIM_DATA,*(SimCard.txbuffer+SimCard.txindex));
                  SimCard.txindex++;
                  SIM_SetRXTIDE(1);
                  SimCard.cmdState = SIM_WaitProcByte;
                  /*Trx command*/
                  DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
                  return;
               }
               else
               {
                  SIM_SetTXTIDE(0xffff);
                  SimCard.cmdState = SIM_NAckDataState;
                  DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
               }
               continue;
            }
         
            if (ACK == 0x60)    //ACK
            {
                ////dbg_print("NULL\r\n");
               continue;
            }
            if (SIM_CheckSW(ACK))    //ACK
            {
               SimCard.SW1 = (kal_uint8)ACK;
               SIM_SetRXTIDE(1);
               SimCard.recDataLen++;
               SimCard.cmdState = SIM_WaitSWByte;
               continue;
            }
         }
      
         if (SimCard.cmdState == SIM_WaitSWByte)
         {
            SimCard.SW2 = (kal_uint8)DRV_Reg(SIM_DATA);
            /*SimCard.recDataLen++;*/
            SimCard.recDataLen--;
            if (SimCard.INS == 0xc0)
            {
               SimCard.recDataLen++;
            }
            SIM_SetEvent(SimCard,SIM_SUCCESS);
            return;
         }
      
         if (SimCard.cmdState == SIM_AckDataState)
         {
            *(SimCard.rxbuffer+SimCard.recDataLen) = (kal_uint8)DRV_Reg(SIM_DATA);
            SimCard.recDataLen++;
            if (SimCard.recsize == SimCard.recDataLen)
            {
               SimCard.cmdState = SIM_WaitProcByte;
            }
            continue;
         }
      
         if (SimCard.cmdState == SIM_NAckDataState)
         {
            *(SimCard.rxbuffer+SimCard.recDataLen) = (kal_uint8)DRV_Reg(SIM_DATA);
            SimCard.recDataLen++;
            SimCard.cmdState = SIM_WaitProcByte;
            continue;
         }
      }  /*while(SIM_FIFO_GetLev())*/
      
      if (SimCard.txsize == 5)
      {
         if ((SimCard.recsize+2 - SimCard.recDataLen) > 31)
         {
            SIM_SetRXTIDE(CMD_RECBUFSIZE);
         }
         else
         {
            SIM_SetRXTIDE(SimCard.recsize+2 - SimCard.recDataLen);
         }
         DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);
      }
      return;
   }
}

void SIM_HISR(void)
{
   kal_uint16   sim_int;
   
   sim_int = DRV_Reg(SIM_STS);

   ////dbg_print("sim_int=%x\r\n",sim_int);
   if ( sim_int & SIM_STS_TXERR)
   {
      ////dbg_print("SIM_STS_TXERR\r\n");
      if (SimCard.State == SIM_PROCESSCMD)
      {
         SimCard.State = SIM_SERIOUSERR;
         DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_TOUT);
      }
      else
      {
         SIM_Reject();
         //SIM_SetEvent(SimCard,SIM_INIPTSERR);
      }
   }

   if ( sim_int & SIM_STS_TX)
   {
       ////dbg_print("SIM_STS_TX\r\n");
      SIM_Txhandler();  /* Only used for no DMA */
   }
   
   if ( sim_int & SIM_STS_TOUT)
   {
      ////dbg_print("SIM_STS_TOUT\r\n");
      if(SimCard.State == SIM_PROCESS_ATR) 
      {
         SIM_Rxhandler(sim_int);
      }
      
      if( SimCard.State == SIM_PROCESS_PTS)
      {
         SIM_SetEvent(SimCard,SIM_INIPTSERR);
      }
      
      if (SimCard.State == SIM_PROCESSCMD)
      {
         if(SimCard.recDataErr == KAL_TRUE)
         {
            SIM_SetEvent(SimCard,SIM_CMDRECERR);
         }
         else
         {
            switch(SimCard.cmdState)
            {
               case SIM_ProcessClk:
                  ////dbg_print("SIM_ProcessClk\r\n");
                  SIM_SetEvent(SimCard,SIM_CLKPROC);
                  break;
                  
               case SIM_StopClk:
                  ////dbg_print("SIM_StopClk\r\n");
                  SIM_Idle(SimCard.clkStopLevel);
                  break;
                  
               default: /*normal command case*/
                    #if 0
/* under construction !*/
/* under construction !*/
                    #endif
                  if (SimCard.cmdState == SIM_WaitProcByte)
                  {
                     kal_uint8 ACK;
                     kal_uint8 Error;
                     Error = KAL_TRUE;
                     while(SIM_FIFO_GetLev())
                     {
                        ACK = (kal_uint8)DRV_Reg(SIM_DATA);
                        if (ACK == 0x60)    //NULL
                        {
                           continue;
                        }
                        if (SIM_CheckSW(ACK))    //ACK
                        {
                           SimCard.SW1 = ACK;
                           SimCard.SW2 = (kal_uint8)DRV_Reg(SIM_DATA);
                           SIM_SetEvent(SimCard,SIM_SUCCESS);
                           Error = KAL_FALSE;
                        }
                        else
                        {
                           break;
                        }
                     }
                     if (Error)
                     {
                        SIM_SetEvent(SimCard,SIM_CMDTOUT);
                     }
                  }
                  else
                  {
                     SIM_SetEvent(SimCard,SIM_CMDTOUT);
                  }
                  break;
            }/*endof switch*/
         }
      }/*if (SimCard.State == SIM_PROCESSCMD)*/
      
      if (SimCard.State == SIM_SERIOUSERR)
      {
         SIM_SetEvent(SimCard,SIM_CMDTXERR);
      }
      SIM_DisAllIntr();
   }
   
   if (sim_int & SIM_STS_RX)
   {
      ////dbg_print("SIM_STS_RX\r\n");
      SIM_Rxhandler(sim_int);
   }

   if ( sim_int & SIM_STS_OV)
   {
      ////dbg_print("SIM_STS_OV\r\n");
      SimCard.recDataErr = KAL_TRUE;
   }
   
   if ( sim_int & SIM_STS_NATR)
	{
	   ////dbg_print("SIM_STS_NATR\r\n");
	   SIM_DisAllIntr();
      if (SimCard.SIM_ENV == ME_18V_30V)
	   {
	      if (SimCard.Power == SimCard.initialPower)
         {
            if (SimCard.Power != SIM_30V)
            {
               SimCard.Power = SIM_30V;
            }
            else
            {
               SimCard.Power = SIM_18V;
            }
            SIM_L1Reset();
         }
         else
         {
            SIM_Reject();
         }
	   }
	   else
	   {
	      SIM_Reject();
	   }
   }

   if ( sim_int & SIM_STS_SIMOFF)
   {
      ////dbg_print("SIM_STS_SIMOFF\r\n");
      //////dbg_print("SIM off intr.\r\n");
      SIM_DisAllIntr();
      if (SimCard.State == SIM_PWROFF)
      {
         DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
         if (SimCard.reject_set_event)
            SIM_SetEvent(SimCard,SIM_NOREADY);
      }
      else
      {
         SIM_Initialize(SimCard.Data_format,SimCard.Power);
      }
   }
   IRQClearInt(IRQ_SIM_CODE);
   IRQUnmask(IRQ_SIM_CODE);   
   ////dbg_print("IRQ unmask\r\n");
}

void SIM_LISR(void)
{
   ////dbg_print("sim LISR\r\n");
   IRQMask(IRQ_SIM_CODE);
   drv_active_hisr(DRV_SIM_HISR_ID);
}

#if 1
//==========================SIM adaption=============================
/*
* FUNCTION                                                            
*  L1sim_PowerOff
*
* DESCRIPTION                                                           
*     The function requests the driver to deactivate SIM
*
* CALLS  
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_PowerOff(void)  //Validate
{
   SIM_DisAllIntr();
   SimCard.reject_set_event = KAL_FALSE;
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   if(DRV_Reg(SIM_CTRL) | SIM_CTRL_HALT)
   	DRV_Reg(SIM_CTRL) &= ~SIM_CTRL_HALT;   
   SIM_Reject();
   //DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
}

/*
* FUNCTION
*  L1sim_Reset
*
* DESCRIPTION
*     The function L1sim_Reset is used to reset SIM by specific voltage
*
* CALLS
*
* PARAMETERS
*  resetVolt: Request the driver to reset SIM at voltage resetVolt
*  resultVolt: The pointer to the voltage after the driver reset SIM. 
*  (RESET_3V,RESET_5V)
*  Info: The pointer to buffer of ATR data returned from SIM
*
* RETURNS
*  SIM_NO_ERROR   No SIM error
*  SIM_NO_INSERT  No SIM inserted
*  SIM_CARD_ERROR SIM fatal error
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 L1sim_Reset(kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info)   //Validate
{
   kal_uint8 index;
   
   SIM_DisAllIntr();
   SimCard.reject_set_event = KAL_TRUE;
   SimCard.sim_card_speed = sim_card_normal_speed;
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   TOUTValue = 0x260;
   TOUT_Factor=1;
   SimCard.clkStop = KAL_FALSE;
   SimCard.Speed = Speed372;
   SimCard.State = SIM_WAIT_FOR_ATR;
   SimCard.Power = resetVolt;
   SimCard.initialPower = resetVolt;
   SimCard.Data_format = SIM_direct;
   
   reset_index = 0;
   SimCard.result = SIM_NOREADY;
   SIM_L1Reset();
   
   SIM_WaitEvent(SimCard,RST_READY);
   
   if (SimCard.result == SIM_NOREADY)
   {
      L1sim_PowerOff();
      return SIM_NO_INSERT;
   }
   
   if (SimCard.result == SIM_CARDERR)
   {
      if (SimCard.Power == SIM_30V)
      {
         SimCard.Power = SIM_18V;
         SIM_L1Reset();
      }
      else
      {
         SimCard.Power = SIM_30V;
         SIM_L1Reset();
      }
      SIM_WaitEvent(SimCard,RST_READY);
   }
   
   if (SimCard.result == SIM_SUCCESS)
   {
      index=0;
      while(1)
      {
         if (!SIM_ProcessATRData())
			{
				index++;
				if (index ==2)
				{
				   PTS_check = KAL_FALSE;
				}
				else if (index > 2)
				{
				   PTS_check = KAL_FALSE;
					L1sim_PowerOff();
					return SIM_CARD_ERROR;
				}
				SIM_ResetNoATR(SimCard.Power);
			}
         else
         {
            if (resultVolt != NULL)
            {
               *resultVolt = SimCard.Power;
            }
            if (Info != NULL)
            {
               for (index = 0;index < SimCard.recDataLen;index++)
               {
                  Info->info[index] = SimCard.recData[index];
               }
            }
            return SIM_NO_ERROR;
         }
      }
   }
   else
   {
      L1sim_PowerOff();
      return SIM_CARD_ERROR;
   }
}


void L1sim_NormalBaud(void)
{
//#if ( (defined(MT6218)) || (defined(MT6218B)) )
#if defined(DRV_SIM_BAUD_6218B_SERIES)
   DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372));
#endif   /*MT6218,MT6218B*/
}

void L1sim_ChangeBaud(void)
{
//#if ( (defined(MT6218)) || (defined(MT6218B)) )
#if defined(DRV_SIM_BAUD_6218B_SERIES)
   DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | (0x17<<2)));
#endif   /*MT6218,MT6218B*/
}

/*
* FUNCTION
*	L1sim_Enable_Enhanced_Speed
*
* DESCRIPTION                                                           
*   	The function must call before L1sim_Reset. Otherwise, enhance speed is disable.
*     This function can enable enhance speed mode or not.
*
* CALLS  
*
* PARAMETERS
*	enable: KAL_TRUE: enable enhanced speed. KAL_FALSE: disable it.
*
* RETURNS
*	NULL
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Enable_Enhanced_Speed(kal_bool enable)
{
   PTS_check = enable;
}

void L1sim_Enable_Enhanced_Speed_2(kal_bool enable)  // nick
{
   PTS_check = enable;
}

sim_card_speed_type L1sim_Get_CardSpeedType_2(void) //nick
{}

sim_card_speed_type L1sim_Get_CardSpeedType(void)
{
   return SimCard.sim_card_speed;
}

/*
* FUNCTION                                                            
*  L1sim_Configure
*
* DESCRIPTION                                                           
*     The function indicates clock mode when idle.
*
* CALLS  
*
* PARAMETERS
*  clockMode: The clockMode defines the clock mode when idle.
*     CLOCK_STOP_AT_HIGH,CLOCK_STOP_AT_LOW,CLOCK_STOP_NOT_ALLOW
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Configure(kal_uint8 clockMode)  //Validate
{
   switch (clockMode)
   {
      case CLOCK_STOP_AT_HIGH:
         SimCard.clkStop = KAL_TRUE;
         SimCard.clkStopLevel = KAL_TRUE;
         break;
         
      case CLOCK_STOP_AT_LOW:
         SimCard.clkStop = KAL_TRUE;
         SimCard.clkStopLevel = KAL_FALSE;
         break;
         
      case CLOCK_STOP_NOT_ALLOW:
         SimCard.clkStop = KAL_FALSE;
         break;
         
      default:
         break;
   }
}

/*
* FUNCTION                                                            
*  L1sim_Cmd
*
* DESCRIPTION                                                           
*     The function is used to transmit coded command and 
*  its following data to the driver.
*
* CALLS  
*
* PARAMETERS
*  txData: Pointer to the transmitted command and data.
*  txSize:  The size of the transmitted command and data from AL to driver.
*  expSize: The size of expected data from SIM
*  result: Pointer to received data 
*  rcvSize: Pointer to the size of data received
*  parityError: 1 (parity error) or 0(no parity error)
*
* RETURNS
*  status(high byte:sw1 low byte: sw2)
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint16 L1sim_Cmd_2(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error)
{}

kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error)
//kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  expSize, kal_uint8  *result,kal_uint8  *rcvSize, kal_uint8 *Error)
{
   kal_uint16 SW;
   kal_uint8 index;
   kal_uint16 temp;
   kal_uint16 expSize = *rcvSize;
   
   if (SimCard.State != SIM_PROCESSCMD)
   {
      *Error = KAL_TRUE;
      return 0;
   }
   
   if ((SimCard.cmdState != SIMD_CmdIdle)&&(SimCard.cmdState != SIM_StopClk))
   {
      *Error = KAL_TRUE;
      return 0;
   }
   
   /*for clock stop mode*/
   SIM_DisAllIntr();
   
   if (SimCard.clkStop == KAL_TRUE)
   {
      SIM_ActiveClk();
   }
   else
   {
      DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
   }
   
   if( (SimCard.Speed != Speed372) &&
       ((DRV_Reg(SIM_CTRL)) & SIM_CTRL_HALT) 
     )     
   {
      SIM_SetTOUT(ClkStopTimeTable[SimCard.Speed][0]*TOUT_Factor);
      SimCard.cmdState = SIM_ProcessClk;
      DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_TOUT);
      SIM_WaitEvent(SimCard,CLK_PROC);
   }

   SIM_SetTOUT(TOUTValue);
   SIM_FIFO_Flush();
   *Error = KAL_FALSE;
   
   SimCard.txbuffer = txData;
   SimCard.txsize = txSize;
   SimCard.rxbuffer = result;
   SimCard.recDataLen = 0;
   SimCard.recsize = expSize;
   SimCard.txindex = 0;
   SimCard.INS = *(txData+1);

   for(index=0;index<5;index++)
   {
      DRV_WriteReg(SIM_DATA,*(txData+index));
   }
   SimCard.txindex = 5;
   SimCard.cmdState = SIM_WaitProcByte;
   
   if (expSize == 0) //Transmit
   {
      if (txSize == 5)
      {
         SIM_SetRXTIDE(2);
      }
      else
      {
         SIM_SetRXTIDE(1);
      }
   }
   else
   {
      if ((expSize+3) > 31)
      {
         SIM_SetRXTIDE(CMD_RECBUFSIZE);
      }
      else
      {
         SIM_SetRXTIDE(expSize+3);
      }
   }
   temp = DRV_Reg(SIM_STS);
   DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_Normal);

   SIM_WaitEvent(SimCard,CMD_END);
   
   SimCard.initialPower = SimCard.cmdState;
   SimCard.cmdState = SIMD_CmdIdle;

   *rcvSize = SimCard.recDataLen;

   if (SimCard.result == SIM_SUCCESS)
   {
      SW = (SimCard.SW2 | (SimCard.SW1 << 8));

      /*for clock stop mode*/
      if(SimCard.clkStop == KAL_TRUE)
      {
         SIM_DisAllIntr();
      
         SIM_SetTOUT(ClkStopTimeTable[SimCard.Speed][1]*TOUT_Factor);
         SimCard.cmdState = SIM_StopClk;
         DRV_WriteReg(SIM_IRQEN,SIM_IRQEN_TOUT);
      }
      //dbg_print("SW=%x\r\n",SW);
      return SW;
   }
   else
   {
      //dbg_print("Command Error\r\n");
      SimCard.recDataErr = KAL_FALSE;
      *Error = KAL_TRUE;
      return 0;
   }
}

kal_uint16 SIM_CMD(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error)
{
   return L1sim_Cmd(txData,txSize,result,rcvSize,Error);
}
/*
* FUNCTION                                                            
*  L1sim_Init
*
* DESCRIPTION                                                           
*     The function L1sim_Init initialize the SIM driver.
*
* CALLS  
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Init(void)      //Validate
{
   kal_uint16 tmp;
   
   SimCard.SIM_ENV = SIM_GetCurrentEnv();
   if (SimCard.SIM_ENV == ME_30V_ONLY)
	{
	   SimCard.Power = SIM_30V;
	}
	else
	{
	   SimCard.Power = SIM_18V;
	}

   SimCard.Data_format = SIM_direct;
   SimCard.State = SIM_WAIT_FOR_ATR;
   SimCard.clkStop = KAL_FALSE;
   SimCard.Speed = Speed372;
   
   tmp = DRV_Reg(SIM_STS);

   if (SimCard.event == NULL)
      SimCard.event = kal_create_event_group("SIMEVT");

   DRV_Register_HISR(DRV_SIM_HISR_ID, SIM_HISR);
      
   IRQ_Register_LISR(IRQ_SIM_CODE, SIM_LISR,"SIM handler");
   IRQSensitivity(IRQ_SIM_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_SIM_CODE);
}
#endif

//================================SIM test code==================================
#ifdef DEVDRV_TEST
kal_uint8 Volt;
kal_uint8 resVolt;
AtrStruct ATRInfo;

#if 1
void PinCheck(kal_uint8 *inputdata,kal_uint16 *res)
{
   kal_uint8 cmd[50],j;
   kal_uint16 rec;
   kal_uint16 SW;
   kal_uint8 parity_err;
   
   cmd[0]= 0xa0;
   cmd[1]= 0x20;
   cmd[2]= 0x0;
   cmd[3]= 0x01;
   cmd[4]= 0x08;
   for (j=0;j<8;j++)
   {
      cmd[j+5]= *(inputdata+j);
   }
   
   //SIM_Command(&sim_cmd);
   rec = 0;
   SW = L1sim_Cmd(cmd,13,NULL,&rec, &parity_err);
   if (parity_err)
   {
      //////dbg_print("Parity Error\r\n");
   }
   //////dbg_print("PinCheck SW=%x\r\n",SW);
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
}


void SelectFile(kal_uint8 *inputdata,kal_uint16 *res)
{
   kal_uint8 cmd[50];
   kal_uint16 rec;
   kal_uint8 parity_err;
   kal_uint16 SW;
   
   cmd[0]= 0xa0;
   cmd[1]= 0xa4;
   cmd[2]= 0x0;
   cmd[3]= 0x0;
   cmd[4]= 0x02;
   
   cmd[5]= *inputdata;
   cmd[6]= *(inputdata+1);
      
   //SIM_Command(&sim_cmd);
   rec = 0;
   SW = L1sim_Cmd(cmd,7,NULL,&rec, &parity_err);
   if (parity_err)
   {
      //////dbg_print("Parity Error\r\n");
   }
   *res = (kal_uint8)(SW >> 8);
   *(res+1) = (kal_uint8)SW;
   //////dbg_print("SelectFile SW=%x\r\n",SW);

   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   //////dbg_print("Select File cmd is ok\r\n");
}

void GetResponse(kal_uint8 len, kal_uint16 *res)
{
   kal_uint8 cmd[50];
   kal_uint16 i;
   kal_uint16 rec;
   kal_uint8 resp[50];
   kal_uint16 SW;
   kal_uint8 parity_err;

   cmd[0]= 0xa0;
   cmd[1]= 0xc0;
   cmd[2]= 0x0;
   cmd[3]= 0x0;
   cmd[4]= len;
      
   //SIM_Command(&sim_cmd);
   rec = len;
   SW = L1sim_Cmd(cmd,5,(kal_uint8 *)resp,&rec, &parity_err);
   for(i=0;i<rec;i++)
   {
      res[i] = (kal_uint16)resp[i];
   }
   *(res+rec) = (kal_uint8)(SW >> 8);
   *(res+rec+1) = (kal_uint8)SW;
   if (parity_err)
   {
      //////dbg_print("Parity Error\r\n");
   }
   
   //////dbg_print("GetResponse SW=%x\r\n",SW);
   
   //////dbg_print("the voltage value=%x\r\n",res[13]);
}

void ReadBinary(kal_uint8 len, kal_uint16 *res)
{
   kal_uint8 cmd[50];
   kal_uint16 i;
   kal_uint16 rec;
   kal_uint8 resp[50];
   kal_uint16 SW;
   kal_uint8 parity_err;

   cmd[0]= 0xa0;
   cmd[1]= 0xb0;
   cmd[2]= 0x0;
   cmd[3]= 0x0;
   cmd[4]= len;
      
   //SIM_Command(&sim_cmd);
   rec = len;
   SW = L1sim_Cmd(cmd,5,(kal_uint8 *)resp,&rec, &parity_err);
   for(i=0;i<rec;i++)
   {
      res[i] = (kal_uint16)resp[i];
   }
   *(res+rec) = (kal_uint8)(SW >> 8);
   *(res+rec+1) = (kal_uint8)SW;
   if (parity_err)
   {
      //////dbg_print("Parity Error\r\n");
   }
   //////dbg_print("ReadBinary SW=%x\r\n",SW);
   
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   //////dbg_print("Read Binary cmd is ok\r\n");
   //////dbg_print("the read data [14]=%x\r\n",res[13]); 
}


kal_bool vcc_check(void)
{
	kal_uint8 cmd[50];
   kal_uint16 resp[300];
   kal_uint16 temp;

   #if 1
   //cmd[0]= 0x7f;
   //cmd[1]= 0x20;
   //SelectFile(cmd,resp);
   cmd[0]= 0x7f;
   cmd[1]= 0x20;
   //dbg_print("SIM: SelectFile\r\n");
   SelectFile(cmd,resp);
   //dbg_print("SIM: SelectFile end\r\n");
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   
   //////dbg_print("rec length=%d\r\n",*(resp+1));
   //dbg_print("SIM: GetResponse start\r\n");
   GetResponse(*(resp+1),resp);
   //dbg_print("SIM: GetResponse end\r\n");
   temp = resp[13] & 0x000d;
   
   SimCard.clkStop = KAL_TRUE;
   //SimCard.clkStop = KAL_FALSE;
   if (temp & 0x0001)
   {
      if ((temp & 0x0004)!=0)
      {
         SimCard.clkStopLevel = KAL_TRUE;  //bit 3
      }
      
      if ((temp & 0x0008)!=0)    //bit 4
      {
         SimCard.clkStopLevel = KAL_FALSE;
      }
   
      if ((temp & 0x000c) == 0)  //default
      {
         SimCard.clkStopLevel = KAL_FALSE;
      }
   }
   else
   {
      if ((temp & 0x0004)!=0)
      {
         SimCard.clkStopLevel = KAL_TRUE;  //bit 3
      }
      
      if ((temp & 0x0008)!=0)    //bit 4
      {
         SimCard.clkStopLevel = KAL_FALSE;
      }
   
      if ((temp & 0x000c) == 0)  //default
      {
         SimCard.clkStopLevel = KAL_FALSE;
      }
   }
   temp = resp[13] & 0x000d;
   if (temp == 0)
   {
      SimCard.clkStop = KAL_FALSE;
      ////////dbg_print("fasfda&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\r\n");
   }
   
   temp = resp[13] & 0x0070;
   temp >>= 4;
   //////dbg_print("the volt=%d\r\n",temp);
   if ( temp == 1)   //3V card
   {
      if (SimCard.Power == SIM_18V)
      {
         //////dbg_print("3V reset\r\n");
         L1sim_Reset(SIM_30V,NULL,NULL);
         //return SimCard.result;
      }
   }
   if (temp == 0) //5V card
   {
      if (SimCard.Power == SIM_30V)
      {
         //////dbg_print("5V reset\r\n");
         L1sim_Reset(SIM_18V,NULL,NULL);   
         //return SimCard.result;
      }
   }
   #endif
   return KAL_TRUE;
}

void CheckPinCMD(void)
{
   kal_uint8 cmd[50];
   kal_uint16 resp[300];
   
   //1
   cmd[0]= 0x7f;
   cmd[1]= 0x20;
   SelectFile(cmd,resp);

   //2
   GetResponse(*(resp+1),resp);
   
   //3
   cmd[0]= 0x6f;
   cmd[1]= 0xae;
   SelectFile(cmd,resp);
   GetResponse(*(resp+1),resp);  //GD
   
   //4
   ReadBinary(1,resp);
   
   //5
   cmd[0]= 0x3f;
   cmd[1]= 0x00;
   SelectFile(cmd,resp);
   
   //6
   cmd[0]= 0x2f;
   cmd[1]= 0xe2;
   SelectFile(cmd,resp);
   
   //7
   ReadBinary(10,resp);
   
   //8
   cmd[0]= 0x7f;
   cmd[1]= 0x20;
   SelectFile(cmd,resp);
   
   //9
   cmd[0]= 0x6f;
   cmd[1]= 0x05;
   SelectFile(cmd,resp);
   
   //10
   GetResponse(*(resp+1),resp);
   
   #if 1
   //11
   ReadBinary(5,resp);
   #endif
   
   //12
   cmd[0]= 0x6f;
   cmd[1]= 0x39;
   SelectFile(cmd,resp);
   
   //13
   GetResponse(*(resp+1),resp);
   
   //14
   cmd[0]= 0x6f;
   cmd[1]= 0x37;
   SelectFile(cmd,resp);
   
   //15
   GetResponse(*(resp+1),resp);
   
   //16
   cmd[0]= 0x6f;
   cmd[1]= 0x41;
   SelectFile(cmd,resp);
   
   //17
   GetResponse(*(resp+1),resp);
   
   //18
   cmd[0]= 0x32;
   cmd[1]= 0x34;
   cmd[2]= 0x36;
   cmd[3]= 0x38;
   cmd[4]= 0xff;
   cmd[5]= 0xff;
   cmd[6]= 0xff;
   cmd[7]= 0xff;
   PinCheck(cmd,resp);
   
   //////dbg_print("Check PIN END..\r\n");
}

void closeSIMcmd(void)
{
   kal_uint8 cmd[50];
   kal_uint16 resp[300];
   
   cmd[0]= 0x6f;
   cmd[1]= 0x37;
   SelectFile(cmd,resp);
   
   GetResponse(*(resp+1),resp);
   
   cmd[0]= 0x6f;
   cmd[1]= 0x41;
   SelectFile(cmd,resp);
   
   GetResponse(*(resp+1),resp);
   SIM_Reject();
}

#endif

void Sim_test(void)
{
   kal_uint8 result;
   result = L1sim_Reset(SIM_30V,&resVolt,&ATRInfo);
   if (result == SIM_NO_ERROR)
   {
      //dbg_print("SIM has no Error!\r\n");
   }
   if (result == SIM_CARD_ERROR)
   {
      //dbg_print("SIM CARD has something error!\r\n");
      return;
   }
   
   if (result == SIM_NO_INSERT)
   {
      //dbg_print("SIM CARD no insert!\r\n");
      return;
   }
   //////dbg_print("the resVolt=%x\r\n",resVolt);
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   
      #if 1
      if (vcc_check())
      {
         //dbg_print("VCC check is ok\r\n");
         //dbg_print("the resVolt=%x\r\n",SimCard.Power);
      // break;
      }
      else
      {
         //dbg_print("VCC check is Failed\r\n");
      }
      #endif
      //return;
      CheckPinCMD();
      //////dbg_print("=========================================\r\n");
      #if 1
      //////dbg_print("Will be close the sim!!\r\n");
      //delay1s(50);
      closeSIMcmd();
      //SIM_Reject();
      //dbg_print("the runVolt=%x\r\n",SimCard.Power);
      //dbg_print("SIM is closed!!\r\n");
      #endif
}
#endif /* DEVDRV_TEST */

#endif /*(MT6208,FPGA)*/

