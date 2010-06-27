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
 *   VdoPlyGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Expose function and variable.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VDOPLYGPROT_H
#define _MMI_VDOPLYGPROT_H

#include "MMI_features.h"
#ifdef __MMI_VIDEO_PLAYER__

/***************************************************************************** 
* Include
*****************************************************************************/
/* headers required by this this VdoPlyGrpot.h interface */
#include "gdi_include.h"
#include "FileMgr.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define VDOPLY_BUFFER_DEPTH         (2) /* RGB565 = 16 bits */
#define VDOPLY_OSD_BUFFER_SIZE      (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*VDOPLY_BUFFER_DEPTH*2)
#define VDOPLY_LAYER_BUFFER_SIZE    (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*VDOPLY_BUFFER_DEPTH)


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_vdoply_init_app(void);
extern void mmi_vdoply_entry_app(void);

/* play video from file manager - will get file manager's selected file */
extern void mmi_vdoply_entry_player_screen(void);
extern void mmi_vdoply_exit_from_fmgr_emptry_folder(void);

/* play video from other app */
extern void mmi_vdoply_entry_player_screen_from_file(PS8 filename, BOOL is_short);
extern void mmi_vdoply_entry_player_screen_from_id(U16 video_id, U16 video_name_id);

/* progressive DL */
extern void mmi_vdoply_entry_player_screen_from_pdl_file(PS8 filename, BOOL is_short);
extern void mmi_vdoply_pdl_da_notify_file(
            	S32	session_id,
            	S32	mime_type,                  
            	S32	mime_subtype,  
            	S32 action,            	
            	U32	filesize,
            	PS8	url,                        
            	PS8	mime_type_string,           
            	U32	content_len,
            	PS8	content,
            	mmi_da_setting_struct *settings);
    
/* streaming */
extern void mmi_vdoply_entry_player_screen_from_rtsp_link(PS8 rtsp_url);
extern void mmi_vdoply_entry_player_screen_from_sdp_file(PS8 sdp_filename, BOOL is_short);
extern void mmi_vdoply_entry_player_screen_from_ram_file(PS8 ram_filename, BOOL is_short);
extern void mmi_vdoply_stream_receive_da_file(
                S32 session_id, 
                S32 mime_type, 
                S32 mime_subtype, 
                S32 action, 
                PU16 file_path, 
                PS8 url, 
                PS8 mime_type_string);
/* link from wap */
extern void mmi_vdoply_send_rtsp_url_req(PS8 rtsp_url);

    
/* storage util */
extern BOOL mmi_vdoply_check_and_restore_valid_drv(void);
extern void mmi_vdoply_get_storage_file_path(PS8 path_buf);
extern S32 mmi_vdoply_create_file_dir(PS8 filepath);
extern U16 mmi_vdoply_get_storage(void);
extern void mmi_vdoply_set_storage(U16 storage);
extern void mmi_vdoply_load_setting(void);
extern void mmi_vdoply_store_setting(void);

/* init */
extern BOOL mmi_vdoply_is_in_app(void);

/* speical check funciont for lcd sleep */
/* when in video player with tvout enable, when lcd sleep, we will force UI timer stay alive */
#ifdef __MMI_TVOUT__
extern MMI_BOOL mmi_vdoply_is_in_play_and_tvout_enable(void);
#endif 

void mmi_vdoply_get_next_snapshot_filename(PS8 file_buf, PS8 file_path);

#endif /* __MMI_VIDEO_PLAYER__ */ 
#endif /* _MMI_VDOPLYGPROT_H */ 

