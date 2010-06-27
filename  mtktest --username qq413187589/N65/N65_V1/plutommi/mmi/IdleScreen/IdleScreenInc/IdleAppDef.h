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
 * IdleAppDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is isle screen application
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      IdleAppDef.h
   Author:        
   Date Created:  September-13-2002
   Contains:      
**********************************************************************************/

#ifndef __IDLE_H__
#define __IDLE_H__

#include "MMI_features.h"
#include "IdleAppResDef.h"
#include "FrameworkStruct.h" /* FuncPtr definition */

#define GSM_SERVICE_TYPE            1
#define GPRS_SERVICE_TYPE           2
#define MAX_DIAL_PAD                41
//#define INVALID_LOCATION_SCR_TIMEOUT  1200
//#define NO_PHONE_NUM_SCR_TIMEOUT              1200

#define KEYPAD_LOCK_TIMEOUT            2000
#define TOGGLE_PROFILE_TIMEOUT         500

#define SET_CURRENT_PROFILE            0
#define SET_SILENT_PROFILE          1

#define MAX_IDLE_SCREEN_DIGITS      13
#define MAX_SPEED_DIAL_KEYS         9
/* start vijay 20050629...for grouping touch dial pad keys */
#ifdef __MMI_TOUCH_DIAL_SCREEN__
#define MAX_TOUCH_DIAL_PAD_KEYS     12
#endif 
/* end vijay */

#define MAX_LOCATION_DIGITS         3

#define NORMAL_SCREEN_SAVER                  0
#define ANALOG_SCREEN_SAVER                  1
#define DIGITAL_SCREEN_SAVER                 2

#define MAX_DISPLAY_CHAR 20

/* Lisen 05062004 for gIsSubLcdOnIdleScreen */
enum SUBLCD_STATE_ENUM
{
    SUBLCD_NOT_ON_IDLE = 0,
    SUBLCD_ON_IDLE_NORMAL,
    SUBLCD_ON_IDLE_INSERT_SIM,
    SUBLCD_ON_IDLE_SIM_BLOCKED
};

enum EMFM_MODE
{
    NORMAL_MODE = 0,
    ENGINEERING_MODE,
    FACTORY_MODE
};

typedef struct
{
    U8 IsOnIdleScreen;              /* This variable tells that current screen is idle screen. */
    U8 IsSubLcdOnIdleScreen;
    U8 IsOnDialerScreen;            /* It tells that current screen is Dialer Screen */
    U8 IsOnSimErrorScreen;
    U8 IsOnSimErrorDialerScreen;
    U8 IsScrSvrSleepIn;             /* is the screensaver exit because lcd sleep-in */
    U8 IsRSKPressOnScreenSaver;     /* This variable tells that Is RSK pressed on Screen saver screen */
    U8 LongPressEnable;             /* MTK amanda change 0107  This variable is to distinguish between speed dial from idle screen and long press of digits from dialer screen. */
    U8 ScreenSaverRunFlag;          /* 0 for False, 1 for True */
    U8 ToNameScrFromIdleApp;
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
    U8 ToMainMenuScrFromIdleApp;
#endif 
    U8 RskPressedFromIdleApp;       /* This variable tells that RSK has been pressed from idle screen. this is used for manual keypad lock. */
#ifdef __MMI_UCM__
    U8 DigitScreenDialMode;
#endif

    S16 IdleScreenDigitKeyCode; /* For digit handlig on dialing screens, it stores the keycode on press of any key on idle screen. */
    pBOOL ToggleProfile;        /* This varible stored current status of Toggle profile */
#ifdef __MMI_SIMAP_SUPPORT__
    pBOOL SimReady;
#endif

    U32 AutoLockTimeOut;    /* This carries the timeout period of Autokeypad lock */
#ifdef __MMI_VOIP__
    S8 DialPadCallBuffer[65 * ENCODING_LENGTH];    /* This buffer stores all dialled digits from idle screen */
#else
    S8 DialPadCallBuffer[MAX_DIAL_PAD * ENCODING_LENGTH];
#endif
} idle_context_struct;

extern idle_context_struct g_idle_context;

typedef struct
{
    U8 gKeyPadLockFlag;                 /* flag to check keypad is locked or unlocked */
    U8 IsOnKeyLockCallbackScreen;
    U16 KeyLockLSKStringID;             /* LSK string in keypad lock idle screen */
    U16 KeyLockRSKStringID;             /* RSK string in keypad lock idle screen */
    U16 KeyLockLSKIconID;               /* LSK icon in keypad lock idle screen */
    U16 KeyLockRSKIconID;               /* RSK icon in keypad lock idle screen */
    FuncPtr keypad_lock_screen_exit;    /* diamond, 2006/03/26 Generic exit function for keypad lock callback screens */
} idle_keylock_struct;

extern idle_keylock_struct g_keylock_context;

#endif /* __IDLE_H__ */ 

