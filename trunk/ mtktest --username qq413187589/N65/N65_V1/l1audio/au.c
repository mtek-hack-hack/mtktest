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
 * au.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Driver for NeXT/Sun audio format
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"

#if defined( AU_DECODE )

#if defined(MT6205B) || defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225)
#define PAGE_NUM 0
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 2
#elif defined(MT6223) || defined(MT6223P)
#define PAGE_NUM 1
#else
#error The new chip should define DM page number
#endif

#if defined(MT6225) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T)  || defined(MT6235) || defined(MT6238)
#define WAV_ABORT_STATE 0x40
#else
#define WAV_ABORT_STATE 0x10
#endif

#if  !defined(MT6205B)

#include "wav.h"
#include "l1audio.h"
#include "afe.h"

// Rey: These are the states of au, the possible transitions are as follows:
#define AU_STATE_IDLE            0     // 1
#define AU_STATE_PLAYING         1     // 2,0
#define AU_STATE_PLAY_PAUSED     2     // 1,0

extern void PutSilence(mediaControl *mctrl, int32 dsp_len);

static struct {
   mediaControl *ctrl;
   uint8  fs_code;         // sample rate code
   uint8  data_size;       // the size of data, in byte
   uint8  state;           // the state of au
   bool   odd_start;       // to specify if the data started from odd offset
   uint16 previous_byte;   // if odd started, the high byte of this word contains the previous byte
   int32  mb_count;        // media buffer count in word, will be updated in hisr
   uint32 data_offset;     // data offset in byte, found in AU file header
   uint32 data_length;     // length of sound data in byte, found in AU file header
   uint32 data_read;       // total data read so far, in byte
   void   (*Au_PutData)(int32 dsp_len);   // the PutData function ptr
} au;

// Rey: To reverse byte order to transform between little-endian and big-endian
#define _bytes_reverse_32( _before, _after )  \
{ _after =  ( _before << 24 ) | ( _before & 0x0000FF00 ) << 8 | ( _before & 0x00FF0000 ) >> 8 | ( _before >> 24 ); }

// Shift the read pointer of media buffer by 1
// And update the ring buffer pointer if needed
#define _ShiftMBReadPtr()  \
{  \
   read_cache++;  \
   if (read_cache == rb_size_cache) {  \
      read_cache = 0;  \
      prb = au.ctrl->rb_base;  \
   }  \
}

static void upd_dsp_len( int32 *dsp_len )
{
   int32 len = ( au.mb_count << 1 ) / au.data_size;
   
   if (au.ctrl->mono2stereo)
      len = (len << 1);
   if( *dsp_len > len)
      *dsp_len = len;
      
   len = ( au.data_offset + au.data_length - au.data_read ) / au.data_size;
   if (au.ctrl->mono2stereo)
      len = (len << 1);
   if( *dsp_len > len)
      *dsp_len = len;
}

static void upd_dsp_w( int32 dsp_len, uint16 dsp_w )
{
   uint32 I = dsp_len * au.data_size;

   if (au.ctrl->mono2stereo)
      I = (I >> 1);

   au.mb_count -= I >> 1;
   au.data_read += I;
   dsp_w += dsp_len;
   ASSERT( dsp_w <= au.ctrl->dsp_rb_size );
   if( dsp_w == au.ctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;
}

static void auLPCM16PutData( int32 dsp_len )
{
   int32 I;
   uint16 dsp_w = *DSP_PCM_W;
   uint32 read_cache, rb_size_cache;
   uint16 *prb;

   upd_dsp_len( &dsp_len );
   if (au.ctrl->mono2stereo)
      dsp_len &= 0xFFFFFFFE;
   if( dsp_len <= 0 )
      return;

   read_cache = au.ctrl->read;
   rb_size_cache = au.ctrl->rb_size;
   prb = &au.ctrl->rb_base[read_cache];
   if( au.odd_start ) {
      if (au.ctrl->mono2stereo) {
         uint16 read_data, previous_byte, dsp_last_sample;
      
         read_data = *prb++;
         dsp_last_sample = au.previous_byte + (read_data & 0x00FF);
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         previous_byte = read_data & 0xFF00;
         _ShiftMBReadPtr();
         for( I = dsp_len-2; I > 0; I-=2 ) {
       	    read_data = *prb++;
            dsp_last_sample = previous_byte + (read_data & 0x00FF);
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            previous_byte = read_data & 0xFF00;
            _ShiftMBReadPtr();
         }
         au.previous_byte = previous_byte;
         au.ctrl->dsp_last_sample = dsp_last_sample;
      } else {
         uint16 read_data, previous_byte, dsp_last_sample;
      
         read_data = *prb++;
         dsp_last_sample = au.previous_byte + (read_data & 0x00FF);
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
         previous_byte = read_data & 0xFF00;
         _ShiftMBReadPtr();
         for( I = dsp_len-1; I > 0; I-- ) {
            read_data = *prb++;
            dsp_last_sample = previous_byte + (read_data & 0x00FF);
            *IDMA_SHORT_ADDR = dsp_last_sample;
            previous_byte = read_data & 0xFF00;
            _ShiftMBReadPtr();
         }
         au.previous_byte = previous_byte;
         au.ctrl->dsp_last_sample = dsp_last_sample;
      }
   } else {
      if (au.ctrl->mono2stereo) {
         uint16 read_data, dsp_last_sample;
      
         read_data = *prb++;
         dsp_last_sample = (read_data >> 8) + (read_data << 8);
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         _ShiftMBReadPtr();
         for( I = dsp_len-2; I > 0; I-=2 ) {
            read_data = *prb++;
            dsp_last_sample = (read_data >> 8) + (read_data << 8);
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            _ShiftMBReadPtr();
         }
         au.ctrl->dsp_last_sample = dsp_last_sample;
      } else {
         uint16 read_data;
      
         read_data = *prb++;
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = (read_data >> 8) + (read_data << 8);
         _ShiftMBReadPtr();
         for( I = dsp_len-1; I > 0; I-- ) {
            read_data = *prb++;
            *IDMA_SHORT_ADDR = (read_data >> 8) + (read_data << 8);
            _ShiftMBReadPtr();
         }
         au.ctrl->dsp_last_sample = (read_data >> 8) + (read_data << 8);
      }
   }
   au.ctrl->read = read_cache;
   upd_dsp_w( dsp_len, dsp_w );
}

static void au8BitDecode( int32 dsp_len, const uint16* Table )
{
   int32 I;
   uint16 dsp_w = *DSP_PCM_W;
   uint32 read_cache, rb_size_cache;
   uint16 *prb;
   
   upd_dsp_len( &dsp_len );
   if (au.ctrl->mono2stereo)
      dsp_len &= 0xFFFFFFFC;  // Force dsp_len to be even to avoid the alignment problem.
   else
      dsp_len &= 0xFFFFFFFE;  // Force dsp_len to be even to avoid the alignment problem.
   if( dsp_len <= 0 )
      return;
   
   read_cache = au.ctrl->read;
   rb_size_cache = au.ctrl->rb_size;
   prb = &au.ctrl->rb_base[read_cache];
   if (au.odd_start)
   {
      if (au.ctrl->mono2stereo) {
         uint16 read_data, dsp_last_sample;

         dsp_len -= 2;
         read_data = au.previous_byte;
         dsp_last_sample = (Table?Table[read_data >> 8]:read_data);
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         for( I = dsp_len-2; I > 0; I-=4 )
         {
            read_data = *prb++;
            dsp_last_sample = (Table?Table[read_data & 0x00FF] : read_data << 8);
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            dsp_last_sample = (Table?Table[read_data >> 8] : read_data & 0xFF00);
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            _ShiftMBReadPtr();
         }
         read_data = *prb++;
         dsp_last_sample = (Table?Table[read_data & 0x00FF] : read_data << 8);
         *IDMA_SHORT_ADDR = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         au.ctrl->dsp_last_sample = dsp_last_sample; 
         au.previous_byte = read_data & 0xFF00;
         _ShiftMBReadPtr();
         dsp_len += 2;
      } else {
         uint16 read_data, dsp_last_sample;

         dsp_len--;
         read_data = au.previous_byte;
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = (Table?Table[read_data>>8]:read_data);
         for( I = dsp_len-1; I > 0; I-=2 )
         {
            read_data = *prb++;
            *IDMA_SHORT_ADDR = (Table?Table[read_data & 0x00FF] : read_data << 8);
            *IDMA_SHORT_ADDR = (Table?Table[read_data >> 8] : read_data & 0xFF00);
            _ShiftMBReadPtr();
         }
         read_data = *prb++;
         dsp_last_sample = (Table?Table[read_data & 0x00FF] :  read_data << 8);
         *IDMA_SHORT_ADDR = dsp_last_sample;
         au.ctrl->dsp_last_sample = dsp_last_sample;
         au.previous_byte =  read_data & 0xFF00;
         _ShiftMBReadPtr();
         dsp_len++;
      }
   } else {
      if (au.ctrl->mono2stereo) {
         uint16 read_data, dsp_last_sample;

         read_data = *prb++;
         dsp_last_sample = (Table?Table[read_data & 0x00FF] : read_data << 8);
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         dsp_last_sample = (Table?Table[read_data >> 8] : read_data & 0xFF00);
         *IDMA_SHORT_ADDR = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         _ShiftMBReadPtr();
         for( I = 4; I < dsp_len; I += 4 )
         {
            read_data = *prb++;
            dsp_last_sample = (Table?Table[read_data & 0x00FF] : read_data << 8);
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            dsp_last_sample = (Table?Table[read_data >> 8] : read_data & 0xFF00);
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            _ShiftMBReadPtr();
         }
         au.ctrl->dsp_last_sample = dsp_last_sample;
      } else {
         uint16 read_data;

         read_data = *prb++;
         *DSP_DM_ADDR(PAGE_NUM, au.ctrl->dsp_rb_base + dsp_w) = (Table?Table[read_data & 0x00FF] : read_data << 8);
         *IDMA_SHORT_ADDR = (Table?Table[read_data >> 8] : read_data & 0xFF00);
         _ShiftMBReadPtr();
         for( I = 2; I < dsp_len; I += 2 )
         {
            read_data = *prb++;
            *IDMA_SHORT_ADDR = (Table?Table[read_data & 0x00FF] : read_data << 8);
            *IDMA_SHORT_ADDR = (Table?Table[read_data >> 8] : read_data & 0xFF00);
            _ShiftMBReadPtr();
         }
         au.ctrl->dsp_last_sample = (Table?Table[read_data >> 8] : read_data & 0xFF00);
      }
   }
   au.ctrl->read = read_cache; // Update the last sample

   upd_dsp_w( dsp_len, dsp_w );
}

static void auLPCM8PutData( int32 dsp_len )
{
   au8BitDecode( dsp_len, NULL );
}

static void auAlawPutData( int32 dsp_len ) /* A-law decoder */
{
   au8BitDecode( dsp_len, Alaw_Tab );
}

static void auUlawPutData( int32 dsp_len ) /* U-law decoder */
{
   au8BitDecode( dsp_len, Ulaw_Tab );
}

static bool auReadHeader( void )
{
   uint32 data_32;
   
   // file magic, 0x646e732e for ASCII "dns."
   if( rb_GetDWord( &data_32 ) == false || data_32 != 0x646e732e )
      return false;
   
   // data offset
   if( rb_GetDWord( &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, au.data_offset );
   
   // data length
   if( rb_GetDWord( &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, au.data_length );
   
   // format id
   if( rb_GetDWord( &data_32 ) == false )
      return false;
   au.data_size = 1;
   switch( data_32 )
   {
      case 0x01000000:
         au.Au_PutData = auUlawPutData;         
         break;
      case 0x1b000000:
         au.Au_PutData = auAlawPutData;
         break;
      case 0x02000000:
         au.Au_PutData = auLPCM8PutData;
         break;
      case 0x03000000:
         au.Au_PutData = auLPCM16PutData;
         au.data_size = 2;
         break;
      default:
         return false;
   }

   // sample rate
   if( rb_GetDWord( &data_32 ) == false )
      return false;
   _bytes_reverse_32( data_32, data_32 );
   switch( data_32/1000 ) {
      case 7: case 8:   au.fs_code = 0x00;
         break;
      case 10: case 11: au.fs_code = 0x11;
         break;
      case 12:          au.fs_code = 0x12;
         break;
      case 15: case 16: au.fs_code = 0x20;
         break;
      case 21: case 22: au.fs_code = 0x21;
         break;
      case 23: case 24: au.fs_code = 0x22;
         break;
      case 31: case 32: au.fs_code = 0x40;
         break;
      case 43: case 44: au.fs_code = 0x41;
         break;
      case 47: case 48: au.fs_code = 0x42;
         break;
      default:
         return false;   // The sample rate is not supported by ASP.
   }
   // channel count
   if( rb_GetDWord( &data_32 ) == false )
      return false;

   if( data_32 == 0x01000000 ) {
      *DSP_PCM_MS |= 0x0001;
      au.ctrl->is_stereo = false;
      au.ctrl->mono2stereo = true;
   } else if( data_32 == 0x02000000 ) {
      *DSP_PCM_MS |= 0x0001;
      au.ctrl->is_stereo = true;
      au.ctrl->mono2stereo = false;
   } else
      return false;

   if( au.data_offset & 0x01 )
      au.odd_start = 1;
   else
      au.odd_start = 0;
   
   if( au.data_offset < 24 )
      return false;
   if( ( au.data_offset >> 1 ) < (uint32)mediaGetDataCount() )
   {
      au.ctrl->read = ( au.data_offset >> 1 );
      au.data_read = au.data_offset; 
      if( au.odd_start )
      {
         au.previous_byte = au.ctrl->rb_base[au.ctrl->read] & 0xFF00;
         au.ctrl->read++;
      }
      au.ctrl->isDataConsumed = true;
   }
   else
   {
      au.data_read = ((au.ctrl->write-au.ctrl->read) << 1 );
      au.ctrl->read = 0;
      au.ctrl->write = 0;
   }
   return true;
}

static void auInternalPlay( void )
{
   uint8 I;
   au.ctrl->end_status = MEDIA_NONE;
   au.state = AU_STATE_PLAYING;
   
//   if (au.ctrl->is_8KVoice) {
//      AM_PCM8K_PlaybackOn();
//   } else {
#if defined( DSP_WT_SYN )
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, au.fs_code );
      AFE_SetDigitalGain(L1SP_AUDIO, au.ctrl->level);
//   }
   *DSP_PCM_CTRL = 1;
   for( I = 0; ; I++ )
   {
      if( *DSP_PCM_CTRL == 8 || au.ctrl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 60 ); // YS modified
      kal_sleep_task( 2 );
   }
}

Media_Status auPlay( mediaControl *mctrl )
{
   au.ctrl = mctrl;
   if( !auReadHeader() )
      return MEDIA_BAD_FORMAT;

   au.ctrl->is_8KVoice = false;
//#if defined(__BT_SUPPORT__)
//   if ( (AM_IsBluetoothOn() == true) && (au.fs_code == 0x00) && (au.ctrl->is_stereo == false) ) {
//      au.ctrl->is_8KVoice = true;
//      au.ctrl->mono2stereo = false;
//   }
//#endif

   auInternalPlay();
   return MEDIA_SUCCESS;
}

static void auWriteToDSP( void )
{
   int32 rb_r, rb_w, tmp1, rb_r_cache;
   
   rb_w = (int32)*DSP_PCM_W;
   do {
      rb_r = (int16)*DSP_PCM_R;
   } while (rb_r != (int16)*DSP_PCM_R);
   rb_r_cache = rb_r;
   rb_r = rb_r - rb_w -1;
   if( rb_r < 0 )
      rb_r += (int32)au.ctrl->dsp_rb_size; // Calculate the free space of dsp buffer
   rb_r &= 0xFFFFFFFC;     // force the number of audio samples filled to be even

   tmp1 = (int32)au.ctrl->dsp_rb_size - rb_w;
   
   if( au.mb_count > 0 )
   {
      if( rb_r > tmp1 )
      {
         au.Au_PutData( tmp1 );
         au.mb_count = mediaGetDataCount();
         rb_r -= tmp1;
      }
      au.Au_PutData( rb_r );
   }
   
   // fill silence
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if ( rb_r_cache < 0 )
      rb_r_cache += (int16)au.ctrl->dsp_rb_size;
   rb_r_cache &= 0xFFFFFFFC;     // force the length of silence filled to be even

   if( rb_r_cache )
   {
      tmp1 = (int16)au.ctrl->dsp_rb_size - rb_w;
      if( rb_r_cache > tmp1 )
      {
         PutSilence(au.ctrl, tmp1);
         rb_r_cache -= tmp1;
      }
      PutSilence(au.ctrl, rb_r_cache);
   }
}

static void auEndHandler(void *data, Media_Event event)
{
   (void) data;      // to avoid warning
      au.state = AU_STATE_IDLE;
//      if (au.ctrl->is_8KVoice)
//         AM_PCM8K_PlaybackOff( false );
//      else
         AM_AudioPlaybackOff( false );
      mediaSetEvent( MEDIA_END );
}

void auPlaybackHisr( void )
{
   if( au.state != AU_STATE_PLAYING )
      return;
      
   if( au.ctrl->end_status == MEDIA_TERMINATED )
      return;

   au.mb_count = mediaGetDataCount();
   if( (((au.mb_count << 1) < au.data_size && au.ctrl->eof)
   || (au.data_read+1 >= au.data_offset + au.data_length)) 
   && *DSP_PCM_CTRL == 0x08)
   {
      au.ctrl->end_status = MEDIA_END;
      *DSP_PCM_CTRL = 0x10;
      au.ctrl->eof = true;
      return;
   }

   if( *DSP_PCM_CTRL == 0 )
   {  // DSP returns to idle state
#if APM_SUPPORT
      APM_NOTIFY_MEDIA_END( auEndHandler, NULL, false , MEDIA_END);
#else
      auEndHandler(NULL, 0);
#endif
      return;
   }

   if( *DSP_PCM_CTRL == 2 ) {   /* DSP gives IDMA address and length */
      au.ctrl->dsp_rb_base = *DSP_PCM_W;
      au.ctrl->dsp_rb_size = *DSP_PCM_R;
      au.ctrl->dsp_rb_end = au.ctrl->dsp_rb_base + au.ctrl->dsp_rb_size;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
      PutSilence( au.ctrl, au.ctrl->dsp_rb_size );  // full dsp ring buffer with silence pattern
      *DSP_PCM_CTRL = 4;
   }

   if( au.data_read < au.data_offset )
   {
      if( (uint32)(au.mb_count << 1) < au.data_offset - au.data_read )
      {
         au.data_read += (au.mb_count << 1);
         au.ctrl->read = 0;
         au.ctrl->write = 0;
         return;
      }
      else
      {
         au.ctrl->read += ((au.data_offset - au.data_read) >> 1);
         if( au.ctrl->read >= au.ctrl->rb_size )
            au.ctrl->read -= au.ctrl->rb_size;
         au.data_read = au.data_offset;
         if( au.odd_start )
         {
            au.previous_byte = au.ctrl->rb_base[au.ctrl->read] & 0xFF00;
            au.ctrl->read ++;
            if( au.ctrl->read == au.ctrl->rb_size )
               au.ctrl->read = 0;
         }
      }
   }
   auWriteToDSP();
}

void auStop( void )
{
   uint16 I, ctl;
   au.ctrl->end_status = MEDIA_TERMINATED;

   switch( au.state )
   {
      case AU_STATE_IDLE:
         return;
      case AU_STATE_PLAYING:
      case AU_STATE_PLAY_PAUSED:
         for( I = 0; ; I++ )
         {
            ctl = *DSP_PCM_CTRL;
            if( ctl == 0x00 )    /* DSP returns to idle state */
               break;
            if( ctl == 0x08 )
               *DSP_PCM_CTRL = WAV_ABORT_STATE;      /* give ABORT command to the DSP */
            ASSERT_REBOOT( I < 40 );
            kal_sleep_task( 2 );
         }
//         if (au.ctrl->is_8KVoice)
//            AM_PCM8K_PlaybackOff( true );
//         else
            AM_AudioPlaybackOff( true );
         break;
      default:
         ASSERT( KAL_FALSE );
   }
   au.state = AU_STATE_IDLE;
// mediaHandler( (void*)MEDIA_TERMINATED );
}

void auPause( mediaControl *mctrl )
{
   uint16 I, ctl;
   au.ctrl->end_status = MEDIA_TERMINATED;

   for( I = 0; ; I++ )
   {
      ctl = *DSP_PCM_CTRL;
      if( ctl == 0x00 )    /* DSP returns to idle state */
         break;
      if( ctl == 0x08 )
         *DSP_PCM_CTRL = WAV_ABORT_STATE;   /* give ABORT command to the DSP */
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
//   if (au.ctrl->is_8KVoice)
//      AM_PCM8K_PlaybackOff( true );
//   else
      AM_AudioPlaybackOff( true );
   au.state = AU_STATE_PLAY_PAUSED;
}

void auResume( mediaControl *mctrl )
{
   if( au.state == AU_STATE_PLAY_PAUSED ) {
      au.ctrl->is_8KVoice = false;
      if (au.ctrl->is_stereo == false)
         au.ctrl->mono2stereo = true;
      else
         au.ctrl->mono2stereo = false;
//#if defined(__BT_SUPPORT__)
//      if ( (AM_IsBluetoothOn() == true) && (au.fs_code == 0x00) && (au.ctrl->is_stereo == false) ) {
//         au.ctrl->is_8KVoice = true;
//         au.ctrl->mono2stereo = false;
//      }
//#endif
      auInternalPlay();
   } else {
      kal_prompt_trace( MOD_L1SPHISR, "auResume Wrong State");
   }
}

void auUpdateLevel( void )
{
   AFE_SetDigitalGain(L1SP_AUDIO, au.ctrl->level);
}

#endif   // IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#endif   // defined( AU_DECODE )
