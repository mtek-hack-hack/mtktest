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
 *   kt_Detect.c
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   Key tone (DTMF) detection in dedicated mode
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "tonedect.h"
#if !defined(MT6205B)

#define  FRAME_BUF_NO            2
#define  FRAME_BUF_MASK          (FRAME_BUF_NO-1)
#define  FRAME_BUF_SIZE          160
#define  DTMF_FRAME_SIZE         106

#define  IDLE_STATE              0
#define  SPEECH_STATE            1
#define  VOIP_STATE              2

//#define KT_DETECT_DEBUG
#ifdef KT_DETECT_DEBUG
#include "fat_fs.h"  /* file system */
   static kal_wchar debugFile[50]; 
   static uint16 ktDDPcmDebugBuf[80000]; // for debug 
   static uint16 *pcmDebugPtr; // for debug 
   static uint32 pcmDebugCnt;
#endif

static struct{
   int16          *rb_base;
   uint16         aud_id;
   uint8          tmp_r;
   uint8          tmp_w;
   DTMF_Handle    *hdl;
   void           (*Callback)( int16 key );
   uint16         state;
} kt_detect;

static void ktDetectDedi( void *data )
{
   int16 result;
   int16 *buf;
   int32 acumBufSize, len, consumedLen;
   while ( (uint8)(kt_detect.tmp_w - kt_detect.tmp_r) > 0){
      buf = (int16 *)(kt_detect.rb_base + ((kt_detect.tmp_r&FRAME_BUF_MASK) * FRAME_BUF_SIZE));
      acumBufSize = 0; len = FRAME_BUF_SIZE; consumedLen = 0;
      while ( acumBufSize < FRAME_BUF_SIZE ){       //not being comsumed to end
         consumedLen = kt_detect.hdl->PutData( kt_detect.hdl, buf+acumBufSize, len);
         len -= consumedLen;
         acumBufSize += consumedLen;
         result = kt_detect.hdl->GetKey( kt_detect.hdl );
         if( result != 0 ) {
            //kal_prompt_trace( MOD_L1SP, "DTMF =%c, threshold=%d\n", (char)result, kt_detect.hdl->key_threshold );
            kt_detect.Callback( result );
         }
      }
      ASSERT(acumBufSize == FRAME_BUF_SIZE);
      kt_detect.tmp_r++;
#ifdef KT_DETECT_DEBUG
{
      uint32 I;
      for( I = 0; I < FRAME_BUF_SIZE; I++ ) {
         if( pcmDebugCnt < 80000 )
         {
            *pcmDebugPtr++ = buf[I];
            pcmDebugCnt ++;
         }
      }
}
#endif
   }
}


static void ktDetectDediHisr( void *data )
{
   int32 first_data_block_len, second_data_block_len;
   int32 I, tmp;
   int16 *buf;
   
   //ASSERT( *DP_TCH_DL_LEN == FRAME_BUF_SIZE );   /* frame size */

   if( (uint8)(kt_detect.tmp_w - kt_detect.tmp_r) >= FRAME_BUF_NO )//insure no overflow
      return;

   first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
   if( first_data_block_len < FRAME_BUF_SIZE )
      second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
   else {
      first_data_block_len = FRAME_BUF_SIZE;
      second_data_block_len = 0;
   }
   
   buf = (int16 *)(kt_detect.rb_base + (kt_detect.tmp_w&FRAME_BUF_MASK) * FRAME_BUF_SIZE );
   tmp = *DSP_DM_ADDR(2, *DP_TCH_DL_PTR);  /* Read downlink data */
   for ( I = first_data_block_len; I > 0; I-- )
      *buf++ = (int16)(*IDMA_SHORT_ADDR);
   if( (I = second_data_block_len) > 0 ){
      tmp = *DSP_DM_ADDR(2, *DP_TCH_DL_BUF_ADDR0);
      for ( ; I > 0 ;I-- )
         *buf++ = (int16)(*IDMA_SHORT_ADDR);
   }
   kt_detect.tmp_w++;
   L1Audio_SetEvent(kt_detect.aud_id, (void *) 0);
}

#if VORTP_SUPPORT
void KtDetectInVoIP( void *data )
{
   uint32 i;
   int16 *src, *buf;
   buf = (int16 *)(kt_detect.rb_base + (kt_detect.tmp_w&FRAME_BUF_MASK) * FRAME_BUF_SIZE );
   src = (int16 *)data;
   for( i = FRAME_BUF_SIZE ; i > 0 ; i-- )
      *buf++ = *src++;
   kt_detect.tmp_w++;
   ktDetectDedi( 0 );
}
#endif

void KtDetectStart(void (*callback)(int16 key))
{
   ASSERT( AM_IsSpeechOn() || AM_IsVoIPOn() );
   kt_detect.state = ( AM_IsSpeechOn() ? SPEECH_STATE : VOIP_STATE );
#ifdef KT_DETECT_DEBUG
   pcmDebugCnt = 0;
   pcmDebugPtr = ktDDPcmDebugBuf;
#endif

   kt_detect.rb_base = (int16 *)get_ctrl_buffer( (FRAME_BUF_SIZE * FRAME_BUF_NO) <<1);
   kt_detect.Callback = callback;
   
   kt_detect.hdl = DTMF_Open( DTMF_FRAME_SIZE, 2 );
   kt_detect.tmp_r = 0;
   kt_detect.tmp_w = 0;

#if VORTP_SUPPORT
   if( kt_detect.state == VOIP_STATE ){
      VMI_HookPostHandler( KtDetectInVoIP );
   } else 
#endif
   {//speech state
      kt_detect.aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler(kt_detect.aud_id, ktDetectDedi);
      L1Audio_HookHisrHandler(DP_D2C_PCM_TCH_R, ktDetectDediHisr, 0);
      AM_PCM8K_RecordOn();
   }
   kal_prompt_trace( MOD_L1SP, "ktDetectStarted");
}

void KtDetectStop( void )
{
#if VORTP_SUPPORT
   if( kt_detect.state == VOIP_STATE ){
      VMI_UnhookPostHandler();
   } else
#endif
   {
      /*stop pcm record*/
      uint16 I, ctl;
      for( I = 0; ; I++ ) {
         ctl = *DSP_PCM_REC_CTRL;
         if( ctl == 0 )                /* DSP returns to idle state */
            break;
         if( ctl == 0x400 )
            *DSP_PCM_REC_CTRL = 0x800;  /* give ABORT command to the DSP */
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
      AM_PCM8K_RecordOff( true );
      L1Audio_UnhookHisrHandler(DP_D2C_PCM_TCH_R); 
      L1Audio_FreeAudioID( kt_detect.aud_id );
   }
   kt_detect.hdl->Close(kt_detect.hdl);
   free_ctrl_buffer( kt_detect.rb_base );
   
   kt_detect.state = IDLE_STATE;
   kal_prompt_trace( MOD_L1SP, "ktDetectStoped");
#ifdef KT_DETECT_DEBUG 
{
      int file_handle;
      kal_prompt_trace(MOD_L1SP, "prepare to dump pcm file");
      kal_wsprintf(debugFile, "C:\\KTDDdebug.pcm");
      file_handle = FS_Open(debugFile, FS_CREATE);
      if(file_handle > 0) 
      { 
         FS_Write( file_handle, (void *)ktDDPcmDebugBuf, pcmDebugCnt << 1, NULL );
         FS_Close(file_handle);
      }
      kal_prompt_trace(MOD_L1SP, "finish dump pcm file");
}
#endif   
}

#endif