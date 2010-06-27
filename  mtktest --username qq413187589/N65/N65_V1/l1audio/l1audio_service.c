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
 * l1audio_service.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Task / L1Audio Service 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "eint.h"
#include "afe.h"
#include "VMI.h"

#if defined( SW_SYN_16K ) || defined( SW_SYN_8K )
#include "midisyn.h"
#endif

#if !defined(MT6205B)
#define  MAX_HISR_HANDLER        3
#else 
#define  MAX_HISR_HANDLER        2
#endif       

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );
extern void DisableIRQ(void);

#ifdef MTK_SLEEP_ENABLE
uint8    L1SM_GetHandle( void );
void     L1SM_SleepEnable( uint8 handle );
void     L1SM_SleepDisable( uint8 handle );
#define  GET_SLEEP_HANDLE()   {  l1audio.sleep_handle=L1SM_GetHandle();       }
#define  SLEEP_LOCK()         {  L1SM_SleepDisable( l1audio.sleep_handle );   }
#define  SLEEP_UNLOCK()       {  L1SM_SleepEnable( l1audio.sleep_handle );    }
#else /* MTK_SLEEP_ENABLE */
#define  GET_SLEEP_HANDLE()
#define  SLEEP_LOCK()
#define  SLEEP_UNLOCK()
#endif /* MTK_SLEEP_ENABLE */

/* ------------------------------------------------------------------------------ */

static struct {
   uint32               state;
   kal_eventgrpid       aud_events;
   uint16               media_flag;
   kal_hisrid           hisr;

   L1Audio_EventHandler evHandler[MAX_AUDIO_FUNCTIONS];
   void                 *evData[MAX_AUDIO_FUNCTIONS];
   uint32               id_flag;
   uint32               event_flag;
   L1Audio_EventHandler hisrHandler[MAX_HISR_HANDLER];
   uint16               hisrMagicNo[MAX_HISR_HANDLER];
   void                 *hisrUserData[MAX_HISR_HANDLER];
   uint16               hisrMagicFlag;
   L1Audio_EventHandler postHisrHandler;
   uint8                sleep_handle;
   
   int8                dsp_slow_idle_counter;
   
   uint16               debug_info[NUM_DEBUG_INFO];
} l1audio;

/* ------------------------------------------------------------------------------ */

extern void L1D_DSP_EnableDspSlowIdle( void );
int8 L1Audio_Disable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    dis_check_counter; 

   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter++;
   dis_check_counter = l1audio.dsp_slow_idle_counter;
   
#if defined(MT6205B)
   DP_SLOW_IDLE_CTRL = 0;   // DSP clock rate = 26MHz (52MHz / 2)
#else
   DP_SLOW_IDLE_CTRL = 0xFFFF;
#endif
   RestoreIRQMask( savedMask );

   return dis_check_counter;

}

int8 L1Audio_Enable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    en_check_counter;
   
   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter--;
   en_check_counter = l1audio.dsp_slow_idle_counter;
   
   if ( l1audio.dsp_slow_idle_counter == 0 )   
       L1D_DSP_EnableDspSlowIdle();      

   RestoreIRQMask( savedMask );   
   ASSERT( en_check_counter >= 0 );

   return en_check_counter;
}


uint16 L1Audio_GetAudioID( void )
{
   uint32 I;
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
      if( (l1audio.id_flag & (1<<I)) == 0 ) {
         l1audio.id_flag |= (1<<I);
         break;
      }
   }
   RestoreIRQMask( savedMask );

   ASSERT( (l1audio.state & (1 << I)) == 0 );
   ASSERT( I < MAX_AUDIO_FUNCTIONS );
   return (uint16)I;
}

void L1Audio_FreeAudioID( uint16 aud_id )
{
   uint32 savedMask;

   ASSERT( (l1audio.state & (1 << aud_id)) == 0 );
   ASSERT( l1audio.id_flag & (1<<aud_id) );
   savedMask = SaveAndSetIRQMask();
   l1audio.id_flag &= ~(1<<aud_id);
   RestoreIRQMask( savedMask );
}

void L1Audio_SetEventHandler( uint16 audio_id, L1Audio_EventHandler handler )
{
   l1audio.evHandler[audio_id] = handler;
}

void L1Audio_SetEvent( uint16 audio_id, void *data )
{
   l1audio.evData[audio_id] = data;
   kal_set_eg_events( l1audio.aud_events, 1 << audio_id, KAL_OR );      /* Activate L1Audio Task */
}

void L1Audio_LSetEvent( uint16 audio_id, void *data )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   l1audio.evData[audio_id] = data;
   l1audio.event_flag |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_activate_hisr( l1audio.hisr );                                   /* Activate L1Audio HISR */
}

bool L1Audio_CheckFlag( uint16 audio_id )      /* return true if error happens */
{
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   if( l1audio.state & (1 << audio_id) )
      return true;
   return false;
}

void L1Audio_SetFlag( uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.state & (1 << audio_id)) == 0 );

   savedMask = SaveAndSetIRQMask();
   l1audio.state |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   SLEEP_LOCK();
}

void L1Audio_ClearFlag( uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.state & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.state &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );
   if( l1audio.state == 0 )
      SLEEP_UNLOCK();
}

void L1Audio_EnterDedicatedMode( void )
{
#if defined( SW_SYN_16K ) || defined( SW_SYN_8K )
   polyphony_limit = MAX_POLYPHONY_BUSY;
#endif
}

void L1Audio_LeaveDedicatedMode( void )
{
#if defined( SW_SYN_16K ) || defined( SW_SYN_8K )
   polyphony_limit = MAX_POLYPHONY;
#endif
}
/* ------------------------------------------------------------------------------ */
/*  L1Audio HISR                                                                  */
/* ------------------------------------------------------------------------------ */

static void L1Audio_HISR( void )
{
   uint32 savedMask;
   int32  I;

   L1Audio_Disable_DSPSlowIdle();

   if( l1audio.hisrMagicFlag ) {
      for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
         if( l1audio.hisrMagicFlag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.hisrMagicFlag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            l1audio.hisrHandler[I]( l1audio.hisrUserData[I] );
            if( l1audio.postHisrHandler != (L1Audio_EventHandler)0 )
               l1audio.postHisrHandler( (void*)l1audio.hisrMagicNo[I] );
         }
      }
   }
   if( l1audio.media_flag != 0 ) {        /* Audio File Playback/Recording */
#ifndef __L1_STANDALONE__ // avoid link error
      mediaHisr( l1audio.media_flag );
#endif
      if( l1audio.postHisrHandler != (L1Audio_EventHandler)0 )
         l1audio.postHisrHandler( (void*)l1audio.media_flag );
      l1audio.media_flag = 0;
   }
   if( l1audio.event_flag ) {
      int16 I;
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if( l1audio.event_flag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.event_flag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            L1Audio_SetEvent( I, l1audio.evData[I] );
         }
      }
   }

   // To restore slow idle ctrl for DSP
   L1Audio_Enable_DSPSlowIdle();
}

void L1SP_D2C_LISR( uint16 itype )
{
   int32  I;

   L1Audio_Msg_DSP_INT( itype );
   
#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if(itype == 0xDD44){
      bool dsp_ok = false;
      itype = *DSP_DEAD_INT;
      if( itype == 0xDD44 ) {
         extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
         DisableIRQ();
         *DP_D2C_TASK1 = 0;            /* freeze DSP */
         L1D_WIN_DisableAllEvents( 0 ); /* disable all TDMA events */
#ifndef  L1D_TEST 
         {
            ASSERT_DUMP_PARAM_T dump_param;
         
            /* Write DSP debug info to exception record */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
            dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x0A0*2);    
            dump_param.len[0]  = 70*2;
            dump_param.addr[1] = (kal_uint32)(DPRAM2_CPU_base+0x130*2);  
            dump_param.len[1]  = 180*2;
            dump_param.addr[2] = 0;    //End of dump param
#else          
            dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x130*2);  
            dump_param.len[0]  = 250*2;
            dump_param.addr[1] = 0;    //End of dump param
#endif         
            EXT_ASSERT_DUMP(0, 0x20060622, 0, 0, &dump_param);
         }
#else
         {
            extern void  L1DTest_AssertFail(void);
            L1DTest_AssertFail();
         }
#endif
      }
      itype = *DSP_PCM_REC_INT;
      if( itype == 0xAA55 || itype == 0xAA56 )
      {
         *DSP_PCM_REC_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;
      }
      itype = *DSP_SOUND_EFFECT_INT;
      if( itype == 0xAA57 )
      {
         *DSP_SOUND_EFFECT_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;
      }
#if defined( __BT_AUDIO_VIA_SCO__ )
      itype = *DP_AUDIO_VIA_8KBT_INT;
      if( itype == D2C_AUDIO_VIA_8KBT_ID )
      {
         *DP_AUDIO_VIA_8KBT_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;
      }
#endif

      if (!dsp_ok) {
         extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
         DisableIRQ();
         *DP_D2C_TASK1 = 0;            /* freeze DSP */
         L1D_WIN_DisableAllEvents( 0 ); /* disable all TDMA events */
         ASSERT_REBOOT(0);
      }
      return;
   }
#else
   if(itype == 0xDD44){
      extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
      DisableIRQ();
      *DP_D2C_TASK1 = 0;            /* freeze DSP */
      L1D_WIN_DisableAllEvents( 0 ); /* disable all TDMA events */
      
      {
         ASSERT_DUMP_PARAM_T dump_param;
         
         /* Write DSP debug info to exception record */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
         dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x0A0*2);    
         dump_param.len[0]  = 70*2;
         dump_param.addr[1] = (kal_uint32)(DPRAM2_CPU_base+0x130*2);  
         dump_param.len[1]  = 180*2;
         dump_param.addr[2] = 0;    //End of dump param
#else          
         dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x130*2);  
         dump_param.len[0]  = 250*2;
         dump_param.addr[1] = 0;    //End of dump param
#endif         
         EXT_ASSERT_DUMP(0, 0x20060622, 0, 0, &dump_param);
      }
   }
#endif

   if( (itype == DP_D2C_SE_SD_DONE) && (*DP_GSM_MODE & 0x02) ) // Fix DSP bug, update flag as GPRS or EDGE connection
      itype = DP_D2C_SE_DONE;

   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( itype == l1audio.hisrMagicNo[I] ) {
         l1audio.hisrMagicFlag |= (1<<I);
         kal_activate_hisr(l1audio.hisr);
         return;
      }
   }
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   if (itype == 0x1234) {
      Media_A2V_LISR();
   } else
#endif
   {
      l1audio.media_flag = itype;
      kal_activate_hisr(l1audio.hisr);
   }
}

void L1Audio_HookHisrHandler( kal_uint16 magic_no, L1Audio_EventHandler handler, void *userData )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == 0 ) {
         l1audio.hisrMagicNo[I] = magic_no;
         l1audio.hisrHandler[I] = handler;
         l1audio.hisrUserData[I] = userData;
         break;
      }
   }
   ASSERT( I != MAX_HISR_HANDLER );
}

void L1Audio_UnhookHisrHandler( kal_uint16 magic_no )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == magic_no ) {
         l1audio.hisrMagicNo[I] = 0;
         break;
      }
   }
   ASSERT( I != MAX_HISR_HANDLER );
}

void L1Audio_SetPostHisrHandler( L1Audio_EventHandler handler )
{
   ASSERT( l1audio.postHisrHandler == (L1Audio_EventHandler)0 );
   l1audio.postHisrHandler = handler;
}

void L1Audio_ResetPostHisrHandler( void )
{
   ASSERT( l1audio.postHisrHandler != (L1Audio_EventHandler)0 );
   l1audio.postHisrHandler = (L1Audio_EventHandler)0;
}

void L1Audio_SetDebugInfo( kal_uint16 debug_info[NUM_DEBUG_INFO])
{
   memcpy(l1audio.debug_info, debug_info, NUM_DEBUG_INFO*sizeof(uint16));
}

kal_uint16 L1Audio_GetDebugInfo( kal_uint8 index )
{
   ASSERT( index < NUM_DEBUG_INFO );
   return l1audio.debug_info[index];   
}

/* ------------------------------------------------------------------------------ */
/*  Debug functions used to verify the data written to DSP                        */
/* ------------------------------------------------------------------------------ */
#if VERIFY_DATA_TO_DSP
#include   "fat_fs.h"
kal_uint8  bDSPBuffer[8192];
kal_uint16 uDSPBufferRead;
kal_uint16 uDSPBufferWrite;
kal_uint32 uDSPBufferSize;
kal_uint16 fname[12] = { 'E', ':', '\\', 'D', 'A', 'T', 'A', '.', 'D', 'A', 'T', 0x00 };
FS_HANDLE  fs_handle = 0;

void VERIFY_DATA_TO_DSP_START( void )
{
   if( fs_handle )
      FS_Close( fs_handle );
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_CREATE_ALWAYS );
   ASSERT( fs_handle > 0 );
   uDSPBufferSize = 8192;
   uDSPBufferRead = 0;
   uDSPBufferWrite = 0;
}

void VERIFY_DATA_TO_DSP_RESUME( void )
{
   kal_uint32 uFileSize;
   kal_int32  ret;
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_READ_WRITE|FS_CREATE );
   ASSERT( fs_handle > 0 );
   ASSERT( FS_GetFileSize(fs_handle, &uFileSize) >= 0 );
   ASSERT( FS_Seek(fs_handle, uFileSize, FS_FILE_BEGIN) >= 0 );
   uDSPBufferSize = 8192;
}

void VERIFY_DATA_TO_DSP_STOP( void )
{
   if( fs_handle )
   {
      ASSERT( FS_Close( fs_handle ) == 0 );
      fs_handle = 0;
   }
}

void VERIFY_DATA_TO_DSP_WRITE_DATA( const kal_uint16 *buf, int32 len )
{
   kal_uint32 uDSPBufferFree;
   if( uDSPBufferWrite < uDSPBufferRead )
   {  /// DDDDWxxxxxxxRDD
      uDSPBufferFree = uDSPBufferRead - uDSPBufferWrite - 1;
      ASSERT( len*2 <= uDSPBufferFree );
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, len*2);
      uDSPBufferWrite += len*2;
   }
   else
   {  /// xxxRDDDDDDWxxxx
      kal_uint32 free_1, free_2, write_count;
      free_1 = uDSPBufferSize - uDSPBufferWrite;
      free_2 = uDSPBufferRead - 1;
      uDSPBufferFree = free_1 + free_2;
      ASSERT( len*2 <= uDSPBufferFree );
      write_count = ( len*2 > free_1 )? free_1 : len*2;
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
      if( uDSPBufferWrite==uDSPBufferSize )
         uDSPBufferWrite = 0;
      write_count = len*2 - write_count;
      if( write_count )
         memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
   }
}

void VERIFY_DATA_TO_DSP_SAVE_DATA( void )
{
   if( fs_handle != 0 && uDSPBufferRead != uDSPBufferWrite )
   {
      kal_uint32 uDSPBufferUsed;
      kal_uint32 uDataSaved;
      if( uDSPBufferRead < uDSPBufferWrite )
      {  /// xxxRDDDDDDWxxxx
         uDSPBufferUsed = uDSPBufferWrite - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, uDSPBufferUsed, &uDataSaved );
         ASSERT( uDSPBufferUsed == uDataSaved );
         uDSPBufferRead += uDataSaved;
      }
      else
      {  /// DDDDWxxxxxxxRDD
         kal_uint32 used_1, used_2, write_count;
         used_1 = uDSPBufferSize - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, used_1, &uDataSaved );
         ASSERT( used_1 == uDataSaved );
         used_2 = uDSPBufferWrite;
         FS_Write( fs_handle, bDSPBuffer, used_2, &uDataSaved );
         ASSERT( used_2 == uDataSaved );
         uDSPBufferRead = uDataSaved;
      }
   }
}
#endif

/* ------------------------------------------------------------------------------ */
/*  L1Audio Task                                                                  */
/* ------------------------------------------------------------------------------ */
void L1Audio_Task(unsigned argc, void *argv)
{
   uint32 retrieved_events;
   uint32 I;

   l1audio.aud_events = kal_create_event_group("L1Audio");
   l1audio.hisr = kal_create_hisr("L1Audio_HISR", 1, 768, L1Audio_HISR, NULL );
   GET_SLEEP_HANDLE();

   l1audio.state        = 0;
   l1audio.dsp_slow_idle_counter = 0;
   l1audio.event_flag   = 0;
   l1audio.id_flag      = 0;
   l1audio.media_flag   = 0;
   l1audio.postHisrHandler = (L1Audio_EventHandler)0;

   l1audio.hisrMagicFlag = 0;
   for( I = 0; I < MAX_HISR_HANDLER; I++ )
      l1audio.hisrMagicNo[I] = 0;

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   DSP_DynamicDownload_Init();

#ifndef  L1D_TEST
   /// Dynamic download for A/V sync
#if defined( DSP_WT_SYN )
   DSP_DynamicDownload( DDID_WAVETABLE );
#endif
#endif
#endif
   AM_Init();

   /// AFE_Init will invoke L1Audio_GetAudioID
   /// and expect to get the id 0 to make sure
   /// it has the highest priority in the event group
   AFE_Init();

   L1SP_Init();

   ktInit( L1Audio_GetAudioID() );
   toneInit( L1Audio_GetAudioID() );
   mediaInit( L1Audio_GetAudioID() );
#if defined(VR_CYBERON)|| defined(VR_ITRI)
   vrsdInit();
#elif defined(VRSI_CYBERON)
   vrsiInit();
#endif
#if (defined(FM_RADIO_ENABLE))
   FMR_Init( L1Audio_GetAudioID() );
#endif

#if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217))
   toneLoopbackRecInit();
#endif

#if ( defined(__BT_A2DP_PROFILE__) || defined(SBC_UNIT_TEST) ) && !(APM_SUPPORT)
   SBC_Init();
#endif

#if APM_SUPPORT
   APM_Init();
#endif

#if defined(AUD_TIME_STRETCH)
   AudioPP_TS_Init();
#endif

#if defined( SW_SYN_16K ) || defined( SW_SYN_8K )
   polyphony_limit = MAX_POLYPHONY;
#endif

#ifdef __CTM_SUPPORT__
   l1ctm_init();
#endif

#if VMI_SUPPORT || defined(VORTP_UNIT_TEST)
   VMI_Init();
#endif

#if VORTP_SUPPORT || defined(VORTP_UNIT_TEST)
   VoRTP_Init();
#endif

   memset( &(l1audio.debug_info), 0, sizeof(l1audio.debug_info) );
      
   AFE_TurnOnFIR( L1SP_SPEECH );
   AFE_TurnOnFIR( L1SP_VOICE );

   while( 1 ) {
#if VERIFY_DATA_TO_DSP
      VERIFY_DATA_TO_DSP_SAVE_DATA();
#endif
      kal_retrieve_eg_events(l1audio.aud_events,0xFFFF,KAL_OR_CONSUME,&retrieved_events,KAL_SUSPEND);
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if( retrieved_events & (1<<I) ) {
            l1audio.evHandler[I]( l1audio.evData[I] );
         }
      }
      if( l1audio.state == 0 )
         SLEEP_UNLOCK();
   }
}

uint32 L1Audio_GetEventGroup( void )
{
   uint32 retrieved_events;
   kal_retrieve_eg_events( l1audio.aud_events, 0xFFFF, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND );
   return retrieved_events;
}

void L1Audio_ExeEventHandler( uint32 event )
{
   ASSERT( event < MAX_AUDIO_FUNCTIONS );
   l1audio.evHandler[event]( l1audio.evData[event] );
}

void L1Audio_ResetDevice(void)
{
   AFE_Init();

#if defined(EXT_AUDIO_CHIP)
   ExtAudChip_Reset();
#endif
}
/* ------------------------------------------------------------------------------ */

void L1Audio_InProcCall2(media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
#ifndef MED_NOT_PRESENT
   extern void aud_send_in_proc_call_req2( module_type src_mod_id, media_in_proc_call_type func,
	kal_uint32 func_arg1, void* func_arg2 );
   aud_send_in_proc_call_req2(MOD_L1SP, func, func_arg1, func_arg2);
#endif
}

void L1Audio_InProcCall(media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
#ifndef MED_NOT_PRESENT
   extern void aud_send_in_proc_call_req( module_type src_mod_id, media_in_proc_call_type func,
	kal_uint32 func_arg1, void* func_arg2 );
   aud_send_in_proc_call_req(MOD_L1SP, func, func_arg1, func_arg2);
#endif
}

static char *_get_next_arg(char **ppstring)
{
   char *pstring = *ppstring, *pstring_t;
   kal_uint8 ch;

   if( *pstring=='\0' )
      return NULL;

   while(1)
   { // find start
      ch = *pstring;
      if( ch!=' ' && ch!='\t' )
         break;
      pstring++;
   }

   pstring_t = pstring;

   while(1)
   {
      ch = *pstring;
      if( ch=='\0' )
         break;
      else if( ch==' ' || ch=='\t' )
      {
         *pstring = '\0';
         pstring++;
         break;
      }
      pstring++;
   }

   *ppstring = (char *)pstring;

   return pstring_t;
}

static void dispatcher(char **ppstring, int (*entry_main)(int argc, char **argv))
{
   int argc = 0;
   char *argv[16];

   while(1)
   {
      char *args = _get_next_arg( ppstring );

      if( args==NULL )
      {
         entry_main( argc, argv );
         break;
      }
      else if( strcmp( args, "|" )==0 )
      {
         argv[argc] = NULL;
         entry_main( argc, argv );
         argc = 0;
      }
      else
         argv[argc++] = args;
   }
}

#if defined(VORTP_UNIT_TEST)
extern int VoRTP_main(int argc, char **argv);
#endif

void l1audio_console(kal_uint8 index, kal_char *string)
{
   int (*entry_main)(int argc, char **argv);
   char *pstring = (char *)string;

   entry_main = NULL;
   switch(index)
   {
      case 99: /* VoRTP unit test */
      {
#if defined(VORTP_UNIT_TEST)
         entry_main = VoRTP_main;
#endif
         break;
      }
      default:
         break;
   }
   if( entry_main!=NULL )
      dispatcher(&pstring, entry_main);
}


