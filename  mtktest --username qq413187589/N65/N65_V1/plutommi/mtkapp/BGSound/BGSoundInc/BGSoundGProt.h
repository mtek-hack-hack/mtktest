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
 * BGSoundGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_BGSOUNDGPROT_H
#define _MMI_BGSOUNDGPROT_H

#include "MMI_features.h"

#ifdef __MMI_BG_SOUND_EFFECT__

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#ifndef __UCM_SUPPORT__
extern MMI_BOOL mmi_bgsnd_mo_call_check_last_char(S8 *str_num, S8 char_to_search);
extern BOOL mmi_bgsnd_mo_call_use_effect(S8 *str_number);
extern void mmi_bgsnd_mo_play_sound(void);
extern void mmi_bgsnd_mt_play_sound(void);
extern void mmi_bgsnd_util_stop_play_sound_in_call(void);
extern void mmi_bgsnd_util_stop_play_sound_end_call(void);
extern void mmi_bgsnd_util_switch_speech(MMI_BOOL speech_on);
#endif
extern void mmi_bgsnd_util_delete_end_call_screen(void);
extern void mmi_bgsnd_util_setup_sd_plug_out_hdlr(void);
extern void mmi_bgsnd_util_calling_sd_plug_out_hdlr(void);

extern void mmi_bgsnd_fmgr_from_file_mgr(S8 *path, BOOL is_short);


#ifdef __UCM_SUPPORT__

extern BOOL mmi_bgsnd_common_get_mo_bgs_permit_state(void);
extern U8 mmi_bgsnd_common_get_mtmo_bgs_curr_effect(void);
extern BOOL mmi_bgsnd_common_mtmo_set_highlight_index(U16 highlight_index);
extern U8 mmi_bgsnd_common_mtmo_prepare_effect_list(PS8 subMenuListDataPtrs[], S32 numofptrs, S32 one_buffer_size);
extern U8 mmi_bgsnd_common_mtmo_check_ext_file_format(void);
extern U16 mmi_bgsnd_common_get_uniform_popup_string_id(U8 error_index);
extern void mmi_bgsnd_common_mtmo_play_sound(void);
extern void mmi_bgsnd_util_stop_play_sound(void);
extern void mmi_bgsnd_highlight_call_manage(void);
extern void mmi_bgsnd_highlight_call_setup(void);
extern void mmi_bgsnd_common_mtmo_reset_state(MMI_BOOL allow_play);

typedef enum
{
    BGSND_AUDIO_SUCCESS,//format is right
    BGSND_NO_EFFECT,//no effect
    BGSND_DRM_PROHIBIT,//drm prohibit
    BGSND_AUDIO_OPEN_FILE_FAIL,// open fail
    BGSND_AUDIO_BAD_FORMAT,//bad format
    BGSND_PLAY_FAIL,//other fail
    BGSND_USB_NOT_ALLOWED,
    BGSND_CHECK_NUM
}bgsnd_check_format_result_ucm_enum;

#endif /* __UCM_SUPPORT__ */

#endif /* __MMI_BG_SOUND_EFFECT__ */ 
#endif /* _MMI_BGSOUNDGPROT_H */ 

