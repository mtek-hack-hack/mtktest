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
 * jsmf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SMF playback using DSP wavetable synthesizer
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
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( DSP_WT_SYN )

#include "dspsyn.h"
#include "media.h"
#include "fsal.h"

#define CMIDI_SUPPORT

#define MIDI_STATE_READY         1
#define MIDI_STATE_PLAYING       2
#define MIDI_STATE_PAUSED        3
#define MIDI_STATE_ABORT         4
#define MIDI_STATE_ENDING        5
#define MIDI_STATE_RTMIDI_ONLY   6

/* Midi events */
#define ME_NONE                  0
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
#define ME_LFO_FREQ              19
#define ME_LFO_DEPTH             20
#define ME_TIMER                 21

#define MAX_MIDI_CHANNEL         16
#define MSG_SIZE                 40
#define EVENT_Q_SIZE             32

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
   int32  dtime;      /* <0 -> ticks,   >=0 ms */
   uint8  ch;
   uint8  type;
   uint8  c1;
   uint8  c2;
} MidiEvent;

typedef struct {
   Media_Event event;
   int32       note;
} ExtCallbackEvent;

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
   int32             smpte_time;  // used for division < 0 case  
   int32             midi_tick_time;  
   int32             midi_qn_time; // quarter note time defined in Tempo message 
   int32             midi_event_time; 
   int32             midi_event_time_factor; 
   int32             played_time; 
   int32             active_tempo;
   int32             tempo;                  /* ms per quarter note, the default tempo is 120 beats/minute */
   int32             java_tempo;
   int32             playRate;
   int32             tsRate;                 /* Used by time stretch 100 is the normal speed */
   int32             ticks;
   uint16            ntrks;
   int16             division;               /* ticks per quarter note */
   MidiChannel       *channel[MAX_MIDI_CHANNEL];
   uint8             msgbuff[MSG_SIZE];      /* message buffer */
   uint16            noteMgr[16*16];
   int8              pitchTranspose;
   bool              eof;
   uint8             tempo_state;
   Media_SMF_Param   param;
   bool              nrpn;
   int8              rpn_msb[16];
   int8              rpn_lsb[16];
   const uint8       *rtmidi_ptr;
   uint16            rtmidi_count;
   uint8             rtmidi_running;
   uint8             rtmidi_status;
   /* Event queue */
   uint16            evq_head;
   uint16            evq_count;
   MidiEvent         evq_buf[EVENT_Q_SIZE];
   RINGBUFFER_T(ExtCallbackEvent,10)  extevent;
   uint16            mipMuteState;
} MIDI_Player;

#if defined(AUD_TIME_STRETCH)
Media_Handle *TS_Midi_Handle;   // KH: Add for Time Stretch
#endif


extern int32 countMSB(uint32 data); 
/* ------------------------------------------------------------------- */

#define  EventQ_Empty(player)    (player->evq_count==0)
#define  EventQ_Full(player)     (player->evq_count==EVENT_Q_SIZE)
#define  EventQ_Count(player)    (player->evq_count)
#define  EventQ_Peek(player)     (&player->evq_buf[player->evq_head])
#define  EventQ_Init(player)     {player->evq_head = player->evq_count = 0;    }
#define  EventQ_Put(player,t, ty, c, a, b)    {  \
   MidiEvent *nt = &player->evq_buf[(player->evq_head + player->evq_count) & (EVENT_Q_SIZE-1)];  \
   nt->dtime = -(int32)t;        \
   nt->type = ty;                \
   nt->ch   = c;                 \
   nt->c1   = a;                 \
   nt->c2   = b;                 \
   player->evq_count++;          \
}

#if defined( CMIDI_SUPPORT )
#define  EventQ_Put2(player,t, ty, c, a, b)    {  \
   MidiEvent *nt = &player->evq_buf[(player->evq_head + player->evq_count) & (EVENT_Q_SIZE-1)];  \
   nt->dtime = (int32)t;         \
   nt->type = ty;                \
   nt->ch   = c;                 \
   nt->c1   = a;                 \
   nt->c2   = b;                 \
   player->evq_count++;          \
}
#endif

#define  EventQ_Consume()  {     \
   player->evq_count--;          \
   player->evq_head = (uint16)((player->evq_head+1) & (EVENT_Q_SIZE-1));  \
}

/* ------------------------------------------------------------------- */
#define BEND_FIX(a)  ((uint32)((a)*(1<<16)))

const static int8 chantype[] = {
   0, 0, 0, 0, 0, 0, 0, 0,    /* 0x00 through 0x70 */
   2, 2, 2, 2, 1, 1, 2, 0     /* 0x80 through 0xf0 */
};

const static uint32 bend_coarse[60] = {
   BEND_FIX(1.0000000000000000), BEND_FIX(1.0594630943592953),
   BEND_FIX(1.1224620483093730), BEND_FIX(1.1892071150027210),
   BEND_FIX(1.2599210498948732), BEND_FIX(1.3348398541700344),
   BEND_FIX(1.4142135623730951), BEND_FIX(1.4983070768766815),
   BEND_FIX(1.5874010519681994), BEND_FIX(1.6817928305074290),
   BEND_FIX(1.7817974362806785), BEND_FIX(1.8877486253633868),
   BEND_FIX(2.0000000000000000), BEND_FIX(2.1189261887185906),
   BEND_FIX(2.2449240966187460), BEND_FIX(2.3784142300054421),
   BEND_FIX(2.5198420997897464), BEND_FIX(2.6696797083400687),
   BEND_FIX(2.8284271247461903), BEND_FIX(2.9966141537533630),
   BEND_FIX(3.1748021039363992), BEND_FIX(3.3635856610148580),
   BEND_FIX(3.5635948725613571), BEND_FIX(3.7754972507267741),
   BEND_FIX(4.0000000000000000), BEND_FIX(4.2378523774371812),
   BEND_FIX(4.4898481932374912), BEND_FIX(4.7568284600108841),
   BEND_FIX(5.0396841995794928), BEND_FIX(5.3393594166801366),
   BEND_FIX(5.6568542494923806), BEND_FIX(5.9932283075067270),
   BEND_FIX(6.3496042078727974), BEND_FIX(6.7271713220297160),
   BEND_FIX(7.1271897451227151), BEND_FIX(7.5509945014535473),
   BEND_FIX(8.0000000000000000), BEND_FIX(8.4757047548743625),
   BEND_FIX(8.9796963864749824), BEND_FIX(9.5136569200217682),
   BEND_FIX(10.079368399158986), BEND_FIX(10.678718833360273),
   BEND_FIX(11.313708498984761), BEND_FIX(11.986456615013454),
   BEND_FIX(12.699208415745595), BEND_FIX(13.454342644059432),
   BEND_FIX(14.254379490245430), BEND_FIX(15.101989002907095),
   BEND_FIX(16.000000000000000), BEND_FIX(16.951409509748721),
   BEND_FIX(17.959392772949972), BEND_FIX(19.027313840043536),
   BEND_FIX(20.158736798317967), BEND_FIX(21.357437666720553),
   BEND_FIX(22.627416997969522), BEND_FIX(23.972913230026901),
   BEND_FIX(25.398416831491197), BEND_FIX(26.908685288118864),
   BEND_FIX(28.508758980490853), BEND_FIX(30.203978005814196),
};

static int16 bend( int32 pb )
{
   int32 frac = (pb >> 5) & 0xFF;

   pb = pb >> 13;
   if( pb >= 59 ) {
      pb = 59;
      frac = 0;
   }
   return (int16)((bend_coarse[pb] + ((bend_coarse[pb+1]-bend_coarse[pb]) * frac >> 8)) >> 6);
}

/* ------------------------------------------------------------------- */
static const kal_int8 programList[] = {
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
   20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
   40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
   60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
   80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
  100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
  120,121,122,123,124,125,126,127
};

static const uint8 instrumentName[128][23] = {
   "Acoustic Grand Piano  ",     // 0
   "Bright Acoustic Piano ",
   "Electric Grand Piano  ",
   "Honky-Tonk            ",
   "Electric Piano 1      ",
   "Electric Piano 2      ",
   "Harpsichord           ",
   "Clavinet              ",
   "Celesta               ",
   "Glockenspiel          ",
   "Music Box             ",     // 10
   "Vibraphone            ",
   "Marimba               ",
   "Xylophone             ",
   "Tubular Bells         ",
   "Dulcimer              ",
   "Drawbar Organ         ",
   "Percussive Organ      ",
   "Rock Organ            ",
   "Church Organ          ",
   "Reed Organ            ",     // 20
   "Accoridan             ",
   "Harmonica             ",
   "Tango Accordian       ",
   "Acoustic Guitar(nylon)",
   "Acoustic Guitar(steel)",
   "Electric Guitar(jazz) ",
   "Electric Guitar(clean)",
   "Electric Guitar(muted)",
   "Overdriven Guitar     ",
   "Distortion Guitar     ",     // 30
   "Guitar Harmonics      ",
   "Acoustic Bass         ",
   "Electric Bass(finger) ",
   "Electric Bass(pick)   ",
   "Fretless Bass         ",
   "Slap Bass 1           ",
   "Slap Bass 2           ",
   "Synth Bass 1          ",
   "Synth Bass 2          ",
   "Violin                ",     // 40
   "Viola                 ",
   "Cello                 ",
   "Contrabass            ",
   "Tremolo Strings       ",
   "Pizzicato Strings     ",
   "Orchestral Harp       ",
   "Timpani               ",
   "String Ensemble 1     ",
   "String Ensemble 2     ",
   "SynthStrings 1        ",     // 50
   "SynthStrings 2        ",
   "Choir Aahs            ",
   "Voice Oohs            ",
   "Synth Voice           ",
   "Orchestra Hit         ",
   "Trumpet               ",
   "Trombone              ",
   "Tuba                  ",
   "Muted Trumpet         ",
   "French Horn           ",     // 60
   "Brass Section         ",
   "SynthBrass 1          ",
   "SynthBrass 2          ",
   "Soprano Sax           ",
   "Alto Sax              ",
   "Tenor Sax             ",
   "Baritone Sax          ",
   "Oboe                  ",
   "English Horn          ",
   "Bassoon               ",     // 70
   "Clarinet              ",
   "Piccolo               ",
   "Flute                 ",
   "Recorder              ",
   "Pan Flute             ",
   "Blown Bottle          ",
   "Skakuhachi            ",
   "Whistle               ",
   "Ocarina               ",
   "Lead 1 (square)       ",     // 80
   "Lead 2 (sawtooth)     ",
   "Lead 3 (calliope)     ",
   "Lead 4 (chiff)        ",
   "Lead 5 (charang)      ",
   "Lead 6 (voice)        ",
   "Lead 7 (fifths)       ",
   "Lead 8 (bass+lead)    ",
   "Pad 1 (new age)       ",
   "Pad 2 (warm)          ",
   "Pad 3 (polysynth)     ",     // 90
   "Pad 4 (choir)         ",
   "Pad 5 (bowed)         ",
   "Pad 6 (metallic)      ",
   "Pad 7 (halo)          ",
   "Pad 8 (sweep)         ",
   "FX 1 (rain)           ",
   "FX 2 (soundtrack)     ",
   "FX 3 (crystal)        ",
   "FX 4 (atmosphere)     ",
   "FX 5 (brightness)     ",     // 100
   "FX 6 (goblins)        ",
   "FX 7 (echoes)         ",
   "FX 8 (sci-fi)         ",
   "Sitar                 ",
   "Banjo                 ",
   "Shamisen              ",
   "Koto                  ",
   "Kalimba               ",
   "Bagpipe               ",
   "Fiddle                ",     // 110
   "Shanai                ",
   "Tinkle Bell           ",
   "Agogo                 ",
   "Steel Drums           ",
   "Woodblock             ",
   "Taiko Drum            ",
   "Melodic Tom           ",
   "Synth Drum            ",
   "Reverse Cymbal        ",
   "Guitar Fret Noise     ",     // 120
   "Breath Noise          ",
   "Seashore              ",
   "Bird Tweet            ",
   "Telephone Ring        ",
   "Helicopter            ",
   "Applause              ",
   "Gunshot               "
};

static const uint8 percussionName[85-33][19] = {
   "Unknown           ",        /* 34 */
   "Acoustic Bass Drum",        /* 35 */
   "Bass Drum 1       ",
   "Side Stick        ",
   "Acoustic Snare    ",
   "Hand Clap         ",
   "Electric Snare    ",
   "Low Floor Tom     ",
   "Closed Hi-Hat     ",
   "High Floor Tom    ",
   "Pedal Hi-Hat      ",
   "Low Tom           ",
   "Open Hi-Hat       ",
   "Low-Mid Tom       ",
   "Hi-Mid Tom        ",
   "Crash Cymbal 1    ",
   "High Tom          ",
   "Ride Cymbal 1     ",
   "Chinese Cymbal    ",
   "Ride Bell         ",
   "Tambourine        ",
   "Splash Cymbal     ",
   "Cowbell           ",
   "Crash Cymbal 2    ",
   "Vibraslap         ",
   "Ride Cymbal 2     ",
   "Hi Bongo          ",
   "Low Bongo         ",
   "Mute Hi Conga     ",
   "Open Hi Conga     ",
   "Low Conga         ",
   "High Timbale      ",
   "Low Timbale       ",
   "High Agogo        ",
   "Low Agogo         ",
   "Cabasa            ",
   "Maracas           ",
   "Short Whistle     ",
   "Long Whistle      ",
   "Short Guiro       ",
   "Long Guiro        ",
   "Claves            ",
   "Hi Wood Block     ",
   "Low Wood Block    ",
   "Mute Cuica        ",
   "Open Cuica        ",
   "Mute Triangle     ",
   "Open Triangle     ",        /* 81 */
   "Unknown           ",        /* 82 */
   "Unknown           ",
   "Bell Tree         ",
   "Unknown           ",        /* 85 */
};

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
static int16 egetc( MidiTrack *trk )       /* read a single character and abort on EOF */
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
   int16 c;

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

static void Update_Tempo( MIDI_Player *player )
{
   int32 rate;

   rate = 1024 * player->tempo / (uint32)player->division;
   rate = rate * 10000 / (player->playRate * player->tsRate);
   player->active_tempo = rate;
}

static int32 Ticks2ms( MIDI_Player *player, int32 ticks )
{
   if( player->division > 0 ) {
      ticks = ticks * player->active_tempo >> 10;
      return ticks;
   }
   return (ticks * player->smpte_time >> 10);
}

static int32 Ticks2musicTime( MIDI_Player *player, int32 ticks )
{
   if( player->division > 0 ) {
      ticks = ticks * player->midi_tick_time >> 10;
      return ticks;
   }
   return (ticks * player->smpte_time >> 10);
}

/* ------------------------------------------------------------------- */
static void msg_read( MIDI_Player *player, MidiTrack *trk )
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

/* ------------------------------------------------------------------- */
static int8 TransformChannelMessage( MIDI_Player *player, int8 status, int8 *c1, int8 *c2 )
{
   int8 type = ME_NONE;
   int8 ch = (int8)(status & 0xf);

   switch ( status & 0xf0 ) {
   case 0x80:
      type = ME_NOTEOFF;                     
      break;
   case 0x90:
      type = (int8)(( *c2 == 0 )? ME_NOTEOFF : ME_NOTEON);            
      break;     
   case 0xb0:     /* Controller message */
      switch( *c1 ) {
      case 0x00:
         type = ME_TONE_BANK_HI;
         break;
      case 0x20:
         type = ME_TONE_BANK_LO;
         break;
      case 0x01:
         type = ME_MODULATION_WHEEL;
         break;
      case 0x07:
         type = ME_MAINVOLUME;
         break;
      case 0x0A:
         type = ME_PAN;
         break;
      case 0x0B:
         type = ME_EXPRESSION;
         break;
      case 0x40:
         type = ME_SUSTAIN;
         break;

      case 98:    player->nrpn=true;  player->rpn_lsb[ch] = *c2;    break;
      case 99:    player->nrpn=true;  player->rpn_msb[ch] = *c2;    break;
      case 100:   player->nrpn=false; player->rpn_lsb[ch] = *c2;    break;
      case 101:   player->nrpn=false; player->rpn_msb[ch] = *c2;    break;

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
            *c2 = 2;
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
   return type;
}

static void ChannelMessage( MIDI_Player *player, int32 dtime, int8 status, int8 c1, int8 c2 )
{
   int8 type = TransformChannelMessage( player, status, &c1, &c2 );
   if( type != ME_NONE || dtime > 0 )
      EventQ_Put( player, dtime, type, status&0x0F, c1, c2 );
}

static void SetMIP( MIDI_Player *player, uint8 *mip )
{
   int32 I, mip_length;
   uint16 MuteState, MIP;

   for(I= 0; I < 16 ; I ++) 
      if(mip[2*I] >= MAX_MIDI_CHANNEL )
         break;
   mip_length = I;      
   MIP = (uint16) mip[2*I - 1];
    
   if(MIP > MAX_POLYPHONY)
   {
      MuteState = 0xFFFF;
      for(I = 0; I < mip_length; I ++)
      {
         if(mip[2*I+1] <= MAX_POLYPHONY)
            MuteState &= ~(1<<mip[2*I]);       
      }   
      player->mipMuteState = MuteState;
   }        
}    

static void SysExEvent( MIDI_Player *player, uint8 *m )
{
   switch  ( m[0] ) {
   case 0x7F:                                /* Universal realtime system exclusive */
      if( m[2] == 0x0B && m[3] == 0x01 )
         SetMIP( player, &m[4] );
      break;
   }
}

static int16 ReadTrack( MIDI_Player *player, int32 dtime, MidiTrack *trk )     /* read a track chunk */
{
   /* This array is indexed by the high half of a status byte.  It's */
   /* value is either the number of bytes needed (1 or 2) for a channel */
   /* message, or 0 (meaning it's not  a channel message). */
   int16 c, c1, type;
   int needed;

   c = egetc( trk );

   if( c == 0xFF ) {                /* meta event */
      type = egetc( trk );
      msg_read( player, trk );
      switch  ( type ) {
      case 0x51:  /* Set tempo */
         EventQ_Put( player, dtime, ME_TEMPO, player->msgbuff[0], player->msgbuff[1], player->msgbuff[2] );
         break;
      case 0x2F:  /* End of Track */
         trk->toberead = 0;
         return 0;
      default:
         if( dtime > 0 )
            EventQ_Put( player, dtime, ME_NONE, 0, 0, 0 );
         break;
      }
   }
   else if( c == 0xF0 ) {           /* start of system exclusive */
      msg_read( player, trk );
      SysExEvent( player, player->msgbuff );
      if( dtime > 0 )
         EventQ_Put( player, dtime, ME_NONE, 0, 0, 0 );
   }
   else if( c == 0xF7 ) {           /* sysex continuation or arbitrary stuff */
      msg_bypass( trk );
      if( dtime > 0 )
         EventQ_Put( player, dtime, ME_NONE, 0, 0, 0 );
   }
   else {
      if( (c & 0x80) == 0 ) {       /* running status? */
         if( trk->status == 0 )
            return -1;
         trk->running = true;
      }
      else {
         trk->status = (uint8)c;
         trk->running = false;
      }

      needed = chantype[ (trk->status>>4) & 0xf ];

      if( needed ) {                /* ie. is it a channel message? */
         if ( trk->running )
            c1 = c;
         else
            c1 = egetc(trk);
         ChannelMessage( player, dtime, trk->status, (int8)c1, (int8)((needed>1) ? egetc(trk) : 0) );
      }
   }
   trk->deltatime = ReadVarNum( trk );
   if( trk->toberead == 0 )
      trk->deltatime = 0;
   return 0;
}

static int8 rtmidiGet( MIDI_Player *player )
{
   if( player->rtmidi_count == 0 )
      return 0;
   player->rtmidi_count--;
   return *player->rtmidi_ptr++;
}

static void rtmidiError( MIDI_Player *player )
{
   player->rtmidi_count = 0;
}

static int32 rtmidiReadVarNum( MIDI_Player *player )
{
   int32 value;
   int16 c;

   c = rtmidiGet( player );
   if( !(c & 0x80) )    return c;
   value = c & 0x7F;
   c = rtmidiGet( player );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = rtmidiGet( player );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = rtmidiGet( player );
   value = (value << 7) + (c & 0x7f);
   return value;
}

static void rtmidi_msg_read( MIDI_Player *player )
{
   uint32 I;
   uint32 count = rtmidiReadVarNum( player );

   if( count < MSG_SIZE - 1 ) {
      for( I = 0; I < count; I++ ) {
         player->msgbuff[I] = rtmidiGet( player );
      }
      player->msgbuff[I] = 0;
   }
   else {
      player->msgbuff[0] = 0;
      if( count > player->rtmidi_count )
         player->rtmidi_count = 0;
      else {
         player->rtmidi_count -= count;
         player->rtmidi_ptr += count;
      }
   }
}

static void ReadRTMidiEvent( MIDI_Player *player, MidiEvent *nt )
{
   int16 c;
   int needed;

   nt->type = ME_NONE;

   c = rtmidiGet( player );

   if( c == 0xFF ) {                /* meta event */
      rtmidiGet( player );                  /* meta event should be ignored in RT MIDI mode */
      rtmidi_msg_read( player );
   }
   else if( c == 0xF0 ) {           /* start of system exclusive */
      rtmidi_msg_read( player );
      SysExEvent( player, player->msgbuff );
   }
   else if( c == 0xF7 ) {           /* sysex continuation or arbitrary stuff */
      rtmidi_msg_read( player );
   }
   else {
      if( (c & 0x80) == 0 ) {       /* running status? */
         if( player->rtmidi_status == 0 ) {
            rtmidiError( player );
            return;
         }
         player->rtmidi_running = true;
      }
      else {
         player->rtmidi_status = (uint8)c;
         player->rtmidi_running = false;
      }

      needed = chantype[ (player->rtmidi_status>>4) & 0xf ];

      if( needed ) {                /* ie. is it a channel message? */
         nt->c1 = ( player->rtmidi_running )? c : rtmidiGet( player );
         nt->c2 = ( needed > 1 )? rtmidiGet( player ):0;
         nt->ch = player->rtmidi_status & 0x0F;
         nt->type = TransformChannelMessage( player, player->rtmidi_status, (int8 *)&(nt->c1), (int8 *)&(nt->c2) );
      }
   }
}

/* return true if EOF encountered */
static void midiParse( MIDI_Player *player )
{
   int16       I;
   int16       next_trk;
   int32       delta;
   MidiTrack   *trk;

   while( !EventQ_Full(player) ) {
      next_trk = MAX_TRACK;
      delta    = 0x7FFFFF;
      for( I = 0 ; I < player->ntrks; I++ ) {
         trk = &player->midi.smf.tracks[I];
         if( trk->toberead > 0 && trk->deltatime < delta ) {
            delta    = trk->deltatime;
            next_trk = I;
            if( delta == 0 )
               break;
         }
      }
      if( next_trk == MAX_TRACK ) {       /* No unhandled MIDI data left */
         player->eof = true;
         break;
      }
      if( delta > 0 ) {
         for( I = 0 ; I < player->ntrks; I++ ) {
            trk = &player->midi.smf.tracks[I];
            if( trk->toberead > 0 )
               trk->deltatime -= delta;
         }
      }
      ReadTrack( player, delta, &player->midi.smf.tracks[next_trk] );
   }
}

#if defined( CMIDI_SUPPORT )
/* ----------------------------------------------------------------- */
static int32 cmidi_getBits( MIDI_Player *player, int32 len )
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

void cmidi_Parse( MIDI_Player *player )
{
   int32 dtime = 0;
   int32 c1, c2;
   uint8 type;

   while( !EventQ_Full(player) ) {
      if( player->midi.cmi.len <= 0 ) {
         player->eof = true;
         break;
      }
      type = ME_NONE;
      c1 = 0; c2 = 0;
      switch( cmidi_getBits( player, 2 ) ) {
      case 0:
         c1 = cmidi_getBits( player, 4 ) + (player->midi.cmi.octave<<4);
         c2 = cmidi_getBits( player, 5 ) << 2;
         type = ME_NOTEON;
         break;
      case 1:
         c1 = cmidi_getBits( player, 4 ) + (player->midi.cmi.octave<<4);         
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
            dtime = (cmidi_getBits( player,4)+1) * 18;
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
                  c2 = cmidi_getBits( player, 5 ) << 2;
                  type = ME_PAN;
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
               case 5:                             /* tone bank high */
                  c2 = cmidi_getBits( player, 7 );
                  type = ME_TONE_BANK_HI;
                  break;
               case 6:                             /* modulation wheel */
                  c2 = cmidi_getBits( player, 7 );
                  type = ME_MODULATION_WHEEL;
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
                  dtime = (c1+1) * 18;
                  break;
               case 2:                             /* tone bank low */
                  c2 = cmidi_getBits( player, 7 );
                  type = ME_TONE_BANK_LO;
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
         EventQ_Put2( player, dtime, type, player->midi.cmi.channel, c1, c2 );
         dtime = 0;
      }
   }
}

/* ----------------------------------------------------------------- */
typedef struct {
   const uint8 *ptr;
   uint32      len;
   uint16      cache;
   uint16      bits;
} CMidi_Type;

static int32 cmidi_getBits2( CMidi_Type *cmidi, int32 len )
{
   int32 cache = cmidi->cache;
   int32 bits = cmidi->bits;

   if( len > bits ) {
      cache = (uint16)((cache<<8) + *cmidi->ptr++);
      bits += 8;
      cmidi->len--;
   }
   bits -= len;
   cmidi->cache = cache & ((1<<bits)-1);
   cmidi->bits = bits;
   return (cache >> bits);
}

int32 cmidi_GetDuration( const uint8 *ptr )
{
   int32 total_time = 0;
   int32 bits;
   CMidi_Type cmidi;

   cmidi.bits = 0;
   cmidi.cache = 0;
   cmidi.len = get32bit( ptr );
   cmidi.ptr = ptr + 4;

   while( cmidi.len > 0 ) {
      switch( cmidi_getBits2( &cmidi,2) ) {
      case 0:     cmidi_getBits2( &cmidi, 4 );   cmidi_getBits2( &cmidi, 5 );  break;
      case 1:     cmidi_getBits2( &cmidi, 4 );     break;
      case 2:
         if( !cmidi_getBits2( &cmidi,1) )     cmidi_getBits2( &cmidi, 4 );
         else                             cmidi_getBits2( &cmidi, 3 );
         break;
      case 3:
         if( !cmidi_getBits2( &cmidi,1) ) {      /* dtime */
            bits = cmidi_getBits2( &cmidi, 4 );
            total_time += (bits+1);
         }
         else {
            switch( cmidi_getBits2( &cmidi,2) ) {
            case 0:     cmidi_getBits2( &cmidi, 5 );     break;
            case 1:     cmidi_getBits2( &cmidi, 7 );     break;
            case 2:
               switch( cmidi_getBits2( &cmidi,3) ) {
               case 0:  case 1:  case 3:  case 7:
                  cmidi_getBits2( &cmidi, 5 );     break;
               case 4:  cmidi_getBits2( &cmidi, 4 );  cmidi_getBits2( &cmidi, 5 );   break;
               case 2:  case 5:  case 6:
                  cmidi_getBits2( &cmidi, 7 );     break;
               }
               break;
            case 3:
               switch( cmidi_getBits2( &cmidi,3) ) {
               case 0:  cmidi_getBits2( &cmidi, 7 );     break;
               case 1:
                  bits = cmidi_getBits2( &cmidi, 6 );
                  bits = (bits << 4) + cmidi_getBits2( &cmidi, 4 );
                  total_time += (bits+1);
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
   }
   return total_time;
}

#endif
/* ------------------------------------------------------------------- */
/*  Functions to be called while processing the MIDI file.             */
/* ------------------------------------------------------------------- */
static void ME_None( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   (void)me;
   (void)cmd;
   (void)handle;
}
/* ----------------------------------------------------------------- */
static MidiChannel *VerifyMidiChannel( Media_Handle *handle, uint8 ch )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   MidiChannel *chan = player->channel[ch];

   if( chan == (MidiChannel*)0 ) {
      chan = player->channel[ch] = DSPSYN_GetMidiChannel( ch == 9 );
      if( chan == (MidiChannel *)0 )
         return (MidiChannel *)0;
   }
   chan->flag |= CHANNEL_FLAG_ACTIVE;
   return chan;
}

static void ME_NoteOff( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );
   MIDI_Player *player = (MIDI_Player *)handle->data;

   if( chan == (MidiChannel *)0 || player->mipMuteState & (1 << me->ch))
      return;

   if( chan->program == 0x7C && chan->bank == 2454 ) {
      ExtCallbackEvent evt;
      evt.note = me->c1;
      if( evt.note >= 60 )
         evt.event = MEDIA_LED_OFF;
      else if( evt.note >= 55 )
         evt.event = MEDIA_VIBRATOR_OFF;
      else
         evt.event = MEDIA_BACKLIGHT_OFF;
      RB_PUT( player->extevent, evt );
      if( RB_COUNT( player->extevent ) == 1 )
         handle->handler( handle, MEDIA_EXTENDED_EVENT );   /* emit extended event */
      return;
   }

   if( chan->program == 0x7C && chan->bank == ((0x79<<7) + 0x06) ) {
      if( chan->flag & CHANNEL_FLAG_VIBE ) {
         chan->flag &= ~CHANNEL_FLAG_VIBE;
         handle->handler( handle, MEDIA_VIBRATOR_OFF );   /* turn on vibrator */
      }
      return;
   }
   
   if(me->ch != 9)  
   {                       
      uint32 j;
      uint16 *ptrChNoteArray; 
      uint16 msbIdx, chNoteArray;
      bool findNote;  
   
      chNoteArray = *(player->noteMgr + me->ch);     
      
      findNote = false; 
      while(chNoteArray > 0) 
      {               
         msbIdx = countMSB(chNoteArray);                                          
         ptrChNoteArray = player->noteMgr + ( msbIdx << 4);     
         for(j = 0 ; j < 16 ; j ++)
         {
            uint16 note;                  
            note = (*ptrChNoteArray++) & 0xFF  ;         
            if( note == (uint16)me->c1)
            {
               findNote = true;
               break;
            }                    
         }
         if(findNote)
         {
            ptrChNoteArray--;
            me->c1 = (*ptrChNoteArray) >> 8;
            *ptrChNoteArray = 0;                                              
            break;
         }                              
         chNoteArray -= (1 << msbIdx);                                      
      }                         
   }         
         
   cmd[0] = 2;
   cmd[1] = 0x0100 + chan->dspChannel;
   cmd[2] = ((uint16)me->c1 << 8) + (uint16)me->c2;
}

static void ME_NoteOn( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   uint16 vel;
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );
   MIDI_Player *player = (MIDI_Player *)handle->data;

   if( chan == (MidiChannel *)0 || player->mipMuteState & (1 << me->ch))
      return;

   if( chan->program == 0x7C && chan->bank == 2454 ) {
      ExtCallbackEvent evt;
      evt.note = me->c1;
      if( evt.note >= 60 )
         evt.event = MEDIA_LED_ON;
      else if( evt.note >= 55 )
         evt.event = MEDIA_VIBRATOR_ON;
      else
         evt.event = MEDIA_BACKLIGHT_ON;
      RB_PUT( player->extevent, evt );
      if( RB_COUNT( player->extevent ) == 1 )
         handle->handler( handle, MEDIA_EXTENDED_EVENT );   /* emit extended event */
      return;
   }

   if( chan->program == 0x7C && chan->bank == ((0x79<<7) + 0x06) ) {
      if( (chan->flag & CHANNEL_FLAG_VIBE) == 0 ) {
         chan->flag |= CHANNEL_FLAG_VIBE;
         handle->handler( handle, MEDIA_VIBRATOR_ON );   /* turn on vibrator */
      }
      return;
   }
   vel = (uint16)me->c2 * handle->volume_level / 100;
   if( vel > 127 )
      vel = 127;
      
   if(me->ch != 9)  
   {
      int32 I;         
      uint32 J; 
      uint16 msbIdx, chNoteArray, availableArray;
      bool findEmpty;
      uint16 *ptrChNoteArray;
      
      chNoteArray = *(player->noteMgr + me->ch); 
             
      I = me->c1 + player->pitchTranspose;
      if(I >= 0 && I <= 107)
      {                                                      
         availableArray = *(player->noteMgr + 9);            
         if(chNoteArray == 0) 
         {             
            if(availableArray == 0)
            { 
               cmd[0] = 2;
               cmd[1] = 0x0000 + chan->dspChannel;
               cmd[2] = ((uint16)me->c1 << 8) + vel;
               return;
            }
                                                      
            msbIdx = countMSB(availableArray);                                                           
            chNoteArray = (1 << msbIdx);
            *(player->noteMgr + me->ch) = chNoteArray;                      
            availableArray -= (1 << msbIdx);
            *(player->noteMgr + 9) = availableArray;                                                                                          
         }
                                
         findEmpty = false; 
         
         while(chNoteArray > 0)  
         {               
            msbIdx = countMSB(chNoteArray);                                                                      
            ptrChNoteArray = player->noteMgr + ( msbIdx << 4);     
            for(J = 0 ; J < 16 ; J ++)
            {                          
               if(*ptrChNoteArray++ == 0)
               {
                  findEmpty = true;
                  break;
               }   
            }
            if(findEmpty)
            {
               ptrChNoteArray--;
               *ptrChNoteArray = (I << 8) + (me->c1);                               
               break;
            }                                                                     
            chNoteArray -= (1 << msbIdx);      
         }
                         
         if(!findEmpty)
         {
            if(availableArray == 0) 
            {
               cmd[0] = 2;
               cmd[1] = 0x0000 + chan->dspChannel;
               cmd[2] = ((uint16)me->c1 << 8) + vel;
               return;
            }            
            msbIdx = countMSB(availableArray);                                                                                                                                               
            *(player->noteMgr + me->ch) |= (1 << msbIdx);
            availableArray -= (1 << msbIdx);
            *(player->noteMgr + 9) = availableArray;
            ptrChNoteArray = player->noteMgr + (msbIdx << 4);  
            *ptrChNoteArray = (I << 8) + (me->c1);                                                                                                                                    
         }  
         me->c1 = I;                                           
      }
      else 
      {
         cmd[0] = DSPSYN_CMD_CONTINUE;
         return;      
      }                                    
   }   
   cmd[0] = 2;
   cmd[1] = 0x0000 + chan->dspChannel;
   cmd[2] = ((uint16)me->c1 << 8) + vel;
}

/* ----------------------------------------------------------------- */

static void ME_Key_Pressure( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 2;
   cmd[1] = 0x0A00 + chan->dspChannel;
   cmd[2] = ((uint16)me->c1 << 8) + (uint16)me->c2;
}

static void ME_Volume( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 2;
   cmd[1] = 0x0500 + chan->dspChannel;
   cmd[2] = (uint16)me->c2;
   chan->volume = me->c2;
}

static void ME_Pan( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 2;
   cmd[1] = 0x0600 + chan->dspChannel;
   cmd[2] = (uint16)me->c2;
}

static void ME_Expression( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 2;
   cmd[1] = 0x0200 + chan->dspChannel;
   cmd[2] = (uint16)me->c2;
}

static void ME_Sustain( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 2;
   cmd[1] = 0x0700 + chan->dspChannel;
   cmd[2] = (uint16)me->c2;
}

static void ME_Pitch_Wheel( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   int16 pb = (int16)(((int16)me->c1 + ((int16)me->c2 << 7)) - 0x2000);
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   if( pb > 0 )
      pb = bend( chan->pitchsens * pb );
   else if( pb < 0 )
      pb = -bend( chan->pitchsens * (-pb) );

   cmd[0] = 2;
   cmd[1] = 0x0300 + chan->dspChannel;
   cmd[2] = (uint16)pb;
}

static void ME_Pitch_Sense( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   chan->pitchsens = (int16)me->c2;
   cmd[0] = DSPSYN_CMD_CONTINUE;
}

static void ME_Program( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
   
   if(me->c1 >= 128)
      me->c1 = 0;    
   chan->program = me->c1;
   cmd[0] = 2;
   cmd[1] = 0x0400 + chan->dspChannel;
   cmd[2] = (uint16)me->c1;
}

static void ME_Channel_Pressure( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 2;
   cmd[1] = 0x0B00 + chan->dspChannel;
   cmd[2] = (uint16)me->c1;
}

static void ME_Bank_HI( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
   chan->bank = ((int16)me->c2<<7) + (chan->bank&0x7F);
   cmd[0] = DSPSYN_CMD_CONTINUE;
}

static void ME_Bank_LO( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
   chan->bank = (chan->bank&0x3F80) + (int16)me->c2;
   cmd[0] = DSPSYN_CMD_CONTINUE;
}

/* Process the All Notes Off event */
static void ME_All_Notes_Off( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 1;
   cmd[1] = 0x0C00 + chan->dspChannel;
}

/* Process the All Sounds Off event */
static void ME_All_Sounds_Off( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   MidiChannel *chan = VerifyMidiChannel( handle, me->ch );

   if( chan == (MidiChannel *)0 )
      return;
      
   cmd[0] = 1;
   cmd[1] = 0x0D00 + chan->dspChannel;
}

static void ME_Reset_Controllers( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   (void)handle;
   cmd[0] = 1;
   cmd[1] = 0x0900;
}

static void ME_Modulation_Wheel( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   (void)handle;
   (void)me;
   (void)cmd;
}

static void ME_Tempo( MidiEvent *me, uint16 *cmd, Media_Handle *handle )
{
   uint32 ltempo;
   MIDI_Player *player = (MIDI_Player *)handle->data;

   (void)cmd;
   ltempo = ((uint32)me->ch << 16) + ((uint32)me->c1 << 8) + (uint32)me->c2;
   player->midi_qn_time = ltempo / 1000;
   player->midi_tick_time = 1024 * player->midi_qn_time / (uint32)player->division;
   
   if( player->tempo_state != 0 || player->java_tempo == 0 ) {      
      player->tempo = player->midi_qn_time;
      player->java_tempo = 60000000 / player->tempo;
      Update_Tempo( player );
      player->ticks = 0;
   }
   player->tempo_state = 1;
}

typedef void (*MidiEventHandler)(MidiEvent *note, uint16 *cmd, Media_Handle *handle);

static const MidiEventHandler midiEventHandler[] = {
   ME_None,
   ME_NoteOn,
   ME_NoteOff,
   ME_Key_Pressure,
   ME_Volume,
   ME_Pan,
   ME_Sustain,
   ME_Expression,
   ME_Pitch_Wheel,
   ME_Pitch_Sense,
   ME_Program,
   ME_Channel_Pressure,
   ME_Bank_HI,
   ME_All_Notes_Off,
   ME_All_Sounds_Off,
   ME_Reset_Controllers,
   ME_Modulation_Wheel,
   ME_Tempo,
   ME_Bank_LO,
   ME_None,
   ME_None,
   ME_None,
   ME_None,
   ME_None
};

/* ------------------------------------------------------------------------------ */
static Media_Status smfParseHeader( Media_Handle *handle )
{
   uint16      I;
   const uint8 *ptr;
   MidiTrack   *trk;
   MIDI_Player *player = (MIDI_Player *)handle->data;
   const uint8 *midifile = player->param.smffile;
   const uint8 *fileend = midifile + player->param.filesize;

   RB_INIT( player->extevent );
   EventQ_Init( player );
   player->eof = false;
   handle->current_time = 0;
   player->played_time     = 0; 

#if defined( CMIDI_SUPPORT )
   if( midifile[0] == 'M' && midifile[1] == 'T' && midifile[2] == 'K' && midifile[3] == '\x12' ) {
      player->ntrks = 0;
      player->midi.cmi.bits = 0;
      player->midi.cmi.cache = 0;
      player->midi.cmi.channel = 0;
      player->midi.cmi.octave = 0;
      player->midi.cmi.len = get32bit( midifile + 4 );
      player->midi.cmi.ptr = midifile + 8;
      cmidi_Parse( player );
      return MEDIA_SUCCESS;
   }
#endif

   if( midifile[0] == 'R' && midifile[1] == 'I' && midifile[2] == 'F' && midifile[3] == 'F' )
      midifile += 20;
   if( midifile[0] != 'M' || midifile[1] != 'T' || midifile[2] != 'h' || midifile[3] != 'd' )
      return MEDIA_BAD_FORMAT;
      
   if(get32bit(&midifile[4]) != 6) // MThk trunk size should be 6   
      return MEDIA_BAD_FORMAT;
      
   if(get16bit(&midifile[8]) > 2) // MIDI format type , should be 0, 1, 2 only    
      return MEDIA_BAD_FORMAT;    

   player->ntrks  = get16bit( &midifile[10] );
   if( player->ntrks > MAX_TRACK )
      player->ntrks = MAX_TRACK;
   player->division = get16bit( &midifile[12] );
   
   if(player->division < 0) 
      player->smpte_time =  1000 * 1024 / (((uint32)-(int8)(((uint16)player->division >> 8) & 0xFF)) * (uint32)((uint16)player->division & 0xFF));

   ptr = (const uint8 *)&midifile[8 + get32bit(&midifile[4])];
   for( I = 0 ; I < player->ntrks && ptr < fileend ; ) {
      if( ptr[0] != 'M' || ptr[1] != 'T' || ptr[2] != 'r' || ptr[3] != 'k' ) {
         // skip unsupported chunks 
         uint32 chunksize;
         chunksize = get32bit( &ptr[4] ); 
         ptr += (chunksize + 8);         
         continue;                 
      }
      trk            = &player->midi.smf.tracks[I];
      trk->toberead  = get32bit( &ptr[4] );
      trk->ptr       = &ptr[8];
      if( trk->ptr + trk->toberead > fileend )
         trk->toberead = (uint32)(fileend - trk->ptr);
      ptr            = ptr + trk->toberead + 8;
      trk->deltatime = ReadVarNum( trk );
      trk->running   = false;
      trk->status    = 0;
      I++; 
   }
   player->ntrks        = I;
   if( player->java_tempo == 0 )
      player->tempo        = 500;
   Update_Tempo( player );   
   player->tempo_state     = 0;
   player->ticks           = 0;

   player->midi_qn_time   = 500; 
   if(player->division > 0) 
      player->midi_tick_time = 1024 * 500 / (uint32)player->division;
   
   
   player->midi_event_time = 0;
   player->midi_event_time_factor = 0;
   
   midiParse( player );

   return MEDIA_SUCCESS;
}

static void FreeAllMidiChannels( MIDI_Player *player )
{
   uint32 I;
   for( I = 0; I < MAX_MIDI_CHANNEL; I++ ) {
      if( player->channel[I] != (MidiChannel*)0 ) {
         DSPSYN_FreeMidiChannel( player->channel[I] );
         player->channel[I] = (MidiChannel*)0;
      }
   }
}

static void midiDspEnd( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   if( handle->current_time >= handle->stop_time ) {
      FreeAllMidiChannels( player );
      handle->state = MIDI_STATE_READY;
      handle->stop_flag = false;
      handle->handler( handle, MEDIA_END );
   }
   else if( handle->state == MIDI_STATE_ABORT )
      handle->state = MIDI_STATE_READY;
   else {
      ASSERT( handle->state == MIDI_STATE_ENDING );
      FreeAllMidiChannels( player );
      handle->state = MIDI_STATE_READY;
      if( handle->stop_flag )
         handle->stop_flag = false;
      else
         handle->handler( handle, MEDIA_END );
   }
}

static void midiGetCmd( Media_Handle *handle, uint16 *dtime, uint16 cmd[4] )
{
   MidiEvent   *note;
   uint32 I;
   MIDI_Player *player = (MIDI_Player *)handle->data;
   MidiChannel *channel;

   cmd[0] = DSPSYN_CMD_NO_DATA;

   if( handle->state == MIDI_STATE_ENDING ) {
      if( handle->stop_flag ) {           /* STOP command is submitted */
         cmd[0] = DSPSYN_CMD_STOP;
         handle->stop_flag = false;
         handle->state = MIDI_STATE_ABORT;
      }
      return;
   }
   if( handle->state != MIDI_STATE_PLAYING && handle->state != MIDI_STATE_RTMIDI_ONLY )
      return;
   if( handle->stop_flag || handle->current_time >= handle->stop_time ) {              /* STOP command is submitted */
      for( I = 0; I < MAX_MIDI_CHANNEL; I++ ) {
         channel = player->channel[I];
         if( channel != (MidiChannel*)0 && (channel->flag&CHANNEL_FLAG_ACTIVE) ) {
            channel->flag &= ~CHANNEL_FLAG_ACTIVE;
            cmd[0] = 1;
            cmd[1] = 0x0D00 + channel->dspChannel;
            return;
         }
      }
      cmd[0] = DSPSYN_CMD_STOP;
      handle->stop_flag = false;
      handle->state = MIDI_STATE_ABORT;
      return;
   }

   while( player->rtmidi_count > 0 ) {          /* For real-time MIDI playback */
      if( player->rtmidi_count == 1 ) {
         player->rtmidi_count = 0;
         break;
      }
      else {
         MidiEvent nt;
         ReadRTMidiEvent( player, &nt );
         midiEventHandler[nt.type]( &nt, cmd, handle );
         if( cmd[0] != 0 )
            return;
      }
   }
   if( handle->state == MIDI_STATE_RTMIDI_ONLY )
      return;

   if( (player->eof && EventQ_Count(player) == 0) ) {
      if( handle->repeat_count > 0 ) {
         if( handle->repeat_count == 1 ) {
            for( I = 0; I < MAX_MIDI_CHANNEL; I++ ) {
               channel = player->channel[I];
               if( channel != (MidiChannel*)0 && (channel->flag&CHANNEL_FLAG_ACTIVE) ) {
                  channel->flag &= ~CHANNEL_FLAG_ACTIVE;
                  cmd[0] = 1;
                  cmd[1] = 0x0C00 + player->channel[I]->dspChannel;
                  return;
               }
            }
            handle->repeat_count = 0;
            cmd[0] = DSPSYN_CMD_END;
            handle->state = MIDI_STATE_ENDING;
            return;
         }
         else
            handle->repeat_count--;
      }
      FreeAllMidiChannels( player );
      player->java_tempo = 0;
      smfParseHeader( handle );
      handle->handler( handle, MEDIA_REPEATED );
      return;
   }

   while( EventQ_Count(player) > 0 && cmd[0] == DSPSYN_CMD_NO_DATA ) {
      int32 prev_time = 0;
      note = EventQ_Peek(player);
      while( note->dtime < 0 ) {
         int32 newtick = player->ticks - note->dtime;
         int32 delta_ms = Ticks2ms( player, newtick ) - Ticks2ms( player, player->ticks ) + prev_time;
         player->midi_event_time += Ticks2musicTime(player, -(note->dtime)); 
         if( delta_ms < 0 ) {  /* overflow */
            newtick = -note->dtime;
            delta_ms = Ticks2ms( player, newtick ) + prev_time;
         }
         note->dtime = delta_ms;
         player->ticks = newtick;
         if( note->type == ME_NONE ) {
            if( EventQ_Count(player) == 1 && player->eof ) {
               EventQ_Consume();
               return;
            }
            if( EventQ_Count(player) >= 2 ) {
               prev_time = note->dtime;
               EventQ_Consume();
               note = EventQ_Peek(player);
               if( note->dtime == 0 )
                  note->dtime = prev_time;
            }
         }
      }
      if( note->dtime <= *dtime ) {
         if( handle->current_time < handle->start_time ) {
            if( note->type != ME_NOTEON && note->type != ME_NOTEOFF && note->type != ME_PITCH_WHEEL 
                    && note->type != ME_KEY_PRESSURE && note->type != ME_SUSTAIN ) {
               midiEventHandler[note->type]( note, cmd, handle );
            }
         }
         else {
            midiEventHandler[note->type]( note, cmd, handle );
            *dtime -= note->dtime;
         }
         
         player->played_time += note->dtime;
      #if defined(CMIDI_SUPPORT)
         if(player->ntrks)
         {  // MIDI case            
            handle->current_time += player->midi_event_time;
            player->midi_event_time = 0;
            player->midi_event_time_factor = 0;
         }
         else // CMIDI case 
            handle->current_time += note->dtime;    
      #else 
         handle->current_time += player->midi_event_time;
         player->midi_event_time = 0;
         player->midi_event_time_factor = 0;      
      #endif    
         EventQ_Consume();
      }
      else {
         if( handle->current_time < handle->start_time ) {
            int32 skip_time;
            if(note->dtime > handle->start_time - handle->current_time) 
            { 
               uint32 elasped_time;          
               skip_time = handle->start_time - handle->current_time; 
            #if defined(CMIDI_SUPPORT) 
               if(player->ntrks)
               {
                  player->midi_event_time_factor =  player->midi_event_time * 1024 / (note->dtime);
                  elasped_time = skip_time * player->midi_event_time_factor >> 10; 
                  handle->current_time += elasped_time; 
                  player->midi_event_time -= elasped_time;   
               }
               else 
                  handle->current_time += skip_time;                 
            #else         
               player->midi_event_time_factor =  player->midi_event_time * 1024 / (note->dtime);
               elasped_time = skip_time * player->midi_event_time_factor >> 10; 
               handle->current_time += elasped_time; 
               player->midi_event_time -= elasped_time;                  
            #endif    
            }   
            else
            { 
               skip_time = note->dtime; 
            #if defined(CMIDI_SUPPORT)   
               if(player->ntrks)
               {
                  handle->current_time += player->midi_event_time;
                  player->midi_event_time = 0;
                  player->midi_event_time_factor = 0;                 
               }
               else 
                  handle->current_time += note->dtime;                    
            #else 
               handle->current_time += player->midi_event_time;
               player->midi_event_time = 0;
               player->midi_event_time_factor = 0;               
            #endif    
            }   
            
            player->played_time += skip_time;
            note->dtime -= skip_time;                        
            
         }
         else {
            if(player->midi_event_time_factor == 0)            
               player->midi_event_time_factor =  player->midi_event_time * 1024 / (note->dtime);                                 
                         
            note->dtime -= *dtime;            
            player->played_time += *dtime;
            if(*dtime > 0) 
            {
               uint32 elasped_time;  
            #if defined(CMIDI_SUPPORT)
               if(player->ntrks)
               {                   
                  elasped_time = (*dtime) * player->midi_event_time_factor >> 10; 
                  handle->current_time += elasped_time; 
                  player->midi_event_time -= elasped_time;               
               }
               else 
                  handle->current_time += *dtime; 
            #else 
               elasped_time = (*dtime) * player->midi_event_time_factor >> 10; 
               handle->current_time += elasped_time; 
               player->midi_event_time -= elasped_time;            
            #endif    
            }                                 
            *dtime = 0;
            break;
         }
      }
      if( !player->eof && EventQ_Count(player) < EVENT_Q_SIZE / 2 ) {
         if( player->ntrks )
            midiParse( player );
#if defined( CMIDI_SUPPORT )
         else
            cmidi_Parse( player );
#endif
      }
   }
}

static Media_Status smfPlay( Media_Handle *handle )
{
   Media_Status retval;

   if( (retval = smfParseHeader( handle )) != MEDIA_SUCCESS )
      return retval;
   DSPSYN_SMF_Start( handle, midiDspEnd, midiGetCmd, true );

   return MEDIA_SUCCESS;
}

static void smfWaitDsp( Media_Handle *handle, uint16 timeout )
{
   uint16 I;

   for( I = 0; ; I++ ) {
      if( handle->state == MIDI_STATE_READY )
         break;
      ASSERT_REBOOT( I < timeout );
      kal_sleep_task( 2 );
   }
}

/* -------------------------------------------------------------------------------------- */
void JSmf_Init( void )
{
}

Media_Handle *JSmf_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_SMF_Param **param )
{
   uint32 I;
   MIDI_Player *player;
   Media_Handle *handle;

   if( (handle = DSPSYN_ObtainSmfHandle()) == 0 )
      return 0;

   player = (MIDI_Player*)get_ctrl_buffer( sizeof(MIDI_Player) );

   player->pitchTranspose  = 0;
   player->nrpn            = false;
   player->tempo           = 0;
   player->java_tempo      = 0;
   player->division        = 960;
   player->playRate        = 100;
   player->tsRate          = 100;
   player->rtmidi_count    = 0;

   for( I = 0; I < MAX_MIDI_CHANNEL; I++ )
      player->channel[I] = (MidiChannel *)0;

   handle->handler         = handler;
   handle->state           = MIDI_STATE_READY;
   handle->stop_flag       = false;
   handle->volume_level    = 100;
   handle->start_time      = 0;
   handle->stop_time       = 0x7FFFFFFF;
   handle->param           = (void *)&player->param;
   handle->data            = (uint32)player;
   *param                  = &player->param;

#if defined(AUD_TIME_STRETCH)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_SMF);
   TS_Midi_Handle = handle;   // KH: Duplicate for Time Stretch
#endif

   return handle;
}

Media_Status JSmf_Close( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   ASSERT( handle->state == MIDI_STATE_READY );
#if defined(AUD_TIME_STRETCH)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_DAF);
   TS_Midi_Handle = NULL;   // KH: Release for Time Stretch
#endif
   free_ctrl_buffer( (MIDI_Player*)handle->data );
   DSPSYN_ReleaseSmfHandle( handle );
   return MEDIA_SUCCESS;
}

Media_Status JSmf_Play( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   Media_Status retval;

#if defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST)
   return MEDIA_SUCCESS;
#endif    
   
   ASSERT( handle->state == MIDI_STATE_READY );  
   handle->state = MIDI_STATE_PLAYING;
   handle->repeat_count = ((Media_SMF_Param *)handle->param)->repeats;
   memset( player->noteMgr, 0 , 256 * 2);
   *(player->noteMgr + 9) = 0xFFFE;
   player->mipMuteState = 0;      
   if( (retval = smfPlay( handle )) != MEDIA_SUCCESS )
      handle->state = MIDI_STATE_READY;
   return retval;
}

Media_Status JSmf_Stop( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   
#if defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST)
   return MEDIA_SUCCESS;
#endif       

   switch( handle->state ) {
      case MIDI_STATE_PLAYING:
         handle->stop_flag = true;
      case MIDI_STATE_ABORT:  // for Stop_Time_Up case  
         smfWaitDsp( handle, 80 );
         FreeAllMidiChannels( player );
         break;
      case MIDI_STATE_ENDING:
      #if APM_SUPPORT
         if(DSPSYN_APM_Ending())
         {
            handle->state = MIDI_STATE_ABORT;
            APM_EXECUTE_END_HANDLER();
         }   
         else 
      #endif    
         {   
            handle->stop_flag = true;
            smfWaitDsp( handle, 400 );
         }   
         FreeAllMidiChannels( player );
         break;
      case MIDI_STATE_PAUSED:
         FreeAllMidiChannels( player );
         handle->state = MIDI_STATE_READY;
      case MIDI_STATE_READY:
         break;
      default:
         ASSERT( false );
   }
   return MEDIA_SUCCESS;
}

Media_Status JSmf_Pause( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   switch( handle->state ) {
      case MIDI_STATE_PLAYING:
         handle->stop_flag = true;
      case MIDI_STATE_ABORT: // for Stop_Time_Up case    
         smfWaitDsp( handle, 40 );
         if(handle->current_time < handle->stop_time) // pause at PLAYING and not Stop_Time_Up
            handle->state = MIDI_STATE_PAUSED;
         break;
      case MIDI_STATE_ENDING:
      #if APM_SUPPORT
         if(DSPSYN_APM_Ending())
         {
            handle->state = MIDI_STATE_ABORT;
            APM_EXECUTE_END_HANDLER();
         }   
         else 
      #endif   
         {   
            handle->stop_flag = true;
            smfWaitDsp( handle, 400 );
         }
         FreeAllMidiChannels( player );
         return MEDIA_SEEK_EOF; 
      case MIDI_STATE_READY:
         return MEDIA_FAIL;
      default:
         ASSERT( false );
   }
   return MEDIA_SUCCESS;
}

Media_Status JSmf_Resume( Media_Handle *handle )
{
   ASSERT( handle->state == MIDI_STATE_PAUSED );
   handle->state = MIDI_STATE_PLAYING;
   DSPSYN_SMF_Start( handle, midiDspEnd, midiGetCmd, false );
   return MEDIA_SUCCESS;
}

Media_Status JSmf_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   handle->start_time = handle->current_time = msStartTime;
   return MEDIA_SUCCESS;
}

Media_Status JSmf_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   handle->stop_time = msStopTime;
   return MEDIA_SUCCESS;
}

kal_int32 JSmf_GetCurrentTime( Media_Handle *handle )
{
   return handle->current_time;
}

kal_int32 JSmf_GetPlayedTime( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   return player->played_time;
}

int32 JSmf_GetMidiDuration( const uint8 *mid );
int32 JSmf_GetDuration( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   const uint8 *midifile;
   int32 duration; 
   
   midifile = player->param.smffile;
   duration = JSmf_GetMidiDuration( midifile );   
   return duration;
}

Media_Event JSmf_QueryExtEvent( Media_Handle *handle, int32 *note )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   ExtCallbackEvent evt;
   
   if( RB_EMPTY( player->extevent ) )
      return MEDIA_NONE;
    RB_GET( player->extevent, evt );
   *note = evt.note;
   return evt.event;
}

/* -------------------------------------------------------------------------------------- */
kal_bool JMidi_isBankQuerySupported( void )
{
   return KAL_TRUE;
}

void JMidi_GetBankList( kal_bool custom, const kal_int16 **buf, kal_int16 *len)
{
   static const kal_int16 banklist[] = { 0 };
   *buf = banklist;
   *len = 1;
}

void JMidi_GetProgramList( kal_int16 bank, const kal_int8 **buf, kal_int16 *len)
{
   *buf = programList;
   if( bank == 0 )
      *len = sizeof(programList) / sizeof(int8);
   else
      *len = 0;
}

const kal_uint8 *JMidi_GetProgramName( kal_int16 bank, kal_int8 prog )
{
   static const uint8 empty_name[] = "";
   if( bank == 0 && prog >= 0 )
      return instrumentName[prog];
   else
      return empty_name;
}

const kal_uint8 *JMidi_GetKeyName( kal_int16 bank, kal_int8 prog, kal_int8 key )
{
   static const uint8 empty_name[] = "";
   if( bank == 0 && prog >= 0 && key >= 0 ) {
      if( key < 34 )
         key = 34;
      if( key > 85 )
         key = 85;
      return percussionName[key-34];
   }
   else
      return empty_name;
}

Media_Handle *JMidi_OpenDevice( void )
{
   uint32 I;
   Media_Handle *handle;
   MIDI_Player *player;

   if( (handle = DSPSYN_ObtainSmfHandle()) == 0 )
      return 0;

   player = (MIDI_Player*)get_ctrl_buffer( sizeof(MIDI_Player) );

   player->pitchTranspose  = 0;      
   memset( player->noteMgr, 0 , 256 * 2);
   *(player->noteMgr + 9) = 0xFFFE;        
   player->nrpn            = false;
   player->rtmidi_count    = 0;
   player->division        = 960;
   player->mipMuteState    = 0;
   for( I = 0; I < MAX_MIDI_CHANNEL; I++ )
      player->channel[I] = (MidiChannel *)0;

   EventQ_Init( player );

   handle->state           = MIDI_STATE_RTMIDI_ONLY;
   handle->stop_flag       = false;
   handle->volume_level    = 100;
   handle->start_time      = 0;
   handle->stop_time       = 0x7FFFFFFF;
   handle->param           = (void *)&player->param;
   handle->data            = (uint32)player;

   DSPSYN_SMF_Start( handle, midiDspEnd, midiGetCmd, true );
   return handle;
}

Media_Status JMidi_CloseDevice( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   ASSERT( handle != 0 && handle->state == MIDI_STATE_RTMIDI_ONLY );

   handle->stop_flag = true;
   smfWaitDsp( handle, 80 );
   FreeAllMidiChannels( player );
   handle->state = MIDI_STATE_READY;
   free_ctrl_buffer( (MIDI_Player*)handle->data );
   DSPSYN_ReleaseSmfHandle( handle );
   return MEDIA_SUCCESS;
}

Media_Status JMidi_SendLongMsg( Media_Handle *handle, const uint8 *buf, uint16 len )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   uint16 I;

   player->rtmidi_running = false;
   player->rtmidi_status = 0;
   player->rtmidi_ptr = buf;
   player->rtmidi_count = len;
   for( I = 0; ; I++ ) {
      if( player->rtmidi_count == 0 )
         break;
      ASSERT_REBOOT( I < 80 );
      kal_sleep_task( 1 );
   }
   return MEDIA_SUCCESS;
}

Media_Status JMidi_SendShortMsg( Media_Handle *handle, uint8 type, uint8 data1, uint8 data2 )
{
   uint8 buf[3];

   buf[0] = type;
   buf[1] = data1;
   buf[2] = data2;
   return JMidi_SendLongMsg( handle, buf, 3 );
}

Media_Status JMidi_SetLevel( Media_Handle *handle, kal_uint8 level )
{
   handle->volume_level = level;
   return MEDIA_SUCCESS;
}

uint8 JMidi_GetLevel( Media_Handle *handle )
{
   return handle->volume_level;
}

Media_Status JMidi_SetTempo( Media_Handle *handle, kal_int32 milliTempo )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   player->java_tempo = milliTempo;
   player->tempo = 60000000 / milliTempo;
   Update_Tempo( player );
   player->ticks = 0;
   return MEDIA_SUCCESS;
}

kal_int32 JMidi_GetTempo( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   return player->java_tempo;
}

Media_Status JMidi_SetTSRate( Media_Handle *handle, kal_int32 Rate )
{
   if (handle == NULL) {
      return MEDIA_FAIL;
   } else {
      MIDI_Player *player = (MIDI_Player *)handle->data;

      player->tsRate = Rate;
      Update_Tempo( player );
   }
   return MEDIA_SUCCESS;
}

Media_Status JMidi_SetRate( Media_Handle *handle, kal_int32 milliRate )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   player->playRate = milliRate / 1000;
   Update_Tempo( player );
   return MEDIA_SUCCESS;
}

kal_int32 JMidi_GetRate( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   return (kal_int32)(player->playRate * 1000);
}

Media_Status JMidi_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   milliSt /= 1000;
   if( milliSt > 64 || milliSt < -64 )
      return MEDIA_FAIL;
   player->pitchTranspose = milliSt;
   return MEDIA_SUCCESS;
}

kal_int32 JMidi_GetPitchTranspose( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;

   return (kal_int32)player->pitchTranspose*1000;
}

Media_Status JMidi_SetChannelVolume( Media_Handle *handle, kal_int8 channel, kal_uint8 level )
{
   (void)handle;
   ASSERT( channel >= 0 && channel <= 15 );
   JMidi_SendShortMsg( handle, 0xB0 + channel, 0x07, level );
   return MEDIA_SUCCESS;
}

kal_int8 JMidi_GetChannelVolume( Media_Handle *handle, kal_int8 channel )
{
   MidiChannel *chan = VerifyMidiChannel( handle, channel );

   if( chan == (MidiChannel *)0 )
      return 90;
      
   return chan->volume;
}

Media_Status JMidi_SetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 bank, kal_int8 program )
{
   (void)handle;
   ASSERT( channel >= 0 && channel <= 15 );
   JMidi_SendShortMsg( handle, 0xC0 + channel, program, 0 );
   return MEDIA_SUCCESS;
}

void JMidi_GetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 *bank, kal_int8 *program )
{
   MidiChannel *chan = VerifyMidiChannel( handle, channel );

   if( chan == (MidiChannel *)0 )
      return;
      
   *bank = 0;
   *program = chan->program ;
}

/* ------------------------------------------------------------------------------ */
typedef struct {
   int32       ticks;
   int32       toberead;
   const uint8 *ptr;
   uint32      status;
} TrkParam;

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

int32 JSmf_GetMidiDuration( const uint8 *mid )
{
   uint32      I;
   uint32      ntrks;
   int32       duration;
   int32       active_tempo;   
   int16       ch;
   int16       division;
   TrkParam    *trk;
   int16       next_trk;
   int32       delta;
   TrkParam    *tracks;
   bool        fail = false;

#if defined( CMIDI_SUPPORT )
   if( mid[0] == 'M' && mid[1] == 'T' && mid[2] == 'K' && mid[3] == '\x12' ) {
      return cmidi_GetDuration( mid+4 );
   }
#endif

   if( mid[0] == 'R' && mid[1] == 'I' && mid[2] == 'F' && mid[3] == 'F' )
      mid += 20;
   if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'h' || mid[3] != 'd' )
      return -1;

   if( get16bit( &mid[8] ) > 2 )
      return -1;
   if( (ntrks  = (uint32)get16bit( &mid[10] )) > MAX_TRACK )
      return -1;
   division = get16bit( &mid[12] );

   mid = (const uint8 *)&mid[8 + get32bit(&mid[4])];

   ASSERT( (sizeof(TrkParam) & 3) == 0 );
   tracks = (TrkParam*)get_ctrl_buffer( MAX_TRACK * sizeof(TrkParam) );
   ASSERT( tracks != (TrkParam*)0 );

   for( I = 0 ; I < ntrks; I++ ) {
      if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'r' || mid[3] != 'k' )
         break;
      trk            = &tracks[I];
      trk->toberead  = get32bit( &mid[4] );
      trk->ptr       = &mid[8];
      mid            = mid + 8 + trk->toberead;
      trk->ticks     = getVarNum( trk );
      trk->status    = 0;
   }
   ntrks = I;

   duration = 0;  
   if(division > 0) 
      active_tempo = 1024 * 500 / (uint32)division;
   else 
      active_tempo =  1000 * 1024 / (((uint32)-(int8)(((uint16)division >> 8) & 0xFF)) * (uint32)((uint16)division & 0xFF));  

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
      }
      delta = delta * active_tempo >> 10;  
         
      duration += delta;
      trk = &tracks[next_trk];

      ch = *trk->ptr++;   trk->toberead--;
      if( ch == 0xFF ) {
         ch = *trk->ptr++;   trk->toberead--;                  /* read type */
         if( (delta = getVarNum( trk )) < 0 ) {                /* get meta event length */
            fail = true;
            break;
         }
         if( ch == 0x51 ) {                                    /* Set tempo */
            active_tempo = (((uint32)trk->ptr[0] << 16) + ((uint32)trk->ptr[1] << 8) + (uint32)trk->ptr[2]) / 1000;
            active_tempo = 1024 * active_tempo / (uint32)division;
         }
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 ) {
            fail = true;
            break;
         }
      }
      else if( ch == 0xF0 || ch == 0xF7 ) {
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
         if( (ch & 0x80) == 0 ) {       /* running status? */
            if( trk->status == 0 ) {
               fail = true;
               break;
            }
            if( chantype[ (trk->status>>4) & 0xf ] > 1 ) {
               trk->ptr++;
               trk->toberead--;
            }
         }
         else {
            trk->status = (uint8)ch;
            delta = chantype[ (trk->status>>4) & 0xf ];
            trk->ptr += delta;
            trk->toberead -= delta;
         }
      }
      if( (trk->ticks = getVarNum( trk )) < 0 ) {
         fail = true;
         break;
      }
   }
   free_ctrl_buffer( tracks );
   if( fail )
      return -1;
   return duration;
}

Media_Status JSmf_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize,
                  audInfoStruct *contentInfo, void *param )
{
#ifndef __L1_STANDALONE__

   uint32      I;
   uint32      ntrks;
   int32       duration, temp_dura;
   int32       active_tempo;
   int16       ch;
   int16       division;
   TrkParam    *trk;
   int16       next_trk;
   int32       delta;
   TrkParam    *tracks;
   bool        fail = false;

   STFSAL *pstFSAL = 0;
   kal_uint8 *pbPtr = pbBuf;
   const kal_uint8 *mid;

   if(NULL != filename){
      pstFSAL = NULL;
      pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
      if(pstFSAL == NULL)
         return MEDIA_FAIL;
      memset(pstFSAL, 0, sizeof(STFSAL));
      {
         FSAL_Status eFSALStatus;
         eFSALStatus = FSAL_Open(pstFSAL, (void*)filename, FSAL_READ);
         if(eFSALStatus != FSAL_OK){
            free_ctrl_buffer(pstFSAL);
            return MEDIA_FAIL;
         }
      }
      pbPtr = NULL;
      pbPtr = (kal_uint8 *)get_ctrl_buffer( sizeof(kal_uint8)* 2048 );
      if(pbPtr == NULL){
         FSAL_Close(pstFSAL);
         free_ctrl_buffer(pstFSAL);
         return MEDIA_FAIL;
      }
      memset(pbPtr, 0, sizeof(kal_uint8)* 2048);
      FSAL_GetFileSize(pstFSAL, &uSize);
      if(uSize > 2046)
         uSize = 2046;
      if(FSAL_Read_Bytes( pstFSAL, pbPtr, uSize) != FSAL_OK){
         FSAL_Close(pstFSAL);
         free_ctrl_buffer(pstFSAL);
         free_ctrl_buffer(pbPtr);
         return MEDIA_FAIL;
      }
      FSAL_Close(pstFSAL);
      free_ctrl_buffer(pstFSAL);
   }

   ASSERT(0 != pbPtr);
   mid = (const kal_uint8 *)pbPtr;
   
#if defined( CMIDI_SUPPORT )
   if( mid[0] == 'M' && mid[1] == 'T' && mid[2] == 'K' && mid[3] == '\x12' ) {
      if(NULL != filename)
         free_ctrl_buffer(pbPtr);
      return MEDIA_SUCCESS;
   }
#endif

   if( mid[0] == 'R' && mid[1] == 'I' && mid[2] == 'F' && mid[3] == 'F' )
      mid += 20;
   if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'h' || mid[3] != 'd' ){
      if(NULL != filename)
         free_ctrl_buffer(pbPtr);
      return MEDIA_FAIL;
   }

   if( get16bit( &mid[8] ) > 2 ){
      if(NULL != filename)
         free_ctrl_buffer(pbPtr);
      return MEDIA_FAIL;
   }
   if( (ntrks  = (uint32)get16bit( &mid[10] )) > MAX_TRACK ){
      if(NULL != filename)
         free_ctrl_buffer(pbPtr);
      return MEDIA_FAIL;
   }
   division = get16bit( &mid[12] );

   mid = (uint8 *)&mid[8 + get32bit(&mid[4])];

   ASSERT( (sizeof(TrkParam) & 3) == 0 );
   tracks = (TrkParam*)get_ctrl_buffer( MAX_TRACK * sizeof(TrkParam) );
   ASSERT( tracks != (TrkParam*)0 );

   for( I = 0 ; I < ntrks; I++ ) {
      if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'r' || mid[3] != 'k' )
         break;
      trk            = &tracks[I];
      trk->toberead  = get32bit( &mid[4] );
      trk->ptr       = &mid[8];
      mid            = mid + 8 + trk->toberead;
      trk->ticks     = getVarNum( trk );
      trk->status    = 0;
   }
   ntrks = I;

   duration = 0;
   temp_dura = 0;
   if(division > 0) 
      active_tempo = 1024 * 500 / (uint32)division;
   else 
      active_tempo =  1000 * 1024 / (((uint32)-(int8)(((uint16)division >> 8) & 0xFF)) * (uint32)((uint16)division & 0xFF));  

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
      }
      delta = delta * active_tempo >> 10;  

      temp_dura += delta;
      trk = &tracks[next_trk];

      ch = *trk->ptr++;   trk->toberead--;
      if( ch == 0xFF ) {
         ch = *trk->ptr++;   trk->toberead--;                  /* read type */
         if( (delta = getVarNum( trk )) < 0 ) {                /* get meta event length */
            fail = true;
            break;
         }
         if( ch == 0x02 ) {
            kal_uint32 uCnt;
            const kal_uint8 *ptr = trk->ptr;
            kal_wchar *pbTmp = contentInfo->copyright;
            for( uCnt = 0; uCnt < delta; uCnt++ ) {
               *pbTmp++ = (kal_wchar)*ptr++;
            }
            break;
         }
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 ) {
            fail = true;
            break;
         }
      }
      else if( ch == 0xF0 || ch == 0xF7 ) {
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
         duration += temp_dura;
         temp_dura = 0;
         if( (ch & 0x80) == 0 ) {       /* running status? */
            if( trk->status == 0 ) {
               fail = true;
               break;
            }
            if( chantype[ (trk->status>>4) & 0xf ] > 1 ) {
               trk->ptr++;
               trk->toberead--;
            }
         }
         else {
            trk->status = (uint8)ch;
            delta = chantype[ (trk->status>>4) & 0xf ];
            trk->ptr += delta;
            trk->toberead -= delta;
         }
      }
      if( (trk->ticks = getVarNum( trk )) < 0 ) {
         fail = true;
         break;
      }
   }

   contentInfo->time = JSmf_GetMidiDuration( (const uint8 *)pbPtr );

   free_ctrl_buffer( tracks );
   if(NULL != filename)
      free_ctrl_buffer(pbPtr);
   if( fail )
      return MEDIA_FAIL;

#endif // #ifndef __L1_STANDALONE__

   return MEDIA_SUCCESS;
}

kal_bool JSmf_isSpMidi( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   const uint8 *mid = player->param.smffile;  
   const uint8 *fileend = mid + player->param.filesize;
   uint32      I;
   uint32      ntrks;     
   int16       ch;   
   TrkParam    *trk;
   int16       next_trk;
   int32       delta;
   TrkParam    *tracks;         
      
   if( mid[0] == 'R' && mid[1] == 'I' && mid[2] == 'F' && mid[3] == 'F' )
      mid += 20;
   if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'h' || mid[3] != 'd' )
      return KAL_FALSE;

   if( get16bit( &mid[8] ) > 2 )
      return KAL_FALSE;
   if( (ntrks  = (uint32)get16bit( &mid[10] )) > MAX_TRACK )
      return KAL_FALSE;   

   mid = (const uint8 *)&mid[8 + get32bit(&mid[4])];

   ASSERT( (sizeof(TrkParam) & 3) == 0 );
   tracks = (TrkParam*)get_ctrl_buffer( MAX_TRACK * sizeof(TrkParam) );
   ASSERT( tracks != (TrkParam*)0 );

   for( I = 0 ; I < ntrks && mid < fileend ; ) {
      if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'r' || mid[3] != 'k' ){
      // skip unsupported chunks 
         uint32 chunksize;
         chunksize = get32bit( &mid[4] ); 
         mid += (chunksize + 8);         
         continue;         
      }        
      trk            = &tracks[I];
      trk->toberead  = get32bit( &mid[4] );
      trk->ptr       = &mid[8];
      mid            = mid + 8 + trk->toberead;
      trk->ticks     = getVarNum( trk );
      trk->status    = 0;
      I++; 
   }
   ntrks = I;  
   
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
      }      
         
      trk = &tracks[next_trk];

      ch = *trk->ptr++;   trk->toberead--;
      if( ch == 0xFF ) {
         ch = *trk->ptr++;   trk->toberead--;                  /* read type */
         if( (delta = getVarNum( trk )) < 0 )
            break;                           
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 )            
            break;                  
      }
      else if( ch == 0xF0 || ch == 0xF7 ) {
         if( (delta = getVarNum( trk )) < 0 )           
            break;        
         
         if( ch == 0xF0 )
         {
            const uint8 *msg;   
            msg = trk->ptr;
            if(msg[0] == 0x7F &&  msg[2] == 0x0B && msg[3] == 0x01)
            {
               free_ctrl_buffer( tracks );     
               return KAL_TRUE;
            }   
         } 
                        
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 )
            break;         
      }
      else {         
         if( (ch & 0x80) == 0 ) {       /* running status? */
            if( trk->status == 0 )
               break;
            
            if( chantype[ (trk->status>>4) & 0xf ] > 1 ) {
               trk->ptr++;
               trk->toberead--;
            }
         }
         else {
            trk->status = (uint8)ch;
            delta = chantype[ (trk->status>>4) & 0xf ];
            trk->ptr += delta;
            trk->toberead -= delta;
         }
      }
      if( (trk->ticks = getVarNum( trk )) < 0 )          
         break;      
   }
   free_ctrl_buffer( tracks );   
   return KAL_FALSE;   
   
}

/* ------------------------------------------------------------------------------ */
#endif /* DSP_WT_SYN */


