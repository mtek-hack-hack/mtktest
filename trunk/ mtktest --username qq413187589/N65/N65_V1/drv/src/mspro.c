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
 *   mspro.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   MS-Pro driver file.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************
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
#include "fat_fs.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "mspro_def.h"
#include "gpt_sw.h"
#include "intrCtrl.h"
#include "drv_comm.h"

#if defined(__MSDC_MSPRO__)
// global variables
MSP_HANDLE		gMSP = {0};
kal_uint8		msp_info[96];
mspro_di_confirm_count_struct di_confirm_count[] = {
	{SYS_INFO_ID,SYS_INFO_COUNT, 0},
	{MODEL_NAME_ID,MODEL_NAME_COUNT, 0},
	{MBR_VALUE_ID,MBR_VALUE_COUNT, 0},
	{PBR_16_ID,PBR_16_COUNT, 0},
	{PBR_32_ID,PBR_32_COUNT, 0},
	{FILE_VALUE1_ID,FILE_VALUE1_COUNT, 0},
	{FILE_VALUE2_ID,FILE_VALUE2_COUNT, 0},
	{ID_DEVICE_ID,ID_DEVICE_COUNT, 0},
	{VENDER1_ID,0, 0},
	{VENDER2_ID,0, 0},
};
FS_Driver FS_MspDrvAll;


// function declaration
static MSP_STATUS MSP_TPCs(kal_uint32* buffer, kal_uint16 size, kal_uint8 tpc);
static MSP_STATUS MSP_TPC_ReadLongData(kal_uint32* rxbuffer);
static MSP_STATUS MSP_TPC_ReadReg(kal_uint32* buffer, kal_uint8 length);
static MSP_STATUS MSP_TPC_WriteReg(kal_uint32* buffer, kal_uint8 length);
static MSP_STATUS MSP_TPC_SetRWAdrs(kal_uint8 r_adrs, kal_uint8 r_len, kal_uint8 w_adrs, kal_uint8 w_len);
static MSP_STATUS MSP_TPC_GetInt(kal_uint32* intreg);
static MSP_STATUS MSP_TPC_ReadShortData(kal_uint32* buffer, ms_ShortData_enum length);
static MSP_STATUS MSP_TPC_ExSetCmd(kal_uint32 adrs, kal_uint16 count, kal_uint8 cmd,kal_uint16* msc_sta);
extern void GPTI_BusyWait(kal_uint16 len);
extern MSP_STATUS MS_MediaTypeIdentify(kal_uint8 type, kal_uint8 category, kal_uint8 _class, kal_uint8 status);
extern MSP_STATUS MS_Initialize(void);


/*************************************************************************
* FUNCTION
*  detect_parallel_mode
*
* DESCRIPTION
*	Detect if ms-pro is at parallel mode of serial mode.
*
* PARAMETERS
*	
*
* RETURNS
*  
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
static MSP_STATUS detect_parallel_mode(void)
{
	MSP_STATUS status;
	kal_uint32 regint;
	
	// disable parallel mode for controller 	
	MSDC_CLR_BIT32(MSC_CFG,MSC_CFG_PMODE);
   if((status = MSP_TPC_GetInt(&regint)) != MSP_NOERROR)
   {
      // time out => set parallel mode
      MSDC_SET_BIT32(MSC_CFG,MSC_CFG_PMODE);
		if((status = MSP_TPC_GetInt(&regint)) == MSP_NOERROR)
      	gMSP.mode = MSP_PARALLEL;
		else
			return MSP_ERRORS;
   }
   else
   	gMSP.mode = MSP_SERIAL;

	return MSP_NOERROR;
}
/*************************************************************************
* FUNCTION
*  MSP_Confirm_CPU
*
* DESCRIPTION
*	Check if MS-PRO controller is ready	
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static MSP_STATUS MSP_Confirm_CPU(void)
{
	kal_uint32 t1, reg;
	MSP_STATUS status;

	t1 = drv_get_current_time();
	while(1)
	{
		if(kal_query_systemInit()==KAL_TRUE)
			GPTI_BusyWait(50);
		else
			kal_sleep_task(12);
		
		reg = 0;
		if(drv_get_duration_ms(t1) > 13000)
		{
			//MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_VDDPD);
			return MSP_ERRORS;
		}
		if((status = MSP_TPC_GetInt(&reg)) != MSP_NOERROR)
			continue;
		if(reg & INT_CED)
		{
			reg = 0;
			if((status = MSP_TPC_GetInt(&reg)) != MSP_NOERROR)
				continue;
			if(reg & INT_ERR)
			{
				if(reg & INT_CMDNK)
				{
					gMSP.is_wp = KAL_TRUE;
					return MSP_NOERROR;					
				}
				else
				{
					// MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_VDDPD);
					return  MSP_ERRORS;// meida error			
				}
			}
			else
				return MSP_NOERROR;
		}
	}

	
	return MSP_ERRORS;
}
static MSP_STATUS MSP_Confirm_DevInfo_Count(kal_uint32 start, kal_uint32 di_count)
{
	kal_uint8 id, *p = (kal_uint8*)start;
	kal_uint32 size, adrs;

	while(di_count--)
	{	
		kal_uint32 i;
		
		MSDC_InvertN((kal_uint8*)&adrs, &p[0], 4);
		MSDC_InvertN((kal_uint8*)&size, &p[4], 4);
		MSDC_InvertN((kal_uint8*)&id, &p[8], 1);
		if( (adrs + size ) > 0x8000 || adrs < 0x1A0)
			return MSP_ERR_SI_CONFIM;
		for(i = 0; i < 8; i++)
		{
			if(id == di_confirm_count[i].id)
			{
				if(size != di_confirm_count[i].count)
					return MSP_ERR_SI_CONFIM;
				di_confirm_count[i].adrs = adrs;	
				break;
			}
		}
		p += 12;		
	}
	return MSP_NOERROR;
}
/*************************************************************************
* FUNCTION
*  MSP_Confirm_Atrb
*
* DESCRIPTION
*	Read the attribute of MS-PRO card
*
* PARAMETERS
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	gMSP
*
*************************************************************************/
static MSP_STATUS MSP_Confirm_Atrb(void)
{
	MSP_STATUS status;
	kal_uint8 *p = (kal_uint8*)MSDC_Sector;
	kal_uint16 sectors;
	kal_uint32 tmp, adrs, tmp1;

	status = MSP_CMD_ReadAtrb(0, 1, MSDC_Sector, &sectors);
	if(status != MSP_NOERROR)
		return status;
	// confirmation area
	MSDC_InvertN((kal_uint8*)&tmp, &p[0], 2);
	gMSP.signature = (kal_uint16)tmp;
	MSDC_InvertN((kal_uint8*)&tmp, &p[2], 2);
	gMSP.version = (kal_uint16)tmp;	
	gMSP.di_count = p[4];
	status = MSP_Confirm_DevInfo_Count((kal_uint32)&p[16], p[4]);
	if(status != MSP_NOERROR)
		return status;
	if(gMSP.signature != 0xA5C3)
		return MSP_ERR_SIG;
	if(gMSP.di_count > 12)
		return MSP_ERR_SI_CONFIM;
	// retreive device information
	adrs = di_confirm_count[0].adrs;
	tmp = adrs/512;
	tmp1 = adrs%512;
	if(tmp == 0)
	{
		kal_mem_cpy(msp_info, ((kal_uint8*)MSDC_Sector + adrs), 96);
	}
	else
	{
		if(tmp1+96 < 512)
		{
			status = MSP_CMD_ReadAtrb(tmp, 1, MSDC_Sector, &sectors);
			if(status != MSP_NOERROR)
				return status;
			kal_mem_cpy(msp_info, ((kal_uint8*)MSDC_Sector + tmp1), 96);
		}
		else
		{
			kal_uint32 remain = 512-tmp1;
			
			status = MSP_CMD_ReadAtrb(tmp, 1, MSDC_Sector, &sectors);
			if(status != MSP_NOERROR)
				return status;
			kal_mem_cpy(msp_info,(kal_uint8*)MSDC_Sector + tmp1, remain);
			status = MSP_CMD_ReadAtrb(tmp+1, 1, MSDC_Sector, &sectors);
			if(status != MSP_NOERROR)
				return status;
			kal_mem_cpy((msp_info+remain) ,(kal_uint8*)MSDC_Sector, 96-remain);			
		}
	}
	p = msp_info;
	gMSP.mSIClass = (kal_uint8)p[0];
	gMSP.mSIDevType = (kal_uint8)p[56];
   MSDC_InvertN((kal_uint8*)&tmp, &p[2], 2);
   gMSP.block_size = (kal_uint16)tmp;
   MSDC_InvertN((kal_uint8*)&tmp, &p[4], 2);
   gMSP.total_block = (kal_uint16)tmp;
   MSDC_InvertN((kal_uint8*)&tmp, &p[6], 2);
   gMSP.user_block = (kal_uint16)tmp;
   MSDC_InvertN((kal_uint8*)&tmp, &p[8], 2);
   gMSP.page_size = (kal_uint16)tmp;
   MSDC_InvertN((kal_uint8*)&tmp, &p[44], 2);
   gMSP.unit_size = (kal_uint16)tmp;
	gMSP.mSISubClass = (kal_uint8)p[46]; 	
	gMSP.mSIDevType = (kal_uint8)p[55];

	if(gMSP.mSIClass != 2)
		return MSP_ERR_SI_CONFIM;

	if(gMSP.mSIDevType > 0 && gMSP.mSIDevType < 4)
	{
		gMSP.is_wp = KAL_TRUE;
	}
	else if(gMSP.mSIDevType >= 4)
		return MSP_ERR_SI_CONFIM;
		
	if(gMSP.mSISubClass & 0xc0)
	{
		return MSP_ERR_SI_CONFIM;
	}
	return MSP_NOERROR;
}
/*************************************************************************
* FUNCTION
*  MS_Switch_Interface
*
* DESCRIPTION
*	switch the serial mode or parallel mode
*
* PARAMETERS
*	MSP_PARALLEL : parallel mode
*	MSP_SERIAL : serial mode
*
* RETURNS
*  MSP_STATUS
*
* GLOBALS AFFECTED
*	gMSP
*
*************************************************************************/
static MSP_STATUS MSP_Switch_Interface(msp_mode_enum srac)
{
	// clear SRAC 0: parallel, 1: serial to enable parallel interface 	
	MSP_STATUS status;
	kal_uint8 retry = 0;

	if((status = MSP_TPC_SetRWAdrs(MSP_SYS_REG,1,MSP_SYS_REG,1)) != MSP_NOERROR)
		return status;
	while(retry++ < 5)
	{
		status = MSP_TPC_WriteReg((kal_uint32*)&srac,1);
		if(status == MSP_NOERROR)
		{
			if(srac == MSP_PARALLEL)
			{
				MSDC_SetClock(26000);
				gMSP.mode = MSP_PARALLEL;
				MSDC_SET_BIT32(MSC_CFG,MSC_CFG_PMODE);
			}
			else
			{
				MSDC_SetClock(13000);
				MSDC_CLR_BIT32(MSC_CFG,MSC_CFG_PMODE);
				gMSP.mode = MSP_SERIAL;
			}
			if(kal_query_systemInit()==KAL_TRUE)
				GPTI_BusyWait(8);
			else
				kal_sleep_task(2);					
			
			return MSP_NOERROR;			
		}
	}
	if(retry >= 5)
		return MSP_ERR_SWITCH_MODE;	
	
	
	return MSP_ERR_SWITCH_MODE;
}
/*************************************************************************
* FUNCTION
*  MSP_Initialize
*
* DESCRIPTION
*	Initialize the driver and MSDC controller for MS-PRO
*
* PARAMETERS
*	
*
* RETURNS
*  MSP_STATUS
*
* GLOBALS AFFECTED
*	gMSP
*
*************************************************************************/
MSP_STATUS MSP_Initialize(void)
{
	kal_uint8 buffer[8];
	MSP_STATUS status;

	if(gMSDC_Handle->mIsInitialized)
		return MSP_NOERROR;
	
	#ifdef MSDC_USE_INT
	// reset the events
	kal_set_eg_events(MSDC_Events, 0, KAL_AND);
	#endif
	MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_VDDPD);	
	if(kal_query_systemInit()==KAL_TRUE)
		GPTI_BusyWait(50);
	else
		kal_sleep_task(11);
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
	SET_FIFO_THRESHOLD(1);

	// tuning the signal
	//MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_CRED);
	//MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_RED);
	//MSDC_SET_BIT32(MSC_CFG,MSC_CFG_PRED);	
	// tuning the driving capability
	// MSDC_WriteReg32(MSDC_IOCON,0xC0);	
	
	//set clock of serial clcok
	gMSDC_Handle->msdc_clock = MSDC_CLOCK;;
	MSDC_SetClock(13000);
	// set ready time out value
	BitFieldWrite32((kal_uint32*)MSC_CFG,(kal_uint32)7,MSC_CFG_BUSYCNT);	
	// enable the serial interface
	MSDC_SET_BIT32(MSC_CFG,MSC_CFG_SIEN);
	MSDC_CLR_BIT32(MSC_CFG,MSC_CFG_PMODE);
	//if((status = detect_parallel_mode()) != MSP_NOERROR)
		//return MSP_ERRORS;
	// read status registers
	// ms pro has default value 0h,8h,10h,10h
	if((status = MSP_TPC_SetRWAdrs(0,8,MSP_SYS_REG,1)) != MSP_NOERROR)
		return status;	
	if ((status = MSP_TPC_ReadReg((kal_uint32*)buffer,8)) != MSP_NOERROR)
		return status;

	// media identification procedure
	// type:1, Category:0, Class:0 for mspro
	gMSP.mType = buffer[MSP_TYPE_REG];
	gMSP.mCategory = buffer[MSP_CATEGORY_REG];
	gMSP.mClass = buffer[MSP_CLASS_REG];
	gMSP.is_wp = buffer[MSP_STA_REG] & STA_WP;	
	if(gMSP.mType == 0 || gMSP.mType == 0xFF)
	{
		gMSDC_Handle->mMSDC_type = MS_CARD;
		status = MS_MediaTypeIdentify(buffer[MSP_TYPE_REG],buffer[MSP_CATEGORY_REG], buffer[MSP_CLASS_REG],buffer[MSP_STA_REG]);
		if(status == MSP_NOERROR)
		{			
			status = MS_Initialize();
			if(status == MSP_NOERROR)
			{
				FS_MsDrv.MountDevice = FS_MspDrv.MountDevice;
				FS_MspDrvAll = FS_MsDrv;
				return MSP_NOERROR;
			}
			else 
				return MSP_ERR_NOT_MSP;
		}
		else
			return MSP_ERR_NOT_MSP;
	}
	else
	{
		gMSDC_Handle->mMSDC_type = MSPRO_CARD;
	}
	if(gMSP.mType != TYPE_MSPRO_CARD || gMSP.mCategory != 0 )
	{
		return MSP_ERR_NOT_MSP;
	}
	if(gMSP.mClass > 0 && gMSP.mClass < 4)
	{
		gMSP.is_wp = KAL_TRUE;
	}	 
	else if(gMSP.mClass != 0)
	{
		return MSP_ERR_NOT_MSP;
	}
	// check write protect status
	gMSP.is_wp = buffer[MSP_STA_REG] & STA_WP;
	// Confirm CPU startup
	if(MSP_Confirm_CPU() != MSP_NOERROR)
		return MSP_ERR_INIT;	
	
#if defined(MSP_USE_PARALLEL_MODE)
	if(!gMSP.is_failed)
	{
		if((status = MSP_Switch_Interface(MSP_PARALLEL))!= MSP_NOERROR)
			return status;
	}
	else
	{
		if((status = MSP_Switch_Interface(MSP_SERIAL))!= MSP_NOERROR)
			return status;
	}
#endif

	status = MSP_Confirm_Atrb();
	if(status == MSP_NOERROR)
		gMSDC_Handle->mIsInitialized = KAL_TRUE;

	#if 0// format the MS-PRO
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
*  MSP_SendTPC
*
* DESCRIPTION
*	Send TPC to MS-PRO card 
*
* PARAMETERS
*	cmd: TPC commands
*	size: size of the data for this command
*
* RETURNS
*  none
*
* GLOBALS AFFECTED
*	none
*
*************************************************************************/
static void MSP_SendTPC(kal_uint8 cmd, kal_uint16 size)
{
	kal_uint16 arg = 0;

	ASSERT(!MSDC_IS_BUSY);
	arg = cmd << 12;
	arg |= size;
	MSDC_WriteReg16(MSC_CMD,arg);
}
/*************************************************************************
* FUNCTION
*  MSP_WaitCmdRdyOrTo
*
* DESCRIPTION
*	wait for TPC transaction complete(end of BS3 or timeout,crc occurs)
*
* PARAMETERS
*
* RETURNS
*  MSP_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
MSP_STATUS MSP_WaitCmdRdyOrTo(void)
{
	kal_uint16 msc_sta;

#ifdef MSDC_USE_INT	
	kal_uint32 flags;

	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
	kal_retrieve_eg_events(MSDC_Events,EVENT_MSRDYIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);	
	MSDC_STOP_TIMER();
#else	
{
	kal_uint32 t1;

	t1 = drv_get_current_time();
	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
	while(!MSDC_IS_INT && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
			gMSDC_Handle->is_timeout = KAL_TRUE;
	}
	MSDC_STOP_TIMER();
	MSDC_CLR_INT();	
}
#endif

	msc_sta = *(volatile kal_uint16*)MSC_STA;
	if(msc_sta & MSC_STA_CRCERR)
		return MSP_ERR_CRCERR;
	else if(msc_sta & MSC_STA_TOER)
		return MSP_ERR_TIMEOUT;
	else if(msc_sta & MSC_STA_RDY)
		return MSP_NOERROR;
	if(gMSDC_Handle->is_timeout)
	{
		kal_prompt_trace(MOD_MSDC_HISR,"cmd timeout");
		return MSDC_GPT_TIMEOUT_ERR;
	}
	return MSP_NOERROR;
}
/*************************************************************************
* FUNCTION
*  MSP_WaitCard_INT
*
* DESCRIPTION
*	wait for MS card producing INT signal and retreive result of the INT
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static MSP_STATUS MSP_WaitCard_INT(kal_uint16 *msc_sta)
{
#ifdef MSDC_USE_INT	
	kal_uint32 flags;

	MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
	kal_retrieve_eg_events(MSDC_Events,EVENT_MSIFIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);	
	MSDC_STOP_TIMER();
	*msc_sta = *(volatile kal_uint16*)MSC_STA;
#else	
		kal_uint32 t1;
		MSP_STATUS status;
		kal_uint8 reg[4], reg1[4];
		
		t1 = drv_get_current_time();
		MSDC_START_TIMER(MSP_INT_TIMEOUT);
		while(!((*msc_sta = *(volatile kal_uint16*)MSC_STA)&MSC_STA_SIF)
			&& MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSP_INT_TIMEOUT*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;
		}
		MSDC_STOP_TIMER();
		MSDC_CLR_INT();	
#endif
	if(gMSP.mode == MSP_SERIAL)
	{			
		status = MSP_TPC_GetInt((kal_uint32*)reg);
		if(reg[0] & INT_BREQ)
			*msc_sta |= MSC_STA_BREQ;
		if(reg[0] & INT_CED)
			*msc_sta |= MSC_STA_CED;
		if(reg[0]& INT_CMDNK)
			*msc_sta |= MSC_STA_CMDNK;
		if((reg[0] & INT_ERR) || (status != MSP_NOERROR))
			*msc_sta |= MSC_STA_ERR;
	}	
	if((*msc_sta = *(volatile kal_uint16*)MSC_STA)&MSC_STA_SIF)
		return MSP_NOERROR;
	
	if(gMSDC_Handle->is_timeout)
	{		
		kal_prompt_trace(MOD_MSDC_HISR,"INT timeout");
		status = MSP_TPC_GetInt((kal_uint32*)reg);
		status = MSP_TPC_GetInt((kal_uint32*)reg1);
		
		if(reg[0] & INT_BREQ)
			*msc_sta |= MSC_STA_BREQ;
		if(reg[0] & INT_CED)
			*msc_sta |= MSC_STA_CED;
		if(reg[0]& INT_CMDNK)
			*msc_sta |= MSC_STA_CMDNK;
		if((reg[0] & INT_ERR) || (status != MSP_NOERROR))
			*msc_sta |= MSC_STA_ERR;
	
		return MSDC_GPT_TIMEOUT_ERR;
	}
	return MSP_ERRORS;
}
/*************************************************************************
* FUNCTION
*  MSP_TPCs
*
* DESCRIPTION
*	send TPC with data transfer 
*
* PARAMETERS
*	buffer: data buffer for read or write
*	size: size of data to read or write(bytes)
*	tpc: TPC code
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static MSP_STATUS MSP_TPCs(kal_uint32* buffer, kal_uint16 size, kal_uint8 tpc)
{
	MSP_STATUS status;
	kal_uint32 i, count;
	kal_bool IsWrite;
	
	// check handshake ready produced by card
	//direction 0: read, 1: write
	IsWrite = (tpc & 0x8)?KAL_TRUE:KAL_FALSE;
	
	// data transfer
	if(size == 512)
	{
		EnableMSDC_DMA();
		MSDC_DMATransferFirst((kal_uint32)buffer,512/4,IsWrite);						
		// send TPC
		MSP_SendTPC(tpc,size);
		status = MSDC_DMATransferFinal();
		status = MSP_WaitCmdRdyOrTo();		
		DisableMSDC_DMA();
		if(status != MSP_NOERROR)
			goto err_exit; // maybe timeout, crc err.			
	}	
	else
	{		
		kal_uint32 t1;
		
		MSP_SendTPC(tpc,size);
		count = (size+3)/4;

		t1 = drv_get_current_time();		
		if(!IsWrite)	// read
		{	
			for(i=0;i<count;)
			{
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(buffer+i) = *(volatile kal_uint32*)MSDC_DAT;
					i++;
				} 
				else if(MS_IS_TIMEOUT)
					break;				
				else if(!gMSDC_Handle->mIsPresent)
					break;
				if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				{					
					gMSDC_Handle->is_timeout = KAL_TRUE;
					return MSDC_GPT_TIMEOUT_ERR;
					
				}
			}
		}
		else	// write
		{
			for(i=0;i<count;)
			{
				if(!MSDC_IS_FIFO_FULL)
				{
					*(volatile kal_uint32*)MSDC_DAT = *(buffer+i);
					i++;
				}
				else if(MS_IS_TIMEOUT)
					break;				
				else if(!gMSDC_Handle->mIsPresent)
					break;	
				if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				{					
					gMSDC_Handle->is_timeout = KAL_TRUE;
					return MSDC_GPT_TIMEOUT_ERR;
					
				}				
			}
			// wait cmd ready or busy timeout
		}
		if((status = MSP_WaitCmdRdyOrTo()) != MSP_NOERROR)
			return status;
			
	}
	return MSP_NOERROR;
	
err_exit:
	#if defined(MSDC_USE_INT)
	kal_set_eg_events(MSDC_Events,0,KAL_AND);
	#endif
	DisableMSDC_DMA();
	MSP_CMD_Stop();
	return status;
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_ReadLongData
*
* DESCRIPTION
*	read data form pagebuffer in uints of page(512 bytes)
*
* PARAMETERS
*	rxbuffer: data buffer for read 
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static MSP_STATUS MSP_TPC_ReadLongData(kal_uint32* rxbuffer)
{	
	return MSP_TPCs(rxbuffer,512,TPC_READ_LONG_DATA);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_WriteLongData
*
* DESCRIPTION
*	write data to pagebuffer in uints of page(512 bytes)
*
* PARAMETERS
*	txbuffer: data buffer for read 
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
// TPC for writing to PageBuffer in uints of page(512 bytes)
MSP_STATUS MSP_TPC_WriteLongData(kal_uint32* txbuffer)
{
	return MSP_TPCs(txbuffer,512,TPC_WRITE_LONG_DATA);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_ReadReg
*
* DESCRIPTION
*	TPC for reading form the register which address was set by TPC_SET_R/W_REG_ADRS.
*
* PARAMETERS
*	buffer: data buffer for read 
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
* 	Note: buffer must be prepared up to multiple of 4 ,ex.
* 	if length  = 7 , u must prepare 8 bytes  = 2x4 bytes as buffer 
*
*************************************************************************/
static MSP_STATUS MSP_TPC_ReadReg(kal_uint32* buffer, kal_uint8 length)
{
	return 	MSP_TPCs(buffer,(kal_uint16)length,TPC_READ_REG);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_WriteReg
*
* DESCRIPTION
*	TPC for writing data into the register which address was set by TPC_SET_R/W_REG_ADRS.
*
* PARAMETERS
*	buffer: data buffer for write 
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
* 	Note: buffer must be prepared up to multiple of 4 ,ex.
* 	if length  = 7 , u must prepare 8 bytes  = 2x4 bytes as buffer 
*
*************************************************************************/
static MSP_STATUS MSP_TPC_WriteReg(kal_uint32* buffer, kal_uint8 length)
{
	return 	MSP_TPCs(buffer,(kal_uint16)length,TPC_WRITE_REG);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_SetRWAdrs
*
* DESCRIPTION
*	TPC for setting values which determine the registers accessed by WRITE_REG and READ_REG
*
* PARAMETERS
*	r_adrs: start address of register for ReadReg
*	r_len: length for ReadReg
*	w_adrs: start address of register for WriteReg
*	w_len: length for WriteReg
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
static MSP_STATUS MSP_TPC_SetRWAdrs(kal_uint8 r_adrs, kal_uint8 r_len, kal_uint8 w_adrs, kal_uint8 w_len)
{
	kal_uint8 data[4];

	data[0] = r_adrs;
	data[1] = r_len;
	data[2] = w_adrs;
	data[3] = w_len;

	return 	MSP_TPCs((kal_uint32*)data,(kal_uint16)4,TPC_SET_R_W_REG_ADRS);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_GetInt
*
* DESCRIPTION
*	TPC for read 1 byte INT register
*
* PARAMETERS
*	intreg: intreg contains the result of the INT register
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
static MSP_STATUS MSP_TPC_GetInt(kal_uint32* intreg)
{
	return 	MSP_TPCs(intreg,(kal_uint16)1,TPC_GET_INT);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_ReadShortData
*
* DESCRIPTION
*	read data from data buffer in the size of (32, 64, 128 and 256 bytes)
*
* PARAMETERS
*	buffer: data buffer for read
*	length: enum of short data (32,64,128,256)
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
// read data from data buffer in the size of (32, 64, 128 and 256 bytes)
static MSP_STATUS MSP_TPC_ReadShortData(kal_uint32* buffer, ms_ShortData_enum length)
{
	/*
	// set TPC parameter for short data length
	MSP_TPC_SetRWAdrs(0,8,MSP_TPCPARA_REG,1);
	MSP_TPC_WriteReg((kal_uint32*)&length,1);
	*/
	return 	MSP_TPCs(buffer,(kal_uint16)(1 << (length+5)),TPC_READ_SHORT_DATA);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_WriteShortData
*
* DESCRIPTION
*	write data into data buffer in the size of (32, 64, 128 and 256 bytes)
*
* PARAMETERS
*	buffer: data buffer for write
*	length: enum of short data (32,64,128,256)
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
MSP_STATUS MSP_TPC_WriteShortData(kal_uint32* buffer, ms_ShortData_enum length)
{
	// set TPC parameter for short data length
	MSP_TPC_SetRWAdrs(0,8,MSP_TPCPARA_REG,1);
	MSP_TPC_WriteReg((kal_uint32*)&length,1);
		
	return 	MSP_TPCs(buffer,(kal_uint16)length,TPC_WRITE_SHORT_DATA);
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_SetCmd
*
* DESCRIPTION
*	send command to be executed by Memory I/F Sequencer
*
* PARAMETERS
*	cmd: command code
*	msc_stc: status after command is executed 
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
MSP_STATUS MSP_TPC_SetCmd(kal_uint8 cmd, kal_uint16* msc_sta)
{
	MSP_STATUS status;

	// send the TPC (1 bytes data)
	MSP_SendTPC(TPC_SET_CMD,1);
	// write 1 byte data into fifo
	*(volatile kal_uint8*)MSDC_DAT = cmd;
	// TPC transaction complete
	if((status = MSP_WaitCmdRdyOrTo()) != MSP_NOERROR)
		return status;			
	// wait for INT signal
	MSP_WaitCard_INT(msc_sta);
	// cmd not accept
	if(*msc_sta & (MSC_STA_CMDNK|MSC_STA_ERR))
		return MSP_ERR_CMDFAIL;

	return MSP_NOERROR;	
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_ExSetCmd
*
* DESCRIPTION
*	send command with data count and address to Memory I/F Sequencer
*
* PARAMETERS
*	adrs: start address for data 
*	count: data count
*	cmd: command code
*	msc_sta: status after command is executed
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
static MSP_STATUS MSP_TPC_ExSetCmd(kal_uint32 adrs, kal_uint16 count, kal_uint8 cmd, kal_uint16* msc_sta)
{
	MSP_STATUS status;
	kal_uint8 buffer[8] = {0};
	
	// set parameter register (7 bytes = cmd x1 + count x2 + adrs x4 )
	buffer[0] = cmd;
	buffer[1] = count >> 8;
	buffer[2] = (kal_uint8)count;
	buffer[3] = adrs >> 24;
	buffer[4] = adrs >> 16;
	buffer[5] = adrs >> 8;
	buffer[6] = (kal_uint8)adrs;
	
	if((status = MSP_TPCs((kal_uint32*)buffer,7,TPC_EX_SET_CMD)) != MSP_NOERROR)
		return status;

	// wait for INT signal
	MSP_WaitCard_INT(msc_sta);
	// cmd not accept
	if(*msc_sta & (MSC_STA_CMDNK|MSC_STA_ERR))
		return MSP_ERR_CMDFAIL;

	return MSP_NOERROR;	
}
/*************************************************************************
* FUNCTION
*  MSP_CMD_ReadWriteData
*
* DESCRIPTION
*  read/write data in user area sequentially starting from the designated address.
*
* PARAMETERS
*	1. adrs: start address.
*	2. count: number of of sectors
*	3. buffer: data buffer 
*	4. sectors: actually sectors accessed 
*	5. IsWrite: indicating read or write data
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
MSP_STATUS MSP_CMD_ReadWriteData(kal_uint32 adrs, kal_uint16 count, kal_uint32* buffer, kal_uint16* sectors,msp_direction_enum IsWrite)
{
	MSP_STATUS status;
	kal_uint16 msc_sta;
	kal_uint8	cmd,tpc;
	
	*sectors = 0;
	if(IsWrite == MSP_WRITE)
	{
		if(gMSP.is_wp)
			return MSP_ERR_WRITE_PROTECT;
		cmd = CMD_WRITE_DATA;
		tpc = TPC_WRITE_LONG_DATA;
	}
	else
	{
		cmd = CMD_READ_DATA;
		tpc = TPC_READ_LONG_DATA;	
	}
	
//#define USE_SET_CMD
#ifdef USE_SET_CMD	
	{
		kal_uint8 data[8] = {0};
		// set parameter register
		data[0] = (kal_uint8)(count >> 8);
		data[1] = (kal_uint8)(count);
		data[2] = (kal_uint8)(adrs >> 24);
		data[3] = (kal_uint8)(adrs >> 16);
		data[4] = (kal_uint8)(adrs >> 8);
		data[5] = (kal_uint8)(adrs);
		if((status = MSP_TPC_SetRWAdrs(0,8,MSP_DATCNT1_REG,6)) != MSP_NOERROR)
			return status;
		if((status = MSP_TPC_WriteReg((kal_uint32*)data,6)) != MSP_NOERROR)
			return status;	
		
		// send SET_CMD [READ_DATA] or [WRITE_DATA]
		if((status = MSP_TPC_SetCmd(cmd,&msc_sta)) != MSP_NOERROR)
			return status;	
	}
#else	// use Ex_Set_Cmd
	if((status = MSP_TPC_ExSetCmd(adrs,count,cmd,&msc_sta)) != MSP_NOERROR)
		return status;		
#endif	
	if(!(msc_sta & MSC_STA_BREQ))
	{
		status = MSP_ERR_NOBREQ;
		goto error_exit;
	}

	// check INT status
	while(msc_sta & MSC_STA_BREQ)
	{
		// use TPC_xxx_LONG_DATA to transfer data
		if((status = MSP_TPCs(buffer,MSP_LONGDATA_SIZE,tpc)) != MSP_NOERROR)
         goto error_exit;
         
		(*sectors)++;
		buffer += MSP_LONGDATA_SIZE/sizeof(kal_uint32);
		
		MSP_WaitCard_INT(&msc_sta);
		if(msc_sta & MSC_STA_ERR)
		{
			status = MSP_ERR_INTERR;
			goto error_exit;
		}
		if(msc_sta & MSC_STA_CED)
			break;				
	}
	
	return MSP_NOERROR;	
	
error_exit:
   MSP_CMD_Stop();
   return status;	
}
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
#ifdef USE_SET_CMD	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else	// use Ex_Set_Cmd
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
#endif
/*************************************************************************
* FUNCTION
*  MSP_CMD_ReadAtrb
*
* DESCRIPTION
*	TTPC for read 1 byte INT register
*
* PARAMETERS
*	1. adrs: start address.
*	2. count: number of of sectors
*	3. buffer: data buffer 
*	4. sectors: actually sectors accessed 
*	5. IsWrite: indicating read or write data
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
MSP_STATUS MSP_CMD_ReadAtrb(kal_uint32 adrs, kal_uint16 count, kal_uint32* buffer, kal_uint16* sectors)
{
	MSP_STATUS status;
	kal_uint16 msc_sta;

	// check if count and adrs are valid
	if(count == 0 || count > 0x40 || adrs > 0x3F)
		return MSP_ERR_CMDFAIL;
	
	if((status = MSP_TPC_ExSetCmd(adrs,count,CMD_READ_ATRB,&msc_sta)) != MSP_NOERROR)
		return status;	
	if(!(msc_sta & MSC_STA_BREQ))
	{
		status = MSP_ERR_NOBREQ;
		goto error_exit;
	}	
	while(msc_sta & MSC_STA_BREQ)
	{
		// use TPC_xxx_LONG_DATA to transfer data
		if((status = MSP_TPC_ReadLongData(buffer)) != MSP_NOERROR)
		   goto error_exit;
		   
		(*sectors)++;
		buffer += MSP_LONGDATA_SIZE/sizeof(kal_uint32);
		
		MSP_WaitCard_INT(&msc_sta);
		if(msc_sta & MSC_STA_ERR)
		{		   
			status = MSP_ERR_INTERR;
			goto error_exit;
		}
		if(msc_sta & MSC_STA_CED)
			return MSP_NOERROR;				
	}			
	return MSP_NOERROR;
	
error_exit:
   MSP_CMD_Stop();
   return status;		
}
/*************************************************************************
* FUNCTION
*  MSP_CMD_Erase
*
* DESCRIPTION
*	Erase data from the assigned address in USER AREA
*
* PARAMETERS
*	adrs: start address 
*	count: sectors to be erased 
*	callback: callback function to indicate the progress status
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
MSP_STATUS MSP_CMD_Erase(kal_uint32 adrs, kal_uint16 count,MSP_CallBack callback)
{
	MSP_STATUS status;
	kal_uint16 msc_sta;
	kal_uint8 data[8] = {0};
	
	// set parameter registers for Erase
	data[0] = (kal_uint8)(count >> 8);
	data[1] = (kal_uint8)(count);
	data[2] = (kal_uint8)(adrs >> 24);
	data[3] = (kal_uint8)(adrs >> 16);
	data[4] = (kal_uint8)(adrs >> 8);
	data[5] = (kal_uint8)(adrs);
	data[6] = 0; // set TPC parameter to 0 => 32 bytes for READ_SHORT_DATAs
	if((status = MSP_TPC_SetRWAdrs(MSP_INT_REG,2,MSP_DATCNT1_REG,7)) != MSP_NOERROR)
		return status;
	if((status = MSP_TPC_WriteReg((kal_uint32*)data,7)) != MSP_NOERROR)
		return status;	     		

   // send TPC SetCmd with cmd
	if((status = MSP_TPC_ExSetCmd(adrs,count,CMD_ERASE,&msc_sta)) != MSP_NOERROR)
		return status;

	while(!(msc_sta & MSC_STA_CED))
	{
		kal_uint8 p[24];
					
		// erase is in onging
		if(msc_sta & MSC_STA_BREQ)
		{
			if((status = MSP_TPC_ReadShortData((kal_uint32*) p, SHORT_DATA_24)) != MSP_NOERROR)
				goto error_exit;				
			if(callback != NULL)
				(*callback)();
		}
		MSP_WaitCard_INT(&msc_sta);
		if(msc_sta & MSC_STA_ERR)
		{
			status = MSP_ERR_INTERR;
			goto error_exit;
		}
		if(msc_sta & MSC_STA_CED)
			break;				
			
	};
	
	return MSP_NOERROR;
error_exit:
   MSP_CMD_Stop();
   return status;		
}

/*************************************************************************
* FUNCTION
*  MSP_CMD_FORMAT
*
* DESCRIPTION
*	Self-format with unique values.(Recober to factory default)
*
* PARAMETERS
*	adrs: start address 
*	count: sectors to be erased 
*	callback: callback function to indicate the progress status
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
MSP_STATUS MSP_CMD_Format(msp_format_enum type, MSP_CallBack callback)
{
	MSP_STATUS status;
	kal_uint16 msc_sta;
	kal_uint8 data[4] = {0};
	
	// set parameter registers for Format
	if(gMSP.mode == MSP_SERIAL)
		data[0] = 0x80;
	else
		data[0] = 0;
	data[1] = 0; // use READ_SHORT_DATA for reading the progress data
	data[2] = (kal_uint8)type;
	if((status = MSP_TPC_SetRWAdrs(MSP_INT_REG,2,MSP_SYS_REG,3)) != MSP_NOERROR)
		return status;
	if((status = MSP_TPC_WriteReg((kal_uint32*)data,3)) != MSP_NOERROR)
		return status;	    
	
	// set TPC parameter for short data length
	data[0] = 0; // use 32 byte for short packet length
	if((status = MSP_TPC_SetRWAdrs(MSP_INT_REG,2,MSP_TPCPARA_REG,1)) != MSP_NOERROR)
		return status;
	if((status = MSP_TPC_WriteReg((kal_uint32*)data,1)) != MSP_NOERROR)
		return status;	    

   // send TPC SetCmd with cmd
	if((status = MSP_TPC_SetCmd(CMD_FORMAT,&msc_sta)) != MSP_NOERROR)
		return status;

	while(!(msc_sta & MSC_STA_CED))
	{
		kal_uint8 p[32];
					
		// erase is in onging
		if(msc_sta & MSC_STA_BREQ)
		{
			if((status = MSP_TPC_ReadShortData((kal_uint32*) p, SHORT_DATA_24)) != MSP_NOERROR)
				goto error_exit;				
			if(callback != NULL)
				(*callback)();
		}
		MSP_WaitCard_INT(&msc_sta);
		if(msc_sta & MSC_STA_ERR)
		{
			status = MSP_ERR_INTERR;
			goto error_exit;
		}
		if(msc_sta & MSC_STA_CED)
			break;				
			
	};
	
	return MSP_NOERROR;
error_exit:
   MSP_CMD_Stop();
   return status;		
}

/*************************************************************************
* FUNCTION
*  MSP_CMD_Stop
*
* DESCRIPTION
*	Terminate the operation by READ_DATA, WRITE_DATA, READ_ATRB, ERASE and FORMAT
*
* PARAMETERS
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
MSP_STATUS MSP_CMD_Stop(void)
{
	kal_uint16 msc_sta;
	kal_uint8 reg[4];

	// check if INT_BREQ is set
	MSP_TPC_GetInt((kal_uint32 *)reg);
	if(reg[0] & INT_BREQ)
		return MSP_TPC_SetCmd(CMD_STOP,&msc_sta);
	
	return MSP_NOERROR;
}
/*************************************************************************
* FUNCTION
*  MSP_TPC_ReadShortData
*
* DESCRIPTION
*	TTPC for read 1 byte INT register
*
* PARAMETERS
*	intreg: intreg contains the result of the INT register
*
* RETURNS
*	MSP_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
MSP_STATUS MSP_CMD_Sleep(void)
{
	kal_uint16 msc_sta;
	return MSP_TPC_SetCmd(CMD_SLEEP,&msc_sta);
}



//===========================================================================================//

#ifdef MSP_TEST

#define SIZE   (512*32)
kal_uint8 gbuffer[SIZE] = {0};

void MSP_Mass(void)
{
	MSP_STATUS status;
	kal_uint32 i,adrs,count,error;
	kal_uint16 bytes;

		adrs = 512*128; // start of address
		count = SIZE/512;     // number of pages
		for(i=0;i<SIZE;i++) {
			gbuffer[i] = (kal_uint8)(i%256);
      }

   // write 8 M bytes
	for(i=0;i<(1024*1024*8)/SIZE;i++)
	{
		status = MSP_CMD_ReadWriteData(adrs,count,(kal_uint32*)gbuffer,&bytes,MSP_WRITE);
		if(status)
			MSP_TPC_GetInt((kal_uint32*)gbuffer);
	}

	for(i=0;i<SIZE;i++)
		gbuffer[i] = 0;

	for(i=0;i<(1024*1024*8)/SIZE;i++)
	{
		status = MSP_CMD_ReadWriteData(adrs,count,(kal_uint32*)gbuffer,&bytes,MSP_READ);
		if(status)
			MSP_TPC_GetInt((kal_uint32*)gbuffer);
	}
		for(i=0;i<SIZE;i++)
		{
		   if(gbuffer[i] != (i%256))
		      error++;
		     gbuffer[i] = 0;
      }
}

void MSP_Test(void)
{
	MSP_STATUS status;
	volatile kal_uint8 c = 1;
	
	// initialization
	status = MSP_Initialize();
	while(c)
	{
		kal_uint32 adrs,i,error;
		kal_uint16 count,bytes;
		
		
		adrs = 512*100; // start of address
		count = SIZE/512;     // number of pages
		for(i=0;i<SIZE;i++) {
			//if (i%2==0) gbuffer[i] = (kal_uint8)0x70;
			//else	      gbuffer[i] = (kal_uint8)0x0f;
			gbuffer[i] = (kal_uint8)(i%256);
      }

		// read data
		status = MSP_CMD_ReadWriteData(adrs,count,(kal_uint32*)gbuffer,&bytes,MSP_READ);
		if(status)
			MSP_TPC_GetInt((kal_uint32*)gbuffer);

		for(i=0;i<SIZE;i++) {
			//if (i%2==0) gbuffer[i] = (kal_uint8)0x70;
			//else	      gbuffer[i] = (kal_uint8)0x0f;
		   gbuffer[i] = (kal_uint8)(i%256);
      }

		status = MSP_CMD_ReadWriteData(adrs,count,(kal_uint32*)gbuffer,&bytes,1);
		if(status)
			MSP_TPC_GetInt((kal_uint32*)gbuffer);
			
		for(i=0;i<SIZE;i++)
			gbuffer[i] = 0;		
		bytes = 0;	
		// read data
		status = MSP_CMD_ReadWriteData(adrs,count,(kal_uint32*)gbuffer,&bytes,0);		
		if(status)
			MSP_TPC_GetInt((kal_uint32*)gbuffer);
		error = 0;
		for(i=0;i<SIZE;i++)
		{
		   if(gbuffer[i] != (i%256))
		      error++;	
		     gbuffer[i] = 0;
      }
#define MSP_MASS_TEST
#ifdef MSP_MASS_TEST
		MSP_Mass();
#endif
		status = MSP_CMD_ReadAtrb(0,1,(kal_uint32*)gbuffer,&bytes);
		status = MSP_CMD_Erase(100,3,NULL);
		status = MSP_CMD_Format(MSP_FULL,NULL);
		
	}
}
#endif // MSP_TEST
#endif // __MSDC_MSPRO__


