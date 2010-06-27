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
 *   sccb_v2.c
 *
 *
 * Description:
 * ------------
 *   SCCB/I2C V2 Driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "stack_timer.h"      /*stack_timer_struct....definitions*/
#include "drv_comm.h"
#include "reg_base.h"
#include "sccb_v2.h"

#if (defined(DRV_I2C_25_SERIES))
//#define I2C_DEBUG

#define I2C_POWER_OFF	DRV_Reg(DRVPDN_CON2_SET) = DRVPDN_CON2_SCCB  /* Power off SCCB */
#define I2C_POWER_ON    DRV_Reg(DRVPDN_CON2_CLR) = DRVPDN_CON2_SCCB/* Power on SCCB */	
#define I2C_DMA_POWER_ON   DRV_Reg(DRVPDN_CON0_CLR) = DRVPDN_CON0_DMA   /* Power on DMA */

sccb_handle_struct sccb_handle[SCCB_NUM_OF_OWNER];
sccb_status_struct i2c_status;


#if defined(I2C_DEBUG)
#define I2C_LOG 0xff
volatile kal_uint32 LT;
volatile kal_uint32 WLT_C=0,RLT_C=0,ContWLT_C=0,ContRLT_C=0,WRLT_C=0;

volatile kal_uint32 Wbase,Wcount;

volatile kal_int32 WorstWLT=0,WorstRLT=0,WorstContWLT=0,WorstContRLT=0,WorstWRLT=0;
volatile kal_int32 WLT[I2C_LOG+1],RLT[I2C_LOG+1],ContWLT[I2C_LOG+1],ContRLT[I2C_LOG+1],WRLT[I2C_LOG+1];

#endif

void i2c_lisr(void);
void i2c_init(void)
{
 //kal_uint32 savedMask;

 	
 i2c_status.state=SCCB_READY_STATE;
 
 //savedMask = SaveAndSetIRQMask();
   /* Switch GPIO to HW Mode */
   //GPIO_ModeSetup(SCCB_SERIAL_CLK_PIN,SCCB_GPIO_SCL_MODE);
   //GPIO_ModeSetup(SCCB_SERIAL_DATA_PIN,SCCB_GPIO_SDA_MODE);
 //RestoreIRQMask(savedMask);
 
 IRQ_Register_LISR(IRQ_I2C_CODE, i2c_lisr,"I2C ISR");
 IRQUnmask(IRQ_I2C_CODE);
    
 ENABLE_I2C_ACK_ERR_DET; //Always enable ack error detection
 ENABLE_I2C_NAKERR_DET;  //Always enable nack error detection
 
 #if (defined(SCCB_DMA_ENABLED))
  i2c_status.is_DMA_enabled=KAL_FALSE;
 #endif
}


//----------------------------Sccb internal arbiteration------------------------------
//--When return from this function, I bit is turned off!!--
static kal_uint32 i2c_wait_transaction_complete_and_lock(SCCB_OWNER owner)
{
 kal_uint32 savedMask;

 while(1)
 {
  if(i2c_status.state==SCCB_READY_STATE)
  {
   savedMask = SaveAndSetIRQMask();
   
   #if defined(I2C_DEBUG)
   LT=DRV_Reg(0x80200000);
   #endif
   
   if(i2c_status.state==SCCB_READY_STATE) //The sccb is currently free
   {
    i2c_status.state=SCCB_BUSY_STATE; //Lock it
    i2c_status.owner=owner;
	
    I2C_POWER_ON;
    
    return savedMask;
   }
   else
   RestoreIRQMask(savedMask); // What a pity, that the handle is locked by somebody again. back to waiting loop
  }
  else if(sccb_handle[owner].sccb_config.get_handle_wait==KAL_FALSE)
	return 0;
 }//end of while
}

static void i2c_wait_transaction_complete()
{
  while(i2c_status.state==SCCB_BUSY_STATE);
  return;
}

void i2c_lisr(void)
{
 kal_uint32 savedMask;
 kal_uint32 sta;
 sccb_handle_struct* handle;
 register kal_uint8* read_buffer;
 register kal_uint32 number_of_read;
 register kal_uint32 i;
 
 savedMask = SaveAndSetIRQMask();

 read_buffer=i2c_status.read_buffer;
 number_of_read=i2c_status.number_of_read;

 handle=&sccb_handle[i2c_status.owner];

 sta=REG_I2C_INT_STA;

 if(sta == I2C_TRANSAC_COMPLETE) //This transaction is done now
 {
  handle->transaction_result=SCCB_TRANSACTION_COMPLETE;
  #if(defined (I2C_DMA_ENABLED))
   if(!handle->sccb_config.is_DMA_enabled) //copy the read data to the previous transcation owner
  #endif
   {
  for(i=0;i<number_of_read;i++)
   read_buffer[i]=(REG_I2C_DATA_PORT & 0xff); //copy the read data to the previous transcation owner
   }
 }
 else
 {
  handle->transaction_result=sta;
 }

 i2c_status.state=SCCB_READY_STATE;

 I2C_POWER_OFF;
 
 RestoreIRQMask(savedMask);
}


//----------------------------Sccb Configuration APIs-------------------------------
kal_uint32 i2c_set_transaction_speed_internal(SCCB_OWNER owner,SCCB_TRANSACTION_MODE mode,kal_uint8 sample_cnt_div,kal_uint8 step_cnt_div)
{
 register sccb_handle_struct* handle=&sccb_handle[owner];
 kal_uint32 clock_rate;
 
 ASSERT(owner<SCCB_NUM_OF_OWNER);

 clock_rate= SCCB_CLOCK_RATE/2/sample_cnt_div/step_cnt_div; 

 if(mode==SCCB_TRANSACTION_FAST_MODE)
 {
  ASSERT(sample_cnt_div <= 8); //3 bits only
  ASSERT(step_cnt_div <= 64 );	//6 bits only
  
    if(clock_rate > 400)
	ASSERT(0);
  
  handle->fs_sample_cnt_div=sample_cnt_div-1;
  handle->fs_step_cnt_div=step_cnt_div-1;
	 
 }
 else if(mode==SCCB_TRANSACTION_HIGH_SPEED_MODE)
 {
  ASSERT(sample_cnt_div <=8); //3 bits only
  ASSERT(step_cnt_div <=8);	//3 bits only

  if(clock_rate <= 400)
   ASSERT(0);

  handle->hs_sample_cnt_div=sample_cnt_div-1;
  handle->hs_step_cnt_div=step_cnt_div-1;
 }
 else
  ASSERT(0);

 handle->sccb_config.transaction_mode=mode;
 
 return clock_rate;
}

void i2c_set_transaction_speed(SCCB_OWNER owner,SCCB_TRANSACTION_MODE mode,kal_uint32* Fast_Mode_Speed,kal_uint32* HS_Mode_Speed)
{
 kal_uint32	step_cnt_div;
 kal_uint32	sample_cnt_div;
 kal_uint32	temp;
 	
 ASSERT(owner<SCCB_NUM_OF_OWNER);

 if(mode==SCCB_TRANSACTION_FAST_MODE && Fast_Mode_Speed==0)
 {
  ASSERT(0);	
 }
 
 if(mode==SCCB_TRANSACTION_HIGH_SPEED_MODE && (Fast_Mode_Speed==0 || HS_Mode_Speed==0))
 {
  ASSERT(0);
 }

 if(*Fast_Mode_Speed>400)//Out of Spec.
  ASSERT(0);	
	
 //Fast Mode Speed
  for(sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
  {
   temp=((*Fast_Mode_Speed)*2*sample_cnt_div);	
   step_cnt_div=(SCCB_CLOCK_RATE+temp-1)/temp;	//cast the <1 part
   
   if(step_cnt_div<=64) 
    break;
  }
  if(step_cnt_div>64 && sample_cnt_div>8)
  {
   step_cnt_div=64;
   sample_cnt_div=8;
  }
  
  *Fast_Mode_Speed=i2c_set_transaction_speed_internal(owner,SCCB_TRANSACTION_FAST_MODE,sample_cnt_div,step_cnt_div);
  
 //HS Mode Speed
 if(mode==SCCB_TRANSACTION_HIGH_SPEED_MODE) 
 { 
  if(*HS_Mode_Speed<=400 || *HS_Mode_Speed>3400) //Out of Spec.
   ASSERT(0);
   
   for(sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
   {
    temp=((*HS_Mode_Speed)*2*sample_cnt_div);	
    step_cnt_div=(SCCB_CLOCK_RATE+temp-1)/temp;
    if(step_cnt_div<=8) 
     break;
   }
   
   *HS_Mode_Speed=i2c_set_transaction_speed_internal(owner,SCCB_TRANSACTION_HIGH_SPEED_MODE,sample_cnt_div,step_cnt_div);
 }
}

/* Or, you can set one of the sccb configuration */
kal_uint32 i2c_set_transaction_mode(SCCB_OWNER owner,SCCB_TRANSACTION_MODE mode,SCCB_SPEED_ENUM speed)
{
 kal_uint8	step_cnt_div=2;
 kal_uint8	sample_cnt_div=1;

 ASSERT(owner<SCCB_NUM_OF_OWNER);

 

 if(mode==SCCB_TRANSACTION_FAST_MODE)
 {
  ASSERT(speed<=SCCB_400KB); //must less than or equal to 400KB
 }
 else if(mode==SCCB_TRANSACTION_HIGH_SPEED_MODE)
 {
  ASSERT(speed>SCCB_400KB); // must greater than 400KB
 }
 else
  ASSERT(0);

 switch(speed)
 {	/* Fast Mode */
	case SCCB_100KB:	step_cnt_div=13;	sample_cnt_div=5;	break;	//100.0KB
	case SCCB_200KB:	step_cnt_div=32;	sample_cnt_div=1;	break;	//203.1KB
	case SCCB_300KB:	step_cnt_div=22;	sample_cnt_div=1;	break;	//295.5KB
	case SCCB_400KB:	step_cnt_div=17;	sample_cnt_div=1;	break;	//382.4KB
	/* HS Mode */
	case SCCB_460KB:	step_cnt_div=7;		sample_cnt_div=2;	break;	//464.3KB
	case SCCB_540KB:	step_cnt_div=6;		sample_cnt_div=2;	break;	//541.7KB
	case SCCB_650KB:	step_cnt_div=5;		sample_cnt_div=2;	break;	//650.0KB
	case SCCB_720KB:	step_cnt_div=3;		sample_cnt_div=3;	break;	//722.0KB

	case SCCB_810KB:	step_cnt_div=8;		sample_cnt_div=1;	break;	//812.5KB
	case SCCB_930KB:	step_cnt_div=7;		sample_cnt_div=1;	break;	//928.6KB
	case SCCB_1100KB:	step_cnt_div=6;		sample_cnt_div=1;	break;	//1083.3KB
	case SCCB_1300KB:	step_cnt_div=5;		sample_cnt_div=1;	break;	//1300.0KB
	case SCCB_1625KB:	step_cnt_div=4;		sample_cnt_div=1;	break;	//1625.0KB
	case SCCB_2150KB:	step_cnt_div=3;		sample_cnt_div=1;	break;	//2166.6KB
	case SCCB_3250KB:	step_cnt_div=2;		sample_cnt_div=1;	break;	//3250.6KB
	default: ASSERT(0);
 }
 return i2c_set_transaction_speed_internal(owner,mode,sample_cnt_div,step_cnt_div);
}

/* Of course you can config the sccb behavior all by ur own */
void i2c_config(SCCB_OWNER owner,sccb_config_struct* para)
{
  register sccb_config_struct* config=&sccb_handle[owner].sccb_config;
  ASSERT(owner<SCCB_NUM_OF_OWNER);
  
  config->sccb_mode=para->sccb_mode;//If u want the old apis, you shold always set this correctly.
  config->get_handle_wait=para->get_handle_wait;
  config->slave_address=para->slave_address;
  config->delay_len=para->delay_len;
  
  config->transaction_mode=para->transaction_mode;
  config->Fast_Mode_Speed=para->Fast_Mode_Speed;
  config->HS_Mode_Speed=para->HS_Mode_Speed;
  
  i2c_set_transaction_speed(owner,config->transaction_mode,&(config->Fast_Mode_Speed),&(config->HS_Mode_Speed));
  
  para->Fast_Mode_Speed=config->Fast_Mode_Speed;
  para->HS_Mode_Speed=config->HS_Mode_Speed;
  
  #if (defined(SCCB_DMA_ENABLED))
  config->is_DMA_enabled=para->is_DMA_enabled;	//Transaction via DMA instead of 8-byte FIFO
  #endif  
  

}

SCCB_TRANSACTION_MODE i2c_get_transaction_mode(SCCB_OWNER owner)
{
 ASSERT(owner<SCCB_NUM_OF_OWNER);
 
 return sccb_handle[owner].sccb_config.transaction_mode;	
}

void i2c_set_sccb_mode(SCCB_OWNER owner,SCCB_MODE_ENUM sccb_mode)
{
 ASSERT(owner<SCCB_NUM_OF_OWNER);
 sccb_handle[owner].sccb_config.sccb_mode=sccb_mode;
}

void i2c_set_get_handle_wait(SCCB_OWNER owner,kal_bool enable)
{
 ASSERT(owner<SCCB_NUM_OF_OWNER);
 sccb_handle[owner].sccb_config.get_handle_wait=enable;
}

void i2c_set_slave_address(SCCB_OWNER owner,kal_uint8 slave_address)
{
 ASSERT(owner<SCCB_NUM_OF_OWNER);
 sccb_handle[owner].sccb_config.slave_address=slave_address;
}

void i2c_set_delay(SCCB_OWNER owner,kal_uint8 delay)
{
 ASSERT(owner<SCCB_NUM_OF_OWNER);
 sccb_handle[owner].sccb_config.delay_len=delay;
}

#if (defined(I2C_DMA_ENABLED))
void i2c_set_DMA(SCCB_OWNER owner,kal_bool enable)
{
 ASSERT(owner<SCCB_NUM_OF_OWNER);
 sccb_handle[owner].sccb_config.is_DMA_enabled=enable;
}
#endif


//----------------------------NEW Sccb Transaction APIs-------------------------------
/*************************************************************************
* FUNCTION
*	i2c_write
*
* DESCRIPTION
*	This function write bytes to specified registers through SCCB interface
*
* PARAMETERS
*  owner : Who wants to write bytes 
*  para  : Setting value of the specified register of device
*  datalen: Number of bytes to write
*
* RETURNS
*	None
*************************************************************************/
SCCB_TRANSACTION_RESULT i2c_write(SCCB_OWNER owner,kal_uint8* para,kal_uint32 datalen)
{
 register sccb_handle_struct* handle=&sccb_handle[owner];
 register sccb_config_struct* config=&handle->sccb_config;
 kal_uint32 savedMask;
 kal_uint32 i;
 
  ASSERT(owner<SCCB_NUM_OF_OWNER);
  
  if(kal_if_lisr())
   ASSERT(0);

 #if(defined (I2C_DMA_ENABLED)) //if u want a transcation with len>8, please enable DMA.
  if((!config->is_DMA_enabled) && datalen>8)
   ASSERT(0); 
 #else
  if(datalen>8)
   ASSERT(0);
 #endif

 savedMask=i2c_wait_transaction_complete_and_lock(owner);

 if(i2c_status.owner!=owner)
 {
  if(config->get_handle_wait)
  {ASSERT(0);}
  else
	return SCCB_TRANSACTION_FAIL;
 }

 i2c_status.number_of_read=0;

 /* hw config */
 CLEAR_I2C_FIFO;
 CLEAR_I2C_STA;

 ENABLE_I2C_INT;
 
 SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_WRITE_BIT);
 
 SET_I2C_TRANSFER_LENGTH(datalen);	
 
 SET_I2C_STEP_CNT_DIV(handle->fs_step_cnt_div);
 SET_I2C_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
 if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_FAST_MODE)
 {
	SET_I2C_FAST_MODE;
	SET_I2C_ST_BETWEEN_TRANSFER;
 }
 else if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_HIGH_SPEED_MODE)
 {
	SET_I2C_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
	SET_I2C_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
	SET_I2C_HS_MODE;
	SET_I2C_RS_BETWEEN_TRANSFER;
 }
 else
  ASSERT(0);

 SET_I2C_TRANSACTION_LENGTH(1);
 DISABLE_I2C_DIR_CHANGE;
 
 #if(defined (I2C_DMA_ENABLED))
  i2c_status.is_DMA_enabled=config->is_DMA_enabled;
 if(i2c_status.is_DMA_enabled)
 {
   ENABLE_I2C_DMA_TRANSFER;

   /*DMA Setting*/
   I2C_STOP_DMA_TRANSFER(4);
   I2C_SET_TX_DMA_CONTROL(4,DMA_MASTER_I2C_TX);
   I2C_SET_DMA_PROGRAMMABLE_ADDR(4,(kal_uint32)para);
   I2C_SET_DMA_TRANSFER_COUNT(4,datalen);
   I2C_START_DMA_TRANSFER(4);
 }
 else
#endif
 {
  DISABLE_I2C_DMA_TRANSFER;
 
  for(i=0;i<datalen;i++) 
  {
   REG_I2C_DATA_PORT=*(para+i);	
  }  
 }
 
 START_I2C_TRANSACTION;
 
 #if defined(I2C_DEBUG)
 WLT[WLT_C]=DRV_Reg(0x80200000)-LT;
 
 if(WLT[WLT_C]>0 && WLT[WLT_C]>WorstWLT)
  WorstWLT=WLT[WLT_C];
 
 WLT_C++; 
 WLT_C&=I2C_LOG;
 #endif
 
 RestoreIRQMask(savedMask); // !! After the configuration, clear the I bit.!!
 
 i2c_wait_transaction_complete();

 return handle->transaction_result;
}

/*************************************************************************
* FUNCTION
*	i2c_read
*
* DESCRIPTION
*	This function read bytes from specified registers through SCCB interface
*
* PARAMETERS
*  owner : Who wants to read bytes 
*  para  : read buffer of reading the specified register from device
*  datalen: Number of bytes to read
*
* RETURNS
*	None
*************************************************************************/
SCCB_TRANSACTION_RESULT i2c_read(SCCB_OWNER owner,kal_uint8* para,kal_uint32 datalen)
{
 register sccb_handle_struct* handle=&sccb_handle[owner];
 register sccb_config_struct* config=&handle->sccb_config;
 kal_uint32 savedMask;

 ASSERT(owner<SCCB_NUM_OF_OWNER);
 
  if(kal_if_lisr())
   ASSERT(0);
 
 #if(defined (I2C_DMA_ENABLED)) //if u want a transcation with len>8, please enable DMA.
  if((!config->is_DMA_enabled) && datalen>8)
   ASSERT(0); 
 #else
  if(datalen>8)
   ASSERT(0);
 #endif

 savedMask=i2c_wait_transaction_complete_and_lock(owner);
 if(i2c_status.owner!=owner)
 {
  if(config->get_handle_wait)
  {ASSERT(0);}
  else
	return SCCB_TRANSACTION_FAIL;
 }
  i2c_status.read_buffer=para;

  CLEAR_I2C_FIFO;
  CLEAR_I2C_STA;

  ENABLE_I2C_INT;
 
 SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_READ_BIT);
 
 SET_I2C_TRANSFER_LENGTH(datalen);
 
 SET_I2C_STEP_CNT_DIV(handle->fs_step_cnt_div);
 SET_I2C_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
 if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_FAST_MODE)
 {
	SET_I2C_FAST_MODE;
	SET_I2C_ST_BETWEEN_TRANSFER;
 }
 else if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_HIGH_SPEED_MODE)
 {
	SET_I2C_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
	SET_I2C_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
	SET_I2C_HS_MODE;
	SET_I2C_RS_BETWEEN_TRANSFER;
 }
 else
  ASSERT(0);
 
 SET_I2C_TRANSACTION_LENGTH(1);
 DISABLE_I2C_DIR_CHANGE;
 
 #if(defined (I2C_DMA_ENABLED))
 i2c_status.is_DMA_enabled=config->is_DMA_enabled;
 if(i2c_status.is_DMA_enabled)
 {
   i2c_status.number_of_read=0;	
   ENABLE_I2C_DMA_TRANSFER;

   /*DMA Setting*/
   I2C_STOP_DMA_TRANSFER(5);
   I2C_SET_RX_DMA_CONTROL(5,DMA_MASTER_I2C_RX);
   I2C_SET_DMA_PROGRAMMABLE_ADDR(5,(kal_uint32)para);
   I2C_SET_DMA_TRANSFER_COUNT(5,datalen);
   I2C_START_DMA_TRANSFER(5);
 }
 else
#endif
 {
  i2c_status.number_of_read=datalen;	
  DISABLE_I2C_DMA_TRANSFER;
 }
 
 START_I2C_TRANSACTION;
 #if defined(I2C_DEBUG)
 RLT[RLT_C]=DRV_Reg(0x80200000)-LT;
  
  if(RLT[RLT_C]>0 && WLT[RLT_C]>WorstRLT)
  WorstRLT=RLT[RLT_C];
  RLT_C++; 
 
 RLT_C&=I2C_LOG;
 #endif
 RestoreIRQMask(savedMask); // !! After the configuration, clear the I bit.!!
 
 i2c_wait_transaction_complete();

 return handle->transaction_result;
}

/*************************************************************************
* FUNCTION
*	i2c_cont_write
*
* DESCRIPTION
*	This function write bytes to specified registers through SCCB interface via multiple transaction
*
* PARAMETERS
*  owner : Who wants to write bytes 
*  para  : Setting value of the specified register of device
*  datalen: Number of bytes in one transfer
*  transfer_num: Number of transfer in this transaction
*
* RETURNS
*	None
*************************************************************************/
SCCB_TRANSACTION_RESULT i2c_cont_write(SCCB_OWNER owner,kal_uint8* para,kal_uint32 transfer_num,kal_uint32 datalen)
{
 register sccb_handle_struct* handle=&sccb_handle[owner];
 register sccb_config_struct* config=&handle->sccb_config;
 register kal_uint32 count;
 kal_uint32 savedMask;
 kal_uint32 i;
 
 //config->is_DMA_enabled=1;

 ASSERT(owner<SCCB_NUM_OF_OWNER);
 
 if(kal_if_lisr())
   ASSERT(0);
  
 count=datalen*transfer_num;

 #if(defined (I2C_DMA_ENABLED)) //if u want a transcation with len>8, please enable DMA.
  if((!config->is_DMA_enabled) && count>8)
   ASSERT(0); 
 #else
  if(count>8)
   ASSERT(0);
 #endif

  //if(handle->transaction_mode==SCCB_TRANSACTION_HIGH_SPEED_MODE && config->delay_len!=0)
	//ASSERT(0); //Multi-transfer with STOP condition can't be applied to high speed mode.

 savedMask=i2c_wait_transaction_complete_and_lock(owner);

 if(i2c_status.owner!=owner)
 {
  if(config->get_handle_wait)
  {ASSERT(0);}
  else
	return SCCB_TRANSACTION_FAIL;
 }

 i2c_status.number_of_read=0;

 /* hw config */
 CLEAR_I2C_FIFO;
 CLEAR_I2C_STA;

 ENABLE_I2C_INT;
 
 SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_WRITE_BIT);
 
 SET_I2C_TRANSFER_LENGTH(datalen);
 SET_I2C_TRANSACTION_LENGTH(transfer_num);
 
 SET_I2C_STEP_CNT_DIV(handle->fs_step_cnt_div);
 SET_I2C_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
 if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_FAST_MODE)
 {
	SET_I2C_FAST_MODE;
	if(config->delay_len>0)
	{
	 SET_I2C_ST_BETWEEN_TRANSFER;
	 SET_I2C_DELAY_LENGTH(config->delay_len-1);
	}
	else
    {
	 SET_I2C_RS_BETWEEN_TRANSFER;
	}
 }	 
 else if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_HIGH_SPEED_MODE)
 {
	SET_I2C_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
	SET_I2C_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
	SET_I2C_HS_MODE;
	SET_I2C_RS_BETWEEN_TRANSFER;
 }
 else
  ASSERT(0);

 
 DISABLE_I2C_DIR_CHANGE;
 
 #if(defined (I2C_DMA_ENABLED))
  i2c_status.is_DMA_enabled=config->is_DMA_enabled;
 if(i2c_status.is_DMA_enabled)
 {
   ENABLE_I2C_DMA_TRANSFER;

   /*DMA Setting*/
   I2C_STOP_DMA_TRANSFER(4);
   I2C_SET_TX_DMA_CONTROL(4,DMA_MASTER_I2C_TX);
   I2C_SET_DMA_PROGRAMMABLE_ADDR(4,(kal_uint32)para);
   I2C_SET_DMA_TRANSFER_COUNT(4,count);
   I2C_START_DMA_TRANSFER(4);	
 }
 else
#endif
 {
  DISABLE_I2C_DMA_TRANSFER;
 
  for(i=0;i<count;i++) 
  {
   REG_I2C_DATA_PORT=*(para+i);	
  }  
 }
 
 START_I2C_TRANSACTION;
 
 #if defined(I2C_DEBUG)
 ContWLT[ContWLT_C]=DRV_Reg(0x80200000)-LT;
 
  if(ContWLT[ContWLT_C]>0 && ContWLT[ContWLT_C]>WorstContWLT)
  WorstContWLT=ContWLT[ContWLT_C];
  ContWLT_C++; 
 
 ContWLT_C&=I2C_LOG;
 #endif
 
 RestoreIRQMask(savedMask); // !! After the configuration, clear the I bit.!!
 
 i2c_wait_transaction_complete();

 return handle->transaction_result;
}

/*************************************************************************
* FUNCTION
*	i2c_read
*
* DESCRIPTION
*	This function read bytes from specified registers through SCCB interface
*
* PARAMETERS
*  owner : Who wants to read bytes 
*  para  : read buffer of reading the specified register from device
*  datalen: Number of bytes to read in one transfer
*  transfer_num: Number of transfer in this transaction
*
* RETURNS
*	None
*************************************************************************/
SCCB_TRANSACTION_RESULT i2c_cont_read(SCCB_OWNER owner,kal_uint8* para,kal_uint32 transfer_num,kal_uint32 datalen)
{
 register sccb_handle_struct* handle=&sccb_handle[owner];
 register sccb_config_struct* config=&handle->sccb_config;
 register kal_uint32 count;

 kal_uint32 savedMask;

 ASSERT(owner<SCCB_NUM_OF_OWNER);
 
 if(kal_if_lisr())
   ASSERT(0);

 count=datalen*transfer_num;

 #if(defined (I2C_DMA_ENABLED)) //if u want a transcation with len>8, please enable DMA.
  if((!config->is_DMA_enabled) && count>8)
   ASSERT(0); 
 #else
  if(count>8)
   ASSERT(0);
 #endif

  //if(handle->transaction_mode==SCCB_TRANSACTION_HIGH_SPEED_MODE && config->delay_len!=0)
	//ASSERT(0); //Multi-transfer with STOP condition can't be applied to high speed mode.

 savedMask=i2c_wait_transaction_complete_and_lock(owner);
 if(i2c_status.owner!=owner)
 {
  if(config->get_handle_wait)
   {ASSERT(0);}
  else
	return SCCB_TRANSACTION_FAIL;
 }
  i2c_status.read_buffer=para;

  CLEAR_I2C_FIFO;
  CLEAR_I2C_STA;

  ENABLE_I2C_INT;
 
 SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_READ_BIT);
 
 SET_I2C_TRANSFER_LENGTH(datalen);
 SET_I2C_TRANSACTION_LENGTH(transfer_num);
 
 SET_I2C_STEP_CNT_DIV(handle->fs_step_cnt_div);
 SET_I2C_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
 if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_FAST_MODE)
 {
	SET_I2C_FAST_MODE;
	if(config->delay_len>0)
	{
	 SET_I2C_ST_BETWEEN_TRANSFER;
	 SET_I2C_DELAY_LENGTH(config->delay_len-1);
	}
	else
    {
	 SET_I2C_RS_BETWEEN_TRANSFER;
	}
 }	 
 else if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_HIGH_SPEED_MODE)
 {
	SET_I2C_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
	SET_I2C_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
	SET_I2C_HS_MODE;
	SET_I2C_RS_BETWEEN_TRANSFER;
 }
 else
  ASSERT(0);
 
 DISABLE_I2C_DIR_CHANGE;
 
 #if(defined (I2C_DMA_ENABLED))
 i2c_status.is_DMA_enabled=config->is_DMA_enabled;
 if(i2c_status.is_DMA_enabled)
 {
   i2c_status.number_of_read=0;
   	
   ENABLE_I2C_DMA_TRANSFER;

   /*DMA Setting*/
   I2C_STOP_DMA_TRANSFER(5);
   I2C_SET_RX_DMA_CONTROL(5,DMA_MASTER_I2C_RX);
   I2C_SET_DMA_PROGRAMMABLE_ADDR(5,(kal_uint32)para);
   I2C_SET_DMA_TRANSFER_COUNT(5,count);
   I2C_START_DMA_TRANSFER(5);	
 }
 else
#endif
 {
  i2c_status.number_of_read=count;	
  DISABLE_I2C_DMA_TRANSFER;
 }
 
 START_I2C_TRANSACTION;
 #if defined(I2C_DEBUG)
 ContRLT[ContRLT_C]=DRV_Reg(0x80200000)-LT;
 if(ContRLT[ContRLT_C]>0 && ContRLT[ContRLT_C]>WorstContRLT)
  WorstContRLT=ContRLT[ContRLT_C];
  ContRLT_C++; 
 
 ContRLT_C&=I2C_LOG;
 #endif
 RestoreIRQMask(savedMask); // !! After the configuration, clear the I bit.!!
 
 i2c_wait_transaction_complete();

 return handle->transaction_result;
}

/*************************************************************************
* FUNCTION
*	i2c_write_and_read
*
* DESCRIPTION
*	This function write command to devices through SCCB interface, and then read bytes from it.
*
* PARAMETERS
*  owner : Who wants to read bytes 
*  R_buffer: The reading buffer of command to write
*  R_len: The length of R_buffer
*  W_buffer: The writing buffer of data whcih are read from device registers
*  W_len: The length of W_buffer
*
* RETURNS
*	None
*************************************************************************/
SCCB_TRANSACTION_RESULT i2c_write_and_read(SCCB_OWNER owner,kal_uint8* in_buffer,kal_uint32 in_len,kal_uint8* out_buffer,kal_uint32 out_len)
{
 register sccb_handle_struct* handle=&sccb_handle[owner];
 register sccb_config_struct* config=&handle->sccb_config;
 kal_uint32 savedMask,i;

 ASSERT(owner<SCCB_NUM_OF_OWNER);
 
 if(kal_if_lisr())
   ASSERT(0);

 #if(defined (I2C_DMA_ENABLED)) 
  if((!config->is_DMA_enabled) && (out_len>8 || in_len>8))
   ASSERT(0); 
 #else
  if(out_len>8 || in_len>8) //if u want a transcation with len>8, please enable DMA.
   ASSERT(0);
 #endif

 savedMask=i2c_wait_transaction_complete_and_lock(owner);
 if(i2c_status.owner!=owner)
 {
  if(config->get_handle_wait)
  {ASSERT(0);}
  else
	return SCCB_TRANSACTION_FAIL;
 }
 i2c_status.read_buffer=out_buffer;

 CLEAR_I2C_FIFO;
 CLEAR_I2C_STA;

 ENABLE_I2C_INT;
 
 SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_WRITE_BIT);
 SET_I2C_TRANSFER_LENGTH(in_len);
 SET_I2C_AUX_TRANSFER_LENGTH(out_len);
 SET_I2C_RS_BETWEEN_TRANSFER;
 SET_I2C_TRANSACTION_LENGTH(2);
 ENABLE_I2C_DIR_CHANGE;
 
 SET_I2C_STEP_CNT_DIV(handle->fs_step_cnt_div);
 SET_I2C_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
 if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_FAST_MODE)
 {
	SET_I2C_FAST_MODE;
	//SET_I2C_ST_BETWEEN_TRANSFER;
 }
 else if(handle->sccb_config.transaction_mode==SCCB_TRANSACTION_HIGH_SPEED_MODE)
 {
	SET_I2C_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
	SET_I2C_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
	SET_I2C_HS_MODE;
	//SET_I2C_RS_BETWEEN_TRANSFER;
 }
 else
  ASSERT(0);
 
 #if(defined (I2C_DMA_ENABLED))
 i2c_status.is_DMA_enabled=config->is_DMA_enabled;
 if(i2c_status.is_DMA_enabled)
 {
   i2c_status.number_of_read=0;	
   ENABLE_I2C_DMA_TRANSFER;

   //DMA Setting
   I2C_STOP_DMA_TRANSFER(4);
   I2C_SET_TX_DMA_CONTROL(4,DMA_MASTER_I2C_TX);
   I2C_SET_DMA_PROGRAMMABLE_ADDR(4,(kal_uint32)in_buffer);
   I2C_SET_DMA_TRANSFER_COUNT(4,in_len);
   I2C_START_DMA_TRANSFER(4);
   
   I2C_STOP_DMA_TRANSFER(5);
   I2C_SET_RX_DMA_CONTROL(5,DMA_MASTER_I2C_RX);
   I2C_SET_DMA_PROGRAMMABLE_ADDR(5,(kal_uint32)out_buffer);
   I2C_SET_DMA_TRANSFER_COUNT(5,out_len);
   I2C_START_DMA_TRANSFER(5);		
 }
 else
#endif
 {
  i2c_status.number_of_read=out_len;	
  DISABLE_I2C_DMA_TRANSFER;
 
  for(i=0;i<in_len;i++) 
  {
   REG_I2C_DATA_PORT=*(in_buffer+i);	
  }  
 }
 
 START_I2C_TRANSACTION;	
 
 #if defined(I2C_DEBUG)
 WRLT[WRLT_C]=DRV_Reg(0x80200000)-LT;
 if(WRLT[WRLT_C]>0 && WRLT[WRLT_C]>WorstWRLT)
 {
  WorstWRLT=WRLT[WRLT_C];
  Wbase=LT;
  Wcount= WRLT_C;
 }
  WRLT_C++; 
 
 WRLT_C&=I2C_LOG;
 #endif

 RestoreIRQMask(savedMask); // !! After the configuration, clear the I bit.!!
 
 i2c_wait_transaction_complete();
 
 return handle->transaction_result;
}

//---------------------------Old Sccb Transcation APIs--------------------------------
void sccb_write(SCCB_OWNER owner,kal_uint32 cmd, kal_uint32 param)
{
 register sccb_config_struct* config=&sccb_handle[owner].sccb_config;
 kal_uint8 sccb_buffer[3];
 
  ASSERT(owner<SCCB_NUM_OF_OWNER);

 	if(config->sccb_mode==SCCB_SW_8BIT)
	{/*
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		sccb_send_byte(param);
		SCCB_STOP_TRANSMISSION;
		*/
	}	
	else if(config->sccb_mode==SCCB_SW_16BIT)
	{/*
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		sccb_send_byte(param>>8);
		sccb_send_byte(param&0xFF);
		SCCB_STOP_TRANSMISSION;
		*/
	}	
	else if(config->sccb_mode==SCCB_HW_8BIT)
	{
		sccb_buffer[0]=cmd;
		sccb_buffer[1] = param;
		i2c_write(owner,sccb_buffer,2);
	}
	else if(config->sccb_mode==SCCB_HW_16BIT)
	{	
		sccb_buffer[0] = cmd;
		sccb_buffer[1] = (param&0xff00)>>8;
		sccb_buffer[2] = (param&0xff);  
		i2c_write(owner,sccb_buffer,3);
	}		
	else
	{
		ASSERT(0);
	}	
}

void sccb_multi_write(SCCB_OWNER owner,kal_uint32 cmd, kal_uint32 *param, kal_uint8 num)
{
 	kal_uint16 i;
	kal_uint8 sccb_buffer[SCCB_MAXIMUM_TRANSACTION_LENGTH];
	register sccb_config_struct* config=&sccb_handle[owner].sccb_config;

	if((config->sccb_mode==SCCB_SW_8BIT)||(config->sccb_mode==SCCB_SW_16BIT))
	{/*
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		for(i=0;i<num;i++)			
			sccb_send_byte(param[i]);
		SCCB_STOP_TRANSMISSION;*/
	}	
	else if(config->sccb_mode==SCCB_HW_8BIT)	
	{
	 if(num+1>SCCB_MAXIMUM_TRANSACTION_LENGTH)
	  ASSERT(0);
	 sccb_buffer[0] = cmd;
	 for(i=0;i<num;i++)	
	  sccb_buffer[i+1] = param[i];		
	 
	 i2c_write(owner,sccb_buffer,num+1);			
	}		
	else if(config->sccb_mode==SCCB_HW_16BIT)
	{	
	 if(num*2+1>SCCB_MAXIMUM_TRANSACTION_LENGTH)
	  ASSERT(0);
		
  	  sccb_buffer[0] = cmd;
	  for(i=0;i<num;i++)	
	  {		
		sccb_buffer[2*i+1] = (param[i]&0xff00)>>8;
		sccb_buffer[2*i+2] = (param[i]&0xff);
	  }
	 i2c_write(owner,sccb_buffer,2*num+1);;
	}		
	else
	{
		ASSERT(0);
	}		
}

void sccb_cont_write(SCCB_OWNER owner,kal_uint32 cmd, kal_uint32 spec_cmd, kal_uint32 param)
{
	register sccb_config_struct* config=&sccb_handle[owner].sccb_config;
	kal_uint8 sccb_buffer[4];

	if(config->sccb_mode==SCCB_SW_8BIT)
	{
	 /*
	SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
	sccb_send_byte(cmd);
		sccb_send_byte(param>>8);
		SCCB_STOP_TRANSMISSION;		
		
		SCCB_START_TRANSMISSION;	//Re-Start Bit
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(spec_cmd);
		sccb_send_byte(param&0xFF);
	SCCB_STOP_TRANSMISSION;*/
	}	
	else if(config->sccb_mode==SCCB_HW_8BIT)
	{
		sccb_buffer[0]=cmd;
		sccb_buffer[1] = param>>8;
		sccb_buffer[2]=spec_cmd;
		sccb_buffer[3] = param&0xff;
		i2c_write(owner,sccb_buffer,2);
		i2c_cont_write(owner,sccb_buffer,2,2);
	}
	else
	{
		ASSERT(0);
	}	
}

kal_uint32 sccb_read (SCCB_OWNER owner,kal_uint32 cmd)
{
	register sccb_config_struct* config=&sccb_handle[owner].sccb_config;
	kal_uint32 get_byte=0;
	kal_uint8 sccb_buffer[2];
	
	if(config->sccb_mode==SCCB_SW_8BIT)
	{
		/*
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		SCCB_STOP_TRANSMISSION;
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		get_byte=sccb_get_byte();
		SCCB_STOP_TRANSMISSION;*/
	}
	else if(config->sccb_mode==SCCB_SW_16BIT)
	{/*
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		SCCB_STOP_TRANSMISSION;
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		get_byte=sccb_get_byte();
		SCCB_STOP_TRANSMISSION;*/											
	}	
	else if(config->sccb_mode==SCCB_HW_8BIT)	
	{						
		sccb_buffer[0]=cmd;
		i2c_write(owner,sccb_buffer,1);
		
		i2c_read(owner,sccb_buffer,1);
		
		get_byte = sccb_buffer[0] & 0xFF;
	}
	else if(config->sccb_mode==SCCB_HW_16BIT)
	{	
		sccb_buffer[0]=cmd;
		i2c_write(owner,sccb_buffer,1);		
		
		i2c_read(owner,sccb_buffer,2);
		get_byte=(sccb_buffer[0]<<8) | (sccb_buffer[1]);  		
	}		
	else
	{
		ASSERT(0);
	}	

	return get_byte;
}

kal_uint32 sccb_phase3_read (SCCB_OWNER owner,kal_uint32 cmd)
{
	register sccb_config_struct* config=&sccb_handle[owner].sccb_config;
	kal_uint16 get_byte=0;
	kal_uint8 sccb_buffer[2];

	if(config->sccb_mode==SCCB_SW_8BIT)
	{
		/*
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_write_id);
		sccb_send_byte(cmd);
		SCCB_STOP_TRANSMISSION;
		SCCB_START_TRANSMISSION;
		sccb_send_byte(sccb_read_id);
		get_byte = (sccb_get_byte()&0xFF)<<8;
		get_byte |= (sccb_get_byte()&0xFF);		
		SCCB_STOP_TRANSMISSION;
		*/
	}
	else if(config->sccb_mode==SCCB_HW_8BIT)	
	{
		sccb_buffer[0]=cmd;
		i2c_write(owner,sccb_buffer,1);		
		
		i2c_read(owner,sccb_buffer,2);
		get_byte=(sccb_buffer[0]<<8) | (sccb_buffer[1]);  
	}
	else
	{
		ASSERT(0);
	}	
	
	return get_byte;

}

kal_uint8 sccb_multi_read (SCCB_OWNER owner,kal_uint32 cmd, kal_uint32 *param, kal_uint8 num)
{
	kal_uint16 idx;
	
	kal_uint8 sccb_buffer[SCCB_MAXIMUM_TRANSACTION_LENGTH];
	register sccb_config_struct* config=&sccb_handle[owner].sccb_config;

	if((config->sccb_mode==SCCB_SW_8BIT)||(config->sccb_mode==SCCB_SW_16BIT))
	{/*						
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
			return KAL_FALSE;	*/	
	}
	else if(config->sccb_mode==SCCB_HW_8BIT)	
	{
		sccb_buffer[0]=cmd;
		i2c_write(owner,sccb_buffer,1);

		if(i2c_read(owner,sccb_buffer,2)!=SCCB_TRANSACTION_COMPLETE) return KAL_FALSE;
		for(idx=0;idx<num;idx++)
		{
		 param[idx]=sccb_buffer[idx];
		}
	}
	else if(config->sccb_mode==SCCB_HW_16BIT)
	{	
		sccb_buffer[0]=cmd;
		i2c_write(owner,sccb_buffer,1);		
		
		if(i2c_read(owner,sccb_buffer,2*num)!=SCCB_TRANSACTION_COMPLETE) return KAL_FALSE;

		for(idx=0;idx<num;idx++)		
		{
			param[idx] = (((sccb_buffer[2*num])&0xff)<<8) | ((sccb_buffer[2*num+1]));
		}				
	}		
	else
	{
		ASSERT(0);
	}	

	return KAL_TRUE;
}

kal_uint32 sccb_cont_read (SCCB_OWNER owner,kal_uint32 cmd, kal_uint32 spec_cmd)
{
	kal_uint8 sccb_buffer[SCCB_MAXIMUM_TRANSACTION_LENGTH];
	register sccb_config_struct* config=&sccb_handle[owner].sccb_config;

	kal_uint16 get_byte;
	kal_uint8 hibyte=0, lobyte=0;
	
	if(config->sccb_mode==SCCB_SW_8BIT)
	{/*						
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
	SCCB_STOP_TRANSMISSION;*/
	}
	else if(config->sccb_mode==SCCB_HW_8BIT)	
	{
		sccb_buffer[0]=cmd;
		i2c_write(owner,sccb_buffer,1);

		i2c_read(owner,sccb_buffer,1);
		hibyte=sccb_buffer[0];

		sccb_buffer[0]=spec_cmd;
		i2c_write(owner,sccb_buffer,1);

		i2c_read(owner,sccb_buffer,1);
		lobyte=sccb_buffer[1];
	}
	else
	{
		ASSERT(0);
	}	
	get_byte =(hibyte<<8) | (lobyte);								
	return get_byte;
}

#ifdef I2C_V2_DVT

//Logging
#define SCCB_LOG 0xff
#define MAXIMUM_Q_BIT_COUNT	5000

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   #define RECORD_RESULT(record,count,worst){}
   #define RECORD_Q_BIT(Q){}
#endif

volatile kal_uint32 TP_W_C=0,TP_R_C=0,TP_WR_C=0,TP_ContR_C=0;
volatile kal_int32 MS_ContW_C=0,MS_WR_C=0,MS_WR1_C=0;
volatile kal_int32 Worst_TP_W=0,Worst_TP_R=0,Worst_TP_WR=0,Worst_TP_ContR=0;
volatile kal_int32 Worst_MS_ContW=0,Worst_MS_WR=0,Worst_MS_WR1=0;
volatile kal_int32 TP_W[SCCB_LOG+1],TP_R[SCCB_LOG+1],TP_WR[SCCB_LOG+1],TP_ContR[SCCB_LOG+1];
volatile kal_int32 MS_ContW[SCCB_LOG+1],MS_WR[SCCB_LOG+1],MS_WR1[SCCB_LOG+1];

volatile kal_int32 TP_SCCB_R[SCCB_LOG+1],Worst_TP_SCCB_R,TP_SCCB_R_C;

//--Touch Panel--
#define TP_SLAVE_ADDR		0x90
#define TP_CMD_X_POS_12BIT	0xc0
#define TP_CMD_Y_POS_12BIT	0xd0

//--Motion Sensor KXB84--
#define MS_SLAVE_ADDR		0x30 //ADDR0 must be connect to ground

#define XOUT_H		0x00
#define XOUT_L		0x01
#define YOUT_H		0x02
#define YOUT_L		0x03
#define ZOUT_H		0x02
#define ZOUT_L		0x03
#define FF_INT		0x06
#define FF_DELAY	0x07
#define MOT_INT		0x08
#define MOT_DELAY	0x09
#define CTRL_REGC	0x0A
#define CTRL_REGB	0x0B
#define CTRL_REGA	0x0C

kal_uint32 tp_count=0;
kal_uint32 ms_count=0;

void I2C_tp_test(kal_uint32 option,kal_uint32 round)
{
  kal_uint32 i,j,X,Y,data;	
  kal_uint8  tp_write_cmd_buffer[2]={TP_CMD_X_POS_12BIT,TP_CMD_Y_POS_12BIT};
  kal_uint8  tp_read_buffer[2];
  SCCB_TRANSACTION_RESULT ret;
  kal_uint32 savedMask;
  volatile kal_int32 t,temp;
  
  switch(option)
  {
   case 0 : // Single transfer
   {
    for(i=0;i<round;i++)
    {
     //for(j=0;j<delay;j++) ;
     
     //X 
     RECORD_Q_BIT(temp);
     ret=i2c_write(SCCB_OWNER_TP,tp_write_cmd_buffer,1);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_W,TP_W_C,Worst_TP_W);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 0] Error code:%d\n\r",i,ret);continue;}
     
     RECORD_Q_BIT(temp);
     ret=i2c_read(SCCB_OWNER_TP,tp_read_buffer,2);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_R,TP_R_C,Worst_TP_R);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 0] Error code:%d\n\r",i,ret);continue;}
      X=(tp_read_buffer[0]<<8) + tp_read_buffer[1];
     
     //Y
     RECORD_Q_BIT(temp);	   	
     ret=i2c_write(SCCB_OWNER_TP,tp_write_cmd_buffer+1,1);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_W,TP_W_C,Worst_TP_W);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 0] Error code:%d\n\r",i,ret);continue;}
     
     RECORD_Q_BIT(temp);
     ret=i2c_read(SCCB_OWNER_TP,tp_read_buffer,2);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_R,TP_R_C,Worst_TP_R);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 0] Error code:%d\n\r",i,ret);continue;}
     Y=(tp_read_buffer[0]<<8) + tp_read_buffer[1];

     dbg_print("[TP 0] X=%x, Y=%x \n\r",X,Y);	
    }

   break;
   }
   case 1: // Repeated Start test with direction change
   {
    for(i=0;i<round;i++)
    {
     //for(j=0;j<delay;j++) ;
     RECORD_Q_BIT(temp);
     ret=i2c_write_and_read(SCCB_OWNER_TP,tp_write_cmd_buffer,1,tp_read_buffer,2);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_WR,TP_WR_C,Worst_TP_WR);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 1] Error code:%d\n\r",i,ret);continue;}
     X=(tp_read_buffer[0]<<8) + tp_read_buffer[1];
     
     RECORD_Q_BIT(temp);
     ret=i2c_write_and_read(SCCB_OWNER_TP,tp_write_cmd_buffer+1,1,tp_read_buffer,2);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_WR,TP_WR_C,Worst_TP_WR);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 1] Error code:%d\n\r",i,ret);continue;}
     Y=(tp_read_buffer[0]<<8) + tp_read_buffer[1];
      
    dbg_print("[TP 1] X=%x, Y=%x \n\r",X,Y);
   }
   break;
   }
   case 2:
    {
    for(i=0;i<round;i++)
    {
     //for(j=0;j<delay;j++) ;
     
     i2c_set_delay(SCCB_OWNER_TP,0);
     ret=i2c_write(SCCB_OWNER_TP,tp_write_cmd_buffer,1);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 2] Error code:%d\n\r",i,ret);continue;}
     
     RECORD_Q_BIT(temp);
     ret=i2c_cont_read(SCCB_OWNER_TP,tp_read_buffer,2,1);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_ContR,TP_ContR_C,Worst_TP_ContR);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 2] Error code:%d\n\r",i,ret);continue;}
     X=(tp_read_buffer[0]<<8) + tp_read_buffer[1];
    
     i2c_set_delay(SCCB_OWNER_TP,tp_count%5);
     ret=i2c_write(SCCB_OWNER_TP,tp_write_cmd_buffer+1,1);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 2] Error code:%d\n\r",i,ret);continue;}

     RECORD_Q_BIT(temp);   
     ret=i2c_cont_read(SCCB_OWNER_TP,tp_read_buffer,2,1);
     RECORD_Q_BIT(t);
     RECORD_RESULT(TP_ContR,TP_ContR_C,Worst_TP_ContR);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[TP 2] Error code:%d\n\r",i,ret);continue;}
     Y=(tp_read_buffer[0]<<8) + tp_read_buffer[1];

     dbg_print("[TP 2] X=%x, Y=%x \n\r",X,Y);	
    }

   break;
   }
 
  default:
   break;
 
 }
}

void I2C_ms_test1(kal_uint32 transfer_num,kal_uint32 transfer_byte)
{
 kal_uint32 i,j;
 kal_uint8 ret;
 
 kal_uint8 ms_ctrl_write_buffer_FF[100];
 kal_uint8 ms_ctrl_write_buffer_00[100];
 
 kal_uint8  ms_RA_buffer[13]={XOUT_H,XOUT_L,YOUT_H,YOUT_L,ZOUT_H,
 			      ZOUT_L,FF_INT,FF_DELAY,MOT_INT,MOT_DELAY,
 			      CTRL_REGC,CTRL_REGB,CTRL_REGA};	
 kal_uint8  ms_read_buffer[13];
  
 char str_input[16];
 kal_uint32 fifo;
 volatile kal_int32 t,temp;
 kal_uint32 savedMask;
 
  
 fifo=transfer_num*transfer_byte;
 
 if(fifo>7)
  return;
 
 //-- Cont. read write test --
     
    for(i=0;i<transfer_num;i++)
     {
      ms_ctrl_write_buffer_FF[i*(1+transfer_byte)]=ms_RA_buffer[FF_INT+i*transfer_byte];
      
      for(j=1;j<=transfer_byte;j++)
      {
      	ms_ctrl_write_buffer_FF[i*(1+transfer_byte)+j]=transfer_num*16+transfer_byte;  	
      }	      
     }
     RECORD_Q_BIT(temp);    
     ret=i2c_cont_write(SCCB_OWNER_MS,ms_ctrl_write_buffer_FF,transfer_num,transfer_byte+1);
     RECORD_Q_BIT(t);
     RECORD_RESULT(MS_ContW,MS_ContW_C,Worst_MS_ContW);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("Cont Write Error code:%d\n\r",ret);}	
     
     RECORD_Q_BIT(temp);    
     ret=i2c_write_and_read(SCCB_OWNER_MS,ms_RA_buffer+FF_INT,1,ms_read_buffer,fifo);
     RECORD_Q_BIT(t);
     RECORD_RESULT(MS_WR1,MS_WR1_C,Worst_MS_WR1);
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("Cont Read Error code:%d\n\r",ret);}	
   
     if(fifo>0)
      dbg_print("[ms] FF_INT =%x \n\r",ms_read_buffer[0]);
     if(fifo>1)
      dbg_print("[ms] FF_DELAY =%x \n\r",ms_read_buffer[1]);
     if(fifo>2)
      dbg_print("[ms] MOT_INT =%x \n\r",ms_read_buffer[2]);
     if(fifo>3)
      dbg_print("[ms] MOT_DELAY =%x \n\r",ms_read_buffer[3]);     
     if(fifo>4)
      dbg_print("[ms] CTRL_REGC =%x \n\r",ms_read_buffer[4]);
     if(fifo>5)
      dbg_print("[ms] CTRL_REGB =%x \n\r",ms_read_buffer[5]);
     if(fifo>6)
     dbg_print("[ms] CTRL_REGA =%x \n\r",ms_read_buffer[6]); 

}


void I2C_ms_test()
{
 kal_uint32 arg_num,round,round_delay=100000;
 char str_input[16];
 kal_uint32 i,j,X,Y,Z;
 kal_uint8 ret;
 volatile kal_int32 t,temp;
 kal_uint32 savedMask;
 
 kal_uint8  ms_RA_buffer[13]={XOUT_H,XOUT_L,YOUT_H,YOUT_L,ZOUT_H,
 			      ZOUT_L,FF_INT,FF_DELAY,MOT_INT,MOT_DELAY,
 			      CTRL_REGC,CTRL_REGB,CTRL_REGA};	
 kal_uint8  ms_read_buffer[13];

 round=1;

 for(i=0;i<round;i++)
 {
   // for(j=0;j<round_delay;j++) ;	
     RECORD_Q_BIT(temp);   	
     ret=i2c_write_and_read(SCCB_OWNER_MS,ms_RA_buffer,1,ms_read_buffer,6);
     RECORD_Q_BIT(t);
     RECORD_RESULT(MS_WR,MS_WR_C,Worst_MS_WR);
     
     //if(MS_WR[MS_WR_C-1]<100 && MS_WR[MS_WR_C-1]>0){while(1);}
          
     if(ret!=SCCB_TRANSACTION_COMPLETE) {dbg_print("[ms] Error code:%d\n\r",i,ret);continue;}
     X=(ms_read_buffer[0]<<8) + ms_read_buffer[1];
     Y=(ms_read_buffer[2]<<8) + ms_read_buffer[3];
     Z=(ms_read_buffer[4]<<8) + ms_read_buffer[5];
     dbg_print("[ms] X=%x, Y=%x, Z=%x \n\r",X,Y,Z);
 }
 
}

kal_bool i2c_test_main(void)
{
  sccb_config_struct config;
  
  i2c_init();
  
  I2C_DMA_POWER_ON;	
  
  //Tp init
  config.sccb_mode= SCCB_HW_16BIT ; 	 
  config.get_handle_wait=KAL_TRUE;	 
  config.slave_address= TP_SLAVE_ADDR; 
  config.delay_len = 0 ;
  config.Fast_Mode_Speed=400;	//The speed of sccb fast mode(Kb)
  config.HS_Mode_Speed=1000;	//The speed of sccb high speed mode(Kb)
  config.transaction_mode=SCCB_TRANSACTION_HIGH_SPEED_MODE;
  
  i2c_config(SCCB_OWNER_TP, &config);

  //Ms	init
  config.sccb_mode= SCCB_HW_8BIT ; 	 
  config.get_handle_wait=KAL_TRUE;	 
  config.slave_address= MS_SLAVE_ADDR;
  config.Fast_Mode_Speed=300;	//The speed of sccb fast mode(Kb)
  config.HS_Mode_Speed=800;	//The speed of sccb high speed mode(Kb)
  config.transaction_mode=SCCB_TRANSACTION_FAST_MODE;
  config.delay_len = 0 ;
  i2c_config(SCCB_OWNER_MS, &config);
 
 while(1)
 {
  kal_sleep_task(50);
  
  #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #endif
  
  #if 0
/* under construction !*/
  #endif
  
  if(sccb_handle[SCCB_OWNER_MS].sccb_config.is_DMA_enabled)
  {
   if(ms_count%3==0)
    I2C_ms_test1(2,3);
   else if(ms_count%3==1)
    I2C_ms_test1(3,2);
   else
    I2C_ms_test1(7,1); 
  }
  else
  {
   if(ms_count%2==0)
    I2C_ms_test1(2,3);
   else if(ms_count%2==1)
    I2C_ms_test1(1,2);
  }
  
  ms_count++;
 }
}

#endif //I2C_V2_DVT
#endif //DRV_I2C_25_SERIES