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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   snd_effect.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Sound effect interface and driver, providing in-call background sound and sound event playback
 *     support FSAL stream input with Microsoft WAV format
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#if defined(BGSND_ENABLE) 

#include "l1audio.h"
#include "l1audio_def.h"

#if  !(defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238))
#error BB chip not support background sound
#endif

#include "afe.h"
#include "gpt_sw.h"
#include "am.h"
#include "wav.h"
#include "fsal.h"
#include "ddload.h"

#if IS_EV_BOARD
#include "alerter_sw.h"
#endif

#include "kal_trace.h"
#include "l1sp_trc.h"
#define L1SND_TRC_ON

#if defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 2
#elif defined(MT6223) || defined(MT6223P)
#define PAGE_NUM 1
#else
#error Need indicate DM page of SND_EFFECT for new chip
#endif

#define DP_BUFFER_DEFAULT_LEN       2048   /* The frame size of DSP. */
#define SND_RB_DEFAULT_THRESHOLD    512

#define MASTER_GAIN_FACTOR          12

#define SND_EFFECT_MAGIC_NO           0xAA57

/* DSP Sound Effect State */
#define DP_SND_STATE_IDLE           0     /* MCU: 0 -> 1 */
#define DP_SND_STATE_READY          1     /* DSP: 1 -> 2 */
#define DP_SND_STATE_PLAYING        2     /* MCU: 2 -> 3 */
#define DP_SND_STATE_STOPPED        3     /* DSP: 3 -> 0 */

//#define SND_APPLY_MCU_GAIN
//#define SND_CHECK_DATA

#ifdef SND_CHECK_DATA
int16 snd_check_data[0x80000];
int16 *snd_check_w2;
#endif

//#define SND_UNIT_TEST
typedef struct {
   int16 formatTag;
   uint16 numChannels;
   uint32 sampleRate;
   uint32 avgBytesPerSec;   
   uint16 blockAlign;
   uint16 bitsPerSample;
   uint32 extHeaderOffset;
   uint16 extHeaderSize;
   uint32 dataChunkOffset;
   uint32 dataChunkSize;
} sndHeader;

typedef struct sndcontrol SndControl;
struct sndcontrol{
   uint16 aud_id;
   void (*SND_PutData)(SndControl *snd_ctrl);
   Media_Event end_status;
#ifdef SND_APPLY_MCU_GAIN
   int16 level;
#endif
   kal_bool bULSPHFlag; /* if KAL_TRUE, mix uplink speech */
   kal_bool bDLSPHFlag; /* if KAL_TRUE, mix downlink speech */
   kal_int16 ULSNDGain; /* 0 ~ 100, digital gain for mixed uplink sound */
   kal_int16 DLSNDGain; /* 0 ~ 100, digital gain for mixed downlink sound */

   sndHeader info;
   int16 dsp_last_sample;  /* The last sample written to DSP buffer by MCU, for last-sample padding */
   dviAdpcm_State dvi_state;
   int16 dvi_data[4];
   uint16 dvi_blockCounter;
   uint8 dvi_dataCount;

   /* Ring buffer control variables */
   uint16 rb_threshold;
   uint16 rb_size;          /* Size of the ring buffer(word) */
   uint16 write;            /* R/W by MMI, R by WAV driver   */
   uint16 read;             /* R by MMI, R/W by WAV driver   */
   int16 *rb_base;         /* Pointer to the ring buffer    */
   uint32 total_write_bytes;
   bool waiting;
   bool eof;              /* Flag indicating End-Of-File   */

   void *parent;
} ;

typedef struct {
   kal_int8       repeat_count;
   kal_uint8      volume_level;
   kal_uint32     data;
   void           (*handler)( Media_Handle *handle, Media_Event event );
   void           *param;
} mhandle;

typedef struct {
  mhandle mh;
  SndControl snd_ctrl;
} sndMediaHandleInternal;


#define SND_GAIN_CONFIG   1 /* 0: right shamt, 1: multiplier */

static int32 sndGetDataCount( SndControl *snd_ctrl );

#define sndShiftReadPointer() \
{ \
   snd_ctrl->read ++; \
   if(snd_ctrl->read == snd_ctrl->rb_size) \
      snd_ctrl->read = 0; \
}

#ifdef SND_APPLY_MCU_GAIN
__inline int16 sndSetSampleAmplitude(int16 sample, int16 arg)
{
   return((sample*arg)>>15);
}
#endif

static void sndAUlawPCM_DecodeSample( SndControl *snd_ctrl, const uint16* Table )
{
   uint16 dsp_sound_effect_addr, dsp_sound_effect_len;
   int32 numSamples, I;
   
   int16 sample = snd_ctrl->dsp_last_sample;
   bool sampleType = (snd_ctrl->info.bitsPerSample==8);
#ifdef SND_APPLY_MCU_GAIN
   int16 arg = snd_ctrl->level;
#endif

   
   dsp_sound_effect_addr = *DSP_SOUND_EFFECT_ADDR;
   dsp_sound_effect_len  = *DSP_SOUND_EFFECT_LEN;

   numSamples = sndGetDataCount(snd_ctrl)*(sampleType?2:1);
   if(numSamples > dsp_sound_effect_len)
      numSamples = dsp_sound_effect_len;

   for(I=numSamples; I>0; I-=(sampleType?2:1)){
      uint16 data = snd_ctrl->rb_base[snd_ctrl->read];
      
      sample = (sampleType?(Table?Table[data&0x00FF]:((data<<8)-0x8000)):data);
#ifdef SND_APPLY_MCU_GAIN
      sample = sndSetSampleAmplitude(sample, arg);
#endif
      if(I == numSamples)
         *DSP_DM_ADDR(PAGE_NUM, dsp_sound_effect_addr) = sample;
      else
         *IDMA_SHORT_ADDR = sample;
         
      if(sampleType){
         sample = (Table?Table[data>>8]:((data&0xFF00)-0x8000));
#ifdef SND_APPLY_MCU_GAIN
         sample = sndSetSampleAmplitude(sample, arg);
#endif
         *IDMA_SHORT_ADDR = sample;
      }

      sndShiftReadPointer();
   }
   snd_ctrl->dsp_last_sample = sample;

   // Fill silence to DSP if buffer underflow
   numSamples = dsp_sound_effect_len - numSamples;
   for(I=numSamples; I>0; I--){
      if( I == dsp_sound_effect_len )
         *DSP_DM_ADDR(PAGE_NUM, dsp_sound_effect_addr) = snd_ctrl->dsp_last_sample;
      else
         *IDMA_SHORT_ADDR = snd_ctrl->dsp_last_sample;
   }
}

static void sndDVIADPCM_DecodeWord(uint16 data, SndControl *snd_ctrl )
{
   snd_ctrl->dvi_data[3] = dviAdpcm_Decode( (uint8)(data & 0xF), &snd_ctrl->dvi_state );
   snd_ctrl->dvi_data[2] = dviAdpcm_Decode( (uint8)((data >> 4) & 0xF), &snd_ctrl->dvi_state );
   snd_ctrl->dvi_data[1] = dviAdpcm_Decode( (uint8)((data >> 8) & 0xF), &snd_ctrl->dvi_state );
   snd_ctrl->dvi_data[0] = dviAdpcm_Decode( (uint8)((data >> 12) & 0xF), &snd_ctrl->dvi_state );
}

static void sndPutData_PCM( SndControl *snd_ctrl ) /* 16 bit linear pcm */
{
   sndAUlawPCM_DecodeSample( snd_ctrl, NULL );
}

static void sndPutData_Alaw( SndControl *snd_ctrl ) /* A-law decoder */
{
   sndAUlawPCM_DecodeSample( snd_ctrl, Alaw_Tab );
}

static void sndPutData_Ulaw( SndControl *snd_ctrl )  /* U-law decoder */
{
   sndAUlawPCM_DecodeSample( snd_ctrl, Ulaw_Tab );
}

static void sndPutData_DVIADPCM( SndControl *snd_ctrl )  /* DVI-ADPCM decoder */
{
   uint16 dp_sound_effect_len, dp_sound_effect_addr;
   int32 numSamples = snd_ctrl->dvi_dataCount;
   int32 rbWordCount, tmp1, tmp2, I;

   uint16 sample = snd_ctrl->dsp_last_sample;   
#ifdef SND_APPLY_MCU_GAIN
   int16 arg = snd_ctrl->level;
#endif

   
   dp_sound_effect_len = *DSP_SOUND_EFFECT_LEN;
   dp_sound_effect_addr = *DSP_SOUND_EFFECT_ADDR;

   rbWordCount = sndGetDataCount(snd_ctrl);
   tmp1 = (snd_ctrl->info.blockAlign>>1) - snd_ctrl->dvi_blockCounter; /* number of blocks (words) remained in current block */
   if(rbWordCount <= tmp1){
      if(snd_ctrl->dvi_blockCounter > 0)
         numSamples += rbWordCount<<2;
      else if(rbWordCount >= 2)
        numSamples += 1 + ((rbWordCount-2)<<2);
   }
   else{
      if(snd_ctrl->dvi_blockCounter > 0)
         numSamples += tmp1<<2;
      else
         numSamples += 1 + ((tmp1-2)<<2);
      rbWordCount -= tmp1;

      tmp1 = 1 + (((snd_ctrl->info.blockAlign>>1)-2)<<2); /* samples per block */
      tmp2 = snd_ctrl->info.blockAlign>>1; /* words per block */
      while(rbWordCount >= tmp2){
         numSamples += tmp1;
         rbWordCount -= tmp2;
      }

      if(rbWordCount >= 2)
        numSamples += 1 + ((rbWordCount-2)<<2);      
   }
   if(numSamples > dp_sound_effect_len) /* number of samples in rb */
      numSamples = dp_sound_effect_len;

   for(I=numSamples; I>0; I--){
      int32 data = (int32)snd_ctrl->rb_base[ snd_ctrl->read ];
      if(snd_ctrl->dvi_dataCount == 0){
         if(snd_ctrl->dvi_blockCounter == 0){
            snd_ctrl->dvi_state.valpred = data;
            snd_ctrl->dvi_data[0] = (int16)data;
            sndShiftReadPointer();
            snd_ctrl->dvi_state.index = (int32)snd_ctrl->rb_base[ snd_ctrl->read ];
            sndShiftReadPointer();
            snd_ctrl->dvi_dataCount = 1;
            snd_ctrl->dvi_blockCounter = 2;
         }
         else{
            sndDVIADPCM_DecodeWord((uint16)data, snd_ctrl);
            sndShiftReadPointer();
            snd_ctrl->dvi_dataCount = 4;
            snd_ctrl->dvi_blockCounter++;
            if(snd_ctrl->dvi_blockCounter == (snd_ctrl->info.blockAlign>>1))
               snd_ctrl->dvi_blockCounter = 0;
         }
      }

      sample = snd_ctrl->dvi_data[--snd_ctrl->dvi_dataCount];
#ifdef SND_CHECK_DATA
      *snd_check_w2++ = sample;
#endif
#ifdef SND_APPLY_MCU_GAIN
      sample = sndSetSampleAmplitude(sample, arg);
#endif
      if( I == numSamples )
         *DSP_DM_ADDR(PAGE_NUM, dp_sound_effect_addr) = sample;
      else
         *IDMA_SHORT_ADDR = sample;
   }
   snd_ctrl->dsp_last_sample = sample;
   
   // Fill silence to DSP if buffer underflow
   numSamples = dp_sound_effect_len - numSamples; /* number of silence samples */
   for(I=numSamples; I>0; I--){
#ifdef SND_CHECK_DATA
      *snd_check_w2++ = snd_ctrl->dsp_last_sample;
#endif
      if(I == dp_sound_effect_len)
         *DSP_DM_ADDR(PAGE_NUM, dp_sound_effect_addr) = snd_ctrl->dsp_last_sample;
      else
         *IDMA_SHORT_ADDR = snd_ctrl->dsp_last_sample;
   }

}

/* ------------------------------------------------------------------------------ */

static int32 sndGetFreeSpace( SndControl *snd_ctrl )
{
   int32 count;
   count = (int32)snd_ctrl->read - (int32)snd_ctrl->write - 1;
   if( count < 0 )
      count += (int32)snd_ctrl->rb_size;
   return count;
}

static int32 sndGetDataCount( SndControl *snd_ctrl )
{
   int32 count = (int32)snd_ctrl->write - (int32)snd_ctrl->read;
   if( count < 0 )
      count += snd_ctrl->rb_size;
   return count;
}

static void sndSetEvent( SndControl *snd_ctrl, Media_Event event )
{
   mhandle *handle = (mhandle *)snd_ctrl->parent;
   handle->data = (kal_uint32)event;
   L1Audio_SetEvent( snd_ctrl->aud_id, (void *)handle );
}

static void sndDataRequest( SndControl *snd_ctrl )
{
   if( snd_ctrl->waiting || snd_ctrl->eof || (snd_ctrl->end_status != MEDIA_NONE) )
      return;
   if( sndGetFreeSpace(snd_ctrl) >= snd_ctrl->rb_threshold ) {
      sndSetEvent( snd_ctrl, MEDIA_DATA_REQUEST );
      snd_ctrl->waiting = true;
   }
}

static void sndUpdateMixer( SndControl *snd_ctrl )
{
   if(AM_IsSpeechOn())
      *DSP_SOUND_EFFECT_SPH_STATE = ((snd_ctrl->bULSPHFlag==KAL_TRUE)?2:0) | ((snd_ctrl->bDLSPHFlag==KAL_TRUE)?1:0);
   else
      *DSP_SOUND_EFFECT_SPH_STATE = 0;

   *DSP_SOUND_EFFECT_UL_GAIN = snd_ctrl->ULSNDGain;
   *DSP_SOUND_EFFECT_DL_GAIN = snd_ctrl->DLSNDGain;
}

static void sndHisr( void *data )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;
   SndControl *snd_ctrl = &handle->snd_ctrl;

   sndUpdateMixer(snd_ctrl);
   
   if( snd_ctrl->end_status != MEDIA_NONE )
      return;
   
   if( *DSP_SOUND_EFFECT_CTRL != DP_SND_STATE_PLAYING )
      return;
   
   snd_ctrl->SND_PutData(snd_ctrl);
   if( sndGetDataCount(snd_ctrl) == 0 && snd_ctrl->eof) {
      snd_ctrl->end_status = MEDIA_END;
      *DSP_SOUND_EFFECT_CTRL = DP_SND_STATE_STOPPED;
      //AM_SND_PlaybackOff( false );
      //L1Audio_UnhookHisrHandler(SND_EFFECT_MAGIC_NO);
      sndSetEvent( snd_ctrl, MEDIA_END );
   }
   else
      sndDataRequest(snd_ctrl);
}

/* ------------------------------------------------------------------------------ */

static void sndDataFinished( SndControl *snd_ctrl )
{
   snd_ctrl->eof = true;
}

static void sndWriteDataDone( SndControl *snd_ctrl, uint32 len )
{
   snd_ctrl->write += len;
   if( snd_ctrl->write >= snd_ctrl->rb_size )
      snd_ctrl->write = 0;
   snd_ctrl->waiting = false;
}

static void sndGetWriteBuffer( SndControl *snd_ctrl, int16 **buffer, uint32 *buf_len )
{
   int32 count;
   if( snd_ctrl->read > snd_ctrl->write )
      count = (int32)snd_ctrl->read - (int32)snd_ctrl->write - 1;
   else if( snd_ctrl->read == 0 )
      count = (int32)snd_ctrl->rb_size - (int32)snd_ctrl->write - 1;
   else
      count = (int32)snd_ctrl->rb_size - (int32)snd_ctrl->write;

   *buffer = &snd_ctrl->rb_base[snd_ctrl->write];
   *buf_len = (uint32)count;
}

static bool sndFillBuffer( sndMediaHandleInternal *handle, bool bIsStarted ) /* return the repeat status */
{
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;

   uint32 I;

   for(I=0; I<2; I++){ /* 2-stage filling */
      uint32 nBytes;
      int16 *write_ptr;
      uint32 write_len;
      FSAL_Status status;

      sndGetWriteBuffer( snd_ctrl, &write_ptr, &write_len );
      if(write_len == 0)
         break;
      nBytes = write_len<<1;
      if(nBytes > (snd_ctrl->info.dataChunkSize-snd_ctrl->total_write_bytes))
        nBytes = snd_ctrl->info.dataChunkSize-snd_ctrl->total_write_bytes;
      nBytes &= ~1;

      if( nBytes==0 )
         break;
      status = FSAL_Read( param->pstFSAL, (kal_uint8 *)write_ptr, nBytes );
      if( FSAL_OK != status )
      {
         if( FSAL_DEVICE_BUSY == status )
         {
#ifdef L1SND_TRC_ON
            kal_trace( TRACE_INFO, L1SND_DATACHUNK_SIZE, -1 );
#endif
            snd_ctrl->waiting = false;
         }
         break; // snd_ctrl->waiting will be hold to true
      }

      sndWriteDataDone( snd_ctrl, nBytes>>1 );
      snd_ctrl->total_write_bytes += nBytes;
   }
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_GROUP_SND, L1SND_FILLBUFFER, snd_ctrl->total_write_bytes );
#endif
   if( !bIsStarted )
      return false;
   
   if( snd_ctrl->total_write_bytes >= snd_ctrl->info.dataChunkSize ){
      if( handle->mh.repeat_count == 1 ){
         sndDataFinished(snd_ctrl);
         return false;
      }
      else{
         if( sndGetDataCount(snd_ctrl)==0 )
         {
            if( FSAL_OK != FSAL_Seek(param->pstFSAL, snd_ctrl->info.dataChunkOffset) )
               return false;
            snd_ctrl->total_write_bytes = 0;
            if(snd_ctrl->info.formatTag == 0x0011){
               dviAdpcm_Init( &snd_ctrl->dvi_state );
               snd_ctrl->dvi_dataCount = 0;
               snd_ctrl->dvi_blockCounter = 0;
            }
            if( handle->mh.repeat_count > 1 )
               handle->mh.repeat_count--;
#ifdef L1SND_TRC_ON
            kal_trace( TRACE_GROUP_SND, L1SND_REPEATED, handle->mh.repeat_count );
#endif
            L1Audio_SetEvent( snd_ctrl->aud_id, (void *)handle );
            return true;
         }
         else
         {
            snd_ctrl->waiting = false;
         }
      }
   }

   return false;
}

static void sndProcess( void *data )
{ /* This function works in L1Audio Task */
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;   
   Media_Event event = (Media_Event)handle->mh.data;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   
   if(event == MEDIA_DATA_REQUEST){
      if( snd_ctrl->end_status==MEDIA_NONE ) {
         bool isRepeated;
         isRepeated = sndFillBuffer( handle, true );
         if(isRepeated == true)
            handle->mh.handler( (Media_Handle *)handle, MEDIA_REPEATED );
      }
   }
   else if( event == MEDIA_END ) {
      snd_ctrl->waiting = false;
      handle->mh.handler( (Media_Handle *)handle, event );
   }
   
   return;
}

/* ------------------------------------------------------------------------------ */
#define RIFF_ID  0x46464952
#define MTK_ID  0x2044544D
#define WAVE_ID  0x45564157
#define FMT_ID  0x20746D66
#define DATA_ID  0x61746164
static bool sndParser(STFSAL *pstFSAL, sndHeader *info) /* Parse RIFF/MTK header, fmt Chunk, seek data Chunk */
{
   uint32 curPos=0, fileSize;
   uint32 cache_32;
   uint16 cache_16;
   int32 extendedHeaderSize;
   
   if( FSAL_OK != FSAL_GetFileSize(pstFSAL, (kal_uint32 *)&fileSize) )
      return false;
   if( FSAL_OK != FSAL_Seek(pstFSAL, 0) )
      return false;

   /* Parse Chunk ID, RIFF/MTK */
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
      return false;
   curPos += 4;

   /* Parse WAV info */
   if(cache_32 == RIFF_ID){ /* RIFF file */
      curPos += 4;
      if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Chunk Data Size */
         return false;
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
         return false;
      curPos += 4;
      if(cache_32 != WAVE_ID)
         return false;
   }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   else 
      return false;
   
   /* Seek RIFF fmt Chunk */
   while(1){
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
         return false;
      curPos += 4;

      if(cache_32 == FMT_ID)
         break;

      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
         return false;
      curPos += 4;
      curPos += cache_32;
      if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Chunk Data */
         return false;
   }

   /* Parse RIFF fmt Chunk */
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
      return false;
   curPos += 4;
   extendedHeaderSize = (int32)cache_32-16;
   if(extendedHeaderSize < 0) /* fmt Chunk Size should be > 16 */
      return false;

   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get formatTag */
      return false;
   curPos += 2;
   info->formatTag = cache_16;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get numChannel */
      return false;
   curPos += 2;
   info->numChannels = cache_16;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get sampleRate */
      return false;
   curPos += 4;
   info->sampleRate = cache_32;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get avgBytesPerSec */
      return false;
   curPos += 4;
   info->avgBytesPerSec = cache_32;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get blockAlign */
      return false;
   curPos += 2;
   info->blockAlign = cache_16;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get bitsPerSample */
      return false;
   curPos += 2;
   info->bitsPerSample = cache_16;

   /* Locate Extended Header */
   if(extendedHeaderSize > 2){
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get bitsPerSample */
         return false;
      curPos += 2;
      extendedHeaderSize -= 2;
      
      info->extHeaderOffset = curPos;
      info->extHeaderSize = ((uint16)extendedHeaderSize < cache_16)? (uint16)extendedHeaderSize: cache_16;
   }
   else{
      info->extHeaderOffset = 0;
      info->extHeaderSize = 0;
   }
   curPos += extendedHeaderSize;
   if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Extended Header */
      return false;

   /* Seek data Chunk */   
   while(1){
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
         return false;
      curPos += 4;

      if(cache_32 == DATA_ID)
         break;

      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
         return false;
      curPos += 4;
      curPos += cache_32;
      if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Chunk Data */
         return false;
   }

   /* Get RIFF data Chunk */
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
      return false;
   curPos += 4;
   info->dataChunkOffset = curPos;
   info->dataChunkSize = (cache_32<(fileSize-curPos))?cache_32:(fileSize-curPos);
   info->dataChunkSize &= ~1;

   return true;
}

/* ------------------------------------------------------------------------------ */

/*
 * Description
 * ---------
 *   The function is used to check if the sound format of a FSAL instance is supported 
 *   by this SND interface.
 *
 * Syntax
 * ---------
 *   Media_Status SND_GetFormat( STFSAL *pstFSAL, Media_Format *pFormat );
 *
 * where
 *   pstFSAL   The pointer to the FSAL instance
 *   pFormat   The pointer to the sound format of the FSAL instance. It is valid only 
 *             when the function return
 *
 * Return Value
 * ---------
 *   Media_Status   Return MEDIA_SUCCESS if this SND interface supports the sound 
 *                  format of the FSAL instance. Return MEDIA_BAD_FORMAT otherwise.
 */
Media_Status SND_GetFormat(STFSAL *pstFSAL, Media_Format *pFormat)
{
   sndHeader info;
   
   *pFormat =(Media_Format)-1;   
   if(sndParser(pstFSAL, &info) == false)
      return MEDIA_BAD_FORMAT;
   if( (info.numChannels != 1) || 
   	(info.sampleRate != 8000) || 
   	(info.dataChunkSize < 2) )
      return MEDIA_BAD_FORMAT;
   
   switch( info.formatTag ) {
      case 0x0001:
      	  if(info.bitsPerSample != 16 && info.bitsPerSample != 8)
      	     return MEDIA_BAD_FORMAT;
         *pFormat = MEDIA_FORMAT_PCM_8K;
      	  break;
      case 0x0006:
      	  if(info.bitsPerSample != 8)
            return MEDIA_BAD_FORMAT;
         *pFormat = MEDIA_FORMAT_G711_ALAW;
         break;
      case 0x0007:
      	  if(info.bitsPerSample != 8)
            return MEDIA_BAD_FORMAT;
         *pFormat = MEDIA_FORMAT_G711_ULAW;
         break;
      case 0x0011:
         if(info.bitsPerSample != 4)
            return MEDIA_BAD_FORMAT;
      	  if((info.blockAlign&1) != 0)
      	     return MEDIA_BAD_FORMAT;
      	  *pFormat = MEDIA_FORMAT_DVI_ADPCM;
      	  break;
      default:
         return MEDIA_BAD_FORMAT;
   }
   return MEDIA_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function sets the output device.
 *
 * Syntax
 * ---------
 *   void SND_SetOutputDevice( kal_uint8 device );
 *
 * where
 *   device   The output device (L1SP_SPEAKER1, L1SP_SPEAKER2, L1SP_LOUD_SPEAKER)
 *
 * Return Value
 * ---------
 *   None
 */
void SND_SetOutputDevice( kal_uint8 device )
{
   if( !AM_IsSpeechOn() )
      AFE_SetOutputDevice( L1SP_SND_EFFECT, device );
}

/*
 * Description
 * ---------
 *   The function sets the playback mode. The function can be invoked after the media 
 *   handle is opened and during the media handle is playing.
 *
 * Syntax
 * ---------
 *   void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain );
 *   void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain );
 *
 * where
 *   hdl   The media handle
 *   bULSPHFlag   Mixer switch for uplink speech
 *   ULSNDGain   Sound effect gain for uplink mixer
 *   bDLSPHFlag   Mixer switch for downlink speech
 *   DLSNDGain   Sound effect gain for downlink mixer
 *
 * Return Value
 * ---------
 *   None
 */
void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain )
{
   kal_int16 gain = 0;
   ASSERT(ULSNDGain>=0 && ULSNDGain<=7);
   if( ULSNDGain!=0 )
      gain = (kal_int16)(32767>>(7 - ULSNDGain));
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.bULSPHFlag = bULSPHFlag;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.ULSNDGain = gain;
   
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_CONFIG_ULMIXER, bULSPHFlag, ULSNDGain );
#endif
}
void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain )
{
   kal_int16 gain = 0;
   ASSERT(DLSNDGain>=0 && DLSNDGain<=7);
   if( DLSNDGain!=0 )
      gain = (kal_int16)(32767>>(7 - DLSNDGain));
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.bDLSPHFlag = bDLSPHFlag;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.DLSNDGain = gain;
   
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_CONFIG_DLMIXER, bDLSPHFlag, DLSNDGain );
#endif
}

/*
 * Description
 * ---------
 *   The function opens a handle for background sound playback. It should be invoked 
 *   before any other operation.
 *
 * Syntax
 * ---------
 *   Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ), 
 *   Snd_Param **param);
 *
 * where
 *   handler   A callback function used for handling MEDIA_END event.
 *   param     Specific parameter for the background sound playback.
 *
 * Return Value
 * ---------
 *   Media_Handle   The media handle
 */
 
#include "med_utility.h"
//extern void*  med_alloc_ext_mem(kal_int32 size);
//extern void   med_free_ext_mem(void** pointer);

Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ), Snd_Param **param)
{
   sndMediaHandleInternal *handle;
   Snd_Param *pparam;
   SndControl *snd_ctrl;
   kal_uint8 *ctrl_buffer;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_OPEN );
#endif

   ASSERT( handler != 0 );

   ctrl_buffer = (kal_uint8 *)med_alloc_ext_mem(
      sizeof(sndMediaHandleInternal)+
      sizeof(Snd_Param)+
      2*DP_BUFFER_DEFAULT_LEN*sizeof(int16));

   handle = (sndMediaHandleInternal *)ctrl_buffer;
   ctrl_buffer += sizeof(sndMediaHandleInternal);
   
   pparam = (Snd_Param *)ctrl_buffer;
   ctrl_buffer += sizeof(Snd_Param);

   
   pparam->pstFSAL = NULL; /* Should be initiated by caller */
   pparam->repeats = 1; /* default */
   pparam->format = (Media_Format)-1; /* Should be initiated by caller */
   //pparam->mix = SND_MIX_DL | SND_MIX_UL; /* default */

   snd_ctrl = &handle->snd_ctrl;
   snd_ctrl->bULSPHFlag = KAL_TRUE;
   snd_ctrl->bDLSPHFlag = KAL_TRUE;
   snd_ctrl->ULSNDGain = 32767; // default: full scale
   snd_ctrl->DLSNDGain = 32767; // default: full scale
   sndUpdateMixer(snd_ctrl);
   
   snd_ctrl->aud_id = L1Audio_GetAudioID();
   snd_ctrl->rb_threshold = SND_RB_DEFAULT_THRESHOLD;
   snd_ctrl->rb_size = 2*DP_BUFFER_DEFAULT_LEN;
   snd_ctrl->rb_base = (int16 *)ctrl_buffer;
   snd_ctrl->parent = (void *)handle;
   
#ifdef SND_APPLY_MCU_GAIN
   snd_ctrl->level = 16;
#endif
   handle->mh.handler = handler;
   handle->mh.volume_level = 100;
   handle->mh.param = (void *)pparam;


   L1Audio_SetEventHandler( snd_ctrl->aud_id, sndProcess );
   AFE_SetOutputVolume( L1SP_SND_EFFECT, 200, 0 );

   *param = pparam;
   return((Media_Handle *)handle);
}

/*
 * Description
 * ---------
 *   The function starts the background sound playback of the media handle.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Play( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => Background sound has been played.
 *                  MEDIA_REENTRY	=> Reentrance has occurred. Operation aborted.
 *                  MEDIA_NOT_INITIALIZED =>	The media handle is invalid. Operation 
 *                                            aborted.
 *                  MEDIA_BAD_FORMAT =>	Bad sound format. Operation aborted.
 */
Media_Status SND_Play( Media_Handle *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;   
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_PLAY );
#endif

   ASSERT(param->pstFSAL != NULL);
   

   if( L1Audio_CheckFlag( snd_ctrl->aud_id ) )
      return MEDIA_REENTRY;
   if( snd_ctrl->rb_base == (int16*)0 )
      return MEDIA_NOT_INITIALIZED;

   handle->mh.repeat_count = param->repeats;

   snd_ctrl->read = 0;
   snd_ctrl->write = 0;
   snd_ctrl->eof = false;
   
   snd_ctrl->dsp_last_sample = 0;
   snd_ctrl->end_status = MEDIA_NONE;
   snd_ctrl->waiting = false;

   if(sndParser(param->pstFSAL, &snd_ctrl->info) == false)
      return MEDIA_BAD_FORMAT;
   if( (snd_ctrl->info.numChannels != 1) || 
   	(snd_ctrl->info.sampleRate != 8000) || 
   	(snd_ctrl->info.dataChunkSize < 2) )
      return MEDIA_BAD_FORMAT;
   
   switch( snd_ctrl->info.formatTag ) {
      case 0x0001:
      	  if(snd_ctrl->info.bitsPerSample != 16 && snd_ctrl->info.bitsPerSample != 8)
      	     return MEDIA_BAD_FORMAT;
         param->format = MEDIA_FORMAT_PCM_8K;
         snd_ctrl->SND_PutData = sndPutData_PCM;
         break;
      case 0x0006:
         if(snd_ctrl->info.bitsPerSample != 8)
            return MEDIA_BAD_FORMAT;
         param->format = MEDIA_FORMAT_G711_ALAW;
         snd_ctrl->SND_PutData = sndPutData_Alaw;
         break;
      case 0x0007:
         if(snd_ctrl->info.bitsPerSample != 8)
            return MEDIA_BAD_FORMAT;
         param->format = MEDIA_FORMAT_G711_ULAW;
         snd_ctrl->SND_PutData = sndPutData_Ulaw;
         break;
      case 0x0011:
         if(snd_ctrl->info.bitsPerSample != 4)
            return MEDIA_BAD_FORMAT;
      	  if((snd_ctrl->info.blockAlign&1) != 0)
      	     return MEDIA_BAD_FORMAT;
         param->format = MEDIA_FORMAT_DVI_ADPCM;
         snd_ctrl->SND_PutData = sndPutData_DVIADPCM;
         dviAdpcm_Init( &snd_ctrl->dvi_state );
         break;
      default:
         return MEDIA_BAD_FORMAT;
   }
   
   if( FSAL_OK != FSAL_Seek( param->pstFSAL, snd_ctrl->info.dataChunkOffset ) )
      return MEDIA_FAIL;
   snd_ctrl->total_write_bytes = 0;
   snd_ctrl->dvi_dataCount = 0;
   snd_ctrl->dvi_blockCounter = 0;
   sndFillBuffer( handle, false );
   
   L1Audio_SetFlag( snd_ctrl->aud_id );

   
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_DATACHUNK_SIZE, snd_ctrl->info.dataChunkSize );
#endif
   
   L1Audio_HookHisrHandler(SND_EFFECT_MAGIC_NO, sndHisr, (void *)handle);
   AM_SND_PlaybackOn();
   *DSP_SOUND_EFFECT_CTRL = DP_SND_STATE_READY;
   {
      uint32 I;
      for( I = 0; ; I++ ) {
         if( *DSP_SOUND_EFFECT_CTRL == DP_SND_STATE_PLAYING || snd_ctrl->end_status == MEDIA_END )
            break;
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
   return MEDIA_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function stops the background sound playback of the media handle.
 *
 * Syntax
 * ---------
 *   void SND_Stop( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   None
 */
void SND_Stop( Media_Handle *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;   
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;
   
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_STOP );
#endif


   if( !L1Audio_CheckFlag( snd_ctrl->aud_id ) )
      return;

   snd_ctrl->waiting = true;      /* Forbid data request */
   
   switch( param->format ) {
      uint16 I;
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         if( *DSP_SOUND_EFFECT_CTRL == DP_SND_STATE_PLAYING ) {
            snd_ctrl->end_status = MEDIA_TERMINATED;
            *DSP_SOUND_EFFECT_CTRL = DP_SND_STATE_STOPPED;      /* give ABORT command to the DSP */
         }
         for( I = 0; ; I++ ) {
            if( *DSP_SOUND_EFFECT_CTRL == DP_SND_STATE_IDLE )   /* DSP returns to idle state */
               break;
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
//         if( snd_ctrl->end_status == MEDIA_TERMINATED ) {
            AM_SND_PlaybackOff( true );
            L1Audio_UnhookHisrHandler(SND_EFFECT_MAGIC_NO);
//         }
         break;
      default:
         ASSERT(KAL_FALSE);
   }
   L1Audio_ClearFlag( snd_ctrl->aud_id );
   
}

/*
 * Description
 * ---------
 *   The function closes the media handle.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Close(Media_Handle *hdl);
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => the operation is complete.
 */
Media_Status SND_Close(Media_Handle *hdl){
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   kal_uint8 *ctrl_buffer = (kal_uint8 *)handle;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_CLOSE );
#endif

   L1Audio_FreeAudioID( snd_ctrl->aud_id );
   med_free_ext_mem( (void **)&ctrl_buffer );
   
   return MEDIA_SUCCESS;
}

#ifdef SND_APPLY_MCU_GAIN
/*
 * Description
 * ---------
 *   The function sets the digital gain of background sound. The function can be 
 *   invoked after the media handle is opened and during the media handle is playing.
 *
 * Syntax
 * ---------
 *   Media_Status SND_SetLevel( Media_Handle *hdl, kal_uint8 level );
 *
 * where
 *   hdl     The media handle
 *   level   Volume level (0~100).
 *           Note 1: The default value is 100(maximum volume). 
 *           Note 2: A level value larger than 100 will change nothing and cause the 
 *                   return value to be MEDIA_FAIL.
 *           Note 3: The volume level 0 will mute the background sound at both downlink 
 *                   and uplink.
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => the operation is complete.
 *                  MEDIA_FAIL    => otherwise
 */
Media_Status SND_SetLevel( Media_Handle *hdl, kal_uint8 level )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   if(level>100)
      return MEDIA_FAIL;
   
   hdl->volume_level= level;
   snd_ctrl->level = ((int16)level*level*26843)>>13;
   return(MEDIA_SUCCESS);
}

/*
 * Description
 * ---------
 *   Get the current volume level setting.
 *
 * Syntax
 * ---------
 *   kal_uint8 SND_GetLevel( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   kal_uint8   current volume level setting
 */
kal_uint8 SND_GetLevel( Media_Handle *hdl )
{
   return(hdl->volume_level);
}
#endif

#if defined (SND_UNIT_TEST)   /* SND Unit Test */

extern uint16 snd_test_data3[41080];
extern uint16 snd_test_data4[15739];
extern uint16 snd_test_data5[28949];
extern uint16 snd_test_data6[31475];

uint16 *snd_test_data_a[4] = {snd_test_data3, snd_test_data4, snd_test_data5, snd_test_data6};
uint32 sz_snd_test_data_a[4] = {/*(4+16)*2, (4+8192)*2, (4+3504*16)*2,*/
   41080*2, 15739*2, 28949*2, 31475*2};
uint16 select_test_data = 3;

STFSAL snd_file;
Media_Handle *snd_hdl=NULL;
Snd_Param *snd_param;
#ifdef SND_APPLY_MCU_GAIN
int8 snd_level = 100;
#endif
uint8  snd_play_flag = 0;
uint8 snd_repeats = 0;
uint8  snd_output_buffer;       /* 1 for L1SP_SPEAKER1, 2 for L1SP_SPEAKER2 1, 4 for L1SP_LOUD_SPEAKER */

kal_bool snd_ul_sph_flag = KAL_TRUE;
kal_bool snd_dl_sph_flag = KAL_TRUE;
kal_int8 snd_ul_gain = 50;
kal_int8 snd_dl_gain = 50;

void snd_ut_event_handler( Media_Handle *handle, Media_Event event )
{
   switch( event )
   {      
      case MEDIA_END:
         SND_Stop(handle);
         SND_Close(handle);
         snd_hdl = NULL;
         snd_play_flag = 0;
         break;
      case MEDIA_REPEATED:
         break;
      default:
         ASSERT( 0 );
   }
}

bool snd_ut_snd_play( /*uint16 snd_mix*/ )
{
   if( snd_play_flag == 0 )
   {
      FSAL_Status eFSALRet;
      uint16 *snd_ut_pattern;
      uint32 sz_snd_ut_pattern;

      snd_output_buffer = L1SP_LOUD_SPEAKER;
      snd_ut_pattern = snd_test_data_a[select_test_data];
      sz_snd_ut_pattern = sz_snd_test_data_a[select_test_data];
      
#ifdef SND_CHECK_DATA
      snd_check_w2 = &snd_check_data[0];
#endif
      
      FSAL_Direct_SetRamFileSize(&snd_file, sz_snd_ut_pattern);
      eFSALRet = FSAL_Open(&snd_file, (void *)snd_ut_pattern, FSAL_ROMFILE);
      ASSERT(eFSALRet==FSAL_OK);

      snd_hdl = SND_Open(snd_ut_event_handler, &snd_param);
      snd_param->pstFSAL = &snd_file;
      snd_param->repeats = snd_repeats; /* not necessary, default 1 */
      SND_SetOutputDevice( snd_output_buffer );
      //SND_SetMix(snd_hdl, snd_mix); /* not necessary, default true */
      SND_ConfigULMixer(snd_hdl, snd_ul_sph_flag, snd_ul_gain);
      SND_ConfigDLMixer(snd_hdl, snd_dl_sph_flag, snd_dl_gain);
#ifdef SND_APPLY_MCU_GAIN
      SND_SetLevel(snd_hdl, snd_level);
#endif
      SND_Play(snd_hdl);
      snd_play_flag = 1;
      return true;
   }
   else
   {
      SND_Stop(snd_hdl);
      SND_Close(snd_hdl);
      snd_hdl = NULL;      
      snd_play_flag = 0;
      return false;
   }
}

void snd_ut_config( kal_bool flag ){
   if(flag==KAL_TRUE){
      snd_ul_gain += 10;
      snd_dl_gain -= 10;
   }
   else{
      snd_ul_gain -= 10;
      snd_dl_gain += 10;
   }

   if(snd_ul_gain>100)
      snd_ul_gain = 100;
   else if(snd_ul_gain<0)
      snd_ul_gain = 0;

   if(snd_dl_gain>100)
      snd_dl_gain = 100;
   else if(snd_dl_gain<0)
      snd_dl_gain = 0;

   SND_ConfigULMixer(snd_hdl, snd_ul_sph_flag, snd_ul_gain);
   SND_ConfigDLMixer(snd_hdl, snd_dl_sph_flag, snd_dl_gain);
}

#ifdef SND_APPLY_MCU_GAIN
void snd_ut_set_level( bool dir ){
  if(dir==true)
    snd_level += 12;
  else
    snd_level -= 12;
  
  if(snd_level > 100)
    snd_level = 100;
  else if(snd_level < 0)
     snd_level = 0;

  if(snd_hdl != NULL)
     SND_SetLevel(snd_hdl, snd_level);
}
#endif /* ...SND_APPLY_MCU_GAIN */

#endif /* ...SND_UNIT_TEST */

#endif /* ...BGSND_ENABLE */
