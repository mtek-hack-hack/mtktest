#if (defined(RDA5800) || defined(RDA5802) || defined(RDA5802E)|| defined(RDA5803))   
#include "l1audio_def.h"
#define READ	1
#define WRITE	0


// Huyanwei Add It For  Compile
#if !defined(GPIO_MAGIC_NUM)
#define GPIO_MAGIC_NUM (0x80)
#endif

#if !defined(GPO_MAGIC_NUM)
#define GPO_MAGIC_NUM (0x70)
#endif

#define ADRW 0x20
#define ADRR 0x21
#define DURATION_INIT_1 	20//600ns 
#define DURATION_INIT_2		20//600ns 
#define DURATION_INIT_3 	20//600ns 

#define DURATION_START_1	20//600ns 
#define DURATION_START_2	24//600ns 
#define DURATION_START_3	24//800ns 

#define DURATION_STOP_1		24//800ns 
#define DURATION_STOP_2		20//600ns 
#define DURATION_STOP_3		50//1300ns

#define DURATION_HIGH			26//900ns 
#define DURATION_LOW			70//1600ns

#define POWER_SETTLING		5*1000*80//80ms//50~100ms

extern const char gpio_fm_32k;

#define CRYCLK 			gpio_fm_32k

#define CRYCLK_MSK          3				///设置时钟输出类型, 根据Pin需要作出修改
#define RST     		       254       ///LE pin
#define SDA  				9  		///I2C data pin  
#define SCL  				8      ///I2C clock pin

uint16 RDAFMChipID;
void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_InitIO(char direction, char port);
void GPIO_WriteIO(char data,char port);
char GPIO_ReadIO(char port);
#define DELAY(DURATION)		{unsigned int i; for(i = 1; i <= (DURATION); i++){}}

void SerialCommStart(void) /* start or re-start */
{
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(1,SDA);
   GPIO_WriteIO(1,SCL);
   DELAY(DURATION_START_1);
   GPIO_WriteIO(0,SDA);   
   DELAY(DURATION_START_2);
   GPIO_WriteIO(0,SCL);
   DELAY(DURATION_START_3);/* start condition */
}

void SerialCommStop(void)
{
   GPIO_WriteIO(0,SCL);
   DELAY(DURATION_LOW);
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(0,SDA);
   DELAY(DURATION_STOP_1);
   GPIO_WriteIO(1,SCL);
   DELAY(DURATION_STOP_2);
   GPIO_WriteIO(1,SDA); /* stop condition */
   DELAY(DURATION_STOP_3);
}
void FM_Stop(void)
{
		GPIO_ModeSetup(SDA,0);
		GPIO_ModeSetup(SCL,0);
		GPIO_InitIO(1, SDA);		
		GPIO_InitIO(1, SCL);	
		GPIO_WriteIO(0, SDA);		
		GPIO_WriteIO(0, SCL);	
}
uint8 SerialCommTxByte(uint8 data) /* return 0 --> ack */
{
   int32 i;
   uint8 temp_value = 0;
   for(i=7; (i>=0)&&(i<=7); i--){
      GPIO_WriteIO( 0, SCL); /* low */
      DELAY(DURATION_LOW);
       if(i==7)GPIO_InitIO(1,SDA);
      DELAY(DURATION_LOW);
   
      GPIO_WriteIO(((data>>i)&0x01), SDA);
      DELAY(DURATION_LOW/2);
      GPIO_WriteIO( 1, SCL); /* high */
      DELAY(DURATION_HIGH);
   }
   GPIO_WriteIO(0, SCL); /* low */
   DELAY(DURATION_LOW);
   GPIO_InitIO(0,SDA);/* input  */
   DELAY(DURATION_LOW/2);
   GPIO_WriteIO(1, SCL); /* high */
   DELAY(DURATION_HIGH);
   temp_value = GPIO_ReadIO(SDA);
   //kal_prompt_trace(MOD_MED_V,"SerialCommTxByte()   temp_value =%d ,GPIO_DATA=%d ",temp_value,(SDA));  
   return temp_value;
}

void SerialCommRxByte(uint8 *data, uint8 ack)
{
   int32 i;
   uint32 dataCache;

   dataCache = 0;
   for(i=7; (i>=0)&&(i<=7); i--){
      GPIO_WriteIO(0, SCL);
      DELAY(DURATION_LOW);
       if(i==7)GPIO_InitIO(0,SDA);
      DELAY(DURATION_LOW);
      GPIO_WriteIO(1, SCL);
      DELAY(DURATION_HIGH);
      dataCache |= (GPIO_ReadIO(SDA)<<i);
      DELAY(DURATION_LOW/2);
   }
   
   GPIO_WriteIO(0, SCL);
   DELAY(DURATION_LOW);
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(ack, SDA);
   DELAY(DURATION_LOW/2);
   GPIO_WriteIO(1, SCL);
   DELAY(DURATION_HIGH);
   *data = (uint8)dataCache;
}

void SerialCommInit(void)
{
	GPIO_ModeSetup(SCL,0);
	GPIO_ModeSetup(SDA,0);

#if (defined(RST))  	
	GPIO_ModeSetup(RST,0);
#endif 	
	   
	GPIO_InitIO(1,SCL);
	GPIO_InitIO(1,SDA);
	
#if (defined(RST))  		
	GPIO_InitIO(1,RST);
#endif	
		
	GPIO_WriteIO(1,SCL);
  GPIO_WriteIO(1,SDA);    
}

void SerialCommCryClkOn(void)
{
	if ((CRYCLK& GPIO_MAGIC_NUM) == GPIO_MAGIC_NUM)
	{
		GPIO_InitIO(1, CRYCLK);
		GPIO_ModeSetup(CRYCLK, CRYCLK_MSK);
	}
	else
	{
	     GPO_ModeSetup(CRYCLK, CRYCLK_MSK);
	}
}

void SerialCommCryClkOff(void)
{              
	DELAY(DURATION_LOW);
	if ((CRYCLK& GPIO_MAGIC_NUM) == GPIO_MAGIC_NUM)
	{
		GPIO_InitIO(1, CRYCLK);
	GPIO_ModeSetup(CRYCLK,0);
	}
	else
	{
	     GPO_ModeSetup(CRYCLK, 0);
	}
	GPIO_WriteIO(1,SDA);
	GPIO_WriteIO(1,SCL);  
}



uint8 OperationRDAFM_2w(uint8 operation, uint8 *data, uint8 numBytes)
{
	uint8 j;
	uint8 acknowledge=0;

/***************************************************

START: make sure here SDIO_DIR =OUT, SCLK = 1,	SDIO = 1

****************************************************/
  SerialCommStart();

/***************************************************

WRITE CONTROL DATA: make sure here: SLCK = 0; SDIO = 0

****************************************************/

/***************************

CHECK ACK for control word

***************************/

	if(operation == READ)
		 acknowledge = SerialCommTxByte(ADRR);
	else 
		 acknowledge = SerialCommTxByte(ADRW);
	
 //kal_prompt_trace(MOD_MED_V,"OperationRDAFM_2w   lrjaaaaaa acknowledge =%d ",acknowledge);  


/***************************************

WRITE or READ data

****************************************/	

/******************************

CHECK ACK or SEND ACK=0

*******************************/

for(j = 0; j < numBytes; j++, data++)
{
	if(operation == READ)
	{
	if(j == (numBytes -1))
		SerialCommRxByte(data,1); 
	else
		SerialCommRxByte(data, 0); 
	}	 
	else 
		acknowledge = SerialCommTxByte(*data);   
	//kal_prompt_trace(MOD_MED_V,"OperationRDAFM_2w numBytes =%d acknowledge=%d,data=%x",numBytes,acknowledge,*data);  //lrj  add for test 20060522
	
}
/****************************

STOP: make sure here: SCLK = 0

*****************************/
   SerialCommStop();
   
      return acknowledge;

}

uint16 RDAFM_GetChipID(void)
{
	uint8 RDAFM_reg_data[6]={0};
	uint16 cChipID;
	
	SerialCommInit();
	
	GPIO_WriteIO(0, SCL);
	DELAY(DURATION_LOW);
	GPIO_WriteIO(1, SCL);
	DELAY(DURATION_LOW*30);
  
#if (defined(RST))     
	GPIO_WriteIO(0,RST);
	DELAY(DURATION_LOW*30);
#endif
	
	GPIO_WriteIO(1,SDA);
	GPIO_WriteIO(1,SCL);
	
	RDAFM_reg_data[0]=0x00;
	RDAFM_reg_data[1]=0x00;
	OperationRDAFM_2w(WRITE,&(RDAFM_reg_data[0]), 2);
	kal_sleep_task(5);
	
	OperationRDAFM_2w(READ,&(RDAFM_reg_data[0]), 6);
	cChipID=(RDAFM_reg_data[4]*0x100)+ RDAFM_reg_data[5];
	if(0x5802==cChipID || 0x5803==cChipID )
	{
		RDAFMChipID=0x5802;
		return(0x5802);
	}	
	
	SerialCommInit();
	
#if (defined(RST))  	
	GPIO_WriteIO(0,RST);
	DELAY(DURATION_LOW*30);
	GPIO_WriteIO(1,RST);
#endif

	GPIO_WriteIO(1,SDA);
  GPIO_WriteIO(1,SCL);
  
	RDAFM_reg_data[0]=0x00;
	RDAFM_reg_data[1]=0x00;
	OperationRDAFM_2w(WRITE,&(RDAFM_reg_data[0]), 2);
	kal_sleep_task(18);
	 
	OperationRDAFM_2w(READ,&(RDAFM_reg_data[0]), 6);
	cChipID=(RDAFM_reg_data[4]*0x100)+ RDAFM_reg_data[5];
	if(0x5800==cChipID)
	{
		RDAFMChipID=0x5800;
		return(0x5800);
	}	
	return(0xFFFF);		
}
#endif
