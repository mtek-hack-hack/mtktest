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
 * wav_thumb.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   critical routines of WAV playback/recording functionality
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "wav.h"
#include "afe.h"
#if defined(MT6223) || defined(MT6223P)
#include "dcmgr.h"
#endif
#define  REAL_RESUMING_SUPPORT

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

// #define  DSP_DEBUG_DEDICATED_MODE_RECORD  // This flag is for DSP to record stereo wave in dedicated mode.

extern void wavADPCMPutData( int32 dsp_len );
extern void wavADPCMPutData_ST( int32 dsp_len );
extern void wavMSADPCMPutData( int32 dsp_len );
extern void (*MS_ADPCM_Decode)( uint16 data, uint32 position );
extern void ms_adpcm_decode_stereo( uint16 data, uint32 position );
extern void ms_adpcm_decode_mono( uint16 data, uint32 position );

extern struct wavHeader_Struct wavHeader;
extern struct wav_Struct wav;

static const kal_uint8 SampleRateTable[] = {
   0x00, /*8000*/   0x11,/* 11025 */ 0x12,/* 12000 */
   0x20, /*16000,*/ 0x21,/* 22050,*/ 0x22,/* 24000,*/
   0x40, /*32000,*/ 0x41,/* 44100,*/ 0x42 /* 48000 */
};

#if defined(REAL_RESUMING_SUPPORT)
static uint16         tmp_BlockCount[2];
static dviAdpcm_State tmp_dvi_state_ch1[2];
static dviAdpcm_State tmp_dvi_state_ch2[2];
static MS_ADPCM_STATE tmp_ms_adpcm_state[2][2];
static short          tmp_aCoeff[2][MSADPCM_EXTRA_COEFF][2];
#endif

#if !defined(MT6205B)
static bool wavRECpcmPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
   **pbuf = data;
   *pbuf = *pbuf + 1;
   *sample_count = 1;
   return true;
}

static bool wavRECalawPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
   wav.data[wav.data_count++] = data;
   if( wav.data_count == 2 ) {
      **pbuf = (uint16)linear2alaw( wav.data[0] ) |
               ((uint16)linear2alaw( wav.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      wav.data_count = 0;
      *sample_count = 2;
      return true;
   }
   return false;
}

static bool wavRECulawPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
   wav.data[wav.data_count++] = data;
   if( wav.data_count == 2 ) {
      **pbuf = (uint16)linear2ulaw( wav.data[0] ) |
               ((uint16)linear2ulaw( wav.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      wav.data_count = 0;
      *sample_count = 2;
      return true;
   }
   return false;
}

static bool wavRECdviPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count )
{
   switch(wav.BlockCount){
      case 128:   wav.BlockCount=0;  /* Reset block counter, store block header */
      case 0:
                  dviAdpcm_Encode( data, &wav.dvi_state_ch1 );
                  **pbuf= (uint16)(int16)wav.dvi_state_ch1.valpred;
                  *pbuf = *pbuf + 1;
                  wav.BlockCount++;
                  *sample_count = 1;
                  return true;
      case 1:   /* store block header */
                  wav.data[wav.data_count++] = data;
                  **pbuf= ( uint16 )(int16)wav.dvi_state_ch1.index;
                  *pbuf = *pbuf + 1;
                  wav.BlockCount++;
                  *sample_count = 0;
                  return true;
      default:
                  wav.data[wav.data_count++] = data; /* store compressed data */
                  if( wav.data_count == 4 ) {
                     **pbuf = dviAdpcm_Encode( wav.data[0], &wav.dvi_state_ch1 ) |
                              (dviAdpcm_Encode( wav.data[1], &wav.dvi_state_ch1 ) << 4) |
                              (dviAdpcm_Encode( wav.data[2], &wav.dvi_state_ch1 ) << 8) |
                              (dviAdpcm_Encode( wav.data[3], &wav.dvi_state_ch1 ) << 12);
                     *pbuf = *pbuf + 1;
                     wav.data_count = 0;
                     wav.BlockCount++;
                     *sample_count = 4;
                     return true;
                  }
   }
   return false;
}

#endif  // #if !defined(MT6205B)

/************************************************************/
/*  data writing to DSP ring buf via IDMA for wav playback  */
/*  Format: linear PCM                                      */
/************************************************************/

static void wavLPCMPutData( int32 dsp_len )
{
   const uint16 *ptr;
   int32 I,count1;
   uint16 dsp_w = *DSP_PCM_W;
   bool mono2stereo = wav.ctrl->mono2stereo;

   if (mono2stereo)
      dsp_len = (dsp_len >> 1);
   
   if( dsp_len <= 0 )
      return;
   
   if( wav.MBCount < dsp_len )   /* modify dsp len if data isn't enough */
      dsp_len = wav.MBCount;     /* D */

   if(wavHeader.wDataLength >= (dsp_len<<1))
      wavHeader.wDataLength -= dsp_len<<1;
   else{
      dsp_len = wavHeader.wDataLength>>1;
      wavHeader.wDataLength = 0;
   }

   count1 = wav.ctrl->rb_size - wav.ctrl->read;  /* C1 */

   ptr = &wav.ctrl->rb_base[wav.ctrl->read];     /* send first sample */
   if (mono2stereo) {
      *DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) = *ptr;
      *IDMA_SHORT_ADDR = *ptr++;
   } else {
      *DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) = *ptr++;
   }

   /***** Data transferring, Handle Media ring buf *****/
   if (mono2stereo) {
      if(dsp_len <= count1 )
      {  /* 1. D <= C1 , write directly */
         for( I = dsp_len - 1; I > 0; I-- ) {    /* data transferring via IDMA */
            *IDMA_SHORT_ADDR = *ptr;
            *IDMA_SHORT_ADDR = *ptr++;
         }
      }
      else
      {  /* 2. D > C1 , two phase transferring */
         for( I = count1 - 1; I > 0; I-- ) {  /* 1st phase */
            *IDMA_SHORT_ADDR = *ptr;
            *IDMA_SHORT_ADDR = *ptr++;
         }

         ptr = wav.ctrl->rb_base;    /* update media data pointer */

         for( I = dsp_len - count1; I > 0; I-- ) {  /* 2nd phase */
            *IDMA_SHORT_ADDR = *ptr;
            *IDMA_SHORT_ADDR = *ptr++;
         }
      }
   } else {
      if(dsp_len <= count1 )
      {  /* 1. D <= C1 , write directly */
         for( I = dsp_len - 1; I > 0; I-- )    /* data transferring via IDMA */
            *IDMA_SHORT_ADDR = *ptr++;
      }
      else
      {  /* 2. D > C1 , two phase transferring */
         for( I = count1 - 1; I > 0; I-- )  /* 1st phase */
            *IDMA_SHORT_ADDR = *ptr++;

         ptr = wav.ctrl->rb_base;    /* update media data pointer */

         for( I = dsp_len - count1; I > 0; I-- )  /* 2nd phase */
            *IDMA_SHORT_ADDR = *ptr++;
      }
   }

   wav.ctrl->dsp_last_sample = *(--ptr);
#if !defined(MT6205B) && !defined(MT6228) && !defined(MT6225) && !defined(MT6229) && !defined(MT6230) && !defined(MT6268T) && !defined(MT6235) && !defined(MT6238)
   /******************************************************/
   SPT_PutPcmData( (int16*)&wav.ctrl->rb_base[wav.ctrl->read], dsp_len, mono2stereo );    /* Send data for spectrum analysis */
   /******************************************************/
#endif   

   wav.ctrl->read += dsp_len;
   if( wav.ctrl->read >= wav.ctrl->rb_size )
      wav.ctrl->read -= wav.ctrl->rb_size;

   if (mono2stereo)
      dsp_w += (dsp_len << 1);
   else
      dsp_w += dsp_len;

   if( dsp_w == wav.ctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;             /* Update DSP writing pointer */
}

/*----------------------------------------------------------------------*/
#define wavShiftReadPointer() \
{ \
   read_cache ++; \
   if( read_cache == rb_size_cache ) { \
      read_cache = 0; \
      prb = wav.ctrl->rb_base; \
   } \
}

static void wavAUlawShortPCM_DecodeSample( int32 dsp_len, const uint16* Table )
{
   int32 I;
   uint16 read_data, dsp_last_sample;
   uint16 dsp_w = *DSP_PCM_W;
   bool mono2stereo = wav.ctrl->mono2stereo;
   uint32 read_cache, rb_size_cache;
   uint16 *prb;


   if(mono2stereo)
      dsp_len = (dsp_len >> 1);
   if (wav.MBCount < (dsp_len >> 1))
      dsp_len = wav.MBCount << 1;

   if (wavHeader.wDataLength >= dsp_len)  /* update data length */
      wavHeader.wDataLength -= dsp_len;
   else
   {
      dsp_len = wavHeader.wDataLength;
      wavHeader.wDataLength = 0;
   }

   if(!mono2stereo)
      dsp_len &= 0xFFFFFFFE;  // Force dsp_len to be even to avoid the alignment problem.
   if (dsp_len <= 0)
      return;

   read_cache = wav.ctrl->read;
   rb_size_cache = wav.ctrl->rb_size;
   prb = &wav.ctrl->rb_base[read_cache];
   read_data = *prb++;
   if (mono2stereo) {
      dsp_last_sample = (Table?Table[read_data & 0x00FF]:(read_data<<8)-0x8000);
      *DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
      *IDMA_SHORT_ADDR = dsp_last_sample;
      dsp_last_sample = (Table?Table[read_data>>8]:(read_data & 0xFF00)-0x8000);   	
      *IDMA_SHORT_ADDR = dsp_last_sample;
      *IDMA_SHORT_ADDR = dsp_last_sample;
   } else {
      *DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) = (Table?Table[read_data & 0x00FF]:(read_data<<8)-0x8000);
      dsp_last_sample = (Table?Table[read_data>>8]:(read_data & 0xFF00)-0x8000);
      *IDMA_SHORT_ADDR = dsp_last_sample;   	
   }
   wav.ctrl->dsp_last_sample = dsp_last_sample;
   wavShiftReadPointer();

   if (mono2stereo) {
      if( Table ) {
         for( I = dsp_len - 2; I > 0; I-=2 )
         {
            read_data = *prb++;
            dsp_last_sample = Table[read_data & 0x00FF];
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            dsp_last_sample = Table[read_data>>8];
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            wavShiftReadPointer();
         }
      } else {
         for( I = dsp_len - 2; I > 0; I-=2 )
         {
            read_data = *prb++;
            dsp_last_sample = (read_data<<8)-0x8000;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            dsp_last_sample = (read_data & 0xFF00)-0x8000;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            wavShiftReadPointer();
         }
      }
      wav.ctrl->dsp_last_sample = dsp_last_sample;
   } else {
      if( Table ) {
         for( I = dsp_len - 2; I > 0; I-=2 )
         {
            read_data = *prb++;
            *IDMA_SHORT_ADDR = Table[read_data & 0x00FF];
            *IDMA_SHORT_ADDR = Table[read_data>>8];
            wavShiftReadPointer();
         }
         wav.ctrl->dsp_last_sample = Table[read_data>>8];
      } else {
         for( I = dsp_len - 2; I > 0; I-=2 )
         {
            read_data = *prb++;
            *IDMA_SHORT_ADDR = (read_data<<8)-0x8000;
            *IDMA_SHORT_ADDR = (read_data & 0xFF00)-0x8000;
            wavShiftReadPointer();
         }
         wav.ctrl->dsp_last_sample = (read_data & 0xFF00)-0x8000;;  // Update the last sample
      }
   }
   wav.ctrl->read = read_cache;  // Update the read pointer

   if (mono2stereo)
      dsp_w += (dsp_len << 1); 
   else
      dsp_w += dsp_len;               /* update DSP buf writing pointer */

   if( dsp_w == wav.ctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;
}

/************************************************************/
/*  data writing to DSP ring buf via IDMA for wav playback  */
/*  Format: G711 A-law/U-law , 8bit-linear PCM              */
/************************************************************/

static void wavPutData8bit( int32 dsp_len ) /* 8 bit linear pcm */
{
   wavAUlawShortPCM_DecodeSample( dsp_len, NULL);
}

static void wavAlawPutData( int32 dsp_len ) /* A-law decoder */
{
   wavAUlawShortPCM_DecodeSample( dsp_len, Alaw_Tab );
}

static void wavUlawPutData( int32 dsp_len )  /* U-law decoder */
{
   wavAUlawShortPCM_DecodeSample( dsp_len, Ulaw_Tab );
}
/*----------------------------------------------------------*/

/*************************************************/

void PutSilence(mediaControl *mctrl, int32 dsp_len)
{
   int32 I;
   uint16 dsp_last_sample = mctrl->dsp_last_sample;
   uint16 dsp_w = *DSP_PCM_W;

   if(dsp_len <= 0)
      return;
   *DSP_DM_ADDR(PAGE_NUM, mctrl->dsp_rb_base + dsp_w) = dsp_last_sample;

   for( I = dsp_len - 1; I > 0; I-- )     /* data transferring via IDMA */
      *IDMA_SHORT_ADDR = dsp_last_sample;

   dsp_w += dsp_len;
   if( dsp_w ==  mctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;             /* Update DSP writing pointer */
}

static void wavWriteToDSP( void )
{
   int16 rb_r, rb_w, tmp1, rb_r_cache;

   rb_w = (int16)*DSP_PCM_W;
   do {
      rb_r = (int16)*DSP_PCM_R;
   } while( rb_r != (int16)*DSP_PCM_R );
   rb_r_cache = rb_r;

   rb_r = rb_r - rb_w -1;
   if( rb_r < 0 )
      rb_r += (int16)wav.ctrl->dsp_rb_size; /* free size of DSP buf */
   rb_r &= 0xFFFFFFFE;

   tmp1 = (int16)wav.ctrl->dsp_rb_size - rb_w;

   if( wav.MBCount )
   {
      if( rb_r > tmp1 )
      {
         wav.Wav_PutData( tmp1 );
         wav.MBCount = mediaGetDataCount();
         rb_r -= tmp1;
      }
      wav.Wav_PutData( rb_r );
   }

   // fill silence
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if ( rb_r_cache < 0 )
      rb_r_cache += (int16)wav.ctrl->dsp_rb_size;
   rb_r_cache &= 0xFFFFFFFE;

   if (rb_r_cache)   // if MCU should fill silence to DSP...
   {
      tmp1 = (int16)wav.ctrl->dsp_rb_size - rb_w;
      if (rb_r_cache > tmp1)
      {
         PutSilence(wav.ctrl, tmp1);
         rb_r_cache -= tmp1;
      }
      PutSilence(wav.ctrl, rb_r_cache);
   }
}

/* search "data" chunk descriptor */
static bool wavPLAYSearchData( void )
{
   uint32 data_32;
   do {
      if( wav.next_chunk && (wav.next_chunk -= rb_SkipNWord( wav.next_chunk )) != 0  )
         return false;
      if( rb_GetByteCount() < 8 )
         return false;
      if( rb_GetDWord( &data_32 ) == false ) // Get chunk id
         return false;
      if( data_32 == 0x61746164 )            // "data"
         break;
      if( rb_GetDWord( &wav.next_chunk ) == false )    // Get chunk size
         return false;
      wav.next_chunk = ( wav.next_chunk + 1 ) >> 1;
      wav.next_chunk -= rb_SkipNWord( wav.next_chunk );
      if( wav.next_chunk )
         return false;
   }while( 1 );
   if( rb_GetDWord( &wavHeader.wDataLength ) == false ) /* Get the data ckSize */
      return false;
   return true;
}

static void wavEndHandler(void *data, Media_Event event)
{
   (void) data;      // to avoid warning
#if !defined(MT6205B)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if (wav.ctrl->is_8KVoice)
      AM_PCM8K_PlaybackOff( false );
   else
#endif
      AM_AudioPlaybackOff( false );
#else
   AM_PCM8K_PlaybackOff( false );
#endif
   mediaSetEvent( MEDIA_END );
   wav.state = WAV_STATE_IDLE;
}

void wavPlaybackHisr( void )
{
   if( wav.state != WAV_STATE_READY_TO_PLAY && wav.state != WAV_STATE_PLAYING )
      return;
   if( wav.ctrl->end_status == MEDIA_TERMINATED )
      return;
   wav.MBCount = mediaGetDataCount();
   if( ((wav.MBCount <= 4 && wav.ctrl->eof) ||
        (wav.state == WAV_STATE_PLAYING && wavHeader.wDataLength == 0)) &&
        *DSP_PCM_CTRL == 8)
   {
      wav.ctrl->end_status = MEDIA_END;
      *DSP_PCM_CTRL = 0x10;
      return;
   }

   if( *DSP_PCM_CTRL == 0 ) {   /* DSP returns to idle state */
#if APM_SUPPORT
      APM_NOTIFY_MEDIA_END( wavEndHandler, NULL, false , MEDIA_END);
#else
      wavEndHandler(NULL, 0);
#endif
      return;
   }

   if( *DSP_PCM_CTRL == 2 ) {   /* DSP gives IDMA address and length */
      wav.ctrl->dsp_rb_base = *DSP_PCM_W;
      wav.ctrl->dsp_rb_size = *DSP_PCM_R;
      wav.ctrl->dsp_rb_end = wav.ctrl->dsp_rb_base + wav.ctrl->dsp_rb_size;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
      PutSilence( wav.ctrl, wav.ctrl->dsp_rb_size );
      // data chunk has not been found yet, fill silence pattern to dsp ring buffer
      *DSP_PCM_CTRL = 4;
   }

   // If the data chunk is not found yet, look for it
   if( wav.state == WAV_STATE_READY_TO_PLAY && wavPLAYSearchData() ){
      wav.state = WAV_STATE_PLAYING;
      wav.ctrl->isDataConsumed = true;
   }
   if( wav.state == WAV_STATE_PLAYING )
      wavWriteToDSP();
}

#if !defined(MT6205B)

static void wavReadFromDSP( int16 *buf )
{
   int32 first_data_block_len, second_data_block_len;
   int32 I, tmp, count;
   uint16 dummy, ptr_addr;

   if(wav.dedicated_mode){ /* WAV recording in TCH mode */

      ASSERT( *DP_TCH_UL_LEN == FRAME_BUF_SIZE );   /* frame size */
      ASSERT( *DP_TCH_DL_LEN == FRAME_BUF_SIZE );   /* frame size */
      
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
      // Uplink
      first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
      if( first_data_block_len < FRAME_BUF_SIZE )
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      else
      {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_PTR);
      for ( I = first_data_block_len; I > 0; I-- )
      {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      if( (I = second_data_block_len) > 0 )
      {
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_BUF_ADDR0);
         for ( ; I > 0 ;I-- )
         {
            *buf = (int16)(*IDMA_SHORT_ADDR);
            buf += 2;
         }
      }      
      // Downlink
      buf -= ((FRAME_BUF_SIZE << 1) - 1);
      first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
      if( first_data_block_len < FRAME_BUF_SIZE )
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      else
      {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR);
      for ( I = first_data_block_len; I > 0; I-- )
      {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      if( (I = second_data_block_len) > 0 )
      {
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0);
         for ( ; I > 0 ;I-- )
         {
            *buf = (int16)(*IDMA_SHORT_ADDR);
            buf += 2;
         }
      }
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
      first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
      if( first_data_block_len < FRAME_BUF_SIZE )
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_PTR);  /* Read uplink data */
      for ( I = first_data_block_len; I > 0; I-- )
         *buf++ = (int16)(*IDMA_SHORT_ADDR);
      if( (I = second_data_block_len) > 0 ){
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_BUF_ADDR0);
         for ( ; I > 0 ;I-- )
            *buf++ = (int16)(*IDMA_SHORT_ADDR);
      }

      /* handle downlink data */
      buf -= FRAME_BUF_SIZE;
      first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
      if( first_data_block_len < FRAME_BUF_SIZE )
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR);  /* Read downlink data */
      for( I = first_data_block_len; I > 0; I-- ){
         tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
         *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
      }
      if( (I = second_data_block_len) > 0 ){
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0);
         for ( ; I > 0; I-- ){
            tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
            *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
         }
      }
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
   }else{  /* for WAV recording in idle mode */
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      if ( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K ){ 
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
         ptr_addr = *DSP2_DM_ADDR( PAGE_NUM, DSP_PCM_16K_REC_PTR);//get address
         dummy    = *DSP2_DM_ADDR( PAGE_NUM, ptr_addr);           //trigger IDMA
#else
         ptr_addr = *DSP_DM_ADDR( PAGE_NUM, DSP_PCM_16K_REC_PTR); //get address
         dummy    = *DSP_DM_ADDR( PAGE_NUM, ptr_addr);            //trigger IDMA
#endif
         count = FRAME_BUF_SIZE_16K;
      }
      else
#endif
      {
         dummy = *DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR);
         count = (int32)(*DSP_PCM_REC_LEN);
      }

      for( I = count; I > 0; I-- ) {
         *buf++ = (int16)(*IDMA_SHORT_ADDR);
      }
   }
}

static void wavDataEncode( void *data ) /* This function works in L1Audio Task */
{
   int32 I, count, write_count;
   uint16 *rb_addr, *rb_end, sample_count, *SCptr, *ptr, frame_len;

   (void)data;
   SCptr = &sample_count;
   rb_end   = &wav.ctrl->rb_base[wav.ctrl->rb_size];
   rb_addr  = &wav.ctrl->rb_base[wav.ctrl->write];

   if( wav.ctrl->end_status == MEDIA_TERMINATED) {
      if( (wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM || wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
         && wav.BlockCount != 128 && wav.state == WAV_STATE_IDLE) {
         write_count = 0;
         count = 128 - wav.BlockCount;     /* zero padding the latest block */
         count <<= 2;
         for( I = count; I > 0; I-- ) {
            if( wav.PutSample( &rb_addr, 0 , SCptr) ) {
               write_count++;
               wavHeader.wRiffLength+=2;
               wavHeader.wDataLength+=2;
               wavHeader.wSamplesWritten += sample_count;
               if( rb_addr == rb_end )
                  rb_addr = &wav.ctrl->rb_base[0];
            }
         }
         wav.ctrl->write += write_count;
         if( wav.ctrl->write >= wav.ctrl->rb_size )
            wav.ctrl->write -= wav.ctrl->rb_size;
      }
      return;
   }

   while( (uint8)(wav.tmp_w - wav.tmp_r) > 0 ) {
      write_count = 0;
      ptr = wav.tmp_buf[wav.tmp_r&FRAME_BUF_MASK];
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
      if( FRAME_BUF_SIZE * 2 <= mediaGetFreeSpace() ) {
         for( I = FRAME_BUF_SIZE * 2; I > 0; I-- ) {  /* writing to MB */
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      if ( wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
         frame_len = FRAME_BUF_SIZE_16K;
      else
#endif
         frame_len = FRAME_BUF_SIZE;
      if( frame_len <= mediaGetFreeSpace() ) {
         for( I = frame_len; I > 0; I-- ) {  /* writing to MB */
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
            if( wav.PutSample( &rb_addr, *ptr++, SCptr) ) {
               write_count++;
               wavHeader.wRiffLength+=2;
               wavHeader.wDataLength+=2;
               wavHeader.wSamplesWritten += sample_count;
               if( rb_addr == rb_end )
                  rb_addr = &wav.ctrl->rb_base[0];
            }
         }
         wav.ctrl->write += write_count;
         if( wav.ctrl->write >= wav.ctrl->rb_size )
            wav.ctrl->write -= wav.ctrl->rb_size;
      }
      wav.tmp_r++;
   }
}

void wavRecordHisr( void )
{
   if(wav.state != WAV_STATE_RECORDING)
      return;

   if( wav.ctrl->end_status == MEDIA_TERMINATED) {
      if( (wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM  || wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
         && wav.BlockCount != 128 && wav.state == WAV_STATE_IDLE){
         L1Audio_SetEvent( wav.aud_id, (void *)0 );        /* zero padding */
      }
      return;
   }
   if(!wav.dedicated_mode && wav.ctrl->format != MEDIA_FORMAT_WAV_DVI_ADPCM_16K ){
      if( *DSP_PCM_REC_CTRL == 0 ) {   /* DSP returns to idle state */
         return;
      }
   }
#ifdef __PRODUCTION_RELEASE__
   if( (uint8)(wav.tmp_w - wav.tmp_r) < FRAME_BUF_NO )
   {
      wavReadFromDSP((int16 *)wav.tmp_buf[wav.tmp_w&FRAME_BUF_MASK] );
      wav.tmp_w++;
      L1Audio_SetEvent( wav.aud_id, (void *)0 ); /* Activate the encoder runing in l1audio task */
   }
#else
   ASSERT( (uint8)(wav.tmp_w - wav.tmp_r) < FRAME_BUF_NO );
   wavReadFromDSP((int16 *)wav.tmp_buf[wav.tmp_w&FRAME_BUF_MASK] );
   wav.tmp_w++;
   L1Audio_SetEvent( wav.aud_id, (void *)0 ); /* Activate the encoder runing in l1audio task */
#endif // __PRODUCTION_RELEASE__
}

void wavInternalRecord( void )
{
   uint16 I;
   wav.state = WAV_STATE_RECORDING;
   wav.ctrl->end_status = MEDIA_NONE;
#if defined(MT6223) || defined(MT6223P)
   if( !DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
#endif
   if(wav.dedicated_mode){ /* WAV recording in TCH mode */
      AM_PCM8K_RecordOn();
   }else{
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      if ( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
         AM_PCM16K_RecordOn();
      else
#endif
      {
         *DSP_PCM_REC_CTRL  = 0x200;
         AM_PCM8K_RecordOn();
         for( I = 0; ; I++ ) {
            if( *DSP_PCM_REC_CTRL == 0x400 )
               break;
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
      }
   }
}

void wavRecord( mediaControl *ctrl )
{
   uint16 I, frame_len;
   wav.ctrl = ctrl;

   wav.BlockCount = 0;
   wav.data_count  = 0;
   wavHeader.wSamplesWritten=0;
   wavHeader.wDataLength=0;
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
   ASSERT(ctrl->rb_size > FRAME_BUF_SIZE * FRAME_BUF_NO * 4);
   ctrl->rb_size -= FRAME_BUF_SIZE * FRAME_BUF_NO * 2; /* Get temp buffer */
   for( I = 0; I < FRAME_BUF_NO; I++ )
      wav.tmp_buf[I] = &ctrl->rb_base[ctrl->rb_size + FRAME_BUF_SIZE*I*2];
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if ( ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
      frame_len = FRAME_BUF_SIZE_16K;
   else
#endif
      frame_len = FRAME_BUF_SIZE;
   ASSERT(ctrl->rb_size > frame_len * FRAME_BUF_NO * 2);
   ctrl->rb_size -= frame_len * FRAME_BUF_NO; /* Get temp buffer */
   for( I = 0; I < FRAME_BUF_NO; I++ )
      wav.tmp_buf[I] = &ctrl->rb_base[ctrl->rb_size + frame_len*I];
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
   wav.tmp_r = 0;
   wav.tmp_w = 0;
   
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
   wav.ctrl->format = MEDIA_FORMAT_WAV;
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD

   switch(wav.ctrl->format){
      case MEDIA_FORMAT_WAV:
         wav.PutSample = wavRECpcmPutSample;
         wav.data_size = 1;
         wavHeader.wRiffLength=36;
         wav.ctrl->write += 22;
         break;
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
         wav.PutSample = (wav.ctrl->format == MEDIA_FORMAT_WAV_ALAW)? wavRECalawPutSample:wavRECulawPutSample;
         wav.data_size = 2;
         wavHeader.wRiffLength=50;
         wav.ctrl->write += 29;
         break;
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
         wav.PutSample = wavRECdviPutSample;
         wav.data_size = 4;
         wavHeader.wRiffLength=52;
         wav.ctrl->write += 30;
         dviAdpcm_Init( &wav.dvi_state_ch1 );
   }
   wav.dedicated_mode = AM_IsSpeechOn();
   wavInternalRecord();
}

#endif   

static bool wavReadHeader( void )
{
   uint32 dummy_32, ckSize, bytes_read;
   uint16 dummy_16, FormatTag;

/* Check to see if header is invalid, "RIFF" chunk descriptor */
   if( rb_GetDWord( &dummy_32 ) == false || dummy_32 != 0x46464952 )
      return false;

   rb_SkipNWord( 2 );

   if( rb_GetDWord( &dummy_32 ) == false || dummy_32 != 0x45564157 )
      return false;

   do {
      if( rb_GetDWord( &dummy_32 ) == false )
         return false;
      if( dummy_32 == 0x20746D66 )        // seek sub-chunk "fmt chunk"
         break;
      if( rb_GetDWord( &dummy_32 ) == false )
         return false;
      if( rb_SkipNWord( dummy_32 >> 1 ) != (dummy_32 >> 1) )
         return false;
   }while(1);
   // Get the fmt ckSize
   if( rb_GetDWord( &ckSize ) == false || ckSize < 16 )
      return false;

   /* Check fmt chunk */
   rb_GetWord ( &FormatTag );

   rb_GetWord ( &dummy_16 );              // channel count
   if( dummy_16 == 1 ) {
#if  defined(MT6205B) || ((defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)) && defined(__ROMSA_SUPPORT__))
      *DSP_PCM_MS &= ~(0x0001);
      wav.ctrl->mono2stereo = false;
#else
      *DSP_PCM_MS |= 0x0001;
      wav.ctrl->mono2stereo = true;
#endif
      wav.ctrl->is_stereo = false;
   }
#if !defined(MT6205B)
   else if( dummy_16 == 2 ) {
      *DSP_PCM_MS |= 0x0001;
      wav.ctrl->is_stereo = true;
      wav.ctrl->mono2stereo = false;
   }
#endif
   else
      return false;

   rb_GetDWord( &dummy_32 );              // sample rate
   switch( dummy_32 / 1000 ){             // update sample rate index of control table
      case 8:  wav.sr_index = 0;
         break;
#if !defined(MT6205B)
      case 11: wav.sr_index = 1;
         break;
      case 12: wav.sr_index = 2;
         break;
      case 16: wav.sr_index = 3;
         break;
      case 22: wav.sr_index = 4;
         break;
      case 24: wav.sr_index = 5;
         break;
      case 32: wav.sr_index = 6;
         break;
      case 44: wav.sr_index = 7;
         break;
      case 48: wav.sr_index = 8;
         break;
#endif
      default: return false;
   }
   rb_GetDWord( &dummy_32 );              // AvgBytesPerSec
   rb_GetWord ( &wavHeader.wBlockAlign ); // wavHeader.wBlockAlign
   rb_GetWord ( &dummy_16 );              // BitsPerSample
   bytes_read = 16;
   switch( FormatTag ) {
      case 0x0001:
         if( dummy_16 == 8 )
            wav.Wav_PutData = wavPutData8bit;
         else if( dummy_16 == 16 )
            wav.Wav_PutData = wavLPCMPutData;
         else
            return false;
         wav.data_size = 1;
         break;
      case 0x0006:
      case 0x0007:
         wav.Wav_PutData = ( FormatTag == 0x0006 )?
            wavAlawPutData : wavUlawPutData;
         wav.data_size = 2;
         break;
      case 0x0011:
         if( dummy_16 != 4 )                 // support 4 bit dvi-adpcm only
            return false;
         wav.data_size = 4;
         wav.Wav_PutData = ( wav.ctrl->is_stereo )?
            wavADPCMPutData_ST : wavADPCMPutData;
         break;
      case 0x0002:                           // MS ADPCM
         if( dummy_16 != 4 )                 // support 4 bit ms-adpcm only
            return false;
         wav.data_size = 4;
         wav.Wav_PutData = wavMSADPCMPutData;
         if( wav.ctrl->is_stereo )              // test if stereo
            MS_ADPCM_Decode = ms_adpcm_decode_stereo;
         else
            MS_ADPCM_Decode = ms_adpcm_decode_mono;
         rb_GetWord( &dummy_16 );            // cbSize
         rb_GetWord( &dummy_16 );            // nSamplesPerBlock
         rb_GetWord( &wavHeader.nNumCoef );  // nSamplesPerBlock
         if( wavHeader.nNumCoef > MSADPCM_EXTRA_COEFF + 7 )
            return false;
         if( rb_SkipNWord( 14 ) != 14 )
            return false;
         for( dummy_32=0; dummy_32 < wavHeader.nNumCoef - 7; dummy_32++ )
         {
            // These values are stored in 8.8 signed format !!!
            rb_GetWord( (uint16*)&(wav.aCoeff[dummy_32][0]) );
            rb_GetWord( (uint16*)&(wav.aCoeff[dummy_32][1]) );
         }
         bytes_read += 6 + wavHeader.nNumCoef * 4;
         break;
      default:
         return false;
   }
   if( rb_SkipNWord((ckSize - bytes_read) >> 1) != ((ckSize - bytes_read) >> 1))
      return false;
   wav.next_chunk = 0;
   return true;
}

void wavInternalPlay( void )  /* actviate DSP audio task */
{
   uint16 I;
   wav.ctrl->end_status = MEDIA_NONE;

   wav.ctrl->is_8KVoice = false;
#if defined(__BT_SUPPORT__)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if ( (AM_IsBluetoothOn() == true) && (wav.sr_index == 0x00) && (wav.ctrl->is_stereo == false) ) {
      wav.ctrl->is_8KVoice = true;
      wav.ctrl->mono2stereo = false;
   }
#endif
#endif

#if !defined(MT6205B)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if (wav.ctrl->is_8KVoice) {
      AM_PCM8K_PlaybackOn();
   } else 
#endif
   {
#if defined( DSP_WT_SYN )
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, (uint16)SampleRateTable[wav.sr_index] );
      AFE_SetDigitalGain( L1SP_AUDIO, wav.ctrl->level );
   }
#else
   AM_PCM8K_PlaybackOn();
#endif
   *DSP_PCM_CTRL = 1;
   for( I = 0; ; I++ ) {
      if( *DSP_PCM_CTRL == 8 || wav.ctrl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 60 ); // YS modified
      kal_sleep_task( 2 );
   }
}

#if defined(REAL_RESUMING_SUPPORT)
void wavSetAdpcmState(bool realResume, uint32 mode)
{
   if(realResume)
   {
      wav.BlockCount = tmp_BlockCount[mode];
      wav.dvi_state_ch1.index = tmp_dvi_state_ch1[mode].index;
      wav.dvi_state_ch2.index = tmp_dvi_state_ch2[mode].index;
      wav.dvi_state_ch1.valpred = tmp_dvi_state_ch1[mode].valpred;
      wav.dvi_state_ch2.valpred = tmp_dvi_state_ch2[mode].valpred;

      memcpy(wav.ms_adpcm_state, tmp_ms_adpcm_state[mode], 2*sizeof(MS_ADPCM_STATE));
      memcpy(wav.aCoeff, tmp_aCoeff[1], 20*sizeof(short));

   } else
    {
      wav.BlockCount = 0;  /* reset counter */
    }
}

void wavGetAdpcmState(uint32 mode)
{
    tmp_BlockCount[mode] = wav.BlockCount;
    tmp_dvi_state_ch1[mode].index = wav.dvi_state_ch1.index;
    tmp_dvi_state_ch2[mode].index = wav.dvi_state_ch2.index;
    tmp_dvi_state_ch1[mode].valpred = wav.dvi_state_ch1.valpred;
    tmp_dvi_state_ch2[mode].valpred = wav.dvi_state_ch2.valpred;

    memcpy(tmp_ms_adpcm_state[mode], wav.ms_adpcm_state, 2*sizeof(MS_ADPCM_STATE));
    memcpy(tmp_aCoeff[mode], wav.aCoeff, 20*sizeof(short));
}

void wavCopyAdpcmState(uint32 src_mode, uint32 dst_mode)
{
    tmp_BlockCount[dst_mode] = tmp_BlockCount[src_mode];
    memcpy( &tmp_dvi_state_ch1[dst_mode], &tmp_dvi_state_ch1[src_mode], sizeof(dviAdpcm_State) );
    memcpy( &tmp_dvi_state_ch2[dst_mode], &tmp_dvi_state_ch2[src_mode], sizeof(dviAdpcm_State) );
    memcpy( tmp_ms_adpcm_state[dst_mode], tmp_ms_adpcm_state[src_mode], sizeof(MS_ADPCM_STATE) );
    memcpy(tmp_aCoeff[dst_mode], tmp_aCoeff[src_mode], 20*sizeof(short));
}
#endif

Media_Status wavPlay( mediaControl *mctrl )
{
   wav.ctrl = mctrl;   /* initiate data */
   ASSERT(wav.state == WAV_STATE_IDLE);
   if( !wavReadHeader() )   /* read *.wav file header, return header length */
      return MEDIA_BAD_FORMAT;

   //wav.BlockCount = 0;  /* reset counter */
   wav.data_count = 0;
   wav.ctrl->dsp_last_sample = 0;
   wav.state = WAV_STATE_READY_TO_PLAY;     /* Ready state */

   wavInternalPlay();
   return MEDIA_SUCCESS;
}

#if !defined(MT6205B)

void wavRecordTurnOffDSP(void)
{
   uint16 I, ctl;
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if (wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
      AM_PCM16K_RecordOff( true );
   else
#endif
   {
      for( I = 0; ; I++ ) {
         ctl = *DSP_PCM_REC_CTRL;
         if( ctl == 0 )                /* DSP returns to idle state */
            break;
         if( ctl == 0x400 )
            *DSP_PCM_REC_CTRL = 0x800;  /* give ABORT command to the DSP */
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
      AM_PCM8K_RecordOff( true );
   }
#if defined(MT6223) || defined(MT6223P)
   if( DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Unload( DYNAMIC_CODE_SBC );
#endif 
}
#endif    //  #if !defined(MT6205B)

void wavPlayTurnOffDSP(void)
{
   uint16 I, ctl;
   for( I = 0; ; I++ ) {
      ctl = *DSP_PCM_CTRL;
      if( ctl == 0 )                /* DSP returns to idle state */
         break;
      if( ctl == 8 )
         *DSP_PCM_CTRL = WAV_ABORT_STATE;       /* give ABORT command to the DSP */
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }

#if !defined(MT6205B)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if (wav.ctrl->is_8KVoice)
     AM_PCM8K_PlaybackOff( true );
   else
#endif
      AM_AudioPlaybackOff( true );
#else
   AM_PCM8K_PlaybackOff( true );
#endif
}

void wavStop( void )
{
   wav.ctrl->end_status = MEDIA_TERMINATED;
   if(wav.state == WAV_STATE_IDLE)
      return;
   switch(wav.state) {
#if !defined(MT6205B)
      case WAV_STATE_RECORDING:
      case WAV_STATE_RECORD_PAUSE:
         wavRecordTurnOffDSP();
         break;
      case WAV_STATE_READY_PAUSE:
      case WAV_STATE_PLAY_PAUSE:
#endif
      case WAV_STATE_READY_TO_PLAY:
      case WAV_STATE_PLAYING:
         wavPlayTurnOffDSP();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
   wav.state = WAV_STATE_IDLE;  /* return to idle state */
}
#if !defined(MT6205B)

void wavGetFileHeader( uint32 *len )
{
   rb_ClearRB();
   rb_PutDWord( 0x46464952 );/* RIFF , 0*/

   if((wavHeader.wRiffLength+8) == (wav.ctrl->file_len<<1)){
      rb_PutDWord(wavHeader.wRiffLength);   /* file size , 2*/
   }else{
       rb_PutDWord((wav.ctrl->file_len<<1)-8);   /* file size , 2*/
       wavHeader.wDataLength -= (wavHeader.wRiffLength+8)-(wav.ctrl->file_len<<1);
       if( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM || wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
          wavHeader.wSamplesWritten = (wavHeader.wDataLength>>8)*505;
       else
          wavHeader.wSamplesWritten = wavHeader.wDataLength;
    }

   rb_PutDWord( 0x45564157 );  /* WAVE , 4 */
   rb_PutDWord( 0x20746D66 );   /* fmt , 6 */

   switch (wav.ctrl->format) {
      case MEDIA_FORMAT_WAV:     /* linear PCM */
         rb_PutDWord(16);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord(0x01); /*wavHeader.wFormatTag, 10 */
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutWord(2); /*wavHeader.wChannels , 11 */
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutDWord(8000); /* wavHeader.wSamplesPerSecond, 12 */
         rb_PutDWord(16000); /*wavHeader.wAvgBytesPerSec, 14 */
         rb_PutWord(2);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(16);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutDWord( 0x61746164 );   /* data , 18 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 20 */
         *len = (uint32)44;   /* Byte pre unit */
         //wav.ctrl->write+=22;
         break;
      case MEDIA_FORMAT_WAV_ALAW:     /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:     /* g.711 mu-law */
         rb_PutDWord(18);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord((wav.ctrl->format==MEDIA_FORMAT_WAV_ALAW)?0x06:0x07); /*wavHeader.wFormatTag, 10 */
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
         rb_PutDWord(8000); /* wavHeader.wSamplesPerSecond, 12 */
         rb_PutDWord(8000); /*wavHeader.wAvgBytesPerSec, 14 */
         rb_PutWord(1);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(8);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutWord(0);  /*wavHeader.wExtSize, 18 */
         rb_PutDWord( 0x74636166 );   /* fact , 19 */
         rb_PutDWord(4);   /* wavHeader.wFactSize, 21 */
         rb_PutDWord(wavHeader.wSamplesWritten); // 23
         rb_PutDWord(0x61746164);/* data, 25 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 27 */
         *len = (uint32)58;
         //wav.ctrl->write+=29;
         break;
      case MEDIA_FORMAT_WAV_DVI_ADPCM:    /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         rb_PutDWord(20);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord(0x11); /*wavHeader.wFormatTag, 10 */
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
         if( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K ){
            rb_PutDWord(16000);/* wavHeader.wSamplesPerSecond, 12 */
            rb_PutDWord(8110); /*wavHeader.wAvgBytesPerSec, 14 */
         } else {
            rb_PutDWord(8000); /* wavHeader.wSamplesPerSecond, 12 */
            rb_PutDWord(4055); /*wavHeader.wAvgBytesPerSec, 14 */
         }
         rb_PutWord(256);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(4);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutWord(2);  /*wavHeader.wExtSize, 18 */
         rb_PutWord(505);  /* wavHeader.wSamplesPerBlock, 19 */
         rb_PutDWord( 0x74636166 );   /* data , 20 */
         rb_PutDWord(4);   /* wavHeader.wFactSize, 22 */
         rb_PutDWord(wavHeader.wSamplesWritten); // 24
         rb_PutDWord(0x61746164);/* data, 26 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 28 */
         *len = (uint32)60;
         //wav.ctrl->write+=30;
         break;
      default:
         *len = (uint32) 0;
   }
}

void wavPause(mediaControl *mctrl)
{
   wav.ctrl->end_status = MEDIA_TERMINATED;
   switch(wav.state) {
      case WAV_STATE_RECORDING:
         wavRecordTurnOffDSP();
         wav.state = WAV_STATE_RECORD_PAUSE;
         break;
      case WAV_STATE_READY_TO_PLAY:
         wavPlayTurnOffDSP();
         wav.state = WAV_STATE_READY_PAUSE;
         break;
      case WAV_STATE_PLAYING:
         wavPlayTurnOffDSP();
         wav.state = WAV_STATE_PLAY_PAUSE;
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

void wavResume(mediaControl *mctrl)
{
   switch(wav.state) {
      case WAV_STATE_RECORD_PAUSE:
         wav.state = WAV_STATE_RECORDING;
         wavInternalRecord();
         break;
      case WAV_STATE_READY_PAUSE:
         wav.state = WAV_STATE_READY_TO_PLAY;
         wavInternalPlay();
         break;
      case WAV_STATE_PLAY_PAUSE:
         wav.state = WAV_STATE_PLAYING;
         wavInternalPlay();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

void wavUpdateLevel( void )
{
   AFE_SetDigitalGain( L1SP_AUDIO, wav.ctrl->level );
}

void wavInit( uint16 aud_id )
{
   wav.aud_id = aud_id;
   wav.state = WAV_STATE_IDLE;  /* idle state */
   L1Audio_SetEventHandler( wav.aud_id, wavDataEncode );
}
#endif    //  #if !defined(MT6205B)
