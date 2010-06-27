/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 * med_status.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes the common status of video module of media task.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __MED_STATUS_H__
#define __MED_STATUS_H__

#define MED_STAT_MP4_PARSER_START     1
#define MED_STAT_VIDEO_DEC_START      100
#define MED_STAT_VIDEO_ENC_START      150
#define MED_STAT_AUDIO_START          200
#define MED_STAT_FSAL_START           300
#define MED_STAT_MP4_PRODUCER_START    400
#define MED_STAT_MP4_SAMPLEDATA_START  500

typedef enum
{
    MEDIA_STATUS_OK = 0,
    MP4_PARSER_ERROR,
    VIDEO_ERROR,
    AUDIO_ERROR,
    FSAL_ERROR,
    FSAL_READ_EOF,
    FSAL_SEEK_EOF,
    FS_ERROR,
    MP4_PRODUCER_ERROR,
    MP4_SAMPLEDATA_ERROR,
    NO_VISUAL_TRACK,    
    VEDIT_AUDIO_TIME_ERROR,
    SENSOR_ERROR,
    MAX_MEDIA_ERROR
} MEDIA_STATUS_CODE;

typedef enum
{
    MED_STAT_NO_ERROR = 0,
    /* MP4 parser status */
    MED_STAT_MP4_PARSER_OK = MED_STAT_MP4_PARSER_START,
    MED_STAT_MP4_PARSER_FILE_READ_ERROR,
    MED_STAT_MP4_PARSER_FILE_SEEK_ERROR,
    MED_STAT_MP4_PARSER_FILE_ACCESS_ERROR,
    MED_STAT_MP4_PARSER_PARSE_ERROR,
    MED_STAT_MP4_PARSER_PARSE_TRAK_ERROR,
    MED_STAT_MP4_PARSER_ATOM_NOT_FOUND,
    MED_STAT_MP4_PARSER_ES_DESCR_TAG_EXPECTED,
    MED_STAT_MP4_PARSER_BITR_BOX_EXPECTED,
    MED_STAT_MP4_PARSER_D263_BOX_EXPECTED,
    MED_STAT_MP4_PARSER_DAMR_BOX_EXPECTED,
    MED_STAT_MP4_PARSER_64BIT_NOT_SUPPORT,
    MED_STAT_MP4_PARSER_LARGER_31BIT_NOT_SUPPORT,
    MED_STAT_MP4_PARSER_TOO_MANY_TRACKS,
    MED_STAT_MP4_PARSER_EXTERNAL_DATA_REFERENCE,
    MED_STAT_MP4_PARSER_AUDIO_TOO_MANY_CHANNEL,
    MED_STAT_MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT,
    MED_STAT_MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT,
    MED_STAT_MP4_PARSER_960_120_IMDCT_NOT_SUPPORT,
    MED_STAT_MP4_PARSER_NO_MOOV,
    MED_STAT_MP4_PARSER_NO_MVHD,
    MED_STAT_MP4_PARSER_NO_TRAK,
    MED_STAT_MP4_PARSER_NO_TKHD,
    MED_STAT_MP4_PARSER_NO_MDIA,
    MED_STAT_MP4_PARSER_NO_MDHD,
    MED_STAT_MP4_PARSER_NO_HDLR,
    MED_STAT_MP4_PARSER_NO_MINF,
    MED_STAT_MP4_PARSER_NO_STBL,
    MED_STAT_MP4_PARSER_NO_STSD,
    MED_STAT_MP4_PARSER_NO_STTS,
    MED_STAT_MP4_PARSER_NO_STSC,
    MED_STAT_MP4_PARSER_NO_STCO,
    /* / This is a warning. The file can still be handled. */
    MED_STAT_MP4_PARSER_WARNING_TRAILING_GARBAGE,
    /* / This is used by MP4_Audio_Read. */
    MED_STAT_MP4_PARSER_READ_EOF,
    MED_STAT_MP4_PARSER_NO_SUCH_TRACK,
    MED_STAT_MP4_PARSER_INVALID_ARGUMENT,
    MED_STAT_MP4_PARSER_INTERNAL_ERROR,
    /* / This is a warning. The specified sample number is invalid. */
    MED_STAT_MP4_PARSER_NO_SUCH_SAMPLE,
    MED_STAT_MP4_PARSER_END = MED_STAT_MP4_PARSER_INTERNAL_ERROR,

    /* VIDEO decode status */
    /* / Video decode ok */
    MED_STAT_VIDEO_DEC_OK = MED_STAT_VIDEO_DEC_START,
    /* / This video decode frame size in file exceed our maximum size. */
    MED_STAT_VIDEO_DEC_FRAME_SIZE_ERROR,
    /* / This video bitstream is error. */
    MED_STAT_VIDEO_DEC_BITSTREAM_ERROR,
    /* / Some functions in this file are not supported. */
    MED_STAT_VIDEO_DEC_NOT_SUPPORT,
    /* / This function can't be called in this state. */
    MED_STAT_VIDEO_DEC_FUNC_STATE_ERROR,
    /* / The resource is not enough */
    MED_STAT_VIDEO_DEC_RESOURCE_NOT_AVAIL,
    /* / Function parameter error */
    MED_STAT_VIDEO_DEC_FUNC_PARAMETER_ERROR,
    /* / The error that is the bug of the driver */
    MED_STAT_VIDEO_DEC_FATAL_ERROR,
    /* / Video duration exceed the max duration. */
    MED_STAT_VIDEO_DEC_LONG_DURATION,
    /* / The error that is the bug of the driver */
    MED_STAT_VIDEO_DEC_END = MED_STAT_VIDEO_DEC_LONG_DURATION,
    /* / The warning show the end of audio when video seek */
    MED_STAT_VIDEO_DEC_SEEK_AUDIO_END,

    /* VIDEO encode status */
    /* / Video encode ok */
    MED_STAT_VIDEO_ENC_OK = MED_STAT_VIDEO_ENC_START,
    /* / This video encode frame size exceed our maximum size. */
    MED_STAT_VIDEO_ENC_FRAME_SIZE_ERROR,
    /* / The bitrate too large. */
    MED_STAT_VIDEO_ENC_BITRATE_ERROR,
    /* / The frame rate too large. */
    MED_STAT_VIDEO_ENC_FRAME_RATE_ERROR,
    /* / This function can't be called in this state. */
    MED_STAT_VIDEO_ENC_FUNC_STATE_ERROR,
    /* / The resource is not enough */
    MED_STAT_VIDEO_ENC_RESOURCE_NOT_AVAIL,
    /* / The bitstream file and meta file can't merge a media file. */
    MED_STAT_VIDEO_ENC_FILE_CANT_MERGE,
    /* / Some functions in this file are not supported. */
    MED_STAT_VIDEO_ENC_NOT_SUPPORT,
    /* / The error that is the bug of the driver */
    MED_STAT_VIDEO_ENC_FATAL_ERROR,
    MED_STAT_VIDEO_ENC_END = MED_STAT_VIDEO_ENC_FATAL_ERROR,

    /* Audio Status */
    MED_STAT_MEDIA_SUCCESS = MED_STAT_AUDIO_START,
    MED_STAT_MEDIA_FAIL,
    MED_STAT_MEDIA_REENTRY,
    MED_STAT_MEDIA_NOT_INITIALIZED,
    MED_STAT_MEDIA_BAD_FORMAT,
    MED_STAT_MEDIA_BAD_PARAMETER,
    MED_STAT_MEDIA_BAD_COMMAND,
    MED_STAT_MEDIA_NO_HANDLER,
    MED_STAT_MEDIA_UNSUPPORTED_CHANNEL,
    MED_STAT_MEDIA_UNSUPPORTED_FREQ,
    MED_STAT_MEDIA_UNSUPPORTED_TYPE,
    MED_STAT_AUDIO_END = MED_STAT_MEDIA_UNSUPPORTED_TYPE,

    /* FSAL_STATUS */
    MED_STAT_FSAL_OK = MED_STAT_FSAL_START,
    MED_STAT_FSAL_OPEN_ERROR,
    MED_STAT_FSAL_READ_ERROR,
    MED_STAT_FSAL_WRITE_ERROR,
    MED_STAT_FSAL_SEEK_ERROR,
    MED_STAT_FSAL_CLOSE_ERROR,
    MED_STAT_FSAL_INVALID_ARGUMENT,
    /* / The field of the structure is invalid. Possibly caused by memory corruption. */
    MED_STAT_FSAL_MEMORY_CORRUPTION,
    MED_STAT_FSAL_FATAL_ERROR,
    MED_STAT_FSAL_END = MED_STAT_FSAL_FATAL_ERROR,

    /* MP4PRODUCER status */
    MED_STAT_MP4_PRODUCER_OK = MED_STAT_MP4_PRODUCER_START,
    MED_STAT_MP4_PRODUCER_FILE_READ_ERROR,
    MED_STAT_MP4_PRODUCER_FILE_WRITE_ERROR,
    MED_STAT_MP4_PRODUCER_FILE_SEEK_ERROR,
    MED_STAT_MP4_PRODUCER_FILE_ACCESS_ERROR,
    MED_STAT_MP4_PRODUCER_SAMPLE_DATA_READ_ERROR,
    MED_STAT_MP4_PRODUCER_SAMPLE_DATA_AUDIO_TYPE_ERROR,
    /// In MP4_Produce_CalculateLimitedAudioFileSize, it's found that
    /// the Audio File is less than 8 bytes. The first 8 bytes are
    /// supposed to be MDAT (4 bytes) and SIZE (4 bytes).
    MP4_STAT_MP4_PRODUCER_AUDIO_FILE_TOO_SMALL,
    MED_STAT_MP4_PRODUCER_AMR_FQI_INVALID,
    MED_STAT_MP4_PRODUCER_AMR_FRAME_INVALID,
    MED_STAT_MP4_PRODUCER_INVALID_ARGUMENT,
    MED_STAT_MP4_PRODUCER_END = MED_STAT_MP4_PRODUCER_INVALID_ARGUMENT,

    /* MP4 sample data status */
    MED_STAT_MP4_SAMPLE_DATA_OK = MED_STAT_MP4_SAMPLEDATA_START,
    MED_STAT_MP4_SAMPLE_DATA_FILE_READ_ERROR,
    MED_STAT_MP4_SAMPLE_DATA_FILE_SEEK_ERROR,
    MED_STAT_MP4_SAMPLE_DATA_FILE_FORMAT_ERROR,
    MED_STAT_MP4_SAMPLE_DATA_INVALID_ARGUMENT,
    MED_STAT_MP4_SAMPLE_END = MED_STAT_MP4_SAMPLE_DATA_INVALID_ARGUMENT,

    MAX_MED_STATUS
} MED_STATUS;

#endif /* __MED_STATUS_H__ */ 

