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
 *   Sd_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of SD/MMC driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef SD_DEF_H
#define SD_DEF_H

#ifndef DRV_LSD
// registers address definition
#define SDC_CFG			(MSDC_ADRS+0x20)
#define SDC_CMD			(MSDC_ADRS+0x24)
#define SDC_ARG			(MSDC_ADRS+0x28)
#define SDC_STA			(MSDC_ADRS+0x2c)
#define SDC_RESP0		(MSDC_ADRS+0x30)
#define	SDC_RESP1	(MSDC_ADRS+0x34)
#define	SDC_RESP2	(MSDC_ADRS+0x38)
#define	SDC_RESP3	(MSDC_ADRS+0x3c)
// updated at 9/27
// #define SDC_EXESTA		(MSDC_ADRS+0x30)
#define SDC_CMDSTA		(MSDC_ADRS+0x40) // 16bits
#define SDC_DATSTA		(MSDC_ADRS+0x44) // 16bits	

#define SDC_CSTA			(MSDC_ADRS+0x48)
#define SDC_IRQMASK0		(MSDC_ADRS+0x4c)
#define SDC_IRQMASK1		(MSDC_ADRS+0x50)
#else
#define SDC_CFG			LSD_SDC_CFG
#define SDC_CMD			LSD_SDC_CMD
#define SDC_ARG			LSD_SDC_ARG
#define SDC_STA			LSD_SDC_STA
#define SDC_RESP0		LSD_SDC_RESP0
#define	SDC_RESP1		LSD_SDC_RESP1
#define	SDC_RESP2		LSD_SDC_RESP2
#define	SDC_RESP3		LSD_SDC_RESP3
#define SDC_CMDSTA		LSD_SDC_CMDSTA
#define SDC_DATSTA		LSD_SDC_DATSTA
#define SDC_CSTA		LSD_SDC_CSTA
#define SDC_IRQMASK0	LSD_SDC_IRQMASK0
#define SDC_IRQMASK1	LSD_SDC_IRQMASK1
#define SD_SPI_R1_ILLEGAL_CMD 4
#endif

#if defined(DRV_MSDC_MT6238_SERIES)
#define SDC_CFG2			(MSDC_ADRS2+0x20)
#define SDC_CMD2			(MSDC_ADRS2+0x24)
#define SDC_ARG2			(MSDC_ADRS2+0x28)
#define SDC_STA2			(MSDC_ADRS2+0x2c)
#define SDC_RESP02		(MSDC_ADRS2+0x30)
#define SDC_RESP12		(MSDC_ADRS2+0x34)
#define SDC_RESP22		(MSDC_ADRS2+0x38)
#define SDC_RESP32		(MSDC_ADRS2+0x3c)
#define SDC_CMDSTA2		(MSDC_ADRS2+0x40) // 16bits
#define SDC_DATSTA2		(MSDC_ADRS2+0x44) // 16bits	
#define SDC_CSTA2			(MSDC_ADRS2+0x48)
#define SDC_IRQMASK02   (MSDC_ADRS2+0x4c)
#define SDC_IRQMASK12	(MSDC_ADRS2+0x50)
#endif

// masks for SDC_CFG
#define SDC_CFG_BLKLEN		0x00000fff
#define SDC_CFG_BSYDLY		0x0000f000
// updated at 10/17
#define SDC_CFG_SIEN		0x00010000
#define SDC_CFG_MDLEN	0x00020000
#define SDC_CFG_WDOD		0x00f00000
#define SDC_CFG_DTOC		0xff000000
//#if defined(MT6228) || defined(MT6229) || defined (MT6227)
#define SDC_CFG_MDLEN8	0x00060000	// support MMC4.0 8-bit bus width
//#endif

// masks for SDC_CMD
#define SDC_CMD_CMD		0x003f
#define SDC_CMD_BREAK	0x0040
#define SDC_CMD_RSPTYP	0x0380
#define SDC_CMD_IDRT		0x0400
#define SDC_CMD_DTYPE	0x1800
#define SDC_CMD_RW		0x2000
#define SDC_CMD_STOP		0x4000
#define SDC_CMD_INTC		0x8000

// masks for SDC_STA
#define SDC_STA_SDCBUSY		0x0001
#define SDC_STA_CMDBUSY		0x0002
#define SDC_STA_DATBUSY		0x0004
#define SDC_STA_R1BSY		0x0010
#define SDC_STA_WP			0x8000

// masks for SDC_CMDSTA
#define SDC_CMDSTA_CMDRDY		0x0001
#define SDC_CMDSTA_CMDTO		0x0002
#define SDC_CMDSTA_RSPCRCERR	0x0004
#define SDC_CMDSTA_MMCIRQ		0x0008

// maske for SDC_DATSTA
#define SDC_DATSTA_BLKDONE		0x0001
#define SDC_DATSTA_DATTO		0x0002
#define SDC_DATSTA_DATCRCERR	0x0004

//masks for command error response(32) of SDC_CSTA
#define SDC_OUT_OF_RANGE			0x80000000
#define SDC_ADDRESS_ERROR			0x40000000
#define SDC_BLOCK_LEN_ERROR		0X20000000
#define SDC_ERASE_SEQ_ERROR		0X10000000
#define SDC_ERASE_PARAM				0X08000000
#define SDC_WP_VIOLATION			0X04000000
#define SDC_CARD_IS_LOCKED			0x02000000
#define SDC_LOCK_UNLOCK_FAILED	0X01000000
#define SDC_COM_CRC_ERROR			0X00800000
#define SDC_ILLEGAL_COMMAND		0X00400000
#define SDC_CARD_ECC_FAILED			0X00200000
#define SDC_CC_ERROR					0X00100000
#define SDC_ERROR						0X00080000
#define SDC_UNDERRUN					0X00040000
#define SDC_OVERRUN					0X00020000
#define SDC_CIDCSD_OVERWRITE		0X00010000
#define SDC_AKE_SEQ_ERROR			0X00000008

#define SDC_CSTA_MASK 				0xffff0000

//masks for card status contained in R1
#define R1_AKE_SEQ_ERROR_3				0x00000004
#define R1_APP_CMD_5						0x00000020
#define R1_READY_FOR_DATA_8			0x00000100
#define R1_CURRENT_STATE_9_12			0x00001e00
#define R1_ERASE_RESET_13				0x00002000
#define R1_CARD_ECC_DISABLE_14			0x00004000
#define R1_WP_ERASE_SKIP_15			0x00008000
#define R1_CID_CSD_OVERWRITE_16		0x00010000
#define R1_OVERRUN_17					0x00020000
#define R1_UNDERRUN_18					0x00040000
#define R1_ERROR_19						0x00080000
#define R1_CC_ERROR_20					0x00100000
#define R1_CARD_ECC_FAILED_21			0x00200000
#define R1_ILLEGAL_COMMAND_22			0x00400000
#define R1_COM_CRC_ERROR_23			0x00800000
#define R1_LOCK_UNLOCK_FAILED_24		0x01000000
#define R1_CARD_IS_LOCKED_25			0x02000000
#define R1_WP_VIOLATION_26				0x04000000
#define R1_ERASE_PARAM_27				0x08000000
#define R1_ERASE_SEQ_ERROR_28			0x10000000
#define R1_BLOCK_LEN_ERROR_29			0x20000000
#define R1_ADDRESS_ERROR_30			0x40000000
#define R1_OUT_OF_RANGE_31				0x80000000
#define R1_CUR_STATE						0x00001E00

#define CurState(a)	(kal_uint32)(((a) & R1_CUR_STATE) >> 9)

#define SD_RW_ERRORS	(R1_OUT_OF_RANGE_31|R1_ADDRESS_ERROR_30|R1_ERASE_PARAM_27|R1_WP_VIOLATION_26|R1_CARD_IS_LOCKED_25|R1_LOCK_UNLOCK_FAILED_24 \
						|R1_COM_CRC_ERROR_23|R1_ILLEGAL_COMMAND_22|R1_CARD_ECC_FAILED_21|R1_CC_ERROR_20|R1_ERROR_19 \
						|R1_UNDERRUN_18|R1_OVERRUN_17|R1_CID_CSD_OVERWRITE_16|R1_WP_ERASE_SKIP_15|R1_CARD_ECC_DISABLE_14\
						|R1_ERASE_RESET_13)

#define SD_COM_ERRORS	(R1_OUT_OF_RANGE_31|R1_ERASE_PARAM_27|R1_WP_VIOLATION_26|R1_CARD_IS_LOCKED_25|R1_LOCK_UNLOCK_FAILED_24 \
						|R1_COM_CRC_ERROR_23|R1_ILLEGAL_COMMAND_22|R1_CARD_ECC_FAILED_21|R1_CC_ERROR_20|R1_ERROR_19 \
						|R1_UNDERRUN_18|R1_OVERRUN_17|R1_CID_CSD_OVERWRITE_16|R1_WP_ERASE_SKIP_15|R1_CARD_ECC_DISABLE_14\
						|R1_ERASE_RESET_13)

/* MMC bus commands */
#define CMD0_GO_IDLE_STATE          0x00    /* Resets the MMC */
#define CMD1_SEND_OP_COND           0x01    /* Activates the card's initialization process */
#define CMD2_ALL_SEND_CID           0x02    /* Asks all cards in ready state to send their CID */
#define CMD3_SET_RELATIVE_ADDR      0x03    /* Assigns relative address to the card in identification state */
#define CMD4_SET_DSR                0x04    /* Sets drive stage register DSR */
#define CMD7_SELECT_CARD            0x07
#define CMD9_SEND_CSD               0x09    /* Asks the selected card to send its CSD */
#define CMD10_SEND_CID              0x0A    /* Asks the selected card to send its CID */
#define CMD11_READ_DAT_UNTIL_STOP_MMC   0x0B
#define CMD12_STOP_TRANSMISSION     0x0C    /* Stop data transmission */
#define CMD13_SEND_STATUS           0x0D    /* Asks the selected card to send its status register */
#define CMD15_GO_INACTIVE_STATE     0x0F
#define CMD16_SET_BLOCKLEN          0x10    /* Selects a block length for all following block commands */
#define CMD17_READ_SINGLE_BLOCK     0x11    /* Reads a block of the size selected by the SET_BLOCKLEN command */
#define CMD18_READ_MULTIPLE_BLOCK   0x12
#define CMD20_WRITE_DAT_UNTIL_STOP_MMC  0x14
#define CMD24_WRITE_SINGLE_BLOCK    0x18    /* Writes a block of the size selected by SET_BLOCKLEN command */
#define CMD25_WRITE_MULTIPLE_BLOCK  0x19     /* Writes multiple block until CMD 12 */
#define CMD26_PROGRAM_CID           0x1A
#define CMD27_PROGRAM_CSD           0x1B    /* Programming of the programmable bits of the CSD */
#define CMD28_SET_WRITE_PROT        0x1C    /* If the card has write protection features, sets the write protection bit */
#define CMD29_CLR_WRITE_PROT        0x1D    /* If with write protection features, clears the write protection bit */
#define CMD30_SEND_WRITE_PROT       0x1E    /* If with write protection features, asks the card to send status of write protection bit */
#define CMD32_TAG_SECTOR_START      0x20    /* Sets the address of the first sector */
#define CMD33_TAG_SECTOR_END        0x21    /* Sets the address of the last sectore */
#define CMD34_UNTAG_SECTOR          0x22    /* Removes one previously selected sector */
#define CMD35_TAG_ERASE_GROUP_START 0x23    /* Sets the address of the first erase group */
#define CMD36_TAG_ERASE_GROUP_END   0x24    /* Sets the address of the last erase group */
#define CMD37_UNTAG_ERASE_GROUP     0x25    /* Removes on previously selected erase group */
#define CMD38_ERASE                 0x26    /* Erases all previously selected sectors */
#define CMD39_FAST_IO_MMC           0x27
#define CMD40_GO_IRQ_STATE          0x28    
#define CMD42_LOCK_UNLOCK           0x2A    /* Used to set/reset the password or lock/unlock the card */
#define CMD55_APP					0x37	/* Indicates to the card the next cmd is an application specific command */
#define CMD56_GEN					0x38	/* Used either to transfer a data block or to get a data block form the card for general purpse */

// commnad value for MSDC controller SDC_CMD
#define SDC_CMD_CMD0	         0x0000
#define SDC_CMD_CMD1	         0x0181
#define SDC_CMD_CMD2	         0x0502
#define SDC_CMD_CMD3_SD	     0x0303
#define SDC_CMD_CMD3_MMC    0x0083
#define SDC_CMD_CMD4	         0x0004
#define SDC_CMD_CMD7	         0x0387
//#define SDC_CMD_CMD7	         0x0087
#define SDC_CMD_CMD8				0x0088
#define SDC_CMD_CMD9	         0x0109
#define SDC_CMD_CMD10	         0x010a	// the response time delay is not NID(5 cycles)
#define SDC_CMD_CMD11_MMC		 0x188b 
#define SDC_CMD_CMD12	         0x438c	
//#define SDC_CMD_CMD12	         0x038c	// remove STOP bit 
#define SDC_CMD_CMD13	         0x008d
#define SDC_CMD_CMD15	         0x000f
#define SDC_CMD_CMD16	         0x0090
#define SDC_CMD_CMD17	         0x0891
#define SDC_CMD_CMD18	         0x1092
#define SDC_CMD_CMD20_MMC        0x3894
#define SDC_CMD_CMD24	         0x2898
//#define SDC_CMD_CMD24	         0x2b98	// use R1b to replace R1 write single block
#define SDC_CMD_CMD25	         0x3099
//#define SDC_CMD_CMD25	         0x3399	// use R1b to replace R1 write single block
#define SDC_CMD_CMD26	         0x009a
#define SDC_CMD_CMD27	         0x009b
#define SDC_CMD_CMD28	         0x039c
#define SDC_CMD_CMD29	         0x039d
#define SDC_CMD_CMD30	         0x089e
#define SDC_CMD_CMD32	         0x00a0
#define SDC_CMD_CMD33	         0x00a1
#define SDC_CMD_CMD34_MMC        0x00a2
#define SDC_CMD_CMD35_MMC        0x00a3
#define SDC_CMD_CMD36_MMC        0x00a4
#define SDC_CMD_CMD37_MMC        0x00a5
#define SDC_CMD_CMD38	         0x03a6
#define SDC_CMD_CMD39_MMC        0x0227
#define SDC_CMD_CMD40_MMC        0x82a8
#define SDC_CMD_CMD41_SD         0x01a9     
#define SDC_CMD_CMD42	         0x2baa     
#define SDC_CMD_CMD55	         0x00b7     
#define SDC_CMD_CMD56	         0x00b8
#define SDC_CMD_ACMD6			 0x0086
#define SDC_CMD_ACMD13			 0x088d
#define SDC_CMD_ACMD22			 0x0896
#define SDC_CMD_ACMD23			 0x0097	
#define SDC_CMD_ACMD42			 0x00aa
#define SDC_CMD_ACMD51			 0x08b3	

// for MMC4.0
#define SDC_CMD_CMD6_MMC40			0x0386	// SWITCH
#define SDC_CMD_CMD8_MMC40			0x0888	// SEND_EXT_CSD

#define SDC_CMD_CMD6_SD11			0x0886	// SWITCH
/* SDIO command*/
#define SDC_CMD_CMD5				0x0185	// use R3 to replace R4
#define SDC_CMD_CMD52			0x02b4	// STOp field will be set while used to Stop data transfer
#define SDC_CMD_CMD53			0x01b5	// the RWand DTYPE will be changed according request
// bit masks     
#define BIT_MASK_1 0x01
#define BIT_MASK_2 0x03
#define BIT_MASK_3 0x07
#define BIT_MASK_4 0x0F
#define BIT_MASK_5 0x1F
#define BIT_MASK_6 0x3F
#define BIT_MASK_7 0x7F
#define BIT_MASK_8 0xFF

// useful macros
#define SD_IS_BLKDONE		(*(volatile kal_uint16*)SDC_DATSTA & SDC_DATSTA_BLKDONE)
#define SD_IS_DATA_CRCERR	(*(volatile kal_uint16*)SDC_DATSTA & SDC_DATSTA_DATCRCERR)
#define SD_IS_DATA_TIMEOUT  (*(volatile kal_uint16*)SDC_DATSTA & SDC_DATSTA_DATTO)
#define SD_IS_RSP_CRCERR	(*(volatile kal_uint16*)SDC_CMDSTA & SDC_CMDSTA_CMDCRCERR)
#define SD_IS_CMD_TIMEOUT	(*(volatile kal_uint16*)SDC_CMDSTA & SDC_CMDSTA_CMDTO)
#define SD_IS_CMD_READY		(*(volatile kal_uint16*)SDC_CMDSTA & SDC_CMDSTA_CMDRDY)
#define SD_IS_MMC_IRQ		(*(volatile kal_uint16*)SDC_CMDSTA & SDC_CMDSTA_MMCIRQ)
#define SD_IS_CMD_BUSY   	(*(volatile kal_uint16*)SDC_STA & SDC_STA_CMDBUSY)
#define SD_IS_DAT_BUSY   	(*(volatile kal_uint16*)SDC_STA & SDC_STA_DATBUSY)
#define SD_IS_SDC_BUSY   	(*(volatile kal_uint16*)SDC_STA & SDC_STA_SDCBUSY)
#ifndef DRV_LSD
#define SD_IS_R1B_BUSY   	(*(volatile kal_uint16*)SDC_STA & SDC_STA_R1BSY)
#else
#define SD_IS_R1B_BUSY		LSD_HostDetectBusy()
#endif

#if defined(__MSDC2_SD_MMC__)||defined(__MSDC2_SD_SDIO__)
#define SD_IS_BLKDONE_2		(*(volatile kal_uint16*)SDC_DATSTA2 & SDC_DATSTA_BLKDONE)
#define SD_IS_DATA_CRCERR_2	(*(volatile kal_uint16*)SDC_DATSTA2 & SDC_DATSTA_DATCRCERR)
#define SD_IS_DATA_TIMEOUT_2  (*(volatile kal_uint16*)SDC_DATSTA2 & SDC_DATSTA_DATTO)
#define SD_IS_RSP_CRCERR_2	(*(volatile kal_uint16*)SDC_CMDSTA2 & SDC_CMDSTA_CMDCRCERR)
#define SD_IS_CMD_TIMEOUT_2	(*(volatile kal_uint16*)SDC_CMDSTA2 & SDC_CMDSTA_CMDTO)
#define SD_IS_CMD_READY_2		(*(volatile kal_uint16*)SDC_CMDSTA2 & SDC_CMDSTA_CMDRDY)
#define SD_IS_MMC_IRQ_2		(*(volatile kal_uint16*)SDC_CMDSTA2 & SDC_CMDSTA_MMCIRQ)
#define SD_IS_CMD_BUSY_2   	(*(volatile kal_uint16*)SDC_STA2 & SDC_STA_CMDBUSY)
#define SD_IS_DAT_BUSY_2   	(*(volatile kal_uint16*)SDC_STA2 & SDC_STA_DATBUSY)
#define SD_IS_SDC_BUSY_2   	(*(volatile kal_uint16*)SDC_STA2 & SDC_STA_SDCBUSY)
#define SD_IS_R1B_BUSY_2   	(*(volatile kal_uint16*)SDC_STA2 & SDC_STA_R1BSY)
#endif

#define GET_BIT(byte, bit_pos, bit_mask)    (((byte) & ((bit_mask)<<(bit_pos)))>> (bit_pos))
	
// default values
typedef kal_uint32				SDC_CMD_STATUS;

#define SDC_OCR_DEFAULT		0x00FF8000
#define SDC_OCR_QUERY		0x0
#define TRY_OCR				20 
#define SDC_OCR_BUSY			0x80000000
#define SDC_RCA_DEFAULT		0x0000
#define	ARG_RCA_MASK		0xffff0000
#define SDC_RCA_MMC			1
#define SDC_DSR_DEFAULT		0x0404
#define SDC_NO_ARG			0
#define SDC_MAX_BKLENGTH	2048
#define SDC_MAX_LOCKBK		34
#define SDC_CMD8_ARG			0x000001AA			// the argument of the CMD8
#define SD_ACMD41_HCS		0x40000000			// indicate host support high capacity card.
#define SD_CMD6_RESP_LEN	64						// lenght of the CMD6 response
#define SD_CMD6_QUERY_HIGH_SPEED		0x00FFFFF1	// argument of CMD6 to query the high speed interface
#define SD_CMD6_SELECT_HIGH_SPEED	0x80FFFFF1	// argument of CMD6 to query the high speed interface
#define SD_FUNC_HIGH_SPEED				0x1
#define SD_CSD_VER_20					0x01

#define SD_FLAG_MMC_MRSW_FAIL  (0x01)		// some special MMC card will fail at multi-read follow a single wirte
#define SD_FLAG_HCS_SUPPORT	 (0x02)		// support block access mode
#define SD_FLAG_CMD6_SUPPORT	 (0x04)		// support CMD6 (SD1.1 higher)
#define SD_FLAG_HS_SUPPORT		 (0x08)		// support high speed interface (SD1.1 higher)
#define SD_FLAG_HS_ENABLED		 (0x10)		// enable high speed interface (SD1.1 higher)	
#define SD_FLAG_SD_TYPE_CARD	 (0x20)		// to indicate SD or MMC type card
#define SD_FLAG_USE_USB_CLK	 (0x40)		// to indicate use USB clock 

// ERROR definition of SDC_CMD_STATUS
#define NO_ERROR				0
#define ERR_CMD_TIMEOUT			1
#define ERR_APP_CMD_NOT_ACCEPT	2
#define ERR_R3_OCR_BUSY			3
#define ERR_RCA_FAIL			4
#define ERR_INVALID_CARD		5
#define ERR_INVALID_BKLENGTH	6  // over 2048 or not multiple of 4
#define ERR_DAT_CRCERR			7
#define ERR_RW_CMDERR			8
#define ERR_CMD_RSPCRCERR		9
#define ERR_DAT_TIMEOUT			10
#define ERR_STATUS				11
#define ERR_LOCK_UNLOCK_FAILED  12
#define ERR_APPCMD_FAILED		13
#define ERR_NOT_SUPPORT_4BITS   14
#define ERR_NORESP				15
#define ERR_WRITE_PROTECT		16
#define ERR_DATA_NOT_READY		17
#define ERR_CARD_NOT_PRESENT	18
#define ERR_OCR_NOT_SUPPORT	19
#define ERR_DAT_ERROR			20
#define SDIO_4MI_NOT_SUPPORT  21
#define ERR_MMC_BUS_HS_ERROR	22
#define ERR_SendEXTCSD			23
#define ERR_CMD8_INVALID		24
#define ERR_SD_HS_FAIL			25		// SD change high speed interface fail

#define CARD_IS_LOCKED			60

#define ERR_ERRORS				30	// general errors

//enums
typedef enum{
	SET_PWD,
	CLR_PWD,
	LOCK_CARD,
	UNLOCK_CARD,
	ERASE
}SD_LOCK_OP;

typedef enum{
	BIT_1W = 0x0000,
	BIT_4W = 0x0002
}SD_BITWIDTH;
 typedef enum{
	CSD_VER_1_0 = 0,
	CSD_VER_1_1 = 0,
	CSD_VER_2_0 = 1,
	CSD_VER_EXT
 }CSD_VER_ENUM;

typedef enum {
	IDLE_STA,
	READY_STA,
	IDENT_STA,
	STBY_STA,
	TRAN_STA,
	DATA_STA,
	RCV_STA,
	PRG_STA,
	DIS_STA,
	INV_STA
}T_SDC_STATE;

// MMC40
typedef enum{
	CMD_SET,
	SET_BIT,
	CLR_BIT,
	SET_BYTE
}CMD6_ACCESS_MODE;

typedef enum{
	BIT_1_MMC40,
	BIT_4_MMC40,
	BIT_8_MMC40
}BUS_WIDHT_MMC40;

typedef enum{
	HS_26M = 1,
	HS_52M = 2
}EXT_CSD_CARD_TYPE_MMC40;

typedef enum{
	SD_CMD8_RESP_NORESP,		// before SD2.0 version or MMC
	SD_CMD8_RESP_INVALID,	// SD 2.0 or higher compliant but voltage condition is not allow
	SD_CMD8_RESP_VALID		// SD 2.0 or higher compliant
}SD_CMD8_RESP;

typedef enum{
	SD_SPEC_101,
	SD_SPEC_110,
	SD_SPEC_200
}SD_SPEC;

#define MSDC_SD_BLOCK_SIZE				128	// x4 bytes
#define EXT_CSD_BUS_WIDTH_INDEX		183
#define EXT_CSD_HIGH_SPPED_INDEX		185
#define EXT_CSD_POW_CLASS_INDEX		187
#define EXT_CSD_ENABLE_HIGH_SPEED	1
#define MMC_HIGH_DESITY_CHECK_BIT	(0x40000000)
#define MMC_HIGH_DESITY_CHECK_MSK	(0x60000000)

// structures	
typedef struct {
	kal_uint8 rev1[183];
	kal_uint8 bus_width;
	kal_uint8 rev2;
	kal_uint8 high_speed;
	kal_uint8 rev3;
	kal_uint8 power_class;
	kal_uint8 rev4;
	kal_uint8 cmd_set_rev;
	kal_uint8 rev5;
	kal_uint8 cmd_set;
	kal_uint8 ext_csd_rev;
	kal_uint8 rev7;
	kal_uint8 ext_csd_ver;
	kal_uint8 rev8;
	kal_uint8 card_type;
	kal_uint8 rev9[3];
	kal_uint8 pwr_52_195;
	kal_uint8 pwr_26_195;
	kal_uint8 pwr_52_360;
	kal_uint8 pwr_26_360;
	kal_uint8 rev10;
	kal_uint8 min_perf_r_4_26;
	kal_uint8 min_perf_w_4_26;
	kal_uint8 min_perf_r_8_26_4_52;
	kal_uint8 min_perf_w_8_26_4_52;
	kal_uint8 min_perf_r_8_52;
	kal_uint8 min_perf_w_8_52;
	kal_uint8 resv11;
	kal_uint32 sec_count;	/*newly defined in MMC42*/
	kal_uint8 rev12[288];
	kal_uint8 s_cmd_set;
	kal_uint8 rev13[7];	
}T_EXT_CSD_MMC40;
	
/* Card Specific Data(CSD) register structure */
typedef struct {
   kal_uint8   tacc;				   /* read access time-1 */
   kal_uint8   nsac;				   /* read access time-2 */
   kal_uint8   tran_speed;			   /* max. data transfer rate */
   kal_uint16  ccc;					   /* card command classes */
   kal_uint32  w_blk_len;              /* actual write block length in bytes */
   kal_uint32  r_blk_len;              /* actual read block length in bytes */
   kal_uint32  max_w_blk_len;          /* max write data block length */
   kal_uint32  max_r_blk_len;          /* max read data block length */
   kal_uint8   w_blk_misali;           /* write block misalighment */
   kal_uint8   r_blk_misali;           /* read block misalighment */
   kal_uint8   w_blk_part;             /* partial blocks for write allowed */
   kal_uint8   r_blk_part;             /* partial blocks for write allowed */
   kal_uint32  erase_sec_size_mmc;     /* erase sector size */
   kal_uint32  erase_grp_size_mmc;     /* erase group size */
   kal_uint32  wp_grp_size_mmc;        /* write protect group size */
   kal_uint8   erase_blk_en_sd;			
   kal_uint32  erase_sec_size_sd;   
   kal_uint32  wp_prg_size_sd;
   kal_uint8   wp_grp_enable;          /* write protect group enable */
   kal_uint64  capacity;               /* capacity in bytes */
   kal_uint16  cmd_class;              /* card command classes */
   kal_uint8   temp_wp;                /* temporary write protection  */
   kal_uint8   perm_wp;                /* permanent write protection  */
   kal_uint8   dsr_imp;
   CSD_VER_ENUM 	csd_ver;					/* the version of CSD structure */
   kal_uint8	spec_ver;					/* defne the MMC system spec. */
   T_EXT_CSD_MMC40 *ext_csd;				/* pointer to EXT_CSD */
} T_CSD;

typedef struct {
	kal_uint8	mid;
	kal_uint16	oid;
	kal_uint8	pnm[6];
	kal_uint8	prv;
	kal_uint32	psn;
	kal_uint16	year;
	kal_uint8	month;
}T_CID;

typedef struct {
	kal_uint8 dat_after_erase;
	kal_uint8 security;
	kal_uint8 bus_width;
	SD_SPEC spec_ver;
}T_SCR;

typedef struct{
	kal_uint32 max_current	: 16;
	kal_uint32 group6_info	: 16;
	kal_uint32 group5_info	: 16;
	kal_uint32 group4_info	: 16;
	kal_uint32 group3_info	: 16;
	kal_uint32 group2_info	: 16;
	kal_uint32 group1_info	: 16;
	kal_uint32 group6_result: 4;
	kal_uint32 group5_result: 4;
	kal_uint32 group4_result: 4;
	kal_uint32 group3_result: 4;
	kal_uint32 group2_result: 4;
	kal_uint32 group1_result: 4;
	kal_uint32 ver				: 8;
	kal_uint32 group6_busy	: 16;
	kal_uint32 group5_busy	: 16;
	kal_uint32 group4_busy	: 16;
	kal_uint32 group3_busy	: 16;
	kal_uint32 group2_busy	: 16;
	kal_uint32 group1_busy	: 16;	
	kal_uint8  rev[34];
}T_SWITCH_STATUS;
	
typedef struct {
	kal_uint32		mSDC_ocr;	// store the OCR
	kal_uint32		mBKLength;	// store the block length
	kal_uint32 		mBKNum;		// store the block numbers
	kal_uint32		flags;		// for some special case handling 	
	T_CSD				mCSD;		// card specific data
	T_CID				mCID;		// card idendtification
	T_SCR				mSCR;		// only for SD
	kal_uint16		mRCA;		// store relative card address
	T_SDC_STATE		mState;		// indicate the current state
	kal_bool			mInactive;	// indicate whether card in inactive state
	kal_uint8		bus_width;	// indicate 4-bits data line enable	
	kal_bool			mWPEnabled;	// indicate write protection is enabled(SD) 
	kal_bool			mIsLocked;	// indicate whether the card is locked by switch
	kal_bool			mCD_DAT3;	// indicate the pull-up resistor of CD_DAT3 pin
	SD_CMD8_RESP	mCMD8Resp;		// receive response after CMD8 (SD2.0 or higher)
}T_SDC_HANDLE;

extern T_SDC_HANDLE *gSD;
extern T_SDC_HANDLE	gSD_blk[SD_NUM];

void SD_AnalysisCSD(kal_uint32* csd);
void SD_AnalysisCID(kal_uint32* cid);
void SD_AnalysisSCR(kal_uint32* scr);
SDC_CMD_STATUS SD_WaitCmdRdyOrTo(void);
SDC_CMD_STATUS SD_WaitCardNotBusy(void);
SDC_CMD_STATUS SD_WaitDatRdyOrTo(void);
SDC_CMD_STATUS SD_CheckStatus(void);
SDC_CMD_STATUS SD_Send_Cmd(kal_uint32 cmd, kal_uint32 arg);
SDC_CMD_STATUS SD_Reset(void);
SDC_CMD_STATUS SD_Cmd55(kal_uint16 rca);
SDC_CMD_STATUS SD_Cmd56(kal_uint32* buffer, kal_bool IsWrite);
SDC_CMD_STATUS SD_Cmd1_MMC(void);
SDC_CMD_STATUS SD_Acmd41_SD(void);
SDC_CMD_STATUS SD_GetCID(kal_uint32 Cid[4]);
SDC_CMD_STATUS SD_ValidateRCA(kal_uint16* pRca);
SDC_CMD_STATUS SD_SetDSR(void);
SDC_CMD_STATUS SD_SelectCard(kal_uint16 rca);
SDC_CMD_STATUS SD_GetCSD(kal_uint16 rca, kal_uint32 Csd[4]);
SDC_CMD_STATUS SD_GetAddressedCID(kal_uint16 rca, kal_uint32 Cid[4]);
SDC_CMD_STATUS SD_ReadStream_MMC(kal_uint32 address, kal_uint32* rx_buffer, kal_uint32 size);
SDC_CMD_STATUS SD_StopTrans(kal_bool);
SDC_CMD_STATUS SD_GetStatus(kal_uint16 rca, kal_uint32* resp);
SDC_CMD_STATUS SD_GoInactive(kal_uint16 rca);
SDC_CMD_STATUS SD_SetBlength(kal_uint32 BKLength);
SDC_CMD_STATUS SD_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer);
SDC_CMD_STATUS SD_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num);
SDC_CMD_STATUS SD_WriteStream_MMC(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 bytes);
SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer);
SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32*, kal_uint32);
SDC_CMD_STATUS SD_ProgramCSD(kal_uint32 Csd[4]);
SDC_CMD_STATUS SD_SetWriteProtect(kal_uint32 address);
SDC_CMD_STATUS SD_ClrWriteProtect(kal_uint32 address);
SDC_CMD_STATUS SD_SendWriteProtect(kal_uint32 address, kal_uint32* WPBits32);
SDC_CMD_STATUS SD_EraseCmdClass(kal_uint32 cmd ,kal_uint32 address);
SDC_CMD_STATUS SD_FastIO_MMC(kal_uint16 rca, kal_bool isWrite, kal_uint8 reg_adrs, kal_uint8 data);
SDC_CMD_STATUS SD_GoIRQ_MMC(void);
SDC_CMD_STATUS SD_LockUnlock(SD_LOCK_OP op, char* Oldpwd, char* Newpwd, kal_uint8 Oldlen,kal_uint8 Newlen);
SDC_CMD_STATUS SD_SetBusWidth(SD_BITWIDTH width);
SDC_CMD_STATUS SD_ReadSCR(kal_uint32* scr);
SDC_CMD_STATUS SD_GetSDStatus(kal_uint32* sd_status);
SDC_CMD_STATUS SD_GetNumWrittenBlk(kal_uint32* num);
SDC_CMD_STATUS SD_SetPreEraseBlk(kal_uint32 num);
SDC_CMD_STATUS SD_SetCardDetect(kal_uint8 detect);
void SD_Cmd8(void);
SDC_CMD_STATUS SD_SelectHighSpeed_SD11(void);
SDC_CMD_STATUS SD_Switch_SD11(kal_uint32 arg, T_SWITCH_STATUS* info);

// MMC4.0
SDC_CMD_STATUS SD_Switch_MMC40(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set);
SDC_CMD_STATUS SD_SendEXTCSD_MMC40(kal_uint32* rxbuffer);

// sd.c
SDC_CMD_STATUS SD_Initialize(void);
T_MSDC_CARD SD_CheckSDorMMC(void);
void SD_SetDefault(void);
kal_bool SD_CardDetect(void);

#if defined(__MSDC2_SD_MMC__)  || defined(__MSDC2_SD_SDIO__)
void SD_AnalysisCSD_2(kal_uint32* csd);
void SD_AnalysisCID_2(kal_uint32* cid);
void SD_AnalysisSCR_2(kal_uint32* scr);
SDC_CMD_STATUS SD_WaitCmdRdyOrTo_2(void);
SDC_CMD_STATUS SD_WaitCardNotBusy_2(void);
SDC_CMD_STATUS SD_WaitDatRdyOrTo_2(void);
SDC_CMD_STATUS SD_CheckStatus_2(void);
SDC_CMD_STATUS SD_Send_Cmd_2(kal_uint32 cmd, kal_uint32 arg);
SDC_CMD_STATUS SD_Reset_2(void);
SDC_CMD_STATUS SD_Cmd55_2(kal_uint16 rca);
SDC_CMD_STATUS SD_Cmd56_2(kal_uint32* buffer, kal_bool IsWrite);
SDC_CMD_STATUS SD_Cmd1_MMC_2(void);
SDC_CMD_STATUS SD_Acmd41_SD_2(void);
SDC_CMD_STATUS SD_GetCID_2(kal_uint32 Cid[4]);
SDC_CMD_STATUS SD_ValidateRCA_2(kal_uint16* pRca);
SDC_CMD_STATUS SD_SetDSR_2(void);
SDC_CMD_STATUS SD_SelectCard_2(kal_uint16 rca);
SDC_CMD_STATUS SD_GetCSD_2(kal_uint16 rca, kal_uint32 Csd[4]);
SDC_CMD_STATUS SD_GetAddressedCID_2(kal_uint16 rca, kal_uint32 Cid[4]);
SDC_CMD_STATUS SD_ReadStream_MMC_2(kal_uint32 address, kal_uint32* rx_buffer, kal_uint32 size);
SDC_CMD_STATUS SD_StopTrans_2(kal_bool);
SDC_CMD_STATUS SD_GetStatus_2(kal_uint16 rca, kal_uint32* resp);
SDC_CMD_STATUS SD_GoInactive_2(kal_uint16 rca);
SDC_CMD_STATUS SD_SetBlength_2(kal_uint32 BKLength);
SDC_CMD_STATUS SD_ReadSingleBlock_2(kal_uint32 data_adrs, kal_uint32* rxbuffer);
SDC_CMD_STATUS SD_ReadMultiBlock_2(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num);
SDC_CMD_STATUS SD_WriteStream_MMC_2(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 bytes);
SDC_CMD_STATUS SD_WriteSingleBlock_2(kal_uint32 address, kal_uint32* txbuffer);
SDC_CMD_STATUS SD_WriteMultiBlock_2(kal_uint32 address, kal_uint32*, kal_uint32);
SDC_CMD_STATUS SD_ProgramCSD_2(kal_uint32 Csd[4]);
SDC_CMD_STATUS SD_SetBusWidth_2(SD_BITWIDTH width);
SDC_CMD_STATUS SD_ReadSCR_2(kal_uint32* scr);
SDC_CMD_STATUS SD_GetSDStatus_2(kal_uint32* sd_status);
SDC_CMD_STATUS SD_GetNumWrittenBlk_2(kal_uint32* num);
SDC_CMD_STATUS SD_SetPreEraseBlk_2(kal_uint32 num);
SDC_CMD_STATUS SD_SetCardDetect_2(kal_uint8 detect);
void SD_Cmd8_2(void);
SDC_CMD_STATUS SD_SelectHighSpeed_SD11_2(void);
SDC_CMD_STATUS SD_Switch_SD11_2(kal_uint32 arg, T_SWITCH_STATUS* info);
SDC_CMD_STATUS SD_Switch_MMC40_2(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set);
SDC_CMD_STATUS SD_SendEXTCSD_MMC40_2(kal_uint32* rxbuffer);
SDC_CMD_STATUS SD_Initialize_2(void);
T_MSDC_CARD SD_CheckSDorMMC_2(void);
void SD_SetDefault_2(void);
kal_bool SD_CardDetect_2(void);
#endif

/*following 2 API is used to declare the beginning and ending of high level format*/
void SD_startFastFormat(void);
void SD_closeFastFormat(void);

#endif // end of SD_DEF_H


