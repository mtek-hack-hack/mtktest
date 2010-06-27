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
 * BTMMICmGprots.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for external module to use btmmicm related apis
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_CM_GPROTS_H__
#define __BT_MMI_CM_GPROTS_H__

/***************************************************************************** 
* Extern Global Function Pointer
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_bth_activate_cnf_hdler(U32 profile_id);
extern void mmi_bth_deactivate_cnf_hdler(U32 profile_id);
extern void mmi_bth_connect_cnf_hdler(
                MMI_BOOL result,
                U32 lap,
                U8 uap,
                U16 nap,
                U8 *name_p /* utf8 encoding */ ,
                U32 profile_id,
                U32 connection_id);
extern void mmi_bth_multiple_connect_cnf_hdler(
                MMI_BOOL result,
                U32 lap,
                U8 uap,
                U16 nap,
                U8 *name_p /* utf8 encoding */ ,
                U32 profile_id,
                U32 connection_id,
                U8  connecting_index);
extern void mmi_bth_connect_ind_hdler(
                U32 lap,
                U8 uap,
                U16 nap,
                U8 *name_p /* utf8 encoding */ ,
                U32 profile_id,
                U32 connection_id);
extern void mmi_bth_connect_accept_confirm_req_hdler(U32 lap, U8 uap, U16 nap, U8 *name_p /* utf8 encoding */, U32 profile_id);
extern void mmi_bth_connect_accept_confirm_failed_ind_hdler(U32 lap, U8 uap, U16 nap, U32 profile_id);
extern void mmi_bth_disconnect_cnf_hdler(MMI_BOOL result, U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id);
extern void mmi_bth_disconnect_ind_hdler(U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id);
extern void mmi_bth_sco_connect_cnf_hdler(U8 result, U32 connection_id);
extern void mmi_bth_sco_connect_ind_hdler(U32 connection_id);
extern void mmi_bth_sco_disconnect_cnf_hdler(U8 result, U32 connection_id);
extern void mmi_bth_sco_disconnect_ind_hdler(U32 connection_id);
extern void mmi_bth_get_last_hid_dev(mmi_bth_bt_addr *bt_addr_p);
/* for registering pairing function call */
extern void mmi_bth_reg_pairing_permission(U32 profile_id, void *fp);
extern void mmi_bth_unreg_pairing_permission(U32 profile_id);

#endif /* __BT_MMI_CM_GPROTS_H__ */

