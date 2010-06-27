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
 *    sim_sw_comm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for different SIM drivers on multiple SIM solution.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SIM_SW_H
#define _SIM_SW_H



//#define __30V_ONLY_ME__
//#define __18V_ONLY_ME__
//#define __18V_30V_ME__

//#if ( (!defined(MT6208)) && (!defined(FPGA)) )
#if !defined(DRV_SIM_MT6208_SERIES)
/* SIM_ADDDMA & NoT0CTRL can't active concurrently */
#define  SIM_ADDDMA
//#define  NoT0CTRL

/* SIM Format */
#define SIM_direct      0
#define SIM_indirect    1

/* SIM Power */
#define SIM_30V          RESET_30V
#define SIM_18V          RESET_18V

#define CMD_RECBUFSIZE  13
/*DMA setting, such usb*/
/* Size = 8bit, sinc en, dinc disable, hw management, 1 trans/dma cycle, USB master,Interrupt disable */
#define DMA_CON_SimTxNormal   0x0074
/* Size = 8bit, sinc disable, dinc enable, hw management, 1 trans/dma cycle, USB master,Interrupt disable */
#define DMA_CON_SimRxNormal   0x0078

/* SIM State   */
#define  SIM_WAIT_FOR_ATR     0       /* reset SIM card and wait ATR */
#define 	SIM_PROCESS_ATR      1        /* receiving ATR data */
#define 	SIM_PROCESS_PTS      2        /* receiving PTS response data */
#define 	SIM_PROCESSCMD       3
#define 	SIM_SERIOUSERR       4        /* serous error due to txerr*/
#define  SIM_PWROFF           5
#define  SIM_WaitRejectDone   6


/* SIM Miner State   */
#ifdef NoT0CTRL
#define SIMD_CmdIdle          0
#define SIM_WaitProcByte      1
#define SIM_AckDataState      2
#define SIM_NAckDataState     3
#define SIM_WaitSWByte        4
#endif /*NoT0CTRL*/
   /*just for clock stop mode*/
#define SIM_ProcessClk        5
#define SIM_StopClk           6
#define SIM_WaitCmdEnd        7


/* Event */
#define  ATR_END		   0x0010
#define  PTS_END		   0x0008
#define  CMD_END	      0x0004
#define  RST_READY	   0x0002
#define  CLK_PROC       0x0020
#define  ACTIVATE_DONE	0x0040
/*#define INIRET		0x0001*/

/*ATR data define*/
#define TAMask		0x0010
#define TBMask		0x0020
#define TCMask		0x0040
#define TDMask		0x0080

/* Result */
#define SIM_SUCCESS              SIM_NO_ERROR
#define SIM_NOREADY              SIM_NO_INSERT
#define SIM_CARDERR              SIM_CARD_ERROR
#define SIM_INITXERR             5
#define SIM_INIPTSERR            6
#define SIM_CMDTXERR             7  /* parity error */
#define SIM_CMDRECERR            8
#define SIM_CMDTOUT              9
#define SIM_CLKPROC              10

#define SW1_GET_RESP_SIM			0x9f
#define SW1_GET_RESP_USIM			0x61
#define SW1_RESEND_USIM				0x6c
#define LEN_INDEX						4		// index to the P3 of command header
#define LEN_OF_CMD					5
#define GET_RESP_CLA_SIM			0xa0
#define GET_RESP_CLA_USIM			0x00
#define SW1_WARN1						0x62
#define SW1_WARN2						0x63
#define STATUS_OK						0x9000
#define STATUS_FAIL					0x00

#define Speed372                 0
#define Speed64                  1
#define Speed32                  2

typedef kal_uint16 sim_status;

#define MAX_SIM_ERROR_LINE           4

#ifdef SIM_DBG_OPTION_ENABLE
#define SIM_ASSERT(_condition) \
   {                             \
      ASSERT(_condition);        \
   }
#else   /*!SIM_DBG_OPTION_ENABLE*/
#define SIM_ASSERT(_condition) \
   {                             \
      if (!(_condition))         \
      {                          \
         sim_assert(__LINE__); \
      }                          \
   }
#endif   /*SIM_DBG_OPTION_ENABLE*/

typedef enum
{
	SIM_PROTOCOL,
	USIM_PROTOCOL
}sim_protocol_app_enum;

typedef enum
{
	T0_PROTOCOL,
	T1_PROTOCOL,
	UNKNOWN_PROTOCOL
}sim_protocol_phy_enum;

typedef enum{
	UNKNOWN_POWER_CLASS = 0,
	CLASS_A_50V = 1,
	CLASS_B_30V = 2,
	CLASS_AB 	= 3,
	CLASS_C_18V = 4,
	ClASS_BC		= 6,
	CLASS_ABC	= 7
}sim_power_enum;

typedef enum{
	CLOCK_STOP_NOT_SUPPORT 	= 0x0,
	CLOCK_STOP_LOW 			= 0x40,
	CLOCK_STOP_HIGH 			= 0x80,
	CLOCK_STOP_ANY				= 0xc0,
	CLOCK_STOP_MSK				= 0xc0,
	CLOCK_STOP_UNKONW			= 0x0f
}sim_clock_stop_enum;

typedef enum{
	SPEED_372,
	SPEED_64,
	SPEED_32,
	SPEED_16
}sim_speed_enum;

typedef enum{
	SIM_DIRECT,
	SIM_INVERSE
}sim_dir_enum;

typedef enum{
	usim_case_1 = 1,
	usim_case_2,
	usim_case_3,
	usim_case_4
}usim_cmd_case_enum;

typedef struct {
	kal_uint32* ptr;
	kal_uint32 size;
}sim_nvram_param_struct;

typedef struct{
	sim_power_enum power;
	sim_speed_enum speed;		
	sim_clock_stop_enum clock_stop;	
	sim_protocol_app_enum app_proto;
	sim_protocol_phy_enum phy_proto;
	kal_bool T0_support;	// if T0 is supported
	kal_bool T1_support;	// if T1 is supported	
	kal_uint8 hist_index; // index to the historical char of ATR
	kal_uint8 *ATR;
}sim_info_struct;

typedef struct
{
	kal_uint8    State;
	kal_uint8    Data_format;      /*SIM_direct,SIM_indirect*/
	kal_uint8    Power;            /*SIM_3V,SIM_5V*/
	kal_uint8    recData[40];     /*PTS or ATR data*/
	kal_bool     recDataErr;
	kal_uint16   recDataLen;       /* for command, ATR process   */
	kal_uint8    result;           /* for ATR, command, RST   */
	kal_uint32   EvtFlag;
	sim_env      SIM_ENV;
#ifndef SIM_ADDDMA
	kal_uint8    *txbuffer;        /* only used for no DMA */
	kal_uint16   txsize;           /* only used for no DMA */
	kal_uint16   txindex;          /* only used for no DMA */
	kal_uint8    *rxbuffer;        /* only used for no DMA */
#ifdef   NoT0CTRL
   kal_uint16   recsize;
   kal_uint8    INS;
   kal_uint8    SW1;
   kal_uint8    SW2;
#endif	/*NoT0CTRL*/
#endif   /*SIM_ADDDMA*/
/*add for clock stop mode*/
   kal_uint8    cmdState;         /* only used for no T0CTRL, and for clock stop */
   kal_uint8    Speed;            /*Speed372,Speed64,Speed32*/
   kal_bool     clkStop;          /*Clok Stop Enable*/
   kal_bool     clkStopLevel;     /*Clok Stop level*/
   kal_bool     reject_set_event;
   kal_bool     event_state;
   kal_uint8    initialPower;
   sim_card_speed_type  sim_card_speed;
	kal_hisrid        hisr;             /*SIM HISR*/
  	kal_eventgrpid    event;      /*SIM Event*/
  	
  	sim_protocol_app_enum app_proto;
  	kal_bool 	timeout;
  	usim_cmd_case_enum cmd_case;
	kal_bool 	is_err;	// sim command has error once.

	/*following variables are get from global variables for 2 SIM projects*/
  	kal_uint32			TOUTValue;
  	kal_uint8			TOUT_Factor;
  	kal_uint8			sim_dmaport;
  	kal_uint8			reset_index;
  	DMA_HWMENU	sim_menu;
  	DMA_INPUT		sim_input;
  	kal_bool			TS_HSK_ENABLE;
  	kal_bool			sim_ATR_fail;
  	kal_bool			PTS_check;
  	kal_uint8			PTS_data[4];

}Sim_Card;

#define GET_SIM_CB(a) &SimCard_cb[a]

#define SIM_SetRXRetry(_RXRetry)\
{\
	kal_uint16 _Retry;\
	_Retry = DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK);\
	_Retry &= ~SIM_RETRY_RXMASK;\
	_Retry |= _RXRetry;\
	DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), _Retry);\
}

#define SIM_SetTXRetry(_TXRetry) \
{\
	kal_uint16 	_Retry;\
	_Retry = DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK);\
	_Retry &= ~SIM_RETRY_TXMASK;\
	_Retry |= (_TXRetry<<8);\
	DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), _Retry);\
}

#define SIM_ObtainSW(_SW) \
{\
   kal_uint16 _SW1;\
   kal_uint16 _SW2;\
   _SW1 = DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK);\
   _SW2 = DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK);\
   _SW = (_SW2 | (_SW1 << 8));\
}

//#define SIM_SetIMP3(_IMP3)    *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK) = _IMP3
#define SIM_SetIMP3(_IMP3)    DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), _IMP3)

//#define SIM_SetCmdINS(_INS)   *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_INS_MTK) = _INS
#define SIM_SetCmdINS(_INS)   DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_INS_MTK), _INS)

//#define SIM_SetAtime(_ATIME)  *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_ATIME_MTK) = _ATIME
#define SIM_SetAtime(_ATIME)  DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_ATIME_MTK), _ATIME)

//#define SIM_SetDtime(_DTIME)  *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_DTIME_MTK) = _DTIME
#define SIM_SetDtime(_DTIME)  DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_DTIME_MTK), _DTIME)

//#define SIM_FIFO_Flush()      *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK) = 0x01
#define SIM_FIFO_Flush()      DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0x01)

#define SIM_Reject(simInterface) \
{\
   SIM_DisAllIntr(simInterface);\
   if (DRV_Reg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))&SIM_CTRL_SIMON)\
   {\
   sim_MT6302_addMsg(SIM_MT6302_DRIVER_DEACT, simInterface, 2, 0);\
      SimCard->State = SIM_PWROFF;\
      DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_SIMOFF);\
      SIM_FIFO_Flush();\
      if(KAL_FALSE == sim_MT6302_QueryNeedManualControl()){\
      DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_SIMON);\
      sim_MT6302_VCCCtrl(simInterface, 0);\
	}\
      	else{\
      		sim_MT6302_manualDeactive(simInterface);\
      	}\
	}\
	else\
	{\
      sim_PDNEnable(simInterface);\
      if(SimCard->reject_set_event)\
         SIM_SetEvent(SimCard,SIM_NOREADY);\
	}\
}

#define SIM_Active()    DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0x0001)


#define SIM_WaitEvent(_SIMCARD,_flag, _unmaskSIMIntr) \
{\
   kal_uint32 _event_group;\
   extern void sim_dump_error_line(void);\
   _SIMCARD->event_state = KAL_TRUE;\
   _SIMCARD->EvtFlag = _flag;\
   sim_workingTaskWaiting = KAL_TRUE;\
   if(KAL_TRUE == _unmaskSIMIntr)\
   	IRQUnmask(IRQ_SIM_CODE);\
	kal_retrieve_eg_events(_SIMCARD->event,_flag,KAL_OR_CONSUME,&_event_group,KAL_SUSPEND);\
	sim_workingTaskWaiting = KAL_FALSE;\
	sim_dump_error_line();\
}

#define SIM_SetEvent(_SIMCARD,_result)   \
{\
   _SIMCARD->result = _result;\
   _SIMCARD->event_state = KAL_FALSE;\
   if(0 == _SIMCARD->EvtFlag)\
   	kal_set_eg_events(_SIMCARD->event,CMD_END,KAL_OR);\
   else\
   kal_set_eg_events(_SIMCARD->event,_SIMCARD->EvtFlag,KAL_OR);\
   DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF);\
   sim_MT6302_addMsg(0x12345678, _SIMCARD->EvtFlag, __LINE__, drv_get_current_time());\
}

//#define SIM_NotifyCARDisHALTEN()       *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_HALTEN
#define SIM_NotifyCARDisHALTEN()       DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HALTEN)
//#define SIM_T0CtrlEnable()             *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_T0EN
#define SIM_T0CtrlEnable()             DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_T0EN)
//#define SIM_T0CtrlDisable()            *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_T0EN
#define SIM_T0CtrlDisable()            DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_T0EN)
//#define SIM_FlowCtrlEnable()             *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_HFEN
#define SIM_FlowCtrlEnable()             DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HFEN)
//#define SIM_FlowCtrlDisable()            *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_HFEN
#define SIM_FlowCtrlDisable()            DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HFEN)

//#define SIM_DisIntr(_Intr)            *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK) &= ~_Intr
#define SIM_DisIntr(_Intr)            DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), _Intr)
#define SIM_ActiveClk(simInterface)       \
{\
   sim_PDNDisable(simInterface);\
   DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
}

#define SIM_Idle(_level, simInterface)   \
{\
	if (_level == KAL_TRUE)\
	{\
		DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
		DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	else\
	{\
	    DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
	    DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	sim_PDNEnable(simInterface);\
}


#define SIM_FIFO_GetLev(a)  (*(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK) & SIM_COUNT_MASK)
//#define SIM_DisTOUTIntr(a)  *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK) &= ~SIM_IRQEN_TOUT
#define SIM_DisTOUTIntr(a)  DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_TOUT)
//#define SIM_OpenTOUTIntr(a)  *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK) |= SIM_IRQEN_TOUT
#define SIM_OpenTOUTIntr(a)  DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_TOUT)
//#define SIM_DisAllIntr(a)    *(volatile kal_uint16 *)(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK) = SIM_IRQEN_ALLOFF
#define SIM_DisAllIntr(a)    DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF)
#define SIM_SetTOUT(_TOUT)    \
{\
   kal_uint16 _temp;\
   DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
   if (_TOUT < 0xffff)\
   	DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), _TOUT);\
   else\
   	DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffff);\
   _temp = DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);\
   DRV_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
}

#ifdef NoT0CTRL
#define SIMCmdInit() 
#else /*NoT0CTRL*/
#define SIMCmdInit() \
{\
   SIM_T0CtrlEnable(); /*SIM_FlowCtrlEnable()*/ \
}
#endif   /*NoT0CTRL*/

extern void sim_assert(kal_uint32 line);
extern kal_uint16 SIM_CMD(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error, kal_uint32 simInterface);
extern void L1sim_ChangeBaud(void);
extern void L1sim_NormalBaud(void);
extern sim_card_speed_type L1sim_Get_CardSpeedType(kal_uint32 simInterface);
extern void L1sim_Enable_Enhanced_Speed(kal_bool enable, kal_uint32 simInterface);
extern kal_uint16 L1sim_Cmd_Layer(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, kal_uint32 simInterface);


#endif   /*(MT6208,FPGA)*/

#endif   /*_SIM_SW_H*/
