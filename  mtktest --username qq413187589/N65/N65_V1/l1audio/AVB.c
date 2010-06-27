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
 *   AVB.c
 *
 * Project:
 * --------
 *   MAUI (currently support MT6228/MT6229/MT6225)
 *
 * Description:
 * ------------
 *   Audio Playback Via Bluetooth SCO link Function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "l1audio_def.h"
#include "resample.h"
#include "am.h"

#if defined( __BT_AUDIO_VIA_SCO__ )

struct {
   kal_uint32       sampleFreq;
   Resample_Handle  *downsampler;
   kal_uint32       *tcmPtr;
   kal_uint32       tcmLen;
   kal_uint32       buffered;//0: not buffered; 1,2:buffered but not delayed; 3: buffered and delayed to avoid initial discontinuity
   bool             enable;
   bool             isStereo;
   bool             flushing;
   bool             isEOF;
   bool             isChange;
}AVB = {8000, NULL, NULL, 0, 0, false, false, false, false, false};

void avb_HisrHandler(void *data)
{
   uint16 ptr_addr;
   int16 *dspPtr;
   uint32 outputNum,i;
   
   if (AVB.enable == false)
      return;

   if( DSP_TONE_CTRL2 != 0 || DSP_TONE_CTRL1 != 0 ){
      AVB.downsampler->GetSamples( AVB.downsampler, NULL, 160, false, true );
      kal_prompt_trace( MOD_L1SPHISR, "KT1=%x,KT2=%x",DSP_TONE_CTRL1,DSP_TONE_CTRL2);
   }
   else
   {
      ptr_addr = *DSP_DM_ADDR(BT_AUDIO_PLAYBACK_SD_PAGE_NUM, BT_AUDIO_PLAYBACK_SD_PTR_ADDR);
      ASSERT( ptr_addr >= BT_AUDIO_PLAYBACK_SD_ADDR && 
         ptr_addr < (BT_AUDIO_PLAYBACK_SD_ADDR + BT_AUDIO_PLAYBACK_SD_BUF_LEN) );

      dspPtr = (int16 *)DSP_DM_ADDR(BT_AUDIO_PLAYBACK_SD_PAGE_NUM, ptr_addr);
      outputNum = AVB.downsampler->GetOutputNum(AVB.downsampler);
      kal_prompt_trace( MOD_L1SPHISR, "AVB outNum =%d,Put2DSPAddr=%x", outputNum, ptr_addr);
      if ( AVB.buffered < 3 && outputNum >= 1024 ){    // avoid initial discontinuity
         AVB.buffered++;
      }
      if( outputNum > 160 && AVB.buffered > 2 )
         AVB.downsampler->GetSamples( AVB.downsampler, dspPtr, 160, false, false );
      else if ( AVB.flushing ){ 
         if (outputNum >= 160){
            AVB.downsampler->GetSamples( AVB.downsampler, dspPtr, 160, false, false );
            kal_prompt_trace( MOD_L1SPHISR, "AVB Flushing");
         }
         else{
            AVB.downsampler->GetSamples( AVB.downsampler, dspPtr, outputNum, false, false );
            dspPtr += outputNum;
            for( i = outputNum ; i < 160 ; i++ )
               *dspPtr++ = 0;
            kal_prompt_trace( MOD_L1SPHISR, "AVB Flushed");
         }
      }
      else {
         for( i = 160 ; i > 0 ; i-- )
            *dspPtr++ = 0;
         kal_prompt_trace( MOD_L1SPHISR, "AVB fill Silence,outBuf=%d",outputNum);
      }
      
      //get other samples to DSP via DSP
      //dspPtr = (int16 *)IDMA_SHORT_ADDR;
      //AVB.downsampler->GetSamples(AVB.downsampler, dspPtr, 159, true, false);
   }
} 
void avb_Init(APM_TCM *tcm)
{
   AVB.tcmPtr = tcm->tcmBuf;
   AVB.tcmLen = tcm->tcmBufLen;
   kal_prompt_trace( MOD_L1SP, "AVBInit TCM buf=%x,len=%d", AVB.tcmPtr, AVB.tcmLen);
}

kal_bool avb_Process(APM_Buffer *buf, APM_Info *info)
{
   int32 count=0;
   uint32 inLen, ret;
   
   //buf->outBufLen = buf->inBufLen;//could be removed since AVBT is read only process
   inLen = buf->inBufLen;

   if( !AVB.enable )
      return false;
   
   if( info->isChange ){
      AVB.sampleFreq = info->sampleFreq;
      AVB.isStereo   = info->isStereo;
      AVB.downsampler->Init( AVB.downsampler, AVB.sampleFreq, 8000, AVB.isStereo);
      kal_prompt_trace( MOD_L1SP, "AvbInitRes FS=%d,St=%d", AVB.sampleFreq, AVB.isStereo);
   }
   while ( count < inLen && !AVB.isEOF){
      ret = AVB.downsampler->PutSamples( AVB.downsampler, buf->inBuf + count, inLen-count );
      if ( ret == 0 ){
         kal_prompt_trace(MOD_L1SP, "AVB OVFLOW");
         break;
      }
      count += ret;
      if( AVB.downsampler->IsReady(AVB.downsampler) )
         AVB.downsampler->Convert(AVB.downsampler);
      else
         break;
   }

   if( info->isEOF ){
      AVB.isEOF = true;
      AVB.flushing = true;
      if( AVB.downsampler->GetOutputNum(AVB.downsampler) > 0 )
         return false; //not flsuhing all
      else
         return true;  //buffer flushed, tell APM that close procedure can be continued
   }
   else
      return true;
}


/*Runs under task level*/
void avb_Activate(APM_Info *info)
{
   if (AVB.enable == true)
      return;
   AVB.sampleFreq = info->sampleFreq;
   AVB.isStereo   = info->isStereo;

   if ( AVB.downsampler == NULL ){       //the case that in TCM or first time called
      AVB.downsampler = (Resample_Handle *)Resample_Open(AVB.tcmPtr, AVB.tcmLen);
      if (AM_IsAudioPlaybackOn() != -1){
         AVB.downsampler->Init( AVB.downsampler, AVB.sampleFreq, 8000, AVB.isStereo);
         kal_prompt_trace( MOD_L1SP, "AvbInitRes FS=%d,St=%d", AVB.sampleFreq, AVB.isStereo);
      }
   }
   else                                 //the case that not in TCM and didn't release
      AVB.downsampler->Reset(AVB.downsampler);
   L1Audio_HookHisrHandler( D2C_AUDIO_VIA_8KBT_ID, avb_HisrHandler, 0);
   AVB.buffered = 0;
   AVB.flushing = false;
   AVB.enable   = true;
   AVB.isEOF    = false;
   AVB.isChange = false;
   kal_prompt_trace( MOD_L1SP, "AVB Opened");
}

/* Runs under task level     */
void avb_Deactivate()
{
   if (AVB.enable == false)
      return;

   AVB.enable = false;
   L1Audio_UnhookHisrHandler(D2C_AUDIO_VIA_8KBT_ID);
   
   AVB.downsampler->Close(AVB.downsampler);
   AVB.downsampler = NULL;
   
   kal_prompt_trace( MOD_L1SP, "AVB Closed");
}

#endif// endif __BT_AUDIO_VIA_SCO__
