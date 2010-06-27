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
 * pcm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PCM recording/playback
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __L1_STANDALONE__ // avoid link error

#include "wav.h"
#include "afe.h"

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

/* ------------------------------------------------------------------------------ */
static struct{
   mediaControl   *ctrl;
   /* PCM/ADPCM/ALAW/ULAW specific variables */
   uint16         data[4];
   uint8          data_size;
   uint8          data_count;
   bool           isPlayback;
   uint16         (*GetSample)( const uint16 **pbuf );
   bool           (*PutSample)( uint16 **pbuf, uint16 data );
   dviAdpcm_State dvi_state;

   // For EOF Handling
   bool           decode_EOF;
   int16          dsp_last_sample;
   int32          zeroCount;
} pcm;

/* ------------------------------------------------------------------------------ */
static int32 pcmWriteIDMA( const uint16 *buf, int32 len )
{
   int32 I, count;
   uint16 rb_w, data;

   rb_w = *DSP_PCM_W;

   do {
      I = (int32)*DSP_PCM_R;
   } while( I != (int32)*DSP_PCM_R );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += pcm.ctrl->dsp_rb_size;

   if (pcm.ctrl->mono2stereo) {
      len <<= 1;
      I &= 0xFFFE;
   }

   len *= pcm.data_size;
   if( I < len )
      len = I;

   if( len == 0 )
      return 0;

   count = (int32)(pcm.ctrl->dsp_rb_size - rb_w);
   if( count > len )
      count = len;

#if defined(MT6205B)
   data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf) * pcm.ctrl->max_swing >> MASTER_GAIN_FACTOR);
#else
   data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf));
#endif
   *DSP_DM_ADDR(PAGE_NUM, pcm.ctrl->dsp_rb_base + rb_w) = data;
   if (pcm.ctrl->mono2stereo) {
      *IDMA_SHORT_ADDR = data;
      for( I = count-1; I > 0; I-=2 ) {
#if defined(MT6205B)
         data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf) * pcm.ctrl->max_swing >> MASTER_GAIN_FACTOR);
#else
         data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf));
#endif
         *IDMA_SHORT_ADDR = data;
         *IDMA_SHORT_ADDR = data;
      }
   } else {
      for( I = count-1; I > 0; I-- ) {
#if defined(MT6205B)
         data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf) * pcm.ctrl->max_swing >> MASTER_GAIN_FACTOR);
#else
         data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf));
#endif
         *IDMA_SHORT_ADDR = data;
      }
   }

   rb_w += (uint16)count;
   if( rb_w >= pcm.ctrl->dsp_rb_size )
      rb_w = 0;
   *DSP_PCM_W = rb_w;

   count = len - count;
   if( count > 0 ) {
#if defined(MT6205B)
      data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf) * pcm.ctrl->max_swing >> MASTER_GAIN_FACTOR);
#else
      data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf));
#endif
      *DSP_DM_ADDR(PAGE_NUM, pcm.ctrl->dsp_rb_base + rb_w) = data;
      if (pcm.ctrl->mono2stereo) {
         *IDMA_SHORT_ADDR = data;
         for( I = count-2; I > 0; I-=2 ) {
#if defined(MT6205B)
            data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf) * pcm.ctrl->max_swing >> MASTER_GAIN_FACTOR);
#else
  	        data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf));
#endif
            *IDMA_SHORT_ADDR = data;
            *IDMA_SHORT_ADDR = data;
         }
      } else {
         for( I = count-1; I > 0; I-- ) {
#if defined(MT6205B)
            data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf) * pcm.ctrl->max_swing >> MASTER_GAIN_FACTOR);
#else
  	        data = (uint16)(int16)((int32)(int16)pcm.GetSample(&buf));
#endif
            *IDMA_SHORT_ADDR = data;
         }
      }
      *DSP_PCM_W = rb_w + (uint16)count;
   }

   if( pcm.data_size == 2 )
      len = ( len + 1 ) >> 1;
   else if( pcm.data_size == 4 )
      len = ( len + 3 ) >> 2;

   if (pcm.ctrl->mono2stereo)
      len = (len + 1) >> 1;

   pcm.dsp_last_sample = data;

   return len;
}

static void pcmWriteToDSP( void )
{
   int32 I, count;
   
   if (pcm.decode_EOF) {
      if (pcm.zeroCount > 0) {
         kal_int32 count;
         
         count = wavPutSilence(pcm.ctrl->dsp_rb_base, pcm.ctrl->dsp_rb_size, pcm.dsp_last_sample);
         pcm.zeroCount -= count;
      }
      
      if (pcm.zeroCount <= 0) {
         pcm.ctrl->end_status = MEDIA_END;
         if( *DSP_PCM_CTRL == 8 )
            *DSP_PCM_CTRL = 0x10;
      }
      return;
   }

   count = mediaGetDataCount();
   if (count == 0) {
   	  if (pcm.ctrl->eof) {
         pcm.decode_EOF = true;
         pcm.zeroCount = wavGetDSPDataCnt(pcm.ctrl->dsp_rb_size);
//         wavPutSilence(pcm.ctrl->dsp_rb_base, pcm.ctrl->dsp_rb_size, pcm.dsp_last_sample);
         return;
      }
   }

   I = pcm.ctrl->rb_size - pcm.ctrl->read;
   if( I > count )
      I = count;
   count -= I;

   I = pcmWriteIDMA( &pcm.ctrl->rb_base[pcm.ctrl->read], I );
   pcm.ctrl->read += I;

   if( pcm.ctrl->read >= pcm.ctrl->rb_size ){
      pcm.ctrl->read = 0;
      if( count > 0 ) {
         I = pcmWriteIDMA( &pcm.ctrl->rb_base[pcm.ctrl->read], count );
         pcm.ctrl->read += I;
      }
   }
}

static void pcmReadFromDSP( void )
{
	int32 I, count, write_count = 0;
   uint16 dummy, *rb_addr, *rb_end, ptr_addr;

   count = mediaGetFreeSpace();
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
      I = DSP_PCM_16K_REC_LEN;
   else
#endif
      I = (int32)(*DSP_PCM_REC_LEN);
   if( I < count )
      count = I;
   if( count == 0 )
      return;

   rb_end   = &pcm.ctrl->rb_base[pcm.ctrl->rb_size];
   rb_addr  = &pcm.ctrl->rb_base[pcm.ctrl->write];

#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K ){ 
#if defined (MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      ptr_addr = *DSP2_DM_ADDR(PAGE_NUM, DSP_PCM_16K_REC_PTR);
      dummy    = *DSP2_DM_ADDR(PAGE_NUM, ptr_addr);
#else
      ptr_addr = *DSP_DM_ADDR(PAGE_NUM, DSP_PCM_16K_REC_PTR);
      dummy    = *DSP_DM_ADDR(PAGE_NUM, ptr_addr);
#endif
   }
   else
#endif
      dummy = *DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR);

   for( I = 0; I < count; I++ ) {
      if( pcm.PutSample( &rb_addr, *IDMA_SHORT_ADDR ) ) {
         write_count++;
         if( rb_addr == rb_end )
            rb_addr = &pcm.ctrl->rb_base[0];
      }
   }
   pcm.ctrl->write += write_count;
   if( pcm.ctrl->write >= pcm.ctrl->rb_size )
      pcm.ctrl->write -= pcm.ctrl->rb_size;
}

/* ------------------------------------------------------------------------------ */
static uint16 pcmGetSample( const uint16 **pbuf )
{
   uint16 dat = **pbuf;
   *pbuf = *pbuf + 1;
   return dat;
}

static bool pcmPutSample( uint16 **pbuf, uint16 data )
{
   **pbuf = data;
   *pbuf = *pbuf + 1;
   return true;
}

static uint16 alawGetSample( const uint16 **pbuf )
{
   if( pcm.data_count == 0 ) {
      uint16 data = **pbuf;
      pcm.data[1] = alaw2linear( (uint8)(data & 0xFF) );
      pcm.data[0] = alaw2linear( (uint8)(data >> 8) );
      *pbuf = *pbuf + 1;
      pcm.data_count = 2;
   }
   return pcm.data[--pcm.data_count];
}

static bool alawPutSample( uint16 **pbuf, uint16 data )
{
   pcm.data[pcm.data_count++] = data;
   if( pcm.data_count == 2 ) {
      **pbuf = (uint16)linear2alaw( pcm.data[0] ) +
               ((uint16)linear2alaw( pcm.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      pcm.data_count = 0;
      return true;
   }
   return false;
}

static uint16 ulawGetSample( const uint16 **pbuf )
{
   if( pcm.data_count == 0 ) {
      uint16 data = **pbuf;
      pcm.data[1] = ulaw2linear( (uint8)(data & 0xFF) );
      pcm.data[0] = ulaw2linear( (uint8)(data >> 8) );
      *pbuf = *pbuf + 1;
      pcm.data_count = 2;
   }
   return pcm.data[--pcm.data_count];
}

static bool ulawPutSample( uint16 **pbuf, uint16 data )
{
   pcm.data[pcm.data_count++] = data;
   if( pcm.data_count == 2 ) {
      **pbuf = (uint16)linear2ulaw( pcm.data[0] ) +
               ((uint16)linear2ulaw( pcm.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      pcm.data_count = 0;
      return true;
   }
   return false;
}

static uint16 dviGetSample( const uint16 **pbuf )
{
   if( pcm.data_count == 0 ) {
      uint16 data = **pbuf;
      pcm.data[3] = dviAdpcm_Decode( (uint8)(data & 0xF), &pcm.dvi_state );
      pcm.data[2] = dviAdpcm_Decode( (uint8)((data >> 4) & 0xF), &pcm.dvi_state );
      pcm.data[1] = dviAdpcm_Decode( (uint8)((data >> 8) & 0xF), &pcm.dvi_state );
      pcm.data[0] = dviAdpcm_Decode( (uint8)((data >> 12) & 0xF), &pcm.dvi_state );
      *pbuf = *pbuf + 1;
      pcm.data_count = 4;
   }
   return pcm.data[--pcm.data_count];
}

static bool dviPutSample( uint16 **pbuf, uint16 data )
{
   pcm.data[pcm.data_count++] = data;
   if( pcm.data_count == 4 ) {
      **pbuf = dviAdpcm_Encode( pcm.data[0], &pcm.dvi_state ) |
               (dviAdpcm_Encode( pcm.data[1], &pcm.dvi_state ) << 4) |
               (dviAdpcm_Encode( pcm.data[2], &pcm.dvi_state ) << 8) |
               (dviAdpcm_Encode( pcm.data[3], &pcm.dvi_state ) << 12);
      *pbuf = *pbuf + 1;
      pcm.data_count = 0;
      return true;
   }
   return false;
}

/* ------------------------------------------------------------------------------ */
static void pcmEndHandler(void *data, Media_Event event)
{
   (void) data;      // to avoid warning
#if defined(MT6205B)
   if( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
      AM_PCM16K_PlaybackOff( false );
   else
      AM_PCM8K_PlaybackOff( false );
#else
#if !defined(__BT_AUDIO_VIA_SCO__)
   if (pcm.ctrl->is_8KVoice)
      AM_PCM8K_PlaybackOff( false );
   else
#endif
      AM_AudioPlaybackOff( false );
#endif
   mediaSetEvent( pcm.ctrl->end_status );
}


void pcmPlaybackHisr( void )
{
   if( pcm.ctrl->end_status == MEDIA_TERMINATED )
      return;
   if( pcm.ctrl->end_status == MEDIA_END && *DSP_PCM_CTRL == 8 ) {
      *DSP_PCM_CTRL = 0x10;
      return;
   }
   if( *DSP_PCM_CTRL == 0 ) {           /* DSP returns to idle state */
#if APM_SUPPORT
      APM_NOTIFY_MEDIA_END( pcmEndHandler, NULL, false , MEDIA_END);
#else
      pcmEndHandler(NULL, 0);
#endif
      return;
   }
   if( *DSP_PCM_CTRL == 2 ) {           /* DSP gives IDMA address and length */
      pcm.ctrl->dsp_rb_base = *DSP_PCM_W;
      pcm.ctrl->dsp_rb_size = *DSP_PCM_R;
      pcm.ctrl->dsp_rb_end = pcm.ctrl->dsp_rb_base + pcm.ctrl->dsp_rb_size;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
   }
   pcmWriteToDSP();
   if( *DSP_PCM_CTRL == 2 )
      *DSP_PCM_CTRL = 4;
}

void pcmRecordHisr( void )
{
   if( pcm.ctrl->end_status == MEDIA_TERMINATED )
      return;
   if( *DSP_PCM_REC_CTRL == 0 && pcm.ctrl->format != MEDIA_FORMAT_PCM_16K ) {       /* DSP returns to idle state */
      AM_PCM8K_RecordOff( false );
      mediaSetEvent( pcm.ctrl->end_status );
      return;
   }
   pcmReadFromDSP();
}

/* ------------------------------------------------------------------------------ */
void pcmPlayTurnOnDSP(void)
{
   uint16 I;

   pcm.ctrl->is_8KVoice = false;
#if defined(__BT_SUPPORT__)
#if !defined(__BT_AUDIO_VIA_SCO__)
   if ( (AM_IsBluetoothOn() == true) && (pcm.ctrl->format != MEDIA_FORMAT_PCM_16K) )
      pcm.ctrl->is_8KVoice = true;
#endif
#endif

#if defined(MT6205B)
   pcm.ctrl->mono2stereo = false;
   if( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
      AM_PCM16K_PlaybackOn();
   else
      AM_PCM8K_PlaybackOn();
#else
   *DSP_PCM_MS |= 0x0001;
#if !defined(__BT_AUDIO_VIA_SCO__)
   if (pcm.ctrl->is_8KVoice) {
      pcm.ctrl->mono2stereo = false;
     AM_PCM8K_PlaybackOn();
   } else 
#endif
   {
#if defined( DSP_WT_SYN )
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      pcm.ctrl->mono2stereo = true;
      if( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
         AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ASP_FS_16K );
      else
         AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ASP_FS_8K );
      AFE_SetDigitalGain( L1SP_AUDIO, pcm.ctrl->level );
   }
#endif
   *DSP_PCM_CTRL = 1;
   for( I = 0; ; I++ ) {
      if( *DSP_PCM_CTRL == 8 || pcm.ctrl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 60 ); // YS modified
      kal_sleep_task( 2 );
   }
}

void pcmRecordTurnOnDSP(void)
{
   uint16 I;

#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K ){
      AM_PCM16K_RecordOn();    // no need to control *DP_AWB_SE_CTRL
   }
   else                       //8K PCM
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

void pcmTurnOffDSP(void)
{
   uint16 I, ctl;
   
   if( pcm.isPlayback ) {           /* PCM Playback */
      for( I = 0; ; I++ ) {
         ctl = *DSP_PCM_CTRL;
         if( ctl == 0 )                /* DSP returns to idle state */
            break;
         if( ctl == 8 )
            *DSP_PCM_CTRL = WAV_ABORT_STATE;      /* give ABORT command to the DSP */
         ASSERT_REBOOT( I < 40 );
         kal_sleep_task( 2 );
      }
#if defined(MT6205B)
      if( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
         AM_PCM16K_PlaybackOff( true );
      else
         AM_PCM8K_PlaybackOff( true );
#else    /* MT6218 and later */
#if !defined(__BT_AUDIO_VIA_SCO__)
      if (pcm.ctrl->is_8KVoice)
         AM_PCM8K_PlaybackOff( true );
      else
#endif
         AM_AudioPlaybackOff( true );
#endif
   } else {                              /* PCM Record */
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K ){
         AM_PCM16K_RecordOff ( true );// no need to wait *DP_AWB_SE_CTRL
      } else
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
   }
}

/* ------------------------------------------------------------------------------ */
void pcmPlay( mediaControl *mctrl )
{   
   pcm.ctrl = mctrl;
   pcm.data_count = 0;
   pcm.isPlayback = true;
   
   pcm.dsp_last_sample = 0;
   pcm.decode_EOF = false;
   pcm.zeroCount  = 0;
   
   switch( pcm.ctrl->format ) {
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
         pcm.GetSample = pcmGetSample;
         pcm.data_size = 1;
         break;
      case MEDIA_FORMAT_G711_ALAW:
         pcm.GetSample = alawGetSample;
         pcm.data_size = 2;
         break;
      case MEDIA_FORMAT_G711_ULAW:
         pcm.GetSample = ulawGetSample;
         pcm.data_size = 2;
         break;
      case MEDIA_FORMAT_DVI_ADPCM:
         pcm.GetSample = dviGetSample;
         pcm.data_size = 4;
         dviAdpcm_Init( &pcm.dvi_state );
         break;
   }
   pcm.ctrl->end_status = MEDIA_NONE;
   pcmPlayTurnOnDSP();
}

void pcmRecord( mediaControl *ctrl )
{   
   pcm.ctrl = ctrl;
   pcm.data_count  = 0;
   pcm.isPlayback = false;
   switch( pcm.ctrl->format ) {
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
         pcm.PutSample = pcmPutSample;
         pcm.data_size = 1;
         break;
      case MEDIA_FORMAT_G711_ALAW:
         pcm.PutSample = alawPutSample;
         pcm.data_size = 2;
         break;
      case MEDIA_FORMAT_G711_ULAW:
         pcm.PutSample = ulawPutSample;
         pcm.data_size = 2;
         break;
      case MEDIA_FORMAT_DVI_ADPCM:
         pcm.PutSample = dviPutSample;
         pcm.data_size = 4;
         dviAdpcm_Init( &pcm.dvi_state );
         break;
   }
   ctrl->end_status = MEDIA_NONE;
   pcmRecordTurnOnDSP();
}

void pcmPause( mediaControl *mctrl )
{
   pcm.ctrl->end_status = MEDIA_TERMINATED;
   pcmTurnOffDSP();
}

void pcmResume( mediaControl *ctrl )
{
   if (pcm.isPlayback) {
      pcm.ctrl->end_status = MEDIA_NONE;
      pcmPlayTurnOnDSP();
   } else {
      ctrl->end_status = MEDIA_NONE;
      pcmRecordTurnOnDSP();
   }
}

void pcmStop( void )
{
   pcm.ctrl->end_status = MEDIA_TERMINATED;
   pcmTurnOffDSP();
}

/* ------------------------------------------------------------------------------ */

#endif
