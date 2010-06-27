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
 * Filename:
 * ---------
 * Custom_at_command.c
 *
 * Description:
 * ------------
 *   This file is intends for Customer to implement and parse its own defined AT commands
 *
 * Author:
 * -------
 * -------
 *
*****************************************************************************/

#include "kal_non_specific_general_types.h"
#include "stdio.h"
#include "string.h"

/*****************************************************************************
* CUSTOM_SYMBOL:
*	customer can modify this symbol.
*     Every command begin with this symbol will be recognized as a customer-defined command
*	and passed to custom_command_hdlr().
*     For example: if CUSTOM_SYMBOL is set to '^', 
*				then AT^AAAA, AT^BBBB will be customer-defined command.
*   	NOTE:  '+'  and '/' and ' \ 'is not allowed since they might be standard command format
*****************************************************************************/
#define CUSTOM_SYMBOL  '^'	 // '+'  and '/' and ' \ 'is NOT allowed   

/*****************************************************************************
* MAX_UART_LEN = 128 bytes.
*	when you write a lot of data to UART at the same time, 
*	UART's buffer might be full and cannot handle.
*     so the safer way is to seperate the long data, each time only write data length <= 128
*****************************************************************************/
#define MAX_UART_LEN	128  

kal_uint8 custom_get_atcmd_symbol(void);
void custom_command_hdlr(char *full_cmd_string);

/*****************************************************************************
* FUNCTION
*  	rmmi_write_to_uart()
* DESCRIPTION
*   	This function extern L4C RMMI function,
*     is to write data to UART
* PARAMETERS
*   	kal_uint8 * buffer 	- the data to be written
*	kal_uint16 length 	- the length of data to be written
*     kal_bool stuff 		- KAL_TRUE : <CR><LF> will be added at the beginning and end. (eg.<CR><LF>OK<CR><LF>)
*					   KAL_FALSE: no <CR><LF> is added
* RETURNS
*	none
*****************************************************************************/
extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff); 

/* 2009.3.31 added by hongzhe.liu for at command debug + */
void custom_debug_at_command_handler(char * cmd);
/* 2009.3.31 added by hongzhe.liu for at command debug - */

/*****************************************************************************
* FUNCTION
*  	custom_command_hdlr()
* DESCRIPTION
*   	This function should parse the custom AT command and do correspondent action.
*     Customer should maintain and modify the code.
* PARAMETERS
*   	kal_uint8 * cmd_string
* RETURNS
*	none
*****************************************************************************/
void custom_command_hdlr(char *full_cmd_string)
{
	char buffer[MAX_UART_LEN];
	char cmd_name[15];
	kal_uint8 index = 3; // we start parsing index after the CUSTOM_SYMBOL 
	kal_uint8 tmp_idx = 0;

	while ((full_cmd_string[index] != '=' ) &&  //might be TEST command or EXE command
			(full_cmd_string[index] != '?' ) && // might be READ command
			(full_cmd_string[index] != 13 ))  //carriage return
	{
		cmd_name[tmp_idx] = full_cmd_string[index] ;
		tmp_idx ++;
		index ++;
	}
	cmd_name[tmp_idx] = '\0' ;
	
	/* just a very basic example : customer can implement their own */
	if (strcmp(cmd_name, "EXAMPLE") == 0)
	{		
		/* BEGIN: do the following parsing and correspondent action */
		/*  												    */
		/*  												    */
		/*  												    */
 		/* END: do the following parsing and correspondent action    */

		/* generate final result code: "OK" */
		sprintf(buffer, "OK");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	}
/* 2009.3.31 added by hongzhe.liu for debug + */
	else if(strcmp(cmd_name, "debug") == 0)
	{
		custom_debug_at_command_handler(full_cmd_string);
	}
/* 2009.3.31 added by hongzhe.liu for debug - */	
	else
	{
	       /* unrecognized command */
		/* generate final result code: "ERROR" */
		sprintf(buffer, "ERROR");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	}	
	
	return;
	
}


/*****************************************************************************
* FUNCTION
*  	custom_get_atcmd_symbol()
* DESCRIPTION
*   	This function returns special symbol for customer-defined AT command, 
*   	so AT parser can recognize its a custom command and forward the string to custom_command_handler().
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_atcmd_symbol(void)
{
   return (CUSTOM_SYMBOL);
}


/*****************************************************************************
* FUNCTION
*  	custom_debug_at_command_handler()
* DESCRIPTION
*   	This function returns special symbol for customer-defined AT command, 
*   	so AT parser can recognize its a custom command and forward the string to custom_command_handler().
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*      
*****************************************************************************/
//extern void sensor_reg(kal_uint16 reg_index, kal_uint16 reg_data);
void custom_debug_at_command_handler(char * cmd)
{
/*   
	format : at^lcdrw=19,20,
	meas   : reg = 19,  data = 20, not hex
 */
	char buffer[MAX_UART_LEN];
	char cmd_name[15];
	kal_uint8 index = 3; // we start parsing index after the CUSTOM_SYMBOL 
	kal_uint8 tmp_idx = 0;
	kal_uint16 reg_addr;
	kal_uint16 reg_data;
	char cmd_reg_addr[5];
	char cmd_reg_data[5];

	while ((cmd[index] != '=' ) &&  //might be TEST command or EXE command
			(cmd[index] != '?' ) && // might be READ command
			(cmd[index] != 13 ))  //carriage return
	{
		cmd_name[tmp_idx] = cmd[index] ;
		tmp_idx ++;
		index ++;
	}
	cmd_name[tmp_idx] = '\0' ;

	tmp_idx = 0;
	index ++;
	while ((cmd[index] != ',' ) && (cmd[index] != 13 ))  //carriage return
	{
		cmd_reg_addr[tmp_idx] = cmd[index] ;
		tmp_idx ++;
		index ++;
	}
	cmd_reg_addr[tmp_idx] = '\0' ;
	
	tmp_idx = 0;
	index ++;
	while ((cmd[index] != ',' ) && (cmd[index] != 13 ))  //carriage return
	{
		cmd_reg_data[tmp_idx] = cmd[index] ;
		tmp_idx ++;
		index ++;
	}
	cmd_reg_data[tmp_idx] = '\0' ;

	reg_addr = atoi(cmd_reg_addr);
	reg_data = atoi(cmd_reg_data);

	sprintf(buffer, "write  : 0x%x - 0x%x", reg_addr, reg_data);
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	
	sprintf(buffer, "2 write  : %s - %s", cmd_reg_addr, cmd_reg_data);
	
	
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	//noke_dbg_printf("Sensor write : 0x%x = 0x%x\r\n", lcd_reg, lcd_data); //ghw66
	//sensor_reg( lcd_reg, lcd_data);
}

