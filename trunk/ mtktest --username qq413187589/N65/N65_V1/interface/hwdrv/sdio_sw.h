/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   sdio_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of SDIO driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef SDIO_SW_H
#define SDIO_SW_H

/*SW*/

#define SDIO_CCCR_VERISON_MASK 0xf
#define SDIO_SD_VERISON_MASK 0xf
#define SDIO_VERISON_MASK  0xf0
#define SDIO_VERISON_SHIFT 4

/*CIS tuple code*/
#define  CISTPL_NULL             0x0
#define  CISTPL_CHECKSUM         0x10
#define  CISTPL_VERS_1           0x15
#define  CISTPL_ALTSTR           0x16
#define  CISTPL_MANFID           0x20
#define  CISTPL_FUNCID           0x21 
#define  CISTPL_FUNCE            0x22
#define  CISTPL_SDIO_STD         0x91
#define  CISTPL_SDIO_EXT         0x92
#define  CISTPL_END              0xff 

/*Function definition*/
#define SDIO_CCCR_SIZE       32
#define SDIO_FBR_SIZE        256
#define SDIO_TUPLE_SIZE      256

typedef enum{
	SDIO_FUCN_0=0,
	SDIO_FUCN_1,
	SDIO_MAX_FUCN_ID, 
	SDIO_FUCN_MEM=0x1000
}SDIO_function_id_enum;
typedef enum{
	SDIO_BS_FREE=0,
	SDIO_BS_BUS
}SDIO_bus_status_enum;
typedef enum{
	SDIO_INTERFACE_NULL=0,
	SDIO_INTERFACE_UART,
	SDIO_INTERFACE_A_BT,
	SDIO_INTERFACE_B_BT,
	SDIO_INTERFACE_GPS,
	SDIO_INTERFACE_CAMERA,
	SDIO_INTERFACE_PHS,
	SDIO_INTERFACE_WLAN	
}SDIO_interface_code_enum;

typedef enum{
	SDIO_FIX,	//multi byte r/w at fixed address
	SDIO_INC		//multi byte r/w at incrementing address 
}cmd53_op_enum;
typedef enum{
	SDIO_READ,
	SDIO_WRITE
}rw_dir_enum;
typedef enum{
	DIS,
	CMD,
	TRN,
	RFU
}sdio_state_enum;
typedef struct{
	rw_dir_enum rw;	// directon (input)
	kal_uint8 func;	// function (input)
	kal_bool raw;		// read after write
	kal_bool stop;		// stop data transfer 
	kal_uint8 data;	// write data or read back data (Input , output)
	kal_uint32 adrs;	// address (input)
}cmd52_config_struct;

#define SDIO_SUPPORT_FUNCTION (SDIO_MAX_FUCN_ID-1)
typedef struct{
	rw_dir_enum rw;		// directon
	kal_uint8 func;		// function
	kal_bool block;		// block mode or not
	cmd53_op_enum op;		// operation mode
	kal_uint16 count;		// byte or block count
	kal_uint32 adrs;		// address
	kal_uint32 buffer;	// address of buffer for data transfer
}cmd53_config_struct;

typedef struct{
	kal_uint8 num_func;
	kal_bool mem_present;
	kal_bool io_ready;
	kal_bool ocr_valid;
	kal_bool stop;				// stop trans issued
	sdio_state_enum state;
	kal_uint8 resp;
	kal_uint8 bit_width;
	kal_uint8 capability;
	kal_uint32 ocr;	
	kal_uint8 power_control;
	kal_uint32 block_size[SDIO_MAX_FUCN_ID];	  	
	void (*callback[SDIO_MAX_FUCN_ID])(void);
}sdio_dcb_struct;

/*SDIO command set*/
SDC_CMD_STATUS SDIO_Cmd5(kal_uint32 ocr);
SDC_CMD_STATUS SDIO_Cmd52_isr(cmd52_config_struct *p);
SDC_CMD_STATUS SDIO_Cmd52(cmd52_config_struct *p);
SDC_CMD_STATUS SDIO_Cmd53_isr(cmd53_config_struct *p);
SDC_CMD_STATUS SDIO_Cmd53(cmd53_config_struct *p);
SDC_CMD_STATUS SD_Send_Cmd_poll(kal_uint32 cmd, kal_uint32 arg);
SDC_CMD_STATUS SD_WaitCmdRdyOrTo_poll(void);
SDC_CMD_STATUS SD_StopTrans_poll(void);
/*Driver only*/
SDC_CMD_STATUS SDIO_read_FBR(SDIO_function_id_enum function);
SDC_CMD_STATUS SDIO_read_CCCR(void);
SDC_CMD_STATUS SDIO_read_CIS(SDIO_function_id_enum function);
SDC_CMD_STATUS SDIO_read_capacity(void);
SDC_CMD_STATUS SDIO_abort_IO(SDIO_function_id_enum function);
SDC_CMD_STATUS SDIO_SW_reset(void);
SDC_CMD_STATUS SDIO_check_IO_Int(SDIO_function_id_enum function, kal_bool *pending);
SDC_CMD_STATUS SDIO_check_IO_ready(SDIO_function_id_enum function, kal_bool *ready);
SDC_CMD_STATUS SDIO_configure_bus(SD_BITWIDTH bus);
SDC_CMD_STATUS SDIO_enable_E4MI(kal_bool enable);
SDC_CMD_STATUS SDIO_read_power_control(void);
SDC_CMD_STATUS SDIO_enable_MPS(kal_bool enable);
kal_bool SDIO_support_MPS(void);
kal_bool SDIO_support_SDC(void);
kal_bool SDIO_support_SMB(void);
kal_bool SDIO_support_SRW(void);
kal_bool SDIO_support_SBS(void);
kal_bool SDIO_support_S4MI(void);
kal_bool SDIO_support_LSC(void);
kal_bool SDIO_support_4BLS(void);
void SDIO_HISR_Entry(void);
kal_bool SDIO_Register_Read_poll(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 *data,
                             cmd53_op_enum op);
SDC_CMD_STATUS SDIO_stop(void);
SDC_CMD_STATUS SDIO_WaitDatRdyOrTo(void);
/*SDIO function */
SDC_CMD_STATUS SDIO_read_CCCR_ver(kal_uint8 *version);
SDC_CMD_STATUS SDIO_read_SDIO_ver(kal_uint8 *version);
SDC_CMD_STATUS SDIO_read_SD_ver(kal_uint8 *version);
SDC_CMD_STATUS SDIO_configure_BLK_size(SDIO_function_id_enum function, kal_uint32 size);
kal_uint32 SDIO_query_BLK_size(SDIO_function_id_enum function);
SDIO_function_id_enum SDIO_query_IO_id(SDIO_interface_code_enum ap);
SDC_CMD_STATUS SDIO_enable_IO_Int(SDIO_function_id_enum function, kal_bool enable);
SDC_CMD_STATUS SDIO_enable_IO(SDIO_function_id_enum function, kal_bool enable);
void SDIO_int_registration(SDIO_function_id_enum function, void (func)(void));
/*Function for WiFi */
/*Write Register*/
kal_bool SDIO_Register_Write(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 data,
                             cmd53_op_enum op);                                                        
kal_bool SDIO_Register_Write_isr(SDIO_function_id_enum function, 
                                 kal_uint32 addr, 
                                 kal_uint32 data,
                                 cmd53_op_enum op);                             
/*Write Data */                             
kal_bool SDIO_Data_Write(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint8  *data,
                             cmd53_op_enum op,
                             kal_uint32 count,
                             kal_bool block);                             
/*Read Register*/
kal_bool SDIO_Register_Read(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 *data,
                             cmd53_op_enum op);
kal_bool SDIO_Data_Read(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint8  *data,
                             cmd53_op_enum op,
                             kal_uint32 count,
                             kal_bool block);
#ifdef __SDIO_SRW_SRW__
SDC_CMD_STATUS SDIO_suspend_IO(SDIO_bus_status_enum *bus_status);
SDC_CMD_STATUS SDIO_select_IO(SDIO_function_id_enum function, kal_bool *resume_data);
SDC_CMD_STATUS SDIO_check_IO_exec(SDIO_function_id_enum function, kal_bool *execution);
SDC_CMD_STATUS SDIO_check_IO_ready_flag(SDIO_function_id_enum function, kal_bool *ready);
#endif

/*extern varibale*/
extern sdio_dcb_struct gSDIO;
#endif // end of SD_DEF_H
