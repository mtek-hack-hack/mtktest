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
 *   sd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for SD/MMC 
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
#include "kal_release.h"
#include "app_buff_alloc.h"
#include "gpt_sw.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "intrCtrl.h"
#include "upll_ctrl.h"
#include "gpio_sw.h"
#include "init.h"

#ifdef DRV_LSD
#include "msdc_lsd.h"
#endif

#if defined(__MSDC_SD_MMC__)
//global variables
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;

extern void GPTI_BusyWait(kal_uint16 len);
extern kal_uint8 MSDC_GetIOCtrlParam(void);
extern kal_bool INT_USBBoot(void);

/*************************************************************************
* FUNCTION
*  SD_Acmd42
*
* DESCRIPTION
*	connect/disconnect the 50K Ohm pull-up resistor on CD/DAT3
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	
*
*************************************************************************/

// Get CID(CMD2)
SDC_CMD_STATUS SD_Acmd42(kal_bool connect)
{
	SDC_CMD_STATUS status;

	// send APP_CMD
	if((status = SD_Cmd55(gSD->mRCA))!=NO_ERROR)
		return status;
	// send cmd6
	if((status = SD_Send_Cmd(SDC_CMD_ACMD42,connect))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;	

	gSD->mCD_DAT3 = KAL_FALSE;	// pull-up resistor is disconnected for data trnasfer
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetMMC40_4bit_high_speed
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*	
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
SDC_CMD_STATUS SD_SetMMC40_bus_high_speed(void)
{
		kal_uint32 clock, hs;
	#ifdef DRV_MSDC_MT6225_SERIES
		/*use larger driving current. In mt6225 and mt6227D, IOCON is 32 bit register and DLT cannot be 0*/
		MSDC_WriteReg16(MSDC_IOCON,0x36);
		MSDC_SetIOCONRegDLT();
	#else
		MSDC_WriteReg16(MSDC_IOCON,0x1B);
	#endif

		if(SD_SetBlength(512)!=NO_ERROR)			
			goto err;
		
		// read the EXT_CSD
		if(SD_SendEXTCSD_MMC40(MSDC_Sector) != NO_ERROR)
			goto err;;

		/*calculate size*/
		if(MMC42_CARD == gMSDC_Handle->mMSDC_type){
			gSD->mCSD.capacity = (kal_uint64)gSD->mCSD.ext_csd->sec_count * 512;
		}
		
		// set high speed
		if(gSD->mCSD.ext_csd->card_type & HS_52M)
		{
			// should be 52000
			//clock = 52000;
                        clock = gMSDC_Handle->msdc_clock / 2;
			hs = 1;
			//MSDC_WriteReg32(MSDC_IOCON,0x010002FF);
			MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_CRED);;
			
		}
		else if(gSD->mCSD.ext_csd->card_type & HS_26M)
		{
			// should be 26000
			clock = 26000;
			hs = 1;
		}
		else
		{
			clock = 13000;
			hs = 0;
		}
		if(hs)
		{
			// select proper power class
			if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_POW_CLASS_INDEX,
				(gSD->mCSD.ext_csd->pwr_52_360&0xf) ,0) != NO_ERROR)
				goto err;
			
			// enable high speed (26M or 52M)
			if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_HIGH_SPPED_INDEX,
				EXT_CSD_ENABLE_HIGH_SPEED,0) != NO_ERROR)
				goto err;

			// latch data at falling edge to cover the card driving capability
			// MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_RED);			
		}
		
	#ifndef DRV_LSD
		gMSDC_Handle->msdc_clock = MSDC_CLOCK;
		MSDC_SetClock(clock);
	#else
		LSD_HostSetClock(LSD_SPEED_52M);
	#endif
	
	#ifdef DRV_MSDC_MT6225_SERIES
		/*change DLT and set cmd latch at rising edge*/
		MSDC_WriteReg16(MSDC_IOCON,0x8036);
		MSDC_SetIOCONRegDLT();
	#endif
		// select bus width
		#if defined(MMC40_USE_4BIT_BUS)
		// enable 4-bit bus width
		if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_BUS_WIDTH_INDEX,BIT_4_MMC40,0) != NO_ERROR)
			goto err;
		MSDC_SET_BIT32(SDC_CFG,SDC_CFG_MDLEN);
		gSD->bus_width = 4;		
		#elif defined(MMC40_USE_8BIT_BUS)
		// enable 8-bit bus width
		if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_BUS_WIDTH_INDEX,BIT_8_MMC40,0) != NO_ERROR)
			goto err;
		MSDC_SET_BIT32(SDC_CFG,SDC_CFG_MDLEN8);
		gSD->bus_width = 8;		
		#endif
					
		if(SD_SendEXTCSD_MMC40(MSDC_Sector) != NO_ERROR)
			goto err;;
				
		return NO_ERROR;
err:
		return ERR_MMC_BUS_HS_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_CheckSDorMMC
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*	
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
T_MSDC_CARD SD_CheckSDorMMC()
{
	SDC_CMD_STATUS status; 

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	SD_Cmd8();
#endif
	if((status = SD_Acmd41_SD())==NO_ERROR)
		return gMSDC_Handle->mMSDC_type;	// SD_CARD
	else if((status = SD_Cmd1_MMC())==NO_ERROR)
		return gMSDC_Handle->mMSDC_type;	// MMC_CARD

	return UNKNOWN_CARD;
}
/*************************************************************************
* FUNCTION
*  SD_SetDefault
*
* DESCRIPTION
*	set default values to gSD
*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_SetDefault(void)
{
	kal_mem_set(gSD,0,sizeof(T_SDC_HANDLE));
	gSD->mBKLength = 512;
	gSD->mRCA = 0;
	gSD->mInactive = KAL_FALSE;
	gSD->mState = IDLE_STA;
	gSD->bus_width = 1;
	gSD->mCD_DAT3 = KAL_TRUE;
}

void SD_Use24M_Clock(void)
{
#ifndef DRV_LSD
	if(gMSDC_Handle->mMSDC_type == SD_CARD || gMSDC_Handle->mMSDC_type == SD20_LCS_CARD
		|| gMSDC_Handle->mMSDC_type == SD20_HCS_CARD)
	{
		UPLL_Enable(UPLL_OWNER_MSDC);
		MSDC_SET_BIT32(MSDC_CFG, MSDC_CFG_CLKSRC);
		gMSDC_Handle->msdc_clock = MSDC_CLOCK_USB;
		MSDC_SetClock(MSDC_SD_OP_CLOCK);
		gSD->flags |= SD_FLAG_USE_USB_CLK;	
	}
#else
	LSD_HostSetClock(LSD_SPEED_52M);
#endif
}

void SD_Use13M_Clock(void)
{
#ifndef DRV_LSD
	MSDC_CLR_BIT32(MSDC_CFG, MSDC_CFG_CLKSRC);
	gMSDC_Handle->msdc_clock = MSDC_CLOCK;
	MSDC_SetClock(MSDC_OP_CLOCK);
	gSD->flags &= ~SD_FLAG_USE_USB_CLK;
#else
	LSD_HostSetClock(LSD_SPEED_52M);
#endif
}


/*************************************************************************
* FUNCTION
*  SD_Initialize
*
* DESCRIPTION
*	Initial SD controller and card
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
SDC_CMD_STATUS SD_Initialize(void)
{
	kal_uint32 cid[4],csd[4],scr[4];
	kal_uint16 rca, iocon;
	SDC_CMD_STATUS status;

	if(gMSDC_Handle->mIsInitialized == KAL_TRUE)
	{
		return NO_ERROR;
	}
	// reset the events
	kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
	// reset msdc
#ifndef DRV_LSD
	if(*(volatile kal_uint32*)MSDC_CFG & MSDC_CFG_RST)
#else
	ASSERT(LSD_Support());
	if(LSD_Reg32(MSDC_CFG) & MSDC_CFG_RST)
#endif
	{
		MSDC_CLR_BIT32(MSDC_CFG, MSDC_CFG_RST);
	}
	else
	{
		RESET_MSDC();
	}
	
	//#if defined(MT6225)
	#if defined(DRV_MSDC_MT6225_SERIES)
	MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_CRED);
	#endif
	
	// set the output driving capability from customization interface
	#if defined(__SIM_PLUS__)
	MSDC_WriteReg16(MSDC_IOCON,0x2DB);			
	#else
	iocon = *(volatile kal_uint16*)MSDC_IOCON;
	iocon &= ~(0xff);
	iocon |= MSDC_GetIOCtrlParam();	
	MSDC_WriteReg16(MSDC_IOCON,(kal_uint16)iocon);			
	#endif
	// set pull up the data and cmd 
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)2,MSDC_CFG_PRCFG0);
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)2,MSDC_CFG_PRCFG1);
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)2,MSDC_CFG_PRCFG2);	
	// set read timeout x5ms
	BitFieldWrite32((kal_uint32*)SDC_CFG,(kal_uint32)40,SDC_CFG_DTOC);
	//set clock of serial clcok for initialization
	#ifndef DRV_LSD
	MSDC_CLR_BIT32(MSDC_CFG, MSDC_CFG_CLKSRC);
	gMSDC_Handle->msdc_clock = MSDC_CLOCK;
	MSDC_SetClock(MSDC_INI_CLOCK);	
	#else
	LSD_HostSetClock(LSD_SPEED_INIT);
	#endif
	// disable 4-bit
	MSDC_CLR_BIT32(SDC_CFG,SDC_CFG_MDLEN);
	// initial global sturctures
	SD_SetDefault();
	
	#if defined(__SIM_PLUS__)
	// turn on the power of the MMC of the SIM+ 
	if(INT_USBBoot() == KAL_TRUE && current_card == SD_SIM)
	{
		static kal_bool is_first = KAL_TRUE;

		if(is_first)
		{
			is_first = KAL_FALSE;
			GPIO_WriteIO(1, GPIO_LDO_SWITCH);
			GPTI_BusyWait(300);
		}		
	}
	#endif
	
	#ifdef DRV_LSD
	LSD_Host74TCMDHigh();
	#endif
	// send the card to IDLE state
	if((status = SD_Reset())!=NO_ERROR)
	{
		goto err;
	}

	// and validate the OCR  (CMD0,CMD1 or ADMD41)
	if(SD_CheckSDorMMC() == UNKNOWN_CARD)
	{
		status = ERR_STATUS;
		goto err;
	}

	// get CID(CMD2)
	if((status = SD_GetCID(cid))!=NO_ERROR)
	{
		goto err;
	}
	// get or set RCA(CMD3)
	if((status = SD_ValidateRCA(&rca))!=NO_ERROR)
	{
		goto err;
	}
	// get CSD and analysis the CSD(CMD9)
	if((status = SD_GetCSD(gSD->mRCA,csd))!=NO_ERROR)
	{
		goto err;
	}		
	// Set driver stage register DSR to default value (0x0404)(CMD4)
	if(gSD->mCSD.dsr_imp)
		if((status = SD_SetDSR())!=NO_ERROR)
		{
			//dbg_print("6\r\n");
			goto err;
		}
	
#ifndef DRV_LSD
	#if !defined(__MSDC_NO_WRITE_PROTECT__)
	// check write proctect switch(WP at SDC_STA)
	#if defined(__SIM_PLUS__)
	if(current_card == SD_EXT)	
	#endif
	{
		if((*(volatile kal_uint16*)SDC_STA & SDC_STA_WP))
			gSD->mWPEnabled = KAL_TRUE;
	}
	#endif
#endif	
	// select the card (CMD7) ,maybe locked 
	status = SD_SelectCard(gSD->mRCA);
	if(status == CARD_IS_LOCKED)
		gSD->mIsLocked = KAL_TRUE;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD->flags & SD_FLAG_SD_TYPE_CARD)
	#else
	if(gMSDC_Handle->mMSDC_type == SD_CARD)
	#endif
	{		
		#if defined(MSDC_USE_USB_CLK)	&& !defined(__SIM_PLUS__)
		SD_Use24M_Clock();
		#else
		/*JRD SIM+ issue on 2007_03_08, JRD data line signal not stable, we can't use 24M even without SIM+ existence*/
		if((!MSDC_Blk[SD_SIM].mIsInitialized) && (MSDC_24M == MSDC_GetClockWithoutSIMPlus()))
			SD_Use24M_Clock();
		else
			SD_Use13M_Clock();		
		#endif
		if((status = SD_ReadSCR(scr))!=NO_ERROR)
		{
			goto err;
		}	
		#if defined(MSDC_SD_BITS4_BUS)
		if((status = SD_SetBusWidth(BIT_4W))!=NO_ERROR)
		{
			goto err;
		}
		#endif
		
		#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
		if((status = SD_Acmd42(KAL_FALSE))!=NO_ERROR)
		{
			goto err;
		}
		#endif
		
		if(gSD->flags & SD_FLAG_CMD6_SUPPORT)
		{
			status = SD_SelectHighSpeed_SD11();
			if(status == NO_ERROR)
			{
				dbg_print("SD_SelectHighSpeed_SD11 fail\r\n");
				gSD->flags |= SD_FLAG_HS_ENABLED;
				//1 NEED to Modify such as using 48M clock
				MSDC_CLR_BIT32(MSDC_CFG, MSDC_CFG_CLKSRC);
				gMSDC_Handle->msdc_clock = MSDC_CLOCK;
				MSDC_SetClock(26000);			
			}
		}
	}
	else
	{
		#if defined(MSDC_MMC40_SUPPORT)
		if((gMSDC_Handle->mMSDC_type == MMC_CARD || gMSDC_Handle->mMSDC_type == MMC42_CARD) && gSD->mCSD.spec_ver >= 4)
		{
			if(gMSDC_Handle->mMSDC_type == MMC_CARD)/*we don't need to change MMC42_CARD to MMC40_CARD*/
			gMSDC_Handle->mMSDC_type = MMC40_CARD;
			if((status = SD_SetMMC40_bus_high_speed())!= NO_ERROR)
				goto err;
		}	
		else
		#endif
		{
			SD_Use13M_Clock();
		}
	}

	// set block length (CMD16)
	status = SD_SetBlength(512);
err:	
	if(status != NO_ERROR)
	{
		kal_print("SD mount fail!");
		SD_SetDefault();
		gMSDC_Handle->mIsInitialized = KAL_FALSE;
	}
	else
	{
		kal_print("SD mount ok!");
		gMSDC_Handle->mIsInitialized = KAL_TRUE;
	}
	kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);

	return status	;
}

void SD_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len)
{
	int i;
	for(i=0; i<len; i++)
		*(dest+len-1-i) = *(src+i);
	
}
/*************************************************************************
* FUNCTION
*  power2
*
* DESCRIPTION
*	Calculate the power of 2
*
* PARAMETERS
*	num: 
*
* RETURNS
*  2^num
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 power2(kal_uint32 num)
{
   return 1 << num;
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCSD
*
* DESCRIPTION
*	Analysis Card Specific Data and store in the member of gSD
*
* PARAMETERS
*	csd: input csd for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCSD(kal_uint32* csd)
{	
	kal_uint8 *ptr;
	kal_uint32 c_mult,c_size;
	
	ptr = (kal_uint8*)csd;
	c_mult = c_size = 0;
	// these offsets refer to the spec. of SD and MMC 
	GetBitFieldN((kal_uint8*)&gSD->mCSD.csd_ver, ptr, 126,2);	
	GetBitFieldN((kal_uint8*)&gSD->mCSD.tacc,ptr,112,8);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.nsac,ptr,104,8);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.tran_speed,ptr,96,8);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.ccc,ptr,84,12);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_len,ptr,80,4);
	gSD->mCSD.r_blk_len = power2(gSD->mCSD.r_blk_len);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_part,ptr,79,1);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_misali,ptr,78,1);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_misali,ptr,77,1);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.dsr_imp,ptr,76,1);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_part,ptr,21,1);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_len,ptr,22,4);
	gSD->mCSD.w_blk_len = power2(gSD->mCSD.w_blk_len);
	GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_grp_enable,ptr,31,1);
	// there are some difference of CSD between SD and MMC
	if(gMSDC_Handle->mMSDC_type == MMC_CARD || gMSDC_Handle->mMSDC_type == MMC42_CARD)
	{
		GetBitFieldN((kal_uint8*)&gSD->mCSD.spec_ver, ptr, 122,4);		
		GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_sec_size_mmc,ptr,42,5);
		gSD->mCSD.erase_sec_size_mmc = (gSD->mCSD.erase_sec_size_mmc+1)*gSD->mCSD.w_blk_len; 
		GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_grp_size_mmc,ptr,37,5);
		gSD->mCSD.erase_grp_size_mmc = (gSD->mCSD.erase_grp_size_mmc+1)*gSD->mCSD.erase_sec_size_mmc;
		GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_grp_size_mmc,ptr,32,5);		
		gSD->mCSD.wp_grp_size_mmc = (gSD->mCSD.wp_grp_size_mmc + 1)*gSD->mCSD.erase_grp_size_mmc;	
	}
	else // SD_CARD
	{
		GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_sec_size_sd,ptr,39,7);
		gSD->mCSD.erase_sec_size_sd += 1;
		GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_prg_size_sd,ptr,32,7);
		gSD->mCSD.wp_prg_size_sd = (gSD->mCSD.wp_prg_size_sd+1) * gSD->mCSD.erase_sec_size_sd;
		GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_blk_en_sd,ptr,46,1);
	}
	
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gMSDC_Handle->mMSDC_type == SD20_HCS_CARD && gSD->mCSD.csd_ver >= SD_CSD_VER_20)
	{
		GetBitFieldN((kal_uint8*)&c_size,ptr,48,22);
		gSD->mBKNum = (c_size+1);
		gSD->mCSD.capacity = (kal_uint64)gSD->mBKNum*512*1024;
	}
	else
	#endif
	{
		GetBitFieldN((kal_uint8*)&c_mult,ptr,47,3);
		c_mult = power2(c_mult+2);
		GetBitFieldN((kal_uint8*)&c_size,ptr,62,12);
		gSD->mBKNum = (c_size+1)*c_mult;
		gSD->mCSD.capacity = (c_size+1)*c_mult*gSD->mCSD.r_blk_len;
	}
	
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCID
*
* DESCRIPTION
*	Analysis Card Identificaton and store in the member of gSD
*
* PARAMETERS
*	cid: input of card ID for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCID(kal_uint32* cid)
{
	kal_uint8	i;
	kal_uint8* pcid;
	pcid = (kal_uint8*)cid;

	if(gMSDC_Handle->mMSDC_type == MMC_CARD || MMC42_CARD == gMSDC_Handle->mMSDC_type)
	{
		GetBitFieldN((kal_uint8*)&gSD->mCID.year,pcid,8,4);
		gSD->mCID.year += 1997;
		GetBitFieldN((kal_uint8*)&gSD->mCID.month,pcid,12,4);
		GetBitFieldN((kal_uint8*)&gSD->mCID.psn,pcid,16,32);
		GetBitFieldN((kal_uint8*)&gSD->mCID.prv,pcid,48,8);
		for(i=0;i<6;i++)
			gSD->mCID.pnm[i] = *(pcid+7+i);
		GetBitFieldN((kal_uint8*)&gSD->mCID.oid,pcid,104,16);
		GetBitFieldN((kal_uint8*)&gSD->mCID.mid,pcid,120,8);
		
		// special case handling
		{
			kal_uint8 pnm[] = {0xFF,0xFF,0xFF,0xFF,0x36,0x31};
			if(gSD->mCID.mid == 6 && gSD->mCID.oid == 0 &&
				!kal_mem_cmp(gSD->mCID.pnm,pnm,6))
			{
				gSD->flags |= SD_FLAG_MMC_MRSW_FAIL;
			}
		}
	}
	else // SD_CARD
	{
		gSD->mCID.mid = *(pcid+15);
		gSD->mCID.oid = *(pcid+13) + 256*(*(pcid+14));
		for(i=0;i<5;i++)
			gSD->mCID.pnm[i] = *(pcid+8+i);
		gSD->mCID.prv = *(pcid+7);
		//gSD->mCID.psn = *(kal_uint32*)(pcid+3);
		gSD->mCID.psn = (*(kal_uint32*)(pcid+4)<<8)|*(pcid+3);
		gSD->mCID.month = (kal_uint8)GET_BIT(*(pcid+1),0,BIT_MASK_4);
		gSD->mCID.year = GET_BIT(*(pcid+1),4,BIT_MASK_4)+16*GET_BIT(*(pcid+2),0,BIT_MASK_4) + 2000;
	}
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisSCR
*
* DESCRIPTION
*	Analysis SD Card Configuration Register and store in the member of gSD
*
* PARAMETERS
*	scr: input of scr for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	Only for SD card.
*
*************************************************************************/
void SD_AnalysisSCR(kal_uint32* scr)
{
	kal_uint8 *pscr;

	pscr = (kal_uint8*)scr;
	gSD->mSCR.spec_ver = (kal_uint8)GET_BIT(*(pscr),0,BIT_MASK_4);
	if(gSD->mSCR.spec_ver > SD_SPEC_101)
		gSD->flags |= SD_FLAG_CMD6_SUPPORT;
	gSD->mSCR.dat_after_erase = (kal_uint8)GET_BIT(*(pscr+1),7,BIT_MASK_1);
	gSD->mSCR.security = (kal_uint8)GET_BIT(*(pscr+1),4,BIT_MASK_3);
	gSD->mSCR.bus_width = (kal_uint8)GET_BIT(*(pscr+1),0,BIT_MASK_4);
}

/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo
*
* DESCRIPTION
*	Wait until command ready or timeout
*
* PARAMETERS
*	
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitCmdRdyOrTo(void)
{

	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
#ifdef MSDC_USE_INT	
	{
	kal_uint32 	flags = 0;
	kal_uint16 sdc_cmdsta = 0;
	
	if(!gMSDC_Handle->mIsPresent)
		return ERR_CARD_NOT_PRESENT;	
	kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDCMDIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);		
	MSDC_STOP_TIMER();
	
	sdc_cmdsta = *(volatile kal_uint16*)SDC_CMDSTA;  
	gMSDC_Handle->cmd_sta = sdc_cmdsta;
	if(sdc_cmdsta & SDC_CMDSTA_CMDTO)            
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:cmd timeout");
		return ERR_CMD_TIMEOUT;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)   
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:cmd crc");
		return ERR_CMD_RSPCRCERR;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_CMDRDY)      
		return NO_ERROR;                                     	
	}
#else		
	{
	volatile kal_uint16 sdc_cmdsta;
	kal_uint32 t1;

	t1 = drv_get_current_time();
#ifndef DRV_LSD
	while(!(sdc_cmdsta = *(volatile kal_uint16*)SDC_CMDSTA)
#else
	while(!(sdc_cmdsta = LSD_Reg32(SDC_CMDSTA))
#endif
		&& MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
			gMSDC_Handle->is_timeout = KAL_TRUE;
	}
	MSDC_STOP_TIMER();
	MSDC_CLR_INT();
	gMSDC_Handle->cmd_sta = sdc_cmdsta;
	if(sdc_cmdsta & SDC_CMDSTA_CMDTO)            
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:cmd timeout");
		return ERR_CMD_TIMEOUT;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)   
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:cmd crc");
		return ERR_CMD_RSPCRCERR;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_CMDRDY)      
		return NO_ERROR;                                     	
	}
	if(gMSDC_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
#endif
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_WaitDatRdyOrTo
*
* DESCRIPTION
*	Wait until data ready or timeout
*
* PARAMETERS
*	
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitDatRdyOrTo(void)
{
	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
	
#ifdef MSDC_USE_INT	
	{
	kal_uint16 sdc_datsta = 0;	
	kal_uint32 	flags = 0;
	
	if(!gMSDC_Handle->mIsPresent)
		return ERR_CARD_NOT_PRESENT;		
	kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDDATIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);
	MSDC_STOP_TIMER();
	sdc_datsta = *(volatile kal_uint16*)SDC_DATSTA;    
	gMSDC_Handle->dat_sta = sdc_datsta;
	if(sdc_datsta & SDC_DATSTA_DATTO)              
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:dat timeout");
		return ERR_DAT_TIMEOUT;                    
	}
	else if(sdc_datsta & SDC_DATSTA_DATCRCERR)     
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:dat crc");
		return ERR_DAT_CRCERR;                     
	}
	else if(sdc_datsta & SDC_DATSTA_BLKDONE)       
		return NO_ERROR;                                     
   }                                	
#else
	{
	volatile kal_uint16 sdc_datsta;	
	kal_uint32 t1;

	t1 = drv_get_current_time();
#ifndef DRV_LSD
	while(!(sdc_datsta = *(volatile kal_uint16*)SDC_DATSTA)
#else
	while(!(sdc_datsta = LSD_Reg32(SDC_DATSTA))
#endif
		&& MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
			gMSDC_Handle->is_timeout = KAL_TRUE;		
	};
	MSDC_STOP_TIMER();
	MSDC_CLR_INT();
	gMSDC_Handle->dat_sta = sdc_datsta;
	if(sdc_datsta & SDC_DATSTA_DATTO)              
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:dat timeout");
		return ERR_DAT_TIMEOUT;                    
	}
	else if(sdc_datsta & SDC_DATSTA_DATCRCERR)     
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:dat crc");
		return ERR_DAT_CRCERR;                     
	}
	else if(sdc_datsta & SDC_DATSTA_BLKDONE)       
		return NO_ERROR;                                     
	}
	if(gMSDC_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
#endif
	
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_WaitCardNotBusy
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

SDC_CMD_STATUS SD_WaitCardNotBusy(void)
{
	kal_uint32 t1;

	t1 = drv_get_current_time();
	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
#ifdef MSDC_USE_INT
	{
	kal_uint32 	flags = 0;
	if(!gMSDC_Handle->mIsPresent)
		return;
	kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);				
	}
#else	
	{
	while(SD_IS_R1B_BUSY && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
			gMSDC_Handle->is_timeout = KAL_TRUE;
	};
	MSDC_CLR_INT();
	MSDC_STOP_TIMER();
	}
#endif

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_CheckStatus
*
* DESCRIPTION
*	Check command status
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
SDC_CMD_STATUS SD_CheckStatus()
{
	kal_uint32 status;

	MSDC_ReadReg32(SDC_RESP0,&status);
	if((status & SDC_CSTA_MASK)==0 )
		return NO_ERROR;
	if(status &SDC_CARD_IS_LOCKED)
		return CARD_IS_LOCKED;

	return ERR_STATUS;
}

/*************************************************************************
* FUNCTION
*  SD_Send_Cmd
*
* DESCRIPTION
*	to launch the command packet to the card
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	1. Check if controller is available  before launch any commands 
*	2. Maybe add check if card is busy (R1b)
*************************************************************************/
SDC_CMD_STATUS SD_Send_Cmd(kal_uint32 cmd, kal_uint32 arg)
{
	SDC_CMD_STATUS status;
	kal_uint32 t1;

	t1 = drv_get_current_time();
	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
	// check the controller is ready (stop transaction will fail)
	if(cmd != SDC_CMD_CMD12)		
	{
		while(SD_IS_SDC_BUSY && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;
		}
	}
	else
	{
		while(SD_IS_CMD_BUSY && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;
		}
	}
	MSDC_STOP_TIMER();
	if(gMSDC_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	MSDC_CLR_INT();
	// fill out the argument
	MSDC_WriteReg32(SDC_ARG,arg);
	// launch the command
	MSDC_WriteReg32(SDC_CMD,cmd);
	if((status = SD_WaitCmdRdyOrTo())!=NO_ERROR)
		return status; 

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_Reset
*
* DESCRIPTION
*	reset all cards to idle state
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Reset(void)
{
	SDC_CMD_STATUS status;

	status = SD_Send_Cmd(SDC_CMD_CMD0,SDC_NO_ARG);
	gSD->mState = IDLE_STA;

	return status;
}

/*************************************************************************
* FUNCTION
*  SD_Cmd55
*
* DESCRIPTION
*	APP_CMD: inidicate to the card that the next command is an application specified command
*			rather than a standard command
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Cmd55(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD55,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;
	//check APP_CMD bit in status register
	MSDC_ReadReg32(SDC_RESP0,&status);
	if(!(status & R1_APP_CMD_5))
		return ERR_APPCMD_FAILED;

	return NO_ERROR;	
}
/*************************************************************************
* FUNCTION
*  SD_Cmd8
*
* DESCRIPTION
*	1. Sends SD Memory Card interface conditions for support larger than 2G cards
*	2. check if the card is compliant to SD2.0 or higher
*	3. only performed while at IDLE state.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD->mIsCMD8
*
*************************************************************************/
void SD_Cmd8(void)
{
	kal_uint32 resp;

	if(SD_Send_Cmd(SDC_CMD_CMD8,SDC_CMD8_ARG)!=NO_ERROR)
	{
		dbg_print("SD_Cmd8 fail \r\n");
		SD_Reset();
		gSD->mCMD8Resp = SD_CMD8_RESP_NORESP;
		return;
	}
	MSDC_ReadReg32(SDC_RESP0,&resp);
	if(resp == SDC_CMD8_ARG)
		gSD->mCMD8Resp = SD_CMD8_RESP_VALID;
	else
		gSD->mCMD8Resp = SD_CMD8_RESP_INVALID;
}

/*************************************************************************
* FUNCTION
*  SD_Cmd1_MMC
*
* DESCRIPTION
*	 asks all cards in idle state to send their OCR in the response on the CMD line
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for MMC
*
*************************************************************************/
SDC_CMD_STATUS SD_Cmd1_MMC(void)
{
	SDC_CMD_STATUS status;
	kal_uint32 _ocr, ocr_i, t1, t2;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD->mCMD8Resp == SD_CMD8_RESP_INVALID)
		return ERR_CMD8_INVALID;
	ocr_i = (SDC_OCR_DEFAULT|MMC_HIGH_DESITY_CHECK_BIT);
	#else
	ocr_i = SDC_OCR_DEFAULT;
	#endif

	if(gMSDC_Handle->is_init_timeout == KAL_TRUE)
		return ERR_R3_OCR_BUSY;
	t2 = drv_get_current_time();
	do{
		t1 = drv_get_current_time();
		MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
		while((MSDC_IS_BUSY)
			&& MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;
		};
		MSDC_STOP_TIMER();		
		if(gMSDC_Handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;		
		MSDC_WriteReg32(SDC_ARG,ocr_i);
		MSDC_WriteReg32(SDC_CMD,SDC_CMD_CMD1);
		if((status = SD_WaitCmdRdyOrTo())  != NO_ERROR)
		{
			return status;
		}		
		MSDC_ReadReg32(SDC_RESP0, &_ocr);
		if((_ocr & SDC_OCR_DEFAULT) == 0)
			return ERR_OCR_NOT_SUPPORT;
		if(!gMSDC_Handle->mIsPresent)
			return MSDC_CARD_NOT_PRESENT;
		
		if(!(_ocr&SDC_OCR_BUSY))		
		{
			if(drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
			{
				gMSDC_Handle->is_init_timeout = KAL_TRUE;			
				break;
			}					
			if((kal_query_systemInit() == KAL_TRUE) 
#ifdef  __TST_WRITE_TO_FILE_ONLY__ 			/*error recording: considering error recording additionally*/
				|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
			)
				GPTI_BusyWait(30);
			else
				kal_sleep_task(7);
				
		}
		else
			break;		
	}while(1);

	if(gMSDC_Handle->is_init_timeout)
		return ERR_CMD_TIMEOUT;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if((_ocr & MMC_HIGH_DESITY_CHECK_MSK) == MMC_HIGH_DESITY_CHECK_BIT)
	{
		gSD->flags |= SD_FLAG_HCS_SUPPORT;
		gMSDC_Handle->mMSDC_type = MMC42_CARD;
		kal_print("MMC4.2 or higher");
	}
	else
	#endif
	gMSDC_Handle->mMSDC_type = MMC_CARD;
	gSD->mInactive = KAL_FALSE;
	gSD->mSDC_ocr = _ocr;
	gSD->mState = READY_STA;
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_Acmd41_SD
*
* DESCRIPTION
*	asks all cards in idle state to send their OCR in the response on the CMD line
*	OCR: Operation Condition Register
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_Acmd41_SD(void)
{

	SDC_CMD_STATUS		status;
	kal_uint32			_ocr = 0, ocr_i, t1, t2;
	
#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)	
	if(gSD->mCMD8Resp == SD_CMD8_RESP_NORESP)
		ocr_i = SDC_OCR_DEFAULT;
	else if(gSD->mCMD8Resp == SD_CMD8_RESP_VALID)
		ocr_i = (SDC_OCR_DEFAULT|SD_ACMD41_HCS);
	else if(gSD->mCMD8Resp == SD_CMD8_RESP_INVALID)
		return ERR_CMD8_INVALID;	
#else	
	ocr_i = SDC_OCR_DEFAULT;
#endif	

	gMSDC_Handle->is_init_timeout = KAL_FALSE;
	t2 = drv_get_current_time();
	do{
		t1 = drv_get_current_time();		
		MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
		while((MSDC_IS_BUSY)
			&& MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;			
		};
		MSDC_STOP_TIMER();
		if(gMSDC_Handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;		
		status=SD_Cmd55(SDC_RCA_DEFAULT);
		if(status != NO_ERROR)
		{
			return status;
		}
		MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
		t1 = drv_get_current_time();
		while((MSDC_IS_BUSY)
			&& MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;			
		};
		MSDC_STOP_TIMER();
		if(gMSDC_Handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;		
		MSDC_WriteReg32(SDC_ARG,ocr_i);
		MSDC_WriteReg32(SDC_CMD,SDC_CMD_CMD41_SD);
		if((status = SD_WaitCmdRdyOrTo())  != NO_ERROR)
		{
			return status;
		}		
		MSDC_ReadReg32(SDC_RESP0, &_ocr);
		if((_ocr & SDC_OCR_DEFAULT) == 0)
			return ERR_OCR_NOT_SUPPORT;
		if(!gMSDC_Handle->mIsPresent)
			return ERR_CARD_NOT_PRESENT;	
		if(!(_ocr&SDC_OCR_BUSY))		
		{
			if(drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
			{
				gMSDC_Handle->is_init_timeout = KAL_TRUE;			
				break;
			}					
			if((kal_query_systemInit() == KAL_TRUE) 
#ifdef  __TST_WRITE_TO_FILE_ONLY__ 			/*error recording: considering error recording additionally*/
				|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
			)
				GPTI_BusyWait(30);
			else
				kal_sleep_task(7);
		}
		else
			break;		
	}
	while(1);

	if(gMSDC_Handle->is_init_timeout)
		return ERR_R3_OCR_BUSY;

	gSD->mInactive = KAL_FALSE;
	gSD->mSDC_ocr = _ocr;
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	gSD->flags |= SD_FLAG_SD_TYPE_CARD;	
	if(_ocr & SD_ACMD41_HCS)
	{
		gSD->flags |= SD_FLAG_HCS_SUPPORT;
		gMSDC_Handle->mMSDC_type = SD20_HCS_CARD;
		kal_print("SD2.0 or higher");
	}
	else if(gSD->mCMD8Resp == SD_CMD8_RESP_VALID)
		gMSDC_Handle->mMSDC_type = SD20_LCS_CARD;
	else
	#endif
		gMSDC_Handle->mMSDC_type = SD_CARD;
	gSD->mState = READY_STA;

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetCID
*
* DESCRIPTION
*	Read Card Identification.
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	
*
*************************************************************************/

// Get CID(CMD2)
SDC_CMD_STATUS SD_GetCID(kal_uint32 Cid[4])
{
	int i;
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD2,SDC_NO_ARG))!=NO_ERROR)
		return status;
	//read R2
	for(i=0;i<4;i++)
		MSDC_ReadReg32((SDC_RESP0+i*sizeof(kal_uint32)), &Cid[i]);
	SD_AnalysisCID(Cid);
	gSD->mState = IDENT_STA;
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_ValidateRCA
*
* DESCRIPTION
*	assing or read RCA
*
* PARAMETERS
*	pRca: used for input or output RCA
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	RCA is assinged to MMC card fixed to SDC_RCA_MMC(1)
*
*************************************************************************/

// assign or read RCA
SDC_CMD_STATUS SD_ValidateRCA(kal_uint16* pRca)
{
	SDC_CMD_STATUS status;
	kal_uint32 resp;
	kal_uint8  state;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD->flags & SD_FLAG_SD_TYPE_CARD )
	#else
	if(gMSDC_Handle->mMSDC_type == SD_CARD)
	#endif
	{
		//read RCA form card
		if((status = SD_Send_Cmd(SDC_CMD_CMD3_SD,SDC_NO_ARG))!=NO_ERROR)
			return status;
		//read R6
		MSDC_ReadReg32(SDC_RESP0, &resp);
		*pRca = resp >>  16;
		gSD->mRCA =*pRca;
		
	}
	else
	{
		//assign RCA to card
		if((status = SD_Send_Cmd(SDC_CMD_CMD3_MMC,(kal_uint32)SDC_RCA_MMC<<16))!=NO_ERROR)
			return status;

		//read R1
		MSDC_ReadReg32(SDC_RESP0, &resp);
		SD_GetStatus(SDC_RCA_MMC,&resp);
		state = 0;
		GetBitFieldN((kal_uint8*)&state,(kal_uint8*)&resp,9,4);
		if(STBY_STA != state)
			return ERR_RCA_FAIL;		
		*pRca = gSD->mRCA = SDC_RCA_MMC;			
	}

	gSD->mState = STBY_STA;
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetDSR
*
* DESCRIPTION
*	set default value to the DSR
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	SDC_DSR_DEFAULT(0x404)
*
*************************************************************************/
SDC_CMD_STATUS SD_SetDSR(void)
{
	return SD_Send_Cmd(SDC_CMD_CMD4,(kal_uint32)SDC_DSR_DEFAULT<<16);
}

/*************************************************************************
* FUNCTION
*  SD_SelectCard
*
* DESCRIPTION
*	select/deselect card
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SelectCard(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD7,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
		
	//read R1b
	if((status = SD_WaitCardNotBusy())!=NO_ERROR)	
		return status;
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetCSD
*
* DESCRIPTION
*	Get CSD from addressed card
*
* PARAMETERS
*	rca: relative card address
*	Csd: used for containing read CSD
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_GetCSD(kal_uint16 rca, kal_uint32 Csd[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD_Send_Cmd(SDC_CMD_CMD9,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
	// read R2
	for(i=0;i<4;i++)
	{
	#ifndef DRV_LSD
		MSDC_ReadReg32((volatile kal_uint32 *)(SDC_RESP0+i*4), &Csd[i]);
	#else
		MSDC_ReadReg32(SDC_RESP0+i, &Csd[i]);
	#endif
	}
	// analysis CSD...
	SD_AnalysisCSD(Csd);

	return NO_ERROR;
}

// addressed send CID
SDC_CMD_STATUS SD_GetAddressedCID(kal_uint16 rca, kal_uint32 Cid[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD_Send_Cmd(SDC_CMD_CMD10,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;

	// read R2
	for(i=0;i<4;i++)
	{
	#ifndef DRV_LSD
		MSDC_ReadReg32((volatile kal_uint32 *)(SDC_RESP0+i*4), &Cid[i]);
	#else
		MSDC_ReadReg32(SDC_RESP0+i, &Cid[i]);
	#endif
	}
	return NO_ERROR;
}


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
*	definition of SD_STOP_SLOW is used for some erroneous card
*************************************************************************/
SDC_CMD_STATUS SD_StopTrans(kal_bool isTx)
{
	SDC_CMD_STATUS status;
	kal_uint32 retry = 0;

	while(retry < 30)
	{
#ifdef LSD_STOP_IMMEDIATLY
		extern kal_bool LSD_stoped;
		if(LSD_stoped)
			break;
#endif
		if((status = SD_Send_Cmd(SDC_CMD_CMD12,SDC_NO_ARG))!=NO_ERROR)
		{
			retry ++;
		}
		else
		{
			break;
		}
	}
	if(retry >= 30)
	{
		return status;
	}
	if(isTx)
		SD_WaitCardNotBusy();
	

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
*  SD_GetStatus
*
* DESCRIPTION
*	addressed send status
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
SDC_CMD_STATUS SD_GetStatus(kal_uint16 rca, kal_uint32* resp)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD13,(kal_uint32)rca <<16))!=NO_ERROR)
		return status;

	MSDC_ReadReg32(SDC_RESP0,resp);

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetBlength
*
* DESCRIPTION
*	set block length
*
* PARAMETERS
*	BKLength: block length u want to set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD->mBKLength
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBlength(kal_uint32 BKLength)
{
	SDC_CMD_STATUS status;

	// maximal value of block length is 2048
	if(BKLength > SDC_MAX_BKLENGTH)
		return ERR_INVALID_BKLENGTH;
	if(!gSD->mCSD.r_blk_part && BKLength < gSD->mCSD.max_r_blk_len )
		return ERR_INVALID_BKLENGTH;		
	if((status = SD_Send_Cmd(SDC_CMD_CMD16,BKLength))!=NO_ERROR)
		return status;
	//read R1
	status = SD_CheckStatus();		
	// 2. configure the controller
	gSD->mBKLength = BKLength;
	BitFieldWrite32((kal_uint32*)SDC_CFG,BKLength,SDC_CFG_BLKLEN);

	return NO_ERROR;
}


/*************************************************************************
* FUNCTION
*  SD_ReadSingleBlock
*
* DESCRIPTION
*	1. read a single block form data_adrs of card to the rxbuffer
*	2. the block length is set by set block length
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	the size of rxbuffer should be 4*n (n : integer)
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
	kal_uint32 count;
	SDC_CMD_STATUS status;

	
	EnableMSDC_DMA();
	count = MSDC_SD_BLOCK_SIZE;
	MSDC_DMATransferFirst((kal_uint32)rxbuffer,count,KAL_FALSE);
	#ifdef DRV_LSD
	LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
	#endif
	if((status = SD_Send_Cmd(SDC_CMD_CMD17,data_adrs))!=NO_ERROR)	
		goto ERR_Exit;
	if((status = SD_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;
	status = MSDC_DMATransferFinal();
	if(status != NO_ERROR)
	{
		goto ERR_Exit;			
	}		
	if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
		goto ERR_Exit;
	
	DisableMSDC_DMA();
	MSDC_CLR_FIFO();
	
	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		
		#ifdef MSDC_USE_INT
		kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
		#endif
		DisableMSDC_DMA();
		RESET_MSDC();

		// SD_StopTrans(KAL_FALSE);		
		SD_GetStatus(gSD->mRCA,(kal_uint32*)&tmp);
		MSDC_ReadReg32(SDC_DATSTA,&tmp);
		MSDC_CLR_FIFO();		
		return status;
	}
	
}

/*************************************************************************
* FUNCTION
*  SD_ReadMultiBlock
*
* DESCRIPTION
*	read num of blocks into rxbuffer
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*	num: number of blocks to read
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num)
{
	SDC_CMD_STATUS status;
	kal_uint32 j, count;
	#ifndef MSDC_DMA
	kal_uint32 i;	
	#endif

	EnableMSDC_DMA();
	count = MSDC_SD_BLOCK_SIZE;	
	MSDC_DMATransferFirst((kal_uint32)rxbuffer,count*num,KAL_FALSE);	
	#ifndef DRV_LSD
	if((status = SD_Send_Cmd(SDC_CMD_CMD18,data_adrs))!=NO_ERROR)
	#else
	LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
	if((status = SD_Send_Cmd(SDC_CMD_CMD18|(num<<20) ,data_adrs))!=NO_ERROR)
	#endif
		goto ERR_Exit;
	if((status = SD_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;	
	count = MSDC_SD_BLOCK_SIZE;	
	status = MSDC_DMATransferFinal();
	if(status != NO_ERROR)
			goto ERR_Exit;	

	if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
		goto ERR_Exit;
	
	
	MSDC_CLR_INT();
	DisableMSDC_DMA();

	if(gSD->flags & SD_FLAG_MMC_MRSW_FAIL)
	{
		kal_uint32 delay = 200;
		while(delay--);		
	}
	if((status = SD_StopTrans(KAL_FALSE))!=NO_ERROR)
	{
		//if((data_adrs/gSD->mBKLength + j) < gSD->mBKNum)			
			goto ERR_Exit;		
	}
	MSDC_CLR_FIFO();			
	return NO_ERROR;
	
ERR_Exit:

	#ifdef MSDC_USE_INT	
	kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
	#endif
	DisableMSDC_DMA();
	RESET_MSDC();		
	SD_StopTrans(KAL_FALSE);		
	SD_GetStatus(gSD->mRCA,(kal_uint32*)&j);
	MSDC_ReadReg32(SDC_DATSTA,&j);
	MSDC_CLR_FIFO();
	return status;
	
}

/*************************************************************************
* FUNCTION
*  SD_WriteSingleBlock
*
* DESCRIPTION
*	write a single block
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;
	kal_uint32 *ptr;	
#if defined(MT6225)
	kal_bool is_aligned;
	ECO_VERSION eco;
	eco = INT_ecoVersion();	
#endif

	if(gSD->mWPEnabled)
		return ERR_WRITE_PROTECT;
	EnableMSDC_DMA();
	count = MSDC_SD_BLOCK_SIZE;
	
	#if defined(MT6225)
	if(eco <= ECO_E3)
	{
		is_aligned = ((kal_uint32)txbuffer%4 == 0); 
		if(is_aligned)
		{
			ptr = txbuffer;
		}
		else
		{
			kal_mem_cpy(MSDC_Sector, txbuffer, 512);
			ptr = MSDC_Sector;
		}
	}
	else
	{
		ptr = txbuffer;
	}
	#else
	ptr = txbuffer;
	#endif
	
	EnableMSDC_DMA();
	count = MSDC_SD_BLOCK_SIZE;	
	MSDC_DMATransferFirst((kal_uint32)ptr,count,KAL_TRUE);	
	#ifdef DRV_LSD
	LSD_HostSetBuffer((kal_uint8 *)txbuffer);
	#endif
	if((status = SD_Send_Cmd(SDC_CMD_CMD24,address))!=NO_ERROR)
		goto ERR_Exit;
	if((status = SD_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;
	status = MSDC_DMATransferFinal();
	if(status != NO_ERROR)
		goto ERR_Exit;	
	// wait R1b interrupt because cmd24 is configured as R1b response but cmd25 needn't
	if((status = SD_WaitCardNotBusy())!=NO_ERROR)	
		 goto ERR_Exit;	
	DisableMSDC_DMA();
	if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
		goto ERR_Exit;
	

	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		
		#ifdef MSDC_USE_INT	
		kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
		#endif
		DisableMSDC_DMA();
		RESET_MSDC();
		//SD_StopTrans(KAL_TRUE);		
		SD_GetStatus(gSD->mRCA,(kal_uint32*)&tmp);
		MSDC_ReadReg32(SDC_DATSTA,&tmp);
		return status;
	}
	
}

/*************************************************************************
* FUNCTION
*	SD_WriteMultiBlock
*
* DESCRIPTION
*	write num blocks starting at address
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*	num: number of blocks to write
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;
	kal_uint32 *ptr;
	#if defined(MT6225)
	kal_bool is_aligned, dma_issue;
	ECO_VERSION eco;
	eco = INT_ecoVersion();	
	if(eco <= ECO_E3) 
		dma_issue = KAL_TRUE;
	#endif
		
	if(gSD->mWPEnabled)
		return ERR_WRITE_PROTECT;
	EnableMSDC_DMA();	
	count = MSDC_SD_BLOCK_SIZE;	
	#if defined(MT6225)
	if(dma_issue)
	{
		is_aligned = ((kal_uint32)txbuffer%4 == 0); 
		if(is_aligned)
		{
			MSDC_DMATransferFirst((kal_uint32)txbuffer,count*num,KAL_TRUE);	
		}
		else
		{
			kal_mem_cpy(MSDC_Sector, txbuffer, 512);
			ptr = txbuffer;
			MSDC_DMATransferFirst((kal_uint32)MSDC_Sector,count,KAL_TRUE);
		}
	}
	else
	{
		MSDC_DMATransferFirst((kal_uint32)txbuffer,count*num,KAL_TRUE);	
	}
	#elif defined(MSDC_MULTI_BLOCK_WRITE)
	MSDC_DMATransferFirst((kal_uint32)txbuffer,count*num,KAL_TRUE);
	#else
	ptr = txbuffer;
	MSDC_DMATransferFirst((kal_uint32)ptr,count,KAL_TRUE);
	#endif
#ifndef DRV_LSD
	if((status = SD_Send_Cmd(SDC_CMD_CMD25,address))!=NO_ERROR)
#else
	LSD_HostSetBuffer((kal_uint8 *)txbuffer);
	if((status = SD_Send_Cmd(SDC_CMD_CMD25|(num<<20) ,address))!=NO_ERROR)
#endif
		goto ERR_Exit;
	if((status = SD_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;
	   
	#if defined(MT6225)
	if(dma_issue)
	{
		if(is_aligned)
		{
			status = MSDC_DMATransferFinal();
			if(status != NO_ERROR)
				goto ERR_Exit;
			if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
				goto ERR_Exit;		
		}
		else
		{
			kal_uint32 j;
			
			for(j=0;j<num;j++)
			{
				if(gMSDC_Handle->mIsPresent  == KAL_FALSE)
				{
					status = ERR_CARD_NOT_PRESENT;
					goto ERR_Exit;		
				}
				if(j!=0)
				{
					kal_mem_cpy(MSDC_Sector, ptr, 512);
					MSDC_DMATransferFirst((kal_uint32)MSDC_Sector,count,KAL_TRUE);
				}
				status = MSDC_DMATransferFinal();
				ptr += MSDC_SD_BLOCK_SIZE; 
				if(status != NO_ERROR)
					goto ERR_Exit;		
				if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)	
					goto ERR_Exit;
			}	
		}	
	}
	else
	{
		status = MSDC_DMATransferFinal();
		if(status != NO_ERROR)
			goto ERR_Exit;
		if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
			goto ERR_Exit;		
	}
	#elif defined(MSDC_MULTI_BLOCK_WRITE)
		status = MSDC_DMATransferFinal();
		if(status != NO_ERROR)
			goto ERR_Exit;
		if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
			goto ERR_Exit;			
	#else // not MT6225
	{
		kal_uint32 j;
		
		for(j=0;j<num;j++)
		{
			if(gMSDC_Handle->mIsPresent  == KAL_FALSE)
			{
				status = ERR_CARD_NOT_PRESENT;
				goto ERR_Exit;		
			}
			if(j!=0)
			{
				MSDC_DMATransferFirst((kal_uint32)ptr,count,KAL_TRUE);
			}
			status = MSDC_DMATransferFinal();
			ptr += MSDC_SD_BLOCK_SIZE; 
			if(status != NO_ERROR)
				goto ERR_Exit;		
			if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)	
				goto ERR_Exit;
		}
	
	}	
	#endif // MT6225

	DisableMSDC_DMA();
	if((status = SD_StopTrans(KAL_TRUE))!=NO_ERROR)
		goto ERR_Exit;
	
	MSDC_CLR_INT();
	#ifdef MSDC_USE_INT	
	kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
	#endif
	
	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		
	#ifdef MSDC_USE_INT	
	kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
	#endif	
		DisableMSDC_DMA();
		RESET_MSDC();
		SD_StopTrans(KAL_TRUE);		
		SD_GetStatus(gSD->mRCA,(kal_uint32*)&tmp);
		MSDC_ReadReg32(SDC_DATSTA,&tmp);
		return status;
	}
	
}
/*************************************************************************
* FUNCTION
*	SD_SetBusWidth
*
* DESCRIPTION
*	ACMD6: set the data width 00 for 1 bit, 10 for 4 bits
*
* PARAMETERS
*	width: indicate the bus width
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Not every card support 4-bits bus
*	only for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBusWidth(SD_BITWIDTH width)
{
	SDC_CMD_STATUS status;

	// check if card support 4 bits bus
	if((width == BIT_4W) && !(gSD->mSCR.bus_width&0x04))
		return ERR_NOT_SUPPORT_4BITS;
	// send APP_CMD
	if((status = SD_Cmd55(gSD->mRCA))!=NO_ERROR)
		return status;
	// send cmd6
	if((status = SD_Send_Cmd(SDC_CMD_ACMD6,width))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;	
	// set the controler MDLEN to enalbe 4bits bus width
	MSDC_SET_BIT32(SDC_CFG,SDC_CFG_MDLEN);
	gSD->bus_width = 4;
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_ReadSCR
*
* DESCRIPTION
*	ACMD51: read the SD Configuration Register(8bytes block read)
*
* PARAMETERS
*	scr: used for store SCR
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Make sure the size of SCR is 8 bytes 
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadSCR(kal_uint32* scr)
{
	SDC_CMD_STATUS status;
	kal_uint32 blklen,i, t1;

	ASSERT((kal_uint32)scr % 4  == 0);
	// save the original block length 
	blklen = gSD->mBKLength;
	// set block length(MSDC_CFG)
	if((status = SD_SetBlength(8))!=NO_ERROR)
		return status;
	// send APP_CMD
	if((status = SD_Cmd55(gSD->mRCA))!=NO_ERROR)
		return status;
	// send command
	if((status = SD_Send_Cmd(SDC_CMD_ACMD51,SDC_NO_ARG))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;	
	// read data(8bytes)	
#ifndef DRV_LSD
	// failed to use DMA with burst mode
	t1 = drv_get_current_time();
	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
	for(i=0;i<2;)
	{	
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
			gMSDC_Handle->is_timeout = KAL_TRUE;		
		if(!gMSDC_Handle->mIsPresent)
			return ERR_CARD_NOT_PRESENT;
		if(gMSDC_Handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;
		if(!MSDC_IS_FIFO_EMPTY)
		{
			*(kal_uint32*)(scr+i) = *(volatile kal_uint32*)MSDC_DAT;
			i++;
		}
	}
#else
	LSD_readFIFO(scr ,2);
	
#endif
	MSDC_STOP_TIMER();
	// analysis scr
	SD_AnalysisSCR(scr);
	// clean EVENT_SDDATIRQ
	#ifdef MSDC_USE_INT	
	kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
	#endif
	MSDC_CLR_FIFO();
	return NO_ERROR;
	
}

/*************************************************************************
* FUNCTION
*	SD_SetPreEraseBlk
*
* DESCRIPTION
*	ACMD23: set the number of write blocksto be pre-erased before writing
*	used for faster multiple Block Write
*
* PARAMETERS
*	num: used for storing number of blocks during multi-block operation
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetPreEraseBlk(kal_uint32 num)
{
	SDC_CMD_STATUS status;

	//[22:0] number of blocks 
	num &= 0x003FFF;
	// send APP_CMD
	if((status = SD_Cmd55(gSD->mRCA))!=NO_ERROR)
		return status;
	// send CMD23
	if((status = SD_Send_Cmd(SDC_CMD_ACMD23,num))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;	

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_EraseCmdClass
*
* DESCRIPTION
*	groups of erase commands including CMD32 ~CMD38
*
* PARAMETERS
*	cmd: indicate which command to execute
*	address: starting address wiht write protection
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	CMD34~CMD37 are only for MMC
*
*************************************************************************/
SDC_CMD_STATUS SD_EraseCmdClass(kal_uint32 cmd ,kal_uint32 address)
{
	SDC_CMD_STATUS status;

	if(cmd != SDC_CMD_CMD38)
	{
		if((status = SD_Send_Cmd(cmd,address))!=NO_ERROR)
			return status;
	}
	else if((status = SD_Send_Cmd(cmd,SDC_NO_ARG))!=NO_ERROR)
			return status;

	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;

	if(cmd == SDC_CMD_CMD38)
	{
		SD_WaitCardNotBusy();
		do{	
		SD_GetStatus(gSD->mRCA,(kal_uint32*)&status);
		if(gMSDC_Handle->mIsPresent == KAL_FALSE)
			break;
			}while(CurState(status)!=  TRAN_STA);
	}
	
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*	SD_Switch_MMC40
*
* DESCRIPTION
*	CMD6: set the command set or write to the EXT_CSD (for MMC4.0)
*
* PARAMETERS
*	access: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set 
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_MMC40(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;
	
	arg = (access<<24)|(index<<16)|(value<<8)|set;
	// send command
	if((status = SD_Send_Cmd(SDC_CMD_CMD6_MMC40,arg))!=NO_ERROR)
		return status;
#ifdef DRV_LSD
	//read R1b
	if((status = SD_WaitCardNotBusy())!=NO_ERROR)	
		return status;
#endif
	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_SendEXTCSD_MMC40
*
* DESCRIPTION
*	CMD8: read the content of EXT_CSD register
*
* PARAMETERS
*	kal: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set 
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SendEXTCSD_MMC40(kal_uint32* rxbuffer)
{
	SDC_CMD_STATUS status;
	kal_bool retry_4bit = KAL_FALSE;

start:
	// read the block	of 512 bytes (make sure the rxbuffer is 4 byte aligned)
	EnableMSDC_DMA();
	MSDC_DMATransferFirst((kal_uint32)rxbuffer,128,KAL_FALSE);		
#ifdef DRV_LSD
	LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
#endif
	if((status = SD_Send_Cmd(SDC_CMD_CMD8_MMC40,SDC_NO_ARG))!=NO_ERROR)
		goto ERR_Exit;
	//read R1
	if((status = SD_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;		
	// read the block	of 512 bytes (make sure the rxbuffer is 4 byte aligned)
	status = MSDC_DMATransferFinal();	
	if(status != NO_ERROR)
		goto ERR_Exit;			
	if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
		goto ERR_Exit;
	
	DisableMSDC_DMA();
	MSDC_CLR_FIFO();	
	gSD->mCSD.ext_csd = (T_EXT_CSD_MMC40 *)rxbuffer;
	return NO_ERROR;	
	
ERR_Exit:

	if(retry_4bit == KAL_FALSE)
	{
		retry_4bit = KAL_TRUE;
		MSDC_SET_BIT32(SDC_CFG,SDC_CFG_MDLEN);
		gSD->bus_width = 4;
		goto start;
	}
	MSDC_CLR_BIT32(SDC_CFG,SDC_CFG_MDLEN);
	gSD->bus_width = 1;
	DisableMSDC_DMA();
	MSDC_CLR_FIFO();	
	RESET_MSDC();

	return status;
}

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	CMD6: switch command to query and select the specific functions. (SD1.1 or later)
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_SD11(kal_uint32 arg, T_SWITCH_STATUS* info)
{
	SDC_CMD_STATUS status = NO_ERROR;
	
	BitFieldWrite32((kal_uint32*)SDC_CFG,SD_CMD6_RESP_LEN,SDC_CFG_BLKLEN);	
	EnableMSDC_DMA();
	MSDC_DMATransferFirst((kal_uint32)info,(SD_CMD6_RESP_LEN>>2),KAL_FALSE);	
	if((status = SD_Send_Cmd(SDC_CMD_CMD6_SD11,arg))!=NO_ERROR)
		goto exit;
	if((status = SD_CheckStatus())!=NO_ERROR)
		goto exit;
	status = MSDC_DMATransferFinal();	
	
exit:	
	DisableMSDC_DMA();	
	return status;
}

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	Enable the high speed interface to support up to 50M Hz clock 
*
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SelectHighSpeed_SD11(void)
{
	SDC_CMD_STATUS status;
	T_SWITCH_STATUS *p = (T_SWITCH_STATUS*)MSDC_Sector;
	
	if((status = SD_Switch_SD11(SD_CMD6_QUERY_HIGH_SPEED, p))!=NO_ERROR)
		return status;
	if(p->max_current == 0)
		return ERR_SD_HS_FAIL;
	if((p->group1_info & (1 << SD_FUNC_HIGH_SPEED)) && 
		(p->group1_result == SD_FUNC_HIGH_SPEED))
	{
		if((status = SD_Switch_SD11(SD_CMD6_SELECT_HIGH_SPEED, p))!=NO_ERROR)
				return status;
		if(p->max_current == 0)
			return ERR_SD_HS_FAIL;
		if(p->group1_result == SD_FUNC_HIGH_SPEED)
			gSD->flags |= SD_FLAG_HS_SUPPORT;
	}	
	else
		return ERR_SD_HS_FAIL;


	return NO_ERROR;
}

SDC_CMD_STATUS SD_GoInactive(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD15,(kal_uint32)rca <<16))!= NO_ERROR)
		return status;

	return NO_ERROR;
}

SDC_CMD_STATUS SD_ReadStream_MMC(kal_uint32 address, kal_uint32* rxbuffer, kal_uint32 bytes)
{
	SDC_CMD_STATUS status;
	kal_uint32 i,count;

	MSDC_CLR_FIFO();
	count = (bytes%4)?(bytes/4+1):(bytes/4);
#ifdef MSDC_DMA
	EnableMSDC_DMA();
	MSDC_DMATransferFirst((kal_uint32)rxbuffer,count,KAL_FALSE);
#endif
	//launch stream read command
	if((status = SD_Send_Cmd(SDC_CMD_CMD11_MMC,address)) != NO_ERROR)
	{
		goto ERR_Exit;
	}
	//read R1
	if((status = SD_CheckStatus())!= NO_ERROR)
	{		
		SD_WaitDatRdyOrTo();
		goto ERR_Exit;
	}
	

#ifdef MSDC_DMA
	status = MSDC_DMATransferFinal();
	if(status != NO_ERROR)
	{
		goto ERR_Exit;			
	}		
#else		
	//size assumed to be multiple of 4
	for(i=0;i<count;)
	{
		//check fifo is not empty
		if(!MSDC_IS_FIFO_EMPTY)
		{
			*(rxbuffer+i) = *(volatile kal_uint32*)MSDC_DAT;
			i++;
		}
	}
#endif
	DisableMSDC_DMA();
	SD_StopTrans(KAL_FALSE);
	MSDC_CLR_FIFO();
	return NO_ERROR;

ERR_Exit:
	{
		kal_uint32 tmp;
		
	#ifdef MSDC_USE_INT
		kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
	#endif
		DisableMSDC_DMA();
		RESET_MSDC();

		SD_StopTrans(KAL_FALSE);		
		SD_GetStatus(gSD->mRCA,(kal_uint32*)&tmp);
		MSDC_ReadReg32(SDC_DATSTA,&tmp);
		MSDC_CLR_FIFO();		
		return status;
	}
	 
}


// write data stream from card only for MMC
SDC_CMD_STATUS SD_WriteStream_MMC(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 bytes)
{
	SDC_CMD_STATUS status;
	kal_uint32 i,count;

	if(!gSD->mCSD.w_blk_part && (address + bytes)%512 != 0)
		return ERR_ERRORS;		
	
		MSDC_CLR_FIFO();
		count = (bytes%4)?(bytes/4+1):(bytes/4);
#ifdef MSDC_DMA
		EnableMSDC_DMA();
		MSDC_DMATransferFirst((kal_uint32)txbuffer,count,KAL_TRUE);
#endif

 	if((status = SD_Send_Cmd(SDC_CMD_CMD20_MMC,address))!= NO_ERROR)
	{
		goto ERR_Exit;
 	}	
	if((status = SD_CheckStatus())!= NO_ERROR)
	{
		goto ERR_Exit;
 	}
 #ifdef MSDC_DMA
	 status = MSDC_DMATransferFinal();
	 if(status != NO_ERROR)
	 {
		 goto ERR_Exit;		 
	 } 	 
#else		
	for(i=0;i<count;)
	{
		
		if(!MSDC_IS_FIFO_FULL)
		{
			*(volatile uint32*)MSDC_DAT = *(txbuffer+i);
			i++;
		}
		// check data ready (512 bytes)
		if((i%128) == 0)
			SD_WaitCardNotBusy();
	}
#endif
	DisableMSDC_DMA();
	SD_StopTrans(KAL_TRUE);
	MSDC_CLR_FIFO();
	return NO_ERROR;

ERR_Exit:
	{
		kal_uint32 tmp;
		
	#ifdef MSDC_USE_INT
		kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
	#endif
		DisableMSDC_DMA();
		RESET_MSDC();

		SD_StopTrans(KAL_TRUE);		
		SD_GetStatus(gSD->mRCA,(kal_uint32*)&tmp);
		MSDC_ReadReg32(SDC_DATSTA,&tmp);
		MSDC_CLR_FIFO();		
		return status;
	}
}

//program CSD, transfer CSD through data line
SDC_CMD_STATUS SD_ProgramCSD(kal_uint32 Csd[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD_Send_Cmd(SDC_CMD_CMD27,0))!= NO_ERROR)
		return status;

	//read R1
	if((status = SD_CheckStatus())!= NO_ERROR)
	{
		SD_WaitDatRdyOrTo();
		return status;
	}
	//clear fifo 
	MSDC_CLR_FIFO();

	//send CSD 128 bits = 4x32
	for(i=0;i<4;i++)
		*(volatile kal_uint32*)MSDC_DAT = Csd[i];

	//wait until crc status token received
	if((status = SD_WaitDatRdyOrTo())!= NO_ERROR)
		return status;

	//wait until programming is finished
	SD_WaitCardNotBusy();
	return NO_ERROR;
}


//set write protect
SDC_CMD_STATUS SD_SetWriteProtect(kal_uint32 address)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD28,address))!= NO_ERROR)
		return status;
	if((status = SD_CheckStatus())!= NO_ERROR)
		return status;

	//wait until data line is ready
	SD_WaitCardNotBusy();
	return NO_ERROR;
}

//clear write protect
SDC_CMD_STATUS SD_ClrWriteProtect(kal_uint32 address)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD29,address))!= NO_ERROR)
		return status;
	if((status = SD_CheckStatus())!= NO_ERROR)
		return status;
	SD_WaitCardNotBusy();
	return NO_ERROR;
}

// send write protect(single block read)
SDC_CMD_STATUS SD_SendWriteProtect(kal_uint32 address, kal_uint32* WPBits32)
{
	SDC_CMD_STATUS status;
	kal_uint32	tmp;
	
	BitFieldWrite32((kal_uint32*)SDC_CFG,4,SDC_CFG_BLKLEN);
	MSDC_CLR_FIFO();
	if((status = SD_Send_Cmd(SDC_CMD_CMD30,address))!= NO_ERROR)
		return status;
	if((status = SD_CheckStatus())!= NO_ERROR)
		return status;
	//read 32 write protection bits
	MSDC_ReadReg32(MSDC_DAT,&tmp);
	MSDC_InvertN((kal_uint8*)WPBits32,(kal_uint8*)&tmp,4);
	// configure the controller to the original block length
	BitFieldWrite32((kal_uint32*)SDC_CFG,gSD->mBKLength,SDC_CFG_BLKLEN);

	return NO_ERROR;
}

// CMD39: Fast IO-used to write and read 8 bit register
SDC_CMD_STATUS SD_FastIO_MMC(kal_uint16 rca, kal_bool isWrite, kal_uint8 reg_adrs, kal_uint8 data)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;

	arg = rca << 16;
	arg |= isWrite << 15;
	arg |= reg_adrs << 8;
	arg |= data;

	if((status = SD_Send_Cmd(SDC_CMD_CMD39_MMC,arg))!= NO_ERROR)
		return status;
	if((status = SD_CheckStatus())!= NO_ERROR)
		return status;

	return NO_ERROR;
}


// Sets the system into interrupt mode (MMC)
SDC_CMD_STATUS SD_GoIRQ_MMC(void)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd(SDC_CMD_CMD40_MMC,SDC_NO_ARG))!= NO_ERROR)
		return status;
	status = *(kal_uint32*)SDC_RESP0;

	return NO_ERROR;
}

// Used to set/reset password ,lock/unlock the card and force erase total card. 
// similiar to a signle block write structure.(CMD42)
// max password length = 16
SDC_CMD_STATUS SD_LockUnlock(SD_LOCK_OP op, kal_char* Oldpwd, kal_char* Newpwd, kal_uint8 Oldlen,kal_uint8 Newlen)
{
	SDC_CMD_STATUS status;
	kal_uint8 lockbk[SDC_MAX_LOCKBK];
	kal_uint32 i,blklen,*ptr = (kal_uint32*)lockbk,count;

	if(Oldlen > 16 || Newlen > 16)
		return ERR_ERRORS;

	/* save the original block length*/
	blklen = gSD->mBKLength;

	memset(lockbk,0,SDC_MAX_LOCKBK);
	switch(op)
	{
	case SET_PWD:
		lockbk[0] = 0x01;
		break;
	case CLR_PWD:
		lockbk[0] = 0x02;
		break;
	case LOCK_CARD:
		lockbk[0] = 0x04;
		break;
	case UNLOCK_CARD:
		lockbk[0] = 0x00;
		break;
	case ERASE:
		lockbk[0] = 0x08;
		break;
	}
	lockbk[1] = Oldlen+Newlen;
	memcpy(&lockbk[2],Oldpwd,Oldlen);
	memcpy(&lockbk[2+Oldlen],Newpwd,Newlen);

	/* set block length */
	if(op != ERASE)
	{
		SD_SetBlength(2+lockbk[1]);
		count = ((lockbk[1]+2)%sizeof(kal_uint32))?((lockbk[1]+2)/sizeof(kal_uint32)+1):
											   ((lockbk[1]+2)/sizeof(kal_uint32));
	}
	else
	{
		SD_SetBlength(1);
		count = 1;
	}
	/* send command */
	if((status = SD_Send_Cmd(SDC_CMD_CMD42,SDC_NO_ARG))!= NO_ERROR)
		return status;
	/* read R1b */
	SD_CheckStatus();
	/* clear FIFO */
	MSDC_CLR_FIFO();
	count = ((lockbk[1]+2)%sizeof(kal_uint32))?((lockbk[1]+2)/sizeof(kal_uint32)+1):
											   ((lockbk[1]+2)/sizeof(kal_uint32));
#ifndef DRV_LSD
	/* write data into fifo */
	for(i=0;i<count;)
	{
		if(!MSDC_IS_FIFO_FULL)
		{
			*(volatile kal_uint32*)MSDC_DAT = *(kal_uint32*)(ptr+i);
			i++;
		}
	}
#endif
	/* wait until crc status token received */
	status = SD_WaitDatRdyOrTo();
	/* wait util card has finished programming */
	SD_WaitCardNotBusy();
	// restore the block length back
	SD_SetBlength(blklen);
	/* check status*/
	SD_GetStatus(gSD->mRCA,&status);
	if(status & R1_LOCK_UNLOCK_FAILED_24)
		return ERR_LOCK_UNLOCK_FAILED;
	if((op == LOCK_CARD) && !(status & R1_CARD_IS_LOCKED_25))
		return ERR_LOCK_UNLOCK_FAILED;
	if((op == UNLOCK_CARD) && (status & R1_CARD_IS_LOCKED_25))
		return ERR_LOCK_UNLOCK_FAILED;

	return NO_ERROR;
}

// ACMD13: read SD status(512bits = 64bytes single block read)
SDC_CMD_STATUS SD_GetSDStatus(kal_uint32* sd_status)
{
	SDC_CMD_STATUS status;
	kal_uint32 blklen,i;

	// save the orignial block length
	blklen = gSD->mBKLength;
	// set block length
	if((status = SD_SetBlength(64))!= NO_ERROR)
		return status;
	// clear fifo
	MSDC_CLR_FIFO();
	// send APP_CMD
	if((status = SD_Cmd55(gSD->mRCA))!= NO_ERROR)
		return status;
	// send CMD13
	if((status = SD_Send_Cmd(SDC_CMD_ACMD13,SDC_NO_ARG))!= NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus())!= NO_ERROR)
		return status;	
	// read sd status(64bytes = 4x16)	
#ifndef DRV_LSD
	for(i=0;i<16;)
	{
		if(!MSDC_IS_FIFO_EMPTY)
		{
			*(kal_uint32*)(sd_status+i) = *(volatile kal_uint32*)MSDC_DAT;
			i++;
		}
	}
#endif
	// resotre block length
	if((status = SD_SetBlength(blklen))!= NO_ERROR)
		return status;

	return NO_ERROR;
}
//ACMD22: get the number of written write blocks(4bytes single block read)
SDC_CMD_STATUS SD_GetNumWrittenBlk(kal_uint32* num)
{
	SDC_CMD_STATUS status;
	kal_uint32 blklen,tmp;

	// save the orignial block length
	blklen = gSD->mBKLength;
	// set block length
	if((status = SD_SetBlength(4)) != NO_ERROR)
		return status;
	// clear fifo
	MSDC_CLR_FIFO();
	// send APP_CMD
	if((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
		return status;
	// send CMD22
	if((status = SD_Send_Cmd(SDC_CMD_ACMD22,SDC_NO_ARG)) != NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus()) != NO_ERROR)
		return status;	
	// read the number of written write blocks(4bytes)	
#ifndef DRV_LSD
	while(MSDC_IS_FIFO_EMPTY);
#endif
	tmp = *(volatile kal_uint32*)MSDC_DAT;
	MSDC_InvertN((kal_uint8*)num,(kal_uint8*)&tmp,4);
	// resotre block length
	if((status = SD_SetBlength(blklen))!= NO_ERROR)
		return status;
	return NO_ERROR;
}


void SD_startFastFormat(void)
{
	
#ifdef DRV_LSD
	LSD_startFastFormat();
#endif
}

void SD_closeFastFormat(void)
{
	
#ifdef DRV_LSD
	LSD_closeFastFormat();
#endif

}

kal_bool MSDC_ModuleTest_Report(void)
{
    return gMSDC_Handle->mIsInitialized;
}
#else
#ifdef DRV_LSD
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;
#endif
#endif //  defined(__MSDC_SD_MMC__)

#ifdef MSDC_DEBUG

#define TST_ADRS	512*12
static kal_uint8 rxbuffer[512*32],txbuffer[512*32];
//static kal_uint8 rxbuffer[512],txbuffer[512];
kal_uint32 SD_MMC_Test(void)
{

	kal_uint32 result,resp;
	int i;
	SDC_CMD_STATUS status;

	// initialize MSDC
	MSDC_Initialize();
	// initialize SDC
	SD_Initialize();
		

//////////////////////////
//Mass data Tansfer(8M)//
//////////////////////////
#ifdef MASS
{
	int block_num,i,j,cmp,loop = 1;
	kal_uint32 ticks;
	
#ifdef BITS4_BUS
	if(gMSDC_Handle->mMSDC_type == SD_CARD){
		if(status = SD_SetBusWidth(BIT_4W))
			return status;
	}
#endif

	for(i=0;i<512*32;i++)
		txbuffer[i] = i%256;
		
	j=0;
	ticks = NU_Retrieve_Clock();	
	while(loop){
		status = SD_WriteMultiBlock(j*512*32,(uint32*)txbuffer,32);
		if(status) 
		{
			ticks = NU_Retrieve_Clock()- ticks  ;	
			//dbg_print("SD_WriteMultiBlock failed! %d \n\r",ticks);
			//while(1);
		}

		status = SD_ReadMultiBlock(j*512*32,(uint32*)rxbuffer,32);	
		if(status) 
		{
			ticks = NU_Retrieve_Clock()- ticks  ;	
			//dbg_print("SD_ReadMultiBlock failed! %d \n\r",ticks);
			//while(1);
		}
		ticks = NU_Retrieve_Clock()- ticks  ;
		
		cmp = memcmp(txbuffer,rxbuffer,512*32);
		if(cmp)
		{
			ticks = NU_Retrieve_Clock()- ticks  ;	
			//dbg_print("compare failed! %d \n\r",ticks);
			//while(1);
		}
		//dbg_print("Check %d OK!\t",j);
		kal_mem_set(rxbuffer,0,512*32);
		j++;
		if(j*32 >= gSD->mBKNum-32)
		{
			static count = 0;
			ticks = NU_Retrieve_Clock()- ticks  ;	
			//dbg_print("\n\r###############################\n\r",ticks);			
			//dbg_print("end of card %d at count %d\n\r",ticks,count++);
			//dbg_print("\n\r###############################\n\r",ticks);			
			
			j=0;
			ticks = NU_Retrieve_Clock();	

			//while(1);
		}
	}
/*	
	// (1) using single block transfer
	ticks = NU_Retrieve_Clock();
	block_num  = 32;
	//block_num  = 1024;
	for(i=0;i<block_num;i++)
		if(status = SD_WriteSingleBlock(i*512,(kal_uint32*)txbuffer))
			break;

	ticks = NU_Retrieve_Clock()- ticks  ;
	ticks = NU_Retrieve_Clock();
	for(i=0;i<block_num;i++)
	{
		if(status = SD_ReadSingleBlock(i*512,(kal_uint32*)rxbuffer))
			break;
	}
	ticks = NU_Retrieve_Clock()- ticks  ;

	// (2) using multiple block transfer(requied to rewind the buffer pointer)
	ticks = NU_Retrieve_Clock();
	status = SD_WriteMultiBlock(0,(kal_uint32*)txbuffer,block_num);
	ticks = NU_Retrieve_Clock()- ticks  ;
	
	ticks = NU_Retrieve_Clock();
	status = SD_ReadMultiBlock(0,(kal_uint32*)rxbuffer,block_num);
	ticks = NU_Retrieve_Clock()- ticks  ;
*/	

}
#endif // end of MASS

#ifdef SD_ERASE
	// there are differences between SD and MMC
	// tag erase start(CMD32)
	if(status = SD_EraseCmdClass(SDC_CMD_CMD32,0))
		return status;
	// tag erase end(CMD33)
	if(status = SD_EraseCmdClass(SDC_CMD_CMD33,512*32))
		return status;
	// erase...(CMD38)
	if(status = SD_EraseCmdClass(SDC_CMD_CMD38,0))
		return status;

	// check result of erase
	// single block read (CMD17)
	if(status = SD_ReadSingleBlock(0,(kal_uint32*)rxbuffer))
		return status;
	result = 0;
	for(i=0;i<512;i++)
	{	
		if(gSD->mSCR.dat_after_erase)
		{
			if(rxbuffer[i] != 0xff)
				result++;
		}
		else
		{
			if(rxbuffer[i] != 0x00)
				result++;
		}
	}
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
#ifdef BITS4_BUS
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
#endif // end of 0
	
}
#endif	// FPGA_DEBUG

