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
 * midisyn.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Midi Synthesizer
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MIDISYN_H
#define MIDISYN_H

#include "media.h"

#if defined( SW_SYN_16K )
   #define  MAX_POLYPHONY        16
   #define  MAX_POLYPHONY_BUSY   12
   #define  PLAY_RATE            16000          /* 16K samples per second */
#else
   #define  MAX_POLYPHONY        20
   #define  MAX_POLYPHONY_BUSY   16
   #define  PLAY_RATE            8000           /* 8K samples per second */
#endif

#define  ENABLE_AGC
#define  AGC_GAIN_FACTOR         12             /* Maximum gain = 2^(16-AGC_GAIN_FACTOR) */

#define  SAMPLES_PER_MS          (PLAY_RATE/1000)
#define  BLOCK_PERIOD            16                /* ms */
#define  FREQ_FACTOR             4
#define  INS_TABLE_SIZE          22
#define  MAX_ENVELOPE            (127<<16)
#define  MIN_ENVELOPE            (50<<16)
#define  MAX_CHANNEL             16
#define  BLOCK_SAMPLE_NO         (BLOCK_PERIOD * SAMPLES_PER_MS)

#define CONFIRM_WRITE_SPACE()    if( mediaGetFreeSpace() < BLOCK_SAMPLE_NO ) \
                                    return false;

#define  AGC_INIT_STATE          0
#define  AGC_STEADY_STATE        1

/* --------------------------------------------- */
/*  Declarations of Data Types                   */
/* --------------------------------------------- */
#define  EG_FREE        0x00
#define  EG_ATTACK      0x01
#define  EG_HOLD        0x02
#define  EG_DECAY       0x04
#define  EG_SUSTAIN     0x08
#define  EG_RELEASE     0x10
#define  EG_DIE         0x20

#define  CHANNEL_FLAG_MUTE    0x01
#define  CHANNEL_FLAG_MONO    0x02
#define  CHANNEL_FLAG_VIBE    0x04

typedef struct {
   int32    pitchbend;
   int16    bank;
   int16    pitchsens;
   int8     program;
   int8     volume;
   int8     sustain;
   int8     expression;
   uint8    flag;
} MidiChannel;

typedef const struct {
   int32       loopEnd;
   int32       loopLength;
   int32       freqRate;
   int32       attack;
   int16       hold;
   int16       reverbDelay;
   int32       decay;
   int32       sustain;
   int32       release;
   uint16      tremolo_increment;
   uint16      tremolo_depth;
   int32       tab_off;
} WT_Param;

typedef struct {
   uint8       state;
   int8        channel;
   int8        pitch;
   int8        velocity;
	int32       sample_offset;
   int32       sample_increment;
   int32       orig_freq;
	int32       envelope_volume;
   int32       envelope_increment;
   uint16      tremolo_offset;
   uint16      vibrato_offset;
   int16       holdTime;
   int16       wt_volume;
   bool        compressed;
   WT_Param    *wt;
   const int16 *wt_table;
   int32       left_amp;
   int32       left_mix;
} ToneGenerator;

/* --------------------------------------------- */
/*  Declarations of Global Variables             */
/* --------------------------------------------- */
extern int16         audio_buffer[256*2];
extern int16         polyphony_limit;
extern int16         current_polyphony;
extern const uint16  *freqTable;
extern const uint32  *bendTable;
extern const int16   *sineTable;
extern const uint16  *attVolTab;
extern const uint16  *expVolTab;
extern const int16   *wavTable;
extern const int16   **melodicInst;
extern const int16   **percussiveInst;
extern ToneGenerator *toneGen;
extern MidiChannel   *midiChannel;

extern int32         agc_gain;
extern int16         agc_init_speed;
extern int16         agc_steady_speed;
extern int8          agc_state;

/* --------------------------------------------- */
/*  Declarations of Function Calls               */
/* --------------------------------------------- */
void  SWSYN_LoadWavetable( const void *wavtab );
void  SWSYN_UnloadWavetable( void );
void  SWSYN_PcmPlaybackHisr( mediaControl *ctrl );
void  SWSYN_PcmStart( mediaControl *ctrl );
void  SWSYN_PcmStop( mediaControl *ctrl );
void  SWSYN_ResetControllers( int ch );
void  SWSYN_ResetMIDI(void);
void  SWSYN_ResampleVoice( ToneGenerator *tg, int32 *sample );
void  SWSYN_ResetAgc( int32 init_gain, int16 init_speed, int16 steady_speed );
void  SWSYN_Agc( int32 master_volume );
void  SWSYN_RecomputeAmplitude( ToneGenerator *tg );
void  SWSYN_AdjustVolume( int8 ch );
void  SWSYN_RecomputeFrequency( ToneGenerator *tg );
void  SWSYN_StartNote( ToneGenerator *tg );
void  SWSYN_CloseNote( ToneGenerator *tg );
void  SWSYN_KillNote( ToneGenerator *tg );
void  SWSYN_Synthesize( bool end_flag );
bool  SWSYN_ToneGenIdle( void );
int16 SWSYN_FindWeakestNote( void );

#endif


