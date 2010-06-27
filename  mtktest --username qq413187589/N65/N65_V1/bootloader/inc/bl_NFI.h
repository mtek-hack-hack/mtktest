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
 *   bl_NFI.h
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   Item test - NANDFlash test.
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

#ifndef _BOOTLOADER_NFI_H
#define _BOOTLOADER_NFI_H

/* Register definition */
#define NFI_base        (0x80090000)
#define NFI_ACCCON      ((volatile kal_uint16 *)(NFI_base+0x0000))
#define NFI_PAGEFMT     ((volatile kal_uint16 *)(NFI_base+0x0004))
#define NFI_OPCON       ((volatile kal_uint16 *)(NFI_base+0x0008))
#define NFI_CMD         ((volatile kal_uint16 *)(NFI_base+0x000C))
#define NFI_ADDNOB      ((volatile kal_uint16 *)(NFI_base+0x0010))
#define NFI_ADDRL       ((volatile kal_uint32 *)(NFI_base+0x0014))
#define NFI_ADDRM       ((volatile kal_uint16 *)(NFI_base+0x0018))
#define NFI_DATAW       ((volatile kal_uint32 *)(NFI_base+0x001C))
#define NFI_DATAWB      ((volatile kal_uint16 *)(NFI_base+0x0020))
#define NFI_DATAR       ((volatile kal_uint32 *)(NFI_base+0x0024))
#define NFI_DATARB	   ((volatile kal_uint16 *)(NFI_base+0x0028))
#define NFI_PSTA        ((volatile kal_uint16 *)(NFI_base+0x002C))
#define NFI_FIFOCON     ((volatile kal_uint16 *)(NFI_base+0x0030))
#define NFI_CON         ((volatile kal_uint16 *)(NFI_base+0x0034))
#define NFI_INTR        ((volatile kal_uint16 *)(NFI_base+0x0038))
#define NFI_INTR_EN     ((volatile kal_uint16 *)(NFI_base+0x003C))
#define NFI_PAGECNTR	   ((volatile kal_uint16 *)(NFI_base+0x0040))
#define NFI_ADDRCNTR	   ((volatile kal_uint16 *)(NFI_base+0x0044))
#define NFI_SYM0_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0050))
#define NFI_SYM1_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0054))
#define NFI_SYM2_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0058))
#define NFI_SYM3_ADDR   ((volatile kal_uint16 *)(NFI_base+0x005C))
#define NFI_SYM0_DAT    ((volatile kal_uint32 *)(NFI_base+0x0060))
#define NFI_SYM1_DAT    ((volatile kal_uint32 *)(NFI_base+0x0064))
#define NFI_SYM2_DAT    ((volatile kal_uint32 *)(NFI_base+0x0068))
#define NFI_SYM3_DAT    ((volatile kal_uint32 *)(NFI_base+0x006C))
#define NFI_ERRDET      ((volatile kal_uint16 *)(NFI_base+0x0070))
#define NFI_PAR0        ((volatile kal_uint16 *)(NFI_base+0x0080))
#define NFI_PAR1        ((volatile kal_uint16 *)(NFI_base+0x0084))
#define NFI_PAR2        ((volatile kal_uint16 *)(NFI_base+0x0088))
#define NFI_PAR3        ((volatile kal_uint16 *)(NFI_base+0x008C))
#define NFI_PAR4        ((volatile kal_uint16 *)(NFI_base+0x0090))
#define NFI_PAR5        ((volatile kal_uint16 *)(NFI_base+0x0094))
#define NFI_PAR6        ((volatile kal_uint16 *)(NFI_base+0x0098))
#define NFI_PAR7        ((volatile kal_uint16 *)(NFI_base+0x009C))
#define NFI_CSEL	      ((volatile kal_uint16 *)(NFI_base+0x0100))


/*******************************************************************************
 * NFI register definition
 *******************************************************************************/
/* NFI_ACCCON */
#define ACCCON			      0x07C6	// C2R=111, W2R=11, WH=00, WST=00, RLT=10

/* NFI_PAGEFMT */
//#define PAGEFMT_512      0x0020
//#define PAGEFMT_2K		   0x0125
#define PAGEFMT_512        0x0000
#define PAGEFMT_2K		   0x0005
#define PAGEFMT_8BITS      0x0000
#define PAGEFMT_16BITS     0x0100


/* NFI_OPCON */
#define BURST_RD           0x0001
#define BURST_WR           0x0002
#define ECC_RD_INIT        0x0010
#define ECC_WR_INIT        0x0020
#define SINGLE_RD          0x0100
#define NOB_BYTE           0x1000
#define NOB_WORD           0x2000
#define NOB_DWORD          0x0000


/* Nand flash command */
#define RD_1ST_CMD         0x00
#define RD_2ND_HALF_CMD    0x01	// only for 512 bytes page-size
#define RD_SPARE_CMD      	0x50	// only for 512 bytes page-size
#define RD_2ND_CYCLE_CMD	0x30	// only for 2K  bytes page-size
#define INPUT_DATA_CMD     0x80
#define PROG_DATA_CMD      0x10
#define BLOCK_ERASE1_CMD   0x60
#define BLOCK_ERASE2_CMD   0xD0
#define RD_ID_CMD          0x90
#define RD_STATUS_CMD      0x70
#define RESET_CMD          0xFF



/* NFI_PSTA */
#define STATUS_CMD         0x1
#define STATUS_ADDR        0x2
#define STATUS_DATAR       0x4
#define STATUS_DATAW       0x8
#define STATUS_BUSY        0x100


/* NFI_FIFOCON */
#define RD_EMPTY_MASK      0x001
#define RD_FULL_MASK       0x002
#define WR_EMPTY_MASK      0x004
#define WR_FULL_MASK      	0x008
#define FIFO_FLUSH         0x010
#define RESET              0x020


/* NFI_CON */
#define BYTE_RW_EN		   0x8000
#define MULTIPAGE_CON	   0x0800
#define READ_CON_EN		   0x0400
#define PROGRAM_CON_EN		0x0200
#define ERASE_CON_EN		   0x0100
#define SW_PROGSPARE_EN    0x0020
#define MULTI_PAGE_RD_EN   0x0010
#define AUTOECC_ENC_EN     0x0008
#define AUTOECC_DEC_EN     0x0004
#define DMA_WR_EN          0x0002
#define DMA_RD_EN          0x0001


/* NFI_CSEL */
#define DEVICE_512		   0x00
#define DEVICE_2K		      0x01


/* Status register */
#define RDY_BUSY           0x40
#define PASS_FAIL          0x01

 
/* NFI_INTR_EN */
#define RD_COMPLETE_EN     0x01
#define WR_COMPLETE_EN     0x02
#define RESET_COMPLETE_EN  0x04
#define ERASE_COMPLETE_EN  0x08
#define ERR_DET_EN         0x10
#define ERR_COR_EN         0x20
#define BUSY_RETURN_EN     0x40
#define ALL_EN             0x7F

/* NFI_INTR */
#define RD_COMPLETE        0x0001
#define WR_COMPLETE        0x0002
#define RESET_COMPLETE     0x0004
#define ERASE_COMPLETE     0x0008
#define ERR_DET0           0x0010
#define ERR_DET1           0x0020
#define ERR_DET2           0x0040
#define ERR_DET3           0x0080
#define ERR_COR0           0x0100
#define ERR_COR1           0x0200
#define ERR_COR2           0x0400
#define ERR_COR3           0x0800
#define BUSY_RETURN        0x1000

#define NFI_Wait_Ready(timeout)   while ( (*NFI_PSTA & STATUS_BUSY) && (timeout--) )

#define REPLICATION_NUMBER  512/sizeof(BOOTL_HEADER)

/*========================================================================
 Type definition 
=========================================================================*/

#define  IO_8BITS   0x0000
#define  IO_16BITS  0x0001


/*========================================================================
 Prototypes 
=========================================================================*/

void NFI_Init(void);
void NFI_DeInit(void);
void NFI_Config(NFI_MENU *input);
void NFIReconfigure(void);
kal_bool GoodBlockChecking(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2);
_RET_CODE NFI_PageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, \
                       kal_uint16 pageSize, kal_bool ECC, kal_bool continous);
_RET_CODE NFI_ParityCheck(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, \
                          kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, \
                          kal_uint16 IO, kal_uint32 blockSize);                       

#ifdef BIT_ERROR_TEST
void EmulateBitError(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize);
#endif
                  
#endif
