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
 
#ifndef OTG_DRV_PRI_H
#define OTG_DRV_PRI_H

//#define OTG_A_NOT_INSERTION_BASE

/* timer definetions*/

/* Wait for VBUS Rise  */
#define TA_WAIT_VRISE		(100)	/* a_wait_vrise 100 ms, section: 6.6.5.1 */

/* A bus suspend timer before we can switch to B_WAIT_ACON */
#define TB_A_SUSPEND		(7)

/* A-Idle to B-Disconnect */
/* It is necessary for this timer to be more than 750 ms because of a bug in OPT
test 5.4 in which B OPT disconnects after 750 ms instead of 75ms as stated in the
test description */
#define TA_AIDL_BDIS		(800)	/* a_suspend minimum 200 ms, section: 6.6.5.3 */

#define TA_DATA_PLS			(3)	

#define TA_REMOTE_WAKEUP	(30)		/* OPT remote wakeup */

#define TA_BIDL_ADIS		(3)

#define TA_CHECK_VBUS		(535)

/* A-SE0 to B-Reset  */
//#define TB_ASE0_BRST		(6)		/* b_wait_acon 3.125, section: 6.8.2.4 */
#define TB_ASE0_BRST		(7)

/* SE0 Time Before SRP */
#define TB_SE0_SRP			(5)		/* b_idle 2 ms 5.3.2 */

/* Data-Line Pulse Time*/
#define TB_DATA_PLS			(6)		/* b_srp_init 5 to 10 ms, section: 5.3.3 */

/* VBus timer */
#define TB_VBUS_PLS			(10)		/* sufficient time to keep Vbus pulsing asserted */ 

/* Discharge timer */
//#define TB_VBUS_DSCHRG	(7)		
//#define TB_VBUS_DSCHRG		(3)	
#define TB_VBUS_DSCHRG		(50)	

/* SRP Fail Time  */
#define TB_SRP_FAIL			(7000)	/* b_srp_init 5 to 30 sec,section: 6.8.2.2*/

#define TA_ATTATCH_DEBOUNCE		(100)

#define TA_WAIT_BCON				(2000)

#define TA_CHECK_VFALL		1

typedef enum
{
	OTG_TIMER_NONE,
	OTG_TIMER_A_BUS_SUSPEND,
	OTG_TIMER_A_WAIT_VRISE,
	OTG_TIMER_A_WAIT_BCON,
	OTG_TIMER_A_IDLE_BDIS,
	OTG_TIMER_A_DATA_PLS,
	OTG_TIMER_A_BIDLE_ADIS,
	OTG_TIMER_A_REMOTE_WAKEUP,
	OTG_TIMER_A_CHECK_VBUS,
	OTG_TIMER_A_CHECK_VFALL,
	OTG_TIMER_A_ATTATCH_DEBOUNCE,
	//OTG_TIMER_A_WAIT_BCON,
	OTG_TIMER_B_ASE0_BRST,
	OTG_TIMER_B_SE0_SRP,
	OTG_TIMER_B_DATA_PLS,
	OTG_TIMER_B_VBUS_PLS,
	OTG_TIMER_B_VBUS_DSCHG,
	OTG_TIMER_B_SRP_FAIL
}OTG_TIMER_TYPE;

typedef struct
{
	/* state machine*/
	OTG_STATE			otg_state;

	/* host/device down/up handler*/
	otg_intr_handler_ptr	host_up_hdlr;
	otg_intr_handler_ptr	host_down_hdlr;
	otg_intr_handler_ptr	device_up_hdlr;
	otg_intr_handler_ptr	device_down_hdlr;
	
	otg_intr_handler_ptr	a_host_stop_hdlr;
	otg_intr_handler_ptr	a_no_response_hdlr;
	
	/* HNP handler*/
	otg_intr_handler_ptr	b_hnp_fail_hdlr;
	otg_intr_handler_ptr	a_hnp_fail_hdlr;
	otg_intr_handler_ptr	a_hnp_stop_hdlr;

	/* SRP handler*/
	otg_intr_handler_ptr	a_vrise_fail_hdlr;
	otg_intr_handler_ptr	b_srp_fail_hdlr;
	otg_intr_handler_ptr	b_srp_stop_hdlr;
	
	/* status*/
	kal_bool				a_bus_req;				/* For VBUS request */
	kal_bool				a_detect_b_conn;
	kal_bool				a_detect_b_suspend;
	kal_bool				a_detect_b_resume;
	kal_bool				a_detect_b_data_pls;	
	kal_bool				a_detect_b_srp;
	kal_bool				a_suspend_req;
	kal_bool				a_resume_req;
	kal_bool				a_set_b_hnp_enable;

	kal_bool				a_process_hnp;
	kal_bool				a_process_srp;

	kal_bool				b_session_valid;	
	kal_bool				b_suspend_req;				/* For B request for host role or not*/
	kal_bool				b_detect_a_conn;
	kal_bool				b_detect_a_suspend;
	kal_bool				b_detect_a_resume;	
	kal_bool				b_srp_request;
	kal_bool				b_hnp_enable;
	
	kal_bool				b_check_session;
	
	OTG_TIMER_TYPE			timer_type;
	kal_bool				timer_on;
	kal_bool				timer_out;
	kal_uint32				timeout_tick;

	kal_bool				device_up;
	kal_bool				host_up;

	kal_bool				b_processing;

	kal_bool				b_unmask_irq;
	kal_bool				is_ProOTGHISR;

	volatile kal_uint8		otg_intr_status;

	kal_uint8				gpt_handle;    /*GPT handle*/

	OTG_PLUG_TYPE			plug_type;
	kal_uint8				a_plug_gpt_handle;    /*GPT handle for A-plug debounce*/
	kal_bool				a_plug_intr_allow;
}OTG_Drv_Info;


#endif /* OTG_DRV_PRI_H */
 
