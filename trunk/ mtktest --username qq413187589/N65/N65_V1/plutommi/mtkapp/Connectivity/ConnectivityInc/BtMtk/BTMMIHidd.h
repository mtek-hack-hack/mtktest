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
 * BTMMIHidd.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for HID-Device application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_MMI_HIDD_H
#define BT_MMI_HIDD_H


#ifndef BT_MMI_CM_H
#error "BTMMICm.h should be included"
#endif

 
/***************************************************************************** 
* Macro
*****************************************************************************/
#define MMI_BTH_HIDD_LOG_STATE_TRANS(x)                                                        \
{                                                                                             \
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_HIDD_STATE_TRANS, g_mmi_bth_hidd_cntx.state, x);\
}
#define MMI_HID_LOG(x)                                                             \
{                                                                               \
    MMI_TRACE(MMI_TRACE_G7_MISC, x);                                           \
}
#define MMI_HID_LOG1(x,x1)                                                             \
{                                                                               \
    MMI_TRACE(MMI_TRACE_G7_MISC, x,x1);                                           \
}
#define MMI_HID_LOG2(x,x1,x2)                                                             \
{                                                                               \
    MMI_TRACE(MMI_TRACE_G7_MISC, x,x1,x2);                                           \
}

#define MMI_BTH_HIDD_STATE_TRANS(x)  \
{                                   \
    MMI_BTH_HIDD_LOG_STATE_TRANS(x); \
    g_mmi_bth_hidd_cntx.state = x;   \
}

/***************************************************************************** 
* Definations
*****************************************************************************/
#define MMI_BTH_HIDD_MAX_CONNECTION        1
#define BT_HIDD_MAX_DEV_NAME_LEN            80
/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
	MMI_BTH_HIDD_STAT_IDLE,
    MMI_BTH_HIDD_STAT_ACTIVATED,
    MMI_BTH_HIDD_STAT_CONNECTED,

    MMI_BTH_HIDD_STAT_ACTIVATING,
    MMI_BTH_HIDD_STAT_DEACTIVATING,
    MMI_BTH_HIDD_STAT_CONNECTING,
    MMI_BTH_HIDD_STAT_DISCONNECTING,
    MMI_BTH_HIDD_STAT_AUTHORIZING
} mmi_bth_hidd_state_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
	 /*  Connection identification  */
	 MMI_BOOL						active;
	 U32							conn_id;
	 mmi_bth_bt_addr	 			bd_addr;
	 
}mmi_bth_hidd_connect_struct;

typedef struct
{
	 /* hidd state */
	 mmi_bth_hidd_state_enum			state;
	 /* hidd authorise setting */	
	 U8					 				authorise;   

	 mmi_bth_bt_addr	 			last_connected_bd_addr;
	 
	 /* active connections */
    U8 active_conn_num;
    mmi_bth_hidd_connect_struct active_conn_list[MMI_BTH_HIDD_MAX_CONNECTION];
    S8 hidd_dev_name[BT_HIDD_MAX_DEV_NAME_LEN];
 
} mmi_bth_hidd_cntx_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern mmi_bth_hidd_cntx_struct g_mmi_bth_hidd_cntx;

/***************************************************************************** 
* Functions
*****************************************************************************/
extern void mmi_bth_init_hidd_event_handler(void);
extern void mmi_bth_hidd_activate_cnf_hdler(void *msg);
extern void mmi_bth_hidd_deactivate_cnf_hdler(void *msg);
extern void mmi_bth_hidd_connect_cnf_hdler(void *msg);
extern void mmi_bth_hidd_connect_ind_hdler(void *msg);
extern void mmi_bth_hidd_disconnect_cnf_hdler(void *msg);
extern void mmi_bth_hidd_disconnect_ind_hdler(void *msg);
extern MMI_BOOL mmi_bth_hidd_disconnect_all(void);
extern void mmi_bth_hidd_connection_authorize_ind_hdler(void *msg);
extern void mmi_bth_hidd_interrupt_data_cnf_hdler(void *msg);
extern void mmi_bth_hidd_get_dev_name(U8 *name_buf);
extern void mmi_bth_hidd_accept_conn(void);
extern void mmi_bth_hidd_reject_conn(void);
extern U8 mmi_bth_hidd_authorize_confirm_del_cb(void *p);


#endif /* BT_MMI_HIDD_H */ /* end of BT_MMI_HIDD_H */

