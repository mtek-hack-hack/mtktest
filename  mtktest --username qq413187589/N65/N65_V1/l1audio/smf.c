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
 * smf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SMF playback
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
#if defined( SW_SYN_8K ) || defined( SW_SYN_16K )

#include "midisyn.h"
#include "wav.h"

#if defined(MT6225) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define WAV_ABORT_STATE 0x40
#else
#define WAV_ABORT_STATE 0x10
#endif

#define CMIDI_SUPPORT

extern const unsigned char Wavetable[];

#define  MAX_TRACK               32
#define  MSG_SIZE                16
#define  EVENT_Q_SIZE            32

#define  MAX_SOUND               8

/* Midi events */
#define ME_NONE                  0
#define ME_NOTEON                1
#define ME_NOTEOFF               2
#define ME_KEY_PRESSURE          3
#define ME_MAINVOLUME            4
#define ME_SUSTAIN               5
#define ME_EXPRESSION            6
#define ME_PITCH_WHEEL           7
#define ME_PITCH_SENS            8
#define ME_PROGRAM               9 
#define ME_CHANNEL_PRESSURE      10
#define ME_TONE_BANK             11
#define ME_ALL_NOTES_OFF         12
#define ME_ALL_SOUNDS_OFF        13
#define ME_RESET_CONTROLLERS     14

/* --------------------------------------------- */
/*  Type Definitions                             */
/* --------------------------------------------- */
typedef struct {
   uint32      deltatime;
   uint32      toberead;
   const uint8 *ptr;
   uint8       running;
   uint8       status;
} MidiTrack;

typedef struct {
  int32  time;
  uint8  ch;
  uint8  type;
  uint8  c1;
  uint8  c2;
} MidiEvent;

/* --------------------------------------------- */
/*  Declarations of Global variables             */
/* --------------------------------------------- */
typedef struct {
   union {
      struct {
         MidiTrack   tracks[MAX_TRACK];
      } smf;
#if defined( CMIDI_SUPPORT )
      struct {
         const uint8 *ptr;
         int32       len;
         uint16      cache;
         uint16      bits;
         uint8       channel;
         uint8       octave;
      } cmi;
#endif
   } midi;

   int32             resettime;              /* current time in delta-time units */
   int32             ticks;
   int32             tempo;                  /* the default tempo is 120 beats/minute */
   uint16            ntrks;
   int16             division;
   void              (*output_func)(const int16 *buf, int32 count);
   uint32            synth_time;
   mediaControl      *ctrl;
   uint8             msgbuff[MSG_SIZE];      /* message buffer */
   MidiEvent         evq_buf[EVENT_Q_SIZE];
   uint16            evq_head;
   uint16            evq_count;
   int8              rpn_msb[16];
   int8              rpn_lsb[16];
   bool              nrpn;
   int8              repeats;
} SmfPlayer;

static struct {
   uint16      aud_id;
   SmfPlayer   *player;
} smf;
/* ------------------------------------------------------------------- */
#define  EventQ_Empty(p)   (p->evq_count==0)
#define  EventQ_Full(p)    (p->evq_count==EVENT_Q_SIZE)
#define  EventQ_Count(p)   (p->evq_count)
#define  EventQ_Peek(p)    (&p->evq_buf[p->evq_head])
#define  EventQ_Init(p)    {  p->evq_head = p->evq_count = 0;    }
#define  EventQ_Put(p, t, ty, c, a, b)    {  \
   MidiEvent *nt = &p->evq_buf[(p->evq_head + p->evq_count) & (EVENT_Q_SIZE-1)];  \
   nt->time = t;                 \
   nt->type = ty;                \
   nt->ch   = c;                 \
   nt->c1   = a;                 \
   nt->c2   = b;                 \
   p->evq_count++;               \
}

#define  EventQ_Consume(p)  {    \
   p->evq_count--;               \
   p->evq_head = (uint16)((p->evq_head+1) & (EVENT_Q_SIZE-1));  \
}

/* ------------------------------------------------------------------- */
static uint32 get32bit( const uint8 *s )
{
   return ((uint32)s[0] << 24) + ((uint32)s[1] << 16) + ((uint32)s[2] << 8) + (uint32)s[3];
}

static uint16 get16bit( const uint8 *s )
{
   return (uint16)(((uint16)s[0] << 8) + (uint16)s[1]);
}

/* ------------------------------------------------------------------- */
static int32 egetc( MidiTrack *trk )       /* read a single character and abort on EOF */
{
   if( trk->toberead > 0 ) {
      trk->toberead--;
      return *trk->ptr++;
   }
   return -1;
}

/* ------------------------------------------------------------------- */
/* ReadVarNum - read a varying-length number, and return the */
/* number of characters it took. */

static int32 ReadVarNum( MidiTrack *trk )
{
   int32 value;
   int32 c;

   c = egetc( trk );
   if( !(c & 0x80) )    return c;
   value = c & 0x7F;
   c = egetc( trk );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = egetc( trk );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = egetc( trk );
   value = (value << 7) + (c & 0x7f);
   return value;
}

/* ------------------------------------------------------------------- */
static void msg_read( SmfPlayer *player, MidiTrack *trk )
{
   uint32 I;
   uint32 count = ReadVarNum( trk );

   if( count < MSG_SIZE - 1 ) {
      for( I = 0; I < count; I++ ) {
         player->msgbuff[I] = *trk->ptr++;
      }
      player->msgbuff[I] = 0;
   }
   else {
      player->msgbuff[0] = 0;
      trk->ptr+= count;
   }
   trk->toberead = ( trk->toberead > count )? trk->toberead - count : 0;
}

static void msg_bypass( MidiTrack *trk )
{
   uint32 count = ReadVarNum( trk );

   trk->ptr += count;
   trk->toberead = ( trk->toberead > count )? trk->toberead - count : 0;
}

uint32 Ticks2ms( SmfPlayer *player )
{
   if( player->division > 0 )
      return  (player->ticks * player->tempo) / (uint32)player->division;
   else {
      int8 low, high;
      low = (int8)(player->division & 0xFF);
      high = (int8)((player->division >> 8) & 0xFF);
      return (player->ticks * 1000) / ((uint32)(-high) * (uint32)low);
   }
}

/* ------------------------------------------------------------------- */
static void MetaEvent( SmfPlayer *player, int type, uint8 *m )
{
   switch  ( type ) {
   case 0x51:  /* Set tempo */
      {
         int32 ltempo = ((uint32)m[0] << 16) + ((uint32)m[1] << 8) + (uint32)m[2];
         player->resettime += Ticks2ms( player );
         player->ticks = 0;
         player->tempo = ltempo / 1000;
         break;
      }
   case 0x2f:  /* End of Track */
      break;
   }
}

static void ChannelMessage( SmfPlayer *player, int8 status, int8 c1, int8 c2)
{
   int8 type = ME_NONE, ch = (int8)(status & 0xf);
   int I;

   switch ( status & 0xf0 ) {
   case 0x80:
      I = c1 + player->ctrl->key_shift;
      if( I >= 27 && I <= 108 ) {
         c1 = (int8)I;
         type = ME_NOTEOFF;
      }
      break;
   case 0x90:
      I = c1 + player->ctrl->key_shift;
      if( I >= 27 && I <= 108 ) {
         c1 = (int8)I;
         type = (int8)(( c2 == 0 )? ME_NOTEOFF : ME_NOTEON);
      }
      break;
   case 0xb0:     /* Controller message */
      switch( c1 ) {
      case 0x00:
         type = ME_TONE_BANK;
         break;
      case 0x07:
         type = ME_MAINVOLUME;
         break;
      case 0x0B:
         type = ME_EXPRESSION;
         break;
      case 0x40:
         type = ME_SUSTAIN;
         break;

      case 98:    player->nrpn=true;  player->rpn_lsb[ch] = c2;    break;
      case 99:    player->nrpn=true;  player->rpn_msb[ch] = c2;    break;
      case 100:   player->nrpn=false; player->rpn_lsb[ch] = c2;    break;
      case 101:   player->nrpn=false; player->rpn_msb[ch] = c2;    break;

      case 0x06:     /* RPN */
         if( player->nrpn )
            break;
         switch( ( (int16)player->rpn_msb[ch] << 7 ) | (int16)player->rpn_lsb[ch] ) {
         case 0x0000: /* Pitch bend sensitivity */
            type = ME_PITCH_SENS;
            break;
         case 0x3FFF: /* RPN reset */
            /* reset pitch bend sensitivity to 2 */
            type = ME_PITCH_SENS;
            c2 = 2;
            break;
         }
         break;
      }
      break;
   case 0xc0:
      type = ME_PROGRAM;
      break;
   case 0xa0:
      type = ME_KEY_PRESSURE;
      break;
   case 0xe0:
      type = ME_PITCH_WHEEL;
      break;
   case 0xd0:
      type = ME_CHANNEL_PRESSURE;
      break;
   }
   if( type != ME_NONE ) {
      int32 ctime = player->resettime + Ticks2ms( player );
      EventQ_Put( player, ctime, type, ch, c1, c2 );
   }
}

static void SetMIP( uint8 *mip )
{
   int32 I;
   uint32 ch;

   for( I = 0; I < MAX_CHANNEL; I++ )
      midiChannel[I].flag |= CHANNEL_FLAG_MUTE;

   for( I = 0; ; I++ ) {
      ch = mip[I*2];
      if( ch >= MAX_CHANNEL )
         break;
      if( mip[I*2+1] <= MAX_POLYPHONY )
         midiChannel[ch].flag &= ~CHANNEL_FLAG_MUTE;
   }
}

static void SysExEvent( uint8 *m )
{
   switch  ( m[0] ) {
   case 0x7F:                                /* Universal realtime system exclusive */
      if( m[2] == 0x0B && m[3] == 0x01 )
         SetMIP( &m[4] );
      break;
   }
}

static int16 ReadTrack( SmfPlayer *player, MidiTrack *trk )     /* read a track chunk */
{
   static const int8 chantype[] = {
      0, 0, 0, 0, 0, 0, 0, 0,    /* 0x00 through 0x70 */
      2, 2, 2, 2, 1, 1, 2, 0     /* 0x80 through 0xf0 */
   };
   int32 c, c1, type;
   int needed;

   c = egetc( trk );

   if( c == 0xFF ) {                   /* meta event */
      type = egetc( trk );
      msg_read( player, trk );
      MetaEvent( player, type, player->msgbuff );
   }
   else if( c == 0xF0 ) {              /* system exclusive */
      msg_read( player, trk );
      SysExEvent( player->msgbuff );
   }
   else if( c == 0xF7 ) {              /* sysex continuation or arbitrary stuff */
      msg_bypass( trk );
   }
   else {
      if( (c & 0x80) == 0 ) {       /* running status? */
         if( trk->status == 0 )
            return -1;
         trk->running = 1;
      }
      else {
         trk->status = (uint8)c;
         trk->running = 0;
      }

      needed = chantype[ (trk->status>>4) & 0xf ];

      if( needed ) {                /* ie. is it a channel message? */
         if ( trk->running )
            c1 = c;
         else
            c1 = egetc(trk);
         ChannelMessage( player, trk->status, (int8)c1, (int8)((needed>1) ? egetc(trk) : 0) );
      }
   }
   trk->deltatime = ReadVarNum( trk );
   return 0;
}

/* return true if EOF encountered */
static bool midiParse( SmfPlayer *player )
{
   int32       I;
   int32       next_trk;
   uint32      delta;
   MidiTrack   *trk;

   while( !EventQ_Full( player ) ) {
      next_trk = MAX_TRACK;
      delta    = 0x7FFFFF;
      for( I = 0 ; I < player->ntrks; I++ ) {
         trk = &player->midi.smf.tracks[I];
         if( trk->toberead > 0 && trk->deltatime < delta ) {
            delta    = trk->deltatime;
            next_trk = I;
         }
      }
      if( next_trk == MAX_TRACK )      /* No unhandled MIDI data left */
         return true;
      if( delta > 0 ) {
         for( I = 0 ; I < player->ntrks; I++ ) {
            trk = &player->midi.smf.tracks[I];
            if( trk->toberead > 0 )
               trk->deltatime -= delta;
         }
         player->ticks += delta;
      }
      if( ReadTrack( player, &player->midi.smf.tracks[next_trk] ) == -1 ) {
         return true;
      }
   }
   return false;
}

#if defined( CMIDI_SUPPORT )
/* ----------------------------------------------------------------- */
static int32 cmidi_getBits( SmfPlayer *player, int32 len )
{
   int32 cache = player->midi.cmi.cache;
   int32 bits = player->midi.cmi.bits;

   if( len > bits ) {
      cache = (cache<<8) + *player->midi.cmi.ptr++;
      bits += 8;
      player->midi.cmi.len--;
   }
   bits -= len;
   player->midi.cmi.cache = cache & ((1<<bits)-1);
   player->midi.cmi.bits = bits;
   return (cache >> bits);
}

void cmidi_Parse( SmfPlayer *player )
{
   int32 dtime = 0;
   int32 c1, c2;
   uint8 type;

   while( !EventQ_Full(player) ) {
      if( player->midi.cmi.len <= 0 )
         break;
      type = ME_NONE;
      c1 = 0; c2 = 0;
      switch( cmidi_getBits( player, 2 ) ) {
      case 0:
         c1 = cmidi_getBits( player, 4 ) + (player->midi.cmi.octave<<4);
         c2 = cmidi_getBits( player, 5 ) << 2;
         c1 = c1 + player->ctrl->key_shift;
         if( c1 >= 27 && c1 <= 108 )
            type = ME_NOTEON;
         break;
      case 1:
         c1 = cmidi_getBits( player, 4 ) + (player->midi.cmi.octave<<4);
         c1 = c1 + player->ctrl->key_shift;
         if( c1 >= 27 && c1 <= 108 )
            type = ME_NOTEOFF;
         break;
      case 2:
         if( !cmidi_getBits( player, 1 ) )
            player->midi.cmi.channel = cmidi_getBits( player, 4 );
         else
            player->midi.cmi.octave = cmidi_getBits( player, 3 );
         break;
      case 3:
         if( !cmidi_getBits( player, 1 ) ) {      /* dtime */
            dtime = (cmidi_getBits( player,4)+1) * 20;
         }
         else {
            switch( cmidi_getBits( player,2) ) {
            case 0:                                /* main volume */
               c2 = cmidi_getBits( player, 5 ) << 2;
               type = ME_MAINVOLUME;
               break;
            case 1:                                /* pitch wheel */
               c2 = cmidi_getBits( player, 7 );
               type = ME_PITCH_WHEEL;
               break;
            case 2:
               switch( cmidi_getBits( player,3) ) {
               case 0:                             /* sustain */
                  c2 = cmidi_getBits( player, 5 ) << 2;
                  type = ME_SUSTAIN;
                  break;
               case 1:                             /* pan */
                  cmidi_getBits( player, 5 );
                  break;
               case 2:                             /* program */
                  c1 = cmidi_getBits( player, 7 );
                  type = ME_PROGRAM;
                  break;
               case 3:                             /* channel pressure */
                  c1 = cmidi_getBits( player, 5 ) << 2;
                  type = ME_CHANNEL_PRESSURE;
                  break;
               case 4:                             /* key pressure */
                  c1 = cmidi_getBits( player,4) + (player->midi.cmi.octave<<4);
                  c2 = cmidi_getBits( player,5) << 2;
                  type = ME_KEY_PRESSURE;
                  break;
               case 5:                             /* tone bank */
                  c2 = cmidi_getBits( player, 7 );
                  type = ME_TONE_BANK;
                  break;
               case 6:                             /* modulation wheel */
                  cmidi_getBits( player, 7 );
                  break;
               case 7:                             /* channel expression */
                  c2 = cmidi_getBits( player, 5 ) << 2;
                  type = ME_EXPRESSION;
                  break;
               }
               break;
               case 3:
                  switch( cmidi_getBits( player,3) ) {
                  case 0:                             /* pitch sense */
                     c2 = cmidi_getBits( player, 7 );
                     type = ME_PITCH_SENS;
                     break;
                  case 1:                             /* dtime(10bits) */
                     c1 = cmidi_getBits( player, 6 );
                     c1 = (c1 << 4) + cmidi_getBits( player, 4 );
                     dtime = (c1+1) * 20;
                     break;
                  default:
                     ASSERT(false);
                  }
                  break;
            }
         }
         break;
      default:
         ASSERT( false );
      }
      if( type != ME_NONE ) {
         player->resettime += dtime;
         EventQ_Put( player, player->resettime, type, player->midi.cmi.channel, c1, c2 );
         dtime = 0;
      }
   }
}

#endif
/* ------------------------------------------------------------------- */
/*  Functions to be called while processing the MIDI file.             */
/* ------------------------------------------------------------------- */
static void ME_None( MidiEvent *me )
{
   (void)me;
}
/* ----------------------------------------------------------------- */
static void ME_NoteOff( MidiEvent *me )
{
   int I = 0;
   ToneGenerator *tg;
   MidiChannel *chan = &midiChannel[me->ch];

   if( chan->flag & CHANNEL_FLAG_MUTE )
      return;

   if( chan->program == 0x7C && chan->bank == 0x7906 ) {
      if( chan->flag & CHANNEL_FLAG_VIBE ) {
         chan->flag &= ~CHANNEL_FLAG_VIBE;
         mediaHandler( (void *)MEDIA_VIBRATOR_OFF );   /* turn on vibrator */
      }
      return;
   }

   do {
      tg = &toneGen[I];
      if( (tg->state & (EG_ATTACK|EG_HOLD|EG_DECAY|EG_SUSTAIN)) &&
         tg->channel == me->ch && tg->pitch == me->c1 ) {
         SWSYN_CloseNote( tg );
         return;
      }
   } while( ++I < MAX_POLYPHONY );
}

static void ME_NoteOn( MidiEvent *me )
{
   int I = 0;
   int lowest = -1;
   ToneGenerator *tg;
   MidiChannel *chan = &midiChannel[me->ch];

   if( chan->flag & CHANNEL_FLAG_MUTE )
      return;

   if( chan->program == 0x7C && chan->bank == 0x7906 ) {
      if( (chan->flag & CHANNEL_FLAG_VIBE) == 0 ) {
         chan->flag |= CHANNEL_FLAG_VIBE;
         mediaHandler( (void *)MEDIA_VIBRATOR_ON );   /* turn on vibrator */
      }
      return;
   }

   if( current_polyphony < polyphony_limit ) {
      do {
         tg = &toneGen[I];
         if( tg->state == EG_FREE )
            lowest = I;
         else if( tg->channel == me->ch &&
            (tg->pitch == me->c1 || (midiChannel[tg->channel].flag & CHANNEL_FLAG_MONO)) && tg->state != EG_RELEASE ) {
            tg->state = EG_DIE;
            tg->envelope_increment = -(MAX_ENVELOPE / 16);
         }
      } while( ++I < MAX_POLYPHONY );

      ASSERT( lowest != -1 );
      tg             = &toneGen[lowest];
      tg->channel    = me->ch;
      tg->pitch      = me->c1;
      tg->velocity   = me->c2;
      SWSYN_StartNote( tg );
      return;
   }
   /* Look for the decaying note with the lowest volume */
   lowest = SWSYN_FindWeakestNote();
   if( lowest != -1 ) {
      tg             = &toneGen[lowest];
      SWSYN_KillNote( tg );
      tg->channel    = me->ch;
      tg->pitch      = me->c1;
      tg->velocity   = me->c2;
      SWSYN_StartNote( tg );
   }
}

/* ----------------------------------------------------------------- */

static void ME_Key_Pressure( MidiEvent *me )
{
   ToneGenerator *tg;
   int I = 0;
   do {
      tg = &toneGen[I];
      if( tg->channel == me->ch && (tg->state & (EG_ATTACK|EG_HOLD|EG_DECAY) ) && tg->pitch == me->c1 ) {
         tg->velocity = me->c2;
         SWSYN_RecomputeAmplitude( tg );
         return;
      }
   } while( ++I < MAX_POLYPHONY );
}

static void ME_Volume( MidiEvent *me )
{
   midiChannel[me->ch].volume = me->c2;
   SWSYN_AdjustVolume( me->ch );
}

static void ME_Expression( MidiEvent *me )
{
   midiChannel[me->ch].expression = me->c2;
   SWSYN_AdjustVolume( me->ch );
}

static void ME_Sustain( MidiEvent *me )
{
   midiChannel[me->ch].sustain = me->c2;
   if( !me->c2 ) {
      ToneGenerator *tg;
      int I = 0;
      do {
         tg = &toneGen[I];
         if( tg->state == EG_SUSTAIN && tg->channel == me->ch ) {
            tg->state = EG_DIE;
            tg->envelope_increment = -(MAX_ENVELOPE / 16);
         }
      } while( ++I < MAX_POLYPHONY );
   }
}

static int32 bend( int32 pb )
{
   int32 frac = (pb >> 5) & 0xFF;

   pb = pb >> 13;
   return (bendTable[pb] + ((bendTable[pb+1]-bendTable[pb]) * frac >> 8)) >> 6;
}

static void ME_Pitch_Wheel( MidiEvent *me )
{
   int32 I;
   ToneGenerator *tg;
   MidiChannel *chan = &midiChannel[me->ch];

   I = (int16)(((int32)me->c1 + ((int32)me->c2 << 7)) - 0x2000);
   if( I == 0 )
      chan->pitchbend = 0;
   else if( I > 0 )
      chan->pitchbend = bend( chan->pitchsens * I );
   else
      chan->pitchbend = -bend( chan->pitchsens * (-I) );

   I = 0;
   do {
      tg = &toneGen[I];
      if( tg->state != EG_FREE && tg->channel == me->ch )
         SWSYN_RecomputeFrequency( tg );
   } while( ++I < MAX_POLYPHONY );
}

static void ME_Pitch_Sense( MidiEvent *me )
{
   midiChannel[me->ch].pitchsens = (int16)me->c2;
}

static void ME_Program( MidiEvent *me )
{
   midiChannel[me->ch].program = me->c1;
}

static void ME_Channel_Pressure( MidiEvent *me )
{
   ToneGenerator *tg;
   int I = 0;
   do {
      tg = &toneGen[I];
      if( tg->channel == me->ch && (tg->state & (EG_ATTACK|EG_HOLD|EG_DECAY) ) ) {
         tg->velocity = me->c1;
         SWSYN_RecomputeAmplitude( tg );
      }
   } while( ++I < MAX_POLYPHONY );
}

static void ME_Bank( MidiEvent *me )
{
   midiChannel[me->ch].bank = me->c2;
}

/* Process the All Notes Off event */
static void ME_All_Notes_Off( MidiEvent *me )
{
   int I = 0;
   ToneGenerator *tg;

   do {
      tg = &toneGen[I];
      if( tg->channel == me->ch &&
         tg->state & (EG_ATTACK|EG_HOLD|EG_DECAY|EG_SUSTAIN) ) {
         if( midiChannel[me->ch].sustain )
            tg->state = EG_SUSTAIN;
         else {
            tg->state = EG_RELEASE;
            tg->envelope_increment = tg->wt->release;
         }
      }
   } while( ++I < MAX_POLYPHONY );
}

/* Process the All Sounds Off event */
static void ME_All_Sounds_Off( MidiEvent *me )
{
   ToneGenerator *tg;
   int I = 0;
   do {
      tg = &toneGen[I];
      if( tg->channel == me->ch && tg->state != EG_FREE ) {
         tg->state = EG_DIE;
         tg->envelope_increment = -(MAX_ENVELOPE / 16);
      }
   } while( ++I < MAX_POLYPHONY );
}

static void ME_Reset_Controllers( MidiEvent *me )
{
   SWSYN_ResetControllers( me->ch );
}

typedef void (*MidiEventHandler)(MidiEvent *note);

static const MidiEventHandler  midiEventHandler[] = {
   ME_None,
   ME_NoteOn,
   ME_NoteOff,
   ME_Key_Pressure,
   ME_Volume,
   ME_Sustain,
   ME_Expression,
   ME_Pitch_Wheel,
   ME_Pitch_Sense,
   ME_Program,
   ME_Channel_Pressure,
   ME_Bank,
   ME_All_Notes_Off,
   ME_All_Sounds_Off,
   ME_Reset_Controllers,
   ME_None,
   ME_None
};
/* ------------------------------------------------------------------- */
static bool smfComputeData( SmfPlayer *player )
{
   MidiEvent   *note;

   CONFIRM_WRITE_SPACE();

   if( EventQ_Empty(player) ) {
      if( SWSYN_ToneGenIdle() )
         return true;
   }
   else { /* !EventQ_Empty() */
      do {
         bool flag = (bool)(EventQ_Count(player) >= EVENT_Q_SIZE/2);
         while( !EventQ_Empty(player) ) {
            note = EventQ_Peek(player);
            if( note->time - player->synth_time >= BLOCK_PERIOD )
               break;
            midiEventHandler[note->type]( note );
            EventQ_Consume(player);
         }
         if( flag && EventQ_Empty(player) ) {
            if( player->ntrks )
               midiParse( player );
#if defined( CMIDI_SUPPORT )
            else
               cmidi_Parse( player );
#endif
            continue;
         }

         SWSYN_Synthesize( false );
         // smfSndMix();
         SWSYN_Agc( player->ctrl->max_swing );
         player->synth_time += BLOCK_PERIOD;
         player->output_func( audio_buffer, BLOCK_SAMPLE_NO );
         if( !EventQ_Full(player) ) {
            if( player->ntrks )
               midiParse( player );
#if defined( CMIDI_SUPPORT )
            else
               cmidi_Parse( player );
#endif
         }

         CONFIRM_WRITE_SPACE();
      } while( !EventQ_Empty(player) );
   }

   if( EventQ_Empty(player) ) {   /* EventQ_Empty, waiting for the end of the song playback */
      do {
         SWSYN_Synthesize( true );
         // smfSndMix();
         SWSYN_Agc( player->ctrl->max_swing );
         player->synth_time += BLOCK_PERIOD;
         player->output_func( audio_buffer, BLOCK_SAMPLE_NO );
         CONFIRM_WRITE_SPACE();
      } while( !SWSYN_ToneGenIdle() );
      if( SWSYN_ToneGenIdle() )
         return true;
   }
   return false;
}

bool smfPlay( SmfPlayer *player, void (*output)(const int16 *buf, int32 count) )
{
   uint32      I;
   const uint8 *ptr;
   MidiTrack   *trk;
   const uint8 *midifile = player->ctrl->param.smf.smffile;
   const uint8 *fileend = midifile + player->ctrl->param.smf.filesize;

   EventQ_Init( player );
   player->repeats      = (int8)player->ctrl->param.smf.repeats;
   player->output_func  = output;
   player->synth_time   = 0;
   player->resettime    = 0;

   SWSYN_ResetMIDI();

#if defined( CMIDI_SUPPORT )
   if( midifile[0] == 'M' && midifile[1] == 'T' && midifile[2] == 'K' && midifile[3] == '\x14' ) {
      player->ntrks = 0;
      player->midi.cmi.bits = 0;
      player->midi.cmi.cache = 0;
      player->midi.cmi.channel = 0;
      player->midi.cmi.octave = 0;
      player->midi.cmi.len = get32bit( midifile + 4 );
      player->midi.cmi.ptr = midifile + 8;
      cmidi_Parse( player );
      smfComputeData( player );
      return true;
   }
#endif

   if( midifile[0] == 'R' && midifile[1] == 'I' && midifile[2] == 'F' && midifile[3] == 'F' )
      midifile += 20;

   if( midifile[0] != 'M' || midifile[1] != 'T' || midifile[2] != 'h' || midifile[3] != 'd' )
      return false;

   if( (I  = get16bit( &midifile[10] )) > MAX_TRACK )
      I = MAX_TRACK;
   player->ntrks = I;
   player->division = get16bit( &midifile[12] );

   ptr = (const uint8 *)&midifile[8 + get32bit(&midifile[4])];
   for( I = 0 ; I < player->ntrks; I++ ) {
      if( ptr[0] != 'M' || ptr[1] != 'T' || ptr[2] != 'r' || ptr[3] != 'k' )
         break;
      trk            = &player->midi.smf.tracks[I];
      trk->toberead  = get32bit( &ptr[4] );
      trk->ptr       = &ptr[8];
      if( trk->ptr + trk->toberead > fileend )
         trk->toberead = (uint32)(fileend - trk->ptr);
      ptr            = ptr + trk->toberead + 8;
      trk->deltatime = ReadVarNum( trk );
      trk->running   = 0;
      trk->status    = 0;
   }
   player->ntrks          = I;
   player->ticks          = 0;
   player->tempo          = 500;
   player->nrpn           = false;

   midiParse( player );

   smfComputeData( player );

   return true;
}

/* ------------------------------------------------------------------------------ */
static void smfWritePCM(const int16 *buf, int32 count)
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

static void smfHandler( void *data )     /* This function works in L1Audio Task */
{
   Media_Event event = (Media_Event)(int32)data;
   SmfPlayer *player = smf.player;

   if( event == MEDIA_END ) {
      free_ctrl_buffer( smf.player );
      smf.player = (SmfPlayer *)0;
      SWSYN_UnloadWavetable();
      mediaHandler( data );
   }
   else if( event == MEDIA_DATA_REQUEST) {
      if( player->ctrl->end_status != MEDIA_TERMINATED && player->repeats >= 0 ) {
         if( smfComputeData( player ) ) {
            if( player->repeats == 1 ) {
               player->repeats = -1;
               Media_DataFinished();
            }
            else {
               if( player->repeats != 0 )
                  player->repeats--;
               smfPlay( player, smfWritePCM );
            }
         }
      }
   }
}

void smfInit( uint16 aud_id )
{
   smf.aud_id = aud_id;
   smf.player = (SmfPlayer *)0;
   L1Audio_SetEventHandler( smf.aud_id, smfHandler );
}

void smfSetEvent( Media_Event event )
{
   L1Audio_SetEvent( smf.aud_id, (void *)event );
}

Media_Status smfStart( mediaControl *ctrl )
{
   SWSYN_ResetAgc( 2048, 200, 10 );

   ASSERT( smf.player == (SmfPlayer *)0 )
   smf.player = (SmfPlayer *)get_ctrl_buffer( sizeof(SmfPlayer) );
   smf.player->ctrl = ctrl;

   SWSYN_LoadWavetable( Wavetable );

   if( smfPlay( smf.player, smfWritePCM ) == true ) {
      SWSYN_PcmStart( ctrl );
      return MEDIA_SUCCESS;
   }
   else {
      SWSYN_UnloadWavetable();
      free_ctrl_buffer( smf.player );
      smf.player = (SmfPlayer *)0;
      return MEDIA_FAIL;
   }
}

void smfStop( void )
{
   SWSYN_PcmStop( smf.player->ctrl );
   free_ctrl_buffer( smf.player );
   smf.player = (SmfPlayer *)0;
   SWSYN_UnloadWavetable();
}

/* ------------------------------------------------------------------------------ */
/* SWSYN thumb code part                                                          */
/* ------------------------------------------------------------------------------ */
void SWSYN_LoadWavetable( const void *wt )
{
   int I;
   uint32 offset = 0;
   const int16 *wavptr;
   uint16 melCount, perCount;
   int16 temp;
   const uint8 *wavtab = (const uint8 *)wt;

   ASSERT( ((uint32)wavtab & 3) == 0 );

   freqTable      = (const uint16 *)&wavtab[0];
   bendTable      = (const uint32 *)&wavtab[256];
   sineTable      = (const int16 *)&wavtab[768];
   attVolTab      = (const uint16 *)&wavtab[1280];
   expVolTab      = (const uint16 *)&wavtab[1792];
   wavTable       = (const int16 *)&wavtab[2304];

   melodicInst = (const int16 **)get_ctrl_buffer( sizeof(const int16*)*128 );
   percussiveInst = (const int16 **)get_ctrl_buffer( sizeof(const int16*)*128 );
   midiChannel = (MidiChannel*)get_ctrl_buffer( sizeof(MidiChannel)*MAX_CHANNEL );
   toneGen = (ToneGenerator*)get_ctrl_buffer( sizeof(ToneGenerator)*MAX_POLYPHONY );

   SWSYN_ResetMIDI();
   for( I = 0; I < 128; I++ ) {
      melodicInst[I] = (const int16 *)0;
      percussiveInst[I] = (const int16 *)0;
   }
   /* searching for the beginning of instrument table */
   while( wavTable[offset] != 0 ) {
      I = wavTable[offset];
      if( I < 0 )
         I = (-I + 1) / 2;
      offset = offset + 1 + I;
   }
   while( wavTable[offset] == 0 )
      offset++;
   /* melodic instrument begins */
   wavptr = &wavTable[offset];
   melCount = *wavptr++;
   perCount = *wavptr++;
   for( I = 0; I < melCount; I++ ) {
      temp = (int16)*wavptr++;
      melodicInst[temp] = wavptr + 1;
      temp = (int16)*wavptr;
      if( temp < 0 )    /* alias instrument number */
         wavptr++;
      else              /* waveform count */
         wavptr += (INS_TABLE_SIZE * temp + 1);
   }
   /* percussive instrument begins */
   for( I = 0; I < perCount; I++ ) {
      temp = *wavptr++;
      percussiveInst[temp] = wavptr + 1;
      temp = (int16)*wavptr;
      if( temp < 0 )    /* alias instrument number */
         wavptr++;
      else              /* waveform count */
         wavptr += (INS_TABLE_SIZE + 1);
   }
}

void SWSYN_UnloadWavetable( void )
{
   if( melodicInst == (const int16**)0 )
      return;
   free_ctrl_buffer( melodicInst );
   free_ctrl_buffer( percussiveInst );
   free_ctrl_buffer( midiChannel );
   free_ctrl_buffer( toneGen );
   melodicInst = (const int16**)0;
}

/* ------------------------------------------------------------------- */

void SWSYN_RecomputeAmplitude( ToneGenerator *tg )
{
   MidiChannel *chan = &midiChannel[tg->channel];
   register uint32 tempamp;

   tempamp = (int32)tg->velocity * chan->volume * chan->expression >> 7;
   tempamp = (tempamp * tempamp >> 15) * tg->wt_volume >> 8;
   tg->left_amp = tempamp;
}

void SWSYN_AdjustVolume( int8 ch )
{
   ToneGenerator *tg;
   int I = 0;
   do {
      tg = &toneGen[I];
      if( tg->channel == ch && (tg->state & (EG_ATTACK|EG_HOLD|EG_DECAY|EG_SUSTAIN)) )
         SWSYN_RecomputeAmplitude( tg );
   } while( ++I < MAX_POLYPHONY );
}
/* ------------------------------------------------------------------- */

void SWSYN_RecomputeFrequency( ToneGenerator *tg )
{
   if( tg->channel != 9 ) {
   	int32 freq;
      MidiChannel *chan = &midiChannel[tg->channel];

      if( chan->pitchbend == 0 )
         freq = tg->orig_freq;
      else if( chan->pitchbend > 0 )
         freq = chan->pitchbend * tg->orig_freq >> 10;
      else /* chan->pitchbend < 0 */
         freq = (tg->orig_freq << 10) / (-chan->pitchbend);

      tg->sample_increment = (freq * (tg->wt->freqRate>>4)) / (PLAY_RATE * FREQ_FACTOR >> 4);
   }
   else
      tg->sample_increment = tg->wt->freqRate / PLAY_RATE;
}

void SWSYN_ResetControllers( int ch )
{
   midiChannel[ch].volume           = 90;
   midiChannel[ch].expression       = 127;
   midiChannel[ch].sustain          = 0;
   midiChannel[ch].pitchbend        = 0;
}

void SWSYN_ResetMIDI( void )
{
   int I;
   for( I = 0; I < MAX_CHANNEL; I++ ) {
      SWSYN_ResetControllers( I );
      midiChannel[I].bank          = 0;
      midiChannel[I].program       = 0;
      midiChannel[I].flag          = 0;
      midiChannel[I].pitchsens     = 2;
   }
   for( I = 0; I < MAX_POLYPHONY; I++ )
      toneGen[I].state = EG_FREE;
   current_polyphony = 0;
}

void SWSYN_ResetAgc( int32 init_gain, int16 init_speed, int16 steady_speed )
{
   agc_state         = AGC_INIT_STATE;
   agc_gain          = init_gain;
   agc_init_speed    = init_speed;
   agc_steady_speed  = steady_speed;
}

void SWSYN_StartNote( ToneGenerator *tg )
{
   int I;
   MidiChannel *chan = &midiChannel[tg->channel];
   const uint16 *inst;

   tg->sample_offset = 0;
   tg->tremolo_offset = 64 << 8;    /* starting phase = pi/2 */
   tg->vibrato_offset = 0;
   if( tg->channel != 9 ) {         /* melodic instrument */
      if( (inst = (const uint16 *)melodicInst[chan->program]) != 0 ) {
         if( (I = (int16)inst[-1]) < 0 ) {
            inst = (const uint16 *)melodicInst[-I - 1];
            if( inst == 0 )
               return;
         }
         for( I = 0; I < 10; I++, inst += INS_TABLE_SIZE ) {
            if( tg->pitch <= inst[0] )
               break;
         }
         ASSERT( I < 10 );
         tg->wt_volume     = (int16)inst[1];
         tg->wt            = (WT_Param *)&inst[2];
         tg->wt_table      = &wavTable[tg->wt->tab_off];
         tg->compressed    = (bool)(( tg->wt_table[-1] < 0 )? true : false);
         tg->orig_freq     = freqTable[tg->pitch];
         SWSYN_RecomputeFrequency( tg );
         SWSYN_RecomputeAmplitude( tg );
         current_polyphony++;
         if( tg->wt->attack != 0 ) {
            tg->state = EG_ATTACK;
            tg->envelope_volume = 0;
            tg->envelope_increment = tg->wt->attack;
         }
         else if( tg->wt->hold != 0 ) {
            tg->state = EG_HOLD;
            tg->holdTime = 0;
            tg->envelope_volume = MAX_ENVELOPE;
            tg->envelope_increment = 0;
         }
         else {
            tg->state = EG_DECAY;
            tg->envelope_volume = MAX_ENVELOPE;
            tg->envelope_increment = tg->wt->decay;
         }
      }
   }
   else {   /* percussive instrument */
      if( (inst = (const uint16 *)percussiveInst[tg->pitch]) != 0 ) {
         if( (I = (int16)inst[-1]) < 0 ) {
            inst = (const uint16 *)percussiveInst[-I];
            if( inst == 0 )
               return;
         }
         tg->wt_volume        = (int16)inst[1];
         tg->wt               = (WT_Param *)&inst[2];
         tg->wt_table         = &wavTable[tg->wt->tab_off];
         tg->compressed       = (bool)(( tg->wt_table[-1] < 0 )? true : false);
         tg->envelope_volume  = MAX_ENVELOPE;
         SWSYN_RecomputeFrequency( tg );
         SWSYN_RecomputeAmplitude( tg );
         current_polyphony++;
         if( tg->wt->loopLength == 0 ) {
            tg->state = EG_SUSTAIN;
            tg->envelope_increment = 0;
         }
         else if( tg->wt->hold != 0 ) {
            tg->state = EG_HOLD;
            tg->holdTime = 0;
            tg->envelope_increment = 0;
         }
         else {
            tg->state = EG_DECAY;
            tg->envelope_increment = tg->wt->decay;
         }
      }
   }
}

void SWSYN_CloseNote( ToneGenerator *tg )
{
   if( (tg->state & (EG_RELEASE|EG_DIE)) || tg->state == EG_FREE )
      return;
   if( midiChannel[tg->channel].sustain == 0 ) {
      if( tg->state == EG_ATTACK ) {
         uint32 temp = tg->envelope_volume >> 15;
         uint32 temp2 = attVolTab[temp];
         while( expVolTab[temp] < temp2 )
            temp++;
         tg->envelope_volume = ((temp-1) << 15) + (tg->envelope_volume&0x7FFF);
      }
      tg->state = EG_RELEASE;
      tg->envelope_increment = tg->wt->release;
   }
}

void SWSYN_KillNote( ToneGenerator *tg )
{
   tg->state = EG_FREE;
   current_polyphony--;
   ASSERT( current_polyphony >= 0 );
}

int16 SWSYN_FindWeakestNote( void )
{
   int32 I = 0, lowest = -1;
   int32 lv = 0x7FFFFFFF;
   ToneGenerator *tg;

   do {
      tg = &toneGen[I];
      if( tg->state & (EG_SUSTAIN|EG_RELEASE|EG_DIE) ) {
         if( tg->left_mix < lv ) {
            lv = tg->left_mix;
            lowest = I;
         }
      }
   } while( ++I < MAX_POLYPHONY );
   return lowest;
}

bool SWSYN_ToneGenIdle( void )
{
   return (bool)( current_polyphony == 0 );
}
/* ------------------------------------------------------------------- */
void SWSYN_Synthesize( bool end_flag )
{
   int16 I;
   int32 *ptr32 = (int32*)audio_buffer;
   ToneGenerator *tg;

   if( current_polyphony > polyphony_limit ) {
      if( (I = SWSYN_FindWeakestNote()) != -1 ) {
         toneGen[I].state = EG_DIE;
         toneGen[I].envelope_increment = -(MAX_ENVELOPE / 16);
      }
   }

   /* clean the output buffer */
   for( I = 0; I < BLOCK_SAMPLE_NO; I++ )
      *ptr32++ = 0;

   I = 0;
   do {
      tg = &toneGen[I];
      if( tg->state != EG_FREE ) {
         if( end_flag && tg->state == EG_SUSTAIN ) {
            tg->state = EG_RELEASE;
            tg->envelope_increment = tg->wt->release;
         }
         SWSYN_ResampleVoice( tg, (int32*)audio_buffer );
      }
   } while( ++I < MAX_POLYPHONY );
}

/* ------------------------------------------------------------------- */
/*  MCU/DSP PCM interface                                              */
/* ------------------------------------------------------------------- */
static int32 SWSYN_WriteIDMA( mediaControl *ctrl, const uint16 *buf, int32 len )
{
   int32 I, count;
   uint16 rb_w, data;

   rb_w = *DSP_PCM_W;

   do {
      I = (int32)*DSP_PCM_R;
   } while( I != (int32)*DSP_PCM_R );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += ctrl->dsp_rb_size;

   if( I < len )
      len = I;

   if( len == 0 )
      return 0;

   count = (int32)(ctrl->dsp_rb_size - rb_w);
   if( count > len )
      count = len;

   data = *buf++;
   *DSP_DM_ADDR(2, ctrl->dsp_rb_base + rb_w) = data;
   for( I = 1; I < count; I++ ) {
      data = *buf++;
      *IDMA_SHORT_ADDR = data;
   }

   rb_w += (uint16)count;
   if( rb_w >= ctrl->dsp_rb_size )
      rb_w = 0;
   *DSP_PCM_W = rb_w;

   count = len - count;
   if( count > 0 ) {
      data = *buf++;
      *DSP_DM_ADDR(2, ctrl->dsp_rb_base + rb_w) = data;
      for( I = 1; I < count; I++ ) {
         data = *buf++;
         *IDMA_SHORT_ADDR = data;
      }

      *DSP_PCM_W = rb_w + (uint16)count;
   }

   return len;
}

static void SWSYN_WriteToDSP( mediaControl *ctrl )
{
   int32 I, count;

   count = mediaGetDataCount();
   if( count == 0 ) {
      if( ctrl->eof ) {
         ctrl->end_status = MEDIA_END;
         if( *DSP_PCM_CTRL == 8 )
            *DSP_PCM_CTRL = 0x10;
      }
      return;
   }
   I = ctrl->rb_size - ctrl->read;
   if( I > count )
      I = count;
   count -= I;

   I = SWSYN_WriteIDMA( ctrl, &ctrl->rb_base[ctrl->read], I );
   ctrl->read += I;
   if( ctrl->read >= ctrl->rb_size )
      ctrl->read = 0;

   if( count > 0 ) {
      I = SWSYN_WriteIDMA( ctrl, &ctrl->rb_base[ctrl->read], count );
      ctrl->read += I;
   }
}

void SWSYN_PcmPlaybackHisr( mediaControl *ctrl )
{
   if( ctrl->end_status == MEDIA_TERMINATED )
      return;
   if( ctrl->end_status == MEDIA_END && *DSP_PCM_CTRL == 8 ) {
      *DSP_PCM_CTRL = 0x10;
      return;
   }
   if( *DSP_PCM_CTRL == 0 ) {           /* DSP returns to idle state */
#if (PLAY_RATE == 8000)
      AM_PCM8K_PlaybackOff( false );
#elif defined( MT6205B )
      AM_PCM16K_PlaybackOff( false );
#else
      AM_AudioPlaybackOff( false );
#endif
      if( ctrl->format == MEDIA_FORMAT_SMF )
         smfSetEvent( MEDIA_END );
      else if( ctrl->format == MEDIA_FORMAT_IMELODY )
         imySetEvent( MEDIA_END );
      return;
   }
   if( *DSP_PCM_CTRL == 2 ) {           /* DSP gives IDMA address and length */
      ctrl->dsp_rb_base = *DSP_PCM_W;
      ctrl->dsp_rb_size = *DSP_PCM_R;
      ctrl->dsp_rb_end = ctrl->dsp_rb_base + ctrl->dsp_rb_size;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
   }
   SWSYN_WriteToDSP( ctrl );
   if( *DSP_PCM_CTRL == 2 )
      *DSP_PCM_CTRL = 4;

   if( !ctrl->eof && mediaGetFreeSpace() >= BLOCK_SAMPLE_NO ) {
      if( ctrl->format == MEDIA_FORMAT_SMF )
         smfSetEvent( MEDIA_DATA_REQUEST );
      else if( ctrl->format == MEDIA_FORMAT_IMELODY )
         imySetEvent( MEDIA_DATA_REQUEST );
   }
}

void SWSYN_PcmStart( mediaControl *ctrl )
{
   uint16 I;
   ctrl->end_status = MEDIA_NONE;

#if (PLAY_RATE == 8000)
   AM_PCM8K_PlaybackOn();
#elif defined( MT6205B )
   AM_PCM16K_PlaybackOn();
#else
#if defined( DSP_WT_SYN )
   DSP_DynamicDownload( DDID_WAVETABLE );
#endif
   AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ASP_FS_16K );
   *DSP_PCM_MS = 0;      /* Mono */
#endif

   *DSP_PCM_CTRL = 1;
   for( I = 0; ; I++ ) {
      if( *DSP_PCM_CTRL == 8 || ctrl->end_status == MEDIA_END )
         break;
      ASSERT( I < 20 );
      kal_sleep_task( 2 );
   }
}

void SWSYN_PcmStop( mediaControl *ctrl )
{
   uint16 I, ctl;

   ctrl->end_status = MEDIA_TERMINATED;

   for( I = 0; ; I++ ) {
      ctl = *DSP_PCM_CTRL;
      if( ctl == 0 )                /* DSP returns to idle state */
         break;
      if( ctl == 8 ) {
         *DSP_PCM_CTRL = WAV_ABORT_STATE;       /* give ABORT command to the DSP */
      }
      ASSERT( I < 40 );
      kal_sleep_task( 2 );
   }
#if (PLAY_RATE == 8000)
   AM_PCM8K_PlaybackOff( true );
#elif defined( MT6205B )
   AM_PCM16K_PlaybackOff( true );
#else
   AM_AudioPlaybackOff( true );
#endif
}

/* ------------------------------------------------------------------------------ */
#else
char dummy_smf_c;    /* define a dummy variable to avoid warning message */
#endif /*  SW_SYN_8K || SW_SYN_16K  */


