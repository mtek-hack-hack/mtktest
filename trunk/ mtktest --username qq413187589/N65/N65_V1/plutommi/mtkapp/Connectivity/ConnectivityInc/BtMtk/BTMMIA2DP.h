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
 * BTMMIA2DP.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for BT A2DP application layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_A2DP_H__
#define __BT_MMI_A2DP_H__

//#ifndef _MMI_DATA_TYPE_H
//#error "MMIDataType.h should be included"
//#endif

/***************************************************************************** 
* Macro
*****************************************************************************/

/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
    MMI_A2DP_STATE_IDLE,            /* Initial state */
    MMI_A2DP_STATE_ACTIVATING,
    MMI_A2DP_STATE_ACTIVATED,
    MMI_A2DP_STATE_DEACTIVATING,
    MMI_A2DP_STATE_CONNECTING,      /* Send connect request to OPC service */
    MMI_A2DP_STATE_CONNECTED,       /* Received successful response from server */
    MMI_A2DP_STATE_DISCONNECTING    /* Received failed response from peer */
} mmi_a2dp_state_enum;

typedef enum
{
    MMI_A2DP_REQ_FLAG_NONE,
    MMI_A2DP_REQ_FLAG_APP = 1,
    MMI_A2DP_REQ_FLAG_CM = 2
} mmi_a2dp_req_flag_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    mmi_a2dp_state_enum state;
    U8 conn_req_flag;
    U8 disc_req_flag;
    U16 connect_id;
    mmi_bth_bt_addr bd_addr;
} mmi_a2dp_cntx_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* Context access */
extern mmi_a2dp_cntx_struct g_mmi_a2dp_cntx;

#define MMI_A2DP_LOG_STATE()                                                   \
{                                                                              \
    MMI_TRACE(MMI_TRACE_INFO, MMI_A2DP_STATE_CURRENT, g_mmi_a2dp_cntx.state);\
}

#define MMI_A2DP_LOG_STATE_ERR()                                             \
{                                                                            \
    MMI_TRACE(MMI_TRACE_INFO, MMI_A2DP_STATE_ERROR, g_mmi_a2dp_cntx.state);\
}

#define MMI_A2DP_LOG_TRANS_STATE(x)                                                  \
{                                                                                    \
    MMI_TRACE(MMI_TRACE_INFO, MMI_A2DP_STATE_TRANSITION, g_mmi_a2dp_cntx.state, x);\
}

#define MMI_A2DP_STATE_TRANS(x)  \
{                                \
    MMI_A2DP_LOG_TRANS_STATE(x); \
    g_mmi_a2dp_cntx.state = x;   \
}

/***************************************************************************** 
* Functions
*****************************************************************************/
/* */

extern void mmi_bt_a2dp_init(void);
extern mmi_a2dp_state_enum mmi_bt_a2dp_query_state(void);

extern void mmi_bt_a2dp_activate_req(void);
extern void mmi_bt_a2dp_deactivate_req(void);
extern void mmi_bt_a2dp_connect_req(mmi_bth_bt_addr dev_addr);
extern void mmi_bt_a2dp_connect_req_by_cm(mmi_bth_bt_addr dev_addr);
extern void mmi_bt_a2dp_disconnect_req(mmi_bth_bt_addr dev_addr, U32 connect_id);
extern void mmi_bt_a2dp_disconnect_req_by_cm(mmi_bth_bt_addr dev_addr, U32 connect_id);

extern void mmi_bt_a2dp_activate_cnf_hdlr(void *msg);
extern void mmi_bt_a2dp_deactivate_cnf_hdlr(void *msg);
extern void mmi_bt_a2dp_connect_cnf_hdlr(void *msg);
extern void mmi_bt_a2dp_connect_ind_hdlr(void *msg);
extern void mmi_bt_a2dp_disconnect_cnf_hdlr(void *msg);
extern void mmi_bt_a2dp_disconnect_ind_hdlr(void *msg);

#endif /* __BT_MMI_A2DP_H__ */ /* __BT_MMI_AVRCP_H__ */

