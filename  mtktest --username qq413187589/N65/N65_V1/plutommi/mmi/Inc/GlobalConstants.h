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
 * GlobalConstants.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Global const define
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
#ifndef _GLOBALCONSTANTS_H_
#define _GLOBALCONSTANTS_H_

/* Constants from Menu.h */

#define MAX_SUB_MENUS         60
#define MAX_SUBMENU_CHARACTERS   41
#define MAX_SUB_MENU_SIZE     (41*ENCODING_LENGTH + ENCODING_LENGTH)
#define MAX_SUB_MENU_HINT_SIZE   (41*ENCODING_LENGTH + ENCODING_LENGTH)

/* Queue structures */
#define MAX_PRT_NODES         50

#define INVALID_HANDLER       0
#define QUEUE_NOT_YET_CREATED 0

typedef enum
{
    KEY_0 = 0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_LSK,
    KEY_RSK,
    KEY_CSK,
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_SEND,
    KEY_END,
    KEY_CLEAR,
    KEY_STAR,
    KEY_POUND,
    KEY_VOL_UP,
    KEY_VOL_DOWN,
    KEY_QUICK_ACS,
    KEY_CAMERA = KEY_QUICK_ACS,
    KEY_ENTER,
    KEY_WAP = KEY_ENTER,
    KEY_IP = KEY_ENTER,
    KEY_EXTRA_1,
    KEY_EXTRA_2,
    KEY_PLAY_STOP,
    KEY_FWD,
    KEY_BACK,
    KEY_POWER,
    KEY_EXTRA_A,
    KEY_EXTRA_B,
#ifdef __SENDKEY2_SUPPORT__
   /*
    * the second call key is define for MERCURY dual mode
    * KEY_SEND means KEY_SEND1 and KEY_SEND2
    * But the application could set the individual key handler in using KEY_SEND1 and KEY_SEND2
    * KEY_SEND1 has its KEY_SEND1's entry in nKeyPadMap[]
    * KEY_SEND2 has its KEY_SEND2's entry in nKeyPadMap[]
    */
    KEY_SEND1,
    KEY_SEND2,
#endif	/* __SENDKEY2_SUPPORT__ */
    MAX_KEYS,   /* max key codes support */

    KEY_INVALID = 0xFE  // 255  /* By JL, to sync with driver */
} mmi_keypads_enum;


/* KEY BOARD MSG TYPES (Global to MMI, KBD and KBH tasks) */
typedef enum
{
    KEY_FULL_PRESS_DOWN,
    KEY_EVENT_DOWN = KEY_FULL_PRESS_DOWN,
    KEY_EVENT_UP,
    KEY_LONG_PRESS,
    KEY_REPEAT,
    KEY_HALF_PRESS_DOWN,
    KEY_HALF_PRESS_UP,
    MAX_KEY_TYPE
} mmi_key_types_enum;


/* concurrent key mode */
typedef enum {
    CONCURRENT_KEY_MODE_1_KEY,
    CONCURRENT_KEY_MODE_2_KEYS,
    CONCURRENT_KEY_MODE_3_KEYS,
    CONCURRENT_KEY_MODE_END
} mmi_frm_concurrent_key_mode_enum;


/* ++Robin */
#define KEY_EVENT_REPEAT               KEY_REPEAT
#define KEY_EVENT_LONG_PRESS        KEY_LONG_PRESS
/* --Robin */

//PRT MESSAGE TYPES (Global to MMI and PRT task)
//#define PRT_SETUP_IND                         1
/*  Sound media interface message types */
#define START_MELODY       1
#define STOP_MELODY           2
#define RESUME_MELODY         3

/* EVENT TYPES */
#define KBD_EVENT          1
#define PRT_EVENT          2
#define TMR_EVENT          3
#define HWR_EVENT          4
#define MEDIA_EVENT           5

#define KEY_IDLE     0
#define KEY_PRESS    1

/* WINDOWS KEY CODES */
#define WM_KEYPRESS        0
#define WM_KEYRELEASE      1
/* ++Robin */
#define DRV_WM_KEYLONGPRESS   2
#define DRV_WM_KEYREPEATED   3
/* --Robin */
#define DRV_WM_KEYFULLPRESS   4

#define WM_KEYBRD_PRESS       256       /* Equivalent to WM_KEYDOWN for key board keys */
#define WM_KEYBRD_RELEASE     257       /* Equivalent to WM_KEYUP for key board keys */

#endif /* _GLOBALCONSTANTS_H_ */ 

