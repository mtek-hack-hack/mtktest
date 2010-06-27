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
 * wav_drv_thumb.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   WAV Decoder Driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __L1_STANDALONE__ // avoid link error

#include "fsal.h"
#include "wav.h"
#include "l1sp_trc.h"
#if defined(MT6223) || defined(MT6223P)
#include "dcmgr.h"
#endif

#if defined(MT6205B) || defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225)
#define PAGE_NUM 0
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 2
#elif defined(MT6223) || defined(MT6223P)
#define PAGE_NUM 1
#else
#error The new chip should define DM page number
#endif

#if defined(MT6225) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define WAV_ABORT_STATE 0x40
#else
#define WAV_ABORT_STATE 0x10
#endif

static const kal_uint16 samplePerFrame[] = {80,441,120,160,441,240,320,441,480};
static const kal_uint8  framDuration[] = {10,40,10,10,20,10,10,10,10};
static const kal_uint8 SampleRateTable[] = {
   0x00, /*8000*/   0x11,/* 11025 */ 0x12,/* 12000 */
   0x20, /*16000,*/ 0x21,/* 22050,*/ 0x22,/* 24000,*/
   0x40, /*32000,*/ 0x41,/* 44100,*/ 0x42 /* 48000 */
};

extern kal_semid  WAVsema;
extern void SPT_PutPcmData( const kal_int16 *pcm, kal_int32 len, kal_bool mono );

//----------- Functions for EOF Handling -----------
// For wav_drv_thumb.c / pcm.c / pcm_strm_drv.c

/* Count the number of remained samples in DSP buffer */
kal_int32 wavGetDSPDataCnt( kal_int32 dsp_rb_size )
{
   kal_int32 cnt;
   kal_int32 rb_w, rb_r;

   rb_w = (kal_int32)*DSP_PCM_W;

   do {
      rb_r = (kal_int32)*DSP_PCM_R;
   } while (rb_r != (kal_int32)*DSP_PCM_R);

   cnt = rb_w - rb_r;
   if (cnt < 0)
      cnt += dsp_rb_size;
   
   return cnt;
}

/* Put silence to DSP, and fill DSP buffer */
static void PutSilence(kal_uint16 dsp_rb_base, kal_int32 dsp_rb_size, kal_int16 dsp_last_sample, kal_int32 dsp_len)
{
   kal_int32 I;
   kal_uint16 dsp_w = *DSP_PCM_W;

   if (dsp_len <= 0)
      return;

   /* data transferring via IDMA */
   *DSP_DM_ADDR(PAGE_NUM, dsp_rb_base + dsp_w) = dsp_last_sample;
   for (I = dsp_len - 2; I >= 0; I--)
      *IDMA_SHORT_ADDR = dsp_last_sample;

   dsp_w += dsp_len;
   if (dsp_w == dsp_rb_size)
      dsp_w = 0;
   
   /* Update DSP writing pointer */
   *DSP_PCM_W = dsp_w;
}

kal_int32 wavPutSilence(kal_uint16 dsp_rb_base, kal_int32 dsp_rb_size, kal_int16 dsp_last_sample)
{
   kal_int16 rb_w, rb_r_cache, tmp;
   
   do {
      rb_r_cache = (int16)*DSP_PCM_R;
   } while (rb_r_cache != (int16)*DSP_PCM_R);
   
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if (rb_r_cache < 0)
      rb_r_cache += (int16)dsp_rb_size;
   
   tmp = (int16)dsp_rb_size - rb_w;
   if (tmp > rb_r_cache)
      tmp = rb_r_cache;
      
   PutSilence( dsp_rb_base, dsp_rb_size, dsp_last_sample, tmp );
   PutSilence( dsp_rb_base, dsp_rb_size, dsp_last_sample, rb_r_cache - tmp );

   return rb_r_cache;
}

//--------------------------------------------------

static kal_int32 LPCM16BitPutData( MHdl *hdl, kal_int32 uMBufLen )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;
   kal_int32 cnt, uGetNByte;
   kal_uint8 *pMBwrite = &hdl->rb_base[hdl->write];
   kal_uint8 *pInBuf = (kal_uint8 *)&ihdl->buf[0];

   ASSERT( (uMBufLen & 0x01)==0 );
   if(uMBufLen > WAV_MAX_DATA_REQUESTED)
      uMBufLen = WAV_MAX_DATA_REQUESTED;
   uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, uMBufLen, pInBuf);
   if(uGetNByte < 0) return -1;

   if( uGetNByte != uMBufLen )
      uGetNByte &= 0xFFFFFFFE;

   for(cnt=uGetNByte; cnt > 0; cnt-=2){
      kal_uint8 tmp;
      tmp = *pInBuf++;
      *pMBwrite++ = *pInBuf++;
      *pMBwrite++ = tmp;
   }
   ihdl->wav.dsp_last_sample = *(--pMBwrite);
   return uGetNByte;
}

static kal_int32 wav_DecodeSample( MHdl *hdl, kal_int32 uMBufLen, const uint16* Table )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;
   kal_int32   cnt, uGetNByte;
   kal_uint16  *pMBwrite = (kal_uint16 *)&hdl->rb_base[hdl->write];
   kal_uint16  *ptr = &ihdl->buf[0]; // word-aligned

   ASSERT( uMBufLen > 3 );

   uMBufLen >>= 1;
   if(uMBufLen > WAV_MAX_DATA_REQUESTED)
      uMBufLen = WAV_MAX_DATA_REQUESTED;
   uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, uMBufLen, (kal_uint8 *)&ihdl->buf[0]);
   if(uGetNByte < 0) return -1;

   // to avoid the noise induced by zero padding in last odd byte
   if ( hdl->eof && (uGetNByte>=2) ) {
      kal_uint8 *ptr = (kal_uint8 *) ihdl->buf;
      
      if (ptr[uGetNByte-1] == 0) {
         ptr[uGetNByte-1] = ptr[uGetNByte-2];
      }
   }

   if( uGetNByte != uMBufLen )
      uGetNByte &= 0xFFFFFFFC;

   if( Table ){
      for(cnt=uGetNByte; cnt > 0; cnt-=2){
         *pMBwrite++ = Table[(*ptr) & 0x00FF];
         *pMBwrite++ = Table[(*ptr++)>>8];
      }
   }else if(hdl->mediaType == MEDIA_FORMAT_WAV){
      for(cnt=uGetNByte; cnt > 0; cnt-=2){
         *pMBwrite++ = (*ptr<<8) - 0x8000;
         *pMBwrite++ = ((*ptr++) & 0xFF00) - 0x8000;
      }
   }else{
      for(cnt=uGetNByte; cnt > 0; cnt-=2){
         *pMBwrite++ = (*ptr<<8);
         *pMBwrite++ = ((*ptr++) & 0xFF00);
      }
    }
   ihdl->wav.dsp_last_sample = *(--pMBwrite);
   return (uGetNByte << 1);
}

static kal_int32 wavPutData8bit( MHdl *hdl, kal_int32 mbBufLen) /* 8 bit linear pcm */
{
   return wav_DecodeSample( hdl, mbBufLen, NULL);
}

static kal_int32 wavAlawPutData( MHdl *hdl, kal_int32 mbBufLen) /* A-law decoder */
{
   return wav_DecodeSample( hdl, mbBufLen, Alaw_Tab );
}

static kal_int32 wavUlawPutData( MHdl *hdl, kal_int32 mbBufLen)  /* U-law decoder */
{
   return wav_DecodeSample( hdl, mbBufLen, Ulaw_Tab );
}

static kal_bool wavSeek( wavMediaHdl *ihdl )
{   /* file offset must be aligned the first frame header */
   kal_int64  frameNum, totalSamples;

   frameNum = ihdl->mh.start_time  / framDuration[ihdl->wav.sr_index];
   totalSamples = frameNum * samplePerFrame[ihdl->wav.sr_index];

   switch( ihdl->wav.formatTag ) {
      case 0x0001:
         if( ihdl->wav.BitsPerSample == 8 )
            ihdl->fileOffset += totalSamples * ihdl->wav.channel_num;
         else if( ihdl->wav.BitsPerSample == 16 )
            ihdl->fileOffset += totalSamples * ihdl->wav.channel_num * 2;
         else
            ASSERT(KAL_FALSE); // never reach here, memory corrupt
         break;
      case 0x0006:
      case 0x0007:
         ihdl->fileOffset += totalSamples * ihdl->wav.channel_num;
         break;

      case 0x0011:
      case 0x0002:
         {
           kal_int64 blockNum;
           blockNum = totalSamples / ihdl->wav.samplesPerBlock;
           ihdl->fileOffset += blockNum * ihdl->wav.wBlockAlign;
           ihdl->wav.data_count = 0;
           ihdl->wav.BlockCount = 0;
         }
         break;
      default:
         return false;
   }

   FSAL_GetFileSize( ihdl->pstFSAL, &ihdl->file_size);
   if( ihdl->fileOffset > ihdl->file_size){
      ihdl->fileOffset = ihdl->file_size;
      return false;
   }

   return true;
}

static void wavIncTime( MHdl *hdl, uint32 num_bytes )
{
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;
   kal_int32  totalConsumedData = (ihdl->reidualDataCnt + num_bytes) >> 1;
   if(!num_bytes) return;
   ihdl->reidualDataCnt = totalConsumedData  % (samplePerFrame[ihdl->wav.sr_index]*ihdl->wav.channel_num);
   ihdl->reidualDataCnt <<= 1;
   ihdl->mh.current_time += ( totalConsumedData / (samplePerFrame[ihdl->wav.sr_index]*ihdl->wav.channel_num)) * framDuration[ihdl->wav.sr_index];
}

static void wavHisr( void *data )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)data;
   kal_int16 rb_w, rb_r_cache, tmp1;

   if( ihdl->end_status == MEDIA_TERMINATED )
      return;

   if( *DSP_PCM_CTRL == 0 ) {  // DSP in idle state
      kal_prompt_trace( MOD_L1SPHISR, " WAV_L1AUDIO_IDLE_STATE ");
   	  if(ihdl->end_status == MEDIA_STOP_TIME_UP){
   	  	  mhdlException( (MHdl*)ihdl, MEDIA_STOP_TIME_UP );
   	  }else{
   	  	  mhdlException( (MHdl*)ihdl, MEDIA_END );
   	  }
   	  ihdl->end_status = MEDIA_TERMINATED;
      return;
   }

   if( ihdl->end_status == MEDIA_END || ihdl->end_status == MEDIA_STOP_TIME_UP)
      return;

   if (ihdl->decode_EOF) {
      if (ihdl->zeroCount > 0) {
         kal_int32 count;
         
         count = wavPutSilence(ihdl->mh.dsp_rb_base, ihdl->mh.dsp_rb_size, ihdl->wav.dsp_last_sample);
         ihdl->zeroCount -= count;
      }
      
      if (ihdl->zeroCount <= 0) {
         ihdl->end_status = MEDIA_END;
         *DSP_PCM_CTRL = 0x10;
         kal_prompt_trace( MOD_L1SPHISR, " WAV_L1AUDIO_END_STATE ");
      }
      return;
   }

   if( *DSP_PCM_CTRL == 2 ) {   // DSP RingBuf initialization
      kal_prompt_trace( MOD_L1SPHISR, " WAV_L1AUDIO_INIT_STATE ");
      ihdl->mh.dsp_rb_base = *DSP_PCM_W;
      ihdl->mh.dsp_rb_size = *DSP_PCM_R;
      ihdl->mh.dsp_rb_end = ihdl->mh.dsp_rb_base + ihdl->mh.dsp_rb_size;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
      *DSP_PCM_CTRL = 4;
   }

   do {
      rb_r_cache = (int16)*DSP_PCM_R;
   } while( rb_r_cache != (int16)*DSP_PCM_R );

   autWriteDataToDSP((MHdl*)ihdl, (uint16*)DSP_PCM_W, (uint16*)DSP_PCM_R, PAGE_NUM, wavIncTime);

   if( ihdl->mh.current_time >= ihdl->mh.stop_time) {
      ihdl->end_status = MEDIA_STOP_TIME_UP;
      *DSP_PCM_CTRL = 0x10;
      kal_prompt_trace( MOD_L1SPHISR, " WAV_L1AUDIO_TIME_UP_STATE ");
      return;
   }

   if( ( *DSP_PCM_CTRL == 8) && (  ( (ihdl->mh.eof) && (ihdl->mh.GetDataCount((MHdl*)ihdl) <= 1)) ||
       (ihdl->mh.current_time >= ihdl->mh.stop_time) || ((ihdl->mh.mediaType == MEDIA_FORMAT_WAV) && 
       (ihdl->wav.wDataLength == 0) && (ihdl->mh.GetDataCount((MHdl*)ihdl) <= 1))  )) {
      ihdl->decode_EOF = true;
      ihdl->zeroCount = wavGetDSPDataCnt(ihdl->mh.dsp_rb_size);
   }

   // fill silence, Media Buffer underflow
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if ( rb_r_cache < 0 )
      rb_r_cache += (int16)ihdl->mh.dsp_rb_size;
   rb_r_cache &= 0xFFFFFFFE;

   if (rb_r_cache)   // if MCU should fill silence to DSP...
   {
      kal_prompt_trace( MOD_L1SPHISR, "BUF_UF"); // buffer underflow
      tmp1 = (int16)ihdl->mh.dsp_rb_size - rb_w;
      if (rb_r_cache > tmp1)
      {
         PutSilence( ihdl->mh.dsp_rb_base, ihdl->mh.dsp_rb_size, ihdl->wav.dsp_last_sample, tmp1 );
         rb_r_cache -= tmp1;
      }
      PutSilence( ihdl->mh.dsp_rb_base, ihdl->mh.dsp_rb_size, ihdl->wav.dsp_last_sample, rb_r_cache );
   }

   mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
}

static void wavOpenDevice( wavMediaHdl *ihdl, kal_bool DDFlag)
{
   ihdl->end_status = MEDIA_NONE; // Clear for streaming case
   ihdl->mh.dsp_rb_base = 0;

   KT_StopAndWait();
   TONE_StopAndWait();
   
   mhdlDisallowSleep( (MHdl*)ihdl );
   ASSERT(*DSP_PCM_CTRL == 0);

#if !defined(MT6205B)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if (ihdl->wav.is_8KVoice) {
      AM_PCM8K_PlaybackOn();
   } else 
#endif
   {
#if defined( DSP_WT_SYN )
      if(DDFlag)
         DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, (uint16)SampleRateTable[ihdl->wav.sr_index] );
   }
#else
   AM_PCM8K_PlaybackOn();
#endif

   *DSP_PCM_CTRL = 1;
   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );
   {
      kal_uint16 I;
      for( I = 0; ; I++ ) {
         if( *DSP_PCM_CTRL == 8 || ihdl->end_status != MEDIA_NONE ){
            kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
            break;
         }
         ASSERT_REBOOT( I < 40 );
         kal_sleep_task( 2 );
      }
   }
}

static void pcmOpenDevice( wavMediaHdl *ihdl)
{
   uint16 I;
   
   KT_StopAndWait();
   TONE_StopAndWait();
   
   ihdl->end_status = MEDIA_NONE;
   ihdl->mh.dsp_rb_base = 0;
   mhdlDisallowSleep( (MHdl*)ihdl );
   ASSERT(*DSP_PCM_CTRL == 0);

#if defined( MT6205B )
   if( ihdl->mh.mediaType == MEDIA_FORMAT_PCM_16K )
      AM_PCM16K_PlaybackOn();
   else
      AM_PCM8K_PlaybackOn();
#else
   *DSP_PCM_MS |= 0x0001;
#if !defined(__BT_AUDIO_VIA_SCO__)
   if( ihdl->wav.is_8KVoice ) {
      AM_PCM8K_PlaybackOn();
   } else 
#endif
   {
#if defined( DSP_WT_SYN )
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      if( ihdl->mh.mediaType == MEDIA_FORMAT_PCM_16K )
         AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ASP_FS_16K );
      else
         AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ASP_FS_8K );
   }
#endif

   *DSP_PCM_CTRL = 1;
   for( I = 0; ; I++ ) {
      if( *DSP_PCM_CTRL == 8 || ihdl->end_status != MEDIA_NONE ){
         kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
         break;
      }
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
}

static void wavCloseDevice( wavMediaHdl *ihdl )
{
   uint16 I, ctl;
   for( I = 0; ; I++ ) {
      ctl = *DSP_PCM_CTRL;
      if( ctl == 0 )                /* DSP returns to idle state */
         break;
      if( ctl == 8 ){
         *DSP_PCM_CTRL = WAV_ABORT_STATE;       /* give ABORT command to the DSP */
         kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      }
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }

#if defined( MT6205B )
   if( ihdl->mh.mediaType == MEDIA_FORMAT_PCM_16K )
      AM_PCM16K_PlaybackOff( true );
   else
      AM_PCM8K_PlaybackOff( true );
#else
#if !defined(__BT_AUDIO_VIA_SCO__)
   if (ihdl->wav.is_8KVoice)
      AM_PCM8K_PlaybackOff( true );
   else
#endif
      AM_AudioPlaybackOff( true );
#endif
   mhdlAllowSleep( (MHdl*)ihdl );
}

static Media_Status wavMFClose( MHdl *hdl )
{
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;
   ASSERT( hdl != 0 && hdl->state != WAV_STATE_PLAYING);
   mhdlFinalize( hdl, DP_D2C_PCM_P );

   L1Audio_FreeAudioID( ihdl->aud_id_decoder );

#if APM_SUPPORT
   if (ihdl->fUseTCMFromAPM)
   {
      APM_Release_Buffer();
   }
   else
#endif
   {
      free_ctrl_buffer( hdl );
   }

   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static bool wavGetByte(wavMediaHdl *ihdl, kal_uint8 *data)
{
   *data = ihdl->mh.rb_base[ihdl->mh.read];
   ihdl->mh.read++;
   if( ihdl->mh.read >= ihdl->mh.write)
      return false;
   return true;
}

static bool wavGetWord(wavMediaHdl *ihdl, kal_uint16 *data)
{
   kal_uint8 buf_8;

   if(!wavGetByte(ihdl, &buf_8))
      return false;
   *data = (kal_uint16)buf_8;

   if(!wavGetByte(ihdl, &buf_8))
      return false;

   *data |= (kal_uint16)buf_8 << 8;
   return true;
}

static bool wavGetDword(wavMediaHdl *ihdl, kal_uint32 *data)
{
   kal_uint16 buf_16;
   if(!wavGetWord(ihdl, &buf_16))
      return false;
   *data = (kal_uint32)buf_16;

   if(!wavGetWord(ihdl, &buf_16))
      return false;

   *data |= (kal_uint32)buf_16 << 16;
   return true;
}

static bool wavSkipByte(wavMediaHdl *ihdl)
{
   ihdl->mh.read++;
   if( ihdl->mh.read >= ihdl->mh.write)
      return false;
   return true;
}

static bool wavSkipNBytes(wavMediaHdl *ihdl, kal_uint32 NBytes)
{
   kal_uint32 cnt;

   for(cnt=NBytes; cnt > 0; cnt--){
      if(!wavSkipByte(ihdl))
         return false;
   }
   return true;
}

/* search "data" chunk descriptor */
static bool wavReachDataChunk( wavMediaHdl *ihdl )
{
   uint32 data_32, uRead = 0;
   do {
      if( (ihdl->mh.write - ihdl->wav.dataChunkOffset) < 8 || (ihdl->mh.read > ihdl->mh.write) )   return false;

      // Get chunk id
      wavGetDword(ihdl, &data_32);
      uRead += 4;
      if( data_32 == 0x61746164 )   break;  // "data"
      wavGetDword(ihdl, &ihdl->wav.nextChunkOffset);
      uRead += 4;

      if(ihdl->wav.dataChunkOffset > ihdl->mh.write) return false;
      wavSkipNBytes(ihdl, ihdl->wav.nextChunkOffset);
      uRead += ihdl->wav.nextChunkOffset;
   }while( 1 );

   wavGetDword(ihdl, &ihdl->wav.wDataLength);
   uRead += 4;
   ihdl->wav.dataChunkOffset += uRead;
   ihdl->fileOffset = ihdl->wav.dataChunkOffset;

   if(4 != ihdl->wav.BitsPerSample){
      ihdl->wav.wDataLength *= (16/ihdl->wav.BitsPerSample);
   }else{
     kal_int64 len, samplePerBlock;
     len = (kal_int64)ihdl->wav.wDataLength;
     samplePerBlock = (kal_int64)ihdl->wav.samplesPerBlock;
     ihdl->wav.wDataLength = len * samplePerBlock * 2 * ihdl->wav.channel_num / ihdl->wav.wBlockAlign;
   }

   return true;
}

static Media_Status wavReadHeader( wavMediaHdl *ihdl )
{
   uint32 dummy_32, ckSize, bytes_read;
   uint16 FormatTag;

/* Check to see if header is invalid, "RIFF" chunk descriptor */
   wavGetDword(ihdl, &dummy_32);
   if( dummy_32 != 0x46464952 )
      return MEDIA_BAD_FORMAT;
   wavSkipNBytes(ihdl, 4); // Skip 2 word
   wavGetDword(ihdl, &dummy_32);
   if( dummy_32 != 0x45564157 )
      return MEDIA_BAD_FORMAT;
   do {
      if(!wavGetDword(ihdl, &dummy_32))
         return MEDIA_BAD_FORMAT;
      if( dummy_32 == 0x20746D66 )        // seek sub-chunk "fmt chunk"
         break;
      wavGetDword(ihdl, &dummy_32);
      wavSkipNBytes(ihdl, dummy_32);
   }while(1);
   // Get the fmt ckSize
   wavGetDword(ihdl, &ckSize);
   if( ckSize < 16 )
      return MEDIA_BAD_FORMAT;
   /* Check fmt chunk */
   wavGetWord(ihdl, &FormatTag);
   ihdl->wav.formatTag = FormatTag;
   wavGetWord(ihdl, &ihdl->wav.channel_num);
   if( ihdl->wav.channel_num == 1 ) {
#if  defined(MT6205B)
      ihdl->mh.mono2stereo = false;
#else
      *DSP_PCM_MS |= 0x0001;
      ihdl->mh.mono2stereo = true;
#endif
      ihdl->wav.is_stereo = false;
   }
#if !defined(MT6205B)
   else if( ihdl->wav.channel_num == 2 ) {
      *DSP_PCM_MS |= 0x0001;
      ihdl->wav.is_stereo = true;
   }
#endif
   else
      return MEDIA_BAD_FORMAT;

   // sample rate
   wavGetDword(ihdl, (kal_uint32 *)&ihdl->wav.sampleRate);
   switch( ihdl->wav.sampleRate / 1000 ){             // update sample rate index of control table
      case 7: case 8:  ihdl->wav.sr_index = 0;
         break;
#if !defined(MT6205B)
      case 10: case 11: ihdl->wav.sr_index = 1;
         break;
      case 12: ihdl->wav.sr_index = 2;
         break;
      case 15: case 16: ihdl->wav.sr_index = 3;
         break;
      case 21: case 22: ihdl->wav.sr_index = 4;
         break;
      case 23: case 24: ihdl->wav.sr_index = 5;
         break;
      case 31: case 32: ihdl->wav.sr_index = 6;
         break;
      case 43: case 44: ihdl->wav.sr_index = 7;
         break;
      case 47: case 48: ihdl->wav.sr_index = 8;
         break;
#endif
      default: return MEDIA_UNSUPPORTED_FREQ;
   }
   wavGetDword(ihdl, (kal_uint32 *)&ihdl->wav.AvgBytesPerSec);
   wavGetWord(ihdl, (kal_uint16 *)&ihdl->wav.wBlockAlign);
   wavGetWord(ihdl, (kal_uint16 *)&ihdl->wav.BitsPerSample); // 36

   bytes_read = 16;
   switch( FormatTag ) {
      case 0x0001:
         if( ihdl->wav.BitsPerSample == 8 )
            ihdl->wav.Wav_PutData = wavPutData8bit;
         else if( ihdl->wav.BitsPerSample == 16 );
         else
            return MEDIA_UNSUPPORTED_TYPE;
         break;
      case 0x0006:
      case 0x0007:
         ihdl->wav.Wav_PutData = ( FormatTag == 0x0006 )?
            wavAlawPutData : wavUlawPutData;
         break;
      case 0x0011:
         if( ihdl->wav.BitsPerSample != 4 )   // support 4 bit dvi-adpcm only
            return MEDIA_UNSUPPORTED_TYPE;
         wavSkipNBytes(ihdl, 2);
         wavGetWord(ihdl, &ihdl->wav.samplesPerBlock);
         ihdl->wav.Wav_PutData = ( ihdl->wav.is_stereo )?
         wavDviADPCMPutData_ST : wavDviADPCMPutDataMono;
         bytes_read += 4;
         break;
      case 0x0002:                           // MS ADPCM
         if( ihdl->wav.BitsPerSample != 4 )  // support 4 bit ms-adpcm only
            return MEDIA_UNSUPPORTED_TYPE;
         ihdl->wav.Wav_PutData = wavMSADPCMPutDataMonoST;
         if( ihdl->wav.is_stereo )              // test if stereo
            wavMS_ADPCM_Decode = wavMSADPCM_decode_stereo;
         else
            wavMS_ADPCM_Decode = wavMSADPCM_decode_mono;

         wavSkipNBytes(ihdl, 2);
         wavGetWord(ihdl, &ihdl->wav.samplesPerBlock);
         wavGetWord(ihdl, (kal_uint16 *)&ihdl->wav.nNumCoef);
         if( ihdl->wav.nNumCoef > MSADPCM_EXTRA_COEFF + 7 )
            return MEDIA_UNSUPPORTED_TYPE;

        wavSkipNBytes(ihdl, 28); // Skip 14 word

         for( dummy_32=0; dummy_32 < ihdl->wav.nNumCoef - 7; dummy_32++ )
         {
            // These values are stored in 8.8 signed format !!!
            wavGetWord(ihdl, (kal_uint16 *)&ihdl->wav.aCoeff[dummy_32][0]);
            wavGetWord(ihdl, (kal_uint16 *)&ihdl->wav.aCoeff[dummy_32][1]);
         }
         bytes_read += 6 + ihdl->wav.nNumCoef * 4;
         break;
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }

   wavSkipNBytes(ihdl, ckSize - bytes_read);
   ihdl->wav.nextChunkOffset = 0;
   ihdl->wav.dataChunkOffset = ihdl->mh.read;

   return MEDIA_SUCCESS;
}

// Look for SSND chunk
// Bedofe calling this function, aiff.mb_count should be assigned correct value.
// Return value:
//    0: ssnd not found yet
//    1: ssnd found but the actual sound data is not found yet
//    2: sound data is found
static kal_uint32 aiffLookForSSND( wavMediaHdl *ihdl )
{
   MHdl *hdl = (MHdl *)ihdl;
   kal_uint32 data_32;

   while( 1 )
   {
      if( ihdl->wav.word_left_in_ck )
      {
         data_32 = (kal_uint32) hdl->GetDataCount(hdl);
         if(data_32 >= (ihdl->wav.word_left_in_ck << 1)){
            wavSkipNBytes(ihdl, (ihdl->wav.word_left_in_ck << 1));
            ihdl->wav.word_left_in_ck = 0;
            ihdl->wav.word_left_in_form -= ihdl->wav.word_left_in_ck;
         }
         if( ihdl->wav.word_left_in_ck )
            return 0;
      }
      if( hdl->GetDataCount(hdl) < 16 )
         return 0;
      wavGetDword(ihdl, &data_32 );   // Get chunk id
      ihdl->wav.word_left_in_form -= 2;
      if( data_32 == 0x444e5353 )
         break;
      wavGetDword(ihdl, &data_32 );    // Get chunk size
      ihdl->wav.word_left_in_form -= 2;
      _bytes_reverse_32( data_32, ihdl->wav.word_left_in_ck )
      ihdl->wav.word_left_in_ck = ( ihdl->wav.word_left_in_ck + 1 ) >> 1;
   }
   // the ssnd is found
   wavGetDword(ihdl, &data_32 ); // chunk size
   _bytes_reverse_32( data_32, ihdl->wav.word_left_in_ck );
   ihdl->wav.word_left_in_ck = ( ihdl->wav.word_left_in_ck + 1 ) >> 1;
   wavGetDword(ihdl, &data_32 ); // SSND offset
   _bytes_reverse_32( data_32, ihdl->wav.ssnd_offset );
   wavSkipNBytes(ihdl, 4);  // blockSize
   ihdl->wav.word_left_in_ck -= 4;
   ihdl->wav.word_left_in_form -= 6;
   if( ihdl->wav.ssnd_offset == 0 )
   {
      ihdl->fileOffset += ihdl->mh.read;
      return 2;
   }
   else if( ihdl->wav.ssnd_offset & 0x01 )
      return 0;   // We don't support odd offset.
   else
   {
      ihdl->fileOffset += (ihdl->mh.read + ihdl->wav.ssnd_offset);
      ihdl->wav.ssnd_offset = 0;
      return 2;
   }

}

static bool aiffReadHeader( wavMediaHdl *ihdl )
{
   kal_uint16 data_16_a, data_16_b;
   kal_uint32 data_32;

   // file magic, 0x4d524f46 for ASCII "MROF"
   if( wavGetDword( ihdl, &data_32 ) == false || data_32 != 0x4d524f46 )
      return false;

   // chunk size
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, ihdl->wav.word_left_in_form );
   ihdl->wav.word_left_in_form = ( ihdl->wav.word_left_in_form + 1 ) >> 1;

   // aiff type
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;

   if( data_32 == 0x46464941 )   // 0x46464941 for ASCII "FFIA"
      ihdl->wav.aiff_type = IS_AIFF;
   else if( data_32 == 0x43464941 ) // 0x46464941 for ASCII "CFIA"
      ihdl->wav.aiff_type = IS_AIFF_C;
   else
      return false;
   ihdl->wav.word_left_in_form -= 2;

   // Look for the COMM chunk
   while( 1 )
   {
      if( wavGetDword( ihdl, &data_32 ) == false || data_32 == 0x444e5353 )
         return false;  // Counld not find the COMM chunk or the SSND chunk is before COMM chunk, error!
      ihdl->wav.word_left_in_form -= 2;
      if( data_32 == 0x4d4d4f43 )
         break;

      if( wavGetDword( ihdl, &data_32 ) == false )
         return false;
      _bytes_reverse_32( data_32, ihdl->wav.word_left_in_ck );
      if( wavSkipNBytes( ihdl, ihdl->wav.word_left_in_ck ) == false )
         return false;
      ihdl->wav.word_left_in_ck = ( ihdl->wav.word_left_in_ck + 1 ) >> 1;
      ihdl->wav.word_left_in_form -= (ihdl->wav.word_left_in_ck + 2);
   }
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;
   ihdl->wav.word_left_in_form -= 2;
   _bytes_reverse_32( data_32, ihdl->wav.word_left_in_ck );
   if( ihdl->wav.aiff_type == IS_AIFF && ihdl->wav.word_left_in_ck != 18 )
      return false;   // The file is AIFF and ckSize of COMM chunk is not equal to 18, error!
   ihdl->wav.word_left_in_ck = ( ihdl->wav.word_left_in_ck + 1 ) >> 1;

   // Check channel count
   if( wavGetWord( ihdl, &data_16_a) == false )
      return false;
   if( data_16_a == 0x0100 ) {
      *DSP_PCM_MS |= 0x0001;
      ihdl->wav.channel_num = 1;
      ihdl->wav.is_stereo = false;
#if  defined(MT6205B)
      ihdl->mh.mono2stereo = false;
#else
      ihdl->mh.mono2stereo = true;
#endif
   } else if( data_16_a == 0x0200 ) {
      *DSP_PCM_MS |= 0x0001;
      ihdl->wav.channel_num = 2;
      ihdl->wav.is_stereo = true;
      ihdl->mh.mono2stereo = false;
   } else
      return false;

   // numSampleFrames
   if( wavSkipNBytes(ihdl, 4) == false )
      return false;

   if( wavGetWord( ihdl, &data_16_a) == false )
      return false;
   _bytes_reverse_16( data_16_a, ihdl->wav.data_size );
   ihdl->wav.data_size >>= 3;
   if( ihdl->wav.data_size != 1 && ihdl->wav.data_size != 2 )
      return false;   // Support only 8/16 bit data

   if( wavGetWord( ihdl, &data_16_a ) == false )
      return false;
   if( wavGetWord( ihdl, &data_16_b ) == false )
      return false;
   _bytes_reverse_16( data_16_a, data_16_a );
   _bytes_reverse_16( data_16_b, data_16_b );
   data_16_a -= 16383;
   data_16_b >>= ( 15 - data_16_a );
   ihdl->wav.sampleRate = data_16_b;
   switch( data_16_b / 1000 ){
      case 7: case 8:   ihdl->wav.sr_index = 0;
         break;
      case 10: case 11: ihdl->wav.sr_index = 1;
         break;
      case 12:          ihdl->wav.sr_index = 2;
         break;
      case 15: case 16: ihdl->wav.sr_index = 3;
         break;
      case 21: case 22: ihdl->wav.sr_index = 4;
         break;
      case 23: case 24: ihdl->wav.sr_index = 5;
         break;
      case 31: case 32: ihdl->wav.sr_index = 6;
         break;
      case 43: case 44: ihdl->wav.sr_index = 7;
         break;
      case 47: case 48: ihdl->wav.sr_index = 8;
         break;
      default:
         return 0;   // The sample rate is not supported by ASP.
   }
   if( wavSkipNBytes(ihdl, 6) == false )
      return false;
   ihdl->wav.word_left_in_form -= 9;
   ihdl->wav.word_left_in_ck -= 9;
   if( ihdl->wav.aiff_type == IS_AIFF)
   {
      if( ihdl->wav.data_size == 1 ){
         ihdl->wav.Wav_PutData = wavPutData8bit;
         ihdl->wav.BitsPerSample = 8;
      }else{
         ihdl->wav.Wav_PutData = LPCM16BitPutData;
         ihdl->wav.BitsPerSample = 16;
       }
      ihdl->wav.formatTag = 0x0001;
   }
   else
   {
      if( wavGetDword( ihdl, &data_32 ) == false )
         return false;
      _bytes_reverse_32( data_32, data_32 );
      switch( data_32 )
      {
         case 0x4e4f4e45:  // "NONE"
            ihdl->wav.formatTag = 0x0001;
            if( ihdl->wav.data_size == 1 ){
               ihdl->wav.Wav_PutData = wavPutData8bit;
               ihdl->wav.BitsPerSample = 8;
            }else{
               ihdl->wav.Wav_PutData = LPCM16BitPutData;
               ihdl->wav.BitsPerSample = 16;
            }
            break;

         case 0x756c6177:  // "ulaw"
         case 0x554c4157:  // "ULAW"
            ihdl->wav.formatTag = 0x0007;
            ihdl->wav.BitsPerSample = 8;
            ihdl->wav.Wav_PutData = wavUlawPutData;
            ihdl->wav.data_size = 1;
            break;
         case 0x616c6177:  // "alaw"
         case 0x414c4157:  // "ALAW"
            ihdl->wav.formatTag = 0x0006;
            ihdl->wav.BitsPerSample = 8;
            ihdl->wav.Wav_PutData = wavAlawPutData;
            ihdl->wav.data_size = 1;
            break;
         default:
            return false;
      }
      ihdl->wav.word_left_in_form -= 2;
      ihdl->wav.word_left_in_ck -= 2;
   }
   ihdl->wav.ssnd_state = 0;
   return true;
}

static bool auReadHeader( wavMediaHdl *ihdl )
{
   kal_uint32 data_32;

   // file magic, 0x646e732e for ASCII "dns."
   if( wavGetDword( ihdl, &data_32 ) == false || data_32 != 0x646e732e )
      return false;

   // data offset
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, ihdl->wav.data_offset );

   // data length
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, ihdl->wav.data_length );

   // format id
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;

   switch( data_32 )
   {
      case 0x01000000:
         ihdl->wav.formatTag = 0x0007;
         ihdl->wav.BitsPerSample = 8;
         ihdl->wav.Wav_PutData = wavUlawPutData;
         break;
      case 0x1b000000:
         ihdl->wav.formatTag = 0x0006;
         ihdl->wav.BitsPerSample = 8;
         ihdl->wav.Wav_PutData = wavAlawPutData;
         break;
      case 0x02000000:
         ihdl->wav.formatTag = 0x0001;
         ihdl->wav.BitsPerSample = 8;
         ihdl->wav.Wav_PutData = wavPutData8bit;
         break;
      case 0x03000000:
         ihdl->wav.formatTag = 0x0001;
         ihdl->wav.BitsPerSample = 16;
         ihdl->wav.Wav_PutData = LPCM16BitPutData;
         break;
      default:
         return false;
   }

   // sample rate
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, data_32 );
   ihdl->wav.sampleRate = data_32;

   switch( data_32/1000 ) {
      case 7: case 8:   ihdl->wav.sr_index = 0;
         break;
      case 10: case 11: ihdl->wav.sr_index = 1;
         break;
      case 12:          ihdl->wav.sr_index = 2;
         break;
      case 15: case 16: ihdl->wav.sr_index = 3;
         break;
      case 21: case 22: ihdl->wav.sr_index = 4;
         break;
      case 23: case 24: ihdl->wav.sr_index = 5;
         break;
      case 31: case 32: ihdl->wav.sr_index = 6;
         break;
      case 43: case 44: ihdl->wav.sr_index = 7;
         break;
      case 47: case 48: ihdl->wav.sr_index = 8;
         break;
      default:
         return false;   // The sample rate is not supported by ASP.
   }
   // channel count
   if( wavGetDword( ihdl, &data_32 ) == false )
      return false;

   if( data_32 == 0x01000000 ) {
      *DSP_PCM_MS |= 0x0001;
      ihdl->wav.channel_num = 1;
      ihdl->wav.is_stereo = false;
#if  defined(MT6205B)
      ihdl->mh.mono2stereo = false;
#else
      ihdl->mh.mono2stereo = true;
#endif
   } else if( data_32 == 0x02000000 ) {
      *DSP_PCM_MS |= 0x0001;
      ihdl->wav.channel_num = 2;
      ihdl->wav.is_stereo = true;
      ihdl->mh.mono2stereo = false;
   } else
      return false;

   if( ihdl->wav.data_offset < 24 )
      return false;

   ihdl->fileOffset = ihdl->wav.data_offset;
   return true;
}

static void wavUpdateDataLen( wavMediaHdl *ihdl, kal_uint32 *uMBufLen)
{
   kal_uint32 wDataLength = ihdl->wav.wDataLength;
   kal_uint32 MBLen = *uMBufLen;
   
   if(ihdl->mh.mediaType != MEDIA_FORMAT_WAV) return;

   if(wDataLength >= MBLen){
      ihdl->wav.wDataLength -= MBLen;
   }else{
      *uMBufLen = wDataLength;
      ihdl->wav.wDataLength = 0;
   }
}

static Media_Status wavMFPlayFile( MHdl *hdl )
{
   kal_uint32 buf_len;
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;

   if(!hdl->uSeekProgress){
      if(hdl->start_time || hdl->current_time){
         ihdl->fileOffset = 0;
         ihdl->end_status = MEDIA_NONE;
         hdl->read = 0;
         hdl->write = 0;
         hdl->eof = KAL_FALSE;
         hdl->waiting = KAL_FALSE;
         hdl->current_time = hdl->start_time;
         ihdl->decode_EOF = false;
         ihdl->zeroCount = 0;
      }

      {  /* Fill Media Buffer to parse file header */
         kal_uint8 *pBuf;
         kal_int32 num_bytes;
         hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
         num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
         if(num_bytes < 0) return MEDIA_READ_FAIL;
         hdl->WriteDataDone( hdl, num_bytes );
      }

      switch(hdl->mediaType){
         case MEDIA_FORMAT_WAV:
              {
                 Media_Status mResult;
                 
                 /* parse file header */
                 mResult = wavReadHeader(ihdl);
                 if (mResult != MEDIA_SUCCESS)
                    return mResult;
              }

              if ( wavReachDataChunk(ihdl) == KAL_FALSE ) // reach data offset, "ihdl->fileOffset"
                 return MEDIA_BAD_FORMAT;
              break;

         case MEDIA_FORMAT_AU:
              if( !auReadHeader(ihdl) )
                 return MEDIA_BAD_FORMAT;
              break;

         case MEDIA_FORMAT_AIFF:
              if( !aiffReadHeader(ihdl) )   /* parse file header */
                 return MEDIA_BAD_FORMAT;

              if ( aiffLookForSSND(ihdl) != 2 ) // reach data offset, "ihdl->fileOffset"
                 return MEDIA_BAD_FORMAT;
              break;

         default: ASSERT(0);
      }

      hdl->write = 0;
      hdl->read = 0;
      hdl->eof = KAL_FALSE;

      if (wavSeek(ihdl)==KAL_FALSE) // update file offset at start frame
         return MEDIA_SEEK_EOF;
   }
#if defined(MT6223) || defined(MT6223P)
   if( !DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
#endif

#if defined(MT6223) || defined(MT6223P)
   // Due to loading issue, MT6223 doesn't support 44.1 kHz and 48 kHz
   if (ihdl->wav.sr_index >= 4) {
      return MEDIA_UNSUPPORTED_TYPE;
   }
#endif

   FSAL_Seek( ihdl->pstFSAL, ihdl->fileOffset);

   {
      kal_uint8  *pBuf;
      kal_uint32 uMBufLen;
      while(1){
         hdl->GetWriteBuffer(hdl, &pBuf, &uMBufLen); // Len in byte

         if(ihdl->wav.formatTag == 0x01 && ihdl->wav.BitsPerSample == 16){
            if(hdl->mediaType == MEDIA_FORMAT_WAV){
               if(uMBufLen <= 1 || hdl->eof) break;
               uMBufLen &= 0xFFFFFFFE;
               uMBufLen = autGetBytes(hdl, ihdl->pstFSAL, uMBufLen, pBuf);
               ihdl->wav.dsp_last_sample = *((uint16 *)(pBuf+uMBufLen-2));
            }else{
                if(uMBufLen <= 1 || hdl->eof) break;
                uMBufLen &= 0xFFFFFFFE;
                uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
             }
            if((kal_int32)uMBufLen < 0) return MEDIA_READ_ERROR;
            wavUpdateDataLen( ihdl, &uMBufLen);
            hdl->WriteDataDone( hdl, uMBufLen );
         }else if(((ihdl->wav.formatTag == 0x01) && (ihdl->wav.BitsPerSample == 8)) ||
                 (ihdl->wav.formatTag == 0x06) || (ihdl->wav.formatTag == 0x07)){
             if(uMBufLen <= 3 || hdl->eof) break;
             uMBufLen &= 0xFFFFFFFC;
             uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
             if((kal_int32)uMBufLen < 0) return MEDIA_READ_ERROR;
             wavUpdateDataLen( ihdl, &uMBufLen);
             hdl->WriteDataDone( hdl, uMBufLen );
          }else{
              if(uMBufLen <= 1 || hdl->eof) break;
              uMBufLen &= 0xFFFFFFFE;
              uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
              if((kal_int32)uMBufLen < 0) return MEDIA_READ_ERROR;
              wavUpdateDataLen( ihdl, &uMBufLen);
              hdl->WriteDataDone( hdl, uMBufLen );
           }
#if !defined(MT6205B) && !defined(MT6228) && !defined(MT6225) && !defined(MT6229) && !defined(MT6230) && !defined(MT6268T) && !defined(MT6235) && !defined(MT6238)
         SPT_PutPcmData( (int16*)pBuf, (uMBufLen>>1), !ihdl->wav.is_stereo );
         /* Send data for spectrum analysis */
#endif
         if((hdl->mediaType == MEDIA_FORMAT_WAV)&&(!ihdl->wav.wDataLength))
            hdl->eof = KAL_TRUE;
      }
   }

#if defined(__BT_SUPPORT__)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if ( (AM_IsBluetoothOn() == true) && (ihdl->wav.sr_index == 0) && (ihdl->wav.is_stereo == false) ) {
      hdl->mono2stereo = false;
      ihdl->wav.is_8KVoice = true;
   }
#endif
#endif

   wavOpenDevice(ihdl, true);
   hdl->state = WAV_STATE_PLAYING;

   {
      kal_uint32 uBitRate = ihdl->wav.sampleRate * ( ihdl->wav.is_stereo + 1 ) * ihdl->wav.BitsPerSample;
      if(uBitRate)
         hdl->uTotalDuration = (kal_uint64)ihdl->file_size * 8000 / (kal_uint64)uBitRate; // in ms
   }

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status pcmMFPlayFile( MHdl *hdl )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;

   ihdl->fileOffset = 0;
   ihdl->end_status = MEDIA_NONE;
   hdl->read = 0;
   hdl->write = 0;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->current_time = hdl->start_time;
   ihdl->wav.sr_index = 0;  // 8k Hz
   ihdl->wav.channel_num = 1;
   ihdl->wav.is_stereo = false;
   ihdl->wav.sampleRate = 8000;
#if defined(MT6205B)
   hdl->mono2stereo = false;
#else
   hdl->mono2stereo = true;
#endif
   ihdl->wav.is_8KVoice = false;
   ihdl->decode_EOF = false;
   ihdl->zeroCount = 0;

   switch (hdl->mediaType) {
      case MEDIA_FORMAT_PCM_16K:
         ihdl->wav.sampleRate = 16000;
         ihdl->wav.sr_index = 3;
      case MEDIA_FORMAT_PCM_8K:
         ihdl->wav.BitsPerSample = 16;
         ihdl->wav.formatTag   = 0x0001;
         ihdl->wav.Wav_PutData = LPCM16BitPutData;
         break;
      case MEDIA_FORMAT_G711_ALAW:
         ihdl->wav.BitsPerSample = 8;
         ihdl->wav.formatTag   = 0x0006;
         ihdl->wav.Wav_PutData = wavAlawPutData;
         break;
      case MEDIA_FORMAT_G711_ULAW:
         ihdl->wav.BitsPerSample = 8;
         ihdl->wav.formatTag   = 0x0007;
         ihdl->wav.Wav_PutData = wavUlawPutData;
         break;
      case MEDIA_FORMAT_DVI_ADPCM:
         ihdl->wav.BitsPerSample = 4;
         ihdl->wav.formatTag   = 0x0011;
         ihdl->wav.wBlockAlign  = 256;
         ihdl->wav.samplesPerBlock = 512;
         ihdl->wav.Wav_PutData = pcmDviADPCMPutDataMono;
         break;
      default:
         ASSERT(0);
   }

   if (hdl->mediaType == MEDIA_FORMAT_DVI_ADPCM) {
   	  if (hdl->start_time != 0)
         return MEDIA_SEEK_FAIL;
   } else if (wavSeek(ihdl)==KAL_FALSE) {
      return MEDIA_SEEK_FAIL;
   }
#if defined(MT6223) || defined(MT6223P)
   if( !DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
#endif
   FSAL_Seek( ihdl->pstFSAL, ihdl->fileOffset);

   {
      kal_uint8  *pBuf;
      kal_uint32 uMBufLen;
      while(1){
         hdl->GetWriteBuffer(hdl, &pBuf, &uMBufLen); // Len in byte

         if ( (hdl->mediaType == MEDIA_FORMAT_PCM_8K) || (hdl->mediaType == MEDIA_FORMAT_PCM_16K) ) {
            if(uMBufLen == 0 || hdl->eof) break;
            uMBufLen = autGetBytes(hdl, ihdl->pstFSAL, uMBufLen, pBuf);
            if((kal_int32)uMBufLen < 0) return MEDIA_READ_ERROR;
            hdl->WriteDataDone( hdl, uMBufLen );
         } else if (hdl->mediaType == MEDIA_FORMAT_DVI_ADPCM){
             if(uMBufLen <= 1 || hdl->eof) break;
             uMBufLen &= 0xFFFFFFFE;
             uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
             if((kal_int32)uMBufLen < 0) return MEDIA_READ_ERROR;
             hdl->WriteDataDone( hdl, uMBufLen );
         } else {  // A-law and U-law
             if(uMBufLen <= 3 || hdl->eof) break;
             uMBufLen &= 0xFFFFFFFC;
             uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
             if((kal_int32)uMBufLen < 0) return MEDIA_READ_ERROR;
             hdl->WriteDataDone( hdl, uMBufLen );
         }
#if !defined(MT6205B) && !defined(MT6228) && !defined(MT6225) && !defined(MT6229) && !defined(MT6230) && !defined(MT6268T) && !defined(MT6235) && !defined(MT6238)
         SPT_PutPcmData( (int16*)pBuf, (uMBufLen>>1), !ihdl->wav.is_stereo );
         /* Send data for spectrum analysis */
#endif
      }
   }

#if defined(__BT_SUPPORT__)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if ( (AM_IsBluetoothOn() == true) && (hdl->mediaType != MEDIA_FORMAT_PCM_16K) && (ihdl->wav.is_stereo == false) ) {
      hdl->mono2stereo = false;
      ihdl->wav.is_8KVoice = true;
   }
#endif
#endif

   pcmOpenDevice(ihdl);
   hdl->state = WAV_STATE_PLAYING;
   return MEDIA_SUCCESS;
}

static Media_Status wavMFStop( MHdl *hdl )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;

   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
   if( hdl->state == WAV_STATE_PLAY_PAUSE || hdl->state == WAV_STATE_IDLE ){
      kal_give_sem( WAVsema );
      return MEDIA_SUCCESS;
   }

   ihdl->end_status = MEDIA_TERMINATED;
   wavCloseDevice( ihdl );

   hdl->uSeekProgress = 0;
   hdl->state = WAV_STATE_IDLE;
   
   kal_give_sem( WAVsema );

   kal_trace( TRACE_FUNC, L1AUDIO_STOP, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status wavMFPause( MHdl *hdl )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;

   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );

   ASSERT( hdl->state == WAV_STATE_PLAYING );

   ihdl->end_status = MEDIA_TERMINATED;
   wavCloseDevice( ihdl );

   hdl->uSeekProgress = 0;
   hdl->state = WAV_STATE_PLAY_PAUSE;
   
   kal_give_sem( WAVsema );

   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status pcmMFPause( MHdl *hdl )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;

   ASSERT( hdl->state == WAV_STATE_PLAYING );

   if (hdl->mediaType == MEDIA_FORMAT_DVI_ADPCM)
      return MEDIA_UNSUPPORTED_OPERATION;

   ihdl->end_status = MEDIA_TERMINATED;
   wavCloseDevice( ihdl );

   hdl->state = WAV_STATE_PLAY_PAUSE;
   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status wavMFResumeFile( MHdl *hdl )
{
   hdl->start_time = hdl->current_time;
   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );
   return wavMFPlayFile(hdl);
}

static Media_Status pcmMFResumeFile( MHdl *hdl )
{
   hdl->start_time = hdl->current_time;
   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );
   return pcmMFPlayFile(hdl);
}

Media_Event wavMFProcess( MHdl *hdl, Media_Event event )
{
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch(event)
   {
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
         if( hdl->state == WAV_STATE_PLAYING )
            wavCloseDevice( ihdl );
         hdl->uSeekProgress = 0;
         hdl->state = WAV_STATE_IDLE;
         return event;
      case MEDIA_ERROR:
         if( hdl->state == WAV_STATE_PLAYING )
            wavCloseDevice( ihdl );
         hdl->uSeekProgress = 0;
         hdl->state = WAV_STATE_IDLE;
         return event;
      case MEDIA_DATA_REQUEST:

         kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
         L1Audio_SetEvent( ihdl->aud_id_decoder, hdl );
         kal_give_sem( WAVsema );
         if( ihdl->read_error ) return MEDIA_READ_ERROR;
         return MEDIA_NONE;
#if !defined(__PRODUCTION_RELEASE__)
      default:
         ASSERT(0); // should never reach here
#endif
   }
   return MEDIA_NONE;
}

static void wavDecodeTask( void *data )
{
   MHdl *hdl = (MHdl *)data;
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;

   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
   if( hdl->state != WAV_STATE_PLAYING ){
      hdl->waiting = KAL_FALSE;
      kal_give_sem( WAVsema );
      return;
   }
   {
      kal_uint8  *pBuf;
      kal_uint32 uMBufLen;
      while(1){
         hdl->GetWriteBuffer(hdl, &pBuf, &uMBufLen); // Len in byte

         if(ihdl->wav.formatTag == 0x01 && ihdl->wav.BitsPerSample == 16){
            if ( (hdl->mediaType == MEDIA_FORMAT_WAV)    ||
                 (hdl->mediaType == MEDIA_FORMAT_PCM_8K) ||
                 (hdl->mediaType == MEDIA_FORMAT_PCM_16K) ) {
               if(uMBufLen == 0 || hdl->eof) break;
               uMBufLen = autGetBytes(hdl, ihdl->pstFSAL, uMBufLen, pBuf);
               ihdl->wav.dsp_last_sample = *((uint16 *)(pBuf+uMBufLen-2));
            }else{
                if(uMBufLen <= 1 || hdl->eof) break;
                uMBufLen &= 0xFFFFFFFE;
                uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
             }
            if((kal_int32)uMBufLen < 0){
               ihdl->read_error = true;
               hdl->waiting = KAL_FALSE;
               kal_give_sem( WAVsema );
               return;
            }
            wavUpdateDataLen( ihdl, &uMBufLen);
            hdl->WriteDataDone( hdl, uMBufLen );
         }else if(((ihdl->wav.formatTag == 0x01) && (ihdl->wav.BitsPerSample == 8)) ||
                 (ihdl->wav.formatTag == 0x06) || (ihdl->wav.formatTag == 0x07)){
             if(uMBufLen <= 3 || hdl->eof) break;
             uMBufLen &= 0xFFFFFFFC;
             uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
             if((kal_int32)uMBufLen < 0){
                ihdl->read_error = true;
                hdl->waiting = KAL_FALSE;
                kal_give_sem( WAVsema );
                return;
             }
             wavUpdateDataLen( ihdl, &uMBufLen);
             hdl->WriteDataDone( hdl, uMBufLen );
          }else{
              if(uMBufLen <= 1 || hdl->eof) break;
              uMBufLen &= 0xFFFFFFFE;
              uMBufLen = ihdl->wav.Wav_PutData(hdl, uMBufLen);
              if((kal_int32)uMBufLen < 0){
                ihdl->read_error = true;
                hdl->waiting = KAL_FALSE;
                kal_give_sem( WAVsema );
                return;
              }
              wavUpdateDataLen( ihdl, &uMBufLen);
              hdl->WriteDataDone( hdl, uMBufLen );
           }
#if !defined(MT6205B) && !defined(MT6228) && !defined(MT6225) && !defined(MT6229) && !defined(MT6230) && !defined(MT6268T) && !defined(MT6235) && !defined(MT6238)
         SPT_PutPcmData( (int16*)pBuf, (uMBufLen>>1), !ihdl->wav.is_stereo );
         /* Send data for spectrum analysis */
#endif
         if((hdl->mediaType == MEDIA_FORMAT_WAV)&&(!ihdl->wav.wDataLength))
            hdl->eof = KAL_TRUE;
      }
   }
   hdl->waiting = KAL_FALSE;
   kal_give_sem( WAVsema );
}

static void wavHdlInit(wavMediaHdl *ihdl)
{
   MHdl *hdl = (MHdl *) ihdl;

   hdl->state     = WAV_STATE_IDLE;
   hdl->Close     = wavMFClose;
   hdl->Pause     = wavMFPause;
   hdl->Stop      = wavMFStop;
   hdl->Process   = wavMFProcess;

   hdl->Play      = wavMFPlayFile;
   hdl->Resume    = wavMFResumeFile;
   FSAL_GetFileSize( ihdl->pstFSAL, &ihdl->file_size);

}

MHdl *WAV_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   wavMediaHdl *ihdl;

#if APM_SUPPORT
   ihdl = (wavMediaHdl*) APM_Allocate_Buffer(sizeof(wavMediaHdl));
   if (ihdl != NULL)
   {
      memset(ihdl, 0, sizeof(wavMediaHdl));
      ihdl->fUseTCMFromAPM = true;
   }
   else
#endif
   {
      ihdl = (wavMediaHdl*)get_ctrl_buffer( sizeof(wavMediaHdl) );
      memset(ihdl, 0, sizeof(wavMediaHdl));
   }
   
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, DP_D2C_PCM_P, wavHisr );

   hdl->mediaType = MEDIA_FORMAT_WAV;
   hdl->handler   = handler;
   ihdl->pstFSAL  = pstFSAL;
   wavHdlInit(ihdl);
   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, wavDecodeTask );

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, hdl->mediaType );

   return hdl;
}

#if defined( AIFF_DECODE )
MHdl *AIFF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   wavMediaHdl *ihdl;

#if APM_SUPPORT
   ihdl = (wavMediaHdl*) APM_Allocate_Buffer(sizeof(wavMediaHdl));
   if (ihdl != NULL)
   {
      memset(ihdl, 0, sizeof(wavMediaHdl));
      ihdl->fUseTCMFromAPM = true;
   }
   else
#endif
   {
      ihdl = (wavMediaHdl*)get_ctrl_buffer( sizeof(wavMediaHdl) );
      memset(ihdl, 0, sizeof(wavMediaHdl));
   }

   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, DP_D2C_PCM_P, wavHisr );

   hdl->handler   = handler;
   ihdl->pstFSAL  = pstFSAL;
   hdl->mediaType = MEDIA_FORMAT_AIFF;
   wavHdlInit(ihdl);
   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, wavDecodeTask );

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, hdl->mediaType );

   return hdl;
}
#endif

#if defined( AU_DECODE )
MHdl *AU_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   wavMediaHdl *ihdl;

#if APM_SUPPORT
   ihdl = (wavMediaHdl*) APM_Allocate_Buffer(sizeof(wavMediaHdl));
   if (ihdl != NULL)
   {
      memset(ihdl, 0, sizeof(wavMediaHdl));
      ihdl->fUseTCMFromAPM = true;
   }
   else
#endif
   {
      ihdl = (wavMediaHdl*)get_ctrl_buffer( sizeof(wavMediaHdl) );
      memset(ihdl, 0, sizeof(wavMediaHdl));
   }

   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, DP_D2C_PCM_P, wavHisr );

   hdl->handler   = handler;
   ihdl->pstFSAL  = pstFSAL;
   hdl->mediaType = MEDIA_FORMAT_AU;
   wavHdlInit(ihdl);
   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, wavDecodeTask );

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, hdl->mediaType );

   return hdl;
}
#endif

MHdl *PCM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   wavMediaHdl *ihdl;
   Media_VM_PCM_Param *pcm_param = (Media_VM_PCM_Param *) param;

#if APM_SUPPORT
   ihdl = (wavMediaHdl*) APM_Allocate_Buffer(sizeof(wavMediaHdl));
   if (ihdl != NULL)
   {
      memset(ihdl, 0, sizeof(wavMediaHdl));
      ihdl->fUseTCMFromAPM = true;
   }
   else
#endif
   {
      ihdl = (wavMediaHdl*)get_ctrl_buffer( sizeof(wavMediaHdl) );
      memset(ihdl, 0, sizeof(wavMediaHdl));
   }

   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, DP_D2C_PCM_P, wavHisr );

   ihdl->aud_id_decoder = L1Audio_GetAudioID();

   L1Audio_SetEventHandler( ihdl->aud_id_decoder, wavDecodeTask );

   hdl->handler   = handler;
   hdl->mediaType = pcm_param->mediaType;
   ihdl->pstFSAL  = pstFSAL;

   hdl->state     = WAV_STATE_IDLE;
   hdl->Close     = wavMFClose;
   hdl->Pause     = pcmMFPause;
   hdl->Stop      = wavMFStop;
   hdl->Process   = wavMFProcess;
   hdl->Play      = pcmMFPlayFile;
   hdl->Resume    = pcmMFResumeFile;
   FSAL_GetFileSize( ihdl->pstFSAL, &ihdl->file_size);

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, hdl->mediaType );

   return hdl;
}

Media_Status WAV_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   MHdl *hdl;
   wavMediaHdl *ihdl;
   Media_Status mResult;

   ihdl = (wavMediaHdl*)get_ctrl_buffer( sizeof(wavMediaHdl) );
   memset(ihdl, 0, sizeof(wavMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, 0xFFFF, wavHisr );
   ihdl->pstFSAL = pstFSAL;
   hdl->rb_base = (kal_uint8 *)&ihdl->buf[0];
   hdl->rb_size = WAV_MAX_DATA_REQUESTED;

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

   {  /* Fill Media Buffer to parse file header */
      kal_int32 num_bytes;
      num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, WAV_MAX_DATA_REQUESTED, (kal_uint8 *)&ihdl->buf[0]);
      if(num_bytes < 0){
         mhdlFinalize( hdl, 0xFFFF );
         free_ctrl_buffer( ihdl );
         return MEDIA_READ_FAIL;
      }
      hdl->write += num_bytes;
   }

   /* parse file header */
   mResult = wavReadHeader(ihdl);
   if (mResult != MEDIA_SUCCESS) {   
      mhdlFinalize( hdl, 0xFFFF );
      free_ctrl_buffer( ihdl );
      return mResult;
   }

   if ( wavReachDataChunk(ihdl) == KAL_FALSE ){ // reach data offset, "ihdl->fileOffset"
      mhdlFinalize( hdl, 0xFFFF );
      free_ctrl_buffer( ihdl );
      return MEDIA_BAD_FORMAT;
   }

   contentInfo->bitRate = ihdl->wav.AvgBytesPerSec * 8;
   contentInfo->stereo = ihdl->wav.is_stereo;
   contentInfo->sampleRate = ihdl->wav.sampleRate;

   {
      kal_uint32 file_size;
      FSAL_GetFileSize( ihdl->pstFSAL, &file_size);
      if(contentInfo->bitRate)
         contentInfo->time = (kal_uint64)file_size * 8000 / (kal_uint64)contentInfo->bitRate; // in ms
   }

   mhdlFinalize( hdl, 0xFFFF );
   free_ctrl_buffer( ihdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, MEDIA_FORMAT_WAV );
   return MEDIA_SUCCESS;
}

Media_Status WAV_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
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

   ret = WAV_GetContentDescInfo( pstFSAL, contentInfo, (void *)0 );

   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   return ret;
}

#if defined( AIFF_DECODE )
Media_Status AIFF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   MHdl *hdl;
   wavMediaHdl *ihdl;

   ihdl = (wavMediaHdl*)get_ctrl_buffer( sizeof(wavMediaHdl) );
   memset(ihdl, 0, sizeof(wavMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, 0xFFFF, wavHisr );
   ihdl->pstFSAL = pstFSAL;
   hdl->rb_base = (kal_uint8 *)&ihdl->buf[0];
   hdl->rb_size = WAV_MAX_DATA_REQUESTED;

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

   {  /* Fill Media Buffer to parse file header */
      kal_int32 num_bytes;
      num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, WAV_MAX_DATA_REQUESTED, (kal_uint8 *)&ihdl->buf[0]);
      if(num_bytes < 0){
          mhdlFinalize( hdl, 0xFFFF );
          free_ctrl_buffer( ihdl );
          return MEDIA_READ_FAIL;
      }
      hdl->write += num_bytes;
   }

   if( !aiffReadHeader(ihdl) ){   /* parse file header */
      mhdlFinalize( hdl, 0xFFFF );
      free_ctrl_buffer( ihdl );
      return MEDIA_BAD_FORMAT;
   }

   if ( aiffLookForSSND(ihdl) != 2 ){ // reach data offset, "ihdl->fileOffset"
      mhdlFinalize( hdl, 0xFFFF );
      free_ctrl_buffer( ihdl );
      return MEDIA_BAD_FORMAT;
   }

   contentInfo->stereo = ihdl->wav.is_stereo;
   contentInfo->sampleRate = ihdl->wav.sampleRate;
   contentInfo->bitRate = ihdl->wav.sampleRate * ( ihdl->wav.is_stereo + 1 ) * ihdl->wav.BitsPerSample;

   {
      kal_uint32 file_size;
      FSAL_GetFileSize( ihdl->pstFSAL, &file_size);
      file_size -= ihdl->wav.data_offset;
      contentInfo->time = (kal_uint64)file_size * 8000 / (kal_uint64)contentInfo->bitRate; // in ms
   }

   mhdlFinalize( hdl, 0xFFFF );
   free_ctrl_buffer( ihdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, MEDIA_FORMAT_AIFF );
   return MEDIA_SUCCESS;
}

Media_Status AIFF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
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

   ret = AIFF_GetContentDescInfo( pstFSAL, contentInfo, (void *)0 );

   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   return ret;
}
#endif

#if defined( AU_DECODE )
Media_Status AU_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   MHdl *hdl;
   wavMediaHdl *ihdl;

   ihdl = (wavMediaHdl*)get_ctrl_buffer( sizeof(wavMediaHdl) );
   memset(ihdl, 0, sizeof(wavMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, 0xFFFF, wavHisr );
   ihdl->pstFSAL = pstFSAL;
   hdl->rb_base = (kal_uint8 *)&ihdl->buf[0];
   hdl->rb_size = WAV_MAX_DATA_REQUESTED;

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

   {  /* Fill Media Buffer to parse file header */
      kal_int32 num_bytes;
      num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, WAV_MAX_DATA_REQUESTED, (kal_uint8 *)&ihdl->buf[0]);
      if(num_bytes < 0){
         mhdlFinalize( hdl, 0xFFFF );
         free_ctrl_buffer( ihdl );
         return MEDIA_READ_FAIL;
      }
      hdl->write += num_bytes;
   }

   if( !auReadHeader(ihdl) ){
      mhdlFinalize( hdl, 0xFFFF );
      free_ctrl_buffer( ihdl );
      return MEDIA_BAD_FORMAT;
   }

   contentInfo->stereo = ihdl->wav.is_stereo;
   contentInfo->sampleRate = ihdl->wav.sampleRate;
   contentInfo->bitRate = ihdl->wav.sampleRate * ( ihdl->wav.is_stereo + 1 ) * ihdl->wav.BitsPerSample;

   {
      kal_uint32 file_size;
      FSAL_GetFileSize( ihdl->pstFSAL, &file_size);
      file_size -= ihdl->wav.data_offset;
      contentInfo->time = (kal_uint64)file_size * 8000 / (kal_uint64)contentInfo->bitRate; // in ms
   }

   mhdlFinalize( hdl, 0xFFFF );
   free_ctrl_buffer( ihdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, MEDIA_FORMAT_AU );
   return MEDIA_SUCCESS;
}

Media_Status AU_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
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

   ret = AU_GetContentDescInfo( pstFSAL, contentInfo, (void *)0 );

   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   return ret;
}
#endif

Media_Status PCM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   kal_uint32 file_size;
   Media_Format eFormat;

   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->author[0]  = '\0';
   contentInfo->copyright[0]  = '\0';
   contentInfo->date[0]  = '\0';
   contentInfo->time = 0;
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 8000;
   contentInfo->stereo = false;

   eFormat = (Media_Format) ((kal_uint32)param);
   FSAL_GetFileSize(pstFSAL, &file_size);
   switch (eFormat) {
      case MEDIA_FORMAT_DVI_ADPCM:
         contentInfo->time = (file_size >> 2);
         contentInfo->bitRate = 32000;
         break;
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
         contentInfo->time = (file_size >> 3);
         contentInfo->bitRate = 64000;
         break;
      case MEDIA_FORMAT_PCM_8K:
         contentInfo->time = (file_size >> 4);
         contentInfo->bitRate = 128000;
         break;
      case MEDIA_FORMAT_PCM_16K:
         contentInfo->sampleRate = 16000;
         contentInfo->time = (file_size >> 5);
         contentInfo->bitRate = 256000;
      default:
         ASSERT(0);
   }
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, eFormat );
   return MEDIA_SUCCESS;
}
#endif
