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
 *	flash_user.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This is the flash user's API
 *  Original file name is flash_int.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "NAND_FDM.h"

extern NOR_FLASH_DRV_Data  FlashDriveData; 

#ifdef __USB_ENABLE__

#include "drv_comm.h"
#include "usb_msdisk.h"

#define FLASH_USB_ADAPT_C

#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )

extern FS_Driver NORFlashDriver;
static FS_Driver *CardDrv = &NORFlashDriver;

static kal_bool usbms_read_nor( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_int32 status;
	FS_PartitionRecord *Par, Par1;
	
	status = CardDrv->ReadSectors((void *)(&FlashDriveData),LBA,sec_len,data);

	if(status)
		ASSERT(0);
		
   if(LBA == 0)
	{
	   kal_mem_set( (void *)(&Par1), 0x00, sizeof(FS_PartitionRecord) );
	   Par = (FS_PartitionRecord *)(&(((FS_MasterBootRecord *)data)->PTable[1]));
	   *Par = Par1;
	}		

	return KAL_TRUE;
}

static kal_bool usbms_write_nor(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
   kal_int32 status;

	/* prevent USB to write sector 0 */
	if(LBA==0)
	  return KAL_TRUE;
	else
	  status = CardDrv->WriteSectors((void *)(&FlashDriveData),LBA,sec_len,data);

	if(status)
	    ASSERT(0);
	
	return KAL_TRUE;
}

/*status =0(ok),1(MediaChanged),2(NoMedia)*/
static kal_uint8 usbms_checkmedia_exit_nor(void)
{
   return 0;
}

static kal_bool usbms_format_nor()
{
   CardDrv->MountDevice((void *)(&FlashDriveData), 1, FS_DEVICE_FDISK, 0);

   return KAL_TRUE;  
}

static kal_bool usbms_prevmedia_removal_nor(kal_bool enable)
{
   return KAL_TRUE;
}

static kal_bool usbms_read_capacity_nor(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
   kal_int32 status;

   status = CardDrv->MountDevice((void *)(&FlashDriveData), 1, FS_DEVICE_FDISK, 0);
	if(status != 512)
		ASSERT(0);
 	*max_lba = FlashDriveData.TotalFATSectors-1;
	*sec_len =512;

   return KAL_TRUE;
}
/*
static kal_bool usbms_read_formatcapacity_nor(kal_uint32 *no_of_blks, kal_uint32 *blk_len)
{
	kal_int32 status;

   status = CardDrv->MountDevice((void *)(&FlashDriveData), 1, FS_DEVICE_FDISK, 0);
	if(status != 512)
		ASSERT(0);
 	*no_of_blks = FlashDriveData.TotalFATSectors;
	*blk_len =512;

   return KAL_TRUE;
}
*/

static USB_STORAGE_DEV_TYPE usbms_dev_type_nor(void)
{
	return USB_STORAGE_DEV_NOR;	
}

#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */

USB_DiskDriver_STRUCT USB_NOR_drv = 
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )   
	usbms_read_nor,
	usbms_write_nor,
	usbms_format_nor,
	usbms_checkmedia_exit_nor,
	usbms_prevmedia_removal_nor,
	usbms_read_capacity_nor,
//	usbms_read_formatcapacity_nor,
	usbms_dev_type_nor
#else
   0, 0, 0, 0, 0, 0, 0
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
};

/* parameter for performance of USB mode */
kal_uint32 write_startsec_array[4];
kal_uint32 read_startsec_array[4];
kal_uint32 write_length_array[128];
kal_uint32 read_length_array[128];

kal_uint32 total_read_sector;
kal_uint32 total_write_sector;
kal_int32 total_read_time;
kal_int32 total_write_time;

static kal_int32 debug_usb = 0;

extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;
extern FS_Driver NANDFlashDriver;
static FS_Driver *NANDCardDrv = &NANDFlashDriver;
//extern kal_int32 TMD_System_Clock;

static kal_bool usbms_read_nand( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_int32 status;
	kal_int32 start_time, end_time;
	
	kal_get_time((kal_uint32 *)&start_time);
	status = NANDCardDrv->ReadSectors((void *)(&NANDFlashDriveData),LBA,sec_len,data);
	kal_get_time((kal_uint32 *)&end_time);

	if(status) ASSERT(0);

	/* record start sector and sector length for histogram statistics;
	   record total read sectors and read time for throughput test */
	read_startsec_array[(LBA%4)]++;
	if(sec_len < 128)
	  read_length_array[(sec_len-1)]++;
	else
	  read_length_array[127]++;

	total_read_sector += sec_len;
	total_read_time += (end_time - start_time);

	return KAL_TRUE;
}

static kal_bool usbms_write_nand(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
   kal_int32 status;
   kal_int32 start_time, end_time;


   //status = NANDCardDrv->WriteSectors((void *)(&NANDFlashDriveData),LBA,sec_len,data);		   

   
    /* prevent USB to write sector 0 */
	if(LBA==0)
	  return KAL_TRUE;
	else
	{
	   kal_get_time((kal_uint32 *)&start_time);
	   status = NANDCardDrv->WriteSectors((void *)(&NANDFlashDriveData),LBA,sec_len,data);		   
	   kal_get_time((kal_uint32 *)&end_time);
	}
   
   
   /* prevent USB to write sector 0 and sector 1 */
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
/* under construction !*/
	#endif
	
	
	if(status)
	    ASSERT(0);
	

	/* record start sector and sector length for histogram statistics;
	   record total write sectors and write time for throughput test */
	write_startsec_array[(LBA%4)]++;
	if(sec_len < 128)
	  write_length_array[(sec_len-1)]++;
	else
	  write_length_array[127]++;

	total_write_sector += sec_len;
	total_write_time += (end_time - start_time);


	return KAL_TRUE;
}

/*status =0(ok),1(MediaChanged),2(NoMedia)*/
static kal_uint8 usbms_checkmedia_exit_nand(void)
{
   return 0;
}

static kal_bool usbms_format_nand()
{
   NANDCardDrv->MountDevice((void *)(&NANDFlashDriveData), 1, FS_DEVICE_FDISK, 0);

   return KAL_TRUE;  
}

static kal_bool usbms_prevmedia_removal_nand(kal_bool enable)
{
   return KAL_TRUE;
}

static kal_bool usbms_read_capacity_nand(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
   kal_int32 status;
   
   status = NANDCardDrv->MountDevice((void *)(&NANDFlashDriveData), 1, FS_DEVICE_FDISK, 0);
	if(status != 512)
		ASSERT(0);
    
    if(NANDCardDrv->MountDevice != SuperAND_FDM_MountDevice)
    {
 	    *max_lba = NANDFlashDriveData.flash_info.total_FAT_sectors - 1;
 	}
 	else
 	{
 	    SuperAND_FLASH_DRV_DATA *D = (SuperAND_FLASH_DRV_DATA*)&NANDFlashDriveData;
 	    *max_lba = D->total_fat_sectors - 1;
 	}
	*sec_len =512;

   return KAL_TRUE;
}
/*
static kal_bool usbms_read_formatcapacity_nand(kal_uint32 *no_of_blks, kal_uint32 *blk_len)
{
	kal_int32 status;

   status = NANDCardDrv->MountDevice((void *)(&NANDFlashDriveData), 1, FS_DEVICE_FDISK, 0);
	if(status != 512)
		ASSERT(0);

    if(NANDCardDrv->MountDevice != SuperAND_FDM_MountDevice)
    {
 	    *no_of_blks = NANDFlashDriveData.flash_info.total_FAT_sectors;
 	}
 	else
 	{
 	    SuperAND_FLASH_DRV_DATA *D = (SuperAND_FLASH_DRV_DATA*)&NANDFlashDriveData;
 	    *no_of_blks = D->total_fat_sectors;
 	}		
	*blk_len =512;

   return KAL_TRUE;
}
*/

static USB_STORAGE_DEV_TYPE usbms_dev_type_nand(void)
{
	return USB_STORAGE_DEV_NAND;	
}

USB_DiskDriver_STRUCT USB_NAND_drv = {
	usbms_read_nand,
	usbms_write_nand,
	usbms_format_nand,
	usbms_checkmedia_exit_nand,
	usbms_prevmedia_removal_nand,
	usbms_read_capacity_nand,
//	usbms_read_formatcapacity_nand,
	usbms_dev_type_nand
};


#endif /* __USB_ENABLE__ */

int Check_NORFlash_Formatted(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )

   int i = 0, j;
   int addr;
   NOR_Flash_MTD_Data *p = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
     
   addr = (int)(p->BaseAddr);
      
   while(p->RegionInfo[i].BlockSize)
   {
      for(j = 0; j < p->RegionInfo[i].RegionBlocks; j++)
      {
         if(*(volatile unsigned short*)addr != 0xffff)
         {
            return 0; //formatted (may false alarm!)
         }
         else
         {
            addr += p->RegionInfo[i].BlockSize;
         }
      }
      i++;
   }
   return 1; //unformatted
   
#else   
   
   return 0; //formatted (may false alarm!)
   
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */ 
}