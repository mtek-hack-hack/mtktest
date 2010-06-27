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
 *   mtv_streaming_player.c
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
#include "med_trc.h"

#if defined(__MED_MTV_MOD__)

#if defined(__MTK_TARGET__)
#include "SST_sla.h"
#endif

#include "med_struct.h"		/* message struct */
#include "med_utility.h"

#include "mtv_streaming_player.h"

#ifdef __MTK_TARGET__
#if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
#include "aud_main.h"
#define _MTV_BT_A2DP
#endif
#endif /* __MTK_TARGET__ */

#define MIN_AUDIO_BUFFER_SECONDS    2

//#define _DUMP_MTV_AUDIO_BITSTREAM
#ifdef _DUMP_MTV_AUDIO_BITSTREAM
    typedef struct
    {
        kal_uint32 len;
        kal_uint8 data[512*1024];
    } data_dump_t;
    #define DECLARE_DUMP(_d) static data_dump_t _d;
    #define INIT_DUMP(_d) _d.len = 0;
    #define DUMP_DATA(_d, _p, _len) \
        do { \
            ASSERT(_d.len + _len <= ARRAY_SIZE(_d.data)); \
            kal_mem_cpy(_d.data + _d.len, _p, _len); \
            _d.len += _len; \
        } while (0);
#else
    #define DECLARE_DUMP(_d)
    #define INIT_DUMP(_d) do {;} while(0);
    #define DUMP_DATA(_d, _p, _len) do {;} while(0);
#endif

DECLARE_DUMP(g_audio_dump)

/* global variables */

static const kal_uint8 aac_silence_frame[9] = {
0x21, 0x00, 0x49, 0x90, 0x02, 0x19, 0x00, 0x23, 0x80};

static const kal_uint8 bsac_silence_frame_with_adts_header[18] = {
0xFF, 0xF1, 0x6C, 0x60, 0x02, 0x5F, 0xFC ,0x01, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* forward declaration */

static mtv_result_t mtv_streaming_player_stop_playing(mtv_player_t* player);

/* helper functions */

static const kal_uint32 mp4a_sampling_frequency_table[] =
{ 96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050, 16000, 12000, 11025, 8000 };

kal_uint32 mp4a_get_sample_rate_from_index(kal_uint32 index)
{
    ASSERT(index < ARRAY_SIZE(mp4a_sampling_frequency_table));
    return mp4a_sampling_frequency_table[index];
}

/* copied from mp4_parser_audio.c */
static void put_bits(unsigned char *in, unsigned int *bitcnt, int data, int data_length)
{
   int t,count;

   ASSERT(data_length>0 && data_length<=16);

   t = *bitcnt;

   if( (t & 0x7)== 0)
      in[t>>3] = 0;

   if( (t & 0x7) + data_length  <= 8)
      in[(t>>3)] |= (data << (8-((t&0x7) + data_length)));
   else {
      count = (t&7) + data_length;
      in[(t>>3)] |= (data >> (data_length - 8 + (t&7)));
      count -= 8;

      if(count > 8) {
         in[(t>>3)+1] = (unsigned char)((data >> (count-8))&0xFF);
         in[(t>>3)+2] = (unsigned char)((data << (16-count))&0xFF);
      } else {
         in[(t>>3)+1] = (unsigned char)((data << (8-count))&0xFF);
      }
   }
   *bitcnt += data_length;
}

void mtv_fill_adts_header(kal_uint8* h, mtv_m4a_dec_config_t* m4a, kal_uint32 payload_length)
{
    kal_uint32 bit_count = 0;

    /* adts_fixed_header */
    put_bits(h, &bit_count, 0xFFF, 12); // syncword
    put_bits(h, &bit_count, 0, 1);      // ID
    put_bits(h, &bit_count, 0, 2);      // Layer
    put_bits(h, &bit_count, 1, 1);      // Protection absent
    put_bits(h, &bit_count, 1, 2);      // Profile
    put_bits(h, &bit_count, m4a->sampling_frequency_index, 4); // sample_frequency_index
    put_bits(h, &bit_count, 0, 1);      // private_bit
    put_bits(h, &bit_count, m4a->channel_configuration, 3); // Channel_configuration
    put_bits(h, &bit_count, 1, 1);      // original_copy
    put_bits(h, &bit_count, 0, 1);      // Home

    /* adts_variable_header */
    put_bits(h, &bit_count, 0, 1);      // copy_identification_bit
    put_bits(h, &bit_count, 0, 1);      // copy_identification_byte
    put_bits(h, &bit_count, payload_length + LEN_ADTS_HEADER, 13); // length
    put_bits(h, &bit_count, 0x7FF, 11); // buffer_fullness
    put_bits(h, &bit_count, 0, 2);      // no_raw_data_blocks_in_frame

    ASSERT(bit_count == 56);
}

#ifdef __MTK_TARGET__

/* audio decoder */

static rtp_audio_codec_type mtv_get_rtp_audio_codec_type(mtv_dec_config_t* dec_config)
{
    if (dec_config->codec == MTV_CODEC_AAC)
    {
        return RTP_AUDIO_MPEG4_GENERIC_AAC;
    }
    else if (dec_config->codec == MTV_CODEC_BSAC)
    {
        return RTP_AUDIO_BSAC;
    }
    else if (dec_config->codec == MTV_CODEC_MUSICAM)
    {
        return RTP_AUDIO_MP2;
    }

    NOT_REACHED("Unhandled audio decoder?!");
    return RTP_AUDIO_NONE;
}

static kal_int32 mtv_get_audio_sample_rate(mtv_dec_config_t* dec_config)
{
    if (dec_config->codec == MTV_CODEC_AAC ||
        dec_config->codec == MTV_CODEC_BSAC)
    {
        return mp4a_get_sample_rate_from_index(dec_config->u.m4a.sampling_frequency_index);
    }
    else if (dec_config->codec == MTV_CODEC_MUSICAM)
    {
        return dec_config->u.musicam.sample_rate;
    }

    NOT_REACHED("Unhandled audio decoder?!");
    return 0;
}

static const kal_char hex_char[] =
{
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

static void mtv_fill_rtp_audio_cap(mtv_streaming_player_t* pthis, mtv_dec_config_t* dec_config, rtp_audio_codec_cap* audio_cap)
{
    kal_mem_set(audio_cap, 0, sizeof(*audio_cap));

    if (dec_config->codec == MTV_CODEC_AAC || dec_config->codec == MTV_CODEC_BSAC)
    {
        kal_uint32 bit_count;
        kal_uint8 mpeg4_audio_config[2];
        kal_int32 i;

        audio_cap->aac.streamType = MPEG4_STREAM_AUDIO;
        audio_cap->aac.profile_level_id = MOBILE_AUDIO_INTERNETWORKING_PROFILE_L4; /* A.1 in ETSI 102 428 */
        audio_cap->aac.mode = AAC_HBR;
        audio_cap->aac.object = dec_config->u.m4a.audio_object_type;

        audio_cap->aac.rate = dec_config->timestamp_resolution;
        audio_cap->aac.bitrate = dec_config->u.m4a.avg_bitrate;

        audio_cap->aac.uNumOfSubFrame = dec_config->u.m4a.num_of_sub_frame;
        audio_cap->aac.uLayerLength = dec_config->u.m4a.layer_length;

        audio_cap->aac.channel = dec_config->u.m4a.channel_configuration;
        audio_cap->aac.sample_rate = mp4a_get_sample_rate_from_index(dec_config->u.m4a.sampling_frequency_index);

        bit_count = 0;
        put_bits(mpeg4_audio_config, &bit_count, dec_config->u.m4a.audio_object_type, 5);
        put_bits(mpeg4_audio_config, &bit_count, dec_config->u.m4a.sampling_frequency_index, 4);
        put_bits(mpeg4_audio_config, &bit_count, dec_config->u.m4a.channel_configuration, 4);
        ASSERT(bit_count <= sizeof(mpeg4_audio_config) * 8);

        for (i = 0; i < ARRAY_SIZE(mpeg4_audio_config); i++)
        {
            pthis->m4a_config[2*i] = hex_char[mpeg4_audio_config[i] >> 4];
            pthis->m4a_config[2*i + 1] = hex_char[mpeg4_audio_config[i] & 0x0F];
        }
        pthis->m4a_config[2*i] = 0;

        audio_cap->aac.config = (kal_uint8*) pthis->m4a_config;
    }
    else if (dec_config->codec == MTV_CODEC_MUSICAM)
    {
        /* do nothing */
    }
    else
    {
        NOT_REACHED("Unexpected audio decoder?!");
    }
}

void mtv_l1_audio_decoding_callback(AudRTP_EVENT event, AudRTP_DL_HANDLE *handle, void *host_data)
{
    mtv_streaming_player_t* pthis = (mtv_streaming_player_t*) host_data;

    switch (event)
    {
    case AudRTP_EVENT_BUF_OVERFLOW:
        SLA_LABEL("AOF");
        break;

    case AudRTP_EVENT_PACKET_LOSS:
        SLA_LABEL("APL");
        break;

    case AudRTP_EVENT_MEDIA_ERROR:
        SLA_LABEL("AME");
        break;

    case AudRTP_EVENT_BUF_UNDERFLOW:
        SLA_LABEL("AUF");
        break;

    default:
        NOT_REACHED("Unhandled audio decoder event!");
        break;
    }

    mtv_streaming_player_stop_playing(&pthis->itf);

    /* After playing is stopped, the player will enter OPENED state and the player
       will be restarted if there are enough packets delivered. */
}

static mtv_result_t mtv_streaming_player_init_audio(mtv_streaming_player_t* pthis, mtv_dec_config_t* dec_config, media_config_audio_struct* audio_config)
{
    AudRTP_STATUS status;
    rtp_audio_codec_type codec_type;
    rtp_audio_codec_cap audio_cap;
    kal_uint32 audio_buf_size;
    AudRTP_DL_HANDLE* audio_h;

    codec_type = mtv_get_rtp_audio_codec_type(dec_config);

    audio_h = RTPAudio_OpenDLChannel(codec_type);
    ASSERT(audio_h != NULL);

    /* currently the following steps are necessary only for AAC */
    if (codec_type == RTP_AUDIO_MPEG4_GENERIC_AAC ||
        codec_type == RTP_AUDIO_BSAC ||
        codec_type == RTP_AUDIO_MP2)
    {
        kal_uint32 samples_per_frame;
        kal_uint32 audio_bitrate = 128 * 1000;

        status = audio_h->GetCodecCapability(audio_h, codec_type, &audio_cap);
        if (status != AudRTP_STATUS_SUCCESS)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ERROR, status);
            return MTV_DEC_E_AUDIO;
        }

        mtv_fill_rtp_audio_cap(pthis, dec_config, &audio_cap);

        status = audio_h->Config(audio_h, codec_type, &audio_cap, mtv_l1_audio_decoding_callback, pthis, 1);
        if (status != AudRTP_STATUS_SUCCESS)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ERROR, status);
            return MTV_DEC_E_AUDIO;
        }

        if (codec_type == RTP_AUDIO_MP2) {
            samples_per_frame = 1152;
        }
        else if (codec_type == RTP_AUDIO_BSAC) {
            samples_per_frame = 1024 * dec_config->u.m4a.num_of_sub_frame;
        }
        else {
            samples_per_frame = 1024;
        }

        pthis->min_buffered_packets += MIN_AUDIO_BUFFER_SECONDS * mtv_get_audio_sample_rate(dec_config) / samples_per_frame;

        pthis->audio_ts_stat.au_duration = dec_config->timestamp_resolution * samples_per_frame / mtv_get_audio_sample_rate(dec_config);
        pthis->audio_ts_stat.last_timestamp = 0;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        pthis->audio_ts_stat.size_to_duration_ratio = 0;
#endif
        audio_buf_size = (audio_bitrate * MIN_AUDIO_BUFFER_SECONDS * 2) / 8;
    }
    else
    {
        NOT_REACHED("Unsupported audio format!");
        return MTV_DEC_E_AUDIO;
    }

    ASSERT(pthis->audio_buf == NULL);
    pthis->audio_buf = (kal_uint8*) med_alloc_ext_mem(audio_buf_size);
    ASSERT(pthis->audio_buf != NULL);
    status = audio_h->SetBuffer(audio_h, pthis->audio_buf, audio_buf_size);
    if (status != AudRTP_STATUS_SUCCESS)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ERROR, status);
        med_free_ext_mem((void**)&pthis->audio_buf);
        return MTV_DEC_E_AUDIO;
    }

    INIT_DUMP(g_audio_dump)

    pthis->audio_h = audio_h;
    pthis->audio_dec_config = dec_config;
    return MTV_S_OK;
}

static void mtv_streaming_player_close_audio(mtv_streaming_player_t* pthis)
{
    if (pthis->audio_h)
    {
        AudRTP_STATUS status;

        status = pthis->audio_h->Close(pthis->audio_h);
        if (status != AudRTP_STATUS_SUCCESS) {
            MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ERROR, status);
        }

        pthis->audio_h = NULL;
    }

    med_free_ext_mem((void**)&pthis->audio_buf);
}


static void mtv_streaming_player_init_bt_a2dp(mtv_dec_config_t* dec_config)
{
#if defined(_MTV_BT_A2DP)
    switch (dec_config->codec)
    {
    case MTV_CODEC_BSAC:
        aud_bt_a2dp_open_codec(MEDIA_FORMAT_BSAC);
         break;
    case MTV_CODEC_AAC:
        aud_bt_a2dp_open_codec(MEDIA_FORMAT_AAC);
        break;
    case MTV_CODEC_MUSICAM:
        aud_bt_a2dp_open_codec(MEDIA_FORMAT_MUSICAM);
        break;
    default:
        NOT_REACHED("Unhandled audio decoder?!");
        break;
    }
#endif
}

static mtv_result_t mtv_streaming_player_start_audio(mtv_streaming_player_t* pthis)
{
    ASSERT(pthis->state == MTV_STREAMING_PLAYER_STATE_OPENED);

    if (pthis->audio_h)
    {
        AudRTP_STATUS status;

        mtv_streaming_player_init_bt_a2dp(pthis->audio_dec_config);

        status = pthis->audio_h->Start(pthis->audio_h, 0);
        if (status != AudRTP_STATUS_SUCCESS)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ERROR, status);
            mtv_streaming_player_close_audio(pthis);
            return MTV_DEC_E_AUDIO;
        }
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_streaming_player_stop_audio(mtv_streaming_player_t* pthis)
{
    /* don't try to stop decoder again when restart counting down */
    if (pthis->audio_h && pthis->state == MTV_STREAMING_PLAYER_STATE_STARTED)
    {
        AudRTP_STATUS status;

        status = pthis->audio_h->Stop(pthis->audio_h);
        if (status != AudRTP_STATUS_SUCCESS)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ERROR, status);
            return MTV_DEC_E_AUDIO;
        }
    }

    return MTV_S_OK;
}

/* video decoder */

static mtv_streaming_player_t* g_mtv_streaming_player;

static void mtv_l1_video_decoding_callback(VIDEO_RTP_EVENT event)
{
    mtv_streaming_player_t* pthis = g_mtv_streaming_player;

    /*
     * Note that if buffer overflow, buffer underflow, or any other error happened,
     * decoder will call video_rtp_callback with error code.
     */

    switch (event)
    {
    case VIDEO_RTP_EVENT_OVERFLOW:
    case VIDEO_RTP_EVENT_UNDERFLOW:
    case VIDEO_RTP_EVENT_PACKET_LOSS:

        mtv_streaming_player_stop_playing(&pthis->itf);
        break;

    case VIDEO_RTP_EVENT_RESOLUTION_ERR:

        /* it is a fatal error that requires user's attention */
        pthis->client->on_video_error(pthis->client, event);
        break;

    default:

        NOT_REACHED("Unhandled video decoder event!");
        break;
    }
}

typedef union
{
    video_rtp_mp4_cap mp4;
    video_rtp_h263_cap h263;
    video_rtp_h264_cap h264;

} video_rtp_cap;

static void mtv_fill_video_cap(mtv_dec_config_t* dec_config, video_rtp_cap* video_cap)
{
    if (dec_config->codec == MTV_CODEC_H264)
    {
        video_cap->h264.timescale = dec_config->timestamp_resolution;
        video_cap->h264.packetization_mode = H264_RTP_SINGLE_NALU_MODE;
        video_cap->h264.profile_level_id = (*(kal_uint32*) dec_config->u.h264.sps) & 0xFFFFFF;

        /* TODO: fill complete H.264 info */
    }
    else
    {
        NOT_REACHED("Unexpected video decoder?!");
    }
}

static void mtv_fill_image_data_path_config(mtv_streaming_player_t* pthis, MP4DEC_IMGPATH_STRUCT* image_data_path, media_config_video_struct* video_config)
{
    lcd_frame_update_struct* lcd_data = &pthis->lcd_data;

    image_data_path->lcd_data = lcd_data;

    image_data_path->lcd_buf_addr =
        (kal_uint32) video_config->image_buffer_p + video_config->display_offset_y * video_config->display_width * 2;

    image_data_path->disp_width             = video_config->display_width;
    image_data_path->disp_height            = video_config->display_height;
    image_data_path->video_display_offset_x = video_config->video_display_offset_x;
    image_data_path->video_display_offset_y = video_config->video_display_offset_y;
    image_data_path->force_lcd_hw_trigger   = video_config->force_lcd_hw_trigger;

#if MT6228_SERIES
#ifdef __MED_TVO_MOD__
    lcd_data->tv_output_width    = video_config->tv_output_width;
    lcd_data->tv_output_height   = video_config->tv_output_height;
    lcd_data->tv_output_offset_x = video_config->tv_output_offset_x;
    lcd_data->tv_output_offset_y = video_config->tv_output_offset_y;

    image_data_path->image_pitch_mode  = video_config->image_pitch_mode;
    image_data_path->image_data_format = video_config->image_data_format;
    image_data_path->image_pitch_bytes = video_config->image_pitch_bytes;

    image_data_path->tv_output                       = video_config->tv_output;
    image_data_path->tv_output_frame_buffer1_address = (kal_uint32) video_config->tv_output_buffer1_address;
    image_data_path->tv_output_frame_buffer2_address = (kal_uint32) video_config->tv_output_buffer2_address;
    image_data_path->tv_output_frame_buffer_size     = video_config->tv_output_buffer_size;
#endif /* __MED_TVO_MOD__ */
#endif /* MT6228_SERIES */

    lcd_data->module_id       = LCD_UPDATE_MODULE_MEDIA;
    lcd_data->lcd_id          = video_config->lcd_id;
    lcd_data->lcm_start_x     = video_config->lcd_start_x;
    lcd_data->lcm_start_y     = video_config->lcd_start_y;
    lcd_data->lcm_end_x       = video_config->lcd_end_x;
    lcd_data->lcm_end_y       = video_config->lcd_end_y;
    lcd_data->roi_offset_x    = video_config->roi_offset_x;
    lcd_data->roi_offset_y    = video_config->roi_offset_y;
    lcd_data->update_layer    = video_config->update_layer;
    lcd_data->hw_update_layer = video_config->hw_update_layer;
    lcd_data->fb_update_mode  = LCD_HW_TRIGGER_MODE;
    lcd_data->rotate_value    = (kal_uint8) video_config->lcd_rotate;
}

static video_rtp_codec_type mtv_get_rtp_video_codec_type(mtv_dec_config_t* dec_config)
{
    if (dec_config->codec == MTV_CODEC_H264)
    {
        return video_rtp_codec_h264;
    }
    else if (dec_config->codec == MTV_CODEC_MPEG4)
    {
        return video_rtp_codec_mp4;
    }
    else if (dec_config->codec == MTV_CODEC_VC1)
    {
        return video_rtp_codec_vc1;
    }

    NOT_REACHED("Unhandled video decoder?!");
    return video_rtp_codec_h264;
}

static mtv_result_t mtv_streaming_player_init_video(mtv_streaming_player_t* pthis, mtv_dec_config_t* dec_config, mtv_dec_config_t* adec_config, media_config_video_struct* video_config)
{
    video_rtp_cap video_cap;
    VIDEO_RTP_STATUS status;
    Video_Rtp_Handle_Struct* video_h;

    /* H.264 video is not ready yet */
    return MTV_DEC_E_VIDEO;

    ASSERT(pthis->vid_intmem == NULL);
    pthis->vid_intmem = med_alloc_int_mem(MAX_VID_DEC_INT_MEM_SIZE);
    ASSERT(pthis->vid_intmem != NULL);
    intmem_init(pthis->vid_intmem, MAX_VID_DEC_INT_MEM_SIZE);

    ASSERT(pthis->vid_extmem == NULL);
    pthis->vid_extmem = med_alloc_ext_mem(MAX_VID_DEC_EXT_MEM_SIZE);
    ASSERT(pthis->vid_extmem != NULL);
    extmem_init(pthis->vid_extmem, MAX_VID_DEC_EXT_MEM_SIZE);

    video_h = Video_Rtp_Get_Handle();
    ASSERT(video_h != NULL);

    status = video_h->SetActiveCodec(video_h, mtv_get_rtp_video_codec_type(dec_config));
    if (status != VIDEO_RTP_OK)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
        return MTV_DEC_E_VIDEO;
    }

    status = video_h->GetCapability(video_h, &video_cap);
    if (status != VIDEO_RTP_OK)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
        return MTV_DEC_E_VIDEO;
    }

    mtv_fill_video_cap(dec_config, &video_cap);

    g_mtv_streaming_player = pthis;

    status = video_h->Config(
        video_h,
        &video_cap,
        mtv_get_rtp_audio_codec_type(adec_config),
        mtv_get_audio_sample_rate(adec_config),
        mtv_l1_video_decoding_callback);
    if (status != VIDEO_RTP_OK)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
        return MTV_DEC_E_VIDEO;
    }

    mtv_fill_image_data_path_config(pthis, &pthis->image_data_path, video_config);

    pthis->video_h = video_h;

    /* TODO: use more accurate number */
    pthis->min_buffered_packets += 64;

    return MTV_S_OK;
}

static void mtv_streaming_player_close_video(mtv_streaming_player_t* pthis)
{
    if (pthis->video_h)
    {
        VIDEO_RTP_STATUS status;

        status = pthis->video_h->Close(pthis->video_h);
        if (status != VIDEO_RTP_OK) {
            MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
        }

        pthis->video_h = NULL;
    }

    intmem_deinit();
    med_free_int_mem(&pthis->vid_intmem);

    extmem_deinit();
    med_free_ext_mem(&pthis->vid_extmem);
}

static mtv_result_t mtv_streaming_player_start_video(mtv_streaming_player_t* pthis)
{
    ASSERT(pthis->state == MTV_STREAMING_PLAYER_STATE_OPENED);

    if (pthis->video_h)
    {
        VIDEO_RTP_STATUS status;

        status = pthis->video_h->ImagePathOpen(pthis->video_h, &pthis->image_data_path);
        if (status != VIDEO_RTP_OK)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
            mtv_streaming_player_close_video(pthis);
            return MTV_DEC_E_VIDEO;
        }

        visual_disable_sleep(); /* ? */

        status = pthis->video_h->Start(pthis->video_h, 0, mtv_l1_video_decoding_callback);
        if (status != VIDEO_RTP_OK)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
            mtv_streaming_player_close_video(pthis);
            return MTV_DEC_E_VIDEO;
        }
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_streaming_player_stop_video(mtv_streaming_player_t* pthis)
{
    /* don't try to stop decoder again when restart counting down */
    if (pthis->video_h && pthis->state == MTV_STREAMING_PLAYER_STATE_STARTED)
    {
        VIDEO_RTP_STATUS status;

        status = pthis->video_h->Stop(pthis->video_h);
        if (status != VIDEO_RTP_OK)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
            return MTV_DEC_E_VIDEO;
        }

        status = pthis->video_h->ImagePathClose(pthis->video_h);
        if (status != VIDEO_RTP_OK)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_VIDEO_ERROR, status);
            return MTV_DEC_E_VIDEO;
        }
    }

    return MTV_S_OK;
}

/* player */

static mtv_result_t mtv_streaming_player_start_playing(mtv_streaming_player_t* pthis)
{
    mtv_result_t ret;

    ret = mtv_streaming_player_start_video(pthis);
    if (ret < 0)
    {
        pthis->client->on_video_error(pthis->client, ret);
        return ret;
    }

    ret = mtv_streaming_player_start_audio(pthis);
    if (ret < 0)
    {
        pthis->client->on_audio_error(pthis->client, ret);
        return ret;
    }

    pthis->state = MTV_STREAMING_PLAYER_STATE_STARTED;

    return MTV_S_OK;
}

static mtv_result_t mtv_streaming_player_stop_playing(mtv_player_t* player)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);
    mtv_result_t ret;

    if (pthis->state != MTV_STREAMING_PLAYER_STATE_STARTED)
    {
        /* do nothing if the player is not started yet */
        return MTV_S_FALSE;
    }

    ret = mtv_streaming_player_stop_audio(pthis);

    ret = mtv_streaming_player_stop_video(pthis);

    pthis->state = MTV_STREAMING_PLAYER_STATE_OPENED;
    pthis->au_count = 0;

    return MTV_S_OK;
}

static mtv_result_t mtv_streaming_player_start(
    mtv_player_t* player,
    mtv_spi_service_info_t* info,
    media_config_audio_struct* audio_config,
    media_config_video_struct* video_config,
    mtv_player_client_t* client)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);
    mtv_spi_component_info_t* audio_comp = NULL;
    mtv_result_t ret = MTV_E_FAIL;
    kal_int32 i;

    ASSERT(pthis->state == MTV_STREAMING_PLAYER_STATE_CLOSED);

    /* reset minimum amount of buffered packets so that init_audio
       and init_video can increase them correctly. */
    pthis->min_buffered_packets = 0;

    /* initialize audio first */
    for (i = 0; i < ARRAY_SIZE(info->components); i++)
    {
        mtv_spi_component_info_t* comp = &info->components[i];

        if ((comp->type == MTV_SPI_COMPONENT_AUDIO) && ((comp->flags & MTV_SPI_COMPONENT_PRIMARY) != 0))
        {
            audio_comp = comp;
            ret = mtv_streaming_player_init_audio(pthis, &comp->dec_config, audio_config);
            break;
        }
    }

    if (audio_comp) /* do it only if audio component is available */
    {
        /* initialize video later */
        for (i = 0; i < ARRAY_SIZE(info->components); i++)
        {
            mtv_spi_component_info_t* comp = &info->components[i];

            if ((comp->type == MTV_SPI_COMPONENT_VIDEO) && ((comp->flags & MTV_SPI_COMPONENT_PRIMARY) != 0))
            {
                ret = mtv_streaming_player_init_video(pthis, &comp->dec_config, &audio_comp->dec_config, video_config);
                break;
            }
        }
    }

    if (!pthis->audio_h && !pthis->video_h) {
        return MTV_E_FAIL;
    }

    pthis->client = client;
    pthis->state = MTV_STREAMING_PLAYER_STATE_OPENED;
    pthis->au_count = 0;

    return MTV_S_OK;
}

/**
  * @return the number of lost packets
  */
static void mtv_streaming_player_check_timestamp(mtv_timestamp_stat_t* tstat, mtv_packet_t* au, mtv_packet_stat_t* pstat)
{
    pstat->au_loss = 0;
    pstat->au_count = 1;

    if (tstat->last_timestamp != 0)
    {
        kal_uint32 gap = au->timestamp - tstat->last_timestamp;
        if (gap >= 0x80000000)  // negative
        {
            mtv_prompt_trace(MOD_MTV,
                "Decreasing timestamp? last = %u, curr = %u",
                tstat->last_timestamp, au->timestamp);
        }
        else if (gap > tstat->au_duration)
        {
            kal_uint32 diff = gap - tstat->au_duration;

            /* +1 : to compensate the possible +1/-1 offset of AU duration */
            pstat->au_loss = (diff + 1) / tstat->au_duration;
            if (pstat->au_loss > 0)
            {
                if (gap > au->size * tstat->size_to_duration_ratio)
                {
                    mtv_prompt_trace(MOD_MTV,
                        "Abnormal timestamp interval: expected = %u, actual = %u, diff = %u",
                        tstat->au_duration, gap, diff);
                }
                else
                {
                    /*
                     * It may not be a real packet loss. it is possible that there are multiple
                     * AUs in one packet.
                     */
                    pstat->au_count += pstat->au_loss;
                    pstat->au_loss = 0;
                    mtv_prompt_trace(MOD_MTV, "There may be %u AUs in one packet!", pstat->au_count);
                }
            }
        }
        else /* gap <= tstat->au_duration */
        {
            /* do nothing */
        }
    }

    tstat->last_timestamp = au->timestamp;
}

static mtv_result_t mtv_streaming_player_deliver_adts_header(mtv_streaming_player_t* pthis, kal_uint32 au_size, kal_uint32 au_timestamp)
{
    AudRTP_STATUS status;

    ASSERT(pthis->audio_dec_config != NULL);

    mtv_fill_adts_header(pthis->adts_header, &pthis->audio_dec_config->u.m4a, au_size);

    DUMP_DATA(g_audio_dump, pthis->adts_header, sizeof(pthis->adts_header));
    status = pthis->audio_h->AddAccessUnit(pthis->audio_h, pthis->adts_header, sizeof(pthis->adts_header), au_timestamp);
    if (status != AudRTP_STATUS_SUCCESS) {
        return MTV_DEC_E_AUDIO;
    }

    return MTV_S_OK;
}

/* a typical BSAC frame is about 21.3ms */
#define MTV_MAX_AUDIO_CONCEALMENT 128

static mtv_result_t mtv_streaming_player_deliver_audio_concealment(mtv_streaming_player_t* pthis, kal_int32 packet_loss)
{
    kal_int32 i;
    kal_uint32 timestamp = pthis->audio_ts_stat.last_timestamp;

    /*
     * The number of packet loss concealment should be limited because large
     * timestamp gap probably means video packets are lost also. Therefore,
     * it is better to do re-synchonization than concealment.
     */
    for (i = 0; i < MTV_MAX_AUDIO_CONCEALMENT && i < packet_loss; i++)
    {
        timestamp += pthis->audio_ts_stat.au_duration;

        if (pthis->audio_dec_config->codec == MTV_CODEC_AAC)
        {
            mtv_prompt_trace(MOD_MTV, "[MTV][BE] Add one AAC silence frame");
            mtv_streaming_player_deliver_adts_header(pthis, sizeof(aac_silence_frame), timestamp);

            DUMP_DATA(g_audio_dump, aac_silence_frame, sizeof(aac_silence_frame));
            pthis->audio_h->AddAccessUnit(pthis->audio_h, (kal_uint8*) aac_silence_frame, sizeof(aac_silence_frame), timestamp);
        }
        else if (pthis->audio_dec_config->codec == MTV_CODEC_BSAC)
        {
            mtv_prompt_trace(MOD_MTV, "[MTV][BE] Add one BSAC silence frame");

            DUMP_DATA(g_audio_dump, bsac_silence_frame_with_adts_header, sizeof(bsac_silence_frame_with_adts_header));
            pthis->audio_h->AddAccessUnit(pthis->audio_h, (kal_uint8*) bsac_silence_frame_with_adts_header, sizeof(bsac_silence_frame_with_adts_header), timestamp);
        }
    }

    return MTV_S_OK;
}

static void mtv_streaming_player_deliver_audio_au(mtv_streaming_player_t* pthis, mtv_packet_t* au)
{
    AudRTP_STATUS status;
    mtv_packet_stat_t packet_stat;

    /* check time-stamp validility */
    mtv_streaming_player_check_timestamp(&pthis->audio_ts_stat, au, &packet_stat);
    if (packet_stat.au_loss > 0) {
        mtv_streaming_player_deliver_audio_concealment(pthis, packet_stat.au_loss);
    }

    /* MPEG-4 audio decoder requires ADTS header for each frame */
    if (pthis->audio_dec_config->codec == MTV_CODEC_AAC ||
        pthis->audio_dec_config->codec == MTV_CODEC_BSAC)
    {
        if ((au->flags & MTV_PACKET_WITH_ADTS_HEADER) == 0)
        {
            mtv_streaming_player_deliver_adts_header(pthis, au->size, au->timestamp);
        }
    }

    DUMP_DATA(g_audio_dump, au->data, au->size);
    status = pthis->audio_h->AddAccessUnit(pthis->audio_h, au->data, au->size, au->timestamp);
    if (status == AudRTP_STATUS_SUCCESS)
    {
        pthis->au_count++;
    }
}

static void mtv_streaming_player_deliver_video_au(mtv_streaming_player_t* pthis, mtv_packet_t* au)
{
#ifdef _ENABLE_MTV_VIDEO
    /* we need to get video frame rate first beforing checking time-stamp validility */
    mtv_streaming_player_check_timestamp(&pthis->video_ts_stat, au);
#endif

#ifdef _ENABLE_MTV_VIDEO
    VIDEO_RTP_STATUS status;
    ASSERT(pthis->video_h);
    status = pthis->video_h->PutPacket(pthis->video_h, au->data, au->size);
    if (status == VIDEO_RTP_OK)
    {
        pthis->au_count++;
    }
#endif
}

static mtv_result_t mtv_streaming_player_deliver_au(mtv_player_t* player, mtv_stream_type_t st, mtv_packet_t* au)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);
    mtv_result_t ret = MTV_S_OK;

    ASSERT(pthis->state != MTV_STREAMING_PLAYER_STATE_CLOSED);

    /* check audio handle because it may get closed if any error occurred */
    if (st == MTV_STREAM_AUDIO)
    {
        if (pthis->audio_h != NULL) {
            mtv_streaming_player_deliver_audio_au(pthis, au);
        }
    }
    else if (st == MTV_STREAM_VIDEO)
    {
        if (pthis->video_h != NULL) {
            mtv_streaming_player_deliver_video_au(pthis, au);
        }
    }
    else
    {
        NOT_REACHED("Unhandled stream type!");
        return MTV_E_INVALID_PARAM;
    }

    /* check whether enough data has been sent to decoder. if yes, start the decoder */
    if (pthis->state == MTV_STREAMING_PLAYER_STATE_OPENED &&
        pthis->au_count >= pthis->min_buffered_packets)
    {
        ret = mtv_streaming_player_start_playing(pthis);
    }

    return ret;
}

static mtv_result_t mtv_streaming_player_stop(mtv_player_t* player)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    ASSERT(pthis->state != MTV_STREAMING_PLAYER_STATE_CLOSED);

    mtv_streaming_player_stop_playing(player);

    mtv_streaming_player_close_audio(pthis);
    mtv_streaming_player_close_video(pthis);

    pthis->state = MTV_STREAMING_PLAYER_STATE_CLOSED;
    return MTV_S_OK;
}

static mtv_player_state_t mtv_streaming_player_get_state(mtv_player_t* player)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);
    return (pthis->state == MTV_STREAMING_PLAYER_STATE_CLOSED) ? MTV_PLAYER_STATE_STOPPED : MTV_PLAYER_STATE_STARTED;
}

static mtv_player_buffer_level_t mtv_streaming_player_get_buffer_level(mtv_player_t* player, mtv_stream_type_t st)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    if (st == MTV_STREAM_AUDIO)
    {
        kal_uint32 uCurBufDur;
        kal_uint32 uBufFreeSize;
        kal_uint32 uBufTotalSize;
        kal_uint32 uMinBufTotalDur;
        AudRTP_STATUS status;

        status = pthis->audio_h->GetBufferStatus(pthis->audio_h, &uCurBufDur, &uBufFreeSize, &uBufTotalSize, &uMinBufTotalDur);
        ASSERT(status == AudRTP_STATUS_SUCCESS);
        if (uBufFreeSize * 4 > uBufTotalSize) {
            return MTV_PLAYER_BUFFER_LEVEL_LOW;
        }
        else {
            return MTV_PLAYER_BUFFER_LEVEL_HIGH;
        }
    }
    else if (st == MTV_STREAM_VIDEO)
    {
#ifdef _ENABLE_MTV_VIDEO
        kal_uint32 percentage_used;
        kal_uint32 free_space;
        VIDEO_RTP_STATUS status;

        status = pthis->video_h->GetBufferStatus(pthis->video_h, &percentage_used, &free_space);
        ASSERT(status == VIDEO_RTP_OK);
        if (percentage_used < 50) {
            return MTV_PLAYER_BUFFER_LEVEL_LOW;
        }
        else {
            return MTV_PLAYER_BUFFER_LEVEL_HIGH;
        }
#else
        return MTV_PLAYER_BUFFER_LEVEL_HIGH;
#endif
    }

    NOT_REACHED("Unsupported stream type!");
    return MTV_PLAYER_BUFFER_LEVEL_FAMINE;
}

#else /* __MTK_TARGET__ */

static mtv_result_t mtv_streaming_player_start(
    mtv_player_t* player,
    mtv_spi_service_info_t* info,
    media_config_audio_struct* audio_config,
    media_config_video_struct* video_config,
    mtv_player_client_t* client)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    UNUSED(audio_config);
    UNUSED(video_config);
    UNUSED(info);

    pthis->client = client;
    pthis->state = MTV_STREAMING_PLAYER_STATE_OPENED;

    return MTV_S_OK;
}

static mtv_result_t mtv_streaming_player_deliver_au(mtv_player_t* player, mtv_stream_type_t st, mtv_packet_t* au)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    UNUSED(au);
    UNUSED(st);

    pthis->state = MTV_STREAMING_PLAYER_STATE_STARTED;
    return MTV_S_OK;
}

static mtv_result_t mtv_streaming_player_stop(mtv_player_t* player)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    pthis->state = MTV_STREAMING_PLAYER_STATE_CLOSED;
    return MTV_S_OK;
}

static mtv_player_state_t mtv_streaming_player_get_state(mtv_player_t* player)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    return (pthis->state == MTV_STREAMING_PLAYER_STATE_CLOSED) ? MTV_PLAYER_STATE_STOPPED : MTV_PLAYER_STATE_STARTED;
}

static mtv_player_buffer_level_t mtv_streaming_player_get_buffer_level(mtv_player_t* player, mtv_stream_type_t st)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    return MTV_PLAYER_BUFFER_LEVEL_HIGH;
}

#endif  /* __MTK_TARGET__ */

static void mtv_streaming_player_destroy(mtv_player_t* player)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    med_free_ext_mem((void**) &pthis);
}

static mtv_result_t mtv_streaming_player_get_control(mtv_player_t* player, mtv_control_t control_id, void** control)
{
    mtv_streaming_player_t* pthis = PTHIS(player, mtv_streaming_player_t, itf);

    if (control_id == MTV_CONTROL_VIDEO)
    {
        *control = &pthis->video_ctrl;
        return MTV_S_OK;
    }
    else if (control_id == MTV_CONTROL_VOLUME)
    {
        *control = &pthis->volume_ctrl;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t mtv_streaming_player_set_visible(mtv_control_video_t* control, kal_bool visible)
{
	UNUSED(control);
    UNUSED(visible);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_get_visible(mtv_control_video_t* control, kal_bool* visible)
{
	UNUSED(control);
    UNUSED(visible);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_set_brightness(mtv_control_video_t* control, kal_int32 brightness)
{
	UNUSED(control);
    UNUSED(brightness);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_get_brightness(mtv_control_video_t* control, kal_int32* brightness)
{
	UNUSED(control);
    UNUSED(brightness);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_set_contrast(mtv_control_video_t* control, kal_int32 contrast)
{
	UNUSED(control);
    UNUSED(contrast);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_get_contrast(mtv_control_video_t* control, kal_int32* contrast)
{
	UNUSED(control);
    UNUSED(contrast);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_set_gamma(mtv_control_video_t* control, kal_int32 gamma)
{
	UNUSED(control);
    UNUSED(gamma);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_get_gamma(mtv_control_video_t* control, kal_int32* gamma)
{
	UNUSED(control);
    UNUSED(gamma);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_set_mute(mtv_control_volume_t* control, kal_bool mute)
{
	UNUSED(control);
    UNUSED(mute);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_get_mute(mtv_control_volume_t* control, kal_bool* mute)
{
	UNUSED(control);
    UNUSED(mute);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_set_level(mtv_control_volume_t* control, kal_int32 level)
{
	UNUSED(control);
    UNUSED(level);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_streaming_player_get_level(mtv_control_volume_t* control, kal_int32* level)
{
	UNUSED(control);
    UNUSED(level);
    return MTV_E_NOT_IMPLEMENTED;
}

mtv_player_t* construct_mtv_streaming_player()
{
    mtv_streaming_player_t* pthis = (mtv_streaming_player_t*) med_alloc_ext_mem(sizeof(mtv_streaming_player_t));
    ASSERT(pthis != NULL);

    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->itf.start = mtv_streaming_player_start;
    pthis->itf.get_control = mtv_streaming_player_get_control;
    pthis->itf.deliver_au = mtv_streaming_player_deliver_au;
    pthis->itf.get_state = mtv_streaming_player_get_state;
    pthis->itf.get_buffer_level = mtv_streaming_player_get_buffer_level;
    pthis->itf.stop = mtv_streaming_player_stop;
    pthis->itf.destroy = mtv_streaming_player_destroy;

    pthis->video_ctrl.set_visible = mtv_streaming_player_set_visible;
    pthis->video_ctrl.get_visible = mtv_streaming_player_get_visible;
    pthis->video_ctrl.set_brightness = mtv_streaming_player_set_brightness;
    pthis->video_ctrl.get_brightness = mtv_streaming_player_get_brightness;
    pthis->video_ctrl.set_contrast = mtv_streaming_player_set_contrast;
    pthis->video_ctrl.get_contrast = mtv_streaming_player_get_contrast;
    pthis->video_ctrl.set_gamma = mtv_streaming_player_set_gamma;
    pthis->video_ctrl.get_gamma = mtv_streaming_player_get_gamma;

    pthis->volume_ctrl.set_mute = mtv_streaming_player_set_mute;
    pthis->volume_ctrl.get_mute = mtv_streaming_player_get_mute;
    pthis->volume_ctrl.set_level = mtv_streaming_player_set_level;
    pthis->volume_ctrl.get_level = mtv_streaming_player_get_level;

    return &pthis->itf;
}

#endif /* defined(__MED_MTV_MOD__) */

