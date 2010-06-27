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
 *   aud_vrsi_main.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SI VR  module main function : process SI VR messages 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
#include "stack_config.h"
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
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
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_VRSI_MOD__

#if 0
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
#endif /* 0 */ 

aud_vrsi_context_struct vrsi_ctx;

#define MED_AUD_VRSI_STATE_IDLE  0x1
#define MED_AUD_VRSI_STATE_READY  0x2
#define MED_AUD_VRSI_STATE_PROCESS  0x4


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_startup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_startup(void)
{
#ifdef __NVRAM_IN_USB_MS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack_query_boot_mode() == USBMS_BOOT)
    {
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    aud_context_p->vrsi_event = kal_create_event_group("vrsi_events");

    kal_wsprintf(vrsi_ctx.db_path, "Z:\\@VRSI\\");
    aud_create_full_path_folder(vrsi_ctx.db_path);

    vrsi_ctx.state = MED_AUD_VRSI_STATE_IDLE;
    vrsi_ctx.session_id = 0;
    vrsi_ctx.session_on = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_VRSI_INIT_REQ:
            aud_vrsi_init_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_ADD_TAGS_REQ:
            aud_vrsi_add_tags_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_START_TRN_REQ:
            aud_vrsi_start_trn_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_START_RCG_REQ:
            aud_vrsi_start_rcg_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_PROCESS_IND:
            aud_vrsi_process_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_PLAY_TAG_REQ:
            aud_vrsi_play_tag_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_PLAY_TTS_REQ:
            aud_vrsi_play_tts_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_GET_TAGNUM_REQ:
            aud_vrsi_get_tagnum_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_GET_TAGINFO_REQ:
            aud_vrsi_get_taginfo_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_DEL_TAGS_REQ:
            aud_vrsi_del_tags_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_RESET_TAGS_REQ:
            aud_vrsi_reset_tags_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_SYNC_DB_REQ:
            aud_vrsi_sync_db_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VRSI_ABORT_REQ:
            aud_vrsi_abort_req_hdlr(ilm_ptr);
            vrsi_ctx.session_on = KAL_FALSE;
            break;
        case MSG_ID_MEDIA_VRSI_CLOSE_REQ:
            aud_vrsi_close_req_hdlr(ilm_ptr);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_new_session_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 media_aud_vrsi_new_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        return 0;
    }
    else
    {
        vrsi_ctx.session_on = KAL_TRUE;
        vrsi_ctx.session_id++;
        if (vrsi_ctx.session_id == 0)
        {
            vrsi_ctx.session_id++;
        }

        return vrsi_ctx.session_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_prompt_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_prompt_cnf(module_type src_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vrsi_ctx.session_on || vrsi_ctx.session_id != session_id)
    {
        return;
    }
    else
    {
        aud_vrsi_prompt_cnf();
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_read_dgt_adp_prompt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pmp_len         [?]         
 *  pmp_text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_read_dgt_adp_prompt(kal_uint8 *pmp_len, const kal_uint16 **pmp_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pmp_len = vrsi_ctx.pmp_len;
    *pmp_text = vrsi_ctx.pmp_text;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_read_cmd_trn_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 media_aud_vrsi_read_cmd_trn_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vrsi_ctx.tag_param.tagID;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_read_cmd_rcg_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vrsi_rcg_res        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_read_cmd_rcg_result(media_aud_vrsi_cmd_rcg_result_struct *vrsi_rcg_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vrsi_rcg_res->res_type = vrsi_ctx.recog_result->resType;
    vrsi_rcg_res->tag_num = vrsi_ctx.recog_result->numTag;
    vrsi_rcg_res->id_list = vrsi_ctx.recog_result->pTagID;
    vrsi_rcg_res->name_list = vrsi_ctx.recog_result->ppTagName;
    vrsi_rcg_res->long_list = vrsi_ctx.recog_result->pTagLong;
    vrsi_rcg_res->pre_cmd = vrsi_ctx.recog_result->preCmd;
    vrsi_rcg_res->post_cmd = vrsi_ctx.recog_result->postCmd;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_read_dgt_rcg_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  digit_length        [?]         
 *  digit_list          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_read_dgt_rcg_result(kal_uint16 *digit_length, kal_uint16 **digit_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *digit_length = vrsi_ctx.dgt_rcg_result->digitLen;
    *digit_list = vrsi_ctx.dgt_rcg_result->pDigits;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_query_tag_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar         [?]         
 *  tag_long        [IN]        
 *  tag_id          [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_query_tag_id(kal_uint8 *grammar, kal_int32 tag_long, kal_uint16 *tag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        return MED_RES_VRSI_ERR_BUSY;
    }

    if (VRSI_QueryTagId(grammar, tag_long, tag_id) == VRSI_FAIL)
    {
        return aud_vrsi_error();
    }

    return MED_RES_VRSI_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_query_next_tag_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [?]     
 *  tag_id      [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_query_next_tag_id(kal_uint8 *grammar, kal_uint16 *tag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        return MED_RES_VRSI_ERR_BUSY;
    }

    if (VRSI_QueryNextTagId(grammar, tag_id) == VRSI_FAIL)
    {
        return aud_vrsi_error();
    }

    return MED_RES_VRSI_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_query_all_tag_ids
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar         [?]         
 *  tag_long        [IN]        
 *  buf_size        [IN]        
 *  id_buf          [?]         
 *  tag_num         [?]         
 *  getAll          [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_query_all_tag_ids(
            kal_uint8 *grammar,
            kal_int32 tag_long,
            kal_uint16 buf_size,
            kal_uint16 *id_buf,
            kal_uint16 *tag_num,
            kal_bool *getAll)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        return MED_RES_VRSI_ERR_BUSY;
    }

    if (VRSI_QueryAllTagIds(grammar, tag_long, buf_size, id_buf, tag_num, getAll) == VRSI_FAIL)
    {
        return aud_vrsi_error();
    }

    return MED_RES_VRSI_OK;
}

/* message handler */

/* initialization */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_init_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_init_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = aud_vrsi_init();

    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_INIT);
}

/* SIVR functions */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_add_tags_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_add_tags_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_add_tags_req_struct *msg_p = (media_vrsi_add_tags_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vrsi_ctx.session_on || vrsi_ctx.session_id != msg_p->session_id)
    {
        result = MED_RES_VRSI_ERR_SESSION;
    }
    else
    {
        vrsi_ctx.grammar = msg_p->grammar;
        vrsi_ctx.addtags_param.numTag = msg_p->tag_num;
        vrsi_ctx.addtags_param.ppTagName = msg_p->name_list;
        vrsi_ctx.addtags_param.pTagLong = msg_p->long_list;
        vrsi_ctx.addtags_param.pIsPeopleName = msg_p->is_name_list;
        vrsi_ctx.id_list = msg_p->id_list;

        result = aud_vrsi_add_tags();
    }
    if (result != MED_RES_OK)
    {
        aud_set_result(result);
        VRSI_SET_EVENT(VRSI_EVT_ADD_TAGS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_start_trn_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_start_trn_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_start_trn_req_struct *msg_p = (media_vrsi_start_trn_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vrsi_ctx.session_on || vrsi_ctx.session_id != msg_p->session_id)
    {
        result = MED_RES_VRSI_ERR_SESSION;
    }
    else
    {
        if (msg_p->grammar != NULL)
        {
            vrsi_ctx.grammar = msg_p->grammar;
            vrsi_ctx.tag_param.pTagName = msg_p->tag_name;
            vrsi_ctx.tag_param.tagLong = msg_p->tag_long;
            result = aud_vrsi_start_cmd_trn();
        }
        else
        {
            result = aud_vrsi_start_digit_adapt(msg_p->lang);
        }
    }

    aud_set_result(result);

    if (msg_p->grammar != NULL)
    {
        VRSI_SET_EVENT(VRSI_EVT_START_CMD_TRN);
    }
    else
    {
        VRSI_SET_EVENT(VRSI_EVT_START_DIGIT_ADAPT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_start_rcg_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_start_rcg_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_start_rcg_req_struct *msg_p = (media_vrsi_start_rcg_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vrsi_ctx.session_on || vrsi_ctx.session_id != msg_p->session_id)
    {
        result = MED_RES_VRSI_ERR_SESSION;
    }
    else
    {
        if (msg_p->grammar != NULL)
        {
            vrsi_ctx.grammar = msg_p->grammar;
            result = aud_vrsi_start_cmd_rcg();
        }
        else
        {
            result = aud_vrsi_start_digit_rcg(msg_p->lang, msg_p->limit);
        }
    }

    aud_set_result(result);

    if (msg_p->grammar != NULL)
    {
        VRSI_SET_EVENT(VRSI_EVT_START_CMD_RCG);
    }
    else
    {
        VRSI_SET_EVENT(VRSI_EVT_START_DIGIT_RCG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_process_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_process_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_process_ind_struct *msg_p = (media_vrsi_process_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_PROCESS)
    {
        return;
    }

    switch (msg_p->proc_type)
    {
        case VRSI_PROCESS:
            VRSI_Process();
            break;
        case VRSI_RECOG_MPR:
            aud_send_vrsi_rcg_prompt_req(MOD_MMI, vrsi_ctx.session_id, MED_VRSI_CMD_RCG_PROMPT);
            break;
        case VRSI_RECOG_OK:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            VRSI_ReadResult((void **)&(vrsi_ctx.recog_result));
            vrsi_ctx.session_on = KAL_FALSE;
            aud_send_vrsi_rcg_result_ind(MOD_MMI, vrsi_ctx.session_id, vrsi_ctx.recog_result->resType);
            break;
        case VRSI_DIGIT_RECOG_MPR:
            aud_send_vrsi_rcg_prompt_req(MOD_MMI, vrsi_ctx.session_id, MED_VRSI_DGT_RCG_PROMPT);
            break;
        case VRSI_DIGIT_RECOG_OK:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            VRSI_ReadResult((void **)&(vrsi_ctx.dgt_rcg_result));
            vrsi_ctx.session_on = KAL_FALSE;
            aud_send_vrsi_rcg_result_ind(MOD_MMI, vrsi_ctx.session_id, 0);
            break;
        case VRSI_DIGIT_ADAPT_MPR:
            VRSI_ReadPrompt(&vrsi_ctx.pmp_len, &vrsi_ctx.pmp_text);
            aud_send_vrsi_trn_prompt_req(MOD_MMI, vrsi_ctx.session_id, MED_VRSI_1ST_DGT_ADP_PROMPT);
            break;
        case VRSI_DIGIT_ADAPT_OK:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            vrsi_ctx.session_on = KAL_FALSE;
            aud_send_vrsi_trn_result_ind(MOD_MMI, vrsi_ctx.session_id, 0);
            break;
        case VRSI_TRAIN_TAG_1ST_MPR:
            aud_send_vrsi_trn_prompt_req(MOD_MMI, vrsi_ctx.session_id, MED_VRSI_1ST_TRN_PROMPT);
            break;
        case VRSI_TRAIN_TAG_2ND_MPR:
            aud_send_vrsi_trn_prompt_req(MOD_MMI, vrsi_ctx.session_id, MED_VRSI_2ND_TRN_PROMPT);
            break;
        case VRSI_TRAIN_TAG_OK:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            vrsi_ctx.session_on = KAL_FALSE;
            aud_send_vrsi_trn_result_ind(MOD_MMI, vrsi_ctx.session_id, vrsi_ctx.tag_param.tagID);
            break;
        case VRSI_ADD_TAGS_OK:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            vrsi_ctx.session_on = KAL_FALSE;
            aud_vrsi_save_addtags_result();
            aud_set_result(MED_RES_OK);
            VRSI_SET_EVENT(VRSI_EVT_ADD_TAGS);
            break;
        case VRSI_TTS_OK:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            vrsi_ctx.session_on = KAL_FALSE;
            aud_send_vrsi_play_tts_finish_ind(MOD_MMI, vrsi_ctx.session_id);
            break;
        case VRSI_PLAY_TAG_OK:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            vrsi_ctx.session_on = KAL_FALSE;
            aud_send_vrsi_play_tag_finish_ind(MOD_MMI, vrsi_ctx.session_id);
            break;
        case VRSI_ERROR:
            vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
            vrsi_ctx.session_on = KAL_FALSE;
            aud_send_vrsi_err_ind(MOD_MMI, vrsi_ctx.session_id);
            break;
    }
}

/* play */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_play_tag_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_play_tag_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tag_req_struct *msg_p = (media_vrsi_play_tag_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vrsi_ctx.session_on || vrsi_ctx.session_id != msg_p->session_id)
    {
        result = MED_RES_VRSI_ERR_SESSION;
    }
    else
    {
        SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, msg_p->volume);
        aud_set_active_ring_tone_volume();

        aud_context_p->melody_output_device = msg_p->output_path;
        aud_get_active_device_path_by_mode(msg_p->output_path, aud_melody_set_output_device);

        vrsi_ctx.grammar = msg_p->grammar;

        result = aud_vrsi_play_tag(msg_p->tag_id);
    }

    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_PLAY_TAG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_play_tts_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_play_tts_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tts_req_struct *msg_p = (media_vrsi_play_tts_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vrsi_ctx.session_on || vrsi_ctx.session_id != msg_p->session_id)
    {
        result = MED_RES_VRSI_ERR_SESSION;
    }
    else
    {
        SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, msg_p->volume);
        aud_set_active_ring_tone_volume();

        aud_context_p->melody_output_device = msg_p->output_path;
        aud_get_active_device_path_by_mode(msg_p->output_path,aud_melody_set_output_device);

        vrsi_ctx.pmp_text = msg_p->text;
        result = aud_vrsi_play_tts(msg_p->lang);
    }

    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_PLAY_TTS);
}

/* database maagement : ok */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_get_tagnum_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_get_tagnum_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_get_tagnum_req_struct *msg_p = (media_vrsi_get_tagnum_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        result = MED_RES_VRSI_ERR_BUSY;
    }
    else
    {
        vrsi_ctx.grammar = msg_p->grammar;
        result = aud_vrsi_get_tagnum(msg_p->tag_num);
    }

    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_GET_TAG_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_get_taginfo_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_get_taginfo_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_get_taginfo_req_struct *msg_p = (media_vrsi_get_taginfo_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        result = MED_RES_VRSI_ERR_BUSY;
    }
    else
    {
        vrsi_ctx.grammar = msg_p->grammar;

        result = aud_vrsi_get_tag_info(msg_p->tag_num, msg_p->id_list, msg_p->name_list, msg_p->long_list);
    }

    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_GET_TAG_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_del_tags_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_del_tags_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_del_tags_req_struct *msg_p = (media_vrsi_del_tags_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        result = MED_RES_VRSI_ERR_BUSY;
    }
    else
    {
        vrsi_ctx.grammar = msg_p->grammar;

        result = aud_vrsi_del_tags(msg_p->tag_num, msg_p->id_list);
    }

    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_DEL_TAGS);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_reset_tags_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_reset_tags_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_reset_tags_req_struct *msg_p = (media_vrsi_reset_tags_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        result = MED_RES_VRSI_ERR_BUSY;
    }
    else
    {
        vrsi_ctx.grammar = msg_p->grammar;

        result = aud_vrsi_reset_tags();
    }

    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_RESET_TAGS);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_sync_db_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_sync_db_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_sync_db_req_struct *msg_p = (media_vrsi_sync_db_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        result = MED_RES_VRSI_ERR_BUSY;
    }
    else
    {
        vrsi_ctx.grammar = msg_p->grammar;
        if (msg_p->name_list == NULL)
        {
            result = aud_vrsi_sync_db_by_id(msg_p->tag_num, msg_p->id_list, msg_p->sync_flag);
        }
        else
        {
            result = aud_vrsi_sync_db(msg_p->tag_num, msg_p->id_list, msg_p->name_list, msg_p->sync_flag);
        }
    }
    aud_set_result(result);
    VRSI_SET_EVENT(VRSI_EVT_SYNC_DB);
}

/* termination */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_abort_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_abort_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_trn_result_ind_struct *msg_p = (media_vrsi_trn_result_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vrsi_ctx.session_on || vrsi_ctx.session_id != msg_p->session_id)
    {
        VRSI_SET_EVENT(VRSI_EVT_ABORT);
        return;
    }

    aud_vrsi_abort();
    VRSI_SET_EVENT(VRSI_EVT_ABORT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_close_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.session_on)
    {
        aud_vrsi_abort();
    }

    aud_vrsi_close();
    VRSI_SET_EVENT(VRSI_EVT_CLOSE);
}

#if !defined(__MTK_TARGET__)


/*****************************************************************************
 * FUNCTION
 *  VRSI_Init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vrsi_handler        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Init(void (*vrsi_handler) (VRSI_Event event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_GetMemRequest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  maxRecogTag     [IN]        
 *  maxSDTag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 VRSI_GetMemRequest(kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_SetMem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memory          [?]         
 *  size            [IN]        
 *  maxRecogTag     [IN]        
 *  maxSDTag        [IN]        
 *  vrsiDir         [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_SetMem(kal_uint8 *memory, kal_uint32 size, kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag ,uint16 *vrsiDir) 

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Add_Tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 *  param       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Add_Tags(const kal_uint8 *grammar, VRSI_AddTags_Param *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Train_Tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 *  param       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Train_Tag(const kal_uint8 *grammar, VRSI_Tag_Param *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Recog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Recog(const kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Digit_Recog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang        [IN]        
 *  limit       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Digit_Recog(VRSI_Language lang, kal_uint16 limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Digit_Adapt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Digit_Adapt(VRSI_Language lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Play_Tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 *  tagID       [IN]        
 *  param       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Play_Tag(const kal_uint8 *grammar, kal_uint16 tagID, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_TTS_Play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang        [IN]        
 *  pText       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_TTS_Play(VRSI_Language lang, kal_uint16 *pText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_ReadPrompt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  promptLen       [?]         
 *  prompt          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VRSI_ReadPrompt(kal_uint8 *promptLen, const kal_uint16 **prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_MMI_Confirmed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VRSI_MMI_Confirmed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_ReadResult
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VRSI_ReadResult(void **result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_GetErrMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VRSI_ErrMsg VRSI_GetErrMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Gram_GetTagNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 *  tagNum      [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Gram_GetTagNum(const kal_uint8 *grammar, kal_int32 *tagNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Gram_ReadTagIDs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar         [IN]        
 *  pTagID          [?]         
 *  bufferSize      [IN]        
 *  readTagNum      [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Gram_ReadTagIDs(
                const kal_uint8 *grammar,
                kal_uint16 *pTagID,
                kal_int32 bufferSize,
                kal_int32 *readTagNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Gram_DeleteAllTags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Gram_DeleteAllTags(const kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_DeleteTags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar         [IN]        
 *  tagNum          [IN]        
 *  pTagID          [IN]        
 *  delTagNum       [?]         
 *  pDelagID        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_DeleteTags(
                const kal_uint8 *grammar,
                kal_int32 tagNum,
                const kal_uint16 *pTagID,
                kal_int32 *delTagNum,
                kal_uint16 *pDelagID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_TagExist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 *  tagID       [IN]        
 *  bExist      [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_TagExist(const kal_uint8 *grammar, kal_uint16 tagID, kal_bool *bExist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_ReadTags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar         [IN]        
 *  tagNum          [IN]        
 *  pTagID          [IN]        
 *  ppTagName       [IN]        
 *  pTagLong        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_ReadTags(
                const kal_uint8 *grammar,
                kal_int32 tagNum,
                const kal_uint16 *pTagID,
                kal_uint16 **ppTagName,
                kal_int32 *pTagLong)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_Close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_Close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_QueryTagId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 *  tagLong     [IN]        
 *  tagID       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_QueryTagId(const kal_uint8 *grammar, kal_int32 tagLong, kal_uint16 *tagID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_QueryNextTagId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar     [IN]        
 *  tagID       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_QueryNextTagId(const kal_uint8 *grammar, kal_uint16 *tagID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VRSI_QueryAllTagIds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grammar         [IN]        
 *  tagLong         [IN]        
 *  buf_size        [IN]        
 *  id_buf          [?]         
 *  tagNum          [?]         
 *  getAll          [?]         
 * RETURNS
 *  
 *****************************************************************************/
VRSI_Status VRSI_QueryAllTagIds(
                const kal_uint8 *grammar,
                kal_int32 tagLong,
                kal_uint16 buf_size,
                kal_uint16 *id_buf,
                kal_uint16 *tagNum,
                kal_bool *getAll)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* !defined(__MTK_TARGET__) */ 

#endif /* __MED_VRSI_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

