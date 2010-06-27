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
 *   tdmb_ts_demod.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "med_global.h"

#if defined(__MED_MTV_MOD__) && defined(_MTV_USE_TDMB_TS_DEMOD)

#include "tdmb_ts_demod.h"
#include "med_utility.h"

#include "stack_timer.h"
#include "fat_fs.h"

static tdmb_ts_demod_t* g_dab_demod;

extern stack_timer_struct g_mtv_transport_timer;

static mtv_result_t tdmb_ts_demod_open(dab_demod_t* demod, dab_demod_client_t* client)
{
	tdmb_ts_demod_t* pthis = PTHIS(demod, tdmb_ts_demod_t, itf);

    if (pthis->state == DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }
	if (client == NULL) {
		return MTV_E_INVALID_PARAM;
	}

    pthis->num_services = 0;
    kal_mem_set(pthis->services, 0, sizeof(pthis->services));

	pthis->client = client;
	pthis->state = DAB_DEMOD_OPENED;

	return MTV_S_OK;
}

static kal_bool on_found_ts_file(void* param, kal_wchar* filename)
{
    tdmb_ts_demod_t* pthis = (tdmb_ts_demod_t*) param;
    kal_int32 i;
    dab_demod_service_t* service = NULL;

    static dab_demod_component_t components[] =
    {
        {100},
        {101}
    };

    if (pthis->num_services >= ARRAY_SIZE(pthis->services)) {
        return KAL_FALSE;
    }

    ASSERT(pthis->services[pthis->num_services] == NULL);
    pthis->services[pthis->num_services] = service = (dab_demod_service_t*) med_alloc_ext_mem(sizeof(*service));

    service->id = pthis->num_services++;
    kal_wstrncpy(service->name, filename, ARRAY_SIZE(service->name));
    service->transport = DAB_DEMOD_STREAM_MODE_DATA;
    service->where = service->id + 100;
    service->app_type = DAB_APPLICATION_DMB;
    service->app_data = NULL;
    service->app_data_size = 0;
    service->ca_flag = 0;
    service->number = service->id + 1;

	pthis->client->on_service(pthis->client, service);

    for (i = 0; i < ARRAY_SIZE(components); i++)
    {
        pthis->client->on_component(pthis->client, &components[i]);
    }

    return KAL_TRUE;    /* continue the searching */
}

static mtv_result_t tdmb_ts_demod_scan(dab_demod_t* demod, kal_int32 band)
{
	tdmb_ts_demod_t* pthis = PTHIS(demod, tdmb_ts_demod_t, itf);
    kal_uint32 i;
    static dab_demod_ensemble_t ensemble =
    {
        1, 0, 0, L"T-DMB Ensemble"
    };

	UNUSED(band);

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    pthis->state = DAB_DEMOD_SCANNING;

    for (i = 0; i < pthis->num_services; i++) {
        med_free_ext_mem((void**)&pthis->services[i]);
    }
    pthis->num_services = 0;

	pthis->client->on_status(pthis->client, DAB_DEMOD_SCAN_PROGRESS, 0);

    pthis->client->on_ensemble(pthis->client, &ensemble);

    mtv_process_files(L"C:\\", L"*.ts", on_found_ts_file, pthis);

    pthis->client->on_status(pthis->client, DAB_DEMOD_SCAN_PROGRESS, 100);

    pthis->state = DAB_DEMOD_OPENED;

	return MTV_S_OK;
}

/* use a global packet buffer temporarily */
static kal_uint8 g_dab_packet_buffer[188*188];

void tdmb_ts_send_data()
{
    tdmb_ts_demod_t* pthis = g_dab_demod;
    kal_int32 ret;
    kal_uint32 bytes = 0;

    kal_take_mutex(g_mtv_transport_lock);

    ASSERT(pthis->local_ts != 0);

    ret = FS_Read((FS_HANDLE) pthis->local_ts, g_dab_packet_buffer, ARRAY_SIZE(g_dab_packet_buffer), &bytes);
    if (bytes > 0)
    {
        pthis->client->on_data(pthis->client, pthis->active_service, g_dab_packet_buffer, ARRAY_SIZE(g_dab_packet_buffer));

        /* start the timer again for next read */
        stack_start_timer(&g_mtv_transport_timer, 0, 10);
    }
    else
    {
        pthis->client->on_status(pthis->client, DAB_DEMOD_SERVICE_ABORTED, pthis->active_service);
    }

    kal_give_mutex(g_mtv_transport_lock);
}

static mtv_result_t tdmb_ts_demod_start_service(dab_demod_t* demod, kal_uint32 service_id)
{
	tdmb_ts_demod_t* pthis = PTHIS(demod, tdmb_ts_demod_t, itf);

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    ASSERT(service_id < ARRAY_SIZE(pthis->services));

    pthis->local_ts = (kal_uint32) FS_Open(pthis->services[service_id]->name, FS_READ_ONLY);
    if (pthis->local_ts == 0) {
        return MTV_E_FAIL;
    }

    pthis->active_service = service_id;
    stack_start_timer(&g_mtv_transport_timer, 0, 10);

	return MTV_S_OK;
}

static mtv_result_t telechips_dab_get_service_info(dab_demod_t* demod, kal_uint32 service_id, dab_demod_service_t* info)
{
	tdmb_ts_demod_t* pthis = PTHIS(demod, tdmb_ts_demod_t, itf);

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    ASSERT(service_id < ARRAY_SIZE(pthis->services));

    *info = *pthis->services[service_id];
    return MTV_S_OK;
}

static mtv_result_t tdmb_ts_demod_stop_service(dab_demod_t* demod, kal_uint32 service_id)
{
	tdmb_ts_demod_t* pthis = PTHIS(demod, tdmb_ts_demod_t, itf);

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    ASSERT(service_id == pthis->active_service);

    stack_stop_timer(&g_mtv_transport_timer);

	if (pthis->local_ts != 0)
	{
        FS_Close((FS_HANDLE) pthis->local_ts);
   		pthis->local_ts = 0;
	}

	return MTV_S_OK;
}

static mtv_result_t tdmb_ts_demod_close(dab_demod_t* demod)
{
	tdmb_ts_demod_t* pthis = PTHIS(demod, tdmb_ts_demod_t, itf);
    kal_int32 i;

	if (pthis->state != DAB_DEMOD_OPENED) {
        return MTV_E_WRONG_STATE;
    }

    for (i = 0; i < pthis->num_services; i++) {
        med_free_ext_mem((void**)&pthis->services[i]);
    }
    pthis->num_services = 0;

	pthis->state = DAB_DEMOD_CLOSED;
	return MTV_S_OK;
}

static void tdmb_ts_demod_destroy(dab_demod_t* demod)
{
	tdmb_ts_demod_t* pthis = PTHIS(demod, tdmb_ts_demod_t, itf);

    med_free_ext_mem((void**)&pthis);
}

dab_demod_t* construct_tdmb_ts_demod()
{
    tdmb_ts_demod_t* pthis = med_alloc_ext_mem(sizeof(tdmb_ts_demod_t));
    ASSERT(pthis != NULL);
    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->itf.open = tdmb_ts_demod_open;
    pthis->itf.scan = tdmb_ts_demod_scan;
    pthis->itf.start_service = tdmb_ts_demod_start_service;
    pthis->itf.get_service_info = telechips_dab_get_service_info;
    pthis->itf.stop_service = tdmb_ts_demod_stop_service;
    pthis->itf.close = tdmb_ts_demod_close;
    pthis->itf.destroy = tdmb_ts_demod_destroy;

	pthis->state = DAB_DEMOD_CLOSED;
	pthis->client = NULL;

    g_dab_demod = pthis;

	return &pthis->itf;
}

#endif /* defined(__MED_MTV_MOD__) && defined(_MTV_USE_TDMB_TS_DEMOD) */

