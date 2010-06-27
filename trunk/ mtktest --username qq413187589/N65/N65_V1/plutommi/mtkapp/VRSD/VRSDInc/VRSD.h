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
 * VRSD.h
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
#ifndef _MMI_VRSD_H
#define _MMI_VRSD_H

/* if some header should be include before this one */
//#ifndef _NVRAM_USER_DEFS_H
//#error "nvram_user_defs.h should be included before header.h"
//#endif

/* 
 * Define
 */
#define MMI_VRSD_MAX_TAG   20
#define MMI_VRSD_PLAY_TONE_DELAY_TIME  500
#define MMI_VRSD_DIAL_OUT_TIME 3000
#define MMI_VRSD_PLAY_TAG_DELAY  500

/* 
 * Typedef 
 */
typedef enum
{
    MMI_VRSD_GROUP_NONE,
    MMI_VRSD_GROUP_ALL = 1
} vrsd_group_id_enum;

typedef enum
{
    MMI_VRSD_APP_ALL,
#if defined(__MMI_VRSD_DIAL__)
    MMI_VRSD_APP_DIAL,
#endif 
#if defined(__MMI_VRSD_REDIAL__)
    MMI_VRSD_APP_REDIAL,
#endif 
#if defined(__MMI_VRSD_PROFILE__)
    MMI_VRSD_APP_PROFILE,
#endif 
#if defined(__MMI_VRSD_AUDPLAYER__)
    MMI_VRSD_APP_AUDPLAYER,
#endif 
#if defined(__MMI_VRSD_SHORTCUT__)
    MMI_VRSD_APP_SHORTCUT,
#endif 
    MMI_VRSD_APP_TOTAL,
    MMI_VRSD_APP_NONE = 0xff
} vrsd_app_id_enum;

typedef enum
{
    MMI_VRSD_STATE_IDLE,
    MMI_VRSD_STATE_TRN_VOICE_IN_FIRST = 1,  /* Must be 1 here */
    MMI_VRSD_STATE_TRN_VOICE_IN_SECOND = 2, /* Must be 2 here */
    MMI_VRSD_STATE_RCG_VOICE_IN
} vrsd_engine_state_enum;

typedef enum
{
    MMI_VRSD_TRN_FAIL,
    MMI_VRSD_TRN_SUCCESS
} vrsd_result_enum;

typedef struct
{
    U16 appref_id;
    U8 app_id;
    U8 dummy;
} vrsd_tag_struct;

typedef struct
{
    void (*trn_callback) (U8);                      /* train callback function */
    void (*rcg_callback[MMI_VRSD_APP_TOTAL]) (U16); /* train callback function */
    void (*play_callback) (void);
    U32 session_id;                                 /* VR engine session id */
    U16 vrtag_id;                                   /* Voice tag id */
    U16 appref_id;                                  /* Application reference index */
    U8 app_id;                                      /* Application id */
    U8 rcg_enable;                                  /* Is recognition enable */
    U8 vrstage;                                     /* VR engine stage */
    U8 vrtag_sync;                                  /* Is voice tag sync with MED */
    U8 user_abort;                                  /* Is user abort receive voice */
} vrsd_context_struct;

/* 
 * Extern Global Variable
 */
extern vrsd_context_struct g_vrsd_cntx;

/* 
 * Extern Global Function
 */
extern U32 mmi_vrsd_get_prompt_tone_size(void);

#define MMI_VRSD_INIT
extern void mmi_vrsd_init(void);
extern void mmi_vrsd_init_highlight_handler(void);

#define MMI_VRSD_MAIN_MENU
extern void mmi_vrsd_highlight_main_menu(void);
extern void mmi_vrsd_main_menu_pre_entry(void);
extern void mmi_vrsd_entry_main_menu(void);
extern void mmi_vrsd_exit_main_menu(void);
extern void mmi_vrsd_main_menu_highlight_hdlr(S32 hiliteid);

#define MMI_VRSD_RCG_ENABLE
extern void mmi_vrsd_highlight_rcg_enable(void);
extern void mmi_vrsd_hint_rcg_enable(U16 index);
extern void mmi_vrsd_rcg_enable_switch(void);

#define MMI_VRSD_TRAIN
extern void mmi_vrsd_train_init(U8 app_id, U16 appref_id, void (*trn_callback) (U8));
extern void mmi_vrsd_train_result_ind(mdi_result result);
extern void mmi_vrsd_train_success(void);

#define MMI_VRSD_RCG
extern void mmi_vrsd_rcg_pre_entry(void);
extern void mmi_vrsd_rcg_init(void);
extern void mmi_vrsd_rcg_result_ind(mdi_result result);

#define MMI_VRSD_RECEIVE_VOICE
extern void mmi_vrsd_entry_recv_voice(void);
extern void mmi_vrsd_exit_recv_voice(void);
extern void mmi_vrsd_recv_voice_abort(void);
extern void mmi_vrsd_recv_voice_prompt_tone(void);
extern void mmi_vrsd_recv_voice_req(mdi_result event);

#define MMI_VRSD_DELETE_ALL
extern void mmi_vrsd_highlight_delete_all(void);
extern void mmi_vrsd_entry_delete_all(void);
extern void mmi_vrsd_delete_all_highlight_hdlr(S32 hiliteid);
extern void mmi_vrsd_delete_all_confirm(void);

#define MMI_VRSD_STATUS
extern void mmi_vrsd_highlight_status(void);
extern void mmi_vrsd_entry_status(void);
extern void mmi_vrsd_tag_status_print_string(U16 str_id, U16 count, S8 *tag_status);
extern void mmi_vrsd_get_each_tag_count(U16 *count_list);

#define MMI_VRSD_UTILITY
extern void mmi_vrsd_sync_tag_with_db(void);
extern U16 mmi_vrsd_util_get_tag_id(U8 app_id, U16 appref_id);
extern U16 mmi_vrsd_util_get_tag_id_in_list(U8 app_id, U16 appref_id, vrsd_tag_struct *tag_list);
extern void mmi_vrsd_playback_req(U16 tag_id, void (*callback) (void));
extern void mmi_vrsd_playback_finish(mdi_result result);
extern U16 mmi_vrsd_get_total_tag_count(U8 app_id);
extern void mmi_vrsd_error_popup(U16 error_id);
extern void mmi_vrsd_clear_rcg_callback(void);
extern void mmi_vrsd_register_rcg_callback(U8 app_id, void (*rcg_callback) (U16));
extern void mmi_vrsd_get_mapping_index(U16 tag_id, U16 *appref_id, U8 *app_id);
extern void mmi_vrsd_del_tag_req(U16 vrtag_id);
extern void mmi_vrsd_del_all_tag_by_appid(void);
extern U16 mmi_vrsd_get_strid_by_appid(U8 app_id);
extern U16 mmi_vrsd_get_appid_by_menuid(U16 menu_id);

#if defined(__MMI_VRSD_DIAL__)
extern void mmi_vrsddial_init(void);
#endif 

#if defined(__MMI_VRSD_REDIAL__)
extern void mmi_vrsdredial_init(void);
#endif 

#if defined(__MMI_VRSD_PROFILE__)
extern void mmi_vrsdprf_init(void);
#endif 

#if defined(__MMI_VRSD_AUDPLAYER__)
extern void mmi_vrsdaudp_init(void);
#endif 

#if defined(__MMI_VRSD_SHORTCUT__)
extern void mmi_vrsdscut_init(void);
#endif 

#endif /* _MMI_VRSD_H */ /* #ifndef _MMI_VRSD_H */

