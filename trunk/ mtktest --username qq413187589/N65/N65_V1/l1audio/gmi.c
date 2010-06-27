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
 * gmi2.c
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   New Generic Melody Interface (GMI)
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( SIN_WAV_SYN )
#include "media.h"
#include "gpt_sw.h"
#include "am.h"
#include "afe.h"
#include "gmi.h"

/*****************************************************************************
* Hardware Registers Definition
*****************************************************************************/
/* defines the maximum duration of a note */
#define  GMI_RB_SIZE          128      /* should be power of 2 */

/* defines control registers of DSP melody generator */
#define QTMF_CONTROL          (*(volatile uint16*)(DPRAM_CPU_base+0x010*2))
#define QTMF_COUNTER          (*(volatile uint16*)(DPRAM_CPU_base+0x011*2))
#define QTMF_FREQ(n)          (*(volatile uint16*)(DPRAM_CPU_base+(0x012+3*(n))*2))
#define QTMF_AMP(n)           (*(volatile uint16*)(DPRAM_CPU_base+(0x013+3*(n))*2))
#define QTMF_DURA(n)          (*(volatile uint16*)(DPRAM_CPU_base+(0x014+3*(n))*2))
#define QTMF_TIME(n)          (*(volatile uint16*)(DPRAM_CPU_base+(0x11D+1+(n))*2))

typedef enum {
   GMI_STATE_IDLE,
   GMI_STATE_INIT,
   GMI_STATE_PLAY,
   GMI_STATE_DATA_COMPLETE
} GMI_State;

/* Pitch to frequency conversion table */
static const uint16 Pitch2Frequency[] = {
/*  0     1     2     3     4     5     6     7     8     9    10    11 */
/* C0   C0#    D0   D0#    E0    F0   F0#    G0   G0#    A0   A0#    B0 */
//    8,    9,    9,   10,   10,   11,   12,   12,   13,   14,   15,   15,
/* 12    13    14    15    16    17    18    19    20    21    22    23 */
/* C1   C1#    D1   D1#    E1    F1   F1#    G1   G1#    A1   A1#    B1 */
   16,   17,   18,   19,   20,   21,   23,   24,   25,   27,   29,   30,
/* 24    25    26    27    28    29    30    31    32    33    34    35 */
/* C2   C2#    D2   D2#    E2    F2   F2#    G2   G2#    A2   A2#    B2 */
   32,   34,   36,   38,   41,   43,   46,   49,   51,   55,   58,   61,
/* 36    37    38    39    40    41    42    43    44    45    46    47 */
/* C3   C3#    D3   D3#    E3    F3   F3#    G3   G3#    A3   A3#    B3 */
   65,   69,   73,   77,   82,   87,   92,   98,  103,  110,  116,  123,
/* 48    49    50    51    52    53    54    55    56    57    58    59 */
/* C4   C4#    D4   D4#    E4    F4   F4#    G4   G4#    A4   A4#    B4 */
  130,  138,  146,  155,  164,  174,  185,  196,  207,  220,  233,  246,
/* 60    61    62    63    64    65    66    67    68    69    70    71 */
/* C5   C5#    D5   D5#    E5    F5   F5#    G5   G5#    A5   A5#    B5 */
  261,  277,  293,  311,  329,  349,  370,  392,  415,  440,  466,  493,
/* 72    73    74    75    76    77    78    79    80    81    82    83 */
/* C6   C6#    D6   D6#    E6    F6   F6#    G6   G6#    A6   A6#    B6 */
  523,  554,  587,  622,  659,  698,  740,  784,  830,  880,  932,  987,
/* 84    85    86    87    88    89    90    91    92    93    94    95 */
/* C7   C7#    D7   D7#    E7    F7   F7#    G7   G7#    A7   A7#    B7 */
 1046, 1108, 1174, 1244, 1318, 1397, 1480, 1568, 1661, 1760, 1864, 1975,
/* 96    97    98    99   100   101   102   103   104   105   106   107 */
/* C8   C8#    D8   D8#    E8    F8   F8#    G8   G8#    A8   A8#    B8 */
 2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951,
/*108   109   110   111   112   113   114   115   116   117   118   119 */
/* C9   C9#    D9   D9#    E9    F9   F9#    G9   G9#    A9   A9#    B9 */
 4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902,
/*120   121   122   123   124   125   126   127 */
/*C10  C10#   D10  D10#   E10   F10  F10#   G10 */
 8372, 8870, 9397, 9956,10548,11175,11840,12544 
};

typedef struct {
   uint16   delta_time;
   uint16   duration;
   int16    amplitude;
   int8     pitch;
   int8     timbre;
} GMI_Note;

static struct
{
   GMI_State   state;                              /* GMI State                                 */
   uint8       gpt;                                
   GMI_Note    rb[GMI_RB_SIZE];                    /* Ring buffer to keep notes                 */
   uint16      rb_head;                            /* head pointer of the ring buffer           */
   uint16      rb_tail;                            /* tail pointer of the ring buffer           */
   void        (*gmi_handler)(GMI_Event event);    /* End of melody handler                     */
   uint16      start_time;                         /* Start time                                */
   uint32      end_time;                           /* End time                                  */
   uint32      note_time;                          /* keep the time of the last note in DSP     */
   uint32      mmi_time;                           /* Variable for keeping track of MMI time    */
   uint32      dsp_time[MAX_DPRAM_BUFFER];         /* Variables for keeping track of DSP time   */
   bool        eof_flag;
   uint16      aud_id;
} gmi;

#define RB_Empty()         (gmi.rb_head==gmi.rb_tail)
#define RB_Peek()          (&gmi.rb[gmi.rb_tail&(GMI_RB_SIZE-1)])
#define RB_GetNextFree()   (&gmi.rb[gmi.rb_head&(GMI_RB_SIZE-1)])
#define RB_Consume()       (gmi.rb_tail++)
#define RB_Count()         (gmi.rb_head-gmi.rb_tail)

/*****************************************************************************
* FUNCTION
*  gmiTerminate
* DESCRIPTION
*   This function is to handle the terminating state of GMI.
*****************************************************************************/
static void gmiTerminate( void *data )
{
   QTMF_CONTROL = 0;
   AM_MelodyOff();
   gmi.state = GMI_STATE_IDLE;
   L1Audio_SetEvent( gmi.aud_id, (void*)GMI_END );
}

/*****************************************************************************
* FUNCTION
*  gmiWriteToDSP
* DESCRIPTION
*   This function is the call-back function of GPT for playing notes.
*****************************************************************************/
static void gmiWriteToDSP( void *data )
{
   GMI_Note *note;
   uint16   I;
   uint32   curtime;
   uint32   note_time;
   uint32   next_time;
   uint16   rb_count_org;

   rb_count_org = RB_Count();
   curtime = (uint32)(QTMF_COUNTER - gmi.start_time);
   next_time = curtime;

   while( !RB_Empty() ) {
      note = RB_Peek();

      note_time = gmi.note_time + note->delta_time;

      if( note_time > next_time ) {
         next_time = note_time;
      }
      else if( note_time < curtime ) {
         RB_Consume();
         gmi.note_time = note_time;
         continue;
      }

      /* search for the first available DSP tone */
      for( I = 0; I < MAX_DPRAM_BUFFER; I++ ) {
#if defined(MT6205)
         if( QTMF_DURA(I) == 0 && gmi.dsp_time[I] <= note_time ) {
#else
         if( QTMF_DURA(I) == 0 ) {
#endif
            QTMF_FREQ(I) = Pitch2Frequency[ note->pitch ];
            QTMF_AMP(I) = (uint16)note->amplitude;
            QTMF_DURA(I) = note->duration << 4;
/*          QTMF_DURA(I) = (note->duration << 4) + ((note->timbre >> 3) & 0x0F );
*/
            QTMF_TIME(I) = (uint16)note_time + gmi.start_time;
            gmi.dsp_time[I] = note_time + note->duration;
            if( gmi.end_time < gmi.dsp_time[I] )
               gmi.end_time = gmi.dsp_time[I];
            RB_Consume();
            gmi.note_time = note_time;
            break;
         }
      }

      if( I == MAX_DPRAM_BUFFER )
         break;
   }

   switch( gmi.state ) {
   case GMI_STATE_INIT:
      QTMF_CONTROL = 3;
      gmi.state = GMI_STATE_PLAY;
      break;
   case GMI_STATE_PLAY:
      if( rb_count_org >= GMI_RB_SIZE/2 && RB_Count() < GMI_RB_SIZE/2 ) 
         L1Audio_SetEvent( gmi.aud_id, (void*)GMI_NOTE_REQUEST );
      if( gmi.eof_flag )
         gmi.state = GMI_STATE_DATA_COMPLETE;
      break;
   case GMI_STATE_DATA_COMPLETE:
      if( RB_Empty() ) {
         GPTI_StartItem( gmi.gpt, (gmi.end_time - curtime + 5) * 2, gmiTerminate, 0 );
         return;
      }
      break;
   }

   if( next_time > curtime )
      next_time = next_time - curtime;
   else
      next_time = 1;

   GPTI_StartItem( gmi.gpt, next_time, gmiWriteToDSP, 0 );
}

/*****************************************************************************
* FUNCTION
*  GMI_Play
* DESCRIPTION
*   This function is used to start melody playing.
*
* PARAMETERS
*   gmi_handler - a call back function used to be notified an event that
*                 the end of a song is reached.
*****************************************************************************/
void GMI_Play( void (*gmi_handler)( GMI_Event event ) )
{
   int16 I;
   if( L1Audio_CheckFlag( gmi.aud_id ) )
      return;
   if( gmi_handler == 0 )
      return;
   if( gmi.state != GMI_STATE_IDLE )
      return;

   L1Audio_SetFlag( gmi.aud_id );

   GPTI_StopItem( gmi.gpt );

   for( I = 0; I < MAX_DPRAM_BUFFER; I++ ) {
      gmi.dsp_time[I] = 0;
      QTMF_DURA(I) = 0;
   }

   gmi.rb_head = 0;
   gmi.rb_tail = 0;
   gmi.mmi_time = 0;
   gmi.start_time = QTMF_COUNTER;
   gmi.end_time = 0;

   gmi.state = GMI_STATE_INIT;
   gmi.note_time = 0;
   gmi.eof_flag = false;
   gmi.gmi_handler = gmi_handler;
   
   gmi.gmi_handler( GMI_NOTE_REQUEST );   
   
   AM_MelodyOn();

   gmiWriteToDSP( 0 );
} /* end of gmiPlay */

/*****************************************************************************
* FUNCTION
*  GMI_Stop
* DESCRIPTION
*   This function is used to stop melody playing.
*****************************************************************************/
void GMI_Stop( void )
{
   int16 I;
   if( !L1Audio_CheckFlag( gmi.aud_id ) )
      return;

   if( gmi.state == GMI_STATE_IDLE )
      return;

   GPTI_StopItem( gmi.gpt );

   QTMF_CONTROL = 0;
   for( I = 0; I < MAX_DPRAM_BUFFER; I++ )
      QTMF_DURA(I) = 0;
   AM_MelodyOff();
   gmi.state = GMI_STATE_IDLE;

   L1Audio_ClearFlag( gmi.aud_id );
}

/*****************************************************************************
* FUNCTION
*  GMI_GetFreeSpace
* DESCRIPTION
*   This function is used to get the count of free entries in the ring buffer.
* RETURNS
*   Free entry count.
*****************************************************************************/
uint16 GMI_GetFreeSpace( void )
{
   return( GMI_RB_SIZE - RB_Count() );
}

/*****************************************************************************
* FUNCTION
*  GMI_PutNote
* DESCRIPTION
*   This function is used to put a note to the ring buffer.
*
* PARAMETERS
*   time       - Starting time of a note (in ms unit).
*   duration   - Duration of a note (in ms unit)
*   pitch      - Pitch of a note
*   amplitude  - Volume of a note (0-0x7FFF)
*   timbre     - Instrument used to play a note (0-15)
* RETURNS
*   None.
*****************************************************************************/
void GMI_PutNote( uint32 time, uint32 duration, int8 pitch, int16 amplitude, int8 timbre )
{
   GMI_Note *note = RB_GetNextFree();

   duration          = (time + duration + 10) / 5 >> 2;
   time              = ( time + 10 ) / 5 >> 2;
   duration          -= time;
   if( duration == 0 )
      return;         
      
   note->delta_time  = (uint16)(time - gmi.mmi_time);
   note->duration    = (uint16)duration;
   note->pitch       = pitch;
   note->amplitude   = amplitude;
   note->timbre      = timbre;
   gmi.rb_head++;
   gmi.mmi_time      = time;
}

/*****************************************************************************
* FUNCTION
*  GMI_DataFinished
* DESCRIPTION
*   This function is used to set END-OF-FILE flag
*****************************************************************************/
void GMI_DataFinished( void )
{
   gmi.eof_flag = true;
}

static void gmiHandler( void *data )     /* This function works in L1Audio Task */
{
   GMI_Event event = (GMI_Event)(int32)data;
   
   if( event == GMI_END ) {
      L1Audio_ClearFlag( gmi.aud_id );   
      gmi.gmi_handler( GMI_END );
   }
   else if( event == GMI_NOTE_REQUEST ) {
      gmi.gmi_handler( GMI_NOTE_REQUEST );            
   }
}

/*****************************************************************************
* FUNCTION
*  gmiInit
* DESCRIPTION
*   This function is used to initialize GMI Driver
*****************************************************************************/
void gmiInit( uint16 aud_id )
{
   gmi.aud_id = aud_id;
   L1Audio_SetEventHandler( gmi.aud_id, gmiHandler );

   GPTI_GetHandle( &gmi.gpt );
   gmi.state      = GMI_STATE_IDLE;
}
#else
char dummy_gmi_c;    /* define a dummy variable to avoid warning message */
#endif /* SIN_WAV_SYN */


