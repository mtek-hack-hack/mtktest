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
 * iMelody.c
 *
 * Project:
 * --------
 *   MTK6208
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"

#if defined( ORDNANCE )
#include "gpt_sw.h"
#else
#include "alerter_sw.h"
#endif

static Media_Status imyPlay( void );

static struct {
   Media_iMelody_Param   *msp;
   const uint8    *cur_pos;
   uint8          repeats;
   bool           bad_flag;
   uint32         note_time;
   uint8          gpt;
   uint16         beat;
   uint8          style;

   const uint8    *repeat_begin;
   int8           repeat_count;
   uint8          octave;
   uint8          var_volume;
   uint16         full_note_duration;
   uint16         aud_id;
} imy;

const static uint8 PitchTab[3][7] = {
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
      return( ch + ('a' - 'A') );
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
   uint16 val;

   ch = *ptr;
   if( !(ch >= '0' && ch <= '9') )
      return -1;
   val = ch - '0';
   ptr++;

   while(1) {
      ch = *ptr;
      if( !(ch >= '0' && ch <= '9') )
         break;
      val = val * 10 + ch - '0';
      ptr++;
   }
   *pptr = ptr;
   return val;
}

static void iGetBeat( const uint8 **pptr, uint16 *beat )
{
   int16 new_beat;

   SkipSpace( pptr );
   new_beat = iGetInteger( pptr );
   if( new_beat >=25 && new_beat <= 900 )
      *beat = new_beat;
   ClearToEnd( pptr );
}

static bool iGetVolume( const uint8 **pptr, uint8 *volume )
{
   const uint8 *ptr;
   uint8 old_volume = *volume;

   SkipSpace( pptr );
   ptr = *pptr;

   if( *ptr == 'V' || *ptr == 'v' )
      ptr++;

   if( *ptr == '+' ) {
      *volume = (old_volume >= 15)? 15 : old_volume+1;
      ptr++;
   }
   else if( *ptr == '-' ) {
      *volume = (old_volume==0)? old_volume : old_volume-1;
      ptr++;
   }
   else {
      int16 vol = iGetInteger( &ptr );
      if( vol < 0 )
         return false;
      *volume = ( vol > 15 )? 15 : (uint8)vol;
   }
   *pptr = ptr;
   return true;
}

/* ----------------------------------------------------------------- */
static uint8 iPeek( void )
{
   uint8 ch;
   while( 1 ) {
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
   imy.octave = ch - '0';
   *pptr = ptr;
   return true;
}

static bool iGetNote( const uint8 **pptr, uint8 *pitch, uint16 *dura, int8 flag )
{
   const uint8 *ptr = *pptr;
   uint8 ch;

   ch = Tolower( *ptr++ );
   if( ch == 'r' )
      *pitch = 200;
   else {
      if( !(ch >= 'a' && ch <= 'g') )
         return false;
      ch = (ch >= 'c')? ch-'c': ch -'a'+5;
      *pitch = (imy.octave + 1) * 12 + PitchTab[flag][ch];
   }
   imy.octave = 4;
   ch = *ptr++;
   if( !(ch >= '0' && ch <= '5') )
      return false;
   *dura = imy.full_note_duration >> (ch - '0');

   ch = *ptr;
   if( ch == '.' ) {
      *dura += *dura / 2;
      ptr++;
   }
   else if( ch == ':' ) {
      *dura += *dura / 4;
      ptr++;
   }
   else if( ch == ';' ) {
      *dura = *dura * 2 / 3;
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

   if( count < 0 )
      imy.bad_flag = true;
   else if( imy.repeat_count < 0 )
      imy.repeat_count = (count==0)? 0 : count;
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
static IMY_Status iGetMelody( uint8 *pitch, uint16 *dura )
{
   uint8 ch;
   IMY_Status status = IMY_NONE;

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
               L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_LED_ON );
            else if( iCompare( &imy.cur_pos, "ledoff" ) )
               L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_LED_OFF );
            else
               status = IMY_ERROR;
            break;
         case 'v':
            if( iCompare( &imy.cur_pos, "vibeon" ) )
               L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_VIBRATOR_ON );
            else if( iCompare( &imy.cur_pos, "vibeoff" ) )
               L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_VIBRATOR_OFF );
            else if( iGetVolume( &imy.cur_pos, &imy.var_volume ) ) {
               /* midify volume */
            }
            else
               status = IMY_ERROR;
            break;
         case 'b':
            if( iCompare( &imy.cur_pos, "backon" ) )
               L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_BACKLIGHT_ON );
            else if( iCompare( &imy.cur_pos, "backoff" ) )
               L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_BACKLIGHT_OFF );
            else if( iGetNote( &imy.cur_pos, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         case 'e':
            if( iCompare( &imy.cur_pos, "END:IMELODY" ) )
               status = IMY_EOF;
            else if( iGetNote( &imy.cur_pos, pitch, dura, 0 ) )
               status = IMY_GOTNOTE;
            else
               status = IMY_ERROR;
            break;
         default:             /* note */
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
static void eosHandler( void )
{
   if( imy.bad_flag ) {
      L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_ERROR );
      return;
   }
   if( imy.repeats == 1 ) {
      L1Audio_SetEvent( imy.aud_id, (void*)MEDIA_END );
      return;
   }
   if( imy.repeats > 0 )
      imy.repeats--;
   imyPlay();
}

/* ----------------------------------------------------------------- */
#if defined( ORDNANCE )
static void Refill_gmi( void *data )
{
   uint8 pitch;
   uint16 dura;
   uint16 dura_on;
   IMY_Status status;

   status = iGetMelody( &pitch, &dura );
      
   if( status == IMY_ERROR ) {
      imy.bad_flag      = true;
      GMI_DataFinished();
   }
   else if( status == IMY_EOF ) {
      GMI_DataFinished();
   }
   else {   /* done */
      if( imy.style == 0 )
         dura_on  = dura * 20 / 21;
      else if( imy.style == 1 )
         dura_on  = dura;
      else  /* style == 2 */
         dura_on  = dura / 2;
      dura = (((dura+10)/5)>>2) * 20;
      dura_on = (((dura_on+10)/5)>>2) * 20;
      
      if( pitch < 128 )
         GMI_PutNote( imy.note_time + 40, dura_on, pitch, 
            ((int16)imy.var_volume*imy.var_volume*145), 0 );
      imy.note_time += dura;
      GPTI_StartItem( imy.gpt, dura / 10, Refill_gmi, 0 );
   }
}

static void GetMelody_gmi( GMI_Event event )
{
   if( event == GMI_END )
      eosHandler();
   else if( event == GMI_NOTE_REQUEST ) {
      GPTI_StopItem( imy.gpt );
      Refill_gmi( 0 );
   }
}
#else
static bool GetMelody_buz( BuzNoteStruct *Buz )
{
   uint8 pitch;
   uint16 dura;
   IMY_Status status;

   status = iGetMelody( &pitch, &dura );

   if( status == IMY_ERROR ) {
      imy.bad_flag      = true;
      Buz->pitch        = 200;
      Buz->volume       = 0;
      Buz->on_duration  = 5;
      Buz->off_duration = 0;
      return false;
   }
   else if( status == IMY_EOF ) {
      Buz->pitch        = 200;
      Buz->volume       = 0;
      Buz->on_duration  = 300;
      Buz->off_duration = 0;
      return false;
   }
   else {   /* done */
      Buz->pitch           = pitch;
      Buz->volume          = imy.var_volume;
      if( imy.style == 0 ) {
         Buz->on_duration  = dura * 20 / 21;
         Buz->off_duration = dura / 21;
      }
      else if( imy.style == 1 ) {
         Buz->on_duration  = dura;
         Buz->off_duration = 0;
      }
      else { /* style == 2 */
         Buz->on_duration  = dura / 2;
         Buz->off_duration = dura / 2;
      }
   }

   return true;
}
#endif
/* ----------------------------------------------------------------- */
static Media_Status imyPlay( void )
{
   const uint8 *ptr = imy.msp->imyfile;

   imy.beat          = 120;
   imy.style         = 0;
   imy.bad_flag      = false;

   if( !iCompare( &ptr, "BEGIN:" ) )
      return MEDIA_FAIL;
   if( !iCompare( &ptr, "IMELODY" ) ) 
      return MEDIA_FAIL;

   while( !iCompare( &ptr, "MELODY:" ) ) {
      if( iCompare( &ptr, "VERSION:" ) )
         ClearToEnd( &ptr );
      else if( iCompare( &ptr, "FORMAT:" ) )
         ClearToEnd( &ptr );
      else if( iCompare( &ptr, "NAME:" ) )
         ClearToEnd( &ptr );
      else if( iCompare( &ptr, "COMPOSER:" ) )
         ClearToEnd( &ptr );
      else if( iCompare( &ptr, "BEAT:" ) )
         iGetBeat( &ptr, &imy.beat );
      else if( iCompare( &ptr, "STYLE:" ) ) {
         if( iCompare( &ptr, "S0" ) || iCompare( &ptr, "0" ) )
            imy.style = 0;
         else if( iCompare( &ptr, "S1" ) || iCompare( &ptr, "1" ) )
            imy.style = 1;
         else if( iCompare( &ptr, "S2" ) || iCompare( &ptr, "2" ) )
            imy.style = 2;
         else
            ClearToEnd( &ptr );
      }
      else if( iCompare( &ptr, "VOLUME:" ) )
         iGetVolume( &ptr, &imy.var_volume );
      else
         return MEDIA_FAIL;
   }

   imy.cur_pos             = ptr;
   imy.repeat_begin        = ptr;
   imy.repeat_count        = -1;
   imy.octave              = 4;
   imy.full_note_duration  = (uint16)60000 / (uint16)(imy.beat>>2);

#if defined( ORDNANCE )
   imy.note_time     = 0;
   imy.var_volume    = 15;
   GMI_Play( GetMelody_gmi );
#else
   imy.var_volume    = 7;
   PlayAlterNotes( GetMelody_buz, eosHandler );
#endif         
   return MEDIA_SUCCESS;
}

/* ------------------------------------------------------------------------------ */
/*  iMelody Interface(include eMelody and MEL format)                             */
/* ------------------------------------------------------------------------------ */
static void imyHandler( void *data )     /* This function works in L1Audio Task */
{
   mediaHandler( data );
}

void iMelodyInit( uint16 aud_id )
{
   imy.aud_id = aud_id;
   L1Audio_SetEventHandler( imy.aud_id, imyHandler );
   
   GPTI_GetHandle( &imy.gpt );
}

Media_Status iMelodyPlay( mediaControl *ctrl )
{
   imy.msp              = &ctrl->param.imy;
   imy.repeats          = imy.msp->repeats;
   return imyPlay();
}

void iMelodyStop( void )
{
#if defined( ORDNANCE )
   GPTI_StopItem( imy.gpt );
   GMI_Stop();
#else      
   StopAlterNotes();
#endif      
}


