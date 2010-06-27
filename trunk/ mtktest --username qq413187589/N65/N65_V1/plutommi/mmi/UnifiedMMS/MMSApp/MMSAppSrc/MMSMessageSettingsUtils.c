/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSMessageSettingsUtils.C
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
****************************************************************************/

#include "MMI_include.h"
#if defined (__MMI_MMS_2__) && defined(MMS_SUPPORT)
//#include "FileSystemDef.h"
//#include "FileMgr.h"
//#include "Fmt_struct.h"
//#include "FileSystemGProt.h"
#include "FileManagerGProt.h"
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "Conversions.h"
#include "MainMenuDef.h"
#include "MMSXMLDef.h"
#include "MMSMessageSettingsUtils.h"
#include "MMSMessageSettings.h"
#include "MMSMessageTemplates.h"

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
extern umms_context_struct *g_umms_context;

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* /compose settings wrapper */
#ifdef __MMI_MMS_SIGNATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_sign_info
 * DESCRIPTION
 *  Returns the auto signature status set in compose settings
 * PARAMETERS
 *  signature       [?]     [?]
 * RETURNS
 *  U8(?)(?)
 *****************************************************************************/
void mmi_umms_compose_settings_sign_info(mma_signature_struct *signature)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_text_path[MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH];
    FS_HANDLE file_handle;
    U32 write_len = 0;
	S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(signature, 0, sizeof(mma_signature_struct));
    if (g_umms_context->nvram_compose_settings.auto_signature)
    {
		if(mmi_ucs2strlen((S8*) g_umms_context->nvram_compose_settings.auto_signature_content))
		{
        U32 utf8_buffer_size =
            (mmi_ucs2strlen((S8*) g_umms_context->nvram_compose_settings.auto_signature_content) * 3 + ENCODING_LENGTH);
        U8 *utf8_buffer = (U8*) OslMalloc(utf8_buffer_size);
        U32 utf8_len = 0;
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
			UMMS_MMI_MAKE_SETTINGS_TEXT_FILE_PATH(mmi_uc_text_path, 0);
			mmi_ucs2cpy((S8*) signature->text_file, (S8*) mmi_uc_text_path);
			signature->enable = g_umms_context->nvram_compose_settings.auto_signature;
			mmi_ucs2cpy((S8*)signature->img_file, (S8*)g_umms_context->nvram_compose_settings.auto_signature_image_file);
			mmi_ucs2cpy((S8*)signature->audio_file, (S8*)g_umms_context->nvram_compose_settings.auto_signature_audio_file);
			mmi_ucs2cpy((S8*)signature->video_file, (S8*)g_umms_context->nvram_compose_settings.auto_signature_video_file);
			OslMfree(utf8_buffer);
             return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
        UMMS_MMI_MAKE_SETTINGS_TEXT_FILE_PATH(mmi_uc_text_path, 0);

        memset(utf8_buffer, 0, utf8_buffer_size);
        utf8_len = mmi_chset_ucs2_to_utf8_string(
                    utf8_buffer,
                    utf8_buffer_size,
                    g_umms_context->nvram_compose_settings.auto_signature_content);

        file_handle = FS_Open((U16*) mmi_uc_text_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
			if (file_handle < 0)
        {
				PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSettingUtils.c] mmi_umms_compose_settings_sign_info :text file open fail");
			OslMfree(utf8_buffer);
			signature->enable = 0;
			return;
            //MMI_ASSERT(0);
        }

			result = FS_Write(
            file_handle,
            utf8_buffer,
            utf8_len - 1,   /* null terminator */
            &write_len);

			if(result == FS_NO_ERROR)
			{
        OslMfree(utf8_buffer);
        FS_Close(file_handle);
				mmi_ucs2cpy((S8*) signature->text_file, (S8*) mmi_uc_text_path);
			}
			else
			{
			    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSettingUtils.c] mmi_umms_compose_settings_sign_info :text file write fail");
				OslMfree(utf8_buffer);
				FS_Close(file_handle);
				signature->enable = 0;
				return;
			}
		}

        signature->enable = g_umms_context->nvram_compose_settings.auto_signature;
		mmi_ucs2cpy((S8*)signature->img_file, (S8*)g_umms_context->nvram_compose_settings.auto_signature_image_file);
		mmi_ucs2cpy((S8*)signature->audio_file, (S8*)g_umms_context->nvram_compose_settings.auto_signature_audio_file);
		mmi_ucs2cpy((S8*)signature->video_file, (S8*)g_umms_context->nvram_compose_settings.auto_signature_video_file);


    }
    return;
}
#endif /* __MMI_MMS_SIGNATURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_setting_image_resize_info
 * DESCRIPTION
 *  mmi_umms_compose_setting_image_resize_info
 * PARAMETERS
 *  resize      [?]     [?]
 * RETURNS
 *  U8(?)(?)
 *****************************************************************************/
void mmi_umms_compose_setting_image_resize_info(mma_image_resizing_struct *resize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize->width = 0;
    resize->height = 0;
    switch (g_umms_context->nvram_compose_settings.image_resize_option)
    {
        case E_IMAGE_RESIZE_OFF:
            resize->enable = 0;
            break;
        case E_IMAGE_RESIZE_160x120:
            resize->enable = 1;
            resize->width = 160;
            resize->height = 120;
            break;
        case E_IMAGE_RESIZE_320x240:
            resize->enable = 1;
            resize->width = 320;
            resize->height = 240;
            break;
        case E_IMAGE_RESIZE_640x480:
            resize->enable = 1;
            resize->width = 640;
            resize->height = 480;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_best_page_duration
 * DESCRIPTION
 *  Returns the best page duration status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_compose_settings_best_page_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_compose_settings.best_page_duration;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_creation_mode
 * DESCRIPTION
 *  Returns the  status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_creation_mode_enum mmi_umms_compose_settings_creation_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_compose_settings.creation_mode)
    {
        case E_CREAT_MODE_RESTRICTED:
            return MMA_CREATION_MODE_RESTRICTED;
#ifdef __MMS_CREATION_MODE_SUPPORTED__
        case E_CREAT_MODE_WARNING:
            return MMA_CREATION_MODE_WARNING;
#endif
        case E_CREAT_MODE_FREE:
            return MMA_CREATION_MODE_FREE;
        default:
            return MMA_CREATION_MODE_FREE;
    }

}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_add_as_drm
 * DESCRIPTION
 *  Returns the add as drm object status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_compose_settings_add_as_drm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_compose_settings.add_drm;
}
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_layout
 * DESCRIPTION
 *  Returns the layout(Potrait/Landscape)  status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_compose_settings_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_compose_settings.layout;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_max_no_pages
 * DESCRIPTION
 *  Returns the max no pages value set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_compose_settings_max_no_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_compose_settings.max_no_pages;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_default_slide_time
 * DESCRIPTION
 *  Returns the  default slide time set in compose settings
 * PARAMETERS
 *  set     [?]     [?]
 * RETURNS
 *  U32(?)(?)
 *****************************************************************************/
void mmi_umms_compose_settings_default_slide_time(mma_setting_struct *set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set->value = g_umms_context->nvram_compose_settings.default_slide_time;
    set->min = 1;
    set->max = UMMS_MAX_DEFAULT_SLIDE_TIME_DURATION;
}

#ifdef __MMI_MMS_SIGNATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_settings_auto_sign_content
 * DESCRIPTION
 *  Returns the  auto sign content set in compose settings
 * PARAMETERS
 *  content     [?]     [?]     [?]     [?]     (ponter to auto sign content)
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
    content = g_umms_context->nvram_compose_settings.auto_signature_content;
}
#endif /* __MMI_MMS_SIGNATURE__ */ 

/* /sending settings wrapper */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_delivery_report
 * DESCRIPTION
 *  Returns the delivery report status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_sending_settings_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_sending_settings.delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_delivery_time
 * DESCRIPTION
 *  Returns the  delivery time value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_delivery_time_enum mmi_umms_sending_settings_delivery_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_sending_settings.delivery_time)
    {
        case E_IMMEDIATE:
            return MMA_DELIVERY_IMMEDIATE;
        case E_1_HR:
            return MMA_DELIVERY_1_HOUR;
        case E_12_HRS:
            return MMA_DELIVERY_12_HOURS;
        case E_24_HRS:
            return MMA_DELIVERY_24_HOURS;
        default:
            return MMA_DELIVERY_IMMEDIATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_hide_sender
 * DESCRIPTION
 *  Returns the hide sender status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_sending_settings_hide_sender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_sending_settings.hide_sender;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_send_and_save
 * DESCRIPTION
 *  Returns the send and save status  in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_sending_settings_send_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_sending_settings.send_and_save;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_priority
 * DESCRIPTION
 *  Returns the priroty value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_priority_enum mmi_umms_sending_settings_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_sending_settings.priority)
    {
        case E_PRIORITY_LOW:
            return MMA_PRIORITY_LOW;
        case E_PRIORITY_NORMAL:
            return MMA_PRIORITY_MEDIUM;
        case E_PRIORITY_HIGH:
            return MMA_PRIORITY_HIGH;
        default:
            return MMA_PRIORITY_MEDIUM;
    }

    return MMA_PRIORITY_MEDIUM;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_read_report
 * DESCRIPTION
 *  Returns the read report status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_sending_settings_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_sending_settings.read_report;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_validity_period
 * DESCRIPTION
 *  Returns the validity period value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_expiry_time_enum mmi_umms_sending_settings_validity_period(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_sending_settings.validity_period)
    {
        case E_VALIDITY_PERIOD_MAX:
            return MMA_EXPIRY_MAX;
        case E_VALIDITY_PERIOD_1HR:
            return MMA_EXPIRY_1_HOUR;
		case E_VALIDITY_PERIOD_6HRS:
			return MMA_EXPIRY_6_HOURS;
        case E_VALIDITY_PERIOD_12HRS:
            return MMA_EXPIRY_12_HOURS;
        case E_VALIDITY_PERIOD_1DAY:
            return MMA_EXPIRY_1_DAY;
        case E_VALIDITY_PERIOD_1WEEK:
            return MMA_EXPIRY_1_WEEK;
        default:
            return MMA_EXPIRY_MAX;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_reply_charging_status
 * DESCRIPTION
 *  Returns the reply charging status set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_sending_settings_reply_charging_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_sending_settings.reply_charging;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_reply_charging_request_type
 * DESCRIPTION
 *  Returns the reply charging request type set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_reply_charging_type_enum mmi_umms_sending_settings_reply_charging_request_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_sending_settings.request_type)
    {
        case E_FULL_MMS:
            return MMA_FULL_MMS;
        case E_TEXT_ONLY:
            return MMA_TEXT_ONLY;
        default:
            return MMA_REPLY_CHARGING_TYPE_TOTAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_deadline_for_reply
 * DESCRIPTION
 *  Returns the  deadline for reply set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_umms_sending_settings_deadline_for_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_sending_settings.deadline_for_reply;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_reply_charging_size
 * DESCRIPTION
 *  Returns the reply charging size value set in sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U32 mmi_umms_sending_settings_reply_charging_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_sending_settings.size;
}

/* /retrieval settings wrapper */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_home_network_retrieval_mode
 * DESCRIPTION
 *  Retruns the home network retrieval mode set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_retrieval_mode_enum mmi_umms_retrieval_settings_home_network_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_retrieval_settings.home_network)
    {
        case E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE:
            return MMA_RETRIEVAL_MODE_IMMED;
        case E_HOME_NOETWORK_RETRIEVAL_DEFFERED:
            return MMA_RETRIEVAL_MODE_DEFERRED;
        case E_HOME_NOETWORK_RETRIEVAL_RESTRICTED:
            return MMA_RETRIEVAL_MODE_REJECT;
        default:
            return MMA_RETRIEVAL_MODE_IMMED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_roaming_retrieval_mode
 * DESCRIPTION
 *  Retruns the roaming retrieval mode set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_retrieval_mode_enum mmi_umms_retrieval_settings_roaming_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_retrieval_settings.roaming)
    {
        case E_ROAMING_RETRIEVAL_AS_HOME:
            return MMA_RETRIEVAL_MODE_AS_HOME;

        case E_ROAMING_RETRIEVAL_IMMEDAITE:
            return MMA_RETRIEVAL_MODE_IMMED;

        case E_ROAMING_RETRIEVAL_DEFFERED:
            return MMA_RETRIEVAL_MODE_DEFERRED;

        case E_ROAMING_RETRIEVAL_RESTRICTED:
            return MMA_RETRIEVAL_MODE_REJECT;
        default:
            return MMA_RETRIEVAL_MODE_AS_HOME;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_anonymous_filter
 * DESCRIPTION
 *  Retruns the anonymous status(Allow/reject) set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_retrieval_settings_anonymous_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_retrieval_settings.anonymous_filter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_advertisment_filter
 * DESCRIPTION
 *  Retruns the advertisement status(Allow/reject) set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_retrieval_settings_advertisment_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_retrieval_settings.advertisement_filter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_read_report
 * DESCRIPTION
 *  Retruns the read report status set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
umms_read_report_enum mmi_umms_retrieval_settings_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_retrieval_settings.read_report)
    {
        case E_READ_REPORT_SEND_ON_REQUEST:
            return E_READ_REPORT_SEND_ON_REQUEST;
            break;
        case E_READ_REPORT_SEND_ALWAYS:
            return E_READ_REPORT_SEND_ALWAYS;
            break;
        case E_READ_REPORT_SEND_NEVER:
            return E_READ_REPORT_SEND_NEVER;
            break;
        default:
            return E_READ_REPORT_SEND_ON_REQUEST;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_delivery_report
 * DESCRIPTION
 *  Retruns the delivery report status set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_retrieval_settings_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_retrieval_settings.delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_msg_size_filter
 * DESCRIPTION
 *  Retruns the msg size filter value set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
#ifndef __MMI_MMS_OMA_CONF_273__
U16 mmi_umms_retrieval_settings_msg_size_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_context->nvram_retrieval_settings.msgsize_filter;
}
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_signature_file_mgr_filter
 * DESCRIPTION
 *  Set file manager filters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_signature_file_mgr_filter(FMGR_FILTER* filter, const char *mime_types)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (strstr(mime_types, "jpeg"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
        FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
    }

    if (strstr(mime_types, "gif"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    }
    
    if (strstr(mime_types, "wbmp"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
        FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);        
    }    

    if (strstr(mime_types, "mid")) /* Including "audio/mid" */
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_MID);       
    }

    if (strstr(mime_types, "amr")) /* Assume audio/amr is okay even the parameter is audio/amr-wb */
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);       
    }
#ifdef __MMI_VCARD__
    if (strstr(mime_types, "vcard"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_VCF);  
    }
#endif /* __MMI_VCARD__ */ 
#ifdef __MMI_VCALENDAR__
    if (strstr(mime_types, "vcalendar"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_VCS);  
    }
#endif /* __MMI_VCALENDAR__ */ 

    if (strstr(mime_types, "video/mp4"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);  
    }
    
    if (strstr(mime_types, "video/mpeg"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_MPG);  
    }

    if (strstr(mime_types, "video/3gp"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);  
    }

    if (strstr(mime_types, "video/3gpp2"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);  
    }    

    if (strstr(mime_types, "image/bmp"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);  
    }
    
    if (strstr(mime_types, "png"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);  
    }

    if (strstr(mime_types, "wav"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);  
    }

    if (strstr(mime_types, "imelody"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_IMY);  
    }
            
    if (strstr(mime_types, "smaf"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_MMF);  
    }

    if (strstr(mime_types, "mp3") || strstr(mime_types, "audio/mpeg"))      /* with disagreement */
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_DAF);  
    }
    
    if (strstr(mime_types, "video/x-msvideo"))  /* with disagreement */
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_AVI);  
    }

    if (strstr(mime_types, "amr-wb"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);  
    }

    if (strstr(mime_types, "wma"))  /* with disagreement */
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_WMA);  
    }

    if (strstr(mime_types, "audio/aac"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_AAC);  
    }

    if (strstr(mime_types, "m4a"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_M4A);  
    }
    
    if (strstr(mime_types, "aiff"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_AIF);  
        FMGR_FILTER_SET(filter, FMGR_TYPE_AIFF);  
        FMGR_FILTER_SET(filter, FMGR_TYPE_AIFC);  
    }
    
    if (strstr(mime_types, "audio/basic"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_AU);  
        FMGR_FILTER_SET(filter, FMGR_TYPE_SND);  
    }    

    if (strstr(mime_types, "text/vnd.sun.j2me.app-descriptor"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_JAD);  
    }

    if (strstr(mime_types, "application/java-archive"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_JAR);  
    }

    if (strstr(mime_types, "application/vnd.mtk.lrc"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_LRC);  
    }

    if (strstr(mime_types, "image/svg+xml"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);  
    }

    if (strstr(mime_types, "application/vnd.mtk.m3d"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_M3D);  
    }

    if (strstr(mime_types, "text/plain"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_EBOOK_TXT);  
    }
    
    if (strstr(mime_types, "application/text"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_EBOOK_TXT);  
    }

    if (strstr(mime_types, "chemical/x-pdb"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_EBOOK_PDB);  
    }
#if defined(__DRM_V02__)
    if (strstr(mime_types, "odf"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_ODF);  
    }
#endif
#if defined(WAP_SUPPORT)
    if (strstr(mime_types, "text/html"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_HTML);  
    }

    if (strstr(mime_types, "text/vnd.wap.wml"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_WML);  
    }
#endif


    if (strstr(mime_types, "audio/mp2"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_MP2);  
    }
#ifdef __MMI_BARCODEREADER__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif    
    if (strstr(mime_types, "image/svg+xml"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);  
    }

    if (strstr(mime_types, "audio/vm"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_VM);  
    }

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)

    if (strstr(mime_types, "mtk/med.thm"))
    {
        FMGR_FILTER_SET(filter, FMGR_TYPE_THEME);  
    }
#endif


    return;
}

#endif /* defined (__MMI_MMS_2__) && defined(MMS_SUPPORT) */ 
// #endif //#if 0 //Pranav Commeneted

