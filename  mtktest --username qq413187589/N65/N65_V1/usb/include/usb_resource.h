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
 *    usb_resource.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for usb resource management definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_RESOURCE_H
#define USB_RESOURCE_H

/***********************************************
	implement enum and structure 
************************************************/

/* interface create infomration structrue, use this information to create interface */
typedef struct 
{
	kal_char		*if_name_ptr;
	usb_create_if_func_ptr	if_create_func;
	VOID_FUNC		if_init_func;
#ifdef USB_20_ENABLE
	usb_speed_if_func_ptr	if_speed_func;
#endif
} Usb_IfCreate_Info;


typedef struct
{
	kal_uint8 	device_code; 	/*device class*/
	kal_uint8 	subclass_code;	
	kal_uint8 	protocol_code;
	kal_uint16 	product_code;
	kal_bool	b_registerd;
} Usb_Device_Code;


/***********************************************
	function and global variable
************************************************/

extern void USB_Register_CreateFunc( kal_char* if_name, usb_create_if_func_ptr if_create_func, VOID_FUNC if_init_func, usb_speed_if_func_ptr if_speed_func);
extern void USB_Register_Device_Code(kal_uint8 device_code, kal_uint8 subclass_code, kal_uint8 protocol_code, kal_uint16 product_code);
extern void USB_DeRegister_CreateFunc(void);
extern void USB_DeRegister_Device_Code(void);
extern Usb_Ep_Info* USB_Get_Intr_Ep(kal_uint8 *p_num);
extern Usb_Ep_Info* USB_Get_Bulk_Tx_Ep(kal_uint8 *p_num);
extern Usb_Ep_Info* USB_Get_Bulk_Rx_Ep(kal_uint8 *p_num);
extern Usb_Alternate_Interface_Info* USB_Get_Interface_Alternate_Setting(kal_uint8 p_num, kal_uint8 *p_setting);
extern Usb_Interface_Info* USB_Get_Interface_Number(kal_uint8 *p_num);
extern kal_uint8 USB_Get_String_Number(void *usb_string);
extern Usb_IAD_Dscr* USB_Get_IAD_Number(kal_uint8 *p_num);
extern void USB_Software_Create(void);
extern void USB_Software_Speed_Init(kal_bool b_other_speed);
extern void USB_Software_Init(void);


#endif /* USB_RESOURCE_H */

