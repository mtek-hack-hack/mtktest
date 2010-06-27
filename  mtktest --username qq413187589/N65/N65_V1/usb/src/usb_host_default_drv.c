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
 *    usb_host_default_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host default class driver
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_comm.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "usb_comm.h"
#include "usb.h"
#include "usbd.h"
#include "otg_drv.h"
#include "otg.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */

#ifdef __OTG_ENABLE__

kal_bool USB_Host_Default_Match(USBD_Desc_Info *p_desc_info, kal_uint8 *p_cfg_num)
{
	*p_cfg_num = 0;
	return KAL_TRUE;
}

void USB_Host_Default_Startup(kal_uint8 cfg_num)
{
	ilm_struct *USB_ilm;
	
	// if A device
	if(OTG_Get_Plug_Type()==OTG_PLUG_A)
	{
		if(USBD_Get_HNP_Support()==KAL_FALSE)
		{
			OTG_A_Stop_Host();
			OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);
		}
		else
		{
			OTG_Display_Message(OTG_DISPLAY_MSG_HNP_PROCESS);

			/* Notify UART owner plug out*/
			DRV_BuildPrimitive(USB_ilm,
							MOD_DRV_HISR,
							MOD_USB,
							MSG_ID_USBD_START_HNP,
							NULL);
			msg_send_ext_queue(USB_ilm);	
		}
	}
	else // if B device
	{
		OTG_B_Stop_Host();
		OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);
	}	
}

void USB_Host_Default_Detach(void)
{
	// for test
	volatile static kal_uint32 detach_count = 0;
	detach_count++;
	//dbg_print("Device Plug out\n");
}

 USBD_ClassDriver_Struct USB_Host_Default_Drv = 
{
	USB_Host_Default_Match,
	USB_Host_Default_Startup,
	USB_Host_Default_Detach
};

#endif
 
