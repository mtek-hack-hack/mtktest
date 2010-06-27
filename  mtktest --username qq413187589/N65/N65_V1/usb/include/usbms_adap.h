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
 *    usbms_adap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for usb adaption layer for mass storage definitions
 *
 * Author:
 * -------
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
 
#ifndef USBMS_ADAP_H
#define USBMS_ADAP_H

#include "usb_msdisk.h"
#include "fat_fs.h"

/***********************************************
	function and global variable
************************************************/

#ifdef __USB_RAMDISK__
extern USB_DiskDriver_STRUCT USB_RAM_drv;
void FAT_Init(void);
#endif  

/* translate fd type to usb dev type*/
extern USB_STORAGE_DEV_TYPE USB_Ms_Trans_Fs_Type(FS_DEVICE_TYPE_ENUM type);
extern kal_uint8 USB_Ms_Get_Max_LUN(void);

#ifdef __USB_IN_NORMAL_MODE__
extern void USB_Ms_DeRegister_DiskDriver(kal_uint8 disk_index);
extern void USB_Ms_Change_Register_DiskDriver(kal_uint8 disk_index, USB_DiskDriver_STRUCT *disk_api);
#endif

extern kal_uint8 USB_Ms_Checkmedia_Exist(kal_uint8 LUN);
extern kal_bool USB_Ms_Format(kal_uint8 LUN);
extern kal_bool USB_Ms_Read_Capacity(kal_uint8 LUN, kal_uint32 *max_lba, kal_uint32 *sec_len);
extern kal_bool USB_Ms_Read_FormatCapacity(kal_uint8 LUN, kal_uint32 *max_lba, kal_uint32 *sec_len);
extern kal_bool USB_Ms_Read(kal_uint8 LUN, void *data, kal_uint32 LBA, kal_uint16 sec_len);
extern kal_bool USB_Ms_Write(kal_uint8 LUN, void *data, kal_uint32 LBA, kal_uint16 sec_len);
extern kal_bool USB_Ms_Prevmedia_Removal(kal_uint8 LUN, kal_bool enable);
extern USB_STORAGE_DEV_TYPE USB_Ms_Dev_Type(kal_uint8 LUN);

#endif //USBMS_ADAP_H

