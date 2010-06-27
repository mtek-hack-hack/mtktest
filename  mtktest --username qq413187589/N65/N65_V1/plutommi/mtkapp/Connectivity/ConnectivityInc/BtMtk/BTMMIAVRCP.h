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
 * BTMMIAVRCP.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_AVRCP_H__
#define __BT_MMI_AVRCP_H__

//#ifndef _MMI_DATA_TYPE_H
//#error "MMIDataType.h should be included"
//#endif

/***************************************************************************** 
* Macro
*****************************************************************************/

#define  MMI_AVRCP_ASSERT( a ) ASSERT( a )

/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
    MMI_AVRCP_IDLE,         /* Initial state */
    MMI_AVRCP_ACTIVATING,
    MMI_AVRCP_ACTIVATED,
    MMI_AVRCP_DEACTIVATING,
    MMI_AVRCP_CONNECTING,   /* Send connect request to OPC service */
    MMI_AVRCP_CONNECTED,    /* Received successful response from server */
    MMI_AVRCP_DISCONNECTING /* Received failed response from peer */
} mmi_avrcp_state_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    kal_uint8 avrcp_role;
    mmi_avrcp_state_enum avrcp_state;
    bt_avrcp_dev_addr_struct device_addr;
} mmi_avrcp_cntx_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* Context access */

#define MMI_AVRCP_CTX(chnl,x) g_mmi_avrcp_cntx[chnl].x

#define MMI_AVRCP_LOG_STATE(chnl)                                                                   \
{                                                                                                   \
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_AVRCP_STATE_CURRENT, chnl, MMI_AVRCP_CTX(chnl,avrcp_state) );\
}

#define MMI_AVRCP_LOG_STATE_ERR(chnl)                                                             \
{                                                                                                 \
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_AVRCP_STATE_ERROR, chnl, MMI_AVRCP_CTX(chnl,avrcp_state) );\
}

#define MMI_AVRCP_LOG_TRANS_STATE(chnl, x)                                                                \
{                                                                                                         \
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_AVRCP_STATE_TRANSITION, chnl, MMI_AVRCP_CTX(chnl,avrcp_state), x );\
}

#define MMI_AVRCP_STATE_TRANS(chnl,x)       \
{                                           \
    MMI_AVRCP_LOG_TRANS_STATE(chnl,x);      \
    MMI_AVRCP_CTX(chnl,avrcp_state) = x;    \
}

/***************************************************************************** 
* Functions
*****************************************************************************/
/* */

extern void mmi_bt_avrcp_init_event_handler(void);

extern void mmi_bt_avrcp_activate_cnf_hdlr(void *msg);
extern void mmi_bt_avrcp_deactivate_cnf_hdlr(void *msg);
extern void mmi_bt_avrcp_connect_cnf_hdlr(void *msg);
extern void mmi_bt_avrcp_connect_ind_hdlr(void *msg);
extern void mmi_bt_avrcp_disconnect_cnf_hdlr(void *msg);
extern void mmi_bt_avrcp_disconnect_ind_hdlr(void *msg);
extern void mmi_bt_avrcp_cmd_frame_req(U8 avrcp_chnl, U8 op_code, U8 op_id, U8 key_down);
extern void mmi_bt_avrcp_cmd_frame_cnf_hdlr(void *msg);
extern void mmi_bt_avrcp_cmd_frame_ind_hdlr(void *msg);

extern U16 mmi_bt_avrcp_util_check_cmd_type(U8 c_type, U8 subunit_type, U8 subunit_id, U16 data_len, U8 *frame_data);
extern void mmi_bt_avrcp_auto_release_cmd(void);
#if defined(__MMI_TOUCH_SCREEN__)
extern void mmi_bt_avrcp_frm_sync_touch_calllback(U16 Touch_event);
#endif

#endif /* __BT_MMI_AVRCP_H__ */ 

