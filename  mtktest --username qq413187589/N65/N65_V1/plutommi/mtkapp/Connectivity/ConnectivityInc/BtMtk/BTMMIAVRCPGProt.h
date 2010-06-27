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
 * BTMMIAVRCPGProt.h
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
#ifndef __BT_MMI_AVRCP_GPROT_H__
#define __BT_MMI_AVRCP_GPROT_H__

/***************************************************************************** 
* Macro
*****************************************************************************/

/***************************************************************************** 
* Definations
*****************************************************************************/
/* AVRCP device roles */
#define MMI_AVRCP_TG    0
#define MMI_AVRCP_CT    1

/* AVRCP command control type */
#define MMI_AVRCP_CR_ACCEPT            (0x09)
#define MMI_AVRCP_CR_REJECT            (0x0A)
#define MMI_AVRCP_CR_NOT_IMPLEMENT     (0x08)

/* AVRCP Commands */
#define MMI_AVRCP_POP_SELECT            0x00
#define MMI_AVRCP_POP_UP                0x01
#define MMI_AVRCP_POP_DOWN              0x02
#define MMI_AVRCP_POP_LEFT              0x03
#define MMI_AVRCP_POP_RIGHT             0x04
#define MMI_AVRCP_POP_RIGHT_UP          0x05
#define MMI_AVRCP_POP_RIGHT_DOWN        0x06
#define MMI_AVRCP_POP_LEFT_UP           0x07
#define MMI_AVRCP_POP_LEFT_DOWN         0x08
#define MMI_AVRCP_POP_ROOT_MENU         0x09
#define MMI_AVRCP_POP_SETUP_MENU        0x0A
#define MMI_AVRCP_POP_CONTENTS_MENU     0x0B
#define MMI_AVRCP_POP_FAVORITE_MENU     0x0C
#define MMI_AVRCP_POP_EXIT              0x0D

#define MMI_AVRCP_POP_0                 0x20
#define MMI_AVRCP_POP_1                 0x21
#define MMI_AVRCP_POP_2                 0x22
#define MMI_AVRCP_POP_3                 0x23
#define MMI_AVRCP_POP_4                 0x24
#define MMI_AVRCP_POP_5                 0x25
#define MMI_AVRCP_POP_6                 0x26
#define MMI_AVRCP_POP_7                 0x27
#define MMI_AVRCP_POP_8                 0x28
#define MMI_AVRCP_POP_9                 0x29
#define MMI_AVRCP_POP_DOT               0x2A
#define MMI_AVRCP_POP_ENTER             0x2B
#define MMI_AVRCP_POP_CLEAR             0x2C

#define MMI_AVRCP_POP_CHANNEL_UP        0x30
#define MMI_AVRCP_POP_CHANNEL_DOWN      0x31
#define MMI_AVRCP_POP_PREVIOUS_CHANNEL  0x32
#define MMI_AVRCP_POP_SOUND_SELECT      0x33
#define MMI_AVRCP_POP_INPUT_SELECT      0x34
#define MMI_AVRCP_POP_DISPLAY_INFO      0x35
#define MMI_AVRCP_POP_HELP              0x36
#define MMI_AVRCP_POP_PAGE_UP           0x37
#define MMI_AVRCP_POP_PAGE_DOWN         0x38

#define MMI_AVRCP_POP_POWER             0x40
#define MMI_AVRCP_POP_VOLUME_UP         0x41
#define MMI_AVRCP_POP_VOLUME_DOWN       0x42
#define MMI_AVRCP_POP_MUTE              0x43
#define MMI_AVRCP_POP_PLAY              0x44
#define MMI_AVRCP_POP_STOP              0x45
#define MMI_AVRCP_POP_PAUSE             0x46
#define MMI_AVRCP_POP_RECORD            0x47
#define MMI_AVRCP_POP_REWIND            0x48
#define MMI_AVRCP_POP_FAST_FORWARD      0x49
#define MMI_AVRCP_POP_EJECT             0x4A
#define MMI_AVRCP_POP_FORWARD           0x4B
#define MMI_AVRCP_POP_BACKWARD          0x4C

#define MMI_AVRCP_POP_ANGLE             0x50
#define MMI_AVRCP_POP_SUBPICTURE        0x51

#define MMI_AVRCP_POP_F1                0x71
#define MMI_AVRCP_POP_F2                0x72
#define MMI_AVRCP_POP_F3                0x73
#define MMI_AVRCP_POP_F4                0x74
#define MMI_AVRCP_POP_F5                0x75

#define MMI_AVRCP_POP_VENDOR_UNIQUE     0x7E

#define MMI_AVRCP_POP_RESERVED          0x7F

/***************************************************************************** 
* Enum
*****************************************************************************/

typedef enum
{
    MMI_AVRCP_KEY_DOWN =0,
    MMI_AVRCP_KEY_UP,
    MMI_AVRCP_KEY_LONGPRESS,
    MMI_AVRCP_KEY_REPEAT,
    MMI_AVRCP_KEY_CANCELED,

    MMI_AVRCP_TOTAL_KEY_EVENTS
} mmi_avrcp_key_events;


/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef U8(*AVRCPCmdFuncPtr) (U8 command_type, mmi_avrcp_key_events key_events);
typedef void(*AVRCPCmdCnfPtr) (U16 op_code, U16 command_type, BOOL key_press);

/***************************************************************************** 
* Structure
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/
extern void mmi_bt_avrcp_activate_tg_req(void);
extern void mmi_bt_avrcp_activate_ct_req(void);
extern void mmi_bt_avrcp_activate_req(U8 avrcp_role);

extern void mmi_bt_avrcp_deactivate_tg_req(void);
extern void mmi_bt_avrcp_deactivate_ct_req(void);
extern void mmi_bt_avrcp_deactivate_req(U8 avrcp_chnl);

extern void mmi_bt_avrcp_connect_tg_req(mmi_bth_bt_addr dev_addr);
extern void mmi_bt_avrcp_connect_ct_req(mmi_bth_bt_addr dev_addr);
extern void mmi_bt_avrcp_connect_req(U8 avrcp_chnl, mmi_bth_bt_addr dev_addr);

extern void mmi_bt_avrcp_disconnect_tg_req(mmi_bth_bt_addr dev_addr, U32 connect_id);
extern void mmi_bt_avrcp_disconnect_ct_req(mmi_bth_bt_addr dev_addr, U32 connect_id);
extern void mmi_bt_avrcp_disconnect_req(U8 avrcp_chnl, mmi_bth_bt_addr dev_addr, U32 connect_id);

extern void mmi_bt_avrcp_set_cmd_hdlr(AVRCPCmdFuncPtr callback_func);
extern void mmi_bt_avrcp_clear_cmd_hdlr(AVRCPCmdFuncPtr callback_func);
extern void mmi_bt_avrcp_frm_sync_calllback(BOOL is_blocked);

#ifdef __MMI_AVRCP_TEST__
extern void mmi_bt_avrcp_tst_different_down_cmd(void);
extern void mmi_bt_avrcp_tst_same_down_cmd(void);
extern void mmi_bt_avrcp_tst_only_down_cmd(void);
extern void mmi_bt_avrcp_tst_only_up_cmd(void);
#endif /*__MMI_AVRCP_TEST__*/

extern U16 mmi_bt_avrcp_util_get_cmd_string(U8 command);

#endif /* __BT_MMI_AVRCP_GPROT_H__ */ 

