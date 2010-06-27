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
 *    SyncMLRegularity.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "AlarmFrameWorkProt.h"
#include "DateTimeGprot.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "Wapadp.h"
#include "SimDetectionGProt.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

/*
 * Local Variable
 */


/*
 * Global Variable
 */
extern syncml_context_struct g_syncml_context;

/* MENU_ID_SYNCML_MAIN
 * Global Function
 */

extern MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id);

#ifdef __MMI_DUAL_SIM_MASTER__
extern MTPNP_BOOL MTPNP_PFAL_Phb_IsReady(void);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_expiry_time_cb
 * DESCRIPTION
 *  Sync alarm callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_expiry_time_cb(U8 index, MYTIME *alarmTime, U8 *repeat, U8 *weekday, MYTIME *preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);

    switch (g_syncml_context.regular_sync)
    {
        case SYNCML_REGULAR_SYNC_EVERY_DAY:
            alarmTime->nYear = currTime.nYear;
            alarmTime->nMonth = currTime.nMonth;
            alarmTime->nDay = currTime.nDay;
            alarmTime->nHour = 12;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_EVERYDAY;
            *weekday = 0;
            break;

        case SYNCML_REGULAR_SYNC_EVERY_WEEK:
            alarmTime->nYear = currTime.nYear;
            alarmTime->nMonth = currTime.nMonth;
            alarmTime->nDay = currTime.nDay;
            alarmTime->DayIndex = DOW(alarmTime->nYear, alarmTime->nMonth, alarmTime->nDay);
            alarmTime->nHour = 12;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_DAYS;
            *weekday = 0x01; /* Sunday */
            break;

        case SYNCML_REGULAR_SYNC_EVERY_MONTH:
            alarmTime->nYear = currTime.nYear;
            alarmTime->nMonth = currTime.nMonth;
            alarmTime->nDay = 1;
            alarmTime->nHour = 12;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_MONTHLY;
            *weekday = 0;
            break;

        default:
            alarmTime->nYear = 0;
            alarmTime->nMonth = 0;
            alarmTime->nDay = 0;
            alarmTime->nHour = 0;
            alarmTime->nMin = 0;
            alarmTime->nSec = 0;
            *repeat = ALM_FREQ_OFF;
            *weekday = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_expiry_hdlr_cb
 * DESCRIPTION
 *  Sync alarm callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_syncml_set_expiry_hdlr_cb(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML] Sync alarm expires...");
    *period = ALM_WITHOUD_EXPIRY_PERIOD;

    if (power_on)
    {
        if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
        {
            g_syncml_context.power_on_sync = 1;

            if (mmi_idle_is_on_idle_screen() || mmi_idle_is_screensaver_running())
            {
                EntryIdleScreen();
            }
        }
    }
    else
    {
        mmi_syncml_read_settings_from_nvram();
        g_syncml_context.power_on_sync = 1;
        mmi_syncml_update_settings_to_nvram();
    }

    return ALM_HAS_NO_IND;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_reinit_queue_cb
 * DESCRIPTION
 *  Sync alarm callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_reinit_queue_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.regular_sync >= SYNCML_REGULAR_SYNC_EVERY_DAY)
    {
        AlmInsertIntoQueue(ALM_SYNCML, FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_alarm
 * DESCRIPTION
 *  Initialize the alarm callback functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))   
    mmi_alm_set_start_index(ALM_TYPE_SYNCML, ALM_SYNCML);
    AlmSetExpiryTimeCB(ALM_TYPE_SYNCML, mmi_syncml_set_expiry_time_cb);
    AlmSetExpiryHandlerCB(ALM_TYPE_SYNCML, mmi_syncml_set_expiry_hdlr_cb);
    AlmSetInitHandlerCB(ALM_TYPE_SYNCML, NULL, mmi_syncml_reinit_queue_cb);
    AlmSetStopAlarmCB(ALM_TYPE_SYNCML, NULL);
#endif /*(defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))*/    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_power_on_sync_timer_hdlr
 * DESCRIPTION
 *  Timer to wait WAP and phonebook ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_power_on_sync_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.regular_sync == SYNCML_REGULAR_SYNC_POWER_ON &&
        (!wap_is_ready() || !mmi_syncml_is_phb_ready()))
    {
        StartTimer(SYNCML_POWER_ON_SYNC_TIMER, 2000, mmi_syncml_power_on_sync_timer_hdlr);
        return;
    }

    if (mmi_idle_is_on_idle_screen() || mmi_idle_is_screensaver_running())
    {
        EntryIdleScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_sync_alarm_expired
 * DESCRIPTION
 *  Sync alarm idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_syncml_is_sync_alarm_expired(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_sim_valid() == MMI_FALSE)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_netset_get_active_preferred_mode() == 0)
    #endif /* __MMI_WLAN_FEATURES__ */
            return 0;
    }

    /* if no menu MENU_ID_SYNCML_MAIN, regular sync will quit */
    if (mmi_frm_test_menu_item_hide(MENU_ID_SYNCML_MAIN))
    {
        g_syncml_context.power_on_sync = 0;
        mmi_syncml_update_settings_to_nvram();
        return 0;
    }
    
#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_syncml_context.regular_sync == SYNCML_REGULAR_SYNC_POWER_ON &&
        (!wap_is_ready() || !MTPNP_PFAL_Phb_IsReady() || g_phb_cntx.processing))
#else
    if (g_syncml_context.regular_sync == SYNCML_REGULAR_SYNC_POWER_ON &&
        (!wap_is_ready() || !g_phb_cntx.phb_ready || g_phb_cntx.processing))
#endif
    {
        StartTimer(SYNCML_POWER_ON_SYNC_TIMER, 2000, mmi_syncml_power_on_sync_timer_hdlr);
        return 0;
    }

    return g_syncml_context.power_on_sync;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_alarm_accept
 * DESCRIPTION
 *  Sync alarm acceptance
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_sync_alarm_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.power_on_sync = 0;
    mmi_syncml_update_settings_to_nvram();

    mmi_syncml_entry_sync_pre_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_alarm_cancel
 * DESCRIPTION
 *  Sync alarm calcellation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_sync_alarm_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.power_on_sync = 0;
    mmi_syncml_update_settings_to_nvram();

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_alarm_hdlr
 * DESCRIPTION
 *  Sync alarm idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_sync_alarm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sync_alarm_string = STR_ID_SYNC_ALARM_EXPIRED_QUERY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_ALARM_QUERY, NULL, NULL, NULL);

    switch (g_syncml_context.regular_sync)
    {
        case SYNCML_REGULAR_SYNC_DATA_CHANGED:
            sync_alarm_string = STR_ID_SYNC_DATA_CHANGED_QUERY;
            break;

        case SYNCML_REGULAR_SYNC_POWER_ON:
            sync_alarm_string = STR_ID_SYNC_POWER_ON_QUERY;
            break;

        default:
            break;
    }

    if (g_keylock_context.gKeyPadLockFlag)
    {
        ShowCategory2Screen(
            STR_ID_SYNC_MENU,
            IMG_ID_SYNC_MENU,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            sync_alarm_string,
            NULL);
    }
    else
    {
        ShowCategory2Screen(
            STR_ID_SYNC_MENU,
            IMG_ID_SYNC_MENU,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            sync_alarm_string,
            NULL);

        SetRightSoftkeyFunction(mmi_syncml_sync_alarm_cancel, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_syncml_sync_alarm_accept, KEY_EVENT_UP);
        SetKeyHandler(mmi_syncml_sync_alarm_cancel, KEY_END, KEY_EVENT_DOWN);
    }
}


#endif /* __SYNCML_SUPPORT__ */

