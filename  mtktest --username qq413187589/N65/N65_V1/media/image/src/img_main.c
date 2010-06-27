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
 *   img_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of image module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "img_main.h"

#if defined(JPG_DECODE) || defined(JPG_ENCODE)
#include "visual_comm.h"
#include "jpeg.h"
#endif /* defined(JPG_DECODE) || defined(JPG_ENCODE) */ 

#ifdef __IMG_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_IMG_MOD__

img_context_struct *img_context_p = &(med_context.img_context);

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  img_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of image module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->src_mod = ilm_ptr->src_mod_id;
    // moved to img_init()
    //   img_context_p->img_event = kal_create_event_group("img_events");

}


/*****************************************************************************
 * FUNCTION
 *  img_main
 * DESCRIPTION
 *  This function is main message dispatching function of image module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_IMG_DECODE_REQ:
            img_decode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IMG_DECODE_EVENT_IND:
            img_decode_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IMG_ENCODE_REQ:
            img_encode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IMG_ENCODE_EVENT_IND:
            img_encode_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IMG_STOP_REQ:
            img_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IMG_RESIZE_REQ:
            img_resize_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IMG_EXIF_DECODE_REQ:
            img_exif_decode_req_hdlr(ilm_ptr);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  img_init
 * DESCRIPTION
 *  This function is used to init image module of media task.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool img_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->state = IMG_IDLE;

    img_context_p->file_buffer_address = NULL;
    img_context_p->intmem_start_address = NULL;
    img_context_p->extmem_start_address = NULL;
    img_context_p->processing = KAL_FALSE;
    img_context_p->img_event = kal_create_event_group("img_events");
#if (defined(JPG_DECODE) || defined(JPG_ENCODE)) && defined(__MTK_TARGET__)
    jpeg_codec_init();
#endif 
    return KAL_TRUE;
}

#endif /* __MED_IMG_MOD__ */ 
#endif /* MED_NOT_PRESENT */ 

