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
 *   img_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary exported functions of image module.
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

#ifdef __IMG_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_IMG_MOD__

static kal_int32 img_result;
static kal_uint32 img_result_arg0;
static kal_uint32 img_result_arg1;
static kal_uint16 decoded_image_width;

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  img_set_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMG_RESULT_TRACE(result, img_context_p->state, img_context_p->seq_num) img_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  img_set_result_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  arg0        [IN]        
 *  arg1        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_set_result_ext(kal_int32 result, kal_uint32 arg0, kal_uint32 arg1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMG_RESULT_TRACE(result, img_context_p->state, img_context_p->seq_num) img_result = result;
    img_result_arg0 = arg0;
    img_result_arg1 = arg1;
}


/*****************************************************************************
 * FUNCTION
 *  img_set_decoded_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_set_decoded_width(kal_uint16 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    decoded_image_width = width;
}


/*****************************************************************************
 * FUNCTION
 *  media_img_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  decode          [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_img_decode(module_type src_mod_id, void *decode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_result = MED_RES_OK;
    img_send_decode_req(src_mod_id, decode);
    IMG_WAIT_EVENT(IMG_EVT_DECODE);

    ((media_img_decode_req_struct*) decode)->decoded_image_width = decoded_image_width;
    /* img_send_decode_finish_ind(MED_RES_OK); */
    return img_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_img_exif_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  exif_decode     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_img_exif_decode(module_type src_mod_id, void *exif_decode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_result = MED_RES_OK;
    img_send_exif_decode_req(src_mod_id, exif_decode);
    IMG_WAIT_EVENT(IMG_EVT_EXIF_DECODE);
    return img_result;

}


/*****************************************************************************
 * FUNCTION
 *  media_img_encode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  encode          [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_img_encode(module_type src_mod_id, img_encode_struct *encode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_result = MED_RES_OK;
    img_send_encode_req(src_mod_id, encode);
    IMG_WAIT_EVENT(IMG_EVT_ENCODE);
    return img_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_img_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_img_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_send_stop_req(src_mod_id);
    IMG_WAIT_EVENT(IMG_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  media_img_resize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  resize          [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_img_resize(module_type src_mod_id, img_resize_struct *resize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_result = MED_RES_OK;
    img_send_resize_req(src_mod_id, resize);
    IMG_WAIT_EVENT(IMG_EVT_RESIZE);
    return img_result;
}

#endif /* __MED_IMG_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

