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
 *    custom_drv_init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the driver init functions
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h" 
#include "fat_fs.h"

#ifdef __USB_ENABLE__
#include "usb_msdisk.h"

extern USB_DiskDriver_STRUCT USB_NOR_drv;
#ifdef NAND_SUPPORT
extern USB_DiskDriver_STRUCT USB_NAND_drv;
#endif
extern USB_DiskDriver_STRUCT USB_SIMPLUS_drv;
#endif   /*__USB_ENABLE__*/

#if defined(__SIM_PLUS__)
extern kal_bool g_usb_ms_simplus_exist;
#endif

extern void GPIO_init(void);
extern void spi_ini(void);
extern void LCD_FunConfig(void);
extern void Alter_init(void);
extern void PWM_initialize(void);


void custom_drv_init(void)
{
	GPIO_init(); /* configure GPIO for debugging */
	spi_ini(); /* For LCD module */
	LCD_FunConfig();
	Alter_init();
#ifndef __L1_STANDALONE__
	PWM_initialize();
#endif
}

void custom_usb_ms_init(void)
{
#ifdef __USB_ENABLE__
	#if ((defined(__MSDC_MS__))||(defined(__MSDC_MSPRO__))||(defined(__MSDC_SD_MMC__)) )
		#ifdef __SIM_PLUS__
	if(g_usb_ms_simplus_exist == KAL_TRUE)
	{
		USB_Ms_Register_DiskDriver(&USB_SIMPLUS_drv);
	}
		#endif
	USB_Ms_Register_DiskDriver(&USB_MSDC_drv);
	#endif

	#ifdef __USB_RAMDISK__
	USB_Ms_Register_DiskDriver(&USB_RAM_drv);
	#endif

	#if (!defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_))
	if(FS_GetDevPartitions(FS_DEVICE_TYPE_NOR) >= 2)
	{
		USB_Ms_Register_DiskDriver(&USB_NOR_drv);
	}
	#endif

	#ifdef NAND_SUPPORT
	if(FS_GetDevPartitions(FS_DEVICE_TYPE_NAND) >= 2)
	{
		USB_Ms_Register_DiskDriver(&USB_NAND_drv);
	}
	else if (FS_GetDevPartitions(FS_DEVICE_TYPE_NAND) == 1)
	{
		#if (!defined(__FS_SYSDRV_ON_NAND__))
		USB_Ms_Register_DiskDriver(&USB_NAND_drv);
		#endif
	}
	#endif
#endif   /*__USB_ENABLE__*/
}

void custom_drv_deinit(void)
{
}


