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
 *    usb_host_ms_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host mass storage adaptaion layer (file system API)
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
 *============================================================================
 ****************************************************************************/
 
#include "kal_release.h"
#include "app_buff_alloc.h"

#include "usb_comm.h"
#include "usb.h"
#include "usbd.h"
#include "otg_drv.h"
#include "usbms_state.h"
#include "usb_host_ms_drv.h"
#include "usb_host_ms_state.h"
#include "usb_host_ms_adap.h"

#ifdef __OTG_ENABLE__

/************************************************************
	Interface with File system
*************************************************************/

static int  USB_Host_Ms_DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors)
{
   return FS_NO_ERROR;
}

static int  USB_Host_Ms_ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	USB_HOST_MS_RESULT result;
	kal_uint32 start_sec;
	kal_uint32 sec_num;
	kal_uint32 offset_sec_num;
	kal_uint32 left_sec_num;
	kal_uint8* start_addr;
	kal_uint8  active_lun = *((kal_uint8*)DriveData);
	
	if(g_UsbHostMs.mutex_id==0)
		return FS_MSDC_READ_SECTOR_ERROR;
	
	kal_take_mutex(g_UsbHostMs.mutex_id);

	if((g_UsbHostMs.dev_state != USB_HOST_MS_DEV_STATE_READY) ||(g_UsbHostMs.dev_attatch==KAL_FALSE))
	{
		/* device state not ready, may be plug out or query error */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_READ_SECTOR_ERROR;
	}

	if( ((g_UsbHostMs.media_info[active_lun].state!=USB_HOST_MS_MEDIA_STATE_READY)
		&& (g_UsbHostMs.media_info[active_lun].state!=USB_HOST_MS_MEDIA_STATE_WR_PROTECT))
		|| (g_UsbHostMs.media_info[active_lun].sec_size==0))
	{
		/* media state is not ready*/
		/* Note that even media state is READY, but sec_size is zero should be detected as error.
		    It means read capacity action is not ready */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_READ_SECTOR_ERROR;
	}

	/* If the sector number application request is more than one read command can support,
	    divide it into multiple command */
	start_sec = Sector;
	offset_sec_num = 0;
	left_sec_num = Sectors;
	start_addr = (kal_uint8*)Buffer;
	while(left_sec_num>0)
	{
		if(left_sec_num>USB_HOST_MS_RW_MAX_SEC_LEN)
		{
			sec_num = USB_HOST_MS_RW_MAX_SEC_LEN;		
		}
		else
		{
			sec_num = left_sec_num;
		}

		/* This is a block function. It returns when the whole CBW, DATA, CSW complete */
		/* If read error, g_UsbHostMs.b_rw_result will be FALSE */
		result = USB_Host_Ms_Read(active_lun, (kal_uint32)start_sec, (kal_uint16)sec_num, start_addr);
		offset_sec_num+= sec_num;
		start_sec+=sec_num;
		left_sec_num-=sec_num;
		start_addr+=(g_UsbHostMs.media_info[active_lun].sec_size*sec_num);

		if((result !=USB_HOST_MS_RESULT_OK) || (g_UsbHostMs.b_rw_result==KAL_FALSE))
		{
			kal_give_mutex(g_UsbHostMs.mutex_id);
			return FS_MSDC_READ_SECTOR_ERROR;
		}
	}	

	kal_give_mutex(g_UsbHostMs.mutex_id);
	return FS_NO_ERROR;
}


static int  USB_Host_Ms_WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	USB_HOST_MS_RESULT result;
	kal_uint32 start_sec;
	kal_uint32 sec_num;
	kal_uint32 offset_sec_num;
	kal_uint32 left_sec_num;
	kal_uint8* start_addr;
	kal_uint8  active_lun = *((kal_uint8*)DriveData);
	
	if(g_UsbHostMs.mutex_id==0)
		return FS_MSDC_WRITE_SECTOR_ERROR;
		
	kal_take_mutex(g_UsbHostMs.mutex_id);

	if((g_UsbHostMs.dev_state != USB_HOST_MS_DEV_STATE_READY)||(g_UsbHostMs.dev_attatch==KAL_FALSE))
	{
		/* device state not ready, may be plug out or query error */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_WRITE_SECTOR_ERROR;
	}

	if((g_UsbHostMs.media_info[active_lun].state!=USB_HOST_MS_MEDIA_STATE_READY)
		|| (g_UsbHostMs.media_info[active_lun].sec_size==0))
	{
		/* media state is not ready*/
		/* Note that even media state is READY, but sec_size is zero should be detected as error.
		    It means read capacity action is not ready */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_WRITE_SECTOR_ERROR;
	}

	/* If the sector number application request is more than one read command can support,
	    divide it into multiple command */
	start_sec = Sector;
	offset_sec_num = 0;
	left_sec_num = Sectors;
	start_addr = (kal_uint8*)Buffer;
	while(left_sec_num>0)
	{
		if(left_sec_num>USB_HOST_MS_RW_MAX_SEC_LEN)
		{
			sec_num = USB_HOST_MS_RW_MAX_SEC_LEN;
		}
		else
		{
			sec_num = left_sec_num;
		}

		/* This is a block function. It returns when the whole CBW, DATA, CSW complete */
		/* If write error, g_UsbHostMs.b_rw_result will be FALSE */
		result = USB_Host_Ms_Write(active_lun, (kal_uint32)start_sec, (kal_uint16)sec_num, start_addr);
		
		offset_sec_num+= sec_num;
		start_sec+=sec_num;
		left_sec_num-=sec_num;
		start_addr+=(g_UsbHostMs.media_info[active_lun].sec_size*sec_num);

		if((result !=USB_HOST_MS_RESULT_OK) || (g_UsbHostMs.b_rw_result==KAL_FALSE))
		{
			kal_give_mutex(g_UsbHostMs.mutex_id);
			return FS_MSDC_WRITE_SECTOR_ERROR;
		}
	}	


	kal_give_mutex(g_UsbHostMs.mutex_id);
	return FS_NO_ERROR;
	
/*	return FS_MSDC_READ_SECTOR_ERROR;  ?? */
}

static int  USB_Host_Ms_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags)
{	
	kal_uint8  active_lun = *((kal_uint8*)DriveData);
	
	if(g_UsbHostMs.mutex_id==0)
		return FS_MSDC_MOUNT_ERROR;
		
	kal_take_mutex(g_UsbHostMs.mutex_id);

	if((g_UsbHostMs.dev_state != USB_HOST_MS_DEV_STATE_READY)||(g_UsbHostMs.dev_attatch==KAL_FALSE))
	{
		/* device state not ready, may be plug out or query error */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_MOUNT_ERROR;
	}
	
	if(((g_UsbHostMs.media_info[active_lun].state==USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
		||(g_UsbHostMs.media_info[active_lun].state==USB_HOST_MS_MEDIA_STATE_READY))
		&& (g_UsbHostMs.media_info[active_lun].sec_size!=0))
	{
		/* media state is ready*/
		/* Note that even media state is READY, but sec_size is zero should be detected as error.
		    It means read capacity action is not ready */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return g_UsbHostMs.media_info[active_lun].sec_size;
	}

	kal_give_mutex(g_UsbHostMs.mutex_id);
    	return FS_MSDC_MOUNT_ERROR;
}

static int  USB_Host_Ms_MediaChanged(void * DriveData)
{
	kal_uint8  active_lun = *((kal_uint8*)DriveData);
	
	if(g_UsbHostMs.mutex_id==0)
		return FS_MSDC_NOT_PRESENT;
		
	kal_take_mutex(g_UsbHostMs.mutex_id);

	if((g_UsbHostMs.dev_state != USB_HOST_MS_DEV_STATE_READY)||(g_UsbHostMs.dev_attatch==KAL_FALSE))
	{
		/* device state not ready, may be plug out or query error */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_NOT_PRESENT;
	}
	
	if(((g_UsbHostMs.media_info[active_lun].state==USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
		||(g_UsbHostMs.media_info[active_lun].state==USB_HOST_MS_MEDIA_STATE_READY))
		&& (g_UsbHostMs.media_info[active_lun].sec_size!=0))
	{
		/* media state is ready*/
		/* Note that even media state is READY, but sec_size is zero should be detected as error.
		    It means read capacity action is not ready */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_NO_ERROR;
	}	

	if(((g_UsbHostMs.media_info[active_lun].state==USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
		||(g_UsbHostMs.media_info[active_lun].state==USB_HOST_MS_MEDIA_STATE_READY))
		&& (g_UsbHostMs.media_info[active_lun].sec_size==0))
	{
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_PRESNET_NOT_READY;
	}

	kal_give_mutex(g_UsbHostMs.mutex_id);
	return FS_MSDC_NOT_PRESENT;

	/* when should USB report FS_MSDC_PRESNET_NOT_READY ? */    
}

#define USB_MEDIA_DESCRIPTOR		0xF8
static int  USB_Host_Ms_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
	kal_uint8  active_lun = *((kal_uint8*)DriveData);
	
	if(g_UsbHostMs.mutex_id==0)
		return FS_MSDC_NOT_PRESENT;
		
	kal_take_mutex(g_UsbHostMs.mutex_id);

	if((g_UsbHostMs.dev_state != USB_HOST_MS_DEV_STATE_READY)||(g_UsbHostMs.dev_attatch==KAL_FALSE))
	{
		/* device state not ready, may be plug out or query error */
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_NOT_PRESENT;
	}
	
	if(((g_UsbHostMs.media_info[active_lun].state!=USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
		&&(g_UsbHostMs.media_info[active_lun].state!=USB_HOST_MS_MEDIA_STATE_READY))
		|| (g_UsbHostMs.media_info[active_lun].sec_size==0))
	{
		/* media state is not ready*/
		/* Note that even media state is READY, but sec_size is zero should be detected as error.
		    It means read capacity action is not ready */
		kal_give_mutex(g_UsbHostMs.mutex_id);    
		return FS_MSDC_NOT_PRESENT;
	}
	
	kal_mem_set((void*)DiskGeometry, 0, sizeof * DiskGeometry);
	DiskGeometry->Sectors = g_UsbHostMs.media_info[active_lun].sec_num;
	// file system need this descriptor for format operation
	*MediaDescriptor = USB_MEDIA_DESCRIPTOR;
	if(g_UsbHostMs.media_info[active_lun].state==USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
	{
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_WRITE_PROTECTION;		
	}
	
	kal_give_mutex(g_UsbHostMs.mutex_id);
	return FS_NO_ERROR;
}

static int USB_Host_Ms_MessageAck(void * DriveData, int AckType)
{
	kal_uint8  active_lun = *((kal_uint8*)DriveData);
	
	if(g_UsbHostMs.mutex_id==0)
		return FS_MSDC_NOT_PRESENT;
		
	kal_take_mutex(g_UsbHostMs.mutex_id);

	if(AckType==FS_DEV_SLOT_ACK_ENUM)
	{
		g_UsbHostMs.b_sending_change_ilm = KAL_FALSE;
		if(((g_UsbHostMs.media_info[active_lun].state == USB_HOST_MS_MEDIA_STATE_READY)
			||(g_UsbHostMs.media_info[active_lun].state == USB_HOST_MS_MEDIA_STATE_WR_PROTECT))
			&& (g_UsbHostMs.media_info[active_lun].sec_size!=0))
		{
			/* device state ready */
			kal_give_mutex(g_UsbHostMs.mutex_id);
			return FS_NO_ERROR;
		}
		else
		{
			kal_give_mutex(g_UsbHostMs.mutex_id);
			return FS_MSDC_NOT_PRESENT;
		}	
	}
	else if(AckType == FS_DEV_OUT_ACK_ENUM)
	{
		g_UsbHostMs.b_sending_plugout_ilm = KAL_FALSE;		
		/* free device resource and enable device again */
		USB_Host_Ms_Free_Media_Resource();
		USB_Host_Ms_En_Device();
		kal_give_mutex(g_UsbHostMs.mutex_id);
		return FS_MSDC_NOT_PRESENT;
	}
	
	kal_give_mutex(g_UsbHostMs.mutex_id);
	return FS_NO_ERROR;
}

static int  USB_Host_Ms_ShutDown(void * DriveData)
{
   return FS_NO_ERROR;
} 

FS_Driver FS_OTGDrv = {
   USB_Host_Ms_MountDevice,
   USB_Host_Ms_ShutDown,
   USB_Host_Ms_ReadSectors,
   USB_Host_Ms_WriteSectors,
   USB_Host_Ms_MediaChanged,
   USB_Host_Ms_DiscardSectors,
   USB_Host_Ms_GetDiskGeometry,
   NULL,
   NULL,
   NULL,
   NULL,
   NULL,
   NULL,
   USB_Host_Ms_MessageAck
};

#endif /* __OTG_ENABLE__*/
 
