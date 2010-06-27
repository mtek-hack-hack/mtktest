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
 *   mspro_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of MS-Pro driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef MSPRO_DEF_H
#define MSPRO_DEF_H

//#define MSP_TEST
#define MSP_USE_PARALLEL_MODE

typedef kal_uint32					MSP_STATUS;

//registers address definition
#define MSC_CFG		(MSDC_ADRS+0x60)
#define MSC_CMD	(MSDC_ADRS+0x64)
#define MSC_ACMD	(MSDC_ADRS+0x68)
#define MSC_STA	(MSDC_ADRS+0x6c)

// masks for MSC_CFG(16)
#define MSC_CFG_SIEN			0x0001
#define MSC_CFG_BUSYCNT		0x000e
#define MSC_CFG_PRED			0x4000
#define MSC_CFG_PMODE		0x8000

//masks for MSC_CMD
#define MSC_CMD_DATASIZE	0x03ff
#define MSC_CMD_PID			0xf000

//masks for MSC_ACMD
#define MSC_ACMD_ACEN		0x0001
#define MSC_ADATASIZE		0x07ff
#define MSC_APID				0xf000

// masks for MSC_STA
#define MSC_STA_RDY			0x0001
#define MSC_STA_SIF			0x0002
#define MSC_STA_TOER			0x0004
#define MSC_STA_CRCERR		0x0008
#define MSC_STA_HSRDY		0x0010
#define MSC_STA_CED			0x1000
#define MSC_STA_ERR			0x2000
#define MSC_STA_BREQ			0x4000
#define MSC_STA_CMDNK		0x8000

// TPC CMDs
#define TPC_READ_LONG_DATA 		0x2
#define TPC_READ_SHORT_DATA 		0x3
#define TPC_READ_REG            	0x4
#define TPC_GET_INT             	0x7
#define TPC_WRITE_LONG_DATA 		0xd
#define TPC_WRITE_SHORT_DATA 	   0xc
#define TPC_WRITE_REG           	0xb
#define TPC_SET_R_W_REG_ADRS    	0x8
#define TPC_SET_CMD             	0xe
#define TPC_EX_SET_CMD				0x9

// CMDs for SET_CMD
//    Memory Access CMD                  
#define CMD_READ_DATA				0x20
#define CMD_WRITE_DATA				0x21
#define CMD_READ_INFO				0x22
#define CMD_WRITE_INFO				0x23
#define CMD_READ_ATRB				0x24
#define CMD_STOP						0x25
#define CMD_ERASE						0x26
#define CMD_CHG_CLASS				0x27

//   Function CMD               
#define CMD_FORMAT					0x10
#define CMD_SLEEP						0x11


// MS registers address
// status registers 
#define MSP_INT_REG			0x01
#define MSP_STA_REG			0x02
#define MSP_TYPE_REG			0x04
#define MSP_CATEGORY_REG	0x06
#define MSP_CLASS_REG		0x07
// parameter registers
#define MSP_SYS_REG			0x10
#define MSP_DATCNT1_REG		0x11
#define MSP_DATCNT0_REG		0x12
#define MSP_ADRS3_REG		0x13
#define MSP_ADRS2_REG		0x14
#define MSP_ADRS1_REG		0x15
#define MSP_ADRS0_REG		0x16
#define MSP_TPCPARA_REG		0x17
#define MSP_CMDPARA_REG		0x18

// masks for register
// mask for INT
#define INT_CMDNK			0x01
#define INT_BREQ			0x20
#define INT_ERR				0x40
#define INT_CED				0x80
// mask for status register
#define STA_WP			0x01
#define STA_SL			0x02
#define STA_PRS0		0x10
#define STA_PRS1		0x20
#define STA_PRS2		0x40
#define STA_PRS3		0x80

#define MSP_TYPE_REG_DEFAULT		0x01
#define MSP_CTGY_REG_DEFAULT		0x00
#define MSP_CLASS_REG_DEFAULT		0x00

// mask for system parameter
#define SYS_SRAC						0x80	// for serial or parallel

// CMD parameter
#define CMD_AC_SECTOR	0x00
#define CMD_AC_FILE		0x01

// definition of the constants
#define MSP_LONGDATA_SIZE				512

#define MSP_INT_TIMEOUT					120	// x10ms

// macros
#define MS_IS_TIMEOUT	(*(volatile kal_uint16*)MSC_STA & MSC_STA_TOER)
#define MS_IS_CMDRDY		(*(volatile kal_uint16*)MSC_STA & MSC_STA_RDY)
#define MS_IS_INT			(*(volatile kal_uint16*)MSC_STA & MSC_STA_SIF)
#define MS_IS_CRCERR		(*(volatile kal_uint16*)MSC_STA & MSC_STA_CRCERR)
#define MSDC_IS_SIF		(*(volatile kal_uint16*)MSDC_INTR & MSDC_INT_MSIFIRQ)
#define IS_IN_PACKET(tpc)		!(tpc & 0x80)
/* Get low byte value from word value */
#define LOBYTE(w)               ((unsigned char)(w))

/* Get high byte value from word value */
#define HIBYTE(w)               ((unsigned char)(((unsigned short)(w) >> 8) & 0xFF))

// error definition
#define MSP_NOERROR				0
#define MSP_ERR_TIMEOUT			1		// CMD busy time out(not INT timeout)
#define MSP_ERR_CRCERR			2		// DATA crc error
#define MSP_ERR_CMDFAIL			3		// CMD not accept
#define MSP_ERR_EXECUTE			4		// During CMD execution
#define MSP_ERRORS				5		// Unknown error
#define MSP_ERR_UC				6		// Uncorrectable errors
#define MSP_ERR_INT				7		// Int register err bit set
#define MSP_ERR_STABUSY			8		// media busy or flash busy
#define MSP_ERR_WRITEFAIL 		9
#define MSP_ERR_ERASEFAIL		10	
#define MSP_ERR_WP				11		// write protect error
#define MSP_ERR_WAIT				12		// wait uintil ready, timeout and crc fail
#define MSP_ERR_READBOOTBLK	13
#define MSP_ERR_LPTABLE			14
#define MSP_ERR_INTERR			15		// INT register which err bit is set
#define MSP_ERR_INIT				16		// initail MS Pro failed
#define MSP_ERR_INVALIDPAR		17		// invalid data count or invalid start address
#define MSP_ERR_NOT_MSP			18		// not memory stick pro card
#define MSP_ERR_SIG				19
#define MSP_ERR_WRITE_PROTECT	20
#define MSP_ERR_NOBREQ			21		// No BREQ after READ_DATA or WRITE_DATA set cmd.
#define MSP_ERR_SWITCH_MODE	22		// Select parallel or serial mode fail
#define MSP_ERR_SI_CONFIM		23		// system confirm fail
#define MSP_ERR_FAT				24


#define MSP_LASTPAGE				50		// reach the last page
#define MSP_POWER_ON()		\
{\
	MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_VDDPD);\
	if(kal_query_systemInit()==KAL_TRUE)\
		GPTI_BusyWait(50);\
	else\
		kal_sleep_task(11);\
}

#define MSP_POWER_OFF()		\
{\
	MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_VDDPD);\
	if(kal_query_systemInit()==KAL_TRUE)\
		GPTI_BusyWait(500);\
	else\
		kal_sleep_task(110);\
}	


typedef enum {
	TYPE_MS_CARD = 0,		
	TYPE_MSPRO_CARD	
}ms_type_enum;

typedef enum {
	DIRECTION_IN = 0,		
	DIRECTION_OUT		
}ms_direction_enum;

typedef enum {
	MSP_READ = 0,		
	MSP_WRITE=1		
}msp_direction_enum;
typedef enum {
	MSP_PARALLEL = 0x00,		
	MSP_SERIAL		= 0x80
}msp_mode_enum;

typedef enum {
	MSP_QUICK = 0x00,		
	MSP_FULL		= 0x01
}msp_format_enum;

typedef enum {
	SHORT_DATA_24 = 0,		
	SHORT_DATA_56		,			
	SHORT_DATA_120	,			
	SHORT_DATA_248			
}ms_ShortData_enum;

typedef enum {
	SYS_INFO_ID		= 0x10,
	MODEL_NAME_ID	= 0x15,
	MBR_VALUE_ID	= 0x20,
	PBR_16_ID		= 0x21,
	PBR_32_ID		= 0x22,
	FILE_VALUE1_ID = 0x25,
	FILE_VALUE2_ID = 0x26,
	ID_DEVICE_ID   = 0x30,	
	VENDER1_ID   	= 0x11,		
	VENDER2_ID   	= 0x12	
}mspro_DIEntry_ID_enum;

typedef enum {
	SYS_INFO_COUNT		= 96,
	MODEL_NAME_COUNT	= 48,
	MBR_VALUE_COUNT	= 16,
	PBR_16_COUNT		= 64,
	PBR_32_COUNT		= 96,
	FILE_VALUE1_COUNT = 32,
	FILE_VALUE2_COUNT = 32,
	ID_DEVICE_COUNT   = 16	
}mspro_DIEntry_Count_enum;

typedef struct{
	mspro_DIEntry_ID_enum id;
	mspro_DIEntry_Count_enum count;
	kal_uint32 adrs;
}mspro_di_confirm_count_struct;
		

typedef struct{
	kal_uint32	adrs;
	kal_uint32	size;
	kal_uint8	id;
	kal_uint8   rev[3];
}msp_DIEntry_struct;

typedef struct{	
	kal_uint8	mType;				// Is MS card or MS PRO 
	kal_uint8	mCategory;			// category register
	kal_uint8	mClass;				// class register
	kal_uint8  	is_wp;				// write protect?
	kal_bool		is_failed;			// errors happpend during parallel mode
	kal_uint8	mSIClass;			// Memory Stick class of system information
	kal_uint8	mSIDevType;			// Memory Stick device type of system information
	kal_uint8	mSISubClass;		// Memory Stick sub-Class of system information
	
	// attribute information
	kal_uint16	signature;			// 0xA5C3
	kal_uint16	version;				//0x10xx
	kal_uint8	di_count;			// device information entry count 1~12
   // device information
	kal_uint16  block_size;       // unit: sector => cluster
	kal_uint16  total_block	;     // unit: block
	kal_uint16  user_block;       // unit: block
	kal_uint16  page_size;        // unit: sector
	kal_uint16  unit_size;        // unit: bytes => 512

	msp_mode_enum	mode;
}MSP_HANDLE;

typedef void (* MSP_CallBack)(void);

MSP_STATUS MSP_CMD_ReadWriteData(kal_uint32 adrs, kal_uint16 count, kal_uint32* buffer, kal_uint16* sectors,msp_direction_enum IsWrite);
MSP_STATUS MSP_CMD_ReadWriteInfo(kal_uint32 adrs, kal_uint16 count, kal_uint32* buffer, kal_uint16* bytes,kal_uint8 IsWrite);
MSP_STATUS MSP_CMD_Erase(kal_uint32 adrs, kal_uint16 count,MSP_CallBack callback);
MSP_STATUS MSP_CMD_Format(msp_format_enum type, MSP_CallBack callback);
MSP_STATUS MSP_CMD_Stop(void);
MSP_STATUS MSP_CMD_Sleep(void);
MSP_STATUS MSP_CMD_ReadAtrb(kal_uint32 adrs, kal_uint16 count, kal_uint32* buffer, kal_uint16* sectors);
MSP_STATUS MSP_Initialize(void);
MSP_STATUS MSP_WaitCmdRdyOrTo(void);
void MSP_Test(void);

extern MSP_HANDLE	gMSP;
extern FS_Driver FS_MspDrvAll;
extern FS_Driver FS_MsDrv;
extern FS_Driver FS_MspDrv;

#endif // end of MSPRO_DEF_H  


