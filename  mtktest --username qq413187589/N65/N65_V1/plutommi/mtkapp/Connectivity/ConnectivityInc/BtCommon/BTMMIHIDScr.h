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
 * BTMMIHIDScr.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of btmmihidscr.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_HID_SCR_H__
#define __BT_MMI_HID_SCR_H__


/***************************************************************************** 
* Macro
*****************************************************************************/

/***************************************************************************** 
* Definitions
*****************************************************************************/
#define MMI_HID_MAX_CTRL_DATA_LENGHT  9
#define MMI_HID_NUM_OF_CTRL_DATA  (16+4)

#define MMI_HID_MAX_KBD_CMD  3

#define MMI_HID_KEY_REPEAT_PERIOD  100// msec
#define MMI_HID_KEY_DELAY_REPEAT_PERIOD    2// (N+1)*100 msec


/***************************************************************************** 
* Enum
*****************************************************************************/
/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    U8 flag;
    U8 key_cmd[(MMI_HID_MAX_KBD_CMD+1)*ENCODING_LENGTH];

} mmi_bt_hid_scr_cntx_struct;

typedef struct
{
    U16 key_code;
    U16 key_type; 
    U8  ctrl_data[MMI_HID_MAX_CTRL_DATA_LENGHT];
    
} mmi_bt_hid_key_control_data_struct;

/***************************************************************************** 
* External Global Variable
*****************************************************************************/
extern mmi_bt_hid_scr_cntx_struct g_mmi_bt_hid_scr_cntx;
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/* init */
extern void mmi_bt_hid_scr_init(void);
extern void mmi_bt_hid_scr_init_menu_highlight_hdlr(void);

extern void mmi_bt_remote_control_menu_hilight_handler(void);
extern void mmi_bt_remote_control_menu_hint_handler(U16 index);
extern void mmi_bt_hid_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
extern void mmi_bt_hid_entry_conn_confirm_scr(void);
extern void mmi_bt_hid_conn_confirm(void);
extern void mmi_bt_entry_remote_control(void);
extern void mmi_bt_exit_remote_control(void);
extern void mmi_bt_remote_control_hilite_hdlr(S32 idx);

extern void mmi_bt_entry_hid_power_on_confirm(void);
extern void mmi_bt_exit_hid_power_on_confirm(void);
extern void mmi_bt_hid_power_on_confirm_goback(void);
extern void mmi_bt_hid_power_on_confirm_endkey(void);
extern U8 mmi_bt_hid_power_on_confirm_del_cb(void);


extern void mmi_bt_hid_connect_last_dev(void);
extern void mmi_bt_hid_no_last_dev_info(void);
extern void mmi_bt_hid_connect_selected_dev(mmi_bth_bt_addr device_addr);

extern void mmi_bt_entry_hid_app_select(void);
extern void mmi_bt_exit_hid_app_select(void);
extern void mmi_bt_hid_app_select_hilit_hdler(S32 idx);
extern U8 mmi_bt_hid_app_select_del_cb(void);
extern void mmi_bt_entry_disconnect_hid_confirm(void);
extern void mmi_bt_exit_disconnect_hid_confirm(void);
extern void mmi_bt_disconnect_hid_confirm_goback(void);
extern void mmi_bt_disconnect_hid_confirm_endkey(void);
extern void mmi_bt_disconnect_hid(void);

/* desktop */
extern void mmi_bt_hid_desktop_key_up_event_callback(void);
extern void mmi_bt_hid_desktop_key_repeat_event_callback(void);
extern void mmi_bt_entry_hid_desktop(void);
extern void mmi_bt_exit_hid_desktop(void);
/* media player */
extern void mmi_bt_hid_media_player_key_up_event_callback(void);
extern void mmi_bt_hid_media_player_key_repeat_event_callback(void);
extern void mmi_bt_entry_hid_media_player(void);
extern void mmi_bt_exit_hid_media_player(void);
/* presenter */
extern void mmi_bt_hid_presenter_key_up_event_callback(void);
extern void mmi_bt_hid_presenter_key_repeat_event_callback(void);
extern void mmi_bt_entry_hid_presenter(void);
extern void mmi_bt_exit_hid_presenter(void);
/* keyboard */
extern void mmi_bt_entry_hid_keyboard(void);
extern void mmi_bt_exit_hid_keyboard(void);
extern void mmi_bt_hid_keyboard_send_cmd(void);


#endif /* __BT_MMI_HID_SCR_H__ */ /* end of __BT_MMI_HID_SCR_H__ */

