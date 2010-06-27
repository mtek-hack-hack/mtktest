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
 *   usim_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   USIM driver functions.
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#include  	"drv_comm.h"
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include    "sim_al.h"
#include    "sim_hw.h"
#include    "dma_sw.h"
#include    "sim_sw.h"
#include    "dma_hw.h"
#include		"gpt_sw.h"
#include		"gpio_sw.h"
#include		"drv_hisr.h"

#include "msdc_def.h" 

#if defined(__USIM_DRV__)
#ifndef DRV_MULTIPLE_SIM
#include		"usim_drv.h"

#include "pwic.h"

extern void SIM_SetRXTIDE(kal_uint16 RXTIDE);
extern void SIM_SetTXTIDE(kal_uint16 _TXTIDE);
extern Sim_Card SimCard;
//extern 	kal_bool  TS_HSK_ENABLE;
extern kal_char sim_dbg_str[];
usim_dcb_struct usim_dcb;
usim_dcb_struct usim_dcb_2;
kal_uint8 BWT_Factor[3] = {1, 6, 12}; // 372/64 = 6, 372/32 = 12 

#if defined(USIM_DEBUG)
#define BUF_COUNT		1024
kal_uint16 int_buffer[BUF_COUNT];
kal_uint32 buf_index;
#define PUSH_INT(a)	int_buffer[(buf_index&(BUF_COUNT-1))] = a;\
							buf_index++;
#else
#define PUSH_INT(a)	
#endif

extern int sprintf(char *, const char *, ...);
#if defined(USIM_DEBUG)
extern void dbg_print(char * fmt,...);
static kal_uint32 start, end;
kal_uint32 get_current_time(void)
{
	return (DRV_Reg32(TDMA_base+0x0230));
}
kal_uint32 get_duration_tick(kal_uint32 previous_time)
{
	kal_uint32 result, current_time;

	current_time = DRV_Reg32(TDMA_base+0x0230);
	if (previous_time > current_time)
	{
		result = 0x80000 - previous_time + current_time;
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
}
#endif

// proto type
static kal_bool usim_check_input_volt(usim_power_enum  volt);
static usim_status_enum usim_process_ATR(void);
static void usim_process_TA1(kal_uint8 TA1);
static void usim_process_PTS(void);
static void usim_set_speed(usim_speed_enum speed);
static void usim_set_protocol(usim_protocol_enum T);
static void usim_set_timeout(kal_uint32 timeout);
static kal_bool usim_select_power(usim_power_enum ExpectVolt);
static void usim_activation(void);
static void usim_lisr(void);
static void usim_deactivation(void) ;
static void usim_t1end_handler(void);
static void usim_hisr(void);
static void usim_rx_handler(kal_uint32 int_status);
static void usim_send_block(kal_uint8 *adrs );
static kal_bool usim_rx_block_handler(kal_uint32 *adrs);
static sim_status usim_send_i_block(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize);

/*************************************************************************
* FUNCTION
*  usim_check_input_volt
*
* DESCRIPTION
*	 check if the input volt is supported by the interface device
*
* PARAMETERS
*	volt: voltage used by SIM card
*
* RETURNS
*	KAL_TRUE: it is supported 
*	KAL_FALSE: not supported
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
static kal_bool usim_check_input_volt(usim_power_enum  volt)
{
	if(usim_dcb.sim_env == ME_18V_30V)
		return KAL_TRUE;
	if(usim_dcb.sim_env == ME_30V_ONLY && volt == CLASS_B_30V)
		return KAL_TRUE;	
	if(usim_dcb.sim_env == ME_18V_ONLY && volt == CLASS_C_18V)
		return KAL_TRUE;
	
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  usim_check_TCK
*
* DESCRIPTION
*	 check if TCK present and the checksum of ATR is correct
*
* PARAMETERS
*
* RETURNS
*	KAL_TRUE: TCK is not present or chekcsum is correct
*	KAL_FALSE: Chekcsum is incorrect
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool usim_check_TCK(void)
{
	kal_uint32 i = 0;
	kal_uint8 ck = 0;
	kal_uint8 *ptr = usim_dcb.ATR_data; 

	kal_print("usim_check_TCK");
   while(DRV_Reg(SIM_COUNT) == 0 && i++ <= 22)
   {
		kal_sleep_task(10);
   }	   	
	if(i >= 23)
	{
		kal_print("TCK not present");	
		return KAL_TRUE;
	}
	ptr[usim_dcb.ATR_index++] = DRV_Reg(SIM_DATA);
	for(i=1;i<usim_dcb.ATR_index;i++)
		ck ^= ptr[i];
	if(ck != 0)
	{
		kal_print("TCK checksum err");	
		return KAL_FALSE;
	}

	kal_print("TCK checksum ok");	
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  usim_process_ATR
*
* DESCRIPTION
*	1. wait all ATR characters received at HISR and put into usim_dcb.ATR_data
*	2. Get parameters from ATR, Fi, Di, T0_support, T1_support, reset mode, WWT(T0)
*		IFSC(T1), CWI, BWI, X, U
*
* PARAMETERS
*	None
* RETURNS
*  KAL_TRUE: Valid TS is received
*  KAL_FALSE: Valid TS is not received, card is not present or not supported
*
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static usim_status_enum usim_process_ATR(void)
{
	kal_uint8 data,TD;
	kal_bool T15;
	kal_uint8 *ptr = usim_dcb.ATR_data;	
	kal_uint32 index = 1;	// skip the first TS byte

   // get the application protocol of the sim card 
   if((ptr[index] & 0x0f) == 0)
   	usim_dcb.app_proto = SIM_PROTOCOL; // no historical char imply SIM_PROTOCOL
   do 
   {
   	data = ptr[index++];
   	USIM_CAL_TD_COUNT(data, index);
   }while(data & TDMask);
   usim_dcb.hist_index = index;
   if(ptr[index] == HIST_FIRST_USIM && ptr[index+1] == HIST_SEC_USIM 
   	&& ptr[index+3] == HIST_FOUR_USIM)
   	usim_dcb.app_proto = USIM_PROTOCOL;
   else
   	usim_dcb.app_proto = SIM_PROTOCOL;
	// parse the content of ATR	
	T15 = KAL_FALSE;
	index = 1;
	TD = ptr[index++];	//T0
	if(TD & TAMask)
	{
		// TA1 (FI, DI)		
		data = ptr[index++];
		usim_process_TA1(data);
		usim_dcb.WWT = INIT_WWT_T0*usim_dcb.Di;
	}			
	if(TD & TBMask)
	{
		// TB1 (PI, II) (neglect it)
		data = ptr[index++];
	}
	if(TD & TCMask)
	{
		// TC1 (N: extra guard time) (neglect it)
		data = ptr[index++];
		if(data != 0 && data != 255)
			return USIM_INVALID_ATR;
	}
	if( !(TD & TDMask))
	{
		usim_dcb.T0_support = KAL_TRUE;
		return USIM_NO_ERROR;
	}
	
	TD = ptr[index++]; // TD1
	if((TD & 0x0f) == 0)
		usim_dcb.T0_support = KAL_TRUE;
	else if((TD & 0x0f) == 1)
		usim_dcb.T1_support = KAL_TRUE;
	else if(TD & 0x0f == 0x0f)
	{
		// T = 15 is forbidden in TD1
		return USIM_INVALID_ATR;
	}
	
	if(TD & TAMask)
	{
		//TA2 (specific mode)
		/////dbg_print("TA2(specific mode) \r\n");
		data = ptr[index++];
		usim_dcb.reset_mode = USIM_RESET_SPECIFIC;
		// chage the clock to the one before reset.
	}
	if(TD & TBMask)
	{
		// TB2 (PI2)(neglect it)
		data = ptr[index++];
	}
	if(TD & TCMask)
	{
		// TC2 (work waiting time = 960xWIxDi etu)(T0)
		data = ptr[index++];
		usim_dcb.WWT = 960*data*usim_dcb.Di;
	}
	/////dbg_print("WWT: %d \r\n",usim_dcb.WWT);
	if( !(TD & TDMask))
	{
		if(usim_dcb.T0_support && !usim_dcb.T1_support && !T15)
		{
			return USIM_NO_ERROR;
		}
		else
		{
			if (usim_check_TCK() == KAL_FALSE)
				return USIM_INVALID_ATR;
			else
				return USIM_NO_ERROR;
		}
	}
	
	TD = ptr[index++]; // TD2
	if((TD & 0x0f) == 1)
	{
		usim_dcb.T1_support = KAL_TRUE;
	}
	else if(TD & 0x0f == 0x0f)
	{
		T15 = KAL_TRUE;
		goto global_interface;
	}
	if(TD & TAMask)
	{
		//TA3 (ISFC)
		data = ptr[index++];
		usim_dcb.ifsc = data;
		/////dbg_print("IFSC: %d \r\n",data);		
	}
	if(TD & TBMask)
	{
		kal_uint8 cwi,bwi;
		
		// TB3 (PI2)
		data = ptr[index++];
		cwi = data&0xf; // range from 0~5
		bwi = (data&0xf0)>>4;
		if(cwi > MAX_CWI)
			return USIM_INVALID_ATR;
		if(bwi > MAX_BWI)
			return USIM_INVALID_ATR;
		usim_dcb.CWT = (1<<cwi)+11;
		usim_dcb.BWT = (1<<bwi)*960; 
	}
	else
	{
		usim_dcb.CWT = USIM_CWT_DEFAULT;
		usim_dcb.BWT = USIM_BWT_DEFAULT;
	}	
	/////dbg_print("BWT: %d \r\n",usim_dcb.BWT);		
	if(TD & TCMask)
	{
		// TC3 (neglect)
		data = ptr[index++];
	}	
	if( !(TD & TDMask))
	{
		if(usim_dcb.T0_support && !usim_dcb.T1_support && !T15)
			return USIM_NO_ERROR;
		else
		{
			if (usim_check_TCK() == KAL_FALSE)
				return USIM_INVALID_ATR;
			else
				return USIM_NO_ERROR;
		}
	}
	TD = ptr[index++]; // TD3
	if(TD & 0x0f != 0x0f)
	{
		if(usim_dcb.T0_support && !usim_dcb.T1_support && !T15)
			return USIM_NO_ERROR;
		else
		{
			if (usim_check_TCK() == KAL_FALSE)
				return USIM_INVALID_ATR;
			else
				return USIM_NO_ERROR;
		}
	}
	
global_interface:
	
	if (usim_check_TCK() == KAL_FALSE)
		return USIM_INVALID_ATR;
		
	if(TD & TAMask)
	{
		//TAi (clock stop(X) and power class(U))
		data = ptr[index++];
		usim_dcb.clock_stop_type = (data&CLOCK_STOP_MSK);
		if(usim_dcb.app_proto == SIM_PROTOCOL)
			usim_dcb.power_class = 0xff;
		else
		usim_dcb.power_class = (data & USIM_POW_CLASS_MSK);
		/////dbg_print("clock stop[7:8]|power class[1:6]: %x \r\n",data);
	}
	// check if used power is supported by the UICC
	if((usim_dcb.power & usim_dcb.power_class) == 0)
	{
		if(usim_dcb.sim_env == ME_18V_30V)
		{
			if(usim_dcb.power == CLASS_C_18V)
				usim_dcb.power = CLASS_B_30V;
		
			return USIM_VOLT_NOT_SUPPORT;
		}
	}
	else if(usim_dcb.app_proto == SIM_PROTOCOL)
		return USIM_NO_ERROR;
	
	return USIM_NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  usim_process_TA1
*
* DESCRIPTION
	1. Get Di and Fi from TA1
*
* PARAMETERS
	TA1: first interface character used to indicate the Fi and Di
	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*	usim_dcb.Fi, usim_dcb.Di 
*
*************************************************************************/
static void usim_process_TA1(kal_uint8 TA1)
{
	if(TA1 == ATR_TA1_64)
	{
		/////dbg_print("SPEED64 \r\n");
		usim_dcb.Fi = 512;
		usim_dcb.Di = 8;		
		usim_dcb.card_speed = SPEED_64;
	}
	else if(TA1 == ATR_TA1_32)
	{
		/////dbg_print("SPEED32 \r\n");
		usim_dcb.Fi = 512;
		usim_dcb.Di = 16;				
		usim_dcb.card_speed = SPEED_32;		
	}
	else if(TA1 == ATR_TA1_16)
	{	// only support speed32 even encounter a speed16 card
		/////dbg_print("SPEED16 \r\n");
		usim_dcb.Fi = 512;
		usim_dcb.Di = 16;				
		usim_dcb.card_speed = SPEED_16;		
	}
	else
	{
		/////dbg_print("SPEED372 \r\n");		
		usim_dcb.Fi = 372;
		usim_dcb.Di = 1;					
		usim_dcb.card_speed = SPEED_372;		
	}
		 
}

/*************************************************************************
* FUNCTION
*  usim_process_PTS
*
* DESCRIPTION
*	1. Perform the PTS to select the protocol and enhanced speed parameter(Fn,Dn).
		T1 has higher priority than T0
*	2. Change the clock rate according to the PTS response
*	3. Enable the T0 or T1 controller according to the PTS response
*
* PARAMETERS
	None

* RETURNS
*	None
*
* GLOBALS AFFECTED
*	usim_dcb.speed
*
*************************************************************************/
static void usim_process_PTS(void)
{
	kal_uint32 i;	
	kal_uint8 pts[PPS_LEN],pts_r[PPS_LEN],pck;
	usim_speed_enum speed;
	kal_bool echoed = KAL_TRUE;

	/////dbg_print("usim_process_PTS \r\n");
	if(usim_dcb.app_proto == SIM_PROTOCOL)
	{
		/////dbg_print("PTS not performed (SIM_PROTOCOL) ");
		echoed = KAL_FALSE;
		goto exit;
	}
	if(usim_dcb.reset_mode == USIM_RESET_SPECIFIC)
	{
		/////dbg_print("not performed (specific mode)");
		echoed = KAL_TRUE;
		goto exit;
	}
	if(usim_dcb.high_speed_en)
	{
		if(usim_dcb.Di == 1)
			speed = SPEED_372;
		else if(usim_dcb.Di == 8)
			speed = SPEED_64;
		else if(usim_dcb.Di == 16)
			speed = SPEED_32;
		else
			speed = SPEED_372;
	}
	else
	{
		speed = SPEED_372;
	}
	/////dbg_print("select speed %d(372:64:32, 0:1:2)", speed); 
	
	// generate PTS packet
	pts[PPSS] = 0xff;
	pck = 0xff;
	pts[PPS0] = USIM_PTS_PS1_MSK;
	if(usim_dcb.T1_support && usim_dcb.app_proto == USIM_PROTOCOL && !usim_dcb.T0_support ) // priority T1 > T0
	{	// T1 only usim card will go to here
		/////dbg_print("select T=1\r\n");
		pts[PPS0] |= USIM_PTS_PS0_T1;			
	}
	else{
		/////dbg_print("select T=0\r\n");
	}
	pck ^= pts[PPS0];
	if(speed == SPEED_372)
		pts[PPS1] = ATR_TA1_372_5;
	else if(speed == SPEED_64)
		pts[PPS1] = ATR_TA1_64;
	else if(speed == SPEED_32) 	// SPEED_32
		pts[PPS1] = ATR_TA1_32;					
	pck ^= pts[PPS1];
		
	// send PTS packet
	usim_dcb.main_state = PTS_STATE;	
	pts[PCK] = pck;
	SIM_FIFO_Flush();	            
	SIM_SetRXTIDE(PPS_LEN); 
	for(i=0;i<PPS_LEN;i++)
	{		
		DRV_WriteReg(SIM_DATA,pts[i]);
	}
	usim_set_timeout(INIT_WWT_T0);
	USIM_WAIT_EVENT();
	usim_set_timeout(0);
	if(usim_dcb.ev_status != USIM_NO_ERROR)
		echoed = KAL_FALSE;
	// read the response
	if(echoed)
	{
		for(i=0;i<PPS_LEN;i++)
		{		
			pts_r[i] = DRV_Reg(SIM_DATA);
			if(pts[i]!= pts_r[i])
				echoed = KAL_FALSE;
		}
	}
	if(echoed)
	{
		/////dbg_print("PTS OK!\r\n");
		usim_set_speed(speed); 
	}
	else
	{
		/////dbg_print("PTS Fail!\r\n");
		usim_set_speed(Speed372); 
	}

exit:	
	// GSM will only use T=0, no matter t=1 is supported.
	if(usim_dcb.T1_support && !usim_dcb.T0_support &&
		(usim_dcb.app_proto == USIM_PROTOCOL) && echoed )
	{	// T1 only usim card will go to here
		usim_dcb.phy_proto = T1_PROTOCOL;		
		usim_set_protocol(T1_PROTOCOL);
		USIM_DISABLE_TXRX_HANSHAKE();					
		SIM_SetRXRetry(0);
		SIM_SetTXRetry(0);
	}
	else
	{
		usim_dcb.phy_proto = T0_PROTOCOL;	
		if(usim_dcb.app_proto == USIM_PROTOCOL)
			usim_set_protocol(T0_PROTOCOL); // SIM_PROTOCOL is enabled at simd.c			
		SIM_SetRXRetry(7);
		SIM_SetTXRetry(7);
		USIM_ENABLE_TXRX_HANSHAKE();
	}
	
	
}

/*************************************************************************
* FUNCTION
*  usim_set_timeout
*
* DESCRIPTION
*	 setup the timeout value in the unit of etu
*
* PARAMETERS
*	timeout: timeout value in the unit of etu , 0 means disabling timeout
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usim_set_timeout(kal_uint32 timeout)
{	
	if(timeout)
	{
		timeout >>= 2;
		SIM_SetTOUT(timeout+TOUT_OFFSET);
		usim_dcb.timeout = timeout+TOUT_OFFSET;
	}
	else
	{
		USIM_DISABLE_TOUT();
	}
}
/*************************************************************************
* FUNCTION
*  usim_set_speed
*
* DESCRIPTION
*	 setup the baudrate of the SIM card, only support 372, 64 and 32.
*	 speed 16 is not supported, use speed32 insteadly.
*
* PARAMETERS
*	timeout: timeout value in the unit of etu , 0 means disabling timeout
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usim_set_speed(usim_speed_enum speed)
{	
	switch(speed)
	{
		case SPEED_372: 
			// clock: 13/4 = 3.25M, with default etu F/372
			DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372));
			break;
		case SPEED_64:
			DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div64));
			break;
		case SPEED_32:
			DRV_WriteReg(SIM_BRR,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div32));
			break;
	}
	usim_dcb.speed = speed;		
	usim_dcb.BWT = usim_dcb.BWT*BWT_Factor[speed]+11;
}
/*************************************************************************
* FUNCTION
*  usim_set_protocol
*
* DESCRIPTION
*	 setup the physical protocol layer including T=0 and T=1.
*
* PARAMETERS
*	T: physical protocol layer including T=0 and T=1.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usim_set_protocol(usim_protocol_enum T)
{
	if( T == T1_PROTOCOL)
	{
		USIM_ENABLE_T1();
	}
	else
	{
		USIM_ENABLE_T0();
	}
	usim_dcb.phy_proto = T;
}
/*************************************************************************
* FUNCTION
*  usim_select_power
*
* DESCRIPTION
	1. Try the input voltage from application layer if availabe.
	2. Try the possible voltage which the ME can support.
	3. Get the valid TS
*
* PARAMETERS
	1. ExpectVolt: application layer give a expected power class

* RETURNS
*  KAL_TRUE: Valid TS is received
*  KAL_FALSE: Valid TS is not received, card is not present or not supported
*
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static kal_bool usim_select_power(usim_power_enum ExpectVolt)
{
	kal_uint32 retry;

	/////dbg_print("usim_select_power with power: %d \r\n", ExpectVolt);

	SIM_FIFO_Flush();	
	if(usim_dcb.warm_rst == KAL_FALSE)
	{
		usim_deactivation();
		// decide the initial power class
		usim_dcb.power_in = ExpectVolt;
		if(ExpectVolt != UNKNOWN_POWER_CLASS)
		{			
			usim_dcb.power = ExpectVolt;
		}
		else
		{		
			if (usim_dcb.sim_env == ME_30V_ONLY)
			{
				usim_dcb.power = CLASS_B_30V;
			}
			else // ME_18_ONLY, ME_18V_30V
			{
			   usim_dcb.power = CLASS_C_18V;
			}
		}
	}	
	// start from low power class to high, if no ATR received, try another power class
	// if the an invalid TS byte is received, change the convention with the same power class
	retry = 0;
	while(retry++ < 3)
	{
		kal_set_eg_events(usim_dcb.event,0,KAL_AND);
		//2007_04_12, some 3G card will give wrong ATR in the first time, and we should reset it twice
		//If we don't reset these 2 variables, former wrong path will affect next time we process ATR
		usim_dcb.abort = usim_dcb.resync = KAL_FALSE;
		usim_activation();	
		USIM_WAIT_EVENT();
		if(usim_dcb.ev_status == USIM_NO_ERROR )
		{	// a correct TS byte is received			
			USIM_WAIT_EVENT();			
			// all ATR characters are received
			if(usim_dcb.ev_status != USIM_ATR_REC)
				return KAL_FALSE;
			else
				return KAL_TRUE;
		}
		else if(usim_dcb.ev_status == USIM_ATR_REC)
		{	// all ATR characters are received
			return KAL_TRUE;
		}
		else if(usim_dcb.warm_rst == KAL_TRUE)
		{
			/////dbg_print("warm reset fail!!\r\n");
			usim_deactivation();
			return KAL_FALSE;
		}
		else if((usim_dcb.ev_status == USIM_TS_INVALID || usim_dcb.ev_status == USIM_RX_INVALID)
			&& (usim_dcb.dir == USIM_DIRECT))
		{				
			// try another convention 
			usim_dcb.dir = !usim_dcb.dir;
			usim_deactivation();			
			/////dbg_print("change another convention %d !!\r\n", usim_dcb.dir);			
		}
		else if(usim_dcb.ev_status == USIM_NO_ATR || usim_dcb.ev_status == USIM_BWT_TIMEOUT ||
			(usim_dcb.ev_status == USIM_TS_INVALID || usim_dcb.ev_status == USIM_RX_INVALID ))
		{
			retry = 0;
			usim_dcb.dir = USIM_DIRECT;
			// deactivate and delay			
			usim_deactivation();
			// change another power class if availabe, no retry with the same power class
			if(usim_dcb.sim_env == ME_18V_30V )
			{
				if(usim_dcb.power_in == UNKNOWN_POWER_CLASS && usim_dcb.power == CLASS_C_18V )
				{
					usim_dcb.power = CLASS_B_30V;
				}
				else if(usim_dcb.power_in != UNKNOWN_POWER_CLASS && usim_dcb.power_in == usim_dcb.power)
				{
					if(usim_dcb.power_in == CLASS_C_18V)
						usim_dcb.power = CLASS_B_30V;
					else
						usim_dcb.power = CLASS_C_18V;
				}				
				else
				{
					return KAL_FALSE;
				}				
			}
			else
			{
				return KAL_FALSE;
			}
			
		}
		else
		{
			ASSERT(0);
		}
	}
	return KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*  usim_activation
*
* DESCRIPTION
* Perform the activation of USIM
* It is a cold reset
* select the power according to usim_dcb.power (input)
* select the convention according to usim_dcb.dir (input)
* the clock rate adopted is SPEED_372
* set the default timeout value
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static void usim_activation(void)
{
	kal_uint16 reg = 0;

	/////dbg_print("usim_activation, pow = %d, dir: %d \r\n",usim_dcb.power, usim_dcb.dir);
	
#ifdef PMIC_VSIM_SEL
   if (usim_dcb.power == CLASS_B_30V)
      //pmic_vsim_sel(VSIM_3);
      pmic_adpt_set_vsim(PMIC_VSIM_3_0);
   else
      //pmic_vsim_sel(VSIM_1_8);
      pmic_adpt_set_vsim(PMIC_VSIM_1_8);
#elif !defined(PMIC_PRESENT)
	if (usim_dcb.power != CLASS_B_30V)
	{
		reg = SIM_CONF_SIMSEL;
	}
#else /*Phone setting*/
	if (usim_dcb.power == CLASS_B_30V) 
	{
		reg = SIM_CONF_SIMSEL;
	}
#endif   /*Phone setting*/
	if(usim_dcb.dir == USIM_DIRECT)
		reg |= SIM_CONF_Direct;
	else
		reg |= SIM_CONF_InDirect;
	
	if(KAL_TRUE == usim_dcb.ts_hsk_en)
	{
		reg |= (SIM_CONF_TXHSK | SIM_CONF_RXHSK);
      SIM_SetRXRetry(1);
	   SIM_SetTXRetry(1);		
	}
	else
	{
      SIM_SetRXRetry(0);
	   SIM_SetTXRetry(0);		
	}	
	DRV_WriteReg(SIM_CONF,reg);
	
	SIM_FIFO_Flush();
	SIM_SetRXTIDE(2);	// generate a interrupt while TS byte and T0 is received
	DRV_WriteReg(SIM_IRQEN,USIM_IRQEN_ATR|SIM_STS_RXERR);
	reg = DRV_Reg(SIM_STS);	
	usim_dcb.main_state = ACTIVATION_STATE;
	usim_dcb.ev_status = USIM_NO_ERROR;
	if(usim_dcb.warm_rst == KAL_FALSE)
	{
		USIM_POW_ON();	
	}
	else
	{
		USIM_WRST();
		kal_sleep_task(10);
	}
	// go to usim_hisr of case RXTIDE, ATRERR, RXERR(parity error)
}
	
static void usim_lisr(void)
{
   IRQMask(IRQ_SIM_CODE);
   drv_active_hisr(DRV_USIM_HSIR_ID);
}
/*************************************************************************
* FUNCTION
*  usim_deactivation
*
* DESCRIPTION
*	1. deactivate the UICC card 
*	2. wait util the the deactivation is complete
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb.main_state
*
*************************************************************************/
static void usim_deactivation(void) 
{	
	/////dbg_print("usim_deactivation\r\n");

	if(DRV_Reg(SIM_CTRL)&SIM_CTRL_SIMON)
	{
		kal_uint32 i = 5;
		// before deactivate the SIM interface, turn on the clock first.
		DRV_Reg(SIM_CTRL) &= ~SIM_CTRL_HALT;
		while(i--);
		kal_set_eg_events(usim_dcb.event,0,KAL_AND);
	   DRV_WriteReg(SIM_IRQEN, SIM_IRQEN_SIMOFF);
	   DRV_Reg(SIM_CTRL) &= ~SIM_CTRL_SIMON;	   
	   USIM_WAIT_EVENT();
	   USIM_CLR_FIFO();
	   usim_dcb.main_state = DEACTIVATION_STATE;
	   if(usim_dcb.ev_status == USIM_POWER_OFF)
	   	usim_dcb.main_state = DEACTIVATION_STATE;
	   else 
	   	ASSERT(0);
	}
}
/*************************************************************************
* FUNCTION
*  usim_t1end_handler
*
* DESCRIPTION
*	1. it is called while t1end interrupt is generated.
*	2. there are two different states in this function: 
		CMD_TX_STATE: a complete block is sent to UICC
		CMD_RX_INF_STATE: a complete block is received from UICC 
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb.main_state
*
*************************************************************************/
static void usim_t1end_handler(void)
{	
	/////dbg_print("usim_t1end_handler ");
	switch(usim_dcb.main_state)
	{
		case CMD_TX_STATE:
			/////dbg_print("CMD_TX_STATE ");

			USIM_DMA_RX_TIDE();
			usim_dcb.dma_menu.addr = (kal_uint32)usim_dcb.dma_buffer; // (kal_uint32)usim_dcb.rx_buf+usim_dcb.rx_index;
			usim_dcb.dma_input.type = DMA_HWRX;
			usim_dcb.dma_input.count = USIM_DMA_MAX_SIZE;
			DMA_Config(usim_dcb.dma_port,&usim_dcb.dma_input,KAL_TRUE);
			if(usim_dcb.wtx == KAL_TRUE)
			{
				usim_dcb.wtx = KAL_FALSE;
				usim_set_timeout(usim_dcb.BWT * usim_dcb.wtx_m);
			}
			else
				usim_set_timeout(usim_dcb.BWT);
			usim_dcb.ev_status = USIM_NO_ERROR;
			usim_dcb.main_state = CMD_RX_STATE;
			DRV_WriteReg(SIM_IRQEN, (SIM_STS_EDCERR|SIM_STS_RXERR|SIM_STS_T1END|SIM_STS_OV|SIM_STS_TOUT)); 			
			break;
		case CMD_RX_STATE:
			{
				kal_uint8 len, pcb;
				kal_uint8 *dma_buffer = usim_dcb.dma_buffer;
				
				usim_set_timeout(0);
				DMA_Stop(usim_dcb.dma_port);	
				if(usim_dcb.ev_status == USIM_RX_INVALID)
				{
					// comes from EDC or parity error
					USIM_SET_EVENT();
					return;
				}
				// receive a complete block, except a S-block received, there still is one
				// parameter byte in the fifo
				usim_dcb.header_rx[T1_NAD_INDEX] = dma_buffer[T1_NAD_INDEX]; // NAD
				pcb = usim_dcb.header_rx[T1_PCB_INDEX] = dma_buffer[T1_PCB_INDEX]; // PCB
				len = usim_dcb.header_rx[T1_LEN_INDEX] = dma_buffer[T1_LEN_INDEX]; // LEN	
				/////dbg_print("CMD_RX_STATE (reveive a block!! len: %d)",len );

				if(len)
				{
					if(len == 1 && USIM_IS_SBLOCK(pcb))
					{
						usim_dcb.header_rx[T1_INF_INDEX] = dma_buffer[T1_INF_INDEX];
					}
					else
					{
						kal_mem_cpy(usim_dcb.rx_buf+usim_dcb.rx_index, &dma_buffer[T1_INF_INDEX], len);
					}
				}
				usim_dcb.ev_status = USIM_NO_ERROR;							
				USIM_SET_EVENT();
			}
			break;
	}
	/////dbg_print("\r\n");
}
static void usim_timeout_handler()
{
	/////dbg_print("usim_timeout_handler ");
	
	switch(usim_dcb.main_state)
	{
		case ATR_STATE:			
			/////dbg_print("ATR_STATE (timeout) should not go over here ");
			// may be optimized by parsing the content instead of using timeout.
			// read the remaining bytes of ATR
			{
				kal_uint32 count;
				
				count = DRV_Reg(SIM_COUNT);
				while(count--)
				{
					usim_dcb.ATR_data[usim_dcb.ATR_index++] = (kal_uint8)DRV_Reg(SIM_DATA);		
				}
            usim_dcb.ev_status = USIM_ATR_REC;	
            USIM_SET_EVENT();
			}			
			break;
		case CLK_STOPPING_STATE:
			/////dbg_print("CLK_STOPPING_STATE ");
			{
				kal_bool level;

				usim_set_timeout(0);
				usim_dcb.main_state = CLK_STOPPED_STATE;
				if(usim_dcb.clock_stop_type == CLOCK_STOP_HIGH )				
					level = KAL_TRUE;
				else
					level = KAL_FALSE;	
				SIM_Idle(level);				
				SIM_DisAllIntr();
				#if defined(USIM_DEBUG)
				end = get_duration_tick(start);
				/////dbg_print("clock stoped!! duration = %d", end);
				#endif
			}
			break;
		case CLK_STOPPED_STATE:
			/////dbg_print("CLK_STOPPED_STATE ");
			{
				usim_dcb.main_state = MAIN_CMD_READY_STATE;
				usim_dcb.ev_status = USIM_NO_ERROR;
				USIM_SET_EVENT();
				/////dbg_print("clock start!!");
			}
			break;
		default:
			/////dbg_print("default:");
			DMA_Stop(usim_dcb.dma_port);	
			usim_dcb.ev_status = USIM_BWT_TIMEOUT;
			USIM_SET_EVENT();
	}
	
	/////dbg_print("\r\n");
}

static void usim_hisr(void)
{
	kal_uint32 int_status;

	int_status = DRV_Reg(SIM_STS);
	usim_dcb.int_status = int_status;	
	PUSH_INT(int_status);
	/////dbg_print("usim_hisr int:%x\r\n",int_status);

	if(int_status & SIM_STS_RXERR )
	{
		/////dbg_print("parity error \r\n");
		usim_set_timeout(0);
		usim_dcb.ev_status = USIM_RX_INVALID;
		if(usim_dcb.main_state ==  ACTIVATION_STATE)
		{
			SIM_DisAllIntr();
			USIM_SET_EVENT();
			goto end_of_hisr;
		}
		// wait t1end interrupt
	}
	
	if(int_status& SIM_STS_EDCERR)
	{	
		/////dbg_print("EDC error \r\n");
		usim_set_timeout(0);
		usim_dcb.ev_status = USIM_RX_INVALID;		
	}
	if(int_status& SIM_STS_TOUT)
	{
		usim_timeout_handler();
		goto end_of_hisr;
	}	
	if(int_status & SIM_STS_T1END)
	{
		usim_t1end_handler();
	}	
	if(int_status & SIM_STS_RX)
	{
		usim_rx_handler(int_status);
	}	
	if(int_status & SIM_STS_SIMOFF)
	{
		usim_dcb.ev_status = USIM_POWER_OFF;
		USIM_SET_EVENT();
		goto end_of_hisr;
	}
	if(int_status & SIM_STS_TXERR || int_status & SIM_STS_OV)
	{
		ASSERT(0);
	}	
	if(int_status & SIM_STS_NATR)
	{
		usim_dcb.ev_status = USIM_NO_ATR;
		USIM_SET_EVENT();
	}
	
end_of_hisr:
	
	IRQClearInt(IRQ_SIM_CODE);
	IRQUnmask(IRQ_SIM_CODE);   
	
}

/*************************************************************************
* FUNCTION
*  usim_rx_handler
*
* DESCRIPTION
*	1. It is called byt usim_hisr
*	2. It is called while RXTIDE interrupt is triggerred
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static void usim_rx_handler(kal_uint32 int_status)
{
	/////dbg_print("usim_rx_handler ");
	
	switch(usim_dcb.main_state)
	{
		case ACTIVATION_STATE:
			/////dbg_print("ACTIVATION_STATE ");		
			{
				kal_uint8 TS,T0,count;

				TS = DRV_Reg(SIM_DATA);
				/////dbg_print("TS = %x ", TS);
				if(TS == 0x3B || TS == 0x3F)
				{					
					usim_set_timeout(INIT_WWT_T0);
					USIM_ENABLE_TXRX_HANSHAKE();					
					SIM_SetRXRetry(USIM_RETRY);
					SIM_SetTXRetry(USIM_RETRY);    
					count = 0;
					T0 = DRV_Reg(SIM_DATA);
					usim_dcb.hist_index = T0&0xf; // use to contain the length of historical char (temperary)
					USIM_CAL_TD_COUNT(T0, count);
					if((T0 & TDMask) == NULL)
					{
						count += usim_dcb.hist_index;
						if(count >= SIM_TOTAL_FIFO_LEN)
						{
							usim_dcb.abort = KAL_TRUE;	// for temp usage (separate two times)
							count -= 6;					
						}
						usim_dcb.resync = KAL_TRUE; // for temp usage (last time)								
					}
					else
						count++;
					if(count == 0)
					{
						usim_dcb.ev_status = USIM_ATR_REC;
						USIM_SET_EVENT();
					}
					else
					{
						usim_dcb.rx_size = count+1;	// for temp usage (index to TD byte)
						SIM_SetRXTIDE(count); 
						DRV_WriteReg(SIM_IRQEN,USIM_IRQEN_NORMAL);
						usim_dcb.ev_status = USIM_NO_ERROR;
					}
					
					usim_dcb.main_state = ATR_STATE;
					usim_dcb.ATR_index = 0;
					usim_dcb.ATR_data[usim_dcb.ATR_index++] = TS;
					usim_dcb.ATR_data[usim_dcb.ATR_index++] = T0;
				}	
				else
				{
					kal_uint16 reg;
					
					usim_dcb.ev_status = USIM_TS_INVALID;
					SIM_DisAllIntr(); // prevent the following ATR bytes trigger RX interrupt
					reg = DRV_Reg(SIM_STS);		
				}		
				USIM_SET_EVENT();
			}			
			break;
		case ATR_STATE:			
			{	// receive all ATR data without timeout to indicate
				kal_uint32 count;
				kal_uint8 TD;
				
				count = DRV_Reg(SIM_COUNT);					
				/////dbg_print("ATR_STATE : %d ",count);				
				while(count--)
					usim_dcb.ATR_data[usim_dcb.ATR_index++] = (kal_uint8)DRV_Reg(SIM_DATA);
				if(usim_dcb.abort == KAL_TRUE)
				{
					usim_dcb.abort = KAL_FALSE;
					SIM_SetRXTIDE(6); 
					usim_dcb.resync = KAL_TRUE;
					break;
				}
				if(usim_dcb.resync == KAL_FALSE)
				{
					TD = usim_dcb.ATR_data[usim_dcb.rx_size];
					/////dbg_print(", TD = %x ,%d", TD,usim_dcb.rx_size);
					count = 0;
					USIM_CAL_TD_COUNT(TD, count);			
					if((TD & TDMask) == NULL)
					{
						count += usim_dcb.hist_index;
						if(count >= SIM_TOTAL_FIFO_LEN)
						{
							// usim_dcb.rx_index = count; // for temp usage (total ATR len)
							usim_dcb.abort = KAL_TRUE;	// for temp usage (separate two times)
							count -= 6;					
						}
						usim_dcb.resync = KAL_TRUE; // for temp usage (last time)								
					}
					else
						count++;				
					usim_dcb.rx_size += (count);	// for temp usage (index to TD byte)
					SIM_SetRXTIDE(count); 					
				}
				else
				{
					usim_set_timeout(0);
					/////dbg_print("\r\n!! all ATR received \r\n");
					usim_dcb.hist_index = 0;
					usim_dcb.rx_size = 0;					
					usim_dcb.resync = KAL_FALSE;
					usim_dcb.abort = KAL_FALSE;
	            usim_dcb.ev_status = USIM_ATR_REC;
	            USIM_SET_EVENT();					
				}				
			}
			break;
		case PTS_STATE:
			SIM_DisAllIntr();
			usim_dcb.ev_status = USIM_NO_ERROR;
			USIM_SET_EVENT();
			break;			
	}
}

/*************************************************************************
* FUNCTION
*  usim_send_block
*
* DESCRIPTION
*	1. sending a block to UICC, with header in usim_dcb.header_tx
*	2. if len > 0 then using DMA to transfer data from tx buffer to the fifo of sim
		interface.
	3. after a complete block is sent, T1END is generated
	4. after that, three bytes of received block header will come into rx fifo
*
* PARAMETERS
	adrs: tx buffer address
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static void usim_send_block(kal_uint8 *adrs )
{
	kal_uint32 len, pcb;
	kal_uint8 *header;
	usim_dcb_struct *dcb = &usim_dcb;

	header = dcb->header_tx;
	dcb->main_state = CMD_TX_STATE;
	USIM_CLR_FIFO();
	// write header into fifo
	len = header[T1_LEN_INDEX];	
	pcb = header[T1_PCB_INDEX];
	/////dbg_print("usim_send_block [00][%x][%x]\r\n",pcb, len);
	#if defined(USIM_DEBUG)
	{
		kal_uint32 i;
		/////dbg_print("tx:");
		if(USIM_IS_SBLOCK(pcb)&& len ==1)
		{
			/////dbg_print(" %x",header[T1_INF_INDEX]);
		}
		else
		{
			for(i=0;i<len;i++)
			{
				/////dbg_print(" %x",adrs[i]);
			}
		}
		/////dbg_print("\r\n");
	}
	#endif
	
	DRV_WriteReg(SIM_DATA, header[T1_NAD_INDEX]);
	DRV_WriteReg(SIM_DATA, pcb);
	DRV_WriteReg(SIM_DATA, len);
	DRV_WriteReg(SIM_IMP3, len);
	// transfer by DMA if the count > 12, otherwise by MCU
	SIM_SetTXTIDE(1);
	if(len > 12)
	{
		dcb->dma_menu.addr = (kal_uint32)adrs;
		dcb->dma_input.type = DMA_HWTX;
		dcb->dma_input.count = (kal_uint16)len;
		USIM_TX_START_T1();
		DMA_Config(dcb->dma_port,&dcb->dma_input,KAL_TRUE);
	}
	else if(USIM_IS_SBLOCK(pcb)&& len ==1)
	{
		DRV_WriteReg(SIM_DATA, header[T1_INF_INDEX]);
		USIM_TX_START_T1();
	}
	else
	{
		kal_uint32 i;
		
		for(i=0;i<len;i++)
			DRV_WriteReg(SIM_DATA, adrs[i]);
		USIM_TX_START_T1();
	}
	DRV_WriteReg(SIM_IRQEN, SIM_STS_T1END);
}
/*
1. send S blocks of request or response.
2. if sending request, check if the response is correct.
3. if sending response,
4. EDC will be generated(tx) and removed(rx) by T1 controller

id: PCB of the S block
param: parameter of the S-block

*/
static usim_status_enum usim_send_s_block(usim_s_block_id_enum id, kal_uint8 param)	
{
	kal_uint8 *tx_buf, *rx_buf, len, t;
	kal_bool is_resp;
	kal_uint32 i;
	usim_dcb_struct *dcb = &usim_dcb;

	/////dbg_print("usim_send_s_block id:%x, param:%d \r\n", id, param);
	tx_buf = dcb->header_tx;
	rx_buf = dcb->header_rx;
	tx_buf[T1_NAD_INDEX] = USIM_NAD_DEFAULT;
	tx_buf[T1_PCB_INDEX] = id;
	is_resp = ((id & PCB_S_RESP) != 0);
	dcb->cmd_state = (is_resp)?(S_BlOCK_RESP_TX):(S_BlOCK_REQ_TX);
	if(id==IFS_REQ || id==WTX_REQ || id==IFS_RESP|| id==WTX_RESP )
	{
		len = 4;
		tx_buf[T1_LEN_INDEX] = 1;
	}
	else
	{
		len = 3;
		tx_buf[T1_LEN_INDEX] = 0;
	}
   tx_buf[T1_INF_INDEX] = param;
   dcb->retry = 0;

   while(dcb->retry++ < 3)
   {
		usim_send_block(&param);
		USIM_WAIT_EVENT();
		if(usim_dcb.ev_status == USIM_NO_ERROR)
		{
			if(!is_resp)
			{
				for(t=0,i=0;i<len;i++)
					t += rx_buf[i]^tx_buf[i];
				if(t != PCB_S_RESP)
					continue;
			}			
			break;
		}
   }
   if(dcb->retry == 4)
   {
   	usim_deactivation();
   }
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
	#endif
	
	return USIM_NO_ERROR;	
	
}

/*************************************************************************
* FUNCTION
*  usim_rx_block_handler
*
* DESCRIPTION
*	1. process the received block including I, R, and S blocks
*	2. prepare the next sending block header in the usim_dcb.header_tx
*
* PARAMETERS
	adrs: address of the data buffer
	
* RETURNS
	KAL_TRUE: a valid block is received
	KAL_FALSE: an invalid block is received
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static kal_bool usim_rx_block_handler(kal_uint32 *adrs)
{
	kal_uint8 pcb, len;

	if(usim_dcb.header_rx[T1_NAD_INDEX] != 0)
	{
		/////dbg_print("(invlid block) invalid NAD\r\n");
		return KAL_FALSE;
	}
	pcb = usim_dcb.header_rx[T1_PCB_INDEX];
	len = usim_dcb.header_rx[T1_LEN_INDEX];
	if(len > usim_dcb.ifsd) // 0 <= len <= IFSC (max 254)
		return KAL_FALSE;
	#if defined(USIM_DEBUG)
	{	
		/////dbg_print("rx:%x %x %x",usim_dcb.header_rx[0],usim_dcb.header_rx[1],usim_dcb.header_rx[2]);
		if(USIM_IS_SBLOCK( usim_dcb.header_rx[1])){
			/////dbg_print(" %x \r\n",usim_dcb.rx_buf[3]);
		}
	
	}
	#endif
	// USIM_INV_N(usim_dcb.ns);
	if(USIM_IS_IBLOCK(pcb))
	{	// I-block
		/////dbg_print("received a I-block\r\n");
		if(pcb & PCB_I_RFU)
		{
			/////dbg_print("(invlid block) error PCB \r\n");
			return KAL_FALSE;
		}	
		#if defined(USIM_DEBUG)
		{
			kal_uint32 i;
			for(i=0;i<len;i++)
			{
				/////dbg_print(" %x",usim_dcb.rx_buf[usim_dcb.rx_index+i]);
			}
			/////dbg_print("\r\n");
		}
		#endif
		if((pcb & PCB_I_SEQ) != usim_dcb.nr)
		{
			/////dbg_print("(invlid block) receive sequence err\r\n");
			return KAL_FALSE;
		}
		if(usim_dcb.header_rx[T1_LEN_INDEX] > usim_dcb.ifsd)
		{
			/////dbg_print("(invalid block) receive lenght > IFSD \r\n");
			return KAL_FALSE;
		}		
		if(usim_dcb.header_tx[T1_PCB_INDEX]== RESYNC_REQ)
		{
			// must receive a S RESP not any other block
			/////dbg_print("(invalid block) must receive a S RESP not any other block \r\n");
			return KAL_FALSE;			
		}
			
		usim_dcb.tx_chain = KAL_FALSE;
		USIM_INV_N(usim_dcb.nr);
		usim_dcb.retry = 0;
		usim_dcb.tx_size -= usim_dcb.header_tx[T1_LEN_INDEX];
		usim_dcb.tx_index += usim_dcb.header_tx[T1_LEN_INDEX]; 		
		usim_dcb.rx_size  -= usim_dcb.header_rx[T1_LEN_INDEX]; 		
		usim_dcb.rx_index += usim_dcb.header_rx[T1_LEN_INDEX];
		if(pcb & PCB_I_M)
		{
			// a chaining I-block received send a R-block
			usim_dcb.rx_chain = KAL_TRUE;
			/////dbg_print("chaining...\r\n");
			USIM_MAKE_R_BLOCK(PCB_R_STATUS_OK);
		}
		else
		{	// command complete
			/////dbg_print("command complete!!\r\n");
			usim_dcb.rx_chain = KAL_FALSE;
			usim_dcb.retry = 0;
			usim_dcb.main_state = MAIN_CMD_READY_STATE;
		}				
	}
	else if(USIM_IS_RBLOCK(pcb))
	{	// R-block
		/////dbg_print("received a R-block\r\n");
		if(usim_dcb.header_tx[T1_PCB_INDEX]== RESYNC_REQ)
		{
			// must receive a S RESP not any other block
			/////dbg_print("(invalid block) must receive a S RESP not any other block \r\n");
			return KAL_FALSE;			
		}
		if(len)
		{
			/////dbg_print("(invalid block) R block of len = %d \r\n", len);
			return KAL_FALSE;
		}						
		if(usim_dcb.tx_chain && (pcb & PCB_R_STATUS) == 0)
		{	// receive a err free R block
			if(((pcb & PCB_R_SEQ)<<2) == usim_dcb.ns )
			{	// send next chaining block				
				if(usim_dcb.abort == KAL_TRUE)
				{
					usim_dcb.main_state = MAIN_CMD_READY_STATE;
				}
				else if(usim_dcb.tx_size != 0)
				{
					// normal chaining case
					usim_dcb.retry = 0;
					usim_dcb.tx_size -= usim_dcb.ifsc;
					usim_dcb.tx_index += usim_dcb.ifsc; 			
					*adrs =(kal_uint32)(usim_dcb.tx_buf+usim_dcb.tx_index);
					if(usim_dcb.tx_size <= usim_dcb.ifsc)
					{
						pcb = 0;
						len = usim_dcb.tx_size;
						usim_dcb.cmd_state = I_BLOCK_M0_TX;
					}
					else	// txSize > IFSC
					{
						pcb = PCB_I_M;
						len = usim_dcb.ifsc;
						usim_dcb.cmd_state = I_BLOCK_M1_TX;
					}
					if(usim_dcb.ns) 
						pcb |= PCB_I_SEQ;
					usim_dcb.header_tx[T1_PCB_INDEX] = pcb;
					usim_dcb.header_tx[T1_LEN_INDEX] = len;	
					usim_dcb.header_tx_bak[T1_PCB_INDEX] = pcb;
					usim_dcb.header_tx_bak[T1_LEN_INDEX] = len;	
					USIM_INV_N(usim_dcb.ns);
					}
			}
			else
			{	// sending the previous I block again				
				usim_dcb.retry++;
				usim_dcb.cmd_state = usim_dcb.cmd_state_bak;
				usim_dcb.header_tx[T1_PCB_INDEX] = usim_dcb.header_tx_bak[T1_PCB_INDEX];
				usim_dcb.header_tx[T1_LEN_INDEX] = usim_dcb.header_tx_bak[T1_LEN_INDEX];				
			}
		}
		else
		{
			// error handling R-Block received
			if((pcb & PCB_R_SEQ)<<2 != (usim_dcb.ns) )
			{	// previous sending sequence
				usim_dcb.retry++;
				usim_dcb.cmd_state = usim_dcb.cmd_state_bak;
				usim_dcb.header_tx[T1_PCB_INDEX] = usim_dcb.header_tx_bak[T1_PCB_INDEX];
				usim_dcb.header_tx[T1_LEN_INDEX] = usim_dcb.header_tx_bak[T1_LEN_INDEX];
			}
			else
			{				
				// next sending sequence
				// send the previous R-block again
				usim_dcb.retry = 0;
				return KAL_FALSE;
			}			
		}		
	}
	else if(USIM_IS_SBLOCK(pcb))
	{	// S-block(REQ)
		/////dbg_print("receive S-block(%x)\r\n",pcb);
		if(USIM_IS_RESP(pcb))
		{	// response (only resync response block will be received.)
			/////dbg_print("receive RESP block!\r\n");
			if(pcb == RESYNC_RESP && usim_dcb.header_tx[T1_PCB_INDEX]== RESYNC_REQ )
			{
				if(len != 0)
				{
					/////dbg_print("Invalid len of RESYNC");
					return KAL_FALSE;
				}
				// resync complete (the card is reset to the initial state)
				usim_dcb.main_state = MAIN_CMD_READY_STATE;
				usim_dcb.ns = 0;
				usim_dcb.nr = 0;
				usim_dcb.resync = KAL_TRUE;
				usim_dcb.retry = 0;
				// usim_dcb.ifsc = USIM_IFSC_DEFAULT;
			}
			else
			{
				/////dbg_print("receive a error S RESP,[%x]\r\n", pcb);
				return KAL_FALSE;			
			}
		}
		else
		{ // receiving a S-block of request
			if(usim_dcb.header_tx[T1_PCB_INDEX]== RESYNC_REQ)
			{
				// must receive a S RESP not any other block
				/////dbg_print("(invalid block) must receive a S RESP not any other block \r\n");
				return KAL_FALSE;			
			}
		
			usim_dcb.cmd_state = S_BlOCK_RESP_TX;
			usim_dcb.header_tx[T1_PCB_INDEX]= pcb|PCB_S_RESP;
			usim_dcb.header_tx[T1_LEN_INDEX]= len;		
			if(len)
			{
				usim_dcb.header_tx[T1_INF_INDEX] = usim_dcb.header_rx[T1_INF_INDEX];
			}
			switch(pcb)
			{
				case RESYNC_REQ:
					/////dbg_print("(ERR) receive RESYNC_REQ\r\n");
					return KAL_FALSE;
					break;
				case IFS_REQ:	
					/////dbg_print("receive IFS_REQ\r\n");					
					if(len != 1)
						return KAL_FALSE;
					usim_dcb.ifsc = usim_dcb.header_rx[T1_INF_INDEX];
					break;
				case ABORT_REQ:
					/////dbg_print("receive ABORT_REQ\r\n");
					if(len != 0)
						return KAL_FALSE;	
					usim_dcb.retry = 0;
					usim_dcb.abort = KAL_TRUE;
					break;
				case WTX_REQ:
					if(len != 1)
						return KAL_FALSE;
					usim_dcb.retry = 0;
					/////dbg_print("receive WTX_REQ\r\n");
					// re-start the BWT( according to the spec, the timer should be restart after 
					// the WTX response has been sent.
					usim_dcb.wtx = KAL_TRUE;
					usim_dcb.wtx_m = usim_dcb.header_rx[T1_INF_INDEX];;
					break;
				default:
					return KAL_FALSE;
			}
		}
	}
	else
	{
		/////dbg_print("Invalid PCB \r\n");
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}
/*************************************************************************
* FUNCTION
*  usim_err_handler
*
* DESCRIPTION
*	1. send R block to UICC to indicate the previous block is error at previous two retry. 
*	2. send S(RESYN) to UICC to recover the errors.
*	3. deactivate the UICC 
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*	usim_dcb.retry
*
*************************************************************************/
static void usim_err_handler(void)
{
	// send R block
	usim_dcb.retry++;
	/////dbg_print("usim_err_handler %d",usim_dcb.retry);	
	USIM_CLR_FIFO();
	if(usim_dcb.retry < 3)
	{
		/////dbg_print("send R block!\r\n");
		{
			if(usim_dcb.ev_status == USIM_RX_INVALID)
			{
				USIM_MAKE_R_BLOCK(PCB_R_STATUS_EDC_ERR);	
			}
			else
			{
				USIM_MAKE_R_BLOCK(PCB_R_STATUS_OTHER_ERR);	
			}	
		}
	}
	else if(usim_dcb.retry <  6)
	{
		// next level error handling => resync		
		/////dbg_print("send RESYNC REQ !\r\n");
		USIM_MAKE_S_RESYNC();		
	}
	else
	{
		// deactivate
		usim_deactivation();
	}
}

/*************************************************************************
* FUNCTION
*  usim_send_i_block
*
* DESCRIPTION
*	1. send I block to UICC with length of ifsc including case 1~4.
*
* PARAMETERS
*	1. txData: tx buffer containing command header optional with tx data.
*	2. txSize: length of the tx data
*	3. rxData: rx buffer (must inluding two extra one for sw1 and sw2)
*	4. rxSize: length of the rx data except sw1|sw2
*	
* RETURNS
*	status bytes(SW1|SW2), 0 means a physical error.
*	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static sim_status usim_send_i_block(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize)
{	
	kal_uint8 pcb, len;
	kal_uint32 count,adrs;
	usim_status_enum status;
	kal_uint16 sw;

	/////dbg_print("\r\n\r\n @@@@ usim_send_i_block @@@@\r\n");
	DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
	if(usim_dcb.clock_stop_en == KAL_TRUE)
	{
		if(usim_dcb.main_state == CLK_STOPPING_STATE)
		{
			usim_set_timeout(0);
			usim_dcb.main_state = MAIN_CMD_READY_STATE;
		}
		else if(usim_dcb.main_state == CLK_STOPPED_STATE)
		{
			DRV_Reg(SIM_CTRL) &= ~SIM_CTRL_HALT;	
			usim_set_timeout(usim_dcb.etu_of_700);
			DRV_WriteReg(SIM_IRQEN, SIM_IRQEN_TOUT);
			USIM_WAIT_EVENT();			
		}
	}
	
	do
	{
		status = USIM_NO_ERROR;
		usim_dcb.tx_index = 0;
		usim_dcb.rx_index = 0;
		usim_dcb.tx_buf = txData;
		if(rxData == NULL)
			usim_dcb.rx_buf = usim_dcb.sw;	
		else
			usim_dcb.rx_buf = rxData;
		usim_dcb.tx_size = *txSize;			
		usim_dcb.rx_size = *rxSize+2; // include SW1, SW2 
		usim_dcb.retry = 0;
		usim_dcb.abort = KAL_FALSE;
		usim_dcb.resync = KAL_FALSE;
		usim_dcb.rx_chain = KAL_FALSE;
		
		count = *txSize;
		adrs =(kal_uint32)usim_dcb.tx_buf;
		if(count <= usim_dcb.ifsc)
		{
			pcb = 0;
			len = count;
			usim_dcb.tx_chain = KAL_FALSE;
			usim_dcb.cmd_state = I_BLOCK_M0_TX;
		}
		else	// txSize > IFSC
		{
			pcb = PCB_I_M;
			len = usim_dcb.ifsc;
			usim_dcb.tx_chain = KAL_TRUE;
			usim_dcb.cmd_state = I_BLOCK_M1_TX;
		}
		if(usim_dcb.ns) 
			pcb |= PCB_I_SEQ;
		
		usim_dcb.cmd_state_bak = usim_dcb.cmd_state;	
		usim_dcb.header_tx[T1_NAD_INDEX] = USIM_NAD_DEFAULT;
		usim_dcb.header_tx[T1_PCB_INDEX] = pcb;
		usim_dcb.header_tx_bak[T1_PCB_INDEX] = pcb;
		usim_dcb.header_tx[T1_LEN_INDEX] = len;		
		usim_dcb.header_tx_bak[T1_LEN_INDEX] = len;
		USIM_INV_N(usim_dcb.ns);
		
		while(1)
		{
			usim_send_block((kal_uint8*)adrs);
			USIM_WAIT_EVENT();			
			if(usim_dcb.ev_status == USIM_NO_ERROR)
			{	// a complete block is received
				if(usim_rx_block_handler(&adrs)== KAL_FALSE)
					usim_err_handler();
			}
			else 
			{
				usim_err_handler();
			}
			if(usim_dcb.main_state == MAIN_CMD_READY_STATE)
			{
				// command complete
				*rxSize = usim_dcb.rx_index;
				break;
			}
		}
		
		if(usim_dcb.abort == KAL_TRUE)
		{
			status = USIM_DATA_ABORT;
			break;
		}
		if(usim_dcb.main_state == DEACTIVATION_STATE)
		{
			status =  USIM_DEACTIVATED;
			break;
		}
	}while(usim_dcb.resync == KAL_TRUE);

	if(usim_dcb.clock_stop_en == KAL_TRUE)
	{
		usim_dcb.main_state = CLK_STOPPING_STATE;		
		usim_set_timeout(usim_dcb.etu_of_1860);
		DRV_WriteReg(SIM_IRQEN, SIM_IRQEN_TOUT);
		#if defined(USIM_DEBUG)
		start = get_current_time();
		#endif
	}
	usim_dcb.status = status;
	if(status != USIM_NO_ERROR)
		return STATUS_FAIL;
	// the *rxsize include the sw1 and sw1, the upper layer should prepare it.
	*rxSize -= 2;
	if(rxData == NULL)
		return (kal_uint16)((usim_dcb.sw[0]<<8)|(usim_dcb.sw[1]));
	sw = (rxData[*rxSize]<<8)|(rxData[*rxSize+1]);
	return sw;

}

/*************************************************************************
* FUNCTION
*  usim_update_sim_to_ready
*
* DESCRIPTION
*	1. update the ATR informations from usim_dcb into SimCard
*		to make sim(t=0) driver work..
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*	SimCard
*	TOUTValue
*
*************************************************************************/
void static usim_update_sim_to_ready(void)
{
	extern kal_uint32 TOUTValue;
	
	SimCard.app_proto = usim_dcb.app_proto;
	SimCard.State = SIM_PROCESSCMD;
	SimCard.Data_format = usim_dcb.dir;
	if(usim_dcb.power == CLASS_B_30V)
		SimCard.Power = SIM_30V;
	else if(usim_dcb.power == CLASS_C_18V)
		SimCard.Power = SIM_18V;
	SimCard.SIM_ENV = usim_dcb.sim_env;
	SimCard.Speed = usim_dcb.speed;
	SimCard.clkStop = usim_dcb.clock_stop_en;
	if(usim_dcb.clock_stop_type == CLOCK_STOP_HIGH)
		SimCard.clkStopLevel = KAL_TRUE;
	else if(usim_dcb.clock_stop_type == CLOCK_STOP_LOW)
		SimCard.clkStopLevel = KAL_FALSE;
	SimCard.sim_card_speed = usim_dcb.card_speed;
	TOUTValue = usim_dcb.WWT>>2;
}
/*************************************************************************
* FUNCTION
*  L1usim_Init
*
* DESCRIPTION
*	1. It is the initialization function of usim driver
*	2. It shall be called only once.
*	3. It gets the customization data of borad-supported voltage.
*	4. It initialize the structure of usim control block .
*	5. It get a GPT handler, a dma port,and register lisr, hisr, a event groug 
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
void L1usim_Init(void)	
{	
	if(usim_dcb.warm_rst == KAL_FALSE)
	{
		usim_dcb.sim_env = SIM_GetCurrentEnv();
		usim_dcb.dir = USIM_DIRECT;
		usim_dcb.speed = SPEED_372;
		usim_dcb.clock_stop_en = KAL_FALSE;
		usim_dcb.clock_stop_type = CLOCK_STOP_UNKONW;
		usim_dcb.phy_proto = T1_PROTOCOL;
		usim_dcb.warm_rst = KAL_FALSE;
		usim_dcb.rx_size = 0;
		usim_dcb.rx_buf = NULL;
		usim_dcb.tx_size = 0;
		usim_dcb.tx_buf = NULL;
		usim_dcb.Fi = FI_DEFAULT;	
		usim_dcb.Di = DI_DEFAULT;
		usim_dcb.header_tx[0] = NAD;
		usim_dcb.ts_hsk_en = KAL_TRUE;
		usim_dcb.WWT = INIT_WWT_T0;
		usim_dcb.etu_of_1860 = (1860/32);
		usim_dcb.etu_of_700 = (700/32);
		usim_dcb.present = KAL_TRUE;
					
		// note: MT6218B half channel can't work, use full channel insteadly.
		#if !defined(MT6218B) && !defined(MT6218)
		if(usim_dcb.dma_port == 0)
			usim_dcb.dma_port = DMA_GetChannel(DMA_SIM);
		usim_dcb.dma_menu.TMOD.burst_mode = KAL_FALSE;
		usim_dcb.dma_menu.master = DMA_SIM;
		usim_dcb.dma_menu.addr = NULL;
		usim_dcb.dma_input.type = DMA_HWTX;
		usim_dcb.dma_input.size = DMA_BYTE;
		usim_dcb.dma_input.callback = NULL;
		usim_dcb.dma_input.menu = &usim_dcb.dma_menu;
		#endif
		
		if(usim_dcb.event == NULL)
			usim_dcb.event = kal_create_event_group("USIM_EV");
		DRV_Register_HISR(DRV_USIM_HSIR_ID, usim_hisr);
		if(usim_dcb.gpt_handle == NULL)
			GPTI_GetHandle(&usim_dcb.gpt_handle);
		IRQSensitivity(IRQ_SIM_CODE,LEVEL_SENSITIVE);
		IRQUnmask(IRQ_SIM_CODE);
	}
	
	// reset these value no matter cold or warm reset
	usim_dcb.main_state = ACTIVATION_STATE;
	usim_dcb.ifsc = USIM_IFSC_DEFAULT;
	usim_dcb.ifsd = USIM_IFSD_DEFAULT;
	usim_dcb.ns = 0;
	usim_dcb.nr = 0;
	IRQ_Register_LISR(IRQ_SIM_CODE, usim_lisr,"USIM_Lisr");	
}

/*************************************************************************
* FUNCTION
*  L1sim_Reset
*
* DESCRIPTION
* 1. Reset the sim card and parse the ATR and perform the PTS(optional) and 
		enter the command ready mode
* 2. First time it is a cold reset, second it's a warm reset
* 3. If the ExpectVolt equal to the current volt, perform a warm reset. 
		Otherwise perform a cold reset.
* 4. Finally, S-block of IFS request is sent the UICC to configure the IFSD  
*
* PARAMETERS
	1. ExpectVolt: application layer give a expected power class

* RETURNS
*  USIM_VOLT_NOT_SUPPORT: Valid TS is received
*  KAL_FALSE: Valid TS is not received, card is not present or not supported
*
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
usim_status_enum L1usim_Reset(usim_power_enum ExpectVolt, usim_power_enum *ResultVolt)
{
	kal_uint32 retry;

	/////dbg_print("L1usim_Reset\r\n");

	DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);

	if(usim_dcb.clock_stop_en == KAL_TRUE && usim_dcb.warm_rst == KAL_TRUE &&
		usim_dcb.phy_proto == T1_PROTOCOL)
	{
		if(usim_dcb.main_state == CLK_STOPPING_STATE)
		{
			usim_set_timeout(0);
			usim_dcb.main_state = MAIN_CMD_READY_STATE;
		}
		else if(usim_dcb.main_state == CLK_STOPPED_STATE)
		{
			DRV_Reg(SIM_CTRL) &= ~SIM_CTRL_HALT;			
			usim_set_timeout(usim_dcb.etu_of_700);
			DRV_WriteReg(SIM_IRQEN, SIM_IRQEN_TOUT);
			USIM_WAIT_EVENT();			
		}
	}	
	L1usim_Init();
	if(usim_check_input_volt(ExpectVolt) == KAL_FALSE)
		return USIM_VOLT_NOT_SUPPORT; 	
	// 1. Activate the USIM interface
	SIM_DisAllIntr();	
	DMA_Stop(usim_dcb.dma_port);
	usim_set_speed(SPEED_372);
	usim_set_timeout(INIT_WWT_T0);
	/*
	if(TS_HSK_ENABLE)
	{
		SIM_SetRXRetry(7);
		SIM_SetTXRetry(7);
		USIM_ENABLE_TXRX_HANSHAKE();		
	}
	*/
	// if corrupted ATRs are received, retry 3 times
	for(retry = 0; retry < ATR_RETRY; retry++)
	{
		kal_set_eg_events(usim_dcb.event,0,KAL_AND);
		if(usim_select_power(ExpectVolt) == KAL_FALSE)
		{
			if(usim_dcb.warm_rst == KAL_TRUE)
				return USIM_ATR_ERR;
			if( usim_dcb.ts_hsk_en == KAL_TRUE)
				usim_dcb.ts_hsk_en = KAL_FALSE;
			else
				return USIM_NO_INSERT;
			//continue;
		}
		else if (usim_process_ATR() == USIM_NO_ERROR) 			
				break;
				
		ExpectVolt = usim_dcb.power;		
	}
	if(retry == 3)
		return USIM_ATR_ERR;
	*ResultVolt = usim_dcb.power;
	// 3. Process PTS
	//if(usim_dcb.reset_mode == USIM_RESET_NEGOTIABLE)
	{
		usim_process_PTS();
		// 4. Configure the IFSD	
		if(usim_dcb.phy_proto == T1_PROTOCOL)
		{
			if( usim_send_s_block(IFS_REQ, USIM_IFSD_MAX) == USIM_NO_ERROR)
				usim_dcb.ifsd = USIM_IFSD_MAX;
		}
	}
	// NOTE: can't turn off the PDN bit of SIM interface over, it will cause
	// the SIM behavior abnormal. 
	usim_dcb.main_state = MAIN_CMD_READY_STATE;
	usim_dcb.cmd_state = USIM_CMD_READY;
	kal_set_eg_events(usim_dcb.event,0,KAL_AND);
	return USIM_NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  L1usim_PowerOff
*
* DESCRIPTION
*	1. perform the deactivation to UICC
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
void L1usim_PowerOff(void)
{
	DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);	
	usim_deactivation();
	DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);	
}
/*************************************************************************
* FUNCTION
*  L1usim_Get_Card_Info
*
* DESCRIPTION
*	get the card informations
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
void L1usim_Get_Card_Info(sim_info_struct *info)
{
	ASSERT(usim_dcb.main_state >= ATR_STATE);
	info->power = usim_dcb.power;	
	info->speed = usim_dcb.speed;	
	info->clock_stop = usim_dcb.clock_stop_type;
	info->app_proto = usim_dcb.app_proto;
	info->phy_proto = usim_dcb.phy_proto;
	info->T0_support = usim_dcb.T0_support;
	info->T1_support = usim_dcb.T1_support;
	info->hist_index = usim_dcb.hist_index;
	info->ATR = usim_dcb.ATR_data;
}

/*************************************************************************
* FUNCTION
*  L1usim_Enable_Enhanced_Speed
*
* DESCRIPTION
*	1. enable the enhance speed mode if UICC supports
*	2. shall be called before reset after init
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
void L1usim_Enable_Enhanced_Speed(kal_bool enable)
{
	ASSERT(usim_dcb.main_state == IDLE_STATE);
	usim_dcb.high_speed_en = enable;
}

void L1usim_Enable_Enhanced_Speed_2(kal_bool enable)  // nick
{
	ASSERT(usim_dcb.main_state == IDLE_STATE);
	usim_dcb.high_speed_en = enable;
}

/*************************************************************************
* FUNCTION
*  L1usim_Set_ClockStopMode
*
* DESCRIPTION
*	setup the clock stop mode according to the ATR information.
*
* PARAMETERS
*	mode:	clock stop mode
*
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
void L1usim_Set_ClockStopMode(usim_clock_stop_enum mode)
{	
	if(mode & CLOCK_STOP_MSK)
	{		
		// calculate the clock to etu for 1860 and 700
		usim_dcb.etu_of_1860 = (1860/(usim_dcb.Fi/usim_dcb.Di))+10; // longer than spec.
		usim_dcb.etu_of_700 = (700/(usim_dcb.Fi/usim_dcb.Di))+5;
		usim_dcb.clock_stop_en = KAL_TRUE;
		if(mode == CLOCK_STOP_ANY)
			usim_dcb.clock_stop_type = CLOCK_STOP_LOW;
		else
			usim_dcb.clock_stop_type = mode;
	}
	else
	{
		usim_dcb.clock_stop_en = KAL_FALSE;
	}
}
/*************************************************************************
* FUNCTION
*  L1usim_Cmd
*
* DESCRIPTION
*	usim T=1 command
*
* PARAMETERS
*	1. txData: tx buffer containing command header optional with tx data.
*	2. txSize: length of the tx data
*	3. rxData: rx buffer (must inluding two extra one for sw1 and sw2)
*	4. rxSize: length of the rx data except sw1|sw2
*	
* RETURNS
*	status bytes(SW1|SW2), 0 means a physical error.

* GLOBALS AFFECTED
*
*************************************************************************/
sim_status L1usim_Cmd_2(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize) //nick
{}

sim_status L1usim_Cmd(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize)
{

	/*
	if(usim_dcb.main_state != MAIN_CMD_READY_STATE && usim_dcb.main_state != CLK_STOPPED_STATE)
	{
		kal_prompt_trace(MOD_SIM,"[SIM_DRV]:L1usim_Cmd is called at err state");
		return STATUS_FAIL;
	}
	*/
	if(rxData == NULL && *rxSize != 0)
		ASSERT(0);
	if(usim_dcb.cmd_case == usim_case_1)
	{ // for case1, only 4 bytes need to be transfer
		*txSize = 4;
		*rxSize = 0;
	}	
	return usim_send_i_block(txData, txSize, rxData, rxSize);
}
/*************************************************************************
* FUNCTION
*  usim_TimeOutHandler
*
* DESCRIPTION
*	Callback function of gpt timer, and launched while MSDC busy for a while

*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void usim_gpt_timeout_handler(void *parameter)
{
	kal_prompt_trace(MOD_SIM,"[SIM_DRV]: usim gpt timeout !");
	usim_dcb.status  = USIM_GPT_TIMEOUT;
	USIM_SET_EVENT();
}

//------------------------------------------------------------------------//
// General interfaces of sim driver
//------------------------------------------------------------------------//
/*************************************************************************
* FUNCTION
*  L1sim_Reset_All
*
* DESCRIPTION
*	1. general interface of sim reset for T=0 and T=1
*	2. it support warm reset for UICC
*	3. first enable error repeat handling process to cover parity error at ATR, if not 
*		success, disable it.
*	4. for SIM protocol with T=0, additional reset will be perfromed.
*
* PARAMETERS
*	ExpectVolt: expected input voltage for the SIM card.
*	ResultVolt: finally used power voltage.
*	warm: specify warm reset for UICC
*
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
usim_status_enum L1sim_Reset_All_2(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm)  // nick
{}

usim_status_enum L1sim_Reset_All(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm)
{
	usim_status_enum status;
	
	if(warm == KAL_FALSE)
	{
		/////dbg_print("cold reset \r\n");
		//TS_HSK_ENABLE = KAL_TRUE;
		status = L1usim_Reset(ExpectVolt, ResultVolt);
		if(status < 0)
		{
			kal_sprintf(sim_dbg_str,"L1usim_Reset failed!(%d)",status);
			kal_print(sim_dbg_str);
			L1sim_PowerOff_All();
			if(status == USIM_NO_INSERT)
				usim_dcb.present = KAL_FALSE;
			return status;
			/*
			TS_HSK_ENABLE = KAL_FALSE;	
			status = L1usim_Reset(ExpectVolt, ResultVolt);
			if(status <0)
			{
				L1sim_PowerOff_All();
				return status;
			}
			*/
		}
		else
		{
			kal_uint32 i;
			kal_char *p;
			
			p = sim_dbg_str;
			kal_sprintf(p,"[SIM_DRV]:ATR= ");
			p += strlen(p);
			for(i = 0; i< usim_dcb.ATR_index; i++)
			{
				kal_sprintf(p,"%02X",usim_dcb.ATR_data[i]);
				p+= 2;
			}
			kal_print(sim_dbg_str);
			kal_sprintf(sim_dbg_str,"[SIM_DRV]: L1usim_Reset OK v: %d, T: %d, app: %d, speed:%d",
				usim_dcb.power, usim_dcb.phy_proto, usim_dcb.app_proto, usim_dcb.card_speed);
			kal_print(sim_dbg_str);
		}
		if(usim_dcb.phy_proto == T0_PROTOCOL)
		{		
			extern kal_uint8 sim_dmaport;
			kal_uint8 s;
			kal_uint8 power;

			#if !defined(MT6218B) && !defined(MT6218)
			sim_dmaport = usim_dcb.dma_port;
			#endif			
			L1sim_Init();
			if(usim_dcb.power == CLASS_C_18V)
				power = SIM_18V;
			else 
				power = SIM_30V;		
			if(usim_dcb.app_proto == SIM_PROTOCOL)
			{
				s = L1sim_Reset(power, NULL, NULL );
				ASSERT(s == SIM_NO_ERROR);
			}
			else
				usim_update_sim_to_ready();
		}
	}
	else
	{
		/////dbg_print("warm reset \r\n");
		if(usim_dcb.app_proto == USIM_PROTOCOL)
		{
			usim_dcb.warm_rst = KAL_TRUE;
			status = L1usim_Reset(usim_dcb.power, ResultVolt);
			usim_dcb.warm_rst = KAL_FALSE;
			if(status <0)
			{
				L1sim_PowerOff_All();
				return status;
			}
			if(usim_dcb.phy_proto == T0_PROTOCOL)
			{		
				extern kal_uint8 sim_dmaport;
				kal_uint8 power = 0;

				sim_dmaport = usim_dcb.dma_port;
				L1sim_Init();
				if(usim_dcb.power == CLASS_C_18V)
					power = SIM_18V;
				else 
					power = SIM_30V;
				if(usim_dcb.app_proto == SIM_PROTOCOL)
					L1sim_Reset(power, NULL, NULL);
				else
					usim_update_sim_to_ready();
			}			
		}
		else
		{
			status = USIM_INVALID_WRST;
		}
	}
		
	return status;
}
/*************************************************************************
* FUNCTION
*  L1sim_Enable_Enhanced_Speed_All
*
* DESCRIPTION
*	enable the enhance speed
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

void L1sim_Enable_Enhanced_Speed_All(kal_bool enable)
{
	L1sim_Enable_Enhanced_Speed(enable);
	L1usim_Enable_Enhanced_Speed(enable);
}

void L1sim_Enable_Enhanced_Speed_All_2(kal_bool enable)  // nick
{
	L1sim_Enable_Enhanced_Speed_2(enable);
	L1usim_Enable_Enhanced_Speed_2(enable);
}

/*************************************************************************
* FUNCTION
*  L1sim_Select_Prefer_PhyLayer_All
*
* DESCRIPTION
*	select the prefer physical layer protocol, the selected one has higher priority
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
void L1sim_Select_Prefer_PhyLayer_All_2(sim_protocol_phy_enum T)  // nick
{
		usim_dcb.perfer_phy_proto = T;
		kal_sprintf(sim_dbg_str,"select phy layer: %d",T);
		kal_print(sim_dbg_str);
}


void L1sim_Select_Prefer_PhyLayer_All(sim_protocol_phy_enum T)
{
		usim_dcb.perfer_phy_proto = T;
		kal_sprintf(sim_dbg_str,"select phy layer: %d",T);
		kal_print(sim_dbg_str);
}
/*************************************************************************
* FUNCTION
*  L1sim_Set_ClockStopMode_All
*
* DESCRIPTION
*	configure the clock stop mode.
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool L1sim_Set_ClockStopMode_All_2(sim_clock_stop_enum mode)  //nick
{}

kal_bool L1sim_Set_ClockStopMode_All(sim_clock_stop_enum mode)
{
	if(usim_dcb.phy_proto == T0_PROTOCOL)
	{
		if(mode == CLOCK_STOP_HIGH)
			L1sim_Configure(CLOCK_STOP_AT_HIGH);
		else if(mode == CLOCK_STOP_LOW || mode == CLOCK_STOP_ANY)
			L1sim_Configure(CLOCK_STOP_AT_LOW);
		else
			L1sim_Configure(CLOCK_STOP_NOT_ALLOW);
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
		
	}
	else
	{
		L1usim_Set_ClockStopMode(mode);
	}
	
	return KAL_TRUE;
}
/*************************************************************************
* FUNCTION
*  L1sim_PowerOff_All
*
* DESCRIPTION
*	turn off the SIM card.
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

void L1sim_PowerOff_All_2(void)  //nick
{}

void L1sim_PowerOff_All(void)
{
	if(usim_dcb.phy_proto == T0_PROTOCOL)
		L1sim_PowerOff();
	else
		L1usim_PowerOff();
}
/*************************************************************************
* FUNCTION
*  L1sim_Get_Card_Info_All
*
* DESCRIPTION
*	get the card information
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

void L1sim_Get_Card_Info_All(sim_info_struct *info)
{
	L1usim_Get_Card_Info(info);
}
/*************************************************************************
* FUNCTION
*  L1sim_Cmd_All
*
* DESCRIPTION
*	1. check which case the command belongs to.
*	2. direct the command into T=0 or T=1 protocol layer. 
*
* PARAMETERS
*	1. txData: tx buffer containing command header optional with tx data.
*	2. txSize: length of the tx data
*	3. rxData: rx buffer (for T=1, must inluding two extra one for sw1 and sw2)
*	4. rxSize: length of the rx data except sw1|sw2
*	
* RETURNS
*	status bytes(SW1|SW2), 0 means a physical error.
*
* GLOBALS AFFECTED
*
*************************************************************************/
sim_status L1sim_Cmd_All_2(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize)  // nick
{}

sim_status L1sim_Cmd_All(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize)
{
	if(usim_dcb.present == KAL_FALSE)
		return STATUS_FAIL;
	// check cmd cases
	if(*txSize == 5 && rxData == NULL)
	{
		usim_dcb.cmd_case = usim_case_1;
		/////dbg_print("usim_case_1 \r\n");
	}
	else if(*txSize == 5 && rxData != NULL)
	{
		usim_dcb.cmd_case = usim_case_2;
		/////dbg_print("usim_case_2 \r\n");
	}
	else if(*txSize != 5 && rxData == NULL)
	{
		usim_dcb.cmd_case = usim_case_3;
		/////dbg_print("usim_case_3 \r\n");
	}
	else if(*txSize != 5 && rxData != NULL)
	{
		usim_dcb.cmd_case = usim_case_4;
		/////dbg_print("usim_case_4 \r\n");
	}	
	SimCard.cmd_case = usim_dcb.cmd_case;
	
	if(usim_dcb.phy_proto == T0_PROTOCOL)
	{		
		return L1sim_Cmd_Layer(txData, txSize,  rxData, rxSize);		
	}
	else
	{
		return L1usim_Cmd(txData, txSize,  rxData, rxSize);		
	}
}

#if defined(__SIM_PLUS__)
void L1sim_Select_SIM_PLUS(kal_bool isSIMPLUS)
{	
	extern void SD_Use24M_Clock(void);
	extern void SD_Use13M_Clock(void);
	if(isSIMPLUS)
	{
		SD_Use13M_Clock(); // reset to 13M for SD_EXT
		// control GPIO17 to turn on the LDO		
		GPIO_ModeSetup(GPIO_LDO_SWITCH, 0); // gpio mode
		GPIO_InitIO(OUTPUT, GPIO_LDO_SWITCH);
		GPIO_WriteIO(1, GPIO_LDO_SWITCH);
		kal_print("SIM+ MMC Card");
		MSDC_Blk[SD_SIM].mIsPresent = KAL_TRUE;
		MSDC_Blk[SD_SIM].mIsChanged = KAL_TRUE;
		MSDC_SendCardInd(MOD_FMT, SD_SIM); 
	}	
	else
	{
		
		kal_print("no SIM+ MMC");
		if(MSDC_24M == MSDC_GetClockWithoutSIMPlus())
		SD_Use24M_Clock();
	}
}
#endif
//--------------------------------------------------------------------------//
// usim driver unit test code
//--------------------------------------------------------------------------//
/*
The behavior of the T1 controller
1. enable T1 controller
2. write NAD, PCB, LEN  into SIM_DATA
3. write LEN into SIMP3
4. configure the DMA for data transfer (INF field) 
5. write any value into SIM_INS (trigger to start)
6. generate the T1END interrupt.
7. if a response block is received, T1END is generated again
8. The received block is in the data buffer, the EDC is checked and removed.
*/

#if defined(USIM_DEBUG)
//kal_uint8 IFS_REQ[] = { 0x00, 0xc1, 0x01, 0xFE, 0x3E};
kal_uint8 select_t0[] = {0xa0,0xa4,0x00,0x00,0x02,0x7f,0x20, 0x00};

kal_uint8 usim_cmd0[] = {0x00,0xa4,0x08,0x0c,0x02,0x2f,0xe2}; // select
kal_uint8 usim_cmd1[] = {0x00, 0xB0, 0x00 ,0x00 ,0x0A};	// read binary
kal_uint8 usim_cmd2[] = {0x00, 0xA4, 0x00, 0x04, 0x02, 0x2F, 0x05, 0x00}; // select fail
kal_uint8 usim_cmd3[] = {0x00, 0xB0, 0x00, 0x00, 0x02}; // read binary
// Terminal profil []
kal_uint8 usim_cmd4[] = {0x80, 0x10, 0x00, 0x00, 0x13, 0xDF, 0xF7, 0xFF, 0xFF, 0x1D, 0x00, 0x00, 0xD8, 0x41, 0x00, 0x00, 0x00, 0x00, 0x05, 0x0F, 0x80, 0x00, 0x00, 0x00};
kal_uint8 usim_cmd5[] = {0x00, 0xA4, 0x04, 0x0C, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x87, 0x10, 0x02, 0xFF, 0x49, 0xFF, 0xFF, 0x89, 0x04, 0x03, 0x00, 0x00, 0x00};
kal_uint8 usim_cmd6[] = {0x00, 0xA4, 0x00, 0x04, 0x02, 0x6F, 0xB7, 0x00}; // select fail
kal_uint8 usim_cmd7[] = {0x00, 0xB2, 0x01, 0x04, 0x04}; //read record
//kal_uint8 usim_cmd7_1[] = {00 A4 08 04 04 7F FF 6F B7}; //error 1
//kal_uint8 usim_cmd7_2[] = {00 A4 00 0C 02 3F 00}; //error 1
kal_uint8 usim_cmd8[] = {0x00, 0xA4, 0x00, 0x04, 0x02, 0x6F, 0x05, 0x00}; // select fail
kal_uint8 usim_cmd9[] = {0x80, 0xF2, 0x00, 0x00, 0x00}; // status
kal_uint8 usim_cmd10[] = {0x80, 0xF2, 0x00, 0x00, 0x39}; // status
kal_uint8 usim_cmd11[] = {0x00, 0xA4, 0x08, 0x0C, 0x02, 0x7F, 0xFF}; // select
kal_uint8 usim_cmd12[] = {0x00, 0x20, 0x00, 0x01, 0x00}; // Verify CHV
kal_uint8 usim_cmd13[] = {0x00, 0x20, 0x00, 0x01, 0x08, 0x33, 0x33, 0x33, 0x33, 0xFF, 0xFF, 0xFF, 0xFF};
kal_uint8 usim_cmd14[] = {0x00, 0xA4, 0x08, 0x04, 0x06, 0x7F, 0x10, 0x5F, 0x3A, 0x4F, 0x3A, 0x00} ;// case 4, select
kal_uint8 usim_cmd15[] = {0x00, 0xa2, 0x01, 0x0c, 0xfe};

kal_uint8 *cmd_group[14] = {
	usim_cmd0, usim_cmd1, usim_cmd2, usim_cmd3, usim_cmd4, usim_cmd5, usim_cmd6, usim_cmd7,
	usim_cmd8, usim_cmd9, usim_cmd10, usim_cmd11, usim_cmd12, usim_cmd13};
	
	

kal_uint8 rx[300];
kal_uint8 tx[300];
kal_bool usim_loop = KAL_FALSE;
kal_bool usim_abort = KAL_FALSE;
void usim_chain_search_cmd(void)
{
	kal_uint32 tx_size, rx_size = 0;
	kal_uint16 sw;
	kal_bool fail;

	//while(usim_loop)
	{
		// select (case 4)
		tx_size = sizeof(usim_cmd14);
		rx_size = 255;
		sw = L1sim_Cmd_All(usim_cmd14, &tx_size, rx, &rx_size);	
		if(sw == STATUS_FAIL)
			return	;
		if((sw & 0xf000) == 0x6000)
			fail = KAL_TRUE;
		else 
			fail = KAL_FALSE;
		
		/////dbg_print("select cmd, status: %x \r\n",sw);
		memset(rx,0, sizeof(rx));

		if(!fail)
		{
		memset(tx, 0xff,sizeof(tx)); //0x00
		memcpy(tx, usim_cmd15, sizeof(usim_cmd15));
		tx[259] = 0; // le
		tx_size = 260;	// 5 (header) + 254 (tx data) + 1 (le)
		rx_size = 255;
		sw = L1sim_Cmd_All(tx, &tx_size, rx, &rx_size);	
		if(sw == STATUS_FAIL)
			return	;
		
		/////dbg_print("select cmd, status: %x \r\n",sw);
		memset(rx,0, sizeof(rx));
		}
	}		
}
extern void Sim_test(void);
sim_info_struct info;

// perform the commands until verify chv
void usim_test_case(void)
{	
	kal_uint32 tx_size, rx_size = 0;
	kal_uint16 sw;
	//kal_char *pin_code = "4320";
	kal_char *pin_code = "2468";
	kal_bool fail;
	
	// select (case 3)
	tx_size = sizeof(usim_cmd0);
	rx_size = 0;
	sw = L1sim_Cmd_All(usim_cmd0, &tx_size, NULL, &rx_size);
	if(sw == STATUS_FAIL)
		return;
	if((sw & 0xf000) == 0x6000)
		fail = KAL_TRUE;
	else 
		fail = KAL_FALSE;
	/////dbg_print("select cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));
	
	// read binary (case 2)
	if(!fail)
	{
	tx_size = sizeof(usim_cmd1);
	rx_size = 10;
	sw = L1sim_Cmd_All(usim_cmd1, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	/////dbg_print("read binary cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));
	}
	
	// select (case 4)
	tx_size = sizeof(usim_cmd2);
	rx_size = 255;
	sw = L1sim_Cmd_All(usim_cmd2, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	if((sw & 0xf000) == 0x6000)
		fail = KAL_TRUE;
	else 
		fail = KAL_FALSE;
	
	/////dbg_print("select cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));
	
	// read binary (case 2)
	if(!fail)
	{
	
	tx_size = sizeof(usim_cmd3);
	rx_size = 2;
	sw = L1sim_Cmd_All(usim_cmd3, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("read binary cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));
	}
	
	// Terminal profile (case 3)
	tx_size = sizeof(usim_cmd4);
	rx_size = 0;
	sw = L1sim_Cmd_All(usim_cmd4, &tx_size, NULL, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("select cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));

	// select (case 4)
	tx_size = sizeof(usim_cmd5);
	rx_size = 255;
	sw = L1sim_Cmd_All(usim_cmd5, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("select cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));

	// select (case 4)
	tx_size = sizeof(usim_cmd6);
	rx_size = 255;
	sw = L1sim_Cmd_All(usim_cmd6, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	if((sw & 0xf000) == 0x6000)
		fail = KAL_TRUE;
	else 
		fail = KAL_FALSE;
	
	/////dbg_print("select cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));

	if(!fail)
	{
	
	// read record (case 2)
	tx_size = sizeof(usim_cmd7);
	rx_size = 4;
	sw = L1sim_Cmd_All(usim_cmd7, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("read record cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));
	
	// select (case 4)
	tx_size = sizeof(usim_cmd8);
	rx_size = 255;
	sw = L1sim_Cmd_All(usim_cmd8, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("select cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));
	}
	
	// status (case 4)
	tx_size = sizeof(usim_cmd9);
	rx_size = 255;
	sw = L1sim_Cmd_All(usim_cmd9, &tx_size, rx, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("status cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));

	// select (case 3)
	tx_size = sizeof(usim_cmd11);
	rx_size = 0;
	sw = L1sim_Cmd_All(usim_cmd11, &tx_size, NULL, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("select cmd, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));

	// verify chv (case 1)
	tx_size = sizeof(usim_cmd12);
	rx_size = 0;
	sw = L1sim_Cmd_All(usim_cmd12, &tx_size, NULL, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("verify chv query , status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));

	kal_sleep_task(1000);
		// verify chv with pin code (case 3)
	memcpy(usim_cmd13+5, pin_code, 4);
	tx_size = sizeof(usim_cmd13);
	rx_size = 0;
	sw = L1sim_Cmd_All(usim_cmd13, &tx_size, NULL, &rx_size);	
	if(sw == STATUS_FAIL)
		return	;
	
	/////dbg_print("verify chv  with pin code, status: %x \r\n",sw);
	memset(rx,0, sizeof(rx));

	// IT3 does'nt allow MS entering clock stop mode before verify PIN (102 230 7.2.6)
	L1sim_Set_ClockStopMode_All(info.clock_stop);
	usim_chain_search_cmd();	
	
}


void usim_warm_reset(void)
{
	usim_power_enum power;
	kal_uint32 tx_size, rx_size = 0;
	//kal_uint16 sw;
	
	L1sim_Reset_All(UNKNOWN_POWER_CLASS, &power, KAL_TRUE);
	if(usim_dcb.app_proto == USIM_PROTOCOL)
	{
		usim_test_case();
	}
	else
	{
		tx_size = sizeof(select_t0);
		rx_size = 0;
		//sw = L1sim_Cmd_All(select_t0, &tx_size, rx, &rx_size);
		//Sim_test();
	}
	
}

void usim_ut_main(void)
{
	usim_power_enum power;
	kal_uint32 tx_size, rx_size = 0;
	//kal_uint16 sw;
	usim_status_enum status;

	/////dbg_print("\r\n@@@@@@@@@@@ usim_ut_main @@@@@@@@@@@@@\r\n");
	//L1sim_Init_All();
	L1sim_Enable_Enhanced_Speed_All(KAL_TRUE);
	status = L1sim_Reset_All(UNKNOWN_POWER_CLASS, &power, KAL_FALSE);
	if(status)
	{
		L1sim_PowerOff_All();
	}
	
	#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
	L1sim_Get_Card_Info_All(&info);
	//L1sim_Set_ClockStopMode_All(info.clock_stop);
	
	if(1)
	{
		if(usim_dcb.app_proto == USIM_PROTOCOL)
		{
			usim_test_case();
		}
		else
		{
			tx_size = sizeof(select_t0);
			rx_size = 0;
			//sw = L1sim_Cmd_All(select_t0, &tx_size, rx, &rx_size);
			// Sim_test();
		}
	}

	kal_sleep_task(3000);
	L1sim_PowerOff_All();
}
#else	// USIM_DEBUG
void usim_ut_main(void)
{
}
#endif // USIM_DEBUG
#endif // DRV_MULTIPLE_SIM
#endif // __USIM_DRV__
