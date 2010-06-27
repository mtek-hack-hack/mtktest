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
 * aud_bt_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes BT service functions
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

extern void aud_bt_a2dp_open_codec_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_a2dp_close_codec_req_hdlr(ilm_struct *ilm_ptr);

#ifdef __MED_BT_MOD__
#ifdef __MED_BT_A2DP_MOD__
extern void aud_bt_a2dp_init(void);
extern void aud_bt_a2dp_stream_start_req(void);
extern kal_uint16 aud_bt_a2dp_stream_reconfig_req(void);
extern void aud_bt_a2dp_stream_close_req(void);
extern void aud_bt_a2dp_stream_pause_req(void);
extern void aud_bt_a2dp_stream_abort_req(void);
extern void aud_bt_a2dp_stream_qos_ind_hdlr(ilm_struct *ilm_ptr);
#endif /* __MED_BT_A2DP_MOD__ */ 

#ifdef __MED_BT_HFP_MOD__
extern void aud_bt_hfp_init(void);
extern void aud_bt_hfp_close_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_hfp_open_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_hfp_sco_connect_cnf_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_hfp_sco_connect_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_hfp_sco_disconnect_cnf_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_hfp_sco_disconnect_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_hfp_turn_on_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_bt_hfp_turn_off_req_hdlr(ilm_struct *ilm_ptr);
#endif /* __MED_BT_HFP_MOD__ */ 


/*****************************************************************************
 * FUNCTION
 *  aud_bt_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_BT_HFP_MOD__
    aud_bt_hfp_init();
#endif 

#ifdef __MED_BT_A2DP_MOD__
    aud_bt_a2dp_init();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_audio_open_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_audio_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_req_struct *msg_p = (media_bt_audio_open_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->profile)
    {
    #ifdef __MED_BT_HFP_MOD__
        case BT_HFP:
            aud_bt_hfp_open_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_BT_HFP_MOD__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_audio_close_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_audio_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_req_struct *msg_p = (media_bt_audio_close_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->profile)
    {
    #ifdef __MED_BT_HFP_MOD__
        case BT_HFP:
            aud_bt_hfp_close_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_BT_HFP_MOD__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_audio_turn_on_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_audio_turn_on_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_turn_on_req_struct *msg_p = (media_bt_audio_turn_on_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->profile)
    {
    #ifdef __MED_BT_HFP_MOD__
        case BT_HFP:
            aud_bt_hfp_turn_on_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_BT_HFP_MOD__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_audio_turn_off_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_audio_turn_off_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_turn_off_req_struct *msg_p = (media_bt_audio_turn_off_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->profile)
    {
    #ifdef __MED_BT_HFP_MOD__
        case BT_HFP:
            aud_bt_hfp_turn_off_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_BT_HFP_MOD__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
    #ifdef __MED_BT_HFP_MOD__
        case MSG_ID_BT_HFG_SCO_CONNECT_CNF:
            aud_bt_hfp_sco_connect_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_BT_HFG_SCO_CONNECT_IND:
            aud_bt_hfp_sco_connect_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_BT_HFG_SCO_DISCONNECT_CNF:
            aud_bt_hfp_sco_disconnect_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_BT_HFG_SCO_DISCONNECT_IND:
            aud_bt_hfp_sco_disconnect_ind_hdlr(ilm_ptr);
            break;
    #endif /* __MED_BT_HFP_MOD__ */ 

        case MSG_ID_MEDIA_BT_AUDIO_OPEN_REQ:
            aud_bt_audio_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BT_AUDIO_CLOSE_REQ:
            aud_bt_audio_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BT_AUDIO_TURN_ON_REQ:
            aud_bt_audio_turn_on_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BT_AUDIO_TURN_OFF_REQ:
            aud_bt_audio_turn_off_req_hdlr(ilm_ptr);
            break;
    #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
        case MSG_ID_BT_A2DP_STREAM_QOS_IND:
            aud_bt_a2dp_stream_qos_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BT_OPEN_CODEC_REQ:
            aud_bt_a2dp_open_codec_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BT_CLOSE_CODEC_REQ:
            aud_bt_a2dp_close_codec_req_hdlr(ilm_ptr);
            break;
    #endif /* __BTMTK__ && __MED_BT_A2DP_MOD__ */
        default:
            return KAL_FALSE;
    }

    return KAL_TRUE;
}
#endif /* __MED_BT_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

