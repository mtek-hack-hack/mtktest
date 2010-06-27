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
 *   ms.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for Memory Stick
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
//	Include files
#include "kal_release.h"
#include "fat_fs.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "ms_def.h"
#include "gpt_sw.h"
#include "intrCtrl.h"
#include "drv_comm.h"

#if defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)

//	global variables
T_MS_HANDLE	 gMS;	// store some important parameters of MS
static kal_uint16 gLPtable[MS_PAGE_SIZE];	// for LBA(Logical adrs) to PBA(Physical adrs) translation
static kal_uint16 ms_init_defect[16];	// used to store the initial defect block
//===================================================================================//
MS_STATUS MS_MediaTypeIdentify(kal_uint8 type, kal_uint8 category, kal_uint8 _class, kal_uint8 status)
{
	if(type == 0)
	{
		if(category >= 0x80 && category <= 0xFF)
			return MS_ERR_MEDIA;
		else if(category >= 0x01 && category <= 0x7F)
			return MS_ERR_EXPAND_IO;
		else if(_class >= 0x04 && _class <= 0xFF)
			return MS_ERR_MEDIA;
	}
	else 
	{	// type == 0xFF
		if((category >= 0x80 && category <= 0xFE) || category == 0x00)
			return MS_ERR_MEDIA;
		else if(category >= 0x01 && category <= 0x7F)
			return MS_ERR_EXPAND_IO;
		else if((_class >= 0x04 && _class <= 0xFE) || _class == 0x00)
			return MS_ERR_MEDIA;		
	}

	if((_class >= 1 && _class <= 3) || status & STA0_WP)
	{
		gMS.is_wp = KAL_TRUE;
	}
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_EraseLPTable
*
* DESCRIPTION
*  Erase the Logical to Physical table in the last segment if exists
*
* PARAMETERS
*
* RETURNS
*  MS_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
MS_STATUS MS_EraseLPTable(void)
{
	MS_STATUS status;
	kal_uint32 start_block, blk;
	kal_uint8 extra[EXTRA_SIZE];

	if(gMS.is_wp)
		return MS_NOERROR;
	start_block = (gMS.NumBlock/BLOCKS_PER_SEGMENT-1)*512;
	for(blk = start_block; blk< start_block+512; blk++)
	{		
    	if((status = MS_API_ReadExtraData(blk,0,(kal_uint32*)extra)) != MS_NOERROR)
		   continue;
		if(MS_IS_LPTABLE(extra[MANAGE_FLAG]))
		{
			if((status = MS_API_EraseBlock(blk)) != MS_NOERROR)
			{
				extra[0] &= ~MS_OVFLG_BKST;
				MS_API_WriteExtraData(blk, 0, (kal_uint32 *)extra);
				return MS_ERR_ERASEFAIL;
			}
			break;
		}			
	}

	return MS_NOERROR;
}
/*************************************************************************
* FUNCTION
*  MS_Initialize
*
* DESCRIPTION
*  1. Initial the global variables for MS.
*  2. Initial the MSDC controller.
*  3. Initial the MS Card. 
*
* PARAMETERS
*
* RETURNS
*  MS_STATUS
*
* GLOBALS AFFECTED
*  1. gMS
*	2. gLPtable
*************************************************************************/
MS_STATUS MS_Initialize(void)
{
	kal_uint32 buffer;
	MS_STATUS status;

#if !defined(__MSDC_MSPRO__)
	// reset the events
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
			
	// reset msdc
	if(*(volatile kal_uint32*)MSDC_CFG & MSDC_CFG_RST)
	{
		MSDC_CLR_BIT32(MSDC_CFG, MSDC_CFG_RST);
	}
	else
	{
		RESET_MSDC();
	}
			
	// pull down for MS and MS-PRO
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)1,MSDC_CFG_PRCFG1);
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)1,MSDC_CFG_PRCFG2);
	
	//set clock of serial clcok
	gMSDC_Handle->msdc_clock = MSDC_CLOCK;
	MSDC_SetClock(MSDC_OP_CLOCK);
	// set ready time out value
	BitFieldWrite32((kal_uint32*)MSC_CFG,(kal_uint32)7,MSC_CFG_BUSYCNT);
	// enable the serial interface
	MSDC_SET_BIT32(MSC_CFG,MSC_CFG_SIEN);
	// initila the structure
#endif
	MS_SetDefault();
	if ((status = MS_API_ResetFlash())!=MS_NOERROR)
		return status;
	if ((status =MS_API_ClrBuffer())!=MS_NOERROR)
		return status;
	// check write protect status
	if ((status = MS_TPC_SetRWAdrs(MS_STA0_REG,1,0,0))!=MS_NOERROR)
		return status;
	if ((status = MS_TPC_ReadReg(&buffer,1))!=MS_NOERROR)
		return status;
	gMS.is_wp = (kal_uint8)buffer & STA0_WP;
	// read the boot block
	if((status = MS_API_ReadBootBlk())!=MS_NOERROR)
		return  MS_ERR_READBOOTBLK;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
	if((status = MS_EraseLPTable()) != MS_NOERROR)
		return status;

	if(gMS.Flags & MS_FLAG_BAP)
	{
		MS_BootAreaProtection();
	}
	MS_API_CheckLogicalAdrsValid();
	//if((status = MS_API_CheckLogicalAdrsValid())!=MS_NOERROR)
		//return MS_ERR_LPTABLE;
	// generate the LPTable for the first segment
	//if ((status = MS_API_GenLPTable(gMS.pLPTbl,gMS.pFreeTbl,0))!=MS_NOERROR)
		//return MS_ERRORS;
	gMSDC_Handle->mIsInitialized = KAL_TRUE;
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_SetDefault
*
* DESCRIPTION
*  1. Initial the global variables for MS.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*  1. gMS
*	2. gLPtable
*************************************************************************/

void MS_SetDefault(void)
{
	kal_mem_set(&gMS,0,sizeof(T_MS_HANDLE));
	// oxFFFF means invalid Physical address
	kal_mem_set((void *)gLPtable,0xFF,sizeof(gLPtable));
	// 512 : (pLPtbl)496 ... (pFreeTbl)16
	gMS.pLPTbl = gLPtable;
	gMS.pFreeTbl = gLPtable+MS_LPTABLE_SIZE;
	gMS.BootBlks[0] = gMS.BootBlks[1] = 0xFE; 
}

/*************************************************************************
* FUNCTION
*  MS_CardDetect
*
* DESCRIPTION
*  1. Detect if the card is present
*
* PARAMETERS
*
* RETURNS
*	kal_bool
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool MS_CardDetect(void)
{
	int i;

	// pull up CD/DAT3(INS) pin
	BitFieldWrite32((kal_uint32*)MSDC_CFG,2,MSDC_CFG_PRCFG0);
	// enable card detection and input pin at the same time
	MSDC_SET_BIT32(MSDC_PS, (MSDC_PS_CDEN|MSDC_PS_PIEN0));
	// trun on power for memory card
	MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_VDDPD);
	// to be modified : 1000 magic number 
	for( i=0; i<1000; i++)
	{
		if(*(volatile kal_uint32*)(MSDC_PS) & MSDC_PS_PINCH)
			return KAL_TRUE;
	}
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  MS_WaitCmdRdyOrTo
*
* DESCRIPTION
*  1. Wait until MS command ready or time out
*
* PARAMETERS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*  1. MSDC_Events if using HW interrupt.
*	
*************************************************************************/
MS_STATUS MS_WaitCmdRdyOrTo(void)
{
#ifdef MSDC_USE_INT	
	register kal_uint16 msc_sta;
	kal_uint32 	flags = 0;

	if(!gMSDC_Handle->mIsPresent) 
		return MS_ERR_CARD_NOT_PRESENT;	
	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
	kal_retrieve_eg_events(MSDC_Events,EVENT_MSIFIRQ|EVENT_MSRDYIRQ,KAL_OR_CONSUME,&flags,KAL_SUSPEND);	
	MSDC_STOP_TIMER();
	msc_sta = *(volatile kal_uint16*)MSC_STA;  
	if(msc_sta & MSC_STA_CRCERR)           
	{
		// if autocmd is enabled, then reset MSDC is a MUST!
		MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_RST);
		return MS_ERR_CRCERR;              
	} 
	else if(msc_sta & MSC_STA_TOER)        
	{
		// if autocmd is enabled, then reset MSDC is a MUST!
		MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_RST);
		return MS_ERR_TIMEOUT;             
	} else if(msc_sta & MSC_STA_RDY)                     
		return MS_NOERROR;                           
#else	// MSDC_USE_INT
	register kal_uint16 msc_sta;
	kal_uint32 t1;

	t1 = drv_get_current_time();
	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
	while(!MSDC_IS_INT && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
			gMSDC_Handle->is_timeout = KAL_TRUE;
	};
	MSDC_STOP_TIMER();
	MSDC_CLR_INT();	
	msc_sta = *(volatile kal_uint16*)MSC_STA;
	if(msc_sta & MSC_STA_CRCERR)
		return MS_ERR_CRCERR;
	else if(msc_sta & MSC_STA_TOER)
		return MS_ERR_TIMEOUT;
	else if(msc_sta & MSC_STA_RDY)
		return MS_NOERROR;
	if(gMSDC_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;

#endif	// MSDC_USE_INT

	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_SendTPC
*
* DESCRIPTION
*  1. tell the controller to launch the TPC code with data size.
*
* PARAMETERS
*	1. cmd: TPC( Transfer Protocol Command)
*	2. size: bytes of data for current transaction
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
void MS_SendTPC(kal_uint8 cmd, kal_uint32 size)
{
	kal_uint16 arg = 0;

	arg = cmd << MSC_CMD_PID_START;
	arg |= size;
	MSDC_WriteReg16(MSC_CMD,arg);
}

/*************************************************************************
* FUNCTION
*  MS_SetAcmd
*
* DESCRIPTION
*  1. Enable Auto command
*
* PARAMETERS
*	1. acmd: TPC of GET_INT or READ_REG
*	2. asize: bytes of data for current transaction
*
* RETURNS
*
* GLOBALS AFFECTED
*	
* NOTE
*	Auto command will take one INT bs state
*
*************************************************************************/
void MS_SetAcmd(kal_uint8 acmd, kal_uint32 asize)
{
	kal_uint16 arg = 0;

	arg = (acmd << MSC_ACMD_APID_START);
	arg |= (asize << MSC_ACMD_ACEN_START);
	arg |= MSC_ACMD_ACEN;
	MSDC_WriteReg16(MSC_ACMD,arg);
}

/*************************************************************************
* FUNCTION
*  MS_TPC_ReadPage
*
* DESCRIPTION
*  1. TPC for reading data from PageBuffer(512 bytes)
*
* PARAMETERS
*	1. rxbuffer: used for storing page data read from MS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	1. Two mechanisms of DMA transfer and Polling are implemented.
*	2. Make sure rxbuffer is at least the size of 512 bytes.
*
*************************************************************************/
MS_STATUS MS_TPC_ReadPage(kal_uint32 *rxbuffer)
{
	MS_STATUS status;
	kal_uint8 *ptr;
	
	ptr = (kal_uint8*)rxbuffer;
	

	EnableMSDC_DMA();
	MSDC_DMATransferFirst((kal_uint32)ptr,MS_PAGE_SIZE/sizeof(kal_uint32),KAL_FALSE);

	MS_SendTPC(TPC_READ_PAGE_DATA, MS_PAGE_SIZE);
	status = MSDC_DMATransferFinal();
	if(status != MS_NOERROR)
				goto ERR_Exit;		
	
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
	{
		goto ERR_Exit;
	}	
	DisableMSDC_DMA();

	return MS_NOERROR;
	
ERR_Exit:
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
	DisableMSDC_DMA();
	return status;
}

/*************************************************************************
* FUNCTION
*  MS_TPC_WritePage
*
* DESCRIPTION
*  1. TPC for writing data to PageBuffer(512 bytes)
*
* PARAMETERS
*	1. txbuffer: used for storing data written to MS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	1. Two mechanisms of DMA transfer and Polling are implemented.
*	2. Make sure rxbuffer is at least the size of 512 bytes.
*
*************************************************************************/
MS_STATUS MS_TPC_WritePage(kal_uint32 *txbuffer)
{
	MS_STATUS status;

	ASSERT((kal_uint32)txbuffer %4 == 0);
	EnableMSDC_DMA();
	MSDC_DMATransferFirst((kal_uint32)txbuffer,MS_PAGE_SIZE/sizeof(kal_uint32),KAL_TRUE);
	MS_SendTPC(TPC_WRITE_PAGE_DATA,MS_PAGE_SIZE);
	status = MSDC_DMATransferFinal();
	if(status != MS_NOERROR)
				goto ERR_Exit;				

	DisableMSDC_DMA();
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
	{
		goto ERR_Exit;
	}	
	return MS_NOERROR;
	
ERR_Exit:
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
	DisableMSDC_DMA();
	return status;	
}

/*************************************************************************
* FUNCTION
*  MS_TPC_ReadReg
*
* DESCRIPTION
*  1. TPC for reading registers which address is set by MS_TPC_SetRWAdrs 
*
* PARAMETERS
*	1. buffer: used for storing data read from registers
*	2. length: bytes of data to read
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
* 	buffer must be prepared up to multiple of 4 ,ex.
*  if length = 7 , u must prepare 8 bytes  = 2x4 bytes as buffer size
*
*************************************************************************/
MS_STATUS MS_TPC_ReadReg(kal_uint32 *buffer, kal_uint8 length)
{
	MS_STATUS status;
	kal_uint32 i,count;

	MS_SendTPC(TPC_READ_REG,length);
	// read data from fifo
	count = (length+sizeof(kal_uint32)-1)/sizeof(kal_uint32);
	for(i=0; i<count;)
	{
		if(!gMSDC_Handle->mIsPresent) 
			return MS_ERR_CARD_NOT_PRESENT;			
		if(!MSDC_IS_FIFO_EMPTY)
		{
			*(buffer+i) = *(volatile kal_uint32*)MSDC_DAT;
			i++;
		}
	}
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
		return status;

	return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_TPC_WriteReg
*
* DESCRIPTION
*  1. TPC for writing registers which address is set by MS_TPC_SetRWAdrs 
*
* PARAMETERS
*	1. buffer: used for storing data written to registers
*	2. length: bytes of data to write
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
* 	buffer must be prepared up to multiple of 4 ,ex.
*  if length = 7 , u must prepare 8 bytes  = 2x4 bytes as buffer size
*
*************************************************************************/
//TPC for writing form the register which address was set.
MS_STATUS MS_TPC_WriteReg(kal_uint32 *buffer, kal_uint8 length)
{
	MS_STATUS status;
	kal_uint32 i,count;

	MS_SendTPC(TPC_WRITE_REG,length);
	count = (length+sizeof(kal_uint32)-1)/sizeof(kal_uint32);
	// write data into fifo
	for(i=0;i<count;)
	{
		if(!gMSDC_Handle->mIsPresent) 
			return MS_ERR_CARD_NOT_PRESENT;		
		if(!MSDC_IS_FIFO_FULL)
		{
			*(volatile kal_uint32*)MSDC_DAT = *(buffer+i);
			i++;
		}
	}
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
		return status;

	return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_TPC_SetRWAdrs
*
* DESCRIPTION
*  TPC for setting values which determine the register accessed by WRITE_REG and READ_REG
*
* PARAMETERS
*	1. r_adrs: starting address for READ_REG
*	2. r_len: consecutive size for READ_REG
*	3. w_adrs: starting address for WRITE_REG
*	4. w_len: consecutive size for WRITE_REG
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
* 	buffer must be prepared up to multiple of 4 ,ex.
*  if length = 7 , u must prepare 8 bytes  = 2x4 bytes as buffer size
*
*************************************************************************/
MS_STATUS MS_TPC_SetRWAdrs(kal_uint8 r_adrs, kal_uint8 r_len, kal_uint8 w_adrs, kal_uint8 w_len)
{
	MS_STATUS status;
	kal_uint8 data[4];

	// send the TPC (4 bytes data)
	MS_SendTPC(TPC_SET_R_W_REG_ADRS,4);

	data[0] = r_adrs;
	data[1] = r_len;
	data[2] = w_adrs;
	data[3] = w_len;

	MSDC_CLR_FIFO();
	// write data into fifo
	*(volatile kal_uint32*)MSDC_DAT = *(kal_uint32 *)data;	
	// wait cmd ready or busy timeout
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
		return status;

	return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_TPC_GetInt
*
* DESCRIPTION
*  TPC for reading 1 byte INT register
*
* PARAMETERS
*	1. intreg: storing the data read form INT register.
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
* 	buffer must be prepared up to multiple of 4 ,ex.
*  if length = 7 , u must prepare 8 bytes  = 2x4 bytes as buffer size
*
*************************************************************************/
// TPC for read 1 byte INT register
MS_STATUS MS_TPC_GetInt(kal_uint8 *intreg)
{
	MS_STATUS status;

	// the data length is 1 for INT register
	MS_SendTPC(TPC_GET_INT,1);
	// read 1 byte data from fifo
	while(MSDC_IS_FIFO_EMPTY && gMSDC_Handle->mIsPresent);
	*intreg = *(volatile kal_uint8*)MSDC_DAT;
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
		return status;

	return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_TPC_SetCmd
*
* DESCRIPTION
*  1. TPC set CMD to be executed by Flash Memory Controller.
*	2. Always cause card to issue INT
*	3. Always enable auto GET_INT
*
* PARAMETERS
*	1. cmd: command code for Flash Controller.
*	2. intreg: after excuted cmd, get INT register
*
* RETURNS
*	MS_NOERROR
*	MS_ERR_CRCERR
*	MS_ERR_TIMEOUT
*	MS_ERR_CMDNK
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_TPC_SetCmd(kal_uint8 cmd, kal_uint8 *intreg)
{
	MS_STATUS status;

	// set ACMD
	MS_SetAcmd(TPC_GET_INT,1);
	// send the TPC (1 bytes data)
	MS_SendTPC(TPC_SET_CMD,1);
	// write 1 byte data into fifo
	while(MSDC_IS_FIFO_FULL && gMSDC_Handle->mIsPresent);
	*(volatile kal_uint8*)MSDC_DAT = cmd;
#ifndef MSDC_INT	
	// wait cmd ready or busy timeout
	while(!MSDC_IS_INT && gMSDC_Handle->mIsPresent);
#endif	
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
		return status;	
	while(MSDC_IS_FIFO_EMPTY && gMSDC_Handle->mIsPresent);
	// read fifo to get int register
	*intreg = *(volatile kal_uint8*)MSDC_DAT;
	// cmd not accept
	if(*intreg & INT_NMDNK)
		return MS_ERR_CMDNK;

	return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_API_ReadSinglePage
*
* DESCRIPTION
*  Read single page with extra data from MS.
*
* PARAMETERS
*	1. blkadrs: physical block address.
*	2. page: page number of the block
*	3. rxbuffer: of size of 512bytes
*	4. extra: buffer for the extra data of the page, of size of 4 bytes.
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	if extra == NULL, doesn't read the extra data.
*
*************************************************************************/
MS_STATUS MS_API_ReadSinglePage(kal_uint32 blkadrs, kal_uint8 page, kal_uint32 *rxbuffer, kal_uint32 *extra)
{
	MS_STATUS status;
	kal_uint8 data[5],intreg;

	// set parameters
	data[0] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[1] = (kal_uint8)(blkadrs >> 8);		// block address 1
	data[2] = (kal_uint8)blkadrs;				// block address 0
	data[3] = (kal_uint8)PAGE_MODE;			// access mode		
	data[4] = page;							// page number of the block

	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,5))!=MS_NOERROR)
		return status;
	if((status = MS_TPC_WriteReg((kal_uint32*)data,5))!=MS_NOERROR)
		return status;
	// send SET_CMD[BLOCK_READ] ~ page mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_READ,&intreg))!=MS_NOERROR)
		return status;		
	// read status0~1
	if((status = MS_TPC_ReadReg((kal_uint32*)data,2))!=MS_NOERROR)
		return status;								
	// uncorrectable errors	
	if((intreg & INT_ERR))
	{
		// chect the status1
		if(data[1] & (STA1_UCFG | STA1_UCEX | STA1_UCDT))
		{
			// uncorrectable error, update the page status to 1
			MS_API_ReadExtraData( blkadrs, page, (kal_uint32*) data);
			data[0] &= ~MS_OVFLG_PGST;
			data[0] |= MS_OVFLG_PGST1;
			MS_API_WriteExtraData( blkadrs, page, (kal_uint32*) data);
			return MS_ERR_UC;	
		}
	}	
	// check int register
	if((intreg &(INT_CED|INT_BREQ)) != (INT_CED|INT_BREQ))
		return MS_ERRORS;

	// check MB and FB0 of status0
	if(data[0] & (STA0_MB | STA0_FB0))
		return MS_ERR_STABUSY;

	// data is ready at pagebuffer
	if(data[0] & STA0_BF)
	{
		// read extra data
		if(extra != NULL)
		{
			if((status = MS_TPC_SetRWAdrs(MS_OVERWRITE_REG,MS_EXTRA_RSIZE,0,0))!=MS_NOERROR)
				goto ERR_EXIT;
			if((status = MS_TPC_ReadReg(extra,MS_EXTRA_RSIZE))!=MS_NOERROR)
				goto ERR_EXIT;
		}
		// read data for pagebuffer
		if((status = MS_TPC_ReadPage(rxbuffer))!=MS_NOERROR)
			goto ERR_EXIT;		
	}else
		return MS_ERRORS;

	return MS_NOERROR;
	
ERR_EXIT:
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
	MS_API_ResetFlash();
	MS_API_ClrBuffer();
	MSDC_CLR_FIFO();
	return status;
}

/*************************************************************************
* FUNCTION
*  MS_API_ReadBlock
*
* DESCRIPTION
*	1. read numpage pages form spage during a block or till the end of the block
*	2. if extra == NULL, doesn't read the extra data
*	3. only read extra data of the start page
*
* PARAMETERS
*		blkadrs:		physical block address
*		rxbuffer:	buffer for the read data
*		extra:		buffer for the extra data
*		spage:		start of the reading page number
*		numpage:		number of the pages to read
*		readpage:	pages really be read
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	if extra == NULL, doesn't read the extra data.
*
*************************************************************************/
MS_STATUS MS_API_ReadBlock(kal_uint32 blkadrs, kal_uint32 *rxbuffer,kal_uint32 *extra, kal_uint8 spage, kal_uint8 numpage, kal_uint8 *readpage)
{
	MS_STATUS status;
	kal_uint8 data[8],i,lastpage,intreg;
	kal_uint32 *rx = rxbuffer;

	gMS.uc_pages = 0;	
	gMS.de_pages = 0;
	// set parameters                                                  
	data[0] = (kal_uint8)(blkadrs >> 16);	// block address 2             	
	data[1] = (kal_uint8)(blkadrs >> 8);	// block address 1             	
	data[2] = (kal_uint8)blkadrs;			// block address 0             	
	data[3] = (kal_uint8)BLOCK_MODE;		// access mode		           	
	data[4] = spage;					// page number of the block    	
	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,5))!=MS_NOERROR)     	
		goto ERR_EXIT;                                                 	
	if((status = MS_TPC_WriteReg((kal_uint32*)data,5))!=MS_NOERROR)	
		goto ERR_EXIT;                                                 	
	// send SET_CMD[BLOCK_READ] ~ block mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_READ,&intreg))!=MS_NOERROR)
		goto ERR_EXIT;	
	// only read extra data of the start page
	if(extra != NULL)
	{
		if((status = MS_TPC_SetRWAdrs(MS_OVERWRITE_REG,MS_EXTRA_RSIZE,0,0))!=MS_NOERROR)
			goto ERR_EXIT;				
		if((status = MS_TPC_ReadReg(extra,MS_EXTRA_RSIZE))!=MS_NOERROR)
			goto ERR_EXIT;
		//extra++;
	}
	lastpage = 0;
	*readpage = 0;
	for( i = 0; i < numpage; i++)
	{ 			
		if(!gMSDC_Handle->mIsPresent) 
			return MS_ERR_CARD_NOT_PRESENT;		
		if(gMS.uc_pages != 0)
		{
			MS_API_ReadSinglePage(blkadrs, i, rx, NULL);
			rx  += MS_PAGE_SIZE/4;	
			(*readpage)++;				
		}
		else
		{
			kal_uint8 de[4];

			MS_TPC_SetRWAdrs(MS_OVERWRITE_REG,1,0,0);
			MS_TPC_ReadReg((kal_uint32*)de,1);
			if((de[0] & MS_OVFLG_PGST) == 0)
			{
				gMS.de_pages |= (1<<i);
			}
			
	 	   if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,0,0))!=MS_NOERROR)
				goto ERR_EXIT;
					   
			// read status0~1
			if((status = MS_TPC_ReadReg((kal_uint32*)data,2))!=MS_NOERROR)
				goto ERR_EXIT;
			// uncorrectable flash read error
			if(data[1] & (STA1_UCDT | STA1_UCEX | STA1_UCFG))
			{
				
				MS_TPC_SetCmd(CMD_BLOCK_END,&intreg);
				MS_API_Stop();
				MS_API_ClrBuffer();
				MSDC_CLR_FIFO();
				
				// uncorrectable error, update the page status to 1 (NG)
				MS_API_ReadExtraData( blkadrs, spage+i, (kal_uint32*) data);
				data[0] &= ~MS_OVFLG_PGST;
				data[0] |= MS_OVFLG_PGST1;
				MS_API_WriteExtraData( blkadrs, spage+i, (kal_uint32*) data);
				gMS.uc_pages |= (1<<i);
				rx  += MS_PAGE_SIZE/4;	
				(*readpage)++;				
				continue;
				//return MS_ERR_UC;
			}
			// check if reach last page
			if(!(data[0] & STA0_MB) && (intreg & INT_CED))
				lastpage = 1;
			// data is ready at pagebuffer
			if(data[0] & STA0_BF)
			{			   		
				// set auto command again
				// note the last page will not incur  INT
				if(!lastpage)
				   MS_SetAcmd(TPC_GET_INT,1);				
				// read data for pagebuffer
				if((status = MS_TPC_ReadPage(rx ))!=MS_NOERROR)
					goto ERR_EXIT;
					
				rx  += MS_PAGE_SIZE/4;	
				(*readpage)++;
				// read extra data

			}else
				return MS_ERRORS;			
			if(lastpage)
				return (*readpage == numpage)?MS_NOERROR:MS_LASTPAGE;
					
#ifndef MSDC_INT
			// wait cmd ready for ACMD(TPC_GET_INT)		
			if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
				goto ERR_EXIT;
#endif			
			// read fifo to get int register
			while(MSDC_IS_FIFO_EMPTY && gMSDC_Handle->mIsPresent);
			intreg = *(volatile kal_uint8*)MSDC_DAT;	
		}
									
	}	
	// reach the number of the numpage
	// send block end to stop the transmission (may be failed but don't care about it)
	MS_TPC_SetCmd(CMD_BLOCK_END,&intreg);
	if((status = MS_API_ClrBuffer())!=MS_NOERROR)
		goto ERR_EXIT;
	// clear the fifo
	MSDC_CLR_FIFO();	
	
	// if uncorrectable error, update the block status
	if(gMS.uc_pages != 0 && gMS.is_write)
	{

 		kal_uint32 i;
 		kal_uint16 *FreeTable, *LPTable, spareblk, lba;
 		kal_uint8  extra[4];
		// find a unused block from FreeTable, erase it and write updated info into it

		LPTable = gMS.pLPTbl;
		FreeTable = gMS.pFreeTbl;			
		
		MS_API_ReadExtraData(blkadrs, 0, (kal_uint32*) extra);
		extra[0] &= ~MS_OVFLG_BKST;
		extra[0] &= ~MS_OVFLG_UDST;
		MS_API_WriteExtraData(blkadrs, 0, (kal_uint32*) extra);
		extra[0] |= (MS_OVFLG_BKST|MS_OVFLG_UDST);
		MSDC_InvertN((kal_uint8*)&lba,&extra[2],2);	
		i = 0;
		while((FreeTable[i++] == 0xFFFF) && (i < MS_FREETABLE_SIZE));
		spareblk = FreeTable[i-1];
		status = MS_API_EraseBlock(spareblk);
		MS_API_WriteBlock(spareblk, rxbuffer, (kal_uint32*)extra, 0, numpage, readpage);
		// update the LPTable and FreeTable
		LPTable[MS_GetLPIndex(lba)] = spareblk;
		FreeTable[i-1] = 0xFFFF;
		gMS.FreeCnt--;
		for(i = 0; i< numpage ;i++)
		{
			if(gMS.uc_pages & (1<<i))
			{
				MS_API_ReadExtraData(spareblk, i, (kal_uint32*) extra);
				extra[0] &= ~MS_OVFLG_PGST;
				MS_API_WriteExtraData(spareblk, i, (kal_uint32*) extra);
			}
		}			
	}


	
	return MS_NOERROR;
	
ERR_EXIT:
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
	MS_API_ResetFlash();
	MS_API_ClrBuffer();
	MSDC_CLR_FIFO();
	return status;	
}

/*************************************************************************
* FUNCTION
*  MS_API_WriteSinglePage
*
* DESCRIPTION
*  Read single page with extra data from MS.
*
* PARAMETERS
*	1. blkadrs: physical block address.
*	2. page: page number of the block
*	3. txbuffer: of size of 512bytes
*	4. extra: buffer for the extra data of the page, of size of 4 bytes.
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	extra should not be NULL, make sure extra data contains reasonable data
*
*************************************************************************/
MS_STATUS MS_API_WriteSinglePage(kal_uint32 blkadrs,  kal_uint8 page, kal_uint32 *txbuffer, kal_uint32 extra)
{
	MS_STATUS status;
	kal_uint8 data[10],intreg,*ptr;

	if(gMS.is_wp)	
		return MS_ERR_WP;
	ptr = (kal_uint8*)extra;
	// set parameters
	data[0] = MS_SYS_DEFAULT;
	data[1] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[2] = (kal_uint8)(blkadrs >> 8);	// block address 1
	data[3] = (kal_uint8)blkadrs;			// block address 0
	data[4] = (kal_uint8)PAGE_MODE;			// access mode		
	data[5] = page;						// page number of the block
	data[6] = *ptr;						// overwriteflag
	data[7] = *(ptr+1);					// managementflag
	data[8] = *(ptr+2);					// logical address 1
	data[9]	= *(ptr+3);					// logical address 0
	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_SYS_REG,10))!=MS_NOERROR)
		goto ERR_EXIT;
	if((status = MS_TPC_WriteReg((kal_uint32*)data,10))!=MS_NOERROR)
		goto ERR_EXIT;
	// write page data into page buffer
	if((status = MS_TPC_WritePage(txbuffer))!=MS_NOERROR)
		goto ERR_EXIT;
	
	// send SET_CMD[BLOCK_WRITE] ~ page mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_WRITE,&intreg))!=MS_NOERROR)
		goto ERR_EXIT;
		
	// check int register
	if((intreg & INT_ERR))
		return MS_ERR_WRITEFAIL;
			
	return MS_NOERROR;	

ERR_EXIT:
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
	MS_API_ResetFlash();
	MS_API_ClrBuffer();
	return status;		
}

/*************************************************************************
* FUNCTION
*  MS_API_WriteBlock
*
* DESCRIPTION
*	1. write numpage pages form spage during a block or till the end of the block
*	2. make sure extra contains meaingful data.
*	3. the content of extra will be written to every modified page
*
* PARAMETERS
*		blkadrs:		physical block address
*		txbuffer:	buffer for the write data
*		extra:		buffer for the extra data
*		spage:		start of the writing page number
*		numpage:		number of the pages to write
*		writtenpage:	pages really be written
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	.
*
*************************************************************************/
MS_STATUS MS_API_WriteBlock(kal_uint32 blkadrs, kal_uint32* txbuffer, kal_uint32* extra, kal_uint8 spage, kal_uint8 numpage, kal_uint8 *writtenpage)
{
	MS_STATUS status;
	kal_uint8 data[12],intreg,*ptr,i;
   
	if(gMS.is_wp)	
		return MS_ERR_WP;
	if(blkadrs == 0 || blkadrs == 1)
		return MS_ERR_WP;
	ptr = (kal_uint8*)extra;
	// set parameters
	data[0] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[1] = (kal_uint8)(blkadrs >> 8);	// block address 1
	data[2] = (kal_uint8)blkadrs;			// block address 0
	data[3] = (kal_uint8)BLOCK_MODE;		// access mode		
	data[4] = spage;					// page number of the block
	data[5] = *ptr;						// overwriteflag
	data[6] = *(ptr+1);					// managementflag
	data[7] = *(ptr+2);					// logical address 1
	data[8] = *(ptr+3);					// logical address 0
	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,9))!=MS_NOERROR)
		goto ERR_EXIT;
	if((status = MS_TPC_WriteReg((kal_uint32*)data,9))!=MS_NOERROR)
		goto ERR_EXIT;
	// send SET_CMD[BLOCK_WRITE] ~ block mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_WRITE,&intreg))!=MS_NOERROR)
		goto ERR_EXIT;
				
	*writtenpage = 0;
	for(i = 0; i < numpage; i++)
	{		
		if(!gMSDC_Handle->mIsPresent) 
			return MS_ERR_CARD_NOT_PRESENT;		
		if((status = MS_TPC_ReadReg((kal_uint32*)data,2))!=MS_NOERROR)
			goto ERR_EXIT;					
		if(intreg & INT_ERR)
		{
			// uncorrectable flash read error
			if(data[1] & (STA1_UCDT | STA1_UCEX | STA1_UCFG))
			{
				// uncorrectable error, update the page status to 1
				MS_API_ReadExtraData( blkadrs, 0, (kal_uint32*) data);
				data[0] &= ~MS_OVFLG_BKST;
				data[0] &= ~MS_OVFLG_PGST;
				data[0] |= MS_OVFLG_PGST1;
				MS_API_WriteExtraData( blkadrs, spage+i, (kal_uint32*) data);			
				return MS_ERR_UC;
			}
		}
		
		if((data[0] & STA0_BE) && (intreg & INT_BREQ))
		{
			// set auto command
			MS_SetAcmd(TPC_GET_INT,1);	
			if((status = MS_TPC_WritePage(txbuffer))!=MS_NOERROR)
				goto ERR_EXIT;
			txbuffer += MS_PAGE_SIZE/sizeof(kal_uint32);
			(*writtenpage)++;	
		}
		
#ifndef MSDC_INT		
		if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
			goto ERR_EXIT;		
#endif						
		// read fifo to get int register
		while(MSDC_IS_FIFO_EMPTY && gMSDC_Handle->mIsPresent);
		intreg = *(volatile kal_uint8*)MSDC_DAT;			
	}
	// reach the number of page

	// check last page			
	if( intreg & INT_CED)
			return (*writtenpage == numpage)?MS_NOERROR:MS_LASTPAGE;
	else{
	   // send block end to stop the transmission
	 MS_TPC_SetCmd(CMD_BLOCK_END,&intreg);
	}
			
	// clear the fifo
	MSDC_CLR_FIFO();		
	return MS_NOERROR;		

ERR_EXIT:
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
	MS_API_ResetFlash();
	MS_API_ClrBuffer();
	return status;		
}

/*************************************************************************
* FUNCTION
*  MS_API_CopyPage
*
* DESCRIPTION
*	Copy pages from spage following numpage pages in the r_blkadrs to w_blkadrs
*
* PARAMETERS
*		w_blkadrs:	destination
*		r_blkadrs:	source
*		spage:		starting page
*		numpage:		number of pages to copy
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	
*
*************************************************************************/

MS_STATUS MS_API_CopyPage(kal_uint32 w_blkadrs, kal_uint32 r_blkadrs, kal_uint8 spage,kal_uint8 numpage)
{
	MS_STATUS status;
	kal_uint8 data[12],i,intreg;
	
	if(gMS.is_wp)
		return MS_ERR_WP;
	for(i = 0; i < numpage; i++)
	{	
		// set read parameters                                                  
		data[0] = (kal_uint8)(r_blkadrs >> 16);	// block address 2             	
		data[1] = (kal_uint8)(r_blkadrs >> 8);	// block address 1             	
		data[2] = (kal_uint8)r_blkadrs;			// block address 0             	
		data[3] = (kal_uint8)PAGE_MODE;			// access mode		           	
		data[4] = spage+i;					// page number of the block    		
	
		if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,5))!=MS_NOERROR)
			return status;
		if((status = MS_TPC_WriteReg((kal_uint32*)data,5))!=MS_NOERROR)
			return status;
	
		// send SET_CMD[BLOCK_READ] ~ page mode
		if((status = MS_TPC_SetCmd(CMD_BLOCK_READ,&intreg))!=MS_NOERROR)
			return status;
			
		// read status0~1
		if((status = MS_TPC_ReadReg((kal_uint32*)data,2))!=MS_NOERROR)
			return status;
			
		// check int register
		if(!(intreg & INT_CED))
			return MS_ERRORS;
			
		// uncorrectable errors	
		if((intreg & INT_ERR))
		{
			// chect the status1
			if(*((kal_uint8*)data +1) & (STA1_UCFG | STA1_UCEX | STA1_UCDT))
				return MS_ERR_UC;	
		}	
		// check MB and FB0 of status0
		if(data[0] & (STA0_MB | STA0_FB0))
			return MS_ERR_STABUSY;
	
			
		// data is ready at pagebuffer
		if(data[0] & STA0_BF)
		{		
			//read extra data
			if((status = MS_TPC_SetRWAdrs(MS_OVERWRITE_REG,MS_EXTRA_RSIZE,MS_BLKADRS2_REG,9))!=MS_NOERROR)
				return status;
			if((status = MS_TPC_ReadReg((kal_uint32*)((kal_uint8*)data+5),MS_EXTRA_RSIZE))!=MS_NOERROR)
				return status;		
					
			// set the parameter for page write
			data[0] = (kal_uint8)(w_blkadrs >> 16);	// block address 2             
			data[1] = (kal_uint8)(w_blkadrs >> 8);	// block address 1             
			data[2] = (kal_uint8)w_blkadrs;			// block address 0             
			data[3] = (kal_uint8)PAGE_MODE;			// access mode		           
			data[4] = spage+i;					// page number of the block    
			         		         		        		         
			if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,9))!=MS_NOERROR)     
				return status;                                                 
			if((status = MS_TPC_WriteReg((kal_uint32*)data,9))!=MS_NOERROR) 
				return status;                                        
			// send SET_CMD[BLOCK_WRITE] ~ page mode                    
			if((status = MS_TPC_SetCmd(CMD_BLOCK_WRITE,&intreg))!=MS_NOERROR) 
	        	return status;                                                  
	        	                                                                
	        // check int register                                               
	        if((intreg & INT_ERR))                             
				return MS_ERR_WRITEFAIL;                       
				                                               
			// short data state error                          
			if( !(intreg & INT_CED))                           
				return MS_ERRORS;                              		                                                                  
		}else               
			return MS_ERRORS;				
	}// end of for(i) 			                 	
	
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_API_EraseBlock
*
* DESCRIPTION
*	Erase the specific block with its extra data
*
* PARAMETERS
*	blkadrs: physical block address to be erased
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	After erased, the content of the block and extra data will filled with 0xff
*
*************************************************************************/
MS_STATUS MS_API_EraseBlock(kal_uint32 blkadrs)
{
	MS_STATUS status;
	kal_uint8 data[4],intreg;
	
	if(gMS.is_wp)	
		return MS_ERR_WP;
	if(blkadrs == 0 || blkadrs == 1)	
		return MS_ERR_WP;
	data[0] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[1] = (kal_uint8)(blkadrs >> 8);	// block address 1
	data[2] = (kal_uint8)blkadrs;			// block address 0
	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,3))!=MS_NOERROR)             
		return status;                                                         	
	if((status = MS_TPC_WriteReg((kal_uint32*)data,3))!=MS_NOERROR)
		return status;	
	if((status = MS_TPC_SetCmd(CMD_BLOCK_ERASE,&intreg))!=MS_NOERROR)
		return status;	
	if(intreg & INT_ERR)
		return	MS_ERR_ERASEFAIL;
		
	return MS_NOERROR;		                                                       	
}

/*************************************************************************
* FUNCTION
*  MS_API_ReadExtraData
*
* DESCRIPTION
*	read the extra data from the page of a block
*
* PARAMETERS
*	blkadrs: physical block address
*	page: page number of the block
*	extra: extra data 
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	
*************************************************************************/
MS_STATUS MS_API_ReadExtraData(kal_uint32 blkadrs, kal_uint8 page, kal_uint32 *extra)
{
	MS_STATUS status;
	kal_uint8 data[8],intreg;

	// set parameters
	data[0] = MS_SYS_DEFAULT;
	data[1] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[2] = (kal_uint8)(blkadrs >> 8);	// block address 1
	data[3] = (kal_uint8)blkadrs;			// block address 0
	data[4] = (kal_uint8)EXTRA_MODE;		// access mode		
	data[5] = page;						// page number of the block

	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_SYS_REG,6))!=MS_NOERROR)
		return status;
	if((status = MS_TPC_WriteReg((kal_uint32*)data,6))!=MS_NOERROR)
		return status;


	// send SET_CMD[BLOCK_READ] ~ extra mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_READ,&intreg))!=MS_NOERROR)
		return status;
		
	// read status0~1
	if((status = MS_TPC_ReadReg((kal_uint32*)data,2))!=MS_NOERROR)
		return status;	

	if((intreg & INT_ERR) && ( data[1] & (STA1_UCEX | STA1_UCFG)))
		return MS_ERRORS;

	// read extra data 	
	if(intreg & INT_CED)

	{
		if((status = MS_TPC_SetRWAdrs(MS_OVERWRITE_REG,MS_EXTRA_RSIZE,MS_BLKADRS2_REG,5))!=MS_NOERROR)
			return status;                                            
		if((status = MS_TPC_ReadReg(extra,MS_EXTRA_RSIZE))!=MS_NOERROR)
			return status;                                            				
	}

	else
		return MS_ERRORS;
	
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_API_WriteExtraData
*
* DESCRIPTION
*	write the extra data to the page of a block
*
* PARAMETERS
*	blkadrs: physical block address
*	page: page number of the block
*	extra: extra data 
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_WriteOWF(kal_uint32 blkadrs, kal_uint8 page, kal_uint8 owf)
{
	MS_STATUS status;
	kal_uint8 data[8],intreg;

	if(gMS.is_wp)
		return MS_ERR_WP;

	// set parameters
	data[0] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[1] = (kal_uint8)(blkadrs >> 8);	// block address 1
	data[2] = (kal_uint8)blkadrs;			// block address 0
	data[3] = (kal_uint8)OVERWRITE_MODE;		// access mode		
	data[4] = page;						// page number of the block
	data[5] = owf;						// overwriteflag
	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,6))!=MS_NOERROR)
		return status;
	if((status = MS_TPC_WriteReg((kal_uint32*)data,6))!=MS_NOERROR)
		return status;

	// send SET_CMD[BLOCK_READ] ~ page mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_WRITE,&intreg))!=MS_NOERROR)
		return status;
				
	if((intreg & INT_ERR) || !(intreg & INT_CED))
		return  MS_ERRORS;
	
	return MS_NOERROR;	
}

MS_STATUS MS_API_WriteExtraData(kal_uint32 blkadrs, kal_uint8 page, kal_uint32 *extra)
{
	MS_STATUS status;
	kal_uint8 data[9],intreg,*ptr;

	if(gMS.is_wp)
		return MS_ERR_WP;

	ptr = (kal_uint8*)extra;
	// set parameters
	data[0] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[1] = (kal_uint8)(blkadrs >> 8);	// block address 1
	data[2] = (kal_uint8)blkadrs;			// block address 0
	data[3] = (kal_uint8)EXTRA_MODE;		// access mode		
	data[4] = page;						// page number of the block
	data[5] = *ptr;						// overwriteflag
	data[6] = *(ptr+1);					// managementflag
	data[7] = *(ptr+2);					// logical address 1
	data[8]	= *(ptr+3);					// logical address 0
	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,9))!=MS_NOERROR)
		return status;
	if((status = MS_TPC_WriteReg((kal_uint32*)data,9))!=MS_NOERROR)
		return status;

	// send SET_CMD[BLOCK_READ] ~ page mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_WRITE,&intreg))!=MS_NOERROR)
		return status;
				
	if((intreg & INT_ERR) || !(intreg & INT_CED))
		return  MS_ERRORS;
	
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_API_OverwriteExtraData
*
* DESCRIPTION
*	Overwrite the OverwriteFlag of single page
*
* PARAMETERS
*	blkadrs: physical block address
*	page: page number of the block
*	overwrite: overwrite flag byte
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_OverwriteExtraData(kal_uint32 blkadrs, kal_uint8 page, kal_uint8 overwrite)
{
	MS_STATUS status;
	kal_uint8 data[6],intreg;

	if(gMS.is_wp)	
		return MS_ERR_WP;
	// set parameters
	data[0] = (kal_uint8)(blkadrs >> 16);	// block address 2
	data[1] = (kal_uint8)(blkadrs >> 8);	// block address 1
	data[2] = (kal_uint8)blkadrs;			// block address 0
	data[3] = (kal_uint8)OVERWRITE_MODE;	// access mode		
	data[4] = page;						// page number of the block
	data[5] = overwrite;				// overwriteflag

	if((status = MS_TPC_SetRWAdrs(MS_STA0_REG,2,MS_BLKADRS2_REG,6))!=MS_NOERROR)
		return status;
	if((status = MS_TPC_WriteReg((kal_uint32*)data,6))!=MS_NOERROR)
		return status;

	// send SET_CMD[BLOCK_READ] ~ page mode
	if((status = MS_TPC_SetCmd(CMD_BLOCK_WRITE,&intreg))!=MS_NOERROR)
		return status;
				
	if((intreg & INT_ERR) || !(intreg & INT_CED))
		return  MS_ERRORS;
	
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_API_ResetFlash
*
* DESCRIPTION
*	Flash Memory Controller is forced to reset.
*
* PARAMETERS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_ResetFlash()
{
	MS_STATUS status;

	// send the TPC (1 bytes data)
	MS_SendTPC(TPC_SET_CMD,1);
	// write 1 byte data into fifo
	while(MSDC_IS_FIFO_FULL && gMSDC_Handle->mIsPresent);
	*(volatile kal_uint8*)MSDC_DAT = CMD_RESET;
	// wait cmd ready or busy timeout
	if((status = MS_WaitCmdRdyOrTo())!=MS_NOERROR)
		return status;
	
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_API_Sleep
*
* DESCRIPTION
*	To suspend the oscillation for the internal clock of MS
*
* PARAMETERS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_Sleep()
{
	MS_STATUS status;
	kal_uint8 intreg;
	
	if((status = MS_TPC_SetCmd(CMD_SLEEP,&intreg))!=MS_NOERROR)
		return status;
	
	if(!(intreg & INT_CED))
		return MS_ERRORS;
		
	return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_API_ClrBuffer
*
* DESCRIPTION
*	To clear the data in PageBuffer
*
* PARAMETERS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_ClrBuffer()
{
	MS_STATUS status;
	kal_uint8 intreg;
	
	if((status = MS_TPC_SetCmd(CMD_CLEAR_BUF,&intreg))!=MS_NOERROR)
		return status;
	
	if(!(intreg & INT_CED))
		return MS_ERRORS;
		
	return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_API_Stop
*
* DESCRIPTION
*	To send a reset comand to Flash Memory chip
*
* PARAMETERS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_Stop()
{
	MS_STATUS status;
	kal_uint8 intreg;
	
	if((status = MS_TPC_SetCmd(CMD_FLASH_STOP,&intreg))!=MS_NOERROR)
		return status;
	
	if(!(intreg & INT_CED))
		return MS_ERRORS;
		
	return MS_NOERROR;	
}
/*************************************************************************
* FUNCTION
*  MS_CheckBlockSize
*
* DESCRIPTION
*	chekc if the block size, block number and effect blocks number confirm with the spec.
*
* PARAMETERS
*	size: block size(16K or 8K)
*	blk_no: total block numbers
*	eb: number of effective blocks
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MS_STATUS MS_CheckBlockSize(kal_uint32 size, kal_uint32 blk_no, kal_uint32 eb)
{
	if(blk_no == 0x200)
	{// 4M
		if(size != 0x2000)
			return MS_ERR_MEDIA;
		if(eb != 0x1F0)
			return MS_ERR_MEDIA;
		gMS.Size = MS_4M;
	}
	else if(blk_no == 0x400 && size == 0x2000)
	{// 8M
		if(eb != 0x3E0)
			return MS_ERR_MEDIA;		
		gMS.Size = MS_8M;
	}
	else if(blk_no == 0x400 && size == 0x4000)
	{// 16M
		if(eb != 0x3E0)
			return MS_ERR_MEDIA;		
		gMS.Size = MS_16M;
	}	
	else if(blk_no == 0x800)
	{// 32M
		if(size != 0x4000)
			return MS_ERR_MEDIA;
		if(eb != 0x7C0)
			return MS_ERR_MEDIA;				
		gMS.Size = MS_32M;	
	}
	else if(blk_no ==0x1000)
	{// 64M
		if(size != 0x4000)
			return MS_ERR_MEDIA;
		if(eb != 0xF80)
			return MS_ERR_MEDIA;				
		gMS.Size = MS_64M;		
	}
	else if(blk_no ==0x2000)
	{// 128M
		if(size != 0x4000)
			return MS_ERR_MEDIA;
		if(eb != 0x1F00)
			return MS_ERR_MEDIA;				
		gMS.Size = MS_128M;		
	}
	else
		return MS_ERR_MEDIA;

	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_AnalysisBB
*
* DESCRIPTION
*	Analysis boot block and store the corresponding information in the global variable.
*
* PARAMETERS
*	bootblk: buffer contains first page of the bootblock.
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	gMS
*
* NOTE
*	the entries of the boot block is coded in big endien  
*	the offset of corresponding is defined in the spec. of MS
*************************************************************************/
MS_STATUS MS_AnalysisBB(kal_uint32* bootblk)
{
	kal_uint8 *ptr,tmp[4];
	kal_uint8 bClass, bType, bFormat, bParallel;
	kal_uint32 eb; // effect blocks
	MS_STATUS status;

	ptr = (kal_uint8*)bootblk;
	MSDC_InvertN(tmp,(ptr+MS_BB_HEADER_SIZE+4),4);
	gMS.DisBlk = *(kal_uint32*)tmp/2 -1;
	bClass = *(ptr+MS_BB_HEADER_SIZE+MS_BB_SYSTEM);
	bParallel = *(ptr+0x1D3); 	// 0:serial, 1:serial & parallel
	if(bParallel)
	{
		gMS.Flags |= MS_FLAG_PARALLEL;
	}
	bFormat = *(ptr+0x1D6); 	// format type, must be 1 -> FAT
	bType = *(ptr+0x1D8);		// 0: memory stick, 1~3 ROM, others: reserved	
	//if(bClass != 1 || bFormat != 1)
	if(bFormat != 1)
	{
 		return MS_ERR_MEDIA;
	}
	MSDC_InvertN(tmp,(ptr+MS_BB_HEADER_SIZE+MS_BB_SYSTEM+2),2);
	gMS.BlockSize = *(kal_uint16*)tmp * 1024;
	MSDC_InvertN(tmp,(ptr+MS_BB_HEADER_SIZE+MS_BB_SYSTEM+4),2);
	gMS.NumBlock = *(kal_uint16*)tmp;
	MSDC_InvertN(tmp,(ptr+MS_BB_HEADER_SIZE+MS_BB_SYSTEM+6),2);	
	eb = *(kal_uint16*)tmp;
	status = MS_CheckBlockSize(gMS.BlockSize, gMS.NumBlock, eb);
	if(status != MS_NOERROR)
	{
 		return status;
	}
	MSDC_InvertN(tmp,(ptr+MS_BB_HEADER_SIZE+MS_BB_SYSTEM+32),2);
	gMS.Capacity = *(kal_uint16*)tmp;
	gMS.PagesPerBlk = gMS.BlockSize/MS_PAGE_SIZE;
 	
	return MS_NOERROR;
}

MS_STATUS MS_BootAreaProtection(void)
{
	MS_STATUS status;	
	kal_uint16 ladrs;
	kal_uint32 blk, last, i, fblk;
	kal_uint8 extra[MS_EXTRA_RSIZE], extra2[MS_EXTRA_RSIZE],*rx;

 	if(gMS.is_wp)
		return MS_NOERROR;

	fblk = 0;
	rx = (kal_uint8*)MSDC_Sector;
	if(gMS.BootBlks[1] == 0xFE) // if only one boot block the block before this is boot area
	{
		last = gMS.BootBlks[0];
		blk = 0;
	}
	else
	{
		blk = gMS.BootBlks[0]+1;
		last = gMS.BootBlks[1];
	}
	for( ; blk< last; blk++)
	{
		if((status = MS_API_ReadSinglePage(blk,0,(kal_uint32*)rx,(kal_uint32*)extra))!=MS_NOERROR)
			continue;		
		if(!MS_IS_BLK_OK(extra[OVERWRITE_FLAG]))
			continue;
		if(MS_IS_BOOT_BLK(extra[MANAGE_FLAG]))
			continue;
		MSDC_InvertN((kal_uint8*)&ladrs,extra+2,2); 
		if(ladrs != 0xFFFF)
		{	// copy to user area	
			kal_uint16 ladrs2;
			kal_uint32 pages;
			kal_bool update, same;

 			update = same = KAL_FALSE;			
			for(i= last+1; i<512; i++)
			{
				if((status = MS_API_ReadExtraData(i,0,(kal_uint32*)extra2)) != MS_NOERROR)
					continue;
				if(!MS_IS_BLK_OK(extra2[OVERWRITE_FLAG]))
					continue;
				MSDC_InvertN((kal_uint8*)&ladrs2,&extra2[2],2);								
				if(i == gMS.InfoBlk)
					continue;
				if(ladrs2 == ladrs)
				{
 					same = KAL_TRUE;
					if(MS_UPDATE_STATUS(extra[0]) != MS_UPDATE_STATUS(extra2[0]) &&
						MS_UPDATE_STATUS(extra2[0]) != 0)
					{	// erase the user area one
 						MS_API_EraseBlock(i);
						update = KAL_TRUE;
					}
					else // keep the user area one
					{
 						break;
					}
				}
				if(ladrs2 == 0xFFFF)
				{
					fblk = i;
					if(update)
						break;
				}
			}
			if(!same || update)
			{
				extern kal_uint8 MS_buffer[16*1024];
				kal_uint8 readpage;

 				// copy to fblk
				pages = (gMS.Size >= MS_16M)?32:16;
				status = MS_API_ReadBlock(blk,(kal_uint32*)MS_buffer, (kal_uint32 *)extra, 0, pages, &readpage);
				status = MS_API_WriteBlock(fblk,(kal_uint32*)MS_buffer, (kal_uint32 *)extra2, 0, pages, &readpage);
				MS_API_WriteExtraData(fblk, 0, (kal_uint32 *)extra);
				//MS_API_CopyPage(fblk,blk,0,pages);
			}
			// set to blk to NG status
			extra[OVERWRITE_FLAG] &= ~MS_OVFLG_BKST;
			if((status = MS_API_WriteExtraData(blk, 0, (kal_uint32 *)extra)) != MS_NOERROR)
				continue;							
		}
		
	}
	return MS_NOERROR;
}
/*************************************************************************
* FUNCTION
*  MS_API_ReadBootBlk
*
* DESCRIPTION
*	1. find the boot block(BB) and save it in gMS.BootBlock_no.
*	2. Get gMS.DisBlk, gMS.BlockSize, gMS.NumBlock, gMS.InfoBlk form BB
*
* PARAMETERS
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	gMS
*
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_ReadBootBlk(void)
{
	MS_STATUS status;
	kal_uint32 i,extra,bootcnt;
	kal_uint8 *ptr, *rx = (kal_uint8*)MSDC_Sector;

	bootcnt = 0;
	ptr = (kal_uint8 *)&extra;
	// check first 12 blocks to find the boot block
	for(i = 0; i < 12; i++)
	{
		if((status = MS_API_ReadSinglePage(i,0,(kal_uint32*)rx,&extra))!=MS_NOERROR)
			continue;		
		if(!MS_IS_BLK_OK(*ptr))
			continue;
		if(MS_IS_BOOT_BLK(*(ptr+1)))
		{	
			if((*rx == 0x00) && (*(rx+1) == 0x01) ) // check boot block id 0x0001
			{
				kal_uint32 j;
				kal_uint16 padrs;

 				gMS.BootBlks[bootcnt++] = i;
				if(bootcnt == 2)
					return MS_NOERROR;
				if((status = MS_AnalysisBB((kal_uint32*)rx)) != MS_NOERROR)
					return status;
				// get phy block number of information block(page 1)
				if((status = MS_API_ReadSinglePage(i,1,(kal_uint32*)rx,&extra))!=MS_NOERROR)
					return status;
				MSDC_InvertN((kal_uint8*)&padrs,rx,2);
				gMS.InfoBlk = padrs;
				// get initial disabled block
				for(j=0;j<gMS.DisBlk;j++)
				{
					MSDC_InvertN((kal_uint8*)&padrs,rx+2+j*2,2);
					if(padrs == 0xFFFF)
						return MS_ERR_MEDIA;
					ms_init_defect[j] = padrs;					
 				}
			}
			else
			{
 				gMS.Flags |= MS_FLAG_BAP;
			}		
		}
		else
		{
 			gMS.Flags |= MS_FLAG_BAP;
		}
	}
	if(i >= 12 && bootcnt == 0)
	{
 		return MS_ERR_NO_BOOT_BLK;
	}
	
	return MS_NOERROR;
}

/*************************************************************************
* FUNCTION
*  MS_API_GenLPTable
*
* DESCRIPTION
*	1. Generate a physical to logical translation table for a segment
*	2. Generate a free block table for a segment
*	3. After successful generation, save segment number.
*
* PARAMETERS
*	lptbl: a buffer used for storing generated L->P table.
*	ftbl: a buffer used for storing free block address.
*	seg: segmentation number
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	gLPtable
*  gMS.Seg
*
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_GenLPTable(kal_uint16 *lptbl,kal_uint16 *ftbl,kal_uint8 seg)
{
    kal_uint8 		extra[4],extra2[4];
    kal_uint16		*fptr, ladrs;
	 kal_uint32 	pblk, minpblk, free;
	 kal_int32		lindex;
    MS_STATUS		status;
	 kal_bool 		invalid;

    if( seg > (gMS.NumBlock/512 - 1)) 
        return MS_ERRORS;
  
    kal_mem_set(ftbl, 0xff, MS_FREETABLE_SIZE * sizeof(kal_uint16));
    kal_mem_set(lptbl,0xff, MS_LPTABLE_SIZE * sizeof(kal_uint16));
	minpblk = seg * 512;
	free = 0; 
	lindex = 0;
	// contruct the table of physicat -> logical table
    for(pblk = minpblk, fptr = ftbl; pblk < minpblk + 512; pblk++)
    {	 	
	 	invalid = KAL_FALSE;
		if(pblk == gMS.InfoBlk)
		{
 			 continue;
		}
		if(gMS.DisBlk)
		{
			kal_uint32 i = (gMS.DisBlk>=16)?(16):(gMS.DisBlk);

			while(i--)
			{
				if(pblk == 	ms_init_defect[i])
				{
 					invalid = KAL_TRUE;
					break;
				}
			}
			if(invalid) continue;	// skip initial disabled block		
		}
    	if((status=MS_API_ReadExtraData(pblk,0,(kal_uint32*)extra)) != MS_NOERROR)
    	{
			extra[OVERWRITE_FLAG] &= ~MS_OVFLG_BKST;
			MS_API_WriteExtraData(pblk, 0, (kal_uint32 *)extra);
			continue;
    	}	
		// The last segment and translation block ?
		if((seg == (gMS.NumBlock/512 -1)) && !(extra[1]&MS_MANAFLG_PLTB))
		{
			MS_API_EraseBlock(pblk);
		}				
		// block status = 0 or page statu != 11
		if(!(extra[0] & MS_OVFLG_BKST)
		|| !(((extra[0] & MS_OVFLG_PGST) == MS_OVFLG_PGST)||
		((extra[0] & MS_OVFLG_PGST) == 0))) 
		{
 		   continue;
		}
		// system bit of management flag 0: boot blocks
		if(!(extra[1] & MS_MANAFLG_SYS)) 
		{
 			continue;
		}
		// skip information block
		// store logical address 
		MSDC_InvertN((kal_uint8*)&ladrs,&extra[2],2);
		if(ladrs != 0xFFFF)
		{
			if(seg ==0)
			{
				if(ladrs > 493)
					invalid = KAL_TRUE;
				lindex = ladrs;			
			}
			else
			{
				lindex = ladrs-seg*496+2;
				if(lindex < 0 || lindex > 496)
					invalid = KAL_TRUE;
			}
		}
		
		if(invalid || ladrs == 0xffff )
		{
			MS_API_EraseBlock(pblk);
			if(free < 16)
			{
				*fptr++ = pblk;
				free++;
			}
			continue;
			
		}
		if(lptbl[lindex] == 0xffff)
		{
			lptbl[lindex] = pblk;
			continue;
		}
		// more than one pblk have the same logical address
		MS_API_ReadExtraData(lptbl[lindex], 0, (kal_uint32*)extra2);
		if((extra[0]&MS_OVFLG_UDST) == (extra2[0]&MS_OVFLG_UDST))
		{	// with the same update status
			MS_API_EraseBlock(lptbl[lindex]);
			*fptr++ = lptbl[lindex];
			continue;
		}
		// different update status
		if(!(extra[0]&MS_OVFLG_UDST))
		{
			MS_API_EraseBlock(lptbl[lindex]);
			*fptr = lptbl[lindex];
			lptbl[lindex] = pblk;
			continue;
		}
		MS_API_EraseBlock(pblk);
		*fptr = pblk;
    }

	 gMS.FreeCnt = free;
    gMS.Seg = seg;
    return MS_NOERROR;	
}

/*************************************************************************
* FUNCTION
*  MS_API_LogToPhy
*
* DESCRIPTION
*	Get physical address through logical address
*
* PARAMETERS
*	lptbl: logical to physical translation table
*	ladrs: logical address
*	padrs: physical address
*
* RETURNS
*	MS_STATUS
*
* GLOBALS AFFECTED
*	gMS.pLPTbl
*	gMS.pFreeTbl
*
* NOTE
*
*************************************************************************/
MS_STATUS MS_API_LogToPhy(kal_uint16* lptbl, kal_uint32 ladrs, kal_uint32* padrs)
{
	kal_uint8	seg;
	kal_uint16 min;

	seg = (ladrs < 494)?0:((ladrs-494)/496 + 1);
	min = (seg == 0)?0:(seg*496-2);		
	// check if ladrs is inside the segment of the lptbl 
	// reference the lptbl to get the physical address
	if(seg != gMS.Seg)
		MS_API_GenLPTable(gMS.pLPTbl,gMS.pFreeTbl,seg);	
	*padrs = *(lptbl+ladrs-min);

	return MS_NOERROR;
}

// Find discontiunous logical address and fix it.
MS_STATUS MS_API_CheckLogicalAdrsValid(void)
{
	MS_STATUS status;
	kal_int32 seg;
	kal_uint32 i,count,maxladrs;
	kal_uint16 *LPTable, *FreeTable, ladrs;
	kal_uint8 extra[4];

 	LPTable = gMS.pLPTbl;
	FreeTable = gMS.pFreeTbl;
	for(seg = gMS.NumBlock/BLOCKS_PER_SEGMENT-1; seg >= 0; seg--)
	{	
 		status = MS_API_GenLPTable(LPTable, FreeTable, seg);		
		if(status)
			return MS_ERR_LPTABLE;
		if((seg == gMS.NumBlock/BLOCKS_PER_SEGMENT-1 && gMS.FreeCnt < 2) ||
			 (gMS.FreeCnt <1))
		{
 			gMS.is_wp = KAL_TRUE;
			break;
		}
		if(seg == 0)
			maxladrs = 494;
		else
			maxladrs = 496;
		count = 0;
		for(i = 0; i < maxladrs; i++)
		{
			if(LPTable[i] == 0xFFFF)
			{				
				MS_API_ReadExtraData(FreeTable[gMS.FreeCnt-1], 0, (kal_uint32 *) extra);
				if(seg != 0)
					ladrs = i+seg*496-2;
				else
					ladrs = i;
				extra[2] = HIBYTE(ladrs);
				extra[3] = LOBYTE(ladrs);	
				MS_API_WriteExtraData(FreeTable[gMS.FreeCnt-1], 0, (kal_uint32*)extra);				
				LPTable[i] = FreeTable[gMS.FreeCnt-1];
				gMS.FreeCnt--;				
 				if((seg == gMS.NumBlock/BLOCKS_PER_SEGMENT-1 && gMS.FreeCnt < 2) ||
					 (gMS.FreeCnt <1))
				{
 					gMS.is_wp = KAL_TRUE;
					break;
				}	
			}			
		}				
	}	
	return MS_NOERROR;	
}


MS_STATUS MS_API_ReOrgnizeLogicalAdrs(void)
{
	kal_int32 seg;
	kal_uint16 ladrs;
	kal_uint32 i,count,maxladrs;
	kal_uint8 extra[4];

	ladrs = 0;
	for(seg = gMS.NumBlock/BLOCKS_PER_SEGMENT-1; seg >= 0; seg--)
	{	
		count = 512;
		while(count--)
		{
			MS_API_EraseBlock(seg*512+count);
		}
		
		if(seg == 0)
			maxladrs = 494;
		else
			maxladrs = 496;
		count = 0;
		for(i = 0; i < maxladrs; i++)
		{
			{				
				MS_API_ReadExtraData(i+seg*512, 0, (kal_uint32 *) extra);
				if(seg != 0)
					ladrs = i+seg*496-2;
				extra[2] = HIBYTE(ladrs);
				extra[3] = LOBYTE(ladrs);	
				MS_API_WriteExtraData(i+seg*512, 0, (kal_uint32*)extra);	
			}			
		}				
	}	
	return MS_NOERROR;	
}
void MS_API_SetBlockNG(kal_uint32 pblk)
{
	kal_uint8 extra[4];

	if(gMS.is_wp)
		return;
	MS_API_ReadExtraData(pblk, 0, (kal_uint32*) extra);
	extra[0] &= ~MS_OVFLG_BKST;
	MS_API_WriteExtraData(pblk, 0, (kal_uint32*) extra);
	
}

kal_uint16 MS_GetLPIndex(kal_uint32 ladrs)
{
	kal_uint8	seg;
	kal_uint16 min;

	seg = (ladrs < 494)?0:((ladrs-494)/496 + 1);
	min = (seg == 0)?0:(seg*496-2);		

	return ladrs - min;
	
}


#endif //  defined(__MSDC_MS__)
// the following code is for msdc testing
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
#ifdef MASS	
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
/* under construction !*/
/* under construction !*/
#endif			
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	//FPGA_DEBUG


