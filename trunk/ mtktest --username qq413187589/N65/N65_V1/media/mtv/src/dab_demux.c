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
 *   dab_demux.c
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

#include "dab_demux.h"
#include "PAD_ParserIO.h"
#include "DLS_ParserIO.h"
#include "cyberlink_adaptation.h"

#ifndef __MTK_TARGET__
#include "CodecInterface.h"
#endif

#define AUDIO_SAMPLES_PER_FRAME 1152

static void dab_demux_deliver_dynamic_label(dab_demux_t* pthis, kal_uint8* label, kal_uint32 len, kal_uint32 charset)
{
    mtv_packet_t packet;

    switch (charset)
    {
    case 0x0: /* TODO: complete EBU Latin based repertoire */
    case 0x1: /* TODO: EBU Latin based common core, Cyrilllic, Greek */
    case 0x2: /* TODO: EBU Latin based core, Arabic, Hebrew, Cyrillic and Greek */
    case 0x3: /* TODO: ISO Latin Alphabet No 2 */
    case 0xf: /* ISO 10646-1 using UTF-8 transformation format */
        med_util_utf8_to_ucs2((kal_uint8*) pthis->dynamic_label, sizeof(pthis->dynamic_label), label, len);
        break;
    }

    packet.data = (kal_uint8*) pthis->dynamic_label;
    packet.size = kal_wstrlen(pthis->dynamic_label) * sizeof(kal_wchar);
    packet.timestamp = 0;
    packet.flags = 0;
    pthis->client->on_pad(pthis->client, TDMB_PAD_DYNAMIC_LABEL, &packet);

}

static kal_int32 dab_demux_on_dls_data(void* param, void* dls_parser)
{
    dab_demux_t* pthis = (dab_demux_t*) param;
	kal_uint8* dls_data = NULL;
	kal_int32 dls_data_len = 0;
    kal_uint8 charset;

	CL_get_DLS_Data(dls_parser, &dls_data, &dls_data_len);
    ASSERT(dls_data != NULL && dls_data_len > 0);
    CL_get_DLS_Charset(dls_parser, &charset);

#if defined(_MTV_DEBUG)
    dls_data[dls_data_len] = 0;
    mtv_prompt_trace(MOD_MTV, "DLS: '%s', len = %d, charset = %d", dls_data, dls_data_len, charset);
#endif

    dab_demux_deliver_dynamic_label(pthis, dls_data, dls_data_len, charset);

	return 0;
}

static kal_int32 dab_demux_on_pad_data(void* param, void* pad_parser)
{
    dab_demux_t* pthis = (dab_demux_t*) param;
	enum XPADAppTy app_type;

    UNUSED(pthis);

	CL_get_PAD_AppTy(pad_parser, &app_type);
	if (app_type == CL_DLS)
	{
		if (CL_Parse_DLS(pthis->dls_parser, pad_parser) > 0)
        {
			return 1;
		}
	}

	return 0;
}

static mtv_result_t dab_demux_open(tdmb_demux_t* demux, tdmb_demux_client_t* client)
{
    dab_demux_t* pthis = PTHIS(demux, dab_demux_t, itf);

    if (pthis->state != TDMB_DEMUX_CLOSED) {
        return MTV_E_WRONG_STATE;
    }
    if (client == NULL) {
        return MTV_E_INVALID_PARAM;
    }

    pthis->state = TDMB_DEMUX_OPENED;
    pthis->client = client;
    pthis->frame_count = 0;

    /* create PAD parser */
    pthis->pad_parser = CL_PAD_Parse_Create();
    CL_PAD_Parse_Register(pthis->pad_parser, dab_demux_on_pad_data, pthis);

    /* create DLS parser */
    pthis->dls_parser = CL_Parse_DLS_Create();
    CL_Parse_DLS_Register(pthis->dls_parser, dab_demux_on_dls_data, pthis);

	return MTV_S_OK;
}

typedef struct
{
    kal_uint32
        syncword1 : 8,
		protection_bit : 1,
		layer : 2,
		id : 1,
		syncword2: 4,
		bitrate_index : 4,
		sampling_frequency : 2,
		padding_bit : 1,
		private_bit : 1,
		mode: 2,
		mode_extension: 2,
		copyright: 1,
		orignal_copy: 1,
		emphasis: 2;
} musicam_frame_header;

typedef struct
{
    kal_uint32
        l_minus_1_data : 6,
        type: 2,
        Z : 1,
        CI : 1,
        l_data : 6;
} fpad_t;

#ifdef WIN32
#define TRACE_PAD(app_ty, data, len) printf("PAD: app_ty = %d, len = %d\n", app_ty, len)
#else
#define TRACE_PAD(app_ty, data, len) mtv_prompt_trace(MOD_MTV, "PAD: app_ty = %d, len = %d", app_ty, len);
#endif

static void dispatch_pad_data(kal_uint32 app_ty, kal_uint8* data, kal_uint32 len)
{
	switch (app_ty)
	{
	case 0: /* End marker */
		break;
	case 1: /* MOT X-PAD data group length, see EN 301 234 [20] */
		TRACE_PAD(app_ty, data, len);
		break;
	case 2: /* Dynamic label segment, start of X-PAD data group */
	case 3: /* Dynamic label segment, continuation of X-PAD data group */
		TRACE_PAD(app_ty, data, len);
        {
#ifdef WIN32
            kal_uint32 len = (data[0] & 0xf) + 1;
            data[2 + len] = 0;  /* overwrite CRC with null terminator */
            printf("DLS: %s\n", data + 2);
#endif
        }
		break;
	case 4: /* ITTS, start of X-PAD data group, see bibliography */
	case 5: /* ITTS, continuation of X-PAD data group, see bibliography */
		TRACE_PAD(app_ty, data, len);
		break;
	case 6: /* In-house information, start of X-PAD data group */
	case 7: /* In-house information, continuation of X-PAD data group */
		TRACE_PAD(app_ty, data, len);
		break;
	case 8: /* Closed user-group packet channel, start of X-PAD data group */
	case 9: /* Closed user-group packet channel, continuation of X-PAD data group */
		TRACE_PAD(app_ty, data, len);
		break;
	case 10: /* Table of contents, start of X-PAD data group */
	case 11: /* Table of contents, continuation of X-PAD data group */
		TRACE_PAD(app_ty, data, len);
		break;
	case 12: /* MOT, start of X-PAD data group, see EN 301 234 [20] */
	case 13: /* MOT, continuation of X-PAD data group, see EN 301 234 [20] */
		TRACE_PAD(app_ty, data, len);
		break;
	case 14: /* MOT, start of CA messages, see EN 301 234 [20] */
	case 15: /* MOT, continuation of CA messages, see EN 301 234 [20] */
		TRACE_PAD(app_ty, data, len);
		break;
	case 23: /* TDC, see TS 101 759 [24] */
		TRACE_PAD(app_ty, data, len);
		break;
	case 32: /* Closed user-group stream channel, start of X-PAD data group */
	case 33: /* Closed user-group stream channel, continuation of X-PAD data group */
		TRACE_PAD(app_ty, data, len);
		break;
	}
}

static kal_uint8* reverse_byte_array(kal_uint8* p, kal_uint32 len)
{
    kal_uint8* head = p;
    kal_uint8* tail = head + len;
    kal_uint8 temp;

    while (head < --tail)
    {
        temp = *tail;
        *tail = *head;
        *head++ = temp;
    }

    return p;
}

static void dab_demux_check_pad_data(kal_uint8* frame, kal_uint32 size, musicam_frame_header* header)
{
    fpad_t* fpad = (fpad_t*)(frame + size - 2);

    if (fpad->l_data != 0)
    {
        mtv_prompt_trace(MOD_MTV, "PAD: DRC = %u", fpad->l_data);
    }

	if (fpad->type == 0)
	{
		kal_uint32 xpad_ind = fpad->l_minus_1_data >> 4;
		kal_uint32 byte_l_ind = fpad->l_minus_1_data & 0x0F;

        UNUSED(byte_l_ind);

		if (xpad_ind == 0)
		{
			/* no X-PAD */
		}
		else if (xpad_ind == 3)
		{
			/* reserved for future use. */
            mtv_prompt_trace(MOD_MTV, "PAD: invalid X-PAD ind!");
		}
        else
        {
            kal_uint32 crc_bytes = (header->id == 1) ? 4 : /* 2 or 4 bytes of CRC */ 2;
            kal_uint8* xpad_ptr = frame + size - 2 - crc_bytes;

            if (xpad_ind == 1) /* short X-PAD */
            {
                static kal_uint32 app_ty;
                kal_uint32 subfield_len;

   			    if (fpad->CI == 0)
                {
                    /* app_ty is the same as previous one */
                    subfield_len = 4;
                }
                else
			    {
                    app_ty = *(xpad_ptr - 1);
                    subfield_len = 3;
                }

                dispatch_pad_data(app_ty, reverse_byte_array(xpad_ptr - 4, subfield_len), subfield_len);
            }
            else if (xpad_ind == 2) /* variable size X-PAD */
            {
                static const kal_uint8 var_size_xpad_len[] = {4, 6, 8, 12, 16, 24, 32, 48};
                kal_uint32 subfield_len[4] = {0};
                kal_uint32 app_ty[4] = {0};
                kal_uint32 i;
                kal_uint8* p = xpad_ptr;

                /* iterate the CI list */
                for (i = 0; xpad_ptr - p < 4 ; i++)
                {
                    subfield_len[i] = var_size_xpad_len[*--p >> 5];
                    app_ty[i] = *p & 0x1f;
                    if (app_ty[i] == 0) {
                        break;
                    }

                    if (app_ty[i] == 31) {
                        app_ty[i] = *--p + 31;
                    }
                }

                /* iterate each subfield */
                for (i = 0; app_ty[i] != 0 && i < ARRAY_SIZE(app_ty); i++)
                {
                    p -= subfield_len[i];
                    dispatch_pad_data(app_ty[i], reverse_byte_array(p, subfield_len[i]), subfield_len[i]);
                }
            }
		}
	}
	else if (fpad->type == 2)
	{
		kal_uint32 fpad_type_ext = fpad->l_minus_1_data >> 4;
		if (fpad_type_ext == 0)
		{
			kal_uint32 ih_command = fpad->l_minus_1_data & 0x0F;

            UNUSED(ih_command);
		}
		else if (fpad_type_ext == 1)
		{
			kal_uint32 ms_flag = (fpad->l_minus_1_data & 0x0c) >> 2;
			kal_uint32 rfa = (fpad->l_minus_1_data & 0x02) >> 1;
			kal_uint32 origin = fpad->l_minus_1_data & 0x01;

            mtv_prompt_trace(MOD_MTV, "PAD: ms_flag = %u, rfa = %u, origin = %u", ms_flag, rfa, origin);
		}
		else
		{
			kal_uint32 serial_command = fpad->l_minus_1_data & 0x0F;

            UNUSED(serial_command);
		}
	}
	else
	{
        mtv_prompt_trace(MOD_MTV, "PAD: invalid F-PAD type!?");
	}
}

static mtv_result_t dab_demux_send(tdmb_demux_t* demux, kal_uint8* packets, kal_uint32 size)
{
    dab_demux_t* pthis = PTHIS(demux, dab_demux_t, itf);
    musicam_frame_header* header = (musicam_frame_header*) packets;
    mtv_result_t ret = MTV_S_OK;
    kal_bool lsf;           /* low sampling frequency */
    kal_bool frame_sync;    /* to detect whether it is even or odd subframe in case of LSF */

    if (pthis->state == TDMB_DEMUX_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

	ASSERT(size >= 4);
    frame_sync = (header->syncword1 == 0xFF && header->syncword2 == 0xF);
    lsf = (header->id == 0);

    if (pthis->state == TDMB_DEMUX_OPENED && frame_sync)
    {
        tdmb_stream_info_t si;
#ifndef __MTK_TARGET__
        CL_StreamInfo cl_si;

        kal_mem_set(&cl_si, 0, sizeof(cl_si));
        cl_si.codec_type = CL_AUDIO_STREAM;
        cl_si.codec_id = CODEC_MP2;
#endif
        /* get audio decoder information from the first packet. */
        si.stream_type = MPEG4_STREAM_AUDIO;
        si.obj_type = MPEG4_OBJECT_TYPE_AUDIO_DAB;
        si.stream_id = 0;
        si.object_descriptor_id = 0;
        si.dec_config.u.musicam.bits_per_sample = 16;
        si.dec_config.u.musicam.channels = (kal_uint16)((header->mode == 3) ? 1 : 2);
        si.dec_config.u.musicam.sample_rate = lsf ? 24000 : 48000;
        si.dec_config.codec = MTV_CODEC_MUSICAM;
        si.dec_config.timestamp_resolution = si.dec_config.u.musicam.sample_rate;
#ifdef __MTK_TARGET__
        si.dec_config.private_init = NULL;
#else
        si.dec_config.private_init = &cl_si;
#endif
        pthis->client->on_stream(pthis->client, &si);

        pthis->state = TDMB_DEMUX_READY;
        ret = pthis->client->on_event(pthis->client, TDMB_DEMUX_ALL_STREAMS_FOUND);
    }

    if (ret >= 0 && pthis->state == TDMB_DEMUX_READY)
    {
        mtv_packet_t packet;

        if (frame_sync) {
            pthis->frame_count++;
        }

		packet.data = packets;
		packet.size = size;
		packet.timestamp = pthis->frame_count * AUDIO_SAMPLES_PER_FRAME -
            (frame_sync ? AUDIO_SAMPLES_PER_FRAME : AUDIO_SAMPLES_PER_FRAME/2);
		packet.flags = 0;
		pthis->client->on_access_unit(pthis->client, 0, &packet);

        CL_Parse_PAD(pthis->pad_parser, packets, size);
    }

	return MTV_S_OK;
}

static mtv_result_t dab_demux_close(tdmb_demux_t* demux)
{
    dab_demux_t* pthis = PTHIS(demux, dab_demux_t, itf);

    if (pthis->state == TDMB_DEMUX_CLOSED) {
        return MTV_E_WRONG_STATE;
    }

    CL_Parse_PAD_Destory(pthis->pad_parser);
    CL_Parse_DLS_Destroy(pthis->dls_parser);

    cyberlink_dump_mem_usage();

    pthis->state = TDMB_DEMUX_CLOSED;

	return MTV_S_OK;
}

static void dab_demux_destroy(tdmb_demux_t* demux)
{
    dab_demux_t* pthis = PTHIS(demux, dab_demux_t, itf);

    med_free_ext_mem((void**) &pthis);
}

tdmb_demux_t* construct_dab_demux()
{
    dab_demux_t* pthis = (dab_demux_t*) med_alloc_ext_mem(sizeof(dab_demux_t));
    ASSERT(pthis);

	pthis->itf.open = dab_demux_open;
	pthis->itf.send = dab_demux_send;
	pthis->itf.close = dab_demux_close;
    pthis->itf.destroy = dab_demux_destroy;

    pthis->state = TDMB_DEMUX_CLOSED;
    pthis->client = NULL;

	return &pthis->itf;
}

#endif /* defined(__MED_MTV_MOD__) && defined(__TDMB_SUPPORT__) */
