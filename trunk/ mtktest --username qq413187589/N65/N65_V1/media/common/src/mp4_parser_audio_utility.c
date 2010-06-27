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
 *   mp4_parser_audio_utility.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Platform-Depedent MPEG-4 Parser Audio Utility Functions
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mp4_parser.h"

Media_Format MP4_Audio_Type_To_Media_Format(MP4_Audio_Type eAudioType)
{
   Media_Format eAudioFormat;

   switch(eAudioType) {
      case MP4_AUDIO_AAC:
         eAudioFormat = MEDIA_FORMAT_AAC;
         break;
      case MP4_AUDIO_AMR:
         eAudioFormat = MEDIA_FORMAT_AMR;
         break;
      case MP4_AUDIO_AMR_WB:
         eAudioFormat = MEDIA_FORMAT_AMR_WB;
         break;
      case MP4_AUDIO_NONE:
         eAudioFormat = MEDIA_FORMAT_AMR;
         break;
   }
   return eAudioFormat;
}

/*
   Get audio playback time in mili-second.
*/
#if defined(MP4_CODEC)
MP4_Parser_Status MP4_Audio_GetPlayTime(STMp4Parser *pstMp4Parser, kal_uint64 *puMiliSecond, kal_uint32 speed_scale )
{
   kal_uint32 uAudioInterruptCount;
   kal_uint32 uAudioInterruptTimeScale;
   kal_uint64 uPreviousTime;
   Media_Format eFormat;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puMiliSecond!=NULL);

   uPreviousTime = *puMiliSecond;
   eFormat = MP4_Audio_Type_To_Media_Format( pstMp4Parser->bAudioType );
   uAudioInterruptTimeScale = Media_A2V_GetPlaybackInterruptTimeScale( eFormat, pstMp4Parser->bAudioSamplingFreqIndex );
   uAudioInterruptCount = Media_A2V_GetInterruptCount();
   *puMiliSecond = pstMp4Parser->uAudioSeekPointTime + uAudioInterruptCount * speed_scale * 10 / uAudioInterruptTimeScale;
   return MP4_PARSER_OK;
}

/*
   Get video playback time in mili-second.
*/
MP4_Parser_Status MP4_GetPlayTime(STMp4Parser *pstMp4Parser, kal_uint64 *puMiliSecond, kal_uint32 speed_scale )
{
   kal_uint32 uCurrentInterruptCount;
   kal_uint32 uAudioInterruptTimeScale;
   Media_Format eFormat;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puMiliSecond!=NULL);

   eFormat = MP4_Audio_Type_To_Media_Format( pstMp4Parser->bAudioType );
   uAudioInterruptTimeScale = Media_A2V_GetPlaybackInterruptTimeScale( eFormat, pstMp4Parser->bAudioSamplingFreqIndex );

   uCurrentInterruptCount = Media_A2V_GetInterruptCount();
   if( uCurrentInterruptCount < pstMp4Parser->uPreviousInterruptCount )
      pstMp4Parser->uPreviousInterruptCount = uCurrentInterruptCount;
   *puMiliSecond = pstMp4Parser->uPlaybackTimeBase + ( uCurrentInterruptCount - pstMp4Parser->uPreviousInterruptCount ) * speed_scale * 10 / uAudioInterruptTimeScale;

   pstMp4Parser->uPlaybackTimeBase = *puMiliSecond;
   pstMp4Parser->uPreviousInterruptCount = uCurrentInterruptCount;

   return MP4_PARSER_OK;
}
#endif // #if defined(MP4_CODEC)
/*
   Set the playback timer base to the given time.
   The playback time will be accumulated based on the timer base.
   Playback timer should only be set when AV sync is not activated yet.
*/
void MP4_SetPlaybackTimerBase(STMp4Parser *pstMp4Parser, kal_uint32 uPlaybackTimeBase, kal_bool bResetPreviousInterruptCount)
{
   pstMp4Parser->uPlaybackTimeBase = uPlaybackTimeBase;
   if (bResetPreviousInterruptCount)
   	pstMp4Parser->uPreviousInterruptCount = 0;
}
