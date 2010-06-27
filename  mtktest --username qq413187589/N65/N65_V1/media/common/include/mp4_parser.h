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
 *
 * Filename:
 * ---------
 * mp4_parser.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __MP4_PARSER_H__
#define __MP4_PARSER_H__


#ifndef MP4_UT_ONWIN32
   /// For target and MoDIS
   #define MP4_PARSER_VERBOSE 0
   #include "kal_release.h"
   #include "med_status.h"
#else
   /// For Win32 standalone application, unit test and PC Simulator
   #include <stdio.h>
   #include <assert.h>
   #include <string.h>
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
   #define MP4_PARSER_VERBOSE 1
   #define kal_mem_cpy(a,b,c) memcpy(a,b,c)
   #define kal_mem_set(a,b,c) memset(a,b,c)
   #include "kal_non_specific_general_types.h"
   #include "med_status.h"
#endif

#include "mp4_common.h"
#include "fsal.h"

//#define MP4_ERR_UNRECOGNIZED_FILE_TYPE -1



/* --- public definitions --- */

typedef enum {
  MP4_PARSER_OK = MED_STAT_MP4_PARSER_START,
  MP4_PARSER_FILE_READ_ERROR,
  MP4_PARSER_FILE_SEEK_ERROR,
  MP4_PARSER_FILE_ACCESS_ERROR,
  MP4_PARSER_PARSE_ERROR,
  MP4_PARSER_PARSE_TRAK_ERROR,
  MP4_PARSER_ATOM_NOT_FOUND,
  MP4_PARSER_ES_DESCR_TAG_EXPECTED,
  MP4_PARSER_BITR_BOX_EXPECTED,
  MP4_PARSER_D263_BOX_EXPECTED,
  MP4_PARSER_DAMR_BOX_EXPECTED,
  MP4_PARSER_64BIT_NOT_SUPPORT,
  MP4_PARSER_LARGER_31BIT_NOT_SUPPORT,
  MP4_PARSER_TOO_MANY_TRACKS,
  MP4_PARSER_EXTERNAL_DATA_REFERENCE,
  MP4_PARSER_AUDIO_TOO_MANY_CHANNEL,
  MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT,
  MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT,
  MP4_PARSER_960_120_IMDCT_NOT_SUPPORT,
  MP4_PARSER_NO_MOOV,
  MP4_PARSER_NO_MVHD,
  MP4_PARSER_NO_TRAK,
  MP4_PARSER_NO_TKHD,
  MP4_PARSER_NO_MDIA,
  MP4_PARSER_NO_MDHD,
  MP4_PARSER_NO_HDLR,
  MP4_PARSER_NO_MINF,
  MP4_PARSER_NO_STBL,
  MP4_PARSER_NO_STSD,
  MP4_PARSER_NO_STTS,
  MP4_PARSER_NO_STSC,
  MP4_PARSER_NO_STCO,
  // This is a warning. The file can still be handled.
  MP4_PARSER_WARNING_TRAILING_GARBAGE,
  // This is used by MP4_Audio_Read. When the data has been read out completely, this value will be returned.
  // This is a warning. The file can still be handled.
  MP4_PARSER_READ_EOF,
  // This means there is no such audio or video track. Some APIs have an argument 'track type', if the
  // track is not existed, this value will be returned.
  // This is a warning. The file can still be handled.
  MP4_PARSER_NO_SUCH_TRACK,
  MP4_PARSER_INVALID_ARGUMENT,
  MP4_PARSER_INTERNAL_ERROR,
  // This is a warning. The specified sample number is invalid.
  MP4_PARSER_NO_SUCH_SAMPLE
} MP4_Parser_Status;

typedef enum {
   MP4_AUD_EXTR_OK,
   MP4_AUD_EXTR_FILE_READ_ERROR,
   MP4_AUD_EXTR_FILE_WRITE_ERROR,
   MP4_AUD_EXTR_FILE_SEEK_ERROR,
   MP4_AUD_EXTR_FILE_FORMAT_ERROR,
   MP4_AUD_EXTR_PARSE_ERROR,
   MP4_AUD_EXTR_DISK_SPACE_NOT_ENOUGH,
   MP4_AUD_EXTR_INVALID_ARGUMENT,
   MP4_AUD_EXTR_INVALID_START_TIME,
   MP4_AUD_EXTR_INVALID_STOP_TIME,
   MP4_AUD_EXTR_AUDIO_TYPE_MATCH,
   MP4_AUD_EXTR_AUDIO_TYPE_MISMATCH,
   MP4_AUD_EXTR_CHANNEL_NUMBER_MISMATCH,
   MP4_AUD_EXTR_SAMPLE_RATE_MISMATCH,
   MP4_AUD_EXTR_Get_TIME_SCALE_FAILED,
   MP4_AUD_EXTR_ADIF_NOT_SUPPORT,
   MP4_AUD_EXTR_AUDIO_TYPE_NOT_SUPPORT,
   MP4_AUD_EXTR_FILL_SILENCE_NOT_SUPPORT
} MP4_Aud_Extr_Status;

/* --- private definitions --- */

#define MP4_NUM_TRACKS 3

#define CHNUK_SAMPLE_NO 1024

/* Definition for STTS cache table */
typedef struct {
   kal_uint32 accumulated_sample_count;
   kal_uint64 accumulated_decode_time;
} STTS_Cache_Entry;

/* Definition for STSC cache table */
typedef struct {
   kal_uint32 accumulated_sample_count;
} STSC_Cache_Entry;

/* Definition for STSS cache table */
typedef struct {
   kal_uint32 sample_number;
} STSS_Cache_Entry;

typedef struct {
   kal_uint32 track_ID;

   /* Track Header */
   kal_uint32 width;
   kal_uint32 height;

   /* Media Header */
   kal_uint32 uMediaTimeScale;
   kal_uint32 uMediaDuration;

   /* Handler Reference Box */
   kal_uint32 handler_type;

   /* Time to Sample Box (STTS) */
   kal_uint32 uTimeToSampleTableEntryCount;
   kal_uint32 uOffsetTimeToSampleTable;

   kal_uint32 uSTTSCurSampleCount;
   kal_uint64 uSTTSCurDecodeTime;
   kal_uint32 uSTTSIndex;
   kal_uint16 uSTTSStepCounter;
   kal_uint16 uSTTSCacheIndex;
   kal_uint16 uSTTSCacheTableEntryCount;     // Number of entries in STTS cache table
   kal_uint16 uSTTSCacheTableStepSize;       // The step size of STTS index of STTS cache table entry
   STTS_Cache_Entry *pSTTSCacheTable;        // The STTS cache table

   /* Sample Size Box (STSZ) */
   kal_bool   bSampleCountUpdated;     // flag to record if the sample count is updated or not
   kal_uint32 uSampleCount;            // number of samples in a track
   kal_uint32 uConstantSampleSize;
   kal_uint32 uOffsetSampleSizeTable;  // file offset of the first entry_size in sample size box

   /* Chunk Offset Box (STCO) */
   kal_uint32 uChunkCount;
   kal_uint32 uOffsetChunkOffsetTable; // file offset of the first chunk_offset in chunk offset box

   /* Sample To Chunk Box (STSC) */
   kal_uint32 uSampleToChunkEntryCount;
   kal_uint32 uOffsetSampleToChunkTable;

   kal_uint16 uSTSCCacheTableEntryCount;
   kal_uint16 uSTSCCacheTableStepSize;
   STSC_Cache_Entry *pSTSCCacheTable;

   /* Sync Sample Box (STSS) */
   kal_uint32 uSyncCount;
   kal_uint32 uOffsetSyncSampleTable;  // file offset of the first sync sample in sync sample box

   kal_uint32 uSTSSIndex;
   kal_uint16 uSTSSCacheIndex;
   kal_uint16 uSTSSCacheTableEntryCount;
   kal_uint16 uSTSSCacheTableStepSize;
   STSS_Cache_Entry *pSTSSCacheTable;

   /* Marks for checking the mandatory atoms */
   kal_bool bHasTKHD;
   kal_bool bHasMDIA;
   kal_bool bHasMDHD;
   kal_bool bHasHDLR;
   kal_bool bHasMINF;
   kal_bool bHasSTBL;
   kal_bool bHasSTSD;
   kal_bool bHasSTTS;
   kal_bool bHasSTSC;
   kal_bool bHasSTCO;
   kal_bool bHasSTSS;

   /* cache some values for optimization in MP4_GetChunkNoAndOffset_Next */
   kal_uint32 uCurSampleNo;
   kal_uint32 uSampleToChunkIndex;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uFirstChunk;
   kal_uint32 uSampleSum;
   kal_uint32 uSampleSumPrev;

   /* cache some values for optimization in MP4_GetChunkNoAndOffset_Next */
   kal_uint32 uSampleInChunk_Cache;
   kal_uint32 uSampleOffset_Cache;

   /* cache some values for optimization in MP4_GetDecodeTimeDelta_Next */
   kal_uint32 uDecodeTimeDelta_SampleNo;
   kal_uint32 uDecodeTimeDelta_TableIndex;
   kal_uint32 uDecodeTimeDelta_ThisSampleDelta;
   kal_uint32 uDecodeTimeDelta_CurSampleCount;

   /* cache some values for optimization in MP4_GetDecodeTime_Next */
   kal_uint32 uDecodeTime_SampleNo;
   kal_uint32 uDecodeTime_TableIndex;
   kal_uint64 uDecodeTime_PrevDecodeTime;
   kal_uint32 uDecodeTime_ThisSampleDelta;
   kal_uint32 uDecodeTime_CurSampleCount;

   STFSAL *pstFSAL_STSZ;
   STFSAL *pstFSAL_STCO;
   kal_uint32 uGetAvaDurCurSampleCnt;
} STMp4Track;

typedef struct {
   /* file system abstration layer for accessing sample tables */
   STFSAL *pstFSAL;
   FSAL_Status eFSALErr;

   STMp4Track stMp4Track[MP4_NUM_TRACKS];

   kal_uint8 bCurTrack;                // the track we're currently parsing
   kal_uint8 bAudioTrack;              // track no. of audio track
   kal_uint8 bVideoTrack;              // track no. of video track

   kal_uint32 timescale;               // in Movie Header
   kal_uint32 duration;                // in Movie Header
   kal_uint32 next_track_ID;           // in Movie Header

   MP4_Audio_Type bAudioType;          // in Audio Sample Entry
   MP4_Video_Type bVideoType;          // in Video Sample Entry

   kal_uint8 bAudioSamplingFreqIndex;  // sampling frequency index (defined in 14496-3)
   kal_uint8 bAudioChannelConfig;      // channel configuration (14496-3)
   kal_uint8 bFramesPerSample;         // in AMR Decoder Specific Structure

   kal_uint32 uAudioAvgBitrate;        // in Decoder Config Descriptor
   kal_uint32 uAudioMaxBitrate;        // in Decoder Config Descriptor
   kal_uint32 uAudioPCEFileOffset;     // for 14496-3 GA Specific Config
   kal_uint32 uAudioPCEBitLength;      // for 14496-3 GA Specific Config

   /* Marks for checking the mandatory atoms */
   kal_bool bHasMOOV;
   kal_bool bHasMVHD;
   kal_bool bHasTRAK;

   /* for MP4_Audio_Read */
   STFSAL *pstFSALAudio;

   kal_uint32 uAudioReadSampleNo;
   kal_uint32 uAudioReadSampleOffset;
   kal_uint32 uAudioReadSampleFileOffset;
   kal_uint64 uAudioSeekPointTime;     // the time of the previous seek point, in mili-second */

   kal_bool   bAddADTSFrameHeader;
   kal_uint8  pbADTSFrameHeader[ADTS_HEADER_SIZE];
   kal_uint32 uADTSHeaderReadOffset;

   kal_bool   bAddADIFFrameHeader;
   kal_uint8  pbADIFFrameHeader[ADIF_HEADER_SIZE];
   kal_uint32 uADIFFrameHeaderLen;
   kal_uint32 uADIFHeaderReadOffset;

   kal_uint32 uMOOVOffset;                // file offset of movie header
   kal_uint32 uVOSOffset;                 // file offset of video header
   kal_uint32 uVOSSize;                   // length of video header

   /* These two variable is used to keep the MP4 playback time */
   kal_uint64 uPlaybackTimeBase;          // the time base of the playback, in mili-second
   kal_uint32 uPreviousInterruptCount;    // the interrupt count kept when the previous MP4_GetPlayTime is called

   /* For SAMPLE_FMT_MP4A copy */
   kal_uint32 uMP4A_FMT_offset;
   kal_uint32 uMP4A_FMT_size;

} STMp4Parser;


/* ------ Private Macros ------ */

#define MP4_PARSER_FILE_GET_CUR_POS(pos) \
   if (FSAL_GetCurPos(pstMp4Parser->pstFSAL, &(pos))!=FSAL_OK) \
      return MP4_PARSER_FILE_ACCESS_ERROR

#define MP4_PARSER_CHECK_ARG(exp) \
   if (!(exp)) \
      return MP4_PARSER_INVALID_ARGUMENT

#define MP4_PARSER_ASSERT(exp) \
   if (!(exp)) \
      return MP4_PARSER_INTERNAL_ERROR

#define MP4_PARSER_ASSERT_NO_RET_VAL(exp) \
   if (!(exp)) \
      return

/* ------ Private Functions - file I/O ------ */

MP4_Parser_Status mp4_next_start_code(STMp4Parser *pstMp4Parser, kal_uint32 *puBitCnt);

/* ------ Private Functions ------ */

MP4_Parser_Status mp4_parse_box(STMp4Parser *pstMp4Parser, kal_uint32 *size, kal_uint32 *type);
MP4_Parser_Status mp4_parse_esds(STMp4Parser *pstMp4Parser, kal_int32 esds_size);

/* ------ Private Functions - audio ------ */

MP4_Parser_Status mp4_parse_mp4a(STMp4Parser *pstMp4Parser, long mp4a_size);
MP4_Parser_Status mp4_parse_decoder_config_14496_3(STMp4Parser *pstMp4Parser, long box_size);
MP4_Parser_Status mp4_parse_samr(STMp4Parser *pstMp4Parser, long samr_size);
MP4_Parser_Status prepareAACFrameHeader(STMp4Parser *pstMp4Parser);
kal_uint8 mp4_audio_amr_get_frame_per_sample(STMp4Parser *pstMp4Parser);

/* ------ Private Functions - video ------ */

MP4_Parser_Status mp4_parse_mp4v(STMp4Parser *pstMp4Parser, long mp4v_size);
MP4_Parser_Status mp4_parse_s263(STMp4Parser *pstMp4Parser, long s263_size);
/* extern int mp4_parse_decoder_config_14496_2(STMp4Parser *pstMp4Parser, long box_size); */

/* ------ Public Functions ------ */

MP4_Parser_Status MP4_Parse(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL);
MP4_Parser_Status MP4_STBL_CacheTablePreprocess(STMp4Parser *pstMp4Parser, kal_uint32 *pCachePool, kal_uint32 uCachePoolSize);

MP4_Audio_Type MP4_GetAudioType(STMp4Parser *pstMp4Parser);
MP4_Video_Type MP4_GetVideoType(STMp4Parser *pstMp4Parser);

/* Media Header Box related functions */

MP4_Parser_Status MP4_GetMediaTimeScale(STMp4Parser *pstMp4Parser, kal_uint32 *puTimeScale, MP4_Track_Type eTrackType);
MP4_Parser_Status MP4_GetMediaDuration(STMp4Parser *pstMp4Parser, kal_uint32 *puDuration, MP4_Track_Type eTrackType);

MP4_Parser_Status MP4_SetFSAL_STCO(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL);
MP4_Parser_Status MP4_SetFSAL_STSZ(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL);

MP4_Parser_Status MP4_GetSampleCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 *puSampleCount);
MP4_Parser_Status MP4_UpdateSampleCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType);

MP4_Parser_Status MP4_GetSampleSize(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint32 *puSampleSize, MP4_Track_Type eTrackType);
MP4_Parser_Status MP4_GetSampleOffset(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint32 *puSampleOffset, MP4_Track_Type eTrackType);
MP4_Parser_Status MP4_GetSampleOffset_Next(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleOffset, MP4_Track_Type eTrackType);
MP4_Parser_Status MP4_GetSampleOffset_Previous(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleOffset, MP4_Track_Type eTrackType);
MP4_Parser_Status MP4_GetSampleOffset_Array(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint32 *puSampleOffsetArray, kal_uint32 *pArraySize, MP4_Track_Type eTrackType);

/* Decoding Time to Sample Box related functions */

MP4_Parser_Status MP4_GetDecodeTimeDelta(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint64 *puDecodeTimeDelta, MP4_Track_Type eTrackType);
MP4_Parser_Status MP4_GetDecodeTimeDelta_Next(STMp4Parser *pstMp4Parser, kal_uint64 *puDecodeTimeDelta, MP4_Track_Type eTrackType);
MP4_Parser_Status MP4_GetDecodeTimeDelta_Array(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint64 *puDecodeTimeDeltaArray, kal_uint32 *pArraySize, MP4_Track_Type eTrackType);

MP4_Parser_Status MP4_GetDecodeTime(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint64 *puDecodeTime, MP4_Track_Type eTrackType );
MP4_Parser_Status MP4_GetDecodeTime_Next(STMp4Parser *pstMp4Parser, kal_uint64 *puDecodeTime, MP4_Track_Type eTrackType );
MP4_Parser_Status MP4_GetDecodeTime_Array(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint64 *puDecodeTimeArray, kal_uint32 *pArraySize, MP4_Track_Type eTrackType );

MP4_Parser_Status MP4_GetSampleNumber(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleNo, kal_uint64 uDecodeTime, MP4_Track_Type eTrackType );

/* Sync Sample Box related functions */

MP4_Parser_Status MP4_GetPrevSyncSampleNo(STMp4Parser *pstMp4Parser, kal_uint32 uCurSampleNo, kal_uint32 *puPrevSyncSampleNo, MP4_Track_Type eTrackType);

kal_uint8 MP4_Audio_GetFreqIndex(STMp4Parser *pstMp4Parser);
kal_uint32 MP4_Audio_GetSamplingFreq(STMp4Parser *pstMp4Parser);
kal_uint8 MP4_Audio_GetChannelNum(STMp4Parser *pstMp4Parser);

/* Audio related function */
MP4_Parser_Status MP4_Audio_SetFSAL(STMp4Parser *pstMp4Parser, STFSAL *pstFSALAudio);
MP4_Parser_Status MP4_Audio_Seek_To_Video(STMp4Parser *pstMp4Parser, kal_uint64 uVideoDecodeTime, kal_uint32 *puAudioSampleNo);
MP4_Parser_Status MP4_Audio_Seek(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo);
MP4_Parser_Status MP4_Audio_Read(STMp4Parser *pstMp4Parser, kal_uint8* pBuf, kal_uint32 uSize, kal_uint32 *uReadSize);
MP4_Parser_Status MP4_Audio_TimeToSampleNo(STMp4Parser *pstMp4Parser, kal_uint64 uMiliSecond, kal_uint32 *puAudioSampleNo );

/* Platform dependent function */
#include "l1audio.h"
MP4_Parser_Status MP4_Audio_GetPlayTime(STMp4Parser *pstMp4Parser, kal_uint64 *puMiliSecond, kal_uint32 speed_scale);
Media_Format MP4_Audio_Type_To_Media_Format(MP4_Audio_Type eAudioType);
MP4_Parser_Status MP4_GetPlayTime(STMp4Parser *pstMp4Parser, kal_uint64 *puMiliSecond, kal_uint32 speed_scale );
void MP4_SetPlaybackTimerBase(STMp4Parser *pstMp4Parser, kal_uint32 uPlaybackTimeBase, kal_bool bResetPreviousInterruptCount);

/* Video related function */
kal_uint32 MP4_Video_GetVOSOffset(STMp4Parser *pstMp4Parser);
kal_uint32 MP4_Video_GetVOSSize(STMp4Parser *pstMp4Parser);

kal_uint32 MP4_GetMovieHeaderOffset(STMp4Parser *pstMp4Parser);

/* Special function */
void MP4_Parser_Clone(STMp4Parser *pstMp4Parser_Src, STMp4Parser *pstMp4Parser_Dst, STFSAL *pstFSAL_Dst);

/* Mpeg4 extraction */
MP4_Aud_Extr_Status MP4_ExtrAudio(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uStartTime, kal_uint32 uStopTime);
MP4_Aud_Extr_Status MP4_ExtrAudio_Write_Sample_Data(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_AudioSampleDataFile, kal_uint32 uStartTime, kal_uint32 uStopTime);
MP4_Aud_Extr_Status MP4_ExtrAudio_Append_Silence(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uSilenceFrameCnt);
MP4_Aud_Extr_Status MP4_ExtrAudio_Append_Silence_To_Sample_Data(STFSAL *pstFSAL_AudioSampleDataFile, kal_uint32 uSilenceFrameCnt);
MP4_Aud_Extr_Status MP4_ExtrAudio_Append(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uStartTime, kal_uint32 uStopTime);
MP4_Aud_Extr_Status MP4_ExtrAudio_Write_Sample_Data_Append(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_AudioSampleDataFile, kal_uint32 uStartTime, kal_uint32 uStopTime);
MP4_Aud_Extr_Status MP4_ExtrAudio_Merge_Auido_File(STFSAL *pstFSAL_ASDFileSrc, STFSAL *pstFSAL_ASDFileDes);
MP4_Aud_Extr_Status MP4_ExtrAudio_Merge_Sample_Data(STFSAL *pstFSAL_ASDFileSrc, STFSAL *pstFSAL_ASDFileDes);
MP4_Aud_Extr_Status MP4_ExtrAudio_CheckAudType(STMp4Parser *pstMp4Parser1, STMp4Parser *pstMp4Parser2);
MP4_Aud_Extr_Status MP4_ExtrAudio_GetAudSize(STMp4Parser *pstMp4Parser, kal_uint32 uStartTime, kal_uint32 uStopTime, kal_uint32 *puAudSizeInByte);
MP4_Aud_Extr_Status MP4_ExtrAudio_GetAudFrameDur(STMp4Parser *pstMp4Parser, kal_uint32 *puAudFrameDur);

/* Progressive Download Profile */
MP4_Parser_Status MP4_GetMdatBoxOffset(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL, kal_uint32 *puMetaOffset);
MP4_Parser_Status MP4_IsPDProfile(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL, kal_bool *pfPD);
MP4_Parser_Status MP4_Audio_GetAvailableDur(STMp4Parser *pstMp4Parser, kal_uint32 *puAudioDuration );
MP4_Parser_Status MP4_Video_GetAvailableDur(STMp4Parser *pstMp4Parser, kal_uint32 *puVideoDuration);
MEDIA_STATUS_CODE MP4_Video_FrameAvailable(STMp4Parser * pstMp4Parser);

MP4_Parser_Status MP4_MetaHasAudioTrack(STMp4Parser *pstMp4Parser, kal_bool *pfAudTrack);
MP4_Parser_Status MP4_MetaHasVideoTrack(STMp4Parser *pstMp4Parser, kal_bool *pfVidTrack);
MP4_Parser_Status MP4_Meta_Estimate_FPS(STMp4Parser *pstMp4Parser, kal_uint32 *uFPS);
#endif

