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
 * jamr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   AMR/AMR-WB playback interface for Java
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "media.h"

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

#include "amr_table.h"
#include "am.h"
#include "afe.h"

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
#define DSP_IDLE                     0
#define DSP_INITIALIZED              1
#define DSP_PLAYING                  2
#define DSP_RECORDING                2
#define DSP_STOP                     3
#endif

#define AMR_STATE_READY       0
#define AMR_STATE_NB_PLAY     1
#define AMR_STATE_NB_PAUSED   2
#define AMR_STATE_WB_PLAY     4
#define AMR_STATE_WB_PAUSED   8

#define DP_D2C_SD_DONE        0xDD01      /* magic number for l1audio HISR */

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

typedef struct media_handle_internal {
   Media_Handle      mh;      /* this should be the first line in this structure */
   Media_AMR_Param   param;
   const uint8       *orgpos;
   const uint8       *curpos;
   const uint8       *endpos;
   uint16            aud_id;
   int16             repeat_count;
   uint16            orderingBuffer[30];
   uint16            Tx_data_buffer[30];
   uint8             bCodecMode; /* Codec Mode for DSP Sherif Setting */
   uint8             play_style;
   bool              is_awb;
   Media_Status      end_status;
} Media_Handle_Internal;

static void jamrWriteSpeechMode( Media_Handle_Internal *handle, uint8 bCodecMode, uint8 bTxType )
{
#if defined(AMRWB_DECODE)
   if( handle->mh.state == AMR_STATE_WB_PLAY ) {
      *DP_SD2_AWB_VM_0 = (bCodecMode << 8) | bTxType; /* codec mode | Tx-Type */
   } else
#endif
   {
      *DP_SD2_VM_17 = bCodecMode;
      *DP_SD2_VM_0 = bTxType;
   }
}

static void jamrWriteSpeechData( Media_Handle_Internal *handle, uint16 *data, uint32 len )
{
   volatile uint16 *dspAddr;
   uint32 I;

#if defined(AMRWB_DECODE)
   if( handle->mh.state == AMR_STATE_WB_PLAY ) {
      I = 0;
      dspAddr = DP_SD2_AWB_VM_1;
      if( len > 17 ) {
         for(; I < 17; I++ )
            *dspAddr++ = *data++;
         dspAddr = DP_SD2_AWB_VM_18;
      }
      for(; I< len; I++)
         *dspAddr++ = *data++;
   } else
#endif
   {
      dspAddr = DP_SD2_VM_1;
      for (I = 0; I < len; I++)
         *dspAddr++ = *data++;
   }
}

static void jamrOrderConvert( Media_Handle_Internal *handle, uint32 bTxType, uint32 bFrameType,
                              uint16 *dataIn, uint16 *dataOut, uint32 bits)
{
   uint32 I, k, p, q;

#if defined(AMRWB_DECODE)
   if( handle->mh.state == AMR_STATE_WB_PLAY ) {
      const uint16 *tab = tblAMR_WBOrder[bFrameType];
      for( I = 0, p = 0, q = 0; I < bits; I++ ) {
         if( bTxType == 2 )   /* Speech */
            k = tab[I];
         else                 /* bTxType == 3, SID first or SID update */
            k = I;
         dataOut[k/16] |= (dataIn[q] & AMR_ord_tab[p]) ? AMR_get_tab[k%16] : 0;
         if( ++p == 16 ) {
            p = 0;
            q++;
         }
      }
   } else
#endif
   {
      const uint8 *tab = tblAMROrder[bFrameType];
      for( I = 0, p = 0, q = 0; I < bits; I++ ){
         if( bTxType == 2 )   /* Speech */
            k = tab[I];
         else                 /* SID first or SID update */
            k = I;
         dataOut[k/16] |= (dataIn[q] & AMR_ord_tab[p]) ? AMR_get_tab[k%16] : 0;
         if( ++p == 16 ) {
            p = 0;
            q++;
         }
      }
   }
}

/* FUNCTION:  jamrPass20ms
      return value:
         0 -> ok
         1 -> end
         2 -> error
*/
static int32 jamrPass20ms( const uint8 **curpos, const uint8 *endpos )
{
   uint32 FT, FQI;
   const uint8 *ptr = *curpos;

   if( ptr >= endpos )
      return 1;

   FQI = *ptr++;
   FT = (FQI >> 3) & 0x0F;
   FQI = (FQI >> 2) & 0x01;

   if (FT <= 8) { /* AMR 4.75 ~ 12.2 kbps and SID */
      ptr += (lenSpeechBitsAMR[FT] + 7) / 8;
   }
   else if( FT == 15 && FQI == 1 ) { /* no data */
      /* do nothing */
   }
   else {
      return 2; /* error */
   }

   *curpos = ptr;
   if( ptr >= endpos )
      return 1;
   return 0;
}

#if defined(AMRWB_DECODE)
/* FUNCTION:  jamrwbPass20ms
      return value:
         0 -> ok
         1 -> end
         2 -> error
*/
static int32 jamrwbPass20ms( const uint8 **curpos, const uint8 *endpos )
{
   uint32 FT, FQI;
   const uint8 *ptr = *curpos;

   if( ptr >= endpos )
      return 1;

   FQI = *ptr++;
   FT = (FQI >> 3) & 0x0F;
   FQI = (FQI >> 2) & 0x01;

   if( FT <= 9 ) { /* AMR-WB 6.60 kbps ~ 23.85 kbps */
      ptr += (lenSpeechBitsAMR_WB[FT] + 7) / 8;
   }
   else if( ( FT == 14 && FQI == 0 ) ||   /* SPEECH_LOST */
            ( FT == 15 && FQI == 1 ) ) {  /* NO_DATA */
      /* do nothing */
   }
   else { /* 'for-future-use' mode */
      return 2;
   }

   *curpos = ptr;
   if( ptr >= endpos )
      return 1;
   return 0;
}
#endif

static void jamrHisr( void *data );

static void jamrOpenDevice( Media_Handle_Internal *handle, uint16 wCodecMode )
{
   ktLock();
   L1Audio_SetFlag( handle->aud_id );
   L1Audio_HookHisrHandler( DP_D2C_SD_DONE, jamrHisr, (void*)handle );
   
#if AMR_AWB_AUDIO_PATH_SUPPORT
   {
      uint16 control = wCodecMode ;
      uint32 style = handle->play_style;
      uint32 vm_control  = (style<<16) | control;
      uint16 sc_mode, sd_mode;
      uint16 codec_mode;
      uint16 amr_sd_mode = (control&0x3C) >> 2;
      uint16 awb_sd_mode = (control&0xFC) >> 2;
      uint16 samplingrate;

      /* Set Digital Gain for AMR/AMR-WB */
      AFE_SetDigitalGain( L1SP_AUDIO, handle->mh.volume_level );
      if( ((0x03<=amr_sd_mode) && (0x0A>=amr_sd_mode))){ // AMR
         DSP_DynamicDownload( DDID_AMRSBC );
         codec_mode = ASP_TYPE_AMR;
         sc_mode = (vm_control>>2) & 0xF;
         sd_mode = (vm_control>>6) & 0xF;
         samplingrate = ASP_FS_8K;
      }else if ((0x20<=awb_sd_mode) && (0x28>=awb_sd_mode)){  // AWB
          DSP_DynamicDownload(DDID_AWBDEC);
          codec_mode = ASP_TYPE_AWBDEC;
          sc_mode = (vm_control>>2) & 0xFF;
          sd_mode = 0;
          samplingrate = ASP_FS_16K;
      }

      if( sc_mode == 0 )
         sc_mode = sd_mode;
      if( sd_mode == 0 )
         sd_mode = sc_mode;

      *AMR_AWB_AUDIO_PATH_CTRL = 0x40;
      if( sc_mode > 2){
         *AMR_PARAM1 = 0x1622;
      }else{
          *AMR_PARAM1 = 0x2622;
      }
      *AMR_PARAM2 = sd_mode | (sc_mode << 8);
      *DP_AUDIO_FLEXI_CTRL = 0x5;
      AM_AudioPlaybackOn( codec_mode, samplingrate);
   }
#else // AMR_AWB_AUDIO_PATH_SUPPORT
   /* Set Digital Gain for AMR/AMR-WB */
   AFE_SetDigitalGain( L1SP_VOICE, handle->mh.volume_level );
   AM_VMPlaybackOn( wCodecMode, handle->play_style );
#endif

#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
   if( handle->mh.state == AMR_STATE_WB_PLAY ){
      kal_uint32 I;

      *DP_AWB_SD_CTRL = DSP_INITIALIZED;
      for( I = 0; ; I++ ) {
         if( *DP_AWB_SD_CTRL == DSP_PLAYING )                /* DSP returns to idle state */
            break;
         ASSERT_REBOOT( I < 40 );
         kal_sleep_task( 1 );
      }
   }
#endif

#if AMR_AWB_AUDIO_PATH_SUPPORT
   {
      kal_uint32 uCnt;
      for( uCnt = 0; ; uCnt++ ) {
         if( *AMR_AWB_AUDIO_PATH_CTRL == 0 ){
            break;
         }
         ASSERT_REBOOT( uCnt < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif // AMR_AWB_AUDIO_PATH_SUPPORT

}

static void jamrCloseDevice( Media_Handle_Internal *handle, bool wait )
{
#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
   kal_uint32 I;
   if( handle->is_awb && wait ) {
      if(*DP_AWB_SD_CTRL == DSP_PLAYING)
         *DP_AWB_SD_CTRL = DSP_STOP;
      for( I = 0; ; I++ ) {
         if( *DP_AWB_SD_CTRL == DSP_IDLE )                /* DSP returns to idle state */
            break;
         ASSERT_REBOOT( I < 40 );
         kal_sleep_task( 1 );
      }
   }
#endif
   (void)wait;    /* to avoid warning */

#if AMR_AWB_AUDIO_PATH_SUPPORT
   *DP_AUDIO_FLEXI_CTRL = 0;
   AM_AudioPlaybackOff( true );
#else // AMR_AWB_AUDIO_PATH_SUPPORT
   AM_VMPlaybackOff( handle->play_style );
#endif

   L1Audio_UnhookHisrHandler( DP_D2C_SD_DONE );
   L1Audio_ClearFlag( handle->aud_id );
   ktUnlock();
}

static void jamrTask( void *data )
{
   Media_Handle *handle = (Media_Handle *)data;

   handle->handler( handle, (Media_Event)handle->data );
}

static void jamrException( Media_Handle_Internal *handle, Media_Event event ) {
   /* Prevent the message from overwritten in mediaDataRequest */
   handle->mh.data = (uint32)event;
   L1Audio_SetEvent( handle->aud_id, handle );
}

static void jamrEnding( Media_Handle_Internal *handle, Media_Event event )
{
#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
   if( handle->is_awb ) {
      ASSERT_REBOOT(*DP_AWB_SD_CTRL == DSP_PLAYING);
      *DP_AWB_SD_CTRL = DSP_STOP;      /* waiting for DSP to return to DSP_IDLE state */
      handle->end_status = event;
   }
   else 
#endif            
   {
      handle->mh.state = AMR_STATE_READY;
      jamrCloseDevice( handle, KAL_FALSE );
      jamrException( handle, event );
   }
}

static void jamrEndHandler( void *data, Media_Event event)
{
   (void) data;   // to avoid warning 
   jamrEnding( (Media_Handle_Internal *)data, MEDIA_END);
}

static void jamrHisr( void *data )
{
   uint32 I, FT, FQI, txType, bits;
   uint8 *ptr;
   Media_Handle_Internal *handle = (Media_Handle_Internal *)data;

   if( (handle->mh.state & (AMR_STATE_NB_PLAY|AMR_STATE_WB_PLAY )) == 0 )
      return;

#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
   if( handle->is_awb ) {
      switch( *DP_AWB_SD_CTRL )
      {
         case DSP_PLAYING:    break;
         case DSP_STOP:       return;
         case DSP_IDLE:
                  handle->mh.state = AMR_STATE_READY;
                  jamrCloseDevice( handle, KAL_FALSE );
                  jamrException( handle, handle->end_status );
                  return;
         default:
                  ASSERT_REBOOT(KAL_FALSE);
      }
   }
#endif

   if( (handle->mh.current_time > handle->mh.stop_time ) || ( handle->curpos >= handle->endpos ) ) {
      if( handle->repeat_count > 0 ) {
         if( handle->repeat_count == 1 ) {
            handle->repeat_count = 0;
            jamrWriteSpeechMode( handle, handle->bCodecMode, 0 );
#if APM_SUPPORT
            APM_NOTIFY_MEDIA_END( jamrEndHandler, (void *)handle, false , MEDIA_END);
#else
            jamrEnding( handle, MEDIA_END );
#endif
            return;
         }
         else
            handle->repeat_count--;
      }
      handle->curpos = handle->orgpos;
      jamrException( handle, MEDIA_REPEATED );
   }

   /* decode frame header */
   FQI = *handle->curpos++;
   FT = (FQI >> 3) & 0x0F;
   FQI = (FQI >> 2) & 0x01;

#if defined(AMRWB_DECODE)
   if (handle->mh.state == AMR_STATE_WB_PLAY ) {
      /* If the codec mode are not right, DSP may mal-function */
      EXT_ASSERT((((((*DP_SD2_AWB_VM_0)>>8)&0xFF)>=0x20) &&((((*DP_SD2_AWB_VM_0)>>8)&0xFF)<=0x28)), (*DP_SD2_AWB_VM_0), 0, 0);
      if( FT <= 8 ) { /* AMR-WB 6.60 kbps ~ 23.85 kbps */
         txType = 2;
         handle->bCodecMode = FTtoSCM_AMR_WB[FT];
         bits = lenSpeechBitsAMR_WB[FT];
      }
      else if( FT == 9 ) { /* AMR-WB SID */
         txType = 3;
         bits = lenSpeechBitsAMR_WB[FT];
      }
      else if( ( FT == 14 && FQI == 0 ) ||   /* SPEECH_LOST */
               ( FT == 15 && FQI == 1 ) ) {  /* NO_DATA */
         bits = 0;
         txType = 0;
      }
      else { /* 'for-future-use' mode */
         jamrEnding( handle, MEDIA_ERROR );
         return;
      }
   } else
#endif
   {
      /* If the codec mode are not right, DSP may mal-function */
      EXT_ASSERT(((*DP_SD2_VM_17>=0x03) && (*DP_SD2_VM_17<=0x0A)), (*DP_SD2_VM_17), 0, 0);
      if (FT <= 7) { /* AMR 4.75 ~ 12.2 kbps */
         handle->bCodecMode = FTtoSCM_AMR[FT];
         txType = 2;
         bits = lenSpeechBitsAMR[FT];
      }
      else if( FT == 8 ) { /* AMR SID */
         bits = lenSpeechBitsAMR[FT];
         txType = 3;
      }
      else if( FT == 15 && FQI == 1 ) { /* No_Data*/
         bits = 0;
         txType = 0;
      }
      else {
         jamrEnding( handle, MEDIA_ERROR );
         return;
      }
   }

   for( ptr = (uint8*)handle->orderingBuffer, I = (bits+7)/8; I > 0; I-- )
      *ptr++ = *handle->curpos++;

   /* bits re-ordering */
   kal_mem_set( handle->Tx_data_buffer, 0, sizeof(handle->Tx_data_buffer) );
   jamrOrderConvert( handle, txType, FT, handle->orderingBuffer, handle->Tx_data_buffer, bits );

   if( txType == 3 ) { /* SID first or SID update */
      handle->Tx_data_buffer[2] &= 0x00E0;
      if( (handle->orderingBuffer[2]&0x0010) == 0 )   /* STI */
         txType = 1; /* SID first */
   }

   /* write speech frame to sherif */
   jamrWriteSpeechMode( handle, handle->bCodecMode, txType );
   jamrWriteSpeechData( handle, handle->Tx_data_buffer, (bits+15)/16 );
   handle->mh.current_time += 20;      /* increase current time by 20ms */
}

Media_Handle *JAmr_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_AMR_Param **param )
{
   Media_Handle_Internal *handle;

   handle = (Media_Handle_Internal*)get_ctrl_buffer( sizeof(Media_Handle_Internal) );
   handle->mh.handler      = handler;
   handle->mh.start_time   = 0;
   handle->mh.stop_time    = 0x7FFFFFFF;
   handle->mh.volume_level = 100;
   handle->mh.state        = AMR_STATE_READY;
   handle->aud_id          = L1Audio_GetAudioID();
   handle->param.amrfile   = 0;
   *param = &handle->param;
   L1Audio_SetEventHandler( handle->aud_id, jamrTask );
   return (Media_Handle*)handle;
}

Media_Status JAmr_Close( Media_Handle *handle )
{
   ASSERT( handle != 0 && handle->state == AMR_STATE_READY );
   L1Audio_FreeAudioID( ((Media_Handle_Internal *)handle)->aud_id );
   free_ctrl_buffer( handle );
   return MEDIA_SUCCESS;
}

Media_Status JAmr_Play( Media_Handle *hdl )
{
   uint16 wCodecMode;
   Media_Handle_Internal *handle = (Media_Handle_Internal *)hdl;
   const uint8 *amrfile = handle->param.amrfile;

   ASSERT( amrfile != 0 );
   handle->endpos = amrfile + handle->param.filesize;
   handle->repeat_count = handle->param.repeats;
   hdl->current_time = 0;

#if defined(AMRWB_DECODE)
   if( memcmp( amrfile, "#!AMR-WB\n", 9) == 0 ) {

#if !AMR_AWB_AUDIO_PATH_SUPPORT
#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
      DSP_DynamicDownload( DDID_AWB );
#endif
#endif
      handle->orgpos = amrfile + 9;
      handle->bCodecMode = 0x20;
      wCodecMode = (0x20<<2);
      handle->play_style = (uint8)((uint32)MEDIA_VMP_AMR_WB | (uint32)MEDIA_VMP_AS_RINGTONE);
      /* go to the start position */
      while( hdl->current_time < hdl->start_time ) {
         if( jamrwbPass20ms( &handle->orgpos, handle->endpos ) )
            return MEDIA_FAIL;
         hdl->current_time += 20;
      }
      handle->mh.state = AMR_STATE_WB_PLAY;
      handle->is_awb = KAL_TRUE;
   } else
#endif
   if( memcmp( amrfile, "#!AMR\n", 6) == 0 ) {
      handle->orgpos = amrfile + 6;
      handle->bCodecMode = 0x03;
      wCodecMode = (0x03<<2) | (0x03<<6);
      handle->play_style = (uint8)((uint32)MEDIA_VMP_AMR | (uint32)MEDIA_VMP_AS_RINGTONE);
      /* go to the start position */
      while( hdl->current_time < hdl->start_time ) {
         if( jamrPass20ms( &handle->orgpos, handle->endpos ) )
            return MEDIA_FAIL;
         hdl->current_time += 20;
      }
      handle->mh.state = AMR_STATE_NB_PLAY;
      handle->is_awb = KAL_FALSE;
   }
   else {
      return MEDIA_BAD_FORMAT;
   }

   handle->curpos = handle->orgpos;
   /* write 'No-Data' speech frame to dsp */
   jamrWriteSpeechMode( handle, handle->bCodecMode, 0);

   jamrOpenDevice( handle, wCodecMode );

   return MEDIA_SUCCESS;
}

Media_Status JAmr_Stop( Media_Handle *hdl )
{
   Media_Handle_Internal *handle = (Media_Handle_Internal *)hdl;
   uint32 savedMask;

   if( hdl->state & (AMR_STATE_NB_PAUSED|AMR_STATE_WB_PAUSED|AMR_STATE_READY) ) {
      hdl->state = AMR_STATE_READY;
      return MEDIA_SUCCESS;
   }
   savedMask = SaveAndSetIRQMask();
   if( hdl->state & (AMR_STATE_NB_PLAY|AMR_STATE_WB_PLAY) ) {
      hdl->state = AMR_STATE_READY;    /* Changing state before closing device is to block HISR entry */
      RestoreIRQMask( savedMask );
      jamrCloseDevice( handle, KAL_TRUE );
   }
   else
      RestoreIRQMask( savedMask );
   
   return MEDIA_SUCCESS;
}

Media_Status JAmr_Pause( Media_Handle *hdl )
{
   Media_Handle_Internal *handle = (Media_Handle_Internal *)hdl;
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   if( !(hdl->state & (AMR_STATE_NB_PLAY|AMR_STATE_WB_PLAY)) ) {
      RestoreIRQMask( savedMask );
      return MEDIA_FAIL;
   }
   if( hdl->state == AMR_STATE_NB_PLAY )
      hdl->state = AMR_STATE_NB_PAUSED;
   else
      hdl->state = AMR_STATE_WB_PAUSED;
   RestoreIRQMask( savedMask );
   jamrCloseDevice( handle, KAL_TRUE );
   return MEDIA_SUCCESS;
}

Media_Status JAmr_Resume( Media_Handle *hdl )
{
   uint16 wCodecMode;
   Media_Handle_Internal *handle = (Media_Handle_Internal *)hdl;

   if( (hdl->state & (AMR_STATE_NB_PAUSED|AMR_STATE_WB_PAUSED)) == 0 )
      return MEDIA_FAIL;

#if defined(AMRWB_DECODE)
   if( hdl->state & AMR_STATE_WB_PAUSED ) {
      handle->bCodecMode = 0x20;
      wCodecMode = (0x20<<2);
      hdl->state = AMR_STATE_WB_PLAY;
   } else
#endif
   {
      handle->bCodecMode = 0x03;
      wCodecMode = (0x03<<2) | (0x03<<6);
      hdl->state = AMR_STATE_NB_PLAY;
   }

   /* write 'No-Data' speech frame to dsp */
   jamrWriteSpeechMode( handle, handle->bCodecMode, 0 );

   jamrOpenDevice( handle, wCodecMode );

   return MEDIA_SUCCESS;
}

Media_Status JAmr_SetStartTime( Media_Handle *hdl, kal_int32 msStartTime )
{
   ASSERT( hdl->state == AMR_STATE_READY );
   hdl->current_time = hdl->start_time = msStartTime;
   return MEDIA_SUCCESS;
}

Media_Status JAmr_SetStopTime( Media_Handle *hdl, kal_int32 msStopTime )
{
   hdl->stop_time = msStopTime;
   return MEDIA_SUCCESS;
}

kal_int32 JAmr_GetCurrentTime( Media_Handle *hdl )
{
   return hdl->current_time;
}

Media_Status JAmr_SetLevel( Media_Handle *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   hdl->volume_level = level;
#if AMR_AWB_AUDIO_PATH_SUPPORT
   /* Set Digital Gain for AMR/AMR-WB */
   AFE_SetDigitalGain( L1SP_AUDIO, level );
#else // AMR_AWB_AUDIO_PATH_SUPPORT
   /* Set Digital Gain for AMR/AMR-WB */
   AFE_SetDigitalGain( L1SP_VOICE, level );
#endif
   return MEDIA_SUCCESS;
}

kal_uint8 JAmr_GetLevel( Media_Handle *hdl )
{
   return hdl->volume_level;
}

Media_Status JAmr_GetDuration( const uint8 *amrfile, int32 amrsize, int32 *duration )
{
   int32 retval;
   const uint8 *endpos = amrfile + amrsize;
#if defined(AMRWB_DECODE)
   if( memcmp( amrfile, "#!AMR-WB\n", 9) == 0 ) {
      amrfile += 9;
      while( (retval = jamrwbPass20ms( &amrfile, endpos )) == 0 )
         *duration += 20;
      if( retval == 2 ) /* error */
         return MEDIA_FAIL;
   } else
#endif
   if( memcmp( amrfile, "#!AMR\n", 6) == 0 ) {
      amrfile += 6;
      while( (retval = jamrPass20ms( &amrfile, endpos )) == 0 )
         *duration += 20;
      if( retval == 2 ) /* error */
         return MEDIA_FAIL;
   }
   else {
      return MEDIA_BAD_FORMAT;
   }
   return MEDIA_SUCCESS;
}

#endif   // IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION


