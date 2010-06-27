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
 * aud_bt_hfp.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes BT HFP service functions
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
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
#include "med_utility.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_BT_HFP_MOD__
#include "bt_dm_struct.h"
#include "bt_hfg_struct.h"
#include "bt_hfg.h"

extern kal_bool aud_bt_hfp_sco_connect_req(void);
extern kal_bool aud_bt_hfp_sco_disconnect_req(void);

typedef struct
{
    module_type src_mod_id;
    kal_uint16 connect_id;
    kal_bool disabled;  /* Disable set audio path and not allow turn on SCO */
    kal_bool audio_path_on;
    kal_uint8 state;
    kal_uint8 next_cmd;
    kal_uint8 speech_mode;
} aud_bt_hfp_context_struct;

aud_bt_hfp_context_struct aud_bt_hfp_ctx;


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_reset_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_reset_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY(AUD_BT_HFP_RESET_STATE)
    
    aud_bt_hfp_ctx.src_mod_id = MOD_MMI;  /* set MMI as the default receiver */
    
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);
    aud_bt_hfp_ctx.audio_path_on = KAL_FALSE;
    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    aud_bt_hfp_ctx.disabled = KAL_FALSE;
    aud_bt_hfp_ctx.speech_mode = BT_HFP_EARPHONE_MODE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_bt_hfp_reset_state();
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_close_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* media_bt_audio_close_req_struct* msg_p = (media_bt_audio_close_req_struct*)ilm_ptr->local_para_ptr; */

    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_CLOSE_REQ_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on)
    aud_bt_hfp_set_audio_path(KAL_FALSE);

    if (!aud_bt_hfp_sco_disconnect_req())
    {
        aud_send_bt_audio_close_cnf(aud_bt_hfp_ctx.src_mod_id, BT_HFP, MED_RES_OK);
    }

    /* To make sure message send to BT task before MMI task continues */
    /* Because there may have sleep function when change audio path */
    AUD_SET_EVENT(AUD_EVT_BT_CLOSE_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_open_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_req_struct *msg_p = (media_bt_audio_open_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_OPEN_REQ_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on)
    
    aud_bt_hfp_ctx.src_mod_id = ilm_ptr->src_mod_id;
    aud_bt_hfp_ctx.connect_id = msg_p->connect_id;
    aud_bt_hfp_ctx.speech_mode = msg_p->mode;

    if( aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE )
    {
        ASSERT(aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_NONE);

        aud_bt_hfp_sco_connect_req();
    }
    else
    {
        aud_send_bt_audio_open_cnf(aud_bt_hfp_ctx.src_mod_id, BT_HFP, MED_RES_BUSY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_turn_on_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_turn_on_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2( AUD_BT_HFP_TURN_ON_REQ_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on );

    /* Turn on path if path is not turn on yet */
    if(!aud_bt_hfp_ctx.audio_path_on)
    {
        aud_bt_hfp_ctx.audio_path_on = KAL_TRUE;
        aud_bt_hfp_set_audio_path_on();
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_turn_off_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_turn_off_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2( AUD_BT_HFP_TURN_OFF_REQ_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on );

    /* Turn off path if path is on */
    if(aud_bt_hfp_ctx.audio_path_on)
    {
        aud_bt_hfp_ctx.audio_path_on = KAL_FALSE;
        aud_bt_hfp_set_audio_path_off();
    }

    /* To make sure message send to BT task before MMI task continues */
    /* Because there may have sleep function when change audio path */
    AUD_SET_EVENT(AUD_EVT_BT_TURN_OFF_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_hfp_sco_connect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool processed = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_NONE)
    {
        if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
        {
            /* Set path before connect request */
            //aud_bt_hfp_set_audio_path(KAL_TRUE);
            bt_hfg_send_sco_connect_req(MOD_MED, aud_bt_hfp_ctx.connect_id);
        }
        else
        {
            processed = KAL_FALSE;
        }
    }

    if (processed)
    {
        aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_CONNECT_SCO;
    }

    return processed;
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_connect_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_sco_connect_cnf_struct *msg_p = (bt_hfg_sco_connect_cnf_struct*) ilm_ptr->local_para_ptr;
    kal_bool next_disc = (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_DISCONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3( AUD_BT_HFP_SCO_CONNECT_CNF_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on, msg_p->result)
    
    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;

    if (msg_p->result == BT_HFG_RESULT_OK)
    {
        AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_OPEN);

        aud_send_bt_audio_open_ind(aud_bt_hfp_ctx.src_mod_id, BT_HFP);

        if (next_disc)
        {
            aud_bt_hfp_sco_disconnect_req();
        }
        else
        {
        	/* check if it's disabled */
		    if (aud_bt_hfp_ctx.disabled)
		    {
	        	return;
	        }

            /* Set path after the connect request */
            aud_bt_hfp_set_audio_path(KAL_TRUE);
        }
    }
    else
    {
        //aud_bt_hfp_set_audio_path(KAL_FALSE);
        aud_send_bt_audio_open_cnf(aud_bt_hfp_ctx.src_mod_id, BT_HFP, MED_RES_FAIL);

        if (next_disc)
        {
            aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, BT_HFP, MED_RES_OK);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_connect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_connect_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* bt_hfg_sco_connect_ind_struct *msg_p = (bt_hfg_sco_connect_ind_struct*)ilm_ptr->local_para_ptr; */
    kal_bool next_disc = (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_DISCONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SCO_CONNECT_IND_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on)
    
    ASSERT(aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE);

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_OPEN);

    aud_send_bt_audio_open_ind(aud_bt_hfp_ctx.src_mod_id, BT_HFP);

    if (next_disc)
    {
        aud_bt_hfp_sco_disconnect_req();
    }
#ifdef __MED_BT_FM_VIA_SCO__
    /* Can not accept SCO connect while FM recording. */
    else if(aud_fmr_is_power_on() &&
           (aud_context_p->state == AUD_MEDIA_RECORD || aud_context_p->state == AUD_MEDIA_RECORD_PAUSED))
    {
        aud_bt_hfp_sco_disconnect_req();    
    }
#endif /* __MED_BT_FM_VIA_SCO__ */
#if defined (__MED_BT_A2DP_MOD__) && defined (__BTMTK__)
    /* Can not accept SCO connect while A2DP codec is open */
    else if(aud_bt_a2dp_is_codec_opened())
    {
        aud_bt_hfp_sco_disconnect_req();
    }
#endif /* defined (__MED_BT_A2DP_MOD__) && defined (__BTMTK__) */
    else
    {
    	/* check if it's disabled */
	    if (aud_bt_hfp_ctx.disabled)
	    {
        	return;
        }
        
        aud_bt_hfp_set_audio_path(KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_hfp_sco_disconnect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool processed = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_NONE)
    {
        if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_OPEN)
        {
            bt_hfg_send_sco_disconnect_req(MOD_MED, aud_bt_hfp_ctx.connect_id);
        }
        else
        {
            processed = KAL_FALSE;
        }
    }

    if (processed)
    {
        aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_DISCONNECT_SCO;
    }

    return processed;
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_disconnect_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_sco_disconnect_cnf_struct *msg_p = (bt_hfg_sco_disconnect_cnf_struct*) ilm_ptr->local_para_ptr;
    kal_uint16 result;
    kal_bool next_conn = (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_CONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3(
        AUD_BT_HFP_SCO_DISCONNECT_CNF_HDLR,
        aud_bt_hfp_ctx.state,
        aud_bt_hfp_ctx.audio_path_on,
        msg_p->result)

    if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
    {
        return;
    }

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);

    if (msg_p->result == BT_HFG_RESULT_OK)
    {
        result = MED_RES_OK;
    }
    else
    {
        result = MED_RES_FAIL;
    }

    aud_bt_hfp_set_audio_path(KAL_FALSE);

    aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, BT_HFP, result);

	/* check if it's disabled */
    if (aud_bt_hfp_ctx.disabled)
    {
        return;
    }

    if (next_conn)
    {
        aud_bt_hfp_sco_connect_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_sco_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_sco_disconnect_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* bt_hfg_sco_disconnect_ind_struct *msg_p = (bt_hfg_sco_disconnect_ind_struct*)ilm_ptr->local_para_ptr; */
    kal_bool next_conn = (aud_bt_hfp_ctx.next_cmd == AUD_BT_HFP_CMD_CONNECT_SCO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SCO_DISCONNECT_IND_HDLR, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on)

    if (aud_bt_hfp_ctx.state == AUD_BT_HFP_STATE_IDLE)
    {
        return;    
    }

    aud_bt_hfp_ctx.next_cmd = AUD_BT_HFP_CMD_NONE;
    AUD_BT_HFP_ENTER_STATE(AUD_BT_HFP_STATE_IDLE);

    aud_bt_hfp_set_audio_path(KAL_FALSE);

    aud_send_bt_audio_close_ind(aud_bt_hfp_ctx.src_mod_id, BT_HFP, MED_RES_HFP_CLOSE);

	/* check if it's disabled */
    if (aud_bt_hfp_ctx.disabled)
    {
        return;
    }

    if (next_conn)
    {
        aud_bt_hfp_sco_connect_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_is_audio_path_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_hfp_is_audio_path_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_IS_AUDIO_PATH_ON, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on)

    return aud_bt_hfp_ctx.audio_path_on;
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_path_delay_timer_hdlr
 * DESCRIPTION
 *  Mute microphone before set speech mode and unmute it after a short time
 *  to avoid noise goes to uplink right after connect
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_bt_hfp_set_path_delay_timer_hdlr(void *arg)
{
    L1SP_MuteMicrophone(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_audio_path_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_bt_hfp_set_audio_path_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 speech_mode;
    kal_uint8 speech_param_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SET_AUDIO_PATH_ON, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on);

    if (aud_context_p->speech_on)
    {
        L1SP_Speech_Off();
    }

#ifdef __MED_BT_FM_VIA_SCO__
    if(aud_fmr_is_power_on())
    {
        /* Set Speech Path*/
        speech_mode = SPH_MODE_FM_VIA_BT_CORDLESS;
        speech_param_index = SPH_MODE_BT_EARPHONE;

        /* Also need to set FM radio input path*/
        L1SP_SetInputSource(L1SP_LNA_FMRR);

        /* Set FM Radio Path */
        if(aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            aud_fmr_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));            
        }
        else
        {
            /* Mute loud speaker, but need output to earphone to get signal */
            aud_fmr_set_output_device(0);
        }
    }
    else
#endif /* __MED_BT_FM_VIA_SCO__ */
    {
        /* Set Speech Path*/            
        if(aud_bt_hfp_ctx.speech_mode == BT_HFP_CARKIT_MODE)
        {
            speech_mode = SPH_MODE_BT_CARKIT;
            speech_param_index = SPH_MODE_BT_CARKIT;
        }
        else
        {
            speech_mode = SPH_MODE_BT_EARPHONE;
            speech_param_index = SPH_MODE_BT_EARPHONE;
        }

        /* Set Audio Path */
        if(aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            aud_melody_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));            
        }
        else
        {
            aud_melody_set_output_device(0); /* Mute loud speaker */
        }
    }

    /* Mute speech, keypad tone output device */
    aud_speech_set_output_device(0);
    aud_keytone_set_output_device(0);
    aud_tone_set_output_device(0);

    /* Set FIR coeffinient */
    aud_speech_set_fir_coefficient(3,3);

    /* Mute microphone for a short time to avoid noise goes to uplink */
    L1SP_MuteMicrophone(KAL_TRUE);
    med_stop_timer(AUD_BT_SET_PATH_TIMER);
    med_start_timer(AUD_BT_SET_PATH_TIMER, 1000, aud_bt_hfp_set_path_delay_timer_hdlr, 0);

    /* Set speech mode*/
    L1SP_SetSpeechMode(speech_mode, aud_context_p->audio_param.speech_mode_para[speech_param_index]);

    if (aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_audio_path_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_set_audio_path_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_path = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY2(AUD_BT_HFP_SET_AUDIO_PATH_OFF, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on);

    if (aud_context_p->speech_on)
    {
        L1SP_Speech_Off();
    }

    /* Stop delay timer and unmute microphone when set path back to phone */
    med_stop_timer(AUD_BT_SET_PATH_TIMER);
    L1SP_MuteMicrophone(KAL_FALSE);

    /* Set Speech Mode*/        
    L1SP_SetSpeechMode(
        aud_context_p->audio_mode,
        aud_context_p->audio_param.speech_mode_para[aud_context_p->audio_mode]);

    /* Set speech output device */
    if(aud_context_p->audio_mode == AUD_MODE_NORMAL)
    {
        audio_path = AUDIO_DEVICE_SPEAKER;
    }
    else if(aud_context_p->audio_mode == AUD_MODE_HEADSET)
    {
        audio_path = AUDIO_DEVICE_SPEAKER2;
    }
    else if(aud_context_p->audio_mode == AUD_MODE_LOUDSPK)
    {
        audio_path = AUDIO_DEVICE_LOUDSPEAKER;
    }
    else
    {
        ASSERT(0);
    }

    /* Restore speech, keypad tone output device path*/
    aud_speech_set_output_device(custom_cfg_hw_aud_output_path(audio_path));
    aud_keytone_set_output_device(custom_cfg_hw_aud_output_path(audio_path));
    aud_tone_set_output_device(custom_cfg_hw_aud_output_path(audio_path));

    /* set speech FIR coefficient */
    aud_speech_set_fir_index_by_mode(aud_context_p->audio_mode);

    /* Set Audio Path */
    aud_audio_set_melody_path_volume(aud_context_p->audio_mode);

#ifdef __MED_BT_FM_VIA_SCO__
    /* Restore input source when disconnect SCO */
    L1SP_SetInputSource(aud_context_p->input_device);

    /* Set FM Radio Path */
    aud_audio_set_fmrdo_path_volume(aud_context_p->audio_mode);
#endif /* __MED_BT_FM_VIA_SCO__ */

    if (aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_hfp_set_audio_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_hfp_set_audio_path(kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_BT_HFP_FUNC_ENTRY3(AUD_BT_HFP_SET_AUDIO_PATH, aud_bt_hfp_ctx.state, aud_bt_hfp_ctx.audio_path_on, on)

    if ((aud_bt_hfp_ctx.audio_path_on && !on) || (!aud_bt_hfp_ctx.audio_path_on && on))
    {
        aud_bt_hfp_ctx.audio_path_on = on;
    
        if (on)
        {
            aud_bt_hfp_set_audio_path_on();
        }
        /* Off */
        else
        {
            aud_bt_hfp_set_audio_path_off();
        }
    }
}

#endif /* __MED_BT_HFP_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

