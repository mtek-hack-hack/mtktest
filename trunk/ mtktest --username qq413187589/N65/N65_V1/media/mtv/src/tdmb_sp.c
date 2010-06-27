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
 *   tdmb_sp.c
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
#include "med_global.h"

#if defined(__MED_MTV_MOD__) && defined(__TDMB_SUPPORT__)

#include "med_utility.h"
#include "med_trc.h"
#include "mtv_spi.h"
#include "dab_demod.h"
#include "dab_demux.h"
#include "tdmb_sp.h"
#include "cyberlink_adaptation.h"

#define MTV_MAX_ALLOWED_CONSECUTIVE_ERRORS 128
#define MTV_DEMUX_BUF_BYTES (384*1024)

void mtv_copy_dec_config_extra(mtv_dec_config_t* dst, mtv_dec_config_t* src)
{
    UNUSED(dst);
    UNUSED(src);
}

void mtv_free_dec_config_extra(mtv_dec_config_t* cfg)
{
    UNUSED(cfg);
}

static void copy_tdmb_stream_info(tdmb_stream_info_t* dst, tdmb_stream_info_t* src)
{
    *dst = *src;	/* do bit-wise copy first */
	mtv_copy_dec_config_extra(&dst->dec_config, &src->dec_config);
}

static void free_tdmb_stream_info(tdmb_stream_info_t* info)
{
	mtv_free_dec_config_extra(&info->dec_config);
}

static mtv_result_t tdmb_sp_open(mtv_spi_t* spi, mtv_spi_client_t* client)
{
    tdmb_sp_t* pthis = (tdmb_sp_t*) spi;
    mtv_result_t ret;

    if (pthis->state != TDMB_SP_CLOSED) {
        return MTV_E_WRONG_STATE;
    }
	if (client == NULL) {
		return MTV_E_INVALID_PARAM;
	}

    ASSERT(pthis->demux_buffer == NULL);
    pthis->demux_buffer = med_alloc_ext_mem(MTV_DEMUX_BUF_BYTES);
    if (!pthis->demux_buffer) {
        return MTV_E_OUT_OF_MEMORY;
    }
    cyberlink_init_adaptation(pthis->demux_buffer, MTV_DEMUX_BUF_BYTES);

    ret = pthis->demod->open(pthis->demod, &pthis->demod_client);
	if (ret < 0)
    {
        cyberlink_uninit_adaptation();
        med_free_ext_mem(&pthis->demux_buffer);
		return ret;
	}

    pthis->client = client;
    pthis->state = TDMB_SP_OPENED;

    return MTV_S_OK;
}

static kal_bool tdmb_is_service_started(tdmb_service_context_t* sc)
{
	return (sc->state != TDMB_SERVICE_STOPPED);
}

static tdmb_service_context_t* tdmb_find_service_context(tdmb_sp_t* pthis, kal_uint32 service_id)
{
    kal_int32 i;

    /* find specified service slot */
    for (i = 0; i < ARRAY_SIZE(pthis->services); i++)
    {
        if (tdmb_is_service_started(&pthis->services[i]) &&
			pthis->services[i].service_id == service_id)
		{
            return &pthis->services[i];
        }
    }

    return NULL;
}

static tdmb_service_context_t* tdmb_find_empty_service_context(tdmb_sp_t* pthis)
{
    kal_int32 i;

    /* find specified service slot */
    for (i = 0; i < ARRAY_SIZE(pthis->services); i++)
    {
        if (!tdmb_is_service_started(&pthis->services[i])) {
            return &pthis->services[i];
        }
    }

    return NULL;
}

static void tdmb_reset_service_context(tdmb_service_context_t* sc)
{
    kal_uint32 i;

    if (sc->demux)
    {
        sc->demux->destroy(sc->demux);
        sc->demux = NULL;
    }

    for (i = 0; i < sc->num_streams; i++) {
		free_tdmb_stream_info(&sc->streams[i]);
    }

    kal_mem_set(sc->streams, 0, sizeof(sc->streams));
    sc->num_streams = 0;
    sc->errors = 0;

    sc->sp = NULL; /* mark this context as free */
    sc->state = TDMB_SERVICE_STOPPED;
}

static mtv_result_t tdmb_sp_search_services(mtv_spi_t* spi, mtv_freq_band_t band)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
	mtv_result_t ret;

    if (pthis->state == TDMB_SP_SEARCHING_SERVICES) {
        return MTV_E_RESOURCE_CONFLICT; /* searching in progress */
    }
    else if (pthis->state != TDMB_SP_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    pthis->state = TDMB_SP_SEARCHING_SERVICES;

	ret = pthis->demod->scan(pthis->demod, band);
	if (ret < 0)    /* failed to open demod */
	{
        pthis->state = TDMB_SP_OPENED;
		return ret;
	}

    return ret;
}

static mtv_result_t tdmb_sp_abort_searching(mtv_spi_t* spi)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
	mtv_result_t ret;

    if (pthis->state != TDMB_SP_SEARCHING_SERVICES) {
        return MTV_E_WRONG_STATE;
    }

	ret = pthis->demod->stop_scan(pthis->demod);
	if (ret < 0) {   /* failed to stop demod */
		return ret;
	}

    pthis->state = TDMB_SP_OPENED;

    return ret;
}

static mtv_result_t tdmb_sp_start_service(mtv_spi_t* spi, kal_uint32 service_id)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
    mtv_result_t ret;
    tdmb_service_context_t* sc;
	dab_demod_service_t info;

    if (pthis->state == TDMB_SP_SEARCHING_SERVICES) {
        return MTV_E_RESOURCE_CONFLICT;
    }
    else if (pthis->state != TDMB_SP_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    /* check service_id validity */
    sc = tdmb_find_service_context(pthis, service_id);
    if (sc) {
        return MTV_SPI_E_ALREADY_STARTED;
    }
    sc = tdmb_find_empty_service_context(pthis);
    if (!sc) {
        return MTV_SPI_E_NO_MORE_SERVICE;
    }

    ret = pthis->demod->get_service_info(pthis->demod, service_id, &info);
    if (ret < 0) {
        return ret;
    }

    /* specified the ID new so that data can be dispatched immediately after
       the service is started */
    sc->service_id = service_id;

    ASSERT(sc->demux == NULL);

    /* open demux according to application type */
    switch (info.app_type)
    {
    case DAB_APPLICATION_DMB:       /* if it is T-DMB service */
        sc->demux = construct_cyberlink_tdmb_demux();
        break;

    case DAB_APPLICATION_DAB:
        sc->demux = construct_dab_demux();
        break;

    default:
        MTV_TRACE(TRACE_INFO, MTV_TRC_UNSUPPORTED_SERVICE_TYPE, info.app_type);
        return MTV_SPI_E_UNSUPPORTED_SERVICE_TYPE;
    }

    ASSERT(sc->demux);
    ret = sc->demux->open(sc->demux, &sc->demux_client);
    if (ret >= 0)
    {
        sc->sp = pthis;
        sc->state = TDMB_SERVICE_STARTED;
    }
	else
    {
        tdmb_reset_service_context(sc);
        return ret;
    }

    /* command demod to start the service */
    ret = pthis->demod->start_service(pthis->demod, service_id);
    if (ret < 0)
    {
        sc->demux->close(sc->demux);
        tdmb_reset_service_context(sc);
        return ret;
    }

    return ret;
}

static mtv_result_t tdmb_sp_stop_service(mtv_spi_t* spi, kal_uint32 service_id)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
    mtv_result_t ret;
    tdmb_service_context_t* sc;

    if (pthis->state != TDMB_SP_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    /* find specified service slot */
    sc = tdmb_find_service_context(pthis, service_id);
    if (!sc) {
        return MTV_S_FALSE; /* the service is already stopped */
    }

    ret = pthis->demod->stop_service(pthis->demod, service_id);
    if (ret < 0) {
        return ret;
    }

    ASSERT(sc->demux);
    ret = sc->demux->close(sc->demux);
    ASSERT(ret >= 0);

    tdmb_reset_service_context(sc);

    return MTV_S_OK;
}

static mtv_result_t tdmb_sp_get_status(mtv_spi_t* spi, mtv_spi_status_t* status)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
    dab_demod_status_t demod_status;
    mtv_result_t ret;

    ret = pthis->demod->get_status(pthis->demod, &demod_status);
    if (ret >= 0)
    {
        status->signal_strength = demod_status.signal_strength;
    }

    return ret;
}

static mtv_result_t tdmb_sp_abort_all_services(mtv_spi_t* spi)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
    mtv_result_t ret;
    kal_int32 i;

    for (i = 0; i < ARRAY_SIZE(pthis->services); i++)
    {
        if (tdmb_is_service_started(&pthis->services[i]))
        {
			kal_uint32 service_id = pthis->services[i].service_id;

            ret = spi->stop_service(spi, service_id);
            ASSERT(ret >= 0);

            pthis->client->on_event(pthis->client, MTV_SPI_SERVICE_ABORTED, service_id);
        }
    }

    return MTV_S_OK;
}

static mtv_result_t tdmb_sp_restart_service(mtv_spi_t* spi, kal_uint32 service_id)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_TDMB_RESTART_SERVICE, service_id);

    /* try restarting the service when consecutive errors occurred */
    ret = tdmb_sp_stop_service(spi, service_id);
    ASSERT(ret >= 0);

    ret = tdmb_sp_start_service(spi, service_id);
    if (ret >= 0)
    {
        tdmb_service_context_t* sc = tdmb_find_service_context(pthis, service_id);

        /* change the state to TDMB_SERVICE_RESTARTING for special handling */
        sc->state = TDMB_SERVICE_RESTARTING;
    }

    return ret;
}

static mtv_result_t tdmb_sp_close(mtv_spi_t* spi)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
    mtv_result_t ret;

    if (pthis->state == TDMB_SP_CLOSED) {
        return MTV_E_WRONG_STATE;
    }
    else if (pthis->state == TDMB_SP_SEARCHING_SERVICES) {
        spi->abort_searching(spi);
    }

    ret = tdmb_sp_abort_all_services(spi);
    ASSERT(ret >= 0);

    ret = pthis->demod->close(pthis->demod);
    ASSERT(ret >= 0);
    pthis->demod->destroy(pthis->demod);
    pthis->demod = NULL;

    cyberlink_uninit_adaptation();
    med_free_ext_mem(&pthis->demux_buffer);

    pthis->state = TDMB_SP_CLOSED;

    return MTV_S_OK;
}

void tdmb_sp_destroy(mtv_spi_t* spi)
{
    tdmb_sp_t* pthis = PTHIS(spi, tdmb_sp_t, itf);
    med_free_ext_mem((void**) &pthis);
}

static void dab_demod_on_ensemble(dab_demod_client_t* client, dab_demod_ensemble_t* ensemble)
{
    tdmb_sp_t* pthis = PTHIS(client, tdmb_sp_t, demod_client);

    ASSERT(pthis->state == TDMB_SP_SEARCHING_SERVICES);

    pthis->search_ctx.found_ensemble = ensemble;
}

static void dab_demod_fill_service_info(mtv_spi_service_info_t* info, dab_demod_service_t* dab_service, tdmb_service_context_t* sc)
{
    kal_uint32 i;

    kal_mem_set(info, 0, sizeof(*info));

    info->id = dab_service->id;
    kal_wstrncpy(info->name, dab_service->name, ARRAY_SIZE(info->name));
    info->number = dab_service->number;

    /* TODO: check CA flag here */
    info->flags = MTV_SPI_SERVICE_FREE | MTV_SPI_SERVICE_CLEAR_TO_AIR;

    switch (dab_service->app_type)
    {
    case DAB_APPLICATION_DMB:
        info->type = MTV_SPI_SERVICE_DIGITAL_TV;
        break;

    case DAB_APPLICATION_DAB:
        info->type = MTV_SPI_SERVICE_DIGITAL_RADIO;
        break;

    case DAB_APPLICATION_MOT_SLIDE_SHOW:
        info->type = MTV_SPI_SERVICE_MOT_SLIDESHOW;
        break;

    case DAB_APPLICATION_MOT_BWS:
        info->type = MTV_SPI_SERVICE_MOT_BWS;
        break;

    case DAB_APPLICATION_TPEG:
        info->type = MTV_SPI_SERVICE_TPEG;
        break;

    case DAB_APPLICATION_EPG:
        info->type = MTV_SPI_SERVICE_EPG;
        break;

    default:
        info->type = MTV_SPI_SERVICE_UNKNOWN;
        break;
    }

	if (sc)
	{
		ASSERT(ARRAY_SIZE(info->components) >= ARRAY_SIZE(sc->streams));

		info->num_components = 0;
		for (i = 0; i < sc->num_streams; i++)
		{
			tdmb_stream_info_t* si = &sc->streams[i];
			mtv_spi_component_info_t* comp = &info->components[info->num_components++];

			switch (si->stream_type)
			{
			case MPEG4_STREAM_VISUAL:
				comp->type = MTV_SPI_COMPONENT_VIDEO;
				comp->flags = MTV_SPI_COMPONENT_PRIMARY;
				break;

			case MPEG4_STREAM_AUDIO:
				comp->type = MTV_SPI_COMPONENT_AUDIO;
				break;

			case MPEG4_STREAM_SCENE_DESCRIPTION:
				comp->type = MTV_SPI_COMPONENT_DATA;
				break;

			default:
				NOT_REACHED("Unhandled stream type from T-DMB demux!");
				return;
			}

            /* assume demux will send only one stream for each type (audio/video/BIFS) */
			comp->flags = MTV_SPI_COMPONENT_PRIMARY;

			comp->dec_config = si->dec_config;
		}
	}
}

static void dab_demod_on_service(dab_demod_client_t* client, dab_demod_service_t* service)
{
	tdmb_sp_t* pthis = PTHIS(client, tdmb_sp_t, demod_client);
    mtv_spi_service_info_t info;

    ASSERT(pthis->state == TDMB_SP_SEARCHING_SERVICES);

    pthis->search_ctx.found_service = service;
    dab_demod_fill_service_info(&info, service, NULL);

    pthis->client->on_service(pthis->client, &info);
}

static void dab_demod_on_component(dab_demod_client_t* client, dab_demod_component_t* component)
{
	tdmb_sp_t* pthis = PTHIS(client, tdmb_sp_t, demod_client);

    ASSERT(pthis->state == TDMB_SP_SEARCHING_SERVICES);

    pthis->search_ctx.found_component = component;
}

static void dab_demod_on_data(dab_demod_client_t* client, kal_uint32 service_id, kal_uint8* data, kal_uint32 size)
{
    tdmb_sp_t* pthis = PTHIS(client, tdmb_sp_t, demod_client);
    tdmb_service_context_t* sc = tdmb_find_service_context(pthis, service_id);
    mtv_result_t ret;

    if (sc)
    {
        /* pass the data to corresponding demux */
        ret = sc->demux->send(sc->demux, data, size);

        /* handle errors */
        if (ret < 0 && ++sc->errors >= MTV_MAX_ALLOWED_CONSECUTIVE_ERRORS)
        {
            /* try restarting the service when consecutive errors occurred */
            ret = tdmb_sp_restart_service(&pthis->itf, service_id);
            if (ret < 0)
            {
                /* abort the service finally if it still cannot work */
                pthis->client->on_event(pthis->client, MTV_SPI_SERVICE_ABORTED, service_id);
            }
        }
        else {
            sc->errors = 0;  /* reset the error count */
        }
    }
    else
    {
        NOT_REACHED("Data from unknown stream ID!");
    }
}

static void dab_demod_on_event(dab_demod_client_t* client, dab_demod_event_t event, kal_uint32 param)
{
    tdmb_sp_t* pthis = PTHIS(client, tdmb_sp_t, demod_client);

    switch (event)
    {
    case DAB_DEMOD_ERROR:
        /* abort all services if there is any demod error */
        tdmb_sp_abort_all_services(&pthis->itf);
        break;

    case DAB_DEMOD_SCAN_PROGRESS:
        {
            kal_uint32 percentage = param;

            ASSERT(pthis->state == TDMB_SP_SEARCHING_SERVICES);
            if (percentage == 100)
            {
                pthis->state = TDMB_SP_OPENED;
            }
            else if (percentage > 100)
            {
                SHOULD_NOT_HAPPEN("More than 100%!");
                percentage = 100;
            }

            pthis->client->on_event(pthis->client, MTV_SPI_SEARCH_PROGRESS, percentage);
        }
        break;

    case DAB_DEMOD_SERVICE_ABORTED:
        pthis->client->on_event(pthis->client, MTV_SPI_SERVICE_ABORTED, param);
        break;

    case DAB_DEMOD_ANNOUNCEMENT:
        /* TODO: handle announcement */
        break;

    default:
        NOT_REACHED("Unhandled event!");
        break;
    }
}

static kal_bool tdmb_demux_on_stream(tdmb_demux_client_t* client, tdmb_stream_info_t* stream)
{
    tdmb_service_context_t* sc = PTHIS(client, tdmb_service_context_t, demux_client);
    kal_uint32 i;

    if (sc->num_streams >= ARRAY_SIZE(sc->streams))
    {
        NOT_REACHED("Not enough space for more stream!");
        return KAL_FALSE;
    }

    /* disable duplicated stream of existing stream type */
    for (i = 0; i < sc->num_streams; i++)
    {
        if (sc->streams[i].stream_type == stream->stream_type) {
            return KAL_FALSE;
        }
    }

    ASSERT(stream->dec_config.timestamp_resolution != 0);
    copy_tdmb_stream_info(&sc->streams[sc->num_streams++], stream);

    return KAL_TRUE;
}

static void tdmb_demux_on_access_unit(tdmb_demux_client_t* client, kal_uint32 stream_id, mtv_packet_t* au)
{
    tdmb_service_context_t* sc = PTHIS(client, tdmb_service_context_t, demux_client);
    tdmb_sp_t* pthis = sc->sp;
	kal_uint32 i;

    ASSERT(au->data != NULL);
    ASSERT(au->size > 0);

    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_PACKET, stream_id, au->size, au->timestamp);

    for (i = 0; i < sc->num_streams; i++)
    {
        tdmb_stream_info_t* stream = &sc->streams[i];
        if (stream->stream_id == stream_id)
        {
            switch (stream->stream_type)
            {
            case MPEG4_STREAM_VISUAL:
                pthis->client->on_video_au(pthis->client, sc->service_id, au);
                break;

            case MPEG4_STREAM_AUDIO:

                if ((au->flags & MTV_PACKET_FROM_CL_TDMB_DEMUX) != 0)
                {
                    if (stream->dec_config.codec == MTV_CODEC_AAC)
                    {
                        /* Cyberlink demux will always append 7-byte ADTS header to AAC audio. */
                        ASSERT(au->size > LEN_ADTS_HEADER);
                        au->flags |= MTV_PACKET_WITH_ADTS_HEADER;
                    }
                }
                pthis->client->on_audio_au(pthis->client, sc->service_id, au);
                break;

            default:
                NOT_REACHED("Unhandled stream type!");
                break;
            }

            return;
        }
    }

    /* ignore packets from other unsupported streams */
}

static void tdmb_demux_on_pad(tdmb_demux_client_t* client, tdmb_pad_data_type_t data_type, mtv_packet_t* data)
{
    tdmb_service_context_t* sc = PTHIS(client, tdmb_service_context_t, demux_client);
    tdmb_sp_t* pthis = sc->sp;

    switch (data_type)
    {
    case TDMB_PAD_DYNAMIC_LABEL:
        pthis->client->on_data_au(pthis->client, sc->service_id, MTV_SPI_DYNAMIC_LABEL, data);
        break;

    default:
        NOT_REACHED("Unhandled PAD data type!");
        break;
    }
}

static mtv_result_t tdmb_demux_on_event(tdmb_demux_client_t* client, tdmb_demux_event_t event)
{
    tdmb_service_context_t* sc = PTHIS(client, tdmb_service_context_t, demux_client);
    tdmb_sp_t* pthis = sc->sp;
    mtv_result_t ret = MTV_S_OK;

    switch (event)
    {
    case TDMB_DEMUX_ALL_STREAMS_FOUND:

        if (sc->state == TDMB_SERVICE_RESTARTING)
        {
            /* don't notify the client and just transit to READY state */
            sc->state = TDMB_SERVICE_READY;
        }
        else
        {
            dab_demod_service_t* dab_service = (dab_demod_service_t*) med_alloc_ext_mem(sizeof(*dab_service));
            mtv_spi_service_info_t* info = (mtv_spi_service_info_t*) med_alloc_ext_mem(sizeof(*info ));
            mtv_result_t ret;

            ASSERT(sc->state == TDMB_SERVICE_STARTED);

            MTV_TRACE(TRACE_INFO, MTV_TRC_DEMUX_TOTAL_STREAMS, sc->num_streams);

            ret = pthis->demod->get_service_info(pthis->demod, sc->service_id, dab_service);
            ASSERT(ret >= 0);
            dab_demod_fill_service_info(info, dab_service, sc);

            /* notify the client about service info */
            pthis->client->on_event(pthis->client, MTV_SPI_SERVICE_ACQUIRED, (kal_uint32) info);

            med_free_ext_mem((void**) &info);
            med_free_ext_mem((void**) &dab_service);

            /* Note that the service may be stopped in ACCQUIRED callback. Check whether the state is still in STARTED here. */
            if (sc->state == TDMB_SERVICE_STARTED)
            {
                sc->state = TDMB_SERVICE_READY;
            }
            else
            {
                ASSERT(sc->demux == NULL);
                ret = MTV_E_FAIL;
            }
        }
        break;

    case TDMB_DEMUX_ERROR:
        pthis->client->on_event(pthis->client, MTV_SPI_SERVICE_ERROR, sc->service_id);
        ret = MTV_E_FAIL;
        break;

    default:
        NOT_REACHED("Unhandled event code!");
        ret = MTV_E_FAIL;
        break;
    }

    return ret;
}

mtv_spi_t* construct_tdmb_sp(void)
{
    kal_int32 i;
    tdmb_sp_t* pthis = (tdmb_sp_t*) med_alloc_ext_mem(sizeof(*pthis));
    ASSERT(pthis);

    pthis->itf.open = tdmb_sp_open;
    pthis->itf.search_services = tdmb_sp_search_services;
    pthis->itf.abort_searching = tdmb_sp_abort_searching;
    pthis->itf.start_service = tdmb_sp_start_service;
    pthis->itf.stop_service = tdmb_sp_stop_service;
    pthis->itf.get_status = tdmb_sp_get_status;
    pthis->itf.close = tdmb_sp_close;
    pthis->itf.destroy = tdmb_sp_destroy;

    pthis->demod_client.on_ensemble = dab_demod_on_ensemble;
    pthis->demod_client.on_service = dab_demod_on_service;
    pthis->demod_client.on_component = dab_demod_on_component;
    pthis->demod_client.on_data = dab_demod_on_data;
    pthis->demod_client.on_event = dab_demod_on_event;

#if defined(_MTV_USE_TDMB_TS_DEMOD)
    pthis->demod = construct_tdmb_ts_demod();
#else
    pthis->demod = construct_tdmb_demod();
#endif

    kal_mem_set(pthis->services, 0, sizeof(pthis->services));
    for (i = 0; i < ARRAY_SIZE(pthis->services); i++)
    {
        tdmb_service_context_t* sc = &pthis->services[i];

        sc->demux_client.on_stream = tdmb_demux_on_stream;
        sc->demux_client.on_access_unit = tdmb_demux_on_access_unit;
        sc->demux_client.on_pad = tdmb_demux_on_pad;
        sc->demux_client.on_event = tdmb_demux_on_event;
    }

	pthis->client = NULL;
    pthis->state = TDMB_SP_CLOSED;
    pthis->demux_buffer = NULL;

	return &pthis->itf;
}

#endif /* defined(__MED_MTV_MOD__) && defined(__TDMB_SUPPORT__) */
