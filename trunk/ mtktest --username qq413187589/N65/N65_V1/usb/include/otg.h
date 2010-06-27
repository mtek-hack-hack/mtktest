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
 *    otg_drv_pri.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
*    This file intends for otg definitions.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef OTG_H
#define OTG_H

#include "otg_if.h"

//#define OTG_SRP_HNP_APP_FIXED
#ifdef OTG_SRP_HNP_APP_FIXED
#define OTG_NORMAL_APP_FIXED
#endif

typedef struct
{
	kal_bool	b_check_srp;	/* If SRP is in progress */
	USB_DEVICE_TYPE hnp_srp_type;	/* This is mainly used for SRP, HNP */
	kal_uint32	*hnp_srp_parameter;
//	kal_uint8	eint_no;
//	kal_uint8	eint_time_delay;
}OTG_Struct;

typedef enum
{
	OTG_HDLR_TASK_INIT_MS,
	OTG_HDLR_TASK_END_MS,
	OTG_HDLR_TASK_INIT_NOMAL_MS,
	OTG_HDLR_TASK_END_NORMAL_MS,
	OTG_HDLR_TASK_MAX
}OTG_HDLR_TASK_TYPE;

typedef struct 
{
	LOCAL_PARA_HDR
	OTG_HDLR_TASK_TYPE type;
	kal_uint32 *parameter;
	kal_bool b_param;
}otg_hdr_ind_struct; 


extern OTG_Struct gUsbOtg;

extern void OTG_Init(otg_intr_handler_ptr hdlr_a_host_stop);
extern void OTG_Start_SRP(void);
extern void OTG_Config_SRP(USB_DEVICE_TYPE type, kal_uint32 *parameter);
extern void OTG_Config_HNP(USB_DEVICE_TYPE type, kal_uint32 *parameter);
extern void OTG_Display_Message(OTG_DISPLAY_MSG_TYPE msg_type);
extern void OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_TYPE type, kal_uint32* parameter, kal_bool b_param);

#endif

