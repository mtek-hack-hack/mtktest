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
 *    serial_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines Serial Interface.
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
#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
#include 	"kal_release.h" 
#include    "drv_comm.h" 
#include    "gpio_hw.h"
#include    "gpio_sw.h"
#include    "touch_panel_spi.h"
//#include    "serial_interface.h"

 
#define 	 ZERO_FIELD_COUNT 0 /*zero filled cycles*/
void serial_write_data(kal_uint8 data);
kal_uint16 serial_read_data(void);
     
/*------------------B2PSI_SERIAL_SHARED---------------------*/
 static volatile kal_uint8 b2spi_serial_num =0;

 static  kal_bool b2spi_mode = KAL_TRUE;

void b2spi_serial_lock()
{
	while(b2spi_serial_num)
	 	kal_sleep_task(1);
	b2spi_serial_num = 1;
}
void b2spi_serial_unlock()
{
	b2spi_serial_num = 0;
}
void serial_init_sharePin(void)
{
	if(!b2spi_mode)return;

	b2spi_mode = KAL_FALSE;


	GPIO_WriteIO(0,SPI_CS_PIN);

	GPIO_ModeSetup(SPI_DIN_PIN,  0x0);
	GPIO_ModeSetup(SPI_CLK_PIN,  0x0);

	GPIO_InitIO(OUTPUT,SPI_DIN_PIN); 
	GPIO_InitIO(OUTPUT,SPI_CLK_PIN);

	GPIO_WriteIO(0, SPI_DIN_PIN);
	GPIO_WriteIO(0, SPI_CLK_PIN);
	
}
void B2PSI_init_sharePin(void)
{
	if(b2spi_mode)
		return;
	b2spi_mode = KAL_TRUE;

	GPIO_WriteIO(1,SPI_CS_PIN);
}	
/*------------------B2PSI_SERIAL_SHARED---------------------*/
/*************************************************************************
* FUNCTION
*	serial_init
*
* DESCRIPTION
*	This function initializes serial interface.
*
* PARAMETERS
*  None
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void serial_init(void) 
{ 
   kal_uint16 delay;
	kal_int16 x, y;
   
	GPIO_WriteIO(0,SPI_CS_PIN);
   GPIO_ModeSetup(SPI_DIN_PIN,  0x0);
   GPIO_ModeSetup(SPI_CLK_PIN,  0x0);
   GPIO_ModeSetup(SPI_DOUT_PIN, 0x0); 
   GPIO_ModeSetup(SPI_CS_PIN,   0x0);
   GPIO_ModeSetup(SPI_BUSY_PIN, 0x0);  
   GPIO_InitIO(OUTPUT,SPI_DIN_PIN); 
   GPIO_InitIO(OUTPUT,SPI_CLK_PIN);
   GPIO_InitIO(INPUT,SPI_DOUT_PIN);
   GPIO_InitIO(OUTPUT,SPI_CS_PIN);
   GPIO_InitIO(INPUT,SPI_BUSY_PIN);
   GPIO_WriteIO(0,SPI_CS_PIN);
/*------------------B2PSI_SERIAL_SHARED---------------------*/
 	serial_init_sharePin();
/*------------------B2PSI_SERIAL_SHARED---------------------*/
   
   /*AR7643 needs this, so weird*/
   for(delay=0;delay<1000;delay++){};   
   //tp_read_adc(&x, &y);
}
/*************************************************************************
* FUNCTION
*	serial_delay
*
* DESCRIPTION
*	This function is to add delay.
*
* PARAMETERS
*  None
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void serial_delay(void)
{
   kal_uint16 delay;
   for(delay=0;delay<0;delay++){}
}
/*************************************************************************
* FUNCTION
*	serial_write_bit_high
*
* DESCRIPTION
*	This function is to set a bit as high.
*
* PARAMETERS
*  None
* RETURNS
*	None    
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*write 1*/
void serial_write_bit_high(void)
{
   SET_DATA_HIGH();         /*    ----              */
   SET_CLK_LOW();           /*     _-_             */
   serial_delay();
   SET_CLK_HIGH();
   serial_delay();
   SET_CLK_LOW();
}
/*************************************************************************
* FUNCTION
*	serial_write_bit_low
*
* DESCRIPTION
*	This function is to set a bit as low.
*
* PARAMETERS
*  None
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*write 0*/
void serial_write_bit_low(void)
{
   SET_DATA_LOW();          /*    ____              */
   SET_CLK_LOW();           /*     _-_             */
   serial_delay();
   SET_CLK_HIGH();
   serial_delay();
   SET_CLK_LOW();
}
/*************************************************************************
* FUNCTION
*	serial_read_data
*
* DESCRIPTION
*	This function is to read data via SPI.
*
* PARAMETERS
*  None
*
* RETURNS
*	received data
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*read*/
kal_uint16 serial_read_data(void)
{ 
   kal_uint16 data=0; 
   kal_int16    i;        
   kal_uint32 savedMask;
   kal_uint32 retry=0;	

   //savedMask = SaveAndSetIRQMask();
   SET_CLK_LOW();
   SET_CLK_HIGH();
   while(GET_BUSY_BIT())
   {

 	   SET_CLK_LOW();
   	SET_CLK_HIGH();
   	retry++;
   	if(retry>1000000)/*give up the read. controller may be broken*/
   		return 0;
   	};
   for(i=11;i>=0;i--)
   {
      //SET_CLK_LOW();
      //serial_delay();
      SET_CLK_HIGH();
      serial_delay();
		if(GET_DATA_BIT())
			data |= (1<<i); 

		SET_CLK_LOW();
		serial_delay();
   }
   for(i=0;i<ZERO_FIELD_COUNT;i++)
   {
      SET_CLK_LOW();
      serial_delay();
      SET_CLK_HIGH();
      SET_CLK_LOW();  
   }
   data&=0x3fff;
   //RestoreIRQMask(savedMask);
   return data;
}
/*************************************************************************
* FUNCTION
*	serial_write_data
*
* DESCRIPTION
*	This function is to write data via SPI.
*
* PARAMETERS
*  transmitted data
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void serial_write_data(kal_uint8 data)
{
   kal_int8 i;
   //kal_uint32 savedMask;
   //savedMask = SaveAndSetIRQMask();

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (data & (1<<i))
		{
		   serial_write_bit_high();
		}
		else
		{
			serial_write_bit_low();
		}
	}
   SET_DATA_LOW(); 
	//RestoreIRQMask(savedMask);
}

#endif







