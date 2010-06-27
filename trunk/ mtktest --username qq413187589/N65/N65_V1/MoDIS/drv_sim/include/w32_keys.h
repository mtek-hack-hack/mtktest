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
 *   w32_keys.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of keypad driver simulation for WIN32 environment
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef WIN32_KEYS_H
#define WIN32_KEYS_H

// Include MAUI header file
#include "keypad_sw.h"

extern void w32_key_detect_ind(unsigned char key_status, unsigned char key_code);
extern kal_bool kbd_two_key_detection_switch(kal_bool enable);
// This function is defined in keypad_sw.h, no more need to declare here
//extern kal_bool kbd_key_det_mode_switch(kal_uint32 mode);


typedef enum win32_ext_key_enum_
{
    WIN32_EXT_KEY_1,
    WIN32_EXT_KEY_2,
    WIN32_EXT_KEY_3,
    WIN32_EXT_KEY_4,
    WIN32_EXT_KEY_5,
    WIN32_EXT_KEY_6,
    WIN32_EXT_KEY_7,
    WIN32_EXT_KEY_8,
    WIN32_EXT_KEY_9,
    WIN32_EXT_KEY_0,
    WIN32_EXT_KEY_STAR,
    WIN32_EXT_KEY_HASH,
    WIN32_EXT_KEY_SK_LEFT,
    WIN32_EXT_KEY_SK_RIGHT,
    WIN32_EXT_KEY_SEND,
    WIN32_EXT_KEY_END,
    WIN32_EXT_KEY_UP,
    WIN32_EXT_KEY_DOWN,
    WIN32_EXT_KEY_LEFT,
    WIN32_EXT_KEY_RIGHT,
    WIN32_EXT_KEY_MENU,
    WIN32_EXT_KEY_FUNCTION,
    WIN32_EXT_KEY_VOL_UP,
    WIN32_EXT_KEY_VOL_DOWN,
    WIN32_EXT_KEY_POWER,
    WIN32_EXT_KEY_CLEAR,
    WIN32_EXT_KEY_MP3_FWD,
    WIN32_EXT_KEY_MP3_PLAY_STOP,
    WIN32_EXT_KEY_MP3_BACK,

    WIN32_EXT_KEY_COUNT
} win32_ext_key_enum;

#endif /* WIN32_KEYS_H */ 

