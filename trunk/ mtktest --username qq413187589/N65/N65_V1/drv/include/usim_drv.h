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
 *   usim_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of USIM driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef DRV_MULTIPLE_SIM
#ifndef _USIM_DRV_H_
#define _USIM_DRV_H_
#ifdef __USIM_DRV__

typedef enum{
	USIM_DIRECT,
	USIM_INVERSE
}usim_dir_enum;

typedef enum{
	PPSS = 0,	// initial character 0xFF
	PPS0 = 1,	// format character 0x1x
	PPS1 = 2,	// indicate the baudrate F, D
	PCK  = 3,	// exclusive-or PPSS to PCK should be null
	PPS_LEN = 4
}usim_pts_enum;

#define usim_protocol_enum 		sim_protocol_phy_enum	
#define usim_speed_enum				sim_speed_enum
#define usim_clock_stop_enum 		sim_clock_stop_enum
#define usim_power_enum 			sim_power_enum

typedef enum{
	ERR_INVALID_BLOCK,
	ERR_TIMEOUT
}usim_err_enum;

typedef enum{
	USIM_RESET_NEGOTIABLE,	// type 1
	USIM_RESET_SPECIFIC		// type 2
}usim_reset_type_enum;

typedef enum{
	IDLE_STATE,
	ACTIVATION_STATE,
	ATR_STATE,
	PTS_STATE,
	MAIN_CMD_READY_STATE,
	CMD_TX_STATE,
	//CMD_RX_HEADER_STATE,
	CMD_RX_BLOCK_REC_STATE,
	//CMD_RX_S_BLOCK_STATE,
	CMD_RX_STATE,
	CLK_STOPPING_STATE,
	CLK_STOPPED_STATE,
	DEACTIVATION_STATE
}usim_main_state_enum;

typedef enum{
	EVENT_TX = 		0x1,
	EVENT_RX = 		0x2,
	EVENT_OV = 		0x4,
	EVENT_TOUT = 	0x8,
	EVENT_TXERR = 	0x10,
	EVENT_NATR = 	0x20,
	EVENT_OFF = 	0x40,
	EVENT_T0END = 	0x80,
	EVENT_RXERR = 	0x100,
	EVENT_T1END = 	0x200,
	EVENT_EDCERR = 0x400
}usim_event_type_enum;

typedef enum{
	USIM_NO_ERROR = 0,

	// expected status
	USIM_WAITING_EVENT = 1,		// initial wait event status
	USIM_BLOCK_REC = 2,		// successfully received a complete block
	USIM_POWER_OFF = 3,		// successfully powered off
	USIM_ATR_REC = 4,			// successfully reveived all ATR
	USIM_S_BLOCK_REC = 5,	// successfully reveived S RESP
	
	// error status	
	USIM_NO_INSERT = -1,
	USIM_VOLT_NOT_SUPPORT = -2,
	USIM_NO_ATR = -3,
	USIM_TS_INVALID = -4,
	USIM_ATR_ERR = -5,
	USIM_INVALID_ATR = -6,
	USIM_PTS_FAIL = -7,
	USIM_RX_INVALID = -8,	// EDC error or parity error
	USIM_BWT_TIMEOUT = -9,
	USIM_DATA_ABORT = -10,
	USIM_DEACTIVATED = -11, 
	USIM_S_BLOCK_FAIL = -12,
	USIM_INVALID_WRST = -13,
	USIM_GPT_TIMEOUT = -14
}usim_status_enum;

typedef enum{
	USIM_CMD_READY,
	I_BLOCK_RX,		
	I_BLOCK_TX,
	I_BLOCK_M0_RX,
	I_BLOCK_M0_TX,
	I_BLOCK_M1_RX,
	I_BLOCK_M1_TX,
	R_BLOCK_RX,
	R_BLOCK_TX,
	S_BlOCK_REQ_RX,
	S_BlOCK_REQ_TX,
	S_BlOCK_RESP_RX,
	S_BlOCK_RESP_TX		
}usim_cmd_state_enum;

typedef enum{
 T1_NAD_INDEX		=		0,
 T1_PCB_INDEX		=		1,
 T1_LEN_INDEX		=		2,
 T1_INF_INDEX		=		3,
 T1_EDC_INDEX		=		4
}usim_t1_header_index_enum;

// definitions
#define	SELECT_PW_RETRY	3
#define 	SELECT_DIR_RETRY	2
#define 	ATR_RETRY  		3
#define	INVALID_RETRY	3
#define	RESYNC_RETRY	3
#define 	IFS_RETRY		2
#define 	USIM_IFSD_MAX	0xFE

#define FI_DEFAULT		372
#define DI_DEFAULT		1
#define INIT_WWT_T0		(9600+400)	// etu	(initial work waiting time) +400 to cover some slow card
#define TOUT_OFFSET		0x10		// apply a offset to all timeout settings (4*16 = 64 etu)
#define BGT_T1				22 		// etu	(block guard time)
#define NAD					0			// node address byte
#define SIM_DEFAULT_TOUT_VALUE      0x983
#define SIM_CMD_TOUT_VALUE          0x1400


// coding of PCB for I-block (0xxxxxxx)
#define PCB_I_BIT8		0x80		// I-block must be 0, others(R,S) are 1
#define PCB_I_SEQ			0x40		// sequence number
#define PCB_I_M			0x20		// chaining more data bit(M)
#define PCB_I_RFU			0x1F		// RFU should be zero

// coding of PCB for R-block (100xxxxx)
#define PCB_R_N1			0x90
#define PCB_R_N0			0x80
#define PCB_R_BIT7		0x40		// R: 0, S:1, use to distinguish R-block with S-block
#define PCB_R_SEQ			0x10		// sequence number
#define PCB_R_STATUS		0x0f		// 0: error free, 1:EDC or parity error, 2: other errors
#define PCB_R_STATUS_EDC_ERR 		0x1
#define PCB_R_STATUS_OTHER_ERR 	0x2
#define PCB_R_STATUS_OK	 0x0
#define PCB_R_DEFAULT	0xe0

// coding of PCB for S-block (11xxxxxx)
#define PCB_S_DEFAULT	0xc0
#define PCB_S_RESP		0x20		// 1: a response, 0: a request
#define PCB_S_ID			0x1f


#define LEN_MIN_T1			0
#define LEN_MAX_T1			254
#define USIM_IFSC_DEFAULT	32
#define USIM_IFSD_DEFAULT	32
#define USIM_CWT_DEFAULT	8203		// (11 + 1>>13) etu
#define USIM_BWT_DEFAULT	15360		// (1<<4)*960
#define USIM_POW_CLASS_MSK	0x3f		// TAi bit 1~6
#define USIM_PTS_PS1_MSK	0x10
#define USIM_PTS_PS0_T1		0x1		// select T1 protocol
#define USIM_NAD_DEFAULT	0x0

#define USIM_EVENT			0x1

#define ATR_TA1_372_5		0x11
#define ATR_TA1_372_4		0x01
#define ATR_TA1_64			0x94
#define ATR_TA1_32			0x95
#define ATR_TA1_16			0x96

#define USIM_RETRY			3
#define INDEX_COUNT			4		// the count of the wline and sline
#define MAX_BWI				9
#define MAX_CWI				16
#define SIM_TOTAL_FIFO_LEN	16		// excep 6208
#define HIST_FIRST_USIM				0x80	// the first of the historical character of USIM
#define HIST_SEC_USIM				0x31	// the second of the historical character of USIM
#define HIST_FOUR_USIM				0x73	// the fourth of the historical character of USIM
#define USIM_DMA_MAX_SIZE			260
#define USIM_GPT_TIMEOUT_PERIOD  500	// x 10ms

typedef enum{
	RESYNC_REQ = PCB_S_DEFAULT,
	IFS_REQ = (PCB_S_DEFAULT|1),
	ABORT_REQ = (PCB_S_DEFAULT|2),
	WTX_REQ = (PCB_S_DEFAULT|3),
	RESYNC_RESP = RESYNC_REQ|PCB_S_RESP,
	IFS_RESP = IFS_REQ|PCB_S_RESP,
	ABORT_RESP = ABORT_REQ|PCB_S_RESP,
	WTX_RESP = WTX_REQ|PCB_S_RESP
}usim_s_block_id_enum;


// macros
#define SIM_WARM_RST()		DRV_Reg(SIM_CTRL)|=SIM_CTRL_WRST

/*
	normally, wait event will before set event, but sometimes set event will before wait event.
	for instance, during wait event, an interrupt is generated and trigger another interrupt before
	the corresponding wait event.
*/

#define USIM_CLR_EVENT()\
	kal_set_eg_events(usim_dcb.event,0,KAL_AND)

#define USIM_POW_ON() DRV_Reg(SIM_CTRL) |= SIM_CTRL_SIMON
#define USIM_WRST()	DRV_Reg(SIM_CTRL) = (SIM_CTRL_WRST|SIM_CTRL_SIMON)
#define USIM_ENABLE_T0()	DRV_Reg(SIM_CONF)|= SIM_CONF_T0EN
#define USIM_ENABLE_T1()	DRV_Reg(SIM_CONF)|= SIM_CONF_T1EN
#define USIM_DISABLE_T1()	DRV_Reg(SIM_CONF)&= (~SIM_CONF_T1EN)
#define USIM_ENABLE_TXRX_HANSHAKE()	DRV_Reg(SIM_CONF)|= (SIM_CONF_TXHSK|SIM_CONF_RXHSK)
#define USIM_DISABLE_TXRX_HANSHAKE()	DRV_Reg(SIM_CONF)&= ~(SIM_CONF_TXHSK|SIM_CONF_RXHSK)
#define USIM_TX_START_T1()	DRV_WriteReg(SIM_INS, 1)
#define USIM_IS_IBLOCK(pcb)	((pcb&PCB_I_BIT8)==0)
#define USIM_IS_RBLOCK(pcb)	((pcb&PCB_R_DEFAULT) == 0x80)
#define USIM_IS_SBLOCK(pcb)	((pcb&PCB_S_DEFAULT) == PCB_S_DEFAULT)
#define USIM_IS_RESP(pcb)		(pcb&PCB_S_RESP)
#define USIM_INV_N(n)	n = (n)?0:PCB_I_SEQ
#define USIM_CLR_FIFO()	DRV_WriteReg(SIM_COUNT, 1)
#define USIM_RESET_T1()	USIM_DISABLE_T1();USIM_ENABLE_T1();
#define USIM_ENABLE_TOUT()	DRV_Reg(SIM_CONF)|=SIM_CONF_TOUTEN
#define USIM_DISABLE_TOUT()	DRV_Reg(SIM_CONF)&=(~SIM_CONF_TOUTEN)
//#define USIM_CLR_TX_TIDE()		DRV_Reg(SIM_TIDE)&=(~SIM_TIDE_TXMASK)
#define USIM_DMA_RX_TIDE()			DRV_Reg(SIM_TIDE) = 0;
#define USIM_CAL_TD_COUNT(a,b)	\
		{\
			if(a & TAMask) b++;\
   		if(a & TBMask) b++;\
   		if(a & TCMask) b++;\
   	}

// generate R-block header 
#define USIM_MAKE_R_BLOCK(e)	\
		{\
			kal_uint8 pcb;\
\
			if(usim_dcb.nr)\
				pcb = (PCB_R_N1|e);\
			else\
				pcb = (PCB_R_N0|e);\
			usim_dcb.header_tx[T1_PCB_INDEX] = pcb;\
			usim_dcb.header_tx[T1_LEN_INDEX] = 0;\
			usim_dcb.cmd_state = R_BLOCK_TX;\
		}

#define USIM_MAKE_S_RESYNC()\
{\
			usim_dcb.header_tx[T1_PCB_INDEX] = PCB_S_DEFAULT;\
			usim_dcb.header_tx[T1_LEN_INDEX] = 0;\
			usim_dcb.cmd_state = S_BlOCK_REQ_TX;\
}

//#define USIM_GET_PCB_I() 

////////////// temp definitions///////////////
#define error()
//////////////////////////////////////////////

typedef struct{
	usim_dir_enum dir;

}ATR_struct;

// specify the supported attributes  of the UICC
typedef struct{
	usim_power_enum power;	
	usim_protocol_enum protocol;
	usim_clock_stop_enum clock_stop;
	usim_speed_enum speed;		
}usim_info_struct;

typedef struct{
	// before reset
	kal_bool high_speed_en;		// control if high speed is enalbed
	usim_power_enum power_in;		// expected power class input form application layer	
	// after reset
	usim_clock_stop_enum clock_stop_type; 
}usim_config_struct;

typedef struct{
	// ATR info
	kal_uint8 ATR_data[36];		// used to store all ATR data string
	kal_uint8 ATR_index;			// index to the ATR_data
	kal_uint8 header_tx[4], header_tx_bak[4]; // header_tx_bak used to backup the previous command
	kal_uint8 header_rx[4];
	kal_uint8 dma_buffer[USIM_DMA_MAX_SIZE];
	
	// informations
	usim_dir_enum dir;	// convention of character frame
	sim_env sim_env;		// the voltage which MS can supply
	usim_power_enum power_in;		// expected power class input form application layer
	usim_power_enum power;			// power class used
	usim_power_enum power_class;		// supported power class indicated at ATR
	// usim_protocol_enum T;		
	usim_speed_enum speed;		// speed selected
	usim_speed_enum card_speed; // TA1, max speed card can support
	kal_bool high_speed_en;		// control if high speed is enalbed
	usim_clock_stop_enum clock_stop_type;
	kal_bool	clock_stop_en;		// clock_stop is enabled or not
	kal_uint16 etu_of_1860;
	kal_uint16 etu_of_700;
	usim_reset_type_enum reset_mode; // specific or negotiable mode
	kal_bool warm_rst;	// KAL_TRUE: it's a warm reset, KAL_FALSE: a cold reset
	kal_bool T0_support;	// if T0 is supported
	kal_bool T1_support;	// if T1 is supported
	kal_uint16 Fi;
	kal_uint8 Di;
		
	// state control
	volatile usim_main_state_enum main_state;
	volatile usim_status_enum ev_status;
	kal_uint8 retry;
	
	// time out control
	kal_uint32 WWT;	// work waiting time (T0)
	kal_uint32 CWT;	// character waiting time in etu(T1)
	kal_uint32 BWT;	// blcok waiting time in etu(T1)
	kal_uint32 timeout;	// etu
	
	// T=1 
	kal_uint8 ns;		// sequence # of sending
	kal_uint8 nr;		// sequence # of receiving
	kal_uint8 ifsd;	// information size of interface device
	kal_uint8 ifsc;	// information size of card
	usim_cmd_state_enum cmd_state;
	usim_cmd_state_enum cmd_state_bak;	
	kal_bool abort;
	kal_bool wtx;	// waiting time extension
	kal_bool resync;
  	kal_bool send_prev;	// send the previous block	
	kal_bool tx_chain;	
	kal_bool rx_chain;
	kal_uint16 tx_size;
	kal_uint16 rx_size;
	kal_uint16 tx_index;
	kal_uint16 rx_index;
	kal_uint8 *tx_buf;
	kal_uint8 *rx_buf;
	kal_uint8 sw[2];		// used to contain SW1 and SW2
	kal_uint8 wtx_m;		// multiplier of BWT

	// others
	kal_bool ts_hsk_en;	// enable handshake at TS byte (error signal and char repetition)
	kal_uint8 dma_port;
	DMA_INPUT dma_input;
	DMA_HWMENU dma_menu;
	kal_eventgrpid event;
	kal_uint32 ev_flag;
	kal_hisrid hisr; 
	kal_uint32 int_status;
  	sim_protocol_app_enum app_proto;	// application protocol (USIM, SIM) 	
  	sim_protocol_phy_enum phy_proto; // protocol type selected (physical layer)
  	kal_uint8 hist_index;		// index to the historical characters 
	usim_status_enum status;
  	usim_cmd_case_enum cmd_case;
	kal_uint8 gpt_handle;
	kal_bool present;
	sim_protocol_phy_enum perfer_phy_proto; // protocol type selected (physical layer)
#if defined(USIM_DEBUG)
	kal_int32 sline[INDEX_COUNT];	// set event at the which line in usim_drv.c
	kal_uint32 sindex;	// index to the sline[4]
	kal_int32 wline[INDEX_COUNT];	// wait event at the which line in usim_drv.c
	kal_uint32 windex;	// index to the wline
#endif

}usim_dcb_struct;

#define sim_print(a,b)		dbg_print(a,b)
//#define sim_print(a,b)	kal_prompt_trace(MOD_SIM,a,b) 

extern usim_dcb_struct usim_dcb;
extern usim_dcb_struct usim_dcb_2;
usim_status_enum L1sim_Reset_All(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm);
usim_status_enum L1sim_Reset_All_2(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm); // nick
void L1sim_Enable_Enhanced_Speed_All(kal_bool enable);
kal_bool L1sim_Set_ClockStopMode_All(sim_clock_stop_enum mode);
kal_bool L1sim_Set_ClockStopMode_All_2(sim_clock_stop_enum mode);  // nick
void L1sim_PowerOff_All(void);
void L1sim_PowerOff_All_2(void);  //nick
void L1sim_Get_Card_Info_All(sim_info_struct *info);
sim_status L1sim_Cmd_All(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize);
sim_status L1sim_Cmd_All_2(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize);  // nick

void usim_gpt_timeout_handler(void *parameter);
void L1sim_Select_SIM_PLUS(kal_bool isSIMPLUS);
void L1sim_Select_Prefer_PhyLayer_All(sim_protocol_phy_enum T);
void L1sim_Select_Prefer_PhyLayer_All_2(sim_protocol_phy_enum T); // nick

#if defined(USIM_DEBUG)
#define USIM_WAIT_EVENT() \
{\
	usim_dcb.wline[(usim_dcb.windex&(INDEX_COUNT-1))] = __LINE__;\
	dbg_print("wait event at line:%d\r\n",__LINE__);\
	usim_dcb.windex++;\
	GPTI_StartItem(usim_dcb.gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  NULL);\
	kal_retrieve_eg_events(usim_dcb.event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb.ev_flag,KAL_SUSPEND);\
	if(usim_dcb.status != USIM_GPT_TIMEOUT)\
		GPTI_StopItem(usim_dcb.gpt_handle);	\	
}
#define USIM_SET_EVENT()\
{\
	usim_dcb.sline[(usim_dcb.sindex&(INDEX_COUNT-1))] = __LINE__;\
	dbg_print("set event at line:%d\r\n",__LINE__);\
	usim_dcb.sindex++;\
	kal_set_eg_events(usim_dcb.event,USIM_EVENT,KAL_OR);\
}
#else
#define USIM_WAIT_EVENT()\
{\
	GPTI_StartItem(usim_dcb.gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  NULL);\
	kal_retrieve_eg_events(usim_dcb.event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb.ev_flag,KAL_SUSPEND);\
	if(usim_dcb.status != USIM_GPT_TIMEOUT)\
		GPTI_StopItem(usim_dcb.gpt_handle);	\
}
#define USIM_SET_EVENT()\
	kal_set_eg_events(usim_dcb.event,USIM_EVENT,KAL_OR)
#endif


#endif //__USIM_DRV__
#endif // _USIM_DRV_H_
#else	//DRV_MULTIPLE_SIM
#include "usim_MT6302.h"
#endif	//DRV_MULTIPLE_SIM
