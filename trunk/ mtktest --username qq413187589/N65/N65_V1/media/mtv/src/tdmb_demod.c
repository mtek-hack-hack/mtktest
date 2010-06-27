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
 *   tdmb_demod.c
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

#if defined(__MED_MTV_MOD__) && defined(__TDMB_SUPPORT__)

#include "tdmb_demod.h"

#include "med_trc.h"
#include "med_utility.h"

#if defined(WIN32)
#include <windows.h>
#include <tchar.h>
#endif

#if !defined(_MTV_USE_TDMB_TS_DEMOD)

#define _DUMP_TDMB_DATA
#ifdef _DUMP_TDMB_DATA
    typedef struct
    {
        kal_uint8 data[5120*188];
        kal_uint32 len;
    } data_dump_t;
    #define DECLARE_DUMP(_d) static data_dump_t _d;
    #define INIT_DUMP(_d) _d.len = 0;
    #define DUMP_DATA(_d, _p, _len) \
        do { \
            kal_uint32 offset = _d.len % ARRAY_SIZE(_d.data); \
            if (offset + _len <= ARRAY_SIZE(_d.data)) {\
                kal_mem_cpy(_d.data + offset, _p, _len); \
            } else { \
                kal_uint32 tail_bytes = ARRAY_SIZE(_d.data) - offset; \
                kal_mem_cpy(_d.data + offset, _p, tail_bytes); \
                kal_mem_cpy(_d.data, (kal_uint8*) _p + tail_bytes, _len - tail_bytes); \
            } \
            _d.len += _len; \
        } while (0);
#else
    #define DECLARE_DUMP(_d)
    #define INIT_DUMP(_d) do {;} while(0);
    #define DUMP_DATA(_d, _p, _len) do {;} while(0);
#endif

DECLARE_DUMP(g_ts_dump)

#define MSG_STRUCT(type, name, ilm) \
    type* name  = (type*) ilm->local_para_ptr

static void send_tdmb_msg(kal_uint16 msg_id, void* local_param_ptr)
{
    ilm_struct* ilm = NULL;
    module_type src_mod_id = MTV_TRANSPORT_MOD;

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = INVALID_SAP;

    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;

    ilm->dest_mod_id = MOD_TDMB;

    msg_send_ext_queue(ilm);
}

static void tdmb_data_indication(void* parameter)
{
    tdmb_demod_t* pthis = (tdmb_demod_t*) parameter;

    ASSERT(pthis->state == DAB_DEMOD_OPENED);

    if (pthis->send_data_notification && tdmb_get_data_avail() > 0)
    {
        ilm_struct* ilm = NULL;
        module_type src_mod_id = MTV_TRANSPORT_MOD;
        CONSTRUCT_LOCAL_PARAM(media_mtv_tdmb_data_ind_struct, ind);

        pthis->send_data_notification = KAL_FALSE;

        ind->tdmb_demod = pthis;

        ilm = allocate_ilm(src_mod_id);
        ilm->src_mod_id = src_mod_id;
        ilm->sap_id = INVALID_SAP;
        ilm->msg_id = (msg_type) MSG_ID_TDMB_DATA_INDICATION;
        ilm->local_para_ptr = (local_para_struct*) ind;
        ilm->peer_buff_ptr = NULL;

        ilm->dest_mod_id = MTV_TRANSPORT_MOD;

        msg_send_ext_queue(ilm);
    }
}

static void tdmb_demod_get_signal(tdmb_demod_t* pthis)
{
    CONSTRUCT_LOCAL_PARAM(tdmb_get_signal_request_struct, req);

    send_tdmb_msg(MSG_ID_TDMB_GET_SIGNAL_REQUEST, req);

    /* update SNR and BER in confirm message handler */
}

static mtv_result_t tdmb_demod_open(dab_demod_t* demod, dab_demod_client_t* client)
{
	tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);

    if (pthis->state != DAB_DEMOD_CLOSED) {
        return MTV_E_WRONG_STATE;
    }
	if (client == NULL) {
		return MTV_E_INVALID_PARAM;
	}

    MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_OPENING);

    {
        CONSTRUCT_LOCAL_PARAM(tdmb_turn_on_request_struct, req);

        req->cb = tdmb_data_indication;
        req->cb_para = pthis;

#ifndef __MTK_TARGET__
        {
            WCHAR wszFilename[MAX_PATH] = {'\0'};
            OPENFILENAMEW of;
            WCHAR wszExtName[100] = {0};

            memset((LPVOID)&of, 0, sizeof(OPENFILENAME));
            of.lStructSize = sizeof(OPENFILENAME);
            of.hwndOwner = NULL;
            of.lpstrCustomFilter = NULL;
            of.nFilterIndex = 1;
            of.lpstrFile = wszFilename;
            of.lpstrFile[0] = L'\0';
            of.nMaxFile = sizeof(wszFilename)/sizeof(TCHAR);
            of.lpstrFileTitle = NULL;
            of.lpstrInitialDir = L"..\\..\\..\\..\\WIN32FS";
            of.lpstrTitle = L"Open ETI file\0";
            of.Flags = OFN_FILEMUSTEXIST | OFN_READONLY | OFN_PATHMUSTEXIST;
            of.lpstrDefExt = wszExtName;
            of.lpfnHook = NULL;

            if (GetOpenFileNameW(&of))
            {
                WCHAR* p = wcsstr(of.lpstrFile, L"DRIVE_");
                if (p)
                {
                    p[5] = p[6];
                    p[6] = L':';
                    req->RFH = FS_Open(p + 5, FS_READ_ONLY);
                }
            }
            else
            {
                return MTV_E_FAIL;
            }
        }
#endif
        send_tdmb_msg(MSG_ID_TDMB_TURN_ON_REQUEST, req);
    }

    /* TODO: wait until the confirm message has arrived */

	pthis->client = client;
	pthis->state = DAB_DEMOD_OPENED;
    pthis->ensembles = NULL;
    pthis->send_data_notification = KAL_TRUE;
    pthis->packet_count = 0;

    kal_mem_set(pthis->active_services, 0, sizeof(pthis->active_services));

    tdmb_demod_get_signal(pthis);

    INIT_DUMP(g_ts_dump)

	return MTV_S_OK;
}

typedef struct {
    mtv_freq_band_t band;
    TDMB_BAND_enum device_band;
} dab_demod_band_mapping_t;

const dab_demod_band_mapping_t g_dab_demod_band_mapping[] =
{
    {MTV_FREQ_INVALID_BAND,    TDMB_UNDEF_BAND},
    {MTV_FREQ_KOREA_BAND,      TDMB_KOREA_BAND},
    {MTV_FREQ_BAND_III,        TDMB_BAND_III},
    {MTV_FREQ_L_BAND,          TDMB_L_BAND},
    {MTV_FREQ_CANADA_BAND,     TDMB_CANADA_BAND},
    {MTV_FREQ_CHINESE_BAND,    TDMB_CHINESE_BAND},
    {MTV_FREQ_BAND_II,         TDMB_BAND_II},
    {MTV_FREQ_BAND_IF,         TDMB_BAND_IF}
};

static TDMB_BAND_enum tdmb_demod_to_device_band(mtv_freq_band_t band)
{
    kal_int32 i;
    for (i = 0; i < ARRAY_SIZE(g_dab_demod_band_mapping); i++)
    {
        if (g_dab_demod_band_mapping[i].band == band) {
            return g_dab_demod_band_mapping[i].device_band;
        }
    }
    NOT_REACHED("Unknown frequency band?!");
    return TDMB_UNDEF_BAND;
}

static mtv_freq_band_t tdmb_demod_from_device_band(TDMB_BAND_enum device_band)
{
    kal_int32 i;
    for (i = 0; i < ARRAY_SIZE(g_dab_demod_band_mapping); i++)
    {
        if (g_dab_demod_band_mapping[i].device_band == device_band) {
            return g_dab_demod_band_mapping[i].band;
        }
    }
    NOT_REACHED("Unknown frequency band?!");
    return MTV_FREQ_INVALID_BAND;
}

static mtv_result_t tdmb_demod_scan(dab_demod_t* demod, mtv_freq_band_t band)
{
	tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);

    MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_SCANNING);

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    pthis->state = DAB_DEMOD_SCANNING;

    /* band */
    {
        CONSTRUCT_LOCAL_PARAM(tdmb_set_band_request_struct, req);

        req->band = tdmb_demod_to_device_band(band);
        send_tdmb_msg(MSG_ID_TDMB_SET_BAND_REQUEST, req);
    }
    /* scan specified band */
    {
        send_tdmb_msg(MSG_ID_TDMB_AUTO_SCAN_REQUEST, NULL);
    }

    /* send progress 0% */
    pthis->client->on_event(pthis->client, DAB_DEMOD_SCAN_PROGRESS, 0);

	return MTV_S_OK;
}

static mtv_result_t tdmb_demod_stop_scan(dab_demod_t* demod)
{
    tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);

    if (pthis->state != DAB_DEMOD_SCANNING) {
        return MTV_S_FALSE;
    }

    /*
     * Since tdmb task is busy in scanning loop, we have to stop it with
     * a function call rather than a message.
     */
    tdmb_stop_autoscan();

    pthis->state = DAB_DEMOD_OPENED;
    return MTV_S_OK;
}

static TDMB_SERVICEDB* tdmb_find_service_db(tdmb_demod_t* pthis, kal_uint32 service_id)
{
    TDMB_ENSEMBLEDB* ensemble;

    for (ensemble = pthis->ensembles; ensemble != NULL; ensemble = ensemble->Next)
    {
        TDMB_SERVICEDB* service = ensemble->Service;
        for (; service != NULL; service = service->Next)
        {
            if (service->Id == service_id) {
                return service;
            }
        }
    }

    return NULL;
}

static mtv_result_t tdmb_demod_tune_to_service(dab_demod_t* demod, kal_uint32 service_id)
{
    tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);
    TDMB_ENSEMBLEDB* ensemble;

    for (ensemble = pthis->ensembles; ensemble != NULL; ensemble = ensemble->Next)
    {
        TDMB_SERVICEDB* service = ensemble->Service;

        for (; service != NULL; service = service->Next)
        {
            if (service->Id == service_id)
            {
                /* band */
                {
                    CONSTRUCT_LOCAL_PARAM(tdmb_set_band_request_struct, req);

                    req->band = ensemble->Band;
                    send_tdmb_msg(MSG_ID_TDMB_SET_BAND_REQUEST, req);
                }
                /* freq */
                {
                    CONSTRUCT_LOCAL_PARAM(tdmb_set_frequency_request_struct, req);

                    req->fre = ensemble->Frequency;
                    send_tdmb_msg(MSG_ID_TDMB_SET_FREQUENCY_REQUEST, req);
                }

                MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_TUNING, ensemble->Band, ensemble->Frequency);
                return MTV_S_OK;
            }
        }
    }

    return MTV_E_FAIL;
}

static mtv_result_t tdmb_demod_start_service(dab_demod_t* demod, kal_uint32 service_id)
{
	tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);
    TDMB_SERVICEDB* service_db;
    mtv_result_t ret;
    kal_int32 i;

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_STARTING_SERVICE, service_id);

    service_db = tdmb_find_service_db(pthis, service_id);
    if (!service_db) {
        return MTV_E_INVALID_PARAM;
    }

    for (i = 0; i < ARRAY_SIZE(pthis->active_services); i++)
    {
        if (pthis->active_services[i].db == NULL)
        {
            pthis->active_services[i].id = service_id;

            /* TODO: prevent tuning again if the new service uses the same frequency */
            ret = tdmb_demod_tune_to_service(demod, service_id);
            if (ret >= 0) {
                pthis->state = DAB_DEMOD_TUNING;
            }
            return ret;
        }
    }

    return MTV_E_RESOURCE_CONFLICT;
}

static dab_application_type_t tdmb_get_app_type(TDMB_CHANNELDB* channel)
{
    dab_application_type_t app_type = DAB_APPLICATION_UNKNOWN;

    switch (channel->Type)
    {
    case 1:
        app_type = DAB_APPLICATION_DAB;
        break;

    case 2:
        app_type = DAB_APPLICATION_DMB;
        break;

    default:

        /* ETSI TS 101 756 V1.23.1 secton 5.3 */
        switch (channel->ASCTy_DSCTy)
        {
        case 0x01:
            app_type = DAB_APPLICATION_TMC;
            break;

        case 0x02:
            app_type = DAB_APPLICATION_EWS;
            break;

        case 0x03:
            app_type = DAB_APPLICATION_ITTS;
            break;

        case 0x04:
            app_type = DAB_APPLICATION_PAGING;
            break;

        case 0x05:
            app_type = DAB_APPLICATION_TDC;
            break;

        case 0x06:
            app_type = DAB_APPLICATION_MPEG2_TS;
            break;

        case 0x3b:
            app_type = DAB_APPLICATION_IP_PACKETS;
            break;

        case 0x3c:
            app_type = DAB_APPLICATION_MOT_UNKNOWN;
            break;

        case 0x3d:
        case 0x3e:
            app_type = DAB_APPLICATION_PROPRIETARY;
            break;

        case 0x3f:
            app_type = DAB_APPLICATION_EXTENSION;
            break;

        }

        break;
    }

    if (app_type == DAB_APPLICATION_UNKNOWN || app_type == DAB_APPLICATION_MOT_UNKNOWN)
    {
        /* ETSI TS 101 756 V1.23.1 secton 5.10 */
        switch (channel->UserApplType)
        {
        case 0x02:
            app_type = DAB_APPLICATION_MOT_SLIDE_SHOW;
            break;

        case 0x03:
            app_type = DAB_APPLICATION_MOT_BWS;
            break;

        case 0x04:
            app_type = DAB_APPLICATION_TPEG;
            break;

        case 0x05:
            app_type = DAB_APPLICATION_DGPS;
            break;

        case 0x06:
            app_type = DAB_APPLICATION_TMC;
            break;

        case 0x07:
            app_type = DAB_APPLICATION_EPG;
            break;

        case 0x08:
            app_type = DAB_APPLICATION_DAB_JAVA;
            break;

        case 0x09:
            app_type = DAB_APPLICATION_DMB;
            break;
        }
    }

    return app_type;
}

static void mtv_trim_leading_and_trailing_space(kal_wchar* str)
{
    kal_wchar *p, *q;
    kal_int32 leading_spaces = 0;

    /* count leading spaces */
    for (p = str; *p != 0; p++)
    {
        if (*p == L' ') {
            leading_spaces++;
        }
        else {
            break;
        }
    }

    /* remove leading spaces */
    for (p = str + leading_spaces, q = str; *p != 0; p++, q++)
    {
        if (p != q)
        {
            *q = *p;
            *p = L' ';
        }
    }


    /* remove tailing spaces */
    for (; p != str; p--)
    {
        if (p[- 1] == L' ') {
            p[- 1] = 0;
        }
        else {
            break;
        }
    }
}

static mtv_result_t tdmb_fill_service_info(dab_demod_service_t* info, TDMB_SERVICEDB* service)
{
    TDMB_CHANNELDB* channel;

    for (channel = service->Channel;
         channel != NULL;
         channel = channel->Next)
    {
#ifndef __MTK_TARGET__ /* wait for host lib implementation */
        if (!channel->Primary) {
            continue;
        }
#endif

        info->id = service->Id;

        switch (channel->pSvcComp->TMId)
        {
        case 0:
            info->transport = DAB_DEMOD_STREAM_MODE_AUDIO;
            info->where = channel->pSvcComp->SubCh_FIDCId;
            break;

        case 1:
            info->transport = DAB_DEMOD_STREAM_MODE_DATA;
            info->where = channel->pSvcComp->SubCh_FIDCId;
            break;

        case 2:
            info->transport = DAB_DEMOD_FIDC;
            info->where = channel->pSvcComp->SubCh_FIDCId;
            break;

        case 3:
            info->transport = DAB_DEMOD_PACKET_MODE;
            info->where = channel->pSvcComp->SCId;
            break;

        default:
            NOT_REACHED("Unknown T-DMB TMId!");
            info->transport = DAB_DEMOD_INVALID_TRANSPORT;
            info->where = 0;
            break;
        }

        info->app_type = tdmb_get_app_type(channel);
        info->app_data = 0;
        info->app_data_size = 0;
        info->ca_flag = channel->CAflag;
        info->number = 0;
        med_util_utf8_to_ucs2((kal_uint8*) info->name, sizeof(info->name), (kal_uint8*) service->Label, sizeof(service->Label));
        mtv_trim_leading_and_trailing_space(info->name);

        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t tdmb_get_service_info(dab_demod_t* demod, kal_uint32 service_id, dab_demod_service_t* info)
{
	tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);
    TDMB_SERVICEDB* service_db;

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    service_db = tdmb_find_service_db(pthis, service_id);
    if (service_db)
    {
        return tdmb_fill_service_info(info, service_db);
    }

    return MTV_E_INVALID_PARAM;
}

static mtv_result_t tdmb_demod_stop_service(dab_demod_t* demod, kal_uint32 service_id)
{
	tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);
    kal_int32 i;

    MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_STOPPING_SERVICE, service_id);

    if (pthis->state == DAB_DEMOD_TUNING)
    {
        /* cannot stop a service before tuning finishes */
        return MTV_E_BUSY;
    }
	else if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    for (i = 0; i < ARRAY_SIZE(pthis->active_services); i++)
    {
        if (pthis->active_services[i].id == service_id)
        {
            pthis->active_services[i].id = 0;
            pthis->active_services[i].db = NULL;
            break;
        }
    }

    if (i >= ARRAY_SIZE(pthis->active_services)) {
        return MTV_S_FALSE;  /* the service was not started */
    }
    else
    {
        CONSTRUCT_LOCAL_PARAM(tdmb_set_idle_request_struct, req);

        req->enable = 0;
        send_tdmb_msg(MSG_ID_TDMB_SET_IDLE_REQUEST, req);

    	return MTV_S_OK;
    }
}

static mtv_result_t tdmd_demod_get_status(dab_demod_t* demod, dab_demod_status_t* status)
{
    tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);

    /* calculate signal strength according to SNR and BER */
    status->signal_strength = pthis->snr;

    return MTV_S_OK;
}

static mtv_result_t tdmb_demod_close(dab_demod_t* demod)
{
	tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);

	if (pthis->state != DAB_DEMOD_OPENED && pthis->state != DAB_DEMOD_TUNING) {
        return MTV_E_WRONG_STATE;
    }

    MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_CLOSE);

    {
        CONSTRUCT_LOCAL_PARAM(tdmb_turn_off_request_struct, req);
        send_tdmb_msg(MSG_ID_TDMB_TURN_OFF_REQUEST, req);
    }

	pthis->state = DAB_DEMOD_CLOSED;
	return MTV_S_OK;
}

/* T-DMB modulator message handlers */

static void tdmb_demod_on_turnon_confirm(tdmb_demod_t* pthis, tdmb_turn_on_confirm_struct* confirm)
{
    if (confirm->return_code != TDMB_SUCCESS)
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }
    else
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_OPENED);
    }
}

static void tdmb_demod_on_setband_confirm(tdmb_demod_t* pthis, tdmb_set_band_confirm_struct* confirm)
{
    if (confirm->return_code != TDMB_SUCCESS)
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }
    else
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_BAND_TUNED);
    }
}

static void tdmb_demod_notify_channels(tdmb_demod_t* pthis, TDMB_ENSEMBLEDB* ensemblelist)
{
    TDMB_ENSEMBLEDB* ensemble;

    for (ensemble = ensemblelist;
         ensemble != NULL;
         ensemble = ensemble->Next)
    {
        TDMB_SERVICEDB* service;
        dab_demod_ensemble_t demod_ensemble;

        demod_ensemble.id = ensemble->Id;
        demod_ensemble.band = tdmb_demod_from_device_band(ensemble->Band);
        demod_ensemble.freq = ensemble->Frequency;
        med_util_utf8_to_ucs2((kal_uint8*) demod_ensemble.name, sizeof(demod_ensemble.name), (kal_uint8*) ensemble->Label, sizeof(ensemble->Label));

        pthis->client->on_ensemble(pthis->client, &demod_ensemble);

        for (service = ensemble->Service;
             service != NULL;
             service = service->Next)
        {
            dab_demod_service_t demod_service;

            if (tdmb_fill_service_info(&demod_service, service) >= 0)
            {
                pthis->client->on_service(pthis->client, &demod_service);
            }
        }
    }
}

static void tdmb_demod_on_autoscan_confirm(tdmb_demod_t* pthis, tdmb_auto_scan_confirm_struct* confirm)
{
    if (confirm->return_code != TDMB_SUCCESS)
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }
    else
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_SCANNED);

        tdmb_demod_notify_channels(pthis, confirm->ensemblelist);

        /* send progress 100% */
        pthis->client->on_event(pthis->client, DAB_DEMOD_SCAN_PROGRESS, 100);

        pthis->ensembles = confirm->ensemblelist;
        pthis->state = DAB_DEMOD_OPENED;
    }
}

static void tdmb_demod_on_setfreqency_confirm(tdmb_demod_t* pthis, tdmb_set_frequency_confirm_struct* confirm)
{
    ASSERT(pthis->state == DAB_DEMOD_TUNING);

    if (confirm->return_code != TDMB_SUCCESS)
    {
        pthis->state = DAB_DEMOD_OPENED;

        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }
    else
    {
        kal_int32 i;

        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_FREQUENCY_TUNED);

        /* use the new ensemble list */
        pthis->ensembles = confirm->ensemblelist;

        for (i = 0; i < ARRAY_SIZE(pthis->active_services); i++)
        {
            if (pthis->active_services[i].db == NULL)
            {
                CONSTRUCT_LOCAL_PARAM(tdmb_select_service_request_struct, req);
                kal_uint32 service_id = pthis->active_services[i].id;
                TDMB_SERVICEDB* service_db = tdmb_find_service_db(pthis, service_id);

                req->service_id = service_id;
                req->subchannel_id = service_db->Channel->Id;
                send_tdmb_msg(MSG_ID_TDMB_SELECT_SERVICE_REQUEST, req);

                pthis->active_services[i].db = service_db;
            }
        }

        pthis->state = DAB_DEMOD_OPENED;
    }
}

static void tdmb_demod_on_selectservice_confirm(tdmb_demod_t* pthis, tdmb_select_service_confirm_struct* confirm)
{
    if (confirm->return_code != TDMB_SUCCESS)
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }
    else
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_SERVICE_STARTED);
    }
}

static void tdmb_demod_on_getsignal_confirm(tdmb_demod_t* pthis, tdmb_get_signal_confirm_struct* confirm)
{
    if (confirm->return_code != TDMB_SUCCESS)
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }

    pthis->snr = confirm->snr;
    pthis->ber = confirm->ber;
}

static void tdmb_demod_on_setidle_confirm(tdmb_demod_t* pthis, tdmb_set_idle_confirm_struct* confirm)
{
    if (confirm->return_code != TDMB_SUCCESS)
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }
    else
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_SERVICE_STOPPED);
    }
}

static void tdmb_demod_restart_active_services(tdmb_demod_t* pthis)
{
    dab_demod_t* demod = &pthis->itf;
    mtv_result_t ret;
    kal_int32 i;

    for (i = 0; i < ARRAY_SIZE(pthis->active_services); i++)
    {
        /* assume current service is affected and stop it immediately */
        if (pthis->active_services[i].db != NULL)
        {
            kal_uint32 service_id = pthis->active_services[i].db->Id;

            /* assume the ensemble DB has been updated and restart the service */
            ret = demod->stop_service(demod, service_id);
            ret = demod->start_service(demod, service_id);
            if (ret < 0) {
                pthis->client->on_event(pthis->client, DAB_DEMOD_SERVICE_ABORTED, service_id);
            }
        }
    }
}

static void tdmb_demod_abort_active_services(tdmb_demod_t* pthis)
{
    dab_demod_t* demod = &pthis->itf;
    kal_int32 i;

    for (i = 0; i < ARRAY_SIZE(pthis->active_services); i++)
    {
        if (pthis->active_services[i].db != NULL)
        {
            kal_uint32 service_id = pthis->active_services[i].db->Id;

            /* assume current service is affected and stop it immediately */
            demod->stop_service(demod, service_id);

            pthis->client->on_event(pthis->client, DAB_DEMOD_SERVICE_ABORTED, service_id);
        }
    }
}

static void tdmb_demod_on_mci_reconfig_indication(tdmb_demod_t* pthis, tdmb_mci_reconfig_indication_struct* ind)
{
    MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_RECONFIG, ind->return_code);

    switch (ind->return_code)
    {
    case TDMB_RCI_CHANGE_OTHER_SERVICE:
        /* do nothing */
        break;

    case TDMB_RCI_CHANGE_OTHER_CHANNEL:
        tdmb_demod_restart_active_services(pthis);
        break;

    case TDMB_RCI_TUNE_FAIL:
    case TDMB_RCI_CURRENT_SERVICE_NOT_EXIST:
    case TDMB_RCI_CURRENT_CHANNEL_NOT_EXIST:
    case TDMB_RCI_CURRENT_CHANNEL_TYPE_NOT_MATCH:
        tdmb_demod_abort_active_services(pthis);
        break;

    default:
        NOT_REACHED("Unhandled reconfiguration error code");
        break;
    }
}

static void tdmb_demod_on_get_ensemble_info_confirm(tdmb_demod_t* pthis, tdmb_get_ensemble_info_confirm_struct* confirm)
{
    if (confirm->return_code != TDMB_SUCCESS)
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_ERROR, confirm->return_code);
        pthis->client->on_event(pthis->client, DAB_DEMOD_ERROR, confirm->return_code);
    }
}

static void tdmb_demod_on_announcement_indication(tdmb_demod_t* pthis, tdmb_announcement_indication_struct* ind)
{
    MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_SERVICE_ANNOUNCEMENT);

    pthis->client->on_event(pthis->client, DAB_DEMOD_ANNOUNCEMENT, ind->service_id);
}

static void tdmb_demod_send_tdmb_data(tdmb_demod_t* pthis, media_mtv_tdmb_data_ind_struct* ind)
{
    TDMB_PacketStruct packet;
    kal_int32 i;

    UNUSED(ind);

    kal_take_mutex(g_mtv_transport_lock);

    while (tdmb_get_data(&packet))
    {
        MTV_TRACE(MTV_TRACE_GROUP_DEMOD, MTV_TRC_DEMOD_GET_DATA, packet.tdmb_buf_len);
        ASSERT(packet.tdmb_buf_len > 0);
        ASSERT(packet.tdmb_buf_ptr != NULL);

        for (i = 0; i < ARRAY_SIZE(pthis->active_services); i++)
        {
            TDMB_SERVICEDB* svc = pthis->active_services[i].db;

#ifdef __MTK_TARGET__
            if (svc != NULL)
#else
            if (svc != NULL &&
                svc->Channel->pSvcComp->TMId == packet.tmid &&
                svc->Channel->pSvcComp->SubCh_FIDCId == packet.subch_fidc_id)
#endif
            {
                DUMP_DATA(g_ts_dump, packet.tdmb_buf_ptr, packet.tdmb_buf_len)
                pthis->packet_count++;
                pthis->client->on_data(pthis->client, svc->Id, packet.tdmb_buf_ptr, packet.tdmb_buf_len);
                break;
            }
        }

        if (i >= ARRAY_SIZE(pthis->active_services)) {
            /* ignore data from unknown service */
        }

        tdmb_free_buffer(packet.tdmb_buf_ptr);
    }

    pthis->send_data_notification = KAL_TRUE;

    /* update signal strength periodically */
    if (pthis->packet_count % 128 == 0)
    {
        tdmb_demod_get_signal(pthis);
    }

    kal_give_mutex(g_mtv_transport_lock);
}

static void tdmb_demod_destroy(dab_demod_t* demod)
{
    tdmb_demod_t* pthis = PTHIS(demod, tdmb_demod_t, itf);

    med_free_ext_mem((void**)&pthis);
}

dab_demod_t* construct_tdmb_demod()
{
    tdmb_demod_t* pthis = med_alloc_ext_mem(sizeof(tdmb_demod_t));
    ASSERT(pthis != NULL);
    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->itf.open = tdmb_demod_open;
    pthis->itf.scan = tdmb_demod_scan;
    pthis->itf.stop_scan = tdmb_demod_stop_scan;
    pthis->itf.start_service = tdmb_demod_start_service;
    pthis->itf.get_service_info = tdmb_get_service_info;
    pthis->itf.stop_service = tdmb_demod_stop_service;
    pthis->itf.get_status = tdmd_demod_get_status;
    pthis->itf.close = tdmb_demod_close;
    pthis->itf.destroy = tdmb_demod_destroy;

    pthis->on_turnon_confirm = tdmb_demod_on_turnon_confirm;
    pthis->on_setband_confirm = tdmb_demod_on_setband_confirm;
    pthis->on_autoscan_confirm = tdmb_demod_on_autoscan_confirm;
    pthis->on_setfreqency_confirm = tdmb_demod_on_setfreqency_confirm;
    pthis->on_selectservice_confirm = tdmb_demod_on_selectservice_confirm;
    pthis->on_getsignal_confirm = tdmb_demod_on_getsignal_confirm;
    pthis->on_setidle_confirm = tdmb_demod_on_setidle_confirm;
    pthis->on_mci_reconfig_indication = tdmb_demod_on_mci_reconfig_indication;
    pthis->on_get_ensemble_info_confirm = tdmb_demod_on_get_ensemble_info_confirm;
    pthis->on_announcement_indication = tdmb_demod_on_announcement_indication;
    pthis->send_tdmb_data = tdmb_demod_send_tdmb_data;

	return &pthis->itf;
}

#endif /* !defined(_MTV_USE_TDMB_TS_DEMOD) */

#endif /* defined(__MED_MTV_MOD__) && defined(__TDMB_SUPPORT__) */
