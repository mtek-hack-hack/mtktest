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
 * vcall_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains vcall main procedures.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef WIN32
#include <stdio.h>
#endif 

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

/* Task Management */
#include "syscomp_config.h"
#include "task_config.h"

/* Timer Management  */
#include "stacklib.h"
#include "event_shed.h" /* event schedulet */
#include "stack_timer.h"

#include "app_buff_alloc.h"     /* buffer management API */
#include "lcd_cqueue.h" /* circular queue */
#include "app2soc_struct.h"     /* interface with Applications */

#include <setjmp.h>

#include "soc_api.h"
#include "fat_fs.h"
#include "rtc_sw.h"

#include "stack_utils.h"

#include "kal_trace.h"

#include <time.h>
#include "l1audio.h"
#include "med_global.h"
#include "med_struct.h"

#ifdef __MED_VCALL_MOD__

#include "vcall.h"
#include "med_vt_struct.h"
#include "vcall_api.h"
#include "med_trc.h"

/* 
 * Global variables
 */
vcall_context_struct vcall_ctx;

/*----------------------------------------------------------------*/
/* External functions                                             */
/*----------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  vcall_init
 * DESCRIPTION
 *  initiation function for vcall
 * PARAMETERS
 *  void
 * RETURNS
 * TRUE
 *****************************************************************************/
kal_bool vcall_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_VCALL_INIT);
    
    kal_mem_set(&vcall_ctx, 0, sizeof(vcall_context_struct));

    vcall_ctx.event = kal_create_event_group("vcall_event");

    vcall_ctx.video_encoder.cfg.callback = vcall_video_encoder_event_callback;
    vcall_ctx.video_decoder.cfg.callback = vcall_video_decoder_event_callback;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vcall_main
 * DESCRIPTION
 *  Main ilm handler for vcall
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        /* MMI */    
        case MSG_ID_MEDIA_VCALL_VIDEO_CODEC_OPEN_REQ:
            vcall_video_codec_open_req_hdlr(ilm_ptr);
            break;
    
        case MSG_ID_MEDIA_VCALL_VIDEO_CODEC_CLOSE_REQ:
            vcall_video_codec_close_req_hdlr(ilm_ptr);
            break;
            
        /* VT */
        case MSG_ID_MEDIA_VCALL_CHANNEL_STATUS_IND:
            vcall_channel_status_ind_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_VCALL_VIDEO_REPLENISH_DATA_READY_IND:
            vcall_video_replenish_data_ready_ind_hdlr(ilm_ptr);
            break;
            
        /* Video Decoder Callback */
        case MSG_ID_MEDIA_VCALL_VIDEO_DECODE_DATA_READY_IND:
            vcall_video_decode_data_ready_ind_hdlr(ilm_ptr);
            break;
            
        /* video Encoder Callback */
        case MSG_ID_MEDIA_VCALL_VIDEO_ENCODE_DATA_READY_IND:
            vcall_video_encode_data_ready_ind_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_VT_ADJUST_VIDEO_QUALITY_IND:
            vcall_adjust_quality_ind_hdlr(ilm_ptr);
            break;  

        case MSG_ID_MEDIA_VT_SWITCH_VIDEO_SIZE:
            vcall_adjust_size_ind_hdlr(ilm_ptr);
            break;      

        default:
            ASSERT(0);
    }
}




#endif /* __MED_VCALL_MOD__ */

