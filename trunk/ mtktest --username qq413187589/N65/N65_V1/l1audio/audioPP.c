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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   AudioPP.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  Audio Post Processing includes Time Stretch
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(AUD_TIME_STRETCH)

#include "media.h"
#include "am.h"
#include "kal_trace.h"
#include "l1sp_trc.h"

#if defined(MT6228)
#define PAGE_NUM 0
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 2
#else
#error The new chip should define DM page number
#endif

// define the state machine of Time Stretch
#define AUDIO_PP_IDLE          0x00
#define AUDIO_PP_TS_INIT       0x23
#define AUDIO_PP_TS_ON         0x21


#define AUDIO_PP_MASK          0x003F
#define AUDIO_PP_MASK_IDLE     0x003E
#define AUDIO_PP_STATE_OFF     0x0001

// define the ID of each Post Process
#define AUDIO_PP_NONE          0
#define AUDIO_PP_TS            1


#if defined(MT6228) || defined(MT6225)
#define VBI_Reset()       { *SHARE_M2DI1 = 0x0838; }
#else
#define VBI_Reset()       { *SHARE2_M2DI1 = 0x0838; }
#endif

uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );

#if defined( DSP_WT_SYN )
extern Media_Handle *TS_Midi_Handle;
extern Media_Handle *TS_Imy_Handle;
#endif

static struct ts_struct {
   bool audioPP_disableFlag;
   bool audioPP_TS_Wait;
   uint16 audioPP_TS_Ratio;
   Media_Format audioPP_Format;
} TS_Control;

// Get Time Stretch Setting Speed Rate (50 ~ 160) for Midi
kal_int32 AudioPP_GetTSRate( void )
{
   int32 rate;

   switch (TS_Control.audioPP_TS_Ratio) {
      case 1:  rate =  50;  break;
      case 2:  rate =  80;  break;
      case 3:  rate = 128;  break;
      case 4:  rate = 160;  break;
      default:
         rate = 100;
   }

   return rate;
}


void AudioPP_SetMediaFormat(Media_Format eFormat) {
   TS_Control.audioPP_Format = eFormat;
}


/*
 * Description
 * -----------
 *  Set the initial value for Time Stretch 
 *
 * Syntax
 * ------------
 *  void AudioPP_TS_Iniy(void);
 *
 * Return Value
 * ------------
 *  None
 */
void AudioPP_TS_Init(void) {
   TS_Control.audioPP_TS_Wait = false;
   TS_Control.audioPP_TS_Ratio = 0;
   TS_Control.audioPP_disableFlag = false;
   TS_Control.audioPP_Format = MEDIA_FORMAT_DAF;
}


/*
 * Description
 * -----------
 *  Activate time stretch
 *  Follow the TS state machine 
 *
 * Syntax
 * ------------
 *  void AudioPP_TS_Activate(void);
 *
 * Return Value
 * ------------
 *  None
 */
void AudioPP_TS_Activate(bool voice_init) {
   int32 I;

   (void) voice_init;

   if ( (TS_Control.audioPP_TS_Ratio == 0) || (TS_Control.audioPP_disableFlag) )
      return;

   // KH: Audio is MIDI
   if (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) {
      int32 rate;
      
      rate = AudioPP_GetTSRate();
      JMidi_SetTSRate(TS_Midi_Handle, rate);
      return;
   } else if (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) {
      int32 rate;
      
      rate = AudioPP_GetTSRate();
      JImy_SetTSRate(TS_Imy_Handle, rate);
      return;
   }

   if (AM_IsAudioPlaybackOn()!=-1) {
      *AFE_AMCU_CON1 |= 0x0C;  // Hardware mute
      kal_sleep_task(30); 
      APM_ClearBuffer();
   }

   *AUDIO_PP_TS_SPEED = TS_Control.audioPP_TS_Ratio;
   AM_SetPostProcessCtrl( AUDIO_PP_MASK_IDLE, AUDIO_PP_TS_INIT);
   kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_TS_INIT);

   if (AM_IsAudioPlaybackOn()!=-1) {
      for (I = 0; ; I++) {
         if ( ( (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON) ||
         	    ( (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK_IDLE) == AUDIO_PP_IDLE))
            break;
         ASSERT_REBOOT( I < 80 );
         kal_sleep_task( 2 );
      }
      *AFE_AMCU_CON1 &= ~0x0C;  // Release hardware mute
   }

   if ( (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON )
      kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_TS_ON);
   else
      kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_IDLE);

}

/*
 * Description
 * -----------
 *  Keep the speed_mode in local variable.
 *  If DSP is on, then MCU sets the mode (call AudioPP_TS_Activate)
 *
 * Syntax
 * ------------
 *  Media_Status AudioPP_TS_SetSpeed(kal_uint16 speed_mode);
 *
 *  where:
 *     speed_mode     controls the TS ratio
 *
 * Return Value
 * ------------
 *  Return MEDIA_SUCCESS when the operation is complete.
 *  Return MEDIA_FAIL when argument or state is wrong.
 */
Media_Status AudioPP_TS_SetSpeed(kal_uint16 speed_mode) {
   uint16 audioPP_state;

   // Check the speed mode
   if ( (speed_mode < 1) || (speed_mode > 4) )
      return MEDIA_FAIL;
   
   // Check whether 3D effect is running
   audioPP_state = (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK);
   if ( ((audioPP_state & AUDIO_PP_MASK_IDLE) != AUDIO_PP_IDLE) &&
        (audioPP_state != AUDIO_PP_TS_INIT) &&
        (audioPP_state != AUDIO_PP_TS_ON) )
      return MEDIA_FAIL;

   // Check reentry
   if (TS_Control.audioPP_TS_Wait)
      return MEDIA_FAIL;

   TS_Control.audioPP_TS_Ratio = speed_mode;

   kal_trace(TRACE_FUNC, L1AUDIO_PP_SET_TS, speed_mode);
   if (AM_IsAudioPlaybackOn()!=-1)
   {
      TS_Control.audioPP_TS_Wait = true;
      AudioPP_TS_Activate(false);
      TS_Control.audioPP_TS_Wait = false;
   }

   return MEDIA_SUCCESS;
}

/*
 * Description
 * -----------
 *  Close the Time Stretch.
 *  The speed will be set to NORMAL.
 *
 * Syntax
 * ------------
 *  void AudioPP_CloseTS(void);
 *
 * Return Value
 * ------------
 *  None
 */
void AudioPP_TS_Close(void) {
   uint16 audioPP_state;

   audioPP_state = (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK);
   if ( ((audioPP_state & AUDIO_PP_MASK_IDLE) == AUDIO_PP_IDLE) ||
        (audioPP_state == AUDIO_PP_TS_ON) ||
        (audioPP_state == AUDIO_PP_TS_INIT) )
   {
      *DP_AUDIO_CTRL2 &= ~0x0800;                    // Disable AMR time stretch

      TS_Control.audioPP_TS_Ratio = 0;

      // KH: Audio is MIDI
      if (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) {    
         *AUDIO_PP_TS_SPEED = 0;
         JMidi_SetTSRate( TS_Midi_Handle, 100);
         return;
      } else if (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) {
         *AUDIO_PP_TS_SPEED = 0;
         JImy_SetTSRate( TS_Imy_Handle, 100);
         return;
      } else {
         if (AM_IsAudioPlaybackOn()!=-1) {
            *AFE_AMCU_CON1 |= 0x0C;   // Hardware mute
            APM_ClearBuffer();
         }
         *AUDIO_PP_TS_SPEED = 0;
      }

      AM_ClearPostProcessCtrl( AUDIO_PP_MASK_IDLE );
      kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_IDLE);

      if (AM_IsAudioPlaybackOn()!=-1) {
         *AFE_AMCU_CON1 &= ~0x0C;  // Release hardware mute
      }
   }
}


void AudioPP_Close(void) {
   AM_ClearPostProcessCtrl( AUDIO_PP_MASK_IDLE );
   kal_prompt_trace(MOD_L1SP, "AudioPP in Idle");
}

// Get Current Time Stretch Speed mode (0 ~ 4)
kal_uint16 AudioPP_TS_GetSpeed(void) {
   if ( (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) || (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) ) {
      return TS_Control.audioPP_TS_Ratio;
   }

   if ( ( (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK) == AUDIO_PP_TS_INIT ) ||
   	    ( (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON) )
      return *AUDIO_PP_TS_SPEED;
   else
      return 0;
}

kal_bool AudioPP_TS_IsEnable(void) {
   if ( (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) || (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) ) {
      if ( AM_IsAudioPlaybackOn() != -1 )
         return (TS_Control.audioPP_TS_Ratio != 0);
      else
         return 0;
   } else {
      return ( (*DP2_AUDIO_PP_CTRL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON);
   }
}


/*
 * Description
 * -----------
 *  Determine whether TS supports the file
 *
 * Syntax
 * ------------
 *  kal_bool AudioPP_TS_IsSupport(Media_Format eFormat, STFSAL *pstFSAL);
 *
 *  where:
 *    eFormat     is the file type
 *    *pstFSAL    is the file pointer
 *
 * Return Value
 * ------------
 *  Return true when TS supports the file
 */
kal_bool AudioPP_TS_IsSupport(Media_Format eFormat, STFSAL *pstFSAL) {

   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
#if AMR_AWB_AUDIO_PATH_SUPPORT
      case MEDIA_FORMAT_AMR_WB:
#endif // #if AMR_AWB_AUDIO_PATH_SUPPORT
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_SMF:
      case MEDIA_FORMAT_IMELODY:
      case MEDIA_FORMAT_MMF:
      case MEDIA_FORMAT_WMA:
      case MEDIA_FORMAT_MUSICAM:
         return true;
      case MEDIA_FORMAT_AAC:
#if defined(AAC_PLUS_DECODE)
         if (pstFSAL == NULL)
            return true;
         else
            return AAC_IsPPSupport(pstFSAL);
#else
         return true;
#endif
      case MEDIA_FORMAT_M4A:
#if defined(AAC_PLUS_DECODE) && defined(MP4_CODEC)
         return M4A_IsPPSupport(pstFSAL);
#else
         return true;
#endif
      default:
         return false;
   }
}

/*
 * Description
 * -----------
 *  Determine whether 3D-effect supports the file
 *
 * Syntax
 * ------------
 *  kal_bool AudioPP_Is3DSupport(Media_Format eFormat, STFSAL *pstFSAL);
 *
 *  where:
 *    eFormat     is the file type
 *    *pstFSAL    is the file pointer
 *
 * Return Value
 * ------------
 *  Return true when 3D-effect supports the file
 */
kal_bool AudioPP_Is3DSupport(Media_Format eFormat, STFSAL *pstFSAL) {

   switch (eFormat) {
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_SMF:
      case MEDIA_FORMAT_IMELODY:
      case MEDIA_FORMAT_MMF:
      case MEDIA_FORMAT_WMA:
      case MEDIA_FORMAT_MUSICAM:
         return true;
      case MEDIA_FORMAT_AAC:
#if defined(AAC_PLUS_DECODE)
         if (pstFSAL == NULL)
            return true;
         else
            return AAC_IsPPSupport(pstFSAL);
#else
         return true;
#endif
      case MEDIA_FORMAT_M4A:
#if defined(MP4_CODEC) && defined(AAC_PLUS_DECODE)
         return M4A_IsPPSupport(pstFSAL);
#else
         return true;
#endif
      default:
         return false;;
   }
}

/*
 * Internal Use.
 * To enable or disable the functionality of 3D effect.
 * When disable 3D, user cannot use 3D effect even if AudioPP_TurnOn3D is called 
 */
void AudioPP_Disable(void) {
   TS_Control.audioPP_disableFlag = true;
}

void AudioPP_Enable(void) {
   TS_Control.audioPP_disableFlag = false;
}


#endif  // AUD_TIME_STRETCH