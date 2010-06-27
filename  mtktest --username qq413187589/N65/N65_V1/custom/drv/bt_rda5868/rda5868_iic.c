/*************************************************************************
 *
 * MODULE NAME:    rda5868_iic.c
 * PROJECT CODE:   rda5868
 * DESCRIPTION:    rda5868 iic drv.
 * MAINTAINER:     mql
 * CREATION DATE:  18/12/08
 *
 * SOURCE CONTROL: $Id: rda5868_iic.c,v 2.6 2009/8/14 18:08:38 mql Exp $
 *
 * LICENSE:
 *     This source code is copyright (c) 2008-2009 rda.
 *     All rights reserved.
 *
 * NOTES TO USERS:
 *   None.
 *
 *************************************************************************/
#ifdef __BT_RDA5868__
#include "l1audio_def.h"
#include "rda5868.h"

#define DURATION_INIT_1 	20//600ns 
#define DURATION_INIT_2	    20//600ns 
#define DURATION_INIT_3 	20//600ns 

#define DURATION_START_1	20//600ns 
#define DURATION_START_2	24//600ns 
#define DURATION_START_3	24//800ns 

#define DURATION_STOP_1	24//800ns 
#define DURATION_STOP_2	20//600ns 
#define DURATION_STOP_3	50//1300ns

#define DURATION_HIGH		40//900ns 
#define DURATION_LOW		56//1600ns

#define POWER_SETTLING		5*1000*80//80ms//50~100ms




void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_InitIO(char direction, char port);
void GPIO_WriteIO(char data,char port);
char GPIO_ReadIO(char port);
//static char bufferdata[50];
//extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff);

#define DELAY(DURATION)		{unsigned int i; for(i = 1; i <= (DURATION); i++){}}

void RDA_bt_SerialCommStart(void) /* start or re-start */
{
   GPIO_InitIO(1,RDA5868_SDA);
   GPIO_WriteIO(1,RDA5868_SDA);
   GPIO_WriteIO(1,RDA5868_SCL);
   
   DELAY(DURATION_START_1);
   GPIO_WriteIO(0,RDA5868_SDA);   
   DELAY(DURATION_START_2);
   GPIO_WriteIO(0,RDA5868_SCL);
   DELAY(DURATION_START_3);/* start condition */
}

void RDA_bt_SerialCommStop(void)
{
   GPIO_WriteIO(0,RDA5868_SCL);
   DELAY(DURATION_LOW);
   GPIO_InitIO(1,RDA5868_SDA);
   GPIO_WriteIO(0,RDA5868_SDA);
   DELAY(DURATION_STOP_1);
   GPIO_WriteIO(1,RDA5868_SCL);
   DELAY(DURATION_STOP_2);
   GPIO_WriteIO(1,RDA5868_SDA); /* stop condition */
   DELAY(DURATION_STOP_3);
}

uint8 RDA_bt_SerialCommTxByte(uint8 data) /* return 0 --> ack */
{
	int32 i;
	uint8 temp_value = 0;
	for(i=7; (i>=0)&&(i<=7); i--)
	{
		GPIO_WriteIO( 0, RDA5868_SCL); /* low */
		DELAY(DURATION_LOW);
		if(i==7)GPIO_InitIO(1,RDA5868_SDA);
		DELAY(DURATION_LOW);

		GPIO_WriteIO(((data>>i)&0x01), RDA5868_SDA);
		DELAY(DURATION_LOW/2);
		GPIO_WriteIO( 1, RDA5868_SCL); /* high */
		DELAY(DURATION_HIGH);
	}
	GPIO_WriteIO(0, RDA5868_SCL); /* low */
	DELAY(DURATION_LOW);
	GPIO_InitIO(0,RDA5868_SDA);/* input  */
	DELAY(DURATION_LOW/2);
	GPIO_WriteIO(1, RDA5868_SCL); /* high */
	DELAY(DURATION_HIGH);
	temp_value = GPIO_ReadIO(RDA5868_SDA);
	GPIO_WriteIO(0, RDA5868_SCL); /* low */
	DELAY(DURATION_LOW);
	return temp_value;
}

void RDA_bt_SerialCommRxByte(uint8 *data, uint8 ack)
{
	int32 i;
	uint32 dataCache;

	dataCache = 0;
	for(i=7; (i>=0)&&(i<=7); i--)
	{
		GPIO_WriteIO(0, RDA5868_SCL);
		DELAY(DURATION_LOW);
		if(i==7)GPIO_InitIO(0,RDA5868_SDA);
		DELAY(DURATION_LOW);
		GPIO_WriteIO(1, RDA5868_SCL);
		DELAY(DURATION_HIGH);
		dataCache |= (GPIO_ReadIO(RDA5868_SDA)<<i);
		DELAY(DURATION_LOW/2);
	}

	GPIO_WriteIO(0, RDA5868_SCL);
	DELAY(DURATION_LOW);
	GPIO_InitIO(1,RDA5868_SDA);
	GPIO_WriteIO(ack, RDA5868_SDA);
	DELAY(DURATION_LOW/2);
	GPIO_WriteIO(1, RDA5868_SCL);
	DELAY(DURATION_HIGH);
	GPIO_WriteIO(0, RDA5868_SCL); /* low */
	DELAY(DURATION_LOW);
	*data = (uint8)dataCache;
}

void RDA_bt_SerialCommInit(void)
{
	GPIO_ModeSetup(RDA5868_SCL,0);
	GPIO_ModeSetup(RDA5868_SDA,0);
	
	GPIO_InitIO(1,RDA5868_SCL);
	GPIO_InitIO(1,RDA5868_SDA);
	
	GPIO_WriteIO(1,RDA5868_SCL);
	GPIO_WriteIO(1,RDA5868_SDA);   
	DELAY(DURATION_LOW); 
}




//////////////////////////////////////////////5400 iic ///////////////////////////////////////////////////
#define RDA5400_ADRW 0x2c
#define RDA5400_ADRR 0x2d


void rda5400_write_data(unsigned char regaddr, unsigned short *data, unsigned char datalen)
{
	unsigned char i=0;
	
	RDA_bt_SerialCommStart();///start
	RDA_bt_SerialCommTxByte(RDA5400_ADRW);//chip adress
	RDA_bt_SerialCommTxByte(regaddr);

	for(i=0;i<datalen;i++,data++)//data
	{
		RDA_bt_SerialCommTxByte(*data>>8);
		RDA_bt_SerialCommTxByte(*data);
	}
	RDA_bt_SerialCommStop();
}

void rda5400_read_data(unsigned char regaddr, unsigned short *data, unsigned char datalen)
{
	unsigned char tempdata;
	unsigned char i=0;
	
	RDA_bt_SerialCommStart();///start
	RDA_bt_SerialCommTxByte(RDA5400_ADRW);//chip adress
	RDA_bt_SerialCommTxByte(regaddr);
	
	RDA_bt_SerialCommStart();//start
	RDA_bt_SerialCommTxByte(RDA5400_ADRR);//chip adress
	
	for( i=0;i<datalen-1;i++,data++)//data
	{
		RDA_bt_SerialCommRxByte(&tempdata, 0);
		*data = (tempdata<<8);	
		RDA_bt_SerialCommRxByte(&tempdata, 0);			
		*data |= tempdata;		
	}
	
	RDA_bt_SerialCommRxByte(&tempdata, 0);
	*data = (tempdata<<8);	
	RDA_bt_SerialCommRxByte(&tempdata, 1);			
	*data |= tempdata;	
	
	RDA_bt_SerialCommStop();
}










//////////////////////////5868 iic/////////////////////////////////////////////////



#define RDA5868_ADRW 0x2a
#define RDA5868_ADRR 0x2b




void rda5868_write_data(unsigned int regaddr, unsigned int *data, unsigned char datalen)
{
	unsigned char i=0;
	
	RDA_bt_SerialCommStart();///start
	RDA_bt_SerialCommTxByte(RDA5868_ADRW);//chip adress
	RDA_bt_SerialCommTxByte(regaddr>>24);/////reg adress
	RDA_bt_SerialCommTxByte(regaddr>>16);
	RDA_bt_SerialCommTxByte(regaddr>>8);	
	RDA_bt_SerialCommTxByte(regaddr);
	RDA_bt_SerialCommStart();///start
	RDA_bt_SerialCommTxByte(RDA5868_ADRW);//chip adress
	for(i=0;i<datalen;i++,data++)//data
	{
		RDA_bt_SerialCommTxByte(*data>>24);
		RDA_bt_SerialCommTxByte(*data>>16);
		RDA_bt_SerialCommTxByte(*data>>8);
		RDA_bt_SerialCommTxByte(*data);
	}
	RDA_bt_SerialCommStop();
}

void rda5868_read_data(unsigned int regaddr, unsigned int *data, unsigned char datalen)
{
	unsigned char tempdata;
	unsigned char i=0;
	
	RDA_bt_SerialCommStart();///start
	RDA_bt_SerialCommTxByte(RDA5868_ADRW);//chip adress
	RDA_bt_SerialCommTxByte(regaddr>>24);
	RDA_bt_SerialCommTxByte(regaddr>>16);
	RDA_bt_SerialCommTxByte(regaddr>>8);
	RDA_bt_SerialCommTxByte(regaddr);
	
	RDA_bt_SerialCommStart();//start
	RDA_bt_SerialCommTxByte(RDA5868_ADRR);//chip adress
	
	for( i=0;i<datalen-1;i++,data++)//data
	{
		RDA_bt_SerialCommRxByte(&tempdata, 0);
		*data  = (tempdata<<24);	
		RDA_bt_SerialCommRxByte(&tempdata, 0);			
		*data |= (tempdata<<16);				
		RDA_bt_SerialCommRxByte(&tempdata, 0);
		*data |= (tempdata<<8);	
		RDA_bt_SerialCommRxByte(&tempdata, 0);			
		*data |= tempdata;		
	}
	RDA_bt_SerialCommRxByte(&tempdata, 0);
	*data = (tempdata<<24);	
	RDA_bt_SerialCommRxByte(&tempdata, 0);			
	*data |= (tempdata<<16);		
	RDA_bt_SerialCommRxByte(&tempdata, 0);
	*data |= (tempdata<<8);	
	RDA_bt_SerialCommRxByte(&tempdata, 1);			
	*data |= tempdata;	
	
	RDA_bt_SerialCommStop();
}




#endif
