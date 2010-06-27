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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef SWFLASH_GPROT_H
#define SWFLASH_GPROT_H

#ifdef __MMI_SWFLASH__

#include "filemgr.h"
/* Storage file path */
#define SWFLASH_STORAGE_FILEPATH_PHONE              FMGR_DEFAULT_FOLDER_SWFLASH
#define SWFLASH_STORAGE_FILEPATH_MEMORY_CARD        FMGR_DEFAULT_FOLDER_SWFLASH
#define SWFLASH_SUB_FOLDER_ANIMATION    L"Animation\\"
#define SWFLASH_SUB_FOLDER_GAME    L"Game\\"
#define SWFLASH_SUB_FOLDER_KARAOK    L"KalaOK\\"
#define SWFLASH_SUB_FOLDER_EXTENT    L"Movie\\"
#define SWFLASH_SUB_FOLDER_OTHER    L"Other\\"

#ifdef SWFLASH_CHAOTEX
#define SWFLASH_PLAYER CIM_PLAYERMODE
#define SWFLASH_SCREEN CIM_SCREENMODE
#endif

#ifdef SWFLASH_NEOMTEL
#define SWFLASH_PLAYER VIS_PLAYER
#define SWFLASH_SCREEN VIS_SCREEN
#endif

extern U16 mmi_swflash_get_menuId(void *filename, FMGR_FILE_INFO_STRUCT *info,MMI_BOOL forward,U8 src_app);
extern U32 mmi_swflash_get_category(void *filename, S32 *downloaded,FMGR_FILTER *type);
extern MMI_BOOL mmi_swflash_get_storage_file_path(PS8 filepath);
extern void mmi_swflash_enter_idle_screen_notify(void);
extern void highlight_fmgr_swflash_play(void);
extern void highlight_fmgr_swflash_info(void);
extern void highlight_fmgr_swflash_download(void);
extern void mmi_swflash_filemanager_re_download(S8 *file_path, S8 *filename, S8 * file_ext);
extern void mmi_swflash_set_file_full_path(const S8 *path, const S8 *filename);
extern void mmi_swflash_receive_da_file(
                S32 session_id,
                S32 mime_type,
                S32 mime_subtype,
                S32 action,
                PU16 file_path,
                PS8 url,
                PS8 mime_type_string);
extern void mmi_swflash_option_play_entry_screen(void);
extern void mmi_swflash_option_download(void);
extern void mmi_swflash_option_info_entry_screen(void);
extern void mmi_swflash_init_app(void);
extern void mmi_swflash_card_plug_out_hdlr(void);

/*********** Storage ***********/
typedef enum
{
    MMI_SWFLASH_STORAGE_PHONE = 0,
    MMI_SWFLASH_STORAGE_CARD,
    MMI_SWFLASH_STORAGE_TOTAL
} mmi_swflash_storage_enum;

#endif /* __MMI_SWFLASH__ */ 
#endif /* SWFLASH_GPROT_H */ /* #define SWFLASH_GPROT_H */

