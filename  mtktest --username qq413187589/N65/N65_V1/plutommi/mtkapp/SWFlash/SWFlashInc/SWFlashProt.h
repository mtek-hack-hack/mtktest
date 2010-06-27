/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * SWFlashProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define prototypes of SW Flash related routines.
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

#ifndef SWFLASH_PROT_H
#define SWFLASH_PROT_H

#ifdef __MMI_SWFLASH__

#define MMI_SWFLASH_TYPE_ANIMATION 0X0001
#define MMI_SWFLASH_TYPE_KALAOK 0X0010
#define MMI_SWFLASH_TYPE_GAME 0X0100
#define MMI_SWFLASH_TYPE_MTV 0X1000
#define MMI_SWFLASH_TYPE_OTHER 0X1111


/* Level 1 */
extern void mmi_swflash_highlight_main(void);
extern void mmi_swflash_entry_screen(void);
extern void mmi_swflash_exit_screen(void);

/* Level 2 */
extern void mmi_swflash_highlight_monternet(void);
extern void mmi_swflash_highlight_list(void);
extern void mmi_swflash_highlight_setting(void);

extern void mmi_swflash_list_content(void);
extern void mmi_swflash_setting_entry_screen(void);
extern void mmi_swflash_setting_exit_screen(void);

extern void mmi_swflash_highlight_option_play(void);
extern void mmi_swflash_highlight_option_info(void);
extern void mmi_swflash_highlight_option_download(void);

extern void mmi_swflash_option_play_exit_screen(void);
extern void mmi_swflash_option_info_exit_screen(void);

extern void mmi_swflash_option_play_play(void);
extern void mmi_swflash_option_play_pause(void);
extern void mmi_swflash_option_play_stop(void);
extern void mmi_swflash_option_play_resume(void);

extern void mmi_swflash_press_inc_volume(void);
extern void mmi_swflash_press_dec_volume(void);
extern MMI_BOOL mmi_swflash_vis_decipher(FS_HANDLE input_handle, const S8 *filename, S32 file_size, U8 *outbuf, U16 *type_info, S32 *outsize);
extern void mmi_swflash_get_fs_info(void);
extern void mmi_swflash_filename_callback(void *fullname, int is_short);

extern MMI_BOOL mmi_swflash_is_card_ready(void);

extern void mmi_swflash_hint_storage(U16 index);
extern void mmi_swflash_hint_datacnt(U16 index);
extern void mmi_swflash_highlight_storage(void);
extern void mmi_swflash_highlight_datacnt(void);
extern void mmi_swflash_setting_storage_entry_screen(void);

extern void mmi_swflash_set_storage_value(void);
extern MMI_BOOL mmi_swflash_get_storage_file_path(PS8 filepath);
MMI_BOOL mmi_swflash_get_current_storage_file_path(PS8 filepath);

extern BOOL mmi_swflash_get_storage_disk_path(PS8 drv_buf);
extern S32 mmi_swflash_create_file_dir(S8 *filepath);

extern void mmi_swflash_load_setting(void);
extern void mmi_swflash_store_setting(void);
extern void mmi_swflash_datacnt_select(void);
extern void mmi_swflash_datacnt_select_callback(U16 nwk_account_id);
extern void mmi_swflash_percentage_bar_entry_screen(void);
extern U16 * mmi_swflash_get_file_full_path(void);
void mmi_swflash_dl_init(void);
extern void mmi_swflash_set_save_file(MMI_BOOL save_on);
extern void mmi_swflash_exit_play(void);
extern void mmi_swflash_start_wap_browser(void);
extern void mmi_swflash_set_next_url(MMI_BOOL flag_on);
#endif /* __MMI_SWFLASH__ */ 
#endif /* SWFLASH_PROT_H */ /* #define SWFLASH_PROT_H */

