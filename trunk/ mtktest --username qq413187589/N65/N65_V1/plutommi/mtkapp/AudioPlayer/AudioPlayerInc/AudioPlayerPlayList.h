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
*  AudioPlayerPlayList.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player play list
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef __AUDIO_PLAYER_PLAY_LIST_H__
#define __AUDIO_PLAYER_PLAY_LIST_H__

#include "Fat_fs.h"
/*
 * Need to include:
 * (1) MMIDataType.h
 */

#ifdef __MMI_AUDIO_PLAYER__

extern BOOL mmi_audply_check_restorable(UI_string_type ext);
extern void mmi_audply_check_whether_build_cache(
                BOOL *need_to_build_cache, 
                BOOL *seekable,
                UI_string_type ext);

#if defined(MT6223) || defined(MT6223P)
extern BOOL mmi_audply_check_support_A2DP_or_not(UI_string_type ext);
#endif

extern BOOL mmi_audply_apply_picked_file(void);
extern void mmi_audply_regen_and_reload_playlist(BOOL need_regen_list, BOOL need_reload_list);
extern void mmi_audply_split_filename_ext(
                UI_string_type filename,
                UI_string_type filename_without_ext,
                UI_string_type ext);
extern void mmi_audply_extract_filename(UI_string_type filename, UI_string_type fullfilename);
extern void mmi_audply_extract_ext(UI_string_type filename, UI_string_type ext);
extern BOOL mmi_audply_playlist_get_filename(UI_string_type filename, S32 index);
extern U8 mmi_audply_playlist_get_fullfilename(UI_string_type fullfilename, S32 index);
extern void mmi_audply_start_playlist_at(S32 index);
extern S32 mmi_audply_pick_playlist(void);
extern S32 mmi_audply_pick_playlist_next(void);
extern S32 mmi_audply_pick_playlist_prev(void);
extern void mmi_audply_pick_playlist_at(S32 index);

extern UI_string_type mmi_audply_get_present_list_root(void);
extern UI_string_type mmi_audply_get_present_list_file(void);
extern UI_string_type mmi_audply_get_choosen_list_root(UI_character_type folder);
extern UI_string_type mmi_audply_get_choosen_list_file(UI_character_type folder);

extern void mmi_audply_init_playlist(void);
extern BOOL mmi_audply_playlist_remove_index(FS_HANDLE fd, S32 index);
extern U8 mmi_audply_playlist_append_one(S8 *fullfilename);
extern BOOL mmi_audply_playlist_remove_one(S32 index);
extern BOOL mmi_audply_playlist_remove_all(void);
extern U8 mmi_audply_get_preferred_or_available_list(void);
extern BOOL mmi_audply_is_dir_ready(UI_string_type path);
extern BOOL mmi_audply_does_file_exist(UI_string_type path);
extern MMI_BOOL mmi_audply_does_present_list_file_exist(void);
extern BOOL mmi_audply_is_any_file_selected(void);
extern BOOL mmi_audply_is_audio_path(const PS8 path);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#endif /* __AUDIO_PLAYER_PLAY_LIST_H__ */ 

