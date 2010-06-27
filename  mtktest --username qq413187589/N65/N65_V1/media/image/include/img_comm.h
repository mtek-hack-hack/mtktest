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
 * img_comm.h
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   This file is intends for M6219 common image driver.
 *
 * Author:
 * -------
 * -------
 * -------
 *
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
 * Rev 1.1   Mar 02 2004 11:14:00   mtk00548
 * Modify the spelling of scenario_id
 *******************************************************************************/



#ifndef __IMG_COMM_H__
#define __IMG_COMM_H__

extern kal_bool img_dma_ibw2_int;

#include "reg_base.h"
#include "drv_comm.h"

#if defined(DRV_IDP_6219_SERIES)

#include "imgproc.h"
#include "imgdma.h"

#define IDP_VR_MAXIMUM_RESZ_WM_SIZE (320*4*3)

typedef struct
{
	kal_uint32 intmem_start_address;			/* internal memory start address for hardware engine buffer */
	kal_uint32 intmem_size;						/* internal memory size for hardware engine buffer */
	kal_uint32 extmem_start_address;			/* external memroy start address for hardware engine buffer */
	kal_uint32 extmem_size;						/* external memory size for hardware engine buffer */

	IMGDMA_DATA_TYPE_ENUM type;				/* RGB565 or RGB888 */
	IMGDMA_DATA_ORDER_ENUM data_order;		/* BGR888 or RGB888 */
	kal_uint32 src_image_address;				/* the source image buffer start address */
	kal_uint32 dest_image_address;			/* the destination image buffer start address */
	kal_uint32 dest_buffer_size;				/* the buffer size of destination image buffer size */
	kal_uint16 src_width;						/* the width of image source */
	kal_uint16 src_height;						/* the height of image source */
	kal_uint16 src_pitch;						/* the pitch width of image source */
	kal_uint16 target_width;					/* the width of target image */
	kal_uint16 target_height;					/* the height of target image */
	kal_uint16 target_pitch;					/* the pitch width of target image  */

	kal_uint16 image_clip_x1;					/* image clip window start x */
	kal_uint16 image_clip_x2;					/* image clip window end x */
	kal_uint16 image_clip_y1;					/* image clip window start y */
	kal_uint16 image_clip_y2;					/* image clip window end x */

	kal_uint8	image_data_format;				/* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
	kal_bool		image_pitch_mode;					/* KAL_TRUE or KAL_FALSE for block mode of decoded image */
	kal_uint16	image_pitch_bytes;				/* pitch width */

}resize_struct;


extern resize_struct image_resize_data;

kal_uint8 config_image_resize_data_path(MMDI_SCENERIO_ID scenario_id, resize_struct *resize_para);
void close_image_resize_data_path(void);
kal_uint8 image_resize_process(resize_struct *resize_para);
kal_uint8 config_pixel_resizer(MMDI_SCENERIO_ID scenario_id);
kal_uint8 config_image_processor(MMDI_SCENERIO_ID scenario_id);
kal_uint8 config_image_dma(MMDI_SCENERIO_ID scenario_id, kal_uint16 tar_width, kal_uint16 tar_height);
kal_uint8 stop_image_dma(MMDI_SCENERIO_ID scenario_id);

#elif (defined(DRV_IDP_6228_SERIES) || defined(DRV_IDP_6238_SERIES))

#include "isp_if.h"
#include "tv_out.h"
#include "jpeg.h"
#include "imgproc.h"
#include "imgdma.h"

#define IDP_VR_MAXIMUM_RESZ_WM_SIZE (320*4*3)

typedef enum {
	 VIDEO_EDITOR_EFFECT_NONE = 0,
    VIDEO_EDITOR_EFFECT_GRAYSCALE,
    VIDEO_EDITOR_EFFECT_SEPIA,
    VIDEO_EDITOR_EFFECT_SEPIAGREEN,
    VIDEO_EDITOR_EFFECT_SEPIABLUE,
    VIDEO_EDITOR_EFFECT_COLORINV,
    VIDEO_EDITOR_EFFECT_GRAYINV
} VIDEO_EDITOR_EFFECT_ENUM;

typedef enum {
	 VIDEO_DECODE_EFFECT_NONE = 0,
    VIDEO_DECODE_EFFECT_GRAYSCALE,
    VIDEO_DECODE_EFFECT_SEPIA,
    VIDEO_DECODE_EFFECT_SEPIAGREEN,
    VIDEO_DECODE_EFFECT_SEPIABLUE,
    VIDEO_DECODE_EFFECT_COLORINV,
    VIDEO_DECODE_EFFECT_GRAYINV
} VIDEO_DECODE_EFFECT_ENUM;

typedef void (*VIDEO_EDITOR_CB_FUNC)(void);
typedef struct
{
    kal_uint32 intmem_start_address;
    kal_uint32 intmem_size;
    kal_uint32 extmem_start_address;
    kal_uint32 extmem_size;

    kal_uint16 image_src_width;     /* image width for CRZ input */
    kal_uint16 image_src_height;    /* image height for CRZ input */
    kal_uint16 preview_width;       /* image width for LCD preview */
    kal_uint16 preview_height;      /* image height for LCD preview */

    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_bool overlay_frame_mode;    /* KAL_TRUE or KAL_FALSE to enable or disable overlay function */
    kal_uint8 overlay_color_depth;
    kal_uint8 overlay_frame_source_key;
    kal_uint16 overlay_frame_width;
    kal_uint16 overlay_frame_height;
    kal_uint32 overlay_frame_buffer_address;

    kal_uint32 frame_buffer_address;    /* image buffer for LCM source buffer */
    kal_uint32 frame_buffer_address1;   /* second image buffer for LCM source buffer */
    kal_uint32 frame_buffer_size;       /* image buffer size of LCM source buffer */
    kal_uint32 frame_buffer_size1;

    kal_bool tv_output;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_rotate_buffer1_address;   /* image buffer1 for TV rotate source buffer */
    kal_uint32 tv_rotate_buffer2_address;   /* image buffer2 for TV rotate source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
} camera_preview_data_path_struct;

typedef struct
{
    kal_uint32 jpeg_file_address[20];
    kal_uint32 jpeg_file_size[20];
} camera_burst_capture_info_struct;

typedef struct
{
    isp_burst_capture_info_struct *jpeg_file_info;
    kal_uint32 intmem_start_address;
    kal_uint32 intmem_size;
    kal_uint32 extmem_start_address;
    kal_uint32 extmem_size;

    kal_uint8 snapshot_number;          /* total number of captured picture in on shot */
    kal_uint16 image_src_width;         /* image width that come from ISP */
    kal_uint16 image_src_height;        /* image width that come from ISP */
    kal_uint16 image_capture_width;     /* captured picture width */
    kal_uint16 image_capture_height;    /* captured picture height */

    kal_bool thumbnail_mode;    /* add thumbnail in JPEG file or not */
    kal_uint16 thumbnail_width;
    kal_uint16 thumbnail_height;

    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE */
    kal_uint8 overlay_color_depth;              /* 1/2/4/8 bpp */
    kal_uint8 overlay_frame_source_key;         /* source key of the overlay frame buffer */
    kal_uint16 overlay_frame_width;             /* overlay frame width */
    kal_uint16 overlay_frame_height;            /* overlay frame height */
    kal_uint32 overlay_frame_buffer_address;    /* bsae address of the overlay frame buffer */

    kal_uint8 image_quality;
    kal_uint8 jpeg_yuv_mode;

    kal_uint32 jpeg_file_start_address1;
    kal_uint32 jpeg_file_buffer_size1;

    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_bool display;           /* output to LCM or TV */
    kal_uint16 display_width;   /* image width for display on LCM or TV */
    kal_uint16 display_height;  /* image height for display on LCM or TV */
    kal_uint32 frame_buffer_address;
    kal_uint32 frame_buffer_size;

    void (*cam_capture_jpeg_cb) (kal_uint8 return_code);
} camera_capture_jpeg_data_path_struct;

typedef struct
{
    kal_uint32 intmem_start_address;
    kal_uint32 intmem_size;
    kal_uint32 extmem_start_address;
    kal_uint32 extmem_size;

    kal_uint16 image_src_width;         /* image width that come from ISP */
    kal_uint16 image_src_height;        /* image width that come from ISP */
    kal_uint16 barcode_image_width;     /* captured picture width */
    kal_uint16 barcode_image_height;    /* captured picture height */

    kal_uint32 barcode_buffer_address;
    kal_uint32 barcode_buffer_size;
    kal_uint8 barcode_image_data_format;

    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_uint16 display_width;           /* image width for display on LCM or TV */
    kal_uint16 display_height;          /* image height for display on LCM or TV */
    kal_uint32 frame_buffer_address;    /* image buffer for LCM source buffer */
    kal_uint32 frame_buffer_address1;   /* second image buffer for LCM source buffer */
    kal_uint32 frame_buffer_size;       /* image buffer size of LCM source buffer */
    kal_uint32 frame_buffer_size1;

    void (*cam_capture_barcode_cb) (kal_uint8 return_code);
} camera_capture_barcode_data_path_struct;

typedef struct
{
    kal_uint32 intmem_start_address;
    kal_uint32 intmem_size;
    kal_uint32 extmem_start_address;
    kal_uint32 extmem_size;

    kal_uint16 image_src_width;
    kal_uint16 image_src_height;
    kal_uint16 image_capture_width;
    kal_uint16 image_capture_height;

    kal_uint8 overlay_frame_mode;
    kal_uint8 overlay_color_depth;
    kal_uint8 overlay_frame_source_key;
    kal_uint16 overlay_frame_width;
    kal_uint16 overlay_frame_height;
    kal_uint32 overlay_frame_buffer_address;

    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_bool image_clip_mode;   /* KAL_TRUE or KAL_FALSE for clipping image */
    kal_uint16 image_clip_x1;   /* clip window start x for clipping captured image */
    kal_uint16 image_clip_x2;   /* clip window end x for clipping captured image */
    kal_uint16 image_clip_y1;   /* clip window start y for clipping captured image */
    kal_uint16 image_clip_y2;   /* clip window end y for clipping captured image */

    kal_uint32 frame_buffer_address;
    kal_uint32 frame_buffer_size;
} camera_capture_mem_data_path_struct;

typedef struct
{
    kal_bool   init_mem;/**/
    kal_uint32 intmem_start_address;
    kal_uint32 intmem_size;
    kal_uint32 extmem_start_address;
    kal_uint32 extmem_size;

    kal_uint16 image_src_width;
    kal_uint16 image_src_height;
    kal_uint16 display_width;
    kal_uint16 display_height;
    kal_uint16 encode_width;
    kal_uint16 encode_height;

    kal_uint8 overlay_frame_mode;
    kal_uint8 overlay_color_depth;
    kal_uint8 overlay_frame_source_key;
    kal_uint16 overlay_frame_width;
    kal_uint16 overlay_frame_height;
    kal_uint32 overlay_frame_buffer_address;

    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_uint32 frame_buffer_address;
    kal_uint32 frame_buffer_size;

    kal_bool tv_output;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;
    void (*video_encode_cb) (kal_uint32 yuv_address);
} video_encode_data_path_struct;

typedef struct
{
	kal_uint32 intmem_start_address;
	kal_uint32 intmem_size;
	kal_uint32 extmem_start_address;
	kal_uint32 extmem_size;
  
    kal_uint16 video_src_width;
    kal_uint16 video_src_height;
    kal_uint16 display_width;
    kal_uint16 display_height;

    kal_bool   pan;   /*when pan is enable, we use resize_width and resize_height as resizer target size*/
    kal_uint16 resize_tar_width;
    kal_uint16 resize_tar_height;


    kal_uint32 video_y_buffer_address;
    kal_uint32 video_u_buffer_address;
    kal_uint32 video_v_buffer_address;

  kal_uint32 mp4_deblk_quant_buf;
    kal_uint8 contrast_level;   /* IPP contrast gain level */
    kal_uint8 brightness_level; /* IPP brightness level */

    kal_bool force_lcd_hw_trigger;
    kal_bool discard_frame_address;

    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_uint32 frame_buffer_address;
    kal_uint32 frame_buffer_size;

    kal_bool display;   /* Enable/Disable to display decoded image on LCM and TV */
    kal_bool drop_lcm_frame;
    kal_bool tv_output; /* Enable/Disable to display decoded image on TV, only take effect when
                           display is KAL_TRUE */
	/*for tvout display size*/
	 kal_uint16 tv_output_display_width;
    kal_uint16 tv_output_display_height;

    kal_uint16 tv_output_width;         /* image width for TV output */
    kal_uint16 tv_output_height;        /* image height for TV output */
    kal_uint16 tv_output_offset_x;      /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;      /* the offset Y from TV output frame buffer to preview image */
    kal_uint16 video_display_offset_x;  /* X offset of displayed image from ROI window */
    kal_uint16 video_display_offset_y;  /* Y offset of displayed image from ROI window */

    VIDEO_DECODE_EFFECT_ENUM effect;
} video_decode_data_path_struct;

/*Video Editor image data path*/
typedef struct
{
    /*Video and Display size*/
    kal_uint16 video_src_width;      /*video encode source file size*/
    kal_uint16 video_src_height;
    kal_uint16 video_tar_width;      /*video encode target file size*/
    kal_uint16 video_tar_height;

    /*source video buffer address*/
    kal_uint32 source_video_y_buffer_address;
    kal_uint32 source_video_u_buffer_address;
    kal_uint32 source_video_v_buffer_address;

    /*target video buffer address*/
    kal_uint32 target_video_y_buffer_address;
    kal_uint32 target_video_u_buffer_address;
    kal_uint32 target_video_v_buffer_address;

    /*IPP*/
    kal_uint8 contrast_level;   /* IPP contrast gain level */
    kal_uint8 brightness_level; /* IPP brightness level */
    IMGPROC_PIXEL_EFFECT_STURCT ipp_para;

    /*LCD display*/
    kal_bool display;   /* Enable/Disable to display decoded image on LCM and TV */
    kal_uint32 overlay_layer;		/* the updated layer */
	 kal_uint32 hw_update_layer;	/* which layer will be applied by hw trigger or direct couple
												for MT6219 only */
	 kal_uint32 lcd_buffer_address;

    /*callback function*/
    VIDEO_EDITOR_CB_FUNC video_cb;
    VIDEO_EDITOR_CB_FUNC effect_cb;
} video_editor_data_path_struct;

/*RGB2YUV420 struct*/
typedef struct
{
   kal_uint32 src_address;	       /* source base address*/
   kal_uint32 src_width;          /* source width*/
   kal_uint32 src_height;         /* source height*/
   IMGDMA_DATA_TYPE_ENUM	type;  /* IBR1_TYPE_RGB888, IBR1_TYPE_RGB565*/
	IMGDMA_DATA_ORDER_ENUM	order; /* IBR1_ORDER_RGB888, IBR1_ORDER_BGR888*/
	kal_uint32  tar_address;       /* target base address*/

} RGB2YUV420_struct;
/*****3g324M****/
typedef enum
{
   IDP_FULLVIDEO_PATH_FULLDUPLEX	 = 0,   
   IDP_FULLVIDEO_PATH_DECODEONLY, 
   IDP_FULLVIDEO_PATH_NONE 
}IDP_FULLVIDEO_PATH_enum;

typedef struct
{
    /*the following are set in the callback*/
    kal_uint16 video_src_width; /*video source size*/
    kal_uint16 video_src_height;
    kal_uint16 display_width;   /*video display size*/ 
    kal_uint16 display_height;    
    
    kal_bool   pan;   /*when pan is enable, we use resize_width and resize_height as resizer target size*/        
    kal_uint16 resize_tar_width;
    kal_uint16 resize_tar_height;        
            
    kal_uint32 video_yuv_buffer_address; /*video yuv addr*/ 
    //kal_uint32 video_u_buffer_address;
    //kal_uint32 video_v_buffer_address;

    /*the following are set in the beginning*/
    kal_uint8  contrast_level;   /* IPP contrast gain level */
    kal_uint8  brightness_level; /* IPP brightness level */

    kal_bool   force_lcd_hw_trigger;  
    
    kal_bool is_update;          /*This variable is to indicate update LCD or not,
                                  if it's false, ignore other parameter.*/  
    
    kal_bool   image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8  image_data_format;     /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;     /* pitch width */

    kal_uint32 frame_buffer_address;  /*output to LCD buffer address*/
    kal_uint32 frame_buffer_size;
    
    kal_uint32 	decode_update_layer;	  /*decode display layer*/
                        
   /*20070508 add, the following for decode only case*/
   
   /*buffer assignment*/
   kal_uint32 	intmem_start_address;	/* internal memory start address for hardware engine buffer */
	kal_uint32 	intmem_size;				/* internal memory size for hardware engine buffer */
	kal_uint32 	extmem_start_address;	/* external memroy start address for hardware engine buffer */
	kal_uint32 	extmem_size;				/* external memory size for hardware engine buffer */
   
   /*lcd update setting*/
   kal_uint8 	lcd_id;						/* MAIN_LCD or SUB_LCD */
	kal_uint16 	lcm_start_x;				/* the start x axis of LCM to be updated*/
	kal_uint16 	lcm_start_y;				/* the start y axis of LCM to be updated*/
	kal_uint16 	lcm_end_x;					/* the end x axis of LCM to be updated*/
	kal_uint16 	lcm_end_y;					/* the end y axis of LCM to be updated*/
	kal_uint16 	roi_offset_x;				/* the ROI window offset x from main window */
	kal_uint16 	roi_offset_y;				/* the ROI window offset y from main window */
	kal_uint32 	update_layer;				/* the updated layer */
	kal_uint32 	hw_update_layer;			/* which layer will be applied by hw trigger or direct couple for MT6219 only */
	kal_uint8 	rotate_value;				/* rotate select for hardware update layer */	      		
	kal_uint32	roi_background_color;	/* set the background color */	
	
	/* TV Setting */
	kal_bool		tv_output;
	kal_uint16	tv_output_width;
	kal_uint16 	tv_output_height;
	kal_uint16	tv_output_offset_x;
	kal_uint16	tv_output_offset_y;
   kal_uint32 	tv_output_buffer1_address;		/* image buffer1 for TV source buffer */
   kal_uint32 	tv_output_buffer2_address;		/* image buffer2 for TV source buffer */
   kal_uint32 	tv_output_buffer_size;			/* image buffer size for TV source buffer */
                        
} fullvideo_video_decode_data_path_struct;
typedef struct
{
	kal_uint32 intmem_start_address;			/* internal memory start address for hardware engine buffer */
	kal_uint32 intmem_size;						/* internal memory size for hardware engine buffer */
	kal_uint32 extmem_start_address;			/* external memroy start address for hardware engine buffer */
	kal_uint32 extmem_size;						/* external memory size for hardware engine buffer */

	IMGDMA_DATA_TYPE_ENUM type;				/* RGB565 or RGB888 */
	IMGDMA_DATA_ORDER_ENUM data_order;		/* BGR888 or RGB888 */
	kal_uint32 src_image_address;				/* the source image buffer start address */
	kal_uint32 dest_image_address;			/* the destination image buffer start address */
	kal_uint32 dest_buffer_size;				/* the buffer size of destination image buffer size */
	kal_uint16 src_width;						/* the width of image source */
	kal_uint16 src_height;						/* the height of image source */
	kal_uint16 src_pitch;						/* the pitch width of image source */
	kal_uint16 target_width;					/* the width of target image */
	kal_uint16 target_height;					/* the height of target image */
	kal_uint16 target_pitch;					/* the pitch width of target image  */

	kal_uint16 image_clip_x1;					/* image clip window start x */
	kal_uint16 image_clip_x2;					/* image clip window end x */
	kal_uint16 image_clip_y1;					/* image clip window start y */
	kal_uint16 image_clip_y2;					/* image clip window end x */

	kal_uint8	image_data_format;				/* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
	kal_bool		image_pitch_mode;					/* KAL_TRUE or KAL_FALSE for block mode of decoded image */
	kal_uint16	image_pitch_bytes;				/* pitch width */
}resize_struct;


/*3g324M*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//__3G_VIDEO_CALL__
extern resize_struct image_resize_data;
kal_uint8 config_image_resize_data_path(MMDI_SCENERIO_ID scenario_id, resize_struct *resize_para);
void close_image_resize_data_path(void);
kal_uint8 image_resize_process(resize_struct *resize_para);

#ifdef __VIDEO_EDITOR__
kal_uint8 config_video_editor(MMDI_SCENERIO_ID scenario_id,
                        video_editor_data_path_struct *video_editor_para,
                        lcd_frame_update_to_mem_struct *lcd_para);
void reconfig_video_editor(MMDI_SCENERIO_ID scenario_id,
                           video_editor_data_path_struct *video_editor_para,
                           lcd_frame_update_to_mem_struct *lcd_para);
void config_video_editor_effect(VIDEO_EDITOR_EFFECT_ENUM effect, kal_uint8 brightness, kal_uint8 contrast);
void close_video_editor_data_path(void);
void start_video_editor_data_path(video_editor_data_path_struct *video_editor_para, kal_bool enable_effect);
void video_editor_data_path2(void);
kal_bool is_video_editor_running(void);
void config_video_decode_effect(VIDEO_DECODE_EFFECT_ENUM effect);
#endif
/*RGB to YUV420*/
extern void stop_RGB2YUV420_data_path(void);
extern void config_RGB2YUV420_data_path(MMDI_SCENERIO_ID scenario_id, RGB2YUV420_struct  *rgb2yuv420_struct);


extern MMDI_SCENERIO_ID current_image_data_path_owner;
extern camera_preview_data_path_struct camera_preview_config_data;
extern camera_capture_jpeg_data_path_struct camera_capture_jpeg_config_data;
extern camera_capture_mem_data_path_struct camera_capture_mem_config_data;
extern video_encode_data_path_struct video_encode_config_data;
extern volatile kal_uint8 current_captured_file_number;

void preview_tv_buffer_rotate_cb(void);


extern volatile kal_bool ibw3_complete_flag;
extern volatile kal_bool wait_ibw3_complete;
extern volatile kal_bool ibw4_complete_flag;
extern volatile kal_bool wait_ibw4_complete;

extern void (*ibw1_cb) (void);
extern void (*ibw2_cb) (void);
extern void (*irt1_cb) (void);
extern void (*vid_enc_w_cb1) (kal_uint32 yuv_address);
extern void (*vid_enc_w_cb) (void);
extern void (*vid_enc_r_cb) (kal_uint8 update_mode);

extern MMDI_SCENERIO_ID current_image_data_path_owner;

kal_bool open_image_data_path(MMDI_SCENERIO_ID scenario_id);
void close_image_data_path(MMDI_SCENERIO_ID scenario_id);
kal_uint8 config_camera_preview_data_path(
                    MMDI_SCENERIO_ID scenario_id,
                    camera_preview_data_path_struct *preview_para);
void reconfig_camera_preview_data_path(
                MMDI_SCENERIO_ID scenario_id,
                camera_preview_data_path_struct *preview_para);
void close_camera_preview_data_path(void);
kal_uint8 config_camera_capture_jpeg_data_path(
                    MMDI_SCENERIO_ID scenario_id,
                    camera_capture_jpeg_data_path_struct *capture_para);
kal_uint8 config_camera_usbvideo_jpeg_data_path(
                    MMDI_SCENERIO_ID scenario_id,
                    camera_capture_jpeg_data_path_struct *capture_para);
void close_camera_capture_jpeg_data_path(void);
kal_uint8 config_camera_capture_barcode_data_path(
                    MMDI_SCENERIO_ID scenario_id,
                    camera_capture_barcode_data_path_struct *capture_para);
void close_camera_capture_barcode_data_path(void);
void get_barcode_image(void);
kal_uint8 config_camera_capture_mem_data_path(
                    MMDI_SCENERIO_ID scenario_id,
                    camera_capture_mem_data_path_struct *capture_para);
void close_camera_capture_mem_data_path(void);
kal_uint8 config_jpeg_encode_data_path(MMDI_SCENERIO_ID scenario_id, jpeg_encode_process_struct *jpeg_para);
void close_jpeg_encode_data_path(void);
kal_uint8 config_jpeg_decode_data_path(MMDI_SCENERIO_ID scenario_id, jpeg_decode_process_struct *jpeg_para);
void close_jpeg_decode_data_path(void);
kal_uint8 config_jpeg_resize_data_path(MMDI_SCENERIO_ID scenario_id, jpeg_file_resize_struct *jpeg_para);
void close_jpeg_resize_data_path(void);
kal_uint8 config_video_encode_data_path(
                    MMDI_SCENERIO_ID scenario_id,
                    video_encode_data_path_struct *video_para);
void reconfig_video_encode_data_path(MMDI_SCENERIO_ID scenario_id, video_encode_data_path_struct *video_para);
void close_video_encode_data_path(void);
kal_uint8 config_video_decode_data_path(
                    MMDI_SCENERIO_ID scenario_id,
                    video_decode_data_path_struct *video_para,
                    lcd_frame_update_struct *lcd_para);
void video_decode_display(video_decode_data_path_struct *video_para);
void close_video_decode_data_path(void);
kal_uint8 config_filter_effect_data_path(ipp_effect_struct *ipp_para);
kal_uint8 config_pixel_effect_data_path(ipp_effect_struct *ipp_para);
kal_bool idp_register_app(MMDI_SCENERIO_ID new_app, MMDI_SCENERIO_ID *old_app);
void close_image_effect_data_path(void);



/* Function in img_comm_jpeg.c */
void config_jpeg_capture_path(camera_capture_jpeg_data_path_struct *capture_para);
void close_jpeg_module(kal_bool encode, kal_bool decode, kal_bool power_down);
void config_jpeg_usbvideo_path(camera_capture_jpeg_data_path_struct *capture_para);
void config_jpeg_encode_path(jpeg_encode_process_struct *jpeg_para);
void config_jpeg_resize_path(jpeg_file_resize_struct *jpeg_para);

extern kal_uint8 video_record_frame;
extern kal_uint8 video_decode_lcd_id;
extern kal_bool video_display;

extern void mpeg4_vid_enc_r_cb(kal_uint8 update_mode);
extern void mpeg4_vid_enc_w_cb(void);

#ifdef MTK_SLEEP_ENABLE
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
extern kal_uint8 image_data_path_sleep_mode_handler;
#endif

#endif /*6228*/



#ifdef __SYNC_LCM_SW_SUPPORT__
extern void (*sync_lcm_update_cb) (void);
extern kal_uint8 preview_frame_update_flag;
extern kal_uint8 video_encode_update_flag;
extern kal_uint8 video_encode_dc_flag;
extern kal_uint8 video_decode_update_flag;
extern kal_uint8 video_decode_direct_couple;
extern kal_uint32 preview_layer_base_address;
extern kal_uint32 preview_buffer1_address;
extern kal_uint32 preview_buffer2_address;
extern kal_uint8 preview_frame_buffer_swap;

void sync_lcm_preview_update_cb(void);
void sync_lcm_video_encode_update_cb(void);
void sync_lcm_video_decode_update_cb(void);
void video_decode_ibw2_cb(void);
#endif

extern void jpeg_decode_cb(void);
extern kal_uint8 current_video_buffer_count;
extern kal_uint32 mpeg4_video_buffer[2];
extern void isp_ibw2_cb(void);
#endif /* __IMG_COMM_H__ */

