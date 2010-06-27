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
 * imy.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   iMelody File Format Decoder
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#if defined( SW_SYN_8K ) || defined( SW_SYN_16K ) 

#include "midisyn.h"

extern const unsigned char Wavetable[];

static struct {
   const uint8          *cur_pos;
   const uint8          *repeat_begin;
   int8                 repeat_count;
   uint8                octave;
   uint8                velocity;
   int32                full_note_duration;
   uint16               beat;
   uint8                style;
   int32                on_time;
   int32                off_time;
   int16                delay_on;
   int16                delay_off;
   ToneGenerator        *tg;
   ToneGenerator        *tg1;
   void                 (*output_func)(const int16 *buf, int32 count);
   mediaControl         *ctrl;
   int8                 repeats;
   bool                 imy_eof;
#ifdef __MTK_TARGET__
   uint16               aud_id;
#endif
} imy;

static const uint8 PitchTab[3][7] = {
   {  0, 2, 4, 5, 7,  9, 11   },
   {  1, 3, 4, 6, 8, 10, 11   },
   {  0, 1, 3, 5, 6,  8, 10   }
};

typedef enum {
   IMY_NONE    = 0,
   IMY_GOTNOTE = 1,
   IMY_ERROR   = 2,
   IMY_EOF     = 3
} IMY_Status;

/* ----------------------------------------------------------------- */
/*   Utility Functions                                               */
/* ----------------------------------------------------------------- */

static void SkipSpaceCrlf( const uint8 **pptr )
{
   const uint8 *ptr = *pptr;
   while( *ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' )
      ptr++;
   *pptr = ptr;
}

static void SkipSpace( const uint8 **pptr )
{
   const uint8 *ptr = *pptr;
   while( *ptr == ' ' || *ptr == '\t' )
      ptr++;
   *pptr = ptr;
}

static void ClearToEnd( const uint8 **pptr )
{
   const uint8 *ptr = *pptr;
   while( *ptr != '\n' && *ptr != '\r' )
      ptr++;
   *pptr = ptr;
}

static uint8 Tolower( uint8 ch )
{
   if( ch >='A' && ch <= 'Z' )
      return (uint8)( ch + ('a' - 'A') );
   return ch;
}

static int8 Strnicmp( const uint8 *s1, const uint8 *s2, int maxlen)
{
   int ch1, ch2;
   while( maxlen-- > 0 ) {
      ch1 = Tolower( *s1++ );
      ch2 = Tolower( *s2++ );
      if( ch1 > ch2 )
         return 1;
      if( ch1 < ch2 )
         return -1;
   }
   return 0;
}

static bool iCompare( const uint8 **pptr, const void *s )
{
   uint8 len = 0;
   const uint8 *str = (uint8 *)s;

   while( str[len] )
      len++;

   SkipSpaceCrlf( pptr );
   if( Strnicmp( *pptr, str, len ) )
      return false;
   *pptr += len;
   return true;
}

static int16 iGetInteger( const uint8 **pptr )
{
   const uint8 *ptr = *pptr;
   uint8 ch;
   int32 val;

   ch = *ptr;
   if( !(ch >= '0' && ch <= '9') )
      return -1;
   val = ch - '0';
   ptr++;

   for(;;) {
      ch = *ptr;
      if( !(ch >= '0' && ch <= '9') )
         break;
      val = val * 10 + ch - '0';
      ptr++;
   }
   *pptr = ptr;
   return (int16)val;
}

static int16 iGetComposer( const uint8 **pptr )
{
   int16 I;
   const uint8 *ptr;

   SkipSpace( pptr );
   for( ptr = *pptr; *ptr != 0; ptr++ ) {
      if( *ptr == '(' ) {
         ptr++;
         I = iGetInteger( &ptr );
         return (int16)((I > 0 && I <= 128)? I : 0);
      }
   }
   return 0;
}

static void iGetBeat( const uint8 **pptr )
{
   int16 new_beat;

   SkipSpace( pptr );
   new_beat = iGetInteger( pptr );
   if( new_beat >=25 && new_beat <= 900 )
      imy.beat = new_beat;
   ClearToEnd( pptr );
}

static void iGetStyle( const uint8 **pptr )
{
   SkipSpace( pptr );
   if( iCompare( pptr, "S0" ) || iCompare( pptr, "0" ) )
      imy.style = 0;
   else if( iCompare( pptr, "S1" ) || iCompare( pptr, "1" ) )
      imy.style = 1;
   else if( iCompare( pptr, "S2" ) || iCompare( pptr, "2" ) )
      imy.style = 2;
   else
      ClearToEnd( pptr );
}

static bool iGetVolume( const uint8 **pptr, uint8 *volume )
{
   const uint8 *ptr;
   uint8 vol;

   SkipSpace( pptr );
   ptr = *pptr;

   vol = (uint8)(( *volume <= 7 )? 0 : (*volume - 7) / 8);

   if( *ptr == 'V' || *ptr == 'v' )
      ptr++;

   if( *ptr == '+' ) {
      vol = (uint8)((vol >= 15)? 15 : vol+1);
      ptr++;
   }
   else if( *ptr == '-' ) {
      vol = (uint8)((vol==0)? vol : vol-1);
      ptr++;
   }
   else {
      int16 new_vol = iGetInteger( &ptr );
      if( new_vol < 0 )
         return false;
      vol = (uint8)(( new_vol > 15 )? 15 : (uint8)new_vol);
   }
   *pptr = ptr;
   *volume = (uint8)(vol * 8 + 7);
   return true;
}

/* ----------------------------------------------------------------- */
static uint8 iPeek( void )
{
   uint8 ch;
   for(;;) {
      ch = *imy.cur_pos;
      if( ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' )
         break;
      imy.cur_pos++;
   }
   return ch;
}

static bool iGetOctave(  const uint8 **pptr )
{
   const uint8 *ptr = *pptr + 1;
   uint8 ch;

   ch = *ptr++;
   if( !(ch >= '0' && ch <= '8') )
      return false;
   imy.octave = (uint8)(ch - '0');
   *pptr = ptr;
   return true;
}

static bool iGetNote( const uint8 **pptr, uint8 *pitch, int32 *dura, int8 flag )
{
   const uint8 *ptr = *pptr;
   uint8 ch;

   ch = Tolower( *ptr++ );
   if( ch == 'r' )
      *pitch = 0;
   else {
      if( !(ch >= 'a' && ch <= 'g') )
         return false;
      ch = (uint8)((ch >= 'c')? ch-'c': ch -'a'+5);
      *pitch = (uint8)((imy.octave + 2) * 12 + PitchTab[flag][ch]);
   }
   imy.octave = 4;
   ch = *ptr++;
   if( !(ch >= '0' && ch <= '5') )
      return false;
   *dura = (uint16)(imy.full_note_duration >> (ch - '0'));

   ch = *ptr;
   if( ch == '.' ) {
      *dura = (uint16)(*dura + (*dura>>1));
      ptr++;
   }
   else if( ch == ':' ) {
      *dura = (uint16)(*dura + (*dura>>2));
      ptr++;
   }
   else if( ch == ';' ) {
      *dura = (uint16)(*dura * 2 / 3);
      ptr++;
   }

   *pptr = ptr;

   return true;
}

/* ----------------------------------------------------------------- */
static void iRepeatBegin( void )
{
   imy.repeat_begin = ++imy.cur_pos;
}

static void iRepeatCount( const uint8 **pptr )
{
   const uint8 *ptr = *pptr + 1;
   int16 count = iGetInteger( &ptr );

   if( imy.repeat_count < 0 )
      imy.repeat_count = (int8)((count==0)? 0 : count);
   *pptr = ptr;
}

static void iRepeatEnd( void )
{
   if( imy.repeat_count == 1 || imy.repeat_count < 0 ) {
      imy.cur_pos++;
      imy.repeat_count = -1;
      return;
   }
   if( imy.repeat_count > 0 )
      imy.repeat_count--;
   imy.cur_pos = imy.repeat_begin;
}

/* ----------------------------------------------------------------- */
static IMY_Status iGetMelody( uint8 *pitch, int32 *dura )
{
   uint8 ch;
   IMY_Status status = IMY_NONE;

   if( imy.imy_eof )
      return IMY_EOF;
   SkipSpaceCrlf( &imy.cur_pos );

   while( status == IMY_NONE ) {
      ch = Tolower( iPeek() );
      switch( ch ) {
         case '(':            /* Begin of repeat */
            iRepeatBegin();
            break;
         case ')':            /* End of repeat */
            iRepeatEnd();
            break;
         case '@':
            iRepeatCount( &imy.cur_pos );
            break;
         case '*':            /* octave-prefix */
            if( !iGetOctave( &imy.cur_pos ) )
               status = IMY_ERROR;
            break;
         case '&':            /* flat note */
            imy.cur_pos++;
            if( iGetNote( &imy.cur_pos, pitch, dura, 2 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         case '#':            /* sharp note */
            imy.cur_pos++;
            if( iGetNote( &imy.cur_pos, pitch, dura, 1 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         case 'l':
            if( iCompare( &imy.cur_pos, "ledon" ) )
               mediaHandler( (void *)MEDIA_LED_ON );        /* light on LED */
            else if( iCompare( &imy.cur_pos, "ledoff" ) )
               mediaHandler( (void *)MEDIA_LED_OFF );       /* light off LED */
            else
               status = IMY_ERROR;
            break;
         case 'v':
            if( iCompare( &imy.cur_pos, "vibeon" ) )
               mediaHandler( (void *)MEDIA_VIBRATOR_ON );   /* turn on vibrator */
            else if( iCompare( &imy.cur_pos, "vibeoff" ) )
               mediaHandler( (void *)MEDIA_VIBRATOR_OFF );  /* turn off vibrator */
            else if( iGetVolume( &imy.cur_pos, &imy.velocity ) ) {
               /* midify volume */
            }
            else
               status = IMY_ERROR;
            break;
         case 'b':
            if( iCompare( &imy.cur_pos, "backon" ) )
               mediaHandler( (void *)MEDIA_BACKLIGHT_ON );  /* turn on backlight */
            else if( iCompare( &imy.cur_pos, "backoff" ) )
               mediaHandler( (void *)MEDIA_BACKLIGHT_OFF ); /* turn off backlight */
            else if( iGetNote( &imy.cur_pos, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         case 'e':
            if( iCompare( &imy.cur_pos, "END:IMELODY" ) ) {
               status = IMY_EOF;
               imy.imy_eof = true;
            }
            else if( iGetNote( &imy.cur_pos, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         default:             /* Note */
            if( iGetNote( &imy.cur_pos, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
      }
   }

   return status;
}

/* ----------------------------------------------------------------- */
static IMY_Status imyParse( void )
{
   ToneGenerator *tg;
   IMY_Status  status;
   uint8       pitch;
   int32       dura;
   int         I = 0;

   status = iGetMelody( &pitch, &dura );
   if( status == IMY_EOF || status == IMY_ERROR )
      return IMY_EOF;

   if( imy.style == 0 ) {
      imy.on_time  = dura * 20 / 21;
      imy.off_time = dura / 21;
   }
   else if( imy.style == 1 ) {
      imy.on_time  = dura;
      imy.off_time = 0;
   }
   else {   /* style == 2 */
      imy.on_time  = imy.off_time = dura / 2;
   }
   imy.tg = 0;
   if( pitch > 0 ) {
      I = pitch + imy.ctrl->key_shift;
      if( I > 0 && I < 119 ) {
         pitch = (uint8)I;
         I = 0;
         do {
            tg = &toneGen[I];
            if( tg->state == EG_FREE ) {
               imy.tg         = tg;
               tg->channel    = 0;
               tg->pitch      = pitch;
               tg->velocity   = imy.velocity;
               SWSYN_StartNote( tg );
               imy.delay_on   = tg->wt->reverbDelay;
               break;
            }
         } while( ++I < MAX_POLYPHONY );
      }
   }

   return IMY_GOTNOTE;
}

static bool imyComputeData( void )
{
   CONFIRM_WRITE_SPACE();

   if( imy.on_time <= 0 && imy.off_time <= 0 ) {
      if( imyParse() == IMY_EOF && SWSYN_ToneGenIdle() )
         return true;
   }

   do {
      SWSYN_Synthesize( false );
      SWSYN_Agc( imy.ctrl->max_swing );
      imy.output_func( audio_buffer, BLOCK_SAMPLE_NO );
      if( imy.on_time > 0 ) {
         imy.on_time -= BLOCK_PERIOD;
         if( imy.on_time <= 0 ) {
            imy.on_time = 0;
            if( imy.tg != 0 ) {
               imy.delay_off   = imy.tg->wt->reverbDelay;
               SWSYN_CloseNote( imy.tg );
            }
         }
      }
      else if( imy.off_time > 0 )
         imy.off_time -= BLOCK_PERIOD;
      if( imy.delay_off > 0 ) {
         imy.delay_off -= BLOCK_PERIOD;
         if( imy.delay_off <= 0 ) {
            SWSYN_CloseNote( imy.tg1 );
         }
      }
      if( imy.delay_on > 0 ) {
         imy.delay_on -= BLOCK_PERIOD;
         if( imy.delay_on <= 0 ) {
            ToneGenerator *tg;
            int16 I = 0;
            do {
               tg = &toneGen[I];
               if( tg->state == EG_FREE ) {
                  imy.tg1        = tg;
                  tg->channel    = 0;
                  tg->pitch      = imy.tg->pitch;
                  tg->velocity   = (int8)(imy.tg->velocity * 3 / 4);
                  SWSYN_StartNote( tg );
                  break;
               }
            } while( ++I < MAX_POLYPHONY );
         }
      }
      if( imy.on_time <= 0 && imy.off_time <= 0 )
         imyParse();

      CONFIRM_WRITE_SPACE();
   } while( imy.on_time > 0 || imy.off_time > 0 || !SWSYN_ToneGenIdle() );

   return false;
}

/* ----------------------------------------------------------------- */
bool imyPlay( mediaControl *ctrl, void (*output)(const int16 *buf, int32 count) )
{
   const uint8 *ptr = ctrl->param.imy.imyfile;
   int16 temp_inst = 0;

   if( ctrl->param.imy.default_instrument < 1 || ctrl->param.imy.default_instrument > 128 )
      return false;

   imy.ctrl = ctrl;
   imy.imy_eof = false;
   imy.repeats = (int8)ctrl->param.imy.repeats;
   imy.beat       = 120;
   imy.style      = 0;
   imy.velocity   = 63;

   if( iCompare( &ptr, "BEGIN:" ) ) {
      if( !iCompare( &ptr, "IMELODY" ) )
         return false;
      ClearToEnd( &ptr );
   }

   while( *ptr != 0 ) {
      if( iCompare( &ptr, "VERSION:" ) ) {
         if( !iCompare( &ptr, "1.0" ) && !iCompare( &ptr, "1.1" ) && !iCompare( &ptr, "1.2" ) )
            return false;
         ClearToEnd( &ptr );
      }
      else if( iCompare( &ptr, "FORMAT:" ) ) {
         if( !iCompare( &ptr, "CLASS1.0" ) && !iCompare( &ptr, "CLASS2.0" ) )
            return false;
         ClearToEnd( &ptr );
      }
      else if( iCompare( &ptr, "NAME:" ) )              /* ignore song name */
         ClearToEnd( &ptr );
      else if( iCompare( &ptr, "COMPOSER:" ) ) {   /* ignore composer name */
         temp_inst = iGetComposer( &ptr );
         ClearToEnd( &ptr );
      }
      else if( iCompare( &ptr, "BEAT:" ) )
         iGetBeat( &ptr );
      else if( iCompare( &ptr, "STYLE:" ) )
         iGetStyle( &ptr );
      else if( iCompare( &ptr, "VOLUME:" ) )
         iGetVolume( &ptr, &imy.velocity );
      else if( iCompare( &ptr, "MELODY:" ) )
         break;
      else
         return false;
   }

   imy.cur_pos             = ptr;
   imy.repeat_begin        = ptr;
   imy.repeat_count        = -1;
   imy.octave              = 4;
   imy.full_note_duration  = (uint16)60000 / (uint16)(imy.beat>>2);
   imy.output_func         = output;
   imy.on_time             = 0;
   imy.off_time            = 0;
   imy.delay_on            = 0;
   imy.delay_off           = 0;

   SWSYN_ResetMIDI();

   midiChannel[0].program = (int8)((temp_inst!=0)? temp_inst-1:ctrl->param.imy.default_instrument-1);
   midiChannel[0].expression = 127;
   midiChannel[0].volume = 127;

   imyComputeData();

   return true;
}

/* ------------------------------------------------------------------------------ */
#ifdef __MTK_TARGET__

static void imyWritePCM(const int16 *buf, int32 count)
{
   uint16 *writebuffer;
   uint32 I, buf_len;
   Media_GetWriteBuffer( &writebuffer, &buf_len );
   ASSERT( buf_len > 0 );
   if( buf_len >= count ) {
      for( I = 0; I < count; I++ )
         writebuffer[I] = buf[I];
      Media_WriteDataDone( count );
   }
   else {
      for( I = 0; I < buf_len; I++ )
         writebuffer[I] = buf[I];
      Media_WriteDataDone( buf_len );
      I = count - buf_len;
      Media_GetWriteBuffer( &writebuffer, &buf_len );
      ASSERT( buf_len >= I );
      buf_len = I;
      for( I = 0; I < buf_len; I++ )
         writebuffer[I] = buf[I];
      Media_WriteDataDone( buf_len );
   }
}

static void imyHandler( void *data )     /* This function works in L1Audio Task */
{
   Media_Event event = (Media_Event)(int32)data;

   if( event == MEDIA_END ) {
      SWSYN_UnloadWavetable();
      mediaHandler( data );
   }
   else if( event == MEDIA_DATA_REQUEST ) {
      if( imy.repeats >= 0 ) {
         if( imyComputeData() ) {
            if( imy.repeats == 1 ) {
               imy.repeats = -1;
               Media_DataFinished();
            }
            else {
               if( imy.repeats != 0 )
                  imy.repeats--;
               imyPlay( imy.ctrl, imyWritePCM );
            }
         }
      }
   }
}

void imyInit( uint16 aud_id )
{
   imy.aud_id = aud_id;
   L1Audio_SetEventHandler( imy.aud_id, imyHandler );
}

void imySetEvent( Media_Event event )
{
   L1Audio_SetEvent( imy.aud_id, (void *)event );
}

Media_Status imyStart( mediaControl *ctrl )
{
   SWSYN_ResetAgc( 0xC000, 100, 10 );
   SWSYN_LoadWavetable( Wavetable );
   
   if( imyPlay( ctrl, imyWritePCM ) == true ) {
      SWSYN_PcmStart( ctrl );
      return MEDIA_SUCCESS;
   }
   else {
      SWSYN_UnloadWavetable();
      return MEDIA_FAIL;
   }
}

void imyStop( void )
{
   SWSYN_PcmStop( imy.ctrl );
   SWSYN_UnloadWavetable();
}

#endif   /* __MTK_TARGET__ */
/* ------------------------------------------------------------------------------ */

#else
char dummy_imy_c;    /* define a dummy variable to avoid warning message */
#endif /*  SW_SYN_8K || SW_SYN_16K  */


