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
 *   cam_hp_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of MED camera high proirity module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MED_C_NOT_PRESENT


/*==== INCLUDES =========*/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"          /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"         /* Task creation */
#include "app_buff_alloc.h"        /* Declaration of buffer management API */
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"          /* Event scheduler */
#include "stack_timer.h"         /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "fat_fs.h"

#include "rtc_sw.h"
#include "lcd_if.h"
#ifdef ISP_SUPPORT
#include "isp_if.h"
#endif

#ifdef MP4_CODEC
#include "FSAL.h"
//#include "MP4_Parser.h"
//#include "MP4_Producer_Audio.h"
//#include "MP4_Sample_Data_Audio.h"
//#include "video_file_creator.h"
#include "drv_comm.h"
#include "visual_comm.h"
#include "l1audio.h"
#include "bmd.h"
//#include "video_dec_glb.h"
//#include "video_enc_glb.h"
//#include "video_glb.h"
#endif

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_c_struct.h"
#include "med_c_context.h"
#include "med_c_main.h"
#include "med_main.h"
#include "cam_main.h"
#include "med_utility.h"



#ifdef __CAM_TRACE_ON__
#include "med_trc.h"
#endif

#ifdef __MED_CAM_MOD__

/*************************************************************************
* FUNCTION
*	cam_hp_event_ind_hdlr
*
* DESCRIPTION
*	This function is to handle camera hight priority event indication. 
*
* PARAMETERS
*	ilm_struct *ilm_ptr
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void cam_hp_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    media_cam_event_ind_struct *ind_p;

    ind_p = (media_cam_event_ind_struct*)ilm_ptr->local_para_ptr;
    
    if((ind_p->event==CAM_EVT_PREVIEW) &&
      (CAM_IN_STATE(CAM_READY) || CAM_IN_STATE(CAM_PREVIEW) || CAM_IN_STATE(CAM_CAPTURE_BARCODE) ||
      (FACTORY_BOOT==stack_query_boot_mode())
    #ifdef __MED_VID_ENC_MOD__
      || VID_IN_STATE(VID_PREVIEW)
    #endif
    #ifdef __MED_VCALL_MOD__
       || media_vall_is_cam_able_to_update_para()
    #endif    
       ))
    {
        /* auto adjust exposue value and white balance */
    #if defined(ISP_SUPPORT) && defined(__MTK_TARGET__) && !defined(YUV_SENSOR_SUPPORT)
        ae_awb_main();
    #endif
    }
#ifdef __MED_WEBCAM_MOD__
    else if ((ind_p->event == CAM_EVT_PREVIEW) && (WEBCAM_IN_STATE(WEBCAM_PREVIEW)))
    {
        /* auto adjust exposue value and white balance */
    #if defined(ISP_SUPPORT) && defined(__MTK_TARGET__) && !defined(YUV_SENSOR_SUPPORT)
        ae_awb_main();
    #endif 

    }
#endif /* __MED_WEBCAM_MOD__ */ 

}

#endif /* __MED_CAM_MOD__ */

#endif /* MED_C_NOT_PRESENT */



