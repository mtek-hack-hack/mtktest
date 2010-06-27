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
 *   sccb.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   SCCB module driver code
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "stack_timer.h"      /*stack_timer_struct....definitions*/
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "sccb.h"
#include "isp_if.h"

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6228)||defined(MT6229)||defined(MT6230))

//#define SCCB_LISR_ENABLE
volatile kal_uint8 sccb_status=0;
kal_uint32 SCCB_DELAY=0x100;
kal_uint32 MAX_RETRY_COUNT=0x1000;
kal_uint8	sccb_mode = 0;
kal_uint8	sccb_write_id=0, sccb_read_id=0;

/*************************************************************************
* FUNCTION
*	sccb_LISR
*
* DESCRIPTION
*	Entry function of SCCB LISR routine
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void sccb_LISR(void)
{
	kal_uint16 int_status;

	int_status=DRV_Reg(SCCB_STATUS_REG);

	if (int_status & SCCB_READ_COMPLETE)
		sccb_status |= SCCB_READ_COMPLETE;
	if (int_status & SCCB_WRITE_COMPLETE)
		sccb_status |= SCCB_WRITE_COMPLETE;
}

void init_sccb(void)
{
	sccb_config(SCCB_SW_8BIT, 0x00, 0x00, NULL);
}

/*************************************************************************
* FUNCTION
*	power_off_sccb
*
* DESCRIPTION
*	This function power off SCCB interface
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void power_off_sccb(void)
{
	kal_uint32 save_irq_mask;    
    save_irq_mask=SaveAndSetIRQMask();			
    DRV_Reg(DRVPDN_CON2) |= DRVPDN_CON2_SCCB;  /* Power off SCCB */	    
    RestoreIRQMask(save_irq_mask);			    
}
/*************************************************************************
* FUNCTION
*	sccb_config
*
* DESCRIPTION
*	This function configure SCCB interface
*
* PARAMETERS
*	para
*		mode - SCCB_SW_8BIT, SCCB_SW_16BIT, SCCB_HW_8BIT or SCCB_HW_16BIT
*		wid, rid - slave write/read id
*	freq - HW SCCB Frequency Parameter
*
* RETURNS
*	TRUE/FALSE
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 sccb_config(kal_uint8 mode, kal_uint8 write_id, kal_uint8 read_id, SCCB_FREQ_STRUCT *freq)
{
	kal_uint32 save_irq_mask;

	sccb_mode = mode;		
	sccb_write_id = write_id;
	sccb_read_id = read_id;		  			  		  	
	switch(mode)
	{
		case SCCB_SW_8BIT:
		case SCCB_SW_16BIT:		
			GPIO_ModeSetup(SCCB_SERIAL_CLK_PIN,0x0);
			GPIO_ModeSetup(SCCB_SERIAL_DATA_PIN,0x0);		
		  	save_irq_mask=SaveAndSetIRQMask();					
			SET_SCCB_CLK_HIGH;
			SET_SCCB_DATA_HIGH;
			SET_SCCB_CLK_OUTPUT;
			SET_SCCB_DATA_OUTPUT;			
		  	RestoreIRQMask(save_irq_mask);			
		break;
		case SCCB_HW_8BIT:
		case SCCB_HW_16BIT:		
		    /* Set GPIO as Output High */
            GPIO_ModeSetup(SCCB_SERIAL_CLK_PIN,0);
            GPIO_ModeSetup(SCCB_SERIAL_DATA_PIN,0);
            GPIO_InitIO(OUTPUT,SCCB_SERIAL_CLK_PIN);
            GPIO_InitIO(OUTPUT,SCCB_SERIAL_DATA_PIN);		    
		    GPIO_WriteIO(1,SCCB_SERIAL_CLK_PIN);
		    GPIO_WriteIO(1,SCCB_SERIAL_DATA_PIN);		    		
            save_irq_mask=SaveAndSetIRQMask();		    		    
            /* Power on SCCB and then switch GPIO to HW Mode */
            DRV_Reg(DRVPDN_CON2) &= (~DRVPDN_CON2_SCCB);  /* Power on SCCB */	
            RestoreIRQMask(save_irq_mask);			               
        	GPIO_ModeSetup(SCCB_SERIAL_CLK_PIN,0x01);
        	GPIO_ModeSetup(SCCB_SERIAL_DATA_PIN,0x01);
			if(freq!=NULL)
			{
				SET_SCCB_BUFFER_TIMER( freq->TBUF );
				SET_SCCB_START_HOLD_TIME( freq->THDSTA );
				SET_SCCB_DATA_HOLD_TIME( freq->THDDTA );
				SET_SCCB_CLK_LOW_PERIOD( freq->TLOW );
				SET_SCCB_CLK_HIGH_PERIOD( freq->THIGH );
				SET_SCCB_STOP_SETUP_TIME( freq->TSUSTO );
			}		
	SET_SCCB_MASTER_MODE;
	CLEAR_SCCB_BUFFER;
#if (defined(SCCB_LISR_ENABLE))
	IRQ_Register_LISR(IRQ_SCCB_CODE, sccb_LISR,"SCCB ISR");

  	IRQSensitivity(IRQ_SCCB_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_SCCB_CODE);
#endif			
		break;
		default:		
			return KAL_FALSE;
	}
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	sccb_getMode
*
* DESCRIPTION
*	This function Get SCCB Mode
*
* PARAMETERS
*	None
*
* RETURNS
*	SCCB Mode - SCCB_SW_8BIT, SCCB_SW_16BIT, SCCB_HW_8BIT, SCCB_HW_16BIT
*************************************************************************/
kal_uint8 sccb_getMode(void)
{
	return sccb_mode;
}

/*************************************************************************
* FUNCTION
*	sccb_setDelay
*
* DESCRIPTION
*	This function set SCCB delay count for read SCCB status complete signal
*
* PARAMETERS
*	delay - 0x100~=1; 0x800~=8; 0x1000~=16; 0x8000~=132 TDMA@52MHz (1TDMA=1/32K )
*
* RETURNS
*	SCCB Mode - SCCB_SW_8BIT, SCCB_SW_16BIT, SCCB_HW_8BIT, SCCB_HW_16BIT
*************************************************************************/
void sccb_setDelay(kal_uint32 delay)
{
	SCCB_DELAY = delay;
}

kal_uint8 sccb_wait_writeComplete(void)
{
	kal_uint32 i=0;
	#if (defined(SCCB_LISR_ENABLE))
	while (!(sccb_status & SCCB_WRITE_COMPLETE)) {};		
#else
	for(i=SCCB_DELAY;i>0;i--)	;		
	while (SCCB_IS_WRITTING && ((i++)<MAX_RETRY_COUNT) ) ;		
	#endif	
	if(i>=MAX_RETRY_COUNT)
		return KAL_FALSE;
	return KAL_TRUE;		
}

kal_uint8 sccb_wait_readComplete(void)
{
	kal_uint32 i=0;	
	if((sccb_mode==SCCB_SW_8BIT)||(sccb_mode==SCCB_SW_16BIT))	
	{
		while (GET_SCCB_DATA_BIT && ((i++)<MAX_RETRY_COUNT));	
	}
	else
	{
		#if (defined(SCCB_LISR_ENABLE))				
		while (!(sccb_status & SCCB_READ_COMPLETE)) {};		
		#else
		for(i=SCCB_DELAY;i>0;i--)	;
		while (SCCB_IS_READING && ((i++)<MAX_RETRY_COUNT)) ;			
#endif
		if(i>=MAX_RETRY_COUNT)
			return KAL_FALSE;
	}
	return KAL_TRUE;			
}

/*************************************************************************
* FUNCTION
*	sccb_send_byte
*
* DESCRIPTION
*	This function send one byte to through software SCCB
*
* PARAMETERS
*	send_byte : the data that writes out through software sccb
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void sccb_send_byte(kal_uint8 send_byte)
{
	signed char i;
	kal_uint32 j=0;	
	SET_SCCB_CLK_LOW;	
	SET_SCCB_DATA_OUTPUT;

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (send_byte & (1<<i))
		{
			SET_SCCB_DATA_HIGH;
		}
		else
		{
			SET_SCCB_DATA_LOW;
		}
		for (j=0; j<SCCB_DELAY; j++); 
		SET_SCCB_CLK_HIGH;
		for (j=0; j<SCCB_DELAY; j++); 
		SET_SCCB_CLK_LOW;
	}
	/* don't care bit, 9th bit */

	SET_SCCB_DATA_LOW;
	SET_SCCB_DATA_INPUT;
	SET_SCCB_CLK_HIGH;
	sccb_wait_readComplete();	
	SET_SCCB_CLK_LOW;
	SET_SCCB_DATA_OUTPUT;	
}	/* SCCB_send_byte() */

/*************************************************************************
* FUNCTION
*	sccb_get_byte
*
* DESCRIPTION
*	This function read one byte through software SCCB interface
*
* PARAMETERS
*	None
*
* RETURNS
*	the data that read from SCCB interface
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 sccb_get_byte(void)
{
	kal_uint16 get_byte=0;
	signed char i;
	kal_uint32 j;
	SET_SCCB_CLK_LOW;		
	if(sccb_mode==SCCB_SW_8BIT)
	{
	SET_SCCB_DATA_INPUT;
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
			for (j=0; j<SCCB_DELAY; j++); 
		SET_SCCB_CLK_HIGH;
			for (j=0; j<SCCB_DELAY; j++); 			
		if (GET_SCCB_DATA_BIT)
			get_byte |= (1<<i);
			for (j=0; j<SCCB_DELAY; j++); 
		SET_SCCB_CLK_LOW;
	}
	/* don't care bit, 9th bit */
		NACK_BIT;		
	}
	else if(sccb_mode==SCCB_SW_16BIT)
	{
		SET_SCCB_DATA_INPUT;
		
		for (i=15; i>=8; i--)
		{	/* data bit 15~8 */
			for(j=0;j<SCCB_DELAY;j++);		
			SET_SCCB_CLK_HIGH;
			for(j=0;j<SCCB_DELAY;j++);
			if (GET_SCCB_DATA_BIT)
				get_byte |= (1<<i);
			for(j=0;j<SCCB_DELAY;j++);
			SET_SCCB_CLK_LOW;
		}
		for(j=0;j<SCCB_DELAY;j++);	
		SET_SCCB_DATA_OUTPUT;
		SET_SCCB_DATA_LOW;
		for(j=0;j<SCCB_DELAY;j++);
		SET_SCCB_CLK_HIGH;
		for(j=0;j<SCCB_DELAY;j++);
		SET_SCCB_CLK_LOW;
		for(j=0;j<SCCB_DELAY;j++);

		SET_SCCB_DATA_INPUT;
		
		for (i=7; i>=0; i--)
		{	/* data bit 7~0 */
			for(j=0;j<SCCB_DELAY;j++);		
			SET_SCCB_CLK_HIGH;
			for(j=0;j<SCCB_DELAY;j++);
			if (GET_SCCB_DATA_BIT)
				get_byte |= (1<<i);
			for(j=0;j<SCCB_DELAY;j++);
			SET_SCCB_CLK_LOW;
		}
		NACK_BIT;			
	}
	return get_byte;
}	/* sccb_get_byte() */

/*************************************************************************
* FUNCTION
*	sccb_write
*
* DESCRIPTION
*	This function 3 phase write to specified register through SCCB interface
*
* PARAMETERS
*	cmd : the register index of device
*  parameter : setting value of the specified register of device
*
* RETURNS
*	None
*************************************************************************/
void sccb_write(kal_uint32 cmd, kal_uint32 param)
{
	if(sccb_mode==SCCB_SW_8BIT)
	{
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		sccb_send_byte(param);
		SCCB_STOP_TRANSMISSION;
	}	
	else if(sccb_mode==SCCB_SW_16BIT)
	{
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		sccb_send_byte(param>>8);
		sccb_send_byte(param&0xFF);
		SCCB_STOP_TRANSMISSION;					
	}	
	else if(sccb_mode==SCCB_HW_8BIT)
	{
		CLEAR_SCCB_BUFFER;		
		sccb_status = 0;	
		SET_SCCB_DATA_LENGTH(3);
		ENABLE_SCCB;
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		REG_SCCB_DATA = param;
		sccb_wait_writeComplete();
	}
#if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
	else if(sccb_mode==SCCB_HW_16BIT)
	{	
		CLEAR_SCCB_BUFFER;			
		SET_SCCB_DATA_LENGTH(4);
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		REG_SCCB_DATA = (param&0xff00)>>8;
		REG_SCCB_DATA = (param&0xff);  
		sccb_status=0;
		ENABLE_SCCB;       
		sccb_wait_writeComplete();		
	}		
#endif
	else
	{
		ASSERT(0);
	}	
}

/*************************************************************************
* FUNCTION
*	sccb_multi_write
*
* DESCRIPTION
*	This function 1/2/3/.. phase write to specified register through 
*  SCCB interface
*
* PARAMETERS
*	cmd : the register index
*  param : setting value of the specified register
*  num : setting number of values 
*
* RETURNS
*	None
*************************************************************************/
void sccb_multi_write(kal_uint32 cmd, kal_uint32 *param, kal_uint8 num)
{
	kal_uint16 i;
	if((sccb_mode==SCCB_SW_8BIT)||(sccb_mode==SCCB_SW_16BIT))
	{
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		for(i=0;i<num;i++)			
			sccb_send_byte(param[i]);
		SCCB_STOP_TRANSMISSION;
	}	
	else if(sccb_mode==SCCB_HW_8BIT)	
{
		CLEAR_SCCB_BUFFER;			
	sccb_status=0;
		SET_SCCB_DATA_LENGTH(num+2);
	ENABLE_SCCB;
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
	REG_SCCB_DATA = cmd;
		for(i=0;i<num;i++)	
			REG_SCCB_DATA = param[i];			
		sccb_wait_writeComplete();			
	}		
#if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
	else if(sccb_mode==SCCB_HW_16BIT)
	{	
		CLEAR_SCCB_BUFFER;
		sccb_status=0;							
		SET_SCCB_DATA_LENGTH(num*2+2);
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		for(i=0;i<num;i++)	
		{		
			REG_SCCB_DATA = (param[i]&0xff00)>>8;
			REG_SCCB_DATA = (param[i]&0xff);  
		}
		ENABLE_SCCB;      
		sccb_wait_writeComplete();
	}		
#endif
	else
	{
		ASSERT(0);
	}		
}

/*************************************************************************
* FUNCTION
*	sccb_cont_write
*
* DESCRIPTION
*	This function send cont 8bit command to write 16bit at a time to the register
*
* PARAMETERS
*	cmd : the register index of device
*	spec_cmd : the special command of device
*  parameter : setting value of the specified register of device
*
* RETURNS
*	None
*************************************************************************/
void sccb_cont_write(kal_uint32 cmd, kal_uint32 spec_cmd, kal_uint32 param)
{
	if(sccb_mode==SCCB_SW_8BIT)
	{
	SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
	sccb_send_byte(cmd);
		sccb_send_byte(param>>8);
		SCCB_STOP_TRANSMISSION;		
		
		SCCB_START_TRANSMISSION;	/*Re-Start Bit*/
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(spec_cmd);
		sccb_send_byte(param&0xFF);
	SCCB_STOP_TRANSMISSION;
	}	
	else if(sccb_mode==SCCB_HW_8BIT)
	{
			SET_SCCB_DATA_LENGTH(3);
			REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
			REG_SCCB_DATA = cmd;
			REG_SCCB_DATA = param>>8;
			ENABLE_SCCB;						
			sccb_wait_writeComplete();			
					
			SET_SCCB_DATA_LENGTH(3);				
			REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
			REG_SCCB_DATA = spec_cmd;
			REG_SCCB_DATA = param&0xff;
			ENABLE_SCCB;						
			sccb_wait_writeComplete();			
	}
	else
	{
		ASSERT(0);
	}	
}

/*************************************************************************
* FUNCTION
*	sccb_read
*
* DESCRIPTION
*	This function 2 phase read to specified register through SCCB interface
*
* PARAMETERS
*	cmd : the register index of CMOS sensor
*
* RETURNS
*  value of the specified register of device
*************************************************************************/
kal_uint32 sccb_read (kal_uint32 cmd)
{
	kal_uint32 get_byte=0;
	
	if(sccb_mode==SCCB_SW_8BIT)
	{						
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		SCCB_STOP_TRANSMISSION;
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		get_byte=sccb_get_byte();
		SCCB_STOP_TRANSMISSION;
	}
	else if(sccb_mode==SCCB_SW_16BIT)
	{
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		SCCB_STOP_TRANSMISSION;
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		get_byte=sccb_get_byte();
		SCCB_STOP_TRANSMISSION;											
	}	
	else if(sccb_mode==SCCB_HW_8BIT)	
	{						
		CLEAR_SCCB_BUFFER;					
		sccb_status=0;
		SET_SCCB_DATA_LENGTH(2);
		ENABLE_SCCB;
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		sccb_wait_writeComplete();		
		
		CLEAR_SCCB_BUFFER;							
		sccb_status=0;				
		SET_SCCB_DATA_LENGTH(2);
		ENABLE_SCCB;
		REG_SCCB_DATA = sccb_read_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = 0;
		sccb_wait_readComplete();		
		
		get_byte = (REG_SCCB_READ_DATA) & 0xFF;
	}
#if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
	else if(sccb_mode==SCCB_HW_16BIT)
	{	
		CLEAR_SCCB_BUFFER;	
		sccb_status=0;				
		SET_SCCB_DATA_LENGTH(2);
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		ENABLE_SCCB;          
		sccb_wait_writeComplete();		
		
		CLEAR_SCCB_BUFFER;		
		sccb_status=0;				
		SET_SCCB_DATA_LENGTH(3);  
		REG_SCCB_DATA = sccb_read_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = 0;		
		ENABLE_SCCB; 
		sccb_wait_readComplete();
		get_byte=(((REG_SCCB_READ_DATA)&0xff)<<8) | (REG_SCCB_READ_DATA_L);  
	}		
#endif
	else
	{
		ASSERT(0);
	}	

	return get_byte;
}

kal_uint32 sccb_phase3_read (kal_uint32 cmd)
{
	kal_uint16 get_byte=0;

	if(sccb_mode==SCCB_SW_8BIT)
	{						
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		SCCB_STOP_TRANSMISSION;
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		get_byte = (sccb_get_byte()&0xFF)<<8;
		get_byte |= (sccb_get_byte()&0xFF);		
		SCCB_STOP_TRANSMISSION;
	}
	else if(sccb_mode==SCCB_HW_8BIT)	
	{
		CLEAR_SCCB_BUFFER;					
		sccb_status=0;
		SET_SCCB_DATA_LENGTH(2);
		ENABLE_SCCB;
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		sccb_wait_writeComplete();		

		CLEAR_SCCB_BUFFER;							
		sccb_status=0;				
		SET_SCCB_DATA_LENGTH(3);
		ENABLE_SCCB;
		REG_SCCB_DATA = sccb_read_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = 0;
		sccb_wait_readComplete();		
		get_byte = (REG_SCCB_READ_DATA& 0xFF)<<8;
		get_byte|= (REG_SCCB_READ_DATA);					
	}
	else
	{
		ASSERT(0);
	}	
	
	return get_byte;
}

/*************************************************************************
* FUNCTION
*	sccb_multi_read
*
* DESCRIPTION
*	This function 1/2/3/.. phase read from specified register through 
*  SCCB interface (auto increase)
*
* PARAMETERS
*	cmd : the register index
*  param : read value of the specified register (auto increase)
*  num : number of values 
*
* RETURNS
*	TRUE / FALSE
*************************************************************************/
kal_uint8 sccb_multi_read (kal_uint32 cmd, kal_uint32 *param, kal_uint8 num)
{
	kal_uint16 idx;

	if((sccb_mode==SCCB_SW_8BIT)||(sccb_mode==SCCB_SW_16BIT))
	{						
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		SCCB_STOP_TRANSMISSION;
		
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		for(idx=0;idx<num;idx++)				
			param[idx]=sccb_get_byte();
		SCCB_STOP_TRANSMISSION;
		if(idx!=num)		
			return KAL_FALSE;		
	}
	else if(sccb_mode==SCCB_HW_8BIT)	
	{
		CLEAR_SCCB_BUFFER;					
	sccb_status=0;
	SET_SCCB_DATA_LENGTH(2);
	ENABLE_SCCB;
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
	REG_SCCB_DATA = cmd;
		sccb_wait_writeComplete();		

		CLEAR_SCCB_BUFFER;							
		sccb_status=0;				
		SET_SCCB_DATA_LENGTH(1+num);
		ENABLE_SCCB;
		REG_SCCB_DATA = sccb_read_id | SCCB_DATA_REG_ID_ADDRESS;
		for(idx=0;idx<num;idx++)		
		{
			if(sccb_wait_readComplete()==KAL_FALSE)
				break;
			param[idx] = REG_SCCB_READ_DATA;
		}
		if(idx!=num)		
			return KAL_FALSE;
	}
#if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
	else if(sccb_mode==SCCB_HW_16BIT)
	{	
		CLEAR_SCCB_BUFFER;				
		sccb_status=0;	
		SET_SCCB_DATA_LENGTH(2);
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		ENABLE_SCCB;          
		sccb_wait_writeComplete();		
		
		CLEAR_SCCB_BUFFER;				
	sccb_status=0;
		SET_SCCB_DATA_LENGTH(1+num);  
		REG_SCCB_DATA = sccb_read_id | SCCB_DATA_REG_ID_ADDRESS;
		//REG_SCCB_DATA = 0;
	ENABLE_SCCB;
		for(idx=0;idx<num;idx++)		
		{
			if(sccb_wait_readComplete()==KAL_FALSE)
				break;			
			param[idx] = (((REG_SCCB_READ_DATA)&0xff)<<8) | (REG_SCCB_READ_DATA_L);
		}				
		if(idx!=num)		
			return KAL_FALSE;		
	}		
#endif
	else
	{
		ASSERT(0);
	}	

	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	sccb_cont_read
*
* DESCRIPTION
*	This function send cont 8bit command to read 16bit at a time to the register
*
* PARAMETERS
*	cmd : the register index of device
*	spec_cmd : the special command of device
*
* RETURNS
*  value of the specified register of device
*************************************************************************/
kal_uint32 sccb_cont_read (kal_uint32 cmd, kal_uint32 spec_cmd)
{
	kal_uint16 get_byte;
	kal_uint8 hibyte=0, lobyte=0;
	
	if(sccb_mode==SCCB_SW_8BIT)
	{						
	SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
	sccb_send_byte(cmd);
	SCCB_STOP_TRANSMISSION;
		
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		hibyte = sccb_get_byte()& 0xFF;	
		SCCB_STOP_TRANSMISSION;
		
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(spec_cmd);
		SCCB_STOP_TRANSMISSION;
		
	SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		lobyte = sccb_get_byte()& 0xFF;	
	SCCB_STOP_TRANSMISSION;
	}
	else if(sccb_mode==SCCB_HW_8BIT)	
	{
		CLEAR_SCCB_BUFFER;					
		sccb_status=0;
		SET_SCCB_DATA_LENGTH(2);
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = cmd;
		ENABLE_SCCB;		
		sccb_wait_writeComplete();		

		CLEAR_SCCB_BUFFER;							
		sccb_status=0;				
		SET_SCCB_DATA_LENGTH(2);
		REG_SCCB_DATA = sccb_read_id | SCCB_DATA_REG_ID_ADDRESS;
		//REG_SCCB_DATA = 0;
		ENABLE_SCCB;		
		sccb_wait_readComplete();		
		hibyte = (REG_SCCB_READ_DATA) & 0xFF;		

		CLEAR_SCCB_BUFFER;					
		sccb_status=0;
		SET_SCCB_DATA_LENGTH(2);
		REG_SCCB_DATA = sccb_write_id | SCCB_DATA_REG_ID_ADDRESS;
		REG_SCCB_DATA = spec_cmd;
		ENABLE_SCCB;		
		sccb_wait_writeComplete();		

		CLEAR_SCCB_BUFFER;							
		sccb_status=0;				
		SET_SCCB_DATA_LENGTH(2);
		REG_SCCB_DATA = sccb_read_id | SCCB_DATA_REG_ID_ADDRESS;
		//REG_SCCB_DATA = 0;
		ENABLE_SCCB;		
		sccb_wait_readComplete();		
		lobyte = (REG_SCCB_READ_DATA) & 0xFF;			
	}
	else
	{
		ASSERT(0);
	}	
	get_byte =(hibyte<<8) | (lobyte);								
	return get_byte;
}

#elif(defined(MT6225) || defined(MT6238))
//#define SCCB_LISR_ENABLE
volatile kal_uint8 sccb_status=0;
kal_uint32 SCCB_DELAY=0x100;
kal_uint32 MAX_RETRY_COUNT=0x1000;
kal_uint8	sccb_mode = 0;
kal_uint8	sccb_write_id=0, sccb_read_id=0;

kal_uint8 sccb_config(kal_uint8 mode, kal_uint8 write_id, kal_uint8 read_id, SCCB_FREQ_STRUCT *freq)
{
	kal_uint32 save_irq_mask;

	sccb_mode = mode;		
	sccb_write_id = write_id;
	sccb_read_id = read_id;		  			  		  	
	switch(mode)
	{
		case SCCB_SW_8BIT:
		case SCCB_SW_16BIT:		
		  	save_irq_mask=SaveAndSetIRQMask();		
			GPIO_ModeSetup(SCCB_SERIAL_CLK_PIN,0x0);
			GPIO_ModeSetup(SCCB_SERIAL_DATA_PIN,0x0);		
			SET_SCCB_CLK_HIGH;
			SET_SCCB_DATA_HIGH;
			SET_SCCB_CLK_OUTPUT;
			SET_SCCB_DATA_OUTPUT;			
		  	RestoreIRQMask(save_irq_mask);			
		   break;

		default:		
			return KAL_FALSE;
	}
	return KAL_TRUE;
}

void sccb_setDelay(kal_uint32 delay)
{
	SCCB_DELAY = delay;
}

kal_uint8 sccb_getMode(void)
{
	return sccb_mode;
}

#endif /* MT6219 */


