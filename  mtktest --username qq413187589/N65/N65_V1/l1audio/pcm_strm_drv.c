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
 * pcm_strm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Streaming PCM Playback and Record
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

#ifndef __L1_STANDALONE__ // avoid link error

#include "wav.h"
#include "kal_trace.h"
#include "l1sp_trc.h"

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

#define FRAME_BUF_SIZE 160

// This flag is for DSP to record stereo PCM in dedicated mode
// #define  DSP_DEBUG_DEDICATED_MODE_RECORD


typedef struct pcmStrm_Internal {
   kal_bool         isPlayback;        // true:Playback, false:Record
   kal_bool         isStereo;
   kal_bool         dedicated_mode;
   kal_bool         is8KVoice;
   kal_int8         bitPerSample;
   kal_uint8        freqType;
   kal_uint16       sampleFreq;
   kal_uint16       dsp_last_sample;
} pcmStrmInternal;

typedef struct pcmStrm_MediaHdlInternal {
   MHdl             mh;
   pcmStrmInternal  pcmStrm;
   Media_Event      end_status;
   kal_uint32       accumulateSize;    // In sample
   kal_uint32       accumulateTime;    // In milli-second
   kal_uint16       frameDuration;

   // EOF handling
   kal_bool         decode_EOF;
   kal_int32        zeroCount;
} pcmStrmMediaHdl;


static void pcmStrmOpenDevice( pcmStrmMediaHdl *ihdl )
{
   uint16 I;

   ihdl->end_status = MEDIA_NONE;
   ihdl->mh.dsp_rb_base = 0;
   mhdlDisallowSleep( (MHdl*)ihdl );
   ASSERT(*DSP_PCM_CTRL == 0);

#if defined(MT6205B)
   if ( ihdl->pcmStrm.freqType == 0x20 )      // sampling frequency: 16k
      AM_PCM16K_PlaybackOn();
   else                                       // sampling frequency: 8k
      AM_PCM8K_PlaybackOn();
#else
   *DSP_PCM_MS |= 0x0001;
#if !defined(__BT_AUDIO_VIA_SCO__)
   if ( ihdl->pcmStrm.is8KVoice ) {
      AM_PCM8K_PlaybackOn();
   } else 
#endif
   {
#if defined( DSP_WT_SYN )
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ihdl->pcmStrm.freqType );
   }
#endif

   *DSP_PCM_CTRL = 1;
   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );
   for ( I = 0; ; I++ ) {
      if ( *DSP_PCM_CTRL == 8 || ihdl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
}

static void pcmStrmRecOpenDevice( pcmStrmMediaHdl *ihdl )
{
   uint16 I;

   ihdl->end_status = MEDIA_NONE;
   mhdlDisallowSleep( (MHdl*)ihdl );
   if (ihdl->pcmStrm.dedicated_mode) {  // PCM recording in TCH mode/
      AM_PCM8K_RecordOn();
   } else {
      *DSP_PCM_REC_CTRL  = 0x200;
      AM_PCM8K_RecordOn();
      for ( I = 0; ; I++ ) {
         if ( *DSP_PCM_REC_CTRL == 0x400 )
            break;
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
}

static void pcmStrmCloseDevice( MHdl *hdl )
{
   uint16 I, ctl;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   
   for ( I = 0; ; I++ ) {
      ctl = *DSP_PCM_CTRL;
      if ( ctl == 0 )                // DSP returns to idle state
         break;
      if ( ctl == 8 ) {
         *DSP_PCM_CTRL = WAV_ABORT_STATE;       // give ABORT command to the DSP
         kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      }
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
   kal_trace( TRACE_STATE, L1AUDIO_IDLE_STATE );

#if defined(MT6205B)
   if( ihdl->pcmStrm.freqType == 0x20 )   // sampling frequency: 16k
      AM_PCM16K_PlaybackOff( true );
   else                                   // sampling frequency: 8k
      AM_PCM8K_PlaybackOff( true );
#else
#if !defined(__BT_AUDIO_VIA_SCO__)
   if ( ihdl->pcmStrm.is8KVoice )
      AM_PCM8K_PlaybackOff( true );
   else
#endif
      AM_AudioPlaybackOff( true );
#endif
   mhdlAllowSleep( hdl );
}

static void pcmStrmRecCloseDevice( MHdl *hdl )
{
   uint16 I, ctl;

   for ( I = 0; ; I++ ) {
      ctl = *DSP_PCM_REC_CTRL;
      if ( ctl == 0 )                // DSP returns to idle state
         break;
      if ( ctl == 0x400 )
         *DSP_PCM_REC_CTRL = 0x800;  // give ABORT command to the DSP
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
   AM_PCM8K_RecordOff( true );
   mhdlAllowSleep( hdl );
}

static void pcmWriteDataSegmentByIDMA(pcmStrmMediaHdl *ihdl, int32 DSP_FreeSeg)
{
   const uint16 *buf;
   uint16 dsp_last_sample, dsp_w, read_data;
   int32 I;

   dsp_w = *DSP_PCM_W;

   buf = (uint16 *)&ihdl->mh.rb_base[ihdl->mh.read];

   if (ihdl->mh.mono2stereo){
      if (ihdl->pcmStrm.bitPerSample == 16) {
         dsp_last_sample = *buf++;
         *DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w) = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         for (I=DSP_FreeSeg-2; I>0; I-=2) {
            dsp_last_sample = *buf++;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
         }
         ihdl->mh.read += (DSP_FreeSeg);
      } else {
         read_data = *buf++;
         dsp_last_sample = (read_data<<8) - 0x8000;
         *DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w) = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         dsp_last_sample = (read_data & 0xFF00) - 0x8000;   	
         *IDMA_SHORT_ADDR = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         for (I=DSP_FreeSeg-4; I>0; I-=4) {
            read_data = *buf++;
            dsp_last_sample = (read_data<<8) - 0x8000;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            dsp_last_sample = (read_data & 0xFF00) - 0x8000;   	
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
         }
         ihdl->mh.read += (DSP_FreeSeg >> 1);
      }
   } else {
      if (ihdl->pcmStrm.bitPerSample == 16) {
         *DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w) = *buf++;
         for (I=DSP_FreeSeg-1; I>0; I--) {
            *IDMA_SHORT_ADDR = *buf++;
         }
         ihdl->mh.read += (DSP_FreeSeg << 1);
         dsp_last_sample = *(--buf);
      } else {
         read_data = *buf++;
         *DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w) = (read_data<<8) - 0x8000;
         *IDMA_SHORT_ADDR = (read_data & 0xFF00) - 0x8000;
         for (I=DSP_FreeSeg-2; I>0; I-=2) {
            read_data = *buf++;
            *IDMA_SHORT_ADDR = (read_data<<8) - 0x8000;
            *IDMA_SHORT_ADDR = (read_data & 0xFF00) - 0x8000;
         }
         ihdl->mh.read += (DSP_FreeSeg);
         dsp_last_sample = (read_data & 0xFF00) - 0x8000;
      }
   }
   ihdl->pcmStrm.dsp_last_sample = dsp_last_sample;
   ihdl->accumulateSize += DSP_FreeSeg;
}

static void pcmReadDataSegment(pcmStrmMediaHdl *ihdl)
{
   int32 first_data_block_len, second_data_block_len;
   int32 I, tmp, count;
   uint16 dummy;
   int16 *buf;

   buf = (int16 *)&ihdl->mh.rb_base[ihdl->mh.write];

   if (ihdl->pcmStrm.dedicated_mode){    // WAV recording in TCH mode
      ASSERT( *DP_TCH_UL_LEN == FRAME_BUF_SIZE );   // uplink frame size
      ASSERT( *DP_TCH_DL_LEN == FRAME_BUF_SIZE );   // downlink frame size

#ifdef DSP_DEBUG_DEDICATED_MODE_RECORD
      // Uplink
      first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      dummy = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_PTR);
      for ( I = first_data_block_len; I > 0; I-- ) {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      if ( second_data_block_len > 0 ) {
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_BUF_ADDR0);
         for ( I = second_data_block_len; I > 0 ; I-- ) {
            *buf = (int16)(*IDMA_SHORT_ADDR);
            buf += 2;
         }
      }
      
      // Downlink
      buf -= ((FRAME_BUF_SIZE << 1) - 1);
      first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      dummy = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR);
      for ( I = first_data_block_len; I > 0; I-- ) {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      if ( second_data_block_len > 0 ) {
         dummy = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0);
         for ( I = second_data_block_len; I > 0; I-- ) {
            *buf = (int16)(*IDMA_SHORT_ADDR);
            buf += 2;
         }
      }
#else
      // handle uplink data
      first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      dummy = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_PTR);
      for ( I = first_data_block_len; I > 0; I-- )
         *buf++ = (int16)(*IDMA_SHORT_ADDR);
      if (second_data_block_len > 0 ) {
         dummy = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_BUF_ADDR0);
         for ( I = second_data_block_len; I > 0; I-- )
            *buf++ = (int16)(*IDMA_SHORT_ADDR);
      }

      // handle downlink data
      buf -= FRAME_BUF_SIZE;
      first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      // Mix Uplink and Download
      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR);
      for ( I = first_data_block_len; I > 0; I-- ) {
         tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
         *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp < -32768)? -32768:tmp);
      }
      if ( second_data_block_len > 0 ) {
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0);
         for ( I = second_data_block_len; I > 0; I-- ) {
            tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
            *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp < -32768)? -32768:tmp);
         }
      }
#endif
   } else {
      count = (int32)(*DSP_PCM_REC_LEN);
      dummy = *DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR);
      for ( I = count; I > 0; I-- )
         *buf++ = (int16)(*IDMA_SHORT_ADDR);
   }

   // Update media buffer write pointer
   {
      MHdl *hdl = (MHdl *) ihdl;
#ifdef DSP_DEBUG_DEDICATED_MODE_RECORD
      if (ihdl->pcmStrm.dedicated_mode) {
         hdl->WriteDataDone(hdl, (FRAME_BUF_SIZE << 2));
      } else {
         hdl->WriteDataDone(hdl, (FRAME_BUF_SIZE << 1));
      }
#else
      hdl->WriteDataDone(hdl, (FRAME_BUF_SIZE << 1));
#endif
      hdl->waiting = KAL_FALSE;
   }
}

static void pcmWriteDataByIDMA(pcmStrmMediaHdl *ihdl, int32 mbDecodeLen)
{
   int32 count, DSP_FreeLenLow, dsp_r, DSP_FreeLen;
   uint16 dsp_w;

   dsp_w = *DSP_PCM_W;

   do {
      dsp_r = (int32)*DSP_PCM_R;
   } while( dsp_r != (int32)*DSP_PCM_R );

   DSP_FreeLen = dsp_r - (int32)dsp_w - 1;
   if ( DSP_FreeLen < 0 )
      DSP_FreeLen += ihdl->mh.dsp_rb_size;

   if (ihdl->mh.mono2stereo){
      mbDecodeLen <<= 1;
      DSP_FreeLen &= 0xFFFC;
   } else {
      DSP_FreeLen &= 0xFFFE;
   }

   if ( DSP_FreeLen < mbDecodeLen )
      mbDecodeLen = DSP_FreeLen;

   if ( mbDecodeLen == 0 )
      return;

   DSP_FreeLenLow = (int32)(ihdl->mh.dsp_rb_size - dsp_w);
   if ( DSP_FreeLenLow > mbDecodeLen )
      DSP_FreeLenLow = mbDecodeLen;

   pcmWriteDataSegmentByIDMA(ihdl, DSP_FreeLenLow);
   kal_prompt_trace( MOD_L1SPHISR, "Addr=%d, Len=%d", (dsp_w+ihdl->mh.dsp_rb_base), DSP_FreeLenLow );

   dsp_w += (uint16)DSP_FreeLenLow;
   if ( dsp_w >= ihdl->mh.dsp_rb_size )
      dsp_w = 0;

   *DSP_PCM_W = dsp_w;
   count = mbDecodeLen - DSP_FreeLenLow;

   if ( count > 0 ) {
      pcmWriteDataSegmentByIDMA(ihdl, count);
      *DSP_PCM_W = dsp_w + (uint16)count;

      kal_prompt_trace( MOD_L1SPHISR, "Addr=%d, Len=%d", (dsp_w+ihdl->mh.dsp_rb_base), count );
   }
}

static void pcmWriteDataToDSP(pcmStrmMediaHdl *ihdl)
{
   int32 mbDataLen, mbDataLenLow, mbDataLenHigh;

   if (ihdl->pcmStrm.bitPerSample == 16) {
      mbDataLen = ihdl->mh.GetDataCount((MHdl *)ihdl) >> 1;      // in word
      mbDataLenLow = (ihdl->mh.rb_size - ihdl->mh.read) >> 1;    // in word
   } else {
      mbDataLen = ihdl->mh.GetDataCount((MHdl *)ihdl);           // decoded size in word
      mbDataLenLow = (ihdl->mh.rb_size - ihdl->mh.read);         // decoded size in word
   }

   if( mbDataLenLow > mbDataLen )
      mbDataLenLow = mbDataLen;
   mbDataLenHigh = mbDataLen - mbDataLenLow;

   pcmWriteDataByIDMA( ihdl, mbDataLenLow );

   ASSERT(ihdl->mh.read <= ihdl->mh.rb_size);
   if( ihdl->mh.read >= ihdl->mh.rb_size ){
      ihdl->mh.read = 0;
      if( mbDataLenHigh > 0 )
         pcmWriteDataByIDMA( ihdl, mbDataLenHigh );
   }
}

static void pcmReadDataFromDSP(pcmStrmMediaHdl *ihdl)
{
   int32 dspRecLen, count;
   MHdl *hdl = (MHdl *) ihdl;

   count = hdl->GetFreeSpace(hdl);  // In byte
   count = (count >> 1);            // In word


   // Check the remaind media buffer size
   if (ihdl->pcmStrm.dedicated_mode){
#ifdef DSP_DEBUG_DEDICATED_MODE_RECORD
      if ( count < (FRAME_BUF_SIZE << 1) ) {
         kal_prompt_trace( MOD_L1SPHISR, "BUF_OverFlow"); // buffer overflow
         return;
      }
#else
      if ( count < FRAME_BUF_SIZE ) {
         kal_prompt_trace( MOD_L1SPHISR, "BUF_OverFlow"); // buffer overflow
         return;
      }
#endif
   } else {
      dspRecLen = (int32)(*DSP_PCM_REC_LEN);
      if( dspRecLen < count )
         count = dspRecLen;

      if ( count < FRAME_BUF_SIZE ) {
         kal_prompt_trace( MOD_L1SPHISR, "BUF_OverFlow"); // buffer overflow
         return;
      }
   }

   pcmReadDataSegment(ihdl);
}

static void PutSilence(pcmStrmMediaHdl *ihdl, int32 dsp_len)
{
   int32 I;
   uint16 dsp_last_sample = ihdl->pcmStrm.dsp_last_sample;
   uint16 dsp_w = *DSP_PCM_W;

   if(dsp_len <= 0)
      return;
   *DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w) = dsp_last_sample;

   for( I = dsp_len - 1; I > 0; I-- )     /* data transferring via IDMA */
      *IDMA_SHORT_ADDR = dsp_last_sample;

   dsp_w += dsp_len;
   if( dsp_w ==  ihdl->mh.dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;             /* Update DSP writing pointer */
}

static void pcmStrmHisr( void *data )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)data;
   kal_int16 rb_w, rb_r_cache, tmp1;

   if( ihdl->end_status == MEDIA_TERMINATED )
      return;

   if( *DSP_PCM_CTRL == 0 ) {  // DSP in idle state
      ihdl->end_status = MEDIA_TERMINATED;
     kal_prompt_trace( MOD_L1SPHISR, " STRM_PCM_IDLE_STATE ");
      mhdlException( (MHdl*)ihdl, MEDIA_END );
      return;
   }

   if( ihdl->end_status == MEDIA_END )
      return;

   if (ihdl->decode_EOF) {
      if (ihdl->zeroCount > 0) {
         kal_int32 count;
         
         count = wavPutSilence( ihdl->mh.dsp_rb_base, ihdl->mh.dsp_rb_size, ihdl->pcmStrm.dsp_last_sample);
         ihdl->zeroCount -= count;
      }
      
      if (ihdl->zeroCount <= 0) {
         ihdl->end_status = MEDIA_END;
         if( *DSP_PCM_CTRL == 8) {
            *DSP_PCM_CTRL = 0x10;
            kal_prompt_trace( MOD_L1SPHISR, " STRM_PCM_END_STATE ");
         }
      }
      return;
   }

   if( *DSP_PCM_CTRL == 2 ) {   // DSP RingBuf initialization
      kal_prompt_trace( MOD_L1SPHISR, " STRM_PCM_RUN_STATE ");
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

   pcmWriteDataToDSP(ihdl);

   if( ((ihdl->mh.eof) && (ihdl->mh.GetDataCount((MHdl*)ihdl) <= 1)) ||
       (ihdl->mh.current_time >= ihdl->mh.stop_time)) {
      ihdl->decode_EOF = true;
      ihdl->zeroCount = wavGetDSPDataCnt(ihdl->mh.dsp_rb_size);
   }

   // fill silence, Media Buffer underflow
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if ( rb_r_cache < 0 )
      rb_r_cache += (int16)ihdl->mh.dsp_rb_size;
   rb_r_cache &= 0xFFFC;

   if (rb_r_cache)   // if MCU should fill silence to DSP...
   {
      tmp1 = (int16)ihdl->mh.dsp_rb_size - rb_w;
      kal_prompt_trace( MOD_L1SPHISR, "Silence %d", tmp1 );

      if (rb_r_cache > tmp1)
      {
         PutSilence( ihdl, tmp1 );
         rb_r_cache -= tmp1;
      }
      PutSilence( ihdl, rb_r_cache );
   }

   mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
   ihdl->mh.current_time += ihdl->frameDuration;
}

static void pcmStrmRecHisr( void *data )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)data;

   if(ihdl->mh.state != WAV_STATE_RECORDING)
      return;

   if ( ihdl->end_status == MEDIA_TERMINATED )
      return;

   if ( !ihdl->pcmStrm.dedicated_mode ) {
      if( *DSP_PCM_REC_CTRL == 0 ) {           // DSP in idle state
         ihdl->end_status = MEDIA_TERMINATED;
         mhdlException( (MHdl*)ihdl, MEDIA_END );
         kal_prompt_trace( MOD_L1SPHISR, "STRM_PCM_IDLE_STATE"); // buffer underflow
         return;
      }
   }

   pcmReadDataFromDSP(ihdl);
   mhdlDataNotification((MHdl*)ihdl);
}


static Media_Event pcmStrmMFProcess( MHdl *hdl, Media_Event event )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, MEDIA_FORMAT_PCM_8K );

   switch(event)
   {
      case MEDIA_END:
         if (ihdl->pcmStrm.isPlayback) {
            if ( hdl->state == WAV_STATE_PLAYING )
               pcmStrmCloseDevice( hdl );
         } else {
            if ( hdl->state == WAV_STATE_RECORDING )
               pcmStrmRecCloseDevice( hdl );
         }
         hdl->state = WAV_STATE_IDLE;
         return event;

      case MEDIA_DATA_REQUEST:
         return MEDIA_DATA_REQUEST;
      case MEDIA_DATA_NOTIFICATION:
         return MEDIA_DATA_NOTIFICATION;
      
      default:
         ASSERT(0);    // should never reach here
   }
   return MEDIA_NONE;  // no use (only for compile)
}

static Media_Status pcmStrmMFPlay( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   ihdl->end_status = MEDIA_NONE;
   ihdl->decode_EOF = false;
   ihdl->zeroCount = 0;

   switch( ihdl->pcmStrm.sampleFreq / 1000 ){   // update sample rate index of control table
      case 8:
         ihdl->pcmStrm.freqType = 0x00;
         ihdl->frameDuration    = 10;
         break;
      case 16:
         ihdl->pcmStrm.freqType = 0x20;
         ihdl->frameDuration    = 10;
         break;
#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
      case 11:
         ihdl->pcmStrm.freqType = 0x11;
         ihdl->frameDuration    = 40;
         break;
      case 12:
         ihdl->pcmStrm.freqType = 0x12;
         ihdl->frameDuration    = 10;
         break;
      case 22:
         ihdl->pcmStrm.freqType = 0x21;
         ihdl->frameDuration    = 20;
         break;
      case 24:
         ihdl->pcmStrm.freqType = 0x22;
         ihdl->frameDuration    = 10;
         break;
      case 32:
         ihdl->pcmStrm.freqType = 0x40;
         ihdl->frameDuration    = 10;
         break;
      case 44:
         ihdl->pcmStrm.freqType = 0x41;
         ihdl->frameDuration    = 10;
         break;
      case 48:
         ihdl->pcmStrm.freqType = 0x42;
         ihdl->frameDuration    = 10;
         break;
#endif
      default: 
         return MEDIA_UNSUPPORTED_FREQ;
   }

#if defined(MT6223) || defined(MT6223P)
   // Due to loading issue, MT6223 doesn't support 44.1 kHz and 48 kHz
   if (ihdl->pcmStrm.sampleFreq >= 17000)
      return MEDIA_UNSUPPORTED_TYPE;
#endif

   if ( (ihdl->pcmStrm.bitPerSample != 8) && (ihdl->pcmStrm.bitPerSample != 16) )
      return MEDIA_BAD_PARAMETER;

#if defined(MT6205B)
   hdl->mono2stereo = false;

   if (ihdl->pcmStrm.isStereo)
      return MEDIA_UNSUPPORTED_CHANNEL;
#else
#if defined(__BT_SUPPORT__) && !defined(__BT_AUDIO_VIA_SCO__)
   if ( (AM_IsBluetoothOn() == true) && (ihdl->pcmStrm.freqType == 0x00) && (ihdl->pcmStrm.isStereo == false) ) {
      hdl->mono2stereo = false;
      ihdl->pcmStrm.is8KVoice = true;
   } else {
      if (ihdl->pcmStrm.isStereo)
         hdl->mono2stereo = false;
      else
         hdl->mono2stereo = true;
   }
#else
   if (ihdl->pcmStrm.isStereo)
      hdl->mono2stereo = false;
   else
      hdl->mono2stereo = true;
#endif
#endif

   pcmStrmOpenDevice(ihdl);
   ihdl->mh.state = WAV_STATE_PLAYING;
   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_STREAM, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFRecord( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   ihdl->end_status = MEDIA_NONE;

   // Check buffer size
   ihdl->mh.rb_size = (FRAME_BUF_SIZE * 2) * (ihdl->mh.rb_size / (FRAME_BUF_SIZE * 2));
   if (ihdl->mh.rb_size == 0)
      return MEDIA_FAIL;

   ihdl->mh.state = WAV_STATE_RECORDING;
   pcmStrmRecOpenDevice(ihdl);
   kal_trace( TRACE_FUNC, L1AUDIO_RECORD, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFResume( MHdl *hdl )
{
   Media_Status result;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if (ihdl->pcmStrm.isPlayback) {
      result = pcmStrmMFPlay(hdl);
   } else {
      result = pcmStrmMFRecord(hdl);
   }

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, MEDIA_FORMAT_PCM_8K );

   return result;
}

static Media_Status pcmStrmMFPause( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if (ihdl->pcmStrm.isPlayback) {
      ASSERT( hdl->state == WAV_STATE_PLAYING );

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmCloseDevice( hdl );

      hdl->state = WAV_STATE_PLAY_PAUSE;
   } else {
      ASSERT( hdl->state == WAV_STATE_RECORDING );

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmRecCloseDevice( hdl );

      hdl->state = WAV_STATE_PLAY_PAUSE;
   }

   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFStop( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if (ihdl->pcmStrm.isPlayback) {
      if( hdl->state == WAV_STATE_PLAY_PAUSE || hdl->state == WAV_STATE_IDLE )
         return MEDIA_SUCCESS;

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmCloseDevice( hdl );
   } else {
      if( hdl->state == WAV_STATE_RECORD_PAUSE || hdl->state == WAV_STATE_IDLE )
         return MEDIA_SUCCESS;

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmRecCloseDevice( hdl );
   }

   hdl->state = WAV_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, MEDIA_FORMAT_PCM_8K );
   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFClose( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if (ihdl->pcmStrm.isPlayback) {
      ASSERT( hdl != 0 && hdl->state != WAV_STATE_PLAYING);
      mhdlFinalize( hdl, DP_D2C_PCM_P );
   } else {
      ASSERT( hdl != 0 && hdl->state != WAV_STATE_RECORDING);

      if (ihdl->pcmStrm.dedicated_mode) {
         mhdlFinalize( hdl, DP_D2C_PCM_TCH_R );
      } else {
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
         mhdlFinalize( hdl, DP_D2C_WAV_REC );
#else
         mhdlFinalize( hdl, DP_D2C_PCM_R );
#endif
      }
   }

   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

MHdl *PCM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   MHdl *hdl;
   pcmStrmMediaHdl *ihdl;
   Media_PCM_Stream_Param *pcm_param = (Media_PCM_Stream_Param *) param;

   ihdl = (pcmStrmMediaHdl*)get_ctrl_buffer( sizeof(pcmStrmMediaHdl) );
   memset(ihdl, 0, sizeof(pcmStrmMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, DP_D2C_PCM_P, pcmStrmHisr );

   hdl->handler   = handler;
   hdl->state     = WAV_STATE_IDLE;
   ihdl->pcmStrm.isPlayback    = true;
   ihdl->pcmStrm.isStereo      = pcm_param->isStereo;
   ihdl->pcmStrm.bitPerSample  = pcm_param->bitPerSample;
   ihdl->pcmStrm.sampleFreq    = pcm_param->sampleFreq;

   hdl->Close     = pcmStrmMFClose;
   hdl->Pause     = pcmStrmMFPause;
   hdl->Stop      = pcmStrmMFStop;
   hdl->Process   = pcmStrmMFProcess;
   hdl->Play      = pcmStrmMFPlay;
   hdl->Resume    = pcmStrmMFResume;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_PCM_8K );

   return hdl;
}

#if !defined( MT6205B ) && !defined( MT6205 ) && !defined( MT6208 )

MHdl *PCM_Strm_Rec_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   MHdl *hdl;
   pcmStrmMediaHdl *ihdl;

   ihdl = (pcmStrmMediaHdl*)get_ctrl_buffer( sizeof(pcmStrmMediaHdl) );
   memset(ihdl, 0, sizeof(pcmStrmMediaHdl));
   hdl = (MHdl *) ihdl;

   ihdl->pcmStrm.dedicated_mode = AM_IsSpeechOn();

   if (ihdl->pcmStrm.dedicated_mode) {
     mhdlInit( hdl, DP_D2C_PCM_TCH_R, pcmStrmRecHisr );
   } else {
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
      mhdlInit( hdl, DP_D2C_WAV_REC, pcmStrmRecHisr );
#else
      mhdlInit( hdl, DP_D2C_PCM_R, pcmStrmRecHisr );
#endif
   }

   hdl->handler   = handler;
   hdl->state     = WAV_STATE_IDLE;
   ihdl->pcmStrm.isPlayback    = false;

   hdl->Close     = pcmStrmMFClose;
   hdl->Pause     = pcmStrmMFPause;
   hdl->Stop      = pcmStrmMFStop;
   hdl->Process   = pcmStrmMFProcess;
   hdl->Record    = pcmStrmMFRecord;
   hdl->Resume    = pcmStrmMFResume;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_PCM_8K );

   return hdl;
}

#endif   // MT6205/6205B/6208 do not support record

#endif
