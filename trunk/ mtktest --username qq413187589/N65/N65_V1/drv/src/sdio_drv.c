#include "drv_features.h"
#include "kal_release.h"
#include "reg_base.h"
#include "app_buff_alloc.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "sdio_def.h"
#include "drv_comm.h"  
#include "intrCtrl.h"  
#include "sdio_sw.h"
 
#if defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)

#if defined(DRV_MSDC_MT6225_SERIES)
#define DRV_MSDC_DATA_LATCH_TIMING
#endif 
__align(4) kal_uint8 sdio_cccr_reg[SDIO_CCCR_SIZE];
__align(4) kal_uint8 sdio_fbr_reg[SDIO_FBR_SIZE];
__align(4) kal_uint8 sdio_tuple[SDIO_MAX_FUCN_ID][SDIO_TUPLE_SIZE];
sdio_dcb_struct gSDIO;
kal_mutexid sdio_mutex; 
/*************************************************************************
* FUNCTION
*  SDIO_Initialize
*
* DESCRIPTION
*	SDIO Intialization function
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	
*************************************************************************/
extern kal_uint8 MSDC_GetIOCtrlParam(void);
SDC_CMD_STATUS SDIO_Initialize(void)
{	
	kal_uint16 rca;
   #if !defined(DRV_MSDC_DATA_LATCH_TIMING)
	kal_uint16 iocon;
   #else
	kal_uint32 iocon;
   #endif
	SDC_CMD_STATUS status;
	kal_uint32 flags;	
	kal_uint32 retry_count = 0;
	kal_uint32 count=0;	   
		
	TurnOnMSDC();	
	#ifdef MSDC_INT
	kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,
			(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ|EVENT_PINIRQ),
			KAL_OR_CONSUME,&flags,KAL_NO_SUSPEND);
	#else
	/*check if the card is present*/
	if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
	{  /*card not present (1)*/
		gMSDC_Handle->mIsPresent = KAL_FALSE;
	}
	else
	{  /*card present (0)*/
		gMSDC_Handle->mIsPresent = KAL_TRUE;
	}
	#endif

   /*create mutex*/
   sdio_mutex = kal_create_mutex("MutexSDIO");

	/* reset msdc*/
	MSDC_SET_BIT32(MSDC_CFG, MSDC_CFG_RST);

   /*Driving current*/
	//MSDC_WriteReg32(MSDC_IOCON,0xC3);
	//MSDC_WriteReg32(MSDC_IOCON,0xdb);

   /* set the output driving capability from customization interface*/
   #if !defined(DRV_MSDC_DATA_LATCH_TIMING)
	iocon = *(volatile kal_uint16*)MSDC_IOCON;
	iocon &= ~(0xff);
	iocon |= MSDC_GetIOCtrlParam();
	MSDC_WriteReg16(MSDC_IOCON,(kal_uint16)iocon);	
   #else /* !defined(DRV_MSDC_DATA_LATCH_TIMING) */
	iocon = *(volatile kal_uint32*)MSDC_IOCON;
	iocon &= ~(0xff0000ff);
	iocon |= MSDC_GetIOCtrlParam();
	 #ifdef MCU_208M
	    iocon |= 0x08000000;
   #elif defined(MCU_104M)
      iocon |= 0x04000000;
   #elif defined(MCU_52M)
      iocon |= 0x02000000;
   #endif
	MSDC_WriteReg32(MSDC_IOCON,iocon);	
   #if defined(MCU_52M)
   	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)1, MSDC_CFG_CRED);
   #endif
   #endif /* !defined(DRV_MSDC_DATA_LATCH_TIMING) */

	/*set pull up in CMD/DAT line configuration*/	
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)2,MSDC_CFG_PRCFG1);
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)2,MSDC_CFG_PRCFG2);

	/*set write timeout=(40+1)*65536*(1/serial clock)*/
	BitFieldWrite32((kal_uint32*)SDC_CFG,(kal_uint32)255,SDC_CFG_DTOC);	
	/*set write timeout=(40+1)*65536*(1/serial clock)*/
	BitFieldWrite32((kal_uint32*)SDC_CFG,(kal_uint32)15,SDC_CFG_WDOD);		

 	/* disable 4-bit*/
	MSDC_CLR_BIT32(SDC_CFG,SDC_CFG_MDLEN);	   		
	/* enable serila clock 104/8=13MHz*/	
	//BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY8,MSDC_CFG_SCLKF);			
	/* enable serila clock 104/255*4=100KHz*/	
	//DRV_Reg32(MSDC_CFG)|= 0x8; 
	MSDC_CLR_BIT32(SDC_CFG,SDC_CFG_SIEN);
	#ifdef MCU_208M
		BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)32,MSDC_CFG_SCLKF);	
	#else
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)32,MSDC_CFG_SCLKF);		
	#endif
	MSDC_SET_BIT32(SDC_CFG,SDC_CFG_SIEN);
	/* config the sdio controller*/
	/* enable SDIO mode*/
	DRV_Reg32(SDC_CFG)|= SDC_CFG_SDIO; 
	/* enable SDIO interrupt*/
	DRV_WriteReg32(SDIO_CFG, 1); 		
	{
		kal_uint32 i;
		for(i=0;i<1000;i++);
	}	
	/*SDIO initialization CMD*/
   status = SDIO_Cmd5(0);
   #ifdef _SDIO_DEBUG_
	dbg_print("write CMD5(0) %d\r\n", status);						
	dbg_print("card OCR %d\r\n", gSDIO.ocr);						
	#endif
	do 
	{	
	   retry_count++;
	   if(gSDIO.ocr & 0x8000)
	   {					      
	   	if((status = SDIO_Cmd5(0x8000))!=NO_ERROR)	   	
	   	{
	   	   #ifdef _SDIO_DEBUG_
	   		dbg_print("card deny OCR \r\n");													   	
	   		#endif
	   		
	   	}	
	   	else	   				
	   	{
	   	   #ifdef _SDIO_DEBUG_
	   		dbg_print("card accept OCR \r\n");							   		
	   	#endif	
	   	}	
	   	
	   	gSDIO.ocr_valid = KAL_TRUE;	
	   }
	   else 
	   {	   
	      #ifdef _SDIO_DEBUG_
	      dbg_print("card not match OCR \r\n");												  
	      dbg_print("uses card's OCR \r\n");												  
	      #endif												  
	      if((status = SDIO_Cmd5(gSDIO.ocr))!=NO_ERROR)	   	
	      {
	         #ifdef _SDIO_DEBUG_
	   		dbg_print("card deny OCR \r\n");													   			   			   	
	   		#endif	
	   	}	
	   	else	   	
	   	{
	   	   #ifdef _SDIO_DEBUG_
	   		dbg_print("card accept OCR \r\n");							   	
	   		#endif	
	   	}	
	   	
	   	gSDIO.ocr_valid = KAL_TRUE;	
	   }
	   if(retry_count>=100)
	      goto err;
	}while(gSDIO.io_ready!=KAL_TRUE);	
	MSDC_CLR_BIT32(SDC_CFG,SDC_CFG_SIEN);			
	#ifdef MCU_208M
	 BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)4,MSDC_CFG_SCLKF);		  
	#elif defined(MCU_104M)   
   BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY8,MSDC_CFG_SCLKF);		   	
   #else
   BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY4,MSDC_CFG_SCLKF);		   	
   #endif   /*MCU_208M*/
	MSDC_SET_BIT32(SDC_CFG,SDC_CFG_SIEN);   
	status = SD_ValidateRCA(&rca);
	#ifdef _SDIO_DEBUG_
	dbg_print("CMD7 select card \r\n");								
	dbg_print("CMD3 request RCA \r\n");
	#endif
	
	status = SD_SelectCard(rca);
	
	/* get parameters*/
	/*read CCCR, FBR, CIS tuple*/	
	status=SDIO_read_CCCR();
   status=SDIO_read_capacity();   
   status=SDIO_read_power_control();
	
	#if 1/*support 4-bits*/
	/*enable multiple block interrupt */
	if(!(SDIO_support_LSC()))	
	{	
#ifndef DRV_MSDC_USING_2ND
	   if(SDIO_support_S4MI())
	      status=SDIO_enable_E4MI(KAL_TRUE);   
	   status=SDIO_configure_bus(BIT_4W);	   
	   /* enable serila clock 104/8=13MHz*/	
	   //BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY8,MSDC_CFG_SCLKF);    	   
#else
		 //MSDC2 only support 1-bit Mode
		 status=SDIO_configure_bus(BIT_1W);
#endif	      
	}
	else/*low speed card*/
	{
#ifndef DRV_MSDC_USING_2ND		
	   if(SDIO_support_4BLS())
	      status=SDIO_configure_bus(BIT_4W);	      
#else
		//MSDC2 only support 1-bit Mode
#endif	      
	}    
	#else
/* under construction !*/
	#endif  
	status=SDIO_read_CIS(SDIO_FUCN_0);
   /*enable I/O function*/
	for(count=SDIO_FUCN_1;count<SDIO_MAX_FUCN_ID;count++)
	{	   
	   kal_uint32 retry=0;
	   kal_bool ready;
	   for(retry=0;retry<100;retry++) 
	   {
	      status=SDIO_enable_IO(count, KAL_TRUE);
	      SDIO_check_IO_ready(count, &ready);
	      if(ready==KAL_TRUE)
	         break;
	   }   	   
	   status=SDIO_read_FBR(count);	 
	   for(retry=0;retry<100;retry++)   	   
	   {
	      status=SDIO_read_CIS(count);	   
	      if(status==NO_ERROR)
	         break;
	   }   
	   
	}      
	if(SDIO_support_MPS())
	   status=SDIO_enable_MPS(KAL_TRUE);
	   
	status=SDIO_read_CCCR();   
	
	/* for Sandisk SDIO WIFI card*/   
	
	

err:
	if(status != NO_ERROR)
	{
		//dbg_print("10\r\n");
		kal_mem_set(gSD,0,sizeof(gSD));
		gMSDC_Handle->mIsInitialized = KAL_FALSE;
		ASSERT(0);
	}
	else
		gMSDC_Handle->mIsInitialized = KAL_TRUE;
   
	return status;
}

/*SDIO commnad set*/
/*************************************************************************
* FUNCTION
*  SD_StopTrans
*
* DESCRIPTION
*	Stop Muli-Block operation
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Use polling to check write command completely
*************************************************************************/
SDC_CMD_STATUS SD_StopTrans_poll(void)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd_poll(SDC_CMD_CMD12,SDC_NO_ARG))!=NO_ERROR)
		return status;
	/*Read R1b*/
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;


#ifdef SD_STOP_SLOW
		while(*(volatile kal_uint16*)(SDC_STA) & SDC_STA_R1BSY);
		do{
		SD_GetStatus(gSD->mRCA,(kal_uint32*)&status);
			}while((status & R1_CUR_STATE) >> 9 !=  TRAN_STA);
#endif

	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_WaitCardNotBusy
*
* DESCRIPTION
*	Wait until card is not busy (R1b)
*
* PARAMETERS
*
* RETURNS
*	void
*
* GLOBALS AFFECTED
*
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
/*R1b*/
void SDIO_WaitCardNotBusy(void)
{
	while( *(volatile kal_uint16*)(SDC_STA) & SDC_STA_R1BSY);
}
/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo_poll
*
* DESCRIPTION
*	write command completely
*
* PARAMETERS
*
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitCmdRdyOrTo_poll(void)
{
	kal_uint16 sdc_cmdsta = 0;
	kal_uint32 counter = 0;
	
	while(DRV_Reg(SDC_STA)&0x2){};
   #if 1
	do{
		sdc_cmdsta = *(volatile kal_uint16*)SDC_CMDSTA;
		if(sdc_cmdsta & SDC_CMDSTA_CMDTO)
			return ERR_CMD_TIMEOUT;
		else if(sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)
			return ERR_CMD_RSPCRCERR;
		else if(sdc_cmdsta & SDC_CMDSTA_CMDRDY)
			break;
	}while(counter++ < 10000);
   #endif
	if (counter >= 10000)
	{
		return ERR_NORESP;
	}

	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo_poll
*
* DESCRIPTION
*	write command completely
*
* PARAMETERS
*
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
SDC_CMD_STATUS SD_Send_Cmd_poll(kal_uint32 cmd, kal_uint32 arg)
{
	SDC_CMD_STATUS status;

	/*check the controller is ready (stop transaction will fail)*/
	//if( != SDC_CMD_CMD12)
	if(!(SDC_CMD_STOP&cmd))
		while(SD_IS_SDC_BUSY && gMSDC_Handle->mIsPresent);
	else
		while(SD_IS_CMD_BUSY && gMSDC_Handle->mIsPresent);

	/* fill out the argument*/
	MSDC_WriteReg32(SDC_ARG,arg);
	/* launch the command*/
	MSDC_WriteReg32(SDC_CMD,cmd);
	if((status = SD_WaitCmdRdyOrTo_poll())!=NO_ERROR)
		return status;

	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_Cmd53
*
* DESCRIPTION
*	IO_RW_DIRECT command
*
* PARAMETERS
*  command 53 structrue
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_uint8 debug_flag = 0;
SDC_CMD_STATUS SDIO_Cmd53(cmd53_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg;
	kal_uint32 cmd;
	kal_uint32 *ptr = (kal_uint32 *) p->buffer;	

	ASSERT(p->adrs < 0x20000 && p->count < 0x200);   

#ifndef DRV_MSDC_USING_2ND
   IRQMask(IRQ_MSDC_CODE);      
#else
  IRQMask(IRQ_MSDC2_CODE);
#endif
	
	arg = (p->rw << 31)|(p->func << 28)|(p->block << 27)|(p->op << 26)|(p->adrs << 9)|(p->count);
	cmd = SDC_CMD_CMD53 | (p->rw << 13);
	if(p->block)
	{
		cmd |= (2 << 11);	// multi-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,gSDIO.block_size[1],SDC_CFG_BLKLEN);
	}
	else
	{
		cmd |= (1 << 11);	// single-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,p->count,SDC_CFG_BLKLEN);
	}

	// send cmd53	   
   //if(p->rw == SDIO_WRITE)
   if(0)/*R1b*/
   {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   else/*R1*/
   {
       cmd &= ~0x380;
      cmd |= 0x80;      
   }      
   #ifdef MSDC_DMA      
	{
      kal_uint32 total_size=0;

	   EnableMSDC_DMA();   
      if(p->block)		
			total_size = (p->count*gSDIO.block_size[p->func]);				
		else
		   total_size =p->count;
		total_size=total_size>>2;	
			
   	if(p->rw == SDIO_READ)
      	MSDC_DMATransferFirst((kal_uint32)ptr,total_size,KAL_FALSE);
      else
   		MSDC_DMATransferFirst((kal_uint32)ptr,total_size,KAL_TRUE);
   }
   #endif /* MSDC_DMA */

  	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)
	{ 
	   goto ERROR_EXIT;		
	}		
	MSDC_ReadReg32(SDC_RESP0,&status);	
	status = (status & 0xff00)>>8;
	gSDIO.resp = status;   			
	/* start data transfer*/
	if(p->rw == SDIO_READ)
	{
      #ifdef MSDC_DMA      
		status = MSDC_DMATransferFinal();
		/*check DMA*/
		if(status != NO_ERROR)	   
		   goto ERROR_EXIT;
		/*check Data ready*/   
		if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
         goto ERROR_EXIT;	
	   
      DisableMSDC_DMA();
	   MSDC_CLR_FIFO();	   
	         
      #else/*!MSDC_DMA*/
      kal_uint32 i;
		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = *(volatile kal_uint32*)MSDC_DAT;
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}
		}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = *(volatile kal_uint32*)MSDC_DAT;
					i++;
					if((i%((p->count+3)>> 2)==0)&&(i!=0))
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}
		}
		}
		#endif/*MSDC_DMA*/
	}
	else
	{	// SDIO_WRITE
	   #ifdef MSDC_DMA      
		status = MSDC_DMATransferFinal();
		/*check DMA*/
		if(status != NO_ERROR)	   
		   goto ERROR_EXIT;
		/*check Data ready*/   
		if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
         goto ERROR_EXIT;	
	   
      DisableMSDC_DMA();
	   MSDC_CLR_FIFO();	   	         
      #else/* MSDC_DMA*/ 
      kal_uint32 i;     
		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{			      			      
				if(!MSDC_IS_FIFO_FULL)
				{
					*(volatile kal_uint32*)MSDC_DAT = *(ptr+i);
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
				}				
			}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			   
				if(!MSDC_IS_FIFO_FULL)
				{
					*(volatile kal_uint32*)MSDC_DAT = *(ptr+i);
					i++;
					if(i%((p->count+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;						     
				}
			}
		   }
		}
		#endif/*MSDC_DMA*/    
	}   
	//SD_StopTrans_poll();
	if(p->block)
	  SD_StopTrans_poll();
        SDIO_stop();

#ifndef DRV_MSDC_USING_2ND
	IRQUnmask(IRQ_MSDC_CODE);
#else
	IRQUnmask(IRQ_MSDC2_CODE);
#endif

	return NO_ERROR;
	ERROR_EXIT:
   {  
      kal_uint32 tmp;
      #ifdef MSDC_DMA
      DisableMSDC_DMA();
      #endif
      if(p->block)
	      SD_StopTrans_poll();
        SDIO_stop();
		MSDC_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_ReadReg32(SDC_DATSTA,&tmp);
		MSDC_CLR_FIFO();
#ifndef DRV_MSDC_USING_2ND
      IRQUnmask(IRQ_MSDC_CODE);
#else
    IRQUnmask(IRQ_MSDC2_CODE);
#endif
   	return status;
   }
}

/*SDIO_Cmd53_poll*/
SDC_CMD_STATUS SDIO_Cmd53_isr(cmd53_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg;
	kal_uint32 cmd,i;
	kal_uint32 *ptr = (kal_uint32 *) p->buffer;	

	ASSERT(p->adrs < 0x20000 && p->count < 0x200);      
	arg = (p->rw << 31)|(p->func << 28)|(p->block << 27)|(p->op << 26)|(p->adrs << 9)|(p->count);
	cmd = SDC_CMD_CMD53 | (p->rw << 13);
	if(p->block)
	{
		cmd |= (2 << 11);	// multi-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,gSDIO.block_size[1],SDC_CFG_BLKLEN);
	}
	else
	{
		cmd |= (1 << 11);	// single-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,p->count,SDC_CFG_BLKLEN);
	}

	// send cmd53	   
   //if(p->rw == SDIO_WRITE)
   if(0)/*R1b*/
   {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   else/*R1*/
   {
       cmd &= ~0x380;
      cmd |= 0x80;      
   }      
	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)
	{ 
	   goto ERROR_EXIT;		
	}		
	MSDC_ReadReg32(SDC_RESP0,&status);	
	status = (status & 0xff00)>>8;
	gSDIO.resp = status;   			
	/* start data transfer*/
	if(p->rw == SDIO_READ)
	{

		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{
			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = *(volatile kal_uint32*)MSDC_DAT;
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}
				
			}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = *(volatile kal_uint32*)MSDC_DAT;
					i++;
					if(i%((p->count+3)>> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}

		}

		}
	}
	else
	{	// SDIO_WRITE
		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{			      			      
				if(!MSDC_IS_FIFO_FULL)
				{
					*(volatile kal_uint32*)MSDC_DAT = *(ptr+i);
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
				}
				

			}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			   
				if(!MSDC_IS_FIFO_FULL)
				{
					*(volatile kal_uint32*)MSDC_DAT = *(ptr+i);
					i++;
					if(i%((p->count+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;						     
				}
			}

		}

		}
	}   	
	if(p->block)
	  SD_StopTrans_poll();
   SDIO_stop();	
	return NO_ERROR;
	ERROR_EXIT:
   {  
      kal_uint32 tmp;      
      #ifdef MSDC_DMA  
      DisableMSDC_DMA();
      #endif
      if(p->block)
	      SD_StopTrans_poll();
      SDIO_stop();
		MSDC_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_ReadReg32(SDC_DATSTA,&tmp);
		MSDC_CLR_FIFO();    
   	return status;
   }
}
/*************************************************************************
* FUNCTION
*  SDIO_Cmd52
*
* DESCRIPTION
*	IO_RW_DIRECT command
*
* PARAMETERS
*  command 52 structrue
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
/* refer to the IO_RW_DIRECT command (CMD52) in SDIO 1.1 chapter 5.1*/
SDC_CMD_STATUS SDIO_Cmd52(cmd52_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;
	kal_uint32 cmd;	
   
#ifndef DRV_MSDC_USING_2ND
   IRQMask(IRQ_MSDC_CODE);
#else
	IRQMask(IRQ_MSDC2_CODE);
#endif

	if(p->rw == SDIO_WRITE)
	{
		arg |= (IO_ARG_RW_FLAG|p->data);
	}
	arg |= ((p->raw << 27)|(p->func << 28)|(p->adrs <<9));

	cmd = SDC_CMD_CMD52 ;
	if(p->stop)
		cmd |= SDC_CMD_STOP;
      
   if(p->stop)
    //if(0)
    {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   #if 1
   else
   {
      cmd &= ~0x380;
      cmd |= 0x80;      
   }    
   #endif
	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)
		goto ERROR_EXIT;         		
	while(*(volatile kal_uint16*)(SDC_STA) & SDC_STA_R1BSY);	
	MSDC_ReadReg32(SDC_RESP0,&status);
	if(p->rw == SDIO_READ)
	{
		p->data = status & 0xff;
	}
	status = (status & 0xff00)>>8;
	gSDIO.state = (status & 0x30)>>4;	
	gSDIO.resp = status;	

#ifndef DRV_MSDC_USING_2ND
	IRQUnmask(IRQ_MSDC_CODE);   
#else
	IRQUnmask(IRQ_MSDC2_CODE);
#endif

   return NO_ERROR;   
   ERROR_EXIT:
   {
      kal_uint32 tmp;
		MSDC_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_CLR_FIFO();
#ifndef DRV_MSDC_USING_2ND
      IRQUnmask(IRQ_MSDC_CODE);	   
#else
		IRQUnmask(IRQ_MSDC2_CODE);
#endif
   	return status;
   }	
	
	
}
SDC_CMD_STATUS SDIO_Cmd52_isr(cmd52_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;
	kal_uint32 cmd;

	if(p->rw == SDIO_WRITE)
	{
		arg |= (IO_ARG_RW_FLAG|p->data);
	}
	arg |= ((p->raw << 27)|(p->func << 28)|(p->adrs <<9));

	cmd = SDC_CMD_CMD52 ;
	if(p->stop)
		cmd |= SDC_CMD_STOP;
	   if(p->stop)
    //if(0)
    {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   #if 1
   else
   {
      cmd &= ~0x380;
      cmd |= 0x80;      
   }    
   #endif	
	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)		
		goto ERROR_EXIT;	
   while(*(volatile kal_uint16*)(SDC_STA) & SDC_STA_R1BSY);
	MSDC_ReadReg32(SDC_RESP0,&status);
	if(p->rw == SDIO_READ)
	{
		p->data = status & 0xff;
	}
	status = (status & 0xff00)>>8;
	gSDIO.state = (status & 0x30)>>4;	
	gSDIO.resp = status;   
	return NO_ERROR;   
	/*error handle*/
   ERROR_EXIT:
   {  
      kal_uint32 tmp;  
		MSDC_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_CLR_FIFO();      
   	return status;
   }		

}   

/* for SDIO*/
/*************************************************************************
* FUNCTION
*  SDIO_Cmd5
*
* DESCRIPTION
*	SDIO initialization command
*
* PARAMETERS
*
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	it is similar to the operation of ACMD41 for SD memory cards.
*
*************************************************************************/
SDC_CMD_STATUS SDIO_Cmd5(kal_uint32 ocr)
{
	SDC_CMD_STATUS status;     
   
	if((status = SD_Send_Cmd_poll(SDC_CMD_CMD5,ocr))!=NO_ERROR)	
		return status;

	/*read R4*/
	MSDC_ReadReg32(SDC_RESP0,&status);
	gSDIO.ocr = status &0xFFFFFF;
	status >>= 24;
	gSDIO.num_func = (kal_uint8)(status & 0x70) >> 4;	
	gSDIO.mem_present = ((status & 0x08) != 0) ;	
	gSDIO.io_ready = ((status & SDIO_R4_CARD_READY)!=0);
	#ifdef _SDIO_DEBUG_
	dbg_print("card function number %d\r\n", gSDIO.num_func);							
	dbg_print("memory card present %d\r\n", gSDIO.mem_present);						
	dbg_print("card ready %d\r\n", gSDIO.io_ready);	
	#endif
	return NO_ERROR;
}

void SDIO_dispatch_IO(SDIO_function_id_enum function)   
{
   /*single function*/   
   kal_take_mutex(sdio_mutex);    
   /*multiple function*/
   /*not support now*/
}

void SDIO_resume_IO(SDIO_function_id_enum function)   
{
   /*single function*/   
   kal_give_mutex(sdio_mutex);    
   /*multiple function*/
   /*not support now*/
   
}
/*************************************************************************
* FUNCTION
*  SDIO_read_CIS
*
* DESCRIPTION
*	This function is to read function's CIS
*
* PARAMETERS
*  function: function id
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	This function is only user for SDIO bus driver
*
*************************************************************************/
SDC_CMD_STATUS SDIO_read_CIS(SDIO_function_id_enum function)
{
   kal_uint32 i=0, j=0;
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;      
   ASSERT(function<8);          
   /* read all configuration register of CCCR*/
   while(1)
   {
	   cmd52.rw = SDIO_READ;
	   cmd52.func = SDIO_FUCN_0;
	   cmd52.raw = KAL_FALSE;
	   cmd52.stop = KAL_FALSE;
	   if(function==0)
	      cmd52.adrs =(kal_uint32)((sdio_cccr_reg[11]<<16)|(sdio_cccr_reg[10]<<8)|
	                                      (sdio_cccr_reg[9])+i);
	   else 
	      cmd52.adrs =(kal_uint32)((sdio_fbr_reg[11]<<16)|(sdio_fbr_reg[10]<<8)|
	                                      (sdio_fbr_reg[9])+i);
	   cmd52.data = 0;
	   if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	      return status;
	   sdio_tuple[function][i]=cmd52.data;
	   i++;
	   if(cmd52.data==CISTPL_NULL||cmd52.data==CISTPL_END)
	      return NO_ERROR;
	   else
	   {
	      kal_uint32 tuple_size=0;
	      cmd52.rw = SDIO_READ;	      
	      cmd52.raw = KAL_FALSE;
	      cmd52.stop = KAL_FALSE;
	      cmd52.adrs++;
	      if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	         return status;
	      sdio_tuple[function][i]=cmd52.data;	      
	      tuple_size=cmd52.data;
	      i++;
	      for(j=0;j<tuple_size;j++)
	      {
	         cmd52.adrs++;
	         if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	            return status;
	         sdio_tuple[function][i]=cmd52.data;	      
	         i++;
	      }      
	   }         
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_read_CCCR_ver
*
* DESCRIPTION
*	This function is to read card's CCCR version 
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/   
/*read SDIO CCCR version*/
SDC_CMD_STATUS SDIO_read_CCCR_ver(kal_uint8 *version)
{
   SDC_CMD_STATUS status=NO_ERROR;
      
   #if 1
   *version=sdio_cccr_reg[0]&SDIO_CCCR_VERISON_MASK;	   
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
	#endif
	return status;
	
}

SDC_CMD_STATUS SDIO_stop(void)
{
   SDC_CMD_STATUS status=NO_ERROR;
         
   cmd52_config_struct cmd52;   
   cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_TRUE;
	cmd52.adrs = 6;
	cmd52.data = 1;
	status = SDIO_Cmd52(&cmd52);	   
	/*wait card is not busy*/	
   SDIO_WaitCardNotBusy();		
	return status;	
}
SDC_CMD_STATUS SDIO_WaitDatRdyOrTo(void)
{
	// maybe have to add a timer
	register kal_uint16 sdc_datsta = 0;

	int counter = 0;
	//while(DRV_Reg(SDC_STA)&0x4){};
	do{
		sdc_datsta = *(volatile kal_uint16*)SDC_DATSTA;
		if(sdc_datsta & SDC_DATSTA_DATTO)
			return ERR_DAT_TIMEOUT;
		else if(sdc_datsta & SDC_DATSTA_DATCRCERR)
			return ERR_DAT_CRCERR;
		else if(sdc_datsta & SDC_DATSTA_BLKDONE)
			break;
	}while(1);//(counter++  < 1000);

	if (counter >= 1000)
		return ERR_NORESP;
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_read_SDIO_ver
*
* DESCRIPTION
*	This function is to read card's SDIO version 
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/   
/*read SDIO spec version*/
SDC_CMD_STATUS SDIO_read_SDIO_ver(kal_uint8 *version)
{
   SDC_CMD_STATUS status=NO_ERROR;
   
   #if 1
   *version=sdio_cccr_reg[0]&SDIO_VERISON_MASK>>SDIO_VERISON_SHIFT;	
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
	#endif
	return status;
	
}   
/*************************************************************************
* FUNCTION
*  SDIO_read_SD_ver
*
* DESCRIPTION
*	This function is to read card's SD version 
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
/*read SD spec version*/
SDC_CMD_STATUS SDIO_read_SD_ver(kal_uint8 *version)
{
   SDC_CMD_STATUS status=NO_ERROR;
   
   #if 1
   *version=sdio_cccr_reg[1]&SDIO_SD_VERISON_MASK;	
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
	#endif
	return status;
}   
/*************************************************************************
* FUNCTION
*  SDIO_read_CCCR
*
* DESCRIPTION
*	This function is to read card CCCR
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_CCCR(void)
{
   #if 1
   kal_uint32 i;
    SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;      
   cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	for(i=0;i<SDIO_CCCR_SIZE;i++)
	{
	   cmd52.adrs =i;
	   status = SDIO_Cmd52(&cmd52);	
	   sdio_cccr_reg[i]=cmd52.data;	   
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
	#endif
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_read_FBR
*
* DESCRIPTION
*	This function is to read card FBR
*
* PARAMETERS
*  function: function id
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_FBR(SDIO_function_id_enum function)
{
   #if 1  /*to cover 5911 issue*/ 
   SDC_CMD_STATUS status;   
   cmd52_config_struct cmd52;   
   kal_uint32 i=0;
      
   cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;	
	cmd52.data = 0;
	for(i=0;i<SDIO_FBR_SIZE;i++)
	{
	   cmd52.adrs = 0x100*function+i;
	   status=SDIO_Cmd52(&cmd52);
	   sdio_fbr_reg[i] = cmd52.data;	
	}   
	
	return status;	
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
	#endif
}
/*************************************************************************
* FUNCTION
*  SDIO_read_power_control
*
* DESCRIPTION
*	This function is to read card's power control
*
* PARAMETERS
*  None
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_power_control(void)
{
   SDC_CMD_STATUS status;   
   cmd52_config_struct cmd52;   
      
   cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0x12;
	cmd52.data = 0;
	status=SDIO_Cmd52(&cmd52);
	gSDIO.power_control = cmd52.data;	
	return status;	
}
/*************************************************************************
* FUNCTION
*  SDIO_support_MPS
*
* DESCRIPTION
*	This function is to query card's power control
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
kal_bool SDIO_support_MPS(void)
{
     return ((gSDIO.power_control&0x1));   
}   
/*************************************************************************
* FUNCTION
*  SDIO_enable_MPS
*
* DESCRIPTION
*	This function is to enable card's power control
*
* PARAMETERS
*  enable: enable or disable
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_MPS(kal_bool enable)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
      
   cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0x12;
	if(enable)
	   cmd52.data |= 0x2;
	else
	   cmd52.data &= ~0x2;
	   
	status=SDIO_Cmd52(&cmd52);	   
	if(enable)   	
	   gSDIO.power_control |= 0x2;
	else
	   gSDIO.power_control &= ~0x2;   
		
	return status;	
}   
/*************************************************************************
* FUNCTION
*  SDIO_read_capacity
*
* DESCRIPTION
*	This function is to read card's capacity
*
* PARAMETERS
*  enable: None
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_capacity(void)
{
   SDC_CMD_STATUS status=NO_ERROR;
   #if 1
   gSDIO.capability = sdio_cccr_reg[8];
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
	#endif
	return status;	
}      
/*************************************************************************
* FUNCTION
*  SDIO_support_SDC
*
* DESCRIPTION
*	This function is to query if card can support SDC
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
/*query card capacity*/
kal_bool SDIO_support_SDC(void)
{   
   return ((gSDIO.capability&0x1));   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_SMB
*
* DESCRIPTION
*	This function is to query if card can support Multiple Block
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_SMB(void)
{   
   return ((gSDIO.capability&0x2)>>1);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_SRW
*
* DESCRIPTION
*	This function is to query if card can support Suspend/Resume
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_SRW(void)
{   
   return ((gSDIO.capability&0x4)>>2);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_SBS
*
* DESCRIPTION
*	This function is to query if card can support Read/Wait
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_SBS(void)
{   
   return ((gSDIO.capability&0x8)>>3);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_S4MI
*
* DESCRIPTION
*	This function is to query if card can support interrupt during multiple block
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_S4MI(void)
{   
   return ((gSDIO.capability&0x10)>>4);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_enable_E4MI
*
* DESCRIPTION
*	This function is to enable interrupt during multiple block
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_E4MI(kal_bool enable)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   kal_uint8 temp_data; 
   
   if(!SDIO_support_S4MI())
      return SDIO_4MI_NOT_SUPPORT;
   
   cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 8;
	if(enable)
	{
	   cmd52.data = 0x20;
	   temp_data=0x20;
	}   
	else
	{
	   cmd52.data = 0;
	   temp_data=0;
	}   
	if((status = SDIO_Cmd52(&cmd52))==NO_ERROR)
	{
	   /*double check*/
	   cmd52.rw = SDIO_READ;   
	   status = SDIO_Cmd52(&cmd52);	      
	   if((cmd52.data&0x20)!=temp_data)	   
	      ASSERT(0);	   
	          
	   if(enable)
	      gSDIO.capability|=0x20;	   
	   else
	     gSDIO.capability&=~0x20;	       	   	   	   
	}   	
	
	return status;		      
}   
/*************************************************************************
* FUNCTION
*  SDIO_enable_E4MI
*
* DESCRIPTION
*	This function is to query if card is a low speed card
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_LSC(void)
{   
   return ((gSDIO.capability&0x40)>>6);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_4BLS
*
* DESCRIPTION
*	This function is to query if card can support 4-bits in low speed card
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_4BLS(void)
{   
   return ((gSDIO.capability&0x80)>>7);   
}
/*************************************************************************
* FUNCTION
*  SDIO_configure_bus
*
* DESCRIPTION
*	This function is to configure bus width
*
* PARAMETERS
*  bus: bus width
*
* RETURNS
*  bus
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_configure_bus(SD_BITWIDTH bus)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 7;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{	   
	   return status;	   
	}   
	cmd52.data &= ~0x3;
	cmd52.data |= (bus|0x80);/*also disable card detection*/
	cmd52.rw = SDIO_WRITE;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{	 
	   return status;
	}   
	gSDIO.bit_width=bus;
	if(bus==BIT_4W)	
	   MSDC_SET_BIT32(SDC_CFG,SDC_CFG_MDLEN);	        
	
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_enable_IO
*
* DESCRIPTION
*	This function is to enable function
*
* PARAMETERS
*  function: function id
*  enable: enable or disable
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_IO(SDIO_function_id_enum function, kal_bool enable)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 2;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{
	   SDIO_resume_IO(SDIO_FUCN_0); 
	   return status;	   
	}   
	if(enable)   	
	   cmd52.data |= (function<<1);	
	else   	
	   cmd52.data &= ~(function<<1);	 
		
	cmd52.rw = SDIO_WRITE;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{
	   SDIO_resume_IO(SDIO_FUCN_0); 
	   return status;
	}   
   SDIO_resume_IO(SDIO_FUCN_0); 
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_check_IO_ready
*
* DESCRIPTION
*	This function is to check function status
*
* PARAMETERS
*  function: function id
*  *ready: ready or not
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_check_IO_ready(SDIO_function_id_enum function, kal_bool *ready)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 3;
	status = SDIO_Cmd52(&cmd52);	   
	*ready=(cmd52.data&(1<<function))>>function;		   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_enable_IO_Int
*
* DESCRIPTION
*	This function is to configure function interrupt enable
*
* PARAMETERS
*  function: function id
*  enable: enable or diable
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_IO_Int(SDIO_function_id_enum function, kal_bool enable)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 4;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{
	   SDIO_resume_IO(SDIO_FUCN_0); 
	   return status;	   
	}	   
	if(enable)   	
	   cmd52.data |= (1<<function);	
	else   	
	   cmd52.data &= ~(1<<function);	 
		
	cmd52.rw = SDIO_WRITE;
		
	status = SDIO_Cmd52(&cmd52);	      	   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_int_registration
*
* DESCRIPTION
*	This function is to register interrupt handler
*
* PARAMETERS
*  function: function id
*  func: interrupt handler
* RETURNS
*  None
*
* GLOBALS AFFECTED
*	
*************************************************************************/
void SDIO_int_registration(SDIO_function_id_enum function, void (func)(void))
{   
   gSDIO.callback[function]=func;
}   
/*************************************************************************
* FUNCTION
*  SDIO_HISR_Entry
*
* DESCRIPTION
*	This function is to handle SDIO interrupt
*
* PARAMETERS
*  None 
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS int_status;
void SDIO_HISR_Entry(void)
{
   
   cmd52_config_struct cmd52;
   kal_uint32 count;   
   if(gSDIO.state!=CMD&&gSDIO.state!=TRN)		      
   {
      #ifdef MSDC_INT
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDMCIRQ,KAL_OR);		      		
		#endif
	}	
   else
   {   
      #if 1
	   cmd52.rw = SDIO_READ;
	   cmd52.func = 0;
	   cmd52.raw = KAL_FALSE;
	   cmd52.stop = KAL_FALSE;
	   cmd52.adrs = 5;
	   
	   if((int_status = SDIO_Cmd52_isr(&cmd52))==NO_ERROR)	
	   { 
         for(count=SDIO_FUCN_1;count<SDIO_MAX_FUCN_ID;count++)	
         {
            if(cmd52.data&(1<<count))
               gSDIO.callback[count]();
         }
      }
      else
      {
        /*dbg_print("int read failed\r\n");*/
      }    
      #endif        
   }            
}   

/*************************************************************************
* FUNCTION
*  SDIO_check_IO_Int
*
* DESCRIPTION
*	This function is to check interrupt status
*
* PARAMETERS
*  function: function id
*  *pending: interrupt status 
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/  
SDC_CMD_STATUS SDIO_check_IO_Int(SDIO_function_id_enum function, kal_bool *pending)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 5;
	status = SDIO_Cmd52(&cmd52);	
	*pending=(cmd52.data&(1<<function))>>function;		   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_configure_BLK_size
*
* DESCRIPTION
*	This function is to configure block size
*
* PARAMETERS
*  function: function id
*  size: block size
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_configure_BLK_size(SDIO_function_id_enum function, kal_uint32 size)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0x10+0x100*function;
	cmd52.data = size&0xff;
	status = SDIO_Cmd52(&cmd52);	   
   if(size>=256)
   {
	   cmd52.adrs = 0x11+0x100*function;
	   cmd52.data = (size&0xff00)>>8;    
	   status = SDIO_Cmd52(&cmd52);	   
	}   
   if(status==NO_ERROR)					   
   {
	   gSDIO.block_size[function]=size;   	   		
	   /*set block length as size*/
	   BitFieldWrite32((kal_uint32*)SDC_CFG,(kal_uint32)size,SDC_CFG_BLKLEN);
	}   
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_query_BLK_size
*
* DESCRIPTION
*	This function is to query function's maximum block size
*
* PARAMETERS
*  function: function id
*
* RETURNS
*  size: block size
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_uint32 SDIO_query_BLK_size(SDIO_function_id_enum function)
{
   kal_uint32 max_block_size;
   kal_uint32 i;
   for(i=0;i<SDIO_TUPLE_SIZE;i++) 
   {      
      if(sdio_tuple[function][i]==0x22)
      {
         if(function==SDIO_FUCN_0)   
            max_block_size=(sdio_tuple[function][i+3])|(sdio_tuple[function][i+4]<<8);
         else
            max_block_size=(sdio_tuple[function][i+14])|(sdio_tuple[function][i+15]<<8);   
         return   max_block_size;         
      }  
   }
   return 0;         
}  
/*************************************************************************
* FUNCTION
*  SDIO_query_IO_id
*
* DESCRIPTION
*	This function is to query application function id
*
* PARAMETERS
*  ap: application type
*
* RETURNS
*  function: function id
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
SDIO_function_id_enum SDIO_query_IO_id(SDIO_interface_code_enum ap)
{
   switch(ap)
   {
      case SDIO_INTERFACE_NULL:        
      break;      
      case SDIO_INTERFACE_UART:
      break;
      case SDIO_INTERFACE_A_BT:
      break;
      case SDIO_INTERFACE_B_BT:
      break;
      case SDIO_INTERFACE_GPS:
      break;
      case SDIO_INTERFACE_CAMERA:
      break;
      case SDIO_INTERFACE_PHS:
      break;
      case SDIO_INTERFACE_WLAN:
         return 1;
      break;
      default:
      break;
   }   
   return 0;
}   
/*************************************************************************
* FUNCTION
*  SDIO_SW_reset
*
* DESCRIPTION
*	This function is to reset all I/O function
*
* PARAMETERS
*  None
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
SDC_CMD_STATUS SDIO_SW_reset(void)
{
   cmd52_config_struct cmd52;
   SDC_CMD_STATUS status;
      
   /*use CMD52 to reset card*/	   
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 6;
	cmd52.data = 0xff;
	status=SDIO_Cmd52(&cmd52);	   	
	return status; 
}   
/*************************************************************************
* FUNCTION
*  SDIO_abort_IO
*
* DESCRIPTION
*	This function is to abort function
*
* PARAMETERS
*  function:function id
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
SDC_CMD_STATUS SDIO_abort_IO(SDIO_function_id_enum function)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 6;
	cmd52.data = function&0x7;						
	status = SDIO_Cmd52(&cmd52);  			   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*Function for WiFi */
/*************************************************************************
* FUNCTION
*  SDIO_Register_Write
*
* DESCRIPTION
*	This function is to write register
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
/*Write Register*/
kal_bool SDIO_Register_Write(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 data,
                             cmd53_op_enum op)
{

	kal_uint32 tmp = data;
   cmd53_config_struct cmd53;
   
   SDIO_dispatch_IO(function);
	cmd53.rw = SDIO_WRITE;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32)&tmp;
	cmd53.count = 4;
	cmd53.op = op; 
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   	      
	}   	   
}                                                         
kal_bool SDIO_Register_Write_isr(SDIO_function_id_enum function, 
                                 kal_uint32 addr, 
                                 kal_uint32 data,
                                 cmd53_op_enum op)
{

	kal_uint32 tmp = data;
        cmd53_config_struct cmd53;
      
	cmd53.rw = SDIO_WRITE;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32)&tmp;
	cmd53.count = 4;
	cmd53.op = op; 
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53_isr(&cmd53)!=NO_ERROR))
	{	   
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   return KAL_TRUE;   	      
	}   	   
}                                                         
/*Write Data */   
/*************************************************************************
* FUNCTION
*  SDIO_Data_Write
*
* DESCRIPTION
*	This function is to write memory
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*  count: transfer count
*  block: block/byte mode 
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/                           
kal_bool SDIO_Data_Write(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint8  *data,
                             cmd53_op_enum op,
                             kal_uint32 count,
                             kal_bool block)
{
   cmd53_config_struct cmd53;
   //kal_uint32 size, i;
   //kal_uint32 sdio_buffer[256];
   
   SDIO_dispatch_IO(function);
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif 
 	cmd53.rw = SDIO_WRITE;
	cmd53.func = function;
	cmd53.block = block;
	cmd53.buffer = (kal_uint32)data;//(kal_uint32)&sdio_buffer[0];
	cmd53.count = count;
	cmd53.op = op; 
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_Register_Read
*
* DESCRIPTION
*	This function is to Read register
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/                                                        
/*Read Register*/
kal_bool SDIO_Register_Read(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 *data,
                             cmd53_op_enum op)
{
   cmd53_config_struct cmd53;
   
   SDIO_dispatch_IO(function);
	cmd53.rw = SDIO_READ;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32)data;
	cmd53.count = 4;
	cmd53.op = op;;
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))	
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   	      
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_Register_Read_poll
*
* DESCRIPTION
*	This function is to Read register by SDIO bus driver
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	only for SDIO bus driver
*************************************************************************/
kal_bool SDIO_Register_Read_poll(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 *data,
                             cmd53_op_enum op)
{
   cmd53_config_struct cmd53;
   
	cmd53.rw = SDIO_READ;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32)data;
	cmd53.count = 4;
	cmd53.op = op;;
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53_isr(&cmd53)!=NO_ERROR))	
	{
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   return KAL_TRUE;   	      
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_Data_Read
*
* DESCRIPTION
*	This function is to read memory
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*  count: transfer count
*  block: block/byte mode 
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool SDIO_Data_Read(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint8  *data,
                             cmd53_op_enum op,
                             kal_uint32 count,
                             kal_bool block)
{
   cmd53_config_struct cmd53;
   SDIO_dispatch_IO(function);
   cmd53.rw = SDIO_READ;
	cmd53.func = function;
	cmd53.block = block;
	cmd53.buffer = (kal_uint32)data;
	cmd53.count = count;
	cmd53.op = op;
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   	  	   
	}      
}                                
   
/*not support in MT6228 and MT6229*/
#ifdef __SDIO_SRW_SRW__
/*************************************************************************
* FUNCTION
*  SDIO_suspend_IO
*
* DESCRIPTION
*	This function is to suspend function
*
* PARAMETERS
*  bus_status: bus status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
SDC_CMD_STATUS SDIO_suspend_IO(SDIO_bus_status_enum *bus_status)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_TRUE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xc;
	cmd52.data = 1;						
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   	
	*bus_status=(cmd52.data&0x2)>>1;
			   	   		
	return NO_ERROR;      
}   

/*************************************************************************
* FUNCTION
*  SDIO_select_IO
*
* DESCRIPTION
*	This function is to resume function
*
* PARAMETERS
*  bus_status: bus status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
SDC_CMD_STATUS SDIO_select_IO(SDIO_function_id_enum function, kal_bool *resume_data)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_TRUE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xd;
	cmd52.data = function&0xf;						
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   	
	*resume_data=(cmd52.data&0x80)>>7;
			   	   		
	return NO_ERROR;         
}
/*************************************************************************
* FUNCTION
*  SDIO_check_IO_exec
*
* DESCRIPTION
*	This function is to check function execution status
*
* PARAMETERS
*  execute_status: execute status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/   
SDC_CMD_STATUS SDIO_check_IO_exec(SDIO_function_id_enum function, kal_bool *execution)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xe;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   			
	if(function!=SDIO_FUCN_MEM)		 
	   *execution=(cmd52.data&(1<<function))>>function ;									   	   		
	else
	   *execution=cmd52.data&0x1;									   	   		
	   
	return NO_ERROR;         
}
/*************************************************************************
* FUNCTION
*  SDIO_check_IO_ready_flag
*
* DESCRIPTION
*	This function is to check function execution status
*
* PARAMETERS
*  bus_status: bus status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
SDC_CMD_STATUS SDIO_check_IO_ready_flag(SDIO_function_id_enum function, kal_bool *ready)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xf;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   			
	if(function!=SDIO_FUCN_MEM)		 
	   *ready=(cmd52.data&(1<<function))>>function ;									   	   		
	else
	   *ready=cmd52.data&0x1;									   	   		
	   
	return NO_ERROR;         
}
#endif
#endif