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
 *  This file intends for otg hardware related function definitions. Only use for hardware driver.
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
 
#ifndef OTG_DRV_H
#define OTG_DRV_H

typedef enum
{
	OTG_PLUG_B,
	OTG_PLUG_A
} OTG_PLUG_TYPE;


/* interrupt handler type*/
typedef enum
{
	OTG_DRV_HDLR_HOST_UP,
	OTG_DRV_HDLR_HOST_DOWN,
	OTG_DRV_HDLR_DEVICE_UP,
	OTG_DRV_HDLR_DEVICE_DOWN,
	OTG_DRV_HDLR_A_VRISE_FAIL,
	OTG_DRV_HDLR_A_HNP_FAIL,
	OTG_DRV_HDLR_A_HNP_STOP,
	OTG_DRV_HDLR_A_NO_RESPONSE,
	OTG_DRV_HDLR_B_HNP_FAIL,	
	OTG_DRV_HDLR_B_SRP_FAIL,
	OTG_DRV_HDLR_B_SRP_STOP,
	OTG_DRV_HDLR_A_HOST_STOP
}OTG_DRV_HDLR_TYPE;

typedef enum
{
	OTG_STATUS_A_BUS_REQUEST,
	OTG_STATUS_A_DETECT_B_CONN,
	OTG_STATUS_A_DETECT_B_SUSPEND,
	OTG_STATUS_A_DETECT_B_RESUME,
	OTG_STATUS_A_DETECT_B_DATA_PLS,
	OTG_STATUS_A_SUSPEND_REQUEST,
	OTG_STATUS_A_RESUME_REQUEST,
	OTG_STATUS_A_SET_B_HNP_ENABLE,
	OTG_STATUS_B_SESSION_VALID,
	OTG_STATUS_B_SUSPEND_REQUEST,
	OTG_STATUS_B_DETECT_A_CONN,
	OTG_STATUS_B_DETECT_A_SUSPEND,
	OTG_STATUS_B_DETECT_A_RESUME,
	OTG_STATUS_B_SRP_REQUEST,
	OTG_STATUS_B_HNP_ENABLE
}OTG_STATUS_TYPE;

typedef enum
{
	 OTG_STATE_START,
	 OTG_STATE_A_IDLE,
	 OTG_STATE_A_WAIT_VRISE,
	 OTG_STATE_A_WAIT_BCON,
	 OTG_STATE_A_HOST,
	 OTG_STATE_A_SUSPEND,
	 OTG_STATE_A_PERIPHERAL,
	 OTG_STATE_A_WAIT_VFALL,

	 OTG_STATE_B_IDLE,
	 OTG_STATE_B_SRP_INIT,
	 OTG_STATE_B_PERIPHERAL,
	 OTG_STATE_B_WAIT_ACON,
	 OTG_STATE_B_HOST
}OTG_STATE;

/* interrupt handler function type */
typedef void (*otg_intr_handler_ptr)(void);

extern void OTG_Init_Drv_Info(void);
extern void OTG_Register_Drv_Info(OTG_DRV_HDLR_TYPE type, otg_intr_handler_ptr hdlr);
extern void OTG_Drv_Create_ISR(void);
extern void OTG_Drv_Activate_ISR(void);

extern void OTG_Init_Drv(void);
extern OTG_PLUG_TYPE OTG_Get_Plug_Type(void);
extern void OTG_A_Suspend_Req(void);
extern void OTG_A_Resume_Req(void);
extern void OTG_A_Stop_Host(void);
extern void OTG_A_Start_HNP(void);
extern void OTG_B_EnDis_HNP(kal_bool set);
extern void OTG_B_Start_SRP(void);
extern void OTG_B_Stop_Host(void);
extern void OTG_B_Set_Session_Valid(kal_bool set);
extern void OTG_Set_Status(OTG_STATUS_TYPE type, kal_bool set);
extern OTG_STATE OTG_Get_State(void);
extern void OTG_Enable_Device(void);

extern kal_bool  OTG_Process_Exceptions(void);

extern kal_bool OTG_PowerOn_Is_A_Plug(void);
extern void OTG_Init_A_Plug_Detect(void);

#endif /* OTG_DRV_H */

