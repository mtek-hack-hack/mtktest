#include "l1audio_def.h"

#if (defined(RDA5800) || defined(RDA5802)|| defined(RDA5802E) || defined(RDA5803))   
#define READ	1
#define WRITE	0

#define ADRW 0x20
#define ADRR 0x21

/***************************************************
Extern Definitions and Types
****************************************************/
/***************************************************
Serial communication interfaces 
****************************************************/
void SerialCommInit(void);
void SerialCommCryClkOn(void);
void SerialCommCryClkOff(void);
void SerialCommRxByte(uint8 *data, uint8 ack);
uint8 SerialCommTxByte(uint8 data);
void SerialCommStop(void);
void SerialCommStart(void);
uint8 OperationRDAFM_2w(uint8 operation, uint8 *data, uint8 numBytes);
uint16 RDAFM_GetChipID(void);
void FM_Stop(void);
/***************************************************
Local Definitions and Types
****************************************************/
/***************************************************
RDA5802 interfaces
****************************************************/
void  RDA5802_PowerOnReset(void);
void  RDA5802_PowerOffProc(void);
void	RDA5802_ChipInit(void);
void	RDA5802_Mute(uint8 mute);
uint16	RDA5802_FreqToChan(uint16 frequency);
void	RDA5802_SetFreq( int16 curf );
uint8 RDA5802_ValidStop(int16 freq);
uint8 RDA5802_GetSigLvl( int16 curf );
void	RDA5802_SetVolumeLevel(uint8 level);
bool  RDA5802_Intialization(void);
/***************************************************
RDA5800 interfaces
****************************************************/
void	RDA5800_PowerOnReset(void);
void  RDA5800_PowerOffProc(void);
void	RDA5800_ChipInit(void);
void	RDA5800_Mute(uint8 mute);
uint16	RDA5800_FreqToChan(uint16 frequency);
void	RDA5800_SetFreq(int16 curFreq);
uint8	RDA5800_ValidStop(int16 freq);
uint8	RDA5800_GetSigLvl(int16 curf );
void	RDA5800_SetVolumeLevel(uint8 level);
bool	RDA5800_Intialization(void);
/***************************************************
Local variables
****************************************************/
static uint16 RDAFMChipID;
/***************************************************
MTK API
****************************************************/
void  FMDrv_PowerOnReset(void)
{
	if(0x5802==RDAFMChipID)
	{	
		RDA5802_PowerOnReset();
	}
	else if(0x5800==RDAFMChipID)
	{
		RDA5800_PowerOnReset();
	}
}

void  FMDrv_PowerOffProc(void)
{
	if(0x5802==RDAFMChipID)
	{
		RDA5802_PowerOffProc();
	}
	else if(0x5800==RDAFMChipID)
	{
		RDA5800_PowerOffProc();
	}
	FM_Stop();
}

void FMDrv_ChipInit()
{
/* 2009.05.20 modified by hongzhe.liu for camera confilict fm + */
/*
	RDAFMChipID=0;
	RDAFMChipID=RDAFM_GetChipID();
*/
#ifdef RDA5800
	RDAFMChipID = 0x5800;
#elif defined RDA5802
	RDAFMChipID = 0x5802;
#elif defined RDA5802E
	RDAFMChipID = 0x5802;
#elif defined RDA5803
	RDAFMChipID = 0x5803;
#else
	#error "U should give a support rda fm chip id!"
#endif
/* 2009.05.20 modified by hongzhe.liu for camera confilict fm - */

	if(0x5802==RDAFMChipID)
	{	
		RDA5802_ChipInit();
	}	
	else if(0x5800==RDAFMChipID)
	{
		RDA5800_ChipInit();
	}	
}

void  FMDrv_Mute(uint8 mute)
{
	if(0x5802==RDAFMChipID)
	{
		RDA5802_Mute(mute);
	}
	else if(0x5800==RDAFMChipID)
	{
		RDA5800_Mute(mute);
	}		 
}
void  FMDrv_SetFreq( int16 curf )
{ 
	if(0x5802==RDAFMChipID)
	{	  
		RDA5802_SetFreq(curf);
	}
	else if(0x5800==RDAFMChipID)
	{
		RDA5800_SetFreq(curf);
	}	
}

uint8 FMDrv_ValidStop(int16 freq, int8 signalvl, bool is_step_up)  /* 自动搜索时，作为判定条件，再从中选择信号最强的9个台*/
{
	bool result;
	if(0x5802==RDAFMChipID)
	{	 	
		result=RDA5802_ValidStop(freq);
	}
	else if(0x5800==RDAFMChipID)
	{
		result=RDA5800_ValidStop(freq);
	}	
	return result;
}

uint8 FMDrv_GetSigLvl( int16 curf )  /*当满足rssi 的条件时，将信号记录，再选最强的9个频段*/
{  
	uint8 result;	
	if(0x5802==RDAFMChipID)
	{	
		result=RDA5802_GetSigLvl(curf);
	}
	else if(0x5800==RDAFMChipID)
	{
		result=RDA5802_GetSigLvl(curf);
	}
	return result;
}

bool  FMDrv_IsChipValid(void)
{
	bool result=0;
	RDAFMChipID=0;
	RDAFMChipID=RDAFM_GetChipID();
	if(0x5802==RDAFMChipID)
	{	
		result=1;
	}
	else if(0x5800==RDAFMChipID)
	{
		result=1;
	}
	return result;
}

void  FMDrv_SetVolumeLevel(uint8 level)   /*一般不调用，即不用芯片来调节音量。*/
{
	if(0x5802==RDAFMChipID)
	{	
		RDA5802_SetVolumeLevel(level);
	}
	else if(0x5800==RDAFMChipID)
	{
		RDA5800_SetVolumeLevel(level);
	}		
}

/***************************************************
RDA5802
****************************************************/
uint8 RDA5802_initialization_reg[]={
0xC0, 0x01, //02H: 
0x00, 0x00,        
0x04, 0x00,        
#ifdef FM_RADIO_INTERNAL_ANTENNA
0x88, 0x7F, //05H: 
#else
0x88, 0xAF, //05H: 
#endif
0x00, 0x00,        
0x5E, 0xC6,        
0x50, 0x96,        
0x00, 0x00,        
0x40, 0x00, //0AH: 
0x00, 0x8F,        
0x00, 0x00,        
0x00, 0x00,        
0x00, 0x00,        
0x00, 0x00,        
0xF0, 0x05, //10H: 
0x90, 0x00,        
0xF4, 0x84,        
0x70, 0x01,        
0x40, 0xF0,        
0x21, 0x80, //15H: 
0x7A, 0xD0,        
0x3E, 0x40,        
0x55, 0xA9,        
0xE8, 0x48,        
0x50, 0x80, //1AH: 
0x00, 0x00,        
0x37, 0xB6,        
0x40, 0x0C,        
0x07, 0x9B,        
0x4C, 0x1D,        
0x81, 0x11, //20H: 
0x45, 0x80,        
};

void  RDA5802_PowerOnReset(void)
{
	SerialCommCryClkOn();
	kal_sleep_task(1);
	SerialCommInit(); 
	RDA5802_Intialization(); 
}

void  RDA5802_PowerOffProc(void)
{

	uint8 RDA5802_poweroff[] ={0x00,0x00};  
	OperationRDAFM_2w(WRITE, &(RDA5802_poweroff[0]), 2);
	SerialCommCryClkOff();
}

void RDA5802_ChipInit(void)
{
	SerialCommCryClkOn();
	kal_sleep_task(1);
	SerialCommInit();
	RDA5802_Intialization();
	FMDrv_PowerOffProc();
}

void RDA5802_Mute(uint8 mute)
{
	uint8 RDA5802_Muteon[] ={0x80,0x01}; 
	uint8 RDA5802_Muteclose[] ={0xc0,0x01}; 
	if(mute)
	 OperationRDAFM_2w(WRITE, &(RDA5802_Muteon[0]), 2);
	else
	 OperationRDAFM_2w(WRITE, &(RDA5802_Muteclose[0]), 2);
}

uint16 RDA5802_FreqToChan(uint16 frequency) 
{
	uint8 channelSpacing;
	uint16 bottomOfBand;
	uint16 channel;

	if ((RDA5802_initialization_reg[3] & 0x0c) == 0x00) 
		bottomOfBand = 870;
	else if ((RDA5802_initialization_reg[3] & 0x0c) == 0x04)	
		bottomOfBand = 760;
	else if ((RDA5802_initialization_reg[3] & 0x0c) == 0x08)	
		bottomOfBand = 760;	
	if ((RDA5802_initialization_reg[3] & 0x03) == 0x00) 
		channelSpacing = 1;
	else if ((RDA5802_initialization_reg[3] & 0x03) == 0x01) 
		channelSpacing = 2;

	channel = (frequency - bottomOfBand) / channelSpacing;
	return (channel);
}

void RDA5802_SetFreq( int16 curFreq )
{   
	uint8 RDA5802_channel_start_tune[] ={0xc0,0x01,0x00,0x10}; 	//87.0MHz
	uint16 curChan;
	
	curChan=RDA5802_FreqToChan(curFreq);
	RDA5802_channel_start_tune[2]=curChan>>2;
	RDA5802_channel_start_tune[3]=(((curChan&0x0003)<<6)|0x10) | (RDA5802_initialization_reg[3]&0x0f);	//set tune bit
	
	OperationRDAFM_2w(WRITE, &(RDA5802_channel_start_tune[0]), 4);
	kal_sleep_task(5);
}

uint8 RDA5802_ValidStop(int16 freq)  /* 自动搜索时，作为判定条件，再从中选择信号最强的9个台*/
{
	uint8 RDA5802_reg_data[4]={0};	
	uint8 RDA5802_channel_seek[] = {0xc0,0x01};
	uint8 falseStation = 0;
	uint16 curChan;
	
	curChan=RDA5802_FreqToChan(freq);
	
	RDA5802_reg_data[0]=RDA5802_channel_seek[0];
	RDA5802_reg_data[1]=RDA5802_channel_seek[1];
	RDA5802_reg_data[2]=curChan>>2;
	RDA5802_reg_data[3]=(((curChan&0x0003)<<6)|0x10) | (RDA5802_initialization_reg[3]&0x0f);
	OperationRDAFM_2w(WRITE,&(RDA5802_reg_data[0]), 4);
	
	kal_sleep_task(8);   	

	//read REG0A&0B	
	OperationRDAFM_2w(READ,&(RDA5802_reg_data[0]), 4);			
	//check whether STC=1
	if((RDA5802_reg_data[0]&0x40)==0) falseStation=1;
	//check FM_TURE
	if((RDA5802_reg_data[2] &0x01)==0) falseStation=1;
		
	if (falseStation==1)
		return 0;   
	else 
		return 1;
}

uint8 RDA5802_GetSigLvl( int16 curf )  /*当满足rssi 的条件时，将信号记录，再选最强的9个频段*/
{    
	uint8 RDA5802_reg_data[4]={0};	
	if(875==curf)
			return(1);
	else
		OperationRDAFM_2w(READ,&(RDA5802_reg_data[0]), 4);
	return  (RDA5802_reg_data[2]>>1);  /*返回rssi*/
}

void RDA5802_SetVolumeLevel(uint8 level)   /*一般不调用，即不用芯片来调节音量。*/
{
	RDA5802_initialization_reg[7]=( RDA5802_initialization_reg[7] & 0xf0 ) | level; 
	OperationRDAFM_2w(WRITE, &(RDA5802_initialization_reg[0]), 8);
}

bool  RDA5802_Intialization(void)
{
	uint8 error_ind = 0;
	uint8 RDA5802_REG[]={0x00,0x02};
	
	error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5802_REG[0], 2);
	kal_sleep_task(1);
	error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5802_initialization_reg[0], sizeof(RDA5802_initialization_reg));
	#if (defined(XTAL))
		kal_sleep_task(120);
	#else
		kal_sleep_task(5);	
	#endif
	
	
	if (error_ind )
	   return 0;
	else
	   return 1;
}

/***************************************************
RDA5800
****************************************************/
uint8 RDA5800_initialization_reg[]={
//0x00,0x00,
//0x00,0x00,	
0xc8,0x81,	//0x02
0x00,0x00,
0x44,0x00,	//0x04
0x0c,0xff, //0x13ff, lilin, 06/22, 0x10f8, //0x05
0x00,0x00,
0x00,0xcd,
0x00,0x96,
0x00,0x20,
0x41,0x63,
0x08,0x06,
0x58,0x00,
0x58,0x00,
0x58,0x00,
0x58,0x00,
0x4c,0x17,	//lilin, 08/13, seek_singlestep, 0x4817,
0x20,0xa2,
0x00,0x00,
0x00,0x0f,
0x06,0xde,
0xec,0xc0,
0x02,0x00,
0x53,0x83,
0x95,0xa4,
0xe8,0x48,
0x05,0x00,	//0x0500, lilin, 06/22, 0x0500,
0x00,0xa4, //0x00a4, lilin, 06/22, 0x00a4,
0x88,0x9b,
0x0d,0x84,
0x4f,0x04,
0x88,0x32,
0x7f,0x71,
0x06,0x60,
0x40,0x10,
0x60,0x02,
0x18,0x08,
0x64,0x58,
0x78,0x7f,
0x01,0x00,
0xc0,0x40,
0xc0,0x20,
0x00,0x24,
0x04,0x00,
0x00,0x20,
};

void  RDA5800_PowerOnReset(void)
{
   SerialCommCryClkOn();
   kal_sleep_task(1);   
   SerialCommInit();
   RDA5800_Intialization(); 
}

void  RDA5800_PowerOffProc(void)
{
	uint8 RDA5800_poweroff[] ={0x00,0x00};  
	OperationRDAFM_2w(WRITE, &(RDA5800_poweroff[0]), 2);
	SerialCommCryClkOff();
}

void RDA5800_ChipInit(void)
{
	SerialCommCryClkOn();
	kal_sleep_task(1);
	SerialCommInit();
	RDA5800_Intialization();
	FMDrv_PowerOffProc();
}

void  RDA5800_Mute(uint8 mute)
{
	uint8 RDA5800_Muteon[] ={0x88,0x81}; 
	uint8 RDA5800_Muteclose[] ={0xc8,0x81}; 
	if(mute)
		OperationRDAFM_2w(WRITE, &(RDA5800_Muteon[0]), 2);
	else
		OperationRDAFM_2w(WRITE, &(RDA5800_Muteclose[0]), 2);
}

uint16 RDA5800_FreqToChan(uint16 frequency) 
{
	uint8 channelSpacing;
	uint16 bottomOfBand;
	uint16 channel;
	
	if ((RDA5800_initialization_reg[3] & 0x02) == 0x00) 
		bottomOfBand = 875;
	else 	
		bottomOfBand = 760;
	if ((RDA5800_initialization_reg[3] & 0x01) == 0x00) 
		channelSpacing = 1;
	else if ((RDA5800_initialization_reg[5] & 0x01) == 0x01) 
		channelSpacing = 2;
	else 
		channelSpacing = 1;
		
	channel = (frequency - bottomOfBand) / channelSpacing;
	
	return (channel);	
}

void  RDA5800_SetFreq(int16 curFreq)
{  
	uint8 RDA5800_channel_start_tune[] ={0xc8,0x81,0x00,0x00};
	uint16 curChan;

	curChan=RDA5800_FreqToChan(curFreq);
	RDA5800_channel_start_tune[2]=curChan;
	RDA5800_channel_start_tune[3]=RDA5800_initialization_reg[3];
	
	OperationRDAFM_2w(WRITE, &(RDA5800_channel_start_tune[0]), 4);
	kal_sleep_task(18);
	
}

uint8 RDA5800_ValidStop(int16 freq)  /* 自动搜索时，作为判定条件，再从中选择信号最强的9个台*/
{ 
	uint8 RDA5800_reg_data[4]={0};	
	uint8 RDA5800_channel_seek_up[] = {0xcb,0x81};
	uint8 falseStation = 0;
	uint16 curChan;
	
	curChan=RDA5800_FreqToChan(freq);
	
	RDA5800_reg_data[0]=RDA5800_channel_seek_up[0];
	RDA5800_reg_data[1]=RDA5800_channel_seek_up[1];
	RDA5800_reg_data[2]=curChan;
	RDA5800_reg_data[3]=RDA5800_initialization_reg[3];
	OperationRDAFM_2w(WRITE,&(RDA5800_reg_data[0]), 4);
	kal_sleep_task(18);   	

	//read REG0A&0B	
	OperationRDAFM_2w(READ,&(RDA5800_reg_data[0]), 4);			
	//check whether SF=1
	if((RDA5800_reg_data[0]&0x20)!=0) falseStation=1;
	//check station RSSI again, if RSSI<SEEKTH, then falseStation, continue seek
	if(RDA5800_reg_data[2] < RDA5800_initialization_reg[6]) falseStation=1;
	if(freq==960) falseStation=1;
	
	if (falseStation==1)
		return 0;   
	else 
		return 1;
}

uint8 RDA5800_GetSigLvl( int16 curf )  /*当满足rssi 的条件时，将信号记录，再选最强的9个频段*/
{  
	uint8 RDA5800_reg_data[4]={0};	
	
	if(875==curf)
		return(1);
	else
		OperationRDAFM_2w(READ,&(RDA5800_reg_data[0]), 4);	
	
	return (RDA5800_reg_data[2]);  /*返回rssi*/
}

void  RDA5800_SetVolumeLevel(uint8 level)   /*一般不调用，即不用芯片来调节音量。*/
{
}

bool  RDA5800_Intialization(void)
{
	uint8 error_ind = 0;
	uint8 RDA5800_REG[]={0x00,0x02};
	
	error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5800_REG[0], 2);
	kal_sleep_task(1);
	error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5800_initialization_reg[0], 86);
	kal_sleep_task(20);
	#if (defined(XTAL))
		kal_sleep_task(120);
	#else
		kal_sleep_task(20);	
	#endif
	
	if (error_ind )
	   return 0;
	else
	   return 1;
}

#endif
