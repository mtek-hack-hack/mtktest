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
 *   mtv_sm.c
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
#include "app_ltlcom.h" /* Task message communiction */
#include "med_global.h"
#include "stack_timer.h"

#if defined(__MED_MTV_MOD__)

#include "med_struct.h"
#include "med_trc.h"
#include "med_utility.h"

#include "mtv_sm.h"

#if defined(__MTK_TARGET__)
#include "SST_sla.h"
#endif

/* allow the debugger to disable recording checkpoint at runtime */
static kal_bool g_mtv_enable_rec_checkpoint = KAL_TRUE;

/* helper function for service callback */

static void sm_callback(mtv_sm_t* sm, mtv_service_context_t* sc, mtv_service_event_t event, kal_uint32 event_param)
{
    sm->service_callback(sm->service_callback_ctx, sc, event, event_param);
}

/* service context private functions */

static mtv_recording_format_t sc_get_recording_format(mtv_service_context_t* sc)
{
    mtv_recording_format_t rf;

    switch (sc->info.type)
    {
    case MTV_SPI_SERVICE_DIGITAL_TV:
        rf = MTV_RECORDING_FORMAT_MP4;
        break;

    case MTV_SPI_SERVICE_DIGITAL_RADIO:
        rf = MTV_RECORDING_FORMAT_MP2;
        break;

    default:
        NOT_REACHED("Unsupported service type for recording!");
        rf = MTV_RECORDING_FORMAT_INVALID;
        break;
    }

	return rf;
}

static kal_bool sc_is_player_started(mtv_service_context_t* sc)
{
    return (sc->player && sc->player->get_state(sc->player) != MTV_PLAYER_STATE_STOPPED);
}

static kal_bool sc_is_recorder_started(mtv_service_context_t* sc)
{
    return (sc->recorder && sc->recorder->get_state(sc->recorder) != MTV_RECORDER_STATE_STOPPED);
}

static mtv_result_t sc_start_player(mtv_sm_t* sm, mtv_service_context_t* sc)
{
    return sc->player->start(sc->player, &sc->info, &sm->audio_config, &sm->video_config, &sc->player_client);
}

static mtv_result_t sc_stop_player(mtv_service_context_t* sc)
{
    return sc_is_player_started(sc) ? sc->player->stop(sc->player) : MTV_S_FALSE;
}

static mtv_result_t sc_restart_player(mtv_sm_t* sm, mtv_service_context_t* sc)
{
    sc_stop_player(sc);
    return sc_start_player(sm, sc);
}

static mtv_result_t sc_close_unsaved_buffer_engine(mtv_service_context_t* sc)
{
    mtv_result_t ret = MTV_S_FALSE;
    mtv_buffer_engine_t* be = sc->unsaved_be;

    sc->unsaved_be = NULL; /* detach it immediately */
    if (be)
    {
        ret = be->close(be);
        ASSERT(ret >= 0);

        be->destroy(be);
    }

    return ret;
}

static mtv_result_t sc_start_recorder(mtv_service_context_t* sc)
{
    mtv_result_t ret;

    /* discard unsaved content */
    ret = sc_close_unsaved_buffer_engine(sc);

    if (sc->be == NULL)
    {
        /* The current recording implementation depends on buffer engine. */
        return MTV_E_FAIL;
    }

    ret = sc->recorder->start(sc->recorder, sc->be, &sc->recorder_client, sc->info.name, sc_get_recording_format(sc));
    if (ret >= 0 && g_mtv_enable_rec_checkpoint)
    {
        /* save a checkpoint immediately after start the recording */
        sc->recorder->save_checkpoint(sc->recorder, sc->be->storing_dir);
    }

    return ret;
}

static mtv_result_t sc_stop_recorder(mtv_service_context_t* sc)
{
    return sc_is_recorder_started(sc) ? sc->recorder->stop(sc->recorder) : MTV_S_FALSE;
}

/* time-shift timer */

stack_timer_struct g_mtv_timeshift_timer;
static mtv_service_context_t* g_mtv_timeshift_sc;

#define MTV_TIMESHIFT_TIMER_INTERVAL (KAL_TICKS_1_SEC/2)

static void sc_start_timeshift_timer(mtv_service_context_t* sc)
{
    g_mtv_timeshift_sc = sc;
    stack_start_timer(&g_mtv_timeshift_timer, 0, MTV_TIMESHIFT_TIMER_INTERVAL);
}

static void sc_stop_timeshift_timer(mtv_service_context_t* sc)
{
    stack_stop_timer(&g_mtv_timeshift_timer);
    g_mtv_timeshift_sc = NULL;
}

/* time-shift packet dispatching */

#define MAX_NUM_DISPATCH_LOOP 16
#define MIN_NUM_DISPATCHED_PACKETS 16

/**
  * @param drain_buffer [in] dispatch packets until the buffer is drained
  */
static mtv_result_t sc_dispatch_packets(mtv_service_context_t* pthis, kal_bool drain_buffer)
{
    kal_uint32 stream_index;
    mtv_packet_t au;
    mtv_result_t ret;
    kal_int32 i;
    kal_int32 loop;
    mtv_player_t* player =pthis->player;
    kal_uint32 dispatched_packets = 0;

	if (!sc_is_player_started(pthis)) {
		return MTV_S_FALSE;
	}

    ASSERT(pthis->be);

    for (loop = 0; drain_buffer || loop < MAX_NUM_DISPATCH_LOOP; loop++)
    {
        if (!drain_buffer)
        {
            if (player->get_buffer_level(player, MTV_STREAM_AUDIO) >= MTV_PLAYER_BUFFER_LEVEL_HIGH &&
                player->get_buffer_level(player, MTV_STREAM_VIDEO) >= MTV_PLAYER_BUFFER_LEVEL_HIGH)
            {
                /* all streams have high buffer level */
                break;
            }
        }
        for (i = 0; i < MIN_NUM_DISPATCHED_PACKETS; i++)
        {
            SLA_BEGIN("BER");
            ret = pthis->be->read_packet(pthis->be, &stream_index, &au);
            SLA_END("BER");
            if (ret >= 0)
            {
                dispatched_packets++;

                if (stream_index == pthis->be_audio_stream)
                {
                    ret = player->deliver_au(player, MTV_STREAM_AUDIO, &au);
                }
                else if (stream_index == pthis->be_video_stream)
                {
                    ret = player->deliver_au(player, MTV_STREAM_VIDEO, &au);
                }
            	else
            	{
            		ret = MTV_E_FAIL;
            	}
            }
            else /* reach end of content */
            {
                mtv_sm_t* sm = (mtv_sm_t*) pthis->owner;
                mtv_control_timeshift_t* control = NULL;

                mtv_prompt_trace(MOD_MTV, "[MTV][BE] stream buffer has been drained");
                sm_callback(sm, pthis, MTV_SERVICE_EVENT_PLAYER_END_OF_CONTENT, 0);

                /* switch back to live broadcasting */
                ret = pthis->be->get_control(pthis->be, MTV_CONTROL_TIMESHIFT, (void**) &control);
                ASSERT(ret >= 0 && control);
                ret = control->set_delay(control, 0);

                goto end_of_dispatching;
            }
        }
    }

    sc_start_timeshift_timer(pthis);  /* start the timer again for next dispatching */

end_of_dispatching:

    mtv_prompt_trace(MOD_MTV, "[MTV][BE] %u packets in stream buffer are dispatched", dispatched_packets);
    return MTV_S_OK;
}

void sm_process_timeshift_timer()
{
    ASSERT(g_mtv_timeshift_sc != NULL);
    sc_dispatch_packets(g_mtv_timeshift_sc, KAL_FALSE);
}

static void sc_be_on_read_state_change(
    mtv_buffer_engine_client_t* client,
    mtv_buffer_engine_read_state_t old_state,
    mtv_buffer_engine_read_state_t new_state)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, be_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    ASSERT(old_state != new_state);

    switch (old_state)
    {
    case MTV_BE_READ_DELAYED:

        sc_stop_timeshift_timer(sc);
        break;

    case MTV_BE_READ_PAUSED:

        if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != 0) {
            sc_start_player(sm, sc);
        }
        break;
    }

    switch (new_state)
    {
    case MTV_BE_READ_PREBUFFERING:

        /* Drain stream buffer to enter LIVE mode */
        sc_dispatch_packets(sc, KAL_TRUE);
        break;

    case MTV_BE_READ_LIVE:

        sm_callback(sm, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_LIVE, 0);
        break;

    case MTV_BE_READ_PAUSED:

        /*
         * TODO: back off read position when pause; otherwise, buffered content will be
         * flushed when resuming playback.
         */

        /* we have to stop the player to release decoder resource */
        sc_stop_player(sc);

        sm_callback(sm, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_PAUSED, 0);
        break;

    case MTV_BE_READ_DELAYED:

        /* start a timer to dispatch packets in time-shift buffer */
        sc_dispatch_packets(sc, KAL_FALSE);

        sm_callback(sm, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_DELAYED, 0);
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }
}

static void sc_be_on_read_seek(mtv_buffer_engine_client_t* client, kal_uint32 target_time)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, be_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    UNUSED(target_time);

    /* to flush the buffer when seeking */
    sc_restart_player(sm, sc);
}

static void sc_player_on_audio_error(mtv_player_client_t* client, kal_int32 error)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, player_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ERROR, error);

    sm_callback(sm, sc, MTV_SERVICE_EVENT_PLAYER_ERROR, MTV_DEC_E_AUDIO);
}

static void sc_player_on_video_error(mtv_player_client_t* client, kal_int32 error)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, player_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, error);

    sm_callback(sm, sc, MTV_SERVICE_EVENT_PLAYER_ERROR, MTV_DEC_E_VIDEO);
}

static void sc_player_on_state_change(mtv_player_client_t* client, mtv_player_state_t state)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, player_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    switch (state)
    {
    case MTV_PLAYER_STATE_STOPPED:
        sm_callback(sm, sc, MTV_SERVICE_EVENT_PLAYER_STARTED, 0);
        break;

    case MTV_PLAYER_STATE_STARTED:
        sm_callback(sm, sc, MTV_SERVICE_EVENT_PLAYER_STOPPED, 0);
        break;

    default:
        NOT_REACHED("Unhandled player state?!");
        break;
    }
}

static void sc_recorder_on_state_change(mtv_recorder_client_t* client, mtv_recorder_state_t state)
{
    mtv_service_context_t* sc = PTHIS(client, mtv_service_context_t, recorder_client);
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;

    switch (state)
    {
    case MTV_RECORDER_STATE_STOPPED:
        sm_callback(sm, sc, MTV_SERVICE_EVENT_RECORDER_STOPPED, 0);
        break;

    case MTV_RECORDER_STATE_STARTED:
        sm_callback(sm, sc, MTV_SERVICE_EVENT_RECORDER_STARTED, 0);
        break;

    case MTV_RECORDER_STATE_SAVING:
        sm_callback(sm, sc, MTV_SERVICE_EVENT_RECORDER_SAVING, 0);
        break;

    default:
        NOT_REACHED("Unhandled recorder state?!");
        break;
    }
}

/* service manager private functions */

static kal_bool sm_is_service_started(mtv_service_context_t* sc)
{
	return (sc->state > MTV_SERVICE_STATE_STOPPED);
}

static mtv_service_context_t* sm_find_service_by_id(mtv_sm_t* pthis, kal_uint32 service_id)
{
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (sc->info.id == service_id) {
                return sc;
            }
            sc = sc->next;
        } while (sc != head);
    }

    return NULL;
}

static mtv_service_context_t* sm_find_service_by_activities(mtv_sm_t* pthis, kal_uint32 activities)
{
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if ((activities & sc->activities) != 0) {
                return sc;
            }
            sc = sc->next;
        } while (sc != head);
    }

    return NULL;
}

static kal_bool sm_is_any_service_started(mtv_sm_t* pthis)
{
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (sm_is_service_started(sc)) {
                return KAL_TRUE;
            }
            sc = sc->next;
        } while (sc != head);
    }

    return KAL_FALSE;
}

static mtv_service_context_t* sm_alloc_service_context(mtv_sm_t* pthis)
{
    mtv_service_context_t* sc = med_alloc_ext_mem(sizeof(mtv_service_context_t));
    ASSERT(sc != NULL);
    kal_mem_set(sc, 0, sizeof(*sc));

    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        pthis->sc_tail->next = sc;
        sc->next = head;
    }
    else {
        sc->next = sc;
    }
    pthis->sc_tail = sc;

    return sc;
}

static mtv_service_context_t* sm_set_service_started(mtv_sm_t* pthis, mtv_service_context_t* started_service_context, kal_uint32 activities)
{
    mtv_service_context_t* tail = pthis->sc_tail;
    if (tail != NULL)
    {
        mtv_service_context_t* head = tail->next;
        mtv_service_context_t* sc = head;

        do
        {
            if (sc->next == started_service_context)
            {
                /* adjust tail pointer so that new started service can be found quickly */
                pthis->sc_tail = sc;
                break;
            }
            sc = sc->next;
        } while (sc != head);
    }

    started_service_context->state = MTV_SERVICE_STATE_STARTED;
    started_service_context->activities = activities;
	started_service_context->owner = (kal_uint32) pthis;

    return started_service_context;
}

static mtv_service_context_t* sm_set_service_stopped(mtv_service_context_t* sc)
{
    sc->state = MTV_SERVICE_STATE_STOPPED;
    sc->owner = 0;
    sc->activities = 0;

    return sc;
}

/* mtv_sm_t public interface */

static mtv_result_t sm_open(mtv_sm_t* sm, mtv_service_callback_t cb, void* context)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_OPEN);

    pthis->sc_tail = NULL;

    kal_mem_set(&pthis->audio_config, 0, sizeof(pthis->audio_config));
    kal_mem_set(&pthis->video_config, 0, sizeof(pthis->video_config));
    kal_mem_set(&pthis->record_config, 0, sizeof(pthis->record_config));

#if defined(__TDMB_SUPPORT__)
  	pthis->spi = construct_tdmb_sp();
#else
    return MTV_E_FAIL;
#endif

    /* open the service provider */
    ret = pthis->spi->open(pthis->spi, &pthis->spi_client);
    if (ret >= 0)
    {
        pthis->service_callback = cb;
        pthis->service_callback_ctx = context;
    }

    return ret;
}

static mtv_result_t sm_config(mtv_sm_t* sm, media_config_audio_struct* audio, media_config_video_struct* video, media_mtv_config_record_struct* record)
{
    mtv_sm_t* pthis = sm;

    MTV_TRACE(TRACE_INFO, MTV_TRC_CONFIG);

    if (!audio || !video)
    {
        NOT_REACHED("These parameters cannot be NULL!");
        return MTV_E_INVALID_PARAM;
    }

    /* TODO: check validility of specified configurations */

    kal_mem_cpy(&pthis->audio_config, audio, sizeof(pthis->audio_config));
    kal_mem_cpy(&pthis->video_config, video, sizeof(pthis->video_config));
    kal_mem_cpy(&pthis->record_config, record, sizeof(pthis->record_config));

    ASSERT(pthis->record_config.record_dir != NULL);

    return MTV_S_OK;
}

static mtv_result_t sm_find_unsaved_recording(mtv_sm_t* sm, kal_bool* found)
{
    mtv_sm_t* pthis = sm;

    ASSERT(pthis->record_config.record_dir != NULL);
    *found = mtv_recorder_find_checkpoints(pthis->record_config.record_dir);

    return MTV_S_OK;
}

static mtv_result_t sm_recover_recording(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;

    ASSERT(pthis->record_config.record_dir != NULL);
    pthis->recovering_aborted = KAL_FALSE;
    ret = mtv_recorder_recover_recording(pthis->record_config.record_dir, &pthis->recovering_aborted);

    sm_callback(pthis, NULL, MTV_SERVICE_EVENT_RECORDER_RECOVERING_COMPLETED, ret);

    return ret;
}

static mtv_result_t sm_abort_recovering(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;

    pthis->recovering_aborted = KAL_TRUE;
    return MTV_S_OK;
}

static mtv_result_t sm_discard_unsaved_recording(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;

    ASSERT(pthis->record_config.record_dir != NULL);
    mtv_recorder_discard_unsaved_recording(pthis->record_config.record_dir);

    return MTV_S_OK;
}

static mtv_result_t sm_abort_searching(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;

    MTV_TRACE(TRACE_INFO, MTV_TRC_ABORT_SEARCHING);

    return pthis->spi->abort_searching(pthis->spi);
}

static mtv_result_t sm_check_service_activities(mtv_sm_t* sm, mtv_service_context_t* sc, kal_uint32 activities)
{
    mtv_sm_t* pthis = sm;

    if ((activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != 0 &&      /* to turn it ON */
        (sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) == 0)    /* it is not ON yet */
    {
        if (sm_find_service_by_activities(pthis, activities) != NULL)
        {
            return MTV_E_RESOURCE_CONFLICT;
        }
        else
        {
            if (sc->info.type != MTV_SPI_SERVICE_DIGITAL_RADIO &&
                sc->info.type != MTV_SPI_SERVICE_DIGITAL_TV)
            {
                return MTV_E_INVALID_PARAM;
            }
        }
    }
    else if ((activities & MEDIA_MTV_SERVICE_ACTIVITY_RECORD) != 0 &&
             (sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_RECORD) == 0)
    {
        if (sm_find_service_by_activities(pthis, activities) != NULL)
        {
            return MTV_E_RESOURCE_CONFLICT;
        }
        else
        {
            if (sc->info.type != MTV_SPI_SERVICE_DIGITAL_RADIO &&
                sc->info.type != MTV_SPI_SERVICE_DIGITAL_TV)
            {
                return MTV_E_INVALID_PARAM;
            }
        }
    }

    return MTV_S_OK;
}

static mtv_result_t sc_close_buffer_engine(mtv_service_context_t* sc)
{
    mtv_result_t ret = MTV_S_FALSE;

    if (sc->be)
    {
        ret = sc->be->close(sc->be);
        ASSERT(ret >= 0);

        sc->be->destroy(sc->be);
        sc->be = NULL;
    }

    return ret;
}

static kal_uint32 sm_get_max_stream_buffer_kb(mtv_sm_t* pthis, kal_wchar* storing_dir)
{
    FS_DiskInfo di;
    kal_uint32 free_kb;
    kal_int32 fs_error;

    /* get disk free space */
    fs_error = FS_GetDiskInfo(storing_dir, &di, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
    if (fs_error < 0) {
        return 0;
    }

	free_kb = di.FreeClusters * di.SectorsPerCluster * di.BytesPerSector / 1024;

    /*
     * We cannot allow the max buffer size to go beyond 7/16 of free disk space because
     * we want to reserve some space for the user to record for a while. Otherwise,
     * the recording will stop immediately after the user start recording because of
     * running out of disk space.
     */
    return MIN(pthis->record_config.max_timeshift_buffer_kb, free_kb * 7 / 16);
}

static mtv_result_t sm_setup_buffer_engine(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_spi_service_info_t* info)
{
	mtv_result_t ret;
	kal_uint32 i;
    kal_uint32 be_streams;
    mtv_stream_info_t st;
    mtv_buffer_engine_config_t config;

    switch (info->type)
    {
    case MTV_SPI_SERVICE_DIGITAL_RADIO:
        config.estimated_bitrate = 128;
        break;

    case MTV_SPI_SERVICE_DIGITAL_TV:
        config.estimated_bitrate = 512;
        break;

    default:
        /* does not support recording */
        return MTV_E_INVALID_PARAM;
    }

    ASSERT(pthis->record_config.record_dir != NULL);
    config.storing_dir = pthis->record_config.record_dir;
    config.max_buffer_kb = sm_get_max_stream_buffer_kb(pthis, pthis->record_config.record_dir);
    config.flags = MTV_BE_BUFFER_WRAPAROUND;

    ASSERT(sc->be == NULL);
    sc->be = construct_mtv_buffer_engine();

    sc->be_client.on_read_state_change = sc_be_on_read_state_change;
    sc->be_client.on_read_seek = sc_be_on_read_seek;

    ret = sc->be->open(sc->be, &sc->be_client, &config);
    if (ret < 0)
    {
        sc->be->destroy(sc->be);
        sc->be = NULL;
        return ret;
    }

    for (i = 0, be_streams = 0; i < info->num_components; i++)
    {
        st.dec_config = info->components[i].dec_config;

        if (info->components[i].type == MTV_SPI_COMPONENT_AUDIO)
        {
            st.type = MTV_STREAM_AUDIO;

            if (st.dec_config.codec == MTV_CODEC_BSAC ||
				st.dec_config.codec == MTV_CODEC_AAC)
            {
                mtv_m4a_dec_config_t* m4a_dec_config = &info->components[i].dec_config.u.m4a;

                st.format.audio.bits_per_sample = 16;
                ASSERT(m4a_dec_config->channel_configuration <= 6);
                st.format.audio.channels = m4a_dec_config->channel_configuration;
                st.format.audio.sample_rate = mp4a_get_sample_rate_from_index(m4a_dec_config->sampling_frequency_index);
                ret = sc->be->add_stream(sc->be, &st);
            }
            else if (st.dec_config.codec == MTV_CODEC_MUSICAM)
            {
                mtv_musicam_dec_config_t* musicam_dec_config = &info->components[i].dec_config.u.musicam;

                st.format.audio.bits_per_sample = musicam_dec_config->bits_per_sample;
                st.format.audio.channels = musicam_dec_config->channels;
                st.format.audio.sample_rate = musicam_dec_config->sample_rate;
                ret = sc->be->add_stream(sc->be, &st);
            }
            else
            {
                NOT_REACHED("Unhandled audio codec!");
                return MTV_E_FAIL;
            }

            if (ret < 0)
            {
                sc_close_buffer_engine(sc);
                return ret;
            }

            sc->be_audio_stream = be_streams++;
        }
        else if (info->components[i].type == MTV_SPI_COMPONENT_VIDEO)
        {
            st.type = MTV_STREAM_VIDEO;

            if (st.dec_config.codec == MTV_CODEC_H264)
            {
                /* TODO: parse SPS to get these info. need support from codec team. */
                st.format.video.width = 320;
                st.format.video.height = 240;
                st.format.video.time_scale = st.dec_config.timestamp_resolution;
                st.format.video.frame_duration = st.dec_config.timestamp_resolution / 25;

                ret = sc->be->add_stream(sc->be, &st);
                if (ret < 0)
                {
                    sc_close_buffer_engine(sc);
                    return ret;
                }
            }
            else
            {
                NOT_REACHED("Unhandled video codec!");
                return MTV_E_FAIL;
            }

            sc->be_video_stream = be_streams++;
        }
        else
        {
            /* ignore other kinds of components */
        }
    }

	return ret;
}

static mtv_result_t sm_start_buffer_engine(mtv_sm_t* sm, mtv_service_context_t* sc)
{
    mtv_sm_t* pthis = sm;
	mtv_result_t ret = MTV_S_FALSE;

    if (pthis->record_config.enable_timeshift && sc->be == NULL)
    {
		ret = sm_setup_buffer_engine(pthis, sc, &sc->info);
    }

    return ret;
}

static mtv_result_t sm_start_player(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;
    mtv_service_context_t* sc;
    mtv_control_timeshift_t* control = NULL;

    MTV_TRACE(TRACE_INFO, MTV_TRC_START_PLAYER, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_E_FAIL;
    }

    ret = sm_check_service_activities(pthis, sc, MEDIA_MTV_SERVICE_ACTIVITY_PLAY);
    if (ret < 0) {
        return ret;
    }

    pthis->get_control(pthis, service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
    if (control)
    {
        /* unpause will trigger the action to start player */
        ret = control->set_pause(control, KAL_FALSE);
    }

    if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) == 0)
    {
        /* no time-shift is available, start a player alone */
        ret = sc_start_player(pthis, sc);
        if (ret >= 0)
        {
            /* The client has requested to start playing explicitly. */
            sc->activities |= MEDIA_MTV_SERVICE_ACTIVITY_PLAY;
        }
    }

    return ret;
}

static mtv_result_t sm_stop_player(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;
    mtv_service_context_t* sc;

    MTV_TRACE(TRACE_INFO, MTV_TRC_STOP_PLAYER, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_S_FALSE;
    }

    ret = sc_stop_player(sc);
    if (ret >= 0)
    {
        /* The client has requested to stop playing explicitly. */
        sc->activities &= ~MEDIA_MTV_SERVICE_ACTIVITY_PLAY;
    }

	return ret;
}

static mtv_result_t sm_start_recorder(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_START_RECORDER, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_E_FAIL;
    }

    ret = sm_check_service_activities(pthis, sc, MEDIA_MTV_SERVICE_ACTIVITY_RECORD);
    if (ret < 0) {
        return ret;
    }

    return sc_start_recorder(sc);
}

static mtv_result_t sm_get_recorder_state(mtv_sm_t* sm, kal_uint32 service_id, mtv_recorder_state_t* state)
{
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(sm, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    *state = sc->recorder->get_state(sc->recorder);
    return MTV_S_OK;
}

/*
 * This method is assumed to be called by another task for background file saving.
 */
static mtv_result_t sm_stop_recorder(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
	mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_STOP_RECORDER, service_id);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_S_FALSE;
    }

    ret = sc_stop_recorder(sc);
    if (ret == MTV_S_OK)
    {
        /* detach current BE for file saving */
        sc->unsaved_be = sc->be;
        sc->be = NULL;

        /* create a new BE for player */
        ret = sm_start_buffer_engine(pthis, sc);
        if (ret >= 0)
        {
            /* switch back to live broadcasting */
            mtv_control_timeshift_t* control = NULL;
            ret = pthis->get_control(pthis, service_id, MTV_CONTROL_TIMESHIFT, (void**) &control);
            ASSERT(ret >= 0 && control);
            ret = control->set_delay(control, 0);
        }
    }

	return ret;
}

/**
  * Theoretically sc_close_unsaved_buffer_engine may happen at the same
  * time as sc_save_recording. However, it should be very hard to happen with
  * current MMI implementation.
  */
static mtv_result_t sc_save_recording(mtv_service_context_t* sc)
{
    mtv_result_t ret = MTV_S_FALSE;
    mtv_sm_t* sm = (mtv_sm_t*) sc->owner;
    mtv_buffer_engine_t* be = sc->unsaved_be;

    sc->unsaved_be = NULL; /* detach it immediately */
    if (be)
    {
        sc->saving_aborted = KAL_FALSE;
        ret = sc->recorder->save(sc->recorder, &sc->saving_aborted);
        if (ret >= 0)
        {
            be->destroy(be);
            sm_callback(sm, sc, MTV_SERVICE_EVENT_RECORDER_SAVING_SUCCEEDED, ret);
        }
        else
        {
            ASSERT(sc->unsaved_be == NULL);
            sc->unsaved_be = be;
            sm_callback(sm, sc, MTV_SERVICE_EVENT_RECORDER_SAVING_FAILED, ret);
        }

        return ret;
    }

    return ret;
}

static mtv_result_t sm_save_recording(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_E_INVALID_PARAM;
    }

    return sc_save_recording(sc);
}

static mtv_result_t sm_abort_saving(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }

    sc->saving_aborted = KAL_TRUE;
    return MTV_S_OK;
}

static mtv_result_t sm_recorder_discard_recording(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc) {
        return MTV_E_INVALID_PARAM;
    }
    else if (sc->state != MTV_SERVICE_STATE_READY) {
        return MTV_S_FALSE;
    }

    return sc_close_unsaved_buffer_engine(sc);
}

static mtv_result_t sm_start_service(mtv_sm_t* sm, kal_uint32 service_id, kal_uint32 activities)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_START_SERVICE, service_id, activities);

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state != MTV_SERVICE_STATE_STOPPED) {
        return MTV_E_FAIL;
    }

    ret = sm_check_service_activities(pthis, sc, activities);
    if (ret < 0) {
        return ret;
    }

    ret = pthis->spi->start_service(pthis->spi, service_id);
    if (ret < 0) {
        return ret;
    }

    /* construct the player */
#ifdef WIN32
    sc->player = construct_cyberlink_player();
#else
    sc->player = construct_mtv_streaming_player();
#endif
    sc->player_client.on_audio_error = sc_player_on_audio_error;
    sc->player_client.on_video_error = sc_player_on_video_error;
    sc->player_client.on_state_change = sc_player_on_state_change;

    /* construct the recorder */
    ASSERT(sc->recorder == NULL);
    sc->recorder = construct_mtv_recorder();

    sc->recorder_client.on_state_change = sc_recorder_on_state_change;

    sc = sm_set_service_started(pthis, sc, activities);
    sm_callback(pthis, sc, MTV_SERVICE_EVENT_STARTED, 0);

    return MTV_S_OK;
}

static mtv_result_t sm_get_control(mtv_sm_t* sm, kal_uint32 service_id, mtv_control_t control_id, void** control)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;
    mtv_result_t ret;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state == MTV_SERVICE_STATE_STOPPED) {
        return MTV_E_FAIL;
    }

    switch (control_id)
    {
    case MTV_CONTROL_RECORD:
        return sc_is_recorder_started(sc) ? sc->recorder->get_control(sc->recorder, control_id, control) : MTV_E_FAIL;

    case MTV_CONTROL_TIMESHIFT:
        return sc->be ? sc->be->get_control(sc->be, control_id, control) : MTV_E_FAIL;

    case MTV_CONTROL_VIDEO:
    case MTV_CONTROL_VOLUME:
        return sc_is_player_started(sc) ? sc->player->get_control(sc->player, control_id, control) : MTV_E_FAIL;

    default:
        return MTV_E_FAIL;
    }

    return ret;
}

static mtv_result_t sm_get_service_param(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_param_t param, kal_uint32* value)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc;

    sc = sm_find_service_by_id(pthis, service_id);
    if (!sc || sc->state == MTV_SERVICE_STATE_STOPPED) {
        return MTV_E_FAIL;
    }

    switch (param)
    {
    case MTV_SERVICE_PARAM_SIGNAL_STRENGTH:
        {
            mtv_spi_status_t spi_status;
            pthis->spi->get_status(pthis->spi, &spi_status);
            *value = spi_status.signal_strength;
        }
        break;

    default:
        return MTV_E_INVALID_PARAM;
    }

    return MTV_S_OK;
}

static mtv_result_t sm_get_service_context(mtv_sm_t* sm, kal_uint32 service_id, mtv_service_context_t* sc)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* service_context = sm_find_service_by_id(pthis, service_id);

    if (service_context)
    {
        *sc = *service_context;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t sm_stop_service_context(mtv_sm_t* pthis, mtv_service_context_t* sc)
{
    mtv_result_t ret;

    ASSERT(sc && sc->state != MTV_SERVICE_STATE_STOPPED);

    ret = sc_stop_recorder(sc);
    if (ret < 0)
    {
        /* stopping a recorder may fail if saving recording is in progress */
        return MTV_E_BUSY;
    }

    if (sc->recorder)
    {
        sc->recorder->destroy(sc->recorder);
        sc->recorder = NULL;
    }

    ret = sc_stop_player(sc);
    ASSERT(ret >= 0);
    if (sc->player)
    {
        sc->player->destroy(sc->player);
        sc->player = NULL;
    }

    ret = sc_close_buffer_engine(sc);
    ASSERT(ret >= 0);
    ret = sc_close_unsaved_buffer_engine(sc);
    ASSERT(ret >= 0);

    sc = sm_set_service_stopped(sc);
    sm_callback(pthis, sc, MTV_SERVICE_EVENT_STOPPED, 0);

    return ret;

}

static mtv_result_t sm_stop_service(mtv_sm_t* sm, mtv_service_context_t* sc)
{
	mtv_sm_t* pthis = sm;
	mtv_result_t ret;

    if (!sc || sc->state == MTV_SERVICE_STATE_STOPPED) {
        return MTV_E_FAIL;
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_STOP_SERVICE, sc->info.id);

    ret = pthis->spi->stop_service(pthis->spi, sc->info.id);
    if (ret < 0) { /* a service cannot be stopped in some state */
        return ret;
    }

    ret = sm_stop_service_context(pthis, sc);
    return ret;
}

static mtv_result_t sm_stop_service_by_id(mtv_sm_t* sm, kal_uint32 service_id)
{
    mtv_sm_t* pthis = sm;
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    return sc ? sm_stop_service(pthis, sc) : MTV_E_INVALID_PARAM;
}

static mtv_result_t sm_free_service_context_list(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;

    /* abort all running services and free their context */
    if (pthis->sc_tail != NULL)
    {
        mtv_service_context_t* head = pthis->sc_tail->next;
        mtv_service_context_t* sc = head;
        mtv_service_context_t* next;

        do
        {
            if (sm_is_service_started(sc)) {
                ret = sm_stop_service(pthis, sc);
            }
            next = sc->next;
            med_free_ext_mem((void**)&sc);
            sc = next;
        } while (sc != head);

        pthis->sc_tail = NULL;

        return MTV_S_OK;
    }

    return MTV_S_FALSE;
}

static mtv_result_t sm_search_services(mtv_sm_t* sm, media_mtv_service_source_enum source, mtv_freq_band_t band)
{
    mtv_sm_t* pthis = sm;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_SEARCH_SERVICES, source);

    if (source == MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL)
    {
        if (sm_is_any_service_started(pthis))
        {
            /* servic searching is mutually exclusive with service receiving. */
            ret = MTV_E_RESOURCE_CONFLICT;
        }
        else
        {
            sm_free_service_context_list(pthis);

            /* search service from service provider */
            ret = pthis->spi->search_services(pthis->spi, band);
        }
    }
    else if (source == MEDIA_MTV_SERVICES_FROM_LOCAL_DATABASE)
    {
        /* TODO: load from service database */
        ret = MTV_E_FAIL;
    }
    else
    {
        NOT_REACHED("Invalid service source is specified!");
        ret = MTV_E_FAIL;
    }

    return ret;
}

static mtv_result_t sm_close(mtv_sm_t* sm)
{
    mtv_sm_t* pthis = sm;
	mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_CLOSE);

    sm_free_service_context_list(pthis);

    /* close service provider */
    if (pthis->spi)
    {
    	ret = pthis->spi->close(pthis->spi);
	    ASSERT(ret >= 0);

        pthis->spi->destroy(pthis->spi);
        pthis->spi = NULL;
    }

    return MTV_S_OK;
}

/* mtv_spi_client_t interface implementation */

static void sm_on_service(mtv_spi_client_t* client, mtv_spi_service_info_t* info)
{
	mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc;

    ASSERT(info != NULL);
    ASSERT(sm_find_service_by_id(pthis, info->id) == NULL);

    sc = sm_alloc_service_context(pthis);  /* find empty slot */
    if (sc)
    {
        kal_mem_cpy(&sc->info, info, sizeof(sc->info));

        /* call-back to notify client about the new service */
        sm_callback(pthis, sc, MTV_SERVICE_EVENT_FOUND, 0);
    }
    else
    {
        NOT_REACHED("Not enough memory for new service!");
    }
}

static mtv_result_t sm_write_be_packet(mtv_sm_t* pthis, mtv_service_context_t* sc, mtv_packet_t* au, kal_uint32 be_stream_index)
{
    mtv_result_t ret = MTV_S_FALSE;

    ASSERT(sc->be);
    if (au->timestamp != (kal_uint32) -1)
    {
        /*
         * save a checkpoint after a period of time.
         */
        if (sc->be->num_packets % MTV_SAVE_CHECKPOINT_INTERVAL == (MTV_SAVE_CHECKPOINT_INTERVAL - 1) &&
            sc_is_recorder_started(sc) && g_mtv_enable_rec_checkpoint)
        {
            SLA_BEGIN("CKP");
            sc->recorder->save_checkpoint(sc->recorder, pthis->record_config.record_dir);
            SLA_END("CKP");
        }

        SLA_BEGIN("BEW");
        ret = sc->be->write_packet(sc->be, be_stream_index, au);
        SLA_END("BEW");
        if (ret < 0)
        {
            if (sc_is_recorder_started(sc))
            {
                /* stop the recorder automaticlly */
                sm_stop_recorder(pthis, sc->info.id);

                /* notify the client about the error */
                sm_callback(pthis, sc, MTV_SERVICE_EVENT_RECORDER_ERROR, ret);

                /* the client should handle the error and save the recording */
            }

            /* the following processing applies both to time-shifted and recording */

            sc_close_buffer_engine(sc);

            /* notify the client about the error */
            sm_callback(pthis, sc, MTV_SERVICE_EVENT_PLAYER_TIMESHIFT_ERROR, ret);
        }
    }
	return ret;
}

static void sm_on_audio_au(mtv_spi_client_t* client, kal_uint32 service_id, mtv_packet_t* au)
{
    mtv_result_t ret = MTV_S_OK;
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    if (sc)
    {
        ASSERT(sc->state != MTV_SERVICE_STATE_STOPPED);
        if (sc->be)
        {
    		ret = sm_write_be_packet(pthis, sc, au, sc->be_audio_stream);
            switch (sc->be->get_read_state(sc->be))
            {
            case MTV_BE_READ_LIVE:
				if (sc_is_player_started(sc))
				{
					/* deliver the AU to decoder directly in no-delay mode */
					ret = sc->player->deliver_au(sc->player, MTV_STREAM_AUDIO, au);
				}
                break;
            }
        }
        else if (sc_is_player_started(sc))
        {
            ret = sc->player->deliver_au(sc->player, MTV_STREAM_AUDIO, au);
        }
    }
    else
    {
        NOT_REACHED("AU comes from unknown service!");
    }
}

static void sm_on_video_au(mtv_spi_client_t* client, kal_uint32 service_id, mtv_packet_t* au)
{
    mtv_result_t ret = MTV_S_OK;
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    if (sc)
    {
        ASSERT(sc->state != MTV_SERVICE_STATE_STOPPED);
        if (sc->be)
        {
			ret = sm_write_be_packet(pthis, sc, au, sc->be_video_stream);
            switch (sc->be->get_read_state(sc->be))
            {
            case MTV_BE_READ_LIVE:
				if (sc_is_player_started(sc))
				{
					/* deliver the AU to decoder directly in no-delay mode */
     				ret = sc->player->deliver_au(sc->player, MTV_STREAM_VIDEO, au);
				}
                break;
            }
        }
        else if (sc_is_player_started(sc))
        {
            ret = sc->player->deliver_au(sc->player, MTV_STREAM_VIDEO, au);
        }
    }
    else
    {
        NOT_REACHED("AU comes from unknown service!");
    }
}

static void sm_on_data_au(mtv_spi_client_t* client, kal_uint32 service_id, mtv_spi_service_data_type_t data_type, mtv_packet_t* au)
{
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

    if (sc)
    {
        switch (data_type)
        {
        case MTV_SPI_DYNAMIC_LABEL:

            /* assume AU data is a null-terminated wchar string */
            sm_callback(pthis, sc, MTV_SERVICE_EVENT_DYNAMIC_LABEL, (kal_uint32) au->data);

            /* does not pass it to player */
            break;

        case MTV_SPI_MPEG4_SCENE_DESCRIPTION:
        default:

            /* these data will be handled by player */

            ASSERT(sc->state != MTV_SERVICE_STATE_STOPPED);
            if (sc_is_player_started(sc))
            {
                sc->player->deliver_au(sc->player, MTV_STREAM_DATA, au);
            }
            break;
        }
    }
    else
    {
        NOT_REACHED("AU comes from unknown service!");
    }
}

static void sm_on_service_acquired(mtv_sm_t* pthis, mtv_spi_service_info_t* info)
{
    mtv_service_context_t* sc = sm_find_service_by_id(pthis, info->id);
	mtv_result_t ret;

    ASSERT(sc != NULL);

    ASSERT(sc->state == MTV_SERVICE_STATE_STARTED);
    sc->state = MTV_SERVICE_STATE_READY;

    /* copy the info again because it contains new info */
    kal_mem_cpy(&sc->info, info, sizeof(sc->info));

    ret = sm_start_buffer_engine(pthis, sc);
    if (ret < 0) {
        /* we can continue to play even when buffer engine is not available. */
    }

    if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_PLAY) != 0)
    {
        ret = sc_start_player(pthis, sc);
        if (ret < 0) {
            goto service_accquired_cleanup;
        }
    }

    if ((sc->activities & MEDIA_MTV_SERVICE_ACTIVITY_RECORD) != 0)
    {
        ret = sc_start_recorder(sc);
        if (ret < 0) {
            goto service_accquired_cleanup;
        }
    }

service_accquired_cleanup:
    if (ret >= 0)
    {
        sm_callback(pthis, sc, MTV_SERVICE_EVENT_READY, 0);
    }
    else
    {
        /*
         * May return failure for the following cases:
         *   - unsupport decoder
         *   - unsupport audio/video format
         *   - no audio/video streams can be found
         */
        sm_callback(pthis, sc, MTV_SERVICE_EVENT_ERROR, ret);
    }
}

static void sm_on_event(mtv_spi_client_t* client, mtv_spi_event_t event, kal_uint32 param)
{
    mtv_sm_t* pthis = PTHIS(client, mtv_sm_t, spi_client);

    MTV_TRACE(TRACE_INFO, MTV_TRC_SERVICE_EVENT, event);

    switch (event)
    {
    case MTV_SPI_SERVICE_ACQUIRED:
        {
            mtv_spi_service_info_t* info = (mtv_spi_service_info_t*) param;
            sm_on_service_acquired(pthis, info);
        }
        break;

    case MTV_SPI_SERVICE_ERROR:
    case MTV_SPI_SERVICE_ABORTED:
        {
            kal_uint32 service_id = param;
            mtv_service_context_t* sc = sm_find_service_by_id(pthis, service_id);

            sm_callback(pthis, sc, MTV_SERVICE_EVENT_ERROR, MTV_SPI_E_INTERNAL_ERROR);
        }
        break;

    case MTV_SPI_SERVICE_ADDED:
        {
            mtv_spi_service_info_t* si = (mtv_spi_service_info_t*) param;
            mtv_service_context_t* sc = sm_find_service_by_id(pthis, si->id);
            sm_callback(pthis, sc, MTV_SERVICE_EVENT_ADDED, (kal_uint32) si);
        }
        break;

    case MTV_SPI_SERVICE_REMOVED:
        {
            mtv_spi_service_info_t* si = (mtv_spi_service_info_t*) param;
            mtv_service_context_t* sc = sm_find_service_by_id(pthis, si->id);
            sm_callback(pthis, sc, MTV_SERVICE_EVENT_REMOVED, (kal_uint32) si);
        }
        break;

    case MTV_SPI_SEARCH_PROGRESS:
        {
            kal_uint32 percentage = param;
            sm_callback(pthis, NULL, MTV_SERVICE_EVENT_SEARCH_PROGRESS, percentage);
        }
        break;

    default:
        NOT_REACHED("Unhandled event!");
		break;
    }
}

void construct_mtv_sm(mtv_sm_t* pthis)
{
    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->open = sm_open;
    pthis->config = sm_config;
    pthis->find_unsaved_recording = sm_find_unsaved_recording;
    pthis->recover_recording = sm_recover_recording;
    pthis->abort_recovering = sm_abort_recovering;
    pthis->discard_unsaved_recording = sm_discard_unsaved_recording;
    pthis->search_services = sm_search_services;
    pthis->abort_searching = sm_abort_searching;
    pthis->start_service = sm_start_service;
    pthis->start_player = sm_start_player;
    pthis->stop_player = sm_stop_player;
    pthis->start_recorder = sm_start_recorder;
    pthis->stop_recorder = sm_stop_recorder;
    pthis->save_recording = sm_save_recording;
    pthis->abort_saving = sm_abort_saving;
    pthis->recorder_discard_recording = sm_recorder_discard_recording;
    pthis->get_recorder_state = sm_get_recorder_state;
    pthis->get_control = sm_get_control;
    pthis->get_service_param = sm_get_service_param;
    pthis->get_service_context = sm_get_service_context;
    pthis->stop_service = sm_stop_service_by_id;
    pthis->close = sm_close;

    pthis->spi_client.on_service = sm_on_service;
    pthis->spi_client.on_audio_au = sm_on_audio_au;
    pthis->spi_client.on_video_au = sm_on_video_au;
    pthis->spi_client.on_data_au = sm_on_data_au;
    pthis->spi_client.on_event = sm_on_event;
}

#endif /* defined(__MED_MTV_MOD__) */
