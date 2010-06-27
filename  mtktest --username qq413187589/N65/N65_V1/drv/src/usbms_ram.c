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
 *    usbms_ram.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb adaption layer of ram disk for mass storage
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#include "drv_comm.h"
#include "gpt_sw.h"
#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usbms_utils.h"
#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usb_custom.h"



/***********************************************
	RAM Disk Related functions
************************************************/
#ifdef __USB_RAMDISK__

static const kal_uint8 MBR[16]=
{
	0x80,
	0x02,
	0x0a,
	0x00,
	0x01,
	0x03,
	0x50,
	0xf3,
	0x02,
	0x00,
	0x00,
	0x00,
	0x1e,
	0x00,
	0x00,
	0x00
};

static const kal_uint8 BRSIG[2]=
{
	0x55,
	0xaa
};

static const kal_uint8 PBR[]=
{	/*64*/
	0xE9,
	0x00,
	0x00,
	0x2A, /* 8 */
	0x64,
	0x38,
	0x65,
	0x39,
	0x49,
	0x48,
	0x43,
	0x00, /* 25 */
	0x02,
	0x01,
	0x01,
	0x00,
	0x01,  /* 1FAT */
	0x10,  /* 16 entries */
	0x00,
	0x1e,
	0x00,
	0xF8,
	0x01, 
	0x00,
	0x10, /* no of tracks */
	0x00,
	0x04,
	0x00,
	0x02, /* 0x29 */
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x46,
	0x41,
	0x54,
	0x31,
	0x32,
	0x20,
	0x20,
	0x20,
	0x00,
	0x00
};

static kal_uint8 FAT_Str[3] = 
{
	0xf8,
	0xff,
	0xff
};

static kal_uint32 RAM_DISK_MEMORY[0x40000/4];

void FAT_Init(void)
{
	kal_uint32 index;
	kal_uint32 addr = (kal_uint32)RAM_DISK_MEMORY;
	for(index =0;index<0x4000;index++)
		*(volatile kal_uint8 *)(addr+index) = 0;

	/*kal_mem_cpy(dst,src,len)*/
	kal_mem_cpy((kal_uint8 *)(addr+0x1be),(kal_uint8 *)MBR,sizeof(MBR));
	kal_mem_cpy((kal_uint8 *)(addr+0x1fe),(kal_uint8 *)BRSIG,sizeof(BRSIG));
	kal_mem_cpy((kal_uint8 *)(addr+512*2),(kal_uint8 *)PBR,sizeof(PBR));
	kal_mem_cpy((kal_uint8 *)(addr+512*2+0x1fe),(kal_uint8 *)BRSIG,sizeof(BRSIG));
	kal_mem_cpy((kal_uint8 *)(addr+512*3),(kal_uint8 *)FAT_Str,sizeof(FAT_Str));
}


/* RAM Disk Driver APIs */
static kal_bool usbms_read_ram( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_uint32 addr;
	addr = LBA*512;
	addr += (kal_uint32)RAM_DISK_MEMORY;
	kal_mem_cpy(data, (void *)addr, (sec_len*512));
	return KAL_TRUE;
}

static kal_bool usbms_write_ram(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_uint32 addr;
	addr = LBA*512;
	addr += (kal_uint32)RAM_DISK_MEMORY;
	kal_mem_cpy((void *)addr, data, (sec_len*512));
	return KAL_TRUE;
}


static kal_uint8 usbms_checkmedia_exist_ram(void)
{
	return USB_STORAGE_DEV_STATUS_OK;
}

static kal_bool usbms_format_ram(void)
{
	FAT_Init();
	return KAL_TRUE;
}

static kal_bool usbms_prevmedia_removal_ram(kal_bool enable)
{
	return KAL_TRUE;
}

static kal_bool usbms_read_capacity_ram(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
	*max_lba = (32-1);
	*sec_len = 512;
	return KAL_TRUE;
}

/*
static kal_bool usbms_read_formatcapacity_ram(kal_uint32 *no_of_blks, kal_uint32 *blk_len)
{
	*no_of_blks = 32;
	*blk_len = 512;
	return KAL_TRUE;
}
*/

static USB_STORAGE_DEV_TYPE usbms_read_dev_type_ram(void)
{
	return USB_STORAGE_DEV_NONE;
}

USB_DiskDriver_STRUCT USB_RAM_drv = 
{
	usbms_read_ram,
	usbms_write_ram,
	usbms_format_ram,
	usbms_checkmedia_exist_ram,
	usbms_prevmedia_removal_ram,
	usbms_read_capacity_ram,
//	usbms_read_formatcapacity_ram,
	usbms_read_dev_type_ram
};
#endif   /*__USB_RAMDISK__*/
