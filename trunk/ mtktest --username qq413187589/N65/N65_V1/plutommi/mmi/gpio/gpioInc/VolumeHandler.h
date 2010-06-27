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
 * VolumeHandler.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Volume Key Handler
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : VolumeHandler.h

   PURPOSE     : Volume Key Handler

   REMARKS     : nil

   AUTHOR      : Deepali, NEERAJ SHARMA

   DATE     : July 22,03

**************************************************************/
#ifndef _VOLUME_HANDLER_H
#define _VOLUME_HANDLER_H
#include "FrameworkStruct.h"
#include "SettingProfile.h"

#ifdef MMI_ON_WIN32
// #define PROFILES_TESTING_ON_WINDOWS
#endif 

#define MAX_VOL_LEVEL_SCR_KEYS         19
#define KEY_VOLUME_TIMEOUT          2000
typedef enum
{
    VOLUMEHANDLER_RING_TONE,
    VOLUMEHANDLER_SPEECH_TONE,
    VOLUMEHANDLER_KEY_TONE
} VOLUMEHANDLER_TYPE;

extern void SetDefaultVolumeKeyHandlers(void);

extern void SetVolumeKeyHandlerFunctions(
                FuncPtr decreaseFunction,
                FuncPtr increaseFunction,
                FuncPtr minFunction,
                FuncPtr maxFunction,
                U16 caption,
                S32 *volume,
                U16 captionLSK,
                U16 captionRSK,
                FuncPtr callbackLSK,
                FuncPtr callbackRSK,
                U32 timerDuration,
                FuncPtr callbackExit,
                U8 updown,
                VOLUMEHANDLER_TYPE type);

extern void SetKeyPadVolMaxLongPress(void);
extern void SetKeyPadVolMinLongPress(void);
extern void SetKeyPadVolDown(void);
extern void SetKeyPadVolUp(void);
extern void EntryScrSetKeyPadVolumeLevel(void);
extern void ExitScrSetKeyPadVolumeLevel(void);
extern void StartKeyPadVolumeLevelTimer(void);
extern void StopKeyPadVolumeLevelTimer(void);
extern void ShowVerticalBarMin(void);
extern void ShowVerticalBarMax(void);
extern void ShowVerticalBarDown(void);
extern void ShowVerticalBarUp(void);

extern void SpeechVolumeFunction(void);
extern void SpeechVolumeExitFunction(void);
extern void RingVolumeExitFunction(void);
extern void RingToneVolumeFunction(void);

extern void KeyPadVolumeFunction(void);
extern void KeyPadVolumeExitFunction(void);

/* PMT HIMANSHU START 20050729 */
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__)

extern void CallShowVerticalBarMax(void);
extern void CallShowVerticalBarMin(void);
extern void ResetCallbackTimer(void);

#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
/* PMT HIMANSHU END 20050729 */

#endif /* _VOLUME_HANDLER_H */ 

