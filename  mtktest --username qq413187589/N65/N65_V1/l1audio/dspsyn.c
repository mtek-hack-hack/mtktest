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
 * dspsyn.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   DSP Wavetable Synthesizer Driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( DSP_WT_SYN )

#include "dspsyn.h"
#include "ddload.h"
#include "afe.h"

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

#define DSPSYN_TRACE   kal_prompt_trace
//#define DSPSYN_TRACE   (void)
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
extern unsigned int        WTVolumeTable[64 + 24];
extern unsigned int        Wavetable[];
#else
extern const unsigned int        WTVolumeTable[64 + 24];
extern const unsigned int        Wavetable[];
#endif

#define RTMIDI_BUFS              4        /* should be power of 2 */
#define RTMIDI_BUFSIZE           128
#define INST_Q_SIZE              16

#define CTRL_STATE_IDLE          0
#define CTRL_STATE_BEGIN         1
#define CTRL_STATE_PLAYING       2
#define CTRL_STATE_STOP          3
#define CTRL_STATE_END           8

typedef struct media_handle_internal {
   Media_Handle   mh;      /* this should be the first line in this structure */
   /* DSPSYN internal use */
   void           (*endHandler)( Media_Handle *handle );
   void           (*getCmd)(Media_Handle *handle, kal_uint16 *dtime, kal_uint16 cmd[4]);
   kal_uint16     state_bit;
   kal_bool       active;
   kal_uint16     end_flag;
   struct media_handle_internal *next;
} Media_Handle_Dspsyn;

static struct {
   kal_semid      sema;
   uint16         state;
   uint16         ending_state;
   uint16         aud_id;
   uint16         end_cmd;
   uint32         midChannelState;
   MidiChannel    midChannel[MAX_CHANNEL];

   Media_Handle_Dspsyn   *hdl_list;
   uint16         hdl_state;

   uint16         *rtmidi_dspbuf;
   uint16         rtmidi_events[RTMIDI_BUFS];
   uint16         *rtmidi_buf;
   uint8          rtmidi_head;
   uint8          rtmidi_tail;
#if APM_SUPPORT    
   uint8          apm_ending_state;
#endif   
   RINGBUFFER_T(int16,INST_Q_SIZE)  instq;

   bool           terminate;
} dspsyn;

#define RTMIDI_COUNT()     ((int)(uint8)(dspsyn.rtmidi_tail-dspsyn.rtmidi_head))
#define RTMIDI_MASK()      (RTMIDI_BUFS-1)

/* ----------------------------------------------------------------------------------------------- */
static void DSPSYN_GetWavCmd( Media_Handle_Dspsyn *handle, uint16 state_word, uint16 **buf, uint16 *cmdCount )
{
   uint16 cmd[4];
   uint16 dtime;
   uint16 *ptr = *buf;
   uint16 count = *cmdCount;

   dtime = 18;
   while( count <= RTMIDI_BUFSIZE-4 ) {
      cmd[0] = 0;
      if( dspsyn.end_cmd == 0 )
         handle->getCmd( (Media_Handle*)handle, &dtime, cmd );
         
      if( cmd[0] == DSPSYN_CMD_NO_DATA ) {
         break;
      }
      else if( cmd[0] == DSPSYN_CMD_STOP || cmd[0] == DSPSYN_CMD_END ) {
         handle->end_flag = cmd[0];
         cmd[0] = DSPSYN_CMD_NO_DATA;
         break;
      }
      else if( cmd[0] == DSPSYN_CMD_CONTINUE ) {
         continue;
      }
      else {
         *ptr++ = cmd[1];      count++;
         if( cmd[0] > 1 ) {
            *ptr++ = cmd[2];           count++;
            if( cmd[0] > 2 ) {
               *ptr++ = cmd[3];        count++;
            }
         }
      }
   }
   *buf = ptr;
   *cmdCount = count;
}
/* ----------------------------------------------------------------------------------------------- */
static void DSPSYN_GetCmd( Media_Handle_Dspsyn *handle, uint16 state_word, uint16 **buf, uint16 *cmdCount )
{
   uint16 cmd[4];
   uint16 dtime;
   uint16 *ptr = *buf;
   uint16 count = *cmdCount;

   dtime = 18;
   while( count <= RTMIDI_BUFSIZE-4 ) {
      cmd[0] = 0;
      if( dspsyn.end_cmd == 0 )
         handle->getCmd( (Media_Handle*)handle, &dtime, cmd );
         
      while( !RB_EMPTY( dspsyn.instq ) && count <= RTMIDI_BUFSIZE-7 ) {
         int16 val;
         RB_GET( dspsyn.instq, val );
         if( val > 0 ) {
            val--;
            *ptr++ = 0x1800 + val;        /* specify the channel as a percussion channel */
         }
         else {
            val = -val - 1;
            *ptr++ = 0x1900 + val;        /* specify the channel as a melody channel */
         }
         *ptr++ = 0x0400 + val;  /* reset the default instrument to be 0(piano)*/
         *ptr++ = 0x0000;
         count += 3;
         DSPSYN_TRACE( MOD_L1SP, "SetCh %d", val );
      }
      
      if( cmd[0] == DSPSYN_CMD_NO_DATA ) {
         break;
      }
      else if( cmd[0] == DSPSYN_CMD_STOP || cmd[0] == DSPSYN_CMD_END ) {
         handle->end_flag = cmd[0];
         cmd[0] = DSPSYN_CMD_NO_DATA;
         break;
      }
      else if( cmd[0] == DSPSYN_CMD_CONTINUE ) {
         continue;
      }
      else {         
         *ptr++ = cmd[1];      count++;
         if( cmd[0] > 1 ) {
            *ptr++ = cmd[2];           count++;
            if( cmd[0] > 2 ) {
               *ptr++ = cmd[3];        count++;
            }
         }
      }
   }
   *buf = ptr;
   *cmdCount = count;
}

static void DSPSYN_Tick_Task( void *data )
{
   uint16 cmdCount = 0;
   uint16 *ptr;
   Media_Handle_Dspsyn *hdl;

   if( (uint32)data != 0 ) {     /* end of playback */
      DSPSYN_TRACE(MOD_L1SP, "DFreeBuf");
      free_ctrl_buffer( dspsyn.rtmidi_dspbuf );
      dspsyn.rtmidi_dspbuf = (uint16*)0;
      free_ctrl_buffer( dspsyn.rtmidi_buf );
      dspsyn.rtmidi_buf = (uint16*)0;
      L1Audio_UnhookHisrHandler( DP_D2C_WT );      
      L1Audio_ClearFlag( dspsyn.aud_id );
      L1Audio_FreeAudioID( dspsyn.aud_id );
      ktUnlock();
      
      for( hdl = dspsyn.hdl_list; hdl != 0; hdl = hdl->next ) {
         if( hdl->active == true ) {
            hdl->active = false;
            DSPSYN_TRACE(MOD_L1SP, "CallEndHdlr");
            hdl->endHandler( (Media_Handle*)hdl );
            break;
         }
      }
      return;
   }

   while( RTMIDI_COUNT() < RTMIDI_BUFS ) {
      ptr = dspsyn.rtmidi_buf + (dspsyn.rtmidi_tail&RTMIDI_MASK()) * RTMIDI_BUFSIZE;
      cmdCount = 0;

      for( hdl = dspsyn.hdl_list; hdl != 0; hdl = hdl->next ) {
         if( hdl->active == true ) {
            if( (hdl->state_bit&DSPSYN_WAV_MASK) == 0 )
               DSPSYN_GetCmd( hdl, hdl->state_bit, &ptr, &cmdCount );
            else                          /* Wave player need Task-Level tick */
               hdl->getCmd( (Media_Handle*)hdl, 0, 0 );
         }
      }
      if( cmdCount == 1 ) {      /* If duplicate the single word due to DSP/HW requirement */
         ptr = dspsyn.rtmidi_buf + (dspsyn.rtmidi_tail&RTMIDI_MASK()) * RTMIDI_BUFSIZE;
         ptr[1] = ptr[0];
         cmdCount = 2;
      }
      dspsyn.rtmidi_events[dspsyn.rtmidi_tail&RTMIDI_MASK()] = cmdCount;
      dspsyn.rtmidi_tail++;
   }

   for( hdl = dspsyn.hdl_list; hdl != 0; hdl = hdl->next ) {
      if( hdl->active == true && hdl->end_flag != 0 ) {
         uint16 st_word = hdl->state_bit;
         if( hdl->end_flag == DSPSYN_CMD_STOP ) {
            DSPSYN_TRACE(MOD_L1SP, "GotStopCmd %d->%d, head=%d, tail=%d", dspsyn.state, dspsyn.state & ~st_word, dspsyn.rtmidi_head,dspsyn.rtmidi_tail);
         }
         else { /* hdl->end_flag == DSPSYN_CMD_END */
            DSPSYN_TRACE(MOD_L1SP, "GotEndCmd %d->%d, head=%d, tail=%d", dspsyn.state, dspsyn.state & ~st_word, dspsyn.rtmidi_head,dspsyn.rtmidi_tail);
         }
         if( (dspsyn.state & ~st_word) != 0 ) {
            dspsyn.state &= ~st_word;
            hdl->active = false;
            hdl->endHandler( (Media_Handle*)hdl );
         }
         else {
            dspsyn.ending_state = dspsyn.state;
            dspsyn.state = 0;
            dspsyn.end_cmd = hdl->end_flag;
         }
         hdl->end_flag = 0;
      }
   }
}

static void dspsynEndHandler(void *data, Media_Event event)
{
   (void) data;      // to avoid warning
   ASSERT( dspsyn.ending_state != 0 );
   AM_AudioPlaybackOff( false );
   DSPSYN_TRACE(MOD_L1SPHISR, "DSP Idle");
   L1Audio_SetEvent( dspsyn.aud_id, (void *)dspsyn.ending_state );
   dspsyn.ending_state = 0;
   dspsyn.terminate = false;
#if APM_SUPPORT         
   dspsyn.apm_ending_state = 0;
#endif    
      
}

#if APM_SUPPORT
bool DSPSYN_APM_Ending( void )
{
   if(dspsyn.apm_ending_state == 2)
      return KAL_TRUE;
   else 
      return KAL_FALSE;   
   
}
#endif 

void DSPSYN_Tick( void *data )
{
   uint16 I, cmdCount;
   uint16 *ptr, *ptr2;
   uint16 ctrl = DP_WT_CTRL;
   Media_Handle_Dspsyn *hdl;

   if( ctrl == CTRL_STATE_IDLE ) {  /* DSP return to idle state */
   #if APM_SUPPORT
      if(dspsyn.apm_ending_state == 1)
      {
          dspsyn.apm_ending_state = 2; 
          APM_NOTIFY_MEDIA_END( dspsynEndHandler, NULL, false , MEDIA_END);
      }    
      else 
   #endif    
      dspsynEndHandler(NULL, 0);         
   }
   else if( ctrl == CTRL_STATE_PLAYING ) {
      cmdCount = 0;
      ptr = dspsyn.rtmidi_dspbuf;
      for( hdl = dspsyn.hdl_list; hdl != 0; hdl = hdl->next ) {
         if( hdl->active == true && (hdl->state_bit&DSPSYN_WAV_MASK) )    /* WAV getCmd runs in HISR */
            DSPSYN_GetWavCmd( hdl, hdl->state_bit, &ptr, &cmdCount );
      }

      if( RTMIDI_COUNT() > 0 ) {
         ptr2 = dspsyn.rtmidi_buf + (dspsyn.rtmidi_head&RTMIDI_MASK()) * RTMIDI_BUFSIZE;;
         I = dspsyn.rtmidi_events[dspsyn.rtmidi_head&RTMIDI_MASK()];
         cmdCount += I;
         ASSERT( cmdCount <= RTMIDI_BUFSIZE );
         for( ; I > 0; I-- )
            *ptr++ = *ptr2++;
         DP_WT_EVT_COUNT = cmdCount;
         dspsyn.rtmidi_head++;
      }
      else {
         DP_WT_EVT_COUNT = cmdCount;
         if( dspsyn.end_cmd != 0 ) {
            if ( (dspsyn.ending_state & DSPSYN_WAV_MASK) || dspsyn.end_cmd == DSPSYN_CMD_STOP )
               DP_WT_CTRL = CTRL_STATE_STOP;
            else 
            {
            #if APM_SUPPORT   
               dspsyn.apm_ending_state = 1;
            #endif    
               DP_WT_CTRL = CTRL_STATE_END;
            }   

            dspsyn.end_cmd = 0;
            return;
         }
      }
      if( dspsyn.end_cmd == 0 )
         L1Audio_SetEvent( dspsyn.aud_id, (void *)0 );
   }
   else if( ctrl == CTRL_STATE_END ){     /* polling for stop command */
   #if APM_SUPPORT
      dspsyn.apm_ending_state = 0;
   #endif    
      DSPSYN_TRACE(MOD_L1SPHISR, "DSP Ending");
      if( dspsyn.terminate ) {
         DSPSYN_TRACE(MOD_L1SPHISR, "DSP Terminating" );
         DP_WT_CTRL = CTRL_STATE_STOP;
         dspsyn.terminate = false;
      }
      else {
         uint16 cmd[4];
         uint16 dtime;
         for( hdl = dspsyn.hdl_list; hdl != 0; hdl = hdl->next ) {
            if( hdl->active == true ) {
               hdl->getCmd( (Media_Handle*)hdl, &dtime, cmd );
               if( cmd[0] == DSPSYN_CMD_STOP )
                  DP_WT_CTRL = CTRL_STATE_STOP;
               break;
            }
         }
      }
   }
}

void DSPSYN_Start( Media_Handle *handle, void (*end)(Media_Handle *handle),
                     void (*getCmd)(Media_Handle *handle,uint16 *dtime,uint16 cmd[4]), bool reset )
{
   uint32 savedMask;
   uint16 I;
   const int16 *melody_fir;
   Media_Handle_Dspsyn *ihandle = (Media_Handle_Dspsyn *)handle;

   ASSERT( (dspsyn.state & ihandle->state_bit) == 0 );

   kal_take_sem( dspsyn.sema, KAL_INFINITE_WAIT );

   DSPSYN_TRACE(MOD_L1SP, "DStart %x", dspsyn.state|ihandle->state_bit );

   savedMask = SaveAndSetIRQMask();
   if( dspsyn.ending_state ) {
      dspsyn.terminate = true;
      RestoreIRQMask(savedMask);      
      DSPSYN_TRACE(MOD_L1SP, "PutTermCmd" );
      for( I = 0; ; I++ ) {
         if( !dspsyn.ending_state )
            break;
         ASSERT( I < 50 );
         kal_sleep_task( 2 );
      }
      ASSERT( dspsyn.state == 0 );
      savedMask = SaveAndSetIRQMask();
   }
   ihandle->active      = true;
   ihandle->endHandler  = end;
   ihandle->getCmd      = getCmd;
   I                    = dspsyn.state;
   dspsyn.state         |= ihandle->state_bit;
   RestoreIRQMask(savedMask);
 
#if APM_SUPPORT   
   dspsyn.apm_ending_state = 0;
#endif 
   
   AFE_SetDigitalGain(L1SP_AUDIO, 100);
   
   if( I == 0 ) {
      DSPSYN_TRACE(MOD_L1SP, "DSP Start %x", dspsyn.state);
      dspsyn.rtmidi_head = 0;
      dspsyn.rtmidi_tail = 0;

      ktLock();
      
      ASSERT( dspsyn.rtmidi_dspbuf == (uint16*)0 );
      dspsyn.rtmidi_dspbuf = (uint16 *)get_ctrl_buffer( sizeof(uint16)*RTMIDI_BUFSIZE );
      ASSERT( dspsyn.rtmidi_buf == (uint16*)0 );
      dspsyn.rtmidi_buf = (uint16 *)get_ctrl_buffer( sizeof(uint16)*RTMIDI_BUFS*RTMIDI_BUFSIZE );
   
      dspsyn.aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( dspsyn.aud_id, DSPSYN_Tick_Task );
      L1Audio_SetFlag( dspsyn.aud_id );
      L1Audio_HookHisrHandler( DP_D2C_WT, DSPSYN_Tick, 0 );
#if defined( DSP_WT_SYN )
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      AM_AudioPlaybackOn( ASP_TYPE_MELODY_16K, ASP_FS_32K );
   
      DP_WT_EVT_COUNT      = 0;
      DP_WT_EFFECT         = 3;
      DP_WT_VOLUME         = DG_MIDI;
      DP_WT_VOLUME2        = DG_IMY;
      DP_WT_ADDR_LO        = (uint16)((uint32)Wavetable & 0xFFFF);
      DP_WT_ADDR_HI        = (uint16)((uint32)Wavetable >> 16);
      DP_WT_INST_VOL_LO    = (uint16)((uint32)WTVolumeTable & 0xFFFF);
      DP_WT_INST_VOL_HI    = (uint16)((uint32)WTVolumeTable >> 16);
      melody_fir = mediaGetControl()->Media_FIR_Melody32K_1;
      DP_WT_EQPARA_LO      = (uint16)((uint32)melody_fir & 0xFFFF);
      DP_WT_EQPARA_HI      = (uint16)((uint32)melody_fir >> 16);
      DP_WT_RTMIDI_ADDR_LO = (uint16)((uint32)dspsyn.rtmidi_dspbuf & 0xFFFF);
      DP_WT_RTMIDI_ADDR_HI = (uint16)((uint32)dspsyn.rtmidi_dspbuf >> 16);
      DP_WT_RESET_CTRLR    = (reset)? 1 : 0;
   
      ASSERT( DP_WT_CTRL == 0 );
      DP_WT_CTRL        = 1;
   
      for( I = 0; ; I++ ) {
         if( DP_WT_CTRL == 2 )
            break;
         ASSERT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
   kal_give_sem( dspsyn.sema );
}

void DSPSYN_ReleaseHandle( Media_Handle *handle )
{
   Media_Handle_Dspsyn   *ihandle = (Media_Handle_Dspsyn *)handle;
   Media_Handle_Dspsyn   *hdl;

   ASSERT( dspsyn.hdl_state & ihandle->state_bit );
   if( dspsyn.hdl_list == ihandle ) {
      dspsyn.hdl_list = ihandle->next;
   }
   else {
      hdl = dspsyn.hdl_list;
      while( hdl->next != ihandle )
         hdl = hdl->next;
      hdl->next = ihandle->next;
   }
   dspsyn.hdl_state &= ~ihandle->state_bit;
   free_ctrl_buffer( ihandle );
}

/* -------------------------------------------------------------------------------------- */
Media_Handle *DSPSYN_ObtainSmfHandle( void )
{
   uint16 I, state_bit;
   Media_Handle_Dspsyn *handle;

   for( I = 0; I < MAX_MIDI_PLAYERS; I++ ) {
      state_bit = DSPSYN_MIDI_STATE << I;
      if( (dspsyn.hdl_state & state_bit) == 0 ) {
         dspsyn.hdl_state |= state_bit;

         handle = (Media_Handle_Dspsyn*)get_ctrl_buffer( sizeof(Media_Handle_Dspsyn) );
         handle->active = false;
         handle->end_flag = 0;
         handle->state_bit = state_bit;
         handle->next = dspsyn.hdl_list;
         handle->mh.index = I;
         dspsyn.hdl_list = handle;
         return (Media_Handle *)handle;
      }
   }
   return 0;
}

Media_Handle *DSPSYN_ObtainWavHandle( void )
{
   uint16 I, state_bit;
   Media_Handle_Dspsyn *handle;

   for( I = 0; I < MAX_WAV_PLAYERS; I++ ) {
      state_bit = DSPSYN_WAV_STATE << I;
      if( (dspsyn.hdl_state & state_bit) == 0 ) {
         dspsyn.hdl_state |= state_bit;

         handle = (Media_Handle_Dspsyn*)get_ctrl_buffer( sizeof(Media_Handle_Dspsyn) );
         handle->active = false;
         handle->end_flag = 0;
         handle->state_bit = state_bit;
         handle->next = dspsyn.hdl_list;
         handle->mh.index = I;
         dspsyn.hdl_list = handle;
         return (Media_Handle *)handle;
      }
   }
   return 0;
}

Media_Handle *DSPSYN_ObtainToneHandle( void )
{
   uint16 I, state_bit;
   Media_Handle_Dspsyn *handle;

   for( I = 0; I < MAX_TONE_PLAYERS; I++ ) {
      state_bit = DSPSYN_TONE_STATE << I;
      if( (dspsyn.hdl_state & state_bit) == 0 ) {
         dspsyn.hdl_state |= state_bit;

         handle = (Media_Handle_Dspsyn*)get_ctrl_buffer( sizeof(Media_Handle_Dspsyn) );
         handle->active = false;
         handle->end_flag = 0;
         handle->state_bit = state_bit;
         handle->next = dspsyn.hdl_list;
         handle->mh.index = I;
         dspsyn.hdl_list = handle;
         return (Media_Handle *)handle;
      }
   }
   return 0;
}

/* -------------------------------------------------------------------------------------- */
MidiChannel *DSPSYN_GetMidiChannel( bool perc )
{
   int I;
   uint32 check_bit;
   MidiChannel *ch = (MidiChannel*)0;
   uint32 savedMask;

   for( I = 0; I < MAX_CHANNEL; I++ ) {
      check_bit = 1 << I;
      savedMask = SaveAndSetIRQMask();
      if( (dspsyn.midChannelState & check_bit) == 0 ) {
         dspsyn.midChannelState |= check_bit;
         ch = &dspsyn.midChannel[I];
         RestoreIRQMask(savedMask);
         DSPSYN_TRACE( MOD_L1SP, "GetCh %d", I );
         if( perc ) {
            RB_PUT( dspsyn.instq, (int16)(I+1) );
         }
         else {
            RB_PUT( dspsyn.instq, (int16)-(I+1) );
         }
         break;
      }
      RestoreIRQMask(savedMask);
   }
   if( ch != (MidiChannel*)0 ) {
      ch->bank       = 0;
      ch->program    = 0;
      ch->volume     = 90;
      ch->pitchsens  = 2;
      ch->flag       = 0;
      ch->dspChannel = I;
   }
   return ch;
}

void DSPSYN_FreeMidiChannel( MidiChannel *channel )
{
   uint32 check_bit;
   uint32 savedMask;
   uint32 count, I;
   int16 inst;

   check_bit = 1 << channel->dspChannel;
   count = RB_COUNT( dspsyn.instq );

   for( I = 0; I < count; I++ ) {
      savedMask = SaveAndSetIRQMask();   	
      RB_GET( dspsyn.instq, inst );
      if( inst == (channel->dspChannel+1) || inst == -(channel->dspChannel+1) ) {
         RestoreIRQMask(savedMask);
         continue;
      }
      RB_PUT( dspsyn.instq, inst );
      RestoreIRQMask(savedMask);
   }

   savedMask = SaveAndSetIRQMask();   
   if( dspsyn.midChannelState & check_bit )
      dspsyn.midChannelState &= ~check_bit;
   RestoreIRQMask(savedMask);
}


void DSPSYN_Init( void )
{
   dspsyn.sema             = kal_create_sem( "dspsyn", 1 );
   dspsyn.state            = 0;

   RB_INIT( dspsyn.instq );

   dspsyn.ending_state     = 0;
   dspsyn.end_cmd          = 0;
   dspsyn.hdl_state        = 0;
   dspsyn.hdl_list         = 0;
   dspsyn.terminate        = false;
   dspsyn.rtmidi_dspbuf    = (uint16*)0;
   dspsyn.rtmidi_buf       = (uint16*)0;
   dspsyn.midChannelState  = 0;           /* all Midi channels are free */

   DP_WT_CTRL              = 0;
   DP_WT_EVT_COUNT         = 0;
   DP_WT_EFFECT            = 3;
}

#endif /* DSP_WT_SYN */


