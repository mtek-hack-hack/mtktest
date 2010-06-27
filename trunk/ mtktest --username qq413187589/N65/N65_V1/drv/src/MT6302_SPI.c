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
 *   this file is to be adaption layer for different SPI implementation
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include	"drv_comm.h"
#include	"reg_base.h"
#include	"gpio_sw.h"
#include	"MT6302_spi.h"
#include	"lcd_if_hw.h"
#include	"lcd_if.h"
#include  "..\..\ps\sim\include\sim_trc.h"

#ifdef DRV_MULTIPLE_SIM
extern sim_MT6302_SPIWriter	sim_MT6320_writer;
kal_uint32 MT6302_getLCDSerialInterface(void);
kal_uint32 MT6302_getSPIInterface(void);

#define IMPLEMENTING_ASSERT	ASSERT(0)

kal_uint32	MT6302_SPI_LCDSerialData;
kal_uint8		MT6302_LCD_pdnHandle = 0xff; /*lcd_get_power_handle will return value less than 32, set this as RW 0xff*/
kal_uint8		MT6302_LCD_dummyReadValue;

void noke_drv_mt6302_delay_us(kal_uint32 time)
{
	volatile unsigned long delay;
	for (delay =0;delay <time* /*9600*/ 10;delay++) {} // 1ms


	//unsigned long delay = time*10;  //1us
	//while(delay--) {};
}

void MT6302_Writer_LCD(kal_uint8 data)
{
	kal_uint32 i, loopIndex;

	if(0 != MT6302_getSPIInterface())
		ASSERT(0);

	i = SaveAndSetIRQMask();
	if(DRVPDN_CON1_LCD & DRV_Reg(DRVPDN_CON1)){
		 RestoreIRQMask(i);
		ASSERT(0);
	}

	if(0xc != REG_LCD_SERIAL_CONFIG){
		 RestoreIRQMask(i);
		ASSERT(0);
	}

	if(KAL_FALSE == MT6302_checkSPIMode()){
		RestoreIRQMask(i);
		ASSERT(0);
	}

	/*	becareful that SW will hang on here until LCD controller return RDY signal on bus
	*	accoring to the measurement, in the slowest timing setting, LCD takes 2us to send on byte
	*/
	 //DRV_Reg8(MT6302_SPI_LCDSerialData) = data;
	 DRV_WriteReg8((MT6302_SPI_LCDSerialData), data);

	/*dummy read to make sure former byte has been written on SPI*/
	MT6302_LCD_dummyReadValue = DRV_Reg8(MT6302_SPI_LCDSerialData);
	
	 RestoreIRQMask(i);
	
	// 285 OK
	// 250 FAIL
	
	if( 0x60 == (0xE0 & data))
		//noke_drv_mt6302_delay_us(300);
		noke_drv_mt6302_delay_us(450);
	
}

void MT6302_Writer_GPIO(kal_uint8 data)
{
	kal_uint32 i, j;
	kal_uint8 	MT6302_CS_PIN, MT6302_CLK_PIN, MT6302_DAT_PIN;

	i = SaveAndSetIRQMask();

	if(KAL_FALSE == MT6302_checkSPIMode()){
		RestoreIRQMask(i);
		// some states of 3 SPI pins don't match our expectation.
		ASSERT(0);
	}

	MT6302_CS_PIN=MT6302_getGPIOCS();
	MT6302_CLK_PIN=MT6302_getGPIOCLK();
	MT6302_DAT_PIN=MT6302_getGPIODAT();

	GPIO_WriteIO(0, MT6302_CS_PIN);
	for(j=8;j>0;j--)
	{
		if(data&(0x1<<(j-1)))
			GPIO_WriteIO(1, MT6302_DAT_PIN);
		else
			GPIO_WriteIO(0, MT6302_DAT_PIN);
		
		GPIO_WriteIO(1, MT6302_CLK_PIN);
		GPIO_WriteIO(0, MT6302_CLK_PIN);
	}
	GPIO_WriteIO(0, MT6302_DAT_PIN);
	GPIO_WriteIO(1, MT6302_CS_PIN);

	RestoreIRQMask(i);
}

void MT6302_spiPowerCtrl(kal_bool on)
{
	kal_uint32 i;
	if(0 == MT6302_getSPIInterface())
	{
		if(31 < MT6302_LCD_pdnHandle)
			ASSERT(0);
		
		if (KAL_FALSE == on)
			lcd_clk_disable(MT6302_LCD_pdnHandle);
		else if(KAL_TRUE == on){
			lcd_clk_enable(MT6302_LCD_pdnHandle);
			if(DRVPDN_CON1_LCD & DRV_Reg(DRVPDN_CON1))
				ASSERT(0);
			i = 1000;
			while(i)
				i--;
		}
	else
		ASSERT(0);
	}
	else if(1 == MT6302_getSPIInterface())
	{
		/*we don't know should we do power control before want to write SPI in GPIO implementation*/
	}
	else{
		IMPLEMENTING_ASSERT;
	}
	
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_MT6302_SPI, __LINE__,
		on, DRV_Reg(DRVPDN_CON1), MT6302_getSPIInterface(), MT6302_LCD_pdnHandle,
		drv_get_current_time(), 0
	);
	
}


void MT6302_spiInit(void)
{
	kal_uint32 i;
	
	if(0 == MT6302_getSPIInterface()){
		//power on LCD module
		//DRV_Reg(DRVPDN_CON1_CLR) = DRVPDN_CON1_LCD;
		DRV_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_LCD);

		/*config serial interface*/
		REG_LCD_SERIAL_CONFIG = 0xC;

		i = SaveAndSetIRQMask();
		sim_MT6320_writer = (sim_MT6302_SPIWriter)MT6302_Writer_LCD;
		MT6302_LCD_pdnHandle = lcd_get_power_handle();
		if(31 < MT6302_LCD_pdnHandle){
			RestoreIRQMask(i);
			ASSERT(0);
		}
		RestoreIRQMask(i);
	
		switch(MT6302_getLCDSerialInterface()){
			case 0:
				MT6302_SPI_LCDSerialData = LCD_SERIAL_DATA0_REG;
				break;
			case 1:
				MT6302_SPI_LCDSerialData = LCD_SERIAL_DATA1_REG;
				break;
			default:
				ASSERT(0);
				break;
		}
		
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_MT6302_SPI, __LINE__,
			MT6302_getSPIInterface(), DRV_Reg(DRVPDN_CON1), REG_LCD_SERIAL_CONFIG, MT6302_SPI_LCDSerialData,
			(kal_uint32)sim_MT6320_writer, MT6302_LCD_pdnHandle
		);
	}
	else if(1 == MT6302_getSPIInterface()){
		sim_MT6320_writer = (sim_MT6302_SPIWriter)MT6302_Writer_GPIO;
		if((0xff == MT6302_getGPIOCS()) || (0xff == MT6302_getGPIOCLK()) || (0xff == MT6302_getGPIODAT()))
			ASSERT(0);
	}
	else{
		IMPLEMENTING_ASSERT;
	}
}
#endif
