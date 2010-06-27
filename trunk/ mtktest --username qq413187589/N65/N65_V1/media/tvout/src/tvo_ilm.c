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
 * tvo_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of tvout module.
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

/*==== INCLUDES ===========*/

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
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"

#ifdef __MED_TVO_MOD__


/*****************************************************************************
 * FUNCTION
 *  tvo_send_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_send_start_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_start_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;
    tvo_mode_struct *data_p = (tvo_mode_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_tvo_start_req_struct*) construct_local_para(sizeof(media_tvo_start_req_struct), TD_CTRL);
    msg_p->tv_output_mode = data_p->tv_output_mode;
    msg_p->tv_output_format = data_p->tv_output_format;
    msg_p->tv_output_width = data_p->tv_output_width;
    msg_p->tv_output_height = data_p->tv_output_height;

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_TVO_START_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_send_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_send_stop_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_stop_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_tvo_stop_req_struct*) construct_local_para(sizeof(media_tvo_stop_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_TVO_STOP_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_send_set_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_send_set_mode_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_set_mode_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;
    tvo_mode_struct *data_p = (tvo_mode_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_tvo_set_mode_req_struct*) construct_local_para(sizeof(media_tvo_set_mode_req_struct), TD_CTRL);

    msg_p->tv_output_mode = data_p->tv_output_mode;
    msg_p->tv_output_format = data_p->tv_output_format;
    msg_p->tv_output_width = data_p->tv_output_width;
    msg_p->tv_output_height = data_p->tv_output_height;
    msg_p->tv_output_vertical_filter = data_p->tv_output_vertical_filter;

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_TVO_SET_MODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_send_set_param_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_send_set_param_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_set_param_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_tvo_set_param_req_struct*) construct_local_para(sizeof(media_tvo_set_param_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_tvo_set_param_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_TVO_SET_PARAM_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_send_av_cable_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_send_av_cable_detect_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_av_cable_detect_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_tvo_av_cable_detect_ind_struct*)
        construct_local_para(sizeof(media_tvo_av_cable_detect_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_JPEG_HISR);
    ilm_ptr->src_mod_id = MOD_JPEG_HISR;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_TVO_AV_CABLE_DETECT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_send_tv_connect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_send_tv_connect_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_tv_connect_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_tvo_tv_connect_ind_struct*) construct_local_para(sizeof(media_tvo_tv_connect_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_TVO_TV_CONNECT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

#endif /* __MED_TVO_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

