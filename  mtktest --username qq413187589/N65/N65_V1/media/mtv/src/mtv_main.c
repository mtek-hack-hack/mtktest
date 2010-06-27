/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mtv_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_timer.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "med_global.h"

#if defined(__MED_MTV_MOD__)

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "med_main.h"		/* error codes */
#include "med_struct.h"		/* message struct */
#include "mtv_main.h"
#include "med_trc.h"
#include "mtv_debug_event.h"

#include "tdmb_sp.h"
#include "mtv_sm.h"
#include "cyberlink_tdmb_demux.h"
#include "mtv_async_io.h"

#define MSG_STRUCT(type, name, ilm) \
    type* name  = (type*) ilm->local_para_ptr

#if defined(_MTV_USE_TDMB_TS_DEMOD)
  extern void tdmb_ts_send_data(void);
#else
  #include "tdmb_demod.h"
#endif

extern kal_taskid kal_get_current_thread_ID(void);

typedef enum
{
    MTV_STATE_CLOSED,
    MTV_STATE_OPENED

} mtv_state_t;

typedef enum
{
    MTV_EVT_OPEN_REQ                                = 1 <<  0,
    MTV_EVT_CONFIG_REQ                              = 1 <<  1,
    MTV_EVT_FIND_UNSAVED_RECORDING_REQ              = 1 <<  2,
    MTV_EVT_RECOVER_RECORDING_REQ                   = 1 <<  3,
    MTV_EVT_ABORT_RECOVERING_REQ                    = 1 <<  4,
    MTV_EVT_DISCARD_UNSAVED_RECORDING_REQ           = 1 <<  5,
    MTV_EVT_SEARCH_SERVICES_REQ                     = 1 <<  6,
    MTV_EVT_ABORT_SEARCHING_REQ                     = 1 <<  7,
    MTV_EVT_START_SERVICE_REQ                       = 1 <<  8,
    MTV_EVT_PLAYER_PLAY_REQ                         = 1 <<  9,
    MTV_EVT_PLAYER_PAUSE_REQ                        = 1 << 10,
    MTV_EVT_PLAYER_STOP_REQ                         = 1 << 11,
    MTV_EVT_PLAYER_SEEK_REQ                         = 1 << 12,
    MTV_EVT_PLAYER_SET_RATE_REQ                     = 1 << 13,
    MTV_EVT_PLAYER_SNAPSHOT_REQ                     = 1 << 14,
    MTV_EVT_PLAYER_GET_STATUS_REQ                   = 1 << 15,
    MTV_EVT_RECORDER_START_REQ                      = 1 << 16,
    MTV_EVT_RECORDER_STOP_REQ                       = 1 << 17,
    MTV_EVT_RECORDER_GET_STATUS_REQ                 = 1 << 18,
    MTV_EVT_RECORDER_DISCARD_RECORDING_REQ          = 1 << 19,
    MTV_EVT_RECORDER_SAVE_REQ                       = 1 << 20,
    MTV_EVT_RECORDER_ABORT_SAVING_REQ               = 1 << 21,
    MTV_EVT_SET_PARAM_REQ                           = 1 << 22,
    MTV_EVT_GET_PARAM_REQ                           = 1 << 23,
    MTV_EVT_SERVICE_GET_STATUS_REQ                  = 1 << 24,
    MTV_EVT_STOP_SERVICE_REQ                        = 1 << 25,
    MTV_EVT_CLOSE_REQ                               = 1 << 26

} mtv_wait_event_enum;

/**
  * Mobile TV engine context.
  */
typedef struct
{
    kal_eventgrpid req_events;  /* event group for blocking request */
    mtv_state_t state;          /* context state */
    module_type src_mod;        /* the source module for sending indication message */

    mtv_sm_t sm;                /* service manager */

    kal_taskid control_thread;  /* the thread responsible for execution control */
    kal_taskid mtv_thread;      /* the thread responsible for MTV-specific jobs */

} mtv_context_t;

static mtv_context_t g_mtv_context;

#if defined(_MTV_USE_TDMB_TS_DEMOD)
stack_timer_struct g_mtv_transport_timer;
#endif

/* the timer to dispatch packets in time-shift mode */
extern stack_timer_struct g_mtv_timeshift_timer;
extern void sm_process_timeshift_timer(void);

/* to synchronize with transport thread */
kal_mutexid g_mtv_transport_lock;

/* forward declaration */

static void mtv_service_callback(void* context, mtv_service_context_t* sc, mtv_service_event_t event, kal_uint32 event_param);

/* private functions */

void mtv_send_outgoing_ilm(module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr)
{
    ilm_struct* ilm = NULL;
    module_type src_mod_id;

    /*
     * Since outgoing ILM may be sent by control or transport thread,
     * we need to know which thread we are running to allocate correct
     * ILM struct for use.
     */
    if (kal_get_current_thread_ID() == g_mtv_context.control_thread) {
        src_mod_id = MTV_CONTROL_MOD;
    }
    else if (kal_get_current_thread_ID() == g_mtv_context.mtv_thread) {
        src_mod_id = MTV_BACKGROUND_MOD;
    }
    else {
        src_mod_id = MTV_TRANSPORT_MOD;
    }

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = MED_SAP;

    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;

    ilm->dest_mod_id = dest_mod_id;

    msg_send_ext_queue(ilm);
}

static void mtv_send_incoming_ilm(module_type src_mod_id, module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr)
{
    ilm_struct* ilm = NULL;

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->dest_mod_id = dest_mod_id;
    ilm->sap_id = MED_SAP;

    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm);
}

static void mtv_send_search_progress_ind(module_type src_mod_id, void* context, kal_uint32 percentage)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_search_progress_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->percentage = percentage;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND, ind);
}

static void mtv_send_service_found_ind(module_type src_mod_id, void* context, media_mtv_service_info_struct* info)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_service_found_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->info = *info;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND, ind);
}

static void mtv_send_complete_recovering_ind(module_type src_mod_id, void* context, kal_uint32 error)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_complete_recovering_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->error = error;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_COMPLETE_RECOVERING_IND, ind);
}

static void mtv_send_service_event_ind(module_type src_mod_id, void* context, kal_uint32 service_id, kal_uint32 event, kal_uint32 parameter)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_service_event_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->service_id = service_id;
    ind->event = event;
    ind->parameter = parameter;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_SERVICE_EVENT_IND, ind);
}

static void mtv_send_player_event_ind(module_type src_mod_id, void* context, kal_uint32 service_id, kal_uint32 event, kal_uint32 parameter)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_player_event_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->service_id = service_id;
    ind->event = event;
    ind->parameter = parameter;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_PLAYER_EVENT_IND, ind);
}

static void mtv_send_recorder_event_ind(module_type src_mod_id, void* context, kal_uint32 service_id, kal_uint32 event, kal_uint32 parameter)
{
    CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_event_ind_struct, ind);

    ind->context = (kal_uint32) context;
    ind->service_id = service_id;
    ind->event = event;
    ind->parameter = parameter;

    mtv_send_outgoing_ilm(src_mod_id, MSG_ID_MEDIA_MTV_RECORDER_EVENT_IND, ind);
}

static kal_int32 mtv_error_to_med_error(kal_int32 mtv_error)
{
    if (mtv_error >= 0) {
        return MED_RES_OK;
    }

    switch (mtv_error)
    {
    case MTV_IO_E_DISK_FULL:
        return MED_RES_DISC_FULL;
    case MTV_DEC_E_VIDEO:
        return MED_RES_VIDEO_ERROR;
    case MTV_DEC_E_AUDIO:
        return MED_RES_AUDIO_ERROR;
    case MTV_E_BUSY:
        return MED_RES_BUSY;
    }

    return MED_RES_FAIL;
}

/* public API */

#define MTV_WAIT_EVENT(evt) \
    do { \
        kal_uint32 retrieved_events; \
        kal_retrieve_eg_events(ctx->req_events, (evt), \
            KAL_OR_CONSUME, &retrieved_events, (kal_uint32) KAL_SUSPEND); \
    } while (0)

#define REQ_CONSTRUCT_LOCAL_PARAM(st, name) \
    kal_uint32 req_result; \
    CONSTRUCT_LOCAL_PARAM(st, name); \
    name->result = &req_result;

kal_int32 media_mtv_open(module_type src_mod_id, kal_uint32* context)
{
	mtv_context_t* ctx = &g_mtv_context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_open_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_OPEN_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_OPEN_REQ);

    return req_result;
}

kal_int32 media_mtv_config(module_type src_mod_id, kal_uint32 context, media_config_video_struct* video, media_config_audio_struct* audio, media_mtv_config_record_struct* record)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_config_req_struct, req);

    req->context = context;
    req->video = *video;
    req->audio = *audio;
    req->record = *record;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_CONFIG_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_CONFIG_REQ);

    return req_result;
}

kal_int32 media_mtv_find_unsaved_recording(module_type src_mod_id, kal_uint32 context, kal_bool* found)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_find_unsaved_recording_req_struct, req);

    req->context = context;
    req->found = found;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_FIND_UNSAVED_RECORDING_REQ);

    return req_result;
}

kal_int32 media_mtv_recover_recording(module_type src_mod_id, kal_uint32 context)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recover_recording_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_BACKGROUND_MOD, MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECOVER_RECORDING_REQ);

    return req_result;
}

kal_int32 media_mtv_abort_recovering(module_type src_mod_id, kal_uint32 context)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_abort_recovering_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ABORT_RECOVERING_REQ);

    return req_result;
}

kal_int32 media_mtv_discard_unsaved_recording(module_type src_mod_id, kal_uint32 context)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_discard_unsaved_recording_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_DISCARD_UNSAVED_RECORDING_REQ);

    return req_result;
}

kal_int32 media_mtv_search_services(module_type src_mod_id, kal_uint32 context, kal_uint32 source, kal_uint32 band)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_search_services_req_struct, req);

    req->context = context;
    req->source = source;
    req->band = band;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SEARCH_SERVICES_REQ);

    return req_result;
}

kal_int32 media_mtv_abort_searching(module_type src_mod_id, kal_uint32 context)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_search_services_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_ABORT_SEARCHING_REQ);

    return req_result;
}

kal_int32 media_mtv_start_service(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 activities)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_start_service_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->activities = activities;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_START_SERVICE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_START_SERVICE_REQ);

    return req_result;
}

kal_int32 media_mtv_player_play(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_play_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_PLAY_REQ);

    return req_result;
}

kal_int32 media_mtv_player_pause(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_pause_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_PAUSE_REQ);

    return req_result;
}

kal_int32 media_mtv_player_stop(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_stop_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_STOP_REQ);

    return req_result;
}

kal_int32 media_mtv_player_seek(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 delay_in_seconds)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_seek_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->delay_in_seconds = delay_in_seconds;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_SEEK_REQ);

    return req_result;
}

kal_int32 media_mtv_player_set_rate(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_int32 rate)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_set_rate_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->rate = rate;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_SET_RATE_REQ);

    return req_result;
}

kal_int32 media_mtv_player_snapshot(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_snapshot_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_SNAPSHOT_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_SNAPSHOT_REQ);

    return req_result;
}

kal_int32 media_mtv_player_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_player_status_struct* status)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_player_get_status_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->status = status;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_PLAYER_GET_STATUS_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_start(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_start_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_START_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_START_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_stop(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_stop_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_STOP_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_save(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_save_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_BACKGROUND_MOD, MSG_ID_MEDIA_MTV_RECORDER_SAVE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_SAVE_REQ);

    return MED_RES_OK;
}

kal_int32 media_mtv_recorder_abort_saving(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_abort_saving_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_ABORT_SAVING_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_discard_recording(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_discard_recording_req_struct, req);

    req->context = context;
    req->service_id = service_id;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_DISCARD_RECORDING_REQ);

    return req_result;
}

kal_int32 media_mtv_recorder_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_recorder_status_struct* status)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_recorder_get_status_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->status = status;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_RECORDER_GET_STATUS_REQ);

    return req_result;
}

kal_int32 media_mtv_service_get_status(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, media_mtv_service_status_struct* status)
{
    mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_service_get_status_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->status = status;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SERVICE_GET_STATUS_REQ);

    return req_result;
}

kal_int32 media_mtv_stop_service(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    kal_uint32 req_result;
    kal_int32 retries;

    /*
     * Retries stopping the services when it is busy:
     *   - the tuner has not finished its tuning to specified frequency.
     *   - the aborting of recorder saving is still in progress (typically takes 4 retries)
     */
    for (retries = 0; retries < 8; retries++)
    {
        CONSTRUCT_LOCAL_PARAM(media_mtv_stop_service_req_struct, req);

        req->result = &req_result;
        req->context = context;
        req->service_id = service_id;

        mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ, req);
        MTV_WAIT_EVENT(MTV_EVT_STOP_SERVICE_REQ);
        if (req_result == MED_RES_BUSY)
        {
            kal_sleep_task(100);
            continue;
        }

        break;
    }

    return req_result;
}

kal_int32 media_mtv_set_param(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 param, kal_uint32 value)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_set_param_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->param = param;
    req->value = value;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_SET_PARAM_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_SET_PARAM_REQ);

    return req_result;
}

kal_int32 media_mtv_get_param(module_type src_mod_id, kal_uint32 context, kal_uint32 service_id, kal_uint32 param, kal_uint32* value)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_get_param_req_struct, req);

    req->context = context;
    req->service_id = service_id;
    req->param = param;
    req->value = value;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_GET_PARAM_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_GET_PARAM_REQ);

    return req_result;
}

kal_int32 media_mtv_close(module_type src_mod_id, kal_uint32 context)
{
	mtv_context_t* ctx = (mtv_context_t*) context;
    REQ_CONSTRUCT_LOCAL_PARAM(media_mtv_close_req_struct, req);

    req->context = context;

    mtv_send_incoming_ilm(src_mod_id, MTV_CONTROL_MOD, MSG_ID_MEDIA_MTV_CLOSE_REQ, req);
    MTV_WAIT_EVENT(MTV_EVT_CLOSE_REQ);

    return req_result;
}

/* message handlers */

#define MTV_SET_RESULT(ctx, req, ret, event) \
    *req->result = ret; \
    kal_set_eg_events(ctx->req_events, event, KAL_OR);

static void mtv_open_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_open_req_struct, req, ilm);
    mtv_context_t* ctx = &g_mtv_context;    /* currently use the global context */
    kal_int32 ret;

    *(req->context) = (kal_uint32) NULL;

    if (ctx->state == MTV_STATE_CLOSED)
    {
        ret = ctx->sm.open(&ctx->sm, mtv_service_callback, ctx);
        if (ret >= 0)
        {
            *(req->context) = (kal_uint32) ctx;

            ctx->state = MTV_STATE_OPENED;
            ctx->src_mod = ilm->src_mod_id;
            ctx->control_thread = kal_get_current_thread_ID();
        }
    }
    else if (ctx->state == MTV_STATE_OPENED)
    {
        ret = MTV_E_WRONG_STATE;
    }
    else
    {
        ret = MTV_E_FAIL;
        NOT_REACHED("Invalid context state!");
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_OPEN_REQ);
}

static void mtv_config_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_config_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.config(&ctx->sm, &req->audio, &req->video, &req->record);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_CONFIG_REQ);
}

static void mtv_find_unsaved_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_find_unsaved_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.find_unsaved_recording(&ctx->sm, req->found);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_FIND_UNSAVED_RECORDING_REQ);
}

static void mtv_recover_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recover_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    /* let the requesting task continue to run */
    MTV_SET_RESULT(ctx, req, MED_RES_OK, MTV_EVT_RECOVER_RECORDING_REQ);

    ret = ctx->sm.recover_recording(&ctx->sm);
}

static void mtv_abort_recovering_req_hdlr(ilm_struct *ilm)
{
    media_mtv_abort_recovering_req_struct* req = (media_mtv_abort_recovering_req_struct*) ilm->local_para_ptr;
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.abort_recovering(&ctx->sm);
    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ABORT_RECOVERING_REQ);
}

static void mtv_discard_unsaved_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_discard_unsaved_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.discard_unsaved_recording(&ctx->sm);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_DISCARD_UNSAVED_RECORDING_REQ);
}

static void mtv_search_services_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_search_services_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;
    mtv_freq_band_t band;

    switch (req->band)
    {
    case MEDIA_MTV_INVALID_BAND:
        band = MTV_FREQ_INVALID_BAND;
        break;
    case MEDIA_MTV_TDMB_KOREA_BAND:
        band = MTV_FREQ_KOREA_BAND;
        break;
    case MEDIA_MTV_TDMB_BAND_III:
        band = MTV_FREQ_BAND_III;
        break;
    case MEDIA_MTV_TDMB_L_BAND:
        band = MTV_FREQ_L_BAND;
        break;
    case MEDIA_MTV_TDMB_CANADA_BAND:
        band = MTV_FREQ_CANADA_BAND;
        break;
    case MEDIA_MTV_TDMB_CHINESE_BAND:
        band = MTV_FREQ_CHINESE_BAND;
        break;
    case MEDIA_MTV_TDMB_BAND_II:
        band = MTV_FREQ_BAND_II;
        break;
    case MEDIA_MTV_TDMB_BAND_IF:
        band = MTV_FREQ_BAND_IF;
        break;
    default:
        NOT_REACHED("Invalid frequency band?!");
        band = MTV_FREQ_INVALID_BAND;
        break;
    }

    ret = ctx->sm.search_services(&ctx->sm, req->source, band);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SEARCH_SERVICES_REQ);
}

static void mtv_abort_searching_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_abort_searching_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.abort_searching(&ctx->sm);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_ABORT_SEARCHING_REQ);
}

static void mtv_start_service_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_start_service_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.start_service(&ctx->sm, req->service_id, req->activities);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_START_SERVICE_REQ);
}

static void mtv_player_play_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_play_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();

    ret = ctx->sm.start_player(&ctx->sm, req->service_id);

    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_PLAY_REQ);
}

static void mtv_player_pause_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_pause_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();
    {
        mtv_control_timeshift_t* control = NULL;
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
        if (control) {
            ret = control->set_pause(control, KAL_TRUE);
        }
    }
    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_PAUSE_REQ);
}

static void mtv_player_stop_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_stop_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();

    ret = ctx->sm.stop_player(&ctx->sm, req->service_id);

    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_STOP_REQ);
}

static void mtv_player_seek_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_seek_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_FAIL;

    mtv_take_transport_lock();
    {
        mtv_control_timeshift_t* control = NULL;
        ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
        if (control) {
            ret = control->set_delay(control, req->delay_in_seconds);
        }
    }
    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_SEEK_REQ);
}

static void mtv_player_set_rate_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_set_rate_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();
    {
        mtv_control_timeshift_t* control = NULL;
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
        if (control) {
            ret = control->set_rate(control, req->rate);
        }
    }
    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_SET_RATE_REQ);
}

static void mtv_player_snapshot_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_snapshot_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();
    {
        mtv_control_timeshift_t* control = NULL;
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
        if (control) {
            ret = control->take_snapshot(control);
        }
    }
    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_SNAPSHOT_REQ);
}

static void mtv_player_get_status_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_player_get_status_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();
    {
        mtv_control_timeshift_t* cts = NULL;
        ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_TIMESHIFT, (void**) &cts);
        if (cts)
        {
            kal_bool timeshift_paused = KAL_FALSE;

            ret = cts->get_delay(cts, &req->status->play_delay);
            ret = cts->get_buffer_status(cts, &req->status->max_delay, &req->status->buffer_duration);
            ret = cts->get_rate(cts, &req->status->play_rate);
            ret = cts->get_pause(cts, &timeshift_paused);
            req->status->state = timeshift_paused ? MEDIA_MTV_PLAYER_STATE_PAUSED : MEDIA_MTV_PLAYER_STATE_PLAYING;
        }
        else
        {
            req->status->state = MEDIA_MTV_PLAYER_STATE_STOPPED;
            req->status->play_delay = 0;
            req->status->max_delay = 0;
            req->status->play_rate = 1000;
        }

        ret = MTV_S_OK;
    }
    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_PLAYER_GET_STATUS_REQ);
}

static void mtv_recorder_start_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_start_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();

    ret = ctx->sm.start_recorder(&ctx->sm, req->service_id);

    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_START_REQ);
}

static void mtv_recorder_stop_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_stop_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();

    ret = ctx->sm.stop_recorder(&ctx->sm, req->service_id);

    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_STOP_REQ);
}

static void mtv_recorder_save_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_save_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    /* let the requesting task continue to run */
    MTV_SET_RESULT(ctx, req, MED_RES_OK, MTV_EVT_RECORDER_SAVE_REQ);

    ret = ctx->sm.save_recording(&ctx->sm, req->service_id);
}

static void mtv_recorder_abort_saving_req_hdlr(ilm_struct *ilm)
{
    media_mtv_recorder_abort_saving_req_struct* req = (media_mtv_recorder_abort_saving_req_struct*) ilm->local_para_ptr;

    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    ret = ctx->sm.abort_saving(&ctx->sm, req->service_id);

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_ABORT_SAVING_REQ);
}

static void mtv_recorder_discard_recording_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_discard_recording_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();

    ret = ctx->sm.recorder_discard_recording(&ctx->sm, req->service_id);
    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_DISCARD_RECORDING_REQ);

    mtv_give_transport_lock();
}

static void mtv_recorder_get_status_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_recorder_get_status_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();
    {
        mtv_recorder_state_t rec_state = MTV_RECORDER_STATE_STOPPED;

        ret = ctx->sm.get_recorder_state(&ctx->sm, req->service_id, &rec_state);
        switch (rec_state)
        {
        case MTV_RECORDER_STATE_STARTED:
            {
                mtv_control_record_t* control = NULL;
                ret = ctx->sm.get_control(&ctx->sm, req->service_id, MTV_CONTROL_RECORD, (void**) &control);
                ASSERT(control != NULL);

                req->status->state = MEDIA_MTV_RECORDER_STATE_STARTED;
                ret = control->get_recorded_duration(control, &req->status->recorded_duration);
                break;
            }

        case MTV_RECORDER_STATE_STOPPED:
            req->status->state = MEDIA_MTV_RECORDER_STATE_STOPPED;
            req->status->recorded_duration = 0;
            break;

        case MTV_RECORDER_STATE_SAVING:
            req->status->state = MEDIA_MTV_RECORDER_STATE_SAVING;
            req->status->recorded_duration = 0;
            ret = MTV_S_OK;
            break;

        default:
            NOT_REACHED("Unhandled recorder state?!");
            ret = MTV_E_FAIL;
            break;
        }
    }
    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_RECORDER_GET_STATUS_REQ);
}

static void mtv_set_param_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_set_param_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_INVALID_PARAM;

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SET_PARAM_REQ);
}

static void mtv_get_param_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_get_param_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_INVALID_PARAM;

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_GET_PARAM_REQ);
}

static void mtv_service_get_status_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_service_get_status_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_sm_t* sm = &ctx->sm;
    mtv_result_t ret = MTV_S_OK;
    mtv_service_context_t sc;

    ret = sm->get_service_context(sm, req->service_id, &sc);
    if (ret >= 0)
    {
        ret = sm->get_service_param(sm, req->service_id, MTV_SERVICE_PARAM_SIGNAL_STRENGTH, &req->status->signal_strength);
        if (ret < 0) {
            req->status->signal_strength = 0;
        }

        req->status->timeshift_available = (sc.be != NULL);

        switch (sc.state)
        {
        case MTV_SERVICE_STATE_STOPPED:
            req->status->state = MEDIA_MTV_SERVICE_STATE_STOPPED;
            break;

        case MTV_SERVICE_STATE_STARTED:
            req->status->state = MEDIA_MTV_SERVICE_STATE_STARTED;
            break;

        case MTV_SERVICE_STATE_READY:
            req->status->state = MEDIA_MTV_SERVICE_STATE_READY;
            break;

        default:
            NOT_REACHED("Unhandled service state?!");
            ret = MTV_E_FAIL;
            break;
        }
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_SERVICE_GET_STATUS_REQ);
}

static void mtv_stop_service_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_stop_service_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret;

    mtv_take_transport_lock();

    ret = ctx->sm.stop_service(&ctx->sm, req->service_id);

    mtv_give_transport_lock();

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_STOP_SERVICE_REQ);
}

static void mtv_close_req_hdlr(ilm_struct *ilm)
{
    MSG_STRUCT(media_mtv_close_req_struct, req, ilm);
    mtv_context_t* ctx = (mtv_context_t*) req->context;
    mtv_result_t ret = MTV_E_FAIL;

    /* find available service manager */
    if (ctx->state == MTV_STATE_OPENED)
    {
        ret = ctx->sm.close(&ctx->sm);
        ASSERT(ret >= 0);

        ctx->state = MTV_STATE_CLOSED;
    }
    else if (ctx->state == MTV_STATE_CLOSED)
    {
        ret = MTV_E_WRONG_STATE;
        SHOULD_NOT_HAPPEN("Try to close an unopen context!")
    }
    else
    {
        ret = MTV_E_FAIL;
        NOT_REACHED("Invalid context state!");
    }

    MTV_SET_RESULT(ctx, req, mtv_error_to_med_error(ret), MTV_EVT_CLOSE_REQ);
}

static void mtv_async_write_req_hdlr(ilm_struct *ilm)
{
    media_mtv_async_write_req_struct* req = (media_mtv_async_write_req_struct*) ilm->local_para_ptr;
    async_io_process_writing(req->io);
}

static void mtv_async_callback_req_hdlr(ilm_struct *ilm)
{
    media_mtv_async_callback_req_struct* req = (media_mtv_async_callback_req_struct*) ilm->local_para_ptr;

    /* invoke the callback directly */
    req->callback(req->param);
}

static media_mtv_service_type_enum map_to_med_mtv_service_type(mtv_spi_service_type_t st)
{
    switch (st)
    {
    case MTV_SPI_SERVICE_DIGITAL_RADIO:
        return MEDIA_MTV_SERVICE_DIGITAL_RADIO;

    case MTV_SPI_SERVICE_DIGITAL_TV:
        return MEDIA_MTV_SERVICE_DIGITAL_TV;

    case MTV_SPI_SERVICE_MOT_SLIDESHOW:
        return MEDIA_MTV_SERVICE_MOT_SLIDESHOW;

    case MTV_SPI_SERVICE_MOT_BWS:
        return MEDIA_MTV_SERVICE_BWS;

    case MTV_SPI_SERVICE_TPEG:
        return MEDIA_MTV_SERVICE_TPEG;

    case MTV_SPI_SERVICE_FILE_DOWNLOAD:
        return MEDIA_MTV_SERVICE_FILE_DOWNLOAD;

    default:
        return MEDIA_MTV_SERVICE_UNKNOWN;
    }
}

static kal_uint32 map_to_med_mtv_service_flags(kal_uint32 spi_service_flags)
{
    kal_uint32 service_flags = 0;

    if ((spi_service_flags & MTV_SPI_SERVICE_FREE) != 0)
    {
        service_flags |= MEDIA_MTV_SERVICE_FREE;
    }
    if ((spi_service_flags & MTV_SPI_SERVICE_CLEAR_TO_AIR) != 0)
    {
        service_flags |= MEDIA_MTV_SERVICE_CLEAR_TO_AIR;
    }

    return service_flags;
}

static void mtv_service_callback(
    void* context,
    mtv_service_context_t* sc,
    mtv_service_event_t event,
    kal_uint32 event_param)
{
    mtv_context_t* ctx = (mtv_context_t*) context;

    switch (event)
    {
    case MTV_SERVICE_EVENT_FOUND:
        {
			media_mtv_service_info_struct info;

            ASSERT(sc != NULL);
            info.service_id = sc->info.id;
            info.service_number = sc->info.number;

            /*
             * The service context will exist until service manager is closed or
             * channels are re-scanned. therefore, it should be okay to send string
             * pointer direcly without the overhead to copy it.
             */
            info.service_name = sc->info.name;

            info.service_flags = map_to_med_mtv_service_flags(sc->info.flags);
            info.service_type = map_to_med_mtv_service_type(sc->info.type);

            mtv_send_service_found_ind(ctx->src_mod, context, &info);
            break;
        }

    case MTV_SERVICE_EVENT_STARTED:
        {
            mtv_send_service_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_SERVICE_STARTED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_READY:
        {
            mtv_send_service_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_SERVICE_READY, (kal_int32)&sc->info);
            break;
        }

    case MTV_SERVICE_EVENT_ERROR:
        {
            mtv_send_service_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_SERVICE_ERROR, mtv_error_to_med_error(event_param));
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_STARTED:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_STARTED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_PAUSED:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_TIMESHIFT_PAUSED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_DELAYED:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_LIVE:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_TIMESHIFT_LIVE, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_ERROR:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_TIMESHIFT_ERROR, mtv_error_to_med_error(event_param));
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_BEGINNING_OF_CONTENT:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_END_OF_CONTENT:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_END_OF_CONTENT, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_ERROR:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_ERROR, mtv_error_to_med_error(event_param));
            break;
        }

    case MTV_SERVICE_EVENT_PLAYER_STOPPED:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_STOPPED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_DYNAMIC_LABEL:
        {
            mtv_send_player_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_PLAYER_DYNAMIC_LABEL, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_RECORDER_STARTED:
        {
            mtv_send_recorder_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_RECORDER_STARTED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_RECORDER_SAVING:
        {
            mtv_send_recorder_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_RECORDER_SAVING, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_RECORDER_SAVING_SUCCEEDED:
        {
            mtv_send_recorder_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_RECORDER_SAVING_SUCCEEDED, mtv_error_to_med_error(event_param));
            break;
        }

    case MTV_SERVICE_EVENT_RECORDER_SAVING_FAILED:
        {
            mtv_send_recorder_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_RECORDER_SAVING_FAILED, mtv_error_to_med_error(event_param));
            break;
        }

    case MTV_SERVICE_EVENT_RECORDER_RECOVERING_COMPLETED:
        {
            ASSERT(sc == NULL);
            mtv_send_complete_recovering_ind(ctx->src_mod, context, mtv_error_to_med_error(event_param));
            break;
        }

    case MTV_SERVICE_EVENT_RECORDER_ERROR:
        {
            mtv_send_recorder_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_RECORDER_ERROR, mtv_error_to_med_error(event_param));
            break;
        }

    case MTV_SERVICE_EVENT_RECORDER_STOPPED:
        {
            mtv_send_recorder_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_RECORDER_STOPPED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_STOPPED:
        {
            mtv_send_service_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_SERVICE_STOPPED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_ADDED:
        {
            mtv_send_service_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_SERVICE_ADDED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_REMOVED:
        {
            mtv_send_service_event_ind(ctx->src_mod, context, sc->info.id, MEDIA_MTV_SERVICE_REMOVED, event_param);
            break;
        }

    case MTV_SERVICE_EVENT_SEARCH_PROGRESS:
        {
            ASSERT(sc == NULL);
            mtv_send_search_progress_ind(ctx->src_mod, context, event_param);
            break;
        }

    default:
        NOT_REACHED("Unhandled event!");
        break;
    }
}

void mtv_process_time_out(stack_timer_struct* stack_timer_ptr)
{
#if defined(_MTV_USE_TDMB_TS_DEMOD)
    if (stack_timer_ptr == &g_mtv_transport_timer)
    {
        if (stack_is_time_out_valid(stack_timer_ptr))
        {
            tdmb_ts_send_data();
        }
        stack_process_time_out(stack_timer_ptr);
    }
#endif /* _MTV_USE_TDMB_TS_DEMOD */

    if (stack_timer_ptr == &g_mtv_timeshift_timer)
    {
        if (stack_is_time_out_valid(stack_timer_ptr))
        {
            sm_process_timeshift_timer();
        }
        stack_process_time_out(stack_timer_ptr);
    }
}

void mtv_main(ilm_struct* ilm)
{
    switch (ilm->msg_id)
    {
    case MSG_ID_MEDIA_MTV_ASYNC_WRITE:
        mtv_async_write_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_ASYNC_CALLBACK:
        mtv_async_callback_req_hdlr(ilm);
        break;

#if !defined(_MTV_USE_TDMB_TS_DEMOD)
    case MSG_ID_TDMB_DATA_INDICATION:
        {
            MSG_STRUCT(media_mtv_tdmb_data_ind_struct, ind, ilm);
            tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) ind->tdmb_demod;

		    tdmb_demod->send_tdmb_data(tdmb_demod, ind);
        }
		break;

    case MSG_ID_TDMB_TURN_ON_CONFIRM:
            {
                MSG_STRUCT(tdmb_turn_on_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			    tdmb_demod->on_turnon_confirm(tdmb_demod, confirm);
            }
		break;

    case MSG_ID_TDMB_SET_BAND_CONFIRM:
            {
                MSG_STRUCT(tdmb_set_band_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

    			tdmb_demod->on_setband_confirm(tdmb_demod, confirm);
            }
		break;

    case MSG_ID_TDMB_AUTO_SCAN_CONFIRM:
            {
                MSG_STRUCT(tdmb_auto_scan_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			    tdmb_demod->on_autoscan_confirm(tdmb_demod, confirm);
            }
			break;

    case MSG_ID_TDMB_SET_FREQUENCY_CONFIRM:
            {
                MSG_STRUCT(tdmb_set_frequency_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			    tdmb_demod->on_setfreqency_confirm(tdmb_demod, confirm);
            }
		break;

    case MSG_ID_TDMB_SELECT_SERVICE_CONFIRM:
            {
                MSG_STRUCT(tdmb_select_service_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			    tdmb_demod->on_selectservice_confirm(tdmb_demod, confirm);
            }
		break;

    case MSG_ID_TDMB_GET_SIGNAL_CONFIRM:
            {
                MSG_STRUCT(tdmb_get_signal_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			    tdmb_demod->on_getsignal_confirm(tdmb_demod, confirm);
            }
		break;

    case MSG_ID_TDMB_SET_IDLE_CONFIRM:
            {
                MSG_STRUCT(tdmb_set_idle_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			    tdmb_demod->on_setidle_confirm(tdmb_demod, confirm);
            }
		break;

    case MSG_ID_TDMB_MCI_RECONFIG_INDICATION:
            {
                MSG_STRUCT(tdmb_mci_reconfig_indication_struct, ind, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) ind->cb_para;

			    tdmb_demod->on_mci_reconfig_indication(tdmb_demod, ind);
            }
		break;

    case MSG_ID_TDMB_GET_ENSEMBLE_INFO_CONFIRM:
            {
                MSG_STRUCT(tdmb_get_ensemble_info_confirm_struct, confirm, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) confirm->cb_para;

			    tdmb_demod->on_get_ensemble_info_confirm(tdmb_demod, confirm);
            }
		break;

    case MSG_ID_TDMB_ANNOUNCEMENT_INDICATION:
            {
                MSG_STRUCT(tdmb_announcement_indication_struct, ind, ilm);
                tdmb_demod_t* tdmb_demod = (tdmb_demod_t*) ind->cb_para;

			    tdmb_demod->on_announcement_indication(tdmb_demod, ind);
            }
		break;
#endif

    case MSG_ID_MEDIA_MTV_OPEN_REQ:
        mtv_open_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_CONFIG_REQ:
        mtv_config_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ:
        mtv_find_unsaved_recording_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ:
        mtv_recover_recording_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ:
        mtv_abort_recovering_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ:
        mtv_discard_unsaved_recording_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ:
        mtv_search_services_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ:
        mtv_abort_searching_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_START_SERVICE_REQ:
        mtv_start_service_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ:
        mtv_player_play_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ:
        mtv_player_pause_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ:
        mtv_player_stop_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ:
        mtv_player_seek_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ:
        mtv_player_set_rate_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_PLAYER_SNAPSHOT_REQ:
        mtv_player_snapshot_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ:
        mtv_player_get_status_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_RECORDER_START_REQ:
        mtv_recorder_start_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ:
        mtv_recorder_stop_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_RECORDER_SAVE_REQ:
        mtv_recorder_save_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ:
        mtv_recorder_abort_saving_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ:
        mtv_recorder_discard_recording_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ:
        mtv_recorder_get_status_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_SET_PARAM_REQ:
        mtv_set_param_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_GET_PARAM_REQ:
        mtv_get_param_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ:
        mtv_service_get_status_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ:
        mtv_stop_service_req_hdlr(ilm);
        break;

    case MSG_ID_MEDIA_MTV_CLOSE_REQ:
        mtv_close_req_hdlr(ilm);
        break;

    default:
        break;
    }
}

void mtv_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;
    kal_uint32 task_index;

    g_mtv_context.mtv_thread = kal_get_current_thread_ID();

    kal_get_my_task_index(&task_index);

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(task_index, current_ilm.dest_mod_id);

        mtv_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }
}

kal_bool mtv_init(task_indx_type task_indx)
{
    UNUSED(task_indx);

    /*
     * there are some difficulties to allocate the context dynamically because
     * some resource is required to be allocated during system initialization.
     * therefore, a global context is used.
     */
    g_mtv_context.state = MTV_STATE_CLOSED;
    g_mtv_context.req_events = kal_create_event_group("mtv_events");

    /* construct the service manager in global context */
    construct_mtv_sm(&g_mtv_context.sm);

    /*
     * create a global transport lock so that we can run mobile TV in two threads, one
     * for controlling the engine and the other for transporting media data.
     */
    g_mtv_transport_lock = kal_create_mutex("mtv_transport_lock");

#if defined(_MTV_USE_TDMB_TS_DEMOD)
    /* initialize the timer for demodulator emulation */
    stack_init_timer(&g_mtv_transport_timer, "mtv_transport_timer", MTV_TRANSPORT_MOD);
#endif

    /* initialize the timer for time-shift mode */
    stack_init_timer(&g_mtv_timeshift_timer, "mtv_timeshift_timer", MTV_TRANSPORT_MOD);

    mtv_init_lock_pool();

    return KAL_TRUE;
}

kal_bool mtv_reset(task_indx_type task_indx)
{
    UNUSED(task_indx);

    return KAL_TRUE;
}

kal_bool mtv_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct mtv_handler_info =
    {
        mtv_task_main,    /* task entry function */
        mtv_init,         /* task initialization function */
        NULL,             /* task configuration function */
        mtv_reset,        /* task reset handler */
        NULL,             /* task termination handler */
    };

    *handle = (comptask_handler_struct*) &mtv_handler_info;
    return KAL_TRUE;
}

void mtv_take_transport_lock()
{
    kal_bool to_take = (
        kal_get_current_thread_ID() == g_mtv_context.control_thread ||
        kal_get_current_thread_ID() == g_mtv_context.mtv_thread);

    if (to_take)
    {
        kal_take_mutex(g_mtv_transport_lock);
    }
}

void mtv_give_transport_lock()
{
    kal_bool to_give = (
        kal_get_current_thread_ID() == g_mtv_context.control_thread ||
        kal_get_current_thread_ID() == g_mtv_context.mtv_thread);

    if (to_give)
    {
        kal_give_mutex(g_mtv_transport_lock);
    }
}

#endif /* defined(__MED_MTV_MOD__) */
