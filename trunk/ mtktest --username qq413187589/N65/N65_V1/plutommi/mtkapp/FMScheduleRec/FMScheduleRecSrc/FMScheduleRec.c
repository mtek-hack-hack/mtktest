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
 *   FMScheduleRec.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  .............
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
#include "MMI_include.h"
#ifndef _MMI_FMSR_C
#define _MMI_FMSR_C


#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

// #undef __MMI_FM_RADIO__

/*  Include: MMI header file */
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "nvram_user_defs.h"
/* ... Add More MMI header */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "FileManagerDef.h"
#include "Ucs2prot.h"
#include "DateTimeGProt.h"
#include "gpioInc.h"
#include "AlarmFrameworkProt.h"
#include "AlarmProt.h"
#include "FilemanagerGProt.h"
#ifdef __MMI_TOUCH_SCREEN__
#endif 
#ifdef __MMI_SUBLCD__
#endif
#include "FMScheduleRecDef.h"
#include "FMScheduleRecType.h"
#include "FMScheduleRecProt.h"

#include "USBDeviceGprot.h"
#include "USBDeviceDefs.h"
#include "SimDetectionGexdcl.h"

#ifdef __MMI_BT_FM_VIA_SCO__
#include "ProfilesDefs.h"
#include "ProfileGProts.h"
#endif /* __MMI_BT_FM_VIA_SCO__ */

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */

fmsr_context_struct g_fmsr_cntx;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */
extern void QuitSystemOperation(void);
extern void wgui_set_wallpaper_on_bottom(MMI_BOOL state);

#define MMI_FMSR_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_init_app
 * DESCRIPTION
 *  Init function for schedule FM record App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmsr_init_setting();
    mmi_fmsr_init_screen();

    g_fmsr_cntx.rec.state = FMSR_STATE_IDLE;
    g_fmsr_cntx.rec.volume = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_deinit_app
 * DESCRIPTION
 *  Deinit function for schedule FM record App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_deinit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#define MMI_FMSR_RECORDING


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_alarm_expire_ind
 * DESCRIPTION
 *  The indication function for schedule FM record timeout
 * PARAMETERS
 *  index               [IN]        Indicate which schedule record timeout
 *  power_on_record     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_alarm_expire_ind(U16 index, BOOL power_on_record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    S8 buffer[NVRAM_EF_FMSR_SETTING_SIZE];
    fmsr_nvram_struct *data_ptr;
    MYTIME curr_time;
    U32 start_time, end_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Turn on backlight for a short time and disable alarm power off to show message. */
    TurnOnBacklight(1);
    /* Disable power off in RTC power on alarm, need to enable after record finish */
    mmi_alm_disable_pwroff();
    
    g_fmsr_cntx.rec.power_on_record = power_on_record;

    /* Get data from NVRAM */
    ReadRecord(NVRAM_EF_FMSR_SETTING_LID, (U16) (index + 1), buffer, NVRAM_EF_FMSR_SETTING_SIZE, &pError);
    data_ptr = (fmsr_nvram_struct*) buffer;

    /* Change schedule record status to off if it only record once */
    if (data_ptr->repeat == FMSR_REPEAT_ONCE)
    {
        data_ptr->state = 0;
        WriteRecord(NVRAM_EF_FMSR_SETTING_LID, (U16) (index + 1), buffer, NVRAM_EF_FMSR_SETTING_SIZE, &pError);
        mmi_fmsr_main_list_update_state(index, MMI_FALSE);
    }

    /* Shold not happened! If there are other schedule event still recording, abort this request */
    if (g_fmsr_cntx.rec.state != FMSR_STATE_IDLE)
    {
        MMI_ASSERT(0);  // TODO: Use trace instead.
        return;
    }

    /* Assign variable for this schedule record */
    g_fmsr_cntx.rec.index = (U8) index;
    g_fmsr_cntx.rec.error_msg = FMSR_MSG_NONE;

    /* Assign the next 3 value as current time */
    //g_fmsr_cntx.rec.year = data_ptr->year;
    //g_fmsr_cntx.rec.mon = data_ptr->mon;
    //g_fmsr_cntx.rec.day = data_ptr->day;
    g_fmsr_cntx.rec.hour1 = data_ptr->hour1;
    g_fmsr_cntx.rec.min1 = data_ptr->min1;
    g_fmsr_cntx.rec.hour2 = data_ptr->hour2;
    g_fmsr_cntx.rec.min2 = data_ptr->min2;

    g_fmsr_cntx.rec.freqency = data_ptr->freq;
    g_fmsr_cntx.rec.format = (data_ptr->format >= FMSR_REC_FORMAT_NUM) ? FMSR_FORMAT_AMR : data_ptr->format;
    g_fmsr_cntx.rec.quality= (data_ptr->quality >= NO_OF_FMSR_QUALITY) ? FMSR_QUALITY_LOW: data_ptr->quality;
    g_fmsr_cntx.rec.drive = data_ptr->storage;
    g_fmsr_cntx.rec.type = (data_ptr->type >= FMSR_REC_TYPE_NUM) ? FMSR_TYPE_NEW : data_ptr->type;

    /* Send out record request */
    g_fmsr_cntx.rec.is_first_record = TRUE;
    g_fmsr_cntx.rec.is_show_msg = TRUE;
    g_fmsr_cntx.rec.error_str_id = 0;

    /* Check if later than current time */
    DTGetRTCTime(&curr_time);
    start_time = curr_time.nHour * 60 + curr_time.nMin;
    end_time = g_fmsr_cntx.rec.hour2 * 60 + g_fmsr_cntx.rec.min2;

    if (data_ptr->repeat == FMSR_REPEAT_ONCE)
    {
        if ((data_ptr->year < curr_time.nYear) ||
            (data_ptr->year == curr_time.nYear && data_ptr->mon < curr_time.nMonth) ||
            (data_ptr->year == curr_time.nYear && data_ptr->mon == curr_time.nMonth &&
             data_ptr->day < curr_time.nDay) || (data_ptr->year == curr_time.nYear &&
                                                       data_ptr->mon == curr_time.nMonth &&
                                                       data_ptr->day == curr_time.nDay && start_time >= end_time))
        {
            mmi_fmsr_record_error_hdlr(FMSR_ERROR_TIME_EXPIRE);
            return;
        }
    }
    else if (start_time >= end_time)    /* data_ptr->repeat != FMSR_REPEAT_ONCE */
    {
        mmi_fmsr_record_error_hdlr(FMSR_ERROR_TIME_EXPIRE);
        return;
    }

    /* Assign these 3 values as current record time for later check */
    g_fmsr_cntx.rec.year = curr_time.nYear;
    g_fmsr_cntx.rec.mon = curr_time.nMonth;
    g_fmsr_cntx.rec.day = curr_time.nDay;

    /* Check Frequency */
    if ((g_fmsr_cntx.rec.freqency > FMSR_MAX_FREQUENCY) || (g_fmsr_cntx.rec.freqency < FMSR_MIN_FREQUENCY))
    {
        mmi_fmsr_record_error_hdlr(FMSR_ERROR_INVALID_FREQ);
        return;
    }

    /* Check current system mode to see if we can record now */
    if (!mmi_fmsr_alarm_expire_check_mode())
    {
        mmi_fmsr_record_error_hdlr(FMSR_ERROR_USB_MODE);
        return;
    }

    /* Check Storage and Get Record File path */
    if (!mmi_fmsr_alarm_expire_check_file((void*)data_ptr))
    {
        return;
    }

    mmi_fmsr_pre_entry_recording();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_alarm_expire_check_file
 * DESCRIPTION
 *  Check the record file before record
 * PARAMETERS
 *  ptr     [IN]        NVRAM data pointer
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmsr_alarm_expire_check_file(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmsr_nvram_struct *data_ptr = (fmsr_nvram_struct*) ptr;
    S32 result;
    BOOL valid_folder = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check storage folder first */
    mmi_fmsr_util_get_storage_path((UI_string_type) g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.drive);
    result = mmi_fmsr_util_check_storage_folder((UI_string_type) g_fmsr_cntx.rec.full_path);

    /* Can't find or create storage path */
    if (result != FS_NO_ERROR)
    {
        g_fmsr_cntx.rec.drive = (U8)MMI_PUBLIC_DRV;
        mmi_fmsr_util_get_storage_path((UI_string_type) g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.drive);
        result = mmi_fmsr_util_check_storage_folder((UI_string_type) g_fmsr_cntx.rec.full_path);

        if (result != FS_NO_ERROR)
        {
            valid_folder = FALSE;
        }
        else
        {
            g_fmsr_cntx.rec.error_msg |= FMSR_MSG_DEFAULT_FILE;
        }
    }

    if (!valid_folder)
    {
        mmi_fmsr_record_error_hdlr(FMSR_ERROR_NO_FOLDER);
        return FALSE;
    }

    /* Always use new file for wave foramt */
    if (g_fmsr_cntx.rec.type == FMSR_TYPE_NEW || g_fmsr_cntx.rec.format == FMSR_FORMAT_WAV)
    {
        mmi_fmsr_util_get_new_file((UI_string_type) g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.format);
    }
    else    /* File Format is AMR and Type is Append */
    {
        if ((data_ptr->filename[0] != 0xffff) && (mmi_ucs2strlen((S8*) data_ptr->filename) > 0))
        {
            mmi_ucs2ncat((S8*) g_fmsr_cntx.rec.full_path, (S8*) data_ptr->filename, MAX_FMSR_FILE_NAME_LEN);
            mmi_fmsr_util_append_file_ext((UI_string_type) g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.format);
        }
        else    /* Use new file instead */
        {
            g_fmsr_cntx.rec.error_msg |= FMSR_MSG_DEFAULT_FILE;
            mmi_fmsr_util_get_new_file((UI_string_type) g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.format);
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_alarm_expire_check_mode
 * DESCRIPTION
 *  Check the current system mode to see if can access file system.
 * PARAMETERS
 *  void
 *  ptr(?)      [IN]        NVRAM data pointer
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmsr_alarm_expire_check_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Can't record in the power off USB mode */
#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode() && g_charbat_context.isChargerConnected)
    {
        return FALSE;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    /* Can't record in the power on USB mode */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        return FALSE;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_rec_check_remaining_timer
 * DESCRIPTION
 *  Check the remaining record time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmsr_rec_check_remaining_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time1, time2;
    MYTIME curr_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get current time */
    DTGetRTCTime(&curr_time);

    /* Check if it is still the same year, month and day, avoid to record overnight */
    if(curr_time.nYear > g_fmsr_cntx.rec.year)
    {
        return MMI_FALSE;
    }

    if(curr_time.nMonth > g_fmsr_cntx.rec.mon)
    {
        return MMI_FALSE;
    }

    if(curr_time.nDay > g_fmsr_cntx.rec.day)
    {
        return MMI_FALSE;
    }


    time1 = (curr_time.nHour * 60 + curr_time.nMin) * 60 + curr_time.nSec;
    time2 = (g_fmsr_cntx.rec.hour2 * 60 + g_fmsr_cntx.rec.min2) * 60;

    if (time2 > time1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_rec_start_remaining_timer
 * DESCRIPTION
 *  Check the remaining record time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmsr_rec_start_remaining_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration, time1, time2;
    MYTIME curr_time;
    MMI_BOOL is_same_day = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get current time */
    DTGetRTCTime(&curr_time);

    /* Check if it is still the same year, month and day, avoid to record overnight */
    if(curr_time.nYear > g_fmsr_cntx.rec.year)
    {
        is_same_day = MMI_FALSE;
    }

    if(curr_time.nMonth > g_fmsr_cntx.rec.mon)
    {
        is_same_day = MMI_FALSE;
    }

    if(curr_time.nDay > g_fmsr_cntx.rec.day)
    {
        is_same_day = MMI_FALSE;
    }

    time1 = (curr_time.nHour * 60 + curr_time.nMin) * 60 + curr_time.nSec;
    time2 = (g_fmsr_cntx.rec.hour2 * 60 + g_fmsr_cntx.rec.min2) * 60;

    if (is_same_day && (time2 > time1))
    {
        /* Start timer to count when to stop, Count record duration (in milliseconds) */
        duration = (time2 - time1) * 1000;
        StartTimer(FMSR_CHCEK_STOP_TIMER, duration, mmi_fmsr_stop_record_ind);
        return TRUE;
    }
    else
    {
        /* Record timeout but it stops recording and remain on the main screen */
        if (g_fmsr_cntx.rec.state == FMSR_STATE_IDLE)
        {
            mmi_fmsr_record_error_hdlr(MDI_AUDIO_TERMINATED);
        }
        else
        {
            mmi_fmsr_send_stop_req();
        }

        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_send_record_req
 * DESCRIPTION
 *  Send out the record request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmsr_send_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Stop Previous Record Countdown Timer */
    StopTimer(FMSR_CHCEK_STOP_TIMER);

    /*
    * Power on FM radio then begin to record.
    * If record request fail, it will stop FM radio in the request function 
    */
    mmi_fmsr_power_on();

    if (mmi_fmsr_start_record(g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.format, g_fmsr_cntx.rec.quality))
    {
        if (mmi_fmsr_rec_start_remaining_timer())
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_send_re_record_req
 * DESCRIPTION
 *  Send out the re-record request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmsr_send_re_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Stop Previous Record Countdown Timer */
    StopTimer(FMSR_CHCEK_STOP_TIMER);

    /* Get a new file to record again if it is a wave file. (For AMR, it can append so we don't use new file) */
    if (g_fmsr_cntx.rec.format == FMSR_FORMAT_WAV)
    {
        mmi_fmsr_util_get_storage_path((UI_string_type) g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.drive);
        mmi_fmsr_util_get_new_file((UI_string_type) g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.format);
    }

    /*
    * Power on FM radio then begin to record.
    * If record request fail, it will stop FM radio in the request function 
    */
    mmi_fmsr_power_on();

    if (mmi_fmsr_start_record(g_fmsr_cntx.rec.full_path, g_fmsr_cntx.rec.format, g_fmsr_cntx.rec.quality))
    {
        if (mmi_fmsr_rec_start_remaining_timer())
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_send_stop_req
 * DESCRIPTION
 *  Send out the stop record request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_send_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMSR_CHCEK_STOP_TIMER);

    if (g_fmsr_cntx.rec.state != FMSR_STATE_IDLE)
    {
        mmi_fmsr_stop_record();
        mmi_fmsr_power_off();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_send_pause_req
 * DESCRIPTION
 *  Send out the pause record request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_send_pause_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not stop countdown timer here, wait timeout to stop during pause */

    /* Pause record */
    mmi_fmsr_pause_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_send_resume_req
 * DESCRIPTION
 *  Send out the resume record request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_send_resume_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Stop countdown timer and restart again */
    StopTimer(FMSR_CHCEK_STOP_TIMER);

    if (mmi_fmsr_rec_start_remaining_timer())
    {
        mmi_fmsr_resume_record();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_stop_record_ind
 * DESCRIPTION
 *  Record endtime timeout callback for timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_stop_record_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmsr_rec_start_remaining_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_get_duration_ticks
 * DESCRIPTION
 *  Get duration counter ticks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_fmsr_get_duration_ticks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_fmsr_cntx.rec.total_rec_duration;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_init_duration
 * DESCRIPTION
 *  Init the duration counter to zero
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_init_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmsr_cntx.rec.total_rec_duration = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_start_duration
 * DESCRIPTION
 *  Start to count the duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_start_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time((kal_uint32*) & g_fmsr_cntx.rec.rec_time);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_update_duration
 * DESCRIPTION
 *  Update duration time when restore from pause
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);
    g_fmsr_cntx.rec.total_rec_duration += current_time - g_fmsr_cntx.rec.rec_time;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_pre_entry_recording
 * DESCRIPTION
 *  Check if it is the first time enter the recording screen.
 *  If not, try to resume the recording
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_pre_entry_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL record_success = FALSE;
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmsr_cntx.rec.is_show_msg = TRUE;

    /* Draw screen as background only when call by small screen */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens())
    {
        EntryNewScreen(SCR_ID_FMSR_RECORDING, mmi_fmsr_exit_recording, mmi_fmsr_pre_entry_recording, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_FMSR_RECORDING);
        mmi_fmsr_show_main(
            STR_ID_FMSR_APP,
            IMG_ID_FMSR_APP,
            STR_ID_FMSR_PAUSE,
            IMG_GLOBAL_OK,
            STR_ID_FMSR_STOP,
            IMG_GLOBAL_NO,
            guiBuffer);
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

#ifdef __MMI_BT_FM_VIA_SCO__
    /* Can not record while FM via SCO connected*/
    if(mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
    {
        mmi_fmsr_record_error_hdlr(MDI_AUDIO_HFP_SCO_CONNECTED);
        return;
    }
#endif /* __MMI_BT_FM_VIA_SCO__ */

    /* Suspend background play while in schedule record screen */
    mdi_audio_suspend_background_play();

    /* First time record */
    if (g_fmsr_cntx.rec.is_first_record)
    {
        DeleteScreenIfPresent(SCR_ID_FMSR_RECORDING);
        mmi_fmsr_init_duration();
        mmi_fmsr_start_duration();
        mmi_fmsr_entry_recording();

        if (mmi_fmsr_send_record_req())
        {
            /* Delete previous unfinish screen, if any. Then enter recording screen. */
            g_fmsr_cntx.rec.is_first_record = FALSE;
            g_fmsr_cntx.rec.is_screen_paused = FALSE;

            record_success = TRUE;
        }
    }
    /* Come back from history */
    else
    {
        g_fmsr_cntx.rec.error_msg |= FMSR_MSG_REC_INTERRUPT;

        /* Don't start to record if the state is pause before interrupt. */
        if (g_fmsr_cntx.rec.is_screen_paused)
        {
            if (mmi_fmsr_rec_start_remaining_timer())
            {
                mmi_fmsr_entry_recording();
                mmi_fmsr_power_on();

                record_success = TRUE;
            }
        }
        else
        {
            if (mmi_fmsr_rec_check_remaining_timer())
            {
                mmi_fmsr_start_duration();
                mmi_fmsr_entry_recording();

                if (mmi_fmsr_send_re_record_req())
                {
                    record_success = TRUE;
                }
            }
            else
            {
                mmi_fmsr_record_error_hdlr(MDI_AUDIO_SUCCESS);
            }
        }
    }

    /* Resume background play in not begin to record */
    if (!record_success)
    {
        mdi_audio_resume_background_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_entry_recording
 * DESCRIPTION
 *  Enter the main record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_entry_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Turn on backlight and disable schedule power off feature while recording */
    TurnOnBacklight(1);
    AlmDisableSPOF();

    EntryNewScreen(SCR_ID_FMSR_RECORDING, mmi_fmsr_exit_recording, mmi_fmsr_pre_entry_recording, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FMSR_RECORDING);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);

    mmi_fmsr_show_main(
        STR_ID_FMSR_APP,
        IMG_ID_FMSR_APP,
        STR_ID_FMSR_PAUSE,
        IMG_GLOBAL_OK,
        STR_ID_FMSR_STOP,
        IMG_GLOBAL_NO,
        guiBuffer);

    /* If this screen is deleted, call back function. */
    SetDelScrnIDCallbackHandler(SCR_ID_FMSR_RECORDING, (HistoryDelCBPtr) mmi_fmsr_del_scr_callback);

    /* Block the unnecessary interrupt */
   /*-- bettery --*/
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_BATTERY, mmi_fmsr_battery_status_interrupt_hdlr, mmi_fmsr_post_interrupt_hdlr);

    /* Clear all key and end key handler */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        ClearKeyHandler(KEY_END, i);
    }

    /* Register Softkey Up */
    SetKeyHandler(mmi_fmsr_rec_release_LSK, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmsr_rec_release_RSK, KEY_RSK, KEY_EVENT_UP);

    /* Register Softkey Down for Redraw */
    SetKeyHandler(mmi_fmsr_redraw_LSK_down, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmsr_redraw_RSK_down, KEY_RSK, KEY_EVENT_DOWN);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_fmsr_increase_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmsr_decrease_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_fmsr_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_fmsr_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_fmsr_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_SUBLCD__
    ForceSubLCDScreen(mmi_fmsr_entry_sublcd_screen);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_exit_recording
 * DESCRIPTION
 *  Exit the recording screen, stop record here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_exit_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Stop recording. If next screen is message screen, 
     * it will draw draw sub LCD directly. Or it shall go back history */
    if (GetActiveScreenId() != SCR_ID_FMSR_SHOW_MESSAGE)
    {
        g_fmsr_cntx.rec.is_show_msg = FALSE;
#ifdef __MMI_SUBLCD__
        if (GetSubLCDScreenCountInHistory() > 0)
        {
            GoBackSubLCDHistory();
        }
#endif
    }

    mmi_fmsr_send_stop_req();
    wgui_set_wallpaper_on_bottom(MMI_FALSE);

    /* Enable shcedule power off when finish recording */
    AlmEnableSPOF();

    /* Resume background play when exit screen */
    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_del_scr_callback
 * DESCRIPTION
 *  Delete screen callback, always return TRUE to avoid the recording screen to be deleted
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 * TRUE
 *****************************************************************************/
U8 mmi_fmsr_del_scr_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If the screen is exit by USB mode, then let it go back to idle screen. */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        return MMI_FALSE;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /* Don't delete this screen */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_rec_release_RSK
 * DESCRIPTION
 *  Key up callback for record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_rec_release_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmsr_cntx.rec.error_msg |= FMSR_MSG_USER_STOP;

    if (g_fmsr_cntx.rec.state == FMSR_STATE_IDLE)
    {
        mmi_fmsr_record_error_hdlr(MDI_AUDIO_TERMINATED);
    }
    else
    {
        mmi_fmsr_send_stop_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_rec_release_LSK
 * DESCRIPTION
 *  Key up callback for record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_rec_release_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.state == FMSR_STATE_RECORD)
    {
        g_fmsr_cntx.rec.error_msg |= FMSR_MSG_REC_PAUSE;
        mmi_fmsr_send_pause_req();

        g_fmsr_cntx.rec.is_screen_paused = TRUE;
    }
    else if (g_fmsr_cntx.rec.state == FMSR_STATE_PAUSE)
    {
        mmi_fmsr_send_resume_req();

        g_fmsr_cntx.rec.is_screen_paused = FALSE;
    }
    else if (g_fmsr_cntx.rec.state == FMSR_STATE_IDLE || g_fmsr_cntx.rec.state == FMSR_STATE_READY)
    {
        if (mmi_fmsr_send_re_record_req())
        {
            mmi_fmsr_start_duration();
            mmi_fmsr_restore_recording_screen();
            mmi_fmsr_redraw_LSK_up();/*add to fix redraw LSK issue*/
            g_fmsr_cntx.rec.is_screen_paused = FALSE;
        }
    }

//    mmi_fmsr_redraw_LSK_up();
}

#define MMI_FMSR_ERROR_HANDLE


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_show_record_result
 * DESCRIPTION
 *  Show record result screen, delete previous screen in advance
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_show_record_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only display the last error message. The previous message will be deleted. */
    if (IsScreenPresent(SCR_ID_FMSR_SHOW_MESSAGE))
    {
        /* Enalbe power off in RTC power on alarm for the previous schedule FM record */
        mmi_alm_enable_pwroff();
        DeleteScreenIfPresent(SCR_ID_FMSR_SHOW_MESSAGE);
    }

    mmi_fmsr_entry_show_msg();

    /* Record done, delete the recording screen */
    DeleteScreenIfPresent(SCR_ID_FMSR_RECORDING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_entry_show_msg
 * DESCRIPTION
 *  enter show message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_entry_show_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *str;

    /* U8 i; */
    U32 str_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    
    str = (S8*) OslMalloc(FMSR_MAX_MSG_BUFFER);
    mmi_fmsr_show_msg_prepare_data(str);
    str_size = mmi_ucs2strlen(str);

    EntryNewScreen(SCR_ID_FMSR_SHOW_MESSAGE, mmi_fmsr_exit_show_msg, mmi_fmsr_entry_show_msg, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FMSR_SHOW_MESSAGE);

    ShowCategory74Screen(
        STR_ID_FMSR_APP,
        GetRootTitleIcon(MENU_ID_FMSR_MAIN),
        STR_GLOBAL_OK,  /* LSK STR */
        0,              /* LSK IMG */
        0,              /* RSK STR */
        0,              /* RSK IMG */
        (U8*) str,      /* message id */
        str_size,       /* icon id */
        guiBuffer);

    /* Register Softkey Down for Redraw */
    SetLeftSoftkeyFunction(mmi_fmsr_show_msg_confirm, KEY_EVENT_UP);

    /* register END key for power on alarm */
    if (g_alm_frm_cntx.IsPwronAlarm)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(AlmSendPowerOn, KEY_END, KEY_LONG_PRESS);
    }

    /* If this screen is deleted, call back function. */
    SetDelScrnIDCallbackHandler(SCR_ID_FMSR_RECORDING, (HistoryDelCBPtr) mmi_fmsr_del_scr_callback);

    OslMfree(str);

#ifdef __MMI_SUBLCD__
    ForceSubLCDScreen(mmi_fmsr_entry_sublcd_msg_screen);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_exit_show_msg
 * DESCRIPTION
 *  exit show message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_exit_show_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    if (GetSubLCDScreenCountInHistory() > 0)
    {
        GoBackSubLCDHistory();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_show_msg_confirm
 * DESCRIPTION
 *  action after confirm record result message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_show_msg_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Enalbe power off in RTC power on alarm */
    mmi_alm_enable_pwroff();
    
    /* power on record, just go back history. */
    if (g_fmsr_cntx.rec.power_on_record)
    {
        GoBackHistory();
    }
    /* power off record, shutdown handset. */
    else
    {
    #ifdef __NVRAM_IN_USB_MS__
        if (USBMS_BOOT == stack_query_boot_mode() && g_charbat_context.isChargerConnected)
        {
            UsbPwnOnThenPwnOn();
        }
        else
    #endif /* __NVRAM_IN_USB_MS__ */ 
        {
            mmi_alm_check_history_and_poweroff();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_show_msg_prepare_data
 * DESCRIPTION
 *  Prepare the show message data.
 * PARAMETERS
 *  str     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_show_msg_prepare_data(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy(str, GetString((U16) (STR_ID_FMSR_RECORD_FINISH_1 + g_fmsr_cntx.rec.index)), FMSR_MAX_MSG_BUFFER);
    mmi_ucs2ncat(str, (S8*) L"\n", FMSR_MAX_MSG_BUFFER);

    mmi_ucs2ncat(str, GetString(g_fmsr_cntx.rec.error_str_id), FMSR_MAX_MSG_BUFFER);
    mmi_ucs2ncat(str, (S8*) L"\n", FMSR_MAX_MSG_BUFFER);

    if (g_fmsr_cntx.rec.error_msg & FMSR_MSG_REC_INTERRUPT)
    {
        mmi_ucs2ncat(str, GetString(STR_ID_FMSR_SYSTEM_INTERRUPT), FMSR_MAX_MSG_BUFFER);
        mmi_ucs2ncat(str, (S8*) L"\n", FMSR_MAX_MSG_BUFFER);
    }

    if (g_fmsr_cntx.rec.error_msg & FMSR_MSG_USER_STOP)
    {
        mmi_ucs2ncat(str, GetString(STR_ID_FMSR_USER_STOP), FMSR_MAX_MSG_BUFFER);
        mmi_ucs2ncat(str, (S8*) L"\n", FMSR_MAX_MSG_BUFFER);
    }

    if (g_fmsr_cntx.rec.error_msg & FMSR_MSG_REC_PAUSE)
    {
        mmi_ucs2ncat(str, GetString(STR_ID_FMSR_USER_PAUSE), FMSR_MAX_MSG_BUFFER);
        mmi_ucs2ncat(str, (S8*) L"\n", FMSR_MAX_MSG_BUFFER);
    }

    if (g_fmsr_cntx.rec.error_msg & FMSR_MSG_DEFAULT_FILE)
    {
        mmi_ucs2ncat(str, GetString(STR_ID_FMSR_USE_DEFAULT_FILE), FMSR_MAX_MSG_BUFFER);
        mmi_ucs2ncat(str, (S8*) L"\n", FMSR_MAX_MSG_BUFFER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_record_error_hdlr
 * DESCRIPTION
 *  Error handler for all record situaion
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_record_error_hdlr(S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: Set Trace Here

    switch (cause)
    {
            /*
             *  Here are MDI or Media Task Errors.
             */
        case MDI_AUDIO_SUCCESS:
            /* GoBackHistory(); */
            str_id = STR_GLOBAL_DONE;
            break;
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
            str_id = STR_GLOBAL_ERROR;
            break;
        case MDI_AUDIO_BAD_FORMAT:
            str_id = STR_ID_FMSR_BAD_FORMAT;
            break;
        case MDI_AUDIO_INVALID_FORMAT:
            str_id = STR_ID_FMSR_INVALID_FORMAT;
            break;
        case MDI_AUDIO_BUSY:
            str_id = STR_ID_FMSR_DEVICE_BUSY;
            break;
        case MDI_AUDIO_DISC_FULL:
        case MDI_AUDIO_NO_SPACE:
            str_id = FMGR_FS_DISK_FULL_TEXT;
            break;
        case MDI_AUDIO_OPEN_FILE_FAIL:
            str_id = STR_ID_FMSR_OPEN_FILE_ERROR;
            break;
        case MDI_AUDIO_NO_DISC:
            str_id = STR_ID_FMSR_NO_CARD;
            break;
        case MDI_AUDIO_WRITE_PROTECTION:
            str_id = STR_ID_FMSR_WRITE_PROTECTION_ERROR;
            break;
        case MDI_AUDIO_HFP_SCO_CONNECTED:
            str_id = STR_ID_FMSR_RECORD_IN_BT_SCO;
            break;

        case MDI_AUDIO_END_OF_FILE:
        case MDI_AUDIO_TERMINATED:
            /* GoBackHistory(); */
            str_id = STR_GLOBAL_DONE;
            break;

            /*
             *  Here are MMI Errors.
             */
    #if defined(__DRM_SUPPORT__)
        case DRM_NOT_PERMIT_TO_APPEND:
            str_id = STR_GLOBAL_DRM_PROHIBITED;
            break;
    #endif /* defined(__DRM_SUPPORT__) */ 
        case FMSR_ERROR_TIME_EXPIRE:
            str_id = STR_ID_FMSR_TIME_EXPIRE;
            break;
        case FMSR_ERROR_INVALID_FREQ:
            str_id = STR_ID_FMSR_INVALID_FREQUENCY;
            break;
        case FMSR_ERROR_NO_FOLDER:
            str_id = STR_ID_FMSR_CANT_CREATE_FOLDER;
            break;
        case FMSR_ERROR_USB_MODE:
            str_id = STR_ID_FMSR_IN_USB_MODE;
            break;

        default:
            str_id = STR_GLOBAL_DONE;
            /* GoBackHistory(); */
            break;
    }

    if (g_fmsr_cntx.rec.is_show_msg && GetActiveScreenId() != SCR_ID_FMSR_SHOW_MESSAGE)
    {
        g_fmsr_cntx.rec.error_str_id = str_id;
        mmi_fmsr_show_record_result();
    }

}

#define MMI_FMSR_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_battery_status_interrupt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fmsr_battery_status_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interrupt_event & MMI_FRM_INT_BATTERY)
    {
        SetInterruptPopupDisplay(POPUP_ALL_OFF);
    }

    return FALSE;   /* return false will process defualt hdlr */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_post_interrupt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fmsr_post_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_ON);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_deinit_app
 * DESCRIPTION
 *  Deinit function for schedule FM record App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmsr_is_schedule_rec_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(GetActiveScreenId() == SCR_ID_FMSR_RECORDING)
    {
        return MMI_TRUE;
    }
    else if(IsScreenPresent(SCR_ID_FMSR_RECORDING))
    {
        return MMI_TRUE;        
    }
    
    return MMI_FALSE;
}

#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ /* #ifdef __MMI_FM_RADIO_SCHEDULE_REC__ */
#endif /* _MMI_FMSR_C */ /* #ifndef _MMI_FMSR_C */

