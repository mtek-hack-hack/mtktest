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
 * PushInboxCommonUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is common functions calls to be used by both service inbox and UM.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_PUSHINBOXCOMMONUI_C
#define _MMI_PUSHINBOXCOMMONUI_C

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "time.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "worldclock.h" /* Vivek - 01092006 */

#include "wap_ps_struct.h"
#include "wapadp.h"

#include "ddl.h"
#include "jcal.h"
#include "jdd_memapi.h"
#include "jdd_BrowserConfig.h"  /* Added by Vivek  - 08-nov-2006 */

#include "jdi_communicator.h"
#include "jdi_BrowserDatatype.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMIGprots.h"
#include "JBrowserMMITypes.h"
// #include "JBrowserStartup.h"
#include "wgui_status_icons.h"
/* PMT DARA  PROFILE HANDLER 020106 */
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "UnifiedMessageResDef.h"
#include "JPushInboxCommonAPIs.h"
#include "JPushInboxCommonUI.h"
#include "app_datetime.h"
#include "DateTimeGprot.h"
#include "PhoneSetupGprots.h"
#include "CallManagementGprot.h"

#if 0   /* commented by vikas lal */
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
#endif /* 0 */ 
extern void mmi_um_brw_delete_all_push_messages_ind(void);
extern void mmi_um_brw_highlight_push_messages_ind(void);

extern int wap_fix_push_time(kal_uint32 datetime[6]);


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_initialize_push_message_list
 * DESCRIPTION
 *  This function is responsible for initializing th push message list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_initialize_push_message_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get maximum number of push mesages supported */
#ifdef __MMI_UNIFIED_MESSAGE__

    g_mmi_brw_push_cntx.max_push_messages = MMI_UM_MAX_GET_LIST_MSG_NUMBER;
#else /* __MMI_UNIFIED_MESSAGE__ */ 

    g_mmi_brw_push_cntx.max_push_messages = jdd_BrowserConfigGetMaxPushMessage();
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    g_mmi_brw_push_cntx.service_msg_list_p =
        (SERVICE_VALUE **) jdd_MemAlloc(g_mmi_brw_push_cntx.max_push_messages, sizeof(SERVICE_VALUE*));
    /* TODO : null check */
    if (NULL != g_mmi_brw_push_cntx.service_msg_list_p)
    {
        jc_memset(
            g_mmi_brw_push_cntx.service_msg_list_p,
            0,
            g_mmi_brw_push_cntx.max_push_messages * sizeof(SERVICE_VALUE*));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_deinitialize_push_message_list
 * DESCRIPTION
 *  This function is responsible for freeing the push message list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_deinitialize_push_message_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_push_cntx.service_msg_list_p != NULL)
    {
        jdd_MemFree(g_mmi_brw_push_cntx.service_msg_list_p);
        g_mmi_brw_push_cntx.service_msg_list_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_free_service_value_struct
 * DESCRIPTION
 *  This function is responsible for freeing service value struct.
 * PARAMETERS
 *  service_message     [IN]        Service value structure.
 * RETURNS
 *  Returns local time.
 *  
 *  Note : function is freeing only those field which are copied in.
 *  mmi_brw_push_service_value_struct_dup. - Vivek 13072006.
 *****************************************************************************/
void mmi_brw_push_free_service_value_struct(SERVICE_VALUE **service_message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL == service_message) || (NULL == *service_message))
    {
        return;
    }

    if ((*service_message)->pmHref != NULL)
    {
        jdd_MemFree((*service_message)->pmHref);
        (*service_message)->pmHref = NULL;
    }

    if ((*service_message)->pSICreated != NULL)
    {
        jdd_MemFree((*service_message)->pSICreated);
        (*service_message)->pSICreated = NULL;
    }

    if ((*service_message)->pSIExpires != NULL)
    {
        jdd_MemFree((*service_message)->pSIExpires);
        (*service_message)->pSIExpires = NULL;
    }

    if ((*service_message)->pSIRcvd != NULL)
    {
        jdd_MemFree((*service_message)->pSIRcvd);
        (*service_message)->pSIRcvd = NULL;
    }

    if ((*service_message)->pmMessage != NULL)
    {
        jdd_MemFree((*service_message)->pmMessage);
        (*service_message)->pmMessage = NULL;
    }

    jdd_MemFree(*service_message);
    *service_message = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_service_value_struct_dup
 * DESCRIPTION
 *  This function is responsible for creating the copy of service value structure.
 * PARAMETERS
 *  service_message     [IN]        
 * RETURNS
 *  returns local time.
 *  Note : We are copying only those value which are needed in MMI. - Vivek 13072006.
 *****************************************************************************/
SERVICE_VALUE *mmi_brw_push_service_value_struct_dup(SERVICE_VALUE *service_message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SERVICE_VALUE *dup_service_message = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dup_service_message = (SERVICE_VALUE*) jdd_MemAlloc(1, sizeof(SERVICE_VALUE));
    if (NULL == dup_service_message)
    {
        return NULL;
    }

    dup_service_message->service_flag = service_message->service_flag;

    if (service_message->pmMessage != NULL)
    {
        dup_service_message->pmMessage =
            (JC_CHAR*) jdd_MemAlloc(jc_tcslen(service_message->pmMessage) + 1, sizeof(JC_CHAR));
        if (NULL == dup_service_message->pmMessage)
        {
            mmi_brw_push_free_service_value_struct(&dup_service_message);
            return NULL;
        }

        jc_tcscpy(dup_service_message->pmMessage, service_message->pmMessage);
    }

    if (service_message->pmHref != NULL)
    {
        dup_service_message->pmHref = (JC_CHAR*) jdd_MemAlloc(jc_tcslen(service_message->pmHref) + 1, sizeof(JC_CHAR));
        if (NULL == dup_service_message->pmHref)
        {
            mmi_brw_push_free_service_value_struct(&dup_service_message);
            return NULL;
        }

        jc_tcscpy(dup_service_message->pmHref, service_message->pmHref);
    }

    if (NULL != service_message->pSICreated)
    {
        dup_service_message->pSICreated = (SI_TIME*) jdd_MemAlloc(1, sizeof(SI_TIME));
        if (NULL == dup_service_message->pSICreated)
        {
            mmi_brw_push_free_service_value_struct(&dup_service_message);
            return NULL;
        }

        jc_memmove(dup_service_message->pSICreated, service_message->pSICreated, sizeof(SI_TIME));
    }

    if (NULL != service_message->pSIRcvd)
    {
        dup_service_message->pSIRcvd = (SI_TIME*) jdd_MemAlloc(1, sizeof(SI_TIME));
        if (NULL == dup_service_message->pSIRcvd)
        {
            mmi_brw_push_free_service_value_struct(&dup_service_message);
            return NULL;
        }

        jc_memmove(dup_service_message->pSIRcvd, service_message->pSIRcvd, sizeof(SI_TIME));
    }

    if (NULL != service_message->pSIExpires)
    {
        dup_service_message->pSIExpires = (SI_TIME*) jdd_MemAlloc(1, sizeof(SI_TIME));
        if (NULL == dup_service_message->pSIExpires)
        {
            mmi_brw_push_free_service_value_struct(&dup_service_message);
            return NULL;
        }

        jc_memmove(dup_service_message->pSIExpires, service_message->pSIExpires, sizeof(SI_TIME));
    }

    return dup_service_message;
}


/*****************************************************************************
 * FUNCTION
 *  convert_gmt_in_to_local_time
 * DESCRIPTION
 *  This function is responsible for converting GMT time in to local time.
 * PARAMETERS
 *  gmt_time_p      [IN]        
 * RETURNS
 *  returns local time.
 *****************************************************************************/
static SI_TIME convert_gmt_in_to_local_time(SI_TIME *gmt_time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tzdiff = 0;
    U32 timeSecs = 0;
    U32 local_time = 0;
    FLOAT tz = 0.0;

    applib_time_struct result = {0};
    applib_time_struct currGMTTime = {0};

    SI_TIME local_time_p = {0};

    applib_time_struct time = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == gmt_time_p)
    {
        return local_time_p;
    }

    currGMTTime.nSec = gmt_time_p->seconds;
    currGMTTime.nMin = gmt_time_p->minute;
    currGMTTime.nHour = gmt_time_p->hour;
    currGMTTime.nDay = gmt_time_p->day;
    currGMTTime.nMonth = gmt_time_p->month;
    currGMTTime.nYear = gmt_time_p->year;

    /* timeSecs = (U32) mmi_dt_mytime_2_utc_sec(&currGMTTime, MMI_TRUE); */
    timeSecs = (U32) applib_dt_mytime_2_utc_sec(&currGMTTime, MMI_TRUE);

    tz = mmi_dt_get_tz();
    if (tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff = time.nHour * 3600 + time.nMin * 60 + time.nSec;

    if (tz > 0)
    {
        local_time = timeSecs + tzdiff;
    }
    else
    {
        local_time = timeSecs - tzdiff;
    }

    /* mmi_dt_utc_sec_2_mytime(local_time, &result, MMI_TRUE); */
    applib_dt_utc_sec_2_mytime(local_time, &result, MMI_TRUE);

    local_time_p.year = result.nYear;
    local_time_p.month = result.nMonth;
    local_time_p.day = result.nDay;
    local_time_p.hour = result.nHour;
    local_time_p.minute = result.nMin;
    local_time_p.seconds = result.nSec;

    return local_time_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_push_display_format
 * DESCRIPTION
 *  This function is responsible for creating the formatted Push message string.
 *  Push message should display in the following format.
 *  SI message should be display in the following format(example)
 *  
 *  10 jan 2006 12:00 (If created date is not present then received date should be here)
 *  Expires:
 *  20 Jun 2006 12:00
 *  URL:
 *  http://www.exampleSISL.com
 *  Message:
 *  SISL message Body
 *  
 *  for SL messages only URL should display.
 * PARAMETERS
 *  push_message_struct     [IN]        Structure pointer which contatins all the information
 * RETURNS
 *  returns buffer, which contains the formatted string of push messages.
 *****************************************************************************/
PS8 mmi_brw_create_push_display_format(SERVICE_VALUE *push_message_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 message_length = 0;
    S16 message_href_length = 0;
    S16 meassage_body_length = 0;

    PS8 ucs2_message_buffer = NULL;
    S8 ucs2_time_string[MMI_BRW_SI_DATE_N_TIME_STRING_LENGTH] = {0};

    SI_TIME sisl_local_time = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (push_message_struct->service_flag == SERVICE_INDICATION)
    {
        meassage_body_length = mmi_ucs2strlen((const S8*)push_message_struct->pmMessage);
        message_href_length = mmi_ucs2strlen((const S8*)push_message_struct->pmHref);

        /* Calculate the length of the message */
        message_length = message_href_length + meassage_body_length +
            MMI_BRW_SI_DATE_N_TIME_STRING_LENGTH +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_MESSAGE)) +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_URL));

        if (NULL != push_message_struct->pSIExpires)
        {
            message_length += (MMI_BRW_SI_DATE_N_TIME_STRING_LENGTH +
                               mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_EXPIRES)));
        }

        /* adding 1 for '\0' */
        ucs2_message_buffer = (PS8) jdd_MemAlloc((message_length + 1), ENCODING_LENGTH);
        if (NULL == ucs2_message_buffer)
        {
            return NULL;
        }

        if (NULL != push_message_struct->pSICreated)
        {
            sisl_local_time = convert_gmt_in_to_local_time(push_message_struct->pSICreated);
        }
        else    /* If date Created is not present, use date received. */
        {
            sisl_local_time = convert_gmt_in_to_local_time(push_message_struct->pSIRcvd);
        }
        mmi_brw_create_ucs2_push_time_format_string(&sisl_local_time, ucs2_time_string);

        mmi_ucs2cpy(ucs2_message_buffer, ucs2_time_string);
        mmi_ucs2cat(ucs2_message_buffer, "\n");

        if (NULL != push_message_struct->pSIExpires)
        {
            mmi_ucs2cat(ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_EXPIRES));
            mmi_ucs2cat(ucs2_message_buffer, "\n");

            sisl_local_time = convert_gmt_in_to_local_time(push_message_struct->pSIExpires);
            mmi_brw_create_ucs2_push_time_format_string(&sisl_local_time, ucs2_time_string);

            mmi_ucs2cat(ucs2_message_buffer, ucs2_time_string);
            mmi_ucs2cat(ucs2_message_buffer, "\n");
        }

        mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_URL));
        mmi_ucs2cat(ucs2_message_buffer, "\n");

        mmi_ucs2cat((S8*) ucs2_message_buffer, (const S8*)push_message_struct->pmHref);
        mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");

        if (0 != meassage_body_length)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_MESSAGE));
            mmi_ucs2cat(ucs2_message_buffer, "\n");

            mmi_ucs2cat((S8*) ucs2_message_buffer, (const S8*)push_message_struct->pmMessage);
        }
    }

    else if (push_message_struct->service_flag == SERVICE_LOADING)
    {
        message_href_length = mmi_ucs2strlen((const S8*)push_message_struct->pmHref);
        message_length = message_href_length + mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_URL));

        ucs2_message_buffer = (PS8) jdd_MemAlloc((message_length + 2), ENCODING_LENGTH);
        if (NULL == ucs2_message_buffer)
        {
            return NULL;
        }

        mmi_ucs2cpy(ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_URL));

        mmi_ucs2cat(ucs2_message_buffer, "\n");
        mmi_ucs2cat((S8*) ucs2_message_buffer, (const S8*)push_message_struct->pmHref);
    }

    else
    {
        /* error */
    }

    return ucs2_message_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_ucs2_push_time_format_string
 * DESCRIPTION
 *  This function is responsible for generating time string (As given in the following  example),
 *  which will be displayed with push messages.
 *  Ex. : 20 Jun 2006 12:00
 * PARAMETERS
 *  sisl_time               [IN]        
 *  ucs2_time_string        [IN]        
 * RETURNS
 *  returns buffer, which contains the formatted string of time for push messages.
 *****************************************************************************/
void mmi_brw_create_ucs2_push_time_format_string(SI_TIME *sisl_time, PS8 ucs2_time_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time = {0};
    UI_character_type temp_time_buffer[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time.nYear = sisl_time->year;
    time.nMonth = sisl_time->month;
    time.nDay = sisl_time->day;
    time.nHour = sisl_time->hour;
    time.nMin = sisl_time->minute;
    time.nSec = sisl_time->seconds;

    date_string(&time, temp_time_buffer, DT_IDLE_SCREEN);

    mmi_ucs2ncpy((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));

    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) " ", 1);

    time_string(&time, temp_time_buffer, DT_IDLE_SCREEN);

    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));

    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) "\0", 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_read_push_message_exit
 * DESCRIPTION
 *  Exit Function to read arrived push message form idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_read_push_message_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_mmi_brw_push_cntx.message_buffer)
    {
        jdd_MemFree(g_mmi_brw_push_cntx.message_buffer);
        g_mmi_brw_push_cntx.message_buffer = NULL;
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    if (!IsScreenPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE))
    {
        mmi_brw_push_free_service_value_struct(&g_mmi_brw_push_cntx.current_service_message);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_idle_screen_read_message_back_option
 * DESCRIPTION
 *  This function will be called when RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_idle_screen_read_message_back_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_entry_service_inbox();

    DeleteScreenIfPresent(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND);
    DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);

    /* DeleteUptoScrID(IDLE_SCREEN_ID); */
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_read_push_message
 * DESCRIPTION
 *  Deletes the entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_read_push_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 buffer_size;
    SERVICE_VALUE *selected_push_message_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_push_cntx.push_delete_notification = MMI_FALSE;

    if (NULL == g_mmi_brw_push_cntx.current_service_message)
    {
        selected_push_message_p = g_mmi_brw_push_cntx.service_msg_list_p[g_mmi_brw_push_cntx.curr_hilited_item_index];

        /* Set the read status */
        mmi_brw_set_read_status(1, g_mmi_brw_push_cntx.service_msg_list_p[g_mmi_brw_push_cntx.curr_hilited_item_index]);

        /* Save to persistant storage */
        mmi_brw_save_current_push_info();

        mmi_brw_unread_push_message_indication();
        UpdateStatusIcons();    /* Added By Vivek 24072006 */

        g_mmi_brw_push_cntx.message_buffer = (U8*) mmi_brw_create_push_display_format(selected_push_message_p);
        if (NULL == g_mmi_brw_push_cntx.message_buffer)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_PUSH_MEMORY_NOT_ENOUGH),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }

        g_mmi_brw_push_cntx.current_service_message = mmi_brw_push_service_value_struct_dup(selected_push_message_p);
        if (NULL == g_mmi_brw_push_cntx.current_service_message)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_PUSH_MEMORY_NOT_ENOUGH),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
    }
    else
    {
        g_mmi_brw_push_cntx.message_buffer =
            (U8*) mmi_brw_create_push_display_format(g_mmi_brw_push_cntx.current_service_message);
        if (NULL == g_mmi_brw_push_cntx.message_buffer)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_PUSH_MEMORY_NOT_ENOUGH),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
        selected_push_message_p = g_mmi_brw_push_cntx.current_service_message;
    }

    EntryNewScreen(
        SCR_ID_BRW_READ_SERVICE_MESSAGE,
        mmi_brw_entry_read_push_message_exit,
        mmi_brw_entry_read_push_message,
        NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_READ_SERVICE_MESSAGE);

    buffer_size = mmi_ucs2strlen((PS8) g_mmi_brw_push_cntx.message_buffer);

    if (selected_push_message_p->service_flag == SERVICE_LOADING)
    {
        ShowCategory74Screen(
            STR_ID_BRW_MESSAGE,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_brw_push_cntx.message_buffer,
            buffer_size,
            gui_buffer);
    }
    else if (selected_push_message_p->service_flag == SERVICE_INDICATION)
    {
        ShowCategory74Screen(
            STR_ID_BRW_MESSAGE,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_brw_push_cntx.message_buffer,
            buffer_size,
            gui_buffer);
    }
    else
    {
        /* Assert */
    }

    SetLeftSoftkeyFunction(mmi_brw_entry_service_inbox_read_options, KEY_EVENT_UP);

#ifndef __MMI_UNIFIED_MESSAGE__

    if (TRUE == IsScreenPresent(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND))
    {
        SetRightSoftkeyFunction(mmi_brw_idle_screen_read_message_back_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_idle_screen_read_message_back_option, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_unread_push_message_indication
 * DESCRIPTION
 *  Function to show unread push message icon on idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_unread_push_message_indication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 brw_total_msg_count = 0;
    JC_UINT32 brw_unread_msg_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If browser is not ready then return */
    if (!mmi_brw_jbrowser_is_ready())
    {
        return; /* added by tk */
    }

    /* Show unread push message icon on idle screen */
    mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);

    if (brw_unread_msg_count > 0)
    {
        /* Display unread message icon on idle screen */
        ShowStatusIcon(STATUS_ICON_WAP);
    }
    else
    {
        /* hide unread push message icon on idle screen */
        HideStatusIcon(STATUS_ICON_WAP);
    }

    /* Commneted  by Vivek to fix the status bar rehresh prblem */
    /* refresh_status_icon_display(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_service_inbox_read_options
 * DESCRIPTION
 *  Entry function for recent page options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_service_inbox_read_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uc_list_of_items[3];
    U8 *gui_buffer;
    S32 num_of_items;
    U16 parent_menuid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_PUSH_MESSAGE_READ_OPTIONS, NULL, mmi_brw_entry_service_inbox_read_options, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_PUSH_MESSAGE_READ_OPTIONS);

    if (!isInCall())
    {
        parent_menuid = MENU_ID_BRW_PUSH_MSG_READ_OPTIONS_1;
    }
    else
    {
        parent_menuid = MENU_ID_BRW_PUSH_MSG_READ_OPTIONS_2;
    }

    num_of_items = GetNumOfChild(parent_menuid);
    GetSequenceStringIds(parent_menuid, uc_list_of_items);
    SetParentHandler(parent_menuid);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        uc_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_push_message_expired
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_brw_is_push_message_expired(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct tm expiry_timestamp = {0};
    time_t expiry_secs_since_1970 = {0};
    time_t current_secs_since_1970 = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_brw_push_cntx.current_service_message->service_flag == SERVICE_INDICATION) &&
        (NULL != g_mmi_brw_push_cntx.current_service_message->pSIExpires))
    {
        expiry_timestamp.tm_mon = g_mmi_brw_push_cntx.current_service_message->pSIExpires->month - 1;   /* month scale to 0 to 11 */
        expiry_timestamp.tm_year = g_mmi_brw_push_cntx.current_service_message->pSIExpires->year - 1900;        /* offset since 1900 */
        expiry_timestamp.tm_mday = g_mmi_brw_push_cntx.current_service_message->pSIExpires->day;
        expiry_timestamp.tm_hour = g_mmi_brw_push_cntx.current_service_message->pSIExpires->hour;
        expiry_timestamp.tm_min = g_mmi_brw_push_cntx.current_service_message->pSIExpires->minute;
        expiry_timestamp.tm_sec = g_mmi_brw_push_cntx.current_service_message->pSIExpires->seconds;

        /* Get difference of seconds of expiry time from 1970 (as per UTC standard) */
        expiry_secs_since_1970 = (time_t) mktime(&expiry_timestamp);
        /* Get difference of seconds of current time from 1970 (as per UTC standard) */
        current_secs_since_1970 = get_current_utc_time();

        if (expiry_secs_since_1970 <= current_secs_since_1970)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_accept_push_message
 * DESCRIPTION
 *  Deletes the entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_accept_push_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid_url;
    JC_RETCODE iRet = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TRUE == mmi_brw_is_push_message_expired())
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_PUSH_EXPIRED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        is_valid_url = mmi_brw_validate_url((U8*) g_mmi_brw_push_cntx.current_service_message->pmHref);
        if (is_valid_url == MMI_TRUE)
        {
        #ifdef JBROWSER_USE_ASM
            g_mmi_brw_cntx.init_app_flag = BRW_INIT_APP_GOTO_PUSH_MESSAGE;
        #endif 

            iRet = mmi_brw_jbrowser_init_app();
            if (iRet != JC_OK)
            {
                return;
            }

            mmi_brw_set_current_url((S8*) g_mmi_brw_push_cntx.current_service_message->pmHref);
            mmi_brw_pre_entry_goto_url();

            /* Start - PMTSW00006677 & PMTSW00007001 */

        #ifndef __MMI_UNIFIED_MESSAGE__

            /* 
             * When there is only one unread service message, We display the message body 
             * directly, instead of displaying the service Inbox, that is why  we are  adding 
             * service Inbox screen so that while pressing cacel or while exiting the browser 
             * user will come on Service Inbox screen. 
             */
            if ((FALSE == IsScreenPresent(SCR_ID_BRW_SERVICE_INBOX)) &&
                (FALSE == IsScreenPresent(SCR_ID_BRW_SERVICE_INBOX_OPTIONS)))
            {
                HistoryReplace(SCR_ID_BRW_READ_SERVICE_MESSAGE, SCR_ID_BRW_SERVICE_INBOX, mmi_brw_entry_service_inbox);
            }
            DeleteUptoScrID(SCR_ID_BRW_SERVICE_INBOX);

        #else /* __MMI_UNIFIED_MESSAGE__ */ 

            g_mmi_brw_cntx.page_fetch_req_src = 1;
            DeleteUptoScrID(SCR_ID_UM_INBOX);

        #endif /* __MMI_UNIFIED_MESSAGE__ */ 

            /* End - PMTSW00006677 & PMTSW00007001 */

        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_INVALID_URL),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_confirm_delete_push_message
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of push message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_confirm_delete_push_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_BRW_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_delete_push_message, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_push_message
 * DESCRIPTION
 *  Deletes the push message from the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_push_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 brw_total_msg_count = 0;
    U32 brw_unread_msg_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_delete_push_msg(g_mmi_brw_push_cntx.curr_hilited_item_index);

    /* Added by Vivek - 13072006 */
    mmi_brw_push_free_service_value_struct(&g_mmi_brw_push_cntx.current_service_message);

    /* update the copy of local pointers */
    mmi_brw_create_push_msg_list();

    /* Save to persistant storage */
    mmi_brw_save_current_push_info();

    mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);

    if (brw_unread_msg_count > 0)
    {
        /* Display unread message icon on idle screen */
        ShowStatusIcon(STATUS_ICON_WAP);
    }
    else
    {
        /* hide unread push message icon on idle screen */
        HideStatusIcon(STATUS_ICON_WAP);
    }

    /* DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_DELETED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE); */
    /* Edited by Vivek - 02082006. Now instead of displaying the image IMG_GLOBAL_DELETED
       we are displaying IMG_GLOBAL_ACTIVATED as we are doing in other part of browser */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

#ifndef __MMI_UNIFIED_MESSAGE__

    if (IsScreenPresent(SCR_ID_BRW_SERVICE_INBOX))
    {
        DeleteUptoScrID(SCR_ID_BRW_SERVICE_INBOX);
    }
    else    /* when message is deleted from idle screen */
    {
        mmi_brw_entry_service_inbox();
        DeleteScreenIfPresent(SCR_ID_BRW_PUSH_MESSAGE_READ_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND);
        DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
    }

#else /* __MMI_UNIFIED_MESSAGE__ */ 

    mmi_um_brw_highlight_push_messages_ind();
    DeleteUptoScrID(SCR_ID_UM_INBOX);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_confirm_delete_all_push_messages
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_confirm_delete_all_push_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
#ifndef __MMI_UNIFIED_MESSAGE__
                   get_string(STR_ID_BRW_DELETE_ALL),
#else 
                   get_string(STR_ID_BRW_DELETE_ALL_INBOX),
#endif 
                   IMG_GLOBAL_QUESTION, WARNING_TONE);

#ifndef __MMI_UNIFIED_MESSAGE__
    SetLeftSoftkeyFunction(mmi_brw_delete_all_push_messages, KEY_EVENT_UP);
#else 
    SetLeftSoftkeyFunction(mmi_um_brw_delete_all_push_messages_ind, KEY_EVENT_UP);
#endif 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_push_msg_list
 * DESCRIPTION
 *  Function to create the list of push messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_create_push_msg_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msg_counter = 0, temp_ctr;
    SERVICE_VALUE *service_msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (temp_ctr = 0; temp_ctr < g_mmi_brw_push_cntx.max_push_messages; temp_ctr++)
    {
        if (g_mmi_brw_push_cntx.service_msg_list_p[temp_ctr] != NULL)
        {
            g_mmi_brw_push_cntx.service_msg_list_p[temp_ctr] = NULL;
        }
        else
        {
            break;
        }
    }

    /* Get Jataayu service list */
    mmi_brw_get_push_servicelist(&service_msg_p);

    while (service_msg_p != NULL)
    {
        g_mmi_brw_push_cntx.service_msg_list_p[msg_counter] = service_msg_p;
        service_msg_p = service_msg_p->pNext;
        msg_counter++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_current_utc_time
 * DESCRIPTION
 *  This function returns the current time of the system.
 *  The time returned is UTC time.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32.
 *****************************************************************************/
U32 get_current_utc_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 timeSecs;
    FLOAT tz;
    U32 tzdiff = 0;
    MYTIME t;
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dt_get_secure_time(&t);
    timeSecs = mmi_dt_mytime_2_utc_sec(&t, TRUE);
    tz = mmi_dt_get_tz();
    if (tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff = time.nHour * 3600 + time.nMin * 60 + time.nSec;
    if (tz > 0)
    {
        return timeSecs - tzdiff;
    }
    else
    {
        return timeSecs + tzdiff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_check_for_maximun_time
 * DESCRIPTION
 *  This function modify the SI time received to the maximum limit of time
 * PARAMETERS
 *  time_p      [IN]        
 * RETURNS
 *  1 if time modified otherwise returns 0;.
 *****************************************************************************/
U32 mmi_brw_push_check_for_maximun_time(SI_TIME **time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 datetime[6] = {0};
    U32 is_modified = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (time_p == NULL)
    {
        return 0;
    }
    datetime[0] = (*time_p)->year;
    datetime[1] = (*time_p)->month;
    datetime[2] = (*time_p)->day;
    datetime[3] = (*time_p)->hour;
    datetime[4] = (*time_p)->minute;
    datetime[5] = (*time_p)->seconds;
    is_modified = wap_fix_push_time(datetime);

    (*time_p)->year = datetime[0];
    (*time_p)->month = datetime[1];
    (*time_p)->day = datetime[2];
    (*time_p)->hour = datetime[3];
    (*time_p)->minute = datetime[4];
    (*time_p)->seconds = datetime[5];
    return is_modified;
}

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _MMI_PUSHINBOXCOMMONUI_C */ 

