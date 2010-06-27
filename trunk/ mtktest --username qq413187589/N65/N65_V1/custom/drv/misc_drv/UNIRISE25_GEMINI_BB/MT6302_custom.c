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
 * MT6302_interface.C
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file is custom implementation of MT6302 SPI interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include	"drv_comm.h"
#include	"gpio_sw.h"
#include	"MT6302_spi.h"

/*
* FUNCTION                                                            
*	MT6302_getLCDSerialInterface
*
* DESCRIPTION                                                           
*   	This function is to return which LCD serial interface we use to implement SPI
*	If customer doesn't use LCD interface, this function should return 0xff
*
* CALLS  
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of serial interface BB has: the interface we use
*	0xff: customer doesn't use LCD interface to implement SPI
*
*/
kal_uint32 MT6302_getLCDSerialInterface(void)
{
	return 1;
}


/*
* FUNCTION                                                            
*	MT6302_getSPIInterface
*
* DESCRIPTION                                                           
*   	This function is to return which method do we use to implement SPI interface
*
* CALLS  
*
* PARAMETERS
*	none
*
* RETURNS
*	0: use LCD serial interface
*	1: use GPIO
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint32 MT6302_getSPIInterface(void)
{
	return MT6302_SPI_USE_LCD; 
}


/*
* FUNCTION                                                            
*	MT6302_checkSPIMode
*
* DESCRIPTION                                                           
*   	This function is check the SPI 3 pins are in correct mode, no matter use LCD or GPIO to implement
*	customer should add its check code here, or just return kal_true in case they don't want to protect
*
* CALLS  
*
* PARAMETERS
*	none
*
* RETURNS
*	kal_true: control pins are all in correct mode
*	kal_false: control pins are not in correct mode
*
*/
kal_bool MT6302_checkSPIMode(void)
{
	/*29 is SPI clk, 31 is SPI dat, 33 is SPI cs*/
	if(1 != GPIO_ReturnMode(29) || 1 != GPIO_ReturnMode(31) || 1 != GPIO_ReturnMode(33))
		return KAL_FALSE;
	else
		return KAL_TRUE;
	return MT6302_SPI_USE_LCD;
}



/*
* FUNCTION                                                            
*	MT6302_getGPIOCLK
*
* DESCRIPTION                                                           
*   	This function is to return which GPIO we use to implement SPI CLK
*	If customer doesn't GPIO to implement SPI, this function should return 0xff
*	This function is only work when customer used GPIO to implement SPI and CUSTOM_NEW is not defined.
*
* CALLS  
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of GPIO BB has: the GPIO we use
*	0xff: customer doesn't use GPIO to implement SPI CLK
*
*/
kal_uint32 MT6302_getGPIOCLK()
{
	return 0xff;
}

/*
* FUNCTION                                                            
*	MT6302_getGPIOCLK
*
* DESCRIPTION                                                           
*   	This function is to return which GPIO we use to implement SPI CLK
*	If customer doesn't GPIO to implement SPI, this function should return 0xff
*	This function is only work when customer used GPIO to implement SPI and CUSTOM_NEW is not defined.
*
* CALLS  
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of GPIO BB has: the GPIO we use
*	0xff: customer doesn't use GPIO to implement SPI CLK
*
*/
kal_uint32 MT6302_getGPIOCS()
{
	return 0xff;
}

/*
* FUNCTION                                                            
*	MT6302_getGPIOCLK
*
* DESCRIPTION                                                           
*   	This function is to return which GPIO we use to implement SPI CLK
*	If customer doesn't GPIO to implement SPI, this function should return 0xff
*	This function is only work when customer used GPIO to implement SPI and CUSTOM_NEW is not defined.
*
* CALLS  
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of GPIO BB has: the GPIO we use
*	0xff: customer doesn't use GPIO to implement SPI CLK
*
*/
kal_uint32 MT6302_getGPIODAT()
{
	return 0xff;
}
