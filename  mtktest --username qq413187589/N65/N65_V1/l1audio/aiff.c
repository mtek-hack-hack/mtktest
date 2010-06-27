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
 *   aiff.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Driver for AIFF/AIFF-C audio format
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "media.h"

#if defined( AIFF_DECODE )

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

#if !defined(MT6205B)

#include "wav.h"
#include "l1audio.h"
#include "afe.h"

static uint32 aiffLookForSSND( void );

// Rey: To reverse byte order to transform between little-endian and big-endian
#define _bytes_reverse_32( _before, _after )  \
{ _after =  ( _before << 24 ) | ( _before & 0x0000FF00 ) << 8 | ( _before & 0x00FF0000 ) >> 8 | ( _before >> 24 ); }

#define _bytes_reverse_16( _before, _after )  \
{ _after = ( _before << 8 ) | ( _before >> 8 ); }

// Shift the read pointer of media buffer by 1
#define _ShiftMBReadPtr()  \
{  \
   read_cache++;  \
   if (read_cache == rb_size_cache) {  \
      read_cache = 0;  \
      prb = aiff.ctrl->rb_base;  \
   }  \
}

#define IS_AIFF   0
#define IS_AIFF_C 1

// Rey: These are the states of aiff, the possible transitions are as follows:
#define AIFF_STATE_IDLE         0     // 1
#define AIFF_STATE_PLAYING      1     // 2,0
#define AIFF_STATE_PLAY_PAUSED  2     // 1,0

extern void PutSilence(mediaControl *mctrl, int32 dsp_len);

static struct {
   mediaControl *ctrl;
   uint8  aiff_type;          // the type of aiff file, either IS_AIFF or IS_AIFF_C
   uint8  fs_code;            // sample rate code
   uint8  state;              // the state of aiff
   uint16 data_size;          // data size of a sample, in byte
   int32  mb_count;           // media buffer count in word, will be updated in hisr
   uint32 ssnd_offset;        // offset in ssnd chunk
   uint32 word_left_in_form;  // data count left in the form chunk, in word
   uint32 word_left_in_ck;    // data count left in the current chunk, in word
   uint32 ssnd_state;         // 0: not found yet
                              // 1: ssnd is found but the actual sound data is not found
                              // 2: sound data is found
   void   (*AIFF_PutData)(int32 dsp_len);   // the PutData function ptr
} aiff;

static void upd_dsp_len( int32 *dsp_len )
{
   int32 len;

   if (aiff.ctrl->mono2stereo)
      len = ( aiff.mb_count << 2 ) / aiff.data_size;
   else
      len = ( aiff.mb_count << 1 ) / aiff.data_size;

   if( *dsp_len > len)
      *dsp_len = len;
      
   // The current chunk should be SSND chunk
   if (aiff.ctrl->mono2stereo)
      len = ( aiff.word_left_in_ck << 2 ) / aiff.data_size;
   else
      len = ( aiff.word_left_in_ck << 1 ) / aiff.data_size;

   if( *dsp_len > len)
      *dsp_len = len;
}

static void upd_dsp_w( int32 dsp_len, uint16 dsp_w )
{
   uint32 I = dsp_len * aiff.data_size;

   if (aiff.ctrl->mono2stereo)
      I = (I >> 1);

   aiff.mb_count -= I >> 1;
   // The current chunk should be SSND chunk
   aiff.word_left_in_ck -= I >> 1;
   aiff.word_left_in_form -= I >> 1;
   dsp_w += dsp_len;
   ASSERT( dsp_w <= aiff.ctrl->dsp_rb_size );
   if( dsp_w == aiff.ctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;
}

static void aiffLPCM16PutData( int32 dsp_len )
{
   int32 I;
   uint32 read_cache, rb_size_cache;
   uint16 *prb;
   uint16 dsp_w = *DSP_PCM_W;

   upd_dsp_len( &dsp_len );
   if (aiff.ctrl->mono2stereo)
   	  dsp_len &= 0xFFFFFFFE;
   if( dsp_len <= 0 )
      return;

   read_cache = aiff.ctrl->read;
   rb_size_cache = aiff.ctrl->rb_size;
   prb = &aiff.ctrl->rb_base[read_cache];
   if (aiff.ctrl->mono2stereo) {
   	  uint16 read_data, dsp_last_sample;

      read_data = *prb++;
      dsp_last_sample = (read_data >> 8) + (read_data << 8);
      *DSP_DM_ADDR(PAGE_NUM, aiff.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
      *IDMA_SHORT_ADDR = dsp_last_sample;
      _ShiftMBReadPtr();
      for( I = dsp_len-2; I > 0; I-=2 )
      {
         read_data = *prb++;
         dsp_last_sample = (read_data >> 8) + (read_data << 8);
         *IDMA_SHORT_ADDR = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         _ShiftMBReadPtr();
      }
      aiff.ctrl->dsp_last_sample = dsp_last_sample;
   } else { 
   	  uint16 read_data;

      read_data = *prb++;
      *DSP_DM_ADDR(PAGE_NUM, aiff.ctrl->dsp_rb_base + dsp_w) = (read_data >> 8) + (read_data << 8);
      _ShiftMBReadPtr();
      for( I = dsp_len-1; I > 0; I-- )
      {
         read_data = *prb++;
         *IDMA_SHORT_ADDR = (read_data >> 8) + (read_data << 8);
         _ShiftMBReadPtr();
      }
      aiff.ctrl->dsp_last_sample = (read_data >> 8) + (read_data << 8);
   }
   aiff.ctrl->read = read_cache;   // Update the read pointer
   
   upd_dsp_w( dsp_len, dsp_w );
}

static void aiff8BitDecode( int32 dsp_len, const uint16* Table )
{
   int32 I;
   uint32 read_cache, rb_size_cache;
   uint16 *prb;
   uint16 dsp_w = *DSP_PCM_W;
   
   upd_dsp_len( &dsp_len );
   if (aiff.ctrl->mono2stereo)
      dsp_len &= 0xFFFFFFFC;  // Force dsp_len to be even to avoid the alignment problem.
   else
      dsp_len &= 0xFFFFFFFE;  // Force dsp_len to be even to avoid the alignment problem.
   if( dsp_len <= 0 )
      return;

   read_cache = aiff.ctrl->read;
   rb_size_cache = aiff.ctrl->rb_size;
   prb = &aiff.ctrl->rb_base[read_cache];
   if (aiff.ctrl->mono2stereo) {
      uint16 read_data, dsp_last_sample;

      read_data = *prb++;
      dsp_last_sample = (Table ? Table[read_data & 0x00FF] : read_data << 8);
      *DSP_DM_ADDR( PAGE_NUM, aiff.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
      *IDMA_SHORT_ADDR = dsp_last_sample;
      dsp_last_sample = (Table ? Table[read_data >> 8] : read_data & 0xFF00);
      *IDMA_SHORT_ADDR = dsp_last_sample;
      *IDMA_SHORT_ADDR = dsp_last_sample;
      _ShiftMBReadPtr();
      for( I=dsp_len-4; I > 0; I-=4 )
      {
         read_data = *prb++;
         dsp_last_sample = (Table ? Table[read_data & 0x00FF] : read_data << 8);
         *IDMA_SHORT_ADDR = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         dsp_last_sample = (Table ? Table[read_data >> 8] : read_data & 0xFF00);
         *IDMA_SHORT_ADDR = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         _ShiftMBReadPtr();
      }
      aiff.ctrl->dsp_last_sample = dsp_last_sample;
   } else {
      uint16 read_data;

      read_data = *prb++;
      *DSP_DM_ADDR( PAGE_NUM, aiff.ctrl->dsp_rb_base + dsp_w) = (Table ? Table[read_data & 0x00FF] : read_data << 8);
      *IDMA_SHORT_ADDR = (Table ? Table[read_data >> 8] : read_data & 0xFF00);
      _ShiftMBReadPtr();
      for( I=dsp_len-2; I > 0; I-=2 )
      {
         read_data = *prb++;
         *IDMA_SHORT_ADDR = (Table ? Table[read_data & 0x00FF] : read_data << 8);
         *IDMA_SHORT_ADDR = (Table ? Table[read_data >> 8] : read_data & 0xFF00);
         _ShiftMBReadPtr();
      }
      aiff.ctrl->dsp_last_sample = (Table ? Table[read_data >> 8] : read_data & 0xFF00);
   }
   aiff.ctrl->read = read_cache;
   
   upd_dsp_w( dsp_len, dsp_w );
}     
      
static void aiffLPCM8PutData( int32 dsp_len )
{     
   aiff8BitDecode( dsp_len, NULL );
}

static void aiffAlawPutData( int32 dsp_len ) // A-law decoder
{
   aiff8BitDecode( dsp_len, Alaw_Tab );
}

static void aiffUlawPutData( int32 dsp_len ) // U-law decoder
{
   aiff8BitDecode( dsp_len, Ulaw_Tab );
}

static bool aiffReadHeader( void )
{
   uint16 data_16_a, data_16_b;
   uint32 data_32;

   // file magic, 0x4d524f46 for ASCII "MROF"
   if( rb_GetDWord( &data_32 ) == false || data_32 != 0x4d524f46 )
      return false;

   // chunk size
   if( rb_GetDWord( &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, aiff.word_left_in_form );
   aiff.word_left_in_form = ( aiff.word_left_in_form + 1 ) >> 1;
   
   // aiff type
   if( rb_GetDWord( &data_32 ) == false )
      return false;

   if( data_32 == 0x46464941 )   // 0x46464941 for ASCII "FFIA"
      aiff.aiff_type = IS_AIFF;
   else if( data_32 == 0x43464941 ) // 0x46464941 for ASCII "CFIA"
      aiff.aiff_type = IS_AIFF_C;
   else
      return false;
   aiff.word_left_in_form -= 2;

   // Look for the COMM chunk
   while( 1 )
   {
      if( rb_GetDWord( &data_32 ) == false || data_32 == 0x444e5353 )
         return false;  // Counld not find the COMM chunk or the SSND chunk is before COMM chunk, error!
      aiff.word_left_in_form -= 2;
      if( data_32 == 0x4d4d4f43 )
         break;
      
      if( rb_GetDWord( &data_32 ) == false )
         return false;
      _bytes_reverse_32( data_32, aiff.word_left_in_ck );
      aiff.word_left_in_ck = ( aiff.word_left_in_ck + 1 ) >> 1;
      
      if( rb_SkipNWord( aiff.word_left_in_ck ) != aiff.word_left_in_ck )
         return false;
      aiff.word_left_in_form -= (aiff.word_left_in_ck + 2);
   }
   if( rb_GetDWord( &data_32 ) == false )
      return false;
   aiff.word_left_in_form -= 2;
   _bytes_reverse_32( data_32, aiff.word_left_in_ck );
   if( aiff.aiff_type == IS_AIFF && aiff.word_left_in_ck != 18 )
      return false;   // The file is AIFF and ckSize of COMM chunk is not equal to 18, error!
   aiff.word_left_in_ck = ( aiff.word_left_in_ck + 1 ) >> 1;
   
   // Check channel count
   if( rb_GetWord( &data_16_a ) == false )
      return false;
   if( data_16_a == 0x0100 ) {
      aiff.ctrl->is_stereo = false;
      aiff.ctrl->mono2stereo = true;
      *DSP_PCM_MS |= 0x0001;
   } else if( data_16_a == 0x0200 ) {
      aiff.ctrl->is_stereo = true;
      aiff.ctrl->mono2stereo = false;
      *DSP_PCM_MS |= 0x0001;
   } else
      return false;

   // numSampleFrames
   if( rb_SkipNWord( 2 ) == false )
      return false;

   if( rb_GetWord( &data_16_a ) == false )
      return false;
   _bytes_reverse_16( data_16_a, aiff.data_size );
   aiff.data_size >>= 3;
   if( aiff.data_size != 1 && aiff.data_size != 2 )
      return false;   // Support only 8/16 bit data

   if( rb_GetWord( &data_16_a ) == false )
      return false;
   if( rb_GetWord( &data_16_b ) == false )
      return false;
   _bytes_reverse_16( data_16_a, data_16_a );
   _bytes_reverse_16( data_16_b, data_16_b );
   data_16_a -= 16383;
   data_16_b >>= ( 15 - data_16_a );
   switch( data_16_b / 1000 ){
      case 7: case 8:   aiff.fs_code = 0x00;
         break;
      case 10: case 11: aiff.fs_code = 0x11;
         break;
      case 12:          aiff.fs_code = 0x12;
         break;
      case 15: case 16: aiff.fs_code = 0x20;
         break;
      case 21: case 22: aiff.fs_code = 0x21;
         break;
      case 23: case 24: aiff.fs_code = 0x22;
         break;
      case 31: case 32: aiff.fs_code = 0x40;
         break;
      case 43: case 44: aiff.fs_code = 0x41;
         break;
      case 47: case 48: aiff.fs_code = 0x42;
         break;
      default:
         return 0;   // The sample rate is not supported by ASP.
   }
   if( rb_SkipNWord( 3 ) != 3 )
      return false;
   aiff.word_left_in_form -= 9;
   aiff.word_left_in_ck -= 9;
   if( aiff.aiff_type == IS_AIFF)
   {
      if( aiff.data_size == 1 )
         aiff.AIFF_PutData = aiffLPCM8PutData;
      else
         aiff.AIFF_PutData = aiffLPCM16PutData;
   }
   else
   {
      if( rb_GetDWord( &data_32 ) == false )
         return false;
      _bytes_reverse_32( data_32, data_32 );
      switch( data_32 )
      {
         case 0x4e4f4e45:  // "NONE"
            if( aiff.data_size == 1 )
               aiff.AIFF_PutData = aiffLPCM8PutData;
            else
               aiff.AIFF_PutData = aiffLPCM16PutData;
            break;

         case 0x756c6177:  // "ulaw"
         case 0x554c4157:  // "ULAW"
            aiff.AIFF_PutData = aiffUlawPutData;
            aiff.data_size = 1;
            break;
         case 0x616c6177:  // "alaw"
         case 0x414c4157:  // "ALAW"
            aiff.AIFF_PutData = aiffAlawPutData;
            aiff.data_size = 1;
            break;
         default:
            return false;
      }
      aiff.word_left_in_form -= 2;
      aiff.word_left_in_ck -= 2;
   }
   aiff.ssnd_state = 0;
   return true;
}

static void aiffInternalPlay( void )
{
   uint8 I;
   aiff.state = AIFF_STATE_PLAYING;
   aiff.ctrl->end_status = MEDIA_NONE;

//   if (aiff.ctrl->is_8KVoice) {
//      AM_PCM8K_PlaybackOn();
//   } else {
#if defined( DSP_WT_SYN )
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, aiff.fs_code );
      AFE_SetDigitalGain( L1SP_AUDIO, aiff.ctrl->level);
//   }
   *DSP_PCM_CTRL = 1;
   for( I = 0; ; I++ )
   {
      if( *DSP_PCM_CTRL == 8 || aiff.ctrl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 60 ); // YS modified
      kal_sleep_task( 2 );
   }
}

Media_Status aiffPlay( mediaControl *mctrl )
{
   aiff.ctrl = mctrl;
   if( !aiffReadHeader() )
      return MEDIA_BAD_FORMAT;

   aiff.ctrl->is_8KVoice = false;
//#if defined(__BT_SUPPORT__)
//   if ( (AM_IsBluetoothOn() == true) && (aiff.fs_code == 0x00) && (aiff.ctrl->is_stereo == false) ) {
//      aiff.ctrl->is_8KVoice = true;
//      aiff.ctrl->mono2stereo = false;
//   }
//#endif

   aiffInternalPlay();
   return MEDIA_SUCCESS;
}

static void aiffWriteToDSP( void )
{
   int32 rb_r, rb_w, tmp1, rb_r_cache;

   rb_w = (int32)*DSP_PCM_W;
   do {
      rb_r = (int16)*DSP_PCM_R;
   } while (rb_r != (int16)*DSP_PCM_R);
   rb_r_cache = rb_r;

   rb_r = rb_r - rb_w -1;
   if( rb_r < 0 )
      rb_r += (int32)aiff.ctrl->dsp_rb_size; // free size of DSP buf
   rb_r &= 0xFFFFFFFC;     // force the number of audio samples filled to be even

   tmp1 = (int32)aiff.ctrl->dsp_rb_size - rb_w;
   
   if( aiff.mb_count > 0 )
   {
      if( tmp1 < rb_r )
      {
         aiff.AIFF_PutData( tmp1 );
         aiff.mb_count = mediaGetDataCount();
         rb_r -= tmp1;
      }
      aiff.AIFF_PutData( rb_r );
   }

   // fill silence
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if ( rb_r_cache < 0 )
      rb_r_cache += (int16)aiff.ctrl->dsp_rb_size; /* free size of DSP buf */
   rb_r_cache &= 0xFFFFFFFC;     // force the length of silence filled to be even

   tmp1 = (int16)aiff.ctrl->dsp_rb_size - rb_w;
   if( rb_r_cache > tmp1 )
   {
      PutSilence(aiff.ctrl, tmp1);
      rb_r_cache -= tmp1;
   }
   PutSilence(aiff.ctrl, rb_r_cache);
}

static void aiffEndHandler(void *data, Media_Event event)
{
   (void) data;      // to avoid warning
   aiff.state = AIFF_STATE_IDLE;
//   if (aiff.ctrl->is_8KVoice)
//      AM_PCM8K_PlaybackOff( false );
//   else
        AM_AudioPlaybackOff( false );
   mediaSetEvent( MEDIA_END );
}

void aiffPlaybackHisr( void )
{
   if( aiff.state != AIFF_STATE_PLAYING )
      return;
   
   if( aiff.ctrl->end_status == MEDIA_TERMINATED )
      return;
   
   aiff.mb_count = mediaGetDataCount();
   if( (((aiff.mb_count << 1) < aiff.data_size && aiff.ctrl->eof)
   || (aiff.word_left_in_form == 0)
   || (aiff.ssnd_state == 0 && aiff.mb_count < 8 && aiff.ctrl->eof )
   || (aiff.ssnd_state != 0 && aiff.word_left_in_ck == 0))
   && *DSP_PCM_CTRL == 0x08)
   {
      aiff.ctrl->end_status = MEDIA_END;
      *DSP_PCM_CTRL = 0x10;
      aiff.ctrl->eof = true;
      return;
   }
   
   if( *DSP_PCM_CTRL == 0 )
   {  // DSP returns to idle state
#if APM_SUPPORT
      APM_NOTIFY_MEDIA_END( aiffEndHandler, NULL, false , MEDIA_END);
#else
      aiffEndHandler(NULL, 0);
#endif
      return;
   }

   if( *DSP_PCM_CTRL == 2 ) {   // DSP gives IDMA address and length
      aiff.ctrl->dsp_rb_base = *DSP_PCM_W;
      aiff.ctrl->dsp_rb_size = *DSP_PCM_R;
      aiff.ctrl->dsp_rb_end = aiff.ctrl->dsp_rb_base + aiff.ctrl->dsp_rb_size;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
      PutSilence( aiff.ctrl, aiff.ctrl->dsp_rb_size );  // full dsp ring buffer with silence pattern
      *DSP_PCM_CTRL = 4;
   }

   // If the SSND chunk is not found yet, look for it
   if( aiff.ssnd_state != 2  )
      aiff.ssnd_state = aiffLookForSSND();
   else
      aiffWriteToDSP();
}

// Look for SSND chunk
// Bedofe calling this function, aiff.mb_count should be assigned correct value.
// Return value:
//    0: ssnd not found yet
//    1: ssnd found but the actual sound data is not found yet
//    2: sound data is found
static uint32 aiffLookForSSND()
{
   uint32 data_32;
   if( aiff.ssnd_state == 0 )
   {
      while( 1 )
      {
         if( aiff.word_left_in_ck )
         {
            data_32 = rb_SkipNWord( aiff.word_left_in_ck );
            aiff.word_left_in_ck -= data_32;
            aiff.word_left_in_form -= data_32;
            if( aiff.word_left_in_ck )
               return 0;
         }
         if( rb_GetByteCount() < 16 )
            return 0;
         rb_GetDWord( &data_32 );   // Get chunk id
         aiff.word_left_in_form -= 2;
         if( data_32 == 0x444e5353 )
            break;
         rb_GetDWord( &data_32 );    // Get chunk size
         aiff.word_left_in_form -= 2;
         _bytes_reverse_32( data_32, aiff.word_left_in_ck )
         aiff.word_left_in_ck = ( aiff.word_left_in_ck + 1 ) >> 1;
      }
      
      // the ssnd is found
      rb_GetDWord( &data_32 ); // chunk size
      _bytes_reverse_32( data_32, aiff.word_left_in_ck );
      aiff.word_left_in_ck = ( aiff.word_left_in_ck + 1 ) >> 1;
      rb_GetDWord( &data_32 ); // SSND offset
      _bytes_reverse_32( data_32, aiff.ssnd_offset );
      rb_SkipNWord(2);  // blockSize
      aiff.word_left_in_ck -= 4;
      aiff.word_left_in_form -= 6;
      if( aiff.ssnd_offset == 0 )
      {
         aiff.ctrl->isDataConsumed = true;
         return 2;
      }
      else if( aiff.ssnd_offset & 0x01 )
         return 0;   // We don't support odd offset.
      else
      {
         aiff.ssnd_offset >>= 1;
         return 1;
      }
   }
   else
   {
      if( aiff.ssnd_offset )
      {
         data_32 = rb_SkipNWord( aiff.ssnd_offset );
         aiff.ssnd_offset -= data_32;
         aiff.word_left_in_ck -= data_32;
      }
      if( aiff.ssnd_offset )
         return 1;
      else{
         aiff.ctrl->isDataConsumed = true;
         return 2;
      }
   }
}

void aiffStop( void )
{
   uint16 I, ctl;
   aiff.ctrl->end_status = MEDIA_TERMINATED;

   switch( aiff.state ) {
      case AIFF_STATE_IDLE:
         return;
      case AIFF_STATE_PLAYING:
      case AIFF_STATE_PLAY_PAUSED:
         for( I = 0; ; I++ ) {
            ctl = *DSP_PCM_CTRL;
            if( ctl == 0x00 )    // DSP returns to idle state
               break;
            if( ctl == 0x08 )
               *DSP_PCM_CTRL = WAV_ABORT_STATE;      // give ABORT command to the DSP
            ASSERT_REBOOT( I < 40 );
            kal_sleep_task( 2 );
         }
//         if (aiff.ctrl->is_8KVoice)
//            AM_PCM8K_PlaybackOff( true );
//         else
            AM_AudioPlaybackOff( true );
         break;
      default:
         ASSERT(KAL_FALSE);
   }
   aiff.state = AIFF_STATE_IDLE;
// mediaHandler( (void*)MEDIA_TERMINATED );
}

void aiffPause( mediaControl *mctrl )
{
   uint16 I, ctl;
   aiff.ctrl->end_status = MEDIA_TERMINATED;

   for( I = 0; ; I++ ) {
      ctl = *DSP_PCM_CTRL;
      if( ctl == 0x00 )    // DSP returns to idle state
         break;
      if( ctl == 0x08 )
         *DSP_PCM_CTRL = WAV_ABORT_STATE;   // give ABORT command to the DSP
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
//   if (aiff.ctrl->is_8KVoice)
//      AM_PCM8K_PlaybackOff( true );
//   else
      AM_AudioPlaybackOff( true );
   aiff.state = AIFF_STATE_PLAY_PAUSED;
}

void aiffResume( mediaControl *mctrl )
{
   if( aiff.state == AIFF_STATE_PLAY_PAUSED ) {
      aiff.ctrl->is_8KVoice = false;
      if (aiff.ctrl->is_stereo == false)
         aiff.ctrl->mono2stereo = true;
      else
         aiff.ctrl->mono2stereo = false;
//#if defined(__BT_SUPPORT__)
//      if ( (AM_IsBluetoothOn() == true) && (aiff.fs_code == 0x00) && (aiff.ctrl->is_stereo == false) ) {
//         aiff.ctrl->is_8KVoice = true;
//         aiff.ctrl->mono2stereo = false;
//      }
//#endif
      aiffInternalPlay();
   } else {
      kal_prompt_trace( MOD_L1SPHISR, "aiffResume Wrong State");
   }
}

void aiffUpdateLevel( void )
{
   AFE_SetDigitalGain( L1SP_AUDIO, aiff.ctrl->level);
}

#endif   // !defined(MT6205B)
#endif   // defined( AIFF_DECODE )
