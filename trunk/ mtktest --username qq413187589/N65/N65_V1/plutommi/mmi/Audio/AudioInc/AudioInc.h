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
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * AudioSrc.c
 *
 * Project:
 * --------
 *   MediaTeck GSM
 *
 * Description:
 * ------------
 *   This Module defines the L4 Audio Driver Routines.
 *
 * Author:
 * -------
 * -------
 *             
 *
 * HISTORY
 * -------
 * Created On 12 March
*******************************************************************************/
#ifndef _AUDIOINC_H
#define _AUDIOINC_H

#include "MMIDataType.h"
#include "QueueGprot.h"
/* NVRAM_REVISE */
#include "custom_mmi_default_value.h"
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
#ifdef __MMI_CONNECT_NOTICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* 0 */ /* NVRAM_REVISE */
typedef enum
{
    AUDIO_COMPOSER_PLAY_ID = 1
} AUDIO_PLAY_ID;

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
#ifndef DEVELOPER_BUILD_FIRST_PASS
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* DEVELOPER_BUILD_FIRST_PASS */ 
#endif

#include "kal_non_specific_general_types.h"
#include "device.h"
#include "resource_audio.h"

extern void AudioPlayReqWithVolPath(U16 soundId, U8 style, U8 volume, U8 path);
extern void AudioPlayReq(U16 soundId, U8 style);
extern void AudioStopReq(U16 soundId);
extern void AudioPlayIMelodyString(U8 *string, U16 len, U8 style);
extern void AudioPlayIMelodyFile(U8 *file, U8 style);
extern void AudioPlayIMelodyFileWithId(U8 *file, U8 style, U16 nId);
extern void AudioStopIMelodyFile(U8 *file);
extern void AudioPlayToneWithCallBack(U16 soundId, U8 style, U8 tone_type);
extern void AudioPlayToneWithCallBackVolPath(U16 soundId, U8 style, U8 tone_type, U8 volume, U8 path);

extern void StopAudioMidiStream(void);
extern void StopAudioWavStream(void);
extern void StopAudioDviStream(void);
extern void StopAudioStream(void);
extern void PlayAudioMidiStream(U8 *audioBuffer, U16 length, U8 style);
extern void PlayAudioWavStream(U8 *audioBuffer, U16 length, U8 style);
extern void PlayAudioStream(U8 *audioBuffer, U16 length, U8 format, U8 style);
extern void PlayAudioDviStream(U8 *audioBuffer, U16 length, U8 style);

#endif /* _AUDIOINC_H */ 

