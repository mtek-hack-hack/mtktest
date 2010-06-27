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
 *   msdc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for MSDC controller
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
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "eint.h"
#include "gpt_sw.h"
#include "drv_comm.h"
#include "fat_fs.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drv_hisr.h"
#include "msdc_def.h"
#include "sd_def.h"
#if defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)
#include "sdio_sw.h"
#endif
#if defined(__MSDC_MS__)
#include "ms_def.h"
#elif defined(__MSDC_MSPRO__)
#include "mspro_def.h"
#endif
#include "upll_ctrl.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "sim_hw.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/
#include "sim_hw.h"

#ifdef DRV_LSD
#include "msdc_lsd.h"
#endif


/*
#if !(defined __MSDC_NOT_SUPPORT_HOT_PLUG__)
#if defined(MT6218B_FN) || defined(MT6219_EV) ||defined(MT6217)||defined(MT6227)||defined(MT6226)||defined(MT6226M)\
		|| defined(MT6225)
#define USE_INT26_CARD_DETECTION
#endif
#endif
*/

// global variable
MSDC_HANDLE MSDC_Blk[SD_NUM];

#ifdef MSDC_MUST_RECORD_PLUGOUT
kal_bool MSDC_everPlugOut;//this is only be set true in plug out hisr, set false in MSDC_getStatus
#endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__)|| defined(__MSDC_MSPRO__)) || defined(__MSDC_SD_SDIO)
MSDC_HANDLE	*gMSDC_Handle = &(MSDC_Blk[0]);
kal_uint32 MSDC_Sector[128] = {0};

#ifdef  __TST_WRITE_TO_FILE_ONLY__
/*error recording: add this additional global variable to use when in error recording*/
MSDC_HANDLE MSDC_ErrorRecordingBlk;
#endif

#if defined(__SIM_PLUS__)
sd_select_enum current_card; // active card
#if !defined(__CUST_NEW__)
extern kal_char MSDC_GetLDO_GPIO(void);
extern kal_char MSDC_GetSwitch_GPIO(void);
kal_char gpio_simplug_ldo_switch;
kal_char gpio_ext_sd_ldo_switch;
kal_char gpio_sim_msdc_switch;	
#endif
#endif

// system control blocks

// function predeclaration
void MSDC_DMAInit(void);
void MSDC_INT_Init(void);
void MSDC_DMA_Callback(void);
void MSDC_EINT_Handler(void);

extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern boot_mode_type stack_query_boot_mode(void); 
extern kal_bool INT_USBBoot(void);
/*************************************************************************
* FUNCTION
*  MSDC_SetClock
*
* DESCRIPTION
*
* PARAMETERS
*	clock: the desired operating clock rate in the unit of kHz
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC_SetClock(kal_uint32 clock)
{
	kal_uint32 cfg;

	if(clock == 0)
		return;
	MSDC_CLR_BIT32(SDC_CFG,SDC_CFG_SIEN);
	cfg = ((gMSDC_Handle->msdc_clock+clock-1)/clock);
	if(cfg <=2 )
	{		
		cfg = 0;
		gMSDC_Handle->op_clock = gMSDC_Handle->msdc_clock/2;
	}
	else
	{
		cfg = (cfg >> 2) + (cfg&3 != 0);	
		gMSDC_Handle->op_clock = gMSDC_Handle->msdc_clock/(4*cfg);
	}
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)cfg,MSDC_CFG_SCLKF);
	MSDC_SET_BIT32(SDC_CFG,SDC_CFG_SIEN);
	
}
/*************************************************************************
* FUNCTION
*  MSDC_Check_Card_Present
*
* DESCRIPTION
*	c
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC_Check_Card_Present(void)
{
#if !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
	return gMSDC_Handle->mIsPresent;
#else
	return KAL_TRUE;
#endif
}
/*************************************************************************
* FUNCTION
*  MSDC_PDNControl
*
* DESCRIPTION
*	Enable power saving or not.
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_PDNControl(kal_bool ON)
{
	gMSDC_Handle->mIsPWDown = ON;
#ifndef DRV_LSD
	if(ON)
	{	// OFF		
		// clear all pending IRQ
		MSDC_CLR_INT();
		MSDC_CLR_INT();
		#if 0 //!defined(MSDC_USE_INT)
/* under construction !*/
		#endif
		#if defined(MSDC_USE_USB_CLK) && defined(__MSDC_SD_MMC__)
		if(gSD->flags & SD_FLAG_USE_USB_CLK)
			UPLL_Disable(UPLL_OWNER_MSDC);
		#endif
		DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_MSDC,PDN_MSDC);		
	}
	else
	{	// ON
		#if 0 // !defined(MSDC_USE_INT)
/* under construction !*/
		#endif		
		DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_MSDC,PDN_MSDC);
		#if defined(MSDC_USE_USB_CLK) && defined(__MSDC_SD_MMC__)
		if(gSD->flags & SD_FLAG_USE_USB_CLK)
			UPLL_Enable(UPLL_OWNER_MSDC);		
		#endif
	}
	// turn on MSDC_PDN bit always recently to cover sleep mode card detection
	#if 0 // !defined(USE_INT26_CARD_DETECTION)
/* under construction !*/
	#endif	
#else
	LSD_PDNControl(ON);
#endif

}
/*************************************************************************
* FUNCTION
*  MSDC_TimeOutHandler
*
* DESCRIPTION
*	Callback function of gpt timer, and launched while MSDC busy for a while

*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_TimeOutHandler(void *parameter)
{
	kal_print("MSDC_TimeOutHandler");
	gMSDC_Handle->is_timeout = KAL_TRUE;	
	#if defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)
	kal_set_eg_events(gMSDC_Handle->MSDC_Events,
				(EVENT_MSIFIRQ|EVENT_DMAIRQ|EVENT_MSRDYIRQ),
				KAL_OR);	
	#else
	kal_set_eg_events(gMSDC_Handle->MSDC_Events,
				(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ),
				KAL_OR);	
	#endif	
}

/*************************************************************************
* FUNCTION
*  MSDC_GetCardStatus
*
* DESCRIPTION
*	Check currently card is present or not.
*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*	msdc_eint_state
*
*
*************************************************************************/
int MSDC_GetCardStatus(void * DriveData, int AckType)
{
	MSDC_HANDLE *msdc = (MSDC_HANDLE *)DriveData;;

	// a debounce mechanism 
    if(kal_query_systemInit() == KAL_FALSE)
    {
        kal_sleep_task(100);        
    }    
	ENTER_CRITICAL();
	msdc->send_ilm = KAL_TRUE;
	EXIT_CRITICAL();
	
	#if defined(__SIM_PLUS__)
	if(!msdc->mIsPresent && current_card == SD_EXT)
		MSDC_PDNControl(KAL_TRUE);	
	#else
	if(!msdc->mIsPresent)
		MSDC_PDNControl(KAL_TRUE);
	#endif
	return 0;
}
/*************************************************************************
* FUNCTION
*  MSDC_SendCardInd
*
* DESCRIPTION
*	Send card indication to the specified module.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_SendCardInd(module_type dest_id,sd_select_enum sel )
{
	#if defined(__MSDC_SD_SDIO__)|| defined(__MSDC2_SD_SDIO__)
	kal_uint32 custom;
	
	custom =  MSDC_GetCustom();
	// only send the ilm while memroy card is plugged in
	if((sel == SD_MSDC1) && (custom & MSDC_SDIO4_SD1) ||
		(sel == SD_MSDC2) && (custom & MSDC_SD4_SDIO1) )
		return;
	#endif // __MSDC_SD_SDIO__

   	#if defined(__SIM_PLUS__)
	if(MSDC_Blk[sel].send_ilm || sel == SD_SIM)
	#else
	if(MSDC_Blk[sel].send_ilm)
	#endif
	{
		ilm_struct *msdc_ilm;
		msdc_card_detect_ind_struct *local;

		local = (msdc_card_detect_ind_struct*)
				   construct_local_para(sizeof(msdc_card_detect_ind_struct), TD_CTRL);	   
		local->media_size = 1;
		#if defined(__SIM_PLUS__) || defined(__MSDC2_SD_MMC__)
		local->media_array = &MSDC_Blk[sel];
		#else
		local->media_array = &MSDC_Blk[0];
		#endif	   
	   	msdc_ilm = allocate_ilm(MOD_DRV_HISR);
	   	msdc_ilm->src_mod_id = MOD_DRV_HISR;
		
		#if defined(__SIM_PLUS__)
		if(sel == SD_EXT)
		{
			msdc_ilm->msg_id = MSG_ID_MSDC_CARD_DETECT_IND;
			MSDC_Blk[sel].send_ilm = KAL_FALSE;
		}
		else
		{
			msdc_ilm->msg_id = MSG_ID_SIM_PLUS_DETECT_IND;
		}
		#else
		msdc_ilm->msg_id = MSG_ID_MSDC_CARD_DETECT_IND;
		MSDC_Blk[sel].send_ilm = KAL_FALSE;
		#endif
		
		msdc_ilm->sap_id = DRIVER_PS_SAP;
		msdc_ilm->local_para_ptr = (local_para_struct *)local;
		msdc_ilm->peer_buff_ptr = NULL;
		msdc_ilm->dest_mod_id = dest_id;
		msg_send_ext_queue(msdc_ilm);
	}
}
/*************************************************************************
* FUNCTION
*  MSDC_GetMediaChanged
*
* DESCRIPTION
*	Check if the media is changed, and clear the status after function call
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC_GetMediaChanged(void* id)
{	
	kal_bool ret;

	ENTER_CRITICAL();
	gMSDC_Handle = (MSDC_HANDLE *)id;		
	ret = (gMSDC_Handle->mIsChanged )?(KAL_TRUE):(KAL_FALSE);
	gMSDC_Handle->mIsChanged = KAL_FALSE;	
	EXIT_CRITICAL();
		
	return ret; 
}
/*************************************************************************
* FUNCTION
*  MSDC_InvertN
*
* DESCRIPTION
* 	Invert the order of bytes eg,
* 	src: 0x01 0x02, len: 2 => dest: 0x02 0x01 
*
* PARAMETERS
*	1. dest: used for store inverted result
*	2. src: source for inverting
*	3. len: bytes for inverting
*
* RETURNS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. make sure dest has the same size with src.
*************************************************************************/
void MSDC_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len)
{
	int i;
	for(i=0; i<len; i++)
		*(dest+len-1-i) = *(src+i);
	
}
/*************************************************************************
* FUNCTION
*  MSDC_Config_INS_WP
*
* DESCRIPTION
* 	Configure the pull up or pull down status for INS and WP pin
*
* PARAMETERS
*	1. ins: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*	2. wp: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*
* RETURNS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. MT6219 can not be configured to PULL up or down. They are all pulled up by IO.
*	2. MT6218B and MT6217, WP is configured with data lines.
*************************************************************************/
void MSDC_Config_INS_WP(msdc_ioctrl_enum ins, msdc_ioctrl_enum wp)
{
	kal_uint32 msdc_cfg,iocon;
		
	gMSDC_Handle->ins_level = ins;
	//#if defined(MT6218B) || defined(MT6217)
	#if defined(DRV_MSDC_INSWP_MT6218B_SERIES)
	// INS use PRCFG0, WP use PRCFG2 together with data line (must pull high)
	msdc_cfg = *(volatile kal_uint32 *)MSDC_CFG;
	msdc_cfg &= ~(MSDC_CFG_PRCFG0);	
	msdc_cfg |= (ins << 22); 
	*(volatile kal_uint32 *)MSDC_CFG = msdc_cfg;	
	//#elif defined(MT6219)||defined(MT6227)||defined(MT6226)||defined(MT6226M) || defined(MT6225)
	#elif defined(DRV_MSDC_INSWP_MT6219_SERIES)
   #ifndef __CUST_NEW__
	GPIO_ModeSetup(MSDC_GPIO_MCINS,1); // enable card insertion signal
	GPIO_ModeSetup(MSDC_GPIO_WP,1); // enable write protection signal		
   #endif /* __CUST_NEW__ */
	if(ins == MSDC_IOCTRL_PULL_DOWN)
		GPIO_PullenSetup(MSDC_GPIO_MCINS, KAL_FALSE);	
	//#elif defined(MT6228)||defined(MT6229)||defined(MT6227)||defined(MT6226)||defined(MT6226M)
	#else
	msdc_cfg = *(volatile kal_uint32 *)MSDC_CFG;
	// INS use PRCFG3, WP use PRCFG0
	msdc_cfg &= ~(MSDC_CFG_PRCFG0);	
	msdc_cfg |= (wp << 22); 
	*(volatile kal_uint32 *)MSDC_CFG = msdc_cfg;
	iocon = *(volatile kal_uint16*)MSDC_IOCON;
	iocon &= ~(MSDC_IOCON_PRCFG3);
	iocon |= (ins<<8);	
	*(volatile kal_uint32 *)MSDC_IOCON = iocon;
	#endif	

	/*busy loop to wait msdc controller recharge*/
	GPTI_BusyWait(1);
}
/*************************************************************************
* FUNCTION
*  MSDC_Initialize
*
* DESCRIPTION
*	Initialize the MS/SD host controller, called only once at drv_init
*
* PARAMETERS*	
*
* RETURNS
*  1: initailized failed 
*  0: successful
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
void MSDC_Initialize(void)
{	
	// turn on the power of controler
	#ifndef DRV_LSD
	DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_MSDC,PDN_MSDC);
	#else
	ASSERT(LSD_Support());
	LSD_Reset();
	LSD_PDNControl(KAL_FALSE);
	#endif
#if defined(__MSDC_MS__)
	MSDC_CLR_BIT32(MSDC_CFG, MSDC_CFG_MSDC);
	gMSDC_Handle->mMSDC_type = MS_CARD;
#elif defined(__MSDC_MSPRO__)
	MSDC_CLR_BIT32(MSDC_CFG, MSDC_CFG_MSDC);
	gMSDC_Handle->mMSDC_type = MSPRO_CARD;	
	FS_MspDrvAll = FS_MspDrv;
#elif defined(__MSDC_SD_MMC__)
	MSDC_SET_BIT32(MSDC_CFG, MSDC_CFG_MSDC)	;
	gMSDC_Handle->mMSDC_type = SD_CARD;
#endif		
	gMSDC_Handle->msdc_clock = MSDC_CLOCK;

	if(gMSDC_Handle->gpt_handle == 0)
		GPTI_GetHandle(&gMSDC_Handle->gpt_handle);
#ifndef DRV_LSD
	#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
	MSDC_Config_INS_WP(MSDC_IOCTRL_PULL_UP,MSDC_IOCTRL_PULL_UP);
	#else
	MSDC_Config_INS_WP(MSDC_IOCTRL_PULL_DOWN,MSDC_IOCTRL_PULL_UP);
	// first time if card is present, no card insertion interrupt generated
	gMSDC_Handle->mIsPresent = KAL_TRUE; 
	#endif
#endif
	// turn on the power of memory card
	MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_VDDPD);
#ifndef DRV_LSD
	MSDC_SET_FIFO(1);
#endif
	
	#if defined(__SIM_PLUS__)
	#if !defined(__CUST_NEW__)
	GPIO_LDO_SWITCH = MSDC_GetLDO_GPIO();
	GPIO_EXT_SD_LDO_SWITCH = MSDC_GetEXTLDO_GPIO();
	GPIO_SIM_MSDC_SWITCH = MSDC_GetSwitch_GPIO();
	#endif
	GPIO_ModeSetup(GPIO_SIM_MSDC_SWITCH, 0); // gpio mode
	GPIO_InitIO(OUTPUT, GPIO_SIM_MSDC_SWITCH);
	/*bewlow comes after JRD SIM+ issue on 2007_03_08, use custom setting instead of fix value*/
	GPIO_WriteIO(MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH);
	/*end of changes of JRD SIM+ issue on 2007_03_08*/
	if(INT_USBBoot() == KAL_TRUE)
	{
		kal_uint32 i = 20;
		DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
		DRV_Reg(SIM_CONF) |= SIM_CONF_SIMSEL;
		DRV_Reg(SIM_CTRL) |= SIM_CTRL_SIMON;
		DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
		GPIO_ModeSetup(GPIO_LDO_SWITCH, 0); // gpio mode
		GPIO_InitIO(OUTPUT, GPIO_LDO_SWITCH);
		MSDC_Blk[SD_SIM].mIsPresent = KAL_TRUE;
		MSDC_Blk[SD_SIM].mIsChanged = KAL_TRUE;		
	}
	#endif
	
#ifndef DRV_LSD	
	#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
	gMSDC_Handle->mIsPresent = KAL_TRUE; 
	#else
	// enable card detection
	*(volatile kal_uint32*)MSDC_PS = MSDC_PS_CDEN|MSDC_PS_PIEN0|MSDC_PS_POEN0;		
	if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
	{
		if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
			gMSDC_Handle->mIsPresent = KAL_FALSE;	
		else
			gMSDC_Handle->mIsPresent = KAL_TRUE;	
	}
	else
	{
		if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
			gMSDC_Handle->mIsPresent = KAL_TRUE;
		else
			gMSDC_Handle->mIsPresent = KAL_FALSE;	
	}
	#endif //__MSDC_NOT_SUPPORT_HOT_PLUG__
#else
	gMSDC_Handle->mIsPresent = KAL_TRUE;
#endif
	
	#if defined(__SIM_PLUS__)
	/*bewlow comes after JRD SIM+ issue on 2007_03_08, give power, this should be temperary solution for jrd*/
	if(MSDC_NO_EXT_LDO != GPIO_EXT_SD_LDO_SWITCH){
		if(KAL_TRUE == gMSDC_Handle->mIsPresent)
			GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
		else if(KAL_FALSE == gMSDC_Handle->mIsPresent)
			GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH);
	}
	/*end of changes of JRD SIM+ issue on 2007_03_08*/
	#endif
	
	#if !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) && !defined(USE_INT26_CARD_DETECTION)
	MSDC_SET_BIT32(MSDC_CFG, MSDC_CFG_PINEN);	
	#endif
			
	#ifdef MSDC_INT
	MSDC_INT_Init();	
	#endif	// end of MSDC_INT
	#ifdef MSDC_DMA
	MSDC_DMAInit();
	#endif	
	#ifdef __MULTI_BOOT__
	if(stack_query_boot_mode() != NORMAL_BOOT)
		gMSDC_Handle->send_ilm = KAL_FALSE;
	else
		gMSDC_Handle->send_ilm = KAL_TRUE;
	#else
		gMSDC_Handle->send_ilm = KAL_FALSE;
	#endif
		
#ifndef DRV_LSD
	DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_MSDC,PDN_MSDC);	
#else
	LSD_PDNControl(KAL_TRUE);
#endif
}

#ifdef  __TST_WRITE_TO_FILE_ONLY__
/*error recording: add this function to do MSDC reset when error recording*/
void MSDC_ErrorRecordingReset(){
	MSDC_ErrorRecordingBlk.gpt_handle = gMSDC_Handle->gpt_handle;
	gMSDC_Handle = &MSDC_ErrorRecordingBlk;
	MSDC_Initialize();
}
#endif

#ifndef DRV_LSD
/*************************************************************************
* FUNCTION
*  BitFieldWrite32
*
* DESCRIPTION
*	Write src to dest at mask position
*
* PARAMETERS
*	dest: destination to be update
*	src: value to be written
*	mask: bit mask
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
// Note: mask must be a continuous area during 32bits. eg,
// dest : 00A30000 , src : BF, mask : 0000BF00.
// after BitFieldCpy, dest : 00A3BF00, copy src to dest at mask position.
void BitFieldWrite32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
	kal_uint8 bit_pos;
	kal_uint32 tmp;
	
	bit_pos = 0;
	tmp = *(kal_uint32 *)dest;
	// get bit positoin
	while(!((mask >> bit_pos++) & 1));	
	//use mask clear the corresponding area	
	tmp &= ~mask;
	//shift src to the corresponding positiion
	src <<= (bit_pos - 1);
	//copy src into destination	
	tmp |= src;
	*(kal_uint32 *)dest = tmp;	
}
#endif
/*************************************************************************
* FUNCTION
*  BitFieldRead32
*
* DESCRIPTION
*	read src to dest at mask position
*
* PARAMETERS
*	dest: destination to store
*	src: value to be written
*	mask: bit mask
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/

// Note: mask must ve continuous area during 32 bits.eg, 
// src : 00A3BF00, mask : 00FF0000
// after BitFieldRead, dest : A3
void BitFieldRead32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
	kal_uint8 bit_pos = 0;
	
	while(!((mask >> bit_pos++) & 1));
	src &= mask;
	*(kal_uint32 *)dest = src >> (bit_pos - 1);
}
// get the bit field value of start_bit with width bits
// note 1) start_bit start from bit 0
//		2) prepare dest with initialized with zeros
//		3) width must less than 32 if using the retrun value as a result
// eg,
// src:00110110, start_bit:2,width:3 => dest:101 
void GetBitFieldN(kal_uint8* dest, kal_uint8* src, kal_uint16 start_bit, kal_uint16 width)
{
	int i;
	kal_uint16 bytes, bits;

	kal_mem_set(dest,0,width/8+1);
	for( i = 0; i < width; i++)
	{	
		bytes = (start_bit+i)/8;
		bits  = (start_bit+i)%8;		
		*(dest+i/8) |= (kal_uint8)(((*(src+bytes) >> bits) & 1) << (i%8));		
	}

	/*in MT6238, address of kal_uint32 is checked strictly, and we don't need the return value of this function*/
	/*change it's return type to void*/
	return ;
}

void MSDC_SetIOCONRegDLT(void)
{
	kal_uint32 factor;
	/*set DLT field according to SCLKF seeting*/
	factor = gMSDC_Handle->msdc_clock/gMSDC_Handle->op_clock;
#if defined(DRV_MSDC_MT6225_SERIES)
	BitFieldWrite32((kal_uint32*)MSDC_IOCON,(kal_uint32)(factor/2),MSDC_IOCON_DLT);
#endif
}

#ifdef MSDC_DMA 
extern kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE);
/*************************************************************************
* FUNCTION
*  MSDC_DMAInit
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_DMAInit(void)
{
#ifdef  __TST_WRITE_TO_FILE_ONLY__
	/*error recording: it mens this functions is called twice, just return*/
	if(KAL_TRUE == INT_QueryExceptionStatus())
   		return;
#endif	
	gMSDC_Handle->msdc_dmaport = DMA_GetChannel(DMA_MSDC);
	gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
	gMSDC_Handle->msdc_menu.TMOD.cycle = 0x4;
	gMSDC_Handle->msdc_menu.master = DMA_MSDC;
	gMSDC_Handle->msdc_menu.addr = NULL;

	gMSDC_Handle->msdc_input.type = DMA_HWRX;
	gMSDC_Handle->msdc_input.size = DMA_LONG;
	gMSDC_Handle->msdc_input.count = 0;
	gMSDC_Handle->msdc_input.menu = &gMSDC_Handle->msdc_menu;

#if defined(__SIM_PLUS__)
	MSDC_Blk[SD_SIM].msdc_dmaport = MSDC_Blk[SD_EXT].msdc_dmaport;
	MSDC_Blk[SD_SIM].msdc_menu.TMOD.burst_mode = KAL_TRUE;
	MSDC_Blk[SD_SIM].msdc_menu.TMOD.cycle = 0x4;
	MSDC_Blk[SD_SIM].msdc_menu.master = DMA_MSDC;
	MSDC_Blk[SD_SIM].msdc_menu.addr = NULL;

	MSDC_Blk[SD_SIM].msdc_input.type = DMA_HWRX;
	MSDC_Blk[SD_SIM].msdc_input.size = DMA_LONG;
	MSDC_Blk[SD_SIM].msdc_input.count = 0;
	MSDC_Blk[SD_SIM].msdc_input.menu = &MSDC_Blk[SD_SIM].msdc_menu;
	//MSDC_Blk[SD_SIM].msdc_menu = MSDC_Blk[SD_EXT].msdc_menu;
	//MSDC_Blk[SD_SIM].msdc_input = MSDC_Blk[SD_EXT].msdc_input	;
#endif
	//msdc_input.callback = MSDC_DMA_Callback;	
}
/*************************************************************************
* FUNCTION
*  MSDC_DMATransfer
*
* DESCRIPTION
*	MSDC using DAM for data transfer 
*
* PARAMETERS
*	adrs: data buffer
*	count: bytes to be transfered
*	isTx: ture for move data from MSDC to data buffer and vise versa
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_DMATransferFirst(kal_uint32 adrs,kal_uint32 count, kal_bool isTx)
{
#ifndef DRV_LSD
	kal_uint32 total_count;
	kal_bool is_aligned, is_poll;

	DMA_Stop(gMSDC_Handle->msdc_dmaport);	
	gMSDC_Handle->msdc_menu.addr = adrs;
	
	
	if(isTx)
	{
		gMSDC_Handle->timeout_period = (50 + (count>>5));
		gMSDC_Handle->msdc_input.type = DMA_HWTX;		
		if(count <= MSDC_WRITE_THD_POLL)
		//if(0)
		{
			gMSDC_Handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;			
		}
		else
		{
			gMSDC_Handle->msdc_input.callback = MSDC_DMA_Callback;
			is_poll = KAL_FALSE;
		}
	}
	else
	{
	    gMSDC_Handle->timeout_period = (50 + (count>>7));
		gMSDC_Handle->msdc_input.type = DMA_HWRX;	
		if(count <= MSDC_READ_THD_POLL)
		//if(0)
		{
			gMSDC_Handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;
		}
		else
		{
			gMSDC_Handle->msdc_input.callback = MSDC_DMA_Callback;
			is_poll = KAL_FALSE;
		}
	}

	if(kal_query_systemInit() == KAL_TRUE 
#ifdef  __TST_WRITE_TO_FILE_ONLY__	/*error recording: considering error recording additionally*/
		|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
	)
	{
		gMSDC_Handle->msdc_input.callback = NULL;
		is_poll = KAL_TRUE;
	}	
	if(adrs%4 == 0)
	{
		is_aligned = KAL_TRUE;
		total_count = count;
	}
	else
	{
		is_aligned = KAL_FALSE;
		total_count = count<<2;
	}
	gMSDC_Handle->total_count = total_count;
	gMSDC_Handle->is_poll = is_poll;
	gMSDC_Handle->is_aligned = is_aligned;
	{
		if(is_aligned)
		{
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO(4);
			#else
			gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_FALSE;
			#endif
			
			gMSDC_Handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
			gMSDC_Handle->msdc_input.size = DMA_LONG;		
			DMA_Config_B2W(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE,KAL_FALSE);
			gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count*4;
		}
		else
		{
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO(1);
			#else
			
			gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
			#endif
			gMSDC_Handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
			gMSDC_Handle->msdc_input.size = DMA_BYTE;
			DMA_Config_B2W(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE,KAL_TRUE);
			gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count;
		}
		
	}
#endif
}
kal_uint32 MSDC_DMATransferFinal(void)
{
#ifndef DRV_LSD
	kal_uint32 total_count = gMSDC_Handle->total_count, t1;
	kal_bool is_poll = gMSDC_Handle->is_poll;
	kal_bool is_aligned = gMSDC_Handle->is_aligned;

	t1 = drv_get_current_time();
	if(gMSDC_Handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
		gMSDC_Handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;
	MSDC_START_TIMER(gMSDC_Handle->timeout_period);
	if(is_poll)
	{
		while(IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport) && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;
		}
	}
	else
	{
		kal_uint32 flags;
		kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,(EVENT_DMAIRQ),KAL_OR_CONSUME,&flags,KAL_SUSPEND);				
	}				
	MSDC_STOP_TIMER();
	if(IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport) && gMSDC_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	total_count -= gMSDC_Handle->msdc_input.count;
	if(total_count == 0)
		return MSDC_NOERROR;
	
	while(1)
	{
		if(is_aligned)
		{
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO(4);
			#else
			gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_FALSE;
			#endif
			
			gMSDC_Handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
			gMSDC_Handle->msdc_input.size = DMA_LONG;		
			DMA_Config_B2W(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE,KAL_FALSE);
			gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count*4;
			gMSDC_Handle->timeout_period = 1 + (gMSDC_Handle->msdc_input.count>>7);
		}
		else
		{
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO(1);
			#else
			gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
			#endif
			gMSDC_Handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
			gMSDC_Handle->msdc_input.size = DMA_BYTE;
			DMA_Config_B2W(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE,KAL_TRUE);
			gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count;
			gMSDC_Handle->timeout_period = 1 + (gMSDC_Handle->msdc_input.count>>9);
		}
		
		// wait until running bit clr
		if(gMSDC_Handle->msdc_input.type == DMA_HWTX)
			gMSDC_Handle->timeout_period <<= 2 ;
		if(gMSDC_Handle->mMSDC_type == MMC_CARD)
			gMSDC_Handle->timeout_period <<= 1;
		
		t1 = drv_get_current_time();
		MSDC_START_TIMER(gMSDC_Handle->timeout_period);
		if(is_poll)
		{
			while(IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport) && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
			{
				if(drv_get_duration_ms(t1) > gMSDC_Handle->timeout_period*11)
					gMSDC_Handle->is_timeout = KAL_TRUE;				
			}
		}
		else
		{
			kal_uint32 flags;
			kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,(EVENT_DMAIRQ),KAL_OR_CONSUME,&flags,KAL_SUSPEND);				
		}				
		MSDC_STOP_TIMER();
		if(IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport) && gMSDC_Handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;
		total_count -= gMSDC_Handle->msdc_input.count;
		if(total_count == 0)
			break;		
	}
	
	return MSDC_NOERROR;
#else
	return MSDC_NOERROR;
#endif
}

#endif // DMA

#ifdef MSDC_INT

#ifdef USE_INT26_CARD_DETECTION
void MSDC_CardDetect_LISR(void)
{
	IRQMask(IRQ_MSDC_CD_CODE);
	gMSDC_Handle->mIsChanged = KAL_TRUE;
	drv_active_hisr(DRV_MSDC_HISR_ID);
}
#endif //USE_INT26_CARD_DETECTION


#ifdef DRV_LSD
kal_uint32 MSDC_CARD_INSERT_COUNTER, MSDC_CARD_REMOVE_COUNTER;
kal_uint32 notifiedFMT;//this variable is to sync the state, since we only allow FMT get disk infor to be the first operation that access SD


void MSDC_LSD_HISR(void)
{
	static kal_bool pre_IsPresent = KAL_TRUE; // it works only at first time

	if(pre_IsPresent)
			pre_IsPresent = gMSDC_Handle->mIsPresent;

	if(LSD_cardInsertion == LSD_cardDetection())
	{
		gMSDC_Handle->mIsPresent = KAL_TRUE;	
		MSDC_CARD_INSERT_COUNTER ++;
	}
	else if(LSD_cardRemoval == LSD_cardDetection())
	{
		gMSDC_Handle->mIsPresent = KAL_FALSE;
		MSDC_CARD_REMOVE_COUNTER++;
	}
	else
		ASSERT(0);

	// if the card is present during power on, then the 
	// card detection interrup of INT26 will always generated. This interrupt should be ignored.		
	if(pre_IsPresent && gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized )
	{			
		pre_IsPresent = KAL_FALSE;
		gMSDC_Handle->mIsInitialized = KAL_TRUE;		
		return;			
	}
	else
		gMSDC_Handle->mIsInitialized = KAL_FALSE;

	if(gMSDC_Handle->mIsPresent == KAL_FALSE)
	{
		MSDC_CLR_FIFO();
		MSDC_CLR_INT();
		MSDC_CLR_INT();
		//TurnOffMSDC();
	}

	if(gMSDC_Handle->mIsPresent)
	{
		notifiedFMT = 0;
	}
	
	#if !defined(FMT_NOT_PRESENT)
		MSDC_SendCardInd(MOD_FMT, SD_EXT);		
	#endif
	/*
	if(LSD_cardInsertion == LSD_cardDetection()){
		MSDC_CARD_INSERT_COUNTER ++;
	}
	else if(LSD_cardRemoval == LSD_cardDetection()){
		MSDC_CARD_REMOVE_COUNTER++;
	}
	else
		ASSERT(0);
	*/
}


/*this function will be called once by FMT while booting up, used to let FMT send meesage to itself*/
void NotifyFMTWhenCardPresent(void)
{
	/*in LSD solution, mIsPresent is true without card plugging out, so we aslo have to check initialied*/
	if(gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized){
		gMSDC_Handle->send_ilm = KAL_TRUE;
	#if !defined(FMT_NOT_PRESENT)
		MSDC_SendCardInd(MOD_FMT, SD_EXT);
	#endif
	}
	
}

void MSDC_unsealMountOperation(void)
{
	/*notifiedFMT may be modified by FMT and MMI tasks, but it is no need to protect this, any task that preempt FMT just get mount fail*/
	if(1 == notifiedFMT){/*FMT may call this function no matter card exits or not*/
		notifiedFMT = 2;
	}
	
}
#endif

/*************************************************************************
* FUNCTION
*  MSDC_INT_Init
*
* DESCRIPTION
*	Initialize MSDC's interrupt
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_INT_Init(void)
{
#ifdef  __TST_WRITE_TO_FILE_ONLY__
   /*error recording: it mens this functions is called twice, just return*/
   if(KAL_TRUE == INT_QueryExceptionStatus())
   	return;
#endif
   gMSDC_Handle->MSDC_Events = kal_create_event_group("MSDC Events");

#ifdef __SIM_PLUS__
	MSDC_Blk[SD_SIM].MSDC_Events = gMSDC_Handle->MSDC_Events;
#endif

#ifndef DRV_LSD
   DRV_Register_HISR(DRV_MSDC_HISR_ID, MSDC_HISR_Entry);
   IRQ_Register_LISR(IRQ_MSDC_CODE, MSDC_LISR,"MSDC ISR");
   IRQSensitivity(IRQ_MSDC_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_MSDC_CODE);
   
	// enable MSDC interrupt
	MSDC_CLR_INT();	
	#if !defined(MSDC_USE_INT)
	MSDC_DISABLE_INT();// (active)turn off other interrupt event except pin interrupt		
	#else
	MSDC_ENABLE_INT();// (deactive)
	#endif
	
	#ifdef USE_INT26_CARD_DETECTION
   // for card detection
   IRQ_Register_LISR(IRQ_MSDC_CD_CODE, MSDC_CardDetect_LISR,"MSDC CD ISR");
   IRQSensitivity(IRQ_MSDC_CD_CODE,EDGE_SENSITIVE);
   IRQUnmask(IRQ_MSDC_CD_CODE);
	#if !defined(MSDC_USE_INT)
	IRQMask(IRQ_MSDC_CODE);
	#endif
   #endif //USE_INT26_CARD_DETECTION
#else
#ifndef __MSDC_NOT_SUPPORT_HOT_PLUG__
    LSD_HISR_Registration();
#endif   
#endif   
}
void MSDC_LISR(void)
{
#ifndef DRV_LSD
	IRQMask(IRQ_MSDC_CODE);
	drv_active_hisr(DRV_MSDC_HISR_ID);
#endif
}
/*************************************************************************
* FUNCTION
*  MSDC_HISR_Entry
*
* DESCRIPTION
*	Set corresponding enevt and wake up waiting task.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_HISR_Entry(void)
{
	register kal_uint16 msdc_int = 0;

#if defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)
	kal_uint16 msc_sta;

	FS_MspDrvAll = FS_MspDrv;
	#if defined (USE_INT26_CARD_DETECTION)
	if(gMSDC_Handle->mIsChanged == KAL_TRUE)
	{
		static kal_bool pre_IsPresent = KAL_TRUE; // it works only at first time
		
		if(pre_IsPresent)
			pre_IsPresent = gMSDC_Handle->mIsPresent;
		#if defined(MSDC_USE_INT)
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,
				(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ),
				KAL_OR);		
		#endif	
		TurnOnMSDC();
		if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
			else
				gMSDC_Handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_TRUE;
			else
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
		}
		// use INT26 as the card detection, if the card is present during power on, then the 
		// card detection interrup of INT26 will always generated. This interrupt should be ignored.		
		if(pre_IsPresent && gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized )
		{			
			pre_IsPresent = KAL_FALSE;
			gMSDC_Handle->mIsInitialized = KAL_TRUE;
			IRQUnmask(IRQ_MSDC_CD_CODE); 			
			return;			
		}
		else
			gMSDC_Handle->mIsInitialized = KAL_FALSE;					
		if(gMSDC_Handle->mIsPresent == KAL_FALSE)
		{
			MSDC_CLR_FIFO();
			MSDC_CLR_INT();
			MSDC_CLR_INT();
			//TurnOffMSDC();
			DMA_Stop(gMSDC_Handle->msdc_dmaport);		
		}
		#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_EXT);			
		#endif
		IRQUnmask(IRQ_MSDC_CD_CODE); 
		return;
	}
	#endif //USE_INT26_CARD_DETECTION	
	TurnOnMSDC();
	msc_sta = *(volatile kal_uint16*)MSC_STA;
	if(msc_sta & MSC_STA_SIF)
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_MSIFIRQ,KAL_OR);
	else
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_MSRDYIRQ,KAL_OR);

	msdc_int = *(volatile kal_uint16*)MSDC_INTR;
	#if !defined(USE_INT26_CARD_DETECTION)
	if(msdc_int & MSDC_INT_PINIRQ)
	{
		gMSDC_Handle->mIsInitialized = KAL_FALSE;	
		gMSDC_Handle->mIsChanged = KAL_TRUE;		
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,
			(EVENT_MSIFIRQ|EVENT_DMAIRQ|EVENT_MSRDYIRQ),
			KAL_OR);								
		if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
			else
				gMSDC_Handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_TRUE;
			else
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
		}
	#ifdef MSDC_MUST_RECORD_PLUGOUT
		if(KAL_FALSE == gMSDC_Handle->mIsPresent)
       		MSDC_everPlugOut = KAL_TRUE;
       #endif

		if(gMSDC_Handle->mIsPresent == KAL_FALSE)
		{			
			MSDC_CLR_FIFO();
			MSDC_CLR_INT();
			MSDC_CLR_INT();
			//TurnOffMSDC();
			DMA_Stop(gMSDC_Handle->msdc_dmaport);		
		}		//dbg_print("MSDC_HISR present %d \r\n",gMSDC_Handle->mIsPresent);					
		#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_EXT);		
		#endif		
		//MSDC_PDNControl(KAL_TRUE);	
	}
	#endif //USE_INT26_CARD_DETECTION
#else // sd/mmc
	#if defined (USE_INT26_CARD_DETECTION)
	#if defined(__SIM_PLUS__)
	{
		
		MSDC_Blk[SD_EXT].mIsInitialized = KAL_FALSE;				
		MSDC_Blk[SD_EXT].mIsChanged = KAL_TRUE;				
		if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
		{
			if(MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
				MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;	
			else
				MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
				MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;
			else
				MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;	
		}
		/*bewlow comes after JRD SIM+ issue on 2007_03_08, give power, this should be temperary solution for jrd*/
		if(MSDC_NO_EXT_LDO != GPIO_EXT_SD_LDO_SWITCH){
			if(KAL_TRUE == gMSDC_Handle->mIsPresent)
				GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
			else if(KAL_FALSE == gMSDC_Handle->mIsPresent)
				GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH);
		}
		/*end of changes of JRD SIM+ issue on 2007_03_08*/
		if(MSDC_Blk[SD_EXT].mIsPresent == KAL_FALSE && current_card == SD_EXT)
		{
			MSDC_CLR_FIFO();
			MSDC_CLR_INT();
			MSDC_CLR_INT();
			DMA_Stop(gMSDC_Handle->msdc_dmaport);		
		}	
	#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_EXT);		
	#endif	
	#else // __SIM_PLUS__
	if(gMSDC_Handle->mIsChanged == KAL_TRUE)
	{	
		static kal_bool pre_IsPresent = KAL_TRUE; // it works only at first time
		
		if(pre_IsPresent)
			pre_IsPresent = gMSDC_Handle->mIsPresent;
		#if defined(MSDC_USE_INT)
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,
				(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ),
				KAL_OR);		
		#endif	
		TurnOnMSDC();
		if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
			else
				gMSDC_Handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_TRUE;
			else
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
		}
		// use INT26 as the card detection, if the card is present during power on, then the 
		// card detection interrup of INT26 will always generated. This interrupt should be ignored.		
		if(pre_IsPresent && gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized )
		{			
			pre_IsPresent = KAL_FALSE;
			gMSDC_Handle->mIsInitialized = KAL_TRUE;
			IRQUnmask(IRQ_MSDC_CD_CODE); 			
			return;			
		}
		else
			gMSDC_Handle->mIsInitialized = KAL_FALSE;					
	#ifdef MSDC_MUST_RECORD_PLUGOUT
		if(KAL_FALSE == gMSDC_Handle->mIsPresent)
       		MSDC_everPlugOut = KAL_TRUE;
       #endif

		if(gMSDC_Handle->mIsPresent == KAL_FALSE)
		{
			MSDC_CLR_FIFO();
			MSDC_CLR_INT();
			MSDC_CLR_INT();
			//TurnOffMSDC();
			DMA_Stop(gMSDC_Handle->msdc_dmaport);		
		}
		#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_EXT);		
		#endif
		#endif // __SIM_PLUS__
		IRQUnmask(IRQ_MSDC_CD_CODE); 
		return;
	}
	#endif //USE_INT26_CARD_DETECTION
	TurnOnMSDC();		
	msdc_int = *(volatile kal_uint16*)MSDC_INTR;	
	#if defined(MSDC_USE_INT)
	if(msdc_int & MSDC_INT_SDCMDIRQ)
	{	
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDCMDIRQ,KAL_OR);
	}
	if(msdc_int & MSDC_INT_SDDATIRQ)
	{
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDDATIRQ,KAL_OR);
		
	}
	if(msdc_int & MSDC_INT_SDMCIRQ)
	{
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDMCIRQ,KAL_OR);
		
	}
	if(msdc_int & MSDC_INT_SDR1BIRQ)
	{
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_OR);		
	}
	#endif // MSDC_USE_INT
        	#if defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)
	/*SDIO*/
	if(msdc_int & MSDC_INT_SDIOIRQ)
	{	    
      SDIO_HISR_Entry();		   		 
	} 
	#endif 	
	#if !defined(USE_INT26_CARD_DETECTION)
	#if defined(__SIM_PLUS__)
	if(msdc_int & MSDC_INT_PINIRQ)
	{
		MSDC_Blk[SD_EXT].mIsInitialized = KAL_FALSE;				
		MSDC_Blk[SD_EXT].mIsChanged = KAL_TRUE;				
		if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
		{
			if(MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
				MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;	
			else
				MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
				MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;
			else
				MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;	
		}
		/*bewlow comes after JRD SIM+ issue on 2007_03_08, give power, this should be temperary solution for jrd*/
		if(MSDC_NO_EXT_LDO != GPIO_EXT_SD_LDO_SWITCH){
			if(KAL_TRUE == gMSDC_Handle->mIsPresent)
				GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
			else if(KAL_FALSE == gMSDC_Handle->mIsPresent)
				GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH);
		}
		/*end of changes of JRD SIM+ issue on 2007_03_08*/
		if(MSDC_Blk[SD_EXT].mIsPresent == KAL_FALSE && current_card == SD_EXT)
		{
			MSDC_CLR_FIFO();
			MSDC_CLR_INT();
			MSDC_CLR_INT();
			DMA_Stop(gMSDC_Handle->msdc_dmaport);		
		}	
	#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_EXT);		
	#endif	
	#else // __SIM_PLUS__
	if(msdc_int & MSDC_INT_PINIRQ)
	{
		gMSDC_Handle->mIsInitialized = KAL_FALSE;				
		gMSDC_Handle->mIsChanged = KAL_TRUE;				
		#if defined(MSDC_USE_INT)
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,
				(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ),
				KAL_OR);		
		#endif						
		if(*(volatile kal_uint16*)MSDC_PS & MSDC_PS_PIN0)
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
			else
				gMSDC_Handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
				gMSDC_Handle->mIsPresent = KAL_TRUE;
			else
				gMSDC_Handle->mIsPresent = KAL_FALSE;	
		}
	#ifdef MSDC_MUST_RECORD_PLUGOUT
		if(KAL_FALSE == gMSDC_Handle->mIsPresent)
       		MSDC_everPlugOut = KAL_TRUE;
       #endif
		if(gMSDC_Handle->mIsPresent == KAL_FALSE)
		{
			MSDC_CLR_FIFO();
			MSDC_CLR_INT();
			MSDC_CLR_INT();
			//TurnOffMSDC();
			DMA_Stop(gMSDC_Handle->msdc_dmaport);		
		}	
		#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_EXT);		
		#endif
		#endif // __SIM_PLUS__
		// Set the power down bit too fast will cause MSDC failed to detect next card plug in/out
		// So, move it to GetCardStatus
		//MSDC_PDNControl(KAL_TRUE);
	}	
	#endif // USE_INT26_CARD_DETECTION
	#endif // MSDC_MS
#ifndef DRV_LSD
	IRQUnmask(IRQ_MSDC_CODE);				
#endif
}
/*************************************************************************
* FUNCTION
*  MSDC_DMA_Callback
*
* DESCRIPTION
*	Call back while DMA has done the data transfer.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_DMA_Callback(void)
{
	kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_DMAIRQ,KAL_OR);
}

#if defined(__SIM_PLUS__)
void MSDC_Switch_Card(sd_select_enum sel)
{
	if(current_card == sel)
		return;
	
	ENTER_CRITICAL();
	current_card = sel;	

	
	/*bewlow comes after JRD SIM+ issue on 2007_03_08, use custom setting instead of fix value*/
	if(GPIO_SELECT_MSDC == sel)
		GPIO_WriteIO(MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH);
	else if(GPIO_SELECT_SIM == sel)
		GPIO_WriteIO(1-MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH);
	else
		ASSERT(0);
	/*end of changes of JRD SIM+ issue on 2007_03_08*/
	
	gMSDC_Handle = &MSDC_Blk[sel];
	gSD = &gSD_blk[sel];
	EXIT_CRITICAL();
	
	if(MSDC_Blk[SD_EXT].mIsInitialized || MSDC_Blk[SD_SIM].mIsInitialized)
	{
		//MSDC_SetClock(gMSDC_Handle->op_clock);
		if(gSD->bus_width == 4)
			MSDC_SET_BIT32(SDC_CFG,SDC_CFG_MDLEN);
		else
			MSDC_CLR_BIT32(SDC_CFG,SDC_CFG_MDLEN);
	}		
}
#endif

#endif //end of MSDC_INT
#else
#ifdef DRV_LSD
void MSDC_LSD_HISR(void)
{
}
#endif
#endif // end of  (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
