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
 *  JMMSMessageSettingsUtils.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_include.h"
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "JMMSStoreHandling.h"
#include "MainMenuDef.h"
#include "MessagingDataTypes.h"

#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
#include "JMMSCompose.h"
#include "JMMSGprot.h"
#include "JMMSInbox.h"
#include "JMMSJSRHandler.h"
#include "JMMSMainMMS.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSOutbox.h"
#include "JMMSProtocols.h"
#include "JMMSPushHandling.h"
#include "JMMSResDef.h"
#include "JMMSSent.h"
#include "JMMSStoreHandling.h"
#include "JMMSStructs.h"
#include "JMMSTemplates.h"
#include "JMMSUseDetails.h"
#include "JMMSView.h"
#include "JMMSWriteMMS.h"
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "Conversions.h"
#endif 
#include "mdi_datatype.h"
#include "mdi_audio.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* /compose settings wrapper */
// #ifdef __MMI_MMS_SIGNATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_auto_sign_status
 * DESCRIPTION
 *  Returns the auto signature status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_compose_settings_auto_sign_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_compose_settings.auto_signature;
}

// #endif /* __MMI_MMS_SIGNATURE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_best_page_duration
 * DESCRIPTION
 *  Returns the best page duration status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_jmms_compose_settings_best_page_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_compose_settings.best_page_duration;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_creation_mode
 * DESCRIPTION
 *  Returns the  status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
ECreationMode mmi_jmms_compose_settings_creation_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_jmms_context->nvram_compose_settings.creation_mode)
    {
        case E_CREAT_MODE_RESTRICTED:
            return E_CREATION_MODE_RESTRICTED;
    #ifndef __MMI_UNIFIED_COMPOSER__
        case E_CREAT_MODE_WARNING:
            return E_CREATION_MODE_WARNING;
    #endif /* __MMI_UNIFIED_COMPOSER__ */ 
        case E_CREAT_MODE_FREE:
            return E_CREATION_MODE_FREE;
        default:
            return E_CREATION_MODE_WARNING;
    }

}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_compose_add_as_drm
 * DESCRIPTION
 *  Returns the add as drm object status set in compose settings
 * PARAMETERS
 *  filePath        [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_is_compose_add_as_drm(JC_CHAR *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_media_type_enum media_type = MEDIA_OTHER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->nvram_compose_settings.add_drm)
    {
        if (mmi_ucs2str((S8*) filePath, (S8*) L"3gp") != NULL || mmi_ucs2str((S8*) filePath, (S8*) L"mp4") != NULL)
        {
            EMediaType media_type;

            if (mdi_audio_is_pure_audio((void*)filePath) == KAL_TRUE)
            {
                media_type = E_MEDIA_AUDIO;
            }
            else
            {
                media_type = E_MEDIA_OTHERS;
            }
        }
        media_type = mmi_jmms_get_mms_media_type_from_file(filePath, media_type);
        switch (media_type)
        {
            case MEDIA_IMAGE:
            case MEDIA_AUDIO:
            case MEDIA_VIDEO:
                return MMI_TRUE;
            default:
                return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_layout
 * DESCRIPTION
 *  Returns the layout(Potrait/Landscape)  status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_compose_settings_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_compose_settings.layout;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_max_no_pages
 * DESCRIPTION
 *  Returns the max no pages value set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_compose_settings_max_no_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_compose_settings.max_no_pages;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_default_slide_time
 * DESCRIPTION
 *  Returns the  default slide time set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_jmms_compose_settings_default_slide_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_compose_settings.default_slide_time;
}

// #ifdef __MMI_MMS_SIGNATURE__

#ifdef __UNIFIED_COMPOSER_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_auto_sign_content
 * DESCRIPTION
 *  Returns the  auto sign content set in compose settings
 * PARAMETERS
 *  content         [IN]       (ponter to auto sign content)
 *  buffer_size     [IN]        
* RETURNS
 *  length
 *****************************************************************************/
S32 mmi_jmms_compose_settings_auto_sign_content(U8 *content, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_chset_ucs2_to_utf8_string(
                (kal_uint8*) content,
                buffer_size,
                (kal_uint8*) g_jmms_context->nvram_compose_settings.auto_signature_content);
    return length;
}

#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_auto_sign_content
 * DESCRIPTION
 *  Returns the  auto sign content set in compose settings
 * PARAMETERS
 *  content     [IN]        (ponter to auto sign content)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_settings_auto_sign_content(U8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    content = g_jmms_context->nvram_compose_settings.auto_signature_content;
}
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
// #endif /* __MMI_MMS_SIGNATURE__ */

/* /sending settings wrapper */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_delivery_report
 * DESCRIPTION
 *  Returns the delivery report status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_sending_settings_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_sending_settings.delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_delivery_time
 * DESCRIPTION
 *  Returns the  delivery time value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U32 mmi_jmms_sending_settings_delivery_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_jmms_context->nvram_sending_settings.delivery_time)
    {
        case E_IMMEDIATE:
            return (0);
        case E_1_HR:
            return 3600;
        case E_12_HRS:
            return (12 * 3600);
        case E_24_HRS:
            return (24 * 3600);
        default:
            return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_delivery_time_enum
 * DESCRIPTION
 *  Returns the  delivery time enum value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
S32 mmi_jmms_sending_settings_delivery_time_enum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_jmms_context->nvram_sending_settings.delivery_time);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_hide_sender
 * DESCRIPTION
 *  Returns the hide sender status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_sending_settings_hide_sender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_sending_settings.hide_sender;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_priority
 * DESCRIPTION
 *  Returns the priroty value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_sending_settings_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_jmms_context->nvram_sending_settings.priority)
    {
        case E_PRIORITY_LOW:
            return E_MSG_PRIORITY_LOW;
        case E_PRIORITY_NORMAL:
            return E_MSG_PRIORITY_NORMAL;
        case E_PRIORITY_HIGH:
            return E_MSG_PRIORITY_HIGH;
    }

    return E_MSG_PRIORITY_NORMAL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_read_report
 * DESCRIPTION
 *  Returns the read report status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_sending_settings_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_sending_settings.read_report;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_image_resige_option
 * DESCRIPTION
 *  Returns the read report status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
S32 mmi_jmms_image_resige_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_compose_settings.image_resize_option;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_validity_period
 * DESCRIPTION
 *  Returns the validity period value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U32 mmi_jmms_sending_settings_validity_period(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_jmms_context->nvram_sending_settings.validity_period)
    {
        case E_VALIDITY_PERIOD_MAX:
            return (U32) MAX_VALIDITY_PERIOD_VALUE;
        case E_VALIDITY_PERIOD_1HR:
            return (U32) 3600;
        case E_VALIDITY_PERIOD_12HRS:
            return (U32) (12 * 3600);
        case E_VALIDITY_PERIOD_1DAY:
            return (U32) (1 * 24 * 3600);
        case E_VALIDITY_PERIOD_1WEEK:
            return (U32) (1 * 7 * 24 * 3600);
        default:
            return (U32) MAX_VALIDITY_PERIOD_VALUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_validity_period_enum
 * DESCRIPTION
 *  Returns the validity period value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
S32 mmi_jmms_sending_settings_validity_period_enum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_jmms_context->nvram_sending_settings.validity_period);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_reply_charging_status
 * DESCRIPTION
 *  Returns the reply charging status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_sending_settings_reply_charging_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_sending_settings.reply_charging;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_reply_charging_request_type
 * DESCRIPTION
 *  Returns the reply charging request type set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_sending_settings_reply_charging_request_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_jmms_context->nvram_sending_settings.request_type)
    {
        case E_FULL_MMS:
            return E_REQUEST_REPLY_CHARGING;
        case E_TEXT_ONLY:
            return E_REQUEST_TEXT_ONLY_REPLY_CHARGING;
        default:
            return E_REQUEST_REPLY_CHARGING;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_deadline_for_reply
 * DESCRIPTION
 *  Returns the  deadline for reply set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_jmms_sending_settings_deadline_for_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_sending_settings.deadline_for_reply;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_reply_charging_size
 * DESCRIPTION
 *  Returns the reply charging size value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U32 mmi_jmms_sending_settings_reply_charging_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_sending_settings.size;
}

/* /retrieval settings wrapper */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_home_network_retrieval_mode
 * DESCRIPTION
 *  Retruns the home network retrieval mode set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_retrieval_settings_home_network_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_retrieval_settings.home_network;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_roaming_retrieval_mode
 * DESCRIPTION
 *  Retruns the roaming retrieval mode set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_retrieval_settings_roaming_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_retrieval_settings.roaming;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_anonymous_filter
 * DESCRIPTION
 *  Retruns the anonymous status(Allow/reject) set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_retrieval_settings_anonymous_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_retrieval_settings.anonymous_filter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_advertisment_filter
 * DESCRIPTION
 *  Retruns the advertisement status(Allow/reject) set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_retrieval_settings_advertisment_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_retrieval_settings.advertisement_filter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_read_report
 * DESCRIPTION
 *  Retruns the read report status set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_retrieval_settings_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_retrieval_settings.read_report;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_delivery_report
 * DESCRIPTION
 *  Retruns the delivery report status set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_retrieval_settings_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_retrieval_settings.delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_msg_size_filter
 * DESCRIPTION
 *  Retruns the msg size filter value set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U32 mmi_jmms_retrieval_settings_msg_size_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->nvram_retrieval_settings.msgsize_filter * 1024;
}
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
// #endif //#if 0 //Pranav Commeneted

