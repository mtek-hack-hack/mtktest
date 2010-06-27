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
 * BTMMIOppGprots.h
 *
 * Project:
 * --------
 *   MMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MMI_OPP_SUPPORT__

#ifndef __BT_MMI_OPP_GPROTS_H__
#define __BT_MMI_OPP_GPROTS_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 

#ifndef BT_MMI_CM_H
#include "BTMMICm.h"
#endif

/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_bt_opps_sdpdb_register_cfn_handler(void *msg);
extern void mmi_bt_opps_bt_sdpdb_deregister_cfn_handler(void *msg);

extern void mmi_opp_set_recv_files_cnt(U8 cnt);
extern void mmi_bt_opp_snd_abort(void);
extern void mmi_bt_opp_snd_disconnect(void);
extern void mmi_opp_reject_file_recv(void);
extern void mmi_opp_accept_file_recv(void);
extern BOOL mmi_opp_is_sending(void);
extern BOOL mmi_opp_is_aborting(void);
extern void mmi_opp_opc_connection_terminated(U8 cause);
extern void mmi_opp_ops_connection_terminated(U8 cause);
extern U8 mmi_opp_confirm_del_cb(void *p);
extern void mmi_bt_opp_event_hdlr(msg_type msg_id, void* msg);

extern void mmi_bt_opp_init(void);
extern void mmi_bt_opp_deinit(void);
extern U8 mmi_opp_get_recv_files_cnt(void);
extern void mmi_bt_opps_activate(void);
extern void mmi_bt_opps_deactivate(void);
extern void mmi_bt_opps_disconnect_client(mmi_bth_bt_addr bd_addr, U32 g_conn_id);

extern BOOL mmi_opp_is_receiving(void);
extern void mmi_bt_opp_suppress_popup(MMI_BOOL is_true);
extern MMI_BOOL opp_suppress_popup_flag;
extern void mmi_opp_end_key_press_hdler(void);
extern BOOL mmi_opp_disconncting(void);


#endif /* __BT_MMI_OPP_GPROTS_H__ */ 

#endif /* __MMI_OPP_SUPPORT__ */ 

