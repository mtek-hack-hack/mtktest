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
 * tone_loopback_rec.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Tone Loop Back Recording
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "tone_loopback_rec.h"

#if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217))

static struct{
   void (*callback)( kal_uint8 *pBuf );
   kal_uint32  uState;
   kal_uint32  uSize;
   kal_uint32  uDataCnt;
   kal_uint8   *pBuf;
   kal_uint16  aud_id;
} ToneLBR; // ToneLoopBackRec

void toneLoopbackRecInit( void )
{
   memset(&ToneLBR, 0, sizeof(ToneLBR));
   ToneLBR.aud_id   = 0xFFFF;
}

static void toneLoopbackRecHandler( void *data )
{
#ifndef __L1_STANDALONE__ // avoid link error
   ASSERT(ToneLBR.uState == TLBR_STATE_REC);
   ToneLBR.uState = TLBR_STATE_IDLE;

   // De-activate 2-way PCM
   PCM2WAY_Stop(1);

   KT_Stop();
   ToneLBR.callback(ToneLBR.pBuf);
   AFE_EnableToneLoopBackFlag( KAL_FALSE );

   L1Audio_FreeAudioID( ToneLBR.aud_id );
   memset(&ToneLBR, 0, sizeof(ToneLBR));
   ToneLBR.aud_id    = 0xFFFF;
   aud_set_aud_path_volume(aud_context_p->audio_mode); // restore audio setting
   *DP_VOL_IN_PCM  = DG_Microphone;
   *DP_VOL_OUT_PCM = DG_DL_Speech;
   AM_EnableToneLoopBackFlag( KAL_FALSE );
#endif // #ifndef __L1_STANDALONE__
}

static void toneLoopBackRecHisr( void )
{
#ifndef __L1_STANDALONE__ // avoid link error
   if(ToneLBR.uState == TLBR_STATE_IDLE)
      return;
      
   if(ToneLBR.uState == TLBR_STATE_INIT){ // skip 1'st frame
      ToneLBR.uState = TLBR_STATE_REC;
      return;
   }

   if(ToneLBR.uDataCnt < ToneLBR.uSize) {
      // fill data
      PCM2WAY_GetFromMic((kal_uint16 *)(ToneLBR.pBuf + ToneLBR.uDataCnt));
      ToneLBR.uDataCnt += BYTES_PER_FRAME;
   }else {
      // buffer is full
      L1Audio_SetEvent( ToneLBR.aud_id, (void *)0 );
   }
#endif // #ifndef __L1_STANDALONE__
}

void ToneLoopBackRec(void(*callback)( kal_uint8 *pBuf ), ToneLBR_Para *pstPara )
{
#ifndef __L1_STANDALONE__ // avoid link error
   ASSERT(ToneLBR.uState == TLBR_STATE_IDLE);
   ASSERT(0xFFFF == ToneLBR.aud_id);

   ToneLBR.aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ToneLBR.aud_id, toneLoopbackRecHandler );

   ToneLBR.callback = callback;
   ToneLBR.uState   = TLBR_STATE_INIT;
   ToneLBR.uSize    = pstPara->uSize - (pstPara->uSize%BYTES_PER_FRAME);
   ToneLBR.pBuf     = pstPara->pBuf;

   AFE_EnableToneLoopBackFlag( KAL_TRUE );
   AM_EnableToneLoopBackFlag( KAL_TRUE );
   KT_SetOutputDevice( L1SP_LOUD_SPEAKER );
   KT_SetOutputVolume( pstPara->bAnalogSpkGain, 0 );
   KT_Play( pstPara->uFreq, pstPara->uFreq, 0 );
   KT_SetAmplitude( pstPara->uKT_AMP );

   kal_sleep_task(30); // to ensure tone is stable

// Activate 2-way PCM
   *DP_VOL_IN_PCM = pstPara->uUL_DigGain; // uplink digital gain
   *DP_VOL_OUT_PCM = pstPara->uDL_DigGain;

   AFE_MuteMicrophone(0); // un-mute microphone

   L1SP_SetMicrophoneVolume( pstPara->uAnalogMicGain );
   PCM2WAY_Start( toneLoopBackRecHisr, 1 ); // voice
#endif // #ifndef __L1_STANDALONE__
}

#endif // #if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217))
