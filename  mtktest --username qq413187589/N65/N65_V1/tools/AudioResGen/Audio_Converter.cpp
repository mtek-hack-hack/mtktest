// Audio_Converter.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "Audio_Converter.h"

int CMIDI_Convert( unsigned char *buf, int *len, int time_div );

#define SWSYN_CMIDI_Convert(buf,len)    CMIDI_Convert(buf,len,20)
#define DSPSYN_CMIDI_Convert(buf,len)   CMIDI_Convert(buf,len,18)
#define CMIDI_STANDALONE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

#define FORMAT_IMY "18"   /* sync with med_main.h */
#define FORMAT_MID "17"   /* sync with med_main.h */
#define FORMAT_WAV "13"   /* sync with med_main.h */
#define FORMAT_MMF "20"   /* sync with med_main.h */
#define FORMAT_MP3 "5"   /* sync with med_main.h */
#define FORMAT_PCM "7"   /* sync with med_main.h */
#define FORMAT_DVI "11"   /* sync with med_main.h */
#define FORMAT_AMR "3"   /* sync with med_main.h */
#define FORMAT_AAC "6"   /* sync with med_main.h */
#define FORMAT_WMA "24"   /* sync with med_main.h */
#define FORMAT_M4A "25"   /* sync with med_main.h */

/* -------------------------------------------------------------------------------------- */
#ifdef CMIDI_STANDALONE

#define TRACE1(s,t)  \
   if( smf.debug ) { \
      printf(s, t * smf.time_div );    \
   }

#define TRACE2(s,t,a)     \
   if( smf.debug ) { \
      printf(s, t * smf.time_div, a );  \
   }

#define TRACE3(s,t,a,b)    \
   if( smf.debug ) { \
      printf(s, t * smf.time_div, a, b );  \
   }

#define TRACE4(s,t,a,b,c)    \
   if( smf.debug ) { \
      printf(s, t * smf.time_div, a, b, c );  \
   }
#else    /* CMIDI_STANDALONE */
#define TRACE1(s,t) 
#define TRACE2(s,t,a)
#define TRACE3(s,t,a,b) 
#define TRACE4(s,t,a,b,c) 
#endif   /* CMIDI_STANDALONE */

/* -------------------------------------------------------------------------------------- */
typedef unsigned char            uint8;
typedef signed char              int8;
typedef unsigned short           uint16;
typedef signed short             int16;
typedef unsigned int             uint32;
typedef signed int               int32;
//typedef  uint8                   bool;
//#define  true                    1
//#define  false                   0
/* -------------------------------------------------------------------------------------- */
                        
#define MAX_TRACK                32
#define ASSERT                   assert
#define VOLUME_QUANTIZE    

#define MAX_MIDI_EVENTS          19

#define ME_DTIME                 0
#define ME_NOTEON                1
#define ME_NOTEOFF               2
#define ME_KEY_PRESSURE          3
#define ME_MAINVOLUME            4
#define ME_PAN                   5
#define ME_SUSTAIN               6
#define ME_EXPRESSION            7
#define ME_PITCH_WHEEL           8
#define ME_PITCH_SENS            9
#define ME_PROGRAM               10
#define ME_CHANNEL_PRESSURE      11
#define ME_TONE_BANK_HI          12
#define ME_ALL_NOTES_OFF         13
#define ME_ALL_SOUNDS_OFF        14
#define ME_RESET_CONTROLLERS     15
#define ME_MODULATION_WHEEL      16
#define ME_TEMPO                 17
#define ME_TONE_BANK_LO          18

typedef struct {
   int32       ticks;
   int32       toberead;
   const uint8 *ptr;
   uint32      status;
   bool        running;
} TrkParam;


typedef struct midievent {
  uint8     type;
  uint8     ch;
  uint8     c1;
  uint8     c2;
  int32     dtime;
  struct midievent *next;
} MidiEvent;

static struct {
   int32       duration;
   int32       active_tempo;
   int16       division;
   int32       acc_ticks;
   int32       acc_20ms;
   int32       time_div;
   bool        nrpn;
   int8        rpn_msb[16];
   int8        rpn_lsb[16];
   TrkParam    tracks[MAX_TRACK];
   MidiEvent   *event_head;
   MidiEvent   *event_tail;
   bool        debug;
   uint16      cache;
   uint16      bits;
   uint8       old_channel;
   uint8       old_octave;
   int         total_events;
   int         output_bytes;
   int         statistic[MAX_MIDI_EVENTS];
} smf;

/* -------------------------------------------------------------------------------------- */
const static int8 chantype[] = {
   0, 0, 0, 0, 0, 0, 0, 0,    /* 0x00 through 0x70 */
   2, 2, 2, 2, 1, 1, 2, 0     /* 0x80 through 0xf0 */
};

/* -------------------------------------------------------------------------------------- */
static uint32 get32bit( const uint8 *s )
{
   return ((uint32)s[0] << 24) + ((uint32)s[1] << 16) + ((uint32)s[2] << 8) + (uint32)s[3];
}


static uint16 get16bit( const uint8 *s )
{
   return (uint16)(((uint16)s[0] << 8) + (uint16)s[1]);
}

static uint8 egetc( TrkParam *trk )       /* read a single character and abort on EOF */
{
   if( trk->toberead > 0 ) {
      trk->toberead--;
      return *trk->ptr++;
   }
   return -1;
}

static int32 getVarNum( TrkParam *trk )
{
   int32 value;
   int16 c;
   const uint8 *ptr = trk->ptr;
   int32 count = trk->toberead;

   if( count < 0 )  return -1;
   c = *ptr++;          count--;
   value = c & 0x7F;
   if( c & 0x80 ) {
      c = *ptr++;          count--;
      value = (value << 7) + (c & 0x7f);
      if( c & 0x80 ) {
         c = *ptr++;          count--;
         value = (value << 7) + (c & 0x7f);
         if( c & 0x80 ) {
            c = *ptr++;          count--;
            value = (value << 7) + (c & 0x7f);
         }
      }
   }
   trk->ptr = ptr;
   trk->toberead = count;
   return value;
}

static void MidiEvent_Put( uint8 type, uint8 ch, uint8 c1, uint8 c2 )
{
   MidiEvent *event;

   event = (MidiEvent*)malloc( sizeof(MidiEvent) );
   event->type = type;
   event->ch = ch;
   event->c1 = c1;
   event->c2 = c2;
   event->next = 0;
   if( smf.event_head == NULL ) {
      smf.event_head = smf.event_tail = event;
   }
   else {
      ASSERT( smf.event_tail != NULL );
      smf.event_tail->next = event;
      smf.event_tail = event;
   }
}

static MidiEvent *MidiEvent_Get( MidiEvent *event )
{
   MidiEvent *temp;
   if(smf.event_head == NULL )
      return NULL;
   *event = *smf.event_head;
   temp = smf.event_head;
   smf.event_head = smf.event_head->next;
   free( temp );
   if( smf.event_head == NULL )
      smf.event_tail = NULL;
   return event;
}

static void MidiEvent_Free( void )
{
   MidiEvent event;
   while( MidiEvent_Get(&event) != NULL );
}
/* -------------------------------------------------------------------------------------- */

static int32 MIDI_Parse( const uint8 *mid )
{
   int32      I;
   int32      ntrks;
   TrkParam    *trk;
   int16       next_trk;
   int32       temp;
   int32       delta;
   TrkParam    *tracks;
   bool        fail = false;
   int16       needed;
   uint8       type;
   uint8       c1, c2, ch;

   if( mid[0] == 'R' && mid[1] == 'I' && mid[2] == 'F' && mid[3] == 'F' )
      mid += 20;
   if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'h' || mid[3] != 'd' )
      return -1;

   if( get16bit( &mid[8] ) > 2 )
      return -1;
   if( (ntrks  = (uint32)get16bit( &mid[10] )) > MAX_TRACK )
      return -1;

   ASSERT( (smf.division = get16bit( &mid[12] )) > 0 );

   mid = (const uint8 *)&mid[8 + get32bit(&mid[4])];
   tracks = smf.tracks;

   for( I = 0 ; I < ntrks; I++ ) {
      if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'r' || mid[3] != 'k' )
         break;
      trk            = &tracks[I];
      trk->toberead  = get32bit( &mid[4] );
      trk->ptr       = &mid[8];
      mid            = mid + 8 + trk->toberead;
      trk->ticks     = getVarNum( trk );
      trk->status    = 0;
      trk->running   = false;
   }
   ntrks = I;
   
   smf.event_head = smf.event_tail = NULL;
   smf.duration = 0;
   smf.acc_ticks = 0;
   smf.acc_20ms = 0;
   smf.active_tempo = 1024 * 500 / (uint32)smf.division;
   smf.nrpn = false;
   
   while( 1 ) {
      next_trk = MAX_TRACK;
      delta    = 0x7FFFFF;
      for( I = 0 ; I < ntrks; I++ ) {
         trk = &tracks[I];
         if( trk->toberead > 0 && trk->ticks < delta ) {
            delta    = trk->ticks;
            next_trk = I;
            if( delta == 0 )
               break;
         }
      }
      if( next_trk == MAX_TRACK )            /* No unhandled MIDI data left */
         break;
      if( delta > 0 ) {
         for( I = 0 ; I < ntrks; I++ ) {
            trk = &tracks[I];
            if( trk->toberead > 0 )
               trk->ticks -= delta;
         }
         smf.acc_ticks += delta;
         if( smf.acc_ticks * smf.active_tempo < smf.acc_ticks ) { /* overflow */
            smf.duration += smf.acc_20ms;
            smf.acc_ticks = delta;
            smf.acc_20ms = 0;
         }
         temp = ((smf.acc_ticks * smf.active_tempo >> 10) + (smf.time_div/2)) / smf.time_div;
         delta = temp - smf.acc_20ms;
         smf.acc_20ms = temp;
      }
      if( delta != 0 ) {
         MidiEvent_Put( ME_DTIME, 0, (uint8)((delta>>7)&0x7F), (uint8)(delta&0x7F) );
         smf.event_tail->dtime = delta;
      }
      trk = &tracks[next_trk];
      
      type = egetc( trk );
      if( type == 0xFF ) {
         type = egetc( trk );                                    /* read type */
         if( (delta = getVarNum( trk )) < 0 ) {                /* get meta event length */
            fail = true;
            break;
         }
         if( type == 0x51 ) {                                    /* Set tempo */
            smf.duration += smf.acc_20ms;
            smf.acc_ticks = 0;
            smf.acc_20ms = 0;

            smf.active_tempo = (((uint32)trk->ptr[0] << 16) + ((uint32)trk->ptr[1] << 8) + (uint32)trk->ptr[2]) / 1000;
            smf.active_tempo = 1024 * smf.active_tempo / (uint32)smf.division;
         }
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 ) {
            fail = true;
            break;
         }
      }
      else if( type == 0xF0 || type == 0xF7 ) {
         if( (delta = getVarNum( trk )) < 0 ) {
            fail = true;
            break;
         }
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 ) {
            fail = true;
            break;
         }
      }
      else {
         if( (type & 0x80) == 0 ) {       /* running status? */
            if( trk->status == 0 ){
               fail = true;
               break;
            }
            trk->running = true;
         }
         else {
            trk->status = (uint8)type;
            trk->running = false;
         }
         
         needed = chantype[ (trk->status>>4) & 0xf ];
         
         if( needed ) {                /* ie. is it a channel message? */
            if ( trk->running )
               c1 = type;
            else
               c1 = egetc(trk);
            c2 = (uint8)((needed>1) ? egetc(trk) : 0);
            ch = (uint8)(trk->status&0x0F);

            switch( trk->status & 0xf0 ) {
            case 0x80:        /* Note off */
               MidiEvent_Put( ME_NOTEOFF, ch, c1, 0 );
               break;
            case 0x90:        /* Note on */
               if( c2 == 0 )
                  MidiEvent_Put( ME_NOTEOFF, ch, c1, 0 );
               else {
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ME_NOTEON, ch, c1, c2 );
               }
               break;
            case 0xa0:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
               MidiEvent_Put( ME_KEY_PRESSURE, ch, c1, c2 );
               break;
            case 0xb0:     /* Controller message */
               switch( c1 ) {
               case 0x00:
                  MidiEvent_Put( ME_TONE_BANK_HI, ch, c2, 0 );
                  break;
               case 0x20:
                  MidiEvent_Put( ME_TONE_BANK_LO, ch, c2, 0 );
                  break;
               case 0x01:
                  MidiEvent_Put( ME_MODULATION_WHEEL, ch, c2, 0 );
                  break;
               case 0x07:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ME_MAINVOLUME, ch, c2, 0 );
                  break;
               case 0x0A:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ME_PAN, ch, c2, 0 );
                  break;
               case 0x0B:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ME_EXPRESSION, ch, c2, 0 );
                  break;
               case 0x40:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ME_SUSTAIN, ch, c2, 0 );
                  break;
                  
               case 98:    smf.nrpn=true;  smf.rpn_lsb[ch] = c2;    break;
               case 99:    smf.nrpn=true;  smf.rpn_msb[ch] = c2;    break;
               case 100:   smf.nrpn=false; smf.rpn_lsb[ch] = c2;    break;
               case 101:   smf.nrpn=false; smf.rpn_msb[ch] = c2;    break;
                  
               case 0x06:     /* RPN */
                  if( smf.nrpn )
                     break;
                  switch( ( (int16)smf.rpn_msb[ch] << 7 ) | (int16)smf.rpn_lsb[ch] ) {
                  case 0x0000: /* Pitch bend sensitivity */
                     MidiEvent_Put( ME_PITCH_SENS, ch, c2, 0 );
                     break;
                  case 0x3FFF: /* RPN reset */
                     /* reset pitch bend sensitivity to 2 */
                     MidiEvent_Put( ME_PITCH_SENS, ch, 2, 0 );
                     break;
                  }
                  break;
               }
               break;

            case 0xc0:
               MidiEvent_Put( ME_PROGRAM, ch, c1, 0 );
               break;
            case 0xe0:
#ifdef VOLUME_QUANTIZE
                  c1 = 0;
#endif
               MidiEvent_Put( ME_PITCH_WHEEL, ch, c1, c2 );
               break;
            case 0xd0:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
               MidiEvent_Put( ME_CHANNEL_PRESSURE, ch, c1, 0 );
               break;

            }
         }
      }
      if( (trk->ticks = getVarNum( trk )) < 0 ) {
         fail = true;
         break;
      }
   }
   smf.duration += smf.acc_20ms;

   if( fail )
      return -1;
   return smf.duration;
}

/* -------------------------------------------------------------------------------------- */
/*
static void MidiEvent_GroupType( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( head->type != head->next->type ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( curr->type == head->type ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_GroupTypeChannel( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( head->type == head->next->type && head->ch != head->next->ch ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( curr->type == head->type && curr->ch == head->ch ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}
*/

static void MidiEvent_GroupC1( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( (head->c1>>4) != (head->next->c1>>4) ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( (curr->c1>>4) == (head->c1>>4) ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_GroupChannel( MidiEvent *prevtail, MidiEvent **phead, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;
   MidiEvent *head = *phead;

   if( prevtail != 0 ) {
      assert( prevtail->next->next == head );
      if( prevtail->ch != head->ch ) {
         for( prev = head, curr = head->next; curr != tail->next; prev = curr, curr = curr->next ) {
            if( curr->ch == prevtail->ch && (curr->c1>>4) == (prevtail->c1>>4) ) {
               prev->next = curr->next;
               curr->next = head;
               head = curr;
               prevtail->next->next = curr;
               if( curr == tail ) {
                  tail = prev;
                  curr = tail->next;
               }
               break;
            }
         }
         if( curr == tail->next ) {
            for( prev = head, curr = head->next; curr != tail->next; prev = curr, curr = curr->next ) {
               if( curr->ch == prevtail->ch ) {
                  prev->next = curr->next;
                  curr->next = head;
                  head = curr;
                  prevtail->next->next = curr;
                  if( curr == tail ) {
                     tail = prev;
                     curr = tail->next;
                  }
                  break;
               }
            }
            if( curr == tail->next ) {
               for( prev = head, curr = head->next; curr != tail->next; prev = curr, curr = curr->next ) {
                  if( (curr->c1>>4) == (prevtail->c1>>4) ) {
                     prev->next = curr->next;
                     curr->next = head;
                     head = curr;
                     prevtail->next->next = curr;
                     if( curr == tail ) {
                        tail = prev;
                        curr = tail->next;
                     }
                     break;
                  }
               }
            }
         }
      }
   }

   while( head != tail ) {
      if( head->ch != head->next->ch ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( curr->ch == head->ch ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_RemoveDupEvents( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *temp;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( head->type == ME_MAINVOLUME ||
         head->type == ME_SUSTAIN ||
         head->type == ME_PAN ||
         head->type == ME_PITCH_WHEEL || 
         head->type == ME_PROGRAM ||
         head->type == ME_CHANNEL_PRESSURE ||
         head->type == ME_TONE_BANK_HI ||
         head->type == ME_TONE_BANK_LO ||
         head->type == ME_MODULATION_WHEEL ||
         head->type == ME_EXPRESSION ||
         head->type == ME_PITCH_SENS ) {
         for( curr = head; curr != tail;  ) {
            temp = curr->next;
            if( temp->type == head->type && temp->ch == head->ch ) {
               if( head != curr ) {
                  curr->next = temp->next;
                  temp->next = head->next;
               }
               *head = *temp;
               free( temp );
               if( tail == temp ) {
                  tail = curr;
                  break;
               }
            }
            else {
               curr = curr->next;
            }
         }
      }
      if( head != tail )
         head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_Optimize( void )
{
   MidiEvent *head, *tail, *prevtail;

   head = tail = smf.event_head;
   prevtail = 0;
   while( head != NULL ) {
      if( head->type == ME_DTIME ) {
         tail = head->next;
         while( tail != NULL && tail->type == ME_DTIME ) {
            head->dtime += tail->dtime;
            head->next = tail->next;
            free( tail );
            tail = head->next;
         }
         head = head->next;
      }
      else {
         tail = head;
         while( tail->next!= 0 && tail->next->type != ME_DTIME )
            tail = tail->next;
         MidiEvent_RemoveDupEvents( head, &tail );
//         MidiEvent_GroupType( head, &tail );
//         MidiEvent_GroupTypeChannel( head, &tail );
         MidiEvent_GroupC1( head, &tail );
         MidiEvent_GroupChannel( prevtail, &head, &tail );
         head = tail->next;
         prevtail = tail;
      }
   }
}
/* -------------------------------------------------------------------------------------- */

static void putBits( uint8 data, uint32 len, uint8 **pptr )
{
   uint16 mask = ((1<<len)-1);
   if( len == 0 )
      return;
   assert( len <= 8 );

   smf.cache = ((uint16)data & mask) + (smf.cache << len );
   smf.bits += len;
   if( smf.bits >= 8 ) {
      data = (uint8)(smf.cache >> (smf.bits-8));
      smf.bits -= 8;
      smf.cache &= ((1<<smf.bits)-1);
      *(*pptr)++ = data;
      smf.output_bytes++;
   }
}

static void addStatistics( int type )
{
   smf.statistic[type]++;
   smf.total_events++;
}

static void checkChannel( MidiEvent *event, uint8 **pptr )
{
   if( event->ch != smf.old_channel ) {
      smf.old_channel = event->ch;
      addStatistics( 2 );
      putBits( (uint8)0x04, 3, pptr );
      putBits( smf.old_channel, 4, pptr );
   }
}

static void checkOctave( MidiEvent *event, uint8 **pptr )
{
   if( (event->c1>>4) != smf.old_octave ) {
      smf.old_octave = (event->c1>>4);
      addStatistics( 3 );
      putBits( (uint8)0x05, 3, pptr );
      putBits( smf.old_octave, 3, pptr );
   }
}

static void MidiEvent_Output( uint8 *ptr )
{
   MidiEvent event;
   int32 total_time = 0;
   int I;
   smf.bits = 0;
   smf.cache = 0;
   smf.old_channel = 0;
   smf.old_octave = 0;
   smf.total_events = 0;
   smf.output_bytes = 0;

   for( I = 0; I < MAX_MIDI_EVENTS; I++ )
      smf.statistic[I] = 0;

   while( MidiEvent_Get( &event ) != NULL ) {
      switch( event.type ) {
      case ME_DTIME:
         total_time += event.dtime;
         assert( event.dtime != 0 );
         if( event.dtime <= 16 ) {
            addStatistics( 4 );
            putBits( (uint8)0x06, 3, &ptr );
            putBits( (uint8)(event.dtime-1), 4, &ptr );
         }
         else {
            addStatistics( 16 );
//            assert( event.dtime <= 1024 );
            putBits( (uint8)0xF9, 8, &ptr );
            putBits( (uint8)((event.dtime-1)>>6), 4, &ptr );
            putBits( (uint8)((event.dtime-1)&0x3F), 6, &ptr );
         }
         TRACE1("time %d\n", total_time );
         break;
      case ME_NOTEOFF:
         checkChannel( &event, &ptr );
         checkOctave( &event, &ptr );
         addStatistics( 1 );
         putBits( (uint8)0x01, 2, &ptr );
         putBits( (uint8)(event.c1&0x0F), 4, &ptr );
         TRACE3("time %d: Note off, ch=%d, pitch=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_NOTEON:
         checkChannel( &event, &ptr );
         checkOctave( &event, &ptr );
         addStatistics( 0 );
         putBits( (uint8)0x00, 2, &ptr );
         putBits( (uint8)(event.c1&0x0F), 4, &ptr );
         putBits( (uint8)(event.c2>>2), 5, &ptr );
         TRACE4("time %d: Note on, ch=%d, pitch=%d, vel=%d\n", total_time, event.ch+1, event.c1, event.c2 );
         break;
      case ME_MAINVOLUME:
         checkChannel( &event, &ptr );
         addStatistics( 5 );
         putBits( (uint8)0x1C, 5, &ptr );
         putBits( (uint8)(event.c1>>2), 5, &ptr );
         TRACE3("time %d: Volume, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_PITCH_WHEEL:
         checkChannel( &event, &ptr );
         addStatistics( 6 );
         putBits( (uint8)0x1D, 5, &ptr );
         putBits( (uint8)(event.c2), 7, &ptr );
         TRACE4("time %d: Pitch wheel, ch=%d, lsb=%d, msb=%d\n", total_time, event.ch+1, event.c1, event.c2 );
         break;
      case ME_SUSTAIN:
         checkChannel( &event, &ptr );
         addStatistics( 7 );
         putBits( (uint8)0xF0, 8, &ptr );
         putBits( (uint8)(event.c1>>2), 5, &ptr );
         TRACE3("time %d: Sustain, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_PAN:
         checkChannel( &event, &ptr );
         addStatistics( 8 );
         putBits( (uint8)0xF1, 8, &ptr );
         putBits( (uint8)(event.c1>>2), 5, &ptr );
         TRACE3("time %d: Pan, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_PROGRAM:
         checkChannel( &event, &ptr );
         addStatistics( 9 );
         putBits( (uint8)0xF2, 8, &ptr );
         putBits( (uint8)(event.c1), 7, &ptr );
         TRACE3("time %d: Program, ch=%d, prog=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_CHANNEL_PRESSURE:
         checkChannel( &event, &ptr );
         addStatistics( 10 );
         putBits( (uint8)0xF3, 8, &ptr );
         putBits( (uint8)(event.c1>>2), 5, &ptr );
         TRACE3("time %d: Channel pressure, ch=%d, pressure=%d\n", total_time, event.ch+1, event.c1 );
         break;         
      case ME_KEY_PRESSURE:
         checkChannel( &event, &ptr );
         checkOctave( &event, &ptr );
         addStatistics( 11 );
         putBits( (uint8)0xF4, 8, &ptr );
         putBits( (uint8)(event.c1&0x0F), 4, &ptr );
         putBits( (uint8)(event.c2>>2), 5, &ptr );
         TRACE4("time %d: Key pressure, ch=%d, pitch=%d, pressure=%d\n", total_time, event.ch+1, event.c1, event.c2 );
         break;
      case ME_TONE_BANK_HI:
         checkChannel( &event, &ptr );
         addStatistics( 12 );
         putBits( (uint8)0xF5, 8, &ptr );
         putBits( (uint8)(event.c1), 7, &ptr );
         TRACE3("time %d: Tone bank_hi, ch=%d, bank_hi=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_TONE_BANK_LO:
         checkChannel( &event, &ptr );
         addStatistics( 17 );
         putBits( (uint8)0xFA, 8, &ptr );
         putBits( (uint8)(event.c1), 7, &ptr );
         TRACE3("time %d: Tone bank_lo, ch=%d, bank_lo=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_MODULATION_WHEEL:
         checkChannel( &event, &ptr );
         addStatistics( 13 );
         putBits( (uint8)0xF6, 8, &ptr );
         putBits( (uint8)(event.c1), 7, &ptr );
         TRACE3("time %d: Modulation wheel, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_EXPRESSION:
         checkChannel( &event, &ptr );
         addStatistics( 14 );
         putBits( (uint8)0xF7, 8, &ptr );
         putBits( (uint8)(event.c1>>2), 5, &ptr );
         TRACE3("time %d: Expression, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
         break;
      case ME_PITCH_SENS:
         checkChannel( &event, &ptr );
         addStatistics( 15 );
         putBits( (uint8)0xF8, 8, &ptr );
         putBits( (uint8)(event.c1), 7, &ptr );
         TRACE3("time %d: Pitch sense, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
         break;
      default:
         assert(false);
         break;
      }
   }
   if( smf.bits > 0 ) {       /* flush the data inside the cache buffer */
      assert( smf.bits < 8 );
      putBits( (uint8)0, 8-smf.bits, &ptr );
   }
}

/* -------------------------------------------------------------------------------------- */
int CMIDI_Convert( uint8 *buf, int32 *len, int32 time_div )
{
   smf.time_div = time_div;
   if( MIDI_Parse( buf ) < 0 )
      return 0;
   MidiEvent_Optimize();

   MidiEvent_Output( buf+8 );
   buf[0] = 'M';
   buf[1] = 'T';
   buf[2] = 'K';
   buf[3] = smf.time_div;
   buf[4] = (smf.output_bytes>>24) & 0xFF;         /* data length */
   buf[5] = (smf.output_bytes>>16) & 0xFF;         /* data length */
   buf[6] = (smf.output_bytes>>8) & 0xFF;          /* data length */
   buf[7] = smf.output_bytes & 0xFF;               /* data length */
   *len = smf.output_bytes + 8;
   return 1;
}


/* -------------------------------------------------------------------------------------- */
#if defined( CMIDI_STANDALONE )

static void Usage( void )
{
   printf( "Usage:\n    cmidi [-d] in_file out_file\n");
   exit(1);
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

#endif /* CMIDI_STANDALONE */

char* GetFileFormat( const char* filename)
{
	if(strstr(filename,".imy")||strstr(filename,".IMY"))
		return FORMAT_IMY;
	else if(strstr(filename,".mid")||strstr(filename,".MID"))
		return FORMAT_MID;
	else if(strstr(filename,".wav")||strstr(filename,".WAV"))
		return FORMAT_WAV;
	else if(strstr(filename,".mmf")||strstr(filename,".SMAF"))
		return FORMAT_MMF;
	else if(strstr(filename,".mp3")||strstr(filename,".MP3"))
		return FORMAT_MP3;
	else if(strstr(filename,".pcm")||strstr(filename,".PCM"))
		return FORMAT_PCM;
	else if(strstr(filename,".dvi")||strstr(filename,".DVI"))
		return FORMAT_DVI;
	else if(strstr(filename,".amr")||strstr(filename,".AMR"))
		return FORMAT_AMR;
	else if(strstr(filename,".aac")||strstr(filename,".AAC"))
		return FORMAT_AAC;
	else if(strstr(filename,".wma")||strstr(filename,".WMA"))
		return FORMAT_WMA;
	else if(strstr(filename,".m4a")||strstr(filename,".M4A"))
		return FORMAT_M4A;

	return NULL;
}

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

// This is the constructor of a class that has been exported.
CAudioConverter::CAudioConverter()
{ 
}

/*
 * pError:
 *   0 = OK
 *   1 = invalid file format
 *   2 = can't open file
 *   3 = can't malloc
 *   4 = read file fail
 *   5 = convert cmidi fail
 */
CAudioResource* CAudioConverter::GetAudioResource( const char* sAudioFileName, int compress_MIDI, int* pError )
{
	CAudioResource* resource = NULL;
	FILE *pFile;
	char* pFormat = GetFileFormat( sAudioFileName );
	int file_len;
	
	if( pFormat )
	{
		pFile = fopen( sAudioFileName, "rb" );
		resource = new CAudioResource();
      
		if( pFile == NULL )
		{
			*pError = 2;
			return NULL;
		}
	
		fseek( pFile, 0, SEEK_END );
		file_len = ftell( pFile );
		fseek( pFile, 0, SEEK_SET );
   
		resource->data = (unsigned char *)malloc( file_len );
		if( resource->data == NULL )
		{
			*pError = 3;
			delete resource;
			fclose( pFile );
			return NULL;
		}
	
		if( fread( (void*)resource->data, 1, file_len, pFile ) != (unsigned int)file_len )
		{
			*pError = 4;
			delete resource;
			fclose( pFile );
			return NULL;
		}
		fclose( pFile );
		if( compress_MIDI != 0 && strcmp( pFormat, FORMAT_MID ) == 0 )
		{
			if( compress_MIDI == 1 )
			{
				if( DSPSYN_CMIDI_Convert( (unsigned char*)resource->data, &file_len ) == 0 )
				{
					*pError = 5;
					delete resource;
					return NULL;
				}
			}
			else
			{
				if( SWSYN_CMIDI_Convert( (unsigned char*)resource->data, &file_len ) == 0 )
				{
					*pError = 5;
					delete resource;
					return NULL;
				}
			}
		}
   
		resource->len = file_len;
		resource->format = atoi( pFormat );
		*pError = 0;
	}
	else
	   *pError = 1;

	return resource;
}

CAudioResource::CAudioResource() : data( NULL ), len( 0 ), format( 0 )
{
}

CAudioResource::~CAudioResource()
{
	if( data != NULL )
		free( (void*)data );
}
