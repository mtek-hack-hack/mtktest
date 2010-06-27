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
 *    ext_camera.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the interface and data structure for external camera
 *
 *
 * Author:
 * -------
 * -------
 *
  *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
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
 *    Rev 1.18   Jan 31 2005 14:44:20   mtk00747
 * Merge new feature for CAMERA_MODULE_WITH_LCD after AIT700 integration
 * 1. add ext_cam_set_osd_buffer()
 * 2. add ext_cam_update_backend_lcd_buffer()
 * 3. add src_key_color
 * 4. add force_update
 * 5. modify cam_module_write_lcdfb() input data type
 *
 *    Rev 1.16   Nov 29 2004 18:23:40   mtk00548
 * Add one video_clip_mode declaration.
 * Resolution for 8956: [ExtCam][Bug fix] Fix the bug of external cmaer module video clip function.
 *
 *    Rev 1.15   Nov 27 2004 18:18:22   mtk00747
 * Add new design for camera backend with lcd panel
 *
 *    Rev 1.14   Nov 19 2004 23:28:54   mtk00548
 * Modify the function definition for external camera module engineering mode.
 * Resolution for 7929: [Ext Camera] Add engineering mode for setting register/parameters of external camera module
 *
 *    Rev 1.13   Nov 12 2004 21:24:10   mtk00548
 * Modify the data structure for external camera burst capture function.
 * Resolution for 8481: [Ext Cam][Add Feature] Add Video clip, sticker capture and burst capture functions
 *
 *    Rev 1.12   Oct 29 2004 18:36:28   mtk00548
 * Modify the data structure for external camera module video clip, sticker capture and burst capture functions.
 * Resolution for 7929: [Ext Camera] Add engineering mode for setting register/parameters of external camera module
 * Resolution for 8481: [Ext Cam][Add Feature] Add Video clip, sticker capture and burst capture functions
 *
 *    Rev 1.10   Sep 27 2004 18:42:30   mtk00548
 * Add function declarare for external camera module registers/parameters read/write functions.
 * Resolution for 7929: [Ext Camera] Add engineering mode for setting register/parameters of external camera module
 *
 *    Rev 1.7   Jun 25 2004 19:21:14   mtk00548
 * Add banding filter mapping array declaration.
 * Resolution for 6014: [MODIFY][EXT CAMERA] Modify AIT103 driver codes
 *
 *    Rev 1.6   Jun 25 2004 18:59:02   mtk00548
 * Add clam_shell_state item for preview data structure.
 * Resolution for 6014: [MODIFY][EXT CAMERA] Modify AIT103 driver codes
 *
 *    Rev 1.5   Jun 11 2004 19:16:58   mtk00548
 * 1. Add image rotation enum for external camera preview
 * 2. Add preview rotate and image buffer height item for external camera preview
 * Resolution for 6014: [MODIFY][EXT CAMERA] Modify AIT103 driver codes
 *
 *    Rev 1.0   Mar 02 2004 11:14:34   admin
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __EXT_CAMERA_H__
#define __EXT_CAMERA_H__



#if (defined(CAMERA_MODULE))



#include "kal_release.h"
#include "lcd_if.h"



#define NULL_JPEG_FILE			0xFFFFFFFF
#define EXT_CAMERA_DIGITAL_ZOOM_INTERVAL	10



enum
{
	CAMERA_IMAGE_NORMAL=0,
	CAMERA_IMAGE_ROTATE_90,
	CAMERA_IMAGE_ROTATE_180,
	CAMERA_IMAGE_ROTATE_270,
	CAMERA_IMAGE_MIRROR,
	CAMERA_IMAGE_MIRROR_ROTATE_90,
	CAMERA_IMAGE_MIRROR_ROTATE_180,
	CAMERA_IMAGE_MIRROR_ROTATE_270
};



enum
{
	CLAM_SHELL_OPEN=0,
	CLAM_SHELL_CLOSE
};



typedef struct
{
	kal_uint32	burst_capture_file_size[20];
	kal_uint32	burst_capture_file_address[20];
}	ext_camera_burst_struct;



typedef struct
{
	kal_uint8	lcd_id;					/* which lcd will be updated (MAIN_LCD or SUB_LCD) */
	kal_uint16 	lcm_start_x;			/* the start x axis of LCM to be updated*/
	kal_uint16	lcm_start_y;			/* the start y axis of LCM to be updated*/
	kal_uint16 	lcm_end_x;				/* the end x axis of LCM to be updated*/
	kal_uint16 	lcm_end_y;				/* the end y axis of LCM to be updated*/
	kal_uint16 	dest_block_width;		/* x pitch of block write operation */
	kal_uint32  src_key_color;			/* transparent color */
	kal_uint32 	dest_buffer_address;	/* the start address of desination buffer for LCD memory write out */
	kal_uint32 	dest_buffer_size;		/* desination buffer size */
	kal_uint8	force_update;			/* force backend update LCD */
}	ext_camera_osd_para_struct;



typedef struct
{
	ext_camera_burst_struct	*burst_capture_ptr;
	kal_uint16	image_width;
	kal_uint16	image_height;
	kal_uint16  buffer_width;
	kal_uint16  buffer_height;
	kal_uint16  preview_offset_x;
	kal_uint16  preview_offset_y;
	kal_uint16	preview_width;
	kal_uint16	preview_height;
	kal_uint32	total_file_size;
	kal_uint32  src_key_color;
	kal_uint8	captured_picture;
	kal_uint8   snapshot_number;
	kal_uint8	white_balance_mode1;
	kal_uint8	ev_value;
	kal_uint8	gamma_table;
	kal_uint8	zoom_factor;
	kal_uint8 	image_effect1;
	kal_uint8 	post_effect;
	kal_uint8 	sticker_capture;
	kal_uint8	lcd_id;
	kal_uint8	frame_rate;
	kal_uint8	jpeg_compression_ratio;
	kal_uint8 	preview_rotate;
	kal_uint8 	banding_freq;
	kal_uint8	*jpeg_buffer_ptr;
	kal_uint16	*image_buffer_ptr;
	kal_uint32  image_buffer_size;
	kal_uint8	continue_capture;
	kal_bool    video_rec_mode;
} ext_camera_para_struct;



typedef struct
{
   kal_uint16 *frame_buf_addr;
   kal_uint32 length;
   kal_uint32 read_length;
   kal_uint16 *table_addr;
   kal_uint32 read_count;
   kal_uint8  video_encode_quality;
   kal_uint8  frame_rate;
} ext_camera_retrieve_video_struct;



typedef struct
{
#ifdef CAMERA_MODULE_WITH_LCD
   void (* cam_module_bypass)(void);
#endif
   void (* cam_module_power_on)(void);
	void (* cam_module_cmd_mapping)(void);
   kal_uint8 (* cam_module_reset_status)(void);
   kal_uint8 (* cam_module_preview_ready_check)(void);
   kal_uint32 (* cam_module_capture_ready_check)(void);
   void (* cam_module_power_off)(void);
   void (* cam_module_preview)(ext_camera_para_struct *ext_cam_para);
   void (* exit_cam_module_preview)(void);
   void (* cam_module_capture)(ext_camera_para_struct *ext_cam_para);
   kal_uint32 (* cam_module_jpeg_encode) (ext_camera_para_struct *ext_cam_para, kal_bool back_to_preview);
   void (* cam_module_set_para)(kal_uint8 cmd, kal_uint8 para);
   void (* cam_module_write_para)(kal_uint16 cmd, kal_uint16 para);
   kal_uint16 (* cam_module_read_para)(kal_uint16 cmd);
   kal_uint8 (* cam_module_frame_rate)(void);
#ifdef CAMERA_MODULE_WITH_LCD
   void (* cam_module_write_lcdfb)(ext_camera_osd_para_struct *ext_cam_lcd_para);
   void (* cam_module_start_video_encode)(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para);
   void (* cam_module_stop_video_encode)(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para);
   void (* cam_module_pause_video_encode)(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para);
   void (* cam_module_resume_video_encode)(void);
   void (* cam_module_retrieve_video_data)(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para);
#endif
} ext_cam_module_func;



extern ext_cam_module_func *ext_cam_func;
extern ext_camera_para_struct ext_camera_config_data;
extern kal_bool video_clip_mode;

extern kal_uint8 cam_command_map[];
extern kal_uint8 cam_ev_param_map[];
extern kal_uint8 cam_zoom_param_map[];
extern kal_uint8 cam_effect_param_map[];
extern kal_uint8 cam_jpg_qty_param_map[];
extern kal_uint8 cam_wb_param_map[];
extern kal_uint8 cam_banding_param_map[];



void ext_cam_init(void);
void ext_cam_power_on(void);
kal_bool ext_cam_is_ready(void);
kal_bool ext_cam_is_preview_ready(void);
kal_uint32 ext_cam_get_capture_size(void);
kal_bool ext_camera_is_running(void);
void ext_cam_power_off(void);
void ext_cam_start_preview(ext_camera_para_struct *ext_cam_para, lcd_frame_update_struct *lcd_para);
kal_uint32 ext_cam_sticker_capture(ext_camera_para_struct *ext_cam_para, lcd_frame_update_to_mem_struct *lcd_para);
void ext_cam_stop_preview(void);
void ext_cam_capture(ext_camera_para_struct *ext_cam_para);
kal_uint32 ext_cam_video_clip(ext_camera_para_struct *ext_cam_para);
void ext_cam_set_parameter(kal_uint8 cmd, kal_uint8 para);
kal_bool write_ext_camera(kal_uint16 cmd, kal_uint16 para);
kal_bool read_ext_camera(kal_uint16 cmd, kal_uint16 *para);
kal_uint8 ext_cam_get_frame_rate(void);
void ext_cam_set_osd_buffer(kal_uint32 osd_addr, kal_uint32 osd_size);
void ext_cam_update_backend_lcd_buffer(lcd_frame_update_struct *ext_camera_osd_data);
void ext_cam_start_video_encode(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para);
void ext_cam_retrieve_video_data(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para);
void ext_cam_pause_video_encode(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_para);
void ext_cam_resume_video_encode(void);
void ext_cam_stop_video_encode(ext_camera_retrieve_video_struct *ext_camera_retrieve_video_paras);

#endif /* CAMERA_MODULE */

#endif /* __EXT_CAMERA_H__ */
