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
 *   cyberlink_tdmb_demux.c
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
#include "cyberlink_tdmb_demux.h"
#include "CodecInterface.h"
#include "cyberlink_adaptation.h"

static void cyberlink_tdmb_demux_on_stream_data(void* param, CL_Packet* pkt)
{
	cyberlink_tdmb_demux_t* pthis = (cyberlink_tdmb_demux_t*) param;
	mtv_packet_t au;

    au.data = pkt->data;
    au.size = pkt->size;
	au.timestamp = pkt->pts;
	au.flags = MTV_PACKET_FROM_CL_TDMB_DEMUX;

	pthis->client->on_access_unit(pthis->client, pkt->stream_id, &au);
}

static void cyberlink_tdmb_demux_on_audio_stream(void* param, CL_StreamInfo* info, CL_Codec_User user)
{
	cyberlink_tdmb_demux_t* pthis = (cyberlink_tdmb_demux_t*) param;
    CL_AudioSpecificConfig* dsi = info->AudioDecoderSpecificInfo;
    tdmb_stream_info_t si;

    if (user != For_MTK_Codec) {
        return;
    }

    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_ON_AUDIO_STREAM);

    si.stream_id = info->stream_id;
    si.object_descriptor_id = info->ObjectDescriptorID;
    si.stream_type = MPEG4_STREAM_AUDIO;
    si.obj_type = MPEG4_OBJECT_TYPE_AUDIO_14496_3;

    switch (dsi->audioObjectType)
    {
    case 2:
        si.dec_config.codec = MTV_CODEC_AAC;
		break;

    case 22:
        si.dec_config.codec = MTV_CODEC_BSAC;
        ASSERT(dsi->numOfSubFrame >= 1);
		break;

    default:
        NOT_REACHED("Unhandled audio object type!");
        si.dec_config.codec = MTV_CODEC_NONE;
		break;
    }

    si.dec_config.timestamp_resolution = info->timeStampResolution;
    si.dec_config.private_init = (void*) info;

    si.dec_config.u.m4a.max_bitrate = 48000;
    si.dec_config.u.m4a.avg_bitrate = 32000;
    si.dec_config.u.m4a.buffer_size_db = 8000;
    si.dec_config.u.m4a.audio_object_type = dsi->audioObjectType;
	si.dec_config.u.m4a.sampling_frequency_index = dsi->samplingFrequencyIndex;
	si.dec_config.u.m4a.channel_configuration = dsi->channelConfiguration;
    si.dec_config.u.m4a.ep_config = dsi->epConfig;
    si.dec_config.u.m4a.num_of_sub_frame = dsi->numOfSubFrame;
    si.dec_config.u.m4a.layer_length = (kal_uint16) dsi->layer_length;

	pthis->client->on_stream(pthis->client, &si);
}

static void cyberlink_tdmb_demux_on_video_stream(void *param, CL_StreamInfo* info, CL_Codec_User user)
{
	cyberlink_tdmb_demux_t* pthis = (cyberlink_tdmb_demux_t*) param;
    CL_AVCDecoderSpecificInfo* dsi = info->VideoDecoderSpecificInfo;
    tdmb_stream_info_t si;

    if (user != For_MTK_Codec) {
        return;
    }

    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_ON_VIDEO_STREAM);

    si.stream_id = info->stream_id;
    si.object_descriptor_id = info->ObjectDescriptorID;
    si.stream_type = MPEG4_STREAM_VISUAL;
    si.obj_type = MPEG4_OBJECT_TYPE_VISUAL_14496_10;

    si.dec_config.codec = MTV_CODEC_H264;
    si.dec_config.timestamp_resolution = info->timeStampResolution;
    si.dec_config.private_init = (void*) info;

	ASSERT(dsi->numOfSequenceParameterSets > 0);
    si.dec_config.u.h264.sps_num = 1;
    si.dec_config.u.h264.sps_len[0] = dsi->sequenceParameterSetLength[0];
    ASSERT(dsi->sequenceParameterSetLength[0] <= MAX_SPS_LEN);
    kal_mem_cpy(si.dec_config.u.h264.sps[0], dsi->sequenceParameterSetNALUnit[0], dsi->sequenceParameterSetLength[0]);

	ASSERT(dsi->numOfPictureParameterSets > 0);
    si.dec_config.u.h264.pps_num = 1;
    si.dec_config.u.h264.pps_len[0] = dsi->pictureParameterSetLength[0];
    ASSERT(dsi->pictureParameterSetLength[0] <= MAX_PPS_LEN);
    kal_mem_cpy(si.dec_config.u.h264.pps[0], dsi->pictureParameterSetNALUnit[0], dsi->pictureParameterSetLength[0]);

	pthis->client->on_stream(pthis->client, &si);
}

static void cyberlink_tdmb_demux_on_status(void *param , CL_Status* s)
{
	cyberlink_tdmb_demux_t* pthis = (cyberlink_tdmb_demux_t*) param;
    mtv_result_t ret;

    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_ON_STATUS, *s);

    switch (*s)
    {
    case OD_PARSING_COMPLETION:
        /* notify the client the completion of parsing BIFS scene */
        pthis->state = TDMB_DEMUX_READY;
        ret = pthis->client->on_event(pthis->client, TDMB_DEMUX_ALL_STREAMS_FOUND);
        break;

    case FORMAT_CHANGE:
        break;

    case PACKET_DECODED:
        break;

    case END:
        break;

    case CL_ERROR:
        break;

    case CL_OK:
        break;

    case DISCONTINUITY:
        break;

    default:
        NOT_REACHED("Unhanlded demux event!");
        break;
    }
}

static mtv_result_t cyberlink_tdmb_demux_open(tdmb_demux_t* demux, tdmb_demux_client_t* client)
{
    cyberlink_tdmb_demux_t* pthis = PTHIS(demux, cyberlink_tdmb_demux_t, itf);
    CL_Status clstatus;

    if (pthis->state != TDMB_DEMUX_CLOSED) {
        return MTV_E_WRONG_STATE;
    }
    if (client == NULL) {
        return MTV_E_INVALID_PARAM;
    }

    pthis->demux = CL_TDMB_Demux_Creat();
    if (!pthis->demux)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_DEMUX_ERROR);
        return MTV_E_OUT_OF_MEMORY;
    }

    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_OPENING);
	clstatus = CL_TDMB_Demux_Register(pthis->demux, cyberlink_tdmb_demux_on_stream_data, cyberlink_tdmb_demux_on_audio_stream, cyberlink_tdmb_demux_on_video_stream, cyberlink_tdmb_demux_on_status, pthis);
    if (clstatus != CL_OK)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_DEMUX_ERROR);
        return MTV_E_FAIL;
    }
    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_OPENED);

    pthis->client = client;
    pthis->state = TDMB_DEMUX_OPENED;

	return MTV_S_OK;
}

static mtv_result_t cyberlink_tdmb_demux_send(tdmb_demux_t* demux, kal_uint8* packets, kal_uint32 size)
{
    cyberlink_tdmb_demux_t* pthis = PTHIS(demux, cyberlink_tdmb_demux_t, itf);
    CL_Status clstatus;

    if (pthis->state == TDMB_DEMUX_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    if (packets[0] != 0x47 || size < TS_PACKET_BYTES || size % TS_PACKET_BYTES != 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_DEMUX_INVALID_TS_PACKET);
        return MTV_E_FAIL;
    }

	clstatus = CL_TDMB_Demux_Send(pthis->demux, packets, size);
    if (clstatus != CL_OK)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_DEMUX_ERROR);
        return MTV_E_FAIL;
    }

	return MTV_S_OK;
}

static mtv_result_t cyberlink_tdmb_demux_close(tdmb_demux_t* demux)
{
    cyberlink_tdmb_demux_t* pthis = PTHIS(demux, cyberlink_tdmb_demux_t, itf);
    CL_Status clstatus;

    if (pthis->state == TDMB_DEMUX_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_CLOSING);
	clstatus = CL_TDMB_Demux_Destroy(pthis->demux);
    ASSERT(clstatus == CL_OK);
    MTV_TRACE(MTV_TRACE_GROUP_DEMUX, MTV_TRC_DEMUX_CLOSED);

    cyberlink_dump_mem_usage();

    pthis->state = TDMB_DEMUX_CLOSED;

	return MTV_S_OK;
}

static void cyberlink_tdmb_demux_destroy(tdmb_demux_t* demux)
{
    cyberlink_tdmb_demux_t* pthis = PTHIS(demux, cyberlink_tdmb_demux_t, itf);

    med_free_ext_mem((void**) &pthis);
}

tdmb_demux_t* construct_cyberlink_tdmb_demux()
{
    cyberlink_tdmb_demux_t* pthis = (cyberlink_tdmb_demux_t*) med_alloc_ext_mem(sizeof(cyberlink_tdmb_demux_t));
    ASSERT(pthis);
    kal_mem_set(pthis, 0, sizeof(*pthis));

	pthis->itf.open = cyberlink_tdmb_demux_open;
	pthis->itf.send = cyberlink_tdmb_demux_send;
	pthis->itf.close = cyberlink_tdmb_demux_close;
    pthis->itf.destroy = cyberlink_tdmb_demux_destroy;

	return &pthis->itf;
}

#endif /* defined(__MED_MTV_MOD__) && defined(__TDMB_SUPPORT__) */
