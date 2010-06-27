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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  NandMTD.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND Flash MTD driver for Samsung and Toshiba flash devices.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"


/*******************************************************************************
 * Include Header Files
 *******************************************************************************/

    #include "init.h"
    #include "reg_base.h"
    #include "isrentry.h"
    #include "intrCtrl.h"
    #include "fat_fs.h"
    #include "NAND_FDM.h"
    #include "NAND_MTD.h"
    #include "dma_sw.h"
    #include "dma_hw.h"
    #include "drvpdn.h"
    #include "drv_comm.h"
    #include "drv_hisr.h"

#if(! ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) || (defined(MT6223)) || (defined(MT6223P))) )

/*******************************************************************************
 *  Driver declaration
 *******************************************************************************/


/* MTD driver */
NAND_MTD_DRIVER NANDFlashMtd =
{
    MTD_MountDevice,
    MTD_ShutDown,
    MTD_EraseBlock,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

/*******************************************************************************
 *   Declaration for Dual NAND
 *******************************************************************************/

NAND_MTD_SUB_DRIVER_DATA    NANDSUBDriveData[2];


NAND_MTD_SUB_DRIVER NANDFlashMtd_512_default =
{
    ProgramPage_512_default,
    ReadPage_512_default,
    ProgramSpare_512_default,
    ReadSpare_512_default
    ,NULL, NULL
};


NAND_MTD_SUB_DRIVER NANDFlashMtd_512_specific =
{
    ProgramPage_512_specific,
    ReadPage_512_specific,
    ProgramSpare_512_specific,
    ReadSpare_512_specific
    ,NULL, NULL
};

NAND_MTD_SUB_DRIVER NANDFlashMtd_Samsung_512_hw_enhanced =
{
    ProgramPage_512_default,
    ReadPage_512_default,
    ProgramSpare_512_default,
    ReadSpare_512_default
    #ifdef PAGE_COPY_SUPPORT
    ,CopyPage_512_Samsung,
    CopyPermitted_Samsung
    #else
    ,NULL, NULL
    #endif
};

NAND_MTD_SUB_DRIVER NANDFlashMtd_2K_default =
{
    ProgramPage_2K_default,
    ReadPage_2K_default,
    ProgramSpare_2K_default,
    ReadSpare_2K_default
    ,NULL, NULL
};

NAND_MTD_SUB_DRIVER NANDFlashMtd_2K_specific =
{
    ProgramPage_2K_specific,
    ReadPage_2K_specific,
    ProgramSpare_2K_specific,
    ReadSpare_2K_specific
    ,NULL, NULL
};

NAND_MTD_SUB_DRIVER NANDFlashMtd_2K_hw_enhanced =
{
    ProgramPage_2K_default,
    ReadPage_2K_default,
    ProgramSpare_2K_default,
    ReadSpare_2K_default
    #ifdef PAGE_COPY_SUPPORT
    ,CopyPage_2K_default,
    CopyPermitted_Samsung
    #else
    ,NULL, NULL
    #endif
};

NAND_MTD_SUB_DRIVER NANDFlashMtd_Toshiba_2K_hw_enhanced =
{
    ProgramPage_2K_default,
    ReadPage_2K_default,
    ProgramSpare_2K_default,
    ReadSpare_2K_default
    #ifdef PAGE_COPY_SUPPORT
    ,CopyPage_2K_default,
    CopyPermitted_default
    #else
    ,NULL, NULL
    #endif
};
/*******************************************************************************
 *  Global variable
 *******************************************************************************/
#define NFI_EVENT   0x1

/* set flash info table for
   { ID, planesize in MB, blocksize in KB, pagesize in B, address cycle, IO bus width, plane mask, mtd sub driver}  */
const flash_list NAND_ID_Table[] =
{
    /* Samsung series: manufacture ID - EC */
    /* K9F2808U0C */
   { 0x73EC,  16,  16,  512, 3,  8, 0, &NANDFlashMtd_512_default},
    /* K9F5608X0C */
   { 0x75EC,  32,  16,  512, 3,  8, NAND_PLANE_BLOCK_BIT0/*0x01*/, &NANDFlashMtd_512_default},
    /* K9K1208X0C */
   { 0x76EC,  64,  16,  512, 4,  8, NAND_PLANE_BLOCK_BIT0|NAND_PLANE_BLOCK_BIT1|NAND_PLANE_BLOCK_BIT11/*0x803*/, &NANDFlashMtd_512_default},
    /* K9K1G08X0A */
   { 0x79EC, 128,  16,  512, 4,  8, NAND_PLANE_BLOCK_BIT0|NAND_PLANE_BLOCK_BIT1|NAND_PLANE_BLOCK_BIT12/*0x1003*/, &NANDFlashMtd_512_default},
    /* K9F1G08X0M */
   { 0xF1EC, 128, 128, 2048, 4,  8, 0, &NANDFlashMtd_2K_default},
    /* K9F1G16X0M */
   { 0xC1EC, 128, 128, 2048, 4,  16, 0, &NANDFlashMtd_2K_default},
    /* K9F2G08X0M */
   { 0xDAEC, 256, 128, 2048, 5,  8, 0, &NANDFlashMtd_2K_default},
    /* K9K8G08U0M */
   { 0xD3EC, 1024, 128, 2048, 5,  8, NAND_PLANE_BLOCK_BIT0|NAND_PLANE_BLOCK_BIT12/*0x1001*/, &NANDFlashMtd_2K_default},
    /* K9K4G08U0M */
   { 0xDCEC, 512, 128, 2048, 5,  8, NAND_PLANE_BLOCK_BIT11/*0x800*/, &NANDFlashMtd_2K_default},

    /* Toshiba series: manufacture ID - 98 */
    /* TC58DVM82A1FT*/
   { 0x7598,  32,  16,  512, 3,  8, 0, &NANDFlashMtd_512_default},
    /* TC58DVM92A1FT */
   { 0x7698,  64,  16,  512, 4,  8, 0, &NANDFlashMtd_512_default},
    /* TC58DVG02A1FT */
   { 0x7998, 128,  16,  512, 4,  8, 0, &NANDFlashMtd_512_default},
    /* TC58NVG0S3AFT */
   { 0xF198, 128, 128, 2048, 4,  8, 0, &NANDFlashMtd_2K_default},
    /* TC58NVG0S8BFTI0 */
   { 0xC198, 128, 128, 2048, 5,  16, 0, &NANDFlashMtd_2K_default},
    /* TC58NVG1S8BFTI0 */
   { 0xCA98, 256, 128, 2048, 5,  16, 0, &NANDFlashMtd_2K_default},
    /* TH58NVG1S3AFT */
   { 0xDA98, 256, 128, 2048, 5,  8, 0, &NANDFlashMtd_2K_default},
    /* TH58NVG2S3BT */
   { 0xDC98, 512, 128, 2048, 5,  8, NAND_PLANE_BLOCK_BIT10|NAND_PLANE_BLOCK_BIT11/*0xC00*/, &NANDFlashMtd_2K_default},    // Dual NAND test
    /* TC58NWM9S3B */
   { 0xF098, 64, 128, 2048, 4,  8, 0, &NANDFlashMtd_2K_default},   //TR add device
   
    /* Hynix series: manufacture ID - AD */
    /* HY27XS08561M */
   { 0x75AD,  32,  16,  512, 3,  8, 0/*0x400*/, &NANDFlashMtd_512_default},
    /* HY27XS08121M */
   { 0x76AD,  64,  16,  512, 4,  8, 0/*0x801*/, &NANDFlashMtd_512_default},
    /* HY27XA081G1M */
   { 0x79AD, 128,  16,  512, 4,  8, 0/*0x1800*/, &NANDFlashMtd_512_default},
    /* HY27UF081G2M */
   { 0xF1AD, 128,  128, 2048, 4,  8, 0, &NANDFlashMtd_2K_default},
   /* CAUTION: Hynix has removed copy back support from NAND flash in MCP product */

   /* ST series: manufacture ID - 20 */
    /* ST128W3A */
   { 0x7320,  16,  16,  512, 3,  8, NAND_PLANE_BLOCK_BIT9/*0x200*/, &NANDFlashMtd_512_default},
    /* ST128W4A */
   { 0x5320,  16,  16,  512, 3, 16, NAND_PLANE_BLOCK_BIT9/*0x200*/, &NANDFlashMtd_512_default},
    /* ST256W3A */
   { 0x7520,  32,  16,  512, 3,  8, NAND_PLANE_BLOCK_BIT10/*0x400*/, &NANDFlashMtd_512_default},
    /* ST256W4A */
   { 0x5520,  32,  16,  512, 3, 16, NAND_PLANE_BLOCK_BIT10/*0x400*/, &NANDFlashMtd_512_default},
    /* ST512W3A */
   { 0x7620,  64,  16,  512, 4,  8, NAND_PLANE_BLOCK_BIT11/*0x800*/, &NANDFlashMtd_512_default},
    /* ST512W4A */
   { 0x5620,  64,  16,  512, 4, 16, NAND_PLANE_BLOCK_BIT11/*0x800*/, &NANDFlashMtd_512_default},
    /* ST01GW3A */
   { 0x7920, 128,  16,  512, 4,  8, NAND_PLANE_BLOCK_BIT11|NAND_PLANE_BLOCK_BIT12/*0x1800*/, &NANDFlashMtd_512_default},
    /* ST01GW4A */
   { 0x5920, 128,  16,  512, 4, 16, NAND_PLANE_BLOCK_BIT11|NAND_PLANE_BLOCK_BIT12/*0x1800*/, &NANDFlashMtd_512_default},
    /* ST01GW3B */
   { 0xF120, 128, 128, 2048, 4,  8, 0, &NANDFlashMtd_2K_default},

   /* Micron series: manufacture ID - 2C */
    /* MT29F2G08AAC */
   { 0xDA2C,  256,  128,  2048, 5, 8, NAND_PLANE_BLOCK_BIT12/*0x1000*/, &NANDFlashMtd_2K_default},
    /* MT29F4G08BAB */
   { 0xDC2C,  512,  128,  2048, 5, 8, NAND_PLANE_BLOCK_BIT12/*0x1000*/, &NANDFlashMtd_2K_default},

   /* Infineon series: manufacture ID - C1 */
    /* HYF33DS51280 */
   { 0x66C1,  64,    16,   512, 4, 8, 0, &NANDFlashMtd_512_default},
    /* HYF33DS1G80 */
   { 0xF1C1,  128,  128,  2048, 4, 8, 0, &NANDFlashMtd_2K_default},

   { 0xFFFF,   0,   0,    0, 0,  0, 0}   // End of ID Table

};

const kal_uint32 CUSTOMIZED_RESERVED_POOL_SIZE = 12;

static DMA_FULLSIZE_HWMENU nfi_menu;
static kal_uint8       nfi_dmaport;
static DMA_INPUT       nfi_input;
//static kal_hisrid      nfi_hisr_id;
static kal_eventgrpid  nfi_egid = NULL;
static kal_bool is_initialized;

/* for copy back support */
kal_uint32 mtd_copy_counts = 0;
static kal_uint32 mtd_buffer[MAX_PAGE_BUFFER_SIZE/sizeof(kal_uint32)];
static kal_uint32 mtd_spare[MAX_SPARE_BUFFER_SIZE/sizeof(kal_uint32)];
/* for copy back support */
/*******************************************************************************
 *  Declaration for NAND flash booting
 *******************************************************************************/

#ifdef _NAND_FLASH_BOOTING_

typedef kal_int32 (*NFBReadFunc_T)(void *, kal_uint32, kal_uint8 *, kal_uint8 *, kal_uint8);

kal_uint32 NFB_FLASH_BASE_PAGE;
NFBReadFunc_T        NFBReadFunc;
kal_int32                  NFBPageSize;
extern const kal_uint32   NFB_BASE_ADDRESS;
extern const kal_uint32 NFB_ALLOCATED_FAT_SPACE;

kal_int32 NFB_ReadPage_2K_default(void *, kal_uint32, kal_uint8 *, kal_uint8 *, kal_uint8);
kal_int32 NFB_ReadPage_512_default(void *, kal_uint32, kal_uint8 *, kal_uint8 *, kal_uint8);

/* synchronization between NAND FDM and NFB loader */
 //extern kal_uint32 SaveAndSetIRQMask(void);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
 //extern void RestoreIRQMask(kal_uint32 mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
#endif
NAND_MTD_LOCK nfi_mtd_lock = { 0, NULL, NULL};
void init_MTD_lock(void)
{
    if (nfi_mtd_lock.mtd_mutex == NULL)
    {
        nfi_mtd_lock.mtd_mutex = kal_create_mutex("MTD_NFI_LOCK");
        nfi_mtd_lock.lock_count = 0;
        nfi_mtd_lock.owner_id = NULL;
    }
}

void get_MTD_lock(void)
{
    //kal_uint32 mask = 0;/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    //mask = SaveAndSetIRQMask();/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_get_task_self_id() == nfi_mtd_lock.owner_id )
    {
        EXT_ASSERT(0 != nfi_mtd_lock.lock_count, nfi_mtd_lock.lock_count, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)nfi_mtd_lock.mtd_mutex);
        nfi_mtd_lock.lock_count++;
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    }
    else
    {
        if(nfi_mtd_lock.mtd_mutex == NULL)
        {
              init_MTD_lock();
        }
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
        kal_take_mutex(nfi_mtd_lock.mtd_mutex);
        nfi_mtd_lock.owner_id = kal_get_task_self_id();
        nfi_mtd_lock.lock_count++;
    }
}

void free_MTD_lock(void)
{
    //kal_uint32 mask = 0;/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    //mask = SaveAndSetIRQMask();/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_get_task_self_id() == nfi_mtd_lock.owner_id )
    {
        EXT_ASSERT(nfi_mtd_lock.lock_count > 0, nfi_mtd_lock.lock_count, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)nfi_mtd_lock.mtd_mutex);
        nfi_mtd_lock.lock_count--;
        if(0 == nfi_mtd_lock.lock_count)
        {
            nfi_mtd_lock.owner_id = NULL;
            //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
            if(nfi_mtd_lock.mtd_mutex != NULL)
                kal_give_mutex(nfi_mtd_lock.mtd_mutex);
        }
        //else /*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
            //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    }
    else
    {
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
        EXT_ASSERT(0, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)kal_get_task_self_id(), (kal_uint32)nfi_mtd_lock.mtd_mutex);
    }
}
/*******************************************************************************
 *  NFI bus semaphore
 *******************************************************************************/
/*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang - start*/
void get_NFI_bus(void)
{
    get_MTD_lock();
}

void free_NFI_bus(void)
{
    free_MTD_lock();
}
/*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang - End*/

// For NAND flash booting
extern kal_bool use_interrupt;  // KAL_TRUE for using interrupt; KAL_FALSE for using polling



const kal_uint32 NFI_DEBUG_VERSION = 532; // SW ver.05.30

/*******************************************************************************
 *  MTD functions
 *******************************************************************************/


kal_int32 MTD_MountDevice(void * DriveData)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 check_value = 0;

    init_MTD_lock(); /*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang*/

    if(SuperAND_MTD_MountDevice(DriveData) == FS_NO_ERROR)
    {
        SuperAND_MTD_Init();
        return SUPERAND_MOUNTED;
    }


   if(is_initialized)
   {
      get_MTD_lock(); /*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang*/
      pdn_nfi(1);

      /* In case that NFI is performing an operation */
      while (*NFI_PSTA & STATUS_BUSY);

      *NFI_FIFOCON = RESET;
      *NFI_OPCON = 0;
      *NFI_CON = 0;

      /* use 512-byte page and 8-bit IO format for read ID  */
      *NFI_PAGEFMT = PAGEFMT_512_8BIT;

      check_value = InitializeMTD(D);

      *NFI_OPCON = 0;
      pdn_nfi(0);
      free_MTD_lock(); /*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang*/
      if(check_value == MTD_STATUS_NO_ERROR)
         return FS_NO_ERROR;
      else if( check_value == MTD_STATUS_ID_NOT_SUPPORT )
         return FS_NAND_DEVICE_NOT_SUPPORTED;
      else
         return FS_FLASH_MOUNT_ERROR;
   }

    get_MTD_lock(); /*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang*/
    pdn_nfi(1);

/* set NFI conrol bin in GPIO
 * it should be consistent with GPIO_init() of custom\drv\misc_drv\XXX\gpio_drv.c
 */
#if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
    *NFI_GPIO_CON &= 0x000F;
#elif defined(MT6225)
    *NFI_GPIO_CON1 &= 0x03CF;
    *NFI_GPIO_CON1 |= 0x5420;
    *NFI_GPIO_CON2 &= 0xFFC0;
    *NFI_GPIO_CON2 |= 0x0015;
#elif defined MT6217
    *NFI_GPIO_CON &= 0xC003;
    *NFI_GPIO_CON |= 0x1554;
#else
    *NFI_GPIO_CON &= 0xC003;
    *NFI_GPIO_CON |= 0x1554;
#endif


    *NFI_ACCCON = ACCCON | (((NFI_W2R<<6)|(NFI_WH<<4)) | ((NFI_WST<<2)|NFI_RLC));

    /* initialize DMA and interrupt*/
    *PDN_CON0 &= ~0x0001;  // enable DMA
    *NFI_INTR_EN = 0x0;    // disable interrupt


    if ( stack_query_boot_mode() != USBMS_BOOT )
    {
        nfi_egid = kal_create_event_group("NFI_EG");

        //nfi_hisr_id = kal_create_hisr("NFI_HISR",1,512,nfi_hisr,NULL);
        DRV_Register_HISR(DRV_NFI_HISR_ID, nfi_hisr);

        IRQ_Register_LISR(IRQ_NFI_CODE, nfi_lisr, "NFI_LISR");
        IRQSensitivity(IRQ_NFI_CODE, EDGE_SENSITIVE);
        IRQUnmask(IRQ_NFI_CODE);
    }

    nfi_menu.TMOD.burst_mode = KAL_FALSE;
    nfi_menu.master = DMA_NFI;
    nfi_menu.source = NULL;
    nfi_menu.destination = NULL;

    nfi_input.type = DMA_HWTX;
    nfi_input.size = DMA_BYTE;
    nfi_input.menu = &nfi_menu;
    nfi_input.count = 0;

    if (nfi_egid == 0)
        nfi_input.callback = NULL;
    else
        nfi_input.callback = NFI_DMA_Callback;


    // initially set NFI chip select dir and out data
    INITIALIZE_NFI_DIR_DOUT;

    /* use 512-byte page and 8-bit IO format for read ID  */
    *NFI_PAGEFMT = PAGEFMT_512_8BIT;
   check_value = InitializeMTD(D);

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock(); /*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang*/
   is_initialized = KAL_TRUE;

    if (check_value == MTD_STATUS_NO_ERROR)
        return FS_NO_ERROR;
    else if( check_value == MTD_STATUS_ID_NOT_SUPPORT )
        return FS_NAND_DEVICE_NOT_SUPPORTED;
    else
        return FS_FLASH_MOUNT_ERROR;
}   /*  End of MountDevice */


/*******************************************************************************/
kal_int32 MTD_ShutDown(void * DriveData)
{

#ifdef _NAND_FLASH_BOOTING_

    while (IS_NFI_DMA_RUN);
    while (*NFI_PSTA & STATUS_BUSY);
    DMA_Stop(nfi_dmaport);
#endif

    return FS_NO_ERROR;
} /*  End of ShutDown */

/*******************************************************************************/

#ifdef _NAND_FLASH_BOOTING_
kal_int32 NFB_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data)
{

   extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;
   kal_uint32 spare0[16];
   kal_uint32 spare1[16];

   NAND_FLASH_DRV_DATA * D = &NANDFlashDriveData;
   kal_int32 NFBStatus=-1;
   kal_uint32 restore_nfb_flash_base_page;

   if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF )
   {
      if ( D->MTD==NULL )
      {
         NFBStatus = MTD_MountDevice((void *)D);
         EXT_ASSERT(NFBStatus==FS_NO_ERROR, NFBStatus, 0, 0);

         D->MTD = &NANDFlashMtd;

         if ( D->flash_info.page_type==PAGE_2K )
         {
            NFBReadFunc = (NFBReadFunc_T)NFB_ReadPage_2K_default;
            NFBPageSize = 2048;
         }
         else
         {
            NFBReadFunc = (NFBReadFunc_T)NFB_ReadPage_512_default;
            NFBPageSize = 512;
         }
      }
         return (D->flash_info.io_width);
   }
   /*Here mutex is used to protect Global NFB_FLASH_BASE_PAGE - Yehudi Cheng*/
   get_MTD_lock(); /*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang*/

   restore_nfb_flash_base_page = NFB_FLASH_BASE_PAGE;
   NFB_FLASH_BASE_PAGE = 0;

   /* Bad block checking */
   //D->MTD->ReadSpare(D, PhyBlock*B_PAGES, (BYTE*)D->spare0);
   //D->MTD->ReadSpare(D, PhyBlock*B_PAGES+1, (BYTE*)D->spare1);
   D->MTD->ReadSpare(D, PhyBlock*B_PAGES, (kal_uint8*)spare0);
   D->MTD->ReadSpare(D, PhyBlock*B_PAGES+1, (kal_uint8*)spare1);
   NFB_FLASH_BASE_PAGE = restore_nfb_flash_base_page;
   free_MTD_lock(); /*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang*/
   //if ( (!IsGoodBlock(D,D->spare0)) || (!IsGoodBlock(D,D->spare1)) )
    if ( (!IsGoodBlock(D,spare0)) || (!IsGoodBlock(D,spare1)) )
    {
       return -1;
    }
    else
    {
       get_MTD_lock();
       pdn_nfi(1);
       NFBStatus = NFBReadFunc(D,PhyBlock*B_PAGES+PhyPage,(kal_uint8*)Data,NULL,0);
       pdn_nfi(0);
       free_MTD_lock();

      if ( NFBStatus != FS_NO_ERROR )
         return -1;

      return NFBPageSize;
   }

   return FS_NO_ERROR;

} /*  End of NFB_ReadPhysicalPage */
#endif
/*******************************************************************************/

kal_int32 MTD_EraseBlock(void * DriveData, kal_uint32 BlockIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 addr;
    kal_uint16 block_add_num;
    kal_uint8 status, cs;
    kal_uint32 event_group;

        get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    BlockIndex += NFB_FLASH_BASE_PAGE/B_PAGES;
    /*Protect erasing range*/
    ASSERT( NFB_FLASH_BASE_PAGE*DATA_SIZE >= NFB_BASE_ADDRESS);
#endif
    if((BlockIndex<(NANDSUBDriveData[1].base_page/B_PAGES)) || (NANDSUBDriveData[1].base_page==0) )     // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    //switch (B_PAGES)
    switch(NANDSUBDriveData[cs].page_size)
    {
    //case 64:  // 2K page-size
    case 2048:
        if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
        {
            *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
        }
       else
       {
            *NFI_PAGEFMT = PAGEFMT_2K_16BIT;

            #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
                *NFI_GPIO_DATA1 &= 0x0FFF;
                *NFI_GPIO_DATA2 &= 0xF000;
            #endif
        }
        addr = (BlockIndex - (NANDSUBDriveData[cs].base_page/B_PAGES) ) << 6;
        block_add_num = (kal_uint16)(NANDSUBDriveData[cs].address_cycle - 2);
        break;
    //case 32:  // 512 page-siae
    case 512:
        if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
        {
            *NFI_PAGEFMT = PAGEFMT_512_8BIT;
        }
       else
       {
            *NFI_PAGEFMT = PAGEFMT_512_16BIT;

            #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
                *NFI_GPIO_DATA1 &= 0x0FFF;
                *NFI_GPIO_DATA2 &= 0xF000;
            #endif
        }
        addr = (BlockIndex - (NANDSUBDriveData[cs].base_page/B_PAGES) ) << 5;
        block_add_num = (kal_uint16)(NANDSUBDriveData[cs].address_cycle - 1);
        break;
    default:   // avoid unassignment warning
        addr = 0;
        block_add_num = 0;
        EXT_ASSERT(0, NANDSUBDriveData[cs].page_size, cs, NANDSUBDriveData[cs].base_page);
    }

    *NFI_CON = 0x0;
    *NFI_OPCON = 0x0;

    if (nfi_egid && use_interrupt == KAL_TRUE)
       *NFI_INTR_EN = ERASE_COMPLETE_EN;

    *NFI_CMD = BLOCK_ERASE1_CMD;        // erase command phase 1
    while (*NFI_PSTA & STATUS_CMD);


    *NFI_ADDRL = addr;                          // erase block address

    *NFI_ADDNOB = block_add_num;        // no. of block address
    while (*NFI_PSTA & STATUS_ADDR);
    *NFI_CMD = BLOCK_ERASE2_CMD;        // erase command phase 2
    while (*NFI_PSTA & STATUS_CMD);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                    &event_group, KAL_SUSPEND);
    }
    else
    {
        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }


    while (!((status = read_status())&RDY_BUSY)); // NFI ready

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();

    if (status&PASS_FAIL)
    {
        return FS_DATA_ERROR;
    }

    return FS_NO_ERROR;
} /*  End of EraseBlock */

/*******************************************************************************
 *  MTD functions for 512 page-size
 *******************************************************************************/

kal_int32 ProgramPage_512 (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif
    if((PageIndex<NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0) )        // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_512_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_512_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ProgramPage(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data, Spare, ECCFlag);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;


} /*  End of ProgramPage_512 */

/*******************************************************************************/

kal_int32 ReadPage_512 (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif
    if((PageIndex<NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0)  )       // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_512_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_512_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ReadPage(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data, Spare, SpareFlag, ECCFlag);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();
        return status;
}   /*  End of ReadPage_512 */


/*******************************************************************************/
kal_int32 ProgramSpare_512(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

        get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif

    if((PageIndex<NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0) )        // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_512_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_512_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ProgramSpare(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;


}   /*  End of ProgramSpare_512 */


/*******************************************************************************/
kal_int32 ReadSpare_512(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)   //need modification
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif
    if((PageIndex<NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0) )        // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_512_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_512_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ReadSpare(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;


} /*  End of ReadSpare_512 */

#ifdef PAGE_COPY_SUPPORT
kal_int32 CopyPage_512 (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    /* page copy back can be performed only within same plane and with same position attribute, i.e.
     * even to even or odd to odd.
     */
    get_MTD_lock();
    #ifdef _NAND_FLASH_BOOTING_
    if(( (SrcPageIndex+NFB_FLASH_BASE_PAGE) < NANDSUBDriveData[1].base_page)
        || (NANDSUBDriveData[1].base_page==0)) // chip select 0
    #else
    if((SrcPageIndex < NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0)) // chip select 0
    #endif
    {
        cs = 0;
    }
    else
    {
        cs = 1;
    }

    /* In case that one device has copy back support and the other does not under dual NAND condition */
    if( (NANDSUBDriveData[cs].sub_driver != NULL) && (NANDSUBDriveData[cs].sub_driver->CopyPermitted != NULL))
    {
    #ifdef _NAND_FLASH_BOOTING_
        if( !NANDSUBDriveData[cs].sub_driver->CopyPermitted(DriveData, SrcPageIndex+NFB_FLASH_BASE_PAGE, DestPageIndex+NFB_FLASH_BASE_PAGE) )
        {
    #else
        if( !NANDSUBDriveData[cs].sub_driver->CopyPermitted(DriveData, SrcPageIndex, DestPageIndex) )
        {
    #endif
            free_MTD_lock();
            return CopyPage_via_MCU(DriveData, SrcPageIndex, DestPageIndex);
        }
    }
    else
    {
        free_MTD_lock();
        return CopyPage_via_MCU(DriveData, SrcPageIndex, DestPageIndex);
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;

    /* TODO:
     * read src page data via NFI to ensure that data content is ECC verified. -- kirk
     */
    if(NANDSUBDriveData[cs].sub_driver->CopyPage)
    {
        if( MTD_STATUS_CORRECTED != NANDFlashMtd.ReadPage(DriveData, SrcPageIndex, (kal_uint8 *)mtd_buffer, (kal_uint8 *)mtd_spare, 1, ECC_WHOLE) )
        {
            pdn_nfi(1);
            if( 0 == cs ) // chip select 1
            {
                SET_NFI_CS0;
            }
            else // chip select 1
            {
                SET_NFI_CS1;
            }

            if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
            {
                *NFI_PAGEFMT = PAGEFMT_512_8BIT;
            }
            else
            {
                *NFI_PAGEFMT = PAGEFMT_512_16BIT;

                #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
                    *NFI_GPIO_DATA1 &= 0x0FFF;
                    *NFI_GPIO_DATA2 &= 0xF000;
                #endif
            }
            #ifdef _NAND_FLASH_BOOTING_
            status = NANDSUBDriveData[cs].sub_driver->CopyPage(D, (SrcPageIndex+NFB_FLASH_BASE_PAGE-NANDSUBDriveData[cs].base_page),
                                                               (DestPageIndex+NFB_FLASH_BASE_PAGE-NANDSUBDriveData[cs].base_page));
            #else
            status = NANDSUBDriveData[cs].sub_driver->CopyPage(D, (SrcPageIndex-NANDSUBDriveData[cs].base_page),
                                                               (DestPageIndex-NANDSUBDriveData[cs].base_page));
            #endif
            mtd_copy_counts++;

            if(cs)
                SET_NFI_CS1_END;

            *NFI_OPCON = 0;
            pdn_nfi(0);

        }
        else// data has been ECC corrected.
            status = NANDFlashMtd.ProgramPage(DriveData, DestPageIndex, (kal_uint8 *)mtd_buffer, (kal_uint8 *)mtd_spare, ECC_WHOLE);
    }
    else
        EXT_ASSERT(0, (kal_uint32)NANDFlashMtd.CopyPage, (kal_uint32)NANDSUBDriveData[cs].sub_driver->CopyPermitted, 0);//should not happen.

    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;
} /*  End of CopyPage_512 */
#endif


/*******************************************************************************
 *  MTD functions for 2k page-size
 *******************************************************************************/
kal_int32 ProgramPage_2K (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif
    if((PageIndex < NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0)  )     // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_2K_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ProgramPage(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data, Spare, ECCFlag);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;

} /*  End of ProgramPage */



/*******************************************************************************/
kal_int32 ReadPage_2K (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif
    if((PageIndex < NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0)  )     // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_2K_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ReadPage(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data, Spare, SpareFlag, ECCFlag);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();
        return status;
}   /*  End of ReadPage_2K */



/*******************************************************************************/
kal_int32 ProgramSpare_2K(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif
    if((PageIndex < NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0)  )     // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_2K_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ProgramSpare(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;

}   /*  End of ProgramSpare_2K */


/*******************************************************************************/
kal_int32 ReadSpare_2K(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)    //need modification
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    get_MTD_lock();
    pdn_nfi(1);

#ifdef _NAND_FLASH_BOOTING_
    PageIndex += NFB_FLASH_BASE_PAGE;
#endif
    if((PageIndex < NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0)  )     // chip select 0
    {
        cs = 0;
        SET_NFI_CS0;
    }
    else        // chip select 1
    {
        cs = 1;
        SET_NFI_CS1;
    }


    if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
    }
   else
   {
        *NFI_PAGEFMT = PAGEFMT_2K_16BIT;

        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    status = NANDSUBDriveData[cs].sub_driver->ReadSpare(D, (PageIndex-NANDSUBDriveData[cs].base_page), Data);

    if(cs)
        SET_NFI_CS1_END;

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;

} /*  End of ReadSpare_2K */

#ifdef PAGE_COPY_SUPPORT
/*******************************************************************************/
kal_int32 CopyPage_via_MCU(void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 status;
    status = NANDFlashMtd.ReadPage(DriveData, SrcPageIndex, (kal_uint8 *)mtd_buffer, (kal_uint8 *)mtd_spare, 1, ECC_WHOLE);
    /* TODO: handle read failure */
    //if( status != FS_NO_ERROR )//at least one bit correction is done.
    //  return FS_DATA_ERROR;
    status = NANDFlashMtd.ProgramPage(DriveData, DestPageIndex, (kal_uint8 *)mtd_buffer, (kal_uint8 *)mtd_spare, ECC_WHOLE);
    if( status != FS_NO_ERROR )
        return FS_DATA_ERROR;
} /*  End of CopyPage_via_MCU */

/*******************************************************************************/
kal_int32 CopyPermitted_default(void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    if( ((SrcPageIndex < NANDSUBDriveData[1].base_page) && (DestPageIndex >= NANDSUBDriveData[1].base_page)) ||
        ((DestPageIndex < NANDSUBDriveData[1].base_page) && (SrcPageIndex >= NANDSUBDriveData[1].base_page)) )
    {
        return 0;//in different chips
    }
    return 1;
}

kal_int32 CopyPermitted_Samsung(void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 cs = 0, plane_mask = 0;
    kal_uint32 src_blk = 0, dest_blk = 0;

    /* page copy back can be performed only within same plane and with same position attribute, i.e.
     * even to even or odd to odd.
     */

    if((SrcPageIndex & 0x01) != (DestPageIndex & 0x01))
        return 0;

    if( ((SrcPageIndex < NANDSUBDriveData[1].base_page) && (DestPageIndex >= NANDSUBDriveData[1].base_page)) ||
        ((DestPageIndex < NANDSUBDriveData[1].base_page) && (SrcPageIndex >= NANDSUBDriveData[1].base_page)) )
    {
        return 0;/* src page and dest page are in different chips*/
    }
    if((SrcPageIndex < NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0))// chip select 0
    {
        cs = 0; // chip select 0
    }
    else
    {
        cs = 1; // chip select 1
    }

    /* both pages are in the same plane? */
    src_blk = (SrcPageIndex - NANDSUBDriveData[cs].base_page)/(NANDSUBDriveData[cs].pages_per_block);
    dest_blk = (DestPageIndex - NANDSUBDriveData[cs].base_page)/(NANDSUBDriveData[cs].pages_per_block);
    plane_mask = NANDSUBDriveData[cs].plane_mask;
    if( (src_blk & plane_mask) != (dest_blk & plane_mask) )
        return 0;

    return 1;
}

kal_int32 CopyPage_2K (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 status;
    kal_uint8 cs;

    /* page copy back can be performed only within same plane and with same position attribute, i.e.
     * even to even or odd to odd.
     */

    get_MTD_lock();
    #ifdef _NAND_FLASH_BOOTING_
    if(( (SrcPageIndex+NFB_FLASH_BASE_PAGE) < NANDSUBDriveData[1].base_page)
        || (NANDSUBDriveData[1].base_page==0)) // chip select 0
    #else
    if((SrcPageIndex < NANDSUBDriveData[1].base_page) || (NANDSUBDriveData[1].base_page==0)) // chip select 0
    #endif
    {
        cs = 0;
    }
    else
    {
        cs = 1;
    }

    /* In case that one device has copy back support and the other does not under dual NAND condition */
    if( (NANDSUBDriveData[cs].sub_driver != NULL) && (NANDSUBDriveData[cs].sub_driver->CopyPermitted != NULL) )
    {
    #ifdef _NAND_FLASH_BOOTING_
        if( !NANDSUBDriveData[cs].sub_driver->CopyPermitted(DriveData, SrcPageIndex+NFB_FLASH_BASE_PAGE, DestPageIndex+NFB_FLASH_BASE_PAGE) )
        {
    #else
        if( !NANDSUBDriveData[cs].sub_driver->CopyPermitted(DriveData, SrcPageIndex, DestPageIndex) )
        {
    #endif
            free_MTD_lock();
            return CopyPage_via_MCU(DriveData, SrcPageIndex, DestPageIndex);
        }
    }
    else
    {
        free_MTD_lock();
        return CopyPage_via_MCU(DriveData, SrcPageIndex, DestPageIndex);
    }

    D->flash_info.address_cycle = NANDSUBDriveData[cs].address_cycle;
    D->flash_info.io_width = NANDSUBDriveData[cs].io_width;
    /* read src page data via NFI to ensure that data content is ECC verified. -- kirk
     */
    if(NANDSUBDriveData[cs].sub_driver->CopyPage)
    {
        if( MTD_STATUS_CORRECTED != NANDFlashMtd.ReadPage(DriveData, SrcPageIndex, (kal_uint8 *)mtd_buffer, (kal_uint8 *)mtd_spare, 1, ECC_WHOLE) )
        {
            pdn_nfi(1);
            if( 0 == cs ) // chip select 1
            {
                SET_NFI_CS0;
            }
            else // chip select 1
            {
                SET_NFI_CS1;
            }

            if (NANDSUBDriveData[cs].io_width == IO_ACCESS_8BIT)
            {
                *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
            }
            else
            {
                *NFI_PAGEFMT = PAGEFMT_2K_16BIT;

                #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
                    *NFI_GPIO_DATA1 &= 0x0FFF;
                    *NFI_GPIO_DATA2 &= 0xF000;
                #endif
            }
            #ifdef _NAND_FLASH_BOOTING_
            status = NANDSUBDriveData[cs].sub_driver->CopyPage(D, (SrcPageIndex+NFB_FLASH_BASE_PAGE-NANDSUBDriveData[cs].base_page),
                                                               (DestPageIndex+NFB_FLASH_BASE_PAGE-NANDSUBDriveData[cs].base_page));
            #else
            status = NANDSUBDriveData[cs].sub_driver->CopyPage(D, (SrcPageIndex-NANDSUBDriveData[cs].base_page),
                                                               (DestPageIndex-NANDSUBDriveData[cs].base_page));
            #endif
            mtd_copy_counts++;
            if(cs)
                SET_NFI_CS1_END;

            *NFI_OPCON = 0;
            pdn_nfi(0);

        }
        else// data has been ECC corrected.
            status = NANDFlashMtd.ProgramPage(DriveData, DestPageIndex, (kal_uint8 *)mtd_buffer, (kal_uint8 *)mtd_spare, ECC_WHOLE);
    }
    else
        EXT_ASSERT(0, (kal_uint32)NANDFlashMtd.CopyPage, (kal_uint32)NANDSUBDriveData[cs].sub_driver->CopyPermitted, 0);//should not happen.

    free_MTD_lock();

    if( status == FS_DATA_ERROR )
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;
} /*  End of CopyPage_2K */

/*******************************************************************************/
kal_int32 CopyPage_2K_default (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status = 0, nfi_pst = 0;
    kal_uint32 event_group;

    //cmd_resetpointer();
    *NFI_FIFOCON = RESET;
    *NFI_OPCON = 0;
    *NFI_CON = 0;

    //if (nfi_egid != 0 && use_interrupt == KAL_TRUE)
    //  *NFI_INTR_EN = BUSY_RETURN_EN;//WR_COMPLETE_EN;

    *NFI_CMD = RD_1ST_CMD; // Issue read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = SrcPageIndex << 16; // source address stage
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = SrcPageIndex >> 16;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_CMD = CP_READ_CMD; // Issue copy read command
    while (*NFI_PSTA & STATUS_CMD);

    while (*NFI_PSTA & STATUS_BUSY);//wait for data to be copied to data cache from data buffer
    //if (nfi_egid && use_interrupt == KAL_TRUE)
    //{
    //  kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
    //                                &event_group, KAL_SUSPEND);
    //}

    if (nfi_egid && use_interrupt == KAL_TRUE)
      *NFI_INTR_EN = BUSY_RETURN_EN;

    *NFI_CMD = CP_INPUT_CMD_2K; // Issue copy data command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = DestPageIndex << 16; // destination address stage
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = DestPageIndex >> 16;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    //if (nfi_egid && use_interrupt == KAL_TRUE)
    //  *NFI_INTR_EN = BUSY_RETURN_EN;
    *NFI_CMD = PROG_DATA_CMD;       // Issue program command
    while (*NFI_PSTA & STATUS_CMD);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                      &event_group, KAL_SUSPEND);
    }
    else
    {
        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

    //while (*NFI_PSTA & STATUS_BUSY);
    //while (!((status = read_cp_status())&RDY_BUSY));
    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
} /*  End of CopyPage_2K_default */

kal_int32 CopyPage_512_Samsung (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status = 0, nfi_pst = 0;
    kal_uint32 event_group;

    cmd_resetpointer();
    *NFI_OPCON = 0;
    *NFI_FIFOCON = RESET;
    *NFI_CON = 0;

    *NFI_CMD = RD_1ST_CMD; // Issue read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = SrcPageIndex << 8; // source address stage
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = SrcPageIndex >> 24;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    while (*NFI_PSTA & STATUS_BUSY);//wait for data to be copied to data cache from data buffer

    if (nfi_egid && use_interrupt == KAL_TRUE)
      *NFI_INTR_EN = BUSY_RETURN_EN;

    *NFI_CMD = CP_INPUT_CMD_512; // Issue copy data command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = DestPageIndex << 8; // destination address stage
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = DestPageIndex >> 24;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_CMD = PROG_DATA_CMD;       // Issue program command
    while (*NFI_PSTA & STATUS_CMD);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                      &event_group, KAL_SUSPEND);
    }
    else
    {
        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
} /*  End of CopyPage_512_Samsung */

kal_int32 CopyPage_2K_Toshiba (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    return FS_NO_ERROR;
}

kal_int32 CopyPage_2K_test (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status = 0, nfi_pst = 0;
    kal_uint32 event_group;

    *NFI_OPCON = 0;
    *NFI_FIFOCON = RESET;
    *NFI_CON = 0;

    *NFI_CMD = RD_1ST_CMD; // Issue read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = SrcPageIndex << 16; // source address stage
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = SrcPageIndex >> 16;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);
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
#else
    *NFI_CMD = CP_READ_CMD; // Issue copy read command
    while (*NFI_PSTA & STATUS_CMD);

    while (*NFI_PSTA & STATUS_BUSY);//wait for data to be copied to data cache from data buffer
#endif

    if (nfi_egid && use_interrupt == KAL_TRUE)
      *NFI_INTR_EN = BUSY_RETURN_EN;

    *NFI_CMD = CP_INPUT_CMD_2K; // Issue copy data command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = DestPageIndex << 16; // destination address stage
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = DestPageIndex >> 16;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_CMD = PROG_DATA_CMD;       // Issue program command
    while (*NFI_PSTA & STATUS_CMD);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                      &event_group, KAL_SUSPEND);
    }
    else
    {
        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

    while (!((status = read_cp_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
} /*  End of CopyPage_2K_test */
#endif //PAGE_COPY_SUPPORT

/*******************************************************************************
 *  512 page-size MTD sub functions for default device
 *******************************************************************************/

kal_int32 ProgramPage_512_default (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;

    /*Protect programming range*/
#ifdef _NAND_FLASH_BOOTING_
    ASSERT(PageIndex>=NFB_BASE_ADDRESS/512);
#endif
    cmd_resetpointer();

    if (nfi_egid != 0 && use_interrupt == KAL_TRUE)
        *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 8;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_512(Data, Spare, ECCFlag, 128);

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;

} /*  End of ProgramPage_512 */

/*******************************************************************************/

kal_int32 ReadPage_512_default (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag)
{
   NAND_FLASH_DRV_DATA * D = DriveData;
   kal_uint8 *mybuffer = (kal_uint8 *)Data;
   kal_uint16 error_detect, sym0_address;      // for ECC detection/correct
   kal_uint32 sym0_data;
   kal_uint8 * ECC_pointer = NULL;
   kal_uint32 tmp_ecc[16/sizeof(kal_uint32)];
   kal_uint32 parity_new, parity_old, exclusive_parity,i ;
   kal_uint16 ex_check_parity[2];


   /* NFI setting */
   *NFI_FIFOCON = RESET;
   *NFI_CON = AUTOECC_DEC_EN;                   // for NFI ECC decoding
   *NFI_CMD = RD_1ST_CMD;                       // read command
   while (*NFI_PSTA & STATUS_CMD);
   *NFI_ADDRL = PageIndex << 8;
   *NFI_ADDNOB = D->flash_info.address_cycle;   // number of bytes for address
   while (*NFI_PSTA & STATUS_ADDR);

   *NFI_OPCON = BURST_RD;                       // set burst read

   readfifo_512(Data, NULL, 0, 128);

   /* ECC info generated by NFI  */
   parity_new = *NFI_PAR0;
   parity_new |= (*NFI_PAR1) << 16;
   error_detect = *NFI_ERRDET & 0x01;
   sym0_address = *NFI_SYM0_ADDR;
   sym0_data = *NFI_SYM0_DAT;
   *NFI_OPCON = 0x0;

   if (SpareFlag && (Spare==NULL))
   {
      ReadSpare_512_default(DriveData, PageIndex, (Data+512));
      ECC_pointer = (kal_uint8 *)(Data+512);
   }
   else if (SpareFlag && (Spare!=NULL))
   {
      ReadSpare_512_default(DriveData, PageIndex, Spare);
      ECC_pointer = (kal_uint8 *)Spare;
   }
   /*here means caller don't want spare data, decide whether read spare data according to the ECC Flag*/
   else if (ECCFlag != ECC_SKIP)
   {
      ReadSpare_512_default(DriveData, PageIndex, (BYTE *)tmp_ecc);
      ECC_pointer = (kal_uint8 *)tmp_ecc;
   }

   if (ECCFlag == ECC_SKIP)
       return MTD_STATUS_NO_ERROR;
   /* ECC check: two-bit error detection or one-bit error correction */
   parity_old = (kal_uint32)ECC_pointer[0]
              + (((kal_uint32)ECC_pointer[1])<< 8)
              + (((kal_uint32)ECC_pointer[2])<< 16)
              + (((kal_uint32)ECC_pointer[3])<< 24);

   exclusive_parity = (parity_new^parity_old)&0x0fff0fff;

   /* ECC check: two-bit error detection or one-bit error correction */
   if(exclusive_parity!=0)
   {
      ex_check_parity[0] = exclusive_parity&0x0fff;
      ex_check_parity[1] = (exclusive_parity>>16)&0x0fff;
      if (error_detect)
      {
         kal_uint32 iIndex=0,iEccsum=0;

         for(iIndex = 0; iIndex < 12; iIndex++)
         {
             iEccsum += ((ex_check_parity[0] >> iIndex) & 0x01);
             iEccsum += ((ex_check_parity[1] >> iIndex) & 0x01);
         }
         if (iEccsum !=1)
            return MTD_STATUS_ERROR;
      }
      else
      {
         if ( ((ex_check_parity[0]^ex_check_parity[1])&0x0fff)==0x0fff )
         {
            mybuffer[sym0_address] ^= ((sym0_data >> ((sym0_address & 0x03) << 3)) & 0xFF);
            return MTD_STATUS_CORRECTED;
         }
#ifndef __PRODUCTION_RELEASE__
         else
         {
            EXT_ASSERT(0,PageIndex,parity_old,parity_new);
         }
#endif /*__PRODUCTION_RELEASE__*/
      }
   }
    return MTD_STATUS_NO_ERROR;
}   /*  End of ReadPage_512 */

/*******************************************************************************/
#ifdef _NAND_FLASH_BOOTING_
kal_int32 NFB_ReadPage_512_default (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 * ECC_pointer = NULL;
    kal_uint16 i, error_bit_address;
    kal_uint32 tmp_ecc[16/sizeof(kal_uint32)];
    static kal_uint32 parity[4], parity_old[4]; // for ECC detection/correct; use static variable for debug
    static kal_uint32 exclusive_parity[4];
    static kal_uint16 ex_check_parity[2];
   static kal_uint8  update_data;

    /* NFI setting */
    *NFI_FIFOCON = RESET;
   *NFI_CON = AUTOECC_DEC_EN;                   // for NFI ECC decoding
    *NFI_CMD = RD_1ST_CMD;                      // read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 8;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_RD;                      // set burst read

    readfifo_512(Data, NULL, 0, 128);

     /* ECC parity bits generated by NFI */
   while (!(*NFI_FIFOCON & WR_EMPTY_MASK));

   parity[0] = *NFI_PAR0;
   parity[0] |= (*NFI_PAR1) << 16;

   *NFI_OPCON = 0x0;

   /*Read spare to local buffer if SpareFlag==0;
     The spare area must be read for ECC detection/correction */
   ReadSpare_512_default(DriveData, PageIndex, (kal_uint8 *)tmp_ecc);
   ECC_pointer = tmp_ecc;

   /* ECC check: two-bit error detection or one-bit error correction */
   parity_old[0] = *(ECC_pointer+2);

   exclusive_parity[0] = (parity[0]^parity_old[0])&0x0fff0fff;

   // process ECC block
   for (i=0; i<1; i++)
   {
      if (exclusive_parity[i]==0)
       continue;

      // ECC correct
      ex_check_parity[0] = exclusive_parity[i]&0x0fff;
      ex_check_parity[1] = (exclusive_parity[i]>>16)&0x0fff;

      if ( ((ex_check_parity[0]^ex_check_parity[1])&0x0fff)==0x0fff )
      {
         // one-bit correctable error
         error_bit_address = ex_check_parity[1]&(~ex_check_parity[0]); // 16 bits
         update_data = Data[512*i+(error_bit_address>>3)];
         update_data = update_data^(1<<(kal_uint8)(error_bit_address&0x0007));
         Data[512*i+(error_bit_address>>3)] = update_data;
      }
      else
      {
         return FS_DATA_ERROR;
      }
   }

   return FS_NO_ERROR;

}   /*  End of ReadPage_512 */
#endif

/*******************************************************************************/
kal_int32 ProgramSpare_512_default (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;

    /*Protect programming range*/
#ifdef _NAND_FLASH_BOOTING_
    ASSERT(PageIndex>=NFB_BASE_ADDRESS/512);
#endif
    cmd_sparepointer();

    if (nfi_egid && use_interrupt == KAL_TRUE)
       *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 8;
    *NFI_ADDNOB = D->flash_info.address_cycle ; // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);
    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_512(Data, NULL, ECC_WHOLE, 4);    // option:write data without dma

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
}   /*  End of ProgramSpare_512 */

/*******************************************************************************/
kal_int32 ReadSpare_512_default(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)   //need modification
{
    NAND_FLASH_DRV_DATA * D = DriveData;


    *NFI_CON = SW_PROGSPARE_EN;                     // program spare area enable
    *NFI_CMD = RD_SPARE_CMD;                                // read spare command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 8;
    // set up start address, A7-A4 don't care, A3-A0 is the offset whthin the spare area
    *NFI_ADDNOB = D->flash_info.address_cycle;       // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_RD;                              // set burst read

    readfifo_512(Data, NULL, 0, 4);

    return FS_NO_ERROR;

} /*  End of ReadSpare_512 */


/*******************************************************************************
 *  2K page-size MTD sub functions for defualt device
 *******************************************************************************/

kal_int32 ProgramPage_2K_default (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;

    /*Protect programming range*/
#ifdef _NAND_FLASH_BOOTING_
    ASSERT(PageIndex>=NFB_BASE_ADDRESS/2048);
#endif
    //cmd_resetpointer(); /*Mark the un-necessary pointer operation at 2k case - 2007/05/06 - Yehudi Cheng*/

    if (nfi_egid != 0 && use_interrupt == KAL_TRUE)
        *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_FIFOCON = RESET;
    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 16;
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_2K(Data, Spare, ECCFlag, 512);     // option:write data without dma

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
} /*  End of ProgramPage */


/*******************************************************************************/
kal_int32 ReadPage_2K_default (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 * ECC_pointer = NULL;
    kal_uint16 i, error_bit_address, istart = 0, iend = 0;
   static kal_uint32 tmp_ecc[64/sizeof(kal_uint32)];
    static kal_uint32 parity[4], parity_old[4]; // for ECC detection/correct; use static variable for debug
    static kal_uint32 exclusive_parity[4];
    static kal_uint16 ex_check_parity[2];
   static kal_uint8  update_data;
    kal_uint32 status = MTD_STATUS_NO_ERROR;

    /* NFI setting */
    *NFI_FIFOCON = RESET;
    *NFI_CON = 0x0;
    *NFI_CMD = RD_1ST_CMD;                      // read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 16;
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_CMD = RD_2ND_CYCLE_CMD;
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_OPCON = BURST_RD;                      // set burst read

     readfifo_2K(Data, NULL, 0, 512);

     /* ECC parity bits generated by NFI */
     while (!(*NFI_FIFOCON & RD_EMPTY_MASK) || (*NFI_PSTA & STATUS_DATAR));
     parity[0] = *NFI_PAR0;
     parity[0] |= (*NFI_PAR1) << 16;
     parity[1] = *NFI_PAR2;
     parity[1] |= (*NFI_PAR3) << 16;
     parity[2] = *NFI_PAR4;
     parity[2] |= (*NFI_PAR5) << 16;
     parity[3] = *NFI_PAR6;
     parity[3] |= (*NFI_PAR7) << 16;

     *NFI_OPCON = 0x0;

     /* Read spare area to argument buffer if SpareFlag==1,
        while read spare to local buffer if SpareFlag==0;
        The spare area must be read for ECC detection/correction */
     if (SpareFlag && (Spare==NULL))
     {
         ReadSpare_2K_default(DriveData, PageIndex, (Data+2048));
         ECC_pointer = (kal_uint32 *)(Data+2048);
     }
     else if (SpareFlag && (Spare!=NULL))
     {
         ReadSpare_2K_default(DriveData, PageIndex, Spare);
         ECC_pointer = (kal_uint32 *)Spare;
     }
     /*here means caller don't want spare data, decide whether read spare data according to the ECC Flag*/
     else if (ECCFlag != ECC_SKIP)
     {
        ReadSpare_2K_default(DriveData, PageIndex, (kal_uint8 *)tmp_ecc);
        ECC_pointer = tmp_ecc;
     }

     if (ECCFlag == ECC_SKIP)
         return MTD_STATUS_NO_ERROR;
     /* ECC check: two-bit error detection or one-bit error correction */
     parity_old[0] = *(ECC_pointer+2);
     parity_old[1] = *(ECC_pointer+6);
     parity_old[2] = *(ECC_pointer+10);
     parity_old[3] = *(ECC_pointer+14);

     exclusive_parity[0] = (parity[0]^parity_old[0])&0x0fff0fff;
     exclusive_parity[1] = (parity[1]^parity_old[1])&0x0fff0fff;
     exclusive_parity[2] = (parity[2]^parity_old[2])&0x0fff0fff;
     exclusive_parity[3] = (parity[3]^parity_old[3])&0x0fff0fff;

     // process ECC block
     if(ECCFlag == ECC_FIRST_HALF)
     {
        istart = 0;
        iend = 2;
     }
     else if(ECCFlag == ECC_SECOND_HALF)
     {
        istart = 2;
        iend = 4;
     }
     else if(ECCFlag == ECC_WHOLE)
     {
        istart = 0;
        iend = 4;
     }
     else if(ECCFlag == ECC_SKIP)
     {
        istart = 0;
        iend = 0;
     }
     else
        EXT_ASSERT(0, ECCFlag, 0, 0);

     //for (i=0; i<4; i++)
     for (i=istart; i<iend; i++)
     {
         if (exclusive_parity[i]==0)
            continue;

         // ECC correct
         ex_check_parity[0] = exclusive_parity[i]&0x0fff;
         ex_check_parity[1] = (exclusive_parity[i]>>16)&0x0fff;

         if ( ((ex_check_parity[0]^ex_check_parity[1])&0x0fff)==0x0fff )
         {
             // one-bit correctable error
             error_bit_address = ex_check_parity[1]&(~ex_check_parity[0]); // 16 bits
             update_data = Data[512*i+(error_bit_address>>3)];
             update_data = update_data^(1<<(kal_uint8)(error_bit_address&0x0007));
             Data[512*i+(error_bit_address>>3)] = update_data;
            if (status != MTD_STATUS_ERROR)
                status = MTD_STATUS_CORRECTED;
         }
         else
         {
          kal_uint32 iIndex=0,iEccsum=0;

           for(iIndex = 0; iIndex < 12; iIndex++)
           {
               iEccsum += ((ex_check_parity[0] >> iIndex) & 0x01);
               iEccsum += ((ex_check_parity[1] >> iIndex) & 0x01);
           }
           if (iEccsum ==1)
              continue;

             status = MTD_STATUS_ERROR;
         }
     }

    return status;

}   /*  End of ReadPage_2K_default */

/*******************************************************************************/
#ifdef _NAND_FLASH_BOOTING_
kal_int32 NFB_ReadPage_2K_default (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 * ECC_pointer = NULL;
    kal_uint16 i, error_bit_address;
    kal_uint32 tmp_ecc[64/sizeof(kal_uint32)];
    static kal_uint32 parity[4], parity_old[4]; // for ECC detection/correct; use static variable for debug
    static kal_uint32 exclusive_parity[4];
    static kal_uint16 ex_check_parity[2];
   static kal_uint8  update_data;

    /* NFI setting */
    *NFI_FIFOCON = RESET;
    *NFI_CON = 0x0;
    *NFI_CMD = RD_1ST_CMD;                      // read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 16;
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_CMD = RD_2ND_CYCLE_CMD;
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_OPCON = BURST_RD;                      // set burst read

   readfifo_2K(Data, NULL, 0, 512);

   /* ECC parity bits generated by NFI */
   while (!(*NFI_FIFOCON & WR_EMPTY_MASK));

   parity[0] = *NFI_PAR0;
   parity[0] |= (*NFI_PAR1) << 16;
   parity[1] = *NFI_PAR2;
   parity[1] |= (*NFI_PAR3) << 16;
   parity[2] = *NFI_PAR4;
   parity[2] |= (*NFI_PAR5) << 16;
   parity[3] = *NFI_PAR6;
   parity[3] |= (*NFI_PAR7) << 16;


   *NFI_OPCON = 0x0;


   /*Read spare to local buffer if SpareFlag==0;
     The spare area must be read for ECC detection/correction */
   ReadSpare_2K_default(DriveData, PageIndex, (kal_uint8 *)tmp_ecc);
   ECC_pointer = tmp_ecc;

   /* ECC check: two-bit error detection or one-bit error correction */
   parity_old[0] = *(ECC_pointer+11);
   parity_old[1] = *(ECC_pointer+12);
   parity_old[2] = *(ECC_pointer+13);
   parity_old[3] = *(ECC_pointer+14);

   exclusive_parity[0] = (parity[0]^parity_old[0])&0x0fff0fff;
   exclusive_parity[1] = (parity[1]^parity_old[1])&0x0fff0fff;
   exclusive_parity[2] = (parity[2]^parity_old[2])&0x0fff0fff;
   exclusive_parity[3] = (parity[3]^parity_old[3])&0x0fff0fff;

   // process ECC block
   for (i=0; i<4; i++)
   {
      if (exclusive_parity[i]==0)
       continue;

      // ECC correct
      ex_check_parity[0] = exclusive_parity[i]&0x0fff;
      ex_check_parity[1] = (exclusive_parity[i]>>16)&0x0fff;

      if ( ((ex_check_parity[0]^ex_check_parity[1])&0x0fff)==0x0fff )
      {
         // one-bit correctable error
         error_bit_address = ex_check_parity[1]&(~ex_check_parity[0]); // 16 bits
         update_data = Data[512*i+(error_bit_address>>3)];
         update_data = update_data^(1<<(kal_uint8)(error_bit_address&0x0007));
         Data[512*i+(error_bit_address>>3)] = update_data;
      }
      else
      {
         return FS_DATA_ERROR;
      }
   }

   return FS_NO_ERROR;

}   /*  End of ReadPage_2K */
#endif
/*******************************************************************************/
kal_int32 ProgramSpare_2K_default(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;

    /*Protect programming range*/
#ifdef _NAND_FLASH_BOOTING_
    ASSERT(PageIndex>=NFB_BASE_ADDRESS/2048);
#endif
    //cmd_resetpointer(); /*Mark the un-necessary pointer operation at 2k case - 2007/05/06 - Yehudi Cheng*/

    if (nfi_egid && use_interrupt == KAL_TRUE)
       *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);

    /* there is no read spare command for 2k page-size; utilize reset and address offset */
    if (D->flash_info.io_width == IO_ACCESS_8BIT)
      *NFI_ADDRL = (PageIndex<<16)+2048;                // Byte address
    else
      *NFI_ADDRL = (PageIndex<<16)+(2048/2);            // Word address

    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;

    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_2K(Data, NULL, ECC_WHOLE, 16);    // option:write data without dma

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
}   /*  End of ProgramSpare_2K */


/*******************************************************************************/
kal_int32 ReadSpare_2K_default(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)    //need modification
{
    NAND_FLASH_DRV_DATA * D = DriveData;


    *NFI_CON = SW_PROGSPARE_EN;                 // program spare area enable
    *NFI_CMD = RD_1ST_CMD;                      // read spare command
    while (*NFI_PSTA & STATUS_CMD);

    /* there is no read spare command for 2k page-size; utilize reset and address offset */
    if (D->flash_info.io_width == IO_ACCESS_8BIT)
      *NFI_ADDRL = (PageIndex<<16)+2048;                // Byte address
    else
      *NFI_ADDRL = (PageIndex<<16)+(2048/2);            // Word address

    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;

    // set up start address, A7-A4 don't care, A3-A0 is the offset whthin the spare area
    *NFI_ADDNOB = D->flash_info.address_cycle;          // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);
    *NFI_CMD = RD_2ND_CYCLE_CMD;
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_OPCON = BURST_RD;                      // set burst read

    readfifo_2K(Data, NULL, 0, 16);

    return FS_NO_ERROR;

} /*  End of ReadSpare_2K */


/*******************************************************************************
 *  512 page-size MTD sub functions for specific device
 *******************************************************************************/
kal_int32 ProgramPage_512_specific (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;


    cmd_resetpointer();

    if (nfi_egid != 0 && use_interrupt == KAL_TRUE)
        *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 8;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_512(Data, Spare, ECCFlag, 128);

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;

} /*  End of ProgramPage_512 */



/*******************************************************************************/

kal_int32 ReadPage_512_specific (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 *mybuffer = Data;
    kal_uint16 error_detect, sym0_address;      // for ECC detection/correct
    kal_uint32 sym0_data;


    /* NFI setting */
    *NFI_FIFOCON = RESET;
    *NFI_CON = AUTOECC_DEC_EN;                  // for NFI ECC decoding
    *NFI_CMD = RD_1ST_CMD;                      // read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 8;
    *NFI_ADDNOB = D->flash_info.address_cycle;  // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_RD;                      // set burst read

     readfifo_512(Data, NULL, 0, 128);

     /* ECC info generated by NFI  */
     error_detect = *NFI_ERRDET & 0x01;
     sym0_address = *NFI_SYM0_ADDR;
     sym0_data = *NFI_SYM0_DAT;
     *NFI_OPCON = 0x0;

     /* read spare if SpareFlag==1 */
     if (SpareFlag && (Spare==NULL))
         ReadSpare_512_specific(DriveData, PageIndex, (Data+512));
     else if (SpareFlag && (Spare!=NULL))
         ReadSpare_512_specific(DriveData, PageIndex, Spare);

    /* ECC check: two-bit error detection or one-bit error correction */
     if (error_detect)
     {
         return MTD_STATUS_ERROR;
     }

     if (sym0_address != 0)
     {
         mybuffer[sym0_address] ^= ((sym0_data >> ((sym0_address & 0x03) << 3)) & 0xFF);
         return MTD_STATUS_CORRECTED;
     }

    return MTD_STATUS_NO_ERROR;

    return FS_NO_ERROR;

}   /*  End of ReadPage_512 */


/*******************************************************************************/
kal_int32 ProgramSpare_512_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;

    cmd_sparepointer();

    if (nfi_egid && use_interrupt == KAL_TRUE)
       *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 8;
    *NFI_ADDNOB = D->flash_info.address_cycle ; // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_512(Data, NULL, ECC_WHOLE, 4);    // option:write data without dma

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
}   /*  End of ProgramSpare_512 */


/*******************************************************************************/
kal_int32 ReadSpare_512_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)  //need modification
{
    NAND_FLASH_DRV_DATA * D = DriveData;


    *NFI_CON = SW_PROGSPARE_EN;                     // program spare area enable
    *NFI_CMD = RD_SPARE_CMD;                                // read spare command
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_ADDRL = PageIndex << 8;

    // set up start address, A7-A4 don't care, A3-A0 is the offset whthin the spare area
    *NFI_ADDNOB = D->flash_info.address_cycle;       // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_RD;                              // set burst read

    readfifo_512(Data, NULL, 0, 4);

    return FS_NO_ERROR;

} /*  End of ReadSpare_512 */



/*******************************************************************************
 *  2K page-size MTD sub functions for specific device
 *******************************************************************************/
kal_int32 ProgramPage_2K_specific (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;


    cmd_resetpointer();

    if (nfi_egid != 0 && use_interrupt == KAL_TRUE)
        *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 16;
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;

    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_2K(Data, Spare, ECCFlag, 512);     // option:write data without dma

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
} /*  End of ProgramPage */

/*******************************************************************************/
kal_int32 ReadPage_2K_specific (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 * ECC_pointer = NULL;
    kal_uint16 i, error_bit_address;
    static kal_uint32 parity[4], parity_old[4]; // for ECC detection/correct; use static variable for debug
    static kal_uint32 exclusive_parity[4];
    static kal_uint16 ex_check_parity[2];
   static kal_uint8  update_data;
    static char text[100];


    /* NFI setting */
    *NFI_FIFOCON = RESET;
    *NFI_CON = 0x0;
    *NFI_CMD = RD_1ST_CMD;                      // read command
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = PageIndex << 16;
    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;

    *NFI_ADDNOB = D->flash_info.address_cycle;  // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_CMD = RD_2ND_CYCLE_CMD;
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_OPCON = BURST_RD;                      // set burst read

     readfifo_2K(Data, NULL, 0, 512);

     /* ECC parity bits generated by NFI */
     while (!(*NFI_FIFOCON & RD_EMPTY_MASK) || (*NFI_PSTA & STATUS_DATAR));
     parity[0] = *NFI_PAR0;
     parity[0] |= (*NFI_PAR1) << 16;
     parity[1] = *NFI_PAR2;
     parity[1] |= (*NFI_PAR3) << 16;
     parity[2] = *NFI_PAR4;
     parity[2] |= (*NFI_PAR5) << 16;
     parity[3] = *NFI_PAR6;
     parity[3] |= (*NFI_PAR7) << 16;


     *NFI_OPCON = 0x0;


     /* Read spare area to argument buffer if SpareFlag==1,
        while read spare to local buffer if SpareFlag==0;
        The spare area must be read for ECC detection/correction */
     if (SpareFlag && (Spare==NULL))
     {
         ReadSpare_2K(DriveData, PageIndex, (Data+2048));
         ECC_pointer = (kal_uint32 *)(Data+2048);
     }
     else if (SpareFlag && (Spare!=NULL))
     {
         ReadSpare_2K_specific(DriveData, PageIndex, Spare);
         ECC_pointer = (kal_uint32 *)Spare;
     }
     else
     {
        kal_uint32 tmp_ecc[64/sizeof(kal_uint32)];

        ReadSpare_2K_specific(DriveData, PageIndex, (kal_uint8 *)tmp_ecc);
        ECC_pointer = tmp_ecc;
     }

     /* ECC check: two-bit error detection or one-bit error correction */
     parity_old[0] = *(ECC_pointer+2);
     parity_old[1] = *(ECC_pointer+6);
     parity_old[2] = *(ECC_pointer+10);
     parity_old[3] = *(ECC_pointer+14);



     exclusive_parity[0] = (parity[0]^parity_old[0])&0x0fff0fff;
     exclusive_parity[1] = (parity[1]^parity_old[1])&0x0fff0fff;
     exclusive_parity[2] = (parity[2]^parity_old[2])&0x0fff0fff;
     exclusive_parity[3] = (parity[3]^parity_old[3])&0x0fff0fff;

     // process ECC block
     for (i=0; i<4; i++)
     {
         if (exclusive_parity[i]==0)
            continue;

         // ECC correct
         ex_check_parity[0] = exclusive_parity[i]&0x0fff;
         ex_check_parity[1] = (exclusive_parity[i]>>16)&0x0fff;

         if ( ((ex_check_parity[0]^ex_check_parity[1])&0x0fff)==0x0fff )
         {
             // one-bit correctable error
             error_bit_address = ex_check_parity[1]&(~ex_check_parity[0]); // 16 bits
             update_data = Data[512*i+(error_bit_address>>3)];
             update_data = update_data^(1<<(kal_uint8)(error_bit_address&0x0007));
             Data[512*i+(error_bit_address>>3)] = update_data;

         }
         else
         {
             return FS_DATA_ERROR;
         }
     }

     return FS_NO_ERROR;

}   /*  End of ReadPage_2K */


/*******************************************************************************/
kal_int32 ProgramSpare_2K_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint8 status;


    cmd_resetpointer();

    if (nfi_egid && use_interrupt == KAL_TRUE)
       *NFI_INTR_EN = WR_COMPLETE_EN;

    *NFI_CON = SW_PROGSPARE_EN;
    *NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
    while (*NFI_PSTA & STATUS_CMD);
    /* there is no read spare command for 2k page-size; utilize reset and address offset */
    if (D->flash_info.io_width == IO_ACCESS_8BIT)
      *NFI_ADDRL = (PageIndex<<16)+2048;                // Byte address
    else
      *NFI_ADDRL = (PageIndex<<16)+(2048/2);            // Word address

    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;



    *NFI_ADDNOB = D->flash_info.address_cycle;  // no. of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_OPCON = BURST_WR;                      // set burst write

    writefifo_2K(Data, NULL, ECC_WHOLE, 16);    // option:write data without dma

    while (!((status = read_status())&RDY_BUSY));
    *NFI_OPCON = 0;

    if (status&PASS_FAIL)
        return FS_DATA_ERROR;

    return FS_NO_ERROR;
}   /*  End of ProgramSpare_2K */


/*******************************************************************************/
kal_int32 ReadSpare_2K_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data)   //need modification
{
    NAND_FLASH_DRV_DATA * D = DriveData;


    *NFI_CON = SW_PROGSPARE_EN;                 // program spare area enable
    *NFI_CMD = RD_1ST_CMD;                      // read spare command
    while (*NFI_PSTA & STATUS_CMD);

    /* there is no read spare command for 2k page-size; utilize reset and address offset */
    if (D->flash_info.io_width == IO_ACCESS_8BIT)
      *NFI_ADDRL = (PageIndex<<16)+2048;                // Byte address
    else
      *NFI_ADDRL = (PageIndex<<16)+(2048/2);            // Word address

    if (D->flash_info.address_cycle == 5)
        *NFI_ADDRM = PageIndex >> 16;


    // set up start address, A7-A4 don't care, A3-A0 is the offset whthin the spare area
    *NFI_ADDNOB = D->flash_info.address_cycle;          // number of bytes for address
    while (*NFI_PSTA & STATUS_ADDR);

    *NFI_CMD = RD_2ND_CYCLE_CMD;
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_OPCON = BURST_RD;                      // set burst read

    readfifo_2K(Data, NULL, 0, 16);

    return FS_NO_ERROR;

} /*  End of ReadSpare_2K */



/*******************************************************************************
 *  Sub-functions
 *******************************************************************************/

void writefifo_512(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length)
{
    kal_uint32 i;
    kal_uint32 parity;
    kal_uint32 event_group;

    #if defined(MT6225)
    ECO_VERSION eco_6225;

    eco_6225 = INT_ecoVersion();
    #endif

    /* set DMA */
    *NFI_CON |= DMA_WR_EN;

    if (nfi_dmaport == 0)
        nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

    if((kal_uint32)data & 0x03)
    {
    nfi_menu.destination  = (kal_uint32)NFI_DATAWB;
        nfi_input.size = DMA_BYTE;
        nfi_input.count = length * 4;
    }
    else
    {
        nfi_menu.destination  = (kal_uint32)NFI_DATAW;
        nfi_input.size = DMA_LONG;
        nfi_input.count = length;
    }

    nfi_menu.source = (kal_uint32)data;
    nfi_input.type = DMA_HWTX;
    #if defined(MT6225)
    if(eco_6225 <= ECO_E3)
        nfi_menu.TMOD.burst_mode = KAL_FALSE;
    else
        nfi_menu.TMOD.burst_mode = KAL_TRUE;
    #else
    nfi_menu.TMOD.burst_mode = KAL_TRUE;
    #endif

    if (nfi_egid && use_interrupt == KAL_TRUE)
        {
      nfi_input.callback = NFI_DMA_Callback;
        }
    else
      nfi_input.callback = NULL;


    DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

    if (nfi_egid && use_interrupt == KAL_TRUE)
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                    &event_group, KAL_SUSPEND);
    else
    {
        while (IS_NFI_DMA_RUN);
    }

    /* wait until all data is transfered to NAND device */
    #if ( (defined(MT6218B)) || (defined(MT6219)) )
    while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
    #else
    while(*NFI_ADDRCNTR < (length*4));
    #endif

    /* program ECC of spare area    */
    if (length > 4 && ECC_flag)
    {
        kal_uint8 *p1 = NULL, *p2;
        kal_uint32 temp = 0;
        kal_uint32 *tmp_ptr = NULL;
        p2 = (kal_uint8*)&temp;
        /* For one ECC block case, NFI would calculate ECC parity value in parity register 6 and 7 first,
         * and then copy them to parity register 0 and 1 after program command is issued.
         * Since we do not send program command yet, the generated ECC value is still stored in parity
         * register 6 and 7
         */
        parity = *NFI_PAR6;
        parity |= *NFI_PAR7 << 16;
        *NFI_DATAW = parity;

        if(spare == NULL)
        {
            if( ((kal_uint32)data & 0x03) == 0 )/* not 4-bytes aligned */
                tmp_ptr = (kal_uint32 *)(data+516);
            else
                p1 = data+516;
        }
        else
        {
            if( ((kal_uint32)spare & 0x03) == 0 )
                tmp_ptr = (kal_uint32 *)(spare+4);
            else
                p1 = (spare+4);
        }
        if(tmp_ptr)
        {
            for (i=0 ; i<3 ; i++)
            {
                while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
                    *NFI_DATAW = tmp_ptr[i];
            }
        }
        else
        {
            for (i=0 ; i<3 ; i++)
            {
                p2[0] = p1[i<<2];
                p2[1] = p1[1+(i<<2)];
                p2[2] = p1[2+(i<<2)];
                p2[3] = p1[3+(i<<2)];
                while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
                *NFI_DATAW = temp;
            }
        }
        while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
    }

    DMA_FullSize_FreeChannel(nfi_dmaport);
    nfi_dmaport = 0;

    while (*NFI_PSTA & STATUS_DATAW);

    *NFI_OPCON = 0x0;

    *NFI_CMD = PROG_DATA_CMD;       // Issue program command
    while (*NFI_PSTA & STATUS_CMD);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                &event_group, KAL_SUSPEND);
    }
    else
    {
        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }


} /*  End of writefifo_512 */



/*******************************************************************************/
void writefifo_2K(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length)
{
    kal_uint32 i;
    kal_uint32 parity[4];
    kal_uint32 event_group;

    #if defined(MT6225)
    ECO_VERSION eco_6225;

    eco_6225 = INT_ecoVersion();
    #endif

    /* set DMA */
    *NFI_CON |= DMA_WR_EN;

    if (nfi_dmaport == 0)
        nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

    if( (kal_uint32)data & 0x03 )
    {
        nfi_menu.destination  = (kal_uint32)NFI_DATAWB;
        nfi_input.size = DMA_BYTE;
        nfi_input.count = length*4 ;
    }
    else
    {
        nfi_menu.destination  = (kal_uint32)NFI_DATAW;
        nfi_input.size = DMA_LONG;
        nfi_input.count = length;
    }

    //nfi_menu.destination  = (kal_uint32)NFI_DATAWB;
    nfi_menu.source = (kal_uint32)data;
    nfi_input.type = DMA_HWTX;
    #if defined(MT6225)
    if(eco_6225 <= ECO_E3)
        nfi_menu.TMOD.burst_mode = KAL_FALSE;
    else
        nfi_menu.TMOD.burst_mode = KAL_TRUE;
    #else
    nfi_menu.TMOD.burst_mode = KAL_TRUE;
    #endif

    if (nfi_egid && use_interrupt == KAL_TRUE)
        {
        nfi_input.callback = NFI_DMA_Callback;
        }
    else
        nfi_input.callback = NULL;

    DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

    if (nfi_egid && use_interrupt == KAL_TRUE)
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                      &event_group, KAL_SUSPEND);
    else
    {
        while (IS_NFI_DMA_RUN);
    }

    /* wait until all data is transfered to NAND device */
    #if ( (defined(MT6218B)) || (defined(MT6219)) )
    while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
    #else
    while(*NFI_ADDRCNTR < (length*4));
    #endif

    /* program ECC of spare area : first half, second half, or whole */
    if (length > 16 && ECC_flag)
    {
        kal_uint8 *p1 = NULL, *p2;
        kal_uint32 temp = 0;
        kal_uint32 *tmp_ptr = NULL;
        p2 = (kal_uint8*)&temp;

        parity[0] = *NFI_PAR0;
        parity[0] |= (*NFI_PAR1) << 16;
        parity[1] = (*NFI_PAR2);
        parity[1] |= (*NFI_PAR3) << 16;
        parity[2] = (*NFI_PAR4);
        parity[2] |= (*NFI_PAR5) << 16;
        parity[3] = (*NFI_PAR6);
        parity[3] |= (*NFI_PAR7) << 16;

        /* buffer alignment check */
        if(spare == NULL)
        {
            if( ((kal_uint32)data & 0x03) == 0 )/* not 4-bytes aligned */
                tmp_ptr = (kal_uint32*)(data+2048);
            else
                p1 = data+2048;
        }
        else
        {
            if( ((kal_uint32)spare & 0x03) == 0 )
                tmp_ptr = (kal_uint32 *)spare;
            else
                p1 = spare;
        }

        for (i=512; i<528;i++)
        {
            while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
            if ((i&0x03)!= 2)
            {
                if(tmp_ptr)
                {
                    *NFI_DATAW = tmp_ptr[i-512];
                }
                else
                {
                    p2[0] = p1[((i-512)<<2)];
                    p2[1] = p1[1+((i-512)<<2)];
                    p2[2] = p1[2+((i-512)<<2)];
                    p2[3] = p1[3+((i-512)<<2)];
                    *NFI_DATAW = temp;
                }
            }
            else
            {
                switch ((i-512) >> 2 )
                {
                case 0:
                    *NFI_DATAW = (ECC_flag==ECC_FIRST_HALF || ECC_flag==ECC_WHOLE) ?
                                        parity [0] : 0xffffffff ;
                    break;
                case 1:
                    *NFI_DATAW = (ECC_flag==ECC_FIRST_HALF || ECC_flag==ECC_WHOLE) ?
                                        parity [1] : 0xffffffff ;
                    break;
                case 2:
                    *NFI_DATAW = (ECC_flag==ECC_SECOND_HALF || ECC_flag==ECC_WHOLE) ?
                                        parity [2] : 0xffffffff ;
                    break;
                case 3:
                    *NFI_DATAW = (ECC_flag==ECC_SECOND_HALF || ECC_flag==ECC_WHOLE) ?
                                        parity [3] : 0xffffffff ;
                    break;
                }
            }
        }
        while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
    }

    DMA_FullSize_FreeChannel(nfi_dmaport);
    nfi_dmaport = 0;

    while (*NFI_PSTA & STATUS_DATAW);
    *NFI_OPCON = 0x0;

    *NFI_CMD = PROG_DATA_CMD;       // Issue program command
    while (*NFI_PSTA & STATUS_CMD);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                      &event_group, KAL_SUSPEND);
    }
    else
    {
        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

} /*  End of writefifo_2K */

/*******************************************************************************/
void readfifo_512(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length)
{
    kal_uint32 i;
    kal_uint32 event_group;

    if ( ((kal_uint32)data & 0x03) != 0 || length == 4)
    {
        kal_uint8 *p, *p1;
        kal_uint32 temp;
        kal_uint32* data_ptr = NULL;

        p1 = (kal_uint8*)&temp;
        if ( ((kal_uint32)data & 0x03) != 0)     // data isn't aligned
        {
            #if (defined(MT6218B) || defined(MT6219))
            /* Not 4bytes-alignment buffer */
            /* Because MT6218B and MT6219 don't have byte reading register */
            for (i=0; i<length; i++)
            {
                p = (kal_uint8*)(data+(i<<2));
                while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                temp = *NFI_DATAR;
                p[0] = p1[0];
                p[1] = p1[1];
                p[2] = p1[2];
                p[3] = p1[3];
            }
            #else
            *NFI_CON |= DMA_RD_EN | BYTE_RW_EN;

            if (nfi_dmaport == 0)
                nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

            nfi_menu.source  = (kal_uint32)NFI_DATARB;
            nfi_menu.destination = (kal_uint32)data;
            nfi_input.type = DMA_HWRX;
            nfi_menu.TMOD.burst_mode = KAL_FALSE;
            nfi_input.size = DMA_BYTE;
            nfi_input.count = length*4;

            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                nfi_input.callback = NFI_DMA_Callback;
            }
            else
                nfi_input.callback = NULL;

            DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                        &event_group, KAL_SUSPEND);
            }
            else
            {
                while (IS_NFI_DMA_RUN);     // USB mode, polling register

                // using interrupt instead of polling after system initialization and before exception in normal mode
                if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
                    use_interrupt = KAL_TRUE;
            }
            DMA_FullSize_FreeChannel(nfi_dmaport);/*Release DMA Channel - 2007/05/07 - Yehudi*/
            nfi_dmaport = 0;
            #endif

            if (ECC_flag)/* read spare area */
            {
                if( spare == NULL )
                {
                    p = (kal_uint8*)(data+512);
                }
                else if( ((kal_uint32)spare & 0x03) != 0 )
                {
                    p = (kal_uint8*)spare;
                }
                else
                {
                    data_ptr = (kal_uint32 *)spare;
                    p = NULL;
                }
                for (i=0; i<4; i++)
                {
                    // check fifo status and read next
                    while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                    if (data_ptr == NULL)
                    {
                        temp = *NFI_DATAR;
                        p[0 + (i<<2)] = p1[0];
                        p[1 + (i<<2)] = p1[1];
                        p[2 + (i<<2)] = p1[2];
                        p[3 + (i<<2)] = p1[3];
                    }
                    else
                    {
                        data_ptr[i] = *NFI_DATAR;
                    }
                }
            }
        }
        else  /* read spare (length == 4) */
        {
            data_ptr = (kal_uint32 *)data;
            for (i=0; i<4; i++)
            {
                while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                data_ptr[i] = *NFI_DATAR;
            }
        }
    }
    else  // dma_mode for aligned page read
    {
        *NFI_CON |= DMA_RD_EN;

        if (nfi_dmaport == 0)
            nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

        nfi_menu.source  = (kal_uint32)NFI_DATAR;
        nfi_menu.destination = (kal_uint32)data;
        nfi_input.type = DMA_HWRX;
        nfi_menu.TMOD.burst_mode = KAL_FALSE;
        nfi_input.size = DMA_LONG;
        nfi_input.count = length;

        if (nfi_egid && use_interrupt == KAL_TRUE)
                {
            nfi_input.callback = NFI_DMA_Callback;
                }
        else
            nfi_input.callback = NULL;

        DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

        if (nfi_egid && use_interrupt == KAL_TRUE)
        {
            kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                    &event_group, KAL_SUSPEND);
        }
        else
        {
            while (IS_NFI_DMA_RUN);

        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;

        }

       // read spare area
        if (ECC_flag)
        {
            kal_uint8 *p = NULL, *p1;
            kal_uint32 temp;
            kal_uint32 *tmp_ptr = NULL;

            p1 = (kal_uint8*)&temp;
            if(spare == NULL)
            {
                tmp_ptr = (kal_uint32 *)(data + 512);
            }
            else if( ((kal_uint32)spare & 0x03) == 0)
            {
                tmp_ptr = (kal_uint32 *)spare;
            }
            else
            {
                p = (kal_uint8*)spare;
            }

            for (i=0; i<4; i++)
            {
            // check fifo status and read next
                while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                if (tmp_ptr == NULL)
                {
                    temp = *NFI_DATAR;
                    p[0 + (i<<2)] = p1[0];
                    p[1 + (i<<2)] = p1[1];
                    p[2 + (i<<2)] = p1[2];
                    p[3 + (i<<2)] = p1[3];
                }
                else
                {
                    tmp_ptr[i] = *NFI_DATAR;
                }
            }
        }

        DMA_FullSize_FreeChannel(nfi_dmaport);
        nfi_dmaport = 0;
    }

    while (*NFI_PSTA & STATUS_DATAR);
    *NFI_OPCON = 0x0;
    while (!(read_status()&RDY_BUSY));

} /*  End of readfifo_512 */


/*******************************************************************************/
void readfifo_2K(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length)
{
    kal_uint32 i;
    kal_uint32 event_group;


    if ( ((kal_uint32)data & 0x03) != 0 || length == 16)
    {
        kal_uint8 *p = NULL, *p1;
            kal_uint32 temp;
        kal_uint32 *data_ptr = NULL;

            p1 = (kal_uint8*)&temp;
        if ( ((kal_uint32)data & 0x03) != 0)     // data isn't aligned
        {
            #if (defined(MT6218B) || defined(MT6219))
            /* Not 4bytes-alignment buffer */
            /* Because MT6218B and MT6219 don't have byte reading register */
            for (i=0; i<length; i++)
            {
                p = (kal_uint8*)(data+ (i<<2));
                while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                temp = *NFI_DATAR;
                p[0] = p1[0];
                p[1] = p1[1];
                p[2] = p1[2];
                p[3] = p1[3];
            }
            #else
            *NFI_CON |= DMA_RD_EN | BYTE_RW_EN;

            if (nfi_dmaport == 0)
                nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

            nfi_menu.source  = (kal_uint32)NFI_DATARB;
            nfi_menu.destination = (kal_uint32)data;
            nfi_input.type = DMA_HWRX;
            nfi_menu.TMOD.burst_mode = KAL_FALSE;
            nfi_input.size = DMA_BYTE;
            nfi_input.count = length*4;

            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                nfi_input.callback = NFI_DMA_Callback;
            }
            else
                nfi_input.callback = NULL;

            DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                        &event_group, KAL_SUSPEND);
            }
            else
            {
                while (IS_NFI_DMA_RUN);     // USB mode, polling register

                // using interrupt instead of polling after system initialization and before exception in normal mode
                if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
                    use_interrupt = KAL_TRUE;
            }
            DMA_FullSize_FreeChannel(nfi_dmaport);/*Release DMA Channel - 2007/05/07 - Yehudi*/
            nfi_dmaport = 0;
            #endif

            if (ECC_flag)/* read spare area */
            {
                if( spare == NULL )
                {
                    p = (kal_uint8*)(data+2048);
                }
                else if( ((kal_uint32)spare & 0x03) != 0 )
                {
                    p = (kal_uint8*)spare;
                }
                else
                {
                    data_ptr = (kal_uint32 *)spare;
                    p = NULL;
                }
                for (i=0; i<16; i++)
                {
                    // check fifo status and read next
                    while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                    if (data_ptr == NULL)
                    {
                        temp = *NFI_DATAR;
                        p[0 + (i<<2)] = p1[0];
                        p[1 + (i<<2)] = p1[1];
                        p[2 + (i<<2)] = p1[2];
                        p[3 + (i<<2)] = p1[3];
                    }
                    else
                    {
                        data_ptr[i] = *NFI_DATAR;
                    }
                }
            }

        }
        else  /* read spare (length == 16) */
        {
            data_ptr = (kal_uint32 *)data;
            for (i=0; i<16; i++)
            {
                while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                data_ptr[i] = *NFI_DATAR;
            }
        }
    }
    else  // dma_mode for aligned page read
    {
        *NFI_CON |= DMA_RD_EN;

        if (nfi_dmaport == 0)
            nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

        nfi_menu.source  = (kal_uint32)NFI_DATAR;
        nfi_menu.destination = (kal_uint32)data;
        nfi_input.type = DMA_HWRX;
        nfi_menu.TMOD.burst_mode = KAL_FALSE;
        nfi_input.size = DMA_LONG;
        nfi_input.count = length;

        if (nfi_egid && use_interrupt == KAL_TRUE)
                {
            nfi_input.callback = NFI_DMA_Callback;
                }
        else
            nfi_input.callback = NULL;

        DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

        if (nfi_egid && use_interrupt == KAL_TRUE)
        {
            kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                    &event_group, KAL_SUSPEND);
        }
        else
        {
            while (IS_NFI_DMA_RUN);     // USB mode, polling register

        // using interrupt instead of polling after system initialization and before exception in normal mode
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
        }

       // read spare area
        if (ECC_flag)
        {
            kal_uint8 *p = NULL, *p1;
            kal_uint32 temp;
            kal_uint32 *tmp_ptr = NULL;

            p1 = (kal_uint8*)&temp;
            if(spare == NULL)
            {
                tmp_ptr = (kal_uint32 *)(data + 2048);
            }
            else if( ((kal_uint32)spare & 0x03) == 0)
            {
                tmp_ptr = (kal_uint32 *)spare;
            }
            else
            {
                p = (kal_uint8*)spare;
            }

            for (i=0; i<16; i++)
            {
            // check fifo status and read next
                while ((*NFI_FIFOCON & RD_EMPTY_MASK));
                if (tmp_ptr == NULL)
                {
                    temp = *NFI_DATAR;
                    p[0 + (i<<2)] = p1[0];
                    p[1 + (i<<2)] = p1[1];
                    p[2 + (i<<2)] = p1[2];
                    p[3 + (i<<2)] = p1[3];
                }
                else
                {
                    tmp_ptr[i] = *NFI_DATAR;
                }
            }
        }

        DMA_FullSize_FreeChannel(nfi_dmaport);
        nfi_dmaport = 0;
    }

    while (*NFI_PSTA & STATUS_DATAR);
    *NFI_OPCON = 0x0;

} /*  End of readfifo_2K */

/*******************************************************************************/
void cmd_resetpointer(void) // Issue pointer reset command
{
    *NFI_CMD = RD_1ST_CMD;              // read command
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_OPCON = 0;

    while (*NFI_PSTA & STATUS_CMD);

    *NFI_FIFOCON = RESET;
} /*  End of cmd_resetpointer */

/*******************************************************************************/
void cmd_sparepointer(void) // Issue pointer points to spare command
{
    *NFI_CMD = RD_SPARE_CMD;                // read command
    while (*NFI_PSTA & STATUS_CMD);

    *NFI_OPCON = 0;

    while (*NFI_PSTA & STATUS_CMD);

    *NFI_FIFOCON = RESET;
} /*  End of cmd_sparepointer */


/*******************************************************************************/
kal_uint8 read_status(void)
{
    kal_uint8 cmd_status;

    *NFI_CMD = RD_STATUS_CMD;
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_OPCON = (NOB_BYTE | SINGLE_RD);
    while (*NFI_PSTA & STATUS_DATAR);
    cmd_status = (kal_uint8)(*NFI_DATAR);

    return cmd_status;
} /*  End of read_status */

/*******************************************************************************/
kal_uint8 read_cp_status(void)/* CAUTION: only supported by certain samsung devices */
{
    kal_uint8 cmd_status;

    *NFI_CMD = 0x7B;
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_OPCON = (NOB_BYTE | SINGLE_RD);
    while (*NFI_PSTA & STATUS_DATAR);
    cmd_status = (kal_uint8)(*NFI_DATAR);

    return cmd_status;
} /*  End of read_status */

/*******************************************************************************/
// NAND ID table:  { ID, planesize in MB, blocksize in KB, pagesize in B, address cycle, IO bus width, mtd sub driver}
// NANDSUBDriveData: {base_page, address_cycle, io_width, sub_driver}


kal_int32 InitializeMTDData(void * DriveData)       // read NAND ID and construct sub driver data
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint16 i, cs;
    kal_uint16 NTYPE[2];
    kal_uint32 id_data;
    kal_uint32 totalSize=0;

    /* Search NAND flash ID and */
    for(cs=0; cs<2; cs++)
    {
        if(cs==0)
        {
            SET_NFI_CS0;
        }
        else
        {
            SET_NFI_CS1;
        }

        *NFI_CMD = RD_ID_CMD;
    while (*NFI_PSTA & STATUS_CMD);
        *NFI_ADDRL = 0;
        *NFI_ADDNOB = 1;
    while (*NFI_PSTA & STATUS_ADDR);

        *NFI_OPCON = (NOB_WORD | SINGLE_RD);
        while (*NFI_PSTA & STATUS_DATAR);
        id_data = *NFI_DATAR;

        D->flash_info.id_data[cs] = id_data;

        for (i = 0; NAND_ID_Table[i].id != 0xFFFF ; i++)
        {
            if ( NAND_ID_Table[i].id == (id_data&0xFFFF) )
            {
                NTYPE[cs] = i;
                if(cs==0)
                {
                    D->flash_info.block_num = 0;  // prevent from wrong accumulation of mount device twice
                    D->flash_info.pages_per_block = (NAND_ID_Table[i].block_size*1024)/NAND_ID_Table[i].page_size;
                    D->flash_info.page_type = (NAND_ID_Table[i].page_size==512) ? PAGE_512 : PAGE_2K;
                    D->flash_info.io_width = NAND_ID_Table[i].io_width;
                    NANDSUBDriveData[cs].base_page = 0;
                }
                else
                {
                    //ASSERT(NAND_ID_Table[i].block_size == NAND_ID_Table[NTYPE[0]].block_size);
                    //ASSERT(NAND_ID_Table[i].page_size == NAND_ID_Table[NTYPE[0]].page_size);
                    if( (NAND_ID_Table[i].block_size != NAND_ID_Table[NTYPE[0]].block_size) ||
                        (NAND_ID_Table[i].page_size != NAND_ID_Table[NTYPE[0]].page_size) )
                    {
                        /* ignore NAND device on /cs1 if it has different page size or block size than the one on /cs0 */
                        NANDSUBDriveData[cs].page_size = 0;
                        kal_print("NAND flash on CS1 is not supported!");
                        break;
                    }
                    NANDSUBDriveData[cs].base_page = (NAND_ID_Table[NTYPE[0]].plane_size*1024*1024)
                                                                /NAND_ID_Table[NTYPE[0]].page_size;
                }
                totalSize += NAND_ID_Table[NTYPE[cs]].plane_size*1024*1024;
                NANDSUBDriveData[cs].address_cycle = NAND_ID_Table[i].address_cycle;
                NANDSUBDriveData[cs].io_width = NAND_ID_Table[i].io_width;
                NANDSUBDriveData[cs].sub_driver = NAND_ID_Table[i].sub_driver;

                NANDSUBDriveData[cs].page_size = NAND_ID_Table[i].page_size;
                NANDSUBDriveData[cs].pages_per_block =
                          (NAND_ID_Table[i].block_size*1024)/(NAND_ID_Table[i].page_size);
                NANDSUBDriveData[cs].plane_mask = NAND_ID_Table[i].plane_mask;

#ifdef _NAND_FLASH_BOOTING_
   D->flash_info.block_num = NFB_ALLOCATED_FAT_SPACE/(NAND_ID_Table[NTYPE[0]].block_size*1024);
    NFB_FLASH_BASE_PAGE = NFB_BASE_ADDRESS/NAND_ID_Table[NTYPE[0]].page_size;
#else
   D->flash_info.block_num += (NAND_ID_Table[NTYPE[cs]].plane_size*1024)/NAND_ID_Table[NTYPE[0]].block_size;
#endif
                break;
            }
        }

        *NFI_OPCON = 0;
        #ifdef _NAND_FLASH_BOOTING_
        ASSERT(totalSize >= NFB_ALLOCATED_FAT_SPACE + NFB_BASE_ADDRESS);
        #endif
        //ASSERT(! (NAND_ID_Table[i].id == 0xFFFF && cs==0) );
        if( (NAND_ID_Table[i].id) == 0xFFFF && (cs == 0) )
        {
            return MTD_STATUS_ID_NOT_SUPPORT;
        }

        if(cs)
        {
            SET_NFI_CS1_END;
            if( ( (NAND_ID_Table[i].id) != 0xFFFF )&&
                 (NANDSUBDriveData[cs].page_size != NANDSUBDriveData[0].page_size ) )
                return MTD_STATUS_ID_NOT_SUPPORT;
        }
    }

    //D->flash_info.region_num = D->flash_info.block_num/R_BLOCKS;  /*D->flash_info.region_num is decided at FDM layer FindControlBadBlock()*/

    return MTD_STATUS_NO_ERROR;

}

kal_int32 InitializeMTD(void * DriveData)
{
    NAND_FLASH_DRV_DATA * D = DriveData;
    kal_uint32 i;
    kal_int32 status = 0;

    /* Set MTD driver data */
    if( (status = InitializeMTDData(D)) != MTD_STATUS_NO_ERROR )
        return status;

    /* Set function pointer of MTD driver according to page size */
    if(D->flash_info.page_type==PAGE_2K)
    {
        NANDFlashMtd.ProgramPage = ProgramPage_2K;
        NANDFlashMtd.ReadPage = ReadPage_2K;
        NANDFlashMtd.ProgramSpare = ProgramSpare_2K;
    NANDFlashMtd.ReadSpare = ReadSpare_2K;
        #ifdef PAGE_COPY_SUPPORT
        for( i = 0 ; i < 2 ; i++)
        {
            if( (NANDSUBDriveData[i].sub_driver != NULL) &&
                (NANDSUBDriveData[i].sub_driver->CopyPage != NULL) )
            {
                NANDFlashMtd.CopyPage = CopyPage_2K;
                break;
            }
        }
        #endif
    }
    else
    {
        NANDFlashMtd.ProgramPage = ProgramPage_512;
        NANDFlashMtd.ReadPage = ReadPage_512;
        NANDFlashMtd.ProgramSpare = ProgramSpare_512;
        NANDFlashMtd.ReadSpare = ReadSpare_512;
        #ifdef PAGE_COPY_SUPPORT
        for( i = 0 ; i < 2 ; i++)
        {
            if( (NANDSUBDriveData[i].sub_driver != NULL) &&
                (NANDSUBDriveData[i].sub_driver->CopyPage != NULL) )/* flash device exists and supports copy back */
            {
                NANDFlashMtd.CopyPage = CopyPage_512;
                break;
            }
        }
        #endif
    }

    return MTD_STATUS_NO_ERROR;

}   /*  End of InitializeMTD */


/*******************************************************************************/
void nfi_lisr(void)
{
    IRQMask(IRQ_NFI_CODE);
    //kal_activate_hisr(nfi_hisr_id);
    drv_active_hisr(DRV_NFI_HISR_ID);
}


/*******************************************************************************/
void nfi_hisr(void)
{
    kal_uint16 intr_status;

    intr_status = *NFI_INTR;
    *NFI_INTR_EN = 0x0;
    if (intr_status & (WR_COMPLETE | ERASE_COMPLETE | BUSY_RETURN))
        kal_set_eg_events(nfi_egid, NFI_EVENT, KAL_OR);
    else if(intr_status != 0)
        EXT_ASSERT(0, intr_status, 0, 0);

    IRQClearInt(IRQ_NFI_CODE);
    IRQUnmask(IRQ_NFI_CODE);
}


/*******************************************************************************/
void NFI_DMA_Callback(void)
{
   if (nfi_egid)
      kal_set_eg_events(nfi_egid, NFI_EVENT, KAL_OR);
}

/*******************************************************************************/
void pdn_nfi(kal_bool ON)
{
    if (ON)
    {
        // dbg_print("turn on MSDC\r\n");
        DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_NFI,PDN_NFI);
    } else
    {
        // dbg_print("turn off NFI\r\n");
        DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_NFI,PDN_NFI);
    }
}



/*******************************************************************************/
// Sanity check for NAND device; only used in factory mode
/*-----------------------------------*/
static kal_bool IsNANDDevice(void)
{
   kal_uint32 id_data;
   kal_uint16 temp, i;
   kal_uint16 page_type;
   kal_uint8  io_width;

   /* initialize DMA and interrupt*/
   *PDN_CON0 &= ~0x0001;  // enable DMA
   *NFI_INTR_EN = 0x0;    // disable interrupt

   *NFI_OPCON = 0;
   *NFI_FIFOCON = RESET;
   *NFI_CON = 0;

   *NFI_ACCCON = ACCCON | (((NFI_W2R<<6)|(NFI_WH<<4)) | ((NFI_WST<<2)|NFI_RLC));

   /* default page format is 512 page-size for read ID by 8-bits I/O access */
   *NFI_PAGEFMT = PAGEFMT_512_8BIT;

   /* Read NAND Flash ID */
   *NFI_CMD = RD_ID_CMD;
   while (*NFI_PSTA & STATUS_CMD);
   *NFI_ADDRL = 0;// set up address
   if (NAND_ID_Table[i].address_cycle == 5)
      *NFI_ADDRM = 0;
   *NFI_ADDNOB = 1;
   while (*NFI_PSTA & STATUS_ADDR);

   *NFI_OPCON = (NOB_WORD | SINGLE_RD);
   NOT_WAIT_NFI_DONE(*NFI_PSTA & STATUS_DATAR)
   id_data = *NFI_DATAR;
   temp = (kal_uint16)(id_data & 0xFFFF);

   for(i = 0; NAND_ID_Table[i].id != 0xFFFF ; i++)
   {
      if( NAND_ID_Table[i].id == temp )
     {
         page_type = (NAND_ID_Table[i].page_size==512) ? PAGE_512 : PAGE_2K;
         io_width = NAND_ID_Table[i].io_width;
         break;
     }

   }

   if(NAND_ID_Table[i].id == 0xFFFF)
      return KAL_FALSE;

    /* Set page size and IO access width */
   if (page_type == PAGE_2K)
   {
      if (io_width == IO_ACCESS_8BIT)
      {
         *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
      }
      else
      {
         *NFI_PAGEFMT = PAGEFMT_2K_16BIT;

         #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
         *NFI_GPIO_DATA1 &= 0x0FFF;
         *NFI_GPIO_DATA2 &= 0xF000;
         #endif
      }
   }
   else
   {
      if (io_width == IO_ACCESS_8BIT)
      {
         *NFI_PAGEFMT = PAGEFMT_512_8BIT;
      }
      else
      {

         *NFI_PAGEFMT = PAGEFMT_512_16BIT;

         #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
         *NFI_GPIO_DATA1 &= 0x0FFF;
         *NFI_GPIO_DATA2 &= 0xF000;
         #endif
      }
   }

   /* Set function pointer of MTD driver according to page size *///CAUTION: is this necessary?
   if(page_type==PAGE_2K)
   {
      NANDFlashMtd.ProgramPage = ProgramPage_2K;
      NANDFlashMtd.ReadPage = ReadPage_2K;
      NANDFlashMtd.ProgramSpare = ProgramSpare_2K;
      NANDFlashMtd.ReadSpare = ReadSpare_2K;
   }
   else
   {
      NANDFlashMtd.ProgramPage = ProgramPage_512;
      NANDFlashMtd.ReadPage = ReadPage_512;
      NANDFlashMtd.ProgramSpare = ProgramSpare_512;
      NANDFlashMtd.ReadSpare = ReadSpare_512;
   }

   /* read one page to test if flash is accessable */
   *NFI_CMD = RD_1ST_CMD;       // read command
   while (*NFI_PSTA & STATUS_CMD);
   *NFI_ADDRL = 0;
   *NFI_ADDNOB = NAND_ID_Table[i].address_cycle;    // number of bytes for address
   while (*NFI_PSTA & STATUS_ADDR);

   if (page_type == PAGE_2K)
   {
      *NFI_CMD = RD_2ND_CYCLE_CMD;
      while (*NFI_PSTA & STATUS_CMD);
   }
   *NFI_OPCON = BURST_RD;// set burst read

   for(i=0; i<4; i++)
   {
      NOT_WAIT_NFI_DONE((*NFI_FIFOCON & RD_EMPTY_MASK))
      id_data = *NFI_DATAR;
   }

   *NFI_OPCON = 0;
   return KAL_TRUE;
}
static kal_bool IsSuperANDDevice(void);

kal_bool NANDsanitycheck_Factory(void)
{
   kal_uint32 id_data;
   kal_uint16 temp, i;
   kal_uint16 page_type;
   kal_uint8  io_width;
   kal_uint16 old_PFMT = 0, old_ACCCON = 0;
   kal_bool   result = KAL_FALSE;

   /* Initialize NFI setting */
   get_MTD_lock();
   pdn_nfi(1);

   // set NFI conrol bin in GPIO
   #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
    *NFI_GPIO_CON &= 0x000F;
   #elif defined MT6217
    *NFI_GPIO_CON &= 0xC003;
    *NFI_GPIO_CON |= 0x1554;
   #elif defined(MT6225)
    *NFI_GPIO_CON1 &= 0x03CF;
    *NFI_GPIO_CON1 |= 0x5420;
    *NFI_GPIO_CON2 &= 0xFFC0;
    *NFI_GPIO_CON2 |= 0x0015;
   #else
    *NFI_GPIO_CON &= 0xC003;
    *NFI_GPIO_CON |= 0x1554;
   #endif

   // in case that another operation is in progress.
   while (*NFI_PSTA & STATUS_BUSY);

   old_PFMT = *NFI_PAGEFMT;
   old_ACCCON = *NFI_ACCCON;

   if(IsNANDDevice())
      result = KAL_TRUE;
   else if(IsSuperANDDevice())
      result = KAL_TRUE;
   else
   {
      while (*NFI_PSTA & STATUS_BUSY);
      *NFI_OPCON = 0;
      *NFI_CON = 0;
      *NFI_ACCCON = old_ACCCON;
      *NFI_PAGEFMT = old_PFMT;
      *NFI_FIFOCON = RESET;
      result = KAL_FALSE;
   }

   pdn_nfi(0);
   free_MTD_lock();
   return result;
} /*  End of NANDsanitycheck_Factory */

/******************************************************************************
 * SuperAND flash device definition                                           *
 ******************************************************************************/
static kal_bool mtd_mounted;
static const superand_flash_list superand_id_table[] =
{
    /* ID    Capacity(MBytes)   Sector_size(KBytes) io_width(bits)               */
    {0x5807,        64,               16,                    8}, /* M5M25G00C1WG */
    {0x5B07,        64,               16,                   16}, /* M5M25G00C1WG */
    {0x4907,        32,               8,                    8}, /* M6MGA157F2LCWG */
    {0x4A07,        32,               8,                   16}, /* M6MGA157F2LCWG */
    SUPERAND_FLASH_LIST_END
};

void SuperAND_MTD_Init(void)
{
    SuperAND_MTD_DRIVER *mtd_drv = (SuperAND_MTD_DRIVER*)&NANDFlashMtd;

    mtd_drv->MountDevice    = SuperAND_MTD_MountDevice;
    mtd_drv->ShutDown       = SuperAND_MTD_ShutDown;
    mtd_drv->ReadPages      = SuperAND_MTD_ReadPages;
    mtd_drv->RewritePages   = SuperAND_MTD_RewritePages;
    mtd_drv->ProgramData    = SuperAND_MTD_ProgramData;
    mtd_drv->EraseBlock     = SuperAND_MTD_EraseBlock;
    mtd_drv->ReadGoodBlkCnt = SuperAND_MTD_ReadGoodBlkCnt;
}

kal_int32 SuperAND_MTD_MountDevice(void * DriveData)
{
    SuperAND_FLASH_DRV_DATA * D = (SuperAND_FLASH_DRV_DATA*)DriveData;

    if(mtd_mounted)
        return FS_NO_ERROR;
    get_MTD_lock();
    pdn_nfi(1);

#if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
    *NFI_GPIO_CON &= 0x000F;
#elif defined(MT6225)
    *NFI_GPIO_CON1 &= 0x03CF;
    *NFI_GPIO_CON1 |= 0x5420;
    *NFI_GPIO_CON2 &= 0xFFC0;
    *NFI_GPIO_CON2 |= 0x0015;
#else
    *NFI_GPIO_CON &= 0xC003;
    *NFI_GPIO_CON |= 0x1554;
#endif

      /* In case that NFI is performing an operation */
      while (*NFI_PSTA & STATUS_BUSY);
      *NFI_OPCON = 0;
      *NFI_FIFOCON = RESET;
      *NFI_CON = 0;

    *NFI_ACCCON = SUPERAND_ACCCON;

    /* initialize DMA and interrupt*/
    *PDN_CON0 &= ~0x0001;  // enable DMA ???
    *NFI_INTR_EN = 0x0;    // disable interrupt

    if(superand_checkdevice(DriveData) != KAL_TRUE)
    {
        pdn_nfi(0);
        free_MTD_lock();
        return FS_FLASH_MOUNT_ERROR;
    }
    mtd_mounted = KAL_TRUE;

    nfi_menu.TMOD.burst_mode = KAL_FALSE;
    nfi_menu.master = DMA_NFI;

    nfi_input.menu = &nfi_menu;

    /* Set page size and IO access width */
    if (D->io_width == IO_ACCESS_8BIT)
    {
        *NFI_PAGEFMT = SUPERAND_PAGEFMT_8BIT;
    }
    else
    {
         *NFI_PAGEFMT = SUPERAND_PAGEFMT_16BIT;
            #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
                *NFI_GPIO_DATA1 &= 0x0FFF;
                *NFI_GPIO_DATA2 &= 0xF000;
            #endif
    }

    *NFI_OPCON = 0;
    pdn_nfi(0);
    free_MTD_lock();
    return FS_NO_ERROR;
}   /*  End of SuperAND_MTD_MountDevice */

kal_uint16 superand_read_device_id(kal_uint16 csel)
{
#if !(defined(MT6218B) || defined(MT6219))
    *NFI_CSEL = csel;
#endif
    /* Search NAND flash ID */
    *NFI_CMD = RD_ID_CMD;
    NOT_WAIT_NFI_DONE(*NFI_PSTA & STATUS_CMD)
    *NFI_ADDRL = 0;
    *NFI_ADDNOB = 1;
    *NFI_OPCON = (NOB_WORD | SINGLE_RD);
    NOT_WAIT_NFI_DONE(*NFI_PSTA & STATUS_DATAR)

    return (kal_uint16)(*NFI_DATAR);
}

kal_bool superand_checkdevice(void * DriveData)
{
    SuperAND_FLASH_DRV_DATA * D = (SuperAND_FLASH_DRV_DATA*)DriveData;
    kal_uint16 id_data;
    kal_uint16 i, device_idx;

    /* Read device ID of the device mounted on CS0 */
    id_data = superand_read_device_id(0);
    for (i = 0; superand_id_table[i].id != 0xFFFF ; i++)
    {
        if ( superand_id_table[i].id == id_data )
        {
            device_idx = i;
            break;
        }
    }

    if (superand_id_table[i].id == 0xFFFF)
        return 0;

    D->pages_of_first_device = superand_id_table[i].plane_size << 11;
    D->total_pages = D->pages_of_first_device;
    D->pages_of_block = superand_id_table[i].block_size << 1;
    D->io_width = superand_id_table[i].io_width;
    //if ( custom_part_secs > 0 && custom_part_secs < 400)
    //{
    //  ASSERT(0);
    //}
    //else
        D->partition_sectors = custom_part_secs;

    /* Create event group, create HISR and register LISR */
    nfi_egid = kal_create_event_group("NFI_EG");
    //nfi_hisr_id = kal_create_hisr("NFI_HISR",1,512,nfi_hisr,NULL);
    DRV_Register_HISR(DRV_NFI_HISR_ID, nfi_hisr);
    IRQ_Register_LISR(IRQ_NFI_CODE, nfi_lisr, "NFI_LISR");
    IRQSensitivity(IRQ_NFI_CODE, EDGE_SENSITIVE);
    IRQUnmask(IRQ_NFI_CODE);

    SuperAND_MTD_EraseBlock(DriveData, 0); //In case power loss during Rewrite

#if !(defined(MT6218B) || defined(MT6219))
    /* Read device ID of the device mounted on CS1 */
    id_data = superand_read_device_id(1);
    for (i = 0; superand_id_table[i].id != 0xFFFF ; i++)
    {
        if ( superand_id_table[i].id == id_data )
        {
            break;
        }
    }

    if(superand_id_table[i].id != 0xFFFF)
    {
        ASSERT(superand_id_table[i].id == superand_id_table[device_idx].id);
        D->total_pages <<= 1;
        SuperAND_MTD_EraseBlock(DriveData, (D->total_pages - D->pages_of_block)); //In case power loss during Rewrite
    }
#endif

    return 1;
}   /*  End of InitializeMTD */

kal_int32 SuperAND_MTD_ShutDown(void * DriveData)
{
    return FS_NO_ERROR;
}   /*  End of SuperAND_MTD_ShutDown */

#if (defined(MT6218B) || defined(MT6219))
kal_int32 SuperAND_MTD_ReadPages(void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data)
{
    SuperAND_FLASH_DRV_DATA * D = (SuperAND_FLASH_DRV_DATA*)DriveData;
    kal_uint32 addr;
    get_MTD_lock();
    pdn_nfi(1);

    if((kal_uint32)Data & 0x3)
    {
        /* Not 4bytes-alignment buffer */
        *NFI_CON = 0;
    }
    else
    {
        /* 4bytes-alignment buffer */
        *NFI_CON = DMA_RD_EN;
    }

    while(Pages)
    {
        COMPUTE_ADDRESS_AND_SET_CSEL;
        *NFI_FIFOCON = RESET;

        *NFI_CMD = SUPERAND_PAGE_READ_CMD;
        *NFI_ADDRL = addr;
        *NFI_ADDNOB = SUPERAND_ADDR_CYCLE;
        *NFI_OPCON = BURST_RD;

        superand_readfifo(Data, 1);

        /* According to data sheet, after reading the SUPERAND_READ_END_CMD command should be issued to flash */
        *NFI_CMD = SUPERAND_READ_END_CMD;

        /* Set NFI to idle */
        *NFI_OPCON = 0x0;

        Data += PAGES2BYTES(1);
        Pages--;
        PageIndex++;

        /* Make sure the SUPERAND_READ_END_CMD command is sent completely by NFI */
        while (*NFI_PSTA & STATUS_CMD);
    }

    pdn_nfi(0);
    free_MTD_lock();
    return FS_NO_ERROR;
}   /*  End of SuperAND_MTD_ReadPages */

void superand_readfifo(kal_uint8 * Data, kal_uint32 Pages)
{
    kal_uint32 event_group;

    if((kal_uint32)Data & 0x3)
    {
        /* Not 4bytes-alignment buffer */
        /* Because MT6218B and MT6219 don't have byte reading register */
        kal_uint32 i;
        kal_uint32 temp, length;
        kal_uint8 *temp_p8;

        temp_p8 = (kal_uint8*)&temp;
        length = PAGES2DWORDS(Pages);

        for (i = 0; i < length; i++)
        {
            while ((*NFI_FIFOCON & RD_EMPTY_MASK));

            temp = *NFI_DATAR;

            Data[0] = temp_p8[0];
            Data[1] = temp_p8[1];
            Data[2] = temp_p8[2];
            Data[3] = temp_p8[3];

            Data += sizeof(kal_uint32);
        }
    }
    else
    {
        /* 4bytes-alignment buffer */
        nfi_menu.source  = (kal_uint32)NFI_DATAR; //read DWORD-by-DWORD
        nfi_input.size = DMA_LONG;
        nfi_input.count = PAGES2DWORDS(Pages);

        if(use_interrupt == KAL_TRUE)
        {
            nfi_input.callback = NFI_DMA_Callback;
        }
        else
            nfi_input.callback = NULL;

        nfi_menu.destination = (kal_uint32)Data;
        nfi_menu.TMOD.burst_mode = KAL_FALSE;
        nfi_input.type = DMA_HWRX;

        nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

        /* Configure DMA to read data */
        DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

        if(use_interrupt == KAL_TRUE)
        {
            /* Wait for DMA completing data reading */
            kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                            &event_group, KAL_SUSPEND);
        }
        else
        {
            while (IS_NFI_DMA_RUN);

            //using interrupt instead of polling after system initialization and before exception in normal mode
            if(kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE)
                use_interrupt = KAL_TRUE;
        }


        DMA_FullSize_FreeChannel(nfi_dmaport);

        nfi_dmaport = 0;
    }
}   /*  End of superand_readfifo */

#else /* MT6217 or the newer */
/* Sequential read*/
kal_int32 SuperAND_MTD_ReadPages(void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data)
{
    SuperAND_FLASH_DRV_DATA * D = (SuperAND_FLASH_DRV_DATA*)DriveData;
    kal_uint32 addr;
    kal_uint32 proc_pages;
    get_MTD_lock();
    pdn_nfi(1);

    COMPUTE_ADDRESS_AND_SET_CSEL;
    *NFI_FIFOCON = RESET;
    if((kal_uint32)Data & 0x3)
    {
        /* Not 4bytes-alignment buffer */
        *NFI_CON = (BYTE_RW_EN | DMA_RD_EN);
    }
    else
    {
        /* 4bytes-alignment buffer */
        *NFI_CON = DMA_RD_EN;
    }
    /* If the number of pages is greater than 1 the sequential read is used */
    *NFI_CMD = (Pages == 1) ? SUPERAND_PAGE_READ_CMD : SUPERAND_SEQ_READ_CMD;
    *NFI_ADDRL = addr;
    *NFI_ADDNOB = SUPERAND_ADDR_CYCLE;

    /* Wait for NFI and flash to be ready */
    while(*NFI_PSTA != 0);

    *NFI_OPCON = BURST_RD;

    proc_pages = SUPERAND_PAGES_PER_SECTOR - (PageIndex & 0x3);
    if(proc_pages > Pages) proc_pages = Pages;

    while(Pages)
    {
        superand_readfifo(Data, proc_pages);
        Pages -= proc_pages;
        if(Pages != 0)
        {
            Data += PAGES2BYTES(proc_pages);
            proc_pages = (Pages < SUPERAND_PAGES_PER_SECTOR) ?  Pages : SUPERAND_PAGES_PER_SECTOR;

            /* Wait for flash to be ready due to sequential read for next sector */
            while(*NFI_PSTA != 0);

            /* Reset fifo, NFI starts to issue read strobe */
            *NFI_FIFOCON = 0x20;
        }
    }

    /* Set NFI to idle */
    *NFI_OPCON = 0x0;

    /* According to data sheet, after reading the SUPERAND_READ_END_CMD command should be issued to flash */
    *NFI_CMD = SUPERAND_READ_END_CMD;

    /* Make sure the SUPERAND_READ_END_CMD command is sent completely by NFI */
    while (*NFI_PSTA & STATUS_CMD);

    pdn_nfi(0);
    free_MTD_lock();
    return FS_NO_ERROR;
}   /*  End of SuperAND_MTD_ReadPages */

void superand_readfifo(kal_uint8 * Data, kal_uint32 Pages)
{
    kal_uint32 event_group;

    if((kal_uint32)Data & 0x3)
    {
        /* Not 4bytes-alignment buffer */
        nfi_menu.source  = (kal_uint32)NFI_DATARB; //read byte-by-byte
        nfi_input.size = DMA_BYTE;
        nfi_input.count = PAGES2BYTES(Pages);
    }
    else
    {
        /* 4bytes-alignment buffer */
        nfi_menu.source  = (kal_uint32)NFI_DATAR; //read DWORD-by-DWORD
        nfi_input.size = DMA_LONG;
        nfi_input.count = PAGES2DWORDS(Pages);
    }

    if(use_interrupt == KAL_TRUE)
    {
        nfi_input.callback = NFI_DMA_Callback;
    }
    else
        nfi_input.callback = NULL;

    nfi_menu.destination = (kal_uint32)Data;
    nfi_menu.TMOD.burst_mode = KAL_FALSE;
    nfi_input.type = DMA_HWRX;

    nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

    /* Configure DMA to read data */
    DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

    if(use_interrupt == KAL_TRUE)
    {
        /* Wait for DMA completing data reading */
        kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                        &event_group, KAL_SUSPEND);
    }
    else
    {
        while (IS_NFI_DMA_RUN);

        //using interrupt instead of polling after system initialization and before exception in normal mode
        if(kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE)
            use_interrupt = KAL_TRUE;
    }

    DMA_FullSize_FreeChannel(nfi_dmaport);

    nfi_dmaport = 0;
}   /*  End of superand_readfifo */

#endif

kal_int32 SuperAND_MTD_RewritePages(void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data)
{
    ASSERT(Pages <= (SUPERAND_PAGES_PER_SECTOR << 1));

    if(superand_writefifo(DriveData, PageIndex, Data, (Pages << 9), KAL_TRUE) != FS_NO_ERROR)
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;

}   /*  End of SuperAND_MTD_RewritePages */

kal_int32 SuperAND_MTD_ProgramData(void * DriveData, kal_uint32 PageIndex, kal_uint32 Bytes, kal_uint8 * Data)
{

    if(superand_writefifo(DriveData, PageIndex, Data, Bytes, KAL_FALSE) != FS_NO_ERROR)
    {
        ASSERT(0);
        return FS_DATA_ERROR;
    }
    else
        return FS_NO_ERROR;

}   /*  End of SuperAND_MTD_ProgramData */

kal_int32 superand_writefifo(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint32 Bytes, kal_bool rewrite)
{
    SuperAND_FLASH_DRV_DATA * D = (SuperAND_FLASH_DRV_DATA*)DriveData;
    kal_uint32 addr;
    kal_uint32 proc_pages;
    kal_uint32 proc_bytes;
    kal_uint32 event_group;
    kal_bool four_byte_aligned;
    kal_uint8  wr_status;
    #if defined(MT6225)
    ECO_VERSION eco_6225;

    eco_6225 = INT_ecoVersion();
    #endif

    four_byte_aligned = ((kal_uint32)Data & 0x3) ? KAL_FALSE : KAL_TRUE;
    get_MTD_lock();
    pdn_nfi(1);

    if (use_interrupt == KAL_TRUE)
        *NFI_INTR_EN = BUSY_RETURN_EN;

#if (defined(MT6218B) || defined(MT6219))
    *NFI_CON = 0x0002; //for DMA
#else
    *NFI_CON = (four_byte_aligned) ? 0x0002 : 0x8002; //for DMA
#endif

    *NFI_OPCON = BURST_WR; // Be carefull

    nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

    while(Bytes)
    {
        proc_pages = SUPERAND_PAGES_PER_SECTOR - (PageIndex & SUPERAND_SECTOR_MASK);
        proc_bytes = ((proc_pages << 9) > Bytes) ? Bytes : (proc_pages << 9);

        COMPUTE_ADDRESS_AND_SET_CSEL;
        *NFI_CMD = INPUT_DATA_CMD;
        *NFI_ADDRL = addr;
        *NFI_ADDNOB = SUPERAND_ADDR_CYCLE;

        if(four_byte_aligned)
        {
            nfi_menu.destination  = (kal_uint32)NFI_DATAW;
            nfi_input.size = DMA_LONG;
            nfi_input.count = (proc_bytes+3) >> 2;
        }
        else
        {
            nfi_menu.destination  = (kal_uint32)NFI_DATAWB;
            nfi_input.size = DMA_BYTE;
            nfi_input.count = proc_bytes;
        }

        if(use_interrupt == KAL_TRUE)
        {
            nfi_input.callback = NFI_DMA_Callback;
        }
        else
            nfi_input.callback = NULL;

        nfi_menu.source = (kal_uint32)Data;
        #if defined(MT6225)
        if(eco_6225 <= ECO_E3)
        nfi_menu.TMOD.burst_mode = KAL_FALSE;
        else
        nfi_menu.TMOD.burst_mode = KAL_TRUE;
        #else
        nfi_menu.TMOD.burst_mode = KAL_TRUE;
        #endif
        nfi_input.type = DMA_HWTX;

        DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

        if(use_interrupt == KAL_TRUE)
        {
            /* Wait for DMA completing data writing */
            kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                            &event_group, KAL_SUSPEND);
        }
        else
        {
            while (IS_NFI_DMA_RUN);
        }

        Bytes -= proc_bytes;
        if(Bytes != 0)
        {
            PageIndex += proc_pages;
            Data += proc_bytes;

            /* Extended program or rewrite */
            *NFI_CMD = 0x11;

            /* Wait for NFI to finish sending command to flash */
            while(*NFI_PSTA != 0);
        }
    }
    DMA_FullSize_FreeChannel(nfi_dmaport);
    nfi_dmaport = 0;

    /* Wait for NFI to finish sending all data to flash */
    while (*NFI_PSTA & STATUS_DATAW);

    *NFI_OPCON = 0x0;
    *NFI_CMD = (rewrite == KAL_TRUE) ? SUPERAND_REWRITE_CMD : SUPERAND_PROG_CMD;

    if(use_interrupt == KAL_TRUE)
    {
        /* Wait for NAND flash completing data program */
        kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                        &event_group, KAL_SUSPEND);
    }
    else
    {
        while (*NFI_PSTA);

        //using interrupt instead of polling after system initialization and before exception in normal mode
        if(kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE)
            use_interrupt = KAL_TRUE;
    }

    wr_status = superand_read_status()& 0x1;

    pdn_nfi(0);
    free_MTD_lock();
    if(wr_status)
        return FS_DATA_ERROR;
    else
        return FS_NO_ERROR;

}   /*  End of superand_writefifo */

kal_int32 SuperAND_MTD_EraseBlock(void * DriveData, kal_uint32 PageIndex)
{
    SuperAND_FLASH_DRV_DATA * D = (SuperAND_FLASH_DRV_DATA*)DriveData;
    kal_uint32 sec_addr, addr;
    kal_uint32 event_group;

    ASSERT((PageIndex & 0x3) == 0);
    get_MTD_lock();
    pdn_nfi(1);
    COMPUTE_ADDRESS_AND_SET_CSEL;
    /* The sector of SuperAND contains 4 pages, the sector address is contructed
       by ignoring the last 2 bits of PageIndex */
    sec_addr = addr >> 16;

    *NFI_CON = 0x0;
    *NFI_OPCON = 0x0;

    if (use_interrupt == KAL_TRUE)
        *NFI_INTR_EN = ERASE_COMPLETE_EN;

    *NFI_CMD = BLOCK_ERASE1_CMD;        // erase command phase 1
    *NFI_ADDRL = sec_addr;                  // erase block address
    *NFI_ADDNOB = 2;        // no. of block address
    while (*NFI_PSTA);
    *NFI_CMD = BLOCK_ERASE2_CMD;        // erase command phase 2

    if(use_interrupt == KAL_TRUE)
    {
        /* Wait for DMA completing block erase */
        kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                        &event_group, KAL_SUSPEND);
    }
    else
    {
        while (*NFI_PSTA);

        //using interrupt instead of polling after system initialization and before exception in normal mode
        if(kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE)
            use_interrupt = KAL_TRUE;
    }

    if(superand_read_status()&0x1)
        ASSERT(0);

    pdn_nfi(0);
    free_MTD_lock();
    return FS_NO_ERROR;
}   /*  End of SuperAND_MTD_EraseBlock */

kal_uint8 superand_read_status(void)
{
    kal_uint8 cmd_status;

    *NFI_CMD = RD_STATUS_CMD;
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_OPCON = (NOB_BYTE | SINGLE_RD);
    while (*NFI_PSTA & STATUS_DATAR);
    cmd_status = (kal_uint8)(*NFI_DATAR);

    return cmd_status;
} /*  End of read_status */

kal_int32 SuperAND_MTD_ReadGoodBlkCnt(void * DriveData)
{
    /* Can't be used in MT6218B */
    kal_int32 blk_cnt;
    get_MTD_lock();
    pdn_nfi(1);

    *NFI_CMD = 0xF0;
    while (*NFI_PSTA);
    *NFI_CMD = 0xCC;
    while (*NFI_PSTA);
    *NFI_CMD = 0xA5;
    while (*NFI_PSTA);
    *NFI_CMD = 0x5A;
    while (*NFI_PSTA);
    *NFI_CMD = 0xD1;
    while (*NFI_PSTA);
    *NFI_CMD = 0xE0;
    while (*NFI_PSTA);

    *NFI_ADDRL = 0;
    *NFI_ADDNOB = SUPERAND_ADDR_CYCLE;
    while (*NFI_PSTA);

    *NFI_CMD = 0x01;
    while (*NFI_PSTA);

    *NFI_OPCON = (NOB_WORD | SINGLE_RD);
    while (*NFI_PSTA);
    blk_cnt = (kal_int32)((*NFI_DATAR) & 0xFFFF);

    *NFI_OPCON = 0;

    *NFI_CMD = 0xCF;
    while (*NFI_PSTA);
    *NFI_CMD = 0xD1;
    while (*NFI_PSTA);

    pdn_nfi(0);
    free_MTD_lock();
    return blk_cnt;
} /*  End of read_status */

static kal_bool IsSuperANDDevice(void)
{
//  SuperAND_FLASH_DRV_DATA * D = (SuperAND_FLASH_DRV_DATA*)&NANDFlashDriveData;
   kal_uint16 id_data;
   kal_uint16 i, device_idx;

   /* initialize DMA and interrupt*/
   *PDN_CON0 &= ~0x0001;  // enable DMA ???
   *NFI_INTR_EN = 0x0;     // disable interrupt

   *NFI_OPCON = 0;
   *NFI_FIFOCON = RESET;
   *NFI_CON = 0;

   /* default page format is 512 page-size for read ID by 8-bits I/O access */
   *NFI_PAGEFMT = PAGEFMT_512_8BIT;

   *NFI_ACCCON = SUPERAND_ACCCON;

   /* Read device ID of the device mounted on CS0 */
   id_data = superand_read_device_id(0);
   for (i = 0; superand_id_table[i].id != 0xFFFF ; i++)
   {
      if ( superand_id_table[i].id == id_data )
      {
         device_idx = i;
         break;
      }
   }

   if (superand_id_table[i].id == 0xFFFF)
      return KAL_FALSE;

   /* Set page size and IO access width */
   //if (D->io_width == IO_ACCESS_8BIT)
   if(IO_ACCESS_8BIT == superand_id_table[i].io_width)
   {
      *NFI_PAGEFMT = SUPERAND_PAGEFMT_8BIT;
   }
   else if(IO_ACCESS_16BIT == superand_id_table[i].io_width)
   {
      *NFI_PAGEFMT = SUPERAND_PAGEFMT_16BIT;
      #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
      *NFI_GPIO_DATA1 &= 0x0FFF;
      *NFI_GPIO_DATA2 &= 0xF000;
      #endif
   }
   else
      ASSERT(0);

    //SuperAND_MTD_EraseBlock(DriveData, 0); //In case power loss during Rewrite

#if !(defined(MT6218B) || defined(MT6219))
    /* Read device ID of the device mounted on CS1 */
    id_data = superand_read_device_id(1);
   for (i = 0; superand_id_table[i].id != 0xFFFF ; i++)
   {
      if ( superand_id_table[i].id == id_data )
      {
         break;
      }
   }

   if(superand_id_table[i].id != 0xFFFF)
   {
        ASSERT(superand_id_table[i].id == superand_id_table[device_idx].id);
        //D->total_pages <<= 1;
        //SuperAND_MTD_EraseBlock(DriveData, (D->total_pages - D->pages_of_block)); //In case power loss during Rewrite
    }
#endif

   return KAL_TRUE;
}
#else
/*In no NFI platform, ext_camera.c is still possible to call get_NFI_bus() and free_NFI_bus()*/
void get_NFI_bus(void)
{
}

void free_NFI_bus(void)
{
}
#endif  // ifdef(MT6205)
