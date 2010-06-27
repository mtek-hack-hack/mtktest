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
 *  mdi_video.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video related functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)

#ifdef __MTK_TARGET__
   /* 
    * - For PC Simulator and MoDis, do not call media's video functions 
    * - For Target, call media's video functions.
    */
#define MDI_VIDEO_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */ 

#include "stdC.h"
#include "L4Dr1.h"

#include "MMIDataType.h"
#include "fat_fs.h"
#include "lcd_if.h"             /* lcd interface */
#include "gdi_include.h"        /* include data type */
#include "lcd_sw_rnd.h"
#include "gui.h"
#include "QueueGprot.h"         /* message handling */
#include "med_struct.h"
#include "med_api.h"            /* media task */
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_video.h"
#include "QueueGprot.h"         /* message handling */
#include "EventsGprot.h"        /* event hadnling - get message return from camera driver */
#include "gpioInc.h"            /* avoid sleep when using camera */
#include "fat_fs.h"
#include "debuginitdef.h"       /* MMI_ASSERT */
#include "mmi_trc.h"            /* Debug Info */
#include "mdi_include.h"

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#ifdef __MMI_VIDEO_STREAM__
#include "stream_api.h"
#endif

#ifdef __MMI_BT_AUDIO_VIA_SCO__
#include "ProfileGProts.h"
#endif

#if defined(ISP_SUPPORT)
   /* for visual effect */
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
#include "reg_base.h"
#include "IntrCtrl.h"
#include "drv_comm.h"
#include "drvpdn.h"
#include "jpeg.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "fat_fs.h"
#include "resizer.h"
#include "isp_if.h"
#include "imgproc.h"
#include "img_comm.h"
#include "imgdma.h"
#include "Image_effect.h"
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ /* ISP_SUPPORT */
#endif /* defined(ISP_SUPPORT) */ 

#ifdef __DRM_SUPPORT__
#include "Fs_errcode.h"
#include "Drm_gprot.h" 
#endif /* __DRM_SUPPORT__ */ 


/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_VIDEO_DUMMY_TOTAL_TIME  10000
#define MDI_VIDEO_DRM_INVALID_VALUE 0xFFFFFFFF

/***************************************************************************** 
* Typedef
*****************************************************************************/


/***************************************************************************** 
* Local Variable
*****************************************************************************/
mdi_video_context_struct g_mdi_video_cntx;
mdi_video_context_struct *mdi_video_p = &g_mdi_video_cntx;
mdi_video_setting_struct *video_setting_p = &g_mdi_video_cntx.setting;

/* callback function */
void (*mdi_video_rec_save_result_callback)(MDI_RESULT) = NULL;
void (*mdi_video_rec_record_result_callback)(MDI_RESULT) = NULL;
void (*mdi_video_ply_open_file_result_callback)(MDI_RESULT, mdi_video_info_struct *) = NULL;
void (*mdi_video_ply_play_finish_callback)(MDI_RESULT) = NULL;
void (*mdi_video_play_seek_result_callback)(MDI_RESULT) = NULL;

#ifdef __MMI_VIDEO_STREAM__
void (*mdi_video_stream_connect_result_callback)(MDI_RESULT, mdi_video_info_struct *) = NULL;
void (*mdi_video_stream_buffering_result_callback)(MDI_RESULT, mdi_video_info_struct *) = NULL;
void (*mdi_video_stream_play_finish_callback)(MDI_RESULT) = NULL;
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_EDITOR__
void (*mdi_video_edt_encode_merge_result_callback)(MDI_RESULT) = NULL;
#endif 

#ifdef __MMI_VIDEO_TELEPHONY__
void (*mdi_video_tel_codec_event_callback)(mdi_video_tel_codec_event_enum, S32) = NULL;
#endif 


/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mdi_video_rec_save_result_hdlr(void *msg_ptr);
static void mdi_video_rec_record_result_hdlr(void *msg_ptr);
static void mdi_video_ply_play_finish_result_hdlr(void *msgPtr);
static void mdi_video_ply_open_file_result_hdlr(void *msgPtr);
static void mdi_video_ply_non_block_seek_result_hdlr(void *msgPtr);
#ifdef __DRM_SUPPORT__
static void mdi_video_ply_drm_consume_callback(S32 result, S32 id);
#endif 

#ifdef __MMI_VIDEO_STREAM__ 
static void mdi_video_stream_connect_result_hdlr(void *msg_ptr);
static void mdi_video_stream_buffering_result_hdlr(void *msg_ptr);
static void mdi_video_stream_play_result_hdlr(void *msg_ptr);
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_EDITOR__
static void mdi_video_edt_encode_merge_result_hdlr(void *msg_ptr);
#endif

#ifdef __MMI_VIDEO_TELEPHONY__
static void mdi_video_tel_codec_event_ind_hdlr();
#endif 

#ifndef MDI_VIDEO_DRIVER_AVAIALBE
/* drvier not availabe, mdi simulate non-block mechanism */
static void mdi_video_ply_dummy_non_block_seek_result_hdlr(void);
static void mdi_video_ply_dummy_open_file_result_hdlr(void);
static void mdi_video_ply_dummy_save_file_result_hdlr(void);
static void mdi_video_ply_dummy_play_cyclic(void);

#ifdef __MMI_VIDEO_STREAM__ 
static void mdi_video_stream_dummy_connect_result_hdlr(void);
static void mdi_video_stream_dummy_start_buffering_cyclic(void);
static void mdi_video_stream_dummy_play_result_hdlr(void);
static void mdi_video_stream_dummy_play_cyclic(void);
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_PDL__
static void mdi_video_progressive_dummy_loading_cyclic(void);
static void mdi_video_progressive_dummy_open_file_result_hdlr(void);
#endif /* __MMI_VIDEO_PDL__ */

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

/***************************************************************************** 
* Extern Variable
*****************************************************************************/


/****************************************************************************
*
* COMMON                                                               
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mdi_video_message_dispatcher()
 * DESCRIPTION
 *  Message dispatcher of MDI_VIDEO
 * PARAMETERS
 *  ilm_ptr             [IN]    ilm pointer
 * RETURNS
 *  MDI_VIDEO consume the message or not 
 * RETURN VALUE LIST
 *  MMI_TRUE        MDI_VIDEO consume this message
 *  MMI_FALSE       MDI_VIDEO didnt consume this message
 *****************************************************************************/
MMI_BOOL mdi_video_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_p = ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(ilm_p->msg_id)
    {
        case MSG_ID_MEDIA_VID_RECORD_FINISH_IND:
            mdi_video_rec_record_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
            break;
        case MSG_ID_MEDIA_VID_FILE_MERGE_DONE_IND:
            mdi_video_rec_save_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
            break;            
        case MSG_ID_MEDIA_VID_FILE_READY_IND:
            mdi_video_ply_open_file_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
            break;            
        case MSG_ID_MEDIA_VID_PLAY_FINISH_IND:
            mdi_video_ply_play_finish_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
            break;            
        case MSG_ID_MEDIA_VID_SEEK_DONE_IND:
            mdi_video_ply_non_block_seek_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
            break;          
    #ifdef __MMI_VIDEO_STREAM__ 
        case MSG_ID_MEDIA_STREAM_CONNECTED_IND:
            mdi_video_stream_connect_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE; 
            break;            
        case MSG_ID_MEDIA_STREAM_SEEK_IND:
            mdi_video_stream_buffering_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE; 
            break;            
        case MSG_ID_MEDIA_STREAM_PLAY_IND:
            mdi_video_stream_play_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;          
            break;            
    #endif /* __MMI_VIDEO_STREAM__ */
    
        default:
            return MMI_FALSE;

    }

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_enable_mimic_task
 * DESCRIPTION
 *  Mimic task, will only affect next API. Special function for JAVA use only
 *  [Example]
 *  mdi_video_enable_mimic_task(MOD_J2ME);
 *  mdi_video_ply_play(...);
 *  ...
 *  mdi_video_disable_mimic_task();
 *  even the play function is called under MMI task, it will send MOD_J2ME to 
 *  driver, so the driver will send the result message to J2ME
 * PARAMETERS
 *  module_id         [IN]    module id to be mimic
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_enable_mimic_task(module_type module_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mdi_video_cntx.mimic_module_id = module_id;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_disable_mimic_task
 * DESCRIPTION
 *  Disable mimic task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_disable_mimic_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mdi_video_cntx.mimic_module_id = MOD_NIL;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_get_module_id
 * DESCRIPTION
 *  Get module id
 * PARAMETERS
 *  void
 * RETURNS
 *  module id
 *****************************************************************************/
module_type mdi_video_get_module_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (MOD_NIL == g_mdi_video_cntx.mimic_module_id)
    {
    #ifdef MDI_VIDEO_DRIVER_AVAIALBE    	
        return stack_int_get_active_module_id();
    #else 
    	return 1;
    #endif 
    }
    else
    {
        return g_mdi_video_cntx.mimic_module_id;
    }
}




/****************************************************************************
*
* RECORDER                                                                 
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_init
 * DESCRIPTION
 *  Init mdi video recorder
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_power_on
 * DESCRIPTION
 *  power on recorder hw
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_power_on(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_POWER_ON);           

    ret = media_cam_power_up(module_id, 0);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);     
    
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_POWER_ON_FAILED;
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_power_off
 * DESCRIPTION
 *  power off recorder hw
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_power_off(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_POWER_OFF);   

    ret = media_cam_power_down(module_id, 100);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    /* power off alwyas return succeed */
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_preview_start
 * DESCRIPTION
 *  preview start
 * PARAMETERS
 *  preview_layer_handle        [IN]        Layer for preview
 *  blt_layer_flag              [IN]        Blt out layer flag
 *  preview_layer_flag          [IN]        Preview layer flag
 *  is_lcd_udpate               [IN]        Update lcd or not
 *  setting_p                   [IN]        Setting data
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_preview_start(
            gdi_handle preview_layer_handle, 
            U32 blt_layer_flag, 
            U32 preview_layer_flag, 
            MMI_BOOL is_lcd_udpate,
            mdi_video_setting_struct *setting_p)       /* video setting */
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_preview_req_struct preview_data;
    MDI_RESULT ret;
    mdi_blt_para_struct blt_data;
    MMI_BOOL is_tvout = MMI_FALSE;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_PREVIEW_START);   

    /* store video's parameters */
    memcpy(video_setting_p, setting_p, sizeof(mdi_video_setting_struct));

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        g_mdi_video_cntx.tvout_prev_owner = mdi_tvout_get_owner();
        
        /* if tvout is on and has V track */
        mdi_tvout_set_owner(MDI_TV_OWNER_VIDEO);        
        is_tvout = MMI_TRUE;        
    }
    else
    {
        is_tvout = MMI_FALSE;
    }
#endif /* __MMI_TVOUT__ */

    gdi_lcd_get_active(&g_mdi_video_cntx.lcd_handle);

    /* calc blt paramters */
    mdi_calc_blt_para(
        preview_layer_handle, 
        setting_p->lcm_rotate, 
        g_mdi_video_cntx.lcd_handle,  
        is_tvout, 
        &blt_data);

    preview_data.lcd_id = MAIN_LCD;
    preview_data.preview_offset_x = 0;  /* offset from lcd_offset_x, set as 0 */
    preview_data.preview_offset_y = 0;  /* offset from lcd_offset_x, set as 0 */
    preview_data.update_layer = blt_layer_flag;
    preview_data.hw_update_layer = preview_layer_flag;
    
    /* lcd / preview related */
    preview_data.buffer_width = blt_data.display_width;
    preview_data.buffer_height = blt_data.display_height;
    preview_data.image_buffer_size = blt_data.image_buffer_size;
    preview_data.image_buffer_p = (void*)blt_data.image_buffer_p;
    preview_data.preview_width = blt_data.display_width;
    preview_data.preview_height = blt_data.display_height;
    preview_data.lcd_rotate = blt_data.lcd_rotate;
    preview_data.lcd_start_x = blt_data.lcd_start_x;
    preview_data.lcd_start_y = blt_data.lcd_start_y;
    preview_data.lcd_end_x = blt_data.lcd_end_x;
    preview_data.lcd_end_y = blt_data.lcd_end_y;
    preview_data.roi_offset_x = blt_data.roi_offset_x;
    preview_data.roi_offset_y = blt_data.roi_offset_y;    

#if defined(MDI_VIDEO_MT6228_SERIES)
    preview_data.tv_output = blt_data.tv_output;

#ifdef __MMI_TVOUT__
    preview_data.tv_output_width = blt_data.tv_output_width;
    preview_data.tv_output_width = blt_data.tv_output_width;
    preview_data.tv_output_height = blt_data.tv_output_height;
    preview_data.tv_output_offset_x = blt_data.tv_output_offset_x;
    preview_data.tv_output_offset_y = blt_data.tv_output_offset_y;
    preview_data.tv_output_buffer_size = blt_data.tv_output_buffer_size;
    preview_data.tv_output_buffer1_address = (kal_uint32)blt_data.tv_output_buffer1_address;
    preview_data.tv_output_buffer2_address = (kal_uint32)blt_data.tv_output_buffer2_address;
#endif /* __MMI_TVOUT__ */

#endif /* MDI_VIDEO_MT6228_SERIES */


    /* set settings parameters */
    preview_data.WB = video_setting_p->wb;
    preview_data.exposure = video_setting_p->ev;
    preview_data.banding_freq = (U8) video_setting_p->banding;
    preview_data.effect = video_setting_p->effect;
    preview_data.zoom_factor = video_setting_p->zoom;

    /* other para */
    preview_data.brightness = video_setting_p->brightness;
    preview_data.contrast = video_setting_p->contrast;
    preview_data.saturation = video_setting_p->saturation;
    preview_data.hue = video_setting_p->hue;
    preview_data.night_mode = video_setting_p->night;
    preview_data.gamma = 0;
    preview_data.frame_rate = VIDEO_PERVIEW_FRAME_RATE;

    /* lcd */
    preview_data.lcd_update = (kal_bool)is_lcd_udpate;
    preview_data.rotate = video_setting_p->preview_rotate;  
    
#if defined(MDI_VIDEO_MT6228_SERIES)
    preview_data.manual_wb = FALSE;
    preview_data.image_pitch_mode = FALSE; /* do not use this mode */
    preview_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    
    preview_data.overlay_frame_mode = FALSE;
    preview_data.overlay_frame_mode = video_setting_p->overlay_frame_mode;
    preview_data.overlay_color_depth = video_setting_p->overlay_frame_depth;
    preview_data.overlay_frame_source_key = video_setting_p->overlay_frame_source_key;
    preview_data.overlay_frame_width = video_setting_p->overlay_frame_width;
    preview_data.overlay_frame_height = video_setting_p->overlay_frame_height;
    preview_data.overlay_frame_buffer_address = video_setting_p->overlay_frame_buffer_address;
#endif /* MDI_VIDEO_MT6228_SERIES */ 

#ifdef ISP_SUPPORT
    switch (video_setting_p->video_size)
    {
        case MDI_VIDEO_VIDEO_SIZE_SQCIF:
            preview_data.image_width = 128;
            preview_data.image_height = 96;
            break;

        case MDI_VIDEO_VIDEO_SIZE_QQVGA:
            preview_data.image_width = 160;
            preview_data.image_height = 120;
            break;

        case MDI_VIDEO_VIDEO_SIZE_QCIF:
            preview_data.image_width = 176;
            preview_data.image_height = 144;
            break;

        case MDI_VIDEO_VIDEO_SIZE_CIF:
            preview_data.image_width = 352;
            preview_data.image_height = 288;
            break;

        case MDI_VIDEO_VIDEO_SIZE_USER_DEFINE:
            preview_data.image_width = video_setting_p->user_def_width;
            preview_data.image_height = video_setting_p->user_def_height;
            break;
        default:
            ASSERT(0);
    }

    preview_data.encode_quality = (U8) video_setting_p->video_qty;
    preview_data.bit_stream_type = (U8) video_setting_p->video_format;
    preview_data.gray_mode = 0;
    preview_data.seq_num = 0;
#endif /* ISP_SUPPORT */ 

    /* TV out */
    ret = media_vid_preview(module_id, &preview_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret != MED_RES_OK)
    {
    #ifdef __MMI_TVOUT__
        /* restore TV owner */    
        if (is_tvout)
        {
            if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
            {            
                mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
            }
        }
    #endif /* __MMI_TVOUT__ */ 
        
        return MDI_RES_VDOREC_ERR_HW_NOT_READY;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_preview_stop
 * DESCRIPTION
 *  stop recorder preview
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_preview_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_PREVIEW_STOP);   

    media_vid_stop(module_id);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    /* stop alywas return succeed */
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_start
 * DESCRIPTION
 *  start recording
 * PARAMETERS
 *  filename                    [IN]        Video clip's filename
 *  record_result_callback      [IN]        Record result callback function ptr
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_start(S8 *filename, void (*record_result_callback) (MDI_RESULT))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_req_struct record;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_RECORD_START);   

    ASSERT(record_result_callback != NULL);

    mdi_video_rec_record_result_callback = record_result_callback;

    SetProtocolEventHandler(mdi_video_rec_record_result_hdlr, MSG_ID_MEDIA_VID_RECORD_FINISH_IND);

    record.media_mode = MED_MODE_FILE;
    record.data = (void*)filename;
    record.record_audio = (U8) video_setting_p->record_aud;
    record.file_size_limit = (U32) (video_setting_p->size_limit * 1024); /* K */ ;
    record.seq_num = g_mdi_video_cntx.record_seq_num;
    record.encode_quality = (U8) video_setting_p->video_qty;

    ret = media_vid_record(module_id, &record);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret != MED_RES_OK)
    {
        switch (ret)
        {
            case MED_RES_DISC_FULL:
            case MED_RES_OPEN_FILE_FAIL:
                return MDI_RES_VDOREC_ERR_DISK_FULL;

            case MED_RES_WRITE_PROTECTION:
                return MDI_RES_VDOREC_ERR_WRITE_PROTECTION;

            default:
                return MDI_RES_VDOREC_ERR_RECORD_FAILED;
        }
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    g_mdi_video_cntx.is_recording = TRUE;
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_stop
 * DESCRIPTION
 *  stop recording
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_RECORD_STOP);   

    g_mdi_video_cntx.is_recording = FALSE;
    g_mdi_video_cntx.record_seq_num++;
    media_vid_stop(module_id);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    /* stop always return succeed */
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_pause
 * DESCRIPTION
 *  pause recording
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_pause(MMI_BOOL stop_preview)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_pause_req_struct pause_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_RECORD_PAUSE);   

    g_mdi_video_cntx.is_recording = FALSE;
    
    pause_data.stop_preview = (kal_bool)stop_preview;
    
    ret = media_vid_pause(module_id, &pause_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_BUSY)
    {
        /* 
         * ret ==  MED_RES_BUSY many happend at one cirtical situation.
         * When driver recorde almost reach time limit, and user keep pause-resume,
         * 
         * So the driver will send play finish msg to MDI as follow timing.
         * 
         * ResumeA   PauseA   ResumeB  PauseB
         * |         |        |        |
         * --|----x----|--------|---x----|--------            
         * |                 |
         * finish msg---------> 
         * MMI receive msg here   
         * 
         * so the PauseA and ResumeB will return MED_RES_BUSY and shall ignore. 
         */

        /* increase the flag, will ignore recrod finish hdlr from media */
        g_mdi_video_cntx.record_seq_num++;

        /* 
         * mmi see this return shall enter saving handling procedure, since 
         * the record finish callback will not be called 
         */

        return MDI_RES_VDOREC_RECORD_ALREADY_STOP;

    }
    else if (ret == MED_RES_END_OF_FILE)
    {
        return MDI_RES_VDOREC_REACH_SIZE_LIMIT;
    }

    else if (ret == MED_RES_DISC_FULL)
    {
        return MDI_RES_VDOREC_ERR_DISK_FULL;
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_PAUSE_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_resume
 * DESCRIPTION
 *  resume recording
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_resume(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_RECORD_RESUME);   

    ret = media_vid_resume(module_id);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_BUSY)
    {
        /* 
         * ret ==  MED_RES_BUSY many happend at one cirtical situation.
         * When driver recorde almost reach time limit, and user keep pause-resume,
         * 
         * So the driver will send play finish msg to MDI as follow timing.
         * 
         * ResumeA   PauseA   ResumeB  PauseC
         * |         |        |        |
         * --|----x----|--------|---x----|--------            
         * |                 |
         * finish msg---------> 
         * MMI receive msg here   
         * 
         * so the PauseA and ResumeB will return MED_RES_BUSY and shall ignore. 
         */

        /* increase the flag, will ignore recrod finish hdlr from media */
        g_mdi_video_cntx.record_seq_num++;

        /* 
         * mmi see this return shall enter saving handling procedure, since 
         * the record finish callback will not be called 
         */

        return MDI_RES_VDOREC_RECORD_ALREADY_STOP;

    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_RESUME_FAILED;
    }
    else
    {
        g_mdi_video_cntx.is_recording = TRUE;        
        return MDI_RES_VDOREC_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_cur_record_time
 * DESCRIPTION
 *  get current recorded time
 * PARAMETERS
 *  cur_record_time     [OUT]       Current recorded time
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_get_cur_record_time(U64 *cur_record_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_GET_CUR_RECORD_TIME);   

    /* time scale is [ms] */
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vid_get_current_record_time(module_id, cur_record_time);

    {
        U32 cur_time = (U32)*cur_record_time;
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_CUR_TIME, cur_time);     
    }
    
#else 
    *cur_record_time += 1000;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_has_unsaved_file
 * DESCRIPTION
 *  check if there is an unsaved video clip
 * PARAMETERS
 *  filepath        [IN]        Path to check
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mdi_video_rec_has_unsaved_file(S8 *filepath)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_HAS_UNSAVED_FILE);  
    
    ret = media_vid_check_unfinished_file(module_id);
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    return ret;
#else 
    return FALSE;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_delete_unsaved_file
 * DESCRIPTION
 *  delete unsaved video file
 * PARAMETERS
 *  filepath        [IN]        Path of unsaved video temp file
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_delete_unsaved_file(S8 *filepath)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_DELETE_UNSAVED_FILE);  

    media_vid_clean_temp_files(module_id);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_save_file
 * DESCRIPTION
 *  merge and save file, [Non-Blocking]
 * PARAMETERS
 *  filepath                    [IN]        Path to merge file
 *  save_result_callback        [IN]        Merge and save result
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_rec_save_file(S8 *filepath, void (*save_result_callback) (MDI_RESULT))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_merge_req_struct merge_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_SAVE_FILE);   

    ASSERT(save_result_callback != NULL);

    mdi_video_rec_save_result_callback = save_result_callback;
    
    SetProtocolEventHandler(mdi_video_rec_save_result_hdlr, MSG_ID_MEDIA_VID_FILE_MERGE_DONE_IND);

    merge_data.file_path = (kal_wchar*)filepath;
    media_vid_file_merge(module_id, &merge_data);

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    mdi_video_rec_save_result_callback = save_result_callback;
    gui_start_timer(100, mdi_video_ply_dummy_save_file_result_hdlr);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_stop_save
 * DESCRIPTION
 *  stop record saving
 * PARAMETERS
 *  void
 *  voids(?)
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_rec_stop_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_STOP_SAVE);   

    /* stop saving */
    media_vid_stop(module_id);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_ev
 * DESCRIPTION
 *  update ev setting value
 * PARAMETERS
 *  para        [IN]        Ev setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_ev(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_UPDATE_PARA_EV, para);   
    
    ASSERT(para < MDI_VIDEO_EV_COUNT);

    mdi_video_p->setting.ev = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_cam_set_param(module_id, CAM_PARAM_EXPOSURE, para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_zoom
 * DESCRIPTION
 *  update zoom setting value
 * PARAMETERS
 *  para        [IN]        Zoom setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_zoom(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_UPDATE_PARA_ZOOM, para);   
    
    mdi_video_p->setting.zoom = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_cam_set_param(module_id, CAM_PARAM_ZOOM_FACTOR, para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_effect
 * DESCRIPTION
 *  update effect setting value
 * PARAMETERS
 *  para        [IN]        Effect setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_effect(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_UPDATE_PARA_EFFECT, para);  
    
    ASSERT(para < MDI_VIDEO_EFFECT_COUNT);

    video_setting_p->effect = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_cam_set_param(module_id, CAM_PARAM_EFFECT, para);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_wb
 * DESCRIPTION
 *  update wb setting value
 * PARAMETERS
 *  para        [IN]        Ev setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_wb(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_UPDATE_PARA_WB, para);  
    
    ASSERT(para < MDI_VIDEO_WB_COUNT);

    video_setting_p->wb = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_cam_set_param(module_id, CAM_PARAM_WB, para);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_night
 * DESCRIPTION
 *  update night setting value
 * PARAMETERS
 *  para        [IN]        Ev setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_night(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_UPDATE_PARA_NIGHT, para);  
    
    video_setting_p->night = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE

#if defined(ISP_SUPPORT) && !defined(MT6219)
    if (video_setting_p->night)
    {  
        media_cam_set_param(module_id, CAM_PARAM_DSC_MODE, CAM_NIGHTSCENE);
    }
    else
    {
        media_cam_set_param(module_id, CAM_PARAM_DSC_MODE, CAM_AUTO_DSC);
    }
#else
    media_cam_set_param(module_id, CAM_PARAM_NIGHT_MODE, para);
#endif

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_max_zoom_factor
 * DESCRIPTION
 *  get max zoom factor based on resoultion
 * PARAMETERS
 *  record_width        [IN]        Record size width
 *  record_height       [IN]        Record size height
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mdi_video_rec_get_max_zoom_factor(S32 record_width, S32 record_height)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;
    module_type module_id = stack_int_get_active_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_GET_MAX_ZOOM_FACTOR);  
  
    zoom_factor = (U16)media_vid_get_max_digital_zoom_factor(
                        module_id, 
                        (U16) record_width, 
                        (U16) record_height);
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_ZOOM_FACTOR, zoom_factor);
    return zoom_factor;
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return 40;  /* 4x zooming */
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_load_default_setting
 * DESCRIPTION
 *  Init default setting value for video preview/record
 * PARAMETERS
 *  setting_p        [OUT]       setting data
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_load_default_setting(mdi_video_setting_struct *setting_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_p->wb = MDI_VIDEO_WB_AUTO;
    setting_p->ev = MDI_VIDEO_EV_0;
    setting_p->banding = MDI_VIDEO_BANDING_60HZ; /* TW: 60, CN: 50 */
    setting_p->effect = MDI_VIDEO_EFFECT_NOMRAL;
    setting_p->zoom = 10;
    setting_p->brightness = 128;
    setting_p->contrast = 128;
    setting_p->saturation = 128;
    setting_p->hue = 0;
    setting_p->preview_rotate = MDI_VIDEO_PREVIEW_ROTATE_0;
    setting_p->lcm_rotate = MDI_LCD_ROTATE_0; 

    setting_p->night = 0;

    setting_p->video_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
    setting_p->video_qty = MDI_VIDEO_REC_QTY_NORMAL;
    setting_p->size_limit = 0;
    setting_p->time_limit = 0;
    setting_p->record_aud = 1; /* TRUE */
    setting_p->video_format = MDI_VIDEO_VIDEO_FORMAT_3GP;
    setting_p->user_def_width = 0;
    setting_p->user_def_height = 0;

    setting_p->overlay_frame_mode = FALSE;
    setting_p->overlay_frame_depth = 0;
    setting_p->overlay_frame_source_key = 0;
    setting_p->overlay_frame_width = 0;
    setting_p->overlay_frame_height = 0;
    setting_p->overlay_frame_buffer_address = 0;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_record_file_size
 * DESCRIPTION
 *  get current record file size
 * PARAMETERS
*   void
 * RETURNS
 *  U64
 *****************************************************************************/
U64 mdi_video_rec_get_record_file_size(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 file_size;
    module_type module_id = stack_int_get_active_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_GET_RECORD_FILE_SIZE);  

    media_vid_get_current_record_size(module_id, &file_size);
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_FILE_SIZE, (U32)file_size);
    return file_size;
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return 0; 
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}





/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_blt_pause
 * DESCRIPTION
 *  Pause for update blt parameters, special function for Java use only,
 *  This function should be pariled with mdi_video_rec_resume_for_update_blt_para()
 *
 *  [Example]
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume(); 
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
MDI_RESULT mdi_video_rec_update_blt_pause(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_pause_req_struct pause_data; 
    MDI_RESULT ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_vid_update_blt_pause(module_id, &pause_data);

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_blt_resume
 * DESCRIPTION
 *  Resume for update blt parameters, special function for Java use only
 *  This function should be pariled with mdi_video_rec_resume_for_update_blt_para()
 *
 *  [Example]
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume(); 
 * 
 * PARAMETERS
 *  preview_layer_handle        [IN]        Layer for preview
 *  blt_layer_flag              [IN]        Blt out layer flag
 *  preview_layer_flag          [IN]        Preview layer flag
 *  is_lcd_udpate               [IN]        Update lcd or not
 * RETURNS
 *  U16
 *****************************************************************************/
MDI_RESULT mdi_video_rec_update_blt_resume(
            gdi_handle preview_layer_handle,
            U32 blt_layer_flag,     
            U32 preview_layer_flag, 
            MMI_BOOL is_lcd_update)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_resume_req_struct update_data;
    MDI_RESULT ret;
    mdi_blt_para_struct blt_data;
    MMI_BOOL is_tvout = MMI_FALSE;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//  MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_PREVIEW_START);   

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        is_tvout = MMI_TRUE;        
    }
    else
    {
        is_tvout = MMI_FALSE;
    }
#endif /* __MMI_TVOUT__ */


    mdi_calc_blt_para(
        preview_layer_handle, 
        video_setting_p->lcm_rotate, 
        g_mdi_video_cntx.lcd_handle,        
        is_tvout, 
        &blt_data);

    update_data.lcd_id = MAIN_LCD;
    update_data.preview_offset_x = 0;  /* offset from lcd_offset_x, set as 0 */
    update_data.preview_offset_y = 0;  /* offset from lcd_offset_x, set as 0 */
    update_data.update_layer = blt_layer_flag;
    update_data.hw_update_layer = preview_layer_flag;
    update_data.lcd_update = is_lcd_update;
    
    /* lcd / preview related */
    update_data.buffer_width = blt_data.display_width;
    update_data.buffer_height = blt_data.display_height;
    update_data.image_buffer_size = blt_data.image_buffer_size;
    update_data.image_buffer_p = (void*)blt_data.image_buffer_p;
    update_data.preview_width = blt_data.display_width;
    update_data.preview_height = blt_data.display_height;
    update_data.lcd_rotate = blt_data.lcd_rotate;
    update_data.lcd_start_x = blt_data.lcd_start_x;
    update_data.lcd_start_y = blt_data.lcd_start_y;
    update_data.lcd_end_x = blt_data.lcd_end_x;
    update_data.lcd_end_y = blt_data.lcd_end_y;
    update_data.roi_offset_x = blt_data.roi_offset_x;
    update_data.roi_offset_y = blt_data.roi_offset_y;    

#if defined(MDI_VIDEO_MT6228_SERIES)
    update_data.tv_output = blt_data.tv_output;

#ifdef __MMI_TVOUT__
    update_data.tv_output_width = blt_data.tv_output_width;
    update_data.tv_output_width = blt_data.tv_output_width;
    update_data.tv_output_height = blt_data.tv_output_height;
    update_data.tv_output_offset_x = blt_data.tv_output_offset_x;
    update_data.tv_output_offset_y = blt_data.tv_output_offset_y;
    update_data.tv_output_buffer_size = blt_data.tv_output_buffer_size;
    update_data.tv_output_buffer1_address = (kal_uint32)blt_data.tv_output_buffer1_address;
    update_data.tv_output_buffer2_address = (kal_uint32)blt_data.tv_output_buffer2_address;
#endif /* __MMI_TVOUT__ */

#endif /* MDI_VIDEO_MT6228_SERIES */ 

    ret = media_vid_update_blt_resume(module_id, &update_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    


    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_save_result_hdlr
 * DESCRIPTION
 *  save result message hdlr
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_rec_save_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_merge_done_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_SAVE_RESULT_HDLR);   

    ind_p = (media_vid_file_merge_done_ind_struct*) msg_ptr;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);    

    if (ind_p->result == MED_RES_OK)
    {
        mdi_video_rec_save_result_callback(MDI_RES_VDOREC_SUCCEED);
    }
    else if (ind_p->result == MED_RES_DISC_FULL)
    {
        mdi_video_rec_save_result_callback(MDI_RES_VDOREC_ERR_DISK_FULL);
    }
    else
    {
        mdi_video_rec_save_result_callback(MDI_RES_VDOREC_ERR_FAILED);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_dummy_save_file_result_hdlr
 * DESCRIPTION
 *  dummy save file result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_ply_dummy_save_file_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_rec_save_result_callback(MDI_RES_VDOREC_SUCCEED);
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_dummy_play_cyclic
 * DESCRIPTION
 *  dummy play result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_ply_dummy_play_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_video_cntx.dummy_cur_time += 100;

    if (g_mdi_video_cntx.dummy_cur_time >= MDI_VIDEO_DUMMY_TOTAL_TIME)
    {
        if (mdi_video_ply_play_finish_callback != NULL)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_SUCCEED);
        }
        return;
    }

#ifdef __MMI_VIDEO_PDL__    
    if (g_mdi_video_cntx.dummy_cur_time > g_mdi_video_cntx.dummy_max_play_time)
    {
        g_mdi_video_cntx.dummy_loading_percentage = 0;
        mdi_video_progressive_dummy_loading_cyclic();
        
        if (mdi_video_ply_play_finish_callback != NULL)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH);
        }
        return;
    }
#endif /* __MMI_VIDEO_PDL__ */
    gui_start_timer(100, mdi_video_ply_dummy_play_cyclic);
    
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_result_hdlr
 * DESCRIPTION
 *  record result message hdlr
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_rec_record_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_finish_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_RECORD_RESULT_HDLR);   

    ind_p = (media_vid_record_finish_ind_struct*) msg_ptr;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);    

    /* seq number not match, measn it is already stopped, ignore this message */
    if (g_mdi_video_cntx.record_seq_num != ind_p->seq_num)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);   
        return;
    }

    g_mdi_video_cntx.is_recording = FALSE;

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

    /* successful save file */
    if (ind_p->result == MED_RES_END_OF_FILE)
    {
        mdi_video_rec_record_result_callback(MDI_RES_VDOREC_REACH_SIZE_LIMIT);
    }
    else if (ind_p->result == MED_RES_DISC_FULL)
    {
        mdi_video_rec_record_result_callback(MDI_RES_VDOREC_DISK_FULL);
    }
    else if (ind_p->result == MED_RES_BUSY)
    {
        mdi_video_rec_record_result_callback(MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW);
    }    
    else
    {
        mdi_video_rec_record_result_callback(MDI_RES_VDOREC_ERR_FAILED);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}



/****************************************************************************
*
* Video Player
*
****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_init
 * DESCRIPTION
 *  init mdi video player
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_video_cntx.open_seq_num = 0;
    g_mdi_video_cntx.play_seq_num = 0;
    g_mdi_video_cntx.record_seq_num = 0;
    g_mdi_video_cntx.seek_seq_num = 0;
    g_mdi_video_cntx.connect_seq_num = 0;
    g_mdi_video_cntx.buffering_seq_num = 0;   
    g_mdi_video_cntx.merge_seq_num = 0;

    g_mdi_video_cntx.is_seeking = FALSE;
    g_mdi_video_cntx.is_playing = FALSE;    
    g_mdi_video_cntx.is_recording = FALSE;        
    g_mdi_video_cntx.is_enable_partial_display = FALSE;
    g_mdi_video_cntx.is_consume_drm_count = TRUE;
    g_mdi_video_cntx.is_drm_file = FALSE;

#ifdef __DRM_SUPPORT__
    g_mdi_video_cntx.drm_id = MDI_VIDEO_DRM_INVALID_VALUE;    
#endif

#ifdef __MMI_TVOUT__
    g_mdi_video_cntx.tvout_prev_owner = MDI_TV_OWNER_GDI;
#endif 

    /* init shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_file
 * DESCRIPTION
 *  open video file
 * PARAMETERS
 *  filename                    [IN]        Videe clip's full file name
 *  open_result_callback        [IN]        
 *  open_done_callback(?)       [IN]        Open file result  callback function
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_file(
            const S8 *filename,
            void (*open_result_callback) (MDI_RESULT, mdi_video_info_struct*))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_open_req_struct open_data;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_OPEN_FILE);   

    ret = MED_RES_FAIL;

    /* set need seek flag */
    mdi_video_p->is_seek_after_open = FALSE;
    mdi_video_p->is_drm_file = FALSE;
    
    mdi_video_ply_open_file_result_callback = open_result_callback;

    SetProtocolEventHandler(mdi_video_ply_open_file_result_hdlr, MSG_ID_MEDIA_VID_FILE_READY_IND);

#ifdef __DRM_SUPPORT__
    ASSERT(mdi_video_p->drm_state == MDI_VIDEO_DRM_EXIT);
    ASSERT(mdi_video_p->drm_file_h == NULL);

    mdi_video_p->drm_file_h = DRM_open_file((PU16)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY);

    if (mdi_video_p->drm_file_h > FS_NO_ERROR)
    {
        /* check if it is DRM file or not */
        if (DRM_get_object_method(mdi_video_p->drm_file_h, NULL) != DRM_METHOD_NONE)
        {
            mdi_video_p->is_drm_file = TRUE;                

            if (mdi_video_p->is_consume_drm_count)
            {                
                if (DRM_validate_permission(mdi_video_p->drm_file_h, NULL, DRM_PERMISSION_PLAY))
                {
                    /* it is DRM file, and has permission */
                    mdi_video_p->drm_state = MDI_VIDEO_DRM_PERMITTED;
                }   
                else
                {
                    /* it is DRM file, but no rights */
                    DRM_close_file(mdi_video_p->drm_file_h); 
                    mdi_video_p->drm_file_h = NULL;
                    return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
                }
            }
            else
            {
                mdi_video_p->drm_state = MDI_VIDEO_DRM_PERMITTED;
            }
        }
        else
        {
            /* not DRM file... close file handle */
            DRM_close_file(mdi_video_p->drm_file_h);
            mdi_video_p->drm_file_h = NULL;
        }

    }
    else if (mdi_video_p->drm_file_h == DRM_RESULT_NO_PERMISSION)
    {
        mdi_video_p->drm_file_h = NULL;
        return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
    }
    else
    {
        /* open file failed */
        mdi_video_p->drm_file_h = NULL;
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
#endif /* __DRM_SUPPORT__ */

    open_data.media_mode = MED_MODE_FILE;
    open_data.enable_aud_only = KAL_TRUE;
    open_data.data = (void*)filename;

#if defined(MDI_VIDEO_MT6228_SERIES)
    open_data.max_width = 352;  /* CIF width  - max decodable size */
    open_data.max_height = 288; /* CIF height - max decodable size */
#else /* MDI_VIDEO_MT6228_SERIES */ 
    /* MT6219 */
    open_data.max_width = 176;  /* QCIF width  - max decodable size */
    open_data.max_height = 144; /* QCIF height - max decodable size */
#endif /* MDI_VIDEO_MT6228_SERIES */ 

    open_data.play_audio = (U8)TRUE;
    open_data.seq_num = g_mdi_video_cntx.open_seq_num;
    open_data.blocking = FALSE; /* no blocking */

    /* following 4 parameters are used for blocking function */
    open_data.image_width = NULL;
    open_data.image_height = NULL;
    open_data.total_time = NULL;
    open_data.handle = NULL;

#ifdef __SF_MP4_SUPPORT__
    open_data.media_type = (kal_uint8)mmi_fmgr_get_file_type_by_filename((S8*)filename);
#endif //__SF_MP4_SUPPORT__

    ret = media_vid_open(module_id, &open_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    
    
    if (ret != MED_RES_OK)
    {
    #ifdef __DRM_SUPPORT__
        /* close and restore DRM files */
        mdi_video_p->is_consume_drm_count = TRUE;
        mdi_video_p->is_drm_file = FALSE;             
        mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;
        
        if (mdi_video_p->drm_file_h != NULL)
        {
            DRM_close_file(mdi_video_p->drm_file_h);
            mdi_video_p->drm_file_h = NULL;        
        }
    #endif /* __DRM_SUPPORT__ */
    
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    {
        g_mdi_video_cntx.dummy_cur_time = 0;
        
        mdi_video_ply_open_file_result_callback = open_result_callback;
        gui_start_timer(300, mdi_video_ply_dummy_open_file_result_hdlr);

        return MDI_RES_VDOPLY_SUCCEED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_dummy_open_file_result_hdlr
 * DESCRIPTION
 *  dummy open file result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_ply_dummy_open_file_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct vdo_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vdo_clip.width = 176;
    vdo_clip.height = 144;
    vdo_clip.total_time_duration = MDI_VIDEO_DUMMY_TOTAL_TIME;
    vdo_clip.track = MDI_VIDEO_TRACK_AV;
    mdi_video_ply_open_file_result_callback(MDI_RES_VDOPLY_SUCCEED, &vdo_clip);
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_file
 * DESCRIPTION
 *  close video file
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_close_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct close_data;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_CLOSE_FILE);   

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    g_mdi_video_cntx.open_seq_num++;

    close_data.handle = 0;
    close_data.media_mode = MED_MODE_FILE;

    media_vid_close(module_id, &close_data);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

#ifdef __DRM_SUPPORT__
    /* reset flag */
    mdi_video_p->is_consume_drm_count = TRUE;
    mdi_video_p->is_drm_file = FALSE;     

    if (mdi_video_p->drm_state == MDI_VIDEO_DRM_PAUSED)
    {
        ASSERT(mdi_video_p->drm_id != MDI_VIDEO_DRM_INVALID_VALUE)
        DRM_stop_consume(mdi_video_p->drm_id);
        mdi_video_p->drm_id = MDI_VIDEO_DRM_INVALID_VALUE;
        mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;        
    }
    else if (mdi_video_p->drm_state == MDI_VIDEO_DRM_PLAY_FINISHED || 
             mdi_video_p->drm_state == MDI_VIDEO_DRM_PERMITTED)
    {
        mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;   
    }

    if (mdi_video_p->drm_file_h != NULL)
    {
        DRM_close_file(mdi_video_p->drm_file_h);
        mdi_video_p->drm_file_h = NULL;        
    }

#endif /* __DRM_SUPPORT__ */

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_snapshot
 * DESCRIPTION
 *  snapshot video and save as jpeg file
 * PARAMETERS
 *  layer_handle        [IN]        Video play layer
 *  file_name           [IN]        Filename for jpeg
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_snapshot(gdi_handle layer_handle, PS8 file_name)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    img_encode_struct encode_data;
    S32 image_width;
    S32 image_height;
    PU8 image_ptr;
    U32 file_size;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SNAPSHOT);   

    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&image_width, &image_height);
    gdi_layer_get_buffer_ptr(&image_ptr);
    gdi_layer_pop_and_restore_active();

    encode_data.image_width = image_width;
    encode_data.image_height = image_height;

    encode_data.image_quality = CAM_JPG_QTY_HIGH;
    encode_data.image_buffer_p = (void*)image_ptr;
    encode_data.image_buffer_size = (image_width * image_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;

    encode_data.target_width = image_width;
    encode_data.target_height = image_height;
    encode_data.media_mode = MED_MODE_FILE;
    encode_data.media_type = MED_TYPE_JPG;

    encode_data.data = (void*)file_name;
    encode_data.file_size_p = (kal_uint32*) & file_size;
    encode_data.blocking = (kal_bool) TRUE;         /* blocking */
    encode_data.seq_num = (kal_uint16) 0;           /* not used */
    encode_data.file_buffer_len = (kal_uint32) 0;   /* not used */
    encode_data.gray_mode = 0;

#if (MDI_CAMERA_MT6228_SERIES)
    encode_data.jpeg_yuv_mode = JPEG_FORMAT_YUV420;
    encode_data.thumbnail_mode = FALSE;
    encode_data.overlay_frame_mode = FALSE;
#endif /* MDI_CAMERA_MT6228_SERIES */ 

    ret = media_img_encode(module_id, &encode_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else if (ret == MED_RES_DISC_FULL)
    {
        return MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL;
    }
    else if (ret == MED_RES_WRITE_PROTECTION)
    {
        return MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION;
    }
    else if (ret == MED_RES_NO_DISC)
    {
        return MDI_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_play
 * DESCRIPTION
 *  snapshot video and save as jpeg file
 * PARAMETERS
 *  player_layer_handle         [IN]        Play layer handle
 *  blt_layer_flag              [IN]        Layer to blt to LCM
 *  play_layer_flag             [IN]        Layer for HW to draw
 *  repeat_count                [IN]        Repeat how many times
 *  is_visual_update            [IN]        Update to LCM or not
 *  is_play_audio               [IN]        play audio or not
 *  audio_path                  [IN]        Audio output path
 *  rotate                      [IN]        Rotate
 *  play_speed                  [IN]        Play speed
 *  play_finish_callback        [IN]        
 *  play_finish_hdlr(?)         [IN]        Play finish callback
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_play(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag, 
            U32 play_layer_flag,
            U16 repeat_count,
            BOOL is_visual_update,
            BOOL is_play_audio,
            U8 audio_path,
            U16 rotate,
            S16 play_speed,
            void (*play_finish_callback) (MDI_RESULT))  /* call back when play finied */
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_BOOL is_tvout = MMI_FALSE;
    media_vid_play_req_struct play_data;
    mdi_blt_para_struct blt_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_PLAY);   

    ret = MED_RES_FAIL;

#ifdef __DRM_SUPPORT__
    /* consume rights */
    if (mdi_video_p->drm_state == MDI_VIDEO_DRM_PERMITTED)
    {
        ASSERT(mdi_video_p->drm_file_h != NULL);
        
        if (!mdi_video_p->is_consume_drm_count)
        {
            /* will only consume duration rights */
            mdi_video_p->drm_id = DRM_consume_timed_rights_with_module(
                                    mdi_video_p->drm_file_h, 
                                    DRM_PERMISSION_PLAY, 
                                    mdi_video_ply_drm_consume_callback,
                                    module_id);            

            mdi_video_p->is_consume_drm_count = TRUE;
        }
        else
        {
            /* will consume count rights and timing rights */
            mdi_video_p->drm_id = DRM_consume_rights_with_module(
                                    mdi_video_p->drm_file_h, 
                                    DRM_PERMISSION_PLAY, 
                                    mdi_video_ply_drm_consume_callback,
                                    module_id);
        }            

        mdi_video_p->drm_state = MDI_VIDEO_DRM_CONSUMING;    
    }
    else if (mdi_video_p->drm_state == MDI_VIDEO_DRM_PLAY_FINISHED)
    {
        ASSERT(mdi_video_p->drm_file_h != NULL);        
        
        /* play finished, need validate permission again */
        if (DRM_validate_permission(mdi_video_p->drm_file_h, NULL, DRM_PERMISSION_PLAY))
        {
            /* has permission, consume rights */
            ASSERT(mdi_video_p->drm_id == MDI_VIDEO_DRM_INVALID_VALUE);
            mdi_video_p->drm_id = DRM_consume_rights_with_module(
                                    mdi_video_p->drm_file_h, 
                                    DRM_PERMISSION_PLAY, 
                                    mdi_video_ply_drm_consume_callback,
                                    module_id);
                                    
            mdi_video_p->drm_state = MDI_VIDEO_DRM_CONSUMING;
        }   
        else
        {   
            /* it is DRM file, but no rights */
            mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;                
            return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
        }
    }
    else if (mdi_video_p->drm_state == MDI_VIDEO_DRM_PAUSED)
    {
        ASSERT(mdi_video_p->drm_file_h != NULL); 
        ASSERT(mdi_video_p->drm_id != MDI_VIDEO_DRM_INVALID_VALUE);        

        if (!mdi_video_p->is_consume_drm_count)
        {
            DRM_resume_consume(mdi_video_p->drm_id);
        }
        else
        {
            /* stop and consume again */
            DRM_stop_consume(mdi_video_p->drm_id);    

            /* play finished, need validate permission again */
            if (DRM_validate_permission(mdi_video_p->drm_file_h, NULL, DRM_PERMISSION_PLAY))
            {
                /* has permission, consume rights */

                mdi_video_p->drm_id = DRM_consume_rights_with_module(
                                        mdi_video_p->drm_file_h, 
                                        DRM_PERMISSION_PLAY, 
                                        mdi_video_ply_drm_consume_callback,
                                        module_id);

                mdi_video_p->drm_state = MDI_VIDEO_DRM_CONSUMING;
            }   
            else
            {   
                /* it is DRM file, but no rights */
                mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;                
                return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
            }
        }   

        mdi_video_p->drm_state = MDI_VIDEO_DRM_CONSUMING;           
    }
    else if (mdi_video_p->drm_state == MDI_VIDEO_DRM_EXIT &&
             mdi_video_p->is_drm_file)
    {
        return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
    }
#endif /* __DRM_SUPPORT__ */


    /* after open, need seek before start play */
    ASSERT(mdi_video_p->is_seek_after_open);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    /* Connect SCO to output audio to BT earpone */
    mmi_profiles_bt_connect_audio_via_sco();
#endif

    mdi_video_ply_play_finish_callback = play_finish_callback;

    SetProtocolEventHandler(mdi_video_ply_play_finish_result_hdlr, MSG_ID_MEDIA_VID_PLAY_FINISH_IND);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable() && 
        (g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_AV || 
         g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY))
    {
        g_mdi_video_cntx.tvout_prev_owner = mdi_tvout_get_owner();
        
        /* if tvout is on and has V track */
        mdi_tvout_set_owner(MDI_TV_OWNER_VIDEO);        
        is_tvout = MMI_TRUE;        
    }
    else
    {
        is_tvout = MMI_FALSE;
    }
#endif /* __MMI_TVOUT__ */


    /* set display lcd */
    gdi_lcd_get_active(&g_mdi_video_cntx.lcd_handle);
    
    if (g_mdi_video_cntx.lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        play_data.lcd_id = MAIN_LCD;

    #ifdef __MMI_SUBLCD__
        if (is_visual_update)
        {
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            //gdi_lcd_freeze(TRUE); //Huyanwei Del It
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        }
    #endif /* __MMI_SUBLCD__ */         
    }
    else if (g_mdi_video_cntx.lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        play_data.lcd_id = SUB_LCD;

        if (is_visual_update)
        {
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            gdi_lcd_freeze(TRUE);
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        }    
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* calc blt paramters */
    mdi_calc_blt_para(
        player_layer_handle, 
        rotate, 
        g_mdi_video_cntx.lcd_handle, 
        is_tvout, 
        &blt_data);

    play_data.display_offset_x = 0;         /* not used */
    play_data.display_offset_y = 0;         /* not used */
    play_data.video_display_offset_x = 0;   /* not used */
    play_data.video_display_offset_y = 0;   /* not used */

    play_data.lcd_start_x = blt_data.lcd_start_x;
    play_data.lcd_start_y = blt_data.lcd_start_y;
    play_data.lcd_end_x = blt_data.lcd_end_x;
    play_data.lcd_end_y = blt_data.lcd_end_y;
    play_data.display_width = blt_data.display_width;
    play_data.display_height = blt_data.display_height;
    play_data.roi_offset_x = blt_data.roi_offset_x;
    play_data.roi_offset_y = blt_data.roi_offset_y;    
    play_data.image_buffer_p = (void*)blt_data.image_buffer_p;
    play_data.image_buffer_size = blt_data.image_buffer_size;
    play_data.lcd_rotate = blt_data.lcd_rotate;

#if defined(MDI_VIDEO_MT6228_SERIES)
    play_data.image_pitch_mode = FALSE; /* do not use this mode */
    play_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    play_data.tv_output = blt_data.tv_output;
#endif /* MDI_VIDEO_MT6228_SERIES */ 

#ifdef __MMI_TVOUT__
    play_data.tv_output_width = blt_data.tv_output_width;
    play_data.tv_output_width = blt_data.tv_output_width;
    play_data.tv_output_height = blt_data.tv_output_height;
    play_data.tv_output_offset_x = blt_data.tv_output_offset_x;
    play_data.tv_output_offset_y = blt_data.tv_output_offset_y;
    play_data.tv_output_buffer_size = blt_data.tv_output_buffer_size;
    play_data.tv_output_buffer1_address = (kal_uint32)blt_data.tv_output_buffer1_address;
    play_data.tv_output_buffer2_address = (kal_uint32)blt_data.tv_output_buffer2_address;
#endif /* __MMI_TVOUT__ */

    play_data.update_layer = blt_layer_flag;
    play_data.hw_update_layer = play_layer_flag;
    play_data.play_audio = is_play_audio;
    play_data.play_speed = play_speed;
    play_data.audio_path = audio_path;
    play_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    play_data.seq_num = g_mdi_video_cntx.play_seq_num;

    /* 
     * Set this to true will force driver to use hw trigger instead of direct couple.
     * Direct couple has better frame rate but cant draw out side of lcd region. 
     */
    play_data.force_lcd_hw_trigger = g_mdi_video_cntx.is_enable_partial_display;

    /* speed */
    /* 
     * driver only support audio time stretch at speed 
     * 50, 80, 125, 160 
     * We will do remapping
     * 50  -> 50
     * 75  -> 80
     * 125 -> 125
     * 150 -> 160
     */
    if (play_data.play_speed == 75)
    {
        play_data.play_speed = 80;
    }

    if (play_data.play_speed == 150)
    {
        play_data.play_speed = 160;
    }

    if (is_visual_update)
    {
        play_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    }
    else
    {
        play_data.display_device = MED_DISPLAY_NONE;
    }

    if (repeat_count == 0)
    {
        play_data.repeats = 0xffff; /* infinite play */
    }
    else
    {
        play_data.repeats = repeat_count;
    }


    ret = media_vid_play(module_id, &play_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret != MED_RES_OK)
    {

    #ifdef __MMI_SUBLCD__
        if (g_mdi_video_cntx.lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
        {    
            /* un-freeze sublcd */    
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_freeze(FALSE);
	   gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        }
        else if (g_mdi_video_cntx.lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
        {
            /* un-freeze mainlcd */    
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            gdi_lcd_freeze(FALSE);
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        }
    #endif /* __MMI_SUBLCD__ */ 

    #ifdef __MMI_TVOUT__
        /* restore TV owner */    
        if (is_tvout)
        {
            /* restore to previous owner */
            if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
            {
                mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
            }
        }
    #endif /* __MMI_TVOUT__ */ 


    #ifdef __DRM_SUPPORT__
        /* pause consume */
        if (mdi_video_p->drm_state == MDI_VIDEO_DRM_CONSUMING)
        {
            ASSERT(mdi_video_p->drm_id != MDI_VIDEO_DRM_INVALID_VALUE);
            DRM_pause_consume(mdi_video_p->drm_id);
            mdi_video_p->drm_state = MDI_VIDEO_DRM_PAUSED;
        }
    #endif /* __DRM_SUPPORT__ */

        if (ret == MED_RES_PDL_AUDIO_UNDERFLOW || 
            ret == MED_RES_PDL_VIDEO_UNDERFLOW)
        {
            return MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH;
        }
        else if (ret == MED_RES_REACH_STOP_TIME)
        {
            return MDI_RES_VDOPLY_REACH_STOP_TIME;
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
        }
        
    }
#else
    mdi_video_ply_play_finish_callback = play_finish_callback;
    mdi_video_ply_dummy_play_cyclic();
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    g_mdi_video_cntx.is_playing = TRUE;
    return MDI_RES_VDOPLY_SUCCEED;
}

#ifdef __SF_MP4_SUPPORT__
extern BOOL mmi_vdoply_is_full_screen(void);
extern BOOL SFApp_VdoFreeGDI(void);
#endif //__SF_MP4_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_stop
 * DESCRIPTION
 *  stop video playing
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_STOP);   

    g_mdi_video_cntx.is_playing = FALSE;
    g_mdi_video_cntx.play_seq_num++;
    media_vid_stop(module_id);

#ifdef __SF_MP4_SUPPORT__
    if (mmi_vdoply_is_full_screen()) 
        SFApp_VdoFreeGDI();
#endif //__SF_MP4_SUPPORT__

    /* un-freeze sublcd */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_freeze(FALSE);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable() && 
        (g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_AV || 
         g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY))
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    gui_cancel_timer(mdi_video_ply_dummy_play_cyclic);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    g_mdi_video_cntx.is_enable_partial_display = FALSE;

#ifdef __DRM_SUPPORT__
    /* pause consume */
    if (mdi_video_p->drm_state == MDI_VIDEO_DRM_CONSUMING)
    {
        ASSERT(mdi_video_p->drm_id != MDI_VIDEO_DRM_INVALID_VALUE);
        DRM_pause_consume(mdi_video_p->drm_id);
        mdi_video_p->drm_state = MDI_VIDEO_DRM_PAUSED;
    }

    mdi_video_p->is_consume_drm_count = TRUE;    
#endif /* __DRM_SUPPORT__ */

    /* stop always return succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_seek
 * DESCRIPTION
 *  seek video
 * PARAMETERS
 *  time        [IN]        Seek time stamp
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_seek(U64 time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_req_struct seek_data;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SEEK);   

    mdi_video_p->is_seek_after_open = TRUE;

    seek_data.time = time;
    seek_data.get_frame = FALSE;
    seek_data.blocking = TRUE;

#if defined(MDI_VIDEO_MT6228_SERIES)
    seek_data.tv_output = FALSE;
    seek_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    seek_data.image_pitch_bytes = 0; /* not used */    
#endif /* MDI_VIDEO_MT6228_SERIES */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (mdi_tvout_get_owner() == MDI_TV_OWNER_VIDEO)
        {
            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_VIDEO,
                    NULL,   /* mode_ptr */
                    NULL,   /* buf_width_ptr */
                    NULL,   /* buf_height_ptr */
                    (PU32) & seek_data.tv_output_buffer_size,  /* buf size */
                    (PU8*) & seek_data.tv_output_buffer1_address,     /* buf1 pp */
                    (PU8*) & seek_data.tv_output_buffer2_address,     /* buf2 pp */
                    NULL,   /* rotate_buf_1_pp */
                    NULL);  /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                seek_data.tv_output = TRUE;
            }
            else
            {
                seek_data.tv_output = FALSE;
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    ret = media_vid_seek(module_id, &seek_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_VIDEO_SEEK_PARTIAL_DONE)
    {
        return MDI_RES_VDOPLY_SEEK_PARTIAL_DONE;
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_SEEK_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    g_mdi_video_cntx.dummy_cur_time = time;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}

#ifdef __SF_MP4_SUPPORT__
static void mdi_video_ply_idle_seek_result_hdlr(void *msgPtr)
{
    media_vid_seek_done_ind_struct *ind_p = (media_vid_seek_done_ind_struct *)msgPtr;
    kal_prompt_trace(MOD_MMI, "In mdi_video_ply_idle_seek_result_hdlr, ind_p->result:%d", ind_p->result);
}
#endif //__SF_MP4_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_seek_and_get_frame
 * DESCRIPTION
 *  seek video and get seek frame
 * PARAMETERS
 *  time                    [IN]        Seek time stamp
 *  player_layer_handle     [IN]        Get frame on this layer
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_seek_and_get_frame(U64 time, gdi_handle player_layer_handle)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    U8 *buf_ptr;
    S32 ret;
    media_vid_seek_req_struct seek_data;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SEEK_AND_GET_FRAME);   

    mdi_video_p->is_seek_after_open = TRUE;

    gdi_layer_push_and_set_active(player_layer_handle);

    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    gdi_layer_pop_and_restore_active();

#ifdef __SF_MP4_SUPPORT__
    //SetProtocolEventHandler(mdi_video_ply_idle_seek_result_hdlr, MSG_ID_MEDIA_VID_SEEK_DONE_IND);
#endif //__SF_MP4_SUPPORT__

    seek_data.time = time;
    seek_data.get_frame = TRUE;
    seek_data.display_width = layer_width;
    seek_data.display_height = layer_height;
    seek_data.display_offset_x = 0;
    seek_data.display_offset_y = 0;
    seek_data.image_buffer_p = (void*)buf_ptr;
    seek_data.image_buffer_size = (layer_width * layer_height * GDI_LAYER.act_bit_per_pixel) >> 3;
    seek_data.blocking = TRUE;

#if defined(MDI_VIDEO_MT6228_SERIES)
    seek_data.tv_output = FALSE;
    seek_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    seek_data.image_pitch_bytes = 0; /* not used */    
#endif /* MDI_VIDEO_MT6228_SERIES */ 

    /* TV out */
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (mdi_tvout_get_owner() == MDI_TV_OWNER_VIDEO)
        {
            /* if owner is VIDEO, means already in mode2 */
            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_VIDEO,
                    NULL,   /* mode_ptr */
                    NULL,   /* buf_width_ptr */
                    NULL,   /* buf_height_ptr */
                    (PU32) & seek_data.tv_output_buffer_size,  /* buf size */
                    (PU8*) & seek_data.tv_output_buffer1_address,     /* buf1 pp */
                    (PU8*) & seek_data.tv_output_buffer2_address,     /* buf2 pp */
                    NULL,   /* rotate_buf_1_pp */
                    NULL);  /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                seek_data.tv_output = TRUE;
            }
            else
            {
                seek_data.tv_output = FALSE;
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    ret = media_vid_seek(module_id, &seek_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_VIDEO_SEEK_PARTIAL_DONE)
    {
        return MDI_RES_VDOPLY_SEEK_PARTIAL_DONE;
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_SEEK_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    g_mdi_video_cntx.dummy_cur_time = time;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_non_block_seek
 * DESCRIPTION
 *  seek video
 * PARAMETERS
 *  time                        [IN]        Seek time stamp
 *  seek_result_callback        [IN]        Seek result callback function
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_non_block_seek(U64 time, void (*seek_result_callback) (MDI_RESULT))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_req_struct seek_data;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_NON_BLOCK_SEEK);   

    SetProtocolEventHandler(mdi_video_ply_non_block_seek_result_hdlr, MSG_ID_MEDIA_VID_SEEK_DONE_IND);

    mdi_video_p->is_seek_after_open = TRUE;
    mdi_video_play_seek_result_callback = seek_result_callback;

    seek_data.time = time;
    seek_data.get_frame = FALSE;
    seek_data.blocking = FALSE;
    seek_data.seq_num = g_mdi_video_cntx.seek_seq_num;

#if defined(MDI_VIDEO_MT6228_SERIES)
    seek_data.tv_output = FALSE;
    seek_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    seek_data.image_pitch_bytes = 0; /* not used */    
#endif /* MDI_VIDEO_MT6228_SERIES */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (mdi_tvout_get_owner() == MDI_TV_OWNER_VIDEO)
        {
            /* if owner is VIDEO, means already in mode2 */
            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_VIDEO,
                    NULL,   /* mode_ptr */
                    NULL,   /* buf_width_ptr */
                    NULL,   /* buf_height_ptr */
                    (PU32) & seek_data.tv_output_buffer_size,  /* buf size */
                    (PU8*) & seek_data.tv_output_buffer1_address,     /* buf1 pp */
                    (PU8*) & seek_data.tv_output_buffer2_address,     /* buf2 pp */
                    NULL,   /* rotate_buf_1_pp */
                    NULL);  /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                seek_data.tv_output = TRUE;
            }
            else
            {
                seek_data.tv_output = FALSE;
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    ret = media_vid_seek(module_id, &seek_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_PDL_VIDEO_UNDERFLOW)
    {
        return MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH;        
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_SEEK_FAILED;
    }

    g_mdi_video_cntx.is_seeking = TRUE;

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    g_mdi_video_cntx.dummy_cur_time = time;
    mdi_video_play_seek_result_callback = seek_result_callback;
    gui_start_timer(100, mdi_video_ply_dummy_non_block_seek_result_hdlr);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_dummy_non_block_seek_result_hdlr
 * DESCRIPTION
 *  dummy non-block seek result callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_ply_dummy_non_block_seek_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_SUCCEED);
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_non_block_seek_and_get_frame
 * DESCRIPTION
 *  seek video and get seek frame
 * PARAMETERS
 *  time                        [IN]        Seek time stamp
 *  player_layer_handle         [IN]        Get frame on this layer
 *  seek_result_callback        [IN]        Seek result callback function
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_non_block_seek_and_get_frame(
            U64 time,
            gdi_handle player_layer_handle,
            void (*seek_result_callback) (MDI_RESULT))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    U8 *buf_ptr;
    S32 ret;
    media_vid_seek_req_struct seek_data;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_NON_BLOCK_SEEK_AND_GET_FRAME);   

    SetProtocolEventHandler(mdi_video_ply_non_block_seek_result_hdlr, MSG_ID_MEDIA_VID_SEEK_DONE_IND);

    mdi_video_p->is_seek_after_open = TRUE;
    mdi_video_play_seek_result_callback = seek_result_callback;

    gdi_layer_push_and_set_active(player_layer_handle);

    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    gdi_layer_pop_and_restore_active();

    seek_data.time = time;
    seek_data.get_frame = TRUE;
    seek_data.display_width = layer_width;
    seek_data.display_height = layer_height;
    seek_data.display_offset_x = 0;
    seek_data.display_offset_y = 0;
    seek_data.image_buffer_p = (void*)buf_ptr;
    seek_data.image_buffer_size = (layer_width * layer_height * GDI_LAYER.act_bit_per_pixel) >> 3;
    seek_data.blocking = FALSE;
    seek_data.seq_num = g_mdi_video_cntx.seek_seq_num;

#if defined(MDI_VIDEO_MT6228_SERIES)
    seek_data.tv_output = FALSE;
    seek_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    seek_data.image_pitch_bytes = 0; /* not used */
#endif /* MDI_VIDEO_MT6228_SERIES */  

#ifdef __MMI_TVOUT__
    /* TV out */
    if (mdi_tvout_is_enable())
    {
        if (mdi_tvout_get_owner() == MDI_TV_OWNER_VIDEO)
        {
            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_VIDEO,
                    NULL,   /* mode_ptr */
                    NULL,   /* buf_width_ptr */
                    NULL,   /* buf_height_ptr */
                    (PU32) & seek_data.tv_output_buffer_size,  /* buf size */
                    (PU8*) & seek_data.tv_output_buffer1_address,     /* buf1 pp */
                    (PU8*) & seek_data.tv_output_buffer2_address,     /* buf2 pp */
                    NULL,   /* rotate_buf_1_pp */
                    NULL);  /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                seek_data.tv_output = TRUE;
            }
            else
            {
                seek_data.tv_output = FALSE;
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    ret = media_vid_seek(module_id, &seek_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_PDL_VIDEO_UNDERFLOW)
    {
        return MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH;        
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_SEEK_FAILED;
    }

    g_mdi_video_cntx.is_seeking = TRUE;

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    g_mdi_video_cntx.dummy_cur_time = time;
    mdi_video_play_seek_result_callback = seek_result_callback;
    gui_start_timer(100, mdi_video_ply_dummy_non_block_seek_result_hdlr);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_stop_non_block_seek
 * DESCRIPTION
 *  stop non block seeking
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_stop_non_block_seek(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_STOP_NON_BLOCK_SEEK);   

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    g_mdi_video_cntx.seek_seq_num++;

    if (g_mdi_video_cntx.is_seeking == TRUE)
    {
        media_vid_stop(module_id);
        g_mdi_video_cntx.is_seeking = FALSE;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_non_block_seek_result_hdlr
 * DESCRIPTION
 *  seek result message hdlr
 * PARAMETERS
 *  msgPtr          [?]         
 *  msg_ptr(?)      [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_non_block_seek_result_hdlr(void *msgPtr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_done_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_STOP_NON_BLOCK_SEEK_RESULT_HDLR);   

    ind_p = (media_vid_seek_done_ind_struct*) msgPtr;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);    

    if (ind_p->seq_num != g_mdi_video_cntx.seek_seq_num)
    {
        /* 
         * this case will happened when meida already send out file_ready_ind_msg, 
         * but before MDI receive this msg, MDI already ask media to stop seeking. 
         * So the seq_num cant match.  
         */
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);            
        return;
    }

    g_mdi_video_cntx.is_seeking = FALSE;

    if (mdi_video_play_seek_result_callback != NULL)
    {
        if (ind_p->result == MED_RES_OK)
        {
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_SUCCEED);
        }
        else if (ind_p->result == MED_RES_VIDEO_SEEK_PARTIAL_DONE)
        {
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_SEEK_PARTIAL_DONE);
        }
        else
        {
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_ERR_SEEK_FAILED);
        }
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_drm_consume_callback
 * DESCRIPTION
 *  drm callback
 * PARAMETERS
 *  result      [IN]        result, currently, it means time consumed.
 *  id          [IN]        id
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_drm_consume_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* video is playing and drm is consuming.. */
    if (mdi_video_p->is_playing &&
        mdi_video_p->drm_state == MDI_VIDEO_DRM_CONSUMING)
    {
        /* stop video playing */
        mdi_video_ply_stop();

        /* notfiy caller */
        if (mdi_video_ply_play_finish_callback != NULL)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ERR_DRM_DURATION_USED);
        }
    }

}
#endif /* __DRM_SUPPORT__ */



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_cur_play_time
 * DESCRIPTION
 *  get current play time
 * PARAMETERS
 *  cur_play_time       [OUT]       Current play time
 * RETURNS
 *  MDI_RESULT(?)
 *****************************************************************************/
void mdi_video_ply_get_cur_play_time(U64 *cur_play_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_GET_CUR_PLAY_TIME); 

    media_vid_get_current_play_time(module_id, cur_play_time);

    {
        U32 cur_time = (U32)*cur_play_time;
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_CUR_TIME, (U32)cur_time); 
    }
#else 
    *cur_play_time = g_mdi_video_cntx.dummy_cur_time;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_play_finish_result_hdlr
 * DESCRIPTION
 *  play finish result message handler
 * PARAMETERS
 *  msgPtr      [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_ply_play_finish_result_hdlr(void *msgPtr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_finish_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_PLAY_FINISH_RESULT_HDLR);   

    ind_p = (media_vid_play_finish_ind_struct*) msgPtr;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);    
    
    /* seq number not match, measn it is already stopped, ignore this message */
    if (g_mdi_video_cntx.play_seq_num != ind_p->seq_num)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);           
        return;
    }
    
    g_mdi_video_cntx.is_playing = FALSE;

    if (ind_p->result == MED_RES_VIDEO_END)
    {
        /* A>V case, video end first. driver will not update LCM, need to change owner */
    #ifdef __MMI_TVOUT__
        if (mdi_tvout_is_enable())
        {
            /* restore to previous owner */
            if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
            {
                mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
            }
        }
    #endif /* __MMI_TVOUT__ */ 

        return;
    }

    /* un-freeze sublcd */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_freeze(FALSE);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

#ifdef __DRM_SUPPORT__
    ASSERT(mdi_video_p->drm_state == MDI_VIDEO_DRM_CONSUMING || 
           mdi_video_p->drm_state == MDI_VIDEO_DRM_EXIT)

    /* stop consume */
    if (mdi_video_p->drm_state == MDI_VIDEO_DRM_CONSUMING)
    {
        ASSERT(mdi_video_p->drm_id != MDI_VIDEO_DRM_INVALID_VALUE);
        DRM_stop_consume(mdi_video_p->drm_id);
        mdi_video_p->drm_id = MDI_VIDEO_DRM_INVALID_VALUE;
        mdi_video_p->drm_state = MDI_VIDEO_DRM_PLAY_FINISHED;
    }
#endif /* __DRM_SUPPORT__ */

    if (mdi_video_ply_play_finish_callback != NULL)
    {
        if (ind_p->result == MED_RES_OK)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_SUCCEED);
        }
        else if (ind_p->result == MED_RES_REACH_STOP_TIME)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_REACH_STOP_TIME);
        }        
        else if (ind_p->result == MED_RES_PDL_AUDIO_UNDERFLOW || 
                 ind_p->result == MED_RES_PDL_VIDEO_UNDERFLOW)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH);
        }
        else
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ERR_PLAY_FAILED);
        }

        /* MDI_RES_VDOPLY_ERR_PDL_FILE_NOT_ENOUGH */
    }

    g_mdi_video_cntx.is_enable_partial_display = FALSE;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_file_result_hdlr
 * DESCRIPTION
 *  record result message hdlr
 * PARAMETERS
 *  msgPtr          [?]         
 *  msg_ptr(?)      [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_open_file_result_hdlr(void *msgPtr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct vdo_clip;
    media_vid_file_ready_ind_struct *ind_p;
    module_type module_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_OPEN_FILE_RESULT_HDLR);   

    ind_p = (media_vid_file_ready_ind_struct*) msgPtr;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);
    
    memset(&vdo_clip, 0, sizeof(mdi_video_info_struct));
    
    if (ind_p->seq_num != g_mdi_video_cntx.open_seq_num)
    {
        /* 
         * this case will happened when meida already send out file_ready_ind_msg, 
         * but before MDI receive this msg, MDI already ask media to close file. 
         * So the seq_num cant match.  
         */
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);            
        return;
    }

    /* get module id after checking seq num */
    module_id = mdi_video_get_module_id();

    if (ind_p->result == MED_RES_OK ||
        ind_p->result == MED_RES_MP4_NO_VIDEO_TRACK)
    {
        /* init brightness/contrast */
        mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);

        /* get aud profile */
        media_vid_get_audio_profile(module_id, &vdo_clip.aud_channel_no, &vdo_clip.aud_sample_rate);        
       
        if(ind_p->result == MED_RES_MP4_NO_VIDEO_TRACK)
        {
            vdo_clip.width = 10;
            vdo_clip.height = 10;
            vdo_clip.track = MDI_VIDEO_TRACK_A_ONLY;
        	vdo_clip.handle = ind_p->handle;
            vdo_clip.is_seekable = MMI_TRUE;
            g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_A_ONLY;            
        }
        else
        {
            vdo_clip.width = ind_p->image_width;
            vdo_clip.height = ind_p->image_height;
            vdo_clip.track = MDI_VIDEO_TRACK_AV;
        	vdo_clip.handle = ind_p->handle;
            vdo_clip.is_seekable = MMI_TRUE;            
            g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;            
        }

        vdo_clip.total_time_duration = ind_p->total_time;

        mdi_video_ply_open_file_result_callback(MDI_RES_VDOPLY_SUCCEED, &vdo_clip);
    }
    else
    {
        vdo_clip.width = 0;
        vdo_clip.height = 0;
        vdo_clip.total_time_duration = 0;
        vdo_clip.track = MDI_VIDEO_TRACK_AV;    
        vdo_clip.is_seekable = MMI_TRUE;            
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;   
        g_mdi_video_cntx.is_consume_drm_count = TRUE;
        
        mdi_video_ply_open_file_result_callback(MDI_RES_VDOPLY_ERR_FAILED, &vdo_clip);
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_lcm_update
 * DESCRIPTION
 *  set video update to lcm or not
 * PARAMETERS
 *  is_update       [IN]        Update flag
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_lcm_update(BOOL is_update)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MED_RES_OK;
    media_vid_set_display_req_struct disp_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SET_LCM_UPDATE, is_update);   


    if (g_mdi_video_cntx.lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {    
        /* video display on mainlcd, freeze and unfreeze sublcd */
    #ifdef __MMI_SUBLCD__
        if (is_update)
        {
            /* mainlcd will start to update, freeze sublcd */
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_freeze(TRUE);
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        }
        else
        {
            /* mainlcd do not update, unfreeze sublcd */
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_freeze(FALSE);
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        }
    #endif /* __MMI_SUBLCD__ */ 

        if (is_update)
        {
            disp_data.device = MED_DISPLAY_TO_MAIN_LCD;
            ret = media_vid_set_display(module_id, &disp_data);
        }
        else
        {
            disp_data.device = MED_DISPLAY_NONE;        
            ret = media_vid_set_display(module_id, &disp_data);
        }

    }
    else if (g_mdi_video_cntx.lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
       /* video display on sublcd, freeze and unfreeze mainlcd */
        if (is_update)
        {
            /* sublcd will start to update, freeze mainlcd */
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            gdi_lcd_freeze(TRUE);
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        }
        else
        {
            /* sublcd do not update, unfreeze mainlcd */
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            gdi_lcd_freeze(FALSE);
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        }

        if (is_update)
        {
            disp_data.device = MED_DISPLAY_TO_SUB_LCD;
            ret = media_vid_set_display(module_id, &disp_data);
        }
        else
        {
            disp_data.device = MED_DISPLAY_NONE;        
            ret = media_vid_set_display(module_id, &disp_data);
        }
        
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOPLY_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_brightness
 * DESCRIPTION
 *  set brightness
 * PARAMETERS
 *  brightness      [IN]        Brightness value
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_brightness(U16 brightness)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_param_req_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SET_BRIGHTNESS, brightness);   
    
    data.param_id = VID_PARAM_BRIGHTNESS;

    switch (brightness)
    {
        case MDI_VIDEO_BRIGHTNESS_N5:
            data.value = 8; /* -120 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N4:
            data.value = 38;    /* -90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N3:
            data.value = 68;    /* -60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N2:
            data.value = 98;    /* -30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N1:
            data.value = 118;   /* -10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_0:
            data.value = 128;   /* 0 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P1:
            data.value = 138;   /* +10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P2:
            data.value = 158;   /* +30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P3:
            data.value = 188;   /* +60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P4:
            data.value = 218;   /* +90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P5:
            data.value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

    media_vid_set_param(module_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_contrast
 * DESCRIPTION
 *  set contrast
 * PARAMETERS
 *  contrast        [IN]        Contrast value
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_contrast(U16 contrast)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_param_req_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SET_CONTRAST, contrast);   
    
    data.param_id = VID_PARAM_CONTRAST;

    switch (contrast)
    {
        case MDI_VIDEO_CONTRAST_N5:
            data.value = 8; /* -120 */
            break;

        case MDI_VIDEO_CONTRAST_N4:
            data.value = 38;    /* -90 */
            break;

        case MDI_VIDEO_CONTRAST_N3:
            data.value = 68;    /* -60 */
            break;

        case MDI_VIDEO_CONTRAST_N2:
            data.value = 98;    /* -30 */
            break;

        case MDI_VIDEO_CONTRAST_N1:
            data.value = 118;   /* -10 */
            break;

        case MDI_VIDEO_CONTRAST_0:
            data.value = 128;   /* 0 */
            break;

        case MDI_VIDEO_CONTRAST_P1:
            data.value = 138;   /* +10 */
            break;

        case MDI_VIDEO_CONTRAST_P2:
            data.value = 158;   /* +30 */
            break;

        case MDI_VIDEO_CONTRAST_P3:
            data.value = 188;   /* +60 */
            break;

        case MDI_VIDEO_CONTRAST_P4:
            data.value = 218;   /* +90 */
            break;

        case MDI_VIDEO_CONTRAST_P5:
            data.value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    } 

    media_vid_set_param(module_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}



/****************************************************************************
*
* VIDEO CLIP                                                                 
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_file
 * DESCRIPTION
 *  open video clip, this is a blocking function, will return untill file is opened
 * PARAMETERS
 *  filename                    [IN]        Video clip's full file name
 *  info                        [OUT]       Video clip's info
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_clip_file(const S8 *filename, mdi_video_info_struct *info)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_open_req_struct open_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_OPEN_CLIP_FILE);   

    /* un-hook open file done hdlr */
    if (module_id == MOD_MMI)
    {
        SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VID_FILE_READY_IND);
    }

#ifdef __DRM_SUPPORT__
    ASSERT(mdi_video_p->drm_state == MDI_VIDEO_DRM_EXIT);
    ASSERT(mdi_video_p->drm_file_h == NULL);

    mdi_video_p->is_drm_file = FALSE;
    mdi_video_p->drm_file_h = DRM_open_file((PU16)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    if (mdi_video_p->drm_file_h > FS_NO_ERROR)
    {
        /* check if it is DRM file or not */
        if (DRM_get_object_method(mdi_video_p->drm_file_h, NULL) != DRM_METHOD_NONE)
        {
            if (mdi_video_p->is_consume_drm_count)
            {              
                /* is DRM file, now check permission  */
                if (DRM_validate_permission(mdi_video_p->drm_file_h, NULL, DRM_PERMISSION_PLAY))
                {
                    /* has permission */
                    mdi_video_p->drm_state = MDI_VIDEO_DRM_PERMITTED;
                    mdi_video_p->is_drm_file = TRUE;                                   
                }   
                else
                {
                    /* it is DRM file, but no rights */
                    DRM_close_file(mdi_video_p->drm_file_h);                
                    mdi_video_p->drm_file_h = NULL;      
                    return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
                }
            }
            else
            {
                mdi_video_p->drm_state = MDI_VIDEO_DRM_PERMITTED;
            }            
        }
        else
        {
            /* not DRM file... close file handle */
            DRM_close_file(mdi_video_p->drm_file_h);
            mdi_video_p->drm_file_h = NULL;            
        }
     
    }
    else if (mdi_video_p->drm_file_h == DRM_RESULT_NO_PERMISSION)
    {
        mdi_video_p->drm_file_h = NULL;
        return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
    }     
    else
    {
        /* open file failed */
        mdi_video_p->drm_file_h = NULL;
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
#endif /* __DRM_SUPPORT__ */

    open_data.enable_aud_only = g_mdi_video_cntx.is_enable_aud_only;
    open_data.media_mode = MED_MODE_FILE;
    g_mdi_video_cntx.is_enable_aud_only = FALSE;

    open_data.data = (void*)filename;

#if defined(MDI_VIDEO_MT6228_SERIES)
    open_data.max_width = 352;  /* CIF width  - max decodable size */
    open_data.max_height = 288; /* CIF height - max decodable size */
#else /* MDI_VIDEO_MT6228_SERIES */ 
    /* MT6219 */
    open_data.max_width = 176;  /* QCIF width  - max decodable size */
    open_data.max_height = 144; /* QCIF height - max decodable size */
#endif /* MDI_VIDEO_MT6228_SERIES */ 

    open_data.play_audio = (U8)TRUE;    /* TODO: this shall be removed - not used */
    open_data.seq_num = g_mdi_video_cntx.open_seq_num;
    open_data.blocking = TRUE;
    open_data.image_width = &info->width;
    open_data.image_height = &info->height;
    open_data.total_time = &info->total_time_duration;
    open_data.handle = NULL;

#ifdef __SF_MP4_SUPPORT__
    open_data.media_type = (kal_uint8)mmi_fmgr_get_file_type_by_filename((S8*)filename);
#endif //__SF_MP4_SUPPORT__

    ret = media_vid_open(module_id, &open_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

#ifdef __SF_MP4_SUPPORT__
    info->width = 176;
    info->height = 144;   
#endif //__SF_MP4_SUPPORT__ 

    if (ret == MED_RES_MP4_NO_VIDEO_TRACK)
    {
        info->track = MDI_VIDEO_TRACK_A_ONLY;   
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_A_ONLY;
        ret = MED_RES_OK;
    }
    else
    {
        info->track = MDI_VIDEO_TRACK_AV;   
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;
    }

    if (ret != MED_RES_OK)
    {
    #ifdef __DRM_SUPPORT__
        /* close and restore DRM files */
        mdi_video_p->is_consume_drm_count = TRUE;
        mdi_video_p->is_drm_file = FALSE;             
        mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;
        
        if (mdi_video_p->drm_file_h != NULL)
        {
            DRM_close_file(mdi_video_p->drm_file_h);
            mdi_video_p->drm_file_h = NULL;        
        }
    #endif /* __DRM_SUPPORT__ */
        
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    else
    {
        /* init brightness/contrast */
        mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);

        return MDI_RES_VDOPLY_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    {
        info->width = 176;
        info->height = 144;
        info->total_time_duration = 30;
        info->track = MDI_VIDEO_TRACK_AV;   
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;

        return MDI_RES_VDOPLY_SUCCEED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_clip_file
 * DESCRIPTION
 *  close video clip
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_close_clip_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct close_data;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_CLOSE_CLIP_FILE);   

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    g_mdi_video_cntx.open_seq_num++;

    close_data.handle = 0;
    close_data.media_mode = MED_MODE_FILE;

    media_vid_close(module_id, &close_data);
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

#ifdef __DRM_SUPPORT__
    if (mdi_video_p->drm_state == MDI_VIDEO_DRM_PAUSED)
    {
        ASSERT(mdi_video_p->drm_id != MDI_VIDEO_DRM_INVALID_VALUE)
        DRM_stop_consume(mdi_video_p->drm_id);
        mdi_video_p->drm_id = MDI_VIDEO_DRM_INVALID_VALUE;
        mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;        
    }
    else if (mdi_video_p->drm_state == MDI_VIDEO_DRM_PLAY_FINISHED || 
             mdi_video_p->drm_state == MDI_VIDEO_DRM_PERMITTED)
    {
        mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;   
    }

    if (mdi_video_p->drm_file_h != NULL)
    {
        DRM_close_file(mdi_video_p->drm_file_h);
        mdi_video_p->drm_file_h = NULL;   
    }

    mdi_video_p->is_consume_drm_count = TRUE;  
    mdi_video_p->is_drm_file = FALSE;     
#endif /* __DRM_SUPPORT__ */

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_id
 * DESCRIPTION
 *  open video clip
 * PARAMETERS
 *  video_id                    [IN]        Video clip resource id
 *  info                        [OUT]       Video clip's info
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_clip_id(U16 video_id, mdi_video_info_struct *info)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_open_req_struct open_data;
    PS8 vdo_ptr;
    S32 vdo_len;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_OPEN_CLIP_ID);   

    /* un-hook open file done hdlr */
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VID_FILE_READY_IND);

    /* get raw data by ID */
    vdo_ptr = GetMedia(video_id);

    if (vdo_ptr == NULL)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    switch (*vdo_ptr)
    {
        case IMAGE_TYPE_AVI:
            open_data.media_type = MED_TYPE_MJPG;
            break;

        case IMAGE_TYPE_3GP:
            open_data.media_type = MED_TYPE_3GP;
            break;

        case IMAGE_TYPE_MP4:
            open_data.media_type = MED_TYPE_MP4;
            break;

        default:
            return MDI_RES_VDOPLY_ERR_FAILED;
    }

    /* get video data length size */
    vdo_len = (S32) (vdo_ptr[2]);
    vdo_len |= (S32) ((S32) vdo_ptr[3] << 8);
    vdo_len |= (S32) ((S32) vdo_ptr[4] << 16);
    vdo_len |= (S32) ((S32) vdo_ptr[5] << 24);


    open_data.enable_aud_only = g_mdi_video_cntx.is_enable_aud_only;
    open_data.media_mode = MED_MODE_ARRAY;
    g_mdi_video_cntx.is_enable_aud_only = FALSE;
    
    open_data.data = (void*)(vdo_ptr + 8);
    open_data.data_size = vdo_len;

#if defined(MDI_VIDEO_MT6228_SERIES)
    open_data.max_width = 352;  /* CIF width  - max decodable size */
    open_data.max_height = 288; /* CIF height - max decodable size */
#else /* MDI_VIDEO_MT6228_SERIES */ 
    /* MT6219 */
    open_data.max_width = 176;  /* QCIF width  - max decodable size */
    open_data.max_height = 144; /* QCIF height - max decodable size */
#endif /* MDI_VIDEO_MT6228_SERIES */ 

    open_data.play_audio = (U8)TRUE;
    open_data.seq_num = g_mdi_video_cntx.open_seq_num;
    open_data.blocking = TRUE;
    open_data.image_width = &info->width;
    open_data.image_height = &info->height;
    open_data.total_time = &info->total_time_duration;
    open_data.handle = NULL;

    ret = media_vid_open(module_id, &open_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    
    
    if (ret == MED_RES_MP4_NO_VIDEO_TRACK)
    {
        info->track = MDI_VIDEO_TRACK_A_ONLY;   
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_A_ONLY;
        ret = MED_RES_OK;
    }
    else
    {
        info->track = MDI_VIDEO_TRACK_AV;   
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;
    }

    if (ret != MED_RES_OK)
    {   
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    else
    {
        /* init brightness/contrast */
        mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);

        return MDI_RES_VDOPLY_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    info->width = 176;
    info->height = 144;
    info->total_time_duration = 30;
    info->track = MDI_VIDEO_TRACK_AV;   
    g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;

    return MDI_RES_VDOPLY_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_clip_id
 * DESCRIPTION
 *  close video clip from id
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_close_clip_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct close_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_CLOSE_CLIP_ID);   

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    g_mdi_video_cntx.open_seq_num++;
    
    close_data.handle = 0;
    close_data.media_mode = MED_MODE_ARRAY;

    media_vid_close(module_id, &close_data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_buffer
 * DESCRIPTION
 *  open video clip from buffer
 * PARAMETERS
 *  file_buffer                 [IN]        Video clip file buffer
 *  buffer_len                  [IN]        Video clip's buffer size
 *  info                        [OUT]       Video clip's info
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_clip_buffer(
            const U8 *file_buffer, 
            const U32 buffer_len, 
            mdi_video_info_struct *info)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_open_req_struct open_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_OPEN_CLIP_BUFFER);   

    /* un-hook open file done hdlr */
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VID_FILE_READY_IND);
 
    open_data.media_type = MED_TYPE_3GP;
    open_data.enable_aud_only = g_mdi_video_cntx.is_enable_aud_only;
    open_data.media_mode = MED_MODE_ARRAY;
    g_mdi_video_cntx.is_enable_aud_only = FALSE;
    
    open_data.data = (void*)file_buffer;
    open_data.data_size = buffer_len;

#if defined(MDI_VIDEO_MT6228_SERIES)
    open_data.max_width = 352;  /* CIF width  - max decodable size */
    open_data.max_height = 288; /* CIF height - max decodable size */
#else /* MDI_VIDEO_MT6228_SERIES */ 
    /* MT6219 */
    open_data.max_width = 176;  /* QCIF width  - max decodable size */
    open_data.max_height = 144; /* QCIF height - max decodable size */
#endif /* MDI_VIDEO_MT6228_SERIES */ 

    open_data.play_audio = (U8)TRUE;
    open_data.seq_num = g_mdi_video_cntx.open_seq_num;
    open_data.blocking = TRUE;
    open_data.image_width = &info->width;
    open_data.image_height = &info->height;
    open_data.total_time = &info->total_time_duration;
    open_data.handle = NULL;

    ret = media_vid_open(module_id, &open_data);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_MP4_NO_VIDEO_TRACK)
    {
        info->track = MDI_VIDEO_TRACK_A_ONLY;   
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_A_ONLY;
        ret = MED_RES_OK;
    }
    else
    {
        info->track = MDI_VIDEO_TRACK_AV;   
        g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;
    }

    if (ret != MED_RES_OK)
    {   
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    else
    {
        /* init brightness/contrast */
        mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);

        return MDI_RES_VDOPLY_SUCCEED;
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_clip_buffer
 * DESCRIPTION
 *  close video clip from buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_close_clip_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct close_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_CLOSE_CLIP_BUFFER);

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    g_mdi_video_cntx.open_seq_num++;
    
    close_data.handle = 0;
    close_data.media_mode = MED_MODE_ARRAY;

    media_vid_close(module_id, &close_data);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_enable_aud_only_video_clip
 * DESCRIPTION
 *  enable aud only video file 
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_enable_aud_only_video_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//  MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_ENABLE_PARTIAL_DISPLAY);       
    
    g_mdi_video_cntx.is_enable_aud_only = TRUE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_enable_partial_display
 * DESCRIPTION
 *  enable video to play outside lcd region
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_enable_partial_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_ENABLE_PARTIAL_DISPLAY);       
    
    g_mdi_video_cntx.is_enable_partial_display = TRUE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_drm_disable_consume_count
 * DESCRIPTION
 *  Do not consume drm count when open. Call this function before calling
 *  open function.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_drm_disable_consume_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: add trace */     
    
    mdi_video_p->is_consume_drm_count = FALSE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_is_drm_file
 * DESCRIPTION
 *  Check if it is drm file or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_video_ply_is_drm_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)mdi_video_p->is_drm_file;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_stop_time
 * DESCRIPTION
 *  Set stop time, currently for Java use only
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_stop_time(U64 stop_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_set_stop_time_req_struct stop_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SET_STOP_TIME);       
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STOP_TIME, (U32)stop_time);    

    stop_data.stop_time = stop_time;
    media_vid_set_stop_time(module_id, &stop_data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_audio_level
 * DESCRIPTION
 *  Set audio level, used by Java only
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_audio_level(U16 aud_level)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(aud_level <= 100);
    media_vid_set_volume_level(module_id, aud_level);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_set_overlay_palette
 * DESCRIPTION
 *  set overlay palette
 * PARAMETERS
 *  palette_size            [IN]        
 *  palette_addr_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_set_overlay_palette(U8 palette_size, U32 *palette_addr_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PLY_SET_OVERLAY_PALETTE);   
    media_vid_set_overlay_palette(module_id, (kal_uint8) palette_size, (kal_uint32*) palette_addr_ptr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_is_playing
 * DESCRIPTION
 *  is currently playing or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mdi_video_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mdi_video_cntx.is_playing;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_is_recording
 * DESCRIPTION
 *  is currently recording or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mdi_video_is_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mdi_video_cntx.is_recording;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_blocked_recovery
 * DESCRIPTION
 *  This function will be called by mdi_switch_device_ownership when someone
 *  switch device ownership.
 *  When switching ownership, we will force media task to termiate all action
 *  and back to idle. MDI also need restore state to idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_blocked_recovery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_STREAM__    
    module_type module_id = mdi_video_get_module_id();
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_BLOCKED_RECOVERY);  

#ifdef __MMI_VIDEO_STREAM__
    if(g_mdi_video_cntx.is_stream_init)
    {
    #ifdef MDI_VIDEO_DRIVER_AVAIALBE
        media_stream_force_abort(module_id ,g_mdi_video_cntx.stream_session_id);
    #endif 
        g_mdi_video_cntx.is_stream_init = FALSE;
        g_mdi_video_cntx.is_stream_connected = FALSE;        
    }
#endif /* __MMI_VIDEO_STREAM__ */
    
    g_mdi_video_cntx.record_seq_num++;
    g_mdi_video_cntx.play_seq_num++;

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

#ifdef __DRM_SUPPORT__
    switch (mdi_video_p->drm_state)
    {
        case MDI_VIDEO_DRM_PAUSED:
        case MDI_VIDEO_DRM_CONSUMING:
            ASSERT(mdi_video_p->drm_id != MDI_VIDEO_DRM_INVALID_VALUE)
            DRM_stop_consume(mdi_video_p->drm_id);
            mdi_video_p->drm_id = MDI_VIDEO_DRM_INVALID_VALUE;
            mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;   
            break;

        case MDI_VIDEO_DRM_PLAY_FINISHED:
        case MDI_VIDEO_DRM_PERMITTED:
            mdi_video_p->drm_state = MDI_VIDEO_DRM_EXIT;               
            break;
            
        case MDI_VIDEO_DRM_EXIT:
            /* do nothing */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    
    if (mdi_video_p->drm_file_h != NULL)
    {
        DRM_close_file(mdi_video_p->drm_file_h);
        mdi_video_p->drm_file_h = NULL;   
    }

    mdi_video_p->is_consume_drm_count = TRUE;    
#endif /* __DRM_SUPPORT__ */

}



/*****************************************************************************
 *
 * Streaming
 *
 *****************************************************************************/
#ifdef __MMI_VIDEO_STREAM__  
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_init
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_init(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_INIT);  

    ret = media_stream_init(module_id, &g_mdi_video_cntx.stream_session_id);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    if (ret == MED_RES_OK)
    {
        g_mdi_video_cntx.is_stream_init = TRUE;        
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else
    {
        g_mdi_video_cntx.is_stream_init = FALSE;        
        return MDI_RES_VDOPLY_ERR_FAILED;           
    }
#else
    return MDI_RES_VDOPLY_SUCCEED; 
#endif     
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_deinit
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_deinit(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_DEINIT);  

    ret = media_stream_deinit(module_id, g_mdi_video_cntx.stream_session_id);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    

    g_mdi_video_cntx.is_stream_init = FALSE;        
    
    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;           
    }
#else
    return MDI_RES_VDOPLY_SUCCEED; 
#endif         
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_connect
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_connect(
            U8 data_account, 
            mdi_video_stream_type_enum stream_type, 
            S8 *data_path,
            MMI_BOOL use_proxy,
            U8 *proxy,
            U16 port,
            MMI_BOOL use_udp_port,
            U16 highest_udp_port,
            U16 lowest_udp_port,            
            void (*connect_result_callback)(MDI_RESULT, mdi_video_info_struct*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 type = 0;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_CONNECT);      

    mdi_video_stream_connect_result_callback = connect_result_callback;

    SetProtocolEventHandler(mdi_video_stream_connect_result_hdlr, MSG_ID_MEDIA_STREAM_CONNECTED_IND);

    if (stream_type == MDI_VIDEO_STREAM_RTSP_URL)
    {
        type = MEDIA_STREAM_CONN_TYPE_RTSP_URL;
    }
    else if(stream_type == MDI_VIDEO_STREAM_SDP_FILE)
    {
        type = MEDIA_STREAM_CONN_TYPE_SDP_FILE;
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    g_mdi_video_cntx.is_stream_connected = FALSE;

    if (!use_udp_port)
    {
        /* application didnt assign udp port, use default */
        highest_udp_port = 65535;
        lowest_udp_port = 6000;
    }
    
    ret = media_stream_connect(
             module_id,
             (kal_uint8)g_mdi_video_cntx.stream_session_id,
             (kal_uint8)g_mdi_video_cntx.connect_seq_num,
             (kal_uint8)data_account,
             (kal_uint8)type,   
             (kal_wchar*)data_path,
             (kal_bool)use_proxy,
             (kal_uint8*)proxy,
             (kal_uint16)port,
             (kal_uint16)lowest_udp_port,
             (kal_uint16)highest_udp_port);
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    
    
    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;           
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    g_mdi_video_cntx.dummy_counter = 0;

    mdi_video_stream_connect_result_callback = connect_result_callback;
    gui_start_timer(3000, mdi_video_stream_dummy_connect_result_hdlr);
    return MDI_RES_VDOPLY_SUCCEED;        
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */    

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_connect_result_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_stream_connect_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_connected_ind_struct *ind_p;
    mdi_video_info_struct video_info;
    media_stream_get_info_struct stream_info;
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_CONNECT_RESULT_HDLR);   
    MMI_ASSERT(mdi_video_stream_connect_result_callback != NULL);

    ind_p = (media_stream_connected_ind_struct*)msg_ptr;
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);   


    /* seq number not match, measn it is already disconnected, ignore this message */
    if (g_mdi_video_cntx.connect_seq_num != ind_p->request_id)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);   
        return;
    }

    /* get module id after seq check */
    module_id = mdi_video_get_module_id();

    if (ind_p->result == MED_RES_OK)
    {
        g_mdi_video_cntx.is_stream_connected = TRUE;        
        
        /* 
         * in connect result, we can get 
         * (1) track type
         * (2) total time (media len)
         * (3) seekable or not,
         * other info will get from seek(buffering) result
         */
         
        if ((ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_AUDIO) &&
            (ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_VIDEO))
        {
            /* A/V */
            g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;
        }
        else if (ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_AUDIO)
        {
            /* A only */
            g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_A_ONLY;
        }
        else if (ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_VIDEO)
        {
            /* V only */
            g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_V_ONLY;            
        }
        else
        {
            MMI_ASSERT(0);
        }

        g_mdi_video_cntx.video_info.total_time_duration = ind_p->media_len;        
        g_mdi_video_cntx.video_info.is_seekable = (MMI_BOOL)ind_p->seekable;


        /* when connect done, may only get aud channel no and sample rate */
        media_stream_get_info(module_id, g_mdi_video_cntx.stream_session_id, &stream_info);
        g_mdi_video_cntx.video_info.aud_channel_no = stream_info.channel_num;
        g_mdi_video_cntx.video_info.aud_sample_rate = stream_info.sampleing_freq;
            
        strcpy((kal_char*)&g_mdi_video_cntx.video_info.title_name, (kal_char*)&ind_p->title);
        
        memset(&video_info, 0, sizeof(mdi_video_info_struct));
        video_info.total_time_duration = g_mdi_video_cntx.video_info.total_time_duration;
        video_info.is_seekable = g_mdi_video_cntx.video_info.is_seekable;
        video_info.track = g_mdi_video_cntx.video_info.track;
        video_info.aud_channel_no = g_mdi_video_cntx.video_info.aud_channel_no;
        video_info.aud_sample_rate = g_mdi_video_cntx.video_info.aud_sample_rate;
        
        strcpy((kal_char*)&video_info.title_name, (kal_char*)&g_mdi_video_cntx.video_info.title_name);

        /* init brightness and contrast */
        mdi_video_stream_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_stream_set_contrast(MDI_VIDEO_CONTRAST_0);     
            
        mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_SUCCEED, &video_info);
    }
    else if (ind_p->result == MED_RES_STREAM_BEARER_DISCONNECTED ||
             ind_p->result == MED_RES_STREAM_RTSP_REQUEST_FAIL)
    {
        mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT, &video_info);    
    }
    else
    {
        mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_ERR_FAILED, &video_info);
    }
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_connect_result_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_connect_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct video_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_info.total_time_duration = 0;
    video_info.is_seekable = FALSE;
    video_info.track = MDI_VIDEO_TRACK_AV;
    
    mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_SUCCEED, &video_info);
}
#endif /* !defined(MDI_VIDEO_DRIVER_AVAIALBE) */



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_disconnect
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_disconnect(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE     
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_DISCONNECT);      
    g_mdi_video_cntx.connect_seq_num++;

    if (g_mdi_video_cntx.is_stream_connected)
    {
        ret = media_stream_disconnect(module_id, g_mdi_video_cntx.stream_session_id);
    }
    else
    {
        ret = media_stream_abort(module_id, g_mdi_video_cntx.stream_session_id);
    }
   
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    g_mdi_video_cntx.is_stream_connected = FALSE;        

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;           
    }   
   
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    gui_cancel_timer(mdi_video_stream_dummy_connect_result_hdlr);

    return MDI_RES_VDOPLY_SUCCEED;    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */



}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_is_connected
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mdi_video_stream_is_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_IS_CONNECTED); 

    /* not implement yet */
    MMI_ASSERT(0);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_start_buffering
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_start_buffering(
            U64 time, 
            void (*buffering_result_callback)(MDI_RESULT result, mdi_video_info_struct *info))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE        
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_START_BUFFERING); 

    mdi_video_stream_buffering_result_callback = buffering_result_callback;
    SetProtocolEventHandler(mdi_video_stream_buffering_result_hdlr, MSG_ID_MEDIA_STREAM_SEEK_IND);

    ret = media_stream_seek(
            module_id, 
            g_mdi_video_cntx.stream_session_id, 
            g_mdi_video_cntx.buffering_seq_num,
            time);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   
    
    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else if (ret == MED_RES_STREAM_STOP_TIMEOUT)
    {
        return MDI_RES_VDOPLY_REACH_STOP_TIME;    
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;           
    }
   
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    g_mdi_video_cntx.dummy_cur_time = time;
    g_mdi_video_cntx.dummy_loading_percentage = 0;
    mdi_video_stream_buffering_result_callback = buffering_result_callback;
    mdi_video_stream_dummy_start_buffering_cyclic();
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */  

    return MDI_RES_VDOPLY_SUCCEED;    
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_buffering_result_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_stream_buffering_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_seek_ind_struct *ind_p;
    mdi_video_info_struct video_info;
    media_stream_get_info_struct stream_info;
    S32 ret;
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_BUFFERING_RESULT_HDLR);   
    MMI_ASSERT(mdi_video_stream_buffering_result_callback != NULL);

    ind_p = (media_stream_seek_ind_struct*)msg_ptr;
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);   

    /* seq number not match, measn it is already disconnected, ignore this message */
    if (g_mdi_video_cntx.buffering_seq_num != ind_p->request_id)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);   
        return;
    }

    /* increase, due to driver may send multiple buffering result ind, we may only accepet 1 */
    g_mdi_video_cntx.buffering_seq_num++;

    /* get module id after seq check */
    module_id = mdi_video_get_module_id();

    if (ind_p->result == MED_RES_OK)
    {
        memset(&video_info, 0, sizeof(video_info));
        
        ret = media_stream_get_info(module_id, g_mdi_video_cntx.stream_session_id, &stream_info);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

        if (ret == MED_RES_OK)
        {
            video_info.width = stream_info.image_width;
            video_info.height = stream_info.image_height;
            video_info.total_time_duration = g_mdi_video_cntx.video_info.total_time_duration;  
            video_info.track = g_mdi_video_cntx.video_info.track;
            video_info.is_seekable = g_mdi_video_cntx.video_info.is_seekable;        
            video_info.handle = 0;  /* not used in this case */                    
            video_info.aud_channel_no = stream_info.channel_num;
            video_info.aud_sample_rate = stream_info.sampleing_freq;
                
            mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_SUCCEED, &video_info);            
        }
        else if (ret == MED_RES_STREAM_INVALID_RESOLUTION)
        {
            mdi_video_stream_stop_buffering();
            mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_INVALID_RESOULTION, &video_info);            
        }
        else
        {
            mdi_video_stream_stop_buffering();            
            mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_FAILED, &video_info);            
        }
    }
    else if (ind_p->result == MED_RES_STREAM_STOP_TIMEOUT)
    {
        mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_REACH_STOP_TIME, &video_info);    
    }
    else   
    {
        mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_FAILED, &video_info);    
    }
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop_buffering
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_stop_buffering(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_STOP_BUFFERING); 
    
    g_mdi_video_cntx.buffering_seq_num++;

    ret = media_stream_abort(module_id, g_mdi_video_cntx.stream_session_id);
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   
    
    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;           
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    gui_cancel_timer(mdi_video_stream_dummy_start_buffering_cyclic);
    return MDI_RES_VDOPLY_SUCCEED;    
#endif


}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_start_buffering_cyclic
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_start_buffering_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct vdo_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_video_cntx.dummy_loading_percentage < 100)
    {
        g_mdi_video_cntx.dummy_loading_percentage += 10;   
        gui_start_timer(300, mdi_video_stream_dummy_start_buffering_cyclic);
    }
    else
    {
        vdo_clip.width = 176;
        vdo_clip.height = 144;
        vdo_clip.total_time_duration = MDI_VIDEO_DUMMY_TOTAL_TIME;
        vdo_clip.is_seekable = MMI_FALSE;
        vdo_clip.track = MDI_VIDEO_TRACK_AV;
        mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_SUCCEED, &vdo_clip);
    }

}
#endif /* !defined(MDI_VIDEO_DRIVER_AVAIALBE) */


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_play
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_play(
            gdi_handle player_layer_handle, 
            U32 blt_layer_flag,
            U32 play_layer_flag, 
            MMI_BOOL is_visual_update, 
            U8 audio_path, 
            U16 rotate, 
            void (*play_finish_callback) (MDI_RESULT))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_set_info_struct set_info_data;
    S32 ret;
    MMI_BOOL is_tvout = MMI_FALSE;
    mdi_blt_para_struct blt_data;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_PLAY); 

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    /* Connect SCO to output audio to BT earpone */
    mmi_profiles_bt_connect_audio_via_sco();
#endif

#ifdef __MMI_SUBLCD__
    /* Freeze sublcd */
    if (is_visual_update)
    {
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(TRUE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable() && 
        (g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_AV || 
         g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY))
    {
        g_mdi_video_cntx.tvout_prev_owner = mdi_tvout_get_owner();
        
        /* if tvout is on and has V track */
        mdi_tvout_set_owner(MDI_TV_OWNER_VIDEO);        
        is_tvout = MMI_TRUE;        
    }
    else
    {
        is_tvout = MMI_FALSE;
    }
#endif /* __MMI_TVOUT__ */

    mdi_video_stream_play_finish_callback = play_finish_callback;
    SetProtocolEventHandler(mdi_video_stream_play_result_hdlr, MSG_ID_MEDIA_STREAM_PLAY_IND);

    gdi_lcd_get_active(&g_mdi_video_cntx.lcd_handle);
    if (g_mdi_video_cntx.lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        set_info_data.lcd_id = MAIN_LCD;
    }
    else if (g_mdi_video_cntx.lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        set_info_data.lcd_id = SUB_LCD;
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* calc blt paramters */
    mdi_calc_blt_para(
        player_layer_handle, 
        rotate, 
        g_mdi_video_cntx.lcd_handle, 
        is_tvout, 
        &blt_data);

    set_info_data.display_offset_x = 0;         /* not used */
    set_info_data.display_offset_y = 0;         /* not used */
    set_info_data.video_display_offset_x = 0;   /* not used */
    set_info_data.video_display_offset_y = 0;   /* not used */

    /* blt para */
    set_info_data.lcd_start_x = blt_data.lcd_start_x;
    set_info_data.lcd_start_y = blt_data.lcd_start_y;
    set_info_data.lcd_end_x = blt_data.lcd_end_x;
    set_info_data.lcd_end_y = blt_data.lcd_end_y;
    set_info_data.display_width = blt_data.display_width;
    set_info_data.display_height = blt_data.display_height;
    set_info_data.roi_offset_x = blt_data.roi_offset_x;
    set_info_data.roi_offset_y = blt_data.roi_offset_y;    
    set_info_data.image_buffer_p = (void*)blt_data.image_buffer_p;
    set_info_data.image_buffer_size = blt_data.image_buffer_size;
    set_info_data.lcd_rotate = blt_data.lcd_rotate;

#if defined(MDI_VIDEO_MT6228_SERIES)
    set_info_data.image_pitch_mode = FALSE; /* do not use this mode */
    set_info_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    set_info_data.tv_output = blt_data.tv_output;
#endif /* MDI_VIDEO_MT6228_SERIES */ 

#ifdef __MMI_TVOUT__
    set_info_data.tv_output_width = blt_data.tv_output_width;
    set_info_data.tv_output_width = blt_data.tv_output_width;
    set_info_data.tv_output_height = blt_data.tv_output_height;
    set_info_data.tv_output_offset_x = blt_data.tv_output_offset_x;
    set_info_data.tv_output_offset_y = blt_data.tv_output_offset_y;
    set_info_data.tv_output_buffer_size = blt_data.tv_output_buffer_size;
    set_info_data.tv_output_buffer1_address = (kal_uint32)blt_data.tv_output_buffer1_address;
    set_info_data.tv_output_buffer2_address = (kal_uint32)blt_data.tv_output_buffer2_address;
#endif /* __MMI_TVOUT__ */

    set_info_data.update_layer = blt_layer_flag;
    set_info_data.hw_update_layer = play_layer_flag;
    set_info_data.play_audio = (U8)TRUE; 
    set_info_data.play_speed = 100;
    set_info_data.audio_path = audio_path;
    set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    set_info_data.seq_num = g_mdi_video_cntx.play_seq_num;
    set_info_data.repeats = 1;
    /* 
     * Set this to true will force driver to use hw trigger instead of direct couple.
     * Direct couple has better frame rate but cant draw out side of lcd region. 
     */
    set_info_data.force_lcd_hw_trigger = g_mdi_video_cntx.is_enable_partial_display;

    if (is_visual_update)
    {
        set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    }
    else
    {
        set_info_data.display_device = MED_DISPLAY_NONE;
    }

    media_stream_set_info(
        module_id, 
        g_mdi_video_cntx.stream_session_id, 
        &set_info_data);

    ret = media_stream_play(
            module_id, 
            g_mdi_video_cntx.stream_session_id, 
            g_mdi_video_cntx.play_seq_num);
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret == MED_RES_OK)
    {
        g_mdi_video_cntx.is_playing = TRUE;        
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else
    {
    #ifdef __MMI_SUBLCD__
        /* un-freeze sublcd */    
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(FALSE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    #endif /* __MMI_SUBLCD__ */ 

    #ifdef __MMI_TVOUT__
        /* restore TV owner */    
        if (is_tvout)
        {
            /* restore to previous owner */
            if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
            {
                mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
            }
        }
    #endif /* __MMI_TVOUT__ */ 

        if (ret == MED_RES_STREAM_STOP_TIMEOUT)
        {
            return MDI_RES_VDOPLY_REACH_STOP_TIME;    
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_FAILED;                       
        }
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    g_mdi_video_cntx.dummy_counter++;
    g_mdi_video_cntx.dummy_loading_percentage = 0;
    mdi_video_stream_play_finish_callback = play_finish_callback;
	mdi_video_stream_dummy_play_cyclic();
    gui_start_timer(3000, mdi_video_stream_dummy_play_result_hdlr);
    
    return MDI_RES_VDOPLY_SUCCEED;    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 


}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_resume
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_pause(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_PAUSE); 

    media_stream_switch_screen_videostop(module_id, g_mdi_video_cntx.stream_session_id);

    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_RES_VDOPLY_SUCCEED */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_resume
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_resume(
            gdi_handle player_layer_handle, 
            U32 blt_layer_flag,
            U32 play_layer_flag, 
            MMI_BOOL is_visual_update, 
            U8 audio_path, 
            U16 rotate)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_set_info_struct set_info_data;
    MMI_BOOL is_tvout = MMI_FALSE;
    mdi_blt_para_struct blt_data;
    module_type module_id = mdi_video_get_module_id(); 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_RESUME); 

#ifdef __MMI_SUBLCD__
    /* Freeze sublcd */
    if (is_visual_update)
    {
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(TRUE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable() && 
        (g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_AV || 
         g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY))
    {
        g_mdi_video_cntx.tvout_prev_owner = mdi_tvout_get_owner();
        
        /* if tvout is on and has V track */
        mdi_tvout_set_owner(MDI_TV_OWNER_VIDEO);        
        is_tvout = MMI_TRUE;        
    }
    else
    {
        is_tvout = MMI_FALSE;
    }
#endif /* __MMI_TVOUT__ */

    /* calc blt paramters */
    gdi_lcd_get_active(&g_mdi_video_cntx.lcd_handle);
    if (g_mdi_video_cntx.lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        set_info_data.lcd_id = MAIN_LCD;
    }
    else if (g_mdi_video_cntx.lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        set_info_data.lcd_id = SUB_LCD;
    }
    else
    {
        MMI_ASSERT(0);
    }

    mdi_calc_blt_para(
        player_layer_handle, 
        rotate, 
        g_mdi_video_cntx.lcd_handle, 
        is_tvout, 
        &blt_data);

    set_info_data.display_offset_x = 0;         /* not used */
    set_info_data.display_offset_y = 0;         /* not used */
    set_info_data.video_display_offset_x = 0;   /* not used */
    set_info_data.video_display_offset_y = 0;   /* not used */

    /* blt para */
    set_info_data.lcd_start_x = blt_data.lcd_start_x;
    set_info_data.lcd_start_y = blt_data.lcd_start_y;
    set_info_data.lcd_end_x = blt_data.lcd_end_x;
    set_info_data.lcd_end_y = blt_data.lcd_end_y;
    set_info_data.display_width = blt_data.display_width;
    set_info_data.display_height = blt_data.display_height;
    set_info_data.roi_offset_x = blt_data.roi_offset_x;
    set_info_data.roi_offset_y = blt_data.roi_offset_y;    
    set_info_data.image_buffer_p = (void*)blt_data.image_buffer_p;
    set_info_data.image_buffer_size = blt_data.image_buffer_size;
    set_info_data.lcd_rotate = blt_data.lcd_rotate;

#if defined(MDI_VIDEO_MT6228_SERIES)
    set_info_data.image_pitch_mode = FALSE; /* do not use this mode */
    set_info_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    set_info_data.tv_output = blt_data.tv_output;
#endif /* MDI_VIDEO_MT6228_SERIES */ 

#ifdef __MMI_TVOUT__
    set_info_data.tv_output_width = blt_data.tv_output_width;
    set_info_data.tv_output_height = blt_data.tv_output_height;
    set_info_data.tv_output_offset_x = blt_data.tv_output_offset_x;
    set_info_data.tv_output_offset_y = blt_data.tv_output_offset_y;
    set_info_data.tv_output_buffer_size = blt_data.tv_output_buffer_size;
    set_info_data.tv_output_buffer1_address = (kal_uint32)blt_data.tv_output_buffer1_address;
    set_info_data.tv_output_buffer2_address = (kal_uint32)blt_data.tv_output_buffer2_address;
#endif /* __MMI_TVOUT__ */
   
    set_info_data.update_layer = blt_layer_flag;
    set_info_data.hw_update_layer = play_layer_flag;
    set_info_data.play_audio = (U8)TRUE; 
    set_info_data.play_speed = 100;
    set_info_data.audio_path = audio_path;
    set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    set_info_data.seq_num = g_mdi_video_cntx.play_seq_num;
    set_info_data.repeats = 1;
    /* 
     * Set this to true will force driver to use hw trigger instead of direct couple.
     * Direct couple has better frame rate but cant draw out side of lcd region. 
     */
    set_info_data.force_lcd_hw_trigger = g_mdi_video_cntx.is_enable_partial_display;

    if (is_visual_update)
    {
        set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    }
    else
    {
        set_info_data.display_device = MED_DISPLAY_NONE;
    }

    media_stream_set_info(
            module_id, 
            g_mdi_video_cntx.stream_session_id, 
            &set_info_data);

    media_stream_switch_screen_videostart(module_id, g_mdi_video_cntx.stream_session_id);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOPLY_SUCCEED;    

}




/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_play_result_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_stream_play_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_play_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_PLAY_RESULT_HDLR);   
    MMI_ASSERT(mdi_video_stream_play_finish_callback != NULL);

    ind_p = (media_stream_play_ind_struct*)msg_ptr;
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);   

    /* seq number not match, measn it is already disconnected, ignore this message */
    if (g_mdi_video_cntx.play_seq_num != ind_p->request_id)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);   
        return;
    }

    /* un-freeze sublcd */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_freeze(FALSE);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (ind_p->result == MED_RES_OK)
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_SUCCEED);            
    }
    else if (ind_p->result == MED_RES_STREAM_BUFFER_UNDERFLOW)
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW);    
    }
    else if (ind_p->result == MED_RES_STREAM_BUFFER_OVERFLOW)
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW);    
    }    
    else if (ind_p->result == MED_RES_STREAM_STOP_TIMEOUT)
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_REACH_STOP_TIME);    
    }    
    else
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_ERR_FAILED);    
    }
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_STOP); 
    g_mdi_video_cntx.play_seq_num++;

    ret = media_stream_stop(module_id, g_mdi_video_cntx.stream_session_id);
    
    /* un-freeze sublcd */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_freeze(FALSE);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable() && 
        (g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_AV || 
         g_mdi_video_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY))
    {
        /* restore to previous owner */
        if (g_mdi_video_cntx.tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(g_mdi_video_cntx.tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;           
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    gui_cancel_timer(mdi_video_stream_dummy_play_cyclic);
    gui_cancel_timer(mdi_video_stream_dummy_play_result_hdlr);
    return MDI_RES_VDOPLY_SUCCEED;    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 


}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_buf_percentage
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_get_buf_percentage(S32 *percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_GET_BUF_PERCENTAGE); 

    (*percentage) = (S32)media_stream_get_dl_percentage(
                            module_id, 
                            g_mdi_video_cntx.stream_session_id);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PERCENTAGE, *percentage); 
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    *percentage = g_mdi_video_cntx.dummy_loading_percentage;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;        
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_cur_play_time
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_stream_get_cur_play_time(U64 *cur_play_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 cur_time;
    kal_int32 ret; 
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_GET_CUR_PLAY_TIME);  

    ret = media_stream_get_playing_time(
             module_id, 
             g_mdi_video_cntx.stream_session_id,
             &cur_time);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);             

    if (ret == MED_RES_OK)
    {
        *cur_play_time = cur_time;
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_CUR_TIME, cur_time);             
    }
    

#else  /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    *cur_play_time = 0;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_play_cyclic
 * DESCRIPTION
 *  dummy play result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_play_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_video_cntx.dummy_cur_time += 100;

    if (g_mdi_video_cntx.dummy_cur_time >= MDI_VIDEO_DUMMY_TOTAL_TIME)
    {
        g_mdi_video_cntx.dummy_cur_time = 0;
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_SUCCEED);
        return;
    }

    gui_start_timer(100, mdi_video_stream_dummy_play_cyclic);
    
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 




/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_play_result_hdlr
 * DESCRIPTION
 *  dummy play result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_play_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mdi_video_cntx.dummy_counter < 3)
    {
        gui_cancel_timer(mdi_video_stream_dummy_play_cyclic);       
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW);
    }
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_brightness
 * DESCRIPTION
 *  set brightness
 * PARAMETERS
 *  brightness      [IN]        Brightness value
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_brightness(U16 brightness)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_set_param_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_SET_BRIGHTNESS, brightness);   
    
    data.param_id = VID_PARAM_BRIGHTNESS;

    switch (brightness)
    {
        case MDI_VIDEO_BRIGHTNESS_N5:
            data.value = 8; /* -120 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N4:
            data.value = 38;    /* -90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N3:
            data.value = 68;    /* -60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N2:
            data.value = 98;    /* -30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N1:
            data.value = 118;   /* -10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_0:
            data.value = 128;   /* 0 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P1:
            data.value = 138;   /* +10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P2:
            data.value = 158;   /* +30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P3:
            data.value = 188;   /* +60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P4:
            data.value = 218;   /* +90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P5:
            data.value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

    media_stream_set_param(module_id, g_mdi_video_cntx.stream_session_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_contrast
 * DESCRIPTION
 *  set contrast
 * PARAMETERS
 *  contrast        [IN]        Contrast value
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_contrast(U16 contrast)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_set_param_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_SET_CONTRAST, contrast);   
    
    data.param_id = VID_PARAM_CONTRAST;

    switch (contrast)
    {
        case MDI_VIDEO_CONTRAST_N5:
            data.value = 8; /* -120 */
            break;

        case MDI_VIDEO_CONTRAST_N4:
            data.value = 38;    /* -90 */
            break;

        case MDI_VIDEO_CONTRAST_N3:
            data.value = 68;    /* -60 */
            break;

        case MDI_VIDEO_CONTRAST_N2:
            data.value = 98;    /* -30 */
            break;

        case MDI_VIDEO_CONTRAST_N1:
            data.value = 118;   /* -10 */
            break;

        case MDI_VIDEO_CONTRAST_0:
            data.value = 128;   /* 0 */
            break;

        case MDI_VIDEO_CONTRAST_P1:
            data.value = 138;   /* +10 */
            break;

        case MDI_VIDEO_CONTRAST_P2:
            data.value = 158;   /* +30 */
            break;

        case MDI_VIDEO_CONTRAST_P3:
            data.value = 188;   /* +60 */
            break;

        case MDI_VIDEO_CONTRAST_P4:
            data.value = 218;   /* +90 */
            break;

        case MDI_VIDEO_CONTRAST_P5:
            data.value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    } 

    media_stream_set_param(module_id, g_mdi_video_cntx.stream_session_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_dimension
 * DESCRIPTION
 *  Get stream source dimension, this function may only be called after 
 *  calling mdi_video_stream_start_buffering, and buf percentage > 0
 * PARAMETERS
 *  video_width        [OUT]        video width ptr
 *  video_height       [OUT]        video height ptr 
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
MDI_RESULT mdi_video_stream_get_dimension(S32 *video_width, S32 *video_height)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_stream_get_info_struct stream_info;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_stream_get_info(module_id, g_mdi_video_cntx.stream_session_id, &stream_info);

    if (ret == MED_RES_OK)
    {
        *video_width = stream_info.image_width;
        *video_height = stream_info.image_height; 
    }
    else
    {
        *video_width = 0;
        *video_height = 0;        
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_enable_partial_display
 * DESCRIPTION
 *  enable video to play outside lcd region
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_stream_enable_partial_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_ENABLE_PARTIAL_DISPLAY);       
    
    g_mdi_video_cntx.is_enable_partial_display = TRUE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_stop_time
 * DESCRIPTION
 *  Set stop time, currently for Java use only
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_stop_time(U64 stop_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STREAM_SET_STOP_TIME);       
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_STOP_TIME, (U32)stop_time);    
    
    media_stream_set_stop_time(
        module_id,
        g_mdi_video_cntx.stream_session_id,
        stop_time);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_audio_level
 * DESCRIPTION
 *  Set audio level, used by Java only
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_audio_level(U16 aud_level)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(aud_level <= 100);
    media_stream_set_audio_level(module_id, g_mdi_video_cntx.stream_session_id, aud_level);
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}
#endif /* __MMI_VIDEO_STREAM__ */



/*****************************************************************************
 *
 * Progressive Download
 *
 *****************************************************************************/
 #ifdef __MMI_VIDEO_PDL__
  /*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_open_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_open_file(
            const S8 *filename,
            void (*progressive_result_callback)(MDI_RESULT result, mdi_video_info_struct *info))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_open_req_struct open_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PROGRESSIVE_OPEN_FILE);   

    ret = MED_RES_FAIL;

    /* set need seek flag */
    mdi_video_p->is_seek_after_open = FALSE;

    mdi_video_ply_open_file_result_callback = progressive_result_callback;

    SetProtocolEventHandler(mdi_video_ply_open_file_result_hdlr, MSG_ID_MEDIA_VID_FILE_READY_IND);

    open_data.media_mode = MED_MODE_PDL_FILE;
    open_data.enable_aud_only = KAL_TRUE;        
    open_data.data = (void*)filename;

#if defined(MDI_VIDEO_MT6228_SERIES)
    open_data.max_width = 352;  /* CIF width  - max decodable size */
    open_data.max_height = 288; /* CIF height - max decodable size */
#else /* MDI_VIDEO_MT6228_SERIES */ 
    /* MT6219 */
    open_data.max_width = 176;  /* QCIF width  - max decodable size */
    open_data.max_height = 144; /* QCIF height - max decodable size */
#endif /* MDI_VIDEO_MT6228_SERIES */ 

    open_data.play_audio = (U8)TRUE;
    open_data.seq_num = g_mdi_video_cntx.open_seq_num;
    open_data.blocking = FALSE; /* no blocking */

    /* following 4 parameters are used for blocking function */
    open_data.image_width = NULL;
    open_data.image_height = NULL;
    open_data.total_time = NULL;
    open_data.handle = NULL;

    ret = media_vid_open(module_id, &open_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    
    
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    mdi_video_ply_open_file_result_callback = progressive_result_callback;
    gui_start_timer(6000, mdi_video_progressive_dummy_open_file_result_hdlr);

    g_mdi_video_cntx.dummy_cur_time = 0;
    g_mdi_video_cntx.dummy_max_play_time = MDI_VIDEO_DUMMY_TOTAL_TIME;
    g_mdi_video_cntx.dummy_loading_percentage = 0;
    mdi_video_progressive_dummy_loading_cyclic();

    return MDI_RES_VDOPLY_SUCCEED;    

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_close_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_close_file(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct close_data;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PROGRESSIVE_CLOSE_FILE); 
    
    g_mdi_video_cntx.open_seq_num++;

    close_data.handle = 0;
    close_data.media_mode = MED_MODE_PDL_FILE;

    media_vid_close(module_id, &close_data);
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    gui_cancel_timer(mdi_video_progressive_dummy_loading_cyclic);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_get_max_play_time
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_get_max_play_time(U64 *max_play_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_max_time_req_struct time_data;
    U64 max_time; 
    S32 ret;    
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PROGRESSIVE_GET_MAX_PLAY_TIME); 
    
    time_data.max_time_p = &max_time;
    ret = media_vid_get_pdl_max_time(module_id, &time_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);       
    
    *max_play_time = max_time;
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MAX_TIME, max_time); 
    
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *max_play_time = g_mdi_video_cntx.dummy_max_play_time;
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */    


}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_get_buf_percentage
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_get_buf_percentage(S32 *buf_percentage)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE       
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_percent_req_struct percent_data;
    U32 precent; 
    S32 ret;
    module_type module_id = mdi_video_get_module_id();    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PROGRESSIVE_GET_BUF_PERCENTAGE);     
    
    percent_data.percent_p = &precent;
    ret = media_vid_get_pdl_percent(module_id, &percent_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   
    
    *buf_percentage = (S32)precent;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PERCENTAGE, precent); 

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;    
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *buf_percentage = g_mdi_video_cntx.dummy_loading_percentage;
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_is_pdl_format
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_is_pdl_format(U8 *file_buffer, S32 buf_size, MMI_BOOL *is_pdl)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE       
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_check_is_pdl_req_struct check_data;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_PROGRESSIVE_IS_PDL_FORMAT);     

    *is_pdl = MMI_FALSE;
    check_data.file_buf_p = (kal_uint8*)file_buffer;
    check_data.buf_size = (kal_uint32)buf_size;
    ret = media_vid_check_is_pdl_file(module_id, &check_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret == MED_RES_OK)
    {
        *is_pdl = MMI_TRUE;
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else if (ret == MED_RES_OPEN_FILE_FAIL)
    {
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *is_pdl = MMI_TRUE;
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_dummy_loading_cyclic
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_progressive_dummy_loading_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_video_cntx.dummy_loading_percentage < 100)
    {
        g_mdi_video_cntx.dummy_loading_percentage += 10;   
        gui_start_timer(300, mdi_video_progressive_dummy_loading_cyclic);
    }

    if (g_mdi_video_cntx.dummy_max_play_time < MDI_VIDEO_DUMMY_TOTAL_TIME)
    {
        g_mdi_video_cntx.dummy_max_play_time += 100;    
        gui_start_timer(300, mdi_video_progressive_dummy_loading_cyclic);
    }
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_dummy_open_file_result_hdlr
 * DESCRIPTION
 *  dummy open file result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_progressive_dummy_open_file_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct vdo_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vdo_clip.width = 176;
    vdo_clip.height = 144;
    vdo_clip.total_time_duration = MDI_VIDEO_DUMMY_TOTAL_TIME;

    mdi_video_ply_open_file_result_callback(MDI_RES_VDOPLY_SUCCEED, &vdo_clip);
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

#endif /* __MMI_VIDEO_PDL__ */




/*****************************************************************************
 *
 * Editor
 *
 * Note: Editor currently only suppot for MMI context 
 *****************************************************************************/
#ifdef __MMI_VIDEO_EDITOR__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_open_clip_file
 * DESCRIPTION
 *  set overlay palette
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_open_clip_file(const S8 *filename, mdi_video_info_struct *info)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_open_req_struct open_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_OPEN_FILE);   

    ret = MED_RES_FAIL;

    /* set need seek flag */
    mdi_video_p->is_seek_after_open = FALSE;

    SetProtocolEventHandler(mdi_video_ply_open_file_result_hdlr, MSG_ID_MEDIA_VID_FILE_READY_IND);

    open_data.media_mode = MED_MODE_EDITOR_FILE;
    open_data.enable_aud_only = KAL_FALSE;    
    open_data.data = (void*)filename;

#if defined(MDI_VIDEO_MT6228_SERIES)
    open_data.max_width = 352;  /* CIF width  - max decodable size */
    open_data.max_height = 288; /* CIF height - max decodable size */
#else /* MDI_VIDEO_MT6228_SERIES */ 
    /* MT6219 */
    open_data.max_width = 176;  /* QCIF width  - max decodable size */
    open_data.max_height = 144; /* QCIF height - max decodable size */
#endif /* MDI_VIDEO_MT6228_SERIES */ 

    open_data.play_audio = (U8)TRUE;
    open_data.seq_num = g_mdi_video_cntx.open_seq_num;
    open_data.blocking = TRUE;
    open_data.image_width = &info->width;
    open_data.image_height = &info->height;
    open_data.total_time = &info->total_time_duration;
    open_data.handle = &info->handle;

#ifdef __SF_MP4_SUPPORT__
    open_data.media_type = (kal_uint8)mmi_fmgr_get_file_type_by_filename((S8*)filename);
#endif //__SF_MP4_SUPPORT__

    ret = media_vid_open(MOD_MMI, &open_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    
    
    info->track = MDI_VIDEO_TRACK_AV;   
    g_mdi_video_cntx.video_info.track = MDI_VIDEO_TRACK_AV;

    if (ret == MED_RES_OK)
    {
        /* init brightness/contrast */
        mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);        
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else if (ret == MED_RES_UNSUPPORTED_TYPE)    
    {
        return MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    {
        info->width = 176;
        info->height = 144;
        info->total_time_duration = MDI_VIDEO_DUMMY_TOTAL_TIME;
        
        return MDI_RES_VDOPLY_SUCCEED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_close_clip_file
 * DESCRIPTION
 *  close editor's video via handle
 * PARAMETERS
 *  v_handle        [IN]    video handle
 * RETURNS
 *  void
 *****************************************************************************/                
MDI_RESULT mdi_video_edt_close_clip_file(mdi_handle v_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct close_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_CLOSE_FILE);   

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    g_mdi_video_cntx.open_seq_num++;
    
    close_data.handle = v_handle;
    close_data.media_mode = MED_MODE_EDITOR_FILE;

    media_vid_close(stack_int_get_active_module_id(), &close_data);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
    
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_active
 * DESCRIPTION
 *  active a video via handle
 * PARAMETERS
 *  v_handle        [IN]    video handle
 * RETURNS
 *  void
 *****************************************************************************/                
MDI_RESULT mdi_video_edt_active(mdi_handle v_handle)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_set_active_req_struct active_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ACTIVE, v_handle);   
    
    MMI_ASSERT(v_handle != 0);
    
    active_data.handle = v_handle;
    ret = media_vid_edt_set_active(stack_int_get_active_module_id(), &active_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_deactive
 * DESCRIPTION
 *  active a video via handle
 * PARAMETERS
 *  deactive current active video
 * RETURNS
 *  void
 *****************************************************************************/                
MDI_RESULT mdi_video_edt_deactive(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_set_active_req_struct active_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_DEACTIVE);   
    
    active_data.handle = 0;
    media_vid_edt_set_active(stack_int_get_active_module_id(), &active_data);
    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

    return MDI_RES_VDOPLY_SUCCEED;
}




/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_encode_open
 * DESCRIPTION
 *  open encode file
 * PARAMETERS
 *  dest_video_width        [IN]
 *  dest_video_height       [IN]
 *  filename_p              [IN]                        
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/      
MDI_RESULT mdi_video_edt_encode_open(S32 dest_video_width, S32 dest_video_height, PS8 filename_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_open_req_struct open_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ENCODE_OPEN);   

    open_data.encode_video_width = dest_video_width;
    open_data.encode_video_height = dest_video_height;
    open_data.filename = (kal_wchar*)filename_p;
    
    ret = media_vid_edt_enc_open(MOD_MMI, &open_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_encode_close
 * DESCRIPTION
 *  close encode file
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/      
MDI_RESULT mdi_video_edt_encode_close(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_close_req_struct close_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ENCODE_CLOSE);   
    
    ret = media_vid_edt_enc_close(MOD_MMI, &close_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_encode_append_image
 * DESCRIPTION
 *  append image
 * PARAMETERS
 *  img_layer           [IN]
 *  ext_layer_1         [IN]
 *  ext_layer_2         [IN]
 *  duration            [IN]
 *  is_use_bgm          [IN]
 *  bgm_start_time      [IN]
 *  bgm_end_time        [IN] 
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/      
MDI_RESULT mdi_video_edt_encode_append_image(
            gdi_handle img_layer, 
            gdi_handle ext_layer_1,
            gdi_handle ext_layer_2,
            U32 duration,
            MMI_BOOL is_use_bgm,
            U32 bgm_start_time,
            U32 bgm_end_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_append_req_struct append_data;
    S32 ret;
    PU8 buf_ptr;
    S32 layer_width;
    S32 layer_height;
    S32 bit_per_pixtel;
    U8 opacity_value;
    BOOL src_key_enable;
    BOOL opacity_enable;
    gdi_color key_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ENCODE_APPEND_IMAGE);   

    append_data.resource_type = MED_VID_EDT_RES_TYPE_IMAGE;
    append_data.video_handle = 0;

    gdi_layer_push_and_set_active(img_layer);
    gdi_layer_get_buffer_ptr(&buf_ptr);

    append_data.img_buf_ptr = (kal_uint8*)buf_ptr;
    
    bit_per_pixtel = gdi_layer_get_bit_per_pixel();    
    gdi_layer_get_dimension(&layer_width, &layer_height);
    
    gdi_layer_pop_and_restore_active();
    
    append_data.img_buf_size = layer_width * layer_height * bit_per_pixtel >> 8;

    if (ext_layer_1 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(ext_layer_1);
        gdi_layer_get_source_key(&src_key_enable, &key_color);
        gdi_layer_get_opacity(&opacity_enable, &opacity_value);
        gdi_layer_get_dimension(&layer_width, &layer_height);
        gdi_layer_get_buffer_ptr(&buf_ptr);

        append_data.extra_layer_1.is_use = (kal_bool)TRUE;
        append_data.extra_layer_1.source_key_enable = (kal_bool)src_key_enable;
        append_data.extra_layer_1.source_key = (kal_uint32)key_color;
        append_data.extra_layer_1.opacity_enable = opacity_enable;
        append_data.extra_layer_1.opacity_value = opacity_value;    
        append_data.extra_layer_1.offset_x = 0;
        append_data.extra_layer_1.offset_y = 0;   
        append_data.extra_layer_1.width = layer_width;
        append_data.extra_layer_1.height = layer_height;   
        append_data.extra_layer_1.frame_buffer_address = (kal_uint32)buf_ptr;
        gdi_layer_pop_and_restore_active();        
    }
    else
    {
       append_data.extra_layer_1.is_use = (kal_bool)FALSE;
    }

    if (ext_layer_2 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(ext_layer_2);
        gdi_layer_get_source_key(&src_key_enable, &key_color);
        gdi_layer_get_opacity(&opacity_enable, &opacity_value);
        gdi_layer_get_dimension(&layer_width, &layer_height);
        gdi_layer_get_buffer_ptr(&buf_ptr);

        append_data.extra_layer_2.is_use = (kal_bool)TRUE;
        append_data.extra_layer_2.source_key_enable = (kal_bool)src_key_enable;
        append_data.extra_layer_2.source_key = (kal_uint32)key_color;
        append_data.extra_layer_2.opacity_enable = opacity_enable;
        append_data.extra_layer_2.opacity_value = opacity_value;    
        append_data.extra_layer_2.offset_x = 0;
        append_data.extra_layer_2.offset_y = 0;   
        append_data.extra_layer_2.width = layer_width;
        append_data.extra_layer_2.height = layer_height;   
        append_data.extra_layer_2.frame_buffer_address = (kal_uint32)buf_ptr;
        gdi_layer_pop_and_restore_active();        
    }
    else
    {
       append_data.extra_layer_2.is_use = (kal_bool)FALSE;
    }

    append_data.start_time = 0;
    append_data.end_time = duration;    
    
    append_data.is_use_bgm = (kal_bool)is_use_bgm;
    append_data.bgm_start_time = bgm_start_time;
    append_data.bgm_end_time = bgm_end_time;    
    
        ret = media_vid_edt_enc_append(MOD_MMI, &append_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_encode_append_video
 * DESCRIPTION
 *  append video
 * PARAMETERS
 *  v_handle            [IN]
 *  ext_layer_1         [IN]
 *  ext_layer_2         [IN]
 *  start_time          [IN]
 *  end_time            [IN] 
 *  is_use_bgm          [IN]
 *  bgm_start_time      [IN]
 *  bgm_end_time        [IN] 
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/    
MDI_RESULT mdi_video_edt_encode_append_video(
            mdi_handle v_handle,
            gdi_handle ext_layer_1,
            gdi_handle ext_layer_2,
            U32 start_time,
            U32 end_time,
            MMI_BOOL is_use_bgm,
            U32 bgm_start_time,
            U32 bgm_end_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_append_req_struct append_data;
    S32 ret;
    PU8 buf_ptr;
    S32 layer_width;
    S32 layer_height;
    U8 opacity_value;
    BOOL src_key_enable;
    BOOL opacity_enable;
    gdi_color key_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ENCODE_APPEND_VIDEO);   

    append_data.resource_type = MED_VID_EDT_RES_TYPE_VIDEO;
    append_data.video_handle = v_handle;
    append_data.img_buf_ptr = NULL;
    append_data.img_buf_size = 0;

    if (ext_layer_1 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(ext_layer_1);
        gdi_layer_get_source_key(&src_key_enable, &key_color);
        gdi_layer_get_opacity(&opacity_enable, &opacity_value);
        gdi_layer_get_dimension(&layer_width, &layer_height);
        gdi_layer_get_buffer_ptr(&buf_ptr);

        append_data.extra_layer_1.is_use = (kal_bool)TRUE;
        append_data.extra_layer_1.source_key_enable = (kal_bool)src_key_enable;
        append_data.extra_layer_1.source_key = (kal_uint32)key_color;
        append_data.extra_layer_1.opacity_enable = opacity_enable;
        append_data.extra_layer_1.opacity_value = opacity_value;    
        append_data.extra_layer_1.offset_x = 0;
        append_data.extra_layer_1.offset_y = 0;   
        append_data.extra_layer_1.width = layer_width;
        append_data.extra_layer_1.height = layer_height;   
        append_data.extra_layer_1.frame_buffer_address = (kal_uint32)buf_ptr;
        gdi_layer_pop_and_restore_active();        
    }
    else
    {
       append_data.extra_layer_1.is_use = (kal_bool)FALSE;
    }

    if (ext_layer_2 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(ext_layer_2);
        gdi_layer_get_source_key(&src_key_enable, &key_color);
        gdi_layer_get_opacity(&opacity_enable, &opacity_value);
        gdi_layer_get_dimension(&layer_width, &layer_height);
        gdi_layer_get_buffer_ptr(&buf_ptr);

        append_data.extra_layer_2.is_use = (kal_bool)TRUE;
        append_data.extra_layer_2.source_key_enable = (kal_bool)src_key_enable;
        append_data.extra_layer_2.source_key = (kal_uint32)key_color;
        append_data.extra_layer_2.opacity_enable = opacity_enable;
        append_data.extra_layer_2.opacity_value = opacity_value;    
        append_data.extra_layer_2.offset_x = 0;
        append_data.extra_layer_2.offset_y = 0;   
        append_data.extra_layer_2.width = layer_width;
        append_data.extra_layer_2.height = layer_height;   
        append_data.extra_layer_2.frame_buffer_address = (kal_uint32)buf_ptr;
        gdi_layer_pop_and_restore_active();        
    }
    else
    {
       append_data.extra_layer_2.is_use = (kal_bool)FALSE;
    }

    append_data.start_time = start_time;
    append_data.end_time = end_time;    
    
    append_data.is_use_bgm = (kal_bool)is_use_bgm;
    append_data.bgm_start_time = bgm_start_time;
    append_data.bgm_end_time = bgm_end_time;    
    
    ret = media_vid_edt_enc_append(MOD_MMI, &append_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_encode_merge
 * DESCRIPTION
 *  merge video
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/    
MDI_RESULT mdi_video_edt_encode_merge(PS8 filename_p, void (*merge_result_callback)(MDI_RESULT))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_merge_req_struct merge_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ENCODE_MERGE);   

    mdi_video_edt_encode_merge_result_callback = merge_result_callback;

    SetProtocolEventHandler(
        mdi_video_edt_encode_merge_result_hdlr,
        MSG_ID_MEDIA_VID_EDT_ENC_MERGE_DONE_IND);

    merge_data.seq_num = g_mdi_video_cntx.merge_seq_num;
    merge_data.filename = (kal_wchar*)filename_p;
      
    ret = media_vid_edt_enc_merge(MOD_MMI, &merge_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_encode_stop_merge
 * DESCRIPTION
 *  stop merge 
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/    
MDI_RESULT mdi_video_edt_encode_stop_merge(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_stop_merge_req_struct stop_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ENCODE_STOP_MERGE);   

    g_mdi_video_cntx.merge_seq_num++;
    
    ret = media_vid_edt_enc_stop_merge(MOD_MMI, &stop_data);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ret);   

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_encode_merge_result_hdlr
 * DESCRIPTION
 *  save result message hdlr
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_edt_encode_merge_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_merge_done_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_EDT_ENCODE_MERGE_RESULT_HDLR);   
    ind_p = (media_vid_edt_enc_merge_done_ind_struct*) msg_ptr;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);    


    /* seq number not match, measn it is already stopped, ignore this message */
    if (g_mdi_video_cntx.merge_seq_num != ind_p->seq_num)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);   
        return;
    }

    if (ind_p->result == MED_RES_OK)
    {
        mdi_video_edt_encode_merge_result_callback(MDI_RES_VDOREC_SUCCEED);
    }
    else if (ind_p->result == MED_RES_DISC_FULL)
    {
        mdi_video_edt_encode_merge_result_callback(MDI_RES_VDOREC_ERR_DISK_FULL);
    }
    else
    {
        mdi_video_edt_encode_merge_result_callback(MDI_RES_VDOREC_ERR_FAILED);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_open_bgm_clip_id
 * DESCRIPTION
 *  Open bgm from id
 * PARAMETERS
 *  audio_id             [IN]        resource id
 *  duration_p           [OUT]       audio duration
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_open_bgm_clip_id(U16 audio_id, U64 *duration_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_open_bgm_req_struct open_data;
    S32 ret;
    PU8 aud_ptr;
    U8 type; 
    U32 file_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_ptr = get_audio((U16)(audio_id), &type, &file_len);
    MMI_ASSERT(aud_ptr != NULL);
     

    open_data.data_p = (kal_uint8*)aud_ptr;
    open_data.data_size = file_len;
    open_data.media_mode = MED_MODE_ARRAY;        
    open_data.media_type = MED_TYPE_M4A;
    open_data.aud_duration_p = duration_p;

    ret = media_vid_edt_open_bgm(MOD_MMI, &open_data);

    /* TODO: add more return case */
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_close_bgm_clip_id
 * DESCRIPTION
 *  Close bgm id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_close_bgm_clip_id(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_bgm_req_struct close_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_bgm(MOD_MMI, &close_data);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_open_bgm_clip_file
 * DESCRIPTION
 *  Open bgm clip file from filename
 * PARAMETERS
 *  filename             [IN]        filename
 *  duration_p           [OUT]       audio duration
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_open_bgm_clip_file(const S8 *filename, U64 *duration_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_open_bgm_req_struct open_data;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    open_data.data_p = (kal_uint8*)filename;
    open_data.data_size = 0; /* not used */
    open_data.media_mode = MED_MODE_FILE;        
    open_data.media_type = MED_TYPE_M4A;
    open_data.aud_duration_p = duration_p;

    ret = media_vid_edt_open_bgm(MOD_MMI, &open_data);

    /* TODO: add more return case */
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_close_bgm_clip_file
 * DESCRIPTION
 *  Close bgm file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_close_bgm_clip_file(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_bgm_req_struct close_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_bgm(MOD_MMI, &close_data);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_open_silence_clip_id
 * DESCRIPTION
 *  Open silence from id
 * PARAMETERS
 *  audio_id             [IN]        resource id
 *  duration_p           [OUT]       audio duration
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_open_silence_clip_id(U16 audio_id, U64 *duration_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE    
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_open_silence_req_struct open_data;
    S32 ret;
    PU8 aud_ptr;
    U8 type; 
    U32 file_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_ptr = get_audio((U16)(audio_id), &type, &file_len);
    MMI_ASSERT(aud_ptr != NULL);
     

    open_data.data_p = (kal_uint8*)aud_ptr;
    open_data.data_size = file_len;
    open_data.media_mode = MED_MODE_ARRAY;        
    open_data.media_type = MED_TYPE_M4A;
    open_data.aud_duration_p = duration_p;

    ret = media_vid_edt_open_silence(MOD_MMI, &open_data);

    /* TODO: add more return case */
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_close_silence_clip_id
 * DESCRIPTION
 *  Close silence id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_close_silence_clip_id(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE        
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_silence_req_struct close_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_silence(MOD_MMI, &close_data);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_open_silence_clip_file
 * DESCRIPTION
 *  Open silence clip file from filename
 * PARAMETERS
 *  filename             [IN]        filename
 *  duration_p           [OUT]       audio duration
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_open_silence_clip_file(const S8 *filename, U64 *duration_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_open_silence_req_struct open_data;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    open_data.data_p = (kal_uint8*)filename;
    open_data.data_size = 0; /* not used */
    open_data.media_mode = MED_MODE_FILE;        
    open_data.media_type = MED_TYPE_M4A;
    open_data.aud_duration_p = duration_p;

    ret = media_vid_edt_open_silence(MOD_MMI, &open_data);

    /* TODO: add more return case */
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_close_silence_clip_file
 * DESCRIPTION
 *  Close silence file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_close_silence_clip_file(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_silence_req_struct close_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_edt_close_silence(MOD_MMI, &close_data);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_init
 * DESCRIPTION
 *  Close silence file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_init(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_vid_edt_init_req_struct init_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    init_data.init = KAL_TRUE;
    ret = media_vid_edt_init(MOD_MMI, &init_data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_edt_deinit
 * DESCRIPTION
 *  Close silence file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_edt_deinit(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_vid_edt_init_req_struct init_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    init_data.init = KAL_FALSE;
    
    ret = media_vid_edt_init(MOD_MMI, &init_data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }    
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}

#endif /* __MMI_VIDEO_EDITOR__ */




/****************************************************************************
*
* VIDEO TELEPHONY                                                                 
*
*****************************************************************************/
#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_start
 * DESCRIPTION
 *  Start video telephony preview / decode
 * PARAMETERS
 *  peer_layer_handle           [IN]        peer display layer handle
 *  local_layer_handle          [IN]        local display layer handle 
 *  peer_disp_type              [IN]        peer display type
 *  local_disp_type             [IN]        local display type
 *  blt_laye_flag               [IN]        which layers will be blt to lcd by driver
 *  peer_layer_flag             [IN]        which layer is for peer display
 *  local_layer_flag            [IN]        which layer is for local display 
 *  local_preview_p             [IN]        local preview video settings
 *  event_callback              [IN]        call back function
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_tel_start(
            gdi_handle peer_layer_handle,
            gdi_handle local_layer_handle,
            mdi_video_tel_disp_type_enum peer_disp_type,
            mdi_video_tel_disp_type_enum local_disp_type,                       
            U32 blt_layer_flag,                     
            U32 peer_layer_flag,                    
            U32 local_layer_flag,                   
            mdi_video_setting_struct *local_preview_setting_p,
            void (*event_callback)(mdi_video_tel_codec_event_enum codec_event, S32 para))   

{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_video_record_struct local_data;
    media_video_playback_struct peer_data;
    media_vcall_view_type_enum local_type;
    media_vcall_view_type_enum peer_type;    
    mdi_blt_para_struct blt_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_tel_codec_event_callback = event_callback;

    SetProtocolEventHandler(
        mdi_video_tel_codec_event_ind_hdlr,
        MSG_ID_MEDIA_VCALL_VIDEO_CODEC_REPORT_IND);
    
    /* store video's parameters */
    memcpy(video_setting_p, local_preview_setting_p, sizeof(mdi_video_setting_struct));

    gdi_lcd_get_active(&g_mdi_video_cntx.lcd_handle);

    /*******************************
     *        LOCAL DISPLAY        *
     *******************************/
    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type ||
        MDI_VIDEO_TEL_DISPLAY_IMAGE == local_disp_type)
    {
        /* common data */
        mdi_calc_blt_para(
            local_layer_handle, 
            MDI_LCD_ROTATE_0, 
            g_mdi_video_cntx.lcd_handle,  
            MMI_FALSE, 
            &blt_data);

    #ifdef ISP_SUPPORT
        switch (video_setting_p->video_size)
        {
            case MDI_VIDEO_VIDEO_SIZE_SQCIF:
                local_data.encode_width = 128;
                local_data.encode_height = 96;
                break;

            case MDI_VIDEO_VIDEO_SIZE_QQVGA:
                MMI_ASSERT(0); /* currently not support */            
                local_data.encode_width = 160;
                local_data.encode_height = 120;
                break;

            case MDI_VIDEO_VIDEO_SIZE_QCIF:
                local_data.encode_width = 176;
                local_data.encode_height = 144;
                break;

            case MDI_VIDEO_VIDEO_SIZE_CIF:
                MMI_ASSERT(0); /* currently not support */            
                local_data.encode_width = 352;
                local_data.encode_height = 288;
                break;

            case MDI_VIDEO_VIDEO_SIZE_USER_DEFINE:
                MMI_ASSERT(0); /* currently not support */            
                local_data.encode_width = video_setting_p->user_def_width;
                local_data.encode_height = video_setting_p->user_def_height;
                break;
            default:
                ASSERT(0);
        }

    #endif /* ISP_SUPPORT */ 

        local_data.preview_width = blt_data.display_width;
        local_data.preview_height = blt_data.display_height;
        local_data.preview_buffer_p = blt_data.image_buffer_p;
        local_data.preview_buffer_size = blt_data.image_buffer_size;
    }

   
    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type)
    {
        local_type = VCALL_VIEW_SHOW_VIDEO;
            
        /* NOTE!! currently do not support lcd rotation */
        MMI_ASSERT(video_setting_p->lcm_rotate == MDI_LCD_ROTATE_0); 

        local_data.camera_rotate = video_setting_p->preview_rotate;
        local_data.lcd_rotate = blt_data.lcd_rotate;

        local_data.zoom_factor = video_setting_p->zoom;
        local_data.exposure = video_setting_p->ev;
        local_data.contrast = video_setting_p->contrast;
        local_data.brightness = video_setting_p->brightness;
        local_data.saturation = video_setting_p->saturation;
        local_data.hue = video_setting_p->hue;
        local_data.gamma = 0;
        local_data.WB = video_setting_p->wb;
        local_data.effect = video_setting_p->effect;
        local_data.night_mode = video_setting_p->night;
        local_data.banding_freq = (U8)video_setting_p->banding;
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = g_mdi_video_cntx.vt_seq_num;

        local_data.lcd_id = MAIN_LCD;
        local_data.update_layer = blt_layer_flag;
        local_data.hw_update_layer = local_layer_flag;
        local_data.lcd_start_x = blt_data.lcd_start_x;
        local_data.lcd_start_y = blt_data.lcd_start_y;
        local_data.lcd_end_x = blt_data.lcd_end_x;
        local_data.lcd_end_y = blt_data.lcd_end_y;
        local_data.roi_offset_x = blt_data.roi_offset_x;
        local_data.roi_offset_y = blt_data.roi_offset_y;    
        local_data.src_key_color = 0; /* not used ? */

        /* update to lcd or not */
        if (local_layer_flag == 0)
        {
            local_data.lcd_update = KAL_FALSE;
        }
        else
        {
            local_data.lcd_update = KAL_TRUE;
        }

    #if (defined(MT6228) || defined(MT6229)) || defined(MT6230)
        local_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
        local_data.roi_background_color = GDI_COLOR_BLACK;
        local_data.tv_output = blt_data.tv_output;
        
    #ifdef __MMI_TVOUT__
        local_data.tv_output_width = blt_data.tv_output_width;
        local_data.tv_output_width = blt_data.tv_output_width;
        local_data.tv_output_height = blt_data.tv_output_height;
        local_data.tv_output_offset_x = blt_data.tv_output_offset_x;
        local_data.tv_output_offset_y = blt_data.tv_output_offset_y;
        local_data.tv_output_buffer_size = blt_data.tv_output_buffer_size;
        local_data.tv_output_buffer1_address = (kal_uint32)blt_data.tv_output_buffer1_address;
        local_data.tv_output_buffer2_address = (kal_uint32)blt_data.tv_output_buffer2_address;
    #endif /* __MMI_TVOUT__ */

    #endif /* (defined(MT6228) || defined(MT6229)) || defined(MT6230) */
        
    }
    else if (MDI_VIDEO_TEL_DISPLAY_IMAGE == local_disp_type)
    {
        local_type = VCALL_VIEW_SHOW_IMAGE;
        
        /* encoder qty */
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = g_mdi_video_cntx.vt_seq_num;    

        /* update to lcd or not */
        if (local_layer_flag == 0)
        {
            local_data.lcd_update = KAL_FALSE;
        }
        else
        {
            local_data.lcd_update = KAL_TRUE;
        }        
        
    }
    else if(MDI_VIDEO_TEL_DISPLAY_HIDE == local_disp_type)
    {
        local_type = VCALL_VIEW_HIDE;

        /* encoder qty */
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = g_mdi_video_cntx.vt_seq_num;        
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }


    /*******************************
     *         PEER DISPLAY        *
     *******************************/
    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type || 
        MDI_VIDEO_TEL_DISPLAY_IMAGE == peer_disp_type)
    {
        /* calc blt paramters */
        mdi_calc_blt_para(
            peer_layer_handle, 
            MDI_LCD_ROTATE_0,
            g_mdi_video_cntx.lcd_handle,  
            MMI_FALSE, 
            &blt_data);

        if (MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type)
        {
            peer_type = VCALL_VIEW_SHOW_VIDEO;
        }
        else if (MDI_VIDEO_TEL_DISPLAY_IMAGE == peer_disp_type)
        {
            peer_type = VCALL_VIEW_SHOW_IMAGE;
        }
        else
        {
            MMI_ASSERT(0);
        }

        peer_data.display_width = blt_data.display_width;
        peer_data.display_height = blt_data.display_height;       
        peer_data.display_buffer_p = (void*)blt_data.image_buffer_p;
        peer_data.display_buffer_size = blt_data.image_buffer_size;
        peer_data.lcd_rotate = blt_data.lcd_rotate;
        peer_data.contrast = MDI_VIDEO_CONTRAST_0;      /* TODO */
        peer_data.brightness = MDI_VIDEO_BRIGHTNESS_0;  /* TODO */
        peer_data.seq_num = g_mdi_video_cntx.vt_seq_num;

        peer_data.lcd_id = MAIN_LCD;
        peer_data.lcd_start_x = blt_data.lcd_start_x;
        peer_data.lcd_start_y = blt_data.lcd_start_y;
        peer_data.lcd_end_x = blt_data.lcd_end_x;
        peer_data.lcd_end_y = blt_data.lcd_end_y;
        peer_data.roi_offset_x = blt_data.roi_offset_x;
        peer_data.roi_offset_y = blt_data.roi_offset_y;    
        peer_data.update_layer = blt_layer_flag;
        peer_data.hw_update_layer = peer_layer_flag;
        peer_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;


    #if (defined(MT6228) || defined(MT6229)) || defined(MT6230)
        peer_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
        peer_data.roi_background_color = GDI_COLOR_BLACK;
        peer_data.tv_output = blt_data.tv_output;
        
    #ifdef __MMI_TVOUT__
        peer_data.tv_output_width = blt_data.tv_output_width;
        peer_data.tv_output_width = blt_data.tv_output_width;
        peer_data.tv_output_height = blt_data.tv_output_height;
        peer_data.tv_output_offset_x = blt_data.tv_output_offset_x;
        peer_data.tv_output_offset_y = blt_data.tv_output_offset_y;
        peer_data.tv_output_buffer_size = blt_data.tv_output_buffer_size;
        peer_data.tv_output_buffer1_address = (kal_uint32)blt_data.tv_output_buffer1_address;
        peer_data.tv_output_buffer2_address = (kal_uint32)blt_data.tv_output_buffer2_address;
    #endif /* __MMI_TVOUT__ */

    #endif /* (defined(MT6228) || defined(MT6229)) || defined(MT6230) */
   

    }
    else if(MDI_VIDEO_TEL_DISPLAY_HIDE == peer_disp_type)
    {
        peer_type = VCALL_VIEW_HIDE;
    }    
    else
    {
        MMI_ASSERT(0);
    }

    ret = media_vcall_open_video_codec(
            MOD_MMI,        
            local_type,     /* outgoing data */
            &local_data,    /* outgoing data */
            peer_type,      /* incoming data */
            &peer_data);    /* incoming data */
   
    return MDI_RES_VDOTEL_SUCCEED;
   
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOTEL_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_codec_event_ind_hdlr
 * DESCRIPTION
 *  video tel event handler
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_tel_codec_event_ind_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE        
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_codec_report_ind_struct *ind_p;
    mdi_video_tel_codec_event_enum codec_event;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_TEL_CODEC_EVENT_IND_HDLR);   
    ind_p = (media_vcall_video_codec_report_ind_struct*) msg_ptr;

    if (g_mdi_video_cntx.vt_seq_num != ind_p->seq_no)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);          
        return;
    }

    /* mapping driver's event to MDI */
    switch (ind_p->codec_event)
    {   
        case VCALL_EVENT_CHANGE_ENCODE_SIZE:
            if (ind_p->para == VCALL_VIDEO_SIZE_SQCIF)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE, 
                    MDI_VIDEO_VIDEO_SIZE_SQCIF);
            }
            else if (ind_p->para == VCALL_VIDEO_SIZE_QCIF)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE, 
                    MDI_VIDEO_VIDEO_SIZE_QCIF);
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

        case VCALL_EVENT_CHANGE_ENCODE_QUALITY:
            if (ind_p->para == VCALL_ENC_QTY_FINE)
            {
                mdi_video_tel_codec_event_callback(    
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY, 
                    MDI_VIDEO_TEL_ENC_QTY_FINE);  
            }
            else if (ind_p->para == VCALL_ENC_QTY_NORMAL)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY, 
                    MDI_VIDEO_TEL_ENC_QTY_NORMAL);  
            }
            else if (ind_p->para == VCALL_ENC_QTY_LOW)
            {
                mdi_video_tel_codec_event_callback(    
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY, 
                    MDI_VIDEO_TEL_ENC_QTY_LOW);  
            }            
            else
            {
                MMI_ASSERT(0);
            }   
            break;

        default:
            ASSERT(0);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_stop
 * DESCRIPTION
 *  stop video telephony preview / decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_video_tel_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_video_cntx.vt_seq_num++;

    media_vcall_close_video_codec(MOD_MMI);

    return MDI_RES_VDOTEL_SUCCEED;
    
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOTEL_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_ev
 * DESCRIPTION
 *  update ev setting value
 * PARAMETERS
 *  para        [IN]        ev setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_update_para_ev(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: */
//  MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_UPDATE_PARA_EV, para);   
    ASSERT(para < MDI_VIDEO_EV_COUNT);

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_cam_set_param(MOD_MMI, CAM_PARAM_EXPOSURE, para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_zoom
 * DESCRIPTION
 *  update zoom setting value
 * PARAMETERS
 *  para        [IN]        zoom setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_update_para_zoom(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: */
//  MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_TRC_VIDEO_REC_UPDATE_PARA_ZOOM, para);   
    
    mdi_video_p->setting.zoom = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_cam_set_param(MOD_MMI, CAM_PARAM_ZOOM_FACTOR, para);
#endif 

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_enable_vt_loopback
 * DESCRIPTION
 *  Enable VT task start loopback, this function is for UT use only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_enable_vt_loopback(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mdi_vt_loopback_active_req_struct *msg_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data_ptr = OslConstructDataPtr(sizeof(mdi_vt_loopback_active_req_struct));

    message.oslMsgId = MSG_ID_MDI_VT_LOOPBACK_ACTIVATE_REQ;
    message.oslDataPtr = (oslParaType*)msg_data_ptr;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_VT;

    OslMsgSendExtQueue(&message);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_disable_vt_loopback
 * DESCRIPTION
 *  Disable VT task start loopback, this function is for UT use only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_disable_vt_loopback(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mdi_vt_loopback_deactive_req_struct *msg_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data_ptr = OslConstructDataPtr(sizeof(mdi_vt_loopback_deactive_req_struct));

    message.oslMsgId = MSG_ID_MDI_VT_LOOPBACK_DEACTIVATE_REQ;
    message.oslDataPtr = (oslParaType*)msg_data_ptr;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_VT;

    OslMsgSendExtQueue(&message);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}

#endif /* __MMI_VIDEO_TELEPHONY__ */


#endif /* defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__) */ 

