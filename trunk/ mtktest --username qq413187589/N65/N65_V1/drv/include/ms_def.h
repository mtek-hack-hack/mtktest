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
 *   Ms_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of MS driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef MS_DEF_H
#define MS_DEF_H

//registers address definition
#define MSC_CFG		(MSDC_ADRS+0x60)
#define MSC_CMD		(MSDC_ADRS+0x64)
#define MSC_ACMD	(MSDC_ADRS+0x68)
#define MSC_STA		(MSDC_ADRS+0x6c)

// masks for MSC_CFG(16)
#define MSC_CFG_SIEN		0x0001
#define MSC_CFG_BUSYCNT		0x000e
#define MSC_CFG_PMODE		0x8000

//masks for MSC_CMD
#define MSC_CMD_DATASIZE		0x03ff
#define MSC_CMD_PID				0xf000
#define MSC_CMD_PID_START		12

//masks for MSC_ACMD
#define MSC_ACMD_ACEN				0x0001
#define MSC_ADATASIZE				0x07ff
#define MSC_APID						0xf000
#define MSC_ACMD_ACEN_START		1
#define MSC_ACMD_APID_START		12

// masks for MSC_STA
#define MSC_STA_RDY			0x0001
#define MSC_STA_SIF			0x0002
#define MSC_STA_TOER		0x0004
#define MSC_STA_CRCERR		0x0008

typedef kal_uint32		MS_STATUS;
//#define MS_STATUS			kal_uint32

// TPC CMDs
#define TPC_READ_PAGE_DATA			0x2
#define TPC_READ_REG					0x4
#define TPC_GET_INT             	0x7
#define TPC_WRITE_PAGE_DATA   0xD
#define TPC_WRITE_REG          	0xB
#define TPC_SET_R_W_REG_ADRS  0x8
#define TPC_SET_CMD             0xE

// CMDs for SET_CMD
//    Flash CMD                  
#define CMD_BLOCK_READ   0xaa
#define CMD_BLOCK_WRITE  0x55
#define CMD_BLOCK_END    0x33
#define CMD_BLOCK_ERASE  0x99
#define CMD_FLASH_STOP   0xcc
//   Function CMD               
#define CMD_SLEEP				0x5a
#define CMD_CLEAR_BUF		0xc3
#define CMD_RESET				0x3c

// MS registers
// status registers
#define MS_INT_REG				0x01
#define MS_STA0_REG				0x02
#define MS_STA1_REG				0x03
#define MS_TYPE_REG				0x04
#define	MS_CATEGORY_REG		0x06
#define MS_CLASS_REG				0x07
// parameter registers
#define MS_SYS_REG			0x10
#define MS_BLKADRS2_REG		0x11
#define MS_BLKADRS1_REG		0x12
#define MS_BLKADRS0_REG		0x13
#define MS_CMD_REG			0x14
#define MS_PGADRS_REG		0x15
// ExtraData registers
#define MS_OVERWRITE_REG	0x16
#define MS_MANAGE_REG		0x17
#define MS_LADRS1_REG		0x18
#define MS_LADRS0_REG		0x19

// masks for register
// mask for INT
#define INT_NMDNK			0x01
#define	INT_BREQ			0x20
#define INT_ERR			0x40
#define	INT_CED			0x80
// mask for status0
#define STA0_WP			0x01
#define STA0_SL			0x02
#define STA0_BF			0x10
#define STA0_BE			0x20
#define STA0_FB0			0x40
#define STA0_MB			0x80
// mask for status1
#define STA1_UCFG			0x01
#define STA1_FGER			0x02
#define STA1_UCEX			0x04
#define STA1_EXER			0x08
#define STA1_UCDT			0x10
#define STA1_DTER			0x20
#define STA1_FB1			0x40
#define STA1_MB			0x80
// mask for system parameter
#define SYS_BAND			0x80
// mask for overwrite flag
#define MS_OVFLG_BKST       	0x80 
#define MS_OVFLG_PGST0      	0x40 
#define MS_OVFLG_PGST1      0x20 
#define MS_OVFLG_PGST			0x60
#define MS_OVFLG_UDST       0x10 
// mask for Management flag
#define MS_MANAFLG_ACCESS		0x20 
#define MS_MANAFLG_COPY			0x10 
#define MS_MANAFLG_PLTB			0x08 
#define MS_MANAFLG_SYS			0x04 


// Flash operation type for command parameter
#define	BLOCK_MODE			0
#define PAGE_MODE				0x20
#define	EXTRA_MODE			0x40
#define OVERWRITE_MODE		0x80

// definition of the constants
#define MS_PAGE_SIZE				512
#define MS_EXTRA_RSIZE			4
#define MS_SYS_DEFAULT			0x80
#define MS_SYS_PARALLEL			0x88
#define MS_BB_HEADER_SIZE		368
#define MS_BB_SYSTEM				48
#define BOOTBLOCK            0x8000
#define INITIAL_ERR           0xfffd
#define FATAL_ERR            0xfffe
#define MS_SUPPORT_TYPES		6			// suppport 4,8,32,16,64,128 Mbytes
#define MS_FREETABLE_SIZE		16
#define MS_LPTABLE_SIZE			496
#define MS_MBR_SIZE				16
#define BLOCKS_PER_SEGMENT		512

// flags
#define MS_FLAG_BAP					0x1	// boot area protecton
#define MS_FLAG_PARALLEL			0x2	// support parallel interface
#define MS_FLAG_PARALLEL_ENALBE	0x4	// parallel mode is enabled

// macros
#define MS_IS_TIMEOUT	(*(volatile kal_uint16*)MSC_STA & MSC_STA_TO)
#define MS_IS_CMDRDY		(*(volatile kal_uint16*)MSC_STA & MSC_STA_RDY)
#define MS_IS_INT			(*(volatile kal_uint16*)MSC_STA & MSC_STA_SIF)
#define MS_IS_CRCERR		(*(volatile kal_uint16*)MSC_STA & MSC_STA_CRCERR)
// Get low byte value from word value 
#define LOBYTE(w)               ((unsigned char)(w))
// Get high byte value from word value 
#define HIBYTE(w)             ((unsigned char)(((unsigned short)(w) >> 8) & 0xFF))
#define MS_IS_BLK_OK(x)			(((kal_uint8)(x) & MS_OVFLG_BKST) != 0)
#define MS_IS_BOOT_BLK(x)		(((kal_uint8)(x) & MS_MANAFLG_SYS) == 0)
#define MS_IS_LPTABLE(x)		(((kal_uint8)(x) & MS_MANAFLG_PLTB) == 0)
#define MS_IS_PAGE_OK(x)		(((kal_uint8)(x) & MS_OVFLG_PGST) == MS_OVFLG_PGST)
#define MS_IS_BLK_PAGE_OK(x)	(((kal_uint8)(x) & (MS_OVFLG_PGST|MS_OVFLG_BKST)) == (MS_OVFLG_PGST|MS_OVFLG_BKST))
#define MS_UPDATE_STATUS(x)	((kal_uint8)(x) & MS_OVFLG_UDST)

// error codes
#define MS_NOERROR			0
#define MS_ERR_TIMEOUT		1		// CMD busy time out(not INT timeout)
#define MS_ERR_CRCERR		2		// DATA crc error
#define MS_ERR_CMDNK			3		// CMD not accept
#define MS_ERR_EXECUTE		4		// During CMD execution
#define MS_ERRORS				5		// Unknown error
#define MS_ERR_UC				6		// Uncorrectable errors
#define MS_ERR_INT			7		// Int register err bit set
#define MS_ERR_STABUSY		8		// media busy or flash busy
#define MS_ERR_WRITEFAIL 	9
#define MS_ERR_ERASEFAIL	10	
#define MS_ERR_WP				11
#define MS_ERR_WAIT			12		// wait uintil ready, timeout and crc fail
#define MS_ERR_READBOOTBLK	13
#define MS_ERR_LPTABLE			14	// an error about LP translation table.
#define MS_ERR_CARD_NOT_PRESENT	18
#define MS_ERR_MEDIA			30		// Memory Stick media error
#define MS_ERR_EXPAND_IO	31		// Memory Stick media error
#define MS_ERR_NO_BOOT_BLK 32		// not boot blk
#define MS_ERR_INVALID_BOOTBLK	33

#define MS_LASTPAGE			50		// reach the last page

typedef enum{
	MS_4M,
	MS_8M,
	MS_16M,
	MS_32M,
	MS_64M,
	MS_128M,
	MS_SIZE_TOTAL
}ms_size_enum;

typedef enum{
	OVERWRITE_FLAG,
	MANAGE_FLAG,
	LADRS1,
	LADRS2,
	EXTRA_SIZE
}ms_extra_data_enum;

typedef struct{	
	kal_uint32 	TotalSectors;	// total disk sectors 	
	kal_uint32	DisBlk;				// number of disable of blocks
	kal_uint32	Flags;				// used to indicate various events
	kal_uint32	uc_pages;			// uncorrectable pages
	kal_uint32	de_pages;			// data err pages
	kal_uint16* pLPTbl;				// logical to physical address translation table
	kal_uint16*	pFreeTbl;			// a table for alternative blocks
	kal_uint16 	BlockSize;			// 8k or16k
	kal_uint16 	NumBlock;			// number of total blocks
	kal_uint16 	InfoBlk;				// physical block number of information block
	kal_uint8 	Capacity;			// number of Mbytes
	kal_uint8	PagesPerBlk;		// pages per block (16,32)
	kal_uint8	Seg;
	kal_uint8	FreeCnt;				// free alternative block numbers in the Seg
	kal_bool  	is_wp;				// write protect?
	kal_uint8	BootBlks[2];			// number of boot blocks
	ms_size_enum Size;				// disk size;
	kal_bool 	is_write;
}T_MS_HANDLE;

// extern global variables
extern T_MS_HANDLE gMS;

// function declaration
extern MS_STATUS MS_Initialize(void);
extern void MS_SetDefault(void);
extern kal_bool MS_CardDetect(void);
extern void MS_InvertN(kal_uint8* dest, kal_uint8* src, kal_uint8 len);
extern MS_STATUS MS_WaitCmdRdyOrTo(void);
extern void MS_SendTPC(kal_uint8 cmd, kal_uint32 size);
extern void MS_SetAcmd(kal_uint8 acmd, kal_uint32 asize);
extern MS_STATUS MS_TPC_ReadPage(kal_uint32* rxbuffer);
extern MS_STATUS MS_TPC_WritePage(kal_uint32* txbuffer);
extern MS_STATUS MS_TPC_ReadReg(kal_uint32* buffer, kal_uint8 length);
extern MS_STATUS MS_TPC_WriteReg(kal_uint32* buffer, kal_uint8 length);
extern MS_STATUS MS_TPC_SetRWAdrs(kal_uint8 r_adrs, kal_uint8 r_len, kal_uint8 w_adrs, kal_uint8 w_len);
extern MS_STATUS MS_TPC_GetInt(kal_uint8* intreg);
extern MS_STATUS MS_TPC_SetCmd(kal_uint8 cmd, kal_uint8* intreg);
extern MS_STATUS MS_API_ReadSinglePage(kal_uint32 blkadrs, kal_uint8 page, kal_uint32* rxbuffer, kal_uint32* extra);
extern MS_STATUS MS_API_ReadBlock(kal_uint32 blkadrs, kal_uint32* rxbuffer,kal_uint32* extra, kal_uint8 spage, kal_uint8 numpage, kal_uint8* readpage);
extern MS_STATUS MS_API_WriteSinglePage(kal_uint32 blkadrs,  kal_uint8 page, kal_uint32* txbuffer, kal_uint32 extra);
extern MS_STATUS MS_API_WriteBlock(kal_uint32 blkadrs, kal_uint32* txbuffer, kal_uint32* extra, kal_uint8 spage, kal_uint8 numpage, kal_uint8* writtenpage);
extern MS_STATUS MS_API_CopyPage(kal_uint32 w_blkadrs, kal_uint32 r_blkadrs, kal_uint8 spage,kal_uint8 numpage);
extern MS_STATUS MS_API_EraseBlock(kal_uint32 blkadrs);
extern MS_STATUS MS_API_ReadExtraData(kal_uint32 blkadrs, kal_uint8 page, kal_uint32* extra);
extern MS_STATUS MS_API_WriteExtraData(kal_uint32 blkadrs, kal_uint8 page, kal_uint32* extra);
extern MS_STATUS MS_API_OverwriteExtraData(kal_uint32 blkadrs, kal_uint8 page, kal_uint8 overwrite);
extern MS_STATUS MS_API_ResetFlash(void);
extern MS_STATUS MS_API_Sleep(void);
extern MS_STATUS MS_API_ClrBuffer(void);
extern MS_STATUS MS_API_Stop(void);
extern void MS_API_SetBlockNG(kal_uint32 pblk);
extern MS_STATUS MS_API_WriteOWF(kal_uint32 blkadrs, kal_uint8 page, kal_uint8 owf);
extern kal_uint16 MS_GetLPIndex(kal_uint32 ladrs);
MS_STATUS MS_API_LogToPhy(kal_uint16* lptbl, kal_uint32 ladrs, kal_uint32* padrs);
MS_STATUS MS_API_CheckLogicalAdrsValid(void);
MS_STATUS MS_BootAreaProtection(void);
MS_STATUS MS_AnalysisBB(kal_uint32* bootblk);
MS_STATUS MS_API_ReadBootBlk(void);
MS_STATUS MS_API_GenLPTable(kal_uint16* lptbl,kal_uint16* ftbl,kal_uint8 seg);
MS_STATUS MS_CheckBlockSize(kal_uint32 size, kal_uint32 blk_no, kal_uint32 eb);
MS_STATUS MS_API_ReOrgnizeLogicalAdrs(void);
MS_STATUS MS_MediaTypeIdentify(kal_uint8 type, kal_uint8 category, kal_uint8 _class, kal_uint8 status);
#endif // end of MS_DEF_H  


