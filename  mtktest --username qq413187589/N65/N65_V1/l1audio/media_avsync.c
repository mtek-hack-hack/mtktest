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
 * media_avsync.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   A/V Sync Interface
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


/*
 * Note: A/V Sync DSP/MCU Interface exists since MT6219.
 */

#ifndef WIN32

#include "kal_release.h"
#include "media.h"

#else

#include <stdio.h>
#include <assert.h>
#include <string.h>
#define ASSERT(x) assert(x)
#define kal_mem_cpy(a,b,c) memcpy(a,b,c)
#include "kal_non_specific_general_types.h"
#include "l1audio.h"

kal_uint16 a2v_int_cnt;
kal_uint16 a2v_int_enable;
kal_uint16 a2v_int_stamp;
kal_uint16 share_d2mcon;
kal_uint16 a2v_audio_frame_count;
kal_uint16 a2v_video_frame_count;
#define A2V_INT_CNT (&a2v_int_cnt)
#define A2V_INT_ENABLE (&a2v_int_enable)
#define A2V_INT_STAMP (&a2v_int_stamp)
#define SHARE_D2MCON (&share_d2mcon)
#define A2V_AUDIO_FRAME_COUNT (&a2v_audio_frame_count)
#define A2V_VIDEO_FRAME_COUNT (&a2v_video_frame_count)
#define DSP_ENA_AVSYNC_INTERRUPT 0x0020
#define kal_sleep_task

#endif /* UNIT_TEST_ON_WIN32 */



#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)

#define AVSYNC_CHECK_REENTRY 0

#define AVSYNC_STATE_IDLE 0
#define AVSYNC_STATE_INITIAL 3
#define AVSYNC_STATE_RUNNING 1
#define AVSYNC_STATE_STOP 5

struct {
   /// audio interrupt counts, 32-bit
   kal_uint32 uInterruptCount;
   /// audio interrupt count maintained in DSP, 16-bit
   kal_uint16 wDSPCount_Prev;
   /// call-back function when a/v interrupt occurs
   void (*a2v_lisr_callback)(void);
#if VERIFY_AVSYNC
   /// previous audio interrupt counts, 32-bit
   kal_uint32 uPrevInterruptCount;
#endif
} media_a2v;



void media_a2v_increment_interrupt_count(void)
{
   kal_uint16 wDSPCount_Cur;

   wDSPCount_Cur = *A2V_INT_CNT;

   if (wDSPCount_Cur < media_a2v.wDSPCount_Prev) { /* need a carry */
      /* dsp counts to 0x7FFF and return to 0 */
      media_a2v.uInterruptCount += ( (kal_uint32)(wDSPCount_Cur + 0x8000) - media_a2v.wDSPCount_Prev);
   } else {
      media_a2v.uInterruptCount += (wDSPCount_Cur - media_a2v.wDSPCount_Prev);
   }

   media_a2v.wDSPCount_Prev = wDSPCount_Cur;
}

kal_uint32 Media_A2V_GetInterruptCount(void)
{
   if( *A2V_INT_ENABLE != AVSYNC_STATE_RUNNING )
      return 0;
   media_a2v_increment_interrupt_count();
   return media_a2v.uInterruptCount;
}

/***
 * Set A2V_INT_ENABLE to transit state to AVSYNC_STATE_RUNNING
 * Do this before turning on VBI interrupt.
 */
void media_a2v_start_dsp(void)
{
   //*SHARE_D2MCON |= DSP_ENA_AVSYNC_INTERRUPT;

   //if (AVSYNC_STATE_IDLE == *A2V_INT_ENABLE) {
      *A2V_INT_ENABLE = AVSYNC_STATE_INITIAL;
      /* DSP will see A2V_INT_ENABLE change in its audio/speech interrupt handler,
         and then do some initialization and set A2V_INT_ENABLE to RUNNING */
      //kal_sleep_task(2);
   //}

   /* Make sure DSP set A2V_INT_ENABLE to RUNNING state within certain time */
   //ASSERT(AVSYNC_STATE_RUNNING == *A2V_INT_ENABLE);
}

/***
 * Set A2V_INT_ENABLE to transit state to AVSYNC_STATE_IDLE
 * Do this after turning off VBI interrupt.
 */
void media_a2v_stop_dsp(void)
{
   //*SHARE_D2MCON &= ~DSP_ENA_AVSYNC_INTERRUPT;

   //if (AVSYNC_STATE_RUNNING == *A2V_INT_ENABLE) {
      *A2V_INT_ENABLE = AVSYNC_STATE_STOP;
      //kal_sleep_task(2);
   //}

   /* Make sure DSP set A2V_INT_ENABLE to IDLE state within certain time */
   //ASSERT(AVSYNC_STATE_IDLE == *A2V_INT_ENABLE);
}

/***
 * Enable or disable A2V interrupt.
 */
void Media_A2V_EnableInterrupt(kal_bool bFlag, kal_uint32 start_count)
{
   if (KAL_TRUE==bFlag) {
      media_a2v.uInterruptCount = start_count;
#if VERIFY_AVSYNC
      media_a2v.uPrevInterruptCount = start_count;
#endif
      media_a2v.wDSPCount_Prev = 0;
      /* Do a  stop first in order to make sure DSP initialize A2V related registers */
      media_a2v_stop_dsp();
      *A2V_INT_CNT = 0;
      media_a2v_start_dsp();
   } else if (KAL_FALSE==bFlag) {
      media_a2v_stop_dsp();
   } else {
      ASSERT(KAL_FALSE);
   }
}

/***
 * For MPEG4 encoding: set the interrupt count to the previous paused point to resume encoding
 */
void Media_A2V_SetInterruptCount(kal_uint32 uInterruptCount)
{
   media_a2v.uInterruptCount = uInterruptCount;
}

/***
 * Set the time stamp for displaying the next video frame to DSP.
 */
void Media_A2V_HookInterrupt(void (*a2v_lisr)(void))
{
   media_a2v.a2v_lisr_callback = a2v_lisr;
}

/***
 * Set the time stamp for displaying the next video frame to DSP.
 */
void Media_A2V_SetTimeStamp(kal_uint16 wTimeStamp)
{
   *A2V_INT_STAMP = wTimeStamp;
}

/***
 * Get the number of decoded audio frame from DSP
 */
kal_uint16 Media_A2V_GetAudioFrameCount(void)
{
   return *A2V_AUDIO_FRAME_COUNT;
}

/***
 * Get the number of D2M interrupts for displaying a video frame
 */
kal_uint16 Media_A2V_GetVideoFrameCount(void)
{
   return *A2V_VIDEO_FRAME_COUNT;
}

extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPIO_InitIO(char direction, char port);
extern void GPIO_WriteIO(char data,char port);
#define GPIO_AVSYNC 6

/***
 * This function will be called from L1SP_D2C_LISR in l1sp.c when a/v sync interrupt occurs
 */
void Media_A2V_LISR(void)
{
#if AVSYNC_CHECK_REENTRY
   static kal_uint32 uReentry = 0;

	//GPIO_ModeSetup(GPIO_AVSYNC, 0);
	//GPIO_InitIO(1, GPIO_AVSYNC);
	//GPIO_WriteIO(1, GPIO_AVSYNC);

   ASSERT(uReentry==0);
   if (uReentry!=0)
      return;
   uReentry = 1;
#endif

   if (media_a2v.a2v_lisr_callback!=NULL)
      media_a2v.a2v_lisr_callback();
   media_a2v_increment_interrupt_count();

#if VERIFY_AVSYNC
   /* check timing correctness */
   {
      if (media_a2v.uPrevInterruptCount > 0) {
         kal_uint32 uDeltaInterruptCount = media_a2v.uInterruptCount - media_a2v.uPrevInterruptCount;
         kal_uint32 uTargetInterruptCount = (*A2V_INT_STAMP);
         kal_uint32 uDiff = uDeltaInterruptCount > uTargetInterruptCount ?
            uDeltaInterruptCount - uTargetInterruptCount : uTargetInterruptCount - uDeltaInterruptCount;
         if (uDiff*10 > uTargetInterruptCount) {
            EXT_ASSERT(KAL_FALSE, uDeltaInterruptCount, uTargetInterruptCount, uDiff);
         }
      }
      media_a2v.uPrevInterruptCount = media_a2v.uInterruptCount;
   }
#endif

#if AVSYNC_CHECK_REENTRY
   uReentry = 0;
   //GPIO_WriteIO(0, GPIO_AVSYNC);
#endif
}

/*
 * bSamplingFreqIndex: The one defined in 14496-3.
 */
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_WB:
#if AMR_AWB_AUDIO_PATH_SUPPORT
         return 5333;
#else
         return 8000;
#endif
      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_AAC:
         switch( bSamplingFreqIndex ) {
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
#endif
            case 0x03:
            case 0x06:
            case 0x09:
               return 8000; /* 48000/6 */
            case 0x04:
            case 0x07:
            case 0x0a:
               return 7350; /* 44100/6 */
            case 0x05:
            case 0x08:
            case 0x0b:
               return 5333; /* 32000/6 */

            default:
               return 0;
         }
         break;
      default:
         return 0;
   }
   return 0;
}

kal_uint32 Media_A2V_GetRecInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_WB:
         return 8000;

      default:
         return 0;
   }
   return 0;
}

kal_uint32 Media_A2V_GetRecInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_WB:
         return 8192000;

      default:
         return 0;
   }
   return 0;
}

/*
 * Fixed-point version of Media_A2V_GetAudioInterruptTimeScale.
 * The fraction part is 10 bits
 */
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_WB:
#if AMR_AWB_AUDIO_PATH_SUPPORT
         return 5461333;
#else
         return 8192000;
#endif

      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_AAC:
         switch( bSamplingFreqIndex ) {
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
#endif
            case 0x03:
            case 0x06:
            case 0x09:
               return 8192000; /* 48000/6 */
            case 0x04:
            case 0x07:
            case 0x0a:
               return 7526400; /* 44100/6 */
            case 0x05:
            case 0x08:
            case 0x0b:
               return 5461333; /* 32000/6 */

            default:
               return 0;
         }
         break;
      default:
         return 0;
   }
   return 0;
}

/*
 * This function returns the inherent delay time between the time DSP starts to count
 * audio interrupt and the time the first audio sample is sent to DAC.
 *
 * The return value is in unit of audio interrupt time scale.
 *
 * Refer to am.c to sync the value of DP_DEL_PCM_W, DP_MARGIN_PCM_W, DP_ASP_DEL_W, DP_ASP_DEL_M.
 */
kal_uint32 Media_A2V_GetAudioPlaybackDelay(Media_Format eFormat)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
         return 0x20 + 0x96;
      case MEDIA_FORMAT_AMR_WB:
         return 0x20 + 0x96;
      case MEDIA_FORMAT_AAC:
         return 0x20 + (2040/2)/6;
      case MEDIA_FORMAT_DAF:
         return 0x20 + (1152/2)/6;
      default:
         ASSERT(KAL_FALSE);
   }
   return 0;
}

/*
 * This function returns the inherent delay time between the time DSP starts to count
 * audio interrupt and the time the first audio sample is received from ADC.
 *
 * The return value is in unit of audio interrupt time scale.
 *
 * Refer to am.c to sync the value of DP_DEL_PCM_R.
 */
kal_uint32 Media_A2V_GetAudioRecordDelay(Media_Format eFormat)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
         return 0x20 + 160;
      case MEDIA_FORMAT_AMR_WB:
         return 0x20 + 160;
      default:
         ASSERT(KAL_FALSE);
   }
   return 0;
}

/***
 * Verify the correctness of the Media_A2V series APIs.
 */

#if defined(UNIT_TEST_ON_WIN32) && defined(UNIT_TEST_MEDIA_AVSYNC)
void callback(void)
{
   printf("callbacked\n");
}

int main(int argc, char** argv)
{

   media_a2v.uInterruptCount = 0;
   media_a2v.wDSPCount_Prev = 0;
   *A2V_INT_CNT = 0;
   ASSERT(Media_A2V_GetInterruptCount()==0);

   *A2V_INT_CNT = 1;
   ASSERT(Media_A2V_GetInterruptCount()==1);

   *A2V_INT_CNT = 0xFFFF;
   ASSERT(Media_A2V_GetInterruptCount()==0xFFFF);

   *A2V_INT_CNT = 0x0;
   ASSERT(Media_A2V_GetInterruptCount()==0x10000);

   *A2V_INT_CNT = 0x6000;
   ASSERT(Media_A2V_GetInterruptCount()==0x16000);

   *A2V_INT_CNT = 0x8000;
   media_a2v_Hisr();
   *A2V_INT_CNT = 0xA000;
   media_a2v_Hisr();
   *A2V_INT_CNT = 0x2000;
   ASSERT(Media_A2V_GetInterruptCount()==0x22000);

   Media_A2V_HookInterrupt(callback);
   media_a2v_Hisr();

   return 0;
}
#endif

/***
 * Verify the correctness of DSP.
 */

#if VERIFY_AVSYNC

#define BUF_SIZE 16384
kal_uint32 uTick[BUF_SIZE];
kal_uint32 uOSTick[BUF_SIZE];
kal_uint32 uCount[BUF_SIZE];
kal_uint32 uAudioFrameCount[BUF_SIZE];
kal_uint32 uVideoFrameCount[BUF_SIZE];
volatile kal_uint32 uIndex;

kal_uint32 uTickPlay[BUF_SIZE];
kal_uint32 uINTCNTPlay[BUF_SIZE];
kal_uint32 uIndexTickPlay;

kal_uint32 uTickRecord[BUF_SIZE];
kal_uint32 uINTCNTRecord[BUF_SIZE];
kal_uint32 uIndexTickRecord;

kal_uint32 uTimeStamp;

//#include "tc_defs.h"
//extern UNSIGNED TMD_System_Clock;

kal_uint32 visual_get_current_time(void)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226D)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6228)||defined(MT6229)||defined(MT6230)||defined(MT6225)|| defined(MT6268T) || defined(MT6235) || defined(MT6238))
	return ( (*(volatile kal_uint32 *)(0x80200230)));
#else
	return 0;
#endif
}

/**
 * When verification, this function is to be inserted in mediaHisr of media.c
   at each audio type before playback hisr.
 */
void ut_avsync_play_hisr(void)
{
   if (uIndexTickPlay < BUF_SIZE) {
      kal_get_time(&uTickPlay[uIndexTickPlay]);
      uINTCNTPlay[uIndexTickPlay] = Media_A2V_GetInterruptCount();
      uIndexTickPlay++;
   }
}

/**
 * When verification, this function is to be inserted in mediaHisr of media.c
   at each audio type before record hisr.
 */
void ut_avsync_record_hisr(void)
{
   if (uIndexTickRecord < BUF_SIZE) {
      kal_get_time(&uTickRecord[uIndexTickRecord]);
      uINTCNTRecord[uIndexTickRecord] = Media_A2V_GetInterruptCount();
      uIndexTickRecord++;
   }
}

/**
 * When verification, this function is the called back function for
 * servicing A/V sync interupts.
 */
static void ut_avsync_lisr(void)
{
   if (uIndex < BUF_SIZE) {
      static kal_uint32 uPrevTick;
      kal_uint32 uCurrentTick = visual_get_current_time();
      uTick[uIndex] = uCurrentTick;
      kal_get_time(&uOSTick[uIndex]);
      uCount[uIndex] = Media_A2V_GetInterruptCount();
      uAudioFrameCount[uIndex] = Media_A2V_GetAudioFrameCount();
      uVideoFrameCount[uIndex] = Media_A2V_GetVideoFrameCount();
      if (uIndex > 0) {
         kal_uint32 uDeltaTick = uCurrentTick > uPrevTick ? uCurrentTick - uPrevTick : 0x80000 + uCurrentTick - uPrevTick;
         kal_uint32 uTargetDeltaTick = (*A2V_INT_STAMP) * 32000 / (44100/6);
         kal_uint32 uDiffTick;
         uDiffTick = uDeltaTick > uTargetDeltaTick ? uDeltaTick-uTargetDeltaTick : uTargetDeltaTick-uDeltaTick;
         if (uDiffTick>150) {
            while(1);
            //EXT_ASSERT(KAL_FALSE, uPrevTick, uCurrentTick, uDeltaTick);
         }
      }
      uIndex++;
      uPrevTick = uCurrentTick;
   }
}

/**
 * For verifying A/V Sync when playback
 */
void ut_a2v_play_dsp_start(void) {
   uIndex = 0;
   uIndexTickPlay = 0;
   kal_mem_set(uTick, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uCount, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uAudioFrameCount, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uVideoFrameCount, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uTickPlay, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uINTCNTPlay, 0, BUF_SIZE * sizeof(kal_uint32));

   Media_A2V_HookInterrupt(ut_avsync_lisr);
   Media_A2V_EnableInterrupt(KAL_TRUE, 0);
   uTimeStamp = 110;
   /*
    * 240: 30ms for AMR
    * 220: 29.93 ms for 44100Hz audio
    */
   Media_A2V_SetTimeStamp(uTimeStamp);
}

/**
 * For verifying A/V Sync when recording
 */
void ut_a2v_record_dsp_start()
{
   uIndexTickRecord = 0;
   kal_mem_set(uTickRecord, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uINTCNTRecord, 0, BUF_SIZE * sizeof(kal_uint32));

   Media_A2V_HookInterrupt((void*)NULL);
   Media_A2V_EnableInterrupt(KAL_TRUE, 0);
   Media_A2V_SetTimeStamp(0xFFFF);
}

/**
 * For verifying A/V Sync
 */
void ut_a2v_dsp_stop(void) {
   kal_uint32 uStopTime;
   Media_A2V_EnableInterrupt(KAL_FALSE, 0);
   kal_get_time(&uStopTime);
   /* after stop time, ut_avsync_lisr should not be triggered */
}

#endif /* VERIFY_AVSYNC */

#endif /* IS_CHIP_MT6219_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION */


