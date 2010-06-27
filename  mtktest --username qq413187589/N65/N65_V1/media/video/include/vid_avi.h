/*******************************************************************************
 * Filename:
 * ---------
 * vid_avi.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes avi related info of video module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef VID_AVI_H
#define VID_AVI_H

/*
 * [AVI File Format] for MJPEG
 * 
 * RIFF.4.AVI .
 *     LIST.4.hdlr.avih.(file header)
 *     LIST.4.strl.strh.(video header)
 *                .strf.(video format)
 *     LIST.4.strl.strh.(audio header)
 *                .strf.(audio format)
 *     JUNK.4.(junk)
 *     LIST.4.movi.xxdb.4.(video data)
 *     LIST.4.movi.xxdc.4.(video data) 
 *     LIST.4.movi.xxwb.4.(audio data)  
 *     LIST.4.ind1.(list data)
 */

#define MED_AVI_TAG_RIFF            ("RIFF")
#define MED_AVI_TAG_AVI             ("AVI ")
#define MED_AVI_TAG_LIST            ("LIST")
#define MED_AVI_TAG_JUNK            ("JUNK")
#define MED_AVI_TAG_MJPG            ("MJPG")

#define MED_AVI_TAG_HEADER_LIST     ("hdrl")
#define MED_AVI_TAG_AVI_HEADER      ("avih")
#define MED_AVI_TAG_STREAM_LIST     ("strl")
#define MED_AVI_TAG_STREAM_HEADER   ("strh")
#define MED_AVI_TAG_STREAM_FORMAT   ("strf")
#define MED_AVI_TAG_MOVI            ("movi")
#define MED_AVI_TAG_IDX1            ("idx1")
#define MED_AVI_TAG_STREAM_TYPE_VID ("vids")
#define MED_AVI_TAG_STREAM_TYPE_AUD ("auds")
#define MED_AVI_TAG_WB              ("  wb")
#define MED_AVI_TAG_DC              ("  dc")
#define MED_AVI_TAG_DB              ("  db")

#define MED_AVI_VISUAL_FILE         (L"~visual.tmp")
#define MED_AVI_IDX_FILE            (L"~idx.tmp")

/* flags for med_avi_avi_header_struct */
#define MED_AVI_FH_HAS_INDEX            0x00000010
#define MED_AVI_FH_MUST_USE_INDEX       0x00000020
#define MED_AVI_FH_IS_INTERLEAVED       0x00000100
#define MED_AVI_FH_TRUST_CK_TYPE        0x00000800
#define MED_AVI_FH_WAS_CAPTURE_FILE     0x00010000
#define MED_AVI_FH_COPY_RIGHTED         0x00020000

/* 56 byte */
typedef struct
{
    kal_uint32 micro_sec_per_frame; /* frame rate */
    kal_uint32 max_byte_per_sec;    /* transfer rate */
    kal_uint32 padding_factor;      /* padding factor - * this  */
    kal_uint32 flag;                /* flag */
    kal_uint32 total_frame;         /* total frame */
    kal_uint32 init_frames;         /* init frame */
    kal_uint32 num_of_stream;       /* num of streams */
    kal_uint32 suggest_buf_size;    /* suggested buffer size */
    kal_uint32 width;               /* video width */
    kal_uint32 height;              /* video height */
    kal_uint32 reserve[4];          /* reserve */

} med_avi_file_header_struct;

/* flags for med_avi_stream_header_struct */
#define MED_AVI_SH_DISABLED            0x00000001
#define MED_AVI_SH_VIDEO_PALCHANGES    0x00010000

/* 52 byte */
typedef struct
{
    kal_uint32 fcc_type;
    kal_uint32 fcc_hdlr;
    kal_uint32 flag;
    kal_uint16 priority;
    kal_uint16 language;
    kal_uint32 init_frames;
    kal_uint32 scale;
    kal_uint32 rate;    /* rate/scale = sample/sec */
    kal_uint32 start;
    kal_uint32 length;
    kal_uint32 suggest_buf_size;
    kal_uint32 quality;
    kal_uint32 sample_size;
    kal_uint8 rect_left;
    kal_uint8 rect_top;
    kal_uint8 rect_right;
    kal_uint8 rect_bottom;
} med_avi_stream_header_struct;

typedef struct
{
    kal_uint32 size;
    kal_uint32 width;
    kal_uint32 height;
    kal_uint16 planes;
    kal_uint16 bit_count;
    kal_uint32 compression;
    kal_uint32 size_image;
    kal_uint32 x_pels_per_meter;
    kal_uint32 y_pels_per_meter;
    kal_uint32 color_used;
    kal_uint32 color_important;
} med_avi_video_format_header_struct;

#define MED_AVI_AUD_FORMAT_WAV_UNKNOWN          0x0000
#define MED_AVI_AUD_FORMAT_WAV_PCM              0x0001
#define MED_AVI_AUD_FORMAT_WAV_ADPCM            0x0002
#define MED_AVI_AUD_FORMAT_WAV_IBM_CVSD         0x0005
#define MED_AVI_AUD_FORMAT_WAV_ALAW             0x0006
#define MED_AVI_AUD_FORMAT_WAV_MULAW            0x0007
#define MED_AVI_AUD_FORMAT_WAV_OKI_ADPCM        0x0010
#define MED_AVI_AUD_FORMAT_WAV_DVI_ADPCM        0x0011
#define MED_AVI_AUD_FORMAT_WAV_DIGISTD          0x0015
#define MED_AVI_AUD_FORMAT_WAV_DIGIFIX          0x0016
#define MED_AVI_AUD_FORMAT_WAV_YAMAHA_ADPCM     0x0020
#define MED_AVI_AUD_FORMAT_WAV_DSP_TRUESPEECH   0x0022
#define MED_AVI_AUD_FORMAT_WAV_GSM610           0x0031
#define MED_AVI_AUD_FORMAT_IBM_MULAW            0x0101
#define MED_AVI_AUD_FORMAT_IBM_ALAW             0x0102
#define MED_AVI_AUD_FORMAT_IBM_ADPCM            0x0103

typedef struct
{
    kal_uint16 format;
    kal_uint16 channels;
    kal_uint32 sample_per_sec;
    kal_uint32 avg_byte_per_sec;
    kal_uint16 block_align;
    kal_uint16 bit_per_sample;
    kal_uint16 size;
} med_avi_audio_format_header_struct;

/* flags for med_avi_index_struct */
#define MED_AVI_IF_LIST             0x00000001
#define MED_AVI_IF_KEY_FRAME        0x00000010
#define MED_AVI_IF_NO_TIME          0x00000100
#define MED_AVI_IF_COMP_USE         0x0FFF0000

typedef struct
{
    kal_uint32 chunk_id;
    kal_uint32 flag;
    kal_uint32 chunk_offset;
    kal_uint32 chunk_lenght;
} med_avi_index_struct;

typedef struct
{
    kal_uint32 file_offset;
    kal_uint32 frame_idx;
} med_avi_index_map_struct;

/* avi info, for caller */
#define MED_AVI_AUD_FORMAT_PCM              0x00000001
#define MED_AVI_AUD_FORMAT_NOT_SUPPORT      0x00000002

#define MED_AVI_VID_FORMAT_MJPEG            0x00000001
#define MED_AVI_VID_FORMAT_NOT_SUPPORT      0x00000002

typedef struct
{
    kal_uint32 aud_format;
    kal_uint32 aud_sample_rate;
    kal_uint32 aud_channel;
    kal_uint32 aud_bit_per_sample;
    kal_uint32 vid_format;
    kal_uint16 vid_width;
    kal_uint16 vid_height;
    kal_uint64 vid_duration_in_ms;
    kal_uint32 vid_rate;    /* rate/scale = fps */
    kal_uint32 vid_scale;
    kal_uint32 vid_fps;     /* fps may have rounding error, use rate/scale when need accurate fps */
} med_avi_info_struct;



extern void med_avi_init(void);

/* player */
extern kal_int32 med_avi_open_play_file(med_avi_info_struct *avi_info_p, const kal_wchar *filename_p);
extern kal_int32 med_avi_close_play_file(void);
extern kal_int32 med_avi_read_video_frame(kal_char *data_p, kal_uint32 *len_p);
extern kal_int32 med_avi_read_video_frame_move_next(kal_char *data_p, kal_uint32 *len_p);
extern kal_int32 med_avi_skip_video_frame(void);
extern kal_int32 med_avi_read_audio_data(kal_char *data_p, kal_uint32 *len_p);
extern kal_int32 med_avi_seek_by_time(kal_uint64 time_in_ms);
extern kal_int32 med_avi_open_play_array(med_avi_info_struct *avi_info_p, kal_char *data_p, kal_int32 data_size);
extern kal_int32 med_avi_close_play_array(void);

typedef struct
{
    kal_uint32 aud_format;
    kal_uint32 aud_sample_rate;
    kal_uint32 aud_channel;
    kal_uint32 aud_bit_per_sample;
    kal_uint32 vid_format;
    kal_uint16 vid_width;
    kal_uint16 vid_height;
    kal_uint32 vid_rate;    /* rate/scale = fps */
    kal_uint32 vid_scale;
} med_avi_rec_struct;

/* recorder */
extern kal_int32 med_avi_open_record_file(med_avi_rec_struct *rec_data, const kal_wchar *filename_p);
extern kal_int32 med_avi_close_record_file(void);
extern kal_int32 med_avi_write_video_frame(kal_char *data_p, kal_uint32 len);
extern kal_int32 med_avi_write_audio_data(kal_char *data_p, kal_uint32 len);
extern kal_int32 med_avi_get_current_data_size(void);

extern kal_int32 med_avi_toggle_data_buffer(void);
extern kal_int32 med_avi_toggle_idx_buffer(void);

extern kal_int32 med_avi_dump_data_buffer_to_file(void);
extern kal_int32 med_avi_dump_idx_buffer_to_file(void);

extern kal_int32 med_avi_is_active_data_buf_sufficient(kal_int32 req_size);
extern kal_int32 med_avi_is_active_idx_buf_sufficient(void);

extern kal_int32 med_avi_merge_result(const kal_wchar *filename_p);
extern kal_int32 med_avi_get_cur_file_size(void);
extern kal_int32 med_avi_get_cur_record_time(kal_uint64 *time);
extern kal_bool  med_avi_is_reach_record_limit(void);
extern kal_bool  med_avi_has_unsaved_file(const kal_wchar *filepath_p);
extern kal_bool  med_avi_clean_tmp_files(const kal_wchar *filepath_p);

extern kal_int32 med_avi_get_data_buf_size(void);
extern kal_int32 med_avi_get_idx_buf_size(void);

/* 
 * this function is for MT6225 series only, we do not know actual record
 * fps before record process start, we will set the fps again after record starts 
 */
extern kal_int32 med_avi_update_fps(kal_uint32 rate, kal_uint32 scale);

#endif /* VID_AVI_H */ 
