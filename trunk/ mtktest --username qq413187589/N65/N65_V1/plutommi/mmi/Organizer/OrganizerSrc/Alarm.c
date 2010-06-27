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
 * Alarm.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm application related screens.
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

/**************************************************************

   FILENAME : Alarm.c

   PURPOSE     : Handling of Alarm Application

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma, Gautam Saluja

   DATE     : June 9,03

**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_ALARM_C
#define _MMI_ALARM_C


/*  Include: MMI header file */
#include "ProtocolEvents.h"


#include "wgui_status_icons.h"

#include "gpioInc.h"

#include "DateTimeGprot.h"
#include "AlarmProt.h"
#include "AlarmDef.h"
#include "AlarmGProt.h"
#include "AlarmFrameworkProt.h"

#include "FileMgr.h"
#include "ProfileGprots.h"
#include "ProfileMgrGProt.h"
#include "Profiles_prot.h"



#include "SettingProfile.h"

#include "AudioInc.h"
#include "OrganizerDef.h"
#include "ProfilesDefs.h"
#include "WrapperGprot.h"
#include "SimDetectionGexdcl.h"
#include "ExtDeviceDefs.h"
#include "CommonScreens.h"
#include "Wgui_status_icons.h"
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#include "DownloadDefs.h"
#include "DownloadProtos.h"
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
#ifdef __MMI_ALM_AUDIO_OPTIONS__
#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "MainMenuDef.h"
#include "Aud_Defs.h"
#include "conversions.h"


extern mmi_fmrdo_struct g_fmrdo;    /* defined in FMRadioSrc.c */
extern pBOOL mmi_fmrdo_channel_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_fmrdo_channel_list_item_hint(S32 item_index, UI_string_type *hint_array);
extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);

BOOL g_alm_aud_opt_selected = FALSE;
extern U8 isEarphonePlugged;

S8 *g_alm_audio_options_string[NUM_AUDIO_OPTIONS];  /* array to store the audio option strings */
U16 g_alm_audio_options_curselitem[MAX_NAME_INPUT_LEN];
S8 g_alm_aud_opt_curselitem_inline_index;
S32 g_alm_audio_option_previndex;                   /* the index of the selected audio option i.e. FM or tone. */
U8 g_alm_aud_opt_fmrdo_channel_index;
U16 g_alm_aud_opt_fmrdo_channel_opt_index;
U16 g_alm_fmrdo_man_inp_opt_index;
U16 g_alm_fmrdo_prev_freq;
static UI_character_type channel_manual_input_buffer[MAX_MANUAL_INPUT_LEN];
static BOOL g_alm_fmrdo_read_channel_name = FALSE;

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
static PRFSET_MELODY_CONF_TYPE g_alm_tone_conf_type = 0;
static U8 g_ext_melody_idx = 0;
static U8 extMldHlitItem = 0;
static U8* g_alm_ext_melody_short_name_ptr = NULL;
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

static S32 g_alm_tone_index;
extern U8 mmi_profiles_get_melody_list(U16 CurMelodyID, U16 *selecteditem);
extern U16 gstartRingId;
extern U16 gtotalRingId;
extern U16 gstartMidiId;
extern U16 gtotalMidiId;
extern U16 gcurrentaudioId;
extern PROFILE gcurrentprofile;

#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

/* 
 * Define
 */
/* 
 * Typedef 
 */

/* 
 * Local Variable
 */
const U8 g_alm_freq_set[ALARM_FREQ_NUM] = {ALM_FREQ_ONCE, ALM_FREQ_EVERYDAY, ALM_FREQ_DAYS};

/* 
 * Local Function
 */
/* 
 * Global Variable
 */
alm_context_struct g_alm_cntx;
S8 *gAlmFreqList[ALM_FREQ_TOTAL];   /* array to store frequency type of alarm */

S8 *gAlmOnOffString[NUM_STATE_FOR_ALM];  /* array to store on/off state of an alarm */
U8 gAlmDaysStates[NUM_DAYS];                    /* signifies the days alarm has been set for in case of freq weekdays */

#ifdef __MMI_ALM_CUST_VOLUME__
S8 *gAlmVolumeList[LEVEL7 + 1];
const S8 gAlmVolumeString[LEVEL7 + 1][4] = 
{
    {'1', 0, 0, 0},
    {'2', 0, 0, 0},
    {'3', 0, 0, 0},
    {'4', 0, 0, 0},
    {'5', 0, 0, 0},
    {'6', 0, 0, 0},
    {'7', 0, 0, 0}
};
#endif /* __MMI_ALM_CUST_VOLUME__ */ 
#ifdef __MMI_ALM_SNOOZE_SETTING__
S8 *gAlmSettingSnooze[ALM_SNOOZE_INTERVAL_SETTING_NUM];
#endif 
#ifdef __MMI_ALM_ALERT_TYPE__
S8 *gAlmSettingAlertType[ALM_ALERT_TYPE_SETTING_NUM];
#endif 

extern wgui_inline_item wgui_inline_items[];

/* 
 * Global Function
 */
extern void AlarmDisplayCharging(void);
extern void AudioPlayToneWithCallBackVolPath(U16 soundId, U8 style, U8 tone_type, U8 volume, U8 path);


/*****************************************************************************
 * FUNCTION
 *  HighlightAlmMenu
 * DESCRIPTION
 *  Highlight handler of alarm menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EntryAlmMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryAlmMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    g_alm_cntx.CurrHiliteAlarm = 0;
}


/*****************************************************************************
 * FUNCTION
 *  AlmInit
 * DESCRIPTION
 *  Initailization function. Set the highlight handlers and get required strings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(ORGANIZER_ALARM_MENU, HighlightAlmMenu);
}


/*****************************************************************************
 * FUNCTION
 *  AlmExpiryTimeCBH
 * DESCRIPTION
 *  Callback handler to get information of alarm expiry setting.
 * PARAMETERS
 *  index           [IN]            
 *  alarmTime       [?]             
 *  Freq            [?]             
 *  WeekDays        [?]             
 *  MYTIME(?)       [IN/OUT]        Expiry time set by user
 *  U8(?)           [IN/OUT]        Expiry days of week
 * RETURNS
 *  void
 *****************************************************************************/
void AlmExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime, incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);

	alarmTime->nYear = currTime.nYear;
    alarmTime->nMonth = currTime.nMonth;
    alarmTime->nDay = currTime.nDay;
	alarmTime->DayIndex = DOW(alarmTime->nYear, alarmTime->nMonth, alarmTime->nDay);

    alarmTime->nHour = g_alm_cntx.AlmList[index].Hour;
    alarmTime->nMin = g_alm_cntx.AlmList[index].Min;
    *Freq = g_alm_freq_set[g_alm_cntx.AlmList[index].Freq];
    *WeekDays = g_alm_cntx.AlmList[index].Days;
    if (g_alm_cntx.AlmList[index].Snooze)
    {
        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nMin = AlmGetSnoozeInterval(index);  /* ALM_SNOOZE_INTERVAL; */
        IncrementTime(currTime, incTime, alarmTime);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmReInitQueueCBH
 * DESCRIPTION
 *  Callback handler of reiniting alarm to alarm queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmReInitQueueCBH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_OF_ALM; i++)
    {
        g_alm_cntx.AlmList[i].Snooze = 0;

        if (g_alm_cntx.AlmList[i].State == 1)
        {
            AlmInsertIntoQueue((U8) (i + ALM_ALM_START), FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmExpiryHandlerCB
 * DESCRIPTION
 *  CallBack handler to execute alarm expiry.
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 *  BOOL(?)         [IN]        Power status
 *  U8(?)           [IN]        Index of alarm item
 * RETURNS
 *  void
 *****************************************************************************/
U8 AlmExpiryHandlerCB(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *period = ALM_DEFAULT_EXPIRY_PERIOD;

    /* For the situation of taking off the battery during alarm working.*/
    if (g_alm_freq_set[g_alm_cntx.AlmList[index].Freq] == ALM_FREQ_ONCE)        /* reset the alarm state */
    {
        g_alm_cntx.AlmList[index].State = UNSET_STATE;
        AlmWriteToNvram();
    }

    if (power_on)
    {
        update_mainlcd_dt_display();
        EntryAlmIndicationScreen();
    }
    else
    {
        AlmInitLCDModule();
        EntryAlmIndicationScreen();
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: Alarm idle screen */
    }
    return ALM_HAS_IND;
}


/*****************************************************************************
 * FUNCTION
 *  AlmFCBInit
 * DESCRIPTION
 *  Set callback function needed by alarm framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmFCBInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_set_start_index(ALM_TYPE_ALARM, ALM_ALM_START);
    AlmSetExpiryTimeCB(ALM_TYPE_ALARM, AlmExpiryTimeCBH);
    AlmSetExpiryHandlerCB(ALM_TYPE_ALARM, AlmExpiryHandlerCB);
    AlmSetInitHandlerCB(ALM_TYPE_ALARM, AlmInitNvram, AlmReInitQueueCBH);
    AlmSetStopAlarmCB(ALM_TYPE_ALARM, AlmSnoozeHandler);
}


/*****************************************************************************
 * FUNCTION
 *  AlarmDeInit
 * DESCRIPTION
 *  Deinitailization function of alarm application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlarmDeInit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  AlmInitNvram
 * DESCRIPTION
 *  Gets the information from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInitNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_ALM_ALARM_DATA_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_ALM_ALARM_DATA_LID, 1, (void*)nvram_buf, NVRAM_ALM_ALARM_DATA_SIZE, &error);
    memcpy(g_alm_cntx.AlmList, nvram_buf, sizeof(g_alm_cntx.AlmList));

    if (AlmIsAnyAlarmActivated())
    {
        AlmActivateIndicator();
    }
    else
    {
        AlmDeactivateIndicator();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAlmIndex
 * DESCRIPTION
 *  Highlight handler of alarm item in alarm screen.
 *  Store current highlight index.
 * PARAMETERS
 *  nIndex      [IN]        
 *  S32(?)      [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmIndex(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_cntx.CurrHiliteAlarm = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmMenu
 * DESCRIPTION
 *  Entry function of Alarm application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    U16 alarm_states_icon[NUM_OF_ALM];
    MYTIME almTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use FM radio list before FM radio initialize */
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    mmi_alm_aud_fmrdo_init_channe_list();
#endif 

    EntryNewScreen(SCR_ID_ALM_LIST, NULL, EntryAlmMenu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_ALM_LIST);

    if (guiBuffer == NULL)
    {
        g_alm_cntx.CurrHiliteAlarm = 0;
    }

    g_alm_cntx.IsDOWSet = 0;

    /* construct displayed string and icon */
    for (i = 0; i < NUM_OF_ALM; i++)
    {
        almTime.nHour = g_alm_cntx.AlmList[i].Hour;
        almTime.nMin = g_alm_cntx.AlmList[i].Min;
        time_string(&almTime, (UI_string_type) subMenuDataPtrs[i], DT_IDLE_SCREEN);

        if (g_alm_cntx.AlmList[i].State == SET_STATE)
        {
            alarm_states_icon[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            alarm_states_icon[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    ShowCategory53Screen(
        ORGANIZER_MENU_ALARMS_STRINGID,
        GetRootTitleIcon(ORGANIZER_ALARM_MENU),
        ALARMS_EDIT_SOFTKEY_STRINGID,
        ALARMS_EDIT_SOFTKEY_IMAGEID,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NUM_OF_ALM,
        subMenuDataPtrs,
        alarm_states_icon,
        0,
        0,
        (S32) g_alm_cntx.CurrHiliteAlarm,
        guiBuffer);
    wgui_restore_list_menu_slim_style();

    SetLeftSoftkeyFunction(AlmPrepareInlineScreen, KEY_EVENT_UP);
    SetKeyHandler(AlmPrepareInlineScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    RegisterHighlightHandler(HighlightAlmIndex);
}


/*****************************************************************************
 * FUNCTION
 *  AlmGoBackAlarmMenu
 * DESCRIPTION
 *  Go back to alarm menu list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmGoBackAlarmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_ALM_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmSaveConfirmation
 * DESCRIPTION
 *  Display confirmation screen for setting alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmSaveConfirmation(void)
{
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!
         ((g_alm_cntx.CurrHiliteAudioOption && g_alm_audio_option_previndex) ||
          (!g_alm_cntx.CurrHiliteAudioOption && !g_alm_audio_option_previndex))) ||
        (g_alm_cntx.CurrHiliteAudioOptionValue == 0))
    {
        DisplayConfirm(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            get_string(STR_ID_ALM_FMRDO_AUD_OPT_INCOMPLETE_NOTIFY),
            IMG_GLOBAL_INFO,
            WARNING_TONE);
        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        return;
    }

    /* check if the currently selected option is ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL and some channel is selected for it */
    if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        U16 index;
        BOOL valid_chan = TRUE;

        if (g_alm_cntx.CurrHiliteAudioOptionValue == 0 || g_alm_cntx.CurrHiliteAudioOptionValue > FM_RADIO_CHANNEL_NUM)
        {
            valid_chan = FALSE;
        }
        else
        {
            index = g_alm_cntx.CurrHiliteAudioOptionValue - 1;
            if (g_fmrdo.channel_list.freq[index] < MIN_FM_FREQUENCY ||
                g_fmrdo.channel_list.freq[index] > MAX_FM_FREQUENCY)
            {
                valid_chan = FALSE;
            }
        }

        if (!valid_chan)
        {
            DisplayConfirm(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                0,
                0,
                get_string(STR_ID_ALM_FMRDO_INCOMPLETE_CHANNEL_INFO),
                IMG_GLOBAL_INFO,
                WARNING_TONE);
            SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            return;
        }
    }
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(AlmSaveInlineEdit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(AlmGoBackAlarmMenu, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  AlmPrepareInlineScreen
 * DESCRIPTION
 *  This fuction builds the display information of the selected alarm, and then enter
 *  alarm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmPrepareInlineScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = g_alm_cntx.CurrHiliteAlarm;
    /* fill inline selection strings */
    gAlmOnOffString[0] = GetString(STR_GLOBAL_OFF);
    gAlmOnOffString[1] = GetString(STR_GLOBAL_ON);

#ifdef __MMI_ALM_AUDIO_OPTIONS__
    g_alm_audio_options_string[0] = GetString(STR_ID_ALM_AUDIO_OPTIONS_TONE);
    g_alm_audio_options_string[1] = GetString(STR_ID_ALM_AUDIO_OPTIONS_FMRADIO);
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

    /* time string */
    AlmGetStringValue(g_alm_cntx.HourBuf, g_alm_cntx.AlmList[i].Hour);
    AlmGetStringValue(g_alm_cntx.MinBuf, g_alm_cntx.AlmList[i].Min);

    g_alm_cntx.CurrHiliteState = g_alm_cntx.AlmList[i].State;
    g_alm_cntx.CurrHiliteFreq = g_alm_cntx.AlmList[i].Freq;

#ifdef __MMI_ALM_CUST_VOLUME__
    g_alm_cntx.CurrHiliteVol = g_alm_cntx.AlmList[i].Volume;
#endif 

    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] == ALM_FREQ_DAYS)     /* not Days */
    {
        for (j = 0; j < NUM_DAYS; j++)
        {
            gAlmDaysStates[j] = ((((g_alm_cntx.AlmList[i].Days) & (0x1 << j)) == 0) ? 0 : 1);
        }
    }
    else
    {
        memset(gAlmDaysStates, 0, 7);
    }

    /* Audio options in alarm */
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    g_alm_cntx.CurrHiliteAudioOption = g_alm_cntx.AlmList[i].AudioOption;

    if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        U16 freq = 0;
        U16 index = g_alm_cntx.CurrHiliteAudioOptionValue = g_alm_cntx.AlmList[i].AudioOptionValue;

        if ((index > 0) && (index <= FM_RADIO_CHANNEL_NUM))
        {
            freq = g_fmrdo.channel_list.freq[index - 1];
        }

        /* In valid frequency, restore to default ring tone */
        if ((freq < MIN_FM_FREQUENCY) || (freq > MAX_FM_FREQUENCY))
        {
            g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_TONE;
            g_alm_cntx.CurrHiliteAudioOptionValue = (U16) (gstartMidiId + 1);
        }
    }
    else if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)
    {
        g_alm_cntx.CurrHiliteAudioOptionValue = g_alm_cntx.AlmList[i].AudioOptionValue;
    }
    else    /* ALM_AUDIO_OPTIONS_TONE */
    {
    #ifdef __MMI_ALM_CUSTOMIZE_TONE__
        if (g_alm_cntx.AlmList[i].AudioOptionValue > 0)
        {
            g_alm_cntx.CurrHiliteAudioOptionValue = g_alm_cntx.AlmList[i].AudioOptionValue;
        }
        else
        {
            g_alm_cntx.CurrHiliteAudioOptionValue = (U16) (gstartMidiId + 1);
        }
    #else /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
        g_alm_cntx.CurrHiliteAudioOptionValue = gcurrentprofile.toneSetup.alarmTone;
    #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
    }

#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

#ifdef __MMI_ALM_SNOOZE_SETTING__
    g_alm_cntx.CurrHilightSnoozeInterval = g_alm_cntx.AlmList[i].SnoozeInterval;
#endif 

#ifdef __MMI_ALM_ALERT_TYPE__
    g_alm_cntx.CurrHilightAlertType = g_alm_cntx.AlmList[i].AlertType;
#endif 

    EntryAlmEditScreen();
}

#ifdef __MMI_ALM_CUST_VOLUME__


/*****************************************************************************
 * FUNCTION
 *  AlmPlayAlarmToneWithVol
 * DESCRIPTION
 *  Play alarm tone with setting volume level.
 * PARAMETERS
 *  volume      [IN]        
 *  U8(?)       [IN]        Volumn level
 * RETURNS
 *  void
 *****************************************************************************/
void AlmPlayAlarmToneWithVol(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_frm_cntx.IsAlmTonePlaying == FALSE)
    {
    #ifdef __MMI_PROFILE_ALERT_TYPE_DOMINANT__
        U8 alert_type = GetMtCallAlertTypeEnum();
    #endif 
        VibratorOn();

    #ifdef __MMI_PROFILE_ALERT_TYPE_DOMINANT__
        if (alert_type != MMI_VIBRATION_ONLY && alert_type != MMI_SILENT)
    #endif 
        {
            /* Added support for Alarm Audio Options i.e. FM Radio as alarm tone. */
        #ifdef __MMI_ALM_AUDIO_OPTIONS__
            if (g_alm_frm_cntx.CurrAlmIndex >= ALM_ALM_START && g_alm_frm_cntx.CurrAlmIndex < ALM_SPOF_START)
            {
                U8 alarm_index = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;

                if (g_alm_cntx.AlmList[alarm_index].AudioOption == ALM_AUDIO_OPTIONS_TONE)
                {
                #ifdef __MMI_ALM_CUSTOMIZE_TONE__
                    AudioPlayToneWithCallBackVolPath(
                        g_alm_cntx.AlmList[g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START].AudioOptionValue,  /* current profile alarm tone id */
                        DEVICE_AUDIO_PLAY_INFINITE,
                        ALARM_TONE,
                        volume,             /* your volume level 0~6 */
                        MDI_DEVICE_SPEAKER_BOTH);
                #else /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
                    AudioPlayToneWithCallBackVolPath(
                        GetAlarmToneType(), /* current profile alarm tone id */
                        DEVICE_AUDIO_PLAY_INFINITE,
                        ALARM_TONE,
                        volume,             /* your volume level 0~6 */
                        MDI_DEVICE_SPEAKER_BOTH);
                #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

                }
                else
                {
                    mmi_alm_aud_fmrdo_play_alarm(alarm_index, volume);
                }
            }
            else
        #endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 
            {
                AudioPlayToneWithCallBackVolPath(
                    GetAlarmToneType(), /* current profile alarm tone id */
                    DEVICE_AUDIO_PLAY_INFINITE,
                    ALARM_TONE,
                    volume,             /* your volume level 0~6 */
                    MDI_DEVICE_SPEAKER_BOTH);
            }
        }

        g_alm_frm_cntx.IsAlmTonePlaying = TRUE;
    }
}
#endif /* __MMI_ALM_CUST_VOLUME__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryAlmIndicationScreen
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL IfAlmScreen=FALSE;
void EntryAlmIndicationScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MYTIME currTime;
    U8 timeString[SIZE_OF_DATE_STRING];
    static U8 dateString[SIZE_OF_ALARM_STRING + SIZE_OF_DATE_STRING];
    U8 almindex = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	IfAlmScreen=TRUE;
    StopTimer(ALARM_TIMER_WAIT_FOR_CALL);
    if (!IsMyTimerExist(ALARM_ALERT_NOTIFYDURATION_TIMER))
    {
        StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, AlmHandleAlarmTimeout);
    }
    EntryNewScreen(SCR_ID_ALM_INDICATION, ExitAlmIndicationScreen, NULL, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_ALM_INDICATION, (HistoryDelCBPtr)mmi_alm_stop_alarm_by_delete_screen);

    GetDateTime(&currTime);
    time_string(&currTime, (UI_string_type) timeString, DT_IDLE_SCREEN);
    /* prepare string to display */
    if (g_alm_frm_cntx.CurrAlmIndex == ALM_FACTORY)
    {
        memset(dateString, 0, ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) dateString, (S8*) L"\n");
        mmi_ucs2cat((S8*) dateString, (S8*) GetString(ALARMS_POWER_ON));
        mmi_ucs2cat((S8*) dateString, (S8*) L"?");
    }
    else
    {
        date_string(&currTime, (UI_string_type) dateString, DT_IDLE_SCREEN);
        mmi_ucs2cat((S8*) dateString, (S8*) L"\n");
        mmi_ucs2cat((S8*) dateString, (S8*) timeString);
    }

    /* flush key because alarm if some key is not released, the alarm may be stopped */
    ClearKeyEvents();

    g_alm_cntx.IsSaveToHistory = 1;

    guiBuffer = GetCurrGuiBuffer(SCR_ID_ALM_INDICATION);

    ShowCategory121Screen(
        ALARMS_STOP_STRINGID,
        ALARMS_STOP_IMAGEID,
        ALARMS_SNOOZE_STRINGID,
        ALARMS_SNOOZE_IMAGEID,
        dateString,
        ALARM_ANIMATION_INDICATION_IMAGEID,
        guiBuffer,
        1);

    TurnOnBacklight(1);	

    if (g_alm_frm_cntx.CurrAlmIndex == ALM_FACTORY)
    {
        ChangeLeftSoftkey(STR_GLOBAL_YES, IMG_GLOBAL_YES);
        ChangeRightSoftkey(STR_GLOBAL_NO, IMG_GLOBAL_NO);

        SetLeftSoftkeyFunction(AlmSendPowerOn, KEY_EVENT_UP);
        SetRightSoftkeyFunction(AlmSendPowerOff, KEY_EVENT_UP);
    }
    else
    {
        if (g_alm_cntx.AlmList[almindex].Snooze >= MAX_SNOOZE_CHANCES)
        {
            ChangeRightSoftkey(0, 0);
        }
        else
        {
            SetRightSoftkeyFunction(AlmSnoozeHandler, KEY_EVENT_UP);
        #if defined(__MMI_ALARM_SIDE_KEY_CONTROL__)
            SetKeyHandler(AlmSnoozeHandler, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        #endif 
        }

        SetLeftSoftkeyFunction(AlmStopHandler, KEY_EVENT_UP);
        SetKeyHandler(AlmStopHandler, KEY_END, KEY_EVENT_DOWN); /* SetKeyHandler(AlarmEndKeyPressed,KEY_END,KEY_EVENT_DOWN); */

    #if defined(__MMI_ALARM_SIDE_KEY_CONTROL__)
        SetKeyHandler(AlmStopHandler, KEY_VOL_UP, KEY_EVENT_DOWN);
    #endif 
    }

    ForceSubLCDScreen(EntryAlmSubLcdScreen);

#ifdef __MMI_ALM_CUST_VOLUME__
    if (g_alm_frm_cntx.CurrAlmIndex != ALM_FACTORY)
    {
        AlmPlayAlarmToneWithVol(g_alm_cntx.AlmList[almindex].Volume);
    }
    else
#endif /* __MMI_ALM_CUST_VOLUME__ */ 
    {
        AlmPlayAlarmTone();
    }

    /* register END key for power on alarm */
    if (g_alm_frm_cntx.IsPwronAlarm)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        
    #ifdef __MMI_POWER_ON_OFF_BY_POWER_KEY__     
    	ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    	
        ClearKeyHandler(KEY_POWER, KEY_EVENT_UP);
        ClearKeyHandler(KEY_POWER, KEY_EVENT_DOWN);
        SetKeyHandler(AlmHandleEndKey, KEY_POWER, KEY_LONG_PRESS);                
    #else
    	SetKeyHandler(AlmHandleEndKey, KEY_END, KEY_LONG_PRESS);
    #endif
        
        if (g_charbat_context.isChargerConnected && (!g_charbat_context.ChargingComplete))
        {
            AnimateStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
            AnimateStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        }
        UpdateStatusIcons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmHandleEndKey
 * DESCRIPTION
 *  End key handler of alarm indication screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmHandleEndKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;

    AlmsStopAlarmTone();

    g_alm_cntx.AlmList[i].Snooze = 0;

    if (g_alm_freq_set[g_alm_cntx.AlmList[i].Freq] == ALM_FREQ_ONCE)    /* reset the alarm state */
    {
        g_alm_cntx.AlmList[i].State = UNSET_STATE;
    }
    AlmWriteToNvram();
    AlmSendPowerOn();
}


/*****************************************************************************
 * FUNCTION
 *  ExitAlmIndicationScreen
 * DESCRIPTION
 *  Exit function of alarm indication screen.
 *  If exits screen because of interrupts, add screen to history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitAlmIndicationScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmsStopAlarmTone();
	IfAlmScreen=FALSE;

    if (g_alm_cntx.IsSaveToHistory) /* add screen to history */
    {
        GenericExitScreen(SCR_ID_ALM_INDICATION, EntryAlmIndicationScreen);
    }
    if (g_alm_frm_cntx.IsPwronAlarm == FALSE)
    {
        GoBackSubLCDHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmSubLcdScreen
 * DESCRIPTION
 *  Display sub-lcd screen when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmSubLcdScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(ALARM_ANIMATION_INDICATION_SUBLCD_IMAGEID, 0);
}


/*****************************************************************************
 * FUNCTION
 *  ExitAlmSubLcdScreen
 * DESCRIPTION
 *  Exit function of EntryAlmSubLcdScreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitAlmSubLcdScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = EntryAlmSubLcdScreen;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_ALM_SUB_INDICATION);

}


/*****************************************************************************
 * FUNCTION
 *  AlmCommonExitProcedure
 * DESCRIPTION
 *  Stop alarm tone by user or timeout.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmCommonExitProcedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_cntx.IsSaveToHistory = 0;

    TurnOffBacklight();

    AlmsStopAlarmTone();
}


/*****************************************************************************
 * FUNCTION
 *  AlmExitIndScreen
 * DESCRIPTION
 *  Exit alarm indication screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmExitIndScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_ALM_INDICATION)
    {
    	if (GetSubLCDScreenCountInHistory() == 0)
        {
            GoBackHistory();
        }
        else
        {
            GoBackBothLCDHistory();
        }
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_ALM_INDICATION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmStopHandler
 * DESCRIPTION
 *  Handler for stopping alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmStopHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    AlmCommonExitProcedure();

    /* factory alarm does not have to re-schedule */
    if (g_alm_frm_cntx.CurrAlmIndex != ALM_FACTORY)
    {
        i = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;

        if (i >= NUM_OF_ALM)
        {
            return;
        }
            
        g_alm_cntx.AlmList[i].Snooze = 0;

        if (g_alm_freq_set[g_alm_cntx.AlmList[i].Freq] == ALM_FREQ_ONCE)        /* reset the alarm state */
        {
            g_alm_cntx.AlmList[i].State = UNSET_STATE;

            if (!(AlmIsAnyAlarmActivated()))
            {
                AlmDeactivateIndicator();
            }
        }
        AlmWriteToNvram();
    }

    g_alm_frm_cntx.CurrAlmIndex = 0xff;

    if (g_alm_frm_cntx.IsPwronAlarm == FALSE)
    {
        AlmExitIndScreen();
        if (g_alm_frm_cntx.IsExitByTimer == FALSE)
        {
            AlmExecPwrOnAlarm();
        }
    }
    else
    {

        if (GetCurrScrnId() == (U16) SCR_ID_ALM_PWRON_CONFIRM)
        {
            AlmExitIndScreen();
        }
    #ifdef __NVRAM_IN_USB_MS__            
        else if (g_pwr_context.PowerOnMode == POWER_ON_USB)
        {
            /* USB may be plugged out while alarm is alerting */
            if (GetScreenCountInHistory() > 0)
            {
                AlmExitIndScreen();
            }
        }
    #endif         
        else
        {
            EntryAlmPowerOnConfirmation();
        }
    #ifdef __MTK_TARGET__
        if (g_alm_frm_cntx.IsExitByTimer == FALSE)
        {
            AlmExecPwrOffAlarm();
        }
    #endif /* __MTK_TARGET__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmSnoozeHandler
 * DESCRIPTION
 *  Handler for snoozing alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSnoozeHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);

    i = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;
    
    if (i >= NUM_OF_ALM)
    {
            return;
    }
    
    g_alm_cntx.AlmList[i].Snooze++;
    g_alm_cntx.AlmList[i].State = SET_STATE;

    AlmCommonExitProcedure();

    if (g_alm_cntx.AlmList[i].Snooze <= MAX_SNOOZE_CHANCES)
    {
        AlmWriteToNvram();
        AlmInsertIntoQueue(g_alm_frm_cntx.CurrAlmIndex, TRUE);

        g_alm_frm_cntx.CurrAlmIndex = 0xff;

        if (g_alm_frm_cntx.IsPwronAlarm == FALSE)
        {
            /* GoBackBothLCDHistory(); */
            AlmExitIndScreen();
        }

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
    #endif /* 0 */ 

        else if (g_alm_frm_cntx.IsPwronAlarm && g_alm_frm_cntx.IsAppExecuting)
        {
            /* GoBackHistory(); */
            AlmExitIndScreen();
        }

        if (g_alm_frm_cntx.IsExitByTimer == FALSE)
        {
            if (g_alm_frm_cntx.IsPwronAlarm)
            {
                AlmExecPwrOffAlarm();
            }
            else
            {
                AlmExecPwrOnAlarm();
            }
        }
    }
    else
    {
        AlmStopHandler();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_alarm_usb_mode_off
 * DESCRIPTION
 *  When alarm screen is deleted by USB, the callback function will be executed.
 *  The body of this callback is similar with snooze handler except the screen handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
U8 mmi_alm_stop_alarm_by_delete_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_frm_cntx.CurrAlmIndex == 0xff)
    {
        return MMI_FALSE;
    }
    
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);

    i = g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START;
    
    if (i >= NUM_OF_ALM)
    {
            return MMI_FALSE;
    }
    
    g_alm_cntx.AlmList[i].Snooze++;
    g_alm_cntx.AlmList[i].State = SET_STATE;


    if (g_alm_cntx.AlmList[i].Snooze <= MAX_SNOOZE_CHANCES)
    {
        AlmWriteToNvram();
        AlmSetAlarm(g_alm_frm_cntx.CurrAlmIndex);

        g_alm_frm_cntx.CurrAlmIndex = 0xff;

    }
    else
    {
        /* Stop handler*/
        g_alm_cntx.AlmList[i].Snooze = 0;

        if (g_alm_freq_set[g_alm_cntx.AlmList[i].Freq] == ALM_FREQ_ONCE)        /* reset the alarm state */
        {
            g_alm_cntx.AlmList[i].State = UNSET_STATE;

            if (!(AlmIsAnyAlarmActivated()))
            {
                AlmDeactivateIndicator();
            }
        }
        AlmWriteToNvram();

        g_alm_frm_cntx.CurrAlmIndex = 0xff;

    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  AlmWriteToNvram
 * DESCRIPTION
 *  Write alarm data to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmWriteToNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_ALM_ALARM_DATA_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvram_buf, 0, NVRAM_ALM_ALARM_DATA_SIZE);
    memcpy(nvram_buf, g_alm_cntx.AlmList, sizeof(g_alm_cntx.AlmList));

    WriteRecord(NVRAM_EF_ALM_ALARM_DATA_LID, 1, (void*)nvram_buf, NVRAM_ALM_ALARM_DATA_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  AlmIsAnyAlarmActivated
 * DESCRIPTION
 *  To check if there is any activated alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 if no activated alarm; otherwise 0.
 *****************************************************************************/
U8 AlmIsAnyAlarmActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_OF_ALM; i++)
        if (g_alm_cntx.AlmList[i].State == SET_STATE)
        {
            return 1;
        }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  AlmActivateIndicator
 * DESCRIPTION
 *  Show alarm status icon in IDLE screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmActivateIndicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowStatusIcon(STATUS_ICON_ALARM);
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
    ShowStatusIcon(STATUS_ICON_SUBLCD_ALARM);
#endif 
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  AlmDeactivateIndicator
 * DESCRIPTION
 *  Hide alarm status icon in IDLE screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmDeactivateIndicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HideStatusIcon(STATUS_ICON_ALARM);
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
    HideStatusIcon(STATUS_ICON_SUBLCD_ALARM);
#endif 
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_check_history_and_poweroff
 * DESCRIPTION
 *  Check history before sending power off request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_check_history_and_poweroff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetScreenCountInHistory() > 0)
    {
        if (GetSubLCDScreenCountInHistory() == 0)
        {
            GoBackHistory();
        }
        else
        {
            GoBackBothLCDHistory();
        }
    }
    else
    {
        AlmSendPowerOff();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmPowerOnConfirmation
 * DESCRIPTION
 *  Display confirmation screen to decide power on or not.
 *  This screen is used for power off alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmPowerOnConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_disable_pwroff();

    EntryNewScreen(SCR_ID_ALM_PWRON_CONFIRM, NULL, EntryAlmPowerOnConfirmation, NULL);

    /* to prevent power on confirmation screen from displaying twice */
    DeleteScreenIfPresent(SCR_ID_ALM_PWRON_CONFIRM);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_ALM_PWRON_CONFIRM);

    ShowCategory123Screen(
        ORGANIZER_MENU_ALARMS_STRINGID,
        ALARMS_MAIN_TITLE_IMAGEID,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        ALARMS_POWER_ON,
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(AlmSendPowerOn, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_alm_check_history_and_poweroff, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(AlmSendPowerOn, KEY_END, KEY_LONG_PRESS);

    /* to prevent double displayed this screen */
    DeleteScreenIfPresent(SCR_ID_ALM_PWRON_CONFIRM);
    ForceSubLCDScreen(EntryAlmSubLcdScreen);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightAlmInlineRepeat
 * DESCRIPTION
 *  Highlight handler of Repeat inline selection item in editor screen.
 *  Enable DOW component when selecting "Days"
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmInlineRepeat(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_freq_set[index] == ALM_FREQ_DAYS)
    {
        if (g_alm_cntx.IsDOWSet == 0)
        {
            /* if the user did not select DOW yet */
            if (g_alm_cntx.AlmList[g_alm_cntx.CurrHiliteAlarm].Days == 0)
            {
                memset(gAlmDaysStates, 1, 7);
                gAlmDaysStates[0] = 0;
                gAlmDaysStates[6] = 0;
            }
            else    /* fill user-set value to DOW */
            {
                for (j = 0; j < NUM_DAYS; j++)
                {
                    gAlmDaysStates[j] =
                        ((((g_alm_cntx.AlmList[g_alm_cntx.CurrHiliteAlarm].Days) & (0x1 << j)) == 0) ? 0 : 1);
                }
            }

            g_alm_cntx.IsDOWSet = 1;
            EnableInlineItem(&wgui_inline_items[4], 4); /* multi select days */
        }
    }
    else
    {
        g_alm_cntx.IsDOWSet = 0;
        memset(gAlmDaysStates, 0, 7);
        DisableInlineItem(&wgui_inline_items[4], 4);    /* multi select days */
    }

    RedrawCategory57Screen();
}

/* added the support for alarm audio options. */


/*****************************************************************************
 * FUNCTION
 *  AlmGetSnoozeInterval
 * DESCRIPTION
 *  Get Snooze Interval
 * PARAMETERS
 *  void
 * RETURNS
 *  Snooze interval
 *****************************************************************************/
U8 AlmGetSnoozeInterval(U8 almIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 snooze;

#ifdef __MMI_ALM_SNOOZE_SETTING__

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    snooze = g_alm_cntx.AlmList[almIndex].SnoozeInterval;
#endif /* __MMI_ALM_SNOOZE_SETTING__ */ 

    if (snooze == 0)
    {
        snooze = ALM_SNOOZE_INTERVAL;
    }
    /* ReadValue(NVRAM_ALM_SNOOZE_TIME, &snooze, DS_BYTE, &error); */

    return snooze;
}

#ifdef __MMI_ALM_AUDIO_OPTIONS__

#ifdef __MMI_ALM_CUSTOMIZE_TONE__


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_aud_opt_tone
 * DESCRIPTION
 *  The entry function for the screen displaying options for tone audio option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_aud_opt_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 selecteditem = 0;
    U8 totalItems = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ALM_TONE_SETUP, mmi_alm_exit_aud_opt_tone, mmi_alm_entry_aud_opt_tone, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_ALM_TONE_SETUP);
    SetParentHandler(MENU_ID_ALM_TONE_SETUP);
    RegisterHighlightHandler(mmi_alm_tone_setup_hilite_hdlr);

    /* Get the highlight index from profile */
    if (g_alm_cntx.CurrHiliteAudioOption != ALM_AUDIO_OPTIONS_TONE ||
        (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_TONE && g_alm_cntx.CurrHiliteAudioOptionValue == 0))
    {
        totalItems = mmi_profiles_get_melody_list((U16) (gstartMidiId + 1), &selecteditem);
    }
    else
    {
        totalItems = mmi_profiles_get_melody_list(g_alm_cntx.CurrHiliteAudioOptionValue, &selecteditem);
    }

    ShowCategory89Screen(
        STR_ALARM_TONE_CAPTION,
        IMG_PROFILES_TITLEE,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        totalItems,
        subMenuDataPtrs,
        hintDataPtrs,
        0,
        selecteditem,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_alm_entry_tone_setup_set_alarm_tone, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_exit_aud_opt_tone
 * DESCRIPTION
 *  The exit function for the screen displaying options for tone audio option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_exit_aud_opt_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_profiles_preview_stop_tone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_tone_setup_set_alarm_tone
 * DESCRIPTION
 *  Setting Alarm tone ID.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_tone_setup_set_alarm_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TONE_SETUP tonesetup;
    U32 tempval1 = 0, tempval2 = gtotalRingId;
    U32 data = 0;
    U8 ExtMelodyFlag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((g_alm_tone_index) >= (U8) tempval1) && ((g_alm_tone_index) < (U8) (tempval2)))
    {
        tonesetup.ringTone = g_alm_tone_index + gstartRingId;
    }

    tempval1 = tempval2;
    tempval2 = gtotalMidiId + gtotalRingId;

    if (((g_alm_tone_index) >= (U8) tempval1) && ((g_alm_tone_index) < (U8) (tempval2)))
    {
        tonesetup.ringTone = g_alm_tone_index + gstartMidiId - gtotalRingId;
    }

#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    tempval1 = tempval2;
    tempval2 = gtotalMidiId + gtotalRingId + MAXIMUM_EXT_MELODY_NUM;

    if (((g_alm_tone_index) >= (U8) tempval1) && ((g_alm_tone_index) < (U8) (tempval2)))
    {
        /* data is zero based */
        data = g_alm_tone_index - (gtotalMidiId + gtotalRingId);
        g_ext_melody_idx = (U8) data;
        ExtMelodyFlag = MMI_TRUE;
    }

    if (ExtMelodyFlag == MMI_TRUE)
    {
        g_alm_tone_conf_type = PRFSET_MELODY_TYPE_ALARM;
        mmi_alm_entry_tone_setup_ext_melody();
        return;
    }

#endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    if (g_alm_tone_index == tempval2)
    {
        DYNAUDIOINFO *download_theme_tones;

        if (GetThemeV2TonesInfo(&download_theme_tones) != 0 && mmi_tm_get_current_theme_ringtone())
        {
            tonesetup.ringTone = (U16) download_theme_tones[0].AudioId;
        }
    }
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 

    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    g_alm_cntx.CurrHiliteAudioOptionValue = tonesetup.ringTone;
    g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_TONE;
    g_alm_aud_opt_selected = TRUE;
    mmi_profiles_preview_stop_tone();
    DeleteScreenIfPresent(SCR_ID_ALM_TONE_SETUP);
}

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_tone_setup_ext_melody
 * DESCRIPTION
 *  Entry function for the external melodies screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_tone_setup_ext_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *nStrItemList[PRF_MENU_EXTMLD_MAX];
    U8 nNumofItem = 0;
    U8 *guiBuffer;
    U16 StrIDToneSet = 0, StrIDToneDel = 0, StrIDToneAdd = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StrIDToneSet = STR_TONE_SETUP_ALARM_TONE_EXT_SET;
    StrIDToneDel = STR_TONE_SETUP_ALARM_TONE_EXT_DEL;
    StrIDToneAdd = STR_TONE_SETUP_ALARM_TONE_EXT_ADD;

    if (PmgIsEmptySlot(g_ext_melody_idx) == MMI_FALSE)  /* Not Empty Slot */
    {
        nStrItemList[PRF_MENU_EXTMLD_DONE] = (U8*) GetString(StrIDToneSet);
        nStrItemList[PRF_MENU_EXTMLD_DEL] = (U8*) GetString(StrIDToneDel);
        nStrItemList[PRF_MENU_EXTMLD_ADD] = (U8*) GetString(StrIDToneAdd);
        nNumofItem = (U8) PRF_MENU_EXTMLD_MAX;
    }
    else    /* Empty slot, show replace only */
    {
        nStrItemList[0] = (U8*) GetString(StrIDToneAdd);
        nNumofItem = 1;
    }

    EntryNewScreen(SCR_ID_ALM_TONE_SETUP_EXT_MELODY, NULL, mmi_alm_entry_tone_setup_ext_melody, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_ALM_TONE_SETUP_EXT_MELODY);
    RegisterHighlightHandler(mmi_alm_tone_setup_ext_melody_hilight_hdlr);

    ShowCategory56Screen(
        STR_ALARM_TONE_CAPTION,
        IMG_PROFILES_TITLEE,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        NULL,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_alm_tone_setup_ext_melody_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_tone_setup_ext_melody_hilight_hdlr
 * DESCRIPTION
 *  Highlight handler for the external melodies options screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_tone_setup_ext_melody_hilight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extMldHlitItem = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_tone_setup_ext_melody_option
 * DESCRIPTION
 *  LSK fucntion for the external melodies options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_tone_setup_ext_melody_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = mmi_alm_tone_setup_convert_empty_slot_menu_list(extMldHlitItem);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx == PRF_MENU_EXTMLD_DONE)
    {
        if (PmgIsEmptySlot(g_ext_melody_idx) == MMI_FALSE)
        {
            g_alm_cntx.CurrHiliteAudioOptionValue = PMG_EXT_MELODY_BEGIN + g_ext_melody_idx;
            g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_TONE;
            g_alm_aud_opt_selected = TRUE;

            if (g_alm_tone_conf_type != PRFSET_MELODY_TYPE_PHB_RING)
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    SUCCESS_TONE);
                if(g_alm_tone_conf_type != PRFSET_MELODY_TYPE_ENGINEERMODE)
                {
                    DeleteScreenIfPresent(SCR_ID_ALM_TONE_SETUP_EXT_MELODY);
                }
                return;
            }
        }
    }
    else if (idx == PRF_MENU_EXTMLD_DEL)
    {
        if (PmgDelExtMelodyById((U16) (PMG_EXT_MELODY_BEGIN + g_ext_melody_idx)) == MMI_TRUE)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            return;
        }
    }
    else if (idx == PRF_MENU_EXTMLD_ADD)
    {
        mmi_alm_entry_tone_setup_ext_melody_drv();
        return;
    }

    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_UNFINISHED),
        IMG_GLOBAL_UNFINISHED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_tone_setup_convert_empty_slot_menu_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_alm_tone_setup_convert_empty_slot_menu_list(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PmgIsEmptySlot(g_ext_melody_idx) == MMI_FALSE)  /* Not Empty slot */
    {
        return idx;
    }
    else
    {
        if (idx == 0)
        {
            return PRF_MENU_EXTMLD_ADD; /* PRF_MENU_EXTMLD_DONE */
        }
        else
        {
            MMI_ASSERT(MMI_FALSE);
        }
    }

    return PRF_MENU_EXTMLD_MAX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_tone_setup_ext_melody_drv
 * DESCRIPTION
 *  Fucntion for handling the selection of replace option of external melodies.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_tone_setup_ext_melody_drv(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_AUDIO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF); 

    mmi_fmgr_select_path_and_enter(
        APP_PROFILES,
        FMGR_SELECT_FILE,
        filter,
        (S8*) L"root",
        mmi_alm_tone_setup_ext_melody_drv_select_callback);

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
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
#endif /*defined(__MMI_FILE_MANAGER__) ) */
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_tone_setup_ext_melody_drv_select
 * DESCRIPTION
 *  For displaying the the screen showing the drives.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_tone_setup_ext_melody_drv_select(void)
{
#if defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 phoneDrvLetter, cardDrvLetter;
    S8 temp[3];
    UI_character_type dir_phone_root[4];
    UI_character_type dir_card_root[4];
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_AUDIO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    phoneDrvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
    cardDrvLetter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    sprintf(temp, "%c:\\", (S8) phoneDrvLetter);
    mmi_asc_to_ucs2((S8*) dir_phone_root, temp);
    sprintf(temp, "%c:\\", (S8) cardDrvLetter);
    mmi_asc_to_ucs2((S8*) dir_card_root, temp);

    if (extMldHlitItem == PRF_MENU_EXTMLD_DRV_CARD)
    {
        mmi_fmgr_select_path_and_enter(
            APP_PROFILES,
            FMGR_SELECT_FILE,
            filter,
            (PS8) dir_card_root,
            mmi_alm_tone_setup_ext_melody_drv_select_callback);
    }
    else    /* if( extMldHlitItem == PRF_MENU_EXTMLD_DRV_PHONE) */
    {
        mmi_fmgr_select_path_and_enter(
            APP_PROFILES,
            FMGR_SELECT_FILE,
            filter,
            (PS8) dir_phone_root,
            mmi_alm_tone_setup_ext_melody_drv_select_callback);
    }
#endif /* defined(__MMI_FILE_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_tone_setup_ext_melody_drv_select_callback
 * DESCRIPTION
 *  The call back function called when the user selects some file for replacing an external melody.
 * PARAMETERS
 *  path            [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_tone_setup_ext_melody_drv_select_callback(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *filepath = (S8*) path;
    PMG_ADDFILE_ERRNO err = PMG_ADDFILE_ERR_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath)
    {

        if (PmgCheckImyMidFileSize(filepath) == PMG_ADDFILE_ERR_FILE_TOO_LARGE)
        {
            err = PMG_ADDFILE_ERR_FILE_TOO_LARGE;
        }
        else
        {
            PmgSetShortFileName((BOOL) is_short);
            if (PmgIsEmptySlot(g_ext_melody_idx) == MMI_FALSE)
            {
                err = PmgReplaceExtMelodyBySlotPathFileName(filepath, g_ext_melody_idx);
            }
            else
            {
                err = PmgAddExtMelodyBySlotPathFileName(filepath, g_ext_melody_idx);
            }
        }

        switch (err)
        {
            case PMG_ADDFILE_ERR_SUCCESS:
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    SUCCESS_TONE);
                break;

            case PMG_ADDFILE_ERR_STR_TOO_LONG:
            case PMG_ADDFILE_ERR_STRFILE_TOO_LONG:
            case PMG_ADDFILE_ERR_STRPATH_TOO_LONG:
                DisplayPopup(
                    (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_NAMETOOLONG),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                break;

            case PMG_ADDFILE_ERR_SLOT_FULL:
                DisplayPopup(
                    (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_LISTFULL),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                break;

            case PMG_ADDFILE_ERR_FILE_TOO_LARGE:
                DisplayPopup(
                    (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_FILETOOLARGE),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                break;

            case PMG_ADDFILE_ERR_DUPLICATED:
                DisplayPopup(
                    (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_DUPLICATED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                break;

            default:
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_UNFINISHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                break;
        }

        DeleteUptoScrID(SCR_ID_ALM_TONE_SETUP_EXT_MELODY);
        DeleteScreenIfPresent(SCR_ID_ALM_TONE_SETUP_EXT_MELODY);

    }
    else
    {
        /* DisplayPopup((PU8)GetString(STR_GLOBAL_EMPTY), 
           IMG_GLOBAL_EMPTY, 1,UI_POPUP_NOTIFYDURATION_TIME,WARNING_TONE); */
        GoBackToHistory(SCR_ID_ALM_TONE_SETUP_EXT_MELODY);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_tone_setup_delete_ext_melody
 * DESCRIPTION
 *  When the external file is deleted, Profile will call the function to update ring tone id.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_tone_setup_delete_ext_melody(U16 ToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    BOOL dirty_flag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if external melody ID is deleted */
    for (i = 0; i < NUM_OF_ALM; i++)
    {
        /* If the external ID saved in the alarm NVRAM */
        if ((g_alm_cntx.AlmList[i].AudioOption == ALM_AUDIO_OPTIONS_TONE) &&
            (g_alm_cntx.AlmList[i].AudioOptionValue == ToneId))
        {
            g_alm_cntx.AlmList[i].AudioOptionValue = (U16) (gstartMidiId + 1);
            dirty_flag = TRUE;
        }

        /* If current highlight on the alarm */
        if ((g_alm_cntx.CurrHiliteAlarm == i) &&
            (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_TONE) &&
            (g_alm_cntx.CurrHiliteAudioOptionValue == ToneId))
        {
            g_alm_cntx.CurrHiliteAudioOptionValue = (U16) (gstartMidiId + 1);
        }
    }

    /* Write result back to NVRAM */
    if (dirty_flag)
    {
        AlmWriteToNvram();
    }

}

#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_tone_setup_hilite_hdlr
 * DESCRIPTION
 *  Highlight handler for the tone list screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_tone_setup_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tempval1 = 0;
    U16 tempval2 = gtotalRingId;
    S32 data;
    BOOL play_it = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_tone_index = (U16) index;

    mmi_profiles_preview_stop_tone();

    if ((g_alm_tone_index >= tempval1) && (g_alm_tone_index < tempval2))
    {
        gcurrentaudioId = g_alm_tone_index + gstartRingId;
    }

    tempval1 = tempval2;
    tempval2 = gtotalMidiId + gtotalRingId;

    if ((g_alm_tone_index >= tempval1) && (g_alm_tone_index < tempval2))
    {
        gcurrentaudioId = g_alm_tone_index + gstartMidiId - gtotalRingId;
    }

#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    tempval1 = tempval2;
    tempval2 = gtotalMidiId + gtotalRingId + MAXIMUM_EXT_MELODY_NUM;

    if ((g_alm_tone_index >= tempval1) && (g_alm_tone_index < tempval2))
    {
        data = g_alm_tone_index - (gtotalMidiId + gtotalRingId);
        gcurrentaudioId = PMG_EXT_MELODY_BEGIN + (U16) data;
    }
#endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    if (g_alm_tone_index == tempval2)
    {
        DYNAUDIOINFO *download_theme_tones;

        if (GetThemeV2TonesInfo(&download_theme_tones) != 0 && mmi_tm_get_current_theme_ringtone())
        {
            gcurrentaudioId = (U16) download_theme_tones[0].AudioId;
            if (AudioFileDeletedFromFmgr(gcurrentaudioId))
            {
                play_it = FALSE;
            }
        }
        else
        {
            ASSERT(0);
        }
    }
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
    if (play_it)
    {
        StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_profiles_preview_play_tone);
    }
}
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_aud_opt_fmrdo
 * DESCRIPTION
 *  The entry function for the screen displaying options for fmradio audio option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_aud_opt_fmrdo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 item_count;
    U16 item_texts[10];
    U8 *item_popups[10];
    S32 i;
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ALM_AUDIO_OPT_FMRADIO, NULL, mmi_alm_entry_aud_opt_fmrdo, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_ALM_AUDIO_OPT_FMRADIO);
    item_count = GetNumOfChild(MENU_ID_ALM_AUDIO_OPT_FMRADIO);
    GetSequenceStringIds(MENU_ID_ALM_AUDIO_OPT_FMRADIO, item_texts);

    SetParentHandler(MENU_ID_ALM_AUDIO_OPT_FMRADIO);
    RegisterHighlightHandler(mmi_alm_aud_opt_fmrdo_highlight_hdlr);

    for (i = 0; i < item_count; i++)
    {
        item_popups[i] = NULL;
    }

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON, /* MAIN_MENU_TITLE_MULTIMEDIA_ICON */
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        item_count,
        item_texts,
        item_icons,
        (U8 **) item_popups,
        0,
        0,
        gui_buffer);

    /* Set the right & left arrow key handlers. */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* Set the LSK and RSK handlers. */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_opt_fmrdo_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Alarm Audio Options FM Radio options screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_opt_fmrdo_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        SetLeftSoftkeyFunction(mmi_alm_entry_aud_opt_fmrdo_channel_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_alm_entry_aud_opt_fmrdo_channel_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (index == 1)
    {
        SetLeftSoftkeyFunction(mmi_alm_entry_fmrdo_manual_input, KEY_EVENT_UP);
        SetKeyHandler(mmi_alm_entry_fmrdo_manual_input, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_aud_opt_fmrdo_channel_list
 * DESCRIPTION
 *  The entry function for the screen displaying the FM channels.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_aud_opt_fmrdo_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST, NULL, mmi_alm_entry_aud_opt_fmrdo_channel_list, NULL);

    /* register highlight handler */
    RegisterHighlightHandler(mmi_alm_aud_opt_fmrdo_channel_list_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST);

    if (gui_buffer == NULL)
    {
        if ((g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL) &&
            (g_alm_cntx.CurrHiliteAudioOptionValue > 0))
        {
            g_alm_aud_opt_fmrdo_channel_index = g_alm_cntx.CurrHiliteAudioOptionValue - 1;
        }
        else
        {
            g_alm_aud_opt_fmrdo_channel_index = 0;
        }
    }

    ShowCategory184Screen(
        STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_CHANNELLIST,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        FM_RADIO_CHANNEL_NUM,
        mmi_fmrdo_channel_list_item,
        mmi_fmrdo_channel_list_item_hint,
        g_alm_aud_opt_fmrdo_channel_index,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_opt_fmrdo_channel_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the FM Channels Screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_opt_fmrdo_channel_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_aud_opt_fmrdo_channel_index = index;

    if (g_fmrdo.channel_list.freq[g_alm_aud_opt_fmrdo_channel_index] == 0)
    {
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_alm_entry_aud_opt_fmrdo_channel_options, KEY_EVENT_UP);
        SetKeyHandler(mmi_alm_entry_aud_opt_fmrdo_channel_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_aud_opt_fmrdo_channel_options
 * DESCRIPTION
 *  The entry function for the channel options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_aud_opt_fmrdo_channel_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 item_texts[] = {STR_GLOBAL_SELECT, STR_GLOBAL_PLAY};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};
    U8 *item_popups[] = {NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ALM_AUDIO_OPT_FMRDO_CHANNEL_OPT, NULL, mmi_alm_entry_aud_opt_fmrdo_channel_options, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_ALM_AUDIO_OPT_FMRDO_CHANNEL_OPT);
    RegisterHighlightHandler(mmi_alm_fmrdo_channel_opt_highlight_hdlr);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        item_texts,
        item_icons,
        (U8 **) item_popups,
        0,
        0,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_alm_aud_opt_fmrdo_channel_opt_lsk_hdlr, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* Set Key handlers */
    SetKeyHandler(mmi_alm_aud_opt_fmrdo_channel_opt_lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_fmrdo_channel_opt_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the FM Radio channel options screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_fmrdo_channel_opt_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[] = {STR_GLOBAL_SELECT, STR_GLOBAL_PLAY};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_aud_opt_fmrdo_channel_opt_index = item_texts[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_opt_fmrdo_channel_opt_lsk_hdlr
 * DESCRIPTION
 *  LSK function for the FM Radio channel options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_opt_fmrdo_channel_opt_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_alm_aud_opt_fmrdo_channel_opt_index)
    {
        case STR_GLOBAL_SELECT: /* for selecting a particular FM channel for alarm. */
            g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL;
            g_alm_cntx.CurrHiliteAudioOptionValue = g_alm_aud_opt_fmrdo_channel_index + 1;

            g_alm_aud_opt_selected = TRUE;
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            DeleteUptoScrID(SCR_ID_ALM_EDITOR);
            break;

        case STR_GLOBAL_PLAY:
            g_alm_fmrdo_prev_freq = g_fmrdo.channel_list.freq[g_alm_aud_opt_fmrdo_channel_index];
    #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
            if (!isEarphonePlugged)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME_2000,
                    WARNING_TONE);
            }
            else
    #endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
                mmi_alm_entry_fmrdo_prev_channel();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_manual_input
 * DESCRIPTION
 *  The entry function for the manual input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_fmrdo_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ALM_FMRDO_MANUAL_INPUT, mmi_alm_exit_fmrdo_manual_input, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_ALM_FMRDO_MANUAL_INPUT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_ALM_FMRDO_MANUAL_INPUT, &inputBufferSize);

    RegisterHighlightHandler(mmi_alm_fmrdo_manual_input_highlight_hdlr);

    if (guiBuffer == NULL)
    {
        if (g_alm_cntx.CurrHiliteAudioOption != ALM_AUDIO_OPTIONS_FMRADIO_MANUAL || g_alm_cntx.CurrHiliteAudioOptionValue == 0)
        {
            memset(channel_manual_input_buffer, 0, 2);
        }
        else
        {
            kal_wsprintf(
                channel_manual_input_buffer,
                "%d.%d",
                g_alm_cntx.CurrHiliteAudioOptionValue / 10,
                g_alm_cntx.CurrHiliteAudioOptionValue % 10);
        }
    }

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[0],
        (U8*) channel_manual_input_buffer,
        MAX_MANUAL_INPUT_LEN,
        INPUT_TYPE_DECIMAL_NUMERIC);
    LeftJustifyInlineItem(&wgui_inline_items[0]);
    SetInlineItemFullWidth(&wgui_inline_items[0]);
    EnableInlineItemBoundary(&wgui_inline_items[0]);

    DisableCategory57ScreenDone();

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_MAN_INPUT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,    /* title text and icon */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,                 /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        1,
        0,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_alm_fmrdo_manual_input_options);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_exit_fmrdo_manual_input
 * DESCRIPTION
 *  The exit function for the manual input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_exit_fmrdo_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_ALM_FMRDO_MANUAL_INPUT;
    h.entryFuncPtr = mmi_alm_entry_fmrdo_manual_input;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_fmrdo_manual_input_highlight_hdlr
 * DESCRIPTION
 *  The highlight handler function for the manual input screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_fmrdo_manual_input_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_fmrdo_manual_input_options
 * DESCRIPTION
 *  The LSK function for manual input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_fmrdo_manual_input_options()
{   /* calculate frequency number */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = mmi_fmrdo_get_freq_from_str(channel_manual_input_buffer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check frequency input */
    if (freq == 0xffff) /* invalid decimal digit */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMRDO_VALID_FM_DECIMAL),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) WARNING_TONE);
    }
    else if (freq < MIN_FM_FREQUENCY || freq > MAX_FM_FREQUENCY)        /* warning invalid frequency */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_ALM_FMRDO_VALID_FM_BANDWIDTH),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) WARNING_TONE);
    }
    else
    {
        mmi_alm_entry_fmrdo_manual_input_options();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_manual_input_options
 * DESCRIPTION
 *  Entry function for the manual input options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_fmrdo_manual_input_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_PLAY};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};
    U8 *item_popups[] = {NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ALM_FMRDO_MANUAL_INPUT_OPT, NULL, mmi_alm_entry_fmrdo_manual_input_options, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_ALM_FMRDO_MANUAL_INPUT_OPT);
    RegisterHighlightHandler(mmi_alm_fmrdo_manual_input_opt_highlight_hdlr);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        item_texts,
        item_icons,
        (U8 **) item_popups,
        0,
        0,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_alm_fmrdo_manual_input_opt_lsk_hdlr, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_fmrdo_manual_input_opt_lsk_hdlr
 * DESCRIPTION
 *  LSK handler for the manual input options screen
 * PARAMETERS
 *  void
 *  index(?)        [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_fmrdo_manual_input_opt_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = mmi_fmrdo_get_freq_from_str(channel_manual_input_buffer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_alm_fmrdo_man_inp_opt_index)
    {
        case STR_GLOBAL_DONE:
            g_alm_cntx.CurrHiliteAudioOptionValue = freq;
            g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_FMRADIO_MANUAL;
            g_alm_aud_opt_selected = TRUE;
            GoBackToHistory(SCR_ID_ALM_EDITOR);
            break;

        case STR_GLOBAL_PLAY:
            g_alm_fmrdo_prev_freq = freq;
    #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
            if (!isEarphonePlugged)
            {
                /* DisplayPopupCallBack( (PU8)GetString( STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE ), IMG_GLOBAL_WARNING, 1, 2000, (U8)WARNING_TONE,mmi_alm_entry_fmrdo_prev_channel ); */
                DisplayPopup(
                    (U8*) GetString(STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME_2000,
                    WARNING_TONE);
            }
            else
    #endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
                mmi_alm_entry_fmrdo_prev_channel();

            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_prev_channel
 * DESCRIPTION
 *  Entry function for the preview screen
 * PARAMETERS
 *  void
 *  index(?)        [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_fmrdo_prev_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str[32];
    U8 vol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(str, "FM %d.%d", g_alm_fmrdo_prev_freq / 10, g_alm_fmrdo_prev_freq % 10);

    /* mdi function calls */
    vol = mmi_fmrdo_get_volume();
    mdi_audio_stop_fmr();
    mdi_audio_set_volume(AUD_VOLUME_FMR, vol);
    mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, NULL);
    mdi_fmr_set_freq(g_alm_fmrdo_prev_freq);

    EntryNewScreen(SCR_ID_ALM_FMRDO_PREV, mmi_alm_exit_fmrdo_prev_channel, NULL, NULL);
    /* clear End key */
    //ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    //ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    /* Show searching screen */
    ShowCategory66Screen(
        STR_GLOBAL_PLAY,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_exit_fmrdo_prev_channel
 * DESCRIPTION
 *  The interface for calling the mdi function for stopping the FM Radio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_exit_fmrdo_prev_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_fmr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_fmrdo_manual_input_opt_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the manual input options screen
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_fmrdo_manual_input_opt_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_PLAY};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_fmrdo_man_inp_opt_index = item_texts[index];
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAlmInlineAudioOptions
 * DESCRIPTION
 *  Highlight handler of Alarm Audio Options inline selection item in editor screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmInlineAudioOptions(S32 index)
{
#if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DYNAUDIOINFO *download_theme_tones = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_get_current_theme_ringtone())
    {
        GetThemeV2TonesInfo(&download_theme_tones);
    }
#endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
    /* If selection item changed */
    if (!((g_alm_cntx.CurrHiliteAudioOption && index) || (!g_alm_cntx.CurrHiliteAudioOption && !index)))
    {
        g_alm_cntx.CurrHiliteAudioOptionValue = 0;
        Category57ChangeItemText(g_alm_aud_opt_curselitem_inline_index, (U8*) GetString(STR_GLOBAL_EMPTY_LIST));

    #ifndef __MMI_ALM_CUSTOMIZE_TONE__
        if (!index)
        {
            U16 sel_tone = gcurrentprofile.toneSetup.alarmTone;
            U8 tone_index;

            g_alm_cntx.CurrHiliteAudioOptionValue = gcurrentprofile.toneSetup.alarmTone;
            if ((sel_tone >= gstartRingId) && (sel_tone <= (gstartRingId + gtotalRingId - 1)))
            {
                tone_index = sel_tone - gstartRingId;
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString((U16) (STR_PROFILES_RING_1 + tone_index)));
            }
            else if ((sel_tone) >= gstartMidiId && (sel_tone) <= (gstartMidiId + gtotalMidiId - 1))
            {
                tone_index = (sel_tone - (gstartMidiId) + gtotalRingId);
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString((U16) (STR_PROFILES_RING_1 + tone_index)));
            }
        #if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
            else if (sel_tone >= PMG_EXT_MELODY_BEGIN && sel_tone <= PMG_EXT_MELODY_END)
            {
                DYNEXTMELODYINFO *ExtMelodyInfo;

                tone_index = sel_tone - PMG_EXT_MELODY_BEGIN;
                PmgGetExtMelodyInfo(&ExtMelodyInfo);

                if(g_alm_ext_melody_short_name_ptr != NULL)
                {
                    if (IS_EXTMELODY_SHORTNAME(ExtMelodyInfo->info[tone_index].filepath))
                    {
                        mmi_chset_mixed_text_to_ucs2_str(
                            g_alm_ext_melody_short_name_ptr,
                            MAX_EXT_MELODY_NAME_WIDTH,
                            (U8*) ExtMelodyInfo->info[tone_index].filename,
                            g_chset_text_encoding);
                    }
                    else
                    {
                        memcpy(g_alm_ext_melody_short_name_ptr, ExtMelodyInfo->info[tone_index].filename, MAX_EXT_MELODY_NAME_WIDTH);
                    }
                    
                #if (!defined(__MMI_SHOW_FILE_EXT__))
                    PmgRemoveFileExt((S8*) g_alm_ext_melody_short_name_ptr);
                #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
                    PmgRemoveFileDAFExt((S8*) g_alm_ext_melody_short_name_ptr);
                #endif
                    Category57ChangeItemText(g_alm_aud_opt_curselitem_inline_index, g_alm_ext_melody_short_name_ptr);
                }
            }
        #endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 
        #if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
            else if (download_theme_tones != NULL && sel_tone == download_theme_tones[0].AudioId)
            {
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString(STR_PROFILES_CURR_THEME));
            }
        #endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
        }
    #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
    }
    else    /* if the user has selected the same audio option which is the CurrHiliteAudioOption */
    {
        if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
        {
            U16 index = g_alm_cntx.CurrHiliteAudioOptionValue - 1;

            if (g_fmrdo.channel_list.freq[index] < MIN_FM_FREQUENCY ||
                g_fmrdo.channel_list.freq[index] > MAX_FM_FREQUENCY)
            {
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString((U16) (STR_GLOBAL_EMPTY_LIST)));
            }
            else
            {
                Category57ChangeItemText(g_alm_aud_opt_curselitem_inline_index, (U8*) g_alm_audio_options_curselitem);
            }
        }
        else if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)
        {
            if (g_alm_cntx.CurrHiliteAudioOptionValue < MIN_FM_FREQUENCY ||
                g_alm_cntx.CurrHiliteAudioOptionValue > MAX_FM_FREQUENCY)
            {
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString((U16) (STR_GLOBAL_EMPTY_LIST)));
            }
            else
            {
                Category57ChangeItemText(g_alm_aud_opt_curselitem_inline_index, (U8*) g_alm_audio_options_curselitem);
            }
        }
        else
        {
        #ifdef __MMI_ALM_CUSTOMIZE_TONE__
            U16 sel_tone = g_alm_cntx.CurrHiliteAudioOptionValue;
        #else 
            U16 sel_tone = gcurrentprofile.toneSetup.alarmTone;
        #endif 
            U8 tone_index;

            if ((sel_tone >= gstartRingId) && (sel_tone <= (gstartRingId + gtotalRingId - 1)))
            {
                tone_index = sel_tone - gstartRingId;
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString((U16) (STR_PROFILES_RING_1 + tone_index)));
            }
            else if ((sel_tone >= gstartMidiId) && (sel_tone <= (gstartMidiId + gtotalMidiId - 1)))
            {
                tone_index = (sel_tone - gstartMidiId + gtotalRingId);
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString((U16) (STR_PROFILES_RING_1 + tone_index)));
            }
        #if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
            else if (sel_tone >= PMG_EXT_MELODY_BEGIN && sel_tone <= PMG_EXT_MELODY_END)
            {
                DYNEXTMELODYINFO *ExtMelodyInfo;

                tone_index = sel_tone - PMG_EXT_MELODY_BEGIN;
                PmgGetExtMelodyInfo(&ExtMelodyInfo);

                if(g_alm_ext_melody_short_name_ptr != NULL)
                {
                    if (IS_EXTMELODY_SHORTNAME(ExtMelodyInfo->info[tone_index].filepath))
                    {
                        mmi_chset_mixed_text_to_ucs2_str(
                            g_alm_ext_melody_short_name_ptr,
                            MAX_EXT_MELODY_NAME_WIDTH,
                            (U8*) ExtMelodyInfo->info[tone_index].filename,
                            g_chset_text_encoding);
                    }
                    else
                    {
                        memcpy(g_alm_ext_melody_short_name_ptr, ExtMelodyInfo->info[tone_index].filename, MAX_EXT_MELODY_NAME_WIDTH);
                    }
                    
                #if (!defined(__MMI_SHOW_FILE_EXT__))
                    PmgRemoveFileExt((S8*) g_alm_ext_melody_short_name_ptr);
                #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
                    PmgRemoveFileDAFExt((S8*) g_alm_ext_melody_short_name_ptr);
                #endif                    
                    Category57ChangeItemText(g_alm_aud_opt_curselitem_inline_index, g_alm_ext_melody_short_name_ptr);
                }
            }
        #endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 
        #if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
            else if (download_theme_tones != NULL && sel_tone == download_theme_tones[0].AudioId)
            {
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString(STR_PROFILES_CURR_THEME));
            }
        #endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
            else
            {
                g_alm_cntx.CurrHiliteAudioOptionValue = 0;
                Category57ChangeItemText(
                    g_alm_aud_opt_curselitem_inline_index,
                    (U8*) GetString((U16) (STR_GLOBAL_EMPTY_LIST)));
            }

        }
    }

    RedrawCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_fmrdo_init_channe_list
 * DESCRIPTION
 *  This function is to check if the channel in FM radio initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_fmrdo_init_channe_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_ready && !g_alm_fmrdo_read_channel_name)
    {
        ReadRecord(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE, &error);

        if(g_fmrdo.channel_list.name[0][0] == 0xFFFF)
        {
            memset(&g_fmrdo.channel_list, 0, sizeof(mmi_fmrdo_channel_list_struct));
        }

        g_alm_fmrdo_read_channel_name = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_fmrdo_play_alarm
 * DESCRIPTION
 *  This function is to play the FM radio when alarm expired.
 * PARAMETERS
 *  alarm_index     [IN]        
 *  volume          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_fmrdo_play_alarm(U8 alarm_index, U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if FM Radio freqency set */
    if (g_alm_cntx.AlmList[alarm_index].AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        mmi_alm_aud_fmrdo_init_channe_list();

        if ((g_alm_cntx.AlmList[alarm_index].AudioOptionValue > 0) &&
            (g_alm_cntx.AlmList[alarm_index].AudioOptionValue <= FM_RADIO_CHANNEL_NUM))
        {
            freq = g_fmrdo.channel_list.freq[g_alm_cntx.AlmList[alarm_index].AudioOptionValue - 1];
        }

    }
    else if (g_alm_cntx.AlmList[alarm_index].AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)
    {
        freq = g_alm_cntx.AlmList[alarm_index].AudioOptionValue;
    }

    if ((freq >= MIN_FM_FREQUENCY) && (freq <= MAX_FM_FREQUENCY))
    {
        mdi_audio_stop_fmr();
        mdi_audio_set_volume(MDI_VOLUME_FMR, volume);
        mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, NULL);
        mdi_fmr_set_freq(freq);
    }
    /* Play default ring tone and restore alarm to default value */
    else
    {
        g_alm_cntx.AlmList[alarm_index].AudioOption = ALM_AUDIO_OPTIONS_TONE;
        g_alm_cntx.AlmList[alarm_index].AudioOptionValue = (U16) (gstartMidiId + 1);

        AlmWriteToNvram();
        playRequestedTone(ALARM_TONE);
    }

}

#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 


/*****************************************************************************
 * FUNCTION
 *  AlmIsInlineEditorChanged
 * DESCRIPTION
 *  To check if alarm is changed in inline editor screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  TURE if alarm is changed; otherwise, FLASE.
 *****************************************************************************/
BOOL AlmIsInlineEditorChanged(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmpHour = (g_alm_cntx.HourBuf[0] - '0') * 10 + (g_alm_cntx.HourBuf[ENCODING_LENGTH] - '0');
    U8 tmpMin = (g_alm_cntx.MinBuf[0] - '0') * 10 + (g_alm_cntx.MinBuf[ENCODING_LENGTH] - '0');

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
#ifdef __MMI_ALM_CUST_VOLUME__
           (g_alm_cntx.AlmList[index].Volume != g_alm_cntx.CurrHiliteVol) ||
#endif 
           (g_alm_cntx.AlmList[index].State != g_alm_cntx.CurrHiliteState) ||
           (g_alm_cntx.AlmList[index].Freq != (U8) g_alm_cntx.CurrHiliteFreq) ||
           (g_alm_cntx.AlmList[index].Hour != tmpHour) || (g_alm_cntx.AlmList[index].Min != tmpMin))
    {
        return TRUE;
    }
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    else if ((g_alm_cntx.AlmList[index].AudioOption != g_alm_cntx.CurrHiliteAudioOption))
    {
        return TRUE;
    }
    else if (g_alm_cntx.AlmList[index].AudioOptionValue != g_alm_cntx.CurrHiliteAudioOptionValue)
    {
        return TRUE;
    }
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 
    else if (g_alm_freq_set[g_alm_cntx.AlmList[index].Freq] == ALM_FREQ_DAYS)
    {
        return TRUE;
    }
#ifdef __MMI_ALM_SNOOZE_SETTING__
    else if (g_alm_cntx.AlmList[index].SnoozeInterval != (U8) g_alm_cntx.CurrHilightSnoozeInterval)
    {
        return TRUE;
    }
#endif /* __MMI_ALM_SNOOZE_SETTING__ */ 
#ifdef __MMI_ALM_ALERT_TYPE__
    else if (g_alm_cntx.AlmList[index].AlertType != (U8) g_alm_cntx.CurrHilightAlertType)
    {
        return TRUE;
    }
#endif /* __MMI_ALM_ALERT_TYPE__ */ 
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  AlmInlineEditHighlightHdlr
 * DESCRIPTION
 *  Alarm editor highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInlineEditHighlightHdlr(S32 index)
{
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == g_alm_aud_opt_curselitem_inline_index)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);

        if (g_alm_audio_option_previndex == ALM_AUDIO_OPTIONS_TONE)
        {
        #ifdef __MMI_ALM_CUSTOMIZE_TONE__
            SetLeftSoftkeyFunction(mmi_alm_entry_aud_opt_tone, KEY_EVENT_UP);
        #else /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

        }
        else
        {
            SetLeftSoftkeyFunction(mmi_alm_entry_aud_opt_fmrdo, KEY_EVENT_UP);
        }
    }

#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmEditScreen
 * DESCRIPTION
 *  Display inline editor screen of alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmEditScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U8 nMenuItems;

    U16 alarm_icon_list[] = {IMG_STATUS, IMG_TIME, IMG_REPEAT, 0, 0
    #ifdef __MMI_ALM_CUST_VOLUME__
            , ALARM_VOLUME_IMAGEID, 0
    #endif 
    #ifdef __MMI_ALM_AUDIO_OPTIONS__
            , IMG_ALM_AUD_OPT, 0, 0
    #endif 
    #ifdef __MMI_ALM_SNOOZE_SETTING__
            , ALARMS_SET_SNOOZE_PERIOD_IMAGEID, 0
    #endif 
    #ifdef __MMI_ALM_ALERT_TYPE__
            , ALARMS_SET_ALERT_TYPE_IMAGEID, 0
    #endif 
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nMenuItems = sizeof(alarm_icon_list) / sizeof(U16);
    EntryNewScreen(SCR_ID_ALM_EDITOR, ExitAlmEditScreen, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_ALM_EDITOR);
    InitializeCategory57Screen();
    RegisterHighlightHandler(AlmInlineEditHighlightHdlr);

    /* Use screen base memory to display short name of external melody*/
#if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    g_alm_ext_melody_short_name_ptr = (U8*) mmi_frm_scrmem_alloc(MAX_EXT_MELODY_NAME_WIDTH);
#endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */
    AlmFillInlineEditStruct();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_ALM_EDITOR, &inputBufferSize);     /* added for inline edit history */

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, nMenuItems, inputBuffer);
    }
    
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    if(guiBuffer == NULL)
    {
        g_alm_aud_opt_selected = FALSE;
    }
    else if (g_alm_aud_opt_selected)
    {
        SetInlineDoneFlag(guiBuffer);
    }
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

    ShowCategory57Screen(
        ALARM_EDIT_TITLE_STRINGID,
        GetRootTitleIcon(ORGANIZER_ALARM_MENU),
        ALARM_STR_DONE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nMenuItems,
        alarm_icon_list,
        wgui_inline_items,
        /* currItemAlarmEdit */ 0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EntryAlmSaveConfirmation, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitAlmEditScreen
 * DESCRIPTION
 *  Exit function for inline editor screen of alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitAlmEditScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_ALM_EDITOR;
    CloseCategory57Screen();
    Scr.entryFuncPtr = EntryAlmEditScreen;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, inputBufferSize);                  /* added for inline edit history */

    /* Free screen memory*/
#if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    mmi_frm_scrmem_free((void*)g_alm_ext_melody_short_name_ptr);
    g_alm_ext_melody_short_name_ptr = NULL;
#endif /*defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)*/

}


/*****************************************************************************
 * FUNCTION
 *  AlmTimeEditorCallBack
 * DESCRIPTION
 *  Callback function for inline time editor.
 * PARAMETERS
 *  string_buffer       [IN/OUT]        Buffer to store the result of time
 *  hours_buffer        [IN]            Buffer to store hour string
 *  min_buffer          [IN]            Buffer to store minute string
 *  AM_PM_flag          [IN]            Flag to indicate the time format of time string
 * RETURNS
 *  void
 *****************************************************************************/
void AlmTimeEditorCallBack(U8 *string_buffer, U8 *hours_buffer, U8 *min_buffer, U8 *AM_PM_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) string_buffer, (S8*) hours_buffer);
    mmi_ucs2cat((S8*) string_buffer, (S8*) ":");
    mmi_ucs2cat((S8*) string_buffer, (S8*) min_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  AlmFillInlineEditStruct
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmFillInlineEditStruct()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inline_item_index = 0, j;

#if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    DYNEXTMELODYINFO *ExtMelodyInfo;
#endif 
#if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    DYNAUDIOINFO *download_theme_tones = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_get_current_theme_ringtone())
    {
        GetThemeV2TonesInfo(&download_theme_tones);
    }
#endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
#ifdef __MMI_ALM_CUST_VOLUME__
    gAlmVolumeList[0] = (S8*) gAlmVolumeString[0];
    gAlmVolumeList[1] = (S8*) gAlmVolumeString[1];
    gAlmVolumeList[2] = (S8*) gAlmVolumeString[2];
    gAlmVolumeList[3] = (S8*) gAlmVolumeString[3];
    gAlmVolumeList[4] = (S8*) gAlmVolumeString[4];
    gAlmVolumeList[5] = (S8*) gAlmVolumeString[5];
    gAlmVolumeList[6] = (S8*) gAlmVolumeString[6];
#endif /* __MMI_ALM_CUST_VOLUME__ */ 

#ifdef __MMI_ALM_SNOOZE_SETTING__
    gAlmSettingSnooze[0] = GetString((U16) STR_ID_ALM_DEFAULT);
    gAlmSettingSnooze[1] = GetString((U16) STR_GLOBAL_1);
    gAlmSettingSnooze[2] = GetString((U16) STR_GLOBAL_2);
    gAlmSettingSnooze[3] = GetString((U16) STR_GLOBAL_3);
    gAlmSettingSnooze[4] = GetString((U16) STR_GLOBAL_4);
    gAlmSettingSnooze[5] = GetString((U16) STR_GLOBAL_5);
    gAlmSettingSnooze[6] = GetString((U16) STR_GLOBAL_6);
    gAlmSettingSnooze[7] = GetString((U16) STR_GLOBAL_7);
    gAlmSettingSnooze[8] = GetString((U16) STR_GLOBAL_8);
    gAlmSettingSnooze[9] = GetString((U16) STR_GLOBAL_9);
    gAlmSettingSnooze[10] = GetString((U16) STR_GLOBAL_10);
#endif /* __MMI_ALM_SNOOZE_SETTING__ */ 

#ifdef __MMI_ALM_ALERT_TYPE__
#ifndef __VIBRATOR_TONE_SUPPORT__   //su-2008/12/04
    gAlmSettingAlertType[ALM_ALERT_VIBRATION_AND_RING] = GetString((U16) STR_VIBRATION_AND_RING);
    gAlmSettingAlertType[ALM_ALERT_RING] = GetString((U16) STR_RING);
    gAlmSettingAlertType[ALM_ALERT_VIBRATION] = GetString((U16) STR_VIBRATION_ONLY);
#else
	//gAlmSettingAlertType[ALM_ALERT_VIBRATION_AND_RING] = GetString((U16) STR_VIBRATION_AND_RING);
    gAlmSettingAlertType[ALM_ALERT_RING] = GetString((U16) STR_RING);
    gAlmSettingAlertType[ALM_ALERT_VIBRATION] = GetString((U16) STR_VIBRATION_ONLY);
#endif
#endif /* __MMI_ALM_ALERT_TYPE__ */ 

    for (j = 0; j < ALARM_FREQ_NUM; j++)
    {
        gAlmFreqList[j] = GetString((U16) (g_alm_freq_set[j] + ALARM_REPEAT_OFF_INDEX));
    }
    /* ON/OFF */
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &(wgui_inline_items[inline_item_index]),
        NUM_STATE_FOR_ALM,
        (U8 **) gAlmOnOffString,
        &g_alm_cntx.CurrHiliteState /* (gAlmCurrHiliteState[g_alm_cntx.CurrHiliteAlarm]) */ );
    DisableInlineItemHighlight(&(wgui_inline_items[inline_item_index]));

    /* time */
    inline_item_index++;
    SetInlineItemActivation(
        &(wgui_inline_items[inline_item_index]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        KEY_EVENT_UP);
    SetInlineItemTime(
        &(wgui_inline_items[inline_item_index]),
        (U8*) g_alm_cntx.HourBuf,
        (U8*) g_alm_cntx.MinBuf,
        NULL,
        AlmTimeEditorCallBack);
    DisableInlineItemHighlight(&(wgui_inline_items[inline_item_index]));

    /* repeat caption */
    inline_item_index++;
    SetInlineItemCaption(&(wgui_inline_items[inline_item_index]), (U8*) GetString(ALARM_REPEAT_STRING));

    /* repeat */
    inline_item_index++;
    SetInlineItemSelect(&(wgui_inline_items[inline_item_index]), ALARM_FREQ_NUM, (U8 **) gAlmFreqList, &g_alm_cntx.CurrHiliteFreq);     /* -2 forweekdays and monthly */
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[inline_item_index], HighlightAlmInlineRepeat);

    /* day of week */
    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] != ALM_FREQ_DAYS)     /* not Days */
    {
        memset(gAlmDaysStates, 0, 7);
    }

    inline_item_index++;
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDOWSelect(&(wgui_inline_items[inline_item_index]), inline_item_index, gAlmDaysStates);

    /* day of week */
    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] != ALM_FREQ_DAYS)     /* not Days */
    {
        DisableInlineItem(&wgui_inline_items[inline_item_index], 4);    /* multi select days */
    }

#ifdef __MMI_ALM_CUST_VOLUME__
    /* volume */
    inline_item_index++;
    SetInlineItemCaption(&(wgui_inline_items[inline_item_index]), (U8*) GetString(ALARMS_VOLUME));
    inline_item_index++;
    SetInlineItemSelect(&(wgui_inline_items[inline_item_index]), (LEVEL7 + 1), (U8 **) gAlmVolumeList, &g_alm_cntx.CurrHiliteVol);      /* -2 forweekdays and monthly */
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#endif /* __MMI_ALM_CUST_VOLUME__ */ 

    /* Customize Ring Tone and FM alarm */
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    /* Ring Tone Caption */
    inline_item_index++;
    SetInlineItemCaption(&(wgui_inline_items[inline_item_index]), (U8*) GetString(STR_ID_ALM_AUDIO_OPTIONS));
    g_alm_audio_option_previndex =
        (g_alm_cntx.CurrHiliteAudioOption >
         ALM_AUDIO_OPTIONS_TONE) ? ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL : ALM_AUDIO_OPTIONS_TONE;
    inline_item_index++;

    /* Ring Tone Inline Selectt */
    SetInlineItemSelect(
        &(wgui_inline_items[inline_item_index]),
        NUM_AUDIO_OPTIONS,
        (U8 **) g_alm_audio_options_string,
        &g_alm_audio_option_previndex);
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[inline_item_index], HighlightAlmInlineAudioOptions);
    inline_item_index++;

    g_alm_aud_opt_curselitem_inline_index = inline_item_index;

    if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        if ((g_alm_cntx.CurrHiliteAudioOptionValue > 0) &&
            (g_alm_cntx.CurrHiliteAudioOptionValue <= FM_RADIO_CHANNEL_NUM))
        {
            U8 list_index = g_alm_cntx.CurrHiliteAudioOptionValue - 1;

            if (mmi_ucs2strlen((S8*) g_fmrdo.channel_list.name[list_index]))
            {
                mmi_ucs2cpy((S8*) g_alm_audio_options_curselitem, (S8*) g_fmrdo.channel_list.name[list_index]);
            }
            else
            {
                kal_wsprintf(
                    g_alm_audio_options_curselitem,
                    "FM %d.%d",
                    g_fmrdo.channel_list.freq[list_index] / 10,
                    g_fmrdo.channel_list.freq[list_index] % 10);
            }
        }
        else
        {
            mmi_ucs2cpy((S8*) g_alm_audio_options_curselitem, GetString(STR_GLOBAL_EMPTY_LIST));
        }

        SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemDisplayOnly(&(wgui_inline_items[inline_item_index]), (U8*) g_alm_audio_options_curselitem);
    }
    else if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)
    {
        if (g_alm_cntx.CurrHiliteAudioOptionValue > 0)
        {
            kal_wsprintf(
                g_alm_audio_options_curselitem,
                "FM %d.%d",
                g_alm_cntx.CurrHiliteAudioOptionValue / 10,
                g_alm_cntx.CurrHiliteAudioOptionValue % 10);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_alm_audio_options_curselitem, GetString(STR_GLOBAL_EMPTY_LIST));
        }

        SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemDisplayOnly(&(wgui_inline_items[inline_item_index]), (U8*) g_alm_audio_options_curselitem);
    }
    else
    {
    #ifdef __MMI_ALM_CUSTOMIZE_TONE__
        U16 sel_tone = g_alm_cntx.CurrHiliteAudioOptionValue;
    #else 
        U16 sel_tone = gcurrentprofile.toneSetup.alarmTone;
    #endif 
        U8 tone_index;

        SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

        /* Ring Tone as Alarm */
        if ((sel_tone >= gstartRingId) && (sel_tone <= (gstartRingId + gtotalRingId - 1)))
        {
            tone_index = sel_tone - gstartRingId;
            SetInlineItemDisplayOnly(
                &(wgui_inline_items[inline_item_index]),
                (U8*) GetString((U16) (STR_PROFILES_RING_1 + tone_index)));
        }
        /* Midi Tone as Alarm */
        else if ((sel_tone >= gstartMidiId) && (sel_tone <= (gstartMidiId + gtotalMidiId - 1)))
        {
            tone_index = (sel_tone - gstartMidiId + gtotalRingId);
            SetInlineItemDisplayOnly(
                &(wgui_inline_items[inline_item_index]),
                (U8*) GetString((U16) (STR_PROFILES_RING_1 + tone_index)));
        }
        /* External Resource as Alarm */
    #if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
        else if (sel_tone >= PMG_EXT_MELODY_BEGIN && sel_tone <= PMG_EXT_MELODY_END)
        {
            tone_index = sel_tone - PMG_EXT_MELODY_BEGIN;
            PmgGetExtMelodyInfo(&ExtMelodyInfo);

            if(g_alm_ext_melody_short_name_ptr != NULL)
            {
                if (IS_EXTMELODY_SHORTNAME(ExtMelodyInfo->info[tone_index].filepath))
                {
                    mmi_chset_mixed_text_to_ucs2_str(
                        g_alm_ext_melody_short_name_ptr,
                        MAX_EXT_MELODY_NAME_WIDTH,
                        (U8*) ExtMelodyInfo->info[tone_index].filename,
                        g_chset_text_encoding);
                }
                else
                {
                    memcpy(g_alm_ext_melody_short_name_ptr, (ExtMelodyInfo->info[tone_index]).filename, MAX_EXT_MELODY_NAME_WIDTH);
                }
            #if (!defined(__MMI_SHOW_FILE_EXT__))
                PmgRemoveFileExt((S8*) g_alm_ext_melody_short_name_ptr);
            #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
                PmgRemoveFileDAFExt((S8*) g_alm_ext_melody_short_name_ptr);
            #endif                
                SetInlineItemDisplayOnly(&(wgui_inline_items[inline_item_index]),g_alm_ext_melody_short_name_ptr);
            }
        }
    #endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 
    #if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
        else if (download_theme_tones != NULL && sel_tone == download_theme_tones[0].AudioId)
        {
            mmi_ucs2cpy((S8*) g_alm_audio_options_curselitem, GetString(STR_PROFILES_CURR_THEME));
            SetInlineItemDisplayOnly(&(wgui_inline_items[inline_item_index]), (U8*) g_alm_audio_options_curselitem);
        }
    #endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
        /* Ring tone range incorrect or not initialized */
        else
        {
            mmi_ucs2cpy((S8*) g_alm_audio_options_curselitem, GetString(STR_GLOBAL_EMPTY_LIST));
            SetInlineItemDisplayOnly(&(wgui_inline_items[inline_item_index]), (U8*) g_alm_audio_options_curselitem);
        }
    }

#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ // #ifdef __MMI_ALM_AUDIO_OPTIONS__
#ifdef __MMI_ALM_SNOOZE_SETTING__
    inline_item_index++;
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(
        &(wgui_inline_items[inline_item_index]),
        (U8*) GetString((U16) ALARMS_SETTING_SNOOZE_INTERVAL));

    inline_item_index++;
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &(wgui_inline_items[inline_item_index]),
        (S32) ALM_SNOOZE_INTERVAL_SETTING_NUM,
        (U8 **) gAlmSettingSnooze,
        &(g_alm_cntx.CurrHilightSnoozeInterval));
    /* RegisterInlineSelectHighlightHandler(&wgui_inline_items[SNOOZE_INTERVAL],mmi_hightlight_snooze_selection); */
#endif /* __MMI_ALM_SNOOZE_SETTING__ */ 

#ifdef __MMI_ALM_ALERT_TYPE__
    inline_item_index++;
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[inline_item_index]), (U8*) GetString((U16) STR_MT_CALL_ALERT_TYPE));

    inline_item_index++;
    SetInlineItemActivation(&(wgui_inline_items[inline_item_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &(wgui_inline_items[inline_item_index]),
        (S32) ALM_ALERT_TYPE_SETTING_NUM,
        (U8 **) gAlmSettingAlertType,
        &(g_alm_cntx.CurrHilightAlertType));
#endif /* __MMI_ALM_ALERT_TYPE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  AlmSaveInlineEdit
 * DESCRIPTION
 *  Save alarm to nvram and set/cancel alarm to driver accordingly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSaveInlineEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (AlmIsInlineEditorChanged(g_alm_cntx.CurrHiliteAlarm))
    {
        S32 i, j;

        i = g_alm_cntx.CurrHiliteAlarm;

        g_alm_cntx.AlmList[i].Freq = (U8) g_alm_cntx.CurrHiliteFreq;
        g_alm_cntx.AlmList[i].Days = 0;

        if (g_alm_freq_set[g_alm_cntx.AlmList[i].Freq] == ALM_FREQ_DAYS)
        {
            for (j = 0; j < NUM_DAYS; j++)
            {
                g_alm_cntx.AlmList[i].Days |= (gAlmDaysStates[j] << j);
            }

            if (g_alm_cntx.AlmList[i].Days == 0)
            {
                g_alm_cntx.AlmList[i].Freq = mmi_alm_get_freq_order(ALARM_FREQ_NUM, g_alm_freq_set, ALM_FREQ_ONCE);
            }
        }

        g_alm_cntx.AlmList[i].State = (U8) g_alm_cntx.CurrHiliteState;
        g_alm_cntx.AlmList[i].Hour = (g_alm_cntx.HourBuf[0] - '0') * 10 + (g_alm_cntx.HourBuf[ENCODING_LENGTH] - '0');
        g_alm_cntx.AlmList[i].Min = (g_alm_cntx.MinBuf[0] - '0') * 10 + (g_alm_cntx.MinBuf[ENCODING_LENGTH] - '0');
        g_alm_cntx.AlmList[i].Snooze = 0;

    #ifdef __MMI_ALM_CUST_VOLUME__
        g_alm_cntx.AlmList[i].Volume = (U8) g_alm_cntx.CurrHiliteVol;
    #endif 

        /* Alarm Audio Setting */
    #ifdef __MMI_ALM_AUDIO_OPTIONS__
        if (g_alm_cntx.CurrHiliteAudioOptionValue != 0)
        {
            g_alm_cntx.AlmList[i].AudioOption = (U8) g_alm_cntx.CurrHiliteAudioOption;
            g_alm_cntx.AlmList[i].AudioOptionValue = g_alm_cntx.CurrHiliteAudioOptionValue;
        }
        else    /* Should not enter here because it already check before save */
        {
            g_alm_cntx.AlmList[i].AudioOption = ALM_AUDIO_OPTIONS_TONE;

        #ifdef __MMI_ALM_CUSTOMIZE_TONE__
            g_alm_cntx.AlmList[i].AudioOptionValue = (U16) (gstartMidiId + 1);
        #else 
            g_alm_cntx.AlmList[i].AudioOptionValue = gcurrentprofile.toneSetup.alarmTone;
        #endif 
        }
    #endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

    #ifdef __MMI_ALM_SNOOZE_SETTING__
        g_alm_cntx.AlmList[i].SnoozeInterval = (U8) g_alm_cntx.CurrHilightSnoozeInterval;
    #endif 
    #ifdef __MMI_ALM_ALERT_TYPE__
        g_alm_cntx.AlmList[i].AlertType = (U8) g_alm_cntx.CurrHilightAlertType;
    #endif 
        AlmWriteToNvram();

        if (g_alm_cntx.CurrHiliteState == SET_STATE)
        {
            AlmSetAlarm((U8) (i + ALM_ALM_START));
            AlmActivateIndicator();
        }
        else
        {
            AlmCancelAlarm((U8) (i + ALM_ALM_START));
            if (!(AlmIsAnyAlarmActivated()))
            {
                AlmDeactivateIndicator();
            }
        }
    }

#ifdef __MMI_ALM_AUDIO_OPTIONS__
    if (((g_alm_cntx.AlmList[g_alm_cntx.CurrHiliteAlarm].AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL) ||
        (g_alm_cntx.AlmList[g_alm_cntx.CurrHiliteAlarm].AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)) &&
        g_alm_cntx.AlmList[g_alm_cntx.CurrHiliteAlarm].State == TRUE)
    {
        DisplayConfirm(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            get_string(STR_ID_ALM_FMRDO_HEADFONE_REMINDER),
            IMG_GLOBAL_INFO,
            WARNING_TONE);
        SetLeftSoftkeyFunction(mmi_alm_display_popup, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_ALM_LIST);
    }
}

#ifdef __MMI_ALM_AUDIO_OPTIONS__


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_display_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_ALM_LIST);
}
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 


/*****************************************************************************
 * FUNCTION
 *  AlmCancelAlarmFromAT
 * DESCRIPTION
 *  Handler to cancel alarm from AT command.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AlmCancelAlarmFromAT(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_cntx.AlmList[index].State == 1)   /* alarm is currently on */
    {
        AlmCancelAlarm((U8) (index + ALM_ALM_START));
    }

    if (g_alm_frm_cntx.CurrAlmIndex == (U8) (index + ALM_ALM_START))
    {
        AlmStopHandler();
    }

    memset(&g_alm_cntx.AlmList[index], 0, sizeof(alm_nvram_struct));
    AlmWriteToNvram();

    if (!(AlmIsAnyAlarmActivated()))
    {
        AlmDeactivateIndicator();
    }

}


/*****************************************************************************
 * FUNCTION
 *  AlmSetAlarmFromAT
 * DESCRIPTION
 *  Handler to process alarm request from AT command
 * PARAMETERS
 *  index           [IN]        
 *  mytime          [IN]        
 *  weekdays        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSetAlarmFromAT(U8 index, MYTIME mytime, U8 weekdays)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_cntx.AlmList[index].Hour = mytime.nHour;
    g_alm_cntx.AlmList[index].Min = mytime.nMin;
    g_alm_cntx.AlmList[index].Snooze = 0;
    g_alm_cntx.AlmList[index].State = 1;

    if (weekdays == 0)
    {
        g_alm_cntx.AlmList[index].Freq = mmi_alm_get_freq_order(ALARM_FREQ_NUM, g_alm_freq_set, ALM_FREQ_ONCE);
    }
    else if (weekdays == 0x7F)
    {
        g_alm_cntx.AlmList[index].Freq = mmi_alm_get_freq_order(ALARM_FREQ_NUM, g_alm_freq_set, ALM_FREQ_EVERYDAY);
    }
    else
    {
        g_alm_cntx.AlmList[index].Freq = mmi_alm_get_freq_order(ALARM_FREQ_NUM, g_alm_freq_set, ALM_FREQ_DAYS);
        g_alm_cntx.AlmList[index].Days = weekdays;
    }

    #ifdef __MMI_ALM_AUDIO_OPTIONS__
        g_alm_cntx.AlmList[index].AudioOption = ALM_AUDIO_OPTIONS_TONE;
        g_alm_cntx.AlmList[index].AudioOptionValue = gcurrentprofile.toneSetup.alarmTone;
    #endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

    AlmWriteToNvram();

    AlmSetAlarm((U8) (index + ALM_ALM_START));

    AlmActivateIndicator();

}


/*****************************************************************************
 * FUNCTION
 *  AlmQueryAlarmFromAT
 * DESCRIPTION
 *  Handler to process query alarm request from AT command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmQueryAlarmFromAT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_alarm_query_res_req_struct *rsp;
    MYQUEUE Message;
    S32 i, j;
    MYTIME almTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ;
    rsp = (mmi_at_alarm_query_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_alarm_query_res_req_struct));

    rsp->totalAlarm = NUM_OF_ALM;
    rsp->alarmList = NULL;
    rsp->activeAlarm = 0;

    for (i = 0; i < NUM_OF_ALM; i++)
        if (g_alm_cntx.AlmList[i].State == SET_STATE)
        {
            rsp->activeAlarm++;
        }

    if (rsp->activeAlarm)
    {
        rsp->alarmList = (mmi_at_alarm_info_struct*)
            OslConstructDataPtr(sizeof(mmi_at_alarm_info_struct) * rsp->activeAlarm);

        for (i = 0, j = 0; i < NUM_OF_ALM; i++)
        {
            if (g_alm_cntx.AlmList[i].State == SET_STATE)
            {
                rsp->alarmList[j].alarm_index = i;

                almTime = AlmGetAlarmTime((kal_uint8) (i + ALM_ALM_START));

                rsp->alarmList[j].date_time.rtc_year = almTime.nYear - YEARFORMATE;
                rsp->alarmList[j].date_time.rtc_wday = almTime.DayIndex;
                rsp->alarmList[j].date_time.rtc_mon = almTime.nMonth;
                rsp->alarmList[j].date_time.rtc_day = almTime.nDay;
                rsp->alarmList[j].date_time.rtc_hour = almTime.nHour;
                rsp->alarmList[j].date_time.rtc_min = almTime.nMin;
                rsp->alarmList[j].date_time.rtc_sec = almTime.nSec;

                if (g_alm_freq_set[g_alm_cntx.AlmList[i].Freq] == ALM_FREQ_ONCE)
                {
                    rsp->alarmList[j].recurr = 0;
                }
                else if (g_alm_freq_set[g_alm_cntx.AlmList[i].Freq] == ALM_FREQ_EVERYDAY)
                {
                    rsp->alarmList[j].recurr = ALM_ALL_DAYS;
                }
                else
                {
                    rsp->alarmList[j].recurr = g_alm_cntx.AlmList[i].Days;
                }

                j++;
            }
        }
    }

    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

#endif /* _MMI_ALARM_C */ // #ifndef _MMI_ALARM_C

