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
 * daf_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   DAF playback driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "fsal.h"
#include "l1sp_trc.h"
#include "aud_daf_parser.h"

//#define DEBUG_DUMP_LOG
//#define MUSICAM_DECODE

#ifdef DAF_DECODE

#ifdef MUSICAM_DECODE

#ifdef DEBUG_DUMP_LOG
#define  DAF_CHECKSUM_MAX_SIZE  20480
kal_uint16 dafChecksumInfo[DAF_CHECKSUM_MAX_SIZE];
kal_uint32 dafDebugCnt = 0xFFFFFFFF;
static kal_uint16 _file_name[128];
static uint32 _data_written;
static uint8  _dbg_str[128];
static FS_HANDLE  _file_handle = 0;
#endif // #ifdef DEBUG_DUMP_LOG

#endif // #ifdef MUSICAM_DECODE

extern struct { // to accelerate Real-Resuming
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

#define DAF_STATE_PLAY         1
#define DAF_STATE_PAUSE        2
#define DAF_STATE_IDLE         3
#define MAX_FRAME_CHECK_LEN    (2*1024) // MAX search length of Frame Header Sync.

#if defined(MT6225) || defined(MT6227) || defined(MT6228)|| defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M)
#define DAF_PAGE_NUM 0
#else
#define DAF_PAGE_NUM 2
#endif

#define DAF_MAX_DATA_REQUESTED 1024
#define MAX_CACHE_ENTRIES      254

typedef struct {
   kal_uint32 start_offset[MAX_CACHE_ENTRIES];
   kal_uint32 accumulated_frames[MAX_CACHE_ENTRIES];
   kal_uint32 total_frame;
   kal_uint16 frames_per_cache;
   kal_uint16 valid_cache_number;
   kal_uint16 current_cache_index;
} AudioCacheTable;

#define XING_SUPPORT

#if defined XING_SUPPORT
#define FRAMES_FLAG     0x0001
#define BYTES_FLAG      0x0002
#define TOC_FLAG        0x0004
#define VBR_SCALE_FLAG  0x0008

#define FRAMES_AND_BYTES (FRAMES_FLAG | BYTES_FLAG)

// structure to receive extracted header, toc may be NULL
typedef struct {
    kal_int32   h_id;       // from MPEG header, 0=MPEG2, 1=MPEG1
    kal_int32   samprate;   // determined from MPEG header
    kal_int32   flags;      // from Xing header data
    kal_int32   frames;     // total bit stream frames from Xing header data
    kal_int32   bytes;      // total bit stream bytes from Xing header data
    kal_int32   vbr_scale;  // encoded vbr scale from Xing header data
    kal_uint8   toc[100];  // pointer to unsigned char toc_buffer[100]
                         // may be NULL if toc not desired
}   XHEADDATA;
#endif // #if defined XING_SUPPORT

typedef struct mh_internal {
   MHdl             mh;
   STFSAL           *pstFSAL;
   audInfoStruct    *description;
   kal_uint8        buf[DAF_MAX_DATA_REQUESTED];
   kal_uint8        bCacheHeader[5];
   kal_uint8        bCacheHeaderNum;
   kal_bool         fReadHeader;
   kal_bool         isStreaming;
   kal_bool         DAF_Decode_EOF;
   kal_uint32       fileOffset;
   kal_uint32       lastFrameOffset;
   kal_uint32       resumeFrameOffset;
   kal_uint32       uFileSize;
   kal_uint32       uID3V2Size;
   kal_uint32       uSampleRate;
   kal_uint32       uDurUpdateThd;
   kal_int32        DAF_DSP_Data_Cnt;
   kal_uint16       DAF_DSP_Write_Idx;
   kal_uint16       wDspReadIdx;
   Media_Event      end_status;
   AudioCacheTable  *AudioCacheTbl;
   kal_uint64       uSamplesPerFrame;
   kal_uint64       uCurFrame;
   kal_uint64       frameDur; // in ms * 10E-6
#if defined XING_SUPPORT
   XHEADDATA        stXing;
   kal_bool         fXing; // bit0: checked ? bit1: Xing Header exist ?
#endif // #if defined XING_SUPPORT
} dafMediaHdl;

#ifdef MUSICAM_DECODE
const uint16 DAF_BIT_RATE_TABLE_L2_V1[15]={1, 32, 48, 56, 64, 80, 96, 112,
                                            128, 160, 192, 224, 256, 320, 384};
#endif // #ifdef MUSICAM_DECODE

const uint16 DAF_BIT_RATE_TABLE_V1[15]={1, 32, 40, 48, 56, 64, 80, 96, 112,
                                            128, 160, 192, 224, 256, 320};
const uint16 DAF_BIT_RATE_TABLE_V2[15]={1, 8, 16, 24, 32, 40, 48, 56, 64, 80,
                                            96, 112, 128, 144, 160};
static const uint16 ASP_FS_TABLE[3][3]={ {0x11,0x12,0x00},
                                         {0x21,0x22,0x20},
                                         {0x41,0x42,0x40}};

static kal_uint32 dafGetMinFrameSize( kal_uint32 uSampleRate )
{
   kal_uint32 uMinFSize;
   
   switch( uSampleRate ){
      case 48000:
                   uMinFSize = 96;
                   break;
      case 44100:
                   uMinFSize = 104;
                   break;
      case 32000:
                   uMinFSize = 144;
                   break;
      case 24000:
                   uMinFSize = 24;
                   break;
      case 22050:
                   uMinFSize = 26;
                   break;
      case 16000:
                   uMinFSize = 36;
                   break;
      case 12000:
                   uMinFSize = 48;
                   break;
      case 11025:
                   uMinFSize = 52;
                   break;
      case 8000:
                   uMinFSize = 72;
                   break;
      
      default:
                   uMinFSize = 24;
   }
   
   return uMinFSize;
}

static kal_int32 dafChkFrameLen(uint16 wFHdrW1, uint16 wFHdrW2, int16* wFrameLen)
{
   kal_uint16 MPEGver;
   kal_int32  bit_rate, sample_rate, samplePerFrame;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif // #ifdef MUSICAM_DECODE

   MPEGver = (wFHdrW1>>11) & 3;         /* check MPEG audio version ID */
   sample_rate = (wFHdrW2 >> 2) & 3;    /* sampling rate frequency index */

   /* check sampling rate */
   if( MPEGver == 3 && sample_rate == 0 )         /* MPEG1, 44100 */
      sample_rate = 44100;
   else if( MPEGver == 3 && sample_rate == 1 )    /* MPEG1, 48000 */
      sample_rate = 48000;
   else if( MPEGver == 3 && sample_rate == 2 )    /* MPEG1, 32000 */
      sample_rate = 32000;
   else if( MPEGver == 2 && sample_rate == 0 )    /* MPEG2, 22050 */
      sample_rate = 22050;
   else if( MPEGver == 2 && sample_rate == 1 )    /* MPEG2, 24000 */
      sample_rate = 24000;
   else if( MPEGver == 2 && sample_rate == 2 )    /* MPEG2, 16000 */
      sample_rate = 16000;
   else if( MPEGver == 0 && sample_rate == 0 )    /* MPEG2.5, 11025 */
      sample_rate = 11025;
   else if( MPEGver == 0 && sample_rate == 1 )    /* MPEG2.5, 12000 */
      sample_rate = 12000;
   else if( MPEGver == 0 && sample_rate == 2 )    /* MPEG2.5, 8000 */
      sample_rate = 8000;

#ifdef MUSICAM_DECODE
   if(layer == 1){ // Layer III
#endif // #ifdef MUSICAM_DECODE
   /* check bit rate */
   if( MPEGver == 3 ){                          /* MPEG1 */
      bit_rate = DAF_BIT_RATE_TABLE_V1[(wFHdrW2 >> 4) & 0x0F];
      *wFrameLen = (int16)(144*bit_rate*1000/sample_rate);
      samplePerFrame = 1152000;
   }else{                                    /* MPEG2, MPEG2.5 */
      bit_rate = DAF_BIT_RATE_TABLE_V2[(wFHdrW2 >> 4) & 0x0F];
      *wFrameLen = (int16)(72*bit_rate*1000/sample_rate);
      samplePerFrame = 576000;
    }
#ifdef MUSICAM_DECODE
   }else if(layer == 2){ // Layer II
      if( MPEGver == 3 )                          /* MPEG1 */
       bit_rate = DAF_BIT_RATE_TABLE_L2_V1[(wFHdrW2 >> 4) & 0x0F];
      else
       bit_rate = DAF_BIT_RATE_TABLE_V2[(wFHdrW2 >> 4) & 0x0F];
       *wFrameLen = (int16)(144*bit_rate*1000/sample_rate);
       samplePerFrame = 1152000;
   }else{
      return 0;
   }
#endif // #ifdef MUSICAM_DECODE

   return ( samplePerFrame / sample_rate ); // frame duration
}

static void dafUpdateInfo(dafMediaHdl *ihdl, uint16 wFHdrW1, uint16 wFHdrW2)
{
   kal_uint16 MPEGver;
   kal_int32  sample_rate;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif // #ifdef MUSICAM_DECODE

   MPEGver = (wFHdrW1>>11) & 3;         /* check MPEG audio version ID */
   sample_rate = (wFHdrW2 >> 2) & 3;    /* sampling rate frequency index */

   /* check sampling rate */
   if( MPEGver == 3 && sample_rate == 0 )         /* MPEG1, 44100 */
      sample_rate = 44100;
   else if( MPEGver == 3 && sample_rate == 1 )    /* MPEG1, 48000 */
      sample_rate = 48000;
   else if( MPEGver == 3 && sample_rate == 2 )    /* MPEG1, 32000 */
      sample_rate = 32000;
   else if( MPEGver == 2 && sample_rate == 0 )    /* MPEG2, 22050 */
      sample_rate = 22050;
   else if( MPEGver == 2 && sample_rate == 1 )    /* MPEG2, 24000 */
      sample_rate = 24000;
   else if( MPEGver == 2 && sample_rate == 2 )    /* MPEG2, 16000 */
      sample_rate = 16000;
   else if( MPEGver == 0 && sample_rate == 0 )    /* MPEG2.5, 11025 */
      sample_rate = 11025;
   else if( MPEGver == 0 && sample_rate == 1 )    /* MPEG2.5, 12000 */
      sample_rate = 12000;
   else if( MPEGver == 0 && sample_rate == 2 )    /* MPEG2.5, 8000 */
      sample_rate = 8000;

   ihdl->uSampleRate = sample_rate;

#ifdef MUSICAM_DECODE
   if(layer == 1){ // Layer III
#endif // #ifdef MUSICAM_DECODE
      /* check bit rate */
      if( MPEGver == 3 ){                          /* MPEG1 */
         ihdl->uSamplesPerFrame = 1152;
      }else{                                    /* MPEG2, MPEG2.5 */
         ihdl->uSamplesPerFrame = 576;
       }
#ifdef MUSICAM_DECODE
   }else if(layer == 2){ // Layer II
       ihdl->uSamplesPerFrame = 1152;
   }
#endif // #ifdef MUSICAM_DECODE

   ihdl->frameDur = ihdl->uSamplesPerFrame * 1000000000 / (kal_uint64) ihdl->uSampleRate;
}

static kal_bool dafReachNextFrame(dafMediaHdl *ihdl, uint16 *wFHdrW1, uint16 *wFHdrW2)
{
   kal_uint32 nextFrameOffset = 0;
   kal_int32  uMaxCheckLen;
   kal_uint32 private_bit = 0;
   kal_int16  frame_length = 0;
   kal_uint8  *pbBuf;
   kal_uint8  *pbHeader;

   pbBuf = (kal_uint8*)get_ctrl_buffer( MAX_FRAME_CHECK_LEN );
   pbHeader = pbBuf;
   uMaxCheckLen = autGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset, MAX_FRAME_CHECK_LEN, pbBuf);

   if( uMaxCheckLen <= 4){
      free_ctrl_buffer(pbBuf);
      return KAL_FALSE;
   }

   while(1)
   {
      kal_uint16 w1, w2;      
      kal_uint8  *pbHeaderTmp;

      if(nextFrameOffset > uMaxCheckLen){
         free_ctrl_buffer(pbBuf);
         return KAL_FALSE;
      }

      w1 = (uint16)pbHeader[0] | ((uint16)pbHeader[1] << 8);
      w2 = (uint16)pbHeader[2] | ((uint16)pbHeader[3] << 8);
      private_bit = (kal_uint32) (pbHeader[2]& 0x01);
#ifdef MUSICAM_DECODE
      if( ((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
                      && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C)){
#else
      if( ((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
                      && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C)){
#endif // #ifdef MUSICAM_DECODE
         dafChkFrameLen(w1, w2, &frame_length);
         dafUpdateInfo(ihdl, w1, w2);
         if(0 == frame_length){
            ihdl->fileOffset++;
            nextFrameOffset++;
            pbHeader++;
            continue;
         }

         if( (nextFrameOffset+frame_length) > uMaxCheckLen){
            free_ctrl_buffer(pbBuf);
            return KAL_FALSE;
         }

         pbHeaderTmp = pbHeader+frame_length;

         w1 = (uint16)pbHeaderTmp[1] | ((uint16)pbHeaderTmp[2] << 8);
         w2 = (uint16)pbHeaderTmp[3] | ((uint16)pbHeaderTmp[4] << 8);
#ifdef MUSICAM_DECODE
         if( ((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
                      && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C)
                      && (private_bit == (kal_uint32) (pbHeaderTmp[3]& 0x01)) ){
#else
         if( ((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
                      && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C)
                      && (private_bit == (kal_uint32) (pbHeaderTmp[3]& 0x01)) ){
#endif // #ifdef MUSICAM_DECODE
            *wFHdrW1 = w1;
            *wFHdrW2 = w2;
            free_ctrl_buffer(pbBuf);
            return KAL_TRUE;
         }

         w1 = (uint16)pbHeaderTmp[0] | ((uint16)pbHeaderTmp[1] << 8);
         w2 = (uint16)pbHeaderTmp[2] | ((uint16)pbHeaderTmp[3] << 8);
#ifdef MUSICAM_DECODE
         if( ((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
                      && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C)
                      && (private_bit == (kal_uint32) (pbHeaderTmp[2]& 0x01)) ){
#else
         if( ((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
                      && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C)
                      && (private_bit == (kal_uint32) (pbHeaderTmp[2]& 0x01)) ){
#endif // #ifdef MUSICAM_DECODE
            *wFHdrW1 = w1;
            *wFHdrW2 = w2;
            free_ctrl_buffer(pbBuf);
            return KAL_TRUE;     /* Hit */
         }
      }
      ihdl->fileOffset++;
      nextFrameOffset++;
      pbHeader++;
   }
}

static kal_int32 dafGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   kal_uint32 file_size, data_size;

   FSAL_GetFileSize(pstFSAL, &file_size);
   data_size = file_size - fileOffset;

   if(data_size <= num_bytes){  // EOF
      num_bytes = data_size;
   }

   FSAL_Seek( pstFSAL, fileOffset);
   if(FSAL_Read_Bytes( pstFSAL, ptr, num_bytes) != FSAL_OK)
      return -1; // Playback should be terminated

   return num_bytes;
}

static kal_int32 dafGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf)
{
   kal_uint32 uDataSize, uFileSize, uCurPos;

   FSAL_GetCurPos(pstFSAL, &uCurPos);
   FSAL_GetFileSize(pstFSAL, &uFileSize);
   uDataSize = uFileSize - uCurPos;

   if(uDataSize <= uLen){
      uLen = uDataSize;
   }

   if(FSAL_Read_Bytes( pstFSAL, pbBuf, uLen) != FSAL_OK)
      return -1;

   return uLen;
}

static void dafProcessCache(dafMediaHdl *ihdl, kal_int32 processCacheCnt)
{
   kal_uint32  i, k, uCurPos, frames_per_cache, valid_cache_number, current_cache_index, temp_offset, uOffset, buf_len;
   kal_uint8   *pbHeader;
   kal_int32   uCnt, uFrameCnt;

   ihdl->mh.GetWriteBuffer((MHdl*)ihdl, &pbHeader, &buf_len);
   current_cache_index = (kal_uint32)ihdl->AudioCacheTbl->current_cache_index;
   valid_cache_number = (kal_uint32)ihdl->AudioCacheTbl->valid_cache_number;
   frames_per_cache = (kal_uint32)ihdl->AudioCacheTbl->frames_per_cache;
   temp_offset = ihdl->AudioCacheTbl->start_offset[current_cache_index];

	if(current_cache_index == valid_cache_number-1){
	   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FINISH_RETURN, MEDIA_FORMAT_DAF );
	   return; // cache table finished
	}

   FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);

   uCnt = 0;
   uFrameCnt = 0;
   uOffset = 0;
   for (i=processCacheCnt; i != 0; i--) {
	   for (k=0; k < frames_per_cache; k++){
		    kal_uint16  w1, w2;
	       kal_int16   frame_length;
	       kal_uint32  fhOff=0;

          if(!uCnt){
		       if( (uCnt = dafGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, temp_offset, buf_len, pbHeader)) < 5){
		          valid_cache_number = current_cache_index + 1;
			       FSAL_Seek( ihdl->pstFSAL, uCurPos);
                ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_END, MEDIA_FORMAT_DAF, ihdl->AudioCacheTbl->total_frame);
                return;
		       }
		    }

          w1 = (uint16)pbHeader[1+uOffset] | ((uint16)pbHeader[2+uOffset] << 8);
          w2 = (uint16)pbHeader[3+uOffset] | ((uint16)pbHeader[4+uOffset] << 8);
#ifdef MUSICAM_DECODE
          if( !(((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
                       && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#else
          if( !(((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
                       && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
             w1 = (uint16)pbHeader[0+uOffset] | ((uint16)pbHeader[1+uOffset] << 8);
             w2 = (uint16)pbHeader[2+uOffset] | ((uint16)pbHeader[3+uOffset] << 8);
#ifdef MUSICAM_DECODE
             if( !(((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
                          && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#else
             if( !(((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
                          && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
                   valid_cache_number = current_cache_index + 1;
			          FSAL_Seek( ihdl->pstFSAL, uCurPos);
                   ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                   ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                   ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FAILED, MEDIA_FORMAT_DAF, ihdl->AudioCacheTbl->total_frame );
                   return;
             }
		    }else{
              fhOff=1;
		     }

          if(k==0)
             ihdl->AudioCacheTbl->start_offset[current_cache_index] += fhOff;
          dafChkFrameLen(w1, w2, &frame_length);
          uOffset += (uint32)(frame_length + fhOff);
          uFrameCnt++;

		    if((uOffset+4) >= uCnt){
		       temp_offset += uOffset;
		       uCnt = 0;
		       uOffset = 0;
		    }
	   }
      if(current_cache_index){
         ihdl->AudioCacheTbl->accumulated_frames[current_cache_index]=
		   ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1]+k;
		   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_ACCFRAME, MEDIA_FORMAT_DAF, current_cache_index, ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1]+k );
		}else{
         ihdl->AudioCacheTbl->accumulated_frames[0]= k;
         kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_ACCFRAME, MEDIA_FORMAT_DAF, 0, k );
      }
		if(current_cache_index != valid_cache_number-1){
         ihdl->AudioCacheTbl->start_offset[++current_cache_index]=temp_offset+uOffset;
         kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, MEDIA_FORMAT_DAF, current_cache_index, temp_offset+uOffset );
      }

   }
   FSAL_Seek( ihdl->pstFSAL, uCurPos);
   ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
   ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
   ihdl->AudioCacheTbl->total_frame = ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1];
}

static kal_bool dafSeekProcess( MHdl *hdl, kal_uint32 num_bytes, kal_int32 startFrame, kal_int32 *frameCnt )
{
   kal_int16 frame_length;
   kal_int32  nextFrameOffset, curOffset, incOffset = 0;
   kal_int32  tmpFrameCnt = *frameCnt;

   dafMediaHdl *handle = (dafMediaHdl *) hdl;
   nextFrameOffset = (int32)handle->lastFrameOffset;

   if(handle->fReadHeader){
      int32 k, cnt;
      kal_uint16 data1, data2;
      cnt = 5 - handle->bCacheHeaderNum;
      if(cnt > num_bytes){
         uint8 *ptrCache = &handle->bCacheHeader[handle->bCacheHeaderNum];
         uint8 *ptrMB = &handle->mh.rb_base[handle->mh.read];
         cnt = num_bytes;
         handle->bCacheHeaderNum += cnt;
         for(k=0; k<cnt; k++)
            *ptrCache++ = *ptrMB++;
         return false;
      }
      {
         uint8 *ptrCache = &handle->bCacheHeader[handle->bCacheHeaderNum];
         uint8 *ptrMB = &handle->mh.rb_base[handle->mh.read];
         for(k=0; k<cnt; k++)
            *ptrCache++ = *ptrMB++;
      }
      handle->fReadHeader = false;

      data1 = (uint16)handle->bCacheHeader[0] | ((uint16)handle->bCacheHeader[1] << 8);
      data2 = (uint16)handle->bCacheHeader[2] | ((uint16)handle->bCacheHeader[3] << 8);
#ifdef MUSICAM_DECODE
      if( !(((data1 & 0x1800) != 0x0800) && (((data1 & 0xE6FF) == 0xE2FF) || ((data1 & 0xE6FF) == 0xE4FF))
                      && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#else
      if( !(((data1 & 0x1800) != 0x0800) && ((data1 & 0xE6FF) == 0xE2FF)
                      && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
         data1 = (uint16)handle->bCacheHeader[1] | ((uint16)handle->bCacheHeader[2] << 8);
         data2 = (uint16)handle->bCacheHeader[3] | ((uint16)handle->bCacheHeader[4] << 8);
#ifdef MUSICAM_DECODE
         if( !(((data1 & 0x1800) != 0x0800) && (((data1 & 0xE6FF) == 0xE2FF) || ((data1 & 0xE6FF) == 0xE4FF))
                         && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#else
         if( !(((data1 & 0x1800) != 0x0800) && ((data1 & 0xE6FF) == 0xE2FF)
                         && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
            return true;
         }
         nextFrameOffset += 1;
         incOffset += 1;
      }

      dafChkFrameLen(data1, data2, &frame_length);
      nextFrameOffset += (int32)frame_length;
      incOffset += frame_length;
      tmpFrameCnt++;
      if(tmpFrameCnt == startFrame){
         *frameCnt = tmpFrameCnt;
         handle->resumeFrameOffset += (uint32)incOffset;
         audResumeInfo.uCurOffset = handle->resumeFrameOffset;
         return true;
      }
   }

   if(nextFrameOffset >= handle->mh.rb_size){
      if(handle->mh.read == 0)
         nextFrameOffset -= handle->mh.rb_size;
      else{
         handle->lastFrameOffset = (uint32)nextFrameOffset;
         handle->resumeFrameOffset += (uint32)incOffset;
         audResumeInfo.uCurOffset = handle->resumeFrameOffset;
         *frameCnt = tmpFrameCnt;
         return false;
      }
   }
   curOffset = handle->mh.read + num_bytes;

   while(nextFrameOffset < curOffset)
   {
      kal_uint16 data1, data2;
      {
         int32 headerNum = (int32)handle->mh.rb_size - nextFrameOffset;
         if( headerNum < 5 ){
            uint32 i;
            uint8 *ptrCache = &handle->bCacheHeader[0];
            uint8 *ptrMB = &handle->mh.rb_base[handle->mh.rb_size - headerNum];
            handle->fReadHeader = true;
            headerNum = curOffset - nextFrameOffset;
            handle->bCacheHeaderNum = headerNum;
            for(i=0; i<headerNum; i++)
               *ptrCache++ = *ptrMB++;
            break;
         }
      }
      data1 = (uint16)handle->mh.rb_base[nextFrameOffset] | ((uint16)handle->mh.rb_base[nextFrameOffset+1] << 8);
      data2 = (uint16)handle->mh.rb_base[nextFrameOffset+2] | ((uint16)handle->mh.rb_base[nextFrameOffset+3] << 8);
#ifdef MUSICAM_DECODE
      if( !(((data1 & 0x1800) != 0x0800) && (((data1 & 0xE6FF) == 0xE2FF) || ((data1 & 0xE6FF) == 0xE4FF))
                      && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#else
      if( !(((data1 & 0x1800) != 0x0800) && ((data1 & 0xE6FF) == 0xE2FF)
                      && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
         data1 = (uint16)handle->mh.rb_base[nextFrameOffset+1] | ((uint16)handle->mh.rb_base[nextFrameOffset+2] << 8);
         data2 = (uint16)handle->mh.rb_base[nextFrameOffset+3] | ((uint16)handle->mh.rb_base[nextFrameOffset+4] << 8);
#ifdef MUSICAM_DECODE
         if( !(((data1 & 0x1800) != 0x0800) && (((data1 & 0xE6FF) == 0xE2FF) || ((data1 & 0xE6FF) == 0xE4FF))
                         && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#else
         if( !(((data1 & 0x1800) != 0x0800) && ((data1 & 0xE6FF) == 0xE2FF)
                         && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
            handle->resumeFrameOffset += (uint32)incOffset;
            audResumeInfo.uCurOffset = handle->resumeFrameOffset;
            *frameCnt = tmpFrameCnt;
            return true;
         }
         nextFrameOffset += 1;
         incOffset += 1;
      }

      dafChkFrameLen(data1, data2, &frame_length);

      nextFrameOffset += (int32)frame_length;
      incOffset += frame_length;
      tmpFrameCnt++;
      if(tmpFrameCnt == startFrame){
         *frameCnt = tmpFrameCnt;
         handle->resumeFrameOffset += (uint32)incOffset;
         audResumeInfo.uCurOffset = handle->resumeFrameOffset;
         return true;
      }
   }
   handle->lastFrameOffset = (uint32)nextFrameOffset;
   handle->resumeFrameOffset += (uint32)incOffset;
   audResumeInfo.uCurOffset = handle->resumeFrameOffset;
   *frameCnt = tmpFrameCnt;
   return false;
}

static kal_bool dafSeek( dafMediaHdl *ihdl, kal_bool cacheEnable )
{   /* file offset must be aligned the first frame header */
   kal_int32  cnt, startFrame;
   kal_uint8  *pbHeader;
   kal_uint32 buf_len;

   ihdl->mh.read = 0;
   ihdl->mh.write = 0;
   ihdl->mh.GetWriteBuffer((MHdl*)ihdl, &pbHeader, &buf_len);

   ASSERT(ihdl->frameDur != 0); // memory corrupted
   startFrame = (kal_uint64)ihdl->mh.start_time * 1000000 / ihdl->frameDur; // calculate start frame count

   /// Process cache table
   if((ihdl->AudioCacheTbl != 0) && cacheEnable){
      kal_uint16 start_index, end_index;
      start_index = 0;
      end_index = ihdl->AudioCacheTbl->current_cache_index;
      /// Binary Search
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index + end_index) / 2;
         if (startFrame > (kal_int32)ihdl->AudioCacheTbl->accumulated_frames[middle_index])
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      /// Linear Search

      if (start_index) {
         cnt = ihdl->AudioCacheTbl->accumulated_frames[start_index];
      } else {
         cnt = 0;
      }

      {
         kal_uint16  w1, w2;
	      kal_int16   frame_length;
	      kal_uint32  fhOff, uCnt, uOffset;
	      kal_uint32  temp_offset;

	      if(start_index)
	         temp_offset = ihdl->AudioCacheTbl->start_offset[start_index+1];
	      else
	         temp_offset = ihdl->AudioCacheTbl->start_offset[0];

	      uCnt = 0;
	      uOffset = 0;

         for (; cnt < startFrame; cnt++) {
            fhOff = 0;
            if(!uCnt){
               if( (uCnt = dafGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, temp_offset, buf_len, pbHeader)) < 5){
                  break;
               }
            }

            w1 = (uint16)pbHeader[1+uOffset] | ((uint16)pbHeader[2+uOffset] << 8);
            w2 = (uint16)pbHeader[3+uOffset] | ((uint16)pbHeader[4+uOffset] << 8);
#ifdef MUSICAM_DECODE
            if( !(((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
                         && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#else
            if( !(((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
                         && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
               w1 = (uint16)pbHeader[0+uOffset] | ((uint16)pbHeader[1+uOffset] << 8);
               w2 = (uint16)pbHeader[2+uOffset] | ((uint16)pbHeader[3+uOffset] << 8);
#ifdef MUSICAM_DECODE
               if( !(((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
                            && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#else
               if( !(((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
                            && ((w2 & 0x00F0) != 0x00F0)&& ((w2 & 0x000C) != 0x000C))){
#endif // #ifdef MUSICAM_DECODE
                     break;
               }
		      }else{
                fhOff=1;
		       }

            dafChkFrameLen(w1, w2, &frame_length);
            uOffset += (uint32)(frame_length + fhOff);

            if((uOffset+4) >= uCnt){
               temp_offset += uOffset;
               uCnt = 0;
               uOffset = 0;
            }
         }
         ihdl->fileOffset = temp_offset + uOffset;
	      ihdl->resumeFrameOffset = temp_offset + uOffset; // last frame offset aligned frame boundary
	      audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
      }
   } else {
	   kal_uint32 tmpFileOffset = ihdl->fileOffset;
      FSAL_Seek( ihdl->pstFSAL, tmpFileOffset);
      ihdl->resumeFrameOffset = tmpFileOffset;
      audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
      cnt = 0;
      if(startFrame != 0){
         while(startFrame){
            kal_int32 num_bytes;
            num_bytes = dafGetBytes( (MHdl*)ihdl, ihdl->pstFSAL, ihdl->mh.rb_size, ihdl->mh.rb_base);
            if(num_bytes == ihdl->mh.rb_size){
               ihdl->mh.write = (ihdl->mh.rb_size -1);
               ihdl->mh.read = 0;
               if (dafSeekProcess( (MHdl*)ihdl, (uint32)(ihdl->mh.rb_size -1), startFrame, &cnt ))
                  break;
               ihdl->mh.read = (ihdl->mh.rb_size-1);
               ihdl->mh.write = 0;
               if (dafSeekProcess( (MHdl*)ihdl, 1, startFrame, &cnt ))
                  break;
            }else{
                ihdl->mh.write = num_bytes;
                ihdl->mh.read = 0;
                dafSeekProcess( (MHdl*)ihdl, (uint32)num_bytes, startFrame, &cnt );
                break;
             }
         }

         {
            ihdl->lastFrameOffset = 0;
            ihdl->fReadHeader = false;
            ihdl->bCacheHeaderNum = 0;
            ihdl->mh.write = 0;
            tmpFileOffset = ihdl->resumeFrameOffset;
            ihdl->fileOffset = tmpFileOffset;
         }
      }
   }

   if (cnt != startFrame){
      ihdl->mh.start_time = ihdl->mh.current_time = (kal_uint64)cnt * ihdl->frameDur / 1000000; // update start time
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, MEDIA_FORMAT_DAF, startFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_FALSE;
   }else{
       kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, MEDIA_FORMAT_DAF, startFrame, ihdl->fileOffset, ihdl->mh.start_time);
       return KAL_TRUE;
    }
}

static void dafIncTime( MHdl *hdl, uint32 num_bytes )
{
  (void)hdl;
  (void)num_bytes;
  return; // dummy function
}

static kal_int32 dafGetDSPDataCnt( dafMediaHdl *ihdl, kal_uint16 dspWriteIdx )
{
   int32 I;
   uint16 rb_w;

   if(dspWriteIdx == 0xFFFF){
      rb_w = *DAF_MCU_WRITE_PTR;
      ihdl->DAF_DSP_Write_Idx = rb_w;
   }else
      rb_w = dspWriteIdx;

   do {
      I = (int32)*DAF_DSP_READ_PTR;
   } while( I != (int32)*DAF_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   return (ihdl->mh.dsp_rb_size - I);  // total data size in word
}

static void dafWriteZero( dafMediaHdl *ihdl )
{
   int32 I, count, len;
   uint16 rb_w;

   rb_w = *DAF_MCU_WRITE_PTR;

   do {
      I = (int32)*DAF_DSP_READ_PTR;
   } while( I != (int32)*DAF_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   count = (int32)(ihdl->mh.dsp_rb_end - rb_w);

   if(count > I)
      count = I;

   len = I;

   DSP_WRITE( DSP_PM_ADDR(DAF_PAGE_NUM, rb_w), 0 );
   for( I = 1; I < count; I++ )
      DSP_WRITE( IDMA_SHORT_ADDR, 0 );

   rb_w += (uint16)count;
   if( rb_w >= ihdl->mh.dsp_rb_end )
      rb_w = ihdl->mh.dsp_rb_base;
   *DAF_MCU_WRITE_PTR = rb_w;

   count = len - count;
   if( count > 0 ) {
     DSP_WRITE( DSP_PM_ADDR(DAF_PAGE_NUM, rb_w), 0 );
     for( I = 1; I < count; I++ )
        DSP_WRITE( IDMA_SHORT_ADDR, 0 );

     *DAF_MCU_WRITE_PTR = rb_w + (uint16)count;
   }
}

static kal_int32 dafGetDSPIncOffset( dafMediaHdl *ihdl )
{
   int32 I;
   uint16 rb_r;

   rb_r = ihdl->wDspReadIdx;

   do {
      I = (int32)*DAF_DSP_READ_PTR;
   } while( I != (int32)*DAF_DSP_READ_PTR );
   
   ihdl->wDspReadIdx = I;

   I = I - (int32)rb_r;
   if( I < 0 )
      I += ihdl->mh.dsp_rb_size;

   return (I<<1);  // total data size in byte
}

static void dafHisr( void *data )
{
   dafMediaHdl *ihdl = (dafMediaHdl *)data;

   if( ihdl->end_status == MEDIA_TERMINATED )
      return;

   if( *DAF_MAIN_CONTROL == 0 ) {  // DSP in idle state
   	  if (ihdl->end_status == MEDIA_STOP_TIME_UP){
   	  	kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_IDLE_STATE ");
        mhdlException( (MHdl*)ihdl, MEDIA_STOP_TIME_UP );
   	  }else{
          kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_IDLE_STATE ");
          mhdlException( (MHdl*)ihdl, MEDIA_END );
      }
      ihdl->end_status = MEDIA_TERMINATED;
      return;
   }

  if( ihdl->end_status == MEDIA_END || ihdl->end_status == MEDIA_STOP_TIME_UP )
      return;

// update current time and file offset
   if(ihdl->wDspReadIdx != 0xFFFF){
      kal_int32 iFrameOffset;
      iFrameOffset = dafGetDSPIncOffset( ihdl );
      if(iFrameOffset){ // Don't increase current time as buffer underflow
         ihdl->uCurFrame++;
         ihdl->mh.current_time = ihdl->uCurFrame * ihdl->frameDur / 1000000;
         ihdl->resumeFrameOffset += iFrameOffset;
         audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
      }
      
      if(ihdl->AudioCacheTbl != 0){  // update cache table
         kal_uint32 uAcumFrms, uTotalFrames, uCurCacheIdx;
         uCurCacheIdx = ihdl->AudioCacheTbl->current_cache_index;
         if(uCurCacheIdx)
            uAcumFrms = ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx-1];
         else
            uAcumFrms = 0;

         uTotalFrames = ihdl->uCurFrame;

         if((uTotalFrames-uAcumFrms)==ihdl->AudioCacheTbl->frames_per_cache){
            if(uCurCacheIdx){
               ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx] = uTotalFrames;
               kal_prompt_trace( MOD_L1SP, " DAF: Cache_AccFrame = %d, idx = %d", uTotalFrames, uCurCacheIdx);
		      }else{
               ihdl->AudioCacheTbl->accumulated_frames[0]= uTotalFrames;
               kal_prompt_trace( MOD_L1SP, " DAF: Cache_AccFrame = %d, idx = %d", uTotalFrames, 0);
            }
		      if(uCurCacheIdx != ihdl->AudioCacheTbl->valid_cache_number-1){
               ihdl->AudioCacheTbl->start_offset[++uCurCacheIdx]=ihdl->resumeFrameOffset;
               kal_prompt_trace( MOD_L1SP, " DAF: Cache_StrOffset = %d, idx = %d", ihdl->resumeFrameOffset, uCurCacheIdx);
               ihdl->AudioCacheTbl->current_cache_index = uCurCacheIdx;
               ihdl->AudioCacheTbl->total_frame = ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx-1];
            }
         }
      }
   }

   if( ihdl->mh.dsp_rb_base == 0 ) {   // DSP RingBuf initialization
      ihdl->mh.dsp_rb_base = *DAF_FIFO_BASE;
      ihdl->mh.dsp_rb_size = *DAF_FIFO_LENGTH;
      ihdl->mh.dsp_rb_end = ihdl->mh.dsp_rb_base + ihdl->mh.dsp_rb_size;
      ihdl->wDspReadIdx = *DAF_DSP_READ_PTR;
   }

#ifdef MUSICAM_DECODE
#ifdef DEBUG_DUMP_LOG
   { // log checksum info.
   	  if(dafDebugCnt == 0xFFFFFFFF){
   	     dafDebugCnt = 0;
   	  }

   	  if(*MP2_CHECKSUM_ENABLE == 1){
   	     *MP2_CHECKSUM_ENABLE = 0;
   	     if(dafDebugCnt < DAF_CHECKSUM_MAX_SIZE)
              dafChecksumInfo[dafDebugCnt++] = *MP2_CHECK_SUM;
        }
   }
#endif // #ifdef DEBUG_DUMP_LOG
#endif // #ifdef MUSICAM_DECODE

   if(!ihdl->DAF_Decode_EOF)
      autWriteDataToDSP((MHdl*)ihdl, (uint16*)DAF_MCU_WRITE_PTR, (uint16*)DAF_DSP_READ_PTR, DAF_PAGE_NUM, dafIncTime);
   else{
      kal_int32 data_Cnt;
      data_Cnt = dafGetDSPDataCnt(ihdl, ihdl->DAF_DSP_Write_Idx);
      if(ihdl->DAF_DSP_Data_Cnt >= data_Cnt)
         ihdl->DAF_DSP_Data_Cnt -= (ihdl->DAF_DSP_Data_Cnt - data_Cnt);
      else
         ihdl->DAF_DSP_Data_Cnt = 0;
      if(ihdl->DAF_DSP_Data_Cnt <= 0){
         ihdl->end_status = MEDIA_END;
         if( *DAF_MAIN_CONTROL == 1 )
            *DAF_MAIN_CONTROL = 7;
         kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_END_STATE ");
      }else
         dafWriteZero(ihdl);

      return;
   }

   if( ihdl->mh.current_time >= ihdl->mh.stop_time ) {
      ihdl->end_status = MEDIA_STOP_TIME_UP;
      if( *DAF_MAIN_CONTROL == 1 )
         *DAF_MAIN_CONTROL = 7;
      kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_STOP_TIME_UP_STATE ");
      return;
   }

   if( (ihdl->mh.GetDataCount((MHdl*)ihdl) == 0) && ihdl->mh.eof ) {
      ihdl->DAF_DSP_Data_Cnt = dafGetDSPDataCnt(ihdl, 0xFFFF);
      if(ihdl->DAF_DSP_Data_Cnt){
         SSHdl *my_ss_handle = ihdl->mh.ss_handle;
         ihdl->DAF_Decode_EOF = KAL_TRUE;
         if( is_SSHdl_valid(my_ss_handle) )
            my_ss_handle->Flush(my_ss_handle);
         
         dafWriteZero(ihdl);
         return;
      }else {
         ihdl->end_status = MEDIA_END;
         if( *DAF_MAIN_CONTROL == 1 )
            *DAF_MAIN_CONTROL = 7;
         kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_END_STATE ");
      }

   }

   mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
}

#if defined(MT6223) || defined(MT6223P)
// Download PM table value to fix DSP bug, asked by Sammy
static const int16 DAF_PM_Table[6] = {0x0595, 0x10b4, 0x1bb4, 0x267d, 0x30fb, 0x3b1a};
#endif

static void dafOpenDevice( dafMediaHdl *ihdl , uint16 ver, uint16 data1, kal_bool DDFlag)
{
   ihdl->end_status = MEDIA_NONE; // Clear for streaming case
   ihdl->mh.dsp_rb_base = 0;

   KT_StopAndWait();
   TONE_StopAndWait();
   
#ifdef MUSICAM_DECODE
#ifdef DEBUG_DUMP_LOG
   *(volatile unsigned short int *)0x8000f000 = 0x8070;
   *(volatile unsigned short int *)0x801201B0 |= 0x0030;
   *(volatile unsigned short int *)0x80120210 |= 0x0f00;
   *((volatile kal_uint16 *)(0x80300028)) = 1;
#endif // #ifdef DEBUG_DUMP_LOG
#endif // #ifdef MUSICAM_DECODE

   *DP_AUDIO_CTRL2 |= DP_PCM_R_DIS;
   mhdlDisallowSleep( (MHdl*)ihdl );
   ASSERT(*DAF_MAIN_CONTROL == 0);
 // DSP colleague provided the following control procedure
   *DAF_MAIN_CONTROL   = 3;

#ifdef MUSICAM_DECODE
   *DP_AUDIO_FLEXI_CTRL |= 1; // for mp2
#endif // #ifdef MUSICAM_DECODE

   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );

   {
      if(DDFlag){   /* DSP code dynamic download */
#ifdef MUSICAM_DECODE
      	if(ihdl->mh.mediaType == MEDIA_FORMAT_MUSICAM){
      	   DSP_DynamicDownload( DDID_MUSICAM );
      	}else
#endif // #ifdef MUSICAM_DECODE
             DSP_DynamicDownload( DDID_DAF );
      }

#if defined(MT6223) || defined(MT6223P)
      // Download PM table value to fix DSP bug, asked by Sammy
      {
         const int16 *ptr;
         volatile uint16* dsp_ptr;
         int I;
         
         dsp_ptr = DSP_DM_ADDR(1, 0x2F8A);
         ptr = DAF_PM_Table;
         for (I=5; I>=0; I--) {
            *dsp_ptr++ = *ptr++;
         }
      }
#endif

#ifdef MUSICAM_DECODE
      if(ihdl->mh.mediaType == MEDIA_FORMAT_MUSICAM)
         AM_AudioPlaybackOn( ASP_TYPE_MUSICAM, ASP_FS_TABLE[ver][data1] );
      else
#endif // #ifdef MUSICAM_DECODE
      AM_AudioPlaybackOn( ASP_TYPE_DAF, ASP_FS_TABLE[ver][data1] );

   }

   {
      kal_uint16 I;
      for( I = 0; ; I++ ) {
         if( *DAF_MAIN_CONTROL == 1 || ihdl->end_status != MEDIA_NONE || ihdl->mh.eof ){
            kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
            break;
         }
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
   ihdl->mh.state = DAF_STATE_PLAY;

}

static void dafCloseDevice( dafMediaHdl *ihdl )
{
   kal_uint32 I;

   for( I = 0; ; I++ ) {
      if( *DAF_MAIN_CONTROL == 0 )          /* DSP returns to idle state */
         break;
      if( *DAF_MAIN_CONTROL == 1 ) {
         *DAF_MAIN_CONTROL = 5;             /* give ABORT command to the DSP */
         kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      }
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
   
#ifdef MUSICAM_DECODE
   *DP_AUDIO_FLEXI_CTRL &= ~1;
#endif // #ifdef MUSICAM_DECODE

   *DP_AUDIO_CTRL2 &= ~DP_PCM_R_DIS;
   AM_AudioPlaybackOff( true );
   mhdlAllowSleep( (MHdl*)ihdl );
}

static Media_Status dafMFClose( MHdl *hdl )
{
   ASSERT( hdl != 0 && hdl->state != DAF_STATE_PLAY);
   if( hdl->handler != NULL )
      mhdlFinalize( hdl, DP_D2C_DAF );
   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, hdl->mediaType );

#ifdef MUSICAM_DECODE
#ifdef DEBUG_DUMP_LOG
   if (_file_handle == 0)
      ASSERT(0);

   if(dafDebugCnt == 0xFFFFFFFF)
   	dafDebugCnt = 0;

   {
   	  kal_uint32 cnt;
      for(cnt=0; cnt<dafDebugCnt;){
         kal_sprintf((void*)_dbg_str, "%.4x\n", (kal_int32)dafChecksumInfo[cnt++]);
         FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
      }

   }

   FS_Close(_file_handle);
   _file_handle = 0;

#endif // #ifdef DEBUG_DUMP_LOG
#endif // #ifdef MUSICAM_DECODE

   return MEDIA_SUCCESS;
}

static void dafProgressiveSeek( dafMediaHdl *ihdl )
{
   /// Process cache table   
   dafProcessCache(ihdl, 1);
   if((ihdl->AudioCacheTbl->valid_cache_number-1)!= 0){
      ihdl->mh.uSeekProgress = ihdl->AudioCacheTbl->current_cache_index * 100 / (ihdl->AudioCacheTbl->valid_cache_number-1);
      ihdl->mh.eSeekLastRet = MEDIA_SUCCESS;
   }else{
      ihdl->mh.uSeekProgress = 0;
      ihdl->mh.eSeekLastRet = MEDIA_SEEK_FAIL;
   }
}

static void dafMFSeek( MHdl *hdl, Media_Status *eSeekLastRet, kal_uint32 *uProgress )
{
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;

   if(hdl->uGetDurProgress == 0){
      kal_uint16 data1, data2;
    
      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;
    

      autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );
      if ( dafReachNextFrame(ihdl, &data1, &data2) == KAL_FALSE ){
         hdl->eSeekLastRet = MEDIA_BAD_FORMAT;
         return;
      }
      ihdl->AudioCacheTbl->start_offset[0]=ihdl->fileOffset;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, hdl->mediaType, 0, ihdl->fileOffset );
   }

   dafProgressiveSeek(ihdl);

   *eSeekLastRet = hdl->eSeekLastRet;
   *uProgress = hdl->uSeekProgress;
}

static void dafMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress )
{
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;

   if( 100 == hdl->uGetDurProgress ){ // cache table finished
      *eLastRet = MEDIA_SUCCESS;
      *uProgress = 100;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, hdl->mediaType, MEDIA_SUCCESS, 100 );
      return;
   }

   {
      Media_Status eSeekLastRet;
      kal_uint32 uProgress;
      dafMFSeek( hdl, &eSeekLastRet, &uProgress ); // parse fixed frames
   }
   *eLastRet = hdl->eSeekLastRet; // last result
   {
      kal_uint32 uCurPos;
      ASSERT(ihdl->uFileSize != 0);
      uCurPos = ihdl->AudioCacheTbl->start_offset[ihdl->AudioCacheTbl->current_cache_index];
      hdl->uGetDurProgress = (kal_uint64)uCurPos * (kal_uint64)100 / (kal_uint64)ihdl->uFileSize;
      if(100 == hdl->uGetDurProgress)
         hdl->uGetDurProgress -= 1; // check to see if cache index table is finished
      if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number -1 ))
         hdl->uGetDurProgress = 100;
   }

   *uProgress = hdl->uGetDurProgress;

   if( 100 == hdl->uGetDurProgress ){
      hdl->uSeekProgress = 0;
      hdl->start_time = 0;
      ihdl->fileOffset = 0;
   }
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, hdl->mediaType, *eLastRet, *uProgress );
}

static void dafMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, void *param )
{
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;

   ASSERT(((uint32)ptr & 0x03) == 0 );   /* make sure 4-byte alignment */
   ihdl->AudioCacheTbl = (AudioCacheTable *)ptr;

   if(!ihdl->uSampleRate){
      kal_uint16 data1, data2;
      autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );
      
      if ( dafReachNextFrame(ihdl, &data1, &data2) == KAL_FALSE ){
         ihdl->AudioCacheTbl->frames_per_cache = 100;
         if(!ihdl->AudioCacheTbl->valid_cache_number)
            ihdl->AudioCacheTbl->valid_cache_number = MAX_CACHE_ENTRIES;
         return;
      }
   }
   
   {
      kal_uint32 uMinFSize;
      kal_uint64 uFrames;
      uMinFSize = dafGetMinFrameSize(ihdl->uSampleRate);
      uFrames = (kal_uint64)ihdl->uFileSize / uMinFSize;
      ihdl->AudioCacheTbl->frames_per_cache = (uFrames / MAX_CACHE_ENTRIES)+1;
   }
   
   if(!ihdl->AudioCacheTbl->valid_cache_number)
      ihdl->AudioCacheTbl->valid_cache_number = MAX_CACHE_ENTRIES;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, hdl->mediaType );
}

static Media_Status dafMFPlayFile( MHdl *hdl )
{
   uint16 data1, data2, ver;
   kal_uint32 buf_len;
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;

   if(hdl->start_time || hdl->current_time){      
      ihdl->end_status = MEDIA_NONE;
      ihdl->lastFrameOffset = 0;
      ihdl->bCacheHeaderNum = 0;
      ihdl->fReadHeader = 0;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;
   }

   ihdl->fileOffset = 0;
   ihdl->DAF_Decode_EOF = KAL_FALSE;
   ihdl->wDspReadIdx = 0xFFFF;
   ihdl->DAF_DSP_Data_Cnt = 0x7FFFFFFF;

   autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );
   ihdl->uID3V2Size = ihdl->fileOffset;

   if ( dafReachNextFrame(ihdl, &data1, &data2) == KAL_FALSE )
      return MEDIA_BAD_FORMAT;

   if(ihdl->AudioCacheTbl != 0)
      ihdl->AudioCacheTbl->start_offset[0] = ihdl->fileOffset;

   ver = (data1>>11) & 3;  /* to get MPEG version */
   data1 = (data1>>9) & 3; /* to get Layer # */

#ifdef MUSICAM_DECODE
   if(data1 == 0x02)
      hdl->mediaType = MEDIA_FORMAT_MUSICAM;

   if( (ver == 0x01) || ((data1 != 0x01) && (data1 != 0x02)) ) /* Check MPEG version & Layer */
#else
   if( ver == 0x01 || data1 != 0x01 )  /* Check MPEG version & Layer III */
#endif // #ifdef MUSICAM_DECODE
      return MEDIA_BAD_FORMAT;

   data1 = (data2 >> 2) & 3;

   if(data1 == 3)   /* invalid sampling rate */
      return MEDIA_BAD_FORMAT;

   if(ver==2||ver==3) /* match lookup table to get sampling rate parameter */
      ver--;

   ihdl->uCurFrame = (kal_uint64)hdl->start_time * 1000000 / ihdl->frameDur;

   if(!hdl->fStoreFileOffset){
      FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
      if ((dafSeek(ihdl, true)==KAL_FALSE) || (ihdl->fileOffset >= ihdl->uFileSize)){ // update file offset at start frame
         return MEDIA_SEEK_EOF;
      }
   }else{
        kal_uint16 w1, w2;
        ihdl->resumeFrameOffset = audResumeInfo.uResumeFrameOffset;
        ihdl->fileOffset = ihdl->resumeFrameOffset;

        if ( dafReachNextFrame(ihdl, &w1, &w2) == KAL_FALSE ){
        	 if(hdl->eof){
        	     kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, hdl->mediaType, ihdl->uCurFrame, ihdl->fileOffset, hdl->start_time);
              mhdlException(hdl, MEDIA_END);
              return MEDIA_SUCCESS;
           }else{
               kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, hdl->mediaType, ihdl->uCurFrame, ihdl->fileOffset, hdl->start_time);
               return MEDIA_BAD_FORMAT;
            }
        }
        kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, hdl->mediaType, ihdl->uCurFrame, ihdl->fileOffset, hdl->start_time);
        ihdl->resumeFrameOffset = ihdl->fileOffset;
        audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
    }

   {  /* Fill Media Buffer */
      kal_uint8 *pBuf;
      kal_int32 num_bytes;
      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);

      num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
      if(num_bytes < 0) return MEDIA_READ_FAIL;
      ihdl->fileOffset += num_bytes;
      hdl->WriteDataDone( hdl, num_bytes );
   }
   dafOpenDevice(ihdl, ver, data1, true);

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status dafMFStop( MHdl *hdl )
{
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;

   if( hdl->state == DAF_STATE_PAUSE || hdl->state == DAF_STATE_IDLE )
      return MEDIA_SUCCESS;

   ihdl->end_status = MEDIA_TERMINATED;
   dafCloseDevice( ihdl );

   hdl->state = DAF_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status dafMFPause( MHdl *hdl )
{
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;

   ASSERT( hdl->state == DAF_STATE_PLAY );

   ihdl->end_status = MEDIA_TERMINATED;
   dafCloseDevice( ihdl );

   hdl->state = DAF_STATE_PAUSE;
   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status dafMFResumeFile( MHdl *hdl )
{
   kal_uint16 ver, data1, data2;
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;

   if( hdl->state != DAF_STATE_PAUSE )
      return MEDIA_FAIL;

   if(ihdl->DAF_Decode_EOF){
      mhdlException(hdl, MEDIA_END);
      return MEDIA_SUCCESS;
   }

   hdl->read = 0;
   hdl->write = 0;
   hdl->eof = false;
   hdl->waiting = false;
   ihdl->lastFrameOffset = 0;
   hdl->start_time = hdl->current_time;
   ihdl->fileOffset = ihdl->resumeFrameOffset;
   ihdl->wDspReadIdx = 0xFFFF;
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
   if(ihdl->uFileSize > ihdl->fileOffset){

      if ( dafReachNextFrame(ihdl, &data1, &data2) == KAL_FALSE ){
         if(hdl->eof){
            mhdlException(hdl, MEDIA_END);
            return MEDIA_SUCCESS;            
         }else{
             return MEDIA_BAD_FORMAT;
          }
      }

      ver = (data1>>11) & 3;  /* to get MPEG version */
      data1 = (data1>>9) & 3; /* to get Layer # */

#ifdef MUSICAM_DECODE
      if( (ver == 0x01) || ((data1 != 0x01) && (data1 != 0x02)) )  /* Check MPEG version & Layer III */
#else
      if( ver == 0x01 || data1 != 0x01 )  /* Check MPEG version & Layer III */
#endif // #ifdef MUSICAM_DECODE
         return MEDIA_BAD_FORMAT;

      data1 = (data2 >> 2) & 3;

      if(data1 == 3)   /* invalid sampling rate */
         return MEDIA_BAD_FORMAT;

      if(ver==2||ver==3) /* match lookup table to get sampling rate parameter */
         ver--;

      ihdl->resumeFrameOffset = ihdl->fileOffset;
      audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;

      {  /* file Media Buffer */
         kal_uint8 *pBuf;
         kal_int32 num_bytes;
         kal_uint32 buf_len;
         hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
         num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
         if(num_bytes < 0) return MEDIA_READ_FAIL;
         ihdl->fileOffset += num_bytes;
         hdl->WriteDataDone(hdl, num_bytes);
      }
      dafOpenDevice(ihdl, ver, data1, false);
   }else{
      mhdlException(hdl, MEDIA_END);
    }
   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );

   return MEDIA_SUCCESS;
}

Media_Event dafMFProcess( MHdl *hdl, Media_Event event )
{
   dafMediaHdl *ihdl = (dafMediaHdl *) hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch(event)
   {
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if( hdl->state == DAF_STATE_PLAY )
            dafCloseDevice( ihdl );
         hdl->state = DAF_STATE_IDLE;
         return event;
      case MEDIA_ERROR:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if( hdl->state == DAF_STATE_PLAY )
            dafCloseDevice( ihdl );
         hdl->state = DAF_STATE_IDLE;
         return event;
      case MEDIA_DATA_REQUEST:
         if(ihdl->isStreaming)
            return MEDIA_DATA_REQUEST;
         {
            kal_uint8 *pBuf;
            kal_uint32 buf_len;
            kal_int32 num_bytes, cnt = 0;
            do{
               hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
               if(buf_len == 0 || hdl->eof) break;
               num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
               if(num_bytes < 0) return MEDIA_READ_ERROR;
               ihdl->fileOffset += num_bytes;
               hdl->WriteDataDone( hdl, num_bytes );
            }while(++cnt < 2);
         }
         hdl->waiting = KAL_FALSE;
         
         {
            kal_uint64 uRatio;
            FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
            uRatio = (kal_uint64)ihdl->resumeFrameOffset * 100 / (kal_uint64)ihdl->uFileSize;
            if( uRatio > ihdl->uDurUpdateThd ){
               if(ihdl->uDurUpdateThd != 100)
                  ihdl->uDurUpdateThd += 20;
               return MEDIA_UPDATE_DUR;
            }
         }
         
         return MEDIA_NONE;
#if !defined(__PRODUCTION_RELEASE__)
      default:
         ASSERT(0); // should never reach here
#endif
   }
   return MEDIA_NONE;
}

static Media_Status dafMFPlayStrm( MHdl *hdl )
{
   uint16 data1, data2, ver;
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;
   ihdl->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(ihdl->pstFSAL == NULL)
      return MEDIA_FAIL;

   {
      FSAL_Status eFSALStatus;
      FSAL_Direct_SetRamFileSize(ihdl->pstFSAL, hdl->rb_size);
      eFSALStatus = FSAL_Open(ihdl->pstFSAL, hdl->rb_base, FSAL_ROMFILE);
      ASSERT(eFSALStatus == FSAL_OK);
   }

   ihdl->fileOffset = 0;

   if ( dafReachNextFrame(ihdl, &data1, &data2) == KAL_FALSE ){
      free_ctrl_buffer( ihdl->pstFSAL);
      return MEDIA_BAD_FORMAT;
   }

   ver = (data1>>11) & 3;  /* to get MPEG version */
   data1 = (data1>>9) & 3; /* to get Layer # */

#ifdef MUSICAM_DECODE
   if(data1 == 0x02)
      hdl->mediaType = MEDIA_FORMAT_MUSICAM;

   if( (ver == 0x01) || ((data1 != 0x01) && (data1 != 0x02)) ){  /* Check MPEG version & Layer III */
#else
   if( ver == 0x01 || data1 != 0x01 ){  /* Check MPEG version & Layer III */
#endif // #ifdef MUSICAM_DECODE
      free_ctrl_buffer( ihdl->pstFSAL);
      return MEDIA_BAD_FORMAT;
   }

   data1 = (data2 >> 2) & 3;

   if(data1 == 3){   /* invalid sampling rate */
      free_ctrl_buffer( ihdl->pstFSAL);
      return MEDIA_BAD_FORMAT;
   }

   if(ver==2||ver==3) /* match lookup table to get sampling rate parameter */
      ver--;

   dafOpenDevice(ihdl, ver, data1, true);
   free_ctrl_buffer( ihdl->pstFSAL);
   ihdl->pstFSAL = NULL;

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_STREAM, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status dafMFResumeStrm( MHdl *hdl )
{
   uint16 data1, data2, ver;
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;
   ihdl->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(ihdl->pstFSAL == NULL)
      return MEDIA_FAIL;

   {
      FSAL_Status eFSALStatus;
      FSAL_Direct_SetRamFileSize(ihdl->pstFSAL, hdl->rb_size);
      eFSALStatus = FSAL_Open(ihdl->pstFSAL, hdl->rb_base, FSAL_ROMFILE);
      ASSERT(eFSALStatus == FSAL_OK);
   }

   ihdl->fileOffset = hdl->read;
   if ( dafReachNextFrame(ihdl, &data1, &data2) == KAL_FALSE ){
      ihdl->fileOffset = 0;
      ihdl->mh.eof = false;
      if ( dafReachNextFrame(ihdl, &data1, &data2) == KAL_FALSE ){
         free_ctrl_buffer( ihdl->pstFSAL);
         return MEDIA_BAD_FORMAT;
      }
   }

   ver = (data1>>11) & 3;  /* to get MPEG version */
   data1 = (data1>>9) & 3; /* to get Layer # */

#ifdef MUSICAM_DECODE
   if( (ver == 0x01) || ((data1 != 0x01) && (data1 != 0x02)) ){  /* Check MPEG version & Layer III */
#else
   if( ver == 0x01 || data1 != 0x01 ){  /* Check MPEG version & Layer III */
#endif // #ifdef MUSICAM_DECODE
      free_ctrl_buffer( ihdl->pstFSAL);
      return MEDIA_BAD_FORMAT;
   }

   data1 = (data2 >> 2) & 3;

   if(data1 == 3){   /* invalid sampling rate */
      free_ctrl_buffer( ihdl->pstFSAL);
      return MEDIA_BAD_FORMAT;
   }

   if(ver==2||ver==3) /* match lookup table to get sampling rate parameter */
      ver--;

   dafOpenDevice(ihdl, ver, data1, true);
   free_ctrl_buffer( ihdl->pstFSAL);
   ihdl->pstFSAL = NULL;

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );
   return MEDIA_SUCCESS;
}

kal_uint32 dafMFGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur;
   dafMediaHdl *ihdl = (dafMediaHdl *) hdl;
   ASSERT(ihdl->frameDur != 0);
   ASSERT(ihdl->AudioCacheTbl != 0);

   if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number-1)){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->total_frame * ihdl->frameDur / 1000000;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR_F, hdl->mediaType, uDur );
      return uDur;
   }

   if(ihdl->AudioCacheTbl->current_cache_index){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->accumulated_frames[ihdl->AudioCacheTbl->current_cache_index-1]*ihdl->frameDur/1000000;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR, hdl->mediaType, uDur );
      return uDur;
   }
   return 0;
}

kal_uint32 dafMFGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur;
   kal_uint64 uTotalFrame;
   dafMediaHdl *ihdl = (dafMediaHdl *) hdl;
   ASSERT(ihdl->frameDur != 0);
   ASSERT(ihdl->AudioCacheTbl != 0);

// cache table finished
   if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number-1)){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->total_frame * ihdl->frameDur / 1000000;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR_F, hdl->mediaType, uDur );
      return uDur;
   }
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);

   if (ihdl->resumeFrameOffset <= ihdl->uID3V2Size)
      uDur = 0;
   else
      uDur = (kal_uint64)hdl->current_time * (kal_uint64)(ihdl->uFileSize - ihdl->uID3V2Size) / (kal_uint64)(ihdl->resumeFrameOffset - ihdl->uID3V2Size);

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_TOTAL_DUR, hdl->mediaType, uDur );
   return uDur;
}

#ifdef MUSICAM_DECODE
#ifdef DEBUG_DUMP_LOG
extern kal_uint16 *L1audio_GetFileName(void);
#endif // #ifdef DEBUG_DUMP_LOG
#endif // #ifdef MUSICAM_DECODE

MHdl *DAF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   dafMediaHdl *ihdl;

#ifdef MUSICAM_DECODE
#ifdef DEBUG_DUMP_LOG
   kal_uint16 *fileName;
#endif // #ifdef DEBUG_DUMP_LOG
#endif // #ifdef MUSICAM_DECODE

   ihdl = (dafMediaHdl*)get_ctrl_buffer( sizeof(dafMediaHdl) );
   memset(ihdl, 0, sizeof(dafMediaHdl));
   hdl = (MHdl *) ihdl;
   if( handler != NULL )
      mhdlInit( hdl, DP_D2C_DAF, dafHisr );
   else
      mhdlInitEx( hdl, DP_D2C_DAF, dafHisr );

   hdl->mediaType = MEDIA_FORMAT_DAF;
   hdl->handler   = handler;
   hdl->state     = DAF_STATE_IDLE;
   ihdl->pstFSAL  = pstFSAL;
   hdl->Close     = dafMFClose;
   hdl->Pause     = dafMFPause;
   hdl->Stop      = dafMFStop;
   hdl->Process   = dafMFProcess;

   hdl->BuildCache    = dafMFBuildCache;
   hdl->SetCacheTbl  = dafMFSetCacheTbl;
   hdl->GetCacheDuration = dafMFGetCacheDur;
   hdl->GetTotalDuration = dafMFGetTotalDuration;

   if(pstFSAL != NULL){
      ihdl->isStreaming = false;
      hdl->Play = dafMFPlayFile;
      hdl->Resume = dafMFResumeFile;
      kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, hdl->mediaType );
   } else {
       ihdl->isStreaming = true;
       hdl->Play = dafMFPlayStrm;
       hdl->Resume = dafMFResumeStrm;
       kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, hdl->mediaType );
   }

   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FILE_SIZE, hdl->mediaType, ihdl->uFileSize);

#ifdef MUSICAM_DECODE
#ifdef DEBUG_DUMP_LOG
   fileName = L1audio_GetFileName();
   kal_wsprintf( _file_name, "%w.txt", fileName);
   _file_handle = FS_Open((const WCHAR *)_file_name, FS_CREATE);
   dafDebugCnt = 0xFFFFFFFF;
#endif // #ifdef DEBUG_DUMP_LOG
#endif // #ifdef MUSICAM_DECODE

   return hdl;
}

static void dafGetInfo(kal_uint16 wFHdrW1, kal_uint16 wFHdrW2, audInfoStruct *contentInfo)
{
   kal_uint16 MPEGver;
   kal_int32  srIdx;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif // #ifdef MUSICAM_DECODE

   MPEGver = (wFHdrW1>>11) & 3;         /* check MPEG audio version ID */
   srIdx = (wFHdrW2 >> 2) & 3;          /* sampling rate frequency index */

   /* sampling rate */
   if( MPEGver == 3 && srIdx == 0 )         /* MPEG1, 44100 */
      contentInfo->sampleRate = 44100;
   else if( MPEGver == 3 && srIdx == 1 )    /* MPEG1, 48000 */
      contentInfo->sampleRate = 48000;
   else if( MPEGver == 3 && srIdx == 2 )    /* MPEG1, 32000 */
      contentInfo->sampleRate = 32000;
   else if( MPEGver == 2 && srIdx == 0 )    /* MPEG2, 22050 */
      contentInfo->sampleRate = 22050;
   else if( MPEGver == 2 && srIdx == 1 )    /* MPEG2, 24000 */
      contentInfo->sampleRate = 24000;
   else if( MPEGver == 2 && srIdx == 2 )    /* MPEG2, 16000 */
      contentInfo->sampleRate = 16000;
   else if( MPEGver == 0 && srIdx == 0 )    /* MPEG2.5, 11025 */
      contentInfo->sampleRate = 11025;
   else if( MPEGver == 0 && srIdx == 1 )    /* MPEG2.5, 12000 */
      contentInfo->sampleRate = 12000;
   else if( MPEGver == 0 && srIdx== 2 )    /* MPEG2.5, 8000 */
      contentInfo->sampleRate = 8000;

   /* bit rate */
   if( MPEGver == 3 ){                          /* MPEG1 */
      contentInfo->bitRate = DAF_BIT_RATE_TABLE_V1[(wFHdrW2 >> 4) & 0x0F] * 1000;

#ifdef MUSICAM_DECODE
   }else{                                    /* MPEG2, MPEG2.5 */
      contentInfo->bitRate = DAF_BIT_RATE_TABLE_V2[(wFHdrW2 >> 4) & 0x0F] * 1000;
    }

   /* bit rate */
   if( MPEGver == 3 ){                          /* MPEG1 */
      if(layer == 1) // Layer III
         contentInfo->bitRate = DAF_BIT_RATE_TABLE_V1[(wFHdrW2 >> 4) & 0x0F] * 1000;
      else
         contentInfo->bitRate = DAF_BIT_RATE_TABLE_L2_V1[(wFHdrW2 >> 4) & 0x0F] * 1000;
#endif // #ifdef MUSICAM_DECODE

   }else{                                    /* MPEG2, MPEG2.5 */
      contentInfo->bitRate = DAF_BIT_RATE_TABLE_V2[(wFHdrW2 >> 4) & 0x0F] * 1000;
    }

   contentInfo->details.DAF.bit_rate_index = (kal_uint8)((wFHdrW2 >> 4) & 0x0F);
   contentInfo->details.DAF.CRC = (kal_uint8)((wFHdrW1>>8) & 1);
   contentInfo->details.DAF.channel_mode = (kal_uint8)((wFHdrW2 >> 14) & 0x3);
   if(((wFHdrW2 >> 14) & 0x3) == 0x03) // stereo indicator
      contentInfo->stereo = false;
   else
      contentInfo->stereo = true;
}

static kal_uint32 dafGetDur( dafMediaHdl* ihdl, uint32 bitRate )
{
   kal_uint32 file_size, time;
   FSAL_GetFileSize(ihdl->pstFSAL, &file_size);
   if(bitRate)
      time = (kal_uint64)file_size * 8000 / (kal_uint64)bitRate;
   else
      time = 0;

   return time;
}
#if defined XING_SUPPORT
static int ExtractI4(unsigned char *buf)
{
   int x;
   // big endian extract
   x = buf[0];
   x <<= 8;
   x |= buf[1];
   x <<= 8;
   x |= buf[2];
   x <<= 8;
   x |= buf[3];

   return x;
}

static int GetXingHeader(XHEADDATA *X,  kal_uint8 *buf)
{
   int i, head_flags;
   int h_id, h_mode, h_sr_index;
   static int sr_table[4] = { 44100, 48000, 32000, 99999 };

   // get Xing header data

   X->flags = 0;     // clear to null incase fail

   // get selected MPEG header data
   h_id       = (buf[1] >> 3) & 1;
   h_sr_index = (buf[2] >> 2) & 3;
   h_mode     = (buf[3] >> 6) & 3;

   // determine offset of header
   if( h_id ) {        // mpeg1
       if( h_mode != 3 ) buf+=(32+4);
       else              buf+=(17+4);
   }
   else {      // mpeg2
       if( h_mode != 3 ) buf+=(17+4);
       else              buf+=(9+4);
   }

   if( buf[0] != 'X' ) return 0;    // fail
   if( buf[1] != 'i' ) return 0;    // header not found
   if( buf[2] != 'n' ) return 0;
   if( buf[3] != 'g' ) return 0;
   buf+=4;

   X->h_id = h_id;
   X->samprate = sr_table[h_sr_index];
   if( h_id == 0 ) X->samprate >>= 1;

   head_flags = X->flags = ExtractI4(buf); buf+=4;      // get flags

   if( head_flags & FRAMES_FLAG ) {X->frames   = ExtractI4(buf); buf+=4;}
   if( head_flags & BYTES_FLAG )  {X->bytes = ExtractI4(buf); buf+=4;}

   if( head_flags & TOC_FLAG ) {
       if( X->toc != NULL ) {
           for(i=0;i<100;i++) X->toc[i] = buf[i];
       }
       buf+=100;
   }
   
   X->vbr_scale = -1;
   if( head_flags & VBR_SCALE_FLAG )  {X->vbr_scale = ExtractI4(buf); buf+=4;}
   
   return 1;       // success
}
#endif // #if defined XING_SUPPORT
Media_Status DAF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   dafMediaHdl *ihdl;
   kal_uint16 headerFstWd, headerSndWd;

   ihdl = (dafMediaHdl*)get_ctrl_buffer( sizeof(dafMediaHdl) );
   memset(ihdl, 0, sizeof(dafMediaHdl));
   mhdlInit( ( MHdl *)ihdl, 0xFFFF , dafHisr );
   ihdl->pstFSAL = pstFSAL;

   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->author[0]  = '\0';
   contentInfo->copyright[0]  = '\0';
   contentInfo->date[0]  = '\0';
   contentInfo->time = 0;
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 0;
   contentInfo->stereo = false;

   autSkipID3Tag((MHdl *) ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

   if ( dafReachNextFrame(ihdl, &headerFstWd, &headerSndWd) == KAL_FALSE ){
      free_ctrl_buffer( ihdl );
      return MEDIA_BAD_FORMAT;
   }
#if defined XING_SUPPORT
   if(autGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset, 512, &ihdl->buf[0]) == 512){
		ihdl->fXing = GetXingHeader(&ihdl->stXing,  &ihdl->buf[0]);
	}
#endif // #if defined XING_SUPPORT
   dafGetInfo(headerFstWd, headerSndWd, contentInfo);
#if defined XING_SUPPORT
   if(ihdl->fXing){
      if((contentInfo->sampleRate == 44100) || (contentInfo->sampleRate == 48000) || (contentInfo->sampleRate == 32000))
         contentInfo->time = (kal_int64)ihdl->stXing.frames * 1152000 / contentInfo->sampleRate;
      else
         contentInfo->time = (kal_int64)ihdl->stXing.frames * 576000 / contentInfo->sampleRate;
   }else
#endif // #if defined XING_SUPPORT
      contentInfo->time = dafGetDur(ihdl, contentInfo->bitRate);

   free_ctrl_buffer( ihdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, MEDIA_FORMAT_DAF );

   return MEDIA_SUCCESS;
}

Media_Status DAF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   aud_info_struct *aud_info_p;

   Media_Status ret;
   FSAL_Status eFSALStatus;
   STFSAL *pstFSAL = 0;

   pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(pstFSAL == NULL)
      return MEDIA_FAIL;
   memset(pstFSAL, 0, sizeof(STFSAL));
      
   if(NULL != filename){      
      eFSALStatus = FSAL_Open(pstFSAL, (void*)filename, FSAL_READ);
      if(eFSALStatus != FSAL_OK){
         free_ctrl_buffer(pstFSAL);
         return MEDIA_FAIL;
      }   
   }else{
       ASSERT(pbBuf != 0);
       ASSERT(uSize != 0)
       FSAL_Direct_SetRamFileSize(pstFSAL, uSize);
       eFSALStatus = FSAL_Open(pstFSAL, pbBuf, FSAL_ROMFILE);
       ASSERT(eFSALStatus == FSAL_OK);
   }

   ret = DAF_GetContentDescInfo( pstFSAL, contentInfo, (void *)0);

   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   if( MEDIA_SUCCESS != ret )
      return ret;

   aud_info_p = (aud_info_struct*)get_ctrl_buffer( sizeof(aud_info_struct) );
   memset(aud_info_p, 0, sizeof(aud_info_struct));

   if(filename){
      if(!get_aud_meta_data_file(filename, aud_info_p)){
         free_ctrl_buffer( aud_info_p );
         return MEDIA_FAIL;
      }
   }else{
      ASSERT(0 != pbBuf);
      if(!get_aud_meta_data_array((kal_char *)pbBuf, uSize, aud_info_p)){
         free_ctrl_buffer( aud_info_p );
         return MEDIA_FAIL;
      }
   }

   memcpy(contentInfo->title, aud_info_p->title, sizeof(kal_wchar)* MAX_ID3_TITLE_LEN);
   memcpy(contentInfo->author, aud_info_p->artist, sizeof(kal_wchar)* MAX_ID3_ARTIST_LEN);
   memcpy(contentInfo->copyright, aud_info_p->copyright, sizeof(kal_wchar)* MAX_ID3_COPYRIGHT_LEN);
   memcpy(contentInfo->date, aud_info_p->year, sizeof(kal_wchar)* MAX_ID3_YEAR_LEN);

   free_ctrl_buffer( aud_info_p );
   return MEDIA_SUCCESS;
}

Media_Status DAF_Trim(STFSAL *pstIn, STFSAL *pstOut, kal_uint32 uStartTime, kal_uint32 uStopTime)
{
   kal_uint32 uStartOffset, uEndOffset;
   kal_uint16 headerFstWd, headerSndWd;
   Media_Status eResult = MEDIA_SUCCESS;
   dafMediaHdl *ihdl;

   if(((kal_int32)uStopTime - (kal_int32)uStartTime) <= 0)
      return MEDIA_BAD_PARAMETER; // invalid stop time

   ihdl = (dafMediaHdl*)get_ctrl_buffer( sizeof(dafMediaHdl) );
   memset(ihdl, 0, sizeof(dafMediaHdl));
   ihdl->pstFSAL         = pstIn;

   autSkipID3Tag( (MHdl *)ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

   if ( dafReachNextFrame(ihdl, &headerFstWd, &headerSndWd) == KAL_FALSE ){
      free_ctrl_buffer(ihdl);
      return MEDIA_BAD_FORMAT;
   }

   // find the start/end offset of trim
   {
	   kal_uint32 uFirstFrameFileOffset = ihdl->fileOffset;
	   ihdl->mh.start_time = uStartTime;
      if(dafSeek(ihdl, false) != KAL_TRUE){
		   free_ctrl_buffer(ihdl);
		   return MEDIA_SEEK_FAIL;
	   }
	   uStartOffset = ihdl->fileOffset;
	   ihdl->fileOffset = uFirstFrameFileOffset;

      ihdl->mh.start_time = uStopTime;
      if(dafSeek(ihdl, false) != KAL_TRUE){
         free_ctrl_buffer(ihdl);
		   return MEDIA_SEEK_FAIL;
	   }
      uEndOffset = ihdl->fileOffset;
	   ihdl->fileOffset = uStartOffset;
   }
   //write fregment audio data
   {
	   FSAL_Status eFSALStatus;
	   kal_int32 uNumBytes;
	   kal_int32 uLength = (kal_int32)uEndOffset-(kal_int32)uStartOffset;

	   // refill buffer
	   while(uLength > 0){
		   kal_uint32 len = DAF_MAX_DATA_REQUESTED;
		   if(uLength<DAF_MAX_DATA_REQUESTED)
			   len = uLength;
		   uNumBytes = dafGetBytesFromFile((MHdl *)ihdl, ihdl->pstFSAL, ihdl->fileOffset, len, &ihdl->buf[0]);
		   if(uNumBytes<0){
            free_ctrl_buffer(ihdl);
            return MEDIA_READ_FAIL;
		   }
	      eFSALStatus = FSAL_Write(pstOut, &ihdl->buf[0], uNumBytes);
		   if(FSAL_OK != eFSALStatus){
            free_ctrl_buffer(ihdl);
            if(eFSALStatus == FS_DISK_FULL)
               return MEDIA_DISK_FULL;
            else
               return MEDIA_WRITE_FAIL;
		   }
		   ihdl->fileOffset += uNumBytes;
		   uLength -= uNumBytes;
	   }
   }
   free_ctrl_buffer(ihdl);
   return eResult;
}

Media_Status DAF_Merge(STFSAL *pstIn1, STFSAL *pstIn2, STFSAL *pstOut)
{
   // check to see whether streams could be merged
   // merge file
   kal_uint16    headerFstWd = 0, headerSndWd = 0;
   dafMediaHdl *ihdl;
   Media_Status eResult = MEDIA_SUCCESS;
   kal_uint32 file_size;

   ihdl = (dafMediaHdl*)get_ctrl_buffer( sizeof(dafMediaHdl) );

   {
      kal_uint32 cnt;
      kal_uint16 hw1, hw2;
      for(cnt=0; cnt<2; cnt++)
      {
         memset(ihdl, 0, sizeof(dafMediaHdl));
         if(cnt==0){
            ihdl->pstFSAL = pstIn1;
         }else{
             ihdl->pstFSAL = pstIn2;
          }

         autSkipID3Tag( (MHdl *)ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );

         {
	        if ( dafReachNextFrame(ihdl, &hw1, &hw2) == KAL_FALSE ){
	           free_ctrl_buffer(ihdl);
              return MEDIA_BAD_FORMAT;
           }
         }

         if(cnt==0){
            headerFstWd = hw1;
            headerSndWd = hw2;
         }else{
             if((headerFstWd != hw1) || (headerSndWd != hw2)){
                free_ctrl_buffer(ihdl);
                return MEDIA_MERGE_TYPE_MISMATCH;
             }
          }

         //write fregment audio data
         {
	         FSAL_Status eFSALStatus;
	         kal_int32 uNumBytes, uLength;

            FSAL_GetFileSize( ihdl->pstFSAL, &file_size);
            uLength = (kal_int32)(file_size - ihdl->fileOffset);

	         // refill buffer
	         while(uLength > 0){
	      	   kal_uint32 len = DAF_MAX_DATA_REQUESTED;
	      	   if(uLength < DAF_MAX_DATA_REQUESTED)
	      		   len = uLength;
	      	   uNumBytes = dafGetBytesFromFile((MHdl *)ihdl, ihdl->pstFSAL, ihdl->fileOffset, len, &ihdl->buf[0]);
	      	   if(uNumBytes<0){
                  free_ctrl_buffer(ihdl);
                  return MEDIA_READ_FAIL;
	      	   }
	            eFSALStatus = FSAL_Write(pstOut, &ihdl->buf[0], uNumBytes);
	      	   if(FSAL_OK != eFSALStatus){
                  free_ctrl_buffer(ihdl);
                  if(eFSALStatus == FS_DISK_FULL)
                     return MEDIA_DISK_FULL;
                  else
                     return MEDIA_WRITE_FAIL;
	      	   }
	      	   ihdl->fileOffset += uNumBytes;
	      	   uLength -= uNumBytes;
	         }
         }
      }
   }
   free_ctrl_buffer(ihdl);
   return eResult;
}

#endif // DAF_DECODE