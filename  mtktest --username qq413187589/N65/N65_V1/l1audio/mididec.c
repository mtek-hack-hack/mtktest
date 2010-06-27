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
 * mididrv.c
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   This is the software module for playing MIDI
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#if defined( SIN_WAV_SYN )

#include "media.h"
#include "gmi.h"

#define  MAX_TRACK   32
#define  MAX_CHANNEL 16
#define  NOTE_Q_SIZE 128
#define  MSG_SIZE    64

#define  CHANNEL_FLAG_MUTE    0x01
#define  CHANNEL_FLAG_PEDAL   0x02
#define  CHANNEL_FLAG_VIBE    0x04

/* --------------------------------------------- */
/*  Declarations of Data Types                   */
/* --------------------------------------------- */
typedef struct {
   uint32      deltatime;
   uint32      toberead;
   const uint8 *ptr;
   uint8       running;
   uint8       status;
} MidiTrack;

typedef struct {
   int16    bank;
   int8     program;
   int8     volume;
   int8     pan;
   int8     expression;
   uint8    flag;
} MidiChannel;

typedef struct {
   int32    start_time;
   int32    end_time;
   int8     chan;
   int8     pitch;
   int8     velocity;
   int8     prog;
   int8     pan;
} MidiNote;

typedef struct {
   int32    start_time;
   int32    end_time;
   uint16   amp;
   int8     pitch;
   int8     prog;
} MidiEvNote;
 
typedef struct {
   uint16   head;
   uint16   count;
   MidiNote buf[NOTE_Q_SIZE];
} NoteQueue;

/* --------------------------------------------- */
/*  Declarations of Global variables             */
/* --------------------------------------------- */
static struct {
   uint8       repeats;
   bool        bad_flag;
   int32       currtime;               /* current time in delta-time units */
   int32       tempo;                  /* the default tempo is 120 beats/minute */
   uint16      format;
   uint16      ntrks;
   int16       division;
   MidiTrack   tracks[MAX_TRACK];
   MidiChannel channel[MAX_CHANNEL];
   NoteQueue   noteq;
   MidiNote    *latest_note[MAX_DSP_POLYPHONY];
   uint8       msgbuff[MSG_SIZE];      /* message buffer */
   int16       msgindex;               /* index of next available location in Msg */
   MidiEvNote  ev_note[MAX_DSP_POLYPHONY];
   uint16      polyphony;
   uint16      scalefactor;
   Media_SMF_Param   *msp;
} midi;

/* ------------------------------------------------------------------- */
#define  NoteQ_Empty()     (midi.noteq.count==0)
#define  NoteQ_Full()      (midi.noteq.count==NOTE_Q_SIZE)
#define  NoteQ_Peek(i)     (&midi.noteq.buf[(midi.noteq.head + i) & (NOTE_Q_SIZE-1)])

static void NoteQ_Init(void)
{
   int16 I;

   midi.noteq.head = 0;
   midi.noteq.count = 0;
   for( I = 0; I < MAX_DSP_POLYPHONY; I++ )
      midi.latest_note[I] = (MidiNote *)0;
}

static void NoteQ_Put( int32 time, int8 ch, int8 pitch, int8 vel, int8 prog, int8 pan )
{
   int16 I;
   MidiNote *nt, *note, **earliest_note = (MidiNote **)0;

   nt             = &midi.noteq.buf[(midi.noteq.head + midi.noteq.count) & (NOTE_Q_SIZE-1)];
   nt->start_time = time;
   nt->end_time   = 0;
   nt->chan       = ch;
   nt->pitch      = pitch;
   nt->velocity   = vel;
   nt->prog       = prog;
   nt->pan        = pan;
   midi.noteq.count++;
   
   for( I = 0; I < MAX_DSP_POLYPHONY; I++ ) {
      note = midi.latest_note[I];
      if( note != (MidiNote *)0 && note->chan == ch && note->pitch == pitch && 
         (note->start_time == time || note->end_time == -1) ) {
         note->end_time = time;
         break;
      }
   }

   for( I = 0; I < MAX_DSP_POLYPHONY; I++ ) {
      note = midi.latest_note[I];
      if( note == (MidiNote *)0 ) {
         midi.latest_note[I] = nt;
         break;
      }
      if( note->end_time > 0 && note->end_time <= time ) {
         midi.latest_note[I] = nt;
         break;
      }
      if( earliest_note == (MidiNote **)0 || note->start_time < (*earliest_note)->start_time )
         earliest_note = &midi.latest_note[I];
   }

   if( NoteQ_Full() ) {
      for( I = 0; I < 8; I++ ) {
         note = NoteQ_Peek( I );
         if( note->end_time <= 0 )
            note->end_time = time;
      }
   }
   if( I == MAX_DSP_POLYPHONY ) {      /* Apply Note Stealing */
      (*earliest_note)->end_time = time;
      *earliest_note = nt;
   }
}

static void NoteQ_Close( int32 time, int8 chan, int8 pitch )
{
   MidiNote *note;
   int16 I;

   for( I = 0; I < MAX_DSP_POLYPHONY; I++ ) {
      if( (note = midi.latest_note[I]) == (MidiNote*)0 )
         continue;
      if( note->chan == chan && note->pitch == pitch && note->end_time == 0 ) {
         if( (midi.channel[chan].flag & CHANNEL_FLAG_PEDAL) == 0 ) {
            note->end_time = time;
            midi.latest_note[I] = (MidiNote*)0;
         }
         else
            note->end_time = -1;
         break;
      }
   }
}

static void NoteQ_PedalOff( uint32 time, int8 chan )
{
   MidiNote *note;
   int16 I;

   for( I = 0; I < MAX_DSP_POLYPHONY; I++ ) {
      note = midi.latest_note[I];
      if( note != (MidiNote *)0 && note->chan == chan && note->end_time == -1 ) {
         note->end_time = time;
         midi.latest_note[I] = (MidiNote*)0;
      }
   }
}

static void NoteQ_Consume( void )
{
   midi.noteq.count--;
   midi.noteq.head = (midi.noteq.head+1) & (NOTE_Q_SIZE-1);
}

/* ------------------------------------------------------------------- */

static void msginit()
{
   midi.msgindex = 0;
}

static uint8 *msg()
{
   return midi.msgbuff;
}

static int16 msgleng()
{
   return midi.msgindex;
}

static void msgadd(int16 c)
{
   if( midi.msgindex < MSG_SIZE - 1 ) {
      midi.msgbuff[midi.msgindex++] = (uint8)c;
      midi.msgbuff[midi.msgindex] = 0;
   }
}

/* ------------------------------------------------------------------- */
/*  Functions to be called while processing the MIDI file.             */
/* ------------------------------------------------------------------- */
static void Mf_settempo( int32 ltempo )
{
   midi.tempo = ltempo / 1000;
}

static void Mf_program( int8 ch, int8 prog )
{
   midi.channel[ch].program = prog;
}

static void Mf_parameter( int8 ch, int8 ctrl, int8 val )
{
   switch( ctrl ) {
   case 0x00:
      midi.channel[ch].bank = ((int16)val<<7) | (midi.channel[ch].bank&0x7F);
      break;
   case 0x20:
      midi.channel[ch].bank = (midi.channel[ch].bank&0x3F80) | (int16)val;
      break;
   case 0x07:
      midi.channel[ch].volume = val;
      break;
   case 0x0A:
      midi.channel[ch].pan = val;
      break;
   case 0x0B:
      midi.channel[ch].expression = val;
      break;
   case 0x40:
      if( val >= 0x40 )
         midi.channel[ch].flag |= CHANNEL_FLAG_PEDAL;
      else {
         midi.channel[ch].flag &= ~CHANNEL_FLAG_PEDAL;
         NoteQ_PedalOff( midi.currtime, ch );
      }
      break;
   }
}

static void Mf_noteon( int8 ch, int8 pitch, int8 vel )
{
   int8 prog;

   if( ch == 9 )
      prog = -pitch;
   else
      prog = midi.channel[ch].program + 1;

   if( midi.channel[ch].flag & CHANNEL_FLAG_MUTE )
      return;
   if( vel != 0 ) {
      vel = (int8)( (int32)vel * (int32)midi.channel[ch].volume * 
         (int32)midi.channel[ch].expression >> 14 );
      NoteQ_Put( midi.currtime, ch, pitch, vel, prog, midi.channel[ch].pan );
   }
   else 
      NoteQ_Close( midi.currtime, ch, pitch );
}

static void Mf_noteoff( int8 ch, int8 pitch, int8 vel )
{
   if( midi.channel[ch].flag & CHANNEL_FLAG_MUTE )
      return;
   NoteQ_Close( midi.currtime, ch, pitch );
}

static void Mf_setMIP( uint8 device, int16 len, uint8 *mip )
{
   int16 I;
   uint8 ch;

   for( I = 0; I < MAX_CHANNEL; I++ )
      midi.channel[I].flag |= CHANNEL_FLAG_MUTE;

   for( I = 0; I < len; I++ ) {
      ch = mip[I*2];
      if( mip[I*2+1] <= MAX_DSP_POLYPHONY )
         midi.channel[ch].flag &= ~CHANNEL_FLAG_MUTE;
   }
}

static void Mf_pressure( int chan, int pitch, int press )
{
}

static void Mf_pitchbend( int chan, int msb, int lsb )
{
}

static void Mf_chanpressure( int chan, int press )
{
}

static void Mf_metamisc( int type, int leng, uint8 *mess)
{
}

static void Mf_seqspecific( int type, int leng, uint8 *mess )
{
}

static void Mf_text( int type, int leng, uint8 *mess )
{
   static char *ttype[] = {
      0,
      "Text Event",		/* type=0x01 */
      "Copyright Notice",	/* type=0x02 */
      "Sequence/Track Name",
      "Instrument Name",	/* ...       */
      "Lyric",
      "Marker",
      "Cue Point",		/* type=0x07 */
      "Unrecognized"
   };
   int unrecognized = (sizeof(ttype)/sizeof(char *)) - 1;
   register uint8 *p = mess;
   
   if ( type < 1 || type > unrecognized )
      type = unrecognized;
   (void)p;
}

static void Mf_seqnum( int num )
{
}

static void Mf_eot( void )
{
}

static void Mf_keysig( int sf, int mi )
{
}

static void Mf_timesig( int nn, int dd, int cc, int bb )
{
   int denom = 1;
   while ( dd-- > 0 )
      denom *= 2;
}

static void Mf_smpte( int hr, int mn, int se, int fr, int ff )
{
}

/* ------------------------------------------------------------------- */
static uint32 get32bit( const uint8 *s )
{
   return ((uint32)s[0] << 24) + ((uint32)s[1] << 16) + ((uint32)s[2] << 8) + (uint32)s[3];
}

static uint16 get16bit( const uint8 *s )
{
   return ((uint16)s[0] << 8) + (uint16)s[1];
}

/* ------------------------------------------------------------------- */
static int16 egetc(int16 trk)       /* read a single character and abort on EOF */
{
   if( midi.tracks[trk].toberead > 0 ) {
      midi.tracks[trk].toberead--;
      return *midi.tracks[trk].ptr++;
   }
   return -1;
}

/* ------------------------------------------------------------------- */
/* readvarinum - read a varying-length number, and return the */
/* number of characters it took. */

static int32 readvarinum( int16 trk )
{
   int32 value;
   int16 c;

   c = egetc( trk );
   if( !(c & 0x80) ) return c;
   value = c & 0x7F;
   c = egetc( trk );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) ) return value;
   c = egetc( trk );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) ) return value;
   c = egetc( trk );
   value = (value << 7) + (c & 0x7f);
   return value;
}

static void metaevent(int type)
{
   uint8 *m = msg();
   int16 leng = msgleng();

   switch  ( type ) {
   case 0x51:	/* Set tempo */
      Mf_settempo( ((uint32)m[0] << 16) + ((uint32)m[1] << 8) + (uint32)m[2] );
      break;
   case 0x00:
      Mf_seqnum( get16bit(m) );
      break;
   case 0x01:	/* Text event */
   case 0x02:	/* Copyright notice */
   case 0x03:	/* Sequence/Track name */
   case 0x04:	/* Instrument name */
   case 0x05:	/* Lyric */
   case 0x06:	/* Marker */
   case 0x07:	/* Cue point */
   case 0x08:
   case 0x09:
   case 0x0a:
   case 0x0b:
   case 0x0c:
   case 0x0d:
   case 0x0e:
   case 0x0f:
      /* These are all text events */
      Mf_text(type,leng,m);
      break;
   case 0x2f:	/* End of Track */
      Mf_eot();
      break;
   case 0x54:
      Mf_smpte( m[0], m[1], m[2], m[3], m[4] );
      break;
   case 0x58:
      Mf_timesig( m[0], m[1], m[2], m[3] );
      break;
   case 0x59:
      Mf_keysig( m[0], m[1] );
      break;
   case 0x7f:
      Mf_seqspecific( type, leng, m );
      break;
   default:
      Mf_metamisc( type, leng, m);
      break;
   }
}

static void sysexevent( void )
{
   int16 len = msgleng();
   uint8 *m = msg();
   
   switch  ( m[0] ) {
   case 0x7F:              /* Universal realtime system exclusive */
      if( m[2] == 0x0B && m[3] == 0x01 )
         Mf_setMIP( m[1], (int16)((len - 5) / 2), &m[4] );
      break;
   }
}

static void chanmessage(int8 status, int8 c1, int8 c2)
{
   int8 chan = status & 0xf;

   switch ( status & 0xf0 ) {
   case 0x80:
      Mf_noteoff( chan, c1, c2 );
      break;
   case 0x90:
      Mf_noteon( chan, c1, c2 );
      break;
   case 0xb0:
      Mf_parameter( chan, c1, c2 );
      break;
   case 0xc0:
      Mf_program( chan, c1 );
      break;
   case 0xa0:
      Mf_pressure( chan, c1, c2 );
      break;
   case 0xe0:
      Mf_pitchbend( chan, c1, c2 );
      break;
   case 0xd0:
      Mf_chanpressure( chan, c1 );
      break;
   }
}

static int16 readtrack(int16 trk)		 /* read a track chunk */
{
   /* This array is indexed by the high half of a status byte.  It's */
   /* value is either the number of bytes needed (1 or 2) for a channel */
   /* message, or 0 (meaning it's not  a channel message). */
   static const int8 chantype[] = {
      0, 0, 0, 0, 0, 0, 0, 0,    /* 0x00 through 0x70 */
      2, 2, 2, 2, 1, 1, 2, 0     /* 0x80 through 0xf0 */
   };
   uint32 I;
   uint32 lookfor;
   int16 c, c1, type;
   int needed;

   c = egetc( trk );

   if( (c & 0x80) == 0 ) {  /* running status? */
      if( midi.tracks[trk].status == 0 )
         return -1;
      midi.tracks[trk].running = 1;
   }
   else {
      midi.tracks[trk].status = (uint8)c;
      midi.tracks[trk].running = 0;
   }

   needed = chantype[ (midi.tracks[trk].status>>4) & 0xf ];

   if( needed ) {          /* ie. is it a channel message? */
      if ( midi.tracks[trk].running )
         c1 = c;
      else
         c1 = egetc(trk);
      chanmessage( midi.tracks[trk].status, (int8)c1, (int8)((needed>1) ? egetc(trk) : 0) );
   }
   else {
      switch ( c ) {

      case 0xFF:        /* meta event */
         type = egetc(trk);
         lookfor = readvarinum(trk);
         msginit();

         for( I = 0; I < lookfor; I++ )
            msgadd(egetc(trk));
         metaevent(type);
         break;

      case 0xF0:     /* start of system exclusive */
         lookfor = readvarinum(trk);
         msginit();
         
         for( I = 0; I < lookfor; I++ )
            msgadd(egetc(trk));
         sysexevent();
         break;
      
      case 0xF7:  /* sysex continuation or arbitrary stuff */
         lookfor = readvarinum(trk);
         for( I = 0; I < lookfor; I++ )
            egetc(trk);
         break;

      default:
         return -1;
         break;
      }
   }
   midi.tracks[trk].deltatime = readvarinum( trk );
   return 0;
}

 /*
 * This routine converts delta times in ticks into seconds. The
 * else statement is needed because the formula is different for tracks
 * based on notes and tracks based on SMPTE times.
 *
*/
static uint32 mf_ticks2ms( uint32 ticks )
{
   int8 low, high;
   if(midi.division > 0)
      return  (ticks * midi.tempo) / (uint32)midi.division;
   else {
      low = (int8)(midi.division & 0xFF);
      high = (int8)((midi.division >> 8) & 0xFF);
      return (ticks * 1000) / ((uint32)(-high) * (uint32)low);
   }
}

static bool midiParse( void )
{
   int16    I;
   int16    next_trk;
   uint32   delta;

   while( !NoteQ_Full() ) {
      next_trk = MAX_TRACK;
      delta    = 0x7FFFFF;
      for( I = 0 ; I < midi.ntrks; I++ ) {
         if( midi.tracks[I].toberead > 0 && midi.tracks[I].deltatime < delta ) {
            delta    = midi.tracks[I].deltatime;
            next_trk = I;
         }
      }
      if( next_trk == MAX_TRACK ) {             /* No unhandled MIDI data left */
         if( !NoteQ_Empty() ) {
            for( I = 0; I < MAX_CHANNEL; I++ ) {
               if( midi.channel[I].flag & CHANNEL_FLAG_PEDAL ) {
                  NoteQ_PedalOff( midi.currtime, (int8)I );
                  midi.channel[I].flag &= ~CHANNEL_FLAG_PEDAL;
               }
            }
            return true;
         }
         return false;
      }
      if( delta > 0 ) {
         for( I = 0 ; I < midi.ntrks; I++ ) {
            if( midi.tracks[I].toberead > 0 )
               midi.tracks[I].deltatime -= delta;
         }
         midi.currtime += mf_ticks2ms( delta ); /* delta time */
      }
      if( readtrack( next_trk ) == -1 ) {
         /* midi.bad_flag = true; */
         return false;
      }
   }
   return true;
}

/* ------------------------------------------------------------------- */
static bool midiPrepare( const uint8 *midifile )
{
   uint16       I;
   const uint8 *ptr;

   if( midifile[0] != 'M' || midifile[1] != 'T' || midifile[2] != 'h' || midifile[3] != 'd' )
      return false;

   NoteQ_Init();

   for( I = 0; I < MAX_CHANNEL; I++ ) {
      midi.channel[I].bank       = 0;
      midi.channel[I].program    = 0;
      midi.channel[I].volume     = 100;
      midi.channel[I].expression = 127;
      midi.channel[I].pan        = 64;
      midi.channel[I].flag       &= ~CHANNEL_FLAG_MUTE;
   }

   midi.format = get16bit( &midifile[8] );
   midi.ntrks  = get16bit( &midifile[10] );
   if( midi.ntrks > MAX_TRACK )
      midi.ntrks = MAX_TRACK;
   midi.division = get16bit( &midifile[12] );

   ptr = &midifile[8 + get32bit(&midifile[4])];
   for( I = 0 ; I < midi.ntrks; I++ ) {
      if( ptr[0] != 'M' || ptr[1] != 'T' || ptr[2] != 'r' || ptr[3] != 'k' )
         break;
      midi.tracks[I].toberead = get32bit( &ptr[4] );
      midi.tracks[I].ptr = &ptr[8];
      ptr = ptr + midi.tracks[I].toberead + 8;
      midi.tracks[I].deltatime = readvarinum( I );
      midi.tracks[I].running = 0;
      midi.tracks[I].status = 0;
   }
   midi.ntrks = I;
   midi.currtime = 0;
   midi.tempo = 500;
   midi.bad_flag = false;
   return true;
}

/* ------------------------------------------------------------------- */
static int32 calcAmp( MidiNote *note  )
{
   int32 vel = (int32)note->velocity * (int32)note->velocity;
   return vel;
}

const static uint32 scaleTab[MAX_DSP_POLYPHONY] = 
{  0x2000000, 0x2000000, 0x2300000, 0x2600000, 
   0x2800000, 0x2800000, 0x2800000, 0x2A00000,
   0x2A00000, 0x2A00000, 0x2C00000, 0x2C00000,
   0x3000000, 0x3000000, 0x3000000, 0x3000000
};

const static int16 env_osc_tab3[80] = {         /* Envelop Table from H.W. Nien */
   0x7e41,0x7593,0x6ce5,0x6438,0x5b8a,0x52dd,0x4e21,0x4ea4,
   0x4f27,0x4e66,0x4afa,0x478d,0x4421,0x40b4,0x3d48,0x39dc,
   0x366f,0x3303,0x31a0,0x35e4,0x3754,0x348b,0x31c2,0x2ef9,
   0x2e7d,0x3163,0x3448,0x351d,0x32a9,0x3034,0x2dc0,0x2b4c,
   0x28d8,0x2663,0x23ef,0x217b,0x1f07,0x1c93,0x1a1e,0x1937,
   0x1aa2,0x1c0e,0x1d7a,0x1ee6,0x2052,0x1eb4,0x1c5a,0x1a00,
   0x17a6,0x154d,0x12f3,0x1099,0x0f7f,0x0eec,0x0e59,0x0dc6,
   0x0d33,0x0ca1,0x0c0e,0x0b7b,0x0ae8,0x0a55,0x09c2,0x092f,
   0x089c,0x0809,0x0776,0x06e3,0x0650,0x05bd,0x052a,0x0497,
   0x0405,0x0372,0x02df,0x024c,0x01b9,0x0126,0x0093,0x0000
};

static uint32 calcOverlapAmp( int32 maxamp_time, MidiEvNote *evnote  )
{
   int32 val = 80 * ( maxamp_time - evnote->start_time ) / 
      ( evnote->end_time - evnote->start_time );
   return (uint32)evnote->amp * (uint32)env_osc_tab3[ val ] >> 15;
}

static uint32 calcMaxAmp( MidiNote *note )
{
   int16       I;
   uint16      polyphony = 0;
   uint32      maxamp = 0;
   bool        inserted = false;
   int32       start_time, end_time;
   MidiEvNote  *evnote;

   start_time  = ( note->start_time + 10 ) / 5 >> 2;
   end_time    = ( note->end_time + 10 ) / 5 >> 2;
   if( start_time == end_time )
      return 0;

   /* Analyze maximum amplitude */
   for( I = 0; I < MAX_DSP_POLYPHONY; I++ ) {
      evnote = &midi.ev_note[I];
      if( evnote->end_time <= start_time ) {
         if( inserted )
            continue;
         inserted             = true;
         evnote->start_time   = start_time;
         evnote->end_time     = end_time;
         evnote->amp          = (uint16)calcAmp( note );
         evnote->prog         = note->prog;
         evnote->pitch        = note->pitch;
      }
      maxamp += calcOverlapAmp( start_time, evnote );
      polyphony++;
   }
   if( midi.polyphony < polyphony )
      midi.polyphony = polyphony;
   return maxamp;
}

static bool midiPreprocess( const uint8 *midifile )
{
   MidiNote *note;
   uint32   I, maxamp = 0;

   /* Calculate maximum amplitude */
   midiPrepare( midifile );

   midi.polyphony  = 0;
   for( I = 0; I < MAX_DSP_POLYPHONY; I++ ) {
      midi.ev_note[I].start_time = 0;
      midi.ev_note[I].end_time   = 0;
   }

   while( 1 ) {
      while( 1 ) {
         if( midiParse() == false && NoteQ_Empty() )
            break;
         note = NoteQ_Peek( 0 );
         if( note->end_time > 0 )
            break;
         NoteQ_Consume();
      }
      if( NoteQ_Empty() )
         break;
      while( note->end_time > 0 ) {
         I = calcMaxAmp( note );
         if( maxamp < I )
            maxamp = I;

         NoteQ_Consume();
         if( NoteQ_Empty() )
            break;
         note = NoteQ_Peek( 0 );
      }
   }
   if( maxamp != 0 ) {
      if( midi.polyphony > 16 )
         midi.scalefactor = (uint16)(scaleTab[15] / maxamp);
      else
         midi.scalefactor = (uint16)(scaleTab[midi.polyphony-1] / maxamp);
   }

   return true;
}

/* ------------------------------------------------------------------- */
static void midiDecoder( void )
{
   MidiNote *note;
   int32 vel;
   uint16 count = 0;
   uint16 free_entry = GMI_GetFreeSpace();

   while( count < free_entry ) {
      while( 1 ) {
         if( midiParse() == false ) {     /* No data left */
            GMI_DataFinished();
            if( NoteQ_Empty() )
               return;
         }
         note = NoteQ_Peek(0);
         if( note->end_time > 0 )
            break;
         NoteQ_Consume();
      }

      while( note->end_time > 0 && count < free_entry ) {
         vel = calcAmp( note );
         if( note->prog > 0 ) {   
            GMI_PutNote( note->start_time, note->end_time - note->start_time, 
               note->pitch, vel * midi.scalefactor >> 10, 0 );
            count++;
         }
         NoteQ_Consume();
         if( NoteQ_Empty() )
            break;
         note = NoteQ_Peek(0);
      }
   }
}

static void midiHandler( GMI_Event event )
{
   switch( event ) {
   case GMI_END:
      if( midi.bad_flag ) {
         mediaHandler( (void*)MEDIA_ERROR );
         return;
      }
      if( midi.repeats == 1 ) {
         mediaHandler( (void*)MEDIA_END );
         return;
      }
      if( midi.repeats == 0 )
         midi.repeats = 1;
      midi.repeats--;
      midiPrepare( midi.msp->smffile );
      GMI_Play( midiHandler );
      break;
   case GMI_NOTE_REQUEST:
      midiDecoder();
      break;
   }
}

Media_Status midiPlay( mediaControl *ctrl )
{
   midi.msp = &ctrl->param.smf;
   
   if( midiPreprocess( midi.msp->smffile ) == false )
      return MEDIA_FAIL;
   midi.repeats = midi.msp->repeats;
   midiPrepare( midi.msp->smffile );
   GMI_Play( midiHandler );

   return MEDIA_SUCCESS;
}

void midiStop( void )
{
   GMI_Stop();
}
#else
char dummy_mididec_c;    /* define a dummy variable to avoid warning message */
#endif /* SIN_WAV_SYN */

