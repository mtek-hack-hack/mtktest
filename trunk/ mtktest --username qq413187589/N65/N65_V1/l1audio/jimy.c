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
 * jimy.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( DSP_WT_SYN )

#include "dspsyn.h"
#include "media.h"
#include "fsal.h"

#define  IMY_STATE_READY         1
#define  IMY_STATE_PLAYING       2
#define  IMY_STATE_PAUSED        3
#define  IMY_STATE_ABORT         4
#define  IMY_STATE_ENDING        5

typedef struct {
   int32             notetime;
   int32             full_note_duration;
   int32             ts_rate;
   const uint8       *cur_pos;
   const uint8       *end_pos;
   const uint8       *repeat_begin;
   Media_iMelody_Param   param;
   MidiChannel       *channel;
   uint16            beat;
   uint16            bak_cmd;
   uint16            bak_dtime;
   int16             loops;
   uint8             octave;
   uint8             velocity;
   uint8             style;
   int8              timbre;
   bool              eof;
   bool              error_flag;
   bool              led_on;
   bool              vibrator_on;
   bool              backlight_off;	
} IMY_Player;

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

#if defined(AUD_TIME_STRETCH)
Media_Handle *TS_Imy_Handle;   // KH: Add for Time Stretch
#endif

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

static void iGetBeat( IMY_Player *player, const uint8 **pptr )
{
   int16 new_beat;

   SkipSpace( pptr );
   new_beat = iGetInteger( pptr );
   if( new_beat >=25 && new_beat <= 900 )
      player->beat = new_beat;
   ClearToEnd( pptr );
}

static void iGetStyle( IMY_Player *player, const uint8 **pptr )
{
   SkipSpace( pptr );
   if( iCompare( pptr, "S0" ) || iCompare( pptr, "0" ) )
      player->style = 0;
   else if( iCompare( pptr, "S1" ) || iCompare( pptr, "1" ) )
      player->style = 1;
   else if( iCompare( pptr, "S2" ) || iCompare( pptr, "2" ) )
      player->style = 2;
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
static uint8 iPeek( IMY_Player *player )
{
   uint8 ch;
   for(;;) {
      ch = *player->cur_pos;
      if( ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' )
         break;
      player->cur_pos++;
   }
   return ch;
}

static bool iGetOctave( IMY_Player *player )
{
   const uint8 *ptr = player->cur_pos + 1;
   uint8 ch;

   ch = *ptr++;
   if( !(ch >= '0' && ch <= '8') )
      return false;
   player->octave = (uint8)(ch - '0');
   player->cur_pos = ptr;
   return true;
}

#if defined(AUD_TIME_STRETCH)
Media_Status JImy_SetTSRate( Media_Handle *handle, int32 rate)
{
   if ( handle == NULL ) {
      return MEDIA_FAIL;
   } else {
      IMY_Player *player = (IMY_Player *)handle->data;
      player->ts_rate = rate;
   }
   return MEDIA_SUCCESS;
}
#endif

static bool iGetNote( IMY_Player *player, uint8 *pitch, int32 *dura, int8 flag )
{
   const uint8 *ptr = player->cur_pos;
   uint8 ch;

   ch = Tolower( *ptr++ );
   if( ch == 'r' )
      *pitch = 0;
   else {
      if( !(ch >= 'a' && ch <= 'g') )
         return false;
      ch = (uint8)((ch >= 'c')? ch-'c': ch -'a'+5);
      *pitch = (uint8)((player->octave + 2) * 12 + PitchTab[flag][ch]);
   }
   player->octave = 4;
   ch = *ptr++;
   if( !(ch >= '0' && ch <= '5') )
      return false;
   *dura = (uint16)(player->full_note_duration >> (ch - '0'));

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

   player->cur_pos = ptr;

   return true;
}

/* ----------------------------------------------------------------- */
static void iRepeatBegin( IMY_Player *player )
{
   player->repeat_begin = ++player->cur_pos;
}

static void iRepeatCount( IMY_Player *player )
{
   const uint8 *ptr = player->cur_pos + 1;
   int16 count = iGetInteger( &ptr );

   if( player->loops < 0 )
      player->loops = (int16)((count==0)? 0 : count+1);
   player->cur_pos = ptr;
}

static void iRepeatEnd( IMY_Player *player )
{
   if( player->loops == 1 || player->loops < 0 ) {
      player->cur_pos++;
      player->loops = -1;
      return;
   }
   if( player->loops > 0 )
      player->loops--;
   player->cur_pos = player->repeat_begin;
}

/* ----------------------------------------------------------------- */
static IMY_Status iGetMelody( Media_Handle *handle, uint8 *pitch, int32 *dura )
{
   uint8 ch;
   IMY_Player *player = (IMY_Player *)handle->data;
   IMY_Status status = IMY_NONE;

   if( player->eof )
      return IMY_EOF;

   SkipSpaceCrlf( &player->cur_pos );

   while( status == IMY_NONE ) {
      if( player->cur_pos >= player->end_pos ) {
         status = IMY_EOF;
         player->eof = true;         
         break;
      }
      ch = Tolower( iPeek( player ) );
      switch( ch ) {
         case '(':            /* Begin of repeat */
            iRepeatBegin( player );
            break;
         case ')':            /* End of repeat */
            iRepeatEnd( player );
            break;
         case '@':
            iRepeatCount( player );
            break;
         case '*':            /* octave-prefix */
            if( !iGetOctave( player ) )
               status = IMY_ERROR;
            break;
         case '&':            /* flat note */
            player->cur_pos++;
            if( iGetNote( player, pitch, dura, 2 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         case '#':            /* sharp note */
            player->cur_pos++;
            if( iGetNote( player, pitch, dura, 1 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         case 'l':
            if( iCompare( &player->cur_pos, "ledon" ) ) {
               handle->handler( handle, MEDIA_LED_ON );
               player->led_on = true;	
            }   
            else if( iCompare( &player->cur_pos, "ledoff" ) ) {            	
               handle->handler( handle, MEDIA_LED_OFF );
               player->led_on = false;	
            }   
            else
               status = IMY_ERROR;
            break;
         case 'v':
            if( iCompare( &player->cur_pos, "vibeon" ) ) {
               handle->handler( handle, MEDIA_VIBRATOR_ON );
               player->vibrator_on = true;
            }   
            else if( iCompare( &player->cur_pos, "vibeoff" ) ) {
               handle->handler( handle, MEDIA_VIBRATOR_OFF );
               player->vibrator_on = false;
            }
            else if( iGetVolume( &player->cur_pos, &player->velocity ) ) {
               /* midify volume */
            }
            else
               status = IMY_ERROR;
            break;
         case 'b':
            if( iCompare( &player->cur_pos, "backon" ) ) {
               handle->handler( handle, MEDIA_BACKLIGHT_ON );
               player->backlight_off = false;
            }   
            else if( iCompare( &player->cur_pos, "backoff" ) ) {
               handle->handler( handle, MEDIA_BACKLIGHT_OFF );
               player->backlight_off = true;
            }   
            else if( iGetNote( player, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         case 'e':
            if( iCompare( &player->cur_pos, "END" ) && iCompare( &player->cur_pos, ":" ) && iCompare( &player->cur_pos, "IMELODY" ) ) {
               status = IMY_EOF;
               player->eof = true;
            }
            else if( iGetNote( player, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         default:             /* Note */
            if( iGetNote( player, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
      }
      if( status == IMY_ERROR ) {   /* error recovery */
         status = IMY_NONE;
         player->cur_pos++;
      }
   }
   if(status == IMY_EOF) {
      if(player->led_on) {
         handle->handler( handle, MEDIA_LED_OFF );
         player->led_on = false;	
      }
      if(player->vibrator_on) {
         handle->handler( handle, MEDIA_VIBRATOR_OFF );
         player->vibrator_on = false;	
      }
      if(player->backlight_off) {
         handle->handler( handle, MEDIA_BACKLIGHT_ON );
         player->backlight_off = false;	   			
      }
   }				  
   return status;
}
/* ------------------------------------------------------------------------------ */

static Media_Status imyParseHeader( Media_Handle *handle )
{
   IMY_Player *player = (IMY_Player *)handle->data;
   const uint8 *ptr = player->param.imyfile;
   int16 temp_inst = 0;

   player->end_pos   = ptr + player->param.filesize;
   player->eof       = false;
   player->beat      = 120;
   player->style     = 0;
   player->velocity  = 63;
   player->bak_cmd   = 0;

   if( iCompare( &ptr, "BEGIN" ) && iCompare( &ptr, ":" ) ) {
      if( !iCompare( &ptr, "IMELODY" ) )
         return MEDIA_BAD_FORMAT;
      ClearToEnd( &ptr );
   }

   while( *ptr != 0 ) {
      if( iCompare( &ptr, "VERSION" ) && iCompare( &ptr, ":" ) ) {
         if( !iCompare( &ptr, "1.0" ) && !iCompare( &ptr, "1.1" ) && !iCompare( &ptr, "1.2" ) )
            return MEDIA_BAD_FORMAT;
         ClearToEnd( &ptr );
      }
      else if( iCompare( &ptr, "FORMAT" ) && iCompare( &ptr, ":" ) ) {
         if( !iCompare( &ptr, "CLASS1.0" ) && !iCompare( &ptr, "CLASS2.0" ) )
            return MEDIA_BAD_FORMAT;
         ClearToEnd( &ptr );
      }
      else if( iCompare( &ptr, "NAME" ) && iCompare( &ptr, ":" ) )              /* ignore song name */
         ClearToEnd( &ptr );
      else if( iCompare( &ptr, "COMPOSER" ) && iCompare( &ptr, ":" ) ) {   /* ignore composer name */
         temp_inst = iGetComposer( &ptr );
         ClearToEnd( &ptr );
      }
      else if( iCompare( &ptr, "BEAT" ) && iCompare( &ptr, ":" ) )
         iGetBeat( player, &ptr );
      else if( iCompare( &ptr, "STYLE" ) && iCompare( &ptr, ":" ) )
         iGetStyle( player, &ptr );
      else if( iCompare( &ptr, "VOLUME" ) && iCompare( &ptr, ":" ) )
         iGetVolume( &ptr, &player->velocity );
      else if( iCompare( &ptr, "MELODY" ) && iCompare( &ptr, ":" ) )
         break;
      else
         return MEDIA_BAD_FORMAT;
   }

   player->cur_pos               = ptr;
   player->repeat_begin          = ptr;
   player->loops                 = -1;
   player->octave                = 4;
   player->full_note_duration    = (uint16)60000 / (uint16)(player->beat>>2);
#if defined(AUD_TIME_STRETCH)
   player->ts_rate = AudioPP_GetTSRate();
#else
   player->ts_rate = 100;
#endif
   player->notetime              = 0;
   player->timbre                = (int8)((temp_inst!=0)? temp_inst-1:player->param.default_instrument-1);
   handle->current_time          = 0;

   return MEDIA_SUCCESS;
}

static void imyEnd( Media_Handle *handle )
{
   if( handle->current_time >= handle->stop_time ) {
      handle->state = IMY_STATE_READY;
      handle->stop_flag = false;
      handle->handler( handle, MEDIA_END );
   }
   else if( handle->state == IMY_STATE_ABORT )
      handle->state = IMY_STATE_READY;
   else {
      ASSERT( handle->state == IMY_STATE_ENDING );
      handle->state = IMY_STATE_READY;
      if( handle->stop_flag )
         handle->stop_flag = false;
      else {
         IMY_Player *player = (IMY_Player *)handle->data;
         if( player->error_flag ) {
            player->error_flag = false;
            handle->handler( handle, MEDIA_ERROR );
         }
         else
            handle->handler( handle, MEDIA_END );
      }
   }
}

#define  SET_DTIME( val )  \
            if( handle->current_time >= handle->start_time )  \
               *dtime = (val) *  100 / player->ts_rate 
                              
static void imyDspGetCmd( Media_Handle *handle, uint16 *dtime, uint16 cmd[4] )
{
   IMY_Status  status;
   uint8       pitch;
   int32       dura;
   uint16      vel, logic_dtime;
   IMY_Player *player = (IMY_Player *)handle->data;
   MidiChannel *channel;

   if( handle->stop_flag || handle->current_time >= handle->stop_time  ) {
      channel = ((IMY_Player *)handle->data)->channel;
      if( channel != (MidiChannel*)0 && (channel->flag&CHANNEL_FLAG_ACTIVE) ) {
         channel->flag &= ~CHANNEL_FLAG_ACTIVE;
         cmd[0] = 1;
         cmd[1] = 0x0D00 + channel->dspChannel;
         return;
      }
      cmd[0] = DSPSYN_CMD_STOP;
      handle->stop_flag = false;
      handle->state = IMY_STATE_ABORT;
      return;
   }
   logic_dtime = (*dtime) * player->ts_rate / 100 ;
   if( player->bak_cmd != 0 ) {
      if( player->bak_dtime >= logic_dtime ) {
         if( handle->current_time < handle->start_time ) {
            handle->current_time += player->bak_dtime;
            player->bak_dtime = 0;
         }
         else {
            player->bak_dtime -= logic_dtime;
            handle->current_time += logic_dtime;
            *dtime = 0;
         }
      }
      else {
         handle->current_time += player->bak_dtime;
         cmd[0] = 2;
         cmd[1] = 0x0100 + player->channel->dspChannel;
         cmd[2] = player->bak_cmd;
         player->bak_cmd = 0;
         SET_DTIME( logic_dtime - player->bak_dtime );
      }
      return;
   }

   if( player->notetime - handle->current_time >= logic_dtime ) {
      if( handle->current_time < handle->start_time ) {
         handle->current_time = player->notetime;
      }
      else {
         handle->current_time += logic_dtime;
         SET_DTIME( 0 );
      }
      return;
   }
   SET_DTIME( logic_dtime + handle->current_time - player->notetime );
   handle->current_time = player->notetime;

   status = iGetMelody( handle, &pitch, &dura );
   if( status == IMY_ERROR ) {
      channel = ((IMY_Player *)handle->data)->channel;
      if( channel != (MidiChannel*)0 && (channel->flag&CHANNEL_FLAG_ACTIVE) ) {
         channel->flag &= ~CHANNEL_FLAG_ACTIVE;
         cmd[0] = 1;
         cmd[1] = 0x0C00 + channel->dspChannel;
         return;
      }
      cmd[0] = DSPSYN_CMD_STOP;
      player->error_flag = true;
      handle->state = IMY_STATE_ENDING;
      return;
   }
   else if( status == IMY_EOF ) {
      if( handle->repeat_count > 0 ) {
         if( handle->repeat_count == 1 ) {
            channel = ((IMY_Player *)handle->data)->channel;
            if( channel != (MidiChannel*)0 && (channel->flag&CHANNEL_FLAG_ACTIVE) ) {
               channel->flag &= ~CHANNEL_FLAG_ACTIVE;
               cmd[0] = 1;
               cmd[1] = 0x0C00 + channel->dspChannel;
               return;
            }
            handle->repeat_count = 0;
            cmd[0] = DSPSYN_CMD_END;
            handle->state = IMY_STATE_ENDING;
            return;
         }
         else
            handle->repeat_count--;
      }
      imyParseHeader( handle );
      handle->handler( handle, MEDIA_REPEATED );
      return;
   }

   vel = (uint16)player->velocity * handle->volume_level / 100;
   if( vel > 127 )
      vel = 127;
   cmd[0] = 2;
   cmd[1] = 0x0000 + player->channel->dspChannel;
   cmd[2] = ((uint16)pitch << 8) + vel;

   if( player->style == 0 )
      player->notetime += dura * 20 / 21;
   else if( player->style == 1 )
      player->notetime += dura;
   else  /* style == 2 */
      player->notetime += dura/2;

   player->bak_dtime  = player->notetime - handle->current_time;
   player->bak_cmd    = ((uint16)pitch << 8) + 0x40;

   if( player->style == 0 )
      player->notetime += dura / 21;
   else if( player->style == 2 )
      player->notetime += dura/2;
}

static void imyGetCmd( Media_Handle *handle, uint16 *dtime, uint16 cmd[4] )
{
   IMY_Player *player = (IMY_Player *)handle->data;

   cmd[0] = DSPSYN_CMD_NO_DATA;
   if( handle->state == IMY_STATE_ENDING ) {
      if( handle->stop_flag ) {
         cmd[0] = DSPSYN_CMD_STOP;
         handle->stop_flag = false;
         handle->state = IMY_STATE_ABORT;
      }
      return;
   }
   if( handle->state != IMY_STATE_PLAYING )
      return;
   if( player->timbre >= 0 ) {
      cmd[0] = 2;
      cmd[1] = 0x0400 + player->channel->dspChannel;
      cmd[2] = 0x0100 + player->timbre;      /* Use the second digital gain */
      player->timbre = -1 - player->timbre;
      return;
   }
   do {
      imyDspGetCmd( handle, dtime, cmd );
   } while( handle->current_time < handle->start_time && handle->state == IMY_STATE_PLAYING );
}

static Media_Status imyDspPlay( Media_Handle *handle )
{
   Media_Status retval;

   if( (retval = imyParseHeader( handle )) != MEDIA_SUCCESS )
      return retval;
   DSPSYN_TONE_Start( handle, imyEnd, imyGetCmd, true );

   return MEDIA_SUCCESS;
}

void JImy_Init( void )
{
}

Media_Handle *JImy_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_iMelody_Param **param )
{
   IMY_Player *player;
   Media_Handle *handle;

   if( (handle = DSPSYN_ObtainToneHandle()) == 0 )
      return 0;

   player               = (IMY_Player*)get_ctrl_buffer( sizeof(IMY_Player) );
   player->channel      = DSPSYN_GetMidiChannel( false );
   if( player->channel == (MidiChannel *)0 )
      return 0;
   handle->handler      = handler;
   handle->state        = IMY_STATE_READY;
   handle->stop_flag    = false;
   handle->volume_level = 100;
   handle->start_time   = 0;
   handle->stop_time    = 0x7FFFFFFF;
   handle->param        = (void *)&player->param;
   handle->data         = (uint32)player;
   *param               = &player->param;

#if defined(AUD_TIME_STRETCH)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_IMELODY);
   TS_Imy_Handle        = handle;   // KH: Add for Time Stretch
#endif

   return handle;
}

Media_Status JImy_Close( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   ASSERT( handle->state == IMY_STATE_READY );
#if defined(AUD_TIME_STRETCH)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_DAF);
   TS_Imy_Handle       = NULL;   // KH: Add for Time Stretch
#endif
   DSPSYN_FreeMidiChannel( ((IMY_Player *)handle->data)->channel );
   free_ctrl_buffer( (IMY_Player*)handle->data );
   DSPSYN_ReleaseToneHandle( handle );
   return MEDIA_SUCCESS;
}

Media_Status JImy_Play( Media_Handle *handle )
{
   Media_Status retval;
   IMY_Player *player = (IMY_Player *)handle->data;

   ASSERT( handle != (Media_Handle *)0 );
   if( ((Media_iMelody_Param *)handle->param)->default_instrument < 1 ||
         ((Media_iMelody_Param *)handle->param)->default_instrument > 128 )
      return MEDIA_FAIL;

   ASSERT( handle->state == IMY_STATE_READY );
   handle->state        = IMY_STATE_PLAYING;
   handle->repeat_count = ((Media_iMelody_Param *)handle->param)->repeats;
   player->channel->flag |= CHANNEL_FLAG_ACTIVE;
   player->error_flag   = false;
   player->led_on = false;
   player->vibrator_on = false;
   player->backlight_off = false;

   if( (retval = imyDspPlay(handle)) != MEDIA_SUCCESS )
      handle->state = IMY_STATE_READY;
   return retval;
}

static void imyDspWait( Media_Handle *handle, uint16 timeout )
{
   uint16 I;

   for( I = 0; ; I++ ) {
      if( handle->state == IMY_STATE_READY )
         break;
      ASSERT_REBOOT( I < timeout );
      kal_sleep_task( 2 );
   }
}

Media_Status JImy_Stop( Media_Handle *handle )
{
   switch( handle->state ) {
      case IMY_STATE_PLAYING:
         handle->stop_flag = true;
      case IMY_STATE_ABORT: // for Stop_Time_Up case     
         imyDspWait( handle, 40 );
         break;
      case IMY_STATE_ENDING:
      #if APM_SUPPORT
         if(DSPSYN_APM_Ending())
         {
            handle->state = IMY_STATE_ABORT;
            APM_EXECUTE_END_HANDLER();
         }   
         else 
      #endif    
         {   
            handle->stop_flag = true;
            imyDspWait( handle, 400 );
         }   
         break;
      case IMY_STATE_PAUSED:
         handle->state = IMY_STATE_READY;
      case IMY_STATE_READY:
         break;
      default:
         ASSERT( false );
         break;
   }
   return MEDIA_SUCCESS;
}

Media_Status JImy_Pause( Media_Handle *handle )
{
   switch( handle->state ) {
      case IMY_STATE_PLAYING:
         handle->stop_flag = true;
      case IMY_STATE_ABORT: // for Stop_Time_Up case     
         imyDspWait( handle, 40 );
         if(handle->current_time < handle->stop_time) { 
            // pause at PLAYING and not Stop_Time_Up
            handle->state = IMY_STATE_PAUSED;
            ((IMY_Player*)handle->data)->timbre = -1 - ((IMY_Player*)handle->data)->timbre;
         }   
         break;
      case IMY_STATE_ENDING:
      #if APM_SUPPORT
         if(DSPSYN_APM_Ending())
         {
            handle->state = IMY_STATE_ABORT;
            APM_EXECUTE_END_HANDLER();
         }   
         else 
      #endif    
         {   
            handle->stop_flag = true;
            imyDspWait( handle, 400 );
         }            
         return MEDIA_SEEK_EOF;         
      case IMY_STATE_READY:
         return MEDIA_FAIL;
      default:
         ASSERT( false );
   }
   return MEDIA_SUCCESS;
}

Media_Status JImy_Resume( Media_Handle *handle )
{
   IMY_Player *player = (IMY_Player *)handle->data;

   if( handle->state != IMY_STATE_PAUSED )
      return MEDIA_FAIL;
   handle->state = IMY_STATE_PLAYING;
   player->channel->flag |= CHANNEL_FLAG_ACTIVE;
   DSPSYN_TONE_Start( handle, imyEnd, imyGetCmd, false );
   return MEDIA_SUCCESS;
}

Media_Status JImy_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   handle->start_time = handle->current_time = msStartTime;
   return MEDIA_SUCCESS;
}

Media_Status JImy_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   handle->stop_time = msStopTime;
   return MEDIA_SUCCESS;
}

kal_int32 JImy_GetCurrentTime( Media_Handle *handle )
{
   return handle->current_time;
}

static void dummy_handler( Media_Handle *handle, Media_Event event )
{
}

int32 JImy_GetDuration( Media_Handle *handle )
{
   int32 start_time_bak = handle->start_time;
   int32 stop_time_bak = handle->stop_time;
   uint16 dtime;
   uint16 cmd[4];
   IMY_Player *player = (IMY_Player *)handle->data;
   void (*bak_handler)( Media_Handle *handle, Media_Event event ) = handle->handler;

   ASSERT( handle->state == IMY_STATE_READY );
   if( imyParseHeader( handle ) != MEDIA_SUCCESS )
      return 0;
   handle->start_time = 0x7FFFFFFF;
   handle->stop_time = 0x7FFFFFFF;
   handle->repeat_count = 1;
   handle->handler = dummy_handler;

   do {
      dtime = 18;
      imyDspGetCmd( handle, &dtime, cmd );
      if( player->loops == 0 ) {    /* enter infinite loop, enforce to giveup */
         handle->current_time = -1;
         break;
      }
   } while( handle->state != IMY_STATE_ENDING );

   handle->start_time = start_time_bak;
   handle->stop_time = stop_time_bak;
   handle->state = IMY_STATE_READY;
   handle->handler = bak_handler;

   return handle->current_time;
}

Media_Status JImy_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize,
                     audInfoStruct *contentInfo, void *param )
{
   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->author[0]  = '\0';
   contentInfo->copyright[0]  = '\0';
   contentInfo->date[0]  = '\0';
   return MEDIA_SUCCESS;
}

Media_Status JImy_SetLevel( Media_Handle *handle, kal_uint8 level )
{
   handle->volume_level = level;
   return MEDIA_SUCCESS;
}

kal_uint8 JImy_GetLevel( Media_Handle *handle )
{
   return handle->volume_level;
}

/* ------------------------------------------------------------------------------ */
#endif /* DSP_WT_SYN */


