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
 * Keybrd.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for keypad processing
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
 *
 * removed!
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

/**************************************************************

   FILENAME : KeyBrd.c

   PURPOSE     : Key Board Handler 

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma

   DATE     : Aug 25, 2003

**************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

/*  Include: MMI header file */
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "TimerEvents.h"
#include "GlobalConstants.h"
#include "MMI_trc.h"
#include "FrameworkGprot.h"        
#include "FrameworkProt.h"         
#include "AudioInc.h"
#include "ThrdOsInterface.h"
#include "DebugInitDef.h"
#include "SettingProfile.h"
#include "WrapperGprot.h"
#include "ProfileGprots.h"
#include "VolumeHandler.h"
#include "CallManagementGprot.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif /* __MMI_EMAIL__ */

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /* __MMI_UCM__ */

#include "kbd_table.h"
#include "keypad_sw.h"
#include "gpioInc.h"
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "wgui_touch_screen.h"
#endif 
#include "ScreenRotationGprot.h"
#include "kbd_table.h"
#include "ProfilingEngine.h"
#include "SimDetectionGprot.h"


#include "L4c_eq_msg.h"     /* for l4c_kbd_getkeydata */

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIAVRCPGProt.h"
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) */

#ifdef __LSK_KEYSEND2_IN_ONE__
#include "MTPNP_PFAL_CC.h"   
#endif/*__LSK_KEYSEND2_IN_ONE__*/

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#include "MTPNP_AD_master_if.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

extern BOOL IsClamClose(void);
/***************************************************************************** 
* Define
*****************************************************************************/
#define MAX_PRESENTALLKEYS sizeof(PresentAllKeys)/sizeof(PresentAllKeys[0])
#define MAX_PRESENTDIGITSKEYS sizeof(PresentDigitsKeys)/sizeof(PresentDigitsKeys[0])
#define MAX_KEYPADMAP   sizeof(nKeyPadMap)/sizeof(nKeyPadMap[0])

#define DRV_WM_ENABLE_TWOKEY_DETECTION      (kbd_twokey_detection_enable)
#define DRV_WM_ENABLE_THREEKEY_DETECTION    (kbd_threekey_detection_enable)
#define DRV_WM_DISABLE_MULTIKEY_DETECTION   (kbd_multikey_detection_disable)

#define KBD_ATCMD_GET_KEY_FUNC   (l4c_kbd_getkeydata)

#define KEYTIMER_LONGPRESS       2000   /* Key Long Pres Duration */
#define KEYTIMER_REPEAT          1000   /* Key Reapeat Duration */


/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef struct
{
    S16 nKeyCode;       /* From Key Pad Driver */
    S16 nMMIKeyCode;    /* Key code mapped from MMI perspective */
    /* S16 nKeyState;//Pressed,Released or idle */
    U8 KeyPadTone;
    U8 KeyPadDuration;
} KeyPadMap;

typedef struct
{
    S16 nKeyState;
} KeyPadState;


/***************************************************************************** 
* Local Variable
*****************************************************************************/
static U16 currKeyPadTone = 0xFFFF;
static mmi_key_types_enum nKeyPadStatus[MAX_KEYS];

/* since all key status are initialized to KEY_EVENT_UP, we may 
   assign prevKeyMapIndex to any value less than MAX_KEYPADMAP here */
static U16 prevKeyMapIndex = 0;

#if defined(__MMI_SCREEN_ROTATE__)
static mmi_frm_screen_rotate_enum key_rotate = MMI_FRM_SCREEN_ROTATE_0;
#endif

/* allow multiple keys's processing at the same time */
static mmi_frm_concurrent_key_mode_enum g_kbd_concurrent_key_mode = CONCURRENT_KEY_MODE_1_KEY;

/* how many key under pressing  */
static U8 key_is_pressing_count = 0;

static MMI_BOOL g_process_key_in_high_frequency = MMI_FALSE;


#ifdef __MMI_SUBLCD_MASTER_MODE__
extern BOOL IsClamClose(void);

static U16 CurrSubLCDScrnID = 0;
/* available slave mode key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs_slave[MAX_KEYS][MAX_KEY_TYPE];
/* available master mode key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs_master[MAX_KEYS][MAX_KEY_TYPE];
/* available key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];    /* available key func ptrs to current screen  */

#else
/* available key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];

#endif /*ifdef __MMI_SUBLCD_MASTER_MODE__ */


static U16 currKeyCode;
static U16 currKeyType;

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern U8 gEmerencyNoDialed;

#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
extern BOOL DirectMode;
#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */ 

mmi_frm_context_struct g_mmi_frm_cntx;
static mmi_frm_context_struct *frm_p = &g_mmi_frm_cntx;

static U32 g_2step_key_num = 0;
static U16 g_2step_keyCode[MAX_KEYS];

static MMI_BOOL processUpRepeatKey = MMI_FALSE;

typedef enum
{
    FULL_UP_STATUS   = 0,
    HALF_DOWN_STATUS,
    FULL_DOWN_STATUS
}press_key_status_enum;

static press_key_status_enum  pressKey = FULL_UP_STATUS;   /* 0- full up, 1- half down, 2- full down */

const U16 PresentDigitsKeys[] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9};
const U16 PresentAllKeys[] = 
{
    KEY_0,
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
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_SEND,
    KEY_END,
    KEY_STAR,
    KEY_POUND,
    KEY_VOL_UP,
    KEY_VOL_DOWN,
    KEY_CLEAR,
    KEY_CAMERA,
    KEY_WAP,
    KEY_EXTRA_1,
    KEY_EXTRA_2,
    KEY_PLAY_STOP,
    KEY_PLAY_STOP,
    KEY_BACK,
    KEY_POWER,
    KEY_EXTRA_A,
    KEY_EXTRA_B
#ifdef __SENDKEY2_SUPPORT__
	,
	KEY_SEND1,
	KEY_SEND2
#endif	/* __SENDKEY2_SUPPORT__ */
};


static const KeyPadMap nKeyPadMap[] = 
{
    {DEVICE_KEY_0, KEY_0, TONE_DTMF_0, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_1, KEY_1, TONE_DTMF_1, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_2, KEY_2, TONE_DTMF_2, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_3, KEY_3, TONE_DTMF_3, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_4, KEY_4, TONE_DTMF_4, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_5, KEY_5, TONE_DTMF_5, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_6, KEY_6, TONE_DTMF_6, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_7, KEY_7, TONE_DTMF_7, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_8, KEY_8, TONE_DTMF_8, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_9, KEY_9, TONE_DTMF_9, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_STAR, KEY_STAR,  TONE_KEY_STAR, DEVICE_AUDIO_PLAY_INFINITE},
    {DEVICE_KEY_HASH, KEY_POUND, TONE_KEY_HASH, DEVICE_AUDIO_PLAY_INFINITE},
#if !defined(__MMI_NO_VOL_KEYS__)    
     //Huyanwei Modify It 
    {DEVICE_KEY_VOL_UP, KEY_VOL_UP, TONE_KEY_VOL_UP, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_VOL_DOWN, KEY_VOL_DOWN, TONE_KEY_VOL_DOWN, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_CAMERA, KEY_CAMERA, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE}, /* hongzhe.liu add on 20080603 */
#endif
    {DEVICE_KEY_UP, KEY_UP_ARROW, TONE_KEY_UP, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_DOWN, KEY_DOWN_ARROW, TONE_KEY_DOWN, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_LEFT, KEY_LEFT_ARROW, TONE_KEY_LEFT, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_RIGHT, KEY_RIGHT_ARROW, TONE_KEY_RIGHT, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_MENU, KEY_ENTER, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_FUNCTION, KEY_QUICK_ACS, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
#if defined __SENDKEY2_SUPPORT__ 
    #if defined NO_LSK
    {DEVICE_KEY_SEND, KEY_LSK, TONE_KEY_SEND, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_SEND2, KEY_SEND2, TONE_KEY_SEND, DEVICE_AUDIO_PLAY_ONCE},
    #else
    {DEVICE_KEY_SEND, KEY_SEND1, TONE_KEY_SEND, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_SEND2, KEY_SEND2, TONE_KEY_SEND, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_SK_LEFT, KEY_LSK, TONE_KEY_SK_LEFT, DEVICE_AUDIO_PLAY_ONCE},
    #endif /* NO_LSK */
#else
    #if defined NO_LSK
    // 目前都是双卡， 这里没有定义
#else
    {DEVICE_KEY_SK_LEFT, KEY_LSK, TONE_KEY_SK_LEFT, DEVICE_AUDIO_PLAY_ONCE},
    #endif /* NO_LSK */
    {DEVICE_KEY_SEND, KEY_SEND, TONE_KEY_SEND, DEVICE_AUDIO_PLAY_ONCE},
#endif	/* __SENDKEY2_SUPPORT__ */

    {DEVICE_KEY_SK_RIGHT, KEY_RSK, TONE_KEY_SK_RIGHT, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_END, KEY_END, TONE_KEY_END, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_POWER, KEY_POWER, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},        /* 24 IMPORTANT :This will be power key */
    {DEVICE_KEY_CLEAR, KEY_CLEAR, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_EXT_FUNC1, KEY_EXTRA_1, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_EXT_FUNC2, KEY_EXTRA_2, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_MP3_PLAY_STOP, KEY_PLAY_STOP, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_MP3_FWD, KEY_FWD, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_MP3_BACK, KEY_BACK, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_EXT_A, KEY_EXTRA_A, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE},
    {DEVICE_KEY_EXT_B, KEY_EXTRA_B, TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE} 
};


/*****************************************************************************
* Local Function                                                              
*****************************************************************************/
static void KeyEventHandler(KEYBRD_MESSAGE *eventKey);
static void mmi_frm_reset_internal_key_contex(void);
static U8 mmi_kbd_app_key_hdlr(KEYBRD_MESSAGE *eventKey);
static MMI_BOOL mmi_frm_is_2step_keyCode(U16 keyCode);

#ifdef __MMI_SCREEN_ROTATE__
__inline U16 get_rotated_key(U32 Keyevent, U16 KeyMapIndex);
#endif /* __MMI_SCREEN_ROTATE__ */


/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/
extern void ShutdownSystemOperation(void);
extern void kbd_find_2step(kal_uint32 *number, kal_uint8 *two_step);

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
extern U8 CanPlayHumanVoiceKeyTone(void);
#endif 

#if defined(__MMI_CUST_KEYPAD_TONE__)
extern U8 CanPlayCustKeyTone(void);
#endif 


#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
extern void CallBackPowerOnAnimationCompleteWrapper(void);
#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */ 


/*****************************************************************************
 * FUNCTION
 *  InitProcessKeyEvent
 * DESCRIPTION
 *  This function is used for inits the process key handler for preprocessing 
 *  and postprocessing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitProcessKeyEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_KEYS; i++)
    {
        nKeyPadStatus[i] = KEY_EVENT_UP;
        key_is_pressing_count = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_key_supported
 * DESCRIPTION
 *  query if specified key code is supported
 * PARAMETERS
 *  key_code    [IN]    key code (mmi_keypads_enum) to query
 * RETURNS
 *  key is supported or not
 *****************************************************************************/
MMI_BOOL mmi_frm_kbd_is_key_supported(S16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KEY_CSK == key_code)
    {
/* since CSK is software key, it depends on compile option */
#ifdef __MMI_WGUI_CSK_ENABLE__
        return MMI_TRUE;
#endif
    }
    else
    {
        for (i=0; i<MAX_KEYS; i++)
        {
            /* get corresponding device key code */
            if (nKeyPadMap[i].nMMIKeyCode == key_code)
            {
                return kbd_IsKeyButtonSupported((U8)nKeyPadMap[i].nKeyCode);
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_2step_keys
 * DESCRIPTION
 *  This function is used for gets the 2 step keys of handset.
 *  The function should be called in MMI_Init()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_get_2step_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 keymap_idx;    
    U8 _2step_key[MAX_KEYS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(_2step_key, 0, sizeof(U8) * MAX_KEYS);
    memset(g_2step_keyCode, 0, sizeof(U16) * MAX_KEYS);

    kbd_find_2step(&g_2step_key_num, _2step_key);

    for (i = 0; i < g_2step_key_num; i++)
    {
        keymap_idx = mmi_frm_get_idx_from_device_key_code((U16)_2step_key[i]);
        g_2step_keyCode[i] = nKeyPadMap[keymap_idx].nMMIKeyCode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetkeyInfo
 * DESCRIPTION
 *  This function is used for queries key code & key type of last key event.
 * PARAMETERS
 *  keyCode     [OUT]  The pointer to the Key Code.
 *  keyType     [OUT]  The pointer to the Key type.       
 * RETURNS
 *  void
 *****************************************************************************/
void GetkeyInfo(PU16 keyCode, PU16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *keyCode = currKeyCode;
    *keyType = currKeyType;
}


/*****************************************************************************
 * FUNCTION
 *  SetkeyInfo
 * DESCRIPTION
 *  This function is used for temporary sets key code & key type of last key event.
 * PARAMETERS
 *  keyCode     [IN]  Key to which this event is associated         
 *  keyType     [IN]  KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key 
 *                    is pressed or released      
 * RETURNS
 *  void
 *****************************************************************************/
void SetkeyInfo(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currKeyCode = keyCode;
    currKeyType = keyType;
}


/*****************************************************************************
 * FUNCTION
 *  GetKeyHandler
 * DESCRIPTION
 *  This function is used for gets the key event handler for current screen.
 * PARAMETERS
 *  keyCode     [IN]  Key to which this event is associated.       
 *  keyType     [IN]  What key type is wanted to query.       
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr GetKeyHandler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((keyCode < MAX_KEYS) && (keyType < MAX_KEY_TYPE));

    return (currKeyFuncPtrs[keyCode][keyType]);
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyHandler
 * DESCRIPTION
 *  This is used to sets the curent screen key handlers
 * PARAMETERS
 *  funcPtr     [IN] Function to be executed on occurrence of the event.      
 *  keyCode     [IN] Key to which this event is associated.      
 *  keyType     [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key 
 *                   is pressed or released       
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyHandler(FuncPtr funcPtr, U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETKEY_HDLR, keyCode, keyType, funcPtr);

    MMI_ASSERT((keyCode < MAX_KEYS) && (keyType < MAX_KEY_TYPE));


#ifndef __SENDKEY2_SUPPORT__
    currKeyFuncPtrs[keyCode][keyType] = funcPtr;
#else
	/*
	 * KEY_SEND means KEY_SEND1 and KEY_SEND2
	 * But the application could set the individual key handler in using KEY_SEND1 and KEY_SEND2
	 */
    if (keyCode == KEY_SEND1)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = funcPtr;
        currKeyFuncPtrs[KEY_SEND1][keyType] = funcPtr;
    }
    else if (keyCode == KEY_SEND2)
    {
        currKeyFuncPtrs[KEY_SEND2][keyType] = funcPtr;       
    }
    else if (keyCode == KEY_SEND)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = funcPtr;
        if (funcPtr != mmi_idle_dummy_key_handler)
        {
            currKeyFuncPtrs[KEY_SEND1][keyType] = funcPtr;
            currKeyFuncPtrs[KEY_SEND2][keyType] = funcPtr;
        }
    }
    else
    {
        currKeyFuncPtrs[keyCode][keyType] = funcPtr;
    }
#endif /* __SENDKEY2_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  SetGroupKeyHandler
 * DESCRIPTION
 *  This is used to sets the same key handler for a group of keycodes.
 * PARAMETERS
 *  funcPtr         [IN] Function to be executed on occurrence of the event.       
 *  keyCodes        [IN] Key array to which these events are associated.       
 *  len             [IN] The keyCodes array size.       
 *  keyType         [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                       key is pressed or released.       
 * RETURNS
 *  void
 *****************************************************************************/
void SetGroupKeyHandler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((len <= MAX_KEYS) && (keyType < MAX_KEY_TYPE));

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETGROUPKEY_HDLR, len, keyType, funcPtr);

    for (count = 0; count < len; count++)
    {        
        currKeyFuncPtrs[keyCodes[count]][keyType] = funcPtr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ClearKeyHandler
 * DESCRIPTION
 *  This function is used for clear the key event handler for current screen.
 * PARAMETERS
 *  keyCode     [IN] Key to which this event is associated.       
 *  keyType     [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, free the event associated 
 *                   with press or released state.       
 * RETURNS
 *  void
 *****************************************************************************/
void ClearKeyHandler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRKEY_HDLR, keyCode, keyType);

    MMI_ASSERT((keyCode < MAX_KEYS) && (keyType < MAX_KEY_TYPE));

    
#ifndef __SENDKEY2_SUPPORT__
    currKeyFuncPtrs[keyCode][keyType] = NULL;
#else
    /*
     * KEY_SEND means KEY_SEND1 and KEY_SEND2
     * But the application could set the individual key handler in using KEY_SEND1 and KEY_SEND2
     */
    if (keyCode == KEY_SEND1)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = NULL;
        currKeyFuncPtrs[KEY_SEND1][keyType] = NULL;
    }
    else if (keyCode == KEY_SEND2)
    {
        currKeyFuncPtrs[KEY_SEND2][keyType] = NULL;
    }
    else if (keyCode == KEY_SEND)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = NULL;
        currKeyFuncPtrs[KEY_SEND1][keyType] = NULL;
        currKeyFuncPtrs[KEY_SEND2][keyType] = NULL;
    }
    else
    {
        currKeyFuncPtrs[keyCode][keyType] = NULL;
    }
#endif /* __SENDKEY2_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  ClearAllKeyHandler
 * DESCRIPTION
 *  This function is used for clears all the key handlers associated with 
 *  current screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearAllKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRALLKEY_HDLR);

    memset(currKeyFuncPtrs, 0,  sizeof(currKeyFuncPtrs));

    PowerAndEndKeyHandler();

    SetDefaultVolumeKeyHandlers();
#ifdef __MMI_SUBLCD_MASTER_MODE__
    SetSubLCDMasterKeyHandler();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_goto_puk1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_goto_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* historyNode *History; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    DeleteUptoScrID(SCR_ID_SECSET_PUK1);
    if (GetHistoryScrID(SCR_ID_SECSET_PUK1, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, 2);
        }
    }
    */
    if (IsScreenPresent(SCR_ID_SECSET_PUK_CONFIRM_PIN1))
    {
        DeleteUptoScrID(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
    }
    else if (IsScreenPresent(SCR_ID_SECSET_PUK_NEW_PIN1))
    {
        DeleteUptoScrID(SCR_ID_SECSET_PUK_NEW_PIN1);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_SECSET_PUK1);
    }
    GoBackHistory();
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_secset_goto_sim2_pin1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_goto_sim2_pin1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* historyNode *History; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ENTERSLAVEPIN);
    /*
    if (GetHistoryScrID(SCR_ENTERSLAVEPIN, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, 2);
        }
    }
    */
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_goto_sim2_puk1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_secset_goto_sim2_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* historyNode *History; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    DeleteUptoScrID(SCR_CARD2_ENTER_PUK);
    if (GetHistoryScrID(SCR_CARD2_ENTER_PUK, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, 2);
        }
    }
    MTPNP_PFAL_Clear_CHV_Input_Pwd();
    */
    if (IsScreenPresent(SCR_CARD2_ENTER_CONFIRM_PIN))
    {
        DeleteUptoScrID(SCR_CARD2_ENTER_CONFIRM_PIN);
    }
    else if (IsScreenPresent(SCR_CARD2_ENTER_NEW_PIN))
    {
        DeleteUptoScrID(SCR_CARD2_ENTER_NEW_PIN);
    }
    else
    {
        DeleteUptoScrID(SCR_CARD2_ENTER_PUK);
    }
    GoBackHistory();
}

#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  PowerAndEndKeyHandler
 * DESCRIPTION
 *  This function is used for sets power key & end key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PowerAndEndKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /**
    * The end key must not be registered to
    * Go to IDle screen in case any call exists on the
    * the phone. This is a temporary solution for fixing the
    * CM bugs
    */
    if (isInCall() && !GetWapCallPresent())
    {
#ifdef __MMI_UCM__
        if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
        {
            currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_ucm_end_all_action;
        }
#else /* __MMI_UCM__ */
#ifdef __MMI_VOIP__
        if (GetTotalCallCount() != 0) /* disconnect gsm call */
        {
            currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = HangupAllCalls;
        }
        else if (mmi_voip_app_total_call() != 0) /* disconnect voip call */
        {
            currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_voip_entry_ans_to_disconn_voip;
        }
#else /* __MMI_VOIP__ */
        currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = HangupAllCalls;
#endif /* __MMI_VOIP__ */
#endif /* __MMI_UCM__ */
    }
    else
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (mmi_bootup_is_in_security_check() == MMI_FALSE && mmi_bootup_is_in_sim2_security_check() == MMI_FALSE)
    #else
        if (mmi_bootup_is_in_security_check() == MMI_FALSE)
    #endif
        {
            /**
            * The end key should end all the existing calls
            *  and screen should be the last screen thru call menu.
            */
            #ifdef __MMI_EMAIL__
                if (mmi_email_util_get_stop_cause() == EMAIL_MODULE_ACTIVE_NOW)
                {
                    currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_email_main_goto_idle;
                }
                else
            #endif /* __MMI_EMAIL__ */ 
            #ifdef __MMI_DUAL_SIM_MASTER__
                if (!gSecuritySetupContext.PINBlocked && !gSecuritySetupContext.PINBlocked_2)
            #else
                if (!gSecuritySetupContext.PINBlocked)
            #endif
                {
                    currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = DisplayIdleScreen;
                }
            #ifdef __MMI_DUAL_SIM_MASTER__
                else if (gSecuritySetupContext.PINBlocked && !gSecuritySetupContext.PINBlocked_2)
                {
                    currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_secset_goto_puk1;
                }
                else if (!gSecuritySetupContext.PINBlocked && gSecuritySetupContext.PINBlocked_2)
                {
                    currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_secset_goto_sim2_puk1;
                }
            #else /* __MMI_DUAL_SIM_MASTER__ */
                else
                {
                    currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_secset_goto_puk1;
                }
            #endif /* __MMI_DUAL_SIM_MASTER__ */
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (mmi_bootup_is_in_security_check() == MMI_FALSE && mmi_bootup_is_in_sim2_security_check() == MMI_TRUE)
        {
            if (!gSecuritySetupContext.PINBlocked_2)
            {
                currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_secset_goto_sim2_pin1;
            }
            else
            {
                currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = mmi_secset_goto_sim2_puk1;
            }
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }

#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
    if (DirectMode)
    {
        currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN] = CallBackPowerOnAnimationCompleteWrapper;
    }
#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */ 

    if (!g_keylock_context.gKeyPadLockFlag)
    {
        mmi_frm_set_default_power_onoff_key();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_idx_from_device_key_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  DeviceKeyCode   [IN]   The device key code.
 * RETURNS
 *  U16
 *****************************************************************************/
 U16 mmi_frm_get_idx_from_device_key_code(U16 DeviceKeyCode)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = 0; i < MAX_KEYPADMAP; i++)
    {
        if (DeviceKeyCode == nKeyPadMap[i].nKeyCode)
        {
            return i;
        }
    }

    /* We return 0, if can't find the matched key code */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKeyEvent
 * DESCRIPTION
 *  To send the key events to MMI task
 * PARAMETERS
 *  MsgType         [IN]   KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                         key is pressed or released.      
 *  DeviceKeyCode   [IN]   The device key code
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessKeyEvent(U32 MsgType, U16 DeviceKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL isKeyPaired;
    U16      KeyMapIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    KeyMapIndex = mmi_frm_get_idx_from_device_key_code(DeviceKeyCode);
    
    MMI_ASSERT(nKeyPadMap[KeyMapIndex].nMMIKeyCode != KEY_INVALID);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_PROC_KEYEVENT_HDLR, nKeyPadStatus[prevKeyMapIndex], nKeyPadMap[KeyMapIndex].nMMIKeyCode);

    if (KeyMapIndex >= MAX_KEYS)
    {
        /*
         * Driver has supported QWERTY key pad on W07.41 main-trunk & 07B. But MMI isn't ready.
         * So temporarily add these code to avoid related mistake. 
         */
        return;
    }

    #ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsClamClose() && nKeyPadMap[KeyMapIndex].nMMIKeyCode == KEY_END)
    {
        /*
         * When the clam is closed, the users should not press KEY_END.
         * If hardware mechanism is not good enough, we discard KEY_END here.
         */
        return;
    }
    #endif

    if (MsgType == WM_KEYPRESS)
    {
        /* check if key event is paired when key code changed, except in concurrent key mode */
        if ((KeyMapIndex != prevKeyMapIndex) && (g_kbd_concurrent_key_mode == CONCURRENT_KEY_MODE_1_KEY))
        {
            isKeyPaired = (nKeyPadStatus[prevKeyMapIndex] == KEY_EVENT_UP);
        
            /* if ASSERT here, please ask driver guys for help to make sure key is paired */
            EXT_ASSERT(isKeyPaired, 
                        nKeyPadMap[KeyMapIndex].nMMIKeyCode,     /* current key code */
                        nKeyPadMap[prevKeyMapIndex].nMMIKeyCode, /* previous key code */
                        nKeyPadStatus[prevKeyMapIndex]);         /* previous key status */
            prevKeyMapIndex = KeyMapIndex;
        }
    
        if (nKeyPadStatus[KeyMapIndex] == KEY_EVENT_UP)
        {

            KEYBRD_MESSAGE KeyBrdMsg;

            KeyBrdMsg.nKeyCode = nKeyPadMap[KeyMapIndex].nMMIKeyCode;
            if (mmi_frm_is_2step_keyCode(KeyBrdMsg.nKeyCode))
            {
                nKeyPadStatus[KeyMapIndex] = KEY_HALF_PRESS_DOWN;
                key_is_pressing_count++;
                KeyBrdMsg.nMsgType = KEY_HALF_PRESS_DOWN;
            }
            else
            {
                nKeyPadStatus[KeyMapIndex] = KEY_EVENT_DOWN;    /* same with KEY_FULL_PRESS_DOWN */
                key_is_pressing_count++;
                KeyBrdMsg.nMsgType = KEY_EVENT_DOWN;
            }
            KeyEventHandler((KEYBRD_MESSAGE*) & KeyBrdMsg);

        }
        else
        {
            /* Ignore the event */
        }
    }

    else if (MsgType == WM_KEYRELEASE)
    {
        if ((nKeyPadStatus[KeyMapIndex] == KEY_EVENT_DOWN)
            || (nKeyPadStatus[KeyMapIndex] == KEY_LONG_PRESS)
            || (nKeyPadStatus[KeyMapIndex] == KEY_REPEAT) || (nKeyPadStatus[KeyMapIndex] == KEY_HALF_PRESS_DOWN))
        {

            KEYBRD_MESSAGE KeyBrdMsg;

            nKeyPadStatus[KeyMapIndex] = KEY_EVENT_UP;
            key_is_pressing_count--;
            KeyBrdMsg.nMsgType = KEY_EVENT_UP;
            KeyBrdMsg.nKeyCode = nKeyPadMap[KeyMapIndex].nMMIKeyCode;
            KeyEventHandler((KEYBRD_MESSAGE*) & KeyBrdMsg);

        }
        else
        {
            /* Ignore the event */
        }
    }
    /* ++Robin, modified by Max Chen */
    else if (MsgType == DRV_WM_KEYLONGPRESS)
    {
        if (nKeyPadStatus[KeyMapIndex] == KEY_EVENT_DOWN)
        {
            KEYBRD_MESSAGE KeyBrdMsg;

            nKeyPadStatus[KeyMapIndex] = KEY_LONG_PRESS;
            KeyBrdMsg.nMsgType = KEY_LONG_PRESS;
            KeyBrdMsg.nKeyCode = nKeyPadMap[KeyMapIndex].nMMIKeyCode;
            KeyEventHandler((KEYBRD_MESSAGE*) & KeyBrdMsg);
        }
        else
        {
            /* Ignore the event */
        }
    }
    else if (MsgType == DRV_WM_KEYREPEATED)
    {
        if ((nKeyPadStatus[KeyMapIndex] == KEY_LONG_PRESS) || (nKeyPadStatus[KeyMapIndex] == KEY_REPEAT))
        {
            KEYBRD_MESSAGE KeyBrdMsg;

            nKeyPadStatus[KeyMapIndex] = KEY_REPEAT;
            KeyBrdMsg.nMsgType = KEY_REPEAT;
            KeyBrdMsg.nKeyCode = nKeyPadMap[KeyMapIndex].nMMIKeyCode;
            KeyEventHandler((KEYBRD_MESSAGE*) & KeyBrdMsg);
        }
        else
        {
            /* Ignore the event */
        }
    }
    else if (MsgType == DRV_WM_KEYFULLPRESS)
    {
        /*
         * Only in two-stage key will have KEY_FULL_PRESS_DOWN, and it followed after KEY_HALF_PRESS_DOWN
         */
        if (nKeyPadStatus[KeyMapIndex] == KEY_HALF_PRESS_DOWN)
        {
            KEYBRD_MESSAGE KeyBrdMsg;

            nKeyPadStatus[KeyMapIndex] = KEY_EVENT_DOWN;
            KeyBrdMsg.nMsgType = KEY_EVENT_DOWN;
            KeyBrdMsg.nKeyCode = nKeyPadMap[KeyMapIndex].nMMIKeyCode;
            KeyEventHandler((struct KEYBRD_MESSAGE*)&KeyBrdMsg);
        }
        else
        {
            /* Ignore the event */
        }
    }
    else if ((MsgType == DRV_WM_ENABLE_TWOKEY_DETECTION) || (MsgType == DRV_WM_ENABLE_THREEKEY_DETECTION) ||
                (MsgType == DRV_WM_DISABLE_MULTIKEY_DETECTION))
    {
        /* Ignore the event */
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_PROC_KEYEVENT_HDLR);

        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExecuteCurrKeyHandler
 * DESCRIPTION
 *  This function is used for executes current key function handler only. 
 *  This function won't execute pre key handler and post key handler.
 * PARAMETERS
 *  keyCode     [IN]    Key to which this event is associated.     
 *  keyType     [IN]    KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                      key is pressed or released.      
 * RETURNS
 *  void
 *****************************************************************************/
void PlayKeyEnterBacklightTimes(int times);
void ExecuteCurrKeyHandler(S16 keyCode, S16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    int flag = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_restart_keypad_lock_timer();   /* 2006/01/16 Restart keypad lock timer if any key is pressed in idle screen */

/* 2009.07.20 added by hongzhe.liu for keyenter backlight + */
#ifdef KEY_ENTER_BACKLIGHT_SUPPORT
#ifdef NO_LSK
	if(keyCode == KEY_ENTER || keyCode == KEY_LSK )
#else
	if(keyCode == KEY_ENTER )
#endif
	{
		if( keyType == KEY_EVENT_DOWN )
		{
			PlayKeyEnterBacklight(KEY_ENTER_BK_LIGHT_ALL_ON);
		}else if( keyType == KEY_EVENT_UP ){
			PlayKeyEnterBacklight(KEY_ENTER_BK_LIGHT_CIRCLE);
		}else{
			PlayKeyEnterBacklight(KEY_ENTER_BK_LIGHT_ALL_OFF);
		}
	}
#endif
/* 2009.07.20 added by hongzhe.liu for keyenter backlight - */

#if defined (__MMI_SUBLCD_MASTER_MODE__) 
    if (IsClamClose())
    {
        if (IsSubLCDInMasterMode())
        {
            if (keyType > KEY_EVENT_DOWN)
            {
                if (CurrSubLCDScrnID != GetSubLCActiveScreenId())
                {
                    return;
                }
            }
            else
            {
                CurrSubLCDScrnID = GetSubLCActiveScreenId();
            }
        }
        else
        {
            CurrSubLCDScrnID = 0;
        }
    }
#endif /* __MMI_SUBLCD_MASTER_MODE__ */ 

    currKeyCode = keyCode;
    currKeyType = keyType;

    /* Added for Help */
    /*
     * if(gIsHelpEnabled != 0)
     * {
     * StopTimer(HELP_APPLICATION_TIMER);
     * StartTimer(HELP_APPLICATION_TIMER,HELP_APPLICATION_TIMEOUT,ShowHelp);
     * }
     */
    if (!gEmerencyNoDialed)
    {
        if (mmi_kbd_get_concurrent_mode() == MMI_FALSE)
        {
            /* special handling for single-key mode */
            switch (keyType)
            {
                case KEY_HALF_PRESS_DOWN:
                    pressKey = HALF_DOWN_STATUS;   /* 0- full up, 1- half down, 2- full down */
                    break;
                case KEY_EVENT_DOWN:
                    /* 
                     * The application may call ExecuteCurrKeyHandler() directly 
                     * MMI framework use KEY_HALF_PRESS_DOWN or KEY_FULL_PRESS_DOWN only
                     */
                    pressKey = FULL_DOWN_STATUS;   /* 0- full up, 1- half down, 2- full down */
                    processUpRepeatKey = MMI_TRUE;
                    break;
                case KEY_REPEAT:
                    if (!processUpRepeatKey)
                    {
                        return;
                    }
                    break;
                case KEY_EVENT_UP:
                    if (pressKey == FULL_UP_STATUS)
                    {
                        /* processUpRepeatKey=0; */
                        mmi_frm_reset_internal_key_contex();
                        return;
                    }
                    break;
            }
        }

        currFuncPtr = currKeyFuncPtrs[keyCode][keyType];

#if defined(__SENDKEY2_SUPPORT__) && defined(NO_LSK)
	if((keyCode == KEY_LSK) && ( currKeyFuncPtrs[KEY_SEND1][keyType] != NULL ) )
	{
	        currFuncPtr = currKeyFuncPtrs[KEY_SEND1][keyType];
	}
#endif

        /* MTK Leo add, if there is no handler for center key(KEY_ENTER) registered by APP, use LSK function. */
        if (keyCode == KEY_ENTER && currFuncPtr == NULL)
        {
            /* If any one type of the key eventis registered by APP, we assume APP want to control this key by itself. */
            if (currKeyFuncPtrs[KEY_ENTER][KEY_EVENT_UP] == NULL &&
                currKeyFuncPtrs[KEY_ENTER][KEY_EVENT_DOWN] == NULL &&
                currKeyFuncPtrs[KEY_ENTER][KEY_HALF_PRESS_DOWN] == NULL &&
                currKeyFuncPtrs[KEY_ENTER][KEY_REPEAT] == NULL && currKeyFuncPtrs[KEY_ENTER][KEY_LONG_PRESS] == NULL)

            {
                currFuncPtr = currKeyFuncPtrs[KEY_LSK][keyType];
            }
        }
        /* MTK Leo end. */

        if ((keyType == KEY_REPEAT) && (currFuncPtr == NULL) && (keyCode != KEY_RSK) && (keyCode != KEY_LSK))   /* 20040906 Disable repeat for LSK and RSK */
        {
            currFuncPtr = currKeyFuncPtrs[keyCode][KEY_EVENT_DOWN];
        }

    #ifdef __MMI_WGUI_MINI_TAB_BAR__
        if (wgui_if_mini_tab_bar_enable() == MMI_TRUE && keyCode == KEY_LEFT_ARROW && keyType == KEY_EVENT_DOWN)
        {
            currFuncPtr = wgui_mini_tab_bar_goto_prev;
        }

        if (wgui_if_mini_tab_bar_enable() == MMI_TRUE && keyCode == KEY_RIGHT_ARROW && keyType == KEY_EVENT_DOWN)
        {
            currFuncPtr = wgui_mini_tab_bar_goto_next;
        }
    #endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 

    #ifdef __MMI_SCREEN_SNAPSHOT__
        if ((keyType == KEY_LONG_PRESS) && (keyCode == KEY_CAMERA) && (currFuncPtr == NULL))
        {
            currFuncPtr = mmi_camera_scr_snapshot;
        }
    #endif /* __MMI_SCREEN_SNAPSHOT__ */ 

        if (mmi_kbd_get_concurrent_mode() == MMI_FALSE)
        {
            if (keyType == KEY_EVENT_UP)
            {
                /* release the key */
                if (pressKey == 1)  /* 0- full up, 1- half down, 2- full down */
                {
                    currFuncPtr = currKeyFuncPtrs[keyCode][KEY_HALF_PRESS_UP];
                }
                else if ((pressKey == 2) && (currKeyFuncPtrs[keyCode][KEY_HALF_PRESS_UP] != NULL))
                {
                    /* If KEY_EVENT_UP in 2-stage full-pressed key, need call KEY_HALF_PRESS_UP handler first */
                    currKeyFuncPtrs[keyCode][KEY_HALF_PRESS_UP] ();
                }
                /* special handling for single-key mode */
                mmi_frm_reset_internal_key_contex();
            }
        }
#ifdef __LSK_KEYSEND2_IN_ONE__
        if(MTPNP_PFAL_CC_GetIsKeyForCall())
        {
            if(keyCode == KEY_LSK)
            {
                MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
	            MTPNP_PFAL_CC_SetDialFromLSK(MTPNP_TRUE);
                if((MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD2_USABLE))
                {
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
		            currFuncPtr = currKeyFuncPtrs[KEY_SEND][MTPNP_PFAL_CC_GetSendEventType()];
                }
            else if(MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE)
            {
               MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
               currFuncPtr = currKeyFuncPtrs[KEY_SEND][MTPNP_PFAL_CC_GetSendEventType()];
            }
        }
	 }
	 kal_prompt_trace(MOD_MMI,"ExecuteCurrKeyHandler keyforcall = %d",MTPNP_PFAL_CC_GetIsKeyForCall());
#endif/*__LSK_KEYSEND2_IN_ONE__*/
        if (currFuncPtr)
        {
        #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
            g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
        #endif

            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURKEY_KEYCODE_HDLR,currFuncPtr, keyCode, keyType);
            (*currFuncPtr)();

        }
    }
    else
    {
        gEmerencyNoDialed = 0;
    }
}


#ifdef __MMI_SUBLCD_MASTER_MODE__
/*****************************************************************************
 * FUNCTION
 *  SwitchKeyFuncPtrs
 * DESCRIPTION
 *  This function is used for switch KeyFuncPtrs for sublcd master mode.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void SwitchKeyFuncPtrs(void) 
{
    S32 i = 0, j = 0;
    if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
    {
        for (i = 0; i < MAX_KEYS; i++)
        {
            for (j = 0; j < MAX_KEY_TYPE; j++)
            {
                currKeyFuncPtrs_slave[i][j] = currKeyFuncPtrs[i][j];
                currKeyFuncPtrs[i][j] = currKeyFuncPtrs_master[i][j];
            }
        }
    }
    else if (g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        for (i = 0; i < MAX_KEYS; i++)
        {
            for (j = 0; j < MAX_KEY_TYPE; j++)
            {
                currKeyFuncPtrs_master[i][j] = currKeyFuncPtrs[i][j];
                currKeyFuncPtrs[i][j] = currKeyFuncPtrs_slave[i][j];
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}
#endif /* __MMI_SUBLCD_MASTER_MODE__ */


/*****************************************************************************
 * FUNCTION
 *  InitKeypadBeforePWRON
 * DESCRIPTION
 *  This function is used for initializes keypad before power on.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitKeypadBeforePWRON(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(KeyHandleBeforePWRON, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  KeyHandleBeforePWRON
 * DESCRIPTION
 *  This function is used for detects key presses before power on.
 * PARAMETERS
 *  paraBuff        [IN]   The pointer to the parameter buffer.     
 * RETURNS
 *  void
 *****************************************************************************/
void KeyHandleBeforePWRON(void *paraBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_keypad_detect_ind_struct *p;
    kbd_data k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (mmi_eq_keypad_detect_ind_struct*) paraBuff;

    while ((*(p->func)) (&k) == KAL_TRUE);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_convert_process_key_event
 * DESCRIPTION
 *  This function is used for converts the driver key event type to MMI key event type
 *  and process the key event
 * PARAMETERS
 *  Keyevent        [IN]   The key event.     
 *  DeviceKeyCode   [IN]   The device key code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_convert_process_key_event(U32 Keyevent, U16 DeviceKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INTERACTIVE_PROFILNG__
    if (Keyevent == WM_KEYPRESS)
    {
        mmi_frm_profiling_interactive_start3();
    }
    else if (Keyevent == WM_KEYRELEASE)
    {
        mmi_frm_profiling_interactive_start2();
    }
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

#ifdef __MMI_SCREEN_ROTATE__
    DeviceKeyCode = get_rotated_key(Keyevent, DeviceKeyCode);
#endif /* __MMI_SCREEN_ROTATE__ */ 

    ProcessKeyEvent(Keyevent, DeviceKeyCode);

#ifdef __MMI_INTERACTIVE_PROFILNG__
    if (Keyevent == WM_KEYPRESS)
    {
        mmi_frm_profiling_interactive_end3();
    }
    else if (Keyevent == WM_KEYRELEASE)
    {
        mmi_frm_profiling_interactive_end2();
        mmi_frm_profiling_interactive_show((U8*) L"K", MMI_FRM_PROFILING_MASK_2 | MMI_FRM_PROFILING_MASK_3);
    }
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_handle_in_high_frequency
 * DESCRIPTION
 *  This function is used for process the keypad handler in high frequency mode.
 * PARAMETERS
 *  is_enable       [IN]   Is enable high frequency mode or not.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_key_handle_in_high_frequency(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_process_key_in_high_frequency = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_handle
 * DESCRIPTION
 *  This function is used for process the keypad handler.
 * PARAMETERS
 *  paraBuff        [IN]  The pointer to the parameter buffer.        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_handle(void *paraBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kbd_data k;
    U32 msg_count;
    mmi_eq_keypad_detect_ind_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (paraBuff != NULL)
    {
        drv_get_key_func new_key_ptr;

        p = (mmi_eq_keypad_detect_ind_struct*) paraBuff;

        new_key_ptr = (drv_get_key_func) (p->func);
		MMI_ASSERT(new_key_ptr != NULL);
        if (new_key_ptr != keypad_ptr)
        {
            if (!mmi_kbd_process_keyptr_change((void *)new_key_ptr))
            {
                /* no further key to process, just return */
                return;
            }       
            ClearKeyEvents();
            keypad_ptr = new_key_ptr;
        }
    }

    while (1)
    {
        if ((*(keypad_ptr)) (&k) == MMI_TRUE)
        {
            if (k.Keydata[0] != KEY_INVALID)
            {
                static U8 is_allow_key_action = MMI_TRUE;

            #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
                kal_bool is_pen_enabled, is_pen_down;

                mmi_pen_get_state(&is_pen_enabled, &is_pen_down);
            #endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

            #if defined(__MMI_SLEEP_OUT_BACKLIGHT_ON__)
                if ((IsBacklightOn() == MMI_FALSE) && (k.Keyevent == WM_KEYPRESS))
                {
                    mmi_idle_key_event_backlight_check();
                    /* only allow key action when backlight is controlled by AP */
                    if (mmi_gpio_get_backlight_timer_state() == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)
                        is_allow_key_action = MMI_TRUE;
                    else
                        is_allow_key_action = MMI_FALSE; 
                }
            #endif /* defined(__MMI_SLEEP_OUT_BACKLIGHT_ON__) */ 

            #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
                if (is_pen_down && (k.Keyevent == WM_KEYPRESS))
                {
                    is_allow_key_action = MMI_FALSE;
                }
                else
            #endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
                if ((k.Keyevent == WM_KEYRELEASE) && (is_allow_key_action == MMI_FALSE))
                {
                    is_allow_key_action = MMI_TRUE;
                }
                else if (is_allow_key_action == MMI_TRUE)
                {
                    if ((k.Keyevent == WM_KEYPRESS) && (mmi_kbd_get_key_is_pressing_count() == 0))
                    {
                    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
                        mmi_pen_disable();
                    #endif
                    
                    /* keypad is pressed, disable BT key processing */
                    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)
                        mmi_bt_avrcp_frm_sync_calllback(MMI_TRUE);
                    #endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) */
                    }
                    mmi_frm_convert_process_key_event(k.Keyevent, k.Keydata[0]);

                    if ((k.Keyevent == WM_KEYRELEASE) && (mmi_kbd_get_key_is_pressing_count() == 0))
                    {
                    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
                        mmi_pen_enable();
                    #endif
                    
                    /* keypad is released, enable BT key processing */
                    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)
                        mmi_bt_avrcp_frm_sync_calllback(MMI_FALSE);
                    #endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) */
                    }
                }
            }

            msg_get_ext_queue_info(mmi_ext_qid, &msg_count);
            if (msg_count > 0 || OslNumOfCircularQMsgs() > 0)
            {
                g_keypad_flag = MMI_TRUE;
                break;
            }
        }
        else
        {
            g_keypad_flag = MMI_FALSE;
            break;
        }
    }   /* while(1) */
}


/*****************************************************************************
 * FUNCTION
 *  StopCurrentKeyPadTone
 * DESCRIPTION
 *  This function is used for stops current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopCurrentKeyPadTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currKeyPadTone != 0xFFFF)
    {
        AudioStopReq(currKeyPadTone);
        currKeyPadTone = 0xFFFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ClearKeyEvents
 * DESCRIPTION
 *  This function is used for clears Keyboard buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearKeyEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern drv_get_key_func keypad_ptr;
    kbd_data k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_CLEAR_KEY_EVENTS_HDLR);

    if (keypad_ptr != NULL)
    {
        while ((*(keypad_ptr)) (&k) == KAL_TRUE)
        {
            /* restore state of keys */
            if (k.Keydata[0] != KEY_INVALID)
            {
#ifdef __MMI_SCREEN_ROTATE__
                k.Keydata[0] = get_rotated_key(k.Keyevent, k.Keydata[0]);
#endif             
                mmi_kbd_reset_key_state(k.Keyevent, k.Keydata[0]);
            }
        }
    }
    processUpRepeatKey = 0;
    pressKey = 0;   /* 0- full up, 1- half down, 2- full down */
    StopCurrentKeyPadTone();

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    /*
     * We disable pen on key down and enable pen on key up. 
     * * If key down and key up events are not paired, pen is not enabled again.
     */
    mmi_pen_enable();
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

/* keypad is released, enable BT key processing */
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)
    mmi_bt_avrcp_frm_sync_calllback(MMI_FALSE);
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) */
}

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)


/*****************************************************************************
 * FUNCTION
 *  GetHumanVoiceToneID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMIKeyCode      [IN]   Key code of MMI     
 * RETURNS
 *  
 *****************************************************************************/
S16 GetHumanVoiceToneID(S16 MMIKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 keypad_tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keypad_tone_type >= KEYPAD_TONE_HUMAN_VOICE_1 && keypad_tone_type <= KEYPAD_TONE_HUMAN_VOICE_6)
    {
        if (!CanPlayHumanVoiceKeyTone())
        {
            return -1;
        }
        if (MMIKeyCode >= KEY_0 && MMIKeyCode <= KEY_9)
        {
            i = MMIKeyCode - KEY_0;
        }
        else if (MMIKeyCode == KEY_STAR)
        {
            i = 10;
        }
        else if (MMIKeyCode == KEY_POUND)
        {
            i = 11;
        }
        else
        {
            i = -1;
        }

        if (i >= 0)
        {
            return (S16) ((keypad_tone_type - KEYPAD_TONE_HUMAN_VOICE_1) * 13 + i + MIN_HUMAN_VOICE_ID);
        }
    }
    return -1;
}
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

#if defined(__MMI_CUST_KEYPAD_TONE__)


/*****************************************************************************
 * FUNCTION
 *  GetCustKeyPadToneID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMIKeyCode      [IN]  Key code of MMI      
 * RETURNS
 *  
 *****************************************************************************/
S16 GetCustKeyPadToneID(S16 MMIKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 keypad_tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keypad_tone_type >= KEYPAD_TONE_CUST_1 && keypad_tone_type <= KEYPAD_TONE_CUST_6)
    {
        if (!CanPlayCustKeyTone())
        {
            return -1;
        }
        return (S16) (keypad_tone_type - KEYPAD_TONE_CUST_1 + MIN_KEYPAD_TONE_ID);
    }
    return -1;
}
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 


/*****************************************************************************
 * FUNCTION
 *  GetKeypadTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMIKeyCode      [IN]    Key code of MMI    
 * RETURNS
 *  the ID of key pad tone.
 *****************************************************************************/
U16 GetKeypadTone(S16 MMIKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_found = MMI_FALSE;
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CUST_KEYPAD_TONE__)
    if ((i = GetCustKeyPadToneID(MMIKeyCode)) >= 0)
    {
        return (U16) i;
    }
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    /* MTK added by Tim for human voice keypad tone */
    if ((i = GetHumanVoiceToneID(MMIKeyCode)) >= 0)
    {
        return (U16) i;
    }
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

    for (i = 0; i < MAX_KEYPADMAP; i++)
    {
        if (MMIKeyCode == nKeyPadMap[i].nMMIKeyCode)
        {
            is_found = MMI_TRUE;
            break;
        }
    }

    MMI_ASSERT(is_found == MMI_TRUE);

    return (U16) nKeyPadMap[i].KeyPadTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurKeypadTone
 * DESCRIPTION
 *  This function is used for queries the current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the keypad tone enum. Refer audio_id_enum.
 *****************************************************************************/
U16 GetCurKeypadTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currKeyPadTone;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurKeypadTone
 * DESCRIPTION
 *  This function is used for sets the current keypad tone.
 * PARAMETERS
 *  KeyTone     [IN]  the keypad tone enum. Refer audio_id_enum.      
 * RETURNS
 *  Always returns MMI_TURE.  
 *****************************************************************************/
U8 SetCurKeypadTone(U16 KeyTone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currKeyPadTone = KeyTone;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  GetKeypadDuration
 * DESCRIPTION
 *  This function is used for queries the current keypad duration.
 * PARAMETERS
 *  MMIKeyCode      [IN]    Key code of MMI    
 * RETURNS
 *  The current keypad duration.
 *****************************************************************************/
U8 GetKeypadDuration(S16 MMIKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_found = MMI_FALSE;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CUST_KEYPAD_TONE__)
    if (GetCustKeyPadToneID(MMIKeyCode) >= 0)
    {
        return DEVICE_AUDIO_PLAY_ONCE;
    }
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    /* MTK added by Tim for human voice keypad tone */
    if (GetHumanVoiceToneID(MMIKeyCode) >= 0)
    {
        return DEVICE_AUDIO_PLAY_ONCE;
    }
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

    for (i = 0; i < MAX_KEYPADMAP; i++)
    {
        if (MMIKeyCode == nKeyPadMap[i].nMMIKeyCode)
        {
            is_found = MMI_TRUE;
            break;
        }
    }
    MMI_ASSERT(is_found == MMI_TRUE);

    /* return KeyToneMap[KeyCode].KeyPadDuration; */
    return nKeyPadMap[i].KeyPadDuration;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbd_reverse_code
 * DESCRIPTION
 *  This function is used for reversly get the key code of L4/Driver.
 * PARAMETERS
 *  mmi_key_code        [IN]        Key code of MMI
 * RETURNS
 *  key code of L4/Driver
 *****************************************************************************/
S16 mmi_kbd_reverse_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_found = MMI_FALSE;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_KEYPADMAP; i++)
    {
        if (mmi_key_code == nKeyPadMap[i].nMMIKeyCode)
        {
            is_found = MMI_TRUE;
            break;
        }
    }
    MMI_ASSERT(is_found == MMI_TRUE);

#if 0
    /* in current disign, keycode is equavlent to key code */
    MMI_ASSERT(i == nKeyPadMap[i].nKeyCode);
#endif

    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "mmi_kbd_reverse_code: return %d \n", nKeyPadMap[i].nKeyCode);

    return (nKeyPadMap[i].nKeyCode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbd_process_keyptr_change
 * DESCRIPTION
 *  This function is used for process get-key-ptr change.
 * PARAMETERS
 *  new_key_ptr [IN]    - new get-key pointer
 * RETURNS
 *  if returns MMI_FALSE, no key has to handle further.
 *****************************************************************************/
MMI_BOOL mmi_kbd_process_keyptr_change(void* new_key_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    kbd_data k;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* HW -> +CKPD key. */
    /* if (1) key buffer isn't empty or (2) HW key is pressed, drop all +CKPD keys */
    if ((g_keypad_flag || (nKeyPadStatus[prevKeyMapIndex] != KEY_EVENT_UP))&& 
        ((drv_get_key_func)new_key_ptr == (drv_get_key_func)KBD_ATCMD_GET_KEY_FUNC))
    {
        while(((drv_get_key_func)new_key_ptr)(&k) == MMI_TRUE);   
        return MMI_FALSE; 
    }

    /* +CKPD -> HW key. clear all key status */
    if (keypad_ptr == (drv_get_key_func)KBD_ATCMD_GET_KEY_FUNC)
    {
        for (i=0; i<MAX_KEYS; i++)
        {
            nKeyPadStatus[i] = KEY_EVENT_UP;
        }
        key_is_pressing_count = 0;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbd_reset_key_state
 * DESCRIPTION
 *  This function is used for sets the keypad state according corrent key event.
 *  But keypad handler is not executed.
 * PARAMETERS
 *  MsgType         [IN]        Type of key event
 *  DeviceKeyCode     [IN]      Device key code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_kbd_reset_key_state(U32 MsgType, U16 DeviceKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 KeyMapIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KeyMapIndex = mmi_frm_get_idx_from_device_key_code(DeviceKeyCode);
 
    if (MsgType == WM_KEYPRESS)
    {
        nKeyPadStatus[KeyMapIndex] = KEY_EVENT_DOWN;
        key_is_pressing_count++;
    }
    else if (MsgType == WM_KEYRELEASE)
    {
        nKeyPadStatus[KeyMapIndex] = KEY_EVENT_UP;
        key_is_pressing_count--;
    }
    /*
     * else 
     * others won't change key state.
     */
}


/*****************************************************************************
 * FUNCTION
 *  GetMaxPresentAllKeys
 * DESCRIPTION
 *  This function is used for gets all MMI keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetMaxPresentAllKeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MAX_PRESENTALLKEYS;
}


/*****************************************************************************
 * FUNCTION
 *  GetMaxPresentDigitsKeys
 * DESCRIPTION
 *  This function is used for gets all MMI digits keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetMaxPresentDigitsKeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MAX_PRESENTDIGITSKEYS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_set_tone_state
 * DESCRIPTION
 *  This function is used for chages the state of keypad tone.
 *  To prevent abnormal cases, keypad tone will be stopped before state changed.
 * PARAMETERS
 *  state       [IN]  Keypad tone state that want to be changed      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* not stop original keypage tone. next key tone is able to stop previous tone if still exist */ 
    // StopCurrentKeyPadTone();

    frm_p->key_tone_state = state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_get_key_tone_state
 * DESCRIPTION
 *  This function is used for gets the state to see if keypad tone is disabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the key pad tone state. Refer mmi_frm_kbd_tone_state_enum.
 *****************************************************************************/
mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return frm_p->key_tone_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_pre_key_hdlr
 * DESCRIPTION
 *  This function is used for regiester function to execute before general 
 *  keypad handler.
 * PARAMETERS
 *  func        [IN]  Pre-Key handler      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_reg_pre_key_hdlr(PsKeyProcessCBPtr func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    frm_p->kbd_pre_func = func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_post_key_hdlr
 * DESCRIPTION
 *  This function is used for register function to execute after general 
 *  keypad handler.
 * PARAMETERS
 *  func        [IN]  Post-Key handler     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_reg_post_key_hdlr(PsKeyProcessCBPtr func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    frm_p->kbd_post_func = func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_tone_enabled
 * DESCRIPTION
 *  This function is used for checks if keypad tone can be played or not.
 * PARAMETERS
 *  key_code        [IN]   Key to which this event is associated.
 *  key_type        [IN]   KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                         key is pressed or released.
 * RETURNS
 *  TRUE if the keypad tone shall be played by framework; otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_frm_kbd_is_tone_enabled(S16 key_code, S16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tone_type == KEYPAD_SILENT  /* silent profile */
        || frm_p->key_tone_state == MMI_KEY_TONE_DISABLED)
    {
        return FALSE;
    }
    else if (frm_p->key_tone_state == MMI_KEY_VOL_TONE_DISABLED)
    {
        /* disable volume keypad tone */
        if (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN)
        {
            return FALSE;
        }
    }
    else if (frm_p->key_tone_state == MMI_KEY_VOL_UP_DOWN_TONE_DISABLED)
    {
        /* disable volume keypad tone */
        if (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN || 
            key_code == KEY_UP_ARROW || key_code == KEY_DOWN_ARROW)
        {
            return FALSE;
        }
    }
    else if (frm_p->key_tone_state == MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED)
    {
        if (key_code == KEY_RIGHT_ARROW || key_code == KEY_LEFT_ARROW)
        {
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_play_keypad_tone
 * DESCRIPTION
 *  This function is used for plays corresponding keypad tone.
 * PARAMETERS
 *  key_code        [IN]     Key to which this event is associated.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_play_keypad_tone(S16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tone_type == KEYPAD_CLICK)
    {
        AudioPlayReq(TONE_KEY_CLICK, DEVICE_AUDIO_PLAY_ONCE);
    }
    else
    {
        SetCurKeypadTone(GetKeypadTone(key_code));
        frm_p->key_tone_id = GetCurKeypadTone();
        frm_p->key_tone_duration = GetKeypadDuration(key_code);
        AudioPlayReq(frm_p->key_tone_id, frm_p->key_tone_duration);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_stop_keypad_tone
 * DESCRIPTION
 *  This function is used for stops corresponding keypad tone.
 * PARAMETERS
 *  key_code        [IN]        Key code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_stop_keypad_tone(S16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tone_type == KEYPAD_TONE)
    {
        SetCurKeypadTone(0xFFFF);
        if (GetKeypadDuration(key_code) == DEVICE_AUDIO_PLAY_INFINITE)
        {
            AudioStopReq(GetKeypadTone(key_code));
        }
    }
#if defined(__MMI_CUST_KEYPAD_TONE__)
    else if (tone_type >= KEYPAD_TONE_CUST_1 && tone_type <= KEYPAD_TONE_CUST_6
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
             && frm_p->key_tone_id < MIN_HUMAN_VOICE_ID)    /* MIN_KEYPAD_TONE_ID > MIN_HUMAN_VOICE_ID */
#else 
             && frm_p->key_tone_id < MIN_KEYPAD_TONE_ID)
#endif 
{
    SetCurKeypadTone(0xFFFF);
    if (frm_p->key_tone_duration == DEVICE_AUDIO_PLAY_INFINITE)
    {
        AudioStopReq(frm_p->key_tone_id);
    }
}
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    else
if (tone_type >= KEYPAD_TONE_HUMAN_VOICE_1 && tone_type <= KEYPAD_TONE_HUMAN_VOICE_6 && frm_p->key_tone_id < MIN_HUMAN_VOICE_ID)        /* MIN_KEYPAD_TONE_ID > MIN_HUMAN_VOICE_ID */
{
    SetCurKeypadTone(0xFFFF);
    if (frm_p->key_tone_duration == DEVICE_AUDIO_PLAY_INFINITE)
    {
        AudioStopReq(frm_p->key_tone_id);
    }
}
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbn_key_tone_hdlr
 * DESCRIPTION
 *  This function is used for handle general keypad tones.
 * PARAMETERS
 *  eventKey        [IN]  The Key event.
 * RETURNS
 *  TRUE if general key tone plays; otherwise, FALSE.
 *****************************************************************************/
U8 mmi_kbn_key_tone_hdlr(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK added by JL 031220 for mute microphone to avoid the conflict with speaker and cause the DTMF frequency error */
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "key event <<code %d, type %d>> \n", eventKey->nKeyCode,
                         eventKey->nMsgType);
    if (eventKey->nKeyCode == KEY_INVALID)
    {
        return MMI_TRUE;
    }

/* 2009.05.18 added by hongzhe.liu for vol key tone in calling + */

        //if(  isInCall() &&  MMI_KEY_TONE_ENABLED == mmi_frm_kbd_get_key_tone_state() )
        {

            #if defined(__MMI_NO_VOL_KEYS__)    
            	mmi_frm_kbd_set_tone_state( MMI_KEY_VOL_UP_DOWN_TONE_DISABLED );
            #else
            	mmi_frm_kbd_set_tone_state( MMI_KEY_VOL_TONE_DISABLED );
            #endif

        
        }        
/* 2009.05.18 added by hongzhe.liu for vol key tone in calling - */	


    /* To Play Tones */
    if (eventKey->nMsgType == KEY_EVENT_DOWN)
    {
        if (mmi_frm_kbd_is_tone_enabled(eventKey->nKeyCode, eventKey->nMsgType))
        {
            mmi_frm_play_keypad_tone(eventKey->nKeyCode);
        }
    }
    else if (eventKey->nMsgType == KEY_EVENT_UP)
    {
        mmi_frm_stop_keypad_tone(eventKey->nKeyCode);
    }

    //move to Framework ExecuteCurrKeyHandler((S16)eventKey->nKeyCode,(S16)eventKey->nMsgType);
    //To continue to handler framework process, if false.
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbd_set_concurrent_mode
 * DESCRIPTION
 *  This function is used to set key concurrent mode. Key concurrent mode 
 *  is to allow application handling (through call-back) concurrent multi-key
 *  events on keypad.
 *  For example, user presses "up arrow" key while "left arrow" is pressing.
 *  In general cases, the mode is turned off to prevent applicaiton to make mistake
 *  at processing key events.
 *  Since it is highly relay on hardware capability, the functionality is 
 *  depending on whether the driver compile option __TWO_KEY_DETECTION_SWITCHABLE__
 *  or __THREE_KEY_DETECTION_SWITCHABLE__ being defined in makefile.
 * PARAMETERS
 *  mode    [IN]    see mmi_frm_concurrent_key_mode_enum
 * RETURNS
 *  MMI_TRUE: mode change successfully, MMI_FALSE: fail or no change
 *****************************************************************************/
MMI_BOOL mmi_kbd_set_concurrent_mode(U32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kbd_key_det_mode det_mode = kbd_1_key_det_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mode<CONCURRENT_KEY_MODE_END);

    switch (mode)
    {
    case CONCURRENT_KEY_MODE_1_KEY:
        det_mode = kbd_1_key_det_mode;
        break;

    case CONCURRENT_KEY_MODE_2_KEYS:
        det_mode = kbd_2_keys_det_mode;
        break;

    case CONCURRENT_KEY_MODE_3_KEYS:
        det_mode = kbd_3_keys_det_mode;
        break;

    default:
        MMI_ASSERT(0);
        break;
    }

    /* call keypad driver to set detection(concurrent) mode */
    if (kbd_key_det_mode_switch(det_mode))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_KEY_CONCURRENT_MODE, mode);
        
        ClearKeyEvents();
        g_kbd_concurrent_key_mode = mode;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbd_get_concurrent_mode
 * DESCRIPTION
 *  This function is used for handle transparent mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  concurrent mode
 *****************************************************************************/
U32 mmi_kbd_get_concurrent_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_kbd_concurrent_key_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbd_get_key_is_pressing_count
 * DESCRIPTION
 * This function is used for query count of keys are under pressing state.
 * PARAMETERS
 *  void
 * RETURNS
 *  Count of keys are under pressing state.
 *****************************************************************************/
U8 mmi_kbd_get_key_is_pressing_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return key_is_pressing_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_default_power_onoff_key
 * DESCRIPTION
 *  This function is used for set power on/off key to default handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_default_power_onoff_key(void)
{
#ifdef __MMI_POWER_ON_OFF_BY_POWER_KEY__
    SetKeyHandler(NULL, KEY_END, KEY_LONG_PRESS);
    SetKeyHandler(ShutdownSystemOperation, KEY_POWER, KEY_LONG_PRESS);
#else
    SetKeyHandler(ShutdownSystemOperation, KEY_END, KEY_LONG_PRESS);
#endif /* __MMI_POWER_ON_OFF_BY_POWER_KEY__ */
}

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  KeyEventHandler
 * DESCRIPTION
 *  This function is used for handle the key event.
 * PARAMETERS
 *  eventKey        [IN]  The key event.    
 * RETURNS
 *  void
 *****************************************************************************/
static void KeyEventHandler(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Preprocess the keypad handler */
    mmi_kbd_app_key_hdlr(eventKey);

    if (g_mmi_frm_cntx.kbd_pre_func)
    {
        g_mmi_frm_cntx.kbd_pre_func(eventKey);
    }

    /* Process the register App keypad handler */
    ExecuteCurrKeyHandler((S16) eventKey->nKeyCode, (S16) eventKey->nMsgType);

    if (g_mmi_frm_cntx.kbd_post_func)
    {
        g_mmi_frm_cntx.kbd_post_func(eventKey);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_kbd_app_key_hdlr
 * DESCRIPTION
 *  This function is used for handle general appplication events.
 * PARAMETERS
 *  eventKey        [IN]  The key event.        
 * RETURNS
 *  U8, if return true, Framework will not control the key, otherwse.
 *****************************************************************************/
static U8 mmi_kbd_app_key_hdlr(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2006/02/06 Move these checking codes to idleapp.c */
    if (!mmi_shutdown_is_in_power_off_period())
    {
    	mmi_idle_key_event_backlight_check();
    }
    mmi_idle_key_event_keypad_lock_check(eventKey);

    return mmi_kbn_key_tone_hdlr(eventKey);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_2step_keyCode
 * DESCRIPTION
 *  This function is used for gets the 2 step keys of handset.
 *  The function should be called in MMI_Init()
 * PARAMETERS
 *  keyCode                 [IN]        
 * RETURNS
 *  MMI_TRUE - it's 2 step key
 *  MMI_FALSE - it isn't 2 step key
 *****************************************************************************/
static MMI_BOOL mmi_frm_is_2step_keyCode(U16 keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_2step_key_num; i++)
    {
        if (keyCode == g_2step_keyCode[i])
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_internal_key_contex
 * DESCRIPTION
 *  This function is used for De-initialize history & event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_reset_internal_key_contex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pressKey = 0;
    processUpRepeatKey = 0;
}


#ifdef __MMI_SCREEN_ROTATE__

/*****************************************************************************
 * FUNCTION
 *  get_rotated_key
 * DESCRIPTION
 *  This function is used for gets rotated key according to current key rotate
 *  state.
 * PARAMETERS
 *  Keyevent        [IN]        key event type
 *  DeviceKeyCode   [IN]        hardware key index
 * RETURNS
 *  updated key index
 *****************************************************************************/
__inline U16 get_rotated_key(U32 Keyevent, U16 DeviceKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 newKeyMapIndex = DeviceKeyCode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* only get key rotate state when key-press */
    if (Keyevent == WM_KEYPRESS)
    {
        key_rotate = mmi_frm_get_screen_rotate();
    }

    /* rotate key */
    switch (key_rotate)
    {
    case MMI_FRM_SCREEN_ROTATE_270:
        switch (DeviceKeyCode)
        {
        case DEVICE_KEY_UP:
            newKeyMapIndex = DEVICE_KEY_LEFT;
            break;
        case DEVICE_KEY_DOWN:
            newKeyMapIndex = DEVICE_KEY_RIGHT;
            break;
        case DEVICE_KEY_LEFT:
            newKeyMapIndex = DEVICE_KEY_DOWN;
            break;
        case DEVICE_KEY_RIGHT:
            newKeyMapIndex = DEVICE_KEY_UP;
            break;
        }
        break;
    }

    /* restore key rotate state when key-release */
    if (Keyevent == WM_KEYRELEASE)
    {
        key_rotate = MMI_FRM_SCREEN_ROTATE_0;
    }
    
    return newKeyMapIndex;
}

#endif /* __MMI_SCREEN_ROTATE__ */ 


