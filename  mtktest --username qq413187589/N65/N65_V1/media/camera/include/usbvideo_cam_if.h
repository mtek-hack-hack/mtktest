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
 *   usbvideo_camera_if.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements web camera module interface function (API)
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
#ifndef _USBVIDEO_CAM_IF_H_
#define _USBVIDEO_CAM_IF_H_

#include "kal_release.h"
#include "drv_features.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "custom_util.h"
#include "jpeg.h"
#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_custom.h"
#include "usbvideo_if.h"

typedef enum
{
	USBVIDEO_CAM_ATTR_NONE=0,
	USBVIDEO_CAM_ATTR_FIX,	
	USBVIDEO_CAM_ATTR_ISP,
	USBVIDEO_CAM_ATTR_SENSOR,
	USBVIDEO_CAM_ATTR_EXT_CAM
}USBVIDEO_CAM_ATTR_PROVIDE_ENUM;

typedef enum
{
	USBVIDEO_CAM_OFF_STATE=0,
	USBVIDEO_CAM_STANDBY_STATE,
	USBVIDEO_CAM_PREVIEW_STATE,
	USBVIDEO_CAM_PREVIEW_CHECK_STATE,	
	USBVIDEO_CAM_CAPTURE_STATE
}USBVIDEO_CAM_OPERATION_STATE_ENUM;

typedef struct
{
	kal_uint32 	intmem_start_address;				/* FROM Media Task, internal memory start address for hardware engine buffer */
	kal_uint32 	intmem_size;							/* FROM Media Task, internal memory size for hardware engine buffer */
	kal_uint32 	extmem_start_address;				/* FROM Media Task, external memroy start address for hardware engine buffer */
	kal_uint32 	extmem_size;							/* FROM Media Task, external memory size for hardware engine buffer */
	kal_uint32  source_width;							/* IMG_DATA_PATH, the image width of resizer */
	kal_uint32	source_height;							/* IMG_DATA_PATH, the image height of resizer */
	kal_uint16 	target_width;							/* IMG_DATA_PATH, the width of target image */
	kal_uint16 	target_height;							/* IMG_DATA_PATH, the height of target image */
	kal_uint32 	target_buffer_start_address;		/* IMG_DATA_PATH, the start address for JPEG encoder */
	kal_uint32 	target_buffer_size;					/* IMG_DATA_PATH, the maximum size of for JPEG encoder */	
	USBVIDEO_VIDEO_SIZE_TYPE target_size_enum;	/* FROM Media Task, the size index of target image */			
	USBVIDEO_COMPRESSION_TYPE target_comp_enum;	/* FROM Media Task, the comp Q index of target image */				
	kal_uint8   image_mirror;							/* FROM Media Task, horizonal/vertical mirror from image sensor */	
	kal_uint8  	image_quality;							/* IMG_DATA_PATH, the image quality after encoded */
	kal_uint8  	jpeg_gray_mode;						/* IMG_DATA_PATH, encode a file as gray mode or not */
	kal_uint8 	banding_freq;				    /* Banding frequency selection */	
    // For SW_JPEG
    kal_uint32 	y_address;	            /* the source start address for SW JPEG encoder or LCD output */
    kal_uint32 	u_address;	            /* the source start address for SW JPEG encoder or LCD output */
    kal_uint32 	v_address;	            /* the source start address for SW JPEG encoder or LCD output */	
    kal_uint32 	y_size;	    
    kal_uint32 	u_size;	    
    kal_uint32 	v_size;	    
    
	void (*usbvideo_encode_cb) (kal_uint8 return_code);	/* call back function to start jpeg encoder */    
	void (*usbvideo_cam_preview_cb) (kal_uint8 ret_code);	/* IMG_DATA_PATH, call back function for camera preview AE/AWB adjustment */
} usbvideo_camera_process_struct;

/******* USB Task - usbvideo, jpeg *******/
/* get parameter functions */
extern const USBVideo_Camera_Param* USBVideo_Get_Camera_Param(void);
extern USBVIDEO_CAM_OPERATION_STATE_ENUM usbvideo_cam_operation_state;
extern kal_uint8 *g_usbvideo_cam_buff;
extern usbvideo_camera_process_struct g_usbvideo_camera_data;

/******** Media Task - usbvideo ********/
/* camera operator */
void usbvideo_camera_init(void);
kal_bool usbvideo_camera_power_on(void);
void usbvideo_camera_power_off(void);
kal_bool usbvideo_camera_preview( usbvideo_camera_process_struct* usbvideo_camera_param );
void exit_usbvideo_camera_preview(void);
kal_bool usbvideo_camera_capture( usbvideo_camera_process_struct* usbvideo_camera_param );
void exit_usbvideo_camera_capture(void);
void usbvideo_camera_frame_ready(void);	/* complete frame(HISR) and get next video buffer */
/* usbvideo set attribute */
void usbvideo_camera_set_attr(USBVideo_Attr_Value *attr);
void usbvideo_camera_effect_background_setting_attr(void);
kal_uint8 usbvideo_camera_effect_setting_attr(USBVideo_Attr_Value *attr);
kal_uint8 usbvideo_camera_effect_getting_attr(USBVideo_Attr_Value *attr);

/******** Driver - usbvideo ********/
typedef struct
{
	void (* usbvideo_cmd_mapping)(void);	
   void (*usbvideo_get_attr_value)(USBVideo_Attr_Value *attr);	
   void (* usbvideo_set_attr_value)(USBVideo_Attr_Value *attr);
} usbvideo_sensor_func_struct;

/* usbvideo attribute - USBVIDEO_ATTRIBUTE_TYPE */
#define	ATTR_PU_START			(0x81)
#define	GET_ATTR_CT_IDX(a)	(a-0)
#define	GET_ATTR_PU_IDX(a)	(a-ATTR_PU_START)

typedef struct {
	kal_uint32		min;
	kal_uint32		max;
	kal_uint32		res;
	kal_uint32		def;
} attr_info_struct;

typedef struct {
   attr_info_struct	attr_info[USBVIDEO_ATTRIBUTE_PU_MAX-ATTR_PU_START];
} usbvideo_attr_struct;

extern kal_uint8 usbvideo_cam_command_CT_map[];
extern kal_uint8 usbvideo_cam_command_PU_map[];
extern kal_uint32 usbvideo_attr_PU_value_list[];
extern kal_uint32 usbvideo_attr_setting_CT_index;
extern kal_uint32 usbvideo_attr_setting_PU_index;

void usbvideo_camera_func_config(void);
/* supported feature list */
extern const USBVideo_Attr_Info ATTR_INFO[];
/* supported video size list */
extern const USBVideo_Video_Size_Info VIDEO_SIZE[];
/* supported still image size list */
extern const USBVideo_Still_Size_Info STILL_SIZE[];
/* supported compression type list*/
extern const USBVideo_Compression_Info STILL_COMPRESSION[];
extern const USBVIDEO_VIDEO_SIZE_TYPE g_default_video_size;
extern const USBVIDEO_STILL_SIZE_TYPE g_default_still_size;
extern const USBVIDEO_COMPRESSION_TYPE g_default_compression;
extern usbvideo_sensor_func_struct *usbvideo_image_sensor_func;

/* For WEBCAM MT6228+TG sync AE/AWB frame ready and jpeg encode interrupt sync */
extern kal_bool usbvideo_camera_fr_flag, usbvideo_camera_jpeg_flag;
#endif // END_OF_WEBCAM_SUPPORT
#endif /* _USBVIDEO_CAM_IF_H_ */
