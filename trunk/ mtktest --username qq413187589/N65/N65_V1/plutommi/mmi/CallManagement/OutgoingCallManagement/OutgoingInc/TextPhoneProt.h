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
 *  TextPhoneProt.h
 *
 * Project:
 * --------
 *  MAUI
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
 *==============================================================================
 *******************************************************************************/
#ifndef __MMI_UCM__

#ifndef _TEXT_PHONE_PROT_H
#define _TEXT_PHONE_PROT_H

extern void mmi_init_ctm_call(void);

extern U8 mmi_ctm_get_state(void);
extern void mmi_ctm_set_state(U8 state);
extern void mmi_ctm_reset_buffer(void);

extern void mmi_ctm_open_rsp_hdlr(void *info);
extern void mmi_ctm_close_rsp_hdlr(void *info);
extern void mmi_ctm_connect_rsp_hdlr(void *info);
extern void mmi_ctm_connect_ind_hdlr(void *info);
extern void mmi_ctm_send_text_rsp_hdlr(void *info);
extern void mmi_ctm_recv_text_ind_hdlr(void *info);
extern void mmi_ctm_tty_plug_ind_hdlr(void *info);
extern void mmi_ctm_set_default_rsp_hdlr(void *info);
extern void mmi_ctm_get_default_rsp_hdlr(void *info);

extern void mmi_ctm_send_open_req(U8 mode);
extern void mmi_ctm_send_connect_req(void);
extern void mmi_ctm_send_close_req(void);
extern void mmi_ctm_send_text_req(PS8 text, U16 length);
extern void mmi_ctm_send_set_default_req(pBOOL on_off, U8 mode);
extern void mmi_ctm_send_get_default_req(void);

extern void mmi_ctm_switch_tty_status(pBOOL is_present);
extern void mmi_ctm_connect(void);
extern void mmi_ctm_edit_done(void);
extern void mmi_ctm_toggle_mode(void);
extern void mmi_ctm_setting_select(void);

extern void mmi_ctm_set_tty_status(pBOOL is_present);
extern pBOOL mmi_ctm_get_tty_status(void);
extern pBOOL mmi_ctm_is_tty_on(void);
extern pBOOL mmi_ctm_get_mode(void);
extern U8 mmi_ctm_get_setting(void);

extern U16 mmi_skip_unicode_char(PU16 str, U16 len, U16 ch);

extern void highlight_ctm_main(void);
extern void highlight_ctm_mode(void);
extern void highlight_ctm_setting(void);

extern void highlight_ctm_edit_done(void);
extern void highlight_ctm_input_method(void);

extern void hint_ctm_mode(U16 index);

extern void entry_ctm_menu(void);
extern void entry_ctm_setting_selection(void);

extern void entry_ctm_connect_animation(void);
extern void entry_ctm_talking(void);
extern void entry_ctm_editor(void);
extern void entry_ctm_editor_option(void);

#endif /* _TEXT_PHONE_PROT_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "TextPhoneProtEX.h"
#endif /* __MMI_UCM__ */
