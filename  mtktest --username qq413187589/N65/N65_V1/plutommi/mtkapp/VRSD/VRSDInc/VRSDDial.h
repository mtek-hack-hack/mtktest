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

/*******************************************************************************
 * Filename:
 * ---------
 * VRSDDial.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VRSDDIAL_H
#define _MMI_VRSDDIAL_H

/* if some header should be include before this one */
//#ifndef _NVRAM_USER_DEFS_H
//#error "nvram_user_defs.h should be included before header.h"
//#endif

/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#if defined(__MMI_VRSD_DIAL__)
extern void mmi_vrsddial_init_highlight_handler(void);
extern BOOL mmi_vrsddial_check_sim_change(void);
extern void mmi_vrsddial_highlight_app(void);
extern void mmi_vrsddial_entry_empty_list(void);
extern void mmi_vrsddial_highlight_main_add(void);
extern void mmi_vrsddial_highlight_main_change(void);
extern void mmi_vrsddial_highlight_main_delete(void);
extern void mmi_vrsddial_main_menu_add_only(void);
extern void mmi_vrsddial_main_menu_all_option(void);
extern void mmi_vrsddial_main_menu(void (*entry_ptr) (void), U8 type);
extern void mmi_vrsddial_phb_highlight_main_add(void);
extern void mmi_vrsddial_phb_main_menu_pre_entry(void);
extern void mmi_vrsddial_phb_main_menu_change_delete(void);
extern void mmi_vrsddial_phb_main_menu_add_only(void);
extern void mmi_vrsddial_train_result_callback(U8 result);
extern void mmi_vrsddial_add_tag_from_list(void);
extern void mmi_vrsddial_add_tag(void);
extern void mmi_vrsddial_change_tag(void);
extern void mmi_vrsddial_delete_confirm(void);
extern void mmi_vrsddial_delete_tag_req(void);
extern void mmi_vrsddial_delete_all_tag_in_sim_pre_req(void);
extern void mmi_vrsddial_delete_all_tag_req(U8 storage);
extern void mmi_vrsddial_delete_tag_by_store_index(U16 store_index);
extern void mmi_vrsddial_rcg_callback(U16 appref_id);
extern void mmi_vrsddial_entry_rcg_found(void);
extern void mmi_vrsddial_exit_rcg_found(void);
extern void mmi_vrsddial_rcg_auto_dial(void);
extern void mmi_vrsddial_phb_get_new_highlight(void);
#endif /* defined(__MMI_VRSD_DIAL__) */ 

#endif /* _MMI_VRSDDIAL_H */ /* #ifndef _MMI_VRSDDIAL_H */

