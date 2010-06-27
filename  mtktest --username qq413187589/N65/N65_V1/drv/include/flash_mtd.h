/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	flash_mtd.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a flash MTD driver header file
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef FLASH_MTD_H
#define FLASH_MTD_H

#ifdef __NORFLASH_DEBUGMODE__ 
   #define DEBUG
#endif


/********************************************************/
/*                  Include Header Files                */
/********************************************************/

#include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"


/********************************************************/
/* AM29PDL128G (chip name) command address is different */
/* from others. It is MT6218B, MT6219_EVB, MT6217_EVB   */
/* default on board flash. if you want to use other     */
/* flash on MT6218B, MT6219_EVB, or MT6217_EVB, make    */
/* sure to invalidate the AM29PDL128G definition        */
/********************************************************/

#if ( defined(MT6218B_EVB) || defined(MT6219_EVB) || defined(MT6217_EVB) )
   #define AM29PDL128G
#endif

#ifndef AM29PDL128G
#define ADDR_UNLOCK_1        0x555
#define ADDR_UNLOCK_2        0x2AA
#else
#define ADDR_UNLOCK_1        0xAAA
#define ADDR_UNLOCK_2        0x555
#endif
   
/********************************************************/
/*         Parameter and Function Decleration           */
/********************************************************/
typedef kal_uint16 FLASH_CELL;
#define DriverName NORFlashMtd


/********************************************************/
/*                  Flash Command Definition            */
/********************************************************/


/*********************** AMD SERIES *********************/

#define TOGGLE_ERASE_SUSPEND 0x0004 // DQ2: toggles while the read address is erasing or erase suspending
#define TOGGLE_BUSY          0x0040 // DQ6: toggles while programming or erasing
#define POLL_BUSY            0x0080
#define POLL_TIMEOUT         0x0020
#define TOGGLE_TIMEOUT       0x0020 // DQ5: timeout, not a toggle (only valid while D6 is toggeling)
#define TOGGLE_BUFFER_ABORT  0x0002 // DQ1: buffer write abort, not a toggle (only valid while D6 is toggeling)
#define POLL_ERASE_START     0x0008 // DQ3: sector erase timer (only valid while D6 is toggeling)
#define CMD_RESET            0xF0
#define CMD_UNLOCK_1         0xAA
#define CMD_UNLOCK_2         0x55
#define CMD_UB               0x20
#define CMD_PROG             0xA0
#define CMD_WRITETOBUFFER    0x25
#define CMD_BUFFERTOFLASH    0x29
#define CMD_UB_RESET         0x90

// Sector Erase Command
#define CMD_SERASE           0x80
#define CMD_SERASE_END       0x30

// Sector Erase Suspend/Resume command 
#define CMD_SUSP_SEC_ERASE   0xB0
#define CMD_RESU_SEC_ERASE   0x30

//DYB command (Dynamic Protection Bit Command)
#define CMD_DYB_ENTER 0xE0
#define CMD_DYB_ACT 0xA0
#define CMD_DYB_SET 0x0
#define CMD_DYB_CLR 0x1
#define CMD_DYB_EXIT1 0x90
#define CMD_DYB_EXIT2 0x0

#define DYB_LOCK 0
#define DYB_UNLOCK 1

/********************** INTEL SERIES *********************/

//Read Command
#define INTEL_CMD_RD_ID 0x90     //Read Device ID or Configuration Register
#define INTEL_CMD_RD_ARRAY 0xff  //Read Array
#define INTEL_CMD_RD_SR 0x70     //Read Status Register
#define INTEL_CMD_CLR_SR 0x50;

//Erase Command
#define INTEL_CMD_ERASE_SETUP 0x20
#define INTEL_CMD_ERASE_CONFIRM 0xD0

//Program Command
#define INTEL_CMD_PGM_WORD 0x40
#define INTEL_CMD_BUF_PGM 0xE8;
#define INTEL_CMD_BUF_PGM_CNF 0xD0;

//Block Locking/Unlocking Command
#define INTEL_CMD_LOCK_SETUP 0x60
#define INTEL_CMD_LOCK 0x01
#define INTEL_CMD_UNLOCK 0xD0

//Suspend Command
#define INTEL_CMD_SUSPEND 0xB0
#define INTEL_CMD_RESUME 0xD0

//Status Register Definition
#define INTEL_READY_FLAG (0x80)
#define INTEL_ERASE_SUSPEND (0x40)
#define INTEL_PROGRAM_SUSPEND (0x04)
#define INTEL_ERASE_ERROR_FLAG (0x3A)
#define INTEL_PROGRAM_ERROR_FLAG (0x1A)

//Block Status
#define INTEL_BLOCK_LOCK_FLAG (0x03)

//Wait Function Definition
#define INTEL_WAIT_PROGRAM 0
#define INTEL_WAIT_ERASE 1
#define SIB_WAIT_BLANK_CHECK 2

/*********************** SIBLEY ***********************/


//Program Command
#define SIB_CMD_PGM_WORD 0x41
#define SIB_CMD_PGM_BUF_C1 0xE9
#define SIB_CMD_PGM_BUF_C2 0xD0

//Blank Check Command
#define SIB_CMD_BLANK_CK_C1 0xBC
#define SIB_CMD_BLANK_CK_C2 0xD0

//EFA Command
#define SIB_CMD_RD_EFA 0x94
#define SIB_CMD_PGM_EFA 0x44
#define SIB_CMD_ERASE_EFA 0x24
#define SIB_CMD_LOCKEFA_C1 0x64

//Configuration
#define SIB_CMD_PGM_CR_C1 0x60
#define SIB_CMD_PGM_RCR_C2 0x03
#define SIB_CMD_PGM_ECR_C2 0x04

//Status Register Definition
#define SIB_NOT_ALL_ERASED_FLAG (0x20)


/********************************************************/
/*               Function Prototype                     */
/********************************************************/
void * BlockAddress(void* DriverData, kal_uint32 BlockIndex);
#ifdef __SPANSION_NS_N__
kal_uint32 CalBlkAddr(void* DriverData, kal_uint32 Addr);
#endif
void * MapWindow(void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex);
extern kal_uint32 SaveAndSetIRQMask( void );
extern void RestoreIRQMask( kal_uint32 );
extern kal_uint32 INT_DisableDataCache(void);
extern void INT_RestoreDataCache(kal_uint32);
#if  ((defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)) && defined(MT6205B))
extern kal_uint32 INT_DisableCodePrefetch(void);
extern void INT_RestoreCodePrefetch(kal_uint32);
#endif


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
/* Following functions are assumed to be atomic */
void Flash_ReturnReady(void);
void Flash_ProgramData(void *target, void *src, kal_uint32 size);
void Flash_ResumeOperation(void);
void Flash_SuspendOperation(void);
kal_bool Flash_CheckReady(void);
kal_uint32 CHECK_PENDING_IRQ(kal_uint32 irq_mask, kal_uint32 address);

#if defined(DEBUG_KAL)

#define SNOR_MTD_ASSERT(expr, e1, e2, e3)\
   do{\
         if(!(expr))\
         {\
            Flash_ReturnReady();\
            kal_assert_fail(#expr, __FILE__, __LINE__, KAL_TRUE, e1, e2, e3, NULL);\
         }\
     }while(0);

#else /* DEBUG_KAL */

#define SNOR_MTD_ASSERT(expr, e1, e2, e3)\
   do{\
         if(!(expr))\
         {\
            Flash_ReturnReady();\
            kal_assert_fail();\
         }\
     }while(0);
#endif /* DEBUG_KAL */

#endif

#endif //FLASH_MTD_H
