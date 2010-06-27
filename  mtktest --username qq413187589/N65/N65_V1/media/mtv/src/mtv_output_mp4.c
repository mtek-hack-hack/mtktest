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
 *   mtv_output_mp4.c
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

#if defined(__MED_MTV_MOD__)

#include "med_utility.h"
#include "mtv_output_mp4.h"
#include "mtv_buffer_engine.h"

#include "fat_fs.h"
#include <setjmp.h>

typedef struct
{
    volatile kal_bool* aborted;
    jmp_buf abort_jmpbuf;

    kal_int32 errors;
    kal_int32 last_fs_error;
    cached_io_t mp4_cio;

    mtv_sample_stream_t* ss;
    mtv_sample_index_t* si;
    kal_int32 num_streams;

    kal_uint32 mdat_offset;
    kal_int32 current_track;    /* current track index */

    kal_int32 saved_pos;        /* to support backward overwritten */

} mp4_output_context_t;

static void mp4_seek(mp4_output_context_t* ctx, kal_uint32 pos)
{
    cached_io_seek(&ctx->mp4_cio, pos);
}

static kal_uint32 mp4_tell(mp4_output_context_t* ctx)
{
    return cached_io_tell(&ctx->mp4_cio);
}

static void mp4_save_pos(mp4_output_context_t* ctx)
{
    ctx->saved_pos = mp4_tell(ctx);
}

static void mp4_toggle_saved_pos(mp4_output_context_t* ctx)
{
    kal_int32 pos = mp4_tell(ctx);

    mp4_seek(ctx, ctx->saved_pos);
    ctx->saved_pos = pos;
}

static void mp4_write(mp4_output_context_t* ctx, void* buf, kal_uint32 size)
{
    kal_int32 ret;

    if (ctx->errors > 0) {
        return; /* don't write if any error has happened */
    }

    ret = cached_io_write(&ctx->mp4_cio, buf, size);
    if (ret < 0)
    {
        ctx->last_fs_error = ret;
        ++ctx->errors;
    }
}

static void mp4_write_byte(mp4_output_context_t* ctx, kal_uint32 value)
{
    mp4_write(ctx, &value, 1);
}

static void mp4_write_be16(mp4_output_context_t* ctx, kal_uint32 value)
{
    kal_uint32 be = ((value & 0x000000ff) << 8) + ((value & 0x0000ff00) >> 8);

    mp4_write(ctx, &be, 2);
}

static void mp4_write_be32(mp4_output_context_t* ctx, kal_uint32 value)
{
    kal_uint32 be = ((value & 0x000000ff) << 24) +
                    ((value & 0x0000ff00) << 8) +
                    ((value & 0x00ff0000) >> 8) +
                    ((value & 0xff000000) >> 24);

    mp4_write(ctx, &be, 4);
}

static void mp4_write_be64(mp4_output_context_t* ctx, kal_uint64 value)
{
    mp4_write_be32(ctx, (kal_uint32)(value >> 32));
    mp4_write_be32(ctx, (kal_uint32)(value & 0xffffffff));
}

static void mp4_write_type(mp4_output_context_t* ctx, kal_char* type)
{
    mp4_write(ctx, type, 4);
}

static void mp4_write_string(mp4_output_context_t* ctx, kal_char* str)
{
    kal_uint32 len = (kal_uint32) kal_dchar_strlen(str);

    mp4_write(ctx, &len, 1);
    mp4_write(ctx, str, len);
}

typedef struct
{
    kal_int32 pos;

} mp4_box_context_t;

static void mp4_begin_box(mp4_output_context_t* ctx, mp4_box_context_t* box, kal_char* type)
{
    box->pos = mp4_tell(ctx);

    mp4_write_be32(ctx, 0);
    mp4_write_type(ctx, type);
}

static void mp4_begin_full_box(mp4_output_context_t* ctx, mp4_box_context_t* box, kal_char* type, kal_uint32 version_flags)
{
    mp4_begin_box(ctx, box, type);
    mp4_write_be32(ctx, version_flags);
}

static void mp4_end_box(mp4_output_context_t* ctx, mp4_box_context_t* box)
{
    kal_uint32 pos = mp4_tell(ctx);

    mp4_seek(ctx, box->pos);
    mp4_write_be32(ctx, pos - box->pos);
    mp4_seek(ctx, pos);
}

/* MP4 boxes */

static kal_uint32 mp4_get_track_duration(mtv_sample_index_t* si)
{
    kal_uint32 duration = si->get_duration(si);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return duration;
}

static kal_uint32 mp4_get_track_timescale(mtv_sample_index_t* si)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return si->info.dec_config.timestamp_resolution;
}

static void mp4_write_tkhd(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "tkhd", 0x07);

    mp4_write_be32(ctx, 0);     /* creation time */
    mp4_write_be32(ctx, 0);     /* modification time */

    mp4_write_be32(ctx, ctx->current_track + 1);   /* track ID */
    mp4_write_be32(ctx, 0);                 /* reserved */
    mp4_write_be32(ctx, mp4_get_track_duration(si));      /* duration */

    mp4_write_be32(ctx, 0);     /* reserved */
    mp4_write_be32(ctx, 0);     /* reserved */
    mp4_write_be32(ctx, 0);     /* reserved (Layer & Alternate group) */

    if (si->info.type == MTV_STREAM_AUDIO) {
        mp4_write_be16(ctx, 0x0100);    /* reserved (preferred volume) 1.0 = normal */
    }
    else {
        mp4_write_be16(ctx, 0);
    }
    mp4_write_be16(ctx, 0);         /* reserved */

    /* Matrix structure */
    mp4_write_be32(ctx, 0x00010000);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x00010000);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x40000000);

    if (si->info.type == MTV_STREAM_VIDEO)
    {
        mp4_write_be32(ctx, si->info.format.video.width * 0x10000);
        mp4_write_be32(ctx, si->info.format.video.height * 0x10000);
    }
    else
    {
        mp4_write_be32(ctx, 0);
        mp4_write_be32(ctx, 0);
    }

    mp4_end_box(ctx, &box);
}

static void mp4_write_mdhd(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "mdhd", 0);

    mp4_write_be32(ctx, 0);     /* creation time */
    mp4_write_be32(ctx, 0);     /* modification time */

    mp4_write_be32(ctx, mp4_get_track_timescale(si));   /* timescale */
    mp4_write_be32(ctx, mp4_get_track_duration(si));    /* duration */

    mp4_write_be16(ctx, 0);     /* language */
    mp4_write_be16(ctx, 0);     /* reserved */

    mp4_end_box(ctx, &box);
}

static void mp4_write_hdlr(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    char* hdlr;
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "hdlr", 0);

    if (si->info.type == MTV_STREAM_AUDIO) {
        hdlr = "soun";
    }
    else if (si->info.type == MTV_STREAM_VIDEO) {
        hdlr = "vide";
    }
    else {
        NOT_REACHED("Unhandled stream type?!");
		hdlr = "\0\0\0\0";
    }

    mp4_write_be32(ctx, 0);     /* handler */
    mp4_write_type(ctx, hdlr);  /* handler type */
    mp4_write_be32(ctx ,0);     /* reserved */
    mp4_write_be32(ctx ,0);     /* reserved */
    mp4_write_be32(ctx ,0);     /* reserved */
    mp4_write_string(ctx, "helper"); /* handler description */

    mp4_end_box(ctx, &box);
}

static void mp4_write_vmhd(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;
	UNUSED(si);

    mp4_begin_full_box(ctx, &box, "vmhd", 0x01);

    mp4_write_be64(ctx, 0);    /* graphicsmode + opcolor */

    mp4_end_box(ctx, &box);
}

static void mp4_write_smhd(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;
	UNUSED(si);

    mp4_begin_full_box(ctx, &box, "smhd", 0);

    mp4_write_be16(ctx, 0); /* balance */
    mp4_write_be16(ctx, 0); /* reserved */

    mp4_end_box(ctx, &box);
}

static void mp4_write_dref(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;
    mp4_box_context_t box_url;
	UNUSED(si);

    mp4_begin_full_box(ctx, &box, "dref", 0);

    mp4_write_be32(ctx, 1);     /* entry count */

    mp4_begin_full_box(ctx, &box_url, "url ", 1);
    mp4_end_box(ctx, &box_url);

    mp4_end_box(ctx, &box);
}

static void mp4_write_dinf(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "dinf");

    mp4_write_dref(ctx, si);

    mp4_end_box(ctx, &box);
}

static void mp4_write_esds(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;
    kal_uint32 dec_specific_info_len;
    kal_uint32 dec_specific_info_flags; /* frameLengthFlag, dependsOnCoreCoder, extensionFlag */
    kal_int32 sampling_frequency_index;
    mtv_m4a_dec_config_t* m4a_dec_config = &si->info.dec_config.u.m4a;

	switch (si->info.dec_config.codec)
	{
    case MTV_CODEC_BSAC:

        dec_specific_info_len = 7;
        dec_specific_info_flags = 0x01;
		break;

    case MTV_CODEC_AAC:

        dec_specific_info_len = 6;
        dec_specific_info_flags = 0x00;
		break;

    default:

        NOT_REACHED("Unhandled audio codec type?!");
		return;
    }

    mp4_begin_full_box(ctx, &box, "esds", 0);

    mp4_write_byte(ctx, 0x03);  /* ES_Descriptor */
    mp4_write_byte(ctx, 3 + 15 + dec_specific_info_len + 3);  /* descriptor size */

    mp4_write_be16(ctx, ctx->current_track + 1);     /* ES_ID */
    mp4_write_byte(ctx, 0);     /* flags (stream dependence, URL, OCR stream) + priority */

    mp4_write_byte(ctx, 0x04);  /* DecoderConfigDescriptor */
    mp4_write_byte(ctx, (15 - 2) + dec_specific_info_len);  /* descriptor size */
    mp4_write_byte(ctx, 0x40);  /* object type indication */
    mp4_write_byte(ctx, 0x05 << 2 | 0x01);  /* stream type + upstream + reserved */
    mp4_write_byte(ctx, m4a_dec_config->buffer_size_db >> 16);       /* buffer size DB, 1st part */
    mp4_write_be16(ctx, m4a_dec_config->buffer_size_db & 0xffff);    /* buffer size DB, 2nd part */
    mp4_write_be32(ctx, m4a_dec_config->max_bitrate);    /* max bitrate */
    mp4_write_be32(ctx, m4a_dec_config->avg_bitrate);    /* avg bitrate */

    mp4_write_byte(ctx, 0x05);  /* DecSpecificInfo */
    mp4_write_byte(ctx, dec_specific_info_len - 2);   /* descriptor size */

    sampling_frequency_index = m4a_dec_config->sampling_frequency_index;

    ASSERT(si->info.format.audio.channels == 1 || si->info.format.audio.channels == 2);
    mp4_write_byte(ctx, (m4a_dec_config->audio_object_type << 3) | (sampling_frequency_index >> 1));
    mp4_write_byte(ctx, (sampling_frequency_index << 7) |
                        (m4a_dec_config->channel_configuration << 3) | /* channelConfiguration */
                        dec_specific_info_flags);

    if (si->info.dec_config.codec == MTV_CODEC_BSAC)
    {
        mp4_write_be16(ctx, ((kal_uint32) m4a_dec_config->num_of_sub_frame) << 11 | m4a_dec_config->layer_length);
        ASSERT(m4a_dec_config->ep_config == 0);
        mp4_write_byte(ctx, m4a_dec_config->ep_config); /* extensionFlag3 + epConfig */
    }
    else if (si->info.dec_config.codec == MTV_CODEC_AAC)
    {
        mp4_write_be16(ctx, 0); /* syncExtensionType */
    }

    mp4_write_byte(ctx, 0x06);  /* SLConfigDescriptor */
    mp4_write_byte(ctx, 0x01);  /* descriptor size */
    mp4_write_byte(ctx, 0x00);  /* predefined */

    mp4_end_box(ctx, &box);
}

static void mp4_write_stsd_audio(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box_entry;

    if (si->info.dec_config.codec == MTV_CODEC_BSAC ||
        si->info.dec_config.codec == MTV_CODEC_AAC)
    {
        mp4_begin_full_box(ctx, &box_entry, "mp4a", 0);

        mp4_write_be16(ctx, 0);  /* reserved */
        mp4_write_be16(ctx, 1);  /* data reference index */

        mp4_write_be16(ctx, 0);  /* version */
        mp4_write_be16(ctx, 0);  /* revision level */
        mp4_write_be32(ctx, 0);  /* reserved */

        mp4_write_be16(ctx, si->info.format.audio.channels); /* number of channels */
        mp4_write_be16(ctx, si->info.format.audio.bits_per_sample); /* sample size */

        mp4_write_be16(ctx, 0);  /* pre_defined */
        mp4_write_be16(ctx, 0);  /* reserved */
        mp4_write_be16(ctx, si->info.format.audio.sample_rate);
        mp4_write_be16(ctx, 0);  /* reserved */

        mp4_write_esds(ctx, si);

        mp4_end_box(ctx, &box_entry);
    }
    else
    {
        NOT_REACHED("Unhandled audio codec type?!");
    }
}

static void mp4_write_stsd_video(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    kal_int32 i;
    mp4_box_context_t box_entry;

    if (si->info.dec_config.codec == MTV_CODEC_H264)
    {
        mtv_h264_dec_config_t* h264_dec_config = &si->info.dec_config.u.h264;
        kal_int8 compressor_name[32];

        mp4_begin_full_box(ctx, &box_entry, "avc1", 0);

        mp4_write_be16(ctx, 0);  /* reserved */
        mp4_write_be16(ctx, 1);  /* data reference index */

        mp4_write_be16(ctx, 0);  /* codec stream version */
        mp4_write_be16(ctx, 0);  /* codec stream revision */

        mp4_write_be32(ctx, 0);  /* reserved */
        mp4_write_be32(ctx, 0);  /* reserved */
        mp4_write_be32(ctx, 0);  /* reserved */

        mp4_write_be16(ctx, si->info.format.video.width); /* video width */
        mp4_write_be16(ctx, si->info.format.video.height); /* video height */
        mp4_write_be32(ctx, 0x00480000); /* horizontal resolution 72dpi */
        mp4_write_be32(ctx, 0x00480000); /* vertical resolution 72dpi */
        mp4_write_be32(ctx, 0); /* data size (= 0) */
        mp4_write_be16(ctx, 1); /* frame count (= 1) */

        kal_mem_set(compressor_name, 0, ARRAY_SIZE(compressor_name));
        mp4_write(ctx, compressor_name, ARRAY_SIZE(compressor_name));

        mp4_write_be16(ctx, 0x18);      /* depth */
        mp4_write_be16(ctx, 0xffff);    /* color table ID */

        {
            mp4_box_context_t box_avcC;

            mp4_begin_box(ctx, &box_avcC, "avcC");

			ASSERT(h264_dec_config->sps_num > 0);

            mp4_write_byte(ctx, 1);        /* version */
            mp4_write_byte(ctx, h264_dec_config->sps[0][1]);   /* profile */
            mp4_write_byte(ctx, h264_dec_config->sps[0][2]);   /* profile compat */
            mp4_write_byte(ctx, h264_dec_config->sps[0][3]);   /* level */
            mp4_write_byte(ctx, 0xff);     /* 6 bits reserved (111111) + 2 bits nal length size - 1 (11) */
            mp4_write_byte(ctx, 0xe0 | h264_dec_config->sps_num);  /* 3 bits reserved (111) + 5 bits number of sps */

            for (i = 0; i < h264_dec_config->sps_num; i++)
            {
                mp4_write_be16(ctx, h264_dec_config->sps_len[i]);
                mp4_write(ctx, h264_dec_config->sps[i], h264_dec_config->sps_len[i]);
            }

            ASSERT(h264_dec_config->pps_num > 0);
            mp4_write_byte(ctx, h264_dec_config->pps_num); /* number of pps */
            for (i = 0; i < h264_dec_config->pps_num; i++)
            {
                mp4_write_be16(ctx, h264_dec_config->pps_len[i]);
                mp4_write(ctx, h264_dec_config->pps[i], h264_dec_config->pps_len[i]);
            }

            mp4_end_box(ctx, &box_avcC);
        }

        mp4_end_box(ctx, &box_entry);
    }
    else
    {
        NOT_REACHED("Unhandled video codec type?!");
    }

}

static void mp4_write_stsd(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "stsd", 0);

    mp4_write_be32(ctx, 1);     /* entry count */

    if (si->info.type == MTV_STREAM_AUDIO)
    {
        mp4_write_stsd_audio(ctx, si);
    }
    else if (si->info.type == MTV_STREAM_VIDEO)
    {
        mp4_write_stsd_video(ctx, si);
    }
    else {
        NOT_REACHED("Unhandled stream type?!");
    }

    mp4_end_box(ctx, &box);
}

typedef struct
{
    kal_uint32 sample_count;
    kal_uint32 sample_delta;

} mp4_stts_entry;

static void mp4_write_stts(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    kal_uint32 stts_entry_count = 0;
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "stts", 0);

    mp4_save_pos(ctx);

    mp4_write_be32(ctx, stts_entry_count); /* entry count */
	{
		kal_uint32 entry_count = si->get_entry_count(si);
        kal_uint32 prev, curr = 0;
        kal_uint32 delta;
		kal_uint32 i;

        mtv_sample_index_entry_t entry[2];
        mp4_stts_entry stts_entry = {0};

        si->move_to_head(si);

        si->peek_entry(si, &entry[curr++]);
		si->move_to_next_entry(si);
        for (i = 1; i <= entry_count; i++)
        {
            if (*ctx->aborted) {
                longjmp(ctx->abort_jmpbuf, MTV_E_ABORTED);
            }

            if (i != entry_count)
            {
                si->peek_entry(si, &entry[curr]);
				si->move_to_next_entry(si);

				prev = (curr + 1) & 0x1;

                if (entry[curr].timestamp > entry[prev].timestamp) {
                    delta = entry[curr].timestamp - entry[prev].timestamp;
                }
                else
                {
                    /* invalid decreasing timestamp is found! */
                    delta = 0;
                }
				curr = prev;
            }
            else
            {
                /*
                 * The last entry. We cannot know its duration without the next one.
                 * Assume the delta is the same as previous one.
                 */
            }

            if (stts_entry.sample_count == 0) /* an empty entry */
            {
                stts_entry.sample_count++;
                stts_entry.sample_delta = delta;
            }
            else if (delta == stts_entry.sample_delta) /* the same delta */
            {
                stts_entry.sample_count++;
            }
            else /* a new delta value is found */
            {
                mp4_write_be32(ctx, stts_entry.sample_count);  /* sample count */
                mp4_write_be32(ctx, stts_entry.sample_delta);  /* sample delta */
                stts_entry_count++;

                stts_entry.sample_delta = delta;
                stts_entry.sample_count = 1;
            }
        }

        mp4_write_be32(ctx, stts_entry.sample_count);  /* sample count */
        mp4_write_be32(ctx, stts_entry.sample_delta);  /* sample delta */
        stts_entry_count++;
	}

    mp4_toggle_saved_pos(ctx);
    mp4_write_be32(ctx, stts_entry_count);
    mp4_toggle_saved_pos(ctx);

    mp4_end_box(ctx, &box);
}

static void mp4_write_stss(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    kal_uint32 i, stss_entry_count = 0;
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "stss", 0);

    mp4_save_pos(ctx);
    mp4_write_be32(ctx, stss_entry_count);
    {
        kal_uint32 entry_count = si->get_entry_count(si);
        mtv_sample_index_entry_t entry;

        si->move_to_head(si);
        for (i = 0; i < entry_count; i++)
        {
            if (*ctx->aborted) {
                longjmp(ctx->abort_jmpbuf, MTV_E_ABORTED);
            }

            si->peek_entry(si, &entry);
            si->move_to_next_entry(si);

            if ((entry.flags & MTV_PACKET_WITH_RANDOM_ACCESS_POINT) != 0)
            {
                mp4_write_be32(ctx, i + 1);
                stss_entry_count++;
            }
        }
    }
    mp4_toggle_saved_pos(ctx);
    mp4_write_be32(ctx, stss_entry_count);
    mp4_toggle_saved_pos(ctx);

    mp4_end_box(ctx, &box);
}

static void mp4_write_stsc(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;
	UNUSED(si);

    mp4_begin_full_box(ctx, &box, "stsc", 0);

    mp4_write_be32(ctx, 1); /* entry count */
    mp4_write_be32(ctx, 1); /* first chunk */
    mp4_write_be32(ctx, 1); /* samples per chunk */
    mp4_write_be32(ctx, 1); /* samples description index */

    mp4_end_box(ctx, &box);
}

static void mp4_write_stsz(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mtv_sample_index_entry_t entry;
    kal_int32 i, sample_count = si->get_entry_count(si);
    mp4_box_context_t box;
    kal_uint32 size;

    mp4_begin_full_box(ctx, &box, "stsz", 0);

    mp4_write_be32(ctx, 0); /* sample size */
    mp4_write_be32(ctx, sample_count); /* sample count */

    si->move_to_head(si);
    for (i = 0; i < sample_count; i++)
    {
        if (*ctx->aborted) {
            longjmp(ctx->abort_jmpbuf, MTV_E_ABORTED);
        }

        si->peek_entry(si, &entry);
        size = entry.size;

        /* Skip ADTS header */
        if ((entry.flags & MTV_PACKET_WITH_ADTS_HEADER) != 0) {
            size -= LEN_ADTS_HEADER;
        }

        mp4_write_be32(ctx, size);
        si->move_to_next_entry(si);
    }

    mp4_end_box(ctx, &box);
}

static void mp4_write_stco(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mtv_sample_index_entry_t entry;
    kal_int32 i, entry_count = si->get_entry_count(si);
    kal_uint32 offset;
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "stco", 0);

    mp4_write_be32(ctx, entry_count); /* entry count */
    si->move_to_head(si);
    for (i = 0; i < entry_count; i++)
    {
        if (*ctx->aborted) {
            longjmp(ctx->abort_jmpbuf, MTV_E_ABORTED);
        }

        si->peek_entry(si, &entry);
        offset = entry.pos;

        /* Skip ADTS header */
        if ((entry.flags & MTV_PACKET_WITH_ADTS_HEADER) != 0) {
            offset += LEN_ADTS_HEADER;
        }

        mp4_write_be32(ctx, ctx->mdat_offset + offset); /* chunk offset */
        si->move_to_next_entry(si);
    }

    mp4_end_box(ctx, &box);
}

static void mp4_write_stbl(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "stbl");

    mp4_write_stsd(ctx, si);
    mp4_write_stts(ctx, si);

    if (si->info.type == MTV_STREAM_VIDEO)
    {
        mp4_write_stss(ctx, si);
    }

    mp4_write_stsc(ctx, si);
    mp4_write_stsz(ctx, si);
    mp4_write_stco(ctx, si);

    mp4_end_box(ctx, &box);
}

static void mp4_write_minf(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "minf");

    if (si->info.type == MTV_STREAM_AUDIO) {
        mp4_write_smhd(ctx, si);
    }
    else if (si->info.type == MTV_STREAM_VIDEO) {
        mp4_write_vmhd(ctx, si);
    }
    else {
        NOT_REACHED("Unhandled stream type?!");
    }

    mp4_write_dinf(ctx, si);
    mp4_write_stbl(ctx, si);

    mp4_end_box(ctx, &box);
}

static void mp4_write_mdia(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "mdia");

    mp4_write_mdhd(ctx, si);
    mp4_write_hdlr(ctx, si);
    mp4_write_minf(ctx, si);

    mp4_end_box(ctx, &box);
}

static mtv_sample_index_t* mp4_find_dominate_track(mp4_output_context_t* ctx)
{
    kal_int32 i;
    mtv_sample_index_t* dominant_track = NULL;
    kal_uint32 duration = 0;

    for (i = 0; i < ctx->num_streams; i++)
    {
		mtv_sample_index_t* si = &ctx->si[i];
        if (si->info.type == MTV_STREAM_AUDIO) {
            return si;
        }
        else
        {
            kal_uint32 track_duration = si->get_duration(si);
            if (duration <= track_duration)
            {
                duration = track_duration;
                dominant_track = si;
            }
        }
    }

    return dominant_track;
}

static void mp4_write_mvhd(mp4_output_context_t* ctx)
{
    mtv_sample_index_t* dominant_track = mp4_find_dominate_track(ctx);
    mp4_box_context_t box;

    mp4_begin_full_box(ctx, &box, "mvhd", 0);

    mp4_write_be32(ctx, 0);         /* creation time */
    mp4_write_be32(ctx, 0);         /* modification time */
    mp4_write_be32(ctx, mp4_get_track_timescale(dominant_track)); /* timescale */
    mp4_write_be32(ctx, mp4_get_track_duration(dominant_track));  /* duration */

    mp4_write_be32(ctx, 0x10000);   /* reserved (preferred rate) 1.0 = normal */
    mp4_write_be16(ctx, 0x0100);    /* reserved (preferred volume) 1.0 = normal */

    mp4_write_be16(ctx, 0);         /* reserved */
    mp4_write_be32(ctx, 0);         /* reserved */
    mp4_write_be32(ctx, 0);         /* reserved */

    /* Matrix structure */
    mp4_write_be32(ctx, 0x00010000);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x00010000);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x0);
    mp4_write_be32(ctx, 0x40000000);

    mp4_write_be32(ctx, 0); /* reserved (preview time) */
    mp4_write_be32(ctx, 0); /* reserved (preview duration) */
    mp4_write_be32(ctx, 0); /* reserved (poster time) */
    mp4_write_be32(ctx, 0); /* reserved (selection time) */
    mp4_write_be32(ctx, 0); /* reserved (selection duration) */
    mp4_write_be32(ctx, 0); /* reserved (current time) */
    mp4_write_be32(ctx, ctx->num_streams + 1); /* next track id */

    mp4_end_box(ctx, &box);
}

static void mp4_write_trak(mp4_output_context_t* ctx, mtv_sample_index_t* si)
{
    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "trak");

    mp4_write_tkhd(ctx, si);
    mp4_write_mdia(ctx, si);

    mp4_end_box(ctx, &box);
}

static void mp4_write_moov(mp4_output_context_t* ctx)
{
    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "moov");

    mp4_write_mvhd(ctx);
    for (ctx->current_track = 0; ctx->current_track < ctx->num_streams; ctx->current_track++)
    {
		mtv_sample_index_t* si = &ctx->si[ctx->current_track];
        if (si->get_entry_count(si) > 0) {
            mp4_write_trak(ctx, si);
        }
    }

    mp4_end_box(ctx, &box);
}

static void mp4_write_mdat(mp4_output_context_t* ctx)
{
	kal_uint32 file_size;
    kal_int32 ret;

    cached_io_file_state_t mp4_state = {NULL, 0};
    mtv_sample_stream_closed_t ss_state = {NULL, 0};

    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "mdat");

    /* save current position as chunk base offset */
    ctx->mdat_offset = mp4_tell(ctx);

	/* flush the cache */
    ret = cached_io_get_state_and_close(&ctx->mp4_cio, &mp4_state);
    if (ret < 0)
    {
        ctx->last_fs_error = ret;
        ++ctx->errors;
        goto write_mdat_cleanup;
    }

    file_size = mp4_state.size;

    /* close the sample stream */
    ret = ctx->ss->close_ex(ctx->ss, &ss_state);
    ASSERT(ret >= 0);
    file_size += ss_state.size;

    /* merge these two files */
    ret = FS_PseudoMerge(mp4_state.filename, ss_state.filename);
    if (ret < 0)
    {
        ctx->last_fs_error = ret;
        ++ctx->errors;
        goto write_mdat_cleanup;
    }

	/* reopen the sample stream */
    ret = ctx->ss->reopen(ctx->ss, &ss_state);
    if (ret < 0)
    {
        ctx->last_fs_error = ret;
        ++ctx->errors;
        goto write_mdat_cleanup;
    }

    /* reopen the merged file */
    ret = cached_io_open(&ctx->mp4_cio, mp4_state.filename, FS_READ_WRITE, MP4_CACHE_BLOCK_SIZE);
    if (ret < 0)
    {
        ctx->last_fs_error = ret;
        ++ctx->errors;
        goto write_mdat_cleanup;
    }

    /* we need to compensate the offset due to cluster-alignment during the merge */
	med_free_ext_mem((void**)&mp4_state.filename);
	ret = cached_io_get_state(ctx->mp4_cio.file_h, &mp4_state);
    ASSERT(ret >= 0);
    ctx->mdat_offset += mp4_state.size - file_size;

    /* seek to the end of file */
    mp4_seek(ctx, mp4_state.size);

    mp4_end_box(ctx, &box);

write_mdat_cleanup:
	med_free_ext_mem((void**)&ss_state.filename);
    med_free_ext_mem((void**)&mp4_state.filename);
}

static void mp4_write_ftyp(mp4_output_context_t* ctx)
{
    mp4_box_context_t box;

    mp4_begin_box(ctx, &box, "ftyp");

    mp4_write_type(ctx, "isom");
    mp4_write_be32(ctx, 0x200);
    mp4_write_type(ctx, "mp41");

    mp4_end_box(ctx, &box);
}

mtv_result_t convert_to_mp4(kal_wchar* mp4_file, kal_int32 num_streams, mtv_sample_index_t* si, mtv_sample_stream_t* ss, volatile kal_bool* aborted)
{
    mp4_output_context_t ctx;
    kal_int32 ret;

    kal_mem_set(&ctx, 0, sizeof(ctx));
    ASSERT(num_streams > 0);
    ctx.num_streams = num_streams;
    ctx.ss = ss;
    ctx.si = si;
    ctx.aborted = aborted;

    ret = cached_io_open(&ctx.mp4_cio, mp4_file, FS_READ_WRITE | FS_CREATE_ALWAYS, MP4_CACHE_BLOCK_SIZE);
    if (ret < 0) {
        return mtv_error_from_fs(ret);
    }

    if (setjmp(ctx.abort_jmpbuf) == 0)
    {
        mp4_write_ftyp(&ctx);
        mp4_write_mdat(&ctx);
        mp4_write_moov(&ctx);
    }
    else /* the conversion is aborted */
    {
        ret = cached_io_close(&ctx.mp4_cio);
        FS_Delete(mp4_file);
        return MTV_E_ABORTED;
    }

    ret = cached_io_close(&ctx.mp4_cio);
    if (ret < 0)
    {
        FS_Delete(mp4_file);
        return mtv_error_from_fs(ret);
    }
    else if (ctx.errors > 0)
    {
        FS_Delete(mp4_file);
        return mtv_error_from_fs(ctx.last_fs_error);
    }

    return MTV_S_OK;
}

#endif /* defined(__MED_MTV_MOD__) */
